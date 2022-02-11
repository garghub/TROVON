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
V_73 . V_74 = F_38 ( & V_73 ) ;
if ( V_73 . V_74 < 0 ) {
F_39 (KERN_ERR LIRC_DRIVER_NAME L_3 ) ;
return - V_75 ;
}
return 0 ;
}
static void F_40 ( void )
{
F_41 ( V_73 . V_74 ) ;
}
static long F_42 ( struct V_76 * V_77 , struct V_76 * V_78 )
{
unsigned long V_79 ;
V_79 = V_78 -> V_80 - V_77 -> V_80 ;
if ( V_79 > 15 )
V_79 = 0xFFFFFF ;
else
V_79 = V_79 * 1000000 +
V_78 -> V_81 -
V_77 -> V_81 ;
return V_79 ;
}
static void F_43 ( unsigned long V_72 )
{
unsigned long V_32 ;
unsigned long V_82 ;
F_44 ( & V_83 , V_32 ) ;
if ( V_84 ) {
#ifndef F_23
F_6 ( V_85 , V_4 + V_86 ) ;
#endif
V_82 = F_42 ( & V_87 , & V_88 ) ;
F_33 ( L_4 , V_84 , V_82 ) ;
F_32 ( V_84 , V_82 ) ;
V_84 = 0 ;
V_87 = V_88 ;
}
F_45 ( & V_83 , V_32 ) ;
}
static T_6 F_46 ( int V_89 , void * V_90 )
{
unsigned char V_72 ;
struct V_76 V_91 ;
static unsigned long V_79 ;
#ifdef F_23
int V_92 ;
static int V_18 ;
V_92 = V_36 ;
while ( V_92 & V_93 ) {
int V_94 ;
if ( V_95 ) {
F_33 ( L_5 ) ;
V_94 = V_96 ;
if ( V_94 & V_97 )
F_33 ( L_6 ) ;
if ( V_94 & V_98 )
F_33 ( L_7 ) ;
if ( V_94 & V_99 )
F_33 ( L_8 ) ;
}
V_94 = V_100 ;
V_18 ++ ;
V_92 = V_36 ;
}
if ( V_92 & ( V_101 | V_37 ) ) {
F_47 ( & V_91 ) ;
V_79 = F_42 ( & V_87 , & V_91 ) ;
do {
V_72 = V_100 ;
F_33 ( L_9 , V_18 , ( unsigned int ) V_72 ) ;
V_18 ++ ;
} while ( V_92 & V_37 &&
V_96 & V_102 );
if ( V_92 & V_37 ) {
F_32 ( 0 , V_79 - V_18 * V_70 ) ;
F_32 ( 1 , V_18 * V_70 ) ;
V_18 = 0 ;
V_87 = V_91 ;
}
}
if ( V_92 & V_103 )
F_39 ( V_104 L_10 ) ;
V_92 &= ( V_37 | V_38 | V_39 ) ;
if ( V_92 )
V_36 = V_92 ;
#else
unsigned long V_105 ;
unsigned long V_32 ;
int V_106 , V_107 ;
while ( ( V_106 = F_4 ( V_4 + V_108 ) & V_109 ) ) {
switch ( V_106 & V_109 ) {
case V_110 :
( void ) F_4 ( V_4 + V_111 ) ;
break;
case V_112 :
( void ) F_4 ( V_4 + V_113 ) ;
break;
case V_114 :
#if 0
if (lsr & UART_LSR_THRE)
outb(data, io + UART_TX)
#endif
break;
case V_115 :
F_44 ( & V_83 , V_32 ) ;
do {
F_48 ( & V_116 ) ;
V_72 = F_4 ( V_4 + V_117 ) ;
F_47 ( & V_91 ) ;
V_79 = F_42 ( & V_87 , & V_91 ) ;
V_105 = F_42 ( & V_88 , & V_91 ) ;
F_33 ( L_11 , V_105 , ( int ) V_72 ) ;
if ( V_105 > V_70 * V_118 ) {
if ( V_84 ) {
F_33 ( L_12 ) ;
F_32 ( V_84 ,
V_79 -
V_105 ) ;
V_84 = 0 ;
V_87 . V_80 =
V_88 . V_80 ;
V_87 . V_81 =
V_88 . V_81 ;
V_79 = V_105 ;
}
}
V_72 = 1 ;
if ( V_72 ^ V_84 ) {
F_32 ( V_84 ,
V_79 - V_70 ) ;
V_84 = V_72 ;
V_87 = V_91 ;
if ( V_87 . V_81 >= V_70 ) {
V_87 . V_81 -= V_70 ;
} else {
V_87 . V_80 -- ;
V_87 . V_81 += 1000000 -
V_70 ;
}
}
V_88 = V_91 ;
if ( V_72 ) {
V_116 . V_119 = V_120 +
V_121 ;
F_49 ( & V_116 ) ;
}
V_107 = F_4 ( V_4 + V_113 ) ;
} while ( V_107 & V_122 );
F_45 ( & V_83 , V_32 ) ;
break;
default:
break;
}
}
#endif
return F_50 ( V_123 ) ;
}
static void F_25 ( unsigned long V_124 )
{
unsigned long V_125 , V_126 ;
int V_65 ;
if ( V_124 == 0 )
return;
for ( V_125 = V_65 = 0 ; V_125 < V_124 ; V_125 += V_126 , V_65 = ! V_65 ) {
if ( V_65 ) {
F_2 () ;
V_126 = V_60 ;
} else {
F_1 () ;
V_126 = V_58 ;
}
F_7 ( V_126 ) ;
}
F_2 () ;
}
static void F_26 ( unsigned long V_124 )
{
if ( V_124 == 0 )
return;
F_2 () ;
F_7 ( V_124 ) ;
}
static void F_26 ( unsigned long V_127 )
{
F_7 ( V_127 ) ;
}
static void F_25 ( unsigned long V_127 )
{
long V_128 = V_127 / V_70 ;
if ( V_128 == 0 )
V_128 ++ ;
while ( V_128 -- ) {
F_6 ( V_129 , V_4 + V_130 ) ;
while ( ! ( F_4 ( V_4 + V_113 ) & V_131 ) )
;
}
}
static int F_51 ( int V_132 )
{
if ( V_132 ) {
F_52 ( V_133 ,
V_134 ) ;
F_53 ( V_133 , V_135 ) ;
F_8 ( 100 ) ;
} else {
F_52 ( V_133 ,
V_134 ) ;
F_53 ( V_133 , V_136 ) ;
}
return 0 ;
}
static int F_54 ( void )
{
unsigned long V_32 ;
F_44 ( & V_137 , V_32 ) ;
#ifdef F_23
#ifdef F_55
if ( F_56 () ) {
F_39 ( V_138 L_13 ) ;
F_57 ( V_139 ) ;
}
#endif
#ifdef F_58
F_51 ( 3 ) ;
#endif
V_140 . V_141 = V_142 ;
V_140 . V_143 = V_144 ;
V_140 . V_145 = V_146 ;
V_140 . V_147 = V_148 ;
V_140 . V_149 = V_35 ;
V_140 . V_150 = V_151 ;
V_140 . V_152 = V_100 ;
V_140 . V_153 = V_36 ;
V_140 . V_154 = V_96 ;
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
#elif F_59 ( V_162 )
F_5 ( V_86 ,
V_85 |
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
F_5 ( V_130 , V_178 | V_179 ) ;
F_8 ( 1500 ) ;
F_5 ( V_174 , V_175 | V_176 | V_177 ) ;
F_8 ( 50 ) ;
F_8 ( 1500 ) ;
F_39 (KERN_INFO LIRC_DRIVER_NAME
L_14 , sinp(UART_RX)) ;
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
F_6 ( V_182 , V_4 + V_86 ) ;
F_6 ( V_171 , V_4 + V_167 ) ;
F_6 ( V_176 | V_175 | V_177 , V_4 + V_174 ) ;
#ifdef F_60
F_61 () ;
#elif F_59 ( V_183 )
F_62 () ;
#endif
#endif
F_45 ( & V_137 , V_32 ) ;
return 0 ;
}
static void F_63 ( void )
{
unsigned long V_32 ;
F_44 ( & V_137 , V_32 ) ;
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
F_64 ( V_139 ) ;
#endif
#ifdef F_58
F_51 ( 0 ) ;
#endif
#else
F_6 ( 0 , V_4 + V_167 ) ;
#endif
F_45 ( & V_137 , V_32 ) ;
}
static int F_65 ( void )
{
int V_19 ;
#ifndef F_23
if ( F_66 ( V_4 , 8 , V_184 ) == NULL ) {
F_39 (KERN_ERR LIRC_DRIVER_NAME
L_15 , io) ;
return - V_185 ;
}
#endif
V_19 = F_67 ( V_89 , F_46 , V_186 ,
V_184 , NULL ) ;
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
F_69 ( & V_116 ) ;
V_116 . V_187 = F_43 ;
V_116 . V_72 = 0xabadcafe ;
return 0 ;
}
static void F_70 ( void )
{
F_71 ( V_89 , NULL ) ;
F_72 ( & V_116 ) ;
#ifndef F_23
F_68 ( V_4 , 8 ) ;
#endif
}
static void F_61 ( void )
{
int V_33 ;
T_7 V_188 [] = {
V_189 ,
V_190 | V_191 ,
V_192 | V_193 | V_194 ,
V_190 ,
V_195 | V_196 ,
V_197 | V_198 | V_199 ,
V_200 | V_201 ,
V_202 | V_203 | V_204 | V_205 ,
V_206 | V_207 ,
V_208 | V_209 | V_210 ,
V_211 | ( V_212 & 0x0f ) ,
V_213 | ( ( V_212 >> 4 ) & 0x0f ) ,
V_214 | V_215 | V_216
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
for ( V_33 = 0 ; V_33 < sizeof( V_188 ) ; V_33 ++ ) {
F_5 ( V_130 , V_188 [ V_33 ] ) ;
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
void F_62 ( void )
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
static int T_8 F_75 ( void )
{
int V_19 ;
V_19 = F_37 () ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_73 () ;
if ( V_19 ) {
F_40 () ;
return V_19 ;
}
return 0 ;
}
static void T_9 F_76 ( void )
{
F_63 () ;
F_40 () ;
F_70 () ;
F_39 (KERN_INFO LIRC_DRIVER_NAME L_19 ) ;
}
