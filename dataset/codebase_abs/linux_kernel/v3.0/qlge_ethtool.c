static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 = 0 ;
struct V_5 * V_5 ;
struct V_6 * V_6 ;
if ( ! F_2 ( V_2 -> V_7 ) )
return V_4 ;
V_6 = (struct V_6 * ) & V_2 -> V_5 [ V_2 -> V_8 ] ;
if ( F_3 ( V_6 -> V_9 ) != V_2 -> V_10 ||
F_3 ( V_6 -> V_11 ) !=
V_2 -> V_12 ) {
for ( V_3 = V_2 -> V_8 ; V_3 < V_2 -> V_13 ; V_3 ++ ) {
V_5 = & V_2 -> V_5 [ V_3 ] ;
V_6 = (struct V_6 * ) V_5 ;
V_6 -> V_9 = F_4 ( V_2 -> V_10 ) ;
V_6 -> V_11 =
F_4 ( V_2 -> V_12 ) ;
V_6 -> V_14 = V_15 ;
V_4 = F_5 ( V_2 , V_6 , sizeof( * V_6 ) ,
V_16 , V_5 -> V_17 ) ;
if ( V_4 ) {
F_6 ( V_2 , V_18 , V_2 -> V_7 ,
L_1 ) ;
goto exit;
}
}
}
V_6 = (struct V_6 * ) & V_2 -> V_5 [ 0 ] ;
if ( F_3 ( V_6 -> V_9 ) != V_2 -> V_19 ||
F_3 ( V_6 -> V_11 ) !=
V_2 -> V_20 ) {
for ( V_3 = 0 ; V_3 < V_2 -> V_8 ; V_3 ++ , V_5 ++ ) {
V_5 = & V_2 -> V_5 [ V_3 ] ;
V_6 = (struct V_6 * ) V_5 ;
V_6 -> V_9 = F_4 ( V_2 -> V_19 ) ;
V_6 -> V_11 =
F_4 ( V_2 -> V_20 ) ;
V_6 -> V_14 = V_15 ;
V_4 = F_5 ( V_2 , V_6 , sizeof( * V_6 ) ,
V_16 , V_5 -> V_17 ) ;
if ( V_4 ) {
F_6 ( V_2 , V_18 , V_2 -> V_7 ,
L_1 ) ;
goto exit;
}
}
}
exit:
return V_4 ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_2 V_21 ;
T_2 * V_22 = & V_2 -> V_23 . V_24 ;
F_8 ( & V_2 -> V_25 ) ;
if ( F_9 ( V_2 , V_2 -> V_26 ) ) {
F_6 ( V_2 , V_27 , V_2 -> V_7 ,
L_2 ) ;
goto V_28;
}
for ( V_3 = 0x200 ; V_3 < 0x280 ; V_3 += 8 ) {
if ( F_10 ( V_2 , V_3 , & V_21 ) ) {
F_6 ( V_2 , V_27 , V_2 -> V_7 ,
L_3 ,
V_3 ) ;
goto V_29;
} else
* V_22 = V_21 ;
V_22 ++ ;
}
for ( V_3 = 0x300 ; V_3 < 0x3d0 ; V_3 += 8 ) {
if ( F_10 ( V_2 , V_3 , & V_21 ) ) {
F_6 ( V_2 , V_27 , V_2 -> V_7 ,
L_3 ,
V_3 ) ;
goto V_29;
} else
* V_22 = V_21 ;
V_22 ++ ;
}
for ( V_3 = 0x500 ; V_3 < 0x540 ; V_3 += 8 ) {
if ( F_10 ( V_2 , V_3 , & V_21 ) ) {
F_6 ( V_2 , V_27 , V_2 -> V_7 ,
L_3 ,
V_3 ) ;
goto V_29;
} else
* V_22 = V_21 ;
V_22 ++ ;
}
for ( V_3 = 0x568 ; V_3 < 0x5a8 ; V_3 += 8 ) {
if ( F_10 ( V_2 , V_3 , & V_21 ) ) {
F_6 ( V_2 , V_27 , V_2 -> V_7 ,
L_3 ,
V_3 ) ;
goto V_29;
} else
* V_22 = V_21 ;
V_22 ++ ;
}
if ( F_10 ( V_2 , 0x5b8 , & V_21 ) ) {
F_6 ( V_2 , V_27 , V_2 -> V_7 ,
L_3 , V_3 ) ;
goto V_29;
} else
* V_22 = V_21 ;
V_29:
F_11 ( V_2 , V_2 -> V_26 ) ;
V_28:
F_12 ( & V_2 -> V_25 ) ;
F_13 ( V_2 ) ;
}
static void F_14 ( struct V_30 * V_31 , T_1 V_32 , T_3 * V_33 )
{
switch ( V_32 ) {
case V_34 :
memcpy ( V_33 , V_35 , sizeof( V_35 ) ) ;
break;
}
}
static int F_15 ( struct V_30 * V_31 , int V_36 )
{
switch ( V_36 ) {
case V_37 :
return V_38 ;
case V_34 :
return F_16 ( V_35 ) ;
default:
return - V_39 ;
}
}
static void
F_17 ( struct V_30 * V_7 ,
struct V_40 * V_41 , T_2 * V_21 )
{
struct V_1 * V_2 = F_18 ( V_7 ) ;
struct V_23 * V_42 = & V_2 -> V_23 ;
F_7 ( V_2 ) ;
* V_21 ++ = V_42 -> V_24 ;
* V_21 ++ = V_42 -> V_43 ;
* V_21 ++ = V_42 -> V_44 ;
* V_21 ++ = V_42 -> V_45 ;
* V_21 ++ = V_42 -> V_46 ;
* V_21 ++ = V_42 -> V_47 ;
* V_21 ++ = V_42 -> V_48 ;
* V_21 ++ = V_42 -> V_49 ;
* V_21 ++ = V_42 -> V_50 ;
* V_21 ++ = V_42 -> V_51 ;
* V_21 ++ = V_42 -> V_52 ;
* V_21 ++ = V_42 -> V_53 ;
* V_21 ++ = V_42 -> V_54 ;
* V_21 ++ = V_42 -> V_55 ;
* V_21 ++ = V_42 -> V_56 ;
* V_21 ++ = V_42 -> V_57 ;
* V_21 ++ = V_42 -> V_58 ;
* V_21 ++ = V_42 -> V_59 ;
* V_21 ++ = V_42 -> V_60 ;
* V_21 ++ = V_42 -> V_61 ;
* V_21 ++ = V_42 -> V_62 ;
* V_21 ++ = V_42 -> V_63 ;
* V_21 ++ = V_42 -> V_64 ;
* V_21 ++ = V_42 -> V_65 ;
* V_21 ++ = V_42 -> V_66 ;
* V_21 ++ = V_42 -> V_67 ;
* V_21 ++ = V_42 -> V_68 ;
* V_21 ++ = V_42 -> V_69 ;
* V_21 ++ = V_42 -> V_70 ;
* V_21 ++ = V_42 -> V_71 ;
* V_21 ++ = V_42 -> V_72 ;
* V_21 ++ = V_42 -> V_73 ;
* V_21 ++ = V_42 -> V_74 ;
* V_21 ++ = V_42 -> V_75 ;
* V_21 ++ = V_42 -> V_76 ;
* V_21 ++ = V_42 -> V_77 ;
* V_21 ++ = V_42 -> V_78 ;
* V_21 ++ = V_42 -> V_79 ;
* V_21 ++ = V_42 -> V_80 ;
* V_21 ++ = V_42 -> V_81 ;
* V_21 ++ = V_42 -> V_82 ;
* V_21 ++ = V_42 -> V_83 ;
* V_21 ++ = V_42 -> V_84 ;
* V_21 ++ = V_42 -> V_85 ;
* V_21 ++ = V_42 -> V_86 ;
* V_21 ++ = V_42 -> V_87 ;
* V_21 ++ = V_42 -> V_88 ;
* V_21 ++ = V_42 -> V_89 ;
* V_21 ++ = V_42 -> V_90 ;
* V_21 ++ = V_42 -> V_91 ;
* V_21 ++ = V_42 -> V_92 ;
* V_21 ++ = V_42 -> V_93 ;
* V_21 ++ = V_42 -> V_94 ;
* V_21 ++ = V_42 -> V_95 ;
* V_21 ++ = V_42 -> V_96 ;
* V_21 ++ = V_42 -> V_97 ;
* V_21 ++ = V_42 -> V_98 ;
* V_21 ++ = V_42 -> V_99 ;
* V_21 ++ = V_42 -> V_100 ;
}
static int F_19 ( struct V_30 * V_7 ,
struct V_101 * V_102 )
{
struct V_1 * V_2 = F_18 ( V_7 ) ;
V_102 -> V_103 = V_104 ;
V_102 -> V_105 = V_106 ;
V_102 -> V_107 = V_108 ;
V_102 -> V_109 = V_110 ;
if ( ( V_2 -> V_111 & V_112 ) ==
V_113 ) {
V_102 -> V_103 |= ( V_114 | V_115 ) ;
V_102 -> V_105 |= ( V_116 | V_117 ) ;
V_102 -> V_118 = V_119 ;
} else {
V_102 -> V_103 |= V_120 ;
V_102 -> V_105 |= V_121 ;
V_102 -> V_118 = V_122 ;
}
F_20 ( V_102 , V_123 ) ;
V_102 -> V_124 = V_125 ;
return 0 ;
}
static void F_21 ( struct V_30 * V_7 ,
struct V_126 * V_127 )
{
struct V_1 * V_2 = F_18 ( V_7 ) ;
strncpy ( V_127 -> V_128 , V_129 , 32 ) ;
strncpy ( V_127 -> V_130 , V_131 , 32 ) ;
snprintf ( V_127 -> V_132 , 32 , L_4 ,
( V_2 -> V_133 & 0x00ff0000 ) >> 16 ,
( V_2 -> V_133 & 0x0000ff00 ) >> 8 ,
( V_2 -> V_133 & 0x000000ff ) ) ;
strncpy ( V_127 -> V_134 , F_22 ( V_2 -> V_135 ) , 32 ) ;
V_127 -> V_136 = 0 ;
V_127 -> V_137 = 0 ;
if ( ! F_23 ( V_138 , & V_2 -> V_14 ) )
V_127 -> V_139 = sizeof( struct V_140 ) ;
else
V_127 -> V_139 = sizeof( struct V_141 ) ;
V_127 -> V_142 = 0 ;
}
static void F_24 ( struct V_30 * V_7 , struct V_143 * V_144 )
{
struct V_1 * V_2 = F_18 ( V_7 ) ;
V_144 -> V_103 = V_145 ;
V_144 -> V_146 = V_2 -> V_144 ;
}
static int F_25 ( struct V_30 * V_7 , struct V_143 * V_144 )
{
struct V_1 * V_2 = F_18 ( V_7 ) ;
int V_4 ;
if ( V_144 -> V_146 & ~ V_145 )
return - V_147 ;
V_2 -> V_144 = V_144 -> V_146 ;
F_26 ( V_2 , V_27 , V_2 -> V_7 , L_5 , V_2 -> V_144 ) ;
if ( ! V_2 -> V_144 ) {
T_1 V_144 = 0 ;
V_4 = F_27 ( V_2 , V_144 ) ;
F_6 ( V_2 , V_27 , V_2 -> V_7 , L_6 ,
V_4 == 0 ? L_7 : L_8 ,
V_144 ) ;
}
return 0 ;
}
static int F_28 ( struct V_30 * V_7 ,
enum V_148 V_149 )
{
struct V_1 * V_2 = F_18 ( V_7 ) ;
switch ( V_149 ) {
case V_150 :
if ( F_29 ( V_2 ) )
return - V_151 ;
F_30 ( V_2 , V_152 ) ;
return 0 ;
case V_153 :
if ( F_30 ( V_2 , V_2 -> V_154 ) )
return - V_151 ;
return 0 ;
default:
return - V_147 ;
}
}
static int F_31 ( struct V_1 * V_2 )
{
if ( F_32 ( V_2 -> V_7 ) ) {
F_33 ( V_155 , & V_2 -> V_14 ) ;
F_34 ( V_2 -> V_7 ) ;
} else
F_35 ( V_155 , & V_2 -> V_14 ) ;
V_2 -> V_156 |= V_157 ;
return F_36 ( V_2 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
V_2 -> V_156 &= ~ V_157 ;
F_36 ( V_2 ) ;
if ( F_23 ( V_155 , & V_2 -> V_14 ) ) {
F_38 ( V_2 -> V_7 ) ;
F_35 ( V_155 , & V_2 -> V_14 ) ;
}
}
static void F_39 ( struct V_158 * V_159 ,
unsigned int V_160 )
{
memset ( V_159 -> V_21 , 0xFF , V_160 ) ;
V_160 &= ~ 1 ;
memset ( & V_159 -> V_21 [ V_160 / 2 ] , 0xAA , V_160 / 2 - 1 ) ;
memset ( & V_159 -> V_21 [ V_160 / 2 + 10 ] , 0xBE , 1 ) ;
memset ( & V_159 -> V_21 [ V_160 / 2 + 12 ] , 0xAF , 1 ) ;
}
void F_40 ( struct V_1 * V_2 ,
struct V_158 * V_159 )
{
unsigned int V_160 = V_159 -> V_161 ;
if ( ( * ( V_159 -> V_21 + 3 ) == 0xFF ) &&
( * ( V_159 -> V_21 + V_160 / 2 + 10 ) == 0xBE ) &&
( * ( V_159 -> V_21 + V_160 / 2 + 12 ) == 0xAF ) ) {
F_41 ( & V_2 -> V_162 ) ;
return;
}
}
static int F_42 ( struct V_1 * V_2 )
{
int V_3 ;
T_4 V_163 ;
struct V_158 * V_159 ;
unsigned int V_164 = V_165 ;
for ( V_3 = 0 ; V_3 < 64 ; V_3 ++ ) {
V_159 = F_43 ( V_2 -> V_7 , V_164 ) ;
if ( ! V_159 )
return - V_166 ;
V_159 -> V_167 = 0 ;
F_44 ( V_159 , V_164 ) ;
F_39 ( V_159 , V_164 ) ;
V_163 = F_45 ( V_159 , V_2 -> V_7 ) ;
if ( V_163 != V_168 )
return - V_169 ;
F_46 ( & V_2 -> V_162 ) ;
}
F_47 ( 2 ) ;
F_48 ( & V_2 -> V_5 [ 0 ] , 128 ) ;
return F_49 ( & V_2 -> V_162 ) ? - V_151 : 0 ;
}
static int F_50 ( struct V_1 * V_2 , T_2 * V_21 )
{
* V_21 = F_31 ( V_2 ) ;
if ( * V_21 )
goto V_170;
* V_21 = F_42 ( V_2 ) ;
V_170:
F_37 ( V_2 ) ;
return * V_21 ;
}
static void F_51 ( struct V_30 * V_7 ,
struct V_171 * V_172 , T_2 * V_21 )
{
struct V_1 * V_2 = F_18 ( V_7 ) ;
if ( F_2 ( V_7 ) ) {
F_33 ( V_173 , & V_2 -> V_14 ) ;
if ( V_172 -> V_14 == V_174 ) {
if ( F_50 ( V_2 , & V_21 [ 0 ] ) )
V_172 -> V_14 |= V_175 ;
} else {
V_21 [ 0 ] = 0 ;
}
F_35 ( V_173 , & V_2 -> V_14 ) ;
F_52 ( 4 * 1000 ) ;
} else {
F_6 ( V_2 , V_27 , V_2 -> V_7 ,
L_9 ) ;
V_172 -> V_14 |= V_175 ;
}
}
static int F_53 ( struct V_30 * V_7 )
{
struct V_1 * V_2 = F_18 ( V_7 ) ;
if ( ! F_23 ( V_138 , & V_2 -> V_14 ) )
return sizeof( struct V_140 ) ;
else
return sizeof( struct V_141 ) ;
}
static void F_54 ( struct V_30 * V_7 ,
struct V_176 * V_177 , void * V_178 )
{
struct V_1 * V_2 = F_18 ( V_7 ) ;
F_55 ( V_2 , V_178 ) ;
V_2 -> V_179 = 0 ;
if ( ! F_23 ( V_138 , & V_2 -> V_14 ) )
V_177 -> V_161 = sizeof( struct V_140 ) ;
else
V_177 -> V_161 = sizeof( struct V_141 ) ;
}
static int F_56 ( struct V_30 * V_31 , struct V_180 * V_181 )
{
struct V_1 * V_2 = F_18 ( V_31 ) ;
V_181 -> V_19 = V_2 -> V_19 ;
V_181 -> V_10 = V_2 -> V_10 ;
V_181 -> V_20 = V_2 -> V_20 ;
V_181 -> V_12 = V_2 -> V_12 ;
return 0 ;
}
static int F_57 ( struct V_30 * V_7 , struct V_180 * V_181 )
{
struct V_1 * V_2 = F_18 ( V_7 ) ;
if ( V_181 -> V_19 > V_2 -> V_182 / 2 )
return - V_147 ;
if ( V_181 -> V_20 > V_183 )
return - V_147 ;
if ( V_181 -> V_10 > V_2 -> V_184 / 2 )
return - V_147 ;
if ( V_181 -> V_12 > V_183 )
return - V_147 ;
if ( V_2 -> V_19 == V_181 -> V_19 &&
V_2 -> V_10 == V_181 -> V_10 &&
V_2 -> V_20 == V_181 -> V_20 &&
V_2 -> V_12 == V_181 -> V_12 )
return 0 ;
V_2 -> V_19 = V_181 -> V_19 ;
V_2 -> V_10 = V_181 -> V_10 ;
V_2 -> V_20 = V_181 -> V_20 ;
V_2 -> V_12 = V_181 -> V_12 ;
return F_1 ( V_2 ) ;
}
static void F_58 ( struct V_30 * V_185 ,
struct V_186 * V_187 )
{
struct V_1 * V_2 = F_18 ( V_185 ) ;
F_59 ( V_2 ) ;
if ( V_2 -> V_156 & V_188 ) {
V_187 -> V_189 = 1 ;
V_187 -> V_190 = 1 ;
}
}
static int F_60 ( struct V_30 * V_185 ,
struct V_186 * V_187 )
{
struct V_1 * V_2 = F_18 ( V_185 ) ;
int V_4 = 0 ;
if ( ( V_187 -> V_189 ) && ( V_187 -> V_190 ) )
V_2 -> V_156 |= V_188 ;
else if ( ! V_187 -> V_189 && ! V_187 -> V_190 )
V_2 -> V_156 &= ~ V_188 ;
else
return - V_147 ;
V_4 = F_36 ( V_2 ) ;
if ( V_4 )
return V_4 ;
return V_4 ;
}
static T_1 F_61 ( struct V_30 * V_7 )
{
struct V_1 * V_2 = F_18 ( V_7 ) ;
return V_2 -> V_191 ;
}
static void F_62 ( struct V_30 * V_7 , T_1 V_192 )
{
struct V_1 * V_2 = F_18 ( V_7 ) ;
V_2 -> V_191 = V_192 ;
}
