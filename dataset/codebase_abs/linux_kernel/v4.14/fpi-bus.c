static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
void T_1 * V_12 ;
T_2 V_13 ;
int V_14 ;
V_9 = F_2 ( V_2 , V_15 , 0 ) ;
V_12 = F_3 ( V_4 , V_9 ) ;
if ( F_4 ( V_12 ) )
return F_5 ( V_12 ) ;
V_11 = F_6 ( V_6 , L_1 ) ;
if ( F_4 ( V_11 ) )
return F_5 ( V_11 ) ;
V_14 = F_7 ( V_4 , L_2 ,
& V_13 ) ;
if ( V_14 ) {
F_8 ( & V_2 -> V_4 , L_3 ) ;
return V_14 ;
}
V_14 = F_9 ( V_11 , V_13 ,
V_16 , V_16 ) ;
if ( V_14 ) {
F_10 ( & V_2 -> V_4 ,
L_4 ) ;
return V_14 ;
}
F_11 ( V_17 , 0 , V_12 + V_18 ) ;
return F_12 ( V_4 -> V_7 , NULL , NULL , V_4 ) ;
}
