void __init bcm47xx_leds_register(void)
{
enum bcm47xx_board board = bcm47xx_board_get();
switch (board) {
case BCM47XX_BOARD_ASUS_RTN12:
bcm47xx_set_pdata(bcm47xx_leds_asus_rtn12);
break;
case BCM47XX_BOARD_ASUS_RTN16:
bcm47xx_set_pdata(bcm47xx_leds_asus_rtn16);
break;
case BCM47XX_BOARD_ASUS_RTN66U:
bcm47xx_set_pdata(bcm47xx_leds_asus_rtn66u);
break;
case BCM47XX_BOARD_ASUS_WL300G:
bcm47xx_set_pdata(bcm47xx_leds_asus_wl300g);
break;
case BCM47XX_BOARD_ASUS_WL320GE:
bcm47xx_set_pdata(bcm47xx_leds_asus_wl320ge);
break;
case BCM47XX_BOARD_ASUS_WL330GE:
bcm47xx_set_pdata(bcm47xx_leds_asus_wl330ge);
break;
case BCM47XX_BOARD_ASUS_WL500GD:
bcm47xx_set_pdata(bcm47xx_leds_asus_wl500gd);
break;
case BCM47XX_BOARD_ASUS_WL500GPV1:
bcm47xx_set_pdata(bcm47xx_leds_asus_wl500gpv1);
break;
case BCM47XX_BOARD_ASUS_WL500GPV2:
bcm47xx_set_pdata(bcm47xx_leds_asus_wl500gpv2);
break;
case BCM47XX_BOARD_ASUS_WL500W:
bcm47xx_set_pdata(bcm47xx_leds_asus_wl500w);
break;
case BCM47XX_BOARD_ASUS_WL520GC:
bcm47xx_set_pdata(bcm47xx_leds_asus_wl520gc);
break;
case BCM47XX_BOARD_ASUS_WL520GU:
bcm47xx_set_pdata(bcm47xx_leds_asus_wl520gu);
break;
case BCM47XX_BOARD_ASUS_WL700GE:
bcm47xx_set_pdata(bcm47xx_leds_asus_wl700ge);
break;
case BCM47XX_BOARD_ASUS_WLHDD:
bcm47xx_set_pdata(bcm47xx_leds_asus_wlhdd);
break;
case BCM47XX_BOARD_BELKIN_F7D4301:
bcm47xx_set_pdata(bcm47xx_leds_belkin_f7d4301);
break;
case BCM47XX_BOARD_BUFFALO_WHR2_A54G54:
bcm47xx_set_pdata(bcm47xx_leds_buffalo_whr2_a54g54);
break;
case BCM47XX_BOARD_BUFFALO_WHR_G125:
bcm47xx_set_pdata(bcm47xx_leds_buffalo_whr_g125);
break;
case BCM47XX_BOARD_BUFFALO_WHR_G54S:
bcm47xx_set_pdata(bcm47xx_leds_buffalo_whr_g54s);
break;
case BCM47XX_BOARD_BUFFALO_WHR_HP_G54:
bcm47xx_set_pdata(bcm47xx_leds_buffalo_whr_hp_g54);
break;
case BCM47XX_BOARD_BUFFALO_WZR_G300N:
bcm47xx_set_pdata(bcm47xx_leds_buffalo_wzr_g300n);
break;
case BCM47XX_BOARD_BUFFALO_WZR_RS_G54:
bcm47xx_set_pdata(bcm47xx_leds_buffalo_wzr_rs_g54);
break;
case BCM47XX_BOARD_BUFFALO_WZR_RS_G54HP:
bcm47xx_set_pdata(bcm47xx_leds_buffalo_wzr_rs_g54hp);
break;
case BCM47XX_BOARD_DELL_TM2300:
bcm47xx_set_pdata(bcm47xx_leds_dell_tm2300);
break;
case BCM47XX_BOARD_DLINK_DIR130:
bcm47xx_set_pdata(bcm47xx_leds_dlink_dir130);
break;
case BCM47XX_BOARD_DLINK_DIR330:
bcm47xx_set_pdata(bcm47xx_leds_dlink_dir330);
break;
case BCM47XX_BOARD_HUAWEI_E970:
bcm47xx_set_pdata(bcm47xx_leds_huawei_e970);
break;
case BCM47XX_BOARD_LINKSYS_E1000V1:
bcm47xx_set_pdata(bcm47xx_leds_linksys_e1000v1);
break;
case BCM47XX_BOARD_LINKSYS_E1000V21:
bcm47xx_set_pdata(bcm47xx_leds_linksys_e1000v21);
break;
case BCM47XX_BOARD_LINKSYS_E2000V1:
bcm47xx_set_pdata(bcm47xx_leds_linksys_e2000v1);
break;
case BCM47XX_BOARD_LINKSYS_E3000V1:
bcm47xx_set_pdata(bcm47xx_leds_linksys_e3000v1);
break;
case BCM47XX_BOARD_LINKSYS_E3200V1:
bcm47xx_set_pdata(bcm47xx_leds_linksys_e3200v1);
break;
case BCM47XX_BOARD_LINKSYS_E4200V1:
bcm47xx_set_pdata(bcm47xx_leds_linksys_e4200v1);
break;
case BCM47XX_BOARD_LINKSYS_WRT150NV1:
bcm47xx_set_pdata(bcm47xx_leds_linksys_wrt150nv1);
break;
case BCM47XX_BOARD_LINKSYS_WRT150NV11:
bcm47xx_set_pdata(bcm47xx_leds_linksys_wrt150nv11);
break;
case BCM47XX_BOARD_LINKSYS_WRT160NV1:
bcm47xx_set_pdata(bcm47xx_leds_linksys_wrt160nv1);
break;
case BCM47XX_BOARD_LINKSYS_WRT160NV3:
bcm47xx_set_pdata(bcm47xx_leds_linksys_wrt160nv3);
break;
case BCM47XX_BOARD_LINKSYS_WRT300NV11:
bcm47xx_set_pdata(bcm47xx_leds_linksys_wrt300nv11);
break;
case BCM47XX_BOARD_LINKSYS_WRT310NV1:
bcm47xx_set_pdata(bcm47xx_leds_linksys_wrt310nv1);
break;
case BCM47XX_BOARD_LINKSYS_WRT610NV1:
bcm47xx_set_pdata(bcm47xx_leds_linksys_wrt610nv1);
break;
case BCM47XX_BOARD_LINKSYS_WRT610NV2:
bcm47xx_set_pdata(bcm47xx_leds_linksys_wrt610nv2);
break;
case BCM47XX_BOARD_MOTOROLA_WE800G:
bcm47xx_set_pdata(bcm47xx_leds_motorola_we800g);
break;
case BCM47XX_BOARD_MOTOROLA_WR850GP:
bcm47xx_set_pdata(bcm47xx_leds_motorola_wr850gp);
break;
case BCM47XX_BOARD_MOTOROLA_WR850GV2V3:
bcm47xx_set_pdata(bcm47xx_leds_motorola_wr850gv2v3);
break;
case BCM47XX_BOARD_NETGEAR_WNDR3400V1:
bcm47xx_set_pdata(bcm47xx_leds_netgear_wndr3400v1);
break;
case BCM47XX_BOARD_NETGEAR_WNDR4500V1:
bcm47xx_set_pdata(bcm47xx_leds_netgear_wndr4500v1);
break;
case BCM47XX_BOARD_NETGEAR_WNR834BV2:
bcm47xx_set_pdata(bcm47xx_leds_netgear_wnr834bv2);
break;
case BCM47XX_BOARD_SIMPLETECH_SIMPLESHARE:
bcm47xx_set_pdata(bcm47xx_leds_simpletech_simpleshare);
break;
default:
pr_debug("No LEDs configuration found for this device\n");
return;
}
gpio_led_register_device(-1, &bcm47xx_leds_pdata);
}
