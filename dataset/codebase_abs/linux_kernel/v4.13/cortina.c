static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 . V_5 , V_2 -> V_4 . V_6 ,
V_7 | V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
V_2 -> V_8 = V_9 ;
V_2 -> V_10 = V_9 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_11 , V_12 = 0 ;
V_11 = F_1 ( V_2 , V_13 ) ;
if ( V_11 < 0 ) {
V_12 = V_11 ;
goto V_14;
}
if ( V_11 & 0x8 ) {
V_2 -> V_15 = V_16 ;
V_2 -> V_17 = V_18 ;
V_2 -> V_19 = 1 ;
} else {
V_2 -> V_19 = 0 ;
}
V_14:
return V_12 ;
}
static int F_5 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
T_2 V_20 = 0 ;
int V_21 = 0 , V_22 = 0 ;
V_21 = F_1 ( V_2 , V_23 ) ;
if ( V_21 < 0 )
return - V_24 ;
V_20 = V_21 << 16 ;
V_22 = F_1 ( V_2 , V_25 ) ;
if ( V_22 < 0 )
return - V_24 ;
V_20 |= V_22 ;
if ( V_20 != V_2 -> V_26 -> V_20 ) {
F_7 ( V_2 , L_1 ,
V_2 -> V_26 -> V_27 ) ;
return - V_28 ;
}
return 0 ;
}
