static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_1 * V_5 , unsigned int V_6 )
{
unsigned int V_7 = F_4 ( V_5 -> V_8 ) ;
if ( F_5 ( V_6 > V_7 ) )
return;
F_6 ( 1000 / ( V_7 / V_6 ) ) ;
}
static int F_7 ( struct V_1 * V_5 , T_1 V_9 , T_2 V_10 )
{
T_2 V_11 [ 3 ] = { V_9 >> 8 , V_9 & 0xff , V_10 } ;
struct V_12 * V_13 = V_5 -> V_14 ;
T_3 V_15 ;
V_15 = F_8 ( V_13 , V_11 , sizeof( V_11 ) ) ;
if ( V_15 < 0 ) {
F_9 ( & V_13 -> V_16 , L_1 ,
V_10 , V_9 , V_15 ) ;
return V_15 ;
}
V_15 = F_10 ( V_13 ) ;
if ( V_15 < 0 ) {
F_9 ( & V_13 -> V_16 , L_2 , V_15 ) ;
return V_15 ;
}
F_11 ( 10 , 20 ) ;
return 0 ;
}
static T_4 int F_12 ( struct V_1 * V_5 ,
T_1 V_9 , T_2 * V_10 )
{
T_3 V_15 ;
F_13 ( & V_9 ) ;
V_15 = F_14 ( V_5 -> V_14 , & V_9 , sizeof( V_9 ) ,
V_10 , sizeof( * V_10 ) ) ;
if ( V_15 < 0 )
F_9 ( & V_5 -> V_14 -> V_16 , L_3 ,
V_9 , V_15 ) ;
return V_15 ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( ! V_5 -> V_17 )
return 0 ;
if ( V_5 -> V_18 ) {
V_5 -> V_18 -> V_19 . V_20 = V_21 ;
F_16 ( V_5 -> V_18 ) ;
}
V_5 -> V_17 = false ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_15 ;
if ( ! V_5 -> V_22 )
return 0 ;
F_3 ( V_5 , 4 ) ;
V_15 = F_18 ( V_5 -> V_14 ) ;
if ( V_15 < 0 )
F_9 ( V_3 -> V_16 , L_4 , V_15 ) ;
V_15 = F_19 ( V_5 -> V_14 ) ;
if ( V_15 < 0 )
F_9 ( V_3 -> V_16 , L_5 , V_15 ) ;
F_6 ( 120 ) ;
F_20 ( V_5 -> V_23 ) ;
V_5 -> V_22 = false ;
return 0 ;
}
static int F_21 ( struct V_12 * V_24 ,
struct V_12 * V_25 ,
const struct V_26 * V_8 )
{
int V_15 ;
V_15 = F_22 ( V_24 , 0 , V_8 -> V_27 / 2 - 1 ) ;
if ( V_15 < 0 ) {
F_9 ( & V_24 -> V_16 , L_6 , V_15 ) ;
return V_15 ;
}
V_15 = F_23 ( V_24 , 0 , V_8 -> V_28 - 1 ) ;
if ( V_15 < 0 ) {
F_9 ( & V_24 -> V_16 , L_7 , V_15 ) ;
return V_15 ;
}
V_15 = F_22 ( V_25 , V_8 -> V_27 / 2 ,
V_8 -> V_27 - 1 ) ;
if ( V_15 < 0 ) {
F_9 ( & V_25 -> V_16 , L_6 , V_15 ) ;
return V_15 ;
}
V_15 = F_23 ( V_25 , 0 , V_8 -> V_28 - 1 ) ;
if ( V_15 < 0 ) {
F_9 ( & V_25 -> V_16 , L_7 , V_15 ) ;
return V_15 ;
}
return 0 ;
}
static int F_24 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_2 V_29 = V_30 ;
int V_15 ;
if ( V_5 -> V_22 )
return 0 ;
V_15 = F_25 ( V_5 -> V_23 ) ;
if ( V_15 < 0 )
return V_15 ;
F_6 ( 150 ) ;
V_15 = F_26 ( V_5 -> V_14 ) ;
if ( V_15 < 0 ) {
F_9 ( V_3 -> V_16 , L_8 , V_15 ) ;
goto V_31;
}
V_15 = F_7 ( V_5 , 0x1000 , 0x2a ) ;
if ( V_15 < 0 ) {
F_9 ( V_3 -> V_16 , L_9 , V_15 ) ;
goto V_31;
}
V_15 = F_7 ( V_5 , 0x1001 , 0x01 ) ;
if ( V_15 < 0 ) {
F_9 ( V_3 -> V_16 , L_10 , V_15 ) ;
goto V_31;
}
V_15 = F_27 ( V_5 -> V_14 , V_29 ) ;
if ( V_15 < 0 ) {
F_9 ( V_3 -> V_16 , L_11 , V_15 ) ;
goto V_31;
}
V_15 = F_21 ( V_5 -> V_14 , V_5 -> V_32 ,
V_5 -> V_8 ) ;
if ( V_15 < 0 ) {
F_9 ( V_3 -> V_16 , L_12 ,
V_15 ) ;
goto V_31;
}
V_15 = F_28 ( V_5 -> V_14 ) ;
if ( V_15 < 0 ) {
F_9 ( V_3 -> V_16 , L_13 , V_15 ) ;
goto V_31;
}
V_5 -> V_22 = true ;
F_3 ( V_5 , 6 ) ;
return 0 ;
V_31:
F_20 ( V_5 -> V_23 ) ;
return V_15 ;
}
static int F_29 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_5 -> V_17 )
return 0 ;
if ( V_5 -> V_18 ) {
V_5 -> V_18 -> V_19 . V_20 = V_33 ;
F_16 ( V_5 -> V_18 ) ;
}
V_5 -> V_17 = true ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 )
{
struct V_26 * V_8 ;
V_8 = F_31 ( V_3 -> V_34 , & V_35 ) ;
if ( ! V_8 ) {
F_9 ( V_3 -> V_34 -> V_16 , L_14 ,
V_35 . V_27 , V_35 . V_28 ,
V_35 . V_36 ) ;
return - V_37 ;
}
F_32 ( V_8 ) ;
F_33 ( V_3 -> V_38 , V_8 ) ;
V_3 -> V_38 -> V_39 . V_40 = 217 ;
V_3 -> V_38 -> V_39 . V_41 = 136 ;
return 1 ;
}
static int F_34 ( struct V_1 * V_5 )
{
struct V_42 * V_43 ;
int V_15 ;
V_5 -> V_8 = & V_35 ;
V_5 -> V_23 = F_35 ( & V_5 -> V_14 -> V_16 , L_15 ) ;
if ( F_36 ( V_5 -> V_23 ) )
return F_37 ( V_5 -> V_23 ) ;
V_43 = F_38 ( V_5 -> V_14 -> V_16 . V_44 , L_16 , 0 ) ;
if ( V_43 ) {
V_5 -> V_18 = F_39 ( V_43 ) ;
F_40 ( V_43 ) ;
if ( ! V_5 -> V_18 )
return - V_45 ;
}
F_41 ( & V_5 -> V_4 ) ;
V_5 -> V_4 . V_46 = & V_47 ;
V_5 -> V_4 . V_16 = & V_5 -> V_14 -> V_16 ;
V_15 = F_42 ( & V_5 -> V_4 ) ;
if ( V_15 < 0 )
goto V_48;
return 0 ;
V_48:
if ( V_5 -> V_18 )
F_43 ( & V_5 -> V_18 -> V_16 ) ;
return V_15 ;
}
static void F_44 ( struct V_1 * V_5 )
{
if ( V_5 -> V_4 . V_16 )
F_45 ( & V_5 -> V_4 ) ;
if ( V_5 -> V_18 )
F_43 ( & V_5 -> V_18 -> V_16 ) ;
if ( V_5 -> V_32 )
F_43 ( & V_5 -> V_32 -> V_16 ) ;
}
static int F_46 ( struct V_12 * V_13 )
{
struct V_12 * V_49 = NULL ;
struct V_1 * V_5 ;
struct V_42 * V_43 ;
int V_15 ;
V_13 -> V_50 = 4 ;
V_13 -> V_29 = V_51 ;
V_13 -> V_52 = V_53 ;
V_43 = F_38 ( V_13 -> V_16 . V_44 , L_17 , 0 ) ;
if ( V_43 ) {
V_49 = F_47 ( V_43 ) ;
F_40 ( V_43 ) ;
if ( ! V_49 )
return - V_45 ;
}
if ( V_49 ) {
V_5 = F_48 ( & V_13 -> V_16 , sizeof( * V_5 ) , V_54 ) ;
if ( ! V_5 ) {
F_43 ( & V_49 -> V_16 ) ;
return - V_37 ;
}
F_49 ( V_13 , V_5 ) ;
V_5 -> V_32 = V_49 ;
V_5 -> V_14 = V_13 ;
V_15 = F_34 ( V_5 ) ;
if ( V_15 < 0 ) {
F_43 ( & V_49 -> V_16 ) ;
return V_15 ;
}
}
V_15 = F_50 ( V_13 ) ;
if ( V_15 < 0 ) {
if ( V_49 )
F_44 ( V_5 ) ;
return V_15 ;
}
return 0 ;
}
static int F_51 ( struct V_12 * V_13 )
{
struct V_1 * V_5 = F_52 ( V_13 ) ;
int V_15 ;
if ( ! V_5 ) {
F_53 ( V_13 ) ;
return 0 ;
}
V_15 = F_15 ( & V_5 -> V_4 ) ;
if ( V_15 < 0 )
F_9 ( & V_13 -> V_16 , L_18 , V_15 ) ;
V_15 = F_53 ( V_13 ) ;
if ( V_15 < 0 )
F_9 ( & V_13 -> V_16 , L_19 , V_15 ) ;
F_54 ( & V_5 -> V_4 ) ;
F_44 ( V_5 ) ;
return 0 ;
}
static void F_55 ( struct V_12 * V_13 )
{
struct V_1 * V_5 = F_52 ( V_13 ) ;
if ( ! V_5 )
return;
F_15 ( & V_5 -> V_4 ) ;
}
