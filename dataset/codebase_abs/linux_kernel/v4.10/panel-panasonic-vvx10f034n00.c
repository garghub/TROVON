static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
int V_8 ;
V_8 = F_4 ( V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( ! V_5 -> V_9 )
return 0 ;
F_6 ( V_5 -> V_7 ) ;
if ( V_5 -> V_10 ) {
V_5 -> V_10 -> V_11 . V_12 = V_13 ;
V_5 -> V_10 -> V_11 . V_14 |= V_15 ;
F_7 ( V_5 -> V_10 ) ;
}
V_5 -> V_9 = false ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( ! V_5 -> V_16 )
return 0 ;
F_9 ( V_5 -> V_17 ) ;
V_5 -> V_18 = F_10 ( F_11 () , V_19 ) ;
V_5 -> V_16 = false ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_8 ;
T_1 V_20 ;
if ( V_5 -> V_16 )
return 0 ;
V_20 = F_13 ( V_5 -> V_18 , F_11 () ) ;
if ( V_20 > V_19 )
V_20 = V_19 ;
if ( V_20 > 0 )
F_14 ( V_20 ) ;
V_8 = F_15 ( V_5 -> V_17 ) ;
if ( V_8 < 0 )
return V_8 ;
F_14 ( 250 ) ;
V_8 = F_3 ( V_5 ) ;
if ( V_8 < 0 ) {
F_16 ( V_3 -> V_21 , L_1 , V_8 ) ;
goto V_22;
}
V_5 -> V_16 = true ;
return 0 ;
V_22:
F_9 ( V_5 -> V_17 ) ;
return V_8 ;
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_5 -> V_9 )
return 0 ;
if ( V_5 -> V_10 ) {
V_5 -> V_10 -> V_11 . V_12 = V_23 ;
V_5 -> V_10 -> V_11 . V_14 &= ~ V_15 ;
F_7 ( V_5 -> V_10 ) ;
}
V_5 -> V_9 = true ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 )
{
struct V_24 * V_25 ;
V_25 = F_19 ( V_3 -> V_26 , & V_27 ) ;
if ( ! V_25 ) {
F_16 ( V_3 -> V_26 -> V_21 , L_2 ,
V_27 . V_28 , V_27 . V_29 ,
V_27 . V_30 ) ;
return - V_31 ;
}
F_20 ( V_25 ) ;
F_21 ( V_3 -> V_32 , V_25 ) ;
V_3 -> V_32 -> V_33 . V_34 = 217 ;
V_3 -> V_32 -> V_33 . V_35 = 136 ;
return 1 ;
}
static int F_22 ( struct V_1 * V_5 )
{
struct V_36 * V_21 = & V_5 -> V_7 -> V_21 ;
struct V_37 * V_38 ;
int V_8 ;
V_5 -> V_25 = & V_27 ;
V_5 -> V_17 = F_23 ( V_21 , L_3 ) ;
if ( F_24 ( V_5 -> V_17 ) )
return F_25 ( V_5 -> V_17 ) ;
V_38 = F_26 ( V_21 -> V_39 , L_4 , 0 ) ;
if ( V_38 ) {
V_5 -> V_10 = F_27 ( V_38 ) ;
F_28 ( V_38 ) ;
if ( ! V_5 -> V_10 )
return - V_40 ;
}
F_29 ( & V_5 -> V_4 ) ;
V_5 -> V_4 . V_41 = & V_42 ;
V_5 -> V_4 . V_21 = & V_5 -> V_7 -> V_21 ;
V_8 = F_30 ( & V_5 -> V_4 ) ;
if ( V_8 < 0 )
goto V_43;
return 0 ;
V_43:
if ( V_5 -> V_10 )
F_31 ( & V_5 -> V_10 -> V_21 ) ;
return V_8 ;
}
static void F_32 ( struct V_1 * V_5 )
{
if ( V_5 -> V_4 . V_21 )
F_33 ( & V_5 -> V_4 ) ;
if ( V_5 -> V_10 )
F_31 ( & V_5 -> V_10 -> V_21 ) ;
}
static int F_34 ( struct V_6 * V_7 )
{
struct V_1 * V_5 ;
int V_8 ;
V_7 -> V_44 = 4 ;
V_7 -> V_45 = V_46 ;
V_7 -> V_47 = V_48 |
V_49 |
V_50 |
V_51 ;
V_5 = F_35 ( & V_7 -> V_21 , sizeof( * V_5 ) , V_52 ) ;
if ( ! V_5 )
return - V_31 ;
F_36 ( V_7 , V_5 ) ;
V_5 -> V_7 = V_7 ;
V_8 = F_22 ( V_5 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_37 ( V_7 ) ;
}
static int F_38 ( struct V_6 * V_7 )
{
struct V_1 * V_5 = F_39 ( V_7 ) ;
int V_8 ;
V_8 = F_5 ( & V_5 -> V_4 ) ;
if ( V_8 < 0 )
F_16 ( & V_7 -> V_21 , L_5 , V_8 ) ;
V_8 = F_40 ( V_7 ) ;
if ( V_8 < 0 )
F_16 ( & V_7 -> V_21 , L_6 , V_8 ) ;
F_41 ( & V_5 -> V_4 ) ;
F_32 ( V_5 ) ;
return 0 ;
}
static void F_42 ( struct V_6 * V_7 )
{
struct V_1 * V_5 = F_39 ( V_7 ) ;
F_5 ( & V_5 -> V_4 ) ;
}
