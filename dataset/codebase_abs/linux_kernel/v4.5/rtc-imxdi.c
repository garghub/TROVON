static void F_1 ( const struct V_1 * V_2 , T_1 V_3 ,
unsigned V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
F_3 ( 130 , 200 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_6 )
{
T_1 V_7 ;
V_7 = F_5 ( V_2 -> V_5 + V_8 ) ;
F_6 ( & V_2 -> V_9 -> V_10 , L_1 ) ;
if ( V_6 & V_11 )
F_6 ( & V_2 -> V_9 -> V_10 , L_2 ,
V_7 & V_12 ? L_3 : L_4 ) ;
if ( V_6 & V_13 )
F_6 ( & V_2 -> V_9 -> V_10 , L_5 ,
V_7 & V_14 ? L_3 : L_4 ) ;
if ( V_6 & V_15 )
F_6 ( & V_2 -> V_9 -> V_10 , L_6 ,
V_7 & V_16 ? L_3 : L_4 ) ;
if ( V_6 & V_17 )
F_6 ( & V_2 -> V_9 -> V_10 ,
L_7 ,
V_7 & V_18 ? L_3 : L_4 ) ;
if ( V_6 & V_19 )
F_6 ( & V_2 -> V_9 -> V_10 , L_8 ,
V_7 & V_20 ? L_3 : L_4 ) ;
if ( V_6 & V_21 )
F_6 ( & V_2 -> V_9 -> V_10 , L_9 ,
V_7 & V_22 ? L_3 : L_4 ) ;
if ( V_6 & V_23 )
F_6 ( & V_2 -> V_9 -> V_10 , L_10 ,
V_7 & V_24 ? L_3 : L_4 ) ;
if ( V_6 & V_25 )
F_6 ( & V_2 -> V_9 -> V_10 , L_11 ,
V_7 & V_26 ? L_3 : L_4 ) ;
if ( V_6 & V_27 )
F_6 ( & V_2 -> V_9 -> V_10 ,
L_12 ,
V_7 & V_28 ? L_3 : L_4 ) ;
if ( V_6 & V_29 )
F_6 ( & V_2 -> V_9 -> V_10 , L_13 ,
V_7 & V_30 ? L_3 : L_4 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
const char * V_31 )
{
F_6 ( & V_2 -> V_9 -> V_10 , L_14 ,
V_31 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_6 )
{
T_1 V_32 ;
F_9 ( & V_2 -> V_9 -> V_10 , L_15 , V_6 ) ;
F_4 ( V_2 , V_6 ) ;
V_32 = F_5 ( V_2 -> V_5 + V_33 ) ;
if ( V_32 & V_34 ) {
F_7 ( V_2 , L_16 ) ;
return - V_35 ;
}
F_7 ( V_2 , L_17 ) ;
return - V_35 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_6 )
{
F_1 ( V_2 , V_36 , V_37 ) ;
F_1 ( V_2 , 0 , V_38 ) ;
if ( V_6 & V_39 )
F_1 ( V_2 , V_39 , V_40 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_6 )
{
T_1 V_32 , V_41 ;
F_1 ( V_2 , 0x00000000 , V_8 ) ;
F_1 ( V_2 , V_42 , V_33 ) ;
V_41 = F_5 ( V_2 -> V_5 + V_43 ) ;
if ( V_41 != 0 )
F_12 ( & V_2 -> V_9 -> V_10 ,
L_18 ,
V_41 ) ;
V_32 = F_5 ( V_2 -> V_5 + V_33 ) ;
if ( ! ( V_32 & V_44 ) ) {
if ( V_32 & V_45 ) {
F_7 ( V_2 , L_16 ) ;
return - V_35 ;
}
if ( V_32 & V_46 ) {
F_7 ( V_2 , L_17 ) ;
return - V_35 ;
}
}
F_1 ( V_2 , V_47 , V_40 ) ;
F_1 ( V_2 , V_29 , V_40 ) ;
F_1 ( V_2 , V_32 | V_44 , V_33 ) ;
F_1 ( V_2 , V_41 , V_43 ) ;
return F_10 ( V_2 , F_13 ( V_2 -> V_5 + V_40 ) ) ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_6 )
{
T_1 V_32 ;
if ( V_6 & ( V_25 | V_23 | V_21 | V_19 | V_17 |
V_15 | V_13 | V_11 | V_27 | V_29 ) ) {
V_32 = F_13 ( V_2 -> V_5 + V_33 ) ;
if ( V_32 & V_48 ) {
F_7 ( V_2 , L_16 ) ;
return - V_35 ;
}
if ( V_32 & V_42 ) {
F_7 ( V_2 , L_17 ) ;
return - V_35 ;
}
}
F_1 ( V_2 , 0x00000000 , V_8 ) ;
F_1 ( V_2 , V_6 & ( V_25 | V_23 | V_21 |
V_19 | V_17 | V_15 | V_13 | V_11 |
V_27 | V_29 ) , V_40 ) ;
V_6 = F_5 ( V_2 -> V_5 + V_40 ) ;
if ( ( V_6 & ~ ( V_47 | V_49 | V_50 | V_51 |
V_52 | V_53 ) ) != 0 )
F_12 ( & V_2 -> V_9 -> V_10 ,
L_19 ,
V_6 & ~ ( V_47 | V_49 | V_50 | V_51 |
V_52 | V_53 ) ) ;
F_1 ( V_2 , V_49 , V_40 ) ;
V_6 = F_5 ( V_2 -> V_5 + V_40 ) ;
if ( V_6 & V_49 ) {
F_15 ( & V_2 -> V_9 -> V_10 ,
L_20 ) ;
F_7 ( V_2 , L_16 ) ;
return - V_35 ;
}
return F_11 ( V_2 , V_6 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_54 ;
T_1 V_6 ;
V_6 = F_5 ( V_2 -> V_5 + V_40 ) ;
switch ( V_6 & ( V_47 | V_49 ) ) {
case V_47 :
F_12 ( & V_2 -> V_9 -> V_10 , L_21 ) ;
V_54 = F_11 ( V_2 , V_6 ) ;
break;
case V_49 :
F_12 ( & V_2 -> V_9 -> V_10 , L_22 ) ;
V_54 = F_8 ( V_2 , V_6 ) ;
break;
case V_47 | V_49 :
F_12 ( & V_2 -> V_9 -> V_10 ,
L_23 ) ;
V_54 = F_14 ( V_2 , V_6 ) ;
break;
default:
F_17 ( & V_2 -> V_9 -> V_10 , L_24 ) ;
V_54 = F_10 ( V_2 , V_6 ) ;
}
return V_54 ;
}
static void F_18 ( struct V_1 * V_2 , T_1 V_55 )
{
unsigned long V_56 ;
F_19 ( & V_2 -> V_57 , V_56 ) ;
F_2 ( F_5 ( V_2 -> V_5 + V_58 ) | V_55 ,
V_2 -> V_5 + V_58 ) ;
F_20 ( & V_2 -> V_57 , V_56 ) ;
}
static void F_21 ( struct V_1 * V_2 , T_1 V_55 )
{
unsigned long V_56 ;
F_19 ( & V_2 -> V_57 , V_56 ) ;
F_2 ( F_5 ( V_2 -> V_5 + V_58 ) & ~ V_55 ,
V_2 -> V_5 + V_58 ) ;
F_20 ( & V_2 -> V_57 , V_56 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
int V_59 ;
F_12 ( & V_2 -> V_9 -> V_10 , L_25 ) ;
F_2 ( V_53 , V_2 -> V_5 + V_40 ) ;
for ( V_59 = 0 ; V_59 < 1000 ; V_59 ++ ) {
if ( ( F_5 ( V_2 -> V_5 + V_40 ) & V_53 ) == 0 )
return;
F_23 ( 10 ) ;
}
F_24 ( & V_2 -> V_9 -> V_10 ,
L_26 ) ;
}
static int F_25 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
int V_60 ;
int V_54 = 0 ;
F_26 ( & V_2 -> V_61 ) ;
F_18 ( V_2 , V_62 ) ;
V_2 -> V_6 = 0 ;
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
V_60 = F_27 ( V_2 -> V_63 ,
V_2 -> V_6 & ( V_52 | V_53 ) , F_28 ( 1 ) ) ;
if ( V_60 < 0 ) {
V_54 = V_60 ;
goto V_64;
} else if ( V_60 == 0 ) {
F_12 ( & V_2 -> V_9 -> V_10 ,
L_27
L_28 , V_3 , V_4 ) ;
}
if ( V_2 -> V_6 & V_53 ) {
F_22 ( V_2 ) ;
V_54 = - V_65 ;
}
V_64:
F_29 ( & V_2 -> V_61 ) ;
return V_54 ;
}
static int F_30 ( struct V_66 * V_10 , struct V_67 * V_68 )
{
struct V_1 * V_2 = F_31 ( V_10 ) ;
unsigned long V_69 ;
V_69 = F_5 ( V_2 -> V_5 + V_43 ) ;
F_32 ( V_69 , V_68 ) ;
return 0 ;
}
static int F_33 ( struct V_66 * V_10 , unsigned long V_70 )
{
struct V_1 * V_2 = F_31 ( V_10 ) ;
T_1 V_32 , V_6 ;
int V_54 ;
V_32 = F_5 ( V_2 -> V_5 + V_33 ) ;
V_6 = F_5 ( V_2 -> V_5 + V_40 ) ;
if ( ! ( V_32 & V_44 ) || ( V_6 & V_49 ) ) {
if ( V_32 & V_45 ) {
F_7 ( V_2 , L_16 ) ;
return - V_71 ;
}
if ( ( V_32 & V_46 ) || ( V_6 & V_49 ) ) {
F_7 ( V_2 , L_17 ) ;
return - V_71 ;
}
}
V_54 = F_25 ( V_2 , 0 , V_72 ) ;
if ( V_54 != 0 )
return V_54 ;
V_54 = F_25 ( V_2 , V_70 , V_43 ) ;
if ( V_54 != 0 )
return V_54 ;
return F_25 ( V_2 , F_5 ( V_2 -> V_5 + V_33 ) | V_44 , V_33 ) ;
}
static int F_34 ( struct V_66 * V_10 ,
unsigned int V_73 )
{
struct V_1 * V_2 = F_31 ( V_10 ) ;
if ( V_73 )
F_18 ( V_2 , V_74 ) ;
else
F_21 ( V_2 , V_74 ) ;
return 0 ;
}
static int F_35 ( struct V_66 * V_10 , struct V_75 * V_76 )
{
struct V_1 * V_2 = F_31 ( V_10 ) ;
T_1 V_77 ;
V_77 = F_5 ( V_2 -> V_5 + V_37 ) ;
F_32 ( V_77 , & V_76 -> time ) ;
V_76 -> V_73 = ( F_5 ( V_2 -> V_5 + V_58 ) & V_74 ) != 0 ;
F_26 ( & V_2 -> V_61 ) ;
V_76 -> V_78 = ( F_5 ( V_2 -> V_5 + V_40 ) & V_39 ) != 0 ;
F_29 ( & V_2 -> V_61 ) ;
return 0 ;
}
static int F_36 ( struct V_66 * V_10 , struct V_75 * V_76 )
{
struct V_1 * V_2 = F_31 ( V_10 ) ;
unsigned long V_69 ;
unsigned long V_79 ;
int V_54 ;
V_54 = F_37 ( & V_76 -> time , & V_79 ) ;
if ( V_54 )
return V_54 ;
V_69 = F_5 ( V_2 -> V_5 + V_43 ) ;
if ( V_79 < V_69 )
return - V_80 ;
V_54 = F_25 ( V_2 , ( T_1 ) V_79 , V_37 ) ;
if ( V_54 )
return V_54 ;
if ( V_76 -> V_73 )
F_18 ( V_2 , V_74 ) ;
else
F_21 ( V_2 , V_74 ) ;
return 0 ;
}
static T_2 F_38 ( int V_81 , void * V_82 )
{
struct V_1 * V_2 = V_82 ;
T_1 V_6 , V_83 ;
T_2 V_54 = V_84 ;
V_83 = F_5 ( V_2 -> V_5 + V_58 ) ;
V_6 = F_5 ( V_2 -> V_5 + V_40 ) ;
if ( V_83 & V_85 ) {
if ( V_6 & V_49 ) {
F_21 ( V_2 , V_85 ) ;
F_4 ( V_2 , V_6 ) ;
V_54 = V_86 ;
}
}
if ( V_83 & V_62 ) {
if ( F_39 ( & V_2 -> V_63 . V_87 ) )
return V_54 ;
if ( V_6 & ( V_52 | V_53 ) ) {
F_21 ( V_2 , V_62 ) ;
V_2 -> V_6 |= V_6 ;
F_40 ( & V_2 -> V_63 ) ;
V_54 = V_86 ;
}
}
if ( V_83 & V_74 ) {
if ( V_6 & V_39 ) {
F_21 ( V_2 , V_74 ) ;
F_41 ( & V_2 -> V_88 ) ;
V_54 = V_86 ;
}
}
return V_54 ;
}
static void F_42 ( struct V_89 * V_88 )
{
struct V_1 * V_2 = F_43 ( V_88 ,
struct V_1 , V_88 ) ;
F_25 ( V_2 , V_39 , V_40 ) ;
F_44 ( V_2 -> V_90 , 1 , V_91 | V_92 ) ;
}
static int T_3 F_45 ( struct V_93 * V_9 )
{
struct V_94 * V_95 ;
struct V_1 * V_2 ;
int V_54 ;
V_2 = F_46 ( & V_9 -> V_10 , sizeof( * V_2 ) , V_96 ) ;
if ( ! V_2 )
return - V_97 ;
V_2 -> V_9 = V_9 ;
V_95 = F_47 ( V_9 , V_98 , 0 ) ;
V_2 -> V_5 = F_48 ( & V_9 -> V_10 , V_95 ) ;
if ( F_49 ( V_2 -> V_5 ) )
return F_50 ( V_2 -> V_5 ) ;
F_51 ( & V_2 -> V_57 ) ;
V_2 -> V_81 = F_52 ( V_9 , 0 ) ;
if ( V_2 -> V_81 < 0 )
return V_2 -> V_81 ;
F_53 ( & V_2 -> V_63 ) ;
F_54 ( & V_2 -> V_88 , F_42 ) ;
F_55 ( & V_2 -> V_61 ) ;
V_2 -> V_99 = F_56 ( & V_9 -> V_10 , NULL ) ;
if ( F_49 ( V_2 -> V_99 ) )
return F_50 ( V_2 -> V_99 ) ;
V_54 = F_57 ( V_2 -> V_99 ) ;
if ( V_54 )
return V_54 ;
F_2 ( 0 , V_2 -> V_5 + V_58 ) ;
V_54 = F_16 ( V_2 ) ;
if ( V_54 != 0 )
goto V_100;
V_54 = F_58 ( & V_9 -> V_10 , V_2 -> V_81 , F_38 ,
V_101 , V_9 -> V_102 , V_2 ) ;
if ( V_54 ) {
F_12 ( & V_9 -> V_10 , L_29 ) ;
goto V_100;
}
F_59 ( V_9 , V_2 ) ;
V_2 -> V_90 = F_60 ( & V_9 -> V_10 , V_9 -> V_102 ,
& V_103 , V_104 ) ;
if ( F_49 ( V_2 -> V_90 ) ) {
V_54 = F_50 ( V_2 -> V_90 ) ;
goto V_100;
}
return 0 ;
V_100:
F_61 ( V_2 -> V_99 ) ;
return V_54 ;
}
static int T_4 F_62 ( struct V_93 * V_9 )
{
struct V_1 * V_2 = F_63 ( V_9 ) ;
F_64 ( & V_2 -> V_88 ) ;
F_2 ( 0 , V_2 -> V_5 + V_58 ) ;
F_61 ( V_2 -> V_99 ) ;
return 0 ;
}
