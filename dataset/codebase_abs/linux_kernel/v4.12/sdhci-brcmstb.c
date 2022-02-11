static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_7 ;
if ( V_4 -> V_8 != V_9 )
F_4 ( V_4 -> V_10 ) ;
V_7 = F_5 ( V_4 ) ;
if ( V_7 )
return V_7 ;
F_6 ( V_6 -> V_11 ) ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_12 ;
V_12 = F_8 ( V_6 -> V_11 ) ;
if ( V_12 )
return V_12 ;
return F_9 ( V_4 ) ;
}
static int F_10 ( struct V_13 * V_14 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_11 * V_11 ;
int V_7 ;
V_11 = F_11 ( & V_14 -> V_2 , NULL ) ;
if ( F_12 ( V_11 ) ) {
F_13 ( & V_14 -> V_2 , L_1 ) ;
V_11 = NULL ;
}
V_7 = F_8 ( V_11 ) ;
if ( V_7 )
return V_7 ;
V_4 = F_14 ( V_14 , & V_15 , 0 ) ;
if ( F_12 ( V_4 ) ) {
V_7 = F_15 ( V_4 ) ;
goto V_16;
}
V_4 -> V_10 -> V_17 |= V_18 ;
F_16 ( V_14 ) ;
F_17 ( V_4 -> V_10 ) ;
V_4 -> V_19 = F_18 ( V_4 , V_20 ) ;
if ( F_19 ( V_14 -> V_2 . V_21 , L_2 ) )
V_4 -> V_19 &= ~ V_22 ;
V_4 -> V_23 = F_18 ( V_4 , V_24 ) ;
V_4 -> V_23 &= ~ ( V_25 | V_26 |
V_27 ) ;
V_4 -> V_28 |= V_29 |
V_30 ;
V_7 = F_20 ( V_4 ) ;
if ( V_7 )
goto V_12;
V_6 = F_3 ( V_4 ) ;
V_6 -> V_11 = V_11 ;
return V_7 ;
V_12:
F_21 ( V_14 ) ;
V_16:
F_6 ( V_11 ) ;
return V_7 ;
}
