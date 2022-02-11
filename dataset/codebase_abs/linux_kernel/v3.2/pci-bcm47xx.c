int T_1 F_1 ( const struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
return 0 ;
}
int F_2 ( struct V_1 * V_2 )
{
#ifdef F_3
int V_5 ;
T_2 V_3 , V_4 ;
if ( V_6 != V_7 )
return 0 ;
V_5 = F_4 ( V_2 ) ;
if ( V_5 < 0 ) {
F_5 ( V_8 L_1 ,
F_6 ( V_2 ) ) ;
return V_5 ;
}
F_7 ( V_2 , V_9 , & V_4 ) ;
V_3 = F_8 ( V_2 -> V_10 ) ;
V_5 = F_9 ( V_2 , V_3 , V_4 ) ;
if ( V_5 < 2 ) {
F_5 ( V_8 L_2 ,
F_6 ( V_2 ) ) ;
return V_5 ;
}
V_2 -> V_11 = V_5 ;
#endif
return 0 ;
}
