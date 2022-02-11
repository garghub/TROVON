static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_7 * V_8 ;
void T_1 * V_9 ;
struct V_10 * V_11 ;
T_2 V_12 , V_13 = 0 ;
V_8 = F_2 ( V_2 , V_14 , 0 ) ;
V_9 = F_3 ( & V_2 -> V_5 , V_8 ) ;
if ( F_4 ( V_9 ) )
return F_5 ( V_9 ) ;
if ( F_6 ( V_4 , L_1 , & V_12 ) ) {
F_7 ( & V_2 -> V_5 , L_2 ) ;
return - V_15 ;
}
F_6 ( V_4 , L_3 , & V_13 ) ;
F_8 ( & V_2 -> V_5 , L_4 , V_12 , V_13 ) ;
V_11 = F_9 ( & V_2 -> V_5 , L_5 ) ;
if ( F_4 ( V_11 ) )
return F_5 ( V_11 ) ;
F_10 ( V_11 ) ;
F_11 ( ( V_12 << V_16 ) | V_13 ,
V_9 + V_17 ) ;
F_12 () ;
F_13 ( V_11 ) ;
return F_14 ( V_2 -> V_5 . V_6 , NULL , NULL , & V_2 -> V_5 ) ;
}
