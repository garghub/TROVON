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
V_11 = V_5 -> V_13 * 2 + V_14 ;
V_10 [ 1 ] = V_8 ;
V_12 = F_5 ( V_15 , V_10 , V_11 , 2 ) ;
if ( V_12 < 0 )
F_6 ( V_3 -> V_16 , L_1 , V_5 -> V_17 ) ;
return V_12 ;
}
static int F_7 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
int V_12 ;
T_1 V_19 ;
F_8 ( & V_18 -> V_20 ) ;
V_12 = F_9 ( V_15 , & V_19 , V_21 ) ;
if ( V_12 < 0 ) {
F_6 ( V_3 -> V_16 , L_2 , V_5 -> V_17 ) ;
goto V_22;
}
V_19 |= F_10 ( V_5 -> V_13 , V_23 ) ;
V_12 = F_11 ( V_15 , V_19 , V_21 ) ;
if ( V_12 < 0 )
F_6 ( V_3 -> V_16 , L_3 , V_5 -> V_17 ) ;
V_22:
F_12 ( & V_18 -> V_20 ) ;
return V_12 ;
}
static void F_13 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
int V_12 ;
T_1 V_19 ;
F_8 ( & V_18 -> V_20 ) ;
V_12 = F_9 ( V_15 , & V_19 , V_21 ) ;
if ( V_12 < 0 ) {
F_6 ( V_3 -> V_16 , L_2 , V_5 -> V_17 ) ;
goto V_22;
}
V_19 &= ~ F_10 ( V_5 -> V_13 , V_23 ) ;
V_12 = F_11 ( V_15 , V_19 , V_21 ) ;
if ( V_12 < 0 )
F_6 ( V_3 -> V_16 , L_4 , V_5 -> V_17 ) ;
V_22:
F_12 ( & V_18 -> V_20 ) ;
}
static int F_14 ( struct V_2 * V_3 , struct V_4 * V_5 ,
int V_6 , int V_7 )
{
int V_8 = ( V_6 * V_24 ) / V_7 ;
T_1 V_25 ;
int V_12 ;
V_25 = V_8 & 0xff ;
V_12 = F_11 ( V_26 , V_25 ,
V_27 ) ;
if ( V_12 < 0 )
F_6 ( V_3 -> V_16 , L_1 , V_5 -> V_17 ) ;
return V_12 ;
}
static int F_15 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
int V_12 ;
T_1 V_19 ;
F_8 ( & V_18 -> V_20 ) ;
V_12 = F_9 ( V_26 , & V_19 , V_28 ) ;
if ( V_12 < 0 ) {
F_6 ( V_3 -> V_16 , L_5 ,
V_5 -> V_17 ) ;
goto V_22;
}
V_19 &= ~ V_29 ;
V_19 |= V_30 ;
V_12 = F_11 ( V_26 , V_19 , V_28 ) ;
if ( V_12 < 0 )
F_6 ( V_3 -> V_16 , L_3 , V_5 -> V_17 ) ;
V_22:
F_12 ( & V_18 -> V_20 ) ;
return V_12 ;
}
static void F_16 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
int V_12 ;
T_1 V_19 ;
F_8 ( & V_18 -> V_20 ) ;
V_12 = F_9 ( V_26 , & V_19 , V_28 ) ;
if ( V_12 < 0 ) {
F_6 ( V_3 -> V_16 , L_5 ,
V_5 -> V_17 ) ;
goto V_22;
}
V_19 &= ~ V_29 ;
V_19 |= V_31 ;
V_12 = F_11 ( V_26 , V_19 , V_28 ) ;
if ( V_12 < 0 )
F_6 ( V_3 -> V_16 , L_4 , V_5 -> V_17 ) ;
V_22:
F_12 ( & V_18 -> V_20 ) ;
}
static int F_17 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
int V_12 ;
T_1 V_19 ;
F_8 ( & V_18 -> V_20 ) ;
V_12 = F_9 ( V_26 , & V_19 , V_28 ) ;
if ( V_12 < 0 ) {
F_6 ( V_3 -> V_16 , L_5 ,
V_5 -> V_17 ) ;
goto V_22;
}
V_19 &= ~ V_29 ;
V_19 |= V_31 ;
V_12 = F_11 ( V_26 , V_19 , V_28 ) ;
if ( V_12 < 0 )
F_6 ( V_3 -> V_16 , L_6 , V_5 -> V_17 ) ;
V_22:
F_12 ( & V_18 -> V_20 ) ;
return V_12 ;
}
static void F_18 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
int V_12 ;
T_1 V_19 ;
F_8 ( & V_18 -> V_20 ) ;
V_12 = F_9 ( V_26 , & V_19 , V_28 ) ;
if ( V_12 < 0 ) {
F_6 ( V_3 -> V_16 , L_5 ,
V_5 -> V_17 ) ;
goto V_22;
}
V_19 &= ~ V_29 ;
V_19 |= V_32 ;
V_12 = F_11 ( V_26 , V_19 , V_28 ) ;
if ( V_12 < 0 )
F_6 ( V_3 -> V_16 , L_7 , V_5 -> V_17 ) ;
V_22:
F_12 ( & V_18 -> V_20 ) ;
}
static int F_19 ( struct V_33 * V_34 )
{
struct V_1 * V_18 ;
int V_12 ;
V_18 = F_20 ( & V_34 -> V_16 , sizeof( * V_18 ) , V_35 ) ;
if ( ! V_18 )
return - V_36 ;
if ( F_21 () ) {
V_18 -> V_3 . V_37 = & V_38 ;
V_18 -> V_3 . V_39 = 2 ;
} else {
V_18 -> V_3 . V_37 = & V_40 ;
V_18 -> V_3 . V_39 = 1 ;
}
V_18 -> V_3 . V_16 = & V_34 -> V_16 ;
V_18 -> V_3 . V_11 = - 1 ;
F_22 ( & V_18 -> V_20 ) ;
V_12 = F_23 ( & V_18 -> V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
F_24 ( V_34 , V_18 ) ;
return 0 ;
}
static int F_25 ( struct V_33 * V_34 )
{
struct V_1 * V_18 = F_26 ( V_34 ) ;
return F_27 ( & V_18 -> V_3 ) ;
}
