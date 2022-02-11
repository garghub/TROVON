void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( ! V_2 ) ;
F_3 ( & V_4 ) ;
V_3 ? F_4 ( & V_2 -> V_5 , & V_6 ) :
F_5 ( & V_2 -> V_5 , & V_6 ) ;
F_6 ( & V_4 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
F_3 ( & V_4 ) ;
F_8 ( & V_2 -> V_5 ) ;
F_6 ( & V_4 ) ;
}
static inline void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_7 ) ;
}
static void F_11 ( struct V_8 * V_9 , unsigned long V_10 )
{
struct V_11 * V_12 = V_13 -> V_12 ;
long V_14 = ( long ) ( V_10 - V_9 -> V_15 ) ;
if ( ! V_12 || ! V_14 )
return;
V_9 -> V_15 = V_10 ;
F_12 ( V_12 , V_16 , V_14 ) ;
}
static struct V_17 * F_13 ( struct V_8 * V_9 , unsigned long V_18 ,
int V_19 )
{
struct V_17 * V_17 ;
int V_20 ;
#ifdef F_14
if ( V_19 ) {
V_20 = F_15 ( V_9 -> V_21 , V_18 ) ;
if ( V_20 < 0 )
return NULL ;
}
#endif
V_20 = F_16 ( V_13 , V_9 -> V_12 , V_18 ,
1 , V_19 , 1 , & V_17 , NULL ) ;
if ( V_20 <= 0 )
return NULL ;
if ( V_19 ) {
unsigned long V_22 = V_9 -> V_21 -> V_23 - V_9 -> V_21 -> V_24 ;
struct V_25 * V_26 ;
F_11 ( V_9 , V_22 / V_27 ) ;
if ( V_22 <= V_28 )
return V_17 ;
V_26 = V_13 -> signal -> V_26 ;
if ( V_22 > F_17 ( V_26 [ V_29 ] . V_30 ) / 4 ) {
F_18 ( V_17 ) ;
return NULL ;
}
}
return V_17 ;
}
static void F_19 ( struct V_17 * V_17 )
{
F_18 ( V_17 ) ;
}
static void F_20 ( struct V_8 * V_9 , int V_31 )
{
}
static void F_21 ( struct V_8 * V_9 )
{
}
static void F_22 ( struct V_8 * V_9 , unsigned long V_18 ,
struct V_17 * V_17 )
{
F_23 ( V_9 -> V_21 , V_18 , F_24 ( V_17 ) ) ;
}
static int F_25 ( struct V_8 * V_9 )
{
int V_32 ;
struct V_33 * V_21 = NULL ;
struct V_11 * V_12 = V_9 -> V_12 ;
V_9 -> V_21 = V_21 = F_26 ( V_34 , V_35 ) ;
if ( ! V_21 )
return - V_36 ;
F_27 ( & V_12 -> V_37 ) ;
V_21 -> V_38 = V_12 ;
F_28 ( V_39 & V_40 ) ;
V_21 -> V_23 = V_41 ;
V_21 -> V_24 = V_21 -> V_23 - V_27 ;
V_21 -> V_42 = V_39 | V_40 ;
V_21 -> V_43 = F_29 ( V_21 -> V_42 ) ;
F_30 ( & V_21 -> V_44 ) ;
V_32 = F_31 ( V_12 , V_21 ) ;
if ( V_32 )
goto V_32;
V_12 -> V_45 = V_12 -> V_46 = 1 ;
F_32 ( & V_12 -> V_37 ) ;
V_9 -> V_47 = V_21 -> V_23 - sizeof( void * ) ;
return 0 ;
V_32:
F_32 ( & V_12 -> V_37 ) ;
V_9 -> V_21 = NULL ;
F_33 ( V_34 , V_21 ) ;
return V_32 ;
}
static bool F_34 ( struct V_8 * V_9 , long V_48 )
{
return V_48 <= V_49 ;
}
static inline void F_11 ( struct V_8 * V_9 , unsigned long V_10 )
{
}
static struct V_17 * F_13 ( struct V_8 * V_9 , unsigned long V_18 ,
int V_19 )
{
struct V_17 * V_17 ;
V_17 = V_9 -> V_17 [ V_18 / V_27 ] ;
if ( ! V_17 && V_19 ) {
V_17 = F_35 ( V_50 | V_51 ) ;
if ( ! V_17 )
return NULL ;
V_9 -> V_17 [ V_18 / V_27 ] = V_17 ;
}
return V_17 ;
}
static void F_19 ( struct V_17 * V_17 )
{
}
static void F_20 ( struct V_8 * V_9 , int V_31 )
{
if ( V_9 -> V_17 [ V_31 ] ) {
F_36 ( V_9 -> V_17 [ V_31 ] ) ;
V_9 -> V_17 [ V_31 ] = NULL ;
}
}
static void F_21 ( struct V_8 * V_9 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_52 ; V_31 ++ )
F_20 ( V_9 , V_31 ) ;
}
static void F_22 ( struct V_8 * V_9 , unsigned long V_18 ,
struct V_17 * V_17 )
{
}
static int F_25 ( struct V_8 * V_9 )
{
V_9 -> V_47 = V_27 * V_52 - sizeof( void * ) ;
return 0 ;
}
static bool F_34 ( struct V_8 * V_9 , long V_48 )
{
return V_48 <= V_9 -> V_47 ;
}
int F_37 ( struct V_8 * V_9 )
{
int V_32 ;
struct V_11 * V_12 = NULL ;
V_9 -> V_12 = V_12 = F_38 () ;
V_32 = - V_36 ;
if ( ! V_12 )
goto V_32;
V_32 = F_39 ( V_13 , V_12 ) ;
if ( V_32 )
goto V_32;
V_32 = F_25 ( V_9 ) ;
if ( V_32 )
goto V_32;
return 0 ;
V_32:
if ( V_12 ) {
V_9 -> V_12 = NULL ;
F_40 ( V_12 ) ;
}
return V_32 ;
}
static const char T_1 * F_41 ( struct V_53 V_54 , int V_55 )
{
const char T_1 * V_56 ;
#ifdef F_42
if ( F_43 ( V_54 . V_57 ) ) {
T_2 V_58 ;
if ( F_44 ( V_58 , V_54 . V_59 . V_58 + V_55 ) )
return F_45 ( - V_60 ) ;
return F_46 ( V_58 ) ;
}
#endif
if ( F_44 ( V_56 , V_54 . V_59 . V_56 + V_55 ) )
return F_45 ( - V_60 ) ;
return V_56 ;
}
static int F_47 ( struct V_53 V_54 , int V_61 )
{
int V_31 = 0 ;
if ( V_54 . V_59 . V_56 != NULL ) {
for (; ; ) {
const char T_1 * V_47 = F_41 ( V_54 , V_31 ) ;
if ( ! V_47 )
break;
if ( F_48 ( V_47 ) )
return - V_60 ;
if ( V_31 ++ >= V_61 )
return - V_62 ;
if ( F_49 ( V_13 ) )
return - V_63 ;
F_50 () ;
}
}
return V_31 ;
}
static int F_51 ( int V_64 , struct V_53 V_54 ,
struct V_8 * V_9 )
{
struct V_17 * V_65 = NULL ;
char * V_66 = NULL ;
unsigned long V_67 = 0 ;
int V_20 ;
while ( V_64 -- > 0 ) {
const char T_1 * V_68 ;
int V_48 ;
unsigned long V_18 ;
V_20 = - V_60 ;
V_68 = F_41 ( V_54 , V_64 ) ;
if ( F_48 ( V_68 ) )
goto V_69;
V_48 = F_52 ( V_68 , V_49 ) ;
if ( ! V_48 )
goto V_69;
V_20 = - V_62 ;
if ( ! F_34 ( V_9 , V_48 ) )
goto V_69;
V_18 = V_9 -> V_47 ;
V_68 += V_48 ;
V_9 -> V_47 -= V_48 ;
while ( V_48 > 0 ) {
int V_70 , V_71 ;
if ( F_49 ( V_13 ) ) {
V_20 = - V_63 ;
goto V_69;
}
F_50 () ;
V_70 = V_18 % V_27 ;
if ( V_70 == 0 )
V_70 = V_27 ;
V_71 = V_70 ;
if ( V_71 > V_48 )
V_71 = V_48 ;
V_70 -= V_71 ;
V_18 -= V_71 ;
V_68 -= V_71 ;
V_48 -= V_71 ;
if ( ! V_65 || V_67 != ( V_18 & V_72 ) ) {
struct V_17 * V_17 ;
V_17 = F_13 ( V_9 , V_18 , 1 ) ;
if ( ! V_17 ) {
V_20 = - V_62 ;
goto V_69;
}
if ( V_65 ) {
F_53 ( V_65 ) ;
F_54 ( V_65 ) ;
F_19 ( V_65 ) ;
}
V_65 = V_17 ;
V_66 = F_55 ( V_65 ) ;
V_67 = V_18 & V_72 ;
F_22 ( V_9 , V_67 , V_65 ) ;
}
if ( F_56 ( V_66 + V_70 , V_68 , V_71 ) ) {
V_20 = - V_60 ;
goto V_69;
}
}
}
V_20 = 0 ;
V_69:
if ( V_65 ) {
F_53 ( V_65 ) ;
F_54 ( V_65 ) ;
F_19 ( V_65 ) ;
}
return V_20 ;
}
int F_57 ( int V_64 , const char * const * V_73 ,
struct V_8 * V_9 )
{
int V_74 ;
T_3 V_75 = F_58 () ;
struct V_53 V_54 = {
. V_59 . V_56 = ( const char T_1 * const T_1 * ) V_73 ,
} ;
F_59 ( V_76 ) ;
V_74 = F_51 ( V_64 , V_54 , V_9 ) ;
F_59 ( V_75 ) ;
return V_74 ;
}
static int F_60 ( struct V_33 * V_21 , unsigned long V_77 )
{
struct V_11 * V_12 = V_21 -> V_38 ;
unsigned long V_78 = V_21 -> V_24 ;
unsigned long V_79 = V_21 -> V_23 ;
unsigned long V_80 = V_79 - V_78 ;
unsigned long V_81 = V_78 - V_77 ;
unsigned long V_82 = V_79 - V_77 ;
struct V_83 V_84 ;
F_2 ( V_81 > V_82 ) ;
if ( V_21 != F_61 ( V_12 , V_81 ) )
return - V_60 ;
if ( F_62 ( V_21 , V_81 , V_79 , V_21 -> V_85 , NULL ) )
return - V_36 ;
if ( V_80 != F_63 ( V_21 , V_78 ,
V_21 , V_81 , V_80 ) )
return - V_36 ;
F_64 () ;
F_65 ( & V_84 , V_12 , 0 ) ;
if ( V_82 > V_78 ) {
F_66 ( & V_84 , V_82 , V_79 , V_82 ,
V_21 -> V_86 ? V_21 -> V_86 -> V_24 : 0 ) ;
} else {
F_66 ( & V_84 , V_78 , V_79 , V_82 ,
V_21 -> V_86 ? V_21 -> V_86 -> V_24 : 0 ) ;
}
F_67 ( & V_84 , V_82 , V_79 ) ;
F_62 ( V_21 , V_81 , V_82 , V_21 -> V_85 , NULL ) ;
return 0 ;
}
int F_68 ( struct V_8 * V_9 ,
unsigned long V_87 ,
int V_88 )
{
unsigned long V_20 ;
unsigned long V_89 ;
struct V_11 * V_12 = V_13 -> V_12 ;
struct V_33 * V_21 = V_9 -> V_21 ;
struct V_33 * V_90 = NULL ;
unsigned long V_42 ;
unsigned long V_91 ;
unsigned long V_92 ;
unsigned long V_93 ;
unsigned long V_94 ;
#ifdef F_14
V_91 = F_69 ( V_29 ) ;
if ( V_91 > ( 1 << 30 ) )
V_91 = 1 << 30 ;
if ( V_21 -> V_23 - V_21 -> V_24 > V_91 )
return - V_36 ;
V_91 = F_70 ( V_87 - V_91 ) ;
V_89 = V_21 -> V_24 - V_91 ;
V_12 -> V_95 = V_9 -> V_47 - V_89 ;
V_9 -> V_47 = V_21 -> V_23 - V_89 ;
#else
V_87 = F_71 ( V_87 ) ;
V_87 = F_70 ( V_87 ) ;
if ( F_43 ( V_87 < V_96 ) ||
F_43 ( V_21 -> V_23 - V_21 -> V_24 >= V_87 - V_96 ) )
return - V_36 ;
V_89 = V_21 -> V_23 - V_87 ;
V_9 -> V_47 -= V_89 ;
V_12 -> V_95 = V_9 -> V_47 ;
#endif
if ( V_9 -> V_97 )
V_9 -> V_97 -= V_89 ;
V_9 -> V_98 -= V_89 ;
F_27 ( & V_12 -> V_37 ) ;
V_42 = V_39 ;
if ( F_43 ( V_88 == V_99 ) )
V_42 |= V_100 ;
else if ( V_88 == V_101 )
V_42 &= ~ V_100 ;
V_42 |= V_12 -> V_102 ;
V_42 |= V_40 ;
V_20 = F_72 ( V_21 , & V_90 , V_21 -> V_24 , V_21 -> V_23 ,
V_42 ) ;
if ( V_20 )
goto V_103;
F_2 ( V_90 != V_21 ) ;
if ( V_89 ) {
V_20 = F_60 ( V_21 , V_89 ) ;
if ( V_20 )
goto V_103;
}
V_21 -> V_42 &= ~ V_40 ;
V_93 = 131072UL ;
V_92 = V_21 -> V_23 - V_21 -> V_24 ;
V_94 = V_25 ( V_29 ) & V_72 ;
#ifdef F_14
if ( V_92 + V_93 > V_94 )
V_91 = V_21 -> V_24 + V_94 ;
else
V_91 = V_21 -> V_23 + V_93 ;
#else
if ( V_92 + V_93 > V_94 )
V_91 = V_21 -> V_23 - V_94 ;
else
V_91 = V_21 -> V_24 - V_93 ;
#endif
V_13 -> V_12 -> V_104 = V_9 -> V_47 ;
V_20 = F_73 ( V_21 , V_91 ) ;
if ( V_20 )
V_20 = - V_60 ;
V_103:
F_32 ( & V_12 -> V_37 ) ;
return V_20 ;
}
struct V_105 * F_74 ( const char * V_106 )
{
struct V_105 * V_105 ;
int V_32 ;
static const struct V_107 V_108 = {
. V_109 = V_110 | V_111 | V_112 ,
. V_113 = V_114 | V_115 ,
. V_116 = V_117
} ;
V_105 = F_75 ( V_118 , V_106 , & V_108 , V_119 ) ;
if ( F_48 ( V_105 ) )
goto V_69;
V_32 = - V_120 ;
if ( ! F_76 ( V_105 -> V_121 . V_122 -> V_123 -> V_124 ) )
goto exit;
if ( V_105 -> V_121 . V_125 -> V_126 & V_127 )
goto exit;
F_77 ( V_105 ) ;
V_32 = F_78 ( V_105 ) ;
if ( V_32 )
goto exit;
V_69:
return V_105 ;
exit:
F_79 ( V_105 ) ;
return F_45 ( V_32 ) ;
}
int F_80 ( struct V_105 * V_105 , T_4 V_70 ,
char * V_128 , unsigned long F_47 )
{
T_3 V_129 ;
T_4 V_18 = V_70 ;
int V_130 ;
V_129 = F_58 () ;
F_59 ( F_81 () ) ;
V_130 = F_82 ( V_105 , ( void T_1 * ) V_128 , F_47 , & V_18 ) ;
F_59 ( V_129 ) ;
return V_130 ;
}
static int F_83 ( struct V_11 * V_12 )
{
struct V_131 * V_132 ;
struct V_11 * V_133 , * V_134 ;
V_132 = V_13 ;
V_133 = V_13 -> V_12 ;
F_84 ( V_132 , V_133 ) ;
if ( V_133 ) {
F_85 ( V_133 ) ;
F_86 ( & V_133 -> V_37 ) ;
if ( F_43 ( V_133 -> V_135 ) ) {
F_87 ( & V_133 -> V_37 ) ;
return - V_136 ;
}
}
F_88 ( V_132 ) ;
V_134 = V_132 -> V_134 ;
V_132 -> V_12 = V_12 ;
V_132 -> V_134 = V_12 ;
F_89 ( V_134 , V_12 ) ;
F_90 ( V_132 ) ;
F_91 ( V_12 ) ;
if ( V_133 ) {
F_87 ( & V_133 -> V_37 ) ;
F_2 ( V_134 != V_133 ) ;
F_92 ( & V_132 -> signal -> V_137 , V_133 ) ;
F_93 ( V_133 ) ;
F_94 ( V_133 ) ;
return 0 ;
}
F_40 ( V_134 ) ;
return 0 ;
}
static int F_95 ( struct V_131 * V_132 )
{
struct V_138 * V_139 = V_132 -> signal ;
struct V_140 * V_141 = V_132 -> V_142 ;
T_5 * V_143 = & V_141 -> V_144 ;
if ( F_96 ( V_132 ) )
goto V_145;
F_97 ( V_143 ) ;
if ( F_98 ( V_139 ) ) {
F_99 ( V_143 ) ;
return - V_146 ;
}
V_139 -> V_147 = V_132 ;
V_139 -> V_148 = F_100 ( V_132 ) ;
if ( ! F_101 ( V_132 ) )
V_139 -> V_148 -- ;
while ( V_139 -> V_148 ) {
F_102 ( V_149 ) ;
F_99 ( V_143 ) ;
F_103 () ;
F_97 ( V_143 ) ;
}
F_99 ( V_143 ) ;
if ( ! F_101 ( V_132 ) ) {
struct V_131 * V_150 = V_132 -> V_151 ;
V_139 -> V_148 = - 1 ;
for (; ; ) {
F_104 ( & V_152 ) ;
if ( F_105 ( V_150 -> V_153 ) )
break;
F_102 ( V_149 ) ;
F_106 ( & V_152 ) ;
F_103 () ;
}
V_132 -> V_154 = V_150 -> V_154 ;
F_2 ( ! F_107 ( V_150 , V_132 ) ) ;
F_2 ( F_108 ( V_132 ) ) ;
F_109 ( V_132 , V_155 ) ;
V_132 -> V_156 = V_150 -> V_156 ;
F_110 ( V_132 , V_155 , F_111 ( V_150 ) ) ;
F_112 ( V_150 , V_132 , V_157 ) ;
F_112 ( V_150 , V_132 , V_158 ) ;
F_113 ( & V_150 -> V_159 , & V_132 -> V_159 ) ;
F_114 ( & V_150 -> V_160 , & V_132 -> V_160 ) ;
V_132 -> V_151 = V_132 ;
V_150 -> V_151 = V_132 ;
V_132 -> V_161 = V_162 ;
V_150 -> V_161 = - 1 ;
F_2 ( V_150 -> V_153 != V_163 ) ;
V_150 -> V_153 = V_164 ;
if ( F_43 ( V_150 -> V_165 ) )
F_115 ( V_150 , V_150 -> V_166 ) ;
F_106 ( & V_152 ) ;
F_116 ( V_150 ) ;
}
V_139 -> V_147 = NULL ;
V_139 -> V_148 = 0 ;
V_145:
V_132 -> V_161 = V_162 ;
F_117 ( V_139 ) ;
F_118 () ;
if ( F_119 ( & V_141 -> F_47 ) != 1 ) {
struct V_140 * V_167 ;
V_167 = F_120 ( V_168 , V_35 ) ;
if ( ! V_167 )
return - V_36 ;
F_121 ( & V_167 -> F_47 , 1 ) ;
memcpy ( V_167 -> V_169 , V_141 -> V_169 ,
sizeof( V_167 -> V_169 ) ) ;
F_104 ( & V_152 ) ;
F_122 ( & V_141 -> V_144 ) ;
F_123 ( V_132 -> V_142 , V_167 ) ;
F_124 ( & V_141 -> V_144 ) ;
F_106 ( & V_152 ) ;
F_125 ( V_141 ) ;
}
F_2 ( ! F_101 ( V_132 ) ) ;
return 0 ;
}
static void F_126 ( struct V_170 * V_171 )
{
long V_172 = - 1 ;
struct V_173 * V_174 ;
F_122 ( & V_171 -> V_175 ) ;
for (; ; ) {
unsigned long V_176 , V_31 ;
V_172 ++ ;
V_31 = V_172 * V_177 ;
V_174 = F_127 ( V_171 ) ;
if ( V_31 >= V_174 -> V_178 )
break;
V_176 = V_174 -> V_179 [ V_172 ] ;
if ( ! V_176 )
continue;
V_174 -> V_179 [ V_172 ] = 0 ;
F_124 ( & V_171 -> V_175 ) ;
for ( ; V_176 ; V_31 ++ , V_176 >>= 1 ) {
if ( V_176 & 1 ) {
F_128 ( V_31 ) ;
}
}
F_122 ( & V_171 -> V_175 ) ;
}
F_124 ( & V_171 -> V_175 ) ;
}
char * F_129 ( char * V_180 , struct V_131 * V_132 )
{
F_88 ( V_132 ) ;
strncpy ( V_180 , V_132 -> V_181 , sizeof( V_132 -> V_181 ) ) ;
F_90 ( V_132 ) ;
return V_180 ;
}
void F_130 ( struct V_131 * V_132 , char * V_180 )
{
F_88 ( V_132 ) ;
F_131 ( V_132 , V_180 ) ;
memset ( V_132 -> V_181 , 0 , V_182 ) ;
F_132 () ;
F_133 ( V_132 -> V_181 , V_180 , sizeof( V_132 -> V_181 ) ) ;
F_90 ( V_132 ) ;
F_134 ( V_132 ) ;
}
static void F_135 ( char * V_183 , const char * V_184 , unsigned int V_48 )
{
int V_31 , V_185 ;
for ( V_31 = 0 ; ( V_185 = * ( V_184 ++ ) ) != '\0' ; ) {
if ( V_185 == '/' )
V_31 = 0 ;
else
if ( V_31 < V_48 - 1 )
V_183 [ V_31 ++ ] = V_185 ;
}
V_183 [ V_31 ] = '\0' ;
}
int F_136 ( struct V_8 * V_9 )
{
int V_186 ;
V_186 = F_95 ( V_13 ) ;
if ( V_186 )
goto V_69;
F_137 ( V_9 -> V_12 , V_9 -> V_105 ) ;
F_135 ( V_9 -> V_183 , V_9 -> V_187 , sizeof( V_9 -> V_183 ) ) ;
F_11 ( V_9 , 0 ) ;
V_186 = F_83 ( V_9 -> V_12 ) ;
if ( V_186 )
goto V_69;
V_9 -> V_12 = NULL ;
F_59 ( V_188 ) ;
V_13 -> V_189 &= ~ ( V_190 | V_191 | V_192 ) ;
F_138 () ;
V_13 -> V_193 &= ~ V_9 -> V_194 ;
return 0 ;
V_69:
return V_186 ;
}
void F_139 ( struct V_8 * V_9 , struct V_105 * V_105 )
{
if ( F_140 ( V_105 -> V_121 . V_122 -> V_123 , V_195 ) < 0 )
V_9 -> V_196 |= V_197 ;
}
void F_141 ( struct V_8 * V_9 )
{
F_91 ( V_13 -> V_12 ) ;
V_13 -> V_198 = V_13 -> V_199 = 0 ;
if ( F_142 ( F_143 () , F_144 () ) && F_145 ( F_146 () , F_147 () ) )
F_148 ( V_13 -> V_12 , 1 ) ;
else
F_148 ( V_13 -> V_12 , V_200 ) ;
F_130 ( V_13 , V_9 -> V_183 ) ;
V_13 -> V_12 -> V_201 = V_202 ;
if ( ! F_142 ( V_9 -> V_203 -> V_204 , F_143 () ) ||
! F_145 ( V_9 -> V_203 -> V_205 , F_146 () ) ) {
V_13 -> V_206 = 0 ;
} else {
F_139 ( V_9 , V_9 -> V_105 ) ;
if ( V_9 -> V_196 & V_197 )
F_148 ( V_13 -> V_12 , V_200 ) ;
}
if ( ! F_149 ( V_13 -> V_12 ) )
F_150 ( V_13 ) ;
V_13 -> V_207 ++ ;
F_151 ( V_13 , 0 ) ;
F_126 ( V_13 -> V_171 ) ;
}
int F_152 ( struct V_8 * V_9 )
{
if ( F_153 ( & V_13 -> signal -> V_208 ) )
return - V_209 ;
V_9 -> V_203 = F_154 () ;
if ( F_105 ( V_9 -> V_203 ) )
return 0 ;
F_155 ( & V_13 -> signal -> V_208 ) ;
return - V_36 ;
}
void F_156 ( struct V_8 * V_9 )
{
F_21 ( V_9 ) ;
if ( V_9 -> V_203 ) {
F_155 ( & V_13 -> signal -> V_208 ) ;
F_157 ( V_9 -> V_203 ) ;
}
F_158 ( V_9 ) ;
}
void F_159 ( struct V_8 * V_9 )
{
F_160 ( V_9 ) ;
F_161 ( V_9 -> V_203 ) ;
V_9 -> V_203 = NULL ;
F_162 ( V_9 ) ;
F_155 ( & V_13 -> signal -> V_208 ) ;
}
static int F_163 ( struct V_8 * V_9 )
{
struct V_131 * V_47 = V_13 , * V_210 ;
unsigned V_211 ;
int V_212 = 0 ;
if ( V_47 -> V_165 ) {
if ( V_47 -> V_165 & V_213 )
V_9 -> V_214 |= V_215 ;
else
V_9 -> V_214 |= V_216 ;
}
if ( V_13 -> V_217 )
V_9 -> V_214 |= V_218 ;
V_211 = 1 ;
F_122 ( & V_47 -> V_219 -> V_143 ) ;
F_164 () ;
for ( V_210 = F_165 ( V_47 ) ; V_210 != V_47 ; V_210 = F_165 ( V_210 ) ) {
if ( V_210 -> V_219 == V_47 -> V_219 )
V_211 ++ ;
}
F_166 () ;
if ( V_47 -> V_219 -> V_220 > V_211 ) {
V_9 -> V_214 |= V_221 ;
} else {
V_212 = - V_146 ;
if ( ! V_47 -> V_219 -> V_222 ) {
V_47 -> V_219 -> V_222 = 1 ;
V_212 = 1 ;
}
}
F_124 ( & V_47 -> V_219 -> V_143 ) ;
return V_212 ;
}
int F_167 ( struct V_8 * V_9 )
{
T_6 V_223 ;
struct V_224 * V_224 = V_9 -> V_105 -> V_121 . V_122 -> V_123 ;
int V_186 ;
V_223 = V_224 -> V_124 ;
if ( V_9 -> V_105 -> V_225 == NULL )
return - V_120 ;
V_9 -> V_203 -> V_226 = F_143 () ;
V_9 -> V_203 -> V_227 = F_146 () ;
if ( ! ( V_9 -> V_105 -> V_121 . V_125 -> V_126 & V_228 ) &&
! V_13 -> V_217 ) {
if ( V_223 & V_229 ) {
if ( ! F_168 ( V_9 -> V_203 -> V_230 , V_224 -> V_231 ) )
return - V_232 ;
V_9 -> V_194 |= V_233 ;
V_9 -> V_203 -> V_226 = V_224 -> V_231 ;
}
if ( ( V_223 & ( V_234 | V_235 ) ) == ( V_234 | V_235 ) ) {
if ( ! F_169 ( V_9 -> V_203 -> V_230 , V_224 -> V_236 ) )
return - V_232 ;
V_9 -> V_194 |= V_233 ;
V_9 -> V_203 -> V_227 = V_224 -> V_236 ;
}
}
V_186 = F_170 ( V_9 ) ;
if ( V_186 )
return V_186 ;
V_9 -> V_237 = 1 ;
memset ( V_9 -> V_180 , 0 , V_238 ) ;
return F_80 ( V_9 -> V_105 , 0 , V_9 -> V_180 , V_238 ) ;
}
int F_171 ( struct V_8 * V_9 )
{
int V_20 = 0 ;
unsigned long V_70 ;
char * V_66 ;
struct V_17 * V_17 ;
if ( ! V_9 -> V_64 )
return 0 ;
do {
V_70 = V_9 -> V_47 & ~ V_72 ;
V_17 = F_13 ( V_9 , V_9 -> V_47 , 0 ) ;
if ( ! V_17 ) {
V_20 = - V_60 ;
goto V_69;
}
V_66 = F_172 ( V_17 ) ;
for (; V_70 < V_27 && V_66 [ V_70 ] ;
V_70 ++ , V_9 -> V_47 ++ )
;
F_173 ( V_66 ) ;
F_19 ( V_17 ) ;
if ( V_70 == V_27 )
F_20 ( V_9 , ( V_9 -> V_47 >> V_239 ) - 1 ) ;
} while ( V_70 == V_27 );
V_9 -> V_47 ++ ;
V_9 -> V_64 -- ;
V_20 = 0 ;
V_69:
return V_20 ;
}
int F_174 ( struct V_8 * V_9 , struct V_240 * V_241 )
{
unsigned int V_242 = V_9 -> V_243 ;
int V_244 , V_186 ;
struct V_1 * V_2 ;
T_7 V_245 , V_246 ;
V_186 = F_175 ( V_9 ) ;
if ( V_186 )
return V_186 ;
V_186 = F_176 ( V_9 ) ;
if ( V_186 )
return V_186 ;
V_245 = V_13 -> V_156 ;
F_164 () ;
V_246 = F_177 ( V_13 , F_178 ( V_13 -> V_166 ) ) ;
F_166 () ;
V_186 = - V_247 ;
for ( V_244 = 0 ; V_244 < 2 ; V_244 ++ ) {
F_179 ( & V_4 ) ;
F_180 (fmt, &formats, lh) {
int (* V_184)( struct V_8 * , struct V_240 * ) = V_2 -> V_248 ;
if ( ! V_184 )
continue;
if ( ! F_181 ( V_2 -> V_7 ) )
continue;
F_182 ( & V_4 ) ;
V_186 = V_184 ( V_9 , V_241 ) ;
V_9 -> V_243 = V_242 ;
if ( V_186 >= 0 ) {
if ( V_242 == 0 ) {
F_183 ( V_13 , V_245 , V_9 ) ;
F_184 ( V_249 , V_246 ) ;
}
F_9 ( V_2 ) ;
F_185 ( V_9 -> V_105 ) ;
if ( V_9 -> V_105 )
F_79 ( V_9 -> V_105 ) ;
V_9 -> V_105 = NULL ;
V_13 -> V_250 = 1 ;
F_186 ( V_13 ) ;
return V_186 ;
}
F_179 ( & V_4 ) ;
F_9 ( V_2 ) ;
if ( V_186 != - V_251 || V_9 -> V_12 == NULL )
break;
if ( ! V_9 -> V_105 ) {
F_182 ( & V_4 ) ;
return V_186 ;
}
}
F_182 ( & V_4 ) ;
#ifdef F_187
if ( V_186 != - V_251 || V_9 -> V_12 == NULL ) {
break;
} else {
#define F_188 ( T_8 ) (((c)=='\t') || ((c)=='\n') || (0x20<=(c) && (c)<=0x7e))
if ( F_188 ( V_9 -> V_180 [ 0 ] ) &&
F_188 ( V_9 -> V_180 [ 1 ] ) &&
F_188 ( V_9 -> V_180 [ 2 ] ) &&
F_188 ( V_9 -> V_180 [ 3 ] ) )
break;
if ( V_244 )
break;
F_189 ( L_1 , * ( unsigned short * ) ( & V_9 -> V_180 [ 2 ] ) ) ;
}
#else
break;
#endif
}
return V_186 ;
}
static int F_190 ( const char * V_187 ,
struct V_53 V_54 ,
struct V_53 V_252 ,
struct V_240 * V_241 )
{
struct V_8 * V_9 ;
struct V_105 * V_105 ;
struct V_170 * V_253 ;
bool V_254 ;
int V_186 ;
const struct V_203 * V_203 = F_191 () ;
if ( ( V_13 -> V_189 & V_255 ) &&
F_119 ( & V_203 -> V_256 -> V_257 ) > V_25 ( V_258 ) ) {
V_186 = - V_146 ;
goto V_259;
}
V_13 -> V_189 &= ~ V_255 ;
V_186 = F_192 ( & V_253 ) ;
if ( V_186 )
goto V_259;
V_186 = - V_36 ;
V_9 = F_193 ( sizeof( * V_9 ) , V_35 ) ;
if ( ! V_9 )
goto V_260;
V_186 = F_152 ( V_9 ) ;
if ( V_186 )
goto V_261;
V_186 = F_163 ( V_9 ) ;
if ( V_186 < 0 )
goto V_261;
V_254 = V_186 ;
V_13 -> V_262 = 1 ;
V_105 = F_74 ( V_187 ) ;
V_186 = F_194 ( V_105 ) ;
if ( F_48 ( V_105 ) )
goto V_263;
F_195 () ;
V_9 -> V_105 = V_105 ;
V_9 -> V_187 = V_187 ;
V_9 -> V_264 = V_187 ;
V_186 = F_37 ( V_9 ) ;
if ( V_186 )
goto V_265;
V_9 -> V_64 = F_47 ( V_54 , V_266 ) ;
if ( ( V_186 = V_9 -> V_64 ) < 0 )
goto V_69;
V_9 -> V_267 = F_47 ( V_252 , V_266 ) ;
if ( ( V_186 = V_9 -> V_267 ) < 0 )
goto V_69;
V_186 = F_167 ( V_9 ) ;
if ( V_186 < 0 )
goto V_69;
V_186 = F_57 ( 1 , & V_9 -> V_187 , V_9 ) ;
if ( V_186 < 0 )
goto V_69;
V_9 -> V_98 = V_9 -> V_47 ;
V_186 = F_51 ( V_9 -> V_267 , V_252 , V_9 ) ;
if ( V_186 < 0 )
goto V_69;
V_186 = F_51 ( V_9 -> V_64 , V_54 , V_9 ) ;
if ( V_186 < 0 )
goto V_69;
V_186 = F_174 ( V_9 , V_241 ) ;
if ( V_186 < 0 )
goto V_69;
V_13 -> V_219 -> V_222 = 0 ;
V_13 -> V_262 = 0 ;
F_196 ( V_13 ) ;
F_156 ( V_9 ) ;
if ( V_253 )
F_197 ( V_253 ) ;
return V_186 ;
V_69:
if ( V_9 -> V_12 ) {
F_11 ( V_9 , 0 ) ;
F_94 ( V_9 -> V_12 ) ;
}
V_265:
if ( V_9 -> V_105 ) {
F_185 ( V_9 -> V_105 ) ;
F_79 ( V_9 -> V_105 ) ;
}
V_263:
if ( V_254 )
V_13 -> V_219 -> V_222 = 0 ;
V_13 -> V_262 = 0 ;
V_261:
F_156 ( V_9 ) ;
V_260:
if ( V_253 )
F_198 ( V_253 ) ;
V_259:
return V_186 ;
}
int F_199 ( const char * V_187 ,
const char T_1 * const T_1 * V_73 ,
const char T_1 * const T_1 * V_268 ,
struct V_240 * V_241 )
{
struct V_53 V_54 = { . V_59 . V_56 = V_73 } ;
struct V_53 V_252 = { . V_59 . V_56 = V_268 } ;
return F_190 ( V_187 , V_54 , V_252 , V_241 ) ;
}
int F_200 ( char * V_187 ,
T_2 T_1 * V_73 ,
T_2 T_1 * V_268 ,
struct V_240 * V_241 )
{
struct V_53 V_54 = {
. V_57 = true ,
. V_59 . V_58 = V_73 ,
} ;
struct V_53 V_252 = {
. V_57 = true ,
. V_59 . V_58 = V_268 ,
} ;
return F_190 ( V_187 , V_54 , V_252 , V_241 ) ;
}
void F_201 ( struct V_1 * V_269 )
{
struct V_11 * V_12 = V_13 -> V_12 ;
if ( V_12 -> V_270 )
F_10 ( V_12 -> V_270 -> V_7 ) ;
V_12 -> V_270 = V_269 ;
if ( V_269 )
F_202 ( V_269 -> V_7 ) ;
}
static int F_203 ( struct V_271 * V_272 )
{
char * V_273 = V_272 -> V_274 ;
V_272 -> V_22 = V_275 * F_204 ( & V_276 ) ;
V_272 -> V_274 = F_205 ( V_273 , V_272 -> V_22 , V_35 ) ;
if ( ! V_272 -> V_274 ) {
F_158 ( V_273 ) ;
return - V_36 ;
}
return 0 ;
}
static int F_206 ( struct V_271 * V_272 , const char * V_2 , ... )
{
char * V_277 ;
int V_278 ;
int V_20 ;
T_9 V_279 ;
va_start ( V_279 , V_2 ) ;
V_278 = vsnprintf ( NULL , 0 , V_2 , V_279 ) ;
va_end ( V_279 ) ;
if ( F_105 ( V_278 < V_272 -> V_22 - V_272 -> V_280 - 1 ) )
goto V_281;
V_20 = F_203 ( V_272 ) ;
if ( V_20 )
goto V_282;
V_281:
V_277 = V_272 -> V_274 + V_272 -> V_280 ;
va_start ( V_279 , V_2 ) ;
vsnprintf ( V_277 , V_278 + 1 , V_2 , V_279 ) ;
va_end ( V_279 ) ;
V_272 -> V_280 += V_278 ;
return 0 ;
V_282:
return V_20 ;
}
static void F_207 ( char * V_68 )
{
for (; * V_68 ; V_68 ++ )
if ( * V_68 == '/' )
* V_68 = '!' ;
}
static int F_208 ( struct V_271 * V_272 )
{
struct V_105 * V_283 ;
char * V_284 , * V_285 ;
int V_20 ;
V_283 = F_209 ( V_13 -> V_12 ) ;
if ( ! V_283 ) {
char * V_286 = V_272 -> V_274 + V_272 -> V_280 ;
V_20 = F_206 ( V_272 , L_2 , V_13 -> V_181 ) ;
F_207 ( V_286 ) ;
return V_20 ;
}
V_284 = F_210 ( V_287 , V_288 ) ;
if ( ! V_284 ) {
V_20 = - V_36 ;
goto V_289;
}
V_285 = F_211 ( & V_283 -> V_121 , V_284 , V_287 ) ;
if ( F_48 ( V_285 ) ) {
V_20 = F_194 ( V_285 ) ;
goto V_290;
}
F_207 ( V_285 ) ;
V_20 = F_206 ( V_272 , L_3 , V_285 ) ;
V_290:
F_158 ( V_284 ) ;
V_289:
F_79 ( V_283 ) ;
return V_20 ;
}
static int F_212 ( struct V_271 * V_272 , long V_291 )
{
const struct V_203 * V_203 = F_191 () ;
const char * V_292 = V_293 ;
int V_294 = ( * V_292 == '|' ) ;
int V_295 = 0 ;
int V_32 = 0 ;
V_272 -> V_22 = V_275 * F_119 ( & V_276 ) ;
V_272 -> V_274 = F_210 ( V_272 -> V_22 , V_35 ) ;
V_272 -> V_280 = 0 ;
if ( ! V_272 -> V_274 )
return - V_36 ;
while ( * V_292 ) {
if ( * V_292 != '%' ) {
if ( * V_292 == 0 )
goto V_69;
V_32 = F_206 ( V_272 , L_4 , * V_292 ++ ) ;
} else {
switch ( * ++ V_292 ) {
case 0 :
goto V_69;
case '%' :
V_32 = F_206 ( V_272 , L_4 , '%' ) ;
break;
case 'p' :
V_295 = 1 ;
V_32 = F_206 ( V_272 , L_5 ,
F_213 ( V_13 ) ) ;
break;
case 'u' :
V_32 = F_206 ( V_272 , L_5 , V_203 -> V_204 ) ;
break;
case 'g' :
V_32 = F_206 ( V_272 , L_5 , V_203 -> V_205 ) ;
break;
case 's' :
V_32 = F_206 ( V_272 , L_6 , V_291 ) ;
break;
case 't' : {
struct V_296 V_297 ;
F_214 ( & V_297 ) ;
V_32 = F_206 ( V_272 , L_7 , V_297 . V_298 ) ;
break;
}
case 'h' : {
char * V_299 = V_272 -> V_274 + V_272 -> V_280 ;
F_86 ( & V_300 ) ;
V_32 = F_206 ( V_272 , L_3 ,
F_215 () -> V_301 ) ;
F_87 ( & V_300 ) ;
F_207 ( V_299 ) ;
break;
}
case 'e' : {
char * V_286 = V_272 -> V_274 + V_272 -> V_280 ;
V_32 = F_206 ( V_272 , L_3 , V_13 -> V_181 ) ;
F_207 ( V_286 ) ;
break;
}
case 'E' :
V_32 = F_208 ( V_272 ) ;
break;
case 'c' :
V_32 = F_206 ( V_272 , L_7 ,
V_25 ( V_302 ) ) ;
break;
default:
break;
}
++ V_292 ;
}
if ( V_32 )
return V_32 ;
}
if ( ! V_294 && ! V_295 && V_303 ) {
V_32 = F_206 ( V_272 , L_8 , F_213 ( V_13 ) ) ;
if ( V_32 )
return V_32 ;
}
V_69:
return V_294 ;
}
static int F_216 ( struct V_131 * V_304 , int V_305 )
{
struct V_131 * V_210 ;
int V_55 = 0 ;
V_304 -> signal -> V_189 = V_306 ;
V_304 -> signal -> V_307 = V_305 ;
V_304 -> signal -> V_308 = 0 ;
V_210 = V_304 ;
do {
F_217 ( V_210 , V_309 ) ;
if ( V_210 != V_13 && V_210 -> V_12 ) {
F_218 ( & V_210 -> V_310 . signal , V_311 ) ;
F_219 ( V_210 , 1 ) ;
V_55 ++ ;
}
} while_each_thread(start, t) ;
inline int F_220 ( struct V_131 * V_132 , struct V_11 * V_12 ,
struct V_135 * V_135 , int V_305 )
{
struct V_131 * V_312 , * V_47 ;
unsigned long V_189 ;
int V_55 = - V_146 ;
F_97 ( & V_132 -> V_142 -> V_144 ) ;
if ( ! F_98 ( V_132 -> signal ) ) {
V_12 -> V_135 = V_135 ;
V_55 = F_216 ( V_132 , V_305 ) ;
}
F_99 ( & V_132 -> V_142 -> V_144 ) ;
if ( F_43 ( V_55 < 0 ) )
return V_55 ;
if ( F_119 ( & V_12 -> V_313 ) == V_55 + 1 )
goto V_314;
F_164 () ;
F_221 (g) {
if ( V_312 == V_132 -> V_151 )
continue;
if ( V_312 -> V_189 & V_192 )
continue;
V_47 = V_312 ;
do {
if ( V_47 -> V_12 ) {
if ( F_43 ( V_47 -> V_12 == V_12 ) ) {
F_222 ( V_47 , & V_189 ) ;
V_55 += F_216 ( V_47 , V_305 ) ;
F_223 ( V_47 , & V_189 ) ;
}
break;
}
} while_each_thread(g, p) ;
}
int F_224 ( int V_305 , struct V_135 * V_135 )
{
struct V_131 * V_132 = V_13 ;
struct V_11 * V_12 = V_132 -> V_12 ;
int V_315 = - V_316 ;
F_225 ( & V_135 -> V_317 ) ;
V_135 -> V_318 . V_319 = V_132 ;
V_135 -> V_318 . V_320 = NULL ;
F_27 ( & V_12 -> V_37 ) ;
if ( ! V_12 -> V_135 )
V_315 = F_220 ( V_132 , V_12 , V_135 , V_305 ) ;
F_32 ( & V_12 -> V_37 ) ;
if ( V_315 > 0 ) {
struct V_321 * V_59 ;
F_226 ( & V_135 -> V_317 ) ;
V_59 = V_135 -> V_318 . V_320 ;
while ( V_59 != NULL ) {
F_227 ( V_59 -> V_319 , 0 ) ;
V_59 = V_59 -> V_320 ;
}
}
return V_315 ;
}
static void F_228 ( struct V_11 * V_12 )
{
struct V_321 * V_322 , * V_320 ;
struct V_131 * V_319 ;
V_320 = V_12 -> V_135 -> V_318 . V_320 ;
while ( ( V_322 = V_320 ) != NULL ) {
V_320 = V_322 -> V_320 ;
V_319 = V_322 -> V_319 ;
F_229 () ;
V_322 -> V_319 = NULL ;
F_230 ( V_319 ) ;
}
V_12 -> V_135 = NULL ;
}
void F_148 ( struct V_11 * V_12 , int V_323 )
{
switch ( V_323 ) {
case 0 :
F_231 ( V_324 , & V_12 -> V_189 ) ;
F_232 () ;
F_231 ( V_325 , & V_12 -> V_189 ) ;
break;
case 1 :
F_233 ( V_324 , & V_12 -> V_189 ) ;
F_232 () ;
F_231 ( V_325 , & V_12 -> V_189 ) ;
break;
case 2 :
F_233 ( V_325 , & V_12 -> V_189 ) ;
F_232 () ;
F_233 ( V_324 , & V_12 -> V_189 ) ;
break;
}
}
static int F_234 ( unsigned long V_326 )
{
int V_20 ;
V_20 = V_326 & V_327 ;
return ( V_20 >= 2 ) ? 2 : V_20 ;
}
int F_149 ( struct V_11 * V_12 )
{
return F_234 ( V_12 -> V_189 ) ;
}
static void F_235 ( struct V_105 * V_105 )
{
struct V_328 * V_329 ;
V_329 = V_105 -> V_121 . V_122 -> V_123 -> V_330 ;
F_236 ( V_329 ) ;
V_329 -> V_331 ++ ;
V_329 -> V_332 -- ;
while ( ( V_329 -> V_331 > 1 ) && ( ! F_237 ( V_13 ) ) ) {
F_238 ( & V_329 -> V_333 ) ;
F_239 ( & V_329 -> V_334 , V_335 , V_336 ) ;
F_240 ( V_329 ) ;
}
V_329 -> V_331 -- ;
V_329 -> V_332 ++ ;
F_241 ( V_329 ) ;
}
static int F_242 ( struct V_337 * V_338 , struct V_203 * V_269 )
{
struct V_105 * V_339 , * V_340 ;
struct V_173 * V_174 ;
struct V_341 * V_342 = (struct V_341 * ) V_338 -> V_343 ;
struct V_170 * V_344 = V_13 -> V_171 ;
V_340 = F_243 ( 0 ) ;
if ( F_48 ( V_340 ) )
return F_194 ( V_340 ) ;
V_339 = F_244 ( V_340 , 0 ) ;
if ( F_48 ( V_339 ) ) {
F_245 ( V_340 ) ;
return F_194 ( V_339 ) ;
}
V_342 -> V_105 = V_340 ;
F_128 ( 0 ) ;
F_246 ( 0 , V_339 ) ;
F_122 ( & V_344 -> V_175 ) ;
V_174 = F_127 ( V_344 ) ;
F_247 ( 0 , V_174 ) ;
F_248 ( 0 , V_174 ) ;
F_124 ( & V_344 -> V_175 ) ;
V_13 -> signal -> V_26 [ V_302 ] = (struct V_25 ) { 1 , 1 } ;
return 0 ;
}
void F_249 ( long V_291 , int V_305 , struct V_240 * V_241 )
{
struct V_135 V_135 ;
struct V_271 V_272 ;
struct V_11 * V_12 = V_13 -> V_12 ;
struct V_1 * V_270 ;
const struct V_203 * V_345 ;
struct V_203 * V_203 ;
int V_186 = 0 ;
int V_346 = 0 ;
int V_294 ;
static T_10 V_347 = F_250 ( 0 ) ;
struct V_341 V_348 = {
. V_291 = V_291 ,
. V_241 = V_241 ,
. V_349 = V_25 ( V_302 ) ,
. V_326 = V_12 -> V_189 ,
} ;
F_251 ( V_291 ) ;
V_270 = V_12 -> V_270 ;
if ( ! V_270 || ! V_270 -> V_350 )
goto V_351;
if ( ! F_234 ( V_348 . V_326 ) )
goto V_351;
V_203 = F_252 () ;
if ( ! V_203 )
goto V_351;
if ( F_234 ( V_348 . V_326 ) == 2 ) {
V_346 = V_352 ;
V_203 -> V_353 = V_354 ;
}
V_186 = F_224 ( V_305 , & V_135 ) ;
if ( V_186 < 0 )
goto V_355;
V_345 = F_253 ( V_203 ) ;
F_254 ( V_356 ) ;
V_294 = F_212 ( & V_272 , V_291 ) ;
if ( V_294 ) {
int V_357 ;
char * * V_358 ;
if ( V_294 < 0 ) {
F_255 ( V_359 L_9 ) ;
F_255 ( V_359 L_10 ) ;
goto V_360;
}
if ( V_348 . V_349 == 1 ) {
F_255 ( V_359
L_11 ,
F_213 ( V_13 ) , V_13 -> V_181 ) ;
F_255 ( V_359 L_10 ) ;
goto V_361;
}
V_348 . V_349 = V_362 ;
V_357 = F_204 ( & V_347 ) ;
if ( V_363 && ( V_363 < V_357 ) ) {
F_255 ( V_359 L_12 ,
F_213 ( V_13 ) , V_13 -> V_181 ) ;
F_255 ( V_359 L_13 ) ;
goto V_364;
}
V_358 = F_256 ( V_35 , V_272 . V_274 + 1 , NULL ) ;
if ( ! V_358 ) {
F_255 ( V_359 L_14 ,
V_365 ) ;
goto V_364;
}
V_186 = F_257 ( V_358 [ 0 ] , V_358 ,
NULL , V_366 , F_242 ,
NULL , & V_348 ) ;
F_258 ( V_358 ) ;
if ( V_186 ) {
F_255 ( V_367 L_15 ,
V_272 . V_274 ) ;
goto V_368;
}
} else {
struct V_224 * V_224 ;
if ( V_348 . V_349 < V_270 -> V_369 )
goto V_361;
V_348 . V_105 = F_259 ( V_272 . V_274 ,
V_370 | 2 | V_371 | V_110 | V_346 ,
0600 ) ;
if ( F_48 ( V_348 . V_105 ) )
goto V_361;
V_224 = V_348 . V_105 -> V_121 . V_122 -> V_123 ;
if ( V_224 -> V_372 > 1 )
goto V_368;
if ( F_260 ( V_348 . V_105 -> V_121 . V_122 ) )
goto V_368;
if ( ! F_76 ( V_224 -> V_124 ) )
goto V_368;
if ( ! F_142 ( V_224 -> V_231 , F_261 () ) )
goto V_368;
if ( ! V_348 . V_105 -> V_225 || ! V_348 . V_105 -> V_225 -> V_19 )
goto V_368;
if ( F_262 ( V_348 . V_105 -> V_121 . V_122 , 0 , 0 , V_348 . V_105 ) )
goto V_368;
}
V_186 = V_270 -> V_350 ( & V_348 ) ;
if ( V_186 )
V_13 -> signal -> V_307 |= 0x80 ;
if ( V_294 && V_363 )
F_235 ( V_348 . V_105 ) ;
V_368:
if ( V_348 . V_105 )
F_263 ( V_348 . V_105 , NULL ) ;
V_364:
if ( V_294 )
F_264 ( & V_347 ) ;
V_361:
F_158 ( V_272 . V_274 ) ;
V_360:
F_228 ( V_12 ) ;
F_265 ( V_345 ) ;
V_355:
F_266 ( V_203 ) ;
V_351:
return;
}
int F_267 ( struct V_105 * V_105 , const void * V_128 , int V_55 )
{
return F_268 ( V_373 , V_128 , V_55 ) && V_105 -> V_225 -> V_19 ( V_105 , V_128 , V_55 , & V_105 -> V_374 ) == V_55 ;
}
int F_269 ( struct V_105 * V_105 , T_4 V_375 )
{
int V_20 = 1 ;
if ( V_105 -> V_225 -> V_376 && V_105 -> V_225 -> V_376 != V_377 ) {
if ( V_105 -> V_225 -> V_376 ( V_105 , V_375 , V_378 ) < 0 )
return 0 ;
} else {
char * V_180 = ( char * ) F_270 ( V_35 ) ;
if ( ! V_180 )
return 0 ;
while ( V_375 > 0 ) {
unsigned long V_379 = V_375 ;
if ( V_379 > V_27 )
V_379 = V_27 ;
if ( ! F_267 ( V_105 , V_180 , V_379 ) ) {
V_20 = 0 ;
break;
}
V_375 -= V_379 ;
}
F_271 ( ( unsigned long ) V_180 ) ;
}
return V_20 ;
}
