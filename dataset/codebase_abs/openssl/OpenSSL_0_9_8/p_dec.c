int F_1 ( unsigned char * V_1 , const unsigned char * V_2 , int V_3 ,
T_1 * V_4 )
{
int V_5 = - 1 ;
#ifndef F_2
if ( V_4 -> type != V_6 )
{
#endif
F_3 ( V_7 , V_8 ) ;
#ifndef F_2
goto V_9;
}
V_5 = F_4 ( V_3 , V_2 , V_1 , V_4 -> V_10 . V_11 , V_12 ) ;
V_9:
#endif
return ( V_5 ) ;
}
