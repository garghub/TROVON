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
static int F_37 ( struct V_8 * V_9 )
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
if ( V_31 >= V_61 )
return - V_62 ;
++ V_31 ;
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
if ( ! F_76 ( F_77 ( V_105 ) -> V_123 ) )
goto exit;
if ( V_105 -> V_124 . V_125 -> V_126 & V_127 )
goto exit;
F_78 ( V_105 ) ;
V_32 = F_79 ( V_105 ) ;
if ( V_32 )
goto exit;
V_69:
return V_105 ;
exit:
F_80 ( V_105 ) ;
return F_45 ( V_32 ) ;
}
int F_81 ( struct V_105 * V_105 , T_4 V_70 ,
char * V_128 , unsigned long F_47 )
{
T_3 V_129 ;
T_4 V_18 = V_70 ;
int V_130 ;
V_129 = F_58 () ;
F_59 ( F_82 () ) ;
V_130 = F_83 ( V_105 , ( void T_1 * ) V_128 , F_47 , & V_18 ) ;
F_59 ( V_129 ) ;
return V_130 ;
}
static int F_84 ( struct V_11 * V_12 )
{
struct V_131 * V_132 ;
struct V_11 * V_133 , * V_134 ;
V_132 = V_13 ;
V_133 = V_13 -> V_12 ;
F_85 ( V_132 , V_133 ) ;
if ( V_133 ) {
F_86 ( V_133 ) ;
F_87 ( & V_133 -> V_37 ) ;
if ( F_43 ( V_133 -> V_135 ) ) {
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
F_40 ( V_134 ) ;
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
if ( F_43 ( F_105 ( V_132 ) ) )
goto V_150;
F_98 ( V_143 ) ;
}
F_100 ( V_143 ) ;
if ( ! F_102 ( V_132 ) ) {
struct V_131 * V_151 = V_132 -> V_152 ;
V_139 -> V_148 = - 1 ;
for (; ; ) {
F_106 ( & V_153 ) ;
if ( F_107 ( V_151 -> V_154 ) )
break;
F_103 ( V_149 ) ;
F_108 ( & V_153 ) ;
F_104 () ;
if ( F_43 ( F_105 ( V_132 ) ) )
goto V_150;
}
V_132 -> V_155 = V_151 -> V_155 ;
F_2 ( ! F_109 ( V_151 , V_132 ) ) ;
F_2 ( F_110 ( V_132 ) ) ;
F_111 ( V_132 , V_156 ) ;
V_132 -> V_157 = V_151 -> V_157 ;
F_112 ( V_132 , V_156 , F_113 ( V_151 ) ) ;
F_114 ( V_151 , V_132 , V_158 ) ;
F_114 ( V_151 , V_132 , V_159 ) ;
F_115 ( & V_151 -> V_160 , & V_132 -> V_160 ) ;
F_116 ( & V_151 -> V_161 , & V_132 -> V_161 ) ;
V_132 -> V_152 = V_132 ;
V_151 -> V_152 = V_132 ;
V_132 -> V_162 = V_163 ;
V_151 -> V_162 = - 1 ;
F_2 ( V_151 -> V_154 != V_164 ) ;
V_151 -> V_154 = V_165 ;
if ( F_43 ( V_151 -> V_166 ) )
F_117 ( V_151 , V_151 -> V_167 ) ;
F_108 ( & V_153 ) ;
F_118 ( V_151 ) ;
}
V_139 -> V_147 = NULL ;
V_139 -> V_148 = 0 ;
V_145:
V_132 -> V_162 = V_163 ;
F_119 ( V_139 ) ;
F_120 () ;
if ( F_121 ( & V_141 -> F_47 ) != 1 ) {
struct V_140 * V_168 ;
V_168 = F_122 ( V_169 , V_35 ) ;
if ( ! V_168 )
return - V_36 ;
F_123 ( & V_168 -> F_47 , 1 ) ;
memcpy ( V_168 -> V_170 , V_141 -> V_170 ,
sizeof( V_168 -> V_170 ) ) ;
F_106 ( & V_153 ) ;
F_124 ( & V_141 -> V_144 ) ;
F_125 ( V_132 -> V_142 , V_168 ) ;
F_126 ( & V_141 -> V_144 ) ;
F_108 ( & V_153 ) ;
F_127 ( V_141 ) ;
}
F_2 ( ! F_102 ( V_132 ) ) ;
return 0 ;
V_150:
F_128 ( & V_153 ) ;
V_139 -> V_147 = NULL ;
V_139 -> V_148 = 0 ;
F_129 ( & V_153 ) ;
return - V_146 ;
}
char * F_130 ( char * V_171 , struct V_131 * V_132 )
{
F_89 ( V_132 ) ;
strncpy ( V_171 , V_132 -> V_172 , sizeof( V_132 -> V_172 ) ) ;
F_91 ( V_132 ) ;
return V_171 ;
}
void F_131 ( struct V_131 * V_132 , char * V_171 )
{
F_89 ( V_132 ) ;
F_132 ( V_132 , V_171 ) ;
memset ( V_132 -> V_172 , 0 , V_173 ) ;
F_133 () ;
F_134 ( V_132 -> V_172 , V_171 , sizeof( V_132 -> V_172 ) ) ;
F_91 ( V_132 ) ;
F_135 ( V_132 ) ;
}
static void F_136 ( char * V_174 , const char * V_175 , unsigned int V_48 )
{
int V_31 , V_176 ;
for ( V_31 = 0 ; ( V_176 = * ( V_175 ++ ) ) != '\0' ; ) {
if ( V_176 == '/' )
V_31 = 0 ;
else
if ( V_31 < V_48 - 1 )
V_174 [ V_31 ++ ] = V_176 ;
}
V_174 [ V_31 ] = '\0' ;
}
int F_137 ( struct V_8 * V_9 )
{
int V_177 ;
V_177 = F_96 ( V_13 ) ;
if ( V_177 )
goto V_69;
F_138 ( V_9 -> V_12 , V_9 -> V_105 ) ;
F_136 ( V_9 -> V_174 , V_9 -> V_107 , sizeof( V_9 -> V_174 ) ) ;
F_11 ( V_9 , 0 ) ;
V_177 = F_84 ( V_9 -> V_12 ) ;
if ( V_177 )
goto V_69;
V_9 -> V_12 = NULL ;
F_59 ( V_178 ) ;
V_13 -> V_179 &=
~ ( V_180 | V_181 | V_182 | V_183 ) ;
F_139 () ;
V_13 -> V_184 &= ~ V_9 -> V_185 ;
return 0 ;
V_69:
return V_177 ;
}
void F_140 ( struct V_8 * V_9 , struct V_105 * V_105 )
{
if ( F_141 ( F_77 ( V_105 ) , V_186 ) < 0 )
V_9 -> V_187 |= V_188 ;
}
void F_142 ( struct V_8 * V_9 )
{
F_92 ( V_13 -> V_12 ) ;
V_13 -> V_189 = V_13 -> V_190 = 0 ;
if ( F_143 ( F_144 () , F_145 () ) && F_146 ( F_147 () , F_148 () ) )
F_149 ( V_13 -> V_12 , V_191 ) ;
else
F_149 ( V_13 -> V_12 , V_192 ) ;
F_131 ( V_13 , V_9 -> V_174 ) ;
V_13 -> V_12 -> V_193 = V_194 ;
if ( ! F_143 ( V_9 -> V_195 -> V_196 , F_144 () ) ||
! F_146 ( V_9 -> V_195 -> V_197 , F_147 () ) ) {
V_13 -> V_198 = 0 ;
} else {
F_140 ( V_9 , V_9 -> V_105 ) ;
if ( V_9 -> V_187 & V_188 )
F_149 ( V_13 -> V_12 , V_192 ) ;
}
if ( ! F_150 ( V_13 -> V_12 ) )
F_151 ( V_13 ) ;
V_13 -> V_199 ++ ;
F_152 ( V_13 , 0 ) ;
F_153 ( V_13 -> V_200 ) ;
}
int F_154 ( struct V_8 * V_9 )
{
if ( F_155 ( & V_13 -> signal -> V_201 ) )
return - V_202 ;
V_9 -> V_195 = F_156 () ;
if ( F_107 ( V_9 -> V_195 ) )
return 0 ;
F_157 ( & V_13 -> signal -> V_201 ) ;
return - V_36 ;
}
void F_158 ( struct V_8 * V_9 )
{
F_21 ( V_9 ) ;
if ( V_9 -> V_195 ) {
F_157 ( & V_13 -> signal -> V_201 ) ;
F_159 ( V_9 -> V_195 ) ;
}
if ( V_9 -> V_203 != V_9 -> V_107 )
F_160 ( V_9 -> V_203 ) ;
F_160 ( V_9 ) ;
}
int F_161 ( char * V_203 , struct V_8 * V_9 )
{
if ( V_9 -> V_203 != V_9 -> V_107 )
F_160 ( V_9 -> V_203 ) ;
V_9 -> V_203 = F_162 ( V_203 , V_35 ) ;
if ( ! V_9 -> V_203 )
return - V_36 ;
return 0 ;
}
void F_163 ( struct V_8 * V_9 )
{
F_164 ( V_9 ) ;
F_165 ( V_9 -> V_195 ) ;
V_9 -> V_195 = NULL ;
F_166 ( V_9 ) ;
F_157 ( & V_13 -> signal -> V_201 ) ;
}
static int F_167 ( struct V_8 * V_9 )
{
struct V_131 * V_47 = V_13 , * V_204 ;
unsigned V_205 ;
int V_206 = 0 ;
if ( V_47 -> V_166 ) {
if ( V_47 -> V_166 & V_207 )
V_9 -> V_208 |= V_209 ;
else
V_9 -> V_208 |= V_210 ;
}
if ( V_13 -> V_211 )
V_9 -> V_208 |= V_212 ;
V_205 = 1 ;
F_124 ( & V_47 -> V_213 -> V_143 ) ;
F_168 () ;
for ( V_204 = F_169 ( V_47 ) ; V_204 != V_47 ; V_204 = F_169 ( V_204 ) ) {
if ( V_204 -> V_213 == V_47 -> V_213 )
V_205 ++ ;
}
F_170 () ;
if ( V_47 -> V_213 -> V_214 > V_205 ) {
V_9 -> V_208 |= V_215 ;
} else {
V_206 = - V_146 ;
if ( ! V_47 -> V_213 -> V_216 ) {
V_47 -> V_213 -> V_216 = 1 ;
V_206 = 1 ;
}
}
F_126 ( & V_47 -> V_213 -> V_143 ) ;
return V_206 ;
}
int F_171 ( struct V_8 * V_9 )
{
T_6 V_217 ;
struct V_218 * V_218 = F_77 ( V_9 -> V_105 ) ;
int V_177 ;
V_217 = V_218 -> V_123 ;
if ( V_9 -> V_105 -> V_219 == NULL )
return - V_122 ;
V_9 -> V_195 -> V_220 = F_144 () ;
V_9 -> V_195 -> V_221 = F_147 () ;
if ( ! ( V_9 -> V_105 -> V_124 . V_125 -> V_126 & V_222 ) &&
! V_13 -> V_211 &&
F_172 ( V_9 -> V_195 -> V_223 , V_218 -> V_224 ) &&
F_173 ( V_9 -> V_195 -> V_223 , V_218 -> V_225 ) ) {
if ( V_217 & V_226 ) {
V_9 -> V_185 |= V_227 ;
V_9 -> V_195 -> V_220 = V_218 -> V_224 ;
}
if ( ( V_217 & ( V_228 | V_229 ) ) == ( V_228 | V_229 ) ) {
V_9 -> V_185 |= V_227 ;
V_9 -> V_195 -> V_221 = V_218 -> V_225 ;
}
}
V_177 = F_174 ( V_9 ) ;
if ( V_177 )
return V_177 ;
V_9 -> V_230 = 1 ;
memset ( V_9 -> V_171 , 0 , V_231 ) ;
return F_81 ( V_9 -> V_105 , 0 , V_9 -> V_171 , V_231 ) ;
}
int F_175 ( struct V_8 * V_9 )
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
V_66 = F_176 ( V_17 ) ;
for (; V_70 < V_27 && V_66 [ V_70 ] ;
V_70 ++ , V_9 -> V_47 ++ )
;
F_177 ( V_66 ) ;
F_19 ( V_17 ) ;
if ( V_70 == V_27 )
F_20 ( V_9 , ( V_9 -> V_47 >> V_232 ) - 1 ) ;
} while ( V_70 == V_27 );
V_9 -> V_47 ++ ;
V_9 -> V_64 -- ;
V_20 = 0 ;
V_69:
return V_20 ;
}
int F_178 ( struct V_8 * V_9 )
{
unsigned int V_233 = V_9 -> V_234 ;
int V_235 , V_177 ;
struct V_1 * V_2 ;
T_7 V_236 , V_237 ;
if ( V_233 > 5 )
return - V_238 ;
V_177 = F_179 ( V_9 ) ;
if ( V_177 )
return V_177 ;
V_177 = F_180 ( V_9 ) ;
if ( V_177 )
return V_177 ;
V_236 = V_13 -> V_157 ;
F_168 () ;
V_237 = F_181 ( V_13 , F_182 ( V_13 -> V_167 ) ) ;
F_170 () ;
V_177 = - V_239 ;
for ( V_235 = 0 ; V_235 < 2 ; V_235 ++ ) {
F_128 ( & V_4 ) ;
F_183 (fmt, &formats, lh) {
int (* V_175)( struct V_8 * ) = V_2 -> V_240 ;
if ( ! V_175 )
continue;
if ( ! F_184 ( V_2 -> V_7 ) )
continue;
F_129 ( & V_4 ) ;
V_9 -> V_234 = V_233 + 1 ;
V_177 = V_175 ( V_9 ) ;
V_9 -> V_234 = V_233 ;
if ( V_177 >= 0 ) {
if ( V_233 == 0 ) {
F_185 ( V_13 , V_236 , V_9 ) ;
F_186 ( V_241 , V_237 ) ;
}
F_9 ( V_2 ) ;
F_187 ( V_9 -> V_105 ) ;
if ( V_9 -> V_105 )
F_80 ( V_9 -> V_105 ) ;
V_9 -> V_105 = NULL ;
V_13 -> V_242 = 1 ;
F_188 ( V_13 ) ;
return V_177 ;
}
F_128 ( & V_4 ) ;
F_9 ( V_2 ) ;
if ( V_177 != - V_243 || V_9 -> V_12 == NULL )
break;
if ( ! V_9 -> V_105 ) {
F_129 ( & V_4 ) ;
return V_177 ;
}
}
F_129 ( & V_4 ) ;
#ifdef F_189
if ( V_177 != - V_243 || V_9 -> V_12 == NULL ) {
break;
} else {
#define F_190 ( T_8 ) (((c)=='\t') || ((c)=='\n') || (0x20<=(c) && (c)<=0x7e))
if ( F_190 ( V_9 -> V_171 [ 0 ] ) &&
F_190 ( V_9 -> V_171 [ 1 ] ) &&
F_190 ( V_9 -> V_171 [ 2 ] ) &&
F_190 ( V_9 -> V_171 [ 3 ] ) )
break;
if ( V_235 )
break;
F_191 ( L_1 , * ( unsigned short * ) ( & V_9 -> V_171 [ 2 ] ) ) ;
}
#else
break;
#endif
}
return V_177 ;
}
static int F_192 ( const char * V_107 ,
struct V_53 V_54 ,
struct V_53 V_244 )
{
struct V_8 * V_9 ;
struct V_105 * V_105 ;
struct V_245 * V_246 ;
bool V_247 ;
int V_177 ;
const struct V_195 * V_195 = F_193 () ;
if ( ( V_13 -> V_179 & V_248 ) &&
F_121 ( & V_195 -> V_249 -> V_250 ) > V_25 ( V_251 ) ) {
V_177 = - V_146 ;
goto V_252;
}
V_13 -> V_179 &= ~ V_248 ;
V_177 = F_194 ( & V_246 ) ;
if ( V_177 )
goto V_252;
V_177 = - V_36 ;
V_9 = F_195 ( sizeof( * V_9 ) , V_35 ) ;
if ( ! V_9 )
goto V_253;
V_177 = F_154 ( V_9 ) ;
if ( V_177 )
goto V_254;
V_177 = F_167 ( V_9 ) ;
if ( V_177 < 0 )
goto V_254;
V_247 = V_177 ;
V_13 -> V_255 = 1 ;
V_105 = F_74 ( V_107 ) ;
V_177 = F_196 ( V_105 ) ;
if ( F_48 ( V_105 ) )
goto V_256;
F_197 () ;
V_9 -> V_105 = V_105 ;
V_9 -> V_107 = V_107 ;
V_9 -> V_203 = V_107 ;
V_177 = F_37 ( V_9 ) ;
if ( V_177 )
goto V_257;
V_9 -> V_64 = F_47 ( V_54 , V_258 ) ;
if ( ( V_177 = V_9 -> V_64 ) < 0 )
goto V_69;
V_9 -> V_259 = F_47 ( V_244 , V_258 ) ;
if ( ( V_177 = V_9 -> V_259 ) < 0 )
goto V_69;
V_177 = F_171 ( V_9 ) ;
if ( V_177 < 0 )
goto V_69;
V_177 = F_57 ( 1 , & V_9 -> V_107 , V_9 ) ;
if ( V_177 < 0 )
goto V_69;
V_9 -> V_98 = V_9 -> V_47 ;
V_177 = F_51 ( V_9 -> V_259 , V_244 , V_9 ) ;
if ( V_177 < 0 )
goto V_69;
V_177 = F_51 ( V_9 -> V_64 , V_54 , V_9 ) ;
if ( V_177 < 0 )
goto V_69;
V_177 = F_178 ( V_9 ) ;
if ( V_177 < 0 )
goto V_69;
V_13 -> V_213 -> V_216 = 0 ;
V_13 -> V_255 = 0 ;
F_198 ( V_13 ) ;
F_158 ( V_9 ) ;
if ( V_246 )
F_199 ( V_246 ) ;
return V_177 ;
V_69:
if ( V_9 -> V_12 ) {
F_11 ( V_9 , 0 ) ;
F_95 ( V_9 -> V_12 ) ;
}
V_257:
if ( V_9 -> V_105 ) {
F_187 ( V_9 -> V_105 ) ;
F_80 ( V_9 -> V_105 ) ;
}
V_256:
if ( V_247 )
V_13 -> V_213 -> V_216 = 0 ;
V_13 -> V_255 = 0 ;
V_254:
F_158 ( V_9 ) ;
V_253:
if ( V_246 )
F_200 ( V_246 ) ;
V_252:
return V_177 ;
}
int F_201 ( const char * V_107 ,
const char T_1 * const T_1 * V_73 ,
const char T_1 * const T_1 * V_260 )
{
struct V_53 V_54 = { . V_59 . V_56 = V_73 } ;
struct V_53 V_244 = { . V_59 . V_56 = V_260 } ;
return F_192 ( V_107 , V_54 , V_244 ) ;
}
static int F_202 ( const char * V_107 ,
const T_2 T_1 * V_73 ,
const T_2 T_1 * V_260 )
{
struct V_53 V_54 = {
. V_57 = true ,
. V_59 . V_58 = V_73 ,
} ;
struct V_53 V_244 = {
. V_57 = true ,
. V_59 . V_58 = V_260 ,
} ;
return F_192 ( V_107 , V_54 , V_244 ) ;
}
void F_203 ( struct V_1 * V_261 )
{
struct V_11 * V_12 = V_13 -> V_12 ;
if ( V_12 -> V_262 )
F_10 ( V_12 -> V_262 -> V_7 ) ;
V_12 -> V_262 = V_261 ;
if ( V_261 )
F_204 ( V_261 -> V_7 ) ;
}
void F_149 ( struct V_11 * V_12 , int V_263 )
{
switch ( V_263 ) {
case V_264 :
F_205 ( V_265 , & V_12 -> V_179 ) ;
F_206 () ;
F_205 ( V_266 , & V_12 -> V_179 ) ;
break;
case V_191 :
F_207 ( V_265 , & V_12 -> V_179 ) ;
F_206 () ;
F_205 ( V_266 , & V_12 -> V_179 ) ;
break;
case V_267 :
F_207 ( V_266 , & V_12 -> V_179 ) ;
F_206 () ;
F_207 ( V_265 , & V_12 -> V_179 ) ;
break;
}
}
int F_208 ( unsigned long V_268 )
{
int V_20 ;
V_20 = V_268 & V_269 ;
return ( V_20 > V_191 ) ? V_267 : V_20 ;
}
int F_150 ( struct V_11 * V_12 )
{
return F_208 ( V_12 -> V_179 ) ;
}
T_9 long F_209 ( const char T_1 * V_107 ,
const T_2 T_1 * V_54 ,
const T_2 T_1 * V_244 )
{
struct V_107 * V_270 = F_210 ( V_107 ) ;
int error = F_196 ( V_270 ) ;
if ( ! F_48 ( V_270 ) ) {
error = F_202 ( V_270 -> V_106 , V_54 , V_244 ) ;
F_211 ( V_270 ) ;
}
return error ;
}
