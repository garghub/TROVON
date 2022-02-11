static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_5 , T_1 V_6 , T_2 V_7 )
{
T_2 V_8 [ 3 ] = { V_6 >> 8 , V_6 & 0xff , V_7 } ;
struct V_9 * V_10 = V_5 -> V_11 ;
T_3 V_12 ;
V_12 = F_4 ( V_10 , V_8 , sizeof( V_8 ) ) ;
if ( V_12 < 0 ) {
F_5 ( & V_10 -> V_13 , L_1 ,
V_7 , V_6 , V_12 ) ;
return V_12 ;
}
V_12 = F_6 ( V_10 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_10 -> V_13 , L_2 , V_12 ) ;
return V_12 ;
}
F_7 ( 10 , 20 ) ;
return 0 ;
}
static T_4 int F_8 ( struct V_1 * V_5 ,
T_1 V_6 , T_2 * V_7 )
{
T_3 V_12 ;
F_9 ( & V_6 ) ;
V_12 = F_10 ( V_5 -> V_11 , & V_6 , sizeof( V_6 ) ,
V_7 , sizeof( * V_7 ) ) ;
if ( V_12 < 0 )
F_5 ( & V_5 -> V_11 -> V_13 , L_3 ,
V_6 , V_12 ) ;
return V_12 ;
}
static int F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( ! V_5 -> V_14 )
return 0 ;
if ( V_5 -> V_15 ) {
V_5 -> V_15 -> V_16 . V_17 = V_18 ;
F_12 ( V_5 -> V_15 ) ;
}
V_5 -> V_14 = false ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_12 ;
if ( ! V_5 -> V_19 )
return 0 ;
V_12 = F_14 ( V_5 -> V_11 ) ;
if ( V_12 < 0 )
F_5 ( V_3 -> V_13 , L_4 , V_12 ) ;
V_12 = F_15 ( V_5 -> V_11 ) ;
if ( V_12 < 0 )
F_5 ( V_3 -> V_13 , L_5 , V_12 ) ;
F_16 ( 120 ) ;
F_17 ( V_5 -> V_20 ) ;
V_5 -> V_19 = false ;
return 0 ;
}
static int F_18 ( struct V_9 * V_21 ,
struct V_9 * V_22 ,
const struct V_23 * V_24 )
{
int V_12 ;
V_12 = F_19 ( V_21 , 0 , V_24 -> V_25 / 2 - 1 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_21 -> V_13 , L_6 , V_12 ) ;
return V_12 ;
}
V_12 = F_20 ( V_21 , 0 , V_24 -> V_26 - 1 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_21 -> V_13 , L_7 , V_12 ) ;
return V_12 ;
}
V_12 = F_19 ( V_22 , V_24 -> V_25 / 2 ,
V_24 -> V_25 - 1 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_22 -> V_13 , L_6 , V_12 ) ;
return V_12 ;
}
V_12 = F_20 ( V_22 , 0 , V_24 -> V_26 - 1 ) ;
if ( V_12 < 0 ) {
F_5 ( & V_22 -> V_13 , L_7 , V_12 ) ;
return V_12 ;
}
return 0 ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_2 V_27 = V_28 ;
int V_12 ;
if ( V_5 -> V_19 )
return 0 ;
V_12 = F_22 ( V_5 -> V_20 ) ;
if ( V_12 < 0 )
return V_12 ;
F_7 ( 10000 , 20000 ) ;
V_12 = F_23 ( V_5 -> V_11 ) ;
if ( V_12 < 0 ) {
F_5 ( V_3 -> V_13 , L_8 , V_12 ) ;
goto V_29;
}
F_16 ( 120 ) ;
V_12 = F_24 ( V_5 -> V_11 ) ;
if ( V_12 < 0 ) {
F_5 ( V_3 -> V_13 , L_9 , V_12 ) ;
goto V_29;
}
V_12 = F_3 ( V_5 , 0x1000 , 0x2a ) ;
if ( V_12 < 0 ) {
F_5 ( V_3 -> V_13 , L_10 , V_12 ) ;
goto V_29;
}
V_12 = F_3 ( V_5 , 0x1001 , 0x01 ) ;
if ( V_12 < 0 ) {
F_5 ( V_3 -> V_13 , L_11 , V_12 ) ;
goto V_29;
}
V_12 = F_25 ( V_5 -> V_11 , V_27 ) ;
if ( V_12 < 0 ) {
F_5 ( V_3 -> V_13 , L_12 , V_12 ) ;
goto V_29;
}
V_12 = F_18 ( V_5 -> V_11 , V_5 -> V_30 ,
V_5 -> V_24 ) ;
if ( V_12 < 0 ) {
F_5 ( V_3 -> V_13 , L_13 ,
V_12 ) ;
goto V_29;
}
V_12 = F_26 ( V_5 -> V_11 ) ;
if ( V_12 < 0 ) {
F_5 ( V_3 -> V_13 , L_14 , V_12 ) ;
goto V_29;
}
V_5 -> V_19 = true ;
return 0 ;
V_29:
F_17 ( V_5 -> V_20 ) ;
return V_12 ;
}
static int F_27 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_5 -> V_14 )
return 0 ;
if ( V_5 -> V_15 ) {
V_5 -> V_15 -> V_16 . V_17 = V_31 ;
F_12 ( V_5 -> V_15 ) ;
}
V_5 -> V_14 = true ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_23 * V_24 ;
V_24 = F_29 ( V_3 -> V_32 , & V_33 ) ;
if ( ! V_24 ) {
F_5 ( V_3 -> V_32 -> V_13 , L_15 ,
V_33 . V_25 , V_33 . V_26 ,
V_33 . V_34 ) ;
return - V_35 ;
}
F_30 ( V_24 ) ;
F_31 ( V_3 -> V_36 , V_24 ) ;
V_3 -> V_36 -> V_37 . V_38 = 217 ;
V_3 -> V_36 -> V_37 . V_39 = 136 ;
return 1 ;
}
static int F_32 ( struct V_1 * V_5 )
{
struct V_40 * V_41 ;
int V_12 ;
V_5 -> V_24 = & V_33 ;
V_5 -> V_20 = F_33 ( & V_5 -> V_11 -> V_13 , L_16 ) ;
if ( F_34 ( V_5 -> V_20 ) )
return F_35 ( V_5 -> V_20 ) ;
V_41 = F_36 ( V_5 -> V_11 -> V_13 . V_42 , L_17 , 0 ) ;
if ( V_41 ) {
V_5 -> V_15 = F_37 ( V_41 ) ;
F_38 ( V_41 ) ;
if ( ! V_5 -> V_15 )
return - V_43 ;
}
F_39 ( & V_5 -> V_4 ) ;
V_5 -> V_4 . V_44 = & V_45 ;
V_5 -> V_4 . V_13 = & V_5 -> V_11 -> V_13 ;
V_12 = F_40 ( & V_5 -> V_4 ) ;
if ( V_12 < 0 )
goto V_46;
return 0 ;
V_46:
if ( V_5 -> V_15 )
F_41 ( & V_5 -> V_15 -> V_13 ) ;
return V_12 ;
}
static void F_42 ( struct V_1 * V_5 )
{
if ( V_5 -> V_4 . V_13 )
F_43 ( & V_5 -> V_4 ) ;
if ( V_5 -> V_15 )
F_41 ( & V_5 -> V_15 -> V_13 ) ;
if ( V_5 -> V_30 )
F_41 ( & V_5 -> V_30 -> V_13 ) ;
}
static int F_44 ( struct V_9 * V_10 )
{
struct V_9 * V_47 = NULL ;
struct V_1 * V_5 ;
struct V_40 * V_41 ;
int V_12 ;
V_10 -> V_48 = 4 ;
V_10 -> V_27 = V_49 ;
V_10 -> V_50 = V_51 ;
V_41 = F_36 ( V_10 -> V_13 . V_42 , L_18 , 0 ) ;
if ( V_41 ) {
V_47 = F_45 ( V_41 ) ;
F_38 ( V_41 ) ;
if ( ! V_47 )
return - V_43 ;
}
if ( V_47 ) {
V_5 = F_46 ( & V_10 -> V_13 , sizeof( * V_5 ) , V_52 ) ;
if ( ! V_5 ) {
F_41 ( & V_47 -> V_13 ) ;
return - V_35 ;
}
F_47 ( V_10 , V_5 ) ;
V_5 -> V_30 = V_47 ;
V_5 -> V_11 = V_10 ;
V_12 = F_32 ( V_5 ) ;
if ( V_12 < 0 ) {
F_41 ( & V_47 -> V_13 ) ;
return V_12 ;
}
}
V_12 = F_48 ( V_10 ) ;
if ( V_12 < 0 ) {
if ( V_47 )
F_42 ( V_5 ) ;
return V_12 ;
}
return 0 ;
}
static int F_49 ( struct V_9 * V_10 )
{
struct V_1 * V_5 = F_50 ( V_10 ) ;
int V_12 ;
if ( ! V_5 ) {
F_51 ( V_10 ) ;
return 0 ;
}
V_12 = F_11 ( & V_5 -> V_4 ) ;
if ( V_12 < 0 )
F_5 ( & V_10 -> V_13 , L_19 , V_12 ) ;
V_12 = F_51 ( V_10 ) ;
if ( V_12 < 0 )
F_5 ( & V_10 -> V_13 , L_20 , V_12 ) ;
F_52 ( & V_5 -> V_4 ) ;
F_42 ( V_5 ) ;
return 0 ;
}
static void F_53 ( struct V_9 * V_10 )
{
struct V_1 * V_5 = F_50 ( V_10 ) ;
if ( ! V_5 )
return;
F_11 ( & V_5 -> V_4 ) ;
}
