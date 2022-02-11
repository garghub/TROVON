void
F_1 ( const T_1 * V_1 , int V_2 , T_2 * V_3 )
{
if ( F_2 ( 0 , V_2 , 2 ) && V_1 [ 0 ] == 0xff && V_1 [ 1 ] == 0x03 ) {
F_3 ( V_1 , 0 , V_2 , V_3 ) ;
}
else if ( F_2 ( 0 , V_2 , 8 ) && V_1 [ 6 ] == 0xff && V_1 [ 7 ] == 0x03 ) {
F_3 ( V_1 , 6 , V_2 , V_3 ) ;
}
else if ( F_2 ( 0 , V_2 , 3 ) && V_1 [ 1 ] == 0xff && V_1 [ 2 ] == 0x03 ) {
F_3 ( V_1 , 1 , V_2 , V_3 ) ;
}
else if ( F_2 ( 0 , V_2 , 10 ) && memcmp ( V_1 , V_4 , 10 ) == 0 ) {
F_4 ( V_1 , 10 , V_2 , V_3 ) ;
}
else {
if ( F_2 ( 0 , V_2 , 1 ) ) {
switch ( V_1 [ 0 ] & 0xF0 ) {
case 0x40 :
F_4 ( V_1 , 0 , V_2 , V_3 ) ;
break;
#if 0
case 0x60:
capture_ipv6(pd, 0, len, ld);
break;
#endif
}
}
}
}
static void
F_5 ( T_3 * V_5 , T_4 * V_6 , T_5 * V_7 )
{
T_5 * V_8 ;
T_6 * V_9 ;
T_3 * V_10 ;
F_6 ( V_6 -> V_11 , V_12 , L_1 ) ;
F_6 ( V_6 -> V_11 , V_13 , L_1 ) ;
F_6 ( V_6 -> V_11 , V_14 , L_1 ) ;
F_6 ( V_6 -> V_11 , V_15 , L_2 ) ;
if ( V_7 ) {
V_9 = F_7 ( V_7 , V_16 , V_5 , 0 , 0 , V_17 ) ;
V_8 = F_8 ( V_9 , V_18 ) ;
F_9 ( V_8 , V_5 , 0 , 0 , L_3 ) ;
}
if ( V_6 -> V_19 -> V_20 == V_21 ) {
F_10 ( V_22 , V_5 , V_6 , V_7 ) ;
}
else if ( V_6 -> V_19 -> V_20 == V_23 ) {
F_10 ( V_24 , V_5 , V_6 , V_7 ) ;
}
else
if ( F_11 ( V_5 , 0 ) == 0xff03 ) {
F_10 ( V_25 , V_5 , V_6 , V_7 ) ;
}
else if ( F_11 ( V_5 , 6 ) == 0xff03 ) {
V_10 = F_12 ( V_5 , 6 ) ;
F_10 ( V_25 , V_10 , V_6 , V_7 ) ;
}
else if ( F_11 ( V_5 , 1 ) == 0xff03 ) {
V_10 = F_12 ( V_5 , 1 ) ;
F_10 ( V_25 , V_10 , V_6 , V_7 ) ;
}
else if ( F_13 ( V_5 , 0 , V_4 , 10 ) == 0 ) {
V_10 = F_12 ( V_5 , 10 ) ;
F_10 ( V_22 , V_10 , V_6 , V_7 ) ;
}
else {
switch ( F_14 ( V_5 , 0 ) & 0xF0 ) {
case 0x40 :
F_10 ( V_22 , V_5 , V_6 , V_7 ) ;
break;
case 0x60 :
F_10 ( V_24 , V_5 , V_6 , V_7 ) ;
break;
default:
F_10 ( V_26 , V_5 , V_6 , V_7 ) ;
break;
}
}
}
void
F_15 ( void )
{
static T_7 * V_27 [] = {
& V_18 ,
} ;
V_16 = F_16 ( L_2 , L_4 , L_5 ) ;
F_17 ( V_27 , F_18 ( V_27 ) ) ;
}
void
F_19 ( void )
{
T_8 V_28 ;
V_22 = F_20 ( L_6 ) ;
V_24 = F_20 ( L_7 ) ;
V_26 = F_20 ( L_8 ) ;
V_25 = F_20 ( L_9 ) ;
V_28 = F_21 ( F_5 , V_16 ) ;
F_22 ( L_10 , V_29 , V_28 ) ;
F_22 ( L_10 , V_21 , V_28 ) ;
F_22 ( L_10 , V_23 , V_28 ) ;
}
