void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
enum V_5 V_6 , T_1 V_7 )
{
if ( V_3 == 0xffe ) {
F_2 ( 50 ) ;
} else if ( V_3 == 0xfe ) {
F_3 ( 100 ) ;
} else {
F_4 ( V_2 , V_6 , V_7 , V_8 , V_4 ) ;
F_3 ( 1 ) ;
}
}
void F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_9 = 0x1000 ;
T_1 V_10 = ( T_1 ) ( V_9 & 0xE000 ) ;
F_1 ( V_2 , V_3 , V_4 , V_11 ,
V_3 | V_10 ) ;
F_6 (
V_2 , V_12 ,
L_1 ,
V_3 , V_4 ) ;
}
void F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_9 = 0x1001 ;
T_1 V_10 = ( T_1 ) ( V_9 & 0xE000 ) ;
F_1 ( V_2 , V_3 , V_4 , V_13 ,
V_3 | V_10 ) ;
F_6 (
V_2 , V_12 ,
L_2 ,
V_3 , V_4 ) ;
}
void F_8 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
F_9 ( V_2 , V_3 , V_4 ) ;
F_6 (
V_2 , V_12 ,
L_3 ,
V_3 , V_4 ) ;
}
void F_10 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
struct V_14 * V_15 = & V_2 -> V_16 ;
T_2 V_17 = ( T_2 ) ( ( V_4 & 0xFF000000 ) >> 24 ) ;
T_2 V_18 = ( T_2 ) ( ( V_4 & 0x00ff0000 ) >> 16 ) ;
T_2 V_19 = ( T_2 ) ( ( V_4 & 0x00000f00 ) >> 8 ) ;
static bool V_20 ;
if ( V_3 != 0x81c )
return;
if ( V_18 > 0x3c ) {
if ( ( V_17 == V_15 -> V_17 ) && ! V_20 ) {
V_20 = true ;
V_15 -> V_21 [ V_19 ] = V_18 - 2 ;
F_6 (
V_2 , V_22 ,
L_4 ,
V_19 ,
V_15 -> V_21 [ V_19 ] ) ;
}
} else {
V_20 = false ;
}
V_15 -> V_17 = V_17 ;
}
void F_11 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_23 ,
T_1 V_4 )
{
F_10 ( V_2 , V_3 , V_4 ) ;
F_12 ( V_2 , V_3 , V_23 , V_4 ) ;
F_3 ( 1 ) ;
F_6 ( V_2 , V_12 , L_5 ,
V_24 , V_3 , V_4 ) ;
}
void F_13 ( struct V_1 * V_2 , T_1 V_25 ,
T_1 V_26 , T_1 V_27 , T_1 V_3 ,
T_1 V_23 , T_1 V_4 )
{
if ( V_3 == 0xfe || V_3 == 0xffe ) {
F_2 ( 50 ) ;
} else {
F_14 ( V_2 -> V_28 , V_25 , V_26 , V_27 ,
V_3 , V_23 , V_4 ) ;
}
F_6 ( V_2 , V_12 , L_6 ,
V_24 , V_3 , V_23 , V_4 ) ;
}
void F_15 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_23 ,
T_1 V_4 )
{
if ( V_3 == 0xfe )
F_2 ( 50 ) ;
else if ( V_3 == 0xfd )
F_16 ( 5 ) ;
else if ( V_3 == 0xfc )
F_16 ( 1 ) ;
else if ( V_3 == 0xfb )
F_3 ( 50 ) ;
else if ( V_3 == 0xfa )
F_3 ( 5 ) ;
else if ( V_3 == 0xf9 )
F_3 ( 1 ) ;
else
F_12 ( V_2 , V_3 , V_23 , V_4 ) ;
F_3 ( 1 ) ;
F_6 ( V_2 , V_12 , L_7 ,
V_24 , V_3 , V_4 ) ;
}
void F_17 ( struct V_1 * V_2 , T_2 * V_29 ,
T_2 * V_25 , T_2 * V_30 , T_2 * V_31 ,
T_2 * V_26 , T_2 * V_32 , T_2 * V_33 )
{
F_18 ( V_2 , V_29 , V_25 , V_30 , V_31 ,
V_26 , V_32 , V_33 ) ;
}
