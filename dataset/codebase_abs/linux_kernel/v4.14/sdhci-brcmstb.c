static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_7 ;
int V_8 ;
V_7 = F_2 ( & V_2 -> V_9 , NULL ) ;
if ( F_3 ( V_7 ) ) {
F_4 ( & V_2 -> V_9 , L_1 ) ;
V_7 = NULL ;
}
V_8 = F_5 ( V_7 ) ;
if ( V_8 )
return V_8 ;
V_4 = F_6 ( V_2 , & V_10 , 0 ) ;
if ( F_3 ( V_4 ) ) {
V_8 = F_7 ( V_4 ) ;
goto V_11;
}
F_8 ( V_2 ) ;
F_9 ( V_4 -> V_12 ) ;
V_4 -> V_13 = F_10 ( V_4 , V_14 ) ;
if ( F_11 ( V_2 -> V_9 . V_15 , L_2 ) )
V_4 -> V_13 &= ~ V_16 ;
V_4 -> V_17 = F_10 ( V_4 , V_18 ) ;
V_4 -> V_17 &= ~ ( V_19 | V_20 |
V_21 ) ;
V_4 -> V_22 |= V_23 |
V_24 ;
V_8 = F_12 ( V_4 ) ;
if ( V_8 )
goto V_25;
V_6 = F_13 ( V_4 ) ;
V_6 -> V_7 = V_7 ;
return V_8 ;
V_25:
F_14 ( V_2 ) ;
V_11:
F_15 ( V_7 ) ;
return V_8 ;
}
