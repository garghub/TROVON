static int init_vgpu_opregion(struct intel_vgpu *vgpu, u32 gpa)
{
u8 *buf;
int i;
if (WARN((vgpu_opregion(vgpu)->va),
"vgpu%d: opregion has been initialized already.\n",
vgpu->id))
return -EINVAL;
vgpu_opregion(vgpu)->va = (void *)__get_free_pages(GFP_KERNEL |
__GFP_ZERO,
get_order(INTEL_GVT_OPREGION_SIZE));
if (!vgpu_opregion(vgpu)->va)
return -ENOMEM;
memcpy(vgpu_opregion(vgpu)->va, vgpu->gvt->opregion.opregion_va,
INTEL_GVT_OPREGION_SIZE);
for (i = 0; i < INTEL_GVT_OPREGION_PAGES; i++)
vgpu_opregion(vgpu)->gfn[i] = (gpa >> PAGE_SHIFT) + i;
buf = (u8 *)vgpu_opregion(vgpu)->va;
buf[INTEL_GVT_OPREGION_CLID] = 0x3;
return 0;
}
static int map_vgpu_opregion(struct intel_vgpu *vgpu, bool map)
{
u64 mfn;
int i, ret;
for (i = 0; i < INTEL_GVT_OPREGION_PAGES; i++) {
mfn = intel_gvt_hypervisor_virt_to_mfn(vgpu_opregion(vgpu)->va
+ i * PAGE_SIZE);
if (mfn == INTEL_GVT_INVALID_ADDR) {
gvt_vgpu_err("fail to get MFN from VA\n");
return -EINVAL;
}
ret = intel_gvt_hypervisor_map_gfn_to_mfn(vgpu,
vgpu_opregion(vgpu)->gfn[i],
mfn, 1, map);
if (ret) {
gvt_vgpu_err("fail to map GFN to MFN, errno: %d\n",
ret);
return ret;
}
}
return 0;
}
void intel_vgpu_clean_opregion(struct intel_vgpu *vgpu)
{
gvt_dbg_core("vgpu%d: clean vgpu opregion\n", vgpu->id);
if (!vgpu_opregion(vgpu)->va)
return;
if (intel_gvt_host.hypervisor_type == INTEL_GVT_HYPERVISOR_XEN) {
map_vgpu_opregion(vgpu, false);
free_pages((unsigned long)vgpu_opregion(vgpu)->va,
get_order(INTEL_GVT_OPREGION_SIZE));
vgpu_opregion(vgpu)->va = NULL;
}
}
int intel_vgpu_init_opregion(struct intel_vgpu *vgpu, u32 gpa)
{
int ret;
gvt_dbg_core("vgpu%d: init vgpu opregion\n", vgpu->id);
if (intel_gvt_host.hypervisor_type == INTEL_GVT_HYPERVISOR_XEN) {
gvt_dbg_core("emulate opregion from kernel\n");
ret = init_vgpu_opregion(vgpu, gpa);
if (ret)
return ret;
ret = map_vgpu_opregion(vgpu, true);
if (ret)
return ret;
}
return 0;
}
void intel_gvt_clean_opregion(struct intel_gvt *gvt)
{
memunmap(gvt->opregion.opregion_va);
gvt->opregion.opregion_va = NULL;
}
int intel_gvt_init_opregion(struct intel_gvt *gvt)
{
gvt_dbg_core("init host opregion\n");
pci_read_config_dword(gvt->dev_priv->drm.pdev, INTEL_GVT_PCI_OPREGION,
&gvt->opregion.opregion_pa);
gvt->opregion.opregion_va = memremap(gvt->opregion.opregion_pa,
INTEL_GVT_OPREGION_SIZE, MEMREMAP_WB);
if (!gvt->opregion.opregion_va) {
gvt_err("fail to map host opregion\n");
return -EFAULT;
}
return 0;
}
static const char *opregion_func_name(u32 func)
{
const char *name = NULL;
switch (func) {
case 0 ... 3:
case 5:
case 7 ... 15:
name = "Reserved";
break;
case 4:
name = "Get BIOS Data";
break;
case 6:
name = "System BIOS Callbacks";
break;
default:
name = "Unknown";
break;
}
return name;
}
static const char *opregion_subfunc_name(u32 subfunc)
{
const char *name = NULL;
switch (subfunc) {
case 0:
name = "Supported Calls";
break;
case 1:
name = "Requested Callbacks";
break;
case 2 ... 3:
case 8 ... 9:
name = "Reserved";
break;
case 5:
name = "Boot Display";
break;
case 6:
name = "TV-Standard/Video-Connector";
break;
case 7:
name = "Internal Graphics";
break;
case 10:
name = "Spread Spectrum Clocks";
break;
case 11:
name = "Get AKSV";
break;
default:
name = "Unknown";
break;
}
return name;
}
static bool querying_capabilities(u32 scic)
{
u32 func, subfunc;
func = GVT_OPREGION_FUNC(scic);
subfunc = GVT_OPREGION_SUBFUNC(scic);
if ((func == INTEL_GVT_OPREGION_SCIC_F_GETBIOSDATA &&
subfunc == INTEL_GVT_OPREGION_SCIC_SF_SUPPRTEDCALLS)
|| (func == INTEL_GVT_OPREGION_SCIC_F_GETBIOSDATA &&
subfunc == INTEL_GVT_OPREGION_SCIC_SF_REQEUSTEDCALLBACKS)
|| (func == INTEL_GVT_OPREGION_SCIC_F_GETBIOSCALLBACKS &&
subfunc == INTEL_GVT_OPREGION_SCIC_SF_SUPPRTEDCALLS)) {
return true;
}
return false;
}
int intel_vgpu_emulate_opregion_request(struct intel_vgpu *vgpu, u32 swsci)
{
u32 *scic, *parm;
u32 func, subfunc;
scic = vgpu_opregion(vgpu)->va + INTEL_GVT_OPREGION_SCIC;
parm = vgpu_opregion(vgpu)->va + INTEL_GVT_OPREGION_PARM;
if (!(swsci & SWSCI_SCI_SELECT)) {
gvt_vgpu_err("requesting SMI service\n");
return 0;
}
if ((vgpu_cfg_space(vgpu)[INTEL_GVT_PCI_SWSCI]
& SWSCI_SCI_TRIGGER) ||
!(swsci & SWSCI_SCI_TRIGGER)) {
return 0;
}
func = GVT_OPREGION_FUNC(*scic);
subfunc = GVT_OPREGION_SUBFUNC(*scic);
if (!querying_capabilities(*scic)) {
gvt_vgpu_err("requesting runtime service: func \"%s\","
" subfunc \"%s\"\n",
opregion_func_name(func),
opregion_subfunc_name(subfunc));
*scic &= ~OPREGION_SCIC_EXIT_MASK;
return 0;
}
*scic = 0;
*parm = 0;
return 0;
}
