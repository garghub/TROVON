static int is_valid_cs(unsigned int cs)
{
if (cs > 6)
return 0;
return 1;
}
int bcm63xx_set_cs_base(unsigned int cs, u32 base, unsigned int size)
{
unsigned long flags;
u32 val;
if (!is_valid_cs(cs))
return -EINVAL;
if (size != roundup_pow_of_two(size))
return -EINVAL;
if (size < 8 * 1024 || size > 256 * 1024 * 1024)
return -EINVAL;
val = (base & MPI_CSBASE_BASE_MASK);
val |= (ilog2(size) - ilog2(8 * 1024)) << MPI_CSBASE_SIZE_SHIFT;
spin_lock_irqsave(&bcm63xx_cs_lock, flags);
bcm_mpi_writel(val, MPI_CSBASE_REG(cs));
spin_unlock_irqrestore(&bcm63xx_cs_lock, flags);
return 0;
}
int bcm63xx_set_cs_timing(unsigned int cs, unsigned int wait,
unsigned int setup, unsigned int hold)
{
unsigned long flags;
u32 val;
if (!is_valid_cs(cs))
return -EINVAL;
spin_lock_irqsave(&bcm63xx_cs_lock, flags);
val = bcm_mpi_readl(MPI_CSCTL_REG(cs));
val &= ~(MPI_CSCTL_WAIT_MASK);
val &= ~(MPI_CSCTL_SETUP_MASK);
val &= ~(MPI_CSCTL_HOLD_MASK);
val |= wait << MPI_CSCTL_WAIT_SHIFT;
val |= setup << MPI_CSCTL_SETUP_SHIFT;
val |= hold << MPI_CSCTL_HOLD_SHIFT;
bcm_mpi_writel(val, MPI_CSCTL_REG(cs));
spin_unlock_irqrestore(&bcm63xx_cs_lock, flags);
return 0;
}
int bcm63xx_set_cs_param(unsigned int cs, u32 params)
{
unsigned long flags;
u32 val;
if (!is_valid_cs(cs))
return -EINVAL;
if (cs == MPI_CS_PCMCIA_COMMON ||
cs == MPI_CS_PCMCIA_ATTR ||
cs == MPI_CS_PCMCIA_IO)
return -EINVAL;
spin_lock_irqsave(&bcm63xx_cs_lock, flags);
val = bcm_mpi_readl(MPI_CSCTL_REG(cs));
val &= ~(MPI_CSCTL_DATA16_MASK);
val &= ~(MPI_CSCTL_SYNCMODE_MASK);
val &= ~(MPI_CSCTL_TSIZE_MASK);
val &= ~(MPI_CSCTL_ENDIANSWAP_MASK);
val |= params;
bcm_mpi_writel(val, MPI_CSCTL_REG(cs));
spin_unlock_irqrestore(&bcm63xx_cs_lock, flags);
return 0;
}
int bcm63xx_set_cs_status(unsigned int cs, int enable)
{
unsigned long flags;
u32 val;
if (!is_valid_cs(cs))
return -EINVAL;
spin_lock_irqsave(&bcm63xx_cs_lock, flags);
val = bcm_mpi_readl(MPI_CSCTL_REG(cs));
if (enable)
val |= MPI_CSCTL_ENABLE_MASK;
else
val &= ~MPI_CSCTL_ENABLE_MASK;
bcm_mpi_writel(val, MPI_CSCTL_REG(cs));
spin_unlock_irqrestore(&bcm63xx_cs_lock, flags);
return 0;
}
