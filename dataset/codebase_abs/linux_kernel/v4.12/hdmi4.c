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
struct V_17 * V_18 ;
if ( V_2 . V_19 != NULL )
return 0 ;
V_18 = F_12 ( & V_2 . V_3 -> V_4 , L_3 ) ;
if ( F_13 ( V_18 ) ) {
if ( F_14 ( V_18 ) != - V_20 )
F_15 ( L_4 ) ;
return F_14 ( V_18 ) ;
}
V_2 . V_19 = V_18 ;
return 0 ;
}
static int F_16 ( struct V_21 * V_22 )
{
int V_1 ;
V_1 = F_17 ( V_2 . V_19 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_1 () ;
if ( V_1 )
goto V_23;
F_18 ( V_24 ) ;
V_2 . V_25 = true ;
return 0 ;
V_23:
F_19 ( V_2 . V_19 ) ;
return V_1 ;
}
static void F_20 ( struct V_21 * V_22 )
{
V_2 . V_25 = false ;
F_5 () ;
F_19 ( V_2 . V_19 ) ;
}
static int F_21 ( struct V_21 * V_22 )
{
int V_1 ;
struct V_26 * V_27 ;
enum V_28 V_29 = V_22 -> V_30 ;
struct V_8 * V_9 = & V_2 . V_9 ;
struct V_31 V_32 = { 0 } ;
unsigned V_33 ;
V_1 = F_16 ( V_22 ) ;
if ( V_1 )
return V_1 ;
F_22 ( V_9 , 0xffffffff ) ;
F_9 ( V_9 , 0xffffffff ) ;
V_27 = & V_2 . V_34 . V_27 ;
F_2 ( L_5 , V_27 -> V_35 ,
V_27 -> V_36 ) ;
V_33 = V_27 -> V_37 ;
if ( V_27 -> V_38 & V_39 )
V_33 *= 2 ;
V_33 *= 10 ;
F_23 ( & V_2 . V_40 . V_40 , F_24 ( V_2 . V_40 . V_40 . V_41 ) ,
V_33 , & V_32 ) ;
V_1 = F_25 ( & V_2 . V_40 . V_40 ) ;
if ( V_1 ) {
F_15 ( L_6 ) ;
goto V_42;
}
V_1 = F_26 ( & V_2 . V_40 . V_40 , & V_32 ) ;
if ( V_1 ) {
F_15 ( L_7 ) ;
goto V_43;
}
V_1 = F_27 ( & V_2 . V_44 , V_32 . V_45 ,
V_32 . V_46 [ 0 ] ) ;
if ( V_1 ) {
F_2 ( L_8 ) ;
goto V_47;
}
V_1 = F_10 ( V_9 , V_14 ) ;
if ( V_1 )
goto V_48;
F_28 ( & V_2 . V_49 , & V_2 . V_9 , & V_2 . V_34 ) ;
F_29 ( V_29 , V_27 ) ;
V_1 = F_30 ( V_29 ) ;
if ( V_1 )
goto V_50;
V_1 = F_31 ( & V_2 . V_9 ) ;
if ( V_1 )
goto V_51;
F_32 ( V_9 ,
V_11 | V_12 ) ;
return 0 ;
V_51:
F_33 ( V_29 ) ;
V_50:
F_10 ( & V_2 . V_9 , V_13 ) ;
V_48:
V_47:
V_43:
F_34 ( & V_2 . V_40 . V_40 ) ;
V_42:
F_20 ( V_22 ) ;
return - V_52 ;
}
static void F_35 ( struct V_21 * V_22 )
{
enum V_28 V_29 = V_22 -> V_30 ;
F_22 ( & V_2 . V_9 , 0xffffffff ) ;
F_36 ( & V_2 . V_9 ) ;
F_33 ( V_29 ) ;
F_10 ( & V_2 . V_9 , V_13 ) ;
F_34 ( & V_2 . V_40 . V_40 ) ;
F_20 ( V_22 ) ;
}
static int F_37 ( struct V_21 * V_22 ,
struct V_26 * V_27 )
{
if ( ! F_38 ( V_22 -> V_30 , V_27 ) )
return - V_53 ;
return 0 ;
}
static void F_39 ( struct V_21 * V_22 ,
struct V_26 * V_27 )
{
F_40 ( & V_2 . V_54 ) ;
V_2 . V_34 . V_27 = * V_27 ;
F_41 ( V_27 -> V_37 ) ;
F_42 ( & V_2 . V_54 ) ;
}
static void F_43 ( struct V_21 * V_22 ,
struct V_26 * V_27 )
{
* V_27 = V_2 . V_34 . V_27 ;
}
static void F_44 ( struct V_55 * V_56 )
{
F_40 ( & V_2 . V_54 ) ;
if ( F_1 () ) {
F_42 ( & V_2 . V_54 ) ;
return;
}
F_45 ( & V_2 . V_9 , V_56 ) ;
F_46 ( & V_2 . V_40 , V_56 ) ;
F_47 ( & V_2 . V_44 , V_56 ) ;
F_48 ( & V_2 . V_49 , V_56 ) ;
F_5 () ;
F_42 ( & V_2 . V_54 ) ;
}
static int F_49 ( T_3 * V_57 , int V_58 )
{
int V_1 ;
F_40 ( & V_2 . V_54 ) ;
V_1 = F_1 () ;
F_50 ( V_1 ) ;
V_1 = F_51 ( & V_2 . V_49 , V_57 , V_58 ) ;
F_5 () ;
F_42 ( & V_2 . V_54 ) ;
return V_1 ;
}
static void F_52 ( struct V_59 * V_60 )
{
F_53 ( & V_60 -> V_9 , true ) ;
F_54 ( & V_60 -> V_49 , & V_60 -> V_9 ) ;
}
static void F_55 ( struct V_59 * V_60 )
{
F_56 ( & V_60 -> V_49 , & V_60 -> V_9 ) ;
F_53 ( & V_60 -> V_9 , false ) ;
}
static int F_57 ( struct V_21 * V_22 )
{
struct V_21 * V_61 = & V_2 . V_62 ;
unsigned long V_38 ;
int V_1 = 0 ;
F_2 ( L_9 ) ;
F_40 ( & V_2 . V_54 ) ;
if ( ! V_61 -> V_63 ) {
F_15 ( L_10 ) ;
V_1 = - V_64 ;
goto V_65;
}
V_1 = F_21 ( V_22 ) ;
if ( V_1 ) {
F_15 ( L_11 ) ;
goto V_65;
}
if ( V_2 . V_66 ) {
V_1 = F_58 ( & V_2 . V_49 , & V_2 . V_9 , & V_2 . V_67 ,
V_2 . V_34 . V_27 . V_37 ) ;
if ( V_1 ) {
F_15 ( L_12 , V_1 ) ;
V_2 . V_68 ( & V_2 . V_3 -> V_4 ) ;
V_2 . V_66 = false ;
}
}
F_59 ( & V_2 . V_69 , V_38 ) ;
if ( V_2 . V_66 && V_2 . V_70 )
F_52 ( & V_2 ) ;
V_2 . V_71 = true ;
F_60 ( & V_2 . V_69 , V_38 ) ;
F_42 ( & V_2 . V_54 ) ;
return 0 ;
V_65:
F_42 ( & V_2 . V_54 ) ;
return V_1 ;
}
static void F_61 ( struct V_21 * V_22 )
{
unsigned long V_38 ;
F_2 ( L_13 ) ;
F_40 ( & V_2 . V_54 ) ;
F_59 ( & V_2 . V_69 , V_38 ) ;
F_55 ( & V_2 ) ;
V_2 . V_71 = false ;
F_60 ( & V_2 . V_69 , V_38 ) ;
F_35 ( V_22 ) ;
F_42 ( & V_2 . V_54 ) ;
}
static int F_62 ( struct V_21 * V_22 )
{
int V_1 = 0 ;
F_2 ( L_14 ) ;
F_40 ( & V_2 . V_54 ) ;
V_1 = F_16 ( V_22 ) ;
if ( V_1 ) {
F_15 ( L_11 ) ;
goto V_65;
}
F_42 ( & V_2 . V_54 ) ;
return 0 ;
V_65:
F_42 ( & V_2 . V_54 ) ;
return V_1 ;
}
static void F_63 ( struct V_21 * V_22 )
{
F_2 ( L_15 ) ;
F_40 ( & V_2 . V_54 ) ;
F_20 ( V_22 ) ;
F_42 ( & V_2 . V_54 ) ;
}
static int F_64 ( struct V_21 * V_22 ,
struct V_21 * V_72 )
{
enum V_28 V_29 = V_22 -> V_30 ;
int V_1 ;
V_1 = F_11 () ;
if ( V_1 )
return V_1 ;
V_1 = F_65 ( V_29 , V_22 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_66 ( V_22 , V_72 ) ;
if ( V_1 ) {
F_15 ( L_16 ,
V_72 -> V_73 ) ;
F_67 ( V_29 , V_22 ) ;
return V_1 ;
}
return 0 ;
}
static void F_68 ( struct V_21 * V_22 ,
struct V_21 * V_72 )
{
enum V_28 V_29 = V_22 -> V_30 ;
F_4 ( V_72 != V_22 -> V_72 ) ;
if ( V_72 != V_22 -> V_72 )
return;
F_69 ( V_22 ) ;
F_67 ( V_29 , V_22 ) ;
}
static int F_70 ( struct V_21 * V_22 ,
T_3 * V_74 , int V_58 )
{
bool V_75 ;
int V_1 ;
V_75 = V_2 . V_25 == false ;
if ( V_75 ) {
V_1 = F_62 ( V_22 ) ;
if ( V_1 )
return V_1 ;
}
V_1 = F_49 ( V_74 , V_58 ) ;
if ( V_75 )
F_63 ( V_22 ) ;
return V_1 ;
}
static int F_71 ( struct V_21 * V_22 ,
const struct V_76 * V_77 )
{
V_2 . V_34 . V_78 = * V_77 ;
return 0 ;
}
static int F_72 ( struct V_21 * V_22 ,
bool V_79 )
{
V_2 . V_34 . V_80 = V_79 ? V_81 : V_82 ;
return 0 ;
}
static void F_73 ( struct V_83 * V_3 )
{
struct V_21 * V_61 = & V_2 . V_62 ;
V_61 -> V_4 = & V_3 -> V_4 ;
V_61 -> V_84 = V_85 ;
V_61 -> V_86 = V_87 ;
V_61 -> V_73 = L_17 ;
V_61 -> V_30 = V_88 ;
V_61 -> V_89 . V_2 = & V_90 ;
V_61 -> V_91 = V_92 ;
F_74 ( V_61 ) ;
}
static void F_75 ( struct V_83 * V_3 )
{
struct V_21 * V_61 = & V_2 . V_62 ;
F_76 ( V_61 ) ;
}
static int F_77 ( struct V_83 * V_3 )
{
struct V_93 * V_94 = V_3 -> V_4 . V_95 ;
struct V_93 * V_96 ;
int V_1 ;
V_96 = F_78 ( V_94 , 0 , 0 ) ;
if ( ! V_96 )
return 0 ;
V_1 = F_79 ( V_3 , V_96 , & V_2 . V_44 ) ;
if ( V_1 )
goto V_97;
F_80 ( V_96 ) ;
return 0 ;
V_97:
F_80 ( V_96 ) ;
return V_1 ;
}
static int F_81 ( struct V_98 * V_4 ,
void (* F_82)( struct V_98 * V_4 ) )
{
struct V_59 * V_60 = F_83 ( V_4 ) ;
int V_99 = 0 ;
F_40 ( & V_60 -> V_54 ) ;
if ( ! F_84 ( & V_60 -> V_34 ) || ! V_60 -> V_71 ) {
V_99 = - V_100 ;
goto V_61;
}
V_60 -> V_68 = F_82 ;
V_61:
F_42 ( & V_60 -> V_54 ) ;
return V_99 ;
}
static int F_85 ( struct V_98 * V_4 )
{
struct V_59 * V_60 = F_83 ( V_4 ) ;
F_40 ( & V_60 -> V_54 ) ;
V_60 -> V_68 = NULL ;
V_60 -> V_66 = false ;
V_60 -> V_70 = false ;
F_42 ( & V_60 -> V_54 ) ;
return 0 ;
}
static int F_86 ( struct V_98 * V_4 )
{
struct V_59 * V_60 = F_83 ( V_4 ) ;
unsigned long V_38 ;
F_4 ( ! F_84 ( & V_60 -> V_34 ) ) ;
F_59 ( & V_60 -> V_69 , V_38 ) ;
if ( V_60 -> V_71 )
F_52 ( V_60 ) ;
V_60 -> V_70 = true ;
F_60 ( & V_60 -> V_69 , V_38 ) ;
return 0 ;
}
static void F_87 ( struct V_98 * V_4 )
{
struct V_59 * V_60 = F_83 ( V_4 ) ;
unsigned long V_38 ;
F_4 ( ! F_84 ( & V_60 -> V_34 ) ) ;
F_59 ( & V_60 -> V_69 , V_38 ) ;
if ( V_60 -> V_71 )
F_55 ( V_60 ) ;
V_60 -> V_70 = false ;
F_60 ( & V_60 -> V_69 , V_38 ) ;
}
static int F_88 ( struct V_98 * V_4 ,
struct V_101 * V_102 )
{
struct V_59 * V_60 = F_83 ( V_4 ) ;
int V_99 ;
F_40 ( & V_60 -> V_54 ) ;
if ( ! F_84 ( & V_60 -> V_34 ) || ! V_60 -> V_71 ) {
V_99 = - V_100 ;
goto V_61;
}
V_99 = F_58 ( & V_60 -> V_49 , & V_60 -> V_9 , V_102 ,
V_60 -> V_34 . V_27 . V_37 ) ;
if ( ! V_99 ) {
V_60 -> V_66 = true ;
V_60 -> V_67 = * V_102 ;
}
V_61:
F_42 ( & V_60 -> V_54 ) ;
return V_99 ;
}
static int F_89 ( struct V_98 * V_4 )
{
struct V_103 V_104 = {
. V_4 = V_4 ,
. V_105 = F_90 () ,
. V_106 = F_91 ( & V_2 . V_9 ) ,
. V_89 = & V_107 ,
} ;
V_2 . V_108 = F_92 (
V_4 , L_18 , V_109 ,
& V_104 , sizeof( V_104 ) ) ;
if ( F_13 ( V_2 . V_108 ) )
return F_14 ( V_2 . V_108 ) ;
return 0 ;
}
static int F_93 ( struct V_98 * V_4 , struct V_98 * V_110 , void * V_7 )
{
struct V_83 * V_3 = F_94 ( V_4 ) ;
int V_1 ;
int V_6 ;
V_2 . V_3 = V_3 ;
F_95 ( & V_3 -> V_4 , & V_2 ) ;
F_96 ( & V_2 . V_54 ) ;
F_97 ( & V_2 . V_69 ) ;
if ( V_3 -> V_4 . V_95 ) {
V_1 = F_77 ( V_3 ) ;
if ( V_1 )
return V_1 ;
}
V_1 = F_98 ( V_3 , & V_2 . V_9 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_99 ( V_3 , & V_2 . V_40 , & V_2 . V_9 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_100 ( V_3 , & V_2 . V_44 ) ;
if ( V_1 )
goto V_97;
V_1 = F_101 ( V_3 , & V_2 . V_49 ) ;
if ( V_1 )
goto V_97;
V_6 = F_102 ( V_3 , 0 ) ;
if ( V_6 < 0 ) {
F_15 ( L_19 ) ;
V_1 = - V_64 ;
goto V_97;
}
V_1 = F_103 ( & V_3 -> V_4 , V_6 ,
NULL , F_7 ,
V_111 , L_20 , & V_2 . V_9 ) ;
if ( V_1 ) {
F_15 ( L_21 ) ;
goto V_97;
}
F_104 ( & V_3 -> V_4 ) ;
F_73 ( V_3 ) ;
V_1 = F_89 ( & V_3 -> V_4 ) ;
if ( V_1 ) {
F_15 ( L_22 ) ;
F_75 ( V_3 ) ;
F_105 ( & V_3 -> V_4 ) ;
return V_1 ;
}
F_106 ( L_23 , F_44 ) ;
return 0 ;
V_97:
F_107 ( & V_2 . V_40 ) ;
return V_1 ;
}
static void F_108 ( struct V_98 * V_4 , struct V_98 * V_110 , void * V_7 )
{
struct V_83 * V_3 = F_94 ( V_4 ) ;
if ( V_2 . V_108 )
F_109 ( V_2 . V_108 ) ;
F_75 ( V_3 ) ;
F_107 ( & V_2 . V_40 ) ;
F_105 ( & V_3 -> V_4 ) ;
}
static int F_110 ( struct V_83 * V_3 )
{
return F_111 ( & V_3 -> V_4 , & V_112 ) ;
}
static int F_112 ( struct V_83 * V_3 )
{
F_113 ( & V_3 -> V_4 , & V_112 ) ;
return 0 ;
}
static int F_114 ( struct V_98 * V_4 )
{
F_115 () ;
return 0 ;
}
static int F_116 ( struct V_98 * V_4 )
{
int V_1 ;
V_1 = F_117 () ;
if ( V_1 < 0 )
return V_1 ;
return 0 ;
}
int T_4 F_118 ( void )
{
return F_119 ( & V_113 ) ;
}
void F_120 ( void )
{
F_121 ( & V_113 ) ;
}
