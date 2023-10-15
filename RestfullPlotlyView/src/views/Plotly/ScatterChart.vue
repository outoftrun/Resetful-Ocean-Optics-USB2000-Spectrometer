<template>
  <div>
    <div id="ScatterChart"></div>


  </div>
</template>
<script>
import Plotly from "plotly.js-dist";
import axios from "axios";
import {eventBus} from "@/main";
import store from "@/store";
//import * as d3 from "d3";

export default {
  name: "ScatterChart",

  data: function () {
    return {
      xData: [1, 2, 3],
      yData: [1, 2, 3],
      dataChanged: false,
      polling: null,
    }
  },

  watch: {
    xData: function (oldVal, newVal) {
      this.dataChanged = this.xData != null;

      this.getScatterChart()
    },

    yData: function (oldVal, newVal) {
      this.dataChanged = this.yData != null;

      this.getScatterChart()
    }
  },
  created() {
    eventBus.$on('customEvent', dataPassed => {

      this.message = dataPassed
      if (this.polling) {
        clearInterval(this.polling)
        this.polling = null;
      }
      switch (dataPassed) {

        case 'acquire':
          this.acquire();
          break;
        case "continuous":
          const self = this;
          this.polling = setInterval(function () {
            self.acquire();
          }, 3000);
          break;
        default:
          break;

      }
    })
  },
  mounted: function () {
    this.getScatterChart()
    // console.log(process.env.VUE_APP_NOT_SECRET_CODE)
    this.acquire();
    console.log();
  },
  methods: {
    acquire() {
      store.dispatch('spectrum', {wavelength: 0, spectrum: 1}).then(response => {

        this.yData = response["data"]["spectrum"][0]
        this.xData = response["data"]["wavelength"]
      }).catch(error => {
        alert(error.message)

      })
    },
    getStuff1() {
      axios.get('http://thinkpad-t470p.local:3000/ocean?wavelength&spectrum=1')
          .then(response => {
            // handle success
            console.log(response);
            this.xData = response["data"]["wavelength"]
            // const setFlag = () => this.isDoneLoading = true
            // await setFlag()
            //  console.log(response["data"]["times"]);
            //  Vue.set(scatterChart.trace.x,1,2);
            this.yData = response["data"]["spectrum"][0]
            //console.log(this.trace.y)

          })
          .catch(function (error) {
            alert(error.message)
            console.log(error);
          })
          .finally(function () {
            // always executed
          });
    },
    getScatterChart() {

      const trace2 = {
        x: this.xData,
        y: this.yData,
        name: "LA Zoo",
        type: "scatter",
      };

      const data = [trace2];

      const layout = {
        paper_bgcolor: 'rgba(0,0,0,0)',
        plot_bgcolor: 'rgba(0,0,0,0)',

        barmode: "group",
        opacity: 1,
        font: {
          family: "Droid Sans ",
          color: "#993399",
          size: 20,
          bold: true,
        },
        marker: {
          size: 40,
          color: ["#993399"],
        },
      };
      const config = {responsive: true};
      Plotly.newPlot("ScatterChart", data, layout, config);
    },
  },
};
</script>

<style>

</style>
