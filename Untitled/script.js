function choose(src,id,id1) {
  document.getElementById(id).src = src;
  document.getElementById(id1).src = src;
};
var number = 1;
function createI() {
  number += 1;
var newItem = document.createElement('div');
newItem.className = ('item');
newItem.id = ('number');
newItem.innerHTML = (`<h3>T-shirt ${number}</h3>
        <p>${Math.floor(Math.random() * 99999999)}</p>
        <div class="palette">
          <button class="circle1" onclick="choose('img/White.jpg','img${number}','Img${number}')"></button>
          <button class="circle2" onclick="choose('img/blue.jpg','img${number}','Img${number}')"></button>
          <button class="circle3" onclick="choose('img/red.jpg','img${number}','Img${number}')"></button>
          <button class="circle4" onclick="choose('img/lmfao.png','img${number}','Img${number}')"></button>
        </div>
        <img id="img${number}" src="img/lmfao.png" :hover>
        <button class="add" onclick="add(${number})">Add to cart</button>`);
var list = document.getElementById('container');
list.insertBefore(newItem, list.childNodes[number + 1]);
};
let clicks = 0;
function add(id) {
  clicks += 1
  document.getElementById("nr").innerHTML = clicks
  i = (`<h3>T-shirt ${id}</h3>
  <img id="Img${id}" src="${document.getElementById(`img${id}`).src}"><hr>`)
  document.getElementById("list").innerHTML = (document.getElementById("list").innerHTML + `<div>${i}</div>`)
};
function displayList() {
 if (document.getElementById("list").style.display === "flex") {
    document.getElementById("list").style.display = "none";
  } else {
    document.getElementById("list").style.display = "flex";
  }
};