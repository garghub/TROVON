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
T_3 * V_8 ;
F_6 ( V_6 -> V_9 , V_10 , L_1 ) ;
F_6 ( V_6 -> V_9 , V_11 , L_1 ) ;
F_6 ( V_6 -> V_9 , V_12 , L_1 ) ;
F_6 ( V_6 -> V_9 , V_13 , L_2 ) ;
F_7 ( V_7 , V_14 , V_5 , 0 , F_8 ( V_5 ) , V_15 ) ;
if ( F_9 ( V_5 , 0 ) == 0xff03 ) {
F_10 ( V_16 , V_5 , V_6 , V_7 ) ;
}
else if ( F_9 ( V_5 , 6 ) == 0xff03 ) {
V_8 = F_11 ( V_5 , 6 ) ;
F_10 ( V_16 , V_8 , V_6 , V_7 ) ;
}
else if ( F_9 ( V_5 , 1 ) == 0xff03 ) {
V_8 = F_11 ( V_5 , 1 ) ;
F_10 ( V_16 , V_8 , V_6 , V_7 ) ;
}
else if ( F_12 ( V_5 , 0 , V_4 , 10 ) == 0 ) {
V_8 = F_11 ( V_5 , 10 ) ;
F_10 ( V_17 , V_8 , V_6 , V_7 ) ;
}
else {
switch ( F_13 ( V_5 , 0 ) & 0xF0 ) {
case 0x40 :
F_10 ( V_17 , V_5 , V_6 , V_7 ) ;
break;
case 0x60 :
F_10 ( V_18 , V_5 , V_6 , V_7 ) ;
break;
default:
F_10 ( V_19 , V_5 , V_6 , V_7 ) ;
break;
}
}
}
void
F_14 ( void )
{
static T_6 * V_20 [] = {
& V_21 ,
} ;
V_14 = F_15 ( L_2 , L_3 , L_4 ) ;
F_16 ( V_20 , F_17 ( V_20 ) ) ;
}
void
F_18 ( void )
{
T_7 V_22 ;
V_17 = F_19 ( L_5 ) ;
V_18 = F_19 ( L_6 ) ;
V_19 = F_19 ( L_7 ) ;
V_16 = F_19 ( L_8 ) ;
V_22 = F_20 ( F_5 , V_14 ) ;
F_21 ( L_9 , V_23 , V_22 ) ;
}
