static int F_1 ( struct V_1 * V_2 ,
void * V_3 , T_1 V_4 ,
void * V_5 , T_1 V_6 )
{
struct V_7 V_8 [] = {
{
. V_9 = V_2 -> V_9 ,
. V_10 = 0 ,
. V_11 = V_4 ,
. V_12 = V_3 ,
} ,
{
. V_9 = V_2 -> V_9 ,
. V_10 = V_13 ,
. V_11 = V_6 ,
. V_12 = V_5 ,
} ,
} ;
int error ;
int V_14 ;
V_14 = F_2 ( V_2 -> V_15 , V_8 , F_3 ( V_8 ) ) ;
if ( V_14 != F_3 ( V_8 ) ) {
error = V_14 < 0 ? V_14 : - V_16 ;
F_4 ( & V_2 -> V_17 , L_1 ,
V_18 , error ) ;
return error ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_19 ,
T_2 * V_12 , T_1 V_11 )
{
T_2 V_20 [] = { 0x22 , 0x00 , 0x10 , 0x0E , 0x23 , 0x00 } ;
int error ;
V_20 [ 2 ] |= V_19 & 0xF ;
error = F_1 ( V_2 , V_20 , sizeof( V_20 ) ,
V_12 , V_11 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_2 , error ) ;
return error ;
}
if ( V_12 [ 0 ] != V_11 ) {
F_4 ( & V_2 -> V_17 , L_3 ,
V_12 [ 0 ] ) ;
return - V_21 ;
}
F_6 ( V_22 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_2 V_23 ,
T_2 * V_12 , T_1 V_11 )
{
T_2 V_20 [] = { 0x22 , 0x00 , 0x13 , 0x0E , V_23 , 0x23 , 0x00 } ;
T_2 V_24 [ V_25 ] ;
T_1 V_26 = V_11 + 2 ;
int error ;
if ( V_26 > sizeof( V_24 ) )
return - V_21 ;
error = F_1 ( V_2 , V_20 , sizeof( V_20 ) ,
V_24 , V_26 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_4 , error ) ;
return error ;
}
if ( V_24 [ 1 ] != 0x03 ) {
F_4 ( & V_2 -> V_17 , L_5 ,
V_24 [ 1 ] ) ;
return - V_21 ;
}
V_26 = F_8 ( T_1 , V_11 , V_24 [ 0 ] ) ;
memcpy ( V_12 , & V_24 [ 2 ] , V_26 ) ;
F_6 ( V_22 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
T_2 * V_12 , T_1 V_27 )
{
T_2 V_20 [ 8 ] ;
T_2 V_24 [ V_25 ] ;
T_1 V_28 = 0 ;
T_1 V_26 = V_27 + 2 ;
int error ;
if ( V_26 > sizeof( V_24 ) )
return - V_21 ;
V_20 [ V_28 ++ ] = 0x22 ;
V_20 [ V_28 ++ ] = 0x00 ;
if ( V_12 [ V_29 ] > 0xF ) {
V_20 [ V_28 ++ ] = 0x30 ;
V_20 [ V_28 ++ ] = 0x02 ;
V_20 [ V_28 ++ ] = V_12 [ V_29 ] ;
} else {
V_20 [ V_28 ++ ] = 0x30 | V_12 [ V_29 ] ;
V_20 [ V_28 ++ ] = 0x02 ;
}
V_20 [ V_28 ++ ] = 0x23 ;
V_20 [ V_28 ++ ] = 0x00 ;
error = F_1 ( V_2 , V_20 , V_28 , V_24 , V_26 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_6 , error ) ;
return error ;
}
V_26 = F_8 ( T_1 , V_27 , F_10 ( V_24 ) ) ;
memcpy ( V_12 , & V_24 [ 2 ] , V_26 ) ;
F_6 ( V_22 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
const T_2 * V_12 , T_1 V_27 )
{
T_2 V_20 [ V_25 ] ;
int V_28 = 0 ;
int error ;
V_20 [ V_28 ++ ] = 0x22 ;
V_20 [ V_28 ++ ] = 0x00 ;
if ( V_12 [ V_29 ] > 0xF ) {
V_20 [ V_28 ++ ] = 0x30 ;
V_20 [ V_28 ++ ] = 0x03 ;
V_20 [ V_28 ++ ] = V_12 [ V_29 ] ;
} else {
V_20 [ V_28 ++ ] = 0x30 | V_12 [ V_29 ] ;
V_20 [ V_28 ++ ] = 0x03 ;
}
V_20 [ V_28 ++ ] = 0x23 ;
V_20 [ V_28 ++ ] = 0x00 ;
V_20 [ V_28 ++ ] = ( V_27 & 0xFF ) ;
V_20 [ V_28 ++ ] = ( ( V_27 & 0xFF00 ) >> 8 ) ;
if ( V_28 + V_27 > sizeof( V_20 ) )
return - V_21 ;
memcpy ( & V_20 [ V_28 ] , V_12 , V_27 ) ;
V_28 += V_27 ;
error = F_12 ( V_2 , V_20 , V_28 ) ;
if ( error < 0 ) {
F_4 ( & V_2 -> V_17 , L_7 , error ) ;
return error ;
}
F_6 ( V_22 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int V_30 , int V_31 )
{
T_2 V_32 [ V_33 ] ;
V_32 [ V_29 ] = V_34 ;
V_32 [ V_35 ] = V_36 ;
F_14 ( ( V_37 ) V_30 , & V_32 [ V_38 ] ) ;
switch ( V_30 ) {
case V_39 :
case V_40 :
case V_41 :
F_15 ( ( V_31 & 0xFF ) , & V_32 [ V_42 ] ) ;
break;
case V_43 :
F_14 ( V_44 , & V_32 [ V_45 ] ) ;
break;
case V_46 :
F_14 ( V_47 , & V_32 [ V_45 ] ) ;
break;
case V_48 :
case V_49 :
case V_50 :
F_15 ( V_31 , & V_32 [ V_45 ] ) ;
break;
default:
V_32 [ V_29 ] = 0 ;
F_4 ( & V_2 -> V_17 , L_8 , V_30 ) ;
return - V_21 ;
}
return F_11 ( V_2 , V_32 , sizeof( V_32 ) ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
int error ;
F_17 ( & V_2 -> V_17 , L_9 ) ;
error = F_13 ( V_2 , V_41 , 0 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_10 ) ;
return error ;
}
F_18 ( V_51 ) ;
return 0 ;
}
static const void * F_19 ( const struct V_52 * V_53 , T_3 V_54 )
{
T_1 V_55 = V_56 ;
T_3 V_57 , V_58 ;
while ( V_55 < V_53 -> V_59 ) {
V_57 = F_20 ( V_53 -> V_60 +
V_55 + V_61 ) ;
if ( V_57 == V_54 )
return V_53 -> V_60 + V_55 ;
V_58 = F_20 ( V_53 -> V_60 +
V_55 + V_62 ) ;
V_55 += V_58 + 2 * sizeof( T_3 ) ;
}
return NULL ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
T_2 V_12 [ V_65 ] ;
int error ;
error = F_5 ( V_2 , V_66 , V_12 , 18 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_11 ) ;
return error ;
}
V_64 -> V_67 = F_10 ( V_12 + V_68 ) ;
V_64 -> V_69 = F_10 ( V_12 + V_70 ) ;
error = F_7 ( V_2 , V_71 , V_12 , 34 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_12 ) ;
return error ;
}
V_64 -> V_72 = F_10 ( V_12 + V_73 ) ;
V_64 -> V_74 = F_10 ( V_12 + V_75 ) ;
V_64 -> V_76 = F_10 ( V_12 + V_77 ) ;
V_64 -> V_78 = F_10 ( V_12 + V_79 ) ;
V_64 -> V_80 = F_10 ( V_12 + V_81 ) / 10 ;
V_64 -> V_82 = F_10 ( V_12 + V_83 ) / 10 ;
V_64 -> V_84 =
F_10 ( V_12 + V_85 ) ;
V_64 -> V_86 = V_87 ;
V_64 -> V_88 = F_22 ( V_87 * V_64 -> V_82 ,
V_64 -> V_80 ) ;
error = F_7 ( V_2 , V_89 , V_12 , 8 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_13 ) ;
return error ;
}
V_64 -> V_90 = V_12 [ 1 ] ;
V_12 [ 0 ] = 0xf2 ;
error = F_9 ( V_2 , V_12 , 16 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_14 ) ;
return error ;
}
if ( V_12 [ 0 ] != 0xf2 ) {
F_4 ( & V_2 -> V_17 , L_15 ,
V_12 [ 0 ] ) ;
return - V_21 ;
}
V_64 -> V_91 = F_10 ( & V_12 [ 1 ] ) ;
F_23 ( & V_2 -> V_17 ,
L_16 ,
V_64 -> V_91 , V_64 -> V_90 ,
V_64 -> V_72 , V_64 -> V_74 ) ;
return 0 ;
}
static int F_24 ( struct V_92 * V_93 ,
const struct V_52 * V_53 )
{
const void * V_94 ;
T_3 V_95 , V_96 ;
T_3 V_59 ;
T_2 V_97 ;
T_2 V_98 ;
V_95 = F_20 ( V_53 -> V_60 + V_99 ) ;
V_96 = F_20 ( V_53 -> V_60 + V_100 ) ;
if ( V_95 != V_101 || V_96 != V_102 ) {
F_4 ( & V_93 -> V_2 -> V_17 , L_17 ) ;
return - V_21 ;
}
V_59 = F_20 ( V_53 -> V_60 + V_103 ) ;
if ( V_59 != V_53 -> V_59 ) {
F_4 ( & V_93 -> V_2 -> V_17 ,
L_18 ,
V_59 , V_53 -> V_59 ) ;
return - V_21 ;
}
V_94 = F_19 ( V_53 , V_104 ) ;
if ( ! V_94 ) {
F_4 ( & V_93 -> V_2 -> V_17 ,
L_19 ) ;
return - V_21 ;
}
V_97 = ( F_20 ( V_94 +
V_105 ) >> 12 ) & 0xF ;
V_98 = ( V_93 -> V_64 . V_91 >> 12 ) & 0xF ;
if ( V_97 != V_98 ) {
F_4 ( & V_93 -> V_2 -> V_17 ,
L_20 ,
V_97 , V_98 ) ;
return - V_106 ;
}
return 0 ;
}
static int F_25 ( const void * V_60 , int V_54 )
{
if ( V_54 == V_104 ) {
T_3 V_91 ;
V_91 = F_20 ( V_60 + V_107 ) ;
if ( V_91 != V_108 )
return - V_21 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , const char * V_60 ,
T_3 V_109 , int V_110 )
{
V_37 V_111 ;
int V_112 = 0 ;
int error ;
T_2 V_113 [ V_114 ] ;
if ( ( V_109 & 0x3 ) != 0 || ( V_110 & 0x3 ) != 0 ) {
F_4 ( & V_2 -> V_17 ,
L_21 ,
V_109 , V_110 ) ;
return - V_21 ;
}
while ( V_110 ) {
V_111 = F_27 ( V_110 , V_115 ) ;
V_113 [ V_29 ] = V_34 ;
V_113 [ V_35 ] = V_116 ;
F_14 ( V_111 , & V_113 [ V_38 ] ) ;
F_15 ( V_109 , & V_113 [ V_42 ] ) ;
memcpy ( & V_113 [ V_117 ] , V_60 , V_111 ) ;
error = F_11 ( V_2 , V_113 , sizeof( V_113 ) ) ;
if ( error )
return error ;
V_110 -= V_111 ;
V_60 += V_111 ;
V_109 += V_111 ;
F_6 ( V_118 ) ;
if ( ( ++ V_112 % 32 ) == 0 ) {
F_18 ( 20 ) ;
}
}
return 0 ;
}
static V_37 F_28 ( V_37 V_119 , T_2 V_120 )
{
T_3 V_121 , V_122 ;
T_3 V_123 ;
T_3 V_124 ;
V_121 = V_119 ;
V_122 = V_120 ;
V_123 = V_121 ^ ( V_122 & 1 ) ;
V_123 ^= V_121 >> 1 ;
V_123 ^= V_121 >> 2 ;
V_123 ^= V_121 >> 4 ;
V_123 ^= V_121 >> 5 ;
V_123 ^= V_121 >> 7 ;
V_123 ^= V_121 >> 11 ;
V_123 ^= V_121 >> 15 ;
V_124 = ( V_121 << 1 ) ^ V_122 ;
V_124 = ( V_124 & ~ 1 ) | ( V_123 & 1 ) ;
return ( V_37 ) V_124 ;
}
static V_37 F_29 ( const T_2 * V_60 , T_1 V_110 )
{
V_37 V_125 = 0 ;
T_1 V_126 ;
for ( V_126 = 0 ; V_126 < V_110 ; V_126 ++ )
V_125 = F_28 ( V_125 , V_60 [ V_126 ] ) ;
return V_125 ;
}
static int F_30 ( struct V_1 * V_2 , V_37 * V_125 ,
T_3 V_109 , int V_110 )
{
int error ;
int V_127 ;
T_2 V_113 [ V_114 ] ;
T_2 V_32 [ V_33 ] ;
error = F_13 ( V_2 , V_50 , V_110 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_22 ) ;
return error ;
}
error = F_13 ( V_2 , V_49 , V_109 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_23 ) ;
return error ;
}
V_127 = F_31 ( V_110 , 1024 ) ;
F_18 ( V_127 * 30 ) ;
memset ( V_32 , 0 , sizeof( V_32 ) ) ;
V_32 [ V_29 ] = V_128 ;
V_32 [ V_35 ] = V_129 ;
error = F_11 ( V_2 , V_32 , sizeof( V_32 ) ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_24 ) ;
return error ;
}
memset ( V_113 , 0 , sizeof( V_113 ) ) ;
V_113 [ V_29 ] = V_130 ;
error = F_9 ( V_2 , V_113 , sizeof( V_113 ) ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_25 ) ;
return error ;
}
* V_125 = F_10 ( & V_113 [ V_117 ] ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , const void * V_131 )
{
T_3 V_132 = F_20 ( V_131 + V_133 ) ;
T_3 V_59 = F_20 ( V_131 + V_134 ) ;
const void * V_60 = V_131 + V_107 ;
int error ;
int V_135 ;
int V_136 ;
int V_137 = 0 ;
V_37 V_138 , V_139 ;
F_17 ( & V_2 -> V_17 , L_26 ) ;
error = F_13 ( V_2 , V_40 , V_140 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_27 ) ;
return error ;
}
error = F_13 ( V_2 , V_46 , 0 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_28 ) ;
goto V_141;
}
F_6 ( 10 ) ;
while ( V_59 ) {
F_17 ( & V_2 -> V_17 , L_29 , V_18 ,
V_132 , V_59 ) ;
V_136 = F_8 ( T_3 , V_59 , V_142 ) ;
V_59 -= V_136 ;
for ( V_137 = 0 ; V_137 < V_143 ; V_137 ++ ) {
error = F_13 ( V_2 , V_48 ,
V_132 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 ,
L_30 , V_132 ) ;
break;
}
F_18 ( V_144 ) ;
error = F_26 ( V_2 , V_60 , V_132 ,
V_136 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 ,
L_31 ,
V_132 , V_136 ) ;
break;
}
error = F_30 ( V_2 , & V_138 ,
V_132 , V_136 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 ,
L_32 ,
V_132 , V_136 ) ;
break;
}
V_139 =
F_29 ( V_60 , V_136 ) ;
if ( V_138 == V_139 )
break;
F_4 ( & V_2 -> V_17 ,
L_33 ,
V_138 , V_139 , V_137 ) ;
}
if ( V_137 == V_143 ) {
F_4 ( & V_2 -> V_17 , L_34 ) ;
error = - V_16 ;
goto V_145;
}
V_132 = V_132 + V_136 ;
V_60 = V_60 + V_136 ;
}
V_145:
V_135 = F_13 ( V_2 , V_43 , 0 ) ;
if ( V_135 )
F_4 ( & V_2 -> V_17 , L_35 ) ;
F_6 ( 10 ) ;
V_141:
V_135 = F_13 ( V_2 , V_39 , 0 ) ;
if ( V_135 )
F_4 ( & V_2 -> V_17 , L_36 ) ;
return error ? error : V_135 ;
}
static int F_33 ( struct V_1 * V_2 ,
const struct V_52 * V_53 , T_3 V_146 )
{
const void * V_131 ;
int error ;
V_131 = F_19 ( V_53 , V_146 ) ;
if ( ! V_131 ) {
F_4 ( & V_2 -> V_17 , L_37 ,
V_146 ) ;
return - V_21 ;
}
error = F_25 ( V_131 , V_146 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_38 ,
V_146 , error ) ;
return error ;
}
error = F_32 ( V_2 , V_131 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 ,
L_39 ,
V_146 , error ) ;
return error ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
const struct V_52 * V_53 ,
unsigned int V_57 )
{
struct V_92 * V_93 = F_35 ( V_2 ) ;
int error ;
error = F_24 ( V_93 , V_53 ) ;
if ( error )
return error ;
error = F_36 ( & V_93 -> V_147 ) ;
if ( error )
return error ;
F_37 ( V_2 -> V_148 ) ;
error = F_33 ( V_2 , V_53 , V_57 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 ,
L_40 ,
V_57 , error ) ;
goto V_149;
}
error = F_16 ( V_2 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_41 , error ) ;
goto V_149;
}
error = F_21 ( V_2 , & V_93 -> V_64 ) ;
if ( error )
F_4 ( & V_2 -> V_17 ,
L_42 , error ) ;
V_149:
F_38 ( V_2 -> V_148 ) ;
F_39 ( & V_93 -> V_147 ) ;
return error ? error : 0 ;
}
static int F_40 ( struct V_150 * V_17 ,
const char * V_151 , unsigned int V_57 )
{
struct V_1 * V_2 = F_41 ( V_17 ) ;
const struct V_52 * V_53 ;
int error ;
error = F_42 ( & V_53 , V_151 , V_17 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_43 ,
V_151 , error ) ;
return error ;
}
error = F_34 ( V_2 , V_53 , V_57 ) ;
F_43 ( V_53 ) ;
return error ? error : 0 ;
}
static T_4 F_44 ( struct V_150 * V_17 ,
struct V_152 * V_153 , char * V_12 )
{
struct V_1 * V_2 = F_41 ( V_17 ) ;
struct V_92 * V_93 = F_35 ( V_2 ) ;
T_3 V_154 ;
V_154 = V_93 -> V_64 . V_72 ;
V_154 = ( V_154 << 16 ) | V_93 -> V_64 . V_74 ;
return F_45 ( V_12 , V_155 , L_44 , V_154 ) ;
}
static T_4 F_46 ( struct V_150 * V_17 ,
struct V_152 * V_153 , char * V_12 )
{
struct V_1 * V_2 = F_41 ( V_17 ) ;
struct V_92 * V_93 = F_35 ( V_2 ) ;
return F_45 ( V_12 , V_155 , L_44 , V_93 -> V_64 . V_91 ) ;
}
static T_4 F_47 ( struct V_150 * V_17 ,
struct V_152 * V_153 , char * V_12 )
{
struct V_1 * V_2 = F_41 ( V_17 ) ;
struct V_92 * V_93 = F_35 ( V_2 ) ;
return F_45 ( V_12 , V_155 , L_44 , V_93 -> V_64 . V_90 ) ;
}
static T_4 F_48 ( struct V_150 * V_17 ,
struct V_152 * V_153 ,
const char * V_12 , T_1 V_112 )
{
int error ;
error = F_40 ( V_17 , V_156 , V_157 ) ;
return error ? error : V_112 ;
}
static T_4 F_49 ( struct V_150 * V_17 ,
struct V_152 * V_153 ,
const char * V_12 , T_1 V_112 )
{
int error ;
error = F_40 ( V_17 , V_158 , V_104 ) ;
return error ? error : V_112 ;
}
static void F_50 ( struct V_159 * V_160 ,
struct V_63 * V_64 ,
T_2 * V_12 )
{
int V_161 ;
T_3 V_162 , V_124 , V_163 ;
T_2 V_164 ;
V_161 = ( V_12 [ V_165 ] >> 3 ) - 1 ;
if ( V_161 < 0 )
return;
if ( ! ( V_12 [ V_165 ] & 0x1 ) )
return;
V_163 = V_12 [ V_166 ] ;
V_163 *= V_64 -> V_84 ;
V_164 = V_12 [ V_167 ] ;
V_162 = F_10 ( V_12 + V_168 ) ;
V_124 = F_10 ( V_12 + V_169 ) ;
V_124 = F_22 ( V_124 * V_64 -> V_82 , V_64 -> V_80 ) ;
if ( V_162 > V_64 -> V_86 || V_124 > V_64 -> V_88 )
return;
F_17 ( V_160 -> V_17 . V_170 , L_45 ,
V_161 , V_162 , V_124 ) ;
F_51 ( V_160 , V_161 ) ;
F_52 ( V_160 , V_171 , 1 ) ;
F_53 ( V_160 , V_172 , V_163 ) ;
F_53 ( V_160 , V_173 , V_164 ) ;
F_53 ( V_160 , V_174 , V_162 ) ;
F_53 ( V_160 , V_175 , V_124 ) ;
}
static T_5 F_54 ( int V_148 , void * V_176 )
{
struct V_92 * V_93 = V_176 ;
struct V_1 * V_2 = V_93 -> V_2 ;
int V_126 , V_177 ;
int error ;
T_2 V_178 [ V_179 ] = { 0 } ;
error = F_55 ( V_2 , V_178 , V_179 ) ;
if ( error < 0 ) {
F_4 ( & V_2 -> V_17 , L_46 , error ) ;
goto V_180;
}
V_177 = V_178 [ V_181 ] ;
if ( ! V_177 )
goto V_180;
for ( V_126 = 0 ; V_126 < V_182 ; V_126 ++ )
F_50 ( V_93 -> V_160 ,
& V_93 -> V_64 ,
& V_178 [ V_183 +
V_126 * V_184 ] ) ;
F_56 ( V_93 -> V_160 ) ;
F_57 ( V_93 -> V_160 ) ;
V_180:
return V_185 ;
}
static int F_58 ( struct V_92 * V_93 )
{
struct V_150 * V_17 = & V_93 -> V_2 -> V_17 ;
struct V_159 * V_160 ;
unsigned int V_186 = F_22 ( V_87 , V_93 -> V_64 . V_80 ) ;
int error ;
V_160 = F_59 ( V_17 ) ;
if ( ! V_160 ) {
F_4 ( V_17 , L_47 ) ;
return - V_187 ;
}
V_93 -> V_160 = V_160 ;
V_160 -> V_188 = L_48 ;
V_160 -> V_54 . V_189 = V_190 ;
V_160 -> V_54 . V_191 = V_93 -> V_64 . V_67 ;
V_160 -> V_54 . V_192 = V_93 -> V_64 . V_69 ;
V_160 -> V_193 = V_93 -> V_193 ;
F_60 ( V_160 , V_174 , 0 ,
V_93 -> V_64 . V_86 , 0 , 0 ) ;
F_60 ( V_160 , V_175 , 0 ,
V_93 -> V_64 . V_88 , 0 , 0 ) ;
F_61 ( V_160 , V_174 , V_186 ) ;
F_61 ( V_160 , V_175 , V_186 ) ;
F_60 ( V_160 , V_172 ,
0 , V_93 -> V_64 . V_86 , 0 , 0 ) ;
F_60 ( V_160 , V_173 , 0 , 0xFF , 0 , 0 ) ;
F_62 ( V_160 , V_182 ,
V_194 | V_195 ) ;
error = F_63 ( V_160 ) ;
if ( error ) {
F_4 ( V_17 , L_49 , error ) ;
return error ;
}
return 0 ;
}
static int F_64 ( struct V_1 * V_2 ,
const struct V_196 * V_54 )
{
struct V_92 * V_93 ;
int error ;
F_17 ( & V_2 -> V_17 , L_50 ,
V_2 -> V_15 -> V_197 , V_2 -> V_148 ) ;
if ( ! F_65 ( V_2 -> V_15 , V_198 ) )
return - V_199 ;
V_93 = F_66 ( & V_2 -> V_17 , sizeof( * V_93 ) , V_200 ) ;
if ( ! V_93 )
return - V_187 ;
V_93 -> V_2 = V_2 ;
F_67 ( & V_93 -> V_147 ) ;
F_68 ( V_2 , V_93 ) ;
snprintf ( V_93 -> V_193 , sizeof( V_93 -> V_193 ) , L_51 ,
V_2 -> V_15 -> V_197 , V_2 -> V_9 ) ;
error = F_21 ( V_2 , & V_93 -> V_64 ) ;
if ( error )
return error ;
error = F_58 ( V_93 ) ;
if ( error )
return error ;
error = F_69 ( & V_2 -> V_17 , V_2 -> V_148 ,
NULL , F_54 ,
V_201 ,
V_2 -> V_188 , V_93 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_52 , error ) ;
return error ;
}
error = F_70 ( & V_2 -> V_17 . V_202 , & V_203 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_53 , error ) ;
return error ;
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
F_72 ( & V_2 -> V_17 . V_202 , & V_203 ) ;
return 0 ;
}
static int T_6 F_73 ( struct V_150 * V_17 )
{
struct V_1 * V_2 = F_41 ( V_17 ) ;
int error ;
F_37 ( V_2 -> V_148 ) ;
error = F_13 ( V_2 , V_40 , V_204 ) ;
if ( error ) {
F_38 ( V_2 -> V_148 ) ;
F_4 ( & V_2 -> V_17 ,
L_54 ,
error ) ;
return error ;
}
return 0 ;
}
static int T_6 F_74 ( struct V_150 * V_17 )
{
struct V_1 * V_2 = F_41 ( V_17 ) ;
int error ;
F_6 ( 100 ) ;
error = F_13 ( V_2 , V_39 , 0 ) ;
if ( error )
F_4 ( & V_2 -> V_17 ,
L_55 ,
error ) ;
F_38 ( V_2 -> V_148 ) ;
return 0 ;
}
