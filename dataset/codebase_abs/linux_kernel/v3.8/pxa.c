static inline unsigned int F_1 ( struct V_1 * V_2 , int V_3 )
{
V_3 <<= 2 ;
return F_2 ( V_2 -> V_4 . V_5 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , int V_3 , int V_6 )
{
V_3 <<= 2 ;
F_4 ( V_6 , V_2 -> V_4 . V_5 + V_3 ) ;
}
static void F_5 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
V_2 -> V_8 |= V_9 ;
F_3 ( V_2 , V_10 , V_2 -> V_8 ) ;
}
static void F_6 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
if ( V_2 -> V_8 & V_11 ) {
V_2 -> V_8 &= ~ V_11 ;
F_3 ( V_2 , V_10 , V_2 -> V_8 ) ;
}
}
static void F_7 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
V_2 -> V_8 &= ~ V_12 ;
V_2 -> V_4 . V_13 &= ~ V_14 ;
F_3 ( V_2 , V_10 , V_2 -> V_8 ) ;
}
static inline void F_8 ( struct V_1 * V_2 , int * V_15 )
{
struct V_16 * V_17 = V_2 -> V_4 . V_18 -> V_4 . V_17 ;
unsigned int V_19 , V_20 ;
int V_21 = 256 ;
do {
V_2 -> V_8 &= ~ V_22 ;
F_3 ( V_2 , V_10 , V_2 -> V_8 ) ;
V_19 = F_1 ( V_2 , V_23 ) ;
V_20 = V_24 ;
V_2 -> V_4 . V_25 . V_26 ++ ;
if ( F_9 ( * V_15 & ( V_27 | V_28 |
V_29 | V_30 ) ) ) {
if ( * V_15 & V_27 ) {
* V_15 &= ~ ( V_29 | V_28 ) ;
V_2 -> V_4 . V_25 . V_31 ++ ;
if ( F_10 ( & V_2 -> V_4 ) )
goto V_32;
} else if ( * V_15 & V_28 )
V_2 -> V_4 . V_25 . V_33 ++ ;
else if ( * V_15 & V_29 )
V_2 -> V_4 . V_25 . V_34 ++ ;
if ( * V_15 & V_30 )
V_2 -> V_4 . V_25 . V_35 ++ ;
* V_15 &= V_2 -> V_4 . V_13 ;
#ifdef F_11
if ( V_2 -> V_4 . line == V_2 -> V_4 . V_36 -> V_37 ) {
* V_15 |= V_2 -> V_38 ;
V_2 -> V_38 = 0 ;
}
#endif
if ( * V_15 & V_27 ) {
V_20 = V_39 ;
} else if ( * V_15 & V_28 )
V_20 = V_40 ;
else if ( * V_15 & V_29 )
V_20 = V_41 ;
}
if ( F_12 ( & V_2 -> V_4 , V_19 ) )
goto V_32;
F_13 ( & V_2 -> V_4 , * V_15 , V_30 , V_19 , V_20 ) ;
V_32:
* V_15 = F_1 ( V_2 , V_42 ) ;
} while ( ( * V_15 & V_14 ) && ( V_21 -- > 0 ) );
F_14 ( V_17 ) ;
V_2 -> V_8 |= V_22 ;
F_3 ( V_2 , V_10 , V_2 -> V_8 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = & V_2 -> V_4 . V_18 -> V_44 ;
int V_45 ;
if ( V_2 -> V_4 . V_46 ) {
F_3 ( V_2 , V_47 , V_2 -> V_4 . V_46 ) ;
V_2 -> V_4 . V_25 . V_48 ++ ;
V_2 -> V_4 . V_46 = 0 ;
return;
}
if ( F_16 ( V_44 ) || F_17 ( & V_2 -> V_4 ) ) {
F_6 ( & V_2 -> V_4 ) ;
return;
}
V_45 = V_2 -> V_4 . V_49 / 2 ;
do {
F_3 ( V_2 , V_47 , V_44 -> V_50 [ V_44 -> V_51 ] ) ;
V_44 -> V_51 = ( V_44 -> V_51 + 1 ) & ( V_52 - 1 ) ;
V_2 -> V_4 . V_25 . V_48 ++ ;
if ( F_16 ( V_44 ) )
break;
} while ( -- V_45 > 0 );
if ( F_18 ( V_44 ) < V_53 )
F_19 ( & V_2 -> V_4 ) ;
if ( F_16 ( V_44 ) )
F_6 ( & V_2 -> V_4 ) ;
}
static void F_20 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
if ( ! ( V_2 -> V_8 & V_11 ) ) {
V_2 -> V_8 |= V_11 ;
F_3 ( V_2 , V_10 , V_2 -> V_8 ) ;
}
}
static inline void F_21 ( struct V_1 * V_2 )
{
int V_15 ;
V_15 = F_1 ( V_2 , V_54 ) ;
if ( ( V_15 & V_55 ) == 0 )
return;
if ( V_15 & V_56 )
V_2 -> V_4 . V_25 . V_57 ++ ;
if ( V_15 & V_58 )
V_2 -> V_4 . V_25 . V_59 ++ ;
if ( V_15 & V_60 )
F_22 ( & V_2 -> V_4 , V_15 & V_61 ) ;
if ( V_15 & V_62 )
F_23 ( & V_2 -> V_4 , V_15 & V_63 ) ;
F_24 ( & V_2 -> V_4 . V_18 -> V_4 . V_64 ) ;
}
static inline T_1 F_25 ( int V_65 , void * V_66 )
{
struct V_1 * V_2 = V_66 ;
unsigned int V_67 , V_68 ;
V_67 = F_1 ( V_2 , V_69 ) ;
if ( V_67 & V_70 )
return V_71 ;
V_68 = F_1 ( V_2 , V_42 ) ;
if ( V_68 & V_14 )
F_8 ( V_2 , & V_68 ) ;
F_21 ( V_2 ) ;
if ( V_68 & V_72 )
F_15 ( V_2 ) ;
return V_73 ;
}
static unsigned int F_26 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_74 ;
unsigned int V_75 ;
F_27 ( & V_2 -> V_4 . V_76 , V_74 ) ;
V_75 = F_1 ( V_2 , V_42 ) & V_77 ? V_78 : 0 ;
F_28 ( & V_2 -> V_4 . V_76 , V_74 ) ;
return V_75 ;
}
static unsigned int F_29 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned char V_15 ;
unsigned int V_75 ;
V_15 = F_1 ( V_2 , V_54 ) ;
V_75 = 0 ;
if ( V_15 & V_61 )
V_75 |= V_79 ;
if ( V_15 & V_80 )
V_75 |= V_81 ;
if ( V_15 & V_82 )
V_75 |= V_83 ;
if ( V_15 & V_63 )
V_75 |= V_84 ;
return V_75 ;
}
static void F_30 ( struct V_7 * V_4 , unsigned int V_85 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned char V_86 = 0 ;
if ( V_85 & V_87 )
V_86 |= V_88 ;
if ( V_85 & V_89 )
V_86 |= V_90 ;
if ( V_85 & V_91 )
V_86 |= V_92 ;
if ( V_85 & V_93 )
V_86 |= V_94 ;
if ( V_85 & V_95 )
V_86 |= V_96 ;
V_86 |= V_2 -> V_86 ;
F_3 ( V_2 , V_97 , V_86 ) ;
}
static void F_31 ( struct V_7 * V_4 , int V_98 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_74 ;
F_27 ( & V_2 -> V_4 . V_76 , V_74 ) ;
if ( V_98 == - 1 )
V_2 -> V_99 |= V_100 ;
else
V_2 -> V_99 &= ~ V_100 ;
F_3 ( V_2 , V_101 , V_2 -> V_99 ) ;
F_28 ( & V_2 -> V_4 . V_76 , V_74 ) ;
}
static int F_32 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_74 ;
int V_102 ;
if ( V_4 -> line == 3 )
V_2 -> V_86 |= V_103 ;
else
V_2 -> V_86 = 0 ;
V_2 -> V_4 . V_104 = F_33 ( V_2 -> V_105 ) ;
V_102 = F_34 ( V_2 -> V_4 . V_65 , F_25 , 0 , V_2 -> V_106 , V_2 ) ;
if ( V_102 )
return V_102 ;
F_3 ( V_2 , V_107 , V_108 ) ;
F_3 ( V_2 , V_107 , V_108 |
V_109 | V_110 ) ;
F_3 ( V_2 , V_107 , 0 ) ;
( void ) F_1 ( V_2 , V_42 ) ;
( void ) F_1 ( V_2 , V_23 ) ;
( void ) F_1 ( V_2 , V_69 ) ;
( void ) F_1 ( V_2 , V_54 ) ;
F_3 ( V_2 , V_101 , V_111 ) ;
F_27 ( & V_2 -> V_4 . V_76 , V_74 ) ;
V_2 -> V_4 . V_85 |= V_93 ;
F_30 ( & V_2 -> V_4 , V_2 -> V_4 . V_85 ) ;
F_28 ( & V_2 -> V_4 . V_76 , V_74 ) ;
V_2 -> V_8 = V_12 | V_112 | V_22 | V_113 ;
F_3 ( V_2 , V_10 , V_2 -> V_8 ) ;
( void ) F_1 ( V_2 , V_42 ) ;
( void ) F_1 ( V_2 , V_23 ) ;
( void ) F_1 ( V_2 , V_69 ) ;
( void ) F_1 ( V_2 , V_54 ) ;
return 0 ;
}
static void F_35 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_74 ;
F_36 ( V_2 -> V_4 . V_65 , V_2 ) ;
V_2 -> V_8 = 0 ;
F_3 ( V_2 , V_10 , 0 ) ;
F_27 ( & V_2 -> V_4 . V_76 , V_74 ) ;
V_2 -> V_4 . V_85 &= ~ V_93 ;
F_30 ( & V_2 -> V_4 , V_2 -> V_4 . V_85 ) ;
F_28 ( & V_2 -> V_4 . V_76 , V_74 ) ;
F_3 ( V_2 , V_101 , F_1 ( V_2 , V_101 ) & ~ V_100 ) ;
F_3 ( V_2 , V_107 , V_108 |
V_109 |
V_110 ) ;
F_3 ( V_2 , V_107 , 0 ) ;
}
static void
F_37 ( struct V_7 * V_4 , struct V_114 * V_115 ,
struct V_114 * V_116 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned char V_117 , V_118 = 0 ;
unsigned long V_74 ;
unsigned int V_119 , V_120 ;
unsigned int V_121 ;
switch ( V_115 -> V_122 & V_123 ) {
case V_124 :
V_117 = V_125 ;
break;
case V_126 :
V_117 = V_127 ;
break;
case V_128 :
V_117 = V_129 ;
break;
default:
case V_130 :
V_117 = V_111 ;
break;
}
if ( V_115 -> V_122 & V_131 )
V_117 |= V_132 ;
if ( V_115 -> V_122 & V_133 )
V_117 |= V_134 ;
if ( ! ( V_115 -> V_122 & V_135 ) )
V_117 |= V_136 ;
V_119 = F_38 ( V_4 , V_115 , V_116 , 0 , V_4 -> V_104 / 16 ) ;
V_120 = F_39 ( V_4 , V_119 ) ;
if ( ( V_2 -> V_4 . V_104 / V_120 ) < ( 2400 * 16 ) )
V_118 = V_108 | V_137 ;
else if ( ( V_2 -> V_4 . V_104 / V_120 ) < ( 230400 * 16 ) )
V_118 = V_108 | V_138 ;
else
V_118 = V_108 | V_139 ;
F_27 ( & V_2 -> V_4 . V_76 , V_74 ) ;
V_2 -> V_8 |= V_113 ;
F_40 ( V_4 , V_115 -> V_122 , V_119 ) ;
V_2 -> V_4 . V_13 = V_30 | V_72 | V_14 ;
if ( V_115 -> V_140 & V_141 )
V_2 -> V_4 . V_13 |= V_29 | V_28 ;
if ( V_115 -> V_140 & ( V_142 | V_143 ) )
V_2 -> V_4 . V_13 |= V_27 ;
V_2 -> V_4 . V_144 = 0 ;
if ( V_115 -> V_140 & V_145 )
V_2 -> V_4 . V_144 |= V_28 | V_29 ;
if ( V_115 -> V_140 & V_146 ) {
V_2 -> V_4 . V_144 |= V_27 ;
if ( V_115 -> V_140 & V_145 )
V_2 -> V_4 . V_144 |= V_30 ;
}
if ( ( V_115 -> V_122 & V_147 ) == 0 )
V_2 -> V_4 . V_144 |= V_14 ;
V_2 -> V_8 &= ~ V_9 ;
if ( F_41 ( & V_2 -> V_4 , V_115 -> V_122 ) )
V_2 -> V_8 |= V_9 ;
F_3 ( V_2 , V_10 , V_2 -> V_8 ) ;
if ( V_115 -> V_122 & V_148 )
V_2 -> V_86 |= V_103 ;
else
V_2 -> V_86 &= ~ V_103 ;
F_3 ( V_2 , V_101 , V_117 | V_149 ) ;
F_3 ( V_2 , V_150 , V_120 & 0xff ) ;
V_121 = F_1 ( V_2 , V_150 ) ;
F_42 ( V_121 != ( V_120 & 0xff ) ) ;
F_3 ( V_2 , V_151 , V_120 >> 8 ) ;
F_3 ( V_2 , V_101 , V_117 ) ;
V_2 -> V_99 = V_117 ;
F_30 ( & V_2 -> V_4 , V_2 -> V_4 . V_85 ) ;
F_3 ( V_2 , V_107 , V_118 ) ;
F_28 ( & V_2 -> V_4 . V_76 , V_74 ) ;
}
static void
F_43 ( struct V_7 * V_4 , unsigned int V_18 ,
unsigned int V_152 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
if ( ! V_18 )
F_44 ( V_2 -> V_105 ) ;
else
F_45 ( V_2 -> V_105 ) ;
}
static void F_46 ( struct V_7 * V_4 )
{
}
static int F_47 ( struct V_7 * V_4 )
{
return 0 ;
}
static void F_48 ( struct V_7 * V_4 , int V_74 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
V_2 -> V_4 . type = V_153 ;
}
static int
F_49 ( struct V_7 * V_4 , struct V_154 * V_155 )
{
return - V_156 ;
}
static const char *
F_50 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
return V_2 -> V_106 ;
}
static inline void F_51 ( struct V_1 * V_2 )
{
unsigned int V_15 , V_157 = 10000 ;
do {
V_15 = F_1 ( V_2 , V_42 ) ;
if ( V_15 & V_27 )
V_2 -> V_38 = V_27 ;
if ( -- V_157 == 0 )
break;
F_52 ( 1 ) ;
} while ( ( V_15 & V_158 ) != V_158 );
if ( V_2 -> V_4 . V_74 & V_159 ) {
V_157 = 1000000 ;
while ( -- V_157 &&
( ( F_1 ( V_2 , V_54 ) & V_63 ) == 0 ) )
F_52 ( 1 ) ;
}
}
static void F_53 ( struct V_7 * V_4 , int V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
F_51 ( V_2 ) ;
F_3 ( V_2 , V_47 , V_19 ) ;
}
static void
F_54 ( struct V_160 * V_161 , const char * V_162 , unsigned int V_45 )
{
struct V_1 * V_2 = V_163 [ V_161 -> V_37 ] ;
unsigned int V_8 ;
unsigned long V_74 ;
int V_164 = 1 ;
F_44 ( V_2 -> V_105 ) ;
F_55 ( V_74 ) ;
if ( V_2 -> V_4 . V_165 )
V_164 = 0 ;
else if ( V_166 )
V_164 = F_56 ( & V_2 -> V_4 . V_76 ) ;
else
F_57 ( & V_2 -> V_4 . V_76 ) ;
V_8 = F_1 ( V_2 , V_10 ) ;
F_3 ( V_2 , V_10 , V_113 ) ;
F_58 ( & V_2 -> V_4 , V_162 , V_45 , F_53 ) ;
F_51 ( V_2 ) ;
F_3 ( V_2 , V_10 , V_8 ) ;
if ( V_164 )
F_59 ( & V_2 -> V_4 . V_76 ) ;
F_60 ( V_74 ) ;
F_45 ( V_2 -> V_105 ) ;
}
static int F_61 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned char V_68 = F_1 ( V_2 , V_42 ) ;
while ( ! ( V_68 & V_14 ) )
V_68 = F_1 ( V_2 , V_42 ) ;
return F_1 ( V_2 , V_23 ) ;
}
static void F_62 ( struct V_7 * V_4 ,
unsigned char V_167 )
{
unsigned int V_8 ;
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
V_8 = F_1 ( V_2 , V_10 ) ;
F_3 ( V_2 , V_10 , V_113 ) ;
F_51 ( V_2 ) ;
F_3 ( V_2 , V_47 , V_167 ) ;
if ( V_167 == 10 ) {
F_51 ( V_2 ) ;
F_3 ( V_2 , V_47 , 13 ) ;
}
F_51 ( V_2 ) ;
F_3 ( V_2 , V_10 , V_8 ) ;
}
static int T_2
F_63 ( struct V_160 * V_161 , char * V_168 )
{
struct V_1 * V_2 ;
int V_119 = 9600 ;
int V_169 = 8 ;
int V_33 = 'n' ;
int V_170 = 'n' ;
if ( V_161 -> V_37 == - 1 || V_161 -> V_37 >= V_171 . V_172 )
V_161 -> V_37 = 0 ;
V_2 = V_163 [ V_161 -> V_37 ] ;
if ( ! V_2 )
return - V_173 ;
if ( V_168 )
F_64 ( V_168 , & V_119 , & V_33 , & V_169 , & V_170 ) ;
return F_65 ( & V_2 -> V_4 , V_161 , V_119 , V_33 , V_169 , V_170 ) ;
}
static int F_66 ( struct V_174 * V_175 )
{
struct V_1 * V_176 = F_67 ( V_175 ) ;
if ( V_176 )
F_68 ( & V_171 , & V_176 -> V_4 ) ;
return 0 ;
}
static int F_69 ( struct V_174 * V_175 )
{
struct V_1 * V_176 = F_67 ( V_175 ) ;
if ( V_176 )
F_70 ( & V_171 , & V_176 -> V_4 ) ;
return 0 ;
}
static int F_71 ( struct V_177 * V_178 ,
struct V_1 * V_176 )
{
struct V_179 * V_180 = V_178 -> V_175 . V_181 ;
int V_75 ;
if ( ! V_180 )
return 1 ;
V_75 = F_72 ( V_180 , L_1 ) ;
if ( V_75 < 0 ) {
F_73 ( & V_178 -> V_175 , L_2 , V_75 ) ;
return V_75 ;
}
V_176 -> V_4 . line = V_75 ;
return 0 ;
}
static int F_74 ( struct V_177 * V_175 )
{
struct V_1 * V_176 ;
struct V_182 * V_183 , * V_184 ;
int V_75 ;
V_183 = F_75 ( V_175 , V_185 , 0 ) ;
V_184 = F_75 ( V_175 , V_186 , 0 ) ;
if ( ! V_183 || ! V_184 )
return - V_173 ;
V_176 = F_76 ( sizeof( struct V_1 ) , V_187 ) ;
if ( ! V_176 )
return - V_188 ;
V_176 -> V_105 = F_77 ( & V_175 -> V_175 , NULL ) ;
if ( F_78 ( V_176 -> V_105 ) ) {
V_75 = F_79 ( V_176 -> V_105 ) ;
goto V_189;
}
V_176 -> V_4 . type = V_153 ;
V_176 -> V_4 . V_190 = V_191 ;
V_176 -> V_4 . V_192 = V_183 -> V_193 ;
V_176 -> V_4 . V_65 = V_184 -> V_193 ;
V_176 -> V_4 . V_49 = 64 ;
V_176 -> V_4 . V_194 = & V_195 ;
V_176 -> V_4 . V_175 = & V_175 -> V_175 ;
V_176 -> V_4 . V_74 = V_196 | V_197 ;
V_176 -> V_4 . V_104 = F_33 ( V_176 -> V_105 ) ;
V_75 = F_71 ( V_175 , V_176 ) ;
if ( V_75 > 0 )
V_176 -> V_4 . line = V_175 -> V_198 ;
else if ( V_75 < 0 )
goto V_199;
snprintf ( V_176 -> V_106 , V_200 - 1 , L_3 , V_176 -> V_4 . line + 1 ) ;
V_176 -> V_4 . V_5 = F_80 ( V_183 -> V_193 , F_81 ( V_183 ) ) ;
if ( ! V_176 -> V_4 . V_5 ) {
V_75 = - V_188 ;
goto V_199;
}
V_163 [ V_176 -> V_4 . line ] = V_176 ;
F_82 ( & V_171 , & V_176 -> V_4 ) ;
F_83 ( V_175 , V_176 ) ;
return 0 ;
V_199:
F_84 ( V_176 -> V_105 ) ;
V_189:
F_85 ( V_176 ) ;
return V_75 ;
}
static int F_86 ( struct V_177 * V_175 )
{
struct V_1 * V_176 = F_87 ( V_175 ) ;
F_83 ( V_175 , NULL ) ;
F_88 ( & V_171 , & V_176 -> V_4 ) ;
F_84 ( V_176 -> V_105 ) ;
F_85 ( V_176 ) ;
return 0 ;
}
int T_2 F_89 ( void )
{
int V_75 ;
V_75 = F_90 ( & V_171 ) ;
if ( V_75 != 0 )
return V_75 ;
V_75 = F_91 ( & V_201 ) ;
if ( V_75 != 0 )
F_92 ( & V_171 ) ;
return V_75 ;
}
void T_3 F_93 ( void )
{
F_94 ( & V_201 ) ;
F_92 ( & V_171 ) ;
}
