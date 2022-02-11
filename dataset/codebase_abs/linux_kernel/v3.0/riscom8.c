static int F_1 ( struct V_1 const * V_2 ,
char * V_3 , const char * V_4 )
{
#ifdef F_2
static const char V_5 [] = V_6
L_1 ;
static const char V_7 [] = V_6
L_2 ;
if ( ! V_2 ) {
F_3 ( V_7 , V_3 , V_4 ) ;
return 1 ;
}
if ( V_2 -> V_8 != V_9 ) {
F_3 ( V_5 , V_3 , V_4 ) ;
return 1 ;
}
#endif
return 0 ;
}
static inline int F_4 ( struct V_10 const * V_11 )
{
return V_11 - V_12 ;
}
static inline int F_5 ( struct V_1 const * V_2 )
{
return F_6 ( V_2 - V_13 ) ;
}
static inline struct V_10 * F_7 ( struct V_1 const * V_2 )
{
return & V_12 [ F_8 ( V_2 - V_13 ) ] ;
}
static inline unsigned char F_9 ( struct V_10 const * V_11 ,
unsigned short V_14 )
{
return F_10 ( V_11 -> V_15 + F_11 ( V_14 ) ) ;
}
static inline void F_12 ( struct V_10 const * V_11 , unsigned short V_14 ,
unsigned char V_16 )
{
F_13 ( V_16 , V_11 -> V_15 + F_11 ( V_14 ) ) ;
}
static void F_14 ( struct V_10 const * V_11 )
{
unsigned long V_17 ;
for ( V_17 = 100000 ; V_17 ; V_17 -- )
if ( ! F_9 ( V_11 , V_18 ) )
return;
F_3 ( V_6 L_3 , F_4 ( V_11 ) ) ;
}
static int F_15 ( struct V_10 * const V_11 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ )
if ( ! F_16 ( F_11 ( V_21 [ V_19 ] ) + V_11 -> V_15 , 1 ,
L_4 ) ) {
goto V_22;
}
return 0 ;
V_22:
F_3 ( V_6 L_5 ,
F_4 ( V_11 ) , V_11 -> V_15 ) ;
while ( -- V_19 >= 0 )
F_17 ( F_11 ( V_21 [ V_19 ] ) + V_11 -> V_15 , 1 ) ;
return 1 ;
}
static void F_18 ( struct V_10 * const V_11 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ )
F_17 ( F_11 ( V_21 [ V_19 ] ) + V_11 -> V_15 , 1 ) ;
}
static void T_1 F_19 ( struct V_10 const * V_11 )
{
unsigned long V_23 ;
F_20 ( & V_24 , V_23 ) ;
F_12 ( V_11 , V_25 , 0 ) ;
F_14 ( V_11 ) ;
F_12 ( V_11 , V_18 , V_26 ) ;
F_21 ( & V_24 , V_23 ) ;
F_22 ( 50 ) ;
F_20 ( & V_24 , V_23 ) ;
F_12 ( V_11 , V_27 , V_28 ) ;
F_12 ( V_11 , V_29 , 0 ) ;
F_12 ( V_11 , V_30 , V_31 ) ;
F_12 ( V_11 , V_32 , V_33 ) ;
F_12 ( V_11 , V_34 , V_35 ) ;
F_12 ( V_11 , V_36 , ( V_37 / ( 1000000 / V_38 ) ) >> 8 ) ;
F_12 ( V_11 , V_39 , ( V_37 / ( 1000000 / V_38 ) ) & 0xff ) ;
F_21 ( & V_24 , V_23 ) ;
}
static int T_1 F_23 ( struct V_10 * V_11 )
{
unsigned char V_40 , V_41 ;
int V_42 = 0 ;
int V_43 ;
V_11 -> V_44 = 0 ;
if ( F_15 ( V_11 ) )
return 1 ;
F_12 ( V_11 , V_39 , 0x5a ) ;
F_13 ( 0xff , 0x80 ) ;
V_40 = F_9 ( V_11 , V_39 ) ;
F_12 ( V_11 , V_39 , 0xa5 ) ;
F_13 ( 0x00 , 0x80 ) ;
V_41 = F_9 ( V_11 , V_39 ) ;
if ( ( V_40 != 0x5a ) || ( V_41 != 0xa5 ) ) {
F_3 ( V_45 L_6 ,
F_4 ( V_11 ) , V_11 -> V_15 ) ;
goto V_22;
}
for ( V_43 = 0 ; V_43 < 5 && V_42 <= 0 ; V_43 ++ ) {
V_42 = F_24 () ;
F_19 ( V_11 ) ;
F_12 ( V_11 , V_46 , 2 ) ;
F_14 ( V_11 ) ;
F_12 ( V_11 , V_18 , V_47 ) ;
F_12 ( V_11 , V_48 , V_49 ) ;
F_22 ( 50 ) ;
V_42 = F_25 ( V_42 ) ;
V_40 = F_9 ( V_11 , V_50 ) ;
V_41 = F_9 ( V_11 , V_33 ) ;
F_19 ( V_11 ) ;
if ( ( V_40 & V_51 ) || ( V_41 != ( V_28 | V_52 ) ) ) {
F_3 ( V_45 L_7
L_8 , F_4 ( V_11 ) , V_11 -> V_15 ) ;
goto V_22;
}
}
if ( V_42 <= 0 ) {
F_3 ( V_45 L_9
L_10 , F_4 ( V_11 ) , V_11 -> V_15 ) ;
goto V_22;
}
V_11 -> V_44 = V_42 ;
V_11 -> V_23 |= V_53 ;
F_3 ( V_6 L_11
L_12 ,
F_4 ( V_11 ) ,
( F_9 ( V_11 , V_54 ) & 0x0f ) + 'A' ,
V_11 -> V_15 , V_11 -> V_44 ) ;
return 0 ;
V_22:
F_18 ( V_11 ) ;
return 1 ;
}
static struct V_1 * F_26 ( struct V_10 const * V_11 ,
unsigned char const * V_55 )
{
unsigned char V_56 ;
struct V_1 * V_2 ;
V_56 = F_9 ( V_11 , V_29 ) >> V_57 ;
if ( V_56 < V_58 ) {
V_2 = & V_13 [ F_4 ( V_11 ) * V_59 + V_56 ] ;
if ( V_2 -> V_2 . V_23 & V_60 )
return V_2 ;
}
F_3 ( V_45 L_13 ,
F_4 ( V_11 ) , V_55 , V_56 ) ;
return NULL ;
}
static void F_27 ( struct V_10 const * V_11 )
{
struct V_1 * V_2 ;
struct V_61 * V_62 ;
unsigned char V_63 ;
unsigned char V_64 , V_65 ;
V_2 = F_26 ( V_11 , L_14 ) ;
if ( V_2 == NULL )
return;
V_62 = F_28 ( & V_2 -> V_2 ) ;
#ifdef F_29
V_63 = F_9 ( V_11 , V_66 ) ;
if ( V_63 & V_67 )
V_2 -> V_68 ++ ;
V_63 &= V_2 -> V_69 ;
#else
V_63 = F_9 ( V_11 , V_66 ) & V_2 -> V_69 ;
#endif
V_64 = F_9 ( V_11 , V_70 ) ;
if ( ! V_63 )
goto V_71;
if ( V_63 & V_72 ) {
F_3 ( V_73 L_15
L_16 ,
F_4 ( V_11 ) , F_5 ( V_2 ) ) ;
goto V_71;
} else if ( V_63 & V_74 ) {
F_3 ( V_6 L_17 ,
F_4 ( V_11 ) , F_5 ( V_2 ) ) ;
V_65 = V_75 ;
if ( V_62 && ( V_2 -> V_2 . V_23 & V_76 ) )
F_30 ( V_62 ) ;
} else if ( V_63 & V_77 )
V_65 = V_78 ;
else if ( V_63 & V_79 )
V_65 = V_80 ;
else if ( V_63 & V_67 )
V_65 = V_81 ;
else
V_65 = V_82 ;
if ( V_62 ) {
F_31 ( V_62 , V_64 , V_65 ) ;
F_32 ( V_62 ) ;
}
V_71:
F_33 ( V_62 ) ;
}
static void F_34 ( struct V_10 const * V_11 )
{
struct V_1 * V_2 ;
struct V_61 * V_62 ;
unsigned char V_83 ;
V_2 = F_26 ( V_11 , L_14 ) ;
if ( V_2 == NULL )
return;
V_62 = F_28 ( & V_2 -> V_2 ) ;
V_83 = F_9 ( V_11 , V_84 ) ;
#ifdef F_35
V_2 -> V_85 [ V_83 > 8 ? 9 : V_83 ] ++ ;
#endif
while ( V_83 -- ) {
T_2 V_64 = F_9 ( V_11 , V_70 ) ;
if ( V_62 )
F_31 ( V_62 , V_64 , V_82 ) ;
}
if ( V_62 ) {
F_32 ( V_62 ) ;
F_33 ( V_62 ) ;
}
}
static void F_36 ( struct V_10 const * V_11 )
{
struct V_1 * V_2 ;
struct V_61 * V_62 ;
unsigned char V_83 ;
V_2 = F_26 ( V_11 , L_18 ) ;
if ( V_2 == NULL )
return;
V_62 = F_28 ( & V_2 -> V_2 ) ;
if ( V_2 -> V_86 & V_87 ) {
F_12 ( V_11 , V_46 , F_5 ( V_2 ) ) ;
V_2 -> V_86 &= ~ V_87 ;
F_12 ( V_11 , V_48 , V_2 -> V_86 ) ;
goto V_71;
}
if ( ( V_2 -> V_88 <= 0 && ! V_2 -> V_89 )
|| ( V_62 && ( V_62 -> V_90 || V_62 -> V_91 ) ) ) {
F_12 ( V_11 , V_46 , F_5 ( V_2 ) ) ;
V_2 -> V_86 &= ~ V_49 ;
F_12 ( V_11 , V_48 , V_2 -> V_86 ) ;
goto V_71;
}
if ( V_2 -> V_89 ) {
if ( V_2 -> V_89 > 0 ) {
if ( V_2 -> V_92 & V_93 ) {
F_12 ( V_11 , V_94 , V_95 ) ;
F_12 ( V_11 , V_94 , V_96 ) ;
V_2 -> V_92 &= ~ V_93 ;
}
V_83 = F_37 ( int , V_2 -> V_89 , 0xff ) ;
F_12 ( V_11 , V_94 , V_95 ) ;
F_12 ( V_11 , V_94 , V_97 ) ;
F_12 ( V_11 , V_94 , V_83 ) ;
V_2 -> V_89 -= V_83 ;
if ( V_2 -> V_89 == 0 )
V_2 -> V_89 -- ;
} else {
F_12 ( V_11 , V_94 , V_95 ) ;
F_12 ( V_11 , V_94 , V_98 ) ;
F_12 ( V_11 , V_99 , V_2 -> V_92 ) ;
F_14 ( V_11 ) ;
F_12 ( V_11 , V_18 , V_100 ) ;
V_2 -> V_89 = 0 ;
}
goto V_71;
}
V_83 = V_101 ;
do {
F_12 ( V_11 , V_94 , V_2 -> V_2 . V_102 [ V_2 -> V_103 ++ ] ) ;
V_2 -> V_103 = V_2 -> V_103 & ( V_104 - 1 ) ;
if ( -- V_2 -> V_88 <= 0 )
break;
} while ( -- V_83 > 0 );
if ( V_2 -> V_88 <= 0 ) {
F_12 ( V_11 , V_46 , F_5 ( V_2 ) ) ;
V_2 -> V_86 &= ~ V_49 ;
F_12 ( V_11 , V_48 , V_2 -> V_86 ) ;
}
if ( V_62 && V_2 -> V_88 <= V_2 -> V_105 )
F_38 ( V_62 ) ;
V_71:
F_33 ( V_62 ) ;
}
static void F_39 ( struct V_10 const * V_11 )
{
struct V_1 * V_2 ;
struct V_61 * V_62 ;
unsigned char V_106 ;
V_2 = F_26 ( V_11 , L_19 ) ;
if ( V_2 == NULL )
return;
V_62 = F_28 ( & V_2 -> V_2 ) ;
V_106 = F_9 ( V_11 , V_107 ) ;
if ( V_106 & V_108 ) {
if ( F_9 ( V_11 , V_109 ) & V_110 )
F_40 ( & V_2 -> V_2 . V_111 ) ;
else if ( V_62 )
F_41 ( V_62 ) ;
}
#ifdef F_42
if ( V_106 & V_112 ) {
if ( F_9 ( V_11 , V_109 ) & V_113 ) {
V_2 -> V_86 |= V_49 ;
if ( V_62 ) {
V_62 -> V_91 = 0 ;
if ( V_2 -> V_88 <= V_2 -> V_105 )
F_38 ( V_62 ) ;
}
} else {
if ( V_62 )
V_62 -> V_91 = 1 ;
V_2 -> V_86 &= ~ V_49 ;
}
F_12 ( V_11 , V_48 , V_2 -> V_86 ) ;
}
if ( V_106 & V_114 ) {
if ( F_9 ( V_11 , V_109 ) & V_115 ) {
V_2 -> V_86 |= V_49 ;
if ( V_62 ) {
V_62 -> V_91 = 0 ;
if ( V_2 -> V_88 <= V_2 -> V_105 )
F_38 ( V_62 ) ;
}
} else {
if ( V_62 )
V_62 -> V_91 = 1 ;
V_2 -> V_86 &= ~ V_49 ;
}
F_12 ( V_11 , V_48 , V_2 -> V_86 ) ;
}
#endif
F_12 ( V_11 , V_107 , 0 ) ;
F_33 ( V_62 ) ;
}
static T_3 F_43 ( int V_116 , void * V_117 )
{
unsigned char V_63 ;
unsigned char V_118 ;
struct V_10 * V_11 = V_117 ;
unsigned long V_119 = 0 ;
int V_120 = 0 ;
if ( ! ( V_11 -> V_23 & V_121 ) )
return V_122 ;
while ( ( ++ V_119 < 16 ) && ( ( V_63 = ~ ( F_9 ( V_11 , V_50 ) ) ) &
( V_123 | V_51 |
V_124 | V_125 ) ) ) {
V_120 = 1 ;
if ( V_63 & V_123 )
F_3 ( V_73 L_20
L_21 , F_4 ( V_11 ) ) ;
else if ( V_63 & V_125 ) {
V_118 = F_9 ( V_11 , V_35 ) ;
if ( V_118 == ( V_28 | V_126 ) )
F_34 ( V_11 ) ;
else if ( V_118 == ( V_28 | V_127 ) )
F_27 ( V_11 ) ;
else
F_3 ( V_73 L_22
L_23 ,
F_4 ( V_11 ) , V_118 ) ;
} else if ( V_63 & V_51 ) {
V_118 = F_9 ( V_11 , V_33 ) ;
if ( V_118 == ( V_28 | V_52 ) )
F_36 ( V_11 ) ;
else
F_3 ( V_73 L_24
L_23 ,
F_4 ( V_11 ) , V_118 ) ;
} else {
V_118 = F_9 ( V_11 , V_31 ) ;
if ( V_118 == ( V_28 | V_128 ) )
F_39 ( V_11 ) ;
else
F_3 ( V_73 L_25
L_23 ,
F_4 ( V_11 ) , V_118 ) ;
}
F_12 ( V_11 , V_129 , 0 ) ;
F_12 ( V_11 , V_25 , 0 ) ;
}
return F_44 ( V_120 ) ;
}
static int F_45 ( struct V_10 * V_11 )
{
int error ;
if ( V_11 -> V_23 & V_121 )
return 0 ;
error = F_46 ( V_11 -> V_44 , F_43 , V_130 ,
L_4 , V_11 ) ;
if ( error )
return error ;
F_12 ( V_11 , V_25 , 0 ) ;
V_11 -> V_131 = ~ 0 ;
F_12 ( V_11 , V_132 , V_11 -> V_131 ) ;
V_11 -> V_23 |= V_121 ;
return 0 ;
}
static void F_47 ( struct V_10 * V_11 )
{
if ( ! ( V_11 -> V_23 & V_121 ) )
return;
V_11 -> V_23 &= ~ V_121 ;
F_48 ( V_11 -> V_44 , NULL ) ;
V_11 -> V_131 = ~ 0 ;
F_12 ( V_11 , V_132 , V_11 -> V_131 ) ;
}
static void F_49 ( struct V_61 * V_62 , struct V_10 * V_11 ,
struct V_1 * V_2 )
{
unsigned long V_133 ;
long V_134 ;
unsigned char V_135 = 0 , V_136 = 0 ;
unsigned char V_137 = 0 , V_138 = 0 ;
V_2 -> V_86 = 0 ;
V_2 -> V_92 = 0 ;
V_2 -> V_139 = V_140 ;
V_133 = F_50 ( V_62 ) ;
F_12 ( V_11 , V_46 , F_5 ( V_2 ) ) ;
if ( ! V_133 ) {
V_11 -> V_131 |= ( 1u << F_5 ( V_2 ) ) ;
F_12 ( V_11 , V_132 , V_11 -> V_131 ) ;
return;
} else {
V_11 -> V_131 &= ~ ( 1u << F_5 ( V_2 ) ) ;
F_12 ( V_11 , V_132 , V_11 -> V_131 ) ;
}
V_134 = ( ( ( V_37 + V_133 / 2 ) / V_133 +
V_141 / 2 ) / V_141 ) ;
F_12 ( V_11 , V_142 , ( V_134 >> 8 ) & 0xff ) ;
F_12 ( V_11 , V_143 , ( V_134 >> 8 ) & 0xff ) ;
F_12 ( V_11 , V_144 , V_134 & 0xff ) ;
F_12 ( V_11 , V_145 , V_134 & 0xff ) ;
V_133 = ( V_133 + 5 ) / 10 ;
V_134 = ( ( V_133 + V_146 / 2 ) / V_146 ) * 2 - V_101 ;
V_2 -> V_105 = ( V_134 < 0 ) ? 0 : ( ( V_134 >= V_104 ) ?
V_104 - 1 : V_134 ) ;
V_134 = ( V_38 + V_38 / 2 + V_133 / 2 ) / V_133 ;
V_134 = ( V_134 > 0xff ) ? 0xff : V_134 ;
F_12 ( V_11 , V_147 , V_134 ) ;
switch ( F_51 ( V_62 ) ) {
case V_148 :
V_135 |= V_149 ;
break;
case V_150 :
V_135 |= V_151 ;
break;
case V_152 :
V_135 |= V_153 ;
break;
case V_154 :
V_135 |= V_155 ;
break;
}
if ( F_52 ( V_62 ) )
V_135 |= V_156 ;
V_135 |= V_157 ;
if ( F_53 ( V_62 ) ) {
V_135 |= V_158 ;
if ( F_54 ( V_62 ) )
V_135 |= V_159 ;
if ( F_55 ( V_62 ) )
V_135 &= ~ V_157 ;
}
V_2 -> V_69 = V_67 | V_72 ;
if ( F_55 ( V_62 ) )
V_2 -> V_69 |= V_79 | V_77 ;
if ( F_56 ( V_62 ) || F_57 ( V_62 ) )
V_2 -> V_69 |= V_74 ;
if ( F_58 ( V_62 ) )
V_2 -> V_69 &= ~ ( V_79 | V_77 ) ;
if ( F_59 ( V_62 ) ) {
V_2 -> V_69 &= ~ V_74 ;
if ( F_58 ( V_62 ) )
V_2 -> V_69 &= ~ V_67 ;
}
if ( F_60 ( V_62 ) ) {
#ifdef F_42
V_2 -> V_86 |= V_160 | V_161 ;
V_137 |= V_162 | V_163 ;
V_138 |= V_164 | V_165 ;
V_62 -> V_91 = ! ( F_9 ( V_11 , V_109 ) &
( V_113 | V_115 ) ) ;
#else
V_2 -> V_92 |= V_166 ;
#endif
}
if ( F_61 ( V_62 ) ) {
V_2 -> V_92 |= V_167 ;
V_136 |= ( V_168 | V_169 ) ;
if ( F_62 ( V_62 ) )
V_2 -> V_92 |= V_170 ;
F_12 ( V_11 , V_171 , F_63 ( V_62 ) ) ;
F_12 ( V_11 , V_172 , F_64 ( V_62 ) ) ;
F_12 ( V_11 , V_173 , F_63 ( V_62 ) ) ;
F_12 ( V_11 , V_174 , F_64 ( V_62 ) ) ;
}
if ( ! F_65 ( V_62 ) ) {
V_2 -> V_86 |= V_175 ;
V_137 |= V_176 ;
V_138 |= V_177 ;
}
if ( F_66 ( V_62 ) )
V_2 -> V_86 |= V_178 ;
V_136 |= V_179 ;
F_12 ( V_11 , V_180 , V_135 ) ;
F_12 ( V_11 , V_99 , V_2 -> V_92 ) ;
F_12 ( V_11 , V_181 , V_136 ) ;
F_14 ( V_11 ) ;
F_12 ( V_11 , V_18 , V_182 | V_100 | V_183 ) ;
F_12 ( V_11 , V_184 , V_137 ) ;
F_12 ( V_11 , V_185 , V_138 ) ;
F_14 ( V_11 ) ;
F_12 ( V_11 , V_18 , V_47 | V_186 ) ;
F_12 ( V_11 , V_48 , V_2 -> V_86 ) ;
F_12 ( V_11 , V_109 , V_2 -> V_139 ) ;
}
static int F_67 ( struct V_187 * V_2 , struct V_61 * V_62 )
{
struct V_1 * V_188 = F_68 ( V_2 , struct V_1 , V_2 ) ;
struct V_10 * V_11 = F_7 ( V_188 ) ;
unsigned long V_23 ;
if ( F_69 ( V_2 ) < 0 )
return - V_189 ;
F_20 ( & V_24 , V_23 ) ;
F_70 ( V_190 , & V_62 -> V_23 ) ;
V_11 -> V_83 ++ ;
V_188 -> V_88 = V_188 -> V_191 = V_188 -> V_103 = 0 ;
F_49 ( V_62 , V_11 , V_188 ) ;
F_21 ( & V_24 , V_23 ) ;
return 0 ;
}
static void F_71 ( struct V_61 * V_62 ,
struct V_10 * V_11 , struct V_1 * V_2 )
{
#ifdef F_29
F_3 ( V_6 L_26 ,
F_4 ( V_11 ) , F_5 ( V_2 ) , V_2 -> V_68 ) ;
#endif
#ifdef F_35
{
int V_19 ;
F_3 ( V_6 L_27 ,
F_4 ( V_11 ) , F_5 ( V_2 ) ) ;
for ( V_19 = 0 ; V_19 < 10 ; V_19 ++ )
F_3 ( L_28 , V_2 -> V_85 [ V_19 ] ) ;
F_3 ( L_29 ) ;
}
#endif
F_72 ( & V_2 -> V_2 ) ;
F_12 ( V_11 , V_46 , F_5 ( V_2 ) ) ;
F_14 ( V_11 ) ;
F_12 ( V_11 , V_18 , V_192 ) ;
V_2 -> V_86 = 0 ;
F_12 ( V_11 , V_48 , V_2 -> V_86 ) ;
F_73 ( V_190 , & V_62 -> V_23 ) ;
if ( -- V_11 -> V_83 < 0 ) {
F_3 ( V_6 L_30
L_31 ,
F_4 ( V_11 ) , V_11 -> V_83 ) ;
V_11 -> V_83 = 0 ;
}
if ( ! V_11 -> V_83 )
F_47 ( V_11 ) ;
}
static int F_74 ( struct V_187 * V_2 )
{
struct V_1 * V_193 = F_68 ( V_2 , struct V_1 , V_2 ) ;
struct V_10 * V_11 = F_7 ( V_193 ) ;
unsigned long V_23 ;
int V_194 ;
F_20 ( & V_24 , V_23 ) ;
F_12 ( V_11 , V_46 , F_5 ( V_193 ) ) ;
V_194 = F_9 ( V_11 , V_109 ) & V_110 ;
F_12 ( V_11 , V_109 , V_140 ) ;
V_11 -> V_131 &= ~ ( 1u << F_5 ( V_193 ) ) ;
F_12 ( V_11 , V_132 , V_11 -> V_131 ) ;
F_21 ( & V_24 , V_23 ) ;
return V_194 ;
}
static void F_75 ( struct V_187 * V_2 , int V_195 )
{
struct V_1 * V_193 = F_68 ( V_2 , struct V_1 , V_2 ) ;
struct V_10 * V_11 = F_7 ( V_193 ) ;
unsigned long V_23 ;
F_20 ( & V_24 , V_23 ) ;
V_11 -> V_131 &= ~ ( 1u << F_5 ( V_193 ) ) ;
if ( V_195 == 0 )
V_11 -> V_131 |= ( 1u << F_5 ( V_193 ) ) ;
F_12 ( V_11 , V_132 , V_11 -> V_131 ) ;
F_21 ( & V_24 , V_23 ) ;
}
static int F_76 ( struct V_61 * V_62 , struct V_196 * V_197 )
{
int V_198 ;
int error ;
struct V_1 * V_2 ;
struct V_10 * V_11 ;
V_198 = F_8 ( V_62 -> V_199 ) ;
if ( V_198 >= V_200 || ! ( V_12 [ V_198 ] . V_23 & V_53 ) )
return - V_201 ;
V_11 = & V_12 [ V_198 ] ;
V_2 = V_13 + V_198 * V_59 + F_6 ( V_62 -> V_199 ) ;
if ( F_1 ( V_2 , V_62 -> V_3 , L_32 ) )
return - V_201 ;
error = F_45 ( V_11 ) ;
if ( error )
return error ;
V_62 -> V_202 = V_2 ;
return F_77 ( & V_2 -> V_2 , V_62 , V_197 ) ;
}
static void F_78 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = V_62 -> V_202 ;
unsigned long V_23 ;
if ( F_1 ( V_2 , V_62 -> V_3 , L_33 ) )
return;
F_20 ( & V_24 , V_23 ) ;
V_2 -> V_88 = V_2 -> V_191 = V_2 -> V_103 = 0 ;
F_21 ( & V_24 , V_23 ) ;
F_38 ( V_62 ) ;
}
static void F_79 ( struct V_187 * V_2 )
{
unsigned long V_23 ;
struct V_1 * V_188 = F_68 ( V_2 , struct V_1 , V_2 ) ;
struct V_10 * V_11 = F_7 ( V_188 ) ;
unsigned long V_203 ;
F_20 ( & V_24 , V_23 ) ;
V_188 -> V_86 &= ~ V_178 ;
V_188 -> V_86 &= ~ V_49 ;
V_188 -> V_86 |= V_87 ;
F_12 ( V_11 , V_46 , F_5 ( V_188 ) ) ;
F_12 ( V_11 , V_48 , V_188 -> V_86 ) ;
V_203 = V_204 + V_146 ;
while ( V_188 -> V_86 & V_87 ) {
F_21 ( & V_24 , V_23 ) ;
F_80 ( F_81 ( V_188 -> V_203 ) ) ;
F_20 ( & V_24 , V_23 ) ;
if ( F_82 ( V_204 , V_203 ) )
break;
}
F_71 ( V_2 -> V_62 , V_11 , V_188 ) ;
F_21 ( & V_24 , V_23 ) ;
}
static void F_83 ( struct V_61 * V_62 , struct V_196 * V_197 )
{
struct V_1 * V_2 = V_62 -> V_202 ;
if ( ! V_2 || F_1 ( V_2 , V_62 -> V_3 , L_34 ) )
return;
F_84 ( & V_2 -> V_2 , V_62 , V_197 ) ;
}
static int F_85 ( struct V_61 * V_62 ,
const unsigned char * V_205 , int V_83 )
{
struct V_1 * V_2 = V_62 -> V_202 ;
struct V_10 * V_11 ;
int V_206 , V_207 = 0 ;
unsigned long V_23 ;
if ( F_1 ( V_2 , V_62 -> V_3 , L_35 ) )
return 0 ;
V_11 = F_7 ( V_2 ) ;
while ( 1 ) {
F_20 ( & V_24 , V_23 ) ;
V_206 = F_37 ( int , V_83 , F_86 ( V_104 - V_2 -> V_88 - 1 ,
V_104 - V_2 -> V_191 ) ) ;
if ( V_206 <= 0 )
break;
memcpy ( V_2 -> V_2 . V_102 + V_2 -> V_191 , V_205 , V_206 ) ;
V_2 -> V_191 = ( V_2 -> V_191 + V_206 ) & ( V_104 - 1 ) ;
V_2 -> V_88 += V_206 ;
F_21 ( & V_24 , V_23 ) ;
V_205 += V_206 ;
V_83 -= V_206 ;
V_207 += V_206 ;
}
if ( V_2 -> V_88 && ! V_62 -> V_90 && ! V_62 -> V_91 &&
! ( V_2 -> V_86 & V_49 ) ) {
V_2 -> V_86 |= V_49 ;
F_12 ( V_11 , V_46 , F_5 ( V_2 ) ) ;
F_12 ( V_11 , V_48 , V_2 -> V_86 ) ;
}
F_21 ( & V_24 , V_23 ) ;
return V_207 ;
}
static int F_87 ( struct V_61 * V_62 , unsigned char V_64 )
{
struct V_1 * V_2 = V_62 -> V_202 ;
unsigned long V_23 ;
int V_208 = 0 ;
if ( F_1 ( V_2 , V_62 -> V_3 , L_36 ) )
return 0 ;
F_20 ( & V_24 , V_23 ) ;
if ( V_2 -> V_88 >= V_104 - 1 )
goto V_71;
V_2 -> V_2 . V_102 [ V_2 -> V_191 ++ ] = V_64 ;
V_2 -> V_191 &= V_104 - 1 ;
V_2 -> V_88 ++ ;
V_208 = 1 ;
V_71:
F_21 ( & V_24 , V_23 ) ;
return V_208 ;
}
static void F_88 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = V_62 -> V_202 ;
unsigned long V_23 ;
if ( F_1 ( V_2 , V_62 -> V_3 , L_37 ) )
return;
if ( V_2 -> V_88 <= 0 || V_62 -> V_90 || V_62 -> V_91 )
return;
F_20 ( & V_24 , V_23 ) ;
V_2 -> V_86 |= V_49 ;
F_12 ( F_7 ( V_2 ) , V_46 , F_5 ( V_2 ) ) ;
F_12 ( F_7 ( V_2 ) , V_48 , V_2 -> V_86 ) ;
F_21 ( & V_24 , V_23 ) ;
}
static int F_89 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = V_62 -> V_202 ;
int V_208 ;
if ( F_1 ( V_2 , V_62 -> V_3 , L_38 ) )
return 0 ;
V_208 = V_104 - V_2 -> V_88 - 1 ;
if ( V_208 < 0 )
V_208 = 0 ;
return V_208 ;
}
static int F_90 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = V_62 -> V_202 ;
if ( F_1 ( V_2 , V_62 -> V_3 , L_39 ) )
return 0 ;
return V_2 -> V_88 ;
}
static int F_91 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = V_62 -> V_202 ;
struct V_10 * V_11 ;
unsigned char V_63 ;
unsigned int V_209 ;
unsigned long V_23 ;
if ( F_1 ( V_2 , V_62 -> V_3 , V_210 ) )
return - V_201 ;
V_11 = F_7 ( V_2 ) ;
F_20 ( & V_24 , V_23 ) ;
F_12 ( V_11 , V_46 , F_5 ( V_2 ) ) ;
V_63 = F_9 ( V_11 , V_109 ) ;
V_209 = F_9 ( V_11 , V_211 ) & ( 1u << F_5 ( V_2 ) ) ? 0 : V_212 ;
F_21 ( & V_24 , V_23 ) ;
V_209 |= ( ( V_63 & V_140 ) ? V_213 : 0 )
| ( ( V_63 & V_214 ) ? V_215 : 0 )
| ( ( V_63 & V_110 ) ? V_216 : 0 )
| ( ( V_63 & V_115 ) ? V_217 : 0 )
| ( ( V_63 & V_113 ) ? V_218 : 0 ) ;
return V_209 ;
}
static int F_92 ( struct V_61 * V_62 ,
unsigned int V_219 , unsigned int V_220 )
{
struct V_1 * V_2 = V_62 -> V_202 ;
unsigned long V_23 ;
struct V_10 * V_11 ;
if ( F_1 ( V_2 , V_62 -> V_3 , V_210 ) )
return - V_201 ;
V_11 = F_7 ( V_2 ) ;
F_20 ( & V_24 , V_23 ) ;
if ( V_219 & V_213 )
V_2 -> V_139 |= V_140 ;
if ( V_219 & V_215 )
V_11 -> V_131 &= ~ ( 1u << F_5 ( V_2 ) ) ;
if ( V_220 & V_213 )
V_2 -> V_139 &= ~ V_140 ;
if ( V_220 & V_215 )
V_11 -> V_131 |= ( 1u << F_5 ( V_2 ) ) ;
F_12 ( V_11 , V_46 , F_5 ( V_2 ) ) ;
F_12 ( V_11 , V_109 , V_2 -> V_139 ) ;
F_12 ( V_11 , V_132 , V_11 -> V_131 ) ;
F_21 ( & V_24 , V_23 ) ;
return 0 ;
}
static int F_93 ( struct V_61 * V_62 , int V_221 )
{
struct V_1 * V_2 = V_62 -> V_202 ;
struct V_10 * V_11 = F_7 ( V_2 ) ;
unsigned long V_23 ;
if ( V_221 == 0 || V_221 == - 1 )
return - V_222 ;
F_20 ( & V_24 , V_23 ) ;
V_2 -> V_89 = V_38 / V_146 * V_221 ;
V_2 -> V_92 |= V_93 ;
V_2 -> V_86 |= V_49 ;
F_12 ( V_11 , V_46 , F_5 ( V_2 ) ) ;
F_12 ( V_11 , V_99 , V_2 -> V_92 ) ;
F_12 ( V_11 , V_48 , V_2 -> V_86 ) ;
F_14 ( V_11 ) ;
F_12 ( V_11 , V_18 , V_100 ) ;
F_14 ( V_11 ) ;
F_21 ( & V_24 , V_23 ) ;
return 0 ;
}
static int F_94 ( struct V_61 * V_62 , struct V_1 * V_2 ,
struct V_223 T_4 * V_224 )
{
struct V_223 V_134 ;
struct V_10 * V_11 = F_7 ( V_2 ) ;
int V_225 ;
if ( F_95 ( & V_134 , V_224 , sizeof( V_134 ) ) )
return - V_226 ;
F_96 ( & V_2 -> V_2 . V_227 ) ;
V_225 = ( ( V_2 -> V_2 . V_23 & V_228 ) !=
( V_134 . V_23 & V_228 ) ) ;
if ( ! F_97 ( V_229 ) ) {
if ( ( V_134 . V_230 != V_2 -> V_2 . V_230 ) ||
( V_134 . V_231 != V_2 -> V_2 . V_231 ) ||
( ( V_134 . V_23 & ~ V_232 ) !=
( V_2 -> V_2 . V_23 & ~ V_232 ) ) ) {
F_98 ( & V_2 -> V_2 . V_227 ) ;
return - V_233 ;
}
V_2 -> V_2 . V_23 = ( ( V_2 -> V_2 . V_23 & ~ V_232 ) |
( V_134 . V_23 & V_232 ) ) ;
} else {
V_2 -> V_2 . V_23 = ( ( V_2 -> V_2 . V_23 & ~ V_234 ) |
( V_134 . V_23 & V_234 ) ) ;
V_2 -> V_2 . V_230 = V_134 . V_230 ;
V_2 -> V_2 . V_231 = V_134 . V_231 ;
}
if ( V_225 ) {
unsigned long V_23 ;
F_20 ( & V_24 , V_23 ) ;
F_49 ( V_62 , V_11 , V_2 ) ;
F_21 ( & V_24 , V_23 ) ;
}
F_98 ( & V_2 -> V_2 . V_227 ) ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 ,
struct V_223 T_4 * V_235 )
{
struct V_223 V_134 ;
struct V_10 * V_11 = F_7 ( V_2 ) ;
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
V_134 . type = V_236 ;
V_134 . line = V_2 - V_13 ;
F_96 ( & V_2 -> V_2 . V_227 ) ;
V_134 . V_2 = V_11 -> V_15 ;
V_134 . V_44 = V_11 -> V_44 ;
V_134 . V_23 = V_2 -> V_2 . V_23 ;
V_134 . V_237 = ( V_37 + V_141 / 2 ) / V_141 ;
V_134 . V_230 = V_2 -> V_2 . V_230 * V_146 / 100 ;
V_134 . V_231 = V_2 -> V_2 . V_231 * V_146 / 100 ;
F_98 ( & V_2 -> V_2 . V_227 ) ;
V_134 . V_238 = V_101 ;
return F_100 ( V_235 , & V_134 , sizeof( V_134 ) ) ? - V_226 : 0 ;
}
static int F_101 ( struct V_61 * V_62 ,
unsigned int V_239 , unsigned long V_240 )
{
struct V_1 * V_2 = V_62 -> V_202 ;
void T_4 * V_241 = ( void T_4 * ) V_240 ;
int V_242 ;
if ( F_1 ( V_2 , V_62 -> V_3 , L_40 ) )
return - V_201 ;
switch ( V_239 ) {
case V_243 :
V_242 = F_99 ( V_2 , V_241 ) ;
break;
case V_244 :
V_242 = F_94 ( V_62 , V_2 , V_241 ) ;
break;
default:
V_242 = - V_245 ;
}
return V_242 ;
}
static void F_102 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = V_62 -> V_202 ;
struct V_10 * V_11 ;
unsigned long V_23 ;
if ( F_1 ( V_2 , V_62 -> V_3 , L_41 ) )
return;
V_11 = F_7 ( V_2 ) ;
F_20 ( & V_24 , V_23 ) ;
V_2 -> V_139 &= ~ V_140 ;
F_12 ( V_11 , V_46 , F_5 ( V_2 ) ) ;
if ( F_103 ( V_62 ) ) {
F_14 ( V_11 ) ;
F_12 ( V_11 , V_18 , V_246 ) ;
F_14 ( V_11 ) ;
}
F_12 ( V_11 , V_109 , V_2 -> V_139 ) ;
F_21 ( & V_24 , V_23 ) ;
}
static void F_104 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = V_62 -> V_202 ;
struct V_10 * V_11 ;
unsigned long V_23 ;
if ( F_1 ( V_2 , V_62 -> V_3 , L_42 ) )
return;
V_11 = F_7 ( V_2 ) ;
F_20 ( & V_24 , V_23 ) ;
V_2 -> V_139 |= V_140 ;
F_12 ( V_11 , V_46 , F_5 ( V_2 ) ) ;
if ( F_103 ( V_62 ) ) {
F_14 ( V_11 ) ;
F_12 ( V_11 , V_18 , V_247 ) ;
F_14 ( V_11 ) ;
}
F_12 ( V_11 , V_109 , V_2 -> V_139 ) ;
F_21 ( & V_24 , V_23 ) ;
}
static void F_105 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = V_62 -> V_202 ;
struct V_10 * V_11 ;
unsigned long V_23 ;
if ( F_1 ( V_2 , V_62 -> V_3 , L_43 ) )
return;
V_11 = F_7 ( V_2 ) ;
F_20 ( & V_24 , V_23 ) ;
V_2 -> V_86 &= ~ V_49 ;
F_12 ( V_11 , V_46 , F_5 ( V_2 ) ) ;
F_12 ( V_11 , V_48 , V_2 -> V_86 ) ;
F_21 ( & V_24 , V_23 ) ;
}
static void F_106 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = V_62 -> V_202 ;
struct V_10 * V_11 ;
unsigned long V_23 ;
if ( F_1 ( V_2 , V_62 -> V_3 , L_44 ) )
return;
V_11 = F_7 ( V_2 ) ;
F_20 ( & V_24 , V_23 ) ;
if ( V_2 -> V_88 && V_2 -> V_2 . V_102 && ! ( V_2 -> V_86 & V_49 ) ) {
V_2 -> V_86 |= V_49 ;
F_12 ( V_11 , V_46 , F_5 ( V_2 ) ) ;
F_12 ( V_11 , V_48 , V_2 -> V_86 ) ;
}
F_21 ( & V_24 , V_23 ) ;
}
static void F_107 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = V_62 -> V_202 ;
if ( F_1 ( V_2 , V_62 -> V_3 , L_45 ) )
return;
F_108 ( & V_2 -> V_2 ) ;
}
static void F_109 ( struct V_61 * V_62 ,
struct V_248 * V_249 )
{
struct V_1 * V_2 = V_62 -> V_202 ;
unsigned long V_23 ;
if ( F_1 ( V_2 , V_62 -> V_3 , L_46 ) )
return;
F_20 ( & V_24 , V_23 ) ;
F_49 ( V_62 , F_7 ( V_2 ) , V_2 ) ;
F_21 ( & V_24 , V_23 ) ;
if ( ( V_249 -> V_250 & V_251 ) &&
! ( V_62 -> V_252 -> V_250 & V_251 ) ) {
V_62 -> V_91 = 0 ;
F_106 ( V_62 ) ;
}
}
static int T_1 F_110 ( void )
{
int error ;
int V_19 ;
V_253 = F_111 ( V_200 * V_59 ) ;
if ( ! V_253 )
return - V_189 ;
V_253 -> V_254 = V_255 ;
V_253 -> V_3 = L_47 ;
V_253 -> V_256 = V_257 ;
V_253 -> type = V_258 ;
V_253 -> V_259 = V_260 ;
V_253 -> V_261 = V_262 ;
V_253 -> V_261 . V_250 =
V_263 | V_154 | V_264 | V_265 | V_266 ;
V_253 -> V_261 . V_267 = 9600 ;
V_253 -> V_261 . V_268 = 9600 ;
V_253 -> V_23 = V_269 | V_270 ;
F_112 ( V_253 , & V_271 ) ;
error = F_113 ( V_253 ) ;
if ( error != 0 ) {
F_114 ( V_253 ) ;
F_3 ( V_45 L_48
L_49 , error ) ;
return 1 ;
}
memset ( V_13 , 0 , sizeof( V_13 ) ) ;
for ( V_19 = 0 ; V_19 < V_59 * V_200 ; V_19 ++ ) {
F_115 ( & V_13 [ V_19 ] . V_2 ) ;
V_13 [ V_19 ] . V_2 . V_272 = & V_273 ;
V_13 [ V_19 ] . V_8 = V_9 ;
}
return 0 ;
}
static void F_116 ( void )
{
F_117 ( V_253 ) ;
F_114 ( V_253 ) ;
}
static int T_1 F_118 ( char * V_274 )
{
int V_275 [ V_200 ] ;
int V_19 ;
V_274 = F_119 ( V_274 , F_120 ( V_275 ) , V_275 ) ;
for ( V_19 = 0 ; V_19 < V_200 ; V_19 ++ ) {
if ( V_19 < V_275 [ 0 ] )
V_12 [ V_19 ] . V_15 = V_275 [ V_19 + 1 ] ;
else
V_12 [ V_19 ] . V_15 = 0 ;
}
return 1 ;
}
static int T_1 F_121 ( void )
{
int V_19 ;
int V_276 = 0 ;
F_3 ( V_277 ) ;
if ( F_110 () )
return - V_278 ;
for ( V_19 = 0 ; V_19 < V_200 ; V_19 ++ )
if ( V_12 [ V_19 ] . V_15 && ! F_23 ( & V_12 [ V_19 ] ) )
V_276 ++ ;
if ( ! V_276 ) {
F_116 () ;
F_3 ( V_279 ) ;
return - V_278 ;
}
return 0 ;
}
static int T_1 F_122 ( void )
{
#ifdef F_123
int V_19 ;
if ( V_280 || V_281 || V_282 || V_283 ) {
for ( V_19 = 0 ; V_19 < V_200 ; V_19 ++ )
V_12 [ V_19 ] . V_15 = 0 ;
}
if ( V_280 )
V_12 [ 0 ] . V_15 = V_280 ;
if ( V_281 )
V_12 [ 1 ] . V_15 = V_281 ;
if ( V_282 )
V_12 [ 2 ] . V_15 = V_282 ;
if ( V_283 )
V_12 [ 3 ] . V_15 = V_283 ;
#endif
return F_121 () ;
}
static void T_5 F_124 ( void )
{
int V_19 ;
F_116 () ;
for ( V_19 = 0 ; V_19 < V_200 ; V_19 ++ )
if ( V_12 [ V_19 ] . V_23 & V_53 )
F_18 ( & V_12 [ V_19 ] ) ;
}
