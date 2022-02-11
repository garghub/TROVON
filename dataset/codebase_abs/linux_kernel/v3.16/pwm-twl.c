static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , struct V_4 * V_5 ,
int V_6 , int V_7 )
{
int V_8 = F_4 ( V_6 * V_9 , V_7 ) + 1 ;
T_1 V_10 [ 2 ] = { 1 , 0 } ;
int V_11 , V_12 ;
if ( V_8 == 1 )
V_8 = 2 ;
else if ( V_8 > V_9 )
V_8 = 1 ;
V_11 = V_5 -> V_13 * 3 ;
V_10 [ 1 ] = V_8 ;
V_12 = F_5 ( V_14 , V_10 , V_11 , 2 ) ;
if ( V_12 < 0 )
F_6 ( V_3 -> V_15 , L_1 , V_5 -> V_16 ) ;
return V_12 ;
}
static int F_7 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_12 ;
T_1 V_18 ;
F_8 ( & V_17 -> V_19 ) ;
V_12 = F_9 ( V_20 , & V_18 , V_21 ) ;
if ( V_12 < 0 ) {
F_6 ( V_3 -> V_15 , L_2 , V_5 -> V_16 ) ;
goto V_22;
}
V_18 |= F_10 ( V_5 -> V_13 , V_23 ) ;
V_12 = F_11 ( V_20 , V_18 , V_21 ) ;
if ( V_12 < 0 )
F_6 ( V_3 -> V_15 , L_3 , V_5 -> V_16 ) ;
V_18 |= F_10 ( V_5 -> V_13 , V_24 ) ;
V_12 = F_11 ( V_20 , V_18 , V_21 ) ;
if ( V_12 < 0 )
F_6 ( V_3 -> V_15 , L_3 , V_5 -> V_16 ) ;
V_22:
F_12 ( & V_17 -> V_19 ) ;
return V_12 ;
}
static void F_13 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_12 ;
T_1 V_18 ;
F_8 ( & V_17 -> V_19 ) ;
V_12 = F_9 ( V_20 , & V_18 , V_21 ) ;
if ( V_12 < 0 ) {
F_6 ( V_3 -> V_15 , L_2 , V_5 -> V_16 ) ;
goto V_22;
}
V_18 &= ~ F_10 ( V_5 -> V_13 , V_24 ) ;
V_12 = F_11 ( V_20 , V_18 , V_21 ) ;
if ( V_12 < 0 )
F_6 ( V_3 -> V_15 , L_4 , V_5 -> V_16 ) ;
V_18 &= ~ F_10 ( V_5 -> V_13 , V_23 ) ;
V_12 = F_11 ( V_20 , V_18 , V_21 ) ;
if ( V_12 < 0 )
F_6 ( V_3 -> V_15 , L_4 , V_5 -> V_16 ) ;
V_22:
F_12 ( & V_17 -> V_19 ) ;
}
static int F_14 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_12 ;
T_1 V_18 , V_25 , V_26 ;
if ( V_5 -> V_13 == 1 ) {
V_25 = V_27 ;
V_26 = V_28 ;
} else {
V_25 = V_29 ;
V_26 = V_30 ;
}
F_8 ( & V_17 -> V_19 ) ;
V_12 = F_9 ( V_20 , & V_18 , V_31 ) ;
if ( V_12 < 0 ) {
F_6 ( V_3 -> V_15 , L_5 , V_5 -> V_16 ) ;
goto V_22;
}
V_17 -> V_32 &= ~ V_25 ;
V_17 -> V_32 |= ( V_18 & V_25 ) ;
V_18 &= ~ V_25 ;
V_18 |= V_26 ;
V_12 = F_11 ( V_20 , V_18 , V_31 ) ;
if ( V_12 < 0 )
F_6 ( V_3 -> V_15 , L_6 , V_5 -> V_16 ) ;
V_22:
F_12 ( & V_17 -> V_19 ) ;
return V_12 ;
}
static void F_15 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_12 ;
T_1 V_18 , V_25 ;
if ( V_5 -> V_13 == 1 )
V_25 = V_27 ;
else
V_25 = V_29 ;
F_8 ( & V_17 -> V_19 ) ;
V_12 = F_9 ( V_20 , & V_18 , V_31 ) ;
if ( V_12 < 0 ) {
F_6 ( V_3 -> V_15 , L_5 , V_5 -> V_16 ) ;
goto V_22;
}
V_18 &= ~ V_25 ;
V_18 |= ( V_17 -> V_32 & V_25 ) ;
V_12 = F_11 ( V_20 , V_18 , V_31 ) ;
if ( V_12 < 0 )
F_6 ( V_3 -> V_15 , L_7 , V_5 -> V_16 ) ;
V_22:
F_12 ( & V_17 -> V_19 ) ;
}
static int F_16 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_12 ;
T_1 V_18 ;
F_8 ( & V_17 -> V_19 ) ;
V_18 = V_17 -> V_33 ;
V_18 |= F_17 ( V_5 -> V_13 , V_34 | V_35 ) ;
V_18 &= ~ F_17 ( V_5 -> V_13 , V_36 ) ;
V_12 = F_11 ( V_37 , V_18 , V_38 ) ;
if ( V_12 < 0 ) {
F_6 ( V_3 -> V_15 , L_3 , V_5 -> V_16 ) ;
goto V_22;
}
V_17 -> V_33 = V_18 ;
V_22:
F_12 ( & V_17 -> V_19 ) ;
return V_12 ;
}
static void F_18 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_17 = F_1 ( V_3 ) ;
int V_12 ;
T_1 V_18 ;
F_8 ( & V_17 -> V_19 ) ;
V_18 = V_17 -> V_33 ;
V_18 |= F_17 ( V_5 -> V_13 , V_36 ) ;
V_18 &= ~ F_17 ( V_5 -> V_13 , V_34 | V_35 ) ;
V_12 = F_11 ( V_37 , V_18 , V_38 ) ;
if ( V_12 < 0 ) {
F_6 ( V_3 -> V_15 , L_4 , V_5 -> V_16 ) ;
goto V_22;
}
V_17 -> V_33 = V_18 ;
V_22:
F_12 ( & V_17 -> V_19 ) ;
}
static int F_19 ( struct V_39 * V_40 )
{
struct V_1 * V_17 ;
int V_12 ;
V_17 = F_20 ( & V_40 -> V_15 , sizeof( * V_17 ) , V_41 ) ;
if ( ! V_17 )
return - V_42 ;
if ( F_21 () )
V_17 -> V_3 . V_43 = & V_44 ;
else
V_17 -> V_3 . V_43 = & V_45 ;
V_17 -> V_3 . V_15 = & V_40 -> V_15 ;
V_17 -> V_3 . V_11 = - 1 ;
V_17 -> V_3 . V_46 = 2 ;
V_17 -> V_3 . V_47 = true ;
F_22 ( & V_17 -> V_19 ) ;
V_12 = F_23 ( & V_17 -> V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
F_24 ( V_40 , V_17 ) ;
return 0 ;
}
static int F_25 ( struct V_39 * V_40 )
{
struct V_1 * V_17 = F_26 ( V_40 ) ;
return F_27 ( & V_17 -> V_3 ) ;
}
