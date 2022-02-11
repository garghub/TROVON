void F_1 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( ! V_2 ) ;
if ( F_3 ( ! V_2 -> V_4 ) )
return;
F_4 ( & V_5 ) ;
V_3 ? F_5 ( & V_2 -> V_6 , & V_7 ) :
F_6 ( & V_2 -> V_6 , & V_7 ) ;
F_7 ( & V_5 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
F_4 ( & V_5 ) ;
F_9 ( & V_2 -> V_6 ) ;
F_7 ( & V_5 ) ;
}
static inline void F_10 ( struct V_1 * V_2 )
{
F_11 ( V_2 -> V_8 ) ;
}
static void F_12 ( struct V_9 * V_10 , unsigned long V_11 )
{
struct V_12 * V_13 = V_14 -> V_13 ;
long V_15 = ( long ) ( V_11 - V_10 -> V_16 ) ;
if ( ! V_13 || ! V_15 )
return;
V_10 -> V_16 = V_11 ;
F_13 ( V_13 , V_17 , V_15 ) ;
}
static struct V_18 * F_14 ( struct V_9 * V_10 , unsigned long V_19 ,
int V_20 )
{
struct V_18 * V_18 ;
int V_21 ;
#ifdef F_15
if ( V_20 ) {
V_21 = F_16 ( V_10 -> V_22 , V_19 ) ;
if ( V_21 < 0 )
return NULL ;
}
#endif
V_21 = F_17 ( V_14 , V_10 -> V_13 , V_19 ,
1 , V_20 , 1 , & V_18 , NULL ) ;
if ( V_21 <= 0 )
return NULL ;
if ( V_20 ) {
unsigned long V_23 = V_10 -> V_22 -> V_24 - V_10 -> V_22 -> V_25 ;
struct V_26 * V_27 ;
F_12 ( V_10 , V_23 / V_28 ) ;
if ( V_23 <= V_29 )
return V_18 ;
V_27 = V_14 -> signal -> V_27 ;
if ( V_23 > F_18 ( V_27 [ V_30 ] . V_31 ) / 4 ) {
F_19 ( V_18 ) ;
return NULL ;
}
}
return V_18 ;
}
static void F_20 ( struct V_18 * V_18 )
{
F_19 ( V_18 ) ;
}
static void F_21 ( struct V_9 * V_10 , int V_32 )
{
}
static void F_22 ( struct V_9 * V_10 )
{
}
static void F_23 ( struct V_9 * V_10 , unsigned long V_19 ,
struct V_18 * V_18 )
{
F_24 ( V_10 -> V_22 , V_19 , F_25 ( V_18 ) ) ;
}
static int F_26 ( struct V_9 * V_10 )
{
int V_33 ;
struct V_34 * V_22 = NULL ;
struct V_12 * V_13 = V_10 -> V_13 ;
V_10 -> V_22 = V_22 = F_27 ( V_35 , V_36 ) ;
if ( ! V_22 )
return - V_37 ;
F_28 ( & V_13 -> V_38 ) ;
V_22 -> V_39 = V_13 ;
F_29 ( V_40 & V_41 ) ;
V_22 -> V_24 = V_42 ;
V_22 -> V_25 = V_22 -> V_24 - V_28 ;
V_22 -> V_43 = V_44 | V_40 | V_41 ;
V_22 -> V_45 = F_30 ( V_22 -> V_43 ) ;
F_31 ( & V_22 -> V_46 ) ;
V_33 = F_32 ( V_13 , V_22 ) ;
if ( V_33 )
goto V_33;
V_13 -> V_47 = V_13 -> V_48 = 1 ;
F_33 ( & V_13 -> V_38 ) ;
V_10 -> V_49 = V_22 -> V_24 - sizeof( void * ) ;
return 0 ;
V_33:
F_33 ( & V_13 -> V_38 ) ;
V_10 -> V_22 = NULL ;
F_34 ( V_35 , V_22 ) ;
return V_33 ;
}
static bool F_35 ( struct V_9 * V_10 , long V_50 )
{
return V_50 <= V_51 ;
}
static inline void F_12 ( struct V_9 * V_10 , unsigned long V_11 )
{
}
static struct V_18 * F_14 ( struct V_9 * V_10 , unsigned long V_19 ,
int V_20 )
{
struct V_18 * V_18 ;
V_18 = V_10 -> V_18 [ V_19 / V_28 ] ;
if ( ! V_18 && V_20 ) {
V_18 = F_36 ( V_52 | V_53 ) ;
if ( ! V_18 )
return NULL ;
V_10 -> V_18 [ V_19 / V_28 ] = V_18 ;
}
return V_18 ;
}
static void F_20 ( struct V_18 * V_18 )
{
}
static void F_21 ( struct V_9 * V_10 , int V_32 )
{
if ( V_10 -> V_18 [ V_32 ] ) {
F_37 ( V_10 -> V_18 [ V_32 ] ) ;
V_10 -> V_18 [ V_32 ] = NULL ;
}
}
static void F_22 ( struct V_9 * V_10 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_54 ; V_32 ++ )
F_21 ( V_10 , V_32 ) ;
}
static void F_23 ( struct V_9 * V_10 , unsigned long V_19 ,
struct V_18 * V_18 )
{
}
static int F_26 ( struct V_9 * V_10 )
{
V_10 -> V_49 = V_28 * V_54 - sizeof( void * ) ;
return 0 ;
}
static bool F_35 ( struct V_9 * V_10 , long V_50 )
{
return V_50 <= V_10 -> V_49 ;
}
static int F_38 ( struct V_9 * V_10 )
{
int V_33 ;
struct V_12 * V_13 = NULL ;
V_10 -> V_13 = V_13 = F_39 () ;
V_33 = - V_37 ;
if ( ! V_13 )
goto V_33;
V_33 = F_40 ( V_14 , V_13 ) ;
if ( V_33 )
goto V_33;
V_33 = F_26 ( V_10 ) ;
if ( V_33 )
goto V_33;
return 0 ;
V_33:
if ( V_13 ) {
V_10 -> V_13 = NULL ;
F_41 ( V_13 ) ;
}
return V_33 ;
}
static const char T_1 * F_42 ( struct V_55 V_56 , int V_57 )
{
const char T_1 * V_58 ;
#ifdef F_43
if ( F_44 ( V_56 . V_59 ) ) {
T_2 V_60 ;
if ( F_45 ( V_60 , V_56 . V_61 . V_60 + V_57 ) )
return F_46 ( - V_62 ) ;
return F_47 ( V_60 ) ;
}
#endif
if ( F_45 ( V_58 , V_56 . V_61 . V_58 + V_57 ) )
return F_46 ( - V_62 ) ;
return V_58 ;
}
static int F_48 ( struct V_55 V_56 , int V_63 )
{
int V_32 = 0 ;
if ( V_56 . V_61 . V_58 != NULL ) {
for (; ; ) {
const char T_1 * V_49 = F_42 ( V_56 , V_32 ) ;
if ( ! V_49 )
break;
if ( F_49 ( V_49 ) )
return - V_62 ;
if ( V_32 >= V_63 )
return - V_64 ;
++ V_32 ;
if ( F_50 ( V_14 ) )
return - V_65 ;
F_51 () ;
}
}
return V_32 ;
}
static int F_52 ( int V_66 , struct V_55 V_56 ,
struct V_9 * V_10 )
{
struct V_18 * V_67 = NULL ;
char * V_68 = NULL ;
unsigned long V_69 = 0 ;
int V_21 ;
while ( V_66 -- > 0 ) {
const char T_1 * V_70 ;
int V_50 ;
unsigned long V_19 ;
V_21 = - V_62 ;
V_70 = F_42 ( V_56 , V_66 ) ;
if ( F_49 ( V_70 ) )
goto V_71;
V_50 = F_53 ( V_70 , V_51 ) ;
if ( ! V_50 )
goto V_71;
V_21 = - V_64 ;
if ( ! F_35 ( V_10 , V_50 ) )
goto V_71;
V_19 = V_10 -> V_49 ;
V_70 += V_50 ;
V_10 -> V_49 -= V_50 ;
while ( V_50 > 0 ) {
int V_72 , V_73 ;
if ( F_50 ( V_14 ) ) {
V_21 = - V_65 ;
goto V_71;
}
F_51 () ;
V_72 = V_19 % V_28 ;
if ( V_72 == 0 )
V_72 = V_28 ;
V_73 = V_72 ;
if ( V_73 > V_50 )
V_73 = V_50 ;
V_72 -= V_73 ;
V_19 -= V_73 ;
V_70 -= V_73 ;
V_50 -= V_73 ;
if ( ! V_67 || V_69 != ( V_19 & V_74 ) ) {
struct V_18 * V_18 ;
V_18 = F_14 ( V_10 , V_19 , 1 ) ;
if ( ! V_18 ) {
V_21 = - V_64 ;
goto V_71;
}
if ( V_67 ) {
F_54 ( V_67 ) ;
F_55 ( V_67 ) ;
F_20 ( V_67 ) ;
}
V_67 = V_18 ;
V_68 = F_56 ( V_67 ) ;
V_69 = V_19 & V_74 ;
F_23 ( V_10 , V_69 , V_67 ) ;
}
if ( F_57 ( V_68 + V_72 , V_70 , V_73 ) ) {
V_21 = - V_62 ;
goto V_71;
}
}
}
V_21 = 0 ;
V_71:
if ( V_67 ) {
F_54 ( V_67 ) ;
F_55 ( V_67 ) ;
F_20 ( V_67 ) ;
}
return V_21 ;
}
int F_58 ( int V_66 , const char * const * V_75 ,
struct V_9 * V_10 )
{
int V_76 ;
T_3 V_77 = F_59 () ;
struct V_55 V_56 = {
. V_61 . V_58 = ( const char T_1 * const T_1 * ) V_75 ,
} ;
F_60 ( V_78 ) ;
V_76 = F_52 ( V_66 , V_56 , V_10 ) ;
F_60 ( V_77 ) ;
return V_76 ;
}
static int F_61 ( struct V_34 * V_22 , unsigned long V_79 )
{
struct V_12 * V_13 = V_22 -> V_39 ;
unsigned long V_80 = V_22 -> V_25 ;
unsigned long V_81 = V_22 -> V_24 ;
unsigned long V_82 = V_81 - V_80 ;
unsigned long V_83 = V_80 - V_79 ;
unsigned long V_84 = V_81 - V_79 ;
struct V_85 V_86 ;
F_2 ( V_83 > V_84 ) ;
if ( V_22 != F_62 ( V_13 , V_83 ) )
return - V_62 ;
if ( F_63 ( V_22 , V_83 , V_81 , V_22 -> V_87 , NULL ) )
return - V_37 ;
if ( V_82 != F_64 ( V_22 , V_80 ,
V_22 , V_83 , V_82 , false ) )
return - V_37 ;
F_65 () ;
F_66 ( & V_86 , V_13 , V_80 , V_81 ) ;
if ( V_84 > V_80 ) {
F_67 ( & V_86 , V_84 , V_81 , V_84 ,
V_22 -> V_88 ? V_22 -> V_88 -> V_25 : V_89 ) ;
} else {
F_67 ( & V_86 , V_80 , V_81 , V_84 ,
V_22 -> V_88 ? V_22 -> V_88 -> V_25 : V_89 ) ;
}
F_68 ( & V_86 , V_80 , V_81 ) ;
F_63 ( V_22 , V_83 , V_84 , V_22 -> V_87 , NULL ) ;
return 0 ;
}
int F_69 ( struct V_9 * V_10 ,
unsigned long V_90 ,
int V_91 )
{
unsigned long V_21 ;
unsigned long V_92 ;
struct V_12 * V_13 = V_14 -> V_13 ;
struct V_34 * V_22 = V_10 -> V_22 ;
struct V_34 * V_93 = NULL ;
unsigned long V_43 ;
unsigned long V_94 ;
unsigned long V_95 ;
unsigned long V_96 ;
unsigned long V_97 ;
#ifdef F_15
V_94 = F_70 ( V_30 ) ;
if ( V_94 > ( 1 << 30 ) )
V_94 = 1 << 30 ;
if ( V_22 -> V_24 - V_22 -> V_25 > V_94 )
return - V_37 ;
V_94 = F_71 ( V_90 - V_94 ) ;
V_92 = V_22 -> V_25 - V_94 ;
V_13 -> V_98 = V_10 -> V_49 - V_92 ;
V_10 -> V_49 = V_22 -> V_24 - V_92 ;
#else
V_90 = F_72 ( V_90 ) ;
V_90 = F_71 ( V_90 ) ;
if ( F_44 ( V_90 < V_99 ) ||
F_44 ( V_22 -> V_24 - V_22 -> V_25 >= V_90 - V_99 ) )
return - V_37 ;
V_92 = V_22 -> V_24 - V_90 ;
V_10 -> V_49 -= V_92 ;
V_13 -> V_98 = V_10 -> V_49 ;
#endif
if ( V_10 -> V_100 )
V_10 -> V_100 -= V_92 ;
V_10 -> V_101 -= V_92 ;
F_28 ( & V_13 -> V_38 ) ;
V_43 = V_40 ;
if ( F_44 ( V_91 == V_102 ) )
V_43 |= V_103 ;
else if ( V_91 == V_104 )
V_43 &= ~ V_103 ;
V_43 |= V_13 -> V_105 ;
V_43 |= V_41 ;
V_21 = F_73 ( V_22 , & V_93 , V_22 -> V_25 , V_22 -> V_24 ,
V_43 ) ;
if ( V_21 )
goto V_106;
F_2 ( V_93 != V_22 ) ;
if ( V_92 ) {
V_21 = F_61 ( V_22 , V_92 ) ;
if ( V_21 )
goto V_106;
}
V_22 -> V_43 &= ~ V_41 ;
V_96 = 131072UL ;
V_95 = V_22 -> V_24 - V_22 -> V_25 ;
V_97 = V_26 ( V_30 ) & V_74 ;
#ifdef F_15
if ( V_95 + V_96 > V_97 )
V_94 = V_22 -> V_25 + V_97 ;
else
V_94 = V_22 -> V_24 + V_96 ;
#else
if ( V_95 + V_96 > V_97 )
V_94 = V_22 -> V_24 - V_97 ;
else
V_94 = V_22 -> V_25 - V_96 ;
#endif
V_14 -> V_13 -> V_107 = V_10 -> V_49 ;
V_21 = F_74 ( V_22 , V_94 ) ;
if ( V_21 )
V_21 = - V_62 ;
V_106:
F_33 ( & V_13 -> V_38 ) ;
return V_21 ;
}
struct V_108 * F_75 ( const char * V_109 )
{
struct V_108 * V_108 ;
int V_33 ;
struct V_110 V_111 = { . V_109 = V_109 } ;
static const struct V_112 V_113 = {
. V_114 = V_115 | V_116 | V_117 ,
. V_118 = V_119 | V_120 ,
. V_121 = V_122 ,
. V_123 = V_124 ,
} ;
V_108 = F_76 ( V_125 , & V_111 , & V_113 ) ;
if ( F_49 ( V_108 ) )
goto V_71;
V_33 = - V_126 ;
if ( ! F_77 ( F_78 ( V_108 ) -> V_127 ) )
goto exit;
if ( V_108 -> V_128 . V_129 -> V_130 & V_131 )
goto exit;
F_79 ( V_108 ) ;
V_33 = F_80 ( V_108 ) ;
if ( V_33 )
goto exit;
V_71:
return V_108 ;
exit:
F_81 ( V_108 ) ;
return F_46 ( V_33 ) ;
}
int F_82 ( struct V_108 * V_108 , T_4 V_72 ,
char * V_132 , unsigned long F_48 )
{
T_3 V_133 ;
T_4 V_19 = V_72 ;
int V_134 ;
V_133 = F_59 () ;
F_60 ( F_83 () ) ;
V_134 = F_84 ( V_108 , ( void T_1 * ) V_132 , F_48 , & V_19 ) ;
F_60 ( V_133 ) ;
return V_134 ;
}
T_5 F_85 ( struct V_108 * V_108 , unsigned long V_132 , T_4 V_19 , T_6 V_50 )
{
T_5 V_135 = V_108 -> V_136 -> V_137 ( V_108 , ( void T_1 * ) V_132 , V_50 , & V_19 ) ;
if ( V_135 > 0 )
F_86 ( V_132 , V_132 + V_50 ) ;
return V_135 ;
}
static int F_87 ( struct V_12 * V_13 )
{
struct V_138 * V_139 ;
struct V_12 * V_140 , * V_141 ;
V_139 = V_14 ;
V_140 = V_14 -> V_13 ;
F_88 ( V_139 , V_140 ) ;
if ( V_140 ) {
F_89 ( V_140 ) ;
F_90 ( & V_140 -> V_38 ) ;
if ( F_44 ( V_140 -> V_142 ) ) {
F_91 ( & V_140 -> V_38 ) ;
return - V_143 ;
}
}
F_92 ( V_139 ) ;
V_141 = V_139 -> V_141 ;
V_139 -> V_13 = V_13 ;
V_139 -> V_141 = V_13 ;
F_93 ( V_141 , V_13 ) ;
F_94 ( V_139 ) ;
F_95 ( V_13 ) ;
if ( V_140 ) {
F_91 ( & V_140 -> V_38 ) ;
F_2 ( V_141 != V_140 ) ;
F_96 ( & V_139 -> signal -> V_144 , V_140 ) ;
F_97 ( V_140 ) ;
F_98 ( V_140 ) ;
return 0 ;
}
F_41 ( V_141 ) ;
return 0 ;
}
static int F_99 ( struct V_138 * V_139 )
{
struct V_145 * V_146 = V_139 -> signal ;
struct V_147 * V_148 = V_139 -> V_149 ;
T_7 * V_150 = & V_148 -> V_151 ;
if ( F_100 ( V_139 ) )
goto V_152;
F_101 ( V_150 ) ;
if ( F_102 ( V_146 ) ) {
F_103 ( V_150 ) ;
return - V_153 ;
}
V_146 -> V_154 = V_139 ;
V_146 -> V_155 = F_104 ( V_139 ) ;
if ( ! F_105 ( V_139 ) )
V_146 -> V_155 -- ;
while ( V_146 -> V_155 ) {
F_106 ( V_156 ) ;
F_103 ( V_150 ) ;
F_107 () ;
if ( F_44 ( F_108 ( V_139 ) ) )
goto V_157;
F_101 ( V_150 ) ;
}
F_103 ( V_150 ) ;
if ( ! F_105 ( V_139 ) ) {
struct V_138 * V_158 = V_139 -> V_159 ;
V_146 -> V_155 = - 1 ;
for (; ; ) {
F_109 ( V_139 ) ;
F_110 ( & V_160 ) ;
if ( F_111 ( V_158 -> V_161 ) )
break;
F_106 ( V_156 ) ;
F_112 ( & V_160 ) ;
F_113 ( V_139 ) ;
F_107 () ;
if ( F_44 ( F_108 ( V_139 ) ) )
goto V_157;
}
V_139 -> V_162 = V_158 -> V_162 ;
V_139 -> V_163 = V_158 -> V_163 ;
F_2 ( ! F_114 ( V_158 , V_139 ) ) ;
F_2 ( F_115 ( V_139 ) ) ;
V_139 -> V_164 = V_158 -> V_164 ;
F_116 ( V_139 , V_165 , F_117 ( V_158 ) ) ;
F_118 ( V_158 , V_139 , V_166 ) ;
F_118 ( V_158 , V_139 , V_167 ) ;
F_119 ( & V_158 -> V_168 , & V_139 -> V_168 ) ;
F_120 ( & V_158 -> V_169 , & V_139 -> V_169 ) ;
V_139 -> V_159 = V_139 ;
V_158 -> V_159 = V_139 ;
V_139 -> V_170 = V_171 ;
V_158 -> V_170 = - 1 ;
F_2 ( V_158 -> V_161 != V_172 ) ;
V_158 -> V_161 = V_173 ;
if ( F_44 ( V_158 -> V_174 ) )
F_121 ( V_158 , V_158 -> V_175 ) ;
F_112 ( & V_160 ) ;
F_113 ( V_139 ) ;
F_122 ( V_158 ) ;
}
V_146 -> V_154 = NULL ;
V_146 -> V_155 = 0 ;
V_152:
V_139 -> V_170 = V_171 ;
F_123 ( V_146 ) ;
F_124 () ;
if ( F_125 ( & V_148 -> F_48 ) != 1 ) {
struct V_147 * V_176 ;
V_176 = F_126 ( V_177 , V_36 ) ;
if ( ! V_176 )
return - V_37 ;
F_127 ( & V_176 -> F_48 , 1 ) ;
memcpy ( V_176 -> V_178 , V_148 -> V_178 ,
sizeof( V_176 -> V_178 ) ) ;
F_110 ( & V_160 ) ;
F_128 ( & V_148 -> V_151 ) ;
F_129 ( V_139 -> V_149 , V_176 ) ;
F_130 ( & V_148 -> V_151 ) ;
F_112 ( & V_160 ) ;
F_131 ( V_148 ) ;
}
F_2 ( ! F_105 ( V_139 ) ) ;
return 0 ;
V_157:
F_132 ( & V_160 ) ;
V_146 -> V_154 = NULL ;
V_146 -> V_155 = 0 ;
F_133 ( & V_160 ) ;
return - V_153 ;
}
char * F_134 ( char * V_179 , struct V_138 * V_139 )
{
F_92 ( V_139 ) ;
strncpy ( V_179 , V_139 -> V_180 , sizeof( V_139 -> V_180 ) ) ;
F_94 ( V_139 ) ;
return V_179 ;
}
void F_135 ( struct V_138 * V_139 , char * V_179 )
{
F_92 ( V_139 ) ;
F_136 ( V_139 , V_179 ) ;
F_137 ( V_139 -> V_180 , V_179 , sizeof( V_139 -> V_180 ) ) ;
F_94 ( V_139 ) ;
F_138 ( V_139 ) ;
}
static void F_139 ( char * V_181 , const char * V_182 , unsigned int V_50 )
{
int V_32 , V_183 ;
for ( V_32 = 0 ; ( V_183 = * ( V_182 ++ ) ) != '\0' ; ) {
if ( V_183 == '/' )
V_32 = 0 ;
else
if ( V_32 < V_50 - 1 )
V_181 [ V_32 ++ ] = V_183 ;
}
V_181 [ V_32 ] = '\0' ;
}
int F_140 ( struct V_9 * V_10 )
{
int V_184 ;
V_184 = F_99 ( V_14 ) ;
if ( V_184 )
goto V_71;
F_141 ( V_10 -> V_13 , V_10 -> V_108 ) ;
F_139 ( V_10 -> V_181 , V_10 -> V_110 , sizeof( V_10 -> V_181 ) ) ;
F_12 ( V_10 , 0 ) ;
V_184 = F_87 ( V_10 -> V_13 ) ;
if ( V_184 )
goto V_71;
V_10 -> V_13 = NULL ;
F_60 ( V_185 ) ;
V_14 -> V_186 &=
~ ( V_187 | V_188 | V_189 | V_190 ) ;
F_142 () ;
V_14 -> V_191 &= ~ V_10 -> V_192 ;
return 0 ;
V_71:
return V_184 ;
}
void F_143 ( struct V_9 * V_10 , struct V_108 * V_108 )
{
if ( F_144 ( F_78 ( V_108 ) , V_193 ) < 0 )
V_10 -> V_194 |= V_195 ;
}
void F_145 ( struct V_9 * V_10 )
{
F_95 ( V_14 -> V_13 ) ;
V_14 -> V_196 = V_14 -> V_197 = 0 ;
if ( F_146 ( F_147 () , F_148 () ) && F_149 ( F_150 () , F_151 () ) )
F_152 ( V_14 -> V_13 , V_198 ) ;
else
F_152 ( V_14 -> V_13 , V_199 ) ;
F_135 ( V_14 , V_10 -> V_181 ) ;
V_14 -> V_13 -> V_200 = V_201 ;
if ( ! F_146 ( V_10 -> V_202 -> V_203 , F_147 () ) ||
! F_149 ( V_10 -> V_202 -> V_204 , F_150 () ) ) {
V_14 -> V_205 = 0 ;
} else {
F_143 ( V_10 , V_10 -> V_108 ) ;
if ( V_10 -> V_194 & V_195 )
F_152 ( V_14 -> V_13 , V_199 ) ;
}
V_14 -> V_206 ++ ;
F_153 ( V_14 , 0 ) ;
F_154 ( V_14 -> V_207 ) ;
}
int F_155 ( struct V_9 * V_10 )
{
if ( F_156 ( & V_14 -> signal -> V_208 ) )
return - V_209 ;
V_10 -> V_202 = F_157 () ;
if ( F_111 ( V_10 -> V_202 ) )
return 0 ;
F_158 ( & V_14 -> signal -> V_208 ) ;
return - V_37 ;
}
void F_159 ( struct V_9 * V_10 )
{
F_22 ( V_10 ) ;
if ( V_10 -> V_202 ) {
F_158 ( & V_14 -> signal -> V_208 ) ;
F_160 ( V_10 -> V_202 ) ;
}
if ( V_10 -> V_210 != V_10 -> V_110 )
F_161 ( V_10 -> V_210 ) ;
F_161 ( V_10 ) ;
}
int F_162 ( char * V_210 , struct V_9 * V_10 )
{
if ( V_10 -> V_210 != V_10 -> V_110 )
F_161 ( V_10 -> V_210 ) ;
V_10 -> V_210 = F_163 ( V_210 , V_36 ) ;
if ( ! V_10 -> V_210 )
return - V_37 ;
return 0 ;
}
void F_164 ( struct V_9 * V_10 )
{
F_165 ( V_10 ) ;
F_166 ( V_10 -> V_202 ) ;
V_10 -> V_202 = NULL ;
if ( F_167 ( V_14 -> V_13 ) != V_198 )
F_168 ( V_14 ) ;
F_169 ( V_10 ) ;
F_158 ( & V_14 -> signal -> V_208 ) ;
}
static int F_170 ( struct V_9 * V_10 )
{
struct V_138 * V_49 = V_14 , * V_211 ;
unsigned V_212 ;
int V_135 = 0 ;
if ( V_49 -> V_174 ) {
if ( V_49 -> V_174 & V_213 )
V_10 -> V_214 |= V_215 ;
else
V_10 -> V_214 |= V_216 ;
}
if ( V_14 -> V_217 )
V_10 -> V_214 |= V_218 ;
V_212 = 1 ;
F_128 ( & V_49 -> V_219 -> V_150 ) ;
F_171 () ;
for ( V_211 = F_172 ( V_49 ) ; V_211 != V_49 ; V_211 = F_172 ( V_211 ) ) {
if ( V_211 -> V_219 == V_49 -> V_219 )
V_212 ++ ;
}
F_173 () ;
if ( V_49 -> V_219 -> V_220 > V_212 ) {
V_10 -> V_214 |= V_221 ;
} else {
V_135 = - V_153 ;
if ( ! V_49 -> V_219 -> V_222 ) {
V_49 -> V_219 -> V_222 = 1 ;
V_135 = 1 ;
}
}
F_130 ( & V_49 -> V_219 -> V_150 ) ;
return V_135 ;
}
int F_174 ( struct V_9 * V_10 )
{
struct V_223 * V_223 = F_78 ( V_10 -> V_108 ) ;
T_8 V_224 = V_223 -> V_127 ;
int V_184 ;
V_10 -> V_202 -> V_225 = F_147 () ;
V_10 -> V_202 -> V_226 = F_150 () ;
if ( ! ( V_10 -> V_108 -> V_128 . V_129 -> V_130 & V_227 ) &&
! V_14 -> V_217 &&
F_175 ( V_10 -> V_202 -> V_228 , V_223 -> V_229 ) &&
F_176 ( V_10 -> V_202 -> V_228 , V_223 -> V_230 ) ) {
if ( V_224 & V_231 ) {
V_10 -> V_192 |= V_232 ;
V_10 -> V_202 -> V_225 = V_223 -> V_229 ;
}
if ( ( V_224 & ( V_233 | V_234 ) ) == ( V_233 | V_234 ) ) {
V_10 -> V_192 |= V_232 ;
V_10 -> V_202 -> V_226 = V_223 -> V_230 ;
}
}
V_184 = F_177 ( V_10 ) ;
if ( V_184 )
return V_184 ;
V_10 -> V_235 = 1 ;
memset ( V_10 -> V_179 , 0 , V_236 ) ;
return F_82 ( V_10 -> V_108 , 0 , V_10 -> V_179 , V_236 ) ;
}
int F_178 ( struct V_9 * V_10 )
{
int V_21 = 0 ;
unsigned long V_72 ;
char * V_68 ;
struct V_18 * V_18 ;
if ( ! V_10 -> V_66 )
return 0 ;
do {
V_72 = V_10 -> V_49 & ~ V_74 ;
V_18 = F_14 ( V_10 , V_10 -> V_49 , 0 ) ;
if ( ! V_18 ) {
V_21 = - V_62 ;
goto V_71;
}
V_68 = F_179 ( V_18 ) ;
for (; V_72 < V_28 && V_68 [ V_72 ] ;
V_72 ++ , V_10 -> V_49 ++ )
;
F_180 ( V_68 ) ;
F_20 ( V_18 ) ;
if ( V_72 == V_28 )
F_21 ( V_10 , ( V_10 -> V_49 >> V_237 ) - 1 ) ;
} while ( V_72 == V_28 );
V_10 -> V_49 ++ ;
V_10 -> V_66 -- ;
V_21 = 0 ;
V_71:
return V_21 ;
}
int F_181 ( struct V_9 * V_10 )
{
bool V_238 = F_182 ( V_239 ) ;
struct V_1 * V_2 ;
int V_184 ;
if ( V_10 -> V_240 > 5 )
return - V_241 ;
V_184 = F_183 ( V_10 ) ;
if ( V_184 )
return V_184 ;
V_184 = - V_242 ;
V_243:
F_132 ( & V_5 ) ;
F_184 (fmt, &formats, lh) {
if ( ! F_185 ( V_2 -> V_8 ) )
continue;
F_133 ( & V_5 ) ;
V_10 -> V_240 ++ ;
V_184 = V_2 -> V_4 ( V_10 ) ;
V_10 -> V_240 -- ;
if ( V_184 >= 0 || V_184 != - V_244 ||
V_10 -> V_13 == NULL || V_10 -> V_108 == NULL ) {
F_10 ( V_2 ) ;
return V_184 ;
}
F_132 ( & V_5 ) ;
F_10 ( V_2 ) ;
}
F_133 ( & V_5 ) ;
if ( V_238 && V_184 == - V_244 ) {
if ( F_186 ( V_10 -> V_179 [ 0 ] ) && F_186 ( V_10 -> V_179 [ 1 ] ) &&
F_186 ( V_10 -> V_179 [ 2 ] ) && F_186 ( V_10 -> V_179 [ 3 ] ) )
return V_184 ;
if ( F_187 ( L_1 , * ( V_245 * ) ( V_10 -> V_179 + 2 ) ) < 0 )
return V_184 ;
V_238 = false ;
goto V_243;
}
return V_184 ;
}
static int F_188 ( struct V_9 * V_10 )
{
T_9 V_246 , V_247 ;
int V_21 ;
V_246 = V_14 -> V_164 ;
F_171 () ;
V_247 = F_189 ( V_14 , F_190 ( V_14 -> V_175 ) ) ;
F_173 () ;
V_21 = F_181 ( V_10 ) ;
if ( V_21 >= 0 ) {
F_191 ( V_10 ) ;
F_192 ( V_14 , V_246 , V_10 ) ;
F_193 ( V_248 , V_247 ) ;
V_14 -> V_249 = 1 ;
F_194 ( V_14 ) ;
if ( V_10 -> V_108 ) {
F_195 ( V_10 -> V_108 ) ;
F_81 ( V_10 -> V_108 ) ;
V_10 -> V_108 = NULL ;
}
}
return V_21 ;
}
static int F_196 ( const char * V_110 ,
struct V_55 V_56 ,
struct V_55 V_250 )
{
struct V_9 * V_10 ;
struct V_108 * V_108 ;
struct V_251 * V_252 ;
bool V_253 ;
int V_184 ;
if ( ( V_14 -> V_186 & V_254 ) &&
F_125 ( & F_197 () -> V_255 ) > V_26 ( V_256 ) ) {
V_184 = - V_153 ;
goto V_257;
}
V_14 -> V_186 &= ~ V_254 ;
V_184 = F_198 ( & V_252 ) ;
if ( V_184 )
goto V_257;
V_184 = - V_37 ;
V_10 = F_199 ( sizeof( * V_10 ) , V_36 ) ;
if ( ! V_10 )
goto V_258;
V_184 = F_155 ( V_10 ) ;
if ( V_184 )
goto V_259;
V_184 = F_170 ( V_10 ) ;
if ( V_184 < 0 )
goto V_259;
V_253 = V_184 ;
V_14 -> V_260 = 1 ;
V_108 = F_75 ( V_110 ) ;
V_184 = F_200 ( V_108 ) ;
if ( F_49 ( V_108 ) )
goto V_261;
F_201 () ;
V_10 -> V_108 = V_108 ;
V_10 -> V_110 = V_110 ;
V_10 -> V_210 = V_110 ;
V_184 = F_38 ( V_10 ) ;
if ( V_184 )
goto V_262;
V_10 -> V_66 = F_48 ( V_56 , V_263 ) ;
if ( ( V_184 = V_10 -> V_66 ) < 0 )
goto V_71;
V_10 -> V_264 = F_48 ( V_250 , V_263 ) ;
if ( ( V_184 = V_10 -> V_264 ) < 0 )
goto V_71;
V_184 = F_174 ( V_10 ) ;
if ( V_184 < 0 )
goto V_71;
V_184 = F_58 ( 1 , & V_10 -> V_110 , V_10 ) ;
if ( V_184 < 0 )
goto V_71;
V_10 -> V_101 = V_10 -> V_49 ;
V_184 = F_52 ( V_10 -> V_264 , V_250 , V_10 ) ;
if ( V_184 < 0 )
goto V_71;
V_184 = F_52 ( V_10 -> V_66 , V_56 , V_10 ) ;
if ( V_184 < 0 )
goto V_71;
V_184 = F_188 ( V_10 ) ;
if ( V_184 < 0 )
goto V_71;
V_14 -> V_219 -> V_222 = 0 ;
V_14 -> V_260 = 0 ;
F_202 ( V_14 ) ;
F_203 ( V_14 ) ;
F_159 ( V_10 ) ;
if ( V_252 )
F_204 ( V_252 ) ;
return V_184 ;
V_71:
if ( V_10 -> V_13 ) {
F_12 ( V_10 , 0 ) ;
F_98 ( V_10 -> V_13 ) ;
}
V_262:
if ( V_10 -> V_108 ) {
F_195 ( V_10 -> V_108 ) ;
F_81 ( V_10 -> V_108 ) ;
}
V_261:
if ( V_253 )
V_14 -> V_219 -> V_222 = 0 ;
V_14 -> V_260 = 0 ;
V_259:
F_159 ( V_10 ) ;
V_258:
if ( V_252 )
F_205 ( V_252 ) ;
V_257:
return V_184 ;
}
int F_206 ( const char * V_110 ,
const char T_1 * const T_1 * V_75 ,
const char T_1 * const T_1 * V_265 )
{
struct V_55 V_56 = { . V_61 . V_58 = V_75 } ;
struct V_55 V_250 = { . V_61 . V_58 = V_265 } ;
return F_196 ( V_110 , V_56 , V_250 ) ;
}
static int F_207 ( const char * V_110 ,
const T_2 T_1 * V_75 ,
const T_2 T_1 * V_265 )
{
struct V_55 V_56 = {
. V_59 = true ,
. V_61 . V_60 = V_75 ,
} ;
struct V_55 V_250 = {
. V_59 = true ,
. V_61 . V_60 = V_265 ,
} ;
return F_196 ( V_110 , V_56 , V_250 ) ;
}
void F_208 ( struct V_1 * V_266 )
{
struct V_12 * V_13 = V_14 -> V_13 ;
if ( V_13 -> V_267 )
F_11 ( V_13 -> V_267 -> V_8 ) ;
V_13 -> V_267 = V_266 ;
if ( V_266 )
F_209 ( V_266 -> V_8 ) ;
}
void F_152 ( struct V_12 * V_13 , int V_268 )
{
switch ( V_268 ) {
case V_269 :
F_210 ( V_270 , & V_13 -> V_186 ) ;
F_211 () ;
F_210 ( V_271 , & V_13 -> V_186 ) ;
break;
case V_198 :
F_212 ( V_270 , & V_13 -> V_186 ) ;
F_211 () ;
F_210 ( V_271 , & V_13 -> V_186 ) ;
break;
case V_272 :
F_212 ( V_271 , & V_13 -> V_186 ) ;
F_211 () ;
F_212 ( V_270 , & V_13 -> V_186 ) ;
break;
}
}
int F_213 ( unsigned long V_273 )
{
int V_21 ;
V_21 = V_273 & V_274 ;
return ( V_21 > V_198 ) ? V_272 : V_21 ;
}
int F_167 ( struct V_12 * V_13 )
{
return F_213 ( V_13 -> V_186 ) ;
}
T_10 long F_214 ( const char T_1 * V_110 ,
const T_2 T_1 * V_56 ,
const T_2 T_1 * V_250 )
{
struct V_110 * V_275 = F_215 ( V_110 ) ;
int error = F_200 ( V_275 ) ;
if ( ! F_49 ( V_275 ) ) {
error = F_207 ( V_275 -> V_109 , V_56 , V_250 ) ;
F_216 ( V_275 ) ;
}
return error ;
}
