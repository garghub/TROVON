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
T_6 * V_8 ;
T_3 * V_9 ;
F_6 ( V_6 -> V_10 , V_11 , L_1 ) ;
F_6 ( V_6 -> V_10 , V_12 , L_1 ) ;
F_6 ( V_6 -> V_10 , V_13 , L_1 ) ;
F_6 ( V_6 -> V_10 , V_14 , L_2 ) ;
V_8 = F_7 ( V_7 , V_15 , V_5 , 0 , 0 , V_16 ) ;
F_8 ( V_6 , V_8 , & V_17 ) ;
if ( V_6 -> V_18 -> V_19 == V_20 ) {
F_9 ( V_21 , V_5 , V_6 , V_7 ) ;
}
else if ( V_6 -> V_18 -> V_19 == V_22 ) {
F_9 ( V_23 , V_5 , V_6 , V_7 ) ;
}
else
if ( F_10 ( V_5 , 0 ) == 0xff03 ) {
F_9 ( V_24 , V_5 , V_6 , V_7 ) ;
}
else if ( F_10 ( V_5 , 6 ) == 0xff03 ) {
V_9 = F_11 ( V_5 , 6 ) ;
F_9 ( V_24 , V_9 , V_6 , V_7 ) ;
}
else if ( F_10 ( V_5 , 1 ) == 0xff03 ) {
V_9 = F_11 ( V_5 , 1 ) ;
F_9 ( V_24 , V_9 , V_6 , V_7 ) ;
}
else if ( F_12 ( V_5 , 0 , V_4 , 10 ) == 0 ) {
V_9 = F_11 ( V_5 , 10 ) ;
F_9 ( V_21 , V_9 , V_6 , V_7 ) ;
}
else {
switch ( F_13 ( V_5 , 0 ) & 0xF0 ) {
case 0x40 :
F_9 ( V_21 , V_5 , V_6 , V_7 ) ;
break;
case 0x60 :
F_9 ( V_23 , V_5 , V_6 , V_7 ) ;
break;
default:
F_9 ( V_25 , V_5 , V_6 , V_7 ) ;
break;
}
}
}
void
F_14 ( void )
{
static T_7 * V_26 [] = {
& V_27 ,
} ;
static T_8 V_28 [] = {
{ & V_17 , { L_3 , V_29 , V_30 , L_4 , V_31 } } ,
} ;
T_9 * V_32 ;
V_15 = F_15 ( L_2 , L_5 , L_6 ) ;
F_16 ( V_26 , F_17 ( V_26 ) ) ;
V_32 = F_18 ( V_15 ) ;
F_19 ( V_32 , V_28 , F_17 ( V_28 ) ) ;
}
void
F_20 ( void )
{
T_10 V_33 ;
V_21 = F_21 ( L_7 ) ;
V_23 = F_21 ( L_8 ) ;
V_25 = F_21 ( L_9 ) ;
V_24 = F_21 ( L_10 ) ;
V_33 = F_22 ( F_5 , V_15 ) ;
F_23 ( L_11 , V_34 , V_33 ) ;
F_23 ( L_11 , V_20 , V_33 ) ;
F_23 ( L_11 , V_22 , V_33 ) ;
}
