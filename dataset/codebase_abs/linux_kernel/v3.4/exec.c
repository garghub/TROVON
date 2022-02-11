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
V_32 = F_31 ( NULL , 0 , 0 , 0 , V_21 -> V_24 , 1 ) ;
if ( V_32 )
goto V_32;
V_32 = F_32 ( V_12 , V_21 ) ;
if ( V_32 )
goto V_32;
V_12 -> V_45 = V_12 -> V_46 = 1 ;
F_33 ( & V_12 -> V_37 ) ;
V_9 -> V_47 = V_21 -> V_23 - sizeof( void * ) ;
return 0 ;
V_32:
F_33 ( & V_12 -> V_37 ) ;
V_9 -> V_21 = NULL ;
F_34 ( V_34 , V_21 ) ;
return V_32 ;
}
static bool F_35 ( struct V_8 * V_9 , long V_48 )
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
V_17 = F_36 ( V_50 | V_51 ) ;
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
F_37 ( V_9 -> V_17 [ V_31 ] ) ;
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
static bool F_35 ( struct V_8 * V_9 , long V_48 )
{
return V_48 <= V_9 -> V_47 ;
}
int F_38 ( struct V_8 * V_9 )
{
int V_32 ;
struct V_11 * V_12 = NULL ;
V_9 -> V_12 = V_12 = F_39 () ;
V_32 = - V_36 ;
if ( ! V_12 )
goto V_32;
V_32 = F_40 ( V_13 , V_12 ) ;
if ( V_32 )
goto V_32;
V_32 = F_25 ( V_9 ) ;
if ( V_32 )
goto V_32;
return 0 ;
V_32:
if ( V_12 ) {
V_9 -> V_12 = NULL ;
F_41 ( V_12 ) ;
}
return V_32 ;
}
static const char T_1 * F_42 ( struct V_53 V_54 , int V_55 )
{
const char T_1 * V_56 ;
#ifdef F_43
if ( F_44 ( V_54 . V_57 ) ) {
T_2 V_58 ;
if ( F_45 ( V_58 , V_54 . V_59 . V_58 + V_55 ) )
return F_46 ( - V_60 ) ;
return F_47 ( V_58 ) ;
}
#endif
if ( F_45 ( V_56 , V_54 . V_59 . V_56 + V_55 ) )
return F_46 ( - V_60 ) ;
return V_56 ;
}
static int F_48 ( struct V_53 V_54 , int V_61 )
{
int V_31 = 0 ;
if ( V_54 . V_59 . V_56 != NULL ) {
for (; ; ) {
const char T_1 * V_47 = F_42 ( V_54 , V_31 ) ;
if ( ! V_47 )
break;
if ( F_49 ( V_47 ) )
return - V_60 ;
if ( V_31 ++ >= V_61 )
return - V_62 ;
if ( F_50 ( V_13 ) )
return - V_63 ;
F_51 () ;
}
}
return V_31 ;
}
static int F_52 ( int V_64 , struct V_53 V_54 ,
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
V_68 = F_42 ( V_54 , V_64 ) ;
if ( F_49 ( V_68 ) )
goto V_69;
V_48 = F_53 ( V_68 , V_49 ) ;
if ( ! V_48 )
goto V_69;
V_20 = - V_62 ;
if ( ! F_35 ( V_9 , V_48 ) )
goto V_69;
V_18 = V_9 -> V_47 ;
V_68 += V_48 ;
V_9 -> V_47 -= V_48 ;
while ( V_48 > 0 ) {
int V_70 , V_71 ;
if ( F_50 ( V_13 ) ) {
V_20 = - V_63 ;
goto V_69;
}
F_51 () ;
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
F_54 ( V_65 ) ;
F_55 ( V_65 ) ;
F_19 ( V_65 ) ;
}
V_65 = V_17 ;
V_66 = F_56 ( V_65 ) ;
V_67 = V_18 & V_72 ;
F_22 ( V_9 , V_67 , V_65 ) ;
}
if ( F_57 ( V_66 + V_70 , V_68 , V_71 ) ) {
V_20 = - V_60 ;
goto V_69;
}
}
}
V_20 = 0 ;
V_69:
if ( V_65 ) {
F_54 ( V_65 ) ;
F_55 ( V_65 ) ;
F_19 ( V_65 ) ;
}
return V_20 ;
}
int F_58 ( int V_64 , const char * const * V_73 ,
struct V_8 * V_9 )
{
int V_74 ;
T_3 V_75 = F_59 () ;
struct V_53 V_54 = {
. V_59 . V_56 = ( const char T_1 * const T_1 * ) V_73 ,
} ;
F_60 ( V_76 ) ;
V_74 = F_52 ( V_64 , V_54 , V_9 ) ;
F_60 ( V_75 ) ;
return V_74 ;
}
static int F_61 ( struct V_33 * V_21 , unsigned long V_77 )
{
struct V_11 * V_12 = V_21 -> V_38 ;
unsigned long V_78 = V_21 -> V_24 ;
unsigned long V_79 = V_21 -> V_23 ;
unsigned long V_80 = V_79 - V_78 ;
unsigned long V_81 = V_78 - V_77 ;
unsigned long V_82 = V_79 - V_77 ;
struct V_83 V_84 ;
F_2 ( V_81 > V_82 ) ;
if ( V_21 != F_62 ( V_12 , V_81 ) )
return - V_60 ;
if ( F_63 ( V_21 , V_81 , V_79 , V_21 -> V_85 , NULL ) )
return - V_36 ;
if ( V_80 != F_64 ( V_21 , V_78 ,
V_21 , V_81 , V_80 ) )
return - V_36 ;
F_65 () ;
F_66 ( & V_84 , V_12 , 0 ) ;
if ( V_82 > V_78 ) {
F_67 ( & V_84 , V_82 , V_79 , V_82 ,
V_21 -> V_86 ? V_21 -> V_86 -> V_24 : 0 ) ;
} else {
F_67 ( & V_84 , V_78 , V_79 , V_82 ,
V_21 -> V_86 ? V_21 -> V_86 -> V_24 : 0 ) ;
}
F_68 ( & V_84 , V_82 , V_79 ) ;
F_63 ( V_21 , V_81 , V_82 , V_21 -> V_85 , NULL ) ;
return 0 ;
}
int F_69 ( struct V_8 * V_9 ,
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
V_91 = F_70 ( V_29 ) ;
if ( V_91 > ( 1 << 30 ) )
V_91 = 1 << 30 ;
if ( V_21 -> V_23 - V_21 -> V_24 > V_91 )
return - V_36 ;
V_91 = F_71 ( V_87 - V_91 ) ;
V_89 = V_21 -> V_24 - V_91 ;
V_12 -> V_95 = V_9 -> V_47 - V_89 ;
V_9 -> V_47 = V_21 -> V_23 - V_89 ;
#else
V_87 = F_72 ( V_87 ) ;
V_87 = F_71 ( V_87 ) ;
if ( F_44 ( V_87 < V_96 ) ||
F_44 ( V_21 -> V_23 - V_21 -> V_24 >= V_87 - V_96 ) )
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
if ( F_44 ( V_88 == V_99 ) )
V_42 |= V_100 ;
else if ( V_88 == V_101 )
V_42 &= ~ V_100 ;
V_42 |= V_12 -> V_102 ;
V_42 |= V_40 ;
V_20 = F_73 ( V_21 , & V_90 , V_21 -> V_24 , V_21 -> V_23 ,
V_42 ) ;
if ( V_20 )
goto V_103;
F_2 ( V_90 != V_21 ) ;
if ( V_89 ) {
V_20 = F_61 ( V_21 , V_89 ) ;
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
V_20 = F_74 ( V_21 , V_91 ) ;
if ( V_20 )
V_20 = - V_60 ;
V_103:
F_33 ( & V_12 -> V_37 ) ;
return V_20 ;
}
struct V_105 * F_75 ( const char * V_106 )
{
struct V_105 * V_105 ;
int V_32 ;
static const struct V_107 V_108 = {
. V_109 = V_110 | V_111 | V_112 ,
. V_113 = V_114 | V_115 ,
. V_116 = V_117
} ;
V_105 = F_76 ( V_118 , V_106 , & V_108 , V_119 ) ;
if ( F_49 ( V_105 ) )
goto V_69;
V_32 = - V_120 ;
if ( ! F_77 ( V_105 -> V_121 . V_122 -> V_123 -> V_124 ) )
goto exit;
if ( V_105 -> V_121 . V_125 -> V_126 & V_127 )
goto exit;
F_78 ( V_105 ) ;
V_32 = F_79 ( V_105 ) ;
if ( V_32 )
goto exit;
V_69:
return V_105 ;
exit:
F_80 ( V_105 ) ;
return F_46 ( V_32 ) ;
}
int F_81 ( struct V_105 * V_105 , T_4 V_70 ,
char * V_128 , unsigned long F_48 )
{
T_3 V_129 ;
T_4 V_18 = V_70 ;
int V_130 ;
V_129 = F_59 () ;
F_60 ( F_82 () ) ;
V_130 = F_83 ( V_105 , ( void T_1 * ) V_128 , F_48 , & V_18 ) ;
F_60 ( V_129 ) ;
return V_130 ;
}
static int F_84 ( struct V_11 * V_12 )
{
struct V_131 * V_132 ;
struct V_11 * V_133 , * V_134 ;
V_132 = V_13 ;
V_133 = V_13 -> V_12 ;
F_85 ( V_133 ) ;
F_86 ( V_132 , V_133 ) ;
if ( V_133 ) {
F_87 ( & V_133 -> V_37 ) ;
if ( F_44 ( V_133 -> V_135 ) ) {
F_88 ( & V_133 -> V_37 ) ;
return - V_136 ;
}
}
F_89 ( V_132 ) ;
V_134 = V_132 -> V_134 ;
V_132 -> V_12 = V_12 ;
V_132 -> V_134 = V_12 ;
F_90 ( V_134 , V_12 ) ;
F_91 ( V_132 ) ;
F_92 ( V_12 ) ;
if ( V_133 ) {
F_88 ( & V_133 -> V_37 ) ;
F_2 ( V_134 != V_133 ) ;
F_93 ( & V_132 -> signal -> V_137 , V_133 ) ;
F_94 ( V_133 ) ;
F_95 ( V_133 ) ;
return 0 ;
}
F_41 ( V_134 ) ;
return 0 ;
}
static int F_96 ( struct V_131 * V_132 )
{
struct V_138 * V_139 = V_132 -> signal ;
struct V_140 * V_141 = V_132 -> V_142 ;
T_5 * V_143 = & V_141 -> V_144 ;
if ( F_97 ( V_132 ) )
goto V_145;
F_98 ( V_143 ) ;
if ( F_99 ( V_139 ) ) {
F_100 ( V_143 ) ;
return - V_146 ;
}
V_139 -> V_147 = V_132 ;
V_139 -> V_148 = F_101 ( V_132 ) ;
if ( ! F_102 ( V_132 ) )
V_139 -> V_148 -- ;
while ( V_139 -> V_148 ) {
F_103 ( V_149 ) ;
F_100 ( V_143 ) ;
F_104 () ;
F_98 ( V_143 ) ;
}
F_100 ( V_143 ) ;
if ( ! F_102 ( V_132 ) ) {
struct V_131 * V_150 = V_132 -> V_151 ;
V_139 -> V_148 = - 1 ;
for (; ; ) {
F_105 ( & V_152 ) ;
if ( F_106 ( V_150 -> V_153 ) )
break;
F_103 ( V_149 ) ;
F_107 ( & V_152 ) ;
F_104 () ;
}
V_132 -> V_154 = V_150 -> V_154 ;
F_2 ( ! F_108 ( V_150 , V_132 ) ) ;
F_2 ( F_109 ( V_132 ) ) ;
F_110 ( V_132 , V_155 ) ;
V_132 -> V_156 = V_150 -> V_156 ;
F_111 ( V_132 , V_155 , F_112 ( V_150 ) ) ;
F_113 ( V_150 , V_132 , V_157 ) ;
F_113 ( V_150 , V_132 , V_158 ) ;
F_114 ( & V_150 -> V_159 , & V_132 -> V_159 ) ;
F_115 ( & V_150 -> V_160 , & V_132 -> V_160 ) ;
V_132 -> V_151 = V_132 ;
V_150 -> V_151 = V_132 ;
V_132 -> V_161 = V_162 ;
V_150 -> V_161 = - 1 ;
F_2 ( V_150 -> V_153 != V_163 ) ;
V_150 -> V_153 = V_164 ;
if ( F_44 ( V_150 -> V_165 ) )
F_116 ( V_150 , V_150 -> V_166 ) ;
F_107 ( & V_152 ) ;
F_117 ( V_150 ) ;
}
V_139 -> V_147 = NULL ;
V_139 -> V_148 = 0 ;
V_145:
V_132 -> V_161 = V_162 ;
F_118 ( V_139 ) ;
F_119 () ;
if ( F_120 ( & V_141 -> F_48 ) != 1 ) {
struct V_140 * V_167 ;
V_167 = F_121 ( V_168 , V_35 ) ;
if ( ! V_167 )
return - V_36 ;
F_122 ( & V_167 -> F_48 , 1 ) ;
memcpy ( V_167 -> V_169 , V_141 -> V_169 ,
sizeof( V_167 -> V_169 ) ) ;
F_105 ( & V_152 ) ;
F_123 ( & V_141 -> V_144 ) ;
F_124 ( V_132 -> V_142 , V_167 ) ;
F_125 ( & V_141 -> V_144 ) ;
F_107 ( & V_152 ) ;
F_126 ( V_141 ) ;
}
F_2 ( ! F_102 ( V_132 ) ) ;
return 0 ;
}
static void F_127 ( struct V_170 * V_171 )
{
long V_172 = - 1 ;
struct V_173 * V_174 ;
F_123 ( & V_171 -> V_175 ) ;
for (; ; ) {
unsigned long V_176 , V_31 ;
V_172 ++ ;
V_31 = V_172 * V_177 ;
V_174 = F_128 ( V_171 ) ;
if ( V_31 >= V_174 -> V_178 )
break;
V_176 = V_174 -> V_179 [ V_172 ] ;
if ( ! V_176 )
continue;
V_174 -> V_179 [ V_172 ] = 0 ;
F_125 ( & V_171 -> V_175 ) ;
for ( ; V_176 ; V_31 ++ , V_176 >>= 1 ) {
if ( V_176 & 1 ) {
F_129 ( V_31 ) ;
}
}
F_123 ( & V_171 -> V_175 ) ;
}
F_125 ( & V_171 -> V_175 ) ;
}
char * F_130 ( char * V_180 , struct V_131 * V_132 )
{
F_89 ( V_132 ) ;
strncpy ( V_180 , V_132 -> V_181 , sizeof( V_132 -> V_181 ) ) ;
F_91 ( V_132 ) ;
return V_180 ;
}
void F_131 ( struct V_131 * V_132 , char * V_180 )
{
F_89 ( V_132 ) ;
F_132 ( V_132 , V_180 ) ;
memset ( V_132 -> V_181 , 0 , V_182 ) ;
F_133 () ;
F_134 ( V_132 -> V_181 , V_180 , sizeof( V_132 -> V_181 ) ) ;
F_91 ( V_132 ) ;
F_135 ( V_132 ) ;
}
static void F_136 ( char * V_183 , const char * V_184 , unsigned int V_48 )
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
int F_137 ( struct V_8 * V_9 )
{
int V_186 ;
V_186 = F_96 ( V_13 ) ;
if ( V_186 )
goto V_69;
F_138 ( V_9 -> V_12 , V_9 -> V_105 ) ;
F_136 ( V_9 -> V_183 , V_9 -> V_187 , sizeof( V_9 -> V_183 ) ) ;
F_11 ( V_9 , 0 ) ;
V_186 = F_84 ( V_9 -> V_12 ) ;
if ( V_186 )
goto V_69;
V_9 -> V_12 = NULL ;
F_60 ( V_188 ) ;
V_13 -> V_189 &= ~ ( V_190 | V_191 | V_192 ) ;
F_139 () ;
V_13 -> V_193 &= ~ V_9 -> V_194 ;
return 0 ;
V_69:
return V_186 ;
}
void F_140 ( struct V_8 * V_9 , struct V_105 * V_105 )
{
if ( F_141 ( V_105 -> V_121 . V_122 -> V_123 , V_195 ) < 0 )
V_9 -> V_196 |= V_197 ;
}
void F_142 ( struct V_8 * V_9 )
{
F_92 ( V_13 -> V_12 ) ;
V_13 -> V_198 = V_13 -> V_199 = 0 ;
if ( F_143 () == F_144 () && F_145 () == F_146 () )
F_147 ( V_13 -> V_12 , 1 ) ;
else
F_147 ( V_13 -> V_12 , V_200 ) ;
F_131 ( V_13 , V_9 -> V_183 ) ;
V_13 -> V_12 -> V_201 = V_202 ;
if ( V_9 -> V_203 -> V_204 != F_143 () ||
V_9 -> V_203 -> V_205 != F_145 () ) {
V_13 -> V_206 = 0 ;
} else {
F_140 ( V_9 , V_9 -> V_105 ) ;
if ( V_9 -> V_196 & V_197 )
F_147 ( V_13 -> V_12 , V_200 ) ;
}
if ( ! F_148 ( V_13 -> V_12 ) )
F_149 ( V_13 ) ;
V_13 -> V_207 ++ ;
F_150 ( V_13 , 0 ) ;
F_127 ( V_13 -> V_171 ) ;
}
int F_151 ( struct V_8 * V_9 )
{
if ( F_152 ( & V_13 -> signal -> V_208 ) )
return - V_209 ;
V_9 -> V_203 = F_153 () ;
if ( F_106 ( V_9 -> V_203 ) )
return 0 ;
F_154 ( & V_13 -> signal -> V_208 ) ;
return - V_36 ;
}
void F_155 ( struct V_8 * V_9 )
{
F_21 ( V_9 ) ;
if ( V_9 -> V_203 ) {
F_154 ( & V_13 -> signal -> V_208 ) ;
F_156 ( V_9 -> V_203 ) ;
}
F_157 ( V_9 ) ;
}
void F_158 ( struct V_8 * V_9 )
{
F_159 ( V_9 ) ;
F_160 ( V_9 -> V_203 ) ;
V_9 -> V_203 = NULL ;
F_161 ( V_9 ) ;
F_154 ( & V_13 -> signal -> V_208 ) ;
}
static int F_162 ( struct V_8 * V_9 )
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
V_211 = 1 ;
F_123 ( & V_47 -> V_217 -> V_143 ) ;
F_163 () ;
for ( V_210 = F_164 ( V_47 ) ; V_210 != V_47 ; V_210 = F_164 ( V_210 ) ) {
if ( V_210 -> V_217 == V_47 -> V_217 )
V_211 ++ ;
}
F_165 () ;
if ( V_47 -> V_217 -> V_218 > V_211 ) {
V_9 -> V_214 |= V_219 ;
} else {
V_212 = - V_146 ;
if ( ! V_47 -> V_217 -> V_220 ) {
V_47 -> V_217 -> V_220 = 1 ;
V_212 = 1 ;
}
}
F_125 ( & V_47 -> V_217 -> V_143 ) ;
return V_212 ;
}
int F_166 ( struct V_8 * V_9 )
{
T_6 V_221 ;
struct V_222 * V_222 = V_9 -> V_105 -> V_121 . V_122 -> V_123 ;
int V_186 ;
V_221 = V_222 -> V_124 ;
if ( V_9 -> V_105 -> V_223 == NULL )
return - V_120 ;
V_9 -> V_203 -> V_224 = F_143 () ;
V_9 -> V_203 -> V_225 = F_145 () ;
if ( ! ( V_9 -> V_105 -> V_121 . V_125 -> V_126 & V_226 ) ) {
if ( V_221 & V_227 ) {
V_9 -> V_194 |= V_228 ;
V_9 -> V_203 -> V_224 = V_222 -> V_229 ;
}
if ( ( V_221 & ( V_230 | V_231 ) ) == ( V_230 | V_231 ) ) {
V_9 -> V_194 |= V_228 ;
V_9 -> V_203 -> V_225 = V_222 -> V_232 ;
}
}
V_186 = F_167 ( V_9 ) ;
if ( V_186 )
return V_186 ;
V_9 -> V_233 = 1 ;
memset ( V_9 -> V_180 , 0 , V_234 ) ;
return F_81 ( V_9 -> V_105 , 0 , V_9 -> V_180 , V_234 ) ;
}
int F_168 ( struct V_8 * V_9 )
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
V_66 = F_169 ( V_17 ) ;
for (; V_70 < V_27 && V_66 [ V_70 ] ;
V_70 ++ , V_9 -> V_47 ++ )
;
F_170 ( V_66 ) ;
F_19 ( V_17 ) ;
if ( V_70 == V_27 )
F_20 ( V_9 , ( V_9 -> V_47 >> V_235 ) - 1 ) ;
} while ( V_70 == V_27 );
V_9 -> V_47 ++ ;
V_9 -> V_64 -- ;
V_20 = 0 ;
V_69:
return V_20 ;
}
int F_171 ( struct V_8 * V_9 , struct V_236 * V_237 )
{
unsigned int V_238 = V_9 -> V_239 ;
int V_240 , V_186 ;
struct V_1 * V_2 ;
T_7 V_241 , V_242 ;
V_186 = F_172 ( V_9 ) ;
if ( V_186 )
return V_186 ;
V_186 = F_173 ( V_9 ) ;
if ( V_186 )
return V_186 ;
V_241 = V_13 -> V_156 ;
F_163 () ;
V_242 = F_174 ( V_13 , F_175 ( V_13 -> V_166 ) ) ;
F_165 () ;
V_186 = - V_243 ;
for ( V_240 = 0 ; V_240 < 2 ; V_240 ++ ) {
F_176 ( & V_4 ) ;
F_177 (fmt, &formats, lh) {
int (* V_184)( struct V_8 * , struct V_236 * ) = V_2 -> V_244 ;
if ( ! V_184 )
continue;
if ( ! F_178 ( V_2 -> V_7 ) )
continue;
F_179 ( & V_4 ) ;
V_186 = V_184 ( V_9 , V_237 ) ;
V_9 -> V_239 = V_238 ;
if ( V_186 >= 0 ) {
if ( V_238 == 0 ) {
F_180 ( V_13 , V_241 , V_9 ) ;
F_181 ( V_245 , V_242 ) ;
}
F_9 ( V_2 ) ;
F_182 ( V_9 -> V_105 ) ;
if ( V_9 -> V_105 )
F_80 ( V_9 -> V_105 ) ;
V_9 -> V_105 = NULL ;
V_13 -> V_246 = 1 ;
F_183 ( V_13 ) ;
return V_186 ;
}
F_176 ( & V_4 ) ;
F_9 ( V_2 ) ;
if ( V_186 != - V_247 || V_9 -> V_12 == NULL )
break;
if ( ! V_9 -> V_105 ) {
F_179 ( & V_4 ) ;
return V_186 ;
}
}
F_179 ( & V_4 ) ;
#ifdef F_184
if ( V_186 != - V_247 || V_9 -> V_12 == NULL ) {
break;
} else {
#define F_185 ( T_8 ) (((c)=='\t') || ((c)=='\n') || (0x20<=(c) && (c)<=0x7e))
if ( F_185 ( V_9 -> V_180 [ 0 ] ) &&
F_185 ( V_9 -> V_180 [ 1 ] ) &&
F_185 ( V_9 -> V_180 [ 2 ] ) &&
F_185 ( V_9 -> V_180 [ 3 ] ) )
break;
if ( V_240 )
break;
F_186 ( L_1 , * ( unsigned short * ) ( & V_9 -> V_180 [ 2 ] ) ) ;
}
#else
break;
#endif
}
return V_186 ;
}
static int F_187 ( const char * V_187 ,
struct V_53 V_54 ,
struct V_53 V_248 ,
struct V_236 * V_237 )
{
struct V_8 * V_9 ;
struct V_105 * V_105 ;
struct V_170 * V_249 ;
bool V_250 ;
int V_186 ;
const struct V_203 * V_203 = F_188 () ;
if ( ( V_13 -> V_189 & V_251 ) &&
F_120 ( & V_203 -> V_252 -> V_253 ) > V_25 ( V_254 ) ) {
V_186 = - V_146 ;
goto V_255;
}
V_13 -> V_189 &= ~ V_251 ;
V_186 = F_189 ( & V_249 ) ;
if ( V_186 )
goto V_255;
V_186 = - V_36 ;
V_9 = F_190 ( sizeof( * V_9 ) , V_35 ) ;
if ( ! V_9 )
goto V_256;
V_186 = F_151 ( V_9 ) ;
if ( V_186 )
goto V_257;
V_186 = F_162 ( V_9 ) ;
if ( V_186 < 0 )
goto V_257;
V_250 = V_186 ;
V_13 -> V_258 = 1 ;
V_105 = F_75 ( V_187 ) ;
V_186 = F_191 ( V_105 ) ;
if ( F_49 ( V_105 ) )
goto V_259;
F_192 () ;
V_9 -> V_105 = V_105 ;
V_9 -> V_187 = V_187 ;
V_9 -> V_260 = V_187 ;
V_186 = F_38 ( V_9 ) ;
if ( V_186 )
goto V_261;
V_9 -> V_64 = F_48 ( V_54 , V_262 ) ;
if ( ( V_186 = V_9 -> V_64 ) < 0 )
goto V_69;
V_9 -> V_263 = F_48 ( V_248 , V_262 ) ;
if ( ( V_186 = V_9 -> V_263 ) < 0 )
goto V_69;
V_186 = F_166 ( V_9 ) ;
if ( V_186 < 0 )
goto V_69;
V_186 = F_58 ( 1 , & V_9 -> V_187 , V_9 ) ;
if ( V_186 < 0 )
goto V_69;
V_9 -> V_98 = V_9 -> V_47 ;
V_186 = F_52 ( V_9 -> V_263 , V_248 , V_9 ) ;
if ( V_186 < 0 )
goto V_69;
V_186 = F_52 ( V_9 -> V_64 , V_54 , V_9 ) ;
if ( V_186 < 0 )
goto V_69;
V_186 = F_171 ( V_9 , V_237 ) ;
if ( V_186 < 0 )
goto V_69;
V_13 -> V_217 -> V_220 = 0 ;
V_13 -> V_258 = 0 ;
F_193 ( V_13 ) ;
F_155 ( V_9 ) ;
if ( V_249 )
F_194 ( V_249 ) ;
return V_186 ;
V_69:
if ( V_9 -> V_12 ) {
F_11 ( V_9 , 0 ) ;
F_95 ( V_9 -> V_12 ) ;
}
V_261:
if ( V_9 -> V_105 ) {
F_182 ( V_9 -> V_105 ) ;
F_80 ( V_9 -> V_105 ) ;
}
V_259:
if ( V_250 )
V_13 -> V_217 -> V_220 = 0 ;
V_13 -> V_258 = 0 ;
V_257:
F_155 ( V_9 ) ;
V_256:
if ( V_249 )
F_195 ( V_249 ) ;
V_255:
return V_186 ;
}
int F_196 ( const char * V_187 ,
const char T_1 * const T_1 * V_73 ,
const char T_1 * const T_1 * V_264 ,
struct V_236 * V_237 )
{
struct V_53 V_54 = { . V_59 . V_56 = V_73 } ;
struct V_53 V_248 = { . V_59 . V_56 = V_264 } ;
return F_187 ( V_187 , V_54 , V_248 , V_237 ) ;
}
int F_197 ( char * V_187 ,
T_2 T_1 * V_73 ,
T_2 T_1 * V_264 ,
struct V_236 * V_237 )
{
struct V_53 V_54 = {
. V_57 = true ,
. V_59 . V_58 = V_73 ,
} ;
struct V_53 V_248 = {
. V_57 = true ,
. V_59 . V_58 = V_264 ,
} ;
return F_187 ( V_187 , V_54 , V_248 , V_237 ) ;
}
void F_198 ( struct V_1 * V_265 )
{
struct V_11 * V_12 = V_13 -> V_12 ;
if ( V_12 -> V_266 )
F_10 ( V_12 -> V_266 -> V_7 ) ;
V_12 -> V_266 = V_265 ;
if ( V_265 )
F_199 ( V_265 -> V_7 ) ;
}
static int F_200 ( struct V_267 * V_268 )
{
char * V_269 = V_268 -> V_270 ;
V_268 -> V_22 = V_271 * F_201 ( & V_272 ) ;
V_268 -> V_270 = F_202 ( V_269 , V_268 -> V_22 , V_35 ) ;
if ( ! V_268 -> V_270 ) {
F_157 ( V_269 ) ;
return - V_36 ;
}
return 0 ;
}
static int F_203 ( struct V_267 * V_268 , const char * V_2 , ... )
{
char * V_273 ;
int V_274 ;
int V_20 ;
T_9 V_275 ;
va_start ( V_275 , V_2 ) ;
V_274 = vsnprintf ( NULL , 0 , V_2 , V_275 ) ;
va_end ( V_275 ) ;
if ( F_106 ( V_274 < V_268 -> V_22 - V_268 -> V_276 - 1 ) )
goto V_277;
V_20 = F_200 ( V_268 ) ;
if ( V_20 )
goto V_278;
V_277:
V_273 = V_268 -> V_270 + V_268 -> V_276 ;
va_start ( V_275 , V_2 ) ;
vsnprintf ( V_273 , V_274 + 1 , V_2 , V_275 ) ;
va_end ( V_275 ) ;
V_268 -> V_276 += V_274 ;
return 0 ;
V_278:
return V_20 ;
}
static void F_204 ( char * V_68 )
{
for (; * V_68 ; V_68 ++ )
if ( * V_68 == '/' )
* V_68 = '!' ;
}
static int F_205 ( struct V_267 * V_268 )
{
struct V_105 * V_279 ;
char * V_280 , * V_281 ;
int V_20 ;
V_279 = F_206 ( V_13 -> V_12 ) ;
if ( ! V_279 ) {
char * V_282 = V_268 -> V_270 + V_268 -> V_276 ;
V_20 = F_203 ( V_268 , L_2 , V_13 -> V_181 ) ;
F_204 ( V_282 ) ;
return V_20 ;
}
V_280 = F_207 ( V_283 , V_284 ) ;
if ( ! V_280 ) {
V_20 = - V_36 ;
goto V_285;
}
V_281 = F_208 ( & V_279 -> V_121 , V_280 , V_283 ) ;
if ( F_49 ( V_281 ) ) {
V_20 = F_191 ( V_281 ) ;
goto V_286;
}
F_204 ( V_281 ) ;
V_20 = F_203 ( V_268 , L_3 , V_281 ) ;
V_286:
F_157 ( V_280 ) ;
V_285:
F_80 ( V_279 ) ;
return V_20 ;
}
static int F_209 ( struct V_267 * V_268 , long V_287 )
{
const struct V_203 * V_203 = F_188 () ;
const char * V_288 = V_289 ;
int V_290 = ( * V_288 == '|' ) ;
int V_291 = 0 ;
int V_32 = 0 ;
V_268 -> V_22 = V_271 * F_120 ( & V_272 ) ;
V_268 -> V_270 = F_207 ( V_268 -> V_22 , V_35 ) ;
V_268 -> V_276 = 0 ;
if ( ! V_268 -> V_270 )
return - V_36 ;
while ( * V_288 ) {
if ( * V_288 != '%' ) {
if ( * V_288 == 0 )
goto V_69;
V_32 = F_203 ( V_268 , L_4 , * V_288 ++ ) ;
} else {
switch ( * ++ V_288 ) {
case 0 :
goto V_69;
case '%' :
V_32 = F_203 ( V_268 , L_4 , '%' ) ;
break;
case 'p' :
V_291 = 1 ;
V_32 = F_203 ( V_268 , L_5 ,
F_210 ( V_13 ) ) ;
break;
case 'u' :
V_32 = F_203 ( V_268 , L_5 , V_203 -> V_204 ) ;
break;
case 'g' :
V_32 = F_203 ( V_268 , L_5 , V_203 -> V_205 ) ;
break;
case 's' :
V_32 = F_203 ( V_268 , L_6 , V_287 ) ;
break;
case 't' : {
struct V_292 V_293 ;
F_211 ( & V_293 ) ;
V_32 = F_203 ( V_268 , L_7 , V_293 . V_294 ) ;
break;
}
case 'h' : {
char * V_295 = V_268 -> V_270 + V_268 -> V_276 ;
F_87 ( & V_296 ) ;
V_32 = F_203 ( V_268 , L_3 ,
F_212 () -> V_297 ) ;
F_88 ( & V_296 ) ;
F_204 ( V_295 ) ;
break;
}
case 'e' : {
char * V_282 = V_268 -> V_270 + V_268 -> V_276 ;
V_32 = F_203 ( V_268 , L_3 , V_13 -> V_181 ) ;
F_204 ( V_282 ) ;
break;
}
case 'E' :
V_32 = F_205 ( V_268 ) ;
break;
case 'c' :
V_32 = F_203 ( V_268 , L_7 ,
V_25 ( V_298 ) ) ;
break;
default:
break;
}
++ V_288 ;
}
if ( V_32 )
return V_32 ;
}
if ( ! V_290 && ! V_291 && V_299 ) {
V_32 = F_203 ( V_268 , L_8 , F_210 ( V_13 ) ) ;
if ( V_32 )
return V_32 ;
}
V_69:
return V_290 ;
}
static int F_213 ( struct V_131 * V_300 , int V_301 )
{
struct V_131 * V_210 ;
int V_55 = 0 ;
V_300 -> signal -> V_189 = V_302 ;
V_300 -> signal -> V_303 = V_301 ;
V_300 -> signal -> V_304 = 0 ;
V_210 = V_300 ;
do {
F_214 ( V_210 , V_305 ) ;
if ( V_210 != V_13 && V_210 -> V_12 ) {
F_215 ( & V_210 -> V_306 . signal , V_307 ) ;
F_216 ( V_210 , 1 ) ;
V_55 ++ ;
}
} while_each_thread(start, t) ;
inline int F_217 ( struct V_131 * V_132 , struct V_11 * V_12 ,
struct V_135 * V_135 , int V_301 )
{
struct V_131 * V_308 , * V_47 ;
unsigned long V_189 ;
int V_55 = - V_146 ;
F_98 ( & V_132 -> V_142 -> V_144 ) ;
if ( ! F_99 ( V_132 -> signal ) ) {
V_12 -> V_135 = V_135 ;
V_55 = F_213 ( V_132 , V_301 ) ;
}
F_100 ( & V_132 -> V_142 -> V_144 ) ;
if ( F_44 ( V_55 < 0 ) )
return V_55 ;
if ( F_120 ( & V_12 -> V_309 ) == V_55 + 1 )
goto V_310;
F_163 () ;
F_218 (g) {
if ( V_308 == V_132 -> V_151 )
continue;
if ( V_308 -> V_189 & V_192 )
continue;
V_47 = V_308 ;
do {
if ( V_47 -> V_12 ) {
if ( F_44 ( V_47 -> V_12 == V_12 ) ) {
F_219 ( V_47 , & V_189 ) ;
V_55 += F_213 ( V_47 , V_301 ) ;
F_220 ( V_47 , & V_189 ) ;
}
break;
}
} while_each_thread(g, p) ;
}
int F_221 ( int V_301 , struct V_135 * V_135 )
{
struct V_131 * V_132 = V_13 ;
struct V_11 * V_12 = V_132 -> V_12 ;
int V_311 = - V_312 ;
F_222 ( & V_135 -> V_313 ) ;
V_135 -> V_314 . V_315 = V_132 ;
V_135 -> V_314 . V_316 = NULL ;
F_27 ( & V_12 -> V_37 ) ;
if ( ! V_12 -> V_135 )
V_311 = F_217 ( V_132 , V_12 , V_135 , V_301 ) ;
F_33 ( & V_12 -> V_37 ) ;
if ( V_311 > 0 )
F_223 ( & V_135 -> V_313 ) ;
return V_311 ;
}
static void F_224 ( struct V_11 * V_12 )
{
struct V_317 * V_318 , * V_316 ;
struct V_131 * V_315 ;
V_316 = V_12 -> V_135 -> V_314 . V_316 ;
while ( ( V_318 = V_316 ) != NULL ) {
V_316 = V_318 -> V_316 ;
V_315 = V_318 -> V_315 ;
F_225 () ;
V_318 -> V_315 = NULL ;
F_226 ( V_315 ) ;
}
V_12 -> V_135 = NULL ;
}
void F_147 ( struct V_11 * V_12 , int V_319 )
{
switch ( V_319 ) {
case 0 :
F_227 ( V_320 , & V_12 -> V_189 ) ;
F_228 () ;
F_227 ( V_321 , & V_12 -> V_189 ) ;
break;
case 1 :
F_229 ( V_320 , & V_12 -> V_189 ) ;
F_228 () ;
F_227 ( V_321 , & V_12 -> V_189 ) ;
break;
case 2 :
F_229 ( V_321 , & V_12 -> V_189 ) ;
F_228 () ;
F_229 ( V_320 , & V_12 -> V_189 ) ;
break;
}
}
static int F_230 ( unsigned long V_322 )
{
int V_20 ;
V_20 = V_322 & V_323 ;
return ( V_20 >= 2 ) ? 2 : V_20 ;
}
int F_148 ( struct V_11 * V_12 )
{
return F_230 ( V_12 -> V_189 ) ;
}
static void F_231 ( struct V_105 * V_105 )
{
struct V_324 * V_325 ;
V_325 = V_105 -> V_121 . V_122 -> V_123 -> V_326 ;
F_232 ( V_325 ) ;
V_325 -> V_327 ++ ;
V_325 -> V_328 -- ;
while ( ( V_325 -> V_327 > 1 ) && ( ! F_233 ( V_13 ) ) ) {
F_234 ( & V_325 -> V_329 ) ;
F_235 ( & V_325 -> V_330 , V_331 , V_332 ) ;
F_236 ( V_325 ) ;
}
V_325 -> V_327 -- ;
V_325 -> V_328 ++ ;
F_237 ( V_325 ) ;
}
static int F_238 ( struct V_333 * V_334 , struct V_203 * V_265 )
{
struct V_105 * V_335 , * V_336 ;
struct V_173 * V_174 ;
struct V_337 * V_338 = (struct V_337 * ) V_334 -> V_339 ;
struct V_170 * V_340 = V_13 -> V_171 ;
V_336 = F_239 ( 0 ) ;
if ( F_49 ( V_336 ) )
return F_191 ( V_336 ) ;
V_335 = F_240 ( V_336 , 0 ) ;
if ( F_49 ( V_335 ) ) {
F_241 ( V_336 ) ;
return F_191 ( V_335 ) ;
}
V_338 -> V_105 = V_336 ;
F_129 ( 0 ) ;
F_242 ( 0 , V_335 ) ;
F_123 ( & V_340 -> V_175 ) ;
V_174 = F_128 ( V_340 ) ;
F_243 ( 0 , V_174 ) ;
F_244 ( 0 , V_174 ) ;
F_125 ( & V_340 -> V_175 ) ;
V_13 -> signal -> V_26 [ V_298 ] = (struct V_25 ) { 1 , 1 } ;
return 0 ;
}
void F_245 ( long V_287 , int V_301 , struct V_236 * V_237 )
{
struct V_135 V_135 ;
struct V_267 V_268 ;
struct V_11 * V_12 = V_13 -> V_12 ;
struct V_1 * V_266 ;
const struct V_203 * V_341 ;
struct V_203 * V_203 ;
int V_186 = 0 ;
int V_342 = 0 ;
int V_290 ;
static T_10 V_343 = F_246 ( 0 ) ;
struct V_337 V_344 = {
. V_287 = V_287 ,
. V_237 = V_237 ,
. V_345 = V_25 ( V_298 ) ,
. V_322 = V_12 -> V_189 ,
} ;
F_247 ( V_287 ) ;
V_266 = V_12 -> V_266 ;
if ( ! V_266 || ! V_266 -> V_346 )
goto V_347;
if ( ! F_230 ( V_344 . V_322 ) )
goto V_347;
V_203 = F_248 () ;
if ( ! V_203 )
goto V_347;
if ( F_230 ( V_344 . V_322 ) == 2 ) {
V_342 = V_348 ;
V_203 -> V_349 = 0 ;
}
V_186 = F_221 ( V_301 , & V_135 ) ;
if ( V_186 < 0 )
goto V_350;
V_341 = F_249 ( V_203 ) ;
F_250 ( V_351 ) ;
V_290 = F_209 ( & V_268 , V_287 ) ;
if ( V_290 ) {
int V_352 ;
char * * V_353 ;
if ( V_290 < 0 ) {
F_251 ( V_354 L_9 ) ;
F_251 ( V_354 L_10 ) ;
goto V_355;
}
if ( V_344 . V_345 == 1 ) {
F_251 ( V_354
L_11 ,
F_210 ( V_13 ) , V_13 -> V_181 ) ;
F_251 ( V_354 L_10 ) ;
goto V_356;
}
V_344 . V_345 = V_357 ;
V_352 = F_201 ( & V_343 ) ;
if ( V_358 && ( V_358 < V_352 ) ) {
F_251 ( V_354 L_12 ,
F_210 ( V_13 ) , V_13 -> V_181 ) ;
F_251 ( V_354 L_13 ) ;
goto V_359;
}
V_353 = F_252 ( V_35 , V_268 . V_270 + 1 , NULL ) ;
if ( ! V_353 ) {
F_251 ( V_354 L_14 ,
V_360 ) ;
goto V_359;
}
V_186 = F_253 ( V_353 [ 0 ] , V_353 ,
NULL , V_361 , F_238 ,
NULL , & V_344 ) ;
F_254 ( V_353 ) ;
if ( V_186 ) {
F_251 ( V_362 L_15 ,
V_268 . V_270 ) ;
goto V_363;
}
} else {
struct V_222 * V_222 ;
if ( V_344 . V_345 < V_266 -> V_364 )
goto V_356;
V_344 . V_105 = F_255 ( V_268 . V_270 ,
V_365 | 2 | V_366 | V_110 | V_342 ,
0600 ) ;
if ( F_49 ( V_344 . V_105 ) )
goto V_356;
V_222 = V_344 . V_105 -> V_121 . V_122 -> V_123 ;
if ( V_222 -> V_367 > 1 )
goto V_363;
if ( F_256 ( V_344 . V_105 -> V_121 . V_122 ) )
goto V_363;
if ( ! F_77 ( V_222 -> V_124 ) )
goto V_363;
if ( V_222 -> V_229 != F_257 () )
goto V_363;
if ( ! V_344 . V_105 -> V_223 || ! V_344 . V_105 -> V_223 -> V_19 )
goto V_363;
if ( F_258 ( V_344 . V_105 -> V_121 . V_122 , 0 , 0 , V_344 . V_105 ) )
goto V_363;
}
V_186 = V_266 -> V_346 ( & V_344 ) ;
if ( V_186 )
V_13 -> signal -> V_303 |= 0x80 ;
if ( V_290 && V_358 )
F_231 ( V_344 . V_105 ) ;
V_363:
if ( V_344 . V_105 )
F_259 ( V_344 . V_105 , NULL ) ;
V_359:
if ( V_290 )
F_260 ( & V_343 ) ;
V_356:
F_157 ( V_268 . V_270 ) ;
V_355:
F_224 ( V_12 ) ;
F_261 ( V_341 ) ;
V_350:
F_262 ( V_203 ) ;
V_347:
return;
}
int F_263 ( struct V_105 * V_105 , const void * V_128 , int V_55 )
{
return F_264 ( V_368 , V_128 , V_55 ) && V_105 -> V_223 -> V_19 ( V_105 , V_128 , V_55 , & V_105 -> V_369 ) == V_55 ;
}
int F_265 ( struct V_105 * V_105 , T_4 V_370 )
{
int V_20 = 1 ;
if ( V_105 -> V_223 -> V_371 && V_105 -> V_223 -> V_371 != V_372 ) {
if ( V_105 -> V_223 -> V_371 ( V_105 , V_370 , V_373 ) < 0 )
return 0 ;
} else {
char * V_180 = ( char * ) F_266 ( V_35 ) ;
if ( ! V_180 )
return 0 ;
while ( V_370 > 0 ) {
unsigned long V_374 = V_370 ;
if ( V_374 > V_27 )
V_374 = V_27 ;
if ( ! F_263 ( V_105 , V_180 , V_374 ) ) {
V_20 = 0 ;
break;
}
V_370 -= V_374 ;
}
F_267 ( ( unsigned long ) V_180 ) ;
}
return V_20 ;
}
