static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_3 * V_6 = V_2 -> V_7 ;
int V_8 ;
V_8 = F_2 ( V_4 , V_9 |
V_10 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_3 ( V_4 , 0 , 11289600 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_2 ( V_6 , V_9 |
V_11 ) ;
return V_8 ;
}
static int F_4 ( struct V_12 * V_13 )
{
int V_8 = - V_14 ;
struct V_15 * V_16 = V_13 -> V_17 . V_18 ;
if ( ! V_16 ) {
F_5 ( & V_13 -> V_17 , L_1 ) ;
goto V_19;
}
V_20 = F_6 ( L_2 , V_16 -> V_21 ) ;
if ( ! V_20 )
goto V_19;
V_22 . V_23 = V_16 -> V_23 ;
V_22 . V_24 = V_16 -> V_23 ;
V_22 . V_25 = V_16 -> V_7 ;
V_22 . V_26 = V_16 -> V_27 ;
V_22 . V_28 = V_16 -> V_4 ;
V_29 . V_23 = V_16 -> V_30 ;
F_7 ( V_20 , & V_29 ) ;
V_8 = F_8 ( V_20 ) ;
if ( V_8 )
F_9 ( V_20 ) ;
V_19:
return V_8 ;
}
static int F_10 ( struct V_12 * V_13 )
{
F_11 ( V_20 ) ;
return 0 ;
}
