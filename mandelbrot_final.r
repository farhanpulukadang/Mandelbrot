#Mandelbrot set by F. Pulukadang
cr <- seq(-2, 1.25, by = 0.005);
x <- seq(1, length(cr));
y <- seq(1, length(cr));
m_re <- c();
m_im <- c();
for(re in x){
  for(im in y){
    c_re = cr[re];
    c_im = cr[im];
    z_re = 0;
    z_im = 0;
    conv = TRUE;
    for (j in seq(1,1000)){
      z_re2 = z_re;
      z_re = (z_re^2 - z_im^2 + c_re);
      z_im = 2*z_re2*z_im + c_im;
      if ((z_re^2)+(z_im^2)>4){
        conv = FALSE;
        break;
      }
    };
    if (conv == TRUE){
      m_re <- append(m_re, c_re);
      m_im <- append(m_im, c_im);
    }
  }
}
plot(m_re, m_im, type = 'p', pch = 16, cex = 0.05, col = 'black')
