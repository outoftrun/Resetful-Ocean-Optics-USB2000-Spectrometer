<template>
    <div id='BoxPlot'>
    </div>
</template>
<script>

import Plotly from 'plotly.js-dist';
//import * as d3 from "d3";

export default {
    name: 'BoxPlot',
    data: () => ({

    }),
    mounted() {
        this.getBoxPlot()
        console.log()

    },
    methods: {
        getBoxPlot() {
            var y0 = [];
            var y1 = [];
            for (var i = 0; i < 50; i++) {
                y0[i] = Math.random();
                y1[i] = Math.random() + 1;
            }

            var trace1 = {
                y: y0,
                type: 'box'
            };

            var trace2 = {
                y: y1,
                type: 'box'
            };

            var data = [trace1, trace2];

            var config = { responsive: true }
            Plotly.newPlot("BoxPlot", data, config)
        }

    }

}

</script>


<style>
</style>