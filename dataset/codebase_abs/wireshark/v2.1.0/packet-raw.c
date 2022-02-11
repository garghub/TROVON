static T_1
F_1 ( const T_2 * V_1 , int T_3 V_2 , int V_3 , T_4 * V_4 , const union V_5 * T_5 V_2 )
{
if ( F_2 ( 0 , V_3 , 2 ) && V_1 [ 0 ] == 0xff && V_1 [ 1 ] == 0x03 ) {
return F_3 ( V_1 , 0 , V_3 , V_4 , T_5 ) ;
}
else if ( F_2 ( 0 , V_3 , 8 ) && V_1 [ 6 ] == 0xff && V_1 [ 7 ] == 0x03 ) {
return F_3 ( V_1 , 6 , V_3 , V_4 , T_5 ) ;
}
else if ( F_2 ( 0 , V_3 , 3 ) && V_1 [ 1 ] == 0xff && V_1 [ 2 ] == 0x03 ) {
return F_3 ( V_1 , 1 , V_3 , V_4 , T_5 ) ;
}
else if ( F_2 ( 0 , V_3 , 10 ) && memcmp ( V_1 , V_6 , 10 ) == 0 ) {
return F_4 ( V_1 , 10 , V_3 , V_4 , T_5 ) ;
}
else {
if ( F_2 ( 0 , V_3 , 1 ) ) {
switch ( V_1 [ 0 ] & 0xF0 ) {
case 0x40 :
return F_4 ( V_1 , 0 , V_3 , V_4 , T_5 ) ;
#if 0
case 0x60:
return capture_ipv6(pd, 0, len, cpinfo, pseudo_header);
#endif
}
}
}
return FALSE ;
}
static int
F_5 ( T_6 * V_7 , T_7 * V_8 , T_8 * V_9 , void * T_9 V_2 )
{
T_6 * V_10 ;
F_6 ( V_8 -> V_11 , V_12 , L_1 ) ;
F_6 ( V_8 -> V_11 , V_13 , L_1 ) ;
F_6 ( V_8 -> V_11 , V_14 , L_1 ) ;
F_6 ( V_8 -> V_11 , V_15 , L_2 ) ;
F_7 ( V_9 , V_16 , V_7 , 0 , F_8 ( V_7 ) , V_17 ) ;
if ( F_9 ( V_7 , 0 ) == 0xff03 ) {
F_10 ( V_18 , V_7 , V_8 , V_9 ) ;
}
else if ( F_9 ( V_7 , 6 ) == 0xff03 ) {
V_10 = F_11 ( V_7 , 6 ) ;
F_10 ( V_18 , V_10 , V_8 , V_9 ) ;
}
else if ( F_9 ( V_7 , 1 ) == 0xff03 ) {
V_10 = F_11 ( V_7 , 1 ) ;
F_10 ( V_18 , V_10 , V_8 , V_9 ) ;
}
else if ( F_12 ( V_7 , 0 , V_6 , 10 ) == 0 ) {
V_10 = F_11 ( V_7 , 10 ) ;
F_10 ( V_19 , V_10 , V_8 , V_9 ) ;
}
else {
switch ( F_13 ( V_7 , 0 ) & 0xF0 ) {
case 0x40 :
F_10 ( V_19 , V_7 , V_8 , V_9 ) ;
break;
case 0x60 :
F_10 ( V_20 , V_7 , V_8 , V_9 ) ;
break;
default:
F_14 ( V_7 , V_8 , V_9 ) ;
break;
}
}
return F_8 ( V_7 ) ;
}
void
F_15 ( void )
{
static T_10 * V_21 [] = {
& V_22 ,
} ;
V_16 = F_16 ( L_2 , L_3 , L_4 ) ;
F_17 ( V_21 , F_18 ( V_21 ) ) ;
V_23 = F_19 ( L_5 , F_5 , V_16 ) ;
}
void
F_20 ( void )
{
V_19 = F_21 ( L_6 , V_16 ) ;
V_20 = F_21 ( L_7 , V_16 ) ;
V_18 = F_21 ( L_8 , V_16 ) ;
F_22 ( L_9 , V_24 , V_23 ) ;
F_23 ( L_9 , V_24 , F_1 , V_16 ) ;
}
