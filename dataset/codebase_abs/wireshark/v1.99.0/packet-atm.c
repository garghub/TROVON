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
V_11 = F_6 ( V_2 , V_1 , V_9 , 8 ,
V_14 , NULL , L_2 , type ) ;
V_12 = F_7 ( V_1 , V_9 ) ;
F_4 ( V_11 , V_15 , V_1 , V_9 , 2 , V_8 ) ;
V_9 += 2 ;
switch ( V_12 ) {
case V_16 :
F_4 ( V_11 , V_17 , V_1 , V_9 , 6 , V_18 ) ;
break;
case V_19 :
V_9 += 4 ;
V_10 = F_4 ( V_11 , V_20 , V_1 , V_9 , 2 , V_21 ) ;
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
T_2 * V_28 ;
while ( V_25 != 0 ) {
V_26 = F_9 ( V_1 , V_9 ) ;
V_27 = F_10 ( V_1 , V_9 + 4 ) ;
V_28 = F_6 ( V_2 , V_1 , V_9 , 5 + V_27 , V_29 , NULL ,
L_3 , F_11 ( V_26 , V_30 , L_4 ) ) ;
F_4 ( V_28 , V_31 , V_1 , V_9 , 4 , V_8 ) ;
F_4 ( V_28 , V_32 , V_1 , V_9 + 4 , 1 , V_8 ) ;
V_9 += 5 + V_27 ;
V_25 -- ;
}
}
static void
F_12 ( T_1 * V_1 , int V_9 , T_2 * V_2 )
{
T_7 V_25 ;
T_7 V_33 ;
F_5 ( V_1 , V_9 , L_5 , V_2 ) ;
V_9 += 8 ;
F_5 ( V_1 , V_9 , L_6 , V_2 ) ;
V_9 += 8 ;
F_4 ( V_2 , V_34 , V_1 , V_9 , 20 , V_18 ) ;
V_9 += 20 ;
F_4 ( V_2 , V_35 , V_1 , V_9 , 1 , V_18 ) ;
V_9 += 1 ;
F_4 ( V_2 , V_36 , V_1 , V_9 , 1 , V_18 ) ;
V_9 += 1 ;
V_25 = F_10 ( V_1 , V_9 ) ;
F_4 ( V_2 , V_37 , V_1 , V_9 , 1 , V_18 ) ;
V_9 += 1 ;
V_33 = F_10 ( V_1 , V_9 ) ;
F_4 ( V_2 , V_38 , V_1 , V_9 , 1 , V_18 ) ;
V_9 += 1 ;
F_4 ( V_2 , V_39 , V_1 , V_9 , 20 , V_18 ) ;
V_9 += 20 ;
if ( V_33 > 32 )
V_33 = 32 ;
if ( V_33 != 0 ) {
F_4 ( V_2 , V_40 , V_1 , V_9 , V_33 , V_18 ) ;
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
F_4 ( V_2 , V_34 , V_1 , V_9 , 20 , V_18 ) ;
V_9 += 20 ;
V_9 += 2 ;
V_25 = F_10 ( V_1 , V_9 ) ;
F_4 ( V_2 , V_41 , V_1 , V_9 , 1 , V_18 ) ;
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
F_4 ( V_2 , V_34 , V_1 , V_9 , 20 , V_18 ) ;
V_9 += 20 ;
V_9 += 2 ;
V_25 = F_10 ( V_1 , V_9 ) ;
F_4 ( V_2 , V_42 , V_1 , V_9 , 1 , V_18 ) ;
V_9 += 1 ;
V_9 += 1 ;
F_4 ( V_2 , V_39 , V_1 , V_9 , 20 , V_18 ) ;
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
F_4 ( V_2 , V_43 , V_1 , V_9 , 1 , V_18 ) ;
V_9 += 1 ;
V_9 += 1 ;
F_4 ( V_2 , V_39 , V_1 , V_9 , 20 , V_18 ) ;
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
F_4 ( V_2 , V_34 , V_1 , V_9 , 20 , V_18 ) ;
V_9 += 20 ;
V_9 += 4 ;
F_4 ( V_2 , V_39 , V_1 , V_9 , 20 , V_18 ) ;
V_9 += 20 ;
V_9 += 32 ;
return V_9 ;
}
static void
F_17 ( T_1 * V_1 , T_8 * V_44 , T_2 * V_2 )
{
T_3 * V_3 ;
T_2 * V_4 = NULL ;
int V_9 = 0 ;
T_3 * V_45 ;
T_2 * V_46 ;
T_4 V_47 ;
F_18 ( V_44 -> V_48 , V_49 , L_7 ) ;
if ( V_2 ) {
V_3 = F_2 ( V_2 , V_5 , V_1 , V_9 , 108 , L_1 ) ;
V_4 = F_3 ( V_3 , V_6 ) ;
F_4 ( V_4 , V_50 , V_1 , V_9 , 2 , V_8 ) ;
}
V_9 += 2 ;
if ( V_2 ) {
F_4 ( V_4 , V_51 , V_1 , V_9 , 1 , V_8 ) ;
}
V_9 += 1 ;
if ( V_2 ) {
F_4 ( V_4 , V_52 , V_1 , V_9 , 1 , V_8 ) ;
}
V_9 += 1 ;
V_47 = F_7 ( V_1 , V_9 ) ;
F_19 ( V_44 -> V_48 , V_49 , L_8 ,
F_11 ( V_47 , V_53 ,
L_9 ) ) ;
if ( V_2 ) {
F_4 ( V_4 , V_54 , V_1 , V_9 , 2 , V_8 ) ;
}
V_9 += 2 ;
if ( V_47 == V_55 || V_47 == V_56 ) {
return;
}
if ( V_2 ) {
if ( V_47 & 0x0100 ) {
F_4 ( V_4 , V_57 , V_1 , V_9 , 2 , V_8 ) ;
}
V_9 += 2 ;
F_4 ( V_4 , V_58 , V_1 , V_9 , 4 , V_8 ) ;
V_9 += 4 ;
F_4 ( V_4 , V_59 , V_1 , V_9 , 2 , V_8 ) ;
V_9 += 2 ;
V_45 = F_4 ( V_4 , V_60 , V_1 , V_9 , 2 , V_8 ) ;
V_46 = F_3 ( V_45 , V_61 ) ;
switch ( V_47 ) {
case V_62 :
case V_63 :
F_4 ( V_46 , V_64 , V_1 , V_9 , 2 , V_8 ) ;
V_9 += 2 ;
F_12 ( V_1 , V_9 , V_4 ) ;
break;
case V_65 :
case V_66 :
F_4 ( V_46 , V_64 , V_1 , V_9 , 2 , V_8 ) ;
if ( V_47 == V_65 ) {
F_4 ( V_46 , V_67 , V_1 , V_9 , 2 , V_8 ) ;
} else {
F_4 ( V_46 , V_68 , V_1 , V_9 , 2 , V_8 ) ;
}
F_4 ( V_46 , V_69 , V_1 , V_9 , 2 , V_8 ) ;
F_4 ( V_46 , V_70 , V_1 , V_9 , 2 , V_8 ) ;
V_9 += 2 ;
F_12 ( V_1 , V_9 , V_4 ) ;
break;
case V_71 :
case V_72 :
case V_73 :
case V_74 :
V_9 += 2 ;
F_13 ( V_1 , V_9 , V_4 ) ;
break;
case V_75 :
case V_76 :
case V_77 :
if ( V_47 != V_77 ) {
F_4 ( V_46 , V_78 , V_1 , V_9 , 2 , V_8 ) ;
}
V_9 += 2 ;
F_14 ( V_1 , V_9 , V_4 ) ;
break;
case V_79 :
F_4 ( V_46 , V_80 , V_1 , V_9 , 2 , V_8 ) ;
break;
case V_81 :
case V_82 :
V_9 += 2 ;
F_15 ( V_1 , V_9 , V_4 ) ;
break;
case V_83 :
case V_84 :
V_9 += 2 ;
F_16 ( V_1 , V_9 , V_4 ) ;
break;
}
}
}
static void
F_20 ( const union V_85 * V_86 , const T_9 * V_87 ,
int V_88 , T_10 * V_89 )
{
switch ( V_86 -> V_90 . V_91 ) {
case V_92 :
case V_93 :
F_21 ( V_87 , 2 , V_88 , V_89 ) ;
break;
case V_94 :
case V_95 :
F_22 ( V_87 , 2 , V_88 , V_89 ) ;
break;
default:
V_89 -> V_96 ++ ;
break;
}
}
static void
F_23 ( T_1 * V_1 , T_8 * V_44 , T_2 * V_2 )
{
T_1 * V_97 ;
T_1 * V_98 ;
F_18 ( V_44 -> V_48 , V_99 , L_1 ) ;
switch ( V_44 -> V_86 -> V_90 . V_91 ) {
case V_100 :
F_17 ( V_1 , V_44 , V_2 ) ;
break;
case V_92 :
case V_93 :
F_18 ( V_44 -> V_48 , V_49 , L_10 ) ;
F_1 ( V_1 , V_2 ) ;
V_98 = F_24 ( V_1 , 2 ) ;
F_25 ( V_101 , V_98 , V_44 , V_2 ) ;
break;
case V_94 :
case V_95 :
F_18 ( V_44 -> V_48 , V_49 , L_11 ) ;
F_1 ( V_1 , V_2 ) ;
V_98 = F_24 ( V_1 , 2 ) ;
F_25 ( V_102 , V_98 , V_44 , V_2 ) ;
break;
default:
F_18 ( V_44 -> V_48 , V_49 , L_12 ) ;
V_97 = F_24 ( V_1 , 0 ) ;
F_25 ( V_103 , V_97 , V_44 , V_2 ) ;
break;
}
}
static void
F_26 ( T_1 * V_1 , T_8 * V_44 , T_2 * V_2 )
{
F_27 ( V_1 , 0 , V_44 , V_2 , V_104 , V_105 , FALSE ) ;
}
void
F_28 ( const union V_85 * V_86 , const T_9 * V_87 ,
int V_88 , T_10 * V_89 )
{
if ( V_86 -> V_90 . V_106 == V_107 ) {
switch ( V_86 -> V_90 . type ) {
case V_108 :
F_29 ( V_87 , 0 , V_88 , V_89 ) ;
break;
case V_109 :
F_20 ( V_86 , V_87 , V_88 , V_89 ) ;
break;
default:
V_89 -> V_96 ++ ;
break;
}
} else
V_89 -> V_96 ++ ;
}
static void
F_30 ( T_1 * V_1 , T_8 * V_44 , T_2 * V_2 ,
T_3 * V_110 ,
T_2 * V_111 , T_11 V_112 , T_11 V_113 )
{
T_5 V_114 , V_115 ;
T_4 V_116 ;
int V_117 ;
T_1 * V_97 ;
T_6 V_118 ;
T_6 V_119 ;
T_12 type ;
T_11 V_120 ;
if ( V_44 -> V_86 -> V_90 . V_106 == V_107 ) {
F_31 ( V_111 , V_121 , V_1 , 0 , 0 , V_44 -> V_86 -> V_90 . type ) ;
switch ( V_44 -> V_86 -> V_90 . type ) {
case V_122 :
F_31 ( V_111 , V_123 , V_1 , 0 , 0 , V_44 -> V_86 -> V_90 . V_91 ) ;
break;
case V_109 :
F_31 ( V_111 , V_124 , V_1 , 0 , 0 , V_44 -> V_86 -> V_90 . V_91 ) ;
break;
case V_125 :
F_31 ( V_111 , V_126 , V_1 , 0 , 0 , V_44 -> V_86 -> V_90 . V_91 ) ;
break;
}
}
if ( ! V_113 ) {
F_31 ( V_111 , V_127 , V_1 , 0 , 0 ,
V_44 -> V_86 -> V_90 . V_128 ) ;
F_31 ( V_111 , V_129 , V_1 , 0 , 0 ,
V_44 -> V_86 -> V_90 . V_130 ) ;
F_19 ( V_44 -> V_48 , V_49 , L_13 ,
V_44 -> V_86 -> V_90 . V_128 ,
V_44 -> V_86 -> V_90 . V_130 ) ;
}
V_97 = V_1 ;
if ( V_112 || V_44 -> V_86 -> V_90 . V_131 & V_132 ) {
if ( V_44 -> V_86 -> V_90 . V_133 != 0 ) {
if ( V_2 ) {
F_31 ( V_111 , V_134 , V_1 , 0 , 0 , V_44 -> V_86 -> V_90 . V_133 ) ;
F_31 ( V_111 , V_135 , V_1 , 0 , 0 , V_44 -> V_86 -> V_90 . V_136 >> 8 ) ;
F_31 ( V_111 , V_137 , V_1 , 0 , 0 , V_44 -> V_86 -> V_90 . V_136 & 0xFF ) ;
F_31 ( V_111 , V_138 , V_1 , 0 , 0 , V_44 -> V_86 -> V_90 . V_139 ) ;
F_31 ( V_111 , V_140 , V_1 , 0 , 0 , V_44 -> V_86 -> V_90 . V_141 ) ;
}
}
} else {
V_114 = F_32 ( V_1 ) ;
V_115 = F_33 ( V_1 ) ;
if ( ( V_115 % 48 ) == 0 ) {
F_31 ( V_111 , V_134 , V_1 , 0 , 0 , V_115 / 48 ) ;
}
if ( ( V_44 -> V_86 -> V_90 . V_106 == V_107 ||
V_44 -> V_86 -> V_90 . V_106 == V_142 ) &&
V_114 >= V_115 ) {
V_116 = F_7 ( V_1 , V_114 - 6 ) ;
if ( V_116 > 0 && V_116 <= V_114 - 8 ) {
V_117 = V_114 - V_116 - 8 ;
if ( V_117 <= 47 ) {
if ( V_2 ) {
T_3 * V_3 ;
if ( V_117 > 0 ) {
F_4 ( V_111 , V_143 , V_1 , V_116 , V_117 , V_18 ) ;
}
F_4 ( V_111 , V_135 , V_1 , V_114 - 8 , 1 , V_8 ) ;
F_4 ( V_111 , V_137 , V_1 , V_114 - 7 , 1 , V_8 ) ;
F_4 ( V_111 , V_138 , V_1 , V_114 - 6 , 2 , V_8 ) ;
V_118 = F_9 ( V_1 , V_114 - 4 ) ;
V_119 = F_34 ( V_1 , V_114 ) ;
V_3 = F_31 ( V_111 , V_140 , V_1 , V_114 - 4 , 4 , V_118 ) ;
F_35 ( V_3 , ( V_119 == 0xC704DD7B ) ? L_14 : L_15 ) ;
}
V_97 = F_36 ( V_1 , 0 , V_116 ) ;
}
}
}
}
V_120 = FALSE ;
switch ( V_44 -> V_86 -> V_90 . V_106 ) {
case V_142 :
if ( ! ( V_44 -> V_86 -> V_90 . V_131 & V_132 ) ) {
F_25 ( V_144 , V_97 , V_44 , V_2 ) ;
V_120 = TRUE ;
}
break;
case V_107 :
if ( ! ( V_44 -> V_86 -> V_90 . V_131 & V_132 ) ) {
switch ( V_44 -> V_86 -> V_90 . type ) {
case V_145 :
F_25 ( V_144 , V_97 , V_44 , V_2 ) ;
V_120 = TRUE ;
break;
case V_146 :
F_25 ( V_147 , V_97 , V_44 , V_2 ) ;
V_120 = TRUE ;
break;
case V_108 :
F_25 ( V_148 , V_97 , V_44 , V_2 ) ;
V_120 = TRUE ;
break;
case V_109 :
F_25 ( V_149 , V_97 , V_44 , V_2 ) ;
V_120 = TRUE ;
break;
case V_150 :
F_25 ( V_151 , V_97 , V_44 , V_2 ) ;
V_120 = TRUE ;
break;
case V_152 :
F_25 ( V_153 , V_97 , V_44 , V_2 ) ;
V_120 = TRUE ;
break;
default:
if ( F_32 ( V_97 ) > 7 )
{
T_7 V_154 [ 8 ] ;
F_37 ( V_97 , V_154 , 0 , sizeof( V_154 ) ) ;
V_120 = TRUE ;
if ( V_154 [ 0 ] == 0xaa
&& V_154 [ 1 ] == 0xaa
&& V_154 [ 2 ] == 0x03 )
{
F_25 ( V_148 , V_97 , V_44 , V_2 ) ;
}
else if ( ( F_38 ( V_154 ) & 0xff ) == V_155 )
{
F_25 ( V_156 , V_97 , V_44 , V_2 ) ;
}
else if ( F_38 ( V_154 ) == 0x00 )
{
F_4 ( V_2 , V_143 , V_1 , 0 , 2 , V_18 ) ;
V_97 = F_24 ( V_1 , 2 ) ;
F_25 ( V_157 , V_97 , V_44 , V_2 ) ;
}
else if ( V_154 [ 2 ] == 0x03 &&
( ( V_154 [ 3 ] == 0xcc ||
V_154 [ 3 ] == 0x8e ) ||
( V_154 [ 3 ] == 0x00 &&
V_154 [ 4 ] == 0x80 ) ) )
{
F_25 ( V_147 , V_97 , V_44 , V_2 ) ;
}
else if ( V_154 [ 4 ] == 0x03 &&
( ( V_154 [ 5 ] == 0xcc ||
V_154 [ 5 ] == 0x8e ) ||
( V_154 [ 5 ] == 0x00 &&
V_154 [ 6 ] == 0x80 ) ) )
{
F_25 ( V_147 , V_97 , V_44 , V_2 ) ;
}
else if ( ( ( V_154 [ 0 ] & 0xf0 ) == 0x40 ) ||
( ( V_154 [ 0 ] & 0xf0 ) == 0x60 ) )
{
F_25 ( V_158 , V_97 , V_44 , V_2 ) ;
}
else
{
V_120 = FALSE ;
}
}
if ( V_2 && ! V_120 ) {
F_25 ( V_103 , V_97 , V_44 , V_2 ) ;
}
}
break;
}
break;
case V_159 :
F_31 ( V_111 , V_160 , V_1 , 0 , 0 ,
V_44 -> V_86 -> V_90 . V_161 ) ;
F_35 ( V_110 , L_16 ,
V_44 -> V_86 -> V_90 . V_128 ,
V_44 -> V_86 -> V_90 . V_130 ,
V_44 -> V_86 -> V_90 . V_161 ) ;
if ( ! ( V_44 -> V_86 -> V_90 . V_131 & V_132 ) ) {
if ( V_44 -> V_86 -> V_90 . V_131 & V_162 ) {
V_97 = V_1 ;
} else {
V_97 = F_24 ( V_1 , 4 ) ;
}
type = V_44 -> V_86 -> V_90 . type ;
if ( type == V_163 ) {
type = V_164 ;
}
switch ( type ) {
case V_165 :
F_25 ( V_166 , V_97 , V_44 , V_2 ) ;
V_120 = TRUE ;
break;
default:
break;
}
}
break;
default:
break;
}
if ( V_2 && ! V_120 ) {
F_25 ( V_103 , V_97 , V_44 , V_2 ) ;
}
}
static int
F_39 ( const T_7 * V_167 )
{
register T_7 V_168 ;
register int V_169 , V_170 ;
V_168 = 0 ;
for ( V_169 = 0 ; V_169 < 4 ; V_169 ++ )
V_168 = V_171 [ V_168 ^ V_167 [ V_169 ] ] ;
V_168 ^= V_167 [ 4 ] ^ V_172 ;
V_170 = V_173 [ V_168 ] ;
if ( V_170 < 0 )
return V_174 ;
else if ( V_170 < 40 )
return V_170 ;
else
return V_175 ;
}
T_11
F_40 ( const T_4 V_130 , const T_7 V_176 )
{
return ( ( ( V_130 == 3 || V_130 == 4 ) && ( ( V_176 & 0x5 ) == 0 ) )
|| ( ( V_176 & 0x6 ) == 0x4 ) ) ;
}
static void
F_41 ( T_1 * V_1 , T_8 * V_44 , T_2 * V_2 ,
T_2 * V_111 , T_5 V_106 , T_11 V_177 ,
T_11 V_178 , const T_13 * V_179 )
{
int V_9 ;
T_2 * V_180 ;
T_3 * V_3 ;
T_7 V_154 , V_176 ;
int V_181 ;
T_4 V_128 , V_130 , V_182 , V_183 ;
T_12 V_114 ;
T_1 * V_97 ;
if ( NULL == V_179 ) {
if ( ! V_177 ) {
V_154 = F_10 ( V_1 , 0 ) ;
F_4 ( V_111 , V_184 , V_1 , 0 , 1 , V_18 ) ;
V_128 = ( V_154 & 0xF ) << 4 ;
V_154 = F_10 ( V_1 , 1 ) ;
V_128 |= V_154 >> 4 ;
F_31 ( V_111 , V_127 , V_1 , 0 , 2 , V_128 ) ;
} else {
V_154 = F_10 ( V_1 , 0 ) ;
V_128 = V_154 << 4 ;
V_154 = F_10 ( V_1 , 1 ) ;
V_128 |= ( V_154 & 0xF0 ) >> 4 ;
F_31 ( V_111 , V_127 , V_1 , 0 , 2 , V_128 ) ;
}
V_130 = ( V_154 & 0x0F ) << 12 ;
V_154 = F_10 ( V_1 , 2 ) ;
V_130 |= V_154 << 4 ;
V_154 = F_10 ( V_1 , 3 ) ;
V_130 |= V_154 >> 4 ;
F_31 ( V_111 , V_129 , V_1 , 1 , 3 , V_130 ) ;
V_176 = ( V_154 >> 1 ) & 0x7 ;
F_4 ( V_111 , V_185 , V_1 , 3 , 1 , V_8 ) ;
F_4 ( V_111 , V_186 , V_1 , 3 , 1 , V_8 ) ;
if ( ! V_178 ) {
V_3 = F_4 ( V_111 , V_187 , V_1 , 4 , 1 , V_8 ) ;
V_181 = F_39 ( F_42 ( V_1 , 0 , 5 ) ) ;
if ( V_181 == V_174 )
F_35 ( V_3 , L_14 ) ;
else if ( V_181 == V_175 )
F_35 ( V_3 , L_17 ) ;
else
F_35 ( V_3 , L_18 , V_181 ) ;
V_9 = 5 ;
} else {
V_9 = 4 ;
}
}
else
{
V_9 = 0 ;
V_130 = V_179 -> V_130 ;
V_176 = V_179 -> V_188 ;
}
if ( V_106 == V_189 || V_106 == V_190 ) {
if ( F_40 ( V_130 , V_176 ) ) {
V_106 = V_191 ;
}
}
switch ( V_106 ) {
case V_192 :
F_18 ( V_44 -> V_48 , V_99 , L_19 ) ;
F_43 ( V_44 -> V_48 , V_49 ) ;
V_3 = F_4 ( V_2 , V_193 , V_1 , V_9 , - 1 , V_18 ) ;
V_180 = F_3 ( V_3 , V_194 ) ;
V_154 = F_10 ( V_1 , V_9 ) ;
F_4 ( V_180 , V_195 , V_1 , V_9 , 1 , V_8 ) ;
F_4 ( V_180 , V_196 , V_1 , V_9 , 1 , V_8 ) ;
F_44 ( V_44 -> V_48 , V_49 , L_20 ,
( V_154 >> 4 ) & 0x7 ) ;
F_4 ( V_180 , V_197 , V_1 , V_9 , 1 , V_8 ) ;
F_4 ( V_180 , V_198 , V_1 , V_9 , 1 , V_8 ) ;
V_9 ++ ;
F_4 ( V_180 , V_199 , V_1 , V_9 , 47 , V_18 ) ;
break;
case V_200 :
F_18 ( V_44 -> V_48 , V_99 , L_21 ) ;
F_43 ( V_44 -> V_48 , V_49 ) ;
V_3 = F_4 ( V_2 , V_201 , V_1 , V_9 , - 1 , V_18 ) ;
V_180 = F_3 ( V_3 , V_202 ) ;
V_182 = F_7 ( V_1 , V_9 ) ;
F_44 ( V_44 -> V_48 , V_49 , L_22 ,
F_11 ( V_182 >> 14 , V_203 , L_23 ) ,
( V_182 >> 10 ) & 0xF ) ;
F_4 ( V_180 , V_204 , V_1 , V_9 , 2 , V_8 ) ;
F_4 ( V_180 , V_205 , V_1 , V_9 , 2 , V_8 ) ;
F_4 ( V_180 , V_206 , V_1 , V_9 , 2 , V_8 ) ;
V_114 = F_45 ( V_1 , V_9 ) ;
V_183 = F_46 ( 0 , V_1 , V_9 , V_114 ) ;
V_9 += 2 ;
F_4 ( V_180 , V_207 , V_1 , V_9 , 44 , V_18 ) ;
V_9 += 44 ;
F_4 ( V_180 , V_208 , V_1 , V_9 , 2 , V_8 ) ;
V_3 = F_4 ( V_180 , V_209 , V_1 , V_9 , 2 , V_8 ) ;
F_35 ( V_3 , L_24 , ( V_183 == 0 ) ? L_14 : L_15 ) ;
break;
case V_191 :
if ( NULL == V_179 || V_179 -> V_210 )
{
F_18 ( V_44 -> V_48 , V_99 , L_25 ) ;
F_43 ( V_44 -> V_48 , V_49 ) ;
}
V_3 = F_4 ( V_2 , V_211 , V_1 , V_9 , - 1 , V_18 ) ;
V_180 = F_3 ( V_3 , V_212 ) ;
V_154 = F_10 ( V_1 , V_9 ) ;
if ( NULL == V_179 || V_179 -> V_210 )
{
F_44 ( V_44 -> V_48 , V_49 , L_26 ,
F_11 ( V_154 >> 4 , V_213 , L_23 ) ) ;
}
F_4 ( V_180 , V_214 , V_1 , V_9 , 1 , V_8 ) ;
switch ( V_154 >> 4 ) {
case V_215 :
F_4 ( V_180 , V_216 , V_1 , V_9 , 1 , V_8 ) ;
break;
case V_217 :
F_4 ( V_180 , V_218 , V_1 , V_9 , 1 , V_8 ) ;
break;
case V_219 :
F_4 ( V_180 , V_220 , V_1 , V_9 , 1 , V_8 ) ;
break;
default:
F_4 ( V_180 , V_221 , V_1 , V_9 , 1 , V_8 ) ;
break;
}
V_114 = F_45 ( V_1 , V_9 ) ;
V_183 = F_46 ( 0 , V_1 , V_9 , V_114 ) ;
V_9 += 1 ;
F_4 ( V_180 , V_222 , V_1 , V_9 , 45 , V_18 ) ;
V_9 += 45 ;
V_3 = F_4 ( V_180 , V_223 , V_1 , V_9 , 2 , V_8 ) ;
F_35 ( V_3 , L_24 , ( V_183 == 0 ) ? L_14 : L_15 ) ;
break;
default:
V_97 = F_24 ( V_1 , V_9 ) ;
F_25 ( V_103 , V_97 , V_44 , V_2 ) ;
break;
}
}
static int
F_47 ( T_1 * V_1 , T_8 * V_44 , T_2 * V_2 ,
T_11 V_112 , const T_13 * V_179 )
{
T_2 * V_111 = NULL ;
T_3 * V_110 = NULL ;
T_11 V_113 = ( NULL != V_179 ) ;
if ( V_44 -> V_86 -> V_90 . V_106 == V_107 &&
V_44 -> V_86 -> V_90 . type == V_109 &&
V_224 ) {
V_44 -> V_86 -> V_90 . V_106 = V_142 ;
}
F_18 ( V_44 -> V_48 , V_99 , L_27 ) ;
if ( ! V_113 ) {
switch ( V_44 -> V_86 -> V_90 . V_225 ) {
case 0 :
F_18 ( V_44 -> V_48 , V_226 , L_28 ) ;
F_18 ( V_44 -> V_48 , V_227 , L_29 ) ;
break;
case 1 :
F_18 ( V_44 -> V_48 , V_226 , L_29 ) ;
F_18 ( V_44 -> V_48 , V_227 , L_28 ) ;
break;
}
}
if ( V_44 -> V_86 -> V_90 . V_106 == V_107 ) {
F_44 ( V_44 -> V_48 , V_49 , L_30 ,
F_11 ( V_44 -> V_86 -> V_90 . type , V_228 ,
L_31 ) ) ;
} else {
F_48 ( V_44 -> V_48 , V_49 ,
F_11 ( V_44 -> V_86 -> V_90 . V_106 , V_229 ,
L_32 ) ) ;
}
if ( V_2 ) {
V_110 = F_4 ( V_2 , V_230 , V_1 , 0 , - 1 , V_18 ) ;
V_111 = F_3 ( V_110 , V_231 ) ;
if ( ! V_113 ) {
F_31 ( V_111 , V_232 , V_1 , 0 , 0 , V_44 -> V_86 -> V_90 . V_225 ) ;
if ( V_44 -> V_86 -> V_90 . V_131 & V_132 )
F_49 ( V_44 , V_110 , & V_233 ) ;
}
F_50 ( V_111 , V_234 , V_1 , 0 , 0 ,
V_44 -> V_86 -> V_90 . V_106 ,
L_26 ,
F_11 ( V_44 -> V_86 -> V_90 . V_106 , V_229 ,
L_32 ) ) ;
}
if ( V_44 -> V_86 -> V_90 . V_131 & V_235 ) {
if ( V_44 -> V_86 -> V_90 . V_131 & V_236 ) {
F_51 ( V_110 , 4 ) ;
} else {
F_51 ( V_110 , 5 ) ;
}
F_41 ( V_1 , V_44 , V_2 , V_111 ,
V_44 -> V_86 -> V_90 . V_106 , FALSE ,
V_44 -> V_86 -> V_90 . V_131 & V_236 , V_179 ) ;
} else {
F_30 ( V_1 , V_44 , V_2 , V_111 , V_110 , V_112 , V_179 != NULL ) ;
}
return F_32 ( V_1 ) ;
}
static int
F_52 ( T_1 * V_1 , T_8 * V_44 , T_2 * V_2 , void * V_237 )
{
const T_13 * V_179 = ( const T_13 * ) V_237 ;
return F_47 ( V_1 , V_44 , V_2 , TRUE , V_179 ) ;
}
static int
F_53 ( T_1 * V_1 , T_8 * V_44 , T_2 * V_2 , void * V_237 )
{
const T_13 * V_179 = ( const T_13 * ) V_237 ;
return F_47 ( V_1 , V_44 , V_2 , FALSE , V_179 ) ;
}
static int
F_54 ( T_1 * V_1 , T_8 * V_44 , T_2 * V_2 , void * V_237 )
{
T_2 * V_111 = NULL ;
T_3 * V_110 = NULL ;
const T_13 * V_179 = ( const T_13 * ) V_237 ;
T_11 V_113 = ( NULL != V_179 ) ;
F_18 ( V_44 -> V_48 , V_99 , L_27 ) ;
if ( ! V_113 ) {
V_110 = F_4 ( V_2 , V_230 , V_1 , 0 , 0 , V_18 ) ;
V_111 = F_3 ( V_110 , V_231 ) ;
}
F_41 ( V_1 , V_44 , V_2 , V_111 , V_191 , FALSE , FALSE , V_179 ) ;
return F_32 ( V_1 ) ;
}
void
F_55 ( void )
{
static T_14 V_238 [] = {
{ & V_234 ,
{ L_33 , L_34 , V_239 , V_240 , F_56 ( V_229 ) , 0x0 ,
NULL , V_241 } } ,
{ & V_184 ,
{ L_35 , L_36 , V_239 , V_240 , NULL , 0xF0 ,
NULL , V_241 } } ,
{ & V_127 ,
{ L_37 , L_38 , V_239 , V_240 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_129 ,
{ L_39 , L_40 , V_242 , V_240 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_160 ,
{ L_41 , L_42 , V_239 , V_240 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_7 ,
{ L_43 , L_44 , V_242 , V_243 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_15 ,
{ L_45 , L_46 , V_242 , V_243 , F_56 ( V_244 ) , 0x0 ,
NULL , V_241 } } ,
{ & V_17 ,
{ L_47 , L_48 , V_245 , V_246 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_31 ,
{ L_49 , L_50 , V_247 , V_243 , F_56 ( V_30 ) , 0x0 ,
NULL , V_241 } } ,
{ & V_32 ,
{ L_51 , L_52 , V_239 , V_240 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_20 ,
{ L_53 , L_54 , V_242 , V_243 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_23 ,
{ L_55 , L_56 , V_242 , V_240 , NULL , 0xFFF0 ,
NULL , V_241 } } ,
{ & V_24 ,
{ L_57 , L_58 , V_242 , V_240 , NULL , 0x000F ,
NULL , V_241 } } ,
{ & V_34 ,
{ L_59 , L_60 , V_248 , V_246 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_39 ,
{ L_61 , L_62 , V_248 , V_246 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_35 ,
{ L_63 , L_64 , V_239 , V_243 , F_56 ( V_249 ) , 0x0 ,
NULL , V_241 } } ,
{ & V_36 ,
{ L_65 , L_66 , V_239 , V_243 , F_56 ( V_250 ) , 0x0 ,
NULL , V_241 } } ,
{ & V_37 ,
{ L_67 , L_68 , V_239 , V_240 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_38 ,
{ L_69 , L_70 , V_239 , V_240 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_41 ,
{ L_67 , L_71 , V_239 , V_240 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_42 ,
{ L_67 , L_72 , V_239 , V_240 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_43 ,
{ L_67 , L_73 , V_239 , V_240 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_40 ,
{ L_74 , L_75 , V_248 , V_246 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_50 ,
{ L_76 , L_77 , V_242 , V_243 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_51 ,
{ L_78 , L_79 , V_239 , V_243 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_52 ,
{ L_80 , L_81 , V_239 , V_243 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_54 ,
{ L_82 , L_83 , V_242 , V_243 , F_56 ( V_53 ) , 0x0 ,
NULL , V_241 } } ,
{ & V_57 ,
{ L_84 , L_85 , V_242 , V_243 , F_56 ( V_251 ) , 0x0 ,
NULL , V_241 } } ,
{ & V_58 ,
{ L_86 , L_87 , V_247 , V_243 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_59 ,
{ L_88 , L_89 , V_242 , V_243 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_60 ,
{ L_90 , L_91 , V_242 , V_243 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_64 ,
{ L_92 , L_93 , V_252 , 16 , F_57 ( & V_253 ) , 0x0002 ,
NULL , V_241 } } ,
{ & V_67 ,
{ L_94 , L_95 , V_252 , 16 , F_57 ( & V_253 ) , 0x0004 ,
NULL , V_241 } } ,
{ & V_68 ,
{ L_96 , L_97 , V_252 , 16 , F_57 ( & V_253 ) , 0x0008 ,
NULL , V_241 } } ,
{ & V_69 ,
{ L_98 , L_99 , V_252 , 16 , F_57 ( & V_253 ) , 0x0080 ,
NULL , V_241 } } ,
{ & V_70 ,
{ L_100 , L_101 , V_252 , 16 , F_57 ( & V_253 ) , 0x0200 ,
NULL , V_241 } } ,
{ & V_78 ,
{ L_102 , L_103 , V_252 , 16 , F_57 ( & V_253 ) , 0x0001 ,
NULL , V_241 } } ,
{ & V_80 ,
{ L_104 , L_105 , V_252 , 16 , F_57 ( & V_254 ) , 0x0100 ,
NULL , V_241 } } ,
{ & V_121 ,
{ L_106 , L_107 , V_239 , V_240 , F_56 ( V_228 ) , 0x0 ,
NULL , V_241 } } ,
{ & V_123 ,
{ L_108 , L_109 , V_239 , V_240 , F_56 ( V_255 ) , 0x0 ,
NULL , V_241 } } ,
{ & V_124 ,
{ L_110 , L_111 , V_239 , V_240 , F_56 ( V_256 ) , 0x0 ,
NULL , V_241 } } ,
{ & V_126 ,
{ L_112 , L_113 , V_239 , V_240 , F_56 ( V_257 ) , 0x0 ,
NULL , V_241 } } ,
{ & V_134 ,
{ L_114 , L_115 , V_242 , V_240 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_135 ,
{ L_116 , L_117 , V_239 , V_243 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_137 ,
{ L_118 , L_119 , V_239 , V_243 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_138 ,
{ L_120 , L_121 , V_242 , V_240 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_140 ,
{ L_122 , L_123 , V_247 , V_243 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_185 ,
{ L_124 , L_125 , V_239 , V_240 , NULL , 0x0E ,
NULL , V_241 } } ,
{ & V_186 ,
{ L_126 , L_127 , V_252 , 8 , F_57 ( & V_258 ) , 0x01 ,
NULL , V_241 } } ,
{ & V_187 ,
{ L_128 , L_129 , V_239 , V_243 , NULL , 0 ,
NULL , V_241 } } ,
{ & V_232 ,
{ L_130 , L_131 , V_242 , V_240 , F_56 ( V_259 ) , 0 ,
NULL , V_241 } } ,
{ & V_195 ,
{ L_132 , L_133 , V_239 , V_240 , NULL , 0x80 ,
NULL , V_241 } } ,
{ & V_196 ,
{ L_134 , L_135 , V_239 , V_240 , NULL , 0x70 ,
NULL , V_241 } } ,
{ & V_197 ,
{ L_136 , L_137 , V_239 , V_240 , NULL , 0x08 ,
NULL , V_241 } } ,
{ & V_198 ,
{ L_138 , L_139 , V_239 , V_240 , NULL , 0x07 ,
NULL , V_241 } } ,
{ & V_199 ,
{ L_140 , L_141 , V_248 , V_246 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_204 ,
{ L_142 , L_143 , V_242 , V_240 , F_56 ( V_203 ) , 0xC000 ,
NULL , V_241 } } ,
{ & V_205 ,
{ L_144 , L_145 , V_242 , V_240 , NULL , 0x3C00 ,
NULL , V_241 } } ,
{ & V_206 ,
{ L_146 , L_147 , V_242 , V_240 , NULL , 0x03FF ,
NULL , V_241 } } ,
{ & V_207 ,
{ L_148 , L_149 , V_248 , V_246 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_208 ,
{ L_150 , L_151 , V_242 , V_240 , F_56 ( V_203 ) , 0xFC00 ,
NULL , V_241 } } ,
{ & V_209 ,
{ L_136 , L_152 , V_242 , V_240 , NULL , 0x03FF ,
NULL , V_241 } } ,
{ & V_214 ,
{ L_153 , L_154 , V_239 , V_240 , F_56 ( V_213 ) , 0xF0 ,
NULL , V_241 } } ,
{ & V_216 ,
{ L_155 , L_156 , V_239 , V_240 , F_56 ( V_260 ) , 0x0F ,
NULL , V_241 } } ,
{ & V_218 ,
{ L_155 , L_157 , V_239 , V_240 , F_56 ( V_261 ) , 0x0F ,
NULL , V_241 } } ,
{ & V_220 ,
{ L_155 , L_158 , V_239 , V_240 , F_56 ( V_262 ) , 0x0F ,
NULL , V_241 } } ,
{ & V_221 ,
{ L_155 , L_159 , V_239 , V_240 , NULL , 0x0F ,
NULL , V_241 } } ,
{ & V_222 ,
{ L_160 , L_161 , V_248 , V_246 , NULL , 0x0 ,
NULL , V_241 } } ,
{ & V_223 ,
{ L_162 , L_163 , V_242 , V_243 , NULL , 0x3FF ,
NULL , V_241 } } ,
{ & V_143 ,
{ L_164 , L_165 , V_248 , V_246 , NULL , 0x0 ,
NULL , V_241 } } ,
} ;
static T_12 * V_263 [] = {
& V_231 ,
& V_105 ,
& V_194 ,
& V_202 ,
& V_212 ,
& V_6 ,
& V_14 ,
& V_22 ,
& V_61 ,
& V_29 ,
} ;
static T_15 V_264 [] = {
{ & V_233 , { L_166 , V_265 , V_266 , L_167 , V_267 } } ,
} ;
T_16 * V_268 ;
static const T_17 V_269 [] = {
{ L_168 , L_169 , V_163 } ,
{ L_170 , L_171 , V_165 } ,
{ NULL , NULL , 0 }
} ;
T_18 * V_270 ;
V_230 = F_58 ( L_172 , L_27 , L_173 ) ;
V_193 = F_58 ( L_174 , L_19 , L_175 ) ;
V_201 = F_58 ( L_176 , L_21 , L_177 ) ;
V_211 = F_58 ( L_178 , L_25 , L_179 ) ;
F_59 ( V_230 , V_238 , F_60 ( V_238 ) ) ;
F_61 ( V_263 , F_60 ( V_263 ) ) ;
V_268 = F_62 ( V_230 ) ;
F_63 ( V_268 , V_264 , F_60 ( V_264 ) ) ;
V_104 = F_58 ( L_180 , L_180 , L_181 ) ;
F_64 ( L_181 , F_26 , V_104 ) ;
V_5 = F_58 ( L_182 ,
L_1 , L_183 ) ;
F_64 ( L_183 , F_23 , V_5 ) ;
V_271 = F_65 ( L_184 , F_52 , V_230 ) ;
V_272 = F_65 ( L_185 , F_53 , V_230 ) ;
F_65 ( L_186 , F_54 , V_211 ) ;
V_270 = F_66 ( V_230 , NULL ) ;
F_67 ( V_270 , L_187 , L_188 ,
L_189 ,
& V_224 ) ;
F_68 ( V_270 , L_190 ,
L_191 ,
L_192 ,
& V_164 , V_269 , FALSE ) ;
}
void
F_69 ( void )
{
V_101 = F_70 ( L_193 ) ;
V_102 = F_70 ( L_194 ) ;
V_147 = F_70 ( L_195 ) ;
V_148 = F_70 ( L_196 ) ;
V_144 = F_70 ( L_197 ) ;
V_149 = F_70 ( L_183 ) ;
V_151 = F_70 ( L_181 ) ;
V_156 = F_70 ( L_198 ) ;
V_157 = F_70 ( L_199 ) ;
V_158 = F_70 ( L_200 ) ;
V_103 = F_70 ( L_201 ) ;
V_166 = F_70 ( L_202 ) ;
V_153 = F_70 ( L_203 ) ;
F_71 ( L_204 , V_273 , V_271 ) ;
F_71 ( L_204 , V_274 ,
V_272 ) ;
}
