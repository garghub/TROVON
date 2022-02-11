static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
F_3 ( V_4 -> V_9 , V_10 , sizeof( V_4 -> V_9 ) ) ;
F_3 ( V_4 -> V_11 , V_12 L_1 V_13 L_2 ,
sizeof( V_4 -> V_11 ) ) ;
snprintf ( V_4 -> V_14 , sizeof( V_4 -> V_14 ) ,
L_3 ,
( V_15 ) ( V_8 -> V_2 -> V_16 . V_17 >> 32 ) ,
( V_15 ) ( ( V_8 -> V_2 -> V_16 . V_17 >> 16 ) & 0xffff ) ,
( V_15 ) ( V_8 -> V_2 -> V_16 . V_17 & 0xffff ) ) ;
F_3 ( V_4 -> V_18 , F_4 ( V_8 -> V_2 -> V_19 ) ,
sizeof( V_4 -> V_18 ) ) ;
V_4 -> V_20 = 0 ;
V_4 -> V_21 = 0 ;
V_4 -> V_22 = 0 ;
}
static T_1 F_5 ( struct V_1 * V_2 )
{
return ( (struct V_5 * ) F_2 ( V_2 ) ) -> V_23 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_24 )
{
( (struct V_5 * ) F_2 ( V_2 ) ) -> V_23 = V_24 ;
}
static void F_7 ( struct V_1 * V_25 ,
struct V_26 * V_27 )
{
struct V_5 * V_6 = F_2 ( V_25 ) ;
int V_28 = 0 ;
T_2 V_29 = 0 ;
T_2 V_30 ;
if ( ( V_6 -> V_31 < 1 ) || ( V_6 -> V_31 > 2 ) ) {
F_8 ( V_6 , L_4 ) ;
return;
}
V_30 = ( V_6 -> V_31 == 1 ) ? V_32 :
V_33 ;
if ( ! ( V_6 -> V_8 -> V_2 -> V_16 . V_34 & V_30 ) ) {
V_27 -> V_35 = 0 ;
V_27 -> V_36 = 0 ;
return;
}
V_28 = F_9 ( V_6 -> V_8 -> V_2 , & V_29 , V_6 -> V_31 ) ;
if ( V_28 ) {
F_8 ( V_6 , L_4 ) ;
return;
}
if ( V_29 & V_37 )
V_27 -> V_35 = V_38 ;
else
V_27 -> V_35 = 0 ;
if ( V_29 & V_39 )
V_27 -> V_36 = V_38 ;
else
V_27 -> V_36 = 0 ;
}
static int F_10 ( struct V_1 * V_25 ,
struct V_26 * V_27 )
{
struct V_5 * V_6 = F_2 ( V_25 ) ;
T_2 V_29 = 0 ;
int V_28 = 0 ;
T_2 V_30 ;
if ( ( V_6 -> V_31 < 1 ) || ( V_6 -> V_31 > 2 ) )
return - V_40 ;
V_30 = ( V_6 -> V_31 == 1 ) ? V_32 :
V_33 ;
if ( ! ( V_6 -> V_8 -> V_2 -> V_16 . V_34 & V_30 ) )
return - V_40 ;
if ( V_27 -> V_35 & ~ V_38 )
return - V_41 ;
V_28 = F_9 ( V_6 -> V_8 -> V_2 , & V_29 , V_6 -> V_31 ) ;
if ( V_28 ) {
F_8 ( V_6 , L_5 ) ;
return V_28 ;
}
if ( V_27 -> V_36 & V_38 ) {
V_29 |= V_42 | V_39 |
V_37 ;
} else {
V_29 &= ~ ( V_39 | V_37 ) ;
V_29 |= V_42 ;
}
V_28 = F_11 ( V_6 -> V_8 -> V_2 , V_29 , V_6 -> V_31 ) ;
if ( V_28 )
F_8 ( V_6 , L_6 ) ;
return V_28 ;
}
static int F_12 ( struct V_1 * V_2 , int V_43 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_44 = F_13 ( V_6 -> V_45 ) ;
switch ( V_43 ) {
case V_46 :
return ( V_6 -> V_45 ? V_44 : V_47 ) +
( V_6 -> V_48 + V_6 -> V_49 ) * 2 ;
case V_50 :
return V_51 - ! ( V_6 -> V_8 -> V_2 -> V_16 . V_34
& V_52 ) * 2 ;
default:
return - V_40 ;
}
}
static void F_14 ( struct V_1 * V_2 ,
struct V_53 * V_54 , T_3 * V_55 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_56 = 0 ;
int V_57 , V_58 = 0 ;
F_15 ( & V_6 -> V_59 ) ;
if ( ! ( V_6 -> V_45 ) ) {
for ( V_57 = 0 ; V_57 < V_60 ; V_57 ++ )
V_55 [ V_56 ++ ] =
( ( unsigned long * ) & V_6 -> V_54 ) [ V_57 ] ;
for ( V_57 = 0 ; V_57 < V_61 ; V_57 ++ )
V_55 [ V_56 ++ ] =
( ( unsigned long * ) & V_6 -> V_62 ) [ V_57 ] ;
for ( V_57 = 0 ; V_57 < V_63 ; V_57 ++ )
V_55 [ V_56 ++ ] =
( ( unsigned long * ) & V_6 -> V_64 ) [ V_57 ] ;
} else {
for ( V_57 = 0 ; V_57 < V_60 ; V_57 ++ ) {
if ( ( V_6 -> V_45 >> V_58 ) & 1 )
V_55 [ V_56 ++ ] =
( ( unsigned long * ) & V_6 -> V_54 ) [ V_57 ] ;
V_58 ++ ;
}
for ( V_57 = 0 ; V_57 < V_61 ; V_57 ++ ) {
if ( ( V_6 -> V_45 >> V_58 ) & 1 )
V_55 [ V_56 ++ ] =
( ( unsigned long * ) & V_6 -> V_62 ) [ V_57 ] ;
V_58 ++ ;
}
}
for ( V_57 = 0 ; V_57 < V_6 -> V_48 ; V_57 ++ ) {
V_55 [ V_56 ++ ] = V_6 -> V_65 [ V_57 ] . V_66 ;
V_55 [ V_56 ++ ] = V_6 -> V_65 [ V_57 ] . V_67 ;
}
for ( V_57 = 0 ; V_57 < V_6 -> V_49 ; V_57 ++ ) {
V_55 [ V_56 ++ ] = V_6 -> V_68 [ V_57 ] . V_66 ;
V_55 [ V_56 ++ ] = V_6 -> V_68 [ V_57 ] . V_67 ;
}
F_16 ( & V_6 -> V_59 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_69 * V_70 , T_2 * V_71 )
{
F_18 ( V_2 , & V_70 -> V_34 , V_71 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
T_4 V_72 , T_5 * V_55 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_56 = 0 ;
int V_57 ;
switch ( V_72 ) {
case V_50 :
for ( V_57 = 0 ; V_57 < V_51 - 2 ; V_57 ++ )
strcpy ( V_55 + V_57 * V_73 , V_74 [ V_57 ] ) ;
if ( V_6 -> V_8 -> V_2 -> V_16 . V_34 & V_52 )
for (; V_57 < V_51 ; V_57 ++ )
strcpy ( V_55 + V_57 * V_73 , V_74 [ V_57 ] ) ;
break;
case V_46 :
if ( ! V_6 -> V_45 ) {
for ( V_57 = 0 ; V_57 < V_60 ; V_57 ++ )
strcpy ( V_55 + ( V_56 ++ ) * V_73 ,
V_75 [ V_57 ] ) ;
for ( V_57 = 0 ; V_57 < V_61 ; V_57 ++ )
strcpy ( V_55 + ( V_56 ++ ) * V_73 ,
V_75 [ V_57 +
V_60 ] ) ;
for ( V_57 = 0 ; V_57 < V_63 ; V_57 ++ )
strcpy ( V_55 + ( V_56 ++ ) * V_73 ,
V_75 [ V_57 +
V_60 +
V_61 ] ) ;
} else
for ( V_57 = 0 ; V_57 < V_60 + V_61 ; V_57 ++ ) {
if ( ( V_6 -> V_45 >> V_57 ) & 1 ) {
strcpy ( V_55 +
( V_56 ++ ) * V_73 ,
V_75 [ V_57 ] ) ;
}
if ( ! ( V_6 -> V_45 >> V_57 ) )
break;
}
for ( V_57 = 0 ; V_57 < V_6 -> V_48 ; V_57 ++ ) {
sprintf ( V_55 + ( V_56 ++ ) * V_73 ,
L_7 , V_57 ) ;
sprintf ( V_55 + ( V_56 ++ ) * V_73 ,
L_8 , V_57 ) ;
}
for ( V_57 = 0 ; V_57 < V_6 -> V_49 ; V_57 ++ ) {
sprintf ( V_55 + ( V_56 ++ ) * V_73 ,
L_9 , V_57 ) ;
sprintf ( V_55 + ( V_56 ++ ) * V_73 ,
L_10 , V_57 ) ;
}
break;
}
}
static int F_20 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_78 ;
V_77 -> V_79 = V_80 ;
V_77 -> V_35 = V_81 ;
V_77 -> V_82 = V_83 ;
if ( F_21 ( V_6 -> V_8 , V_6 -> V_31 ) )
return - V_84 ;
V_78 = V_6 -> V_85 . V_86 ;
if ( F_22 ( V_2 ) ) {
F_23 ( V_77 , V_6 -> V_85 . V_87 ) ;
V_77 -> V_88 = V_89 ;
} else {
F_23 ( V_77 , - 1 ) ;
V_77 -> V_88 = - 1 ;
}
if ( V_78 > 0 && V_78 <= 0xC ) {
V_77 -> V_31 = V_90 ;
V_77 -> V_91 = V_92 ;
V_77 -> V_35 |= V_93 ;
V_77 -> V_82 |= V_94 ;
} else if ( V_78 == 0x80 || V_78 == 0 ) {
V_77 -> V_31 = V_95 ;
V_77 -> V_91 = V_96 ;
V_77 -> V_35 |= V_97 ;
V_77 -> V_82 |= V_98 ;
} else {
V_77 -> V_31 = - 1 ;
V_77 -> V_91 = - 1 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_76 * V_77 )
{
if ( ( V_77 -> V_79 == V_99 ) ||
( F_25 ( V_77 ) != V_100 ) ||
( V_77 -> V_88 != V_89 ) )
return - V_41 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_101 * V_102 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_102 -> V_103 = V_6 -> V_104 ;
V_102 -> V_105 = V_6 -> V_106 ;
V_102 -> V_107 = V_6 -> V_108 ;
V_102 -> V_109 = V_6 -> V_110 ;
V_102 -> V_111 = V_6 -> V_111 ;
V_102 -> V_112 = V_6 -> V_113 ;
V_102 -> V_114 = V_6 -> V_114 ;
V_102 -> V_115 = V_6 -> V_116 ;
V_102 -> V_117 = V_6 -> V_118 ;
V_102 -> V_119 = V_6 -> V_120 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_101 * V_102 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_28 , V_57 ;
V_6 -> V_110 = ( V_102 -> V_109 ==
V_121 ) ?
V_122 :
V_102 -> V_109 ;
V_6 -> V_108 = ( V_102 -> V_107 ==
V_121 ) ?
V_123 :
V_102 -> V_107 ;
if ( V_102 -> V_103 != V_6 -> V_104 ||
V_102 -> V_105 != V_6 -> V_106 ) {
V_6 -> V_104 = V_102 -> V_103 ;
V_6 -> V_106 = V_102 -> V_105 ;
for ( V_57 = 0 ; V_57 < V_6 -> V_48 ; V_57 ++ ) {
V_6 -> V_124 [ V_57 ] . V_125 = V_6 -> V_106 ;
V_6 -> V_124 [ V_57 ] . V_126 = V_6 -> V_104 ;
if ( F_28 ( V_6 , & V_6 -> V_124 [ V_57 ] ) ) {
F_29 ( V_6 , L_11
L_12 , V_57 ) ;
}
}
}
V_6 -> V_111 = V_102 -> V_111 ;
V_6 -> V_113 = V_102 -> V_112 ;
V_6 -> V_114 = V_102 -> V_114 ;
V_6 -> V_116 = V_102 -> V_115 ;
V_6 -> V_118 = V_102 -> V_117 ;
V_6 -> V_120 = V_102 -> V_119 ;
if ( V_6 -> V_120 )
return 0 ;
for ( V_57 = 0 ; V_57 < V_6 -> V_49 ; V_57 ++ ) {
V_6 -> V_127 [ V_57 ] . V_125 = V_6 -> V_110 ;
V_6 -> V_127 [ V_57 ] . V_126 = V_6 -> V_108 ;
V_6 -> V_128 [ V_57 ] = V_121 ;
V_28 = F_28 ( V_6 , & V_6 -> V_127 [ V_57 ] ) ;
if ( V_28 )
return V_28 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_129 * V_130 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_28 ;
V_6 -> V_131 -> V_132 = V_130 -> V_132 != 0 ;
V_6 -> V_131 -> V_133 = V_130 -> V_133 != 0 ;
V_28 = F_31 ( V_8 -> V_2 , V_6 -> V_31 ,
V_6 -> V_134 + V_135 ,
V_6 -> V_131 -> V_132 ,
V_6 -> V_131 -> V_136 ,
V_6 -> V_131 -> V_133 ,
V_6 -> V_131 -> V_137 ) ;
if ( V_28 )
F_8 ( V_6 , L_13 ) ;
return V_28 ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_129 * V_130 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_130 -> V_132 = V_6 -> V_131 -> V_132 ;
V_130 -> V_133 = V_6 -> V_131 -> V_133 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_138 * V_139 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_140 , V_141 ;
int V_142 = 0 ;
int V_28 = 0 ;
int V_57 ;
if ( V_139 -> V_143 || V_139 -> V_144 )
return - V_41 ;
V_140 = F_34 ( V_139 -> V_145 ) ;
V_140 = F_35 ( T_1 , V_140 , V_146 ) ;
V_140 = F_36 ( T_1 , V_140 , V_147 ) ;
V_141 = F_34 ( V_139 -> V_148 ) ;
V_141 = F_35 ( T_1 , V_141 , V_149 ) ;
V_141 = F_36 ( T_1 , V_141 , V_150 ) ;
if ( V_140 == ( V_6 -> V_142 ? V_6 -> V_68 [ 0 ] . V_151 :
V_6 -> V_68 [ 0 ] . V_152 ) &&
V_141 == V_6 -> V_65 [ 0 ] . V_152 )
return 0 ;
F_37 ( & V_8 -> V_153 ) ;
if ( V_6 -> V_142 ) {
V_142 = 1 ;
F_38 ( V_2 ) ;
}
F_39 ( V_6 ) ;
V_6 -> V_131 -> V_154 = V_141 ;
V_6 -> V_131 -> V_155 = V_140 ;
V_28 = F_40 ( V_6 ) ;
if ( V_28 ) {
F_8 ( V_6 , L_14 ) ;
goto V_156;
}
if ( V_142 ) {
V_28 = F_41 ( V_2 ) ;
if ( V_28 )
F_8 ( V_6 , L_15 ) ;
}
for ( V_57 = 0 ; V_57 < V_6 -> V_49 ; V_57 ++ ) {
V_6 -> V_127 [ V_57 ] . V_125 = V_6 -> V_110 ;
V_6 -> V_127 [ V_57 ] . V_126 = V_6 -> V_108 ;
V_6 -> V_128 [ V_57 ] = V_121 ;
V_28 = F_28 ( V_6 , & V_6 -> V_127 [ V_57 ] ) ;
if ( V_28 )
goto V_156;
}
V_156:
F_42 ( & V_8 -> V_153 ) ;
return V_28 ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_138 * V_139 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
memset ( V_139 , 0 , sizeof( * V_139 ) ) ;
V_139 -> V_157 = V_147 ;
V_139 -> V_158 = V_150 ;
V_139 -> V_145 = V_6 -> V_142 ?
V_6 -> V_68 [ 0 ] . V_151 : V_6 -> V_68 [ 0 ] . V_152 ;
V_139 -> V_148 = V_6 -> V_65 [ 0 ] . V_152 ;
}
static T_1 F_44 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_49 ;
}
static int F_45 ( struct V_1 * V_2 , T_1 * V_159 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_160 * V_161 = & V_6 -> V_161 ;
int V_162 ;
T_6 V_163 = V_6 -> V_49 ;
int V_28 = 0 ;
V_162 = V_6 -> V_131 -> V_162 ? : V_6 -> V_49 ;
while ( V_163 -- ) {
V_159 [ V_163 ] = V_161 -> V_164 [ V_163 % V_162 ] . V_165 -
V_161 -> V_166 ;
}
return V_28 ;
}
static int F_46 ( struct V_1 * V_2 ,
const T_1 * V_159 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_142 = 0 ;
int V_28 = 0 ;
int V_57 ;
int V_162 = 0 ;
for ( V_57 = 0 ; V_57 < V_6 -> V_49 ; V_57 ++ ) {
if ( V_57 > 0 && ! V_159 [ V_57 ] && ! V_162 )
V_162 = V_57 ;
if ( V_159 [ V_57 ] != ( V_57 % ( V_162 ? : V_6 -> V_49 ) ) )
return - V_41 ;
}
if ( ! V_162 )
V_162 = V_6 -> V_49 ;
if ( ! F_47 ( V_162 ) )
return - V_41 ;
F_37 ( & V_8 -> V_153 ) ;
if ( V_6 -> V_142 ) {
V_142 = 1 ;
F_38 ( V_2 ) ;
}
V_6 -> V_131 -> V_162 = V_162 ;
if ( V_142 ) {
V_28 = F_41 ( V_2 ) ;
if ( V_28 )
F_8 ( V_6 , L_15 ) ;
}
F_42 ( & V_8 -> V_153 ) ;
return V_28 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_167 * V_77 )
{
struct V_168 * V_169 ;
struct V_170 * V_171 ;
struct V_172 * V_173 ;
T_2 V_174 = ~ 0ull ;
T_2 V_175 = 0 ;
if ( V_77 -> V_176 . V_177 >= V_178 )
return - V_41 ;
switch ( V_77 -> V_176 . V_179 & ~ V_180 ) {
case V_181 :
case V_182 :
if ( V_77 -> V_176 . V_183 . V_184 . V_185 )
return - V_41 ;
V_171 = & V_77 -> V_176 . V_183 . V_184 ;
if ( ! F_49 ( V_171 -> V_186 ) ||
! F_49 ( V_171 -> V_187 ) ||
! F_49 ( V_171 -> V_188 ) ||
! F_49 ( V_171 -> V_189 ) )
return - V_41 ;
break;
case V_190 :
V_169 = & V_77 -> V_176 . V_183 . V_191 ;
if ( V_169 -> V_192 || V_169 -> V_185 || V_169 -> V_193 ||
V_77 -> V_176 . V_194 . V_191 . V_195 != V_196 ||
( ! V_169 -> V_186 && ! V_169 -> V_187 ) ||
! F_49 ( V_169 -> V_186 ) ||
! F_49 ( V_169 -> V_187 ) )
return - V_41 ;
break;
case V_197 :
V_173 = & V_77 -> V_176 . V_183 . V_198 ;
if ( memcmp ( V_173 -> V_199 , & V_175 , V_200 ) )
return - V_41 ;
if ( memcmp ( V_173 -> V_201 , & V_174 , V_200 ) )
return - V_41 ;
if ( ! F_49 ( V_173 -> V_202 ) )
return - V_41 ;
break;
default:
return - V_41 ;
}
if ( ( V_77 -> V_176 . V_179 & V_180 ) ) {
if ( V_77 -> V_176 . V_203 . V_204 ||
! ( V_77 -> V_176 . V_203 . V_205 == 0 ||
V_77 -> V_176 . V_203 . V_205 == F_50 ( 0xfff ) ) )
return - V_41 ;
}
return 0 ;
}
static int F_51 ( struct V_5 * V_6 ,
struct V_167 * V_77 ,
struct V_206 * V_207 )
{
struct V_208 * V_209 ;
struct V_168 * V_169 = & V_77 -> V_176 . V_183 . V_191 ;
V_209 = F_52 ( sizeof *V_209 , V_210 ) ;
if ( ! V_209 ) {
F_8 ( V_6 , L_16 ) ;
return - V_84 ;
}
V_209 -> V_211 = V_212 ;
V_209 -> V_213 . V_214 = V_77 -> V_176 . V_194 . V_191 . V_186 ;
if ( V_169 -> V_186 )
V_209 -> V_213 . V_215 = V_216 ;
V_209 -> V_213 . V_217 = V_77 -> V_176 . V_194 . V_191 . V_187 ;
if ( V_169 -> V_187 )
V_209 -> V_213 . V_218 = V_216 ;
F_53 ( & V_209 -> V_219 , V_207 ) ;
return 0 ;
}
static int F_54 ( struct V_5 * V_6 ,
struct V_167 * V_77 ,
struct V_206 * V_207 , int V_193 )
{
struct V_208 * V_209 ;
struct V_208 * V_220 ;
struct V_170 * V_171 = & V_77 -> V_176 . V_183 . V_184 ;
V_209 = F_52 ( sizeof *V_209 , V_210 ) ;
V_220 = F_52 ( sizeof *V_220 , V_210 ) ;
if ( ! V_220 || ! V_209 ) {
F_8 ( V_6 , L_16 ) ;
F_55 ( V_209 ) ;
F_55 ( V_220 ) ;
return - V_84 ;
}
V_209 -> V_211 = V_212 ;
if ( V_193 == V_181 ) {
V_220 -> V_211 = V_221 ;
V_209 -> V_213 . V_214 = V_77 -> V_176 . V_194 . V_184 . V_186 ;
V_209 -> V_213 . V_217 = V_77 -> V_176 . V_194 . V_184 . V_187 ;
V_220 -> V_222 . V_223 = V_77 -> V_176 . V_194 . V_184 . V_188 ;
V_220 -> V_222 . V_224 = V_77 -> V_176 . V_194 . V_184 . V_189 ;
} else {
V_220 -> V_211 = V_225 ;
V_209 -> V_213 . V_214 = V_77 -> V_176 . V_194 . V_226 . V_186 ;
V_209 -> V_213 . V_217 = V_77 -> V_176 . V_194 . V_226 . V_187 ;
V_220 -> V_222 . V_223 = V_77 -> V_176 . V_194 . V_226 . V_188 ;
V_220 -> V_222 . V_224 = V_77 -> V_176 . V_194 . V_226 . V_189 ;
}
if ( V_171 -> V_186 )
V_209 -> V_213 . V_215 = V_216 ;
if ( V_171 -> V_187 )
V_209 -> V_213 . V_218 = V_216 ;
if ( V_171 -> V_188 )
V_220 -> V_222 . V_227 = V_228 ;
if ( V_171 -> V_189 )
V_220 -> V_222 . V_229 = V_228 ;
F_53 ( & V_209 -> V_219 , V_207 ) ;
F_53 ( & V_220 -> V_219 , V_207 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_167 * V_77 ,
struct V_206 * V_230 )
{
int V_28 ;
T_2 V_231 ;
T_7 V_232 ;
struct V_172 * V_233 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_208 * V_234 ;
T_7 V_235 = F_57 ( V_236 << 16 ) ;
V_28 = F_48 ( V_2 , V_77 ) ;
if ( V_28 )
return V_28 ;
V_234 = F_52 ( sizeof *V_234 , V_210 ) ;
if ( ! V_234 )
return - V_84 ;
V_231 = V_6 -> V_231 & V_236 ;
V_232 = F_57 ( V_231 << 16 ) ;
V_234 -> V_211 = V_237 ;
memcpy ( V_234 -> V_238 . V_239 , & V_235 , V_200 ) ;
if ( ( V_77 -> V_176 . V_179 & ~ V_180 ) != V_197 )
memcpy ( V_234 -> V_238 . V_240 , & V_232 , V_200 ) ;
if ( ( V_77 -> V_176 . V_179 & V_180 ) && V_77 -> V_176 . V_203 . V_205 ) {
V_234 -> V_238 . V_241 = V_77 -> V_176 . V_242 . V_205 ;
V_234 -> V_238 . V_243 = F_50 ( 0xfff ) ;
}
F_53 ( & V_234 -> V_219 , V_230 ) ;
switch ( V_77 -> V_176 . V_179 & ~ V_180 ) {
case V_197 :
V_233 = & V_77 -> V_176 . V_194 . V_198 ;
memcpy ( & V_234 -> V_238 . V_240 , V_233 -> V_201 , V_200 ) ;
V_234 -> V_238 . V_244 = V_233 -> V_202 ;
if ( V_233 -> V_202 )
V_234 -> V_238 . V_245 = 1 ;
break;
case V_190 :
V_28 = F_51 ( V_6 , V_77 , V_230 ) ;
break;
case V_181 :
V_28 = F_54 ( V_6 , V_77 , V_230 , V_181 ) ;
break;
case V_182 :
V_28 = F_54 ( V_6 , V_77 , V_230 , V_182 ) ;
break;
}
return V_28 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_167 * V_77 )
{
int V_28 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_246 * V_247 ;
struct V_208 * V_248 , * V_249 ;
T_1 V_165 ;
T_2 V_250 ;
struct V_251 V_252 = {
. V_253 = V_254 ,
. V_255 = 0 ,
. V_256 = 1 ,
. V_257 = V_258 ,
} ;
V_252 . V_31 = V_6 -> V_31 ;
V_252 . V_259 = V_260 | V_77 -> V_176 . V_177 ;
F_59 ( & V_252 . V_219 ) ;
if ( V_77 -> V_176 . V_261 == V_262 )
V_165 = V_6 -> V_263 . V_165 ;
else if ( V_77 -> V_176 . V_261 & V_264 ) {
V_165 = V_77 -> V_176 . V_261 & ( V_264 - 1 ) ;
} else {
if ( V_77 -> V_176 . V_261 >= V_6 -> V_49 ) {
F_29 ( V_6 , L_17 ,
V_77 -> V_176 . V_261 ) ;
return - V_41 ;
}
V_165 = V_6 -> V_161 . V_164 [ V_77 -> V_176 . V_261 ] . V_165 ;
if ( ! V_165 ) {
F_29 ( V_6 , L_18 ,
V_77 -> V_176 . V_261 ) ;
return - V_41 ;
}
}
V_252 . V_165 = V_165 ;
V_28 = F_56 ( V_2 , V_77 , & V_252 . V_219 ) ;
if ( V_28 )
goto V_265;
V_247 = & V_6 -> V_266 [ V_77 -> V_176 . V_177 ] ;
if ( V_247 -> V_211 ) {
V_28 = F_60 ( V_6 -> V_8 -> V_2 , V_247 -> V_211 ) ;
if ( V_28 ) {
F_8 ( V_6 , L_19 ,
V_77 -> V_176 . V_177 , V_247 -> V_211 ) ;
goto V_265;
}
V_247 -> V_211 = 0 ;
memset ( & V_247 -> V_267 , 0 ,
sizeof( struct V_268 ) ) ;
}
V_28 = F_61 ( V_6 -> V_8 -> V_2 , & V_252 , & V_250 ) ;
if ( V_28 ) {
F_8 ( V_6 , L_20 ,
V_77 -> V_176 . V_177 ) ;
goto V_265;
}
V_247 -> V_211 = V_250 ;
memcpy ( & V_247 -> V_267 , & V_77 -> V_176 ,
sizeof( struct V_268 ) ) ;
V_265:
F_62 (spec, tmp_spec, &rule.list, list) {
F_63 ( & V_248 -> V_219 ) ;
F_55 ( V_248 ) ;
}
return V_28 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_167 * V_77 )
{
int V_28 = 0 ;
struct V_246 * V_252 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_77 -> V_176 . V_177 >= V_178 )
return - V_41 ;
V_252 = & V_6 -> V_266 [ V_77 -> V_176 . V_177 ] ;
if ( ! V_252 -> V_211 ) {
V_28 = - V_269 ;
goto V_156;
}
V_28 = F_60 ( V_6 -> V_8 -> V_2 , V_252 -> V_211 ) ;
if ( V_28 ) {
F_8 ( V_6 , L_21 ,
V_77 -> V_176 . V_177 , V_252 -> V_211 ) ;
goto V_156;
}
V_252 -> V_211 = 0 ;
memset ( & V_252 -> V_267 , 0 , sizeof( struct V_268 ) ) ;
V_156:
return V_28 ;
}
static int F_65 ( struct V_1 * V_2 , struct V_167 * V_77 ,
int V_270 )
{
int V_28 = 0 ;
struct V_246 * V_252 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_270 < 0 || V_270 >= V_178 )
return - V_41 ;
V_252 = & V_6 -> V_266 [ V_270 ] ;
if ( V_252 -> V_211 )
memcpy ( & V_77 -> V_176 , & V_252 -> V_267 ,
sizeof( struct V_268 ) ) ;
else
V_28 = - V_269 ;
return V_28 ;
}
static int F_66 ( struct V_5 * V_6 )
{
int V_57 , V_271 = 0 ;
for ( V_57 = 0 ; V_57 < V_178 ; V_57 ++ ) {
if ( V_6 -> V_266 [ V_57 ] . V_211 )
V_271 ++ ;
}
return V_271 ;
}
static int F_67 ( struct V_1 * V_2 , struct V_167 * V_77 ,
T_1 * V_272 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_28 = 0 ;
int V_57 = 0 , V_259 = 0 ;
if ( ( V_77 -> V_77 == V_273 ||
V_77 -> V_77 == V_274 ||
V_77 -> V_77 == V_275 ) &&
V_8 -> V_2 -> V_16 . V_276 != V_277 )
return - V_41 ;
switch ( V_77 -> V_77 ) {
case V_278 :
V_77 -> V_55 = V_6 -> V_49 ;
break;
case V_273 :
V_77 -> V_279 = F_66 ( V_6 ) ;
break;
case V_274 :
V_28 = F_65 ( V_2 , V_77 , V_77 -> V_176 . V_177 ) ;
break;
case V_275 :
while ( ( ! V_28 || V_28 == - V_269 ) && V_259 < V_77 -> V_279 ) {
V_28 = F_65 ( V_2 , V_77 , V_57 ) ;
if ( ! V_28 )
V_272 [ V_259 ++ ] = V_57 ;
V_57 ++ ;
}
V_28 = 0 ;
break;
default:
V_28 = - V_40 ;
break;
}
return V_28 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_167 * V_77 )
{
int V_28 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_2 -> V_16 . V_276 != V_277 )
return - V_41 ;
switch ( V_77 -> V_77 ) {
case V_280 :
V_28 = F_58 ( V_2 , V_77 ) ;
break;
case V_281 :
V_28 = F_64 ( V_2 , V_77 ) ;
break;
default:
F_29 ( V_6 , L_22 , V_77 -> V_77 ) ;
return - V_41 ;
}
return V_28 ;
}
