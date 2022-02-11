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
struct V_21 * V_22 ;
if ( V_2 . V_23 != NULL )
return 0 ;
V_22 = F_16 ( & V_2 . V_3 -> V_4 , L_3 ) ;
if ( F_17 ( V_22 ) ) {
F_18 ( L_4 ) ;
return F_19 ( V_22 ) ;
}
V_2 . V_23 = V_22 ;
return 0 ;
}
static int F_20 ( struct V_24 * V_25 )
{
int V_1 ;
V_1 = F_21 ( V_2 . V_23 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_1 () ;
if ( V_1 )
goto V_26;
F_22 ( V_27 ) ;
V_2 . V_28 = true ;
return 0 ;
V_26:
F_23 ( V_2 . V_23 ) ;
return V_1 ;
}
static void F_24 ( struct V_24 * V_25 )
{
V_2 . V_28 = false ;
F_5 () ;
F_23 ( V_2 . V_23 ) ;
}
static int F_25 ( struct V_24 * V_25 )
{
int V_1 ;
struct V_29 * V_30 ;
struct V_31 * V_32 = V_2 . V_33 . V_34 ;
struct V_35 V_36 = { 0 } ;
V_1 = F_20 ( V_25 ) ;
if ( V_1 )
return V_1 ;
V_30 = & V_2 . V_37 . V_38 ;
F_2 ( L_5 , V_30 -> V_39 , V_30 -> V_40 ) ;
F_26 ( & V_2 . V_41 , V_30 -> V_42 , & V_36 ) ;
F_27 ( & V_2 . V_9 , 0xffffffff ) ;
F_9 ( & V_2 . V_9 ,
F_8 ( & V_2 . V_9 ) ) ;
V_1 = F_28 ( & V_2 . V_41 . V_41 ) ;
if ( V_1 ) {
F_18 ( L_6 ) ;
goto V_43;
}
V_1 = F_29 ( & V_2 . V_41 . V_41 , & V_36 ) ;
if ( V_1 ) {
F_18 ( L_7 ) ;
goto V_44;
}
V_1 = F_30 ( & V_2 . V_15 , V_36 . V_45 ,
V_36 . V_46 [ 0 ] ) ;
if ( V_1 ) {
F_2 ( L_8 ) ;
goto V_47;
}
V_1 = F_10 ( & V_2 . V_9 , V_18 ) ;
if ( V_1 )
goto V_48;
F_31 ( & V_2 . V_49 , & V_2 . V_9 , & V_2 . V_37 ) ;
F_32 ( 0 ) ;
F_33 ( V_32 , V_30 ) ;
V_1 = F_34 ( & V_2 . V_9 ) ;
if ( V_1 )
goto V_50;
V_1 = F_35 ( V_32 ) ;
if ( V_1 )
goto V_51;
F_36 ( & V_2 . V_9 ,
V_11 | V_12 ) ;
return 0 ;
V_51:
F_37 ( & V_2 . V_9 ) ;
V_50:
F_10 ( & V_2 . V_9 , V_14 ) ;
V_48:
V_47:
V_44:
F_38 ( & V_2 . V_41 . V_41 ) ;
V_43:
F_24 ( V_25 ) ;
return - V_52 ;
}
static void F_39 ( struct V_24 * V_25 )
{
struct V_31 * V_32 = V_2 . V_33 . V_34 ;
F_27 ( & V_2 . V_9 , 0xffffffff ) ;
F_40 ( V_32 ) ;
F_37 ( & V_2 . V_9 ) ;
F_10 ( & V_2 . V_9 , V_14 ) ;
F_38 ( & V_2 . V_41 . V_41 ) ;
F_24 ( V_25 ) ;
}
static int F_41 ( struct V_24 * V_25 ,
struct V_29 * V_38 )
{
struct V_24 * V_53 = & V_2 . V_33 ;
if ( V_38 -> V_54 )
return - V_55 ;
if ( ! F_42 ( V_53 -> V_56 , V_38 ) )
return - V_55 ;
return 0 ;
}
static void F_43 ( struct V_24 * V_25 ,
struct V_29 * V_38 )
{
F_44 ( & V_2 . V_57 ) ;
V_2 . V_37 . V_38 = * V_38 ;
F_45 ( V_38 -> V_42 ) ;
F_46 ( & V_2 . V_57 ) ;
}
static void F_47 ( struct V_24 * V_25 ,
struct V_29 * V_38 )
{
* V_38 = V_2 . V_37 . V_38 ;
}
static void F_48 ( struct V_58 * V_59 )
{
F_44 ( & V_2 . V_57 ) ;
if ( F_1 () ) {
F_46 ( & V_2 . V_57 ) ;
return;
}
F_49 ( & V_2 . V_9 , V_59 ) ;
F_50 ( & V_2 . V_41 , V_59 ) ;
F_51 ( & V_2 . V_15 , V_59 ) ;
F_52 ( & V_2 . V_49 , V_59 ) ;
F_5 () ;
F_46 ( & V_2 . V_57 ) ;
}
static int F_53 ( T_3 * V_60 , int V_61 )
{
int V_1 ;
int V_62 ;
F_44 ( & V_2 . V_57 ) ;
V_1 = F_1 () ;
F_54 ( V_1 ) ;
V_62 = F_55 ( V_2 . V_9 . V_16 , V_63 , 3 , 2 ) ;
F_14 ( V_2 . V_9 . V_16 , V_63 , 1 , 3 , 2 ) ;
V_1 = F_56 ( & V_2 . V_49 , V_60 , V_61 ) ;
F_14 ( V_2 . V_9 . V_16 , V_63 , V_62 , 3 , 2 ) ;
F_5 () ;
F_46 ( & V_2 . V_57 ) ;
return V_1 ;
}
static void F_57 ( struct V_64 * V_65 )
{
F_14 ( V_2 . V_9 . V_16 , V_63 , 1 , 3 , 2 ) ;
F_58 ( & V_65 -> V_9 , true ) ;
F_59 ( & V_65 -> V_9 , true ) ;
}
static void F_60 ( struct V_64 * V_65 )
{
F_59 ( & V_65 -> V_9 , false ) ;
F_58 ( & V_65 -> V_9 , false ) ;
F_14 ( V_65 -> V_9 . V_16 , V_63 , V_65 -> V_66 , 3 , 2 ) ;
}
static int F_61 ( struct V_24 * V_25 )
{
struct V_24 * V_53 = & V_2 . V_33 ;
unsigned long V_67 ;
int V_1 = 0 ;
F_2 ( L_9 ) ;
F_44 ( & V_2 . V_57 ) ;
if ( V_53 -> V_34 == NULL ) {
F_18 ( L_10 ) ;
V_1 = - V_68 ;
goto V_69;
}
V_1 = F_25 ( V_25 ) ;
if ( V_1 ) {
F_18 ( L_11 ) ;
goto V_69;
}
if ( V_2 . V_70 ) {
V_1 = F_62 ( & V_2 . V_49 , & V_2 . V_9 , & V_2 . V_71 ,
V_2 . V_37 . V_38 . V_42 ) ;
if ( V_1 ) {
F_18 ( L_12 , V_1 ) ;
V_2 . V_72 ( & V_2 . V_3 -> V_4 ) ;
V_2 . V_70 = false ;
}
}
F_63 ( & V_2 . V_73 , V_67 ) ;
if ( V_2 . V_70 && V_2 . V_74 )
F_57 ( & V_2 ) ;
V_2 . V_75 = true ;
F_64 ( & V_2 . V_73 , V_67 ) ;
F_46 ( & V_2 . V_57 ) ;
return 0 ;
V_69:
F_46 ( & V_2 . V_57 ) ;
return V_1 ;
}
static void F_65 ( struct V_24 * V_25 )
{
unsigned long V_67 ;
F_2 ( L_13 ) ;
F_44 ( & V_2 . V_57 ) ;
F_63 ( & V_2 . V_73 , V_67 ) ;
F_60 ( & V_2 ) ;
V_2 . V_75 = false ;
F_64 ( & V_2 . V_73 , V_67 ) ;
F_39 ( V_25 ) ;
F_46 ( & V_2 . V_57 ) ;
}
static int F_66 ( struct V_24 * V_25 )
{
int V_1 = 0 ;
F_2 ( L_14 ) ;
F_44 ( & V_2 . V_57 ) ;
V_1 = F_20 ( V_25 ) ;
if ( V_1 ) {
F_18 ( L_11 ) ;
goto V_69;
}
F_46 ( & V_2 . V_57 ) ;
return 0 ;
V_69:
F_46 ( & V_2 . V_57 ) ;
return V_1 ;
}
static void F_67 ( struct V_24 * V_25 )
{
F_2 ( L_15 ) ;
F_44 ( & V_2 . V_57 ) ;
F_24 ( V_25 ) ;
F_46 ( & V_2 . V_57 ) ;
}
static int F_68 ( struct V_24 * V_25 ,
struct V_24 * V_76 )
{
struct V_31 * V_32 ;
int V_1 ;
V_1 = F_15 () ;
if ( V_1 )
return V_1 ;
V_32 = F_69 ( V_25 -> V_56 ) ;
if ( ! V_32 )
return - V_68 ;
V_1 = F_70 ( V_32 , V_25 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_71 ( V_25 , V_76 ) ;
if ( V_1 ) {
F_18 ( L_16 ,
V_76 -> V_77 ) ;
F_72 ( V_32 , V_25 ) ;
return V_1 ;
}
return 0 ;
}
static void F_73 ( struct V_24 * V_25 ,
struct V_24 * V_76 )
{
F_4 ( V_76 != V_25 -> V_76 ) ;
if ( V_76 != V_25 -> V_76 )
return;
F_74 ( V_25 ) ;
if ( V_25 -> V_34 )
F_72 ( V_25 -> V_34 , V_25 ) ;
}
static int F_75 ( struct V_24 * V_25 ,
T_3 * V_78 , int V_61 )
{
bool V_79 ;
int V_1 ;
V_79 = V_2 . V_28 == false ;
if ( V_79 ) {
V_1 = F_66 ( V_25 ) ;
if ( V_1 )
return V_1 ;
}
V_1 = F_53 ( V_78 , V_61 ) ;
if ( V_79 )
F_67 ( V_25 ) ;
return V_1 ;
}
static int F_76 ( struct V_24 * V_25 ,
const struct V_80 * V_81 )
{
V_2 . V_37 . V_82 = * V_81 ;
return 0 ;
}
static int F_77 ( struct V_24 * V_25 ,
bool V_83 )
{
V_2 . V_37 . V_84 = V_83 ? V_85 : V_86 ;
return 0 ;
}
static void F_78 ( struct V_87 * V_3 )
{
struct V_24 * V_53 = & V_2 . V_33 ;
V_53 -> V_4 = & V_3 -> V_4 ;
V_53 -> V_88 = V_89 ;
V_53 -> V_90 = V_91 ;
V_53 -> V_77 = L_17 ;
V_53 -> V_56 = V_92 ;
V_53 -> V_93 . V_2 = & V_94 ;
V_53 -> V_95 = V_96 ;
F_79 ( V_53 ) ;
}
static void F_80 ( struct V_87 * V_3 )
{
struct V_24 * V_53 = & V_2 . V_33 ;
F_81 ( V_53 ) ;
}
static int F_82 ( struct V_87 * V_3 )
{
struct V_97 * V_98 = V_3 -> V_4 . V_99 ;
struct V_97 * V_100 ;
int V_1 ;
V_100 = F_83 ( V_98 ) ;
if ( ! V_100 )
return 0 ;
V_1 = F_84 ( V_3 , V_100 , & V_2 . V_15 ) ;
if ( V_1 )
goto V_101;
F_85 ( V_100 ) ;
return 0 ;
V_101:
F_85 ( V_100 ) ;
return V_1 ;
}
static int F_86 ( struct V_102 * V_4 ,
void (* F_87)( struct V_102 * V_4 ) )
{
struct V_64 * V_65 = F_88 ( V_4 ) ;
int V_103 = 0 ;
F_44 ( & V_65 -> V_57 ) ;
if ( ! F_89 ( & V_65 -> V_37 ) || ! V_65 -> V_75 ) {
V_103 = - V_104 ;
goto V_53;
}
V_65 -> V_72 = F_87 ;
V_53:
F_46 ( & V_65 -> V_57 ) ;
return V_103 ;
}
static int F_90 ( struct V_102 * V_4 )
{
struct V_64 * V_65 = F_88 ( V_4 ) ;
F_44 ( & V_65 -> V_57 ) ;
V_65 -> V_72 = NULL ;
V_65 -> V_70 = false ;
V_65 -> V_74 = false ;
F_46 ( & V_65 -> V_57 ) ;
return 0 ;
}
static int F_91 ( struct V_102 * V_4 )
{
struct V_64 * V_65 = F_88 ( V_4 ) ;
unsigned long V_67 ;
F_4 ( ! F_89 ( & V_65 -> V_37 ) ) ;
F_63 ( & V_65 -> V_73 , V_67 ) ;
if ( V_65 -> V_75 )
F_57 ( V_65 ) ;
V_65 -> V_74 = true ;
F_64 ( & V_65 -> V_73 , V_67 ) ;
return 0 ;
}
static void F_92 ( struct V_102 * V_4 )
{
struct V_64 * V_65 = F_88 ( V_4 ) ;
unsigned long V_67 ;
F_4 ( ! F_89 ( & V_65 -> V_37 ) ) ;
F_63 ( & V_65 -> V_73 , V_67 ) ;
if ( V_65 -> V_75 )
F_60 ( V_65 ) ;
V_65 -> V_74 = false ;
F_64 ( & V_65 -> V_73 , V_67 ) ;
}
static int F_93 ( struct V_102 * V_4 ,
struct V_105 * V_106 )
{
struct V_64 * V_65 = F_88 ( V_4 ) ;
int V_103 ;
F_44 ( & V_65 -> V_57 ) ;
if ( ! F_89 ( & V_65 -> V_37 ) || ! V_65 -> V_75 ) {
V_103 = - V_104 ;
goto V_53;
}
V_103 = F_62 ( & V_65 -> V_49 , & V_65 -> V_9 , V_106 ,
V_65 -> V_37 . V_38 . V_42 ) ;
if ( ! V_103 ) {
V_65 -> V_70 = true ;
V_65 -> V_71 = * V_106 ;
}
V_53:
F_46 ( & V_65 -> V_57 ) ;
return V_103 ;
}
static int F_94 ( struct V_102 * V_4 )
{
struct V_107 V_108 = {
. V_4 = V_4 ,
. V_109 = F_95 () ,
. V_110 = F_96 ( & V_2 . V_9 ) ,
. V_93 = & V_111 ,
} ;
V_2 . V_112 = F_97 (
V_4 , L_18 , V_113 ,
& V_108 , sizeof( V_108 ) ) ;
if ( F_17 ( V_2 . V_112 ) )
return F_19 ( V_2 . V_112 ) ;
F_1 () ;
V_2 . V_66 =
F_55 ( V_2 . V_9 . V_16 , V_63 , 3 , 2 ) ;
F_5 () ;
return 0 ;
}
static int F_98 ( struct V_102 * V_4 , struct V_102 * V_114 , void * V_7 )
{
struct V_87 * V_3 = F_99 ( V_4 ) ;
int V_1 ;
int V_6 ;
V_2 . V_3 = V_3 ;
F_100 ( & V_3 -> V_4 , & V_2 ) ;
F_101 ( & V_2 . V_57 ) ;
F_102 ( & V_2 . V_73 ) ;
if ( V_3 -> V_4 . V_99 ) {
V_1 = F_82 ( V_3 ) ;
if ( V_1 )
return V_1 ;
}
V_1 = F_103 ( V_3 , & V_2 . V_9 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_104 ( V_3 , & V_2 . V_41 , & V_2 . V_9 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_105 ( V_3 , & V_2 . V_15 ) ;
if ( V_1 )
goto V_101;
V_1 = F_106 ( V_3 , & V_2 . V_49 ) ;
if ( V_1 )
goto V_101;
V_6 = F_107 ( V_3 , 0 ) ;
if ( V_6 < 0 ) {
F_18 ( L_19 ) ;
V_1 = - V_68 ;
goto V_101;
}
V_1 = F_108 ( & V_3 -> V_4 , V_6 ,
NULL , F_7 ,
V_115 , L_20 , & V_2 . V_9 ) ;
if ( V_1 ) {
F_18 ( L_21 ) ;
goto V_101;
}
F_109 ( & V_3 -> V_4 ) ;
F_78 ( V_3 ) ;
V_1 = F_94 ( & V_3 -> V_4 ) ;
if ( V_1 ) {
F_18 ( L_22 , V_1 ) ;
F_80 ( V_3 ) ;
F_110 ( & V_3 -> V_4 ) ;
return V_1 ;
}
F_111 ( L_23 , F_48 ) ;
return 0 ;
V_101:
F_112 ( & V_2 . V_41 ) ;
return V_1 ;
}
static void F_113 ( struct V_102 * V_4 , struct V_102 * V_114 , void * V_7 )
{
struct V_87 * V_3 = F_99 ( V_4 ) ;
if ( V_2 . V_112 )
F_114 ( V_2 . V_112 ) ;
F_80 ( V_3 ) ;
F_112 ( & V_2 . V_41 ) ;
F_110 ( & V_3 -> V_4 ) ;
}
static int F_115 ( struct V_87 * V_3 )
{
return F_116 ( & V_3 -> V_4 , & V_116 ) ;
}
static int F_117 ( struct V_87 * V_3 )
{
F_118 ( & V_3 -> V_4 , & V_116 ) ;
return 0 ;
}
static int F_119 ( struct V_102 * V_4 )
{
F_120 () ;
return 0 ;
}
static int F_121 ( struct V_102 * V_4 )
{
int V_1 ;
V_1 = F_122 () ;
if ( V_1 < 0 )
return V_1 ;
return 0 ;
}
int T_4 F_123 ( void )
{
return F_124 ( & V_117 ) ;
}
void F_125 ( void )
{
F_126 ( & V_117 ) ;
}
