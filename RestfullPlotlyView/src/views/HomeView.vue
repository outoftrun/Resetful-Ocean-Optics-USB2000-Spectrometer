<template>
    <h3>{{getIP}}</h3>
</template>

<script>
import HelloWorld from '../components/HelloWorld'
import store from "@/store";

export default {
  name: 'Home',

  components: {
    HelloWorld,
  },

  data() {
    return {

      port: false,
      valid: null,
      theme: 'material'
    };
  },
  beforeMount() {

    // Random IP Address on load
    // this.changeIp()

  },
  methods: {

    /**
     * Generate random number
     */
    random(min = 1, max = 270) {
      return Math.floor(Math.random() * max) + min;
    },

    /**
     * Triggers on change
     */
    ipChange(ip, port, valid) {
      this.ip = ip;
      this.port = port;
      this.valid = valid;
    },

    /**
     * Trigger a random ip and port change
     */
    changeIp(port) {
      this.ip = this.random() + '.' + this.random() + '.' + this.random() + '.' + this.random();

      if (port)
        this.port = '' + this.random(1, 9) + this.random(1, 9) + this.random(1, 9) + this.random(1, 9);
      else
        this.port = false;
    },

    /**
     * Switch on an off material design
     */
    materialSwitch() {

      if (!this.theme)
        this.theme = 'material';
      else
        this.theme = false;

    },

    /**
     * Reset everything
     */
    reset() {

      this.ip = '';
      this.port = false;
      this.valid = null;
      this.theme = 'material'

    }

  },
  computed:
      {
        getIP() {
          return store.getters.ip
        },
      }
}


</script>
