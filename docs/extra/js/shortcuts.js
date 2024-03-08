keyboard$.subscribe(function (key) {  // 键盘左键上一页
    if (key.mode === "global" && key.type === "ArrowLeft") {
        /* Add custom keyboard handler here */
        var elements = document.getElementsByClassName('md-footer__link md-footer__link--prev');
        if (elements.length)
            elements[0].click();
        key.claim()
    }
})

keyboard$.subscribe(function (key) {  // 键盘右键下一页
    if (key.mode === "global" && key.type === "ArrowRight") {
        /* Add custom keyboard handler here */
        var elements = document.getElementsByClassName('md-footer__link md-footer__link--next');
        if (elements.length)
            elements[0].click();
        key.claim()
    }
})

// var flag = false;

// keyboard$.subscribe(function (key) {  // 键盘双击上键回到顶部
//     function reset() {
//         flag = false;
//         clearInterval(inter);
//     }
//     if (key.mode === "global" && key.type === "ArrowUp") {
//         /* Add custom keyboard handler here */
//         if (!flag) {
//             var inter = setInterval(reset, 150);
//             flag = true;
//             return;
//         }
//         var elements = document.getElementsByClassName('md-top md-icon');
//         if (elements.length)
//             elements[0].click();
//     }
// })