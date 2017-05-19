var Greeter = (function () {
    function Greeter(element) {
        this.element = element;
        this.element.innerHTML += "The time is: ";
        this.span = document.createElement('span');
        this.element.appendChild(this.span);
        this.span.innerText = new Date().toUTCString();
    }
    Greeter.prototype.start = function () {
        var _this = this;
        this.timerToken = setInterval(function () { return _this.span.innerHTML = new Date().toUTCString(); }, 500);
    };
    Greeter.prototype.stop = function () {
        clearTimeout(this.timerToken);
    };
    return Greeter;
}());
var Args = (function () {
    function Args() {
    }
    Args.prototype.split = function (strIn) {
        var vstrRe = [];
        var vstr = strIn.split('?');
        if (vstr.length > 1) {
            var vsubstr = vstr[1].split('&');
            if (vsubstr.length >= 2) {
            }
        }
        return vstrRe;
    };
    return Args;
}());
var gArgs = new Args();
window.onload = function () {
    var url = window.location.href;
    gArgs.split(url);
};
