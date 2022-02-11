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
static bool F_8 ( struct V_1 * V_2 )
{
return false ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
switch ( V_2 -> V_14 ) {
#ifdef F_10
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
F_11 ( V_2 ) ;
break;
#endif
case V_20 :
case V_21 :
F_12 ( V_2 ) ;
break;
case V_22 :
case V_23 :
case V_24 :
case V_25 :
F_13 ( V_2 ) ;
break;
case V_26 :
return;
default:
F_14 ( L_1 , V_2 -> V_14 ) ;
}
return;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
return;
}
static void F_16 ( struct V_1 * V_2 ,
bool V_27 )
{
return;
}
static void F_17 ( struct V_1 * V_2 )
{
return;
}
static int F_18 ( struct V_28 * V_3 , T_3 * V_29 ,
T_3 * V_30 , T_3 * V_31 , T_4 V_32 )
{
struct V_33 * V_33 = F_19 ( V_3 ) ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_32 ; V_34 ++ ) {
V_33 -> V_35 [ V_34 ] = V_29 [ V_34 ] >> 6 ;
V_33 -> V_36 [ V_34 ] = V_30 [ V_34 ] >> 6 ;
V_33 -> V_37 [ V_34 ] = V_31 [ V_34 ] >> 6 ;
}
return 0 ;
}
static void F_20 ( struct V_28 * V_3 )
{
struct V_33 * V_33 = F_19 ( V_3 ) ;
F_21 ( V_3 ) ;
F_22 ( V_33 ) ;
}
static void F_23 ( struct V_28 * V_3 , int V_38 )
{
struct V_39 * V_40 = V_3 -> V_40 ;
struct V_1 * V_2 = V_40 -> V_41 ;
struct V_33 * V_33 = F_19 ( V_3 ) ;
unsigned type ;
switch ( V_38 ) {
case V_42 :
V_33 -> V_43 = true ;
type = F_24 ( V_2 , V_33 -> V_4 ) ;
F_25 ( V_2 , & V_2 -> V_44 , type ) ;
F_25 ( V_2 , & V_2 -> V_45 , type ) ;
F_26 ( V_40 , V_33 -> V_4 ) ;
break;
case V_46 :
case V_47 :
case V_48 :
F_27 ( V_40 , V_33 -> V_4 ) ;
V_33 -> V_43 = false ;
break;
}
}
static void F_28 ( struct V_28 * V_3 )
{
F_23 ( V_3 , V_48 ) ;
}
static void F_29 ( struct V_28 * V_3 )
{
F_23 ( V_3 , V_42 ) ;
}
static void F_30 ( struct V_28 * V_3 )
{
struct V_33 * V_33 = F_19 ( V_3 ) ;
F_23 ( V_3 , V_48 ) ;
if ( V_3 -> V_49 -> V_50 ) {
int V_51 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
V_53 = F_31 ( V_3 -> V_49 -> V_50 ) ;
V_55 = F_32 ( V_53 -> V_56 ) ;
V_51 = F_33 ( V_55 , false ) ;
if ( F_34 ( V_51 ) )
F_14 ( L_2 ) ;
else {
F_35 ( V_55 ) ;
F_36 ( V_55 ) ;
}
}
V_33 -> V_57 = V_58 ;
V_33 -> V_59 = NULL ;
V_33 -> V_60 = NULL ;
}
static int F_37 ( struct V_28 * V_3 ,
struct V_61 * V_38 ,
struct V_61 * V_62 ,
int V_63 , int V_64 , struct V_65 * V_66 )
{
struct V_33 * V_33 = F_19 ( V_3 ) ;
V_33 -> V_67 = * V_62 ;
return 0 ;
}
static bool F_38 ( struct V_28 * V_3 ,
const struct V_61 * V_38 ,
struct V_61 * V_62 )
{
struct V_33 * V_33 = F_19 ( V_3 ) ;
struct V_39 * V_40 = V_3 -> V_40 ;
struct V_68 * V_59 ;
F_39 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_59 -> V_3 == V_3 ) {
V_33 -> V_59 = V_59 ;
V_33 -> V_60 = F_40 ( V_59 ) ;
break;
}
}
if ( ( V_33 -> V_59 == NULL ) || ( V_33 -> V_60 == NULL ) ) {
V_33 -> V_59 = NULL ;
V_33 -> V_60 = NULL ;
return false ;
}
return true ;
}
static int F_41 ( struct V_28 * V_3 , int V_63 , int V_64 ,
struct V_65 * V_66 )
{
return 0 ;
}
static void F_42 ( struct V_28 * V_3 )
{
return;
}
static int F_43 ( struct V_28 * V_3 ,
struct V_65 * V_50 ,
int V_63 , int V_64 , enum V_69 V_70 )
{
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , int V_71 )
{
struct V_33 * V_33 ;
int V_34 ;
V_33 = F_45 ( sizeof( struct V_33 ) +
( V_72 * sizeof( struct V_73 * ) ) , V_74 ) ;
if ( V_33 == NULL )
return - V_75 ;
F_46 ( V_2 -> V_76 , & V_33 -> V_77 , & V_78 ) ;
F_47 ( & V_33 -> V_77 , 256 ) ;
V_33 -> V_4 = V_71 ;
V_2 -> V_79 . V_80 [ V_71 ] = V_33 ;
for ( V_34 = 0 ; V_34 < 256 ; V_34 ++ ) {
V_33 -> V_35 [ V_34 ] = V_34 << 2 ;
V_33 -> V_36 [ V_34 ] = V_34 << 2 ;
V_33 -> V_37 [ V_34 ] = V_34 << 2 ;
}
V_33 -> V_57 = V_58 ;
V_33 -> V_59 = NULL ;
V_33 -> V_60 = NULL ;
F_48 ( & V_33 -> V_77 , & V_81 ) ;
return 0 ;
}
static int F_49 ( void * V_82 )
{
struct V_1 * V_2 = (struct V_1 * ) V_82 ;
V_2 -> V_79 . V_83 = V_84 ;
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
V_2 -> V_79 . V_85 = 1 ;
V_2 -> V_79 . V_86 = 1 ;
V_2 -> V_79 . V_87 = 1 ;
return 0 ;
}
static bool F_52 ( struct V_1 * V_2 )
{
struct V_88 V_89 ;
struct V_90 V_91 ;
struct V_92 V_11 ;
V_89 . V_93 = false ;
V_11 . V_11 = V_94 ;
V_89 . V_11 = V_11 . V_11 ;
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
V_91 . V_95 = false ;
V_91 . V_96 = false ;
F_53 ( V_2 ,
0 ,
V_97 ,
V_98 , & V_89 ,
V_99 ,
& V_11 ,
& V_91 ) ;
F_54 ( V_2 , V_100 ,
V_97 ,
0 ) ;
F_55 ( V_2 -> V_76 ) ;
return true ;
}
static int F_56 ( void * V_82 )
{
int V_51 , V_34 ;
struct V_1 * V_2 = (struct V_1 * ) V_82 ;
V_51 = F_57 ( V_2 , 229 , & V_2 -> V_44 ) ;
if ( V_51 )
return V_51 ;
V_2 -> V_76 -> V_101 = 0 ;
V_2 -> V_76 -> V_102 . V_103 = & V_104 ;
V_2 -> V_76 -> V_102 . V_105 = 16384 ;
V_2 -> V_76 -> V_102 . V_106 = 16384 ;
V_2 -> V_76 -> V_102 . V_107 = 24 ;
V_2 -> V_76 -> V_102 . V_108 = 1 ;
V_2 -> V_76 -> V_102 . V_109 = V_2 -> V_110 . V_111 ;
V_51 = F_58 ( V_2 ) ;
if ( V_51 )
return V_51 ;
V_2 -> V_76 -> V_102 . V_105 = 16384 ;
V_2 -> V_76 -> V_102 . V_106 = 16384 ;
for ( V_34 = 0 ; V_34 < V_2 -> V_79 . V_85 ; V_34 ++ ) {
V_51 = F_44 ( V_2 , V_34 ) ;
if ( V_51 )
return V_51 ;
}
F_52 ( V_2 ) ;
F_59 ( V_2 -> V_76 ) ;
F_60 ( V_2 -> V_76 ) ;
V_2 -> V_79 . V_112 = true ;
return 0 ;
}
static int F_61 ( void * V_82 )
{
struct V_1 * V_2 = (struct V_1 * ) V_82 ;
F_22 ( V_2 -> V_79 . V_113 ) ;
F_62 ( V_2 -> V_76 ) ;
F_63 ( V_2 -> V_76 ) ;
V_2 -> V_79 . V_112 = false ;
return 0 ;
}
static int F_64 ( void * V_82 )
{
return 0 ;
}
static int F_65 ( void * V_82 )
{
return 0 ;
}
static int F_66 ( void * V_82 )
{
return F_65 ( V_82 ) ;
}
static int F_67 ( void * V_82 )
{
return F_64 ( V_82 ) ;
}
static bool F_68 ( void * V_82 )
{
return true ;
}
static int F_69 ( void * V_82 )
{
return 0 ;
}
static int F_70 ( void * V_82 )
{
return 0 ;
}
static int F_71 ( void * V_82 ,
enum V_114 V_70 )
{
return 0 ;
}
static int F_72 ( void * V_82 ,
enum V_115 V_70 )
{
return 0 ;
}
static void F_73 ( struct V_68 * V_59 )
{
return;
}
static void F_74 ( struct V_68 * V_59 )
{
return;
}
static void
F_75 ( struct V_68 * V_59 ,
struct V_61 * V_38 ,
struct V_61 * V_62 )
{
return;
}
static void F_76 ( struct V_68 * V_59 )
{
return;
}
static void
F_77 ( struct V_68 * V_59 , int V_38 )
{
return;
}
static bool F_78 ( struct V_68 * V_59 ,
const struct V_61 * V_38 ,
struct V_61 * V_62 )
{
F_79 ( V_59 ) ;
return true ;
}
static void F_80 ( struct V_68 * V_59 )
{
struct V_116 * V_116 = F_81 ( V_59 ) ;
F_22 ( V_116 -> V_117 ) ;
F_82 ( V_59 ) ;
F_22 ( V_116 ) ;
}
static void F_83 ( struct V_1 * V_2 ,
T_4 V_118 ,
T_4 V_119 ,
T_3 V_120 )
{
struct V_39 * V_40 = V_2 -> V_76 ;
struct V_68 * V_59 ;
struct V_116 * V_116 ;
F_39 (encoder, &dev->mode_config.encoder_list, head) {
V_116 = F_81 ( V_59 ) ;
if ( V_116 -> V_118 == V_118 ) {
V_116 -> V_121 |= V_119 ;
return;
}
}
V_116 = F_45 ( sizeof( struct V_116 ) , V_74 ) ;
if ( ! V_116 )
return;
V_59 = & V_116 -> V_77 ;
V_59 -> V_122 = 0x1 ;
V_116 -> V_117 = NULL ;
V_116 -> V_118 = V_118 ;
V_116 -> V_123 = ( V_118 & V_124 ) >> V_125 ;
V_116 -> V_121 = V_119 ;
V_116 -> V_126 = V_127 ;
V_116 -> V_128 = V_129 ;
V_116 -> V_130 = false ;
V_116 -> V_120 = V_120 ;
F_84 ( V_40 , V_59 , & V_131 ,
V_132 , NULL ) ;
F_85 ( V_59 , & V_133 ) ;
F_86 ( L_3 , V_116 -> V_123 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
if ( V_2 -> V_79 . V_103 == NULL )
V_2 -> V_79 . V_103 = & V_134 ;
}
static enum V_135 F_87 ( struct V_136 * V_137 )
{
struct V_138 * V_79 = F_88 ( V_137 , struct V_138 , V_137 ) ;
struct V_1 * V_2 = F_88 ( V_79 , struct V_1 , V_79 ) ;
unsigned V_3 = 0 ;
F_89 ( V_2 -> V_76 , V_3 ) ;
F_90 ( V_2 , NULL , NULL ) ;
F_91 ( V_137 , F_92 ( 0 , V_139 ) , V_140 ) ;
return V_141 ;
}
static void F_93 ( struct V_1 * V_2 ,
int V_3 ,
enum V_142 V_70 )
{
if ( V_3 >= V_2 -> V_79 . V_85 ) {
F_94 ( L_4 , V_3 ) ;
return;
}
if ( V_70 && ! V_2 -> V_79 . V_83 ) {
F_94 ( L_5 ) ;
F_95 ( & V_2 -> V_79 . V_137 , V_143 , V_140 ) ;
F_96 ( & V_2 -> V_79 . V_137 , F_92 ( 0 , V_139 ) ) ;
V_2 -> V_79 . V_137 . V_144 = F_87 ;
F_91 ( & V_2 -> V_79 . V_137 , F_92 ( 0 , V_139 ) , V_140 ) ;
} else if ( ! V_70 && V_2 -> V_79 . V_83 ) {
F_94 ( L_6 ) ;
F_97 ( & V_2 -> V_79 . V_137 ) ;
}
V_2 -> V_79 . V_83 = V_70 ;
F_94 ( L_7 , V_3 , V_70 ) ;
}
static int F_98 ( struct V_1 * V_2 ,
struct V_145 * V_146 ,
unsigned type ,
enum V_142 V_70 )
{
switch ( type ) {
case V_147 :
F_93 ( V_2 , 0 , V_70 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_99 ( struct V_1 * V_2 ,
int V_3 )
{
if ( V_3 >= V_2 -> V_79 . V_85 ) {
F_94 ( L_4 , V_3 ) ;
return;
}
}
static int F_100 ( struct V_1 * V_2 ,
struct V_145 * V_146 ,
struct V_148 * V_149 )
{
unsigned V_3 = 0 ;
unsigned V_150 = V_147 ;
F_99 ( V_2 , V_3 ) ;
if ( F_101 ( V_2 , V_146 , V_150 ) ) {
F_89 ( V_2 -> V_76 , V_3 ) ;
}
F_90 ( V_2 , NULL , NULL ) ;
F_94 ( L_8 , V_3 + 1 ) ;
return 0 ;
}
static int F_102 ( struct V_1 * V_2 ,
struct V_145 * V_151 ,
unsigned type ,
enum V_142 V_70 )
{
if ( type >= V_2 -> V_79 . V_85 ) {
F_14 ( L_9 , type ) ;
return - V_9 ;
}
F_94 ( L_10 , type , V_70 ) ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_145 * V_146 ,
struct V_148 * V_149 )
{
unsigned long V_152 ;
unsigned V_4 = 0 ;
struct V_33 * V_33 ;
struct V_153 * V_154 ;
V_4 = 0 ;
V_33 = V_2 -> V_79 . V_80 [ V_4 ] ;
if ( V_4 >= V_2 -> V_79 . V_85 ) {
F_14 ( L_9 , V_4 ) ;
return - V_9 ;
}
if ( V_33 == NULL )
return 0 ;
F_103 ( & V_2 -> V_76 -> V_155 , V_152 ) ;
V_154 = V_33 -> V_156 ;
if ( V_33 -> V_157 != V_158 ) {
F_104 ( L_11
L_12 ,
V_33 -> V_157 ,
V_158 ) ;
F_105 ( & V_2 -> V_76 -> V_155 , V_152 ) ;
return 0 ;
}
V_33 -> V_157 = V_159 ;
V_33 -> V_156 = NULL ;
if ( V_154 -> V_160 )
F_106 ( & V_33 -> V_77 , V_154 -> V_160 ) ;
F_105 ( & V_2 -> V_76 -> V_155 , V_152 ) ;
F_107 ( & V_33 -> V_77 ) ;
F_108 ( & V_154 -> V_161 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 )
{
V_2 -> V_44 . V_162 = V_163 ;
V_2 -> V_44 . V_103 = & V_164 ;
V_2 -> V_45 . V_162 = V_165 ;
V_2 -> V_45 . V_103 = & V_166 ;
}
