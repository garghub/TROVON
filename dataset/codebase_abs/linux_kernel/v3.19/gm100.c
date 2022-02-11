int
F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case 0x117 :
V_2 -> V_4 = L_1 ;
V_2 -> V_5 [ V_6 ] = & V_7 ;
V_2 -> V_5 [ V_8 ] = V_9 ;
V_2 -> V_5 [ V_10 ] = V_11 ;
V_2 -> V_5 [ V_12 ] = & V_13 ;
V_2 -> V_5 [ V_14 ] = & V_15 ;
V_2 -> V_5 [ V_16 ] = & V_17 ;
V_2 -> V_5 [ V_18 ] = & V_19 ;
V_2 -> V_5 [ V_20 ] = V_21 ;
V_2 -> V_5 [ V_22 ] = V_23 ;
V_2 -> V_5 [ V_24 ] = V_25 ;
V_2 -> V_5 [ V_26 ] = & V_27 ;
V_2 -> V_5 [ V_28 ] = V_29 ;
V_2 -> V_5 [ V_30 ] = V_31 ;
V_2 -> V_5 [ V_32 ] = & V_33 ;
V_2 -> V_5 [ V_34 ] = V_35 ;
V_2 -> V_5 [ V_36 ] = & V_37 ;
V_2 -> V_5 [ V_38 ] = & V_39 ;
V_2 -> V_5 [ V_40 ] = V_41 ;
#if 0
device->oclass[NVDEV_SUBDEV_VOLT ] = &nv40_volt_oclass;
#endif
V_2 -> V_5 [ V_42 ] = V_43 ;
V_2 -> V_5 [ V_44 ] = V_45 ;
V_2 -> V_5 [ V_46 ] = V_47 ;
V_2 -> V_5 [ V_48 ] = V_49 ;
V_2 -> V_5 [ V_50 ] = V_51 ;
V_2 -> V_5 [ V_52 ] = & V_53 ;
#if 0
device->oclass[NVDEV_ENGINE_COPY1 ] = &nve0_copy1_oclass;
#endif
V_2 -> V_5 [ V_54 ] = & V_55 ;
#if 0
device->oclass[NVDEV_ENGINE_BSP ] = &nve0_bsp_oclass;
device->oclass[NVDEV_ENGINE_VP ] = &nve0_vp_oclass;
device->oclass[NVDEV_ENGINE_PPP ] = &nvc0_ppp_oclass;
#endif
break;
case 0x124 :
V_2 -> V_4 = L_2 ;
V_2 -> V_5 [ V_6 ] = & V_7 ;
V_2 -> V_5 [ V_8 ] = V_9 ;
V_2 -> V_5 [ V_10 ] = V_56 ;
V_2 -> V_5 [ V_12 ] = & V_13 ;
#if 0
device->oclass[NVDEV_SUBDEV_CLOCK ] = &nve0_clock_oclass;
device->oclass[NVDEV_SUBDEV_THERM ] = &gm107_therm_oclass;
#endif
V_2 -> V_5 [ V_18 ] = & V_19 ;
V_2 -> V_5 [ V_20 ] = V_57 ;
V_2 -> V_5 [ V_22 ] = V_23 ;
V_2 -> V_5 [ V_24 ] = V_25 ;
V_2 -> V_5 [ V_26 ] = & V_27 ;
V_2 -> V_5 [ V_28 ] = V_29 ;
V_2 -> V_5 [ V_30 ] = V_31 ;
V_2 -> V_5 [ V_32 ] = & V_33 ;
V_2 -> V_5 [ V_34 ] = V_35 ;
V_2 -> V_5 [ V_36 ] = & V_37 ;
V_2 -> V_5 [ V_38 ] = & V_39 ;
V_2 -> V_5 [ V_40 ] = V_41 ;
#if 0
device->oclass[NVDEV_SUBDEV_VOLT ] = &nv40_volt_oclass;
#endif
V_2 -> V_5 [ V_42 ] = V_43 ;
#if 0
device->oclass[NVDEV_ENGINE_FIFO ] = nv108_fifo_oclass;
device->oclass[NVDEV_ENGINE_SW ] = nvc0_software_oclass;
device->oclass[NVDEV_ENGINE_GR ] = gm107_graph_oclass;
#endif
V_2 -> V_5 [ V_50 ] = V_58 ;
#if 0
device->oclass[NVDEV_ENGINE_COPY0 ] = &gm204_copy0_oclass;
device->oclass[NVDEV_ENGINE_COPY1 ] = &gm204_copy1_oclass;
device->oclass[NVDEV_ENGINE_COPY2 ] = &gm204_copy2_oclass;
device->oclass[NVDEV_ENGINE_BSP ] = &nve0_bsp_oclass;
device->oclass[NVDEV_ENGINE_VP ] = &nve0_vp_oclass;
device->oclass[NVDEV_ENGINE_PPP ] = &nvc0_ppp_oclass;
#endif
break;
default:
F_2 ( V_2 , L_3 ) ;
return - V_59 ;
}
return 0 ;
}
