int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
unsigned V_5 = 0 , V_6 = 0 , V_7 = 0 ;
int V_8 ;
if ( V_2 -> V_9 == V_10 )
return F_2 ( V_2 , V_3 , V_4 ) ;
F_3 ( V_11 ,
F_4 ( 1 ) | F_5 ( 1 ) ,
~ ( V_12 | V_13 ) ) ;
if ( ! V_3 || ! V_4 ) {
F_3 ( V_14 , V_15 , ~ V_15 ) ;
return 0 ;
}
V_8 = F_6 ( V_2 , V_3 , V_4 , 50000 , 160000 ,
43663 , 0x03FFFFFE , 1 , 30 , ~ 0 ,
& V_5 , & V_6 , & V_7 ) ;
if ( V_8 )
return V_8 ;
V_5 |= 1 ;
V_6 -= 1 ;
V_7 -= 1 ;
F_3 ( V_16 , F_7 ( 0x50000 ) , ~ V_17 ) ;
F_3 ( V_14 , 0 , ~ ( V_18 | V_15 ) ) ;
F_3 ( V_14 , V_19 , ~ V_19 ) ;
F_3 ( V_16 , F_7 ( 1 ) , ~ F_7 ( 1 ) ) ;
V_8 = F_8 ( V_2 , V_14 ) ;
if ( V_8 )
return V_8 ;
F_3 ( V_14 , V_18 , ~ V_18 ) ;
F_3 ( V_14 , F_9 ( 1 ) , ~ V_20 ) ;
F_3 ( V_11 ,
F_10 ( V_6 >> 1 ) |
F_11 ( ( V_6 >> 1 ) + ( V_6 & 1 ) ) |
F_12 ( V_7 >> 1 ) |
F_13 ( ( V_7 >> 1 ) + ( V_7 & 1 ) ) ,
~ V_21 ) ;
F_3 ( V_16 , F_7 ( V_5 ) ,
~ V_17 ) ;
F_14 ( 15 ) ;
F_3 ( V_14 , 0 , ~ V_18 ) ;
F_14 ( 15 ) ;
F_3 ( V_14 , 0 , ~ V_19 ) ;
F_3 ( V_16 , 0 , ~ F_7 ( 1 ) ) ;
V_8 = F_8 ( V_2 , V_14 ) ;
if ( V_8 )
return V_8 ;
F_3 ( V_11 ,
F_4 ( 2 ) | F_5 ( 2 ) ,
~ ( V_12 | V_13 ) ) ;
F_14 ( 100 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_9 ) {
case V_22 :
F_16 ( V_2 ,
V_23 ,
( const T_1 ) F_17 ( V_23 ) ) ;
F_16 ( V_2 ,
V_24 ,
( const T_1 ) F_17 ( V_24 ) ) ;
if ( V_2 -> V_25 -> V_26 == 0x994e )
F_16 ( V_2 ,
V_27 ,
( const T_1 ) F_17 ( V_27 ) ) ;
else
F_16 ( V_2 ,
V_28 ,
( const T_1 ) F_17 ( V_28 ) ) ;
F_16 ( V_2 ,
V_29 ,
( const T_1 ) F_17 ( V_29 ) ) ;
break;
case V_30 :
F_16 ( V_2 ,
V_23 ,
( const T_1 ) F_17 ( V_23 ) ) ;
F_16 ( V_2 ,
V_24 ,
( const T_1 ) F_17 ( V_24 ) ) ;
F_16 ( V_2 ,
V_31 ,
( const T_1 ) F_17 ( V_31 ) ) ;
F_16 ( V_2 ,
V_32 ,
( const T_1 ) F_17 ( V_32 ) ) ;
break;
case V_33 :
F_16 ( V_2 ,
V_23 ,
( const T_1 ) F_17 ( V_23 ) ) ;
F_16 ( V_2 ,
V_24 ,
( const T_1 ) F_17 ( V_24 ) ) ;
F_16 ( V_2 ,
V_34 ,
( const T_1 ) F_17 ( V_34 ) ) ;
F_16 ( V_2 ,
V_35 ,
( const T_1 ) F_17 ( V_35 ) ) ;
break;
case V_10 :
F_16 ( V_2 ,
V_36 ,
( const T_1 ) F_17 ( V_36 ) ) ;
F_16 ( V_2 ,
V_37 ,
( const T_1 ) F_17 ( V_37 ) ) ;
break;
default:
break;
}
}
T_1 F_18 ( struct V_1 * V_2 )
{
T_1 V_38 = V_2 -> clock . V_39 . V_40 ;
T_1 V_41 = F_19 ( V_42 ) ;
if ( V_41 & V_43 )
return V_44 ;
if ( V_41 & V_45 )
return V_38 / 4 ;
return V_38 ;
}
T_1 F_20 ( struct V_1 * V_2 , int V_46 , T_2 V_47 )
{
struct V_48 * V_48 = V_2 -> V_49 . V_50 [ V_46 ] ;
T_1 V_41 = F_19 ( V_51 + V_48 -> V_52 ) ;
int V_53 ;
V_41 |= V_54 ;
F_21 ( V_51 + V_48 -> V_52 , V_41 ) ;
if ( V_48 -> V_46 ) {
F_21 ( V_55 , F_22 ( V_47 ) ) ;
F_21 ( V_56 , F_22 ( V_47 ) ) ;
} else {
F_21 ( V_57 , F_22 ( V_47 ) ) ;
F_21 ( V_58 , F_22 ( V_47 ) ) ;
}
F_21 ( V_59 + V_48 -> V_52 ,
( T_1 ) V_47 ) ;
F_21 ( V_60 + V_48 -> V_52 ,
( T_1 ) V_47 ) ;
for ( V_53 = 0 ; V_53 < V_2 -> V_61 ; V_53 ++ ) {
if ( F_19 ( V_51 + V_48 -> V_52 ) & V_62 )
break;
F_23 ( 1 ) ;
}
F_24 ( L_1 ) ;
V_41 &= ~ V_54 ;
F_21 ( V_51 + V_48 -> V_52 , V_41 ) ;
return F_19 ( V_51 + V_48 -> V_52 ) & V_62 ;
}
int F_25 ( struct V_1 * V_2 )
{
T_1 V_63 = ( F_19 ( V_64 ) & V_65 ) >>
V_66 ;
int V_67 ;
if ( V_63 & 0x400 )
V_67 = - 256 ;
else if ( V_63 & 0x200 )
V_67 = 255 ;
else if ( V_63 & 0x100 ) {
V_67 = V_63 & 0x1ff ;
V_67 |= ~ 0x1ff ;
} else
V_67 = V_63 & 0xff ;
return ( V_67 * 1000 ) / 2 ;
}
void F_26 ( struct V_1 * V_2 )
{
int V_68 = V_2 -> V_69 . V_70 ;
int V_71 = V_2 -> V_69 . V_72 ;
struct V_73 * V_74 = & V_2 -> V_69 . V_75 [ V_68 ] ;
struct V_76 * V_77 = & V_74 -> V_78 [ V_71 ] . V_77 ;
if ( ( V_77 -> type == V_79 ) && V_77 -> V_77 ) {
if ( V_77 -> V_77 == 0xff01 )
return;
if ( V_77 -> V_77 != V_2 -> V_69 . V_80 ) {
F_27 ( V_2 , V_77 -> V_77 , V_81 ) ;
V_2 -> V_69 . V_80 = V_77 -> V_77 ;
F_24 ( L_2 , V_77 -> V_77 ) ;
}
}
}
static int F_28 ( struct V_1 * V_2 )
{
T_1 V_41 ;
int V_8 , V_53 ;
if ( V_2 -> V_82 . V_83 == NULL ) {
F_29 ( V_2 -> V_84 , L_3 ) ;
return - V_85 ;
}
V_8 = F_30 ( V_2 ) ;
if ( V_8 )
return V_8 ;
F_31 ( V_2 ) ;
F_21 ( V_86 , V_87 | V_88 |
V_89 |
F_32 ( 7 ) ) ;
F_21 ( V_90 , 0 ) ;
F_21 ( V_91 , F_33 ( 0 ) | F_34 ( 2 ) ) ;
V_41 = V_92 | V_93 |
V_94 |
V_95 |
F_35 ( 5 ) | F_36 ( 5 ) ;
F_21 ( V_96 , V_41 ) ;
F_21 ( V_97 , V_41 ) ;
F_21 ( V_98 , V_41 ) ;
if ( V_2 -> V_9 == V_10 )
F_21 ( V_99 , V_41 ) ;
F_21 ( V_100 , V_41 ) ;
F_21 ( V_101 , V_41 ) ;
F_21 ( V_102 , V_41 ) ;
F_21 ( V_103 , V_41 ) ;
F_21 ( V_104 , V_2 -> V_105 . V_106 >> 12 ) ;
F_21 ( V_107 , V_2 -> V_105 . V_108 >> 12 ) ;
F_21 ( V_109 , V_2 -> V_82 . V_110 >> 12 ) ;
F_21 ( V_111 , V_112 | F_37 ( 0 ) |
V_113 ) ;
F_21 ( V_114 ,
( T_1 ) ( V_2 -> V_115 . V_116 >> 12 ) ) ;
for ( V_53 = 1 ; V_53 < 7 ; V_53 ++ )
F_21 ( V_111 + ( V_53 * 4 ) , 0 ) ;
F_38 ( V_2 ) ;
F_39 ( L_4 ,
( unsigned ) ( V_2 -> V_105 . V_117 >> 20 ) ,
( unsigned long long ) V_2 -> V_82 . V_110 ) ;
V_2 -> V_82 . V_118 = true ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 )
{
T_1 V_41 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < 7 ; V_53 ++ )
F_21 ( V_111 + ( V_53 * 4 ) , 0 ) ;
F_21 ( V_86 , V_88 |
F_32 ( 7 ) ) ;
F_21 ( V_90 , 0 ) ;
F_21 ( V_91 , F_33 ( 0 ) | F_34 ( 2 ) ) ;
V_41 = F_35 ( 5 ) | F_36 ( 5 ) ;
F_21 ( V_96 , V_41 ) ;
F_21 ( V_97 , V_41 ) ;
F_21 ( V_98 , V_41 ) ;
F_21 ( V_100 , V_41 ) ;
F_21 ( V_101 , V_41 ) ;
F_21 ( V_102 , V_41 ) ;
F_21 ( V_103 , V_41 ) ;
F_41 ( V_2 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_43 ( V_2 ) ;
F_40 ( V_2 ) ;
F_44 ( V_2 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
T_1 V_41 ;
int V_53 ;
F_21 ( V_86 , V_87 | V_88 |
V_89 |
F_32 ( 7 ) ) ;
F_21 ( V_90 , 0 ) ;
F_21 ( V_91 , F_33 ( 0 ) | F_34 ( 2 ) ) ;
V_41 = V_92 | V_93 |
V_94 |
V_95 |
F_35 ( 5 ) | F_36 ( 5 ) ;
F_21 ( V_96 , V_41 ) ;
F_21 ( V_97 , V_41 ) ;
F_21 ( V_98 , V_41 ) ;
F_21 ( V_100 , V_41 ) ;
F_21 ( V_101 , V_41 ) ;
F_21 ( V_102 , V_41 ) ;
F_21 ( V_103 , V_41 ) ;
for ( V_53 = 0 ; V_53 < 7 ; V_53 ++ )
F_21 ( V_111 + ( V_53 * 4 ) , 0 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_119 V_120 ;
T_1 V_41 ;
int V_53 , V_121 ;
for ( V_53 = 0 , V_121 = 0 ; V_53 < 32 ; V_53 ++ , V_121 += 0x18 ) {
F_21 ( ( 0x2c14 + V_121 ) , 0x00000000 ) ;
F_21 ( ( 0x2c18 + V_121 ) , 0x00000000 ) ;
F_21 ( ( 0x2c1c + V_121 ) , 0x00000000 ) ;
F_21 ( ( 0x2c20 + V_121 ) , 0x00000000 ) ;
F_21 ( ( 0x2c24 + V_121 ) , 0x00000000 ) ;
}
V_41 = F_19 ( V_122 ) ;
F_47 ( V_2 , & V_120 ) ;
if ( F_48 ( V_2 ) ) {
F_49 ( V_2 -> V_84 , L_5 ) ;
}
F_21 ( V_123 , V_124 ) ;
if ( V_2 -> V_125 & V_126 ) {
if ( V_2 -> V_105 . V_127 < V_2 -> V_105 . V_106 ) {
F_21 ( V_128 ,
V_2 -> V_105 . V_127 >> 12 ) ;
F_21 ( V_129 ,
V_2 -> V_105 . V_108 >> 12 ) ;
} else {
F_21 ( V_128 ,
V_2 -> V_105 . V_106 >> 12 ) ;
F_21 ( V_129 ,
V_2 -> V_105 . V_130 >> 12 ) ;
}
} else {
F_21 ( V_128 ,
V_2 -> V_105 . V_127 >> 12 ) ;
F_21 ( V_129 ,
V_2 -> V_105 . V_130 >> 12 ) ;
}
F_21 ( V_131 , V_2 -> V_132 . V_133 >> 12 ) ;
V_41 = ( ( V_2 -> V_105 . V_130 >> 24 ) & 0xFFFF ) << 16 ;
V_41 |= ( ( V_2 -> V_105 . V_127 >> 24 ) & 0xFFFF ) ;
F_21 ( V_134 , V_41 ) ;
F_21 ( V_135 , ( V_2 -> V_105 . V_127 >> 8 ) ) ;
F_21 ( V_136 , ( 2 << 7 ) ) ;
F_21 ( V_137 , 0x3FFFFFFF ) ;
if ( V_2 -> V_125 & V_126 ) {
F_21 ( V_138 , V_2 -> V_105 . V_108 >> 16 ) ;
F_21 ( V_139 , V_2 -> V_105 . V_106 >> 16 ) ;
F_21 ( V_140 , V_2 -> V_105 . V_141 >> 22 ) ;
} else {
F_21 ( V_140 , 0 ) ;
F_21 ( V_138 , 0x0FFFFFFF ) ;
F_21 ( V_139 , 0x0FFFFFFF ) ;
}
if ( F_48 ( V_2 ) ) {
F_49 ( V_2 -> V_84 , L_5 ) ;
}
F_50 ( V_2 , & V_120 ) ;
F_51 ( V_2 ) ;
}
void F_52 ( struct V_1 * V_2 )
{
F_53 ( V_2 , V_2 -> V_105 . V_142 ) ;
F_21 ( V_143 , ( V_144 | V_145 ) ) ;
F_21 ( V_146 , 0 ) ;
V_2 -> V_147 [ V_148 ] . V_118 = false ;
}
static int F_54 ( struct V_1 * V_2 )
{
const T_3 * V_149 ;
int V_53 ;
if ( ! V_2 -> V_150 || ! V_2 -> V_151 )
return - V_85 ;
F_52 ( V_2 ) ;
F_21 ( V_152 ,
#ifdef F_55
V_153 |
#endif
V_154 | F_56 ( 15 ) | F_57 ( 3 ) ) ;
F_21 ( V_155 , V_156 ) ;
F_19 ( V_155 ) ;
F_14 ( 15 ) ;
F_21 ( V_155 , 0 ) ;
V_149 = ( const T_3 * ) V_2 -> V_151 -> V_157 ;
F_21 ( V_158 , 0 ) ;
for ( V_53 = 0 ; V_53 < V_159 ; V_53 ++ )
F_21 ( V_160 , F_58 ( V_149 ++ ) ) ;
F_21 ( V_158 , 0 ) ;
V_149 = ( const T_3 * ) V_2 -> V_150 -> V_157 ;
F_21 ( V_161 , 0 ) ;
for ( V_53 = 0 ; V_53 < V_162 ; V_53 ++ )
F_21 ( V_163 , F_58 ( V_149 ++ ) ) ;
F_21 ( V_158 , 0 ) ;
F_21 ( V_161 , 0 ) ;
F_21 ( V_164 , 0 ) ;
return 0 ;
}
void F_59 ( struct V_1 * V_2 )
{
struct V_165 * V_147 = & V_2 -> V_147 [ V_148 ] ;
F_52 ( V_2 ) ;
F_60 ( V_2 , V_147 ) ;
F_61 ( V_2 , V_147 -> V_166 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
int V_53 , V_121 , V_167 ;
T_1 V_168 ;
T_1 V_169 ;
T_1 V_170 ;
T_1 V_171 ;
T_1 V_172 ;
T_1 V_173 ;
T_1 V_174 = 0 ;
T_1 V_175 ;
T_1 V_176 ;
T_1 V_177 ;
T_1 V_178 ;
T_1 V_179 ;
T_1 V_180 = 0 ;
T_1 V_181 = 0 ;
T_1 V_182 = 0 ;
T_1 V_183 ;
T_1 V_184 , V_41 ;
T_1 V_185 , V_186 ;
T_1 V_187 ;
unsigned V_188 ;
V_2 -> V_189 . V_190 . V_191 = 256 ;
switch ( V_2 -> V_9 ) {
case V_22 :
V_2 -> V_189 . V_190 . V_192 = 4 ;
V_2 -> V_189 . V_190 . V_193 = 8 ;
V_2 -> V_189 . V_190 . V_194 = 10 ;
V_2 -> V_189 . V_190 . V_195 = 4 ;
V_2 -> V_189 . V_190 . V_196 = 256 ;
V_2 -> V_189 . V_190 . V_197 = 248 ;
V_2 -> V_189 . V_190 . V_198 = 512 ;
V_2 -> V_189 . V_190 . V_199 = 8 ;
V_2 -> V_189 . V_190 . V_200 = 16 * 2 ;
V_2 -> V_189 . V_190 . V_201 = 128 ;
V_2 -> V_189 . V_190 . V_202 = 16 ;
V_2 -> V_189 . V_190 . V_203 = 112 ;
V_2 -> V_189 . V_190 . V_204 = 2 ;
V_2 -> V_189 . V_190 . V_205 = 7 ;
V_2 -> V_189 . V_190 . V_206 = 0xF9 ;
V_2 -> V_189 . V_190 . V_207 = 0x30 ;
V_2 -> V_189 . V_190 . V_208 = 0x130 ;
break;
case V_30 :
V_2 -> V_189 . V_190 . V_192 = 2 ;
V_2 -> V_189 . V_190 . V_193 = 4 ;
V_2 -> V_189 . V_190 . V_194 = 8 ;
V_2 -> V_189 . V_190 . V_195 = 2 ;
V_2 -> V_189 . V_190 . V_196 = 128 ;
V_2 -> V_189 . V_190 . V_197 = 248 ;
V_2 -> V_189 . V_190 . V_198 = 256 ;
V_2 -> V_189 . V_190 . V_199 = 8 ;
V_2 -> V_189 . V_190 . V_200 = 16 * 2 ;
V_2 -> V_189 . V_190 . V_201 = 256 ;
V_2 -> V_189 . V_190 . V_202 = 32 ;
V_2 -> V_189 . V_190 . V_203 = 224 ;
V_2 -> V_189 . V_190 . V_204 = 2 ;
V_2 -> V_189 . V_190 . V_205 = 7 ;
V_2 -> V_189 . V_190 . V_206 = 0xf9 ;
V_2 -> V_189 . V_190 . V_207 = 0x30 ;
V_2 -> V_189 . V_190 . V_208 = 0x130 ;
if ( V_2 -> V_189 . V_190 . V_202 > 16 ) {
V_2 -> V_189 . V_190 . V_202 -= 16 ;
V_2 -> V_189 . V_190 . V_203 += 16 ;
}
break;
case V_33 :
V_2 -> V_189 . V_190 . V_192 = 2 ;
V_2 -> V_189 . V_190 . V_193 = 2 ;
V_2 -> V_189 . V_190 . V_194 = 2 ;
V_2 -> V_189 . V_190 . V_195 = 1 ;
V_2 -> V_189 . V_190 . V_196 = 256 ;
V_2 -> V_189 . V_190 . V_197 = 192 ;
V_2 -> V_189 . V_190 . V_198 = 256 ;
V_2 -> V_189 . V_190 . V_199 = 4 ;
V_2 -> V_189 . V_190 . V_200 = 8 * 2 ;
V_2 -> V_189 . V_190 . V_201 = 128 ;
V_2 -> V_189 . V_190 . V_202 = 16 ;
V_2 -> V_189 . V_190 . V_203 = 112 ;
V_2 -> V_189 . V_190 . V_204 = 1 ;
V_2 -> V_189 . V_190 . V_205 = 7 ;
V_2 -> V_189 . V_190 . V_206 = 0x40 ;
V_2 -> V_189 . V_190 . V_207 = 0x30 ;
V_2 -> V_189 . V_190 . V_208 = 0x130 ;
break;
case V_10 :
V_2 -> V_189 . V_190 . V_192 = 4 ;
V_2 -> V_189 . V_190 . V_193 = 4 ;
V_2 -> V_189 . V_190 . V_194 = 8 ;
V_2 -> V_189 . V_190 . V_195 = 4 ;
V_2 -> V_189 . V_190 . V_196 = 256 ;
V_2 -> V_189 . V_190 . V_197 = 248 ;
V_2 -> V_189 . V_190 . V_198 = 512 ;
V_2 -> V_189 . V_190 . V_199 = 8 ;
V_2 -> V_189 . V_190 . V_200 = 16 * 2 ;
V_2 -> V_189 . V_190 . V_201 = 256 ;
V_2 -> V_189 . V_190 . V_202 = 32 ;
V_2 -> V_189 . V_190 . V_203 = 224 ;
V_2 -> V_189 . V_190 . V_204 = 2 ;
V_2 -> V_189 . V_190 . V_205 = 7 ;
V_2 -> V_189 . V_190 . V_206 = 0x100 ;
V_2 -> V_189 . V_190 . V_207 = 0x30 ;
V_2 -> V_189 . V_190 . V_208 = 0x130 ;
if ( V_2 -> V_189 . V_190 . V_202 > 16 ) {
V_2 -> V_189 . V_190 . V_202 -= 16 ;
V_2 -> V_189 . V_190 . V_203 += 16 ;
}
break;
default:
break;
}
V_121 = 0 ;
for ( V_53 = 0 ; V_53 < 32 ; V_53 ++ ) {
F_21 ( ( 0x2c14 + V_121 ) , 0x00000000 ) ;
F_21 ( ( 0x2c18 + V_121 ) , 0x00000000 ) ;
F_21 ( ( 0x2c1c + V_121 ) , 0x00000000 ) ;
F_21 ( ( 0x2c20 + V_121 ) , 0x00000000 ) ;
F_21 ( ( 0x2c24 + V_121 ) , 0x00000000 ) ;
V_121 += 0x18 ;
}
F_21 ( V_209 , F_63 ( 0xff ) ) ;
V_183 = F_19 ( V_210 ) ;
V_186 = F_19 ( V_211 ) ;
V_185 = ( V_186 & V_212 ) >> V_213 ;
for ( V_53 = 0 , V_41 = 1 , V_188 = 0 ; V_53 < V_214 ; V_53 ++ ) {
if ( ! ( V_185 & V_41 ) ) {
V_188 ++ ;
}
V_41 <<= 1 ;
}
if ( V_188 == 1 ) {
F_21 ( V_215 , V_216 ) ;
} else {
F_21 ( V_215 , 0 ) ;
}
V_181 = F_19 ( V_217 ) & 0x00ff0000 ;
V_41 = V_218 - F_64 ( V_181 >> 16 ) ;
if ( V_41 < V_2 -> V_189 . V_190 . V_195 ) {
V_2 -> V_189 . V_190 . V_195 = V_41 ;
}
V_182 = F_19 ( V_211 ) & 0xffffff00 ;
V_41 = V_214 - F_64 ( ( V_182 >> 8 ) & V_219 ) ;
if ( V_41 < V_2 -> V_189 . V_190 . V_192 ) {
V_2 -> V_189 . V_190 . V_192 = V_41 ;
}
V_41 = V_220 - F_64 ( ( V_182 >> 16 ) & V_221 ) ;
if ( V_41 < V_2 -> V_189 . V_190 . V_194 ) {
V_2 -> V_189 . V_190 . V_194 = V_41 ;
}
switch ( V_2 -> V_189 . V_190 . V_193 ) {
case 1 :
default:
V_180 = F_65 ( 0 ) ;
break;
case 2 :
V_180 = F_65 ( 1 ) ;
break;
case 4 :
V_180 = F_65 ( 2 ) ;
break;
case 8 :
V_180 = F_65 ( 3 ) ;
break;
}
V_2 -> V_189 . V_190 . V_222 = V_2 -> V_189 . V_190 . V_193 ;
V_187 = ( F_19 ( V_217 ) >> 16 ) & V_223 ;
V_41 = ( V_180 & V_224 ) >> V_225 ;
V_41 = F_66 ( V_2 , V_41 , V_2 -> V_189 . V_190 . V_195 ,
V_218 , V_187 ) ;
V_180 |= V_41 << 16 ;
V_2 -> V_189 . V_190 . V_226 = V_41 ;
if ( V_2 -> V_9 == V_22 )
V_180 |= F_67 ( 1 ) ;
else {
if ( ( V_183 & V_227 ) >> V_228 )
V_180 |= F_67 ( 1 ) ;
else
V_180 |= F_67 ( 0 ) ;
}
V_2 -> V_189 . V_190 . V_229 = 4 << ( ( V_180 >> 4 ) & 0x3 ) ;
V_180 |= F_68 ( ( V_183 & V_230 ) >> V_231 ) ;
if ( ( ( V_183 & V_232 ) >> V_233 ) > 3 ) {
V_180 |= F_69 ( 3 ) ;
V_180 |= F_70 ( 3 ) ;
} else {
V_180 |=
F_69 ( ( ( V_183 & V_232 ) >> V_233 ) ) ;
V_180 |=
F_70 ( ( ( V_183 & V_232 ) >> V_233 ) ) ;
}
V_180 |= F_71 ( 1 ) ;
V_2 -> V_189 . V_190 . V_234 = V_180 ;
F_21 ( V_235 , V_180 ) ;
F_21 ( V_236 , ( V_180 & 0xffff ) ) ;
F_21 ( V_237 , ( V_180 & 0xffff ) ) ;
F_21 ( V_238 , ( V_180 & 0xffff ) ) ;
F_21 ( V_239 , ( V_180 & 0xffff ) ) ;
if ( V_2 -> V_9 == V_30 ) {
F_21 ( V_240 , ( V_180 & 0xffff ) ) ;
F_21 ( V_241 , ( V_180 & 0xffff ) ) ;
F_21 ( V_242 , ( V_180 & 0xffff ) ) ;
}
F_21 ( V_243 , 0 ) ;
F_21 ( V_244 , 0 ) ;
F_21 ( V_245 , 0 ) ;
F_21 ( V_246 , 0 ) ;
V_167 = V_214 - F_64 ( ( V_182 & V_212 ) >> 8 ) ;
F_21 ( V_247 , ( V_167 * 4 ) & V_248 ) ;
F_21 ( V_249 , ( ( V_167 * 4 ) - 2 ) & V_250 ) ;
F_21 ( V_251 , ( F_72 ( 0x16 ) |
F_73 ( 0x2b ) ) ) ;
F_21 ( V_252 , F_74 ( 0x30 ) ) ;
V_168 = F_19 ( V_253 ) ;
F_21 ( V_253 , V_168 | V_254 ) ;
V_169 = F_19 ( V_255 ) ;
V_169 |= V_256 ;
F_21 ( V_255 , V_169 ) ;
V_170 = F_19 ( V_257 ) ;
V_170 &= ~ F_75 ( 0x1ff ) ;
V_170 |= F_75 ( ( V_2 -> V_189 . V_190 . V_205 * 64 ) - 1 ) ;
F_21 ( V_257 , V_170 ) ;
if ( V_2 -> V_9 != V_10 )
F_21 ( V_258 , ( F_76 ( 4 ) |
F_77 ( 4 ) |
F_78 ( 3 ) |
V_259 ) ) ;
if ( V_2 -> V_9 != V_22 )
F_21 ( V_260 , 0x00003f3f ) ;
V_171 = F_19 ( V_261 ) ;
V_171 &= ~ F_79 ( 0x1f ) ;
switch ( V_2 -> V_9 ) {
case V_22 :
case V_10 :
V_171 |= F_79 ( 0x1f ) ;
break;
case V_33 :
case V_30 :
default:
V_171 |= F_79 ( 2 ) ;
break;
}
F_21 ( V_261 , V_171 ) ;
if ( V_2 -> V_9 != V_22 ) {
V_184 = F_19 ( V_262 ) ;
V_184 |= V_263 ;
F_21 ( V_262 , V_184 ) ;
}
F_21 ( V_264 , ( F_80 ( ( V_2 -> V_189 . V_190 . V_201 / 4 ) - 1 ) |
F_81 ( ( V_2 -> V_189 . V_190 . V_202 / 4 ) - 1 ) |
F_82 ( ( V_2 -> V_189 . V_190 . V_203 / 4 ) - 1 ) ) ) ;
F_21 ( V_265 , ( F_83 ( V_2 -> V_189 . V_190 . V_206 ) |
F_84 ( V_2 -> V_189 . V_190 . V_207 ) |
F_85 ( V_2 -> V_189 . V_190 . V_208 ) ) ) ;
F_21 ( V_266 , 0 ) ;
F_21 ( V_267 , 1 ) ;
F_21 ( V_268 , F_86 ( 4 ) ) ;
F_21 ( V_269 , 0 ) ;
V_175 = ( F_87 ( 16 * V_2 -> V_189 . V_190 . V_204 ) |
F_88 ( 0xe0 ) |
F_89 ( 0x8 ) ) ;
switch ( V_2 -> V_9 ) {
case V_22 :
case V_30 :
case V_33 :
V_175 |= F_90 ( 0x1 ) ;
break;
case V_10 :
default:
V_175 |= F_90 ( 0x4 ) ;
break;
}
F_21 ( V_270 , V_175 ) ;
V_176 = F_19 ( V_271 ) ;
V_176 &= ~ ( F_91 ( 3 ) |
F_92 ( 3 ) |
F_93 ( 3 ) |
F_94 ( 3 ) ) ;
V_176 |= ( V_272 |
V_273 |
V_274 |
F_91 ( 0 ) |
F_92 ( 1 ) |
F_93 ( 2 ) |
F_94 ( 3 ) ) ;
if ( V_2 -> V_9 == V_33 )
V_176 &= ~ V_273 ;
F_21 ( V_271 , V_176 ) ;
F_21 ( V_275 , ( F_95 ( ( V_2 -> V_189 . V_190 . V_196 * 24 ) / 64 ) |
F_96 ( ( V_2 -> V_189 . V_190 . V_196 * 24 ) / 64 ) |
F_97 ( ( ( V_2 -> V_189 . V_190 . V_196 * 24 ) / 64 ) / 2 ) ) ) ;
F_21 ( V_276 , ( F_98 ( ( V_2 -> V_189 . V_190 . V_196 * 7 ) / 64 ) |
F_99 ( ( V_2 -> V_189 . V_190 . V_196 * 7 ) / 64 ) ) ) ;
V_177 = ( F_100 ( ( V_2 -> V_189 . V_190 . V_197 * 4 ) / 8 ) |
F_101 ( ( V_2 -> V_189 . V_190 . V_197 * 2 ) / 8 ) |
F_102 ( ( V_2 -> V_189 . V_190 . V_197 * 1 ) / 8 ) ) ;
if ( ( ( V_2 -> V_189 . V_190 . V_197 * 1 ) / 8 ) > V_2 -> V_189 . V_190 . V_200 )
V_177 |= F_103 ( V_2 -> V_189 . V_190 . V_200 ) ;
else
V_177 |= F_103 ( ( V_2 -> V_189 . V_190 . V_200 * 1 ) / 8 ) ;
F_21 ( V_277 , V_177 ) ;
F_21 ( V_278 , ( F_104 ( ( V_2 -> V_189 . V_190 . V_198 * 1 ) / 4 ) |
F_105 ( ( V_2 -> V_189 . V_190 . V_198 * 1 ) / 4 ) ) ) ;
F_21 ( V_279 , ( F_106 ( ( V_2 -> V_189 . V_190 . V_198 * 1 ) / 4 ) |
F_107 ( ( V_2 -> V_189 . V_190 . V_198 * 1 ) / 4 ) ) ) ;
V_179 = ( F_108 ( ( V_2 -> V_189 . V_190 . V_196 * 38 ) / 64 ) |
F_109 ( ( V_2 -> V_189 . V_190 . V_196 * 38 ) / 64 ) |
F_110 ( ( V_2 -> V_189 . V_190 . V_196 * 38 ) / 64 ) |
F_111 ( ( V_2 -> V_189 . V_190 . V_196 * 38 ) / 64 ) ) ;
F_21 ( V_280 , V_179 ) ;
F_21 ( V_281 , V_179 ) ;
F_21 ( V_282 , V_179 ) ;
F_21 ( V_283 , V_179 ) ;
F_21 ( V_284 , V_179 ) ;
F_21 ( V_285 , V_179 ) ;
F_21 ( V_286 , V_179 ) ;
F_21 ( V_287 , V_179 ) ;
F_21 ( V_288 , ( F_112 ( 4095 ) |
F_113 ( 255 ) ) ) ;
if ( V_2 -> V_9 == V_33 )
F_21 ( V_289 , ( F_114 ( V_290 ) |
F_115 ( V_291 ) ) ) ;
else
F_21 ( V_289 , ( F_114 ( V_292 ) |
F_115 ( V_291 ) ) ) ;
switch ( V_2 -> V_9 ) {
case V_22 :
case V_30 :
case V_10 :
V_174 = 384 ;
break;
case V_33 :
V_174 = 128 ;
break;
default:
break;
}
V_172 = V_2 -> V_189 . V_190 . V_192 * 16 ;
V_173 = V_174 + V_172 ;
if ( V_173 > 256 )
V_173 = 256 ;
F_21 ( V_293 , 128 ) ;
F_21 ( V_294 , V_173 ) ;
F_21 ( V_295 , 2 ) ;
F_21 ( V_296 , 16 ) ;
F_21 ( V_297 , 0 ) ;
F_21 ( V_298 , 0 ) ;
F_21 ( V_299 , 0 ) ;
F_21 ( V_300 , 0 ) ;
F_21 ( V_301 , 0xaaaaaaaa ) ;
F_21 ( V_302 , 0 ) ;
F_21 ( V_303 , 0xffff ) ;
F_21 ( V_304 , 0 ) ;
F_21 ( V_305 , 0 ) ;
F_21 ( V_306 , F_116 ( 2 ) ) ;
F_21 ( V_307 , 0 ) ;
F_21 ( V_308 , 0 ) ;
F_21 ( V_309 , 0 ) ;
F_21 ( V_310 , 0 ) ;
F_21 ( V_311 , 0 ) ;
F_21 ( V_312 , 0 ) ;
F_21 ( V_313 , 0 ) ;
F_21 ( V_314 , 0 ) ;
F_21 ( V_315 , 0 ) ;
F_21 ( V_316 , 0 ) ;
V_178 = F_19 ( V_317 ) ;
F_21 ( V_317 , V_178 ) ;
F_21 ( V_266 , 0 ) ;
F_21 ( V_318 , ( V_319 |
F_117 ( 3 ) ) ) ;
F_21 ( V_320 , 0 ) ;
}
void F_118 ( struct V_1 * V_2 , struct V_321 * V_105 )
{
T_2 V_322 , V_323 ;
if ( V_105 -> V_324 > 0xE0000000 ) {
F_49 ( V_2 -> V_84 , L_6 ) ;
V_105 -> V_325 = 0xE0000000 ;
V_105 -> V_324 = 0xE0000000 ;
}
if ( V_2 -> V_125 & V_126 ) {
V_322 = V_105 -> V_106 ;
V_323 = V_105 -> V_326 - V_105 -> V_108 ;
if ( V_322 > V_323 ) {
if ( V_105 -> V_324 > V_322 ) {
F_49 ( V_2 -> V_84 , L_6 ) ;
V_105 -> V_325 = V_322 ;
V_105 -> V_324 = V_322 ;
}
V_105 -> V_127 = V_105 -> V_106 - V_105 -> V_324 ;
} else {
if ( V_105 -> V_324 > V_323 ) {
F_49 ( V_2 -> V_84 , L_6 ) ;
V_105 -> V_325 = V_323 ;
V_105 -> V_324 = V_323 ;
}
V_105 -> V_127 = V_105 -> V_108 + 1 ;
}
V_105 -> V_130 = V_105 -> V_127 + V_105 -> V_324 - 1 ;
F_119 ( V_2 -> V_84 , L_7 ,
V_105 -> V_324 >> 20 , V_105 -> V_127 ,
V_105 -> V_130 , V_105 -> V_325 >> 20 ) ;
} else {
F_120 ( V_2 , & V_2 -> V_105 , 0 ) ;
V_2 -> V_105 . V_327 = 0 ;
F_121 ( V_2 , V_105 ) ;
}
}
static int F_122 ( struct V_1 * V_2 )
{
T_1 V_41 ;
int V_328 , V_329 ;
V_2 -> V_105 . V_330 = true ;
V_41 = F_19 ( V_210 ) ;
if ( V_41 & V_331 ) {
V_328 = 16 ;
} else if ( V_41 & V_332 ) {
V_328 = 64 ;
} else {
V_328 = 32 ;
}
V_41 = F_19 ( V_333 ) ;
switch ( ( V_41 & V_334 ) >> V_335 ) {
case 0 :
default:
V_329 = 1 ;
break;
case 1 :
V_329 = 2 ;
break;
case 2 :
V_329 = 4 ;
break;
case 3 :
V_329 = 8 ;
break;
}
V_2 -> V_105 . V_336 = V_329 * V_328 ;
V_2 -> V_105 . V_337 = F_123 ( V_2 -> V_25 , 0 ) ;
V_2 -> V_105 . V_338 = F_124 ( V_2 -> V_25 , 0 ) ;
V_2 -> V_105 . V_324 = F_19 ( V_339 ) ;
V_2 -> V_105 . V_325 = F_19 ( V_339 ) ;
V_2 -> V_105 . V_142 = V_2 -> V_105 . V_338 ;
F_118 ( V_2 , & V_2 -> V_105 ) ;
F_125 ( V_2 ) ;
return 0 ;
}
static int F_126 ( struct V_1 * V_2 )
{
struct V_165 * V_147 ;
int V_8 ;
F_127 ( V_2 ) ;
V_8 = F_128 ( V_2 ) ;
if ( V_8 )
return V_8 ;
F_46 ( V_2 ) ;
if ( ! V_2 -> V_150 || ! V_2 -> V_151 || ! V_2 -> V_340 ) {
V_8 = F_129 ( V_2 ) ;
if ( V_8 ) {
F_130 ( L_8 ) ;
return V_8 ;
}
}
if ( V_2 -> V_125 & V_126 ) {
F_45 ( V_2 ) ;
} else {
V_8 = F_28 ( V_2 ) ;
if ( V_8 )
return V_8 ;
}
F_62 ( V_2 ) ;
V_8 = F_131 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_132 ( V_2 , V_148 ) ;
if ( V_8 ) {
F_29 ( V_2 -> V_84 , L_9 , V_8 ) ;
return V_8 ;
}
V_8 = F_132 ( V_2 , V_341 ) ;
if ( V_8 ) {
F_29 ( V_2 -> V_84 , L_10 , V_8 ) ;
return V_8 ;
}
V_8 = F_133 ( V_2 ) ;
if ( ! V_8 ) {
V_8 = F_132 ( V_2 ,
V_342 ) ;
if ( V_8 )
F_29 ( V_2 -> V_84 , L_11 , V_8 ) ;
}
if ( V_8 )
V_2 -> V_147 [ V_342 ] . V_343 = 0 ;
if ( ! V_2 -> V_344 . V_345 ) {
V_8 = F_134 ( V_2 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_135 ( V_2 ) ;
if ( V_8 ) {
F_130 ( L_12 , V_8 ) ;
F_136 ( V_2 ) ;
return V_8 ;
}
F_137 ( V_2 ) ;
V_147 = & V_2 -> V_147 [ V_148 ] ;
V_8 = F_138 ( V_2 , V_147 , V_147 -> V_343 , V_346 ,
V_347 , V_348 ,
V_349 ) ;
if ( V_8 )
return V_8 ;
V_147 = & V_2 -> V_147 [ V_341 ] ;
V_8 = F_138 ( V_2 , V_147 , V_147 -> V_343 , V_350 ,
V_351 , V_352 ,
F_139 ( V_353 , 0 , 0 , 0 ) ) ;
if ( V_8 )
return V_8 ;
V_8 = F_54 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_140 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_141 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_147 = & V_2 -> V_147 [ V_342 ] ;
if ( V_147 -> V_343 ) {
V_8 = F_138 ( V_2 , V_147 , V_147 -> V_343 , 0 ,
V_354 , V_355 ,
V_349 ) ;
if ( ! V_8 )
V_8 = F_142 ( V_2 ) ;
if ( V_8 )
F_130 ( L_13 , V_8 ) ;
}
V_8 = F_143 ( V_2 ) ;
if ( V_8 ) {
F_29 ( V_2 -> V_84 , L_14 , V_8 ) ;
return V_8 ;
}
V_8 = F_144 ( V_2 ) ;
if ( V_8 ) {
F_130 ( L_15 ) ;
return V_8 ;
}
return 0 ;
}
int F_145 ( struct V_1 * V_2 )
{
int V_8 ;
F_146 ( V_2 -> V_49 . V_356 ) ;
F_15 ( V_2 ) ;
V_2 -> V_357 = true ;
V_8 = F_126 ( V_2 ) ;
if ( V_8 ) {
F_130 ( L_16 ) ;
V_2 -> V_357 = false ;
return V_8 ;
}
return V_8 ;
}
int F_147 ( struct V_1 * V_2 )
{
F_148 ( V_2 ) ;
F_149 ( V_2 ) ;
F_150 ( V_2 ) ;
F_52 ( V_2 ) ;
F_151 ( V_2 ) ;
F_152 ( V_2 ) ;
F_153 ( V_2 ) ;
F_40 ( V_2 ) ;
return 0 ;
}
int F_154 ( struct V_1 * V_2 )
{
int V_8 ;
if ( ! F_155 ( V_2 ) ) {
if ( F_156 ( V_2 ) )
return - V_85 ;
}
if ( ! V_2 -> V_358 ) {
F_29 ( V_2 -> V_84 , L_17 ) ;
return - V_85 ;
}
V_8 = F_157 ( V_2 ) ;
if ( V_8 )
return V_8 ;
if ( ! F_158 ( V_2 ) ) {
if ( ! V_2 -> V_359 ) {
F_29 ( V_2 -> V_84 , L_18 ) ;
return - V_85 ;
}
F_39 ( L_19 ) ;
F_146 ( V_2 -> V_49 . V_356 ) ;
}
F_15 ( V_2 ) ;
F_159 ( V_2 ) ;
F_160 ( V_2 ) ;
F_161 ( V_2 -> V_360 ) ;
V_8 = F_162 ( V_2 ) ;
if ( V_8 )
return V_8 ;
if ( V_2 -> V_125 & V_126 ) {
V_8 = F_163 ( V_2 ) ;
if ( V_8 )
F_164 ( V_2 ) ;
}
V_8 = F_122 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_165 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_2 -> V_147 [ V_148 ] . V_361 = NULL ;
F_166 ( V_2 , & V_2 -> V_147 [ V_148 ] , 1024 * 1024 ) ;
V_2 -> V_147 [ V_341 ] . V_361 = NULL ;
F_166 ( V_2 , & V_2 -> V_147 [ V_341 ] , 64 * 1024 ) ;
V_8 = F_167 ( V_2 ) ;
if ( ! V_8 ) {
V_2 -> V_147 [ V_342 ] . V_361 = NULL ;
F_166 ( V_2 , & V_2 -> V_147 [ V_342 ] ,
4096 ) ;
}
V_2 -> V_362 . V_361 = NULL ;
F_168 ( V_2 , 64 * 1024 ) ;
V_8 = F_169 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_2 -> V_357 = true ;
V_8 = F_126 ( V_2 ) ;
if ( V_8 ) {
F_29 ( V_2 -> V_84 , L_20 ) ;
F_59 ( V_2 ) ;
F_170 ( V_2 ) ;
F_171 ( V_2 ) ;
F_172 ( V_2 ) ;
F_173 ( V_2 ) ;
F_136 ( V_2 ) ;
F_42 ( V_2 ) ;
V_2 -> V_357 = false ;
}
return 0 ;
}
void F_174 ( struct V_1 * V_2 )
{
F_59 ( V_2 ) ;
F_170 ( V_2 ) ;
F_171 ( V_2 ) ;
F_172 ( V_2 ) ;
F_173 ( V_2 ) ;
F_136 ( V_2 ) ;
F_42 ( V_2 ) ;
F_149 ( V_2 ) ;
F_175 ( V_2 ) ;
F_176 ( V_2 ) ;
F_177 ( V_2 ) ;
F_178 ( V_2 ) ;
F_179 ( V_2 ) ;
F_180 ( V_2 ) ;
F_181 ( V_2 ) ;
F_182 ( V_2 -> V_359 ) ;
V_2 -> V_359 = NULL ;
}
static void F_127 ( struct V_1 * V_2 )
{
T_1 V_363 , V_364 , V_365 , V_41 ;
T_4 V_366 ;
if ( V_367 == 0 )
return;
if ( V_2 -> V_125 & V_368 )
return;
if ( ! ( V_2 -> V_125 & V_369 ) )
return;
if ( F_183 ( V_2 ) )
return;
if ( ( V_2 -> V_25 -> V_370 -> V_371 != V_372 ) &&
( V_2 -> V_25 -> V_370 -> V_371 != V_373 ) )
return;
F_39 ( L_21 ) ;
V_363 = F_184 ( V_374 ) ;
V_363 &= ~ V_375 ;
F_185 ( V_374 , V_363 ) ;
V_363 = F_184 ( V_374 ) ;
if ( V_363 & V_376 ) {
V_364 = ( V_363 & V_377 ) >> V_378 ;
V_363 &= ~ ( V_379 |
V_380 ) ;
V_363 |= V_364 | V_381 |
V_382 | V_383 ;
F_185 ( V_374 , V_363 ) ;
} else {
V_363 |= V_375 ;
F_185 ( V_374 , V_363 ) ;
}
V_365 = F_184 ( V_384 ) ;
if ( ( V_365 & V_385 ) &&
( V_365 & V_386 ) ) {
V_41 = F_19 ( 0x541c ) ;
F_21 ( 0x541c , V_41 | 0x8 ) ;
F_21 ( V_387 , V_388 ) ;
V_366 = F_186 ( 0x4088 ) ;
V_366 &= ~ V_389 ;
V_366 |= 0x2 ;
F_187 ( 0x4088 , V_366 ) ;
F_21 ( V_387 , 0 ) ;
V_365 = F_184 ( V_384 ) ;
V_365 &= ~ V_390 ;
F_185 ( V_384 , V_365 ) ;
V_365 = F_184 ( V_384 ) ;
V_365 |= V_391 ;
F_185 ( V_384 , V_365 ) ;
V_365 = F_184 ( V_384 ) ;
V_365 &= ~ V_391 ;
F_185 ( V_384 , V_365 ) ;
V_365 = F_184 ( V_384 ) ;
V_365 |= V_392 ;
F_185 ( V_384 , V_365 ) ;
} else {
V_363 = F_184 ( V_374 ) ;
if ( 1 )
V_363 |= V_375 ;
else
V_363 &= ~ V_375 ;
F_185 ( V_374 , V_363 ) ;
}
}
