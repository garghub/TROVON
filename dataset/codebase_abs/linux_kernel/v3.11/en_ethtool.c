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
( V_2 -> V_5 * 2 ) +
#ifdef F_16
( V_2 -> V_12 * 5 ) ;
#else
( V_2 -> V_12 * 2 ) ;
#endif
case V_62 :
return V_63 - ! ( V_2 -> V_23 -> V_19 -> V_31 . V_48
& V_64 ) * 2 ;
default:
return - V_54 ;
}
}
static void F_17 ( struct V_18 * V_19 ,
struct V_65 * V_66 , T_3 * V_67 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
int V_68 = 0 ;
int V_3 , V_69 = 0 ;
F_18 ( & V_2 -> V_70 ) ;
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
#ifdef F_16
V_67 [ V_68 ++ ] = V_2 -> V_79 [ V_3 ] . V_80 ;
V_67 [ V_68 ++ ] = V_2 -> V_79 [ V_3 ] . V_81 ;
V_67 [ V_68 ++ ] = V_2 -> V_79 [ V_3 ] . V_82 ;
#endif
}
F_19 ( & V_2 -> V_70 ) ;
}
static void F_20 ( struct V_18 * V_19 ,
struct V_83 * V_84 , T_2 * V_85 )
{
F_21 ( V_19 , & V_84 -> V_48 , V_85 ) ;
}
static void F_22 ( struct V_18 * V_19 ,
T_4 V_86 , T_5 * V_67 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
int V_68 = 0 ;
int V_3 ;
switch ( V_86 ) {
case V_62 :
for ( V_3 = 0 ; V_3 < V_63 - 2 ; V_3 ++ )
strcpy ( V_67 + V_3 * V_87 , V_88 [ V_3 ] ) ;
if ( V_2 -> V_23 -> V_19 -> V_31 . V_48 & V_64 )
for (; V_3 < V_63 ; V_3 ++ )
strcpy ( V_67 + V_3 * V_87 , V_88 [ V_3 ] ) ;
break;
case V_60 :
if ( ! V_2 -> V_59 ) {
for ( V_3 = 0 ; V_3 < V_71 ; V_3 ++ )
strcpy ( V_67 + ( V_68 ++ ) * V_87 ,
V_89 [ V_3 ] ) ;
for ( V_3 = 0 ; V_3 < V_72 ; V_3 ++ )
strcpy ( V_67 + ( V_68 ++ ) * V_87 ,
V_89 [ V_3 +
V_71 ] ) ;
for ( V_3 = 0 ; V_3 < V_74 ; V_3 ++ )
strcpy ( V_67 + ( V_68 ++ ) * V_87 ,
V_89 [ V_3 +
V_71 +
V_72 ] ) ;
} else
for ( V_3 = 0 ; V_3 < V_71 + V_72 ; V_3 ++ ) {
if ( ( V_2 -> V_59 >> V_3 ) & 1 ) {
strcpy ( V_67 +
( V_68 ++ ) * V_87 ,
V_89 [ V_3 ] ) ;
}
if ( ! ( V_2 -> V_59 >> V_3 ) )
break;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
sprintf ( V_67 + ( V_68 ++ ) * V_87 ,
L_7 , V_3 ) ;
sprintf ( V_67 + ( V_68 ++ ) * V_87 ,
L_8 , V_3 ) ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_12 ; V_3 ++ ) {
sprintf ( V_67 + ( V_68 ++ ) * V_87 ,
L_9 , V_3 ) ;
sprintf ( V_67 + ( V_68 ++ ) * V_87 ,
L_10 , V_3 ) ;
#ifdef F_16
sprintf ( V_67 + ( V_68 ++ ) * V_87 ,
L_11 , V_3 ) ;
sprintf ( V_67 + ( V_68 ++ ) * V_87 ,
L_12 , V_3 ) ;
sprintf ( V_67 + ( V_68 ++ ) * V_87 ,
L_13 , V_3 ) ;
#endif
}
break;
}
}
static int F_23 ( struct V_18 * V_19 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
int V_92 ;
V_91 -> V_93 = V_94 ;
V_91 -> V_49 = V_95 ;
V_91 -> V_96 = V_97 ;
if ( F_24 ( V_2 -> V_23 , V_2 -> V_45 ) )
return - V_98 ;
V_92 = V_2 -> V_99 . V_100 ;
if ( F_25 ( V_19 ) ) {
F_26 ( V_91 , V_2 -> V_99 . V_101 ) ;
V_91 -> V_102 = V_103 ;
} else {
F_26 ( V_91 , - 1 ) ;
V_91 -> V_102 = - 1 ;
}
if ( V_92 > 0 && V_92 <= 0xC ) {
V_91 -> V_45 = V_104 ;
V_91 -> V_105 = V_106 ;
V_91 -> V_49 |= V_107 ;
V_91 -> V_96 |= V_108 ;
} else if ( V_92 == 0x80 || V_92 == 0 ) {
V_91 -> V_45 = V_109 ;
V_91 -> V_105 = V_110 ;
V_91 -> V_49 |= V_111 ;
V_91 -> V_96 |= V_112 ;
} else {
V_91 -> V_45 = - 1 ;
V_91 -> V_105 = - 1 ;
}
return 0 ;
}
static int F_27 ( struct V_18 * V_19 , struct V_90 * V_91 )
{
if ( ( V_91 -> V_93 == V_113 ) ||
( F_28 ( V_91 ) != V_114 ) ||
( V_91 -> V_102 != V_103 ) )
return - V_55 ;
return 0 ;
}
static int F_29 ( struct V_18 * V_19 ,
struct V_115 * V_116 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
V_116 -> V_117 = V_2 -> V_10 ;
V_116 -> V_118 = V_2 -> V_8 ;
V_116 -> V_119 = V_2 -> V_15 ;
V_116 -> V_120 = V_2 -> V_14 ;
V_116 -> V_121 = V_2 -> V_121 ;
V_116 -> V_122 = V_2 -> V_123 ;
V_116 -> V_124 = V_2 -> V_124 ;
V_116 -> V_125 = V_2 -> V_126 ;
V_116 -> V_127 = V_2 -> V_128 ;
V_116 -> V_129 = V_2 -> V_11 ;
return 0 ;
}
static int F_30 ( struct V_18 * V_19 ,
struct V_115 * V_116 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
V_2 -> V_14 = ( V_116 -> V_120 ==
V_17 ) ?
V_130 :
V_116 -> V_120 ;
V_2 -> V_15 = ( V_116 -> V_119 ==
V_17 ) ?
V_131 :
V_116 -> V_119 ;
if ( V_116 -> V_117 != V_2 -> V_10 ||
V_116 -> V_118 != V_2 -> V_8 ) {
V_2 -> V_10 = V_116 -> V_117 ;
V_2 -> V_8 = V_116 -> V_118 ;
}
V_2 -> V_121 = V_116 -> V_121 ;
V_2 -> V_123 = V_116 -> V_122 ;
V_2 -> V_124 = V_116 -> V_124 ;
V_2 -> V_126 = V_116 -> V_125 ;
V_2 -> V_128 = V_116 -> V_127 ;
V_2 -> V_11 = V_116 -> V_129 ;
return F_1 ( V_2 ) ;
}
static int F_31 ( struct V_18 * V_19 ,
struct V_132 * V_133 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
int V_4 ;
V_2 -> V_134 -> V_135 = V_133 -> V_135 != 0 ;
V_2 -> V_134 -> V_136 = V_133 -> V_136 != 0 ;
V_4 = F_32 ( V_23 -> V_19 , V_2 -> V_45 ,
V_2 -> V_137 + V_138 ,
V_2 -> V_134 -> V_135 ,
V_2 -> V_134 -> V_139 ,
V_2 -> V_134 -> V_136 ,
V_2 -> V_134 -> V_140 ) ;
if ( V_4 )
F_10 ( V_2 , L_14 ) ;
return V_4 ;
}
static void F_33 ( struct V_18 * V_19 ,
struct V_132 * V_133 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
V_133 -> V_135 = V_2 -> V_134 -> V_135 ;
V_133 -> V_136 = V_2 -> V_134 -> V_136 ;
}
static int F_34 ( struct V_18 * V_19 ,
struct V_141 * V_142 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
T_1 V_143 , V_144 ;
int V_145 = 0 ;
int V_4 = 0 ;
if ( V_142 -> V_146 || V_142 -> V_147 )
return - V_55 ;
V_143 = F_35 ( V_142 -> V_148 ) ;
V_143 = F_36 ( T_1 , V_143 , V_149 ) ;
V_143 = F_37 ( T_1 , V_143 , V_150 ) ;
V_144 = F_35 ( V_142 -> V_151 ) ;
V_144 = F_36 ( T_1 , V_144 , V_152 ) ;
V_144 = F_37 ( T_1 , V_144 , V_153 ) ;
if ( V_143 == ( V_2 -> V_145 ? V_2 -> V_79 [ 0 ] . V_154 :
V_2 -> V_79 [ 0 ] . V_155 ) &&
V_144 == V_2 -> V_76 [ 0 ] . V_155 )
return 0 ;
F_38 ( & V_23 -> V_156 ) ;
if ( V_2 -> V_145 ) {
V_145 = 1 ;
F_39 ( V_19 , 1 ) ;
}
F_40 ( V_2 ) ;
V_2 -> V_134 -> V_157 = V_144 ;
V_2 -> V_134 -> V_158 = V_143 ;
V_4 = F_41 ( V_2 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_15 ) ;
goto V_159;
}
if ( V_145 ) {
V_4 = F_42 ( V_19 ) ;
if ( V_4 )
F_10 ( V_2 , L_16 ) ;
}
V_4 = F_1 ( V_2 ) ;
V_159:
F_43 ( & V_23 -> V_156 ) ;
return V_4 ;
}
static void F_44 ( struct V_18 * V_19 ,
struct V_141 * V_142 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
memset ( V_142 , 0 , sizeof( * V_142 ) ) ;
V_142 -> V_160 = V_150 ;
V_142 -> V_161 = V_153 ;
V_142 -> V_148 = V_2 -> V_145 ?
V_2 -> V_79 [ 0 ] . V_154 : V_2 -> V_79 [ 0 ] . V_155 ;
V_142 -> V_151 = V_2 -> V_76 [ 0 ] . V_155 ;
}
static T_1 F_45 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
return V_2 -> V_12 ;
}
static int F_46 ( struct V_18 * V_19 , T_1 * V_162 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
struct V_163 * V_164 = & V_2 -> V_164 ;
int V_165 ;
T_6 V_166 = V_2 -> V_12 ;
int V_4 = 0 ;
V_165 = V_2 -> V_134 -> V_165 ? : V_2 -> V_12 ;
while ( V_166 -- ) {
V_162 [ V_166 ] = V_164 -> V_167 [ V_166 % V_165 ] . V_168 -
V_164 -> V_169 ;
}
return V_4 ;
}
static int F_47 ( struct V_18 * V_19 ,
const T_1 * V_162 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
int V_145 = 0 ;
int V_4 = 0 ;
int V_3 ;
int V_165 = 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_12 ; V_3 ++ ) {
if ( V_3 > 0 && ! V_162 [ V_3 ] && ! V_165 )
V_165 = V_3 ;
if ( V_162 [ V_3 ] != ( V_3 % ( V_165 ? : V_2 -> V_12 ) ) )
return - V_55 ;
}
if ( ! V_165 )
V_165 = V_2 -> V_12 ;
if ( ! F_48 ( V_165 ) )
return - V_55 ;
F_38 ( & V_23 -> V_156 ) ;
if ( V_2 -> V_145 ) {
V_145 = 1 ;
F_39 ( V_19 , 1 ) ;
}
V_2 -> V_134 -> V_165 = V_165 ;
if ( V_145 ) {
V_4 = F_42 ( V_19 ) ;
if ( V_4 )
F_10 ( V_2 , L_16 ) ;
}
F_43 ( & V_23 -> V_156 ) ;
return V_4 ;
}
static int F_49 ( struct V_18 * V_19 ,
struct V_170 * V_91 )
{
struct V_171 * V_172 ;
struct V_173 * V_174 ;
struct V_175 * V_176 ;
if ( V_91 -> V_177 . V_178 >= V_179 )
return - V_55 ;
if ( V_91 -> V_177 . V_180 & V_181 ) {
if ( ! F_50 ( V_91 -> V_177 . V_182 . V_183 ) )
return - V_55 ;
}
switch ( V_91 -> V_177 . V_180 & ~ ( V_184 | V_181 ) ) {
case V_185 :
case V_186 :
if ( V_91 -> V_177 . V_187 . V_188 . V_189 )
return - V_55 ;
V_174 = & V_91 -> V_177 . V_187 . V_188 ;
if ( ! F_51 ( V_174 -> V_190 ) ||
! F_51 ( V_174 -> V_191 ) ||
! F_51 ( V_174 -> V_192 ) ||
! F_51 ( V_174 -> V_193 ) )
return - V_55 ;
break;
case V_194 :
V_172 = & V_91 -> V_177 . V_187 . V_195 ;
if ( V_172 -> V_196 || V_172 -> V_189 || V_172 -> V_197 ||
V_91 -> V_177 . V_198 . V_195 . V_199 != V_200 ||
( ! V_172 -> V_190 && ! V_172 -> V_191 ) ||
! F_51 ( V_172 -> V_190 ) ||
! F_51 ( V_172 -> V_191 ) )
return - V_55 ;
break;
case V_201 :
V_176 = & V_91 -> V_177 . V_187 . V_202 ;
if ( ! F_52 ( V_176 -> V_203 ) )
return - V_55 ;
if ( ! F_50 ( V_176 -> V_183 ) )
return - V_55 ;
if ( ! F_51 ( V_176 -> V_204 ) )
return - V_55 ;
break;
default:
return - V_55 ;
}
if ( ( V_91 -> V_177 . V_180 & V_184 ) ) {
if ( V_91 -> V_177 . V_182 . V_205 ||
! ( ( V_91 -> V_177 . V_182 . V_206 & F_53 ( V_207 ) ) ==
0 ||
( V_91 -> V_177 . V_182 . V_206 & F_53 ( V_207 ) ) ==
F_53 ( V_207 ) ) )
return - V_55 ;
if ( V_91 -> V_177 . V_182 . V_206 ) {
if ( F_54 ( V_91 -> V_177 . V_208 . V_206 ) >= V_209 )
return - V_55 ;
}
}
return 0 ;
}
static int F_55 ( struct V_170 * V_91 ,
struct V_210 * V_211 ,
struct V_212 * V_213 ,
unsigned char * V_214 )
{
int V_4 = 0 ;
T_7 V_215 = F_56 ( V_216 << 16 ) ;
V_213 -> V_217 = V_218 ;
memcpy ( V_213 -> V_219 . V_220 , & V_215 , V_221 ) ;
memcpy ( V_213 -> V_219 . V_222 , V_214 , V_221 ) ;
if ( ( V_91 -> V_177 . V_180 & V_184 ) &&
( V_91 -> V_177 . V_182 . V_206 & F_53 ( V_207 ) ) ) {
V_213 -> V_219 . V_223 = V_91 -> V_177 . V_208 . V_206 ;
V_213 -> V_219 . V_224 = F_53 ( V_207 ) ;
}
F_57 ( & V_213 -> V_225 , V_211 ) ;
return V_4 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_170 * V_91 ,
struct V_210 * V_211 ,
struct V_212 * V_213 ,
T_8 V_226 )
{
#ifdef F_59
unsigned char V_214 [ V_221 ] ;
if ( ! F_60 ( V_226 ) ) {
if ( V_91 -> V_177 . V_180 & V_181 )
memcpy ( & V_214 , V_91 -> V_177 . V_208 . V_183 , V_221 ) ;
else
memcpy ( & V_214 , V_2 -> V_19 -> V_227 , V_221 ) ;
} else {
F_61 ( V_226 , V_214 ) ;
}
return F_55 ( V_91 , V_211 , V_213 , & V_214 [ 0 ] ) ;
#else
return - V_55 ;
#endif
}
static int F_62 ( struct V_1 * V_2 ,
struct V_170 * V_91 ,
struct V_210 * V_228 )
{
int V_4 ;
struct V_212 * V_213 = NULL ;
struct V_212 * V_229 = NULL ;
struct V_171 * V_172 = & V_91 -> V_177 . V_187 . V_195 ;
V_229 = F_63 ( sizeof( * V_229 ) , V_230 ) ;
V_213 = F_63 ( sizeof( * V_213 ) , V_230 ) ;
if ( ! V_213 || ! V_229 ) {
V_4 = - V_98 ;
goto V_231;
}
V_4 = F_58 ( V_2 , V_91 , V_228 , V_213 ,
V_91 -> V_177 . V_198 .
V_195 . V_191 ) ;
if ( V_4 )
goto V_231;
V_229 -> V_217 = V_232 ;
V_229 -> V_233 . V_234 = V_91 -> V_177 . V_198 . V_195 . V_190 ;
if ( V_172 -> V_190 )
V_229 -> V_233 . V_235 = V_236 ;
V_229 -> V_233 . V_237 = V_91 -> V_177 . V_198 . V_195 . V_191 ;
if ( V_172 -> V_191 )
V_229 -> V_233 . V_238 = V_236 ;
F_57 ( & V_229 -> V_225 , V_228 ) ;
return 0 ;
V_231:
F_64 ( V_213 ) ;
F_64 ( V_229 ) ;
return V_4 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_170 * V_91 ,
struct V_210 * V_228 , int V_197 )
{
int V_4 ;
struct V_212 * V_213 = NULL ;
struct V_212 * V_229 = NULL ;
struct V_212 * V_239 = NULL ;
struct V_173 * V_174 = & V_91 -> V_177 . V_187 . V_188 ;
V_213 = F_63 ( sizeof( * V_213 ) , V_230 ) ;
V_229 = F_63 ( sizeof( * V_229 ) , V_230 ) ;
V_239 = F_63 ( sizeof( * V_239 ) , V_230 ) ;
if ( ! V_213 || ! V_229 || ! V_239 ) {
V_4 = - V_98 ;
goto V_231;
}
V_229 -> V_217 = V_232 ;
if ( V_197 == V_185 ) {
V_4 = F_58 ( V_2 , V_91 , V_228 ,
V_213 ,
V_91 -> V_177 . V_198 .
V_188 . V_191 ) ;
if ( V_4 )
goto V_231;
V_239 -> V_217 = V_240 ;
V_229 -> V_233 . V_234 = V_91 -> V_177 . V_198 . V_188 . V_190 ;
V_229 -> V_233 . V_237 = V_91 -> V_177 . V_198 . V_188 . V_191 ;
V_239 -> V_241 . V_242 = V_91 -> V_177 . V_198 . V_188 . V_192 ;
V_239 -> V_241 . V_243 = V_91 -> V_177 . V_198 . V_188 . V_193 ;
} else {
V_4 = F_58 ( V_2 , V_91 , V_228 ,
V_213 ,
V_91 -> V_177 . V_198 .
V_244 . V_191 ) ;
if ( V_4 )
goto V_231;
V_239 -> V_217 = V_245 ;
V_229 -> V_233 . V_234 = V_91 -> V_177 . V_198 . V_244 . V_190 ;
V_229 -> V_233 . V_237 = V_91 -> V_177 . V_198 . V_244 . V_191 ;
V_239 -> V_241 . V_242 = V_91 -> V_177 . V_198 . V_244 . V_192 ;
V_239 -> V_241 . V_243 = V_91 -> V_177 . V_198 . V_244 . V_193 ;
}
if ( V_174 -> V_190 )
V_229 -> V_233 . V_235 = V_236 ;
if ( V_174 -> V_191 )
V_229 -> V_233 . V_238 = V_236 ;
if ( V_174 -> V_192 )
V_239 -> V_241 . V_246 = V_247 ;
if ( V_174 -> V_193 )
V_239 -> V_241 . V_248 = V_247 ;
F_57 ( & V_229 -> V_225 , V_228 ) ;
F_57 ( & V_239 -> V_225 , V_228 ) ;
return 0 ;
V_231:
F_64 ( V_213 ) ;
F_64 ( V_229 ) ;
F_64 ( V_239 ) ;
return V_4 ;
}
static int F_66 ( struct V_18 * V_19 ,
struct V_170 * V_91 ,
struct V_210 * V_211 )
{
int V_4 ;
struct V_175 * V_249 ;
struct V_212 * V_213 ;
struct V_1 * V_2 = F_4 ( V_19 ) ;
V_4 = F_49 ( V_19 , V_91 ) ;
if ( V_4 )
return V_4 ;
switch ( V_91 -> V_177 . V_180 & ~ ( V_184 | V_181 ) ) {
case V_201 :
V_213 = F_63 ( sizeof( * V_213 ) , V_230 ) ;
if ( ! V_213 )
return - V_98 ;
V_249 = & V_91 -> V_177 . V_198 . V_202 ;
F_55 ( V_91 , V_211 , V_213 ,
& V_249 -> V_183 [ 0 ] ) ;
V_213 -> V_219 . V_250 = V_249 -> V_204 ;
if ( V_249 -> V_204 )
V_213 -> V_219 . V_251 = 1 ;
break;
case V_194 :
V_4 = F_62 ( V_2 , V_91 , V_211 ) ;
break;
case V_185 :
V_4 = F_65 ( V_2 , V_91 , V_211 , V_185 ) ;
break;
case V_186 :
V_4 = F_65 ( V_2 , V_91 , V_211 , V_186 ) ;
break;
}
return V_4 ;
}
static int F_67 ( struct V_18 * V_19 ,
struct V_170 * V_91 )
{
int V_4 ;
struct V_1 * V_2 = F_4 ( V_19 ) ;
struct V_252 * V_253 ;
struct V_212 * V_254 , * V_255 ;
T_1 V_168 ;
T_2 V_256 ;
struct V_257 V_258 = {
. V_259 = V_260 ,
. V_261 = 0 ,
. V_262 = 1 ,
. V_263 = V_264 ,
} ;
V_258 . V_45 = V_2 -> V_45 ;
V_258 . V_265 = V_266 | V_91 -> V_177 . V_178 ;
F_68 ( & V_258 . V_225 ) ;
if ( V_91 -> V_177 . V_267 == V_268 )
V_168 = V_2 -> V_269 . V_168 ;
else if ( V_91 -> V_177 . V_267 & V_270 ) {
V_168 = V_91 -> V_177 . V_267 & ( V_270 - 1 ) ;
} else {
if ( V_91 -> V_177 . V_267 >= V_2 -> V_12 ) {
F_69 ( V_2 , L_17 ,
V_91 -> V_177 . V_267 ) ;
return - V_55 ;
}
V_168 = V_2 -> V_164 . V_167 [ V_91 -> V_177 . V_267 ] . V_168 ;
if ( ! V_168 ) {
F_69 ( V_2 , L_18 ,
V_91 -> V_177 . V_267 ) ;
return - V_55 ;
}
}
V_258 . V_168 = V_168 ;
V_4 = F_66 ( V_19 , V_91 , & V_258 . V_225 ) ;
if ( V_4 )
goto V_271;
V_253 = & V_2 -> V_272 [ V_91 -> V_177 . V_178 ] ;
if ( V_253 -> V_217 ) {
V_4 = F_70 ( V_2 -> V_23 -> V_19 , V_253 -> V_217 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_19 ,
V_91 -> V_177 . V_178 , V_253 -> V_217 ) ;
goto V_271;
}
V_253 -> V_217 = 0 ;
memset ( & V_253 -> V_273 , 0 ,
sizeof( struct V_274 ) ) ;
F_71 ( & V_253 -> V_225 ) ;
}
V_4 = F_72 ( V_2 -> V_23 -> V_19 , & V_258 , & V_256 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_20 ,
V_91 -> V_177 . V_178 ) ;
goto V_271;
}
V_253 -> V_217 = V_256 ;
memcpy ( & V_253 -> V_273 , & V_91 -> V_177 ,
sizeof( struct V_274 ) ) ;
F_57 ( & V_253 -> V_225 , & V_2 -> V_275 ) ;
V_271:
F_73 (spec, tmp_spec, &rule.list, list) {
F_71 ( & V_254 -> V_225 ) ;
F_64 ( V_254 ) ;
}
return V_4 ;
}
static int F_74 ( struct V_18 * V_19 ,
struct V_170 * V_91 )
{
int V_4 = 0 ;
struct V_252 * V_258 ;
struct V_1 * V_2 = F_4 ( V_19 ) ;
if ( V_91 -> V_177 . V_178 >= V_179 )
return - V_55 ;
V_258 = & V_2 -> V_272 [ V_91 -> V_177 . V_178 ] ;
if ( ! V_258 -> V_217 ) {
V_4 = - V_276 ;
goto V_159;
}
V_4 = F_70 ( V_2 -> V_23 -> V_19 , V_258 -> V_217 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_21 ,
V_91 -> V_177 . V_178 , V_258 -> V_217 ) ;
goto V_159;
}
V_258 -> V_217 = 0 ;
memset ( & V_258 -> V_273 , 0 , sizeof( struct V_274 ) ) ;
F_71 ( & V_258 -> V_225 ) ;
V_159:
return V_4 ;
}
static int F_75 ( struct V_18 * V_19 , struct V_170 * V_91 ,
int V_277 )
{
int V_4 = 0 ;
struct V_252 * V_258 ;
struct V_1 * V_2 = F_4 ( V_19 ) ;
if ( V_277 < 0 || V_277 >= V_179 )
return - V_55 ;
V_258 = & V_2 -> V_272 [ V_277 ] ;
if ( V_258 -> V_217 )
memcpy ( & V_91 -> V_177 , & V_258 -> V_273 ,
sizeof( struct V_274 ) ) ;
else
V_4 = - V_276 ;
return V_4 ;
}
static int F_76 ( struct V_1 * V_2 )
{
int V_3 , V_278 = 0 ;
for ( V_3 = 0 ; V_3 < V_179 ; V_3 ++ ) {
if ( V_2 -> V_272 [ V_3 ] . V_217 )
V_278 ++ ;
}
return V_278 ;
}
static int F_77 ( struct V_18 * V_19 , struct V_170 * V_91 ,
T_1 * V_279 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
int V_4 = 0 ;
int V_3 = 0 , V_265 = 0 ;
if ( ( V_91 -> V_91 == V_280 ||
V_91 -> V_91 == V_281 ||
V_91 -> V_91 == V_282 ) &&
( V_23 -> V_19 -> V_31 . V_283 !=
V_284 || ! V_2 -> V_145 ) )
return - V_55 ;
switch ( V_91 -> V_91 ) {
case V_285 :
V_91 -> V_67 = V_2 -> V_12 ;
break;
case V_280 :
V_91 -> V_286 = F_76 ( V_2 ) ;
break;
case V_281 :
V_4 = F_75 ( V_19 , V_91 , V_91 -> V_177 . V_178 ) ;
break;
case V_282 :
while ( ( ! V_4 || V_4 == - V_276 ) && V_265 < V_91 -> V_286 ) {
V_4 = F_75 ( V_19 , V_91 , V_3 ) ;
if ( ! V_4 )
V_279 [ V_265 ++ ] = V_3 ;
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
static int F_78 ( struct V_18 * V_19 , struct V_170 * V_91 )
{
int V_4 = 0 ;
struct V_1 * V_2 = F_4 ( V_19 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
if ( V_23 -> V_19 -> V_31 . V_283 !=
V_284 || ! V_2 -> V_145 )
return - V_55 ;
switch ( V_91 -> V_91 ) {
case V_287 :
V_4 = F_67 ( V_19 , V_91 ) ;
break;
case V_288 :
V_4 = F_74 ( V_19 , V_91 ) ;
break;
default:
F_69 ( V_2 , L_22 , V_91 -> V_91 ) ;
return - V_55 ;
}
return V_4 ;
}
static void F_79 ( struct V_18 * V_19 ,
struct V_289 * V_290 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
memset ( V_290 , 0 , sizeof( * V_290 ) ) ;
V_290 -> V_291 = V_292 ;
V_290 -> V_293 = V_294 ;
V_290 -> V_295 = V_2 -> V_12 ;
V_290 -> V_296 = V_2 -> V_5 / V_297 ;
}
static int F_80 ( struct V_18 * V_19 ,
struct V_289 * V_290 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
int V_145 ;
int V_4 = 0 ;
if ( V_290 -> V_298 || V_290 -> V_299 ||
V_290 -> V_296 > V_294 ||
V_290 -> V_295 > V_292 ||
! V_290 -> V_296 || ! V_290 -> V_295 )
return - V_55 ;
F_38 ( & V_23 -> V_156 ) ;
if ( V_2 -> V_145 ) {
V_145 = 1 ;
F_39 ( V_19 , 1 ) ;
}
F_40 ( V_2 ) ;
V_2 -> V_300 = V_290 -> V_296 ;
V_2 -> V_5 = V_290 -> V_296 * V_297 ;
V_2 -> V_12 = V_290 -> V_295 ;
V_4 = F_41 ( V_2 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_15 ) ;
goto V_159;
}
F_81 ( V_19 , V_2 -> V_5 ) ;
F_82 ( V_19 , V_2 -> V_12 ) ;
F_83 ( V_19 , V_297 ) ;
F_69 ( V_2 , L_23 , V_2 -> V_5 ) ;
F_69 ( V_2 , L_24 , V_2 -> V_12 ) ;
if ( V_145 ) {
V_4 = F_42 ( V_19 ) ;
if ( V_4 )
F_10 ( V_2 , L_16 ) ;
}
V_4 = F_1 ( V_2 ) ;
V_159:
F_43 ( & V_23 -> V_156 ) ;
return V_4 ;
}
static int F_84 ( struct V_18 * V_19 ,
struct V_301 * V_302 )
{
struct V_1 * V_2 = F_4 ( V_19 ) ;
struct V_22 * V_23 = V_2 -> V_23 ;
int V_303 ;
V_303 = F_85 ( V_19 , V_302 ) ;
if ( V_303 )
return V_303 ;
if ( V_23 -> V_19 -> V_31 . V_304 & V_305 ) {
V_302 -> V_306 |=
V_307 |
V_308 |
V_309 ;
V_302 -> V_310 =
( 1 << V_311 ) |
( 1 << V_312 ) ;
V_302 -> V_313 =
( 1 << V_314 ) |
( 1 << V_315 ) ;
}
return V_303 ;
}
