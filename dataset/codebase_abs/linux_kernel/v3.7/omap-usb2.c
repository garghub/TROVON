int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = F_2 ( V_7 ) ;
if ( F_3 ( V_6 ) )
return - V_8 ;
V_4 = F_4 ( V_6 ) ;
V_4 -> V_2 = V_2 ;
return 0 ;
}
static void F_5 ( struct V_3 * V_4 , int V_9 )
{
T_1 V_10 ;
if ( V_9 ) {
V_10 = F_6 ( V_4 -> V_11 ) ;
if ( V_10 & V_12 ) {
F_7 ( ~ V_12 , V_4 -> V_11 ) ;
F_8 ( 200 ) ;
}
} else {
F_7 ( V_12 , V_4 -> V_11 ) ;
}
}
static int F_9 ( struct V_13 * V_14 , bool V_15 )
{
struct V_3 * V_4 = F_4 ( V_14 -> V_4 ) ;
if ( ! V_4 -> V_2 )
return - V_8 ;
return V_4 -> V_2 -> V_16 ( V_4 -> V_2 , V_15 ) ;
}
static int F_10 ( struct V_13 * V_14 )
{
struct V_3 * V_4 = F_4 ( V_14 -> V_4 ) ;
if ( ! V_4 -> V_2 )
return - V_8 ;
return V_4 -> V_2 -> V_17 ( V_4 -> V_2 ) ;
}
static int F_11 ( struct V_13 * V_14 , struct V_18 * V_19 )
{
struct V_5 * V_4 = V_14 -> V_4 ;
V_14 -> V_19 = V_19 ;
if ( ! V_19 )
V_4 -> V_20 = V_21 ;
return 0 ;
}
static int F_12 ( struct V_13 * V_14 ,
struct V_22 * V_23 )
{
struct V_5 * V_4 = V_14 -> V_4 ;
V_14 -> V_23 = V_23 ;
if ( ! V_23 )
V_4 -> V_20 = V_21 ;
return 0 ;
}
static int F_13 ( struct V_5 * V_6 , int V_24 )
{
T_1 V_25 ;
struct V_3 * V_4 = F_4 ( V_6 ) ;
if ( V_24 && ! V_4 -> V_26 ) {
F_5 ( V_4 , 0 ) ;
F_14 ( V_4 -> V_27 ) ;
V_4 -> V_26 = 1 ;
} else if ( ! V_24 && V_4 -> V_26 ) {
V_25 = F_15 ( V_4 -> V_27 ) ;
if ( V_25 < 0 ) {
F_16 ( V_4 -> V_27 , L_1 ,
V_25 ) ;
return V_25 ;
}
F_5 ( V_4 , 1 ) ;
V_4 -> V_26 = 0 ;
}
return 0 ;
}
static int T_2 F_17 ( struct V_28 * V_29 )
{
struct V_3 * V_4 ;
struct V_13 * V_14 ;
struct V_30 * V_31 ;
V_4 = F_18 ( & V_29 -> V_27 , sizeof( * V_4 ) , V_32 ) ;
if ( ! V_4 ) {
F_16 ( & V_29 -> V_27 , L_2 ) ;
return - V_33 ;
}
V_14 = F_18 ( & V_29 -> V_27 , sizeof( * V_14 ) , V_32 ) ;
if ( ! V_14 ) {
F_16 ( & V_29 -> V_27 , L_3 ) ;
return - V_33 ;
}
V_4 -> V_27 = & V_29 -> V_27 ;
V_4 -> V_4 . V_27 = V_4 -> V_27 ;
V_4 -> V_4 . V_34 = L_4 ;
V_4 -> V_4 . V_35 = F_13 ;
V_4 -> V_4 . V_14 = V_14 ;
V_31 = F_19 ( V_29 , V_36 , 1 ) ;
V_4 -> V_11 = F_20 ( & V_29 -> V_27 , V_31 ) ;
if ( V_4 -> V_11 == NULL ) {
F_16 ( & V_29 -> V_27 , L_5 ) ;
return - V_37 ;
}
V_4 -> V_26 = 1 ;
F_5 ( V_4 , 0 ) ;
V_14 -> V_38 = F_11 ;
V_14 -> V_39 = F_12 ;
V_14 -> V_16 = F_9 ;
V_14 -> V_17 = F_10 ;
V_14 -> V_4 = & V_4 -> V_4 ;
V_4 -> V_40 = F_21 ( V_4 -> V_27 , L_6 ) ;
if ( F_3 ( V_4 -> V_40 ) ) {
F_16 ( & V_29 -> V_27 , L_7 ) ;
return F_22 ( V_4 -> V_40 ) ;
}
F_23 ( V_4 -> V_40 ) ;
F_24 ( & V_4 -> V_4 , V_7 ) ;
F_25 ( V_29 , V_4 ) ;
F_26 ( V_4 -> V_27 ) ;
return 0 ;
}
static int T_3 F_27 ( struct V_28 * V_29 )
{
struct V_3 * V_4 = F_28 ( V_29 ) ;
F_29 ( V_4 -> V_40 ) ;
F_30 ( & V_4 -> V_4 ) ;
return 0 ;
}
static int F_31 ( struct V_41 * V_27 )
{
struct V_28 * V_29 = F_32 ( V_27 ) ;
struct V_3 * V_4 = F_28 ( V_29 ) ;
F_33 ( V_4 -> V_40 ) ;
return 0 ;
}
static int F_34 ( struct V_41 * V_27 )
{
T_1 V_25 = 0 ;
struct V_28 * V_29 = F_32 ( V_27 ) ;
struct V_3 * V_4 = F_28 ( V_29 ) ;
V_25 = F_35 ( V_4 -> V_40 ) ;
if ( V_25 < 0 )
F_16 ( V_4 -> V_27 , L_8 , V_25 ) ;
return V_25 ;
}
