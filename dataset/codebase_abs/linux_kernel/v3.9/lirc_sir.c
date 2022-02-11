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
static T_2 F_11 ( struct V_8 * V_8 , char * V_15 , T_3 V_16 ,
T_4 * V_17 )
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
if ( F_15 ( ( void * ) V_15 + V_18 ,
( void * ) ( V_23 + V_11 ) ,
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
static T_2 F_19 ( struct V_8 * V_8 , const char * V_15 , T_3 V_18 ,
T_4 * V_31 )
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
int V_19 = 0 ;
T_5 V_5 = 0 ;
#ifdef F_23
if ( V_43 == V_45 )
V_5 = V_46 |
V_47 |
V_48 |
V_49 ;
else if ( V_43 == V_50 )
V_5 = V_51 ;
else if ( V_43 == V_52 )
V_5 = V_53 ;
#else
if ( V_43 == V_45 )
V_5 = V_46 | V_49 ;
else if ( V_43 == V_50 )
V_5 = V_51 ;
else if ( V_43 == V_52 )
V_5 = V_53 ;
#endif
switch ( V_43 ) {
case V_45 :
case V_50 :
case V_52 :
V_19 = F_30 ( V_5 , ( T_5 * ) V_44 ) ;
break;
case V_54 :
case V_55 :
V_19 = F_31 ( V_5 , ( T_5 * ) V_44 ) ;
break;
#ifdef F_23
case V_56 :
V_19 = F_31 ( V_5 , ( T_5 * ) V_44 ) ;
if ( V_19 )
return V_19 ;
if ( V_5 <= 0 || V_5 > 100 )
return - V_21 ;
V_57 = V_5 ;
V_58 = ( unsigned long ) V_57 * 10000 / V_59 ;
V_60 = ( unsigned long ) 1000000L / V_59 - V_58 ;
if ( V_58 >= V_61 )
V_58 -= V_61 ;
if ( V_60 >= V_61 )
V_60 -= V_61 ;
break;
case V_62 :
V_19 = F_31 ( V_5 , ( T_5 * ) V_44 ) ;
if ( V_19 )
return V_19 ;
if ( V_5 > 500000 || V_5 < 20000 )
return - V_21 ;
V_59 = V_5 ;
V_58 = ( unsigned long ) V_57 * 10000 / V_59 ;
V_60 = ( unsigned long ) 1000000L / V_59 - V_58 ;
if ( V_58 >= V_61 )
V_58 -= V_61 ;
if ( V_60 >= V_61 )
V_60 -= V_61 ;
break;
#endif
default:
V_19 = - V_63 ;
}
if ( V_19 )
return V_19 ;
if ( V_43 == V_55 ) {
if ( V_5 != V_53 )
V_19 = - V_64 ;
} else if ( V_43 == V_54 ) {
if ( V_5 != V_51 )
V_19 = - V_64 ;
}
return V_19 ;
}
static void F_32 ( int V_65 , unsigned long V_66 )
{
unsigned int V_67 ;
int V_68 ;
F_33 ( L_1 , V_65 , V_66 ) ;
V_68 = V_66 & V_69 ;
if ( V_65 ) {
if ( V_68 > V_70 / 2 )
V_68 -= V_70 / 2 ;
else
V_68 = 1 ;
V_68 |= V_71 ;
} else {
V_68 += V_70 / 2 ;
}
V_67 = ( V_12 + 1 ) & ( V_25 - 1 ) ;
if ( V_67 == V_11 ) {
F_33 ( L_2 ) ;
return;
}
V_23 [ V_12 ] = V_68 ;
V_12 = V_67 ;
F_34 ( & V_10 ) ;
}
static int F_35 ( void * V_72 )
{
return 0 ;
}
static void F_36 ( void * V_72 )
{
}
static int F_37 ( void )
{
V_73 . V_74 = & V_75 -> V_74 ;
V_73 . V_76 = F_38 ( & V_73 ) ;
if ( V_73 . V_76 < 0 ) {
F_39 ( L_3 ) ;
return - V_77 ;
}
return 0 ;
}
static void F_40 ( void )
{
F_41 ( V_73 . V_76 ) ;
}
static long F_42 ( struct V_78 * V_79 , struct V_78 * V_80 )
{
unsigned long V_81 ;
V_81 = V_80 -> V_82 - V_79 -> V_82 ;
if ( V_81 > 15 )
V_81 = 0xFFFFFF ;
else
V_81 = V_81 * 1000000 +
V_80 -> V_83 -
V_79 -> V_83 ;
return V_81 ;
}
static void F_43 ( unsigned long V_72 )
{
unsigned long V_32 ;
unsigned long V_84 ;
F_44 ( & V_85 , V_32 ) ;
if ( V_86 ) {
#ifndef F_23
F_6 ( V_87 , V_4 + V_88 ) ;
#endif
V_84 = F_42 ( & V_89 , & V_90 ) ;
F_33 ( L_4 , V_86 , V_84 ) ;
F_32 ( V_86 , V_84 ) ;
V_86 = 0 ;
V_89 = V_90 ;
}
F_45 ( & V_85 , V_32 ) ;
}
static T_6 F_46 ( int V_91 , void * V_92 )
{
unsigned char V_72 ;
struct V_78 V_93 ;
static unsigned long V_81 ;
#ifdef F_23
int V_94 ;
static int V_18 ;
V_94 = V_36 ;
while ( V_94 & V_95 ) {
int V_96 ;
if ( V_97 ) {
F_33 ( L_5 ) ;
V_96 = V_98 ;
if ( V_96 & V_99 )
F_33 ( L_6 ) ;
if ( V_96 & V_100 )
F_33 ( L_7 ) ;
if ( V_96 & V_101 )
F_33 ( L_8 ) ;
}
V_96 = V_102 ;
V_18 ++ ;
V_94 = V_36 ;
}
if ( V_94 & ( V_103 | V_37 ) ) {
F_47 ( & V_93 ) ;
V_81 = F_42 ( & V_89 , & V_93 ) ;
do {
V_72 = V_102 ;
F_33 ( L_9 , V_18 , ( unsigned int ) V_72 ) ;
V_18 ++ ;
} while ( V_94 & V_37 &&
V_98 & V_104 );
if ( V_94 & V_37 ) {
F_32 ( 0 , V_81 - V_18 * V_70 ) ;
F_32 ( 1 , V_18 * V_70 ) ;
V_18 = 0 ;
V_89 = V_93 ;
}
}
if ( V_94 & V_105 )
F_39 ( L_10 ) ;
V_94 &= ( V_37 | V_38 | V_39 ) ;
if ( V_94 )
V_36 = V_94 ;
#else
unsigned long V_106 ;
unsigned long V_32 ;
int V_107 , V_108 ;
while ( ( V_107 = F_4 ( V_4 + V_109 ) & V_110 ) ) {
switch ( V_107 & V_110 ) {
case V_111 :
( void ) F_4 ( V_4 + V_112 ) ;
break;
case V_113 :
( void ) F_4 ( V_4 + V_114 ) ;
break;
case V_115 :
#if 0
if (lsr & UART_LSR_THRE)
outb(data, io + UART_TX)
#endif
break;
case V_116 :
F_44 ( & V_85 , V_32 ) ;
do {
F_48 ( & V_117 ) ;
V_72 = F_4 ( V_4 + V_118 ) ;
F_47 ( & V_93 ) ;
V_81 = F_42 ( & V_89 , & V_93 ) ;
V_106 = F_42 ( & V_90 , & V_93 ) ;
F_33 ( L_11 , V_106 , ( int ) V_72 ) ;
if ( V_106 > V_70 * V_119 ) {
if ( V_86 ) {
F_33 ( L_12 ) ;
F_32 ( V_86 ,
V_81 -
V_106 ) ;
V_86 = 0 ;
V_89 . V_82 =
V_90 . V_82 ;
V_89 . V_83 =
V_90 . V_83 ;
V_81 = V_106 ;
}
}
V_72 = 1 ;
if ( V_72 ^ V_86 ) {
F_32 ( V_86 ,
V_81 - V_70 ) ;
V_86 = V_72 ;
V_89 = V_93 ;
if ( V_89 . V_83 >= V_70 ) {
V_89 . V_83 -= V_70 ;
} else {
V_89 . V_82 -- ;
V_89 . V_83 += 1000000 -
V_70 ;
}
}
V_90 = V_93 ;
if ( V_72 ) {
V_117 . V_120 = V_121 +
V_122 ;
F_49 ( & V_117 ) ;
}
V_108 = F_4 ( V_4 + V_114 ) ;
} while ( V_108 & V_123 );
F_45 ( & V_85 , V_32 ) ;
break;
default:
break;
}
}
#endif
return F_50 ( V_124 ) ;
}
static void F_25 ( unsigned long V_125 )
{
unsigned long V_126 , V_127 ;
int V_65 ;
if ( V_125 == 0 )
return;
for ( V_126 = V_65 = 0 ; V_126 < V_125 ; V_126 += V_127 , V_65 = ! V_65 ) {
if ( V_65 ) {
F_2 () ;
V_127 = V_60 ;
} else {
F_1 () ;
V_127 = V_58 ;
}
F_7 ( V_127 ) ;
}
F_2 () ;
}
static void F_26 ( unsigned long V_125 )
{
if ( V_125 == 0 )
return;
F_2 () ;
F_7 ( V_125 ) ;
}
static void F_26 ( unsigned long V_128 )
{
F_7 ( V_128 ) ;
}
static void F_25 ( unsigned long V_128 )
{
long V_129 = V_128 / V_70 ;
if ( V_129 == 0 )
V_129 ++ ;
while ( V_129 -- ) {
F_6 ( V_130 , V_4 + V_131 ) ;
while ( ! ( F_4 ( V_4 + V_114 ) & V_132 ) )
;
}
}
static int F_51 ( int V_133 )
{
if ( V_133 ) {
F_52 ( V_134 ,
V_135 ) ;
F_53 ( V_134 , V_136 ) ;
F_8 ( 100 ) ;
} else {
F_52 ( V_134 ,
V_135 ) ;
F_53 ( V_134 , V_137 ) ;
}
return 0 ;
}
static int F_54 ( void )
{
unsigned long V_32 ;
F_44 ( & V_138 , V_32 ) ;
#ifdef F_23
#ifdef F_55
if ( F_56 () ) {
F_57 ( L_13 ) ;
F_58 ( V_139 ) ;
}
#endif
#ifdef F_59
F_51 ( 3 ) ;
#endif
V_140 . V_141 = V_142 ;
V_140 . V_143 = V_144 ;
V_140 . V_145 = V_146 ;
V_140 . V_147 = V_148 ;
V_140 . V_149 = V_35 ;
V_140 . V_150 = V_151 ;
V_140 . V_152 = V_102 ;
V_140 . V_153 = V_36 ;
V_140 . V_154 = V_98 ;
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
#elif F_60 ( V_162 )
F_5 ( V_88 ,
V_87 |
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
F_5 ( V_131 , V_178 | V_179 ) ;
F_8 ( 1500 ) ;
F_5 ( V_174 , V_175 | V_176 | V_177 ) ;
F_8 ( 50 ) ;
F_8 ( 1500 ) ;
F_57 ( L_14 , F_3 ( V_118 ) ) ;
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
F_6 ( V_182 , V_4 + V_88 ) ;
F_6 ( V_171 , V_4 + V_167 ) ;
F_6 ( V_176 | V_175 | V_177 , V_4 + V_174 ) ;
#ifdef F_61
F_62 () ;
#elif F_60 ( V_183 )
F_63 () ;
#endif
#endif
F_45 ( & V_138 , V_32 ) ;
return 0 ;
}
static void F_64 ( void )
{
unsigned long V_32 ;
F_44 ( & V_138 , V_32 ) ;
#ifdef F_23
V_35 = 0 ;
V_144 = V_140 . V_143 ;
V_146 = V_140 . V_145 ;
V_148 = V_140 . V_147 ;
V_151 = V_140 . V_150 ;
V_35 = V_140 . V_149 ;
V_142 = V_140 . V_141 ;
#ifdef F_55
if ( F_56 () )
F_65 ( V_139 ) ;
#endif
#ifdef F_59
F_51 ( 0 ) ;
#endif
#else
F_6 ( 0 , V_4 + V_167 ) ;
#endif
F_45 ( & V_138 , V_32 ) ;
}
static int F_66 ( void )
{
int V_19 ;
#ifndef F_23
if ( F_67 ( V_4 , 8 , V_184 ) == NULL ) {
F_39 ( L_15 , V_4 ) ;
return - V_185 ;
}
#endif
V_19 = F_68 ( V_91 , F_46 , 0 ,
V_184 , NULL ) ;
if ( V_19 < 0 ) {
# ifndef F_23
F_69 ( V_4 , 8 ) ;
# endif
F_39 ( L_16 , V_91 ) ;
return V_19 ;
}
#ifndef F_23
F_57 ( L_17 , V_4 , V_91 ) ;
#endif
F_70 ( & V_117 ) ;
V_117 . V_186 = F_43 ;
V_117 . V_72 = 0xabadcafe ;
return 0 ;
}
static void F_71 ( void )
{
F_72 ( V_91 , NULL ) ;
F_73 ( & V_117 ) ;
#ifndef F_23
F_69 ( V_4 , 8 ) ;
#endif
}
static void F_62 ( void )
{
int V_33 ;
T_7 V_187 [] = {
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
F_5 ( V_131 , V_187 [ V_33 ] ) ;
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
void F_63 ( void )
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
static int F_74 ( void )
{
int V_19 ;
F_75 ( & V_10 ) ;
V_19 = F_66 () ;
if ( V_19 < 0 )
return V_19 ;
F_54 () ;
F_57 ( L_18 ) ;
return 0 ;
}
static int F_76 ( struct V_216 * V_74 )
{
return 0 ;
}
static int F_77 ( struct V_216 * V_74 )
{
return 0 ;
}
static int T_8 F_78 ( void )
{
int V_19 ;
V_19 = F_79 ( & V_217 ) ;
if ( V_19 ) {
F_39 ( L_19 ) ;
return - V_218 ;
}
V_75 = F_80 ( L_20 , 0 ) ;
if ( ! V_75 ) {
F_39 ( L_21 ) ;
V_19 = - V_219 ;
goto V_220;
}
V_19 = F_81 ( V_75 ) ;
if ( V_19 ) {
F_39 ( L_22 ) ;
V_19 = - V_218 ;
goto V_221;
}
V_19 = F_37 () ;
if ( V_19 < 0 )
goto V_222;
V_19 = F_74 () ;
if ( V_19 ) {
F_40 () ;
goto V_222;
}
return 0 ;
V_222:
F_82 ( V_75 ) ;
V_221:
F_83 ( V_75 ) ;
V_220:
F_84 ( & V_217 ) ;
return V_19 ;
}
static void T_9 F_85 ( void )
{
F_64 () ;
F_40 () ;
F_71 () ;
F_86 ( V_75 ) ;
F_84 ( & V_217 ) ;
F_57 ( L_23 ) ;
}
