static inline void __iomem *get_tima_phys(void)
{
return local_paca->kvm_hstate.xive_tima_phys;
}
