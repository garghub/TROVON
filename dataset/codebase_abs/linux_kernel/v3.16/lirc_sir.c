static void F_1 ( void )
{
V_1 |= V_2 ;
}
static void F_2 ( void )
{
V_1 &= ~ V_2 ;
}
static inline unsigned int F_3 ( int V_3 )
{
return F_4 ( V_4 + V_3 ) ;
}
static inline void F_5 ( int V_3 , int V_5 )
{
F_6 ( V_5 , V_4 + V_3 ) ;
}
static void F_7 ( unsigned long V_6 )
{
while ( V_6 > V_7 ) {
F_8 ( V_7 ) ;
V_6 -= V_7 ;
}
F_8 ( V_6 ) ;
}
static unsigned int F_9 ( struct V_8 * V_8 , T_1 * V_9 )
{
F_10 ( V_8 , & V_10 , V_9 ) ;
if ( V_11 != V_12 )
return V_13 | V_14 ;
return 0 ;
}
static T_2 F_11 ( struct V_8 * V_8 , char T_3 * V_15 , T_4 V_16 ,
T_5 * V_17 )
{
int V_18 = 0 ;
int V_19 = 0 ;
F_12 ( V_9 , V_20 ) ;
if ( V_16 % sizeof( int ) )
return - V_21 ;
F_13 ( & V_10 , & V_9 ) ;
F_14 ( V_22 ) ;
while ( V_18 < V_16 ) {
if ( V_11 != V_12 ) {
if ( F_15 ( V_15 + V_18 ,
V_23 + V_11 ,
sizeof( int ) ) ) {
V_19 = - V_24 ;
break;
}
V_11 = ( V_11 + 1 ) & ( V_25 - 1 ) ;
V_18 += sizeof( int ) ;
} else {
if ( V_8 -> V_26 & V_27 ) {
V_19 = - V_28 ;
break;
}
if ( F_16 ( V_20 ) ) {
V_19 = - V_29 ;
break;
}
F_17 () ;
F_14 ( V_22 ) ;
}
}
F_18 ( & V_10 , & V_9 ) ;
F_14 ( V_30 ) ;
return V_18 ? V_18 : V_19 ;
}
static T_2 F_19 ( struct V_8 * V_8 , const char T_3 * V_15 , T_4 V_18 ,
T_5 * V_31 )
{
unsigned long V_32 ;
int V_33 , V_16 ;
int * V_34 ;
V_16 = V_18 / sizeof( int ) ;
if ( V_18 % sizeof( int ) || V_16 % 2 == 0 )
return - V_21 ;
V_34 = F_20 ( V_15 , V_18 ) ;
if ( F_21 ( V_34 ) )
return F_22 ( V_34 ) ;
V_33 = 0 ;
#ifdef F_23
V_35 = 0 ;
#endif
F_24 ( V_32 ) ;
while ( 1 ) {
if ( V_33 >= V_16 )
break;
if ( V_34 [ V_33 ] )
F_25 ( V_34 [ V_33 ] ) ;
V_33 ++ ;
if ( V_33 >= V_16 )
break;
if ( V_34 [ V_33 ] )
F_26 ( V_34 [ V_33 ] ) ;
V_33 ++ ;
}
F_27 ( V_32 ) ;
#ifdef F_23
F_2 () ;
F_8 ( 1000 ) ;
V_35 = 0 ;
V_36 &= ( V_37 | V_38 | V_39 ) ;
V_35 = V_40 | V_41 ;
#endif
F_28 ( V_34 ) ;
return V_16 ;
}
static long F_29 ( struct V_8 * V_42 , unsigned int V_43 , unsigned long V_44 )
{
T_6 T_3 * V_45 = ( T_6 T_3 * ) V_44 ;
int V_19 = 0 ;
T_6 V_5 = 0 ;
#ifdef F_23
if ( V_43 == V_46 )
V_5 = V_47 |
V_48 |
V_49 |
V_50 ;
else if ( V_43 == V_51 )
V_5 = V_52 ;
else if ( V_43 == V_53 )
V_5 = V_54 ;
#else
if ( V_43 == V_46 )
V_5 = V_47 | V_50 ;
else if ( V_43 == V_51 )
V_5 = V_52 ;
else if ( V_43 == V_53 )
V_5 = V_54 ;
#endif
switch ( V_43 ) {
case V_46 :
case V_51 :
case V_53 :
V_19 = F_30 ( V_5 , V_45 ) ;
break;
case V_55 :
case V_56 :
V_19 = F_31 ( V_5 , V_45 ) ;
break;
#ifdef F_23
case V_57 :
V_19 = F_31 ( V_5 , V_45 ) ;
if ( V_19 )
return V_19 ;
if ( V_5 <= 0 || V_5 > 100 )
return - V_21 ;
V_58 = V_5 ;
V_59 = ( unsigned long ) V_58 * 10000 / V_60 ;
V_61 = ( unsigned long ) 1000000L / V_60 - V_59 ;
if ( V_59 >= V_62 )
V_59 -= V_62 ;
if ( V_61 >= V_62 )
V_61 -= V_62 ;
break;
case V_63 :
V_19 = F_31 ( V_5 , V_45 ) ;
if ( V_19 )
return V_19 ;
if ( V_5 > 500000 || V_5 < 20000 )
return - V_21 ;
V_60 = V_5 ;
V_59 = ( unsigned long ) V_58 * 10000 / V_60 ;
V_61 = ( unsigned long ) 1000000L / V_60 - V_59 ;
if ( V_59 >= V_62 )
V_59 -= V_62 ;
if ( V_61 >= V_62 )
V_61 -= V_62 ;
break;
#endif
default:
V_19 = - V_64 ;
}
if ( V_19 )
return V_19 ;
if ( V_43 == V_56 ) {
if ( V_5 != V_54 )
V_19 = - V_65 ;
} else if ( V_43 == V_55 ) {
if ( V_5 != V_52 )
V_19 = - V_65 ;
}
return V_19 ;
}
static void F_32 ( int V_66 , unsigned long V_67 )
{
unsigned int V_68 ;
int V_69 ;
F_33 ( L_1 , V_66 , V_67 ) ;
V_69 = V_67 & V_70 ;
if ( V_66 ) {
if ( V_69 > V_71 / 2 )
V_69 -= V_71 / 2 ;
else
V_69 = 1 ;
V_69 |= V_72 ;
} else {
V_69 += V_71 / 2 ;
}
V_68 = ( V_12 + 1 ) & ( V_25 - 1 ) ;
if ( V_68 == V_11 ) {
F_33 ( L_2 ) ;
return;
}
V_23 [ V_12 ] = V_69 ;
V_12 = V_68 ;
F_34 ( & V_10 ) ;
}
static int F_35 ( void * V_73 )
{
return 0 ;
}
static void F_36 ( void * V_73 )
{
}
static int F_37 ( void )
{
V_74 . V_75 = & V_76 -> V_75 ;
V_74 . V_77 = F_38 ( & V_74 ) ;
if ( V_74 . V_77 < 0 ) {
F_39 ( L_3 ) ;
return - V_78 ;
}
return 0 ;
}
static void F_40 ( void )
{
F_41 ( V_74 . V_77 ) ;
}
static long F_42 ( struct V_79 * V_80 , struct V_79 * V_81 )
{
unsigned long V_82 ;
V_82 = V_81 -> V_83 - V_80 -> V_83 ;
if ( V_82 > 15 )
V_82 = 0xFFFFFF ;
else
V_82 = V_82 * 1000000 +
V_81 -> V_84 -
V_80 -> V_84 ;
return V_82 ;
}
static void F_43 ( unsigned long V_73 )
{
unsigned long V_32 ;
unsigned long V_85 ;
F_44 ( & V_86 , V_32 ) ;
if ( V_87 ) {
#ifndef F_23
F_6 ( V_88 , V_4 + V_89 ) ;
#endif
V_85 = F_42 ( & V_90 , & V_91 ) ;
F_33 ( L_4 , V_87 , V_85 ) ;
F_32 ( V_87 , V_85 ) ;
V_87 = 0 ;
V_90 = V_91 ;
}
F_45 ( & V_86 , V_32 ) ;
}
static T_7 F_46 ( int V_92 , void * V_93 )
{
unsigned char V_73 ;
struct V_79 V_94 ;
static unsigned long V_82 ;
#ifdef F_23
int V_95 ;
static int V_18 ;
V_95 = V_36 ;
while ( V_95 & V_96 ) {
int V_97 ;
if ( V_98 ) {
F_33 ( L_5 ) ;
V_97 = V_99 ;
if ( V_97 & V_100 )
F_33 ( L_6 ) ;
if ( V_97 & V_101 )
F_33 ( L_7 ) ;
if ( V_97 & V_102 )
F_33 ( L_8 ) ;
}
V_97 = V_103 ;
V_18 ++ ;
V_95 = V_36 ;
}
if ( V_95 & ( V_104 | V_37 ) ) {
F_47 ( & V_94 ) ;
V_82 = F_42 ( & V_90 , & V_94 ) ;
do {
V_73 = V_103 ;
F_33 ( L_9 , V_18 , ( unsigned int ) V_73 ) ;
V_18 ++ ;
} while ( V_95 & V_37 &&
V_99 & V_105 );
if ( V_95 & V_37 ) {
F_32 ( 0 , V_82 - V_18 * V_71 ) ;
F_32 ( 1 , V_18 * V_71 ) ;
V_18 = 0 ;
V_90 = V_94 ;
}
}
if ( V_95 & V_106 )
F_39 ( L_10 ) ;
V_95 &= ( V_37 | V_38 | V_39 ) ;
if ( V_95 )
V_36 = V_95 ;
#else
unsigned long V_107 ;
unsigned long V_32 ;
int V_108 , V_109 ;
while ( ( V_108 = F_4 ( V_4 + V_110 ) & V_111 ) ) {
switch ( V_108 & V_111 ) {
case V_112 :
( void ) F_4 ( V_4 + V_113 ) ;
break;
case V_114 :
( void ) F_4 ( V_4 + V_115 ) ;
break;
case V_116 :
#if 0
if (lsr & UART_LSR_THRE)
outb(data, io + UART_TX)
#endif
break;
case V_117 :
F_44 ( & V_86 , V_32 ) ;
do {
F_48 ( & V_118 ) ;
V_73 = F_4 ( V_4 + V_119 ) ;
F_47 ( & V_94 ) ;
V_82 = F_42 ( & V_90 , & V_94 ) ;
V_107 = F_42 ( & V_91 , & V_94 ) ;
F_33 ( L_11 , V_107 , ( int ) V_73 ) ;
if ( V_107 > V_71 * V_120 ) {
if ( V_87 ) {
F_33 ( L_12 ) ;
F_32 ( V_87 ,
V_82 -
V_107 ) ;
V_87 = 0 ;
V_90 . V_83 =
V_91 . V_83 ;
V_90 . V_84 =
V_91 . V_84 ;
V_82 = V_107 ;
}
}
V_73 = 1 ;
if ( V_73 ^ V_87 ) {
F_32 ( V_87 ,
V_82 - V_71 ) ;
V_87 = V_73 ;
V_90 = V_94 ;
if ( V_90 . V_84 >= V_71 ) {
V_90 . V_84 -= V_71 ;
} else {
V_90 . V_83 -- ;
V_90 . V_84 += 1000000 -
V_71 ;
}
}
V_91 = V_94 ;
if ( V_73 ) {
V_118 . V_121 = V_122 +
V_123 ;
F_49 ( & V_118 ) ;
}
V_109 = F_4 ( V_4 + V_115 ) ;
} while ( V_109 & V_124 );
F_45 ( & V_86 , V_32 ) ;
break;
default:
break;
}
}
#endif
return F_50 ( V_125 ) ;
}
static void F_25 ( unsigned long V_126 )
{
unsigned long V_127 , V_128 ;
int V_66 ;
if ( V_126 == 0 )
return;
for ( V_127 = V_66 = 0 ; V_127 < V_126 ; V_127 += V_128 , V_66 = ! V_66 ) {
if ( V_66 ) {
F_2 () ;
V_128 = V_61 ;
} else {
F_1 () ;
V_128 = V_59 ;
}
F_7 ( V_128 ) ;
}
F_2 () ;
}
static void F_26 ( unsigned long V_126 )
{
if ( V_126 == 0 )
return;
F_2 () ;
F_7 ( V_126 ) ;
}
static void F_26 ( unsigned long V_129 )
{
F_7 ( V_129 ) ;
}
static void F_25 ( unsigned long V_129 )
{
long V_130 = V_129 / V_71 ;
if ( V_130 == 0 )
V_130 ++ ;
while ( V_130 -- ) {
F_6 ( V_131 , V_4 + V_132 ) ;
while ( ! ( F_4 ( V_4 + V_115 ) & V_133 ) )
;
}
}
static int F_51 ( int V_134 )
{
if ( V_134 ) {
F_52 ( V_135 ,
V_136 ) ;
F_53 ( V_135 , V_137 ) ;
F_8 ( 100 ) ;
} else {
F_52 ( V_135 ,
V_136 ) ;
F_53 ( V_135 , V_138 ) ;
}
return 0 ;
}
static int F_54 ( void )
{
unsigned long V_32 ;
F_44 ( & V_139 , V_32 ) ;
#ifdef F_23
#ifdef F_55
F_51 ( 3 ) ;
#endif
V_140 . V_141 = V_142 ;
V_140 . V_143 = V_144 ;
V_140 . V_145 = V_146 ;
V_140 . V_147 = V_148 ;
V_140 . V_149 = V_35 ;
V_140 . V_150 = V_151 ;
V_140 . V_152 = V_103 ;
V_140 . V_153 = V_36 ;
V_140 . V_154 = V_99 ;
V_155 |= V_2 ;
V_156 |= V_2 ;
F_2 () ;
V_35 = 0 ;
V_142 = V_140 . V_141 & ( ~ V_157 ) ;
V_36 &= ( V_37 | V_38 | V_39 ) ;
V_144 = V_158 | V_159 ;
V_146 = 0 ;
V_148 = 1 ;
V_151 = V_160 | V_161 ;
V_35 = V_40 | V_41 ;
V_36 &= ( V_37 | V_38 | V_39 ) ;
#elif F_56 ( V_162 )
F_5 ( V_89 ,
V_88 |
V_163 |
V_164 ) ;
F_5 ( V_165 , F_3 ( V_165 ) & ( ~ V_166 ) ) ;
F_5 ( V_167 , F_3 ( V_167 ) &
( ~ ( V_168 | V_169 | V_170 | V_171 ) ) ) ;
F_5 ( V_165 , F_3 ( V_165 ) | V_166 ) ;
F_5 ( V_172 , 0 ) ;
F_5 ( V_173 , 12 ) ;
F_5 ( V_165 , F_3 ( V_165 ) & ( ~ V_166 ) ) ;
F_5 ( V_174 , V_175 | V_176 | V_177 ) ;
F_7 ( 50 * 1000 ) ;
F_5 ( V_174 , V_175 | V_177 ) ;
F_8 ( 1 * 1000 ) ;
F_5 ( V_174 , V_175 | V_176 | V_177 ) ;
F_8 ( 100 ) ;
F_5 ( V_174 , V_176 | V_177 ) ;
F_8 ( 7 ) ;
F_5 ( V_132 , V_178 | V_179 ) ;
F_8 ( 1500 ) ;
F_5 ( V_174 , V_175 | V_176 | V_177 ) ;
F_8 ( 50 ) ;
F_8 ( 1500 ) ;
F_57 ( L_13 , F_3 ( V_119 ) ) ;
F_5 ( V_165 , F_3 ( V_165 ) | V_166 ) ;
F_5 ( V_172 , 0 ) ;
F_5 ( V_173 , 1 ) ;
F_5 ( V_165 , V_180 ) ;
F_5 ( V_167 , F_3 ( V_167 ) | V_171 ) ;
#else
F_6 ( 0 , V_4 + V_174 ) ;
F_6 ( 0 , V_4 + V_167 ) ;
F_6 ( V_166 | V_181 , V_4 + V_165 ) ;
F_6 ( 1 , V_4 + V_173 ) ; F_6 ( 0 , V_4 + V_172 ) ;
F_6 ( V_181 , V_4 + V_165 ) ;
F_6 ( V_182 , V_4 + V_89 ) ;
F_6 ( V_171 , V_4 + V_167 ) ;
F_6 ( V_176 | V_175 | V_177 , V_4 + V_174 ) ;
#ifdef F_58
F_59 () ;
#elif F_56 ( V_183 )
F_60 () ;
#endif
#endif
F_45 ( & V_139 , V_32 ) ;
return 0 ;
}
static void F_61 ( void )
{
unsigned long V_32 ;
F_44 ( & V_139 , V_32 ) ;
#ifdef F_23
V_35 = 0 ;
V_144 = V_140 . V_143 ;
V_146 = V_140 . V_145 ;
V_148 = V_140 . V_147 ;
V_151 = V_140 . V_150 ;
V_35 = V_140 . V_149 ;
V_142 = V_140 . V_141 ;
#ifdef F_55
F_51 ( 0 ) ;
#endif
#else
F_6 ( 0 , V_4 + V_167 ) ;
#endif
F_45 ( & V_139 , V_32 ) ;
}
static int F_62 ( void )
{
int V_19 ;
#ifndef F_23
if ( F_63 ( V_4 , 8 , V_184 ) == NULL ) {
F_39 ( L_14 , V_4 ) ;
return - V_185 ;
}
#endif
V_19 = F_64 ( V_92 , F_46 , 0 ,
V_184 , NULL ) ;
if ( V_19 < 0 ) {
# ifndef F_23
F_65 ( V_4 , 8 ) ;
# endif
F_39 ( L_15 , V_92 ) ;
return V_19 ;
}
#ifndef F_23
F_57 ( L_16 , V_4 , V_92 ) ;
#endif
F_66 ( & V_118 ) ;
V_118 . V_186 = F_43 ;
V_118 . V_73 = 0xabadcafe ;
return 0 ;
}
static void F_67 ( void )
{
F_68 ( V_92 , NULL ) ;
F_69 ( & V_118 ) ;
#ifndef F_23
F_65 ( V_4 , 8 ) ;
#endif
}
static void F_59 ( void )
{
int V_33 ;
T_8 V_187 [] = {
V_188 ,
V_189 | V_190 ,
V_191 | V_192 | V_193 ,
V_189 ,
V_194 | V_195 ,
V_196 | V_197 | V_198 ,
V_199 | V_200 ,
V_201 | V_202 | V_203 | V_204 ,
V_205 | V_206 ,
V_207 | V_208 | V_209 ,
V_210 | ( V_211 & 0x0f ) ,
V_212 | ( ( V_211 >> 4 ) & 0x0f ) ,
V_213 | V_214 | V_215
} ;
F_5 ( V_165 , V_166 | V_180 ) ;
F_5 ( V_172 , 0 ) ;
F_5 ( V_173 , 12 ) ;
F_5 ( V_165 , V_180 ) ;
F_5 ( V_174 , V_175 | V_176 | V_177 ) ;
for ( V_33 = 0 ; V_33 < 50 ; V_33 ++ )
F_7 ( 1000 ) ;
F_5 ( V_174 , V_176 | V_177 ) ;
for ( V_33 = 0 ; V_33 < 25 ; V_33 ++ )
F_8 ( 1000 ) ;
F_5 ( V_174 , V_175 | V_176 | V_177 ) ;
F_8 ( 100 ) ;
F_5 ( V_174 , V_175 | V_177 ) ;
F_8 ( 7 ) ;
for ( V_33 = 0 ; V_33 < sizeof( V_187 ) ; V_33 ++ ) {
F_5 ( V_132 , V_187 [ V_33 ] ) ;
F_8 ( 1500 ) ;
}
F_5 ( V_174 , V_175 | V_176 | V_177 ) ;
F_8 ( 50 ) ;
F_8 ( 1500 ) ;
F_5 ( V_165 , F_3 ( V_165 ) | V_166 ) ;
F_5 ( V_165 , V_166 | V_181 ) ;
F_5 ( V_172 , 0 ) ;
F_5 ( V_173 , 1 ) ;
F_5 ( V_165 , F_3 ( V_165 ) & ( ~ V_166 ) ) ;
F_5 ( V_165 , V_181 ) ;
F_5 ( V_167 , F_3 ( V_167 ) | V_171 ) ;
}
void F_60 ( void )
{
int V_33 ;
F_5 ( V_165 , V_166 | V_181 ) ;
F_5 ( V_172 , 0 ) ;
F_5 ( V_173 , 12 ) ;
F_5 ( V_165 , V_181 ) ;
F_5 ( V_174 , V_175 | V_177 ) ;
F_8 ( 10 ) ;
F_5 ( V_174 , V_176 | V_175 | V_177 ) ;
for ( V_33 = 0 ; V_33 < 3 ; V_33 ++ ) {
F_8 ( 10 ) ;
F_5 ( V_174 , V_176 | V_177 ) ;
F_8 ( 10 ) ;
F_5 ( V_174 , V_175 | V_176 | V_177 ) ;
}
F_8 ( 1500 ) ;
F_5 ( V_165 , V_166 | V_181 ) ;
F_5 ( V_172 , 0 ) ;
F_5 ( V_173 , 1 ) ;
F_5 ( V_165 , V_181 ) ;
F_5 ( V_167 , V_171 ) ;
}
static int F_70 ( void )
{
int V_19 ;
F_71 ( & V_10 ) ;
V_19 = F_62 () ;
if ( V_19 < 0 )
return V_19 ;
F_54 () ;
F_57 ( L_17 ) ;
return 0 ;
}
static int F_72 ( struct V_216 * V_75 )
{
return 0 ;
}
static int F_73 ( struct V_216 * V_75 )
{
return 0 ;
}
static int T_9 F_74 ( void )
{
int V_19 ;
V_19 = F_75 ( & V_217 ) ;
if ( V_19 ) {
F_39 ( L_18 ) ;
return - V_218 ;
}
V_76 = F_76 ( L_19 , 0 ) ;
if ( ! V_76 ) {
F_39 ( L_20 ) ;
V_19 = - V_219 ;
goto V_220;
}
V_19 = F_77 ( V_76 ) ;
if ( V_19 ) {
F_39 ( L_21 ) ;
V_19 = - V_218 ;
goto V_221;
}
V_19 = F_37 () ;
if ( V_19 < 0 )
goto V_222;
V_19 = F_70 () ;
if ( V_19 ) {
F_40 () ;
goto V_222;
}
return 0 ;
V_222:
F_78 ( V_76 ) ;
V_221:
F_79 ( V_76 ) ;
V_220:
F_80 ( & V_217 ) ;
return V_19 ;
}
static void T_10 F_81 ( void )
{
F_61 () ;
F_40 () ;
F_67 () ;
F_82 ( V_76 ) ;
F_80 ( & V_217 ) ;
F_57 ( L_22 ) ;
}
