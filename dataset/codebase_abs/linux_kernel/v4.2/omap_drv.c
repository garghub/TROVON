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
F_11 ( V_2 , V_8 ) ;
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
unsigned long V_26 ;
unsigned int V_13 ;
int V_14 ;
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
for ( V_13 = 0 ; V_13 < V_2 -> V_29 . V_30 ; ++ V_13 ) {
if ( V_15 -> V_21 [ V_13 ] )
V_18 -> V_21 |= 1 << F_27 ( V_15 -> V_21 [ V_13 ] ) ;
}
F_28 ( V_4 -> V_18 . V_22 , ! F_22 ( V_4 , V_18 ) ) ;
F_16 ( & V_4 -> V_18 . V_19 ) ;
V_4 -> V_18 . V_20 |= V_18 -> V_21 ;
F_17 ( & V_4 -> V_18 . V_19 ) ;
F_29 ( & V_2 -> V_31 , V_26 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_29 . V_30 ; ++ V_13 ) {
struct V_9 * V_32 = V_15 -> V_33 [ V_13 ] ;
if ( V_32 && V_32 -> V_34 )
F_30 ( & V_32 -> V_34 -> V_35 . V_36 ,
& V_4 -> V_18 . V_37 ) ;
}
F_31 ( & V_2 -> V_31 , V_26 ) ;
F_32 ( V_2 , V_15 ) ;
if ( V_25 )
F_33 ( & V_18 -> V_24 ) ;
else
F_8 ( V_18 ) ;
return 0 ;
error:
F_13 ( V_2 , V_15 ) ;
return V_14 ;
}
static int F_34 ( struct V_38 * V_39 )
{
switch ( V_39 -> type ) {
case V_40 :
return V_41 ;
case V_42 :
return V_43 ;
default:
return V_44 ;
}
}
static bool F_35 ( struct V_1 * V_2 , enum V_45 V_46 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_4 -> V_47 ; V_13 ++ ) {
struct V_11 * V_12 = V_4 -> V_21 [ V_13 ] ;
if ( F_36 ( V_12 ) == V_46 )
return true ;
}
return false ;
}
static void F_37 ( void )
{
struct V_38 * V_39 = NULL ;
F_38 (dssdev)
V_39 -> V_48 -> V_49 ( V_39 ) ;
}
static int F_39 ( void )
{
int V_50 ;
struct V_38 * V_39 = NULL ;
bool V_51 = true ;
F_38 (dssdev) {
V_50 = V_39 -> V_48 -> V_52 ( V_39 ) ;
if ( V_50 == - V_53 ) {
F_40 ( V_39 ) ;
goto V_54;
} else if ( V_50 ) {
F_7 ( V_39 -> V_2 , L_3 ,
V_39 -> V_55 ) ;
} else {
V_51 = false ;
}
}
if ( V_51 )
return - V_53 ;
return 0 ;
V_54:
F_37 () ;
return V_50 ;
}
static int F_41 ( struct V_1 * V_2 , int V_56 ,
enum V_45 V_46 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_57 * V_58 ;
struct V_11 * V_12 ;
V_58 = F_42 ( V_2 , V_56 , V_59 ) ;
if ( F_43 ( V_58 ) )
return F_44 ( V_58 ) ;
V_12 = F_45 ( V_2 , V_58 , V_46 , V_56 ) ;
F_46 ( V_4 -> V_47 >= F_47 ( V_4 -> V_21 ) ) ;
V_4 -> V_21 [ V_56 ] = V_12 ;
V_4 -> V_47 ++ ;
V_4 -> V_60 [ V_56 ] = V_58 ;
V_4 -> V_61 ++ ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_62 ) {
V_2 -> V_29 . V_63 =
F_49 ( V_2 ,
F_50 ( V_64 ) | F_50 ( V_65 ) |
F_50 ( V_66 ) | F_50 ( V_67 ) |
F_50 ( V_68 ) | F_50 ( V_69 ) ) ;
if ( ! V_2 -> V_29 . V_63 )
return - V_28 ;
}
V_4 -> V_70 = F_51 ( V_2 , 0 , L_4 , 0 , 3 ) ;
if ( ! V_4 -> V_70 )
return - V_28 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_38 * V_39 = NULL ;
int V_71 = F_53 () ;
int V_72 = F_54 () ;
int V_47 ;
int V_13 , V_56 = 0 ;
int V_14 ;
F_55 ( V_2 ) ;
F_56 ( V_2 ) ;
V_14 = F_48 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
V_47 = F_57 ( V_30 , V_72 , V_71 ) ;
V_39 = NULL ;
F_38 (dssdev) {
struct V_73 * V_74 ;
struct V_75 * V_76 ;
enum V_45 V_46 ;
struct V_77 * V_78 ;
if ( ! F_58 ( V_39 ) )
continue;
V_76 = F_59 ( V_2 , V_39 ) ;
if ( ! V_76 ) {
F_60 ( V_2 -> V_2 , L_5 ,
V_39 -> V_55 ) ;
return - V_28 ;
}
V_74 = F_61 ( V_2 ,
F_34 ( V_39 ) , V_39 , V_76 ) ;
if ( ! V_74 ) {
F_60 ( V_2 -> V_2 , L_6 ,
V_39 -> V_55 ) ;
return - V_28 ;
}
F_46 ( V_4 -> V_79 >= F_47 ( V_4 -> V_80 ) ) ;
F_46 ( V_4 -> V_81 >= F_47 ( V_4 -> V_82 ) ) ;
V_4 -> V_80 [ V_4 -> V_79 ++ ] = V_76 ;
V_4 -> V_82 [ V_4 -> V_81 ++ ] = V_74 ;
F_62 ( V_74 , V_76 ) ;
if ( V_56 == V_47 )
continue;
V_78 = F_63 ( V_39 ) ;
V_46 = V_78 -> V_56 ;
if ( ! F_35 ( V_2 , V_46 ) ) {
V_14 = F_41 ( V_2 , V_56 , V_46 ) ;
if ( V_14 < 0 ) {
F_60 ( V_2 -> V_2 ,
L_7 ,
V_46 ) ;
return V_14 ;
}
V_56 ++ ;
}
}
for (; V_56 < V_47 ; V_56 ++ ) {
for ( V_13 = 0 ; V_13 < V_72 ; V_13 ++ ) {
if ( ! F_35 ( V_2 , V_13 ) )
break;
}
if ( V_13 == V_72 ) {
F_60 ( V_2 -> V_2 , L_8 ) ;
return - V_28 ;
}
V_14 = F_41 ( V_2 , V_56 , V_13 ) ;
if ( V_14 < 0 ) {
F_60 ( V_2 -> V_2 ,
L_7 , V_13 ) ;
return V_14 ;
}
}
for (; V_56 < V_71 ; V_56 ++ ) {
struct V_57 * V_58 ;
V_58 = F_42 ( V_2 , V_56 , V_83 ) ;
if ( F_43 ( V_58 ) )
return F_44 ( V_58 ) ;
F_46 ( V_4 -> V_61 >= F_47 ( V_4 -> V_60 ) ) ;
V_4 -> V_60 [ V_4 -> V_61 ++ ] = V_58 ;
}
for ( V_13 = 0 ; V_13 < V_4 -> V_79 ; V_13 ++ ) {
struct V_75 * V_76 = V_4 -> V_80 [ V_13 ] ;
struct V_38 * V_39 =
F_64 ( V_76 ) ;
struct V_38 * V_84 ;
V_84 = F_65 ( V_39 ) ;
V_76 -> V_85 = 0 ;
for ( V_56 = 0 ; V_56 < V_4 -> V_47 ; V_56 ++ ) {
struct V_11 * V_12 = V_4 -> V_21 [ V_56 ] ;
enum V_45 V_86 ;
V_86 = F_36 ( V_12 ) ;
if ( V_84 -> V_87 == V_86 ) {
V_76 -> V_85 |= ( 1 << V_56 ) ;
break;
}
}
F_40 ( V_84 ) ;
}
F_2 ( L_9 ,
V_4 -> V_61 , V_4 -> V_47 , V_4 -> V_79 ,
V_4 -> V_81 ) ;
V_2 -> V_29 . V_88 = 32 ;
V_2 -> V_29 . V_89 = 32 ;
V_2 -> V_29 . V_90 = 2048 ;
V_2 -> V_29 . V_91 = 2048 ;
V_2 -> V_29 . V_92 = & V_93 ;
F_66 ( V_2 ) ;
return 0 ;
}
static void F_67 ( struct V_1 * V_2 )
{
F_68 ( V_2 ) ;
}
static int F_69 ( struct V_1 * V_2 , void * V_94 ,
struct V_95 * V_96 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_97 * args = V_94 ;
F_2 ( L_10 , V_2 , args -> V_98 ) ;
switch ( args -> V_98 ) {
case V_99 :
args -> V_100 = V_4 -> V_101 ;
break;
default:
F_2 ( L_11 , args -> V_98 ) ;
return - V_102 ;
}
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , void * V_94 ,
struct V_95 * V_96 )
{
struct V_97 * args = V_94 ;
switch ( args -> V_98 ) {
default:
F_2 ( L_11 , args -> V_98 ) ;
return - V_102 ;
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , void * V_94 ,
struct V_95 * V_96 )
{
struct V_103 * args = V_94 ;
F_72 ( L_12 , V_2 , V_96 ,
args -> V_104 . V_105 , args -> V_26 ) ;
return F_73 ( V_2 , V_96 , args -> V_104 ,
args -> V_26 , & args -> V_106 ) ;
}
static int F_74 ( struct V_1 * V_2 , void * V_94 ,
struct V_95 * V_96 )
{
struct V_107 * args = V_94 ;
struct V_108 * V_109 ;
int V_14 ;
F_72 ( L_13 , V_2 , V_96 , args -> V_106 , args -> V_110 ) ;
V_109 = F_75 ( V_2 , V_96 , args -> V_106 ) ;
if ( ! V_109 )
return - V_111 ;
V_14 = F_76 ( V_109 , args -> V_110 ) ;
if ( ! V_14 )
V_14 = F_77 ( V_109 , args -> V_110 ) ;
F_78 ( V_109 ) ;
return V_14 ;
}
static int F_79 ( struct V_1 * V_2 , void * V_94 ,
struct V_95 * V_96 )
{
struct V_112 * args = V_94 ;
struct V_108 * V_109 ;
int V_14 ;
F_72 ( L_14 , V_2 , V_96 , args -> V_106 ) ;
V_109 = F_75 ( V_2 , V_96 , args -> V_106 ) ;
if ( ! V_109 )
return - V_111 ;
V_14 = 0 ;
if ( ! V_14 )
V_14 = F_80 ( V_109 , args -> V_110 ) ;
F_78 ( V_109 ) ;
return V_14 ;
}
static int F_81 ( struct V_1 * V_2 , void * V_94 ,
struct V_95 * V_96 )
{
struct V_113 * args = V_94 ;
struct V_108 * V_109 ;
int V_14 = 0 ;
F_72 ( L_14 , V_2 , V_96 , args -> V_106 ) ;
V_109 = F_75 ( V_2 , V_96 , args -> V_106 ) ;
if ( ! V_109 )
return - V_111 ;
args -> V_104 = F_82 ( V_109 ) ;
args -> V_114 = F_83 ( V_109 ) ;
F_78 ( V_109 ) ;
return V_14 ;
}
static int F_84 ( struct V_1 * V_2 , unsigned long V_26 )
{
struct V_115 * V_116 = V_2 -> V_2 -> V_117 ;
struct V_3 * V_4 ;
unsigned int V_13 ;
int V_14 ;
F_2 ( L_15 , V_2 ) ;
V_4 = F_25 ( sizeof( * V_4 ) , V_27 ) ;
if ( ! V_4 )
return - V_28 ;
V_4 -> V_101 = V_116 -> V_101 ;
V_2 -> V_5 = V_4 ;
V_4 -> V_118 = F_85 ( L_16 , 0 ) ;
F_86 ( & V_4 -> V_18 . V_22 ) ;
F_87 ( & V_4 -> V_18 . V_19 ) ;
F_88 ( & V_4 -> V_18 . V_37 ) ;
F_87 ( & V_4 -> V_119 ) ;
F_88 ( & V_4 -> V_120 ) ;
F_89 ( V_2 ) ;
V_14 = F_52 ( V_2 ) ;
if ( V_14 ) {
F_60 ( V_2 -> V_2 , L_17 , V_14 ) ;
V_2 -> V_5 = NULL ;
F_19 ( V_4 ) ;
return V_14 ;
}
V_14 = F_90 ( V_2 , V_4 -> V_47 ) ;
if ( V_14 )
F_7 ( V_2 -> V_2 , L_18 ) ;
for ( V_13 = 0 ; V_13 < V_4 -> V_47 ; V_13 ++ )
F_91 ( V_4 -> V_21 [ V_13 ] ) ;
V_4 -> V_6 = F_92 ( V_2 ) ;
if ( ! V_4 -> V_6 ) {
F_7 ( V_2 -> V_2 , L_19 ) ;
}
F_93 ( V_2 -> V_2 , V_2 ) ;
F_94 ( V_2 ) ;
return 0 ;
}
static int F_95 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( L_20 , V_2 ) ;
F_96 ( V_2 ) ;
if ( V_4 -> V_6 )
F_97 ( V_2 ) ;
F_67 ( V_2 ) ;
F_98 ( V_2 ) ;
F_99 ( V_4 -> V_118 ) ;
F_100 ( V_2 ) ;
F_101 ( V_2 ) ;
F_19 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
F_93 ( V_2 -> V_2 , NULL ) ;
return 0 ;
}
static int F_102 ( struct V_1 * V_2 , struct V_95 * V_121 )
{
V_121 -> V_122 = NULL ;
F_2 ( L_21 , V_2 , V_121 ) ;
return 0 ;
}
static void F_103 ( struct V_1 * V_2 )
{
int V_13 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_14 ;
F_2 ( L_22 , V_2 ) ;
if ( V_2 -> V_29 . V_63 ) {
for ( V_13 = 0 ; V_13 < V_4 -> V_47 ; V_13 ++ ) {
F_104 ( & V_4 -> V_21 [ V_13 ] -> V_35 ,
V_2 -> V_29 . V_63 , 0 ) ;
}
for ( V_13 = 0 ; V_13 < V_4 -> V_61 ; V_13 ++ ) {
F_104 ( & V_4 -> V_60 [ V_13 ] -> V_35 ,
V_2 -> V_29 . V_63 , 0 ) ;
}
}
if ( V_4 -> V_6 ) {
V_14 = F_105 ( V_4 -> V_6 ) ;
if ( V_14 )
F_2 ( L_23 ) ;
}
}
static void F_106 ( struct V_1 * V_2 , struct V_95 * V_121 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_123 * V_34 ;
unsigned long V_26 ;
F_2 ( L_24 , V_2 ) ;
F_29 ( & V_2 -> V_31 , V_26 ) ;
F_107 (event, &priv->commit.events, link) {
if ( V_34 -> V_96 == V_121 ) {
V_121 -> V_124 += V_34 -> V_34 -> V_125 ;
V_34 -> V_96 = NULL ;
}
}
F_31 ( & V_2 -> V_31 , V_26 ) ;
}
static void F_108 ( struct V_1 * V_2 , struct V_95 * V_121 )
{
F_2 ( L_25 , V_2 , V_121 ) ;
}
static int F_109 ( struct V_126 * V_127 )
{
int V_50 ;
if ( F_110 () == false )
return - V_53 ;
F_111 () ;
V_50 = F_39 () ;
if ( V_50 ) {
F_112 () ;
return V_50 ;
}
F_2 ( L_26 , V_127 -> V_55 ) ;
return F_113 ( & V_128 , V_127 ) ;
}
static int F_114 ( struct V_126 * V_127 )
{
F_2 ( L_27 ) ;
F_115 ( F_116 ( V_127 ) ) ;
F_37 () ;
F_112 () ;
return 0 ;
}
static int F_117 ( struct V_127 * V_2 )
{
struct V_1 * V_129 = F_118 ( V_2 ) ;
F_119 ( V_129 ) ;
return 0 ;
}
static int F_120 ( struct V_127 * V_2 )
{
struct V_1 * V_129 = F_118 ( V_2 ) ;
F_121 ( V_129 ) ;
return F_122 ( V_2 ) ;
}
static int T_1 F_123 ( void )
{
int V_50 ;
F_2 ( L_28 ) ;
V_50 = F_124 ( & V_130 ) ;
if ( V_50 ) {
F_125 ( L_29 ) ;
return V_50 ;
}
V_50 = F_124 ( & V_131 ) ;
if ( V_50 ) {
F_125 ( L_30 ) ;
F_126 ( & V_130 ) ;
return V_50 ;
}
return 0 ;
}
static void T_2 F_127 ( void )
{
F_2 ( L_31 ) ;
F_126 ( & V_131 ) ;
F_126 ( & V_130 ) ;
}
