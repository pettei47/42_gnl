<template v-slot:default="{ pending, error, data }">
<!-- Request Pending -->
  <div>
    <div v-if="pending" class="text-center">
      <img src="https://files.codethink.de/public/Preloader_2.gif" alt="loading">
      Loading ..
    </div>
<!-- Request Error -->
    <div v-else-if="error" role="alert">
      {{ error }}
    </div>
<!-- Request Success -->
    <div
    v-else
    v-for="(item, index) in PokemonList"
    v-bind:key="index"
    v-bind:number="index + 1"
    class="col-md-2"
    >
      <div class="card">
        <div class="card-body">
          <img class="card-img-top" :src="'https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/' + (index < 898 ? index + 1 : index + 9103) + '.png'" />
          <div class="card-title">
			{{(index + 1)}}
            {{item.name}}
          </div>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
import axios from 'axios'

export default {
  name: 'Async',
  data() {
    return {
      pending: true,
      error: false,
      PokemonList: [],
    };
  },
  mounted() {
    this.requestData();
  },
  methods: {
    async requestData() {
      this.pending = true;
      try {
		const res = await axios.get("https://pokeapi.co/api/v2/pokemon?offset=0&limit=898");
		this.PokemonList =  res.data.results;
    console.log(this.PokemonList);
        if (this.PokemonList)
            this.error = false;
        else
            this.error = "pokemon not found";
      } catch (e) {
        this.error = e;
      }
      this.pending = false;
    }
  },
  render() {
    return this.$scopedSlots.default({
      pending: this.pending,
      error: this.error,
      data: this.data
    });
  }
}
</script>

<style>
</style>