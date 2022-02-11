static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = NULL ;
T_1 V_9 , type , V_10 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < 64 ; V_11 ++ ) {
if ( ! V_8 ) {
if ( ! ( V_8 = F_2 ( V_2 ) ) )
return - V_12 ;
type = ~ 0 ;
V_10 = 0 ;
}
V_9 = F_3 ( V_6 , 0x022700 + ( V_11 * 0x04 ) ) ;
F_4 ( V_4 , L_1 , V_11 , V_9 ) ;
switch ( V_9 & 0x00000003 ) {
case 0x00000000 :
continue;
case 0x00000001 :
V_10 = ( V_9 & 0x3c000000 ) >> 26 ;
V_8 -> V_13 = ( V_9 & 0x00fff000 ) ;
V_8 -> V_14 = ( V_9 & 0x000000f8 ) >> 3 ;
break;
case 0x00000002 :
if ( V_9 & 0x00000020 )
V_8 -> V_15 = ( V_9 & 0x3c000000 ) >> 26 ;
if ( V_9 & 0x00000010 )
V_8 -> V_16 = ( V_9 & 0x01e00000 ) >> 21 ;
if ( V_9 & 0x00000008 )
V_8 -> V_17 = ( V_9 & 0x000f8000 ) >> 15 ;
if ( V_9 & 0x00000004 )
V_8 -> V_18 = ( V_9 & 0x00003e00 ) >> 9 ;
break;
case 0x00000003 :
type = ( V_9 & 0x7ffffffc ) >> 2 ;
break;
}
if ( V_9 & 0x80000000 )
continue;
#define F_5 ( T_2 ) if (inst == 0) info->index = NVKM_ENGINE_##A
#define F_6 ( T_2 ) if (inst + NVKM_ENGINE_##A##0 < NVKM_ENGINE_##A##_LAST + 1) \
info->index = NVKM_ENGINE_##A##0 + inst
switch ( type ) {
case 0x00000000 : F_5 ( V_19 ) ; break;
case 0x00000001 : F_5 ( V_20 ) ; break;
case 0x00000002 : F_5 ( V_21 ) ; break;
case 0x00000003 : F_5 ( V_22 ) ; break;
case 0x00000008 : F_5 ( V_23 ) ; break;
case 0x00000009 : F_5 ( V_24 ) ; break;
case 0x0000000a : F_5 ( V_25 ) ; break;
case 0x0000000b : F_5 ( V_26 ) ; break;
case 0x0000000c : F_5 ( V_27 ) ; break;
case 0x0000000d : F_5 ( V_28 ) ; break;
case 0x0000000e : F_6 ( V_29 ) ; break;
case 0x0000000f : F_5 ( V_30 ) ; break;
case 0x00000010 : F_5 ( V_31 ) ; break;
case 0x00000013 : F_6 ( V_32 ) ; break;
break;
default:
break;
}
F_7 ( V_4 , L_2
L_3
L_4 , type , V_10 ,
V_8 -> V_33 == V_34 ? NULL :
V_35 [ V_8 -> V_33 ] ,
V_8 -> V_13 , V_8 -> V_14 , V_8 -> V_15 , V_8 -> V_16 ,
V_8 -> V_17 , V_8 -> V_18 ) ;
V_8 = NULL ;
}
return 0 ;
}
int
F_8 ( struct V_5 * V_6 , int V_33 , struct V_1 * * V_36 )
{
return F_9 ( & V_37 , V_6 , V_33 , V_36 ) ;
}
