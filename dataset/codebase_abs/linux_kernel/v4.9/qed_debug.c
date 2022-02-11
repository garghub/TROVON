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
static enum V_5 F_15 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_7 -> V_12 ;
if ( V_11 -> V_13 )
return V_14 ;
if ( F_16 ( V_7 -> V_15 ) ) {
V_11 -> V_16 = V_17 ;
V_11 -> V_18 [ V_19 ] = 1 ;
} else if ( F_17 ( V_7 -> V_15 ) ) {
V_11 -> V_16 = V_20 ;
V_11 -> V_18 [ V_21 ] = 1 ;
} else {
return V_22 ;
}
V_11 -> V_23 = V_24 ;
V_11 -> V_18 [ V_25 ] = 1 ;
V_11 -> V_13 = true ;
return V_14 ;
}
static void F_18 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_2 V_26 , struct V_27 * V_27 )
{
T_1 V_28 = V_29 [ V_26 ] . V_30 +
V_31 +
F_19 ( V_32 ) -
sizeof( struct V_33 ) ;
struct V_33 V_33 ;
T_1 * V_34 = ( T_1 * ) & V_33 ;
T_1 V_35 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
for ( V_35 = 0 ; V_35 < F_20 ( sizeof( V_33 ) ) ;
V_35 ++ , V_28 += V_36 )
V_34 [ V_35 ] = F_21 ( V_7 , V_9 , V_28 ) ;
if ( V_33 . V_37 > 0 && V_33 . V_37 <=
sizeof( * V_27 ) ) {
V_28 = V_33 . V_38 ;
V_34 = ( T_1 * ) V_27 ;
for ( V_35 = 0 ; V_35 < F_20 ( V_33 . V_37 ) ;
V_35 ++ , V_28 += V_36 )
V_34 [ V_35 ] = F_21 ( V_7 , V_9 , V_28 ) ;
}
}
static T_1 F_22 ( char * V_39 , bool V_40 , const char * V_41 )
{
if ( V_40 )
strcpy ( V_39 , V_41 ) ;
return ( T_1 ) strlen ( V_41 ) + 1 ;
}
static T_1 F_23 ( char * V_39 , bool V_40 , T_1 V_42 )
{
T_2 V_43 = ( T_2 ) ( V_42 & 0x3 ) , V_44 ;
V_44 = V_43 ? V_36 - V_43 : 0 ;
if ( V_40 && V_44 )
memset ( V_39 , 0 , V_44 ) ;
return V_44 ;
}
static T_1 F_24 ( T_1 * V_39 ,
bool V_40 ,
const char * V_45 , const char * V_46 )
{
char * V_47 = ( char * ) V_39 ;
T_1 V_48 = 0 ;
V_48 += F_22 ( V_47 + V_48 , V_40 , V_45 ) ;
if ( V_40 )
* ( V_47 + V_48 ) = 1 ;
V_48 ++ ;
V_48 += F_22 ( V_47 + V_48 , V_40 , V_46 ) ;
V_48 += F_23 ( V_47 + V_48 , V_40 , V_48 ) ;
return F_20 ( V_48 ) ;
}
static T_1 F_25 ( T_1 * V_39 ,
bool V_40 , const char * V_45 , T_1 V_46 )
{
char * V_47 = ( char * ) V_39 ;
T_1 V_48 = 0 ;
V_48 += F_22 ( V_47 + V_48 , V_40 , V_45 ) ;
if ( V_40 )
* ( V_47 + V_48 ) = 0 ;
V_48 ++ ;
V_48 += F_23 ( V_47 + V_48 , V_40 , V_48 ) ;
V_48 = F_20 ( V_48 ) ;
if ( V_40 )
* ( V_39 + V_48 ) = V_46 ;
V_48 ++ ;
return V_48 ;
}
static T_1 F_26 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_39 , bool V_40 )
{
struct V_10 * V_11 = & V_7 -> V_12 ;
char V_49 [ 16 ] = V_50 ;
char V_51 [ 16 ] = V_52 ;
struct V_27 V_27 = { { 0 } , { 0 } } ;
int V_53 ;
T_1 V_48 = 0 ;
if ( V_40 ) {
bool V_54 = false ;
T_2 V_26 ;
for ( V_26 = 0 ; V_26 < V_55 && ! V_54 ;
V_26 ++ ) {
if ( ! V_11 -> V_56
[ V_29 [ V_26 ] . V_57 ] ) {
F_18 ( V_7 ,
V_9 , V_26 , & V_27 ) ;
V_53 =
snprintf ( V_49 ,
sizeof( V_49 ) ,
L_1 ,
V_27 . V_58 . V_59 . V_60 ,
V_27 . V_58 . V_59 . V_61 ,
V_27 . V_58 . V_59 . V_62 ,
V_27 . V_58 . V_59 . V_63 ) ;
if ( V_53 < 0 || V_53 >=
sizeof( V_49 ) )
F_27 ( V_7 ,
L_2 ) ;
switch ( V_27 . V_58 . V_64 ) {
case V_65 :
strcpy ( V_51 , L_3 ) ;
break;
default:
strcpy ( V_51 , L_4 ) ;
break;
}
V_54 = true ;
}
}
}
V_48 += F_24 ( V_39 + V_48 ,
V_40 , L_5 , V_49 ) ;
V_48 += F_24 ( V_39 + V_48 ,
V_40 , L_6 , V_51 ) ;
V_48 += F_25 ( V_39 + V_48 ,
V_40 ,
L_7 , V_27 . V_58 . V_66 ) ;
return V_48 ;
}
static T_1 F_28 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_39 , bool V_40 )
{
char V_67 [ 16 ] = V_50 ;
if ( V_40 ) {
T_1 V_68 , V_69 , V_70 ;
T_1 V_71 , V_72 ;
int V_53 ;
V_71 = F_21 ( V_7 , V_9 ,
V_73 ) |
V_74 ;
V_72 = V_71 +
F_29 ( struct V_75 ,
V_76 ) +
sizeof( V_77 ) * V_78 ;
V_68 = F_21 ( V_7 , V_9 ,
V_72 ) ;
V_69 = V_74 +
( V_68 &
V_79 ) * 4 ;
V_70 = F_21 ( V_7 , V_9 ,
V_69 +
F_29 ( struct V_80 , V_70 ) ) ;
V_53 = snprintf ( V_67 , sizeof( V_67 ) ,
L_1 ,
( T_2 ) ( V_70 >> 24 ) ,
( T_2 ) ( V_70 >> 16 ) ,
( T_2 ) ( V_70 >> 8 ) ,
( T_2 ) V_70 ) ;
if ( V_53 < 0 || V_53 >= sizeof( V_67 ) )
F_27 ( V_7 ,
L_8 ) ;
}
return F_24 ( V_39 , V_40 , L_9 , V_67 ) ;
}
static T_1 F_30 ( T_1 * V_39 ,
bool V_40 , const char * V_81 , T_1 V_82 )
{
return F_25 ( V_39 , V_40 , V_81 , V_82 ) ;
}
static T_1 F_31 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_39 ,
bool V_40 ,
T_2 V_83 )
{
struct V_10 * V_11 = & V_7 -> V_12 ;
T_1 V_48 = 0 ;
V_48 += F_30 ( V_39 + V_48 ,
V_40 ,
L_10 ,
V_84 +
V_83 ) ;
V_48 += F_26 ( V_7 , V_9 , V_39 + V_48 , V_40 ) ;
V_48 += F_28 ( V_7 ,
V_9 , V_39 + V_48 , V_40 ) ;
V_48 += F_25 ( V_39 + V_48 ,
V_40 , L_11 , V_85 ) ;
V_48 += F_24 ( V_39 + V_48 ,
V_40 ,
L_12 ,
V_86 [ V_11 -> V_16 ] . V_81 ) ;
V_48 += F_24 ( V_39 + V_48 ,
V_40 ,
L_13 ,
V_87 [ V_11 -> V_23 ] .
V_81 ) ;
V_48 +=
F_25 ( V_39 + V_48 , V_40 , L_14 ,
V_7 -> V_88 ) ;
return V_48 ;
}
static T_1 F_32 ( T_1 * V_39 , T_1 V_48 , bool V_40 )
{
T_1 V_89 = V_48 , V_90 = ~ 0 ;
V_48 += F_30 ( V_39 + V_48 , V_40 , L_15 , 0 ) ;
if ( V_40 )
* ( V_39 + V_48 ) = ~ F_33 ( V_90 , ( T_2 * ) V_39 ,
F_19 ( V_48 ) ) ;
V_48 ++ ;
return V_48 - V_89 ;
}
static void F_34 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_7 -> V_12 ;
T_1 V_91 [ V_92 ] = { 0 } ;
T_1 V_35 ;
for ( V_35 = 0 ; V_35 < V_92 ; V_35 ++ )
if ( V_93 [ V_35 ] . V_94 [ V_11 -> V_16 ] )
V_91 [ V_35 ] = F_21 ( V_7 ,
V_9 , V_93 [ V_35 ] . V_28 ) ;
for ( V_35 = 0 ; V_35 < V_95 ; V_35 ++ )
V_11 -> V_56 [ V_35 ] =
V_96 [ V_35 ] -> V_97 &&
! ( V_91 [ V_96 [ V_35 ] -> V_98 ] &
F_35 ( V_96 [ V_35 ] -> V_99 ) ) ;
}
static void F_36 ( struct V_6 * V_7 ,
struct V_8 * V_9 , bool V_100 )
{
F_37 ( V_7 , V_9 , V_101 , V_100 ? 1 : 0 ) ;
}
static void F_38 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
T_1 V_102 , V_103 , V_104 ;
V_102 =
V_93 [ V_96 [ V_105 ] -> V_98 ] . V_28 ;
V_103 = F_21 ( V_7 , V_9 , V_102 ) ;
V_104 = V_103 &
~ F_35 ( V_96 [ V_105 ] -> V_99 ) ;
F_37 ( V_7 , V_9 , V_102 , V_104 ) ;
F_37 ( V_7 , V_9 , V_102 , V_103 ) ;
}
static void F_39 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
enum V_106 V_107 )
{
F_37 ( V_7 , V_9 , V_108 , ( T_2 ) V_107 ) ;
}
static void F_40 ( struct V_6 * V_7 ,
struct V_8 * V_9 , T_1 V_109 )
{
F_37 ( V_7 , V_9 , V_110 , V_109 ) ;
}
static bool F_41 ( struct V_6 * V_7 , T_3 * V_111 )
{
const T_1 * V_112 = V_113 [ V_114 ] . V_112 ;
struct V_10 * V_11 = & V_7 -> V_12 ;
T_2 V_115 = ( ( T_2 * ) V_112 ) [ ( * V_111 ) ++ ] ;
bool V_116 , V_117 ;
switch ( V_115 ) {
case V_118 :
return ! F_41 ( V_7 , V_111 ) ;
case V_119 :
case V_120 :
V_116 = F_41 ( V_7 , V_111 ) ;
V_117 = F_41 ( V_7 , V_111 ) ;
return ( V_115 == V_119 ) ? ( V_116 ||
V_117 ) : ( V_116 && V_117 ) ;
default:
return V_11 -> V_18 [ V_115 - V_121 ] > 0 ;
}
}
static T_1 F_42 ( struct V_6 * V_7 ,
enum V_122 V_123 )
{
struct V_10 * V_11 = & V_7 -> V_12 ;
return V_11 -> V_124 . V_46 [ V_123 ] ;
}
static void F_43 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = & V_7 -> V_12 ;
T_1 V_35 ;
for ( V_35 = 0 ; V_35 < V_125 ; V_35 ++ )
V_11 -> V_124 . V_126 [ V_35 ] = 0 ;
}
static void F_44 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = & V_7 -> V_12 ;
T_1 V_35 ;
for ( V_35 = 0 ; V_35 < V_125 ; V_35 ++ )
if ( ! V_11 -> V_124 . V_126 [ V_35 ] )
V_11 -> V_124 . V_46 [ V_35 ] =
V_127 [ V_35 ] . V_128 [ V_11 -> V_16 ] ;
}
static bool F_45 ( struct V_6 * V_7 ,
enum V_122 V_123 )
{
return F_42 ( V_7 , V_123 ) > 0 ;
}
static bool F_46 ( struct V_6 * V_7 ,
enum V_129 V_130 )
{
return F_42 ( V_7 , (enum V_122 ) V_130 ) > 0 ;
}
static bool F_47 ( struct V_6 * V_7 ,
enum V_57 V_57 , T_2 V_131 )
{
T_2 V_35 ;
if ( V_96 [ V_57 ] -> V_132 &&
! F_46 ( V_7 ,
(enum V_129 ) V_96 [ V_57 ] -> V_26 ) )
return false ;
for ( V_35 = 0 ; V_35 < V_133 ; V_35 ++ )
if ( V_131 == V_134 [ V_35 ] . V_131 ||
V_131 == V_134 [ V_35 ] . V_135 )
return F_45 ( V_7 ,
V_134 [ V_35 ] . V_123 ) ;
if ( V_131 == V_136 || V_131 ==
V_137 )
return F_45 ( V_7 , V_138 ) ;
if ( V_131 == V_139 )
return F_45 ( V_7 , V_140 ) ;
if ( V_131 == V_141 )
return F_45 ( V_7 , V_142 ) ;
if ( V_131 == V_143 ||
V_131 == V_144 ||
V_131 == V_145 )
return F_45 ( V_7 , V_146 ) ;
if ( V_131 == V_147 )
return F_45 ( V_7 , V_148 ) ;
if ( V_131 == V_149 ||
V_131 == V_150 )
return F_45 ( V_7 , V_151 ) ;
if ( V_131 == V_152 || V_131 ==
V_153 )
return F_45 ( V_7 , V_154 ) ;
if ( V_131 == V_155 )
return F_45 ( V_7 , V_156 ) ;
if ( V_131 == V_157 )
return F_45 ( V_7 , V_158 ) ;
if ( V_131 == V_159 )
return F_45 ( V_7 , V_160 ) ;
if ( V_131 == V_161 )
return F_45 ( V_7 , V_162 ) ;
if ( V_131 == V_163 )
return F_45 ( V_7 , V_164 ) ;
if ( V_131 == V_165 || V_131 ==
V_166 )
return F_45 ( V_7 , V_167 ) ;
if ( V_131 == V_168 )
return F_45 ( V_7 , V_169 ) ;
if ( V_131 == V_170 )
return F_45 ( V_7 , V_171 ) ;
return true ;
}
static void F_48 ( struct V_6 * V_7 ,
struct V_8 * V_9 , bool V_172 )
{
T_2 V_91 = V_172 ? 1 : 0 ;
T_2 V_26 ;
for ( V_26 = 0 ; V_26 < V_55 ; V_26 ++ ) {
if ( F_46 ( V_7 ,
(enum V_129 ) V_26 ) ) {
T_1 V_173 =
V_29 [ V_26 ] . V_30 +
V_174 ;
F_37 ( V_7 , V_9 , V_173 , V_91 ) ;
}
}
F_49 ( V_175 ) ;
}
static void F_50 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_7 -> V_12 ;
T_1 V_91 [ V_92 ] = { 0 } ;
T_1 V_35 ;
for ( V_35 = 0 ; V_35 < V_95 ; V_35 ++ )
if ( V_96 [ V_35 ] -> V_97 && V_96 [ V_35 ] -> V_176 )
V_91 [ V_96 [ V_35 ] -> V_98 ] |=
F_35 ( V_96 [ V_35 ] -> V_99 ) ;
for ( V_35 = 0 ; V_35 < V_92 ; V_35 ++ ) {
if ( V_93 [ V_35 ] . V_94 [ V_11 -> V_16 ] ) {
V_91 [ V_35 ] |= V_93 [ V_35 ] . V_177 ;
if ( V_91 [ V_35 ] )
F_37 ( V_7 ,
V_9 ,
V_93 [ V_35 ] . V_28 +
V_178 , V_91 [ V_35 ] ) ;
}
}
}
static const struct V_179 *
F_51 ( enum V_57 V_57 , enum V_180 V_181 )
{
const struct V_182 * V_183 =
( const struct V_182 * )
V_113 [ V_184 ] . V_112 ;
return & V_183 [ V_57 ] . V_185 [ V_181 ] ;
}
static const struct V_186 *
F_52 ( enum V_57 V_57 , enum V_180 V_181 ,
T_2 * V_187 )
{
const struct V_179 * V_188 =
F_51 ( V_57 , V_181 ) ;
* V_187 = V_188 -> V_189 ;
return & ( ( const struct V_186 * )
V_113 [ V_190 ] . V_112 ) [ V_188 ->
V_191 ] ;
}
static void F_53 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_7 -> V_12 ;
T_2 V_192 , V_187 ;
T_1 V_57 ;
for ( V_57 = 0 ; V_57 < V_95 ; V_57 ++ ) {
const struct V_186 * V_193 ;
if ( V_11 -> V_56 [ V_57 ] )
continue;
V_193 = F_52 ( (enum V_57 ) V_57 ,
V_194 ,
& V_187 ) ;
for ( V_192 = 0 ; V_192 < V_187 ; V_192 ++ ) {
const struct V_186 * V_195 =
& V_193 [ V_192 ] ;
bool V_196 = F_54 ( V_195 -> V_107 . V_197 ,
V_198 ) > 0 ;
T_3 V_111 =
F_54 ( V_195 -> V_107 . V_197 ,
V_199 ) ;
if ( ! V_196 ||
F_41 ( V_7 , & V_111 ) )
F_21 ( V_7 , V_9 ,
F_19 ( V_195 ->
V_200 ) ) ;
}
}
}
static T_1 F_55 ( T_1 * V_39 ,
bool V_40 ,
T_1 V_201 ,
const char * V_202 ,
int V_203 ,
const char * V_45 , const char * V_46 )
{
T_2 V_82 = 2 + ( V_203 >= 0 ? 1 : 0 ) + ( V_45 ? 1 : 0 ) ;
T_1 V_48 = 0 ;
V_48 += F_30 ( V_39 + V_48 ,
V_40 , L_16 , V_82 ) ;
V_48 += F_25 ( V_39 + V_48 ,
V_40 , L_17 , V_201 ) ;
V_48 += F_24 ( V_39 + V_48 ,
V_40 , L_18 , V_202 ) ;
if ( V_203 >= 0 )
V_48 += F_25 ( V_39 + V_48 ,
V_40 , L_19 , V_203 ) ;
if ( V_45 && V_46 )
V_48 += F_24 ( V_39 + V_48 ,
V_40 , V_45 , V_46 ) ;
return V_48 ;
}
static T_1 F_56 ( struct V_6 * V_7 ,
struct V_8 * V_9 , T_1 * V_39 ,
bool V_40 , T_1 V_28 , T_1 V_204 )
{
T_1 V_48 = 0 , V_35 ;
if ( V_40 ) {
* ( V_39 + V_48 ++ ) = V_28 | ( V_204 << V_205 ) ;
for ( V_35 = 0 ; V_35 < V_204 ; V_35 ++ , V_28 ++ , V_48 ++ )
* ( V_39 + V_48 ) = F_21 ( V_7 ,
V_9 ,
F_19 ( V_28 ) ) ;
} else {
V_48 += V_204 + 1 ;
}
return V_48 ;
}
static T_1 F_57 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_206 V_207 ,
T_1 * V_39 ,
bool V_40 ,
bool V_208 [ V_95 ] ,
T_1 * V_209 )
{
T_1 V_35 , V_48 = 0 , V_210 = 0 ;
bool V_211 = true ;
* V_209 = 0 ;
while ( V_210 < V_207 . V_212 ) {
const struct V_213 * V_214 =
( const struct V_213 * )
& V_207 . V_112 [ V_210 ++ ] ;
bool V_196 = F_54 ( V_214 -> V_107 . V_197 ,
V_198 ) > 0 ;
if ( V_196 ) {
T_3 V_111 =
F_54 ( V_214 -> V_107 . V_197 ,
V_199 ) ;
V_211 = F_41 ( V_7 ,
& V_111 ) ;
}
if ( V_211 && V_208 [ V_214 -> V_57 ] ) {
for ( V_35 = 0 ; V_35 < V_214 -> V_215 ;
V_35 ++ , V_210 ++ ) {
const struct V_216 * V_217 =
( const struct V_216 * )
& V_207 . V_112 [ V_210 ] ;
V_48 +=
F_56 ( V_7 , V_9 ,
V_39 + V_48 , V_40 ,
F_54 ( V_217 -> V_197 ,
V_218 ) ,
F_54 ( V_217 -> V_197 ,
V_219 ) ) ;
( * V_209 ) ++ ;
}
} else {
V_210 += V_214 -> V_215 ;
}
}
return V_48 ;
}
static T_1 F_58 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_206 V_207 ,
T_1 * V_39 ,
bool V_40 ,
bool V_208 [ V_95 ] ,
const char * V_220 ,
T_1 V_203 ,
const char * V_45 ,
const char * V_46 )
{
T_1 V_209 , V_48 ;
V_48 = F_55 ( V_39 ,
false ,
0 ,
V_220 ,
V_203 , V_45 , V_46 ) ;
V_48 += F_57 ( V_7 ,
V_9 ,
V_207 ,
V_39 + V_48 ,
V_40 ,
V_208 ,
& V_209 ) ;
if ( V_40 && V_209 > 0 )
F_55 ( V_39 ,
V_40 ,
V_209 ,
V_220 ,
V_203 , V_45 , V_46 ) ;
return V_209 > 0 ? V_48 : 0 ;
}
static T_1 F_59 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_39 ,
bool V_40 ,
bool V_208 [ V_95 ] ,
const char * V_45 , const char * V_46 )
{
struct V_10 * V_11 = & V_7 -> V_12 ;
T_1 V_48 = 0 , V_210 = 0 ;
T_2 V_221 , V_222 ;
if ( V_40 )
F_60 ( V_7 , V_223 , L_20 ) ;
while ( V_210 <
V_113 [ V_224 ] . V_212 ) {
const struct V_225 * V_226 =
( const struct V_225 * )
& V_113 [ V_224 ] . V_112 [ V_210 ++ ] ;
T_2 V_227 = F_54 ( V_226 -> V_228 ,
V_229 ) ;
T_1 V_230 = F_54 ( V_226 -> V_228 ,
V_231 ) ;
struct V_206 V_232 = {
& V_113 [ V_224 ] . V_112 [ V_210 ] ,
V_230 } ;
switch ( V_227 ) {
case V_233 :
case V_234 :
V_48 += F_58 ( V_7 ,
V_9 ,
V_232 ,
V_39 + V_48 ,
V_40 ,
V_208 ,
L_21 ,
( T_1 ) ( - 1 ) ,
V_45 ,
V_46 ) ;
break;
case V_235 :
for ( V_221 = 0 ;
V_221 <
V_86 [ V_11 -> V_16 ] .
V_236 [ V_11 -> V_23 ] . V_237 ;
V_221 ++ ) {
if ( V_40 )
F_61 ( V_7 , V_9 ,
V_221 ) ;
V_48 +=
F_58 ( V_7 , V_9 ,
V_232 ,
V_39 + V_48 ,
V_40 , V_208 ,
L_22 , V_221 ,
V_45 ,
V_46 ) ;
}
break;
case V_238 :
case V_239 :
for ( V_222 = 0 ;
V_222 <
V_86 [ V_11 -> V_16 ] .
V_236 [ V_11 -> V_23 ] . V_240 ;
V_222 ++ ) {
if ( V_40 )
F_62 ( V_7 , V_9 , V_222 ) ;
V_48 += F_58 ( V_7 ,
V_9 ,
V_232 ,
V_39 + V_48 ,
V_40 , V_208 ,
L_23 , V_222 , V_45 ,
V_46 ) ;
}
break;
default:
break;
}
V_210 += V_230 ;
}
if ( V_40 )
F_62 ( V_7 , V_9 , V_7 -> V_241 ) ;
return V_48 ;
}
static T_1 F_63 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_39 , bool V_40 )
{
struct V_10 * V_11 = & V_7 -> V_12 ;
T_1 V_35 , V_48 = 0 , V_189 = 0 ;
V_48 += F_55 ( V_39 ,
false , 0 , L_21 , - 1 , NULL , NULL ) ;
for ( V_35 = 0 ; V_35 < V_92 ; V_35 ++ ) {
if ( V_93 [ V_35 ] . V_94 [ V_11 -> V_16 ] ) {
V_48 += F_56 ( V_7 ,
V_9 ,
V_39 + V_48 ,
V_40 ,
F_20
( V_93
[ V_35 ] . V_28 ) , 1 ) ;
V_189 ++ ;
}
}
if ( V_40 )
F_55 ( V_39 ,
true , V_189 , L_21 , - 1 , NULL , NULL ) ;
return V_48 ;
}
static T_1 F_64 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_39 , bool V_40 )
{
struct V_10 * V_11 = & V_7 -> V_12 ;
T_1 V_48 = 0 , V_201 = 0 , V_57 ;
T_2 V_26 , V_192 , V_187 ;
V_48 += F_55 ( V_39 ,
false , 0 , L_21 , - 1 , NULL , NULL ) ;
for ( V_57 = 0 ; V_57 < V_95 ; V_57 ++ ) {
const struct V_186 * V_193 ;
if ( V_11 -> V_56 [ V_57 ] && V_40 )
continue;
V_193 = F_52 ( (enum V_57 ) V_57 ,
V_194 ,
& V_187 ) ;
for ( V_192 = 0 ; V_192 < V_187 ; V_192 ++ ) {
const struct V_186 * V_195 =
& V_193 [ V_192 ] ;
T_3 V_111 ;
bool V_196 ;
V_196 = F_54 ( V_195 -> V_107 . V_197 ,
V_198 ) > 0 ;
V_111 =
F_54 ( V_195 -> V_107 . V_197 ,
V_199 ) ;
if ( ! V_196 ||
F_41 ( V_7 , & V_111 ) ) {
V_48 += F_56 ( V_7 ,
V_9 ,
V_39 + V_48 ,
V_40 ,
V_195 -> V_242 ,
1 ) ;
V_48 += F_56 ( V_7 ,
V_9 ,
V_39 + V_48 ,
V_40 ,
F_54 ( V_195 -> V_197 ,
V_243 ) ,
1 ) ;
V_201 += 2 ;
}
}
}
for ( V_26 = 0 ; V_26 < V_55 ; V_26 ++ ) {
if ( V_11 -> V_56 [ V_29 [ V_26 ] . V_57 ] &&
V_40 )
continue;
V_48 += F_56 ( V_7 ,
V_9 ,
V_39 + V_48 ,
V_40 ,
F_20 ( V_29 [ V_26 ] .
V_30 +
V_244 ) ,
1 ) ;
V_201 ++ ;
}
if ( V_40 )
F_55 ( V_39 ,
true ,
V_201 , L_21 , - 1 , NULL , NULL ) ;
return V_48 ;
}
static T_1 F_65 ( struct V_6 * V_7 ,
T_1 * V_39 ,
bool V_40 ,
const char * V_81 ,
T_1 V_245 ,
T_1 V_246 ,
T_1 V_247 ,
bool V_248 ,
const char * V_249 ,
bool V_250 , char V_251 )
{
T_2 V_82 = 3 ;
T_1 V_48 = 0 ;
char V_3 [ 64 ] ;
if ( ! V_246 )
F_27 ( V_7 ,
L_24 ) ;
if ( V_247 )
V_82 ++ ;
if ( V_248 )
V_82 ++ ;
V_48 += F_30 ( V_39 + V_48 ,
V_40 , L_25 , V_82 ) ;
if ( V_81 ) {
if ( V_250 ) {
strcpy ( V_3 , L_26 ) ;
V_3 [ 0 ] = V_251 ;
strcpy ( V_3 + strlen ( V_3 ) , V_81 ) ;
} else {
strcpy ( V_3 , V_81 ) ;
}
V_48 += F_24 ( V_39 + V_48 ,
V_40 , L_27 , V_3 ) ;
if ( V_40 )
F_60 ( V_7 ,
V_223 ,
L_28 ,
V_246 , V_3 ) ;
} else {
V_48 += F_25 ( V_39 + V_48 ,
V_40 , L_29 , V_245 ) ;
if ( V_40 && V_246 > 64 )
F_60 ( V_7 ,
V_223 ,
L_30 ,
V_246 , V_245 ) ;
}
V_48 += F_25 ( V_39 + V_48 , V_40 , L_31 , V_246 ) ;
if ( V_247 )
V_48 += F_25 ( V_39 + V_48 ,
V_40 , L_32 , V_247 ) ;
if ( V_248 )
V_48 += F_25 ( V_39 + V_48 ,
V_40 , L_33 , 1 ) ;
if ( V_250 ) {
strcpy ( V_3 , L_26 ) ;
V_3 [ 0 ] = V_251 ;
strcpy ( V_3 + strlen ( V_3 ) , V_249 ) ;
} else {
strcpy ( V_3 , V_249 ) ;
}
V_48 += F_24 ( V_39 + V_48 , V_40 , L_34 , V_3 ) ;
return V_48 ;
}
static T_1 F_66 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_39 ,
bool V_40 ,
const char * V_81 ,
T_1 V_245 ,
T_1 V_246 ,
T_1 V_247 ,
bool V_248 ,
const char * V_249 ,
bool V_250 , char V_251 )
{
T_1 V_48 = 0 ;
V_48 += F_65 ( V_7 ,
V_39 + V_48 ,
V_40 ,
V_81 ,
V_245 ,
V_246 ,
V_247 ,
V_248 ,
V_249 , V_250 , V_251 ) ;
if ( V_40 ) {
T_1 V_35 ;
for ( V_35 = 0 ; V_35 < V_246 ;
V_35 ++ , V_245 += V_36 , V_48 ++ )
* ( V_39 + V_48 ) = F_21 ( V_7 , V_9 , V_245 ) ;
} else {
V_48 += V_246 ;
}
return V_48 ;
}
static T_1 F_67 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_206 V_252 ,
T_1 * V_39 , bool V_40 )
{
T_1 V_35 , V_48 = 0 , V_210 = 0 ;
bool V_211 = true ;
while ( V_210 < V_252 . V_212 ) {
const struct V_213 * V_214 ;
T_1 V_253 ;
bool V_196 ;
V_214 = ( const struct V_213 * )
& V_252 . V_112 [ V_210 ++ ] ;
V_196 = F_54 ( V_214 -> V_107 . V_197 ,
V_198 ) > 0 ;
if ( V_196 ) {
T_3 V_111 =
F_54 ( V_214 -> V_107 . V_197 ,
V_199 ) ;
V_211 = F_41 ( V_7 ,
& V_111 ) ;
}
if ( ! V_211 ) {
V_210 += V_214 -> V_215 ;
continue;
}
V_253 = V_214 -> V_215 / V_254 ;
for ( V_35 = 0 ; V_35 < V_253 ;
V_35 ++ , V_210 += V_254 ) {
const struct V_255 * V_256 =
( const struct V_255 * )
& V_252 . V_112 [ V_210 ] ;
T_2 V_131 ;
V_131 = F_54 ( V_256 -> V_257 ,
V_258 ) ;
if ( V_131 >= V_259 ) {
F_27 ( V_7 , L_35 ) ;
return 0 ;
}
if ( F_47 ( V_7 ,
(enum V_57 ) V_214 -> V_57 ,
V_131 ) ) {
T_1 V_260 =
F_19 ( F_54 ( V_256 -> V_257 ,
V_261 ) ) ;
T_1 V_262 = F_54 ( V_256 -> V_263 ,
V_264 ) ;
char V_251 = 'a' ;
bool V_250 = false ;
if ( V_131 == V_149 )
V_262 = F_42 ( V_7 ,
V_265 )
* ( V_262 / V_266 ) ;
else if ( V_131 == V_150 )
V_262 = F_42 ( V_7 ,
V_267 )
* ( V_262 / V_268 ) ;
if ( V_96 [ V_214 -> V_57 ] ->
V_132 ) {
V_250 = true ;
V_251 =
V_29 [ V_96 [
V_214 -> V_57 ] ->
V_26 ] . V_269 ;
}
V_48 += F_66 ( V_7 , V_9 ,
V_39 + V_48 , V_40 , NULL ,
V_260 , V_262 , 0 ,
false ,
V_270 [ V_131 ] ,
V_250 , V_251 ) ;
}
}
}
return V_48 ;
}
static T_1 F_68 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_39 , bool V_40 )
{
T_1 V_48 = 0 , V_210 = 0 ;
while ( V_210 <
V_113 [ V_271 ] . V_212 ) {
const struct V_225 * V_226 =
( const struct V_225 * )
& V_113 [ V_271 ] . V_112 [ V_210 ++ ] ;
T_2 V_227 = F_54 ( V_226 -> V_228 ,
V_229 ) ;
T_1 V_230 = F_54 ( V_226 -> V_228 ,
V_231 ) ;
struct V_206 V_272 = {
& V_113 [ V_271 ] . V_112 [ V_210 ] ,
V_230 } ;
switch ( V_227 ) {
case V_233 :
V_48 += F_67 ( V_7 ,
V_9 ,
V_272 ,
V_39 + V_48 ,
V_40 ) ;
break;
default:
F_27 ( V_7 ,
L_36 ) ;
break;
}
V_210 += V_230 ;
}
return V_48 ;
}
static T_1 F_69 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_39 ,
bool V_40 ,
const char * V_81 ,
T_1 V_273 ,
T_1 V_274 ,
T_1 V_275 ,
T_2 V_26 )
{
T_1 V_35 , V_276 , V_277 ;
T_1 V_48 = 0 ;
if ( ! V_274 )
return 0 ;
V_274 *= V_36 ;
V_277 = V_273 * V_274 ;
V_48 += F_65 ( V_7 ,
V_39 + V_48 ,
V_40 ,
V_81 ,
0 ,
V_277 ,
V_274 * 32 ,
false ,
V_81 ,
true , V_29 [ V_26 ] . V_269 ) ;
if ( V_40 ) {
for ( V_276 = 0 ; V_276 < V_273 ; V_276 ++ ) {
for ( V_35 = 0 ; V_35 < V_274 ; V_35 ++ , V_48 ++ ) {
F_37 ( V_7 ,
V_9 ,
V_29 [ V_26 ] . V_278 ,
F_35 ( 9 ) | V_276 ) ;
* ( V_39 + V_48 ) = F_21 ( V_7 ,
V_9 ,
V_275 ) ;
}
}
} else {
V_48 += V_277 ;
}
return V_48 ;
}
static T_1 F_70 ( struct V_6 * V_7 ,
struct V_8 * V_9 , T_1 * V_39 , bool V_40 )
{
T_1 V_48 = 0 ;
T_2 V_26 ;
for ( V_26 = 0 ; V_26 < V_55 ; V_26 ++ ) {
if ( ! F_46 ( V_7 ,
(enum V_129 ) V_26 ) )
continue;
V_48 +=
F_69 ( V_7 ,
V_9 ,
V_39 + V_48 ,
V_40 ,
L_37 ,
F_42 ( V_7 ,
V_265 ) ,
V_29 [ V_26 ] .
V_279 ,
V_29 [ V_26 ] .
V_280 ,
V_26 ) ;
V_48 +=
F_69 ( V_7 ,
V_9 ,
V_39 + V_48 ,
V_40 ,
L_38 ,
F_42 ( V_7 ,
V_265 ) ,
V_29 [ V_26 ] .
V_281 ,
V_29 [ V_26 ] .
V_282 ,
V_26 ) ;
V_48 +=
F_69 ( V_7 ,
V_9 ,
V_39 + V_48 ,
V_40 ,
L_39 ,
F_42 ( V_7 ,
V_267 ) ,
V_29 [ V_26 ] .
V_283 ,
V_29 [ V_26 ] .
V_284 ,
V_26 ) ;
V_48 +=
F_69 ( V_7 ,
V_9 ,
V_39 + V_48 ,
V_40 ,
L_40 ,
F_42 ( V_7 ,
V_267 ) ,
V_29 [ V_26 ] .
V_285 ,
V_29 [ V_26 ] .
V_286 ,
V_26 ) ;
}
return V_48 ;
}
static T_1 F_71 ( struct V_6 * V_7 ,
struct V_8 * V_9 , T_1 * V_39 , bool V_40 )
{
char V_3 [ 10 ] = L_41 ;
T_2 V_26 , V_287 ;
T_1 V_48 = 0 ;
for ( V_26 = 0 ; V_26 < V_55 ; V_26 ++ ) {
if ( F_46 ( V_7 ,
(enum V_129 ) V_26 ) ) {
for ( V_287 = 0 ; V_287 < V_288 ; V_287 ++ ) {
T_1 V_28 =
V_29 [ V_26 ] . V_30 +
V_289 +
F_19 ( F_72 ( V_287 ) ) ;
V_3 [ strlen ( V_3 ) - 1 ] = '0' + V_287 ;
V_48 += F_66 ( V_7 ,
V_9 ,
V_39 + V_48 ,
V_40 ,
V_3 ,
V_28 ,
V_290 ,
32 ,
false ,
L_42 ,
true ,
V_29
[ V_26 ] . V_269 ) ;
}
}
}
return V_48 ;
}
static T_1 F_73 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_39 , bool V_40 , T_2 V_26 )
{
T_1 V_277 = V_291 * V_292 ;
T_1 V_293 [ V_294 ] = { 0 } ;
T_1 V_295 [ V_296 ] = { 0 } ;
T_1 V_48 = 0 ;
T_1 V_297 , V_35 ;
V_48 += F_65 ( V_7 ,
V_39 + V_48 ,
V_40 ,
L_43 ,
0 ,
V_277 ,
256 ,
false ,
L_43 ,
true , V_29 [ V_26 ] . V_269 ) ;
if ( V_40 ) {
F_74 ( V_293 , V_298 , V_299 , V_300 ) ;
for ( V_297 = 0 ; V_297 < V_291 ;
V_297 ++ , V_48 += V_292 ) {
F_74 ( V_295 , V_301 , V_302 , V_297 ) ;
F_75 ( V_7 ,
V_9 ,
V_29 [ V_26 ] . V_30 +
V_303 ,
V_295 , V_296 ) ;
F_75 ( V_7 ,
V_9 ,
V_29 [ V_26 ] . V_30 +
V_304 ,
V_293 , V_294 ) ;
F_76 ( V_7 ,
V_9 ,
V_29 [ V_26 ] . V_30 +
V_305 ,
V_39 + V_48 , V_292 ) ;
}
} else {
V_48 += V_277 ;
}
return V_48 ;
}
static T_1 F_77 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_39 ,
bool V_40 ,
T_2 V_26 , struct V_306 * V_307 )
{
T_1 V_277 = V_307 -> V_308 * V_309 ;
T_1 V_310 [ V_311 ] = { 0 } ;
T_1 V_312 [ V_313 ] = { 0 } ;
T_1 V_48 = 0 ;
T_1 V_297 , V_35 ;
V_48 += F_65 ( V_7 ,
V_39 + V_48 ,
V_40 ,
V_307 -> V_314 ,
0 ,
V_277 ,
256 ,
false ,
V_307 -> V_315 ,
true , V_29 [ V_26 ] . V_269 ) ;
F_74 ( V_310 , V_316 , V_299 , V_317 ) ;
if ( ! V_40 )
return V_48 + V_277 ;
for ( V_297 = V_307 -> V_318 ;
V_297 < V_307 -> V_318 + V_307 -> V_308 ;
V_297 ++ , V_48 += V_309 ) {
F_75 ( V_7 ,
V_9 ,
V_29 [ V_26 ] . V_30 +
V_303 ,
V_312 , V_313 ) ;
F_74 ( V_310 , V_316 , V_302 , V_297 ) ;
F_75 ( V_7 ,
V_9 ,
V_29 [ V_26 ] . V_30 +
V_304 ,
V_310 , V_311 ) ;
F_76 ( V_7 ,
V_9 ,
V_29 [ V_26 ] . V_30 +
V_305 ,
V_39 + V_48 , V_309 ) ;
}
return V_48 ;
}
static T_1 F_78 ( struct V_6 * V_7 ,
struct V_8 * V_9 , T_1 * V_39 , bool V_40 )
{
struct V_10 * V_11 = & V_7 -> V_12 ;
T_2 V_26 , V_35 ;
T_1 V_48 = 0 ;
for ( V_26 = 0 ; V_26 < V_55 ; V_26 ++ ) {
if ( F_46 ( V_7 ,
(enum V_129 ) V_26 ) &&
V_29 [ V_26 ] . V_319 &&
( V_26 != V_320 ||
V_11 -> V_23 == V_24 ) ) {
V_48 += F_73 ( V_7 ,
V_9 ,
V_39 + V_48 ,
V_40 , V_26 ) ;
for ( V_35 = 0 ; V_35 < V_321 ; V_35 ++ )
V_48 += F_77 ( V_7 ,
V_9 ,
V_39 +
V_48 ,
V_40 ,
V_26 ,
& V_322
[ V_35 ] ) ;
}
}
return V_48 ;
}
static T_1 F_79 ( struct V_6 * V_7 ,
struct V_8 * V_9 , T_1 * V_39 , bool V_40 )
{
struct V_10 * V_11 = & V_7 -> V_12 ;
T_1 V_48 = 0 ;
T_2 V_323 ;
for ( V_323 = 0 ; V_323 < V_324 ; V_323 ++ ) {
struct V_325 * V_326 = & V_327 [ V_323 ] ;
T_1 V_253 = V_326 -> V_253 [ V_11 -> V_16 ] ;
T_1 V_328 = V_326 -> V_328 [ V_11 -> V_16 ] ;
T_1 V_277 = ( V_253 * V_328 ) / 32 ;
bool V_248 = ( V_328 == 16 ) ;
T_1 V_28 = V_326 -> V_28 ;
T_1 V_35 , V_329 ;
V_48 += F_65 ( V_7 ,
V_39 + V_48 ,
V_40 ,
V_326 -> V_314 ,
V_28 ,
V_277 ,
V_328 ,
V_248 ,
V_326 -> V_315 , false , 0 ) ;
if ( ! V_40 ) {
V_48 += V_277 ;
continue;
}
for ( V_35 = 0 ; V_35 < F_20 ( V_277 ) ; V_35 ++ , V_28 ++ ) {
F_37 ( V_7 , V_9 , V_330 , V_28 ) ;
for ( V_329 = 0 ; V_329 < V_36 ; V_329 ++ , V_48 ++ )
* ( V_39 + V_48 ) =
F_21 ( V_7 , V_9 ,
V_331 +
F_19 ( V_329 ) ) ;
}
}
return V_48 ;
}
static T_1 F_80 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_39 , bool V_40 , T_2 V_332 )
{
struct V_10 * V_11 = & V_7 -> V_12 ;
char V_314 [ 12 ] = L_44 ;
char V_315 [ 8 ] = L_45 ;
T_1 V_333 , V_334 ;
T_1 V_48 = 0 , V_35 , V_329 ;
V_334 =
V_134 [ V_332 ] . V_335 [ V_11 -> V_16 ] ;
V_333 = V_334 * V_336 ;
strncpy ( V_315 , V_134 [ V_332 ] . V_337 ,
strlen ( V_134 [ V_332 ] . V_337 ) ) ;
strncpy ( V_314 , V_134 [ V_332 ] . V_337 ,
strlen ( V_134 [ V_332 ] . V_337 ) ) ;
V_48 += F_65 ( V_7 ,
V_39 + V_48 ,
V_40 ,
V_314 ,
0 ,
V_333 ,
V_338 * 8 ,
false , V_315 , false , 0 ) ;
if ( ! V_40 )
return V_48 + V_333 ;
for ( V_35 = 0 ; V_35 < V_334 / 2 ; V_35 ++ ) {
F_37 ( V_7 , V_9 , V_134 [ V_332 ] . V_339 ,
V_35 ) ;
for ( V_329 = 0 ; V_329 < 2 * V_336 ; V_329 ++ , V_48 ++ )
* ( V_39 + V_48 ) = F_21 ( V_7 , V_9 ,
V_134 [ V_332 ] .
V_340 +
F_19 ( V_329 ) ) ;
}
return V_48 ;
}
static T_1 F_81 ( struct V_6 * V_7 ,
struct V_8 * V_9 , T_1 * V_39 , bool V_40 )
{
bool V_208 [ V_95 ] = { 0 } ;
bool V_341 = false ;
T_1 V_48 = 0 ;
if ( V_40 ) {
V_341 = ! F_82 ( V_7 , V_9 ) ;
if ( ! V_341 )
F_27 ( V_7 , L_46 ) ;
}
V_48 += F_66 ( V_7 ,
V_9 ,
V_39 + V_48 ,
V_40 ,
NULL ,
V_74 ,
V_342 ,
0 , false , L_47 , false , 0 ) ;
V_48 += F_66 ( V_7 ,
V_9 ,
V_39 + V_48 ,
V_40 ,
NULL ,
V_343 ,
V_344 ,
0 , false , L_47 , false , 0 ) ;
V_208 [ V_345 ] = true ;
V_48 += F_59 ( V_7 ,
V_9 ,
V_39 + V_48 ,
V_40 , V_208 , L_48 , L_47 ) ;
V_48 += F_55 ( V_39 + V_48 ,
V_40 , 1 , L_21 , - 1 , L_48 , L_47 ) ;
V_48 += F_56 ( V_7 ,
V_9 ,
V_39 + V_48 ,
V_40 ,
F_20
( V_73 ) , 1 ) ;
if ( V_341 && F_83 ( V_7 , V_9 ) )
F_27 ( V_7 , L_49 ) ;
return V_48 ;
}
static T_1 F_84 ( struct V_6 * V_7 ,
struct V_8 * V_9 , T_1 * V_39 , bool V_40 )
{
T_1 V_48 = 0 , V_346 , V_347 ;
char V_314 [ 32 ] ;
T_2 V_348 ;
for ( V_348 = 0 ; V_348 < F_85 ( V_349 ) ; V_348 ++ ) {
struct V_350 * V_350 = & V_349 [ V_348 ] ;
int V_53 ;
V_53 = snprintf ( V_314 , sizeof( V_314 ) , L_50 ,
V_350 -> V_351 ) ;
if ( V_53 < 0 || V_53 >= sizeof( V_314 ) )
F_27 ( V_7 ,
L_51 ) ;
V_48 += F_65 ( V_7 ,
V_39 + V_48 ,
V_40 ,
V_314 ,
0 ,
V_352 ,
16 , true , V_314 , false , 0 ) ;
if ( V_40 ) {
T_1 V_353 = V_350 -> V_354 +
V_350 -> V_355 ;
T_1 V_356 = V_350 -> V_354 +
V_350 -> V_357 ;
T_1 V_358 = V_350 -> V_354 +
V_350 -> V_359 ;
T_1 V_360 = V_350 -> V_354 +
V_350 -> V_361 ;
T_2 * V_362 = ( T_2 * ) ( V_39 + V_48 ) ;
for ( V_347 = 0 ;
V_347 < ( V_363 >> 8 ) ;
V_347 ++ ) {
F_37 ( V_7 ,
V_9 , V_356 , V_347 ) ;
for ( V_346 = 0 ; V_346 < 256 ;
V_346 ++ ) {
F_37 ( V_7 ,
V_9 ,
V_353 , V_346 ) ;
* ( V_362 ++ ) =
( T_2 ) F_21 ( V_7 , V_9 ,
V_358 ) ;
* ( V_362 ++ ) =
( T_2 ) F_21 ( V_7 , V_9 ,
V_360 ) ;
}
}
}
V_48 += V_352 ;
}
return V_48 ;
}
static void F_86 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
enum V_57 V_57 ,
T_2 V_364 ,
T_2 V_365 ,
T_2 V_366 , T_2 V_367 , T_2 V_368 )
{
struct V_369 * V_370 = V_96 [ V_57 ] ;
F_37 ( V_7 , V_9 , V_370 -> V_371 , V_364 ) ;
F_37 ( V_7 , V_9 , V_370 -> V_372 , V_365 ) ;
F_37 ( V_7 , V_9 , V_370 -> V_373 , V_366 ) ;
F_37 ( V_7 , V_9 , V_370 -> V_374 , V_367 ) ;
F_37 ( V_7 , V_9 , V_370 -> V_375 , V_368 ) ;
}
static T_1 F_87 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_39 , bool V_40 )
{
T_1 V_376 = V_377 * V_378 ;
struct V_10 * V_11 = & V_7 -> V_12 ;
T_1 V_48 = 0 , V_57 , V_364 , V_28 , V_35 ;
struct V_369 * V_370 ;
if ( V_40 ) {
F_60 ( V_7 ,
V_223 , L_52 ) ;
for ( V_57 = 0 ; V_57 < V_95 ; V_57 ++ ) {
V_370 = V_96 [ V_57 ] ;
if ( V_370 -> V_379 [ V_11 -> V_16 ] )
F_37 ( V_7 , V_9 ,
V_370 -> V_372 , 0 ) ;
}
F_38 ( V_7 , V_9 ) ;
F_39 ( V_7 ,
V_9 , V_380 ) ;
F_37 ( V_7 ,
V_9 , V_381 , V_382 ) ;
F_37 ( V_7 , V_9 , V_383 , 1 ) ;
F_36 ( V_7 , V_9 , true ) ;
}
for ( V_57 = 0 ; V_57 < V_95 ; V_57 ++ ) {
V_370 = V_96 [ V_57 ] ;
if ( ! V_370 -> V_379 [ V_11 -> V_16 ] )
continue;
V_48 += F_65 ( V_7 ,
V_39 + V_48 ,
V_40 ,
V_370 -> V_81 , 0 ,
V_376 , 32 , false ,
L_53 , false , 0 ) ;
if ( V_40 && ! V_11 -> V_56 [ V_57 ] ) {
T_2 V_384 =
V_370 -> V_384 [ V_11 -> V_16 ] ;
F_40 ( V_7 , V_9 ,
F_35 ( V_384 ) ) ;
for ( V_364 = 0 ; V_364 < V_377 ;
V_364 ++ ) {
F_86 ( V_7 ,
V_9 ,
(enum V_57 ) V_57 ,
( T_2 ) V_364 ,
0xf , 0 , 0 , 0 ) ;
for ( V_35 = 0 , V_28 = V_385 ;
V_35 < V_378 ;
V_35 ++ , V_48 ++ , V_28 += V_36 )
V_39 [ V_48 ] = F_21 ( V_7 , V_9 ,
V_28 ) ;
}
F_40 ( V_7 , V_9 , 0 ) ;
F_37 ( V_7 , V_9 ,
V_370 -> V_372 , 0 ) ;
} else {
if ( V_40 )
memset ( V_39 + V_48 , 0 ,
F_19 ( V_376 ) ) ;
V_48 += V_376 ;
}
}
if ( V_40 ) {
F_36 ( V_7 , V_9 , false ) ;
F_40 ( V_7 , V_9 , 0 ) ;
}
return V_48 ;
}
static enum V_5 F_88 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_39 ,
bool V_40 , T_1 * V_386 )
{
struct V_10 * V_11 = & V_7 -> V_12 ;
bool V_387 = false ;
T_2 V_35 , V_388 = 0 ;
T_1 V_48 = 0 ;
* V_386 = 0 ;
F_44 ( V_7 ) ;
if ( V_40 ) {
switch ( F_21 ( V_7 , V_9 , V_389 ) ) {
case 0 :
V_388 = 1 ;
break;
case 1 :
V_388 = 2 ;
break;
case 2 :
V_388 = 4 ;
break;
}
}
if ( V_40 )
F_34 ( V_7 , V_9 ) ;
V_48 += F_31 ( V_7 ,
V_9 ,
V_39 + V_48 , V_40 , 4 ) ;
V_48 += F_24 ( V_39 + V_48 ,
V_40 , L_54 , L_55 ) ;
V_48 += F_25 ( V_39 + V_48 ,
V_40 ,
L_56 ,
F_42 ( V_7 ,
V_265 ) ) ;
V_48 += F_25 ( V_39 + V_48 ,
V_40 ,
L_57 ,
F_42 ( V_7 ,
V_267 ) ) ;
V_48 += F_25 ( V_39 + V_48 ,
V_40 , L_58 , V_388 ) ;
if ( F_45 ( V_7 , V_390 ) )
V_48 += F_63 ( V_7 ,
V_9 ,
V_39 + V_48 , V_40 ) ;
if ( V_40 ) {
F_50 ( V_7 , V_9 ) ;
F_34 ( V_7 , V_9 ) ;
}
if ( V_40 ) {
V_387 = ! F_89 ( V_7 , V_9 , 1 ) ;
if ( ! V_387 ) {
if ( F_42
( V_7 , V_391 ) )
return V_392 ;
else
F_27 ( V_7 ,
L_59 ) ;
}
}
if ( F_45 ( V_7 , V_390 ) )
V_48 += F_64 ( V_7 ,
V_9 ,
V_39 + V_48 , V_40 ) ;
if ( V_40 &&
( F_45 ( V_7 ,
V_171 ) ||
F_45 ( V_7 , V_393 ) ) )
F_48 ( V_7 , V_9 , true ) ;
if ( F_45 ( V_7 , V_390 ) ) {
bool V_208 [ V_95 ] ;
for ( V_35 = 0 ; V_35 < V_95 ; V_35 ++ )
V_208 [ V_35 ] = true ;
V_208 [ V_345 ] = false ;
V_48 += F_59 ( V_7 ,
V_9 ,
V_39 +
V_48 ,
V_40 ,
V_208 , NULL , NULL ) ;
}
V_48 += F_68 ( V_7 , V_9 , V_39 + V_48 , V_40 ) ;
if ( F_45 ( V_7 , V_394 ) )
V_48 += F_81 ( V_7 ,
V_9 , V_39 + V_48 , V_40 ) ;
if ( F_45 ( V_7 , V_395 ) )
V_48 += F_70 ( V_7 ,
V_9 , V_39 + V_48 , V_40 ) ;
if ( F_45 ( V_7 , V_396 ) )
V_48 += F_79 ( V_7 ,
V_9 , V_39 + V_48 , V_40 ) ;
for ( V_35 = 0 ; V_35 < V_133 ; V_35 ++ )
if ( F_45 ( V_7 , V_134 [ V_35 ] . V_123 ) )
V_48 += F_80 ( V_7 ,
V_9 ,
V_39 + V_48 ,
V_40 , V_35 ) ;
if ( F_45 ( V_7 , V_171 ) )
V_48 += F_71 ( V_7 ,
V_9 , V_39 + V_48 , V_40 ) ;
if ( F_45 ( V_7 , V_393 ) )
V_48 += F_78 ( V_7 ,
V_9 , V_39 + V_48 , V_40 ) ;
if ( F_45 ( V_7 ,
V_397 ) && V_11 -> V_16 ==
V_17 && V_11 -> V_23 == V_24 )
V_48 += F_84 ( V_7 ,
V_9 , V_39 + V_48 , V_40 ) ;
if ( F_45 ( V_7 ,
V_398 ) &&
V_11 -> V_399 . V_400 == V_401 )
V_48 += F_87 ( V_7 ,
V_9 ,
V_39 + V_48 , V_40 ) ;
V_48 += F_32 ( V_39 , V_48 , V_40 ) ;
if ( V_40 ) {
if ( F_42 ( V_7 , V_402 ) )
F_48 ( V_7 , V_9 , false ) ;
F_53 ( V_7 , V_9 ) ;
if ( V_387 )
F_89 ( V_7 , V_9 , 0 ) ;
}
* V_386 = V_48 ;
return V_14 ;
}
static T_1 F_90 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 *
V_39 ,
bool V_40 ,
T_3 V_403 ,
const struct V_404 * V_405 ,
T_3 V_406 , T_1 * V_407 )
{
const union V_408 * V_409 = & ( ( const union V_408 * )
V_113
[ V_410 ] .
V_112 ) [ V_405 -> V_411 ] ;
const struct V_412 * V_413 = & V_409 [ 0 ] . V_414 ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_415 * V_228 =
(struct V_415 * ) V_39 ;
const struct V_416 * V_417 =
& V_409 [ V_405 -> V_418 ] . V_419 ;
T_1 V_420 = 0 , V_35 , V_48 = 0 ;
T_2 V_421 ;
if ( V_40 ) {
memset ( V_228 , 0 , sizeof( * V_228 ) ) ;
V_228 -> V_403 = V_403 ;
V_228 -> V_422 = V_406 ;
V_228 -> V_423 = V_405 -> V_423 ;
V_228 -> V_424 = V_405 -> V_418 ;
}
V_48 += V_425 ;
for ( V_421 = 0 ; V_421 < V_405 -> V_418 ; V_421 ++ ) {
const struct V_412 * V_217 = & V_413 [ V_421 ] ;
if ( V_40 ) {
struct V_426 * V_427 =
(struct V_426 * ) ( V_39
+ V_48 ) ;
V_48 += V_428 ;
memset ( V_427 , 0 ,
sizeof( struct V_426 ) ) ;
V_427 -> V_429 = V_217 -> V_429 ;
V_427 -> V_37 = V_217 -> V_430 ;
F_91 ( V_427 -> V_197 ,
V_431 ,
V_217 -> V_253 > 1 || V_217 -> V_429 > 0
? 1 : 0 ) ;
F_91 ( V_427 -> V_197 ,
V_432 , V_421 ) ;
for ( V_35 = 0 ; V_35 < V_427 -> V_37 ;
V_35 ++ , V_420 ++ , V_48 ++ )
V_39 [ V_48 ] =
V_407 [ V_420 ] ;
} else {
V_48 += V_428 +
V_217 -> V_430 ;
}
}
for ( V_421 = 0 ; V_421 < V_405 -> V_433 ; V_421 ++ ) {
const struct V_416 * V_217 = & V_417 [ V_421 ] ;
T_1 V_57 ;
if ( ! V_40 ) {
V_48 += V_428 + V_217 -> V_37 ;
continue;
}
V_57 = F_54 ( V_217 -> V_197 , V_434 ) ;
if ( V_57 >= V_95 ) {
F_27 ( V_7 , L_60 ) ;
return 0 ;
}
if ( ! V_11 -> V_56 [ V_57 ] ) {
bool V_196 = F_54 ( V_217 -> V_107 . V_197 ,
V_198 ) > 0 ;
bool V_211 = true ;
if ( V_196 ) {
T_3 V_111 =
F_54 ( V_217 -> V_107 . V_197 ,
V_199 ) ;
V_211 =
F_41 ( V_7 ,
& V_111 ) ;
}
if ( V_211 ) {
T_1 V_38 =
F_19 ( F_54 ( V_217 -> V_197 ,
V_435 ) ) ;
struct V_426 * V_427 =
(struct V_426 * )
( V_39 + V_48 ) ;
V_48 += V_428 ;
V_228 -> V_436 ++ ;
memset ( V_427 , 0 , sizeof( * V_427 ) ) ;
V_427 -> V_37 = V_217 -> V_37 ;
F_91 ( V_427 -> V_197 ,
V_432 ,
V_405 -> V_418 + V_421 ) ;
for ( V_35 = 0 ; V_35 < V_217 -> V_37 ;
V_35 ++ , V_48 ++ , V_38 += 4 )
V_39 [ V_48 ] =
F_21 ( V_7 , V_9 , V_38 ) ;
}
}
}
return V_48 ;
}
static T_1
F_92 ( struct V_6 * V_7 , struct V_8 * V_9 ,
T_1 * V_39 , bool V_40 ,
const struct V_404 * V_437 ,
T_1 V_438 , T_1 * V_439 )
{
struct V_10 * V_11 = & V_7 -> V_12 ;
T_1 V_407 [ V_440 ] ;
T_1 V_35 , V_329 , V_48 = 0 ;
T_3 V_441 ;
T_2 V_421 ;
* V_439 = 0 ;
for ( V_35 = 0 ; V_35 < V_438 ; V_35 ++ ) {
const struct V_412 * V_413 ;
const struct V_404 * V_405 ;
const union V_408 * V_409 ;
T_3 V_201 = 1 ;
bool V_442 = true ;
const T_1 * V_443 ;
V_405 = & V_437 [ V_35 ] ;
V_409 = & ( ( const union V_408 * )
V_113 [ V_410 ] . V_112 )
[ V_405 -> V_411 ] ;
V_413 = & V_409 [ 0 ] . V_414 ;
V_443 = & V_113 [ V_444 ] . V_112
[ V_405 -> V_445 ] ;
for ( V_421 = 0 ; V_421 < V_405 -> V_418 && V_442 ;
V_421 ++ ) {
T_1 V_57 = F_54 ( V_413 [ V_421 ] . V_197 ,
V_446 ) ;
if ( V_57 >= V_95 ) {
F_27 ( V_7 , L_60 ) ;
return 0 ;
}
V_442 = ! V_11 -> V_56 [ V_57 ] ;
if ( V_413 [ V_421 ] . V_253 > V_201 )
V_201 = V_413 [ V_421 ] . V_253 ;
}
if ( ! V_442 && V_40 )
continue;
for ( V_441 = 0 ; V_441 < V_201 ; V_441 ++ ) {
if ( V_40 ) {
T_1 V_420 = 0 ;
for ( V_421 = 0 ;
V_421 < V_405 -> V_418 ;
V_421 ++ ) {
const struct V_412
* V_217 = & V_413 [ V_421 ] ;
T_1 V_38 =
F_19 (
F_54 ( V_217 -> V_197 ,
V_447 ) ) ;
if ( V_217 -> V_253 > 1 ||
V_217 -> V_429 > 0 ) {
T_1 V_448 =
V_217 -> V_430 > 1 ?
F_93
( V_217 -> V_430 ) : 1 ;
V_38 +=
F_19 (
( V_217 -> V_429 +
V_441 )
* V_448 ) ;
}
if ( V_420 + V_217 -> V_430 >=
V_440 ) {
F_27 ( V_7 ,
L_61 ) ;
return 0 ;
}
for ( V_329 = 0 ; V_329 < V_217 -> V_430 ;
V_329 ++ , V_420 ++ ,
V_38 += 4 )
V_407 [ V_420 ] =
F_21 ( V_7 , V_9 , V_38 ) ;
}
}
if ( (* F_94 [ V_405 -> V_449 ])( V_407 ,
V_443 ) || ! V_40 ) {
V_48 +=
F_90 ( V_7 ,
V_9 ,
V_39 + V_48 ,
V_40 ,
V_405 -> V_403 ,
V_405 ,
V_441 ,
V_407 ) ;
( * V_439 ) ++ ;
break;
}
}
}
return V_48 ;
}
static T_1 F_95 ( struct V_6 * V_7 ,
struct V_8 * V_9 , T_1 * V_39 , bool V_40 )
{
T_1 V_48 = 0 , V_210 = 0 , V_439 = 0 ;
T_1 V_450 ;
V_48 += F_31 ( V_7 ,
V_9 ,
V_39 + V_48 , V_40 , 1 ) ;
V_48 += F_24 ( V_39 + V_48 ,
V_40 , L_54 , L_62 ) ;
V_48 += F_30 ( V_39 + V_48 , V_40 , L_63 , 1 ) ;
V_450 = V_48 ;
V_48 += F_25 ( V_39 + V_48 , V_40 , L_64 , 0 ) ;
while ( V_210 <
V_113 [ V_451 ] . V_212 ) {
const struct V_452 * V_214 =
( const struct V_452 * )
& V_113 [ V_451 ] . V_112
[ V_210 ++ ] ;
bool V_196 = F_54 ( V_214 -> V_107 . V_197 ,
V_198 ) > 0 ;
bool V_211 = true ;
if ( V_196 ) {
T_3 V_111 =
F_54 ( V_214 -> V_107 . V_197 ,
V_199 ) ;
V_211 = F_41 ( V_7 ,
& V_111 ) ;
}
if ( V_211 ) {
T_1 V_453 ;
V_48 +=
F_92 ( V_7 ,
V_9 ,
V_39 + V_48 ,
V_40 ,
( const struct V_404 * )
& V_113 [ V_451 ] .
V_112 [ V_210 ] ,
V_214 -> V_215 / V_454 ,
& V_453 ) ;
V_439 += V_453 ;
}
V_210 += V_214 -> V_215 ;
}
if ( V_40 )
F_25 ( V_39 + V_450 ,
V_40 , L_64 , V_439 ) ;
return V_48 ;
}
static enum V_5 F_96 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 V_455 ,
T_1 * V_456 ,
T_1 * V_457 )
{
T_1 V_458 , V_459 , V_460 ;
struct V_461 V_462 ;
if ( F_97 ( V_7 , V_9 , V_463 ,
V_455 , & V_458 , & V_459 ,
& V_460 , ( T_1 * ) & V_462 ) != 0 )
return V_464 ;
if ( ( V_458 & V_465 ) != V_466 )
return V_464 ;
* V_456 = V_462 . V_467 ;
* V_457 = V_462 . V_204 ;
F_60 ( V_7 ,
V_223 ,
L_65 ,
V_455 , * V_456 , * V_457 ) ;
if ( * V_457 & 0x3 )
return V_468 ;
return V_14 ;
}
static enum V_5 F_98 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 V_456 ,
T_1 V_457 , T_1 * V_469 )
{
T_1 V_458 , V_459 , V_470 ;
T_1 V_471 , V_472 = 0 ;
T_4 V_473 = V_457 ;
F_60 ( V_7 ,
V_223 ,
L_66 ,
V_457 ) ;
do {
V_471 =
( V_473 >
V_474 ) ? V_474 : V_473 ;
if ( F_97 ( V_7 , V_9 ,
V_475 ,
( V_456 +
V_472 ) |
( V_471 <<
V_476 ) ,
& V_458 , & V_459 ,
& V_470 ,
( T_1 * ) ( ( T_2 * ) V_469 +
V_472 ) ) != 0 )
return V_477 ;
if ( ( V_458 & V_465 ) != V_466 )
return V_477 ;
V_472 += V_470 ;
V_473 -= V_470 ;
} while ( V_473 > 0 );
return V_14 ;
}
static enum V_5 F_99 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_478 ,
T_1 * V_479 )
{
T_1 V_480 = F_21 ( V_7 ,
V_9 ,
V_481 ) ;
T_1 V_482 ;
* V_478 =
V_74 + F_100 ( V_480 ) ;
V_482 = F_21 ( V_7 , V_9 ,
* V_478 +
F_29 ( struct V_483 , V_482 ) ) ;
if ( V_482 != V_484 )
return V_485 ;
* V_479 = F_21 ( V_7 ,
V_9 ,
* V_478 +
F_29 ( struct V_483 , V_37 ) ) ;
return V_14 ;
}
static enum V_5 F_101 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 V_479 ,
T_1 * V_486 ,
T_1 * V_487 ,
T_1 * V_488 )
{
T_1 V_480 = F_21 ( V_7 ,
V_9 ,
V_481 ) ;
T_1 V_489 =
V_74 + F_100 ( V_480 ) +
F_102 ( V_480 ) + V_479 ;
enum V_5 V_490 ;
T_1 V_491 ;
* V_486 = F_21 ( V_7 , V_9 , V_489 ) ;
if ( * V_486 > 1 )
return V_492 ;
V_491 =
( * V_486 ==
V_493 ) ? V_494 : V_495 ;
V_490 = F_96 ( V_7 ,
V_9 ,
V_491 ,
V_487 ,
V_488 ) ;
return V_490 ;
}
static void F_103 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 V_38 , T_1 V_212 , T_1 * V_3 )
{
T_1 V_35 ;
F_60 ( V_7 ,
V_223 ,
L_67 ,
V_212 , V_38 ) ;
for ( V_35 = 0 ; V_35 < V_212 ; V_35 ++ , V_38 += V_36 )
V_3 [ V_35 ] = F_21 ( V_7 , V_9 , V_38 ) ;
}
static enum V_5 F_104 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 V_496 ,
T_1 V_497 , T_1 * V_3 )
{
T_2 * V_498 = ( T_2 * ) V_3 ;
T_2 V_499 , V_35 ;
T_1 V_482 ;
enum V_5 V_490 = F_98 ( V_7 ,
V_9 ,
V_496 ,
V_497 ,
V_3 ) ;
if ( V_490 != V_14 )
return V_490 ;
V_482 = F_14 ( V_498 ) ;
V_498 += sizeof( T_1 ) ;
if ( V_482 != V_500 )
return V_485 ;
V_499 = * ( V_498 ++ ) ;
for ( V_35 = 0 ; V_35 < V_499 ; V_35 ++ ) {
T_2 V_501 = * ( V_498 ++ ) ;
V_498 += V_501 ;
}
V_482 = F_14 ( V_498 ) ;
V_498 += sizeof( T_1 ) ;
if ( V_482 != V_500 )
return V_485 ;
return V_14 ;
}
static enum V_5 F_105 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_39 ,
bool V_40 , T_1 * V_386 )
{
T_1 V_478 , V_479 , V_502 ;
T_1 V_503 , V_486 , V_48 = 0 ;
T_1 V_487 , V_488 ;
enum V_5 V_490 ;
int V_341 = 0 ;
* V_386 = 0 ;
V_490 = F_99 ( V_7 ,
V_9 ,
& V_478 ,
& V_479 ) ;
if ( V_490 != V_14 )
return V_490 ;
V_48 += F_31 ( V_7 ,
V_9 ,
V_39 + V_48 , V_40 , 1 ) ;
V_48 += F_24 ( V_39 + V_48 ,
V_40 , L_54 , L_68 ) ;
if ( V_40 ) {
V_341 = ! F_82 ( V_7 , V_9 ) ;
if ( ! V_341 )
F_27 ( V_7 , L_46 ) ;
}
V_502 =
F_106 ( V_479 + sizeof( struct V_483 ) ,
V_36 ) ;
V_48 += F_30 ( V_39 + V_48 ,
V_40 , L_69 , 1 ) ;
V_48 += F_25 ( V_39 + V_48 ,
V_40 , L_70 , V_502 ) ;
if ( V_40 )
F_103 ( V_7 ,
V_9 ,
V_478 ,
V_502 ,
V_39 + V_48 ) ;
V_48 += V_502 ;
if ( V_341 && F_83 ( V_7 , V_9 ) != 0 )
F_27 ( V_7 , L_49 ) ;
V_48 += F_30 ( V_39 + V_48 ,
V_40 , L_71 , 1 ) ;
V_490 = F_101 ( V_7 ,
V_9 ,
V_479 ,
& V_486 ,
& V_487 ,
& V_488 ) ;
if ( V_490 != V_14 )
return V_490 ;
V_503 = F_20 ( V_488 ) ;
V_48 += F_25 ( V_39 + V_48 , V_40 , L_70 ,
V_503 ) ;
if ( V_40 ) {
V_490 = F_104 ( V_7 ,
V_9 ,
V_487 ,
V_488 ,
V_39 + V_48 ) ;
if ( V_490 != V_14 )
return V_490 ;
}
V_48 += V_503 ;
* V_386 = V_48 ;
return V_14 ;
}
static enum V_5 F_107 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_39 ,
bool V_40 , T_1 * V_386 )
{
T_1 V_48 = 0 , V_504 , V_505 ;
bool V_506 ;
* V_386 = 0 ;
V_48 += F_31 ( V_7 ,
V_9 ,
V_39 + V_48 , V_40 , 1 ) ;
V_48 += F_24 ( V_39 + V_48 ,
V_40 , L_54 , L_72 ) ;
V_48 += F_30 ( V_39 + V_48 ,
V_40 , L_73 , 1 ) ;
V_505 = V_48 ;
V_48 += F_25 ( V_39 + V_48 , V_40 , L_70 , 0 ) ;
if ( ! V_40 ) {
V_48 += V_507 ;
* V_386 = V_48 ;
return V_14 ;
}
V_506 = F_21 ( V_7 , V_9 ,
V_508 ) > 0 ;
for ( V_504 = 0 ;
V_506 && V_504 < V_507 ;
V_504 += V_509 , V_48 +=
V_509 ) {
if ( F_108 ( V_7 , V_9 , V_510 ,
( V_511 ) ( V_512 ) ( & V_39 [ V_48 ] ) ,
V_509 , 0 ) )
return V_513 ;
V_506 = F_21 ( V_7 , V_9 ,
V_508 ) > 0 ;
}
F_25 ( V_39 + V_505 , V_40 , L_70 ,
V_504 ) ;
* V_386 = V_48 ;
return V_14 ;
}
static enum V_5 F_109 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_39 ,
bool V_40 , T_1 * V_386 )
{
T_1 V_48 = 0 , V_504 , V_505 ;
bool V_506 ;
* V_386 = 0 ;
V_48 += F_31 ( V_7 ,
V_9 ,
V_39 + V_48 , V_40 , 1 ) ;
V_48 += F_24 ( V_39 + V_48 ,
V_40 , L_54 , L_74 ) ;
V_48 += F_30 ( V_39 + V_48 ,
V_40 , L_75 , 1 ) ;
V_505 = V_48 ;
V_48 += F_25 ( V_39 + V_48 , V_40 , L_70 , 0 ) ;
if ( ! V_40 ) {
V_48 += V_514 ;
* V_386 = V_48 ;
return V_14 ;
}
V_506 = F_21 ( V_7 , V_9 ,
V_515 ) > 0 ;
for ( V_504 = 0 ;
V_506 && V_504 < V_514 ;
V_504 += V_516 , V_48 +=
V_516 ) {
if ( F_108 ( V_7 , V_9 ,
V_517 ,
( V_511 ) ( V_512 ) ( & V_39 [ V_48 ] ) ,
V_516 , 0 ) )
return V_513 ;
V_506 = F_21 ( V_7 , V_9 ,
V_515 ) > 0 ;
}
F_25 ( V_39 + V_505 , V_40 , L_70 ,
V_504 ) ;
* V_386 = V_48 ;
return V_14 ;
}
static enum V_5 F_110 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_39 ,
bool V_40 ,
T_1 * V_386 )
{
T_1 V_48 = 0 , V_505 , V_518 ;
* V_386 = 0 ;
V_48 += F_31 ( V_7 ,
V_9 ,
V_39 + V_48 , V_40 , 1 ) ;
V_48 += F_24 ( V_39 + V_48 ,
V_40 , L_54 , L_76 ) ;
V_48 += F_30 ( V_39 + V_48 ,
V_40 , L_77 , 1 ) ;
V_505 = V_48 ;
V_48 += F_25 ( V_39 + V_48 , V_40 , L_70 , 0 ) ;
if ( ! V_40 ) {
V_48 += V_519 ;
* V_386 = V_48 ;
return V_14 ;
}
V_518 =
F_21 ( V_7 , V_9 ,
V_520 ) *
V_521 ;
if ( F_108 ( V_7 , V_9 ,
V_522 ,
( V_511 ) ( V_512 ) ( V_39 + V_48 ) ,
V_518 , 0 ) )
return V_513 ;
V_48 += V_518 ;
F_25 ( V_39 + V_505 , V_40 , L_70 ,
V_518 ) ;
* V_386 = V_48 ;
return V_14 ;
}
static T_1 F_111 ( struct V_6 * V_7 ,
struct V_8 * V_9 , T_1 * V_39 , bool V_40 )
{
struct V_10 * V_11 = & V_7 -> V_12 ;
char V_523 [ 2 ] = L_78 ;
struct V_27 V_27 ;
T_1 V_48 = 0 , V_35 ;
T_2 V_26 ;
V_48 += F_31 ( V_7 ,
V_9 ,
V_39 + V_48 , V_40 , 1 ) ;
V_48 += F_24 ( V_39 + V_48 ,
V_40 , L_54 , L_79 ) ;
for ( V_26 = 0 ; V_26 < V_55 ; V_26 ++ ) {
T_1 V_524 , V_525 , V_526 ,
V_527 , V_528 ;
if ( V_11 -> V_56 [ V_29 [ V_26 ] . V_57 ] )
continue;
F_18 ( V_7 , V_9 , V_26 , & V_27 ) ;
V_523 [ 0 ] = V_29 [ V_26 ] . V_269 ;
V_48 += F_30 ( V_39 + V_48 , V_40 ,
L_80 , 2 ) ;
V_48 += F_24 ( V_39 + V_48 , V_40 , L_81 ,
V_523 ) ;
V_48 += F_25 ( V_39 + V_48 , V_40 , L_70 ,
V_27 . V_529 .
V_530 ) ;
if ( ! V_40 ) {
V_48 += V_27 . V_529 .
V_530 ;
continue;
}
V_524 =
V_29 [ V_26 ] . V_30 +
V_31 +
F_112 ( V_27 . V_529 .
V_531 ) ;
V_525 =
V_524 +
F_19 ( V_27 . V_529 .
V_532 ) ;
V_526 = F_21 ( V_7 , V_9 , V_525 ) ;
V_527 = ( V_526 > 0
? V_526
: V_27 . V_529 . V_533 )
- 1 ;
V_528 =
V_524 +
F_19 ( V_27 . V_529 .
V_534 ) +
V_527 *
F_19 ( V_27 . V_529 .
V_530 ) ;
for ( V_35 = 0 ;
V_35 < V_27 . V_529 . V_530 ;
V_35 ++ , V_48 ++ , V_528 += V_36 )
V_39 [ V_48 ] = F_21 ( V_7 , V_9 , V_528 ) ;
}
V_48 += F_30 ( V_39 + V_48 , V_40 , L_15 , 0 ) ;
return V_48 ;
}
enum V_5 F_113 ( const T_2 * const V_535 )
{
T_1 V_536 = * ( T_1 * ) V_535 ;
struct V_537 * V_538 ;
T_2 V_539 ;
V_538 = (struct V_537 * ) ( ( T_1 * ) V_535 + 1 ) ;
for ( V_539 = 0 ; V_539 < V_536 ; V_539 ++ ) {
V_113 [ V_539 ] . V_112 =
( T_1 * ) ( V_535 + V_538 [ V_539 ] . V_48 ) ;
V_113 [ V_539 ] . V_212 =
F_20 ( V_538 [ V_539 ] . V_540 ) ;
}
return V_14 ;
}
enum V_5 F_114 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_541 )
{
enum V_5 V_490 = F_15 ( V_7 , V_9 ) ;
* V_541 = 0 ;
if ( V_490 != V_14 )
return V_490 ;
if ( ! V_113 [ V_114 ] . V_112 ||
! V_113 [ V_224 ] . V_112 ||
! V_113 [ V_271 ] . V_112 ||
! V_113 [ V_184 ] . V_112 ||
! V_113 [ V_190 ] . V_112 )
return V_542 ;
return F_88 ( V_7 , V_9 , NULL , false , V_541 ) ;
}
enum V_5 F_115 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_39 ,
T_1 V_543 ,
T_1 * V_386 )
{
T_1 V_544 ;
enum V_5 V_490 ;
V_490 = F_114 ( V_7 , V_9 ,
& V_544 ) ;
* V_386 = 0 ;
if ( V_490 != V_14 )
return V_490 ;
if ( V_543 < V_544 )
return V_545 ;
V_490 = F_88 ( V_7 , V_9 , V_39 , true , V_386 ) ;
F_43 ( V_7 ) ;
return V_490 ;
}
enum V_5 F_116 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_541 )
{
enum V_5 V_490 = F_15 ( V_7 , V_9 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
* V_541 = 0 ;
if ( V_490 != V_14 )
return V_490 ;
if ( ! V_113 [ V_114 ] . V_112 ||
! V_113 [ V_410 ] . V_112 ||
! V_113 [ V_444 ] . V_112 ||
! V_113 [ V_451 ] . V_112 )
return V_542 ;
if ( ! V_11 -> V_546 . V_547 ) {
V_11 -> V_546 . V_541 = F_95 ( V_7 ,
V_9 ,
NULL , false ) ;
V_11 -> V_546 . V_547 = true ;
}
* V_541 = V_11 -> V_546 . V_541 ;
return V_14 ;
}
enum V_5 F_117 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_39 ,
T_1 V_543 ,
T_1 * V_386 )
{
T_1 V_544 ;
enum V_5 V_490 ;
V_490 = F_116 ( V_7 , V_9 ,
& V_544 ) ;
* V_386 = 0 ;
if ( V_490 != V_14 )
return V_490 ;
if ( V_543 < V_544 )
return V_545 ;
F_34 ( V_7 , V_9 ) ;
* V_386 = F_95 ( V_7 , V_9 , V_39 , true ) ;
return V_14 ;
}
enum V_5 F_118 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_541 )
{
enum V_5 V_490 = F_15 ( V_7 , V_9 ) ;
* V_541 = 0 ;
if ( V_490 != V_14 )
return V_490 ;
return F_105 ( V_7 , V_9 , NULL , false , V_541 ) ;
}
enum V_5 F_119 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_39 ,
T_1 V_543 ,
T_1 * V_386 )
{
T_1 V_544 ;
enum V_5 V_490 ;
V_490 = F_118 ( V_7 , V_9 ,
& V_544 ) ;
if ( V_490 != V_14 )
return V_490 ;
if ( V_543 < V_544 )
return V_545 ;
F_34 ( V_7 , V_9 ) ;
return F_105 ( V_7 ,
V_9 , V_39 , true , V_386 ) ;
}
enum V_5 F_120 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_541 )
{
enum V_5 V_490 = F_15 ( V_7 , V_9 ) ;
* V_541 = 0 ;
if ( V_490 != V_14 )
return V_490 ;
return F_107 ( V_7 , V_9 , NULL , false , V_541 ) ;
}
enum V_5 F_121 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_39 ,
T_1 V_543 ,
T_1 * V_386 )
{
T_1 V_544 ;
enum V_5 V_490 ;
V_490 = F_120 ( V_7 , V_9 ,
& V_544 ) ;
* V_386 = 0 ;
if ( V_490 != V_14 )
return V_490 ;
if ( V_543 < V_544 )
return V_545 ;
F_34 ( V_7 , V_9 ) ;
return F_107 ( V_7 ,
V_9 , V_39 , true , V_386 ) ;
}
enum V_5 F_122 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_541 )
{
enum V_5 V_490 = F_15 ( V_7 , V_9 ) ;
* V_541 = 0 ;
if ( V_490 != V_14 )
return V_490 ;
return F_109 ( V_7 , V_9 , NULL , false , V_541 ) ;
}
enum V_5 F_123 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_39 ,
T_1 V_543 ,
T_1 * V_386 )
{
T_1 V_544 ;
enum V_5 V_490 ;
V_490 = F_122 ( V_7 , V_9 ,
& V_544 ) ;
* V_386 = 0 ;
if ( V_490 != V_14 )
return V_490 ;
if ( V_543 < V_544 )
return V_545 ;
F_34 ( V_7 , V_9 ) ;
return F_109 ( V_7 ,
V_9 , V_39 , true , V_386 ) ;
}
enum V_5
F_124 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_541 )
{
enum V_5 V_490 = F_15 ( V_7 , V_9 ) ;
* V_541 = 0 ;
if ( V_490 != V_14 )
return V_490 ;
return F_110 ( V_7 ,
V_9 , NULL , false , V_541 ) ;
}
enum V_5 F_125 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_39 ,
T_1 V_543 ,
T_1 * V_386 )
{
T_1 V_544 ;
enum V_5 V_490 ;
V_490 = F_124 ( V_7 , V_9 ,
& V_544 ) ;
* V_386 = 0 ;
if ( V_490 != V_14 )
return V_490 ;
if ( V_543 < V_544 )
return V_545 ;
F_34 ( V_7 , V_9 ) ;
return F_110 ( V_7 ,
V_9 ,
V_39 , true , V_386 ) ;
}
enum V_5 F_126 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_541 )
{
enum V_5 V_490 = F_15 ( V_7 , V_9 ) ;
* V_541 = 0 ;
if ( V_490 != V_14 )
return V_490 ;
F_34 ( V_7 , V_9 ) ;
* V_541 = F_111 ( V_7 , V_9 , NULL , false ) ;
return V_14 ;
}
enum V_5 F_127 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 * V_39 ,
T_1 V_543 ,
T_1 * V_386 )
{
T_1 V_544 ;
enum V_5 V_490 ;
V_490 = F_126 ( V_7 , V_9 ,
& V_544 ) ;
* V_386 = 0 ;
if ( V_490 != V_14 )
return V_490 ;
if ( V_543 < V_544 )
return V_545 ;
* V_386 = F_111 ( V_7 , V_9 , V_39 , true ) ;
return V_14 ;
}
enum V_5 F_128 ( const T_2 * const V_535 )
{
T_1 V_536 = * ( T_1 * ) V_535 ;
struct V_537 * V_538 ;
T_2 V_539 ;
V_538 = (struct V_537 * ) ( ( T_1 * ) V_535 + 1 ) ;
for ( V_539 = 0 ; V_539 < V_536 ; V_539 ++ ) {
V_113 [ V_539 ] . V_112 =
( T_1 * ) ( V_535 + V_538 [ V_539 ] . V_48 ) ;
V_113 [ V_539 ] . V_212 =
F_20 ( V_538 [ V_539 ] . V_540 ) ;
}
return V_14 ;
}
static T_1 F_129 ( T_1 V_548 , T_1 V_549 , T_1 V_37 )
{
return ( V_548 + V_549 ) % V_37 ;
}
static T_1 F_130 ( T_1 V_548 , T_1 V_549 , T_1 V_37 )
{
return ( V_37 + V_548 - V_549 ) % V_37 ;
}
static T_1 F_131 ( void * V_3 ,
T_1 * V_48 ,
T_1 V_541 , T_2 V_550 )
{
T_2 * V_362 = ( T_2 * ) V_3 ;
T_2 * V_551 ;
T_1 V_552 = 0 ;
T_2 V_35 ;
V_551 = ( T_2 * ) & V_552 ;
for ( V_35 = 0 ; V_35 < V_550 ; V_35 ++ ) {
V_551 [ V_35 ] = V_362 [ * V_48 ] ;
* V_48 = F_129 ( * V_48 , 1 , V_541 ) ;
}
return V_552 ;
}
static T_2 F_132 ( void * V_3 , T_1 * V_48 )
{
return ( ( T_2 * ) V_3 ) [ ( * V_48 ) ++ ] ;
}
static T_1 F_133 ( void * V_3 , T_1 * V_48 )
{
T_1 V_553 = * ( T_1 * ) & ( ( T_2 * ) V_3 ) [ * V_48 ] ;
* V_48 += 4 ;
return V_553 ;
}
static void F_134 ( void * V_3 , T_1 * V_48 , T_1 V_37 , char * V_34 )
{
const char * V_554 = & ( ( const char * ) V_3 ) [ * V_48 ] ;
strncpy ( V_34 , V_554 , V_37 ) ;
V_34 [ V_37 - 1 ] = '\0' ;
* V_48 += V_37 ;
}
static char * F_135 ( void * V_3 , T_1 V_48 )
{
return V_3 ? ( char * ) V_3 + V_48 : V_555 ;
}
static T_1 F_136 ( T_1 * V_39 ,
const char * * V_45 ,
const char * * V_556 , T_1 * V_557 )
{
char * V_47 = ( char * ) V_39 ;
T_1 V_48 = 0 ;
* V_45 = V_47 ;
V_48 += strlen ( * V_45 ) + 1 ;
if ( * ( V_47 + V_48 ++ ) ) {
* V_556 = V_47 + V_48 ;
V_48 += strlen ( * V_556 ) + 1 ;
if ( V_48 & 0x3 )
V_48 += ( 4 - ( V_48 & 0x3 ) ) ;
} else {
* V_556 = NULL ;
if ( V_48 & 0x3 )
V_48 += ( 4 - ( V_48 & 0x3 ) ) ;
* V_557 = * ( T_1 * ) ( V_47 + V_48 ) ;
V_48 += 4 ;
}
return V_48 / 4 ;
}
static T_1 F_137 ( T_1 * V_39 ,
const char * * V_558 ,
T_1 * V_559 )
{
const char * V_556 ;
return F_136 ( V_39 ,
V_558 , & V_556 , V_559 ) ;
}
static T_1 F_138 ( T_1 * V_39 ,
T_1 V_559 ,
char * V_560 , T_1 * V_561 )
{
T_1 V_35 , V_562 = 0 , V_563 = 0 ;
for ( V_35 = 0 ; V_35 < V_559 ; V_35 ++ ) {
const char * V_45 ;
const char * V_556 ;
T_1 V_557 = 0 ;
V_562 += F_136 ( V_39 + V_562 ,
& V_45 ,
& V_556 , & V_557 ) ;
if ( V_556 )
V_563 +=
sprintf ( F_135 ( V_560 ,
V_563 ) ,
L_82 , V_45 , V_556 ) ;
else if ( strcmp ( V_45 , L_7 ) )
V_563 +=
sprintf ( F_135 ( V_560 ,
V_563 ) ,
L_83 , V_45 , V_557 ) ;
}
V_563 +=
sprintf ( F_135 ( V_560 , V_563 ) , L_84 ) ;
* V_561 = V_563 ;
return V_562 ;
}
const char * F_139 ( enum V_5 V_490 )
{
return ( V_490 <
V_564 ) ? V_565 [ V_490 ] : L_85 ;
}
static T_1 F_140 ( struct V_6 * V_7 ,
T_1 * V_39 ,
T_1 * V_566 ,
T_1 V_567 ,
bool V_568 ,
char * V_560 ,
T_1 * V_569 , T_1 * V_570 )
{
T_1 V_571 , V_563 = 0 ;
T_3 V_35 , V_329 ;
* V_569 = 0 ;
* V_570 = 0 ;
for ( V_571 = 0 ; V_571 < V_567 && V_39 < V_566 ;
V_571 ++ ) {
const struct V_572 * V_573 ;
struct V_415 * V_228 ;
const char * V_574 ;
T_1 V_575 ;
const char * V_576 ;
T_2 V_577 = 0 ;
bool V_578 ;
V_228 = (struct V_415 * ) V_39 ;
V_573 =
( const struct V_572 * )
& V_113 [ V_579 ] .
V_112 [ V_228 -> V_403 ] ;
V_575 =
F_54 ( V_573 -> V_197 ,
V_580 ) ;
V_578 =
F_54 ( V_573 -> V_197 ,
V_581 ) > 0 ;
V_574 = & ( ( const char * )
V_113 [ V_582 ] . V_112 )
[ V_575 ] ;
V_576 = V_574 ;
if ( V_228 -> V_423 >= V_583 )
return 0 ;
V_39 += ( sizeof( struct V_415 ) / 4 ) ;
if ( V_228 -> V_423 == V_584 ||
V_228 -> V_423 == V_585 )
( * V_569 ) ++ ;
else
( * V_570 ) ++ ;
V_563 +=
sprintf ( F_135 ( V_560 ,
V_563 ) , L_86 ,
V_586 [ V_228 -> V_423 ] ) ;
if ( V_578 )
V_574 += strlen ( V_574 ) + 1 ;
V_563 +=
sprintf ( F_135 ( V_560 ,
V_563 ) , L_87 ,
V_578 &&
V_568 ? V_574 : V_576 ) ;
V_574 += strlen ( V_574 ) + 1 ;
V_563 +=
sprintf ( F_135 ( V_560 ,
V_563 ) , L_88 ) ;
for ( V_35 = 0 ;
V_35 < V_228 -> V_424 + V_228 -> V_436 ;
V_35 ++ ) {
struct V_426 * V_427
= (struct V_426 * )
V_39 ;
bool V_587 =
F_54 ( V_427 -> V_197 ,
V_431 ) ;
T_2 V_421 =
F_54 ( V_427 -> V_197 ,
V_432 ) ;
V_39 +=
( sizeof( struct V_426 ) / 4 ) ;
for (; V_421 > V_577 ;
V_577 ++ ,
V_574 += strlen ( V_574 ) + 1 ) ;
V_563 +=
sprintf ( F_135 ( V_560 ,
V_563 ) , L_89 ,
V_574 ) ;
if ( V_35 < V_228 -> V_424 && V_587 )
V_563 +=
sprintf ( F_135 ( V_560 ,
V_563 ) ,
L_90 , V_228 -> V_422 +
V_427 -> V_429 ) ;
V_563 +=
sprintf ( F_135 ( V_560 ,
V_563 ) , L_91 ) ;
for ( V_329 = 0 ; V_329 < V_427 -> V_37 ; V_329 ++ , V_39 ++ ) {
V_563 +=
sprintf ( F_135 ( V_560 ,
V_563 ) ,
L_92 , * V_39 ) ;
if ( V_329 < V_427 -> V_37 - 1 )
V_563 +=
sprintf ( F_135
( V_560 ,
V_563 ) , L_93 ) ;
}
}
V_563 +=
sprintf ( F_135 ( V_560 , V_563 ) , L_84 ) ;
}
if ( V_39 > V_566 )
return 0 ;
return V_563 ;
}
static enum V_5 F_141 ( struct V_6 * V_7 ,
T_1 * V_39 ,
T_1 V_386 ,
char * V_560 ,
T_1 * V_588 ,
T_1 * V_569 ,
T_1 * V_570 )
{
const char * V_558 , * V_45 , * V_556 ;
T_1 * V_566 = V_39 + V_386 ;
T_1 V_559 = 0 , V_567 ;
T_1 V_563 = 0 ;
* V_588 = 0 ;
* V_569 = 0 ;
* V_570 = 0 ;
if ( ! V_113 [ V_582 ] . V_112 ||
! V_113 [ V_579 ] . V_112 )
return V_542 ;
V_39 += F_137 ( V_39 ,
& V_558 , & V_559 ) ;
if ( strcmp ( V_558 , L_10 ) )
return V_589 ;
V_39 += F_138 ( V_39 ,
V_559 ,
V_560 , & V_563 ) ;
V_39 += F_137 ( V_39 ,
& V_558 , & V_559 ) ;
if ( strcmp ( V_558 , L_63 ) || V_559 != 1 )
return V_589 ;
V_39 += F_136 ( V_39 ,
& V_45 , & V_556 , & V_567 ) ;
if ( strcmp ( V_45 , L_64 ) != 0 )
return V_589 ;
if ( V_567 ) {
T_1 V_590 ;
V_563 +=
sprintf ( F_135 ( V_560 ,
V_563 ) ,
L_94 ) ;
V_590 =
F_140 ( V_7 , V_39 ,
V_566 , V_567 ,
true ,
V_560 ?
V_560 +
V_563 : NULL ,
V_569 , V_570 ) ;
V_563 += V_590 ;
if ( V_590 == 0 )
return V_589 ;
V_563 +=
sprintf ( F_135 ( V_560 ,
V_563 ) ,
L_95 ) ;
V_590 =
F_140 ( V_7 , V_39 ,
V_566 , V_567 ,
false ,
V_560 ?
V_560 +
V_563 : NULL ,
V_569 , V_570 ) ;
V_563 += V_590 ;
if ( V_590 == 0 )
return V_589 ;
}
if ( * V_569 ) {
V_563 +=
sprintf ( F_135 ( V_560 ,
V_563 ) ,
L_96 ,
* V_569 , * V_570 ) ;
} else if ( * V_570 ) {
V_563 +=
sprintf ( F_135 ( V_560 ,
V_563 ) ,
L_97 ,
* V_570 ) ;
} else {
V_563 +=
sprintf ( F_135 ( V_560 ,
V_563 ) ,
L_98 ) ;
}
* V_588 = V_563 + 1 ;
return V_14 ;
}
enum V_5 F_142 ( struct V_6 * V_7 ,
T_1 * V_39 ,
T_1 V_386 ,
T_1 * V_591 )
{
T_1 V_569 , V_570 ;
return F_141 ( V_7 ,
V_39 ,
V_386 ,
NULL ,
V_591 ,
& V_569 , & V_570 ) ;
}
enum V_5 F_143 ( struct V_6 * V_7 ,
T_1 * V_39 ,
T_1 V_386 ,
char * V_560 ,
T_1 * V_569 , T_1 * V_570 )
{
T_1 V_592 ;
return F_141 ( V_7 ,
V_39 ,
V_386 ,
V_560 ,
& V_592 ,
V_569 , V_570 ) ;
}
static void F_144 ( struct V_6 * V_7 ,
struct V_593 * V_594 )
{
T_1 V_35 ;
if ( V_594 -> V_595 ) {
for ( V_35 = 0 ; V_35 < V_594 -> V_499 ; V_35 ++ )
F_145 ( V_594 -> V_595 [ V_35 ] ) ;
F_145 ( V_594 -> V_595 ) ;
}
if ( V_594 -> V_596 ) {
for ( V_35 = 0 ; V_35 < V_594 -> V_597 ; V_35 ++ )
F_145 ( V_594 -> V_596 [ V_35 ] . V_598 ) ;
F_145 ( V_594 -> V_596 ) ;
}
}
static enum V_5 F_146 ( struct V_6 * V_7 ,
const T_1 * V_599 ,
struct V_593 * V_594 )
{
T_2 * V_600 = ( T_2 * ) V_599 ;
T_1 V_48 = 0 , V_482 , V_35 ;
memset ( V_594 , 0 , sizeof( * V_594 ) ) ;
V_482 = F_133 ( V_600 , & V_48 ) ;
if ( V_482 != V_500 )
return V_485 ;
V_594 -> V_499 = F_132 ( V_600 , & V_48 ) ;
V_594 -> V_595 = F_147 ( V_594 -> V_499 * sizeof( char * ) , V_601 ) ;
if ( ! V_594 -> V_595 )
return V_602 ;
for ( V_35 = 0 ; V_35 < V_594 -> V_499 ; V_35 ++ ) {
T_2 V_501 = F_132 ( V_600 , & V_48 ) ;
* ( V_594 -> V_595 + V_35 ) = F_147 ( V_501 , V_601 ) ;
if ( ! ( * ( V_594 -> V_595 + V_35 ) ) ) {
V_594 -> V_499 = V_35 ? V_35 - 1 : 0 ;
return V_602 ;
}
F_134 ( V_600 , & V_48 , V_501 ,
* ( V_594 -> V_595 + V_35 ) ) ;
if ( V_501 > V_603 )
( * ( V_594 -> V_595 + V_35 ) ) [ V_603 ] = '\0' ;
}
V_482 = F_133 ( V_600 , & V_48 ) ;
if ( V_482 != V_500 )
return V_485 ;
V_594 -> V_597 = F_133 ( V_600 , & V_48 ) ;
V_594 -> V_596 = F_147 ( V_594 -> V_597 *
sizeof( struct V_604 ) ,
V_601 ) ;
if ( ! V_594 -> V_596 )
return V_602 ;
for ( V_35 = 0 ; V_35 < V_594 -> V_597 ; V_35 ++ ) {
struct V_604 * V_605 = & V_594 -> V_596 [ V_35 ] ;
T_2 V_606 ;
V_605 -> V_197 = F_133 ( V_600 ,
& V_48 ) ;
V_606 =
( V_605 -> V_197 &
V_607 ) >> V_608 ;
V_605 -> V_598 = F_147 ( V_606 , V_601 ) ;
if ( ! V_605 -> V_598 ) {
V_594 -> V_597 = V_35 ? V_35 - 1 : 0 ;
return V_602 ;
}
F_134 ( V_600 ,
& V_48 ,
V_606 , V_605 -> V_598 ) ;
}
return V_14 ;
}
static enum V_5 F_148 ( struct V_6 * V_7 ,
T_1 * V_39 ,
T_1 V_386 ,
char * V_560 ,
T_1 * V_588 )
{
T_1 V_563 = 0 , V_609 , V_610 , V_557 ;
T_1 V_559 , V_48 , V_611 , V_473 ;
const char * V_558 , * V_45 , * V_556 ;
T_1 V_612 , V_613 ;
struct V_593 V_594 ;
struct V_483 * V_614 ;
enum V_5 V_490 ;
const T_1 * V_599 ;
T_2 * V_615 ;
* V_588 = 0 ;
V_39 += F_137 ( V_39 ,
& V_558 , & V_559 ) ;
if ( strcmp ( V_558 , L_10 ) )
return V_616 ;
V_39 += F_138 ( V_39 ,
V_559 ,
V_560 , & V_563 ) ;
V_39 += F_137 ( V_39 ,
& V_558 , & V_559 ) ;
if ( strcmp ( V_558 , L_69 ) || V_559 != 1 )
return V_616 ;
V_39 += F_136 ( V_39 ,
& V_45 , & V_556 , & V_557 ) ;
if ( strcmp ( V_45 , L_70 ) )
return V_616 ;
V_612 = V_557 ;
V_614 = (struct V_483 * ) V_39 ;
V_615 = ( T_2 * ) V_39 + sizeof( struct V_483 ) ;
V_48 = V_614 -> V_617 ;
V_611 = V_614 -> V_618 ;
V_473 = F_130 ( V_611 , V_48 , V_614 -> V_37 ) ;
V_39 += V_612 ;
V_39 += F_137 ( V_39 ,
& V_558 , & V_559 ) ;
if ( strcmp ( V_558 , L_71 ) )
return V_616 ;
V_39 += F_136 ( V_39 ,
& V_45 , & V_556 , & V_557 ) ;
if ( strcmp ( V_45 , L_70 ) != 0 )
return V_616 ;
V_613 = V_557 ;
if ( ! V_613 ) {
if ( ! V_619 . V_112 )
return V_620 ;
V_599 = V_619 . V_112 ;
} else {
V_599 = V_39 ;
}
V_490 = F_146 ( V_7 , V_599 , & V_594 ) ;
if ( V_490 != V_14 )
goto V_621;
while ( V_473 ) {
struct V_604 * V_605 ;
T_2 V_622 , V_623 ;
T_1 V_624 [ 3 ] = { 0 , 0 , 0 } ;
T_1 V_625 , V_626 , V_35 ;
if ( V_473 < V_627 ) {
V_490 = V_616 ;
goto V_621;
}
V_625 = F_131 ( V_615 ,
& V_48 ,
V_614 -> V_37 ,
V_627 ) ;
V_473 -= V_627 ;
V_626 = V_625 & V_628 ;
if ( V_626 > V_594 . V_597 ) {
T_2 V_629 =
( T_2 ) ( ( V_625 &
V_630 ) >>
V_631 ) ;
if ( V_473 < V_629 ) {
V_490 = V_616 ;
goto V_621;
}
V_48 = F_129 ( V_48 ,
V_629 , V_614 -> V_37 ) ;
V_473 -= V_629 ;
continue;
}
V_605 = & V_594 . V_596 [ V_626 ] ;
for ( V_35 = 0 ,
V_609 = V_632 , V_610 =
V_633 ;
V_35 < V_634 ;
V_35 ++ , V_609 <<= V_635 ,
V_610 += V_635 ) {
T_2 V_636 =
( T_2 ) ( ( V_605 -> V_197 &
V_609 ) >> V_610 ) ;
if ( ! V_636 )
break;
if ( V_636 == 3 )
V_636 = 4 ;
if ( V_473 < V_636 ) {
V_490 = V_616 ;
goto V_621;
}
V_624 [ V_35 ] = F_131 ( V_615 ,
& V_48 ,
V_614 -> V_37 ,
V_636 ) ;
V_473 -= V_636 ;
}
V_622 =
( T_2 ) ( ( V_605 -> V_197 &
V_637 ) >>
V_638 ) ;
V_623 =
( T_2 ) ( ( V_605 -> V_197 &
V_639 ) >>
V_640 ) ;
if ( V_622 >= F_85 ( V_641 ) ) {
V_490 = V_616 ;
goto V_621;
}
V_563 +=
sprintf ( F_135 ( V_560 ,
V_563 ) , L_99 ,
V_641 [ V_622 ] ,
V_594 . V_595 [ V_623 ] ) ;
V_563 +=
sprintf ( F_135 ( V_560 ,
V_563 ) ,
V_605 -> V_598 , V_624 [ 0 ] , V_624 [ 1 ] ,
V_624 [ 2 ] ) ;
}
V_621:
* V_588 = V_563 + 1 ;
F_144 ( V_7 , & V_594 ) ;
return V_490 ;
}
enum V_5 F_149 ( struct V_6 * V_7 ,
T_1 * V_39 ,
T_1 V_386 ,
T_1 * V_591 )
{
return F_148 ( V_7 ,
V_39 ,
V_386 ,
NULL , V_591 ) ;
}
enum V_5 F_150 ( struct V_6 * V_7 ,
T_1 * V_39 ,
T_1 V_386 ,
char * V_560 )
{
T_1 V_592 ;
return F_148 ( V_7 ,
V_39 ,
V_386 ,
V_560 , & V_592 ) ;
}
static enum V_5 F_151 ( struct V_6 * V_7 ,
T_1 * V_39 ,
T_1 V_386 ,
char * V_560 ,
T_1 * V_588 )
{
T_1 V_563 = 0 , V_557 , V_559 , V_642 ;
const char * V_558 , * V_45 , * V_556 ;
struct V_643 * V_644 ;
T_2 V_35 , V_329 , V_645 , V_646 ;
char V_647 [ 4 ] ;
V_39 += F_137 ( V_39 ,
& V_558 , & V_559 ) ;
if ( strcmp ( V_558 , L_10 ) )
return V_648 ;
V_39 += F_138 ( V_39 ,
V_559 ,
V_560 , & V_563 ) ;
V_39 += F_137 ( V_39 ,
& V_558 , & V_559 ) ;
if ( strcmp ( V_558 , L_73 ) )
return V_648 ;
V_39 += F_136 ( V_39 ,
& V_45 , & V_556 , & V_557 ) ;
if ( strcmp ( V_45 , L_70 ) )
return V_648 ;
if ( V_557 % V_509 )
return V_648 ;
V_642 = V_557 / V_509 ;
V_644 = (struct V_643 * ) V_39 ;
for ( V_35 = 0 ; V_35 < V_642 ; V_35 ++ ) {
bool V_649 = false ;
V_646 = F_54 ( V_644 [ V_35 ] . V_197 , V_650 ) ;
if ( V_646 == V_651 )
sprintf ( V_647 , L_100 , L_101 ) ;
else
sprintf ( V_647 , L_102 , V_646 ) ;
V_563 +=
sprintf ( F_135 ( V_560 ,
V_563 ) ,
L_103 ,
V_644 [ V_35 ] . V_197 ,
F_54 ( V_644 [ V_35 ] . V_197 ,
V_652 ) *
V_653 ,
V_654 [ F_54 ( V_644 [ V_35 ] . V_197 ,
V_655 ) ] ,
F_54 ( V_644 [ V_35 ] . V_197 ,
V_656 ) , V_647 ,
F_54 ( V_644 [ V_35 ] . V_197 ,
V_657 ) ,
V_658 [ F_54 ( V_644 [ V_35 ] .
V_197 ,
V_659 ) ] ,
V_660 [ F_54 ( V_644 [ V_35 ] . V_197 ,
V_661 ) ] ,
V_662 [ F_54 ( V_644 [ V_35 ] . V_197 ,
V_663 ) ] ) ;
for ( V_329 = 0 ,
V_645 = F_54 ( V_644 [ V_35 ] . V_197 ,
V_664 ) ;
V_329 < F_85 ( V_665 ) ;
V_329 ++ , V_645 >>= 1 ) {
if ( ! ( V_645 & 0x1 ) )
continue;
if ( V_649 )
V_563 +=
sprintf ( F_135 ( V_560 ,
V_563 ) ,
L_104 ) ;
V_563 +=
sprintf ( F_135 ( V_560 ,
V_563 ) , L_100 ,
V_665 [ V_329 ] ) ;
V_649 = true ;
}
V_563 +=
sprintf ( F_135 ( V_560 , V_563 ) , L_84 ) ;
}
V_563 += sprintf ( F_135 ( V_560 ,
V_563 ) ,
L_105 , V_642 ) ;
* V_588 = V_563 + 1 ;
return V_14 ;
}
enum V_5 F_152 ( struct V_6 * V_7 ,
T_1 * V_39 ,
T_1 V_386 ,
T_1 * V_591 )
{
return F_151 ( V_7 ,
V_39 ,
V_386 ,
NULL , V_591 ) ;
}
enum V_5 F_153 ( struct V_6 * V_7 ,
T_1 * V_39 ,
T_1 V_386 ,
char * V_560 )
{
T_1 V_592 ;
return F_151 ( V_7 ,
V_39 ,
V_386 ,
V_560 , & V_592 ) ;
}
static enum V_5 F_154 ( struct V_6 * V_7 ,
T_1 * V_39 ,
T_1 V_386 ,
char * V_560 ,
T_1 * V_588 )
{
T_1 V_563 = 0 , V_557 , V_559 , V_642 ;
const char * V_558 , * V_45 , * V_556 ;
struct V_666 * V_644 ;
char V_667 [ 32 ] ;
char V_668 [ 256 ] ;
T_2 V_35 , V_329 ;
V_39 += F_137 ( V_39 ,
& V_558 , & V_559 ) ;
if ( strcmp ( V_558 , L_10 ) )
return V_669 ;
V_39 += F_138 ( V_39 ,
V_559 ,
V_560 , & V_563 ) ;
V_39 += F_137 ( V_39 ,
& V_558 , & V_559 ) ;
if ( strcmp ( V_558 , L_75 ) )
return V_669 ;
V_39 += F_136 ( V_39 ,
& V_45 , & V_556 , & V_557 ) ;
if ( strcmp ( V_45 , L_70 ) )
return V_669 ;
if ( V_557 % V_516 )
return V_669 ;
V_642 = V_557 / V_516 ;
V_644 = (struct V_666 * ) V_39 ;
for ( V_35 = 0 ; V_35 < V_642 ; V_35 ++ ) {
V_511 V_670 =
( ( V_511 ) V_644 [ V_35 ] . V_671 << 32 ) | V_644 [ V_35 ] . V_263 ;
bool V_672 = F_54 ( V_670 ,
V_673 ) ;
bool V_674 = F_54 ( V_644 [ V_35 ] . V_257 ,
V_675 ) ;
T_3 V_676 = F_54 ( V_644 [ V_35 ] . V_257 ,
V_677 ) ;
T_2 V_678 = F_54 ( V_644 [ V_35 ] . V_257 ,
V_679 ) ;
T_2 V_680 = F_54 ( V_644 [ V_35 ] . V_257 ,
V_681 ) ;
const struct V_682 * V_683 = NULL ;
if ( V_678 >= F_85 ( V_684 ) )
return V_669 ;
if ( V_680 >= F_85 ( V_685 ) )
return V_669 ;
for ( V_329 = 0 ; V_329 < F_85 ( V_686 ) && ! V_683 ;
V_329 ++ )
if ( V_676 >= V_686 [ V_329 ] . V_687 &&
V_676 <= V_686 [ V_329 ] . V_688 )
V_683 = & V_686 [ V_329 ] ;
if ( ! V_683 )
return V_669 ;
switch ( V_683 -> type ) {
case V_689 :
sprintf ( V_667 ,
L_106 , V_676 / 2 ) ;
break;
case V_690 :
case V_691 :
sprintf ( V_667 ,
L_107 , V_676 - V_683 -> V_687 ) ;
break;
default:
V_667 [ 0 ] = '\0' ;
}
if ( V_672 ) {
T_1 V_692 = F_54 ( V_670 ,
V_693 ) ;
T_1 V_694 = F_54 ( V_692 ,
V_695 ) ;
T_2 V_696 = F_54 ( V_692 ,
V_697 ) ;
if ( V_678 == V_698 ) {
sprintf ( V_668 ,
L_108 , V_694 ) ;
} else {
if ( V_696 ) {
T_2 V_699 = F_54 ( V_692 ,
V_700 ) ;
T_2 V_701 = F_54 ( V_692 ,
V_702 ) ;
sprintf ( V_668 ,
L_109 ,
V_699 ? L_110 : L_111 ,
V_701 ) ;
} else {
T_2 V_703 = F_54 ( V_692 ,
V_704 ) ;
T_2 V_705 =
F_54 ( V_692 ,
V_706 ) ;
T_2 V_707 = F_54 ( V_692 ,
V_708 ) ;
T_2 V_709 = F_54 ( V_692 ,
V_710 ) ;
sprintf ( V_668 ,
L_112 ,
V_694 ,
V_703 ? L_113 : L_114 ,
V_705
? ( V_705 ==
1 ? L_115 : L_114 ) :
L_116 ,
V_707 ? L_117 : L_118 ,
V_709 ) ;
}
}
} else {
V_668 [ 0 ] = '\0' ;
}
V_563 +=
sprintf ( F_135 ( V_560 ,
V_563 ) ,
L_119 ,
V_644 [ V_35 ] . V_671 , V_644 [ V_35 ] . V_263 ,
V_644 [ V_35 ] . V_257 ,
V_674 ? L_23 : L_120 ,
F_54 ( V_644 [ V_35 ] . V_257 ,
V_711 ) ,
V_684 [ V_678 ] ,
V_672 ? L_121 : L_122 , V_676 ,
( ! V_674 && V_683 -> V_712 )
? V_683 -> V_712 : V_683 -> V_713 ,
V_667 , V_668 ,
V_685 [ V_680 ] ) ;
}
V_563 += sprintf ( F_135 ( V_560 ,
V_563 ) ,
L_105 , V_642 ) ;
* V_588 = V_563 + 1 ;
return V_14 ;
}
enum V_5 F_155 ( struct V_6 * V_7 ,
T_1 * V_39 ,
T_1 V_386 ,
T_1 * V_591 )
{
return F_154 ( V_7 ,
V_39 ,
V_386 ,
NULL , V_591 ) ;
}
enum V_5 F_156 ( struct V_6 * V_7 ,
T_1 * V_39 ,
T_1 V_386 ,
char * V_560 )
{
T_1 V_592 ;
return F_154 ( V_7 ,
V_39 ,
V_386 ,
V_560 , & V_592 ) ;
}
static enum V_5
F_157 ( struct V_6 * V_7 ,
T_1 * V_39 ,
T_1 V_386 ,
char * V_560 ,
T_1 * V_588 )
{
T_1 V_563 = 0 , V_557 , V_559 , V_642 ;
const char * V_558 , * V_45 , * V_556 ;
struct V_714 * V_644 ;
T_2 V_35 ;
V_39 += F_137 ( V_39 ,
& V_558 , & V_559 ) ;
if ( strcmp ( V_558 , L_10 ) )
return V_715 ;
V_39 += F_138 ( V_39 ,
V_559 ,
V_560 , & V_563 ) ;
V_39 += F_137 ( V_39 ,
& V_558 , & V_559 ) ;
if ( strcmp ( V_558 , L_77 ) )
return V_715 ;
V_39 += F_136 ( V_39 ,
& V_45 , & V_556 , & V_557 ) ;
if ( strcmp ( V_45 , L_70 ) )
return V_715 ;
if ( V_557 % V_521 != 0 )
return V_715 ;
V_642 = V_557 / V_521 ;
V_644 = (struct V_714 * ) V_39 ;
for ( V_35 = 0 ; V_35 < V_642 ; V_35 ++ ) {
T_1 V_716 = F_54 ( V_644 [ V_35 ] . V_197 ,
V_717 ) *
V_718 ;
V_563 +=
sprintf ( F_135 ( V_560 ,
V_563 ) ,
L_123 ,
V_35 , V_716 ,
F_54 ( V_644 [ V_35 ] . V_197 ,
V_719 ) ,
F_54 ( V_644 [ V_35 ] . V_197 ,
V_720 ) ,
F_54 ( V_644 [ V_35 ] . V_197 ,
V_721 ) ,
V_660 [ F_54 ( V_644 [ V_35 ] . V_197 ,
V_722 ) ] ,
V_660 [ F_54 ( V_644 [ V_35 ] . V_197 ,
V_723 ) ] ) ;
}
V_563 += sprintf ( F_135 ( V_560 ,
V_563 ) ,
L_124 ,
V_642 ) ;
* V_588 = V_563 + 1 ;
return V_14 ;
}
enum V_5
F_158 ( struct V_6 * V_7 ,
T_1 * V_39 ,
T_1 V_386 ,
T_1 * V_591 )
{
return F_157 ( V_7 ,
V_39 ,
V_386 ,
NULL , V_591 ) ;
}
enum V_5 F_159 ( struct V_6 * V_7 ,
T_1 * V_39 ,
T_1 V_386 ,
char * V_560 )
{
T_1 V_592 ;
return F_157 ( V_7 ,
V_39 ,
V_386 ,
V_560 ,
& V_592 ) ;
}
static enum V_5 F_160 ( struct V_6 * V_7 ,
T_1 * V_39 ,
T_1 V_386 ,
char * V_560 ,
T_1 * V_588 )
{
T_1 V_563 = 0 , V_559 , V_557 , V_35 ;
const char * V_45 , * V_556 , * V_558 ;
bool V_724 = false ;
* V_588 = 0 ;
V_39 += F_137 ( V_39 ,
& V_558 , & V_559 ) ;
if ( strcmp ( V_558 , L_10 ) )
return V_725 ;
V_39 += F_138 ( V_39 ,
V_559 ,
V_560 , & V_563 ) ;
while ( ! V_724 ) {
const char * V_251 = NULL ;
T_1 V_726 = 0 ;
V_39 += F_137 ( V_39 ,
& V_558 ,
& V_559 ) ;
if ( ! strcmp ( V_558 , L_15 ) ) {
V_724 = true ;
continue;
} else if ( strcmp ( V_558 , L_80 ) ) {
return V_725 ;
}
for ( V_35 = 0 ; V_35 < V_559 ; V_35 ++ ) {
V_39 += F_136 ( V_39 ,
& V_45 ,
& V_556 ,
& V_557 ) ;
if ( ! strcmp ( V_45 , L_81 ) )
V_251 = V_556 ;
else if ( ! strcmp ( V_45 , L_70 ) )
V_726 = V_557 ;
else
return V_725 ;
}
if ( ! V_251 || ! V_726 )
return V_725 ;
V_563 += sprintf ( F_135 ( V_560 ,
V_563 ) ,
L_125 ,
V_251 , V_726 ) ;
for ( V_35 = 0 ; V_35 < V_726 ; V_35 ++ , V_39 ++ )
V_563 +=
sprintf ( F_135 ( V_560 ,
V_563 ) ,
L_126 , * V_39 ) ;
}
* V_588 = V_563 + 1 ;
return V_14 ;
}
enum V_5 F_161 ( struct V_6 * V_7 ,
T_1 * V_39 ,
T_1 V_386 ,
T_1 * V_591 )
{
return F_160 ( V_7 ,
V_39 ,
V_386 ,
NULL , V_591 ) ;
}
enum V_5 F_162 ( struct V_6 * V_7 ,
T_1 * V_39 ,
T_1 V_386 ,
char * V_560 )
{
T_1 V_592 ;
return F_160 ( V_7 ,
V_39 ,
V_386 ,
V_560 , & V_592 ) ;
}
static enum V_5
F_163 ( struct V_6 * V_7 ,
T_1 * V_39 ,
T_1 V_386 ,
char * V_560 )
{
T_1 V_569 , V_727 ;
return F_143 ( V_7 , V_39 , V_386 ,
V_560 , & V_569 ,
& V_727 ) ;
}
static void F_164 ( T_2 * V_728 , T_1 V_729 )
{
T_1 V_35 , V_730 = 80 ;
if ( ! V_728 )
return;
F_165 ( L_127 , V_730 , V_728 ) ;
for ( V_35 = V_730 ; V_35 < V_729 ; V_35 += V_730 )
F_166 ( L_128 , V_730 , V_728 + V_35 ) ;
F_166 ( L_84 ) ;
}
static enum V_5 F_167 ( struct V_6 * V_7 ,
enum V_731 V_732 )
{
struct V_733 * V_734 =
& V_7 -> V_15 -> V_735 . V_736 [ V_732 ] ;
T_1 V_737 , V_738 , V_35 ;
enum V_5 V_739 ;
char * V_740 ;
if ( ! V_741 [ V_732 ] . V_591 )
return V_14 ;
V_739 = V_741 [ V_732 ] .
V_591 ( V_7 , ( T_1 * ) V_734 -> V_39 ,
V_734 -> V_742 , & V_737 ) ;
if ( V_739 != V_14 )
return V_739 ;
V_738 = V_737 - 1 ;
V_737 = ( V_737 + 3 ) & ~ 0x3 ;
if ( V_737 < V_743 ) {
F_27 ( V_7 -> V_15 ,
L_129 ,
V_737 ) ;
return V_744 ;
}
V_740 = F_168 ( V_737 ) ;
if ( ! V_740 )
return V_602 ;
V_739 = V_741 [ V_732 ] .
F_169 ( V_7 , ( T_1 * ) V_734 -> V_39 ,
V_734 -> V_742 , V_740 ) ;
if ( V_739 != V_14 ) {
F_170 ( V_740 ) ;
return V_739 ;
}
for ( V_35 = V_738 ; V_35 < V_737 ; V_35 ++ )
V_740 [ V_35 ] = '\n' ;
if ( V_7 -> V_15 -> V_735 . V_745 )
F_164 ( V_740 , V_737 ) ;
F_170 ( V_734 -> V_39 ) ;
V_734 -> V_39 = V_740 ;
V_734 -> V_541 = V_737 ;
V_734 -> V_742 = V_737 / 4 ;
return V_739 ;
}
static enum V_5 F_171 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
enum V_731 V_732 )
{
struct V_733 * V_734 =
& V_7 -> V_15 -> V_735 . V_736 [ V_732 ] ;
T_1 V_746 ;
enum V_5 V_739 ;
F_27 ( V_7 -> V_15 , L_130 ,
V_741 [ V_732 ] . V_81 ) ;
if ( V_734 -> V_39 ) {
F_170 ( V_734 -> V_39 ) ;
V_734 -> V_39 = NULL ;
}
V_739 = V_741 [ V_732 ] . F_172 ( V_7 , V_9 ,
& V_746 ) ;
if ( V_739 != V_14 )
return V_739 ;
V_734 -> V_541 = V_746 * sizeof( T_1 ) ;
V_734 -> V_39 = F_173 ( V_734 -> V_541 ) ;
if ( ! V_734 -> V_39 )
return V_602 ;
V_739 = V_741 [ V_732 ] .
F_174 ( V_7 , V_9 , ( T_1 * ) V_734 -> V_39 ,
V_734 -> V_541 / sizeof( T_1 ) ,
& V_734 -> V_742 ) ;
if ( V_739 == V_464 )
return V_14 ;
if ( V_739 != V_14 )
return V_739 ;
V_739 = F_167 ( V_7 , V_732 ) ;
return V_739 ;
}
int F_175 ( struct V_747 * V_15 , void * V_748 , T_1 * V_749 )
{
return V_733 ( V_15 , V_748 , V_750 , V_749 ) ;
}
int F_176 ( struct V_747 * V_15 )
{
return F_177 ( V_15 , V_750 ) ;
}
int F_178 ( struct V_747 * V_15 , void * V_748 , T_1 * V_749 )
{
return V_733 ( V_15 , V_748 , V_751 ,
V_749 ) ;
}
int F_179 ( struct V_747 * V_15 )
{
return F_177 ( V_15 , V_751 ) ;
}
int F_180 ( struct V_747 * V_15 , void * V_748 , T_1 * V_749 )
{
return V_733 ( V_15 , V_748 , V_752 ,
V_749 ) ;
}
int F_181 ( struct V_747 * V_15 )
{
return F_177 ( V_15 , V_752 ) ;
}
int F_182 ( struct V_747 * V_15 , void * V_748 , T_1 * V_749 )
{
return V_733 ( V_15 , V_748 , V_753 ,
V_749 ) ;
}
int F_183 ( struct V_747 * V_15 )
{
return F_177 ( V_15 , V_753 ) ;
}
int F_184 ( struct V_747 * V_15 , void * V_748 ,
T_1 * V_749 )
{
return V_733 ( V_15 , V_748 , V_754 ,
V_749 ) ;
}
int F_185 ( struct V_747 * V_15 )
{
return F_177 ( V_15 , V_754 ) ;
}
int F_186 ( struct V_747 * V_15 , void * V_748 ,
T_1 * V_749 )
{
return V_733 ( V_15 , V_748 , V_755 ,
V_749 ) ;
}
int F_187 ( struct V_747 * V_15 )
{
return F_177 ( V_15 , V_755 ) ;
}
int F_188 ( struct V_747 * V_15 , void * V_748 ,
T_1 * V_749 )
{
return V_733 ( V_15 , V_748 , V_756 ,
V_749 ) ;
}
int F_189 ( struct V_747 * V_15 )
{
return F_177 ( V_15 , V_756 ) ;
}
static T_1 F_190 ( enum V_757 V_734 ,
int V_758 , T_1 V_759 , T_2 V_760 )
{
return V_759 | ( V_734 << V_761 ) |
( V_760 << V_762 ) |
( V_758 << V_763 ) ;
}
int F_191 ( struct V_747 * V_15 , void * V_748 )
{
T_2 V_764 , V_760 = 0 , V_765 ;
T_1 V_48 = 0 , V_759 ;
int V_739 ;
if ( V_15 -> V_766 == 1 )
V_760 = 1 ;
V_765 = F_192 ( V_15 ) ;
for ( V_764 = 0 ; V_764 < V_15 -> V_766 ; V_764 ++ ) {
F_60 ( V_15 , V_223 ,
L_131 ) ;
F_193 ( V_15 , V_764 ) ;
V_739 = F_178 ( V_15 , ( T_2 * ) V_748 + V_48 +
V_767 , & V_759 ) ;
if ( ! V_739 ) {
* ( T_1 * ) ( ( T_2 * ) V_748 + V_48 ) =
F_190 ( V_768 , V_764 ,
V_759 , V_760 ) ;
V_48 += ( V_759 + V_767 ) ;
} else {
F_194 ( V_15 , L_132 , V_739 ) ;
}
V_739 = F_178 ( V_15 , ( T_2 * ) V_748 + V_48 +
V_767 , & V_759 ) ;
if ( ! V_739 ) {
* ( T_1 * ) ( ( T_2 * ) V_748 + V_48 ) =
F_190 ( V_768 , V_764 ,
V_759 , V_760 ) ;
V_48 += ( V_759 + V_767 ) ;
} else {
F_194 ( V_15 , L_132 , V_739 ) ;
}
V_739 = F_180 ( V_15 , ( T_2 * ) V_748 + V_48 +
V_767 , & V_759 ) ;
if ( ! V_739 ) {
* ( T_1 * ) ( ( T_2 * ) V_748 + V_48 ) =
F_190 ( V_769 , V_764 ,
V_759 , V_760 ) ;
V_48 += ( V_759 + V_767 ) ;
} else {
F_194 ( V_15 , L_133 , V_739 ) ;
}
V_739 = F_182 ( V_15 , ( T_2 * ) V_748 + V_48 +
V_767 , & V_759 ) ;
if ( ! V_739 ) {
* ( T_1 * ) ( ( T_2 * ) V_748 + V_48 ) =
F_190 ( V_770 , V_764 ,
V_759 , V_760 ) ;
V_48 += ( V_759 + V_767 ) ;
} else {
F_194 ( V_15 , L_134 , V_739 ) ;
}
V_739 = F_184 ( V_15 , ( T_2 * ) V_748 + V_48 +
V_767 ,
& V_759 ) ;
if ( ! V_739 ) {
* ( T_1 * ) ( ( T_2 * ) V_748 + V_48 ) =
F_190 ( V_771 ,
V_764 ,
V_759 , V_760 ) ;
V_48 += ( V_759 + V_767 ) ;
} else {
F_194 ( V_15 ,
L_135 ,
V_739 ) ;
}
V_739 = F_186 ( V_15 , ( T_2 * ) V_748 + V_48 +
V_767 , & V_759 ) ;
if ( ! V_739 ) {
* ( T_1 * ) ( ( T_2 * ) V_748 + V_48 ) =
F_190 ( V_772 , V_764 ,
V_759 , V_760 ) ;
V_48 += ( V_759 + V_767 ) ;
} else {
F_194 ( V_15 , L_136 ,
V_739 ) ;
}
V_739 = F_175 ( V_15 , ( T_2 * ) V_748 + V_48 +
V_767 , & V_759 ) ;
if ( ! V_739 ) {
* ( T_1 * ) ( ( T_2 * ) V_748 + V_48 ) =
F_190 ( V_773 , V_764 ,
V_759 , V_760 ) ;
V_48 += ( V_759 + V_767 ) ;
} else {
F_194 ( V_15 , L_137 , V_739 ) ;
}
}
V_739 = F_188 ( V_15 , ( T_2 * ) V_748 + V_48 +
V_767 , & V_759 ) ;
if ( ! V_739 ) {
* ( T_1 * ) ( ( T_2 * ) V_748 + V_48 ) =
F_190 ( V_774 , V_764 ,
V_759 , V_760 ) ;
V_48 += ( V_759 + V_767 ) ;
} else {
F_194 ( V_15 , L_138 , V_739 ) ;
}
F_193 ( V_15 , V_765 ) ;
return 0 ;
}
int F_195 ( struct V_747 * V_15 )
{
T_2 V_764 , V_765 ;
T_1 V_775 = 0 ;
V_765 = F_192 ( V_15 ) ;
for ( V_764 = 0 ; V_764 < V_15 -> V_766 ; V_764 ++ ) {
F_60 ( V_15 , V_223 ,
L_139 ) ;
F_193 ( V_15 , V_764 ) ;
V_775 += V_767 + F_179 ( V_15 ) +
V_767 + F_179 ( V_15 ) +
V_767 + F_176 ( V_15 ) +
V_767 + F_181 ( V_15 ) +
V_767 + F_183 ( V_15 ) +
V_767 +
F_185 ( V_15 ) +
V_767 + F_187 ( V_15 ) ;
}
V_775 += V_767 + F_189 ( V_15 ) ;
F_193 ( V_15 , V_765 ) ;
return V_775 ;
}
int V_733 ( struct V_747 * V_15 , void * V_748 ,
enum V_731 V_734 , T_1 * V_749 )
{
struct V_6 * V_7 =
& V_15 -> V_776 [ V_15 -> V_735 . V_777 ] ;
struct V_733 * V_778 =
& V_15 -> V_735 . V_736 [ V_734 ] ;
enum V_5 V_779 ;
struct V_8 * V_9 ;
int V_739 = 0 ;
V_9 = F_196 ( V_7 ) ;
if ( ! V_9 )
return - V_780 ;
V_779 = F_171 ( V_7 , V_9 , V_734 ) ;
if ( V_779 != V_14 ) {
F_60 ( V_15 , V_223 , L_140 ,
F_139 ( V_779 ) ) ;
* V_749 = 0 ;
V_739 = - V_780 ;
goto V_781;
}
F_60 ( V_15 , V_223 ,
L_141 ) ;
memcpy ( V_748 , V_778 -> V_39 , V_778 -> V_541 ) ;
* V_749 = V_15 -> V_735 . V_736 [ V_734 ] . V_742 *
4 ;
V_781:
F_197 ( V_7 , V_9 ) ;
return V_739 ;
}
int F_177 ( struct V_747 * V_15 , enum V_731 V_734 )
{
struct V_6 * V_7 =
& V_15 -> V_776 [ V_15 -> V_735 . V_777 ] ;
struct V_8 * V_9 = F_196 ( V_7 ) ;
struct V_733 * V_778 =
& V_15 -> V_735 . V_736 [ V_734 ] ;
T_1 V_746 ;
enum V_5 V_739 ;
if ( ! V_9 )
return - V_780 ;
V_739 = V_741 [ V_734 ] . F_172 ( V_7 , V_9 ,
& V_746 ) ;
if ( V_739 != V_14 )
V_746 = 0 ;
F_197 ( V_7 , V_9 ) ;
V_778 -> V_541 = V_746 * sizeof( T_1 ) ;
return V_778 -> V_541 ;
}
T_2 F_192 ( struct V_747 * V_15 )
{
return V_15 -> V_735 . V_777 ;
}
void F_193 ( struct V_747 * V_15 , int V_782 )
{
F_60 ( V_15 , V_223 , L_142 ,
V_782 ) ;
V_15 -> V_735 . V_777 = V_782 ;
}
void F_198 ( struct V_747 * V_15 )
{
const T_2 * V_783 ;
V_783 = V_15 -> V_784 -> V_197 + * ( T_1 * ) V_15 -> V_784 -> V_197 ;
F_113 ( ( T_2 * ) V_783 ) ;
F_128 ( ( T_2 * ) V_783 ) ;
}
void F_199 ( struct V_747 * V_15 )
{
struct V_733 * V_734 = NULL ;
enum V_731 V_732 ;
for ( V_732 = 0 ; V_732 < V_785 ; V_732 ++ ) {
V_734 = & V_15 -> V_735 . V_736 [ V_732 ] ;
if ( V_734 -> V_39 ) {
F_170 ( V_734 -> V_39 ) ;
V_734 -> V_39 = NULL ;
}
}
}
