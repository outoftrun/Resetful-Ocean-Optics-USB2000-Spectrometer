import Vue from 'vue'
import VueRouter from 'vue-router'
import HomeView from '../views/HomeView.vue'


import PieChart from '../views/Plotly/PieChart.vue'
import BarChart from '../views/Plotly/BarChart.vue'
import BoxPlot from '../views/Plotly/BoxPlot.vue'
import BubbleChart from '../views/Plotly/BubbleChart.vue'
import ContinuousErrorBar from '../views/Plotly/ContinuousErrorBar.vue'
import ScatterChart from "@/views/Plotly/ScatterChart.vue";

Vue.use(VueRouter)

const routes = [
  {
    path: '/',
    name: 'home',
    component: HomeView
  },
  {
    path: '/about',
    name: 'about',
    // route level code-splitting
    // this generates a separate chunk (about.[hash].js) for this route
    // which is lazy-loaded when the route is visited.
    component: () => import(/* webpackChunkName: "about" */ '../views/AboutView.vue')
  },
  {path: '/pieChart',component:PieChart },
  {path: '/BoxPlot',component:BoxPlot },
  {path: '/BubbleChart',component:BubbleChart },
  {path: '/ContinuousErrorBar',component:ContinuousErrorBar },
  {path: '/BarChart',component:BarChart },
  {path: '/ScatterChart', component: ScatterChart},

]

const router = new VueRouter({
  routes
})

export default router
