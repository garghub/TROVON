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
F_9 () ;
F_10 ( V_2 , V_8 ) ;
F_11 ( V_2 , V_8 , false ) ;
F_12 ( V_2 , V_8 ) ;
F_4 ( V_2 , V_8 ) ;
F_13 ( V_2 , V_8 ) ;
F_14 () ;
F_15 ( V_8 ) ;
F_16 ( & V_4 -> V_18 . V_19 ) ;
V_4 -> V_18 . V_20 &= ~ V_18 -> V_21 ;
F_17 ( & V_4 -> V_18 . V_19 ) ;
F_18 ( & V_4 -> V_18 . V_22 ) ;
F_19 ( V_18 ) ;
}
static void F_20 ( struct V_23 * V_24 )
{
struct V_17 * V_18 =
F_21 ( V_24 , struct V_17 , V_24 ) ;
F_8 ( V_18 ) ;
}
static bool F_22 ( struct V_3 * V_4 ,
struct V_17 * V_18 )
{
bool V_20 ;
F_16 ( & V_4 -> V_18 . V_19 ) ;
V_20 = V_4 -> V_18 . V_20 & V_18 -> V_21 ;
F_17 ( & V_4 -> V_18 . V_19 ) ;
return V_20 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_7 * V_15 , bool V_25 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_17 * V_18 ;
struct V_11 * V_12 ;
struct V_9 * V_26 ;
int V_13 , V_14 ;
V_14 = F_24 ( V_2 , V_15 ) ;
if ( V_14 )
return V_14 ;
V_18 = F_25 ( sizeof( * V_18 ) , V_27 ) ;
if ( V_18 == NULL ) {
V_14 = - V_28 ;
goto error;
}
F_26 ( & V_18 -> V_24 , F_20 ) ;
V_18 -> V_2 = V_2 ;
V_18 -> V_15 = V_15 ;
F_5 (state, crtc, crtc_state, i)
V_18 -> V_21 |= F_27 ( V_12 ) ;
F_28 ( V_4 -> V_18 . V_22 , ! F_22 ( V_4 , V_18 ) ) ;
F_16 ( & V_4 -> V_18 . V_19 ) ;
V_4 -> V_18 . V_20 |= V_18 -> V_21 ;
F_17 ( & V_4 -> V_18 . V_19 ) ;
F_29 ( V_15 , true ) ;
if ( V_25 )
F_30 ( & V_18 -> V_24 ) ;
else
F_8 ( V_18 ) ;
return 0 ;
error:
F_13 ( V_2 , V_15 ) ;
return V_14 ;
}
static int F_31 ( struct V_29 * V_30 )
{
switch ( V_30 -> type ) {
case V_31 :
return V_32 ;
case V_33 :
return V_34 ;
case V_35 :
return V_36 ;
default:
return V_37 ;
}
}
static bool F_32 ( struct V_1 * V_2 , enum V_38 V_39 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_4 -> V_40 ; V_13 ++ ) {
struct V_11 * V_12 = V_4 -> V_21 [ V_13 ] ;
if ( F_33 ( V_12 ) == V_39 )
return true ;
}
return false ;
}
static void F_34 ( void )
{
struct V_29 * V_30 = NULL ;
F_35 (dssdev)
V_30 -> V_41 -> V_42 ( V_30 ) ;
}
static int F_36 ( void )
{
int V_43 ;
struct V_29 * V_30 = NULL ;
bool V_44 = true ;
F_35 (dssdev) {
V_43 = V_30 -> V_41 -> V_45 ( V_30 ) ;
if ( V_43 == - V_46 ) {
F_37 ( V_30 ) ;
goto V_47;
} else if ( V_43 ) {
F_7 ( V_30 -> V_2 , L_3 ,
V_30 -> V_48 ) ;
} else {
V_44 = false ;
}
}
if ( V_44 )
return - V_46 ;
return 0 ;
V_47:
F_34 () ;
return V_43 ;
}
static int F_38 ( struct V_1 * V_2 , int V_49 ,
enum V_38 V_39 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_50 * V_51 ;
struct V_11 * V_12 ;
V_51 = F_39 ( V_2 , V_49 , V_52 ) ;
if ( F_40 ( V_51 ) )
return F_41 ( V_51 ) ;
V_12 = F_42 ( V_2 , V_51 , V_39 , V_49 ) ;
F_43 ( V_4 -> V_40 >= F_44 ( V_4 -> V_21 ) ) ;
V_4 -> V_21 [ V_49 ] = V_12 ;
V_4 -> V_40 ++ ;
V_4 -> V_53 [ V_49 ] = V_51 ;
V_4 -> V_54 ++ ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_55 ) {
V_2 -> V_56 . V_57 =
F_46 ( V_2 ,
F_47 ( V_58 ) | F_47 ( V_59 ) |
F_47 ( V_60 ) | F_47 ( V_61 ) |
F_47 ( V_62 ) | F_47 ( V_63 ) ) ;
if ( ! V_2 -> V_56 . V_57 )
return - V_28 ;
}
V_4 -> V_64 = F_48 ( V_2 , 0 , L_4 , 0 , 3 ) ;
if ( ! V_4 -> V_64 )
return - V_28 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_29 * V_30 = NULL ;
int V_65 = F_50 () ;
int V_66 = F_51 () ;
int V_40 ;
int V_13 , V_49 = 0 ;
int V_14 ;
F_52 ( V_2 ) ;
F_53 ( V_2 ) ;
V_14 = F_45 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
V_40 = F_54 ( V_67 , V_66 , V_65 ) ;
V_30 = NULL ;
F_35 (dssdev) {
struct V_68 * V_69 ;
struct V_70 * V_71 ;
enum V_38 V_39 ;
struct V_29 * V_72 ;
if ( ! F_55 ( V_30 ) )
continue;
V_71 = F_56 ( V_2 , V_30 ) ;
if ( ! V_71 ) {
F_57 ( V_2 -> V_2 , L_5 ,
V_30 -> V_48 ) ;
return - V_28 ;
}
V_69 = F_58 ( V_2 ,
F_31 ( V_30 ) , V_30 , V_71 ) ;
if ( ! V_69 ) {
F_57 ( V_2 -> V_2 , L_6 ,
V_30 -> V_48 ) ;
return - V_28 ;
}
F_43 ( V_4 -> V_73 >= F_44 ( V_4 -> V_74 ) ) ;
F_43 ( V_4 -> V_75 >= F_44 ( V_4 -> V_76 ) ) ;
V_4 -> V_74 [ V_4 -> V_73 ++ ] = V_71 ;
V_4 -> V_76 [ V_4 -> V_75 ++ ] = V_69 ;
F_59 ( V_69 , V_71 ) ;
if ( V_49 == V_40 )
continue;
V_72 = F_60 ( V_30 ) ;
V_39 = V_72 -> V_77 ;
F_37 ( V_72 ) ;
if ( ! F_32 ( V_2 , V_39 ) ) {
V_14 = F_38 ( V_2 , V_49 , V_39 ) ;
if ( V_14 < 0 ) {
F_57 ( V_2 -> V_2 ,
L_7 ,
V_39 ) ;
return V_14 ;
}
V_49 ++ ;
}
}
for (; V_49 < V_40 ; V_49 ++ ) {
for ( V_13 = 0 ; V_13 < V_66 ; V_13 ++ ) {
if ( ! F_32 ( V_2 , V_13 ) )
break;
}
if ( V_13 == V_66 ) {
F_57 ( V_2 -> V_2 , L_8 ) ;
return - V_28 ;
}
V_14 = F_38 ( V_2 , V_49 , V_13 ) ;
if ( V_14 < 0 ) {
F_57 ( V_2 -> V_2 ,
L_7 , V_13 ) ;
return V_14 ;
}
}
for (; V_49 < V_65 ; V_49 ++ ) {
struct V_50 * V_51 ;
V_51 = F_39 ( V_2 , V_49 , V_78 ) ;
if ( F_40 ( V_51 ) )
return F_41 ( V_51 ) ;
F_43 ( V_4 -> V_54 >= F_44 ( V_4 -> V_53 ) ) ;
V_4 -> V_53 [ V_4 -> V_54 ++ ] = V_51 ;
}
for ( V_13 = 0 ; V_13 < V_4 -> V_73 ; V_13 ++ ) {
struct V_70 * V_71 = V_4 -> V_74 [ V_13 ] ;
struct V_29 * V_30 =
F_61 ( V_71 ) ;
struct V_29 * V_79 ;
V_79 = F_60 ( V_30 ) ;
V_71 -> V_80 = 0 ;
for ( V_49 = 0 ; V_49 < V_4 -> V_40 ; V_49 ++ ) {
struct V_11 * V_12 = V_4 -> V_21 [ V_49 ] ;
enum V_38 V_81 ;
V_81 = F_33 ( V_12 ) ;
if ( V_79 -> V_77 == V_81 ) {
V_71 -> V_80 |= ( 1 << V_49 ) ;
break;
}
}
F_37 ( V_79 ) ;
}
F_2 ( L_9 ,
V_4 -> V_54 , V_4 -> V_40 , V_4 -> V_73 ,
V_4 -> V_75 ) ;
V_2 -> V_56 . V_82 = 32 ;
V_2 -> V_56 . V_83 = 32 ;
V_2 -> V_56 . V_84 = 2048 ;
V_2 -> V_56 . V_85 = 2048 ;
V_2 -> V_56 . V_86 = & V_87 ;
F_62 ( V_2 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 )
{
F_64 ( V_2 ) ;
}
static int F_65 ( struct V_1 * V_2 , void * V_88 ,
struct V_89 * V_90 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_91 * args = V_88 ;
F_2 ( L_10 , V_2 , args -> V_92 ) ;
switch ( args -> V_92 ) {
case V_93 :
args -> V_94 = V_4 -> V_95 ;
break;
default:
F_2 ( L_11 , args -> V_92 ) ;
return - V_96 ;
}
return 0 ;
}
static int F_66 ( struct V_1 * V_2 , void * V_88 ,
struct V_89 * V_90 )
{
struct V_91 * args = V_88 ;
switch ( args -> V_92 ) {
default:
F_2 ( L_11 , args -> V_92 ) ;
return - V_96 ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , void * V_88 ,
struct V_89 * V_90 )
{
struct V_97 * args = V_88 ;
T_1 V_98 = args -> V_98 & V_99 ;
F_68 ( L_12 , V_2 , V_90 ,
args -> V_100 . V_101 , V_98 ) ;
return F_69 ( V_2 , V_90 , args -> V_100 , V_98 ,
& args -> V_102 ) ;
}
static int F_70 ( struct V_1 * V_2 , void * V_88 ,
struct V_89 * V_90 )
{
struct V_103 * args = V_88 ;
struct V_104 * V_105 ;
int V_14 ;
F_68 ( L_13 , V_2 , V_90 , args -> V_102 , args -> V_106 ) ;
V_105 = F_71 ( V_90 , args -> V_102 ) ;
if ( ! V_105 )
return - V_107 ;
V_14 = F_72 ( V_105 , args -> V_106 ) ;
if ( ! V_14 )
V_14 = F_73 ( V_105 , args -> V_106 ) ;
F_74 ( V_105 ) ;
return V_14 ;
}
static int F_75 ( struct V_1 * V_2 , void * V_88 ,
struct V_89 * V_90 )
{
struct V_108 * args = V_88 ;
struct V_104 * V_105 ;
int V_14 ;
F_68 ( L_14 , V_2 , V_90 , args -> V_102 ) ;
V_105 = F_71 ( V_90 , args -> V_102 ) ;
if ( ! V_105 )
return - V_107 ;
V_14 = 0 ;
if ( ! V_14 )
V_14 = F_76 ( V_105 , args -> V_106 ) ;
F_74 ( V_105 ) ;
return V_14 ;
}
static int F_77 ( struct V_1 * V_2 , void * V_88 ,
struct V_89 * V_90 )
{
struct V_109 * args = V_88 ;
struct V_104 * V_105 ;
int V_14 = 0 ;
F_68 ( L_14 , V_2 , V_90 , args -> V_102 ) ;
V_105 = F_71 ( V_90 , args -> V_102 ) ;
if ( ! V_105 )
return - V_107 ;
args -> V_100 = F_78 ( V_105 ) ;
args -> V_110 = F_79 ( V_105 ) ;
F_74 ( V_105 ) ;
return V_14 ;
}
static int F_80 ( struct V_1 * V_2 , unsigned long V_98 )
{
struct V_111 * V_112 = V_2 -> V_2 -> V_113 ;
struct V_3 * V_4 ;
unsigned int V_13 ;
int V_14 ;
F_2 ( L_15 , V_2 ) ;
V_4 = F_25 ( sizeof( * V_4 ) , V_27 ) ;
if ( ! V_4 )
return - V_28 ;
V_4 -> V_95 = V_112 -> V_95 ;
V_2 -> V_5 = V_4 ;
V_4 -> V_114 = F_81 ( L_16 , 0 ) ;
F_82 ( & V_4 -> V_18 . V_22 ) ;
F_83 ( & V_4 -> V_18 . V_19 ) ;
F_83 ( & V_4 -> V_115 ) ;
F_84 ( & V_4 -> V_116 ) ;
F_85 ( V_2 ) ;
V_14 = F_49 ( V_2 ) ;
if ( V_14 ) {
F_57 ( V_2 -> V_2 , L_17 , V_14 ) ;
V_2 -> V_5 = NULL ;
F_19 ( V_4 ) ;
return V_14 ;
}
V_14 = F_86 ( V_2 , V_4 -> V_40 ) ;
if ( V_14 )
F_7 ( V_2 -> V_2 , L_18 ) ;
for ( V_13 = 0 ; V_13 < V_4 -> V_40 ; V_13 ++ )
F_87 ( V_4 -> V_21 [ V_13 ] ) ;
V_4 -> V_6 = F_88 ( V_2 ) ;
F_89 ( V_2 -> V_2 , V_2 ) ;
F_90 ( V_2 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( L_19 , V_2 ) ;
F_92 ( V_2 ) ;
if ( V_4 -> V_6 )
F_93 ( V_2 ) ;
F_63 ( V_2 ) ;
F_94 ( V_2 ) ;
F_95 ( V_4 -> V_114 ) ;
F_96 ( V_2 ) ;
F_97 ( V_2 ) ;
F_19 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
F_89 ( V_2 -> V_2 , NULL ) ;
return 0 ;
}
static int F_98 ( struct V_1 * V_2 , struct V_89 * V_117 )
{
V_117 -> V_118 = NULL ;
F_2 ( L_20 , V_2 , V_117 ) ;
return 0 ;
}
static void F_99 ( struct V_1 * V_2 )
{
int V_13 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_14 ;
F_2 ( L_21 , V_2 ) ;
if ( V_2 -> V_56 . V_57 ) {
for ( V_13 = 0 ; V_13 < V_4 -> V_40 ; V_13 ++ ) {
F_100 ( & V_4 -> V_21 [ V_13 ] -> V_119 ,
V_2 -> V_56 . V_57 , 0 ) ;
}
for ( V_13 = 0 ; V_13 < V_4 -> V_54 ; V_13 ++ ) {
F_100 ( & V_4 -> V_53 [ V_13 ] -> V_119 ,
V_2 -> V_56 . V_57 , 0 ) ;
}
}
if ( V_4 -> V_6 ) {
V_14 = F_101 ( V_4 -> V_6 ) ;
if ( V_14 )
F_2 ( L_22 ) ;
}
}
static int F_102 ( struct V_120 * V_121 )
{
int V_43 ;
if ( F_103 () == false )
return - V_46 ;
F_104 () ;
V_43 = F_36 () ;
if ( V_43 ) {
F_105 () ;
return V_43 ;
}
F_2 ( L_23 , V_121 -> V_48 ) ;
return F_106 ( & V_122 , V_121 ) ;
}
static int F_107 ( struct V_120 * V_121 )
{
F_2 ( L_24 ) ;
F_108 ( F_109 ( V_121 ) ) ;
F_34 () ;
F_105 () ;
return 0 ;
}
static int F_110 ( void )
{
struct V_29 * V_30 = NULL ;
F_35 (dssdev) {
if ( ! V_30 -> V_41 )
continue;
if ( V_30 -> V_15 == V_123 ) {
V_30 -> V_41 -> V_124 ( V_30 ) ;
V_30 -> V_125 = true ;
} else {
V_30 -> V_125 = false ;
}
}
return 0 ;
}
static int F_111 ( void )
{
struct V_29 * V_30 = NULL ;
F_35 (dssdev) {
if ( ! V_30 -> V_41 )
continue;
if ( V_30 -> V_125 ) {
V_30 -> V_41 -> V_16 ( V_30 ) ;
V_30 -> V_125 = false ;
}
}
return 0 ;
}
static int F_112 ( struct V_121 * V_2 )
{
struct V_1 * V_126 = F_113 ( V_2 ) ;
F_114 ( V_126 ) ;
F_115 ( V_126 ) ;
F_110 () ;
F_116 ( V_126 ) ;
return 0 ;
}
static int F_117 ( struct V_121 * V_2 )
{
struct V_1 * V_126 = F_113 ( V_2 ) ;
F_115 ( V_126 ) ;
F_111 () ;
F_116 ( V_126 ) ;
F_118 ( V_126 ) ;
return F_119 ( V_2 ) ;
}
static int T_2 F_120 ( void )
{
F_2 ( L_25 ) ;
return F_121 ( V_127 , F_44 ( V_127 ) ) ;
}
static void T_3 F_122 ( void )
{
F_2 ( L_26 ) ;
F_123 ( V_127 , F_44 ( V_127 ) ) ;
}
