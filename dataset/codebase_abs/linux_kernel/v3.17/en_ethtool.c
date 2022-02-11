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
case V_66 :
return F_17 ( V_67 ) ;
default:
return - V_55 ;
}
}
static void F_18 ( struct V_19 * V_20 ,
struct V_68 * V_69 , T_3 * V_70 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
int V_71 = 0 ;
int V_3 , V_72 = 0 ;
F_19 ( & V_2 -> V_73 ) ;
if ( ! ( V_2 -> V_60 ) ) {
for ( V_3 = 0 ; V_3 < V_74 ; V_3 ++ )
V_70 [ V_71 ++ ] =
( ( unsigned long * ) & V_2 -> V_69 ) [ V_3 ] ;
for ( V_3 = 0 ; V_3 < V_75 ; V_3 ++ )
V_70 [ V_71 ++ ] =
( ( unsigned long * ) & V_2 -> V_76 ) [ V_3 ] ;
for ( V_3 = 0 ; V_3 < V_77 ; V_3 ++ )
V_70 [ V_71 ++ ] =
( ( unsigned long * ) & V_2 -> V_78 ) [ V_3 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_74 ; V_3 ++ ) {
if ( ( V_2 -> V_60 >> V_72 ) & 1 )
V_70 [ V_71 ++ ] =
( ( unsigned long * ) & V_2 -> V_69 ) [ V_3 ] ;
V_72 ++ ;
}
for ( V_3 = 0 ; V_3 < V_75 ; V_3 ++ ) {
if ( ( V_2 -> V_60 >> V_72 ) & 1 )
V_70 [ V_71 ++ ] =
( ( unsigned long * ) & V_2 -> V_76 ) [ V_3 ] ;
V_72 ++ ;
}
}
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
V_70 [ V_71 ++ ] = V_2 -> V_79 [ V_3 ] -> V_80 ;
V_70 [ V_71 ++ ] = V_2 -> V_79 [ V_3 ] -> V_81 ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_13 ; V_3 ++ ) {
V_70 [ V_71 ++ ] = V_2 -> V_82 [ V_3 ] -> V_80 ;
V_70 [ V_71 ++ ] = V_2 -> V_82 [ V_3 ] -> V_81 ;
#ifdef F_16
V_70 [ V_71 ++ ] = V_2 -> V_82 [ V_3 ] -> V_83 ;
V_70 [ V_71 ++ ] = V_2 -> V_82 [ V_3 ] -> V_84 ;
V_70 [ V_71 ++ ] = V_2 -> V_82 [ V_3 ] -> V_85 ;
#endif
}
F_20 ( & V_2 -> V_73 ) ;
}
static void F_21 ( struct V_19 * V_20 ,
struct V_86 * V_87 , T_2 * V_88 )
{
F_22 ( V_20 , & V_87 -> V_49 , V_88 ) ;
}
static void F_23 ( struct V_19 * V_20 ,
T_4 V_89 , T_5 * V_70 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
int V_71 = 0 ;
int V_3 ;
switch ( V_89 ) {
case V_63 :
for ( V_3 = 0 ; V_3 < V_64 - 2 ; V_3 ++ )
strcpy ( V_70 + V_3 * V_90 , V_91 [ V_3 ] ) ;
if ( V_2 -> V_24 -> V_20 -> V_32 . V_49 & V_65 )
for (; V_3 < V_64 ; V_3 ++ )
strcpy ( V_70 + V_3 * V_90 , V_91 [ V_3 ] ) ;
break;
case V_61 :
if ( ! V_2 -> V_60 ) {
for ( V_3 = 0 ; V_3 < V_74 ; V_3 ++ )
strcpy ( V_70 + ( V_71 ++ ) * V_90 ,
V_92 [ V_3 ] ) ;
for ( V_3 = 0 ; V_3 < V_75 ; V_3 ++ )
strcpy ( V_70 + ( V_71 ++ ) * V_90 ,
V_92 [ V_3 +
V_74 ] ) ;
for ( V_3 = 0 ; V_3 < V_77 ; V_3 ++ )
strcpy ( V_70 + ( V_71 ++ ) * V_90 ,
V_92 [ V_3 +
V_74 +
V_75 ] ) ;
} else
for ( V_3 = 0 ; V_3 < V_74 + V_75 ; V_3 ++ ) {
if ( ( V_2 -> V_60 >> V_3 ) & 1 ) {
strcpy ( V_70 +
( V_71 ++ ) * V_90 ,
V_92 [ V_3 ] ) ;
}
if ( ! ( V_2 -> V_60 >> V_3 ) )
break;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
sprintf ( V_70 + ( V_71 ++ ) * V_90 ,
L_7 , V_3 ) ;
sprintf ( V_70 + ( V_71 ++ ) * V_90 ,
L_8 , V_3 ) ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_13 ; V_3 ++ ) {
sprintf ( V_70 + ( V_71 ++ ) * V_90 ,
L_9 , V_3 ) ;
sprintf ( V_70 + ( V_71 ++ ) * V_90 ,
L_10 , V_3 ) ;
#ifdef F_16
sprintf ( V_70 + ( V_71 ++ ) * V_90 ,
L_11 , V_3 ) ;
sprintf ( V_70 + ( V_71 ++ ) * V_90 ,
L_12 , V_3 ) ;
sprintf ( V_70 + ( V_71 ++ ) * V_90 ,
L_13 , V_3 ) ;
#endif
}
break;
case V_66 :
for ( V_3 = 0 ; V_3 < F_17 ( V_67 ) ; V_3 ++ )
strcpy ( V_70 + V_3 * V_90 ,
V_67 [ V_3 ] ) ;
break;
}
}
static int F_24 ( struct V_19 * V_20 , struct V_93 * V_94 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
int V_95 ;
V_94 -> V_96 = V_97 ;
V_94 -> V_50 = V_98 ;
V_94 -> V_99 = V_100 ;
if ( F_25 ( V_2 -> V_24 , V_2 -> V_46 ) )
return - V_101 ;
V_95 = V_2 -> V_102 . V_103 ;
if ( F_26 ( V_20 ) ) {
F_27 ( V_94 , V_2 -> V_102 . V_104 ) ;
V_94 -> V_105 = V_106 ;
} else {
F_27 ( V_94 , V_107 ) ;
V_94 -> V_105 = V_108 ;
}
if ( V_95 > 0 && V_95 <= 0xC ) {
V_94 -> V_46 = V_109 ;
V_94 -> V_110 = V_111 ;
V_94 -> V_50 |= V_112 ;
V_94 -> V_99 |= V_113 ;
} else if ( V_95 == 0x80 || V_95 == 0 ) {
V_94 -> V_46 = V_114 ;
V_94 -> V_110 = V_115 ;
V_94 -> V_50 |= V_116 ;
V_94 -> V_99 |= V_117 ;
} else {
V_94 -> V_46 = - 1 ;
V_94 -> V_110 = - 1 ;
}
return 0 ;
}
static int F_28 ( struct V_19 * V_20 , struct V_93 * V_94 )
{
if ( ( V_94 -> V_96 == V_118 ) ||
( F_29 ( V_94 ) != V_119 ) ||
( V_94 -> V_105 != V_106 ) )
return - V_56 ;
return 0 ;
}
static int F_30 ( struct V_19 * V_20 ,
struct V_120 * V_121 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
V_121 -> V_122 = V_2 -> V_10 ;
V_121 -> V_123 = V_2 -> V_8 ;
V_121 -> V_124 = V_2 -> V_125 ;
V_121 -> V_126 = V_2 -> V_16 ;
V_121 -> V_127 = V_2 -> V_15 ;
V_121 -> V_128 = V_2 -> V_128 ;
V_121 -> V_129 = V_2 -> V_130 ;
V_121 -> V_131 = V_2 -> V_131 ;
V_121 -> V_132 = V_2 -> V_133 ;
V_121 -> V_134 = V_2 -> V_135 ;
V_121 -> V_136 = V_2 -> V_12 ;
return 0 ;
}
static int F_31 ( struct V_19 * V_20 ,
struct V_120 * V_121 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
if ( ! V_121 -> V_124 )
return - V_56 ;
V_2 -> V_15 = ( V_121 -> V_127 ==
V_18 ) ?
V_137 :
V_121 -> V_127 ;
V_2 -> V_16 = ( V_121 -> V_126 ==
V_18 ) ?
V_138 :
V_121 -> V_126 ;
if ( V_121 -> V_122 != V_2 -> V_10 ||
V_121 -> V_123 != V_2 -> V_8 ) {
V_2 -> V_10 = V_121 -> V_122 ;
V_2 -> V_8 = V_121 -> V_123 ;
}
V_2 -> V_128 = V_121 -> V_128 ;
V_2 -> V_130 = V_121 -> V_129 ;
V_2 -> V_131 = V_121 -> V_131 ;
V_2 -> V_133 = V_121 -> V_132 ;
V_2 -> V_135 = V_121 -> V_134 ;
V_2 -> V_12 = V_121 -> V_136 ;
V_2 -> V_125 = V_121 -> V_124 ;
return F_1 ( V_2 ) ;
}
static int F_32 ( struct V_19 * V_20 ,
struct V_139 * V_140 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_4 ;
if ( V_140 -> V_96 )
return - V_56 ;
V_2 -> V_141 -> V_142 = V_140 -> V_142 != 0 ;
V_2 -> V_141 -> V_143 = V_140 -> V_143 != 0 ;
V_4 = F_33 ( V_24 -> V_20 , V_2 -> V_46 ,
V_2 -> V_144 + V_145 ,
V_2 -> V_141 -> V_142 ,
V_2 -> V_141 -> V_146 ,
V_2 -> V_141 -> V_143 ,
V_2 -> V_141 -> V_147 ) ;
if ( V_4 )
F_10 ( V_2 , L_14 ) ;
return V_4 ;
}
static void F_34 ( struct V_19 * V_20 ,
struct V_139 * V_140 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
V_140 -> V_142 = V_2 -> V_141 -> V_142 ;
V_140 -> V_143 = V_2 -> V_141 -> V_143 ;
}
static int F_35 ( struct V_19 * V_20 ,
struct V_148 * V_149 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
T_1 V_150 , V_151 ;
int V_11 = 0 ;
int V_4 = 0 ;
if ( V_149 -> V_152 || V_149 -> V_153 )
return - V_56 ;
V_150 = F_36 ( V_149 -> V_154 ) ;
V_150 = F_37 ( T_1 , V_150 , V_155 ) ;
V_150 = F_38 ( T_1 , V_150 , V_156 ) ;
V_151 = F_36 ( V_149 -> V_157 ) ;
V_151 = F_37 ( T_1 , V_151 , V_158 ) ;
V_151 = F_38 ( T_1 , V_151 , V_159 ) ;
if ( V_150 == ( V_2 -> V_11 ? V_2 -> V_82 [ 0 ] -> V_160 :
V_2 -> V_82 [ 0 ] -> V_161 ) &&
V_151 == V_2 -> V_79 [ 0 ] -> V_161 )
return 0 ;
F_39 ( & V_24 -> V_162 ) ;
if ( V_2 -> V_11 ) {
V_11 = 1 ;
F_40 ( V_20 , 1 ) ;
}
F_41 ( V_2 ) ;
V_2 -> V_141 -> V_163 = V_151 ;
V_2 -> V_141 -> V_164 = V_150 ;
V_4 = F_42 ( V_2 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_15 ) ;
goto V_165;
}
if ( V_11 ) {
V_4 = F_43 ( V_20 ) ;
if ( V_4 )
F_10 ( V_2 , L_16 ) ;
}
V_4 = F_1 ( V_2 ) ;
V_165:
F_44 ( & V_24 -> V_162 ) ;
return V_4 ;
}
static void F_45 ( struct V_19 * V_20 ,
struct V_148 * V_149 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
memset ( V_149 , 0 , sizeof( * V_149 ) ) ;
V_149 -> V_166 = V_156 ;
V_149 -> V_167 = V_159 ;
V_149 -> V_154 = V_2 -> V_11 ?
V_2 -> V_82 [ 0 ] -> V_160 : V_2 -> V_82 [ 0 ] -> V_161 ;
V_149 -> V_157 = V_2 -> V_79 [ 0 ] -> V_161 ;
}
static T_1 F_46 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
return V_2 -> V_13 ;
}
static int F_47 ( struct V_19 * V_20 , T_1 * V_168 , T_6 * V_169 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_170 * V_171 = & V_2 -> V_171 ;
int V_172 ;
T_7 V_173 = V_2 -> V_13 ;
int V_4 = 0 ;
V_172 = V_2 -> V_141 -> V_172 ? : V_2 -> V_13 ;
while ( V_173 -- ) {
V_168 [ V_173 ] = V_171 -> V_174 [ V_173 % V_172 ] . V_175 -
V_171 -> V_176 ;
}
return V_4 ;
}
static int F_48 ( struct V_19 * V_20 , const T_1 * V_168 ,
const T_6 * V_169 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_11 = 0 ;
int V_4 = 0 ;
int V_3 ;
int V_172 = 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_13 ; V_3 ++ ) {
if ( V_3 > 0 && ! V_168 [ V_3 ] && ! V_172 )
V_172 = V_3 ;
if ( V_168 [ V_3 ] != ( V_3 % ( V_172 ? : V_2 -> V_13 ) ) )
return - V_56 ;
}
if ( ! V_172 )
V_172 = V_2 -> V_13 ;
if ( ! F_49 ( V_172 ) )
return - V_56 ;
F_39 ( & V_24 -> V_162 ) ;
if ( V_2 -> V_11 ) {
V_11 = 1 ;
F_40 ( V_20 , 1 ) ;
}
V_2 -> V_141 -> V_172 = V_172 ;
if ( V_11 ) {
V_4 = F_43 ( V_20 ) ;
if ( V_4 )
F_10 ( V_2 , L_16 ) ;
}
F_44 ( & V_24 -> V_162 ) ;
return V_4 ;
}
static int F_50 ( struct V_19 * V_20 ,
struct V_177 * V_94 )
{
struct V_178 * V_179 ;
struct V_180 * V_181 ;
struct V_182 * V_183 ;
if ( V_94 -> V_184 . V_185 >= V_186 )
return - V_56 ;
if ( V_94 -> V_184 . V_187 & V_188 ) {
if ( ! F_51 ( V_94 -> V_184 . V_189 . V_190 ) )
return - V_56 ;
}
switch ( V_94 -> V_184 . V_187 & ~ ( V_191 | V_188 ) ) {
case V_192 :
case V_193 :
if ( V_94 -> V_184 . V_194 . V_195 . V_196 )
return - V_56 ;
V_181 = & V_94 -> V_184 . V_194 . V_195 ;
if ( ! F_52 ( V_181 -> V_197 ) ||
! F_52 ( V_181 -> V_198 ) ||
! F_52 ( V_181 -> V_199 ) ||
! F_52 ( V_181 -> V_200 ) )
return - V_56 ;
break;
case V_201 :
V_179 = & V_94 -> V_184 . V_194 . V_202 ;
if ( V_179 -> V_203 || V_179 -> V_196 || V_179 -> V_204 ||
V_94 -> V_184 . V_205 . V_202 . V_206 != V_207 ||
( ! V_179 -> V_197 && ! V_179 -> V_198 ) ||
! F_52 ( V_179 -> V_197 ) ||
! F_52 ( V_179 -> V_198 ) )
return - V_56 ;
break;
case V_208 :
V_183 = & V_94 -> V_184 . V_194 . V_209 ;
if ( ! F_53 ( V_183 -> V_210 ) )
return - V_56 ;
if ( ! F_51 ( V_183 -> V_190 ) )
return - V_56 ;
if ( ! F_52 ( V_183 -> V_211 ) )
return - V_56 ;
break;
default:
return - V_56 ;
}
if ( ( V_94 -> V_184 . V_187 & V_191 ) ) {
if ( V_94 -> V_184 . V_189 . V_212 ||
! ( ( V_94 -> V_184 . V_189 . V_213 & F_54 ( V_214 ) ) ==
0 ||
( V_94 -> V_184 . V_189 . V_213 & F_54 ( V_214 ) ) ==
F_54 ( V_214 ) ) )
return - V_56 ;
if ( V_94 -> V_184 . V_189 . V_213 ) {
if ( F_55 ( V_94 -> V_184 . V_215 . V_213 ) >= V_216 )
return - V_56 ;
}
}
return 0 ;
}
static int F_56 ( struct V_177 * V_94 ,
struct V_217 * V_218 ,
struct V_219 * V_220 ,
unsigned char * V_221 )
{
int V_4 = 0 ;
T_8 V_222 = F_57 ( V_223 << 16 ) ;
V_220 -> V_224 = V_225 ;
memcpy ( V_220 -> V_226 . V_227 , & V_222 , V_228 ) ;
memcpy ( V_220 -> V_226 . V_229 , V_221 , V_228 ) ;
if ( ( V_94 -> V_184 . V_187 & V_191 ) &&
( V_94 -> V_184 . V_189 . V_213 & F_54 ( V_214 ) ) ) {
V_220 -> V_226 . V_230 = V_94 -> V_184 . V_215 . V_213 ;
V_220 -> V_226 . V_231 = F_54 ( V_214 ) ;
}
F_58 ( & V_220 -> V_232 , V_218 ) ;
return V_4 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_177 * V_94 ,
struct V_217 * V_218 ,
struct V_219 * V_220 ,
T_9 V_233 )
{
#ifdef F_60
unsigned char V_221 [ V_228 ] ;
if ( ! F_61 ( V_233 ) ) {
if ( V_94 -> V_184 . V_187 & V_188 )
memcpy ( & V_221 , V_94 -> V_184 . V_215 . V_190 , V_228 ) ;
else
memcpy ( & V_221 , V_2 -> V_20 -> V_234 , V_228 ) ;
} else {
F_62 ( V_233 , V_221 ) ;
}
return F_56 ( V_94 , V_218 , V_220 , & V_221 [ 0 ] ) ;
#else
return - V_56 ;
#endif
}
static int F_63 ( struct V_1 * V_2 ,
struct V_177 * V_94 ,
struct V_217 * V_235 )
{
int V_4 ;
struct V_219 * V_220 = NULL ;
struct V_219 * V_236 = NULL ;
struct V_178 * V_179 = & V_94 -> V_184 . V_194 . V_202 ;
V_236 = F_64 ( sizeof( * V_236 ) , V_237 ) ;
V_220 = F_64 ( sizeof( * V_220 ) , V_237 ) ;
if ( ! V_220 || ! V_236 ) {
V_4 = - V_101 ;
goto V_238;
}
V_4 = F_59 ( V_2 , V_94 , V_235 , V_220 ,
V_94 -> V_184 . V_205 .
V_202 . V_198 ) ;
if ( V_4 )
goto V_238;
V_236 -> V_224 = V_239 ;
V_236 -> V_240 . V_241 = V_94 -> V_184 . V_205 . V_202 . V_197 ;
if ( V_179 -> V_197 )
V_236 -> V_240 . V_242 = V_243 ;
V_236 -> V_240 . V_244 = V_94 -> V_184 . V_205 . V_202 . V_198 ;
if ( V_179 -> V_198 )
V_236 -> V_240 . V_245 = V_243 ;
F_58 ( & V_236 -> V_232 , V_235 ) ;
return 0 ;
V_238:
F_65 ( V_220 ) ;
F_65 ( V_236 ) ;
return V_4 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_177 * V_94 ,
struct V_217 * V_235 , int V_204 )
{
int V_4 ;
struct V_219 * V_220 = NULL ;
struct V_219 * V_236 = NULL ;
struct V_219 * V_246 = NULL ;
struct V_180 * V_181 = & V_94 -> V_184 . V_194 . V_195 ;
V_220 = F_64 ( sizeof( * V_220 ) , V_237 ) ;
V_236 = F_64 ( sizeof( * V_236 ) , V_237 ) ;
V_246 = F_64 ( sizeof( * V_246 ) , V_237 ) ;
if ( ! V_220 || ! V_236 || ! V_246 ) {
V_4 = - V_101 ;
goto V_238;
}
V_236 -> V_224 = V_239 ;
if ( V_204 == V_192 ) {
V_4 = F_59 ( V_2 , V_94 , V_235 ,
V_220 ,
V_94 -> V_184 . V_205 .
V_195 . V_198 ) ;
if ( V_4 )
goto V_238;
V_246 -> V_224 = V_247 ;
V_236 -> V_240 . V_241 = V_94 -> V_184 . V_205 . V_195 . V_197 ;
V_236 -> V_240 . V_244 = V_94 -> V_184 . V_205 . V_195 . V_198 ;
V_246 -> V_248 . V_249 = V_94 -> V_184 . V_205 . V_195 . V_199 ;
V_246 -> V_248 . V_250 = V_94 -> V_184 . V_205 . V_195 . V_200 ;
} else {
V_4 = F_59 ( V_2 , V_94 , V_235 ,
V_220 ,
V_94 -> V_184 . V_205 .
V_251 . V_198 ) ;
if ( V_4 )
goto V_238;
V_246 -> V_224 = V_252 ;
V_236 -> V_240 . V_241 = V_94 -> V_184 . V_205 . V_251 . V_197 ;
V_236 -> V_240 . V_244 = V_94 -> V_184 . V_205 . V_251 . V_198 ;
V_246 -> V_248 . V_249 = V_94 -> V_184 . V_205 . V_251 . V_199 ;
V_246 -> V_248 . V_250 = V_94 -> V_184 . V_205 . V_251 . V_200 ;
}
if ( V_181 -> V_197 )
V_236 -> V_240 . V_242 = V_243 ;
if ( V_181 -> V_198 )
V_236 -> V_240 . V_245 = V_243 ;
if ( V_181 -> V_199 )
V_246 -> V_248 . V_253 = V_254 ;
if ( V_181 -> V_200 )
V_246 -> V_248 . V_255 = V_254 ;
F_58 ( & V_236 -> V_232 , V_235 ) ;
F_58 ( & V_246 -> V_232 , V_235 ) ;
return 0 ;
V_238:
F_65 ( V_220 ) ;
F_65 ( V_236 ) ;
F_65 ( V_246 ) ;
return V_4 ;
}
static int F_67 ( struct V_19 * V_20 ,
struct V_177 * V_94 ,
struct V_217 * V_218 )
{
int V_4 ;
struct V_182 * V_256 ;
struct V_219 * V_220 ;
struct V_1 * V_2 = F_4 ( V_20 ) ;
V_4 = F_50 ( V_20 , V_94 ) ;
if ( V_4 )
return V_4 ;
switch ( V_94 -> V_184 . V_187 & ~ ( V_191 | V_188 ) ) {
case V_208 :
V_220 = F_64 ( sizeof( * V_220 ) , V_237 ) ;
if ( ! V_220 )
return - V_101 ;
V_256 = & V_94 -> V_184 . V_205 . V_209 ;
F_56 ( V_94 , V_218 , V_220 ,
& V_256 -> V_190 [ 0 ] ) ;
V_220 -> V_226 . V_257 = V_256 -> V_211 ;
if ( V_256 -> V_211 )
V_220 -> V_226 . V_258 = 1 ;
break;
case V_201 :
V_4 = F_63 ( V_2 , V_94 , V_218 ) ;
break;
case V_192 :
V_4 = F_66 ( V_2 , V_94 , V_218 , V_192 ) ;
break;
case V_193 :
V_4 = F_66 ( V_2 , V_94 , V_218 , V_193 ) ;
break;
}
return V_4 ;
}
static int F_68 ( struct V_19 * V_20 ,
struct V_177 * V_94 )
{
int V_4 ;
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_259 * V_260 ;
struct V_219 * V_261 , * V_262 ;
T_1 V_175 ;
T_2 V_263 ;
struct V_264 V_265 = {
. V_266 = V_267 ,
. V_268 = 0 ,
. V_269 = 1 ,
. V_270 = V_271 ,
} ;
V_265 . V_46 = V_2 -> V_46 ;
V_265 . V_272 = V_273 | V_94 -> V_184 . V_185 ;
F_69 ( & V_265 . V_232 ) ;
if ( V_94 -> V_184 . V_274 == V_275 )
V_175 = V_2 -> V_276 . V_175 ;
else if ( V_94 -> V_184 . V_274 & V_277 ) {
V_175 = V_94 -> V_184 . V_274 & ( V_277 - 1 ) ;
} else {
if ( V_94 -> V_184 . V_274 >= V_2 -> V_13 ) {
F_70 ( V_2 , L_17 ,
V_94 -> V_184 . V_274 ) ;
return - V_56 ;
}
V_175 = V_2 -> V_171 . V_174 [ V_94 -> V_184 . V_274 ] . V_175 ;
if ( ! V_175 ) {
F_70 ( V_2 , L_18 ,
V_94 -> V_184 . V_274 ) ;
return - V_56 ;
}
}
V_265 . V_175 = V_175 ;
V_4 = F_67 ( V_20 , V_94 , & V_265 . V_232 ) ;
if ( V_4 )
goto V_278;
V_260 = & V_2 -> V_279 [ V_94 -> V_184 . V_185 ] ;
if ( V_260 -> V_224 ) {
V_4 = F_71 ( V_2 -> V_24 -> V_20 , V_260 -> V_224 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_19 ,
V_94 -> V_184 . V_185 , V_260 -> V_224 ) ;
goto V_278;
}
V_260 -> V_224 = 0 ;
memset ( & V_260 -> V_280 , 0 ,
sizeof( struct V_281 ) ) ;
F_72 ( & V_260 -> V_232 ) ;
}
V_4 = F_73 ( V_2 -> V_24 -> V_20 , & V_265 , & V_263 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_20 ,
V_94 -> V_184 . V_185 ) ;
goto V_278;
}
V_260 -> V_224 = V_263 ;
memcpy ( & V_260 -> V_280 , & V_94 -> V_184 ,
sizeof( struct V_281 ) ) ;
F_58 ( & V_260 -> V_232 , & V_2 -> V_282 ) ;
V_278:
F_74 (spec, tmp_spec, &rule.list, list) {
F_72 ( & V_261 -> V_232 ) ;
F_65 ( V_261 ) ;
}
return V_4 ;
}
static int F_75 ( struct V_19 * V_20 ,
struct V_177 * V_94 )
{
int V_4 = 0 ;
struct V_259 * V_265 ;
struct V_1 * V_2 = F_4 ( V_20 ) ;
if ( V_94 -> V_184 . V_185 >= V_186 )
return - V_56 ;
V_265 = & V_2 -> V_279 [ V_94 -> V_184 . V_185 ] ;
if ( ! V_265 -> V_224 ) {
V_4 = - V_283 ;
goto V_165;
}
V_4 = F_71 ( V_2 -> V_24 -> V_20 , V_265 -> V_224 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_21 ,
V_94 -> V_184 . V_185 , V_265 -> V_224 ) ;
goto V_165;
}
V_265 -> V_224 = 0 ;
memset ( & V_265 -> V_280 , 0 , sizeof( struct V_281 ) ) ;
F_72 ( & V_265 -> V_232 ) ;
V_165:
return V_4 ;
}
static int F_76 ( struct V_19 * V_20 , struct V_177 * V_94 ,
int V_284 )
{
int V_4 = 0 ;
struct V_259 * V_265 ;
struct V_1 * V_2 = F_4 ( V_20 ) ;
if ( V_284 < 0 || V_284 >= V_186 )
return - V_56 ;
V_265 = & V_2 -> V_279 [ V_284 ] ;
if ( V_265 -> V_224 )
memcpy ( & V_94 -> V_184 , & V_265 -> V_280 ,
sizeof( struct V_281 ) ) ;
else
V_4 = - V_283 ;
return V_4 ;
}
static int F_77 ( struct V_1 * V_2 )
{
int V_3 , V_285 = 0 ;
for ( V_3 = 0 ; V_3 < V_186 ; V_3 ++ ) {
if ( V_2 -> V_279 [ V_3 ] . V_224 )
V_285 ++ ;
}
return V_285 ;
}
static int F_78 ( struct V_19 * V_20 , struct V_177 * V_94 ,
T_1 * V_286 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_4 = 0 ;
int V_3 = 0 , V_272 = 0 ;
if ( ( V_94 -> V_94 == V_287 ||
V_94 -> V_94 == V_288 ||
V_94 -> V_94 == V_289 ) &&
( V_24 -> V_20 -> V_32 . V_290 !=
V_291 || ! V_2 -> V_11 ) )
return - V_56 ;
switch ( V_94 -> V_94 ) {
case V_292 :
V_94 -> V_70 = V_2 -> V_13 ;
break;
case V_287 :
V_94 -> V_293 = F_77 ( V_2 ) ;
break;
case V_288 :
V_4 = F_76 ( V_20 , V_94 , V_94 -> V_184 . V_185 ) ;
break;
case V_289 :
while ( ( ! V_4 || V_4 == - V_283 ) && V_272 < V_94 -> V_293 ) {
V_4 = F_76 ( V_20 , V_94 , V_3 ) ;
if ( ! V_4 )
V_286 [ V_272 ++ ] = V_3 ;
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
static int F_79 ( struct V_19 * V_20 , struct V_177 * V_94 )
{
int V_4 = 0 ;
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
if ( V_24 -> V_20 -> V_32 . V_290 !=
V_291 || ! V_2 -> V_11 )
return - V_56 ;
switch ( V_94 -> V_94 ) {
case V_294 :
V_4 = F_68 ( V_20 , V_94 ) ;
break;
case V_295 :
V_4 = F_75 ( V_20 , V_94 ) ;
break;
default:
F_70 ( V_2 , L_22 , V_94 -> V_94 ) ;
return - V_56 ;
}
return V_4 ;
}
static void F_80 ( struct V_19 * V_20 ,
struct V_296 * V_297 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
memset ( V_297 , 0 , sizeof( * V_297 ) ) ;
V_297 -> V_298 = V_299 ;
V_297 -> V_300 = V_301 ;
V_297 -> V_302 = V_2 -> V_13 ;
V_297 -> V_303 = V_2 -> V_5 / V_304 ;
}
static int F_81 ( struct V_19 * V_20 ,
struct V_296 * V_297 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_11 = 0 ;
int V_4 = 0 ;
if ( V_297 -> V_305 || V_297 -> V_306 ||
V_297 -> V_303 > V_301 ||
V_297 -> V_302 > V_299 ||
! V_297 -> V_303 || ! V_297 -> V_302 )
return - V_56 ;
F_39 ( & V_24 -> V_162 ) ;
if ( V_2 -> V_11 ) {
V_11 = 1 ;
F_40 ( V_20 , 1 ) ;
}
F_41 ( V_2 ) ;
V_2 -> V_307 = V_297 -> V_303 ;
V_2 -> V_5 = V_297 -> V_303 * V_304 ;
V_2 -> V_13 = V_297 -> V_302 ;
V_4 = F_42 ( V_2 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_15 ) ;
goto V_165;
}
F_82 ( V_20 , V_2 -> V_5 ) ;
F_83 ( V_20 , V_2 -> V_13 ) ;
if ( V_20 -> V_308 )
F_84 ( V_20 , V_304 ) ;
F_70 ( V_2 , L_23 , V_2 -> V_5 ) ;
F_70 ( V_2 , L_24 , V_2 -> V_13 ) ;
if ( V_11 ) {
V_4 = F_43 ( V_20 ) ;
if ( V_4 )
F_10 ( V_2 , L_16 ) ;
}
V_4 = F_1 ( V_2 ) ;
V_165:
F_44 ( & V_24 -> V_162 ) ;
return V_4 ;
}
static int F_85 ( struct V_19 * V_20 ,
struct V_309 * V_310 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_311 ;
V_311 = F_86 ( V_20 , V_310 ) ;
if ( V_311 )
return V_311 ;
if ( V_24 -> V_20 -> V_32 . V_312 & V_313 ) {
V_310 -> V_314 |=
V_315 |
V_316 |
V_317 ;
V_310 -> V_318 =
( 1 << V_319 ) |
( 1 << V_320 ) ;
V_310 -> V_321 =
( 1 << V_322 ) |
( 1 << V_323 ) ;
if ( V_24 -> V_324 )
V_310 -> V_325 = F_87 ( V_24 -> V_324 ) ;
}
return V_311 ;
}
static int F_88 ( struct V_19 * V_20 , T_1 V_49 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
bool V_326 = ! ! ( V_49 & V_327 ) ;
bool V_328 = ! ! ( V_2 -> V_329 & V_327 ) ;
int V_3 ;
if ( V_326 == V_328 )
return 0 ;
if ( V_326 ) {
bool V_330 = true ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ )
V_330 &= V_2 -> V_79 [ V_3 ] -> V_331 ;
if ( ! V_330 ) {
F_10 ( V_2 , L_25 ) ;
return - V_56 ;
}
V_2 -> V_329 |= V_327 ;
} else {
V_2 -> V_329 &= ~ V_327 ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ )
V_2 -> V_79 [ V_3 ] -> V_332 = V_326 ;
F_89 ( V_2 , L_26 ,
V_326 ? L_27 : L_28 ) ;
return 0 ;
}
static T_1 F_90 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
return V_2 -> V_329 ;
}
