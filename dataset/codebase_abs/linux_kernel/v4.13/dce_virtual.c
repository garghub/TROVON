static void F_1 ( struct V_1 * V_2 , int V_3 )
{
return;
}
static T_1 F_2 ( struct V_1 * V_2 , int V_3 )
{
return 0 ;
}
static void F_3 ( struct V_1 * V_2 ,
int V_4 , T_2 V_5 , bool V_6 )
{
return;
}
static int F_4 ( struct V_1 * V_2 , int V_3 ,
T_1 * V_7 , T_1 * V_8 )
{
* V_7 = 0 ;
* V_8 = 0 ;
return - V_9 ;
}
static bool F_5 ( struct V_1 * V_2 ,
enum V_10 V_11 )
{
return true ;
}
static void F_6 ( struct V_1 * V_2 ,
enum V_10 V_11 )
{
return;
}
static T_1 F_7 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
switch ( V_2 -> V_14 ) {
#ifdef F_9
case V_15 :
case V_16 :
case V_17 :
case V_18 :
F_10 ( V_2 ) ;
break;
#endif
#ifdef F_11
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
F_12 ( V_2 ) ;
break;
#endif
case V_24 :
case V_25 :
F_13 ( V_2 ) ;
break;
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
F_14 ( V_2 ) ;
break;
case V_31 :
#ifdef F_9
case V_32 :
#endif
return;
default:
F_15 ( L_1 , V_2 -> V_14 ) ;
}
return;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
return;
}
static void F_17 ( struct V_1 * V_2 ,
bool V_33 )
{
return;
}
static void F_18 ( struct V_1 * V_2 )
{
return;
}
static int F_19 ( struct V_34 * V_3 , T_3 * V_35 ,
T_3 * V_36 , T_3 * V_37 , T_4 V_38 ,
struct V_39 * V_40 )
{
struct V_41 * V_41 = F_20 ( V_3 ) ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_38 ; V_42 ++ ) {
V_41 -> V_43 [ V_42 ] = V_35 [ V_42 ] >> 6 ;
V_41 -> V_44 [ V_42 ] = V_36 [ V_42 ] >> 6 ;
V_41 -> V_45 [ V_42 ] = V_37 [ V_42 ] >> 6 ;
}
return 0 ;
}
static void F_21 ( struct V_34 * V_3 )
{
struct V_41 * V_41 = F_20 ( V_3 ) ;
F_22 ( V_3 ) ;
F_23 ( V_41 ) ;
}
static void F_24 ( struct V_34 * V_3 , int V_46 )
{
struct V_47 * V_48 = V_3 -> V_48 ;
struct V_1 * V_2 = V_48 -> V_49 ;
struct V_41 * V_41 = F_20 ( V_3 ) ;
unsigned type ;
if ( F_25 ( V_2 ) )
return;
switch ( V_46 ) {
case V_50 :
V_41 -> V_51 = true ;
type = F_26 ( V_2 , V_41 -> V_4 ) ;
F_27 ( V_2 , & V_2 -> V_52 , type ) ;
F_28 ( V_3 ) ;
break;
case V_53 :
case V_54 :
case V_55 :
F_29 ( V_3 ) ;
V_41 -> V_51 = false ;
break;
}
}
static void F_30 ( struct V_34 * V_3 )
{
F_24 ( V_3 , V_55 ) ;
}
static void F_31 ( struct V_34 * V_3 )
{
F_24 ( V_3 , V_50 ) ;
}
static void F_32 ( struct V_34 * V_3 )
{
struct V_41 * V_41 = F_20 ( V_3 ) ;
F_24 ( V_3 , V_55 ) ;
if ( V_3 -> V_56 -> V_57 ) {
int V_58 ;
struct V_59 * V_60 ;
struct V_61 * V_62 ;
V_60 = F_33 ( V_3 -> V_56 -> V_57 ) ;
V_62 = F_34 ( V_60 -> V_63 ) ;
V_58 = F_35 ( V_62 , true ) ;
if ( F_36 ( V_58 ) )
F_15 ( L_2 ) ;
else {
F_37 ( V_62 ) ;
F_38 ( V_62 ) ;
}
}
V_41 -> V_64 = V_65 ;
V_41 -> V_66 = NULL ;
V_41 -> V_67 = NULL ;
}
static int F_39 ( struct V_34 * V_3 ,
struct V_68 * V_46 ,
struct V_68 * V_69 ,
int V_70 , int V_71 , struct V_72 * V_73 )
{
struct V_41 * V_41 = F_20 ( V_3 ) ;
V_41 -> V_74 = * V_69 ;
return 0 ;
}
static bool F_40 ( struct V_34 * V_3 ,
const struct V_68 * V_46 ,
struct V_68 * V_69 )
{
return true ;
}
static int F_41 ( struct V_34 * V_3 , int V_70 , int V_71 ,
struct V_72 * V_73 )
{
return 0 ;
}
static void F_42 ( struct V_34 * V_3 )
{
return;
}
static int F_43 ( struct V_34 * V_3 ,
struct V_72 * V_57 ,
int V_70 , int V_71 , enum V_75 V_76 )
{
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , int V_77 )
{
struct V_41 * V_41 ;
int V_42 ;
V_41 = F_45 ( sizeof( struct V_41 ) +
( V_78 * sizeof( struct V_79 * ) ) , V_80 ) ;
if ( V_41 == NULL )
return - V_81 ;
F_46 ( V_2 -> V_82 , & V_41 -> V_83 , & V_84 ) ;
F_47 ( & V_41 -> V_83 , 256 ) ;
V_41 -> V_4 = V_77 ;
V_2 -> V_85 . V_86 [ V_77 ] = V_41 ;
for ( V_42 = 0 ; V_42 < 256 ; V_42 ++ ) {
V_41 -> V_43 [ V_42 ] = V_42 << 2 ;
V_41 -> V_44 [ V_42 ] = V_42 << 2 ;
V_41 -> V_45 [ V_42 ] = V_42 << 2 ;
}
V_41 -> V_64 = V_65 ;
V_41 -> V_66 = NULL ;
V_41 -> V_67 = NULL ;
V_41 -> V_87 = V_88 ;
F_48 ( & V_41 -> V_83 , & V_89 ) ;
return 0 ;
}
static int F_49 ( void * V_90 )
{
struct V_1 * V_2 = (struct V_1 * ) V_90 ;
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
V_2 -> V_85 . V_91 = 1 ;
V_2 -> V_85 . V_92 = 1 ;
return 0 ;
}
static struct V_93 *
F_52 ( struct V_79 * V_67 )
{
int V_94 = V_67 -> V_95 [ 0 ] ;
struct V_93 * V_66 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_96 ; V_42 ++ ) {
if ( V_67 -> V_95 [ V_42 ] == 0 )
break;
V_66 = F_53 ( V_67 -> V_48 , V_67 -> V_95 [ V_42 ] ) ;
if ( ! V_66 )
continue;
if ( V_66 -> V_97 == V_98 )
return V_66 ;
}
if ( V_94 )
return F_53 ( V_67 -> V_48 , V_94 ) ;
return NULL ;
}
static int F_54 ( struct V_79 * V_67 )
{
struct V_47 * V_48 = V_67 -> V_48 ;
struct V_68 * V_46 = NULL ;
unsigned V_42 ;
static const struct V_99 {
int V_100 ;
int V_101 ;
} V_102 [ 17 ] = {
{ 640 , 480 } ,
{ 720 , 480 } ,
{ 800 , 600 } ,
{ 848 , 480 } ,
{ 1024 , 768 } ,
{ 1152 , 768 } ,
{ 1280 , 720 } ,
{ 1280 , 800 } ,
{ 1280 , 854 } ,
{ 1280 , 960 } ,
{ 1280 , 1024 } ,
{ 1440 , 900 } ,
{ 1400 , 1050 } ,
{ 1680 , 1050 } ,
{ 1600 , 1200 } ,
{ 1920 , 1080 } ,
{ 1920 , 1200 }
} ;
for ( V_42 = 0 ; V_42 < 17 ; V_42 ++ ) {
V_46 = F_55 ( V_48 , V_102 [ V_42 ] . V_100 , V_102 [ V_42 ] . V_101 , 60 , false , false , false ) ;
F_56 ( V_67 , V_46 ) ;
}
return 0 ;
}
static int F_57 ( struct V_79 * V_67 ,
struct V_68 * V_46 )
{
return V_103 ;
}
static int
F_58 ( struct V_79 * V_67 , int V_46 )
{
return 0 ;
}
static int
F_59 ( struct V_79 * V_67 ,
struct V_104 * V_105 ,
T_5 V_106 )
{
return 0 ;
}
static void F_60 ( struct V_79 * V_67 )
{
F_61 ( V_67 ) ;
F_62 ( V_67 ) ;
F_23 ( V_67 ) ;
}
static void F_63 ( struct V_79 * V_67 )
{
return;
}
static int F_64 ( void * V_90 )
{
int V_58 , V_42 ;
struct V_1 * V_2 = (struct V_1 * ) V_90 ;
V_58 = F_65 ( V_2 , V_107 , 229 , & V_2 -> V_52 ) ;
if ( V_58 )
return V_58 ;
V_2 -> V_82 -> V_108 = 0 ;
V_2 -> V_82 -> V_109 . V_110 = & V_111 ;
V_2 -> V_82 -> V_109 . V_112 = 16384 ;
V_2 -> V_82 -> V_109 . V_113 = 16384 ;
V_2 -> V_82 -> V_109 . V_114 = 24 ;
V_2 -> V_82 -> V_109 . V_115 = 1 ;
V_2 -> V_82 -> V_109 . V_116 = V_2 -> V_117 . V_118 ;
V_58 = F_66 ( V_2 ) ;
if ( V_58 )
return V_58 ;
V_2 -> V_82 -> V_109 . V_112 = 16384 ;
V_2 -> V_82 -> V_109 . V_113 = 16384 ;
for ( V_42 = 0 ; V_42 < V_2 -> V_85 . V_119 ; V_42 ++ ) {
V_58 = F_44 ( V_2 , V_42 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_67 ( V_2 , V_42 ) ;
if ( V_58 )
return V_58 ;
}
F_68 ( V_2 -> V_82 ) ;
V_2 -> V_85 . V_120 = true ;
return 0 ;
}
static int F_69 ( void * V_90 )
{
struct V_1 * V_2 = (struct V_1 * ) V_90 ;
F_23 ( V_2 -> V_85 . V_121 ) ;
F_70 ( V_2 -> V_82 ) ;
F_71 ( V_2 -> V_82 ) ;
V_2 -> V_85 . V_120 = false ;
return 0 ;
}
static int F_72 ( void * V_90 )
{
return 0 ;
}
static int F_73 ( void * V_90 )
{
return 0 ;
}
static int F_74 ( void * V_90 )
{
return F_73 ( V_90 ) ;
}
static int F_75 ( void * V_90 )
{
return F_72 ( V_90 ) ;
}
static bool F_76 ( void * V_90 )
{
return true ;
}
static int F_77 ( void * V_90 )
{
return 0 ;
}
static int F_78 ( void * V_90 )
{
return 0 ;
}
static int F_79 ( void * V_90 ,
enum V_122 V_76 )
{
return 0 ;
}
static int F_80 ( void * V_90 ,
enum V_123 V_76 )
{
return 0 ;
}
static void F_81 ( struct V_93 * V_66 )
{
return;
}
static void F_82 ( struct V_93 * V_66 )
{
return;
}
static void
F_83 ( struct V_93 * V_66 ,
struct V_68 * V_46 ,
struct V_68 * V_69 )
{
return;
}
static void F_84 ( struct V_93 * V_66 )
{
return;
}
static void
F_85 ( struct V_93 * V_66 , int V_46 )
{
return;
}
static bool F_86 ( struct V_93 * V_66 ,
const struct V_68 * V_46 ,
struct V_68 * V_69 )
{
return true ;
}
static void F_87 ( struct V_93 * V_66 )
{
F_88 ( V_66 ) ;
F_23 ( V_66 ) ;
}
static int F_67 ( struct V_1 * V_2 ,
int V_77 )
{
struct V_93 * V_66 ;
struct V_79 * V_67 ;
V_66 = F_45 ( sizeof( struct V_93 ) , V_80 ) ;
if ( ! V_66 )
return - V_81 ;
V_66 -> V_124 = 1 << V_77 ;
F_89 ( V_2 -> V_82 , V_66 , & V_125 ,
V_98 , NULL ) ;
F_90 ( V_66 , & V_126 ) ;
V_67 = F_45 ( sizeof( struct V_79 ) , V_80 ) ;
if ( ! V_67 ) {
F_23 ( V_66 ) ;
return - V_81 ;
}
F_91 ( V_2 -> V_82 , V_67 , & V_127 ,
V_128 ) ;
F_92 ( V_67 , & V_129 ) ;
V_67 -> V_130 . V_131 = V_132 ;
V_67 -> V_133 = false ;
V_67 -> V_134 = false ;
F_93 ( V_67 ) ;
F_94 ( V_67 , V_66 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 )
{
if ( V_2 -> V_85 . V_110 == NULL )
V_2 -> V_85 . V_110 = & V_135 ;
}
static int F_95 ( struct V_1 * V_2 ,
unsigned V_4 )
{
unsigned long V_136 ;
struct V_41 * V_41 ;
struct V_137 * V_138 ;
V_41 = V_2 -> V_85 . V_86 [ V_4 ] ;
if ( V_4 >= V_2 -> V_85 . V_119 ) {
F_15 ( L_3 , V_4 ) ;
return - V_9 ;
}
if ( V_41 == NULL )
return 0 ;
F_96 ( & V_2 -> V_82 -> V_139 , V_136 ) ;
V_138 = V_41 -> V_140 ;
if ( V_41 -> V_141 != V_142 ) {
F_97 ( L_4
L_5 ,
V_41 -> V_141 ,
V_142 ) ;
F_98 ( & V_2 -> V_82 -> V_139 , V_136 ) ;
return 0 ;
}
V_41 -> V_141 = V_143 ;
V_41 -> V_140 = NULL ;
if ( V_138 -> V_144 )
F_99 ( & V_41 -> V_83 , V_138 -> V_144 ) ;
F_98 ( & V_2 -> V_82 -> V_139 , V_136 ) ;
F_100 ( & V_41 -> V_83 ) ;
F_101 ( & V_138 -> V_145 ) ;
return 0 ;
}
static enum V_146 F_102 ( struct V_147 * V_148 )
{
struct V_41 * V_41 = F_103 ( V_148 ,
struct V_41 , V_148 ) ;
struct V_47 * V_82 = V_41 -> V_83 . V_48 ;
struct V_1 * V_2 = V_82 -> V_49 ;
F_104 ( V_82 , V_41 -> V_4 ) ;
F_95 ( V_2 , V_41 -> V_4 ) ;
F_105 ( V_148 , V_149 ,
V_150 ) ;
return V_151 ;
}
static void F_106 ( struct V_1 * V_2 ,
int V_3 ,
enum V_152 V_76 )
{
if ( V_3 >= V_2 -> V_85 . V_119 ) {
F_107 ( L_6 , V_3 ) ;
return;
}
if ( V_76 && ! V_2 -> V_85 . V_86 [ V_3 ] -> V_87 ) {
F_107 ( L_7 ) ;
F_108 ( & V_2 -> V_85 . V_86 [ V_3 ] -> V_148 ,
V_153 , V_150 ) ;
F_109 ( & V_2 -> V_85 . V_86 [ V_3 ] -> V_148 ,
V_149 ) ;
V_2 -> V_85 . V_86 [ V_3 ] -> V_148 . V_154 =
F_102 ;
F_105 ( & V_2 -> V_85 . V_86 [ V_3 ] -> V_148 ,
V_149 , V_150 ) ;
} else if ( ! V_76 && V_2 -> V_85 . V_86 [ V_3 ] -> V_87 ) {
F_107 ( L_8 ) ;
F_110 ( & V_2 -> V_85 . V_86 [ V_3 ] -> V_148 ) ;
}
V_2 -> V_85 . V_86 [ V_3 ] -> V_87 = V_76 ;
F_107 ( L_9 , V_3 , V_76 ) ;
}
static int F_111 ( struct V_1 * V_2 ,
struct V_155 * V_156 ,
unsigned type ,
enum V_152 V_76 )
{
if ( type > V_157 )
return - V_9 ;
F_106 ( V_2 , type , V_76 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 )
{
V_2 -> V_52 . V_158 = V_159 ;
V_2 -> V_52 . V_110 = & V_160 ;
}
