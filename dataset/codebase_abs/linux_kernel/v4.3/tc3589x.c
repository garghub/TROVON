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
F_21 ( V_19 ) ;
return 0 ;
}
static void F_22 ( struct V_22 * V_23 , unsigned int V_19 )
{
F_19 ( V_19 , NULL , NULL ) ;
F_18 ( V_19 , NULL ) ;
}
static int F_23 ( struct V_1 * V_1 , struct V_28 * V_29 )
{
V_1 -> V_20 = F_24 (
V_29 , V_30 , 0 ,
& V_31 , V_1 ) ;
if ( ! V_1 -> V_20 ) {
F_3 ( V_1 -> V_5 , L_5 ) ;
return - V_32 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_1 )
{
int V_33 , V_34 , V_3 ;
V_33 = F_1 ( V_1 , V_35 ) ;
if ( V_33 < 0 )
return V_33 ;
V_34 = F_1 ( V_1 , V_36 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_33 != V_37 ) {
F_3 ( V_1 -> V_5 , L_6 , V_33 ) ;
return - V_38 ;
}
F_26 ( V_1 -> V_5 , L_7 , V_33 , V_34 ) ;
V_3 = F_4 ( V_1 , V_39 ,
V_40
| V_41
| V_42 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_4 ( V_1 , V_43 , 0x1 ) ;
}
static int F_27 ( struct V_1 * V_1 )
{
int V_3 = 0 ;
unsigned int V_44 = V_1 -> V_45 -> V_46 ;
if ( V_44 & V_47 ) {
V_3 = F_28 ( V_1 -> V_5 , - 1 , V_48 ,
F_29 ( V_48 ) , NULL ,
0 , V_1 -> V_20 ) ;
if ( V_3 ) {
F_3 ( V_1 -> V_5 , L_8 ) ;
return V_3 ;
}
F_26 ( V_1 -> V_5 , L_9 ) ;
}
if ( V_44 & V_49 ) {
V_3 = F_28 ( V_1 -> V_5 , - 1 , V_50 ,
F_29 ( V_50 ) , NULL ,
0 , V_1 -> V_20 ) ;
if ( V_3 ) {
F_3 ( V_1 -> V_5 , L_10 ) ;
return V_3 ;
}
F_26 ( V_1 -> V_5 , L_11 ) ;
}
return V_3 ;
}
static struct V_51 *
F_30 ( struct V_52 * V_5 , enum V_53 * V_54 )
{
struct V_28 * V_29 = V_5 -> V_55 ;
struct V_51 * V_45 ;
struct V_28 * V_56 ;
const struct V_57 * V_58 ;
V_45 = F_31 ( V_5 , sizeof( * V_45 ) , V_59 ) ;
if ( ! V_45 )
return F_32 ( - V_60 ) ;
V_58 = F_33 ( V_61 , V_5 ) ;
if ( ! V_58 )
return F_32 ( - V_62 ) ;
* V_54 = (enum V_53 ) V_58 -> V_6 ;
F_34 (np, child) {
if ( F_35 ( V_56 , L_12 ) )
V_45 -> V_46 |= V_47 ;
if ( F_35 ( V_56 , L_13 ) )
V_45 -> V_46 |= V_49 ;
}
return V_45 ;
}
static int F_36 ( struct V_63 * V_4 ,
const struct V_64 * V_65 )
{
struct V_28 * V_29 = V_4 -> V_5 . V_55 ;
struct V_51 * V_45 = F_37 ( & V_4 -> V_5 ) ;
struct V_1 * V_1 ;
enum V_53 V_54 ;
int V_3 ;
if ( ! V_45 ) {
V_45 = F_30 ( & V_4 -> V_5 , & V_54 ) ;
if ( F_38 ( V_45 ) ) {
F_3 ( & V_4 -> V_5 , L_14 ) ;
return F_39 ( V_45 ) ;
}
} else {
V_54 = V_65 -> V_66 ;
}
if ( ! F_40 ( V_4 -> V_67 , V_68
| V_69 ) )
return - V_70 ;
V_1 = F_31 ( & V_4 -> V_5 , sizeof( struct V_1 ) ,
V_59 ) ;
if ( ! V_1 )
return - V_60 ;
F_41 ( & V_1 -> V_11 ) ;
V_1 -> V_5 = & V_4 -> V_5 ;
V_1 -> V_4 = V_4 ;
V_1 -> V_45 = V_45 ;
switch ( V_54 ) {
case V_71 :
case V_72 :
case V_73 :
V_1 -> V_74 = 20 ;
break;
case V_75 :
case V_76 :
case V_77 :
case V_78 :
default:
V_1 -> V_74 = 24 ;
break;
}
F_42 ( V_4 , V_1 ) ;
V_3 = F_25 ( V_1 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_23 ( V_1 , V_29 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_43 ( V_1 -> V_4 -> V_13 , NULL , F_13 ,
V_79 | V_80 ,
L_15 , V_1 ) ;
if ( V_3 ) {
F_3 ( V_1 -> V_5 , L_16 , V_3 ) ;
return V_3 ;
}
V_3 = F_27 ( V_1 ) ;
if ( V_3 ) {
F_3 ( V_1 -> V_5 , L_17 ) ;
return V_3 ;
}
return 0 ;
}
static int F_44 ( struct V_63 * V_81 )
{
struct V_1 * V_1 = F_45 ( V_81 ) ;
F_46 ( V_1 -> V_5 ) ;
return 0 ;
}
static int F_47 ( struct V_52 * V_5 )
{
struct V_1 * V_1 = F_48 ( V_5 ) ;
struct V_63 * V_81 = V_1 -> V_4 ;
int V_3 = 0 ;
if ( ! F_49 ( & V_81 -> V_5 ) )
V_3 = F_4 ( V_1 , V_82 ,
V_83 ) ;
return V_3 ;
}
static int F_50 ( struct V_52 * V_5 )
{
struct V_1 * V_1 = F_48 ( V_5 ) ;
struct V_63 * V_81 = V_1 -> V_4 ;
int V_3 = 0 ;
if ( ! F_49 ( & V_81 -> V_5 ) )
V_3 = F_4 ( V_1 , V_82 ,
V_84 ) ;
return V_3 ;
}
static int T_4 F_51 ( void )
{
return F_52 ( & V_85 ) ;
}
static void T_5 F_53 ( void )
{
F_54 ( & V_85 ) ;
}
