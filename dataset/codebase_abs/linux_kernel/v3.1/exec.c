int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( ! V_2 )
return - V_4 ;
F_2 ( & V_5 ) ;
V_3 ? F_3 ( & V_2 -> V_6 , & V_7 ) :
F_4 ( & V_2 -> V_6 , & V_7 ) ;
F_5 ( & V_5 ) ;
return 0 ;
}
void F_6 ( struct V_1 * V_2 )
{
F_2 ( & V_5 ) ;
F_7 ( & V_2 -> V_6 ) ;
F_5 ( & V_5 ) ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_8 ) ;
}
static void F_10 ( struct V_9 * V_10 , unsigned long V_11 )
{
struct V_12 * V_13 = V_14 -> V_13 ;
long V_15 = ( long ) ( V_11 - V_10 -> V_16 ) ;
if ( ! V_13 || ! V_15 )
return;
V_10 -> V_16 = V_11 ;
F_11 ( V_13 , V_17 , V_15 ) ;
}
static struct V_18 * F_12 ( struct V_9 * V_10 , unsigned long V_19 ,
int V_20 )
{
struct V_18 * V_18 ;
int V_21 ;
#ifdef F_13
if ( V_20 ) {
V_21 = F_14 ( V_10 -> V_22 , V_19 ) ;
if ( V_21 < 0 )
return NULL ;
}
#endif
V_21 = F_15 ( V_14 , V_10 -> V_13 , V_19 ,
1 , V_20 , 1 , & V_18 , NULL ) ;
if ( V_21 <= 0 )
return NULL ;
if ( V_20 ) {
unsigned long V_23 = V_10 -> V_22 -> V_24 - V_10 -> V_22 -> V_25 ;
struct V_26 * V_27 ;
F_10 ( V_10 , V_23 / V_28 ) ;
if ( V_23 <= V_29 )
return V_18 ;
V_27 = V_14 -> signal -> V_27 ;
if ( V_23 > F_16 ( V_27 [ V_30 ] . V_31 ) / 4 ) {
F_17 ( V_18 ) ;
return NULL ;
}
}
return V_18 ;
}
static void F_18 ( struct V_18 * V_18 )
{
F_17 ( V_18 ) ;
}
static void F_19 ( struct V_9 * V_10 , int V_32 )
{
}
static void F_20 ( struct V_9 * V_10 )
{
}
static void F_21 ( struct V_9 * V_10 , unsigned long V_19 ,
struct V_18 * V_18 )
{
F_22 ( V_10 -> V_22 , V_19 , F_23 ( V_18 ) ) ;
}
static int F_24 ( struct V_9 * V_10 )
{
int V_33 ;
struct V_34 * V_22 = NULL ;
struct V_12 * V_13 = V_10 -> V_13 ;
V_10 -> V_22 = V_22 = F_25 ( V_35 , V_36 ) ;
if ( ! V_22 )
return - V_37 ;
F_26 ( & V_13 -> V_38 ) ;
V_22 -> V_39 = V_13 ;
F_27 ( V_40 & V_41 ) ;
V_22 -> V_24 = V_42 ;
V_22 -> V_25 = V_22 -> V_24 - V_28 ;
V_22 -> V_43 = V_40 | V_41 ;
V_22 -> V_44 = F_28 ( V_22 -> V_43 ) ;
F_29 ( & V_22 -> V_45 ) ;
V_33 = F_30 ( NULL , 0 , 0 , 0 , V_22 -> V_25 , 1 ) ;
if ( V_33 )
goto V_33;
V_33 = F_31 ( V_13 , V_22 ) ;
if ( V_33 )
goto V_33;
V_13 -> V_46 = V_13 -> V_47 = 1 ;
F_32 ( & V_13 -> V_38 ) ;
V_10 -> V_48 = V_22 -> V_24 - sizeof( void * ) ;
return 0 ;
V_33:
F_32 ( & V_13 -> V_38 ) ;
V_10 -> V_22 = NULL ;
F_33 ( V_35 , V_22 ) ;
return V_33 ;
}
static bool F_34 ( struct V_9 * V_10 , long V_49 )
{
return V_49 <= V_50 ;
}
static inline void F_10 ( struct V_9 * V_10 , unsigned long V_11 )
{
}
static struct V_18 * F_12 ( struct V_9 * V_10 , unsigned long V_19 ,
int V_20 )
{
struct V_18 * V_18 ;
V_18 = V_10 -> V_18 [ V_19 / V_28 ] ;
if ( ! V_18 && V_20 ) {
V_18 = F_35 ( V_51 | V_52 ) ;
if ( ! V_18 )
return NULL ;
V_10 -> V_18 [ V_19 / V_28 ] = V_18 ;
}
return V_18 ;
}
static void F_18 ( struct V_18 * V_18 )
{
}
static void F_19 ( struct V_9 * V_10 , int V_32 )
{
if ( V_10 -> V_18 [ V_32 ] ) {
F_36 ( V_10 -> V_18 [ V_32 ] ) ;
V_10 -> V_18 [ V_32 ] = NULL ;
}
}
static void F_20 ( struct V_9 * V_10 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_53 ; V_32 ++ )
F_19 ( V_10 , V_32 ) ;
}
static void F_21 ( struct V_9 * V_10 , unsigned long V_19 ,
struct V_18 * V_18 )
{
}
static int F_24 ( struct V_9 * V_10 )
{
V_10 -> V_48 = V_28 * V_53 - sizeof( void * ) ;
return 0 ;
}
static bool F_34 ( struct V_9 * V_10 , long V_49 )
{
return V_49 <= V_10 -> V_48 ;
}
int F_37 ( struct V_9 * V_10 )
{
int V_33 ;
struct V_12 * V_13 = NULL ;
V_10 -> V_13 = V_13 = F_38 () ;
V_33 = - V_37 ;
if ( ! V_13 )
goto V_33;
V_33 = F_39 ( V_14 , V_13 ) ;
if ( V_33 )
goto V_33;
V_33 = F_24 ( V_10 ) ;
if ( V_33 )
goto V_33;
return 0 ;
V_33:
if ( V_13 ) {
V_10 -> V_13 = NULL ;
F_40 ( V_13 ) ;
}
return V_33 ;
}
static const char T_1 * F_41 ( struct V_54 V_55 , int V_56 )
{
const char T_1 * V_57 ;
#ifdef F_42
if ( F_43 ( V_55 . V_58 ) ) {
T_2 V_59 ;
if ( F_44 ( V_59 , V_55 . V_60 . V_59 + V_56 ) )
return F_45 ( - V_61 ) ;
return F_46 ( V_59 ) ;
}
#endif
if ( F_44 ( V_57 , V_55 . V_60 . V_57 + V_56 ) )
return F_45 ( - V_61 ) ;
return V_57 ;
}
static int F_47 ( struct V_54 V_55 , int V_62 )
{
int V_32 = 0 ;
if ( V_55 . V_60 . V_57 != NULL ) {
for (; ; ) {
const char T_1 * V_48 = F_41 ( V_55 , V_32 ) ;
if ( ! V_48 )
break;
if ( F_48 ( V_48 ) )
return - V_61 ;
if ( V_32 ++ >= V_62 )
return - V_63 ;
if ( F_49 ( V_14 ) )
return - V_64 ;
F_50 () ;
}
}
return V_32 ;
}
static int F_51 ( int V_65 , struct V_54 V_55 ,
struct V_9 * V_10 )
{
struct V_18 * V_66 = NULL ;
char * V_67 = NULL ;
unsigned long V_68 = 0 ;
int V_21 ;
while ( V_65 -- > 0 ) {
const char T_1 * V_69 ;
int V_49 ;
unsigned long V_19 ;
V_21 = - V_61 ;
V_69 = F_41 ( V_55 , V_65 ) ;
if ( F_48 ( V_69 ) )
goto V_70;
V_49 = F_52 ( V_69 , V_50 ) ;
if ( ! V_49 )
goto V_70;
V_21 = - V_63 ;
if ( ! F_34 ( V_10 , V_49 ) )
goto V_70;
V_19 = V_10 -> V_48 ;
V_69 += V_49 ;
V_10 -> V_48 -= V_49 ;
while ( V_49 > 0 ) {
int V_71 , V_72 ;
if ( F_49 ( V_14 ) ) {
V_21 = - V_64 ;
goto V_70;
}
F_50 () ;
V_71 = V_19 % V_28 ;
if ( V_71 == 0 )
V_71 = V_28 ;
V_72 = V_71 ;
if ( V_72 > V_49 )
V_72 = V_49 ;
V_71 -= V_72 ;
V_19 -= V_72 ;
V_69 -= V_72 ;
V_49 -= V_72 ;
if ( ! V_66 || V_68 != ( V_19 & V_73 ) ) {
struct V_18 * V_18 ;
V_18 = F_12 ( V_10 , V_19 , 1 ) ;
if ( ! V_18 ) {
V_21 = - V_63 ;
goto V_70;
}
if ( V_66 ) {
F_53 ( V_66 ) ;
F_54 ( V_66 ) ;
F_18 ( V_66 ) ;
}
V_66 = V_18 ;
V_67 = F_55 ( V_66 ) ;
V_68 = V_19 & V_73 ;
F_21 ( V_10 , V_68 , V_66 ) ;
}
if ( F_56 ( V_67 + V_71 , V_69 , V_72 ) ) {
V_21 = - V_61 ;
goto V_70;
}
}
}
V_21 = 0 ;
V_70:
if ( V_66 ) {
F_53 ( V_66 ) ;
F_54 ( V_66 ) ;
F_18 ( V_66 ) ;
}
return V_21 ;
}
int F_57 ( int V_65 , const char * const * V_74 ,
struct V_9 * V_10 )
{
int V_75 ;
T_3 V_76 = F_58 () ;
struct V_54 V_55 = {
. V_60 . V_57 = ( const char T_1 * const T_1 * ) V_74 ,
} ;
F_59 ( V_77 ) ;
V_75 = F_51 ( V_65 , V_55 , V_10 ) ;
F_59 ( V_76 ) ;
return V_75 ;
}
static int F_60 ( struct V_34 * V_22 , unsigned long V_78 )
{
struct V_12 * V_13 = V_22 -> V_39 ;
unsigned long V_79 = V_22 -> V_25 ;
unsigned long V_80 = V_22 -> V_24 ;
unsigned long V_81 = V_80 - V_79 ;
unsigned long V_82 = V_79 - V_78 ;
unsigned long V_83 = V_80 - V_78 ;
struct V_84 V_85 ;
F_61 ( V_82 > V_83 ) ;
if ( V_22 != F_62 ( V_13 , V_82 ) )
return - V_61 ;
if ( F_63 ( V_22 , V_82 , V_80 , V_22 -> V_86 , NULL ) )
return - V_37 ;
if ( V_81 != F_64 ( V_22 , V_79 ,
V_22 , V_82 , V_81 ) )
return - V_37 ;
F_65 () ;
F_66 ( & V_85 , V_13 , 0 ) ;
if ( V_83 > V_79 ) {
F_67 ( & V_85 , V_83 , V_80 , V_83 ,
V_22 -> V_87 ? V_22 -> V_87 -> V_25 : 0 ) ;
} else {
F_67 ( & V_85 , V_79 , V_80 , V_83 ,
V_22 -> V_87 ? V_22 -> V_87 -> V_25 : 0 ) ;
}
F_68 ( & V_85 , V_83 , V_80 ) ;
F_63 ( V_22 , V_82 , V_83 , V_22 -> V_86 , NULL ) ;
return 0 ;
}
int F_69 ( struct V_9 * V_10 ,
unsigned long V_88 ,
int V_89 )
{
unsigned long V_21 ;
unsigned long V_90 ;
struct V_12 * V_13 = V_14 -> V_13 ;
struct V_34 * V_22 = V_10 -> V_22 ;
struct V_34 * V_91 = NULL ;
unsigned long V_43 ;
unsigned long V_92 ;
unsigned long V_93 ;
unsigned long V_94 ;
unsigned long V_95 ;
#ifdef F_13
V_92 = F_70 ( V_30 ) ;
if ( V_92 > ( 1 << 30 ) )
V_92 = 1 << 30 ;
if ( V_22 -> V_24 - V_22 -> V_25 > V_92 )
return - V_37 ;
V_92 = F_71 ( V_88 - V_92 ) ;
V_90 = V_22 -> V_25 - V_92 ;
V_13 -> V_96 = V_10 -> V_48 - V_90 ;
V_10 -> V_48 = V_22 -> V_24 - V_90 ;
#else
V_88 = F_72 ( V_88 ) ;
V_88 = F_71 ( V_88 ) ;
if ( F_43 ( V_88 < V_97 ) ||
F_43 ( V_22 -> V_24 - V_22 -> V_25 >= V_88 - V_97 ) )
return - V_37 ;
V_90 = V_22 -> V_24 - V_88 ;
V_10 -> V_48 -= V_90 ;
V_13 -> V_96 = V_10 -> V_48 ;
#endif
if ( V_10 -> V_98 )
V_10 -> V_98 -= V_90 ;
V_10 -> V_99 -= V_90 ;
F_26 ( & V_13 -> V_38 ) ;
V_43 = V_40 ;
if ( F_43 ( V_89 == V_100 ) )
V_43 |= V_101 ;
else if ( V_89 == V_102 )
V_43 &= ~ V_101 ;
V_43 |= V_13 -> V_103 ;
V_43 |= V_41 ;
V_21 = F_73 ( V_22 , & V_91 , V_22 -> V_25 , V_22 -> V_24 ,
V_43 ) ;
if ( V_21 )
goto V_104;
F_61 ( V_91 != V_22 ) ;
if ( V_90 ) {
V_21 = F_60 ( V_22 , V_90 ) ;
if ( V_21 )
goto V_104;
}
V_22 -> V_43 &= ~ V_41 ;
V_94 = 131072UL ;
V_93 = V_22 -> V_24 - V_22 -> V_25 ;
V_95 = V_26 ( V_30 ) & V_73 ;
#ifdef F_13
if ( V_93 + V_94 > V_95 )
V_92 = V_22 -> V_25 + V_95 ;
else
V_92 = V_22 -> V_24 + V_94 ;
#else
if ( V_93 + V_94 > V_95 )
V_92 = V_22 -> V_24 - V_95 ;
else
V_92 = V_22 -> V_25 - V_94 ;
#endif
V_14 -> V_13 -> V_105 = V_10 -> V_48 ;
V_21 = F_74 ( V_22 , V_92 ) ;
if ( V_21 )
V_21 = - V_61 ;
V_104:
F_32 ( & V_13 -> V_38 ) ;
return V_21 ;
}
struct V_106 * F_75 ( const char * V_107 )
{
struct V_106 * V_106 ;
int V_33 ;
static const struct V_108 V_109 = {
. V_110 = V_111 | V_112 | V_113 ,
. V_114 = V_115 | V_116 ,
. V_117 = V_118
} ;
V_106 = F_76 ( V_119 , V_107 , & V_109 , V_120 ) ;
if ( F_48 ( V_106 ) )
goto V_70;
V_33 = - V_121 ;
if ( ! F_77 ( V_106 -> V_122 . V_123 -> V_124 -> V_125 ) )
goto exit;
if ( V_106 -> V_122 . V_126 -> V_127 & V_128 )
goto exit;
F_78 ( V_106 ) ;
V_33 = F_79 ( V_106 ) ;
if ( V_33 )
goto exit;
V_70:
return V_106 ;
exit:
F_80 ( V_106 ) ;
return F_45 ( V_33 ) ;
}
int F_81 ( struct V_106 * V_106 , T_4 V_71 ,
char * V_129 , unsigned long F_47 )
{
T_3 V_130 ;
T_4 V_19 = V_71 ;
int V_131 ;
V_130 = F_58 () ;
F_59 ( F_82 () ) ;
V_131 = F_83 ( V_106 , ( void T_1 * ) V_129 , F_47 , & V_19 ) ;
F_59 ( V_130 ) ;
return V_131 ;
}
static int F_84 ( struct V_12 * V_13 )
{
struct V_132 * V_133 ;
struct V_12 * V_134 , * V_135 ;
V_133 = V_14 ;
V_134 = V_14 -> V_13 ;
F_85 ( V_133 , V_134 ) ;
F_86 ( V_133 , V_134 ) ;
if ( V_134 ) {
F_87 ( & V_134 -> V_38 ) ;
if ( F_43 ( V_134 -> V_136 ) ) {
F_88 ( & V_134 -> V_38 ) ;
return - V_137 ;
}
}
F_89 ( V_133 ) ;
V_135 = V_133 -> V_135 ;
V_133 -> V_13 = V_13 ;
V_133 -> V_135 = V_13 ;
F_90 ( V_135 , V_13 ) ;
if ( V_134 && V_133 -> signal -> V_138 == V_139 ) {
F_91 ( & V_134 -> V_140 ) ;
F_92 ( & V_133 -> V_13 -> V_140 ) ;
}
F_93 ( V_133 ) ;
F_94 ( V_13 ) ;
if ( V_134 ) {
F_88 ( & V_134 -> V_38 ) ;
F_61 ( V_135 != V_134 ) ;
F_95 ( V_134 ) ;
F_96 ( V_134 ) ;
return 0 ;
}
F_40 ( V_135 ) ;
return 0 ;
}
static int F_97 ( struct V_132 * V_133 )
{
struct V_141 * V_142 = V_133 -> signal ;
struct V_143 * V_144 = V_133 -> V_145 ;
T_5 * V_146 = & V_144 -> V_147 ;
if ( F_98 ( V_133 ) )
goto V_148;
F_99 ( V_146 ) ;
if ( F_100 ( V_142 ) ) {
F_101 ( V_146 ) ;
return - V_149 ;
}
V_142 -> V_150 = V_133 ;
V_142 -> V_151 = F_102 ( V_133 ) ;
if ( ! F_103 ( V_133 ) )
V_142 -> V_151 -- ;
while ( V_142 -> V_151 ) {
F_104 ( V_152 ) ;
F_101 ( V_146 ) ;
F_105 () ;
F_99 ( V_146 ) ;
}
F_101 ( V_146 ) ;
if ( ! F_103 ( V_133 ) ) {
struct V_132 * V_153 = V_133 -> V_154 ;
V_142 -> V_151 = - 1 ;
for (; ; ) {
F_106 ( & V_155 ) ;
if ( F_107 ( V_153 -> V_156 ) )
break;
F_104 ( V_152 ) ;
F_108 ( & V_155 ) ;
F_105 () ;
}
V_133 -> V_157 = V_153 -> V_157 ;
F_61 ( ! F_109 ( V_153 , V_133 ) ) ;
F_61 ( F_110 ( V_133 ) ) ;
F_111 ( V_133 , V_158 ) ;
V_133 -> V_159 = V_153 -> V_159 ;
F_112 ( V_133 , V_158 , F_113 ( V_153 ) ) ;
F_114 ( V_153 , V_133 , V_160 ) ;
F_114 ( V_153 , V_133 , V_161 ) ;
F_115 ( & V_153 -> V_162 , & V_133 -> V_162 ) ;
F_116 ( & V_153 -> V_163 , & V_133 -> V_163 ) ;
V_133 -> V_154 = V_133 ;
V_153 -> V_154 = V_133 ;
V_133 -> V_164 = V_165 ;
V_153 -> V_164 = - 1 ;
F_61 ( V_153 -> V_156 != V_166 ) ;
V_153 -> V_156 = V_167 ;
if ( F_43 ( V_153 -> V_168 ) )
F_117 ( V_153 , V_153 -> V_169 ) ;
F_108 ( & V_155 ) ;
F_118 ( V_153 ) ;
}
V_142 -> V_150 = NULL ;
V_142 -> V_151 = 0 ;
V_148:
if ( V_14 -> V_13 )
F_119 ( & V_142 -> V_170 , V_14 -> V_13 ) ;
F_120 ( V_142 ) ;
F_121 () ;
if ( F_122 ( & V_144 -> F_47 ) != 1 ) {
struct V_143 * V_171 ;
V_171 = F_123 ( V_172 , V_36 ) ;
if ( ! V_171 )
return - V_37 ;
F_124 ( & V_171 -> F_47 , 1 ) ;
memcpy ( V_171 -> V_173 , V_144 -> V_173 ,
sizeof( V_171 -> V_173 ) ) ;
F_106 ( & V_155 ) ;
F_125 ( & V_144 -> V_147 ) ;
F_126 ( V_133 -> V_145 , V_171 ) ;
F_127 ( & V_144 -> V_147 ) ;
F_108 ( & V_155 ) ;
F_128 ( V_144 ) ;
}
F_61 ( ! F_103 ( V_133 ) ) ;
return 0 ;
}
static void F_129 ( struct V_174 * V_175 )
{
long V_176 = - 1 ;
struct V_177 * V_178 ;
F_125 ( & V_175 -> V_179 ) ;
for (; ; ) {
unsigned long V_180 , V_32 ;
V_176 ++ ;
V_32 = V_176 * V_181 ;
V_178 = F_130 ( V_175 ) ;
if ( V_32 >= V_178 -> V_182 )
break;
V_180 = V_178 -> V_183 -> V_184 [ V_176 ] ;
if ( ! V_180 )
continue;
V_178 -> V_183 -> V_184 [ V_176 ] = 0 ;
F_127 ( & V_175 -> V_179 ) ;
for ( ; V_180 ; V_32 ++ , V_180 >>= 1 ) {
if ( V_180 & 1 ) {
F_131 ( V_32 ) ;
}
}
F_125 ( & V_175 -> V_179 ) ;
}
F_127 ( & V_175 -> V_179 ) ;
}
char * F_132 ( char * V_185 , struct V_132 * V_133 )
{
F_89 ( V_133 ) ;
strncpy ( V_185 , V_133 -> V_186 , sizeof( V_133 -> V_186 ) ) ;
F_93 ( V_133 ) ;
return V_185 ;
}
void F_133 ( struct V_132 * V_133 , char * V_185 )
{
F_89 ( V_133 ) ;
memset ( V_133 -> V_186 , 0 , V_187 ) ;
F_134 () ;
F_135 ( V_133 -> V_186 , V_185 , sizeof( V_133 -> V_186 ) ) ;
F_93 ( V_133 ) ;
F_136 ( V_133 ) ;
}
int F_137 ( struct V_9 * V_10 )
{
int V_188 ;
V_188 = F_97 ( V_14 ) ;
if ( V_188 )
goto V_70;
F_138 ( V_10 -> V_13 , V_10 -> V_106 ) ;
F_10 ( V_10 , 0 ) ;
V_188 = F_84 ( V_10 -> V_13 ) ;
if ( V_188 )
goto V_70;
V_10 -> V_13 = NULL ;
F_59 ( V_189 ) ;
V_14 -> V_190 &= ~ ( V_191 | V_192 ) ;
F_139 () ;
V_14 -> V_193 &= ~ V_10 -> V_194 ;
return 0 ;
V_70:
return V_188 ;
}
void F_140 ( struct V_9 * V_10 , struct V_106 * V_106 )
{
if ( F_141 ( V_106 -> V_122 . V_123 -> V_124 , V_195 ) < 0 )
V_10 -> V_196 |= V_197 ;
}
void F_142 ( struct V_9 * V_10 )
{
int V_32 , V_198 ;
const char * V_107 ;
char V_199 [ sizeof( V_14 -> V_186 ) ] ;
F_94 ( V_14 -> V_13 ) ;
V_14 -> V_200 = V_14 -> V_201 = 0 ;
if ( F_143 () == F_144 () && F_145 () == F_146 () )
F_147 ( V_14 -> V_13 , 1 ) ;
else
F_147 ( V_14 -> V_13 , V_202 ) ;
V_107 = V_10 -> V_203 ;
for ( V_32 = 0 ; ( V_198 = * ( V_107 ++ ) ) != '\0' ; ) {
if ( V_198 == '/' )
V_32 = 0 ;
else
if ( V_32 < ( sizeof( V_199 ) - 1 ) )
V_199 [ V_32 ++ ] = V_198 ;
}
V_199 [ V_32 ] = '\0' ;
F_133 ( V_14 , V_199 ) ;
V_14 -> V_13 -> V_204 = V_205 ;
if ( V_10 -> V_206 -> V_207 != F_143 () ||
V_10 -> V_206 -> V_208 != F_145 () ) {
V_14 -> V_209 = 0 ;
} else {
F_140 ( V_10 , V_10 -> V_106 ) ;
if ( V_10 -> V_196 & V_197 )
F_147 ( V_14 -> V_13 , V_202 ) ;
}
if ( ! F_148 ( V_14 -> V_13 ) )
F_149 ( V_14 ) ;
V_14 -> V_210 ++ ;
F_150 ( V_14 , 0 ) ;
F_129 ( V_14 -> V_175 ) ;
}
int F_151 ( struct V_9 * V_10 )
{
if ( F_152 ( & V_14 -> signal -> V_211 ) )
return - V_212 ;
V_10 -> V_206 = F_153 () ;
if ( F_107 ( V_10 -> V_206 ) )
return 0 ;
F_154 ( & V_14 -> signal -> V_211 ) ;
return - V_37 ;
}
void F_155 ( struct V_9 * V_10 )
{
F_20 ( V_10 ) ;
if ( V_10 -> V_206 ) {
F_154 ( & V_14 -> signal -> V_211 ) ;
F_156 ( V_10 -> V_206 ) ;
}
F_157 ( V_10 ) ;
}
void F_158 ( struct V_9 * V_10 )
{
F_159 ( V_10 ) ;
F_160 ( V_10 -> V_206 ) ;
V_10 -> V_206 = NULL ;
F_161 ( V_10 ) ;
F_154 ( & V_14 -> signal -> V_211 ) ;
}
int F_162 ( struct V_9 * V_10 )
{
struct V_132 * V_48 = V_14 , * V_213 ;
unsigned V_214 ;
int V_215 = 0 ;
if ( V_48 -> V_168 ) {
if ( V_48 -> V_168 & V_216 )
V_10 -> V_217 |= V_218 ;
else
V_10 -> V_217 |= V_219 ;
}
V_214 = 1 ;
F_125 ( & V_48 -> V_220 -> V_146 ) ;
F_163 () ;
for ( V_213 = F_164 ( V_48 ) ; V_213 != V_48 ; V_213 = F_164 ( V_213 ) ) {
if ( V_213 -> V_220 == V_48 -> V_220 )
V_214 ++ ;
}
F_165 () ;
if ( V_48 -> V_220 -> V_221 > V_214 ) {
V_10 -> V_217 |= V_222 ;
} else {
V_215 = - V_149 ;
if ( ! V_48 -> V_220 -> V_223 ) {
V_48 -> V_220 -> V_223 = 1 ;
V_215 = 1 ;
}
}
F_127 ( & V_48 -> V_220 -> V_146 ) ;
return V_215 ;
}
int F_166 ( struct V_9 * V_10 )
{
T_6 V_224 ;
struct V_225 * V_225 = V_10 -> V_106 -> V_122 . V_123 -> V_124 ;
int V_188 ;
V_224 = V_225 -> V_125 ;
if ( V_10 -> V_106 -> V_226 == NULL )
return - V_121 ;
V_10 -> V_206 -> V_227 = F_143 () ;
V_10 -> V_206 -> V_228 = F_145 () ;
if ( ! ( V_10 -> V_106 -> V_122 . V_126 -> V_127 & V_229 ) ) {
if ( V_224 & V_230 ) {
V_10 -> V_194 |= V_231 ;
V_10 -> V_206 -> V_227 = V_225 -> V_232 ;
}
if ( ( V_224 & ( V_233 | V_234 ) ) == ( V_233 | V_234 ) ) {
V_10 -> V_194 |= V_231 ;
V_10 -> V_206 -> V_228 = V_225 -> V_235 ;
}
}
V_188 = F_167 ( V_10 ) ;
if ( V_188 )
return V_188 ;
V_10 -> V_236 = 1 ;
memset ( V_10 -> V_185 , 0 , V_237 ) ;
return F_81 ( V_10 -> V_106 , 0 , V_10 -> V_185 , V_237 ) ;
}
int F_168 ( struct V_9 * V_10 )
{
int V_21 = 0 ;
unsigned long V_71 ;
char * V_67 ;
struct V_18 * V_18 ;
if ( ! V_10 -> V_65 )
return 0 ;
do {
V_71 = V_10 -> V_48 & ~ V_73 ;
V_18 = F_12 ( V_10 , V_10 -> V_48 , 0 ) ;
if ( ! V_18 ) {
V_21 = - V_61 ;
goto V_70;
}
V_67 = F_169 ( V_18 , V_238 ) ;
for (; V_71 < V_28 && V_67 [ V_71 ] ;
V_71 ++ , V_10 -> V_48 ++ )
;
F_170 ( V_67 , V_238 ) ;
F_18 ( V_18 ) ;
if ( V_71 == V_28 )
F_19 ( V_10 , ( V_10 -> V_48 >> V_239 ) - 1 ) ;
} while ( V_71 == V_28 );
V_10 -> V_48 ++ ;
V_10 -> V_65 -- ;
V_21 = 0 ;
V_70:
return V_21 ;
}
int F_171 ( struct V_9 * V_10 , struct V_240 * V_241 )
{
unsigned int V_242 = V_10 -> V_243 ;
int V_244 , V_188 ;
struct V_1 * V_2 ;
T_7 V_245 ;
V_188 = F_172 ( V_10 ) ;
if ( V_188 )
return V_188 ;
V_188 = F_173 ( V_10 ) ;
if ( V_188 )
return V_188 ;
F_163 () ;
V_245 = F_174 ( V_14 , F_175 ( V_14 -> V_169 ) ) ;
F_165 () ;
V_188 = - V_246 ;
for ( V_244 = 0 ; V_244 < 2 ; V_244 ++ ) {
F_176 ( & V_5 ) ;
F_177 (fmt, &formats, lh) {
int (* F_178)( struct V_9 * , struct V_240 * ) = V_2 -> V_247 ;
if ( ! F_178 )
continue;
if ( ! F_179 ( V_2 -> V_8 ) )
continue;
F_180 ( & V_5 ) ;
V_188 = F_178 ( V_10 , V_241 ) ;
V_10 -> V_243 = V_242 ;
if ( V_188 >= 0 ) {
if ( V_242 == 0 )
F_181 ( V_248 ,
V_245 ) ;
F_8 ( V_2 ) ;
F_182 ( V_10 -> V_106 ) ;
if ( V_10 -> V_106 )
F_80 ( V_10 -> V_106 ) ;
V_10 -> V_106 = NULL ;
V_14 -> V_249 = 1 ;
F_183 ( V_14 ) ;
return V_188 ;
}
F_176 ( & V_5 ) ;
F_8 ( V_2 ) ;
if ( V_188 != - V_250 || V_10 -> V_13 == NULL )
break;
if ( ! V_10 -> V_106 ) {
F_180 ( & V_5 ) ;
return V_188 ;
}
}
F_180 ( & V_5 ) ;
#ifdef F_184
if ( V_188 != - V_250 || V_10 -> V_13 == NULL ) {
break;
} else {
#define F_185 ( T_8 ) (((c)=='\t') || ((c)=='\n') || (0x20<=(c) && (c)<=0x7e))
if ( F_185 ( V_10 -> V_185 [ 0 ] ) &&
F_185 ( V_10 -> V_185 [ 1 ] ) &&
F_185 ( V_10 -> V_185 [ 2 ] ) &&
F_185 ( V_10 -> V_185 [ 3 ] ) )
break;
if ( V_244 )
break;
F_186 ( L_1 , * ( unsigned short * ) ( & V_10 -> V_185 [ 2 ] ) ) ;
}
#else
break;
#endif
}
return V_188 ;
}
static int F_187 ( const char * V_203 ,
struct V_54 V_55 ,
struct V_54 V_251 ,
struct V_240 * V_241 )
{
struct V_9 * V_10 ;
struct V_106 * V_106 ;
struct V_174 * V_252 ;
bool V_253 ;
int V_188 ;
const struct V_206 * V_206 = F_188 () ;
if ( ( V_14 -> V_190 & V_254 ) &&
F_122 ( & V_206 -> V_255 -> V_256 ) > V_26 ( V_257 ) ) {
V_188 = - V_149 ;
goto V_258;
}
V_14 -> V_190 &= ~ V_254 ;
V_188 = F_189 ( & V_252 ) ;
if ( V_188 )
goto V_258;
V_188 = - V_37 ;
V_10 = F_190 ( sizeof( * V_10 ) , V_36 ) ;
if ( ! V_10 )
goto V_259;
V_188 = F_151 ( V_10 ) ;
if ( V_188 )
goto V_260;
V_188 = F_162 ( V_10 ) ;
if ( V_188 < 0 )
goto V_260;
V_253 = V_188 ;
V_14 -> V_261 = 1 ;
V_106 = F_75 ( V_203 ) ;
V_188 = F_191 ( V_106 ) ;
if ( F_48 ( V_106 ) )
goto V_262;
F_192 () ;
V_10 -> V_106 = V_106 ;
V_10 -> V_203 = V_203 ;
V_10 -> V_263 = V_203 ;
V_188 = F_37 ( V_10 ) ;
if ( V_188 )
goto V_264;
V_10 -> V_65 = F_47 ( V_55 , V_265 ) ;
if ( ( V_188 = V_10 -> V_65 ) < 0 )
goto V_70;
V_10 -> V_266 = F_47 ( V_251 , V_265 ) ;
if ( ( V_188 = V_10 -> V_266 ) < 0 )
goto V_70;
V_188 = F_166 ( V_10 ) ;
if ( V_188 < 0 )
goto V_70;
V_188 = F_57 ( 1 , & V_10 -> V_203 , V_10 ) ;
if ( V_188 < 0 )
goto V_70;
V_10 -> V_99 = V_10 -> V_48 ;
V_188 = F_51 ( V_10 -> V_266 , V_251 , V_10 ) ;
if ( V_188 < 0 )
goto V_70;
V_188 = F_51 ( V_10 -> V_65 , V_55 , V_10 ) ;
if ( V_188 < 0 )
goto V_70;
V_188 = F_171 ( V_10 , V_241 ) ;
if ( V_188 < 0 )
goto V_70;
V_14 -> V_220 -> V_223 = 0 ;
V_14 -> V_261 = 0 ;
F_193 ( V_14 ) ;
F_155 ( V_10 ) ;
if ( V_252 )
F_194 ( V_252 ) ;
return V_188 ;
V_70:
if ( V_10 -> V_13 ) {
F_10 ( V_10 , 0 ) ;
F_96 ( V_10 -> V_13 ) ;
}
V_264:
if ( V_10 -> V_106 ) {
F_182 ( V_10 -> V_106 ) ;
F_80 ( V_10 -> V_106 ) ;
}
V_262:
if ( V_253 )
V_14 -> V_220 -> V_223 = 0 ;
V_14 -> V_261 = 0 ;
V_260:
F_155 ( V_10 ) ;
V_259:
if ( V_252 )
F_195 ( V_252 ) ;
V_258:
return V_188 ;
}
int F_196 ( const char * V_203 ,
const char T_1 * const T_1 * V_74 ,
const char T_1 * const T_1 * V_267 ,
struct V_240 * V_241 )
{
struct V_54 V_55 = { . V_60 . V_57 = V_74 } ;
struct V_54 V_251 = { . V_60 . V_57 = V_267 } ;
return F_187 ( V_203 , V_55 , V_251 , V_241 ) ;
}
int F_197 ( char * V_203 ,
T_2 T_1 * V_74 ,
T_2 T_1 * V_267 ,
struct V_240 * V_241 )
{
struct V_54 V_55 = {
. V_58 = true ,
. V_60 . V_59 = V_74 ,
} ;
struct V_54 V_251 = {
. V_58 = true ,
. V_60 . V_59 = V_267 ,
} ;
return F_187 ( V_203 , V_55 , V_251 , V_241 ) ;
}
void F_198 ( struct V_1 * V_268 )
{
struct V_12 * V_13 = V_14 -> V_13 ;
if ( V_13 -> V_269 )
F_9 ( V_13 -> V_269 -> V_8 ) ;
V_13 -> V_269 = V_268 ;
if ( V_268 )
F_199 ( V_268 -> V_8 ) ;
}
static int F_200 ( struct V_270 * V_271 )
{
char * V_272 = V_271 -> V_273 ;
V_271 -> V_23 = V_274 * F_201 ( & V_275 ) ;
V_271 -> V_273 = F_202 ( V_272 , V_271 -> V_23 , V_36 ) ;
if ( ! V_271 -> V_273 ) {
F_157 ( V_272 ) ;
return - V_37 ;
}
return 0 ;
}
static int F_203 ( struct V_270 * V_271 , const char * V_2 , ... )
{
char * V_276 ;
int V_277 ;
int V_21 ;
T_9 V_278 ;
va_start ( V_278 , V_2 ) ;
V_277 = vsnprintf ( NULL , 0 , V_2 , V_278 ) ;
va_end ( V_278 ) ;
if ( F_107 ( V_277 < V_271 -> V_23 - V_271 -> V_279 - 1 ) )
goto V_280;
V_21 = F_200 ( V_271 ) ;
if ( V_21 )
goto V_281;
V_280:
V_276 = V_271 -> V_273 + V_271 -> V_279 ;
va_start ( V_278 , V_2 ) ;
vsnprintf ( V_276 , V_277 + 1 , V_2 , V_278 ) ;
va_end ( V_278 ) ;
V_271 -> V_279 += V_277 ;
return 0 ;
V_281:
return V_21 ;
}
static void F_204 ( char * V_69 )
{
for (; * V_69 ; V_69 ++ )
if ( * V_69 == '/' )
* V_69 = '!' ;
}
static int F_205 ( struct V_270 * V_271 )
{
struct V_106 * V_282 ;
char * V_283 , * V_284 ;
int V_21 ;
V_282 = F_206 ( V_14 -> V_13 ) ;
if ( ! V_282 ) {
char * V_285 = V_271 -> V_273 + V_271 -> V_279 ;
V_21 = F_203 ( V_271 , L_2 , V_14 -> V_186 ) ;
F_204 ( V_285 ) ;
return V_21 ;
}
V_283 = F_207 ( V_286 , V_287 ) ;
if ( ! V_283 ) {
V_21 = - V_37 ;
goto V_288;
}
V_284 = F_208 ( & V_282 -> V_122 , V_283 , V_286 ) ;
if ( F_48 ( V_284 ) ) {
V_21 = F_191 ( V_284 ) ;
goto V_289;
}
F_204 ( V_284 ) ;
V_21 = F_203 ( V_271 , L_3 , V_284 ) ;
V_289:
F_157 ( V_283 ) ;
V_288:
F_80 ( V_282 ) ;
return V_21 ;
}
static int F_209 ( struct V_270 * V_271 , long V_290 )
{
const struct V_206 * V_206 = F_188 () ;
const char * V_291 = V_292 ;
int V_293 = ( * V_291 == '|' ) ;
int V_294 = 0 ;
int V_33 = 0 ;
V_271 -> V_23 = V_274 * F_122 ( & V_275 ) ;
V_271 -> V_273 = F_207 ( V_271 -> V_23 , V_36 ) ;
V_271 -> V_279 = 0 ;
if ( ! V_271 -> V_273 )
return - V_37 ;
while ( * V_291 ) {
if ( * V_291 != '%' ) {
if ( * V_291 == 0 )
goto V_70;
V_33 = F_203 ( V_271 , L_4 , * V_291 ++ ) ;
} else {
switch ( * ++ V_291 ) {
case 0 :
goto V_70;
case '%' :
V_33 = F_203 ( V_271 , L_4 , '%' ) ;
break;
case 'p' :
V_294 = 1 ;
V_33 = F_203 ( V_271 , L_5 ,
F_210 ( V_14 ) ) ;
break;
case 'u' :
V_33 = F_203 ( V_271 , L_5 , V_206 -> V_207 ) ;
break;
case 'g' :
V_33 = F_203 ( V_271 , L_5 , V_206 -> V_208 ) ;
break;
case 's' :
V_33 = F_203 ( V_271 , L_6 , V_290 ) ;
break;
case 't' : {
struct V_295 V_296 ;
F_211 ( & V_296 ) ;
V_33 = F_203 ( V_271 , L_7 , V_296 . V_297 ) ;
break;
}
case 'h' : {
char * V_298 = V_271 -> V_273 + V_271 -> V_279 ;
F_87 ( & V_299 ) ;
V_33 = F_203 ( V_271 , L_3 ,
F_212 () -> V_300 ) ;
F_88 ( & V_299 ) ;
F_204 ( V_298 ) ;
break;
}
case 'e' : {
char * V_285 = V_271 -> V_273 + V_271 -> V_279 ;
V_33 = F_203 ( V_271 , L_3 , V_14 -> V_186 ) ;
F_204 ( V_285 ) ;
break;
}
case 'E' :
V_33 = F_205 ( V_271 ) ;
break;
case 'c' :
V_33 = F_203 ( V_271 , L_7 ,
V_26 ( V_301 ) ) ;
break;
default:
break;
}
++ V_291 ;
}
if ( V_33 )
return V_33 ;
}
if ( ! V_293 && ! V_294 && V_302 ) {
V_33 = F_203 ( V_271 , L_8 , F_210 ( V_14 ) ) ;
if ( V_33 )
return V_33 ;
}
V_70:
return V_293 ;
}
static int F_213 ( struct V_132 * V_303 , int V_304 )
{
struct V_132 * V_213 ;
int V_56 = 0 ;
V_303 -> signal -> V_190 = V_305 ;
V_303 -> signal -> V_306 = V_304 ;
V_303 -> signal -> V_307 = 0 ;
V_213 = V_303 ;
do {
F_214 ( V_213 , V_308 ) ;
if ( V_213 != V_14 && V_213 -> V_13 ) {
F_215 ( & V_213 -> V_309 . signal , V_310 ) ;
F_216 ( V_213 , 1 ) ;
V_56 ++ ;
}
} while_each_thread(start, t) ;
inline int F_217 ( struct V_132 * V_133 , struct V_12 * V_13 ,
struct V_136 * V_136 , int V_304 )
{
struct V_132 * V_311 , * V_48 ;
unsigned long V_190 ;
int V_56 = - V_149 ;
F_99 ( & V_133 -> V_145 -> V_147 ) ;
if ( ! F_100 ( V_133 -> signal ) ) {
V_13 -> V_136 = V_136 ;
V_56 = F_213 ( V_133 , V_304 ) ;
}
F_101 ( & V_133 -> V_145 -> V_147 ) ;
if ( F_43 ( V_56 < 0 ) )
return V_56 ;
if ( F_122 ( & V_13 -> V_312 ) == V_56 + 1 )
goto V_313;
F_163 () ;
F_218 (g) {
if ( V_311 == V_133 -> V_154 )
continue;
if ( V_311 -> V_190 & V_192 )
continue;
V_48 = V_311 ;
do {
if ( V_48 -> V_13 ) {
if ( F_43 ( V_48 -> V_13 == V_13 ) ) {
F_219 ( V_48 , & V_190 ) ;
V_56 += F_213 ( V_48 , V_304 ) ;
F_220 ( V_48 , & V_190 ) ;
}
break;
}
} while_each_thread(g, p) ;
}
int F_221 ( int V_304 , struct V_136 * V_136 )
{
struct V_132 * V_133 = V_14 ;
struct V_12 * V_13 = V_133 -> V_13 ;
struct V_314 * V_315 ;
int V_316 = - V_317 ;
F_222 ( & V_136 -> V_318 ) ;
V_136 -> V_319 . V_320 = V_133 ;
V_136 -> V_319 . V_321 = NULL ;
F_26 ( & V_13 -> V_38 ) ;
if ( ! V_13 -> V_136 )
V_316 = F_217 ( V_133 , V_13 , V_136 , V_304 ) ;
F_32 ( & V_13 -> V_38 ) ;
if ( F_43 ( V_316 < 0 ) )
goto V_322;
V_315 = V_133 -> V_315 ;
if ( V_315 ) {
V_133 -> V_315 = NULL ;
F_223 ( V_315 ) ;
}
if ( V_316 )
F_224 ( & V_136 -> V_318 ) ;
V_322:
return V_316 ;
}
static void F_225 ( struct V_12 * V_13 )
{
struct V_323 * V_324 , * V_321 ;
struct V_132 * V_320 ;
V_321 = V_13 -> V_136 -> V_319 . V_321 ;
while ( ( V_324 = V_321 ) != NULL ) {
V_321 = V_324 -> V_321 ;
V_320 = V_324 -> V_320 ;
F_226 () ;
V_324 -> V_320 = NULL ;
F_227 ( V_320 ) ;
}
V_13 -> V_136 = NULL ;
}
void F_147 ( struct V_12 * V_13 , int V_325 )
{
switch ( V_325 ) {
case 0 :
F_228 ( V_326 , & V_13 -> V_190 ) ;
F_229 () ;
F_228 ( V_327 , & V_13 -> V_190 ) ;
break;
case 1 :
F_230 ( V_326 , & V_13 -> V_190 ) ;
F_229 () ;
F_228 ( V_327 , & V_13 -> V_190 ) ;
break;
case 2 :
F_230 ( V_327 , & V_13 -> V_190 ) ;
F_229 () ;
F_230 ( V_326 , & V_13 -> V_190 ) ;
break;
}
}
static int F_231 ( unsigned long V_328 )
{
int V_21 ;
V_21 = V_328 & V_329 ;
return ( V_21 >= 2 ) ? 2 : V_21 ;
}
int F_148 ( struct V_12 * V_13 )
{
return F_231 ( V_13 -> V_190 ) ;
}
static void F_232 ( struct V_106 * V_106 )
{
struct V_330 * V_331 ;
V_331 = V_106 -> V_122 . V_123 -> V_124 -> V_332 ;
F_233 ( V_331 ) ;
V_331 -> V_333 ++ ;
V_331 -> V_334 -- ;
while ( ( V_331 -> V_333 > 1 ) && ( ! F_234 ( V_14 ) ) ) {
F_235 ( & V_331 -> V_335 ) ;
F_236 ( & V_331 -> V_336 , V_337 , V_338 ) ;
F_237 ( V_331 ) ;
}
V_331 -> V_333 -- ;
V_331 -> V_334 ++ ;
F_238 ( V_331 ) ;
}
static int F_239 ( struct V_339 * V_340 , struct V_206 * V_268 )
{
struct V_106 * V_341 , * V_342 ;
struct V_177 * V_178 ;
struct V_343 * V_344 = (struct V_343 * ) V_340 -> V_345 ;
struct V_174 * V_346 = V_14 -> V_175 ;
V_342 = F_240 ( 0 ) ;
if ( F_48 ( V_342 ) )
return F_191 ( V_342 ) ;
V_341 = F_241 ( V_342 , 0 ) ;
if ( F_48 ( V_341 ) ) {
F_242 ( V_342 ) ;
return F_191 ( V_341 ) ;
}
V_344 -> V_106 = V_342 ;
F_131 ( 0 ) ;
F_243 ( 0 , V_341 ) ;
F_125 ( & V_346 -> V_179 ) ;
V_178 = F_130 ( V_346 ) ;
F_244 ( 0 , V_178 -> V_347 ) ;
F_245 ( 0 , V_178 -> V_183 ) ;
F_127 ( & V_346 -> V_179 ) ;
V_14 -> signal -> V_27 [ V_301 ] = (struct V_26 ) { 1 , 1 } ;
return 0 ;
}
void F_246 ( long V_290 , int V_304 , struct V_240 * V_241 )
{
struct V_136 V_136 ;
struct V_270 V_271 ;
struct V_12 * V_13 = V_14 -> V_13 ;
struct V_1 * V_269 ;
const struct V_206 * V_348 ;
struct V_206 * V_206 ;
int V_188 = 0 ;
int V_349 = 0 ;
int V_293 ;
static T_10 V_350 = F_247 ( 0 ) ;
struct V_343 V_351 = {
. V_290 = V_290 ,
. V_241 = V_241 ,
. V_352 = V_26 ( V_301 ) ,
. V_328 = V_13 -> V_190 ,
} ;
F_248 ( V_290 ) ;
V_269 = V_13 -> V_269 ;
if ( ! V_269 || ! V_269 -> V_353 )
goto V_322;
if ( ! F_231 ( V_351 . V_328 ) )
goto V_322;
V_206 = F_249 () ;
if ( ! V_206 )
goto V_322;
if ( F_231 ( V_351 . V_328 ) == 2 ) {
V_349 = V_354 ;
V_206 -> V_355 = 0 ;
}
V_188 = F_221 ( V_304 , & V_136 ) ;
if ( V_188 < 0 )
goto V_356;
V_348 = F_250 ( V_206 ) ;
F_251 ( V_357 ) ;
V_293 = F_209 ( & V_271 , V_290 ) ;
if ( V_293 ) {
int V_358 ;
char * * V_359 ;
if ( V_293 < 0 ) {
F_252 ( V_360 L_9 ) ;
F_252 ( V_360 L_10 ) ;
goto V_361;
}
if ( V_351 . V_352 == 1 ) {
F_252 ( V_360
L_11 ,
F_210 ( V_14 ) , V_14 -> V_186 ) ;
F_252 ( V_360 L_10 ) ;
goto V_362;
}
V_351 . V_352 = V_363 ;
V_358 = F_201 ( & V_350 ) ;
if ( V_364 && ( V_364 < V_358 ) ) {
F_252 ( V_360 L_12 ,
F_210 ( V_14 ) , V_14 -> V_186 ) ;
F_252 ( V_360 L_13 ) ;
goto V_365;
}
V_359 = F_253 ( V_36 , V_271 . V_273 + 1 , NULL ) ;
if ( ! V_359 ) {
F_252 ( V_360 L_14 ,
V_366 ) ;
goto V_365;
}
V_188 = F_254 ( V_359 [ 0 ] , V_359 ,
NULL , V_367 , F_239 ,
NULL , & V_351 ) ;
F_255 ( V_359 ) ;
if ( V_188 ) {
F_252 ( V_368 L_15 ,
V_271 . V_273 ) ;
goto V_369;
}
} else {
struct V_225 * V_225 ;
if ( V_351 . V_352 < V_269 -> V_370 )
goto V_362;
V_351 . V_106 = F_256 ( V_271 . V_273 ,
V_371 | 2 | V_372 | V_111 | V_349 ,
0600 ) ;
if ( F_48 ( V_351 . V_106 ) )
goto V_362;
V_225 = V_351 . V_106 -> V_122 . V_123 -> V_124 ;
if ( V_225 -> V_373 > 1 )
goto V_369;
if ( F_257 ( V_351 . V_106 -> V_122 . V_123 ) )
goto V_369;
if ( ! F_77 ( V_225 -> V_125 ) )
goto V_369;
if ( V_225 -> V_232 != F_258 () )
goto V_369;
if ( ! V_351 . V_106 -> V_226 || ! V_351 . V_106 -> V_226 -> V_20 )
goto V_369;
if ( F_259 ( V_351 . V_106 -> V_122 . V_123 , 0 , 0 , V_351 . V_106 ) )
goto V_369;
}
V_188 = V_269 -> V_353 ( & V_351 ) ;
if ( V_188 )
V_14 -> signal -> V_306 |= 0x80 ;
if ( V_293 && V_364 )
F_232 ( V_351 . V_106 ) ;
V_369:
if ( V_351 . V_106 )
F_260 ( V_351 . V_106 , NULL ) ;
V_365:
if ( V_293 )
F_91 ( & V_350 ) ;
V_362:
F_157 ( V_271 . V_273 ) ;
V_361:
F_225 ( V_13 ) ;
F_261 ( V_348 ) ;
V_356:
F_262 ( V_206 ) ;
V_322:
return;
}
int F_263 ( struct V_106 * V_106 , const void * V_129 , int V_56 )
{
return F_264 ( V_374 , V_129 , V_56 ) && V_106 -> V_226 -> V_20 ( V_106 , V_129 , V_56 , & V_106 -> V_375 ) == V_56 ;
}
int F_265 ( struct V_106 * V_106 , T_4 V_376 )
{
int V_21 = 1 ;
if ( V_106 -> V_226 -> V_377 && V_106 -> V_226 -> V_377 != V_378 ) {
if ( V_106 -> V_226 -> V_377 ( V_106 , V_376 , V_379 ) < 0 )
return 0 ;
} else {
char * V_185 = ( char * ) F_266 ( V_36 ) ;
if ( ! V_185 )
return 0 ;
while ( V_376 > 0 ) {
unsigned long V_380 = V_376 ;
if ( V_380 > V_28 )
V_380 = V_28 ;
if ( ! F_263 ( V_106 , V_185 , V_380 ) ) {
V_21 = 0 ;
break;
}
V_376 -= V_380 ;
}
F_267 ( ( unsigned long ) V_185 ) ;
}
return V_21 ;
}
