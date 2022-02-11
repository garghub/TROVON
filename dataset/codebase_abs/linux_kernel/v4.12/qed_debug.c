static T_1 F_1 ( const T_1 * V_1 , const T_1 * V_2 )
{
return ( ( V_1 [ 0 ] & V_2 [ 0 ] ) != V_2 [ 1 ] ) && ( ( V_1 [ 1 ] & V_2 [ 2 ] ) != V_2 [ 3 ] ) ;
}
static T_1 F_2 ( const T_1 * V_1 , const T_1 * V_2 )
{
return ( ( V_1 [ 0 ] >> V_2 [ 0 ] ) & V_2 [ 1 ] ) != V_2 [ 2 ] ;
}
static T_1 F_3 ( const T_1 * V_1 , const T_1 * V_2 )
{
return ( V_1 [ 0 ] & V_2 [ 0 ] ) != V_2 [ 1 ] ;
}
static T_1 F_4 ( const T_1 * V_1 , const T_1 * V_2 )
{
return ( ( V_1 [ 0 ] & V_2 [ 0 ] ) >> V_2 [ 1 ] ) !=
( ( ( V_1 [ 0 ] & V_2 [ 2 ] ) >> V_2 [ 3 ] ) | ( ( V_1 [ 1 ] & V_2 [ 4 ] ) << V_2 [ 5 ] ) ) ;
}
static T_1 F_5 ( const T_1 * V_1 , const T_1 * V_2 )
{
return ( ( V_1 [ 0 ] & V_2 [ 0 ] ) >> V_2 [ 1 ] ) != ( V_1 [ 0 ] & V_2 [ 2 ] ) ;
}
static T_1 F_6 ( const T_1 * V_1 , const T_1 * V_2 )
{
return ( V_1 [ 0 ] & ~ V_2 [ 0 ] ) != V_2 [ 1 ] ;
}
static T_1 F_7 ( const T_1 * V_1 , const T_1 * V_2 )
{
return V_1 [ 0 ] != V_2 [ 0 ] ;
}
static T_1 F_8 ( const T_1 * V_1 , const T_1 * V_2 )
{
return V_1 [ 0 ] != V_1 [ 1 ] && V_1 [ 2 ] == V_2 [ 0 ] ;
}
static T_1 F_9 ( const T_1 * V_1 , const T_1 * V_2 )
{
return V_1 [ 0 ] != V_1 [ 1 ] && V_1 [ 2 ] > V_2 [ 0 ] ;
}
static T_1 F_10 ( const T_1 * V_1 , const T_1 * V_2 )
{
return V_1 [ 0 ] != V_1 [ 1 ] ;
}
static T_1 F_11 ( const T_1 * V_1 , const T_1 * V_2 )
{
return V_1 [ 0 ] & V_2 [ 0 ] ;
}
static T_1 F_12 ( const T_1 * V_1 , const T_1 * V_2 )
{
return V_1 [ 0 ] < ( V_1 [ 1 ] - V_2 [ 0 ] ) ;
}
static T_1 F_13 ( const T_1 * V_1 , const T_1 * V_2 )
{
return V_1 [ 0 ] > V_2 [ 0 ] ;
}
static T_1 F_14 ( T_2 * V_3 )
{
T_1 V_4 ;
memcpy ( ( T_2 * ) & V_4 , V_3 , sizeof( V_4 ) ) ;
return V_4 ;
}
static T_1 F_15 ( struct V_5 * V_6 ,
enum V_7 V_8 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
return V_10 -> V_12 . V_13 [ V_8 ] ;
}
static void F_16 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
if ( ! V_10 -> V_12 . V_14 ) {
F_17 ( V_6 ) ;
V_10 -> V_12 . V_14 = 1 ;
}
}
static enum V_15 F_18 ( struct V_5 * V_6 ,
struct V_16 * V_17 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
if ( V_10 -> V_18 )
return V_19 ;
if ( F_19 ( V_6 -> V_20 ) ) {
V_10 -> V_21 = V_22 ;
V_10 -> V_23 [ V_24 ] = 1 ;
} else if ( F_20 ( V_6 -> V_20 ) ) {
V_10 -> V_21 = V_25 ;
V_10 -> V_23 [ V_26 ] = 1 ;
} else {
return V_27 ;
}
V_10 -> V_28 = V_29 ;
V_10 -> V_23 [ V_30 ] = 1 ;
F_16 ( V_6 ) ;
V_10 -> V_18 = true ;
return V_19 ;
}
static void F_21 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_2 V_31 , struct V_32 * V_32 )
{
T_1 V_33 = V_34 [ V_31 ] . V_35 +
V_36 +
F_22 ( V_37 ) -
sizeof( struct V_38 ) ;
struct V_38 V_38 ;
T_1 * V_39 = ( T_1 * ) & V_38 ;
T_1 V_40 ;
memset ( & V_38 , 0 , sizeof( V_38 ) ) ;
memset ( V_32 , 0 , sizeof( * V_32 ) ) ;
for ( V_40 = 0 ; V_40 < F_23 ( sizeof( V_38 ) ) ;
V_40 ++ , V_33 += V_41 )
V_39 [ V_40 ] = F_24 ( V_6 , V_17 , V_33 ) ;
if ( V_38 . V_42 > 0 && V_38 . V_42 <=
sizeof( * V_32 ) ) {
V_33 = V_38 . V_43 ;
V_39 = ( T_1 * ) V_32 ;
for ( V_40 = 0 ; V_40 < F_23 ( V_38 . V_42 ) ;
V_40 ++ , V_33 += V_41 )
V_39 [ V_40 ] = F_24 ( V_6 , V_17 , V_33 ) ;
}
}
static T_1 F_25 ( char * V_44 , bool V_45 , const char * V_46 )
{
if ( V_45 )
strcpy ( V_44 , V_46 ) ;
return ( T_1 ) strlen ( V_46 ) + 1 ;
}
static T_1 F_26 ( char * V_44 , bool V_45 , T_1 V_47 )
{
T_2 V_48 = ( T_2 ) ( V_47 & 0x3 ) , V_49 ;
V_49 = V_48 ? V_41 - V_48 : 0 ;
if ( V_45 && V_49 )
memset ( V_44 , 0 , V_49 ) ;
return V_49 ;
}
static T_1 F_27 ( T_1 * V_44 ,
bool V_45 ,
const char * V_50 , const char * V_13 )
{
char * V_51 = ( char * ) V_44 ;
T_1 V_52 = 0 ;
V_52 += F_25 ( V_51 + V_52 , V_45 , V_50 ) ;
if ( V_45 )
* ( V_51 + V_52 ) = 1 ;
V_52 ++ ;
V_52 += F_25 ( V_51 + V_52 , V_45 , V_13 ) ;
V_52 += F_26 ( V_51 + V_52 , V_45 , V_52 ) ;
return F_23 ( V_52 ) ;
}
static T_1 F_28 ( T_1 * V_44 ,
bool V_45 , const char * V_50 , T_1 V_13 )
{
char * V_51 = ( char * ) V_44 ;
T_1 V_52 = 0 ;
V_52 += F_25 ( V_51 + V_52 , V_45 , V_50 ) ;
if ( V_45 )
* ( V_51 + V_52 ) = 0 ;
V_52 ++ ;
V_52 += F_26 ( V_51 + V_52 , V_45 , V_52 ) ;
V_52 = F_23 ( V_52 ) ;
if ( V_45 )
* ( V_44 + V_52 ) = V_13 ;
V_52 ++ ;
return V_52 ;
}
static T_1 F_29 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_44 , bool V_45 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
char V_53 [ 16 ] = V_54 ;
char V_55 [ 16 ] = V_56 ;
struct V_32 V_32 = { { 0 } , { 0 } } ;
int V_57 ;
T_1 V_52 = 0 ;
if ( V_45 && ! F_15 ( V_6 , V_58 ) ) {
bool V_59 = false ;
T_2 V_31 ;
for ( V_31 = 0 ; V_31 < V_60 && ! V_59 ;
V_31 ++ ) {
if ( ! V_10 -> V_61
[ V_34 [ V_31 ] . V_62 ] ) {
F_21 ( V_6 ,
V_17 , V_31 , & V_32 ) ;
V_57 =
snprintf ( V_53 ,
sizeof( V_53 ) ,
L_1 ,
V_32 . V_63 . V_64 . V_65 ,
V_32 . V_63 . V_64 . V_66 ,
V_32 . V_63 . V_64 . V_67 ,
V_32 . V_63 . V_64 . V_68 ) ;
if ( V_57 < 0 || V_57 >=
sizeof( V_53 ) )
F_30 ( V_6 ,
L_2 ) ;
switch ( V_32 . V_63 . V_69 ) {
case V_70 :
strcpy ( V_55 , L_3 ) ;
break;
default:
strcpy ( V_55 , L_4 ) ;
break;
}
V_59 = true ;
}
}
}
V_52 += F_27 ( V_44 + V_52 ,
V_45 , L_5 , V_53 ) ;
V_52 += F_27 ( V_44 + V_52 ,
V_45 , L_6 , V_55 ) ;
V_52 += F_28 ( V_44 + V_52 ,
V_45 ,
L_7 , V_32 . V_63 . V_71 ) ;
return V_52 ;
}
static T_1 F_31 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_44 , bool V_45 )
{
char V_72 [ 16 ] = V_54 ;
if ( V_45 && ! F_15 ( V_6 , V_58 ) ) {
T_1 V_73 , V_74 , V_75 ;
T_1 V_76 , V_77 ;
int V_57 ;
V_76 = F_24 ( V_6 , V_17 ,
V_78 ) |
V_79 ;
V_77 = V_76 +
F_32 ( struct V_80 ,
V_81 ) +
sizeof( V_82 ) * V_83 ;
V_73 = F_24 ( V_6 , V_17 ,
V_77 ) ;
V_74 = V_79 +
( V_73 &
V_84 ) * 4 ;
V_75 = F_24 ( V_6 , V_17 ,
V_74 +
F_32 ( struct V_85 , V_75 ) ) ;
V_57 = snprintf ( V_72 , sizeof( V_72 ) ,
L_1 ,
( T_2 ) ( V_75 >> 24 ) ,
( T_2 ) ( V_75 >> 16 ) ,
( T_2 ) ( V_75 >> 8 ) ,
( T_2 ) V_75 ) ;
if ( V_57 < 0 || V_57 >= sizeof( V_72 ) )
F_30 ( V_6 ,
L_8 ) ;
}
return F_27 ( V_44 , V_45 , L_9 , V_72 ) ;
}
static T_1 F_33 ( T_1 * V_44 ,
bool V_45 , const char * V_86 , T_1 V_87 )
{
return F_28 ( V_44 , V_45 , V_86 , V_87 ) ;
}
static T_1 F_34 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_44 ,
bool V_45 ,
T_2 V_88 )
{
T_2 V_87 = V_89 + V_88 ;
struct V_9 * V_10 = & V_6 -> V_11 ;
T_1 V_52 = 0 ;
V_52 += F_33 ( V_44 + V_52 ,
V_45 , L_10 , V_87 ) ;
V_52 += F_29 ( V_6 , V_17 , V_44 + V_52 , V_45 ) ;
V_52 += F_31 ( V_6 ,
V_17 , V_44 + V_52 , V_45 ) ;
V_52 += F_28 ( V_44 + V_52 ,
V_45 , L_11 , V_90 ) ;
V_52 += F_27 ( V_44 + V_52 ,
V_45 ,
L_12 ,
V_91 [ V_10 -> V_21 ] . V_86 ) ;
V_52 += F_27 ( V_44 + V_52 ,
V_45 ,
L_13 ,
V_92 [ V_10 -> V_28 ] .
V_86 ) ;
V_52 +=
F_28 ( V_44 + V_52 , V_45 , L_14 ,
V_6 -> V_93 ) ;
return V_52 ;
}
static T_1 F_35 ( T_1 * V_44 , T_1 V_52 , bool V_45 )
{
T_1 V_94 = V_52 , V_95 = ~ 0 ;
V_52 += F_33 ( V_44 + V_52 , V_45 , L_15 , 0 ) ;
if ( V_45 )
* ( V_44 + V_52 ) = ~ F_36 ( V_95 , ( T_2 * ) V_44 ,
F_22 ( V_52 ) ) ;
V_52 ++ ;
return V_52 - V_94 ;
}
static void F_37 ( struct V_5 * V_6 ,
struct V_16 * V_17 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
T_1 V_96 [ V_97 ] = { 0 } ;
T_1 V_40 ;
for ( V_40 = 0 ; V_40 < V_97 ; V_40 ++ )
if ( V_98 [ V_40 ] . V_99 [ V_10 -> V_21 ] )
V_96 [ V_40 ] = F_24 ( V_6 ,
V_17 , V_98 [ V_40 ] . V_33 ) ;
for ( V_40 = 0 ; V_40 < V_100 ; V_40 ++ )
V_10 -> V_61 [ V_40 ] =
V_101 [ V_40 ] -> V_102 &&
! ( V_96 [ V_101 [ V_40 ] -> V_103 ] &
F_38 ( V_101 [ V_40 ] -> V_104 ) ) ;
}
static void F_39 ( struct V_5 * V_6 ,
struct V_16 * V_17 , bool V_105 )
{
F_40 ( V_6 , V_17 , V_106 , V_105 ? 1 : 0 ) ;
}
static void F_41 ( struct V_5 * V_6 ,
struct V_16 * V_17 )
{
T_1 V_107 , V_108 , V_109 ;
V_107 =
V_98 [ V_101 [ V_110 ] -> V_103 ] . V_33 ;
V_108 = F_24 ( V_6 , V_17 , V_107 ) ;
V_109 = V_108 &
~ F_38 ( V_101 [ V_110 ] -> V_104 ) ;
F_40 ( V_6 , V_17 , V_107 , V_109 ) ;
F_40 ( V_6 , V_17 , V_107 , V_108 ) ;
}
static void F_42 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
enum V_111 V_112 )
{
F_40 ( V_6 , V_17 , V_113 , ( T_2 ) V_112 ) ;
}
static void F_43 ( struct V_5 * V_6 ,
struct V_16 * V_17 , T_1 V_114 )
{
F_40 ( V_6 , V_17 , V_115 , V_114 ) ;
}
static bool F_44 ( struct V_5 * V_6 , T_3 * V_116 )
{
const T_1 * V_117 = V_118 [ V_119 ] . V_117 ;
struct V_9 * V_10 = & V_6 -> V_11 ;
T_2 V_120 = ( ( T_2 * ) V_117 ) [ ( * V_116 ) ++ ] ;
bool V_121 , V_122 ;
switch ( V_120 ) {
case V_123 :
return ! F_44 ( V_6 , V_116 ) ;
case V_124 :
case V_125 :
V_121 = F_44 ( V_6 , V_116 ) ;
V_122 = F_44 ( V_6 , V_116 ) ;
return ( V_120 == V_124 ) ? ( V_121 ||
V_122 ) : ( V_121 && V_122 ) ;
default:
return V_10 -> V_23 [ V_120 - V_126 ] > 0 ;
}
}
static bool F_45 ( struct V_5 * V_6 ,
enum V_7 V_8 )
{
return F_15 ( V_6 , V_8 ) > 0 ;
}
static bool F_46 ( struct V_5 * V_6 ,
enum V_127 V_128 )
{
return F_15 ( V_6 , (enum V_7 ) V_128 ) > 0 ;
}
static bool F_47 ( struct V_5 * V_6 ,
enum V_62 V_62 , T_2 V_129 )
{
T_2 V_40 ;
if ( V_101 [ V_62 ] -> V_130 &&
! F_46 ( V_6 ,
(enum V_127 ) V_101 [ V_62 ] -> V_31 ) )
return false ;
for ( V_40 = 0 ; V_40 < V_131 ; V_40 ++ )
if ( V_129 == V_132 [ V_40 ] . V_129 ||
V_129 == V_132 [ V_40 ] . V_133 )
return F_45 ( V_6 ,
V_132 [ V_40 ] . V_8 ) ;
if ( V_129 == V_134 || V_129 ==
V_135 )
return F_45 ( V_6 , V_136 ) ;
if ( V_129 == V_137 )
return F_45 ( V_6 , V_138 ) ;
if ( V_129 == V_139 )
return F_45 ( V_6 , V_140 ) ;
if ( V_129 == V_141 ||
V_129 == V_142 ||
V_129 == V_143 )
return F_45 ( V_6 , V_144 ) ;
if ( V_129 == V_145 )
return F_45 ( V_6 , V_146 ) ;
if ( V_129 == V_147 ||
V_129 == V_148 )
return F_45 ( V_6 , V_149 ) ;
if ( V_129 == V_150 || V_129 ==
V_151 )
return F_45 ( V_6 , V_152 ) ;
if ( V_129 == V_153 )
return F_45 ( V_6 , V_154 ) ;
if ( V_129 == V_155 )
return F_45 ( V_6 , V_156 ) ;
if ( V_129 == V_157 )
return F_45 ( V_6 , V_158 ) ;
if ( V_129 == V_159 )
return F_45 ( V_6 , V_160 ) ;
if ( V_129 == V_161 )
return F_45 ( V_6 , V_162 ) ;
if ( V_129 == V_163 || V_129 ==
V_164 )
return F_45 ( V_6 , V_165 ) ;
if ( V_129 == V_166 )
return F_45 ( V_6 , V_167 ) ;
if ( V_129 == V_168 )
return F_45 ( V_6 , V_169 ) ;
return true ;
}
static void F_48 ( struct V_5 * V_6 ,
struct V_16 * V_17 , bool V_170 )
{
T_2 V_96 = V_170 ? 1 : 0 ;
T_2 V_31 ;
for ( V_31 = 0 ; V_31 < V_60 ; V_31 ++ ) {
if ( F_46 ( V_6 ,
(enum V_127 ) V_31 ) ) {
T_1 V_171 =
V_34 [ V_31 ] . V_35 +
V_172 ;
F_40 ( V_6 , V_17 , V_171 , V_96 ) ;
}
}
F_49 ( V_173 ) ;
}
static void F_50 ( struct V_5 * V_6 ,
struct V_16 * V_17 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
T_1 V_96 [ V_97 ] = { 0 } ;
T_1 V_40 ;
for ( V_40 = 0 ; V_40 < V_100 ; V_40 ++ )
if ( V_101 [ V_40 ] -> V_102 && V_101 [ V_40 ] -> V_174 )
V_96 [ V_101 [ V_40 ] -> V_103 ] |=
F_38 ( V_101 [ V_40 ] -> V_104 ) ;
for ( V_40 = 0 ; V_40 < V_97 ; V_40 ++ ) {
if ( V_98 [ V_40 ] . V_99 [ V_10 -> V_21 ] ) {
V_96 [ V_40 ] |= V_98 [ V_40 ] . V_175 ;
if ( V_96 [ V_40 ] )
F_40 ( V_6 ,
V_17 ,
V_98 [ V_40 ] . V_33 +
V_176 , V_96 [ V_40 ] ) ;
}
}
}
static const struct V_177 *
F_51 ( enum V_62 V_62 , enum V_178 V_179 )
{
const struct V_180 * V_181 =
( const struct V_180 * )
V_118 [ V_182 ] . V_117 ;
return & V_181 [ V_62 ] . V_183 [ V_179 ] ;
}
static const struct V_184 *
F_52 ( enum V_62 V_62 , enum V_178 V_179 ,
T_2 * V_185 )
{
const struct V_177 * V_186 =
F_51 ( V_62 , V_179 ) ;
* V_185 = V_186 -> V_187 ;
return & ( ( const struct V_184 * )
V_118 [ V_188 ] . V_117 ) [ V_186 ->
V_189 ] ;
}
static void F_53 ( struct V_5 * V_6 ,
struct V_16 * V_17 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
T_2 V_190 , V_185 ;
T_1 V_62 ;
for ( V_62 = 0 ; V_62 < V_100 ; V_62 ++ ) {
const struct V_184 * V_191 ;
if ( V_10 -> V_61 [ V_62 ] )
continue;
V_191 = F_52 ( (enum V_62 ) V_62 ,
V_192 ,
& V_185 ) ;
for ( V_190 = 0 ; V_190 < V_185 ; V_190 ++ ) {
const struct V_184 * V_193 =
& V_191 [ V_190 ] ;
bool V_194 = F_54 ( V_193 -> V_112 . V_195 ,
V_196 ) > 0 ;
T_3 V_116 =
F_54 ( V_193 -> V_112 . V_195 ,
V_197 ) ;
if ( ! V_194 ||
F_44 ( V_6 , & V_116 ) )
F_24 ( V_6 , V_17 ,
F_22 ( V_193 ->
V_198 ) ) ;
}
}
}
static T_1 F_55 ( T_1 * V_44 ,
bool V_45 ,
T_1 V_199 ,
const char * V_200 ,
int V_201 ,
const char * V_50 , const char * V_13 )
{
T_2 V_87 = 2 + ( V_201 >= 0 ? 1 : 0 ) + ( V_50 ? 1 : 0 ) ;
T_1 V_52 = 0 ;
V_52 += F_33 ( V_44 + V_52 ,
V_45 , L_16 , V_87 ) ;
V_52 += F_28 ( V_44 + V_52 ,
V_45 , L_17 , V_199 ) ;
V_52 += F_27 ( V_44 + V_52 ,
V_45 , L_18 , V_200 ) ;
if ( V_201 >= 0 )
V_52 += F_28 ( V_44 + V_52 ,
V_45 , L_19 , V_201 ) ;
if ( V_50 && V_13 )
V_52 += F_27 ( V_44 + V_52 ,
V_45 , V_50 , V_13 ) ;
return V_52 ;
}
static T_1 F_56 ( struct V_5 * V_6 ,
struct V_16 * V_17 , T_1 * V_44 ,
bool V_45 , T_1 V_33 , T_1 V_202 )
{
T_1 V_203 = F_22 ( V_33 ) , V_52 = 0 , V_40 ;
if ( V_45 )
for ( V_40 = 0 ; V_40 < V_202 ; V_40 ++ , V_203 += V_41 , V_52 ++ )
* ( V_44 + V_52 ) = F_24 ( V_6 , V_17 , V_203 ) ;
else
V_52 += V_202 ;
return V_52 ;
}
static T_1 F_57 ( T_1 * V_44 , bool V_45 , T_1 V_33 ,
T_1 V_202 )
{
if ( V_45 )
* V_44 = V_33 | ( V_202 << V_204 ) ;
return 1 ;
}
static T_1 F_58 ( struct V_5 * V_6 ,
struct V_16 * V_17 , T_1 * V_44 ,
bool V_45 , T_1 V_33 , T_1 V_202 )
{
T_1 V_52 = 0 ;
V_52 += F_57 ( V_44 , V_45 , V_33 , V_202 ) ;
V_52 += F_56 ( V_6 ,
V_17 ,
V_44 + V_52 , V_45 , V_33 , V_202 ) ;
return V_52 ;
}
static T_1 F_59 ( struct V_5 * V_6 ,
struct V_16 * V_17 , T_1 * V_44 ,
bool V_45 , T_1 V_33 , T_1 V_205 ,
T_1 V_206 , T_1 V_207 )
{
T_1 V_52 = 0 , V_208 = 0 ;
V_52 += F_57 ( V_44 , V_45 , V_33 , V_205 ) ;
if ( V_45 ) {
while ( V_208 < V_205 ) {
T_1 V_209 = F_60 ( T_1 ,
V_206 ,
V_205 - V_208 ) ;
V_52 += F_56 ( V_6 ,
V_17 ,
V_44 + V_52 ,
V_45 , V_33 , V_209 ) ;
V_208 += V_209 ;
V_33 += V_209 ;
if ( V_208 < V_205 ) {
V_209 = F_60 ( T_1 ,
V_207 ,
V_205 - V_207 ) ;
memset ( V_44 + V_52 , 0 ,
F_22 ( V_209 ) ) ;
V_52 += V_209 ;
V_208 += V_209 ;
V_33 += V_209 ;
}
}
} else {
V_52 += V_205 ;
}
return V_52 ;
}
static T_1 F_61 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
struct V_210 V_211 ,
T_1 * V_44 ,
bool V_45 ,
bool V_212 [ V_100 ] ,
T_1 * V_213 )
{
T_1 V_40 , V_52 = 0 , V_214 = 0 ;
bool V_215 = true ;
* V_213 = 0 ;
while ( V_214 < V_211 . V_216 ) {
const struct V_217 * V_218 =
( const struct V_217 * )
& V_211 . V_117 [ V_214 ++ ] ;
bool V_194 = F_54 ( V_218 -> V_112 . V_195 ,
V_196 ) > 0 ;
if ( V_194 ) {
T_3 V_116 =
F_54 ( V_218 -> V_112 . V_195 ,
V_197 ) ;
V_215 = F_44 ( V_6 ,
& V_116 ) ;
}
if ( V_215 && V_212 [ V_218 -> V_62 ] ) {
for ( V_40 = 0 ; V_40 < V_218 -> V_219 ;
V_40 ++ , V_214 ++ ) {
const struct V_220 * V_221 =
( const struct V_220 * )
& V_211 . V_117 [ V_214 ] ;
T_1 V_33 , V_202 ;
V_33 = F_54 ( V_221 -> V_195 ,
V_222 ) ;
V_202 = F_54 ( V_221 -> V_195 , V_223 ) ;
V_52 +=
F_58 ( V_6 , V_17 ,
V_44 + V_52 ,
V_45 ,
V_33 ,
V_202 ) ;
( * V_213 ) ++ ;
}
} else {
V_214 += V_218 -> V_219 ;
}
}
return V_52 ;
}
static T_1 F_62 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
struct V_210 V_211 ,
T_1 * V_44 ,
bool V_45 ,
bool V_212 [ V_100 ] ,
const char * V_224 ,
T_1 V_201 ,
const char * V_50 ,
const char * V_13 )
{
T_1 V_213 , V_52 ;
V_52 = F_55 ( V_44 ,
false ,
0 ,
V_224 ,
V_201 , V_50 , V_13 ) ;
V_52 += F_61 ( V_6 ,
V_17 ,
V_211 ,
V_44 + V_52 ,
V_45 ,
V_212 ,
& V_213 ) ;
if ( V_45 && V_213 > 0 )
F_55 ( V_44 ,
V_45 ,
V_213 ,
V_224 ,
V_201 , V_50 , V_13 ) ;
return V_213 > 0 ? V_52 : 0 ;
}
static T_1 F_63 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_44 ,
bool V_45 ,
bool V_212 [ V_100 ] ,
const char * V_50 , const char * V_13 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
struct V_225 * V_226 ;
T_1 V_52 = 0 , V_214 = 0 ;
struct V_227 * V_228 ;
T_2 V_229 , V_230 , V_231 ;
T_3 V_232 ;
V_228 = & V_91 [ V_10 -> V_21 ] ;
V_226 = & V_228 -> V_233 [ V_10 -> V_28 ] ;
if ( V_45 )
F_64 ( V_6 , V_234 , L_20 ) ;
while ( V_214 <
V_118 [ V_235 ] . V_216 ) {
const struct V_236 * V_237 =
( const struct V_236 * )
& V_118 [ V_235 ] . V_117 [ V_214 ++ ] ;
T_2 V_238 = F_54 ( V_237 -> V_239 ,
V_240 ) ;
T_1 V_241 = F_54 ( V_237 -> V_239 ,
V_242 ) ;
struct V_210 V_243 = {
& V_118 [ V_235 ] . V_117 [ V_214 ] ,
V_241 } ;
switch ( V_238 ) {
case V_244 :
V_52 += F_62 ( V_6 ,
V_17 ,
V_243 ,
V_44 + V_52 ,
V_45 ,
V_212 ,
L_21 ,
( T_1 ) ( - 1 ) ,
V_50 ,
V_13 ) ;
break;
case V_245 :
for ( V_229 = 0 ; V_229 < V_226 -> V_246 ;
V_229 ++ ) {
if ( V_45 )
F_65 ( V_6 , V_17 ,
V_229 ) ;
V_52 +=
F_62 ( V_6 , V_17 ,
V_243 ,
V_44 + V_52 ,
V_45 , V_212 ,
L_22 , V_229 ,
V_50 ,
V_13 ) ;
}
break;
case V_247 :
case V_248 :
for ( V_230 = 0 ; V_230 < V_226 -> V_249 ;
V_230 ++ ) {
T_2 V_250 =
V_251 ;
if ( V_45 ) {
V_232 = V_230 << V_250 ;
F_66 ( V_6 , V_17 , V_232 ) ;
}
V_52 +=
F_62 ( V_6 , V_17 ,
V_243 ,
V_44 + V_52 ,
V_45 , V_212 ,
L_23 , V_230 ,
V_50 ,
V_13 ) ;
}
break;
case V_252 :
for ( V_231 = 0 ; V_231 < V_226 -> V_253 ;
V_231 ++ ) {
T_2 V_254 =
V_255 ;
T_2 V_256 =
V_257 ;
if ( V_45 ) {
V_232 = F_38 ( V_254 ) |
( V_231 << V_256 ) ;
F_66 ( V_6 , V_17 , V_232 ) ;
}
V_52 +=
F_62 ( V_6 , V_17 ,
V_243 ,
V_44 + V_52 ,
V_45 , V_212 ,
L_24 , V_231 ,
V_50 ,
V_13 ) ;
}
break;
default:
break;
}
V_214 += V_241 ;
}
if ( V_45 ) {
V_232 = V_6 -> V_258 << V_251 ;
F_66 ( V_6 , V_17 , V_232 ) ;
}
return V_52 ;
}
static T_1 F_67 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_44 , bool V_45 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
T_1 V_40 , V_52 = 0 , V_187 = 0 ;
V_52 += F_55 ( V_44 ,
false , 0 , L_21 , - 1 , NULL , NULL ) ;
for ( V_40 = 0 ; V_40 < V_97 ; V_40 ++ ) {
if ( V_98 [ V_40 ] . V_99 [ V_10 -> V_21 ] ) {
T_1 V_33 = F_23 ( V_98 [ V_40 ] . V_33 ) ;
V_52 += F_58 ( V_6 ,
V_17 ,
V_44 + V_52 ,
V_45 ,
V_33 ,
1 ) ;
V_187 ++ ;
}
}
if ( V_45 )
F_55 ( V_44 ,
true , V_187 , L_21 , - 1 , NULL , NULL ) ;
return V_52 ;
}
static T_1 F_68 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_44 , bool V_45 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
T_1 V_52 = 0 , V_199 = 0 , V_62 ;
T_2 V_31 , V_190 , V_185 ;
V_52 += F_55 ( V_44 ,
false , 0 , L_21 , - 1 , NULL , NULL ) ;
for ( V_62 = 0 ; V_62 < V_100 ; V_62 ++ ) {
const struct V_184 * V_191 ;
if ( V_10 -> V_61 [ V_62 ] && V_45 )
continue;
V_191 = F_52 ( (enum V_62 ) V_62 ,
V_192 ,
& V_185 ) ;
for ( V_190 = 0 ; V_190 < V_185 ; V_190 ++ ) {
const struct V_184 * V_193 =
& V_191 [ V_190 ] ;
T_3 V_116 ;
bool V_194 ;
T_1 V_33 ;
V_194 = F_54 ( V_193 -> V_112 . V_195 ,
V_196 ) > 0 ;
V_116 =
F_54 ( V_193 -> V_112 . V_195 ,
V_197 ) ;
if ( ! V_194 ||
F_44 ( V_6 , & V_116 ) ) {
V_33 = V_193 -> V_259 ;
V_52 +=
F_58 ( V_6 ,
V_17 ,
V_44 + V_52 ,
V_45 ,
V_33 ,
1 ) ;
V_33 = F_54 ( V_193 -> V_195 ,
V_260 ) ;
V_52 +=
F_58 ( V_6 ,
V_17 ,
V_44 + V_52 ,
V_45 ,
V_33 ,
1 ) ;
V_199 += 2 ;
}
}
}
for ( V_31 = 0 ; V_31 < V_60 ; V_31 ++ ) {
T_1 V_33 ;
if ( V_10 -> V_61 [ V_34 [ V_31 ] . V_62 ] &&
V_45 )
continue;
V_33 =
F_23 ( V_34 [ V_31 ] . V_35 +
V_261 ) ;
V_52 += F_58 ( V_6 ,
V_17 ,
V_44 + V_52 ,
V_45 ,
V_33 ,
1 ) ;
V_199 ++ ;
}
if ( V_45 )
F_55 ( V_44 ,
true ,
V_199 , L_21 , - 1 , NULL , NULL ) ;
return V_52 ;
}
static T_1 F_69 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_44 , bool V_45 )
{
T_1 V_52 = 0 , V_33 ;
V_52 += F_55 ( V_44 ,
V_45 , 2 , L_21 , - 1 , NULL , NULL ) ;
V_33 = F_23 ( V_262 ) ;
V_52 += F_59 ( V_6 ,
V_17 ,
V_44 + V_52 ,
V_45 ,
V_33 ,
V_263 ,
7 ,
1 ) ;
V_33 = F_23 ( V_264 ) ;
V_52 +=
F_59 ( V_6 ,
V_17 ,
V_44 + V_52 ,
V_45 ,
V_33 ,
V_265 ,
7 ,
1 ) ;
return V_52 ;
}
static T_1 F_70 ( struct V_5 * V_6 ,
T_1 * V_44 ,
bool V_45 ,
const char * V_86 ,
T_1 V_33 ,
T_1 V_202 ,
T_1 V_266 ,
bool V_267 ,
const char * V_268 ,
bool V_269 , char V_270 )
{
T_2 V_87 = 3 ;
T_1 V_52 = 0 ;
char V_3 [ 64 ] ;
if ( ! V_202 )
F_30 ( V_6 ,
L_25 ) ;
if ( V_266 )
V_87 ++ ;
if ( V_267 )
V_87 ++ ;
V_52 += F_33 ( V_44 + V_52 ,
V_45 , L_26 , V_87 ) ;
if ( V_86 ) {
if ( V_269 ) {
strcpy ( V_3 , L_27 ) ;
V_3 [ 0 ] = V_270 ;
strcpy ( V_3 + strlen ( V_3 ) , V_86 ) ;
} else {
strcpy ( V_3 , V_86 ) ;
}
V_52 += F_27 ( V_44 + V_52 ,
V_45 , L_28 , V_3 ) ;
if ( V_45 )
F_64 ( V_6 ,
V_234 ,
L_29 ,
V_202 , V_3 ) ;
} else {
V_52 += F_28 ( V_44 + V_52 ,
V_45 , L_30 ,
F_22 ( V_33 ) ) ;
if ( V_45 && V_202 > 64 )
F_64 ( V_6 ,
V_234 ,
L_31 ,
V_202 , ( T_1 ) F_22 ( V_33 ) ) ;
}
V_52 += F_28 ( V_44 + V_52 , V_45 , L_32 , V_202 ) ;
if ( V_266 )
V_52 += F_28 ( V_44 + V_52 ,
V_45 , L_33 , V_266 ) ;
if ( V_267 )
V_52 += F_28 ( V_44 + V_52 ,
V_45 , L_34 , 1 ) ;
if ( V_269 ) {
strcpy ( V_3 , L_27 ) ;
V_3 [ 0 ] = V_270 ;
strcpy ( V_3 + strlen ( V_3 ) , V_268 ) ;
} else {
strcpy ( V_3 , V_268 ) ;
}
V_52 += F_27 ( V_44 + V_52 , V_45 , L_35 , V_3 ) ;
return V_52 ;
}
static T_1 F_71 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_44 ,
bool V_45 ,
const char * V_86 ,
T_1 V_33 ,
T_1 V_202 ,
T_1 V_266 ,
bool V_267 ,
const char * V_268 ,
bool V_269 , char V_270 )
{
T_1 V_52 = 0 ;
V_52 += F_70 ( V_6 ,
V_44 + V_52 ,
V_45 ,
V_86 ,
V_33 ,
V_202 ,
V_266 ,
V_267 ,
V_268 , V_269 , V_270 ) ;
V_52 += F_56 ( V_6 ,
V_17 ,
V_44 + V_52 , V_45 , V_33 , V_202 ) ;
return V_52 ;
}
static T_1 F_72 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
struct V_210 V_271 ,
T_1 * V_44 , bool V_45 )
{
T_1 V_40 , V_52 = 0 , V_214 = 0 ;
bool V_215 = true ;
while ( V_214 < V_271 . V_216 ) {
const struct V_217 * V_218 ;
T_1 V_272 ;
bool V_194 ;
V_218 = ( const struct V_217 * )
& V_271 . V_117 [ V_214 ++ ] ;
V_194 = F_54 ( V_218 -> V_112 . V_195 ,
V_196 ) > 0 ;
if ( V_194 ) {
T_3 V_116 =
F_54 ( V_218 -> V_112 . V_195 ,
V_197 ) ;
V_215 = F_44 ( V_6 ,
& V_116 ) ;
}
if ( ! V_215 ) {
V_214 += V_218 -> V_219 ;
continue;
}
V_272 = V_218 -> V_219 / V_273 ;
for ( V_40 = 0 ; V_40 < V_272 ;
V_40 ++ , V_214 += V_273 ) {
const struct V_274 * V_275 =
( const struct V_274 * )
& V_271 . V_117 [ V_214 ] ;
T_2 V_129 ;
V_129 = F_54 ( V_275 -> V_276 ,
V_277 ) ;
if ( V_129 >= V_278 ) {
F_30 ( V_6 , L_36 ) ;
return 0 ;
}
if ( F_47 ( V_6 ,
(enum V_62 ) V_218 -> V_62 ,
V_129 ) ) {
T_1 V_279 = F_54 ( V_275 -> V_276 ,
V_280 ) ;
T_1 V_281 = F_54 ( V_275 -> V_282 ,
V_283 ) ;
enum V_7 V_8 ;
char V_270 = 'a' ;
bool V_269 = false ;
if ( V_129 == V_147 ) {
if ( V_281 % V_284 != 0 ) {
F_30 ( V_6 ,
L_37 ) ;
return 0 ;
}
V_8 = V_285 ;
V_281 = F_15 ( V_6 ,
V_8 ) *
( V_281 / V_284 ) ;
} else if ( V_129 ==
V_148 ) {
if ( V_281 % V_286 != 0 ) {
F_30 ( V_6 ,
L_38 ) ;
return 0 ;
}
V_8 = V_287 ;
V_281 = F_15 ( V_6 ,
V_8 ) *
( V_281 / V_286 ) ;
}
if ( V_101 [ V_218 -> V_62 ] ->
V_130 ) {
V_269 = true ;
V_270 =
V_34 [ V_101 [
V_218 -> V_62 ] ->
V_31 ] . V_288 ;
}
V_52 += F_71 ( V_6 , V_17 ,
V_44 + V_52 , V_45 , NULL ,
V_279 , V_281 , 0 ,
false ,
V_289 [ V_129 ] ,
V_269 , V_270 ) ;
}
}
}
return V_52 ;
}
static T_1 F_73 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_44 , bool V_45 )
{
T_1 V_52 = 0 , V_214 = 0 ;
while ( V_214 <
V_118 [ V_290 ] . V_216 ) {
const struct V_236 * V_237 =
( const struct V_236 * )
& V_118 [ V_290 ] . V_117 [ V_214 ++ ] ;
T_2 V_238 = F_54 ( V_237 -> V_239 ,
V_240 ) ;
T_1 V_241 = F_54 ( V_237 -> V_239 ,
V_242 ) ;
struct V_210 V_291 = {
& V_118 [ V_290 ] . V_117 [ V_214 ] ,
V_241 } ;
switch ( V_238 ) {
case V_244 :
V_52 += F_72 ( V_6 ,
V_17 ,
V_291 ,
V_44 + V_52 ,
V_45 ) ;
break;
default:
F_30 ( V_6 ,
L_39 ) ;
break;
}
V_214 += V_241 ;
}
return V_52 ;
}
static T_1 F_74 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_44 ,
bool V_45 ,
const char * V_86 ,
T_1 V_292 ,
T_1 V_293 ,
T_1 V_294 ,
T_2 V_31 )
{
T_1 V_40 , V_295 , V_296 ;
T_1 V_52 = 0 ;
if ( ! V_293 )
return 0 ;
V_293 *= V_41 ;
V_296 = V_292 * V_293 ;
V_52 += F_70 ( V_6 ,
V_44 + V_52 ,
V_45 ,
V_86 ,
0 ,
V_296 ,
V_293 * 32 ,
false ,
V_86 ,
true , V_34 [ V_31 ] . V_288 ) ;
if ( V_45 ) {
for ( V_295 = 0 ; V_295 < V_292 ; V_295 ++ ) {
for ( V_40 = 0 ; V_40 < V_293 ; V_40 ++ , V_52 ++ ) {
F_40 ( V_6 ,
V_17 ,
V_34 [ V_31 ] . V_297 ,
( V_40 << 9 ) | V_295 ) ;
* ( V_44 + V_52 ) = F_24 ( V_6 ,
V_17 ,
V_294 ) ;
}
}
} else {
V_52 += V_296 ;
}
return V_52 ;
}
static T_1 F_75 ( struct V_5 * V_6 ,
struct V_16 * V_17 , T_1 * V_44 , bool V_45 )
{
T_1 V_52 = 0 ;
T_2 V_31 ;
for ( V_31 = 0 ; V_31 < V_60 ; V_31 ++ ) {
if ( ! F_46 ( V_6 ,
(enum V_127 ) V_31 ) )
continue;
V_52 +=
F_74 ( V_6 ,
V_17 ,
V_44 + V_52 ,
V_45 ,
L_40 ,
F_15 ( V_6 ,
V_285 ) ,
V_34 [ V_31 ] .
V_298 ,
V_34 [ V_31 ] .
V_299 ,
V_31 ) ;
V_52 +=
F_74 ( V_6 ,
V_17 ,
V_44 + V_52 ,
V_45 ,
L_41 ,
F_15 ( V_6 ,
V_285 ) ,
V_34 [ V_31 ] .
V_300 ,
V_34 [ V_31 ] .
V_301 ,
V_31 ) ;
V_52 +=
F_74 ( V_6 ,
V_17 ,
V_44 + V_52 ,
V_45 ,
L_42 ,
F_15 ( V_6 ,
V_287 ) ,
V_34 [ V_31 ] .
V_302 ,
V_34 [ V_31 ] .
V_303 ,
V_31 ) ;
V_52 +=
F_74 ( V_6 ,
V_17 ,
V_44 + V_52 ,
V_45 ,
L_43 ,
F_15 ( V_6 ,
V_287 ) ,
V_34 [ V_31 ] .
V_304 ,
V_34 [ V_31 ] .
V_305 ,
V_31 ) ;
}
return V_52 ;
}
static T_1 F_76 ( struct V_5 * V_6 ,
struct V_16 * V_17 , T_1 * V_44 , bool V_45 )
{
char V_3 [ 10 ] = L_44 ;
T_2 V_31 , V_306 ;
T_1 V_52 = 0 ;
for ( V_31 = 0 ; V_31 < V_60 ; V_31 ++ ) {
struct V_307 * V_128 = & V_34 [ V_31 ] ;
if ( ! F_46 ( V_6 ,
(enum V_127 ) V_31 ) )
continue;
for ( V_306 = 0 ; V_306 < V_308 ; V_306 ++ ) {
T_1 V_309 , V_33 ;
V_309 = V_128 -> V_35 +
V_310 ;
V_33 = F_23 ( V_309 ) + F_77 ( V_306 ) ;
V_3 [ strlen ( V_3 ) - 1 ] = '0' + V_306 ;
V_52 += F_71 ( V_6 ,
V_17 ,
V_44 + V_52 ,
V_45 ,
V_3 ,
V_33 ,
V_311 ,
32 ,
false ,
L_45 ,
true ,
V_128 -> V_288 ) ;
}
}
return V_52 ;
}
static T_1 F_78 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_44 , bool V_45 , T_2 V_31 )
{
T_1 V_296 = V_312 * V_313 ;
T_1 V_314 [ V_315 ] = { 0 } ;
T_1 V_316 [ V_317 ] = { 0 } ;
T_1 V_52 = 0 ;
T_1 V_318 , V_40 ;
V_52 += F_70 ( V_6 ,
V_44 + V_52 ,
V_45 ,
L_46 ,
0 ,
V_296 ,
256 ,
false ,
L_46 ,
true , V_34 [ V_31 ] . V_288 ) ;
if ( V_45 ) {
F_79 ( V_314 , V_319 , V_320 , V_321 ) ;
for ( V_318 = 0 ; V_318 < V_312 ;
V_318 ++ , V_52 += V_313 ) {
F_79 ( V_316 , V_322 , V_323 , V_318 ) ;
F_80 ( V_6 ,
V_17 ,
V_34 [ V_31 ] . V_35 +
V_324 ,
V_316 , V_317 ) ;
F_80 ( V_6 ,
V_17 ,
V_34 [ V_31 ] . V_35 +
V_325 ,
V_314 , V_315 ) ;
F_81 ( V_6 ,
V_17 ,
V_34 [ V_31 ] . V_35 +
V_326 ,
V_44 + V_52 , V_313 ) ;
}
} else {
V_52 += V_296 ;
}
return V_52 ;
}
static T_1 F_82 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_44 ,
bool V_45 ,
T_2 V_31 , struct V_327 * V_328 )
{
T_1 V_296 = V_328 -> V_329 * V_330 ;
T_1 V_331 [ V_332 ] = { 0 } ;
T_1 V_333 [ V_334 ] = { 0 } ;
T_1 V_52 = 0 ;
T_1 V_318 , V_40 ;
V_52 += F_70 ( V_6 ,
V_44 + V_52 ,
V_45 ,
V_328 -> V_335 ,
0 ,
V_296 ,
256 ,
false ,
V_328 -> V_336 ,
true , V_34 [ V_31 ] . V_288 ) ;
F_79 ( V_331 , V_337 , V_320 , V_338 ) ;
if ( ! V_45 )
return V_52 + V_296 ;
for ( V_318 = V_328 -> V_339 ;
V_318 < V_328 -> V_339 + V_328 -> V_329 ;
V_318 ++ , V_52 += V_330 ) {
F_80 ( V_6 ,
V_17 ,
V_34 [ V_31 ] . V_35 +
V_324 ,
V_333 , V_334 ) ;
F_79 ( V_331 , V_337 , V_323 , V_318 ) ;
F_80 ( V_6 ,
V_17 ,
V_34 [ V_31 ] . V_35 +
V_325 ,
V_331 , V_332 ) ;
F_81 ( V_6 ,
V_17 ,
V_34 [ V_31 ] . V_35 +
V_326 ,
V_44 + V_52 , V_330 ) ;
}
return V_52 ;
}
static T_1 F_83 ( struct V_5 * V_6 ,
struct V_16 * V_17 , T_1 * V_44 , bool V_45 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
T_2 V_31 , V_40 ;
T_1 V_52 = 0 ;
for ( V_31 = 0 ; V_31 < V_60 ; V_31 ++ ) {
if ( F_46 ( V_6 ,
(enum V_127 ) V_31 ) &&
V_34 [ V_31 ] . V_340 &&
( V_31 != V_341 ||
V_10 -> V_28 == V_29 ) ) {
V_52 += F_78 ( V_6 ,
V_17 ,
V_44 + V_52 ,
V_45 , V_31 ) ;
for ( V_40 = 0 ; V_40 < V_342 ; V_40 ++ )
V_52 += F_82 ( V_6 ,
V_17 ,
V_44 +
V_52 ,
V_45 ,
V_31 ,
& V_343
[ V_40 ] ) ;
}
}
return V_52 ;
}
static T_1 F_84 ( struct V_5 * V_6 ,
struct V_16 * V_17 , T_1 * V_44 , bool V_45 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
T_1 V_52 = 0 ;
T_2 V_344 ;
for ( V_344 = 0 ; V_344 < V_345 ; V_344 ++ ) {
struct V_346 * V_347 = & V_348 [ V_344 ] ;
T_1 V_272 = V_347 -> V_272 [ V_10 -> V_21 ] ;
T_1 V_349 = V_347 -> V_349 [ V_10 -> V_21 ] ;
T_1 V_350 = ( V_272 * V_349 ) / 32 ;
T_1 V_42 = V_351 ;
bool V_267 = ( V_349 == 16 ) ;
T_1 V_352 = V_347 -> V_33 ;
T_1 V_40 , V_33 ;
V_52 += F_70 ( V_6 ,
V_44 + V_52 ,
V_45 ,
V_347 -> V_335 ,
0 ,
V_350 ,
V_349 ,
V_267 ,
V_347 -> V_336 , false , 0 ) ;
if ( ! V_45 ) {
V_52 += V_350 ;
continue;
}
for ( V_40 = 0 ; V_40 < V_350 ;
V_40 += V_351 , V_352 ++ ) {
V_33 = F_23 ( V_353 ) ;
F_40 ( V_6 , V_17 , V_354 , V_352 ) ;
V_52 += F_56 ( V_6 ,
V_17 ,
V_44 +
V_52 ,
V_45 ,
V_33 ,
V_42 ) ;
}
}
return V_52 ;
}
static T_1 F_85 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_44 , bool V_45 , T_2 V_355 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
T_1 V_356 , V_357 , V_52 = 0 , V_40 ;
char V_335 [ 12 ] = L_47 ;
char V_336 [ 8 ] = L_48 ;
struct V_358 * V_359 ;
V_359 = & V_132 [ V_355 ] ;
V_356 = V_359 -> V_360 [ V_10 -> V_21 ] ;
V_357 = V_356 * V_361 ;
strncpy ( V_336 , V_359 -> V_362 ,
strlen ( V_359 -> V_362 ) ) ;
strncpy ( V_335 , V_359 -> V_362 ,
strlen ( V_359 -> V_362 ) ) ;
V_52 += F_70 ( V_6 ,
V_44 + V_52 ,
V_45 ,
V_335 ,
0 ,
V_357 ,
V_363 * 8 ,
false , V_336 , false , 0 ) ;
if ( ! V_45 )
return V_52 + V_357 ;
for ( V_40 = 0 ; V_40 < V_356 / 2 ; V_40 ++ ) {
T_1 V_33 , V_202 ;
F_40 ( V_6 , V_17 , V_359 -> V_364 , V_40 ) ;
V_33 = F_23 ( V_359 -> V_365 ) ;
V_202 = 2 * V_361 ;
V_52 += F_56 ( V_6 ,
V_17 ,
V_44 + V_52 ,
V_45 ,
V_33 ,
V_202 ) ;
}
return V_52 ;
}
static T_1 F_86 ( struct V_5 * V_6 ,
struct V_16 * V_17 , T_1 * V_44 , bool V_45 )
{
bool V_212 [ V_100 ] = { 0 } ;
T_1 V_52 = 0 , V_33 ;
bool V_366 = false ;
if ( V_45 && ! F_15 ( V_6 , V_367 ) ) {
V_366 = ! F_87 ( V_6 , V_17 ) ;
if ( ! V_366 )
F_30 ( V_6 , L_49 ) ;
}
V_52 += F_71 ( V_6 ,
V_17 ,
V_44 + V_52 ,
V_45 ,
NULL ,
F_23 ( V_79 ) ,
V_368 ,
0 , false , L_50 , false , 0 ) ;
V_52 += F_71 ( V_6 ,
V_17 ,
V_44 + V_52 ,
V_45 ,
NULL ,
F_23 ( V_369 ) ,
V_370 ,
0 , false , L_50 , false , 0 ) ;
V_212 [ V_371 ] = true ;
V_52 += F_63 ( V_6 ,
V_17 ,
V_44 + V_52 ,
V_45 , V_212 , L_51 , L_50 ) ;
V_52 += F_55 ( V_44 + V_52 ,
V_45 , 1 , L_21 , - 1 , L_51 , L_50 ) ;
V_33 = F_23 ( V_78 ) ;
V_52 += F_58 ( V_6 ,
V_17 ,
V_44 + V_52 ,
V_45 ,
V_33 ,
1 ) ;
if ( V_366 && F_88 ( V_6 , V_17 ) )
F_30 ( V_6 , L_52 ) ;
return V_52 ;
}
static T_1 F_89 ( struct V_5 * V_6 ,
struct V_16 * V_17 , T_1 * V_44 , bool V_45 )
{
T_1 V_52 = 0 , V_372 , V_373 ;
char V_335 [ 32 ] ;
T_2 V_374 ;
for ( V_374 = 0 ; V_374 < F_90 ( V_375 ) ; V_374 ++ ) {
struct V_376 * V_376 = & V_375 [ V_374 ] ;
int V_57 ;
V_57 = snprintf ( V_335 , sizeof( V_335 ) , L_53 ,
V_376 -> V_377 ) ;
if ( V_57 < 0 || V_57 >= sizeof( V_335 ) )
F_30 ( V_6 ,
L_54 ) ;
V_52 += F_70 ( V_6 ,
V_44 + V_52 ,
V_45 ,
V_335 ,
0 ,
V_378 ,
16 , true , V_335 , false , 0 ) ;
if ( V_45 ) {
T_1 V_379 = V_376 -> V_380 +
V_376 -> V_381 ;
T_1 V_382 = V_376 -> V_380 +
V_376 -> V_383 ;
T_1 V_384 = V_376 -> V_380 +
V_376 -> V_385 ;
T_1 V_386 = V_376 -> V_380 +
V_376 -> V_387 ;
T_2 * V_388 = ( T_2 * ) ( V_44 + V_52 ) ;
for ( V_373 = 0 ;
V_373 < ( V_389 >> 8 ) ;
V_373 ++ ) {
F_40 ( V_6 ,
V_17 , V_382 , V_373 ) ;
for ( V_372 = 0 ; V_372 < 256 ;
V_372 ++ ) {
F_40 ( V_6 ,
V_17 ,
V_379 , V_372 ) ;
* ( V_388 ++ ) =
( T_2 ) F_24 ( V_6 , V_17 ,
V_384 ) ;
* ( V_388 ++ ) =
( T_2 ) F_24 ( V_6 , V_17 ,
V_386 ) ;
}
}
}
V_52 += V_378 ;
}
return V_52 ;
}
static void F_91 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
enum V_62 V_62 ,
T_2 V_390 ,
T_2 V_391 ,
T_2 V_392 , T_2 V_393 , T_2 V_394 )
{
struct V_395 * V_396 = V_101 [ V_62 ] ;
F_40 ( V_6 , V_17 , V_396 -> V_397 , V_390 ) ;
F_40 ( V_6 , V_17 , V_396 -> V_398 , V_391 ) ;
F_40 ( V_6 , V_17 , V_396 -> V_399 , V_392 ) ;
F_40 ( V_6 , V_17 , V_396 -> V_400 , V_393 ) ;
F_40 ( V_6 , V_17 , V_396 -> V_401 , V_394 ) ;
}
static T_1 F_92 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_44 , bool V_45 )
{
T_1 V_402 = V_403 * V_404 ;
struct V_9 * V_10 = & V_6 -> V_11 ;
T_1 V_52 = 0 , V_62 , V_390 ;
struct V_395 * V_396 ;
if ( V_45 ) {
F_64 ( V_6 ,
V_234 , L_55 ) ;
for ( V_62 = 0 ; V_62 < V_100 ; V_62 ++ ) {
V_396 = V_101 [ V_62 ] ;
if ( V_396 -> V_405 [ V_10 -> V_21 ] )
F_40 ( V_6 , V_17 ,
V_396 -> V_398 , 0 ) ;
}
F_41 ( V_6 , V_17 ) ;
F_42 ( V_6 ,
V_17 , V_406 ) ;
F_40 ( V_6 ,
V_17 , V_407 , V_408 ) ;
F_40 ( V_6 , V_17 , V_409 , 1 ) ;
F_39 ( V_6 , V_17 , true ) ;
}
for ( V_62 = 0 ; V_62 < V_100 ; V_62 ++ ) {
V_396 = V_101 [ V_62 ] ;
if ( ! V_396 -> V_405 [ V_10 -> V_21 ] )
continue;
V_52 += F_70 ( V_6 ,
V_44 + V_52 ,
V_45 ,
V_396 -> V_86 , 0 ,
V_402 , 32 , false ,
L_56 , false , 0 ) ;
if ( V_45 && ! V_10 -> V_61 [ V_62 ] ) {
T_2 V_410 =
V_396 -> V_410 [ V_10 -> V_21 ] ;
T_1 V_33 = F_23 ( V_411 ) ;
T_1 V_202 = V_404 ;
F_43 ( V_6 , V_17 ,
F_38 ( V_410 ) ) ;
for ( V_390 = 0 ; V_390 < V_403 ;
V_390 ++ ) {
F_91 ( V_6 ,
V_17 ,
(enum V_62 ) V_62 ,
( T_2 ) V_390 ,
0xf , 0 , 0 , 0 ) ;
V_52 +=
F_56 ( V_6 ,
V_17 ,
V_44 + V_52 ,
V_45 ,
V_33 ,
V_202 ) ;
}
F_43 ( V_6 , V_17 , 0 ) ;
F_40 ( V_6 , V_17 ,
V_396 -> V_398 , 0 ) ;
} else {
if ( V_45 )
memset ( V_44 + V_52 , 0 ,
F_22 ( V_402 ) ) ;
V_52 += V_402 ;
}
}
if ( V_45 ) {
F_39 ( V_6 , V_17 , false ) ;
F_43 ( V_6 , V_17 , 0 ) ;
}
return V_52 ;
}
static enum V_15 F_93 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_44 ,
bool V_45 , T_1 * V_412 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
bool V_413 = false ;
T_2 V_40 , V_414 = 0 ;
T_1 V_52 = 0 ;
* V_412 = 0 ;
if ( V_45 ) {
switch ( F_24 ( V_6 , V_17 , V_415 ) ) {
case 0 :
V_414 = 1 ;
break;
case 1 :
V_414 = 2 ;
break;
case 2 :
V_414 = 4 ;
break;
}
}
if ( V_45 )
F_37 ( V_6 , V_17 ) ;
V_52 += F_34 ( V_6 ,
V_17 ,
V_44 + V_52 , V_45 , 4 ) ;
V_52 += F_27 ( V_44 + V_52 ,
V_45 , L_57 , L_58 ) ;
V_52 += F_28 ( V_44 + V_52 ,
V_45 ,
L_59 ,
F_15 ( V_6 ,
V_285 ) ) ;
V_52 += F_28 ( V_44 + V_52 ,
V_45 ,
L_60 ,
F_15 ( V_6 ,
V_287 ) ) ;
V_52 += F_28 ( V_44 + V_52 ,
V_45 , L_61 , V_414 ) ;
if ( F_45 ( V_6 , V_416 ) )
V_52 += F_67 ( V_6 ,
V_17 ,
V_44 + V_52 , V_45 ) ;
if ( V_45 ) {
F_50 ( V_6 , V_17 ) ;
F_37 ( V_6 , V_17 ) ;
}
if ( V_45 && ! F_15 ( V_6 , V_367 ) ) {
V_413 = ! F_94 ( V_6 , V_17 , 1 ) ;
if ( ! V_413 ) {
F_30 ( V_6 ,
L_62 ) ;
if ( F_15
( V_6 , V_417 ) )
return V_418 ;
}
}
if ( F_45 ( V_6 , V_416 ) )
V_52 += F_68 ( V_6 ,
V_17 ,
V_44 + V_52 , V_45 ) ;
if ( V_45 &&
( F_45 ( V_6 ,
V_169 ) ||
F_45 ( V_6 , V_419 ) ) )
F_48 ( V_6 , V_17 , true ) ;
if ( F_45 ( V_6 , V_416 ) ) {
bool V_212 [ V_100 ] ;
for ( V_40 = 0 ; V_40 < V_100 ; V_40 ++ )
V_212 [ V_40 ] = true ;
V_212 [ V_371 ] = false ;
V_52 += F_63 ( V_6 ,
V_17 ,
V_44 +
V_52 ,
V_45 ,
V_212 , NULL , NULL ) ;
V_52 += F_69 ( V_6 ,
V_17 ,
V_44 + V_52 , V_45 ) ;
}
V_52 += F_73 ( V_6 , V_17 , V_44 + V_52 , V_45 ) ;
if ( F_45 ( V_6 , V_420 ) )
V_52 += F_86 ( V_6 ,
V_17 , V_44 + V_52 , V_45 ) ;
if ( F_45 ( V_6 , V_421 ) )
V_52 += F_75 ( V_6 ,
V_17 , V_44 + V_52 , V_45 ) ;
if ( F_45 ( V_6 , V_422 ) )
V_52 += F_84 ( V_6 ,
V_17 , V_44 + V_52 , V_45 ) ;
for ( V_40 = 0 ; V_40 < V_131 ; V_40 ++ )
if ( F_45 ( V_6 , V_132 [ V_40 ] . V_8 ) )
V_52 += F_85 ( V_6 ,
V_17 ,
V_44 + V_52 ,
V_45 , V_40 ) ;
if ( F_45 ( V_6 , V_169 ) )
V_52 += F_76 ( V_6 ,
V_17 , V_44 + V_52 , V_45 ) ;
if ( F_45 ( V_6 , V_419 ) )
V_52 += F_83 ( V_6 ,
V_17 , V_44 + V_52 , V_45 ) ;
if ( F_45 ( V_6 ,
V_423 ) && V_10 -> V_21 ==
V_22 && V_10 -> V_28 == V_29 )
V_52 += F_89 ( V_6 ,
V_17 , V_44 + V_52 , V_45 ) ;
if ( F_45 ( V_6 ,
V_424 ) &&
V_10 -> V_425 . V_426 == V_427 )
V_52 += F_92 ( V_6 ,
V_17 ,
V_44 + V_52 , V_45 ) ;
V_52 += F_35 ( V_44 , V_52 , V_45 ) ;
if ( V_45 ) {
if ( F_15 ( V_6 , V_428 ) )
F_48 ( V_6 , V_17 , false ) ;
F_53 ( V_6 , V_17 ) ;
if ( V_413 )
F_94 ( V_6 , V_17 , 0 ) ;
}
* V_412 = V_52 ;
return V_19 ;
}
static T_1 F_95 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 *
V_44 ,
bool V_45 ,
T_3 V_429 ,
const struct V_430 * V_431 ,
T_3 V_432 , T_1 * V_433 )
{
const union V_434 * V_435 = & ( ( const union V_434 * )
V_118
[ V_436 ] .
V_117 ) [ V_431 -> V_208 ] ;
const struct V_437 * V_438 = & V_435 [ 0 ] . V_439 ;
struct V_9 * V_10 = & V_6 -> V_11 ;
struct V_440 * V_239 =
(struct V_440 * ) V_44 ;
const struct V_441 * V_442 =
& V_435 [ V_431 -> V_443 ] . V_444 ;
T_1 V_445 = 0 , V_40 , V_52 = 0 ;
T_2 V_446 ;
if ( V_45 ) {
memset ( V_239 , 0 , sizeof( * V_239 ) ) ;
V_239 -> V_429 = V_429 ;
V_239 -> V_447 = V_432 ;
V_239 -> V_448 = V_431 -> V_448 ;
V_239 -> V_449 = V_431 -> V_443 ;
}
V_52 += V_450 ;
for ( V_446 = 0 ; V_446 < V_431 -> V_443 ; V_446 ++ ) {
const struct V_437 * V_221 = & V_438 [ V_446 ] ;
if ( V_45 ) {
struct V_451 * V_452 =
(struct V_451 * ) ( V_44
+ V_52 ) ;
V_52 += V_453 ;
memset ( V_452 , 0 ,
sizeof( struct V_451 ) ) ;
V_452 -> V_454 = V_221 -> V_454 ;
V_452 -> V_42 = V_221 -> V_455 ;
F_96 ( V_452 -> V_195 ,
V_456 ,
V_221 -> V_272 > 1 || V_221 -> V_454 > 0
? 1 : 0 ) ;
F_96 ( V_452 -> V_195 ,
V_457 , V_446 ) ;
for ( V_40 = 0 ; V_40 < V_452 -> V_42 ;
V_40 ++ , V_445 ++ , V_52 ++ )
V_44 [ V_52 ] =
V_433 [ V_445 ] ;
} else {
V_52 += V_453 +
V_221 -> V_455 ;
}
}
for ( V_446 = 0 ; V_446 < V_431 -> V_458 ; V_446 ++ ) {
const struct V_441 * V_221 = & V_442 [ V_446 ] ;
T_1 V_62 ;
if ( ! V_45 ) {
V_52 += V_453 + V_221 -> V_42 ;
continue;
}
V_62 = F_54 ( V_221 -> V_195 , V_459 ) ;
if ( V_62 >= V_100 ) {
F_30 ( V_6 , L_63 ) ;
return 0 ;
}
if ( ! V_10 -> V_61 [ V_62 ] ) {
bool V_194 = F_54 ( V_221 -> V_112 . V_195 ,
V_196 ) > 0 ;
bool V_215 = true ;
if ( V_194 ) {
T_3 V_116 =
F_54 ( V_221 -> V_112 . V_195 ,
V_197 ) ;
V_215 =
F_44 ( V_6 ,
& V_116 ) ;
}
if ( V_215 ) {
T_1 V_33 =
F_54 ( V_221 -> V_195 ,
V_460 ) ;
struct V_451 * V_452 =
(struct V_451 * )
( V_44 + V_52 ) ;
V_52 += V_453 ;
V_239 -> V_461 ++ ;
memset ( V_452 , 0 , sizeof( * V_452 ) ) ;
V_452 -> V_42 = V_221 -> V_42 ;
F_96 ( V_452 -> V_195 ,
V_457 ,
V_431 -> V_443 + V_446 ) ;
V_52 +=
F_56 ( V_6 ,
V_17 ,
V_44 + V_52 ,
V_45 ,
V_33 ,
V_221 -> V_42 ) ;
}
}
}
return V_52 ;
}
static T_1
F_97 ( struct V_5 * V_6 , struct V_16 * V_17 ,
T_1 * V_44 , bool V_45 ,
const struct V_430 * V_462 ,
T_1 V_463 , T_1 * V_464 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
T_1 V_433 [ V_465 ] ;
T_1 V_40 , V_52 = 0 ;
T_3 V_466 ;
T_2 V_446 ;
* V_464 = 0 ;
for ( V_40 = 0 ; V_40 < V_463 ; V_40 ++ ) {
const struct V_437 * V_438 ;
const struct V_430 * V_431 ;
const union V_434 * V_435 ;
T_3 V_199 = 1 ;
bool V_467 = true ;
const T_1 * V_468 ;
V_431 = & V_462 [ V_40 ] ;
V_435 = & ( ( const union V_434 * )
V_118 [ V_436 ] . V_117 )
[ V_431 -> V_208 ] ;
V_438 = & V_435 [ 0 ] . V_439 ;
V_468 = & V_118 [ V_469 ] . V_117
[ V_431 -> V_470 ] ;
for ( V_446 = 0 ; V_446 < V_431 -> V_443 && V_467 ;
V_446 ++ ) {
T_1 V_62 = F_54 ( V_438 [ V_446 ] . V_195 ,
V_471 ) ;
if ( V_62 >= V_100 ) {
F_30 ( V_6 , L_63 ) ;
return 0 ;
}
V_467 = ! V_10 -> V_61 [ V_62 ] ;
if ( V_438 [ V_446 ] . V_272 > V_199 )
V_199 = V_438 [ V_446 ] . V_272 ;
}
if ( ! V_467 && V_45 )
continue;
if ( ! V_45 ) {
T_1 V_472 =
F_95 ( V_6 ,
V_17 ,
V_44 + V_52 ,
false ,
V_431 -> V_429 ,
V_431 ,
0 ,
NULL ) ;
V_52 += V_199 * V_472 ;
( * V_464 ) += V_199 ;
continue;
}
for ( V_466 = 0 ; V_466 < V_199 ; V_466 ++ ) {
T_1 V_445 = 0 ;
for ( V_446 = 0 ; V_446 < V_431 -> V_443 ;
V_446 ++ ) {
const struct V_437 * V_221 =
& V_438 [ V_446 ] ;
T_1 V_33 =
F_54 ( V_221 -> V_195 ,
V_473 ) ;
if ( V_221 -> V_272 > 1 ||
V_221 -> V_454 > 0 ) {
T_1 V_474 =
V_221 -> V_455 > 1 ?
F_98 ( V_221 -> V_455 ) :
1 ;
V_33 += ( V_221 -> V_454 + V_466 ) *
V_474 ;
}
if ( V_445 + V_221 -> V_455 >=
V_465 ) {
F_30 ( V_6 ,
L_64 ) ;
return 0 ;
}
V_445 +=
F_56 ( V_6 ,
V_17 ,
V_433 +
V_445 ,
V_45 , V_33 ,
V_221 -> V_455 ) ;
}
if ( (* F_99 [ V_431 -> V_475 ])( V_433 ,
V_468 ) ) {
V_52 +=
F_95 ( V_6 ,
V_17 ,
V_44 + V_52 ,
V_45 ,
V_431 -> V_429 ,
V_431 ,
V_466 ,
V_433 ) ;
( * V_464 ) ++ ;
break;
}
}
}
return V_52 ;
}
static T_1 F_100 ( struct V_5 * V_6 ,
struct V_16 * V_17 , T_1 * V_44 , bool V_45 )
{
T_1 V_52 = 0 , V_214 = 0 , V_464 = 0 ;
T_1 V_476 ;
V_52 += F_34 ( V_6 ,
V_17 ,
V_44 + V_52 , V_45 , 1 ) ;
V_52 += F_27 ( V_44 + V_52 ,
V_45 , L_57 , L_65 ) ;
V_52 += F_33 ( V_44 + V_52 , V_45 , L_66 , 1 ) ;
V_476 = V_52 ;
V_52 += F_28 ( V_44 + V_52 , V_45 , L_67 , 0 ) ;
while ( V_214 <
V_118 [ V_477 ] . V_216 ) {
const struct V_478 * V_218 =
( const struct V_478 * )
& V_118 [ V_477 ] . V_117
[ V_214 ++ ] ;
bool V_194 = F_54 ( V_218 -> V_112 . V_195 ,
V_196 ) > 0 ;
bool V_215 = true ;
if ( V_194 ) {
T_3 V_116 =
F_54 ( V_218 -> V_112 . V_195 ,
V_197 ) ;
V_215 = F_44 ( V_6 ,
& V_116 ) ;
}
if ( V_215 ) {
T_1 V_479 ;
V_52 +=
F_97 ( V_6 ,
V_17 ,
V_44 + V_52 ,
V_45 ,
( const struct V_430 * )
& V_118 [ V_477 ] .
V_117 [ V_214 ] ,
V_218 -> V_219 / V_480 ,
& V_479 ) ;
V_464 += V_479 ;
}
V_214 += V_218 -> V_219 ;
}
if ( V_45 )
F_28 ( V_44 + V_476 ,
V_45 , L_67 , V_464 ) ;
return V_52 ;
}
static enum V_15 F_101 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 V_481 ,
T_1 * V_482 ,
T_1 * V_483 )
{
T_1 V_484 , V_485 , V_486 ;
struct V_487 V_488 ;
int V_489 = F_102 ( V_6 ,
V_17 ,
V_490 ,
V_481 ,
& V_484 ,
& V_485 ,
& V_486 ,
( T_1 * ) & V_488 ) ;
if ( V_489 ||
( V_484 & V_491 ) != V_492 )
return V_493 ;
* V_482 = V_488 . V_494 ;
* V_483 = V_488 . V_202 ;
F_64 ( V_6 ,
V_234 ,
L_68 ,
V_481 , * V_482 , * V_483 ) ;
if ( * V_483 & 0x3 )
return V_495 ;
return V_19 ;
}
static enum V_15 F_103 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 V_482 ,
T_1 V_483 , T_1 * V_496 )
{
T_1 V_484 , V_485 , V_497 ;
T_1 V_498 , V_499 = 0 ;
T_4 V_500 = V_483 ;
F_64 ( V_6 ,
V_234 ,
L_69 ,
V_483 ) ;
do {
V_498 =
( V_500 >
V_501 ) ? V_501 : V_500 ;
if ( F_102 ( V_6 , V_17 ,
V_502 ,
( V_482 +
V_499 ) |
( V_498 <<
V_503 ) ,
& V_484 , & V_485 ,
& V_497 ,
( T_1 * ) ( ( T_2 * ) V_496 +
V_499 ) ) != 0 )
return V_504 ;
if ( ( V_484 & V_491 ) != V_492 )
return V_504 ;
V_499 += V_497 ;
V_500 -= V_497 ;
} while ( V_500 > 0 );
return V_19 ;
}
static enum V_15 F_104 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_505 ,
T_1 * V_506 )
{
T_1 V_507 = F_24 ( V_6 ,
V_17 ,
V_508 ) ;
T_1 V_509 ;
* V_505 =
V_79 + F_105 ( V_507 ) ;
V_509 = F_24 ( V_6 , V_17 ,
* V_505 +
F_32 ( struct V_510 , V_509 ) ) ;
if ( V_509 != V_511 )
return V_512 ;
* V_506 = F_24 ( V_6 ,
V_17 ,
* V_505 +
F_32 ( struct V_510 , V_42 ) ) ;
return V_19 ;
}
static enum V_15 F_106 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 V_506 ,
T_1 * V_513 ,
T_1 * V_514 ,
T_1 * V_515 )
{
T_1 V_507 = F_24 ( V_6 ,
V_17 ,
V_508 ) ;
T_1 V_516 =
V_79 + F_105 ( V_507 ) +
F_107 ( V_507 ) + V_506 ;
T_1 V_517 ;
* V_513 = F_24 ( V_6 , V_17 , V_516 ) ;
if ( * V_513 > 1 )
return V_518 ;
V_517 =
( * V_513 ==
V_519 ) ? V_520 : V_521 ;
return F_101 ( V_6 ,
V_17 ,
V_517 ,
V_514 ,
V_515 ) ;
}
static enum V_15 F_108 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 V_522 ,
T_1 V_523 , T_1 * V_3 )
{
T_2 * V_524 = ( T_2 * ) V_3 ;
T_2 V_525 , V_40 ;
T_1 V_509 ;
enum V_15 V_526 = F_103 ( V_6 ,
V_17 ,
V_522 ,
V_523 ,
V_3 ) ;
if ( V_526 != V_19 )
return V_526 ;
V_509 = F_14 ( V_524 ) ;
V_524 += sizeof( T_1 ) ;
if ( V_509 != V_527 )
return V_512 ;
V_525 = * ( V_524 ++ ) ;
for ( V_40 = 0 ; V_40 < V_525 ; V_40 ++ ) {
T_2 V_528 = * ( V_524 ++ ) ;
V_524 += V_528 ;
}
V_509 = F_14 ( V_524 ) ;
V_524 += sizeof( T_1 ) ;
if ( V_509 != V_527 )
return V_512 ;
return V_19 ;
}
static enum V_15 F_109 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_44 ,
bool V_45 , T_1 * V_412 )
{
T_1 V_505 , V_506 , V_529 ;
T_1 V_530 = 0 , V_513 , V_52 = 0 ;
T_1 V_514 = 0 , V_515 = 0 ;
enum V_15 V_526 ;
bool V_531 ;
int V_366 = 0 ;
V_531 = ! F_15 ( V_6 , V_367 ) ;
* V_412 = 0 ;
V_526 = F_104 ( V_6 ,
V_17 ,
& V_505 ,
& V_506 ) ;
if ( V_526 != V_19 )
return V_526 ;
V_52 += F_34 ( V_6 ,
V_17 ,
V_44 + V_52 , V_45 , 1 ) ;
V_52 += F_27 ( V_44 + V_52 ,
V_45 , L_57 , L_70 ) ;
if ( V_45 && V_531 ) {
V_366 = ! F_87 ( V_6 , V_17 ) ;
if ( ! V_366 )
F_30 ( V_6 , L_49 ) ;
}
V_529 =
F_110 ( V_506 + sizeof( struct V_510 ) ,
V_41 ) ;
V_52 += F_33 ( V_44 + V_52 ,
V_45 , L_71 , 1 ) ;
V_52 += F_28 ( V_44 + V_52 ,
V_45 , L_72 , V_529 ) ;
V_52 += F_56 ( V_6 ,
V_17 ,
V_44 + V_52 ,
V_45 ,
F_23 ( V_505 ) ,
V_529 ) ;
if ( V_366 && F_88 ( V_6 , V_17 ) != 0 )
F_30 ( V_6 , L_52 ) ;
V_52 += F_33 ( V_44 + V_52 ,
V_45 , L_73 , 1 ) ;
if ( V_531 ) {
V_526 = F_106 ( V_6 ,
V_17 ,
V_506 ,
& V_513 ,
& V_514 ,
& V_515 ) ;
if ( V_526 == V_19 )
V_530 =
F_23 ( V_515 ) ;
}
V_52 += F_28 ( V_44 + V_52 ,
V_45 , L_72 , V_530 ) ;
if ( V_45 && V_530 )
V_526 = F_108 ( V_6 ,
V_17 ,
V_514 ,
V_515 ,
V_44 + V_52 ) ;
if ( V_526 == V_19 )
V_52 += V_530 ;
* V_412 = V_52 ;
return V_531 ? V_526 : V_493 ;
}
static enum V_15 F_111 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_44 ,
bool V_45 , T_1 * V_412 )
{
T_1 V_52 = 0 , V_532 , V_533 ;
bool V_534 ;
* V_412 = 0 ;
V_52 += F_34 ( V_6 ,
V_17 ,
V_44 + V_52 , V_45 , 1 ) ;
V_52 += F_27 ( V_44 + V_52 ,
V_45 , L_57 , L_74 ) ;
V_52 += F_33 ( V_44 + V_52 ,
V_45 , L_75 , 1 ) ;
V_533 = V_52 ;
V_52 += F_28 ( V_44 + V_52 , V_45 , L_72 , 0 ) ;
if ( ! V_45 ) {
V_52 += V_535 ;
* V_412 = V_52 ;
return V_19 ;
}
V_534 = F_24 ( V_6 , V_17 ,
V_536 ) > 0 ;
for ( V_532 = 0 ;
V_534 && V_532 < V_535 ;
V_532 += V_537 , V_52 +=
V_537 ) {
if ( F_112 ( V_6 , V_17 , V_538 ,
( V_539 ) ( V_540 ) ( & V_44 [ V_52 ] ) ,
V_537 , 0 ) )
return V_541 ;
V_534 = F_24 ( V_6 , V_17 ,
V_536 ) > 0 ;
}
F_28 ( V_44 + V_533 , V_45 , L_72 ,
V_532 ) ;
* V_412 = V_52 ;
return V_19 ;
}
static enum V_15 F_113 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_44 ,
bool V_45 , T_1 * V_412 )
{
T_1 V_52 = 0 , V_532 , V_533 ;
bool V_534 ;
* V_412 = 0 ;
V_52 += F_34 ( V_6 ,
V_17 ,
V_44 + V_52 , V_45 , 1 ) ;
V_52 += F_27 ( V_44 + V_52 ,
V_45 , L_57 , L_76 ) ;
V_52 += F_33 ( V_44 + V_52 ,
V_45 , L_77 , 1 ) ;
V_533 = V_52 ;
V_52 += F_28 ( V_44 + V_52 , V_45 , L_72 , 0 ) ;
if ( ! V_45 ) {
V_52 += V_542 ;
* V_412 = V_52 ;
return V_19 ;
}
V_534 = F_24 ( V_6 , V_17 ,
V_543 ) > 0 ;
for ( V_532 = 0 ;
V_534 && V_532 < V_542 ;
V_532 += V_544 , V_52 +=
V_544 ) {
if ( F_112 ( V_6 , V_17 ,
V_545 ,
( V_539 ) ( V_540 ) ( & V_44 [ V_52 ] ) ,
V_544 , 0 ) )
return V_541 ;
V_534 = F_24 ( V_6 , V_17 ,
V_543 ) > 0 ;
}
F_28 ( V_44 + V_533 , V_45 , L_72 ,
V_532 ) ;
* V_412 = V_52 ;
return V_19 ;
}
static enum V_15 F_114 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_44 ,
bool V_45 ,
T_1 * V_412 )
{
T_1 V_52 = 0 , V_533 , V_546 ;
* V_412 = 0 ;
V_52 += F_34 ( V_6 ,
V_17 ,
V_44 + V_52 , V_45 , 1 ) ;
V_52 += F_27 ( V_44 + V_52 ,
V_45 , L_57 , L_78 ) ;
V_52 += F_33 ( V_44 + V_52 ,
V_45 , L_79 , 1 ) ;
V_533 = V_52 ;
V_52 += F_28 ( V_44 + V_52 , V_45 , L_72 , 0 ) ;
if ( ! V_45 ) {
V_52 += V_547 ;
* V_412 = V_52 ;
return V_19 ;
}
V_546 =
F_24 ( V_6 , V_17 ,
V_548 ) *
V_549 ;
if ( F_112 ( V_6 , V_17 ,
V_550 ,
( V_539 ) ( V_540 ) ( V_44 + V_52 ) ,
V_546 , 0 ) )
return V_541 ;
V_52 += V_546 ;
F_28 ( V_44 + V_533 , V_45 , L_72 ,
V_546 ) ;
* V_412 = V_52 ;
return V_19 ;
}
static T_1 F_115 ( struct V_5 * V_6 ,
struct V_16 * V_17 , T_1 * V_44 , bool V_45 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
struct V_551 * V_552 ;
char V_553 [ 2 ] = L_80 ;
struct V_32 V_32 ;
T_1 V_52 = 0 ;
T_2 V_31 ;
V_52 += F_34 ( V_6 ,
V_17 ,
V_44 + V_52 , V_45 , 1 ) ;
V_52 += F_27 ( V_44 + V_52 ,
V_45 , L_57 , L_81 ) ;
for ( V_31 = 0 ; V_31 < V_60 ; V_31 ++ ) {
T_1 V_554 , V_555 , V_556 ;
T_1 V_557 , V_33 ;
if ( V_10 -> V_61 [ V_34 [ V_31 ] . V_62 ] )
continue;
F_21 ( V_6 , V_17 , V_31 , & V_32 ) ;
V_552 = & V_32 . V_558 ;
V_553 [ 0 ] = V_34 [ V_31 ] . V_288 ;
V_52 += F_33 ( V_44 + V_52 , V_45 ,
L_82 , 2 ) ;
V_52 += F_27 ( V_44 + V_52 , V_45 , L_83 ,
V_553 ) ;
V_52 += F_28 ( V_44 + V_52 , V_45 , L_72 ,
V_552 -> V_559 ) ;
if ( ! V_45 ) {
V_52 += V_552 -> V_559 ;
continue;
}
V_554 =
V_34 [ V_31 ] . V_35 +
V_36 +
F_116 ( V_552 -> V_560 ) ;
V_555 =
V_554 +
F_22 ( V_552 -> V_561 ) ;
V_556 = F_24 ( V_6 , V_17 , V_555 ) ;
V_557 = ( V_556 > 0
? V_556
: V_552 -> V_562 ) - 1 ;
V_33 = F_23 ( V_554 ) +
V_552 -> V_563 +
V_557 * V_552 -> V_559 ;
V_52 +=
F_56 ( V_6 , V_17 ,
V_44 + V_52 ,
V_45 , V_33 ,
V_552 -> V_559 ) ;
}
V_52 += F_33 ( V_44 + V_52 , V_45 , L_15 , 0 ) ;
return V_52 ;
}
enum V_15 F_117 ( const T_2 * const V_564 )
{
struct V_565 * V_566 = (struct V_565 * ) V_564 ;
T_2 V_567 ;
for ( V_567 = 0 ; V_567 < V_568 ; V_567 ++ ) {
V_118 [ V_567 ] . V_117 =
( T_1 * ) ( V_564 + V_566 [ V_567 ] . V_52 ) ;
V_118 [ V_567 ] . V_216 =
F_23 ( V_566 [ V_567 ] . V_569 ) ;
}
return V_19 ;
}
void F_17 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
T_1 V_40 ;
for ( V_40 = 0 ; V_40 < V_570 ; V_40 ++ )
V_10 -> V_12 . V_13 [ V_40 ] =
V_571 [ V_40 ] . V_572 [ V_10 -> V_21 ] ;
}
enum V_15 F_118 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_573 )
{
enum V_15 V_526 = F_18 ( V_6 , V_17 ) ;
* V_573 = 0 ;
if ( V_526 != V_19 )
return V_526 ;
if ( ! V_118 [ V_119 ] . V_117 ||
! V_118 [ V_235 ] . V_117 ||
! V_118 [ V_290 ] . V_117 ||
! V_118 [ V_182 ] . V_117 ||
! V_118 [ V_188 ] . V_117 )
return V_574 ;
return F_93 ( V_6 , V_17 , NULL , false , V_573 ) ;
}
enum V_15 F_119 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_44 ,
T_1 V_575 ,
T_1 * V_412 )
{
T_1 V_576 ;
enum V_15 V_526 ;
V_526 = F_118 ( V_6 , V_17 ,
& V_576 ) ;
* V_412 = 0 ;
if ( V_526 != V_19 )
return V_526 ;
if ( V_575 < V_576 )
return V_577 ;
V_526 = F_93 ( V_6 , V_17 , V_44 , true , V_412 ) ;
F_17 ( V_6 ) ;
return V_526 ;
}
enum V_15 F_120 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_573 )
{
enum V_15 V_526 = F_18 ( V_6 , V_17 ) ;
struct V_9 * V_10 = & V_6 -> V_11 ;
* V_573 = 0 ;
if ( V_526 != V_19 )
return V_526 ;
if ( ! V_118 [ V_119 ] . V_117 ||
! V_118 [ V_436 ] . V_117 ||
! V_118 [ V_469 ] . V_117 ||
! V_118 [ V_477 ] . V_117 )
return V_574 ;
if ( ! V_10 -> V_578 . V_579 ) {
V_10 -> V_578 . V_573 = F_100 ( V_6 ,
V_17 ,
NULL , false ) ;
V_10 -> V_578 . V_579 = true ;
}
* V_573 = V_10 -> V_578 . V_573 ;
return V_19 ;
}
enum V_15 F_121 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_44 ,
T_1 V_575 ,
T_1 * V_412 )
{
T_1 V_576 ;
enum V_15 V_526 ;
V_526 = F_120 ( V_6 , V_17 ,
& V_576 ) ;
* V_412 = 0 ;
if ( V_526 != V_19 )
return V_526 ;
if ( V_575 < V_576 )
return V_577 ;
F_37 ( V_6 , V_17 ) ;
* V_412 = F_100 ( V_6 , V_17 , V_44 , true ) ;
F_17 ( V_6 ) ;
return V_19 ;
}
enum V_15 F_122 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_573 )
{
enum V_15 V_526 = F_18 ( V_6 , V_17 ) ;
* V_573 = 0 ;
if ( V_526 != V_19 )
return V_526 ;
return F_109 ( V_6 , V_17 , NULL , false , V_573 ) ;
}
enum V_15 F_123 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_44 ,
T_1 V_575 ,
T_1 * V_412 )
{
T_1 V_576 ;
enum V_15 V_526 ;
V_526 =
F_122 ( V_6 , V_17 ,
& V_576 ) ;
if ( V_526 != V_19 &&
V_526 != V_493 )
return V_526 ;
if ( V_575 < V_576 )
return V_577 ;
F_37 ( V_6 , V_17 ) ;
V_526 = F_109 ( V_6 ,
V_17 , V_44 , true , V_412 ) ;
F_17 ( V_6 ) ;
return V_526 ;
}
enum V_15 F_124 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_573 )
{
enum V_15 V_526 = F_18 ( V_6 , V_17 ) ;
* V_573 = 0 ;
if ( V_526 != V_19 )
return V_526 ;
return F_111 ( V_6 , V_17 , NULL , false , V_573 ) ;
}
enum V_15 F_125 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_44 ,
T_1 V_575 ,
T_1 * V_412 )
{
T_1 V_576 ;
enum V_15 V_526 ;
V_526 = F_124 ( V_6 , V_17 ,
& V_576 ) ;
* V_412 = 0 ;
if ( V_526 != V_19 )
return V_526 ;
if ( V_575 < V_576 )
return V_577 ;
F_37 ( V_6 , V_17 ) ;
V_526 = F_111 ( V_6 ,
V_17 , V_44 , true , V_412 ) ;
F_17 ( V_6 ) ;
return V_526 ;
}
enum V_15 F_126 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_573 )
{
enum V_15 V_526 = F_18 ( V_6 , V_17 ) ;
* V_573 = 0 ;
if ( V_526 != V_19 )
return V_526 ;
return F_113 ( V_6 , V_17 , NULL , false , V_573 ) ;
}
enum V_15 F_127 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_44 ,
T_1 V_575 ,
T_1 * V_412 )
{
T_1 V_576 ;
enum V_15 V_526 ;
V_526 = F_126 ( V_6 , V_17 ,
& V_576 ) ;
* V_412 = 0 ;
if ( V_526 != V_19 )
return V_526 ;
if ( V_575 < V_576 )
return V_577 ;
F_37 ( V_6 , V_17 ) ;
V_526 = F_113 ( V_6 ,
V_17 , V_44 , true , V_412 ) ;
F_17 ( V_6 ) ;
return V_526 ;
}
enum V_15
F_128 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_573 )
{
enum V_15 V_526 = F_18 ( V_6 , V_17 ) ;
* V_573 = 0 ;
if ( V_526 != V_19 )
return V_526 ;
return F_114 ( V_6 ,
V_17 , NULL , false , V_573 ) ;
}
enum V_15 F_129 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_44 ,
T_1 V_575 ,
T_1 * V_412 )
{
T_1 V_576 ;
enum V_15 V_526 ;
V_526 = F_128 ( V_6 , V_17 ,
& V_576 ) ;
* V_412 = 0 ;
if ( V_526 != V_19 )
return V_526 ;
if ( V_575 < V_576 )
return V_577 ;
F_37 ( V_6 , V_17 ) ;
V_526 = F_114 ( V_6 ,
V_17 ,
V_44 ,
true , V_412 ) ;
F_17 ( V_6 ) ;
return V_526 ;
}
enum V_15 F_130 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_573 )
{
enum V_15 V_526 = F_18 ( V_6 , V_17 ) ;
* V_573 = 0 ;
if ( V_526 != V_19 )
return V_526 ;
F_37 ( V_6 , V_17 ) ;
* V_573 = F_115 ( V_6 , V_17 , NULL , false ) ;
return V_19 ;
}
enum V_15 F_131 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_44 ,
T_1 V_575 ,
T_1 * V_412 )
{
T_1 V_576 ;
enum V_15 V_526 ;
V_526 = F_130 ( V_6 , V_17 ,
& V_576 ) ;
* V_412 = 0 ;
if ( V_526 != V_19 )
return V_526 ;
if ( V_575 < V_576 )
return V_577 ;
* V_412 = F_115 ( V_6 , V_17 , V_44 , true ) ;
return V_19 ;
}
enum V_15 F_132 ( const T_2 * const V_564 )
{
struct V_565 * V_566 = (struct V_565 * ) V_564 ;
T_2 V_567 ;
for ( V_567 = 0 ; V_567 < V_568 ; V_567 ++ ) {
V_118 [ V_567 ] . V_117 =
( T_1 * ) ( V_564 + V_566 [ V_567 ] . V_52 ) ;
V_118 [ V_567 ] . V_216 =
F_23 ( V_566 [ V_567 ] . V_569 ) ;
}
return V_19 ;
}
static T_1 F_133 ( T_1 V_580 , T_1 V_581 , T_1 V_42 )
{
return ( V_580 + V_581 ) % V_42 ;
}
static T_1 F_134 ( T_1 V_580 , T_1 V_581 , T_1 V_42 )
{
return ( V_42 + V_580 - V_581 ) % V_42 ;
}
static T_1 F_135 ( void * V_3 ,
T_1 * V_52 ,
T_1 V_573 , T_2 V_582 )
{
T_2 * V_388 = ( T_2 * ) V_3 ;
T_2 * V_583 ;
T_1 V_584 = 0 ;
T_2 V_40 ;
V_583 = ( T_2 * ) & V_584 ;
for ( V_40 = 0 ; V_40 < V_582 ; V_40 ++ ) {
V_583 [ V_40 ] = V_388 [ * V_52 ] ;
* V_52 = F_133 ( * V_52 , 1 , V_573 ) ;
}
return V_584 ;
}
static T_2 F_136 ( void * V_3 , T_1 * V_52 )
{
return ( ( T_2 * ) V_3 ) [ ( * V_52 ) ++ ] ;
}
static T_1 F_137 ( void * V_3 , T_1 * V_52 )
{
T_1 V_585 = * ( T_1 * ) & ( ( T_2 * ) V_3 ) [ * V_52 ] ;
* V_52 += 4 ;
return V_585 ;
}
static void F_138 ( void * V_3 , T_1 * V_52 , T_1 V_42 , char * V_39 )
{
const char * V_586 = & ( ( const char * ) V_3 ) [ * V_52 ] ;
strncpy ( V_39 , V_586 , V_42 ) ;
V_39 [ V_42 - 1 ] = '\0' ;
* V_52 += V_42 ;
}
static char * F_139 ( void * V_3 , T_1 V_52 )
{
return V_3 ? ( char * ) V_3 + V_52 : V_587 ;
}
static T_1 F_140 ( T_1 * V_44 ,
const char * * V_50 ,
const char * * V_588 , T_1 * V_589 )
{
char * V_51 = ( char * ) V_44 ;
T_1 V_52 = 0 ;
* V_50 = V_51 ;
V_52 += strlen ( * V_50 ) + 1 ;
if ( * ( V_51 + V_52 ++ ) ) {
* V_588 = V_51 + V_52 ;
V_52 += strlen ( * V_588 ) + 1 ;
if ( V_52 & 0x3 )
V_52 += ( 4 - ( V_52 & 0x3 ) ) ;
} else {
* V_588 = NULL ;
if ( V_52 & 0x3 )
V_52 += ( 4 - ( V_52 & 0x3 ) ) ;
* V_589 = * ( T_1 * ) ( V_51 + V_52 ) ;
V_52 += 4 ;
}
return V_52 / 4 ;
}
static T_1 F_141 ( T_1 * V_44 ,
const char * * V_590 ,
T_1 * V_591 )
{
const char * V_588 ;
return F_140 ( V_44 ,
V_590 , & V_588 , V_591 ) ;
}
static T_1 F_142 ( T_1 * V_44 ,
T_1 V_591 ,
char * V_592 , T_1 * V_593 )
{
T_1 V_40 , V_594 = 0 , V_595 = 0 ;
for ( V_40 = 0 ; V_40 < V_591 ; V_40 ++ ) {
const char * V_50 ;
const char * V_588 ;
T_1 V_589 = 0 ;
V_594 += F_140 ( V_44 + V_594 ,
& V_50 ,
& V_588 , & V_589 ) ;
if ( V_588 )
V_595 +=
sprintf ( F_139 ( V_592 ,
V_595 ) ,
L_84 , V_50 , V_588 ) ;
else if ( strcmp ( V_50 , L_7 ) )
V_595 +=
sprintf ( F_139 ( V_592 ,
V_595 ) ,
L_85 , V_50 , V_589 ) ;
}
V_595 +=
sprintf ( F_139 ( V_592 , V_595 ) , L_86 ) ;
* V_593 = V_595 ;
return V_594 ;
}
const char * F_143 ( enum V_15 V_526 )
{
return ( V_526 <
V_596 ) ? V_597 [ V_526 ] : L_87 ;
}
static T_1 F_144 ( struct V_5 * V_6 ,
T_1 * V_44 ,
T_1 * V_598 ,
T_1 V_599 ,
bool V_600 ,
char * V_592 ,
T_1 * V_601 , T_1 * V_602 )
{
T_1 V_603 , V_595 = 0 ;
T_3 V_40 , V_604 ;
* V_601 = 0 ;
* V_602 = 0 ;
for ( V_603 = 0 ; V_603 < V_599 && V_44 < V_598 ;
V_603 ++ ) {
const struct V_605 * V_606 ;
struct V_440 * V_239 ;
const char * V_607 ;
T_1 V_608 ;
const char * V_609 ;
T_2 V_610 = 0 ;
bool V_611 ;
V_239 = (struct V_440 * ) V_44 ;
V_606 =
( const struct V_605 * )
& V_118 [ V_612 ] .
V_117 [ V_239 -> V_429 ] ;
V_608 =
F_54 ( V_606 -> V_195 ,
V_613 ) ;
V_611 =
F_54 ( V_606 -> V_195 ,
V_614 ) > 0 ;
V_607 = & ( ( const char * )
V_118 [ V_615 ] . V_117 )
[ V_608 ] ;
V_609 = V_607 ;
if ( V_239 -> V_448 >= V_616 )
return 0 ;
V_44 += ( sizeof( struct V_440 ) / 4 ) ;
if ( V_239 -> V_448 == V_617 ||
V_239 -> V_448 == V_618 )
( * V_601 ) ++ ;
else
( * V_602 ) ++ ;
V_595 +=
sprintf ( F_139 ( V_592 ,
V_595 ) , L_88 ,
V_619 [ V_239 -> V_448 ] ) ;
if ( V_611 )
V_607 += strlen ( V_607 ) + 1 ;
V_595 +=
sprintf ( F_139 ( V_592 ,
V_595 ) , L_89 ,
V_611 &&
V_600 ? V_607 : V_609 ) ;
V_607 += strlen ( V_607 ) + 1 ;
V_595 +=
sprintf ( F_139 ( V_592 ,
V_595 ) , L_90 ) ;
for ( V_40 = 0 ;
V_40 < V_239 -> V_449 + V_239 -> V_461 ;
V_40 ++ ) {
struct V_451 * V_452
= (struct V_451 * )
V_44 ;
bool V_620 =
F_54 ( V_452 -> V_195 ,
V_456 ) ;
T_2 V_446 =
F_54 ( V_452 -> V_195 ,
V_457 ) ;
V_44 +=
( sizeof( struct V_451 ) / 4 ) ;
for (; V_446 > V_610 ;
V_610 ++ ,
V_607 += strlen ( V_607 ) + 1 ) ;
V_595 +=
sprintf ( F_139 ( V_592 ,
V_595 ) , L_91 ,
V_607 ) ;
if ( V_40 < V_239 -> V_449 && V_620 )
V_595 +=
sprintf ( F_139 ( V_592 ,
V_595 ) ,
L_92 , V_239 -> V_447 +
V_452 -> V_454 ) ;
V_595 +=
sprintf ( F_139 ( V_592 ,
V_595 ) , L_93 ) ;
for ( V_604 = 0 ; V_604 < V_452 -> V_42 ; V_604 ++ , V_44 ++ ) {
V_595 +=
sprintf ( F_139 ( V_592 ,
V_595 ) ,
L_94 , * V_44 ) ;
if ( V_604 < V_452 -> V_42 - 1 )
V_595 +=
sprintf ( F_139
( V_592 ,
V_595 ) , L_95 ) ;
}
}
V_595 +=
sprintf ( F_139 ( V_592 , V_595 ) , L_86 ) ;
}
if ( V_44 > V_598 )
return 0 ;
return V_595 ;
}
static enum V_15 F_145 ( struct V_5 * V_6 ,
T_1 * V_44 ,
T_1 V_412 ,
char * V_592 ,
T_1 * V_621 ,
T_1 * V_601 ,
T_1 * V_602 )
{
const char * V_590 , * V_50 , * V_588 ;
T_1 * V_598 = V_44 + V_412 ;
T_1 V_591 = 0 , V_599 ;
T_1 V_595 = 0 ;
* V_621 = 0 ;
* V_601 = 0 ;
* V_602 = 0 ;
if ( ! V_118 [ V_615 ] . V_117 ||
! V_118 [ V_612 ] . V_117 )
return V_574 ;
V_44 += F_141 ( V_44 ,
& V_590 , & V_591 ) ;
if ( strcmp ( V_590 , L_10 ) )
return V_622 ;
V_44 += F_142 ( V_44 ,
V_591 ,
V_592 , & V_595 ) ;
V_44 += F_141 ( V_44 ,
& V_590 , & V_591 ) ;
if ( strcmp ( V_590 , L_66 ) || V_591 != 1 )
return V_622 ;
V_44 += F_140 ( V_44 ,
& V_50 , & V_588 , & V_599 ) ;
if ( strcmp ( V_50 , L_67 ) != 0 )
return V_622 ;
if ( V_599 ) {
T_1 V_623 ;
V_595 +=
sprintf ( F_139 ( V_592 ,
V_595 ) ,
L_96 ) ;
V_623 =
F_144 ( V_6 , V_44 ,
V_598 , V_599 ,
true ,
V_592 ?
V_592 +
V_595 : NULL ,
V_601 , V_602 ) ;
V_595 += V_623 ;
if ( V_623 == 0 )
return V_622 ;
V_595 +=
sprintf ( F_139 ( V_592 ,
V_595 ) ,
L_97 ) ;
V_623 =
F_144 ( V_6 , V_44 ,
V_598 , V_599 ,
false ,
V_592 ?
V_592 +
V_595 : NULL ,
V_601 , V_602 ) ;
V_595 += V_623 ;
if ( V_623 == 0 )
return V_622 ;
}
if ( * V_601 ) {
V_595 +=
sprintf ( F_139 ( V_592 ,
V_595 ) ,
L_98 ,
* V_601 , * V_602 ) ;
} else if ( * V_602 ) {
V_595 +=
sprintf ( F_139 ( V_592 ,
V_595 ) ,
L_99 ,
* V_602 ) ;
} else {
V_595 +=
sprintf ( F_139 ( V_592 ,
V_595 ) ,
L_100 ) ;
}
* V_621 = V_595 + 1 ;
return V_19 ;
}
enum V_15 F_146 ( struct V_5 * V_6 ,
T_1 * V_44 ,
T_1 V_412 ,
T_1 * V_624 )
{
T_1 V_601 , V_602 ;
return F_145 ( V_6 ,
V_44 ,
V_412 ,
NULL ,
V_624 ,
& V_601 , & V_602 ) ;
}
enum V_15 F_147 ( struct V_5 * V_6 ,
T_1 * V_44 ,
T_1 V_412 ,
char * V_592 ,
T_1 * V_601 , T_1 * V_602 )
{
T_1 V_625 ;
return F_145 ( V_6 ,
V_44 ,
V_412 ,
V_592 ,
& V_625 ,
V_601 , V_602 ) ;
}
static void F_148 ( struct V_5 * V_6 ,
struct V_626 * V_627 )
{
T_1 V_40 ;
if ( V_627 -> V_628 ) {
for ( V_40 = 0 ; V_40 < V_627 -> V_525 ; V_40 ++ )
F_149 ( V_627 -> V_628 [ V_40 ] ) ;
F_149 ( V_627 -> V_628 ) ;
}
if ( V_627 -> V_629 ) {
for ( V_40 = 0 ; V_40 < V_627 -> V_630 ; V_40 ++ )
F_149 ( V_627 -> V_629 [ V_40 ] . V_631 ) ;
F_149 ( V_627 -> V_629 ) ;
}
}
static enum V_15 F_150 ( struct V_5 * V_6 ,
const T_1 * V_632 ,
struct V_626 * V_627 )
{
T_2 * V_633 = ( T_2 * ) V_632 ;
T_1 V_52 = 0 , V_509 , V_40 ;
memset ( V_627 , 0 , sizeof( * V_627 ) ) ;
V_509 = F_137 ( V_633 , & V_52 ) ;
if ( V_509 != V_527 )
return V_512 ;
V_627 -> V_525 = F_136 ( V_633 , & V_52 ) ;
V_627 -> V_628 = F_151 ( V_627 -> V_525 * sizeof( char * ) , V_634 ) ;
if ( ! V_627 -> V_628 )
return V_635 ;
for ( V_40 = 0 ; V_40 < V_627 -> V_525 ; V_40 ++ ) {
T_2 V_528 = F_136 ( V_633 , & V_52 ) ;
* ( V_627 -> V_628 + V_40 ) = F_151 ( V_528 , V_634 ) ;
if ( ! ( * ( V_627 -> V_628 + V_40 ) ) ) {
V_627 -> V_525 = V_40 ? V_40 - 1 : 0 ;
return V_635 ;
}
F_138 ( V_633 , & V_52 , V_528 ,
* ( V_627 -> V_628 + V_40 ) ) ;
if ( V_528 > V_636 )
( * ( V_627 -> V_628 + V_40 ) ) [ V_636 ] = '\0' ;
}
V_509 = F_137 ( V_633 , & V_52 ) ;
if ( V_509 != V_527 )
return V_512 ;
V_627 -> V_630 = F_137 ( V_633 , & V_52 ) ;
V_627 -> V_629 = F_151 ( V_627 -> V_630 *
sizeof( struct V_637 ) ,
V_634 ) ;
if ( ! V_627 -> V_629 )
return V_635 ;
for ( V_40 = 0 ; V_40 < V_627 -> V_630 ; V_40 ++ ) {
struct V_637 * V_638 = & V_627 -> V_629 [ V_40 ] ;
T_2 V_639 ;
V_638 -> V_195 = F_137 ( V_633 ,
& V_52 ) ;
V_639 =
( V_638 -> V_195 &
V_640 ) >> V_641 ;
V_638 -> V_631 = F_151 ( V_639 , V_634 ) ;
if ( ! V_638 -> V_631 ) {
V_627 -> V_630 = V_40 ? V_40 - 1 : 0 ;
return V_635 ;
}
F_138 ( V_633 ,
& V_52 ,
V_639 , V_638 -> V_631 ) ;
}
return V_19 ;
}
static enum V_15 F_152 ( struct V_5 * V_6 ,
T_1 * V_44 ,
T_1 V_412 ,
char * V_592 ,
T_1 * V_621 )
{
T_1 V_595 = 0 , V_642 , V_643 , V_589 ;
T_1 V_591 , V_52 , V_644 , V_500 ;
const char * V_590 , * V_50 , * V_588 ;
T_1 V_645 , V_646 ;
struct V_626 V_627 ;
struct V_510 * V_647 ;
enum V_15 V_526 ;
const T_1 * V_632 ;
T_2 * V_648 ;
* V_621 = 0 ;
V_44 += F_141 ( V_44 ,
& V_590 , & V_591 ) ;
if ( strcmp ( V_590 , L_10 ) )
return V_649 ;
V_44 += F_142 ( V_44 ,
V_591 ,
V_592 , & V_595 ) ;
V_44 += F_141 ( V_44 ,
& V_590 , & V_591 ) ;
if ( strcmp ( V_590 , L_71 ) || V_591 != 1 )
return V_649 ;
V_44 += F_140 ( V_44 ,
& V_50 , & V_588 , & V_589 ) ;
if ( strcmp ( V_50 , L_72 ) )
return V_649 ;
V_645 = V_589 ;
V_647 = (struct V_510 * ) V_44 ;
V_648 = ( T_2 * ) V_44 + sizeof( struct V_510 ) ;
V_52 = V_647 -> V_650 ;
V_644 = V_647 -> V_651 ;
V_500 = F_134 ( V_644 , V_52 , V_647 -> V_42 ) ;
V_44 += V_645 ;
V_44 += F_141 ( V_44 ,
& V_590 , & V_591 ) ;
if ( strcmp ( V_590 , L_73 ) )
return V_649 ;
V_44 += F_140 ( V_44 ,
& V_50 , & V_588 , & V_589 ) ;
if ( strcmp ( V_50 , L_72 ) != 0 )
return V_649 ;
V_646 = V_589 ;
if ( ! V_646 ) {
if ( ! V_652 . V_117 )
return V_653 ;
V_632 = V_652 . V_117 ;
} else {
V_632 = V_44 ;
}
V_526 = F_150 ( V_6 , V_632 , & V_627 ) ;
if ( V_526 != V_19 )
goto V_654;
while ( V_500 ) {
struct V_637 * V_638 ;
T_2 V_655 , V_656 ;
T_1 V_657 [ 3 ] = { 0 , 0 , 0 } ;
T_1 V_658 , V_659 , V_40 ;
if ( V_500 < V_660 ) {
V_526 = V_649 ;
goto V_654;
}
V_658 = F_135 ( V_648 ,
& V_52 ,
V_647 -> V_42 ,
V_660 ) ;
V_500 -= V_660 ;
V_659 = V_658 & V_661 ;
if ( V_659 > V_627 . V_630 ) {
T_2 V_662 =
( T_2 ) ( ( V_658 &
V_663 ) >>
V_664 ) ;
if ( V_500 < V_662 ) {
V_526 = V_649 ;
goto V_654;
}
V_52 = F_133 ( V_52 ,
V_662 , V_647 -> V_42 ) ;
V_500 -= V_662 ;
continue;
}
V_638 = & V_627 . V_629 [ V_659 ] ;
for ( V_40 = 0 ,
V_642 = V_665 , V_643 =
V_666 ;
V_40 < V_667 ;
V_40 ++ , V_642 <<= V_668 ,
V_643 += V_668 ) {
T_2 V_669 =
( T_2 ) ( ( V_638 -> V_195 &
V_642 ) >> V_643 ) ;
if ( ! V_669 )
break;
if ( V_669 == 3 )
V_669 = 4 ;
if ( V_500 < V_669 ) {
V_526 = V_649 ;
goto V_654;
}
V_657 [ V_40 ] = F_135 ( V_648 ,
& V_52 ,
V_647 -> V_42 ,
V_669 ) ;
V_500 -= V_669 ;
}
V_655 =
( T_2 ) ( ( V_638 -> V_195 &
V_670 ) >>
V_671 ) ;
V_656 =
( T_2 ) ( ( V_638 -> V_195 &
V_672 ) >>
V_673 ) ;
if ( V_655 >= F_90 ( V_674 ) ) {
V_526 = V_649 ;
goto V_654;
}
V_595 +=
sprintf ( F_139 ( V_592 ,
V_595 ) , L_101 ,
V_674 [ V_655 ] ,
V_627 . V_628 [ V_656 ] ) ;
V_595 +=
sprintf ( F_139 ( V_592 ,
V_595 ) ,
V_638 -> V_631 , V_657 [ 0 ] , V_657 [ 1 ] ,
V_657 [ 2 ] ) ;
}
V_654:
* V_621 = V_595 + 1 ;
F_148 ( V_6 , & V_627 ) ;
return V_526 ;
}
enum V_15 F_153 ( struct V_5 * V_6 ,
T_1 * V_44 ,
T_1 V_412 ,
T_1 * V_624 )
{
return F_152 ( V_6 ,
V_44 ,
V_412 ,
NULL , V_624 ) ;
}
enum V_15 F_154 ( struct V_5 * V_6 ,
T_1 * V_44 ,
T_1 V_412 ,
char * V_592 )
{
T_1 V_625 ;
return F_152 ( V_6 ,
V_44 ,
V_412 ,
V_592 , & V_625 ) ;
}
static enum V_15 F_155 ( struct V_5 * V_6 ,
T_1 * V_44 ,
T_1 V_412 ,
char * V_592 ,
T_1 * V_621 )
{
T_1 V_595 = 0 , V_589 , V_591 , V_675 ;
const char * V_590 , * V_50 , * V_588 ;
struct V_676 * V_677 ;
T_2 V_40 , V_604 , V_678 , V_679 ;
char V_680 [ 4 ] ;
V_44 += F_141 ( V_44 ,
& V_590 , & V_591 ) ;
if ( strcmp ( V_590 , L_10 ) )
return V_681 ;
V_44 += F_142 ( V_44 ,
V_591 ,
V_592 , & V_595 ) ;
V_44 += F_141 ( V_44 ,
& V_590 , & V_591 ) ;
if ( strcmp ( V_590 , L_75 ) )
return V_681 ;
V_44 += F_140 ( V_44 ,
& V_50 , & V_588 , & V_589 ) ;
if ( strcmp ( V_50 , L_72 ) )
return V_681 ;
if ( V_589 % V_537 )
return V_681 ;
V_675 = V_589 / V_537 ;
V_677 = (struct V_676 * ) V_44 ;
for ( V_40 = 0 ; V_40 < V_675 ; V_40 ++ ) {
bool V_682 = false ;
V_679 = F_54 ( V_677 [ V_40 ] . V_195 , V_683 ) ;
if ( V_679 == V_684 )
sprintf ( V_680 , L_102 , L_103 ) ;
else
sprintf ( V_680 , L_104 , V_679 ) ;
V_595 +=
sprintf ( F_139 ( V_592 ,
V_595 ) ,
L_105 ,
V_677 [ V_40 ] . V_195 ,
( T_1 ) F_54 ( V_677 [ V_40 ] . V_195 ,
V_685 ) *
V_686 ,
V_687 [ F_54 ( V_677 [ V_40 ] . V_195 ,
V_688 ) ] ,
( T_1 ) F_54 ( V_677 [ V_40 ] . V_195 ,
V_689 ) , V_680 ,
( T_1 ) F_54 ( V_677 [ V_40 ] . V_195 ,
V_690 ) ,
V_691 [ F_54 ( V_677 [ V_40 ] .
V_195 ,
V_692 ) ] ,
V_693 [ F_54 ( V_677 [ V_40 ] . V_195 ,
V_694 ) ] ,
V_695 [ F_54 ( V_677 [ V_40 ] . V_195 ,
V_696 ) ] ) ;
for ( V_604 = 0 ,
V_678 = F_54 ( V_677 [ V_40 ] . V_195 ,
V_697 ) ;
V_604 < F_90 ( V_698 ) ;
V_604 ++ , V_678 >>= 1 ) {
if ( ! ( V_678 & 0x1 ) )
continue;
if ( V_682 )
V_595 +=
sprintf ( F_139 ( V_592 ,
V_595 ) ,
L_106 ) ;
V_595 +=
sprintf ( F_139 ( V_592 ,
V_595 ) , L_102 ,
V_698 [ V_604 ] ) ;
V_682 = true ;
}
V_595 +=
sprintf ( F_139 ( V_592 , V_595 ) , L_86 ) ;
}
V_595 += sprintf ( F_139 ( V_592 ,
V_595 ) ,
L_107 , V_675 ) ;
* V_621 = V_595 + 1 ;
return V_19 ;
}
enum V_15 F_156 ( struct V_5 * V_6 ,
T_1 * V_44 ,
T_1 V_412 ,
T_1 * V_624 )
{
return F_155 ( V_6 ,
V_44 ,
V_412 ,
NULL , V_624 ) ;
}
enum V_15 F_157 ( struct V_5 * V_6 ,
T_1 * V_44 ,
T_1 V_412 ,
char * V_592 )
{
T_1 V_625 ;
return F_155 ( V_6 ,
V_44 ,
V_412 ,
V_592 , & V_625 ) ;
}
static enum V_15 F_158 ( struct V_5 * V_6 ,
T_1 * V_44 ,
T_1 V_412 ,
char * V_592 ,
T_1 * V_621 )
{
T_1 V_595 = 0 , V_589 , V_591 , V_675 ;
const char * V_590 , * V_50 , * V_588 ;
struct V_699 * V_677 ;
char V_700 [ 32 ] ;
char V_701 [ 256 ] ;
T_2 V_40 , V_604 ;
V_44 += F_141 ( V_44 ,
& V_590 , & V_591 ) ;
if ( strcmp ( V_590 , L_10 ) )
return V_702 ;
V_44 += F_142 ( V_44 ,
V_591 ,
V_592 , & V_595 ) ;
V_44 += F_141 ( V_44 ,
& V_590 , & V_591 ) ;
if ( strcmp ( V_590 , L_77 ) )
return V_702 ;
V_44 += F_140 ( V_44 ,
& V_50 , & V_588 , & V_589 ) ;
if ( strcmp ( V_50 , L_72 ) )
return V_702 ;
if ( V_589 % V_544 )
return V_702 ;
V_675 = V_589 / V_544 ;
V_677 = (struct V_699 * ) V_44 ;
for ( V_40 = 0 ; V_40 < V_675 ; V_40 ++ ) {
V_539 V_703 =
( ( V_539 ) V_677 [ V_40 ] . V_704 << 32 ) | V_677 [ V_40 ] . V_282 ;
bool V_705 = F_54 ( V_703 ,
V_706 ) ;
bool V_707 = F_54 ( V_677 [ V_40 ] . V_276 ,
V_708 ) ;
T_3 V_709 = F_54 ( V_677 [ V_40 ] . V_276 ,
V_710 ) ;
T_2 V_711 = F_54 ( V_677 [ V_40 ] . V_276 ,
V_712 ) ;
T_2 V_713 = F_54 ( V_677 [ V_40 ] . V_276 ,
V_714 ) ;
const struct V_715 * V_716 = NULL ;
if ( V_711 >= F_90 ( V_717 ) )
return V_702 ;
if ( V_713 >= F_90 ( V_718 ) )
return V_702 ;
for ( V_604 = 0 ; V_604 < F_90 ( V_719 ) && ! V_716 ;
V_604 ++ )
if ( V_709 >= V_719 [ V_604 ] . V_720 &&
V_709 <= V_719 [ V_604 ] . V_721 )
V_716 = & V_719 [ V_604 ] ;
if ( ! V_716 )
return V_702 ;
switch ( V_716 -> type ) {
case V_722 :
sprintf ( V_700 ,
L_108 , V_709 / 2 ) ;
break;
case V_723 :
case V_724 :
sprintf ( V_700 ,
L_109 , V_709 - V_716 -> V_720 ) ;
break;
default:
V_700 [ 0 ] = '\0' ;
}
if ( V_705 ) {
T_1 V_725 = F_54 ( V_703 ,
V_726 ) ;
T_1 V_727 = F_54 ( V_725 ,
V_728 ) ;
T_2 V_729 = F_54 ( V_725 ,
V_730 ) ;
if ( V_711 == V_731 ) {
sprintf ( V_701 ,
L_110 , V_727 ) ;
} else {
if ( V_729 ) {
T_2 V_732 = F_54 ( V_725 ,
V_733 ) ;
T_2 V_734 = F_54 ( V_725 ,
V_735 ) ;
sprintf ( V_701 ,
L_111 ,
V_732 ? L_112 : L_113 ,
V_734 ) ;
} else {
T_2 V_736 = F_54 ( V_725 ,
V_737 ) ;
T_2 V_738 =
F_54 ( V_725 ,
V_739 ) ;
T_2 V_740 = F_54 ( V_725 ,
V_741 ) ;
T_2 V_742 = F_54 ( V_725 ,
V_743 ) ;
sprintf ( V_701 ,
L_114 ,
V_727 ,
V_736 ? L_115 : L_116 ,
V_738
? ( V_738 ==
1 ? L_117 : L_116 ) :
L_118 ,
V_740 ? L_119 : L_120 ,
V_742 ) ;
}
}
} else {
V_701 [ 0 ] = '\0' ;
}
V_595 +=
sprintf ( F_139 ( V_592 ,
V_595 ) ,
L_121 ,
V_677 [ V_40 ] . V_704 , V_677 [ V_40 ] . V_282 ,
V_677 [ V_40 ] . V_276 ,
V_707 ? L_23 : L_24 ,
F_54 ( V_677 [ V_40 ] . V_276 ,
V_744 ) ,
V_717 [ V_711 ] ,
V_705 ? L_122 : L_123 , V_709 ,
( ! V_707 && V_716 -> V_745 )
? V_716 -> V_745 : V_716 -> V_746 ,
V_700 , V_701 ,
V_718 [ V_713 ] ) ;
}
V_595 += sprintf ( F_139 ( V_592 ,
V_595 ) ,
L_107 , V_675 ) ;
* V_621 = V_595 + 1 ;
return V_19 ;
}
enum V_15 F_159 ( struct V_5 * V_6 ,
T_1 * V_44 ,
T_1 V_412 ,
T_1 * V_624 )
{
return F_158 ( V_6 ,
V_44 ,
V_412 ,
NULL , V_624 ) ;
}
enum V_15 F_160 ( struct V_5 * V_6 ,
T_1 * V_44 ,
T_1 V_412 ,
char * V_592 )
{
T_1 V_625 ;
return F_158 ( V_6 ,
V_44 ,
V_412 ,
V_592 , & V_625 ) ;
}
static enum V_15
F_161 ( struct V_5 * V_6 ,
T_1 * V_44 ,
T_1 V_412 ,
char * V_592 ,
T_1 * V_621 )
{
T_1 V_595 = 0 , V_589 , V_591 , V_675 ;
const char * V_590 , * V_50 , * V_588 ;
struct V_747 * V_677 ;
T_2 V_40 ;
V_44 += F_141 ( V_44 ,
& V_590 , & V_591 ) ;
if ( strcmp ( V_590 , L_10 ) )
return V_748 ;
V_44 += F_142 ( V_44 ,
V_591 ,
V_592 , & V_595 ) ;
V_44 += F_141 ( V_44 ,
& V_590 , & V_591 ) ;
if ( strcmp ( V_590 , L_79 ) )
return V_748 ;
V_44 += F_140 ( V_44 ,
& V_50 , & V_588 , & V_589 ) ;
if ( strcmp ( V_50 , L_72 ) )
return V_748 ;
if ( V_589 % V_549 != 0 )
return V_748 ;
V_675 = V_589 / V_549 ;
V_677 = (struct V_747 * ) V_44 ;
for ( V_40 = 0 ; V_40 < V_675 ; V_40 ++ ) {
T_1 V_749 = F_54 ( V_677 [ V_40 ] . V_195 ,
V_750 ) *
V_751 ;
V_595 +=
sprintf ( F_139 ( V_592 ,
V_595 ) ,
L_124 ,
V_40 , V_749 ,
( T_1 ) F_54 ( V_677 [ V_40 ] . V_195 ,
V_752 ) ,
( T_1 ) F_54 ( V_677 [ V_40 ] . V_195 ,
V_753 ) ,
( T_1 ) F_54 ( V_677 [ V_40 ] . V_195 ,
V_754 ) ,
V_693 [ F_54 ( V_677 [ V_40 ] . V_195 ,
V_755 ) ] ,
V_693 [ F_54 ( V_677 [ V_40 ] . V_195 ,
V_756 ) ] ) ;
}
V_595 += sprintf ( F_139 ( V_592 ,
V_595 ) ,
L_125 ,
V_675 ) ;
* V_621 = V_595 + 1 ;
return V_19 ;
}
enum V_15
F_162 ( struct V_5 * V_6 ,
T_1 * V_44 ,
T_1 V_412 ,
T_1 * V_624 )
{
return F_161 ( V_6 ,
V_44 ,
V_412 ,
NULL , V_624 ) ;
}
enum V_15 F_163 ( struct V_5 * V_6 ,
T_1 * V_44 ,
T_1 V_412 ,
char * V_592 )
{
T_1 V_625 ;
return F_161 ( V_6 ,
V_44 ,
V_412 ,
V_592 ,
& V_625 ) ;
}
static enum V_15 F_164 ( struct V_5 * V_6 ,
T_1 * V_44 ,
T_1 V_412 ,
char * V_592 ,
T_1 * V_621 )
{
T_1 V_595 = 0 , V_591 , V_589 , V_40 ;
const char * V_50 , * V_588 , * V_590 ;
bool V_757 = false ;
* V_621 = 0 ;
V_44 += F_141 ( V_44 ,
& V_590 , & V_591 ) ;
if ( strcmp ( V_590 , L_10 ) )
return V_758 ;
V_44 += F_142 ( V_44 ,
V_591 ,
V_592 , & V_595 ) ;
while ( ! V_757 ) {
const char * V_270 = NULL ;
T_1 V_759 = 0 ;
V_44 += F_141 ( V_44 ,
& V_590 ,
& V_591 ) ;
if ( ! strcmp ( V_590 , L_15 ) ) {
V_757 = true ;
continue;
} else if ( strcmp ( V_590 , L_82 ) ) {
return V_758 ;
}
for ( V_40 = 0 ; V_40 < V_591 ; V_40 ++ ) {
V_44 += F_140 ( V_44 ,
& V_50 ,
& V_588 ,
& V_589 ) ;
if ( ! strcmp ( V_50 , L_83 ) )
V_270 = V_588 ;
else if ( ! strcmp ( V_50 , L_72 ) )
V_759 = V_589 ;
else
return V_758 ;
}
if ( ! V_270 || ! V_759 )
return V_758 ;
V_595 += sprintf ( F_139 ( V_592 ,
V_595 ) ,
L_126 ,
V_270 , V_759 ) ;
for ( V_40 = 0 ; V_40 < V_759 ; V_40 ++ , V_44 ++ )
V_595 +=
sprintf ( F_139 ( V_592 ,
V_595 ) ,
L_127 , * V_44 ) ;
}
* V_621 = V_595 + 1 ;
return V_19 ;
}
enum V_15 F_165 ( struct V_5 * V_6 ,
T_1 * V_44 ,
T_1 V_412 ,
T_1 * V_624 )
{
return F_164 ( V_6 ,
V_44 ,
V_412 ,
NULL , V_624 ) ;
}
enum V_15 F_166 ( struct V_5 * V_6 ,
T_1 * V_44 ,
T_1 V_412 ,
char * V_592 )
{
T_1 V_625 ;
return F_164 ( V_6 ,
V_44 ,
V_412 ,
V_592 , & V_625 ) ;
}
static enum V_15
F_167 ( struct V_5 * V_6 ,
T_1 * V_44 ,
T_1 V_412 ,
char * V_592 )
{
T_1 V_601 , V_760 ;
return F_147 ( V_6 , V_44 , V_412 ,
V_592 , & V_601 ,
& V_760 ) ;
}
static void F_168 ( T_2 * V_761 , T_1 V_762 )
{
T_1 V_40 , V_763 = 80 ;
if ( ! V_761 )
return;
F_169 ( L_128 , V_763 , V_761 ) ;
for ( V_40 = V_763 ; V_40 < V_762 ; V_40 += V_763 )
F_170 ( L_129 , V_763 , V_761 + V_40 ) ;
F_170 ( L_86 ) ;
}
static enum V_15 F_171 ( struct V_5 * V_6 ,
enum V_764 V_765 )
{
struct V_766 * V_767 =
& V_6 -> V_20 -> V_768 . V_769 [ V_765 ] ;
T_1 V_770 , V_771 , V_40 ;
enum V_15 V_772 ;
char * V_773 ;
if ( ! V_774 [ V_765 ] . V_624 )
return V_19 ;
V_772 = V_774 [ V_765 ] .
V_624 ( V_6 , ( T_1 * ) V_767 -> V_44 ,
V_767 -> V_775 , & V_770 ) ;
if ( V_772 != V_19 )
return V_772 ;
V_771 = V_770 - 1 ;
V_770 = ( V_770 + 3 ) & ~ 0x3 ;
if ( V_770 < V_776 ) {
F_30 ( V_6 -> V_20 ,
L_130 ,
V_770 ) ;
return V_777 ;
}
V_773 = F_172 ( V_770 ) ;
if ( ! V_773 )
return V_635 ;
V_772 = V_774 [ V_765 ] .
F_173 ( V_6 , ( T_1 * ) V_767 -> V_44 ,
V_767 -> V_775 , V_773 ) ;
if ( V_772 != V_19 ) {
F_174 ( V_773 ) ;
return V_772 ;
}
for ( V_40 = V_771 ; V_40 < V_770 ; V_40 ++ )
V_773 [ V_40 ] = '\n' ;
if ( V_6 -> V_20 -> V_768 . V_778 )
F_168 ( V_773 , V_770 ) ;
F_174 ( V_767 -> V_44 ) ;
V_767 -> V_44 = V_773 ;
V_767 -> V_573 = V_770 ;
V_767 -> V_775 = V_770 / 4 ;
return V_772 ;
}
static enum V_15 F_175 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
enum V_764 V_765 )
{
struct V_766 * V_767 =
& V_6 -> V_20 -> V_768 . V_769 [ V_765 ] ;
T_1 V_779 ;
enum V_15 V_772 ;
F_30 ( V_6 -> V_20 , L_131 ,
V_774 [ V_765 ] . V_86 ) ;
if ( V_767 -> V_44 ) {
F_174 ( V_767 -> V_44 ) ;
V_767 -> V_44 = NULL ;
}
V_772 = V_774 [ V_765 ] . F_176 ( V_6 , V_17 ,
& V_779 ) ;
if ( V_772 != V_19 && V_772 != V_493 )
return V_772 ;
V_767 -> V_573 = V_779 * sizeof( T_1 ) ;
V_767 -> V_44 = F_177 ( V_767 -> V_573 ) ;
if ( ! V_767 -> V_44 )
return V_635 ;
V_772 = V_774 [ V_765 ] .
F_178 ( V_6 , V_17 , ( T_1 * ) V_767 -> V_44 ,
V_767 -> V_573 / sizeof( T_1 ) ,
& V_767 -> V_775 ) ;
if ( V_772 == V_493 )
return V_19 ;
if ( V_772 != V_19 )
return V_772 ;
V_772 = F_171 ( V_6 , V_765 ) ;
return V_772 ;
}
int F_179 ( struct V_780 * V_20 , void * V_781 , T_1 * V_782 )
{
return V_766 ( V_20 , V_781 , V_783 , V_782 ) ;
}
int F_180 ( struct V_780 * V_20 )
{
return F_181 ( V_20 , V_783 ) ;
}
int F_182 ( struct V_780 * V_20 , void * V_781 , T_1 * V_782 )
{
return V_766 ( V_20 , V_781 , V_784 ,
V_782 ) ;
}
int F_183 ( struct V_780 * V_20 )
{
return F_181 ( V_20 , V_784 ) ;
}
int F_184 ( struct V_780 * V_20 , void * V_781 , T_1 * V_782 )
{
return V_766 ( V_20 , V_781 , V_785 ,
V_782 ) ;
}
int F_185 ( struct V_780 * V_20 )
{
return F_181 ( V_20 , V_785 ) ;
}
int F_186 ( struct V_780 * V_20 , void * V_781 , T_1 * V_782 )
{
return V_766 ( V_20 , V_781 , V_786 ,
V_782 ) ;
}
int F_187 ( struct V_780 * V_20 )
{
return F_181 ( V_20 , V_786 ) ;
}
int F_188 ( struct V_780 * V_20 , void * V_781 ,
T_1 * V_782 )
{
return V_766 ( V_20 , V_781 , V_787 ,
V_782 ) ;
}
int F_189 ( struct V_780 * V_20 )
{
return F_181 ( V_20 , V_787 ) ;
}
int F_190 ( struct V_780 * V_20 , void * V_781 ,
T_1 * V_782 )
{
return V_766 ( V_20 , V_781 , V_788 ,
V_782 ) ;
}
int F_191 ( struct V_780 * V_20 )
{
return F_181 ( V_20 , V_788 ) ;
}
int F_192 ( struct V_780 * V_20 , void * V_781 ,
T_1 * V_782 )
{
return V_766 ( V_20 , V_781 , V_789 ,
V_782 ) ;
}
int F_193 ( struct V_780 * V_20 )
{
return F_181 ( V_20 , V_789 ) ;
}
static T_1 F_194 ( enum V_790 V_767 ,
int V_791 , T_1 V_792 , T_2 V_793 )
{
return V_792 | ( V_767 << V_794 ) |
( V_793 << V_795 ) |
( V_791 << V_796 ) ;
}
int F_195 ( struct V_780 * V_20 , void * V_781 )
{
T_2 V_797 , V_793 = 0 , V_798 ;
T_1 V_52 = 0 , V_792 ;
int V_772 ;
if ( V_20 -> V_799 == 1 )
V_793 = 1 ;
V_798 = F_196 ( V_20 ) ;
for ( V_797 = 0 ; V_797 < V_20 -> V_799 ; V_797 ++ ) {
F_64 ( V_20 , V_234 ,
L_132 ) ;
F_197 ( V_20 , V_797 ) ;
V_772 = F_182 ( V_20 , ( T_2 * ) V_781 + V_52 +
V_800 , & V_792 ) ;
if ( ! V_772 ) {
* ( T_1 * ) ( ( T_2 * ) V_781 + V_52 ) =
F_194 ( V_801 , V_797 ,
V_792 , V_793 ) ;
V_52 += ( V_792 + V_800 ) ;
} else {
F_198 ( V_20 , L_133 , V_772 ) ;
}
V_772 = F_182 ( V_20 , ( T_2 * ) V_781 + V_52 +
V_800 , & V_792 ) ;
if ( ! V_772 ) {
* ( T_1 * ) ( ( T_2 * ) V_781 + V_52 ) =
F_194 ( V_801 , V_797 ,
V_792 , V_793 ) ;
V_52 += ( V_792 + V_800 ) ;
} else {
F_198 ( V_20 , L_133 , V_772 ) ;
}
V_772 = F_184 ( V_20 , ( T_2 * ) V_781 + V_52 +
V_800 , & V_792 ) ;
if ( ! V_772 ) {
* ( T_1 * ) ( ( T_2 * ) V_781 + V_52 ) =
F_194 ( V_802 , V_797 ,
V_792 , V_793 ) ;
V_52 += ( V_792 + V_800 ) ;
} else {
F_198 ( V_20 , L_134 , V_772 ) ;
}
V_772 = F_186 ( V_20 , ( T_2 * ) V_781 + V_52 +
V_800 , & V_792 ) ;
if ( ! V_772 ) {
* ( T_1 * ) ( ( T_2 * ) V_781 + V_52 ) =
F_194 ( V_803 , V_797 ,
V_792 , V_793 ) ;
V_52 += ( V_792 + V_800 ) ;
} else {
F_198 ( V_20 , L_135 , V_772 ) ;
}
V_772 = F_188 ( V_20 , ( T_2 * ) V_781 + V_52 +
V_800 ,
& V_792 ) ;
if ( ! V_772 ) {
* ( T_1 * ) ( ( T_2 * ) V_781 + V_52 ) =
F_194 ( V_804 ,
V_797 ,
V_792 , V_793 ) ;
V_52 += ( V_792 + V_800 ) ;
} else {
F_198 ( V_20 ,
L_136 ,
V_772 ) ;
}
V_772 = F_190 ( V_20 , ( T_2 * ) V_781 + V_52 +
V_800 , & V_792 ) ;
if ( ! V_772 ) {
* ( T_1 * ) ( ( T_2 * ) V_781 + V_52 ) =
F_194 ( V_805 , V_797 ,
V_792 , V_793 ) ;
V_52 += ( V_792 + V_800 ) ;
} else {
F_198 ( V_20 , L_137 ,
V_772 ) ;
}
V_772 = F_179 ( V_20 , ( T_2 * ) V_781 + V_52 +
V_800 , & V_792 ) ;
if ( ! V_772 ) {
* ( T_1 * ) ( ( T_2 * ) V_781 + V_52 ) =
F_194 ( V_806 , V_797 ,
V_792 , V_793 ) ;
V_52 += ( V_792 + V_800 ) ;
} else {
F_198 ( V_20 , L_138 , V_772 ) ;
}
}
V_772 = F_192 ( V_20 , ( T_2 * ) V_781 + V_52 +
V_800 , & V_792 ) ;
if ( ! V_772 ) {
* ( T_1 * ) ( ( T_2 * ) V_781 + V_52 ) =
F_194 ( V_807 , V_797 ,
V_792 , V_793 ) ;
V_52 += ( V_792 + V_800 ) ;
} else {
F_198 ( V_20 , L_139 , V_772 ) ;
}
F_197 ( V_20 , V_798 ) ;
return 0 ;
}
int F_199 ( struct V_780 * V_20 )
{
T_2 V_797 , V_798 ;
T_1 V_808 = 0 ;
V_798 = F_196 ( V_20 ) ;
for ( V_797 = 0 ; V_797 < V_20 -> V_799 ; V_797 ++ ) {
F_64 ( V_20 , V_234 ,
L_140 ) ;
F_197 ( V_20 , V_797 ) ;
V_808 += V_800 + F_183 ( V_20 ) +
V_800 + F_183 ( V_20 ) +
V_800 + F_180 ( V_20 ) +
V_800 + F_185 ( V_20 ) +
V_800 + F_187 ( V_20 ) +
V_800 +
F_189 ( V_20 ) +
V_800 + F_191 ( V_20 ) ;
}
V_808 += V_800 + F_193 ( V_20 ) ;
F_197 ( V_20 , V_798 ) ;
return V_808 ;
}
int V_766 ( struct V_780 * V_20 , void * V_781 ,
enum V_764 V_767 , T_1 * V_782 )
{
struct V_5 * V_6 =
& V_20 -> V_809 [ V_20 -> V_768 . V_810 ] ;
struct V_766 * V_811 =
& V_20 -> V_768 . V_769 [ V_767 ] ;
enum V_15 V_812 ;
struct V_16 * V_17 ;
int V_772 = 0 ;
V_17 = F_200 ( V_6 ) ;
if ( ! V_17 )
return - V_813 ;
V_812 = F_175 ( V_6 , V_17 , V_767 ) ;
if ( V_812 != V_19 ) {
F_64 ( V_20 , V_234 , L_141 ,
F_143 ( V_812 ) ) ;
* V_782 = 0 ;
V_772 = - V_813 ;
goto V_814;
}
F_64 ( V_20 , V_234 ,
L_142 ) ;
memcpy ( V_781 , V_811 -> V_44 , V_811 -> V_573 ) ;
* V_782 = V_20 -> V_768 . V_769 [ V_767 ] . V_775 *
4 ;
V_814:
F_201 ( V_6 , V_17 ) ;
return V_772 ;
}
int F_181 ( struct V_780 * V_20 , enum V_764 V_767 )
{
struct V_5 * V_6 =
& V_20 -> V_809 [ V_20 -> V_768 . V_810 ] ;
struct V_16 * V_17 = F_200 ( V_6 ) ;
struct V_766 * V_811 =
& V_20 -> V_768 . V_769 [ V_767 ] ;
T_1 V_779 ;
enum V_15 V_772 ;
if ( ! V_17 )
return - V_813 ;
V_772 = V_774 [ V_767 ] . F_176 ( V_6 , V_17 ,
& V_779 ) ;
if ( V_772 != V_19 )
V_779 = 0 ;
F_201 ( V_6 , V_17 ) ;
V_811 -> V_573 = V_779 * sizeof( T_1 ) ;
return V_811 -> V_573 ;
}
T_2 F_196 ( struct V_780 * V_20 )
{
return V_20 -> V_768 . V_810 ;
}
void F_197 ( struct V_780 * V_20 , int V_815 )
{
F_64 ( V_20 , V_234 , L_143 ,
V_815 ) ;
V_20 -> V_768 . V_810 = V_815 ;
}
void F_202 ( struct V_780 * V_20 )
{
const T_2 * V_816 ;
V_816 = V_20 -> V_817 -> V_195 + * ( T_1 * ) V_20 -> V_817 -> V_195 ;
F_117 ( ( T_2 * ) V_816 ) ;
F_132 ( ( T_2 * ) V_816 ) ;
}
void F_203 ( struct V_780 * V_20 )
{
struct V_766 * V_767 = NULL ;
enum V_764 V_765 ;
for ( V_765 = 0 ; V_765 < V_818 ; V_765 ++ ) {
V_767 = & V_20 -> V_768 . V_769 [ V_765 ] ;
if ( V_767 -> V_44 ) {
F_174 ( V_767 -> V_44 ) ;
V_767 -> V_44 = NULL ;
}
}
}
