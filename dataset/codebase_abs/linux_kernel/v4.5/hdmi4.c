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
F_10 ( V_9 , V_13 ) ;
F_9 ( V_9 , V_11 |
V_12 ) ;
F_10 ( V_9 , V_14 ) ;
} else if ( V_10 & V_11 ) {
F_10 ( V_9 , V_15 ) ;
} else if ( V_10 & V_12 ) {
F_10 ( V_9 , V_14 ) ;
}
return V_16 ;
}
static int F_11 ( void )
{
int V_1 ;
struct V_17 * V_18 ;
if ( V_2 . V_19 != NULL )
return 0 ;
V_18 = F_12 ( & V_2 . V_3 -> V_4 , L_3 ) ;
if ( F_13 ( V_18 ) ) {
if ( F_14 ( V_18 ) != - V_20 )
F_15 ( L_4 ) ;
return F_14 ( V_18 ) ;
}
if ( F_16 ( V_18 ) ) {
V_1 = F_17 ( V_18 , 1800000 , 1800000 ) ;
if ( V_1 ) {
F_18 ( V_18 ) ;
F_19 ( L_5 ) ;
return V_1 ;
}
}
V_2 . V_19 = V_18 ;
return 0 ;
}
static int F_20 ( struct V_21 * V_22 )
{
int V_1 ;
V_1 = F_21 ( V_2 . V_19 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_1 () ;
if ( V_1 )
goto V_23;
F_22 ( V_24 ) ;
V_2 . V_25 = true ;
return 0 ;
V_23:
F_23 ( V_2 . V_19 ) ;
return V_1 ;
}
static void F_24 ( struct V_21 * V_22 )
{
V_2 . V_25 = false ;
F_5 () ;
F_23 ( V_2 . V_19 ) ;
}
static int F_25 ( struct V_21 * V_22 )
{
int V_1 ;
struct V_26 * V_27 ;
struct V_28 * V_29 = V_2 . V_30 . V_31 ;
struct V_8 * V_9 = & V_2 . V_9 ;
struct V_32 V_33 = { 0 } ;
V_1 = F_20 ( V_22 ) ;
if ( V_1 )
return V_1 ;
F_26 ( V_9 , 0xffffffff ) ;
F_9 ( V_9 , 0xffffffff ) ;
V_27 = & V_2 . V_34 . V_35 ;
F_2 ( L_6 , V_27 -> V_36 , V_27 -> V_37 ) ;
F_27 ( & V_2 . V_38 , V_27 -> V_39 , & V_33 ) ;
V_1 = F_28 ( & V_2 . V_38 . V_38 ) ;
if ( V_1 ) {
F_15 ( L_7 ) ;
goto V_40;
}
V_1 = F_29 ( & V_2 . V_38 . V_38 , & V_33 ) ;
if ( V_1 ) {
F_15 ( L_8 ) ;
goto V_41;
}
V_1 = F_30 ( & V_2 . V_42 , V_33 . V_43 ,
V_33 . V_44 [ 0 ] ) ;
if ( V_1 ) {
F_2 ( L_9 ) ;
goto V_45;
}
V_1 = F_10 ( V_9 , V_14 ) ;
if ( V_1 )
goto V_46;
F_31 ( & V_2 . V_47 , & V_2 . V_9 , & V_2 . V_34 ) ;
F_32 ( 0 ) ;
F_33 ( V_29 , V_27 ) ;
V_1 = F_34 ( & V_2 . V_9 ) ;
if ( V_1 )
goto V_48;
V_1 = F_35 ( V_29 ) ;
if ( V_1 )
goto V_49;
F_36 ( V_9 ,
V_11 | V_12 ) ;
return 0 ;
V_49:
F_37 ( & V_2 . V_9 ) ;
V_48:
F_10 ( & V_2 . V_9 , V_13 ) ;
V_46:
V_45:
V_41:
F_38 ( & V_2 . V_38 . V_38 ) ;
V_40:
F_24 ( V_22 ) ;
return - V_50 ;
}
static void F_39 ( struct V_21 * V_22 )
{
struct V_28 * V_29 = V_2 . V_30 . V_31 ;
F_26 ( & V_2 . V_9 , 0xffffffff ) ;
F_40 ( V_29 ) ;
F_37 ( & V_2 . V_9 ) ;
F_10 ( & V_2 . V_9 , V_13 ) ;
F_38 ( & V_2 . V_38 . V_38 ) ;
F_24 ( V_22 ) ;
}
static int F_41 ( struct V_21 * V_22 ,
struct V_26 * V_35 )
{
struct V_21 * V_51 = & V_2 . V_30 ;
if ( ! F_42 ( V_51 -> V_52 , V_35 ) )
return - V_53 ;
return 0 ;
}
static void F_43 ( struct V_21 * V_22 ,
struct V_26 * V_35 )
{
F_44 ( & V_2 . V_54 ) ;
V_2 . V_34 . V_35 = * V_35 ;
F_45 ( V_35 -> V_39 ) ;
F_46 ( & V_2 . V_54 ) ;
}
static void F_47 ( struct V_21 * V_22 ,
struct V_26 * V_35 )
{
* V_35 = V_2 . V_34 . V_35 ;
}
static void F_48 ( struct V_55 * V_56 )
{
F_44 ( & V_2 . V_54 ) ;
if ( F_1 () ) {
F_46 ( & V_2 . V_54 ) ;
return;
}
F_49 ( & V_2 . V_9 , V_56 ) ;
F_50 ( & V_2 . V_38 , V_56 ) ;
F_51 ( & V_2 . V_42 , V_56 ) ;
F_52 ( & V_2 . V_47 , V_56 ) ;
F_5 () ;
F_46 ( & V_2 . V_54 ) ;
}
static int F_53 ( T_3 * V_57 , int V_58 )
{
int V_1 ;
F_44 ( & V_2 . V_54 ) ;
V_1 = F_1 () ;
F_54 ( V_1 ) ;
V_1 = F_55 ( & V_2 . V_47 , V_57 , V_58 ) ;
F_5 () ;
F_46 ( & V_2 . V_54 ) ;
return V_1 ;
}
static void F_56 ( struct V_59 * V_60 )
{
F_57 ( & V_60 -> V_9 , true ) ;
F_58 ( & V_60 -> V_47 , & V_60 -> V_9 ) ;
}
static void F_59 ( struct V_59 * V_60 )
{
F_60 ( & V_60 -> V_47 , & V_60 -> V_9 ) ;
F_57 ( & V_60 -> V_9 , false ) ;
}
static int F_61 ( struct V_21 * V_22 )
{
struct V_21 * V_51 = & V_2 . V_30 ;
unsigned long V_61 ;
int V_1 = 0 ;
F_2 ( L_10 ) ;
F_44 ( & V_2 . V_54 ) ;
if ( V_51 -> V_31 == NULL ) {
F_15 ( L_11 ) ;
V_1 = - V_62 ;
goto V_63;
}
V_1 = F_25 ( V_22 ) ;
if ( V_1 ) {
F_15 ( L_12 ) ;
goto V_63;
}
if ( V_2 . V_64 ) {
V_1 = F_62 ( & V_2 . V_47 , & V_2 . V_9 , & V_2 . V_65 ,
V_2 . V_34 . V_35 . V_39 ) ;
if ( V_1 ) {
F_15 ( L_13 , V_1 ) ;
V_2 . V_66 ( & V_2 . V_3 -> V_4 ) ;
V_2 . V_64 = false ;
}
}
F_63 ( & V_2 . V_67 , V_61 ) ;
if ( V_2 . V_64 && V_2 . V_68 )
F_56 ( & V_2 ) ;
V_2 . V_69 = true ;
F_64 ( & V_2 . V_67 , V_61 ) ;
F_46 ( & V_2 . V_54 ) ;
return 0 ;
V_63:
F_46 ( & V_2 . V_54 ) ;
return V_1 ;
}
static void F_65 ( struct V_21 * V_22 )
{
unsigned long V_61 ;
F_2 ( L_14 ) ;
F_44 ( & V_2 . V_54 ) ;
F_63 ( & V_2 . V_67 , V_61 ) ;
F_59 ( & V_2 ) ;
V_2 . V_69 = false ;
F_64 ( & V_2 . V_67 , V_61 ) ;
F_39 ( V_22 ) ;
F_46 ( & V_2 . V_54 ) ;
}
static int F_66 ( struct V_21 * V_22 )
{
int V_1 = 0 ;
F_2 ( L_15 ) ;
F_44 ( & V_2 . V_54 ) ;
V_1 = F_20 ( V_22 ) ;
if ( V_1 ) {
F_15 ( L_12 ) ;
goto V_63;
}
F_46 ( & V_2 . V_54 ) ;
return 0 ;
V_63:
F_46 ( & V_2 . V_54 ) ;
return V_1 ;
}
static void F_67 ( struct V_21 * V_22 )
{
F_2 ( L_16 ) ;
F_44 ( & V_2 . V_54 ) ;
F_24 ( V_22 ) ;
F_46 ( & V_2 . V_54 ) ;
}
static int F_68 ( struct V_21 * V_22 ,
struct V_21 * V_70 )
{
struct V_28 * V_29 ;
int V_1 ;
V_1 = F_11 () ;
if ( V_1 )
return V_1 ;
V_29 = F_69 ( V_22 -> V_52 ) ;
if ( ! V_29 )
return - V_62 ;
V_1 = F_70 ( V_29 , V_22 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_71 ( V_22 , V_70 ) ;
if ( V_1 ) {
F_15 ( L_17 ,
V_70 -> V_71 ) ;
F_72 ( V_29 , V_22 ) ;
return V_1 ;
}
return 0 ;
}
static void F_73 ( struct V_21 * V_22 ,
struct V_21 * V_70 )
{
F_4 ( V_70 != V_22 -> V_70 ) ;
if ( V_70 != V_22 -> V_70 )
return;
F_74 ( V_22 ) ;
if ( V_22 -> V_31 )
F_72 ( V_22 -> V_31 , V_22 ) ;
}
static int F_75 ( struct V_21 * V_22 ,
T_3 * V_72 , int V_58 )
{
bool V_73 ;
int V_1 ;
V_73 = V_2 . V_25 == false ;
if ( V_73 ) {
V_1 = F_66 ( V_22 ) ;
if ( V_1 )
return V_1 ;
}
V_1 = F_53 ( V_72 , V_58 ) ;
if ( V_73 )
F_67 ( V_22 ) ;
return V_1 ;
}
static int F_76 ( struct V_21 * V_22 ,
const struct V_74 * V_75 )
{
V_2 . V_34 . V_76 = * V_75 ;
return 0 ;
}
static int F_77 ( struct V_21 * V_22 ,
bool V_77 )
{
V_2 . V_34 . V_78 = V_77 ? V_79 : V_80 ;
return 0 ;
}
static void F_78 ( struct V_81 * V_3 )
{
struct V_21 * V_51 = & V_2 . V_30 ;
V_51 -> V_4 = & V_3 -> V_4 ;
V_51 -> V_82 = V_83 ;
V_51 -> V_84 = V_85 ;
V_51 -> V_71 = L_18 ;
V_51 -> V_52 = V_86 ;
V_51 -> V_87 . V_2 = & V_88 ;
V_51 -> V_89 = V_90 ;
F_79 ( V_51 ) ;
}
static void F_80 ( struct V_81 * V_3 )
{
struct V_21 * V_51 = & V_2 . V_30 ;
F_81 ( V_51 ) ;
}
static int F_82 ( struct V_81 * V_3 )
{
struct V_91 * V_92 = V_3 -> V_4 . V_93 ;
struct V_91 * V_94 ;
int V_1 ;
V_94 = F_83 ( V_92 ) ;
if ( ! V_94 )
return 0 ;
V_1 = F_84 ( V_3 , V_94 , & V_2 . V_42 ) ;
if ( V_1 )
goto V_95;
F_85 ( V_94 ) ;
return 0 ;
V_95:
F_85 ( V_94 ) ;
return V_1 ;
}
static int F_86 ( struct V_96 * V_4 ,
void (* F_87)( struct V_96 * V_4 ) )
{
struct V_59 * V_60 = F_88 ( V_4 ) ;
int V_97 = 0 ;
F_44 ( & V_60 -> V_54 ) ;
if ( ! F_89 ( & V_60 -> V_34 ) || ! V_60 -> V_69 ) {
V_97 = - V_98 ;
goto V_51;
}
V_60 -> V_66 = F_87 ;
V_51:
F_46 ( & V_60 -> V_54 ) ;
return V_97 ;
}
static int F_90 ( struct V_96 * V_4 )
{
struct V_59 * V_60 = F_88 ( V_4 ) ;
F_44 ( & V_60 -> V_54 ) ;
V_60 -> V_66 = NULL ;
V_60 -> V_64 = false ;
V_60 -> V_68 = false ;
F_46 ( & V_60 -> V_54 ) ;
return 0 ;
}
static int F_91 ( struct V_96 * V_4 )
{
struct V_59 * V_60 = F_88 ( V_4 ) ;
unsigned long V_61 ;
F_4 ( ! F_89 ( & V_60 -> V_34 ) ) ;
F_63 ( & V_60 -> V_67 , V_61 ) ;
if ( V_60 -> V_69 )
F_56 ( V_60 ) ;
V_60 -> V_68 = true ;
F_64 ( & V_60 -> V_67 , V_61 ) ;
return 0 ;
}
static void F_92 ( struct V_96 * V_4 )
{
struct V_59 * V_60 = F_88 ( V_4 ) ;
unsigned long V_61 ;
F_4 ( ! F_89 ( & V_60 -> V_34 ) ) ;
F_63 ( & V_60 -> V_67 , V_61 ) ;
if ( V_60 -> V_69 )
F_59 ( V_60 ) ;
V_60 -> V_68 = false ;
F_64 ( & V_60 -> V_67 , V_61 ) ;
}
static int F_93 ( struct V_96 * V_4 ,
struct V_99 * V_100 )
{
struct V_59 * V_60 = F_88 ( V_4 ) ;
int V_97 ;
F_44 ( & V_60 -> V_54 ) ;
if ( ! F_89 ( & V_60 -> V_34 ) || ! V_60 -> V_69 ) {
V_97 = - V_98 ;
goto V_51;
}
V_97 = F_62 ( & V_60 -> V_47 , & V_60 -> V_9 , V_100 ,
V_60 -> V_34 . V_35 . V_39 ) ;
if ( ! V_97 ) {
V_60 -> V_64 = true ;
V_60 -> V_65 = * V_100 ;
}
V_51:
F_46 ( & V_60 -> V_54 ) ;
return V_97 ;
}
static int F_94 ( struct V_96 * V_4 )
{
struct V_101 V_102 = {
. V_4 = V_4 ,
. V_103 = F_95 () ,
. V_104 = F_96 ( & V_2 . V_9 ) ,
. V_87 = & V_105 ,
} ;
V_2 . V_106 = F_97 (
V_4 , L_19 , V_107 ,
& V_102 , sizeof( V_102 ) ) ;
if ( F_13 ( V_2 . V_106 ) )
return F_14 ( V_2 . V_106 ) ;
return 0 ;
}
static int F_98 ( struct V_96 * V_4 , struct V_96 * V_108 , void * V_7 )
{
struct V_81 * V_3 = F_99 ( V_4 ) ;
int V_1 ;
int V_6 ;
V_2 . V_3 = V_3 ;
F_100 ( & V_3 -> V_4 , & V_2 ) ;
F_101 ( & V_2 . V_54 ) ;
F_102 ( & V_2 . V_67 ) ;
if ( V_3 -> V_4 . V_93 ) {
V_1 = F_82 ( V_3 ) ;
if ( V_1 )
return V_1 ;
}
V_1 = F_103 ( V_3 , & V_2 . V_9 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_104 ( V_3 , & V_2 . V_38 , & V_2 . V_9 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_105 ( V_3 , & V_2 . V_42 ) ;
if ( V_1 )
goto V_95;
V_1 = F_106 ( V_3 , & V_2 . V_47 ) ;
if ( V_1 )
goto V_95;
V_6 = F_107 ( V_3 , 0 ) ;
if ( V_6 < 0 ) {
F_15 ( L_20 ) ;
V_1 = - V_62 ;
goto V_95;
}
V_1 = F_108 ( & V_3 -> V_4 , V_6 ,
NULL , F_7 ,
V_109 , L_21 , & V_2 . V_9 ) ;
if ( V_1 ) {
F_15 ( L_22 ) ;
goto V_95;
}
F_109 ( & V_3 -> V_4 ) ;
F_78 ( V_3 ) ;
V_1 = F_94 ( & V_3 -> V_4 ) ;
if ( V_1 ) {
F_15 ( L_23 ) ;
F_80 ( V_3 ) ;
F_110 ( & V_3 -> V_4 ) ;
return V_1 ;
}
F_111 ( L_24 , F_48 ) ;
return 0 ;
V_95:
F_112 ( & V_2 . V_38 ) ;
return V_1 ;
}
static void F_113 ( struct V_96 * V_4 , struct V_96 * V_108 , void * V_7 )
{
struct V_81 * V_3 = F_99 ( V_4 ) ;
if ( V_2 . V_106 )
F_114 ( V_2 . V_106 ) ;
F_80 ( V_3 ) ;
F_112 ( & V_2 . V_38 ) ;
F_110 ( & V_3 -> V_4 ) ;
}
static int F_115 ( struct V_81 * V_3 )
{
return F_116 ( & V_3 -> V_4 , & V_110 ) ;
}
static int F_117 ( struct V_81 * V_3 )
{
F_118 ( & V_3 -> V_4 , & V_110 ) ;
return 0 ;
}
static int F_119 ( struct V_96 * V_4 )
{
F_120 () ;
return 0 ;
}
static int F_121 ( struct V_96 * V_4 )
{
int V_1 ;
V_1 = F_122 () ;
if ( V_1 < 0 )
return V_1 ;
return 0 ;
}
int T_4 F_123 ( void )
{
return F_124 ( & V_111 ) ;
}
void F_125 ( void )
{
F_126 ( & V_111 ) ;
}
