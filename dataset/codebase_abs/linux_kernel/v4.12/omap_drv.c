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
F_5 (old_state, crtc, old_crtc_state, i) {
if ( ! V_12 -> V_15 -> V_16 )
continue;
V_14 = F_6 ( V_12 ) ;
if ( ! V_14 )
F_7 ( V_2 -> V_2 ,
L_2 , V_13 ) ;
}
}
static void F_8 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_7 * V_8 = V_18 -> V_15 ;
V_4 -> V_19 -> V_20 () ;
F_9 ( V_2 , V_8 ) ;
F_10 ( V_2 , V_8 ) ;
F_4 ( V_2 , V_8 ) ;
F_11 ( V_2 , V_8 , 0 ) ;
F_4 ( V_2 , V_8 ) ;
F_12 ( V_2 , V_8 ) ;
V_4 -> V_19 -> V_21 () ;
F_13 ( V_8 ) ;
F_14 ( & V_4 -> V_18 . V_22 ) ;
V_4 -> V_18 . V_23 &= ~ V_18 -> V_24 ;
F_15 ( & V_4 -> V_18 . V_22 ) ;
F_16 ( & V_4 -> V_18 . V_25 ) ;
F_17 ( V_18 ) ;
}
static void F_18 ( struct V_26 * V_27 )
{
struct V_17 * V_18 =
F_19 ( V_27 , struct V_17 , V_27 ) ;
F_8 ( V_18 ) ;
}
static bool F_20 ( struct V_3 * V_4 ,
struct V_17 * V_18 )
{
bool V_23 ;
F_14 ( & V_4 -> V_18 . V_22 ) ;
V_23 = V_4 -> V_18 . V_23 & V_18 -> V_24 ;
F_15 ( & V_4 -> V_18 . V_22 ) ;
return V_23 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_7 * V_15 , bool V_28 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_17 * V_18 ;
struct V_11 * V_12 ;
struct V_9 * V_29 ;
int V_13 , V_14 ;
V_14 = F_22 ( V_2 , V_15 ) ;
if ( V_14 )
return V_14 ;
V_18 = F_23 ( sizeof( * V_18 ) , V_30 ) ;
if ( V_18 == NULL ) {
V_14 = - V_31 ;
goto error;
}
F_24 ( & V_18 -> V_27 , F_18 ) ;
V_18 -> V_2 = V_2 ;
V_18 -> V_15 = V_15 ;
F_5 (state, crtc, crtc_state, i)
V_18 -> V_24 |= F_25 ( V_12 ) ;
F_26 ( V_4 -> V_18 . V_25 , ! F_20 ( V_4 , V_18 ) ) ;
F_14 ( & V_4 -> V_18 . V_22 ) ;
V_4 -> V_18 . V_23 |= V_18 -> V_24 ;
F_15 ( & V_4 -> V_18 . V_22 ) ;
F_27 ( V_15 , true ) ;
F_28 ( V_15 ) ;
if ( V_28 )
F_29 ( & V_18 -> V_27 ) ;
else
F_8 ( V_18 ) ;
return 0 ;
error:
F_12 ( V_2 , V_15 ) ;
return V_14 ;
}
static int F_30 ( struct V_32 * V_33 )
{
switch ( V_33 -> type ) {
case V_34 :
return V_35 ;
case V_36 :
return V_37 ;
case V_38 :
return V_39 ;
default:
return V_40 ;
}
}
static void F_31 ( void )
{
struct V_32 * V_33 = NULL ;
F_32 (dssdev)
V_33 -> V_41 -> V_42 ( V_33 ) ;
}
static int F_33 ( void )
{
int V_43 ;
struct V_32 * V_33 = NULL ;
if ( ! F_34 () )
return - V_44 ;
F_32 (dssdev) {
V_43 = V_33 -> V_41 -> V_45 ( V_33 ) ;
if ( V_43 == - V_44 ) {
F_35 ( V_33 ) ;
goto V_46;
} else if ( V_43 ) {
F_7 ( V_33 -> V_2 , L_3 ,
V_33 -> V_47 ) ;
}
}
return 0 ;
V_46:
F_31 () ;
return V_43 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_48 = F_37 ( V_2 , 0 , L_4 , 0 , 3 ) ;
if ( ! V_4 -> V_48 )
return - V_31 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_32 * V_33 = NULL ;
int V_49 = V_4 -> V_19 -> V_50 () ;
int V_51 = V_4 -> V_19 -> V_52 () ;
int V_53 , V_54 , V_55 ;
int V_14 ;
T_1 V_56 ;
F_39 ( V_2 ) ;
V_14 = F_36 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
V_53 = 0 ;
F_32 (dssdev)
if ( F_40 ( V_33 ) )
V_53 ++ ;
if ( V_53 > V_51 || V_53 > V_49 ||
V_53 > F_41 ( V_4 -> V_24 ) ||
V_53 > F_41 ( V_4 -> V_57 ) ||
V_53 > F_41 ( V_4 -> V_58 ) ||
V_53 > F_41 ( V_4 -> V_59 ) ) {
F_42 ( V_2 -> V_2 , L_5 ,
V_60 ) ;
return - V_61 ;
}
V_56 = ( 1 << V_53 ) - 1 ;
V_33 = NULL ;
V_54 = 0 ;
V_55 = 0 ;
F_32 (dssdev) {
struct V_62 * V_63 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
struct V_11 * V_12 ;
if ( ! F_40 ( V_33 ) )
continue;
V_65 = F_43 ( V_2 , V_33 ) ;
if ( ! V_65 )
return - V_31 ;
V_63 = F_44 ( V_2 ,
F_30 ( V_33 ) , V_33 , V_65 ) ;
if ( ! V_63 )
return - V_31 ;
V_67 = F_45 ( V_2 , V_55 , V_68 ,
V_56 ) ;
if ( F_46 ( V_67 ) )
return F_47 ( V_67 ) ;
V_12 = F_48 ( V_2 , V_67 , V_33 ) ;
if ( F_46 ( V_12 ) )
return F_47 ( V_12 ) ;
F_49 ( V_63 , V_65 ) ;
V_65 -> V_69 = ( 1 << V_54 ) ;
V_4 -> V_24 [ V_4 -> V_53 ++ ] = V_12 ;
V_4 -> V_57 [ V_4 -> V_70 ++ ] = V_67 ;
V_4 -> V_58 [ V_4 -> V_71 ++ ] = V_65 ;
V_4 -> V_59 [ V_4 -> V_72 ++ ] = V_63 ;
V_55 ++ ;
V_54 ++ ;
}
for (; V_55 < V_49 ; V_55 ++ ) {
struct V_66 * V_67 ;
if ( F_50 ( V_4 -> V_70 >= F_41 ( V_4 -> V_57 ) ) )
return - V_61 ;
V_67 = F_45 ( V_2 , V_55 , V_73 ,
V_56 ) ;
if ( F_46 ( V_67 ) )
return F_47 ( V_67 ) ;
V_4 -> V_57 [ V_4 -> V_70 ++ ] = V_67 ;
}
F_2 ( L_6 ,
V_4 -> V_70 , V_4 -> V_53 , V_4 -> V_71 ,
V_4 -> V_72 ) ;
V_2 -> V_74 . V_75 = 8 ;
V_2 -> V_74 . V_76 = 2 ;
V_2 -> V_74 . V_77 = 2048 ;
V_2 -> V_74 . V_78 = 2048 ;
V_2 -> V_74 . V_79 = & V_80 ;
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , void * V_81 ,
struct V_82 * V_83 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_84 * args = V_81 ;
F_2 ( L_7 , V_2 , args -> V_85 ) ;
switch ( args -> V_85 ) {
case V_86 :
args -> V_87 = V_4 -> V_88 ;
break;
default:
F_2 ( L_8 , args -> V_85 ) ;
return - V_61 ;
}
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , void * V_81 ,
struct V_82 * V_83 )
{
struct V_84 * args = V_81 ;
switch ( args -> V_85 ) {
default:
F_2 ( L_8 , args -> V_85 ) ;
return - V_61 ;
}
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , void * V_81 ,
struct V_82 * V_83 )
{
struct V_89 * args = V_81 ;
T_1 V_90 = args -> V_90 & V_91 ;
F_56 ( L_9 , V_2 , V_83 ,
args -> V_92 . V_93 , V_90 ) ;
return F_57 ( V_2 , V_83 , args -> V_92 , V_90 ,
& args -> V_94 ) ;
}
static int F_58 ( struct V_1 * V_2 , void * V_81 ,
struct V_82 * V_83 )
{
struct V_95 * args = V_81 ;
struct V_96 * V_97 ;
int V_14 ;
F_56 ( L_10 , V_2 , V_83 , args -> V_94 , args -> V_98 ) ;
V_97 = F_59 ( V_83 , args -> V_94 ) ;
if ( ! V_97 )
return - V_99 ;
V_14 = F_60 ( V_97 , args -> V_98 ) ;
if ( ! V_14 )
V_14 = F_61 ( V_97 , args -> V_98 ) ;
F_62 ( V_97 ) ;
return V_14 ;
}
static int F_63 ( struct V_1 * V_2 , void * V_81 ,
struct V_82 * V_83 )
{
struct V_100 * args = V_81 ;
struct V_96 * V_97 ;
int V_14 ;
F_56 ( L_11 , V_2 , V_83 , args -> V_94 ) ;
V_97 = F_59 ( V_83 , args -> V_94 ) ;
if ( ! V_97 )
return - V_99 ;
V_14 = 0 ;
if ( ! V_14 )
V_14 = F_64 ( V_97 , args -> V_98 ) ;
F_62 ( V_97 ) ;
return V_14 ;
}
static int F_65 ( struct V_1 * V_2 , void * V_81 ,
struct V_82 * V_83 )
{
struct V_101 * args = V_81 ;
struct V_96 * V_97 ;
int V_14 = 0 ;
F_56 ( L_11 , V_2 , V_83 , args -> V_94 ) ;
V_97 = F_59 ( V_83 , args -> V_94 ) ;
if ( ! V_97 )
return - V_99 ;
args -> V_92 = F_66 ( V_97 ) ;
args -> V_102 = F_67 ( V_97 ) ;
F_62 ( V_97 ) ;
return V_14 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_82 * V_103 )
{
V_103 -> V_104 = NULL ;
F_2 ( L_12 , V_2 , V_103 ) ;
return 0 ;
}
static void F_69 ( struct V_1 * V_2 )
{
int V_13 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_14 ;
F_2 ( L_13 , V_2 ) ;
for ( V_13 = 0 ; V_13 < V_4 -> V_53 ; V_13 ++ ) {
struct V_11 * V_12 = V_4 -> V_24 [ V_13 ] ;
if ( ! V_12 -> V_105 -> V_106 )
continue;
F_70 ( & V_12 -> V_107 ,
V_12 -> V_105 -> V_106 ,
V_108 ) ;
}
for ( V_13 = 0 ; V_13 < V_4 -> V_70 ; V_13 ++ ) {
struct V_66 * V_67 = V_4 -> V_57 [ V_13 ] ;
if ( ! V_67 -> V_106 )
continue;
F_70 ( & V_67 -> V_107 ,
V_67 -> V_106 ,
V_108 ) ;
}
if ( V_4 -> V_6 ) {
V_14 = F_71 ( V_4 -> V_6 ) ;
if ( V_14 )
F_2 ( L_14 ) ;
}
}
static int F_72 ( struct V_109 * V_110 )
{
struct V_111 * V_112 = V_110 -> V_2 . V_113 ;
struct V_3 * V_4 ;
struct V_1 * V_114 ;
unsigned int V_13 ;
int V_14 ;
F_2 ( L_15 , V_110 -> V_47 ) ;
if ( F_73 () == false )
return - V_44 ;
F_74 () ;
V_14 = F_33 () ;
if ( V_14 )
goto V_115;
V_4 = F_23 ( sizeof( * V_4 ) , V_30 ) ;
if ( ! V_4 ) {
V_14 = - V_31 ;
goto V_116;
}
V_4 -> V_19 = F_75 () ;
V_4 -> V_88 = V_112 -> V_88 ;
V_4 -> V_117 = F_76 ( L_16 , 0 ) ;
F_77 ( & V_4 -> V_18 . V_25 ) ;
F_78 ( & V_4 -> V_18 . V_22 ) ;
F_78 ( & V_4 -> V_118 ) ;
F_79 ( & V_4 -> V_119 ) ;
V_114 = F_80 ( & V_120 , & V_110 -> V_2 ) ;
if ( F_46 ( V_114 ) ) {
V_14 = F_47 ( V_114 ) ;
goto V_121;
}
V_114 -> V_5 = V_4 ;
F_81 ( V_110 , V_114 ) ;
F_82 ( V_114 ) ;
V_14 = F_38 ( V_114 ) ;
if ( V_14 ) {
F_42 ( & V_110 -> V_2 , L_17 , V_14 ) ;
goto V_122;
}
V_14 = F_83 ( V_114 , V_4 -> V_53 ) ;
if ( V_14 ) {
F_42 ( & V_110 -> V_2 , L_18 ) ;
goto V_123;
}
for ( V_13 = 0 ; V_13 < V_4 -> V_53 ; V_13 ++ )
F_84 ( V_4 -> V_24 [ V_13 ] ) ;
V_4 -> V_6 = F_85 ( V_114 ) ;
F_86 ( V_114 ) ;
V_14 = F_87 ( V_114 , 0 ) ;
if ( V_14 )
goto V_124;
return 0 ;
V_124:
F_88 ( V_114 ) ;
if ( V_4 -> V_6 )
F_89 ( V_114 ) ;
V_123:
F_90 ( V_114 ) ;
F_91 ( V_114 ) ;
V_122:
F_92 ( V_114 ) ;
F_93 ( V_114 ) ;
V_121:
F_94 ( V_4 -> V_117 ) ;
F_17 ( V_4 ) ;
V_116:
F_31 () ;
V_115:
F_95 () ;
return V_14 ;
}
static int F_96 ( struct V_109 * V_110 )
{
struct V_1 * V_114 = F_97 ( V_110 ) ;
struct V_3 * V_4 = V_114 -> V_5 ;
F_2 ( L_19 ) ;
F_98 ( V_114 ) ;
F_88 ( V_114 ) ;
if ( V_4 -> V_6 )
F_89 ( V_114 ) ;
F_99 ( V_114 ) ;
F_90 ( V_114 ) ;
F_91 ( V_114 ) ;
F_92 ( V_114 ) ;
F_93 ( V_114 ) ;
F_94 ( V_4 -> V_117 ) ;
F_17 ( V_4 ) ;
F_31 () ;
F_95 () ;
return 0 ;
}
static int F_100 ( void )
{
struct V_32 * V_33 = NULL ;
F_32 (dssdev) {
if ( ! V_33 -> V_41 )
continue;
if ( V_33 -> V_15 == V_125 ) {
V_33 -> V_41 -> V_126 ( V_33 ) ;
V_33 -> V_127 = true ;
} else {
V_33 -> V_127 = false ;
}
}
return 0 ;
}
static int F_101 ( void )
{
struct V_32 * V_33 = NULL ;
F_32 (dssdev) {
if ( ! V_33 -> V_41 )
continue;
if ( V_33 -> V_127 ) {
V_33 -> V_41 -> V_16 ( V_33 ) ;
V_33 -> V_127 = false ;
}
}
return 0 ;
}
static int F_102 ( struct V_128 * V_2 )
{
struct V_1 * V_129 = F_103 ( V_2 ) ;
F_104 ( V_129 ) ;
F_105 ( V_129 ) ;
F_100 () ;
F_106 ( V_129 ) ;
return 0 ;
}
static int F_107 ( struct V_128 * V_2 )
{
struct V_1 * V_129 = F_103 ( V_2 ) ;
F_105 ( V_129 ) ;
F_101 () ;
F_106 ( V_129 ) ;
F_108 ( V_129 ) ;
return F_109 ( V_2 ) ;
}
static int T_2 F_110 ( void )
{
F_2 ( L_20 ) ;
return F_111 ( V_130 , F_41 ( V_130 ) ) ;
}
static void T_3 F_112 ( void )
{
F_2 ( L_21 ) ;
F_113 ( V_130 , F_41 ( V_130 ) ) ;
}
