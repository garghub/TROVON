void intel_device_info_dump(struct drm_i915_private *dev_priv)
{
const struct intel_device_info *info = &dev_priv->info;
#define PRINT_S(name) "%s"
#define SEP_EMPTY
#define PRINT_FLAG(name) info->name ? #name "," : ""
#define SEP_COMMA ,
DRM_DEBUG_DRIVER("i915 device info: gen=%i, pciid=0x%04x rev=0x%02x flags="
DEV_INFO_FOR_EACH_FLAG(PRINT_S, SEP_EMPTY),
info->gen,
dev_priv->drm.pdev->device,
dev_priv->drm.pdev->revision,
DEV_INFO_FOR_EACH_FLAG(PRINT_FLAG, SEP_COMMA));
#undef PRINT_S
#undef SEP_EMPTY
#undef PRINT_FLAG
#undef SEP_COMMA
}
static void cherryview_sseu_info_init(struct drm_i915_private *dev_priv)
{
struct intel_device_info *info = mkwrite_device_info(dev_priv);
u32 fuse, eu_dis;
fuse = I915_READ(CHV_FUSE_GT);
info->slice_total = 1;
if (!(fuse & CHV_FGT_DISABLE_SS0)) {
info->subslice_per_slice++;
eu_dis = fuse & (CHV_FGT_EU_DIS_SS0_R0_MASK |
CHV_FGT_EU_DIS_SS0_R1_MASK);
info->eu_total += 8 - hweight32(eu_dis);
}
if (!(fuse & CHV_FGT_DISABLE_SS1)) {
info->subslice_per_slice++;
eu_dis = fuse & (CHV_FGT_EU_DIS_SS1_R0_MASK |
CHV_FGT_EU_DIS_SS1_R1_MASK);
info->eu_total += 8 - hweight32(eu_dis);
}
info->subslice_total = info->subslice_per_slice;
info->eu_per_subslice = info->subslice_total ?
info->eu_total / info->subslice_total :
0;
info->has_slice_pg = 0;
info->has_subslice_pg = (info->subslice_total > 1);
info->has_eu_pg = (info->eu_per_subslice > 2);
}
static void gen9_sseu_info_init(struct drm_i915_private *dev_priv)
{
struct intel_device_info *info = mkwrite_device_info(dev_priv);
int s_max = 3, ss_max = 4, eu_max = 8;
int s, ss;
u32 fuse2, s_enable, ss_disable, eu_disable;
u8 eu_mask = 0xff;
fuse2 = I915_READ(GEN8_FUSE2);
s_enable = (fuse2 & GEN8_F2_S_ENA_MASK) >> GEN8_F2_S_ENA_SHIFT;
ss_disable = (fuse2 & GEN9_F2_SS_DIS_MASK) >> GEN9_F2_SS_DIS_SHIFT;
info->slice_total = hweight32(s_enable);
info->subslice_per_slice = ss_max - hweight32(ss_disable);
info->subslice_total = info->slice_total * info->subslice_per_slice;
for (s = 0; s < s_max; s++) {
if (!(s_enable & BIT(s)))
continue;
eu_disable = I915_READ(GEN9_EU_DISABLE(s));
for (ss = 0; ss < ss_max; ss++) {
int eu_per_ss;
if (ss_disable & BIT(ss))
continue;
eu_per_ss = eu_max - hweight8((eu_disable >> (ss*8)) &
eu_mask);
if (eu_per_ss == 7)
info->subslice_7eu[s] |= BIT(ss);
info->eu_total += eu_per_ss;
}
}
info->eu_per_subslice = info->subslice_total ?
DIV_ROUND_UP(info->eu_total,
info->subslice_total) : 0;
info->has_slice_pg =
(IS_SKYLAKE(dev_priv) || IS_KABYLAKE(dev_priv)) &&
info->slice_total > 1;
info->has_subslice_pg =
IS_BROXTON(dev_priv) && info->subslice_total > 1;
info->has_eu_pg = info->eu_per_subslice > 2;
if (IS_BROXTON(dev_priv)) {
#define IS_SS_DISABLED(_ss_disable, ss) (_ss_disable & BIT(ss))
info->has_pooled_eu = ((info->subslice_per_slice == 3) ||
(info->subslice_per_slice == 2 &&
INTEL_REVID(dev_priv) < BXT_REVID_C0));
info->min_eu_in_pool = 0;
if (info->has_pooled_eu) {
if (IS_SS_DISABLED(ss_disable, 0) ||
IS_SS_DISABLED(ss_disable, 2))
info->min_eu_in_pool = 3;
else if (IS_SS_DISABLED(ss_disable, 1))
info->min_eu_in_pool = 6;
else
info->min_eu_in_pool = 9;
}
#undef IS_SS_DISABLED
}
}
static void broadwell_sseu_info_init(struct drm_i915_private *dev_priv)
{
struct intel_device_info *info = mkwrite_device_info(dev_priv);
const int s_max = 3, ss_max = 3, eu_max = 8;
int s, ss;
u32 fuse2, eu_disable[s_max], s_enable, ss_disable;
fuse2 = I915_READ(GEN8_FUSE2);
s_enable = (fuse2 & GEN8_F2_S_ENA_MASK) >> GEN8_F2_S_ENA_SHIFT;
ss_disable = (fuse2 & GEN8_F2_SS_DIS_MASK) >> GEN8_F2_SS_DIS_SHIFT;
eu_disable[0] = I915_READ(GEN8_EU_DISABLE0) & GEN8_EU_DIS0_S0_MASK;
eu_disable[1] = (I915_READ(GEN8_EU_DISABLE0) >> GEN8_EU_DIS0_S1_SHIFT) |
((I915_READ(GEN8_EU_DISABLE1) & GEN8_EU_DIS1_S1_MASK) <<
(32 - GEN8_EU_DIS0_S1_SHIFT));
eu_disable[2] = (I915_READ(GEN8_EU_DISABLE1) >> GEN8_EU_DIS1_S2_SHIFT) |
((I915_READ(GEN8_EU_DISABLE2) & GEN8_EU_DIS2_S2_MASK) <<
(32 - GEN8_EU_DIS1_S2_SHIFT));
info->slice_total = hweight32(s_enable);
info->subslice_per_slice = ss_max - hweight32(ss_disable);
info->subslice_total = info->slice_total * info->subslice_per_slice;
for (s = 0; s < s_max; s++) {
if (!(s_enable & (0x1 << s)))
continue;
for (ss = 0; ss < ss_max; ss++) {
u32 n_disabled;
if (ss_disable & (0x1 << ss))
continue;
n_disabled = hweight8(eu_disable[s] >> (ss * eu_max));
if (eu_max - n_disabled == 7)
info->subslice_7eu[s] |= 1 << ss;
info->eu_total += eu_max - n_disabled;
}
}
info->eu_per_subslice = info->subslice_total ?
DIV_ROUND_UP(info->eu_total, info->subslice_total) : 0;
info->has_slice_pg = (info->slice_total > 1);
info->has_subslice_pg = 0;
info->has_eu_pg = 0;
}
void intel_device_info_runtime_init(struct drm_i915_private *dev_priv)
{
struct intel_device_info *info = mkwrite_device_info(dev_priv);
enum pipe pipe;
if (IS_BROXTON(dev_priv)) {
info->num_sprites[PIPE_A] = 2;
info->num_sprites[PIPE_B] = 2;
info->num_sprites[PIPE_C] = 1;
} else if (IS_VALLEYVIEW(dev_priv) || IS_CHERRYVIEW(dev_priv))
for_each_pipe(dev_priv, pipe)
info->num_sprites[pipe] = 2;
else
for_each_pipe(dev_priv, pipe)
info->num_sprites[pipe] = 1;
if (i915.disable_display) {
DRM_INFO("Display disabled (module parameter)\n");
info->num_pipes = 0;
} else if (info->num_pipes > 0 &&
(IS_GEN7(dev_priv) || IS_GEN8(dev_priv)) &&
HAS_PCH_SPLIT(dev_priv)) {
u32 fuse_strap = I915_READ(FUSE_STRAP);
u32 sfuse_strap = I915_READ(SFUSE_STRAP);
if (fuse_strap & ILK_INTERNAL_DISPLAY_DISABLE ||
sfuse_strap & SFUSE_STRAP_DISPLAY_DISABLED ||
(dev_priv->pch_type == PCH_CPT &&
!(sfuse_strap & SFUSE_STRAP_FUSE_LOCK))) {
DRM_INFO("Display fused off, disabling\n");
info->num_pipes = 0;
} else if (fuse_strap & IVB_PIPE_C_DISABLE) {
DRM_INFO("PipeC fused off\n");
info->num_pipes -= 1;
}
} else if (info->num_pipes > 0 && IS_GEN9(dev_priv)) {
u32 dfsm = I915_READ(SKL_DFSM);
u8 disabled_mask = 0;
bool invalid;
int num_bits;
if (dfsm & SKL_DFSM_PIPE_A_DISABLE)
disabled_mask |= BIT(PIPE_A);
if (dfsm & SKL_DFSM_PIPE_B_DISABLE)
disabled_mask |= BIT(PIPE_B);
if (dfsm & SKL_DFSM_PIPE_C_DISABLE)
disabled_mask |= BIT(PIPE_C);
num_bits = hweight8(disabled_mask);
switch (disabled_mask) {
case BIT(PIPE_A):
case BIT(PIPE_B):
case BIT(PIPE_A) | BIT(PIPE_B):
case BIT(PIPE_A) | BIT(PIPE_C):
invalid = true;
break;
default:
invalid = false;
}
if (num_bits > info->num_pipes || invalid)
DRM_ERROR("invalid pipe fuse configuration: 0x%x\n",
disabled_mask);
else
info->num_pipes -= num_bits;
}
if (IS_CHERRYVIEW(dev_priv))
cherryview_sseu_info_init(dev_priv);
else if (IS_BROADWELL(dev_priv))
broadwell_sseu_info_init(dev_priv);
else if (INTEL_INFO(dev_priv)->gen >= 9)
gen9_sseu_info_init(dev_priv);
info->has_snoop = !info->has_llc;
if (IS_BXT_REVID(dev_priv, 0, BXT_REVID_A1))
info->has_snoop = false;
DRM_DEBUG_DRIVER("slice total: %u\n", info->slice_total);
DRM_DEBUG_DRIVER("subslice total: %u\n", info->subslice_total);
DRM_DEBUG_DRIVER("subslice per slice: %u\n", info->subslice_per_slice);
DRM_DEBUG_DRIVER("EU total: %u\n", info->eu_total);
DRM_DEBUG_DRIVER("EU per subslice: %u\n", info->eu_per_subslice);
DRM_DEBUG_DRIVER("has slice power gating: %s\n",
info->has_slice_pg ? "y" : "n");
DRM_DEBUG_DRIVER("has subslice power gating: %s\n",
info->has_subslice_pg ? "y" : "n");
DRM_DEBUG_DRIVER("has EU power gating: %s\n",
info->has_eu_pg ? "y" : "n");
}
