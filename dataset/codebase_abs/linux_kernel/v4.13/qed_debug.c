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
return ( V_1 [ 0 ] != V_2 [ 0 ] ) && ( ( ( V_1 [ 1 ] >> V_2 [ 1 ] ) & V_2 [ 2 ] ) == V_2 [ 3 ] ) ;
}
static T_1 F_4 ( const T_1 * V_1 , const T_1 * V_2 )
{
return ( V_1 [ 0 ] & V_2 [ 0 ] ) != V_2 [ 1 ] ;
}
static T_1 F_5 ( const T_1 * V_1 , const T_1 * V_2 )
{
return ( ( V_1 [ 0 ] & V_2 [ 0 ] ) >> V_2 [ 1 ] ) !=
( ( ( V_1 [ 0 ] & V_2 [ 2 ] ) >> V_2 [ 3 ] ) | ( ( V_1 [ 1 ] & V_2 [ 4 ] ) << V_2 [ 5 ] ) ) ;
}
static T_1 F_6 ( const T_1 * V_1 , const T_1 * V_2 )
{
return ( ( V_1 [ 0 ] & V_2 [ 0 ] ) >> V_2 [ 1 ] ) != ( V_1 [ 0 ] & V_2 [ 2 ] ) ;
}
static T_1 F_7 ( const T_1 * V_1 , const T_1 * V_2 )
{
return ( V_1 [ 0 ] & ~ V_2 [ 0 ] ) != V_2 [ 1 ] ;
}
static T_1 F_8 ( const T_1 * V_1 , const T_1 * V_2 )
{
return ( V_1 [ 0 ] & ~ V_1 [ 1 ] ) != V_2 [ 0 ] ;
}
static T_1 F_9 ( const T_1 * V_1 , const T_1 * V_2 )
{
return V_1 [ 0 ] != V_2 [ 0 ] ;
}
static T_1 F_10 ( const T_1 * V_1 , const T_1 * V_2 )
{
return V_1 [ 0 ] != V_1 [ 1 ] && V_1 [ 2 ] == V_2 [ 0 ] ;
}
static T_1 F_11 ( const T_1 * V_1 , const T_1 * V_2 )
{
return V_1 [ 0 ] != V_1 [ 1 ] && V_1 [ 2 ] > V_2 [ 0 ] ;
}
static T_1 F_12 ( const T_1 * V_1 , const T_1 * V_2 )
{
return V_1 [ 0 ] != V_1 [ 1 ] ;
}
static T_1 F_13 ( const T_1 * V_1 , const T_1 * V_2 )
{
return V_1 [ 0 ] & V_2 [ 0 ] ;
}
static T_1 F_14 ( const T_1 * V_1 , const T_1 * V_2 )
{
return V_1 [ 0 ] < ( V_1 [ 1 ] - V_2 [ 0 ] ) ;
}
static T_1 F_15 ( const T_1 * V_1 , const T_1 * V_2 )
{
return V_1 [ 0 ] > V_2 [ 0 ] ;
}
static T_1 F_16 ( T_2 * V_3 )
{
T_1 V_4 ;
memcpy ( ( T_2 * ) & V_4 , V_3 , sizeof( V_4 ) ) ;
return V_4 ;
}
static T_1 F_17 ( struct V_5 * V_6 ,
enum V_7 V_8 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
return V_10 -> V_12 . V_13 [ V_8 ] ;
}
static void F_18 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
if ( ! V_10 -> V_12 . V_14 ) {
F_19 ( V_6 ) ;
V_10 -> V_12 . V_14 = 1 ;
}
}
static enum V_15 F_20 ( struct V_5 * V_6 ,
struct V_16 * V_17 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
if ( V_10 -> V_18 )
return V_19 ;
if ( F_21 ( V_6 -> V_20 ) ) {
V_10 -> V_21 = V_22 ;
V_10 -> V_23 [ V_24 ] = 1 ;
} else if ( F_22 ( V_6 -> V_20 ) ) {
V_10 -> V_21 = V_25 ;
V_10 -> V_23 [ V_26 ] = 1 ;
} else {
return V_27 ;
}
V_10 -> V_28 = V_29 ;
V_10 -> V_23 [ V_30 ] = 1 ;
F_18 ( V_6 ) ;
V_10 -> V_18 = true ;
return V_19 ;
}
static struct V_31 * F_23 ( struct V_5 * V_6 ,
enum V_32 V_32 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
return (struct V_31 * ) & V_33 [ V_32 *
V_34 +
V_10 -> V_21 ] ;
}
static void F_24 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_2 V_35 , struct V_36 * V_36 )
{
struct V_37 * V_38 = & V_39 [ V_35 ] ;
struct V_40 V_40 ;
T_1 V_41 , V_42 , * V_43 ;
memset ( & V_40 , 0 , sizeof( V_40 ) ) ;
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
V_41 = V_38 -> V_44 + V_45 +
F_25 ( V_46 ) -
sizeof( V_40 ) ;
V_43 = ( T_1 * ) & V_40 ;
for ( V_42 = 0 ; V_42 < F_26 ( sizeof( V_40 ) ) ;
V_42 ++ , V_41 += V_47 )
V_43 [ V_42 ] = F_27 ( V_6 , V_17 , V_41 ) ;
if ( V_40 . V_48 > 0 && V_40 . V_48 <=
sizeof( * V_36 ) ) {
V_41 = V_40 . V_49 ;
V_43 = ( T_1 * ) V_36 ;
for ( V_42 = 0 ; V_42 < F_26 ( V_40 . V_48 ) ;
V_42 ++ , V_41 += V_47 )
V_43 [ V_42 ] = F_27 ( V_6 , V_17 , V_41 ) ;
}
}
static T_1 F_28 ( char * V_50 , bool V_51 , const char * V_52 )
{
if ( V_51 )
strcpy ( V_50 , V_52 ) ;
return ( T_1 ) strlen ( V_52 ) + 1 ;
}
static T_1 F_29 ( char * V_50 , bool V_51 , T_1 V_53 )
{
T_2 V_54 , V_55 ;
V_54 = ( T_2 ) ( V_53 & 0x3 ) ;
V_55 = V_54 ? V_47 - V_54 : 0 ;
if ( V_51 && V_55 )
memset ( V_50 , 0 , V_55 ) ;
return V_55 ;
}
static T_1 F_30 ( T_1 * V_50 ,
bool V_51 ,
const char * V_56 , const char * V_13 )
{
char * V_57 = ( char * ) V_50 ;
T_1 V_58 = 0 ;
V_58 += F_28 ( V_57 + V_58 , V_51 , V_56 ) ;
if ( V_51 )
* ( V_57 + V_58 ) = 1 ;
V_58 ++ ;
V_58 += F_28 ( V_57 + V_58 , V_51 , V_13 ) ;
V_58 += F_29 ( V_57 + V_58 , V_51 , V_58 ) ;
return F_26 ( V_58 ) ;
}
static T_1 F_31 ( T_1 * V_50 ,
bool V_51 , const char * V_56 , T_1 V_13 )
{
char * V_57 = ( char * ) V_50 ;
T_1 V_58 = 0 ;
V_58 += F_28 ( V_57 + V_58 , V_51 , V_56 ) ;
if ( V_51 )
* ( V_57 + V_58 ) = 0 ;
V_58 ++ ;
V_58 += F_29 ( V_57 + V_58 , V_51 , V_58 ) ;
V_58 = F_26 ( V_58 ) ;
if ( V_51 )
* ( V_50 + V_58 ) = V_13 ;
V_58 ++ ;
return V_58 ;
}
static T_1 F_32 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 , bool V_51 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
char V_59 [ 16 ] = V_60 ;
char V_61 [ 16 ] = V_62 ;
struct V_36 V_36 = { { 0 } , { 0 } } ;
T_1 V_58 = 0 ;
if ( V_51 && ! F_17 ( V_6 , V_63 ) ) {
bool V_64 = false ;
T_2 V_35 ;
for ( V_35 = 0 ; V_35 < V_65 && ! V_64 ;
V_35 ++ ) {
struct V_37 * V_38 = & V_39 [ V_35 ] ;
if ( V_10 -> V_66 [ V_38 -> V_32 ] )
continue;
F_24 ( V_6 , V_17 , V_35 , & V_36 ) ;
if ( snprintf ( V_59 , sizeof( V_59 ) ,
L_1 , V_36 . V_67 . V_68 . V_69 ,
V_36 . V_67 . V_68 . V_70 , V_36 . V_67 . V_68 . V_71 ,
V_36 . V_67 . V_68 . V_72 ) < 0 )
F_33 ( V_6 ,
L_2 ) ;
switch ( V_36 . V_67 . V_73 ) {
case V_74 :
strcpy ( V_61 , L_3 ) ;
break;
default:
strcpy ( V_61 , L_4 ) ;
break;
}
V_64 = true ;
}
}
V_58 += F_30 ( V_50 + V_58 ,
V_51 , L_5 , V_59 ) ;
V_58 += F_30 ( V_50 + V_58 ,
V_51 , L_6 , V_61 ) ;
V_58 += F_31 ( V_50 + V_58 ,
V_51 ,
L_7 , V_36 . V_67 . V_75 ) ;
return V_58 ;
}
static T_1 F_34 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 , bool V_51 )
{
char V_76 [ 16 ] = V_60 ;
if ( V_51 &&
! F_17 ( V_6 , V_63 ) ) {
T_1 V_77 , V_78 , V_79 ;
T_1 V_80 , V_81 ;
V_80 = F_27 ( V_6 ,
V_17 ,
V_82 ) |
V_83 ;
V_81 = V_80 +
F_35 ( struct V_84 ,
V_85 ) +
sizeof( V_86 ) * V_87 ;
V_77 = F_27 ( V_6 , V_17 ,
V_81 ) ;
V_78 =
V_83 +
( V_77 & V_88 ) * 4 ;
V_79 = F_27 ( V_6 , V_17 ,
V_78 +
F_35 ( struct V_89 , V_79 ) ) ;
if ( snprintf ( V_76 , sizeof( V_76 ) , L_1 ,
( T_2 ) ( V_79 >> 24 ) , ( T_2 ) ( V_79 >> 16 ) ,
( T_2 ) ( V_79 >> 8 ) , ( T_2 ) V_79 ) < 0 )
F_33 ( V_6 ,
L_8 ) ;
}
return F_30 ( V_50 , V_51 , L_9 , V_76 ) ;
}
static T_1 F_36 ( T_1 * V_50 ,
bool V_51 , const char * V_90 , T_1 V_91 )
{
return F_31 ( V_50 , V_51 , V_90 , V_91 ) ;
}
static T_1 F_37 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 ,
bool V_51 ,
T_2 V_92 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
T_1 V_58 = 0 ;
T_2 V_91 ;
V_91 = V_93 + V_92 ;
V_58 += F_36 ( V_50 + V_58 ,
V_51 , L_10 , V_91 ) ;
V_58 += F_32 ( V_6 , V_17 , V_50 + V_58 , V_51 ) ;
V_58 += F_34 ( V_6 ,
V_17 , V_50 + V_58 , V_51 ) ;
V_58 += F_31 ( V_50 + V_58 ,
V_51 , L_11 , V_94 ) ;
V_58 += F_30 ( V_50 + V_58 ,
V_51 ,
L_12 ,
V_95 [ V_10 -> V_21 ] . V_90 ) ;
V_58 += F_30 ( V_50 + V_58 ,
V_51 ,
L_13 ,
V_96 [ V_10 -> V_28 ] .
V_90 ) ;
V_58 +=
F_31 ( V_50 + V_58 , V_51 , L_14 ,
V_6 -> V_97 ) ;
return V_58 ;
}
static T_1 F_38 ( struct V_5 * V_6 ,
T_1 * V_50 , T_1 V_58 , bool V_51 )
{
T_1 V_98 = V_58 ;
V_58 += F_36 ( V_50 + V_58 , V_51 , L_15 , 0 ) ;
if ( V_51 )
* ( V_50 + V_58 ) = ~ F_39 ( 0xffffffff ,
( T_2 * ) V_50 ,
F_25 ( V_58 ) ) ;
V_58 ++ ;
return V_58 - V_98 ;
}
static void F_40 ( struct V_5 * V_6 ,
struct V_16 * V_17 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
T_1 V_99 [ V_100 ] = { 0 } ;
T_1 V_42 ;
for ( V_42 = 0 ; V_42 < V_100 ; V_42 ++ )
if ( V_101 [ V_42 ] . V_102 [ V_10 -> V_21 ] )
V_99 [ V_42 ] = F_27 ( V_6 ,
V_17 , V_101 [ V_42 ] . V_41 ) ;
for ( V_42 = 0 ; V_42 < V_103 ; V_42 ++ ) {
struct V_104 * V_105 = V_106 [ V_42 ] ;
V_10 -> V_66 [ V_42 ] = V_105 -> V_107 &&
! ( V_99 [ V_105 -> V_108 ] & F_41 ( V_105 -> V_109 ) ) ;
}
}
static void F_42 ( struct V_5 * V_6 ,
struct V_16 * V_17 , bool V_110 )
{
F_43 ( V_6 , V_17 , V_111 , V_110 ? 1 : 0 ) ;
}
static void F_44 ( struct V_5 * V_6 ,
struct V_16 * V_17 )
{
T_1 V_112 , V_113 , V_114 ;
struct V_104 * V_115 = V_106 [ V_116 ] ;
V_112 = V_101 [ V_115 -> V_108 ] . V_41 ;
V_113 = F_27 ( V_6 , V_17 , V_112 ) ;
V_114 =
V_113 & ~ F_41 ( V_115 -> V_109 ) ;
F_43 ( V_6 , V_17 , V_112 , V_114 ) ;
F_43 ( V_6 , V_17 , V_112 , V_113 ) ;
}
static void F_45 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
enum V_117 V_118 )
{
F_43 ( V_6 , V_17 , V_119 , ( T_2 ) V_118 ) ;
}
static void F_46 ( struct V_5 * V_6 ,
struct V_16 * V_17 , T_1 V_120 )
{
F_43 ( V_6 , V_17 , V_121 , V_120 ) ;
}
static bool F_47 ( struct V_5 * V_6 , T_3 * V_122 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
bool V_123 , V_124 ;
const T_1 * V_125 ;
T_2 V_126 ;
V_125 = V_127 [ V_128 ] . V_125 ;
V_126 = ( ( T_2 * ) V_125 ) [ ( * V_122 ) ++ ] ;
switch ( V_126 ) {
case V_129 :
return ! F_47 ( V_6 , V_122 ) ;
case V_130 :
case V_131 :
V_123 = F_47 ( V_6 , V_122 ) ;
V_124 = F_47 ( V_6 , V_122 ) ;
return ( V_126 == V_130 ) ? ( V_123 ||
V_124 ) : ( V_123 && V_124 ) ;
default:
return V_10 -> V_23 [ V_126 - V_132 ] > 0 ;
}
}
static bool F_48 ( struct V_5 * V_6 ,
enum V_7 V_8 )
{
return F_17 ( V_6 , V_8 ) > 0 ;
}
static bool F_49 ( struct V_5 * V_6 ,
enum V_133 V_38 )
{
return F_17 ( V_6 , (enum V_7 ) V_38 ) > 0 ;
}
static bool F_50 ( struct V_5 * V_6 ,
enum V_32 V_32 , T_2 V_134 )
{
struct V_104 * V_105 = V_106 [ V_32 ] ;
T_2 V_42 ;
if ( V_105 -> V_135 &&
! F_49 ( V_6 ,
(enum V_133 ) V_105 -> V_35 ) )
return false ;
for ( V_42 = 0 ; V_42 < V_136 ; V_42 ++ ) {
struct V_137 * V_138 = & V_139 [ V_42 ] ;
if ( V_134 == V_138 -> V_134 ||
V_134 == V_138 -> V_140 )
return F_48 ( V_6 , V_138 -> V_8 ) ;
}
switch ( V_134 ) {
case V_141 :
case V_142 :
return F_48 ( V_6 , V_143 ) ;
case V_144 :
return F_48 ( V_6 , V_145 ) ;
case V_146 :
return F_48 ( V_6 , V_147 ) ;
case V_148 :
case V_149 :
case V_150 :
return F_48 ( V_6 , V_151 ) ;
case V_152 :
return F_48 ( V_6 , V_153 ) ;
case V_154 :
case V_155 :
case V_156 :
return F_48 ( V_6 , V_157 ) ;
case V_158 :
case V_159 :
return F_48 ( V_6 , V_160 ) ;
case V_161 :
return F_48 ( V_6 , V_162 ) ;
case V_163 :
return F_48 ( V_6 , V_164 ) ;
case V_165 :
return F_48 ( V_6 , V_166 ) ;
case V_167 :
return F_48 ( V_6 , V_168 ) ;
case V_169 :
return F_48 ( V_6 , V_170 ) ;
case V_171 :
case V_172 :
return F_48 ( V_6 , V_173 ) ;
case V_174 :
return F_48 ( V_6 , V_175 ) ;
case V_176 :
return F_48 ( V_6 , V_177 ) ;
default:
return true ;
}
}
static void F_51 ( struct V_5 * V_6 ,
struct V_16 * V_17 , bool V_178 )
{
T_1 V_179 ;
T_2 V_35 ;
for ( V_35 = 0 ; V_35 < V_65 ; V_35 ++ ) {
if ( ! F_49 ( V_6 ,
(enum V_133 ) V_35 ) )
continue;
V_179 = V_39 [ V_35 ] . V_44 +
V_180 ;
F_43 ( V_6 , V_17 , V_179 , V_178 ? 1 : 0 ) ;
}
F_52 ( V_181 ) ;
}
static void F_53 ( struct V_5 * V_6 ,
struct V_16 * V_17 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
T_1 V_99 [ V_100 ] = { 0 } ;
T_1 V_32 , V_42 ;
for ( V_32 = 0 ; V_32 < V_103 ; V_32 ++ ) {
struct V_104 * V_105 = V_106 [ V_32 ] ;
if ( V_105 -> V_107 && V_105 -> V_182 )
V_99 [ V_105 -> V_108 ] |=
F_41 ( V_105 -> V_109 ) ;
}
for ( V_42 = 0 ; V_42 < V_100 ; V_42 ++ ) {
if ( ! V_101 [ V_42 ] . V_102 [ V_10 -> V_21 ] )
continue;
V_99 [ V_42 ] |= V_101 [ V_42 ] . V_183 ;
if ( V_99 [ V_42 ] )
F_43 ( V_6 ,
V_17 ,
V_101 [ V_42 ] . V_41 +
V_184 , V_99 [ V_42 ] ) ;
}
}
static const struct V_185 *
F_54 ( enum V_32 V_32 , enum V_186 V_187 )
{
const struct V_188 * V_189 =
( const struct V_188 * )
V_127 [ V_190 ] . V_125 ;
return & V_189 [ V_32 ] . V_191 [ V_187 ] ;
}
static const struct V_192 *
F_55 ( enum V_32 V_32 , enum V_186 V_187 ,
T_2 * V_193 )
{
const struct V_185 * V_194 =
F_54 ( V_32 , V_187 ) ;
* V_193 = V_194 -> V_195 ;
return & ( ( const struct V_192 * )
V_127 [ V_196 ] . V_125 ) [ V_194 ->
V_197 ] ;
}
static void F_56 ( struct V_5 * V_6 ,
struct V_16 * V_17 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
const struct V_192 * V_198 ;
T_2 V_199 , V_193 ;
T_1 V_32 ;
for ( V_32 = 0 ; V_32 < V_103 ; V_32 ++ ) {
if ( V_10 -> V_66 [ V_32 ] )
continue;
V_198 = F_55 ( (enum V_32 ) V_32 ,
V_200 ,
& V_193 ) ;
for ( V_199 = 0 ; V_199 < V_193 ; V_199 ++ ) {
const struct V_192 * V_201 =
& V_198 [ V_199 ] ;
T_3 V_122 ;
bool V_202 ;
V_202 = F_57 ( V_201 -> V_118 . V_203 ,
V_204 ) > 0 ;
V_122 =
F_57 ( V_201 -> V_118 . V_203 ,
V_205 ) ;
if ( ! V_202 ||
F_47 ( V_6 , & V_122 ) )
F_27 ( V_6 , V_17 ,
F_25 ( V_201 ->
V_206 ) ) ;
}
}
}
static T_1 F_58 ( T_1 * V_50 ,
bool V_51 ,
T_1 V_207 ,
const char * V_208 ,
int V_209 ,
const char * V_56 , const char * V_13 )
{
T_2 V_91 = 2 + ( V_209 >= 0 ? 1 : 0 ) + ( V_56 ? 1 : 0 ) ;
T_1 V_58 = 0 ;
V_58 += F_36 ( V_50 + V_58 ,
V_51 , L_16 , V_91 ) ;
V_58 += F_31 ( V_50 + V_58 ,
V_51 , L_17 , V_207 ) ;
V_58 += F_30 ( V_50 + V_58 ,
V_51 , L_18 , V_208 ) ;
if ( V_209 >= 0 )
V_58 += F_31 ( V_50 + V_58 ,
V_51 , L_19 , V_209 ) ;
if ( V_56 && V_13 )
V_58 += F_30 ( V_50 + V_58 ,
V_51 , V_56 , V_13 ) ;
return V_58 ;
}
static T_1 F_59 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 ,
bool V_51 , T_1 V_41 , T_1 V_210 , bool V_211 )
{
T_1 V_212 = F_25 ( V_41 ) , V_58 = 0 , V_42 ;
if ( ! V_51 )
return V_210 ;
for ( V_42 = 0 ; V_42 < V_210 ; V_42 ++ , V_212 += V_47 , V_58 ++ )
* ( V_50 + V_58 ) = F_27 ( V_6 , V_17 , V_212 ) ;
return V_58 ;
}
static T_1 F_60 ( T_1 * V_50 ,
bool V_51 , T_1 V_41 , T_1 V_210 )
{
if ( V_51 )
* V_50 = V_41 | ( V_210 << V_213 ) ;
return 1 ;
}
static T_1 F_61 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 ,
bool V_51 , T_1 V_41 , T_1 V_210 , bool V_211 )
{
T_1 V_58 = 0 ;
V_58 += F_60 ( V_50 , V_51 , V_41 , V_210 ) ;
V_58 += F_59 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 , V_41 , V_210 , V_211 ) ;
return V_58 ;
}
static T_1 F_62 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 ,
bool V_51 ,
T_1 V_41 ,
T_1 V_214 ,
T_1 V_215 , T_1 V_216 )
{
T_1 V_58 = 0 , V_217 = 0 ;
V_58 += F_60 ( V_50 , V_51 , V_41 , V_214 ) ;
if ( ! V_51 )
return V_58 + V_214 ;
while ( V_217 < V_214 ) {
T_1 V_218 = F_63 ( T_1 , V_215 , V_214 - V_217 ) ;
V_58 += F_59 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 , V_41 , V_218 , false ) ;
V_217 += V_218 ;
V_41 += V_218 ;
if ( V_217 < V_214 ) {
V_218 = F_63 ( T_1 , V_216 , V_214 - V_216 ) ;
memset ( V_50 + V_58 , 0 , F_25 ( V_218 ) ) ;
V_58 += V_218 ;
V_217 += V_218 ;
V_41 += V_218 ;
}
}
return V_58 ;
}
static T_1 F_64 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
struct V_219 V_220 ,
T_1 * V_50 ,
bool V_51 ,
bool V_221 [ V_103 ] ,
T_1 * V_222 )
{
T_1 V_42 , V_58 = 0 , V_223 = 0 ;
bool V_224 = true ;
* V_222 = 0 ;
while ( V_223 < V_220 . V_225 ) {
const struct V_226 * V_227 =
( const struct V_226 * )
& V_220 . V_125 [ V_223 ++ ] ;
T_3 V_122 ;
bool V_202 ;
V_202 = F_57 ( V_227 -> V_118 . V_203 ,
V_204 ) > 0 ;
if ( V_202 ) {
V_122 =
F_57 ( V_227 -> V_118 . V_203 ,
V_205 ) ;
V_224 = F_47 ( V_6 ,
& V_122 ) ;
}
if ( ! V_224 || ! V_221 [ V_227 -> V_32 ] ) {
V_223 += V_227 -> V_228 ;
continue;
}
for ( V_42 = 0 ; V_42 < V_227 -> V_228 ; V_42 ++ , V_223 ++ ) {
const struct V_229 * V_230 =
( const struct V_229 * )
& V_220 . V_125 [ V_223 ] ;
T_1 V_41 , V_210 ;
bool V_211 ;
V_41 = F_57 ( V_230 -> V_203 , V_231 ) ;
V_210 = F_57 ( V_230 -> V_203 , V_232 ) ;
V_211 = F_57 ( V_230 -> V_203 , V_233 ) ;
V_58 += F_61 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 ,
V_41 ,
V_210 ,
V_211 ) ;
( * V_222 ) ++ ;
}
}
return V_58 ;
}
static T_1 F_65 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
struct V_219 V_220 ,
T_1 * V_50 ,
bool V_51 ,
bool V_221 [ V_103 ] ,
const char * V_234 ,
T_1 V_209 ,
const char * V_56 ,
const char * V_13 )
{
T_1 V_222 , V_58 ;
V_58 = F_58 ( V_50 ,
false ,
0 ,
V_234 ,
V_209 , V_56 , V_13 ) ;
V_58 += F_64 ( V_6 ,
V_17 ,
V_220 ,
V_50 + V_58 ,
V_51 ,
V_221 ,
& V_222 ) ;
if ( V_51 && V_222 > 0 )
F_58 ( V_50 ,
V_51 ,
V_222 ,
V_234 ,
V_209 , V_56 , V_13 ) ;
return V_222 > 0 ? V_58 : 0 ;
}
static T_1 F_66 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 ,
bool V_51 ,
bool V_221 [ V_103 ] ,
const char * V_56 , const char * V_13 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
struct V_235 * V_236 ;
T_1 V_58 = 0 , V_223 = 0 ;
struct V_237 * V_238 ;
T_2 V_239 , V_240 , V_241 ;
T_3 V_242 ;
V_238 = & V_95 [ V_10 -> V_21 ] ;
V_236 = & V_238 -> V_243 [ V_10 -> V_28 ] ;
if ( V_51 )
F_67 ( V_6 , V_244 , L_20 ) ;
while ( V_223 <
V_127 [ V_245 ] . V_225 ) {
const struct V_246 * V_247 ;
struct V_219 V_248 ;
T_1 V_249 ;
T_2 V_250 ;
V_247 =
( const struct V_246 * )
& V_127 [ V_245 ] . V_125 [ V_223 ++ ] ;
V_250 =
F_57 ( V_247 -> V_251 ,
V_252 ) ;
V_249 =
F_57 ( V_247 -> V_251 ,
V_253 ) ;
V_248 . V_125 =
& V_127 [ V_245 ] . V_125 [ V_223 ] ;
V_248 . V_225 = V_249 ;
switch ( V_250 ) {
case V_254 :
V_58 += F_65 ( V_6 ,
V_17 ,
V_248 ,
V_50 + V_58 ,
V_51 ,
V_221 ,
L_21 ,
( T_1 ) ( - 1 ) ,
V_56 ,
V_13 ) ;
break;
case V_255 :
for ( V_239 = 0 ; V_239 < V_236 -> V_256 ;
V_239 ++ ) {
if ( V_51 )
F_68 ( V_6 , V_17 ,
V_239 ) ;
V_58 +=
F_65 ( V_6 , V_17 ,
V_248 ,
V_50 + V_58 ,
V_51 , V_221 ,
L_22 , V_239 ,
V_56 ,
V_13 ) ;
}
break;
case V_257 :
case V_258 :
for ( V_240 = 0 ; V_240 < V_236 -> V_259 ;
V_240 ++ ) {
T_2 V_260 =
V_261 ;
if ( V_51 ) {
V_242 = V_240 << V_260 ;
F_69 ( V_6 , V_17 , V_242 ) ;
}
V_58 +=
F_65 ( V_6 ,
V_17 ,
V_248 ,
V_50 + V_58 ,
V_51 ,
V_221 ,
L_23 ,
V_240 ,
V_56 ,
V_13 ) ;
}
break;
case V_262 :
for ( V_241 = 0 ; V_241 < V_236 -> V_263 ;
V_241 ++ ) {
T_2 V_264 =
V_265 ;
T_2 V_266 =
V_267 ;
if ( V_51 ) {
V_242 = F_41 ( V_264 ) |
( V_241 << V_266 ) ;
F_69 ( V_6 , V_17 , V_242 ) ;
}
V_58 +=
F_65 ( V_6 , V_17 ,
V_248 ,
V_50 + V_58 ,
V_51 , V_221 ,
L_24 , V_241 ,
V_56 ,
V_13 ) ;
}
break;
default:
break;
}
V_223 += V_249 ;
}
if ( V_51 ) {
V_242 = V_6 -> V_268 << V_261 ;
F_69 ( V_6 , V_17 , V_242 ) ;
}
return V_58 ;
}
static T_1 F_70 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 , bool V_51 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
T_1 V_42 , V_58 = 0 , V_195 = 0 ;
V_58 += F_58 ( V_50 ,
false , 0 , L_21 , - 1 , NULL , NULL ) ;
for ( V_42 = 0 ; V_42 < V_100 ; V_42 ++ ) {
if ( ! V_101 [ V_42 ] . V_102 [ V_10 -> V_21 ] )
continue;
V_58 += F_61 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 ,
F_26
( V_101 [ V_42 ] . V_41 ) , 1 ,
false ) ;
V_195 ++ ;
}
if ( V_51 )
F_58 ( V_50 ,
true , V_195 , L_21 , - 1 , NULL , NULL ) ;
return V_58 ;
}
static T_1 F_71 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 , bool V_51 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
T_1 V_32 , V_58 = 0 , V_207 = 0 ;
const struct V_192 * V_198 ;
T_2 V_35 , V_199 , V_193 ;
V_58 += F_58 ( V_50 ,
false , 0 , L_21 , - 1 , NULL , NULL ) ;
for ( V_32 = 0 ; V_32 < V_103 ; V_32 ++ ) {
if ( V_10 -> V_66 [ V_32 ] && V_51 )
continue;
V_198 = F_55 ( (enum V_32 ) V_32 ,
V_200 ,
& V_193 ) ;
for ( V_199 = 0 ; V_199 < V_193 ; V_199 ++ ) {
const struct V_192 * V_201 =
& V_198 [ V_199 ] ;
T_3 V_122 ;
bool V_202 ;
T_1 V_41 ;
V_202 = F_57 ( V_201 -> V_118 . V_203 ,
V_204 ) > 0 ;
V_122 =
F_57 ( V_201 -> V_118 . V_203 ,
V_205 ) ;
if ( V_202 &&
! F_47 ( V_6 , & V_122 ) )
continue;
V_41 = V_201 -> V_269 ;
V_58 += F_61 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 ,
V_41 ,
1 , false ) ;
V_41 = F_57 ( V_201 -> V_203 ,
V_270 ) ;
V_58 += F_61 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 ,
V_41 ,
1 , false ) ;
V_207 += 2 ;
}
}
for ( V_35 = 0 ; V_35 < V_65 ; V_35 ++ ) {
struct V_37 * V_38 = & V_39 [ V_35 ] ;
T_1 V_41 ;
if ( V_10 -> V_66 [ V_38 -> V_32 ] && V_51 )
continue;
V_41 =
F_26 ( V_39 [ V_35 ] . V_44 +
V_271 ) ;
V_58 += F_61 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 ,
V_41 ,
1 ,
false ) ;
V_207 ++ ;
}
if ( V_51 )
F_58 ( V_50 ,
true ,
V_207 , L_21 , - 1 , NULL , NULL ) ;
return V_58 ;
}
static T_1 F_72 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 , bool V_51 )
{
T_1 V_58 = 0 , V_41 ;
V_58 += F_58 ( V_50 ,
V_51 , 2 , L_21 , - 1 , NULL , NULL ) ;
V_41 = F_26 ( V_272 ) ;
V_58 += F_62 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 ,
V_41 ,
V_273 ,
7 ,
1 ) ;
V_41 = F_26 ( V_274 ) ;
V_58 +=
F_62 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 ,
V_41 ,
V_275 ,
7 ,
1 ) ;
return V_58 ;
}
static T_1 F_73 ( struct V_5 * V_6 ,
T_1 * V_50 ,
bool V_51 ,
const char * V_90 ,
T_1 V_41 ,
T_1 V_210 ,
T_1 V_276 ,
bool V_277 ,
const char * V_278 ,
bool V_279 , char V_280 )
{
T_2 V_91 = 3 ;
T_1 V_58 = 0 ;
char V_3 [ 64 ] ;
if ( ! V_210 )
F_33 ( V_6 ,
L_25 ) ;
if ( V_276 )
V_91 ++ ;
if ( V_277 )
V_91 ++ ;
V_58 += F_36 ( V_50 + V_58 ,
V_51 , L_26 , V_91 ) ;
if ( V_90 ) {
if ( V_279 ) {
strcpy ( V_3 , L_27 ) ;
V_3 [ 0 ] = V_280 ;
strcpy ( V_3 + strlen ( V_3 ) , V_90 ) ;
} else {
strcpy ( V_3 , V_90 ) ;
}
V_58 += F_30 ( V_50 + V_58 ,
V_51 , L_28 , V_3 ) ;
if ( V_51 )
F_67 ( V_6 ,
V_244 ,
L_29 ,
V_210 , V_3 ) ;
} else {
T_1 V_281 = F_25 ( V_41 ) ;
V_58 += F_31 ( V_50 + V_58 ,
V_51 , L_30 , V_281 ) ;
if ( V_51 && V_210 > 64 )
F_67 ( V_6 ,
V_244 ,
L_31 ,
V_210 , V_281 ) ;
}
V_58 += F_31 ( V_50 + V_58 , V_51 , L_32 , V_210 ) ;
if ( V_276 )
V_58 += F_31 ( V_50 + V_58 ,
V_51 , L_33 , V_276 ) ;
if ( V_277 )
V_58 += F_31 ( V_50 + V_58 ,
V_51 , L_34 , 1 ) ;
if ( V_279 ) {
strcpy ( V_3 , L_27 ) ;
V_3 [ 0 ] = V_280 ;
strcpy ( V_3 + strlen ( V_3 ) , V_278 ) ;
} else {
strcpy ( V_3 , V_278 ) ;
}
V_58 += F_30 ( V_50 + V_58 , V_51 , L_35 , V_3 ) ;
return V_58 ;
}
static T_1 F_74 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 ,
bool V_51 ,
const char * V_90 ,
T_1 V_41 ,
T_1 V_210 ,
bool V_211 ,
T_1 V_276 ,
bool V_277 ,
const char * V_278 ,
bool V_279 , char V_280 )
{
T_1 V_58 = 0 ;
V_58 += F_73 ( V_6 ,
V_50 + V_58 ,
V_51 ,
V_90 ,
V_41 ,
V_210 ,
V_276 ,
V_277 ,
V_278 , V_279 , V_280 ) ;
V_58 += F_59 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 , V_41 , V_210 , V_211 ) ;
return V_58 ;
}
static T_1 F_75 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
struct V_219 V_282 ,
T_1 * V_50 , bool V_51 )
{
T_1 V_42 , V_58 = 0 , V_223 = 0 ;
bool V_224 = true ;
while ( V_223 < V_282 . V_225 ) {
const struct V_226 * V_227 ;
T_3 V_122 ;
T_1 V_283 ;
bool V_202 ;
V_227 = ( const struct V_226 * )
& V_282 . V_125 [ V_223 ++ ] ;
V_283 = V_227 -> V_228 / V_284 ;
V_202 = F_57 ( V_227 -> V_118 . V_203 ,
V_204 ) > 0 ;
if ( V_202 ) {
V_122 =
F_57 ( V_227 -> V_118 . V_203 ,
V_205 ) ;
V_224 = F_47 ( V_6 ,
& V_122 ) ;
}
if ( ! V_224 ) {
V_223 += V_227 -> V_228 ;
continue;
}
for ( V_42 = 0 ; V_42 < V_283 ;
V_42 ++ , V_223 += V_284 ) {
const struct V_285 * V_286 =
( const struct V_285 * )
& V_282 . V_125 [ V_223 ] ;
T_2 V_134 = F_57 ( V_286 -> V_287 ,
V_288 ) ;
bool V_279 = false , V_289 ;
enum V_7 V_8 ;
char V_280 = 'a' ;
enum V_32 V_32 ;
T_1 V_290 , V_291 ;
if ( V_134 >= V_292 ) {
F_33 ( V_6 , L_36 ) ;
return 0 ;
}
V_32 = (enum V_32 ) V_227 -> V_32 ;
if ( ! F_50 ( V_6 ,
V_32 ,
V_134 ) )
continue;
V_290 = F_57 ( V_286 -> V_287 , V_293 ) ;
V_291 = F_57 ( V_286 -> V_294 , V_295 ) ;
V_289 = F_57 ( V_286 -> V_294 ,
V_296 ) ;
if ( V_134 == V_155 ) {
if ( V_291 % V_297 ) {
F_33 ( V_6 ,
L_37 ) ;
return 0 ;
}
V_8 = V_298 ;
V_291 = F_17 ( V_6 , V_8 ) *
( V_291 / V_297 ) ;
} else if ( V_134 == V_156 ) {
if ( V_291 % V_299 ) {
F_33 ( V_6 ,
L_38 ) ;
return 0 ;
}
V_8 = V_300 ;
V_291 = F_17 ( V_6 , V_8 ) *
( V_291 / V_299 ) ;
}
if ( V_106
[ V_227 -> V_32 ] -> V_135 ) {
V_279 = true ;
V_280 =
V_39 [ V_106
[ V_227 -> V_32 ] ->
V_35 ] . V_301 ;
}
V_58 += F_74 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 ,
NULL ,
V_290 ,
V_291 ,
V_289 ,
0 ,
false ,
V_302 [ V_134 ] ,
V_279 ,
V_280 ) ;
}
}
return V_58 ;
}
static T_1 F_76 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 , bool V_51 )
{
T_1 V_58 = 0 , V_223 = 0 ;
while ( V_223 <
V_127 [ V_303 ] . V_225 ) {
const struct V_246 * V_247 ;
struct V_219 V_304 ;
T_1 V_249 ;
T_2 V_250 ;
V_247 = ( const struct V_246 * )
& V_127 [ V_303 ] . V_125 [ V_223 ++ ] ;
V_250 =
F_57 ( V_247 -> V_251 ,
V_252 ) ;
V_249 =
F_57 ( V_247 -> V_251 ,
V_253 ) ;
V_304 . V_125 =
& V_127 [ V_303 ] . V_125 [ V_223 ] ;
V_304 . V_225 = V_249 ;
switch ( V_250 ) {
case V_254 :
V_58 += F_75 ( V_6 ,
V_17 ,
V_304 ,
V_50 + V_58 ,
V_51 ) ;
break;
default:
F_33 ( V_6 ,
L_39 ) ;
break;
}
V_223 += V_249 ;
}
return V_58 ;
}
static T_1 F_77 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 ,
bool V_51 ,
const char * V_90 ,
T_1 V_305 ,
T_1 V_306 ,
T_1 V_307 ,
T_2 V_35 )
{
struct V_37 * V_38 = & V_39 [ V_35 ] ;
T_1 V_42 , V_308 , V_309 , V_58 = 0 ;
if ( ! V_306 )
return 0 ;
V_306 *= V_47 ;
V_309 = V_305 * V_306 ;
V_58 += F_73 ( V_6 ,
V_50 + V_58 ,
V_51 ,
V_90 ,
0 ,
V_309 ,
V_306 * 32 ,
false , V_90 , true , V_38 -> V_301 ) ;
if ( ! V_51 )
return V_58 + V_309 ;
for ( V_308 = 0 ; V_308 < V_305 ; V_308 ++ ) {
for ( V_42 = 0 ; V_42 < V_306 ; V_42 ++ , V_58 ++ ) {
F_43 ( V_6 ,
V_17 , V_38 -> V_310 , ( V_42 << 9 ) | V_308 ) ;
* ( V_50 + V_58 ) = F_27 ( V_6 ,
V_17 , V_307 ) ;
}
}
return V_58 ;
}
static T_1 F_78 ( struct V_5 * V_6 ,
struct V_16 * V_17 , T_1 * V_50 , bool V_51 )
{
enum V_7 V_8 ;
T_1 V_58 = 0 ;
T_2 V_35 ;
for ( V_35 = 0 ; V_35 < V_65 ; V_35 ++ ) {
struct V_37 * V_38 = & V_39 [ V_35 ] ;
if ( ! F_49 ( V_6 ,
(enum V_133 ) V_35 ) )
continue;
V_8 = V_298 ;
V_58 +=
F_77 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 ,
L_40 ,
F_17 ( V_6 ,
V_8 ) ,
V_38 -> V_311 ,
V_38 -> V_312 ,
V_35 ) ;
V_8 = V_298 ;
V_58 +=
F_77 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 ,
L_41 ,
F_17 ( V_6 ,
V_8 ) ,
V_38 -> V_313 ,
V_38 -> V_314 ,
V_35 ) ;
V_8 = V_300 ;
V_58 +=
F_77 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 ,
L_42 ,
F_17 ( V_6 ,
V_8 ) ,
V_38 -> V_315 ,
V_38 -> V_316 ,
V_35 ) ;
V_8 = V_300 ;
V_58 +=
F_77 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 ,
L_43 ,
F_17 ( V_6 ,
V_8 ) ,
V_38 -> V_317 ,
V_38 -> V_318 ,
V_35 ) ;
}
return V_58 ;
}
static T_1 F_79 ( struct V_5 * V_6 ,
struct V_16 * V_17 , T_1 * V_50 , bool V_51 )
{
char V_3 [ 10 ] = L_44 ;
T_1 V_41 , V_58 = 0 ;
T_2 V_35 , V_319 ;
for ( V_35 = 0 ; V_35 < V_65 ; V_35 ++ ) {
struct V_37 * V_38 = & V_39 [ V_35 ] ;
if ( ! F_49 ( V_6 ,
(enum V_133 ) V_35 ) )
continue;
for ( V_319 = 0 ; V_319 < V_320 ; V_319 ++ ) {
V_41 = F_26 ( V_38 -> V_44 +
V_321 ) +
F_80 ( V_319 ) ;
V_3 [ strlen ( V_3 ) - 1 ] = '0' + V_319 ;
V_58 += F_74 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 ,
V_3 ,
V_41 ,
V_322 ,
false ,
32 ,
false ,
L_45 ,
true ,
V_38 -> V_301 ) ;
}
}
return V_58 ;
}
static T_1 F_81 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 , bool V_51 , T_2 V_35 )
{
T_1 V_309 = V_323 * V_324 ;
struct V_37 * V_38 = & V_39 [ V_35 ] ;
T_1 V_325 [ V_326 ] = { 0 } ;
T_1 V_327 [ V_328 ] = { 0 } ;
T_1 V_329 , V_42 , V_58 = 0 ;
V_58 += F_73 ( V_6 ,
V_50 + V_58 ,
V_51 ,
L_46 ,
0 ,
V_309 ,
256 ,
false , L_46 , true , V_38 -> V_301 ) ;
if ( ! V_51 )
return V_58 + V_309 ;
F_82 ( V_325 , V_330 , V_331 , V_332 ) ;
for ( V_329 = 0 ; V_329 < V_323 ;
V_329 ++ , V_58 += V_324 ) {
F_82 ( V_327 , V_333 , V_334 , V_329 ) ;
F_83 ( V_6 ,
V_17 ,
V_38 -> V_44 + V_335 ,
V_327 , V_328 ) ;
F_83 ( V_6 ,
V_17 ,
V_38 -> V_44 + V_336 ,
V_325 , V_326 ) ;
F_84 ( V_6 ,
V_17 ,
V_38 -> V_44 + V_337 ,
V_50 + V_58 , V_324 ) ;
}
return V_58 ;
}
static T_1 F_85 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 ,
bool V_51 ,
T_2 V_35 , struct V_338 * V_339 )
{
T_1 V_309 = V_339 -> V_340 * V_341 ;
struct V_37 * V_38 = & V_39 [ V_35 ] ;
T_1 V_342 [ V_343 ] = { 0 } ;
T_1 V_344 [ V_345 ] = { 0 } ;
T_1 V_329 , V_42 , V_58 = 0 ;
V_58 += F_73 ( V_6 ,
V_50 + V_58 ,
V_51 ,
V_339 -> V_346 ,
0 ,
V_309 ,
256 ,
false ,
V_339 -> V_347 ,
true , V_38 -> V_301 ) ;
F_82 ( V_342 , V_348 , V_331 , V_349 ) ;
if ( ! V_51 )
return V_58 + V_309 ;
for ( V_329 = V_339 -> V_350 ;
V_329 < V_339 -> V_350 + V_339 -> V_340 ;
V_329 ++ , V_58 += V_341 ) {
F_83 ( V_6 ,
V_17 ,
V_38 -> V_44 + V_335 ,
V_344 , V_345 ) ;
F_82 ( V_342 , V_348 , V_334 , V_329 ) ;
F_83 ( V_6 ,
V_17 ,
V_38 -> V_44 + V_336 ,
V_342 , V_343 ) ;
F_84 ( V_6 ,
V_17 ,
V_38 -> V_44 + V_337 ,
V_50 + V_58 , V_341 ) ;
}
return V_58 ;
}
static T_1 F_86 ( struct V_5 * V_6 ,
struct V_16 * V_17 , T_1 * V_50 , bool V_51 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
T_2 V_35 , V_42 ;
T_1 V_58 = 0 ;
for ( V_35 = 0 ; V_35 < V_65 ; V_35 ++ ) {
if ( ! F_49 ( V_6 ,
(enum V_133 ) V_35 ) ||
! V_39 [ V_35 ] . V_351 ||
( V_35 == V_352 && V_10 -> V_28 !=
V_29 ) )
continue;
V_58 += F_81 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 , V_35 ) ;
for ( V_42 = 0 ; V_42 < V_353 ; V_42 ++ )
V_58 += F_85 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 ,
V_35 ,
& V_354 [ V_42 ] ) ;
}
return V_58 ;
}
static T_1 F_87 ( struct V_5 * V_6 ,
struct V_16 * V_17 , T_1 * V_50 , bool V_51 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
T_1 V_58 = 0 ;
T_2 V_355 ;
for ( V_355 = 0 ; V_355 < V_356 ; V_355 ++ ) {
T_1 V_357 , V_283 , V_358 , V_359 , V_42 ;
struct V_360 * V_361 ;
T_1 V_41 , V_48 ;
bool V_277 ;
V_361 = & V_362 [ V_355 ] ;
V_357 = V_361 -> V_41 ;
V_283 = V_361 -> V_283 [ V_10 -> V_21 ] ;
V_358 = V_361 -> V_358 [ V_10 -> V_21 ] ;
V_359 = ( V_283 * V_358 ) / 32 ;
V_277 = ( V_358 == 16 ) ;
V_58 += F_73 ( V_6 ,
V_50 + V_58 ,
V_51 ,
V_361 -> V_346 ,
0 ,
V_359 ,
V_358 ,
V_277 ,
V_361 -> V_347 , false , 0 ) ;
if ( ! V_51 ) {
V_58 += V_359 ;
continue;
}
V_41 = F_26 ( V_363 ) ;
V_48 = V_364 ;
for ( V_42 = 0 ; V_42 < V_359 ; V_42 += V_48 , V_357 ++ ) {
F_43 ( V_6 , V_17 , V_365 , V_357 ) ;
V_58 += F_59 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 ,
V_41 ,
V_48 ,
false ) ;
}
}
return V_58 ;
}
static T_1 F_88 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 , bool V_51 , T_2 V_366 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
T_1 V_367 , V_368 , V_58 = 0 , V_42 ;
char V_346 [ 12 ] = L_47 ;
char V_347 [ 8 ] = L_48 ;
struct V_137 * V_138 ;
V_138 = & V_139 [ V_366 ] ;
V_367 = V_138 -> V_369 [ V_10 -> V_21 ] ;
V_368 = V_367 * V_370 ;
strncpy ( V_347 , V_138 -> V_371 ,
strlen ( V_138 -> V_371 ) ) ;
strncpy ( V_346 , V_138 -> V_371 ,
strlen ( V_138 -> V_371 ) ) ;
V_58 += F_73 ( V_6 ,
V_50 + V_58 ,
V_51 ,
V_346 ,
0 ,
V_368 ,
V_372 * 8 ,
false , V_347 , false , 0 ) ;
if ( ! V_51 )
return V_58 + V_368 ;
for ( V_42 = 0 ; V_42 < V_367 / 2 ; V_42 ++ ) {
T_1 V_41 , V_210 ;
F_43 ( V_6 , V_17 , V_138 -> V_373 , V_42 ) ;
V_41 = F_26 ( V_138 -> V_374 ) ;
V_210 = 2 * V_370 ;
V_58 += F_59 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 ,
V_41 ,
V_210 ,
false ) ;
}
return V_58 ;
}
static T_1 F_89 ( struct V_5 * V_6 ,
struct V_16 * V_17 , T_1 * V_50 , bool V_51 )
{
bool V_221 [ V_103 ] = { 0 } ;
T_1 V_58 = 0 , V_41 ;
bool V_375 = false ;
if ( V_51 && ! F_17 ( V_6 , V_376 ) ) {
V_375 = ! F_90 ( V_6 , V_17 ) ;
if ( ! V_375 )
F_33 ( V_6 , L_49 ) ;
}
V_58 += F_74 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 ,
NULL ,
F_26 ( V_83 ) ,
V_377 ,
false , 0 , false , L_50 , false , 0 ) ;
V_58 += F_74 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 ,
NULL ,
F_26 ( V_378 ) ,
V_379 ,
false , 0 , false , L_50 , false , 0 ) ;
V_221 [ V_380 ] = true ;
V_58 += F_66 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 , V_221 , L_51 , L_50 ) ;
V_58 += F_58 ( V_50 + V_58 ,
V_51 , 1 , L_21 , - 1 , L_51 , L_50 ) ;
V_41 = F_26 ( V_82 ) ;
V_58 += F_61 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 ,
V_41 ,
1 ,
false ) ;
if ( V_375 && F_91 ( V_6 , V_17 ) )
F_33 ( V_6 , L_52 ) ;
return V_58 ;
}
static T_1 F_92 ( struct V_5 * V_6 ,
struct V_16 * V_17 , T_1 * V_50 , bool V_51 )
{
T_1 V_58 = 0 , V_381 , V_382 ;
char V_346 [ 32 ] ;
T_2 V_383 ;
for ( V_383 = 0 ; V_383 < F_93 ( V_384 ) ; V_383 ++ ) {
T_1 V_385 , V_386 , V_387 , V_388 ;
struct V_389 * V_389 ;
T_2 * V_390 ;
V_389 = & V_384 [ V_383 ] ;
V_385 = V_389 -> V_391 +
V_389 -> V_392 ;
V_386 = V_389 -> V_391 +
V_389 -> V_393 ;
V_387 = V_389 -> V_391 +
V_389 -> V_394 ;
V_388 = V_389 -> V_391 +
V_389 -> V_395 ;
V_390 = ( T_2 * ) ( V_50 + V_58 ) ;
if ( snprintf ( V_346 , sizeof( V_346 ) , L_53 ,
V_389 -> V_396 ) < 0 )
F_33 ( V_6 ,
L_54 ) ;
V_58 += F_73 ( V_6 ,
V_50 + V_58 ,
V_51 ,
V_346 ,
0 ,
V_397 ,
16 , true , V_346 , false , 0 ) ;
if ( ! V_51 ) {
V_58 += V_397 ;
continue;
}
for ( V_382 = 0 ;
V_382 < ( V_398 >> 8 ) ;
V_382 ++ ) {
F_43 ( V_6 , V_17 , V_386 , V_382 ) ;
for ( V_381 = 0 ; V_381 < 256 ;
V_381 ++ ) {
F_43 ( V_6 ,
V_17 , V_385 , V_381 ) ;
* ( V_390 ++ ) = ( T_2 ) F_27 ( V_6 ,
V_17 ,
V_387 ) ;
* ( V_390 ++ ) = ( T_2 ) F_27 ( V_6 ,
V_17 ,
V_388 ) ;
}
}
V_58 += V_397 ;
}
return V_58 ;
}
static void F_94 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
enum V_32 V_32 ,
T_2 V_399 ,
T_2 V_400 ,
T_2 V_401 ,
T_2 V_402 , T_2 V_403 )
{
struct V_104 * V_105 = V_106 [ V_32 ] ;
F_43 ( V_6 , V_17 , V_105 -> V_404 , V_399 ) ;
F_43 ( V_6 , V_17 , V_105 -> V_405 , V_400 ) ;
F_43 ( V_6 , V_17 , V_105 -> V_406 , V_401 ) ;
F_43 ( V_6 , V_17 , V_105 -> V_407 , V_402 ) ;
F_43 ( V_6 , V_17 , V_105 -> V_408 , V_403 ) ;
}
static T_1 F_95 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 , bool V_51 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
T_1 V_32 , V_399 , V_58 = 0 ;
if ( F_27 ( V_6 , V_17 , V_111 ) )
return 0 ;
if ( V_51 ) {
F_67 ( V_6 ,
V_244 , L_55 ) ;
for ( V_32 = 0 ; V_32 < V_103 ; V_32 ++ ) {
struct V_104 * V_105 = V_106 [ V_32 ] ;
if ( V_105 -> V_409 [ V_10 -> V_21 ] )
F_43 ( V_6 , V_17 , V_105 -> V_405 ,
0 ) ;
}
F_44 ( V_6 , V_17 ) ;
F_45 ( V_6 ,
V_17 , V_410 ) ;
F_43 ( V_6 ,
V_17 , V_411 , V_412 ) ;
F_43 ( V_6 , V_17 , V_413 , 1 ) ;
F_42 ( V_6 , V_17 , true ) ;
}
for ( V_32 = 0 ; V_32 < V_103 ; V_32 ++ ) {
struct V_104 * V_105 = V_106 [ V_32 ] ;
struct V_31 * V_414 ;
T_1 V_415 , V_41 , V_210 ;
T_2 V_416 ;
if ( ! V_105 -> V_409 [ V_10 -> V_21 ] )
continue;
V_414 =
F_23 ( V_6 ,
(enum V_32 ) V_32 ) ;
V_415 = F_96 ( V_414 ) *
V_417 ;
V_58 += F_73 ( V_6 ,
V_50 + V_58 ,
V_51 ,
V_105 -> V_90 ,
0 ,
V_415 ,
32 , false , L_56 , false , 0 ) ;
if ( ! V_51 ) {
V_58 += V_415 ;
continue;
}
if ( V_10 -> V_66 [ V_32 ] ) {
memset ( V_50 + V_58 , 0 ,
F_25 ( V_415 ) ) ;
V_58 += V_415 ;
continue;
}
V_416 = V_105 -> V_416 [ V_10 -> V_21 ] ;
F_46 ( V_6 ,
V_17 ,
F_41 ( V_416 ) ) ;
V_41 = F_26 ( V_418 ) ;
V_210 = V_417 ;
for ( V_399 = 0 ; V_399 < ( T_1 ) F_96 ( V_414 ) ;
V_399 ++ ) {
F_94 ( V_6 ,
V_17 ,
(enum V_32 ) V_32 ,
( T_2 ) V_399 , 0xf , 0 , 0 , 0 ) ;
V_58 += F_59 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 ,
V_41 ,
V_210 ,
true ) ;
}
F_46 ( V_6 , V_17 , 0 ) ;
F_43 ( V_6 , V_17 , V_105 -> V_405 , 0 ) ;
}
if ( V_51 ) {
F_42 ( V_6 , V_17 , false ) ;
F_46 ( V_6 , V_17 , 0 ) ;
}
return V_58 ;
}
static enum V_15 F_97 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 ,
bool V_51 , T_1 * V_419 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
bool V_420 = false ;
T_2 V_42 , V_421 = 0 ;
T_1 V_58 = 0 ;
* V_419 = 0 ;
if ( V_51 ) {
switch ( F_27 ( V_6 , V_17 , V_422 ) ) {
case 0 :
V_421 = 1 ;
break;
case 1 :
V_421 = 2 ;
break;
case 2 :
V_421 = 4 ;
break;
}
F_40 ( V_6 , V_17 ) ;
}
V_58 += F_37 ( V_6 ,
V_17 ,
V_50 + V_58 , V_51 , 4 ) ;
V_58 += F_30 ( V_50 + V_58 ,
V_51 , L_57 , L_58 ) ;
V_58 += F_31 ( V_50 + V_58 ,
V_51 ,
L_59 ,
F_17 ( V_6 ,
V_298 ) ) ;
V_58 += F_31 ( V_50 + V_58 ,
V_51 ,
L_60 ,
F_17 ( V_6 ,
V_300 ) ) ;
V_58 += F_31 ( V_50 + V_58 ,
V_51 , L_61 , V_421 ) ;
if ( F_48 ( V_6 , V_423 ) )
V_58 += F_70 ( V_6 ,
V_17 ,
V_50 + V_58 , V_51 ) ;
if ( V_51 ) {
F_53 ( V_6 , V_17 ) ;
F_40 ( V_6 , V_17 ) ;
}
if ( V_51 &&
! F_17 ( V_6 , V_376 ) ) {
V_420 = ! F_98 ( V_6 , V_17 , 1 ) ;
if ( ! V_420 ) {
F_33 ( V_6 ,
L_62 ) ;
if ( F_17
( V_6 , V_424 ) )
return V_425 ;
}
}
if ( F_48 ( V_6 , V_423 ) )
V_58 += F_71 ( V_6 ,
V_17 ,
V_50 + V_58 , V_51 ) ;
if ( V_51 &&
( F_48 ( V_6 ,
V_177 ) ||
F_48 ( V_6 , V_426 ) ) )
F_51 ( V_6 , V_17 , true ) ;
if ( F_48 ( V_6 , V_423 ) ) {
bool V_221 [ V_103 ] ;
for ( V_42 = 0 ; V_42 < V_103 ; V_42 ++ )
V_221 [ V_42 ] = true ;
V_221 [ V_380 ] = false ;
V_58 += F_66 ( V_6 ,
V_17 ,
V_50 +
V_58 ,
V_51 ,
V_221 , NULL , NULL ) ;
V_58 += F_72 ( V_6 ,
V_17 ,
V_50 + V_58 , V_51 ) ;
}
V_58 += F_76 ( V_6 , V_17 , V_50 + V_58 , V_51 ) ;
if ( F_48 ( V_6 , V_427 ) )
V_58 += F_89 ( V_6 ,
V_17 , V_50 + V_58 , V_51 ) ;
if ( F_48 ( V_6 , V_428 ) )
V_58 += F_78 ( V_6 ,
V_17 , V_50 + V_58 , V_51 ) ;
if ( F_48 ( V_6 , V_429 ) )
V_58 += F_87 ( V_6 ,
V_17 , V_50 + V_58 , V_51 ) ;
for ( V_42 = 0 ; V_42 < V_136 ; V_42 ++ )
if ( F_48 ( V_6 , V_139 [ V_42 ] . V_8 ) )
V_58 += F_88 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 , V_42 ) ;
if ( F_48 ( V_6 , V_177 ) )
V_58 += F_79 ( V_6 ,
V_17 , V_50 + V_58 , V_51 ) ;
if ( F_48 ( V_6 , V_426 ) )
V_58 += F_86 ( V_6 ,
V_17 , V_50 + V_58 , V_51 ) ;
if ( F_48 ( V_6 ,
V_430 ) && V_10 -> V_21 ==
V_22 && V_10 -> V_28 == V_29 )
V_58 += F_92 ( V_6 ,
V_17 , V_50 + V_58 , V_51 ) ;
if ( F_48 ( V_6 ,
V_431 ) &&
V_10 -> V_432 . V_433 == V_434 )
V_58 += F_95 ( V_6 ,
V_17 ,
V_50 + V_58 , V_51 ) ;
V_58 += F_38 ( V_6 , V_50 , V_58 , V_51 ) ;
if ( V_51 ) {
if ( F_17 ( V_6 , V_435 ) )
F_51 ( V_6 , V_17 , false ) ;
F_56 ( V_6 , V_17 ) ;
if ( V_420 )
F_98 ( V_6 , V_17 , 0 ) ;
}
* V_419 = V_58 ;
return V_19 ;
}
static T_1 F_99 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 *
V_50 ,
bool V_51 ,
T_3 V_436 ,
const struct V_437 * V_438 ,
T_3 V_439 , T_1 * V_440 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
const struct V_441 * V_442 ;
const struct V_443 * V_444 ;
T_1 V_42 , V_445 = 0 , V_58 = 0 ;
struct V_446 * V_251 ;
const union V_447 * V_448 ;
T_2 V_449 ;
V_251 = (struct V_446 * ) V_50 ;
V_448 = & ( ( const union V_447 * )
V_127 [ V_450 ] . V_125 ) [ V_438 -> V_217 ] ;
V_442 = & V_448 [ 0 ] . V_451 ;
V_444 = & V_448 [ V_438 -> V_452 ] . V_453 ;
if ( V_51 ) {
memset ( V_251 , 0 , sizeof( * V_251 ) ) ;
V_251 -> V_436 = V_436 ;
V_251 -> V_454 = V_439 ;
V_251 -> V_455 = V_438 -> V_455 ;
V_251 -> V_456 = V_438 -> V_452 ;
}
V_58 += V_457 ;
for ( V_449 = 0 ; V_449 < V_438 -> V_452 ; V_449 ++ ) {
const struct V_441 * V_230 = & V_442 [ V_449 ] ;
struct V_458 * V_459 ;
V_459 = (struct V_458 * )
( V_50 + V_58 ) ;
if ( ! V_51 ) {
V_58 += V_460 +
V_230 -> V_461 ;
continue;
}
V_58 += V_460 ;
memset ( V_459 , 0 , sizeof( * V_459 ) ) ;
V_459 -> V_462 = V_230 -> V_462 ;
V_459 -> V_48 = V_230 -> V_461 ;
F_100 ( V_459 -> V_203 ,
V_463 ,
V_230 -> V_283 > 1 || V_230 -> V_462 > 0 ? 1 : 0 ) ;
F_100 ( V_459 -> V_203 ,
V_464 , V_449 ) ;
for ( V_42 = 0 ; V_42 < V_459 -> V_48 ; V_42 ++ , V_445 ++ , V_58 ++ )
V_50 [ V_58 ] = V_440 [ V_445 ] ;
}
for ( V_449 = 0 ; V_449 < V_438 -> V_465 ; V_449 ++ ) {
const struct V_443 * V_230 = & V_444 [ V_449 ] ;
T_1 V_32 ;
if ( ! V_51 ) {
V_58 += V_460 + V_230 -> V_48 ;
continue;
}
V_32 = F_57 ( V_230 -> V_203 , V_466 ) ;
if ( V_32 >= V_103 ) {
F_33 ( V_6 , L_63 ) ;
return 0 ;
}
if ( ! V_10 -> V_66 [ V_32 ] ) {
struct V_458 * V_459 ;
bool V_211 , V_202 , V_224 = true ;
T_3 V_122 ;
T_1 V_41 ;
V_459 = (struct V_458 * )
( V_50 + V_58 ) ;
V_202 = F_57 ( V_230 -> V_118 . V_203 ,
V_204 ) > 0 ;
if ( V_202 ) {
V_122 =
F_57 ( V_230 -> V_118 . V_203 ,
V_205 ) ;
V_224 =
F_47 ( V_6 ,
& V_122 ) ;
}
if ( ! V_224 )
continue;
V_41 = F_57 ( V_230 -> V_203 ,
V_467 ) ;
V_211 = F_57 ( V_230 -> V_203 ,
V_468 ) ;
V_58 += V_460 ;
V_251 -> V_469 ++ ;
memset ( V_459 , 0 , sizeof( * V_459 ) ) ;
V_459 -> V_48 = V_230 -> V_48 ;
F_100 ( V_459 -> V_203 ,
V_464 ,
V_438 -> V_452 + V_449 ) ;
V_58 += F_59 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 ,
V_41 ,
V_230 -> V_48 , V_211 ) ;
}
}
return V_58 ;
}
static T_1
F_101 ( struct V_5 * V_6 , struct V_16 * V_17 ,
T_1 * V_50 , bool V_51 ,
const struct V_437 * V_470 ,
T_1 V_471 , T_1 * V_472 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
T_1 V_440 [ V_473 ] ;
T_1 V_42 , V_58 = 0 ;
T_3 V_474 ;
T_2 V_449 ;
* V_472 = 0 ;
for ( V_42 = 0 ; V_42 < V_471 ; V_42 ++ ) {
const struct V_441 * V_442 ;
const struct V_437 * V_438 ;
const union V_447 * V_448 ;
T_3 V_207 = 1 ;
bool V_475 = true ;
const T_1 * V_476 ;
V_438 = & V_470 [ V_42 ] ;
V_448 = & ( ( const union V_447 * )
V_127 [ V_450 ] . V_125 )
[ V_438 -> V_217 ] ;
V_442 = & V_448 [ 0 ] . V_451 ;
V_476 = & V_127 [ V_477 ] . V_125
[ V_438 -> V_478 ] ;
for ( V_449 = 0 ; V_449 < V_438 -> V_452 && V_475 ;
V_449 ++ ) {
T_1 V_32 =
F_57 ( V_442 [ V_449 ] . V_203 ,
V_479 ) ;
if ( V_32 >= V_103 ) {
F_33 ( V_6 , L_63 ) ;
return 0 ;
}
V_475 = ! V_10 -> V_66 [ V_32 ] ;
if ( V_442 [ V_449 ] . V_283 > V_207 )
V_207 = V_442 [ V_449 ] . V_283 ;
}
if ( ! V_475 && V_51 )
continue;
for ( V_474 = 0 ; V_474 < V_207 ; V_474 ++ ) {
T_1 V_445 = 0 ;
if ( ! V_51 ) {
V_58 += F_99 ( V_6 ,
V_17 ,
V_50 + V_58 ,
false ,
V_438 -> V_436 ,
V_438 ,
V_474 ,
NULL ) ;
( * V_472 ) ++ ;
break;
}
for ( V_449 = 0 ; V_449 < V_438 -> V_452 ;
V_449 ++ ) {
const struct V_441 * V_230 =
& V_442 [ V_449 ] ;
T_1 V_480 , V_41 ;
bool V_211 ;
V_41 = F_57 ( V_230 -> V_203 ,
V_481 ) ;
V_211 =
F_57 ( V_230 -> V_203 ,
V_482 ) ;
if ( V_230 -> V_283 > 1 ||
V_230 -> V_462 > 0 ) {
V_480 =
V_230 -> V_461 > 1 ?
F_102 ( V_230 -> V_461 )
: 1 ;
V_41 += ( V_230 -> V_462 + V_474 ) *
V_480 ;
}
if ( V_445 + V_230 -> V_461 >=
V_473 ) {
F_33 ( V_6 ,
L_64 ) ;
return 0 ;
}
V_445 +=
F_59 ( V_6 , V_17 ,
V_440 +
V_445 ,
V_51 , V_41 ,
V_230 -> V_461 ,
V_211 ) ;
}
if ( (* F_103 [ V_438 -> V_483 ]) ( V_440 ,
V_476 ) ) {
V_58 += F_99 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 ,
V_438 -> V_436 ,
V_438 ,
V_474 ,
V_440 ) ;
( * V_472 ) ++ ;
break;
}
}
}
return V_58 ;
}
static T_1 F_104 ( struct V_5 * V_6 ,
struct V_16 * V_17 , T_1 * V_50 , bool V_51 )
{
T_1 V_484 , V_58 = 0 , V_223 = 0 ;
T_1 V_472 = 0 ;
V_58 += F_37 ( V_6 ,
V_17 ,
V_50 + V_58 , V_51 , 1 ) ;
V_58 += F_30 ( V_50 + V_58 ,
V_51 , L_57 , L_65 ) ;
V_58 += F_36 ( V_50 + V_58 , V_51 , L_66 , 1 ) ;
V_484 = V_58 ;
V_58 += F_31 ( V_50 + V_58 , V_51 , L_67 , 0 ) ;
while ( V_223 <
V_127 [ V_485 ] . V_225 ) {
const struct V_486 * V_227 =
( const struct V_486 * )
& V_127 [ V_485 ] . V_125
[ V_223 ++ ] ;
bool V_202 , V_224 = true ;
T_1 V_487 ;
T_3 V_122 ;
V_202 = F_57 ( V_227 -> V_118 . V_203 ,
V_204 ) > 0 ;
if ( V_202 ) {
V_122 =
F_57 ( V_227 -> V_118 . V_203 ,
V_205 ) ;
V_224 = F_47 ( V_6 ,
& V_122 ) ;
}
if ( V_224 ) {
V_58 +=
F_101 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 ,
( const struct V_437 * )
& V_127 [ V_485 ] .
V_125 [ V_223 ] ,
V_227 -> V_228 / V_488 ,
& V_487 ) ;
V_472 += V_487 ;
}
V_223 += V_227 -> V_228 ;
}
if ( V_51 )
F_31 ( V_50 + V_484 ,
V_51 , L_67 , V_472 ) ;
V_58 += F_38 ( V_6 , V_50 , V_58 , V_51 ) ;
return V_58 ;
}
static enum V_15 F_105 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 V_489 ,
T_1 * V_490 ,
T_1 * V_491 )
{
T_1 V_492 , V_493 , V_494 ;
struct V_495 V_496 ;
int V_497 ;
V_497 = F_106 ( V_6 ,
V_17 ,
V_498 ,
V_489 ,
& V_492 ,
& V_493 ,
& V_494 , ( T_1 * ) & V_496 ) ;
if ( V_497 ||
( V_492 & V_499 ) != V_500 )
return V_501 ;
* V_490 = V_496 . V_502 ;
* V_491 = V_496 . V_210 ;
F_67 ( V_6 ,
V_244 ,
L_68 ,
V_489 , * V_490 , * V_491 ) ;
if ( * V_491 & 0x3 )
return V_503 ;
return V_19 ;
}
static enum V_15 F_107 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 V_490 ,
T_1 V_491 , T_1 * V_504 )
{
T_1 V_492 , V_493 , V_505 , V_506 ;
T_4 V_507 = V_491 ;
T_1 V_508 = 0 ;
F_67 ( V_6 ,
V_244 ,
L_69 ,
V_491 ) ;
do {
V_506 =
( V_507 >
V_509 ) ? V_509 : V_507 ;
if ( F_106 ( V_6 , V_17 ,
V_510 ,
( V_490 +
V_508 ) |
( V_506 <<
V_511 ) ,
& V_492 , & V_493 ,
& V_505 ,
( T_1 * ) ( ( T_2 * ) V_504 + V_508 ) ) )
return V_512 ;
if ( ( V_492 & V_499 ) != V_500 )
return V_512 ;
V_508 += V_505 ;
V_507 -= V_505 ;
} while ( V_507 > 0 );
return V_19 ;
}
static enum V_15 F_108 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_513 ,
T_1 * V_514 )
{
T_1 V_515 , V_516 ;
V_515 = F_27 ( V_6 , V_17 , V_517 ) ;
* V_513 =
V_83 + F_109 ( V_515 ) ;
V_516 = F_27 ( V_6 , V_17 ,
* V_513 +
F_35 ( struct V_518 , V_516 ) ) ;
if ( V_516 != V_519 )
return V_520 ;
* V_514 = F_27 ( V_6 ,
V_17 ,
* V_513 +
F_35 ( struct V_518 , V_48 ) ) ;
return V_19 ;
}
static enum V_15 F_110 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 V_521 ,
T_1 * V_522 ,
T_1 * V_523 ,
T_1 * V_524 )
{
T_1 V_515 , V_525 , V_526 ;
V_515 = F_27 ( V_6 , V_17 , V_517 ) ;
V_526 =
V_83 + F_109 ( V_515 ) +
F_111 ( V_515 ) + V_521 ;
* V_522 = F_27 ( V_6 , V_17 , V_526 ) ;
if ( * V_522 > 1 )
return V_527 ;
V_525 =
( * V_522 ==
V_528 ) ? V_529 : V_530 ;
return F_105 ( V_6 ,
V_17 ,
V_525 ,
V_523 , V_524 ) ;
}
static enum V_15 F_112 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 V_531 ,
T_1 V_532 , T_1 * V_3 )
{
T_2 V_533 , V_534 , V_42 , * V_535 = ( T_2 * ) V_3 ;
enum V_15 V_536 ;
T_1 V_516 ;
V_536 = F_107 ( V_6 ,
V_17 ,
V_531 , V_532 , V_3 ) ;
if ( V_536 != V_19 )
return V_536 ;
V_516 = F_16 ( V_535 ) ;
V_535 += sizeof( V_516 ) ;
if ( V_516 != V_537 )
return V_520 ;
V_533 = * ( V_535 ++ ) ;
for ( V_42 = 0 ; V_42 < V_533 ; V_42 ++ ) {
V_534 = * ( V_535 ++ ) ;
V_535 += V_534 ;
}
V_516 = F_16 ( V_535 ) ;
V_535 += sizeof( V_516 ) ;
if ( V_516 != V_537 )
return V_520 ;
return V_19 ;
}
static enum V_15 F_113 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 ,
bool V_51 , T_1 * V_419 )
{
T_1 V_513 , V_521 , V_538 ;
T_1 V_539 = 0 , V_522 , V_58 = 0 ;
T_1 V_540 = 0 , V_541 = 0 ;
enum V_15 V_536 ;
bool V_542 ;
int V_375 = 0 ;
* V_419 = 0 ;
V_542 = ! F_17 ( V_6 , V_376 ) ;
V_536 = F_108 ( V_6 ,
V_17 ,
& V_513 ,
& V_521 ) ;
if ( V_536 != V_19 )
return V_536 ;
V_58 += F_37 ( V_6 ,
V_17 ,
V_50 + V_58 , V_51 , 1 ) ;
V_58 += F_30 ( V_50 + V_58 ,
V_51 , L_57 , L_70 ) ;
if ( V_51 && V_542 ) {
V_375 = ! F_90 ( V_6 , V_17 ) ;
if ( ! V_375 )
F_33 ( V_6 , L_49 ) ;
}
V_538 =
F_114 ( V_521 + sizeof( struct V_518 ) ,
V_47 ) ;
V_58 += F_36 ( V_50 + V_58 ,
V_51 , L_71 , 1 ) ;
V_58 += F_31 ( V_50 + V_58 ,
V_51 , L_72 , V_538 ) ;
V_58 += F_59 ( V_6 ,
V_17 ,
V_50 + V_58 ,
V_51 ,
F_26 ( V_513 ) ,
V_538 , false ) ;
if ( V_375 && F_91 ( V_6 , V_17 ) )
F_33 ( V_6 , L_52 ) ;
V_58 += F_36 ( V_50 + V_58 ,
V_51 , L_73 , 1 ) ;
if ( V_542 ) {
V_536 = F_110 ( V_6 ,
V_17 ,
V_521 ,
& V_522 ,
& V_540 ,
& V_541 ) ;
if ( V_536 == V_19 )
V_539 =
F_26 ( V_541 ) ;
}
V_58 += F_31 ( V_50 + V_58 ,
V_51 , L_72 , V_539 ) ;
if ( V_51 && V_539 )
V_536 = F_112 ( V_6 ,
V_17 ,
V_540 ,
V_541 ,
V_50 + V_58 ) ;
if ( V_536 == V_19 )
V_58 += V_539 ;
V_58 += F_38 ( V_6 , V_50 , V_58 , V_51 ) ;
* V_419 = V_58 ;
return V_542 ? V_536 : V_501 ;
}
static enum V_15 F_115 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 ,
bool V_51 , T_1 * V_419 )
{
T_1 V_543 , V_544 , V_58 = 0 ;
bool V_545 ;
* V_419 = 0 ;
V_58 += F_37 ( V_6 ,
V_17 ,
V_50 + V_58 , V_51 , 1 ) ;
V_58 += F_30 ( V_50 + V_58 ,
V_51 , L_57 , L_74 ) ;
V_58 += F_36 ( V_50 + V_58 ,
V_51 , L_75 , 1 ) ;
V_544 = V_58 ;
V_58 += F_31 ( V_50 + V_58 , V_51 , L_72 , 0 ) ;
if ( ! V_51 ) {
V_58 += V_546 ;
goto V_547;
}
V_545 = F_27 ( V_6 , V_17 ,
V_548 ) > 0 ;
for ( V_543 = 0 ;
V_545 && V_543 < V_546 ;
V_543 += V_549 , V_58 +=
V_549 ) {
if ( F_116 ( V_6 , V_17 , V_550 ,
( V_551 ) ( V_552 ) ( & V_50 [ V_58 ] ) ,
V_549 , 0 ) )
return V_553 ;
V_545 = F_27 ( V_6 , V_17 ,
V_548 ) > 0 ;
}
F_31 ( V_50 + V_544 , V_51 , L_72 ,
V_543 ) ;
V_547:
V_58 += F_38 ( V_6 , V_50 , V_58 , V_51 ) ;
* V_419 = V_58 ;
return V_19 ;
}
static enum V_15 F_117 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 ,
bool V_51 , T_1 * V_419 )
{
T_1 V_543 , V_544 , V_58 = 0 ;
bool V_545 ;
* V_419 = 0 ;
V_58 += F_37 ( V_6 ,
V_17 ,
V_50 + V_58 , V_51 , 1 ) ;
V_58 += F_30 ( V_50 + V_58 ,
V_51 , L_57 , L_76 ) ;
V_58 += F_36 ( V_50 + V_58 ,
V_51 , L_77 , 1 ) ;
V_544 = V_58 ;
V_58 += F_31 ( V_50 + V_58 , V_51 , L_72 , 0 ) ;
if ( ! V_51 ) {
V_58 += V_554 ;
goto V_547;
}
V_545 = F_27 ( V_6 , V_17 ,
V_555 ) > 0 ;
for ( V_543 = 0 ;
V_545 && V_543 < V_554 ;
V_543 += V_556 , V_58 +=
V_556 ) {
if ( F_116 ( V_6 , V_17 ,
V_557 ,
( V_551 ) ( V_552 ) ( & V_50 [ V_58 ] ) ,
V_556 , 0 ) )
return V_553 ;
V_545 = F_27 ( V_6 , V_17 ,
V_555 ) > 0 ;
}
F_31 ( V_50 + V_544 , V_51 , L_72 ,
V_543 ) ;
V_547:
V_58 += F_38 ( V_6 , V_50 , V_58 , V_51 ) ;
* V_419 = V_58 ;
return V_19 ;
}
static enum V_15 F_118 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 ,
bool V_51 ,
T_1 * V_419 )
{
T_1 V_544 , V_558 , V_58 = 0 ;
* V_419 = 0 ;
V_58 += F_37 ( V_6 ,
V_17 ,
V_50 + V_58 , V_51 , 1 ) ;
V_58 += F_30 ( V_50 + V_58 ,
V_51 , L_57 , L_78 ) ;
V_58 += F_36 ( V_50 + V_58 ,
V_51 , L_79 , 1 ) ;
V_544 = V_58 ;
V_58 += F_31 ( V_50 + V_58 , V_51 , L_72 , 0 ) ;
if ( ! V_51 ) {
V_58 += V_559 ;
goto V_547;
}
V_558 =
F_27 ( V_6 , V_17 ,
V_560 ) *
V_561 ;
if ( F_116 ( V_6 , V_17 ,
V_562 ,
( V_551 ) ( V_552 ) ( V_50 + V_58 ) ,
V_558 , 0 ) )
return V_553 ;
V_58 += V_558 ;
F_31 ( V_50 + V_544 , V_51 , L_72 ,
V_558 ) ;
V_547:
V_58 += F_38 ( V_6 , V_50 , V_58 , V_51 ) ;
* V_419 = V_58 ;
return V_19 ;
}
static T_1 F_119 ( struct V_5 * V_6 ,
struct V_16 * V_17 , T_1 * V_50 , bool V_51 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
struct V_563 * V_564 ;
char V_565 [ 2 ] = L_80 ;
struct V_36 V_36 ;
T_1 V_58 = 0 ;
T_2 V_35 ;
V_58 += F_37 ( V_6 ,
V_17 ,
V_50 + V_58 , V_51 , 1 ) ;
V_58 += F_30 ( V_50 + V_58 ,
V_51 , L_57 , L_81 ) ;
for ( V_35 = 0 ; V_35 < V_65 ; V_35 ++ ) {
T_1 V_566 , V_567 , V_568 ;
struct V_37 * V_38 = & V_39 [ V_35 ] ;
T_1 V_569 , V_41 ;
if ( V_10 -> V_66 [ V_38 -> V_32 ] )
continue;
F_24 ( V_6 , V_17 , V_35 , & V_36 ) ;
V_564 = & V_36 . V_570 ;
V_565 [ 0 ] = V_38 -> V_301 ;
V_58 += F_36 ( V_50 + V_58 ,
V_51 , L_82 , 2 ) ;
V_58 += F_30 ( V_50 + V_58 ,
V_51 , L_83 , V_565 ) ;
V_58 += F_31 ( V_50 + V_58 ,
V_51 ,
L_72 ,
V_564 -> V_571 ) ;
if ( ! V_51 ) {
V_58 += V_564 -> V_571 ;
continue;
}
V_566 = V_38 -> V_44 +
V_45 +
F_120 ( V_564 -> V_572 ) ;
V_567 = V_566 +
F_25 ( V_564 -> V_573 ) ;
V_568 = F_27 ( V_6 , V_17 , V_567 ) ;
V_569 = ( V_568 > 0
? V_568
: V_564 -> V_574 ) - 1 ;
V_41 = F_26 ( V_566 ) +
V_564 -> V_575 +
V_569 * V_564 -> V_571 ;
V_58 +=
F_59 ( V_6 , V_17 ,
V_50 + V_58 ,
V_51 , V_41 ,
V_564 -> V_571 ,
false ) ;
}
V_58 += F_38 ( V_6 , V_50 , V_58 , V_51 ) ;
return V_58 ;
}
enum V_15 F_121 ( const T_2 * const V_576 )
{
struct V_577 * V_578 = (struct V_577 * ) V_576 ;
T_2 V_579 ;
for ( V_579 = 0 ; V_579 < V_580 ; V_579 ++ ) {
V_127 [ V_579 ] . V_125 =
( T_1 * ) ( V_576 + V_578 [ V_579 ] . V_58 ) ;
V_127 [ V_579 ] . V_225 =
F_26 ( V_578 [ V_579 ] . V_581 ) ;
}
return V_19 ;
}
void F_19 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
T_1 V_42 ;
for ( V_42 = 0 ; V_42 < V_582 ; V_42 ++ )
V_10 -> V_12 . V_13 [ V_42 ] =
V_583 [ V_42 ] . V_584 [ V_10 -> V_21 ] ;
}
enum V_15 F_122 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_585 )
{
enum V_15 V_536 = F_20 ( V_6 , V_17 ) ;
* V_585 = 0 ;
if ( V_536 != V_19 )
return V_536 ;
if ( ! V_127 [ V_128 ] . V_125 ||
! V_127 [ V_245 ] . V_125 ||
! V_127 [ V_303 ] . V_125 ||
! V_127 [ V_190 ] . V_125 ||
! V_127 [ V_196 ] . V_125 )
return V_586 ;
return F_97 ( V_6 , V_17 , NULL , false , V_585 ) ;
}
enum V_15 F_123 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 ,
T_1 V_587 ,
T_1 * V_419 )
{
T_1 V_588 ;
enum V_15 V_536 ;
* V_419 = 0 ;
V_536 = F_122 ( V_6 ,
V_17 ,
& V_588 ) ;
if ( V_536 != V_19 )
return V_536 ;
if ( V_587 < V_588 )
return V_589 ;
V_536 = F_97 ( V_6 , V_17 , V_50 , true , V_419 ) ;
F_19 ( V_6 ) ;
return V_536 ;
}
enum V_15 F_124 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_585 )
{
struct V_9 * V_10 = & V_6 -> V_11 ;
struct V_590 * V_591 ;
enum V_15 V_536 ;
V_591 = & V_10 -> V_591 ;
* V_585 = 0 ;
V_536 = F_20 ( V_6 , V_17 ) ;
if ( V_536 != V_19 )
return V_536 ;
if ( ! V_127 [ V_128 ] . V_125 ||
! V_127 [ V_450 ] . V_125 ||
! V_127 [ V_477 ] . V_125 ||
! V_127 [ V_485 ] . V_125 )
return V_586 ;
if ( ! V_591 -> V_592 ) {
V_591 -> V_585 = F_104 ( V_6 ,
V_17 , NULL , false ) ;
V_591 -> V_592 = true ;
}
* V_585 = V_591 -> V_585 ;
return V_19 ;
}
enum V_15 F_125 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 ,
T_1 V_587 ,
T_1 * V_419 )
{
T_1 V_588 ;
enum V_15 V_536 ;
* V_419 = 0 ;
V_536 = F_124 ( V_6 ,
V_17 ,
& V_588 ) ;
if ( V_536 != V_19 )
return V_536 ;
if ( V_587 < V_588 )
return V_589 ;
F_40 ( V_6 , V_17 ) ;
* V_419 = F_104 ( V_6 , V_17 , V_50 , true ) ;
F_19 ( V_6 ) ;
return V_19 ;
}
enum V_15 F_126 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_585 )
{
enum V_15 V_536 = F_20 ( V_6 , V_17 ) ;
* V_585 = 0 ;
if ( V_536 != V_19 )
return V_536 ;
return F_113 ( V_6 , V_17 , NULL , false , V_585 ) ;
}
enum V_15 F_127 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 ,
T_1 V_587 ,
T_1 * V_419 )
{
T_1 V_588 ;
enum V_15 V_536 ;
V_536 =
F_126 ( V_6 ,
V_17 ,
& V_588 ) ;
if ( V_536 != V_19 && V_536 !=
V_501 )
return V_536 ;
if ( V_587 < V_588 )
return V_589 ;
F_40 ( V_6 , V_17 ) ;
V_536 = F_113 ( V_6 ,
V_17 , V_50 , true , V_419 ) ;
F_19 ( V_6 ) ;
return V_536 ;
}
enum V_15 F_128 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_585 )
{
enum V_15 V_536 = F_20 ( V_6 , V_17 ) ;
* V_585 = 0 ;
if ( V_536 != V_19 )
return V_536 ;
return F_115 ( V_6 , V_17 , NULL , false , V_585 ) ;
}
enum V_15 F_129 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 ,
T_1 V_587 ,
T_1 * V_419 )
{
T_1 V_588 ;
enum V_15 V_536 ;
* V_419 = 0 ;
V_536 = F_128 ( V_6 ,
V_17 ,
& V_588 ) ;
if ( V_536 != V_19 )
return V_536 ;
if ( V_587 < V_588 )
return V_589 ;
F_40 ( V_6 , V_17 ) ;
V_536 = F_115 ( V_6 ,
V_17 , V_50 , true , V_419 ) ;
F_19 ( V_6 ) ;
return V_536 ;
}
enum V_15 F_130 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_585 )
{
enum V_15 V_536 = F_20 ( V_6 , V_17 ) ;
* V_585 = 0 ;
if ( V_536 != V_19 )
return V_536 ;
return F_117 ( V_6 , V_17 , NULL , false , V_585 ) ;
}
enum V_15 F_131 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 ,
T_1 V_587 ,
T_1 * V_419 )
{
T_1 V_588 ;
enum V_15 V_536 ;
* V_419 = 0 ;
V_536 = F_130 ( V_6 ,
V_17 ,
& V_588 ) ;
if ( V_536 != V_19 )
return V_536 ;
if ( V_587 < V_588 )
return V_589 ;
F_40 ( V_6 , V_17 ) ;
V_536 = F_117 ( V_6 ,
V_17 , V_50 , true , V_419 ) ;
F_19 ( V_6 ) ;
return V_536 ;
}
enum V_15
F_132 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_585 )
{
enum V_15 V_536 = F_20 ( V_6 , V_17 ) ;
* V_585 = 0 ;
if ( V_536 != V_19 )
return V_536 ;
return F_118 ( V_6 ,
V_17 , NULL , false , V_585 ) ;
}
enum V_15 F_133 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 ,
T_1 V_587 ,
T_1 * V_419 )
{
T_1 V_588 , * V_593 = & V_588 ;
enum V_15 V_536 ;
* V_419 = 0 ;
V_536 =
F_132 ( V_6 ,
V_17 ,
V_593 ) ;
if ( V_536 != V_19 )
return V_536 ;
if ( V_587 < V_588 )
return V_589 ;
F_40 ( V_6 , V_17 ) ;
V_536 = F_118 ( V_6 ,
V_17 ,
V_50 ,
true , V_419 ) ;
F_19 ( V_6 ) ;
return V_536 ;
}
enum V_15 F_134 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_585 )
{
enum V_15 V_536 = F_20 ( V_6 , V_17 ) ;
* V_585 = 0 ;
if ( V_536 != V_19 )
return V_536 ;
F_40 ( V_6 , V_17 ) ;
* V_585 = F_119 ( V_6 , V_17 , NULL , false ) ;
return V_19 ;
}
enum V_15 F_135 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
T_1 * V_50 ,
T_1 V_587 ,
T_1 * V_419 )
{
T_1 V_588 , * V_593 = & V_588 ;
enum V_15 V_536 ;
* V_419 = 0 ;
V_536 =
F_134 ( V_6 ,
V_17 ,
V_593 ) ;
if ( V_536 != V_19 )
return V_536 ;
if ( V_587 < V_588 )
return V_589 ;
* V_419 = F_119 ( V_6 , V_17 , V_50 , true ) ;
F_19 ( V_6 ) ;
return V_19 ;
}
enum V_15 F_136 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
enum V_32 V_32 ,
enum V_186 V_187 ,
bool V_594 ,
struct V_595 * V_596 )
{
enum V_15 V_536 = F_20 ( V_6 , V_17 ) ;
T_2 V_199 , V_193 , V_597 = 0 ;
const struct V_192 * V_198 ;
if ( V_536 != V_19 )
return V_536 ;
if ( ! V_127 [ V_128 ] . V_125 ||
! V_127 [ V_190 ] . V_125 ||
! V_127 [ V_196 ] . V_125 )
return V_586 ;
V_198 = F_55 ( V_32 ,
V_187 , & V_193 ) ;
for ( V_199 = 0 ; V_199 < V_193 ; V_199 ++ ) {
const struct V_192 * V_201 = & V_198 [ V_199 ] ;
struct V_598 * V_599 ;
T_1 V_600 , V_601 ;
T_3 V_122 ;
bool V_202 ;
V_202 = F_57 ( V_201 -> V_118 . V_203 ,
V_204 ) > 0 ;
V_122 = F_57 ( V_201 -> V_118 . V_203 ,
V_205 ) ;
if ( V_202 && ! F_47 ( V_6 , & V_122 ) )
continue;
V_600 = F_25 ( V_594 ?
V_201 -> V_206 :
F_57 ( V_201 -> V_203 ,
V_270 ) ) ;
V_601 = F_27 ( V_6 , V_17 , V_600 ) ;
if ( ! V_601 )
continue;
V_599 = & V_596 -> V_602 [ V_597 ] ;
F_100 ( V_599 -> V_203 ,
V_603 , V_600 ) ;
F_100 ( V_599 -> V_203 ,
V_604 ,
F_57 ( V_201 -> V_203 , V_605 ) ) ;
V_599 -> V_606 = V_201 -> V_606 ;
V_599 -> V_601 = V_601 ;
V_599 -> V_607 = F_27 ( V_6 ,
V_17 ,
F_25
( V_201 -> V_269 ) ) ;
V_597 ++ ;
}
V_596 -> V_32 = ( T_2 ) V_32 ;
V_596 -> V_608 =
F_54 ( V_32 , V_187 ) -> V_608 ;
F_100 ( V_596 -> V_203 , V_609 , V_187 ) ;
F_100 ( V_596 -> V_203 ,
V_610 , V_597 ) ;
return V_19 ;
}
static T_1 F_137 ( T_1 V_611 , T_1 V_612 , T_1 V_48 )
{
return ( V_611 + V_612 ) % V_48 ;
}
static T_1 F_138 ( T_1 V_611 , T_1 V_612 , T_1 V_48 )
{
return ( V_48 + V_611 - V_612 ) % V_48 ;
}
static T_1 F_139 ( void * V_3 ,
T_1 * V_58 ,
T_1 V_585 , T_2 V_613 )
{
T_2 V_42 , * V_614 , * V_390 = ( T_2 * ) V_3 ;
T_1 V_615 = 0 ;
V_614 = ( T_2 * ) & V_615 ;
for ( V_42 = 0 ; V_42 < V_613 ; V_42 ++ ) {
V_614 [ V_42 ] = V_390 [ * V_58 ] ;
* V_58 = F_137 ( * V_58 , 1 , V_585 ) ;
}
return V_615 ;
}
static T_2 F_140 ( void * V_3 , T_1 * V_58 )
{
return ( ( T_2 * ) V_3 ) [ ( * V_58 ) ++ ] ;
}
static T_1 F_141 ( void * V_3 , T_1 * V_58 )
{
T_1 V_616 = * ( T_1 * ) & ( ( T_2 * ) V_3 ) [ * V_58 ] ;
* V_58 += 4 ;
return V_616 ;
}
static void F_142 ( void * V_3 , T_1 * V_58 , T_1 V_48 , char * V_43 )
{
const char * V_617 = & ( ( const char * ) V_3 ) [ * V_58 ] ;
strncpy ( V_43 , V_617 , V_48 ) ;
V_43 [ V_48 - 1 ] = '\0' ;
* V_58 += V_48 ;
}
static char * F_143 ( void * V_3 , T_1 V_58 )
{
return V_3 ? ( char * ) V_3 + V_58 : V_618 ;
}
static T_1 F_144 ( T_1 * V_50 ,
const char * * V_56 ,
const char * * V_619 , T_1 * V_620 )
{
char * V_57 = ( char * ) V_50 ;
T_5 V_58 = 0 ;
* V_56 = V_57 ;
V_58 += strlen ( * V_56 ) + 1 ;
if ( * ( V_57 + V_58 ++ ) ) {
* V_619 = V_57 + V_58 ;
V_58 += strlen ( * V_619 ) + 1 ;
if ( V_58 & 0x3 )
V_58 += ( 4 - ( V_58 & 0x3 ) ) ;
} else {
* V_619 = NULL ;
if ( V_58 & 0x3 )
V_58 += ( 4 - ( V_58 & 0x3 ) ) ;
* V_620 = * ( T_1 * ) ( V_57 + V_58 ) ;
V_58 += 4 ;
}
return V_58 / 4 ;
}
static T_1 F_145 ( T_1 * V_50 ,
const char * * V_621 ,
T_1 * V_622 )
{
const char * V_619 ;
return F_144 ( V_50 ,
V_621 , & V_619 , V_622 ) ;
}
static T_1 F_146 ( T_1 * V_50 ,
T_1 V_622 ,
char * V_623 , T_1 * V_624 )
{
T_1 V_42 , V_625 = 0 , V_626 = 0 ;
for ( V_42 = 0 ; V_42 < V_622 ; V_42 ++ ) {
const char * V_56 , * V_619 ;
T_1 V_620 = 0 ;
V_625 += F_144 ( V_50 + V_625 ,
& V_56 ,
& V_619 , & V_620 ) ;
if ( V_619 )
V_626 +=
sprintf ( F_143 ( V_623 ,
V_626 ) ,
L_84 , V_56 , V_619 ) ;
else if ( strcmp ( V_56 , L_7 ) )
V_626 +=
sprintf ( F_143 ( V_623 ,
V_626 ) ,
L_85 , V_56 , V_620 ) ;
}
V_626 += sprintf ( F_143 ( V_623 , V_626 ) ,
L_86 ) ;
* V_624 = V_626 ;
return V_625 ;
}
static T_1 F_147 ( struct V_5 * V_6 ,
T_1 * V_50 ,
T_1 * V_627 ,
T_1 V_628 ,
bool V_629 ,
char * V_623 ,
T_1 * V_630 , T_1 * V_631 )
{
T_1 V_626 = 0 ;
T_1 V_632 ;
T_3 V_42 , V_633 ;
* V_630 = 0 ;
* V_631 = 0 ;
for ( V_632 = 0 ; V_632 < V_628 && V_50 < V_627 ;
V_632 ++ ) {
const struct V_634 * V_635 ;
struct V_446 * V_251 ;
const char * V_636 , * V_637 ;
T_1 V_638 ;
bool V_639 ;
T_2 V_640 ;
V_251 = (struct V_446 * ) V_50 ;
V_635 =
( const struct V_634 * )
& V_641 [ V_642 ] .
V_125 [ V_251 -> V_436 ] ;
V_638 =
F_57 ( V_635 -> V_203 ,
V_643 ) ;
V_639 =
F_57 ( V_635 -> V_203 ,
V_644 ) > 0 ;
V_636 =
& ( ( const char * )
V_641 [ V_645 ] . V_125 )
[ V_638 ] ;
V_637 = V_636 ;
V_640 = 0 ;
if ( V_251 -> V_455 >= V_646 )
return 0 ;
V_50 += F_26 ( sizeof( * V_251 ) ) ;
if ( V_251 -> V_455 == V_647 ||
V_251 -> V_455 == V_648 )
( * V_630 ) ++ ;
else
( * V_631 ) ++ ;
V_626 +=
sprintf ( F_143 ( V_623 ,
V_626 ) , L_87 ,
V_649 [ V_251 -> V_455 ] ) ;
if ( V_639 )
V_636 += strlen ( V_636 ) + 1 ;
V_626 +=
sprintf ( F_143 ( V_623 ,
V_626 ) , L_88 ,
V_639 &&
V_629 ? V_636 : V_637 ) ;
V_636 += strlen ( V_636 ) + 1 ;
V_626 +=
sprintf ( F_143 ( V_623 ,
V_626 ) , L_89 ) ;
for ( V_42 = 0 ;
V_42 < V_251 -> V_456 + V_251 -> V_469 ;
V_42 ++ ) {
struct V_458 * V_459 ;
bool V_650 ;
T_2 V_449 ;
V_459 =
(struct V_458 * ) V_50 ;
V_650 = F_57 ( V_459 -> V_203 ,
V_463 ) ;
V_449 = F_57 ( V_459 -> V_203 ,
V_464 ) ;
V_50 += F_26 ( sizeof( * V_459 ) ) ;
for (; V_449 > V_640 ;
V_640 ++ ,
V_636 += strlen ( V_636 ) + 1 ) ;
V_626 +=
sprintf ( F_143 ( V_623 ,
V_626 ) , L_90 ,
V_636 ) ;
if ( V_42 < V_251 -> V_456 && V_650 )
V_626 +=
sprintf ( F_143 ( V_623 ,
V_626 ) ,
L_91 , V_251 -> V_454 +
V_459 -> V_462 ) ;
V_626 +=
sprintf ( F_143 ( V_623 ,
V_626 ) , L_92 ) ;
for ( V_633 = 0 ; V_633 < V_459 -> V_48 ; V_633 ++ , V_50 ++ ) {
V_626 +=
sprintf ( F_143 ( V_623 ,
V_626 ) ,
L_93 , * V_50 ) ;
if ( V_633 < V_459 -> V_48 - 1 )
V_626 +=
sprintf ( F_143
( V_623 ,
V_626 ) , L_94 ) ;
}
}
V_626 +=
sprintf ( F_143 ( V_623 , V_626 ) , L_86 ) ;
}
if ( V_50 > V_627 )
return 0 ;
return V_626 ;
}
static enum V_15 F_148 ( struct V_5 * V_6 ,
T_1 * V_50 ,
T_1 V_419 ,
char * V_623 ,
T_1 * V_651 ,
T_1 * V_630 ,
T_1 * V_631 )
{
const char * V_621 , * V_56 , * V_619 ;
T_1 * V_627 = V_50 + V_419 ;
T_1 V_622 = 0 , V_628 ;
T_1 V_626 = 0 ;
* V_651 = 0 ;
* V_630 = 0 ;
* V_631 = 0 ;
if ( ! V_641 [ V_645 ] . V_125 ||
! V_641 [ V_642 ] . V_125 )
return V_586 ;
V_50 += F_145 ( V_50 ,
& V_621 , & V_622 ) ;
if ( strcmp ( V_621 , L_10 ) )
return V_652 ;
V_50 += F_146 ( V_50 ,
V_622 ,
V_623 , & V_626 ) ;
V_50 += F_145 ( V_50 ,
& V_621 , & V_622 ) ;
if ( strcmp ( V_621 , L_66 ) || V_622 != 1 )
return V_652 ;
V_50 += F_144 ( V_50 ,
& V_56 , & V_619 , & V_628 ) ;
if ( strcmp ( V_56 , L_67 ) )
return V_652 ;
if ( V_628 ) {
T_1 V_653 ;
V_626 +=
sprintf ( F_143 ( V_623 ,
V_626 ) ,
L_95 ) ;
V_653 =
F_147 ( V_6 , V_50 ,
V_627 , V_628 ,
true ,
V_623 ?
V_623 +
V_626 : NULL ,
V_630 , V_631 ) ;
V_626 += V_653 ;
if ( ! V_653 )
return V_652 ;
V_626 +=
sprintf ( F_143 ( V_623 ,
V_626 ) ,
L_96 ) ;
V_653 =
F_147 ( V_6 , V_50 ,
V_627 , V_628 ,
false ,
V_623 ?
V_623 +
V_626 : NULL ,
V_630 , V_631 ) ;
V_626 += V_653 ;
if ( ! V_653 )
return V_652 ;
}
if ( * V_630 )
V_626 +=
sprintf ( F_143 ( V_623 ,
V_626 ) ,
L_97 ,
* V_630 , * V_631 ) ;
else if ( * V_631 )
V_626 +=
sprintf ( F_143 ( V_623 ,
V_626 ) ,
L_98 ,
* V_631 ) ;
else
V_626 +=
sprintf ( F_143 ( V_623 ,
V_626 ) ,
L_99 ) ;
* V_651 = V_626 + 1 ;
return V_19 ;
}
static void F_149 ( struct V_5 * V_6 ,
struct V_654 * V_655 )
{
T_1 V_42 ;
if ( V_655 -> V_656 ) {
for ( V_42 = 0 ; V_42 < V_655 -> V_533 ; V_42 ++ )
F_150 ( V_655 -> V_656 [ V_42 ] ) ;
F_150 ( V_655 -> V_656 ) ;
}
if ( V_655 -> V_657 ) {
for ( V_42 = 0 ; V_42 < V_655 -> V_658 ; V_42 ++ )
F_150 ( V_655 -> V_657 [ V_42 ] . V_659 ) ;
F_150 ( V_655 -> V_657 ) ;
}
}
static enum V_15 F_151 ( struct V_5 * V_6 ,
const T_1 * V_660 ,
struct V_654 * V_655 )
{
T_2 * V_661 = ( T_2 * ) V_660 ;
T_1 V_58 = 0 , V_516 , V_42 ;
memset ( V_655 , 0 , sizeof( * V_655 ) ) ;
V_516 = F_141 ( V_661 , & V_58 ) ;
if ( V_516 != V_537 )
return V_520 ;
V_655 -> V_533 = F_140 ( V_661 , & V_58 ) ;
V_655 -> V_656 = F_152 ( V_655 -> V_533 * sizeof( char * ) , V_662 ) ;
if ( ! V_655 -> V_656 )
return V_663 ;
for ( V_42 = 0 ; V_42 < V_655 -> V_533 ; V_42 ++ ) {
T_2 V_534 = F_140 ( V_661 , & V_58 ) ;
* ( V_655 -> V_656 + V_42 ) = F_152 ( V_534 , V_662 ) ;
if ( ! ( * ( V_655 -> V_656 + V_42 ) ) ) {
V_655 -> V_533 = V_42 ? V_42 - 1 : 0 ;
return V_663 ;
}
F_142 ( V_661 , & V_58 , V_534 ,
* ( V_655 -> V_656 + V_42 ) ) ;
if ( V_534 > V_664 )
( * ( V_655 -> V_656 + V_42 ) ) [ V_664 ] = '\0' ;
}
V_516 = F_141 ( V_661 , & V_58 ) ;
if ( V_516 != V_537 )
return V_520 ;
V_655 -> V_658 = F_141 ( V_661 , & V_58 ) ;
V_655 -> V_657 = F_152 ( V_655 -> V_658 *
sizeof( struct V_665 ) ,
V_662 ) ;
if ( ! V_655 -> V_657 )
return V_663 ;
for ( V_42 = 0 ; V_42 < V_655 -> V_658 ; V_42 ++ ) {
struct V_665 * V_666 = & V_655 -> V_657 [ V_42 ] ;
T_2 V_667 ;
V_666 -> V_203 = F_141 ( V_661 ,
& V_58 ) ;
V_667 =
( V_666 -> V_203 &
V_668 ) >> V_669 ;
V_666 -> V_659 = F_152 ( V_667 , V_662 ) ;
if ( ! V_666 -> V_659 ) {
V_655 -> V_658 = V_42 ? V_42 - 1 : 0 ;
return V_663 ;
}
F_142 ( V_661 ,
& V_58 ,
V_667 , V_666 -> V_659 ) ;
}
return V_19 ;
}
static enum V_15 F_153 ( struct V_5 * V_6 ,
T_1 * V_50 ,
T_1 V_419 ,
char * V_623 ,
T_1 * V_651 )
{
T_1 V_670 , V_507 , V_671 , V_672 ;
T_1 V_673 , V_674 , V_620 , V_622 ;
const char * V_621 , * V_56 , * V_619 ;
T_1 V_58 , V_626 = 0 ;
struct V_654 V_655 ;
struct V_518 * V_675 ;
enum V_15 V_536 ;
const T_1 * V_660 ;
T_2 * V_676 ;
* V_651 = 0 ;
V_50 += F_145 ( V_50 ,
& V_621 , & V_622 ) ;
if ( strcmp ( V_621 , L_10 ) )
return V_677 ;
V_50 += F_146 ( V_50 ,
V_622 ,
V_623 , & V_626 ) ;
V_50 += F_145 ( V_50 ,
& V_621 , & V_622 ) ;
if ( strcmp ( V_621 , L_71 ) || V_622 != 1 )
return V_677 ;
V_50 += F_144 ( V_50 ,
& V_56 , & V_619 , & V_620 ) ;
if ( strcmp ( V_56 , L_72 ) )
return V_677 ;
V_671 = V_620 ;
V_675 = (struct V_518 * ) V_50 ;
V_676 = ( T_2 * ) V_50 + sizeof( * V_675 ) ;
V_58 = V_675 -> V_678 ;
V_670 = V_675 -> V_679 ;
V_507 = F_138 ( V_670 , V_58 , V_675 -> V_48 ) ;
V_50 += V_671 ;
V_50 += F_145 ( V_50 ,
& V_621 , & V_622 ) ;
if ( strcmp ( V_621 , L_73 ) )
return V_677 ;
V_50 += F_144 ( V_50 ,
& V_56 , & V_619 , & V_620 ) ;
if ( strcmp ( V_56 , L_72 ) )
return V_677 ;
V_672 = V_620 ;
if ( ! V_672 ) {
if ( ! V_680 . V_125 )
return V_681 ;
V_660 = V_680 . V_125 ;
} else {
V_660 = V_50 ;
}
V_536 = F_151 ( V_6 , V_660 , & V_655 ) ;
if ( V_536 != V_19 )
goto V_682;
while ( V_507 ) {
struct V_665 * V_666 ;
T_2 V_683 , V_684 ;
T_1 V_685 [ 3 ] = { 0 , 0 , 0 } ;
T_1 V_686 , V_687 , V_42 ;
if ( V_507 < V_688 ) {
V_536 = V_677 ;
goto V_682;
}
V_686 = F_139 ( V_676 ,
& V_58 ,
V_675 -> V_48 ,
V_688 ) ;
V_507 -= V_688 ;
V_687 = V_686 & V_689 ;
if ( V_687 > V_655 . V_658 ) {
T_2 V_690 =
( T_2 ) ( ( V_686 &
V_691 ) >>
V_692 ) ;
if ( V_507 < V_690 ) {
V_536 = V_677 ;
goto V_682;
}
V_58 = F_137 ( V_58 ,
V_690 , V_675 -> V_48 ) ;
V_507 -= V_690 ;
continue;
}
V_666 = & V_655 . V_657 [ V_687 ] ;
for ( V_42 = 0 ,
V_673 = V_693 , V_674 =
V_694 ;
V_42 < V_695 ;
V_42 ++ , V_673 <<= V_696 ,
V_674 += V_696 ) {
T_2 V_697 =
( T_2 ) ( ( V_666 -> V_203 &
V_673 ) >> V_674 ) ;
if ( ! V_697 )
break;
if ( V_697 == 3 )
V_697 = 4 ;
if ( V_507 < V_697 ) {
V_536 = V_677 ;
goto V_682;
}
V_685 [ V_42 ] = F_139 ( V_676 ,
& V_58 ,
V_675 -> V_48 ,
V_697 ) ;
V_507 -= V_697 ;
}
V_683 =
( T_2 ) ( ( V_666 -> V_203 &
V_698 ) >>
V_699 ) ;
V_684 =
( T_2 ) ( ( V_666 -> V_203 &
V_700 ) >>
V_701 ) ;
if ( V_683 >= F_93 ( V_702 ) ) {
V_536 = V_677 ;
goto V_682;
}
V_626 +=
sprintf ( F_143 ( V_623 ,
V_626 ) , L_100 ,
V_702 [ V_683 ] ,
V_655 . V_656 [ V_684 ] ) ;
V_626 +=
sprintf ( F_143 ( V_623 ,
V_626 ) ,
V_666 -> V_659 , V_685 [ 0 ] , V_685 [ 1 ] ,
V_685 [ 2 ] ) ;
}
V_682:
* V_651 = V_626 + 1 ;
F_149 ( V_6 , & V_655 ) ;
return V_536 ;
}
static enum V_15 F_154 ( struct V_5 * V_6 ,
T_1 * V_50 ,
T_1 V_419 ,
char * V_623 ,
T_1 * V_651 )
{
const char * V_621 , * V_56 , * V_619 ;
T_1 V_620 , V_622 , V_703 ;
struct V_704 * V_705 ;
T_2 V_42 , V_633 , V_706 , V_707 ;
T_1 V_626 = 0 ;
char V_708 [ 4 ] ;
V_50 += F_145 ( V_50 ,
& V_621 , & V_622 ) ;
if ( strcmp ( V_621 , L_10 ) )
return V_709 ;
V_50 += F_146 ( V_50 ,
V_622 ,
V_623 , & V_626 ) ;
V_50 += F_145 ( V_50 ,
& V_621 , & V_622 ) ;
if ( strcmp ( V_621 , L_75 ) )
return V_709 ;
V_50 += F_144 ( V_50 ,
& V_56 , & V_619 , & V_620 ) ;
if ( strcmp ( V_56 , L_72 ) )
return V_709 ;
if ( V_620 % V_549 )
return V_709 ;
V_703 = V_620 / V_549 ;
V_705 = (struct V_704 * ) V_50 ;
for ( V_42 = 0 ; V_42 < V_703 ; V_42 ++ ) {
bool V_710 = false ;
V_707 = F_57 ( V_705 [ V_42 ] . V_203 , V_711 ) ;
if ( V_707 == V_712 )
sprintf ( V_708 , L_101 , L_102 ) ;
else
sprintf ( V_708 , L_103 , V_707 ) ;
V_626 +=
sprintf ( F_143 ( V_623 ,
V_626 ) ,
L_104 ,
V_705 [ V_42 ] . V_203 ,
( T_1 ) F_57 ( V_705 [ V_42 ] . V_203 ,
V_713 ) *
V_714 ,
V_715 [ F_57 ( V_705 [ V_42 ] . V_203 ,
V_716 ) ] ,
( T_1 ) F_57 ( V_705 [ V_42 ] . V_203 ,
V_717 ) ,
V_708 ,
( T_1 ) F_57 ( V_705 [ V_42 ] . V_203 ,
V_718 ) ,
V_719 [ F_57 ( V_705 [ V_42 ] . V_203 ,
V_720 ) ] ,
V_721 [ F_57 ( V_705 [ V_42 ] . V_203 ,
V_722 ) ] ,
V_723 [ F_57 ( V_705 [ V_42 ] . V_203 ,
V_724 ) ] ) ;
for ( V_633 = 0 ,
V_706 = F_57 ( V_705 [ V_42 ] . V_203 ,
V_725 ) ;
V_633 < F_93 ( V_726 ) ;
V_633 ++ , V_706 >>= 1 ) {
if ( V_706 & 0x1 ) {
if ( V_710 )
V_626 +=
sprintf ( F_143
( V_623 ,
V_626 ) , L_105 ) ;
V_626 +=
sprintf ( F_143
( V_623 , V_626 ) , L_101 ,
V_726 [ V_633 ] ) ;
V_710 = true ;
}
}
V_626 +=
sprintf ( F_143 ( V_623 , V_626 ) , L_86 ) ;
}
V_626 += sprintf ( F_143 ( V_623 ,
V_626 ) ,
L_106 , V_703 ) ;
* V_651 = V_626 + 1 ;
return V_19 ;
}
static enum V_15 F_155 ( struct V_727
* V_728 , char
* V_623 ,
T_1 * V_626 ,
T_1 * V_651 )
{
const struct V_729 * V_730 = NULL ;
T_2 V_731 , V_732 , V_42 , V_733 ;
char V_734 [ 32 ] ;
char V_735 [ 256 ] ;
T_1 V_736 , V_737 ;
bool V_738 , V_739 ;
T_3 V_740 ;
V_551 V_741 ;
V_741 = ( ( V_551 ) V_728 -> V_742 << 32 ) | V_728 -> V_294 ;
V_738 = F_57 ( V_741 , V_743 ) ;
V_739 = F_57 ( V_728 -> V_287 , V_744 ) ;
V_740 = F_57 ( V_728 -> V_287 , V_745 ) ;
V_731 = F_57 ( V_728 -> V_287 , V_746 ) ;
V_732 = F_57 ( V_728 -> V_287 , V_747 ) ;
if ( V_731 >= F_93 ( V_748 ) )
return V_749 ;
if ( V_732 >= F_93 ( V_750 ) )
return V_749 ;
for ( V_42 = 0 ; V_42 < F_93 ( V_751 ) && ! V_730 ; V_42 ++ ) {
const struct V_729 * V_752 =
& V_751 [ V_42 ] ;
if ( V_740 >= V_752 -> V_753 && V_740 <=
V_752 -> V_754 )
V_730 = V_752 ;
}
if ( ! V_730 )
return V_749 ;
switch ( V_730 -> type ) {
case V_755 :
sprintf ( V_734 , L_107 , V_740 / 2 ) ;
break;
case V_756 :
case V_757 :
sprintf ( V_734 ,
L_108 , V_740 - V_730 -> V_753 ) ;
break;
default:
V_734 [ 0 ] = '\0' ;
}
if ( ! V_738 ) {
V_735 [ 0 ] = '\0' ;
goto V_547;
}
V_736 = F_57 ( V_741 , V_758 ) ;
V_737 = F_57 ( V_736 , V_759 ) ;
V_733 = F_57 ( V_736 , V_760 ) ;
if ( V_731 == V_761 ) {
sprintf ( V_735 , L_109 , V_737 ) ;
} else {
if ( V_733 ) {
T_2 V_762 , V_763 ;
V_762 =
F_57 ( V_736 ,
V_764 ) ;
V_763 =
F_57 ( V_736 ,
V_765 ) ;
sprintf ( V_735 ,
L_110 ,
V_762 ? L_111 : L_112 ,
V_763 ) ;
} else {
T_2 V_766 , V_767 , V_768 ;
T_2 V_769 ;
V_766 = F_57 ( V_736 ,
V_770 ) ;
V_767 =
F_57 ( V_736 ,
V_771 ) ;
V_768 = F_57 ( V_736 ,
V_772 ) ;
V_769 = F_57 ( V_736 ,
V_773 ) ;
sprintf ( V_735 ,
L_113 ,
V_737 ,
V_766 ? L_114 : L_115 ,
V_767
? ( V_767 == 1 ? L_116 : L_115 )
: L_117 ,
V_768 ? L_118 : L_119 ,
V_769 ) ;
}
}
V_547:
* V_626 += sprintf ( F_143 ( V_623 ,
* V_626 ) ,
L_120 ,
V_728 -> V_742 , V_728 -> V_294 ,
V_728 -> V_287 ,
V_739 ? L_23 : L_24 ,
F_57 ( V_728 -> V_287 ,
V_774 ) ,
V_748 [ V_731 ] ,
V_738 ? L_121 : L_122 ,
V_740 ,
( ! V_739 && V_730 -> V_775 )
? V_730 -> V_775
: V_730 -> V_776 ,
V_734 ,
V_735 ,
V_750 [ V_732 ] ) ;
return V_19 ;
}
static enum V_15 F_156 ( struct V_5 * V_6 ,
T_1 * V_50 ,
T_1 V_419 ,
char * V_623 ,
T_1 * V_651 )
{
const char * V_621 , * V_56 , * V_619 ;
T_1 V_620 , V_622 , V_703 ;
struct V_727 * V_705 ;
enum V_15 V_536 ;
T_1 V_626 = 0 ;
T_2 V_42 ;
V_50 += F_145 ( V_50 ,
& V_621 , & V_622 ) ;
if ( strcmp ( V_621 , L_10 ) )
return V_749 ;
V_50 += F_146 ( V_50 ,
V_622 ,
V_623 , & V_626 ) ;
V_50 += F_145 ( V_50 ,
& V_621 , & V_622 ) ;
if ( strcmp ( V_621 , L_77 ) )
return V_749 ;
V_50 += F_144 ( V_50 ,
& V_56 , & V_619 , & V_620 ) ;
if ( strcmp ( V_56 , L_72 ) )
return V_749 ;
if ( V_620 % V_556 )
return V_749 ;
V_703 = V_620 / V_556 ;
V_705 = (struct V_727 * ) V_50 ;
for ( V_42 = 0 ; V_42 < V_703 ; V_42 ++ ) {
V_536 = F_155 ( & V_705 [ V_42 ] ,
V_623 ,
& V_626 ,
V_651 ) ;
if ( V_536 != V_19 )
return V_536 ;
}
V_626 += sprintf ( F_143 ( V_623 ,
V_626 ) ,
L_106 , V_703 ) ;
* V_651 = V_626 + 1 ;
return V_19 ;
}
static enum V_15
F_157 ( struct V_5 * V_6 ,
T_1 * V_50 ,
T_1 V_419 ,
char * V_623 ,
T_1 * V_651 )
{
const char * V_621 , * V_56 , * V_619 ;
T_1 V_620 , V_622 , V_703 ;
struct V_777 * V_705 ;
T_1 V_626 = 0 ;
T_2 V_42 ;
V_50 += F_145 ( V_50 ,
& V_621 , & V_622 ) ;
if ( strcmp ( V_621 , L_10 ) )
return V_778 ;
V_50 += F_146 ( V_50 ,
V_622 ,
V_623 , & V_626 ) ;
V_50 += F_145 ( V_50 ,
& V_621 , & V_622 ) ;
if ( strcmp ( V_621 , L_79 ) )
return V_778 ;
V_50 += F_144 ( V_50 ,
& V_56 , & V_619 , & V_620 ) ;
if ( strcmp ( V_56 , L_72 ) )
return V_778 ;
if ( V_620 % V_561 )
return V_778 ;
V_703 = V_620 / V_561 ;
V_705 = (struct V_777 * ) V_50 ;
for ( V_42 = 0 ; V_42 < V_703 ; V_42 ++ ) {
T_1 V_779 = F_57 ( V_705 [ V_42 ] . V_203 ,
V_780 ) *
V_781 ;
V_626 +=
sprintf ( F_143 ( V_623 ,
V_626 ) ,
L_123 ,
V_42 , V_779 ,
( T_1 ) F_57 ( V_705 [ V_42 ] . V_203 ,
V_782 ) ,
( T_1 ) F_57 ( V_705 [ V_42 ] . V_203 ,
V_783 ) ,
( T_1 ) F_57 ( V_705 [ V_42 ] . V_203 ,
V_784 ) ,
V_721 [ F_57 ( V_705 [ V_42 ] . V_203 ,
V_785 ) ] ,
V_721 [ F_57 ( V_705 [ V_42 ] . V_203 ,
V_786 ) ] ) ;
}
V_626 += sprintf ( F_143 ( V_623 ,
V_626 ) ,
L_124 ,
V_703 ) ;
* V_651 = V_626 + 1 ;
return V_19 ;
}
static enum V_15 F_158 ( struct V_5 * V_6 ,
T_1 * V_50 ,
T_1 V_419 ,
char * V_623 ,
T_1 * V_651 )
{
T_1 V_622 , V_620 , V_42 , V_626 = 0 ;
const char * V_56 , * V_619 , * V_621 ;
bool V_787 = false ;
* V_651 = 0 ;
V_50 += F_145 ( V_50 ,
& V_621 , & V_622 ) ;
if ( strcmp ( V_621 , L_10 ) )
return V_788 ;
V_50 += F_146 ( V_50 ,
V_622 ,
V_623 , & V_626 ) ;
while ( ! V_787 ) {
V_50 += F_145 ( V_50 ,
& V_621 ,
& V_622 ) ;
if ( ! strcmp ( V_621 , L_82 ) ) {
const char * V_280 = NULL ;
T_1 V_789 = 0 ;
for ( V_42 = 0 ; V_42 < V_622 ; V_42 ++ ) {
V_50 += F_144 ( V_50 ,
& V_56 ,
& V_619 ,
& V_620 ) ;
if ( ! strcmp ( V_56 , L_83 ) )
V_280 = V_619 ;
else if ( ! strcmp ( V_56 , L_72 ) )
V_789 = V_620 ;
else
return
V_788 ;
}
if ( ! V_280 || ! V_789 )
return V_788 ;
V_626 +=
sprintf ( F_143 ( V_623 ,
V_626 ) ,
L_125 ,
V_280 , V_789 ) ;
for ( V_42 = 0 ; V_42 < V_789 ; V_42 ++ , V_50 ++ )
V_626 +=
sprintf ( F_143 ( V_623 ,
V_626 ) ,
L_126 , * V_50 ) ;
} else if ( ! strcmp ( V_621 , L_15 ) ) {
V_787 = true ;
} else {
return V_788 ;
}
}
* V_651 = V_626 + 1 ;
return V_19 ;
}
enum V_15 F_159 ( const T_2 * const V_576 )
{
struct V_577 * V_578 = (struct V_577 * ) V_576 ;
T_2 V_579 ;
for ( V_579 = 0 ; V_579 < V_580 ; V_579 ++ ) {
V_641 [ V_579 ] . V_125 =
( T_1 * ) ( V_576 + V_578 [ V_579 ] . V_58 ) ;
V_641 [ V_579 ] . V_225 =
F_26 ( V_578 [ V_579 ] . V_581 ) ;
}
return V_19 ;
}
const char * F_160 ( enum V_15 V_536 )
{
return ( V_536 <
V_790 ) ? V_791 [ V_536 ] : L_127 ;
}
enum V_15 F_161 ( struct V_5 * V_6 ,
T_1 * V_50 ,
T_1 V_419 ,
T_1 * V_792 )
{
T_1 V_630 , V_631 ;
return F_148 ( V_6 ,
V_50 ,
V_419 ,
NULL ,
V_792 ,
& V_630 , & V_631 ) ;
}
enum V_15 F_162 ( struct V_5 * V_6 ,
T_1 * V_50 ,
T_1 V_419 ,
char * V_623 ,
T_1 * V_630 , T_1 * V_631 )
{
T_1 V_793 ;
return F_148 ( V_6 ,
V_50 ,
V_419 ,
V_623 ,
& V_793 ,
V_630 , V_631 ) ;
}
void F_163 ( T_1 * V_203 , T_1 V_48 )
{
V_680 . V_125 = V_203 ;
V_680 . V_225 = V_48 ;
}
enum V_15 F_164 ( struct V_5 * V_6 ,
T_1 * V_50 ,
T_1 V_419 ,
T_1 * V_792 )
{
return F_153 ( V_6 ,
V_50 ,
V_419 ,
NULL , V_792 ) ;
}
enum V_15 F_165 ( struct V_5 * V_6 ,
T_1 * V_50 ,
T_1 V_419 ,
char * V_623 )
{
T_1 V_793 ;
return F_153 ( V_6 ,
V_50 ,
V_419 ,
V_623 , & V_793 ) ;
}
enum V_15 F_166 ( struct V_5 * V_6 ,
T_1 * V_50 ,
T_1 V_419 ,
T_1 * V_792 )
{
return F_154 ( V_6 ,
V_50 ,
V_419 ,
NULL , V_792 ) ;
}
enum V_15 F_167 ( struct V_5 * V_6 ,
T_1 * V_50 ,
T_1 V_419 ,
char * V_623 )
{
T_1 V_793 ;
return F_154 ( V_6 ,
V_50 ,
V_419 ,
V_623 , & V_793 ) ;
}
enum V_15 F_168 ( struct V_5 * V_6 ,
T_1 * V_50 ,
T_1 V_419 ,
T_1 * V_792 )
{
return F_156 ( V_6 ,
V_50 ,
V_419 ,
NULL , V_792 ) ;
}
enum V_15 F_169 ( struct V_5 * V_6 ,
T_1 * V_50 ,
T_1 V_419 ,
char * V_623 )
{
T_1 V_793 ;
return F_156 ( V_6 ,
V_50 ,
V_419 ,
V_623 , & V_793 ) ;
}
enum V_15
F_170 ( struct V_5 * V_6 ,
T_1 * V_50 ,
T_1 V_419 ,
T_1 * V_792 )
{
return F_157 ( V_6 ,
V_50 ,
V_419 ,
NULL , V_792 ) ;
}
enum V_15 F_171 ( struct V_5 * V_6 ,
T_1 * V_50 ,
T_1 V_419 ,
char * V_623 )
{
T_1 V_793 ;
return F_157 ( V_6 ,
V_50 ,
V_419 ,
V_623 ,
& V_793 ) ;
}
enum V_15 F_172 ( struct V_5 * V_6 ,
T_1 * V_50 ,
T_1 V_419 ,
T_1 * V_792 )
{
return F_158 ( V_6 ,
V_50 ,
V_419 ,
NULL , V_792 ) ;
}
enum V_15 F_173 ( struct V_5 * V_6 ,
T_1 * V_50 ,
T_1 V_419 ,
char * V_623 )
{
T_1 V_793 ;
return F_158 ( V_6 ,
V_50 ,
V_419 ,
V_623 , & V_793 ) ;
}
enum V_15 F_174 ( struct V_5 * V_6 ,
struct V_595 * V_596 )
{
struct V_794 * V_795 , * V_796 ;
const T_1 * V_797 ;
enum V_186 V_187 ;
const char * V_798 ;
T_2 V_195 , V_42 , V_633 ;
V_195 = F_57 ( V_596 -> V_203 , V_610 ) ;
V_187 = (enum V_186 )
F_57 ( V_596 -> V_203 ,
V_609 ) ;
V_798 = V_799 [ V_596 -> V_32 ] . V_90 ;
if ( ! V_641 [ V_800 ] . V_125 ||
! V_641 [ V_801 ] . V_125 ||
! V_641 [ V_645 ] . V_125 )
return V_586 ;
V_795 = & V_641 [ V_801 ] ;
V_797 = & V_795 -> V_125 [ V_596 -> V_608 ] ;
for ( V_42 = 0 ; V_42 < V_195 ; V_42 ++ ) {
struct V_598 * V_599 ;
struct V_802 * V_803 ;
T_2 V_804 , V_805 = 0 ;
V_599 = & V_596 -> V_602 [ V_42 ] ;
V_804 = F_57 ( V_599 -> V_203 ,
V_604 ) ;
V_795 = & V_641 [ V_800 ] ;
V_803 = & ( (struct V_802 * )
V_795 -> V_125 ) [ V_599 -> V_606 ] ;
V_796 = & V_641 [ V_645 ] ;
for ( V_633 = 0 ; V_633 < V_804 ; V_633 ++ ) {
T_3 V_806 = F_57 ( V_803 [ V_633 ] . V_203 ,
V_807 ) ;
const char * V_808 , * V_809 , * V_810 ;
T_1 V_811 , V_600 ;
if ( F_57 ( V_803 [ V_633 ] . V_203 ,
V_812 ) ) {
V_805 += ( T_2 ) V_806 ;
continue;
}
if ( ! ( V_599 -> V_601 & F_41 ( V_805 ) ) ) {
V_805 ++ ;
continue;
}
V_811 = V_797 [ V_806 ] ;
V_808 = & ( ( const char * )
V_796 -> V_125 ) [ V_811 ] ;
V_809 = V_187 == V_813 ?
L_128 : L_129 ;
V_810 = V_599 -> V_607 & F_41 ( V_805 ) ?
L_130 : L_131 ;
V_600 = F_57 ( V_599 -> V_203 ,
V_603 ) ;
F_33 ( V_6 ,
L_132 ,
V_798 , V_809 , V_808 ,
V_600 , V_805 , V_810 ) ;
V_805 ++ ;
}
}
return V_19 ;
}
static enum V_15
F_175 ( struct V_5 * V_6 ,
T_1 * V_50 ,
T_1 V_419 ,
char * V_623 )
{
T_1 V_630 , V_814 ;
return F_162 ( V_6 , V_50 , V_419 ,
V_623 , & V_630 ,
& V_814 ) ;
}
static void F_176 ( T_2 * V_815 , T_1 V_816 )
{
T_1 V_42 , V_817 = 80 ;
if ( ! V_815 )
return;
F_177 ( L_133 , V_817 , V_815 ) ;
for ( V_42 = V_817 ; V_42 < V_816 ; V_42 += V_817 )
F_178 ( L_134 , V_817 , V_815 + V_42 ) ;
F_178 ( L_86 ) ;
}
static enum V_15 F_179 ( struct V_5 * V_6 ,
enum V_818 V_819 )
{
struct V_820 * V_821 =
& V_6 -> V_20 -> V_822 . V_823 [ V_819 ] ;
T_1 V_824 , V_825 , V_42 ;
enum V_15 V_826 ;
char * V_827 ;
if ( ! V_828 [ V_819 ] . V_792 )
return V_19 ;
V_826 = V_828 [ V_819 ] .
V_792 ( V_6 , ( T_1 * ) V_821 -> V_50 ,
V_821 -> V_829 , & V_824 ) ;
if ( V_826 != V_19 )
return V_826 ;
V_825 = V_824 - 1 ;
V_824 = ( V_824 + 3 ) & ~ 0x3 ;
if ( V_824 < V_830 ) {
F_33 ( V_6 -> V_20 ,
L_135 ,
V_824 ) ;
return V_831 ;
}
V_827 = F_180 ( V_824 ) ;
if ( ! V_827 )
return V_663 ;
V_826 = V_828 [ V_819 ] .
F_181 ( V_6 , ( T_1 * ) V_821 -> V_50 ,
V_821 -> V_829 , V_827 ) ;
if ( V_826 != V_19 ) {
F_182 ( V_827 ) ;
return V_826 ;
}
for ( V_42 = V_825 ; V_42 < V_824 ; V_42 ++ )
V_827 [ V_42 ] = '\n' ;
if ( V_6 -> V_20 -> V_822 . V_832 )
F_176 ( V_827 , V_824 ) ;
F_182 ( V_821 -> V_50 ) ;
V_821 -> V_50 = V_827 ;
V_821 -> V_585 = V_824 ;
V_821 -> V_829 = V_824 / 4 ;
return V_826 ;
}
static enum V_15 F_183 ( struct V_5 * V_6 ,
struct V_16 * V_17 ,
enum V_818 V_819 )
{
struct V_820 * V_821 =
& V_6 -> V_20 -> V_822 . V_823 [ V_819 ] ;
T_1 V_833 ;
enum V_15 V_826 ;
F_33 ( V_6 -> V_20 , L_136 ,
V_828 [ V_819 ] . V_90 ) ;
if ( V_821 -> V_50 ) {
F_182 ( V_821 -> V_50 ) ;
V_821 -> V_50 = NULL ;
}
V_826 = V_828 [ V_819 ] . F_184 ( V_6 , V_17 ,
& V_833 ) ;
if ( V_826 != V_19 && V_826 != V_501 )
return V_826 ;
V_821 -> V_585 = V_833 * sizeof( T_1 ) ;
V_821 -> V_50 = F_185 ( V_821 -> V_585 ) ;
if ( ! V_821 -> V_50 )
return V_663 ;
V_826 = V_828 [ V_819 ] .
F_186 ( V_6 , V_17 , ( T_1 * ) V_821 -> V_50 ,
V_821 -> V_585 / sizeof( T_1 ) ,
& V_821 -> V_829 ) ;
if ( V_826 == V_501 )
return V_19 ;
if ( V_826 != V_19 )
return V_826 ;
V_826 = F_179 ( V_6 , V_819 ) ;
return V_826 ;
}
int F_187 ( struct V_834 * V_20 , void * V_835 , T_1 * V_836 )
{
return V_820 ( V_20 , V_835 , V_837 , V_836 ) ;
}
int F_188 ( struct V_834 * V_20 )
{
return F_189 ( V_20 , V_837 ) ;
}
int F_190 ( struct V_834 * V_20 , void * V_835 , T_1 * V_836 )
{
return V_820 ( V_20 , V_835 , V_838 ,
V_836 ) ;
}
int F_191 ( struct V_834 * V_20 )
{
return F_189 ( V_20 , V_838 ) ;
}
int F_192 ( struct V_834 * V_20 , void * V_835 , T_1 * V_836 )
{
return V_820 ( V_20 , V_835 , V_839 ,
V_836 ) ;
}
int F_193 ( struct V_834 * V_20 )
{
return F_189 ( V_20 , V_839 ) ;
}
int F_194 ( struct V_834 * V_20 , void * V_835 , T_1 * V_836 )
{
return V_820 ( V_20 , V_835 , V_840 ,
V_836 ) ;
}
int F_195 ( struct V_834 * V_20 )
{
return F_189 ( V_20 , V_840 ) ;
}
int F_196 ( struct V_834 * V_20 , void * V_835 ,
T_1 * V_836 )
{
return V_820 ( V_20 , V_835 , V_841 ,
V_836 ) ;
}
int F_197 ( struct V_834 * V_20 )
{
return F_189 ( V_20 , V_841 ) ;
}
int F_198 ( struct V_834 * V_20 , void * V_835 ,
T_1 * V_836 )
{
return V_820 ( V_20 , V_835 , V_842 ,
V_836 ) ;
}
int F_199 ( struct V_834 * V_20 )
{
return F_189 ( V_20 , V_842 ) ;
}
int F_200 ( struct V_834 * V_20 , void * V_835 ,
T_1 * V_836 )
{
return V_820 ( V_20 , V_835 , V_843 ,
V_836 ) ;
}
int F_201 ( struct V_834 * V_20 )
{
return F_189 ( V_20 , V_843 ) ;
}
static T_1 F_202 ( enum V_844 V_821 ,
int V_845 , T_1 V_846 , T_2 V_847 )
{
return V_846 | ( V_821 << V_848 ) |
( V_847 << V_849 ) |
( V_845 << V_850 ) ;
}
int F_203 ( struct V_834 * V_20 , void * V_835 )
{
T_2 V_851 , V_847 = 0 , V_852 ;
T_1 V_58 = 0 , V_846 ;
int V_826 ;
if ( V_20 -> V_853 == 1 )
V_847 = 1 ;
V_852 = F_204 ( V_20 ) ;
for ( V_851 = 0 ; V_851 < V_20 -> V_853 ; V_851 ++ ) {
F_67 ( V_20 , V_244 ,
L_137 ) ;
F_205 ( V_20 , V_851 ) ;
V_826 = F_190 ( V_20 , ( T_2 * ) V_835 + V_58 +
V_854 , & V_846 ) ;
if ( ! V_826 ) {
* ( T_1 * ) ( ( T_2 * ) V_835 + V_58 ) =
F_202 ( V_855 , V_851 ,
V_846 , V_847 ) ;
V_58 += ( V_846 + V_854 ) ;
} else {
F_206 ( V_20 , L_138 , V_826 ) ;
}
V_826 = F_190 ( V_20 , ( T_2 * ) V_835 + V_58 +
V_854 , & V_846 ) ;
if ( ! V_826 ) {
* ( T_1 * ) ( ( T_2 * ) V_835 + V_58 ) =
F_202 ( V_855 , V_851 ,
V_846 , V_847 ) ;
V_58 += ( V_846 + V_854 ) ;
} else {
F_206 ( V_20 , L_138 , V_826 ) ;
}
V_826 = F_192 ( V_20 , ( T_2 * ) V_835 + V_58 +
V_854 , & V_846 ) ;
if ( ! V_826 ) {
* ( T_1 * ) ( ( T_2 * ) V_835 + V_58 ) =
F_202 ( V_856 , V_851 ,
V_846 , V_847 ) ;
V_58 += ( V_846 + V_854 ) ;
} else {
F_206 ( V_20 , L_139 , V_826 ) ;
}
V_826 = F_194 ( V_20 , ( T_2 * ) V_835 + V_58 +
V_854 , & V_846 ) ;
if ( ! V_826 ) {
* ( T_1 * ) ( ( T_2 * ) V_835 + V_58 ) =
F_202 ( V_857 , V_851 ,
V_846 , V_847 ) ;
V_58 += ( V_846 + V_854 ) ;
} else {
F_206 ( V_20 , L_140 , V_826 ) ;
}
V_826 = F_196 ( V_20 , ( T_2 * ) V_835 + V_58 +
V_854 ,
& V_846 ) ;
if ( ! V_826 ) {
* ( T_1 * ) ( ( T_2 * ) V_835 + V_58 ) =
F_202 ( V_858 ,
V_851 ,
V_846 , V_847 ) ;
V_58 += ( V_846 + V_854 ) ;
} else {
F_206 ( V_20 ,
L_141 ,
V_826 ) ;
}
V_826 = F_198 ( V_20 , ( T_2 * ) V_835 + V_58 +
V_854 , & V_846 ) ;
if ( ! V_826 ) {
* ( T_1 * ) ( ( T_2 * ) V_835 + V_58 ) =
F_202 ( V_859 , V_851 ,
V_846 , V_847 ) ;
V_58 += ( V_846 + V_854 ) ;
} else {
F_206 ( V_20 , L_142 ,
V_826 ) ;
}
V_826 = F_187 ( V_20 , ( T_2 * ) V_835 + V_58 +
V_854 , & V_846 ) ;
if ( ! V_826 ) {
* ( T_1 * ) ( ( T_2 * ) V_835 + V_58 ) =
F_202 ( V_860 , V_851 ,
V_846 , V_847 ) ;
V_58 += ( V_846 + V_854 ) ;
} else {
F_206 ( V_20 , L_143 , V_826 ) ;
}
}
V_826 = F_200 ( V_20 , ( T_2 * ) V_835 + V_58 +
V_854 , & V_846 ) ;
if ( ! V_826 ) {
* ( T_1 * ) ( ( T_2 * ) V_835 + V_58 ) =
F_202 ( V_861 , V_851 ,
V_846 , V_847 ) ;
V_58 += ( V_846 + V_854 ) ;
} else {
F_206 ( V_20 , L_144 , V_826 ) ;
}
F_205 ( V_20 , V_852 ) ;
return 0 ;
}
int F_207 ( struct V_834 * V_20 )
{
T_2 V_851 , V_852 ;
T_1 V_862 = 0 ;
V_852 = F_204 ( V_20 ) ;
for ( V_851 = 0 ; V_851 < V_20 -> V_853 ; V_851 ++ ) {
F_67 ( V_20 , V_244 ,
L_145 ) ;
F_205 ( V_20 , V_851 ) ;
V_862 += V_854 + F_191 ( V_20 ) +
V_854 + F_191 ( V_20 ) +
V_854 + F_188 ( V_20 ) +
V_854 + F_193 ( V_20 ) +
V_854 + F_195 ( V_20 ) +
V_854 +
F_197 ( V_20 ) +
V_854 + F_199 ( V_20 ) ;
}
V_862 += V_854 + F_201 ( V_20 ) ;
F_205 ( V_20 , V_852 ) ;
return V_862 ;
}
int V_820 ( struct V_834 * V_20 , void * V_835 ,
enum V_818 V_821 , T_1 * V_836 )
{
struct V_5 * V_6 =
& V_20 -> V_863 [ V_20 -> V_822 . V_864 ] ;
struct V_820 * V_865 =
& V_20 -> V_822 . V_823 [ V_821 ] ;
enum V_15 V_866 ;
struct V_16 * V_17 ;
int V_826 = 0 ;
V_17 = F_208 ( V_6 ) ;
if ( ! V_17 )
return - V_867 ;
V_866 = F_183 ( V_6 , V_17 , V_821 ) ;
if ( V_866 != V_19 ) {
F_67 ( V_20 , V_244 , L_146 ,
F_160 ( V_866 ) ) ;
* V_836 = 0 ;
V_826 = - V_867 ;
goto V_547;
}
F_67 ( V_20 , V_244 ,
L_147 ) ;
memcpy ( V_835 , V_865 -> V_50 , V_865 -> V_585 ) ;
* V_836 = V_20 -> V_822 . V_823 [ V_821 ] . V_829 *
4 ;
V_547:
F_209 ( V_6 , V_17 ) ;
return V_826 ;
}
int F_189 ( struct V_834 * V_20 , enum V_818 V_821 )
{
struct V_5 * V_6 =
& V_20 -> V_863 [ V_20 -> V_822 . V_864 ] ;
struct V_16 * V_17 = F_208 ( V_6 ) ;
struct V_820 * V_865 =
& V_20 -> V_822 . V_823 [ V_821 ] ;
T_1 V_833 ;
enum V_15 V_826 ;
if ( ! V_17 )
return - V_867 ;
V_826 = V_828 [ V_821 ] . F_184 ( V_6 , V_17 ,
& V_833 ) ;
if ( V_826 != V_19 )
V_833 = 0 ;
F_209 ( V_6 , V_17 ) ;
V_865 -> V_585 = V_833 * sizeof( T_1 ) ;
return V_865 -> V_585 ;
}
T_2 F_204 ( struct V_834 * V_20 )
{
return V_20 -> V_822 . V_864 ;
}
void F_205 ( struct V_834 * V_20 , int V_868 )
{
F_67 ( V_20 , V_244 , L_148 ,
V_868 ) ;
V_20 -> V_822 . V_864 = V_868 ;
}
void F_210 ( struct V_834 * V_20 )
{
const T_2 * V_869 ;
V_869 = V_20 -> V_870 -> V_203 + * ( T_1 * ) V_20 -> V_870 -> V_203 ;
F_121 ( ( T_2 * ) V_869 ) ;
F_159 ( ( T_2 * ) V_869 ) ;
}
void F_211 ( struct V_834 * V_20 )
{
struct V_820 * V_821 = NULL ;
enum V_818 V_819 ;
for ( V_819 = 0 ; V_819 < V_871 ; V_819 ++ ) {
V_821 = & V_20 -> V_822 . V_823 [ V_819 ] ;
if ( V_821 -> V_50 ) {
F_182 ( V_821 -> V_50 ) ;
V_821 -> V_50 = NULL ;
}
}
}
