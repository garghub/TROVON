BOOL T_1 F_1 ( T_2 V_1 , T_3 V_2 , T_4 V_3 )
{
switch ( V_2 ) {
case V_4 :
F_2 () ;
# if F_3 ( V_5 )
{
T_5 * V_6 = ( T_5 * ) V_1 ;
T_6 * V_7 ;
if ( V_6 -> V_8 == V_9 ) {
V_7 = ( T_6 * ) ( ( char * ) V_6
+ V_6 -> V_10 ) ;
if ( V_7 -> V_11 == V_12 &&
V_1 !=
( T_2 ) ( V_7 -> V_13 . V_14 ) )
V_15 = 1 ;
}
}
# endif
break;
case V_16 :
break;
case V_17 :
F_4 () ;
break;
case V_18 :
break;
}
return ( TRUE ) ;
}
