<template>
  <div>
    <div id="RibbonChart"></div>


  </div>
</template>
<script>
import Plotly from "plotly.js-dist";
import axios from "axios";

//import * as d3 from "d3";

export default {
  name: "RibbonChart",

  data: function () {
    return {
      xData: [1, 2, 3],
      yData: [[100, 100, 100, 100, 9000],
        [5.625, 6.25, 8.125, 11.25, 15.625],
        [2.5, 3.125, 5.0, 8.125, 12.5],
        [0.625, 1.25, 3.125, 6.25, 10.625],
        [0.625, 1.25, 3.125, 6.25, 10.625],
        [0.625, 1.25, 3.125, 6.25, 10.625],
        [0.625, 1.25, 3.125, 6.25, 10.625],
        [0.625, 1.25, 3.125, 6.25, 10.625],
        [0.625, 1.25, 3.125, 6.25, 10.625],
        [0.625, 1.25, 3.125, 6.25, 10.625],
        [0.625, 1.25, 3.125, 6.25, 10.625],
        [0, 0.625, 2.5, 5.625, 10]],
      dataChanged: false,
    }
  },

  watch: {
    xData: function (oldVal, newVal) {
      if (this.xData == null)
        this.dataChanged = false
      else
        this.dataChanged = true
      console.log(this.xData)
      this.getRibbonChart()
    },

    yData: function (oldVal, newVal) {
      // if (this.yData == null)
      //   this.dataChanged = false
      // else
      //   this.dataChanged = true
      console.log(this.yData)
      this.getRibbonChart()
    }
  },
  mounted: function () {
    this.getRibbonChart()
    const len = 30;
    const url = 'http://thinkpad-t470p.local:3000/ocean?spectrum=' + len;
    axios.get(url)
        .then(response => {
          // handle success
          console.log(response);
          this.xData = response["data"]["wavelength"]
          // const setFlag = () => this.isDoneLoading = true
          // await setFlag()
          //  console.log(response["data"]["times"]);
          //  Vue.set(RibbonChart.trace.x,1,2);
          let tmp = [];
          for (let e = 0; e < len; e++) {
            let w = [];
            for (let j = 0; j < 512; j++) {
              w.push((response["data"]["spectrum"][e][j * 4]+response["data"]["spectrum"][e][j * 4+1]+
              response["data"]["spectrum"][e][j * 4]+response["data"]["spectrum"][e][j * 4+3])/4);
            }
            tmp.push(w)
          }
          this.yData = tmp;

          // }//console.log(this.trace.y)

        })
        .catch(function (error) {
          // handle error
          console.log(error);
        })
        .finally(function () {
          // always executed
        });
    console.log();
  },
  methods: {

    getRibbonChart() {
      const data1 = [{
        z: this.yData,
        //  type: 'contour'
         type: 'surface'
      }
      ];
      var layout = {
        title: 'Basic Contour Plot'
      }

      Plotly.newPlot('RibbonChart', data1, layout);
    },
  },
};
</script>

<style>

</style>
