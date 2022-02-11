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
T_2 V_20 [] = { 0x22 , 0x00 , 0x13 , 0x0E , V_19 , 0x23 , 0x00 } ;
T_2 V_21 [ V_22 ] ;
T_1 V_23 = V_11 + 2 ;
int error ;
if ( V_23 > sizeof( V_21 ) )
return - V_24 ;
error = F_1 ( V_2 , V_20 , sizeof( V_20 ) ,
V_21 , V_23 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_2 , error ) ;
return error ;
}
if ( V_21 [ 1 ] != 0x03 ) {
F_4 ( & V_2 -> V_17 , L_3 ,
V_21 [ 1 ] ) ;
return - V_24 ;
}
V_23 = F_6 ( T_1 , V_11 , V_21 [ 0 ] ) ;
memcpy ( V_12 , & V_21 [ 2 ] , V_23 ) ;
F_7 ( V_25 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
T_2 * V_12 , T_1 V_26 )
{
T_2 V_20 [ 8 ] ;
T_2 V_21 [ V_22 ] ;
T_1 V_27 = 0 ;
T_1 V_23 = V_26 + 2 ;
int error ;
if ( V_23 > sizeof( V_21 ) )
return - V_24 ;
V_20 [ V_27 ++ ] = 0x22 ;
V_20 [ V_27 ++ ] = 0x00 ;
if ( V_12 [ V_28 ] > 0xF ) {
V_20 [ V_27 ++ ] = 0x30 ;
V_20 [ V_27 ++ ] = 0x02 ;
V_20 [ V_27 ++ ] = V_12 [ V_28 ] ;
} else {
V_20 [ V_27 ++ ] = 0x30 | V_12 [ V_28 ] ;
V_20 [ V_27 ++ ] = 0x02 ;
}
V_20 [ V_27 ++ ] = 0x23 ;
V_20 [ V_27 ++ ] = 0x00 ;
error = F_1 ( V_2 , V_20 , V_27 , V_21 , V_23 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_4 , error ) ;
return error ;
}
V_23 = F_6 ( T_1 , V_26 , F_9 ( V_21 ) ) ;
memcpy ( V_12 , & V_21 [ 2 ] , V_23 ) ;
F_7 ( V_25 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
const T_2 * V_12 , T_1 V_26 )
{
T_2 V_20 [ V_22 ] ;
int V_27 = 0 ;
int error ;
V_20 [ V_27 ++ ] = 0x22 ;
V_20 [ V_27 ++ ] = 0x00 ;
if ( V_12 [ V_28 ] > 0xF ) {
V_20 [ V_27 ++ ] = 0x30 ;
V_20 [ V_27 ++ ] = 0x03 ;
V_20 [ V_27 ++ ] = V_12 [ V_28 ] ;
} else {
V_20 [ V_27 ++ ] = 0x30 | V_12 [ V_28 ] ;
V_20 [ V_27 ++ ] = 0x03 ;
}
V_20 [ V_27 ++ ] = 0x23 ;
V_20 [ V_27 ++ ] = 0x00 ;
V_20 [ V_27 ++ ] = ( V_26 & 0xFF ) ;
V_20 [ V_27 ++ ] = ( ( V_26 & 0xFF00 ) >> 8 ) ;
if ( V_27 + V_26 > sizeof( V_20 ) )
return - V_24 ;
memcpy ( & V_20 [ V_27 ] , V_12 , V_26 ) ;
V_27 += V_26 ;
error = F_11 ( V_2 , V_20 , V_27 ) ;
if ( error < 0 ) {
F_4 ( & V_2 -> V_17 , L_5 , error ) ;
return error ;
}
F_7 ( V_25 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , int V_29 , int V_30 )
{
T_2 V_31 [ V_32 ] ;
V_31 [ V_28 ] = V_33 ;
V_31 [ V_34 ] = V_35 ;
F_13 ( ( V_36 ) V_29 , & V_31 [ V_37 ] ) ;
switch ( V_29 ) {
case V_38 :
case V_39 :
case V_40 :
F_14 ( ( V_30 & 0xFF ) , & V_31 [ V_41 ] ) ;
break;
case V_42 :
F_13 ( V_43 , & V_31 [ V_44 ] ) ;
break;
case V_45 :
F_13 ( V_46 , & V_31 [ V_44 ] ) ;
break;
case V_47 :
case V_48 :
case V_49 :
F_14 ( V_30 , & V_31 [ V_44 ] ) ;
break;
default:
V_31 [ V_28 ] = 0 ;
F_4 ( & V_2 -> V_17 , L_6 , V_29 ) ;
return - V_24 ;
}
return F_10 ( V_2 , V_31 , sizeof( V_31 ) ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
int error ;
F_16 ( & V_2 -> V_17 , L_7 ) ;
error = F_12 ( V_2 , V_40 , 0 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_8 ) ;
return error ;
}
F_17 ( 200 ) ;
return 0 ;
}
static const void * F_18 ( const struct V_50 * V_51 , T_3 V_52 )
{
T_1 V_53 = V_54 ;
T_3 V_55 , V_56 ;
while ( V_53 < V_51 -> V_57 ) {
V_55 = F_19 ( V_51 -> V_58 +
V_53 + V_59 ) ;
if ( V_55 == V_52 )
return V_51 -> V_58 + V_53 ;
V_56 = F_19 ( V_51 -> V_58 +
V_53 + V_60 ) ;
V_53 += V_56 + 2 * sizeof( T_3 ) ;
}
return NULL ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_61 * V_62 )
{
T_2 V_12 [ V_63 ] ;
int error ;
error = F_5 ( V_2 , V_64 , V_12 , 34 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_9 ) ;
return error ;
}
V_62 -> V_65 = F_9 ( V_12 + V_66 ) ;
V_62 -> V_67 = F_9 ( V_12 + V_68 ) ;
V_62 -> V_69 = F_9 ( V_12 + V_70 ) ;
V_62 -> V_71 = F_9 ( V_12 + V_72 ) ;
V_62 -> V_73 = F_9 ( V_12 + V_74 ) / 10 ;
V_62 -> V_75 = F_9 ( V_12 + V_76 ) / 10 ;
V_62 -> V_77 =
F_9 ( V_12 + V_78 ) ;
V_62 -> V_79 = V_80 ;
V_62 -> V_81 = F_21 ( V_80 * V_62 -> V_75 ,
V_62 -> V_73 ) ;
error = F_5 ( V_2 , V_82 , V_12 , 8 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_10 ) ;
return error ;
}
V_62 -> V_83 = V_12 [ 1 ] ;
V_12 [ 0 ] = 0xf2 ;
error = F_8 ( V_2 , V_12 , 16 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_11 ) ;
return error ;
}
if ( V_12 [ 0 ] != 0xf2 ) {
F_4 ( & V_2 -> V_17 , L_12 ,
V_12 [ 0 ] ) ;
return - V_24 ;
}
V_62 -> V_84 = F_9 ( & V_12 [ 1 ] ) ;
F_22 ( & V_2 -> V_17 ,
L_13 ,
V_62 -> V_84 , V_62 -> V_83 ,
V_62 -> V_65 , V_62 -> V_67 ) ;
return 0 ;
}
static int F_23 ( struct V_85 * V_86 ,
const struct V_50 * V_51 )
{
const void * V_87 ;
T_3 V_88 , V_89 ;
T_3 V_57 ;
T_2 V_90 ;
T_2 V_91 ;
V_88 = F_19 ( V_51 -> V_58 + V_92 ) ;
V_89 = F_19 ( V_51 -> V_58 + V_93 ) ;
if ( V_88 != V_94 || V_89 != V_95 ) {
F_4 ( & V_86 -> V_2 -> V_17 , L_14 ) ;
return - V_24 ;
}
V_57 = F_19 ( V_51 -> V_58 + V_96 ) ;
if ( V_57 != V_51 -> V_57 ) {
F_4 ( & V_86 -> V_2 -> V_17 ,
L_15 ,
V_57 , V_51 -> V_57 ) ;
return - V_24 ;
}
V_87 = F_18 ( V_51 , V_97 ) ;
if ( ! V_87 ) {
F_4 ( & V_86 -> V_2 -> V_17 ,
L_16 ) ;
return - V_24 ;
}
V_90 = ( F_19 ( V_87 +
V_98 ) >> 12 ) & 0xF ;
V_91 = ( V_86 -> V_62 . V_84 >> 12 ) & 0xF ;
if ( V_90 != V_91 ) {
F_4 ( & V_86 -> V_2 -> V_17 ,
L_17 ,
V_90 , V_91 ) ;
return - V_99 ;
}
return 0 ;
}
static int F_24 ( const void * V_58 , int V_52 )
{
if ( V_52 == V_97 ) {
T_3 V_84 ;
V_84 = F_19 ( V_58 + V_100 ) ;
if ( V_84 != V_101 )
return - V_24 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , const char * V_58 ,
T_3 V_102 , int V_103 )
{
V_36 V_104 ;
int V_105 = 0 ;
int error ;
T_2 V_106 [ V_107 ] ;
if ( ( V_102 & 0x3 ) != 0 || ( V_103 & 0x3 ) != 0 ) {
F_4 ( & V_2 -> V_17 ,
L_18 ,
V_102 , V_103 ) ;
return - V_24 ;
}
while ( V_103 ) {
V_104 = F_26 ( V_103 , V_108 ) ;
V_106 [ V_28 ] = V_33 ;
V_106 [ V_34 ] = V_109 ;
F_13 ( V_104 , & V_106 [ V_37 ] ) ;
F_14 ( V_102 , & V_106 [ V_41 ] ) ;
memcpy ( & V_106 [ V_110 ] , V_58 , V_104 ) ;
error = F_10 ( V_2 , V_106 , sizeof( V_106 ) ) ;
if ( error )
return error ;
V_103 -= V_104 ;
V_58 += V_104 ;
V_102 += V_104 ;
F_7 ( V_111 ) ;
if ( ( ++ V_105 % 32 ) == 0 ) {
F_17 ( 20 ) ;
}
}
return 0 ;
}
static V_36 F_27 ( V_36 V_112 , T_2 V_113 )
{
T_3 V_114 , V_115 ;
T_3 V_116 ;
T_3 V_117 ;
V_114 = V_112 ;
V_115 = V_113 ;
V_116 = V_114 ^ ( V_115 & 1 ) ;
V_116 ^= V_114 >> 1 ;
V_116 ^= V_114 >> 2 ;
V_116 ^= V_114 >> 4 ;
V_116 ^= V_114 >> 5 ;
V_116 ^= V_114 >> 7 ;
V_116 ^= V_114 >> 11 ;
V_116 ^= V_114 >> 15 ;
V_117 = ( V_114 << 1 ) ^ V_115 ;
V_117 = ( V_117 & ~ 1 ) | ( V_116 & 1 ) ;
return ( V_36 ) V_117 ;
}
static V_36 F_28 ( const T_2 * V_58 , T_1 V_103 )
{
V_36 V_118 = 0 ;
T_1 V_119 ;
for ( V_119 = 0 ; V_119 < V_103 ; V_119 ++ )
V_118 = F_27 ( V_118 , V_58 [ V_119 ] ) ;
return V_118 ;
}
static int F_29 ( struct V_1 * V_2 , V_36 * V_118 ,
T_3 V_102 , int V_103 )
{
int error ;
int V_120 ;
T_2 V_106 [ V_107 ] ;
T_2 V_31 [ V_32 ] ;
error = F_12 ( V_2 , V_49 , V_103 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_19 ) ;
return error ;
}
error = F_12 ( V_2 , V_48 , V_102 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_20 ) ;
return error ;
}
V_120 = F_30 ( V_103 , 1024 ) ;
F_17 ( V_120 * 30 ) ;
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
V_31 [ V_28 ] = V_121 ;
V_31 [ V_34 ] = V_122 ;
error = F_10 ( V_2 , V_31 , sizeof( V_31 ) ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_21 ) ;
return error ;
}
memset ( V_106 , 0 , sizeof( V_106 ) ) ;
V_106 [ V_28 ] = V_123 ;
error = F_8 ( V_2 , V_106 , sizeof( V_106 ) ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_22 ) ;
return error ;
}
* V_118 = F_9 ( & V_106 [ V_110 ] ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , const void * V_124 )
{
T_3 V_125 = F_19 ( V_124 + V_126 ) ;
T_3 V_57 = F_19 ( V_124 + V_127 ) ;
const void * V_58 = V_124 + V_100 ;
int error ;
int V_128 ;
int V_129 ;
int V_130 = 0 ;
V_36 V_131 , V_132 ;
F_16 ( & V_2 -> V_17 , L_23 ) ;
error = F_12 ( V_2 , V_39 , V_133 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_24 ) ;
return error ;
}
error = F_12 ( V_2 , V_45 , 0 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_25 ) ;
goto V_134;
}
F_7 ( 10 ) ;
while ( V_57 ) {
F_16 ( & V_2 -> V_17 , L_26 , V_18 ,
V_125 , V_57 ) ;
V_129 = F_6 ( T_3 , V_57 , V_135 ) ;
V_57 -= V_129 ;
for ( V_130 = 0 ; V_130 < V_136 ; V_130 ++ ) {
error = F_12 ( V_2 , V_47 ,
V_125 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 ,
L_27 , V_125 ) ;
break;
}
F_17 ( 50 ) ;
error = F_25 ( V_2 , V_58 , V_125 ,
V_129 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 ,
L_28 ,
V_125 , V_129 ) ;
break;
}
error = F_29 ( V_2 , & V_131 ,
V_125 , V_129 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 ,
L_29 ,
V_125 , V_129 ) ;
break;
}
V_132 =
F_28 ( V_58 , V_129 ) ;
if ( V_131 == V_132 )
break;
F_4 ( & V_2 -> V_17 ,
L_30 ,
V_131 , V_132 , V_130 ) ;
}
if ( V_130 == V_136 ) {
F_4 ( & V_2 -> V_17 , L_31 ) ;
error = - V_16 ;
goto V_137;
}
V_125 = V_125 + V_129 ;
V_58 = V_58 + V_129 ;
}
V_137:
V_128 = F_12 ( V_2 , V_42 , 0 ) ;
if ( V_128 )
F_4 ( & V_2 -> V_17 , L_32 ) ;
F_7 ( 10 ) ;
V_134:
V_128 = F_12 ( V_2 , V_38 , 0 ) ;
if ( V_128 )
F_4 ( & V_2 -> V_17 , L_33 ) ;
return error ? error : V_128 ;
}
static int F_32 ( struct V_1 * V_2 ,
const struct V_50 * V_51 , T_3 V_138 )
{
const void * V_124 ;
int error ;
V_124 = F_18 ( V_51 , V_138 ) ;
if ( ! V_124 ) {
F_4 ( & V_2 -> V_17 , L_34 ,
V_138 ) ;
return - V_24 ;
}
error = F_24 ( V_124 , V_138 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_35 ,
V_138 , error ) ;
return error ;
}
error = F_31 ( V_2 , V_124 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 ,
L_36 ,
V_138 , error ) ;
return error ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
const struct V_50 * V_51 ,
unsigned int V_55 )
{
struct V_85 * V_86 = F_34 ( V_2 ) ;
int error ;
error = F_23 ( V_86 , V_51 ) ;
if ( error )
return error ;
error = F_35 ( & V_86 -> V_139 ) ;
if ( error )
return error ;
F_36 ( V_2 -> V_140 ) ;
error = F_32 ( V_2 , V_51 , V_55 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 ,
L_37 ,
V_55 , error ) ;
goto V_141;
}
error = F_15 ( V_2 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_38 , error ) ;
goto V_141;
}
error = F_20 ( V_2 , & V_86 -> V_62 ) ;
if ( error )
F_4 ( & V_2 -> V_17 ,
L_39 , error ) ;
V_141:
F_37 ( V_2 -> V_140 ) ;
F_38 ( & V_86 -> V_139 ) ;
return error ? error : 0 ;
}
static int F_39 ( struct V_142 * V_17 ,
const char * V_143 , unsigned int V_55 )
{
struct V_1 * V_2 = F_40 ( V_17 ) ;
const struct V_50 * V_51 ;
int error ;
error = F_41 ( & V_51 , V_143 , V_17 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_40 ,
V_143 , error ) ;
return error ;
}
error = F_33 ( V_2 , V_51 , V_55 ) ;
F_42 ( V_51 ) ;
return error ? error : 0 ;
}
static T_4 F_43 ( struct V_142 * V_17 ,
struct V_144 * V_145 , char * V_12 )
{
struct V_1 * V_2 = F_40 ( V_17 ) ;
struct V_85 * V_86 = F_34 ( V_2 ) ;
T_3 V_146 ;
V_146 = V_86 -> V_62 . V_65 ;
V_146 = ( V_146 << 16 ) | V_86 -> V_62 . V_67 ;
return F_44 ( V_12 , V_147 , L_41 , V_146 ) ;
}
static T_4 F_45 ( struct V_142 * V_17 ,
struct V_144 * V_145 , char * V_12 )
{
struct V_1 * V_2 = F_40 ( V_17 ) ;
struct V_85 * V_86 = F_34 ( V_2 ) ;
return F_44 ( V_12 , V_147 , L_41 , V_86 -> V_62 . V_84 ) ;
}
static T_4 F_46 ( struct V_142 * V_17 ,
struct V_144 * V_145 , char * V_12 )
{
struct V_1 * V_2 = F_40 ( V_17 ) ;
struct V_85 * V_86 = F_34 ( V_2 ) ;
return F_44 ( V_12 , V_147 , L_41 , V_86 -> V_62 . V_83 ) ;
}
static T_4 F_47 ( struct V_142 * V_17 ,
struct V_144 * V_145 ,
const char * V_12 , T_1 V_105 )
{
int error ;
error = F_39 ( V_17 , V_148 , V_149 ) ;
return error ? error : V_105 ;
}
static T_4 F_48 ( struct V_142 * V_17 ,
struct V_144 * V_145 ,
const char * V_12 , T_1 V_105 )
{
int error ;
error = F_39 ( V_17 , V_150 , V_97 ) ;
return error ? error : V_105 ;
}
static void F_49 ( struct V_151 * V_152 ,
struct V_61 * V_62 ,
T_2 * V_12 )
{
int V_153 ;
T_3 V_154 , V_117 , V_155 ;
T_2 V_156 ;
V_153 = ( V_12 [ V_157 ] >> 3 ) - 1 ;
if ( V_153 < 0 )
return;
if ( ! ( V_12 [ V_157 ] & 0x1 ) )
return;
V_155 = V_12 [ V_158 ] ;
V_155 *= V_62 -> V_77 ;
V_156 = V_12 [ V_159 ] ;
V_154 = F_9 ( V_12 + V_160 ) ;
V_117 = F_9 ( V_12 + V_161 ) ;
V_117 = F_21 ( V_117 * V_62 -> V_75 , V_62 -> V_73 ) ;
if ( V_154 > V_62 -> V_79 || V_117 > V_62 -> V_81 )
return;
F_16 ( V_152 -> V_17 . V_162 , L_42 ,
V_153 , V_154 , V_117 ) ;
F_50 ( V_152 , V_153 ) ;
F_51 ( V_152 , V_163 , 1 ) ;
F_52 ( V_152 , V_164 , V_155 ) ;
F_52 ( V_152 , V_165 , V_156 ) ;
F_52 ( V_152 , V_166 , V_154 ) ;
F_52 ( V_152 , V_167 , V_117 ) ;
}
static T_5 F_53 ( int V_140 , void * V_168 )
{
struct V_85 * V_86 = V_168 ;
struct V_1 * V_2 = V_86 -> V_2 ;
int V_119 , V_169 ;
int error ;
T_2 V_170 [ V_171 ] = { 0 } ;
error = F_54 ( V_2 , V_170 , V_171 ) ;
if ( error < 0 ) {
F_4 ( & V_2 -> V_17 , L_43 , error ) ;
goto V_172;
}
V_169 = V_170 [ V_173 ] ;
if ( ! V_169 )
goto V_172;
for ( V_119 = 0 ; V_119 < V_174 ; V_119 ++ )
F_49 ( V_86 -> V_152 ,
& V_86 -> V_62 ,
& V_170 [ V_175 +
V_119 * V_176 ] ) ;
F_55 ( V_86 -> V_152 ) ;
F_56 ( V_86 -> V_152 ) ;
V_172:
return V_177 ;
}
static int F_57 ( struct V_85 * V_86 )
{
struct V_142 * V_17 = & V_86 -> V_2 -> V_17 ;
struct V_151 * V_152 ;
unsigned int V_178 = F_21 ( V_80 , V_86 -> V_62 . V_73 ) ;
int error ;
V_152 = F_58 ( V_17 ) ;
if ( ! V_152 ) {
F_4 ( V_17 , L_44 ) ;
return - V_179 ;
}
V_86 -> V_152 = V_152 ;
V_152 -> V_180 = L_45 ;
V_152 -> V_52 . V_181 = V_182 ;
V_152 -> V_183 = V_86 -> V_183 ;
F_59 ( V_152 , V_166 , 0 ,
V_86 -> V_62 . V_79 , 0 , 0 ) ;
F_59 ( V_152 , V_167 , 0 ,
V_86 -> V_62 . V_81 , 0 , 0 ) ;
F_60 ( V_152 , V_166 , V_178 ) ;
F_60 ( V_152 , V_167 , V_178 ) ;
F_59 ( V_152 , V_164 ,
0 , V_86 -> V_62 . V_79 , 0 , 0 ) ;
F_59 ( V_152 , V_165 , 0 , 0xFF , 0 , 0 ) ;
F_61 ( V_152 , V_174 ,
V_184 | V_185 ) ;
error = F_62 ( V_152 ) ;
if ( error ) {
F_4 ( V_17 , L_46 , error ) ;
return error ;
}
return 0 ;
}
static int F_63 ( struct V_1 * V_2 ,
const struct V_186 * V_52 )
{
struct V_85 * V_86 ;
int error ;
F_16 ( & V_2 -> V_17 , L_47 ,
V_2 -> V_15 -> V_187 , V_2 -> V_140 ) ;
if ( ! F_64 ( V_2 -> V_15 , V_188 ) )
return - V_189 ;
V_86 = F_65 ( & V_2 -> V_17 , sizeof( * V_86 ) , V_190 ) ;
if ( ! V_86 )
return - V_179 ;
V_86 -> V_2 = V_2 ;
F_66 ( & V_86 -> V_139 ) ;
F_67 ( V_2 , V_86 ) ;
snprintf ( V_86 -> V_183 , sizeof( V_86 -> V_183 ) , L_48 ,
V_2 -> V_15 -> V_187 , V_2 -> V_9 ) ;
error = F_20 ( V_2 , & V_86 -> V_62 ) ;
if ( error )
return error ;
error = F_57 ( V_86 ) ;
if ( error )
return error ;
error = F_68 ( & V_2 -> V_17 , V_2 -> V_140 ,
NULL , F_53 ,
V_191 ,
V_2 -> V_180 , V_86 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_49 , error ) ;
return error ;
}
error = F_69 ( & V_2 -> V_17 . V_192 , & V_193 ) ;
if ( error ) {
F_4 ( & V_2 -> V_17 , L_50 , error ) ;
return error ;
}
return 0 ;
}
static int F_70 ( struct V_1 * V_2 )
{
F_71 ( & V_2 -> V_17 . V_192 , & V_193 ) ;
return 0 ;
}
static int T_6 F_72 ( struct V_142 * V_17 )
{
struct V_1 * V_2 = F_40 ( V_17 ) ;
int error ;
F_36 ( V_2 -> V_140 ) ;
error = F_12 ( V_2 , V_39 , V_194 ) ;
if ( error ) {
F_37 ( V_2 -> V_140 ) ;
F_4 ( & V_2 -> V_17 ,
L_51 ,
error ) ;
return error ;
}
return 0 ;
}
static int T_6 F_73 ( struct V_142 * V_17 )
{
struct V_1 * V_2 = F_40 ( V_17 ) ;
int error ;
F_7 ( 100 ) ;
error = F_12 ( V_2 , V_38 , 0 ) ;
if ( error )
F_4 ( & V_2 -> V_17 ,
L_52 ,
error ) ;
F_37 ( V_2 -> V_140 ) ;
return 0 ;
}
