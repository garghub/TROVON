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
F_14 ( V_2 ) ;
break;
case V_30 :
#ifdef F_9
case V_31 :
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
bool V_32 )
{
return;
}
static void F_18 ( struct V_1 * V_2 )
{
return;
}
static int F_19 ( struct V_33 * V_3 , T_3 * V_34 ,
T_3 * V_35 , T_3 * V_36 , T_4 V_37 )
{
struct V_38 * V_38 = F_20 ( V_3 ) ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_37 ; V_39 ++ ) {
V_38 -> V_40 [ V_39 ] = V_34 [ V_39 ] >> 6 ;
V_38 -> V_41 [ V_39 ] = V_35 [ V_39 ] >> 6 ;
V_38 -> V_42 [ V_39 ] = V_36 [ V_39 ] >> 6 ;
}
return 0 ;
}
static void F_21 ( struct V_33 * V_3 )
{
struct V_38 * V_38 = F_20 ( V_3 ) ;
F_22 ( V_3 ) ;
F_23 ( V_38 ) ;
}
static void F_24 ( struct V_33 * V_3 , int V_43 )
{
struct V_44 * V_45 = V_3 -> V_45 ;
struct V_1 * V_2 = V_45 -> V_46 ;
struct V_38 * V_38 = F_20 ( V_3 ) ;
unsigned type ;
switch ( V_43 ) {
case V_47 :
V_38 -> V_48 = true ;
type = F_25 ( V_2 , V_38 -> V_4 ) ;
F_26 ( V_2 , & V_2 -> V_49 , type ) ;
F_27 ( V_3 ) ;
break;
case V_50 :
case V_51 :
case V_52 :
F_28 ( V_3 ) ;
V_38 -> V_48 = false ;
break;
}
}
static void F_29 ( struct V_33 * V_3 )
{
F_24 ( V_3 , V_52 ) ;
}
static void F_30 ( struct V_33 * V_3 )
{
F_24 ( V_3 , V_47 ) ;
}
static void F_31 ( struct V_33 * V_3 )
{
struct V_38 * V_38 = F_20 ( V_3 ) ;
F_24 ( V_3 , V_52 ) ;
if ( V_3 -> V_53 -> V_54 ) {
int V_55 ;
struct V_56 * V_57 ;
struct V_58 * V_59 ;
V_57 = F_32 ( V_3 -> V_53 -> V_54 ) ;
V_59 = F_33 ( V_57 -> V_60 ) ;
V_55 = F_34 ( V_59 , false ) ;
if ( F_35 ( V_55 ) )
F_15 ( L_2 ) ;
else {
F_36 ( V_59 ) ;
F_37 ( V_59 ) ;
}
}
V_38 -> V_61 = V_62 ;
V_38 -> V_63 = NULL ;
V_38 -> V_64 = NULL ;
}
static int F_38 ( struct V_33 * V_3 ,
struct V_65 * V_43 ,
struct V_65 * V_66 ,
int V_67 , int V_68 , struct V_69 * V_70 )
{
struct V_38 * V_38 = F_20 ( V_3 ) ;
V_38 -> V_71 = * V_66 ;
return 0 ;
}
static bool F_39 ( struct V_33 * V_3 ,
const struct V_65 * V_43 ,
struct V_65 * V_66 )
{
return true ;
}
static int F_40 ( struct V_33 * V_3 , int V_67 , int V_68 ,
struct V_69 * V_70 )
{
return 0 ;
}
static void F_41 ( struct V_33 * V_3 )
{
return;
}
static int F_42 ( struct V_33 * V_3 ,
struct V_69 * V_54 ,
int V_67 , int V_68 , enum V_72 V_73 )
{
return 0 ;
}
static int F_43 ( struct V_1 * V_2 , int V_74 )
{
struct V_38 * V_38 ;
int V_39 ;
V_38 = F_44 ( sizeof( struct V_38 ) +
( V_75 * sizeof( struct V_76 * ) ) , V_77 ) ;
if ( V_38 == NULL )
return - V_78 ;
F_45 ( V_2 -> V_79 , & V_38 -> V_80 , & V_81 ) ;
F_46 ( & V_38 -> V_80 , 256 ) ;
V_38 -> V_4 = V_74 ;
V_2 -> V_82 . V_83 [ V_74 ] = V_38 ;
for ( V_39 = 0 ; V_39 < 256 ; V_39 ++ ) {
V_38 -> V_40 [ V_39 ] = V_39 << 2 ;
V_38 -> V_41 [ V_39 ] = V_39 << 2 ;
V_38 -> V_42 [ V_39 ] = V_39 << 2 ;
}
V_38 -> V_61 = V_62 ;
V_38 -> V_63 = NULL ;
V_38 -> V_64 = NULL ;
V_38 -> V_84 = V_85 ;
F_47 ( & V_38 -> V_80 , & V_86 ) ;
return 0 ;
}
static int F_48 ( void * V_87 )
{
struct V_1 * V_2 = (struct V_1 * ) V_87 ;
F_49 ( V_2 ) ;
F_50 ( V_2 ) ;
V_2 -> V_82 . V_88 = 1 ;
V_2 -> V_82 . V_89 = 1 ;
return 0 ;
}
static struct V_90 *
F_51 ( struct V_76 * V_64 )
{
int V_91 = V_64 -> V_92 [ 0 ] ;
struct V_90 * V_63 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_93 ; V_39 ++ ) {
if ( V_64 -> V_92 [ V_39 ] == 0 )
break;
V_63 = F_52 ( V_64 -> V_45 , V_64 -> V_92 [ V_39 ] ) ;
if ( ! V_63 )
continue;
if ( V_63 -> V_94 == V_95 )
return V_63 ;
}
if ( V_91 )
return F_52 ( V_64 -> V_45 , V_91 ) ;
return NULL ;
}
static int F_53 ( struct V_76 * V_64 )
{
struct V_44 * V_45 = V_64 -> V_45 ;
struct V_65 * V_43 = NULL ;
unsigned V_39 ;
static const struct V_96 {
int V_97 ;
int V_98 ;
} V_99 [ 17 ] = {
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
for ( V_39 = 0 ; V_39 < 17 ; V_39 ++ ) {
V_43 = F_54 ( V_45 , V_99 [ V_39 ] . V_97 , V_99 [ V_39 ] . V_98 , 60 , false , false , false ) ;
F_55 ( V_64 , V_43 ) ;
}
return 0 ;
}
static int F_56 ( struct V_76 * V_64 ,
struct V_65 * V_43 )
{
return V_100 ;
}
static int
F_57 ( struct V_76 * V_64 , int V_43 )
{
return 0 ;
}
static int
F_58 ( struct V_76 * V_64 ,
struct V_101 * V_102 ,
T_5 V_103 )
{
return 0 ;
}
static void F_59 ( struct V_76 * V_64 )
{
F_60 ( V_64 ) ;
F_61 ( V_64 ) ;
F_23 ( V_64 ) ;
}
static void F_62 ( struct V_76 * V_64 )
{
return;
}
static int F_63 ( void * V_87 )
{
int V_55 , V_39 ;
struct V_1 * V_2 = (struct V_1 * ) V_87 ;
V_55 = F_64 ( V_2 , 229 , & V_2 -> V_49 ) ;
if ( V_55 )
return V_55 ;
V_2 -> V_79 -> V_104 = 0 ;
V_2 -> V_79 -> V_105 . V_106 = & V_107 ;
V_2 -> V_79 -> V_105 . V_108 = 16384 ;
V_2 -> V_79 -> V_105 . V_109 = 16384 ;
V_2 -> V_79 -> V_105 . V_110 = 24 ;
V_2 -> V_79 -> V_105 . V_111 = 1 ;
V_2 -> V_79 -> V_105 . V_112 = V_2 -> V_113 . V_114 ;
V_55 = F_65 ( V_2 ) ;
if ( V_55 )
return V_55 ;
V_2 -> V_79 -> V_105 . V_108 = 16384 ;
V_2 -> V_79 -> V_105 . V_109 = 16384 ;
for ( V_39 = 0 ; V_39 < V_2 -> V_82 . V_115 ; V_39 ++ ) {
V_55 = F_43 ( V_2 , V_39 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_66 ( V_2 , V_39 ) ;
if ( V_55 )
return V_55 ;
}
F_67 ( V_2 -> V_79 ) ;
V_2 -> V_82 . V_116 = true ;
return 0 ;
}
static int F_68 ( void * V_87 )
{
struct V_1 * V_2 = (struct V_1 * ) V_87 ;
F_23 ( V_2 -> V_82 . V_117 ) ;
F_69 ( V_2 -> V_79 ) ;
F_70 ( V_2 -> V_79 ) ;
V_2 -> V_82 . V_116 = false ;
return 0 ;
}
static int F_71 ( void * V_87 )
{
return 0 ;
}
static int F_72 ( void * V_87 )
{
return 0 ;
}
static int F_73 ( void * V_87 )
{
return F_72 ( V_87 ) ;
}
static int F_74 ( void * V_87 )
{
return F_71 ( V_87 ) ;
}
static bool F_75 ( void * V_87 )
{
return true ;
}
static int F_76 ( void * V_87 )
{
return 0 ;
}
static int F_77 ( void * V_87 )
{
return 0 ;
}
static int F_78 ( void * V_87 ,
enum V_118 V_73 )
{
return 0 ;
}
static int F_79 ( void * V_87 ,
enum V_119 V_73 )
{
return 0 ;
}
static void F_80 ( struct V_90 * V_63 )
{
return;
}
static void F_81 ( struct V_90 * V_63 )
{
return;
}
static void
F_82 ( struct V_90 * V_63 ,
struct V_65 * V_43 ,
struct V_65 * V_66 )
{
return;
}
static void F_83 ( struct V_90 * V_63 )
{
return;
}
static void
F_84 ( struct V_90 * V_63 , int V_43 )
{
return;
}
static bool F_85 ( struct V_90 * V_63 ,
const struct V_65 * V_43 ,
struct V_65 * V_66 )
{
return true ;
}
static void F_86 ( struct V_90 * V_63 )
{
F_87 ( V_63 ) ;
F_23 ( V_63 ) ;
}
static int F_66 ( struct V_1 * V_2 ,
int V_74 )
{
struct V_90 * V_63 ;
struct V_76 * V_64 ;
V_63 = F_44 ( sizeof( struct V_90 ) , V_77 ) ;
if ( ! V_63 )
return - V_78 ;
V_63 -> V_120 = 1 << V_74 ;
F_88 ( V_2 -> V_79 , V_63 , & V_121 ,
V_95 , NULL ) ;
F_89 ( V_63 , & V_122 ) ;
V_64 = F_44 ( sizeof( struct V_76 ) , V_77 ) ;
if ( ! V_64 ) {
F_23 ( V_63 ) ;
return - V_78 ;
}
F_90 ( V_2 -> V_79 , V_64 , & V_123 ,
V_124 ) ;
F_91 ( V_64 , & V_125 ) ;
V_64 -> V_126 . V_127 = V_128 ;
V_64 -> V_129 = false ;
V_64 -> V_130 = false ;
F_92 ( V_64 ) ;
F_93 ( V_64 , V_63 ) ;
return 0 ;
}
static void F_49 ( struct V_1 * V_2 )
{
if ( V_2 -> V_82 . V_106 == NULL )
V_2 -> V_82 . V_106 = & V_131 ;
}
static int F_94 ( struct V_1 * V_2 ,
unsigned V_4 )
{
unsigned long V_132 ;
struct V_38 * V_38 ;
struct V_133 * V_134 ;
V_38 = V_2 -> V_82 . V_83 [ V_4 ] ;
if ( V_4 >= V_2 -> V_82 . V_115 ) {
F_15 ( L_3 , V_4 ) ;
return - V_9 ;
}
if ( V_38 == NULL )
return 0 ;
F_95 ( & V_2 -> V_79 -> V_135 , V_132 ) ;
V_134 = V_38 -> V_136 ;
if ( V_38 -> V_137 != V_138 ) {
F_96 ( L_4
L_5 ,
V_38 -> V_137 ,
V_138 ) ;
F_97 ( & V_2 -> V_79 -> V_135 , V_132 ) ;
return 0 ;
}
V_38 -> V_137 = V_139 ;
V_38 -> V_136 = NULL ;
if ( V_134 -> V_140 )
F_98 ( & V_38 -> V_80 , V_134 -> V_140 ) ;
F_97 ( & V_2 -> V_79 -> V_135 , V_132 ) ;
F_99 ( & V_38 -> V_80 ) ;
F_100 ( & V_134 -> V_141 ) ;
return 0 ;
}
static enum V_142 F_101 ( struct V_143 * V_144 )
{
struct V_38 * V_38 = F_102 ( V_144 ,
struct V_38 , V_144 ) ;
struct V_44 * V_79 = V_38 -> V_80 . V_45 ;
struct V_1 * V_2 = V_79 -> V_46 ;
F_103 ( V_79 , V_38 -> V_4 ) ;
F_94 ( V_2 , V_38 -> V_4 ) ;
F_104 ( V_144 , V_145 ,
V_146 ) ;
return V_147 ;
}
static void F_105 ( struct V_1 * V_2 ,
int V_3 ,
enum V_148 V_73 )
{
if ( V_3 >= V_2 -> V_82 . V_115 ) {
F_106 ( L_6 , V_3 ) ;
return;
}
if ( V_73 && ! V_2 -> V_82 . V_83 [ V_3 ] -> V_84 ) {
F_106 ( L_7 ) ;
F_107 ( & V_2 -> V_82 . V_83 [ V_3 ] -> V_144 ,
V_149 , V_146 ) ;
F_108 ( & V_2 -> V_82 . V_83 [ V_3 ] -> V_144 ,
V_145 ) ;
V_2 -> V_82 . V_83 [ V_3 ] -> V_144 . V_150 =
F_101 ;
F_104 ( & V_2 -> V_82 . V_83 [ V_3 ] -> V_144 ,
V_145 , V_146 ) ;
} else if ( ! V_73 && V_2 -> V_82 . V_83 [ V_3 ] -> V_84 ) {
F_106 ( L_8 ) ;
F_109 ( & V_2 -> V_82 . V_83 [ V_3 ] -> V_144 ) ;
}
V_2 -> V_82 . V_83 [ V_3 ] -> V_84 = V_73 ;
F_106 ( L_9 , V_3 , V_73 ) ;
}
static int F_110 ( struct V_1 * V_2 ,
struct V_151 * V_152 ,
unsigned type ,
enum V_148 V_73 )
{
if ( type > V_153 )
return - V_9 ;
F_105 ( V_2 , type , V_73 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 )
{
V_2 -> V_49 . V_154 = V_155 ;
V_2 -> V_49 . V_106 = & V_156 ;
}
