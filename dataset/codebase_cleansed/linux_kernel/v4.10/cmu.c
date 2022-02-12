void vr41xx_supply_clock(vr41xx_clock_t clock)
{
spin_lock_irq(&cmu_lock);
switch (clock) {
case PIU_CLOCK:
cmuclkmsk |= MSKPIU;
break;
case SIU_CLOCK:
cmuclkmsk |= MSKSIU | MSKSSIU;
break;
case AIU_CLOCK:
cmuclkmsk |= MSKAIU;
break;
case KIU_CLOCK:
cmuclkmsk |= MSKKIU;
break;
case FIR_CLOCK:
cmuclkmsk |= MSKFIR | MSKFFIR;
break;
case DSIU_CLOCK:
if (current_cpu_type() == CPU_VR4111 ||
current_cpu_type() == CPU_VR4121)
cmuclkmsk |= MSKDSIU;
else
cmuclkmsk |= MSKSIU | MSKDSIU;
break;
case CSI_CLOCK:
cmuclkmsk |= MSKCSI | MSKSCSI;
break;
case PCIU_CLOCK:
cmuclkmsk |= MSKPCIU;
break;
case HSP_CLOCK:
cmuclkmsk |= MSKSHSP;
break;
case PCI_CLOCK:
cmuclkmsk |= MSKPPCIU;
break;
case CEU_CLOCK:
cmuclkmsk2 |= MSKCEU;
break;
case ETHER0_CLOCK:
cmuclkmsk2 |= MSKMAC0;
break;
case ETHER1_CLOCK:
cmuclkmsk2 |= MSKMAC1;
break;
default:
break;
}
if (clock == CEU_CLOCK || clock == ETHER0_CLOCK ||
clock == ETHER1_CLOCK)
cmu_write(CMUCLKMSK2, cmuclkmsk2);
else
cmu_write(CMUCLKMSK, cmuclkmsk);
spin_unlock_irq(&cmu_lock);
}
void vr41xx_mask_clock(vr41xx_clock_t clock)
{
spin_lock_irq(&cmu_lock);
switch (clock) {
case PIU_CLOCK:
cmuclkmsk &= ~MSKPIU;
break;
case SIU_CLOCK:
if (current_cpu_type() == CPU_VR4111 ||
current_cpu_type() == CPU_VR4121) {
cmuclkmsk &= ~(MSKSIU | MSKSSIU);
} else {
if (cmuclkmsk & MSKDSIU)
cmuclkmsk &= ~MSKSSIU;
else
cmuclkmsk &= ~(MSKSIU | MSKSSIU);
}
break;
case AIU_CLOCK:
cmuclkmsk &= ~MSKAIU;
break;
case KIU_CLOCK:
cmuclkmsk &= ~MSKKIU;
break;
case FIR_CLOCK:
cmuclkmsk &= ~(MSKFIR | MSKFFIR);
break;
case DSIU_CLOCK:
if (current_cpu_type() == CPU_VR4111 ||
current_cpu_type() == CPU_VR4121) {
cmuclkmsk &= ~MSKDSIU;
} else {
if (cmuclkmsk & MSKSSIU)
cmuclkmsk &= ~MSKDSIU;
else
cmuclkmsk &= ~(MSKSIU | MSKDSIU);
}
break;
case CSI_CLOCK:
cmuclkmsk &= ~(MSKCSI | MSKSCSI);
break;
case PCIU_CLOCK:
cmuclkmsk &= ~MSKPCIU;
break;
case HSP_CLOCK:
cmuclkmsk &= ~MSKSHSP;
break;
case PCI_CLOCK:
cmuclkmsk &= ~MSKPPCIU;
break;
case CEU_CLOCK:
cmuclkmsk2 &= ~MSKCEU;
break;
case ETHER0_CLOCK:
cmuclkmsk2 &= ~MSKMAC0;
break;
case ETHER1_CLOCK:
cmuclkmsk2 &= ~MSKMAC1;
break;
default:
break;
}
if (clock == CEU_CLOCK || clock == ETHER0_CLOCK ||
clock == ETHER1_CLOCK)
cmu_write(CMUCLKMSK2, cmuclkmsk2);
else
cmu_write(CMUCLKMSK, cmuclkmsk);
spin_unlock_irq(&cmu_lock);
}
static int __init vr41xx_cmu_init(void)
{
unsigned long start, size;
switch (current_cpu_type()) {
case CPU_VR4111:
case CPU_VR4121:
start = CMU_TYPE1_BASE;
size = CMU_TYPE1_SIZE;
break;
case CPU_VR4122:
case CPU_VR4131:
start = CMU_TYPE2_BASE;
size = CMU_TYPE2_SIZE;
break;
case CPU_VR4133:
start = CMU_TYPE3_BASE;
size = CMU_TYPE3_SIZE;
break;
default:
panic("Unexpected CPU of NEC VR4100 series");
break;
}
if (request_mem_region(start, size, "CMU") == NULL)
return -EBUSY;
cmu_base = ioremap(start, size);
if (cmu_base == NULL) {
release_mem_region(start, size);
return -EBUSY;
}
cmuclkmsk = cmu_read(CMUCLKMSK);
if (current_cpu_type() == CPU_VR4133)
cmuclkmsk2 = cmu_read(CMUCLKMSK2);
spin_lock_init(&cmu_lock);
return 0;
}
