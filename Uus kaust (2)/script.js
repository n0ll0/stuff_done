productList = [];
N = 0;
const addProduct = (name,img) => {
    productList.push({id:N,name:name,img:img,Q:0});N++;
    document.getElementById('List').innerHTML = document.getElementById('List').innerHTML + `<div id="${N}"><h1>${name}</h1><br><img src='${img}'></div>`;
};
const check = () => {for (let i=0;i<productList.length;i++) {console.log(productList[i])};};

addProduct('dadawf','img1.png');
addProduct('asiefjalsf','img2.png');

const selectProduct = (id) => {
    productList[id].Q += 1;
};

selectProduct(0);

check();
