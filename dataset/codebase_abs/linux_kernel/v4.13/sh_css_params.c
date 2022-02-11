struct V_1 *
F_1 (
const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
const struct V_6 * V_7 = V_3 -> V_7 ;
struct V_1 * V_8 ;
unsigned int V_9 , V_10 , V_11 , V_12 ;
unsigned int V_13 ;
short int * V_14 ;
assert ( V_7 != NULL ) ;
assert ( V_5 != NULL ) ;
F_2 ( L_1 ) ;
if ( V_5 == NULL ) {
F_3 ( L_2 ) ;
return NULL ;
}
V_11 = V_7 -> V_15 ;
V_12 = V_11 - V_5 -> V_16 ;
V_13 = V_5 -> V_17 * V_18 * V_11 * sizeof( short ) ;
V_8 = F_4 ( ( V_19 ) V_13 ) ;
if ( ! V_8 )
return NULL ;
V_14 = ( short int * ) V_8 -> V_20 ;
memset ( V_14 ,
0 ,
V_13 ) ;
for ( V_9 = 0 ; V_9 < V_5 -> V_17 ; V_9 ++ ) {
for ( V_10 = 0 ; V_10 < V_18 ; V_10 ++ ) {
memcpy ( V_14 ,
& V_5 -> V_21 [ V_10 ]
[ V_9 * V_5 -> V_16 ] ,
V_5 -> V_16 * sizeof( short ) ) ;
V_14 += V_11 ;
}
}
F_3 ( L_2 ) ;
return V_8 ;
}
enum V_22 F_5 (
const struct V_2 * V_3 ,
T_1 V_23 ,
const struct V_4 * V_24 )
{
struct V_1 * V_25 ;
F_2 ( L_1 ) ;
if ( V_24 == NULL ) {
F_3 ( L_2 ) ;
return V_26 ;
}
V_25 = F_1 ( V_3 , V_24 ) ;
if ( ! V_25 ) {
F_6 ( V_27 ) ;
return V_27 ;
}
F_7 ( V_23 , V_25 ) ;
F_8 ( V_25 ) ;
F_3 ( L_2 ) ;
return V_26 ;
}
static void
F_9 ( const struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_2 ( L_1 ) ;
F_10 ( & V_7 -> V_28 ) ;
F_3 ( L_2 ) ;
}
static enum V_22
F_11 (
struct V_29 * V_30 ,
const struct V_2 * V_31 )
{
const struct V_2 * V_3 ;
enum V_22 V_32 = V_26 ;
struct V_33 V_34 ;
V_34 . V_16 = 0 ;
V_34 . V_17 = 0 ;
assert ( V_30 != NULL ) ;
F_2 ( L_1 ) ;
for ( V_3 = V_31 ; V_3 ; V_3 = V_3 -> V_35 ) {
struct V_6 * V_7 ;
static struct V_6 V_36 ;
const struct V_37 * V_38 = NULL ;
V_7 = V_3 -> V_7 ;
if ( V_7 ) {
V_38 = V_7 -> V_38 ;
} else {
const struct V_39 * args = & V_3 -> args ;
const struct V_40 * V_41 [ V_42 ] = { NULL } ;
if ( args -> V_43 [ 0 ] )
V_41 [ 0 ] = & args -> V_43 [ 0 ] -> V_38 ;
V_38 = & V_3 -> V_44 -> V_38 . V_45 ;
F_12 ( V_38 , false , false ,
V_46 ,
args -> V_47 ? & args -> V_47 -> V_38 : NULL ,
NULL ,
V_41 ,
args -> V_48 ? & args -> V_48 -> V_38
: NULL ,
& V_36 ,
NULL ,
- 1 , true ) ;
V_7 = & V_36 ;
V_7 -> V_38 = V_38 ;
}
if ( V_3 == V_31 ) {
V_34 = V_7 -> V_49 ;
}
assert ( V_3 -> V_50 < V_51 ) ;
if ( V_30 -> V_52 . V_53 . V_54 . V_16 == 0 &&
V_30 -> V_52 . V_53 . V_54 . V_17 == 0 ) {
F_13 (
& V_38 -> V_55 ,
& V_7 -> V_56 ,
& V_7 -> V_57 [ 0 ] ,
& V_7 -> V_58 ,
& V_30 -> V_52 ,
& V_30 -> V_59 ,
& V_30 -> V_60 [ V_3 -> V_50 ] . V_60 ,
& V_30 -> V_60 [ V_3 -> V_50 ] . V_61 ,
V_3 -> V_62 ) ;
} else {
V_32 = F_14 (
& V_38 -> V_55 ,
& V_7 -> V_56 ,
& V_7 -> V_57 [ 0 ] ,
& V_7 -> V_58 ,
& V_30 -> V_52 ,
& V_30 -> V_59 ,
& V_30 -> V_60 [ V_3 -> V_50 ] . V_60 ,
& V_30 -> V_60 [ V_3 -> V_50 ] . V_61 ,
V_34 ,
V_3 -> V_62 ) ;
if ( V_32 != V_26 )
return V_32 ;
}
}
V_30 -> V_63 = true ;
F_3 ( L_2 ) ;
return V_32 ;
}
static void
F_15 ( struct V_29 * V_30 ,
const struct V_64 * V_65 )
{
if ( V_65 == NULL )
return;
F_2 ( L_3 , V_65 ) ;
assert ( V_30 != NULL ) ;
V_30 -> V_66 = * V_65 ;
V_30 -> V_67 [ V_68 ] = true ;
F_3 ( L_2 ) ;
}
static void
F_16 ( const struct V_29 * V_30 ,
struct V_64 * V_65 )
{
if ( V_65 == NULL )
return;
F_2 ( L_3 , V_65 ) ;
assert ( V_30 != NULL ) ;
* V_65 = V_30 -> V_66 ;
F_3 ( L_2 ) ;
}
static void
F_17 ( struct V_29 * V_30 ,
const struct V_69 * V_65 )
{
if ( V_65 == NULL )
return;
F_2 ( L_3 , V_65 ) ;
assert ( V_30 != NULL ) ;
V_30 -> V_70 = * V_65 ;
V_30 -> V_67 [ V_71 ] = true ;
F_3 ( L_2 ) ;
}
static void
F_18 ( const struct V_29 * V_30 ,
struct V_69 * V_65 )
{
if ( V_65 == NULL )
return;
F_2 ( L_3 , V_65 ) ;
assert ( V_30 != NULL ) ;
* V_65 = V_30 -> V_70 ;
F_3 ( L_2 ) ;
}
static void
F_19 ( struct V_29 * V_30 ,
const struct V_72 * V_65 )
{
if ( V_65 == NULL )
return;
F_2 ( L_3 , V_65 ) ;
assert ( V_30 != NULL ) ;
V_30 -> V_73 = * V_65 ;
V_30 -> V_67 [ V_74 ] = true ;
F_3 ( L_2 ) ;
}
static void
F_20 ( const struct V_29 * V_30 ,
struct V_72 * V_65 )
{
if ( V_65 == NULL )
return;
F_2 ( L_3 , V_65 ) ;
assert ( V_30 != NULL ) ;
* V_65 = V_30 -> V_73 ;
F_3 ( L_2 ) ;
}
void F_21 (
struct V_75 * V_76 )
{
unsigned int V_9 ;
if ( V_76 == NULL )
return;
F_22 ( L_1 ) ;
for ( V_9 = 0 ; V_9 < V_77 ; V_9 ++ ) {
if ( V_76 -> V_78 [ V_9 ] ) {
F_23 ( V_76 -> V_78 [ V_9 ] ) ;
V_76 -> V_78 [ V_9 ] = NULL ;
}
if ( V_76 -> V_79 [ V_9 ] ) {
F_23 ( V_76 -> V_79 [ V_9 ] ) ;
V_76 -> V_79 [ V_9 ] = NULL ;
}
}
F_23 ( V_76 ) ;
F_24 ( L_2 ) ;
}
struct V_75 * F_25 (
unsigned int V_16 ,
unsigned int V_17 )
{
unsigned int V_9 ;
struct V_75 * V_76 ;
F_22 ( L_1 ) ;
V_76 = F_26 ( sizeof( * V_76 ) ) ;
if ( V_76 == NULL ) {
F_27 ( L_4 ) ;
return V_76 ;
}
for ( V_9 = 0 ; V_9 < V_77 ; V_9 ++ ) {
V_76 -> V_78 [ V_9 ] = NULL ;
V_76 -> V_79 [ V_9 ] = NULL ;
}
for ( V_9 = 0 ; V_9 < V_77 ; V_9 ++ ) {
V_76 -> V_78 [ V_9 ] =
F_26 ( V_17 * V_16 *
sizeof( * V_76 -> V_78 [ V_9 ] ) ) ;
V_76 -> V_79 [ V_9 ] =
F_26 ( V_17 * V_16 *
sizeof( * V_76 -> V_79 [ V_9 ] ) ) ;
if ( ( V_76 -> V_78 [ V_9 ] == NULL ) ||
( V_76 -> V_79 [ V_9 ] == NULL ) ) {
F_21 ( V_76 ) ;
V_76 = NULL ;
return V_76 ;
}
}
V_76 -> V_16 = V_16 ;
V_76 -> V_17 = V_17 ;
F_24 ( L_1 ) ;
return V_76 ;
}
static enum V_22 F_28 (
struct V_75 * * V_65 ,
const struct V_6 * V_7 )
{
unsigned int V_9 , V_10 , V_80 , V_81 , V_16 , V_17 ;
short V_82 [ V_77 ] = { - 8 , 0 , - 8 , 0 , 0 , - 8 } ,
V_83 [ V_77 ] = { 0 , 0 , - 8 , - 8 , - 8 , 0 } ;
struct V_75 * V_84 ;
assert ( V_65 != NULL ) ;
assert ( V_7 != NULL ) ;
F_2 ( L_1 ) ;
V_81 = ( V_85 / 16 ) * 128 ,
V_16 = V_7 -> V_86 ,
V_17 = V_7 -> V_87 ;
V_84 = F_25 ( V_16 , V_17 ) ;
if ( V_84 == NULL )
return V_27 ;
for ( V_9 = 0 ; V_9 < V_77 ; V_9 ++ ) {
short V_88 = V_83 [ V_9 ] ;
for ( V_10 = 0 ; V_10 < V_17 ; V_10 ++ ) {
short V_89 = V_82 [ V_9 ] ;
unsigned short * V_90 , * V_91 ;
V_90 = & V_84 -> V_78 [ V_9 ] [ V_10 * V_16 ] ;
V_91 = & V_84 -> V_79 [ V_9 ] [ V_10 * V_16 ] ;
for ( V_80 = 0 ; V_80 < V_16 ;
V_80 ++ , V_90 ++ , V_91 ++ , V_89 += ( short ) V_81 ) {
if ( V_80 == 0 )
* V_90 = 0 ;
else if ( V_80 == V_16 - 1 )
* V_90 = V_89 + 2 * V_82 [ V_9 ] ;
else
* V_90 = V_89 ;
if ( V_10 == 0 )
* V_91 = 0 ;
else
* V_91 = V_88 ;
}
V_88 += ( short ) V_81 ;
}
}
* V_65 = V_84 ;
F_6 ( V_26 ) ;
return V_26 ;
}
static void
F_29 ( struct V_29 * V_30 ,
const struct V_75 * V_65 )
{
if ( V_65 == NULL )
return;
F_2 ( L_3 , V_65 ) ;
assert ( V_30 != NULL ) ;
if ( V_65 -> V_92 == false )
V_65 = NULL ;
V_30 -> V_93 = V_65 ;
V_30 -> V_94 = true ;
F_3 ( L_2 ) ;
}
void
F_30 (
struct V_95 * V_96 ,
const struct V_97 * V_98 )
{
F_22 ( L_1 ) ;
if ( V_96 -> V_99 . V_100 ) {
F_31 ( L_5 ) ;
F_32 ( V_96 , V_98 -> V_101 ) ;
} else {
F_31 ( L_6 ) ;
F_33 ( V_96 , V_98 -> V_102 ,
V_98 -> V_103 ) ;
}
#if ! F_34 ( V_104 )
F_31 ( L_7 ) ;
F_35 ( V_96 , V_98 -> V_105 ) ;
#endif
F_24 ( L_2 ) ;
}
void
F_36 ( struct V_97 * V_76 )
{
if ( V_76 ) {
if ( V_76 -> V_106 ) {
F_23 ( V_76 -> V_107 ) ;
V_76 -> V_107 = NULL ;
V_76 -> V_106 = false ;
}
F_23 ( V_76 ) ;
}
}
struct V_97 *
F_37 (
const struct V_108 * V_98 ,
void * V_107 )
{
struct V_97 * V_76 ;
char * V_109 ;
V_76 = F_26 ( sizeof( * V_76 ) ) ;
if ( ! V_76 ) {
F_24 ( L_8 ) ;
goto V_32;
}
V_76 -> V_107 = V_107 ;
V_76 -> V_106 = V_107 == NULL ;
if ( ! V_107 ) {
V_76 -> V_107 = F_26 ( V_98 -> V_110 ) ;
if ( ! V_76 -> V_107 ) {
F_24 ( L_8 ) ;
goto V_32;
}
}
V_109 = V_76 -> V_107 ;
V_76 -> V_110 = V_98 -> V_110 ;
V_76 -> V_101 = ( void * ) V_109 ;
V_76 -> V_102 = ( void * ) ( V_109 + V_98 -> V_111 ) ;
V_76 -> V_103 = ( void * ) ( V_109 + V_98 -> V_111 +
V_98 -> V_112 ) ;
V_76 -> V_105 = ( void * ) ( V_109 + V_98 -> V_111 +
2 * V_98 -> V_112 ) ;
F_24 ( L_9 , V_76 ) ;
return V_76 ;
V_32:
if ( V_76 )
F_23 ( V_76 ) ;
return NULL ;
}
enum V_22
F_38 ( struct V_95 * V_96 ,
const struct V_108 * V_98 )
{
struct V_97 * V_113 ;
enum V_22 V_114 = V_26 ;
F_22 ( L_10 , V_96 , V_98 ) ;
assert ( V_96 != NULL ) ;
assert ( V_98 != NULL ) ;
V_113 = F_37 ( V_98 , NULL ) ;
if ( V_113 ) {
F_39 ( V_98 -> V_107 , V_113 -> V_107 , V_98 -> V_110 ) ;
F_30 ( V_96 , V_113 ) ;
F_36 ( V_113 ) ;
} else {
F_27 ( L_4 ) ;
V_114 = V_27 ;
}
F_40 ( V_114 ) ;
return V_114 ;
}
static void
F_41 ( const struct V_115 * V_116 ,
struct V_29 * V_30 )
{
assert ( V_30 != NULL ) ;
V_30 -> V_117 . V_118 = V_30 -> V_119 . V_118 ;
V_30 -> V_117 . V_120 = V_30 -> V_119 . V_120 ;
V_30 -> V_117 . V_121 = V_30 -> V_119 . V_121 ;
V_30 -> V_117 . V_122 = V_30 -> V_119 . V_122 ;
#ifdef F_42
assert ( V_116 != NULL ) ;
assert ( V_116 -> V_123 < V_124 ) ;
if ( V_116 -> V_123 < V_124 ) {
V_30 -> V_125 [ V_116 -> V_123 ] . V_118 = V_30 -> V_119 . V_118 ;
V_30 -> V_125 [ V_116 -> V_123 ] . V_120 = V_30 -> V_119 . V_120 ;
V_30 -> V_125 [ V_116 -> V_123 ] . V_121 = V_30 -> V_119 . V_121 ;
V_30 -> V_125 [ V_116 -> V_123 ] . V_122 = V_30 -> V_119 . V_122 ;
}
#endif
}
static void
F_43 ( const struct V_115 * V_116 ,
struct V_29 * V_30 ,
const struct V_126 * V_127 )
{
if ( V_127 == NULL )
return;
assert ( V_30 != NULL ) ;
assert ( V_116 != NULL ) ;
assert ( V_116 -> V_123 < V_124 ) ;
F_2 ( L_11 , V_127 ) ;
F_44 ( V_127 , V_128 ) ;
if ( V_116 -> V_123 < V_124 ) {
V_30 -> V_125 [ V_116 -> V_123 ] = * V_127 ;
V_30 -> V_129 [ V_116 -> V_123 ] = true ;
}
F_3 ( L_2 ) ;
}
static void
F_45 ( const struct V_115 * V_116 ,
const struct V_29 * V_30 ,
struct V_126 * V_127 )
{
if ( V_127 == NULL )
return;
assert ( V_30 != NULL ) ;
assert ( V_116 != NULL ) ;
F_2 ( L_11 , V_127 ) ;
* V_127 = V_30 -> V_125 [ V_116 -> V_123 ] ;
F_3 ( L_2 ) ;
}
static void
F_46 ( struct V_29 * V_30 ,
const struct V_130 * V_127 )
{
if ( V_127 == NULL )
return;
assert ( V_30 != NULL ) ;
F_2 ( L_11 , V_127 ) ;
F_47 ( V_127 , V_128 ) ;
V_30 -> V_131 = * V_127 ;
V_30 -> V_132 . V_133 = * V_127 ;
V_30 -> V_67 [ V_134 ] = true ;
V_30 -> V_67 [ V_135 ] = true ;
V_30 -> V_67 [ V_136 ] = true ;
F_3 ( L_2 ) ;
}
static void
F_48 ( struct V_29 * V_30 ,
const struct V_137 * V_127 )
{
if ( V_127 == NULL )
return;
assert ( V_30 != NULL ) ;
F_2 ( L_11 , V_127 ) ;
F_49 ( V_127 , V_128 ) ;
V_30 -> V_138 = * V_127 ;
V_30 -> V_132 . V_139 = * V_127 ;
V_30 -> V_67 [ V_135 ] = true ;
F_3 ( L_2 ) ;
}
static void
F_50 ( const struct V_29 * V_30 ,
struct V_137 * V_127 )
{
if ( V_127 == NULL )
return;
F_2 ( L_11 , V_127 ) ;
assert ( V_30 != NULL ) ;
* V_127 = V_30 -> V_138 ;
F_49 ( V_127 , V_128 ) ;
F_3 ( L_2 ) ;
}
static void
F_51 ( const struct V_115 * V_116 ,
struct V_29 * V_30 ,
const struct V_140 * V_141 )
{
if ( V_141 == NULL )
return;
assert ( V_30 != NULL ) ;
assert ( V_116 != NULL ) ;
assert ( V_141 -> V_142 == V_141 -> V_143 ) ;
assert ( ( V_141 -> V_144 - 1 ) == 2 * ( V_141 -> V_145 - 1 ) ) ;
assert ( V_116 -> V_123 < V_124 ) ;
F_2 ( L_12 , V_141 ) ;
F_52 ( V_30 -> V_146 [ V_116 -> V_123 ] , V_141 ) ;
#if ! F_34 ( V_147 )
V_30 -> V_148 [ V_116 -> V_123 ] = true ;
#endif
F_3 ( L_2 ) ;
}
static void
F_53 ( const struct V_115 * V_116 ,
const struct V_29 * V_30 ,
struct V_140 * V_141 )
{
if ( V_141 == NULL )
return;
assert ( V_30 != NULL ) ;
assert ( V_116 != NULL ) ;
assert ( V_141 -> V_142 == V_141 -> V_143 ) ;
assert ( ( V_141 -> V_144 - 1 ) == 2 * V_141 -> V_145 - 1 ) ;
F_2 ( L_12 , V_141 ) ;
if ( ( V_116 -> V_123 < V_124 ) &&
( V_141 -> V_144 == V_30 -> V_146 [ V_116 -> V_123 ] -> V_144 ) &&
( V_141 -> V_142 == V_30 -> V_146 [ V_116 -> V_123 ] -> V_142 ) &&
( V_141 -> V_145 == V_30 -> V_146 [ V_116 -> V_123 ] -> V_145 ) &&
( V_141 -> V_143 == V_30 -> V_146 [ V_116 -> V_123 ] -> V_143 ) &&
V_141 -> V_149 &&
V_141 -> V_150 &&
V_141 -> V_151 &&
V_141 -> V_152 )
{
F_52 ( V_141 , V_30 -> V_146 [ V_116 -> V_123 ] ) ;
}
F_3 ( L_2 ) ;
}
static void
F_54 ( struct V_29 * V_30 ,
const struct V_153 * V_127 )
{
if ( V_127 == NULL )
return;
assert ( V_30 != NULL ) ;
F_2 ( L_11 , V_127 ) ;
V_30 -> V_154 = * V_127 ;
V_30 -> V_67 [ V_155 ] = true ;
F_3 ( L_2 ) ;
}
static void
F_55 ( const struct V_29 * V_30 ,
struct V_153 * V_127 )
{
if ( V_127 == NULL )
return;
assert ( V_30 != NULL ) ;
F_2 ( L_11 , V_127 ) ;
* V_127 = V_30 -> V_154 ;
F_3 ( L_2 ) ;
}
static void
F_56 ( struct V_29 * V_30 ,
const struct V_156 * V_127 )
{
if ( V_127 == NULL )
return;
assert ( V_30 != NULL ) ;
F_2 ( L_13 , V_127 -> V_157 , V_127 -> V_158 ) ;
assert ( V_127 -> V_157 <= V_159 ) ;
assert ( V_127 -> V_158 <= V_159 ) ;
V_30 -> V_52 = * V_127 ;
V_30 -> V_160 = true ;
V_30 -> V_63 = true ;
F_3 ( L_2 ) ;
}
static void
F_57 ( const struct V_29 * V_30 ,
struct V_156 * V_127 )
{
if ( V_127 == NULL )
return;
assert ( V_30 != NULL ) ;
F_2 ( L_11 , V_127 ) ;
* V_127 = V_30 -> V_52 ;
F_3 ( L_13 , V_127 -> V_157 , V_127 -> V_158 ) ;
}
static void
F_58 ( struct V_29 * V_30 ,
const struct V_161 * V_162 )
{
if ( V_162 == NULL )
return;
assert ( V_30 != NULL ) ;
F_2 ( L_14 , V_162 -> V_163 , V_162 -> V_164 ) ;
V_30 -> V_59 = * V_162 ;
V_30 -> V_165 = true ;
V_30 -> V_63 = true ;
F_3 ( L_2 ) ;
}
static void
F_59 ( const struct V_29 * V_30 ,
struct V_161 * V_162 )
{
if ( V_162 == NULL )
return;
assert ( V_30 != NULL ) ;
F_2 ( L_15 , V_162 ) ;
* V_162 = V_30 -> V_59 ;
F_3 ( L_14 , V_162 -> V_163 , V_162 -> V_164 ) ;
}
struct V_166 *
F_60 ( struct V_115 * V_116 )
{
if ( V_116 == NULL )
{
F_27 ( L_16 , NULL ) ;
return NULL ;
}
return V_116 -> V_127 . V_167 ;
}
enum V_22
F_61 (
struct V_168 * V_169 ,
const struct V_166 * V_127 )
{
return F_62 ( V_169 , V_127 , NULL ) ;
}
enum V_22
F_62 (
struct V_168 * V_169 ,
const struct V_166 * V_127 ,
struct V_115 * V_116 )
{
enum V_22 V_32 = V_26 ;
if ( ( V_169 == NULL ) || ( V_127 == NULL ) )
return V_170 ;
F_22 ( L_17 , V_169 , V_127 , V_116 ) ;
#if F_34 ( V_171 )
if ( V_127 -> V_172 )
V_32 = F_63 ( V_169 , V_127 , V_116 ) ;
else
#endif
V_32 = F_64 ( V_169 -> V_173 [ 0 ] , V_127 , V_116 ) ;
F_40 ( V_32 ) ;
return V_32 ;
}
enum V_22
F_65 ( struct V_115 * V_116 ,
struct V_166 * V_127 )
{
struct V_115 * V_174 = V_116 ;
enum V_22 V_32 = V_26 ;
F_22 ( L_16 , V_116 ) ;
if ( ( V_116 == NULL ) || ( V_116 -> V_169 == NULL ) )
return V_170 ;
F_66 ( V_175 , L_18 , V_127 ) ;
#if F_34 ( V_171 )
if ( V_127 -> V_172 )
V_32 = F_63 ( V_116 -> V_169 , V_127 , V_116 ) ;
else
#endif
V_32 = F_64 ( V_116 , V_127 , V_174 ) ;
F_40 ( V_32 ) ;
return V_32 ;
}
static enum V_22
F_64 (
struct V_115 * V_176 ,
const struct V_166 * V_127 ,
struct V_115 * V_116 )
{
enum V_22 V_32 = V_26 ;
enum V_22 V_177 = V_26 ;
enum V_22 V_178 = V_26 ;
F_2 ( L_17 , V_176 , V_127 , V_116 ) ;
V_177 = F_67 ( V_176 , V_176 -> V_169 -> V_179 , V_127 , V_116 ) ;
V_178 = F_68 ( V_176 , V_176 -> V_169 -> V_179 , F_69 () , V_116 ) ;
V_32 = ( V_177 != V_26 ) ? V_177 : ( ( V_178 != V_26 ) ? V_178 : V_32 ) ;
F_6 ( V_32 ) ;
return V_32 ;
}
static enum V_22
F_63 (
struct V_168 * V_169 ,
const struct V_166 * V_127 ,
struct V_115 * V_116 )
{
unsigned V_9 ;
bool V_180 = false ;
enum V_22 V_32 = V_26 ;
enum V_22 V_177 = V_26 ;
enum V_22 V_178 = V_26 ;
enum V_22 V_181 = V_26 ;
struct V_182 * V_183 ;
struct V_184 * V_185 ;
struct V_29 * V_30 ;
F_2 ( L_17 , V_169 , V_127 , V_116 ) ;
if ( ! V_116 ) {
V_32 = V_170 ;
goto exit;
}
if ( ! V_169 -> V_186 )
{
V_32 = F_70 ( V_169 ,
& V_169 -> V_186 ) ;
if( V_32 != V_26 )
goto exit;
V_180 = true ;
}
V_30 = V_169 -> V_186 ;
if ( ! F_71 ( V_169 , V_30 , false , V_116 ) ) {
V_177 = V_170 ;
}
V_178 = F_67 ( V_169 -> V_173 [ 0 ] , V_30 , V_127 , V_116 ) ;
if ( V_180 )
{
V_183 = & V_30 -> V_183 ;
V_185 = & V_30 -> V_185 ;
for ( V_9 = 0 ; V_9 < V_124 ; V_9 ++ ) {
F_72 ( V_183 , & V_30 -> V_187 [ V_9 ] ) ;
V_30 -> V_188 [ V_9 ] = * V_185 ;
}
}
V_181 = F_68 ( V_169 -> V_173 [ 0 ] , V_30 , F_69 () , V_116 ) ;
V_32 = ( V_177 != V_26 ) ? V_177 :
( V_178 != V_26 ) ? V_178 :
( V_181 != V_26 ) ? V_181 : V_32 ;
exit:
F_6 ( V_32 ) ;
return V_32 ;
}
static enum V_22
F_67 ( struct V_115 * V_116 ,
struct V_29 * V_30 ,
const struct V_166 * V_127 ,
struct V_115 * V_174 )
{
enum V_22 V_32 = V_26 ;
bool V_189 = true ;
assert ( V_116 != NULL ) ;
F_2 ( L_19 , V_116 , V_127 , V_30 ) ;
F_73 ( V_30 , V_127 ) ;
F_46 ( V_30 , V_127 -> V_131 ) ;
F_48 ( V_30 , V_127 -> V_138 ) ;
F_54 ( V_30 , V_127 -> V_190 ) ;
if ( ( V_116 -> V_123 < V_124 ) &&
( V_30 -> V_146 [ V_116 -> V_123 ] ) )
F_51 ( V_116 , V_30 , V_127 -> V_191 ) ;
F_56 ( V_30 , V_127 -> V_52 ) ;
F_58 ( V_30 , V_127 -> V_192 ) ;
F_74 ( V_174 , V_30 ) ;
F_75 ( V_116 -> V_169 , V_30 , V_127 -> V_5 ) ;
F_29 ( V_30 , V_127 -> V_93 ) ;
F_19 ( V_30 , V_127 -> V_73 ) ;
F_15 ( V_30 , V_127 -> V_193 ) ;
F_17 ( V_30 , V_127 -> V_70 ) ;
F_76 ( V_30 , V_127 -> V_194 ) ;
V_30 -> V_195 = ( V_127 -> V_196 != NULL ) ;
V_30 -> V_197 = ( V_127 -> V_198 != NULL ) ;
V_30 -> V_172 = V_127 -> V_172 ;
V_30 -> V_199 = V_127 -> V_200 ;
#ifdef F_42
F_43 ( V_116 , V_30 , V_127 -> V_117 ) ;
F_41 ( V_116 , V_30 ) ;
#endif
if ( V_26 ==
F_77 ( V_116 , & V_189 ) ) {
if( V_189 ) {
V_32 = V_170 ;
}
} else {
V_32 = V_201 ;
goto exit;
}
#ifndef F_42
F_41 ( V_116 , V_30 ) ;
#endif
exit:
F_6 ( V_32 ) ;
return V_32 ;
}
void
F_78 (
const struct V_168 * V_169 ,
struct V_166 * V_127 )
{
F_22 ( L_2 ) ;
F_79 ( V_169 -> V_173 [ 0 ] , V_127 ) ;
F_24 ( L_2 ) ;
}
void
F_79 ( struct V_115 * V_116 ,
struct V_166 * V_127 )
{
struct V_29 * V_30 = NULL ;
assert ( V_127 != NULL ) ;
F_22 ( L_11 , V_127 ) ;
V_30 = V_116 -> V_169 -> V_179 ;
assert ( V_30 != NULL ) ;
F_80 ( V_30 , V_127 ) ;
F_50 ( V_30 , V_127 -> V_138 ) ;
F_55 ( V_30 , V_127 -> V_190 ) ;
F_53 ( V_116 , V_30 , V_127 -> V_191 ) ;
F_45 ( V_116 , V_30 , V_127 -> V_117 ) ;
F_20 ( V_30 , V_127 -> V_73 ) ;
F_16 ( V_30 , V_127 -> V_193 ) ;
F_18 ( V_30 , V_127 -> V_70 ) ;
F_57 ( V_30 , V_127 -> V_52 ) ;
F_59 ( V_30 , V_127 -> V_192 ) ;
F_81 ( V_30 , V_127 -> V_194 ) ;
V_127 -> V_172 = V_30 -> V_172 ;
V_127 -> V_200 = V_30 -> V_199 ;
F_24 ( L_2 ) ;
}
static bool F_82 (
T_1 * V_202 ,
V_19 * V_203 ,
V_19 V_204 ,
bool V_205 ,
enum V_22 * V_32 ,
T_2 V_206 )
{
T_3 V_207 ;
* V_32 = V_26 ;
F_2 ( L_2 ) ;
if ( ! V_205 && * V_203 >= V_204 ) {
F_3 ( L_20 ) ;
return false ;
}
if ( * V_203 == V_204 && F_83 ( * V_202 ) ) {
F_3 ( L_20 ) ;
return false ;
}
V_207 = V_208 ;
F_84 ( V_207 , * V_202 ) ;
* V_202 = F_85 ( V_207 , F_86 ( V_204 ,
V_206 ) ) ;
if ( ! * V_202 ) {
* V_32 = V_27 ;
* V_203 = 0 ;
} else {
* V_203 = V_204 ;
}
F_3 ( L_21 ) ;
return true ;
}
static bool F_87 (
T_1 * V_202 ,
V_19 * V_203 ,
V_19 V_204 ,
bool V_205 ,
enum V_22 * V_32 )
{
bool V_114 ;
T_2 V_206 = V_209 ;
F_2 ( L_2 ) ;
V_114 = F_82 ( V_202 ,
V_203 , V_204 , V_205 , V_32 , V_206 ) ;
F_3 ( L_22 , V_114 ) ;
return V_114 ;
}
struct V_108 *
F_88 ( const struct V_210 * V_99 )
{
struct V_108 * V_76 ;
F_22 ( L_23 , V_99 ) ;
assert ( V_99 != NULL ) ;
if ( ! V_99 -> V_92 )
return NULL ;
V_76 = F_89 ( 1 , sizeof( * V_76 ) ) ;
if ( ! V_76 )
goto V_32;
if ( V_99 -> V_100 ) {
V_76 -> V_111 = sizeof( struct V_211 ) *
V_99 -> V_11 *
V_99 -> V_212 ;
} else {
V_76 -> V_112 = V_213 *
V_99 -> V_212 ;
}
#if ! F_34 ( V_104 )
V_76 -> V_214 = F_90 ( V_215 ) ;
#endif
V_76 -> V_111 = F_91 ( V_76 -> V_111 , V_216 ) ;
V_76 -> V_112 = F_91 ( V_76 -> V_112 , V_216 ) ;
V_76 -> V_214 = F_91 ( V_76 -> V_214 , V_216 ) ;
V_76 -> V_110 = V_76 -> V_111 + V_76 -> V_112 * 2 + V_76 -> V_214 ;
V_76 -> V_107 = F_92 ( V_76 -> V_110 ) ;
if ( V_76 -> V_107 == V_217 ) {
F_23 ( V_76 ) ;
V_76 = NULL ;
goto V_32;
}
if ( V_76 -> V_111 )
V_76 -> V_21 . V_218 . V_219 = V_76 -> V_107 ;
if ( V_76 -> V_112 ) {
V_76 -> V_21 . V_220 . V_221 = V_76 -> V_107 + V_76 -> V_111 ;
V_76 -> V_21 . V_220 . V_222 = V_76 -> V_107 + V_76 -> V_111 + V_76 -> V_112 ;
}
if ( V_76 -> V_214 )
V_76 -> V_223 . V_224 = V_76 -> V_107 + V_76 -> V_111 + 2 * V_76 -> V_112 ;
V_32:
F_24 ( L_24 , V_76 ) ;
return V_76 ;
}
void
F_93 ( struct V_108 * V_76 )
{
if ( V_76 != NULL ) {
F_94 ( V_76 -> V_107 ) ;
F_23 ( V_76 ) ;
}
}
struct V_225 * F_95 ( void )
{
return NULL ;
}
struct V_226 *
F_96 ( const struct V_227 * V_228 )
{
struct V_226 * V_229 = NULL ;
F_22 ( L_1 ) ;
if ( V_228 -> V_110 == 0 )
return NULL ;
V_229 = F_26 ( sizeof( * V_229 ) ) ;
if ( V_229 == NULL )
goto error;
V_229 -> V_38 = * V_228 ;
V_229 -> V_230 = 0 ;
V_229 -> V_20 = F_92 ( V_228 -> V_110 ) ;
if ( V_229 -> V_20 == V_217 )
goto error;
F_24 ( L_24 , V_229 ) ;
return V_229 ;
error:
F_97 ( V_229 ) ;
F_24 ( L_24 , NULL ) ;
return NULL ;
}
void
F_97 ( struct V_226 * V_76 )
{
if ( V_76 != NULL ) {
F_22 ( L_25 , V_76 ) ;
F_94 ( V_76 -> V_20 ) ;
F_23 ( V_76 ) ;
F_24 ( L_2 ) ;
}
}
void
F_98 ( unsigned int V_231 , struct V_226 * * V_232 )
{
unsigned int V_9 ;
if ( V_232 != NULL ) {
for ( V_9 = 0 ; V_9 < V_231 ; V_9 ++ )
F_97 ( V_232 [ V_9 ] ) ;
}
}
enum V_22
F_99 ( struct V_168 * V_169 )
{
enum V_22 V_32 = V_26 ;
unsigned V_9 ;
struct V_182 * V_183 ;
struct V_184 * V_185 ;
struct V_29 * V_30 ;
assert ( V_169 != NULL ) ;
F_2 ( L_2 ) ;
if ( V_169 == NULL ) {
F_6 ( V_170 ) ;
return V_170 ;
}
V_233 = 0 ;
V_234 = 0 ;
V_169 -> V_186 = NULL ;
V_32 = F_70 ( V_169 ,
& V_169 -> V_179 ) ;
if( V_32 != V_26 )
goto V_235;
V_30 = V_169 -> V_179 ;
if ( ! F_71 ( V_169 , V_30 , true , NULL ) ) {
V_32 = V_170 ;
}
V_183 = & V_30 -> V_183 ;
V_185 = & V_30 -> V_185 ;
for ( V_9 = 0 ; V_9 < V_124 ; V_9 ++ ) {
F_72 ( V_183 , & V_30 -> V_187 [ V_9 ] ) ;
V_30 -> V_188 [ V_9 ] = * V_185 ;
}
V_235:
F_6 ( V_32 ) ;
return V_32 ;
}
static void
F_100 (
struct V_29 * V_30 ,
const struct V_236 * V_196 )
{
F_101 ( V_30 , V_196 ) ;
F_102 ( V_30 , V_196 ) ;
F_103 ( V_30 , V_196 ) ;
F_104 ( V_30 , V_196 ) ;
}
static void
F_105 (
struct V_29 * V_30 ,
const struct V_237 * V_198 )
{
F_106 ( V_30 , V_198 ) ;
F_107 ( V_30 , V_198 ) ;
F_108 ( V_30 , V_198 ) ;
F_109 ( V_30 , V_198 ) ;
}
static enum V_22
F_70 ( struct V_168 * V_169 ,
struct V_29 * * V_238 )
{
bool V_239 = true ;
unsigned V_9 ;
struct V_182 * V_183 ;
struct V_184 * V_185 ;
enum V_22 V_32 = V_26 ;
V_19 V_240 ;
struct V_29 * V_30 =
F_26 ( sizeof( struct V_29 ) ) ;
if ( ! V_30 )
{
* V_238 = NULL ;
V_32 = V_27 ;
F_27 ( L_26 , __FILE__ , __LINE__ ) ;
F_6 ( V_32 ) ;
return V_32 ;
} else {
memset ( V_30 , 0 , sizeof( struct V_29 ) ) ;
}
V_183 = & V_30 -> V_183 ;
V_185 = & V_30 -> V_185 ;
for ( V_9 = 0 ; V_9 < V_124 ; V_9 ++ ) {
memset ( & V_30 -> V_187 [ V_9 ] , 0 ,
sizeof( V_30 -> V_187 [ V_9 ] ) ) ;
memset ( & V_30 -> V_188 [ V_9 ] , 0 ,
sizeof( V_30 -> V_188 [ V_9 ] ) ) ;
}
memset ( V_183 , 0 , sizeof( * V_183 ) ) ;
memset ( V_185 , 0 , sizeof( * V_185 ) ) ;
V_240 = sizeof( V_30 -> V_60 ) ;
V_185 -> V_241 = V_240 ;
V_183 -> V_241 =
F_85 ( V_208 ,
F_92 ( V_240 ) ) ;
V_239 &= ( V_183 -> V_241 != V_217 ) ;
V_185 -> V_242 = sizeof( struct V_72 ) ;
V_183 -> V_242 =
F_85 ( V_208 ,
F_92 ( sizeof( struct V_72 ) ) ) ;
V_239 &= ( V_183 -> V_242 != V_217 ) ;
* V_238 = V_30 ;
return V_32 ;
}
static bool
F_71 ( struct V_168 * V_169 ,
struct V_29 * V_30 ,
bool V_243 ,
struct V_115 * V_174 )
{
bool V_244 = true ;
int V_9 = 0 ;
bool V_189 = true ;
unsigned V_245 = F_110 ( V_169 -> V_173 [ 0 ] ) ;
struct V_29 * V_246 = V_169 -> V_179 ;
if ( ! V_243 && ! V_246 ) {
V_244 = false ;
goto exit;
}
V_30 -> V_172 = NULL ;
V_30 -> V_199 = 0 ;
if ( V_243 )
{
F_111 ( V_30 , & V_247 ) ;
F_46 ( V_30 , & V_248 ) ;
F_48 ( V_30 , & V_249 ) ;
if ( V_245 == V_250 )
F_19 ( V_30 , & V_251 ) ;
else if ( V_245 == V_252 )
F_19 ( V_30 , & V_253 ) ;
F_15 ( V_30 , & V_254 ) ;
F_17 ( V_30 , & V_255 ) ;
F_54 ( V_30 , & V_256 ) ;
F_56 ( V_30 , & V_257 ) ;
F_76 ( V_30 , & V_258 ) ;
F_112 ( V_30 , & V_259 ) ;
F_113 ( V_30 , & V_260 ) ;
F_114 ( V_30 , & V_261 ) ;
F_115 ( V_30 , & V_262 ) ;
F_116 ( V_30 , & V_263 ) ;
F_117 ( V_30 , & V_264 ) ;
#ifndef F_42
F_41 ( V_174 , V_30 ) ;
#else
for ( V_9 = 0 ; V_9 < V_169 -> V_265 ; V_9 ++ ) {
if ( V_26 == F_77 ( V_169 -> V_173 [ V_9 ] , & V_189 ) ) {
if( V_189 ) {
F_43 ( V_169 -> V_173 [ V_9 ] , V_30 , & V_266 ) ;
} else {
F_43 ( V_169 -> V_173 [ V_9 ] , V_30 , & V_264 ) ;
}
} else {
V_244 = false ;
goto exit;
}
F_41 ( V_169 -> V_173 [ V_9 ] , V_30 ) ;
}
#endif
F_118 ( V_30 , & V_267 ) ;
F_119 ( V_30 , & V_268 ) ;
F_120 ( V_30 , & V_269 ) ;
F_121 ( V_30 , & V_270 ) ;
F_122 ( V_30 , & V_271 ) ;
F_123 ( V_30 , & V_272 ) ;
F_124 ( V_30 , & V_273 ) ;
F_125 ( V_30 , & V_274 ) ;
F_126 ( V_30 , & V_275 ) ;
F_127 ( V_30 , & V_276 ) ;
F_128 ( V_30 , & V_277 ) ;
F_129 ( V_30 , & V_278 ) ;
F_130 ( V_30 , & V_279 ) ;
F_131 ( V_30 , & V_280 ) ;
F_132 ( V_30 , & V_281 ) ;
F_133 ( V_30 , & V_282 ) ;
F_134 ( V_30 , & V_283 ) ;
F_135 ( V_30 , & V_284 ) ;
F_136 ( V_30 , & V_285 ) ;
F_100 ( V_30 , & V_286 ) ;
F_105 ( V_30 , & V_287 ) ;
F_137 ( V_30 , & V_288 ) ;
V_30 -> V_289 . V_21 = NULL ;
V_30 -> V_67 [ V_290 ] = true ;
V_30 -> V_289 . V_291 = 0 ;
V_30 -> V_59 = V_292 ;
V_30 -> V_165 = true ;
V_30 -> V_93 = NULL ;
V_30 -> V_94 = true ;
V_30 -> V_293 = NULL ;
V_30 -> V_294 = true ;
V_30 -> V_295 = false ;
V_30 -> V_296 = 0 ;
F_138 ( & V_30 -> V_198 ) ;
V_30 -> V_197 = true ;
F_139 ( & V_30 -> V_196 ) ;
V_30 -> V_195 = true ;
#ifdef F_42
F_140 ( & V_30 -> V_297 ) ;
#endif
}
else
{
F_111 ( V_30 , & V_246 -> V_298 ) ;
F_46 ( V_30 , & V_246 -> V_131 ) ;
F_48 ( V_30 , & V_246 -> V_138 ) ;
if ( V_245 == V_250 )
F_19 ( V_30 , & V_246 -> V_73 ) ;
else if ( V_245 == V_252 )
F_19 ( V_30 , & V_246 -> V_73 ) ;
F_15 ( V_30 , & V_246 -> V_66 ) ;
F_17 ( V_30 , & V_246 -> V_70 ) ;
F_54 ( V_30 , & V_246 -> V_154 ) ;
F_56 ( V_30 , & V_246 -> V_52 ) ;
F_76 ( V_30 , & V_246 -> V_194 ) ;
F_112 ( V_30 , & V_246 -> V_299 ) ;
F_113 ( V_30 , & V_246 -> V_119 ) ;
F_114 ( V_30 , & V_246 -> V_300 ) ;
F_115 ( V_30 , & V_246 -> V_301 ) ;
F_116 ( V_30 , & V_246 -> V_302 ) ;
F_117 ( V_30 , & V_246 -> V_117 ) ;
F_118 ( V_30 , & V_246 -> V_303 ) ;
F_119 ( V_30 , & V_246 -> V_304 ) ;
F_120 ( V_30 , & V_246 -> V_305 ) ;
F_121 ( V_30 , & V_246 -> V_306 ) ;
F_122 ( V_30 , & V_246 -> V_307 ) ;
F_123 ( V_30 , & V_246 -> V_308 ) ;
F_124 ( V_30 , & V_246 -> V_309 ) ;
F_125 ( V_30 , & V_246 -> V_310 ) ;
F_126 ( V_30 , & V_246 -> V_311 ) ;
F_127 ( V_30 , & V_246 -> V_312 ) ;
F_128 ( V_30 , & V_246 -> V_313 ) ;
F_129 ( V_30 , & V_246 -> V_314 ) ;
F_130 ( V_30 , & V_246 -> V_315 ) ;
F_131 ( V_30 , & V_246 -> V_316 ) ;
F_132 ( V_30 , & V_246 -> V_317 ) ;
F_133 ( V_30 , & V_246 -> V_318 ) ;
F_134 ( V_30 , & V_246 -> V_319 ) ;
F_135 ( V_30 , & V_246 -> V_320 ) ;
F_136 ( V_30 , & V_246 -> V_321 ) ;
F_137 ( V_30 , & V_246 -> V_322 ) ;
for ( V_9 = 0 ; V_9 < V_169 -> V_265 ; V_9 ++ ) {
if ( V_26 ==
F_77 ( V_169 -> V_173 [ V_9 ] , & V_189 ) ) {
#ifndef F_42
V_244 = ! V_189 ;
#else
if ( V_189 ) {
V_244 = false ;
}
} else {
V_244 = false ;
goto exit;
}
if ( V_169 -> V_173 [ V_9 ] -> V_123 < V_124 ) {
F_43 ( V_169 -> V_173 [ V_9 ] , V_30 ,
& V_246 -> V_125 [ V_169 -> V_173 [ V_9 ] -> V_123 ] ) ;
F_41 ( V_169 -> V_173 [ V_9 ] , V_30 ) ;
#endif
} else {
V_244 = false ;
goto exit;
}
}
#ifndef F_42
F_41 ( V_174 , V_30 ) ;
#endif
V_30 -> V_289 . V_21 = V_246 -> V_289 . V_21 ;
V_30 -> V_67 [ V_290 ] = V_246 -> V_67 [ V_290 ] ;
V_30 -> V_289 . V_291 = V_246 -> V_289 . V_291 ;
F_58 ( V_30 , & V_246 -> V_59 ) ;
F_29 ( V_30 , V_246 -> V_93 ) ;
if ( V_246 -> V_293 ) {
F_74 ( V_174 , V_30 ) ;
F_75 ( V_169 , V_30 , V_246 -> V_293 ) ;
}
else {
V_30 -> V_293 = NULL ;
V_30 -> V_294 = true ;
V_30 -> V_295 = false ;
V_30 -> V_296 = 0 ;
}
for ( V_9 = 0 ; V_9 < V_124 ; V_9 ++ ) {
if ( V_246 -> V_146 [ V_9 ] ) {
if ( V_30 -> V_146 [ V_9 ] ) {
F_52 ( V_30 -> V_146 [ V_9 ] ,
V_246 -> V_146 [ V_9 ] ) ;
} else {
V_30 -> V_146 [ V_9 ] =
F_141 ( V_246 -> V_146 [ V_9 ] ) ;
}
}
}
F_100 ( V_30 , & V_246 -> V_196 ) ;
V_30 -> V_195 = V_246 -> V_195 ;
F_105 ( V_30 , & V_246 -> V_198 ) ;
V_30 -> V_197 = V_246 -> V_197 ;
V_30 -> V_323 = V_246 -> V_323 ;
}
exit:
return V_244 ;
}
enum V_22
F_142 ( void )
{
int V_9 , V_324 ;
F_2 ( L_2 ) ;
V_233 = 0 ;
V_234 = 0 ;
for ( V_324 = 0 ; V_324 < V_124 ; V_324 ++ ) {
for ( V_9 = 0 ; V_9 < V_51 ; V_9 ++ ) {
V_325 [ V_324 ] [ V_9 ] =
F_85 ( - 1 ,
F_143 ( 1 ,
sizeof( struct V_326 ) ) ) ;
V_327 [ V_324 ] [ V_9 ] =
F_85 ( - 1 ,
F_143 ( 1 ,
sizeof( struct V_328 ) ) ) ;
if ( ( V_325 [ V_324 ] [ V_9 ] == V_217 ) ||
( V_327 [ V_324 ] [ V_9 ] == V_217 ) ) {
F_144 () ;
F_6 ( V_27 ) ;
return V_27 ;
}
}
}
F_145 () ;
F_146 () ;
F_147 () ;
F_148 () ;
V_329 = F_85 ( - 1 , F_143 ( 1 ,
F_91 ( sizeof( struct V_182 ) ,
V_216 ) ) ) ;
V_330 = F_85 ( - 1 , F_143 ( 1 ,
sizeof( struct V_331 ) ) ) ;
if ( ( V_329 == V_217 ) ||
( V_330 == V_217 ) ) {
F_149 () ;
F_6 ( V_27 ) ;
return V_27 ;
}
F_6 ( V_26 ) ;
return V_26 ;
}
static void F_150 ( const void * V_332 )
{
unsigned V_9 ;
for ( V_9 = 0 ; V_9 < V_333 ; V_9 ++ )
F_151 ( ( V_334 ) V_9 , ( const int ( * ) [ V_159 ] ) V_332 ) ;
}
inline T_1 F_152 ( void )
{
return F_92 ( sizeof( V_335 ) ) ;
}
inline void F_153 ( T_1 V_336 )
{
if ( V_336 != V_217 )
F_94 ( V_336 ) ;
}
T_1 F_154 ( const struct V_115 * V_116 )
{
assert ( V_116 != NULL ) ;
if ( V_116 -> V_337 != V_217 )
return V_116 -> V_337 ;
else
return F_155 () ;
}
enum V_22 F_156 ( void )
{
enum V_22 V_32 = V_26 ;
F_2 ( L_2 ) ;
if ( V_338 != V_217 )
return V_32 ;
F_150 ( ( void * ) V_335 ) ;
#ifndef F_42
V_338 = F_92 ( sizeof( V_335 ) ) ;
#else
V_338 = F_152 () ;
#endif
if ( V_338 == V_217 )
return V_27 ;
F_157 ( ( const int ( * ) [ V_159 ] ) V_335 ,
V_339 ) ;
F_158 ( V_338 , ( int * ) V_339 ,
sizeof( V_335 ) ) ;
F_3 ( L_27 , V_338 , V_32 ) ;
return V_32 ;
}
void F_159 ( void )
{
F_2 ( L_2 ) ;
F_153 ( V_338 ) ;
V_338 = V_217 ;
F_3 ( L_2 ) ;
}
T_1 F_155 ( void )
{
return V_338 ;
}
static void F_160 (
T_1 V_14 )
{
F_2 ( L_2 ) ;
F_161 ( V_14 ) ;
F_3 ( L_2 ) ;
}
static void F_162 (
T_1 V_14 )
{
F_2 ( L_2 ) ;
F_94 ( V_14 ) ;
F_3 ( L_2 ) ;
}
void
F_163 ( void )
{
F_2 ( L_2 ) ;
F_164 ( V_340 , & F_160 ) ;
F_3 ( L_2 ) ;
}
static void F_165 ( struct V_182 * V_113 )
{
unsigned int V_9 ;
T_1 * V_341 = ( T_1 * ) V_113 ;
F_2 ( L_2 ) ;
for ( V_9 = 0 ; V_9 < ( sizeof( struct V_184 ) /
sizeof( V_19 ) ) ; V_9 ++ ) {
if ( V_341 [ V_9 ] == V_217 )
continue;
F_166 ( V_208 , V_341 [ V_9 ] ) ;
}
F_3 ( L_2 ) ;
}
void
F_167 ( struct V_168 * V_169 )
{
int V_9 ;
struct V_29 * V_30 = V_169 -> V_179 ;
struct V_29 * V_342 =
V_169 -> V_186 ;
F_2 ( L_2 ) ;
if ( V_30 == NULL ) {
F_3 ( L_28 ) ;
return;
}
for ( V_9 = 0 ; V_9 < V_124 ; V_9 ++ )
{
F_165 ( & V_30 -> V_187 [ V_9 ] ) ;
if ( V_342 )
F_165 ( & V_342 -> V_187 [ V_9 ] ) ;
if ( V_30 -> V_146 [ V_9 ] )
F_168 ( & ( V_30 -> V_146 [ V_9 ] ) ) ;
if ( V_342 && V_342 -> V_146 [ V_9 ] )
F_168 ( & ( V_342 -> V_146 [ V_9 ] ) ) ;
}
F_165 ( & V_30 -> V_183 ) ;
if ( V_342 )
F_165 ( & V_342 -> V_183 ) ;
if ( V_30 -> V_289 . V_21 ) {
F_23 ( V_30 -> V_289 . V_21 ) ;
V_30 -> V_289 . V_21 = NULL ;
}
if ( V_30 -> V_24 ) {
F_169 ( V_30 -> V_24 ) ;
V_30 -> V_24 = NULL ;
}
if ( V_342 ) {
if ( V_342 -> V_24 ) {
F_169 ( V_342 -> V_24 ) ;
V_342 -> V_24 = NULL ;
}
}
F_23 ( V_30 ) ;
if ( V_342 )
F_23 ( V_342 ) ;
V_169 -> V_179 = NULL ;
V_169 -> V_186 = NULL ;
F_3 ( L_2 ) ;
}
void
F_144 ( void )
{
unsigned V_324 , V_9 ;
F_2 ( L_2 ) ;
F_84 ( - 1 , V_329 ) ;
V_329 = V_217 ;
F_84 ( - 1 , V_330 ) ;
V_330 = V_217 ;
for ( V_324 = 0 ; V_324 < V_124 ; V_324 ++ )
for ( V_9 = 0 ; V_9 < V_51 ; V_9 ++ ) {
F_84 ( - 1 , V_325 [ V_324 ] [ V_9 ] ) ;
V_325 [ V_324 ] [ V_9 ] = V_217 ;
F_84 ( - 1 , V_327 [ V_324 ] [ V_9 ] ) ;
V_327 [ V_324 ] [ V_9 ] = V_217 ;
}
F_164 ( V_340 , & F_160 ) ;
F_164 ( V_208 , & F_162 ) ;
F_164 ( - 1 , & F_162 ) ;
F_3 ( L_2 ) ;
}
static struct V_1 *
F_170 (
unsigned short * V_21 ,
unsigned int V_16 ,
unsigned int V_17 ,
unsigned int V_11 )
{
unsigned int V_9 , V_10 , V_343 , V_344 ;
struct V_1 * V_76 ;
unsigned int V_345 ;
T_2 * V_346 ;
F_2 ( L_2 ) ;
if ( V_16 > V_11 ) {
V_343 = 0 ;
V_344 = V_11 ;
} else {
V_343 = V_11 - V_16 ;
V_344 = V_16 ;
}
V_345 = V_17 * ( V_344 + V_343 ) * sizeof( T_2 ) ;
V_76 = F_4 ( ( V_19 ) V_345 ) ;
if ( ! V_76 ) {
F_6 ( V_27 ) ;
return NULL ;
}
V_346 = ( T_2 * ) V_76 -> V_20 ;
memset ( V_346 , 0 , ( V_19 ) V_345 ) ;
for ( V_9 = 0 ; V_9 < V_17 ; V_9 ++ ) {
for ( V_10 = 0 ; V_10 < V_344 ; V_10 ++ )
* V_346 ++ = ( T_2 ) V_21 [ V_10 ] ;
V_346 += V_343 ;
V_21 += V_16 ;
}
F_3 ( L_2 ) ;
return V_76 ;
}
static enum V_22
F_171 (
unsigned short * V_21 ,
unsigned int V_16 ,
unsigned int V_17 ,
T_1 V_347 ,
unsigned int V_11 )
{
struct V_1 * V_348 ;
assert ( V_347 != V_217 ) ;
V_348 = F_170 ( V_21 , V_16 , V_17 , V_11 ) ;
if ( ! V_348 ) {
F_6 ( V_27 ) ;
return V_27 ;
}
F_7 ( V_347 , V_348 ) ;
F_8 ( V_348 ) ;
return V_26 ;
}
static void F_172 (
struct V_29 * V_30 ,
T_1 V_349 )
{
V_19 V_110 = sizeof( V_30 -> V_60 ) ;
F_2 ( L_2 ) ;
assert ( V_30 != NULL ) ;
F_158 ( V_349 , & ( V_30 -> V_60 ) , V_110 ) ;
F_3 ( L_2 ) ;
}
static void F_173 (
const struct V_6 * V_7 ,
T_1 V_350 ,
V_19 V_110 ,
enum V_351 V_352 )
{
const struct V_1 * V_30 ;
F_2 ( L_2 ) ;
V_30 = F_174 ( & V_7 -> V_28 , V_353 , V_352 ) ;
F_158 ( V_350 , V_30 -> V_20 , V_110 ) ;
F_3 ( L_2 ) ;
}
void F_175 ( void )
{
unsigned int V_9 ;
T_1 V_354 ;
enum V_355 V_356 [ 3 ] = { V_357 ,
V_358 ,
V_359 } ;
F_2 ( L_2 ) ;
if ( ! F_69 () ) {
F_3 ( L_29 ) ;
return;
}
for ( V_9 = 0 ; V_359 != V_356 [ V_9 ] ; V_9 ++ ) {
V_354 = ( T_1 ) 0 ;
while ( V_26 == F_176 ( V_356 [ V_9 ] , ( V_360 * ) & V_354 ) ) {
V_233 ++ ;
F_177 (
V_361 ,
0 ,
V_356 [ V_9 ] ,
0 ) ;
F_31 ( L_30 , V_354 , 0 ) ;
F_161 ( V_354 ) ;
V_354 = ( T_1 ) 0 ;
}
}
F_3 ( L_2 ) ;
}
static void
F_178 ( unsigned int V_362 ,
struct V_2 * V_3 ,
struct V_29 * V_30 ,
unsigned int V_245 ,
unsigned int V_363 )
{
unsigned V_364 ;
( void ) V_245 ;
( void ) V_363 ;
F_9 ( V_3 -> V_7 ) ;
if ( V_30 -> V_67 [ V_365 ] ) {
F_179 ( & V_30 -> V_366 . V_367 ,
V_245 , V_363 ) ;
}
if ( V_30 -> V_67 [ V_368 ] ) {
F_180 ( V_363 ) ;
}
V_30 -> V_369 . V_61 = V_30 -> V_60 [ V_3 -> V_50 ] . V_61 ;
V_30 -> V_370 . V_61 = V_30 -> V_60 [ V_3 -> V_50 ] . V_61 ;
V_30 -> V_370 . V_60 = V_30 -> V_60 [ V_3 -> V_50 ] . V_60 ;
for ( V_364 = 0 ; V_364 < V_371 ; V_364 ++ ) {
if ( V_364 == V_372 ) continue;
if ( V_30 -> V_67 [ V_364 ] )
V_373 [ V_364 ] ( V_362 , V_3 , V_30 ) ;
}
}
enum V_22
F_68 ( struct V_115 * V_176 ,
struct V_29 * V_30 ,
bool V_374 ,
struct V_115 * V_174 )
{
enum V_22 V_32 = V_26 ;
T_1 V_354 ;
int V_9 ;
unsigned int V_363 = 10 ;
unsigned int V_245 = V_250 ;
bool V_375 = false ;
unsigned int V_376 , V_377 ;
( void ) V_375 ;
assert ( V_176 != NULL ) ;
F_2 ( L_31 , V_174 , V_30 -> V_199 ) ;
V_363 = F_181 ( V_176 -> V_169 ) ;
if ( ! V_374 ) {
F_6 ( V_32 ) ;
return V_32 ;
}
for ( V_9 = 0 ; V_9 < V_176 -> V_169 -> V_265 ; V_9 ++ ) {
struct V_115 * V_116 ;
struct V_182 * V_378 ;
struct V_184 * V_379 ;
struct V_380 V_381 ;
struct V_382 * V_383 ;
struct V_2 * V_3 ;
enum V_355 V_384 ;
( void ) V_3 ;
V_116 = V_176 -> V_169 -> V_173 [ V_9 ] ;
V_383 = F_182 ( V_116 ) ;
V_377 = F_183 ( V_116 ) ;
V_245 = F_110 ( V_116 ) ;
F_184 ( V_377 , & V_376 ) ;
#if F_34 ( V_171 )
F_185 ( V_30 -> V_172
? V_385
: V_386 ,
V_376 , & V_384 ) ;
#else
F_185 ( V_386 , V_376 , & V_384 ) ;
#endif
if ( ! F_69 () ) {
V_32 = V_387 ;
break;
}
V_378 = & V_30 -> V_187 [ V_383 -> V_362 ] ;
V_379 = & V_30 -> V_188 [ V_383 -> V_362 ] ;
{
V_32 = F_11 ( V_30 ,
V_383 -> V_388 ) ;
if ( V_32 != V_26 )
return V_32 ;
}
if ( V_174 && ( V_116 != V_174 ) ) {
F_31 ( L_32 , V_116 ) ;
continue;
}
for ( V_3 = V_383 -> V_388 ; V_3 ; V_3 = V_3 -> V_35 ) {
unsigned V_352 ;
if ( ! V_3 || ! V_3 -> V_7 )
continue;
F_178 ( V_383 -> V_362 ,
V_3 , V_30 ,
V_245 , V_363 ) ;
V_32 = F_186 (
V_116 ,
V_383 -> V_362 ,
V_30 ,
V_3 ,
V_378 ,
V_379 ) ;
if ( V_32 != V_26 )
break;
for ( V_352 = 0 ; V_352 < V_389 ; V_352 ++ ) {
V_30 -> V_390
[ V_383 -> V_362 ] [ V_3 -> V_50 ] [ V_352 ] = false ;
}
}
if ( V_32 != V_26 )
break;
if ( V_30 -> V_63 ) {
F_87 ( & V_378 -> V_241 ,
& V_379 -> V_241 ,
V_379 -> V_241 ,
true ,
& V_32 ) ;
if ( V_32 != V_26 )
break;
F_172 ( V_30 , V_378 -> V_241 ) ;
}
V_32 = F_72 (
V_378 ,
& V_381 . V_391 ) ;
if ( V_32 != V_26 )
break;
V_381 . V_199 = V_30 -> V_199 ;
V_381 . V_392 =
( V_30 -> V_172 ) ? V_30 -> V_172 -> V_21 : V_217 ;
V_32 = F_187 ( & V_381 , & V_354 ) ;
if ( V_32 != V_26 )
break;
F_31 ( L_33 , V_354 , V_376 ) ;
V_32 = F_188 ( V_376 , V_384 , ( V_360 ) V_354 ) ;
if ( V_26 != V_32 ) {
F_161 ( V_354 ) ;
#if F_34 ( V_171 )
F_31 ( L_34 ,
V_381 . V_199 ,
V_381 . V_392 ,
V_384 , V_376 ) ;
#endif
break;
}
else {
V_234 ++ ;
assert ( V_234 < V_233 + 50 ) ;
#ifdef F_42
F_189 ( V_116 , V_354 ) ;
#endif
if ( ! F_69 () ) {
F_6 ( V_387 ) ;
return V_387 ;
}
F_177 (
V_393 ,
( V_394 ) V_376 ,
( V_394 ) V_384 ,
0 ) ;
#if F_34 ( V_171 )
F_31 ( L_35 ,
V_381 . V_199 ,
V_381 . V_392 ,
V_384 , V_376 ) ;
#endif
}
F_175 () ;
V_30 -> V_148 [ V_383 -> V_362 ] = false ;
}
V_30 -> V_63 = false ;
V_30 -> V_294 = false ;
V_30 -> V_195 = false ;
V_30 -> V_197 = false ;
V_30 -> V_94 = false ;
V_30 -> V_160 = false ;
V_30 -> V_165 = false ;
V_30 -> V_395 = false ;
memset ( & V_30 -> V_67 [ 0 ] , 0 , sizeof( V_30 -> V_67 ) ) ;
F_6 ( V_32 ) ;
return V_32 ;
}
static enum V_22
F_186 (
struct V_115 * V_116 ,
unsigned V_362 ,
struct V_29 * V_30 ,
const struct V_2 * V_3 ,
struct V_182 * V_396 ,
struct V_184 * V_397 )
{
enum V_22 V_32 ;
const struct V_6 * V_7 ;
unsigned V_50 ;
unsigned V_352 ;
bool V_398 ;
static struct V_72 V_399 ;
F_2 ( L_2 ) ;
assert ( V_30 != NULL ) ;
assert ( V_396 != NULL ) ;
assert ( V_397 != NULL ) ;
assert ( V_3 != NULL ) ;
V_7 = V_3 -> V_7 ;
assert ( V_7 != NULL ) ;
V_50 = V_3 -> V_50 ;
if ( V_7 -> V_38 -> V_55 . V_92 . V_400 ) {
V_398 = F_87 ( & V_396 -> V_401 ,
& V_397 -> V_401 ,
( V_19 ) ( F_190 ( V_7 ) ) ,
V_30 -> V_67 [ V_290 ] ,
& V_32 ) ;
if ( V_32 != V_26 ) {
F_6 ( V_32 ) ;
return V_32 ;
}
if ( V_30 -> V_67 [ V_290 ] || V_398 ) {
if ( V_30 -> V_289 . V_291 ) {
V_32 = F_191 ( V_30 , V_396 -> V_401 ) ;
if ( V_32 != V_26 ) {
F_6 ( V_32 ) ;
return V_32 ;
}
}
}
}
if ( V_7 -> V_38 -> V_55 . V_92 . V_402 ) {
V_360 V_403 = V_30 ->
V_194 . V_404 ;
V_398 = F_87 ( & V_396 -> V_23 ,
& V_397 -> V_23 ,
( V_19 ) ( F_192 ( V_7 ) ) ,
V_30 -> V_294 ,
& V_32 ) ;
if ( V_32 != V_26 ) {
F_6 ( V_32 ) ;
return V_32 ;
}
if ( V_30 -> V_395 ||
V_30 -> V_294 || V_398 ) {
if ( V_403 == 0 ) {
if ( V_30 -> V_293 ) {
V_32 = F_5 ( V_3 , V_396 -> V_23 , V_30 -> V_293 ) ;
if ( V_32 != V_26 ) {
F_6 ( V_32 ) ;
return V_32 ;
}
V_30 -> V_24 = (struct V_4 * ) V_30 -> V_293 ;
V_373 [ V_372 ] ( V_362 , V_3 , V_30 ) ;
V_30 -> V_24 = NULL ;
} else {
if ( V_30 -> V_24 ) {
F_169 ( V_30 -> V_24 ) ;
V_30 -> V_24 = NULL ;
}
#ifndef F_42
F_193 ( & V_30 -> V_24 , V_7 ) ;
#else
F_193 ( & V_30 -> V_24 ,
V_7 -> V_405 , V_7 -> V_406 ) ;
#endif
if ( V_30 -> V_24 == NULL ) {
F_6 ( V_27 ) ;
return V_27 ;
}
V_32 = F_5 ( V_3 , V_396 -> V_23 , V_30 -> V_24 ) ;
if ( V_32 != V_26 ) {
F_6 ( V_32 ) ;
return V_32 ;
}
V_373 [ V_372 ] ( V_362 , V_3 , V_30 ) ;
F_169 ( V_30 -> V_24 ) ;
V_30 -> V_24 = NULL ;
}
} else {
if ( V_30 -> V_24 ) {
F_169 ( V_30 -> V_24 ) ;
V_30 -> V_24 = NULL ;
}
F_194 (
( const struct V_4 * ) V_30 -> V_293 ,
V_30 -> V_323 ,
& V_30 -> V_24 ,
V_7 , V_116 -> V_407 ) ;
if ( V_30 -> V_24 == NULL ) {
F_6 ( V_27 ) ;
return V_27 ;
}
V_32 = F_5 ( V_3 , V_396 -> V_23 , V_30 -> V_24 ) ;
if ( V_32 != V_26 ) {
F_6 ( V_32 ) ;
return V_32 ;
}
V_373 [ V_372 ] ( V_362 , V_3 , V_30 ) ;
F_169 ( V_30 -> V_24 ) ;
V_30 -> V_24 = NULL ;
}
}
}
#ifdef F_42
if ( V_30 -> V_129 [ V_362 ] && V_7 -> V_38 -> V_55 . V_92 . V_408 ) {
unsigned V_110 = V_3 -> V_7 -> V_38 -> V_409 . V_410 . V_411 -> V_218 . V_412 . V_110 ;
unsigned V_413 = V_3 -> V_7 -> V_38 -> V_409 . V_410 . V_411 -> V_218 . V_412 . V_413 ;
if ( V_110 ) {
F_195 ( (struct V_414 * )
& V_7 -> V_28 . V_30 [ V_353 ] [ V_415 ] . V_20 [ V_413 ] ,
& V_30 -> V_125 [ V_362 ] , V_110 ) ;
#endif
#ifdef F_42
V_30 -> V_63 = true ;
V_30 -> V_390 [ V_362 ] [ V_3 -> V_50 ] [ V_415 ] = true ;
}
}
#endif
if ( V_30 -> V_67 [ V_74 ] && V_7 -> V_38 -> V_55 . V_92 . V_416 ) {
unsigned int V_9 , V_10 , V_417 ;
unsigned int V_418 [] = {
0 , 1 , 3 , 2 , 6 , 7 , 5 , 4 , 12 , 13 , 15 , 14 , 10 , 11 , 9 , 8 } ;
for ( V_9 = 0 ; V_9 < V_419 ; V_9 ++ ) {
V_417 = 4 * V_418 [ V_9 ] ;
V_10 = 4 * V_9 ;
if ( V_7 -> V_38 -> V_55 . V_383 . V_245 == V_250 ) {
V_399 . V_21 [ V_417 ] =
( V_420 ) F_196 ( V_30 -> V_73 . V_21 [ V_10 ] ,
13 , V_421 ) ;
V_399 . V_21 [ V_417 + 1 ] =
( V_420 ) F_196 ( V_30 -> V_73 . V_21 [ V_10 + 1 ] ,
13 , V_421 ) ;
V_399 . V_21 [ V_417 + 2 ] =
( V_420 ) F_196 ( V_30 -> V_73 . V_21 [ V_10 + 2 ] ,
13 , V_421 ) ;
V_399 . V_21 [ V_417 + 3 ] =
( V_420 ) F_196 ( V_30 -> V_73 . V_21 [ V_10 + 3 ] ,
13 , V_421 ) ;
} else if ( V_7 -> V_38 -> V_55 . V_383 . V_245 == V_252 ) {
V_399 . V_21 [ V_417 ] =
V_30 -> V_73 . V_21 [ V_10 ] ;
V_399 . V_21 [ V_417 + 1 ] =
V_30 -> V_73 . V_21 [ V_10 + 1 ] ;
V_399 . V_21 [ V_417 + 2 ] =
V_30 -> V_73 . V_21 [ V_10 + 2 ] ;
V_399 . V_21 [ V_417 + 3 ] =
V_30 -> V_73 . V_21 [ V_10 + 3 ] ;
}
}
F_87 ( & V_396 -> V_242 ,
& V_397 -> V_242 ,
V_397 -> V_242 ,
true ,
& V_32 ) ;
if ( V_32 != V_26 ) {
F_6 ( V_32 ) ;
return V_32 ;
}
F_158 ( V_396 -> V_242 ,
V_399 . V_21 ,
sizeof( V_399 . V_21 ) ) ;
}
if ( V_7 -> V_38 -> V_55 . V_92 . V_422 ) {
V_398 = F_87 (
& V_396 -> V_423 ,
& V_397 -> V_423 ,
( V_19 ) ( ( F_197 ( V_7 ) / 2 ) * 3 ) ,
V_30 -> V_148 [ V_362 ] ,
& V_32 ) ;
if ( V_32 != V_26 ) {
F_6 ( V_32 ) ;
return V_32 ;
}
if ( V_30 -> V_148 [ V_362 ] || V_398 ) {
const struct V_40 * V_424 ;
if ( V_3 -> args . V_425 [ 0 ] ) {
V_424 = & V_3 -> args . V_425 [ 0 ] -> V_38 ;
} else {
V_424 = & V_3 -> args . V_47 -> V_38 ;
}
if ( V_30 -> V_146 [ V_362 ] == NULL ) {
#ifndef F_42
struct V_33 V_426 ;
V_426 . V_16 =
#else
struct V_33 V_426 = { 0 , 0 } ;
if ( V_7 -> V_58 . V_16 || V_7 -> V_58 . V_17 ) {
V_426 . V_16 =
#endif
( V_427 + V_7 -> V_58 . V_16 ) / 2 ;
#ifndef F_42
V_426 . V_17 =
#else
V_426 . V_17 =
#endif
( V_428 + V_7 -> V_58 . V_17 ) / 2 ;
#ifdef F_42
}
#endif
V_30 -> V_146 [ V_362 ] =
F_198 ( & V_7 -> V_57 [ 0 ] . V_429 , & V_426 ) ;
if ( V_30 -> V_146 [ V_362 ] == NULL ) {
F_6 ( V_27 ) ;
return V_27 ;
}
V_30 -> V_148 [ V_362 ] = true ;
}
F_199 ( V_30 -> V_146 [ V_362 ] ,
V_7 ,
V_424 ,
V_396 -> V_423 ) ;
V_30 -> V_63 = true ;
}
}
if ( V_7 -> V_38 -> V_55 . V_92 . V_430 ) {
unsigned int V_9 ;
T_1 * V_431 [
V_77 ] ;
V_19 * V_432 [
V_77 ] ;
T_1 * V_433 [
V_77 ] ;
V_19 * V_434 [
V_77 ] ;
V_431 [ 0 ] = & V_396 -> V_435 ;
V_431 [ 1 ] = & V_396 -> V_436 ;
V_431 [ 2 ] = & V_396 -> V_437 ;
V_431 [ 3 ] = & V_396 -> V_438 ;
V_431 [ 4 ] = & V_396 -> V_439 ;
V_431 [ 5 ] = & V_396 -> V_440 ;
V_432 [ 0 ] = & V_397 -> V_435 ;
V_432 [ 1 ] = & V_397 -> V_436 ;
V_432 [ 2 ] = & V_397 -> V_437 ;
V_432 [ 3 ] = & V_397 -> V_438 ;
V_432 [ 4 ] = & V_397 -> V_439 ;
V_432 [ 5 ] = & V_397 -> V_440 ;
V_433 [ 0 ] = & V_396 -> V_441 ;
V_433 [ 1 ] = & V_396 -> V_442 ;
V_433 [ 2 ] = & V_396 -> V_443 ;
V_433 [ 3 ] = & V_396 -> V_444 ;
V_433 [ 4 ] = & V_396 -> V_445 ;
V_433 [ 5 ] = & V_396 -> V_446 ;
V_434 [ 0 ] = & V_397 -> V_441 ;
V_434 [ 1 ] = & V_397 -> V_442 ;
V_434 [ 2 ] = & V_397 -> V_443 ;
V_434 [ 3 ] = & V_397 -> V_444 ;
V_434 [ 4 ] = & V_397 -> V_445 ;
V_434 [ 5 ] = & V_397 -> V_446 ;
V_398 = false ;
for ( V_9 = 0 ; V_9 < V_77 ; V_9 ++ ) {
V_398 |=
F_87 ( V_431 [ V_9 ] ,
V_432 [ V_9 ] ,
( V_19 )
( F_200 ( V_7 ) ) ,
V_30 -> V_94 ,
& V_32 ) ;
if ( V_32 != V_26 ) {
F_6 ( V_32 ) ;
return V_32 ;
}
V_398 |=
F_87 ( V_433 [ V_9 ] ,
V_434 [ V_9 ] ,
( V_19 )
( F_200 ( V_7 ) ) ,
V_30 -> V_94 ,
& V_32 ) ;
if ( V_32 != V_26 ) {
F_6 ( V_32 ) ;
return V_32 ;
}
}
if ( V_30 -> V_94 || V_398 ) {
const struct V_75 * V_65 = V_30 -> V_93 ;
struct V_75 * V_447 = NULL ;
if ( ( V_65 != NULL ) &&
( V_65 -> V_16 < V_7 -> V_86 ||
V_65 -> V_17 < V_7 -> V_87 ) ) {
V_65 = NULL ;
}
if ( V_65 == NULL ) {
V_32 = F_28 ( & V_447 ,
V_7 ) ;
if ( V_32 != V_26 ) {
F_6 ( V_32 ) ;
return V_32 ;
}
V_65 = V_447 ;
}
for ( V_9 = 0 ; V_9 < V_77 ; V_9 ++ ) {
F_171 ( V_65 -> V_78 [ V_9 ] ,
V_65 -> V_16 ,
V_65 -> V_17 ,
* V_431 [ V_9 ] ,
V_7 -> V_448 ) ;
F_171 ( V_65 -> V_79 [ V_9 ] ,
V_65 -> V_16 ,
V_65 -> V_17 ,
* V_433 [ V_9 ] ,
V_7 -> V_448 ) ;
}
if ( V_447 != NULL )
F_21 ( V_447 ) ;
}
}
for ( V_352 = 0 ; V_352 < V_449 ; V_352 ++ ) {
const struct V_450 * V_348 =
F_201 ( & V_7 -> V_38 -> V_55 . V_451 , V_353 , V_352 ) ;
V_19 V_110 = V_348 -> V_110 ;
if ( ! V_110 ) continue;
V_398 = F_87 ( & V_396 -> V_452 [ V_50 ] [ V_352 ] ,
& V_397 -> V_452 [ V_50 ] [ V_352 ] ,
V_110 ,
V_30 -> V_390 [ V_362 ] [ V_50 ] [ V_352 ] ,
& V_32 ) ;
if ( V_32 != V_26 ) {
F_6 ( V_32 ) ;
return V_32 ;
}
if ( V_30 -> V_390 [ V_362 ] [ V_50 ] [ V_352 ] || V_398 ) {
F_173 ( V_7 ,
V_396 -> V_452 [ V_50 ] [ V_352 ] ,
V_397 -> V_452 [ V_50 ] [ V_352 ] , V_352 ) ;
}
}
F_6 ( V_26 ) ;
return V_26 ;
}
const struct V_453 * F_202 ( struct V_168 * V_169 )
{
struct V_29 * V_30 ;
F_203 ( L_2 ) ;
assert ( V_169 != NULL ) ;
V_30 = V_169 -> V_179 ;
return & ( V_30 -> V_289 ) ;
}
struct V_4 * F_204 ( struct V_168 * V_169 )
{
struct V_4 * V_65 = NULL ;
struct V_29 * V_30 ;
F_22 ( L_2 ) ;
assert ( V_169 != NULL ) ;
V_30 = V_169 -> V_179 ;
if ( ! V_30 )
return NULL ;
if ( V_30 -> V_194 . V_404 == 0 ) {
if ( V_30 -> V_293 ) {
V_65 = (struct V_4 * ) V_30 -> V_293 ;
} else {
const struct V_6 * V_7
= F_205 ( V_169 ) ;
if ( V_7 ) {
if ( V_30 -> V_24 ) {
F_169 ( V_30 -> V_24 ) ;
V_30 -> V_24 = NULL ;
}
#ifndef F_42
F_193 ( & V_30 -> V_24 , V_7 ) ;
#else
F_193 ( & V_30 -> V_24 ,
V_7 -> V_405 , V_7 -> V_406 ) ;
#endif
V_65 = V_30 -> V_24 ;
}
}
} else {
const struct V_6 * V_7
= F_205 ( V_169 ) ;
struct V_115 * V_116 ;
V_116 = V_169 -> V_173 [ 0 ] ;
if ( V_169 -> V_265 == 2 ) {
assert ( V_169 -> V_173 [ 1 ] != NULL ) ;
if ( V_169 -> V_173 [ 1 ] -> V_127 . V_123 == V_454 ||
V_169 -> V_173 [ 1 ] -> V_127 . V_123 == V_455 )
V_116 = V_169 -> V_173 [ 1 ] ;
}
if ( V_7 ) {
if ( V_30 -> V_24 ) {
F_169 ( V_30 -> V_24 ) ;
V_30 -> V_24 = NULL ;
}
F_194 (
( const struct V_4 * ) V_30 -> V_293 ,
V_30 -> V_323 ,
& V_30 -> V_24 ,
V_7 , V_116 -> V_407 ) ;
V_65 = V_30 -> V_24 ;
}
}
F_24 ( L_3 , V_65 ) ;
return V_65 ;
}
T_1 F_206 ( void )
{
F_207 ( L_2 ) ;
F_158 ( V_330 ,
& V_331 ,
sizeof( struct V_331 ) ) ;
return V_330 ;
}
T_1 F_208 (
unsigned V_116 ,
unsigned V_3 )
{
F_207 ( L_2 ) ;
F_158 ( V_325 [ V_116 ] [ V_3 ] ,
& V_326 ,
sizeof( struct V_326 ) ) ;
return V_325 [ V_116 ] [ V_3 ] ;
}
T_1 F_209 (
unsigned V_116 ,
unsigned V_3 )
{
F_207 ( L_2 ) ;
F_158 ( V_327 [ V_116 ] [ V_3 ] ,
& V_328 ,
sizeof( struct V_328 ) ) ;
return V_327 [ V_116 ] [ V_3 ] ;
}
static enum V_22 F_72 (
struct V_182 * V_113 ,
struct V_182 * V_456 )
{
enum V_22 V_32 = V_26 ;
unsigned int V_9 ;
union {
struct V_182 * V_113 ;
T_1 * V_341 ;
} V_457 , V_458 ;
F_2 ( L_2 ) ;
assert ( V_113 != NULL ) ;
assert ( V_456 != NULL ) ;
V_457 . V_113 = V_113 ;
V_458 . V_113 = V_456 ;
assert ( sizeof( struct V_184 ) / sizeof( V_19 ) ==
sizeof( struct V_182 ) / sizeof( T_1 ) ) ;
for ( V_9 = 0 ; V_9 < ( sizeof( struct V_184 ) /
sizeof( V_19 ) ) ; V_9 ++ ) {
if ( V_457 . V_341 [ V_9 ] == V_217 )
V_458 . V_341 [ V_9 ] = V_217 ;
else
V_458 . V_341 [ V_9 ] = F_85 ( V_208 , V_457 . V_341 [ V_9 ] ) ;
}
F_6 ( V_32 ) ;
return V_32 ;
}
static enum V_22 F_187 (
struct V_380 * V_76 ,
T_1 * V_456 )
{
enum V_22 V_32 = V_26 ;
bool V_239 ;
F_2 ( L_2 ) ;
assert ( V_76 != NULL ) ;
assert ( V_456 != NULL ) ;
* V_456 = F_85 ( V_340 , F_92 (
sizeof( struct V_380 ) ) ) ;
V_239 = ( * V_456 != V_217 ) ;
if ( V_239 )
F_158 ( * V_456 ,
V_76 , sizeof( struct V_380 ) ) ;
else
V_32 = V_27 ;
F_6 ( V_32 ) ;
return V_32 ;
}
void
F_210 ( struct V_168 * V_169 )
{
struct V_29 * V_30 ;
unsigned V_9 , V_10 , V_352 ;
F_2 ( L_2 ) ;
assert ( V_169 != NULL ) ;
V_30 = V_169 -> V_179 ;
V_30 -> V_63 = true ;
for ( V_9 = 0 ; V_9 < V_124 ; V_9 ++ ) {
for ( V_10 = 0 ; V_10 < V_51 ; V_10 ++ ) {
for ( V_352 = 0 ; V_352 < V_449 ; V_352 ++ ) {
V_30 -> V_390 [ V_9 ] [ V_10 ] [ V_352 ] = true ;
}
}
}
memset ( & V_30 -> V_67 [ 0 ] , 1 , sizeof( V_30 -> V_67 ) ) ;
V_30 -> V_195 = true ;
V_30 -> V_197 = true ;
V_30 -> V_94 = true ;
V_30 -> V_294 = true ;
V_30 -> V_160 = true ;
V_30 -> V_165 = true ;
for ( V_9 = 0 ; V_9 < V_124 ; V_9 ++ ) {
if ( V_30 -> V_146 [ V_9 ] ) {
F_168 ( & ( V_30 -> V_146 [ V_9 ] ) ) ;
V_30 -> V_148 [ V_9 ] = true ;
}
}
F_3 ( L_2 ) ;
}
void
F_13 (
const struct V_459 * V_38 ,
const struct V_40 * V_56 ,
const struct V_40 * V_57 ,
const struct V_33 * V_460 ,
const struct V_156 * V_461 ,
const struct V_161 * V_192 ,
struct V_462 * V_60 ,
struct V_463 * V_464 ,
bool V_62 )
{
F_2 ( L_2 ) ;
assert ( V_38 != NULL ) ;
assert ( V_56 != NULL ) ;
assert ( V_57 != NULL ) ;
assert ( V_460 != NULL ) ;
assert ( V_461 != NULL ) ;
assert ( V_192 != NULL ) ;
assert ( V_60 != NULL ) ;
assert ( V_464 != NULL ) ;
V_60 -> V_465 = V_62 ? ( T_2 ) V_461 -> V_157 : V_159 ;
V_60 -> V_466 = V_62 ? ( T_2 ) V_461 -> V_158 : V_159 ;
if ( V_38 -> V_92 . V_58 ) {
unsigned int V_467 = 0 ,
V_468 = 0 ,
V_469 = 0 ,
V_470 = 0 ,
V_471 , V_472 ;
int V_473 , V_474 ;
int V_475 = V_192 -> V_163 ;
int V_476 = V_192 -> V_164 ;
bool V_477 = V_56 -> V_429 . V_16 < V_57 -> V_429 . V_16 ;
bool V_478 = V_56 -> V_429 . V_17 < V_57 -> V_429 . V_17 ;
if ( V_38 -> V_92 . V_60 && ! V_38 -> V_92 . V_479 ) {
V_471 = V_460 -> V_16 -
V_480 ;
V_472 = V_460 -> V_17 -
V_480 ;
V_473 = V_471 / 2 ;
V_474 = V_472 / 2 ;
if ( V_477 ) {
V_469 = ( V_56 -> V_429 . V_16
+ V_471
+ V_480 ) / 2 ;
} else {
V_469 = ( V_57 -> V_429 . V_16
+ V_471 ) / 2
+ V_480 ;
}
if ( V_478 ) {
V_470 = ( V_56 -> V_429 . V_17
+ V_472
+ V_480 ) / 2 ;
} else {
V_470 = ( V_57 -> V_429 . V_17
+ V_472 ) / 2
+ V_480 ;
}
V_475 = F_211 ( V_475 , - V_473 , V_473 ) ;
V_476 = F_211 ( V_476 , - V_474 , V_474 ) ;
V_469 += V_475 ;
V_470 += V_476 ;
V_468 = 2 ;
} else if ( V_38 -> V_92 . V_479 ) {
V_471 = V_460 -> V_16 ;
V_472 = V_460 -> V_17 ;
V_473 = V_471 / 2 ;
V_474 = V_472 / 2 ;
V_475 = F_211 ( V_475 , - V_473 , V_473 ) ;
V_476 = F_211 ( V_476 , - V_474 , V_474 ) ;
V_469 = V_56 -> V_429 . V_16 / 2 + V_475 ;
V_470 = V_56 -> V_429 . V_17 / 2 + V_476 ;
V_467 = V_38 -> V_383 . V_481 ;
if ( V_38 -> V_92 . V_479 & 1 )
V_468 = V_38 -> V_383 . V_482 ;
else
V_468 = 2 ;
} else {
V_471 = V_460 -> V_16 -
V_480 ;
V_472 = V_460 -> V_17 -
V_480 ;
V_473 = V_471 / 2 ;
V_474 = V_472 / 2 ;
V_475 = F_211 ( V_475 , - V_473 , V_473 ) ;
V_476 = F_211 ( V_476 , - V_474 , V_474 ) ;
V_467 = V_480
+ V_473 + V_475 ;
V_468 = V_480
+ V_474 + V_476 ;
}
V_467 = F_212 ( V_467 ) ;
V_468 = F_212 ( V_468 ) ;
V_469 = F_212 ( V_469 ) ;
V_470 = F_212 ( V_470 ) ;
V_60 -> V_483 = ( T_2 ) V_469 ;
V_60 -> V_484 = ( T_2 ) V_470 ;
V_464 -> V_163 = ( T_2 ) V_467 ;
V_464 -> V_164 = ( T_2 ) V_468 ;
}
else {
V_60 -> V_483 = ( T_2 ) V_56 -> V_429 . V_16 / 2 ;
V_60 -> V_484 = ( T_2 ) V_56 -> V_429 . V_17 / 2 ;
V_464 -> V_163 = ( T_2 ) V_38 -> V_383 . V_481 ;
V_464 -> V_164 = ( T_2 ) V_38 -> V_383 . V_482 ;
}
F_3 ( L_2 ) ;
}
static enum V_22
F_14 (
const struct V_459 * V_38 ,
const struct V_40 * V_56 ,
const struct V_40 * V_57 ,
const struct V_33 * V_460 ,
const struct V_156 * V_461 ,
const struct V_161 * V_192 ,
struct V_462 * V_60 ,
struct V_463 * V_464 ,
struct V_33 V_34 ,
bool V_62 )
{
unsigned int V_485 = 0 , y0 = 0 , V_486 = 0 , y1 = 0 ;
enum V_22 V_32 = V_26 ;
unsigned int V_487 = 0 ;
F_2 ( L_2 ) ;
assert ( V_38 != NULL ) ;
assert ( V_56 != NULL ) ;
assert ( V_57 != NULL ) ;
assert ( V_460 != NULL ) ;
assert ( V_461 != NULL ) ;
assert ( V_192 != NULL ) ;
assert ( V_60 != NULL ) ;
assert ( V_464 != NULL ) ;
V_485 = V_461 -> V_53 . V_488 . V_163 ;
y0 = V_461 -> V_53 . V_488 . V_164 ;
V_486 = V_461 -> V_53 . V_54 . V_16 + V_485 ;
y1 = V_461 -> V_53 . V_54 . V_17 + y0 ;
if ( ( V_485 > V_486 ) || ( y0 > y1 ) || ( V_486 > V_34 . V_16 ) || ( y1 > V_34 . V_17 ) )
return V_170 ;
if ( ! V_62 ) {
V_60 -> V_465 = V_159 ;
V_60 -> V_466 = V_159 ;
}
if ( V_38 -> V_92 . V_58 ) {
return V_170 ;
} else {
if ( V_62 ) {
if ( V_56 -> V_429 . V_16 != V_34 . V_16 ||
V_56 -> V_429 . V_17 != V_34 . V_17 ) {
V_485 = ( V_485 * V_56 -> V_429 . V_16 ) / ( V_34 . V_16 ) ;
y0 = ( y0 * V_56 -> V_429 . V_17 ) / ( V_34 . V_17 ) ;
V_486 = ( V_486 * V_56 -> V_429 . V_16 ) / ( V_34 . V_16 ) ;
y1 = ( y1 * V_56 -> V_429 . V_17 ) / ( V_34 . V_17 ) ;
}
V_60 -> V_465 =
( ( V_486 - V_485 - V_487 ) * V_159 ) / V_56 -> V_429 . V_16 ;
V_60 -> V_466 =
( ( y1 - y0 - V_487 ) * V_159 ) / V_56 -> V_429 . V_17 ;
V_60 -> V_483 = ( T_2 ) V_485 + ( ( ( V_486 ) - ( V_485 ) ) / 2 ) ;
V_60 -> V_484 = ( T_2 ) y0 + ( ( ( y1 ) - ( y0 ) ) / 2 ) ;
} else {
V_60 -> V_483 = ( T_2 ) V_56 -> V_429 . V_16 / 2 ;
V_60 -> V_484 = ( T_2 ) V_56 -> V_429 . V_17 / 2 ;
}
F_66 ( V_175 , L_36 ,
V_60 -> V_465 , V_60 -> V_483 , V_60 -> V_484 ) ;
F_66 ( V_175 , L_37 ,
V_485 , y0 , V_486 , y1 ) ;
V_464 -> V_163 = ( T_2 ) V_38 -> V_383 . V_481 ;
V_464 -> V_164 = ( T_2 ) V_38 -> V_383 . V_482 ;
}
F_3 ( L_2 ) ;
return V_32 ;
}
struct V_95 *
F_213 ( const struct V_210 * V_99 )
{
struct V_95 * V_76 ;
int V_489 ;
F_22 ( L_23 , V_99 ) ;
assert ( V_99 != NULL ) ;
V_76 = F_89 ( 1 , sizeof( * V_76 ) ) ;
if ( ! V_76 )
goto V_32;
V_76 -> V_99 = * V_99 ;
V_489 = V_99 -> V_16 * V_99 -> V_17 ;
V_76 -> V_21 = F_26 ( V_489 * sizeof( * V_76 -> V_21 ) ) ;
if ( ! V_76 -> V_21 )
goto V_32;
#if ! F_34 ( V_104 )
V_76 -> V_490 = (struct V_491 * ) F_26 ( F_90 ( V_215 ) ) ;
#else
V_76 -> V_490 = NULL ;
#endif
F_24 ( L_24 , V_76 ) ;
return V_76 ;
V_32:
F_214 ( V_76 ) ;
F_24 ( L_24 , NULL ) ;
return NULL ;
}
void
F_214 ( struct V_95 * V_76 )
{
if ( V_76 ) {
F_23 ( V_76 -> V_490 ) ;
F_23 ( V_76 -> V_21 ) ;
memset ( V_76 , 0 , sizeof( struct V_95 ) ) ;
F_23 ( V_76 ) ;
}
}
struct V_492 *
F_215 ( const struct V_493 * V_99 )
{
struct V_492 * V_76 ;
assert ( V_99 != NULL ) ;
V_76 = F_89 ( 1 , sizeof( * V_76 ) ) ;
if ( ! V_76 )
goto V_32;
V_76 -> V_99 = * V_99 ;
V_76 -> V_494 = F_26 ( V_99 -> V_17 * V_495 *
sizeof( * V_76 -> V_494 ) ) ;
if ( ! V_76 -> V_494 )
goto V_32;
V_76 -> V_496 = F_26 ( V_99 -> V_16 * V_495 *
sizeof( * V_76 -> V_496 ) ) ;
if ( ! V_76 -> V_496 )
goto V_32;
return V_76 ;
V_32:
F_216 ( V_76 ) ;
return NULL ;
}
void
F_216 ( struct V_492 * V_76 )
{
if ( V_76 ) {
F_23 ( V_76 -> V_494 ) ;
F_23 ( V_76 -> V_496 ) ;
memset ( V_76 , 0 , sizeof( struct V_492 ) ) ;
F_23 ( V_76 ) ;
}
}
struct V_236 *
F_217 ( const struct V_493 * V_99 )
{
struct V_236 * V_76 ;
assert ( V_99 != NULL ) ;
V_76 = F_89 ( 1 , sizeof( * V_76 ) ) ;
if ( ! V_76 )
goto V_32;
V_76 -> V_99 = * V_99 ;
V_76 -> V_497 = F_26 ( V_99 -> V_498 *
V_495 *
sizeof( * V_76 -> V_497 ) ) ;
if ( ! V_76 -> V_497 )
goto V_32;
V_76 -> V_499 = F_26 ( V_99 -> V_500 *
V_495 *
sizeof( * V_76 -> V_499 ) ) ;
if ( ! V_76 -> V_499 )
goto V_32;
return V_76 ;
V_32:
F_218 ( V_76 ) ;
return NULL ;
}
void
F_218 ( struct V_236 * V_76 )
{
if ( V_76 ) {
F_23 ( V_76 -> V_497 ) ;
F_23 ( V_76 -> V_499 ) ;
memset ( V_76 , 0 , sizeof( struct V_236 ) ) ;
F_23 ( V_76 ) ;
}
}
struct V_501 *
F_219 ( const struct V_493 * V_99 )
{
struct V_501 * V_76 ;
assert ( V_99 != NULL ) ;
V_76 = F_89 ( 1 , sizeof( * V_76 ) ) ;
if ( ! V_76 )
goto V_32;
V_76 -> V_99 = * V_99 ;
V_76 -> V_502 . V_503 = F_26 ( V_99 -> V_11 *
V_99 -> V_212 * sizeof( * V_76 -> V_502 . V_503 ) ) ;
if ( ! V_76 -> V_502 . V_503 )
goto V_32;
V_76 -> V_502 . V_504 = F_26 ( V_99 -> V_11 *
V_99 -> V_212 * sizeof( * V_76 -> V_502 . V_504 ) ) ;
if ( ! V_76 -> V_502 . V_504 )
goto V_32;
V_76 -> V_502 . V_505 = F_26 ( V_99 -> V_11 *
V_99 -> V_212 * sizeof( * V_76 -> V_502 . V_505 ) ) ;
if ( ! V_76 -> V_502 . V_505 )
goto V_32;
V_76 -> V_502 . V_506 = F_26 ( V_99 -> V_11 *
V_99 -> V_212 * sizeof( * V_76 -> V_502 . V_506 ) ) ;
if ( ! V_76 -> V_502 . V_506 )
goto V_32;
V_76 -> V_507 . V_503 = F_26 ( V_99 -> V_11 *
V_99 -> V_212 * sizeof( * V_76 -> V_507 . V_503 ) ) ;
if ( ! V_76 -> V_507 . V_503 )
goto V_32;
V_76 -> V_507 . V_504 = F_26 ( V_99 -> V_11 *
V_99 -> V_212 * sizeof( * V_76 -> V_507 . V_504 ) ) ;
if ( ! V_76 -> V_507 . V_504 )
goto V_32;
V_76 -> V_507 . V_505 = F_26 ( V_99 -> V_11 *
V_99 -> V_212 * sizeof( * V_76 -> V_507 . V_505 ) ) ;
if ( ! V_76 -> V_507 . V_505 )
goto V_32;
V_76 -> V_507 . V_506 = F_26 ( V_99 -> V_11 *
V_99 -> V_212 * sizeof( * V_76 -> V_507 . V_506 ) ) ;
if ( ! V_76 -> V_507 . V_506 )
goto V_32;
return V_76 ;
V_32:
F_220 ( V_76 ) ;
return NULL ;
}
void
F_220 ( struct V_501 * V_76 )
{
if ( V_76 ) {
F_23 ( V_76 -> V_502 . V_503 ) ;
F_23 ( V_76 -> V_502 . V_504 ) ;
F_23 ( V_76 -> V_502 . V_505 ) ;
F_23 ( V_76 -> V_502 . V_506 ) ;
F_23 ( V_76 -> V_507 . V_503 ) ;
F_23 ( V_76 -> V_507 . V_504 ) ;
F_23 ( V_76 -> V_507 . V_505 ) ;
F_23 ( V_76 -> V_507 . V_506 ) ;
memset ( V_76 , 0 , sizeof( struct V_501 ) ) ;
F_23 ( V_76 ) ;
}
}
struct V_237 *
F_221 ( const struct V_493 * V_99 )
{
struct V_237 * V_76 ;
assert ( V_99 != NULL ) ;
V_76 = F_89 ( 1 , sizeof( * V_76 ) ) ;
if ( ! V_76 )
goto V_32;
V_76 -> V_99 = * V_99 ;
V_76 -> V_497 . V_503 = F_26 ( V_99 -> V_498 *
sizeof( * V_76 -> V_497 . V_503 ) ) ;
if ( ! V_76 -> V_497 . V_503 )
goto V_32;
V_76 -> V_497 . V_504 = F_26 ( V_99 -> V_498 *
sizeof( * V_76 -> V_497 . V_504 ) ) ;
if ( ! V_76 -> V_497 . V_504 )
goto V_32;
V_76 -> V_497 . V_505 = F_26 ( V_99 -> V_498 *
sizeof( * V_76 -> V_497 . V_505 ) ) ;
if ( ! V_76 -> V_497 . V_505 )
goto V_32;
V_76 -> V_497 . V_506 = F_26 ( V_99 -> V_498 *
sizeof( * V_76 -> V_497 . V_506 ) ) ;
if ( ! V_76 -> V_497 . V_506 )
goto V_32;
V_76 -> V_499 . V_503 = F_26 ( V_99 -> V_500 *
sizeof( * V_76 -> V_499 . V_503 ) ) ;
if ( ! V_76 -> V_499 . V_503 )
goto V_32;
V_76 -> V_499 . V_504 = F_26 ( V_99 -> V_500 *
sizeof( * V_76 -> V_499 . V_504 ) ) ;
if ( ! V_76 -> V_499 . V_504 )
goto V_32;
V_76 -> V_499 . V_505 = F_26 ( V_99 -> V_500 *
sizeof( * V_76 -> V_499 . V_505 ) ) ;
if ( ! V_76 -> V_499 . V_505 )
goto V_32;
V_76 -> V_499 . V_506 = F_26 ( V_99 -> V_500 *
sizeof( * V_76 -> V_499 . V_506 ) ) ;
if ( ! V_76 -> V_499 . V_506 )
goto V_32;
return V_76 ;
V_32:
F_222 ( V_76 ) ;
return NULL ;
}
void
F_222 ( struct V_237 * V_76 )
{
if ( V_76 ) {
F_23 ( V_76 -> V_497 . V_503 ) ;
F_23 ( V_76 -> V_497 . V_504 ) ;
F_23 ( V_76 -> V_497 . V_505 ) ;
F_23 ( V_76 -> V_497 . V_506 ) ;
F_23 ( V_76 -> V_499 . V_503 ) ;
F_23 ( V_76 -> V_499 . V_504 ) ;
F_23 ( V_76 -> V_499 . V_505 ) ;
F_23 ( V_76 -> V_499 . V_506 ) ;
memset ( V_76 , 0 , sizeof( struct V_237 ) ) ;
F_23 ( V_76 ) ;
}
}
struct V_140 *
F_223 ( const struct V_168 * V_169 )
{
struct V_140 * V_141 = NULL ;
struct V_29 * V_30 = NULL ;
unsigned int V_144 ;
unsigned int V_142 ;
unsigned int V_145 ;
unsigned int V_143 ;
assert ( V_169 != NULL ) ;
V_30 = V_169 -> V_179 ;
if ( ! V_30 || ( V_30 && ! V_30 -> V_146 [ V_508 ] ) ) {
goto V_32;
}
V_141 = (struct V_140 * ) F_89 ( 1 , sizeof( struct V_140 ) ) ;
if ( ! V_141 )
goto V_32;
V_141 -> V_144 = V_144 = V_30 -> V_146 [ V_508 ] -> V_144 ;
V_141 -> V_142 = V_142 = V_30 -> V_146 [ V_508 ] -> V_142 ;
V_141 -> V_145 = V_145 = V_30 -> V_146 [ V_508 ] -> V_145 ;
V_141 -> V_143 = V_143 = V_30 -> V_146 [ V_508 ] -> V_143 ;
F_31 ( L_38 , V_144 , V_142 ) ;
F_31 ( L_39 , V_145 , V_143 ) ;
V_141 -> V_149 = ( V_360 * ) F_26 ( V_144 * V_142 * sizeof( V_360 ) ) ;
if ( ! V_141 -> V_149 )
goto V_32;
V_141 -> V_150 = ( V_360 * ) F_26 ( V_144 * V_142 * sizeof( V_360 ) ) ;
if ( ! V_141 -> V_150 )
goto V_32;
V_141 -> V_151 = ( V_360 * ) F_26 ( V_145 * V_143 * sizeof( V_360 ) ) ;
if ( ! V_141 -> V_151 )
goto V_32;
V_141 -> V_152 = ( V_360 * ) F_26 ( V_145 * V_143 * sizeof( V_360 ) ) ;
if ( ! V_141 -> V_152 )
goto V_32;
return V_141 ;
V_32:
F_224 ( V_141 ) ;
return NULL ;
}
void
F_224 ( struct V_140 * V_191 )
{
if ( V_191 ) {
F_23 ( V_191 -> V_149 ) ;
F_23 ( V_191 -> V_150 ) ;
F_23 ( V_191 -> V_151 ) ;
F_23 ( V_191 -> V_152 ) ;
memset ( V_191 , 0 , sizeof( struct V_140 ) ) ;
F_23 ( V_191 ) ;
}
}
void
F_225 ( struct V_168 * V_169 , bool V_92 )
{
struct V_115 * V_116 ;
struct V_382 * V_383 ;
struct V_2 * V_3 ;
enum V_509 V_362 ;
enum V_22 V_32 ;
int V_9 ;
if ( V_169 == NULL )
return;
for ( V_9 = 0 ; V_9 < V_169 -> V_265 ; V_9 ++ ) {
V_116 = V_169 -> V_173 [ V_9 ] ;
V_383 = F_182 ( V_116 ) ;
V_362 = V_383 -> V_362 ;
if ( V_362 == V_510 ) {
V_32 = F_226 ( V_383 , V_511 , & V_3 ) ;
if ( V_32 == V_26 )
V_3 -> V_62 = V_92 ;
break;
}
}
}
