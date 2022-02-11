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
static void F_13 ( struct V_4 * V_5 ,
enum V_14 V_15 )
{
int V_16 ;
T_1 V_17 ;
switch ( V_15 ) {
case V_18 :
F_14 ( V_5 -> V_19 , L_1 ) ;
if ( V_5 -> V_20 ) {
V_16 = F_15 ( V_5 -> V_20 ) ;
if ( V_16 ) {
F_14 ( V_5 -> V_19 , L_2 ) ;
return;
}
}
V_17 = F_5 ( V_5 ) ;
V_17 &= ~ ( V_21
| V_22
| V_23 ) ;
V_17 |= V_24
| V_25 ;
F_6 ( V_5 , V_17 ) ;
break;
case V_26 :
F_14 ( V_5 -> V_19 , L_3 ) ;
V_17 = F_5 ( V_5 ) ;
V_17 &= ~ V_23 ;
V_17 |= V_21
| V_22
| V_24
| V_25 ;
F_6 ( V_5 , V_17 ) ;
break;
case V_27 :
if ( V_5 -> V_20 )
F_16 ( V_5 -> V_20 ) ;
case V_28 :
F_14 ( V_5 -> V_19 , L_4 ) ;
V_17 = F_5 ( V_5 ) ;
V_17 &= ~ ( V_24
| V_22
| V_25 ) ;
V_17 |= V_23
| V_21 ;
F_6 ( V_5 , V_17 ) ;
break;
default:
F_14 ( V_5 -> V_19 , L_5 ) ;
}
}
static T_3 F_17 ( int V_29 , void * V_30 )
{
struct V_4 * V_5 = V_30 ;
T_1 V_31 ;
V_31 = F_9 ( V_5 ) ;
if ( V_31 & V_32 ) {
F_14 ( V_5 -> V_19 , L_6 ) ;
V_5 -> V_33 = false ;
}
if ( V_31 & V_34 )
F_14 ( V_5 -> V_19 , L_7 ) ;
if ( V_31 & V_35 )
F_14 ( V_5 -> V_19 , L_8 ) ;
if ( V_31 & V_36 )
F_14 ( V_5 -> V_19 , L_9 ) ;
if ( V_31 & V_37 )
F_14 ( V_5 -> V_19 , L_10 ) ;
if ( V_31 & V_38 )
F_14 ( V_5 -> V_19 , L_11 ) ;
if ( V_31 & V_39 )
F_14 ( V_5 -> V_19 , L_12 ) ;
if ( V_31 & V_40 )
F_14 ( V_5 -> V_19 , L_13 ) ;
if ( V_31 & V_41 )
F_14 ( V_5 -> V_19 , L_14 ) ;
if ( V_31 & V_42 )
F_14 ( V_5 -> V_19 , L_15 ) ;
F_10 ( V_5 , V_31 ) ;
V_31 = F_7 ( V_5 ) ;
F_8 ( V_5 , V_31 ) ;
return V_43 ;
}
static int F_18 ( struct V_44 * V_19 , void * V_45 )
{
struct V_46 * V_47 = F_19 ( V_19 ) ;
F_20 ( V_47 ) ;
return 0 ;
}
static void F_21 ( struct V_4 * V_5 )
{
T_1 V_31 ;
V_31 = V_48 ;
F_12 ( V_5 , V_31 ) ;
V_31 = ( V_34 |
V_35 |
V_36 |
V_37 |
V_38 |
V_39 |
V_40 |
V_41 |
V_42 ) ;
F_11 ( V_5 , V_31 ) ;
}
static void F_22 ( struct V_4 * V_5 )
{
F_11 ( V_5 , 0x00 ) ;
F_12 ( V_5 , 0x00 ) ;
}
static int F_23 ( struct V_49 * V_50 ,
unsigned long V_51 , void * V_52 )
{
struct V_4 * V_5 = F_24 ( V_50 , struct V_4 , V_53 ) ;
if ( V_51 )
F_13 ( V_5 , V_18 ) ;
else
F_13 ( V_5 , V_27 ) ;
return V_54 ;
}
static int F_25 ( struct V_49 * V_50 ,
unsigned long V_51 , void * V_52 )
{
struct V_4 * V_5 = F_24 ( V_50 , struct V_4 , V_55 ) ;
if ( V_51 )
F_13 ( V_5 , V_26 ) ;
else
F_13 ( V_5 , V_28 ) ;
return V_54 ;
}
static int F_26 ( struct V_46 * V_47 )
{
struct V_56 * V_57 = V_47 -> V_19 . V_58 ;
struct V_4 * V_5 ;
struct V_59 * V_60 ;
struct V_44 * V_19 = & V_47 -> V_19 ;
struct V_61 * V_62 ;
struct V_63 * V_20 = NULL ;
int V_16 = - V_64 ;
int V_29 ;
int V_65 = 0 ;
int V_66 ;
T_1 V_31 ;
void T_2 * V_1 ;
if ( ! V_57 ) {
F_27 ( V_19 , L_16 ) ;
return - V_67 ;
}
V_5 = F_28 ( V_19 , sizeof( * V_5 ) , V_68 ) ;
if ( ! V_5 ) {
F_27 ( V_19 , L_17 ) ;
return - V_64 ;
}
F_29 ( V_47 , V_5 ) ;
V_29 = F_30 ( V_47 , 0 ) ;
if ( V_29 < 0 ) {
F_27 ( V_19 , L_18 ) ;
return - V_67 ;
}
V_60 = F_31 ( V_47 , V_69 , 0 ) ;
if ( ! V_60 ) {
F_27 ( V_19 , L_19 ) ;
return - V_67 ;
}
V_1 = F_32 ( V_19 , V_60 ) ;
if ( F_33 ( V_1 ) )
return F_34 ( V_1 ) ;
if ( F_35 ( V_57 , L_20 ) ) {
V_20 = F_36 ( V_19 , L_21 ) ;
if ( F_33 ( V_20 ) ) {
F_27 ( V_19 , L_22 ) ;
return F_34 ( V_20 ) ;
}
}
V_5 -> V_19 = V_19 ;
V_5 -> V_29 = V_29 ;
V_5 -> V_1 = V_1 ;
V_5 -> V_20 = V_20 ;
V_19 -> V_70 = & V_71 ;
F_37 ( V_19 ) ;
V_16 = F_38 ( V_19 ) ;
if ( V_16 < 0 ) {
F_27 ( V_19 , L_23 , V_16 ) ;
goto V_72;
}
V_31 = F_1 ( V_5 -> V_1 , V_73 ) ;
V_5 -> V_74 = V_31 ;
V_66 = F_39 ( V_31 ) ;
switch ( V_66 ) {
case V_75 :
case V_76 :
V_5 -> V_77 = 0 ;
V_5 -> V_9 = 0 ;
V_5 -> V_11 = 0 ;
V_5 -> V_7 = 0 ;
V_5 -> V_78 = 0 ;
break;
default:
V_5 -> V_77 = V_79 ;
V_5 -> V_9 = V_80 ;
V_5 -> V_11 = V_81 ;
V_5 -> V_7 = V_82 ;
V_5 -> V_78 = V_83 ;
break;
}
if ( F_40 ( V_57 , L_24 ) ) {
V_5 -> V_77 = V_79 ;
V_5 -> V_9 = V_80 ;
V_5 -> V_11 = V_81 ;
V_5 -> V_7 = V_82 ;
V_5 -> V_78 = V_83 ;
}
V_31 = F_5 ( V_5 ) ;
F_41 ( V_57 , L_25 , & V_65 ) ;
switch ( V_65 ) {
case V_84 :
V_31 |= V_85 ;
break;
case V_86 :
V_31 &= ~ V_85 ;
break;
default:
F_14 ( V_19 , L_26 , V_65 ) ;
}
F_6 ( V_5 , V_31 ) ;
V_31 = F_1 ( V_5 -> V_1 , V_87 ) ;
V_5 -> V_33 = ! ! ( V_31 & V_88 ) ;
V_16 = F_42 ( V_19 , V_5 -> V_29 , F_17 , 0 ,
L_27 , V_5 ) ;
if ( V_16 ) {
F_27 ( V_19 , L_28 ,
V_5 -> V_29 , V_16 ) ;
goto V_89;
}
F_21 ( V_5 ) ;
if ( F_35 ( V_57 , L_29 ) ) {
V_62 = F_43 ( V_19 , 0 ) ;
if ( F_33 ( V_62 ) ) {
F_44 ( V_19 , L_30 ) ;
V_16 = - V_90 ;
goto V_91;
}
V_5 -> V_55 . V_92 = F_25 ;
V_16 = F_45 ( & V_5 -> V_93 ,
V_62 -> V_94 , L_31 , & V_5 -> V_55 ) ;
if ( V_16 < 0 )
F_44 ( V_19 , L_32 ) ;
V_5 -> V_53 . V_92 = F_23 ;
V_16 = F_45 ( & V_5 -> V_95 , V_62 -> V_94 ,
L_33 , & V_5 -> V_53 ) ;
if ( V_16 < 0 )
F_44 ( V_19 ,
L_34 ) ;
if ( F_46 ( V_62 , L_31 ) == true )
F_13 ( V_5 , V_26 ) ;
if ( F_46 ( V_62 , L_33 ) == true )
F_13 ( V_5 , V_18 ) ;
}
V_16 = F_47 ( V_57 , NULL , NULL , V_19 ) ;
if ( V_16 ) {
F_27 ( & V_47 -> V_19 , L_35 ) ;
goto V_96;
}
return 0 ;
V_96:
if ( V_5 -> V_93 . V_62 )
F_48 ( & V_5 -> V_93 ) ;
if ( V_5 -> V_95 . V_62 )
F_48 ( & V_5 -> V_95 ) ;
V_91:
F_22 ( V_5 ) ;
V_89:
F_49 ( V_19 ) ;
V_72:
F_50 ( V_19 ) ;
return V_16 ;
}
static int F_51 ( struct V_46 * V_47 )
{
struct V_4 * V_5 = F_52 ( V_47 ) ;
if ( V_5 -> V_93 . V_62 )
F_48 ( & V_5 -> V_93 ) ;
if ( V_5 -> V_95 . V_62 )
F_48 ( & V_5 -> V_95 ) ;
F_22 ( V_5 ) ;
F_49 ( & V_47 -> V_19 ) ;
F_50 ( & V_47 -> V_19 ) ;
F_53 ( & V_47 -> V_19 , NULL , F_18 ) ;
return 0 ;
}
static int F_54 ( struct V_44 * V_19 )
{
struct V_4 * V_5 = F_55 ( V_19 ) ;
F_22 ( V_5 ) ;
return 0 ;
}
static void F_56 ( struct V_44 * V_19 )
{
struct V_4 * V_5 = F_55 ( V_19 ) ;
F_21 ( V_5 ) ;
}
static int F_57 ( struct V_44 * V_19 )
{
struct V_4 * V_5 = F_55 ( V_19 ) ;
V_5 -> V_97 = F_5 ( V_5 ) ;
return 0 ;
}
static int F_58 ( struct V_44 * V_19 )
{
struct V_4 * V_5 = F_55 ( V_19 ) ;
F_6 ( V_5 , V_5 -> V_97 ) ;
F_50 ( V_19 ) ;
F_59 ( V_19 ) ;
F_37 ( V_19 ) ;
return 0 ;
}
