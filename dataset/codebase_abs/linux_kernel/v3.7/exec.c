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
V_21 , V_81 , V_80 , false ) )
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
struct V_107 V_108 = { . V_106 = V_106 } ;
static const struct V_109 V_110 = {
. V_111 = V_112 | V_113 | V_114 ,
. V_115 = V_116 | V_117 ,
. V_118 = V_119
} ;
V_105 = F_75 ( V_120 , & V_108 , & V_110 , V_121 ) ;
if ( F_48 ( V_105 ) )
goto V_69;
V_32 = - V_122 ;
if ( ! F_76 ( V_105 -> V_123 . V_124 -> V_125 -> V_126 ) )
goto exit;
if ( V_105 -> V_123 . V_127 -> V_128 & V_129 )
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
char * V_130 , unsigned long F_47 )
{
T_3 V_131 ;
T_4 V_18 = V_70 ;
int V_132 ;
V_131 = F_58 () ;
F_59 ( F_81 () ) ;
V_132 = F_82 ( V_105 , ( void T_1 * ) V_130 , F_47 , & V_18 ) ;
F_59 ( V_131 ) ;
return V_132 ;
}
static int F_83 ( struct V_11 * V_12 )
{
struct V_133 * V_134 ;
struct V_11 * V_135 , * V_136 ;
V_134 = V_13 ;
V_135 = V_13 -> V_12 ;
F_84 ( V_134 , V_135 ) ;
if ( V_135 ) {
F_85 ( V_135 ) ;
F_86 ( & V_135 -> V_37 ) ;
if ( F_43 ( V_135 -> V_137 ) ) {
F_87 ( & V_135 -> V_37 ) ;
return - V_138 ;
}
}
F_88 ( V_134 ) ;
V_136 = V_134 -> V_136 ;
V_134 -> V_12 = V_12 ;
V_134 -> V_136 = V_12 ;
F_89 ( V_136 , V_12 ) ;
F_90 ( V_134 ) ;
F_91 ( V_12 ) ;
if ( V_135 ) {
F_87 ( & V_135 -> V_37 ) ;
F_2 ( V_136 != V_135 ) ;
F_92 ( & V_134 -> signal -> V_139 , V_135 ) ;
F_93 ( V_135 ) ;
F_94 ( V_135 ) ;
return 0 ;
}
F_40 ( V_136 ) ;
return 0 ;
}
static int F_95 ( struct V_133 * V_134 )
{
struct V_140 * V_141 = V_134 -> signal ;
struct V_142 * V_143 = V_134 -> V_144 ;
T_5 * V_145 = & V_143 -> V_146 ;
if ( F_96 ( V_134 ) )
goto V_147;
F_97 ( V_145 ) ;
if ( F_98 ( V_141 ) ) {
F_99 ( V_145 ) ;
return - V_148 ;
}
V_141 -> V_149 = V_134 ;
V_141 -> V_150 = F_100 ( V_134 ) ;
if ( ! F_101 ( V_134 ) )
V_141 -> V_150 -- ;
while ( V_141 -> V_150 ) {
F_102 ( V_151 ) ;
F_99 ( V_145 ) ;
F_103 () ;
if ( F_43 ( F_104 ( V_134 ) ) )
goto V_152;
F_97 ( V_145 ) ;
}
F_99 ( V_145 ) ;
if ( ! F_101 ( V_134 ) ) {
struct V_133 * V_153 = V_134 -> V_154 ;
V_141 -> V_150 = - 1 ;
for (; ; ) {
F_105 ( & V_155 ) ;
if ( F_106 ( V_153 -> V_156 ) )
break;
F_102 ( V_151 ) ;
F_107 ( & V_155 ) ;
F_103 () ;
if ( F_43 ( F_104 ( V_134 ) ) )
goto V_152;
}
V_134 -> V_157 = V_153 -> V_157 ;
F_2 ( ! F_108 ( V_153 , V_134 ) ) ;
F_2 ( F_109 ( V_134 ) ) ;
F_110 ( V_134 , V_158 ) ;
V_134 -> V_159 = V_153 -> V_159 ;
F_111 ( V_134 , V_158 , F_112 ( V_153 ) ) ;
F_113 ( V_153 , V_134 , V_160 ) ;
F_113 ( V_153 , V_134 , V_161 ) ;
F_114 ( & V_153 -> V_162 , & V_134 -> V_162 ) ;
F_115 ( & V_153 -> V_163 , & V_134 -> V_163 ) ;
V_134 -> V_154 = V_134 ;
V_153 -> V_154 = V_134 ;
V_134 -> V_164 = V_165 ;
V_153 -> V_164 = - 1 ;
F_2 ( V_153 -> V_156 != V_166 ) ;
V_153 -> V_156 = V_167 ;
if ( F_43 ( V_153 -> V_168 ) )
F_116 ( V_153 , V_153 -> V_169 ) ;
F_107 ( & V_155 ) ;
F_117 ( V_153 ) ;
}
V_141 -> V_149 = NULL ;
V_141 -> V_150 = 0 ;
V_147:
V_134 -> V_164 = V_165 ;
F_118 ( V_141 ) ;
F_119 () ;
if ( F_120 ( & V_143 -> F_47 ) != 1 ) {
struct V_142 * V_170 ;
V_170 = F_121 ( V_171 , V_35 ) ;
if ( ! V_170 )
return - V_36 ;
F_122 ( & V_170 -> F_47 , 1 ) ;
memcpy ( V_170 -> V_172 , V_143 -> V_172 ,
sizeof( V_170 -> V_172 ) ) ;
F_105 ( & V_155 ) ;
F_123 ( & V_143 -> V_146 ) ;
F_124 ( V_134 -> V_144 , V_170 ) ;
F_125 ( & V_143 -> V_146 ) ;
F_107 ( & V_155 ) ;
F_126 ( V_143 ) ;
}
F_2 ( ! F_101 ( V_134 ) ) ;
return 0 ;
V_152:
F_127 ( & V_155 ) ;
V_141 -> V_149 = NULL ;
V_141 -> V_150 = 0 ;
F_128 ( & V_155 ) ;
return - V_148 ;
}
char * F_129 ( char * V_173 , struct V_133 * V_134 )
{
F_88 ( V_134 ) ;
strncpy ( V_173 , V_134 -> V_174 , sizeof( V_134 -> V_174 ) ) ;
F_90 ( V_134 ) ;
return V_173 ;
}
void F_130 ( struct V_133 * V_134 , char * V_173 )
{
F_88 ( V_134 ) ;
F_131 ( V_134 , V_173 ) ;
memset ( V_134 -> V_174 , 0 , V_175 ) ;
F_132 () ;
F_133 ( V_134 -> V_174 , V_173 , sizeof( V_134 -> V_174 ) ) ;
F_90 ( V_134 ) ;
F_134 ( V_134 ) ;
}
static void F_135 ( char * V_176 , const char * V_177 , unsigned int V_48 )
{
int V_31 , V_178 ;
for ( V_31 = 0 ; ( V_178 = * ( V_177 ++ ) ) != '\0' ; ) {
if ( V_178 == '/' )
V_31 = 0 ;
else
if ( V_31 < V_48 - 1 )
V_176 [ V_31 ++ ] = V_178 ;
}
V_176 [ V_31 ] = '\0' ;
}
int F_136 ( struct V_8 * V_9 )
{
int V_179 ;
V_179 = F_95 ( V_13 ) ;
if ( V_179 )
goto V_69;
F_137 ( V_9 -> V_12 , V_9 -> V_105 ) ;
F_135 ( V_9 -> V_176 , V_9 -> V_107 , sizeof( V_9 -> V_176 ) ) ;
F_11 ( V_9 , 0 ) ;
V_179 = F_83 ( V_9 -> V_12 ) ;
if ( V_179 )
goto V_69;
V_9 -> V_12 = NULL ;
F_59 ( V_180 ) ;
V_13 -> V_181 &=
~ ( V_182 | V_183 | V_184 | V_185 ) ;
F_138 () ;
V_13 -> V_186 &= ~ V_9 -> V_187 ;
return 0 ;
V_69:
return V_179 ;
}
void F_139 ( struct V_8 * V_9 , struct V_105 * V_105 )
{
if ( F_140 ( V_105 -> V_123 . V_124 -> V_125 , V_188 ) < 0 )
V_9 -> V_189 |= V_190 ;
}
void F_141 ( struct V_8 * V_9 )
{
F_91 ( V_13 -> V_12 ) ;
V_13 -> V_191 = V_13 -> V_192 = 0 ;
if ( F_142 ( F_143 () , F_144 () ) && F_145 ( F_146 () , F_147 () ) )
F_148 ( V_13 -> V_12 , V_193 ) ;
else
F_148 ( V_13 -> V_12 , V_194 ) ;
F_130 ( V_13 , V_9 -> V_176 ) ;
V_13 -> V_12 -> V_195 = V_196 ;
if ( ! F_142 ( V_9 -> V_197 -> V_198 , F_143 () ) ||
! F_145 ( V_9 -> V_197 -> V_199 , F_146 () ) ) {
V_13 -> V_200 = 0 ;
} else {
F_139 ( V_9 , V_9 -> V_105 ) ;
if ( V_9 -> V_189 & V_190 )
F_148 ( V_13 -> V_12 , V_194 ) ;
}
if ( ! F_149 ( V_13 -> V_12 ) )
F_150 ( V_13 ) ;
V_13 -> V_201 ++ ;
F_151 ( V_13 , 0 ) ;
F_152 ( V_13 -> V_202 ) ;
}
int F_153 ( struct V_8 * V_9 )
{
if ( F_154 ( & V_13 -> signal -> V_203 ) )
return - V_204 ;
V_9 -> V_197 = F_155 () ;
if ( F_106 ( V_9 -> V_197 ) )
return 0 ;
F_156 ( & V_13 -> signal -> V_203 ) ;
return - V_36 ;
}
void F_157 ( struct V_8 * V_9 )
{
F_21 ( V_9 ) ;
if ( V_9 -> V_197 ) {
F_156 ( & V_13 -> signal -> V_203 ) ;
F_158 ( V_9 -> V_197 ) ;
}
F_159 ( V_9 ) ;
}
void F_160 ( struct V_8 * V_9 )
{
F_161 ( V_9 ) ;
F_162 ( V_9 -> V_197 ) ;
V_9 -> V_197 = NULL ;
F_163 ( V_9 ) ;
F_156 ( & V_13 -> signal -> V_203 ) ;
}
static int F_164 ( struct V_8 * V_9 )
{
struct V_133 * V_47 = V_13 , * V_205 ;
unsigned V_206 ;
int V_207 = 0 ;
if ( V_47 -> V_168 ) {
if ( V_47 -> V_168 & V_208 )
V_9 -> V_209 |= V_210 ;
else
V_9 -> V_209 |= V_211 ;
}
if ( V_13 -> V_212 )
V_9 -> V_209 |= V_213 ;
V_206 = 1 ;
F_123 ( & V_47 -> V_214 -> V_145 ) ;
F_165 () ;
for ( V_205 = F_166 ( V_47 ) ; V_205 != V_47 ; V_205 = F_166 ( V_205 ) ) {
if ( V_205 -> V_214 == V_47 -> V_214 )
V_206 ++ ;
}
F_167 () ;
if ( V_47 -> V_214 -> V_215 > V_206 ) {
V_9 -> V_209 |= V_216 ;
} else {
V_207 = - V_148 ;
if ( ! V_47 -> V_214 -> V_217 ) {
V_47 -> V_214 -> V_217 = 1 ;
V_207 = 1 ;
}
}
F_125 ( & V_47 -> V_214 -> V_145 ) ;
return V_207 ;
}
int F_168 ( struct V_8 * V_9 )
{
T_6 V_218 ;
struct V_219 * V_219 = V_9 -> V_105 -> V_123 . V_124 -> V_125 ;
int V_179 ;
V_218 = V_219 -> V_126 ;
if ( V_9 -> V_105 -> V_220 == NULL )
return - V_122 ;
V_9 -> V_197 -> V_221 = F_143 () ;
V_9 -> V_197 -> V_222 = F_146 () ;
if ( ! ( V_9 -> V_105 -> V_123 . V_127 -> V_128 & V_223 ) &&
! V_13 -> V_212 ) {
if ( V_218 & V_224 ) {
if ( ! F_169 ( V_9 -> V_197 -> V_225 , V_219 -> V_226 ) )
return - V_227 ;
V_9 -> V_187 |= V_228 ;
V_9 -> V_197 -> V_221 = V_219 -> V_226 ;
}
if ( ( V_218 & ( V_229 | V_230 ) ) == ( V_229 | V_230 ) ) {
if ( ! F_170 ( V_9 -> V_197 -> V_225 , V_219 -> V_231 ) )
return - V_227 ;
V_9 -> V_187 |= V_228 ;
V_9 -> V_197 -> V_222 = V_219 -> V_231 ;
}
}
V_179 = F_171 ( V_9 ) ;
if ( V_179 )
return V_179 ;
V_9 -> V_232 = 1 ;
memset ( V_9 -> V_173 , 0 , V_233 ) ;
return F_80 ( V_9 -> V_105 , 0 , V_9 -> V_173 , V_233 ) ;
}
int F_172 ( struct V_8 * V_9 )
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
V_66 = F_173 ( V_17 ) ;
for (; V_70 < V_27 && V_66 [ V_70 ] ;
V_70 ++ , V_9 -> V_47 ++ )
;
F_174 ( V_66 ) ;
F_19 ( V_17 ) ;
if ( V_70 == V_27 )
F_20 ( V_9 , ( V_9 -> V_47 >> V_234 ) - 1 ) ;
} while ( V_70 == V_27 );
V_9 -> V_47 ++ ;
V_9 -> V_64 -- ;
V_20 = 0 ;
V_69:
return V_20 ;
}
int F_175 ( struct V_8 * V_9 , struct V_235 * V_236 )
{
unsigned int V_237 = V_9 -> V_238 ;
int V_239 , V_179 ;
struct V_1 * V_2 ;
T_7 V_240 , V_241 ;
V_179 = F_176 ( V_9 ) ;
if ( V_179 )
return V_179 ;
V_179 = F_177 ( V_9 ) ;
if ( V_179 )
return V_179 ;
V_240 = V_13 -> V_159 ;
F_165 () ;
V_241 = F_178 ( V_13 , F_179 ( V_13 -> V_169 ) ) ;
F_167 () ;
V_179 = - V_242 ;
for ( V_239 = 0 ; V_239 < 2 ; V_239 ++ ) {
F_127 ( & V_4 ) ;
F_180 (fmt, &formats, lh) {
int (* V_177)( struct V_8 * , struct V_235 * ) = V_2 -> V_243 ;
if ( ! V_177 )
continue;
if ( ! F_181 ( V_2 -> V_7 ) )
continue;
F_128 ( & V_4 ) ;
V_179 = V_177 ( V_9 , V_236 ) ;
V_9 -> V_238 = V_237 ;
if ( V_179 >= 0 ) {
if ( V_237 == 0 ) {
F_182 ( V_13 , V_240 , V_9 ) ;
F_183 ( V_244 , V_241 ) ;
}
F_9 ( V_2 ) ;
F_184 ( V_9 -> V_105 ) ;
if ( V_9 -> V_105 )
F_79 ( V_9 -> V_105 ) ;
V_9 -> V_105 = NULL ;
V_13 -> V_245 = 1 ;
F_185 ( V_13 ) ;
return V_179 ;
}
F_127 ( & V_4 ) ;
F_9 ( V_2 ) ;
if ( V_179 != - V_246 || V_9 -> V_12 == NULL )
break;
if ( ! V_9 -> V_105 ) {
F_128 ( & V_4 ) ;
return V_179 ;
}
}
F_128 ( & V_4 ) ;
#ifdef F_186
if ( V_179 != - V_246 || V_9 -> V_12 == NULL ) {
break;
} else {
#define F_187 ( T_8 ) (((c)=='\t') || ((c)=='\n') || (0x20<=(c) && (c)<=0x7e))
if ( F_187 ( V_9 -> V_173 [ 0 ] ) &&
F_187 ( V_9 -> V_173 [ 1 ] ) &&
F_187 ( V_9 -> V_173 [ 2 ] ) &&
F_187 ( V_9 -> V_173 [ 3 ] ) )
break;
if ( V_239 )
break;
F_188 ( L_1 , * ( unsigned short * ) ( & V_9 -> V_173 [ 2 ] ) ) ;
}
#else
break;
#endif
}
return V_179 ;
}
static int F_189 ( const char * V_107 ,
struct V_53 V_54 ,
struct V_53 V_247 ,
struct V_235 * V_236 )
{
struct V_8 * V_9 ;
struct V_105 * V_105 ;
struct V_248 * V_249 ;
bool V_250 ;
int V_179 ;
const struct V_197 * V_197 = F_190 () ;
if ( ( V_13 -> V_181 & V_251 ) &&
F_120 ( & V_197 -> V_252 -> V_253 ) > V_25 ( V_254 ) ) {
V_179 = - V_148 ;
goto V_255;
}
V_13 -> V_181 &= ~ V_251 ;
V_179 = F_191 ( & V_249 ) ;
if ( V_179 )
goto V_255;
V_179 = - V_36 ;
V_9 = F_192 ( sizeof( * V_9 ) , V_35 ) ;
if ( ! V_9 )
goto V_256;
V_179 = F_153 ( V_9 ) ;
if ( V_179 )
goto V_257;
V_179 = F_164 ( V_9 ) ;
if ( V_179 < 0 )
goto V_257;
V_250 = V_179 ;
V_13 -> V_258 = 1 ;
V_105 = F_74 ( V_107 ) ;
V_179 = F_193 ( V_105 ) ;
if ( F_48 ( V_105 ) )
goto V_259;
F_194 () ;
V_9 -> V_105 = V_105 ;
V_9 -> V_107 = V_107 ;
V_9 -> V_260 = V_107 ;
V_179 = F_37 ( V_9 ) ;
if ( V_179 )
goto V_261;
V_9 -> V_64 = F_47 ( V_54 , V_262 ) ;
if ( ( V_179 = V_9 -> V_64 ) < 0 )
goto V_69;
V_9 -> V_263 = F_47 ( V_247 , V_262 ) ;
if ( ( V_179 = V_9 -> V_263 ) < 0 )
goto V_69;
V_179 = F_168 ( V_9 ) ;
if ( V_179 < 0 )
goto V_69;
V_179 = F_57 ( 1 , & V_9 -> V_107 , V_9 ) ;
if ( V_179 < 0 )
goto V_69;
V_9 -> V_98 = V_9 -> V_47 ;
V_179 = F_51 ( V_9 -> V_263 , V_247 , V_9 ) ;
if ( V_179 < 0 )
goto V_69;
V_179 = F_51 ( V_9 -> V_64 , V_54 , V_9 ) ;
if ( V_179 < 0 )
goto V_69;
V_179 = F_175 ( V_9 , V_236 ) ;
if ( V_179 < 0 )
goto V_69;
V_13 -> V_214 -> V_217 = 0 ;
V_13 -> V_258 = 0 ;
F_195 ( V_13 ) ;
F_157 ( V_9 ) ;
if ( V_249 )
F_196 ( V_249 ) ;
return V_179 ;
V_69:
if ( V_9 -> V_12 ) {
F_11 ( V_9 , 0 ) ;
F_94 ( V_9 -> V_12 ) ;
}
V_261:
if ( V_9 -> V_105 ) {
F_184 ( V_9 -> V_105 ) ;
F_79 ( V_9 -> V_105 ) ;
}
V_259:
if ( V_250 )
V_13 -> V_214 -> V_217 = 0 ;
V_13 -> V_258 = 0 ;
V_257:
F_157 ( V_9 ) ;
V_256:
if ( V_249 )
F_197 ( V_249 ) ;
V_255:
return V_179 ;
}
int F_198 ( const char * V_107 ,
const char T_1 * const T_1 * V_73 ,
const char T_1 * const T_1 * V_264 ,
struct V_235 * V_236 )
{
struct V_53 V_54 = { . V_59 . V_56 = V_73 } ;
struct V_53 V_247 = { . V_59 . V_56 = V_264 } ;
return F_189 ( V_107 , V_54 , V_247 , V_236 ) ;
}
int F_199 ( const char * V_107 ,
const T_2 T_1 * V_73 ,
const T_2 T_1 * V_264 ,
struct V_235 * V_236 )
{
struct V_53 V_54 = {
. V_57 = true ,
. V_59 . V_58 = V_73 ,
} ;
struct V_53 V_247 = {
. V_57 = true ,
. V_59 . V_58 = V_264 ,
} ;
return F_189 ( V_107 , V_54 , V_247 , V_236 ) ;
}
void F_200 ( struct V_1 * V_265 )
{
struct V_11 * V_12 = V_13 -> V_12 ;
if ( V_12 -> V_266 )
F_10 ( V_12 -> V_266 -> V_7 ) ;
V_12 -> V_266 = V_265 ;
if ( V_265 )
F_201 ( V_265 -> V_7 ) ;
}
void F_148 ( struct V_11 * V_12 , int V_267 )
{
switch ( V_267 ) {
case V_268 :
F_202 ( V_269 , & V_12 -> V_181 ) ;
F_203 () ;
F_202 ( V_270 , & V_12 -> V_181 ) ;
break;
case V_193 :
F_204 ( V_269 , & V_12 -> V_181 ) ;
F_203 () ;
F_202 ( V_270 , & V_12 -> V_181 ) ;
break;
case V_271 :
F_204 ( V_270 , & V_12 -> V_181 ) ;
F_203 () ;
F_204 ( V_269 , & V_12 -> V_181 ) ;
break;
}
}
int F_205 ( unsigned long V_272 )
{
int V_20 ;
V_20 = V_272 & V_273 ;
return ( V_20 > V_193 ) ? V_271 : V_20 ;
}
int F_149 ( struct V_11 * V_12 )
{
return F_205 ( V_12 -> V_181 ) ;
}
T_9 long F_206 ( const char T_1 * V_107 ,
const T_2 T_1 * V_54 ,
const T_2 T_1 * V_247 )
{
struct V_107 * V_274 = F_207 ( V_107 ) ;
int error = F_193 ( V_274 ) ;
if ( ! F_48 ( V_274 ) ) {
error = F_199 ( V_274 -> V_106 , V_54 , V_247 ,
F_208 () ) ;
F_209 ( V_274 ) ;
}
return error ;
}
int F_210 ( const char * V_107 ,
const char * const V_54 [] ,
const char * const V_247 [] )
{
struct V_235 * V_47 = F_208 () ;
int V_20 ;
V_20 = F_198 ( V_107 ,
( const char T_1 * const T_1 * ) V_54 ,
( const char T_1 * const T_1 * ) V_247 , V_47 ) ;
if ( V_20 < 0 )
return V_20 ;
F_211 ( V_47 ) ;
}
