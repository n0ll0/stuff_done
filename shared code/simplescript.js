//const x = document.getElementsByClassName("school");
//
//x.onclick = function () {
//  this.className = "rotate";
//  console.log(this);
//
//  setTimeout(function () {
//    x.classList.remove("rotate");
//  }, 1000);
//};

function schoolrotate(img) {
  img.className = "rotate";
  console.count("Client has rotated " + img.title + " bubble");

  setTimeout(function () {
    img.classList.remove("rotate");
  }, 850);
  console.count(schoolrotate.callCount);
}

function copy_email(email) {
  const tooltip = document.getElementById("emailtooltip");
  var emailaddress = email.innerText.replace(tooltip.innerText, ""); //innertext of tooltip needs to be removed/replaced with nothing , otherwise the text copied to clipboard would be like "@email Email has been copied to clipboard"

  navigator.clipboard.writeText(emailaddress);
  console.log("User has copied email: " + email.innerText);

  tooltip.innerHTML = "Email has been copied to clipboard";
  tooltip.classList.remove("invisible_tooltip");
  tooltip.classList.add("visible_tooltip");
}
