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
struct V_35 V_36 = { 0 } ;
V_1 = F_24 ( V_25 ) ;
if ( V_1 )
return V_1 ;
V_30 = & V_2 . V_37 . V_38 ;
F_2 ( L_6 , V_30 -> V_39 , V_30 -> V_40 ) ;
F_30 ( & V_2 . V_41 , V_30 -> V_42 , & V_36 ) ;
F_31 ( & V_2 . V_9 , 0xffffffff ) ;
F_9 ( & V_2 . V_9 ,
F_8 ( & V_2 . V_9 ) ) ;
V_1 = F_32 ( & V_2 . V_41 . V_41 ) ;
if ( V_1 ) {
F_18 ( L_7 ) ;
goto V_43;
}
V_1 = F_33 ( & V_2 . V_41 . V_41 , & V_36 ) ;
if ( V_1 ) {
F_18 ( L_8 ) ;
goto V_44;
}
V_1 = F_34 ( & V_2 . V_15 , V_36 . V_45 ,
V_36 . V_46 [ 0 ] ) ;
if ( V_1 ) {
F_2 ( L_9 ) ;
goto V_47;
}
V_1 = F_10 ( & V_2 . V_9 , V_18 ) ;
if ( V_1 )
goto V_48;
F_35 ( & V_2 . V_49 , & V_2 . V_9 , & V_2 . V_37 ) ;
F_36 ( 0 ) ;
F_37 ( V_32 , V_30 ) ;
V_1 = F_38 ( & V_2 . V_9 ) ;
if ( V_1 )
goto V_50;
V_1 = F_39 ( V_32 ) ;
if ( V_1 )
goto V_51;
F_40 ( & V_2 . V_9 ,
V_11 | V_12 ) ;
return 0 ;
V_51:
F_41 ( & V_2 . V_9 ) ;
V_50:
F_10 ( & V_2 . V_9 , V_14 ) ;
V_48:
V_47:
V_44:
F_42 ( & V_2 . V_41 . V_41 ) ;
V_43:
F_28 ( V_25 ) ;
return - V_52 ;
}
static void F_43 ( struct V_24 * V_25 )
{
struct V_31 * V_32 = V_2 . V_33 . V_34 ;
F_31 ( & V_2 . V_9 , 0xffffffff ) ;
F_44 ( V_32 ) ;
F_41 ( & V_2 . V_9 ) ;
F_10 ( & V_2 . V_9 , V_14 ) ;
F_42 ( & V_2 . V_41 . V_41 ) ;
F_28 ( V_25 ) ;
}
static int F_45 ( struct V_24 * V_25 ,
struct V_29 * V_38 )
{
struct V_24 * V_53 = & V_2 . V_33 ;
if ( V_38 -> V_54 )
return - V_55 ;
if ( ! F_46 ( V_53 -> V_56 , V_38 ) )
return - V_55 ;
return 0 ;
}
static void F_47 ( struct V_24 * V_25 ,
struct V_29 * V_38 )
{
F_48 ( & V_2 . V_57 ) ;
V_2 . V_37 . V_38 = * V_38 ;
F_49 ( V_38 -> V_42 ) ;
F_50 ( & V_2 . V_57 ) ;
}
static void F_51 ( struct V_24 * V_25 ,
struct V_29 * V_38 )
{
* V_38 = V_2 . V_37 . V_38 ;
}
static void F_52 ( struct V_58 * V_59 )
{
F_48 ( & V_2 . V_57 ) ;
if ( F_1 () ) {
F_50 ( & V_2 . V_57 ) ;
return;
}
F_53 ( & V_2 . V_9 , V_59 ) ;
F_54 ( & V_2 . V_41 , V_59 ) ;
F_55 ( & V_2 . V_15 , V_59 ) ;
F_56 ( & V_2 . V_49 , V_59 ) ;
F_5 () ;
F_50 ( & V_2 . V_57 ) ;
}
static int F_57 ( T_3 * V_60 , int V_61 )
{
int V_1 ;
int V_62 ;
F_48 ( & V_2 . V_57 ) ;
V_1 = F_1 () ;
F_58 ( V_1 ) ;
V_62 = F_59 ( V_2 . V_9 . V_16 , V_63 , 3 , 2 ) ;
F_14 ( V_2 . V_9 . V_16 , V_63 , 1 , 3 , 2 ) ;
V_1 = F_60 ( & V_2 . V_49 , V_60 , V_61 ) ;
F_14 ( V_2 . V_9 . V_16 , V_63 , V_62 , 3 , 2 ) ;
F_5 () ;
F_50 ( & V_2 . V_57 ) ;
return V_1 ;
}
static int F_61 ( struct V_24 * V_25 )
{
struct V_24 * V_53 = & V_2 . V_33 ;
int V_1 = 0 ;
F_2 ( L_10 ) ;
F_48 ( & V_2 . V_57 ) ;
if ( V_53 == NULL || V_53 -> V_34 == NULL ) {
F_18 ( L_11 ) ;
V_1 = - V_64 ;
goto V_65;
}
V_1 = F_29 ( V_25 ) ;
if ( V_1 ) {
F_18 ( L_12 ) ;
goto V_65;
}
V_2 . V_66 = true ;
F_50 ( & V_2 . V_57 ) ;
return 0 ;
V_65:
F_50 ( & V_2 . V_57 ) ;
return V_1 ;
}
static void F_62 ( struct V_24 * V_25 )
{
F_2 ( L_13 ) ;
F_48 ( & V_2 . V_57 ) ;
if ( V_2 . V_67 && V_2 . V_68 )
V_2 . V_68 ( & V_2 . V_67 -> V_4 ) ;
F_43 ( V_25 ) ;
V_2 . V_66 = false ;
F_50 ( & V_2 . V_57 ) ;
}
static int F_63 ( struct V_24 * V_25 )
{
int V_1 = 0 ;
F_2 ( L_14 ) ;
F_48 ( & V_2 . V_57 ) ;
V_1 = F_24 ( V_25 ) ;
if ( V_1 ) {
F_18 ( L_12 ) ;
goto V_65;
}
F_50 ( & V_2 . V_57 ) ;
return 0 ;
V_65:
F_50 ( & V_2 . V_57 ) ;
return V_1 ;
}
static void F_64 ( struct V_24 * V_25 )
{
F_2 ( L_15 ) ;
F_48 ( & V_2 . V_57 ) ;
F_28 ( V_25 ) ;
F_50 ( & V_2 . V_57 ) ;
}
static int F_65 ( struct V_24 * V_25 ,
struct V_24 * V_69 )
{
struct V_31 * V_32 ;
int V_1 ;
V_1 = F_15 () ;
if ( V_1 )
return V_1 ;
V_32 = F_66 ( V_25 -> V_56 ) ;
if ( ! V_32 )
return - V_64 ;
V_1 = F_67 ( V_32 , V_25 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_68 ( V_25 , V_69 ) ;
if ( V_1 ) {
F_18 ( L_16 ,
V_69 -> V_70 ) ;
F_69 ( V_32 , V_25 ) ;
return V_1 ;
}
return 0 ;
}
static void F_70 ( struct V_24 * V_25 ,
struct V_24 * V_69 )
{
F_4 ( V_69 != V_25 -> V_69 ) ;
if ( V_69 != V_25 -> V_69 )
return;
F_71 ( V_25 ) ;
if ( V_25 -> V_34 )
F_69 ( V_25 -> V_34 , V_25 ) ;
}
static int F_72 ( struct V_24 * V_25 ,
T_3 * V_71 , int V_61 )
{
bool V_72 ;
int V_1 ;
V_72 = V_2 . V_28 == false ;
if ( V_72 ) {
V_1 = F_63 ( V_25 ) ;
if ( V_1 )
return V_1 ;
}
V_1 = F_57 ( V_71 , V_61 ) ;
if ( V_72 )
F_64 ( V_25 ) ;
return V_1 ;
}
static int F_73 ( struct V_24 * V_25 ,
const struct V_73 * V_74 )
{
V_2 . V_37 . V_75 = * V_74 ;
return 0 ;
}
static int F_74 ( struct V_24 * V_25 ,
bool V_76 )
{
V_2 . V_37 . V_77 = V_76 ? V_78 : V_79 ;
return 0 ;
}
static void F_75 ( struct V_80 * V_3 )
{
struct V_24 * V_53 = & V_2 . V_33 ;
V_53 -> V_4 = & V_3 -> V_4 ;
V_53 -> V_81 = V_82 ;
V_53 -> V_83 = V_84 ;
V_53 -> V_70 = L_17 ;
V_53 -> V_56 = V_85 ;
V_53 -> V_86 . V_2 = & V_87 ;
V_53 -> V_88 = V_89 ;
F_76 ( V_53 ) ;
}
static void F_77 ( struct V_80 * V_3 )
{
struct V_24 * V_53 = & V_2 . V_33 ;
F_78 ( V_53 ) ;
}
static int F_79 ( struct V_80 * V_3 )
{
struct V_90 * V_91 = V_3 -> V_4 . V_92 ;
struct V_90 * V_93 ;
int V_1 ;
V_93 = F_80 ( V_91 ) ;
if ( ! V_93 )
return 0 ;
V_1 = F_81 ( V_3 , V_93 , & V_2 . V_15 ) ;
if ( V_1 )
goto V_94;
F_82 ( V_93 ) ;
return 0 ;
V_94:
F_82 ( V_93 ) ;
return V_1 ;
}
static int F_83 ( struct V_95 * V_4 ,
void (* F_84)( struct V_95 * V_4 ) )
{
struct V_96 * V_97 = F_85 ( V_4 ) ;
int V_98 = 0 ;
F_48 ( & V_97 -> V_57 ) ;
if ( ! F_86 ( & V_97 -> V_37 ) || ! V_97 -> V_66 ) {
V_98 = - V_99 ;
goto V_53;
}
V_97 -> V_68 = F_84 ;
V_53:
F_50 ( & V_97 -> V_57 ) ;
return V_98 ;
}
static int F_87 ( struct V_95 * V_4 )
{
struct V_96 * V_97 = F_85 ( V_4 ) ;
F_48 ( & V_97 -> V_57 ) ;
V_97 -> V_68 = NULL ;
F_50 ( & V_97 -> V_57 ) ;
return 0 ;
}
static int F_88 ( struct V_95 * V_4 )
{
struct V_96 * V_97 = F_85 ( V_4 ) ;
F_4 ( ! F_86 ( & V_97 -> V_37 ) ) ;
F_4 ( ! V_97 -> V_66 ) ;
V_97 -> V_100 = F_59 ( V_2 . V_9 . V_16 , V_63 , 3 , 2 ) ;
F_14 ( V_2 . V_9 . V_16 , V_63 , 1 , 3 , 2 ) ;
F_89 ( & V_97 -> V_9 , true ) ;
F_90 ( & V_97 -> V_9 , true ) ;
return 0 ;
}
static void F_91 ( struct V_95 * V_4 )
{
struct V_96 * V_97 = F_85 ( V_4 ) ;
F_4 ( ! F_86 ( & V_97 -> V_37 ) ) ;
F_4 ( ! V_97 -> V_66 ) ;
F_90 ( & V_97 -> V_9 , false ) ;
F_89 ( & V_97 -> V_9 , false ) ;
F_14 ( V_2 . V_9 . V_16 , V_63 , V_97 -> V_100 , 3 , 2 ) ;
}
static int F_92 ( struct V_95 * V_4 ,
struct V_101 * V_102 )
{
struct V_96 * V_97 = F_85 ( V_4 ) ;
int V_98 ;
F_48 ( & V_97 -> V_57 ) ;
if ( ! F_86 ( & V_97 -> V_37 ) || ! V_97 -> V_66 ) {
V_98 = - V_99 ;
goto V_53;
}
V_98 = F_93 ( & V_97 -> V_49 , & V_97 -> V_9 , V_102 ,
V_97 -> V_37 . V_38 . V_42 ) ;
V_53:
F_50 ( & V_97 -> V_57 ) ;
return V_98 ;
}
static int F_94 ( struct V_95 * V_4 )
{
struct V_103 V_104 = {
. V_4 = V_4 ,
. V_105 = F_95 () ,
. V_106 = F_96 ( & V_2 . V_9 ) ,
. V_86 = & V_107 ,
} ;
V_2 . V_67 = F_97 (
V_4 , L_18 , V_108 ,
& V_104 , sizeof( V_104 ) ) ;
if ( F_17 ( V_2 . V_67 ) )
return F_19 ( V_2 . V_67 ) ;
return 0 ;
}
static int F_98 ( struct V_80 * V_3 )
{
int V_1 ;
int V_6 ;
V_2 . V_3 = V_3 ;
F_99 ( & V_3 -> V_4 , & V_2 ) ;
F_100 ( & V_2 . V_57 ) ;
if ( V_3 -> V_4 . V_92 ) {
V_1 = F_79 ( V_3 ) ;
if ( V_1 )
return V_1 ;
}
V_1 = F_101 ( V_3 , & V_2 . V_9 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_102 ( V_3 , & V_2 . V_41 , & V_2 . V_9 ) ;
if ( V_1 )
return V_1 ;
V_1 = F_103 ( V_3 , & V_2 . V_15 ) ;
if ( V_1 )
goto V_94;
V_1 = F_104 ( V_3 , & V_2 . V_49 ) ;
if ( V_1 )
goto V_94;
V_6 = F_105 ( V_3 , 0 ) ;
if ( V_6 < 0 ) {
F_18 ( L_19 ) ;
V_1 = - V_64 ;
goto V_94;
}
V_1 = F_106 ( & V_3 -> V_4 , V_6 ,
NULL , F_7 ,
V_109 , L_20 , & V_2 . V_9 ) ;
if ( V_1 ) {
F_18 ( L_21 ) ;
goto V_94;
}
F_107 ( & V_3 -> V_4 ) ;
F_75 ( V_3 ) ;
V_1 = F_94 ( & V_3 -> V_4 ) ;
if ( V_1 ) {
F_18 ( L_22 , V_1 ) ;
F_77 ( V_3 ) ;
F_108 ( & V_3 -> V_4 ) ;
return V_1 ;
}
F_109 ( L_23 , F_52 ) ;
return 0 ;
V_94:
F_110 ( & V_2 . V_41 ) ;
return V_1 ;
}
static int T_4 F_111 ( struct V_80 * V_3 )
{
if ( V_2 . V_67 )
F_112 ( V_2 . V_67 ) ;
F_77 ( V_3 ) ;
F_110 ( & V_2 . V_41 ) ;
F_108 ( & V_3 -> V_4 ) ;
return 0 ;
}
static int F_113 ( struct V_95 * V_4 )
{
F_114 () ;
return 0 ;
}
static int F_115 ( struct V_95 * V_4 )
{
int V_1 ;
V_1 = F_116 () ;
if ( V_1 < 0 )
return V_1 ;
return 0 ;
}
int T_5 F_117 ( void )
{
return F_118 ( & V_110 ) ;
}
void T_4 F_119 ( void )
{
F_120 ( & V_110 ) ;
}
