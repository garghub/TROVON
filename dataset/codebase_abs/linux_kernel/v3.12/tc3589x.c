int F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
int V_3 ;
V_3 = F_2 ( V_1 -> V_4 , V_2 ) ;
if ( V_3 < 0 )
F_3 ( V_1 -> V_5 , L_1 ,
V_2 , V_3 ) ;
return V_3 ;
}
int F_4 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_6 )
{
int V_3 ;
V_3 = F_5 ( V_1 -> V_4 , V_2 , V_6 ) ;
if ( V_3 < 0 )
F_3 ( V_1 -> V_5 , L_2 ,
V_2 , V_3 ) ;
return V_3 ;
}
int F_6 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_7 , T_1 * V_8 )
{
int V_3 ;
V_3 = F_7 ( V_1 -> V_4 , V_2 , V_7 , V_8 ) ;
if ( V_3 < 0 )
F_3 ( V_1 -> V_5 , L_3 ,
V_2 , V_3 ) ;
return V_3 ;
}
int F_8 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_7 ,
const T_1 * V_8 )
{
int V_3 ;
V_3 = F_9 ( V_1 -> V_4 , V_2 , V_7 ,
V_8 ) ;
if ( V_3 < 0 )
F_3 ( V_1 -> V_5 , L_4 ,
V_2 , V_3 ) ;
return V_3 ;
}
int F_10 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_9 , T_1 V_10 )
{
int V_3 ;
F_11 ( & V_1 -> V_11 ) ;
V_3 = F_1 ( V_1 , V_2 ) ;
if ( V_3 < 0 )
goto V_12;
V_3 &= ~ V_9 ;
V_3 |= V_10 ;
V_3 = F_4 ( V_1 , V_2 , V_3 ) ;
V_12:
F_12 ( & V_1 -> V_11 ) ;
return V_3 ;
}
static T_2 F_13 ( int V_13 , void * V_6 )
{
struct V_1 * V_1 = V_6 ;
int V_14 ;
V_15:
V_14 = F_1 ( V_1 , V_16 ) ;
if ( V_14 < 0 )
return V_17 ;
while ( V_14 ) {
int V_18 = F_14 ( V_14 ) ;
int V_19 = F_15 ( V_1 -> V_20 , V_18 ) ;
F_16 ( V_19 ) ;
V_14 &= ~ ( 1 << V_18 ) ;
}
V_14 = F_1 ( V_1 , V_16 ) ;
if ( V_14 )
goto V_15;
return V_21 ;
}
static int F_17 ( struct V_22 * V_23 , unsigned int V_19 ,
T_3 V_24 )
{
struct V_1 * V_1 = V_23 -> V_25 ;
F_18 ( V_19 , V_1 ) ;
F_19 ( V_19 , & V_26 ,
V_27 ) ;
F_20 ( V_19 , 1 ) ;
#ifdef F_21
F_22 ( V_19 , V_28 ) ;
#else
F_23 ( V_19 ) ;
#endif
return 0 ;
}
static void F_24 ( struct V_22 * V_23 , unsigned int V_19 )
{
#ifdef F_21
F_22 ( V_19 , 0 ) ;
#endif
F_19 ( V_19 , NULL , NULL ) ;
F_18 ( V_19 , NULL ) ;
}
static int F_25 ( struct V_1 * V_1 , struct V_29 * V_30 )
{
int V_31 = V_1 -> V_32 ;
V_1 -> V_20 = F_26 (
V_30 , V_33 , V_31 ,
& V_34 , V_1 ) ;
if ( ! V_1 -> V_20 ) {
F_3 ( V_1 -> V_5 , L_5 ) ;
return - V_35 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_1 )
{
int V_36 , V_37 , V_3 ;
V_36 = F_1 ( V_1 , V_38 ) ;
if ( V_36 < 0 )
return V_36 ;
V_37 = F_1 ( V_1 , V_39 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_36 != V_40 ) {
F_3 ( V_1 -> V_5 , L_6 , V_36 ) ;
return - V_41 ;
}
F_28 ( V_1 -> V_5 , L_7 , V_36 , V_37 ) ;
V_3 = F_4 ( V_1 , V_42 ,
V_43
| V_44
| V_45 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_4 ( V_1 , V_46 , 0x1 ) ;
}
static int F_29 ( struct V_1 * V_1 )
{
int V_3 = 0 ;
unsigned int V_47 = V_1 -> V_48 -> V_49 ;
if ( V_47 & V_50 ) {
V_3 = F_30 ( V_1 -> V_5 , - 1 , V_51 ,
F_31 ( V_51 ) , NULL ,
V_1 -> V_32 , V_1 -> V_20 ) ;
if ( V_3 ) {
F_3 ( V_1 -> V_5 , L_8 ) ;
return V_3 ;
}
F_28 ( V_1 -> V_5 , L_9 ) ;
}
if ( V_47 & V_52 ) {
V_3 = F_30 ( V_1 -> V_5 , - 1 , V_53 ,
F_31 ( V_53 ) , NULL ,
V_1 -> V_32 , V_1 -> V_20 ) ;
if ( V_3 ) {
F_3 ( V_1 -> V_5 , L_10 ) ;
return V_3 ;
}
F_28 ( V_1 -> V_5 , L_11 ) ;
}
return V_3 ;
}
static int F_32 ( struct V_29 * V_30 ,
struct V_54 * V_48 )
{
struct V_29 * V_55 ;
F_33 (np, child) {
if ( ! strcmp ( V_55 -> V_56 , L_12 ) ) {
V_48 -> V_49 |= V_50 ;
}
if ( ! strcmp ( V_55 -> V_56 , L_13 ) ) {
V_48 -> V_49 |= V_52 ;
}
}
return 0 ;
}
static int F_34 ( struct V_57 * V_4 ,
const struct V_58 * V_59 )
{
struct V_54 * V_48 = F_35 ( & V_4 -> V_5 ) ;
struct V_29 * V_30 = V_4 -> V_5 . V_60 ;
struct V_1 * V_1 ;
int V_3 ;
if ( ! V_48 ) {
if ( V_30 ) {
V_48 = F_36 ( & V_4 -> V_5 , sizeof( * V_48 ) , V_61 ) ;
if ( ! V_48 )
return - V_62 ;
V_3 = F_32 ( V_30 , V_48 ) ;
if ( V_3 )
return V_3 ;
}
else {
F_3 ( & V_4 -> V_5 , L_14 ) ;
return - V_41 ;
}
}
if ( ! F_37 ( V_4 -> V_63 , V_64
| V_65 ) )
return - V_66 ;
V_1 = F_36 ( & V_4 -> V_5 , sizeof( struct V_1 ) ,
V_61 ) ;
if ( ! V_1 )
return - V_62 ;
F_38 ( & V_1 -> V_11 ) ;
V_1 -> V_5 = & V_4 -> V_5 ;
V_1 -> V_4 = V_4 ;
V_1 -> V_48 = V_48 ;
V_1 -> V_32 = V_48 -> V_32 ;
V_1 -> V_67 = V_59 -> V_68 ;
F_39 ( V_4 , V_1 ) ;
V_3 = F_27 ( V_1 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_25 ( V_1 , V_30 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_40 ( V_1 -> V_4 -> V_13 , NULL , F_13 ,
V_69 | V_70 ,
L_15 , V_1 ) ;
if ( V_3 ) {
F_3 ( V_1 -> V_5 , L_16 , V_3 ) ;
return V_3 ;
}
V_3 = F_29 ( V_1 ) ;
if ( V_3 ) {
F_3 ( V_1 -> V_5 , L_17 ) ;
return V_3 ;
}
return 0 ;
}
static int F_41 ( struct V_57 * V_71 )
{
struct V_1 * V_1 = F_42 ( V_71 ) ;
F_43 ( V_1 -> V_5 ) ;
return 0 ;
}
static int F_44 ( struct V_72 * V_5 )
{
struct V_1 * V_1 = F_45 ( V_5 ) ;
struct V_57 * V_71 = V_1 -> V_4 ;
int V_3 = 0 ;
if ( ! F_46 ( & V_71 -> V_5 ) )
V_3 = F_4 ( V_1 , V_73 ,
V_74 ) ;
return V_3 ;
}
static int F_47 ( struct V_72 * V_5 )
{
struct V_1 * V_1 = F_45 ( V_5 ) ;
struct V_57 * V_71 = V_1 -> V_4 ;
int V_3 = 0 ;
if ( ! F_46 ( & V_71 -> V_5 ) )
V_3 = F_4 ( V_1 , V_73 ,
V_75 ) ;
return V_3 ;
}
static int T_4 F_48 ( void )
{
return F_49 ( & V_76 ) ;
}
static void T_5 F_50 ( void )
{
F_51 ( & V_76 ) ;
}
