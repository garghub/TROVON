int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
switch ( V_1 -> type )
{
#ifndef F_2
case V_3 :
return ( F_3 ( V_1 -> V_4 . V_5 , V_2 ) ) ;
#endif
#ifndef F_4
case V_6 :
return ( F_5 ( V_1 -> V_4 . V_7 , V_2 ) ) ;
#endif
#ifndef F_6
case V_8 :
return ( F_7 ( V_1 -> V_4 . V_9 , V_2 ) ) ;
#endif
default:
F_8 ( V_10 , V_11 ) ;
return ( - 1 ) ;
}
}
