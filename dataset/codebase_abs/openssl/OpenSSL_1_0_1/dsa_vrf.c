int F_1 ( const unsigned char * V_1 , int V_2 , T_1 * V_3 ,
T_2 * V_4 )
{
#ifdef F_2
if ( F_3 () && ! ( V_4 -> V_5 -> V_6 & V_7 )
&& ! ( V_4 -> V_6 & V_8 ) )
{
F_4 ( V_9 , V_10 ) ;
return - 1 ;
}
#endif
return V_4 -> V_5 -> V_11 ( V_1 , V_2 , V_3 , V_4 ) ;
}
