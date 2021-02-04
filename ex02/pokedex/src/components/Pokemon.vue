<template v-slot:default="{ pending, error, data}">
<!-- Request Pending -->
  <div>
    <router-link :to="{name:'pokedex'}"><button type="button" class="return btn btn-info btn-sm">return</button></router-link>
    <div v-if="pending" class="text-center">
      Loading ...
    </div>
<!-- Request Error -->
    <div v-else-if="error" role="alert">
      {{ error }}
    </div>
<!-- Request Success -->
    <div
      v-else
      class="pokemon">
      <div class="card-body">
        <img class="card-img" :src="'https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/' + this.$route.params.id + '.png'" />
        <h2 class="card-title">{{PokemonDetail.name}}</h2>
        <table class="poke-table" border="1">
          <tr>
            <td>ID</td><td>{{PokemonDetail.id}}</td>
          </tr>
          <tr
            v-for="(type, index) in PokemonDetail.types"
            v-bind:key="index"
          >
            <td>TYPE{{index + 1}}</td>
			<td>{{type.type.name}}</td>
          </tr>
          <tr
            v-for="(stat, index) in PokemonDetail.stats"
            v-bind:key="`second-${index}`"
          >
            <td>{{stat.stat.name.toUpperCase()}}</td>
			<td>{{stat.base_stat}}</td>
          </tr>
        </table>
      </div>
    </div>
  </div>
</template>

<script>
import axios from 'axios'

export default {
  name: 'Pokemon',
  data() {
    return {
      pending: true,
      error: false,
      PokemonDetail: {},
    };
  },
    mounted() {
    this.requestData();
  },
  methods: {
    async requestData() {
      this.pending = true;
      try {
		const res = await axios.get("https://pokeapi.co/api/v2/pokemon/" + this.$route.params.id);
		this.PokemonDetail =  res.data;
		console.log(this.PokemonDetail);
        this.error = false;
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
@import url('https://fonts.googleapis.com/css2?family=Lato&family=Rubik:wght@500&display=swap');
h2 {
  font-family: 'Rubik', sans-serif;
  color: #9d0b0b;
}
table {
  border-collapse: collapse;
  border: solid 2px grey;
  margin: auto;
}
table tr {
	background: white;
}
table td {
  padding: 7px 20px;
  font-family: 'Lato', sans-serif;
}
.return {
	color: white;
}
.pokemon {
  text-align: center;
}
.card-img {
  background-color: white;
  width: 150px;
  height: 150px;
  border-radius: 20%;
}
.card-body {
	text-align: center;
}
</style>
