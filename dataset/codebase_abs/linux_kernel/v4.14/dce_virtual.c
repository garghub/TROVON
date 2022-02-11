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
static void F_8 ( struct V_1 * V_2 )
{
return;
}
static int F_9 ( struct V_12 * V_3 , T_3 * V_13 ,
T_3 * V_14 , T_3 * V_15 , T_4 V_16 ,
struct V_17 * V_18 )
{
return 0 ;
}
static void F_10 ( struct V_12 * V_3 )
{
struct V_19 * V_19 = F_11 ( V_3 ) ;
F_12 ( V_3 ) ;
F_13 ( V_19 ) ;
}
static void F_14 ( struct V_12 * V_3 , int V_20 )
{
struct V_21 * V_22 = V_3 -> V_22 ;
struct V_1 * V_2 = V_22 -> V_23 ;
struct V_19 * V_19 = F_11 ( V_3 ) ;
unsigned type ;
if ( F_15 ( V_2 ) )
return;
switch ( V_20 ) {
case V_24 :
V_19 -> V_25 = true ;
type = F_16 ( V_2 , V_19 -> V_4 ) ;
F_17 ( V_2 , & V_2 -> V_26 , type ) ;
F_18 ( V_3 ) ;
break;
case V_27 :
case V_28 :
case V_29 :
F_19 ( V_3 ) ;
V_19 -> V_25 = false ;
break;
}
}
static void F_20 ( struct V_12 * V_3 )
{
F_14 ( V_3 , V_29 ) ;
}
static void F_21 ( struct V_12 * V_3 )
{
F_14 ( V_3 , V_24 ) ;
}
static void F_22 ( struct V_12 * V_3 )
{
struct V_19 * V_19 = F_11 ( V_3 ) ;
F_14 ( V_3 , V_29 ) ;
if ( V_3 -> V_30 -> V_31 ) {
int V_32 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
V_34 = F_23 ( V_3 -> V_30 -> V_31 ) ;
V_36 = F_24 ( V_34 -> V_37 ) ;
V_32 = F_25 ( V_36 , true ) ;
if ( F_26 ( V_32 ) )
F_27 ( L_1 ) ;
else {
F_28 ( V_36 ) ;
F_29 ( V_36 ) ;
}
}
V_19 -> V_38 = V_39 ;
V_19 -> V_40 = NULL ;
V_19 -> V_41 = NULL ;
}
static int F_30 ( struct V_12 * V_3 ,
struct V_42 * V_20 ,
struct V_42 * V_43 ,
int V_44 , int V_45 , struct V_46 * V_47 )
{
struct V_19 * V_19 = F_11 ( V_3 ) ;
V_19 -> V_48 = * V_43 ;
return 0 ;
}
static bool F_31 ( struct V_12 * V_3 ,
const struct V_42 * V_20 ,
struct V_42 * V_43 )
{
return true ;
}
static int F_32 ( struct V_12 * V_3 , int V_44 , int V_45 ,
struct V_46 * V_47 )
{
return 0 ;
}
static int F_33 ( struct V_12 * V_3 ,
struct V_46 * V_31 ,
int V_44 , int V_45 , enum V_49 V_50 )
{
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , int V_51 )
{
struct V_19 * V_19 ;
V_19 = F_35 ( sizeof( struct V_19 ) +
( V_52 * sizeof( struct V_53 * ) ) , V_54 ) ;
if ( V_19 == NULL )
return - V_55 ;
F_36 ( V_2 -> V_56 , & V_19 -> V_57 , & V_58 ) ;
F_37 ( & V_19 -> V_57 , 256 ) ;
V_19 -> V_4 = V_51 ;
V_2 -> V_59 . V_60 [ V_51 ] = V_19 ;
V_19 -> V_38 = V_39 ;
V_19 -> V_40 = NULL ;
V_19 -> V_41 = NULL ;
V_19 -> V_61 = V_62 ;
F_38 ( & V_19 -> V_57 , & V_63 ) ;
return 0 ;
}
static int F_39 ( void * V_64 )
{
struct V_1 * V_2 = (struct V_1 * ) V_64 ;
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
V_2 -> V_59 . V_65 = 1 ;
V_2 -> V_59 . V_66 = 1 ;
return 0 ;
}
static struct V_67 *
F_42 ( struct V_53 * V_41 )
{
int V_68 = V_41 -> V_69 [ 0 ] ;
struct V_67 * V_40 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ ) {
if ( V_41 -> V_69 [ V_70 ] == 0 )
break;
V_40 = F_43 ( V_41 -> V_22 , V_41 -> V_69 [ V_70 ] ) ;
if ( ! V_40 )
continue;
if ( V_40 -> V_72 == V_73 )
return V_40 ;
}
if ( V_68 )
return F_43 ( V_41 -> V_22 , V_68 ) ;
return NULL ;
}
static int F_44 ( struct V_53 * V_41 )
{
struct V_21 * V_22 = V_41 -> V_22 ;
struct V_42 * V_20 = NULL ;
unsigned V_70 ;
static const struct V_74 {
int V_75 ;
int V_76 ;
} V_77 [ 17 ] = {
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
for ( V_70 = 0 ; V_70 < 17 ; V_70 ++ ) {
V_20 = F_45 ( V_22 , V_77 [ V_70 ] . V_75 , V_77 [ V_70 ] . V_76 , 60 , false , false , false ) ;
F_46 ( V_41 , V_20 ) ;
}
return 0 ;
}
static int F_47 ( struct V_53 * V_41 ,
struct V_42 * V_20 )
{
return V_78 ;
}
static int
F_48 ( struct V_53 * V_41 , int V_20 )
{
return 0 ;
}
static int
F_49 ( struct V_53 * V_41 ,
struct V_79 * V_80 ,
T_5 V_81 )
{
return 0 ;
}
static void F_50 ( struct V_53 * V_41 )
{
F_51 ( V_41 ) ;
F_52 ( V_41 ) ;
F_13 ( V_41 ) ;
}
static void F_53 ( struct V_53 * V_41 )
{
return;
}
static int F_54 ( void * V_64 )
{
int V_32 , V_70 ;
struct V_1 * V_2 = (struct V_1 * ) V_64 ;
V_32 = F_55 ( V_2 , V_82 , 229 , & V_2 -> V_26 ) ;
if ( V_32 )
return V_32 ;
V_2 -> V_56 -> V_83 = 0 ;
V_2 -> V_56 -> V_84 . V_85 = & V_86 ;
V_2 -> V_56 -> V_84 . V_87 = 16384 ;
V_2 -> V_56 -> V_84 . V_88 = 16384 ;
V_2 -> V_56 -> V_84 . V_89 = 24 ;
V_2 -> V_56 -> V_84 . V_90 = 1 ;
V_2 -> V_56 -> V_84 . V_91 = V_2 -> V_92 . V_93 ;
V_32 = F_56 ( V_2 ) ;
if ( V_32 )
return V_32 ;
V_2 -> V_56 -> V_84 . V_87 = 16384 ;
V_2 -> V_56 -> V_84 . V_88 = 16384 ;
for ( V_70 = 0 ; V_70 < V_2 -> V_59 . V_94 ; V_70 ++ ) {
V_32 = F_34 ( V_2 , V_70 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_57 ( V_2 , V_70 ) ;
if ( V_32 )
return V_32 ;
}
F_58 ( V_2 -> V_56 ) ;
V_2 -> V_59 . V_95 = true ;
return 0 ;
}
static int F_59 ( void * V_64 )
{
struct V_1 * V_2 = (struct V_1 * ) V_64 ;
F_13 ( V_2 -> V_59 . V_96 ) ;
F_60 ( V_2 -> V_56 ) ;
F_61 ( V_2 -> V_56 ) ;
V_2 -> V_59 . V_95 = false ;
return 0 ;
}
static int F_62 ( void * V_64 )
{
struct V_1 * V_2 = (struct V_1 * ) V_64 ;
switch ( V_2 -> V_97 ) {
#ifdef F_63
case V_98 :
case V_99 :
case V_100 :
case V_101 :
F_64 ( V_2 ) ;
break;
#endif
#ifdef F_65
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
F_66 ( V_2 ) ;
break;
#endif
case V_107 :
case V_108 :
F_67 ( V_2 ) ;
break;
case V_109 :
case V_110 :
case V_111 :
case V_112 :
F_68 ( V_2 ) ;
break;
case V_113 :
#ifdef F_63
case V_114 :
#endif
break;
case V_115 :
break;
default:
F_27 ( L_2 , V_2 -> V_97 ) ;
}
return 0 ;
}
static int F_69 ( void * V_64 )
{
return 0 ;
}
static int F_70 ( void * V_64 )
{
return F_69 ( V_64 ) ;
}
static int F_71 ( void * V_64 )
{
return F_62 ( V_64 ) ;
}
static bool F_72 ( void * V_64 )
{
return true ;
}
static int F_73 ( void * V_64 )
{
return 0 ;
}
static int F_74 ( void * V_64 )
{
return 0 ;
}
static int F_75 ( void * V_64 ,
enum V_116 V_50 )
{
return 0 ;
}
static int F_76 ( void * V_64 ,
enum V_117 V_50 )
{
return 0 ;
}
static void F_77 ( struct V_67 * V_40 )
{
return;
}
static void F_78 ( struct V_67 * V_40 )
{
return;
}
static void
F_79 ( struct V_67 * V_40 ,
struct V_42 * V_20 ,
struct V_42 * V_43 )
{
return;
}
static void F_80 ( struct V_67 * V_40 )
{
return;
}
static void
F_81 ( struct V_67 * V_40 , int V_20 )
{
return;
}
static bool F_82 ( struct V_67 * V_40 ,
const struct V_42 * V_20 ,
struct V_42 * V_43 )
{
return true ;
}
static void F_83 ( struct V_67 * V_40 )
{
F_84 ( V_40 ) ;
F_13 ( V_40 ) ;
}
static int F_57 ( struct V_1 * V_2 ,
int V_51 )
{
struct V_67 * V_40 ;
struct V_53 * V_41 ;
V_40 = F_35 ( sizeof( struct V_67 ) , V_54 ) ;
if ( ! V_40 )
return - V_55 ;
V_40 -> V_118 = 1 << V_51 ;
F_85 ( V_2 -> V_56 , V_40 , & V_119 ,
V_73 , NULL ) ;
F_86 ( V_40 , & V_120 ) ;
V_41 = F_35 ( sizeof( struct V_53 ) , V_54 ) ;
if ( ! V_41 ) {
F_13 ( V_40 ) ;
return - V_55 ;
}
F_87 ( V_2 -> V_56 , V_41 , & V_121 ,
V_122 ) ;
F_88 ( V_41 , & V_123 ) ;
V_41 -> V_124 . V_125 = V_126 ;
V_41 -> V_127 = false ;
V_41 -> V_128 = false ;
F_89 ( V_41 ) ;
F_90 ( V_41 , V_40 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 )
{
if ( V_2 -> V_59 . V_85 == NULL )
V_2 -> V_59 . V_85 = & V_129 ;
}
static int F_91 ( struct V_1 * V_2 ,
unsigned V_4 )
{
unsigned long V_130 ;
struct V_19 * V_19 ;
struct V_131 * V_132 ;
V_19 = V_2 -> V_59 . V_60 [ V_4 ] ;
if ( V_4 >= V_2 -> V_59 . V_94 ) {
F_27 ( L_3 , V_4 ) ;
return - V_9 ;
}
if ( V_19 == NULL )
return 0 ;
F_92 ( & V_2 -> V_56 -> V_133 , V_130 ) ;
V_132 = V_19 -> V_134 ;
if ( V_19 -> V_135 != V_136 ) {
F_93 ( L_4
L_5 ,
V_19 -> V_135 ,
V_136 ) ;
F_94 ( & V_2 -> V_56 -> V_133 , V_130 ) ;
return 0 ;
}
V_19 -> V_135 = V_137 ;
V_19 -> V_134 = NULL ;
if ( V_132 -> V_138 )
F_95 ( & V_19 -> V_57 , V_132 -> V_138 ) ;
F_94 ( & V_2 -> V_56 -> V_133 , V_130 ) ;
F_96 ( & V_19 -> V_57 ) ;
F_97 ( & V_132 -> V_139 ) ;
return 0 ;
}
static enum V_140 F_98 ( struct V_141 * V_142 )
{
struct V_19 * V_19 = F_99 ( V_142 ,
struct V_19 , V_142 ) ;
struct V_21 * V_56 = V_19 -> V_57 . V_22 ;
struct V_1 * V_2 = V_56 -> V_23 ;
F_100 ( V_56 , V_19 -> V_4 ) ;
F_91 ( V_2 , V_19 -> V_4 ) ;
F_101 ( V_142 , V_143 ,
V_144 ) ;
return V_145 ;
}
static void F_102 ( struct V_1 * V_2 ,
int V_3 ,
enum V_146 V_50 )
{
if ( V_3 >= V_2 -> V_59 . V_94 ) {
F_103 ( L_6 , V_3 ) ;
return;
}
if ( V_50 && ! V_2 -> V_59 . V_60 [ V_3 ] -> V_61 ) {
F_103 ( L_7 ) ;
F_104 ( & V_2 -> V_59 . V_60 [ V_3 ] -> V_142 ,
V_147 , V_144 ) ;
F_105 ( & V_2 -> V_59 . V_60 [ V_3 ] -> V_142 ,
V_143 ) ;
V_2 -> V_59 . V_60 [ V_3 ] -> V_142 . V_148 =
F_98 ;
F_101 ( & V_2 -> V_59 . V_60 [ V_3 ] -> V_142 ,
V_143 , V_144 ) ;
} else if ( ! V_50 && V_2 -> V_59 . V_60 [ V_3 ] -> V_61 ) {
F_103 ( L_8 ) ;
F_106 ( & V_2 -> V_59 . V_60 [ V_3 ] -> V_142 ) ;
}
V_2 -> V_59 . V_60 [ V_3 ] -> V_61 = V_50 ;
F_103 ( L_9 , V_3 , V_50 ) ;
}
static int F_107 ( struct V_1 * V_2 ,
struct V_149 * V_150 ,
unsigned type ,
enum V_146 V_50 )
{
if ( type > V_151 )
return - V_9 ;
F_102 ( V_2 , type , V_50 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
V_2 -> V_26 . V_152 = V_151 + 1 ;
V_2 -> V_26 . V_85 = & V_153 ;
}
