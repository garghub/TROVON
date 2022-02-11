static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
T_1 V_6 ;
V_6 = V_7 | V_8 | V_9 |
V_10 ;
V_5 = F_2 ( V_11 , V_6 , V_12 ) ;
if ( V_5 < 0 ) {
F_3 ( V_2 -> V_13 , L_1 ,
V_4 -> V_14 , V_5 ) ;
return V_5 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_15 , int V_16 )
{
T_1 V_17 = ( V_15 * V_18 ) / V_16 ;
int V_5 ;
V_5 = F_2 ( V_11 , V_17 , V_19 ) ;
if ( V_5 < 0 ) {
F_5 ( L_1 ,
V_4 -> V_14 , V_5 ) ;
return V_5 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
T_1 V_6 ;
V_5 = F_7 ( V_11 , & V_6 , V_12 ) ;
if ( V_5 < 0 ) {
F_3 ( V_2 -> V_13 , L_2 ,
V_4 -> V_14 , V_5 ) ;
return V_5 ;
}
V_6 &= ~ V_20 ;
V_6 |= V_21 ;
V_5 = F_2 ( V_11 , V_6 , V_12 ) ;
if ( V_5 < 0 ) {
F_3 ( V_2 -> V_13 , L_2 ,
V_4 -> V_14 , V_5 ) ;
return V_5 ;
}
F_7 ( V_11 , & V_6 , V_12 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
T_1 V_6 ;
V_5 = F_7 ( V_11 , & V_6 , V_12 ) ;
if ( V_5 < 0 ) {
F_3 ( V_2 -> V_13 , L_3 ,
V_4 -> V_14 , V_5 ) ;
return;
}
V_6 &= ~ V_20 ;
V_6 |= V_10 ;
V_5 = F_2 ( V_11 , V_6 , V_12 ) ;
if ( V_5 < 0 ) {
F_3 ( V_2 -> V_13 , L_3 ,
V_4 -> V_14 , V_5 ) ;
}
}
static int F_9 ( struct V_22 * V_23 )
{
struct V_24 * V_25 ;
int V_5 ;
V_25 = F_10 ( & V_23 -> V_13 , sizeof( * V_25 ) , V_26 ) ;
if ( ! V_25 )
return - V_27 ;
V_25 -> V_2 . V_13 = & V_23 -> V_13 ;
V_25 -> V_2 . V_28 = & V_29 ;
V_25 -> V_2 . V_30 = - 1 ;
V_25 -> V_2 . V_31 = 1 ;
V_5 = F_11 ( & V_25 -> V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
F_12 ( V_23 , V_25 ) ;
return 0 ;
}
static int F_13 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = F_14 ( V_23 ) ;
return F_15 ( & V_25 -> V_2 ) ;
}
