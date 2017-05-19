class Greeter {
    element: HTMLElement;
    span: HTMLElement;
    timerToken: number;

    constructor(element: HTMLElement) {
        this.element = element;
        this.element.innerHTML += "The time is: ";
        this.span = document.createElement('span');
        this.element.appendChild(this.span);
        this.span.innerText = new Date().toUTCString();
    }

    start() {
        this.timerToken = setInterval(() => this.span.innerHTML = new Date().toUTCString(), 500);
    }

    stop() {
        clearTimeout(this.timerToken);
    }

}

class Args {

    constructor() {
    }

    split(strIn: string): string[] {
        var vstrRe: string[] = [];
        var vstr: string[] = strIn.split('?');
        if (vstr.length > 1) {
            var vsubstr: string[] = vstr[1].split('&');
            if (vsubstr.length >= 2) {

            }
        }
        return vstrRe;
    }
}
var gArgs: Args = new Args();

window.onload = () => {
    var url = window.location.href;
    gArgs.split(url);
    //var el = document.getElementById('content');
    //var greeter = new Greeter(el);
    //greeter.start();
};