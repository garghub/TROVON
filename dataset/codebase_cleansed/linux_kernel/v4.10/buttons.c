static int __init bcm47xx_buttons_copy(const struct gpio_keys_button *buttons,
size_t nbuttons)
{
size_t size = nbuttons * sizeof(*buttons);
bcm47xx_button_pdata.buttons = kmemdup(buttons, size, GFP_KERNEL);
if (!bcm47xx_button_pdata.buttons)
return -ENOMEM;
bcm47xx_button_pdata.nbuttons = nbuttons;
return 0;
}
int __init bcm47xx_buttons_register(void)
{
enum bcm47xx_board board = bcm47xx_board_get();
int err;
switch (board) {
case BCM47XX_BOARD_ASUS_RTN12:
err = bcm47xx_copy_bdata(bcm47xx_buttons_asus_rtn12);
break;
case BCM47XX_BOARD_ASUS_RTN16:
err = bcm47xx_copy_bdata(bcm47xx_buttons_asus_rtn16);
break;
case BCM47XX_BOARD_ASUS_RTN66U:
err = bcm47xx_copy_bdata(bcm47xx_buttons_asus_rtn66u);
break;
case BCM47XX_BOARD_ASUS_WL300G:
err = bcm47xx_copy_bdata(bcm47xx_buttons_asus_wl300g);
break;
case BCM47XX_BOARD_ASUS_WL320GE:
err = bcm47xx_copy_bdata(bcm47xx_buttons_asus_wl320ge);
break;
case BCM47XX_BOARD_ASUS_WL330GE:
err = bcm47xx_copy_bdata(bcm47xx_buttons_asus_wl330ge);
break;
case BCM47XX_BOARD_ASUS_WL500G:
err = bcm47xx_copy_bdata(bcm47xx_buttons_asus_wl500g);
break;
case BCM47XX_BOARD_ASUS_WL500GD:
err = bcm47xx_copy_bdata(bcm47xx_buttons_asus_wl500gd);
break;
case BCM47XX_BOARD_ASUS_WL500GPV1:
err = bcm47xx_copy_bdata(bcm47xx_buttons_asus_wl500gpv1);
break;
case BCM47XX_BOARD_ASUS_WL500GPV2:
err = bcm47xx_copy_bdata(bcm47xx_buttons_asus_wl500gpv2);
break;
case BCM47XX_BOARD_ASUS_WL500W:
err = bcm47xx_copy_bdata(bcm47xx_buttons_asus_wl500w);
break;
case BCM47XX_BOARD_ASUS_WL520GC:
err = bcm47xx_copy_bdata(bcm47xx_buttons_asus_wl520gc);
break;
case BCM47XX_BOARD_ASUS_WL520GU:
err = bcm47xx_copy_bdata(bcm47xx_buttons_asus_wl520gu);
break;
case BCM47XX_BOARD_ASUS_WL700GE:
err = bcm47xx_copy_bdata(bcm47xx_buttons_asus_wl700ge);
break;
case BCM47XX_BOARD_ASUS_WLHDD:
err = bcm47xx_copy_bdata(bcm47xx_buttons_asus_wlhdd);
break;
case BCM47XX_BOARD_BELKIN_F7D3301:
case BCM47XX_BOARD_BELKIN_F7D3302:
case BCM47XX_BOARD_BELKIN_F7D4301:
case BCM47XX_BOARD_BELKIN_F7D4302:
case BCM47XX_BOARD_BELKIN_F7D4401:
err = bcm47xx_copy_bdata(bcm47xx_buttons_belkin_f7d4301);
break;
case BCM47XX_BOARD_BUFFALO_WHR2_A54G54:
err = bcm47xx_copy_bdata(bcm47xx_buttons_buffalo_whr2_a54g54);
break;
case BCM47XX_BOARD_BUFFALO_WHR_G125:
err = bcm47xx_copy_bdata(bcm47xx_buttons_buffalo_whr_g125);
break;
case BCM47XX_BOARD_BUFFALO_WHR_G54S:
err = bcm47xx_copy_bdata(bcm47xx_buttons_buffalo_whr_g54s);
break;
case BCM47XX_BOARD_BUFFALO_WHR_HP_G54:
err = bcm47xx_copy_bdata(bcm47xx_buttons_buffalo_whr_hp_g54);
break;
case BCM47XX_BOARD_BUFFALO_WZR_G300N:
err = bcm47xx_copy_bdata(bcm47xx_buttons_buffalo_wzr_g300n);
break;
case BCM47XX_BOARD_BUFFALO_WZR_RS_G54:
err = bcm47xx_copy_bdata(bcm47xx_buttons_buffalo_wzr_rs_g54);
break;
case BCM47XX_BOARD_BUFFALO_WZR_RS_G54HP:
err = bcm47xx_copy_bdata(bcm47xx_buttons_buffalo_wzr_rs_g54hp);
break;
case BCM47XX_BOARD_DELL_TM2300:
err = bcm47xx_copy_bdata(bcm47xx_buttons_dell_tm2300);
break;
case BCM47XX_BOARD_DLINK_DIR130:
err = bcm47xx_copy_bdata(bcm47xx_buttons_dlink_dir130);
break;
case BCM47XX_BOARD_DLINK_DIR330:
err = bcm47xx_copy_bdata(bcm47xx_buttons_dlink_dir330);
break;
case BCM47XX_BOARD_HUAWEI_E970:
err = bcm47xx_copy_bdata(bcm47xx_buttons_huawei_e970);
break;
case BCM47XX_BOARD_LINKSYS_E1000V1:
err = bcm47xx_copy_bdata(bcm47xx_buttons_linksys_e1000v1);
break;
case BCM47XX_BOARD_LINKSYS_E1000V21:
err = bcm47xx_copy_bdata(bcm47xx_buttons_linksys_e1000v21);
break;
case BCM47XX_BOARD_LINKSYS_E2000V1:
err = bcm47xx_copy_bdata(bcm47xx_buttons_linksys_e2000v1);
break;
case BCM47XX_BOARD_LINKSYS_E3000V1:
err = bcm47xx_copy_bdata(bcm47xx_buttons_linksys_e3000v1);
break;
case BCM47XX_BOARD_LINKSYS_E3200V1:
err = bcm47xx_copy_bdata(bcm47xx_buttons_linksys_e3200v1);
break;
case BCM47XX_BOARD_LINKSYS_E4200V1:
err = bcm47xx_copy_bdata(bcm47xx_buttons_linksys_e4200v1);
break;
case BCM47XX_BOARD_LINKSYS_WRT150NV1:
err = bcm47xx_copy_bdata(bcm47xx_buttons_linksys_wrt150nv1);
break;
case BCM47XX_BOARD_LINKSYS_WRT150NV11:
err = bcm47xx_copy_bdata(bcm47xx_buttons_linksys_wrt150nv11);
break;
case BCM47XX_BOARD_LINKSYS_WRT160NV1:
err = bcm47xx_copy_bdata(bcm47xx_buttons_linksys_wrt160nv1);
break;
case BCM47XX_BOARD_LINKSYS_WRT160NV3:
err = bcm47xx_copy_bdata(bcm47xx_buttons_linksys_wrt160nv3);
break;
case BCM47XX_BOARD_LINKSYS_WRT300N_V1:
err = bcm47xx_copy_bdata(bcm47xx_buttons_linksys_wrt300n_v1);
break;
case BCM47XX_BOARD_LINKSYS_WRT300NV11:
err = bcm47xx_copy_bdata(bcm47xx_buttons_linksys_wrt300nv11);
break;
case BCM47XX_BOARD_LINKSYS_WRT310NV1:
err = bcm47xx_copy_bdata(bcm47xx_buttons_linksys_wrt310nv1);
break;
case BCM47XX_BOARD_LINKSYS_WRT54G3GV2:
err = bcm47xx_copy_bdata(bcm47xx_buttons_linksys_wrt54g3gv2);
break;
case BCM47XX_BOARD_LINKSYS_WRT54G_TYPE_0101:
case BCM47XX_BOARD_LINKSYS_WRT54G_TYPE_0467:
case BCM47XX_BOARD_LINKSYS_WRT54G_TYPE_0708:
err = bcm47xx_copy_bdata(bcm47xx_buttons_linksys_wrt54g_generic);
break;
case BCM47XX_BOARD_LINKSYS_WRT610NV1:
err = bcm47xx_copy_bdata(bcm47xx_buttons_linksys_wrt610nv1);
break;
case BCM47XX_BOARD_LINKSYS_WRT610NV2:
err = bcm47xx_copy_bdata(bcm47xx_buttons_linksys_wrt610nv2);
break;
case BCM47XX_BOARD_LINKSYS_WRTSL54GS:
err = bcm47xx_copy_bdata(bcm47xx_buttons_linksys_wrtsl54gs);
break;
case BCM47XX_BOARD_LUXUL_XWR_1750_V1:
err = bcm47xx_copy_bdata(bcm47xx_buttons_luxul_xwr_1750_v1);
break;
case BCM47XX_BOARD_MICROSOFT_MN700:
err = bcm47xx_copy_bdata(bcm47xx_buttons_microsoft_nm700);
break;
case BCM47XX_BOARD_MOTOROLA_WE800G:
err = bcm47xx_copy_bdata(bcm47xx_buttons_motorola_we800g);
break;
case BCM47XX_BOARD_MOTOROLA_WR850GP:
err = bcm47xx_copy_bdata(bcm47xx_buttons_motorola_wr850gp);
break;
case BCM47XX_BOARD_MOTOROLA_WR850GV2V3:
err = bcm47xx_copy_bdata(bcm47xx_buttons_motorola_wr850gv2v3);
break;
case BCM47XX_BOARD_NETGEAR_WNDR3400V1:
err = bcm47xx_copy_bdata(bcm47xx_buttons_netgear_wndr3400v1);
break;
case BCM47XX_BOARD_NETGEAR_WNDR3400_V3:
err = bcm47xx_copy_bdata(bcm47xx_buttons_netgear_wndr3400_v3);
break;
case BCM47XX_BOARD_NETGEAR_WNDR3700V3:
err = bcm47xx_copy_bdata(bcm47xx_buttons_netgear_wndr3700v3);
break;
case BCM47XX_BOARD_NETGEAR_WNDR4500V1:
err = bcm47xx_copy_bdata(bcm47xx_buttons_netgear_wndr4500v1);
break;
case BCM47XX_BOARD_NETGEAR_WNR3500L:
err = bcm47xx_copy_bdata(bcm47xx_buttons_netgear_wnr3500lv1);
break;
case BCM47XX_BOARD_NETGEAR_WNR834BV2:
err = bcm47xx_copy_bdata(bcm47xx_buttons_netgear_wnr834bv2);
break;
case BCM47XX_BOARD_SIMPLETECH_SIMPLESHARE:
err = bcm47xx_copy_bdata(bcm47xx_buttons_simpletech_simpleshare);
break;
default:
pr_debug("No buttons configuration found for this device\n");
return -ENOTSUPP;
}
if (err)
return -ENOMEM;
err = platform_device_register(&bcm47xx_buttons_gpio_keys);
if (err) {
pr_err("Failed to register platform device: %d\n", err);
return err;
}
return 0;
}
