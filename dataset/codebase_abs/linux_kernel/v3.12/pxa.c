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
unsigned int V_16 , V_17 ;
int V_18 = 256 ;
do {
V_2 -> V_8 &= ~ V_19 ;
F_3 ( V_2 , V_10 , V_2 -> V_8 ) ;
V_16 = F_1 ( V_2 , V_20 ) ;
V_17 = V_21 ;
V_2 -> V_4 . V_22 . V_23 ++ ;
if ( F_9 ( * V_15 & ( V_24 | V_25 |
V_26 | V_27 ) ) ) {
if ( * V_15 & V_24 ) {
* V_15 &= ~ ( V_26 | V_25 ) ;
V_2 -> V_4 . V_22 . V_28 ++ ;
if ( F_10 ( & V_2 -> V_4 ) )
goto V_29;
} else if ( * V_15 & V_25 )
V_2 -> V_4 . V_22 . V_30 ++ ;
else if ( * V_15 & V_26 )
V_2 -> V_4 . V_22 . V_31 ++ ;
if ( * V_15 & V_27 )
V_2 -> V_4 . V_22 . V_32 ++ ;
* V_15 &= V_2 -> V_4 . V_13 ;
#ifdef F_11
if ( V_2 -> V_4 . line == V_2 -> V_4 . V_33 -> V_34 ) {
* V_15 |= V_2 -> V_35 ;
V_2 -> V_35 = 0 ;
}
#endif
if ( * V_15 & V_24 ) {
V_17 = V_36 ;
} else if ( * V_15 & V_25 )
V_17 = V_37 ;
else if ( * V_15 & V_26 )
V_17 = V_38 ;
}
if ( F_12 ( & V_2 -> V_4 , V_16 ) )
goto V_29;
F_13 ( & V_2 -> V_4 , * V_15 , V_27 , V_16 , V_17 ) ;
V_29:
* V_15 = F_1 ( V_2 , V_39 ) ;
} while ( ( * V_15 & V_14 ) && ( V_18 -- > 0 ) );
F_14 ( & V_2 -> V_4 . V_40 -> V_4 ) ;
V_2 -> V_8 |= V_19 ;
F_3 ( V_2 , V_10 , V_2 -> V_8 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = & V_2 -> V_4 . V_40 -> V_42 ;
int V_43 ;
if ( V_2 -> V_4 . V_44 ) {
F_3 ( V_2 , V_45 , V_2 -> V_4 . V_44 ) ;
V_2 -> V_4 . V_22 . V_46 ++ ;
V_2 -> V_4 . V_44 = 0 ;
return;
}
if ( F_16 ( V_42 ) || F_17 ( & V_2 -> V_4 ) ) {
F_6 ( & V_2 -> V_4 ) ;
return;
}
V_43 = V_2 -> V_4 . V_47 / 2 ;
do {
F_3 ( V_2 , V_45 , V_42 -> V_48 [ V_42 -> V_49 ] ) ;
V_42 -> V_49 = ( V_42 -> V_49 + 1 ) & ( V_50 - 1 ) ;
V_2 -> V_4 . V_22 . V_46 ++ ;
if ( F_16 ( V_42 ) )
break;
} while ( -- V_43 > 0 );
if ( F_18 ( V_42 ) < V_51 )
F_19 ( & V_2 -> V_4 ) ;
if ( F_16 ( V_42 ) )
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
V_15 = F_1 ( V_2 , V_52 ) ;
if ( ( V_15 & V_53 ) == 0 )
return;
if ( V_15 & V_54 )
V_2 -> V_4 . V_22 . V_55 ++ ;
if ( V_15 & V_56 )
V_2 -> V_4 . V_22 . V_57 ++ ;
if ( V_15 & V_58 )
F_22 ( & V_2 -> V_4 , V_15 & V_59 ) ;
if ( V_15 & V_60 )
F_23 ( & V_2 -> V_4 , V_15 & V_61 ) ;
F_24 ( & V_2 -> V_4 . V_40 -> V_4 . V_62 ) ;
}
static inline T_1 F_25 ( int V_63 , void * V_64 )
{
struct V_1 * V_2 = V_64 ;
unsigned int V_65 , V_66 ;
V_65 = F_1 ( V_2 , V_67 ) ;
if ( V_65 & V_68 )
return V_69 ;
V_66 = F_1 ( V_2 , V_39 ) ;
if ( V_66 & V_14 )
F_8 ( V_2 , & V_66 ) ;
F_21 ( V_2 ) ;
if ( V_66 & V_70 )
F_15 ( V_2 ) ;
return V_71 ;
}
static unsigned int F_26 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_72 ;
unsigned int V_73 ;
F_27 ( & V_2 -> V_4 . V_74 , V_72 ) ;
V_73 = F_1 ( V_2 , V_39 ) & V_75 ? V_76 : 0 ;
F_28 ( & V_2 -> V_4 . V_74 , V_72 ) ;
return V_73 ;
}
static unsigned int F_29 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned char V_15 ;
unsigned int V_73 ;
V_15 = F_1 ( V_2 , V_52 ) ;
V_73 = 0 ;
if ( V_15 & V_59 )
V_73 |= V_77 ;
if ( V_15 & V_78 )
V_73 |= V_79 ;
if ( V_15 & V_80 )
V_73 |= V_81 ;
if ( V_15 & V_61 )
V_73 |= V_82 ;
return V_73 ;
}
static void F_30 ( struct V_7 * V_4 , unsigned int V_83 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned char V_84 = 0 ;
if ( V_83 & V_85 )
V_84 |= V_86 ;
if ( V_83 & V_87 )
V_84 |= V_88 ;
if ( V_83 & V_89 )
V_84 |= V_90 ;
if ( V_83 & V_91 )
V_84 |= V_92 ;
if ( V_83 & V_93 )
V_84 |= V_94 ;
V_84 |= V_2 -> V_84 ;
F_3 ( V_2 , V_95 , V_84 ) ;
}
static void F_31 ( struct V_7 * V_4 , int V_96 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_72 ;
F_27 ( & V_2 -> V_4 . V_74 , V_72 ) ;
if ( V_96 == - 1 )
V_2 -> V_97 |= V_98 ;
else
V_2 -> V_97 &= ~ V_98 ;
F_3 ( V_2 , V_99 , V_2 -> V_97 ) ;
F_28 ( & V_2 -> V_4 . V_74 , V_72 ) ;
}
static int F_32 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_72 ;
int V_100 ;
if ( V_4 -> line == 3 )
V_2 -> V_84 |= V_101 ;
else
V_2 -> V_84 = 0 ;
V_2 -> V_4 . V_102 = F_33 ( V_2 -> V_103 ) ;
V_100 = F_34 ( V_2 -> V_4 . V_63 , F_25 , 0 , V_2 -> V_104 , V_2 ) ;
if ( V_100 )
return V_100 ;
F_3 ( V_2 , V_105 , V_106 ) ;
F_3 ( V_2 , V_105 , V_106 |
V_107 | V_108 ) ;
F_3 ( V_2 , V_105 , 0 ) ;
( void ) F_1 ( V_2 , V_39 ) ;
( void ) F_1 ( V_2 , V_20 ) ;
( void ) F_1 ( V_2 , V_67 ) ;
( void ) F_1 ( V_2 , V_52 ) ;
F_3 ( V_2 , V_99 , V_109 ) ;
F_27 ( & V_2 -> V_4 . V_74 , V_72 ) ;
V_2 -> V_4 . V_83 |= V_91 ;
F_30 ( & V_2 -> V_4 , V_2 -> V_4 . V_83 ) ;
F_28 ( & V_2 -> V_4 . V_74 , V_72 ) ;
V_2 -> V_8 = V_12 | V_110 | V_19 | V_111 ;
F_3 ( V_2 , V_10 , V_2 -> V_8 ) ;
( void ) F_1 ( V_2 , V_39 ) ;
( void ) F_1 ( V_2 , V_20 ) ;
( void ) F_1 ( V_2 , V_67 ) ;
( void ) F_1 ( V_2 , V_52 ) ;
return 0 ;
}
static void F_35 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_72 ;
F_36 ( V_2 -> V_4 . V_63 , V_2 ) ;
V_2 -> V_8 = 0 ;
F_3 ( V_2 , V_10 , 0 ) ;
F_27 ( & V_2 -> V_4 . V_74 , V_72 ) ;
V_2 -> V_4 . V_83 &= ~ V_91 ;
F_30 ( & V_2 -> V_4 , V_2 -> V_4 . V_83 ) ;
F_28 ( & V_2 -> V_4 . V_74 , V_72 ) ;
F_3 ( V_2 , V_99 , F_1 ( V_2 , V_99 ) & ~ V_98 ) ;
F_3 ( V_2 , V_105 , V_106 |
V_107 |
V_108 ) ;
F_3 ( V_2 , V_105 , 0 ) ;
}
static void
F_37 ( struct V_7 * V_4 , struct V_112 * V_113 ,
struct V_112 * V_114 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned char V_115 , V_116 = 0 ;
unsigned long V_72 ;
unsigned int V_117 , V_118 ;
unsigned int V_119 ;
switch ( V_113 -> V_120 & V_121 ) {
case V_122 :
V_115 = V_123 ;
break;
case V_124 :
V_115 = V_125 ;
break;
case V_126 :
V_115 = V_127 ;
break;
default:
case V_128 :
V_115 = V_109 ;
break;
}
if ( V_113 -> V_120 & V_129 )
V_115 |= V_130 ;
if ( V_113 -> V_120 & V_131 )
V_115 |= V_132 ;
if ( ! ( V_113 -> V_120 & V_133 ) )
V_115 |= V_134 ;
V_117 = F_38 ( V_4 , V_113 , V_114 , 0 , V_4 -> V_102 / 16 ) ;
V_118 = F_39 ( V_4 , V_117 ) ;
if ( ( V_2 -> V_4 . V_102 / V_118 ) < ( 2400 * 16 ) )
V_116 = V_106 | V_135 ;
else if ( ( V_2 -> V_4 . V_102 / V_118 ) < ( 230400 * 16 ) )
V_116 = V_106 | V_136 ;
else
V_116 = V_106 | V_137 ;
F_27 ( & V_2 -> V_4 . V_74 , V_72 ) ;
V_2 -> V_8 |= V_111 ;
F_40 ( V_4 , V_113 -> V_120 , V_117 ) ;
V_2 -> V_4 . V_13 = V_27 | V_70 | V_14 ;
if ( V_113 -> V_138 & V_139 )
V_2 -> V_4 . V_13 |= V_26 | V_25 ;
if ( V_113 -> V_138 & ( V_140 | V_141 ) )
V_2 -> V_4 . V_13 |= V_24 ;
V_2 -> V_4 . V_142 = 0 ;
if ( V_113 -> V_138 & V_143 )
V_2 -> V_4 . V_142 |= V_25 | V_26 ;
if ( V_113 -> V_138 & V_144 ) {
V_2 -> V_4 . V_142 |= V_24 ;
if ( V_113 -> V_138 & V_143 )
V_2 -> V_4 . V_142 |= V_27 ;
}
if ( ( V_113 -> V_120 & V_145 ) == 0 )
V_2 -> V_4 . V_142 |= V_14 ;
V_2 -> V_8 &= ~ V_9 ;
if ( F_41 ( & V_2 -> V_4 , V_113 -> V_120 ) )
V_2 -> V_8 |= V_9 ;
F_3 ( V_2 , V_10 , V_2 -> V_8 ) ;
if ( V_113 -> V_120 & V_146 )
V_2 -> V_84 |= V_101 ;
else
V_2 -> V_84 &= ~ V_101 ;
F_3 ( V_2 , V_99 , V_115 | V_147 ) ;
F_3 ( V_2 , V_148 , V_118 & 0xff ) ;
V_119 = F_1 ( V_2 , V_148 ) ;
F_42 ( V_119 != ( V_118 & 0xff ) ) ;
F_3 ( V_2 , V_149 , V_118 >> 8 ) ;
F_3 ( V_2 , V_99 , V_115 ) ;
V_2 -> V_97 = V_115 ;
F_30 ( & V_2 -> V_4 , V_2 -> V_4 . V_83 ) ;
F_3 ( V_2 , V_105 , V_116 ) ;
F_28 ( & V_2 -> V_4 . V_74 , V_72 ) ;
}
static void
F_43 ( struct V_7 * V_4 , unsigned int V_40 ,
unsigned int V_150 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
if ( ! V_40 )
F_44 ( V_2 -> V_103 ) ;
else
F_45 ( V_2 -> V_103 ) ;
}
static void F_46 ( struct V_7 * V_4 )
{
}
static int F_47 ( struct V_7 * V_4 )
{
return 0 ;
}
static void F_48 ( struct V_7 * V_4 , int V_72 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
V_2 -> V_4 . type = V_151 ;
}
static int
F_49 ( struct V_7 * V_4 , struct V_152 * V_153 )
{
return - V_154 ;
}
static const char *
F_50 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
return V_2 -> V_104 ;
}
static inline void F_51 ( struct V_1 * V_2 )
{
unsigned int V_15 , V_155 = 10000 ;
do {
V_15 = F_1 ( V_2 , V_39 ) ;
if ( V_15 & V_24 )
V_2 -> V_35 = V_24 ;
if ( -- V_155 == 0 )
break;
F_52 ( 1 ) ;
} while ( ( V_15 & V_156 ) != V_156 );
if ( V_2 -> V_4 . V_72 & V_157 ) {
V_155 = 1000000 ;
while ( -- V_155 &&
( ( F_1 ( V_2 , V_52 ) & V_61 ) == 0 ) )
F_52 ( 1 ) ;
}
}
static void F_53 ( struct V_7 * V_4 , int V_16 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
F_51 ( V_2 ) ;
F_3 ( V_2 , V_45 , V_16 ) ;
}
static void
F_54 ( struct V_158 * V_159 , const char * V_160 , unsigned int V_43 )
{
struct V_1 * V_2 = V_161 [ V_159 -> V_34 ] ;
unsigned int V_8 ;
unsigned long V_72 ;
int V_162 = 1 ;
F_55 ( V_2 -> V_103 ) ;
F_56 ( V_72 ) ;
if ( V_2 -> V_4 . V_163 )
V_162 = 0 ;
else if ( V_164 )
V_162 = F_57 ( & V_2 -> V_4 . V_74 ) ;
else
F_58 ( & V_2 -> V_4 . V_74 ) ;
V_8 = F_1 ( V_2 , V_10 ) ;
F_3 ( V_2 , V_10 , V_111 ) ;
F_59 ( & V_2 -> V_4 , V_160 , V_43 , F_53 ) ;
F_51 ( V_2 ) ;
F_3 ( V_2 , V_10 , V_8 ) ;
if ( V_162 )
F_60 ( & V_2 -> V_4 . V_74 ) ;
F_61 ( V_72 ) ;
F_62 ( V_2 -> V_103 ) ;
}
static int F_63 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned char V_66 = F_1 ( V_2 , V_39 ) ;
while ( ! ( V_66 & V_14 ) )
V_66 = F_1 ( V_2 , V_39 ) ;
return F_1 ( V_2 , V_20 ) ;
}
static void F_64 ( struct V_7 * V_4 ,
unsigned char V_165 )
{
unsigned int V_8 ;
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
V_8 = F_1 ( V_2 , V_10 ) ;
F_3 ( V_2 , V_10 , V_111 ) ;
F_51 ( V_2 ) ;
F_3 ( V_2 , V_45 , V_165 ) ;
if ( V_165 == 10 ) {
F_51 ( V_2 ) ;
F_3 ( V_2 , V_45 , 13 ) ;
}
F_51 ( V_2 ) ;
F_3 ( V_2 , V_10 , V_8 ) ;
}
static int T_2
F_65 ( struct V_158 * V_159 , char * V_166 )
{
struct V_1 * V_2 ;
int V_117 = 9600 ;
int V_167 = 8 ;
int V_30 = 'n' ;
int V_168 = 'n' ;
if ( V_159 -> V_34 == - 1 || V_159 -> V_34 >= V_169 . V_170 )
V_159 -> V_34 = 0 ;
V_2 = V_161 [ V_159 -> V_34 ] ;
if ( ! V_2 )
return - V_171 ;
if ( V_166 )
F_66 ( V_166 , & V_117 , & V_30 , & V_167 , & V_168 ) ;
return F_67 ( & V_2 -> V_4 , V_159 , V_117 , V_30 , V_167 , V_168 ) ;
}
static int F_68 ( struct V_172 * V_173 )
{
struct V_1 * V_174 = F_69 ( V_173 ) ;
if ( V_174 )
F_70 ( & V_169 , & V_174 -> V_4 ) ;
return 0 ;
}
static int F_71 ( struct V_172 * V_173 )
{
struct V_1 * V_174 = F_69 ( V_173 ) ;
if ( V_174 )
F_72 ( & V_169 , & V_174 -> V_4 ) ;
return 0 ;
}
static int F_73 ( struct V_175 * V_176 ,
struct V_1 * V_174 )
{
struct V_177 * V_178 = V_176 -> V_173 . V_179 ;
int V_73 ;
if ( ! V_178 )
return 1 ;
V_73 = F_74 ( V_178 , L_1 ) ;
if ( V_73 < 0 ) {
F_75 ( & V_176 -> V_173 , L_2 , V_73 ) ;
return V_73 ;
}
V_174 -> V_4 . line = V_73 ;
return 0 ;
}
static int F_76 ( struct V_175 * V_173 )
{
struct V_1 * V_174 ;
struct V_180 * V_181 , * V_182 ;
int V_73 ;
V_181 = F_77 ( V_173 , V_183 , 0 ) ;
V_182 = F_77 ( V_173 , V_184 , 0 ) ;
if ( ! V_181 || ! V_182 )
return - V_171 ;
V_174 = F_78 ( sizeof( struct V_1 ) , V_185 ) ;
if ( ! V_174 )
return - V_186 ;
V_174 -> V_103 = F_79 ( & V_173 -> V_173 , NULL ) ;
if ( F_80 ( V_174 -> V_103 ) ) {
V_73 = F_81 ( V_174 -> V_103 ) ;
goto V_187;
}
V_73 = F_82 ( V_174 -> V_103 ) ;
if ( V_73 ) {
F_83 ( V_174 -> V_103 ) ;
goto V_187;
}
V_174 -> V_4 . type = V_151 ;
V_174 -> V_4 . V_188 = V_189 ;
V_174 -> V_4 . V_190 = V_181 -> V_191 ;
V_174 -> V_4 . V_63 = V_182 -> V_191 ;
V_174 -> V_4 . V_47 = 64 ;
V_174 -> V_4 . V_192 = & V_193 ;
V_174 -> V_4 . V_173 = & V_173 -> V_173 ;
V_174 -> V_4 . V_72 = V_194 | V_195 ;
V_174 -> V_4 . V_102 = F_33 ( V_174 -> V_103 ) ;
V_73 = F_73 ( V_173 , V_174 ) ;
if ( V_73 > 0 )
V_174 -> V_4 . line = V_173 -> V_196 ;
else if ( V_73 < 0 )
goto V_197;
snprintf ( V_174 -> V_104 , V_198 - 1 , L_3 , V_174 -> V_4 . line + 1 ) ;
V_174 -> V_4 . V_5 = F_84 ( V_181 -> V_191 , F_85 ( V_181 ) ) ;
if ( ! V_174 -> V_4 . V_5 ) {
V_73 = - V_186 ;
goto V_197;
}
V_161 [ V_174 -> V_4 . line ] = V_174 ;
F_86 ( & V_169 , & V_174 -> V_4 ) ;
F_87 ( V_173 , V_174 ) ;
return 0 ;
V_197:
F_88 ( V_174 -> V_103 ) ;
F_83 ( V_174 -> V_103 ) ;
V_187:
F_89 ( V_174 ) ;
return V_73 ;
}
static int F_90 ( struct V_175 * V_173 )
{
struct V_1 * V_174 = F_91 ( V_173 ) ;
F_92 ( & V_169 , & V_174 -> V_4 ) ;
F_88 ( V_174 -> V_103 ) ;
F_83 ( V_174 -> V_103 ) ;
F_89 ( V_174 ) ;
return 0 ;
}
static int T_2 F_93 ( void )
{
int V_73 ;
V_73 = F_94 ( & V_169 ) ;
if ( V_73 != 0 )
return V_73 ;
V_73 = F_95 ( & V_199 ) ;
if ( V_73 != 0 )
F_96 ( & V_169 ) ;
return V_73 ;
}
static void T_3 F_97 ( void )
{
F_98 ( & V_199 ) ;
F_96 ( & V_169 ) ;
}
