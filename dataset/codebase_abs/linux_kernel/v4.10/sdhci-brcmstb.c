static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_7 ;
V_7 = F_4 ( V_4 ) ;
if ( V_7 )
return V_7 ;
F_5 ( V_6 -> V_8 ) ;
return V_7 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_9 ;
V_9 = F_7 ( V_6 -> V_8 ) ;
if ( V_9 )
return V_9 ;
return F_8 ( V_4 ) ;
}
static int F_9 ( struct V_10 * V_11 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_8 * V_8 ;
int V_7 ;
V_8 = F_10 ( & V_11 -> V_2 , NULL ) ;
if ( F_11 ( V_8 ) ) {
F_12 ( & V_11 -> V_2 , L_1 ) ;
V_8 = NULL ;
}
V_7 = F_7 ( V_8 ) ;
if ( V_7 )
return V_7 ;
V_4 = F_13 ( V_11 , & V_12 , 0 ) ;
if ( F_11 ( V_4 ) ) {
V_7 = F_14 ( V_4 ) ;
goto V_13;
}
V_4 -> V_14 -> V_15 |= V_16 ;
F_15 ( V_11 ) ;
F_16 ( V_4 -> V_14 ) ;
V_4 -> V_17 = F_17 ( V_4 , V_18 ) ;
if ( F_18 ( V_11 -> V_2 . V_19 , L_2 ) )
V_4 -> V_17 &= ~ V_20 ;
V_4 -> V_21 = F_17 ( V_4 , V_22 ) ;
V_4 -> V_21 &= ~ ( V_23 | V_24 |
V_25 ) ;
V_4 -> V_26 |= V_27 |
V_28 ;
V_7 = F_19 ( V_4 ) ;
if ( V_7 )
goto V_9;
V_6 = F_3 ( V_4 ) ;
V_6 -> V_8 = V_8 ;
return V_7 ;
V_9:
F_20 ( V_11 ) ;
V_13:
F_5 ( V_8 ) ;
return V_7 ;
}
