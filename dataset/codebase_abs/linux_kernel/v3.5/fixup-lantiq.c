int F_1 ( struct V_1 * V_2 )
{
if ( V_3 )
return V_3 ( V_2 ) ;
if ( V_4 )
return V_4 ( V_2 ) ;
return 0 ;
}
int T_1 F_2 ( const struct V_1 * V_2 , T_2 V_5 , T_2 V_6 )
{
struct V_7 V_8 ;
int V_9 ;
if ( F_3 ( V_2 , & V_8 ) ) {
F_4 ( & V_2 -> V_2 , L_1 ,
V_5 , V_6 ) ;
return 0 ;
}
V_9 = F_5 ( V_8 . V_10 , V_8 . V_11 ,
V_8 . V_12 ) ;
F_6 ( & V_2 -> V_2 , L_2 , V_5 , V_6 , V_9 ) ;
return V_9 ;
}
