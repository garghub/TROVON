static int F_1 (
struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 = F_2 ( F_3 ( V_2 ) ,
struct V_8 , V_10 ) ;
struct V_11 * V_12 ;
struct V_1 * V_13 , * V_14 , * V_15 , * V_16 , * V_17 ;
bool V_18 ;
if ( ! V_3 -> V_19 ||
V_3 -> V_19 -> V_20 != & V_21 ) {
F_4 ( L_1 , V_3 ) ;
return - V_22 ;
}
V_7 = F_2 ( F_3 ( V_3 ) , struct V_6 , V_23 ) ;
if ( ! V_7 -> V_24 ) {
F_4 ( L_2 ) ;
return - V_25 ;
}
if ( V_7 -> V_26 ) {
F_4 ( L_3
L_4 ) ;
return - V_25 ;
}
V_12 = V_7 -> V_27 ;
V_13 = & V_2 -> V_28 -> V_29 -> V_30 ;
V_14 = & V_13 -> V_29 -> V_30 ;
V_16 = & V_14 -> V_29 -> V_30 ;
V_15 = & V_3 -> V_28 -> V_29 -> V_30 ;
V_17 = & V_15 -> V_29 -> V_30 ;
if ( strcmp ( F_5 ( V_16 ) , F_5 ( V_17 ) ) ) {
F_4 ( L_5 ,
F_5 ( V_16 ) ) ;
return - V_25 ;
}
if ( strcmp ( F_5 ( V_14 ) , F_5 ( V_15 ) ) ) {
F_4 ( L_6
L_7 , F_5 ( V_16 ) ,
F_5 ( V_14 ) ) ;
return - V_25 ;
}
F_6 () ;
V_5 = F_7 ( V_9 -> V_31 , V_9 -> V_32 ) ;
if ( V_5 )
V_18 = V_5 -> V_18 ;
else
V_18 =
( V_12 -> V_33 -> V_34 (
V_12 ) ) ? true : false ;
F_8 () ;
return F_9 ( V_12 , V_9 , V_7 , V_18 ) ;
}
static void F_10 (
struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_8 * V_9 = F_2 ( F_3 ( V_2 ) ,
struct V_8 , V_10 ) ;
struct V_6 * V_7 = F_2 ( F_3 ( V_3 ) ,
struct V_6 , V_23 ) ;
F_11 ( V_7 , V_9 ) ;
}
static struct V_8 * F_12 ( struct V_1 * V_35 )
{
return F_2 ( F_3 ( V_35 ) , struct V_8 ,
V_10 ) ;
}
static T_1 F_13 (
struct V_1 * V_35 , char * V_36 )
{
struct V_8 * V_9 = F_12 ( V_35 ) ;
struct V_37 * V_38 = V_9 -> V_31 ;
struct V_4 * V_5 ;
T_1 V_39 = 0 ;
F_6 () ;
V_5 = F_7 ( V_38 , V_9 -> V_32 ) ;
if ( V_5 ) {
V_39 = sprintf ( V_36 , L_8 , V_5 -> V_18 ) ;
}
F_8 () ;
return V_39 ;
}
static T_1 F_14 (
struct V_1 * V_35 , const char * V_36 , T_2 V_40 )
{
struct V_8 * V_9 = F_12 ( V_35 ) ;
struct V_37 * V_38 = V_9 -> V_31 ;
struct V_11 * V_12 = V_38 -> V_12 ;
unsigned long V_41 ;
int V_42 ;
V_42 = F_15 ( V_36 , 0 , & V_41 ) ;
if ( V_42 )
return V_42 ;
if ( ( V_41 != 1 ) && ( V_41 != 0 ) )
return - V_25 ;
F_16 ( V_9 -> V_32 , V_41 , V_9 -> V_31 ) ;
F_17 ( L_9
L_10 ,
V_12 -> V_33 -> V_43 () ,
V_38 -> V_44 , V_9 -> V_32 , ( V_41 ) ? L_11 : L_12 ) ;
return V_40 ;
}
static void F_18 ( struct V_1 * V_35 )
{
struct V_8 * V_9 = F_2 ( F_3 ( V_35 ) ,
struct V_8 , V_10 ) ;
struct V_11 * V_12 = V_9 -> V_31 -> V_12 ;
F_19 ( V_12 , V_9 ) ;
}
static struct V_45 * F_20 (
struct V_45 * V_46 ,
const char * V_47 )
{
return F_21 ( - V_48 ) ;
}
static void F_22 (
struct V_45 * V_46 ,
struct V_1 * V_35 )
{
return;
}
static struct V_45 * F_23 (
struct V_45 * V_46 ,
const char * V_47 )
{
struct V_37 * V_38 = F_2 ( V_46 ,
struct V_37 , V_49 ) ;
struct V_11 * V_12 = V_38 -> V_12 ;
struct V_50 * V_51 = V_12 -> V_52 -> V_53 ;
struct V_8 * V_9 = NULL ;
char * V_54 ;
unsigned long long V_32 ;
int V_42 = 0 ;
V_54 = F_24 ( strlen ( V_47 ) + 1 , V_55 ) ;
if ( ! V_54 ) {
F_4 ( L_13 ) ;
return F_21 ( - V_56 ) ;
}
snprintf ( V_54 , strlen ( V_47 ) + 1 , L_14 , V_47 ) ;
if ( strstr ( V_54 , L_15 ) != V_54 ) {
F_4 ( L_16
L_17 , V_54 , V_47 ) ;
V_42 = - V_25 ;
goto V_57;
}
V_42 = F_25 ( V_54 + 4 , 0 , & V_32 ) ;
if ( V_42 )
goto V_57;
V_9 = F_26 ( V_12 , V_38 ,
V_32 , & V_42 ) ;
if ( ! V_9 ) {
V_42 = - V_25 ;
goto V_57;
}
F_27 ( & V_9 -> V_10 , V_47 ,
& V_51 -> V_58 ) ;
F_27 ( & V_9 -> V_59 . V_60 ,
L_18 , & V_51 -> V_61 ) ;
F_28 ( & V_9 -> V_59 . V_60 ,
& V_9 -> V_10 ) ;
F_29 ( V_9 ) ;
F_30 ( V_54 ) ;
return & V_9 -> V_10 ;
V_57:
F_30 ( V_9 ) ;
F_30 ( V_54 ) ;
return F_21 ( V_42 ) ;
}
static void F_31 (
struct V_45 * V_46 ,
struct V_1 * V_35 )
{
struct V_8 * V_9 = F_2 ( F_3 ( V_35 ) ,
struct V_8 , V_10 ) ;
F_32 ( & V_9 -> V_59 . V_60 ) ;
F_32 ( & V_9 -> V_10 ) ;
F_33 ( V_35 ) ;
}
static void F_34 ( struct V_1 * V_35 )
{
struct V_37 * V_38 = F_2 ( F_3 ( V_35 ) ,
struct V_37 , V_49 ) ;
F_32 ( & V_38 -> V_62 ) ;
F_35 ( V_38 ) ;
}
static struct V_45 * F_36 (
struct V_45 * V_46 ,
const char * V_47 )
{
struct V_11 * V_12 = F_2 ( V_46 ,
struct V_11 , V_63 ) ;
struct V_50 * V_51 = V_12 -> V_52 -> V_53 ;
struct V_37 * V_38 ;
V_38 = F_37 ( V_12 , V_47 ) ;
if ( F_38 ( V_38 ) )
return F_39 ( V_38 ) ;
F_27 ( & V_38 -> V_49 , V_47 ,
& V_51 -> V_64 ) ;
F_27 ( & V_38 -> V_65 , L_19 ,
& V_51 -> V_66 ) ;
F_28 ( & V_38 -> V_65 ,
& V_38 -> V_49 ) ;
F_27 ( & V_38 -> V_67 , L_20 ,
& V_51 -> V_68 ) ;
F_28 ( & V_38 -> V_67 ,
& V_38 -> V_49 ) ;
F_27 ( & V_38 -> V_69 , L_21 ,
& V_51 -> V_70 ) ;
F_28 ( & V_38 -> V_69 ,
& V_38 -> V_49 ) ;
F_27 ( & V_38 -> V_62 ,
L_22 , & V_51 -> V_71 ) ;
F_28 ( & V_38 -> V_62 ,
& V_38 -> V_49 ) ;
if ( V_51 -> V_72 -> V_73 ) {
int V_42 = V_51 -> V_72 -> V_73 ( V_38 , V_47 ) ;
if ( V_42 ) {
F_32 ( & V_38 -> V_62 ) ;
F_35 ( V_38 ) ;
return F_21 ( V_42 ) ;
}
}
return & V_38 -> V_49 ;
}
static void F_40 (
struct V_45 * V_46 ,
struct V_1 * V_35 )
{
struct V_37 * V_38 = F_2 ( F_3 ( V_35 ) ,
struct V_37 , V_49 ) ;
F_32 ( & V_38 -> V_49 ) ;
F_33 ( V_35 ) ;
}
static void F_41 ( struct V_1 * V_35 )
{
struct V_74 * V_74 = F_2 ( F_3 ( V_35 ) ,
struct V_74 , V_75 ) ;
struct V_11 * V_12 = V_74 -> V_76 ;
struct V_50 * V_51 = V_12 -> V_52 -> V_53 ;
V_51 -> V_72 -> V_77 ( V_74 ) ;
}
static struct V_45 * F_42 (
struct V_45 * V_46 ,
const char * V_47 )
{
struct V_11 * V_12 = F_2 ( V_46 ,
struct V_11 , V_75 ) ;
struct V_50 * V_51 = V_12 -> V_52 -> V_53 ;
struct V_74 * V_74 ;
if ( ! V_51 -> V_72 -> V_78 ) {
F_4 ( L_23 ) ;
return F_21 ( - V_48 ) ;
}
V_74 = V_51 -> V_72 -> V_78 ( V_12 , V_46 , V_47 ) ;
if ( ! V_74 || F_38 ( V_74 ) )
return F_21 ( - V_25 ) ;
V_74 -> V_76 = V_12 ;
F_27 ( & V_74 -> V_75 , V_47 ,
& V_51 -> V_79 ) ;
return & V_74 -> V_75 ;
}
static void F_43 (
struct V_45 * V_46 ,
struct V_1 * V_35 )
{
F_33 ( V_35 ) ;
}
static struct V_6 * F_44 ( struct V_1 * V_35 )
{
return F_2 ( F_3 ( V_35 ) , struct V_6 ,
V_23 ) ;
}
static T_1 F_45 ( struct V_1 * V_35 ,
char * V_36 )
{
struct V_6 * V_7 = F_44 ( V_35 ) ;
if ( ! V_7 || ! V_7 -> V_24 )
return - V_80 ;
return F_46 ( V_7 , V_36 ) ;
}
static T_1 F_47 ( struct V_1 * V_35 ,
const char * V_36 , T_2 V_40 )
{
struct V_6 * V_7 = F_44 ( V_35 ) ;
if ( ! V_7 || ! V_7 -> V_24 )
return - V_80 ;
return F_48 ( V_7 , V_36 , V_40 ) ;
}
static T_1 F_49 (
struct V_1 * V_35 , char * V_36 )
{
struct V_6 * V_7 = F_44 ( V_35 ) ;
if ( ! V_7 || ! V_7 -> V_24 )
return - V_80 ;
return F_50 ( V_7 , V_36 ) ;
}
static T_1 F_51 (
struct V_1 * V_35 , const char * V_36 , T_2 V_40 )
{
struct V_6 * V_7 = F_44 ( V_35 ) ;
if ( ! V_7 || ! V_7 -> V_24 )
return - V_80 ;
return F_52 ( V_7 , V_36 , V_40 ) ;
}
static T_1 F_53 (
struct V_1 * V_35 , char * V_36 )
{
struct V_6 * V_7 = F_44 ( V_35 ) ;
if ( ! V_7 || ! V_7 -> V_24 )
return - V_80 ;
return F_54 ( V_7 , V_36 ) ;
}
static T_1 F_55 (
struct V_1 * V_35 , const char * V_36 , T_2 V_40 )
{
struct V_6 * V_7 = F_44 ( V_35 ) ;
if ( ! V_7 || ! V_7 -> V_24 )
return - V_80 ;
return F_56 ( V_7 , V_36 , V_40 ) ;
}
static T_1 F_57 (
struct V_1 * V_35 , char * V_36 )
{
struct V_6 * V_7 = F_44 ( V_35 ) ;
if ( ! V_7 || ! V_7 -> V_24 )
return - V_80 ;
return F_58 ( V_7 , V_36 ) ;
}
static T_1 F_59 (
struct V_1 * V_35 , const char * V_36 , T_2 V_40 )
{
struct V_6 * V_7 = F_44 ( V_35 ) ;
if ( ! V_7 || ! V_7 -> V_24 )
return - V_80 ;
return F_60 ( V_7 , V_36 , V_40 ) ;
}
static int F_61 (
struct V_1 * V_3 ,
struct V_1 * V_81 )
{
struct V_1 * V_14 ;
struct V_6 * V_7 = F_2 ( F_3 ( V_3 ) ,
struct V_6 , V_23 ) ;
struct V_11 * V_12 ;
struct V_82 * V_83 ;
struct V_50 * V_51 ;
int V_42 ;
if ( ! V_81 -> V_19 ||
V_81 -> V_19 -> V_20 != & V_84 ) {
F_4 ( L_24 , V_81 ) ;
return - V_22 ;
}
V_83 = F_2 ( F_3 ( V_81 ) , struct V_82 , V_85 ) ;
if ( ! ( V_83 -> V_86 & V_87 ) ) {
F_4 ( L_25 ) ;
return - V_80 ;
}
V_14 = & V_3 -> V_28 -> V_29 -> V_30 ;
V_12 = F_2 ( F_3 ( V_14 ) ,
struct V_11 , V_88 ) ;
V_51 = V_12 -> V_52 -> V_53 ;
if ( V_7 -> V_24 != NULL ) {
F_4 ( L_26 ) ;
return - V_89 ;
}
V_42 = F_62 ( V_12 , V_83 , V_7 ) ;
if ( V_42 ) {
F_4 ( L_27 , V_42 ) ;
goto V_57;
}
if ( V_51 -> V_72 -> V_90 ) {
V_51 -> V_72 -> V_90 ( V_12 , V_7 ) ;
}
return 0 ;
V_57:
return V_42 ;
}
static void F_63 (
struct V_1 * V_3 ,
struct V_1 * V_81 )
{
struct V_6 * V_7 = F_2 ( F_3 ( V_3 ) ,
struct V_6 , V_23 ) ;
struct V_11 * V_12 = V_7 -> V_27 ;
struct V_50 * V_51 = V_12 -> V_52 -> V_53 ;
if ( V_51 -> V_72 -> V_91 ) {
V_51 -> V_72 -> V_91 ( V_12 , V_7 ) ;
}
F_64 ( V_12 , V_7 ) ;
}
static void F_65 ( struct V_1 * V_35 )
{
struct V_6 * V_7 = F_2 ( F_3 ( V_35 ) ,
struct V_6 , V_23 ) ;
F_66 ( V_7 , V_92 ) ;
}
static struct V_45 * F_67 (
struct V_45 * V_46 ,
const char * V_47 )
{
return F_21 ( - V_48 ) ;
}
static void F_68 (
struct V_45 * V_46 ,
struct V_1 * V_35 )
{
return;
}
static struct V_45 * F_69 (
struct V_45 * V_46 ,
const char * V_47 )
{
struct V_6 * V_7 ;
struct V_11 * V_12 = F_2 ( V_46 ,
struct V_11 , V_93 ) ;
struct V_50 * V_51 = V_12 -> V_52 -> V_53 ;
unsigned long long V_94 ;
int V_95 ;
if ( strstr ( V_47 , L_15 ) != V_47 ) {
F_4 ( L_28
L_29 ) ;
return F_21 ( - V_25 ) ;
}
V_95 = F_25 ( V_47 + 4 , 0 , & V_94 ) ;
if ( V_95 )
return F_21 ( V_95 ) ;
V_7 = F_70 ( V_12 , V_94 ) ;
if ( F_38 ( V_7 ) )
return F_39 ( V_7 ) ;
F_27 ( & V_7 -> V_23 , V_47 ,
& V_51 -> V_96 ) ;
F_27 ( & V_7 -> V_97 . V_60 ,
L_18 , & V_51 -> V_98 ) ;
F_28 ( & V_7 -> V_97 . V_60 ,
& V_7 -> V_23 ) ;
F_71 ( V_7 ) ;
return & V_7 -> V_23 ;
}
static void F_72 (
struct V_45 * V_46 ,
struct V_1 * V_35 )
{
struct V_6 * V_7 = F_2 ( F_3 ( V_35 ) ,
struct V_6 , V_23 ) ;
F_32 ( & V_7 -> V_97 . V_60 ) ;
F_32 ( & V_7 -> V_23 ) ;
F_33 ( V_35 ) ;
}
static void F_73 ( struct V_1 * V_35 )
{
struct V_11 * V_12 = F_2 ( F_3 ( V_35 ) ,
struct V_11 , V_88 ) ;
struct V_99 * V_100 = V_12 -> V_52 ;
struct V_50 * V_51 = V_100 -> V_53 ;
V_51 -> V_72 -> V_101 ( V_12 ) ;
}
static struct V_45 * F_74 (
struct V_45 * V_46 ,
const char * V_47 )
{
struct V_99 * V_100 = F_2 ( V_46 , struct V_99 , V_102 ) ;
struct V_50 * V_51 = V_100 -> V_53 ;
struct V_11 * V_12 ;
if ( ! V_51 -> V_72 -> V_103 ) {
F_4 ( L_30 ) ;
return F_21 ( - V_48 ) ;
}
V_12 = V_51 -> V_72 -> V_103 ( V_100 , V_46 , V_47 ) ;
if ( ! V_12 || F_38 ( V_12 ) )
return F_21 ( - V_25 ) ;
F_27 ( & V_12 -> V_88 , V_47 ,
& V_51 -> V_104 ) ;
F_27 ( & V_12 -> V_93 , L_31 ,
& V_51 -> V_105 ) ;
F_28 ( & V_12 -> V_93 ,
& V_12 -> V_88 ) ;
F_27 ( & V_12 -> V_75 , L_32 ,
& V_51 -> V_106 ) ;
F_28 ( & V_12 -> V_75 ,
& V_12 -> V_88 ) ;
F_27 ( & V_12 -> V_63 , L_33 ,
& V_51 -> V_107 ) ;
F_28 ( & V_12 -> V_63 ,
& V_12 -> V_88 ) ;
F_27 ( & V_12 -> V_108 , L_19 ,
& V_51 -> V_109 ) ;
F_28 ( & V_12 -> V_108 ,
& V_12 -> V_88 ) ;
F_27 ( & V_12 -> V_110 , L_20 ,
& V_51 -> V_111 ) ;
F_28 ( & V_12 -> V_110 ,
& V_12 -> V_88 ) ;
F_27 ( & V_12 -> V_112 , L_21 ,
& V_51 -> V_113 ) ;
F_28 ( & V_12 -> V_112 ,
& V_12 -> V_88 ) ;
return & V_12 -> V_88 ;
}
static void F_75 (
struct V_45 * V_46 ,
struct V_1 * V_35 )
{
struct V_11 * V_12 = F_2 ( F_3 ( V_35 ) ,
struct V_11 , V_88 ) ;
F_32 ( & V_12 -> V_88 ) ;
F_33 ( V_35 ) ;
}
static void F_76 ( struct V_1 * V_35 )
{
struct V_99 * V_100 = F_2 ( F_3 ( V_35 ) ,
struct V_99 , V_102 ) ;
struct V_50 * V_51 = V_100 -> V_53 ;
F_32 ( & V_100 -> V_114 ) ;
V_51 -> V_72 -> V_115 ( V_100 ) ;
}
static struct V_45 * F_77 (
struct V_45 * V_46 ,
const char * V_47 )
{
struct V_50 * V_51 = F_2 ( V_46 ,
struct V_50 , V_116 ) ;
struct V_99 * V_100 ;
if ( ! V_51 -> V_72 -> V_117 ) {
F_4 ( L_34 ) ;
return F_21 ( - V_48 ) ;
}
V_100 = V_51 -> V_72 -> V_117 ( V_51 , V_46 , V_47 ) ;
if ( ! V_100 || F_38 ( V_100 ) )
return F_21 ( - V_25 ) ;
V_100 -> V_53 = V_51 ;
F_27 ( & V_100 -> V_102 , V_47 , & V_51 -> V_118 ) ;
F_27 ( & V_100 -> V_114 , L_22 ,
& V_51 -> V_119 ) ;
F_28 ( & V_100 -> V_114 , & V_100 -> V_102 ) ;
if ( V_51 -> V_72 -> V_120 )
V_51 -> V_72 -> V_120 ( V_100 ) ;
return & V_100 -> V_102 ;
}
static void F_78 (
struct V_45 * V_46 ,
struct V_1 * V_35 )
{
struct V_99 * V_100 = F_2 ( F_3 ( V_35 ) ,
struct V_99 , V_102 ) ;
F_32 ( & V_100 -> V_102 ) ;
F_33 ( V_35 ) ;
}
int F_79 ( struct V_50 * V_51 )
{
F_80 ( V_51 ) ;
F_81 ( V_51 ) ;
F_82 ( V_51 ) ;
F_83 ( V_51 ) ;
F_84 ( V_51 ) ;
F_85 ( V_51 ) ;
F_86 ( V_51 ) ;
F_87 ( V_51 ) ;
F_88 ( V_51 ) ;
F_89 ( V_51 ) ;
F_90 ( V_51 ) ;
F_91 ( V_51 ) ;
F_92 ( V_51 ) ;
F_93 ( V_51 ) ;
F_94 ( V_51 ) ;
F_95 ( V_51 ) ;
F_96 ( V_51 ) ;
F_97 ( V_51 ) ;
F_98 ( V_51 ) ;
F_99 ( V_51 ) ;
F_100 ( V_51 ) ;
return 0 ;
}
