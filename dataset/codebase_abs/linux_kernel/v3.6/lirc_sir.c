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
F_39 (KERN_ERR LIRC_DRIVER_NAME L_3 ) ;
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
F_39 ( V_106 L_10 ) ;
V_94 &= ( V_37 | V_38 | V_39 ) ;
if ( V_94 )
V_36 = V_94 ;
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
F_44 ( & V_85 , V_32 ) ;
do {
F_48 ( & V_118 ) ;
V_72 = F_4 ( V_4 + V_119 ) ;
F_47 ( & V_93 ) ;
V_81 = F_42 ( & V_89 , & V_93 ) ;
V_107 = F_42 ( & V_90 , & V_93 ) ;
F_33 ( L_11 , V_107 , ( int ) V_72 ) ;
if ( V_107 > V_70 * V_120 ) {
if ( V_86 ) {
F_33 ( L_12 ) ;
F_32 ( V_86 ,
V_81 -
V_107 ) ;
V_86 = 0 ;
V_89 . V_82 =
V_90 . V_82 ;
V_89 . V_83 =
V_90 . V_83 ;
V_81 = V_107 ;
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
V_118 . V_121 = V_122 +
V_123 ;
F_49 ( & V_118 ) ;
}
V_109 = F_4 ( V_4 + V_115 ) ;
} while ( V_109 & V_124 );
F_45 ( & V_85 , V_32 ) ;
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
int V_65 ;
if ( V_126 == 0 )
return;
for ( V_127 = V_65 = 0 ; V_127 < V_126 ; V_127 += V_128 , V_65 = ! V_65 ) {
if ( V_65 ) {
F_2 () ;
V_128 = V_60 ;
} else {
F_1 () ;
V_128 = V_58 ;
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
long V_130 = V_129 / V_70 ;
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
if ( F_56 () ) {
F_39 ( V_140 L_13 ) ;
F_57 ( V_141 ) ;
}
#endif
#ifdef F_58
F_51 ( 3 ) ;
#endif
V_142 . V_143 = V_144 ;
V_142 . V_145 = V_146 ;
V_142 . V_147 = V_148 ;
V_142 . V_149 = V_150 ;
V_142 . V_151 = V_35 ;
V_142 . V_152 = V_153 ;
V_142 . V_154 = V_102 ;
V_142 . V_155 = V_36 ;
V_142 . V_156 = V_98 ;
V_157 |= V_2 ;
V_158 |= V_2 ;
F_2 () ;
V_35 = 0 ;
V_144 = V_142 . V_143 & ( ~ V_159 ) ;
V_36 &= ( V_37 | V_38 | V_39 ) ;
V_146 = V_160 | V_161 ;
V_148 = 0 ;
V_150 = 1 ;
V_153 = V_162 | V_163 ;
V_35 = V_40 | V_41 ;
V_36 &= ( V_37 | V_38 | V_39 ) ;
#elif F_59 ( V_164 )
F_5 ( V_88 ,
V_87 |
V_165 |
V_166 ) ;
F_5 ( V_167 , F_3 ( V_167 ) & ( ~ V_168 ) ) ;
F_5 ( V_169 , F_3 ( V_169 ) &
( ~ ( V_170 | V_171 | V_172 | V_173 ) ) ) ;
F_5 ( V_167 , F_3 ( V_167 ) | V_168 ) ;
F_5 ( V_174 , 0 ) ;
F_5 ( V_175 , 12 ) ;
F_5 ( V_167 , F_3 ( V_167 ) & ( ~ V_168 ) ) ;
F_5 ( V_176 , V_177 | V_178 | V_179 ) ;
F_7 ( 50 * 1000 ) ;
F_5 ( V_176 , V_177 | V_179 ) ;
F_8 ( 1 * 1000 ) ;
F_5 ( V_176 , V_177 | V_178 | V_179 ) ;
F_8 ( 100 ) ;
F_5 ( V_176 , V_178 | V_179 ) ;
F_8 ( 7 ) ;
F_5 ( V_132 , V_180 | V_181 ) ;
F_8 ( 1500 ) ;
F_5 ( V_176 , V_177 | V_178 | V_179 ) ;
F_8 ( 50 ) ;
F_8 ( 1500 ) ;
F_39 (KERN_INFO LIRC_DRIVER_NAME
L_14 , sinp(UART_RX)) ;
F_5 ( V_167 , F_3 ( V_167 ) | V_168 ) ;
F_5 ( V_174 , 0 ) ;
F_5 ( V_175 , 1 ) ;
F_5 ( V_167 , V_182 ) ;
F_5 ( V_169 , F_3 ( V_169 ) | V_173 ) ;
#else
F_6 ( 0 , V_4 + V_176 ) ;
F_6 ( 0 , V_4 + V_169 ) ;
F_6 ( V_168 | V_183 , V_4 + V_167 ) ;
F_6 ( 1 , V_4 + V_175 ) ; F_6 ( 0 , V_4 + V_174 ) ;
F_6 ( V_183 , V_4 + V_167 ) ;
F_6 ( V_184 , V_4 + V_88 ) ;
F_6 ( V_173 , V_4 + V_169 ) ;
F_6 ( V_178 | V_177 | V_179 , V_4 + V_176 ) ;
#ifdef F_60
F_61 () ;
#elif F_59 ( V_185 )
F_62 () ;
#endif
#endif
F_45 ( & V_139 , V_32 ) ;
return 0 ;
}
static void F_63 ( void )
{
unsigned long V_32 ;
F_44 ( & V_139 , V_32 ) ;
#ifdef F_23
V_35 = 0 ;
V_146 = V_142 . V_145 ;
V_148 = V_142 . V_147 ;
V_150 = V_142 . V_149 ;
V_153 = V_142 . V_152 ;
V_35 = V_142 . V_151 ;
V_144 = V_142 . V_143 ;
#ifdef F_55
if ( F_56 () )
F_64 ( V_141 ) ;
#endif
#ifdef F_58
F_51 ( 0 ) ;
#endif
#else
F_6 ( 0 , V_4 + V_169 ) ;
#endif
F_45 ( & V_139 , V_32 ) ;
}
static int F_65 ( void )
{
int V_19 ;
#ifndef F_23
if ( F_66 ( V_4 , 8 , V_186 ) == NULL ) {
F_39 (KERN_ERR LIRC_DRIVER_NAME
L_15 , io) ;
return - V_187 ;
}
#endif
V_19 = F_67 ( V_91 , F_46 , 0 ,
V_186 , NULL ) ;
if ( V_19 < 0 ) {
# ifndef F_23
F_68 ( V_4 , 8 ) ;
# endif
F_39 (KERN_ERR LIRC_DRIVER_NAME
L_16 ,
irq) ;
return V_19 ;
}
#ifndef F_23
F_39 (KERN_INFO LIRC_DRIVER_NAME
L_17 ,
io, irq) ;
#endif
F_69 ( & V_118 ) ;
V_118 . V_188 = F_43 ;
V_118 . V_72 = 0xabadcafe ;
return 0 ;
}
static void F_70 ( void )
{
F_71 ( V_91 , NULL ) ;
F_72 ( & V_118 ) ;
#ifndef F_23
F_68 ( V_4 , 8 ) ;
#endif
}
static void F_61 ( void )
{
int V_33 ;
T_7 V_189 [] = {
V_190 ,
V_191 | V_192 ,
V_193 | V_194 | V_195 ,
V_191 ,
V_196 | V_197 ,
V_198 | V_199 | V_200 ,
V_201 | V_202 ,
V_203 | V_204 | V_205 | V_206 ,
V_207 | V_208 ,
V_209 | V_210 | V_211 ,
V_212 | ( V_213 & 0x0f ) ,
V_214 | ( ( V_213 >> 4 ) & 0x0f ) ,
V_215 | V_216 | V_217
} ;
F_5 ( V_167 , V_168 | V_182 ) ;
F_5 ( V_174 , 0 ) ;
F_5 ( V_175 , 12 ) ;
F_5 ( V_167 , V_182 ) ;
F_5 ( V_176 , V_177 | V_178 | V_179 ) ;
for ( V_33 = 0 ; V_33 < 50 ; V_33 ++ )
F_7 ( 1000 ) ;
F_5 ( V_176 , V_178 | V_179 ) ;
for ( V_33 = 0 ; V_33 < 25 ; V_33 ++ )
F_8 ( 1000 ) ;
F_5 ( V_176 , V_177 | V_178 | V_179 ) ;
F_8 ( 100 ) ;
F_5 ( V_176 , V_177 | V_179 ) ;
F_8 ( 7 ) ;
for ( V_33 = 0 ; V_33 < sizeof( V_189 ) ; V_33 ++ ) {
F_5 ( V_132 , V_189 [ V_33 ] ) ;
F_8 ( 1500 ) ;
}
F_5 ( V_176 , V_177 | V_178 | V_179 ) ;
F_8 ( 50 ) ;
F_8 ( 1500 ) ;
F_5 ( V_167 , F_3 ( V_167 ) | V_168 ) ;
F_5 ( V_167 , V_168 | V_183 ) ;
F_5 ( V_174 , 0 ) ;
F_5 ( V_175 , 1 ) ;
F_5 ( V_167 , F_3 ( V_167 ) & ( ~ V_168 ) ) ;
F_5 ( V_167 , V_183 ) ;
F_5 ( V_169 , F_3 ( V_169 ) | V_173 ) ;
}
void F_62 ( void )
{
int V_33 ;
F_5 ( V_167 , V_168 | V_183 ) ;
F_5 ( V_174 , 0 ) ;
F_5 ( V_175 , 12 ) ;
F_5 ( V_167 , V_183 ) ;
F_5 ( V_176 , V_177 | V_179 ) ;
F_8 ( 10 ) ;
F_5 ( V_176 , V_178 | V_177 | V_179 ) ;
for ( V_33 = 0 ; V_33 < 3 ; V_33 ++ ) {
F_8 ( 10 ) ;
F_5 ( V_176 , V_178 | V_179 ) ;
F_8 ( 10 ) ;
F_5 ( V_176 , V_177 | V_178 | V_179 ) ;
}
F_8 ( 1500 ) ;
F_5 ( V_167 , V_168 | V_183 ) ;
F_5 ( V_174 , 0 ) ;
F_5 ( V_175 , 1 ) ;
F_5 ( V_167 , V_183 ) ;
F_5 ( V_169 , V_173 ) ;
}
static int F_73 ( void )
{
int V_19 ;
F_74 ( & V_10 ) ;
V_19 = F_65 () ;
if ( V_19 < 0 )
return V_19 ;
F_54 () ;
F_39 (KERN_INFO LIRC_DRIVER_NAME
L_18 ) ;
return 0 ;
}
static int T_8 F_75 ( struct V_218 * V_74 )
{
return 0 ;
}
static int T_9 F_76 ( struct V_218 * V_74 )
{
return 0 ;
}
static int T_10 F_77 ( void )
{
int V_19 ;
V_19 = F_78 ( & V_219 ) ;
if ( V_19 ) {
F_39 (KERN_ERR LIRC_DRIVER_NAME L_19
L_20 ) ;
return - V_220 ;
}
V_75 = F_79 ( L_21 , 0 ) ;
if ( ! V_75 ) {
F_39 (KERN_ERR LIRC_DRIVER_NAME L_22
L_20 ) ;
V_19 = - V_221 ;
goto V_222;
}
V_19 = F_80 ( V_75 ) ;
if ( V_19 ) {
F_39 (KERN_ERR LIRC_DRIVER_NAME L_23
L_20 ) ;
V_19 = - V_220 ;
goto V_223;
}
V_19 = F_37 () ;
if ( V_19 < 0 )
goto V_224;
V_19 = F_73 () ;
if ( V_19 ) {
F_40 () ;
goto V_224;
}
return 0 ;
V_224:
F_81 ( V_75 ) ;
V_223:
F_82 ( V_75 ) ;
V_222:
F_83 ( & V_219 ) ;
return V_19 ;
}
static void T_11 F_84 ( void )
{
F_63 () ;
F_40 () ;
F_70 () ;
F_85 ( V_75 ) ;
F_83 ( & V_219 ) ;
F_39 (KERN_INFO LIRC_DRIVER_NAME L_24 ) ;
}
