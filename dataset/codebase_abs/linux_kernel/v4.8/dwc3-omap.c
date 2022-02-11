static inline T_1 F_1 ( void T_2 * V_1 , T_1 V_2 )
{
return F_2 ( V_1 + V_2 ) ;
}
static inline void F_3 ( void T_2 * V_1 , T_1 V_2 , T_1 V_3 )
{
F_4 ( V_3 , V_1 + V_2 ) ;
}
static T_1 F_5 ( struct V_4 * V_5 )
{
return F_1 ( V_5 -> V_1 , V_6 +
V_5 -> V_7 ) ;
}
static void F_6 ( struct V_4 * V_5 , T_1 V_3 )
{
F_3 ( V_5 -> V_1 , V_6 +
V_5 -> V_7 , V_3 ) ;
}
static T_1 F_7 ( struct V_4 * V_5 )
{
return F_1 ( V_5 -> V_1 , V_8 -
V_5 -> V_9 ) ;
}
static void F_8 ( struct V_4 * V_5 , T_1 V_3 )
{
F_3 ( V_5 -> V_1 , V_10 -
V_5 -> V_9 , V_3 ) ;
}
static T_1 F_9 ( struct V_4 * V_5 )
{
return F_1 ( V_5 -> V_1 , V_11 +
V_5 -> V_12 ) ;
}
static void F_10 ( struct V_4 * V_5 , T_1 V_3 )
{
F_3 ( V_5 -> V_1 , V_13 +
V_5 -> V_12 , V_3 ) ;
}
static void F_11 ( struct V_4 * V_5 , T_1 V_3 )
{
F_3 ( V_5 -> V_1 , V_14 +
V_5 -> V_12 , V_3 ) ;
}
static void F_12 ( struct V_4 * V_5 , T_1 V_3 )
{
F_3 ( V_5 -> V_1 , V_15 -
V_5 -> V_9 , V_3 ) ;
}
static void F_13 ( struct V_4 * V_5 , T_1 V_3 )
{
F_3 ( V_5 -> V_1 , V_16 +
V_5 -> V_12 , V_3 ) ;
}
static void F_14 ( struct V_4 * V_5 , T_1 V_3 )
{
F_3 ( V_5 -> V_1 , V_17 -
V_5 -> V_9 , V_3 ) ;
}
static void F_15 ( struct V_4 * V_5 ,
enum V_18 V_19 )
{
int V_20 ;
T_1 V_21 ;
switch ( V_19 ) {
case V_22 :
if ( V_5 -> V_23 ) {
V_20 = F_16 ( V_5 -> V_23 ) ;
if ( V_20 ) {
F_17 ( V_5 -> V_24 , L_1 ) ;
return;
}
}
V_21 = F_5 ( V_5 ) ;
V_21 &= ~ V_25 ;
F_6 ( V_5 , V_21 ) ;
break;
case V_26 :
V_21 = F_5 ( V_5 ) ;
V_21 &= ~ V_27 ;
V_21 |= V_28
| V_29 ;
F_6 ( V_5 , V_21 ) ;
break;
case V_30 :
if ( V_5 -> V_23 )
F_18 ( V_5 -> V_23 ) ;
V_21 = F_5 ( V_5 ) ;
V_21 |= V_25 ;
F_6 ( V_5 , V_21 ) ;
case V_31 :
V_21 = F_5 ( V_5 ) ;
V_21 &= ~ ( V_29
| V_28 ) ;
V_21 |= V_27 ;
F_6 ( V_5 , V_21 ) ;
break;
default:
F_19 ( V_5 -> V_24 , L_2 ) ;
}
}
static T_3 F_20 ( int V_32 , void * V_33 )
{
struct V_4 * V_5 = V_33 ;
if ( F_9 ( V_5 ) ||
F_7 ( V_5 ) ) {
F_21 ( V_5 ) ;
return V_34 ;
}
return V_35 ;
}
static T_3 F_22 ( int V_32 , void * V_33 )
{
struct V_4 * V_5 = V_33 ;
T_1 V_36 ;
V_36 = F_9 ( V_5 ) ;
F_10 ( V_5 , V_36 ) ;
V_36 = F_7 ( V_5 ) ;
F_8 ( V_5 , V_36 ) ;
F_23 ( V_5 ) ;
return V_37 ;
}
static void F_23 ( struct V_4 * V_5 )
{
T_1 V_36 ;
V_36 = V_38 ;
F_12 ( V_5 , V_36 ) ;
V_36 = ( V_39 |
V_40 |
V_41 |
V_42 |
V_43 |
V_44 |
V_45 |
V_46 |
V_47 ) ;
F_11 ( V_5 , V_36 ) ;
}
static void F_21 ( struct V_4 * V_5 )
{
T_1 V_36 ;
V_36 = V_38 ;
F_14 ( V_5 , V_36 ) ;
V_36 = ( V_39 |
V_40 |
V_41 |
V_42 |
V_43 |
V_44 |
V_45 |
V_46 |
V_47 ) ;
F_13 ( V_5 , V_36 ) ;
}
static int F_24 ( struct V_48 * V_49 ,
unsigned long V_50 , void * V_51 )
{
struct V_4 * V_5 = F_25 ( V_49 , struct V_4 , V_52 ) ;
if ( V_50 )
F_15 ( V_5 , V_22 ) ;
else
F_15 ( V_5 , V_30 ) ;
return V_53 ;
}
static int F_26 ( struct V_48 * V_49 ,
unsigned long V_50 , void * V_51 )
{
struct V_4 * V_5 = F_25 ( V_49 , struct V_4 , V_54 ) ;
if ( V_50 )
F_15 ( V_5 , V_26 ) ;
else
F_15 ( V_5 , V_31 ) ;
return V_53 ;
}
static void F_27 ( struct V_4 * V_5 )
{
struct V_55 * V_56 = V_5 -> V_24 -> V_57 ;
if ( F_28 ( V_56 , L_3 ) ) {
V_5 -> V_58 = V_59 ;
V_5 -> V_9 = V_60 ;
V_5 -> V_12 = V_61 ;
V_5 -> V_7 = V_62 ;
V_5 -> V_63 = V_64 ;
}
}
static void F_29 ( struct V_4 * V_5 )
{
T_1 V_36 ;
struct V_55 * V_56 = V_5 -> V_24 -> V_57 ;
int V_65 = 0 ;
V_36 = F_5 ( V_5 ) ;
F_30 ( V_56 , L_4 , & V_65 ) ;
switch ( V_65 ) {
case V_66 :
V_36 |= V_67 ;
break;
case V_68 :
V_36 &= ~ V_67 ;
break;
default:
F_19 ( V_5 -> V_24 , L_5 , V_65 ) ;
}
F_6 ( V_5 , V_36 ) ;
}
static int F_31 ( struct V_4 * V_5 )
{
int V_20 ;
struct V_55 * V_56 = V_5 -> V_24 -> V_57 ;
struct V_69 * V_70 ;
if ( F_32 ( V_56 , L_6 ) ) {
V_70 = F_33 ( V_5 -> V_24 , 0 ) ;
if ( F_34 ( V_70 ) ) {
F_35 ( V_5 -> V_24 , L_7 ) ;
return - V_71 ;
}
V_5 -> V_54 . V_72 = F_26 ;
V_20 = F_36 ( V_70 , V_73 ,
& V_5 -> V_54 ) ;
if ( V_20 < 0 )
F_35 ( V_5 -> V_24 , L_8 ) ;
V_5 -> V_52 . V_72 = F_24 ;
V_20 = F_36 ( V_70 , V_74 ,
& V_5 -> V_52 ) ;
if ( V_20 < 0 )
F_35 ( V_5 -> V_24 , L_9 ) ;
if ( F_37 ( V_70 , V_73 ) == true )
F_15 ( V_5 , V_26 ) ;
if ( F_37 ( V_70 , V_74 ) == true )
F_15 ( V_5 , V_22 ) ;
V_5 -> V_70 = V_70 ;
}
return 0 ;
}
static int F_38 ( struct V_75 * V_76 )
{
struct V_55 * V_56 = V_76 -> V_24 . V_57 ;
struct V_4 * V_5 ;
struct V_77 * V_78 ;
struct V_79 * V_24 = & V_76 -> V_24 ;
struct V_80 * V_23 = NULL ;
int V_20 ;
int V_32 ;
T_1 V_36 ;
void T_2 * V_1 ;
if ( ! V_56 ) {
F_17 ( V_24 , L_10 ) ;
return - V_81 ;
}
V_5 = F_39 ( V_24 , sizeof( * V_5 ) , V_82 ) ;
if ( ! V_5 )
return - V_83 ;
F_40 ( V_76 , V_5 ) ;
V_32 = F_41 ( V_76 , 0 ) ;
if ( V_32 < 0 ) {
F_17 ( V_24 , L_11 ) ;
return - V_81 ;
}
V_78 = F_42 ( V_76 , V_84 , 0 ) ;
V_1 = F_43 ( V_24 , V_78 ) ;
if ( F_34 ( V_1 ) )
return F_44 ( V_1 ) ;
if ( F_32 ( V_56 , L_12 ) ) {
V_23 = F_45 ( V_24 , L_13 ) ;
if ( F_34 ( V_23 ) ) {
F_17 ( V_24 , L_14 ) ;
return F_44 ( V_23 ) ;
}
}
V_5 -> V_24 = V_24 ;
V_5 -> V_32 = V_32 ;
V_5 -> V_1 = V_1 ;
V_5 -> V_23 = V_23 ;
F_46 ( V_24 ) ;
V_20 = F_47 ( V_24 ) ;
if ( V_20 < 0 ) {
F_17 ( V_24 , L_15 , V_20 ) ;
goto V_85;
}
F_27 ( V_5 ) ;
F_29 ( V_5 ) ;
V_36 = F_1 ( V_5 -> V_1 , V_86 ) ;
V_20 = F_48 ( V_24 , V_5 -> V_32 , F_20 ,
F_22 , V_87 ,
L_16 , V_5 ) ;
if ( V_20 ) {
F_17 ( V_24 , L_17 ,
V_5 -> V_32 , V_20 ) ;
goto V_85;
}
V_20 = F_31 ( V_5 ) ;
if ( V_20 < 0 )
goto V_85;
V_20 = F_49 ( V_56 , NULL , NULL , V_24 ) ;
if ( V_20 ) {
F_17 ( & V_76 -> V_24 , L_18 ) ;
goto V_88;
}
F_23 ( V_5 ) ;
return 0 ;
V_88:
F_50 ( V_5 -> V_70 , V_73 , & V_5 -> V_54 ) ;
F_50 ( V_5 -> V_70 , V_74 , & V_5 -> V_52 ) ;
V_85:
F_51 ( V_24 ) ;
F_52 ( V_24 ) ;
return V_20 ;
}
static int F_53 ( struct V_75 * V_76 )
{
struct V_4 * V_5 = F_54 ( V_76 ) ;
F_50 ( V_5 -> V_70 , V_73 , & V_5 -> V_54 ) ;
F_50 ( V_5 -> V_70 , V_74 , & V_5 -> V_52 ) ;
F_21 ( V_5 ) ;
F_55 ( V_5 -> V_24 ) ;
F_51 ( & V_76 -> V_24 ) ;
F_52 ( & V_76 -> V_24 ) ;
return 0 ;
}
static int F_56 ( struct V_79 * V_24 )
{
struct V_4 * V_5 = F_57 ( V_24 ) ;
V_5 -> V_89 = F_5 ( V_5 ) ;
F_21 ( V_5 ) ;
return 0 ;
}
static int F_58 ( struct V_79 * V_24 )
{
struct V_4 * V_5 = F_57 ( V_24 ) ;
F_6 ( V_5 , V_5 -> V_89 ) ;
F_23 ( V_5 ) ;
F_52 ( V_24 ) ;
F_59 ( V_24 ) ;
F_46 ( V_24 ) ;
return 0 ;
}
