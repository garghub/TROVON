static void
F_1 ( T_1 * V_1 , T_2 * V_2 )
{
T_3 * V_3 ;
T_2 * V_4 ;
if ( V_2 ) {
V_3 = F_2 ( V_2 , V_5 , V_1 , 0 , 2 , L_1 ) ;
V_4 = F_3 ( V_3 , V_6 ) ;
F_4 ( V_4 , V_7 , V_1 , 0 , 2 , V_8 ) ;
}
}
static void
F_5 ( T_1 * V_1 , int V_9 , const char * type , T_2 * V_2 )
{
T_3 * V_10 ;
T_2 * V_11 ;
T_4 V_12 ;
T_2 * V_13 ;
V_10 = F_6 ( V_2 , V_1 , V_9 , 8 , L_2 ,
type ) ;
V_11 = F_3 ( V_10 , V_14 ) ;
V_12 = F_7 ( V_1 , V_9 ) ;
F_4 ( V_11 , V_15 , V_1 , V_9 , 2 , V_8 ) ;
V_9 += 2 ;
switch ( V_12 ) {
case V_16 :
F_4 ( V_11 , V_17 , V_1 , V_9 , 6 , V_18 ) ;
break;
case V_19 :
V_9 += 4 ;
F_4 ( V_11 , V_20 , V_1 , V_9 , 2 , V_21 ) ;
V_13 = F_3 ( V_10 , V_22 ) ;
F_4 ( V_13 , V_23 , V_1 , V_9 , 2 , V_21 ) ;
F_4 ( V_13 , V_24 , V_1 , V_9 , 2 , V_21 ) ;
break;
}
}
static void
F_8 ( T_1 * V_1 , int V_9 , T_5 V_25 ,
T_2 * V_2 )
{
T_6 V_26 ;
T_7 V_27 ;
T_3 * V_28 ;
T_2 * V_29 ;
while ( V_25 != 0 ) {
V_26 = F_9 ( V_1 , V_9 ) ;
V_27 = F_10 ( V_1 , V_9 + 4 ) ;
V_28 = F_6 ( V_2 , V_1 , V_9 , 5 + V_27 , L_3 ,
F_11 ( V_26 , V_30 , L_4 ) ) ;
V_29 = F_3 ( V_28 , V_31 ) ;
F_4 ( V_29 , V_32 , V_1 , V_9 , 4 , V_8 ) ;
F_4 ( V_29 , V_33 , V_1 , V_9 + 4 , 1 , V_8 ) ;
V_9 += 5 + V_27 ;
V_25 -- ;
}
}
static void
F_12 ( T_1 * V_1 , int V_9 , T_2 * V_2 )
{
T_7 V_25 ;
T_7 V_34 ;
F_5 ( V_1 , V_9 , L_5 , V_2 ) ;
V_9 += 8 ;
F_5 ( V_1 , V_9 , L_6 , V_2 ) ;
V_9 += 8 ;
F_4 ( V_2 , V_35 , V_1 , V_9 , 20 , V_18 ) ;
V_9 += 20 ;
F_4 ( V_2 , V_36 , V_1 , V_9 , 1 , V_18 ) ;
V_9 += 1 ;
F_4 ( V_2 , V_37 , V_1 , V_9 , 1 , V_18 ) ;
V_9 += 1 ;
V_25 = F_10 ( V_1 , V_9 ) ;
F_4 ( V_2 , V_38 , V_1 , V_9 , 1 , V_18 ) ;
V_9 += 1 ;
V_34 = F_10 ( V_1 , V_9 ) ;
F_4 ( V_2 , V_39 , V_1 , V_9 , 1 , V_18 ) ;
V_9 += 1 ;
F_4 ( V_2 , V_40 , V_1 , V_9 , 20 , V_18 ) ;
V_9 += 20 ;
if ( V_34 > 32 )
V_34 = 32 ;
if ( V_34 != 0 ) {
F_4 ( V_2 , V_41 , V_1 , V_9 , V_34 , V_18 ) ;
}
V_9 += 32 ;
F_8 ( V_1 , V_9 , V_25 , V_2 ) ;
}
static void
F_13 ( T_1 * V_1 , int V_9 , T_2 * V_2 )
{
T_7 V_25 ;
F_5 ( V_1 , V_9 , L_5 , V_2 ) ;
V_9 += 8 ;
F_5 ( V_1 , V_9 , L_6 , V_2 ) ;
V_9 += 8 ;
F_4 ( V_2 , V_35 , V_1 , V_9 , 20 , V_18 ) ;
V_9 += 20 ;
V_9 += 2 ;
V_25 = F_10 ( V_1 , V_9 ) ;
F_4 ( V_2 , V_42 , V_1 , V_9 , 1 , V_18 ) ;
V_9 += 1 ;
V_9 += 53 ;
F_8 ( V_1 , V_9 , V_25 , V_2 ) ;
}
static void
F_14 ( T_1 * V_1 , int V_9 , T_2 * V_2 )
{
T_7 V_25 ;
F_5 ( V_1 , V_9 , L_5 , V_2 ) ;
V_9 += 8 ;
F_5 ( V_1 , V_9 , L_6 , V_2 ) ;
V_9 += 8 ;
F_4 ( V_2 , V_35 , V_1 , V_9 , 20 , V_18 ) ;
V_9 += 20 ;
V_9 += 2 ;
V_25 = F_10 ( V_1 , V_9 ) ;
F_4 ( V_2 , V_43 , V_1 , V_9 , 1 , V_18 ) ;
V_9 += 1 ;
V_9 += 1 ;
F_4 ( V_2 , V_40 , V_1 , V_9 , 20 , V_18 ) ;
V_9 += 20 ;
V_9 += 32 ;
F_8 ( V_1 , V_9 , V_25 , V_2 ) ;
}
static void
F_15 ( T_1 * V_1 , int V_9 , T_2 * V_2 )
{
T_7 V_25 ;
V_9 += 38 ;
V_25 = F_10 ( V_1 , V_9 ) ;
F_4 ( V_2 , V_44 , V_1 , V_9 , 1 , V_18 ) ;
V_9 += 1 ;
V_9 += 1 ;
F_4 ( V_2 , V_40 , V_1 , V_9 , 20 , V_18 ) ;
V_9 += 20 ;
V_9 += 32 ;
F_8 ( V_1 , V_9 , V_25 , V_2 ) ;
}
static int
F_16 ( T_1 * V_1 , int V_9 , T_2 * V_2 )
{
F_5 ( V_1 , V_9 , L_5 , V_2 ) ;
V_9 += 8 ;
F_5 ( V_1 , V_9 , L_6 , V_2 ) ;
V_9 += 8 ;
F_4 ( V_2 , V_35 , V_1 , V_9 , 20 , V_18 ) ;
V_9 += 20 ;
V_9 += 4 ;
F_4 ( V_2 , V_40 , V_1 , V_9 , 20 , V_18 ) ;
V_9 += 20 ;
V_9 += 32 ;
return V_9 ;
}
static void
F_17 ( T_1 * V_1 , T_8 * V_45 , T_2 * V_2 )
{
T_3 * V_3 ;
T_2 * V_4 = NULL ;
int V_9 = 0 ;
T_3 * V_46 ;
T_2 * V_47 ;
T_4 V_48 ;
F_18 ( V_45 -> V_49 , V_50 , L_7 ) ;
if ( V_2 ) {
V_3 = F_2 ( V_2 , V_5 , V_1 , V_9 , 108 , L_1 ) ;
V_4 = F_3 ( V_3 , V_6 ) ;
F_4 ( V_4 , V_51 , V_1 , V_9 , 2 , V_8 ) ;
}
V_9 += 2 ;
if ( V_2 ) {
F_4 ( V_4 , V_52 , V_1 , V_9 , 1 , V_8 ) ;
}
V_9 += 1 ;
if ( V_2 ) {
F_4 ( V_4 , V_53 , V_1 , V_9 , 1 , V_8 ) ;
}
V_9 += 1 ;
V_48 = F_7 ( V_1 , V_9 ) ;
F_19 ( V_45 -> V_49 , V_50 , L_8 ,
F_11 ( V_48 , V_54 ,
L_9 ) ) ;
if ( V_2 ) {
F_4 ( V_4 , V_55 , V_1 , V_9 , 2 , V_8 ) ;
}
V_9 += 2 ;
if ( V_48 == V_56 || V_48 == V_57 ) {
return;
}
if ( V_2 ) {
if ( V_48 & 0x0100 ) {
F_4 ( V_4 , V_58 , V_1 , V_9 , 2 , V_8 ) ;
}
V_9 += 2 ;
F_4 ( V_4 , V_59 , V_1 , V_9 , 4 , V_8 ) ;
V_9 += 4 ;
F_4 ( V_4 , V_60 , V_1 , V_9 , 2 , V_8 ) ;
V_9 += 2 ;
V_46 = F_4 ( V_4 , V_61 , V_1 , V_9 , 2 , V_8 ) ;
V_47 = F_3 ( V_46 , V_62 ) ;
switch ( V_48 ) {
case V_63 :
case V_64 :
F_4 ( V_47 , V_65 , V_1 , V_9 , 2 , V_8 ) ;
V_9 += 2 ;
F_12 ( V_1 , V_9 , V_4 ) ;
break;
case V_66 :
case V_67 :
F_4 ( V_47 , V_65 , V_1 , V_9 , 2 , V_8 ) ;
if ( V_48 == V_66 ) {
F_4 ( V_47 , V_68 , V_1 , V_9 , 2 , V_8 ) ;
} else {
F_4 ( V_47 , V_69 , V_1 , V_9 , 2 , V_8 ) ;
}
F_4 ( V_47 , V_70 , V_1 , V_9 , 2 , V_8 ) ;
F_4 ( V_47 , V_71 , V_1 , V_9 , 2 , V_8 ) ;
V_9 += 2 ;
F_12 ( V_1 , V_9 , V_4 ) ;
break;
case V_72 :
case V_73 :
case V_74 :
case V_75 :
V_9 += 2 ;
F_13 ( V_1 , V_9 , V_4 ) ;
break;
case V_76 :
case V_77 :
case V_78 :
if ( V_48 != V_78 ) {
F_4 ( V_47 , V_79 , V_1 , V_9 , 2 , V_8 ) ;
}
V_9 += 2 ;
F_14 ( V_1 , V_9 , V_4 ) ;
break;
case V_80 :
F_4 ( V_47 , V_81 , V_1 , V_9 , 2 , V_8 ) ;
break;
case V_82 :
case V_83 :
V_9 += 2 ;
F_15 ( V_1 , V_9 , V_4 ) ;
break;
case V_84 :
case V_85 :
V_9 += 2 ;
F_16 ( V_1 , V_9 , V_4 ) ;
break;
}
}
}
static void
F_20 ( const union V_86 * V_87 , const T_9 * V_88 ,
int V_89 , T_10 * V_90 )
{
switch ( V_87 -> V_91 . V_92 ) {
case V_93 :
case V_94 :
F_21 ( V_88 , 2 , V_89 , V_90 ) ;
break;
case V_95 :
case V_96 :
F_22 ( V_88 , 2 , V_89 , V_90 ) ;
break;
default:
V_90 -> V_97 ++ ;
break;
}
}
static void
F_23 ( T_1 * V_1 , T_8 * V_45 , T_2 * V_2 )
{
T_1 * V_98 ;
T_1 * V_99 ;
F_18 ( V_45 -> V_49 , V_100 , L_1 ) ;
switch ( V_45 -> V_87 -> V_91 . V_92 ) {
case V_101 :
F_17 ( V_1 , V_45 , V_2 ) ;
break;
case V_93 :
case V_94 :
F_18 ( V_45 -> V_49 , V_50 , L_10 ) ;
F_1 ( V_1 , V_2 ) ;
V_99 = F_24 ( V_1 , 2 ) ;
F_25 ( V_102 , V_99 , V_45 , V_2 ) ;
break;
case V_95 :
case V_96 :
F_18 ( V_45 -> V_49 , V_50 , L_11 ) ;
F_1 ( V_1 , V_2 ) ;
V_99 = F_24 ( V_1 , 2 ) ;
F_25 ( V_103 , V_99 , V_45 , V_2 ) ;
break;
default:
F_18 ( V_45 -> V_49 , V_50 , L_12 ) ;
V_98 = F_24 ( V_1 , 0 ) ;
F_25 ( V_104 , V_98 , V_45 , V_2 ) ;
break;
}
}
static void
F_26 ( T_1 * V_1 , T_8 * V_45 , T_2 * V_2 )
{
F_27 ( V_1 , 0 , V_45 , V_2 , V_105 , V_106 , FALSE ) ;
}
void
F_28 ( const union V_86 * V_87 , const T_9 * V_88 ,
int V_89 , T_10 * V_90 )
{
if ( V_87 -> V_91 . V_107 == V_108 ) {
switch ( V_87 -> V_91 . type ) {
case V_109 :
F_29 ( V_88 , 0 , V_89 , V_90 ) ;
break;
case V_110 :
F_20 ( V_87 , V_88 , V_89 , V_90 ) ;
break;
default:
V_90 -> V_97 ++ ;
break;
}
} else
V_90 -> V_97 ++ ;
}
static T_6
F_30 ( T_6 V_111 , const T_7 * V_112 , int V_113 )
{
register int V_114 , V_115 ;
for ( V_115 = 0 ; V_115 < V_113 ; V_115 ++ ) {
V_114 = ( ( int ) ( V_111 >> 24 ) ^ * V_112 ++ ) & 0xff ;
V_111 = ( V_111 << 8 ) ^ V_116 [ V_114 ] ;
}
return V_111 ;
}
static void
F_31 ( T_1 * V_1 , T_8 * V_45 , T_2 * V_2 ,
T_3 * V_117 ,
T_2 * V_118 , T_11 V_119 )
{
T_5 V_120 , V_121 ;
T_4 V_122 ;
int V_123 ;
T_1 * V_98 ;
T_6 V_124 ;
T_6 V_125 ;
T_12 type ;
T_11 V_126 = ( NULL != V_45 -> V_127 ) ;
if ( V_45 -> V_87 -> V_91 . V_107 == V_108 ) {
F_32 ( V_118 , V_128 , V_1 , 0 , 0 , V_45 -> V_87 -> V_91 . type ) ;
switch ( V_45 -> V_87 -> V_91 . type ) {
case V_129 :
F_32 ( V_118 , V_130 , V_1 , 0 , 0 , V_45 -> V_87 -> V_91 . V_92 ) ;
break;
case V_110 :
F_32 ( V_118 , V_131 , V_1 , 0 , 0 , V_45 -> V_87 -> V_91 . V_92 ) ;
break;
case V_132 :
F_32 ( V_118 , V_133 , V_1 , 0 , 0 , V_45 -> V_87 -> V_91 . V_92 ) ;
break;
}
}
if ( ! V_126 ) {
F_32 ( V_118 , V_134 , V_1 , 0 , 0 ,
V_45 -> V_87 -> V_91 . V_135 ) ;
F_32 ( V_118 , V_136 , V_1 , 0 , 0 ,
V_45 -> V_87 -> V_91 . V_137 ) ;
F_19 ( V_45 -> V_49 , V_50 , L_13 ,
V_45 -> V_87 -> V_91 . V_135 ,
V_45 -> V_87 -> V_91 . V_137 ) ;
}
V_98 = V_1 ;
if ( V_119 ) {
if ( V_45 -> V_87 -> V_91 . V_138 != 0 ) {
if ( V_2 ) {
F_32 ( V_118 , V_139 , V_1 , 0 , 0 , V_45 -> V_87 -> V_91 . V_138 ) ;
F_32 ( V_118 , V_140 , V_1 , 0 , 0 , V_45 -> V_87 -> V_91 . V_141 >> 8 ) ;
F_32 ( V_118 , V_142 , V_1 , 0 , 0 , V_45 -> V_87 -> V_91 . V_141 & 0xFF ) ;
F_32 ( V_118 , V_143 , V_1 , 0 , 0 , V_45 -> V_87 -> V_91 . V_144 ) ;
F_32 ( V_118 , V_145 , V_1 , 0 , 0 , V_45 -> V_87 -> V_91 . V_146 ) ;
}
}
} else {
V_120 = F_33 ( V_1 ) ;
V_121 = F_34 ( V_1 ) ;
if ( ( V_121 % 48 ) == 0 ) {
F_32 ( V_118 , V_139 , V_1 , 0 , 0 , V_121 / 48 ) ;
}
if ( ( V_45 -> V_87 -> V_91 . V_107 == V_108 ||
V_45 -> V_87 -> V_91 . V_107 == V_147 ) &&
V_120 >= V_121 ) {
V_122 = F_7 ( V_1 , V_120 - 6 ) ;
if ( V_122 > 0 && V_122 <= V_120 - 8 ) {
V_123 = V_120 - V_122 - 8 ;
if ( V_123 <= 47 ) {
if ( V_2 ) {
T_3 * V_3 ;
if ( V_123 > 0 ) {
F_6 ( V_118 , V_1 , V_122 , V_123 ,
L_14 ) ;
}
F_4 ( V_118 , V_140 , V_1 , V_120 - 8 , 1 , V_8 ) ;
F_4 ( V_118 , V_142 , V_1 , V_120 - 7 , 1 , V_8 ) ;
F_4 ( V_118 , V_143 , V_1 , V_120 - 6 , 2 , V_8 ) ;
V_124 = F_9 ( V_1 , V_120 - 4 ) ;
V_125 = F_30 ( 0xFFFFFFFF , F_35 ( V_1 , 0 , V_120 ) ,
V_120 ) ;
V_3 = F_32 ( V_118 , V_145 , V_1 , V_120 - 4 , 4 , V_124 ) ;
F_36 ( V_3 , ( V_125 == 0xC704DD7B ) ? L_15 : L_16 ) ;
}
V_98 = F_37 ( V_1 , 0 , V_122 , V_122 ) ;
}
}
}
}
switch ( V_45 -> V_87 -> V_91 . V_107 ) {
case V_147 :
F_25 ( V_148 , V_98 , V_45 , V_2 ) ;
break;
case V_108 :
switch ( V_45 -> V_87 -> V_91 . type ) {
case V_149 :
F_25 ( V_148 , V_98 , V_45 , V_2 ) ;
break;
case V_150 :
F_25 ( V_151 , V_98 , V_45 , V_2 ) ;
break;
case V_109 :
F_25 ( V_152 , V_98 , V_45 , V_2 ) ;
break;
case V_110 :
F_25 ( V_153 , V_98 , V_45 , V_2 ) ;
break;
case V_154 :
F_25 ( V_155 , V_98 , V_45 , V_2 ) ;
break;
case V_156 :
F_25 ( V_157 , V_98 , V_45 , V_2 ) ;
break;
default:
{
T_11 V_158 = FALSE ;
if ( F_33 ( V_98 ) > 7 )
{
T_7 V_159 [ 8 ] ;
F_38 ( V_98 , V_159 , 0 , sizeof( V_159 ) ) ;
V_158 = TRUE ;
if ( V_159 [ 0 ] == 0xaa
&& V_159 [ 1 ] == 0xaa
&& V_159 [ 2 ] == 0x03 )
{
F_25 ( V_152 , V_98 , V_45 , V_2 ) ;
}
else if ( ( F_39 ( V_159 ) & 0xff ) == V_160 )
{
F_25 ( V_161 , V_98 , V_45 , V_2 ) ;
}
else if ( F_39 ( V_159 ) == 0x00 )
{
F_6 ( V_2 , V_1 , 0 , 2 , L_17 ) ;
V_98 = F_24 ( V_1 , 2 ) ;
F_25 ( V_162 , V_98 , V_45 , V_2 ) ;
}
else if ( V_159 [ 2 ] == 0x03 &&
( ( V_159 [ 3 ] == 0xcc ||
V_159 [ 3 ] == 0x8e ) ||
( V_159 [ 3 ] == 0x00 &&
V_159 [ 4 ] == 0x80 ) ) )
{
F_25 ( V_151 , V_98 , V_45 , V_2 ) ;
}
else if ( V_159 [ 4 ] == 0x03 &&
( ( V_159 [ 5 ] == 0xcc ||
V_159 [ 5 ] == 0x8e ) ||
( V_159 [ 5 ] == 0x00 &&
V_159 [ 6 ] == 0x80 ) ) )
{
F_25 ( V_151 , V_98 , V_45 , V_2 ) ;
}
else if ( ( ( V_159 [ 0 ] & 0xf0 ) == 0x40 ) ||
( ( V_159 [ 0 ] & 0xf0 ) == 0x60 ) )
{
F_25 ( V_163 , V_98 , V_45 , V_2 ) ;
}
else
{
V_158 = FALSE ;
}
}
if ( V_2 && ! V_158 ) {
F_25 ( V_104 , V_98 , V_45 , V_2 ) ;
}
}
break;
}
break;
case V_164 :
F_32 ( V_118 , V_165 , V_1 , 0 , 0 ,
V_45 -> V_87 -> V_91 . V_166 ) ;
F_36 ( V_117 , L_18 ,
V_45 -> V_87 -> V_91 . V_135 ,
V_45 -> V_87 -> V_91 . V_137 ,
V_45 -> V_87 -> V_91 . V_166 ) ;
if ( V_45 -> V_87 -> V_91 . V_167 & V_168 ) {
V_98 = V_1 ;
} else {
V_98 = F_24 ( V_1 , 4 ) ;
}
type = V_45 -> V_87 -> V_91 . type ;
if ( type == V_169 ) {
type = V_170 ;
}
switch ( type ) {
case V_171 :
F_25 ( V_172 , V_98 , V_45 , V_2 ) ;
break;
default:
F_25 ( V_104 , V_98 , V_45 , V_2 ) ;
break;
}
break;
default:
F_25 ( V_104 , V_98 , V_45 , V_2 ) ;
break;
}
}
static int
F_40 ( const T_7 * V_173 )
{
register T_7 V_174 ;
register int V_114 , V_175 ;
V_174 = 0 ;
for ( V_114 = 0 ; V_114 < 4 ; V_114 ++ )
V_174 = V_176 [ V_174 ^ V_173 [ V_114 ] ] ;
V_174 ^= V_173 [ 4 ] ^ V_177 ;
V_175 = V_178 [ V_174 ] ;
if ( V_175 < 0 )
return V_179 ;
else if ( V_175 < 40 )
return V_175 ;
else
return V_180 ;
}
static T_4
F_41 ( T_4 V_181 , const T_7 * V_112 ,
int V_113 )
{
register int V_114 ;
for ( V_114 = 0 ; V_114 < V_113 ; V_114 ++ ) {
V_181 = ( ( V_181 << 8 ) & 0x3ff )
^ V_182 [ ( V_181 >> 2 ) & 0xff ]
^ * V_112 ++ ;
}
return V_181 ;
}
T_11
F_42 ( const T_4 V_137 , const T_7 V_183 )
{
return ( ( ( V_137 == 3 || V_137 == 4 ) && ( ( V_183 & 0x5 ) == 0 ) )
|| ( ( V_183 & 0x6 ) == 0x4 ) ) ;
}
static void
F_43 ( T_1 * V_1 , T_8 * V_45 , T_2 * V_2 ,
T_2 * V_118 , T_5 V_107 , T_11 V_184 ,
T_11 V_185 )
{
int V_9 ;
T_2 * V_186 ;
T_3 * V_3 ;
T_7 V_159 , V_183 ;
int V_187 ;
T_4 V_135 , V_137 , V_188 , V_189 ;
T_12 V_120 ;
T_1 * V_98 ;
const T_13 * V_190 = ( const T_13 * ) V_45 -> V_127 ;
if ( NULL == V_190 ) {
if ( ! V_184 ) {
V_159 = F_10 ( V_1 , 0 ) ;
F_6 ( V_118 , V_1 , 0 , 1 , L_19 , V_159 >> 4 ) ;
V_135 = ( V_159 & 0xF ) << 4 ;
V_159 = F_10 ( V_1 , 1 ) ;
V_135 |= V_159 >> 4 ;
F_32 ( V_118 , V_134 , V_1 , 0 , 2 , V_135 ) ;
} else {
V_159 = F_10 ( V_1 , 0 ) ;
V_135 = V_159 << 4 ;
V_159 = F_10 ( V_1 , 1 ) ;
V_135 |= ( V_159 & 0xF0 ) >> 4 ;
F_32 ( V_118 , V_134 , V_1 , 0 , 2 , V_135 ) ;
}
V_137 = ( V_159 & 0x0F ) << 12 ;
V_159 = F_10 ( V_1 , 2 ) ;
V_137 |= V_159 << 4 ;
V_159 = F_10 ( V_1 , 3 ) ;
V_137 |= V_159 >> 4 ;
F_32 ( V_118 , V_136 , V_1 , 1 , 3 , V_137 ) ;
V_183 = ( V_159 >> 1 ) & 0x7 ;
F_4 ( V_118 , V_191 , V_1 , 3 , 1 , V_8 ) ;
F_4 ( V_118 , V_192 , V_1 , 3 , 1 , V_8 ) ;
if ( ! V_185 ) {
V_3 = F_4 ( V_118 , V_193 , V_1 , 4 , 1 , V_8 ) ;
V_187 = F_40 ( F_35 ( V_1 , 0 , 5 ) ) ;
if ( V_187 == V_179 )
F_36 ( V_3 , L_15 ) ;
else if ( V_187 == V_180 )
F_36 ( V_3 , L_20 ) ;
else
F_36 ( V_3 , L_21 , V_187 ) ;
V_9 = 5 ;
} else {
V_9 = 4 ;
}
}
else
{
V_9 = 0 ;
V_190 = ( const T_13 * ) V_45 -> V_127 ;
V_137 = V_190 -> V_137 ;
V_183 = V_190 -> V_194 ;
}
if ( V_107 == V_195 || V_107 == V_196 ) {
if ( F_42 ( V_137 , V_183 ) ) {
V_107 = V_197 ;
}
}
switch ( V_107 ) {
case V_198 :
F_18 ( V_45 -> V_49 , V_100 , L_22 ) ;
F_44 ( V_45 -> V_49 , V_50 ) ;
V_3 = F_4 ( V_2 , V_199 , V_1 , V_9 , - 1 , V_18 ) ;
V_186 = F_3 ( V_3 , V_200 ) ;
V_159 = F_10 ( V_1 , V_9 ) ;
F_4 ( V_186 , V_201 , V_1 , V_9 , 1 , V_8 ) ;
F_4 ( V_186 , V_202 , V_1 , V_9 , 1 , V_8 ) ;
F_45 ( V_45 -> V_49 , V_50 , L_23 ,
( V_159 >> 4 ) & 0x7 ) ;
F_4 ( V_186 , V_203 , V_1 , V_9 , 1 , V_8 ) ;
F_4 ( V_186 , V_204 , V_1 , V_9 , 1 , V_8 ) ;
V_9 ++ ;
F_4 ( V_186 , V_205 , V_1 , V_9 , 47 , V_18 ) ;
break;
case V_206 :
F_18 ( V_45 -> V_49 , V_100 , L_24 ) ;
F_44 ( V_45 -> V_49 , V_50 ) ;
V_3 = F_4 ( V_2 , V_207 , V_1 , V_9 , - 1 , V_18 ) ;
V_186 = F_3 ( V_3 , V_208 ) ;
V_188 = F_7 ( V_1 , V_9 ) ;
F_45 ( V_45 -> V_49 , V_50 , L_25 ,
F_11 ( V_188 >> 14 , V_209 , L_26 ) ,
( V_188 >> 10 ) & 0xF ) ;
F_4 ( V_186 , V_210 , V_1 , V_9 , 2 , V_8 ) ;
F_4 ( V_186 , V_211 , V_1 , V_9 , 2 , V_8 ) ;
F_4 ( V_186 , V_212 , V_1 , V_9 , 2 , V_8 ) ;
V_120 = F_46 ( V_1 , V_9 ) ;
V_189 = F_41 ( 0 , F_35 ( V_1 , V_9 , V_120 ) ,
V_120 ) ;
V_9 += 2 ;
F_4 ( V_186 , V_213 , V_1 , V_9 , 44 , V_18 ) ;
V_9 += 44 ;
F_4 ( V_186 , V_214 , V_1 , V_9 , 2 , V_8 ) ;
V_3 = F_4 ( V_186 , V_215 , V_1 , V_9 , 2 , V_8 ) ;
F_36 ( V_3 , L_27 , ( V_189 == 0 ) ? L_15 : L_16 ) ;
break;
case V_197 :
if ( NULL == V_190 || V_190 -> V_216 )
{
F_18 ( V_45 -> V_49 , V_100 , L_28 ) ;
F_44 ( V_45 -> V_49 , V_50 ) ;
}
V_3 = F_4 ( V_2 , V_217 , V_1 , V_9 , - 1 , V_18 ) ;
V_186 = F_3 ( V_3 , V_218 ) ;
V_159 = F_10 ( V_1 , V_9 ) ;
if ( NULL == V_190 || V_190 -> V_216 )
{
F_45 ( V_45 -> V_49 , V_50 , L_29 ,
F_11 ( V_159 >> 4 , V_219 , L_26 ) ) ;
}
F_4 ( V_186 , V_220 , V_1 , V_9 , 1 , V_8 ) ;
switch ( V_159 >> 4 ) {
case V_221 :
F_4 ( V_186 , V_222 , V_1 , V_9 , 1 , V_8 ) ;
break;
case V_223 :
F_4 ( V_186 , V_224 , V_1 , V_9 , 1 , V_8 ) ;
break;
case V_225 :
F_4 ( V_186 , V_226 , V_1 , V_9 , 1 , V_8 ) ;
break;
default:
F_4 ( V_186 , V_227 , V_1 , V_9 , 1 , V_8 ) ;
break;
}
V_120 = F_46 ( V_1 , V_9 ) ;
V_189 = F_41 ( 0 , F_35 ( V_1 , V_9 , V_120 ) ,
V_120 ) ;
V_9 += 1 ;
F_4 ( V_186 , V_228 , V_1 , V_9 , 45 , V_18 ) ;
V_9 += 45 ;
V_3 = F_4 ( V_186 , V_229 , V_1 , V_9 , 2 , V_8 ) ;
F_36 ( V_3 , L_27 , ( V_189 == 0 ) ? L_15 : L_16 ) ;
break;
default:
V_98 = F_24 ( V_1 , V_9 ) ;
F_25 ( V_104 , V_98 , V_45 , V_2 ) ;
break;
}
}
static void
F_47 ( T_1 * V_1 , T_8 * V_45 , T_2 * V_2 ,
T_11 V_119 )
{
T_2 * V_118 = NULL ;
T_3 * V_117 = NULL ;
T_11 V_126 = ( NULL != V_45 -> V_127 ) ;
if ( V_45 -> V_87 -> V_91 . V_107 == V_108 &&
V_45 -> V_87 -> V_91 . type == V_110 &&
V_230 ) {
V_45 -> V_87 -> V_91 . V_107 = V_147 ;
}
F_18 ( V_45 -> V_49 , V_100 , L_30 ) ;
if ( ! V_126 ) {
switch ( V_45 -> V_87 -> V_91 . V_231 ) {
case 0 :
F_18 ( V_45 -> V_49 , V_232 , L_31 ) ;
F_18 ( V_45 -> V_49 , V_233 , L_32 ) ;
break;
case 1 :
F_18 ( V_45 -> V_49 , V_232 , L_32 ) ;
F_18 ( V_45 -> V_49 , V_233 , L_31 ) ;
break;
}
}
if ( V_45 -> V_87 -> V_91 . V_107 == V_108 ) {
F_45 ( V_45 -> V_49 , V_50 , L_33 ,
F_11 ( V_45 -> V_87 -> V_91 . type , V_234 ,
L_34 ) ) ;
} else {
F_48 ( V_45 -> V_49 , V_50 ,
F_11 ( V_45 -> V_87 -> V_91 . V_107 , V_235 ,
L_35 ) ) ;
}
if ( V_2 ) {
V_117 = F_4 ( V_2 , V_236 , V_1 , 0 , - 1 , V_18 ) ;
V_118 = F_3 ( V_117 , V_237 ) ;
if ( ! V_126 ) {
F_32 ( V_118 , V_238 , V_1 , 0 , 0 , V_45 -> V_87 -> V_91 . V_231 ) ;
}
F_49 ( V_118 , V_239 , V_1 , 0 , 0 ,
V_45 -> V_87 -> V_91 . V_107 ,
L_29 ,
F_11 ( V_45 -> V_87 -> V_91 . V_107 , V_235 ,
L_35 ) ) ;
}
if ( V_45 -> V_87 -> V_91 . V_167 & V_240 ) {
if ( V_45 -> V_87 -> V_91 . V_167 & V_241 ) {
F_50 ( V_117 , 4 ) ;
} else {
F_50 ( V_117 , 5 ) ;
}
F_43 ( V_1 , V_45 , V_2 , V_118 ,
V_45 -> V_87 -> V_91 . V_107 , FALSE ,
V_45 -> V_87 -> V_91 . V_167 & V_241 ) ;
} else {
F_31 ( V_1 , V_45 , V_2 , V_118 , V_117 , V_119 ) ;
}
}
static void
F_51 ( T_1 * V_1 , T_8 * V_45 , T_2 * V_2 )
{
F_47 ( V_1 , V_45 , V_2 , TRUE ) ;
}
static void
F_52 ( T_1 * V_1 , T_8 * V_45 , T_2 * V_2 )
{
F_47 ( V_1 , V_45 , V_2 , FALSE ) ;
}
static void
F_53 ( T_1 * V_1 , T_8 * V_45 , T_2 * V_2 )
{
T_2 * V_118 = NULL ;
T_3 * V_117 = NULL ;
T_11 V_126 = ( NULL != V_45 -> V_127 ) ;
F_18 ( V_45 -> V_49 , V_100 , L_30 ) ;
if ( ! V_126 ) {
if ( V_2 ) {
V_117 = F_2 ( V_2 , V_236 , V_1 , 0 , 0 , L_30 ) ;
V_118 = F_3 ( V_117 , V_237 ) ;
}
}
F_43 ( V_1 , V_45 , V_2 , V_118 , V_197 , FALSE , FALSE ) ;
}
void
F_54 ( void )
{
static T_14 V_242 [] = {
{ & V_239 ,
{ L_36 , L_37 , V_243 , V_244 , F_55 ( V_235 ) , 0x0 ,
NULL , V_245 } } ,
{ & V_134 ,
{ L_38 , L_39 , V_243 , V_244 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_136 ,
{ L_40 , L_41 , V_246 , V_244 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_165 ,
{ L_42 , L_43 , V_243 , V_244 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_7 ,
{ L_44 , L_45 , V_246 , V_247 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_15 ,
{ L_46 , L_47 , V_246 , V_247 , F_55 ( V_248 ) , 0x0 ,
NULL , V_245 } } ,
{ & V_17 ,
{ L_48 , L_49 , V_249 , V_250 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_32 ,
{ L_50 , L_51 , V_251 , V_247 , F_55 ( V_30 ) , 0x0 ,
NULL , V_245 } } ,
{ & V_33 ,
{ L_52 , L_53 , V_243 , V_244 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_20 ,
{ L_54 , L_55 , V_246 , V_247 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_23 ,
{ L_56 , L_57 , V_246 , V_244 , NULL , 0xFFF0 ,
NULL , V_245 } } ,
{ & V_24 ,
{ L_58 , L_59 , V_246 , V_244 , NULL , 0x000F ,
NULL , V_245 } } ,
{ & V_35 ,
{ L_60 , L_61 , V_252 , V_250 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_40 ,
{ L_62 , L_63 , V_252 , V_250 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_36 ,
{ L_64 , L_65 , V_243 , V_247 , F_55 ( V_253 ) , 0x0 ,
NULL , V_245 } } ,
{ & V_37 ,
{ L_66 , L_67 , V_243 , V_247 , F_55 ( V_254 ) , 0x0 ,
NULL , V_245 } } ,
{ & V_38 ,
{ L_68 , L_69 , V_243 , V_244 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_39 ,
{ L_70 , L_71 , V_243 , V_244 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_42 ,
{ L_68 , L_72 , V_243 , V_244 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_43 ,
{ L_68 , L_73 , V_243 , V_244 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_44 ,
{ L_68 , L_74 , V_243 , V_244 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_41 ,
{ L_75 , L_76 , V_252 , V_250 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_51 ,
{ L_77 , L_78 , V_246 , V_247 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_52 ,
{ L_79 , L_80 , V_243 , V_247 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_53 ,
{ L_81 , L_82 , V_243 , V_247 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_55 ,
{ L_83 , L_84 , V_246 , V_247 , F_55 ( V_54 ) , 0x0 ,
NULL , V_245 } } ,
{ & V_58 ,
{ L_85 , L_86 , V_246 , V_247 , F_55 ( V_255 ) , 0x0 ,
NULL , V_245 } } ,
{ & V_59 ,
{ L_87 , L_88 , V_251 , V_247 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_60 ,
{ L_89 , L_90 , V_246 , V_247 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_61 ,
{ L_91 , L_92 , V_246 , V_247 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_65 ,
{ L_93 , L_94 , V_256 , 16 , F_56 ( & V_257 ) , 0x0002 ,
NULL , V_245 } } ,
{ & V_68 ,
{ L_95 , L_96 , V_256 , 16 , F_56 ( & V_257 ) , 0x0004 ,
NULL , V_245 } } ,
{ & V_69 ,
{ L_97 , L_98 , V_256 , 16 , F_56 ( & V_257 ) , 0x0008 ,
NULL , V_245 } } ,
{ & V_70 ,
{ L_99 , L_100 , V_256 , 16 , F_56 ( & V_257 ) , 0x0080 ,
NULL , V_245 } } ,
{ & V_71 ,
{ L_101 , L_102 , V_256 , 16 , F_56 ( & V_257 ) , 0x0200 ,
NULL , V_245 } } ,
{ & V_79 ,
{ L_103 , L_104 , V_256 , 16 , F_56 ( & V_257 ) , 0x0001 ,
NULL , V_245 } } ,
{ & V_81 ,
{ L_105 , L_106 , V_256 , 16 , F_56 ( & V_258 ) , 0x0100 ,
NULL , V_245 } } ,
{ & V_128 ,
{ L_107 , L_108 , V_243 , V_244 , F_55 ( V_234 ) , 0x0 ,
NULL , V_245 } } ,
{ & V_130 ,
{ L_109 , L_110 , V_243 , V_244 , F_55 ( V_259 ) , 0x0 ,
NULL , V_245 } } ,
{ & V_131 ,
{ L_111 , L_112 , V_243 , V_244 , F_55 ( V_260 ) , 0x0 ,
NULL , V_245 } } ,
{ & V_133 ,
{ L_113 , L_114 , V_243 , V_244 , F_55 ( V_261 ) , 0x0 ,
NULL , V_245 } } ,
{ & V_139 ,
{ L_115 , L_116 , V_246 , V_244 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_140 ,
{ L_117 , L_118 , V_243 , V_247 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_142 ,
{ L_119 , L_120 , V_243 , V_247 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_143 ,
{ L_121 , L_122 , V_246 , V_244 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_145 ,
{ L_123 , L_124 , V_251 , V_247 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_191 ,
{ L_125 , L_126 , V_243 , V_244 , NULL , 0x0E ,
NULL , V_245 } } ,
{ & V_192 ,
{ L_127 , L_128 , V_256 , 8 , F_56 ( & V_262 ) , 0x01 ,
NULL , V_245 } } ,
{ & V_193 ,
{ L_129 , L_130 , V_243 , V_247 , NULL , 0 ,
NULL , V_245 } } ,
{ & V_238 ,
{ L_131 , L_132 , V_246 , V_244 , F_55 ( V_263 ) , 0 ,
NULL , V_245 } } ,
{ & V_201 ,
{ L_133 , L_134 , V_243 , V_244 , NULL , 0x80 ,
NULL , V_245 } } ,
{ & V_202 ,
{ L_135 , L_136 , V_243 , V_244 , NULL , 0x70 ,
NULL , V_245 } } ,
{ & V_203 ,
{ L_137 , L_138 , V_243 , V_244 , NULL , 0x08 ,
NULL , V_245 } } ,
{ & V_204 ,
{ L_139 , L_140 , V_243 , V_244 , NULL , 0x07 ,
NULL , V_245 } } ,
{ & V_205 ,
{ L_141 , L_142 , V_252 , V_250 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_210 ,
{ L_143 , L_144 , V_246 , V_244 , F_55 ( V_209 ) , 0xC000 ,
NULL , V_245 } } ,
{ & V_211 ,
{ L_145 , L_146 , V_246 , V_244 , NULL , 0x3C00 ,
NULL , V_245 } } ,
{ & V_212 ,
{ L_147 , L_148 , V_246 , V_244 , NULL , 0x03FF ,
NULL , V_245 } } ,
{ & V_213 ,
{ L_149 , L_150 , V_252 , V_250 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_214 ,
{ L_151 , L_152 , V_246 , V_244 , F_55 ( V_209 ) , 0xFC00 ,
NULL , V_245 } } ,
{ & V_215 ,
{ L_137 , L_153 , V_246 , V_244 , NULL , 0x03FF ,
NULL , V_245 } } ,
{ & V_220 ,
{ L_154 , L_155 , V_243 , V_244 , F_55 ( V_219 ) , 0xF0 ,
NULL , V_245 } } ,
{ & V_222 ,
{ L_156 , L_157 , V_243 , V_244 , F_55 ( V_264 ) , 0x0F ,
NULL , V_245 } } ,
{ & V_224 ,
{ L_156 , L_158 , V_243 , V_244 , F_55 ( V_265 ) , 0x0F ,
NULL , V_245 } } ,
{ & V_226 ,
{ L_156 , L_159 , V_243 , V_244 , F_55 ( V_266 ) , 0x0F ,
NULL , V_245 } } ,
{ & V_227 ,
{ L_156 , L_160 , V_243 , V_244 , NULL , 0x0F ,
NULL , V_245 } } ,
{ & V_228 ,
{ L_161 , L_162 , V_252 , V_250 , NULL , 0x0 ,
NULL , V_245 } } ,
{ & V_229 ,
{ L_163 , L_164 , V_246 , V_247 , NULL , 0x3FF ,
NULL , V_245 } } ,
} ;
static T_12 * V_267 [] = {
& V_237 ,
& V_106 ,
& V_200 ,
& V_208 ,
& V_218 ,
& V_6 ,
& V_14 ,
& V_22 ,
& V_62 ,
& V_31 ,
} ;
static const T_15 V_268 [] = {
{ L_165 , L_166 , V_169 } ,
{ L_167 , L_168 , V_171 } ,
{ NULL , NULL , 0 }
} ;
T_16 * V_269 ;
V_236 = F_57 ( L_169 , L_30 , L_170 ) ;
V_199 = F_57 ( L_171 , L_22 , L_172 ) ;
V_207 = F_57 ( L_173 , L_24 , L_174 ) ;
V_217 = F_57 ( L_175 , L_28 , L_176 ) ;
F_58 ( V_236 , V_242 , F_59 ( V_242 ) ) ;
F_60 ( V_267 , F_59 ( V_267 ) ) ;
V_105 = F_57 ( L_177 , L_177 , L_178 ) ;
F_61 ( L_178 , F_26 , V_105 ) ;
V_5 = F_57 ( L_179 ,
L_1 , L_180 ) ;
F_61 ( L_180 , F_23 , V_5 ) ;
V_270 = F_61 ( L_181 , F_51 , V_236 ) ;
V_271 = F_61 ( L_182 , F_52 , V_236 ) ;
F_61 ( L_183 , F_53 , V_217 ) ;
V_269 = F_62 ( V_236 , NULL ) ;
F_63 ( V_269 , L_184 , L_185 ,
L_186 ,
& V_230 ) ;
F_64 ( V_269 , L_187 ,
L_188 ,
L_189 ,
& V_170 , V_268 , FALSE ) ;
}
void
F_65 ( void )
{
V_102 = F_66 ( L_190 ) ;
V_103 = F_66 ( L_191 ) ;
V_151 = F_66 ( L_192 ) ;
V_152 = F_66 ( L_193 ) ;
V_148 = F_66 ( L_194 ) ;
V_153 = F_66 ( L_180 ) ;
V_155 = F_66 ( L_178 ) ;
V_161 = F_66 ( L_195 ) ;
V_162 = F_66 ( L_196 ) ;
V_163 = F_66 ( L_197 ) ;
V_104 = F_66 ( L_198 ) ;
V_172 = F_66 ( L_199 ) ;
V_157 = F_66 ( L_200 ) ;
F_67 ( L_201 , V_272 , V_270 ) ;
F_67 ( L_201 , V_273 ,
V_271 ) ;
}
