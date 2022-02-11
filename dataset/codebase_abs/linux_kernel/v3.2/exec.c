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
F_91 ( V_133 ) ;
F_92 ( V_13 ) ;
if ( V_134 ) {
F_88 ( & V_134 -> V_38 ) ;
F_61 ( V_135 != V_134 ) ;
F_93 ( V_134 ) ;
F_94 ( V_134 ) ;
return 0 ;
}
F_40 ( V_135 ) ;
return 0 ;
}
static int F_95 ( struct V_132 * V_133 )
{
struct V_138 * V_139 = V_133 -> signal ;
struct V_140 * V_141 = V_133 -> V_142 ;
T_5 * V_143 = & V_141 -> V_144 ;
if ( F_96 ( V_133 ) )
goto V_145;
F_97 ( V_143 ) ;
if ( F_98 ( V_139 ) ) {
F_99 ( V_143 ) ;
return - V_146 ;
}
V_139 -> V_147 = V_133 ;
V_139 -> V_148 = F_100 ( V_133 ) ;
if ( ! F_101 ( V_133 ) )
V_139 -> V_148 -- ;
while ( V_139 -> V_148 ) {
F_102 ( V_149 ) ;
F_99 ( V_143 ) ;
F_103 () ;
F_97 ( V_143 ) ;
}
F_99 ( V_143 ) ;
if ( ! F_101 ( V_133 ) ) {
struct V_132 * V_150 = V_133 -> V_151 ;
V_139 -> V_148 = - 1 ;
for (; ; ) {
F_104 ( & V_152 ) ;
if ( F_105 ( V_150 -> V_153 ) )
break;
F_102 ( V_149 ) ;
F_106 ( & V_152 ) ;
F_103 () ;
}
V_133 -> V_154 = V_150 -> V_154 ;
F_61 ( ! F_107 ( V_150 , V_133 ) ) ;
F_61 ( F_108 ( V_133 ) ) ;
F_109 ( V_133 , V_155 ) ;
V_133 -> V_156 = V_150 -> V_156 ;
F_110 ( V_133 , V_155 , F_111 ( V_150 ) ) ;
F_112 ( V_150 , V_133 , V_157 ) ;
F_112 ( V_150 , V_133 , V_158 ) ;
F_113 ( & V_150 -> V_159 , & V_133 -> V_159 ) ;
F_114 ( & V_150 -> V_160 , & V_133 -> V_160 ) ;
V_133 -> V_151 = V_133 ;
V_150 -> V_151 = V_133 ;
V_133 -> V_161 = V_162 ;
V_150 -> V_161 = - 1 ;
F_61 ( V_150 -> V_153 != V_163 ) ;
V_150 -> V_153 = V_164 ;
if ( F_43 ( V_150 -> V_165 ) )
F_115 ( V_150 , V_150 -> V_166 ) ;
F_106 ( & V_152 ) ;
F_116 ( V_150 ) ;
}
V_139 -> V_147 = NULL ;
V_139 -> V_148 = 0 ;
V_145:
if ( V_14 -> V_13 )
F_117 ( & V_139 -> V_167 , V_14 -> V_13 ) ;
F_118 ( V_139 ) ;
F_119 () ;
if ( F_120 ( & V_141 -> F_47 ) != 1 ) {
struct V_140 * V_168 ;
V_168 = F_121 ( V_169 , V_36 ) ;
if ( ! V_168 )
return - V_37 ;
F_122 ( & V_168 -> F_47 , 1 ) ;
memcpy ( V_168 -> V_170 , V_141 -> V_170 ,
sizeof( V_168 -> V_170 ) ) ;
F_104 ( & V_152 ) ;
F_123 ( & V_141 -> V_144 ) ;
F_124 ( V_133 -> V_142 , V_168 ) ;
F_125 ( & V_141 -> V_144 ) ;
F_106 ( & V_152 ) ;
F_126 ( V_141 ) ;
}
F_61 ( ! F_101 ( V_133 ) ) ;
return 0 ;
}
static void F_127 ( struct V_171 * V_172 )
{
long V_173 = - 1 ;
struct V_174 * V_175 ;
F_123 ( & V_172 -> V_176 ) ;
for (; ; ) {
unsigned long V_177 , V_32 ;
V_173 ++ ;
V_32 = V_173 * V_178 ;
V_175 = F_128 ( V_172 ) ;
if ( V_32 >= V_175 -> V_179 )
break;
V_177 = V_175 -> V_180 -> V_181 [ V_173 ] ;
if ( ! V_177 )
continue;
V_175 -> V_180 -> V_181 [ V_173 ] = 0 ;
F_125 ( & V_172 -> V_176 ) ;
for ( ; V_177 ; V_32 ++ , V_177 >>= 1 ) {
if ( V_177 & 1 ) {
F_129 ( V_32 ) ;
}
}
F_123 ( & V_172 -> V_176 ) ;
}
F_125 ( & V_172 -> V_176 ) ;
}
char * F_130 ( char * V_182 , struct V_132 * V_133 )
{
F_89 ( V_133 ) ;
strncpy ( V_182 , V_133 -> V_183 , sizeof( V_133 -> V_183 ) ) ;
F_91 ( V_133 ) ;
return V_182 ;
}
void F_131 ( struct V_132 * V_133 , char * V_182 )
{
F_89 ( V_133 ) ;
memset ( V_133 -> V_183 , 0 , V_184 ) ;
F_132 () ;
F_133 ( V_133 -> V_183 , V_182 , sizeof( V_133 -> V_183 ) ) ;
F_91 ( V_133 ) ;
F_134 ( V_133 ) ;
}
int F_135 ( struct V_9 * V_10 )
{
int V_185 ;
V_185 = F_95 ( V_14 ) ;
if ( V_185 )
goto V_70;
F_136 ( V_10 -> V_13 , V_10 -> V_106 ) ;
F_10 ( V_10 , 0 ) ;
V_185 = F_84 ( V_10 -> V_13 ) ;
if ( V_185 )
goto V_70;
V_10 -> V_13 = NULL ;
F_59 ( V_186 ) ;
V_14 -> V_187 &= ~ ( V_188 | V_189 ) ;
F_137 () ;
V_14 -> V_190 &= ~ V_10 -> V_191 ;
return 0 ;
V_70:
return V_185 ;
}
void F_138 ( struct V_9 * V_10 , struct V_106 * V_106 )
{
if ( F_139 ( V_106 -> V_122 . V_123 -> V_124 , V_192 ) < 0 )
V_10 -> V_193 |= V_194 ;
}
void F_140 ( struct V_9 * V_10 )
{
int V_32 , V_195 ;
const char * V_107 ;
char V_196 [ sizeof( V_14 -> V_183 ) ] ;
F_92 ( V_14 -> V_13 ) ;
V_14 -> V_197 = V_14 -> V_198 = 0 ;
if ( F_141 () == F_142 () && F_143 () == F_144 () )
F_145 ( V_14 -> V_13 , 1 ) ;
else
F_145 ( V_14 -> V_13 , V_199 ) ;
V_107 = V_10 -> V_200 ;
for ( V_32 = 0 ; ( V_195 = * ( V_107 ++ ) ) != '\0' ; ) {
if ( V_195 == '/' )
V_32 = 0 ;
else
if ( V_32 < ( sizeof( V_196 ) - 1 ) )
V_196 [ V_32 ++ ] = V_195 ;
}
V_196 [ V_32 ] = '\0' ;
F_131 ( V_14 , V_196 ) ;
V_14 -> V_13 -> V_201 = V_202 ;
if ( V_10 -> V_203 -> V_204 != F_141 () ||
V_10 -> V_203 -> V_205 != F_143 () ) {
V_14 -> V_206 = 0 ;
} else {
F_138 ( V_10 , V_10 -> V_106 ) ;
if ( V_10 -> V_193 & V_194 )
F_145 ( V_14 -> V_13 , V_199 ) ;
}
if ( ! F_146 ( V_14 -> V_13 ) )
F_147 ( V_14 ) ;
V_14 -> V_207 ++ ;
F_148 ( V_14 , 0 ) ;
F_127 ( V_14 -> V_172 ) ;
}
int F_149 ( struct V_9 * V_10 )
{
if ( F_150 ( & V_14 -> signal -> V_208 ) )
return - V_209 ;
V_10 -> V_203 = F_151 () ;
if ( F_105 ( V_10 -> V_203 ) )
return 0 ;
F_152 ( & V_14 -> signal -> V_208 ) ;
return - V_37 ;
}
void F_153 ( struct V_9 * V_10 )
{
F_20 ( V_10 ) ;
if ( V_10 -> V_203 ) {
F_152 ( & V_14 -> signal -> V_208 ) ;
F_154 ( V_10 -> V_203 ) ;
}
F_155 ( V_10 ) ;
}
void F_156 ( struct V_9 * V_10 )
{
F_157 ( V_10 ) ;
F_158 ( V_10 -> V_203 ) ;
V_10 -> V_203 = NULL ;
F_159 ( V_10 ) ;
F_152 ( & V_14 -> signal -> V_208 ) ;
}
int F_160 ( struct V_9 * V_10 )
{
struct V_132 * V_48 = V_14 , * V_210 ;
unsigned V_211 ;
int V_212 = 0 ;
if ( V_48 -> V_165 ) {
if ( V_48 -> V_165 & V_213 )
V_10 -> V_214 |= V_215 ;
else
V_10 -> V_214 |= V_216 ;
}
V_211 = 1 ;
F_123 ( & V_48 -> V_217 -> V_143 ) ;
F_161 () ;
for ( V_210 = F_162 ( V_48 ) ; V_210 != V_48 ; V_210 = F_162 ( V_210 ) ) {
if ( V_210 -> V_217 == V_48 -> V_217 )
V_211 ++ ;
}
F_163 () ;
if ( V_48 -> V_217 -> V_218 > V_211 ) {
V_10 -> V_214 |= V_219 ;
} else {
V_212 = - V_146 ;
if ( ! V_48 -> V_217 -> V_220 ) {
V_48 -> V_217 -> V_220 = 1 ;
V_212 = 1 ;
}
}
F_125 ( & V_48 -> V_217 -> V_143 ) ;
return V_212 ;
}
int F_164 ( struct V_9 * V_10 )
{
T_6 V_221 ;
struct V_222 * V_222 = V_10 -> V_106 -> V_122 . V_123 -> V_124 ;
int V_185 ;
V_221 = V_222 -> V_125 ;
if ( V_10 -> V_106 -> V_223 == NULL )
return - V_121 ;
V_10 -> V_203 -> V_224 = F_141 () ;
V_10 -> V_203 -> V_225 = F_143 () ;
if ( ! ( V_10 -> V_106 -> V_122 . V_126 -> V_127 & V_226 ) ) {
if ( V_221 & V_227 ) {
V_10 -> V_191 |= V_228 ;
V_10 -> V_203 -> V_224 = V_222 -> V_229 ;
}
if ( ( V_221 & ( V_230 | V_231 ) ) == ( V_230 | V_231 ) ) {
V_10 -> V_191 |= V_228 ;
V_10 -> V_203 -> V_225 = V_222 -> V_232 ;
}
}
V_185 = F_165 ( V_10 ) ;
if ( V_185 )
return V_185 ;
V_10 -> V_233 = 1 ;
memset ( V_10 -> V_182 , 0 , V_234 ) ;
return F_81 ( V_10 -> V_106 , 0 , V_10 -> V_182 , V_234 ) ;
}
int F_166 ( struct V_9 * V_10 )
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
V_67 = F_167 ( V_18 , V_235 ) ;
for (; V_71 < V_28 && V_67 [ V_71 ] ;
V_71 ++ , V_10 -> V_48 ++ )
;
F_168 ( V_67 , V_235 ) ;
F_18 ( V_18 ) ;
if ( V_71 == V_28 )
F_19 ( V_10 , ( V_10 -> V_48 >> V_236 ) - 1 ) ;
} while ( V_71 == V_28 );
V_10 -> V_48 ++ ;
V_10 -> V_65 -- ;
V_21 = 0 ;
V_70:
return V_21 ;
}
int F_169 ( struct V_9 * V_10 , struct V_237 * V_238 )
{
unsigned int V_239 = V_10 -> V_240 ;
int V_241 , V_185 ;
struct V_1 * V_2 ;
T_7 V_242 ;
V_185 = F_170 ( V_10 ) ;
if ( V_185 )
return V_185 ;
V_185 = F_171 ( V_10 ) ;
if ( V_185 )
return V_185 ;
F_161 () ;
V_242 = F_172 ( V_14 , F_173 ( V_14 -> V_166 ) ) ;
F_163 () ;
V_185 = - V_243 ;
for ( V_241 = 0 ; V_241 < 2 ; V_241 ++ ) {
F_174 ( & V_5 ) ;
F_175 (fmt, &formats, lh) {
int (* F_176)( struct V_9 * , struct V_237 * ) = V_2 -> V_244 ;
if ( ! F_176 )
continue;
if ( ! F_177 ( V_2 -> V_8 ) )
continue;
F_178 ( & V_5 ) ;
V_185 = F_176 ( V_10 , V_238 ) ;
V_10 -> V_240 = V_239 ;
if ( V_185 >= 0 ) {
if ( V_239 == 0 )
F_179 ( V_245 ,
V_242 ) ;
F_8 ( V_2 ) ;
F_180 ( V_10 -> V_106 ) ;
if ( V_10 -> V_106 )
F_80 ( V_10 -> V_106 ) ;
V_10 -> V_106 = NULL ;
V_14 -> V_246 = 1 ;
F_181 ( V_14 ) ;
return V_185 ;
}
F_174 ( & V_5 ) ;
F_8 ( V_2 ) ;
if ( V_185 != - V_247 || V_10 -> V_13 == NULL )
break;
if ( ! V_10 -> V_106 ) {
F_178 ( & V_5 ) ;
return V_185 ;
}
}
F_178 ( & V_5 ) ;
#ifdef F_182
if ( V_185 != - V_247 || V_10 -> V_13 == NULL ) {
break;
} else {
#define F_183 ( T_8 ) (((c)=='\t') || ((c)=='\n') || (0x20<=(c) && (c)<=0x7e))
if ( F_183 ( V_10 -> V_182 [ 0 ] ) &&
F_183 ( V_10 -> V_182 [ 1 ] ) &&
F_183 ( V_10 -> V_182 [ 2 ] ) &&
F_183 ( V_10 -> V_182 [ 3 ] ) )
break;
if ( V_241 )
break;
F_184 ( L_1 , * ( unsigned short * ) ( & V_10 -> V_182 [ 2 ] ) ) ;
}
#else
break;
#endif
}
return V_185 ;
}
static int F_185 ( const char * V_200 ,
struct V_54 V_55 ,
struct V_54 V_248 ,
struct V_237 * V_238 )
{
struct V_9 * V_10 ;
struct V_106 * V_106 ;
struct V_171 * V_249 ;
bool V_250 ;
int V_185 ;
const struct V_203 * V_203 = F_186 () ;
if ( ( V_14 -> V_187 & V_251 ) &&
F_120 ( & V_203 -> V_252 -> V_253 ) > V_26 ( V_254 ) ) {
V_185 = - V_146 ;
goto V_255;
}
V_14 -> V_187 &= ~ V_251 ;
V_185 = F_187 ( & V_249 ) ;
if ( V_185 )
goto V_255;
V_185 = - V_37 ;
V_10 = F_188 ( sizeof( * V_10 ) , V_36 ) ;
if ( ! V_10 )
goto V_256;
V_185 = F_149 ( V_10 ) ;
if ( V_185 )
goto V_257;
V_185 = F_160 ( V_10 ) ;
if ( V_185 < 0 )
goto V_257;
V_250 = V_185 ;
V_14 -> V_258 = 1 ;
V_106 = F_75 ( V_200 ) ;
V_185 = F_189 ( V_106 ) ;
if ( F_48 ( V_106 ) )
goto V_259;
F_190 () ;
V_10 -> V_106 = V_106 ;
V_10 -> V_200 = V_200 ;
V_10 -> V_260 = V_200 ;
V_185 = F_37 ( V_10 ) ;
if ( V_185 )
goto V_261;
V_10 -> V_65 = F_47 ( V_55 , V_262 ) ;
if ( ( V_185 = V_10 -> V_65 ) < 0 )
goto V_70;
V_10 -> V_263 = F_47 ( V_248 , V_262 ) ;
if ( ( V_185 = V_10 -> V_263 ) < 0 )
goto V_70;
V_185 = F_164 ( V_10 ) ;
if ( V_185 < 0 )
goto V_70;
V_185 = F_57 ( 1 , & V_10 -> V_200 , V_10 ) ;
if ( V_185 < 0 )
goto V_70;
V_10 -> V_99 = V_10 -> V_48 ;
V_185 = F_51 ( V_10 -> V_263 , V_248 , V_10 ) ;
if ( V_185 < 0 )
goto V_70;
V_185 = F_51 ( V_10 -> V_65 , V_55 , V_10 ) ;
if ( V_185 < 0 )
goto V_70;
V_185 = F_169 ( V_10 , V_238 ) ;
if ( V_185 < 0 )
goto V_70;
V_14 -> V_217 -> V_220 = 0 ;
V_14 -> V_258 = 0 ;
F_191 ( V_14 ) ;
F_153 ( V_10 ) ;
if ( V_249 )
F_192 ( V_249 ) ;
return V_185 ;
V_70:
if ( V_10 -> V_13 ) {
F_10 ( V_10 , 0 ) ;
F_94 ( V_10 -> V_13 ) ;
}
V_261:
if ( V_10 -> V_106 ) {
F_180 ( V_10 -> V_106 ) ;
F_80 ( V_10 -> V_106 ) ;
}
V_259:
if ( V_250 )
V_14 -> V_217 -> V_220 = 0 ;
V_14 -> V_258 = 0 ;
V_257:
F_153 ( V_10 ) ;
V_256:
if ( V_249 )
F_193 ( V_249 ) ;
V_255:
return V_185 ;
}
int F_194 ( const char * V_200 ,
const char T_1 * const T_1 * V_74 ,
const char T_1 * const T_1 * V_264 ,
struct V_237 * V_238 )
{
struct V_54 V_55 = { . V_60 . V_57 = V_74 } ;
struct V_54 V_248 = { . V_60 . V_57 = V_264 } ;
return F_185 ( V_200 , V_55 , V_248 , V_238 ) ;
}
int F_195 ( char * V_200 ,
T_2 T_1 * V_74 ,
T_2 T_1 * V_264 ,
struct V_237 * V_238 )
{
struct V_54 V_55 = {
. V_58 = true ,
. V_60 . V_59 = V_74 ,
} ;
struct V_54 V_248 = {
. V_58 = true ,
. V_60 . V_59 = V_264 ,
} ;
return F_185 ( V_200 , V_55 , V_248 , V_238 ) ;
}
void F_196 ( struct V_1 * V_265 )
{
struct V_12 * V_13 = V_14 -> V_13 ;
if ( V_13 -> V_266 )
F_9 ( V_13 -> V_266 -> V_8 ) ;
V_13 -> V_266 = V_265 ;
if ( V_265 )
F_197 ( V_265 -> V_8 ) ;
}
static int F_198 ( struct V_267 * V_268 )
{
char * V_269 = V_268 -> V_270 ;
V_268 -> V_23 = V_271 * F_199 ( & V_272 ) ;
V_268 -> V_270 = F_200 ( V_269 , V_268 -> V_23 , V_36 ) ;
if ( ! V_268 -> V_270 ) {
F_155 ( V_269 ) ;
return - V_37 ;
}
return 0 ;
}
static int F_201 ( struct V_267 * V_268 , const char * V_2 , ... )
{
char * V_273 ;
int V_274 ;
int V_21 ;
T_9 V_275 ;
va_start ( V_275 , V_2 ) ;
V_274 = vsnprintf ( NULL , 0 , V_2 , V_275 ) ;
va_end ( V_275 ) ;
if ( F_105 ( V_274 < V_268 -> V_23 - V_268 -> V_276 - 1 ) )
goto V_277;
V_21 = F_198 ( V_268 ) ;
if ( V_21 )
goto V_278;
V_277:
V_273 = V_268 -> V_270 + V_268 -> V_276 ;
va_start ( V_275 , V_2 ) ;
vsnprintf ( V_273 , V_274 + 1 , V_2 , V_275 ) ;
va_end ( V_275 ) ;
V_268 -> V_276 += V_274 ;
return 0 ;
V_278:
return V_21 ;
}
static void F_202 ( char * V_69 )
{
for (; * V_69 ; V_69 ++ )
if ( * V_69 == '/' )
* V_69 = '!' ;
}
static int F_203 ( struct V_267 * V_268 )
{
struct V_106 * V_279 ;
char * V_280 , * V_281 ;
int V_21 ;
V_279 = F_204 ( V_14 -> V_13 ) ;
if ( ! V_279 ) {
char * V_282 = V_268 -> V_270 + V_268 -> V_276 ;
V_21 = F_201 ( V_268 , L_2 , V_14 -> V_183 ) ;
F_202 ( V_282 ) ;
return V_21 ;
}
V_280 = F_205 ( V_283 , V_284 ) ;
if ( ! V_280 ) {
V_21 = - V_37 ;
goto V_285;
}
V_281 = F_206 ( & V_279 -> V_122 , V_280 , V_283 ) ;
if ( F_48 ( V_281 ) ) {
V_21 = F_189 ( V_281 ) ;
goto V_286;
}
F_202 ( V_281 ) ;
V_21 = F_201 ( V_268 , L_3 , V_281 ) ;
V_286:
F_155 ( V_280 ) ;
V_285:
F_80 ( V_279 ) ;
return V_21 ;
}
static int F_207 ( struct V_267 * V_268 , long V_287 )
{
const struct V_203 * V_203 = F_186 () ;
const char * V_288 = V_289 ;
int V_290 = ( * V_288 == '|' ) ;
int V_291 = 0 ;
int V_33 = 0 ;
V_268 -> V_23 = V_271 * F_120 ( & V_272 ) ;
V_268 -> V_270 = F_205 ( V_268 -> V_23 , V_36 ) ;
V_268 -> V_276 = 0 ;
if ( ! V_268 -> V_270 )
return - V_37 ;
while ( * V_288 ) {
if ( * V_288 != '%' ) {
if ( * V_288 == 0 )
goto V_70;
V_33 = F_201 ( V_268 , L_4 , * V_288 ++ ) ;
} else {
switch ( * ++ V_288 ) {
case 0 :
goto V_70;
case '%' :
V_33 = F_201 ( V_268 , L_4 , '%' ) ;
break;
case 'p' :
V_291 = 1 ;
V_33 = F_201 ( V_268 , L_5 ,
F_208 ( V_14 ) ) ;
break;
case 'u' :
V_33 = F_201 ( V_268 , L_5 , V_203 -> V_204 ) ;
break;
case 'g' :
V_33 = F_201 ( V_268 , L_5 , V_203 -> V_205 ) ;
break;
case 's' :
V_33 = F_201 ( V_268 , L_6 , V_287 ) ;
break;
case 't' : {
struct V_292 V_293 ;
F_209 ( & V_293 ) ;
V_33 = F_201 ( V_268 , L_7 , V_293 . V_294 ) ;
break;
}
case 'h' : {
char * V_295 = V_268 -> V_270 + V_268 -> V_276 ;
F_87 ( & V_296 ) ;
V_33 = F_201 ( V_268 , L_3 ,
F_210 () -> V_297 ) ;
F_88 ( & V_296 ) ;
F_202 ( V_295 ) ;
break;
}
case 'e' : {
char * V_282 = V_268 -> V_270 + V_268 -> V_276 ;
V_33 = F_201 ( V_268 , L_3 , V_14 -> V_183 ) ;
F_202 ( V_282 ) ;
break;
}
case 'E' :
V_33 = F_203 ( V_268 ) ;
break;
case 'c' :
V_33 = F_201 ( V_268 , L_7 ,
V_26 ( V_298 ) ) ;
break;
default:
break;
}
++ V_288 ;
}
if ( V_33 )
return V_33 ;
}
if ( ! V_290 && ! V_291 && V_299 ) {
V_33 = F_201 ( V_268 , L_8 , F_208 ( V_14 ) ) ;
if ( V_33 )
return V_33 ;
}
V_70:
return V_290 ;
}
static int F_211 ( struct V_132 * V_300 , int V_301 )
{
struct V_132 * V_210 ;
int V_56 = 0 ;
V_300 -> signal -> V_187 = V_302 ;
V_300 -> signal -> V_303 = V_301 ;
V_300 -> signal -> V_304 = 0 ;
V_210 = V_300 ;
do {
F_212 ( V_210 , V_305 ) ;
if ( V_210 != V_14 && V_210 -> V_13 ) {
F_213 ( & V_210 -> V_306 . signal , V_307 ) ;
F_214 ( V_210 , 1 ) ;
V_56 ++ ;
}
} while_each_thread(start, t) ;
inline int F_215 ( struct V_132 * V_133 , struct V_12 * V_13 ,
struct V_136 * V_136 , int V_301 )
{
struct V_132 * V_308 , * V_48 ;
unsigned long V_187 ;
int V_56 = - V_146 ;
F_97 ( & V_133 -> V_142 -> V_144 ) ;
if ( ! F_98 ( V_133 -> signal ) ) {
V_13 -> V_136 = V_136 ;
V_56 = F_211 ( V_133 , V_301 ) ;
}
F_99 ( & V_133 -> V_142 -> V_144 ) ;
if ( F_43 ( V_56 < 0 ) )
return V_56 ;
if ( F_120 ( & V_13 -> V_309 ) == V_56 + 1 )
goto V_310;
F_161 () ;
F_216 (g) {
if ( V_308 == V_133 -> V_151 )
continue;
if ( V_308 -> V_187 & V_189 )
continue;
V_48 = V_308 ;
do {
if ( V_48 -> V_13 ) {
if ( F_43 ( V_48 -> V_13 == V_13 ) ) {
F_217 ( V_48 , & V_187 ) ;
V_56 += F_211 ( V_48 , V_301 ) ;
F_218 ( V_48 , & V_187 ) ;
}
break;
}
} while_each_thread(g, p) ;
}
int F_219 ( int V_301 , struct V_136 * V_136 )
{
struct V_132 * V_133 = V_14 ;
struct V_12 * V_13 = V_133 -> V_13 ;
struct V_311 * V_312 ;
int V_313 = - V_314 ;
F_220 ( & V_136 -> V_315 ) ;
V_136 -> V_316 . V_317 = V_133 ;
V_136 -> V_316 . V_318 = NULL ;
F_26 ( & V_13 -> V_38 ) ;
if ( ! V_13 -> V_136 )
V_313 = F_215 ( V_133 , V_13 , V_136 , V_301 ) ;
F_32 ( & V_13 -> V_38 ) ;
if ( F_43 ( V_313 < 0 ) )
goto V_319;
V_312 = V_133 -> V_312 ;
if ( V_312 ) {
V_133 -> V_312 = NULL ;
F_221 ( V_312 ) ;
}
if ( V_313 )
F_222 ( & V_136 -> V_315 ) ;
V_319:
return V_313 ;
}
static void F_223 ( struct V_12 * V_13 )
{
struct V_320 * V_321 , * V_318 ;
struct V_132 * V_317 ;
V_318 = V_13 -> V_136 -> V_316 . V_318 ;
while ( ( V_321 = V_318 ) != NULL ) {
V_318 = V_321 -> V_318 ;
V_317 = V_321 -> V_317 ;
F_224 () ;
V_321 -> V_317 = NULL ;
F_225 ( V_317 ) ;
}
V_13 -> V_136 = NULL ;
}
void F_145 ( struct V_12 * V_13 , int V_322 )
{
switch ( V_322 ) {
case 0 :
F_226 ( V_323 , & V_13 -> V_187 ) ;
F_227 () ;
F_226 ( V_324 , & V_13 -> V_187 ) ;
break;
case 1 :
F_228 ( V_323 , & V_13 -> V_187 ) ;
F_227 () ;
F_226 ( V_324 , & V_13 -> V_187 ) ;
break;
case 2 :
F_228 ( V_324 , & V_13 -> V_187 ) ;
F_227 () ;
F_228 ( V_323 , & V_13 -> V_187 ) ;
break;
}
}
static int F_229 ( unsigned long V_325 )
{
int V_21 ;
V_21 = V_325 & V_326 ;
return ( V_21 >= 2 ) ? 2 : V_21 ;
}
int F_146 ( struct V_12 * V_13 )
{
return F_229 ( V_13 -> V_187 ) ;
}
static void F_230 ( struct V_106 * V_106 )
{
struct V_327 * V_328 ;
V_328 = V_106 -> V_122 . V_123 -> V_124 -> V_329 ;
F_231 ( V_328 ) ;
V_328 -> V_330 ++ ;
V_328 -> V_331 -- ;
while ( ( V_328 -> V_330 > 1 ) && ( ! F_232 ( V_14 ) ) ) {
F_233 ( & V_328 -> V_332 ) ;
F_234 ( & V_328 -> V_333 , V_334 , V_335 ) ;
F_235 ( V_328 ) ;
}
V_328 -> V_330 -- ;
V_328 -> V_331 ++ ;
F_236 ( V_328 ) ;
}
static int F_237 ( struct V_336 * V_337 , struct V_203 * V_265 )
{
struct V_106 * V_338 , * V_339 ;
struct V_174 * V_175 ;
struct V_340 * V_341 = (struct V_340 * ) V_337 -> V_342 ;
struct V_171 * V_343 = V_14 -> V_172 ;
V_339 = F_238 ( 0 ) ;
if ( F_48 ( V_339 ) )
return F_189 ( V_339 ) ;
V_338 = F_239 ( V_339 , 0 ) ;
if ( F_48 ( V_338 ) ) {
F_240 ( V_339 ) ;
return F_189 ( V_338 ) ;
}
V_341 -> V_106 = V_339 ;
F_129 ( 0 ) ;
F_241 ( 0 , V_338 ) ;
F_123 ( & V_343 -> V_176 ) ;
V_175 = F_128 ( V_343 ) ;
F_242 ( 0 , V_175 -> V_344 ) ;
F_243 ( 0 , V_175 -> V_180 ) ;
F_125 ( & V_343 -> V_176 ) ;
V_14 -> signal -> V_27 [ V_298 ] = (struct V_26 ) { 1 , 1 } ;
return 0 ;
}
void F_244 ( long V_287 , int V_301 , struct V_237 * V_238 )
{
struct V_136 V_136 ;
struct V_267 V_268 ;
struct V_12 * V_13 = V_14 -> V_13 ;
struct V_1 * V_266 ;
const struct V_203 * V_345 ;
struct V_203 * V_203 ;
int V_185 = 0 ;
int V_346 = 0 ;
int V_290 ;
static T_10 V_347 = F_245 ( 0 ) ;
struct V_340 V_348 = {
. V_287 = V_287 ,
. V_238 = V_238 ,
. V_349 = V_26 ( V_298 ) ,
. V_325 = V_13 -> V_187 ,
} ;
F_246 ( V_287 ) ;
V_266 = V_13 -> V_266 ;
if ( ! V_266 || ! V_266 -> V_350 )
goto V_319;
if ( ! F_229 ( V_348 . V_325 ) )
goto V_319;
V_203 = F_247 () ;
if ( ! V_203 )
goto V_319;
if ( F_229 ( V_348 . V_325 ) == 2 ) {
V_346 = V_351 ;
V_203 -> V_352 = 0 ;
}
V_185 = F_219 ( V_301 , & V_136 ) ;
if ( V_185 < 0 )
goto V_353;
V_345 = F_248 ( V_203 ) ;
F_249 ( V_354 ) ;
V_290 = F_207 ( & V_268 , V_287 ) ;
if ( V_290 ) {
int V_355 ;
char * * V_356 ;
if ( V_290 < 0 ) {
F_250 ( V_357 L_9 ) ;
F_250 ( V_357 L_10 ) ;
goto V_358;
}
if ( V_348 . V_349 == 1 ) {
F_250 ( V_357
L_11 ,
F_208 ( V_14 ) , V_14 -> V_183 ) ;
F_250 ( V_357 L_10 ) ;
goto V_359;
}
V_348 . V_349 = V_360 ;
V_355 = F_199 ( & V_347 ) ;
if ( V_361 && ( V_361 < V_355 ) ) {
F_250 ( V_357 L_12 ,
F_208 ( V_14 ) , V_14 -> V_183 ) ;
F_250 ( V_357 L_13 ) ;
goto V_362;
}
V_356 = F_251 ( V_36 , V_268 . V_270 + 1 , NULL ) ;
if ( ! V_356 ) {
F_250 ( V_357 L_14 ,
V_363 ) ;
goto V_362;
}
V_185 = F_252 ( V_356 [ 0 ] , V_356 ,
NULL , V_364 , F_237 ,
NULL , & V_348 ) ;
F_253 ( V_356 ) ;
if ( V_185 ) {
F_250 ( V_365 L_15 ,
V_268 . V_270 ) ;
goto V_366;
}
} else {
struct V_222 * V_222 ;
if ( V_348 . V_349 < V_266 -> V_367 )
goto V_359;
V_348 . V_106 = F_254 ( V_268 . V_270 ,
V_368 | 2 | V_369 | V_111 | V_346 ,
0600 ) ;
if ( F_48 ( V_348 . V_106 ) )
goto V_359;
V_222 = V_348 . V_106 -> V_122 . V_123 -> V_124 ;
if ( V_222 -> V_370 > 1 )
goto V_366;
if ( F_255 ( V_348 . V_106 -> V_122 . V_123 ) )
goto V_366;
if ( ! F_77 ( V_222 -> V_125 ) )
goto V_366;
if ( V_222 -> V_229 != F_256 () )
goto V_366;
if ( ! V_348 . V_106 -> V_223 || ! V_348 . V_106 -> V_223 -> V_20 )
goto V_366;
if ( F_257 ( V_348 . V_106 -> V_122 . V_123 , 0 , 0 , V_348 . V_106 ) )
goto V_366;
}
V_185 = V_266 -> V_350 ( & V_348 ) ;
if ( V_185 )
V_14 -> signal -> V_303 |= 0x80 ;
if ( V_290 && V_361 )
F_230 ( V_348 . V_106 ) ;
V_366:
if ( V_348 . V_106 )
F_258 ( V_348 . V_106 , NULL ) ;
V_362:
if ( V_290 )
F_259 ( & V_347 ) ;
V_359:
F_155 ( V_268 . V_270 ) ;
V_358:
F_223 ( V_13 ) ;
F_260 ( V_345 ) ;
V_353:
F_261 ( V_203 ) ;
V_319:
return;
}
int F_262 ( struct V_106 * V_106 , const void * V_129 , int V_56 )
{
return F_263 ( V_371 , V_129 , V_56 ) && V_106 -> V_223 -> V_20 ( V_106 , V_129 , V_56 , & V_106 -> V_372 ) == V_56 ;
}
int F_264 ( struct V_106 * V_106 , T_4 V_373 )
{
int V_21 = 1 ;
if ( V_106 -> V_223 -> V_374 && V_106 -> V_223 -> V_374 != V_375 ) {
if ( V_106 -> V_223 -> V_374 ( V_106 , V_373 , V_376 ) < 0 )
return 0 ;
} else {
char * V_182 = ( char * ) F_265 ( V_36 ) ;
if ( ! V_182 )
return 0 ;
while ( V_373 > 0 ) {
unsigned long V_377 = V_373 ;
if ( V_377 > V_28 )
V_377 = V_28 ;
if ( ! F_262 ( V_106 , V_182 , V_377 ) ) {
V_21 = 0 ;
break;
}
V_373 -= V_377 ;
}
F_266 ( ( unsigned long ) V_182 ) ;
}
return V_21 ;
}
