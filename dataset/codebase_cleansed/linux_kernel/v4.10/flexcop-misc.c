void flexcop_determine_revision(struct flexcop_device *fc)
{
flexcop_ibi_value v = fc->read_ibi_reg(fc,misc_204);
switch (v.misc_204.Rev_N_sig_revision_hi) {
case 0x2:
deb_info("found a FlexCopII.\n");
fc->rev = FLEXCOP_II;
break;
case 0x3:
deb_info("found a FlexCopIIb.\n");
fc->rev = FLEXCOP_IIB;
break;
case 0x0:
deb_info("found a FlexCopIII.\n");
fc->rev = FLEXCOP_III;
break;
default:
err("unknown FlexCop Revision: %x. Please report this to linux-dvb@linuxtv.org.",
v.misc_204.Rev_N_sig_revision_hi);
break;
}
if ((fc->has_32_hw_pid_filter = v.misc_204.Rev_N_sig_caps))
deb_info("this FlexCop has the additional 32 hardware pid filter.\n");
else
deb_info("this FlexCop has the 6 basic main hardware pid filter.\n");
}
void flexcop_device_name(struct flexcop_device *fc,
const char *prefix, const char *suffix)
{
info("%s '%s' at the '%s' bus controlled by a '%s' %s",
prefix, flexcop_device_names[fc->dev_type],
flexcop_bus_names[fc->bus_type],
flexcop_revision_names[fc->rev], suffix);
}
void flexcop_dump_reg(struct flexcop_device *fc,
flexcop_ibi_register reg, int num)
{
flexcop_ibi_value v;
int i;
for (i = 0; i < num; i++) {
v = fc->read_ibi_reg(fc, reg+4*i);
deb_rdump("0x%03x: %08x, ", reg+4*i, v.raw);
}
deb_rdump("\n");
}
