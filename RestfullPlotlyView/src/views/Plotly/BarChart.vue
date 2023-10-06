<template>
  <div id="BarChart"></div>
</template>
<script>
import Plotly from "plotly.js-dist";
//import * as d3 from "d3";

export default {
  name: "BarChart",
  data: () => ({}),
  mounted() {
    this.getBarChart();
    console.log();
  },
  methods: {
    getBarChart() {
      var trace1 = {
        x: ["giraffes", "orangutans", "monkeys"],
        y: [20, 14, 23],
        name: "SF Zoo",
        type: "bar",
      };

      var trace2 = {
        x: ["giraffes", "orangutans", "monkeys"],
        y: [12, 18, 29],
        name: "LA Zoo",
        type: "bar",
      };

      var data = [trace1, trace2];

      var layout = {
        paper_bgcolor: 'rgba(0,0,0,0)',
        plot_bgcolor:'rgba(0,0,0,0)',
        
        barmode: "group",
        opacity:1,  
        font: {
          family: "Droid Sans ",
          color: "#993399",
          size: 20,
          bold: true,
        },
        marker: {
            size:40,
          color: ["#993399"],
        },
      };
      var config = { responsive: true };
      Plotly.newPlot("BarChart", data, layout, config);
    },
  },
};
</script>

<style>

</style>
