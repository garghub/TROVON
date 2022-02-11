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
V_19 = F_1 ( V_2 , V_22 ) ;
V_20 = V_23 ;
V_2 -> V_4 . V_24 . V_25 ++ ;
if ( F_9 ( * V_15 & ( V_26 | V_27 |
V_28 | V_29 ) ) ) {
if ( * V_15 & V_26 ) {
* V_15 &= ~ ( V_28 | V_27 ) ;
V_2 -> V_4 . V_24 . V_30 ++ ;
if ( F_10 ( & V_2 -> V_4 ) )
goto V_31;
} else if ( * V_15 & V_27 )
V_2 -> V_4 . V_24 . V_32 ++ ;
else if ( * V_15 & V_28 )
V_2 -> V_4 . V_24 . V_33 ++ ;
if ( * V_15 & V_29 )
V_2 -> V_4 . V_24 . V_34 ++ ;
* V_15 &= V_2 -> V_4 . V_13 ;
#ifdef F_11
if ( V_2 -> V_4 . line == V_2 -> V_4 . V_35 -> V_36 ) {
* V_15 |= V_2 -> V_37 ;
V_2 -> V_37 = 0 ;
}
#endif
if ( * V_15 & V_26 ) {
V_20 = V_38 ;
} else if ( * V_15 & V_27 )
V_20 = V_39 ;
else if ( * V_15 & V_28 )
V_20 = V_40 ;
}
if ( F_12 ( & V_2 -> V_4 , V_19 ) )
goto V_31;
F_13 ( & V_2 -> V_4 , * V_15 , V_29 , V_19 , V_20 ) ;
V_31:
* V_15 = F_1 ( V_2 , V_41 ) ;
} while ( ( * V_15 & V_14 ) && ( V_21 -- > 0 ) );
F_14 ( V_17 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = & V_2 -> V_4 . V_18 -> V_43 ;
int V_44 ;
if ( V_2 -> V_4 . V_45 ) {
F_3 ( V_2 , V_46 , V_2 -> V_4 . V_45 ) ;
V_2 -> V_4 . V_24 . V_47 ++ ;
V_2 -> V_4 . V_45 = 0 ;
return;
}
if ( F_16 ( V_43 ) || F_17 ( & V_2 -> V_4 ) ) {
F_6 ( & V_2 -> V_4 ) ;
return;
}
V_44 = V_2 -> V_4 . V_48 / 2 ;
do {
F_3 ( V_2 , V_46 , V_43 -> V_49 [ V_43 -> V_50 ] ) ;
V_43 -> V_50 = ( V_43 -> V_50 + 1 ) & ( V_51 - 1 ) ;
V_2 -> V_4 . V_24 . V_47 ++ ;
if ( F_16 ( V_43 ) )
break;
} while ( -- V_44 > 0 );
if ( F_18 ( V_43 ) < V_52 )
F_19 ( & V_2 -> V_4 ) ;
if ( F_16 ( V_43 ) )
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
V_15 = F_1 ( V_2 , V_53 ) ;
if ( ( V_15 & V_54 ) == 0 )
return;
if ( V_15 & V_55 )
V_2 -> V_4 . V_24 . V_56 ++ ;
if ( V_15 & V_57 )
V_2 -> V_4 . V_24 . V_58 ++ ;
if ( V_15 & V_59 )
F_22 ( & V_2 -> V_4 , V_15 & V_60 ) ;
if ( V_15 & V_61 )
F_23 ( & V_2 -> V_4 , V_15 & V_62 ) ;
F_24 ( & V_2 -> V_4 . V_18 -> V_4 . V_63 ) ;
}
static inline T_1 F_25 ( int V_64 , void * V_65 )
{
struct V_1 * V_2 = V_65 ;
unsigned int V_66 , V_67 ;
V_66 = F_1 ( V_2 , V_68 ) ;
if ( V_66 & V_69 )
return V_70 ;
V_67 = F_1 ( V_2 , V_41 ) ;
if ( V_67 & V_14 )
F_8 ( V_2 , & V_67 ) ;
F_21 ( V_2 ) ;
if ( V_67 & V_71 )
F_15 ( V_2 ) ;
return V_72 ;
}
static unsigned int F_26 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_73 ;
unsigned int V_74 ;
F_27 ( & V_2 -> V_4 . V_75 , V_73 ) ;
V_74 = F_1 ( V_2 , V_41 ) & V_76 ? V_77 : 0 ;
F_28 ( & V_2 -> V_4 . V_75 , V_73 ) ;
return V_74 ;
}
static unsigned int F_29 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned char V_15 ;
unsigned int V_74 ;
V_15 = F_1 ( V_2 , V_53 ) ;
V_74 = 0 ;
if ( V_15 & V_60 )
V_74 |= V_78 ;
if ( V_15 & V_79 )
V_74 |= V_80 ;
if ( V_15 & V_81 )
V_74 |= V_82 ;
if ( V_15 & V_62 )
V_74 |= V_83 ;
return V_74 ;
}
static void F_30 ( struct V_7 * V_4 , unsigned int V_84 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned char V_85 = 0 ;
if ( V_84 & V_86 )
V_85 |= V_87 ;
if ( V_84 & V_88 )
V_85 |= V_89 ;
if ( V_84 & V_90 )
V_85 |= V_91 ;
if ( V_84 & V_92 )
V_85 |= V_93 ;
if ( V_84 & V_94 )
V_85 |= V_95 ;
V_85 |= V_2 -> V_85 ;
F_3 ( V_2 , V_96 , V_85 ) ;
}
static void F_31 ( struct V_7 * V_4 , int V_97 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_73 ;
F_27 ( & V_2 -> V_4 . V_75 , V_73 ) ;
if ( V_97 == - 1 )
V_2 -> V_98 |= V_99 ;
else
V_2 -> V_98 &= ~ V_99 ;
F_3 ( V_2 , V_100 , V_2 -> V_98 ) ;
F_28 ( & V_2 -> V_4 . V_75 , V_73 ) ;
}
static int F_32 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_73 ;
int V_101 ;
if ( V_4 -> line == 3 )
V_2 -> V_85 |= V_102 ;
else
V_2 -> V_85 = 0 ;
V_2 -> V_4 . V_103 = F_33 ( V_2 -> V_104 ) ;
V_101 = F_34 ( V_2 -> V_4 . V_64 , F_25 , 0 , V_2 -> V_105 , V_2 ) ;
if ( V_101 )
return V_101 ;
F_3 ( V_2 , V_106 , V_107 ) ;
F_3 ( V_2 , V_106 , V_107 |
V_108 | V_109 ) ;
F_3 ( V_2 , V_106 , 0 ) ;
( void ) F_1 ( V_2 , V_41 ) ;
( void ) F_1 ( V_2 , V_22 ) ;
( void ) F_1 ( V_2 , V_68 ) ;
( void ) F_1 ( V_2 , V_53 ) ;
F_3 ( V_2 , V_100 , V_110 ) ;
F_27 ( & V_2 -> V_4 . V_75 , V_73 ) ;
V_2 -> V_4 . V_84 |= V_92 ;
F_30 ( & V_2 -> V_4 , V_2 -> V_4 . V_84 ) ;
F_28 ( & V_2 -> V_4 . V_75 , V_73 ) ;
V_2 -> V_8 = V_12 | V_111 | V_112 | V_113 ;
F_3 ( V_2 , V_10 , V_2 -> V_8 ) ;
( void ) F_1 ( V_2 , V_41 ) ;
( void ) F_1 ( V_2 , V_22 ) ;
( void ) F_1 ( V_2 , V_68 ) ;
( void ) F_1 ( V_2 , V_53 ) ;
return 0 ;
}
static void F_35 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_73 ;
F_36 ( V_2 -> V_4 . V_64 , V_2 ) ;
V_2 -> V_8 = 0 ;
F_3 ( V_2 , V_10 , 0 ) ;
F_27 ( & V_2 -> V_4 . V_75 , V_73 ) ;
V_2 -> V_4 . V_84 &= ~ V_92 ;
F_30 ( & V_2 -> V_4 , V_2 -> V_4 . V_84 ) ;
F_28 ( & V_2 -> V_4 . V_75 , V_73 ) ;
F_3 ( V_2 , V_100 , F_1 ( V_2 , V_100 ) & ~ V_99 ) ;
F_3 ( V_2 , V_106 , V_107 |
V_108 |
V_109 ) ;
F_3 ( V_2 , V_106 , 0 ) ;
}
static void
F_37 ( struct V_7 * V_4 , struct V_114 * V_115 ,
struct V_114 * V_116 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned char V_117 , V_118 = 0 ;
unsigned long V_73 ;
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
V_117 = V_110 ;
break;
}
if ( V_115 -> V_122 & V_131 )
V_117 |= V_132 ;
if ( V_115 -> V_122 & V_133 )
V_117 |= V_134 ;
if ( ! ( V_115 -> V_122 & V_135 ) )
V_117 |= V_136 ;
V_119 = F_38 ( V_4 , V_115 , V_116 , 0 , V_4 -> V_103 / 16 ) ;
V_120 = F_39 ( V_4 , V_119 ) ;
if ( ( V_2 -> V_4 . V_103 / V_120 ) < ( 2400 * 16 ) )
V_118 = V_107 | V_137 ;
else if ( ( V_2 -> V_4 . V_103 / V_120 ) < ( 230400 * 16 ) )
V_118 = V_107 | V_138 ;
else
V_118 = V_107 | V_139 ;
F_27 ( & V_2 -> V_4 . V_75 , V_73 ) ;
V_2 -> V_8 |= V_113 ;
F_40 ( V_4 , V_115 -> V_122 , V_119 ) ;
V_2 -> V_4 . V_13 = V_29 | V_71 | V_14 ;
if ( V_115 -> V_140 & V_141 )
V_2 -> V_4 . V_13 |= V_28 | V_27 ;
if ( V_115 -> V_140 & ( V_142 | V_143 ) )
V_2 -> V_4 . V_13 |= V_26 ;
V_2 -> V_4 . V_144 = 0 ;
if ( V_115 -> V_140 & V_145 )
V_2 -> V_4 . V_144 |= V_27 | V_28 ;
if ( V_115 -> V_140 & V_146 ) {
V_2 -> V_4 . V_144 |= V_26 ;
if ( V_115 -> V_140 & V_145 )
V_2 -> V_4 . V_144 |= V_29 ;
}
if ( ( V_115 -> V_122 & V_147 ) == 0 )
V_2 -> V_4 . V_144 |= V_14 ;
V_2 -> V_8 &= ~ V_9 ;
if ( F_41 ( & V_2 -> V_4 , V_115 -> V_122 ) )
V_2 -> V_8 |= V_9 ;
F_3 ( V_2 , V_10 , V_2 -> V_8 ) ;
if ( V_115 -> V_122 & V_148 )
V_2 -> V_85 |= V_102 ;
else
V_2 -> V_85 &= ~ V_102 ;
F_3 ( V_2 , V_100 , V_117 | V_149 ) ;
F_3 ( V_2 , V_150 , V_120 & 0xff ) ;
V_121 = F_1 ( V_2 , V_150 ) ;
F_42 ( V_121 != ( V_120 & 0xff ) ) ;
F_3 ( V_2 , V_151 , V_120 >> 8 ) ;
F_3 ( V_2 , V_100 , V_117 ) ;
V_2 -> V_98 = V_117 ;
F_30 ( & V_2 -> V_4 , V_2 -> V_4 . V_84 ) ;
F_3 ( V_2 , V_106 , V_118 ) ;
F_28 ( & V_2 -> V_4 . V_75 , V_73 ) ;
}
static void
F_43 ( struct V_7 * V_4 , unsigned int V_18 ,
unsigned int V_152 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
if ( ! V_18 )
F_44 ( V_2 -> V_104 ) ;
else
F_45 ( V_2 -> V_104 ) ;
}
static void F_46 ( struct V_7 * V_4 )
{
}
static int F_47 ( struct V_7 * V_4 )
{
return 0 ;
}
static void F_48 ( struct V_7 * V_4 , int V_73 )
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
return V_2 -> V_105 ;
}
static inline void F_51 ( struct V_1 * V_2 )
{
unsigned int V_15 , V_157 = 10000 ;
do {
V_15 = F_1 ( V_2 , V_41 ) ;
if ( V_15 & V_26 )
V_2 -> V_37 = V_26 ;
if ( -- V_157 == 0 )
break;
F_52 ( 1 ) ;
} while ( ( V_15 & V_158 ) != V_158 );
if ( V_2 -> V_4 . V_73 & V_159 ) {
V_157 = 1000000 ;
while ( -- V_157 &&
( ( F_1 ( V_2 , V_53 ) & V_62 ) == 0 ) )
F_52 ( 1 ) ;
}
}
static void F_53 ( struct V_7 * V_4 , int V_19 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
F_51 ( V_2 ) ;
F_3 ( V_2 , V_46 , V_19 ) ;
}
static void
F_54 ( struct V_160 * V_161 , const char * V_162 , unsigned int V_44 )
{
struct V_1 * V_2 = V_163 [ V_161 -> V_36 ] ;
unsigned int V_8 ;
F_44 ( V_2 -> V_104 ) ;
V_8 = F_1 ( V_2 , V_10 ) ;
F_3 ( V_2 , V_10 , V_113 ) ;
F_55 ( & V_2 -> V_4 , V_162 , V_44 , F_53 ) ;
F_51 ( V_2 ) ;
F_3 ( V_2 , V_10 , V_8 ) ;
F_45 ( V_2 -> V_104 ) ;
}
static int T_2
F_56 ( struct V_160 * V_161 , char * V_164 )
{
struct V_1 * V_2 ;
int V_119 = 9600 ;
int V_165 = 8 ;
int V_32 = 'n' ;
int V_166 = 'n' ;
if ( V_161 -> V_36 == - 1 || V_161 -> V_36 >= V_167 . V_168 )
V_161 -> V_36 = 0 ;
V_2 = V_163 [ V_161 -> V_36 ] ;
if ( ! V_2 )
return - V_169 ;
if ( V_164 )
F_57 ( V_164 , & V_119 , & V_32 , & V_165 , & V_166 ) ;
return F_58 ( & V_2 -> V_4 , V_161 , V_119 , V_32 , V_165 , V_166 ) ;
}
static int F_59 ( struct V_170 * V_171 )
{
struct V_1 * V_172 = F_60 ( V_171 ) ;
if ( V_172 )
F_61 ( & V_167 , & V_172 -> V_4 ) ;
return 0 ;
}
static int F_62 ( struct V_170 * V_171 )
{
struct V_1 * V_172 = F_60 ( V_171 ) ;
if ( V_172 )
F_63 ( & V_167 , & V_172 -> V_4 ) ;
return 0 ;
}
static int F_64 ( struct V_173 * V_171 )
{
struct V_1 * V_172 ;
struct V_174 * V_175 , * V_176 ;
int V_74 ;
V_175 = F_65 ( V_171 , V_177 , 0 ) ;
V_176 = F_65 ( V_171 , V_178 , 0 ) ;
if ( ! V_175 || ! V_176 )
return - V_169 ;
V_172 = F_66 ( sizeof( struct V_1 ) , V_179 ) ;
if ( ! V_172 )
return - V_180 ;
V_172 -> V_104 = F_67 ( & V_171 -> V_171 , NULL ) ;
if ( F_68 ( V_172 -> V_104 ) ) {
V_74 = F_69 ( V_172 -> V_104 ) ;
goto V_181;
}
V_172 -> V_4 . type = V_153 ;
V_172 -> V_4 . V_182 = V_183 ;
V_172 -> V_4 . V_184 = V_175 -> V_185 ;
V_172 -> V_4 . V_64 = V_176 -> V_185 ;
V_172 -> V_4 . V_48 = 64 ;
V_172 -> V_4 . V_186 = & V_187 ;
V_172 -> V_4 . line = V_171 -> V_188 ;
V_172 -> V_4 . V_171 = & V_171 -> V_171 ;
V_172 -> V_4 . V_73 = V_189 | V_190 ;
V_172 -> V_4 . V_103 = F_33 ( V_172 -> V_104 ) ;
switch ( V_171 -> V_188 ) {
case 0 : V_172 -> V_105 = L_1 ; break;
case 1 : V_172 -> V_105 = L_2 ; break;
case 2 : V_172 -> V_105 = L_3 ; break;
case 3 : V_172 -> V_105 = L_4 ; break;
default:
V_172 -> V_105 = L_5 ;
break;
}
V_172 -> V_4 . V_5 = F_70 ( V_175 -> V_185 , V_175 -> V_191 - V_175 -> V_185 + 1 ) ;
if ( ! V_172 -> V_4 . V_5 ) {
V_74 = - V_180 ;
goto V_192;
}
V_163 [ V_171 -> V_188 ] = V_172 ;
F_71 ( & V_167 , & V_172 -> V_4 ) ;
F_72 ( V_171 , V_172 ) ;
return 0 ;
V_192:
F_73 ( V_172 -> V_104 ) ;
V_181:
F_74 ( V_172 ) ;
return V_74 ;
}
static int F_75 ( struct V_173 * V_171 )
{
struct V_1 * V_172 = F_76 ( V_171 ) ;
F_72 ( V_171 , NULL ) ;
F_77 ( & V_167 , & V_172 -> V_4 ) ;
F_73 ( V_172 -> V_104 ) ;
F_74 ( V_172 ) ;
return 0 ;
}
int T_2 F_78 ( void )
{
int V_74 ;
V_74 = F_79 ( & V_167 ) ;
if ( V_74 != 0 )
return V_74 ;
V_74 = F_80 ( & V_193 ) ;
if ( V_74 != 0 )
F_81 ( & V_167 ) ;
return V_74 ;
}
void T_3 F_82 ( void )
{
F_83 ( & V_193 ) ;
F_81 ( & V_167 ) ;
}
