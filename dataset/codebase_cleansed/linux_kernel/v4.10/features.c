void xen_setup_features(void)
{
struct xen_feature_info fi;
int i, j;
for (i = 0; i < XENFEAT_NR_SUBMAPS; i++) {
fi.submap_idx = i;
if (HYPERVISOR_xen_version(XENVER_get_features, &fi) < 0)
break;
for (j = 0; j < 32; j++)
xen_features[i * 32 + j] = !!(fi.submap & 1<<j);
}
}
