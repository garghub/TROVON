static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( L_1 , V_2 ) ;
if ( V_4 -> V_6 )
F_3 ( V_4 -> V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
unsigned int V_13 ;
int V_14 ;
F_5 (old_state, crtc, new_crtc_state, i) {
if ( ! V_10 -> V_15 )
continue;
V_14 = F_6 ( V_12 ) ;
if ( ! V_14 )
F_7 ( V_2 -> V_2 ,
L_2 , V_13 ) ;
}
}
static void F_8 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_16 -> V_17 () ;
F_9 ( V_2 , V_8 ) ;
if ( V_4 -> V_18 != 0x3430 ) {
F_10 ( V_2 , V_8 ) ;
F_4 ( V_2 , V_8 ) ;
F_11 ( V_2 , V_8 , 0 ) ;
F_12 ( V_8 ) ;
} else {
F_11 ( V_2 , V_8 , 0 ) ;
F_10 ( V_2 , V_8 ) ;
F_12 ( V_8 ) ;
}
F_4 ( V_2 , V_8 ) ;
F_13 ( V_2 , V_8 ) ;
V_4 -> V_16 -> V_19 () ;
}
static int F_14 ( struct V_20 * V_21 )
{
switch ( V_21 -> type ) {
case V_22 :
return V_23 ;
case V_24 :
return V_25 ;
case V_26 :
return V_27 ;
case V_28 :
case V_29 :
return V_30 ;
case V_31 :
return V_32 ;
case V_33 :
return V_34 ;
default:
return V_35 ;
}
}
static void F_15 ( void )
{
struct V_20 * V_21 = NULL ;
F_16 (dssdev)
V_21 -> V_36 -> V_37 ( V_21 ) ;
}
static int F_17 ( void )
{
int V_38 ;
struct V_20 * V_21 = NULL ;
if ( ! F_18 () )
return - V_39 ;
F_16 (dssdev) {
V_38 = V_21 -> V_36 -> V_40 ( V_21 ) ;
if ( V_38 == - V_39 ) {
F_19 ( V_21 ) ;
goto V_41;
} else if ( V_38 ) {
F_7 ( V_21 -> V_2 , L_3 ,
V_21 -> V_42 ) ;
}
}
return 0 ;
V_41:
F_15 () ;
return V_38 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_43 = V_4 -> V_16 -> V_44 () ;
V_4 -> V_45 = F_21 ( V_2 , 0 , L_4 , 0 ,
V_43 - 1 ) ;
if ( ! V_4 -> V_45 )
return - V_46 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_20 * V_21 = NULL ;
int V_47 = V_4 -> V_16 -> V_44 () ;
int V_48 = V_4 -> V_16 -> V_49 () ;
int V_50 , V_51 , V_52 ;
int V_14 ;
T_1 V_53 ;
F_23 ( V_2 ) ;
V_14 = F_20 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
V_50 = 0 ;
F_16 (dssdev)
if ( F_24 ( V_21 ) )
V_50 ++ ;
if ( V_50 > V_48 || V_50 > V_47 ||
V_50 > F_25 ( V_4 -> V_54 ) ||
V_50 > F_25 ( V_4 -> V_55 ) ||
V_50 > F_25 ( V_4 -> V_56 ) ||
V_50 > F_25 ( V_4 -> V_57 ) ) {
F_26 ( V_2 -> V_2 , L_5 ,
V_58 ) ;
return - V_59 ;
}
V_53 = ( 1 << V_50 ) - 1 ;
V_21 = NULL ;
V_51 = 0 ;
V_52 = 0 ;
F_16 (dssdev) {
struct V_60 * V_61 ;
struct V_62 * V_63 ;
struct V_64 * V_65 ;
struct V_11 * V_12 ;
if ( ! F_24 ( V_21 ) )
continue;
V_63 = F_27 ( V_2 , V_21 ) ;
if ( ! V_63 )
return - V_46 ;
V_61 = F_28 ( V_2 ,
F_14 ( V_21 ) , V_21 , V_63 ) ;
if ( ! V_61 )
return - V_46 ;
V_65 = F_29 ( V_2 , V_52 , V_66 ,
V_53 ) ;
if ( F_30 ( V_65 ) )
return F_31 ( V_65 ) ;
V_12 = F_32 ( V_2 , V_65 , V_21 ) ;
if ( F_30 ( V_12 ) )
return F_31 ( V_12 ) ;
F_33 ( V_61 , V_63 ) ;
V_63 -> V_67 = ( 1 << V_51 ) ;
V_4 -> V_54 [ V_4 -> V_50 ++ ] = V_12 ;
V_4 -> V_55 [ V_4 -> V_43 ++ ] = V_65 ;
V_4 -> V_56 [ V_4 -> V_68 ++ ] = V_63 ;
V_4 -> V_57 [ V_4 -> V_69 ++ ] = V_61 ;
V_52 ++ ;
V_51 ++ ;
}
for (; V_52 < V_47 ; V_52 ++ ) {
struct V_64 * V_65 ;
if ( F_34 ( V_4 -> V_43 >= F_25 ( V_4 -> V_55 ) ) )
return - V_59 ;
V_65 = F_29 ( V_2 , V_52 , V_70 ,
V_53 ) ;
if ( F_30 ( V_65 ) )
return F_31 ( V_65 ) ;
V_4 -> V_55 [ V_4 -> V_43 ++ ] = V_65 ;
}
F_2 ( L_6 ,
V_4 -> V_43 , V_4 -> V_50 , V_4 -> V_68 ,
V_4 -> V_69 ) ;
V_2 -> V_71 . V_72 = 8 ;
V_2 -> V_71 . V_73 = 2 ;
V_2 -> V_71 . V_74 = 2048 ;
V_2 -> V_71 . V_75 = 2048 ;
V_2 -> V_71 . V_76 = & V_77 ;
V_2 -> V_71 . V_78 = & V_79 ;
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
return 0 ;
}
static void F_37 ( void )
{
struct V_20 * V_21 = NULL ;
F_16 (dssdev) {
if ( V_21 -> V_36 -> V_80 )
V_21 -> V_36 -> V_80 ( V_21 ) ;
}
}
static void F_38 ( void )
{
struct V_20 * V_21 = NULL ;
F_16 (dssdev) {
if ( V_21 -> V_36 -> V_81 )
V_21 -> V_36 -> V_81 ( V_21 ) ;
}
}
static int F_39 ( struct V_1 * V_2 , void * V_82 ,
struct V_83 * V_84 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_85 * args = V_82 ;
F_2 ( L_7 , V_2 , args -> V_86 ) ;
switch ( args -> V_86 ) {
case V_87 :
args -> V_88 = V_4 -> V_18 ;
break;
default:
F_2 ( L_8 , args -> V_86 ) ;
return - V_59 ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , void * V_82 ,
struct V_83 * V_84 )
{
struct V_85 * args = V_82 ;
switch ( args -> V_86 ) {
default:
F_2 ( L_8 , args -> V_86 ) ;
return - V_59 ;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , void * V_82 ,
struct V_83 * V_84 )
{
struct V_89 * args = V_82 ;
T_1 V_90 = args -> V_90 & V_91 ;
F_42 ( L_9 , V_2 , V_84 ,
args -> V_92 . V_93 , V_90 ) ;
return F_43 ( V_2 , V_84 , args -> V_92 , V_90 ,
& args -> V_94 ) ;
}
static int F_44 ( struct V_1 * V_2 , void * V_82 ,
struct V_83 * V_84 )
{
struct V_95 * args = V_82 ;
struct V_96 * V_97 ;
int V_14 = 0 ;
F_42 ( L_10 , V_2 , V_84 , args -> V_94 ) ;
V_97 = F_45 ( V_84 , args -> V_94 ) ;
if ( ! V_97 )
return - V_98 ;
args -> V_92 = F_46 ( V_97 ) ;
args -> V_99 = F_47 ( V_97 ) ;
F_48 ( V_97 ) ;
return V_14 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_83 * V_100 )
{
V_100 -> V_101 = NULL ;
F_2 ( L_11 , V_2 , V_100 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_14 ;
F_2 ( L_12 , V_2 ) ;
if ( V_4 -> V_6 ) {
V_14 = F_51 ( V_4 -> V_6 ) ;
if ( V_14 )
F_2 ( L_13 ) ;
}
}
static int F_52 ( struct V_102 * V_103 )
{
const struct V_104 * V_105 ;
struct V_3 * V_4 ;
struct V_1 * V_106 ;
unsigned int V_13 ;
int V_14 ;
F_2 ( L_14 , V_103 -> V_42 ) ;
if ( F_53 () == false )
return - V_39 ;
V_14 = F_54 ( & V_103 -> V_2 , F_55 ( 32 ) ) ;
if ( V_14 ) {
F_26 ( & V_103 -> V_2 , L_15 ) ;
return V_14 ;
}
F_56 () ;
V_14 = F_17 () ;
if ( V_14 )
goto V_107;
V_4 = F_57 ( sizeof( * V_4 ) , V_108 ) ;
if ( ! V_4 ) {
V_14 = - V_46 ;
goto V_109;
}
V_4 -> V_16 = F_58 () ;
V_105 = F_59 ( V_110 ) ;
V_4 -> V_18 = V_105 ? ( unsigned int ) V_105 -> V_82 : 0 ;
V_4 -> V_111 = F_60 ( L_16 , 0 ) ;
F_61 ( & V_4 -> V_112 ) ;
F_62 ( & V_4 -> V_113 ) ;
V_106 = F_63 ( & V_114 , & V_103 -> V_2 ) ;
if ( F_30 ( V_106 ) ) {
V_14 = F_31 ( V_106 ) ;
goto V_115;
}
V_106 -> V_5 = V_4 ;
F_64 ( V_103 , V_106 ) ;
F_65 ( V_106 ) ;
V_14 = F_22 ( V_106 ) ;
if ( V_14 ) {
F_26 ( & V_103 -> V_2 , L_17 , V_14 ) ;
goto V_116;
}
V_14 = F_66 ( V_106 , V_4 -> V_50 ) ;
if ( V_14 ) {
F_26 ( & V_103 -> V_2 , L_18 ) ;
goto V_117;
}
for ( V_13 = 0 ; V_13 < V_4 -> V_50 ; V_13 ++ )
F_67 ( V_4 -> V_54 [ V_13 ] ) ;
V_4 -> V_6 = F_68 ( V_106 ) ;
F_69 ( V_106 ) ;
F_37 () ;
V_14 = F_70 ( V_106 , 0 ) ;
if ( V_14 )
goto V_118;
return 0 ;
V_118:
F_38 () ;
F_71 ( V_106 ) ;
if ( V_4 -> V_6 )
F_72 ( V_106 ) ;
V_117:
F_73 ( V_106 ) ;
F_74 ( V_106 ) ;
V_116:
F_75 ( V_106 ) ;
F_76 ( V_106 ) ;
V_115:
F_77 ( V_4 -> V_111 ) ;
F_78 ( V_4 ) ;
V_109:
F_15 () ;
V_107:
F_79 () ;
return V_14 ;
}
static int F_80 ( struct V_102 * V_103 )
{
struct V_1 * V_106 = F_81 ( V_103 ) ;
struct V_3 * V_4 = V_106 -> V_5 ;
F_2 ( L_19 ) ;
F_82 ( V_106 ) ;
F_38 () ;
F_71 ( V_106 ) ;
if ( V_4 -> V_6 )
F_72 ( V_106 ) ;
F_83 ( V_106 ) ;
F_73 ( V_106 ) ;
F_74 ( V_106 ) ;
F_75 ( V_106 ) ;
F_76 ( V_106 ) ;
F_77 ( V_4 -> V_111 ) ;
F_78 ( V_4 ) ;
F_15 () ;
F_79 () ;
return 0 ;
}
static int F_84 ( void )
{
struct V_20 * V_21 = NULL ;
F_16 (dssdev) {
if ( ! V_21 -> V_36 )
continue;
if ( V_21 -> V_119 == V_120 ) {
V_21 -> V_36 -> V_121 ( V_21 ) ;
V_21 -> V_122 = true ;
} else {
V_21 -> V_122 = false ;
}
}
return 0 ;
}
static int F_85 ( void )
{
struct V_20 * V_21 = NULL ;
F_16 (dssdev) {
if ( ! V_21 -> V_36 )
continue;
if ( V_21 -> V_122 ) {
V_21 -> V_36 -> V_123 ( V_21 ) ;
V_21 -> V_122 = false ;
}
}
return 0 ;
}
static int F_86 ( struct V_124 * V_2 )
{
struct V_1 * V_125 = F_87 ( V_2 ) ;
F_88 ( V_125 ) ;
F_89 ( V_125 ) ;
F_84 () ;
F_90 ( V_125 ) ;
return 0 ;
}
static int F_91 ( struct V_124 * V_2 )
{
struct V_1 * V_125 = F_87 ( V_2 ) ;
F_89 ( V_125 ) ;
F_85 () ;
F_90 ( V_125 ) ;
F_92 ( V_125 ) ;
return F_93 ( V_2 ) ;
}
static int T_2 F_94 ( void )
{
F_2 ( L_20 ) ;
return F_95 ( V_126 , F_25 ( V_126 ) ) ;
}
static void T_3 F_96 ( void )
{
F_2 ( L_21 ) ;
F_97 ( V_126 , F_25 ( V_126 ) ) ;
}
