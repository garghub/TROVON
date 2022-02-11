static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 = 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
V_2 -> V_6 [ V_3 ] -> V_7 = V_2 -> V_8 ;
V_2 -> V_6 [ V_3 ] -> V_9 = V_2 -> V_10 ;
if ( V_2 -> V_11 ) {
V_4 = F_2 ( V_2 , V_2 -> V_6 [ V_3 ] ) ;
if ( V_4 )
return V_4 ;
}
}
if ( V_2 -> V_12 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_13 ; V_3 ++ ) {
V_2 -> V_14 [ V_3 ] -> V_7 = V_2 -> V_15 ;
V_2 -> V_14 [ V_3 ] -> V_9 = V_2 -> V_16 ;
V_2 -> V_17 [ V_3 ] = V_18 ;
if ( V_2 -> V_11 ) {
V_4 = F_2 ( V_2 , V_2 -> V_14 [ V_3 ] ) ;
if ( V_4 )
return V_4 ;
}
}
return V_4 ;
}
static void
F_3 ( struct V_19 * V_20 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
F_5 ( V_22 -> V_25 , V_26 , sizeof( V_22 -> V_25 ) ) ;
F_5 ( V_22 -> V_27 , V_28 L_1 V_29 L_2 ,
sizeof( V_22 -> V_27 ) ) ;
snprintf ( V_22 -> V_30 , sizeof( V_22 -> V_30 ) ,
L_3 ,
( V_31 ) ( V_24 -> V_20 -> V_32 . V_33 >> 32 ) ,
( V_31 ) ( ( V_24 -> V_20 -> V_32 . V_33 >> 16 ) & 0xffff ) ,
( V_31 ) ( V_24 -> V_20 -> V_32 . V_33 & 0xffff ) ) ;
F_5 ( V_22 -> V_34 , F_6 ( V_24 -> V_20 -> V_35 ) ,
sizeof( V_22 -> V_34 ) ) ;
V_22 -> V_36 = 0 ;
V_22 -> V_37 = 0 ;
V_22 -> V_38 = 0 ;
}
static T_1 F_7 ( struct V_19 * V_20 )
{
return ( (struct V_1 * ) F_4 ( V_20 ) ) -> V_39 ;
}
static void F_8 ( struct V_19 * V_20 , T_1 V_40 )
{
( (struct V_1 * ) F_4 ( V_20 ) ) -> V_39 = V_40 ;
}
static void F_9 ( struct V_19 * V_41 ,
struct V_42 * V_43 )
{
struct V_1 * V_2 = F_4 ( V_41 ) ;
int V_4 = 0 ;
T_2 V_44 = 0 ;
T_2 V_45 ;
if ( ( V_2 -> V_46 < 1 ) || ( V_2 -> V_46 > 2 ) ) {
F_10 ( V_2 , L_4 ) ;
return;
}
V_45 = ( V_2 -> V_46 == 1 ) ? V_47 :
V_48 ;
if ( ! ( V_2 -> V_24 -> V_20 -> V_32 . V_49 & V_45 ) ) {
V_43 -> V_50 = 0 ;
V_43 -> V_51 = 0 ;
return;
}
V_4 = F_11 ( V_2 -> V_24 -> V_20 , & V_44 , V_2 -> V_46 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_4 ) ;
return;
}
if ( V_44 & V_52 )
V_43 -> V_50 = V_53 ;
else
V_43 -> V_50 = 0 ;
if ( V_44 & V_54 )
V_43 -> V_51 = V_53 ;
else
V_43 -> V_51 = 0 ;
}
static int F_12 ( struct V_19 * V_41 ,
struct V_42 * V_43 )
{
struct V_1 * V_2 = F_4 ( V_41 ) ;
T_2 V_44 = 0 ;
int V_4 = 0 ;
T_2 V_45 ;
if ( ( V_2 -> V_46 < 1 ) || ( V_2 -> V_46 > 2 ) )
return - V_55 ;
V_45 = ( V_2 -> V_46 == 1 ) ? V_47 :
V_48 ;
if ( ! ( V_2 -> V_24 -> V_20 -> V_32 . V_49 & V_45 ) )
return - V_55 ;
if ( V_43 -> V_50 & ~ V_53 )
return - V_56 ;
V_4 = F_11 ( V_2 -> V_24 -> V_20 , & V_44 , V_2 -> V_46 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_5 ) ;
return V_4 ;
}
if ( V_43 -> V_51 & V_53 ) {
V_44 |= V_57 | V_54 |
V_52 ;
} else {
V_44 &= ~ ( V_54 | V_52 ) ;
V_44 |= V_57 ;
}
V_4 = F_13 ( V_2 -> V_24 -> V_20 , V_44 , V_2 -> V_46 ) ;
if ( V_4 )
F_10 ( V_2 , L_6 ) ;
return V_4 ;
}
static int F_14 ( struct V_19 * V_20 , int V_58 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
int V_59 = F_15 ( V_2 -> V_60 ) ;
switch ( V_58 ) {
case V_61 :
return ( V_2 -> V_60 ? V_59 : V_62 ) +
( V_2 -> V_5 * 2 ) +
#ifdef F_16
( V_2 -> V_13 * 5 ) ;
#else
( V_2 -> V_13 * 2 ) ;
#endif
case V_63 :
return V_64 - ! ( V_2 -> V_24 -> V_20 -> V_32 . V_49
& V_65 ) * 2 ;
default:
return - V_55 ;
}
}
static void F_17 ( struct V_19 * V_20 ,
struct V_66 * V_67 , T_3 * V_68 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
int V_69 = 0 ;
int V_3 , V_70 = 0 ;
F_18 ( & V_2 -> V_71 ) ;
if ( ! ( V_2 -> V_60 ) ) {
for ( V_3 = 0 ; V_3 < V_72 ; V_3 ++ )
V_68 [ V_69 ++ ] =
( ( unsigned long * ) & V_2 -> V_67 ) [ V_3 ] ;
for ( V_3 = 0 ; V_3 < V_73 ; V_3 ++ )
V_68 [ V_69 ++ ] =
( ( unsigned long * ) & V_2 -> V_74 ) [ V_3 ] ;
for ( V_3 = 0 ; V_3 < V_75 ; V_3 ++ )
V_68 [ V_69 ++ ] =
( ( unsigned long * ) & V_2 -> V_76 ) [ V_3 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_72 ; V_3 ++ ) {
if ( ( V_2 -> V_60 >> V_70 ) & 1 )
V_68 [ V_69 ++ ] =
( ( unsigned long * ) & V_2 -> V_67 ) [ V_3 ] ;
V_70 ++ ;
}
for ( V_3 = 0 ; V_3 < V_73 ; V_3 ++ ) {
if ( ( V_2 -> V_60 >> V_70 ) & 1 )
V_68 [ V_69 ++ ] =
( ( unsigned long * ) & V_2 -> V_74 ) [ V_3 ] ;
V_70 ++ ;
}
}
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
V_68 [ V_69 ++ ] = V_2 -> V_77 [ V_3 ] -> V_78 ;
V_68 [ V_69 ++ ] = V_2 -> V_77 [ V_3 ] -> V_79 ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_13 ; V_3 ++ ) {
V_68 [ V_69 ++ ] = V_2 -> V_80 [ V_3 ] -> V_78 ;
V_68 [ V_69 ++ ] = V_2 -> V_80 [ V_3 ] -> V_79 ;
#ifdef F_16
V_68 [ V_69 ++ ] = V_2 -> V_80 [ V_3 ] -> V_81 ;
V_68 [ V_69 ++ ] = V_2 -> V_80 [ V_3 ] -> V_82 ;
V_68 [ V_69 ++ ] = V_2 -> V_80 [ V_3 ] -> V_83 ;
#endif
}
F_19 ( & V_2 -> V_71 ) ;
}
static void F_20 ( struct V_19 * V_20 ,
struct V_84 * V_85 , T_2 * V_86 )
{
F_21 ( V_20 , & V_85 -> V_49 , V_86 ) ;
}
static void F_22 ( struct V_19 * V_20 ,
T_4 V_87 , T_5 * V_68 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
int V_69 = 0 ;
int V_3 ;
switch ( V_87 ) {
case V_63 :
for ( V_3 = 0 ; V_3 < V_64 - 2 ; V_3 ++ )
strcpy ( V_68 + V_3 * V_88 , V_89 [ V_3 ] ) ;
if ( V_2 -> V_24 -> V_20 -> V_32 . V_49 & V_65 )
for (; V_3 < V_64 ; V_3 ++ )
strcpy ( V_68 + V_3 * V_88 , V_89 [ V_3 ] ) ;
break;
case V_61 :
if ( ! V_2 -> V_60 ) {
for ( V_3 = 0 ; V_3 < V_72 ; V_3 ++ )
strcpy ( V_68 + ( V_69 ++ ) * V_88 ,
V_90 [ V_3 ] ) ;
for ( V_3 = 0 ; V_3 < V_73 ; V_3 ++ )
strcpy ( V_68 + ( V_69 ++ ) * V_88 ,
V_90 [ V_3 +
V_72 ] ) ;
for ( V_3 = 0 ; V_3 < V_75 ; V_3 ++ )
strcpy ( V_68 + ( V_69 ++ ) * V_88 ,
V_90 [ V_3 +
V_72 +
V_73 ] ) ;
} else
for ( V_3 = 0 ; V_3 < V_72 + V_73 ; V_3 ++ ) {
if ( ( V_2 -> V_60 >> V_3 ) & 1 ) {
strcpy ( V_68 +
( V_69 ++ ) * V_88 ,
V_90 [ V_3 ] ) ;
}
if ( ! ( V_2 -> V_60 >> V_3 ) )
break;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
sprintf ( V_68 + ( V_69 ++ ) * V_88 ,
L_7 , V_3 ) ;
sprintf ( V_68 + ( V_69 ++ ) * V_88 ,
L_8 , V_3 ) ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_13 ; V_3 ++ ) {
sprintf ( V_68 + ( V_69 ++ ) * V_88 ,
L_9 , V_3 ) ;
sprintf ( V_68 + ( V_69 ++ ) * V_88 ,
L_10 , V_3 ) ;
#ifdef F_16
sprintf ( V_68 + ( V_69 ++ ) * V_88 ,
L_11 , V_3 ) ;
sprintf ( V_68 + ( V_69 ++ ) * V_88 ,
L_12 , V_3 ) ;
sprintf ( V_68 + ( V_69 ++ ) * V_88 ,
L_13 , V_3 ) ;
#endif
}
break;
}
}
static int F_23 ( struct V_19 * V_20 , struct V_91 * V_92 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
int V_93 ;
V_92 -> V_94 = V_95 ;
V_92 -> V_50 = V_96 ;
V_92 -> V_97 = V_98 ;
if ( F_24 ( V_2 -> V_24 , V_2 -> V_46 ) )
return - V_99 ;
V_93 = V_2 -> V_100 . V_101 ;
if ( F_25 ( V_20 ) ) {
F_26 ( V_92 , V_2 -> V_100 . V_102 ) ;
V_92 -> V_103 = V_104 ;
} else {
F_26 ( V_92 , V_105 ) ;
V_92 -> V_103 = V_106 ;
}
if ( V_93 > 0 && V_93 <= 0xC ) {
V_92 -> V_46 = V_107 ;
V_92 -> V_108 = V_109 ;
V_92 -> V_50 |= V_110 ;
V_92 -> V_97 |= V_111 ;
} else if ( V_93 == 0x80 || V_93 == 0 ) {
V_92 -> V_46 = V_112 ;
V_92 -> V_108 = V_113 ;
V_92 -> V_50 |= V_114 ;
V_92 -> V_97 |= V_115 ;
} else {
V_92 -> V_46 = - 1 ;
V_92 -> V_108 = - 1 ;
}
return 0 ;
}
static int F_27 ( struct V_19 * V_20 , struct V_91 * V_92 )
{
if ( ( V_92 -> V_94 == V_116 ) ||
( F_28 ( V_92 ) != V_117 ) ||
( V_92 -> V_103 != V_104 ) )
return - V_56 ;
return 0 ;
}
static int F_29 ( struct V_19 * V_20 ,
struct V_118 * V_119 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
V_119 -> V_120 = V_2 -> V_10 ;
V_119 -> V_121 = V_2 -> V_8 ;
V_119 -> V_122 = V_2 -> V_123 ;
V_119 -> V_124 = V_2 -> V_16 ;
V_119 -> V_125 = V_2 -> V_15 ;
V_119 -> V_126 = V_2 -> V_126 ;
V_119 -> V_127 = V_2 -> V_128 ;
V_119 -> V_129 = V_2 -> V_129 ;
V_119 -> V_130 = V_2 -> V_131 ;
V_119 -> V_132 = V_2 -> V_133 ;
V_119 -> V_134 = V_2 -> V_12 ;
return 0 ;
}
static int F_30 ( struct V_19 * V_20 ,
struct V_118 * V_119 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
if ( ! V_119 -> V_122 )
return - V_56 ;
V_2 -> V_15 = ( V_119 -> V_125 ==
V_18 ) ?
V_135 :
V_119 -> V_125 ;
V_2 -> V_16 = ( V_119 -> V_124 ==
V_18 ) ?
V_136 :
V_119 -> V_124 ;
if ( V_119 -> V_120 != V_2 -> V_10 ||
V_119 -> V_121 != V_2 -> V_8 ) {
V_2 -> V_10 = V_119 -> V_120 ;
V_2 -> V_8 = V_119 -> V_121 ;
}
V_2 -> V_126 = V_119 -> V_126 ;
V_2 -> V_128 = V_119 -> V_127 ;
V_2 -> V_129 = V_119 -> V_129 ;
V_2 -> V_131 = V_119 -> V_130 ;
V_2 -> V_133 = V_119 -> V_132 ;
V_2 -> V_12 = V_119 -> V_134 ;
V_2 -> V_123 = V_119 -> V_122 ;
return F_1 ( V_2 ) ;
}
static int F_31 ( struct V_19 * V_20 ,
struct V_137 * V_138 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_4 ;
V_2 -> V_139 -> V_140 = V_138 -> V_140 != 0 ;
V_2 -> V_139 -> V_141 = V_138 -> V_141 != 0 ;
V_4 = F_32 ( V_24 -> V_20 , V_2 -> V_46 ,
V_2 -> V_142 + V_143 ,
V_2 -> V_139 -> V_140 ,
V_2 -> V_139 -> V_144 ,
V_2 -> V_139 -> V_141 ,
V_2 -> V_139 -> V_145 ) ;
if ( V_4 )
F_10 ( V_2 , L_14 ) ;
return V_4 ;
}
static void F_33 ( struct V_19 * V_20 ,
struct V_137 * V_138 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
V_138 -> V_140 = V_2 -> V_139 -> V_140 ;
V_138 -> V_141 = V_2 -> V_139 -> V_141 ;
}
static int F_34 ( struct V_19 * V_20 ,
struct V_146 * V_147 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
T_1 V_148 , V_149 ;
int V_11 = 0 ;
int V_4 = 0 ;
if ( V_147 -> V_150 || V_147 -> V_151 )
return - V_56 ;
V_148 = F_35 ( V_147 -> V_152 ) ;
V_148 = F_36 ( T_1 , V_148 , V_153 ) ;
V_148 = F_37 ( T_1 , V_148 , V_154 ) ;
V_149 = F_35 ( V_147 -> V_155 ) ;
V_149 = F_36 ( T_1 , V_149 , V_156 ) ;
V_149 = F_37 ( T_1 , V_149 , V_157 ) ;
if ( V_148 == ( V_2 -> V_11 ? V_2 -> V_80 [ 0 ] -> V_158 :
V_2 -> V_80 [ 0 ] -> V_159 ) &&
V_149 == V_2 -> V_77 [ 0 ] -> V_159 )
return 0 ;
F_38 ( & V_24 -> V_160 ) ;
if ( V_2 -> V_11 ) {
V_11 = 1 ;
F_39 ( V_20 , 1 ) ;
}
F_40 ( V_2 ) ;
V_2 -> V_139 -> V_161 = V_149 ;
V_2 -> V_139 -> V_162 = V_148 ;
V_4 = F_41 ( V_2 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_15 ) ;
goto V_163;
}
if ( V_11 ) {
V_4 = F_42 ( V_20 ) ;
if ( V_4 )
F_10 ( V_2 , L_16 ) ;
}
V_4 = F_1 ( V_2 ) ;
V_163:
F_43 ( & V_24 -> V_160 ) ;
return V_4 ;
}
static void F_44 ( struct V_19 * V_20 ,
struct V_146 * V_147 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
memset ( V_147 , 0 , sizeof( * V_147 ) ) ;
V_147 -> V_164 = V_154 ;
V_147 -> V_165 = V_157 ;
V_147 -> V_152 = V_2 -> V_11 ?
V_2 -> V_80 [ 0 ] -> V_158 : V_2 -> V_80 [ 0 ] -> V_159 ;
V_147 -> V_155 = V_2 -> V_77 [ 0 ] -> V_159 ;
}
static T_1 F_45 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
return V_2 -> V_13 ;
}
static int F_46 ( struct V_19 * V_20 , T_1 * V_166 , T_6 * V_167 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_168 * V_169 = & V_2 -> V_169 ;
int V_170 ;
T_7 V_171 = V_2 -> V_13 ;
int V_4 = 0 ;
V_170 = V_2 -> V_139 -> V_170 ? : V_2 -> V_13 ;
while ( V_171 -- ) {
V_166 [ V_171 ] = V_169 -> V_172 [ V_171 % V_170 ] . V_173 -
V_169 -> V_174 ;
}
return V_4 ;
}
static int F_47 ( struct V_19 * V_20 , const T_1 * V_166 ,
const T_6 * V_167 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_11 = 0 ;
int V_4 = 0 ;
int V_3 ;
int V_170 = 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_13 ; V_3 ++ ) {
if ( V_3 > 0 && ! V_166 [ V_3 ] && ! V_170 )
V_170 = V_3 ;
if ( V_166 [ V_3 ] != ( V_3 % ( V_170 ? : V_2 -> V_13 ) ) )
return - V_56 ;
}
if ( ! V_170 )
V_170 = V_2 -> V_13 ;
if ( ! F_48 ( V_170 ) )
return - V_56 ;
F_38 ( & V_24 -> V_160 ) ;
if ( V_2 -> V_11 ) {
V_11 = 1 ;
F_39 ( V_20 , 1 ) ;
}
V_2 -> V_139 -> V_170 = V_170 ;
if ( V_11 ) {
V_4 = F_42 ( V_20 ) ;
if ( V_4 )
F_10 ( V_2 , L_16 ) ;
}
F_43 ( & V_24 -> V_160 ) ;
return V_4 ;
}
static int F_49 ( struct V_19 * V_20 ,
struct V_175 * V_92 )
{
struct V_176 * V_177 ;
struct V_178 * V_179 ;
struct V_180 * V_181 ;
if ( V_92 -> V_182 . V_183 >= V_184 )
return - V_56 ;
if ( V_92 -> V_182 . V_185 & V_186 ) {
if ( ! F_50 ( V_92 -> V_182 . V_187 . V_188 ) )
return - V_56 ;
}
switch ( V_92 -> V_182 . V_185 & ~ ( V_189 | V_186 ) ) {
case V_190 :
case V_191 :
if ( V_92 -> V_182 . V_192 . V_193 . V_194 )
return - V_56 ;
V_179 = & V_92 -> V_182 . V_192 . V_193 ;
if ( ! F_51 ( V_179 -> V_195 ) ||
! F_51 ( V_179 -> V_196 ) ||
! F_51 ( V_179 -> V_197 ) ||
! F_51 ( V_179 -> V_198 ) )
return - V_56 ;
break;
case V_199 :
V_177 = & V_92 -> V_182 . V_192 . V_200 ;
if ( V_177 -> V_201 || V_177 -> V_194 || V_177 -> V_202 ||
V_92 -> V_182 . V_203 . V_200 . V_204 != V_205 ||
( ! V_177 -> V_195 && ! V_177 -> V_196 ) ||
! F_51 ( V_177 -> V_195 ) ||
! F_51 ( V_177 -> V_196 ) )
return - V_56 ;
break;
case V_206 :
V_181 = & V_92 -> V_182 . V_192 . V_207 ;
if ( ! F_52 ( V_181 -> V_208 ) )
return - V_56 ;
if ( ! F_50 ( V_181 -> V_188 ) )
return - V_56 ;
if ( ! F_51 ( V_181 -> V_209 ) )
return - V_56 ;
break;
default:
return - V_56 ;
}
if ( ( V_92 -> V_182 . V_185 & V_189 ) ) {
if ( V_92 -> V_182 . V_187 . V_210 ||
! ( ( V_92 -> V_182 . V_187 . V_211 & F_53 ( V_212 ) ) ==
0 ||
( V_92 -> V_182 . V_187 . V_211 & F_53 ( V_212 ) ) ==
F_53 ( V_212 ) ) )
return - V_56 ;
if ( V_92 -> V_182 . V_187 . V_211 ) {
if ( F_54 ( V_92 -> V_182 . V_213 . V_211 ) >= V_214 )
return - V_56 ;
}
}
return 0 ;
}
static int F_55 ( struct V_175 * V_92 ,
struct V_215 * V_216 ,
struct V_217 * V_218 ,
unsigned char * V_219 )
{
int V_4 = 0 ;
T_8 V_220 = F_56 ( V_221 << 16 ) ;
V_218 -> V_222 = V_223 ;
memcpy ( V_218 -> V_224 . V_225 , & V_220 , V_226 ) ;
memcpy ( V_218 -> V_224 . V_227 , V_219 , V_226 ) ;
if ( ( V_92 -> V_182 . V_185 & V_189 ) &&
( V_92 -> V_182 . V_187 . V_211 & F_53 ( V_212 ) ) ) {
V_218 -> V_224 . V_228 = V_92 -> V_182 . V_213 . V_211 ;
V_218 -> V_224 . V_229 = F_53 ( V_212 ) ;
}
F_57 ( & V_218 -> V_230 , V_216 ) ;
return V_4 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_175 * V_92 ,
struct V_215 * V_216 ,
struct V_217 * V_218 ,
T_9 V_231 )
{
#ifdef F_59
unsigned char V_219 [ V_226 ] ;
if ( ! F_60 ( V_231 ) ) {
if ( V_92 -> V_182 . V_185 & V_186 )
memcpy ( & V_219 , V_92 -> V_182 . V_213 . V_188 , V_226 ) ;
else
memcpy ( & V_219 , V_2 -> V_20 -> V_232 , V_226 ) ;
} else {
F_61 ( V_231 , V_219 ) ;
}
return F_55 ( V_92 , V_216 , V_218 , & V_219 [ 0 ] ) ;
#else
return - V_56 ;
#endif
}
static int F_62 ( struct V_1 * V_2 ,
struct V_175 * V_92 ,
struct V_215 * V_233 )
{
int V_4 ;
struct V_217 * V_218 = NULL ;
struct V_217 * V_234 = NULL ;
struct V_176 * V_177 = & V_92 -> V_182 . V_192 . V_200 ;
V_234 = F_63 ( sizeof( * V_234 ) , V_235 ) ;
V_218 = F_63 ( sizeof( * V_218 ) , V_235 ) ;
if ( ! V_218 || ! V_234 ) {
V_4 = - V_99 ;
goto V_236;
}
V_4 = F_58 ( V_2 , V_92 , V_233 , V_218 ,
V_92 -> V_182 . V_203 .
V_200 . V_196 ) ;
if ( V_4 )
goto V_236;
V_234 -> V_222 = V_237 ;
V_234 -> V_238 . V_239 = V_92 -> V_182 . V_203 . V_200 . V_195 ;
if ( V_177 -> V_195 )
V_234 -> V_238 . V_240 = V_241 ;
V_234 -> V_238 . V_242 = V_92 -> V_182 . V_203 . V_200 . V_196 ;
if ( V_177 -> V_196 )
V_234 -> V_238 . V_243 = V_241 ;
F_57 ( & V_234 -> V_230 , V_233 ) ;
return 0 ;
V_236:
F_64 ( V_218 ) ;
F_64 ( V_234 ) ;
return V_4 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_175 * V_92 ,
struct V_215 * V_233 , int V_202 )
{
int V_4 ;
struct V_217 * V_218 = NULL ;
struct V_217 * V_234 = NULL ;
struct V_217 * V_244 = NULL ;
struct V_178 * V_179 = & V_92 -> V_182 . V_192 . V_193 ;
V_218 = F_63 ( sizeof( * V_218 ) , V_235 ) ;
V_234 = F_63 ( sizeof( * V_234 ) , V_235 ) ;
V_244 = F_63 ( sizeof( * V_244 ) , V_235 ) ;
if ( ! V_218 || ! V_234 || ! V_244 ) {
V_4 = - V_99 ;
goto V_236;
}
V_234 -> V_222 = V_237 ;
if ( V_202 == V_190 ) {
V_4 = F_58 ( V_2 , V_92 , V_233 ,
V_218 ,
V_92 -> V_182 . V_203 .
V_193 . V_196 ) ;
if ( V_4 )
goto V_236;
V_244 -> V_222 = V_245 ;
V_234 -> V_238 . V_239 = V_92 -> V_182 . V_203 . V_193 . V_195 ;
V_234 -> V_238 . V_242 = V_92 -> V_182 . V_203 . V_193 . V_196 ;
V_244 -> V_246 . V_247 = V_92 -> V_182 . V_203 . V_193 . V_197 ;
V_244 -> V_246 . V_248 = V_92 -> V_182 . V_203 . V_193 . V_198 ;
} else {
V_4 = F_58 ( V_2 , V_92 , V_233 ,
V_218 ,
V_92 -> V_182 . V_203 .
V_249 . V_196 ) ;
if ( V_4 )
goto V_236;
V_244 -> V_222 = V_250 ;
V_234 -> V_238 . V_239 = V_92 -> V_182 . V_203 . V_249 . V_195 ;
V_234 -> V_238 . V_242 = V_92 -> V_182 . V_203 . V_249 . V_196 ;
V_244 -> V_246 . V_247 = V_92 -> V_182 . V_203 . V_249 . V_197 ;
V_244 -> V_246 . V_248 = V_92 -> V_182 . V_203 . V_249 . V_198 ;
}
if ( V_179 -> V_195 )
V_234 -> V_238 . V_240 = V_241 ;
if ( V_179 -> V_196 )
V_234 -> V_238 . V_243 = V_241 ;
if ( V_179 -> V_197 )
V_244 -> V_246 . V_251 = V_252 ;
if ( V_179 -> V_198 )
V_244 -> V_246 . V_253 = V_252 ;
F_57 ( & V_234 -> V_230 , V_233 ) ;
F_57 ( & V_244 -> V_230 , V_233 ) ;
return 0 ;
V_236:
F_64 ( V_218 ) ;
F_64 ( V_234 ) ;
F_64 ( V_244 ) ;
return V_4 ;
}
static int F_66 ( struct V_19 * V_20 ,
struct V_175 * V_92 ,
struct V_215 * V_216 )
{
int V_4 ;
struct V_180 * V_254 ;
struct V_217 * V_218 ;
struct V_1 * V_2 = F_4 ( V_20 ) ;
V_4 = F_49 ( V_20 , V_92 ) ;
if ( V_4 )
return V_4 ;
switch ( V_92 -> V_182 . V_185 & ~ ( V_189 | V_186 ) ) {
case V_206 :
V_218 = F_63 ( sizeof( * V_218 ) , V_235 ) ;
if ( ! V_218 )
return - V_99 ;
V_254 = & V_92 -> V_182 . V_203 . V_207 ;
F_55 ( V_92 , V_216 , V_218 ,
& V_254 -> V_188 [ 0 ] ) ;
V_218 -> V_224 . V_255 = V_254 -> V_209 ;
if ( V_254 -> V_209 )
V_218 -> V_224 . V_256 = 1 ;
break;
case V_199 :
V_4 = F_62 ( V_2 , V_92 , V_216 ) ;
break;
case V_190 :
V_4 = F_65 ( V_2 , V_92 , V_216 , V_190 ) ;
break;
case V_191 :
V_4 = F_65 ( V_2 , V_92 , V_216 , V_191 ) ;
break;
}
return V_4 ;
}
static int F_67 ( struct V_19 * V_20 ,
struct V_175 * V_92 )
{
int V_4 ;
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_257 * V_258 ;
struct V_217 * V_259 , * V_260 ;
T_1 V_173 ;
T_2 V_261 ;
struct V_262 V_263 = {
. V_264 = V_265 ,
. V_266 = 0 ,
. V_267 = 1 ,
. V_268 = V_269 ,
} ;
V_263 . V_46 = V_2 -> V_46 ;
V_263 . V_270 = V_271 | V_92 -> V_182 . V_183 ;
F_68 ( & V_263 . V_230 ) ;
if ( V_92 -> V_182 . V_272 == V_273 )
V_173 = V_2 -> V_274 . V_173 ;
else if ( V_92 -> V_182 . V_272 & V_275 ) {
V_173 = V_92 -> V_182 . V_272 & ( V_275 - 1 ) ;
} else {
if ( V_92 -> V_182 . V_272 >= V_2 -> V_13 ) {
F_69 ( V_2 , L_17 ,
V_92 -> V_182 . V_272 ) ;
return - V_56 ;
}
V_173 = V_2 -> V_169 . V_172 [ V_92 -> V_182 . V_272 ] . V_173 ;
if ( ! V_173 ) {
F_69 ( V_2 , L_18 ,
V_92 -> V_182 . V_272 ) ;
return - V_56 ;
}
}
V_263 . V_173 = V_173 ;
V_4 = F_66 ( V_20 , V_92 , & V_263 . V_230 ) ;
if ( V_4 )
goto V_276;
V_258 = & V_2 -> V_277 [ V_92 -> V_182 . V_183 ] ;
if ( V_258 -> V_222 ) {
V_4 = F_70 ( V_2 -> V_24 -> V_20 , V_258 -> V_222 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_19 ,
V_92 -> V_182 . V_183 , V_258 -> V_222 ) ;
goto V_276;
}
V_258 -> V_222 = 0 ;
memset ( & V_258 -> V_278 , 0 ,
sizeof( struct V_279 ) ) ;
F_71 ( & V_258 -> V_230 ) ;
}
V_4 = F_72 ( V_2 -> V_24 -> V_20 , & V_263 , & V_261 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_20 ,
V_92 -> V_182 . V_183 ) ;
goto V_276;
}
V_258 -> V_222 = V_261 ;
memcpy ( & V_258 -> V_278 , & V_92 -> V_182 ,
sizeof( struct V_279 ) ) ;
F_57 ( & V_258 -> V_230 , & V_2 -> V_280 ) ;
V_276:
F_73 (spec, tmp_spec, &rule.list, list) {
F_71 ( & V_259 -> V_230 ) ;
F_64 ( V_259 ) ;
}
return V_4 ;
}
static int F_74 ( struct V_19 * V_20 ,
struct V_175 * V_92 )
{
int V_4 = 0 ;
struct V_257 * V_263 ;
struct V_1 * V_2 = F_4 ( V_20 ) ;
if ( V_92 -> V_182 . V_183 >= V_184 )
return - V_56 ;
V_263 = & V_2 -> V_277 [ V_92 -> V_182 . V_183 ] ;
if ( ! V_263 -> V_222 ) {
V_4 = - V_281 ;
goto V_163;
}
V_4 = F_70 ( V_2 -> V_24 -> V_20 , V_263 -> V_222 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_21 ,
V_92 -> V_182 . V_183 , V_263 -> V_222 ) ;
goto V_163;
}
V_263 -> V_222 = 0 ;
memset ( & V_263 -> V_278 , 0 , sizeof( struct V_279 ) ) ;
F_71 ( & V_263 -> V_230 ) ;
V_163:
return V_4 ;
}
static int F_75 ( struct V_19 * V_20 , struct V_175 * V_92 ,
int V_282 )
{
int V_4 = 0 ;
struct V_257 * V_263 ;
struct V_1 * V_2 = F_4 ( V_20 ) ;
if ( V_282 < 0 || V_282 >= V_184 )
return - V_56 ;
V_263 = & V_2 -> V_277 [ V_282 ] ;
if ( V_263 -> V_222 )
memcpy ( & V_92 -> V_182 , & V_263 -> V_278 ,
sizeof( struct V_279 ) ) ;
else
V_4 = - V_281 ;
return V_4 ;
}
static int F_76 ( struct V_1 * V_2 )
{
int V_3 , V_283 = 0 ;
for ( V_3 = 0 ; V_3 < V_184 ; V_3 ++ ) {
if ( V_2 -> V_277 [ V_3 ] . V_222 )
V_283 ++ ;
}
return V_283 ;
}
static int F_77 ( struct V_19 * V_20 , struct V_175 * V_92 ,
T_1 * V_284 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_4 = 0 ;
int V_3 = 0 , V_270 = 0 ;
if ( ( V_92 -> V_92 == V_285 ||
V_92 -> V_92 == V_286 ||
V_92 -> V_92 == V_287 ) &&
( V_24 -> V_20 -> V_32 . V_288 !=
V_289 || ! V_2 -> V_11 ) )
return - V_56 ;
switch ( V_92 -> V_92 ) {
case V_290 :
V_92 -> V_68 = V_2 -> V_13 ;
break;
case V_285 :
V_92 -> V_291 = F_76 ( V_2 ) ;
break;
case V_286 :
V_4 = F_75 ( V_20 , V_92 , V_92 -> V_182 . V_183 ) ;
break;
case V_287 :
while ( ( ! V_4 || V_4 == - V_281 ) && V_270 < V_92 -> V_291 ) {
V_4 = F_75 ( V_20 , V_92 , V_3 ) ;
if ( ! V_4 )
V_284 [ V_270 ++ ] = V_3 ;
V_3 ++ ;
}
V_4 = 0 ;
break;
default:
V_4 = - V_55 ;
break;
}
return V_4 ;
}
static int F_78 ( struct V_19 * V_20 , struct V_175 * V_92 )
{
int V_4 = 0 ;
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
if ( V_24 -> V_20 -> V_32 . V_288 !=
V_289 || ! V_2 -> V_11 )
return - V_56 ;
switch ( V_92 -> V_92 ) {
case V_292 :
V_4 = F_67 ( V_20 , V_92 ) ;
break;
case V_293 :
V_4 = F_74 ( V_20 , V_92 ) ;
break;
default:
F_69 ( V_2 , L_22 , V_92 -> V_92 ) ;
return - V_56 ;
}
return V_4 ;
}
static void F_79 ( struct V_19 * V_20 ,
struct V_294 * V_295 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
memset ( V_295 , 0 , sizeof( * V_295 ) ) ;
V_295 -> V_296 = V_297 ;
V_295 -> V_298 = V_299 ;
V_295 -> V_300 = V_2 -> V_13 ;
V_295 -> V_301 = V_2 -> V_5 / V_302 ;
}
static int F_80 ( struct V_19 * V_20 ,
struct V_294 * V_295 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_11 = 0 ;
int V_4 = 0 ;
if ( V_295 -> V_303 || V_295 -> V_304 ||
V_295 -> V_301 > V_299 ||
V_295 -> V_300 > V_297 ||
! V_295 -> V_301 || ! V_295 -> V_300 )
return - V_56 ;
F_38 ( & V_24 -> V_160 ) ;
if ( V_2 -> V_11 ) {
V_11 = 1 ;
F_39 ( V_20 , 1 ) ;
}
F_40 ( V_2 ) ;
V_2 -> V_305 = V_295 -> V_301 ;
V_2 -> V_5 = V_295 -> V_301 * V_302 ;
V_2 -> V_13 = V_295 -> V_300 ;
V_4 = F_41 ( V_2 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_15 ) ;
goto V_163;
}
F_81 ( V_20 , V_2 -> V_5 ) ;
F_82 ( V_20 , V_2 -> V_13 ) ;
if ( V_20 -> V_306 )
F_83 ( V_20 , V_302 ) ;
F_69 ( V_2 , L_23 , V_2 -> V_5 ) ;
F_69 ( V_2 , L_24 , V_2 -> V_13 ) ;
if ( V_11 ) {
V_4 = F_42 ( V_20 ) ;
if ( V_4 )
F_10 ( V_2 , L_16 ) ;
}
V_4 = F_1 ( V_2 ) ;
V_163:
F_43 ( & V_24 -> V_160 ) ;
return V_4 ;
}
static int F_84 ( struct V_19 * V_20 ,
struct V_307 * V_308 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_309 ;
V_309 = F_85 ( V_20 , V_308 ) ;
if ( V_309 )
return V_309 ;
if ( V_24 -> V_20 -> V_32 . V_310 & V_311 ) {
V_308 -> V_312 |=
V_313 |
V_314 |
V_315 ;
V_308 -> V_316 =
( 1 << V_317 ) |
( 1 << V_318 ) ;
V_308 -> V_319 =
( 1 << V_320 ) |
( 1 << V_321 ) ;
if ( V_24 -> V_322 )
V_308 -> V_323 = F_86 ( V_24 -> V_322 ) ;
}
return V_309 ;
}
