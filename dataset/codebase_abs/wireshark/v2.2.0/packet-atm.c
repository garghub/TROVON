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
F_4 ( V_2 , V_41 , V_1 , V_9 , 2 , V_18 ) ;
V_9 += 2 ;
V_25 = F_10 ( V_1 , V_9 ) ;
F_4 ( V_2 , V_42 , V_1 , V_9 , 1 , V_18 ) ;
V_9 += 1 ;
F_4 ( V_2 , V_41 , V_1 , V_9 , 53 , V_18 ) ;
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
F_4 ( V_2 , V_41 , V_1 , V_9 , 2 , V_18 ) ;
V_9 += 2 ;
V_25 = F_10 ( V_1 , V_9 ) ;
F_4 ( V_2 , V_43 , V_1 , V_9 , 1 , V_18 ) ;
V_9 += 1 ;
F_4 ( V_2 , V_41 , V_1 , V_9 , 1 , V_18 ) ;
V_9 += 1 ;
F_4 ( V_2 , V_39 , V_1 , V_9 , 20 , V_18 ) ;
V_9 += 20 ;
F_4 ( V_2 , V_41 , V_1 , V_9 , 32 , V_18 ) ;
V_9 += 32 ;
F_8 ( V_1 , V_9 , V_25 , V_2 ) ;
}
static void
F_15 ( T_1 * V_1 , int V_9 , T_2 * V_2 )
{
T_7 V_25 ;
F_4 ( V_2 , V_41 , V_1 , V_9 , 38 , V_18 ) ;
V_9 += 38 ;
V_25 = F_10 ( V_1 , V_9 ) ;
F_4 ( V_2 , V_44 , V_1 , V_9 , 1 , V_18 ) ;
V_9 += 1 ;
F_4 ( V_2 , V_41 , V_1 , V_9 , 1 , V_18 ) ;
V_9 += 1 ;
F_4 ( V_2 , V_39 , V_1 , V_9 , 20 , V_18 ) ;
V_9 += 20 ;
F_4 ( V_2 , V_41 , V_1 , V_9 , 32 , V_18 ) ;
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
F_4 ( V_2 , V_41 , V_1 , V_9 , 4 , V_18 ) ;
V_9 += 4 ;
F_4 ( V_2 , V_39 , V_1 , V_9 , 20 , V_18 ) ;
V_9 += 20 ;
F_4 ( V_2 , V_41 , V_1 , V_9 , 32 , V_18 ) ;
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
V_9 += 2 ;
F_4 ( V_47 , V_41 , V_1 , V_9 , 92 , V_18 ) ;
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
static T_9
F_20 ( const T_10 * V_86 , int V_9 V_87 ,
int V_88 , T_11 * V_89 , const union V_90 * V_91 )
{
return F_21 ( L_10 , V_91 -> V_92 . V_93 , V_86 , 2 , V_88 , V_89 , V_91 ) ;
}
static int
F_22 ( T_1 * V_1 , T_8 * V_45 , T_2 * V_2 , void * V_94 )
{
struct V_95 * V_96 = (struct V_95 * ) V_94 ;
T_1 * V_97 ;
T_1 * V_98 ;
F_18 ( V_45 -> V_49 , V_99 , L_1 ) ;
switch ( V_96 -> V_93 ) {
case V_100 :
F_17 ( V_1 , V_45 , V_2 ) ;
break;
case V_101 :
case V_102 :
F_18 ( V_45 -> V_49 , V_50 , L_11 ) ;
F_1 ( V_1 , V_2 ) ;
V_98 = F_23 ( V_1 , 2 ) ;
F_24 ( V_103 , V_98 , V_45 , V_2 ) ;
break;
case V_104 :
case V_105 :
F_18 ( V_45 -> V_49 , V_50 , L_12 ) ;
F_1 ( V_1 , V_2 ) ;
V_98 = F_23 ( V_1 , 2 ) ;
F_24 ( V_106 , V_98 , V_45 , V_2 ) ;
break;
default:
F_18 ( V_45 -> V_49 , V_50 , L_13 ) ;
V_97 = F_23 ( V_1 , 0 ) ;
F_25 ( V_97 , V_45 , V_2 ) ;
break;
}
return F_26 ( V_1 ) ;
}
static int
F_27 ( T_1 * V_1 , T_8 * V_45 , T_2 * V_2 , void * V_94 V_87 )
{
return F_28 ( V_1 , 0 , V_45 , V_2 , V_107 , V_108 , FALSE ) ;
}
static T_9
F_29 ( const T_10 * V_86 , int V_9 ,
int V_88 , T_11 * V_89 , const union V_90 * V_91 )
{
if ( V_91 -> V_92 . V_109 == V_110 ) {
return F_21 ( L_14 , V_91 -> V_92 . type , V_86 , V_9 , V_88 , V_89 , V_91 ) ;
}
return FALSE ;
}
static void
F_30 ( T_1 * V_1 , T_8 * V_45 , T_2 * V_2 ,
T_3 * V_111 , T_2 * V_112 , T_9 V_113 ,
struct V_95 * V_96 , T_9 V_114 )
{
T_5 V_115 , V_116 ;
T_4 V_117 ;
int V_118 ;
T_1 * V_97 ;
T_6 V_119 ;
T_6 V_120 ;
T_9 V_121 ;
if ( V_96 -> V_109 == V_110 ) {
F_31 ( V_112 , V_122 , V_1 , 0 , 0 , V_96 -> type ) ;
switch ( V_96 -> type ) {
case V_123 :
F_31 ( V_112 , V_124 , V_1 , 0 , 0 , V_96 -> V_93 ) ;
break;
case V_125 :
F_31 ( V_112 , V_126 , V_1 , 0 , 0 , V_96 -> V_93 ) ;
break;
case V_127 :
F_31 ( V_112 , V_128 , V_1 , 0 , 0 , V_96 -> V_93 ) ;
break;
}
}
if ( ! V_114 ) {
F_31 ( V_112 , V_129 , V_1 , 0 , 0 , V_96 -> V_130 ) ;
F_31 ( V_112 , V_131 , V_1 , 0 , 0 , V_96 -> V_132 ) ;
F_19 ( V_45 -> V_49 , V_50 , L_15 ,
V_96 -> V_130 , V_96 -> V_132 ) ;
}
V_97 = V_1 ;
if ( V_113 || V_96 -> V_133 & V_134 ) {
if ( V_96 -> V_135 != 0 ) {
if ( V_2 ) {
F_31 ( V_112 , V_136 , V_1 , 0 , 0 , V_96 -> V_135 ) ;
F_31 ( V_112 , V_137 , V_1 , 0 , 0 , V_96 -> V_138 >> 8 ) ;
F_31 ( V_112 , V_139 , V_1 , 0 , 0 , V_96 -> V_138 & 0xFF ) ;
F_31 ( V_112 , V_140 , V_1 , 0 , 0 , V_96 -> V_141 ) ;
F_31 ( V_112 , V_142 , V_1 , 0 , 0 , V_96 -> V_143 ) ;
}
}
} else {
V_115 = F_26 ( V_1 ) ;
V_116 = F_32 ( V_1 ) ;
if ( ( V_116 % 48 ) == 0 ) {
F_31 ( V_112 , V_136 , V_1 , 0 , 0 , V_116 / 48 ) ;
}
if ( ( V_96 -> V_109 == V_110 || V_96 -> V_109 == V_144 ) &&
V_115 >= V_116 ) {
V_117 = F_7 ( V_1 , V_115 - 6 ) ;
if ( V_117 > 0 && V_117 <= V_115 - 8 ) {
V_118 = V_115 - V_117 - 8 ;
if ( V_118 <= 47 ) {
if ( V_2 ) {
T_3 * V_3 ;
if ( V_118 > 0 ) {
F_4 ( V_112 , V_145 , V_1 , V_117 , V_118 , V_18 ) ;
}
F_4 ( V_112 , V_137 , V_1 , V_115 - 8 , 1 , V_8 ) ;
F_4 ( V_112 , V_139 , V_1 , V_115 - 7 , 1 , V_8 ) ;
F_4 ( V_112 , V_140 , V_1 , V_115 - 6 , 2 , V_8 ) ;
V_119 = F_9 ( V_1 , V_115 - 4 ) ;
V_120 = F_33 ( V_1 , V_115 ) ;
V_3 = F_31 ( V_112 , V_142 , V_1 , V_115 - 4 , 4 , V_119 ) ;
F_34 ( V_3 , ( V_120 == 0xC704DD7B ) ? L_16 : L_17 ) ;
}
V_97 = F_35 ( V_1 , 0 , V_117 ) ;
}
}
}
}
V_121 = FALSE ;
switch ( V_96 -> V_109 ) {
case V_144 :
if ( ! ( V_96 -> V_133 & V_134 ) ) {
F_24 ( V_146 , V_97 , V_45 , V_2 ) ;
V_121 = TRUE ;
}
break;
case V_110 :
if ( ! ( V_96 -> V_133 & V_134 ) ) {
if ( F_36 ( V_147 , V_96 -> type , V_97 , V_45 , V_2 , TRUE , V_96 ) )
{
V_121 = TRUE ;
}
else
{
if ( F_32 ( V_97 ) > 7 )
{
T_7 V_148 [ 8 ] ;
F_37 ( V_97 , V_148 , 0 , sizeof( V_148 ) ) ;
if ( V_148 [ 0 ] == 0xaa
&& V_148 [ 1 ] == 0xaa
&& V_148 [ 2 ] == 0x03 )
{
F_24 ( V_149 , V_97 , V_45 , V_2 ) ;
V_121 = TRUE ;
}
else if ( ( F_38 ( V_148 ) & 0xff ) == V_150 )
{
F_24 ( V_151 , V_97 , V_45 , V_2 ) ;
V_121 = TRUE ;
}
else if ( F_38 ( V_148 ) == 0x00 )
{
F_4 ( V_2 , V_145 , V_1 , 0 , 2 , V_18 ) ;
V_97 = F_23 ( V_1 , 2 ) ;
F_24 ( V_152 , V_97 , V_45 , V_2 ) ;
V_121 = TRUE ;
}
else if ( V_148 [ 2 ] == 0x03 &&
( ( V_148 [ 3 ] == 0xcc ||
V_148 [ 3 ] == 0x8e ) ||
( V_148 [ 3 ] == 0x00 &&
V_148 [ 4 ] == 0x80 ) ) )
{
F_24 ( V_153 , V_97 , V_45 , V_2 ) ;
V_121 = TRUE ;
}
else if ( V_148 [ 4 ] == 0x03 &&
( ( V_148 [ 5 ] == 0xcc ||
V_148 [ 5 ] == 0x8e ) ||
( V_148 [ 5 ] == 0x00 &&
V_148 [ 6 ] == 0x80 ) ) )
{
F_24 ( V_153 , V_97 , V_45 , V_2 ) ;
V_121 = TRUE ;
}
else if ( ( ( V_148 [ 0 ] & 0xf0 ) == 0x40 ) ||
( ( V_148 [ 0 ] & 0xf0 ) == 0x60 ) )
{
F_24 ( V_154 , V_97 , V_45 , V_2 ) ;
V_121 = TRUE ;
}
}
}
break;
}
break;
case V_155 :
F_31 ( V_112 , V_156 , V_1 , 0 , 0 ,
V_96 -> V_157 ) ;
F_34 ( V_111 , L_18 ,
V_96 -> V_130 ,
V_96 -> V_132 ,
V_96 -> V_157 ) ;
if ( ! ( V_96 -> V_133 & V_134 ) ) {
if ( V_96 -> V_133 & V_158 ) {
V_97 = V_1 ;
} else {
V_97 = F_23 ( V_1 , 4 ) ;
}
if ( F_39 ( V_159 , V_96 -> type , V_97 , V_45 , V_2 ) )
{
V_121 = TRUE ;
}
}
break;
default:
break;
}
if ( ! V_121 ) {
F_25 ( V_97 , V_45 , V_2 ) ;
}
}
static int
F_40 ( const T_7 * V_160 )
{
register T_7 V_161 ;
register int V_162 , V_163 ;
V_161 = 0 ;
for ( V_162 = 0 ; V_162 < 4 ; V_162 ++ )
V_161 = V_164 [ V_161 ^ V_160 [ V_162 ] ] ;
V_161 ^= V_160 [ 4 ] ^ V_165 ;
V_163 = V_166 [ V_161 ] ;
if ( V_163 < 0 )
return V_167 ;
else if ( V_163 < 40 )
return V_163 ;
else
return V_168 ;
}
static void
F_41 ( T_1 * V_1 , int V_9 , T_8 * V_45 ,
T_2 * V_2 , T_5 V_109 , T_9 V_169 )
{
T_2 * V_170 ;
T_3 * V_3 ;
T_7 V_148 ;
T_12 V_115 ;
T_4 V_171 , V_172 ;
T_1 * V_97 ;
switch ( V_109 ) {
case V_173 :
F_18 ( V_45 -> V_49 , V_99 , L_19 ) ;
F_42 ( V_45 -> V_49 , V_50 ) ;
V_3 = F_4 ( V_2 , V_174 , V_1 , V_9 , - 1 , V_18 ) ;
V_170 = F_3 ( V_3 , V_175 ) ;
V_148 = F_10 ( V_1 , V_9 ) ;
F_4 ( V_170 , V_176 , V_1 , V_9 , 1 , V_8 ) ;
F_4 ( V_170 , V_177 , V_1 , V_9 , 1 , V_8 ) ;
F_43 ( V_45 -> V_49 , V_50 , L_20 ,
( V_148 >> 4 ) & 0x7 ) ;
F_4 ( V_170 , V_178 , V_1 , V_9 , 1 , V_8 ) ;
F_4 ( V_170 , V_179 , V_1 , V_9 , 1 , V_8 ) ;
V_9 ++ ;
F_4 ( V_170 , V_180 , V_1 , V_9 , 47 , V_18 ) ;
break;
case V_181 :
F_18 ( V_45 -> V_49 , V_99 , L_21 ) ;
F_42 ( V_45 -> V_49 , V_50 ) ;
V_3 = F_4 ( V_2 , V_182 , V_1 , V_9 , - 1 , V_18 ) ;
V_170 = F_3 ( V_3 , V_183 ) ;
V_171 = F_7 ( V_1 , V_9 ) ;
F_43 ( V_45 -> V_49 , V_50 , L_22 ,
F_11 ( V_171 >> 14 , V_184 , L_23 ) ,
( V_171 >> 10 ) & 0xF ) ;
F_4 ( V_170 , V_185 , V_1 , V_9 , 2 , V_8 ) ;
F_4 ( V_170 , V_186 , V_1 , V_9 , 2 , V_8 ) ;
F_4 ( V_170 , V_187 , V_1 , V_9 , 2 , V_8 ) ;
V_115 = F_44 ( V_1 , V_9 ) ;
V_172 = F_45 ( 0 , V_1 , V_9 , V_115 ) ;
V_9 += 2 ;
F_4 ( V_170 , V_188 , V_1 , V_9 , 44 , V_18 ) ;
V_9 += 44 ;
F_4 ( V_170 , V_189 , V_1 , V_9 , 2 , V_8 ) ;
V_3 = F_4 ( V_170 , V_190 , V_1 , V_9 , 2 , V_8 ) ;
F_34 ( V_3 , L_24 , ( V_172 == 0 ) ? L_16 : L_17 ) ;
break;
case V_191 :
if ( V_169 )
{
F_18 ( V_45 -> V_49 , V_99 , L_25 ) ;
F_42 ( V_45 -> V_49 , V_50 ) ;
}
V_3 = F_4 ( V_2 , V_192 , V_1 , V_9 , - 1 , V_18 ) ;
V_170 = F_3 ( V_3 , V_193 ) ;
V_148 = F_10 ( V_1 , V_9 ) ;
if ( V_169 )
{
F_43 ( V_45 -> V_49 , V_50 , L_26 ,
F_11 ( V_148 >> 4 , V_194 , L_23 ) ) ;
}
F_4 ( V_170 , V_195 , V_1 , V_9 , 1 , V_8 ) ;
switch ( V_148 >> 4 ) {
case V_196 :
F_4 ( V_170 , V_197 , V_1 , V_9 , 1 , V_8 ) ;
break;
case V_198 :
F_4 ( V_170 , V_199 , V_1 , V_9 , 1 , V_8 ) ;
break;
case V_200 :
F_4 ( V_170 , V_201 , V_1 , V_9 , 1 , V_8 ) ;
break;
default:
F_4 ( V_170 , V_202 , V_1 , V_9 , 1 , V_8 ) ;
break;
}
V_115 = F_44 ( V_1 , V_9 ) ;
V_172 = F_45 ( 0 , V_1 , V_9 , V_115 ) ;
V_9 += 1 ;
F_4 ( V_170 , V_203 , V_1 , V_9 , 45 , V_18 ) ;
V_9 += 45 ;
V_3 = F_4 ( V_170 , V_204 , V_1 , V_9 , 2 , V_8 ) ;
F_34 ( V_3 , L_24 , ( V_172 == 0 ) ? L_16 : L_17 ) ;
break;
default:
V_97 = F_23 ( V_1 , V_9 ) ;
F_25 ( V_97 , V_45 , V_2 ) ;
break;
}
}
T_9
F_46 ( const T_4 V_132 , const T_7 V_205 )
{
return ( ( ( V_132 == 3 || V_132 == 4 ) && ( ( V_205 & 0x5 ) == 0 ) )
|| ( ( V_205 & 0x6 ) == 0x4 ) ) ;
}
static void
F_47 ( T_1 * V_1 , T_8 * V_45 , T_2 * V_2 ,
T_2 * V_112 , T_5 V_109 , T_9 V_206 ,
T_9 V_207 )
{
int V_9 ;
T_3 * V_3 ;
T_7 V_148 , V_205 ;
int V_208 ;
T_4 V_130 , V_132 ;
if ( ! V_206 ) {
V_148 = F_10 ( V_1 , 0 ) ;
F_4 ( V_112 , V_209 , V_1 , 0 , 1 , V_18 ) ;
V_130 = ( V_148 & 0xF ) << 4 ;
V_148 = F_10 ( V_1 , 1 ) ;
V_130 |= V_148 >> 4 ;
F_31 ( V_112 , V_129 , V_1 , 0 , 2 , V_130 ) ;
} else {
V_148 = F_10 ( V_1 , 0 ) ;
V_130 = V_148 << 4 ;
V_148 = F_10 ( V_1 , 1 ) ;
V_130 |= ( V_148 & 0xF0 ) >> 4 ;
F_31 ( V_112 , V_129 , V_1 , 0 , 2 , V_130 ) ;
}
V_132 = ( V_148 & 0x0F ) << 12 ;
V_148 = F_10 ( V_1 , 2 ) ;
V_132 |= V_148 << 4 ;
V_148 = F_10 ( V_1 , 3 ) ;
V_132 |= V_148 >> 4 ;
F_31 ( V_112 , V_131 , V_1 , 1 , 3 , V_132 ) ;
V_205 = ( V_148 >> 1 ) & 0x7 ;
F_4 ( V_112 , V_210 , V_1 , 3 , 1 , V_8 ) ;
F_4 ( V_112 , V_211 , V_1 , 3 , 1 , V_8 ) ;
if ( ! V_207 ) {
V_3 = F_4 ( V_112 , V_212 , V_1 , 4 , 1 , V_8 ) ;
V_208 = F_40 ( ( const T_7 * ) F_48 ( F_49 () , V_1 , 0 , 5 ) ) ;
if ( V_208 == V_167 )
F_34 ( V_3 , L_16 ) ;
else if ( V_208 == V_168 )
F_34 ( V_3 , L_27 ) ;
else
F_34 ( V_3 , L_28 , V_208 ) ;
V_9 = 5 ;
} else {
V_9 = 4 ;
}
if ( V_109 == V_213 || V_109 == V_214 ) {
if ( F_46 ( V_132 , V_205 ) ) {
V_109 = V_191 ;
}
}
F_41 ( V_1 , V_9 , V_45 , V_2 , V_109 , TRUE ) ;
}
static int
F_50 ( T_1 * V_1 , T_8 * V_45 , T_2 * V_2 ,
T_9 V_113 , struct V_95 * V_96 , T_9 V_114 )
{
T_2 * V_112 = NULL ;
T_3 * V_111 = NULL ;
if ( V_96 -> V_109 == V_110 && V_96 -> type == V_125 &&
V_215 ) {
V_96 -> V_109 = V_144 ;
}
F_18 ( V_45 -> V_49 , V_99 , L_29 ) ;
if ( ! V_114 ) {
switch ( V_96 -> V_216 ) {
case 0 :
F_18 ( V_45 -> V_49 , V_217 , L_30 ) ;
F_18 ( V_45 -> V_49 , V_218 , L_31 ) ;
break;
case 1 :
F_18 ( V_45 -> V_49 , V_217 , L_31 ) ;
F_18 ( V_45 -> V_49 , V_218 , L_30 ) ;
break;
}
}
if ( V_96 -> V_109 == V_110 ) {
F_43 ( V_45 -> V_49 , V_50 , L_32 ,
F_11 ( V_96 -> type , V_219 ,
L_33 ) ) ;
} else {
F_51 ( V_45 -> V_49 , V_50 ,
F_11 ( V_96 -> V_109 , V_220 ,
L_34 ) ) ;
}
if ( V_2 ) {
V_111 = F_4 ( V_2 , V_221 , V_1 , 0 , - 1 , V_18 ) ;
V_112 = F_3 ( V_111 , V_222 ) ;
if ( ! V_114 ) {
F_31 ( V_112 , V_223 , V_1 , 0 , 0 , V_96 -> V_216 ) ;
if ( V_96 -> V_133 & V_134 )
F_52 ( V_45 , V_111 , & V_224 ) ;
}
F_53 ( V_112 , V_225 , V_1 , 0 , 0 ,
V_96 -> V_109 ,
L_26 ,
F_11 ( V_96 -> V_109 , V_220 ,
L_34 ) ) ;
}
if ( V_96 -> V_133 & V_226 ) {
if ( V_96 -> V_133 & V_227 ) {
F_54 ( V_111 , 4 ) ;
} else {
F_54 ( V_111 , 5 ) ;
}
F_47 ( V_1 , V_45 , V_2 , V_112 ,
V_96 -> V_109 , FALSE ,
V_96 -> V_133 & V_227 ) ;
} else {
F_30 ( V_1 , V_45 , V_2 , V_112 , V_111 , V_113 ,
V_96 , V_114 ) ;
}
return F_32 ( V_1 ) ;
}
static int
F_55 ( T_1 * V_1 , T_8 * V_45 , T_2 * V_2 , void * V_94 )
{
struct V_95 * V_96 = (struct V_95 * ) V_94 ;
F_56 ( V_96 != NULL ) ;
return F_50 ( V_1 , V_45 , V_2 , TRUE , V_96 , FALSE ) ;
}
static int
F_57 ( T_1 * V_1 , T_8 * V_45 , T_2 * V_2 , void * V_94 )
{
struct V_95 * V_96 = (struct V_95 * ) V_94 ;
F_56 ( V_96 != NULL ) ;
return F_50 ( V_1 , V_45 , V_2 , TRUE , V_96 , TRUE ) ;
}
static int
F_58 ( T_1 * V_1 , T_8 * V_45 , T_2 * V_2 , void * V_94 )
{
struct V_95 * V_96 = (struct V_95 * ) V_94 ;
F_56 ( V_96 != NULL ) ;
return F_50 ( V_1 , V_45 , V_2 , FALSE , V_96 , FALSE ) ;
}
static int
F_59 ( T_1 * V_1 , T_8 * V_45 , T_2 * V_2 , void * V_94 )
{
struct V_95 * V_96 = (struct V_95 * ) V_94 ;
F_56 ( V_96 != NULL ) ;
return F_50 ( V_1 , V_45 , V_2 , FALSE , V_96 , TRUE ) ;
}
static int
F_60 ( T_1 * V_1 , T_8 * V_45 , T_2 * V_2 , void * V_94 V_87 )
{
T_2 * V_112 ;
T_3 * V_111 ;
F_18 ( V_45 -> V_49 , V_99 , L_29 ) ;
V_111 = F_4 ( V_2 , V_221 , V_1 , 0 , 0 , V_18 ) ;
V_112 = F_3 ( V_111 , V_222 ) ;
F_47 ( V_1 , V_45 , V_2 , V_112 , V_191 , FALSE , FALSE ) ;
return F_32 ( V_1 ) ;
}
static int
F_61 ( T_1 * V_1 , T_8 * V_45 , T_2 * V_2 , void * V_94 )
{
const T_13 * V_228 = ( const T_13 * ) V_94 ;
F_18 ( V_45 -> V_49 , V_99 , L_29 ) ;
F_41 ( V_1 , 0 , V_45 , V_2 , V_191 ,
V_228 -> V_229 ) ;
return F_32 ( V_1 ) ;
}
static void F_62 ( T_8 * V_45 V_87 , T_14 * V_230 )
{
F_63 ( V_230 , V_231 , L_35 ) ;
}
static T_15 F_64 ( T_8 * V_45 )
{
return F_65 ( ( T_5 ) V_45 -> V_91 -> V_92 . type ) ;
}
void
F_66 ( void )
{
static T_16 V_232 [] = {
{ & V_225 ,
{ L_36 , L_37 , V_233 , V_234 , F_67 ( V_220 ) , 0x0 ,
NULL , V_235 } } ,
{ & V_209 ,
{ L_38 , L_39 , V_233 , V_234 , NULL , 0xF0 ,
NULL , V_235 } } ,
{ & V_129 ,
{ L_40 , L_41 , V_233 , V_234 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_131 ,
{ L_42 , L_43 , V_236 , V_234 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_156 ,
{ L_44 , L_45 , V_233 , V_234 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_41 ,
{ L_46 , L_47 , V_237 , V_238 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_7 ,
{ L_48 , L_49 , V_236 , V_239 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_15 ,
{ L_50 , L_51 , V_236 , V_239 , F_67 ( V_240 ) , 0x0 ,
NULL , V_235 } } ,
{ & V_17 ,
{ L_52 , L_53 , V_241 , V_238 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_31 ,
{ L_54 , L_55 , V_242 , V_239 , F_67 ( V_30 ) , 0x0 ,
NULL , V_235 } } ,
{ & V_32 ,
{ L_56 , L_57 , V_233 , V_234 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_20 ,
{ L_58 , L_59 , V_236 , V_239 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_23 ,
{ L_60 , L_61 , V_236 , V_234 , NULL , 0xFFF0 ,
NULL , V_235 } } ,
{ & V_24 ,
{ L_62 , L_63 , V_236 , V_234 , NULL , 0x000F ,
NULL , V_235 } } ,
{ & V_34 ,
{ L_64 , L_65 , V_237 , V_238 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_39 ,
{ L_66 , L_67 , V_237 , V_238 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_35 ,
{ L_68 , L_69 , V_233 , V_239 , F_67 ( V_243 ) , 0x0 ,
NULL , V_235 } } ,
{ & V_36 ,
{ L_70 , L_71 , V_233 , V_239 , F_67 ( V_244 ) , 0x0 ,
NULL , V_235 } } ,
{ & V_37 ,
{ L_72 , L_73 , V_233 , V_234 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_38 ,
{ L_74 , L_75 , V_233 , V_234 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_42 ,
{ L_72 , L_76 , V_233 , V_234 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_43 ,
{ L_72 , L_77 , V_233 , V_234 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_44 ,
{ L_72 , L_78 , V_233 , V_234 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_40 ,
{ L_79 , L_80 , V_237 , V_238 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_51 ,
{ L_81 , L_82 , V_236 , V_239 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_52 ,
{ L_83 , L_84 , V_233 , V_239 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_53 ,
{ L_85 , L_86 , V_233 , V_239 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_55 ,
{ L_87 , L_88 , V_236 , V_239 , F_67 ( V_54 ) , 0x0 ,
NULL , V_235 } } ,
{ & V_58 ,
{ L_89 , L_90 , V_236 , V_239 , F_67 ( V_245 ) , 0x0 ,
NULL , V_235 } } ,
{ & V_59 ,
{ L_91 , L_92 , V_242 , V_239 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_60 ,
{ L_93 , L_94 , V_236 , V_239 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_61 ,
{ L_95 , L_96 , V_236 , V_239 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_65 ,
{ L_97 , L_98 , V_246 , 16 , F_68 ( & V_247 ) , 0x0002 ,
NULL , V_235 } } ,
{ & V_68 ,
{ L_99 , L_100 , V_246 , 16 , F_68 ( & V_247 ) , 0x0004 ,
NULL , V_235 } } ,
{ & V_69 ,
{ L_101 , L_102 , V_246 , 16 , F_68 ( & V_247 ) , 0x0008 ,
NULL , V_235 } } ,
{ & V_70 ,
{ L_103 , L_104 , V_246 , 16 , F_68 ( & V_247 ) , 0x0080 ,
NULL , V_235 } } ,
{ & V_71 ,
{ L_105 , L_106 , V_246 , 16 , F_68 ( & V_247 ) , 0x0200 ,
NULL , V_235 } } ,
{ & V_79 ,
{ L_107 , L_108 , V_246 , 16 , F_68 ( & V_247 ) , 0x0001 ,
NULL , V_235 } } ,
{ & V_81 ,
{ L_109 , L_110 , V_246 , 16 , F_68 ( & V_248 ) , 0x0100 ,
NULL , V_235 } } ,
{ & V_122 ,
{ L_111 , L_112 , V_233 , V_234 , F_67 ( V_219 ) , 0x0 ,
NULL , V_235 } } ,
{ & V_124 ,
{ L_113 , L_114 , V_233 , V_234 , F_67 ( V_249 ) , 0x0 ,
NULL , V_235 } } ,
{ & V_126 ,
{ L_115 , L_116 , V_233 , V_234 , F_67 ( V_250 ) , 0x0 ,
NULL , V_235 } } ,
{ & V_128 ,
{ L_117 , L_118 , V_233 , V_234 , F_67 ( V_251 ) , 0x0 ,
NULL , V_235 } } ,
{ & V_136 ,
{ L_119 , L_120 , V_236 , V_234 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_137 ,
{ L_121 , L_122 , V_233 , V_239 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_139 ,
{ L_123 , L_124 , V_233 , V_239 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_140 ,
{ L_125 , L_126 , V_236 , V_234 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_142 ,
{ L_127 , L_128 , V_242 , V_239 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_210 ,
{ L_129 , L_130 , V_233 , V_234 , NULL , 0x0E ,
NULL , V_235 } } ,
{ & V_211 ,
{ L_131 , L_132 , V_246 , 8 , F_68 ( & V_252 ) , 0x01 ,
NULL , V_235 } } ,
{ & V_212 ,
{ L_133 , L_134 , V_233 , V_239 , NULL , 0 ,
NULL , V_235 } } ,
{ & V_223 ,
{ L_135 , L_136 , V_236 , V_234 , F_67 ( V_253 ) , 0 ,
NULL , V_235 } } ,
{ & V_176 ,
{ L_137 , L_138 , V_233 , V_234 , NULL , 0x80 ,
NULL , V_235 } } ,
{ & V_177 ,
{ L_139 , L_140 , V_233 , V_234 , NULL , 0x70 ,
NULL , V_235 } } ,
{ & V_178 ,
{ L_141 , L_142 , V_233 , V_234 , NULL , 0x08 ,
NULL , V_235 } } ,
{ & V_179 ,
{ L_143 , L_144 , V_233 , V_234 , NULL , 0x07 ,
NULL , V_235 } } ,
{ & V_180 ,
{ L_145 , L_146 , V_237 , V_238 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_185 ,
{ L_147 , L_148 , V_236 , V_234 , F_67 ( V_184 ) , 0xC000 ,
NULL , V_235 } } ,
{ & V_186 ,
{ L_149 , L_150 , V_236 , V_234 , NULL , 0x3C00 ,
NULL , V_235 } } ,
{ & V_187 ,
{ L_151 , L_152 , V_236 , V_234 , NULL , 0x03FF ,
NULL , V_235 } } ,
{ & V_188 ,
{ L_153 , L_154 , V_237 , V_238 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_189 ,
{ L_155 , L_156 , V_236 , V_234 , F_67 ( V_184 ) , 0xFC00 ,
NULL , V_235 } } ,
{ & V_190 ,
{ L_141 , L_157 , V_236 , V_234 , NULL , 0x03FF ,
NULL , V_235 } } ,
{ & V_195 ,
{ L_158 , L_159 , V_233 , V_234 , F_67 ( V_194 ) , 0xF0 ,
NULL , V_235 } } ,
{ & V_197 ,
{ L_160 , L_161 , V_233 , V_234 , F_67 ( V_254 ) , 0x0F ,
NULL , V_235 } } ,
{ & V_199 ,
{ L_160 , L_162 , V_233 , V_234 , F_67 ( V_255 ) , 0x0F ,
NULL , V_235 } } ,
{ & V_201 ,
{ L_160 , L_163 , V_233 , V_234 , F_67 ( V_256 ) , 0x0F ,
NULL , V_235 } } ,
{ & V_202 ,
{ L_160 , L_164 , V_233 , V_234 , NULL , 0x0F ,
NULL , V_235 } } ,
{ & V_203 ,
{ L_165 , L_166 , V_237 , V_238 , NULL , 0x0 ,
NULL , V_235 } } ,
{ & V_204 ,
{ L_167 , L_168 , V_236 , V_239 , NULL , 0x3FF ,
NULL , V_235 } } ,
{ & V_145 ,
{ L_169 , L_170 , V_237 , V_238 , NULL , 0x0 ,
NULL , V_235 } } ,
} ;
static T_12 * V_257 [] = {
& V_222 ,
& V_108 ,
& V_175 ,
& V_183 ,
& V_193 ,
& V_6 ,
& V_14 ,
& V_22 ,
& V_62 ,
& V_29 ,
} ;
static T_17 V_258 [] = {
{ & V_224 , { L_171 , V_259 , V_260 , L_172 , V_261 } } ,
} ;
T_18 * V_262 ;
T_19 * V_263 ;
static T_20 V_264 [ 1 ] = { F_64 } ;
static T_21 V_265 = { F_62 , 1 , V_264 } ;
static T_22 V_266 = { L_173 , L_174 , L_175 , 1 , 0 , & V_265 , NULL , NULL ,
V_267 , V_268 , V_269 , NULL } ;
V_221 = F_69 ( L_176 , L_29 , L_173 ) ;
V_174 = F_69 ( L_177 , L_19 , L_178 ) ;
V_182 = F_69 ( L_179 , L_21 , L_180 ) ;
V_192 = F_69 ( L_181 , L_25 , L_182 ) ;
F_70 ( V_221 , V_232 , F_71 ( V_232 ) ) ;
F_72 ( V_257 , F_71 ( V_257 ) ) ;
V_262 = F_73 ( V_221 ) ;
F_74 ( V_262 , V_258 , F_71 ( V_258 ) ) ;
V_107 = F_69 ( L_183 , L_183 , L_184 ) ;
V_5 = F_69 ( L_185 , L_1 , L_186 ) ;
V_159 = F_75 ( L_175 , L_187 , V_221 , V_242 , V_234 ) ;
V_147 = F_75 ( L_14 , L_188 , V_221 , V_242 , V_234 ) ;
F_76 ( L_14 , L_189 ) ;
F_76 ( L_10 , L_185 ) ;
V_270 = F_77 ( L_190 , F_55 , V_221 ) ;
F_77 ( L_191 , F_57 , V_221 ) ;
V_271 = F_77 ( L_192 , F_58 , V_221 ) ;
F_77 ( L_193 , F_59 , V_221 ) ;
F_77 ( L_194 , F_60 , V_192 ) ;
F_77 ( L_195 , F_61 , V_192 ) ;
V_263 = F_78 ( V_221 , NULL ) ;
F_79 ( V_263 , L_196 , L_197 ,
L_198 ,
& V_215 ) ;
F_80 ( V_263 , L_199 ) ;
F_81 ( & V_266 ) ;
}
void
F_82 ( void )
{
V_103 = F_83 ( L_200 , V_5 ) ;
V_106 = F_83 ( L_201 , V_5 ) ;
V_153 = F_83 ( L_202 , V_221 ) ;
V_149 = F_83 ( L_203 , V_221 ) ;
V_146 = F_83 ( L_204 , V_221 ) ;
V_151 = F_83 ( L_205 , V_221 ) ;
V_152 = F_83 ( L_206 , V_221 ) ;
V_154 = F_83 ( L_207 , V_221 ) ;
F_84 ( L_208 , V_272 , V_270 ) ;
F_84 ( L_14 , V_125 , F_85 ( F_22 , V_5 ) ) ;
F_84 ( L_14 , V_273 , F_85 ( F_27 , V_107 ) ) ;
F_84 ( L_208 , V_274 ,
V_271 ) ;
F_86 ( L_208 , V_272 , F_29 , V_221 ) ;
F_86 ( L_14 , V_125 , F_20 , V_5 ) ;
}
