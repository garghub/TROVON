static inline void F_1 ( T_1 * V_1 , unsigned int V_2 , unsigned int V_3 )
{
F_2 ( V_2 , V_1 -> V_4 + V_5 ) ;
F_2 ( V_3 , V_1 -> V_4 + V_6 ) ;
}
static inline int F_3 ( T_1 * V_1 , unsigned int V_2 )
{
if( V_2 == V_7 )
return F_4 ( V_1 -> V_4 + V_5 ) & 255 ;
F_2 ( V_2 , V_1 -> V_4 + V_5 ) ;
return F_4 ( V_1 -> V_4 + V_6 ) & 255 ;
}
static inline unsigned int F_5 ( T_1 * V_1 )
{
return F_6 ( V_1 , V_8 ) << 16 |
F_6 ( V_1 , V_9 ) << 8 |
F_6 ( V_1 , V_10 ) ;
}
static
void F_7 ( T_1 * V_1 , char * V_11 )
{
unsigned int V_12 , V_13 , V_14 ;
V_12 = F_6 ( V_1 , V_15 ) ;
V_13 = F_5 ( V_1 ) ;
V_14 = F_6 ( V_1 , V_16 ) << 8 |
F_6 ( V_1 , V_17 ) ;
F_8 ( L_1 ,
V_1 -> V_1 -> V_18 , V_11 ,
V_12 , V_13 , ( V_14 + 1 ) & 0xffff ,
F_6 ( V_1 , V_19 ) ) ;
F_8 ( L_2 , V_1 -> V_20 . V_21 ) ;
F_8 ( L_3 , V_1 -> V_22 . V_23 . V_24 ,
V_1 -> V_22 . V_23 . V_25 ) ;
F_8 ( L_4 , V_1 -> V_20 . V_26 ,
V_1 -> V_22 . V_23 . V_27 ) ;
F_8 ( L_5 ) ;
}
static
unsigned long F_9 ( T_1 * V_1 )
{
unsigned long V_28 ;
V_28 = F_3 ( V_1 , V_29 ) << 16 ;
V_28 |= F_10 ( V_1 ) << 8 ;
V_28 |= F_10 ( V_1 ) ;
return V_28 ;
}
static int
F_11 ( T_1 * V_1 , int V_30 , int V_31 , int V_32 , char * V_33 )
{
int V_34 ;
do {
V_34 = F_3 ( V_1 , V_7 ) ;
if ( ( V_34 & V_30 ) == V_31 )
return 0 ;
F_12 ( 1 ) ;
} while ( -- V_32 );
F_8 ( L_6 , V_1 -> V_1 -> V_18 , V_33 ) ;
return - 1 ;
}
static
int F_13 ( T_1 * V_1 , int V_35 )
{
if ( F_11 ( V_1 , V_36 , 0 , 1000 , L_7 ) )
return - 1 ;
F_1 ( V_1 , V_37 , V_35 ) ;
return 0 ;
}
static void
F_14 ( unsigned int V_38 )
{
unsigned long V_39 , V_40 ;
V_39 = V_41 + 1 + V_38 * V_42 / 100 ;
F_15 ( V_40 ) ;
F_16 () ;
while ( F_17 ( V_41 , V_39 ) ) F_18 () ;
F_19 ( V_40 ) ;
}
static
void F_20 ( T_1 * V_1 )
{
unsigned int V_43 , V_32 ;
V_1 -> V_44 . V_45 = 0x80 ;
F_2 ( V_1 -> V_44 . V_45 , V_1 -> V_46 + V_47 ) ;
F_14 ( 3 ) ;
V_1 -> V_44 . V_45 = 0 ;
F_2 ( V_1 -> V_44 . V_45 , V_1 -> V_46 + V_47 ) ;
V_32 = 1000 ;
do {
if ( F_21 ( V_1 -> V_46 + V_48 ) & 8 )
break;
F_12 ( 1 ) ;
} while ( -- V_32 );
if ( V_32 == 0 )
F_8 ( L_8 ,
V_1 -> V_1 -> V_18 ) ;
F_3 ( V_1 , V_7 ) ;
F_3 ( V_1 , V_49 ) ;
F_1 ( V_1 , V_50 , V_51 | V_1 -> V_1 -> V_52 ) ;
F_1 ( V_1 , V_37 , V_53 ) ;
V_32 = 1000 ;
do {
if ( F_21 ( V_1 -> V_46 + V_48 ) & 8 )
break;
F_12 ( 1 ) ;
} while ( -- V_32 );
if ( V_32 == 0 )
F_8 ( L_8 ,
V_1 -> V_1 -> V_18 ) ;
F_3 ( V_1 , V_7 ) ;
if ( F_3 ( V_1 , V_49 ) != 0x01 )
F_8 ( V_54 L_9 ,
V_1 -> V_1 -> V_18 ) ;
F_1 ( V_1 , V_55 , V_56 | V_57 ) ;
F_1 ( V_1 , V_58 , V_59 ) ;
F_1 ( V_1 , V_60 , V_61 ) ;
F_1 ( V_1 , V_62 , V_63 | V_64 ) ;
V_1 -> V_44 . V_45 = 0x40 ;
F_2 ( V_1 -> V_44 . V_45 , V_1 -> V_46 + V_47 ) ;
F_22 ( V_1 , V_65 , 0 ) ;
#ifdef F_23
F_22 ( V_1 , V_65 , V_66 ) ;
F_22 ( V_1 , V_67 , V_68 ) ;
F_22 ( V_1 , V_69 , V_70 ) ;
F_22 ( V_1 , V_71 , V_72 ) ;
#endif
V_1 -> V_73 = NULL ;
V_1 -> V_22 . V_74 = V_75 ;
V_1 -> V_22 . V_76 = 0 ;
memset ( V_1 -> V_77 , 0 , sizeof( V_1 -> V_77 ) ) ;
for ( V_43 = 0 ; V_43 < 8 ; V_43 ++ ) {
V_1 -> V_78 [ V_43 ] . V_79 = V_80 ;
V_1 -> V_78 [ V_43 ] . V_81 = 1 ;
}
F_14 ( 25 ) ;
}
static
void F_24 ( unsigned int V_82 )
{
if ( V_83 [ V_82 ] != - 1 )
F_8 ( L_10 ,
V_84 [ ( V_82 >> 4 ) ] ,
V_85 [ V_83 [ V_82 ] ] ) ;
else
F_8 ( L_11 , V_82 >> 4 , V_82 & 0x0f ) ;
}
static
void F_25 ( int V_34 , int V_82 , int V_86 )
{
#ifdef F_26
F_8 ( L_12 ,
V_34 & V_87 ? 'I' : 'i' ,
V_34 & V_88 ? 'L' : 'l' ,
V_34 & V_89 ? 'B' : 'b' ,
V_34 & V_36 ? 'C' : 'c' ,
V_34 & V_90 ? 'P' : 'p' ,
V_34 & V_91 ? 'D' : 'd' ) ;
F_8 ( L_13 ) ;
F_24 ( V_82 ) ;
F_8 ( L_14 , V_86 ) ;
#else
F_8 ( L_15 ,
V_34 , ( V_82 & 0xf0 ) >> 4 , V_82 & 0x0f , V_86 ) ;
#endif
}
static void
F_27 ( T_1 * V_1 , int V_92 , int line )
{
unsigned long V_93 ;
signed int V_24 ;
V_24 = V_1 -> V_94 [ V_92 ] - V_95 ;
if ( V_24 < 0 )
V_24 += V_96 ;
F_8 ( L_16 , V_92 == 8 ? 'H' : '0' + V_92 ,
line == 0 ? L_17 : line == 1 ? L_18 : L_19 ) ;
V_93 = V_1 -> V_97 [ V_92 ] [ V_24 ] . V_98 ;
for (; V_24 != V_1 -> V_94 [ V_92 ] ; V_24 = ( V_24 + 1 ) & ( V_96 - 1 ) ) {
unsigned long V_99 ;
if ( ! V_1 -> V_97 [ V_92 ] [ V_24 ] . V_98 )
continue;
switch ( line ) {
case 0 :
F_8 ( L_20 , V_1 -> V_97 [ V_92 ] [ V_24 ] . V_100 ? '-' : ' ' ,
V_1 -> V_97 [ V_92 ] [ V_24 ] . V_101 ) ;
break;
case 1 :
F_8 ( L_21 , V_1 -> V_97 [ V_92 ] [ V_24 ] . V_82 ) ;
break;
case 2 :
V_99 = V_1 -> V_97 [ V_92 ] [ V_24 ] . V_98 - V_93 ;
V_93 = V_1 -> V_97 [ V_92 ] [ V_24 ] . V_98 ;
if ( V_99 == 0 )
F_8 ( L_22 ) ;
else if ( V_99 >= 100 )
F_8 ( L_23 ) ;
else
F_8 ( L_24 , V_99 ) ;
break;
}
}
F_8 ( L_5 ) ;
}
static
void F_28 ( T_1 * V_1 , int V_92 )
{
do {
F_27 ( V_1 , V_92 , 0 ) ;
F_27 ( V_1 , V_92 , 1 ) ;
F_27 ( V_1 , V_92 , 2 ) ;
if ( V_92 == 8 )
break;
V_92 = 8 ;
} while ( 1 );
}
static
char F_29 ( T_1 * V_1 )
{
if ( V_1 -> V_73 )
return '0' + V_1 -> V_73 -> V_78 -> V_102 ;
return 'H' ;
}
static inline
T_2 F_30 ( int V_35 )
{
switch ( V_35 ) {
case V_103 : case V_104 : case V_105 :
return V_106 ;
case V_107 : case V_108 : case V_109 :
return V_110 ;
default:
return V_111 ;
}
}
static
T_3 F_31 ( int V_35 )
{
switch ( V_35 ) {
case V_112 : case V_113 : case V_114 :
case V_115 : case V_116 : case V_117 :
case V_118 : case V_119 : case V_120 :
case V_121 : case V_122 : case V_123 :
case V_124 : case V_125 : case V_126 :
case V_103 : case V_104 : case V_127 :
case V_128 : case V_129 : case V_130 :
case V_131 : case V_132 : case V_133 :
case V_105 : case V_134 : case V_135 :
case V_136 : case V_137 : case 0xea :
return V_138 ;
default:
return V_139 ;
}
}
static
int F_32 ( unsigned char V_140 )
{
int V_43 ;
V_140 &= 0xf0 ;
if ( V_140 == 0x10 )
V_140 = 0 ;
for ( V_43 = 1 ; V_141 [ V_43 ] . V_142 ; V_43 ++ )
if ( V_140 == V_141 [ V_43 ] . V_143 )
return V_141 [ V_43 ] . V_142 ;
return 0 ;
}
static inline
int F_33 ( unsigned int V_144 )
{
int V_43 ;
for ( V_43 = 1 ; V_141 [ V_43 ] . V_142 ; V_43 ++ ) {
if ( ( V_144 <= V_141 [ V_43 ] . V_142 ) &&
( V_144 > V_141 [ V_43 - 1 ] . V_142 ) )
return V_43 ;
}
return 7 ;
}
static
unsigned char F_34 ( unsigned int V_144 , unsigned int V_145 )
{
return V_141 [ F_33 ( V_144 ) ] . V_143 |
( ( V_145 < V_146 ) ? V_145 : V_146 ) ;
}
static
T_4 F_35 ( T_1 * V_1 )
{
int V_147 = 0 ;
struct V_148 * V_73 ;
V_73 = V_1 -> V_149 ;
V_1 -> V_149 = NULL ;
if ( ! V_73 ) {
V_73 = F_36 ( & V_1 -> V_150 . V_151 , V_1 -> V_77 ) ;
if ( ! V_73 )
return V_152 ;
V_147 = 1 ;
}
if ( V_1 -> V_22 . V_76 && V_1 -> V_73 ) {
F_37 ( & V_1 -> V_150 . V_153 , V_1 -> V_73 ) ;
V_1 -> V_22 . V_76 = 0 ;
#if ( V_154 & ( V_155 | V_156 ) )
F_38 ( V_1 -> V_73 , F_8 ( L_25 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ) ) ;
#endif
V_1 -> V_73 = NULL ;
}
if ( ! ( F_3 ( V_1 , V_7 ) & ( V_87 | V_89 | V_36 ) ) ) {
F_1 ( V_1 , V_157 , V_73 -> V_78 -> V_102 ) ;
F_1 ( V_1 , V_37 , V_158 ) ;
}
V_1 -> V_22 . V_74 = V_159 ;
V_1 -> V_73 = V_73 ;
V_1 -> V_22 . V_23 = V_73 -> V_23 ;
V_1 -> V_20 . V_160 = 0 ;
V_1 -> V_20 . V_161 = 0 ;
V_1 -> V_20 . V_162 = 0 ;
#if ( V_154 & ( V_163 | V_164 ) )
F_38 ( V_73 , F_8 ( L_26 ,
V_1 -> V_1 -> V_18 , '0' + V_73 -> V_78 -> V_102 ,
V_73 -> V_165 [ 0 ] ) ) ;
#endif
if ( V_147 ) {
#ifdef F_39
if ( V_73 -> V_78 -> V_166 ) {
V_73 -> V_78 -> V_167 += 1 ;
if ( V_73 -> V_78 -> V_167 == 0 )
V_73 -> V_78 -> V_167 = 1 ;
V_73 -> V_168 = V_73 -> V_78 -> V_167 ;
} else
#endif
F_40 ( V_73 -> V_78 -> V_102 * 8 +
( V_169 ) ( V_73 -> V_78 -> V_170 & 0x07 ) , V_1 -> V_77 ) ;
V_1 -> V_171 . V_172 += 1 ;
switch ( F_30 ( V_73 -> V_165 [ 0 ] ) ) {
case V_106 :
V_1 -> V_171 . V_173 += 1 ;
break;
case V_110 :
V_1 -> V_171 . V_174 += 1 ;
break;
case V_111 :
V_1 -> V_171 . V_175 += 1 ;
break;
}
}
return V_176 ;
}
static void F_41 ( T_1 * V_1 , struct V_148 * * V_177 ,
unsigned int V_178 )
{
struct V_148 * V_73 = * V_177 ;
F_1 ( V_1 , V_62 , V_63 | V_64 ) ;
V_1 -> V_171 . V_179 += 1 ;
if ( V_73 ) {
* V_177 = NULL ;
F_42 ( V_1 ) ;
V_73 -> V_178 = V_178 << 16 | V_1 -> V_22 . V_23 . V_180 << 8 | V_1 -> V_22 . V_23 . V_181 ;
if ( V_178 == V_182 ) {
int V_183 = 0 ;
if ( V_73 -> V_184 == 0 ) {
if ( V_1 -> V_22 . V_23 . V_24 &&
F_30 ( V_73 -> V_165 [ 0 ] ) != V_111 )
V_183 = 1 ;
} else {
if ( V_1 -> V_22 . V_23 . V_27 < V_73 -> V_184 ||
V_1 -> V_22 . V_23 . V_27 != V_1 -> V_20 . V_26 )
V_183 = 1 ;
}
if ( V_1 -> V_20 . V_162 )
V_183 = 0 ;
if ( V_183 ) {
switch ( F_43 ( V_73 -> V_178 ) ) {
case V_185 :
case V_186 :
case V_187 :
case V_188 :
case V_189 :
break;
default:
F_8 ( V_190 L_27 ,
V_1 -> V_1 -> V_18 , V_73 -> V_178 ) ;
F_44 ( V_73 -> V_165 ) ;
F_7 ( V_1 , L_28 ) ;
F_28 ( V_1 , V_73 -> V_78 -> V_102 ) ;
V_73 -> V_178 &= 0xffff ;
V_73 -> V_178 |= V_191 << 16 ;
}
}
}
if ( ! V_73 -> V_192 )
F_45 ( L_29 , V_1 -> V_1 -> V_18 ) ;
F_46 ( V_73 -> V_78 -> V_102 * 8 +
( V_169 ) ( V_73 -> V_78 -> V_170 & 0x7 ) , V_1 -> V_77 ) ;
V_73 -> V_192 ( V_73 ) ;
} else
F_8 ( L_30 , V_1 -> V_1 -> V_18 ) ;
V_1 -> V_22 . V_74 = V_75 ;
}
static
void F_47 ( T_1 * V_1 , struct V_193 * V_23 , unsigned int V_28 )
{
V_23 -> V_24 += V_28 ;
V_23 -> V_25 -= V_28 ;
if ( V_23 -> V_25 == 0 && F_48 ( V_23 ) == 0 )
V_1 -> V_20 . V_162 = 1 ;
}
static
void F_49 ( T_1 * V_1 , char * V_24 ,
unsigned int V_21 , unsigned int V_28 )
{
extern void V_194 ( void V_195 * , char * V_196 , int V_14 ) ;
unsigned int V_197 , V_145 , V_14 = V_28 ;
V_197 = ( V_21 >> 12 ) ;
V_145 = V_21 & ( ( 1 << 12 ) - 1 ) ;
F_2 ( ( V_197 & 0x3f ) | V_1 -> V_44 . V_45 , V_1 -> V_46 + V_47 ) ;
while ( V_14 > 0 ) {
unsigned int V_198 ;
if ( V_14 + V_145 > ( 1 << 12 ) )
V_198 = ( 1 << 12 ) - V_145 ;
else
V_198 = V_14 ;
V_194 ( V_1 -> V_4 + ( V_145 << 1 ) , V_24 , V_198 ) ;
V_145 += V_198 ;
V_24 += V_198 ;
V_14 -= V_198 ;
if ( V_145 == ( 1 << 12 ) ) {
V_145 = 0 ;
V_197 ++ ;
F_2 ( ( V_197 & 0x3f ) | V_1 -> V_44 . V_45 , V_1 -> V_46 + V_47 ) ;
}
}
F_2 ( V_1 -> V_44 . V_45 , V_1 -> V_46 + V_47 ) ;
}
static
void F_50 ( T_1 * V_1 , char * V_24 ,
unsigned int V_21 , unsigned int V_28 )
{
extern void V_199 ( void V_195 * , char * V_196 , int V_14 ) ;
unsigned int V_197 , V_145 , V_14 = V_28 ;
V_197 = ( V_21 >> 12 ) ;
V_145 = V_21 & ( ( 1 << 12 ) - 1 ) ;
F_2 ( ( V_197 & 0x3f ) | V_1 -> V_44 . V_45 , V_1 -> V_46 + V_47 ) ;
while ( V_14 > 0 ) {
unsigned int V_198 ;
if ( V_14 + V_145 > ( 1 << 12 ) )
V_198 = ( 1 << 12 ) - V_145 ;
else
V_198 = V_14 ;
V_199 ( V_1 -> V_4 + ( V_145 << 1 ) , V_24 , V_198 ) ;
V_145 += V_198 ;
V_24 += V_198 ;
V_14 -= V_198 ;
if ( V_145 == ( 1 << 12 ) ) {
V_145 = 0 ;
V_197 ++ ;
F_2 ( ( V_197 & 0x3f ) | V_1 -> V_44 . V_45 , V_1 -> V_46 + V_47 ) ;
}
}
F_2 ( V_1 -> V_44 . V_45 , V_1 -> V_46 + V_47 ) ;
}
static inline
void F_51 ( T_1 * V_1 )
{
F_22 ( V_1 , V_19 , V_200 ) ;
F_52 ( V_1 ) ;
#if ( V_154 & V_201 )
F_38 ( V_1 -> V_73 , F_7 ( V_1 , L_31 ) ) ;
#endif
}
static
void F_53 ( T_1 * V_1 , T_5 V_202 )
{
unsigned int V_203 , V_28 , V_12 ;
V_1 -> V_20 . V_202 = V_202 ;
F_22 ( V_1 , V_19 , V_200 ) ;
if ( V_202 == V_204 ) {
#if ( V_154 & V_205 )
if ( V_206 & ( 1 << V_1 -> V_73 -> V_78 -> V_102 ) ) {
F_8 ( V_54 L_32 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ) ;
return;
}
#endif
V_12 = V_207 ;
} else
V_12 = V_208 ;
V_28 = F_54 (unsigned int, host->scsi.SCp.this_residual, DMAC_BUFFER_SIZE / 2 ) ;
if ( V_28 ) {
V_1 -> V_20 . V_21 = V_203 = V_1 -> V_20 . V_209 ;
V_1 -> V_20 . V_209 = ( V_1 -> V_20 . V_209 + V_28 ) &
( V_210 - 1 ) ;
if ( V_202 == V_204 )
F_50 ( V_1 , V_1 -> V_22 . V_23 . V_24 , V_1 -> V_20 . V_21 ,
V_28 ) ;
V_28 -= 1 ;
F_22 ( V_1 , V_17 , V_28 ) ;
F_22 ( V_1 , V_16 , V_28 >> 8 ) ;
F_22 ( V_1 , V_10 , V_203 ) ;
F_22 ( V_1 , V_9 , V_203 >> 8 ) ;
F_22 ( V_1 , V_8 , 0 ) ;
F_22 ( V_1 , V_15 , V_12 ) ;
F_22 ( V_1 , V_19 , V_211 ) ;
#if ( V_154 & V_201 )
F_38 ( V_1 -> V_73 , F_7 ( V_1 , L_33 ) ) ;
#endif
V_1 -> V_20 . V_160 = 1 ;
}
}
static
void F_42 ( T_1 * V_1 )
{
F_22 ( V_1 , V_19 , V_200 ) ;
F_52 ( V_1 ) ;
if ( V_1 -> V_20 . V_161 ) {
V_1 -> V_20 . V_161 = 0 ;
if ( V_1 -> V_20 . V_202 == V_212 )
F_49 ( V_1 , V_1 -> V_20 . V_213 ,
V_1 -> V_20 . V_214 , V_1 -> V_20 . V_215 ) ;
}
if ( V_1 -> V_20 . V_160 ) {
unsigned int V_26 ;
V_1 -> V_20 . V_160 = 0 ;
#if ( V_154 & V_201 )
F_38 ( V_1 -> V_73 , F_7 ( V_1 , L_34 ) ) ;
#endif
V_26 = F_5 ( V_1 ) - V_1 -> V_20 . V_21 ;
V_1 -> V_20 . V_26 += V_26 ;
if ( V_1 -> V_20 . V_202 == V_212 )
F_49 ( V_1 , V_1 -> V_22 . V_23 . V_24 ,
V_1 -> V_20 . V_21 , V_26 ) ;
F_47 ( V_1 , & V_1 -> V_22 . V_23 , V_26 ) ;
#if ( V_154 & V_201 )
F_38 ( V_1 -> V_73 , F_7 ( V_1 , L_35 ) ) ;
#endif
}
}
static
void F_55 ( T_1 * V_1 )
{
unsigned int V_203 , V_28 , V_26 ;
#if ( V_154 & V_201 )
F_38 ( V_1 -> V_73 , F_7 ( V_1 , L_36 ) ) ;
#endif
F_22 ( V_1 , V_19 , V_200 ) ;
F_52 ( V_1 ) ;
V_26 = F_5 ( V_1 ) - V_1 -> V_20 . V_21 ;
V_1 -> V_20 . V_26 += V_26 ;
if ( V_1 -> V_20 . V_202 == V_212 ) {
V_1 -> V_20 . V_214 = V_1 -> V_20 . V_21 ;
V_1 -> V_20 . V_215 = V_26 ;
V_1 -> V_20 . V_213 = V_1 -> V_22 . V_23 . V_24 ;
V_1 -> V_20 . V_161 = 1 ;
}
F_47 ( V_1 , & V_1 -> V_22 . V_23 , V_26 ) ;
V_28 = F_54 (unsigned int, host->scsi.SCp.this_residual, DMAC_BUFFER_SIZE / 2 ) ;
if ( V_28 ) {
V_1 -> V_20 . V_21 = V_203 = V_1 -> V_20 . V_209 ;
V_1 -> V_20 . V_209 = ( V_1 -> V_20 . V_209 + V_28 ) &
( V_210 - 1 ) ;
if ( V_1 -> V_20 . V_202 == V_204 )
F_50 ( V_1 , V_1 -> V_22 . V_23 . V_24 , V_1 -> V_20 . V_21 ,
V_28 ) ;
V_28 -= 1 ;
F_22 ( V_1 , V_17 , V_28 ) ;
F_22 ( V_1 , V_16 , V_28 >> 8 ) ;
F_22 ( V_1 , V_10 , V_203 ) ;
F_22 ( V_1 , V_9 , V_203 >> 8 ) ;
F_22 ( V_1 , V_8 , 0 ) ;
F_22 ( V_1 , V_19 , V_211 ) ;
#if ( V_154 & V_201 )
F_38 ( V_1 -> V_73 , F_7 ( V_1 , L_37 ) ) ;
#endif
} else {
V_1 -> V_20 . V_160 = 0 ;
#if 0
if (dmac_read(host, DMAC_STATUS) & STATUS_RQ0) {
acornscsi_abortcmd(host, host->SCpnt->tag);
dmac_write(host, DMAC_TXCNTLO, 0);
dmac_write(host, DMAC_TXCNTHI, 0);
dmac_write(host, DMAC_TXADRLO, 0);
dmac_write(host, DMAC_TXADRMD, 0);
dmac_write(host, DMAC_TXADRHI, 0);
dmac_write(host, DMAC_MASKREG, MASK_OFF);
}
#endif
}
}
static
void F_56 ( T_1 * V_1 )
{
V_1 -> V_20 . V_161 = 0 ;
if ( V_1 -> V_20 . V_202 == V_212 )
F_49 ( V_1 , V_1 -> V_20 . V_213 ,
V_1 -> V_20 . V_214 , V_1 -> V_20 . V_215 ) ;
}
static
void F_57 ( T_1 * V_1 )
{
if ( V_1 -> V_20 . V_160 ) {
signed long V_26 ;
#if ( V_154 & ( V_201 | V_216 ) )
F_38 ( V_1 -> V_73 , F_7 ( V_1 , L_38 ) ) ;
#endif
V_26 = V_1 -> V_22 . V_23 . V_27 - V_1 -> V_20 . V_26 ;
if ( V_26 < 0 )
F_8 ( L_39 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_26 ) ;
else if ( V_26 == 0 )
V_1 -> V_20 . V_160 = 0 ;
else {
V_26 += V_1 -> V_20 . V_21 ;
F_22 ( V_1 , V_10 , V_26 ) ;
F_22 ( V_1 , V_9 , V_26 >> 8 ) ;
F_22 ( V_1 , V_8 , V_26 >> 16 ) ;
#if ( V_154 & ( V_201 | V_216 ) )
F_38 ( V_1 -> V_73 , F_7 ( V_1 , L_40 ) ) ;
#endif
}
}
}
static int
F_58 ( T_1 * V_1 , char * V_217 , int * V_24 , int V_14 , unsigned int V_218 )
{
unsigned int V_34 , V_32 = V_218 ;
int V_219 = * V_24 ;
while ( V_219 < V_14 ) {
V_34 = F_3 ( V_1 , V_7 ) ;
if ( V_34 & V_91 ) {
V_32 = V_218 ;
F_1 ( V_1 , V_220 , V_217 [ V_219 ++ ] ) ;
} else if ( V_34 & V_87 )
break;
else if ( -- V_32 == 0 )
break;
F_12 ( 1 ) ;
}
* V_24 = V_219 ;
return ( V_32 == 0 ) ? - 1 : 0 ;
}
static void
F_59 ( T_1 * V_1 )
{
struct V_148 * V_73 = V_1 -> V_73 ;
F_1 ( V_1 , V_29 , 0 ) ;
F_60 ( V_1 , 0 ) ;
F_60 ( V_1 , V_73 -> V_221 - V_1 -> V_22 . V_23 . V_222 ) ;
F_13 ( V_1 , V_223 ) ;
if ( F_58 ( V_1 , V_73 -> V_165 ,
( int * ) & V_1 -> V_22 . V_23 . V_222 , V_73 -> V_221 , 1000000 ) )
F_8 ( L_41 , V_1 -> V_1 -> V_18 ) ;
V_1 -> V_22 . V_74 = V_224 ;
}
static
void F_61 ( T_1 * V_1 )
{
unsigned int V_225 = F_62 ( & V_1 -> V_22 . V_226 ) ;
unsigned int V_227 ;
struct V_228 * V_33 ;
#if ( V_154 & V_229 )
F_8 ( L_42 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ) ;
#endif
switch ( V_225 ) {
case 0 :
F_13 ( V_1 , V_223 | V_230 ) ;
F_11 ( V_1 , V_91 , V_91 , 1000 , L_43 ) ;
F_1 ( V_1 , V_220 , V_231 ) ;
V_1 -> V_22 . V_232 = V_231 ;
#if ( V_154 & V_229 )
F_8 ( L_44 ) ;
#endif
break;
case 1 :
F_13 ( V_1 , V_223 | V_230 ) ;
V_33 = F_63 ( & V_1 -> V_22 . V_226 , 0 ) ;
F_11 ( V_1 , V_91 , V_91 , 1000 , L_45 ) ;
F_1 ( V_1 , V_220 , V_33 -> V_33 [ 0 ] ) ;
V_1 -> V_22 . V_232 = V_33 -> V_33 [ 0 ] ;
#if ( V_154 & V_229 )
F_64 ( V_33 -> V_33 ) ;
#endif
break;
default:
F_1 ( V_1 , V_29 , 0 ) ;
F_60 ( V_1 , 0 ) ;
F_60 ( V_1 , V_225 ) ;
F_13 ( V_1 , V_223 ) ;
V_227 = 0 ;
while ( ( V_33 = F_63 ( & V_1 -> V_22 . V_226 , V_227 ++ ) ) != NULL ) {
unsigned int V_43 ;
#if ( V_154 & V_229 )
F_64 ( V_33 ) ;
#endif
V_43 = 0 ;
if ( F_58 ( V_1 , V_33 -> V_33 , & V_43 , V_33 -> V_28 , 1000000 ) )
F_8 ( L_46 , V_1 -> V_1 -> V_18 ) ;
V_1 -> V_22 . V_232 = V_33 -> V_33 [ 0 ] ;
if ( V_33 -> V_33 [ 0 ] == V_233 )
V_1 -> V_22 . V_232 |= V_33 -> V_33 [ 2 ] << 8 ;
if ( V_43 != V_33 -> V_28 )
break;
}
break;
}
#if ( V_154 & V_229 )
F_8 ( L_5 ) ;
#endif
}
static
void F_65 ( T_1 * V_1 )
{
F_13 ( V_1 , V_223 | V_230 ) ;
F_11 ( V_1 , V_91 , V_91 , 1000 , L_47 ) ;
V_1 -> V_22 . V_23 . V_181 = F_3 ( V_1 , V_220 ) ;
}
static
unsigned char F_66 ( T_1 * V_1 )
{
unsigned char V_228 ;
F_13 ( V_1 , V_223 | V_230 ) ;
F_11 ( V_1 , V_91 , V_91 , 1000 , L_48 ) ;
V_228 = F_3 ( V_1 , V_220 ) ;
F_11 ( V_1 , V_87 , V_87 , 1000 , L_49 ) ;
F_3 ( V_1 , V_49 ) ;
return V_228 ;
}
static
void F_67 ( T_1 * V_1 )
{
unsigned char V_228 [ 16 ] ;
unsigned int V_234 = 0 , V_235 = 1 ;
do {
V_228 [ V_234 ] = F_66 ( V_1 ) ;
switch ( V_234 ) {
case 0 :
if ( V_228 [ 0 ] == V_233 ||
( V_228 [ 0 ] >= 0x20 && V_228 [ 0 ] <= 0x2f ) )
V_235 = 2 ;
break;
case 1 :
if ( V_228 [ 0 ] == V_233 )
V_235 += V_228 [ V_234 ] ;
break;
}
V_234 += 1 ;
if ( V_234 < V_235 ) {
F_13 ( V_1 , V_236 ) ;
F_11 ( V_1 , V_87 , V_87 , 1000 , L_50 ) ;
F_3 ( V_1 , V_49 ) ;
}
} while ( V_234 < V_235 );
#if ( V_154 & V_229 )
F_8 ( L_51 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ) ;
F_64 ( V_228 ) ;
F_8 ( L_5 ) ;
#endif
if ( V_1 -> V_22 . V_74 == V_237 ) {
if ( V_228 [ 0 ] == V_238 )
V_1 -> V_22 . V_239 . V_168 = V_228 [ 1 ] ;
if ( F_68 ( V_1 ) )
V_1 -> V_22 . V_74 = V_240 ;
}
switch ( V_228 [ 0 ] ) {
case ABORT :
case V_241 :
case V_242 :
if ( V_1 -> V_22 . V_74 != V_243 ) {
F_8 ( V_190 L_52 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ) ;
F_28 ( V_1 , V_1 -> V_73 -> V_78 -> V_102 ) ;
}
V_1 -> V_22 . V_74 = V_244 ;
V_1 -> V_22 . V_23 . V_180 = V_228 [ 0 ] ;
break;
case V_245 :
F_42 ( V_1 ) ;
V_1 -> V_73 -> V_23 = V_1 -> V_22 . V_23 ;
V_1 -> V_73 -> V_23 . V_222 = 0 ;
V_1 -> V_22 . V_74 = V_240 ;
break;
case V_246 :
F_42 ( V_1 ) ;
V_1 -> V_22 . V_23 = V_1 -> V_73 -> V_23 ;
V_1 -> V_22 . V_74 = V_240 ;
break;
case V_247 :
F_42 ( V_1 ) ;
V_1 -> V_22 . V_74 = V_248 ;
break;
case V_249 :
#if 0
if (host->device[host->SCpnt->device->id].sync_state == SYNC_SENT_REQUEST)
host->device[host->SCpnt->device->id].sync_state = SYNC_NEGOCIATE;
#endif
if ( F_62 ( & V_1 -> V_22 . V_226 ) )
F_13 ( V_1 , V_250 ) ;
switch ( V_1 -> V_22 . V_232 ) {
#ifdef F_39
case V_251 :
case V_252 :
case V_238 :
F_8 ( V_253 L_53 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ) ;
V_1 -> V_73 -> V_78 -> V_166 = 0 ;
F_40 ( V_1 -> V_73 -> V_78 -> V_102 * 8 +
( V_169 ) ( V_1 -> V_73 -> V_78 -> V_170 & 0x7 ) , V_1 -> V_77 ) ;
break;
#endif
case V_233 | ( V_254 << 8 ) :
F_8 ( V_253 L_54 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ) ;
V_1 -> V_78 [ V_1 -> V_73 -> V_78 -> V_102 ] . V_255 = V_61 ;
V_1 -> V_78 [ V_1 -> V_73 -> V_78 -> V_102 ] . V_79 = V_256 ;
F_1 ( V_1 , V_60 , V_1 -> V_78 [ V_1 -> V_73 -> V_78 -> V_102 ] . V_255 ) ;
break;
default:
break;
}
break;
case V_188 :
break;
case V_238 :
F_8 ( L_55 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ,
V_228 [ 1 ] ) ;
break;
case V_233 :
switch ( V_228 [ 2 ] ) {
#ifdef F_69
case V_254 :
if ( V_1 -> V_78 [ V_1 -> V_73 -> V_78 -> V_102 ] . V_79 == V_257 ) {
V_1 -> V_78 [ V_1 -> V_73 -> V_78 -> V_102 ] . V_79 = V_258 ;
F_8 ( V_253 L_56 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ,
V_228 [ 4 ] , V_228 [ 3 ] * 4 ) ;
V_1 -> V_78 [ V_1 -> V_73 -> V_78 -> V_102 ] . V_255 =
F_34 ( V_228 [ 3 ] * 4 , V_228 [ 4 ] ) ;
} else {
unsigned char V_144 , V_28 ;
F_13 ( V_1 , V_250 ) ;
V_144 = F_70 (unsigned int, message[3], sdtr_period / 4 ) ;
V_28 = F_54 (unsigned int, message[4], sdtr_size) ;
F_71 ( & V_1 -> V_22 . V_226 , 5 , V_233 , 3 ,
V_254 , V_144 , V_28 ) ;
V_1 -> V_78 [ V_1 -> V_73 -> V_78 -> V_102 ] . V_255 =
F_34 ( V_144 * 4 , V_28 ) ;
}
F_1 ( V_1 , V_60 , V_1 -> V_78 [ V_1 -> V_73 -> V_78 -> V_102 ] . V_255 ) ;
break;
#else
#endif
case V_259 :
default:
F_13 ( V_1 , V_250 ) ;
F_72 ( & V_1 -> V_22 . V_226 ) ;
F_71 ( & V_1 -> V_22 . V_226 , 1 , V_249 ) ;
break;
}
break;
default:
F_8 ( V_190 L_57 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ,
V_228 [ 0 ] ) ;
F_13 ( V_1 , V_250 ) ;
F_72 ( & V_1 -> V_22 . V_226 ) ;
F_71 ( & V_1 -> V_22 . V_226 , 1 , V_249 ) ;
V_1 -> V_22 . V_74 = V_240 ;
break;
}
F_13 ( V_1 , V_236 ) ;
}
static
void F_73 ( T_1 * V_1 )
{
#if 0
if (cmd_reset) {
msgqueue_addmsg(&host->scsi.msgs, 1, BUS_DEVICE_RESET);
return;
}
#endif
F_71 ( & V_1 -> V_22 . V_226 , 1 ,
F_74 ( V_1 -> V_78 [ V_1 -> V_73 -> V_78 -> V_102 ] . V_81 ,
V_1 -> V_73 -> V_78 -> V_170 ) ) ;
#if 0
if (cmd_aborted) {
acornscsi_abortcmd(host->SCpnt->tag);
return;
}
#endif
#ifdef F_39
if ( V_1 -> V_73 -> V_168 ) {
unsigned int V_260 ;
if ( V_1 -> V_73 -> V_165 [ 0 ] == V_261 ||
V_1 -> V_73 -> V_165 [ 0 ] == V_262 ||
V_1 -> V_73 -> V_165 [ 0 ] == V_263 )
V_260 = V_251 ;
else
V_260 = V_238 ;
F_71 ( & V_1 -> V_22 . V_226 , 2 , V_260 , V_1 -> V_73 -> V_168 ) ;
}
#endif
#ifdef F_69
if ( V_1 -> V_78 [ V_1 -> V_73 -> V_78 -> V_102 ] . V_79 == V_80 ) {
V_1 -> V_78 [ V_1 -> V_73 -> V_78 -> V_102 ] . V_79 = V_257 ;
F_71 ( & V_1 -> V_22 . V_226 , 5 ,
V_233 , 3 , V_254 ,
V_264 / 4 , V_265 ) ;
}
#endif
}
static
int F_75 ( T_1 * V_1 )
{
int V_266 ;
if ( ! V_1 -> V_22 . V_23 . V_24 ) {
F_8 ( V_190 L_58 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ) ;
return 0 ;
}
V_266 = F_76 ( V_1 -> V_73 ) - V_1 -> V_22 . V_23 . V_27 ;
F_1 ( V_1 , V_60 , V_1 -> V_78 [ V_1 -> V_73 -> V_78 -> V_102 ] . V_255 ) ;
F_60 ( V_1 , V_266 >> 16 ) ;
F_60 ( V_1 , V_266 >> 8 ) ;
F_60 ( V_1 , V_266 ) ;
F_13 ( V_1 , V_223 ) ;
return 1 ;
}
static
int F_77 ( T_1 * V_1 )
{
unsigned int V_92 , V_170 , V_267 = 0 ;
V_92 = F_3 ( V_1 , V_62 ) ;
if ( ! ( V_92 & 8 ) )
F_8 ( V_190 L_59
L_60 ,
V_1 -> V_1 -> V_18 ) ;
V_92 &= 7 ;
if ( V_1 -> V_73 && ! V_1 -> V_22 . V_76 ) {
F_8 ( V_190 L_61
L_62 ,
V_1 -> V_1 -> V_18 , V_92 , V_1 -> V_73 -> V_78 -> V_102 ) ;
V_1 -> V_73 = NULL ;
}
V_170 = F_3 ( V_1 , V_220 ) & 7 ;
V_1 -> V_22 . V_239 . V_92 = V_92 ;
V_1 -> V_22 . V_239 . V_170 = V_170 ;
V_1 -> V_22 . V_239 . V_168 = 0 ;
if ( V_1 -> V_22 . V_76 && V_1 -> V_73 &&
V_1 -> V_73 -> V_78 -> V_102 == V_92 && V_1 -> V_73 -> V_78 -> V_170 == V_170 )
V_267 = 1 ;
if ( ! V_267 && F_78 ( & V_1 -> V_150 . V_153 , V_92 , V_170 ) )
V_267 = 1 ;
F_79 ( V_92 , 0x81 , V_1 -> V_22 . V_74 , 0 ) ;
if ( V_267 ) {
V_1 -> V_22 . V_74 = V_237 ;
} else {
F_8 ( V_190 L_63
L_64 ,
V_1 -> V_1 -> V_18 , '0' + V_92 ) ;
F_28 ( V_1 , V_92 ) ;
F_80 ( V_1 , 0 ) ;
if ( V_1 -> V_73 ) {
F_37 ( & V_1 -> V_150 . V_153 , V_1 -> V_73 ) ;
V_1 -> V_73 = NULL ;
}
}
F_13 ( V_1 , V_236 ) ;
return ! V_267 ;
}
static
int F_68 ( T_1 * V_1 )
{
if ( V_1 -> V_22 . V_76 && V_1 -> V_73 ) {
V_1 -> V_22 . V_76 = 0 ;
if ( V_1 -> V_73 -> V_78 -> V_102 == V_1 -> V_22 . V_239 . V_92 &&
V_1 -> V_73 -> V_78 -> V_170 == V_1 -> V_22 . V_239 . V_170 &&
V_1 -> V_73 -> V_168 == V_1 -> V_22 . V_239 . V_168 ) {
#if ( V_154 & ( V_155 | V_156 ) )
F_38 ( V_1 -> V_73 , F_8 ( L_65 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ) ) ;
#endif
} else {
F_37 ( & V_1 -> V_150 . V_153 , V_1 -> V_73 ) ;
#if ( V_154 & ( V_155 | V_156 ) )
F_38 ( V_1 -> V_73 , F_8 ( L_66
L_67 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ) ) ;
#endif
V_1 -> V_73 = NULL ;
}
}
if ( ! V_1 -> V_73 ) {
V_1 -> V_73 = F_81 ( & V_1 -> V_150 . V_153 ,
V_1 -> V_22 . V_239 . V_92 ,
V_1 -> V_22 . V_239 . V_170 ,
V_1 -> V_22 . V_239 . V_168 ) ;
#if ( V_154 & ( V_155 | V_156 ) )
F_38 ( V_1 -> V_73 , F_8 ( L_68 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ) ) ;
#endif
}
if ( ! V_1 -> V_73 )
F_80 ( V_1 , V_1 -> V_22 . V_239 . V_168 ) ;
else {
V_1 -> V_22 . V_23 = V_1 -> V_73 -> V_23 ;
#if ( V_154 & ( V_155 | V_156 ) )
F_8 ( L_69 ,
V_1 -> V_22 . V_23 . V_24 , V_1 -> V_22 . V_23 . V_25 ) ;
#endif
}
#if ( V_154 & ( V_155 | V_156 ) )
F_8 ( L_5 ) ;
#endif
V_1 -> V_20 . V_26 = V_1 -> V_22 . V_23 . V_27 ;
return V_1 -> V_73 != NULL ;
}
static
void F_82 ( T_1 * V_1 )
{
F_8 ( V_190 L_70 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ) ;
#if ( V_154 & V_163 )
F_28 ( V_1 , 8 ) ;
#endif
F_41 ( V_1 , & V_1 -> V_73 , V_191 ) ;
}
static
void F_80 ( T_1 * V_1 , unsigned char V_168 )
{
V_1 -> V_22 . V_74 = V_268 ;
F_1 ( V_1 , V_37 , V_250 ) ;
F_72 ( & V_1 -> V_22 . V_226 ) ;
#ifdef F_39
if ( V_168 )
F_71 ( & V_1 -> V_22 . V_226 , 2 , V_241 , V_168 ) ;
else
#endif
F_71 ( & V_1 -> V_22 . V_226 , 1 , ABORT ) ;
}
static
T_4 F_83 ( T_1 * V_1 , int V_269 )
{
unsigned int V_34 , V_82 ;
V_34 = F_3 ( V_1 , V_7 ) ;
if ( ! ( V_34 & V_87 ) )
return V_152 ;
V_82 = F_3 ( V_1 , V_49 ) ;
#if ( V_154 & V_270 )
F_25 ( V_34 , V_82 , V_1 -> V_22 . V_74 ) ;
#endif
F_79 ( 8 , V_82 , V_1 -> V_22 . V_74 , V_269 ) ;
if ( V_1 -> V_73 && ! V_1 -> V_22 . V_76 )
F_79 ( V_1 -> V_73 -> V_78 -> V_102 , V_82 , V_1 -> V_22 . V_74 , V_269 ) ;
switch ( V_82 ) {
case 0x00 :
F_8 ( V_190 L_71 ,
V_1 -> V_1 -> V_18 ) ;
F_1 ( V_1 , V_50 , V_51 | V_1 -> V_1 -> V_52 ) ;
F_1 ( V_1 , V_37 , V_53 ) ;
return V_152 ;
case 0x01 :
F_1 ( V_1 , V_55 , V_56 | V_57 ) ;
F_1 ( V_1 , V_58 , V_59 ) ;
F_1 ( V_1 , V_60 , V_61 ) ;
F_1 ( V_1 , V_62 , V_63 | V_64 ) ;
F_72 ( & V_1 -> V_22 . V_226 ) ;
return V_152 ;
case 0x41 :
F_82 ( V_1 ) ;
return V_271 ;
}
switch ( V_1 -> V_22 . V_74 ) {
case V_159 :
switch ( V_82 ) {
case 0x11 :
V_1 -> V_22 . V_74 = V_272 ;
F_72 ( & V_1 -> V_22 . V_226 ) ;
V_1 -> V_20 . V_26 = V_1 -> V_22 . V_23 . V_27 ;
V_34 = F_3 ( V_1 , V_7 ) ;
if ( ! ( V_34 & V_87 ) )
break;
V_82 = F_3 ( V_1 , V_49 ) ;
F_79 ( 8 , V_82 , V_1 -> V_22 . V_74 , 1 ) ;
F_79 ( V_1 -> V_73 -> V_78 -> V_102 , V_82 , V_1 -> V_22 . V_74 , 1 ) ;
goto V_273;
case 0x42 :
F_41 ( V_1 , & V_1 -> V_73 , V_274 ) ;
return V_271 ;
case 0x81 :
V_1 -> V_149 = V_1 -> V_73 ;
V_1 -> V_73 = NULL ;
F_72 ( & V_1 -> V_22 . V_226 ) ;
F_77 ( V_1 ) ;
break;
default:
F_8 ( V_190 L_72 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_82 ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
F_80 ( V_1 , V_1 -> V_73 -> V_168 ) ;
}
return V_176 ;
V_273:
case V_272 :
switch ( V_82 ) {
#ifdef F_84
case 0x8a :
F_59 ( V_1 ) ;
break;
case 0x8b :
F_65 ( V_1 ) ;
V_1 -> V_22 . V_74 = V_243 ;
break;
#endif
case 0x8e :
V_1 -> V_22 . V_74 = V_275 ;
F_73 ( V_1 ) ;
F_61 ( V_1 ) ;
break;
case 0x85 :
F_41 ( V_1 , & V_1 -> V_73 , V_191 ) ;
break;
default:
F_8 ( V_190 L_73 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_82 ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
F_80 ( V_1 , V_1 -> V_73 -> V_168 ) ;
}
return V_176 ;
case V_275 :
switch ( V_82 ) {
case 0x8a :
case 0x1a :
F_59 ( V_1 ) ;
break;
case 0x8b :
case 0x1b :
F_65 ( V_1 ) ;
V_1 -> V_22 . V_74 = V_243 ;
break;
case 0x8e :
F_61 ( V_1 ) ;
break;
case 0x4f :
case 0x1f :
F_67 ( V_1 ) ;
break;
default:
F_8 ( V_190 L_74 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_82 ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
}
return V_176 ;
case V_224 :
switch ( V_82 ) {
case 0x18 :
if ( V_1 -> V_22 . V_23 . V_222 != V_1 -> V_73 -> V_221 )
F_80 ( V_1 , V_1 -> V_73 -> V_168 ) ;
F_53 ( V_1 , V_204 ) ;
if ( ! F_75 ( V_1 ) )
F_80 ( V_1 , V_1 -> V_73 -> V_168 ) ;
V_1 -> V_22 . V_74 = V_276 ;
return V_152 ;
case 0x19 :
if ( V_1 -> V_22 . V_23 . V_222 != V_1 -> V_73 -> V_221 )
F_80 ( V_1 , V_1 -> V_73 -> V_168 ) ;
F_53 ( V_1 , V_212 ) ;
if ( ! F_75 ( V_1 ) )
F_80 ( V_1 , V_1 -> V_73 -> V_168 ) ;
V_1 -> V_22 . V_74 = V_277 ;
return V_152 ;
case 0x1b :
F_65 ( V_1 ) ;
V_1 -> V_22 . V_74 = V_243 ;
break;
case 0x1e :
F_61 ( V_1 ) ;
break;
case 0x1f :
F_67 ( V_1 ) ;
break;
default:
F_8 ( V_190 L_75 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_82 ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
}
return V_176 ;
case V_248 :
if ( V_82 == 0x85 ) {
V_1 -> V_22 . V_76 = 1 ;
V_1 -> V_22 . V_239 . V_168 = 0 ;
V_1 -> V_22 . V_74 = V_75 ;
V_1 -> V_171 . V_278 += 1 ;
} else {
F_8 ( V_190 L_76 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_82 ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
}
return V_271 ;
case V_75 :
if ( V_82 == 0x81 )
F_77 ( V_1 ) ;
else {
F_8 ( V_190 L_77 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_82 ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
}
return V_176 ;
case V_237 :
if ( V_82 != 0x8f && ! F_68 ( V_1 ) )
return V_152 ;
F_79 ( V_1 -> V_73 -> V_78 -> V_102 , V_82 , V_1 -> V_22 . V_74 , V_269 ) ;
switch ( V_82 ) {
case 0x88 :
F_53 ( V_1 , V_204 ) ;
if ( ! F_75 ( V_1 ) )
F_80 ( V_1 , V_1 -> V_73 -> V_168 ) ;
V_1 -> V_22 . V_74 = V_276 ;
return V_152 ;
case 0x89 :
F_53 ( V_1 , V_212 ) ;
if ( ! F_75 ( V_1 ) )
F_80 ( V_1 , V_1 -> V_73 -> V_168 ) ;
V_1 -> V_22 . V_74 = V_277 ;
return V_152 ;
case 0x8a :
F_59 ( V_1 ) ;
break;
case 0x8b :
F_65 ( V_1 ) ;
V_1 -> V_22 . V_74 = V_243 ;
break;
case 0x8e :
F_61 ( V_1 ) ;
break;
case 0x8f :
F_67 ( V_1 ) ;
break;
default:
F_8 ( V_190 L_78 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_82 ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
}
return V_176 ;
case V_277 :
switch ( V_82 ) {
case 0x19 :
case 0x89 :
F_80 ( V_1 , V_1 -> V_73 -> V_168 ) ;
return V_152 ;
case 0x1b :
case 0x4b :
case 0x8b :
V_1 -> V_22 . V_23 . V_27 = F_76 ( V_1 -> V_73 ) -
F_9 ( V_1 ) ;
F_51 ( V_1 ) ;
F_65 ( V_1 ) ;
V_1 -> V_22 . V_74 = V_243 ;
break;
case 0x1e :
case 0x4e :
case 0x8e :
V_1 -> V_22 . V_23 . V_27 = F_76 ( V_1 -> V_73 ) -
F_9 ( V_1 ) ;
F_51 ( V_1 ) ;
F_61 ( V_1 ) ;
break;
case 0x1f :
case 0x4f :
case 0x8f :
V_1 -> V_22 . V_23 . V_27 = F_76 ( V_1 -> V_73 ) -
F_9 ( V_1 ) ;
F_51 ( V_1 ) ;
F_67 ( V_1 ) ;
break;
default:
F_8 ( V_190 L_79 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_82 ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
}
return V_176 ;
case V_276 :
switch ( V_82 ) {
case 0x18 :
case 0x88 :
F_80 ( V_1 , V_1 -> V_73 -> V_168 ) ;
return V_152 ;
case 0x1b :
case 0x4b :
case 0x8b :
V_1 -> V_22 . V_23 . V_27 = F_76 ( V_1 -> V_73 ) -
F_9 ( V_1 ) ;
F_51 ( V_1 ) ;
F_57 ( V_1 ) ;
F_65 ( V_1 ) ;
V_1 -> V_22 . V_74 = V_243 ;
break;
case 0x1e :
case 0x4e :
case 0x8e :
V_1 -> V_22 . V_23 . V_27 = F_76 ( V_1 -> V_73 ) -
F_9 ( V_1 ) ;
F_51 ( V_1 ) ;
F_57 ( V_1 ) ;
F_61 ( V_1 ) ;
break;
case 0x1f :
case 0x4f :
case 0x8f :
V_1 -> V_22 . V_23 . V_27 = F_76 ( V_1 -> V_73 ) -
F_9 ( V_1 ) ;
F_51 ( V_1 ) ;
F_57 ( V_1 ) ;
F_67 ( V_1 ) ;
break;
default:
F_8 ( V_190 L_80 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_82 ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
}
return V_176 ;
case V_243 :
switch ( V_82 ) {
case 0x1f :
case 0x8f :
F_67 ( V_1 ) ;
break;
case 0x1e :
case 0x8e :
F_61 ( V_1 ) ;
break;
default:
F_8 ( V_190 L_81 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_82 ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
}
return V_176 ;
case V_240 :
switch ( V_82 ) {
case 0x1e :
case 0x4e :
case 0x8e :
F_61 ( V_1 ) ;
break;
case 0x1f :
case 0x2f :
case 0x4f :
case 0x8f :
F_67 ( V_1 ) ;
break;
case 0x85 :
F_8 ( L_82 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
F_41 ( V_1 , & V_1 -> V_73 , V_191 ) ;
break;
default:
F_8 ( V_190 L_83 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_82 ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
}
return V_176 ;
case V_244 :
switch ( V_82 ) {
case 0x85 :
F_41 ( V_1 , & V_1 -> V_73 , V_182 ) ;
return V_271 ;
case 0x1e :
case 0x8e :
F_61 ( V_1 ) ;
break;
default:
F_8 ( V_190 L_84 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_82 ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
}
return V_176 ;
case V_268 :
switch ( V_82 ) {
case 0x85 :
if ( V_1 -> V_73 )
F_41 ( V_1 , & V_1 -> V_73 , V_279 ) ;
else {
F_46 ( V_1 -> V_22 . V_239 . V_92 * 8 + V_1 -> V_22 . V_239 . V_170 ,
V_1 -> V_77 ) ;
V_1 -> V_22 . V_74 = V_75 ;
}
return V_271 ;
case 0x1e :
case 0x2e :
case 0x4e :
case 0x8e :
F_61 ( V_1 ) ;
break;
default:
F_8 ( V_190 L_85 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_82 ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
}
return V_176 ;
default:
F_8 ( V_190 L_86 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_82 ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
}
return V_176 ;
}
static T_6
F_85 ( int V_100 , void * V_280 )
{
T_1 * V_1 = ( T_1 * ) V_280 ;
T_4 V_281 ;
int V_282 ;
int V_269 = 0 ;
do {
V_281 = V_152 ;
V_282 = F_21 ( V_1 -> V_46 + V_48 ) ;
if ( V_282 & 2 ) {
F_55 ( V_1 ) ;
V_282 = F_21 ( V_1 -> V_46 + V_48 ) ;
}
if ( V_282 & 8 )
V_281 = F_83 ( V_1 , V_269 ) ;
if ( V_1 -> V_20 . V_161 )
F_56 ( V_1 ) ;
if ( V_281 == V_271 )
V_281 = F_35 ( V_1 ) ;
V_269 = 1 ;
} while ( V_281 != V_152 );
return V_283 ;
}
static int F_86 ( struct V_148 * V_73 ,
void (* F_87)( struct V_148 * ) )
{
T_1 * V_1 = ( T_1 * ) V_73 -> V_78 -> V_1 -> V_284 ;
if ( ! F_87 ) {
F_45 ( L_87 ,
V_1 -> V_1 -> V_18 , V_73 ) ;
return - V_285 ;
}
#if ( V_154 & V_205 )
if ( F_30 ( V_73 -> V_165 [ 0 ] ) == V_106 && ( V_206 & ( 1 << V_73 -> V_78 -> V_102 ) ) ) {
F_8 ( V_54 L_88 ,
V_1 -> V_1 -> V_18 , '0' + V_73 -> V_78 -> V_102 ) ;
V_73 -> V_178 = V_274 << 16 ;
F_87 ( V_73 ) ;
return 0 ;
}
#endif
V_73 -> V_192 = F_87 ;
V_73 -> V_286 = NULL ;
V_73 -> V_178 = 0 ;
V_73 -> V_168 = 0 ;
V_73 -> V_23 . V_74 = ( int ) F_31 ( V_73 -> V_165 [ 0 ] ) ;
V_73 -> V_23 . V_222 = 0 ;
V_73 -> V_23 . V_27 = 0 ;
F_88 ( V_73 ) ;
V_1 -> V_171 . V_150 += 1 ;
{
unsigned long V_40 ;
if ( ! F_89 ( & V_1 -> V_150 . V_151 , V_73 ) ) {
V_73 -> V_178 = V_191 << 16 ;
F_87 ( V_73 ) ;
return 0 ;
}
F_90 ( V_40 ) ;
if ( V_1 -> V_22 . V_74 == V_75 )
F_35 ( V_1 ) ;
F_19 ( V_40 ) ;
}
return 0 ;
}
static inline void F_91 ( struct V_148 * * V_287 ,
struct V_148 * * V_288 ,
int V_178 )
{
struct V_148 * V_73 = * V_287 ;
if ( V_73 ) {
* V_287 = NULL ;
V_73 -> V_178 = V_178 ;
V_73 -> V_192 ( V_73 ) ;
}
if ( V_73 == * V_288 )
* V_288 = NULL ;
}
static enum V_289 F_92 ( T_1 * V_1 , struct V_148 * V_73 )
{
enum V_289 V_290 = V_291 ;
if ( F_93 ( & V_1 -> V_150 . V_151 , V_73 ) ) {
F_8 ( L_89 ) ;
V_290 = V_292 ;
} else if ( F_93 ( & V_1 -> V_150 . V_153 , V_73 ) ) {
F_8 ( L_90 ) ;
V_290 = V_292 ;
} else if ( V_1 -> V_73 == V_73 ) {
unsigned long V_40 ;
F_8 ( L_91 ) ;
F_90 ( V_40 ) ;
switch ( V_1 -> V_22 . V_74 ) {
case V_75 :
if ( V_1 -> V_22 . V_76 ) {
V_1 -> V_22 . V_76 = 0 ;
V_1 -> V_73 = NULL ;
V_290 = V_292 ;
}
break;
case V_272 :
F_1 ( V_1 , V_37 , V_293 ) ;
V_1 -> V_73 = NULL ;
V_290 = V_294 ;
break;
default:
F_80 ( V_1 , V_1 -> V_73 -> V_168 ) ;
V_290 = V_295 ;
}
F_19 ( V_40 ) ;
} else if ( V_1 -> V_149 == V_73 ) {
V_1 -> V_149 = NULL ;
F_8 ( L_92 ) ;
V_290 = V_294 ;
} else
F_8 ( L_93 ) ;
return V_290 ;
}
int F_94 ( struct V_148 * V_73 )
{
T_1 * V_1 = ( T_1 * ) V_73 -> V_78 -> V_1 -> V_284 ;
int V_178 ;
V_1 -> V_171 . V_296 += 1 ;
#if ( V_154 & V_163 )
{
int V_34 , V_82 ;
V_34 = F_3 ( V_1 , V_7 ) ;
V_82 = F_3 ( V_1 , V_49 ) ;
F_8 ( V_297 L_94 ) ;
F_25 ( V_34 , V_82 , V_1 -> V_22 . V_74 ) ;
F_28 ( V_1 , V_73 -> V_78 -> V_102 ) ;
}
#endif
F_8 ( L_95 , V_1 -> V_1 -> V_18 ) ;
switch ( F_92 ( V_1 , V_73 ) ) {
case V_294 :
F_8 ( L_96 ) ;
F_46 ( V_73 -> V_78 -> V_102 * 8 +
( V_169 ) ( V_73 -> V_78 -> V_170 & 0x7 ) , V_1 -> V_77 ) ;
case V_292 :
F_8 ( L_97 ) ;
V_178 = V_298 ;
break;
case V_295 :
F_8 ( L_98 ) ;
V_178 = V_299 ;
break;
default:
case V_291 :
F_28 ( V_1 , V_73 -> V_78 -> V_102 ) ;
V_178 = V_299 ;
F_8 ( L_99 ) ;
break;
}
return V_178 ;
}
int F_95 ( struct V_148 * V_73 )
{
T_1 * V_1 = ( T_1 * ) V_73 -> V_78 -> V_1 -> V_284 ;
struct V_148 * V_300 ;
V_1 -> V_171 . V_301 += 1 ;
#if ( V_154 & V_302 )
{
int V_34 , V_82 ;
V_34 = F_3 ( V_1 , V_7 ) ;
V_82 = F_3 ( V_1 , V_49 ) ;
F_8 ( V_297 L_100 ) ;
F_25 ( V_34 , V_82 , V_1 -> V_22 . V_74 ) ;
F_28 ( V_1 , V_73 -> V_78 -> V_102 ) ;
}
#endif
F_51 ( V_1 ) ;
F_20 ( V_1 ) ;
while ( ( V_300 = F_96 ( & V_1 -> V_150 . V_153 ) ) != NULL )
;
return V_298 ;
}
const
char * F_97 ( struct V_303 * V_1 )
{
static char string [ 100 ] , * V_304 ;
V_304 = string ;
V_304 += sprintf ( string , L_101
#ifdef F_69
L_102
#endif
#ifdef F_39
L_103
#endif
#if ( V_154 & V_205 )
L_104 F_98 ( V_206 ) L_105
#endif
, V_1 -> V_305 -> V_306 , V_1 -> V_307 , V_1 -> V_100 ,
V_308 , V_309 , V_310 ) ;
return string ;
}
static int F_99 ( struct V_311 * V_312 , struct V_303 * V_313 )
{
int V_314 ;
struct V_315 * V_316 ;
T_1 * V_1 ;
V_1 = ( T_1 * ) V_313 -> V_284 ;
F_100 ( V_312 , L_106
#ifdef F_69
L_102
#endif
#ifdef F_39
L_103
#endif
#if ( V_154 & V_205 )
L_104 F_98 ( V_206 ) L_105
#endif
L_107 , V_308 , V_309 , V_310 ) ;
F_100 ( V_312 , L_108 ,
V_1 -> V_4 + V_5 , V_1 -> V_22 . V_100 ) ;
#ifdef F_23
F_100 ( V_312 , L_109 ,
V_1 -> V_4 + V_317 , V_1 -> V_22 . V_100 ) ;
#endif
F_100 ( V_312 , L_110
L_111
L_112
L_113
L_114
L_115 ,
V_1 -> V_171 . V_150 , V_1 -> V_171 . V_172 ,
V_1 -> V_171 . V_179 , V_1 -> V_171 . V_174 ,
V_1 -> V_171 . V_173 , V_1 -> V_171 . V_175 ,
V_1 -> V_171 . V_278 , V_1 -> V_171 . V_296 ,
V_1 -> V_171 . V_301 ) ;
for ( V_314 = 0 ; V_314 < 9 ; V_314 ++ ) {
unsigned int V_318 , V_93 ;
F_100 ( V_312 , L_116 , V_314 == 8 ? 'H' : ( '0' + V_314 ) ) ;
V_318 = V_1 -> V_94 [ V_314 ] - 10 ;
if ( ( signed int ) V_318 < 0 )
V_318 += V_96 ;
V_93 = V_1 -> V_97 [ V_314 ] [ V_318 ] . V_98 ;
for (; V_318 != V_1 -> V_94 [ V_314 ] ; V_318 = ( V_318 + 1 ) & ( V_96 - 1 ) ) {
if ( V_1 -> V_97 [ V_314 ] [ V_318 ] . V_98 ) {
F_100 ( V_312 , L_117 ,
V_1 -> V_97 [ V_314 ] [ V_318 ] . V_100 ? '-' : ' ' ,
V_1 -> V_97 [ V_314 ] [ V_318 ] . V_101 ,
V_1 -> V_97 [ V_314 ] [ V_318 ] . V_82 ,
( V_1 -> V_97 [ V_314 ] [ V_318 ] . V_98 - V_93 ) < 100 ?
( V_1 -> V_97 [ V_314 ] [ V_318 ] . V_98 - V_93 ) : 99 ) ;
V_93 = V_1 -> V_97 [ V_314 ] [ V_318 ] . V_98 ;
}
}
}
F_100 ( V_312 , L_118 ) ;
F_101 (scd, instance) {
F_100 ( V_312 , L_119 ) ;
F_100 ( V_312 , L_120 , V_316 -> V_102 , V_316 -> V_170 ) ;
if ( V_316 -> V_319 )
F_100 ( V_312 , L_121 ,
V_316 -> V_166 ? L_122 : L_123 ,
V_316 -> V_167 ) ;
else
F_100 ( V_312 , L_124 ) ;
if ( V_1 -> V_78 [ V_316 -> V_102 ] . V_255 & 15 )
F_100 ( V_312 , L_125 ,
V_1 -> V_78 [ V_316 -> V_102 ] . V_255 & 15 ,
F_32 ( V_1 -> V_78 [ V_316 -> V_102 ] . V_255 ) ) ;
else
F_100 ( V_312 , L_126 ) ;
}
return 0 ;
}
static int F_102 ( struct V_320 * V_321 , const struct V_322 * V_102 )
{
struct V_303 * V_1 ;
T_1 * V_323 ;
int V_281 ;
V_281 = F_103 ( V_321 ) ;
if ( V_281 )
goto V_324;
V_1 = F_104 ( & V_325 , sizeof( T_1 ) ) ;
if ( ! V_1 ) {
V_281 = - V_326 ;
goto V_327;
}
V_323 = ( T_1 * ) V_1 -> V_284 ;
V_323 -> V_4 = F_105 ( V_321 , V_328 , 0 , 0 ) ;
V_323 -> V_46 = F_105 ( V_321 , V_329 , 0 , 0 ) ;
if ( ! V_323 -> V_4 || ! V_323 -> V_46 )
goto V_330;
V_1 -> V_100 = V_321 -> V_100 ;
V_323 -> V_1 = V_1 ;
V_323 -> V_22 . V_100 = V_1 -> V_100 ;
V_321 -> V_331 = V_323 -> V_46 + V_48 ;
V_321 -> V_332 = 0x0a ;
V_281 = F_106 ( V_1 -> V_100 , F_85 , 0 , L_127 , V_323 ) ;
if ( V_281 ) {
F_8 ( V_54 L_128 ,
V_1 -> V_18 , V_323 -> V_22 . V_100 , V_281 ) ;
goto V_330;
}
memset ( & V_323 -> V_171 , 0 , sizeof ( V_323 -> V_171 ) ) ;
F_107 ( & V_323 -> V_150 . V_151 ) ;
F_107 ( & V_323 -> V_150 . V_153 ) ;
F_108 ( & V_323 -> V_22 . V_226 ) ;
F_20 ( V_323 ) ;
V_281 = F_109 ( V_1 , & V_321 -> V_333 ) ;
if ( V_281 )
goto V_334;
F_110 ( V_1 ) ;
goto V_324;
V_334:
F_111 ( V_1 -> V_100 , V_323 ) ;
F_112 ( & V_323 -> V_22 . V_226 ) ;
F_113 ( & V_323 -> V_150 . V_153 ) ;
F_113 ( & V_323 -> V_150 . V_151 ) ;
V_330:
F_114 ( V_321 , V_323 -> V_46 ) ;
F_114 ( V_321 , V_323 -> V_4 ) ;
F_115 ( V_1 ) ;
V_327:
F_116 ( V_321 ) ;
V_324:
return V_281 ;
}
static void F_117 ( struct V_320 * V_321 )
{
struct V_303 * V_1 = F_118 ( V_321 ) ;
T_1 * V_323 = ( T_1 * ) V_1 -> V_284 ;
F_119 ( V_321 , NULL ) ;
F_120 ( V_1 ) ;
F_2 ( 0x80 , V_323 -> V_46 + V_47 ) ;
F_111 ( V_1 -> V_100 , V_323 ) ;
F_112 ( & V_323 -> V_22 . V_226 ) ;
F_113 ( & V_323 -> V_150 . V_153 ) ;
F_113 ( & V_323 -> V_150 . V_151 ) ;
F_114 ( V_321 , V_323 -> V_46 ) ;
F_114 ( V_321 , V_323 -> V_4 ) ;
F_115 ( V_1 ) ;
F_116 ( V_321 ) ;
}
static int T_7 F_121 ( void )
{
return F_122 ( & V_335 ) ;
}
static void T_8 F_123 ( void )
{
F_124 ( & V_335 ) ;
}
