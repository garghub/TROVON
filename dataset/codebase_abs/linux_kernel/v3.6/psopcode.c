const struct V_1 * F_1 ( T_1 V_2 )
{
F_2 ( V_3 ) ;
if ( ! ( V_2 & 0xFF00 ) ) {
return ( & V_4
[ V_5 [ ( V_6 ) V_2 ] ] ) ;
}
if ( ( ( V_2 & 0xFF00 ) == V_7 ) &&
( ( ( V_6 ) V_2 ) <= V_8 ) ) {
return ( & V_4
[ V_9 [ ( V_6 ) V_2 ] ] ) ;
}
F_3 ( ( V_10 ,
L_1 , V_2 ) ) ;
return ( & V_4 [ V_11 ] ) ;
}
char * F_4 ( T_1 V_2 )
{
#if F_5 ( V_12 ) || F_5 ( V_13 )
const struct V_1 * V_14 ;
V_14 = F_1 ( V_2 ) ;
return ( V_14 -> V_15 ) ;
#else
return ( L_2 ) ;
#endif
}
V_6 F_6 ( T_2 V_16 )
{
if ( V_16 <= V_17 ) {
return ( V_18 [ V_16 ] ) ;
}
return ( 0 ) ;
}
