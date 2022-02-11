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
F_40 ( V_73 -> V_78 -> V_102 * 8 + V_73 -> V_78 -> V_169 , V_1 -> V_77 ) ;
V_1 -> V_170 . V_171 += 1 ;
switch ( F_30 ( V_73 -> V_165 [ 0 ] ) ) {
case V_106 :
V_1 -> V_170 . V_172 += 1 ;
break;
case V_110 :
V_1 -> V_170 . V_173 += 1 ;
break;
case V_111 :
V_1 -> V_170 . V_174 += 1 ;
break;
}
}
return V_175 ;
}
static void F_41 ( T_1 * V_1 , struct V_148 * * V_176 ,
unsigned int V_177 )
{
struct V_148 * V_73 = * V_176 ;
F_1 ( V_1 , V_62 , V_63 | V_64 ) ;
V_1 -> V_170 . V_178 += 1 ;
if ( V_73 ) {
* V_176 = NULL ;
F_42 ( V_1 ) ;
V_73 -> V_177 = V_177 << 16 | V_1 -> V_22 . V_23 . V_179 << 8 | V_1 -> V_22 . V_23 . V_180 ;
if ( V_177 == V_181 ) {
int V_182 = 0 ;
if ( V_73 -> V_183 == 0 ) {
if ( V_1 -> V_22 . V_23 . V_24 &&
F_30 ( V_73 -> V_165 [ 0 ] ) != V_111 )
V_182 = 1 ;
} else {
if ( V_1 -> V_22 . V_23 . V_27 < V_73 -> V_183 ||
V_1 -> V_22 . V_23 . V_27 != V_1 -> V_20 . V_26 )
V_182 = 1 ;
}
if ( V_1 -> V_20 . V_162 )
V_182 = 0 ;
if ( V_182 ) {
switch ( F_43 ( V_73 -> V_177 ) ) {
case V_184 :
case V_185 :
case V_186 :
case V_187 :
case V_188 :
break;
default:
F_8 ( V_189 L_27 ,
V_1 -> V_1 -> V_18 , V_73 -> V_177 ) ;
F_44 ( V_73 -> V_165 ) ;
F_7 ( V_1 , L_28 ) ;
F_28 ( V_1 , V_73 -> V_78 -> V_102 ) ;
V_73 -> V_177 &= 0xffff ;
V_73 -> V_177 |= V_190 << 16 ;
}
}
}
if ( ! V_73 -> V_191 )
F_45 ( L_29 , V_1 -> V_1 -> V_18 ) ;
F_46 ( V_73 -> V_78 -> V_102 * 8 + V_73 -> V_78 -> V_169 , V_1 -> V_77 ) ;
V_73 -> V_191 ( V_73 ) ;
} else
F_8 ( L_30 , V_1 -> V_1 -> V_18 ) ;
V_1 -> V_22 . V_74 = V_75 ;
}
static
void F_47 ( T_1 * V_1 , struct V_192 * V_23 , unsigned int V_28 )
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
extern void V_193 ( void V_194 * , char * V_195 , int V_14 ) ;
unsigned int V_196 , V_145 , V_14 = V_28 ;
V_196 = ( V_21 >> 12 ) ;
V_145 = V_21 & ( ( 1 << 12 ) - 1 ) ;
F_2 ( ( V_196 & 0x3f ) | V_1 -> V_44 . V_45 , V_1 -> V_46 + V_47 ) ;
while ( V_14 > 0 ) {
unsigned int V_197 ;
if ( V_14 + V_145 > ( 1 << 12 ) )
V_197 = ( 1 << 12 ) - V_145 ;
else
V_197 = V_14 ;
V_193 ( V_1 -> V_4 + ( V_145 << 1 ) , V_24 , V_197 ) ;
V_145 += V_197 ;
V_24 += V_197 ;
V_14 -= V_197 ;
if ( V_145 == ( 1 << 12 ) ) {
V_145 = 0 ;
V_196 ++ ;
F_2 ( ( V_196 & 0x3f ) | V_1 -> V_44 . V_45 , V_1 -> V_46 + V_47 ) ;
}
}
F_2 ( V_1 -> V_44 . V_45 , V_1 -> V_46 + V_47 ) ;
}
static
void F_50 ( T_1 * V_1 , char * V_24 ,
unsigned int V_21 , unsigned int V_28 )
{
extern void V_198 ( void V_194 * , char * V_195 , int V_14 ) ;
unsigned int V_196 , V_145 , V_14 = V_28 ;
V_196 = ( V_21 >> 12 ) ;
V_145 = V_21 & ( ( 1 << 12 ) - 1 ) ;
F_2 ( ( V_196 & 0x3f ) | V_1 -> V_44 . V_45 , V_1 -> V_46 + V_47 ) ;
while ( V_14 > 0 ) {
unsigned int V_197 ;
if ( V_14 + V_145 > ( 1 << 12 ) )
V_197 = ( 1 << 12 ) - V_145 ;
else
V_197 = V_14 ;
V_198 ( V_1 -> V_4 + ( V_145 << 1 ) , V_24 , V_197 ) ;
V_145 += V_197 ;
V_24 += V_197 ;
V_14 -= V_197 ;
if ( V_145 == ( 1 << 12 ) ) {
V_145 = 0 ;
V_196 ++ ;
F_2 ( ( V_196 & 0x3f ) | V_1 -> V_44 . V_45 , V_1 -> V_46 + V_47 ) ;
}
}
F_2 ( V_1 -> V_44 . V_45 , V_1 -> V_46 + V_47 ) ;
}
static inline
void F_51 ( T_1 * V_1 )
{
F_22 ( V_1 , V_19 , V_199 ) ;
F_52 ( V_1 ) ;
#if ( V_154 & V_200 )
F_38 ( V_1 -> V_73 , F_7 ( V_1 , L_31 ) ) ;
#endif
}
static
void F_53 ( T_1 * V_1 , T_5 V_201 )
{
unsigned int V_202 , V_28 , V_12 ;
V_1 -> V_20 . V_201 = V_201 ;
F_22 ( V_1 , V_19 , V_199 ) ;
if ( V_201 == V_203 ) {
#if ( V_154 & V_204 )
if ( V_205 & ( 1 << V_1 -> V_73 -> V_78 -> V_102 ) ) {
F_8 ( V_54 L_32 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ) ;
return;
}
#endif
V_12 = V_206 ;
} else
V_12 = V_207 ;
V_28 = F_54 (unsigned int, host->scsi.SCp.this_residual, DMAC_BUFFER_SIZE / 2 ) ;
if ( V_28 ) {
V_1 -> V_20 . V_21 = V_202 = V_1 -> V_20 . V_208 ;
V_1 -> V_20 . V_208 = ( V_1 -> V_20 . V_208 + V_28 ) &
( V_209 - 1 ) ;
if ( V_201 == V_203 )
F_50 ( V_1 , V_1 -> V_22 . V_23 . V_24 , V_1 -> V_20 . V_21 ,
V_28 ) ;
V_28 -= 1 ;
F_22 ( V_1 , V_17 , V_28 ) ;
F_22 ( V_1 , V_16 , V_28 >> 8 ) ;
F_22 ( V_1 , V_10 , V_202 ) ;
F_22 ( V_1 , V_9 , V_202 >> 8 ) ;
F_22 ( V_1 , V_8 , 0 ) ;
F_22 ( V_1 , V_15 , V_12 ) ;
F_22 ( V_1 , V_19 , V_210 ) ;
#if ( V_154 & V_200 )
F_38 ( V_1 -> V_73 , F_7 ( V_1 , L_33 ) ) ;
#endif
V_1 -> V_20 . V_160 = 1 ;
}
}
static
void F_42 ( T_1 * V_1 )
{
F_22 ( V_1 , V_19 , V_199 ) ;
F_52 ( V_1 ) ;
if ( V_1 -> V_20 . V_161 ) {
V_1 -> V_20 . V_161 = 0 ;
if ( V_1 -> V_20 . V_201 == V_211 )
F_49 ( V_1 , V_1 -> V_20 . V_212 ,
V_1 -> V_20 . V_213 , V_1 -> V_20 . V_214 ) ;
}
if ( V_1 -> V_20 . V_160 ) {
unsigned int V_26 ;
V_1 -> V_20 . V_160 = 0 ;
#if ( V_154 & V_200 )
F_38 ( V_1 -> V_73 , F_7 ( V_1 , L_34 ) ) ;
#endif
V_26 = F_5 ( V_1 ) - V_1 -> V_20 . V_21 ;
V_1 -> V_20 . V_26 += V_26 ;
if ( V_1 -> V_20 . V_201 == V_211 )
F_49 ( V_1 , V_1 -> V_22 . V_23 . V_24 ,
V_1 -> V_20 . V_21 , V_26 ) ;
F_47 ( V_1 , & V_1 -> V_22 . V_23 , V_26 ) ;
#if ( V_154 & V_200 )
F_38 ( V_1 -> V_73 , F_7 ( V_1 , L_35 ) ) ;
#endif
}
}
static
void F_55 ( T_1 * V_1 )
{
unsigned int V_202 , V_28 , V_26 ;
#if ( V_154 & V_200 )
F_38 ( V_1 -> V_73 , F_7 ( V_1 , L_36 ) ) ;
#endif
F_22 ( V_1 , V_19 , V_199 ) ;
F_52 ( V_1 ) ;
V_26 = F_5 ( V_1 ) - V_1 -> V_20 . V_21 ;
V_1 -> V_20 . V_26 += V_26 ;
if ( V_1 -> V_20 . V_201 == V_211 ) {
V_1 -> V_20 . V_213 = V_1 -> V_20 . V_21 ;
V_1 -> V_20 . V_214 = V_26 ;
V_1 -> V_20 . V_212 = V_1 -> V_22 . V_23 . V_24 ;
V_1 -> V_20 . V_161 = 1 ;
}
F_47 ( V_1 , & V_1 -> V_22 . V_23 , V_26 ) ;
V_28 = F_54 (unsigned int, host->scsi.SCp.this_residual, DMAC_BUFFER_SIZE / 2 ) ;
if ( V_28 ) {
V_1 -> V_20 . V_21 = V_202 = V_1 -> V_20 . V_208 ;
V_1 -> V_20 . V_208 = ( V_1 -> V_20 . V_208 + V_28 ) &
( V_209 - 1 ) ;
if ( V_1 -> V_20 . V_201 == V_203 )
F_50 ( V_1 , V_1 -> V_22 . V_23 . V_24 , V_1 -> V_20 . V_21 ,
V_28 ) ;
V_28 -= 1 ;
F_22 ( V_1 , V_17 , V_28 ) ;
F_22 ( V_1 , V_16 , V_28 >> 8 ) ;
F_22 ( V_1 , V_10 , V_202 ) ;
F_22 ( V_1 , V_9 , V_202 >> 8 ) ;
F_22 ( V_1 , V_8 , 0 ) ;
F_22 ( V_1 , V_19 , V_210 ) ;
#if ( V_154 & V_200 )
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
if ( V_1 -> V_20 . V_201 == V_211 )
F_49 ( V_1 , V_1 -> V_20 . V_212 ,
V_1 -> V_20 . V_213 , V_1 -> V_20 . V_214 ) ;
}
static
void F_57 ( T_1 * V_1 )
{
if ( V_1 -> V_20 . V_160 ) {
signed long V_26 ;
#if ( V_154 & ( V_200 | V_215 ) )
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
#if ( V_154 & ( V_200 | V_215 ) )
F_38 ( V_1 -> V_73 , F_7 ( V_1 , L_40 ) ) ;
#endif
}
}
}
static int
F_58 ( T_1 * V_1 , char * V_216 , int * V_24 , int V_14 , unsigned int V_217 )
{
unsigned int V_34 , V_32 = V_217 ;
int V_218 = * V_24 ;
while ( V_218 < V_14 ) {
V_34 = F_3 ( V_1 , V_7 ) ;
if ( V_34 & V_91 ) {
V_32 = V_217 ;
F_1 ( V_1 , V_219 , V_216 [ V_218 ++ ] ) ;
} else if ( V_34 & V_87 )
break;
else if ( -- V_32 == 0 )
break;
F_12 ( 1 ) ;
}
* V_24 = V_218 ;
return ( V_32 == 0 ) ? - 1 : 0 ;
}
static void
F_59 ( T_1 * V_1 )
{
struct V_148 * V_73 = V_1 -> V_73 ;
F_1 ( V_1 , V_29 , 0 ) ;
F_60 ( V_1 , 0 ) ;
F_60 ( V_1 , V_73 -> V_220 - V_1 -> V_22 . V_23 . V_221 ) ;
F_13 ( V_1 , V_222 ) ;
if ( F_58 ( V_1 , V_73 -> V_165 ,
( int * ) & V_1 -> V_22 . V_23 . V_221 , V_73 -> V_220 , 1000000 ) )
F_8 ( L_41 , V_1 -> V_1 -> V_18 ) ;
V_1 -> V_22 . V_74 = V_223 ;
}
static
void F_61 ( T_1 * V_1 )
{
unsigned int V_224 = F_62 ( & V_1 -> V_22 . V_225 ) ;
unsigned int V_226 ;
struct V_227 * V_33 ;
#if ( V_154 & V_228 )
F_8 ( L_42 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ) ;
#endif
switch ( V_224 ) {
case 0 :
F_13 ( V_1 , V_222 | V_229 ) ;
F_11 ( V_1 , V_91 , V_91 , 1000 , L_43 ) ;
F_1 ( V_1 , V_219 , V_230 ) ;
V_1 -> V_22 . V_231 = V_230 ;
#if ( V_154 & V_228 )
F_8 ( L_44 ) ;
#endif
break;
case 1 :
F_13 ( V_1 , V_222 | V_229 ) ;
V_33 = F_63 ( & V_1 -> V_22 . V_225 , 0 ) ;
F_11 ( V_1 , V_91 , V_91 , 1000 , L_45 ) ;
F_1 ( V_1 , V_219 , V_33 -> V_33 [ 0 ] ) ;
V_1 -> V_22 . V_231 = V_33 -> V_33 [ 0 ] ;
#if ( V_154 & V_228 )
F_64 ( V_33 -> V_33 ) ;
#endif
break;
default:
F_1 ( V_1 , V_29 , 0 ) ;
F_60 ( V_1 , 0 ) ;
F_60 ( V_1 , V_224 ) ;
F_13 ( V_1 , V_222 ) ;
V_226 = 0 ;
while ( ( V_33 = F_63 ( & V_1 -> V_22 . V_225 , V_226 ++ ) ) != NULL ) {
unsigned int V_43 ;
#if ( V_154 & V_228 )
F_64 ( V_33 ) ;
#endif
V_43 = 0 ;
if ( F_58 ( V_1 , V_33 -> V_33 , & V_43 , V_33 -> V_28 , 1000000 ) )
F_8 ( L_46 , V_1 -> V_1 -> V_18 ) ;
V_1 -> V_22 . V_231 = V_33 -> V_33 [ 0 ] ;
if ( V_33 -> V_33 [ 0 ] == V_232 )
V_1 -> V_22 . V_231 |= V_33 -> V_33 [ 2 ] << 8 ;
if ( V_43 != V_33 -> V_28 )
break;
}
break;
}
#if ( V_154 & V_228 )
F_8 ( L_5 ) ;
#endif
}
static
void F_65 ( T_1 * V_1 )
{
F_13 ( V_1 , V_222 | V_229 ) ;
F_11 ( V_1 , V_91 , V_91 , 1000 , L_47 ) ;
V_1 -> V_22 . V_23 . V_180 = F_3 ( V_1 , V_219 ) ;
}
static
unsigned char F_66 ( T_1 * V_1 )
{
unsigned char V_227 ;
F_13 ( V_1 , V_222 | V_229 ) ;
F_11 ( V_1 , V_91 , V_91 , 1000 , L_48 ) ;
V_227 = F_3 ( V_1 , V_219 ) ;
F_11 ( V_1 , V_87 , V_87 , 1000 , L_49 ) ;
F_3 ( V_1 , V_49 ) ;
return V_227 ;
}
static
void F_67 ( T_1 * V_1 )
{
unsigned char V_227 [ 16 ] ;
unsigned int V_233 = 0 , V_234 = 1 ;
do {
V_227 [ V_233 ] = F_66 ( V_1 ) ;
switch ( V_233 ) {
case 0 :
if ( V_227 [ 0 ] == V_232 ||
( V_227 [ 0 ] >= 0x20 && V_227 [ 0 ] <= 0x2f ) )
V_234 = 2 ;
break;
case 1 :
if ( V_227 [ 0 ] == V_232 )
V_234 += V_227 [ V_233 ] ;
break;
}
V_233 += 1 ;
if ( V_233 < V_234 ) {
F_13 ( V_1 , V_235 ) ;
F_11 ( V_1 , V_87 , V_87 , 1000 , L_50 ) ;
F_3 ( V_1 , V_49 ) ;
}
} while ( V_233 < V_234 );
#if ( V_154 & V_228 )
F_8 ( L_51 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ) ;
F_64 ( V_227 ) ;
F_8 ( L_5 ) ;
#endif
if ( V_1 -> V_22 . V_74 == V_236 ) {
if ( V_227 [ 0 ] == V_237 )
V_1 -> V_22 . V_238 . V_168 = V_227 [ 1 ] ;
if ( F_68 ( V_1 ) )
V_1 -> V_22 . V_74 = V_239 ;
}
switch ( V_227 [ 0 ] ) {
case ABORT :
case V_240 :
case V_241 :
if ( V_1 -> V_22 . V_74 != V_242 ) {
F_8 ( V_189 L_52 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ) ;
F_28 ( V_1 , V_1 -> V_73 -> V_78 -> V_102 ) ;
}
V_1 -> V_22 . V_74 = V_243 ;
V_1 -> V_22 . V_23 . V_179 = V_227 [ 0 ] ;
break;
case V_244 :
F_42 ( V_1 ) ;
V_1 -> V_73 -> V_23 = V_1 -> V_22 . V_23 ;
V_1 -> V_73 -> V_23 . V_221 = 0 ;
V_1 -> V_22 . V_74 = V_239 ;
break;
case V_245 :
F_42 ( V_1 ) ;
V_1 -> V_22 . V_23 = V_1 -> V_73 -> V_23 ;
V_1 -> V_22 . V_74 = V_239 ;
break;
case V_246 :
F_42 ( V_1 ) ;
V_1 -> V_22 . V_74 = V_247 ;
break;
case V_248 :
#if 0
if (host->device[host->SCpnt->device->id].sync_state == SYNC_SENT_REQUEST)
host->device[host->SCpnt->device->id].sync_state = SYNC_NEGOCIATE;
#endif
if ( F_62 ( & V_1 -> V_22 . V_225 ) )
F_13 ( V_1 , V_249 ) ;
switch ( V_1 -> V_22 . V_231 ) {
#ifdef F_39
case V_250 :
case V_251 :
case V_237 :
F_8 ( V_252 L_53 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ) ;
V_1 -> V_73 -> V_78 -> V_166 = 0 ;
F_40 ( V_1 -> V_73 -> V_78 -> V_102 * 8 + V_1 -> V_73 -> V_78 -> V_169 , V_1 -> V_77 ) ;
break;
#endif
case V_232 | ( V_253 << 8 ) :
F_8 ( V_252 L_54 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ) ;
V_1 -> V_78 [ V_1 -> V_73 -> V_78 -> V_102 ] . V_254 = V_61 ;
V_1 -> V_78 [ V_1 -> V_73 -> V_78 -> V_102 ] . V_79 = V_255 ;
F_1 ( V_1 , V_60 , V_1 -> V_78 [ V_1 -> V_73 -> V_78 -> V_102 ] . V_254 ) ;
break;
default:
break;
}
break;
case V_187 :
break;
case V_237 :
F_8 ( L_55 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ,
V_227 [ 1 ] ) ;
break;
case V_232 :
switch ( V_227 [ 2 ] ) {
#ifdef F_69
case V_253 :
if ( V_1 -> V_78 [ V_1 -> V_73 -> V_78 -> V_102 ] . V_79 == V_256 ) {
V_1 -> V_78 [ V_1 -> V_73 -> V_78 -> V_102 ] . V_79 = V_257 ;
F_8 ( V_252 L_56 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ,
V_227 [ 4 ] , V_227 [ 3 ] * 4 ) ;
V_1 -> V_78 [ V_1 -> V_73 -> V_78 -> V_102 ] . V_254 =
F_34 ( V_227 [ 3 ] * 4 , V_227 [ 4 ] ) ;
} else {
unsigned char V_144 , V_28 ;
F_13 ( V_1 , V_249 ) ;
V_144 = F_70 (unsigned int, message[3], sdtr_period / 4 ) ;
V_28 = F_54 (unsigned int, message[4], sdtr_size) ;
F_71 ( & V_1 -> V_22 . V_225 , 5 , V_232 , 3 ,
V_253 , V_144 , V_28 ) ;
V_1 -> V_78 [ V_1 -> V_73 -> V_78 -> V_102 ] . V_254 =
F_34 ( V_144 * 4 , V_28 ) ;
}
F_1 ( V_1 , V_60 , V_1 -> V_78 [ V_1 -> V_73 -> V_78 -> V_102 ] . V_254 ) ;
break;
#else
#endif
case V_258 :
default:
F_13 ( V_1 , V_249 ) ;
F_72 ( & V_1 -> V_22 . V_225 ) ;
F_71 ( & V_1 -> V_22 . V_225 , 1 , V_248 ) ;
break;
}
break;
#ifdef F_73
case V_259 :
case V_260 :
if ( 0 ) {
#if ( V_154 & V_261 )
F_8 ( L_57 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_1 -> V_73 -> V_168 ) ;
#endif
if ( ! V_1 -> V_73 -> V_262 ) {
F_8 ( V_263 L_58 ,
V_264 -> V_18 , F_29 ( V_1 ) , V_1 -> V_73 -> V_168 ) ;
F_13 ( V_1 , V_249 ) ;
F_71 ( & V_1 -> V_22 . V_225 , 1 , ABORT ) ;
} else {
struct V_148 * V_73 = V_1 -> V_73 ;
F_42 ( V_1 ) ;
V_1 -> V_73 = V_1 -> V_73 -> V_262 ;
V_1 -> V_73 -> V_168 = V_73 -> V_168 ;
V_73 -> V_177 = V_181 | V_1 -> V_22 . V_23 . V_179 << 8 | V_1 -> V_265 . V_23 . V_180 ;
V_73 -> V_266 ( V_73 ) ;
}
break;
}
#endif
default:
F_8 ( V_189 L_59 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ,
V_227 [ 0 ] ) ;
F_13 ( V_1 , V_249 ) ;
F_72 ( & V_1 -> V_22 . V_225 ) ;
F_71 ( & V_1 -> V_22 . V_225 , 1 , V_248 ) ;
V_1 -> V_22 . V_74 = V_239 ;
break;
}
F_13 ( V_1 , V_235 ) ;
}
static
void F_74 ( T_1 * V_1 )
{
#if 0
if (cmd_reset) {
msgqueue_addmsg(&host->scsi.msgs, 1, BUS_DEVICE_RESET);
return;
}
#endif
F_71 ( & V_1 -> V_22 . V_225 , 1 ,
F_75 ( V_1 -> V_78 [ V_1 -> V_73 -> V_78 -> V_102 ] . V_81 ,
V_1 -> V_73 -> V_78 -> V_169 ) ) ;
#if 0
if (cmd_aborted) {
acornscsi_abortcmd(host->SCpnt->tag);
return;
}
#endif
#ifdef F_39
if ( V_1 -> V_73 -> V_168 ) {
unsigned int V_267 ;
if ( V_1 -> V_73 -> V_165 [ 0 ] == V_268 ||
V_1 -> V_73 -> V_165 [ 0 ] == V_269 ||
V_1 -> V_73 -> V_165 [ 0 ] == V_270 )
V_267 = V_250 ;
else
V_267 = V_237 ;
F_71 ( & V_1 -> V_22 . V_225 , 2 , V_267 , V_1 -> V_73 -> V_168 ) ;
}
#endif
#ifdef F_69
if ( V_1 -> V_78 [ V_1 -> V_73 -> V_78 -> V_102 ] . V_79 == V_80 ) {
V_1 -> V_78 [ V_1 -> V_73 -> V_78 -> V_102 ] . V_79 = V_256 ;
F_71 ( & V_1 -> V_22 . V_225 , 5 ,
V_232 , 3 , V_253 ,
V_271 / 4 , V_272 ) ;
}
#endif
}
static
int F_76 ( T_1 * V_1 )
{
int V_273 ;
if ( ! V_1 -> V_22 . V_23 . V_24 ) {
F_8 ( V_189 L_60 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ) ;
return 0 ;
}
V_273 = F_77 ( V_1 -> V_73 ) - V_1 -> V_22 . V_23 . V_27 ;
F_1 ( V_1 , V_60 , V_1 -> V_78 [ V_1 -> V_73 -> V_78 -> V_102 ] . V_254 ) ;
F_60 ( V_1 , V_273 >> 16 ) ;
F_60 ( V_1 , V_273 >> 8 ) ;
F_60 ( V_1 , V_273 ) ;
F_13 ( V_1 , V_222 ) ;
return 1 ;
}
static
int F_78 ( T_1 * V_1 )
{
unsigned int V_92 , V_169 , V_274 = 0 ;
V_92 = F_3 ( V_1 , V_62 ) ;
if ( ! ( V_92 & 8 ) )
F_8 ( V_189 L_61
L_62 ,
V_1 -> V_1 -> V_18 ) ;
V_92 &= 7 ;
if ( V_1 -> V_73 && ! V_1 -> V_22 . V_76 ) {
F_8 ( V_189 L_63
L_64 ,
V_1 -> V_1 -> V_18 , V_92 , V_1 -> V_73 -> V_78 -> V_102 ) ;
V_1 -> V_73 = NULL ;
}
V_169 = F_3 ( V_1 , V_219 ) & 7 ;
V_1 -> V_22 . V_238 . V_92 = V_92 ;
V_1 -> V_22 . V_238 . V_169 = V_169 ;
V_1 -> V_22 . V_238 . V_168 = 0 ;
if ( V_1 -> V_22 . V_76 && V_1 -> V_73 &&
V_1 -> V_73 -> V_78 -> V_102 == V_92 && V_1 -> V_73 -> V_78 -> V_169 == V_169 )
V_274 = 1 ;
if ( ! V_274 && F_79 ( & V_1 -> V_150 . V_153 , V_92 , V_169 ) )
V_274 = 1 ;
F_80 ( V_92 , 0x81 , V_1 -> V_22 . V_74 , 0 ) ;
if ( V_274 ) {
V_1 -> V_22 . V_74 = V_236 ;
} else {
F_8 ( V_189 L_65
L_66 ,
V_1 -> V_1 -> V_18 , '0' + V_92 ) ;
F_28 ( V_1 , V_92 ) ;
F_81 ( V_1 , 0 ) ;
if ( V_1 -> V_73 ) {
F_37 ( & V_1 -> V_150 . V_153 , V_1 -> V_73 ) ;
V_1 -> V_73 = NULL ;
}
}
F_13 ( V_1 , V_235 ) ;
return ! V_274 ;
}
static
int F_68 ( T_1 * V_1 )
{
if ( V_1 -> V_22 . V_76 && V_1 -> V_73 ) {
V_1 -> V_22 . V_76 = 0 ;
if ( V_1 -> V_73 -> V_78 -> V_102 == V_1 -> V_22 . V_238 . V_92 &&
V_1 -> V_73 -> V_78 -> V_169 == V_1 -> V_22 . V_238 . V_169 &&
V_1 -> V_73 -> V_168 == V_1 -> V_22 . V_238 . V_168 ) {
#if ( V_154 & ( V_155 | V_156 ) )
F_38 ( V_1 -> V_73 , F_8 ( L_67 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ) ) ;
#endif
} else {
F_37 ( & V_1 -> V_150 . V_153 , V_1 -> V_73 ) ;
#if ( V_154 & ( V_155 | V_156 ) )
F_38 ( V_1 -> V_73 , F_8 ( L_68
L_69 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ) ) ;
#endif
V_1 -> V_73 = NULL ;
}
}
if ( ! V_1 -> V_73 ) {
V_1 -> V_73 = F_82 ( & V_1 -> V_150 . V_153 ,
V_1 -> V_22 . V_238 . V_92 ,
V_1 -> V_22 . V_238 . V_169 ,
V_1 -> V_22 . V_238 . V_168 ) ;
#if ( V_154 & ( V_155 | V_156 ) )
F_38 ( V_1 -> V_73 , F_8 ( L_70 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ) ) ;
#endif
}
if ( ! V_1 -> V_73 )
F_81 ( V_1 , V_1 -> V_22 . V_238 . V_168 ) ;
else {
V_1 -> V_22 . V_23 = V_1 -> V_73 -> V_23 ;
#if ( V_154 & ( V_155 | V_156 ) )
F_8 ( L_71 ,
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
void F_83 ( T_1 * V_1 )
{
F_8 ( V_189 L_72 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ) ;
#if ( V_154 & V_163 )
F_28 ( V_1 , 8 ) ;
#endif
F_41 ( V_1 , & V_1 -> V_73 , V_190 ) ;
}
static
void F_81 ( T_1 * V_1 , unsigned char V_168 )
{
V_1 -> V_22 . V_74 = V_275 ;
F_1 ( V_1 , V_37 , V_249 ) ;
F_72 ( & V_1 -> V_22 . V_225 ) ;
#ifdef F_39
if ( V_168 )
F_71 ( & V_1 -> V_22 . V_225 , 2 , V_240 , V_168 ) ;
else
#endif
F_71 ( & V_1 -> V_22 . V_225 , 1 , ABORT ) ;
}
static
T_4 F_84 ( T_1 * V_1 , int V_276 )
{
unsigned int V_34 , V_82 ;
V_34 = F_3 ( V_1 , V_7 ) ;
if ( ! ( V_34 & V_87 ) )
return V_152 ;
V_82 = F_3 ( V_1 , V_49 ) ;
#if ( V_154 & V_277 )
F_25 ( V_34 , V_82 , V_1 -> V_22 . V_74 ) ;
#endif
F_80 ( 8 , V_82 , V_1 -> V_22 . V_74 , V_276 ) ;
if ( V_1 -> V_73 && ! V_1 -> V_22 . V_76 )
F_80 ( V_1 -> V_73 -> V_78 -> V_102 , V_82 , V_1 -> V_22 . V_74 , V_276 ) ;
switch ( V_82 ) {
case 0x00 :
F_8 ( V_189 L_73 ,
V_1 -> V_1 -> V_18 ) ;
F_1 ( V_1 , V_50 , V_51 | V_1 -> V_1 -> V_52 ) ;
F_1 ( V_1 , V_37 , V_53 ) ;
return V_152 ;
case 0x01 :
F_1 ( V_1 , V_55 , V_56 | V_57 ) ;
F_1 ( V_1 , V_58 , V_59 ) ;
F_1 ( V_1 , V_60 , V_61 ) ;
F_1 ( V_1 , V_62 , V_63 | V_64 ) ;
F_72 ( & V_1 -> V_22 . V_225 ) ;
return V_152 ;
case 0x41 :
F_83 ( V_1 ) ;
return V_278 ;
}
switch ( V_1 -> V_22 . V_74 ) {
case V_159 :
switch ( V_82 ) {
case 0x11 :
V_1 -> V_22 . V_74 = V_279 ;
F_72 ( & V_1 -> V_22 . V_225 ) ;
V_1 -> V_20 . V_26 = V_1 -> V_22 . V_23 . V_27 ;
V_34 = F_3 ( V_1 , V_7 ) ;
if ( ! ( V_34 & V_87 ) )
break;
V_82 = F_3 ( V_1 , V_49 ) ;
F_80 ( 8 , V_82 , V_1 -> V_22 . V_74 , 1 ) ;
F_80 ( V_1 -> V_73 -> V_78 -> V_102 , V_82 , V_1 -> V_22 . V_74 , 1 ) ;
goto V_280;
case 0x42 :
F_41 ( V_1 , & V_1 -> V_73 , V_281 ) ;
return V_278 ;
case 0x81 :
V_1 -> V_149 = V_1 -> V_73 ;
V_1 -> V_73 = NULL ;
F_72 ( & V_1 -> V_22 . V_225 ) ;
F_78 ( V_1 ) ;
break;
default:
F_8 ( V_189 L_74 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_82 ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
F_81 ( V_1 , V_1 -> V_73 -> V_168 ) ;
}
return V_175 ;
V_280:
case V_279 :
switch ( V_82 ) {
#ifdef F_85
case 0x8a :
F_59 ( V_1 ) ;
break;
case 0x8b :
F_65 ( V_1 ) ;
V_1 -> V_22 . V_74 = V_242 ;
break;
#endif
case 0x8e :
V_1 -> V_22 . V_74 = V_282 ;
F_74 ( V_1 ) ;
F_61 ( V_1 ) ;
break;
case 0x85 :
F_41 ( V_1 , & V_1 -> V_73 , V_190 ) ;
break;
default:
F_8 ( V_189 L_75 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_82 ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
F_81 ( V_1 , V_1 -> V_73 -> V_168 ) ;
}
return V_175 ;
case V_282 :
switch ( V_82 ) {
case 0x8a :
case 0x1a :
F_59 ( V_1 ) ;
break;
case 0x8b :
case 0x1b :
F_65 ( V_1 ) ;
V_1 -> V_22 . V_74 = V_242 ;
break;
case 0x8e :
F_61 ( V_1 ) ;
break;
case 0x4f :
case 0x1f :
F_67 ( V_1 ) ;
break;
default:
F_8 ( V_189 L_76 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_82 ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
}
return V_175 ;
case V_223 :
switch ( V_82 ) {
case 0x18 :
if ( V_1 -> V_22 . V_23 . V_221 != V_1 -> V_73 -> V_220 )
F_81 ( V_1 , V_1 -> V_73 -> V_168 ) ;
F_53 ( V_1 , V_203 ) ;
if ( ! F_76 ( V_1 ) )
F_81 ( V_1 , V_1 -> V_73 -> V_168 ) ;
V_1 -> V_22 . V_74 = V_283 ;
return V_152 ;
case 0x19 :
if ( V_1 -> V_22 . V_23 . V_221 != V_1 -> V_73 -> V_220 )
F_81 ( V_1 , V_1 -> V_73 -> V_168 ) ;
F_53 ( V_1 , V_211 ) ;
if ( ! F_76 ( V_1 ) )
F_81 ( V_1 , V_1 -> V_73 -> V_168 ) ;
V_1 -> V_22 . V_74 = V_284 ;
return V_152 ;
case 0x1b :
F_65 ( V_1 ) ;
V_1 -> V_22 . V_74 = V_242 ;
break;
case 0x1e :
F_61 ( V_1 ) ;
break;
case 0x1f :
F_67 ( V_1 ) ;
break;
default:
F_8 ( V_189 L_77 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_82 ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
}
return V_175 ;
case V_247 :
if ( V_82 == 0x85 ) {
V_1 -> V_22 . V_76 = 1 ;
V_1 -> V_22 . V_238 . V_168 = 0 ;
V_1 -> V_22 . V_74 = V_75 ;
V_1 -> V_170 . V_285 += 1 ;
} else {
F_8 ( V_189 L_78 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_82 ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
}
return V_278 ;
case V_75 :
if ( V_82 == 0x81 )
F_78 ( V_1 ) ;
else {
F_8 ( V_189 L_79 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_82 ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
}
return V_175 ;
case V_236 :
if ( V_82 != 0x8f && ! F_68 ( V_1 ) )
return V_152 ;
F_80 ( V_1 -> V_73 -> V_78 -> V_102 , V_82 , V_1 -> V_22 . V_74 , V_276 ) ;
switch ( V_82 ) {
case 0x88 :
F_53 ( V_1 , V_203 ) ;
if ( ! F_76 ( V_1 ) )
F_81 ( V_1 , V_1 -> V_73 -> V_168 ) ;
V_1 -> V_22 . V_74 = V_283 ;
return V_152 ;
case 0x89 :
F_53 ( V_1 , V_211 ) ;
if ( ! F_76 ( V_1 ) )
F_81 ( V_1 , V_1 -> V_73 -> V_168 ) ;
V_1 -> V_22 . V_74 = V_284 ;
return V_152 ;
case 0x8a :
F_59 ( V_1 ) ;
break;
case 0x8b :
F_65 ( V_1 ) ;
V_1 -> V_22 . V_74 = V_242 ;
break;
case 0x8e :
F_61 ( V_1 ) ;
break;
case 0x8f :
F_67 ( V_1 ) ;
break;
default:
F_8 ( V_189 L_80 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_82 ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
}
return V_175 ;
case V_284 :
switch ( V_82 ) {
case 0x19 :
case 0x89 :
F_81 ( V_1 , V_1 -> V_73 -> V_168 ) ;
return V_152 ;
case 0x1b :
case 0x4b :
case 0x8b :
V_1 -> V_22 . V_23 . V_27 = F_77 ( V_1 -> V_73 ) -
F_9 ( V_1 ) ;
F_51 ( V_1 ) ;
F_65 ( V_1 ) ;
V_1 -> V_22 . V_74 = V_242 ;
break;
case 0x1e :
case 0x4e :
case 0x8e :
V_1 -> V_22 . V_23 . V_27 = F_77 ( V_1 -> V_73 ) -
F_9 ( V_1 ) ;
F_51 ( V_1 ) ;
F_61 ( V_1 ) ;
break;
case 0x1f :
case 0x4f :
case 0x8f :
V_1 -> V_22 . V_23 . V_27 = F_77 ( V_1 -> V_73 ) -
F_9 ( V_1 ) ;
F_51 ( V_1 ) ;
F_67 ( V_1 ) ;
break;
default:
F_8 ( V_189 L_81 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_82 ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
}
return V_175 ;
case V_283 :
switch ( V_82 ) {
case 0x18 :
case 0x88 :
F_81 ( V_1 , V_1 -> V_73 -> V_168 ) ;
return V_152 ;
case 0x1b :
case 0x4b :
case 0x8b :
V_1 -> V_22 . V_23 . V_27 = F_77 ( V_1 -> V_73 ) -
F_9 ( V_1 ) ;
F_51 ( V_1 ) ;
F_57 ( V_1 ) ;
F_65 ( V_1 ) ;
V_1 -> V_22 . V_74 = V_242 ;
break;
case 0x1e :
case 0x4e :
case 0x8e :
V_1 -> V_22 . V_23 . V_27 = F_77 ( V_1 -> V_73 ) -
F_9 ( V_1 ) ;
F_51 ( V_1 ) ;
F_57 ( V_1 ) ;
F_61 ( V_1 ) ;
break;
case 0x1f :
case 0x4f :
case 0x8f :
V_1 -> V_22 . V_23 . V_27 = F_77 ( V_1 -> V_73 ) -
F_9 ( V_1 ) ;
F_51 ( V_1 ) ;
F_57 ( V_1 ) ;
F_67 ( V_1 ) ;
break;
default:
F_8 ( V_189 L_82 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_82 ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
}
return V_175 ;
case V_242 :
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
F_8 ( V_189 L_83 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_82 ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
}
return V_175 ;
case V_239 :
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
F_8 ( L_84 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
F_41 ( V_1 , & V_1 -> V_73 , V_190 ) ;
break;
default:
F_8 ( V_189 L_85 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_82 ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
}
return V_175 ;
case V_243 :
switch ( V_82 ) {
case 0x85 :
F_41 ( V_1 , & V_1 -> V_73 , V_181 ) ;
return V_278 ;
case 0x1e :
case 0x8e :
F_61 ( V_1 ) ;
break;
default:
F_8 ( V_189 L_86 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_82 ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
}
return V_175 ;
case V_275 :
switch ( V_82 ) {
case 0x85 :
if ( V_1 -> V_73 )
F_41 ( V_1 , & V_1 -> V_73 , V_286 ) ;
else {
F_46 ( V_1 -> V_22 . V_238 . V_92 * 8 + V_1 -> V_22 . V_238 . V_169 ,
V_1 -> V_77 ) ;
V_1 -> V_22 . V_74 = V_75 ;
}
return V_278 ;
case 0x1e :
case 0x2e :
case 0x4e :
case 0x8e :
F_61 ( V_1 ) ;
break;
default:
F_8 ( V_189 L_87 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_82 ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
}
return V_175 ;
default:
F_8 ( V_189 L_88 ,
V_1 -> V_1 -> V_18 , F_29 ( V_1 ) , V_82 ) ;
F_28 ( V_1 , V_1 -> V_73 ? V_1 -> V_73 -> V_78 -> V_102 : 8 ) ;
}
return V_175 ;
}
static T_6
F_86 ( int V_100 , void * V_287 )
{
T_1 * V_1 = ( T_1 * ) V_287 ;
T_4 V_288 ;
int V_289 ;
int V_276 = 0 ;
do {
V_288 = V_152 ;
V_289 = F_21 ( V_1 -> V_46 + V_48 ) ;
if ( V_289 & 2 ) {
F_55 ( V_1 ) ;
V_289 = F_21 ( V_1 -> V_46 + V_48 ) ;
}
if ( V_289 & 8 )
V_288 = F_84 ( V_1 , V_276 ) ;
if ( V_1 -> V_20 . V_161 )
F_56 ( V_1 ) ;
if ( V_288 == V_278 )
V_288 = F_35 ( V_1 ) ;
V_276 = 1 ;
} while ( V_288 != V_152 );
return V_290 ;
}
static int F_87 ( struct V_148 * V_73 ,
void (* V_266)( struct V_148 * ) )
{
T_1 * V_1 = ( T_1 * ) V_73 -> V_78 -> V_1 -> V_291 ;
if ( ! V_266 ) {
F_45 ( L_89 ,
V_1 -> V_1 -> V_18 , V_73 ) ;
return - V_292 ;
}
#if ( V_154 & V_204 )
if ( F_30 ( V_73 -> V_165 [ 0 ] ) == V_106 && ( V_205 & ( 1 << V_73 -> V_78 -> V_102 ) ) ) {
F_8 ( V_54 L_90 ,
V_1 -> V_1 -> V_18 , '0' + V_73 -> V_78 -> V_102 ) ;
V_73 -> V_177 = V_281 << 16 ;
V_266 ( V_73 ) ;
return 0 ;
}
#endif
V_73 -> V_191 = V_266 ;
V_73 -> V_293 = NULL ;
V_73 -> V_177 = 0 ;
V_73 -> V_168 = 0 ;
V_73 -> V_23 . V_74 = ( int ) F_31 ( V_73 -> V_165 [ 0 ] ) ;
V_73 -> V_23 . V_221 = 0 ;
V_73 -> V_23 . V_27 = 0 ;
F_88 ( V_73 ) ;
V_1 -> V_170 . V_150 += 1 ;
{
unsigned long V_40 ;
if ( ! F_89 ( & V_1 -> V_150 . V_151 , V_73 ) ) {
V_73 -> V_177 = V_190 << 16 ;
V_266 ( V_73 ) ;
return 0 ;
}
F_90 ( V_40 ) ;
if ( V_1 -> V_22 . V_74 == V_75 )
F_35 ( V_1 ) ;
F_19 ( V_40 ) ;
}
return 0 ;
}
static inline void F_91 ( struct V_148 * * V_294 ,
struct V_148 * * V_295 ,
int V_177 )
{
struct V_148 * V_73 = * V_294 ;
if ( V_73 ) {
* V_294 = NULL ;
V_73 -> V_177 = V_177 ;
V_73 -> V_191 ( V_73 ) ;
}
if ( V_73 == * V_295 )
* V_295 = NULL ;
}
static enum V_296 F_92 ( T_1 * V_1 , struct V_148 * V_73 )
{
enum V_296 V_297 = V_298 ;
if ( F_93 ( & V_1 -> V_150 . V_151 , V_73 ) ) {
F_8 ( L_91 ) ;
V_297 = V_299 ;
} else if ( F_93 ( & V_1 -> V_150 . V_153 , V_73 ) ) {
F_8 ( L_92 ) ;
V_297 = V_299 ;
} else if ( V_1 -> V_73 == V_73 ) {
unsigned long V_40 ;
F_8 ( L_93 ) ;
F_90 ( V_40 ) ;
switch ( V_1 -> V_22 . V_74 ) {
case V_75 :
if ( V_1 -> V_22 . V_76 ) {
V_1 -> V_22 . V_76 = 0 ;
V_1 -> V_73 = NULL ;
V_297 = V_299 ;
}
break;
case V_279 :
F_1 ( V_1 , V_37 , V_300 ) ;
V_1 -> V_73 = NULL ;
V_297 = V_301 ;
break;
default:
F_81 ( V_1 , V_1 -> V_73 -> V_168 ) ;
V_297 = V_302 ;
}
F_19 ( V_40 ) ;
} else if ( V_1 -> V_149 == V_73 ) {
V_1 -> V_149 = NULL ;
F_8 ( L_94 ) ;
V_297 = V_301 ;
} else
F_8 ( L_95 ) ;
return V_297 ;
}
int F_94 ( struct V_148 * V_73 )
{
T_1 * V_1 = ( T_1 * ) V_73 -> V_78 -> V_1 -> V_291 ;
int V_177 ;
V_1 -> V_170 . V_303 += 1 ;
#if ( V_154 & V_163 )
{
int V_34 , V_82 ;
V_34 = F_3 ( V_1 , V_7 ) ;
V_82 = F_3 ( V_1 , V_49 ) ;
F_8 ( V_263 L_96 ) ;
F_25 ( V_34 , V_82 , V_1 -> V_22 . V_74 ) ;
F_28 ( V_1 , V_73 -> V_78 -> V_102 ) ;
}
#endif
F_8 ( L_97 , V_1 -> V_1 -> V_18 ) ;
switch ( F_92 ( V_1 , V_73 ) ) {
case V_301 :
F_8 ( L_98 ) ;
F_46 ( V_73 -> V_78 -> V_102 * 8 + V_73 -> V_78 -> V_169 , V_1 -> V_77 ) ;
case V_299 :
F_8 ( L_99 ) ;
V_177 = V_304 ;
break;
case V_302 :
F_8 ( L_100 ) ;
V_177 = V_305 ;
break;
default:
case V_298 :
F_28 ( V_1 , V_73 -> V_78 -> V_102 ) ;
V_177 = V_305 ;
F_8 ( L_101 ) ;
break;
}
return V_177 ;
}
int F_95 ( struct V_148 * V_73 )
{
T_1 * V_1 = ( T_1 * ) V_73 -> V_78 -> V_1 -> V_291 ;
struct V_148 * V_306 ;
V_1 -> V_170 . V_307 += 1 ;
#if ( V_154 & V_308 )
{
int V_34 , V_82 ;
V_34 = F_3 ( V_1 , V_7 ) ;
V_82 = F_3 ( V_1 , V_49 ) ;
F_8 ( V_263 L_102 ) ;
F_25 ( V_34 , V_82 , V_1 -> V_22 . V_74 ) ;
F_28 ( V_1 , V_73 -> V_78 -> V_102 ) ;
}
#endif
F_51 ( V_1 ) ;
F_20 ( V_1 ) ;
while ( ( V_306 = F_96 ( & V_1 -> V_150 . V_153 ) ) != NULL )
;
return V_304 ;
}
const
char * F_97 ( struct V_309 * V_1 )
{
static char string [ 100 ] , * V_310 ;
V_310 = string ;
V_310 += sprintf ( string , L_103
#ifdef F_69
L_104
#endif
#ifdef F_39
L_105
#endif
#ifdef F_73
L_106
#endif
#if ( V_154 & V_204 )
L_107 F_98 ( V_205 ) L_108
#endif
, V_1 -> V_311 -> V_312 , V_1 -> V_313 , V_1 -> V_100 ,
V_314 , V_315 , V_316 ) ;
return string ;
}
static int F_99 ( struct V_317 * V_318 , struct V_309 * V_264 )
{
int V_319 ;
struct V_320 * V_321 ;
T_1 * V_1 ;
V_1 = ( T_1 * ) V_264 -> V_291 ;
F_100 ( V_318 , L_109
#ifdef F_69
L_104
#endif
#ifdef F_39
L_105
#endif
#ifdef F_73
L_106
#endif
#if ( V_154 & V_204 )
L_107 F_98 ( V_205 ) L_108
#endif
L_110 , V_314 , V_315 , V_316 ) ;
F_100 ( V_318 , L_111 ,
V_1 -> V_4 + V_5 , V_1 -> V_22 . V_100 ) ;
#ifdef F_23
F_100 ( V_318 , L_112 ,
V_1 -> V_4 + V_322 , V_1 -> V_22 . V_100 ) ;
#endif
F_100 ( V_318 , L_113
L_114
L_115
L_116
L_117
L_118 ,
V_1 -> V_170 . V_150 , V_1 -> V_170 . V_171 ,
V_1 -> V_170 . V_178 , V_1 -> V_170 . V_173 ,
V_1 -> V_170 . V_172 , V_1 -> V_170 . V_174 ,
V_1 -> V_170 . V_285 , V_1 -> V_170 . V_303 ,
V_1 -> V_170 . V_307 ) ;
for ( V_319 = 0 ; V_319 < 9 ; V_319 ++ ) {
unsigned int V_323 , V_93 ;
F_100 ( V_318 , L_119 , V_319 == 8 ? 'H' : ( '0' + V_319 ) ) ;
V_323 = V_1 -> V_94 [ V_319 ] - 10 ;
if ( ( signed int ) V_323 < 0 )
V_323 += V_96 ;
V_93 = V_1 -> V_97 [ V_319 ] [ V_323 ] . V_98 ;
for (; V_323 != V_1 -> V_94 [ V_319 ] ; V_323 = ( V_323 + 1 ) & ( V_96 - 1 ) ) {
if ( V_1 -> V_97 [ V_319 ] [ V_323 ] . V_98 ) {
F_100 ( V_318 , L_120 ,
V_1 -> V_97 [ V_319 ] [ V_323 ] . V_100 ? '-' : ' ' ,
V_1 -> V_97 [ V_319 ] [ V_323 ] . V_101 ,
V_1 -> V_97 [ V_319 ] [ V_323 ] . V_82 ,
( V_1 -> V_97 [ V_319 ] [ V_323 ] . V_98 - V_93 ) < 100 ?
( V_1 -> V_97 [ V_319 ] [ V_323 ] . V_98 - V_93 ) : 99 ) ;
V_93 = V_1 -> V_97 [ V_319 ] [ V_323 ] . V_98 ;
}
}
}
F_100 ( V_318 , L_121 ) ;
F_101 (scd, instance) {
F_100 ( V_318 , L_122 ) ;
F_100 ( V_318 , L_123 , V_321 -> V_102 , V_321 -> V_169 ) ;
if ( V_321 -> V_324 )
F_100 ( V_318 , L_124 ,
V_321 -> V_166 ? L_125 : L_126 ,
V_321 -> V_167 ) ;
else
F_100 ( V_318 , L_127 ) ;
if ( V_1 -> V_78 [ V_321 -> V_102 ] . V_254 & 15 )
F_100 ( V_318 , L_128 ,
V_1 -> V_78 [ V_321 -> V_102 ] . V_254 & 15 ,
F_32 ( V_1 -> V_78 [ V_321 -> V_102 ] . V_254 ) ) ;
else
F_100 ( V_318 , L_129 ) ;
}
return 0 ;
}
static int F_102 ( struct V_325 * V_326 , const struct V_327 * V_102 )
{
struct V_309 * V_1 ;
T_1 * V_328 ;
int V_288 ;
V_288 = F_103 ( V_326 ) ;
if ( V_288 )
goto V_329;
V_1 = F_104 ( & V_330 , sizeof( T_1 ) ) ;
if ( ! V_1 ) {
V_288 = - V_331 ;
goto V_332;
}
V_328 = ( T_1 * ) V_1 -> V_291 ;
V_328 -> V_4 = F_105 ( V_326 , V_333 , 0 , 0 ) ;
V_328 -> V_46 = F_105 ( V_326 , V_334 , 0 , 0 ) ;
if ( ! V_328 -> V_4 || ! V_328 -> V_46 )
goto V_335;
V_1 -> V_100 = V_326 -> V_100 ;
V_328 -> V_1 = V_1 ;
V_328 -> V_22 . V_100 = V_1 -> V_100 ;
V_326 -> V_336 = V_328 -> V_46 + V_48 ;
V_326 -> V_337 = 0x0a ;
V_288 = F_106 ( V_1 -> V_100 , F_86 , 0 , L_130 , V_328 ) ;
if ( V_288 ) {
F_8 ( V_54 L_131 ,
V_1 -> V_18 , V_328 -> V_22 . V_100 , V_288 ) ;
goto V_335;
}
memset ( & V_328 -> V_170 , 0 , sizeof ( V_328 -> V_170 ) ) ;
F_107 ( & V_328 -> V_150 . V_151 ) ;
F_107 ( & V_328 -> V_150 . V_153 ) ;
F_108 ( & V_328 -> V_22 . V_225 ) ;
F_20 ( V_328 ) ;
V_288 = F_109 ( V_1 , & V_326 -> V_338 ) ;
if ( V_288 )
goto V_339;
F_110 ( V_1 ) ;
goto V_329;
V_339:
F_111 ( V_1 -> V_100 , V_328 ) ;
F_112 ( & V_328 -> V_22 . V_225 ) ;
F_113 ( & V_328 -> V_150 . V_153 ) ;
F_113 ( & V_328 -> V_150 . V_151 ) ;
V_335:
F_114 ( V_326 , V_328 -> V_46 ) ;
F_114 ( V_326 , V_328 -> V_4 ) ;
F_115 ( V_1 ) ;
V_332:
F_116 ( V_326 ) ;
V_329:
return V_288 ;
}
static void F_117 ( struct V_325 * V_326 )
{
struct V_309 * V_1 = F_118 ( V_326 ) ;
T_1 * V_328 = ( T_1 * ) V_1 -> V_291 ;
F_119 ( V_326 , NULL ) ;
F_120 ( V_1 ) ;
F_2 ( 0x80 , V_328 -> V_46 + V_47 ) ;
F_111 ( V_1 -> V_100 , V_328 ) ;
F_112 ( & V_328 -> V_22 . V_225 ) ;
F_113 ( & V_328 -> V_150 . V_153 ) ;
F_113 ( & V_328 -> V_150 . V_151 ) ;
F_114 ( V_326 , V_328 -> V_46 ) ;
F_114 ( V_326 , V_328 -> V_4 ) ;
F_115 ( V_1 ) ;
F_116 ( V_326 ) ;
}
static int T_7 F_121 ( void )
{
return F_122 ( & V_340 ) ;
}
static void T_8 F_123 ( void )
{
F_124 ( & V_340 ) ;
}
