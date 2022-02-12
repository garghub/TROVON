static inline void grackle_set_stg(struct pci_controller* bp, int enable)
{
unsigned int val;
out_be32(bp->cfg_addr, GRACKLE_CFA(0, 0, 0xa8));
val = in_le32(bp->cfg_data);
val = enable? (val | GRACKLE_PICR1_STG) :
(val & ~GRACKLE_PICR1_STG);
out_be32(bp->cfg_addr, GRACKLE_CFA(0, 0, 0xa8));
out_le32(bp->cfg_data, val);
(void)in_le32(bp->cfg_data);
}
static inline void grackle_set_loop_snoop(struct pci_controller *bp, int enable)
{
unsigned int val;
out_be32(bp->cfg_addr, GRACKLE_CFA(0, 0, 0xa8));
val = in_le32(bp->cfg_data);
val = enable? (val | GRACKLE_PICR1_LOOPSNOOP) :
(val & ~GRACKLE_PICR1_LOOPSNOOP);
out_be32(bp->cfg_addr, GRACKLE_CFA(0, 0, 0xa8));
out_le32(bp->cfg_data, val);
(void)in_le32(bp->cfg_data);
}
void __init setup_grackle(struct pci_controller *hose)
{
setup_indirect_pci(hose, 0xfec00000, 0xfee00000, 0);
if (of_machine_is_compatible("PowerMac1,1"))
ppc_pci_add_flags(PPC_PCI_REASSIGN_ALL_BUS);
if (of_machine_is_compatible("AAPL,PowerBook1998"))
grackle_set_loop_snoop(hose, 1);
#if 0
grackle_set_stg(hose, 1);
#endif
}
