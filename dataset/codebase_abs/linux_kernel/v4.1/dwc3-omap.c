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
F_3 ( V_5 -> V_1 , V_8 -
V_5 -> V_9 , V_3 ) ;
}
static T_1 F_9 ( struct V_4 * V_5 )
{
return F_1 ( V_5 -> V_1 , V_10 +
V_5 -> V_11 ) ;
}
static void F_10 ( struct V_4 * V_5 , T_1 V_3 )
{
F_3 ( V_5 -> V_1 , V_10 +
V_5 -> V_11 , V_3 ) ;
}
static void F_11 ( struct V_4 * V_5 , T_1 V_3 )
{
F_3 ( V_5 -> V_1 , V_12 +
V_5 -> V_11 , V_3 ) ;
}
static void F_12 ( struct V_4 * V_5 , T_1 V_3 )
{
F_3 ( V_5 -> V_1 , V_13 -
V_5 -> V_9 , V_3 ) ;
}
static void F_13 ( struct V_4 * V_5 , T_1 V_3 )
{
F_3 ( V_5 -> V_1 , V_14 +
V_5 -> V_11 , V_3 ) ;
}
static void F_14 ( struct V_4 * V_5 , T_1 V_3 )
{
F_3 ( V_5 -> V_1 , V_15 -
V_5 -> V_9 , V_3 ) ;
}
static void F_15 ( struct V_4 * V_5 ,
enum V_16 V_17 )
{
int V_18 ;
T_1 V_19 ;
switch ( V_17 ) {
case V_20 :
F_16 ( V_5 -> V_21 , L_1 ) ;
if ( V_5 -> V_22 ) {
V_18 = F_17 ( V_5 -> V_22 ) ;
if ( V_18 ) {
F_16 ( V_5 -> V_21 , L_2 ) ;
return;
}
}
V_19 = F_5 ( V_5 ) ;
V_19 &= ~ ( V_23
| V_24
| V_25 ) ;
V_19 |= V_26
| V_27 ;
F_6 ( V_5 , V_19 ) ;
break;
case V_28 :
F_16 ( V_5 -> V_21 , L_3 ) ;
V_19 = F_5 ( V_5 ) ;
V_19 &= ~ V_25 ;
V_19 |= V_23
| V_24
| V_26
| V_27 ;
F_6 ( V_5 , V_19 ) ;
break;
case V_29 :
if ( V_5 -> V_22 )
F_18 ( V_5 -> V_22 ) ;
case V_30 :
F_16 ( V_5 -> V_21 , L_4 ) ;
V_19 = F_5 ( V_5 ) ;
V_19 &= ~ ( V_26
| V_24
| V_27 ) ;
V_19 |= V_25
| V_23 ;
F_6 ( V_5 , V_19 ) ;
break;
default:
F_16 ( V_5 -> V_21 , L_5 ) ;
}
}
static T_3 F_19 ( int V_31 , void * V_32 )
{
struct V_4 * V_5 = V_32 ;
T_1 V_33 ;
V_33 = F_9 ( V_5 ) ;
if ( V_33 & V_34 ) {
F_16 ( V_5 -> V_21 , L_6 ) ;
V_5 -> V_35 = false ;
}
if ( V_33 & V_36 )
F_16 ( V_5 -> V_21 , L_7 ) ;
if ( V_33 & V_37 )
F_16 ( V_5 -> V_21 , L_8 ) ;
if ( V_33 & V_38 )
F_16 ( V_5 -> V_21 , L_9 ) ;
if ( V_33 & V_39 )
F_16 ( V_5 -> V_21 , L_10 ) ;
if ( V_33 & V_40 )
F_16 ( V_5 -> V_21 , L_11 ) ;
if ( V_33 & V_41 )
F_16 ( V_5 -> V_21 , L_12 ) ;
if ( V_33 & V_42 )
F_16 ( V_5 -> V_21 , L_13 ) ;
if ( V_33 & V_43 )
F_16 ( V_5 -> V_21 , L_14 ) ;
if ( V_33 & V_44 )
F_16 ( V_5 -> V_21 , L_15 ) ;
F_10 ( V_5 , V_33 ) ;
V_33 = F_7 ( V_5 ) ;
F_8 ( V_5 , V_33 ) ;
return V_45 ;
}
static void F_20 ( struct V_4 * V_5 )
{
T_1 V_33 ;
V_33 = V_46 ;
F_12 ( V_5 , V_33 ) ;
V_33 = ( V_36 |
V_37 |
V_38 |
V_39 |
V_40 |
V_41 |
V_42 |
V_43 |
V_44 ) ;
F_11 ( V_5 , V_33 ) ;
}
static void F_21 ( struct V_4 * V_5 )
{
T_1 V_33 ;
V_33 = V_46 ;
F_14 ( V_5 , V_33 ) ;
V_33 = ( V_36 |
V_37 |
V_38 |
V_39 |
V_40 |
V_41 |
V_42 |
V_43 |
V_44 ) ;
F_13 ( V_5 , V_33 ) ;
}
static int F_22 ( struct V_47 * V_48 ,
unsigned long V_49 , void * V_50 )
{
struct V_4 * V_5 = F_23 ( V_48 , struct V_4 , V_51 ) ;
if ( V_49 )
F_15 ( V_5 , V_20 ) ;
else
F_15 ( V_5 , V_29 ) ;
return V_52 ;
}
static int F_24 ( struct V_47 * V_48 ,
unsigned long V_49 , void * V_50 )
{
struct V_4 * V_5 = F_23 ( V_48 , struct V_4 , V_53 ) ;
if ( V_49 )
F_15 ( V_5 , V_28 ) ;
else
F_15 ( V_5 , V_30 ) ;
return V_52 ;
}
static void F_25 ( struct V_4 * V_5 )
{
struct V_54 * V_55 = V_5 -> V_21 -> V_56 ;
if ( F_26 ( V_55 , L_16 ) ) {
V_5 -> V_57 = V_58 ;
V_5 -> V_9 = V_59 ;
V_5 -> V_11 = V_60 ;
V_5 -> V_7 = V_61 ;
V_5 -> V_62 = V_63 ;
}
}
static void F_27 ( struct V_4 * V_5 )
{
T_1 V_33 ;
struct V_54 * V_55 = V_5 -> V_21 -> V_56 ;
int V_64 = 0 ;
V_33 = F_5 ( V_5 ) ;
F_28 ( V_55 , L_17 , & V_64 ) ;
switch ( V_64 ) {
case V_65 :
V_33 |= V_66 ;
break;
case V_67 :
V_33 &= ~ V_66 ;
break;
default:
F_16 ( V_5 -> V_21 , L_18 , V_64 ) ;
}
F_6 ( V_5 , V_33 ) ;
}
static int F_29 ( struct V_4 * V_5 )
{
int V_18 ;
struct V_54 * V_55 = V_5 -> V_21 -> V_56 ;
struct V_68 * V_69 ;
if ( F_30 ( V_55 , L_19 ) ) {
V_69 = F_31 ( V_5 -> V_21 , 0 ) ;
if ( F_32 ( V_69 ) ) {
F_33 ( V_5 -> V_21 , L_20 ) ;
return - V_70 ;
}
V_5 -> V_53 . V_71 = F_24 ;
V_18 = F_34 ( & V_5 -> V_72 ,
V_69 -> V_73 , L_21 ,
& V_5 -> V_53 ) ;
if ( V_18 < 0 )
F_33 ( V_5 -> V_21 , L_22 ) ;
V_5 -> V_51 . V_71 = F_22 ;
V_18 = F_34 ( & V_5 -> V_74 ,
V_69 -> V_73 , L_23 ,
& V_5 -> V_51 ) ;
if ( V_18 < 0 )
F_33 ( V_5 -> V_21 , L_24 ) ;
if ( F_35 ( V_69 , L_21 ) == true )
F_15 ( V_5 , V_28 ) ;
if ( F_35 ( V_69 , L_23 ) == true )
F_15 ( V_5 , V_20 ) ;
}
return 0 ;
}
static int F_36 ( struct V_75 * V_76 )
{
struct V_54 * V_55 = V_76 -> V_21 . V_56 ;
struct V_4 * V_5 ;
struct V_77 * V_78 ;
struct V_79 * V_21 = & V_76 -> V_21 ;
struct V_80 * V_22 = NULL ;
int V_18 ;
int V_31 ;
T_1 V_33 ;
void T_2 * V_1 ;
if ( ! V_55 ) {
F_37 ( V_21 , L_25 ) ;
return - V_81 ;
}
V_5 = F_38 ( V_21 , sizeof( * V_5 ) , V_82 ) ;
if ( ! V_5 )
return - V_83 ;
F_39 ( V_76 , V_5 ) ;
V_31 = F_40 ( V_76 , 0 ) ;
if ( V_31 < 0 ) {
F_37 ( V_21 , L_26 ) ;
return - V_81 ;
}
V_78 = F_41 ( V_76 , V_84 , 0 ) ;
V_1 = F_42 ( V_21 , V_78 ) ;
if ( F_32 ( V_1 ) )
return F_43 ( V_1 ) ;
if ( F_30 ( V_55 , L_27 ) ) {
V_22 = F_44 ( V_21 , L_28 ) ;
if ( F_32 ( V_22 ) ) {
F_37 ( V_21 , L_29 ) ;
return F_43 ( V_22 ) ;
}
}
V_5 -> V_21 = V_21 ;
V_5 -> V_31 = V_31 ;
V_5 -> V_1 = V_1 ;
V_5 -> V_22 = V_22 ;
V_21 -> V_85 = & V_86 ;
F_45 ( V_21 ) ;
V_18 = F_46 ( V_21 ) ;
if ( V_18 < 0 ) {
F_37 ( V_21 , L_30 , V_18 ) ;
goto V_87;
}
F_25 ( V_5 ) ;
F_27 ( V_5 ) ;
V_33 = F_1 ( V_5 -> V_1 , V_88 ) ;
V_5 -> V_35 = ! ! ( V_33 & V_89 ) ;
V_18 = F_47 ( V_21 , V_5 -> V_31 , F_19 , 0 ,
L_31 , V_5 ) ;
if ( V_18 ) {
F_37 ( V_21 , L_32 ,
V_5 -> V_31 , V_18 ) ;
goto V_90;
}
F_20 ( V_5 ) ;
V_18 = F_29 ( V_5 ) ;
if ( V_18 < 0 )
goto V_91;
V_18 = F_48 ( V_55 , NULL , NULL , V_21 ) ;
if ( V_18 ) {
F_37 ( & V_76 -> V_21 , L_33 ) ;
goto V_92;
}
return 0 ;
V_92:
if ( V_5 -> V_72 . V_69 )
F_49 ( & V_5 -> V_72 ) ;
if ( V_5 -> V_74 . V_69 )
F_49 ( & V_5 -> V_74 ) ;
V_91:
F_21 ( V_5 ) ;
V_90:
F_50 ( V_21 ) ;
V_87:
F_51 ( V_21 ) ;
return V_18 ;
}
static int F_52 ( struct V_75 * V_76 )
{
struct V_4 * V_5 = F_53 ( V_76 ) ;
if ( V_5 -> V_72 . V_69 )
F_49 ( & V_5 -> V_72 ) ;
if ( V_5 -> V_74 . V_69 )
F_49 ( & V_5 -> V_74 ) ;
F_21 ( V_5 ) ;
F_54 ( V_5 -> V_21 ) ;
F_50 ( & V_76 -> V_21 ) ;
F_51 ( & V_76 -> V_21 ) ;
return 0 ;
}
static int F_55 ( struct V_79 * V_21 )
{
struct V_4 * V_5 = F_56 ( V_21 ) ;
V_5 -> V_93 = F_5 ( V_5 ) ;
F_21 ( V_5 ) ;
return 0 ;
}
static int F_57 ( struct V_79 * V_21 )
{
struct V_4 * V_5 = F_56 ( V_21 ) ;
F_6 ( V_5 , V_5 -> V_93 ) ;
F_20 ( V_5 ) ;
F_51 ( V_21 ) ;
F_58 ( V_21 ) ;
F_45 ( V_21 ) ;
return 0 ;
}
