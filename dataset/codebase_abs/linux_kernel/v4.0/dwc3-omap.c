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
static int F_20 ( struct V_46 * V_21 , void * V_47 )
{
struct V_48 * V_49 = F_21 ( V_21 ) ;
F_22 ( V_49 ) ;
return 0 ;
}
static void F_23 ( struct V_4 * V_5 )
{
T_1 V_33 ;
V_33 = V_50 ;
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
static void F_24 ( struct V_4 * V_5 )
{
T_1 V_33 ;
V_33 = V_50 ;
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
static int F_25 ( struct V_51 * V_52 ,
unsigned long V_53 , void * V_54 )
{
struct V_4 * V_5 = F_26 ( V_52 , struct V_4 , V_55 ) ;
if ( V_53 )
F_15 ( V_5 , V_20 ) ;
else
F_15 ( V_5 , V_29 ) ;
return V_56 ;
}
static int F_27 ( struct V_51 * V_52 ,
unsigned long V_53 , void * V_54 )
{
struct V_4 * V_5 = F_26 ( V_52 , struct V_4 , V_57 ) ;
if ( V_53 )
F_15 ( V_5 , V_28 ) ;
else
F_15 ( V_5 , V_30 ) ;
return V_56 ;
}
static void F_28 ( struct V_4 * V_5 )
{
struct V_58 * V_59 = V_5 -> V_21 -> V_60 ;
if ( F_29 ( V_59 , L_16 ) ) {
V_5 -> V_61 = V_62 ;
V_5 -> V_9 = V_63 ;
V_5 -> V_11 = V_64 ;
V_5 -> V_7 = V_65 ;
V_5 -> V_66 = V_67 ;
}
}
static void F_30 ( struct V_4 * V_5 )
{
T_1 V_33 ;
struct V_58 * V_59 = V_5 -> V_21 -> V_60 ;
int V_68 = 0 ;
V_33 = F_5 ( V_5 ) ;
F_31 ( V_59 , L_17 , & V_68 ) ;
switch ( V_68 ) {
case V_69 :
V_33 |= V_70 ;
break;
case V_71 :
V_33 &= ~ V_70 ;
break;
default:
F_16 ( V_5 -> V_21 , L_18 , V_68 ) ;
}
F_6 ( V_5 , V_33 ) ;
}
static int F_32 ( struct V_4 * V_5 )
{
int V_18 ;
struct V_58 * V_59 = V_5 -> V_21 -> V_60 ;
struct V_72 * V_73 ;
if ( F_33 ( V_59 , L_19 ) ) {
V_73 = F_34 ( V_5 -> V_21 , 0 ) ;
if ( F_35 ( V_73 ) ) {
F_36 ( V_5 -> V_21 , L_20 ) ;
return - V_74 ;
}
V_5 -> V_57 . V_75 = F_27 ;
V_18 = F_37 ( & V_5 -> V_76 ,
V_73 -> V_77 , L_21 ,
& V_5 -> V_57 ) ;
if ( V_18 < 0 )
F_36 ( V_5 -> V_21 , L_22 ) ;
V_5 -> V_55 . V_75 = F_25 ;
V_18 = F_37 ( & V_5 -> V_78 ,
V_73 -> V_77 , L_23 ,
& V_5 -> V_55 ) ;
if ( V_18 < 0 )
F_36 ( V_5 -> V_21 , L_24 ) ;
if ( F_38 ( V_73 , L_21 ) == true )
F_15 ( V_5 , V_28 ) ;
if ( F_38 ( V_73 , L_23 ) == true )
F_15 ( V_5 , V_20 ) ;
}
return 0 ;
}
static int F_39 ( struct V_48 * V_49 )
{
struct V_58 * V_59 = V_49 -> V_21 . V_60 ;
struct V_4 * V_5 ;
struct V_79 * V_80 ;
struct V_46 * V_21 = & V_49 -> V_21 ;
struct V_81 * V_22 = NULL ;
int V_18 ;
int V_31 ;
T_1 V_33 ;
void T_2 * V_1 ;
if ( ! V_59 ) {
F_40 ( V_21 , L_25 ) ;
return - V_82 ;
}
V_5 = F_41 ( V_21 , sizeof( * V_5 ) , V_83 ) ;
if ( ! V_5 )
return - V_84 ;
F_42 ( V_49 , V_5 ) ;
V_31 = F_43 ( V_49 , 0 ) ;
if ( V_31 < 0 ) {
F_40 ( V_21 , L_26 ) ;
return - V_82 ;
}
V_80 = F_44 ( V_49 , V_85 , 0 ) ;
V_1 = F_45 ( V_21 , V_80 ) ;
if ( F_35 ( V_1 ) )
return F_46 ( V_1 ) ;
if ( F_33 ( V_59 , L_27 ) ) {
V_22 = F_47 ( V_21 , L_28 ) ;
if ( F_35 ( V_22 ) ) {
F_40 ( V_21 , L_29 ) ;
return F_46 ( V_22 ) ;
}
}
V_5 -> V_21 = V_21 ;
V_5 -> V_31 = V_31 ;
V_5 -> V_1 = V_1 ;
V_5 -> V_22 = V_22 ;
V_21 -> V_86 = & V_87 ;
F_48 ( V_21 ) ;
V_18 = F_49 ( V_21 ) ;
if ( V_18 < 0 ) {
F_40 ( V_21 , L_30 , V_18 ) ;
goto V_88;
}
F_28 ( V_5 ) ;
F_30 ( V_5 ) ;
V_33 = F_1 ( V_5 -> V_1 , V_89 ) ;
V_5 -> V_35 = ! ! ( V_33 & V_90 ) ;
V_18 = F_50 ( V_21 , V_5 -> V_31 , F_19 , 0 ,
L_31 , V_5 ) ;
if ( V_18 ) {
F_40 ( V_21 , L_32 ,
V_5 -> V_31 , V_18 ) ;
goto V_91;
}
F_23 ( V_5 ) ;
V_18 = F_32 ( V_5 ) ;
if ( V_18 < 0 )
goto V_92;
V_18 = F_51 ( V_59 , NULL , NULL , V_21 ) ;
if ( V_18 ) {
F_40 ( & V_49 -> V_21 , L_33 ) ;
goto V_93;
}
return 0 ;
V_93:
if ( V_5 -> V_76 . V_73 )
F_52 ( & V_5 -> V_76 ) ;
if ( V_5 -> V_78 . V_73 )
F_52 ( & V_5 -> V_78 ) ;
V_92:
F_24 ( V_5 ) ;
V_91:
F_53 ( V_21 ) ;
V_88:
F_54 ( V_21 ) ;
return V_18 ;
}
static int F_55 ( struct V_48 * V_49 )
{
struct V_4 * V_5 = F_56 ( V_49 ) ;
if ( V_5 -> V_76 . V_73 )
F_52 ( & V_5 -> V_76 ) ;
if ( V_5 -> V_78 . V_73 )
F_52 ( & V_5 -> V_78 ) ;
F_24 ( V_5 ) ;
F_57 ( & V_49 -> V_21 , NULL , F_20 ) ;
F_53 ( & V_49 -> V_21 ) ;
F_54 ( & V_49 -> V_21 ) ;
return 0 ;
}
static int F_58 ( struct V_46 * V_21 )
{
struct V_4 * V_5 = F_59 ( V_21 ) ;
V_5 -> V_94 = F_5 ( V_5 ) ;
F_24 ( V_5 ) ;
return 0 ;
}
static int F_60 ( struct V_46 * V_21 )
{
struct V_4 * V_5 = F_59 ( V_21 ) ;
F_6 ( V_5 , V_5 -> V_94 ) ;
F_23 ( V_5 ) ;
F_54 ( V_21 ) ;
F_61 ( V_21 ) ;
F_48 ( V_21 ) ;
return 0 ;
}
