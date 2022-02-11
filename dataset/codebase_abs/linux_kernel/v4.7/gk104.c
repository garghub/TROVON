static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = NULL ;
T_1 V_9 , type ;
int V_10 ;
for ( V_10 = 0 ; V_10 < 64 ; V_10 ++ ) {
if ( ! V_8 ) {
if ( ! ( V_8 = F_2 ( V_2 ) ) )
return - V_11 ;
type = ~ 0 ;
}
V_9 = F_3 ( V_6 , 0x022700 + ( V_10 * 0x04 ) ) ;
F_4 ( V_4 , L_1 , V_10 , V_9 ) ;
switch ( V_9 & 0x00000003 ) {
case 0x00000000 :
continue;
case 0x00000001 :
V_8 -> V_12 = ( V_9 & 0x00fff000 ) ;
V_8 -> V_13 = ( V_9 & 0x000000f8 ) >> 3 ;
break;
case 0x00000002 :
if ( V_9 & 0x00000020 )
V_8 -> V_14 = ( V_9 & 0x3c000000 ) >> 26 ;
if ( V_9 & 0x00000010 )
V_8 -> V_15 = ( V_9 & 0x01e00000 ) >> 21 ;
if ( V_9 & 0x00000008 )
V_8 -> V_16 = ( V_9 & 0x000f8000 ) >> 15 ;
if ( V_9 & 0x00000004 )
V_8 -> V_17 = ( V_9 & 0x00003e00 ) >> 9 ;
break;
case 0x00000003 :
type = ( V_9 & 0x7ffffffc ) >> 2 ;
break;
}
if ( V_9 & 0x80000000 )
continue;
switch ( type ) {
case 0x00000000 : V_8 -> V_18 = V_19 ; break;
case 0x00000001 : V_8 -> V_18 = V_20 ; break;
case 0x00000002 : V_8 -> V_18 = V_21 ; break;
case 0x00000003 : V_8 -> V_18 = V_22 ; break;
case 0x00000008 : V_8 -> V_18 = V_23 ; break;
case 0x00000009 : V_8 -> V_18 = V_24 ; break;
case 0x0000000a : V_8 -> V_18 = V_25 ; break;
case 0x0000000b : V_8 -> V_18 = V_26 ; break;
case 0x0000000c : V_8 -> V_18 = V_27 ; break;
case 0x0000000d : V_8 -> V_18 = V_28 ; break;
case 0x0000000e : V_8 -> V_18 = V_29 ; break;
case 0x0000000f : V_8 -> V_18 = V_30 ; break;
case 0x00000010 : V_8 -> V_18 = V_31 ; break;
break;
default:
break;
}
F_5 ( V_4 , L_2
L_3 , type ,
V_8 -> V_18 == V_32 ? NULL :
V_33 [ V_8 -> V_18 ] ,
V_8 -> V_12 , V_8 -> V_13 , V_8 -> V_14 , V_8 -> V_15 ,
V_8 -> V_16 , V_8 -> V_17 ) ;
V_8 = NULL ;
}
return 0 ;
}
int
F_6 ( struct V_5 * V_6 , int V_18 , struct V_1 * * V_34 )
{
return F_7 ( & V_35 , V_6 , V_18 , V_34 ) ;
}
