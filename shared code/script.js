// vanilla js variables and consts here
let showMenu = false;

// Configure Vue here
const VueApp = {
  // Put variables here
  data() {
    return {
      showMenu: false,
      isClicked: false,
      enable_purpleBG: false,
      sectionstext: [
        {
          id: "personalization",
          div_id: "personalization_text",
          header: "Personalized",
          complementary: "down to every single pixel",
          infobit:
            "Our commitment is to make you a website \n that is prettier than your girlfriend",
        },
        {
          id: 1,
          div_id: "developers",
          header: "Best",
          complementary: "in the game",
          infobit:
            "Our developers have never seen sunlight because they’ve been programming since they were 5",
        },
        {
          id: 2,
          div_id: 3,
          header: "Manage",
          complementary: "everything like a boss",
          infobit:
            "Everything about your business in a glance, data & analytics right at your fingertips",
        },
        {
          id: 3,
          div_id: 4,
          header: "Ready to win?",
          complementary: "With us, all you do is win.",
          infobit: "Choose a plan",
        },
      ],
      sellingpoints: [
        {
          title: "Imagine",
          text: "You show us what kind of site you want - you can sketch it on a piece of paper, draw it in microsoft paint, or however else you want to",
        },
        {
          title: "Create",
          text: "During the developement process you will continuously give us feedback and make sure your site looks exactly the way you want it!",
        },
        {
          title: "Launch",
          text: "Happy with your site? After working closely with us, your site will be finally done and you will be ready to kickstart your business like noone else!",
        },
      ],
      plans: [
        {
          id: 0,
          title: "Small business",
          text: "Get a site tailored just for the needs of your small business. Perfect if you want to kickstart your business for real.",
          price: "€50-300",
          disclaimer: "20% upfront",
          button: "Get started",
        },
        {
          id: 1,
          title: "Enterprise",
          text: "You need a big team of pro developers to work on your website. Transform your brand and truly stand out. Perfect if you need tens or hundreds of pages.",
          price: "Get a quote",
          disclaimer: "Starting from €200",
          button: "Let's talk",
        },
      ],
      schools: [
        //remember to compress images
        {
          imageSRC: "developers/assets/reaalkool logo small.svg",
          onmouseover: "schoolrotate(this)",
          onclick: "schoolrotate(this)",
          title: "Reaalkool",
        },
        {
          imageSRC: "developers/assets/gag logo.png",
          onmouseover: "schoolrotate(this)",
          onclick: "schoolrotate(this)",
          title: "Gustav Adolfi Gümnaasium",
        },
        {
          imageSRC: "developers/assets/ttg pic.png",
          onmouseover: "schoolrotate(this)",
          onclick: "schoolrotate(this)",
          title: "Tallinna Tehnikagümnaasium",
        },
        {
          imageSRC: "developers/assets/ksg logo.jpg",
          onmouseover: "schoolrotate(this)",
          onclick: "schoolrotate(this)",
          title: "Kadrioru Saksagümnaasium",
        },
      ],
      socialmedia: [
        {
          title: "Contact us on WhatsApp",
          href: "https://www.whatsapp.com/",
          src: "footer/WhatsApp logo.svg",
        },
      ],
    };
  },

  // Code that will run as soon as app is ready
  mounted() {},

  // Functions go here
  methods: {
    togglemenu() {
      //toggles burger menu open anc close animations
      showMenu = !showMenu;

      if (showMenu == true) {
        this.openmenu();
        console.log("Opened menu");
      } else {
        this.closemenu();
        console.log("Closed menu");
      }
    },

    clickListener() {
      this.isClicked = !this.isClicked;
    },
    purpleBG() {
      this.enable_purpleBG = !this.enable_purpleBG;
    },
    openmenu() {
      //burger menu opening animation
      const nav = document.getElementById("mobile_nav");
      const bun1 = document.getElementById("bun1");
      const bun2 = document.getElementById("bun2");
      const bun3 = document.getElementById("bun3");
      const bunwall = document.getElementById("bunwall");

      bunwall.classList.remove("bunwall_lower_R");
      bun3.classList.remove("bun_disappear2_R");
      bun1.classList.remove("bun1_an_R");

      bun1.classList.add("bun1_an");
      bunwall.classList.remove("bunwall_lower_R");
      bunwall.classList.add("bunwall_lower");

      setTimeout(function () {
        bun2.classList.add("bun_disappear");
      }, 440);

      setTimeout(function () {
        bun3.classList.add("bun_disappear2");
      }, 450);

      nav.classList.remove("nav-close");
    },
    closemenu() {
      //burger menu closing animation
      const nav = document.getElementById("mobile_nav");
      nav.classList.add("nav-close");

      bunwall.classList.remove("bunwall_lower");
      bunwall.classList.add("bunwall_lower_R");

      bun1.classList.remove("bun1_an");
      bun1.classList.add("bun1_an_R");

      setTimeout(function () {
        bun2.classList.remove("bun_disappear");
      }, 440);

      bun3.classList.remove("bun_disappear2");
      bun3.classList.add("bun_disappear2_R");
    },
  },
};

// Initialize Vue
Vue.createApp(VueApp).mount("#app");
