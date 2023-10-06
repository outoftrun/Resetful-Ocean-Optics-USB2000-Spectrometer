<template>
    <div id='BubbleChart'>
    </div>
</template>
<script>

import Plotly from 'plotly.js-dist';
//import * as d3 from "d3";

export default {
    name: 'BubbleChart',
    data: () => ({

    }),
    mounted() {
        this.getBubbleChart()
        console.log()

    },
    methods: {
        getBubbleChart() {
            var trace1 = {
                x: [1, 2, 3, 4],
                y: [10, 11, 12, 13],
                mode: 'markers',
                marker: {
                    size: [40, 60, 80, 100]
                }
            };

            var data = [trace1];

            var layout = {
                title: 'Marker Size',
                showlegend: false,
                height: 600,
                width: 600
            };
            var config = { responsive: true }
            Plotly.newPlot("BubbleChart", data, layout, config)
        }

    }

}

</script>


<style>
</style>