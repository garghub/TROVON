static T_1
F_1 ( const T_2 * V_1 , int T_3 V_2 , int V_3 , T_4 * V_4 , const union V_5 * T_5 V_2 )
{
if ( F_2 ( 0 , V_3 , 2 ) && V_1 [ 0 ] == 0xff && V_1 [ 1 ] == 0x03 ) {
return F_3 ( V_6 , V_1 , 0 , V_3 , V_4 , T_5 ) ;
}
else if ( F_2 ( 0 , V_3 , 8 ) && V_1 [ 6 ] == 0xff && V_1 [ 7 ] == 0x03 ) {
return F_3 ( V_6 , V_1 , 6 , V_3 , V_4 , T_5 ) ;
}
else if ( F_2 ( 0 , V_3 , 3 ) && V_1 [ 1 ] == 0xff && V_1 [ 2 ] == 0x03 ) {
return F_3 ( V_6 , V_1 , 1 , V_3 , V_4 , T_5 ) ;
}
else if ( F_2 ( 0 , V_3 , 10 ) && memcmp ( V_1 , V_7 , 10 ) == 0 ) {
return F_3 ( V_8 , V_1 , 10 , V_3 , V_4 , T_5 ) ;
}
else {
if ( F_2 ( 0 , V_3 , 1 ) ) {
switch ( V_1 [ 0 ] & 0xF0 ) {
case 0x40 :
return F_3 ( V_8 , V_1 , 0 , V_3 , V_4 , T_5 ) ;
#if 0
case 0x60:
return call_capture_dissector(ipv6_cap_handle, pd, 0, len, cpinfo, pseudo_header);
#endif
}
}
}
return FALSE ;
}
static int
F_4 ( T_6 * V_9 , T_7 * V_10 , T_8 * V_11 , void * T_9 V_2 )
{
T_6 * V_12 ;
F_5 ( V_10 -> V_13 , V_14 , L_1 ) ;
F_5 ( V_10 -> V_13 , V_15 , L_1 ) ;
F_5 ( V_10 -> V_13 , V_16 , L_1 ) ;
F_5 ( V_10 -> V_13 , V_17 , L_2 ) ;
F_6 ( V_11 , V_18 , V_9 , 0 , F_7 ( V_9 ) , V_19 ) ;
if ( F_8 ( V_9 , 0 ) == 0xff03 ) {
F_9 ( V_20 , V_9 , V_10 , V_11 ) ;
}
else if ( F_8 ( V_9 , 6 ) == 0xff03 ) {
V_12 = F_10 ( V_9 , 6 ) ;
F_9 ( V_20 , V_12 , V_10 , V_11 ) ;
}
else if ( F_8 ( V_9 , 1 ) == 0xff03 ) {
V_12 = F_10 ( V_9 , 1 ) ;
F_9 ( V_20 , V_12 , V_10 , V_11 ) ;
}
else if ( F_11 ( V_9 , 0 , V_7 , 10 ) == 0 ) {
V_12 = F_10 ( V_9 , 10 ) ;
F_9 ( V_21 , V_12 , V_10 , V_11 ) ;
}
else {
switch ( F_12 ( V_9 , 0 ) & 0xF0 ) {
case 0x40 :
F_9 ( V_21 , V_9 , V_10 , V_11 ) ;
break;
case 0x60 :
F_9 ( V_22 , V_9 , V_10 , V_11 ) ;
break;
default:
F_13 ( V_9 , V_10 , V_11 ) ;
break;
}
}
return F_7 ( V_9 ) ;
}
void
F_14 ( void )
{
static T_10 * V_23 [] = {
& V_24 ,
} ;
V_18 = F_15 ( L_2 , L_3 , L_4 ) ;
F_16 ( V_23 , F_17 ( V_23 ) ) ;
V_25 = F_18 ( L_5 , F_4 , V_18 ) ;
}
void
F_19 ( void )
{
T_11 V_26 ;
V_21 = F_20 ( L_6 , V_18 ) ;
V_22 = F_20 ( L_7 , V_18 ) ;
V_20 = F_20 ( L_8 , V_18 ) ;
F_21 ( L_9 , V_27 , V_25 ) ;
V_26 = F_22 ( F_1 , V_18 ) ;
F_23 ( L_9 , V_27 , V_26 ) ;
V_8 = F_24 ( L_6 ) ;
V_28 = F_24 ( L_7 ) ;
V_6 = F_24 ( L_8 ) ;
}
