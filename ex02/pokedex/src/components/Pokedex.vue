<template v-slot:default="{ pending, error, data }">
<!-- Request Pending -->
  <div>
    <div v-if="pending" class="text-center">
      Loading ...
    </div>
<!-- Request Error -->
    <div v-else-if="error" role="alert">
      {{ error }}
    </div>
<!-- Request Success -->
    <div v-else>
      <div class="header"><h1 class="title">POKEDEX</h1></div>
      <div class="search">Search: <input class="search_input" type="text" v-model="keyword" placeholder="name"></div>
      <div
        v-for="(item, index) in Pokemons"
		v-bind:key="index"
		class="col-md-2">
        <div class="card">
          <router-link :to="{name:'pokemon', params: {id: item.id}}">
            <div class="card-body">
              <img class="card-img-top" :src="'https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/' + (item.id) + '.png'" />
              <div class="card-title">
                {{(item.id)}}
                {{item.name}}
              </div>
            </div>
          </router-link>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
import axios from 'axios'

export default {
  name: 'Pokedex',
  data() {
    return {
      pending: true,
      error: false,
      PokemonList: [],
      keyword: '',
    };
  },
  mounted() {
    this.requestData();
  },
  computed: {
    Pokemons: function() {
      var selects = [];
      for(var i in this.PokemonList) {
        var select = this.PokemonList[i];
        if(select.name.indexOf(this.keyword) !== -1) {
          selects.push(select);
        }
      }
      return selects;
    }
  },
  methods: {
	async requestData() {
      this.pending = true;
      try {
		const res = await axios.get("https://pokeapi.co/api/v2/pokemon?offset=0&limit=898")
		this.PokemonList = res.data.results;
        this.error = false;
      } catch (e) {
        this.error = e;
      }
      try {
        for (const result of this.PokemonList)
        {
          const detailinfo = await axios.get(result.url);
          result["id"] = detailinfo.data.id
          //console.log(result.id);
        }
      } catch(e) {
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
.title {
	color: #9d0b0b;
	font-family: 'Rubik', sans-serif;
	text-align: center;
	margin-top: 3rem;
	margin-bottom: 3rem;
}
.card {
	background-color: white;
	margin: 0.5rem;
	padding: 1rem;
	text-align: center;
	font-family: 'Lato', sans-serif;
	border-radius: 40%;
}
.search {
	text-align: center;
	padding-bottom: 20px;
}
.search_input {
	width: 250px;
	height: 30px;
}
</style>
