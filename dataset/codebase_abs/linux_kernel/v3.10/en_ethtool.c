static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 = 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
V_2 -> V_6 [ V_3 ] . V_7 = V_2 -> V_8 ;
V_2 -> V_6 [ V_3 ] . V_9 = V_2 -> V_10 ;
V_4 = F_2 ( V_2 , & V_2 -> V_6 [ V_3 ] ) ;
if ( V_4 )
return V_4 ;
}
if ( V_2 -> V_11 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_12 ; V_3 ++ ) {
V_2 -> V_13 [ V_3 ] . V_7 = V_2 -> V_14 ;
V_2 -> V_13 [ V_3 ] . V_9 = V_2 -> V_15 ;
V_2 -> V_16 [ V_3 ] = V_17 ;
V_4 = F_2 ( V_2 , & V_2 -> V_13 [ V_3 ] ) ;
if ( V_4 )
return V_4 ;
}
return V_4 ;
}
static void
F_3 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
F_5 ( V_21 -> V_24 , V_25 , sizeof( V_21 -> V_24 ) ) ;
F_5 ( V_21 -> V_26 , V_27 L_1 V_28 L_2 ,
sizeof( V_21 -> V_26 ) ) ;
snprintf ( V_21 -> V_29 , sizeof( V_21 -> V_29 ) ,
L_3 ,
( V_30 ) ( V_23 -> V_19 -> V_31 . V_32 >> 32 ) ,
( V_30 ) ( ( V_23 -> V_19 -> V_31 . V_32 >> 16 ) & 0xffff ) ,
( V_30 ) ( V_23 -> V_19 -> V_31 . V_32 & 0xffff ) ) ;
F_5 ( V_21 -> V_33 , F_6 ( V_23 -> V_19 -> V_34 ) ,
sizeof( V_21 -> V_33 ) ) ;
V_21 -> V_35 = 0 ;
V_21 -> V_36 = 0 ;
V_21 -> V_37 = 0 ;
}
static T_1 F_7 ( struct V_18 * V_19 )
{
return ( (struct V_1 * ) F_4 ( V_19 ) ) -> V_38 ;
}
static void F_8 ( struct V_18 * V_19 , T_1 V_39 )
{
( (struct V_1 * ) F_4 ( V_19 ) ) -> V_38 = V_39 ;
}
static void F_9 ( struct V_18 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_4 ( V_40 ) ;
int V_4 = 0 ;
T_2 V_43 = 0 ;
T_2 V_44 ;
if ( ( V_2 -> V_45 < 1 ) || ( V_2 -> V_45 > 2 ) ) {
F_10 ( V_2 , L_4 ) ;
return;
}
V_44 = ( V_2 -> V_45 == 1 ) ? V_46 :
V_47 ;
if ( ! ( V_2 -> V_23 -> V_19 -> V_31 . V_48 & V_44 ) ) {
V_42 -> V_49 = 0 ;
V_42 -> V_50 = 0 ;
return;
}
V_4 = F_11 ( V_2 -> V_23 -> V_19 , & V_43 , V_2 -> V_45 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_4 ) ;
return;
}
if ( V_43 & V_51 )
V_42 -> V_49 = V_52 ;
else
V_42 -> V_49 = 0 ;
if ( V_43 & V_53 )
V_42 -> V_50 = V_52 ;
else
V_42 -> V_50 = 0 ;
}
static int F_12 ( struct V_18 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_4 ( V_40 ) ;
T_2 V_43 = 0 ;
int V_4 = 0 ;
T_2 V_44 ;
if ( ( V_2 -> V_45 < 1 ) || ( V_2 -> V_45 > 2 ) )
return - V_54 ;
V_44 = ( V_2 -> V_45 == 1 ) ? V_46 :
V_47 ;
if ( ! ( V_2 -> V_23 -> V_19 -> V_31 . V_48 & V_44 ) )
return - V_54 ;
if ( V_42 -> V_49 & ~ V_52 )
return - V_55 ;
V_4 = F_11 ( V_2 -> V_23 -> V_19 , & V_43 , V_2 -> V_45 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_5 ) ;
return V_4 ;
}
if ( V_42 -> V_50 & V_52 ) {
V_43 |= V_56 | V_53 |
V_51 ;
} else {
V_43 &= ~ ( V_53 | V_51 ) ;
V_43 |= V_56 ;
}
V_4 = F_13 ( V_2 -> V_23 -> V_19 , V_43 , V_2 -> V_45 ) ;
if ( V_4 )
F_10 ( V_2 , L_6 ) ;
return V_4 ;
}
static int F_14 ( struct V_18 * V_19 , int V_57 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
int V_58 = F_15 ( V_2 -> V_59 ) ;
switch ( V_57 ) {
case V_60 :
return ( V_2 -> V_59 ? V_58 : V_61 ) +
( V_2 -> V_5 + V_2 -> V_12 ) * 2 ;
case V_62 :
return V_63 - ! ( V_2 -> V_23 -> V_19 -> V_31 . V_48
& V_64 ) * 2 ;
default:
return - V_54 ;
}
}
static void F_16 ( struct V_18 * V_19 ,
struct V_65 * V_66 , T_3 * V_67 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
int V_68 = 0 ;
int V_3 , V_69 = 0 ;
F_17 ( & V_2 -> V_70 ) ;
if ( ! ( V_2 -> V_59 ) ) {
for ( V_3 = 0 ; V_3 < V_71 ; V_3 ++ )
V_67 [ V_68 ++ ] =
( ( unsigned long * ) & V_2 -> V_66 ) [ V_3 ] ;
for ( V_3 = 0 ; V_3 < V_72 ; V_3 ++ )
V_67 [ V_68 ++ ] =
( ( unsigned long * ) & V_2 -> V_73 ) [ V_3 ] ;
for ( V_3 = 0 ; V_3 < V_74 ; V_3 ++ )
V_67 [ V_68 ++ ] =
( ( unsigned long * ) & V_2 -> V_75 ) [ V_3 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_71 ; V_3 ++ ) {
if ( ( V_2 -> V_59 >> V_69 ) & 1 )
V_67 [ V_68 ++ ] =
( ( unsigned long * ) & V_2 -> V_66 ) [ V_3 ] ;
V_69 ++ ;
}
for ( V_3 = 0 ; V_3 < V_72 ; V_3 ++ ) {
if ( ( V_2 -> V_59 >> V_69 ) & 1 )
V_67 [ V_68 ++ ] =
( ( unsigned long * ) & V_2 -> V_73 ) [ V_3 ] ;
V_69 ++ ;
}
}
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
V_67 [ V_68 ++ ] = V_2 -> V_76 [ V_3 ] . V_77 ;
V_67 [ V_68 ++ ] = V_2 -> V_76 [ V_3 ] . V_78 ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_12 ; V_3 ++ ) {
V_67 [ V_68 ++ ] = V_2 -> V_79 [ V_3 ] . V_77 ;
V_67 [ V_68 ++ ] = V_2 -> V_79 [ V_3 ] . V_78 ;
}
F_18 ( & V_2 -> V_70 ) ;
}
static void F_19 ( struct V_18 * V_19 ,
struct V_80 * V_81 , T_2 * V_82 )
{
F_20 ( V_19 , & V_81 -> V_48 , V_82 ) ;
}
static void F_21 ( struct V_18 * V_19 ,
T_4 V_83 , T_5 * V_67 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
int V_68 = 0 ;
int V_3 ;
switch ( V_83 ) {
case V_62 :
for ( V_3 = 0 ; V_3 < V_63 - 2 ; V_3 ++ )
strcpy ( V_67 + V_3 * V_84 , V_85 [ V_3 ] ) ;
if ( V_2 -> V_23 -> V_19 -> V_31 . V_48 & V_64 )
for (; V_3 < V_63 ; V_3 ++ )
strcpy ( V_67 + V_3 * V_84 , V_85 [ V_3 ] ) ;
break;
case V_60 :
if ( ! V_2 -> V_59 ) {
for ( V_3 = 0 ; V_3 < V_71 ; V_3 ++ )
strcpy ( V_67 + ( V_68 ++ ) * V_84 ,
V_86 [ V_3 ] ) ;
for ( V_3 = 0 ; V_3 < V_72 ; V_3 ++ )
strcpy ( V_67 + ( V_68 ++ ) * V_84 ,
V_86 [ V_3 +
V_71 ] ) ;
for ( V_3 = 0 ; V_3 < V_74 ; V_3 ++ )
strcpy ( V_67 + ( V_68 ++ ) * V_84 ,
V_86 [ V_3 +
V_71 +
V_72 ] ) ;
} else
for ( V_3 = 0 ; V_3 < V_71 + V_72 ; V_3 ++ ) {
if ( ( V_2 -> V_59 >> V_3 ) & 1 ) {
strcpy ( V_67 +
( V_68 ++ ) * V_84 ,
V_86 [ V_3 ] ) ;
}
if ( ! ( V_2 -> V_59 >> V_3 ) )
break;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
sprintf ( V_67 + ( V_68 ++ ) * V_84 ,
L_7 , V_3 ) ;
sprintf ( V_67 + ( V_68 ++ ) * V_84 ,
L_8 , V_3 ) ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_12 ; V_3 ++ ) {
sprintf ( V_67 + ( V_68 ++ ) * V_84 ,
L_9 , V_3 ) ;
sprintf ( V_67 + ( V_68 ++ ) * V_84 ,
L_10 , V_3 ) ;
}
break;
}
}
static int F_22 ( struct V_18 * V_19 , struct V_87 * V_88 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
int V_89 ;
V_88 -> V_90 = V_91 ;
V_88 -> V_49 = V_92 ;
V_88 -> V_93 = V_94 ;
if ( F_23 ( V_2 -> V_23 , V_2 -> V_45 ) )
return - V_95 ;
V_89 = V_2 -> V_96 . V_97 ;
if ( F_24 ( V_19 ) ) {
F_25 ( V_88 , V_2 -> V_96 . V_98 ) ;
V_88 -> V_99 = V_100 ;
} else {
F_25 ( V_88 , - 1 ) ;
V_88 -> V_99 = - 1 ;
}
if ( V_89 > 0 && V_89 <= 0xC ) {
V_88 -> V_45 = V_101 ;
V_88 -> V_102 = V_103 ;
V_88 -> V_49 |= V_104 ;
V_88 -> V_93 |= V_105 ;
} else if ( V_89 == 0x80 || V_89 == 0 ) {
V_88 -> V_45 = V_106 ;
V_88 -> V_102 = V_107 ;
V_88 -> V_49 |= V_108 ;
V_88 -> V_93 |= V_109 ;
} else {
V_88 -> V_45 = - 1 ;
V_88 -> V_102 = - 1 ;
}
return 0 ;
}
static int F_26 ( struct V_18 * V_19 , struct V_87 * V_88 )
{
if ( ( V_88 -> V_90 == V_110 ) ||
( F_27 ( V_88 ) != V_111 ) ||
( V_88 -> V_99 != V_100 ) )
return - V_55 ;
return 0 ;
}
static int F_28 ( struct V_18 * V_19 ,
struct V_112 * V_113 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
V_113 -> V_114 = V_2 -> V_10 ;
V_113 -> V_115 = V_2 -> V_8 ;
V_113 -> V_116 = V_2 -> V_15 ;
V_113 -> V_117 = V_2 -> V_14 ;
V_113 -> V_118 = V_2 -> V_118 ;
V_113 -> V_119 = V_2 -> V_120 ;
V_113 -> V_121 = V_2 -> V_121 ;
V_113 -> V_122 = V_2 -> V_123 ;
V_113 -> V_124 = V_2 -> V_125 ;
V_113 -> V_126 = V_2 -> V_11 ;
return 0 ;
}
static int F_29 ( struct V_18 * V_19 ,
struct V_112 * V_113 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
V_2 -> V_14 = ( V_113 -> V_117 ==
V_17 ) ?
V_127 :
V_113 -> V_117 ;
V_2 -> V_15 = ( V_113 -> V_116 ==
V_17 ) ?
V_128 :
V_113 -> V_116 ;
if ( V_113 -> V_114 != V_2 -> V_10 ||
V_113 -> V_115 != V_2 -> V_8 ) {
V_2 -> V_10 = V_113 -> V_114 ;
V_2 -> V_8 = V_113 -> V_115 ;
}
V_2 -> V_118 = V_113 -> V_118 ;
V_2 -> V_120 = V_113 -> V_119 ;
V_2 -> V_121 = V_113 -> V_121 ;
V_2 -> V_123 = V_113 -> V_122 ;
V_2 -> V_125 = V_113 -> V_124 ;
V_2 -> V_11 = V_113 -> V_126 ;
return F_1 ( V_2 ) ;
}
static int F_30 ( struct V_18 * V_19 ,
struct V_129 * V_130 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
int V_4 ;
V_2 -> V_131 -> V_132 = V_130 -> V_132 != 0 ;
V_2 -> V_131 -> V_133 = V_130 -> V_133 != 0 ;
V_4 = F_31 ( V_23 -> V_19 , V_2 -> V_45 ,
V_2 -> V_134 + V_135 ,
V_2 -> V_131 -> V_132 ,
V_2 -> V_131 -> V_136 ,
V_2 -> V_131 -> V_133 ,
V_2 -> V_131 -> V_137 ) ;
if ( V_4 )
F_10 ( V_2 , L_11 ) ;
return V_4 ;
}
static void F_32 ( struct V_18 * V_19 ,
struct V_129 * V_130 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
V_130 -> V_132 = V_2 -> V_131 -> V_132 ;
V_130 -> V_133 = V_2 -> V_131 -> V_133 ;
}
static int F_33 ( struct V_18 * V_19 ,
struct V_138 * V_139 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_140 , V_141 ;
int V_142 = 0 ;
int V_4 = 0 ;
if ( V_139 -> V_143 || V_139 -> V_144 )
return - V_55 ;
V_140 = F_34 ( V_139 -> V_145 ) ;
V_140 = F_35 ( T_1 , V_140 , V_146 ) ;
V_140 = F_36 ( T_1 , V_140 , V_147 ) ;
V_141 = F_34 ( V_139 -> V_148 ) ;
V_141 = F_35 ( T_1 , V_141 , V_149 ) ;
V_141 = F_36 ( T_1 , V_141 , V_150 ) ;
if ( V_140 == ( V_2 -> V_142 ? V_2 -> V_79 [ 0 ] . V_151 :
V_2 -> V_79 [ 0 ] . V_152 ) &&
V_141 == V_2 -> V_76 [ 0 ] . V_152 )
return 0 ;
F_37 ( & V_23 -> V_153 ) ;
if ( V_2 -> V_142 ) {
V_142 = 1 ;
F_38 ( V_19 , 1 ) ;
}
F_39 ( V_2 ) ;
V_2 -> V_131 -> V_154 = V_141 ;
V_2 -> V_131 -> V_155 = V_140 ;
V_4 = F_40 ( V_2 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_12 ) ;
goto V_156;
}
if ( V_142 ) {
V_4 = F_41 ( V_19 ) ;
if ( V_4 )
F_10 ( V_2 , L_13 ) ;
}
V_4 = F_1 ( V_2 ) ;
V_156:
F_42 ( & V_23 -> V_153 ) ;
return V_4 ;
}
static void F_43 ( struct V_18 * V_19 ,
struct V_138 * V_139 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
memset ( V_139 , 0 , sizeof( * V_139 ) ) ;
V_139 -> V_157 = V_147 ;
V_139 -> V_158 = V_150 ;
V_139 -> V_145 = V_2 -> V_142 ?
V_2 -> V_79 [ 0 ] . V_151 : V_2 -> V_79 [ 0 ] . V_152 ;
V_139 -> V_148 = V_2 -> V_76 [ 0 ] . V_152 ;
}
static T_1 F_44 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
return V_2 -> V_12 ;
}
static int F_45 ( struct V_18 * V_19 , T_1 * V_159 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
struct V_160 * V_161 = & V_2 -> V_161 ;
int V_162 ;
T_6 V_163 = V_2 -> V_12 ;
int V_4 = 0 ;
V_162 = V_2 -> V_131 -> V_162 ? : V_2 -> V_12 ;
while ( V_163 -- ) {
V_159 [ V_163 ] = V_161 -> V_164 [ V_163 % V_162 ] . V_165 -
V_161 -> V_166 ;
}
return V_4 ;
}
static int F_46 ( struct V_18 * V_19 ,
const T_1 * V_159 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
int V_142 = 0 ;
int V_4 = 0 ;
int V_3 ;
int V_162 = 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_12 ; V_3 ++ ) {
if ( V_3 > 0 && ! V_159 [ V_3 ] && ! V_162 )
V_162 = V_3 ;
if ( V_159 [ V_3 ] != ( V_3 % ( V_162 ? : V_2 -> V_12 ) ) )
return - V_55 ;
}
if ( ! V_162 )
V_162 = V_2 -> V_12 ;
if ( ! F_47 ( V_162 ) )
return - V_55 ;
F_37 ( & V_23 -> V_153 ) ;
if ( V_2 -> V_142 ) {
V_142 = 1 ;
F_38 ( V_19 , 1 ) ;
}
V_2 -> V_131 -> V_162 = V_162 ;
if ( V_142 ) {
V_4 = F_41 ( V_19 ) ;
if ( V_4 )
F_10 ( V_2 , L_13 ) ;
}
F_42 ( & V_23 -> V_153 ) ;
return V_4 ;
}
static int F_48 ( struct V_18 * V_19 ,
struct V_167 * V_88 )
{
struct V_168 * V_169 ;
struct V_170 * V_171 ;
struct V_172 * V_173 ;
if ( V_88 -> V_174 . V_175 >= V_176 )
return - V_55 ;
if ( V_88 -> V_174 . V_177 & V_178 ) {
if ( ! F_49 ( V_88 -> V_174 . V_179 . V_180 ) )
return - V_55 ;
}
switch ( V_88 -> V_174 . V_177 & ~ ( V_181 | V_178 ) ) {
case V_182 :
case V_183 :
if ( V_88 -> V_174 . V_184 . V_185 . V_186 )
return - V_55 ;
V_171 = & V_88 -> V_174 . V_184 . V_185 ;
if ( ! F_50 ( V_171 -> V_187 ) ||
! F_50 ( V_171 -> V_188 ) ||
! F_50 ( V_171 -> V_189 ) ||
! F_50 ( V_171 -> V_190 ) )
return - V_55 ;
break;
case V_191 :
V_169 = & V_88 -> V_174 . V_184 . V_192 ;
if ( V_169 -> V_193 || V_169 -> V_186 || V_169 -> V_194 ||
V_88 -> V_174 . V_195 . V_192 . V_196 != V_197 ||
( ! V_169 -> V_187 && ! V_169 -> V_188 ) ||
! F_50 ( V_169 -> V_187 ) ||
! F_50 ( V_169 -> V_188 ) )
return - V_55 ;
break;
case V_198 :
V_173 = & V_88 -> V_174 . V_184 . V_199 ;
if ( ! F_51 ( V_173 -> V_200 ) )
return - V_55 ;
if ( ! F_49 ( V_173 -> V_180 ) )
return - V_55 ;
if ( ! F_50 ( V_173 -> V_201 ) )
return - V_55 ;
break;
default:
return - V_55 ;
}
if ( ( V_88 -> V_174 . V_177 & V_181 ) ) {
if ( V_88 -> V_174 . V_179 . V_202 ||
! ( ( V_88 -> V_174 . V_179 . V_203 & F_52 ( V_204 ) ) ==
0 ||
( V_88 -> V_174 . V_179 . V_203 & F_52 ( V_204 ) ) ==
F_52 ( V_204 ) ) )
return - V_55 ;
if ( V_88 -> V_174 . V_179 . V_203 ) {
if ( F_53 ( V_88 -> V_174 . V_205 . V_203 ) >= V_206 )
return - V_55 ;
}
}
return 0 ;
}
static int F_54 ( struct V_167 * V_88 ,
struct V_207 * V_208 ,
struct V_209 * V_210 ,
unsigned char * V_211 )
{
int V_4 = 0 ;
T_7 V_212 = F_55 ( V_213 << 16 ) ;
V_210 -> V_214 = V_215 ;
memcpy ( V_210 -> V_216 . V_217 , & V_212 , V_218 ) ;
memcpy ( V_210 -> V_216 . V_219 , V_211 , V_218 ) ;
if ( ( V_88 -> V_174 . V_177 & V_181 ) &&
( V_88 -> V_174 . V_179 . V_203 & F_52 ( V_204 ) ) ) {
V_210 -> V_216 . V_220 = V_88 -> V_174 . V_205 . V_203 ;
V_210 -> V_216 . V_221 = F_52 ( V_204 ) ;
}
F_56 ( & V_210 -> V_222 , V_208 ) ;
return V_4 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_167 * V_88 ,
struct V_207 * V_208 ,
struct V_209 * V_210 ,
T_8 V_223 )
{
#ifdef F_58
unsigned char V_211 [ V_218 ] ;
if ( ! F_59 ( V_223 ) ) {
if ( V_88 -> V_174 . V_177 & V_178 )
memcpy ( & V_211 , V_88 -> V_174 . V_205 . V_180 , V_218 ) ;
else
memcpy ( & V_211 , V_2 -> V_19 -> V_224 , V_218 ) ;
} else {
F_60 ( V_223 , V_211 ) ;
}
return F_54 ( V_88 , V_208 , V_210 , & V_211 [ 0 ] ) ;
#else
return - V_55 ;
#endif
}
static int F_61 ( struct V_1 * V_2 ,
struct V_167 * V_88 ,
struct V_207 * V_225 )
{
int V_4 ;
struct V_209 * V_210 = NULL ;
struct V_209 * V_226 = NULL ;
struct V_168 * V_169 = & V_88 -> V_174 . V_184 . V_192 ;
V_226 = F_62 ( sizeof( * V_226 ) , V_227 ) ;
V_210 = F_62 ( sizeof( * V_210 ) , V_227 ) ;
if ( ! V_210 || ! V_226 ) {
V_4 = - V_95 ;
goto V_228;
}
V_4 = F_57 ( V_2 , V_88 , V_225 , V_210 ,
V_88 -> V_174 . V_195 .
V_192 . V_188 ) ;
if ( V_4 )
goto V_228;
V_226 -> V_214 = V_229 ;
V_226 -> V_230 . V_231 = V_88 -> V_174 . V_195 . V_192 . V_187 ;
if ( V_169 -> V_187 )
V_226 -> V_230 . V_232 = V_233 ;
V_226 -> V_230 . V_234 = V_88 -> V_174 . V_195 . V_192 . V_188 ;
if ( V_169 -> V_188 )
V_226 -> V_230 . V_235 = V_233 ;
F_56 ( & V_226 -> V_222 , V_225 ) ;
return 0 ;
V_228:
F_63 ( V_210 ) ;
F_63 ( V_226 ) ;
return V_4 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_167 * V_88 ,
struct V_207 * V_225 , int V_194 )
{
int V_4 ;
struct V_209 * V_210 = NULL ;
struct V_209 * V_226 = NULL ;
struct V_209 * V_236 = NULL ;
struct V_170 * V_171 = & V_88 -> V_174 . V_184 . V_185 ;
V_210 = F_62 ( sizeof( * V_210 ) , V_227 ) ;
V_226 = F_62 ( sizeof( * V_226 ) , V_227 ) ;
V_236 = F_62 ( sizeof( * V_236 ) , V_227 ) ;
if ( ! V_210 || ! V_226 || ! V_236 ) {
V_4 = - V_95 ;
goto V_228;
}
V_226 -> V_214 = V_229 ;
if ( V_194 == V_182 ) {
V_4 = F_57 ( V_2 , V_88 , V_225 ,
V_210 ,
V_88 -> V_174 . V_195 .
V_185 . V_188 ) ;
if ( V_4 )
goto V_228;
V_236 -> V_214 = V_237 ;
V_226 -> V_230 . V_231 = V_88 -> V_174 . V_195 . V_185 . V_187 ;
V_226 -> V_230 . V_234 = V_88 -> V_174 . V_195 . V_185 . V_188 ;
V_236 -> V_238 . V_239 = V_88 -> V_174 . V_195 . V_185 . V_189 ;
V_236 -> V_238 . V_240 = V_88 -> V_174 . V_195 . V_185 . V_190 ;
} else {
V_4 = F_57 ( V_2 , V_88 , V_225 ,
V_210 ,
V_88 -> V_174 . V_195 .
V_241 . V_188 ) ;
if ( V_4 )
goto V_228;
V_236 -> V_214 = V_242 ;
V_226 -> V_230 . V_231 = V_88 -> V_174 . V_195 . V_241 . V_187 ;
V_226 -> V_230 . V_234 = V_88 -> V_174 . V_195 . V_241 . V_188 ;
V_236 -> V_238 . V_239 = V_88 -> V_174 . V_195 . V_241 . V_189 ;
V_236 -> V_238 . V_240 = V_88 -> V_174 . V_195 . V_241 . V_190 ;
}
if ( V_171 -> V_187 )
V_226 -> V_230 . V_232 = V_233 ;
if ( V_171 -> V_188 )
V_226 -> V_230 . V_235 = V_233 ;
if ( V_171 -> V_189 )
V_236 -> V_238 . V_243 = V_244 ;
if ( V_171 -> V_190 )
V_236 -> V_238 . V_245 = V_244 ;
F_56 ( & V_226 -> V_222 , V_225 ) ;
F_56 ( & V_236 -> V_222 , V_225 ) ;
return 0 ;
V_228:
F_63 ( V_210 ) ;
F_63 ( V_226 ) ;
F_63 ( V_236 ) ;
return V_4 ;
}
static int F_65 ( struct V_18 * V_19 ,
struct V_167 * V_88 ,
struct V_207 * V_208 )
{
int V_4 ;
struct V_172 * V_246 ;
struct V_209 * V_210 ;
struct V_1 * V_2 = F_4 ( V_19 ) ;
V_4 = F_48 ( V_19 , V_88 ) ;
if ( V_4 )
return V_4 ;
switch ( V_88 -> V_174 . V_177 & ~ ( V_181 | V_178 ) ) {
case V_198 :
V_210 = F_62 ( sizeof( * V_210 ) , V_227 ) ;
if ( ! V_210 )
return - V_95 ;
V_246 = & V_88 -> V_174 . V_195 . V_199 ;
F_54 ( V_88 , V_208 , V_210 ,
& V_246 -> V_180 [ 0 ] ) ;
V_210 -> V_216 . V_247 = V_246 -> V_201 ;
if ( V_246 -> V_201 )
V_210 -> V_216 . V_248 = 1 ;
break;
case V_191 :
V_4 = F_61 ( V_2 , V_88 , V_208 ) ;
break;
case V_182 :
V_4 = F_64 ( V_2 , V_88 , V_208 , V_182 ) ;
break;
case V_183 :
V_4 = F_64 ( V_2 , V_88 , V_208 , V_183 ) ;
break;
}
return V_4 ;
}
static int F_66 ( struct V_18 * V_19 ,
struct V_167 * V_88 )
{
int V_4 ;
struct V_1 * V_2 = F_4 ( V_19 ) ;
struct V_249 * V_250 ;
struct V_209 * V_251 , * V_252 ;
T_1 V_165 ;
T_2 V_253 ;
struct V_254 V_255 = {
. V_256 = V_257 ,
. V_258 = 0 ,
. V_259 = 1 ,
. V_260 = V_261 ,
} ;
V_255 . V_45 = V_2 -> V_45 ;
V_255 . V_262 = V_263 | V_88 -> V_174 . V_175 ;
F_67 ( & V_255 . V_222 ) ;
if ( V_88 -> V_174 . V_264 == V_265 )
V_165 = V_2 -> V_266 . V_165 ;
else if ( V_88 -> V_174 . V_264 & V_267 ) {
V_165 = V_88 -> V_174 . V_264 & ( V_267 - 1 ) ;
} else {
if ( V_88 -> V_174 . V_264 >= V_2 -> V_12 ) {
F_68 ( V_2 , L_14 ,
V_88 -> V_174 . V_264 ) ;
return - V_55 ;
}
V_165 = V_2 -> V_161 . V_164 [ V_88 -> V_174 . V_264 ] . V_165 ;
if ( ! V_165 ) {
F_68 ( V_2 , L_15 ,
V_88 -> V_174 . V_264 ) ;
return - V_55 ;
}
}
V_255 . V_165 = V_165 ;
V_4 = F_65 ( V_19 , V_88 , & V_255 . V_222 ) ;
if ( V_4 )
goto V_268;
V_250 = & V_2 -> V_269 [ V_88 -> V_174 . V_175 ] ;
if ( V_250 -> V_214 ) {
V_4 = F_69 ( V_2 -> V_23 -> V_19 , V_250 -> V_214 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_16 ,
V_88 -> V_174 . V_175 , V_250 -> V_214 ) ;
goto V_268;
}
V_250 -> V_214 = 0 ;
memset ( & V_250 -> V_270 , 0 ,
sizeof( struct V_271 ) ) ;
F_70 ( & V_250 -> V_222 ) ;
}
V_4 = F_71 ( V_2 -> V_23 -> V_19 , & V_255 , & V_253 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_17 ,
V_88 -> V_174 . V_175 ) ;
goto V_268;
}
V_250 -> V_214 = V_253 ;
memcpy ( & V_250 -> V_270 , & V_88 -> V_174 ,
sizeof( struct V_271 ) ) ;
F_56 ( & V_250 -> V_222 , & V_2 -> V_272 ) ;
V_268:
F_72 (spec, tmp_spec, &rule.list, list) {
F_70 ( & V_251 -> V_222 ) ;
F_63 ( V_251 ) ;
}
return V_4 ;
}
static int F_73 ( struct V_18 * V_19 ,
struct V_167 * V_88 )
{
int V_4 = 0 ;
struct V_249 * V_255 ;
struct V_1 * V_2 = F_4 ( V_19 ) ;
if ( V_88 -> V_174 . V_175 >= V_176 )
return - V_55 ;
V_255 = & V_2 -> V_269 [ V_88 -> V_174 . V_175 ] ;
if ( ! V_255 -> V_214 ) {
V_4 = - V_273 ;
goto V_156;
}
V_4 = F_69 ( V_2 -> V_23 -> V_19 , V_255 -> V_214 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_18 ,
V_88 -> V_174 . V_175 , V_255 -> V_214 ) ;
goto V_156;
}
V_255 -> V_214 = 0 ;
memset ( & V_255 -> V_270 , 0 , sizeof( struct V_271 ) ) ;
F_70 ( & V_255 -> V_222 ) ;
V_156:
return V_4 ;
}
static int F_74 ( struct V_18 * V_19 , struct V_167 * V_88 ,
int V_274 )
{
int V_4 = 0 ;
struct V_249 * V_255 ;
struct V_1 * V_2 = F_4 ( V_19 ) ;
if ( V_274 < 0 || V_274 >= V_176 )
return - V_55 ;
V_255 = & V_2 -> V_269 [ V_274 ] ;
if ( V_255 -> V_214 )
memcpy ( & V_88 -> V_174 , & V_255 -> V_270 ,
sizeof( struct V_271 ) ) ;
else
V_4 = - V_273 ;
return V_4 ;
}
static int F_75 ( struct V_1 * V_2 )
{
int V_3 , V_275 = 0 ;
for ( V_3 = 0 ; V_3 < V_176 ; V_3 ++ ) {
if ( V_2 -> V_269 [ V_3 ] . V_214 )
V_275 ++ ;
}
return V_275 ;
}
static int F_76 ( struct V_18 * V_19 , struct V_167 * V_88 ,
T_1 * V_276 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
int V_4 = 0 ;
int V_3 = 0 , V_262 = 0 ;
if ( ( V_88 -> V_88 == V_277 ||
V_88 -> V_88 == V_278 ||
V_88 -> V_88 == V_279 ) &&
( V_23 -> V_19 -> V_31 . V_280 !=
V_281 || ! V_2 -> V_142 ) )
return - V_55 ;
switch ( V_88 -> V_88 ) {
case V_282 :
V_88 -> V_67 = V_2 -> V_12 ;
break;
case V_277 :
V_88 -> V_283 = F_75 ( V_2 ) ;
break;
case V_278 :
V_4 = F_74 ( V_19 , V_88 , V_88 -> V_174 . V_175 ) ;
break;
case V_279 :
while ( ( ! V_4 || V_4 == - V_273 ) && V_262 < V_88 -> V_283 ) {
V_4 = F_74 ( V_19 , V_88 , V_3 ) ;
if ( ! V_4 )
V_276 [ V_262 ++ ] = V_3 ;
V_3 ++ ;
}
V_4 = 0 ;
break;
default:
V_4 = - V_54 ;
break;
}
return V_4 ;
}
static int F_77 ( struct V_18 * V_19 , struct V_167 * V_88 )
{
int V_4 = 0 ;
struct V_1 * V_2 = F_4 ( V_19 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
if ( V_23 -> V_19 -> V_31 . V_280 !=
V_281 || ! V_2 -> V_142 )
return - V_55 ;
switch ( V_88 -> V_88 ) {
case V_284 :
V_4 = F_66 ( V_19 , V_88 ) ;
break;
case V_285 :
V_4 = F_73 ( V_19 , V_88 ) ;
break;
default:
F_68 ( V_2 , L_19 , V_88 -> V_88 ) ;
return - V_55 ;
}
return V_4 ;
}
static void F_78 ( struct V_18 * V_19 ,
struct V_286 * V_287 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
memset ( V_287 , 0 , sizeof( * V_287 ) ) ;
V_287 -> V_288 = V_289 ;
V_287 -> V_290 = V_291 ;
V_287 -> V_292 = V_2 -> V_12 ;
V_287 -> V_293 = V_2 -> V_5 / V_294 ;
}
static int F_79 ( struct V_18 * V_19 ,
struct V_286 * V_287 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
int V_142 ;
int V_4 = 0 ;
if ( V_287 -> V_295 || V_287 -> V_296 ||
V_287 -> V_293 > V_291 ||
V_287 -> V_292 > V_289 ||
! V_287 -> V_293 || ! V_287 -> V_292 )
return - V_55 ;
F_37 ( & V_23 -> V_153 ) ;
if ( V_2 -> V_142 ) {
V_142 = 1 ;
F_38 ( V_19 , 1 ) ;
}
F_39 ( V_2 ) ;
V_2 -> V_297 = V_287 -> V_293 ;
V_2 -> V_5 = V_287 -> V_293 * V_294 ;
V_2 -> V_12 = V_287 -> V_292 ;
V_4 = F_40 ( V_2 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_12 ) ;
goto V_156;
}
F_80 ( V_19 , V_2 -> V_5 ) ;
F_81 ( V_19 , V_2 -> V_12 ) ;
F_82 ( V_19 , V_294 ) ;
F_68 ( V_2 , L_20 , V_2 -> V_5 ) ;
F_68 ( V_2 , L_21 , V_2 -> V_12 ) ;
if ( V_142 ) {
V_4 = F_41 ( V_19 ) ;
if ( V_4 )
F_10 ( V_2 , L_13 ) ;
}
V_4 = F_1 ( V_2 ) ;
V_156:
F_42 ( & V_23 -> V_153 ) ;
return V_4 ;
}
static int F_83 ( struct V_18 * V_19 ,
struct V_298 * V_299 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
int V_300 ;
V_300 = F_84 ( V_19 , V_299 ) ;
if ( V_300 )
return V_300 ;
if ( V_23 -> V_19 -> V_31 . V_301 & V_302 ) {
V_299 -> V_303 |=
V_304 |
V_305 |
V_306 ;
V_299 -> V_307 =
( 1 << V_308 ) |
( 1 << V_309 ) ;
V_299 -> V_310 =
( 1 << V_311 ) |
( 1 << V_312 ) ;
}
return V_300 ;
}
