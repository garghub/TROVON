void F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_2 -> V_4 )
F_2 ( V_2 -> V_4 , V_5 , V_3 , 0 ) ;
}
int F_3 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
int V_8 ;
V_7 = F_4 ( V_9 ) ;
if ( ! V_7 ) {
F_5 ( V_10 , 1 , L_1 ) ;
V_8 = - V_11 ;
goto V_12;
}
snprintf ( V_2 -> V_13 , sizeof( V_2 -> V_13 ) ,
L_2 , V_2 -> V_14 -> V_15 ) ;
snprintf ( V_2 -> V_16 , sizeof( V_2 -> V_16 ) ,
L_3 , F_6 ( V_2 -> V_17 ) ) ;
V_7 -> V_13 = V_2 -> V_13 ;
V_7 -> V_16 = V_2 -> V_16 ;
V_7 -> V_18 . V_19 = V_20 ;
V_7 -> V_18 . V_21 = V_2 -> V_22 ;
V_7 -> V_18 . V_23 = V_2 -> V_24 ;
V_7 -> V_18 . V_25 = 1 ;
V_7 -> V_26 = V_27 ;
V_7 -> V_28 = V_2 -> V_29 ? : V_30 ;
V_7 -> V_7 . V_31 = & V_2 -> V_17 -> V_7 ;
V_8 = F_7 ( V_7 ) ;
if ( V_8 ) {
F_5 ( V_10 , 1 , L_4 , V_8 ) ;
goto V_32;
}
V_2 -> V_4 = V_7 ;
return 0 ;
V_32:
F_8 ( V_7 ) ;
V_12:
return V_8 ;
}
void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_4 ) ;
}
