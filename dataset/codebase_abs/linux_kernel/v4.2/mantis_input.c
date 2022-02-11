void F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_2 -> V_4 )
F_2 ( V_2 -> V_4 , V_5 , V_3 , 0 ) ;
}
int F_3 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
int V_8 ;
V_7 = F_4 () ;
if ( ! V_7 ) {
F_5 ( V_9 , 1 , L_1 ) ;
V_8 = - V_10 ;
goto V_11;
}
snprintf ( V_2 -> V_12 , sizeof( V_2 -> V_12 ) ,
L_2 , V_2 -> V_13 -> V_14 ) ;
snprintf ( V_2 -> V_15 , sizeof( V_2 -> V_15 ) ,
L_3 , F_6 ( V_2 -> V_16 ) ) ;
V_7 -> V_12 = V_2 -> V_12 ;
V_7 -> V_15 = V_2 -> V_15 ;
V_7 -> V_17 . V_18 = V_19 ;
V_7 -> V_17 . V_20 = V_2 -> V_21 ;
V_7 -> V_17 . V_22 = V_2 -> V_23 ;
V_7 -> V_17 . V_24 = 1 ;
V_7 -> V_25 = V_26 ;
V_7 -> V_27 = V_2 -> V_28 ? : V_29 ;
V_7 -> V_7 . V_30 = & V_2 -> V_16 -> V_7 ;
V_8 = F_7 ( V_7 ) ;
if ( V_8 ) {
F_5 ( V_9 , 1 , L_4 , V_8 ) ;
goto V_31;
}
V_2 -> V_4 = V_7 ;
return 0 ;
V_31:
F_8 ( V_7 ) ;
V_11:
return V_8 ;
}
void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_4 ) ;
}
