static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
int V_8 ;
V_7 -> V_9 |= V_10 ;
V_8 = F_4 ( V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
F_5 ( 120 ) ;
V_8 = F_6 (dsi, 0xae , (u8[]){ 0x03 }, 1 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_7 ( V_7 , V_11 |
( V_11 << 4 ) ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
int V_8 ;
V_7 -> V_9 |= V_10 ;
V_8 = F_9 ( V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
int V_8 ;
V_7 -> V_9 &= ~ V_10 ;
V_8 = F_11 ( V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_12 ( V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( ! V_5 -> V_12 )
return 0 ;
if ( V_5 -> V_13 ) {
V_5 -> V_13 -> V_14 . V_15 = V_16 ;
F_14 ( V_5 -> V_13 ) ;
}
V_5 -> V_12 = false ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_8 ;
if ( ! V_5 -> V_17 )
return 0 ;
V_8 = F_10 ( V_5 ) ;
if ( V_8 < 0 ) {
F_16 ( V_3 -> V_18 , L_1 , V_8 ) ;
return V_8 ;
}
F_17 ( V_5 -> V_19 ) ;
if ( V_5 -> V_20 )
F_18 ( V_5 -> V_20 , 0 ) ;
V_5 -> V_17 = false ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_8 ;
if ( V_5 -> V_17 )
return 0 ;
V_8 = F_20 ( V_5 -> V_19 ) ;
if ( V_8 < 0 )
return V_8 ;
F_5 ( 20 ) ;
if ( V_5 -> V_20 ) {
F_18 ( V_5 -> V_20 , 1 ) ;
F_5 ( 1 ) ;
F_18 ( V_5 -> V_20 , 0 ) ;
F_5 ( 1 ) ;
F_18 ( V_5 -> V_20 , 1 ) ;
F_5 ( 10 ) ;
}
V_8 = F_3 ( V_5 ) ;
if ( V_8 < 0 ) {
F_16 ( V_3 -> V_18 , L_2 , V_8 ) ;
goto V_21;
}
V_8 = F_8 ( V_5 ) ;
if ( V_8 < 0 ) {
F_16 ( V_3 -> V_18 , L_3 , V_8 ) ;
goto V_21;
}
V_5 -> V_17 = true ;
return 0 ;
V_21:
F_17 ( V_5 -> V_19 ) ;
if ( V_5 -> V_20 )
F_18 ( V_5 -> V_20 , 0 ) ;
return V_8 ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_5 -> V_12 )
return 0 ;
if ( V_5 -> V_13 ) {
V_5 -> V_13 -> V_14 . V_15 = V_22 ;
F_14 ( V_5 -> V_13 ) ;
}
V_5 -> V_12 = true ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_23 * V_24 ;
V_24 = F_23 ( V_3 -> V_25 , & V_26 ) ;
if ( ! V_24 ) {
F_16 ( V_3 -> V_25 -> V_18 , L_4 ,
V_26 . V_27 , V_26 . V_28 ,
V_26 . V_29 ) ;
return - V_30 ;
}
F_24 ( V_24 ) ;
F_25 ( V_3 -> V_31 , V_24 ) ;
V_3 -> V_31 -> V_32 . V_33 = 54 ;
V_3 -> V_31 -> V_32 . V_34 = 95 ;
return 1 ;
}
static int F_26 ( struct V_1 * V_5 )
{
struct V_35 * V_18 = & V_5 -> V_7 -> V_18 ;
struct V_36 * V_37 ;
int V_8 ;
V_5 -> V_24 = & V_26 ;
V_5 -> V_19 = F_27 ( V_18 , L_5 ) ;
if ( F_28 ( V_5 -> V_19 ) )
return F_29 ( V_5 -> V_19 ) ;
V_5 -> V_20 = F_30 ( V_18 , L_6 , V_38 ) ;
if ( F_28 ( V_5 -> V_20 ) ) {
F_16 ( V_18 , L_7 ,
F_29 ( V_5 -> V_20 ) ) ;
V_5 -> V_20 = NULL ;
} else {
F_18 ( V_5 -> V_20 , 0 ) ;
}
V_37 = F_31 ( V_18 -> V_39 , L_8 , 0 ) ;
if ( V_37 ) {
V_5 -> V_13 = F_32 ( V_37 ) ;
F_33 ( V_37 ) ;
if ( ! V_5 -> V_13 )
return - V_40 ;
}
F_34 ( & V_5 -> V_4 ) ;
V_5 -> V_4 . V_41 = & V_42 ;
V_5 -> V_4 . V_18 = & V_5 -> V_7 -> V_18 ;
V_8 = F_35 ( & V_5 -> V_4 ) ;
if ( V_8 < 0 )
goto V_43;
return 0 ;
V_43:
if ( V_5 -> V_13 )
F_36 ( & V_5 -> V_13 -> V_18 ) ;
return V_8 ;
}
static void F_37 ( struct V_1 * V_5 )
{
if ( V_5 -> V_4 . V_18 )
F_38 ( & V_5 -> V_4 ) ;
if ( V_5 -> V_13 )
F_36 ( & V_5 -> V_13 -> V_18 ) ;
}
static int F_39 ( struct V_6 * V_7 )
{
struct V_1 * V_5 ;
int V_8 ;
V_7 -> V_44 = 2 ;
V_7 -> V_45 = V_46 ;
V_7 -> V_9 = V_47 |
V_48 |
V_49 |
V_50 ;
V_5 = F_40 ( & V_7 -> V_18 , sizeof( * V_5 ) , V_51 ) ;
if ( ! V_5 )
return - V_30 ;
F_41 ( V_7 , V_5 ) ;
V_5 -> V_7 = V_7 ;
V_8 = F_26 ( V_5 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_42 ( V_7 ) ;
}
static int F_43 ( struct V_6 * V_7 )
{
struct V_1 * V_5 = F_44 ( V_7 ) ;
int V_8 ;
V_8 = F_13 ( & V_5 -> V_4 ) ;
if ( V_8 < 0 )
F_16 ( & V_7 -> V_18 , L_9 , V_8 ) ;
V_8 = F_45 ( V_7 ) ;
if ( V_8 < 0 )
F_16 ( & V_7 -> V_18 , L_10 , V_8 ) ;
F_46 ( & V_5 -> V_4 ) ;
F_37 ( V_5 ) ;
return 0 ;
}
static void F_47 ( struct V_6 * V_7 )
{
struct V_1 * V_5 = F_44 ( V_7 ) ;
F_13 ( & V_5 -> V_4 ) ;
}
