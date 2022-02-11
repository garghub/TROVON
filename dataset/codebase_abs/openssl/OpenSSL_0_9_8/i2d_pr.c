int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
#ifndef F_2
if ( V_1 -> type == V_3 )
{
return ( F_3 ( V_1 -> V_4 . V_5 , V_2 ) ) ;
}
else
#endif
#ifndef F_4
if ( V_1 -> type == V_6 )
{
return ( F_5 ( V_1 -> V_4 . V_7 , V_2 ) ) ;
}
#endif
#ifndef F_6
if ( V_1 -> type == V_8 )
{
return ( F_7 ( V_1 -> V_4 . V_9 , V_2 ) ) ;
}
#endif
F_8 ( V_10 , V_11 ) ;
return ( - 1 ) ;
}
