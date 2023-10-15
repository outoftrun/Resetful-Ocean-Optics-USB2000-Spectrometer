import Vue from 'vue'
import Vuex from 'vuex'
import axios from "axios";

Vue.use(Vuex)

export default new Vuex.Store({
    actions: {
        spectrum: async function (context, payload) {
            let pass = "/ocean?";
            for (const prop in payload) {
                if (prop === "wavelength")
                    pass += prop+'&'
                else
                pass += prop + "=" + payload[prop] + "&"
            }

            const address = this.state.ip + pass.slice(0, -1)
            console.log(address)
            return axios.get(address)
            // if (res.status === 200) {
            //     console.log(res.data["spectrum"])
            // }
        },
        async wavelength(context) {
            const address = this.state.ip + "/ocean?wavelength"
            const res = await axios.get(address)
            if (res.status === 200) {
                console.log(res.data)
            }
        }
    },
    getters: {
        ip(state) {
            return state.ip

        },
        wavelength(state) {
            return state.wavelength

        },
        spectrum(state) {
            return state.spectrum
        },
    },
    modules: {},
    mutations: {},
    state: {
        ip: "http://thinkpad-t470p.local:3000",
        wavelength: [10],
        spectrum: [[]],
        count: 1
    }
})
