static T_1
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = F_2 ( V_2 , V_3 ) ;
if ( ! ( V_4 & 0x00000100 ) )
return F_3 ( V_2 , 0x00e800 ) ;
return F_3 ( V_2 , 0x00e820 ) ;
}
static T_1
F_3 ( struct V_1 * V_2 , T_1 V_5 )
{
T_1 V_6 = F_2 ( V_2 , V_5 + 0 ) ;
T_1 V_7 = F_2 ( V_2 , V_5 + 4 ) ;
T_1 V_8 = ( V_7 & 0x003f0000 ) >> 16 ;
T_1 V_9 = ( V_7 & 0x0000ff00 ) >> 8 ;
T_1 V_10 = ( V_7 & 0x000000ff ) >> 0 ;
T_1 V_11 , V_12 ;
if ( ! ( V_6 & 0x00000001 ) )
return 0 ;
switch ( V_5 & 0xfff000 ) {
case 0x00e000 :
V_11 = 27000 ;
V_8 = 1 ;
break;
case 0x137000 :
V_12 = ( V_5 - 0x137000 ) / 0x20 ;
V_11 = F_4 ( V_2 , V_12 , 0x137120 , 0x137140 ) ;
break;
case 0x132000 :
switch ( V_5 ) {
case 0x132000 :
V_11 = F_3 ( V_2 , 0x132020 ) ;
break;
case 0x132020 :
V_11 = F_4 ( V_2 , 0 , 0x137320 , 0x137330 ) ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
return V_11 * V_9 / V_10 / V_8 ;
}
static T_1
F_4 ( struct V_1 * V_2 , int V_12 , T_1 V_3 , T_1 V_13 )
{
T_1 V_4 = F_2 ( V_2 , V_3 + ( V_12 * 4 ) ) ;
T_1 V_14 = F_2 ( V_2 , V_13 + ( V_12 * 4 ) ) ;
switch ( V_4 & 0x00000003 ) {
case 0 :
if ( ( V_4 & 0x00030000 ) != 0x00030000 )
return 27000 ;
return 108000 ;
case 2 :
return 100000 ;
case 3 :
if ( V_14 & 0x80000000 ) {
T_1 V_11 = F_1 ( V_2 , V_3 + ( V_12 * 4 ) ) ;
T_1 V_15 = ( V_14 & 0x0000003f ) + 2 ;
return ( V_11 * 2 ) / V_15 ;
}
return F_1 ( V_2 , V_3 + ( V_12 * 4 ) ) ;
default:
return 0 ;
}
}
static T_1
F_5 ( struct V_1 * V_2 )
{
T_1 V_16 = F_2 ( V_2 , 0x1373f0 ) ;
if ( V_16 & 0x00000001 )
return F_4 ( V_2 , 0 , 0x137300 , 0x137310 ) ;
return F_3 ( V_2 , 0x132000 ) ;
}
static T_1
F_6 ( struct V_1 * V_2 , int V_17 )
{
T_1 V_14 = F_2 ( V_2 , 0x137250 + ( V_17 * 4 ) ) ;
T_1 V_16 = F_2 ( V_2 , 0x137100 ) ;
T_1 V_11 , V_15 ;
if ( V_16 & ( 1 << V_17 ) ) {
if ( V_17 < 7 )
V_11 = F_3 ( V_2 , 0x137000 + ( V_17 * 0x20 ) ) ;
else
V_11 = F_3 ( V_2 , 0x1370e0 ) ;
V_15 = ( ( V_14 & 0x00003f00 ) >> 8 ) + 2 ;
} else {
V_11 = F_4 ( V_2 , V_17 , 0x137160 , 0x1371d0 ) ;
V_15 = ( ( V_14 & 0x0000003f ) >> 0 ) + 2 ;
}
if ( V_14 & 0x80000000 )
return ( V_11 * 2 ) / V_15 ;
return V_11 ;
}
int
F_7 ( struct V_1 * V_2 , struct V_18 * V_19 )
{
V_19 -> V_20 = F_6 ( V_2 , 0x00 ) ;
V_19 -> V_21 = V_19 -> V_20 / 2 ;
V_19 -> V_22 = F_5 ( V_2 ) ;
V_19 -> V_23 = F_6 ( V_2 , 0x01 ) ;
V_19 -> V_24 = F_6 ( V_2 , 0x02 ) ;
V_19 -> V_25 = F_6 ( V_2 , 0x07 ) ;
V_19 -> V_26 = F_6 ( V_2 , 0x08 ) ;
V_19 -> V_27 = F_6 ( V_2 , 0x09 ) ;
V_19 -> V_28 = F_6 ( V_2 , 0x0c ) ;
V_19 -> V_29 = F_6 ( V_2 , 0x0e ) ;
return 0 ;
}
