import matplotlib.pyplot as plt
import numpy as np
cr = np.arange(-2, 1.25, 0.005)
x = [i for i in range(len(cr))]# seq(1, length(cr));
y = [i for i in range(len(cr))]
m_re = [] # c();
m_im = [] # c();
for re in x:
  for im in y:
    c_re = cr[re]
    c_im = cr[im]
    z_re = 0
    z_im = 0
    conv = True;
    for _ in range (1000):
      z_re2 = z_re;
      z_re = (z_re**2 - z_im**2 + c_re)
      z_im = 2*z_re2*z_im + c_im
      if ((z_re**2)+(z_im**2)>4):
        conv = False;
        break
    if (conv):
      m_re.append(c_re);
      m_im.append(c_im);
plt.scatter(m_re, m_im)
plt.show()
    
