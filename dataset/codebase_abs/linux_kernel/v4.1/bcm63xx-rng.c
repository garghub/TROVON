static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
int error ;
error = F_3 ( V_4 -> V_6 ) ;
if ( error )
return error ;
V_5 = F_4 ( V_4 -> V_7 + V_8 ) ;
V_5 |= V_9 ;
F_5 ( V_5 , V_4 -> V_7 + V_8 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
V_5 = F_4 ( V_4 -> V_7 + V_8 ) ;
V_5 &= ~ V_9 ;
F_5 ( V_5 , V_4 -> V_7 + V_8 ) ;
F_7 ( V_4 -> V_6 ) ;
}
static int F_8 ( struct V_1 * V_2 , int V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_4 ( V_4 -> V_7 + V_11 ) & V_12 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 * V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_13 = F_4 ( V_4 -> V_7 + V_14 ) ;
return 4 ;
}
static int F_10 ( struct V_15 * V_16 )
{
struct V_17 * V_18 ;
struct V_6 * V_6 ;
int V_19 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
V_18 = F_11 ( V_16 , V_20 , 0 ) ;
if ( ! V_18 ) {
F_12 ( & V_16 -> V_21 , L_1 ) ;
return - V_22 ;
}
V_4 = F_13 ( & V_16 -> V_21 , sizeof( * V_4 ) , V_23 ) ;
if ( ! V_4 )
return - V_24 ;
V_4 -> V_2 . V_25 = V_16 -> V_25 ;
V_4 -> V_2 . V_26 = F_1 ;
V_4 -> V_2 . V_27 = F_6 ;
V_4 -> V_2 . V_28 = F_8 ;
V_4 -> V_2 . V_29 = F_9 ;
V_4 -> V_6 = F_14 ( & V_16 -> V_21 , L_2 ) ;
if ( F_15 ( V_4 -> V_6 ) ) {
V_19 = F_16 ( V_4 -> V_6 ) ;
F_12 ( & V_16 -> V_21 , L_3 , V_19 ) ;
return V_19 ;
}
if ( ! F_17 ( & V_16 -> V_21 , V_18 -> V_30 ,
F_18 ( V_18 ) , V_16 -> V_25 ) ) {
F_12 ( & V_16 -> V_21 , L_4 ) ;
return - V_31 ;
}
V_4 -> V_7 = F_19 ( & V_16 -> V_21 , V_18 -> V_30 ,
F_18 ( V_18 ) ) ;
if ( ! V_4 -> V_7 ) {
F_12 ( & V_16 -> V_21 , L_5 ) ;
return - V_24 ;
}
V_19 = F_20 ( & V_16 -> V_21 , & V_4 -> V_2 ) ;
if ( V_19 ) {
F_12 ( & V_16 -> V_21 , L_6 ,
V_19 ) ;
return V_19 ;
}
F_21 ( & V_16 -> V_21 , L_7 ) ;
return 0 ;
}
