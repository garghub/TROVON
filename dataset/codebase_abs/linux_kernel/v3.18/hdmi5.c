static int F_1 ( void )
{
int V_1 ;
F_2 ( L_1 ) ;
V_1 = F_3 ( & V_2 . V_3 -> V_4 ) ;
F_4 ( V_1 < 0 ) ;
if ( V_1 < 0 )
return V_1 ;
return 0 ;
}
static void F_5 ( void )
{
int V_1 ;
F_2 ( L_2 ) ;
V_1 = F_6 ( & V_2 . V_3 -> V_4 ) ;
F_4 ( V_1 < 0 && V_1 != - V_5 ) ;
}
static T_1 F_7 ( int V_6 , void * V_7 )
{
struct V_8 * V_9 = V_7 ;
T_2 V_10 ;
V_10 = F_8 ( V_9 ) ;
F_9 ( V_9 , V_10 ) ;
if ( ( V_10 & V_11 ) &&
V_10 & V_12 ) {
T_2 V_13 ;
F_10 ( V_9 , V_14 ) ;
V_13 = F_11 ( V_2 . V_15 . V_16 , V_17 ) ;
V_13 = F_12 ( V_13 , 1 , 15 , 15 ) ;
V_13 = F_12 ( V_13 , 0 , 14 , 7 ) ;
F_13 ( V_2 . V_15 . V_16 , V_17 , V_13 ) ;
F_9 ( V_9 , V_11 |
V_12 ) ;
F_10 ( V_9 , V_18 ) ;
F_14 ( V_2 . V_15 . V_16 , V_17 , 0 , 15 , 15 ) ;
} else if ( V_10 & V_11 ) {
F_10 ( V_9 , V_19 ) ;
} else if ( V_10 & V_12 ) {
F_10 ( V_9 , V_18 ) ;
}
return V_20 ;
}
static int F_15 ( void )
{
int V_1 ;
struct V_21 * V_22 ;
if ( V_2 . V_23 != NULL )
return 0 ;
V_22 = F_16 ( & V_2 . V_3 -> V_4 , L_3 ) ;
if ( F_17 ( V_22 ) ) {
F_18 ( L_4 ) ;
return F_19 ( V_22 ) ;
}
if ( F_20 ( V_22 ) ) {
V_1 = F_21 ( V_22 , 1800000 , 1800000 ) ;
if ( V_1 ) {
F_22 ( V_22 ) ;
F_23 ( L_5 ) ;
return V_1 ;
}
}
V_2 . V_23 = V_22 ;
return 0 ;
}
static int F_24 ( struct V_24 * V_25 )
{
int V_1 ;
V_1 = F_25 ( V_2 . V_23 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_1 () ;
if ( V_1 )
goto V_26;
F_26 ( V_27 ) ;
V_2 . V_28 = true ;
return 0 ;
V_26:
F_27 ( V_2 . V_23 ) ;
return V_1 ;
}
static void F_28 ( struct V_24 * V_25 )
{
V_2 . V_28 = false ;
F_5 () ;
F_27 ( V_2 . V_23 ) ;
}
static int F_29 ( struct V_24 * V_25 )
{
int V_1 ;
struct V_29 * V_30 ;
struct V_31 * V_32 = V_2 . V_33 . V_34 ;
unsigned long V_15 ;
V_1 = F_24 ( V_25 ) ;
if ( V_1 )
return V_1 ;
V_30 = & V_2 . V_35 . V_36 ;
F_2 ( L_6 , V_30 -> V_37 , V_30 -> V_38 ) ;
V_15 = V_30 -> V_39 / 1000 ;
F_30 ( & V_2 . V_40 , F_31 ( V_2 . V_41 ) , V_15 ) ;
F_32 ( & V_2 . V_9 , 0xffffffff ) ;
F_9 ( & V_2 . V_9 ,
F_8 ( & V_2 . V_9 ) ) ;
V_1 = F_33 ( & V_2 . V_40 , & V_2 . V_9 ) ;
if ( V_1 ) {
F_2 ( L_7 ) ;
goto V_42;
}
V_1 = F_34 ( & V_2 . V_15 , & V_2 . V_35 ) ;
if ( V_1 ) {
F_2 ( L_8 ) ;
goto V_43;
}
V_1 = F_10 ( & V_2 . V_9 , V_18 ) ;
if ( V_1 )
goto V_44;
F_35 ( & V_2 . V_45 , & V_2 . V_9 , & V_2 . V_35 ) ;
F_36 ( 0 ) ;
F_37 ( V_32 , V_30 ) ;
V_1 = F_38 ( & V_2 . V_9 ) ;
if ( V_1 )
goto V_46;
V_1 = F_39 ( V_32 ) ;
if ( V_1 )
goto V_47;
F_40 ( & V_2 . V_9 ,
V_11 | V_12 ) ;
return 0 ;
V_47:
F_41 ( & V_2 . V_9 ) ;
V_46:
F_10 ( & V_2 . V_9 , V_14 ) ;
V_44:
V_43:
F_42 ( & V_2 . V_40 , & V_2 . V_9 ) ;
V_42:
F_28 ( V_25 ) ;
return - V_48 ;
}
static void F_43 ( struct V_24 * V_25 )
{
struct V_31 * V_32 = V_2 . V_33 . V_34 ;
F_32 ( & V_2 . V_9 , 0xffffffff ) ;
F_44 ( V_32 ) ;
F_41 ( & V_2 . V_9 ) ;
F_10 ( & V_2 . V_9 , V_14 ) ;
F_42 ( & V_2 . V_40 , & V_2 . V_9 ) ;
F_28 ( V_25 ) ;
}
static int F_45 ( struct V_24 * V_25 ,
struct V_29 * V_36 )
{
struct V_24 * V_49 = & V_2 . V_33 ;
if ( ! F_46 ( V_49 -> V_50 , V_36 ) )
return - V_51 ;
return 0 ;
}
static void F_47 ( struct V_24 * V_25 ,
struct V_29 * V_36 )
{
F_48 ( & V_2 . V_52 ) ;
V_2 . V_35 . V_36 = * V_36 ;
F_49 ( V_36 -> V_39 ) ;
F_50 ( & V_2 . V_52 ) ;
}
static void F_51 ( struct V_24 * V_25 ,
struct V_29 * V_36 )
{
* V_36 = V_2 . V_35 . V_36 ;
}
static void F_52 ( struct V_53 * V_54 )
{
F_48 ( & V_2 . V_52 ) ;
if ( F_1 () ) {
F_50 ( & V_2 . V_52 ) ;
return;
}
F_53 ( & V_2 . V_9 , V_54 ) ;
F_54 ( & V_2 . V_40 , V_54 ) ;
F_55 ( & V_2 . V_15 , V_54 ) ;
F_56 ( & V_2 . V_45 , V_54 ) ;
F_5 () ;
F_50 ( & V_2 . V_52 ) ;
}
static int F_57 ( T_3 * V_55 , int V_56 )
{
int V_1 ;
int V_57 ;
F_48 ( & V_2 . V_52 ) ;
V_1 = F_1 () ;
F_58 ( V_1 ) ;
V_57 = F_59 ( V_2 . V_9 . V_16 , V_58 , 3 , 2 ) ;
F_14 ( V_2 . V_9 . V_16 , V_58 , 1 , 3 , 2 ) ;
V_1 = F_60 ( & V_2 . V_45 , V_55 , V_56 ) ;
F_14 ( V_2 . V_9 . V_16 , V_58 , V_57 , 3 , 2 ) ;
F_5 () ;
F_50 ( & V_2 . V_52 ) ;
return V_1 ;
}
static int F_61 ( struct V_24 * V_25 )
{
struct V_24 * V_49 = & V_2 . V_33 ;
int V_1 = 0 ;
F_2 ( L_9 ) ;
F_48 ( & V_2 . V_52 ) ;
if ( V_49 == NULL || V_49 -> V_34 == NULL ) {
F_18 ( L_10 ) ;
V_1 = - V_59 ;
goto V_60;
}
V_1 = F_29 ( V_25 ) ;
if ( V_1 ) {
F_18 ( L_11 ) ;
goto V_60;
}
F_50 ( & V_2 . V_52 ) ;
return 0 ;
V_60:
F_50 ( & V_2 . V_52 ) ;
return V_1 ;
}
static void F_62 ( struct V_24 * V_25 )
{
F_2 ( L_12 ) ;
F_48 ( & V_2 . V_52 ) ;
F_43 ( V_25 ) ;
F_50 ( & V_2 . V_52 ) ;
}
static int F_63 ( struct V_24 * V_25 )
{
int V_1 = 0 ;
F_2 ( L_13 ) ;
F_48 ( & V_2 . V_52 ) ;
V_1 = F_24 ( V_25 ) ;
if ( V_1 ) {
F_18 ( L_11 ) ;
goto V_60;
}
F_50 ( & V_2 . V_52 ) ;
return 0 ;
V_60:
F_50 ( & V_2 . V_52 ) ;
return V_1 ;
}
static void F_64 ( struct V_24 * V_25 )
{
F_2 ( L_14 ) ;
F_48 ( & V_2 . V_52 ) ;
F_28 ( V_25 ) ;
F_50 ( & V_2 . V_52 ) ;
}
static int F_65 ( struct V_61 * V_3 )
{
struct V_62 * V_62 ;
V_62 = F_66 ( & V_3 -> V_4 , L_15 ) ;
if ( F_17 ( V_62 ) ) {
F_18 ( L_16 ) ;
return F_19 ( V_62 ) ;
}
V_2 . V_41 = V_62 ;
return 0 ;
}
static int F_67 ( struct V_24 * V_25 ,
struct V_24 * V_63 )
{
struct V_31 * V_32 ;
int V_1 ;
V_1 = F_15 () ;
if ( V_1 )
return V_1 ;
V_32 = F_68 ( V_25 -> V_50 ) ;
if ( ! V_32 )
return - V_59 ;
V_1 = F_69 ( V_32 , V_25 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_70 ( V_25 , V_63 ) ;
if ( V_1 ) {
F_18 ( L_17 ,
V_63 -> V_64 ) ;
F_71 ( V_32 , V_25 ) ;
return V_1 ;
}
return 0 ;
}
static void F_72 ( struct V_24 * V_25 ,
struct V_24 * V_63 )
{
F_4 ( V_63 != V_25 -> V_63 ) ;
if ( V_63 != V_25 -> V_63 )
return;
F_73 ( V_25 ) ;
if ( V_25 -> V_34 )
F_71 ( V_25 -> V_34 , V_25 ) ;
}
static int F_74 ( struct V_24 * V_25 ,
T_3 * V_65 , int V_56 )
{
bool V_66 ;
int V_1 ;
V_66 = V_2 . V_28 == false ;
if ( V_66 ) {
V_1 = F_63 ( V_25 ) ;
if ( V_1 )
return V_1 ;
}
V_1 = F_57 ( V_65 , V_56 ) ;
if ( V_66 )
F_64 ( V_25 ) ;
return V_1 ;
}
static int F_75 ( struct V_24 * V_25 )
{
int V_1 ;
F_48 ( & V_2 . V_52 ) ;
if ( ! F_76 ( V_2 . V_35 . V_67 ) ) {
V_1 = - V_68 ;
goto V_69;
}
V_1 = F_77 ( & V_2 . V_9 , true ) ;
if ( V_1 )
goto V_69;
F_50 ( & V_2 . V_52 ) ;
return 0 ;
V_69:
F_50 ( & V_2 . V_52 ) ;
return V_1 ;
}
static void F_78 ( struct V_24 * V_25 )
{
F_77 ( & V_2 . V_9 , false ) ;
}
static int F_79 ( struct V_24 * V_25 )
{
return F_80 ( & V_2 . V_9 , true ) ;
}
static void F_81 ( struct V_24 * V_25 )
{
F_80 ( & V_2 . V_9 , false ) ;
}
static bool F_82 ( struct V_24 * V_25 )
{
bool V_1 ;
F_48 ( & V_2 . V_52 ) ;
V_1 = F_76 ( V_2 . V_35 . V_67 ) ;
F_50 ( & V_2 . V_52 ) ;
return V_1 ;
}
static int F_83 ( struct V_24 * V_25 ,
struct V_70 * V_71 )
{
int V_1 ;
T_2 V_72 = V_2 . V_35 . V_36 . V_39 ;
F_48 ( & V_2 . V_52 ) ;
if ( ! F_76 ( V_2 . V_35 . V_67 ) ) {
V_1 = - V_68 ;
goto V_69;
}
V_1 = F_84 ( & V_2 . V_45 , & V_2 . V_9 , V_71 , V_72 ) ;
if ( V_1 )
goto V_69;
F_50 ( & V_2 . V_52 ) ;
return 0 ;
V_69:
F_50 ( & V_2 . V_52 ) ;
return V_1 ;
}
static int F_75 ( struct V_24 * V_25 )
{
return - V_68 ;
}
static void F_78 ( struct V_24 * V_25 )
{
}
static int F_79 ( struct V_24 * V_25 )
{
return - V_68 ;
}
static void F_81 ( struct V_24 * V_25 )
{
}
static bool F_82 ( struct V_24 * V_25 )
{
return false ;
}
static int F_83 ( struct V_24 * V_25 ,
struct V_70 * V_71 )
{
return - V_68 ;
}
static int F_85 ( struct V_24 * V_25 ,
const struct V_73 * V_74 )
{
V_2 . V_35 . V_75 = * V_74 ;
return 0 ;
}
static int F_86 ( struct V_24 * V_25 ,
bool V_76 )
{
V_2 . V_35 . V_67 = V_76 ? V_77 : V_78 ;
return 0 ;
}
static void F_87 ( struct V_61 * V_3 )
{
struct V_24 * V_49 = & V_2 . V_33 ;
V_49 -> V_4 = & V_3 -> V_4 ;
V_49 -> V_79 = V_80 ;
V_49 -> V_81 = V_82 ;
V_49 -> V_64 = L_18 ;
V_49 -> V_50 = V_83 ;
V_49 -> V_84 . V_2 = & V_85 ;
V_49 -> V_86 = V_87 ;
F_88 ( V_49 ) ;
}
static void T_4 F_89 ( struct V_61 * V_3 )
{
struct V_24 * V_49 = & V_2 . V_33 ;
F_90 ( V_49 ) ;
}
static int F_91 ( struct V_61 * V_3 )
{
struct V_88 * V_89 = V_3 -> V_4 . V_90 ;
struct V_88 * V_91 ;
int V_1 ;
V_91 = F_92 ( V_89 ) ;
if ( ! V_91 )
return 0 ;
V_1 = F_93 ( V_3 , V_91 , & V_2 . V_15 ) ;
if ( V_1 )
goto V_69;
F_94 ( V_91 ) ;
return 0 ;
V_69:
F_94 ( V_91 ) ;
return V_1 ;
}
static int F_95 ( struct V_61 * V_3 )
{
int V_1 ;
int V_6 ;
V_2 . V_3 = V_3 ;
F_96 ( & V_2 . V_52 ) ;
if ( V_3 -> V_4 . V_90 ) {
V_1 = F_91 ( V_3 ) ;
if ( V_1 )
return V_1 ;
}
V_1 = F_97 ( V_3 , & V_2 . V_9 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_98 ( V_3 , & V_2 . V_40 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_99 ( V_3 , & V_2 . V_15 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_100 ( V_3 , & V_2 . V_45 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_65 ( V_3 ) ;
if ( V_1 ) {
F_18 ( L_19 ) ;
return V_1 ;
}
V_6 = F_101 ( V_3 , 0 ) ;
if ( V_6 < 0 ) {
F_18 ( L_20 ) ;
return - V_59 ;
}
V_1 = F_102 ( & V_3 -> V_4 , V_6 ,
NULL , F_7 ,
V_92 , L_21 , & V_2 . V_9 ) ;
if ( V_1 ) {
F_18 ( L_22 ) ;
return V_1 ;
}
F_103 ( & V_3 -> V_4 ) ;
F_87 ( V_3 ) ;
F_104 ( L_23 , F_52 ) ;
return 0 ;
}
static int T_4 F_105 ( struct V_61 * V_3 )
{
F_89 ( V_3 ) ;
F_106 ( & V_3 -> V_4 ) ;
return 0 ;
}
static int F_107 ( struct V_93 * V_4 )
{
F_108 ( V_2 . V_41 ) ;
F_109 () ;
return 0 ;
}
static int F_110 ( struct V_93 * V_4 )
{
int V_1 ;
V_1 = F_111 () ;
if ( V_1 < 0 )
return V_1 ;
F_112 ( V_2 . V_41 ) ;
return 0 ;
}
int T_5 F_113 ( void )
{
return F_114 ( & V_94 ) ;
}
void T_4 F_115 ( void )
{
F_116 ( & V_94 ) ;
}
