import Vue from 'vue'
import Vuex from 'vuex'

Vue.use(Vuex)

export default new Vuex.Store({
  state: {
    ip: "http://thinkpad-t470p.local:3000/"
  },
  getters: {
    ip(){
      return state.ip
    }
  },
  mutations: {
  },
  actions: {
  },
  modules: {
  }
})
