import numpy as np
import matplotlib.pyplot as plt

aos_data = np.loadtxt('aos_stats.dat')
soa_data = np.loadtxt('soa_stats.dat')

fig, ax = plt.subplots(1,2)

# Runtime plot
ax[0].set_title('Runtime')
ax[0].set_xlabel('Number of Particles')
ax[0].set_ylabel('Seconds')
ax[0].plot(aos_data[:,0], aos_data[:,-1], color='red', label='AOS')
ax[0].plot(soa_data[:,0], soa_data[:,-1], color='blue', label='SOA')

# MFLOPS/s plot
ax[1].plot(aos_data[:,0], aos_data[:, -2], color='red', label='AOS')
ax[1].plot(soa_data[:,0], soa_data[:, -2], color='blue', label='SOA')
ax[1].set_title('MFlops/s')
ax[1].set_xlabel('Number of Particles')
ax[1].set_ylabel('MFlops/s')

plt.legend()
plt.tight_layout()
plt.show()