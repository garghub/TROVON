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
F_11 ( V_2 , V_8 , 0 ) ;
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
F_30 ( V_15 ) ;
if ( V_25 )
F_31 ( & V_18 -> V_24 ) ;
else
F_8 ( V_18 ) ;
return 0 ;
error:
F_13 ( V_2 , V_15 ) ;
return V_14 ;
}
static int F_32 ( struct V_29 * V_30 )
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
static bool F_33 ( struct V_1 * V_2 , enum V_38 V_39 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_4 -> V_40 ; V_13 ++ ) {
struct V_11 * V_12 = V_4 -> V_21 [ V_13 ] ;
if ( F_34 ( V_12 ) == V_39 )
return true ;
}
return false ;
}
static void F_35 ( void )
{
struct V_29 * V_30 = NULL ;
F_36 (dssdev)
V_30 -> V_41 -> V_42 ( V_30 ) ;
}
static int F_37 ( void )
{
int V_43 ;
struct V_29 * V_30 = NULL ;
bool V_44 = true ;
F_36 (dssdev) {
V_43 = V_30 -> V_41 -> V_45 ( V_30 ) ;
if ( V_43 == - V_46 ) {
F_38 ( V_30 ) ;
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
F_35 () ;
return V_43 ;
}
static int F_39 ( struct V_1 * V_2 , int V_49 ,
enum V_38 V_39 ,
T_1 V_50 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_51 * V_52 ;
struct V_11 * V_12 ;
V_52 = F_40 ( V_2 , V_49 , V_53 ,
V_50 ) ;
if ( F_41 ( V_52 ) )
return F_42 ( V_52 ) ;
V_12 = F_43 ( V_2 , V_52 , V_39 , V_49 ) ;
F_44 ( V_4 -> V_40 >= F_45 ( V_4 -> V_21 ) ) ;
V_4 -> V_21 [ V_49 ] = V_12 ;
V_4 -> V_40 ++ ;
V_4 -> V_54 [ V_49 ] = V_52 ;
V_4 -> V_55 ++ ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_56 = F_47 ( V_2 , 0 , L_4 , 0 , 3 ) ;
if ( ! V_4 -> V_56 )
return - V_28 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_29 * V_30 = NULL ;
int V_57 = F_49 () ;
int V_58 = F_50 () ;
int V_40 ;
int V_13 , V_49 = 0 ;
int V_14 ;
T_1 V_50 ;
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
V_14 = F_46 ( V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
V_40 = F_53 ( V_59 , V_58 , V_57 ) ;
V_50 = ( 1 << V_40 ) - 1 ;
V_30 = NULL ;
F_36 (dssdev) {
struct V_60 * V_61 ;
struct V_62 * V_63 ;
enum V_38 V_39 ;
struct V_29 * V_64 ;
if ( ! F_54 ( V_30 ) )
continue;
V_63 = F_55 ( V_2 , V_30 ) ;
if ( ! V_63 ) {
F_56 ( V_2 -> V_2 , L_5 ,
V_30 -> V_48 ) ;
return - V_28 ;
}
V_61 = F_57 ( V_2 ,
F_32 ( V_30 ) , V_30 , V_63 ) ;
if ( ! V_61 ) {
F_56 ( V_2 -> V_2 , L_6 ,
V_30 -> V_48 ) ;
return - V_28 ;
}
F_44 ( V_4 -> V_65 >= F_45 ( V_4 -> V_66 ) ) ;
F_44 ( V_4 -> V_67 >= F_45 ( V_4 -> V_68 ) ) ;
V_4 -> V_66 [ V_4 -> V_65 ++ ] = V_63 ;
V_4 -> V_68 [ V_4 -> V_67 ++ ] = V_61 ;
F_58 ( V_61 , V_63 ) ;
if ( V_49 == V_40 )
continue;
V_64 = F_59 ( V_30 ) ;
V_39 = V_64 -> V_69 ;
F_38 ( V_64 ) ;
if ( ! F_33 ( V_2 , V_39 ) ) {
V_14 = F_39 ( V_2 , V_49 , V_39 ,
V_50 ) ;
if ( V_14 < 0 ) {
F_56 ( V_2 -> V_2 ,
L_7 ,
V_39 ) ;
return V_14 ;
}
V_49 ++ ;
}
}
for (; V_49 < V_40 ; V_49 ++ ) {
for ( V_13 = 0 ; V_13 < V_58 ; V_13 ++ ) {
if ( ! F_33 ( V_2 , V_13 ) )
break;
}
if ( V_13 == V_58 ) {
F_56 ( V_2 -> V_2 , L_8 ) ;
return - V_28 ;
}
V_14 = F_39 ( V_2 , V_49 , V_13 ,
V_50 ) ;
if ( V_14 < 0 ) {
F_56 ( V_2 -> V_2 ,
L_7 , V_13 ) ;
return V_14 ;
}
}
for (; V_49 < V_57 ; V_49 ++ ) {
struct V_51 * V_52 ;
V_52 = F_40 ( V_2 , V_49 , V_70 ,
V_50 ) ;
if ( F_41 ( V_52 ) )
return F_42 ( V_52 ) ;
F_44 ( V_4 -> V_55 >= F_45 ( V_4 -> V_54 ) ) ;
V_4 -> V_54 [ V_4 -> V_55 ++ ] = V_52 ;
}
for ( V_13 = 0 ; V_13 < V_4 -> V_65 ; V_13 ++ ) {
struct V_62 * V_63 = V_4 -> V_66 [ V_13 ] ;
struct V_29 * V_30 =
F_60 ( V_63 ) ;
struct V_29 * V_71 ;
V_71 = F_59 ( V_30 ) ;
V_63 -> V_50 = 0 ;
for ( V_49 = 0 ; V_49 < V_4 -> V_40 ; V_49 ++ ) {
struct V_11 * V_12 = V_4 -> V_21 [ V_49 ] ;
enum V_38 V_72 ;
V_72 = F_34 ( V_12 ) ;
if ( V_71 -> V_69 == V_72 ) {
V_63 -> V_50 |= ( 1 << V_49 ) ;
break;
}
}
F_38 ( V_71 ) ;
}
F_2 ( L_9 ,
V_4 -> V_55 , V_4 -> V_40 , V_4 -> V_65 ,
V_4 -> V_67 ) ;
V_2 -> V_73 . V_74 = 32 ;
V_2 -> V_73 . V_75 = 32 ;
V_2 -> V_73 . V_76 = 2048 ;
V_2 -> V_73 . V_77 = 2048 ;
V_2 -> V_73 . V_78 = & V_79 ;
F_61 ( V_2 ) ;
return 0 ;
}
static void F_62 ( struct V_1 * V_2 )
{
F_63 ( V_2 ) ;
}
static int F_64 ( struct V_1 * V_2 , void * V_80 ,
struct V_81 * V_82 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_83 * args = V_80 ;
F_2 ( L_10 , V_2 , args -> V_84 ) ;
switch ( args -> V_84 ) {
case V_85 :
args -> V_86 = V_4 -> V_87 ;
break;
default:
F_2 ( L_11 , args -> V_84 ) ;
return - V_88 ;
}
return 0 ;
}
static int F_65 ( struct V_1 * V_2 , void * V_80 ,
struct V_81 * V_82 )
{
struct V_83 * args = V_80 ;
switch ( args -> V_84 ) {
default:
F_2 ( L_11 , args -> V_84 ) ;
return - V_88 ;
}
return 0 ;
}
static int F_66 ( struct V_1 * V_2 , void * V_80 ,
struct V_81 * V_82 )
{
struct V_89 * args = V_80 ;
T_1 V_90 = args -> V_90 & V_91 ;
F_67 ( L_12 , V_2 , V_82 ,
args -> V_92 . V_93 , V_90 ) ;
return F_68 ( V_2 , V_82 , args -> V_92 , V_90 ,
& args -> V_94 ) ;
}
static int F_69 ( struct V_1 * V_2 , void * V_80 ,
struct V_81 * V_82 )
{
struct V_95 * args = V_80 ;
struct V_96 * V_97 ;
int V_14 ;
F_67 ( L_13 , V_2 , V_82 , args -> V_94 , args -> V_98 ) ;
V_97 = F_70 ( V_82 , args -> V_94 ) ;
if ( ! V_97 )
return - V_99 ;
V_14 = F_71 ( V_97 , args -> V_98 ) ;
if ( ! V_14 )
V_14 = F_72 ( V_97 , args -> V_98 ) ;
F_73 ( V_97 ) ;
return V_14 ;
}
static int F_74 ( struct V_1 * V_2 , void * V_80 ,
struct V_81 * V_82 )
{
struct V_100 * args = V_80 ;
struct V_96 * V_97 ;
int V_14 ;
F_67 ( L_14 , V_2 , V_82 , args -> V_94 ) ;
V_97 = F_70 ( V_82 , args -> V_94 ) ;
if ( ! V_97 )
return - V_99 ;
V_14 = 0 ;
if ( ! V_14 )
V_14 = F_75 ( V_97 , args -> V_98 ) ;
F_73 ( V_97 ) ;
return V_14 ;
}
static int F_76 ( struct V_1 * V_2 , void * V_80 ,
struct V_81 * V_82 )
{
struct V_101 * args = V_80 ;
struct V_96 * V_97 ;
int V_14 = 0 ;
F_67 ( L_14 , V_2 , V_82 , args -> V_94 ) ;
V_97 = F_70 ( V_82 , args -> V_94 ) ;
if ( ! V_97 )
return - V_99 ;
args -> V_92 = F_77 ( V_97 ) ;
args -> V_102 = F_78 ( V_97 ) ;
F_73 ( V_97 ) ;
return V_14 ;
}
static int F_79 ( struct V_1 * V_2 , unsigned long V_90 )
{
struct V_103 * V_104 = V_2 -> V_2 -> V_105 ;
struct V_3 * V_4 ;
unsigned int V_13 ;
int V_14 ;
F_2 ( L_15 , V_2 ) ;
V_4 = F_25 ( sizeof( * V_4 ) , V_27 ) ;
if ( ! V_4 )
return - V_28 ;
V_4 -> V_87 = V_104 -> V_87 ;
V_2 -> V_5 = V_4 ;
V_4 -> V_106 = F_80 ( L_16 , 0 ) ;
F_81 ( & V_4 -> V_18 . V_22 ) ;
F_82 ( & V_4 -> V_18 . V_19 ) ;
F_82 ( & V_4 -> V_107 ) ;
F_83 ( & V_4 -> V_108 ) ;
F_84 ( V_2 ) ;
V_14 = F_48 ( V_2 ) ;
if ( V_14 ) {
F_56 ( V_2 -> V_2 , L_17 , V_14 ) ;
V_2 -> V_5 = NULL ;
F_19 ( V_4 ) ;
return V_14 ;
}
V_14 = F_85 ( V_2 , V_4 -> V_40 ) ;
if ( V_14 )
F_7 ( V_2 -> V_2 , L_18 ) ;
for ( V_13 = 0 ; V_13 < V_4 -> V_40 ; V_13 ++ )
F_86 ( V_4 -> V_21 [ V_13 ] ) ;
V_4 -> V_6 = F_87 ( V_2 ) ;
F_88 ( V_2 -> V_2 , V_2 ) ;
F_89 ( V_2 ) ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( L_19 , V_2 ) ;
F_91 ( V_2 ) ;
if ( V_4 -> V_6 )
F_92 ( V_2 ) ;
F_62 ( V_2 ) ;
F_93 ( V_2 ) ;
F_94 ( V_4 -> V_106 ) ;
F_95 ( V_2 ) ;
F_96 ( V_2 ) ;
F_19 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
F_88 ( V_2 -> V_2 , NULL ) ;
return 0 ;
}
static int F_97 ( struct V_1 * V_2 , struct V_81 * V_109 )
{
V_109 -> V_110 = NULL ;
F_2 ( L_20 , V_2 , V_109 ) ;
return 0 ;
}
static void F_98 ( struct V_1 * V_2 )
{
int V_13 ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_14 ;
F_2 ( L_21 , V_2 ) ;
for ( V_13 = 0 ; V_13 < V_4 -> V_40 ; V_13 ++ ) {
struct V_11 * V_12 = V_4 -> V_21 [ V_13 ] ;
if ( ! V_12 -> V_111 -> V_112 )
continue;
F_99 ( & V_12 -> V_113 ,
V_12 -> V_111 -> V_112 ,
V_114 ) ;
}
for ( V_13 = 0 ; V_13 < V_4 -> V_55 ; V_13 ++ ) {
struct V_51 * V_52 = V_4 -> V_54 [ V_13 ] ;
if ( ! V_52 -> V_112 )
continue;
F_99 ( & V_52 -> V_113 ,
V_52 -> V_112 ,
V_114 ) ;
}
if ( V_4 -> V_6 ) {
V_14 = F_100 ( V_4 -> V_6 ) ;
if ( V_14 )
F_2 ( L_22 ) ;
}
}
static int F_101 ( struct V_115 * V_116 )
{
int V_43 ;
if ( F_102 () == false )
return - V_46 ;
F_103 () ;
V_43 = F_37 () ;
if ( V_43 ) {
F_104 () ;
return V_43 ;
}
F_2 ( L_23 , V_116 -> V_48 ) ;
return F_105 ( & V_117 , V_116 ) ;
}
static int F_106 ( struct V_115 * V_116 )
{
F_2 ( L_24 ) ;
F_107 ( F_108 ( V_116 ) ) ;
F_35 () ;
F_104 () ;
return 0 ;
}
static int F_109 ( void )
{
struct V_29 * V_30 = NULL ;
F_36 (dssdev) {
if ( ! V_30 -> V_41 )
continue;
if ( V_30 -> V_15 == V_118 ) {
V_30 -> V_41 -> V_119 ( V_30 ) ;
V_30 -> V_120 = true ;
} else {
V_30 -> V_120 = false ;
}
}
return 0 ;
}
static int F_110 ( void )
{
struct V_29 * V_30 = NULL ;
F_36 (dssdev) {
if ( ! V_30 -> V_41 )
continue;
if ( V_30 -> V_120 ) {
V_30 -> V_41 -> V_16 ( V_30 ) ;
V_30 -> V_120 = false ;
}
}
return 0 ;
}
static int F_111 ( struct V_116 * V_2 )
{
struct V_1 * V_121 = F_112 ( V_2 ) ;
F_113 ( V_121 ) ;
F_114 ( V_121 ) ;
F_109 () ;
F_115 ( V_121 ) ;
return 0 ;
}
static int F_116 ( struct V_116 * V_2 )
{
struct V_1 * V_121 = F_112 ( V_2 ) ;
F_114 ( V_121 ) ;
F_110 () ;
F_115 ( V_121 ) ;
F_117 ( V_121 ) ;
return F_118 ( V_2 ) ;
}
static int T_2 F_119 ( void )
{
F_2 ( L_25 ) ;
return F_120 ( V_122 , F_45 ( V_122 ) ) ;
}
static void T_3 F_121 ( void )
{
F_2 ( L_26 ) ;
F_122 ( V_122 , F_45 ( V_122 ) ) ;
}
