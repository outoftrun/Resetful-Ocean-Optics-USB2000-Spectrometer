<template>
  <v-app id="inspire">
    <v-navigation-drawer v-model="drawer" app>
      <v-list-item>
        <v-list-item-content>
          <v-list-item-title class="text-h6"> Application</v-list-item-title>
          <v-list-item-subtitle> subtext</v-list-item-subtitle>
        </v-list-item-content>
      </v-list-item>


      <v-divider></v-divider>

      <v-list dense nav>
        <v-list-item v-for="item in items" :key="item.title" :to="item.to" link>
          <v-list-item-icon>
            <v-icon>{{ item.icon }}</v-icon>
          </v-list-item-icon>


          <v-list-item-content>
            <v-list-item-title>{{ item.title }}</v-list-item-title>
          </v-list-item-content>
        </v-list-item>
      </v-list>
    </v-navigation-drawer>

    <v-app-bar app>
      <v-app-bar-nav-icon @click="drawer = !drawer"></v-app-bar-nav-icon>
      <v-toolbar-title>Application</v-toolbar-title>
    </v-app-bar>


    <v-main id="Back">
      <!--  -->
      <router-view></router-view>
    </v-main>
    <v-bottom-navigation style="height: 35px">
      <v-btn value="reload" @click="SendMessage('acquire')">
        <v-icon>mdi-reload</v-icon>
        <span>reload</span>
      </v-btn>
      <v-btn value="reload" @click="SendMessage('continuous')">
        <v-icon>mdi-reload</v-icon>
        <span>continuous</span>
      </v-btn>


      <label for="jack" style="width: 180px;">Number Of Samples</label>
      <input id="jack" type="number" width="20" value="1"
             style="text-align: center;width: 40px; height: 25px; background-color: aqua">
      <select>
        <option disabled value="">Please select one</option>
        <option>A</option>
        <option>B</option>
        <option>C</option>
      </select>


      <!--      <v-btn value="favorites">-->
      <!--        <v-icon>mdi-heart</v-icon>-->
      <!--        <span>Favorites</span>-->
      <!--      </v-btn>-->

      <!--      <v-btn value="nearby">-->
      <!--        <v-icon>mdi-map-marker</v-icon>-->
      <!--        <span>Nearby</span>-->
      <!--      </v-btn>-->
    </v-bottom-navigation>
  </v-app>
</template>

<script>
import {eventBus} from "@/main"

export default {
  data: () => ({
    drawer: null,
    myNumberData: 10,
    items: [
      {title: "Piechart", icon: "mdi-view-dashboard", to: "/PieChart"},
      {title: "BoxPlot", icon: "mdi-image", to: "/BoxPlot"},
      {title: "BubbleChart", icon: "mdi-help-box", to: "/BubbleChart"},
      {title: "ContinuousErrorBar", icon: "mdi-help-box", to: "/ContinuousErrorBar"},
      {title: "Barchart", icon: "mdi-view-dashboard", to: "/BarChart"},
      {title: "scatterChart", icon: "mdi-view-dashboard", to: "/ScatterChart"},
      {title: "RibbonPlot", icon: "mdi-view-dashboard", to: "/RibbonPlot"},
      {title: "SurfacePlot", icon: "mdi-view-dashboard", to: "/SurfacePlot"},
    ],
  }),
  methods: {
    SendMessage(message) {
      eventBus.$emit('customEvent', message)
    }
  }
};

</script>
<style>
#Back {
  /*background-color: black;*/
}


</style>
