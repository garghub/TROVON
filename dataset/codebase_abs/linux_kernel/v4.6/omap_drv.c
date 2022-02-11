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
unsigned int V_13 ;
int V_14 ;
V_14 = F_24 ( V_2 , V_15 ) ;
if ( V_14 )
return V_14 ;
V_18 = F_25 ( sizeof( * V_18 ) , V_26 ) ;
if ( V_18 == NULL ) {
V_14 = - V_27 ;
goto error;
}
F_26 ( & V_18 -> V_24 , F_20 ) ;
V_18 -> V_2 = V_2 ;
V_18 -> V_15 = V_15 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_28 . V_29 ; ++ V_13 ) {
if ( V_15 -> V_21 [ V_13 ] )
V_18 -> V_21 |= 1 << F_27 ( V_15 -> V_21 [ V_13 ] ) ;
}
F_28 ( V_4 -> V_18 . V_22 , ! F_22 ( V_4 , V_18 ) ) ;
F_16 ( & V_4 -> V_18 . V_19 ) ;
V_4 -> V_18 . V_20 |= V_18 -> V_21 ;
F_17 ( & V_4 -> V_18 . V_19 ) ;
F_29 ( V_2 , V_15 ) ;
if ( V_25 )
F_30 ( & V_18 -> V_24 ) ;
else
F_8 ( V_18 ) ;
return 0 ;
error:
F_13 ( V_2 , V_15 ) ;
return V_14 ;
}
static int F_31 ( struct V_30 * V_31 )
{
switch ( V_31 -> type ) {
case V_32 :
return V_33 ;
case V_34 :
return V_35 ;
default:
return V_36 ;
}
}
static bool F_32 ( struct V_1 * V_2 , enum V_37 V_38 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_4 -> V_39 ; V_13 ++ ) {
struct V_11 * V_12 = V_4 -> V_21 [ V_13 ] ;
if ( F_33 ( V_12 ) == V_38 )
return true ;
}
return false ;
}
static void F_34 ( void )
{
struct V_30 * V_31 = NULL ;
F_35 (dssdev)
V_31 -> V_40 -> V_41 ( V_31 ) ;
}
static int F_36 ( void )
{
int V_42 ;
struct V_30 * V_31 = NULL ;
bool V_43 = true ;
F_35 (dssdev) {
V_42 = V_31 -> V_40 -> V_44 ( V_31 ) ;
if ( V_42 == - V_45 ) {
F_37 ( V_31 ) ;
goto V_46;
} else if ( V_42 ) {
F_7 ( V_31 -> V_2 , L_3 ,
V_31 -> V_47 ) ;
} else {
V_43 = false ;
}
}
if ( V_43 )
return - V_45 ;
return 0 ;
V_46:
F_34 () ;
return V_42 ;
}
static int F_38 ( struct V_1 * V_2 , int V_48 ,
enum V_37 V_38 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_49 * V_50 ;
struct V_11 * V_12 ;
V_50 = F_39 ( V_2 , V_48 , V_51 ) ;
if ( F_40 ( V_50 ) )
return F_41 ( V_50 ) ;
V_12 = F_42 ( V_2 , V_50 , V_38 , V_48 ) ;
F_43 ( V_4 -> V_39 >= F_44 ( V_4 -> V_21 ) ) ;
V_4 -> V_21 [ V_48 ] = V_12 ;
V_4 -> V_39 ++ ;
V_4 -> V_52 [ V_48 ] = V_50 ;
V_4 -> V_53 ++ ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_54 ) {
V_2 -> V_28 . V_55 =
F_46 ( V_2 ,
F_47 ( V_56 ) | F_47 ( V_57 ) |
F_47 ( V_58 ) | F_47 ( V_59 ) |
F_47 ( V_60 ) | F_47 ( V_61 ) ) ;
if ( ! V_2 -> V_28 . V_55 )
return - V_27 ;
}
V_4 -> V_62 = F_48 ( V_2 , 0 , L_4 , 0 , 3 ) ;
if ( ! V_4 -> V_62 )
return - V_27 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_30 * V_31 = NULL ;
int V_63 = F_50 () ;
int V_64 = F_51 () ;
int V_39 ;
int V_13 , V_48 = 0 ;
int V_14 ;
F_52 ( V_2 ) ;
F_53 ( V_2 ) ;
V_14 = F_45 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
V_39 = F_54 ( V_29 , V_64 , V_63 ) ;
V_31 = NULL ;
F_35 (dssdev) {
struct V_65 * V_66 ;
struct V_67 * V_68 ;
enum V_37 V_38 ;
struct V_30 * V_69 ;
if ( ! F_55 ( V_31 ) )
continue;
V_68 = F_56 ( V_2 , V_31 ) ;
if ( ! V_68 ) {
F_57 ( V_2 -> V_2 , L_5 ,
V_31 -> V_47 ) ;
return - V_27 ;
}
V_66 = F_58 ( V_2 ,
F_31 ( V_31 ) , V_31 , V_68 ) ;
if ( ! V_66 ) {
F_57 ( V_2 -> V_2 , L_6 ,
V_31 -> V_47 ) ;
return - V_27 ;
}
F_43 ( V_4 -> V_70 >= F_44 ( V_4 -> V_71 ) ) ;
F_43 ( V_4 -> V_72 >= F_44 ( V_4 -> V_73 ) ) ;
V_4 -> V_71 [ V_4 -> V_70 ++ ] = V_68 ;
V_4 -> V_73 [ V_4 -> V_72 ++ ] = V_66 ;
F_59 ( V_66 , V_68 ) ;
if ( V_48 == V_39 )
continue;
V_69 = F_60 ( V_31 ) ;
V_38 = V_69 -> V_74 ;
F_37 ( V_69 ) ;
if ( ! F_32 ( V_2 , V_38 ) ) {
V_14 = F_38 ( V_2 , V_48 , V_38 ) ;
if ( V_14 < 0 ) {
F_57 ( V_2 -> V_2 ,
L_7 ,
V_38 ) ;
return V_14 ;
}
V_48 ++ ;
}
}
for (; V_48 < V_39 ; V_48 ++ ) {
for ( V_13 = 0 ; V_13 < V_64 ; V_13 ++ ) {
if ( ! F_32 ( V_2 , V_13 ) )
break;
}
if ( V_13 == V_64 ) {
F_57 ( V_2 -> V_2 , L_8 ) ;
return - V_27 ;
}
V_14 = F_38 ( V_2 , V_48 , V_13 ) ;
if ( V_14 < 0 ) {
F_57 ( V_2 -> V_2 ,
L_7 , V_13 ) ;
return V_14 ;
}
}
for (; V_48 < V_63 ; V_48 ++ ) {
struct V_49 * V_50 ;
V_50 = F_39 ( V_2 , V_48 , V_75 ) ;
if ( F_40 ( V_50 ) )
return F_41 ( V_50 ) ;
F_43 ( V_4 -> V_53 >= F_44 ( V_4 -> V_52 ) ) ;
V_4 -> V_52 [ V_4 -> V_53 ++ ] = V_50 ;
}
for ( V_13 = 0 ; V_13 < V_4 -> V_70 ; V_13 ++ ) {
struct V_67 * V_68 = V_4 -> V_71 [ V_13 ] ;
struct V_30 * V_31 =
F_61 ( V_68 ) ;
struct V_30 * V_76 ;
V_76 = F_60 ( V_31 ) ;
V_68 -> V_77 = 0 ;
for ( V_48 = 0 ; V_48 < V_4 -> V_39 ; V_48 ++ ) {
struct V_11 * V_12 = V_4 -> V_21 [ V_48 ] ;
enum V_37 V_78 ;
V_78 = F_33 ( V_12 ) ;
if ( V_76 -> V_74 == V_78 ) {
V_68 -> V_77 |= ( 1 << V_48 ) ;
break;
}
}
F_37 ( V_76 ) ;
}
F_2 ( L_9 ,
V_4 -> V_53 , V_4 -> V_39 , V_4 -> V_70 ,
V_4 -> V_72 ) ;
V_2 -> V_28 . V_79 = 32 ;
V_2 -> V_28 . V_80 = 32 ;
V_2 -> V_28 . V_81 = 2048 ;
V_2 -> V_28 . V_82 = 2048 ;
V_2 -> V_28 . V_83 = & V_84 ;
F_62 ( V_2 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 )
{
F_64 ( V_2 ) ;
}
static int F_65 ( struct V_1 * V_2 , void * V_85 ,
struct V_86 * V_87 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_88 * args = V_85 ;
F_2 ( L_10 , V_2 , args -> V_89 ) ;
switch ( args -> V_89 ) {
case V_90 :
args -> V_91 = V_4 -> V_92 ;
break;
default:
F_2 ( L_11 , args -> V_89 ) ;
return - V_93 ;
}
return 0 ;
}
static int F_66 ( struct V_1 * V_2 , void * V_85 ,
struct V_86 * V_87 )
{
struct V_88 * args = V_85 ;
switch ( args -> V_89 ) {
default:
F_2 ( L_11 , args -> V_89 ) ;
return - V_93 ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , void * V_85 ,
struct V_86 * V_87 )
{
struct V_94 * args = V_85 ;
T_1 V_95 = args -> V_95 & V_96 ;
F_68 ( L_12 , V_2 , V_87 ,
args -> V_97 . V_98 , V_95 ) ;
return F_69 ( V_2 , V_87 , args -> V_97 , V_95 ,
& args -> V_99 ) ;
}
static int F_70 ( struct V_1 * V_2 , void * V_85 ,
struct V_86 * V_87 )
{
struct V_100 * args = V_85 ;
struct V_101 * V_102 ;
int V_14 ;
F_68 ( L_13 , V_2 , V_87 , args -> V_99 , args -> V_103 ) ;
V_102 = F_71 ( V_2 , V_87 , args -> V_99 ) ;
if ( ! V_102 )
return - V_104 ;
V_14 = F_72 ( V_102 , args -> V_103 ) ;
if ( ! V_14 )
V_14 = F_73 ( V_102 , args -> V_103 ) ;
F_74 ( V_102 ) ;
return V_14 ;
}
static int F_75 ( struct V_1 * V_2 , void * V_85 ,
struct V_86 * V_87 )
{
struct V_105 * args = V_85 ;
struct V_101 * V_102 ;
int V_14 ;
F_68 ( L_14 , V_2 , V_87 , args -> V_99 ) ;
V_102 = F_71 ( V_2 , V_87 , args -> V_99 ) ;
if ( ! V_102 )
return - V_104 ;
V_14 = 0 ;
if ( ! V_14 )
V_14 = F_76 ( V_102 , args -> V_103 ) ;
F_74 ( V_102 ) ;
return V_14 ;
}
static int F_77 ( struct V_1 * V_2 , void * V_85 ,
struct V_86 * V_87 )
{
struct V_106 * args = V_85 ;
struct V_101 * V_102 ;
int V_14 = 0 ;
F_68 ( L_14 , V_2 , V_87 , args -> V_99 ) ;
V_102 = F_71 ( V_2 , V_87 , args -> V_99 ) ;
if ( ! V_102 )
return - V_104 ;
args -> V_97 = F_78 ( V_102 ) ;
args -> V_107 = F_79 ( V_102 ) ;
F_74 ( V_102 ) ;
return V_14 ;
}
static int F_80 ( struct V_1 * V_2 , unsigned long V_95 )
{
struct V_108 * V_109 = V_2 -> V_2 -> V_110 ;
struct V_3 * V_4 ;
unsigned int V_13 ;
int V_14 ;
F_2 ( L_15 , V_2 ) ;
V_4 = F_25 ( sizeof( * V_4 ) , V_26 ) ;
if ( ! V_4 )
return - V_27 ;
V_4 -> V_92 = V_109 -> V_92 ;
V_2 -> V_5 = V_4 ;
V_4 -> V_111 = F_81 ( L_16 , 0 ) ;
F_82 ( & V_4 -> V_18 . V_22 ) ;
F_83 ( & V_4 -> V_18 . V_19 ) ;
F_83 ( & V_4 -> V_112 ) ;
F_84 ( & V_4 -> V_113 ) ;
F_85 ( V_2 ) ;
V_14 = F_49 ( V_2 ) ;
if ( V_14 ) {
F_57 ( V_2 -> V_2 , L_17 , V_14 ) ;
V_2 -> V_5 = NULL ;
F_19 ( V_4 ) ;
return V_14 ;
}
V_14 = F_86 ( V_2 , V_4 -> V_39 ) ;
if ( V_14 )
F_7 ( V_2 -> V_2 , L_18 ) ;
for ( V_13 = 0 ; V_13 < V_4 -> V_39 ; V_13 ++ )
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
F_95 ( V_4 -> V_111 ) ;
F_96 ( V_2 ) ;
F_97 ( V_2 ) ;
F_19 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
F_89 ( V_2 -> V_2 , NULL ) ;
return 0 ;
}
static int F_98 ( struct V_1 * V_2 , struct V_86 * V_114 )
{
V_114 -> V_115 = NULL ;
F_2 ( L_20 , V_2 , V_114 ) ;
return 0 ;
}
static void F_99 ( struct V_1 * V_2 )
{
int V_13 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_14 ;
F_2 ( L_21 , V_2 ) ;
if ( V_2 -> V_28 . V_55 ) {
for ( V_13 = 0 ; V_13 < V_4 -> V_39 ; V_13 ++ ) {
F_100 ( & V_4 -> V_21 [ V_13 ] -> V_116 ,
V_2 -> V_28 . V_55 , 0 ) ;
}
for ( V_13 = 0 ; V_13 < V_4 -> V_53 ; V_13 ++ ) {
F_100 ( & V_4 -> V_52 [ V_13 ] -> V_116 ,
V_2 -> V_28 . V_55 , 0 ) ;
}
}
if ( V_4 -> V_6 ) {
V_14 = F_101 ( V_4 -> V_6 ) ;
if ( V_14 )
F_2 ( L_22 ) ;
}
}
static int F_102 ( struct V_117 * V_118 )
{
int V_42 ;
if ( F_103 () == false )
return - V_45 ;
F_104 () ;
V_42 = F_36 () ;
if ( V_42 ) {
F_105 () ;
return V_42 ;
}
F_2 ( L_23 , V_118 -> V_47 ) ;
return F_106 ( & V_119 , V_118 ) ;
}
static int F_107 ( struct V_117 * V_118 )
{
F_2 ( L_24 ) ;
F_108 ( F_109 ( V_118 ) ) ;
F_34 () ;
F_105 () ;
return 0 ;
}
static int F_110 ( void )
{
struct V_30 * V_31 = NULL ;
F_35 (dssdev) {
if ( ! V_31 -> V_40 )
continue;
if ( V_31 -> V_15 == V_120 ) {
V_31 -> V_40 -> V_121 ( V_31 ) ;
V_31 -> V_122 = true ;
} else {
V_31 -> V_122 = false ;
}
}
return 0 ;
}
static int F_111 ( void )
{
struct V_30 * V_31 = NULL ;
F_35 (dssdev) {
if ( ! V_31 -> V_40 )
continue;
if ( V_31 -> V_122 ) {
V_31 -> V_40 -> V_16 ( V_31 ) ;
V_31 -> V_122 = false ;
}
}
return 0 ;
}
static int F_112 ( struct V_118 * V_2 )
{
struct V_1 * V_123 = F_113 ( V_2 ) ;
F_114 ( V_123 ) ;
F_115 ( V_123 ) ;
F_110 () ;
F_116 ( V_123 ) ;
return 0 ;
}
static int F_117 ( struct V_118 * V_2 )
{
struct V_1 * V_123 = F_113 ( V_2 ) ;
F_115 ( V_123 ) ;
F_111 () ;
F_116 ( V_123 ) ;
F_118 ( V_123 ) ;
return F_119 ( V_2 ) ;
}
static int T_2 F_120 ( void )
{
F_2 ( L_25 ) ;
return F_121 ( V_124 , F_44 ( V_124 ) ) ;
}
static void T_3 F_122 ( void )
{
F_2 ( L_26 ) ;
F_123 ( V_124 , F_44 ( V_124 ) ) ;
}
