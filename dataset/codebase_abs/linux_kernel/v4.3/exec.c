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
bool F_12 ( const struct V_9 * V_9 )
{
return ( V_9 -> V_10 -> V_11 & V_12 ) ||
( V_9 -> V_10 -> V_13 -> V_14 & V_15 ) ;
}
static void F_13 ( struct V_16 * V_17 , unsigned long V_18 )
{
struct V_19 * V_20 = V_21 -> V_20 ;
long V_22 = ( long ) ( V_18 - V_17 -> V_23 ) ;
if ( ! V_20 || ! V_22 )
return;
V_17 -> V_23 = V_18 ;
F_14 ( V_20 , V_24 , V_22 ) ;
}
static struct V_25 * F_15 ( struct V_16 * V_17 , unsigned long V_26 ,
int V_27 )
{
struct V_25 * V_25 ;
int V_28 ;
#ifdef F_16
if ( V_27 ) {
V_28 = F_17 ( V_17 -> V_29 , V_26 ) ;
if ( V_28 < 0 )
return NULL ;
}
#endif
V_28 = F_18 ( V_21 , V_17 -> V_20 , V_26 ,
1 , V_27 , 1 , & V_25 , NULL ) ;
if ( V_28 <= 0 )
return NULL ;
if ( V_27 ) {
unsigned long V_30 = V_17 -> V_29 -> V_31 - V_17 -> V_29 -> V_32 ;
struct V_33 * V_34 ;
F_13 ( V_17 , V_30 / V_35 ) ;
if ( V_30 <= V_36 )
return V_25 ;
V_34 = V_21 -> signal -> V_34 ;
if ( V_30 > F_19 ( V_34 [ V_37 ] . V_38 ) / 4 ) {
F_20 ( V_25 ) ;
return NULL ;
}
}
return V_25 ;
}
static void F_21 ( struct V_25 * V_25 )
{
F_20 ( V_25 ) ;
}
static void F_22 ( struct V_16 * V_17 , int V_39 )
{
}
static void F_23 ( struct V_16 * V_17 )
{
}
static void F_24 ( struct V_16 * V_17 , unsigned long V_26 ,
struct V_25 * V_25 )
{
F_25 ( V_17 -> V_29 , V_26 , F_26 ( V_25 ) ) ;
}
static int F_27 ( struct V_16 * V_17 )
{
int V_40 ;
struct V_41 * V_29 = NULL ;
struct V_19 * V_20 = V_17 -> V_20 ;
V_17 -> V_29 = V_29 = F_28 ( V_42 , V_43 ) ;
if ( ! V_29 )
return - V_44 ;
F_29 ( & V_20 -> V_45 ) ;
V_29 -> V_46 = V_20 ;
F_30 ( V_47 & V_48 ) ;
V_29 -> V_31 = V_49 ;
V_29 -> V_32 = V_29 -> V_31 - V_35 ;
V_29 -> V_50 = V_51 | V_47 | V_48 ;
V_29 -> V_52 = F_31 ( V_29 -> V_50 ) ;
F_32 ( & V_29 -> V_53 ) ;
V_40 = F_33 ( V_20 , V_29 ) ;
if ( V_40 )
goto V_40;
V_20 -> V_54 = V_20 -> V_55 = 1 ;
F_34 ( V_20 , V_29 ) ;
F_35 ( & V_20 -> V_45 ) ;
V_17 -> V_56 = V_29 -> V_31 - sizeof( void * ) ;
return 0 ;
V_40:
F_35 ( & V_20 -> V_45 ) ;
V_17 -> V_29 = NULL ;
F_36 ( V_42 , V_29 ) ;
return V_40 ;
}
static bool F_37 ( struct V_16 * V_17 , long V_57 )
{
return V_57 <= V_58 ;
}
static inline void F_13 ( struct V_16 * V_17 , unsigned long V_18 )
{
}
static struct V_25 * F_15 ( struct V_16 * V_17 , unsigned long V_26 ,
int V_27 )
{
struct V_25 * V_25 ;
V_25 = V_17 -> V_25 [ V_26 / V_35 ] ;
if ( ! V_25 && V_27 ) {
V_25 = F_38 ( V_59 | V_60 ) ;
if ( ! V_25 )
return NULL ;
V_17 -> V_25 [ V_26 / V_35 ] = V_25 ;
}
return V_25 ;
}
static void F_21 ( struct V_25 * V_25 )
{
}
static void F_22 ( struct V_16 * V_17 , int V_39 )
{
if ( V_17 -> V_25 [ V_39 ] ) {
F_39 ( V_17 -> V_25 [ V_39 ] ) ;
V_17 -> V_25 [ V_39 ] = NULL ;
}
}
static void F_23 ( struct V_16 * V_17 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_61 ; V_39 ++ )
F_22 ( V_17 , V_39 ) ;
}
static void F_24 ( struct V_16 * V_17 , unsigned long V_26 ,
struct V_25 * V_25 )
{
}
static int F_27 ( struct V_16 * V_17 )
{
V_17 -> V_56 = V_35 * V_61 - sizeof( void * ) ;
return 0 ;
}
static bool F_37 ( struct V_16 * V_17 , long V_57 )
{
return V_57 <= V_17 -> V_56 ;
}
static int F_40 ( struct V_16 * V_17 )
{
int V_40 ;
struct V_19 * V_20 = NULL ;
V_17 -> V_20 = V_20 = F_41 () ;
V_40 = - V_44 ;
if ( ! V_20 )
goto V_40;
V_40 = F_27 ( V_17 ) ;
if ( V_40 )
goto V_40;
return 0 ;
V_40:
if ( V_20 ) {
V_17 -> V_20 = NULL ;
F_42 ( V_20 ) ;
}
return V_40 ;
}
static const char T_1 * F_43 ( struct V_62 V_63 , int V_64 )
{
const char T_1 * V_65 ;
#ifdef F_44
if ( F_45 ( V_63 . V_66 ) ) {
T_2 V_67 ;
if ( F_46 ( V_67 , V_63 . V_68 . V_67 + V_64 ) )
return F_47 ( - V_69 ) ;
return F_48 ( V_67 ) ;
}
#endif
if ( F_46 ( V_65 , V_63 . V_68 . V_65 + V_64 ) )
return F_47 ( - V_69 ) ;
return V_65 ;
}
static int F_49 ( struct V_62 V_63 , int V_70 )
{
int V_39 = 0 ;
if ( V_63 . V_68 . V_65 != NULL ) {
for (; ; ) {
const char T_1 * V_56 = F_43 ( V_63 , V_39 ) ;
if ( ! V_56 )
break;
if ( F_50 ( V_56 ) )
return - V_69 ;
if ( V_39 >= V_70 )
return - V_71 ;
++ V_39 ;
if ( F_51 ( V_21 ) )
return - V_72 ;
F_52 () ;
}
}
return V_39 ;
}
static int F_53 ( int V_73 , struct V_62 V_63 ,
struct V_16 * V_17 )
{
struct V_25 * V_74 = NULL ;
char * V_75 = NULL ;
unsigned long V_76 = 0 ;
int V_28 ;
while ( V_73 -- > 0 ) {
const char T_1 * V_77 ;
int V_57 ;
unsigned long V_26 ;
V_28 = - V_69 ;
V_77 = F_43 ( V_63 , V_73 ) ;
if ( F_50 ( V_77 ) )
goto V_78;
V_57 = F_54 ( V_77 , V_58 ) ;
if ( ! V_57 )
goto V_78;
V_28 = - V_71 ;
if ( ! F_37 ( V_17 , V_57 ) )
goto V_78;
V_26 = V_17 -> V_56 ;
V_77 += V_57 ;
V_17 -> V_56 -= V_57 ;
while ( V_57 > 0 ) {
int V_79 , V_80 ;
if ( F_51 ( V_21 ) ) {
V_28 = - V_72 ;
goto V_78;
}
F_52 () ;
V_79 = V_26 % V_35 ;
if ( V_79 == 0 )
V_79 = V_35 ;
V_80 = V_79 ;
if ( V_80 > V_57 )
V_80 = V_57 ;
V_79 -= V_80 ;
V_26 -= V_80 ;
V_77 -= V_80 ;
V_57 -= V_80 ;
if ( ! V_74 || V_76 != ( V_26 & V_81 ) ) {
struct V_25 * V_25 ;
V_25 = F_15 ( V_17 , V_26 , 1 ) ;
if ( ! V_25 ) {
V_28 = - V_71 ;
goto V_78;
}
if ( V_74 ) {
F_55 ( V_74 ) ;
F_56 ( V_74 ) ;
F_21 ( V_74 ) ;
}
V_74 = V_25 ;
V_75 = F_57 ( V_74 ) ;
V_76 = V_26 & V_81 ;
F_24 ( V_17 , V_76 , V_74 ) ;
}
if ( F_58 ( V_75 + V_79 , V_77 , V_80 ) ) {
V_28 = - V_69 ;
goto V_78;
}
}
}
V_28 = 0 ;
V_78:
if ( V_74 ) {
F_55 ( V_74 ) ;
F_56 ( V_74 ) ;
F_21 ( V_74 ) ;
}
return V_28 ;
}
int F_59 ( int V_73 , const char * const * V_82 ,
struct V_16 * V_17 )
{
int V_83 ;
T_3 V_84 = F_60 () ;
struct V_62 V_63 = {
. V_68 . V_65 = ( const char T_1 * const T_1 * ) V_82 ,
} ;
F_61 ( V_85 ) ;
V_83 = F_53 ( V_73 , V_63 , V_17 ) ;
F_61 ( V_84 ) ;
return V_83 ;
}
static int F_62 ( struct V_41 * V_29 , unsigned long V_86 )
{
struct V_19 * V_20 = V_29 -> V_46 ;
unsigned long V_87 = V_29 -> V_32 ;
unsigned long V_88 = V_29 -> V_31 ;
unsigned long V_89 = V_88 - V_87 ;
unsigned long V_90 = V_87 - V_86 ;
unsigned long V_91 = V_88 - V_86 ;
struct V_92 V_93 ;
F_2 ( V_90 > V_91 ) ;
if ( V_29 != F_63 ( V_20 , V_90 ) )
return - V_69 ;
if ( F_64 ( V_29 , V_90 , V_88 , V_29 -> V_94 , NULL ) )
return - V_44 ;
if ( V_89 != F_65 ( V_29 , V_87 ,
V_29 , V_90 , V_89 , false ) )
return - V_44 ;
F_66 () ;
F_67 ( & V_93 , V_20 , V_87 , V_88 ) ;
if ( V_91 > V_87 ) {
F_68 ( & V_93 , V_91 , V_88 , V_91 ,
V_29 -> V_95 ? V_29 -> V_95 -> V_32 : V_96 ) ;
} else {
F_68 ( & V_93 , V_87 , V_88 , V_91 ,
V_29 -> V_95 ? V_29 -> V_95 -> V_32 : V_96 ) ;
}
F_69 ( & V_93 , V_87 , V_88 ) ;
F_64 ( V_29 , V_90 , V_91 , V_29 -> V_94 , NULL ) ;
return 0 ;
}
int F_70 ( struct V_16 * V_17 ,
unsigned long V_97 ,
int V_98 )
{
unsigned long V_28 ;
unsigned long V_99 ;
struct V_19 * V_20 = V_21 -> V_20 ;
struct V_41 * V_29 = V_17 -> V_29 ;
struct V_41 * V_100 = NULL ;
unsigned long V_50 ;
unsigned long V_101 ;
unsigned long V_102 ;
unsigned long V_103 ;
unsigned long V_104 ;
#ifdef F_16
V_101 = F_71 ( V_37 ) ;
if ( V_101 > V_105 )
V_101 = V_105 ;
V_101 += ( V_106 << V_107 ) ;
if ( V_29 -> V_31 - V_29 -> V_32 > V_101 )
return - V_44 ;
V_101 = F_72 ( V_97 - V_101 ) ;
V_99 = V_29 -> V_32 - V_101 ;
V_20 -> V_108 = V_17 -> V_56 - V_99 ;
V_17 -> V_56 = V_29 -> V_31 - V_99 ;
#else
V_97 = F_73 ( V_97 ) ;
V_97 = F_72 ( V_97 ) ;
if ( F_45 ( V_97 < V_109 ) ||
F_45 ( V_29 -> V_31 - V_29 -> V_32 >= V_97 - V_109 ) )
return - V_44 ;
V_99 = V_29 -> V_31 - V_97 ;
V_17 -> V_56 -= V_99 ;
V_20 -> V_108 = V_17 -> V_56 ;
#endif
if ( V_17 -> V_110 )
V_17 -> V_110 -= V_99 ;
V_17 -> V_111 -= V_99 ;
F_29 ( & V_20 -> V_45 ) ;
V_50 = V_47 ;
if ( F_45 ( V_98 == V_112 ) )
V_50 |= V_113 ;
else if ( V_98 == V_114 )
V_50 &= ~ V_113 ;
V_50 |= V_20 -> V_115 ;
V_50 |= V_48 ;
V_28 = F_74 ( V_29 , & V_100 , V_29 -> V_32 , V_29 -> V_31 ,
V_50 ) ;
if ( V_28 )
goto V_116;
F_2 ( V_100 != V_29 ) ;
if ( V_99 ) {
V_28 = F_62 ( V_29 , V_99 ) ;
if ( V_28 )
goto V_116;
}
V_29 -> V_50 &= ~ V_48 ;
V_103 = 131072UL ;
V_102 = V_29 -> V_31 - V_29 -> V_32 ;
V_104 = V_33 ( V_37 ) & V_81 ;
#ifdef F_16
if ( V_102 + V_103 > V_104 )
V_101 = V_29 -> V_32 + V_104 ;
else
V_101 = V_29 -> V_31 + V_103 ;
#else
if ( V_102 + V_103 > V_104 )
V_101 = V_29 -> V_31 - V_104 ;
else
V_101 = V_29 -> V_32 - V_103 ;
#endif
V_21 -> V_20 -> V_117 = V_17 -> V_56 ;
V_28 = F_75 ( V_29 , V_101 ) ;
if ( V_28 )
V_28 = - V_69 ;
V_116:
F_35 ( & V_20 -> V_45 ) ;
return V_28 ;
}
static struct V_118 * F_76 ( int V_119 , struct V_120 * V_121 , int V_122 )
{
struct V_118 * V_118 ;
int V_40 ;
struct V_123 V_124 = {
. V_125 = V_126 | V_127 | V_128 ,
. V_129 = V_130 | V_131 ,
. V_132 = V_133 ,
. V_134 = V_135 ,
} ;
if ( ( V_122 & ~ ( V_136 | V_137 ) ) != 0 )
return F_47 ( - V_138 ) ;
if ( V_122 & V_136 )
V_124 . V_134 &= ~ V_135 ;
if ( V_122 & V_137 )
V_124 . V_134 |= V_139 ;
V_118 = F_77 ( V_119 , V_121 , & V_124 ) ;
if ( F_50 ( V_118 ) )
goto V_78;
V_40 = - V_140 ;
if ( ! F_78 ( F_79 ( V_118 ) -> V_141 ) )
goto exit;
if ( F_12 ( & V_118 -> V_142 ) )
goto exit;
V_40 = F_80 ( V_118 ) ;
if ( V_40 )
goto exit;
if ( V_121 -> V_121 [ 0 ] != '\0' )
F_81 ( V_118 ) ;
V_78:
return V_118 ;
exit:
F_82 ( V_118 ) ;
return F_47 ( V_40 ) ;
}
struct V_118 * F_83 ( const char * V_121 )
{
struct V_120 * V_120 = F_84 ( V_121 ) ;
struct V_118 * V_143 = F_85 ( V_120 ) ;
if ( ! F_50 ( V_120 ) ) {
V_143 = F_76 ( V_144 , V_120 , 0 ) ;
F_86 ( V_120 ) ;
}
return V_143 ;
}
int F_87 ( struct V_118 * V_118 , T_4 V_79 ,
char * V_145 , unsigned long F_49 )
{
T_3 V_146 ;
T_4 V_26 = V_79 ;
int V_147 ;
V_146 = F_60 () ;
F_61 ( F_88 () ) ;
V_147 = F_89 ( V_118 , ( void T_1 * ) V_145 , F_49 , & V_26 ) ;
F_61 ( V_146 ) ;
return V_147 ;
}
T_5 F_90 ( struct V_118 * V_118 , unsigned long V_145 , T_4 V_26 , T_6 V_57 )
{
T_5 V_148 = F_89 ( V_118 , ( void T_1 * ) V_145 , V_57 , & V_26 ) ;
if ( V_148 > 0 )
F_91 ( V_145 , V_145 + V_57 ) ;
return V_148 ;
}
static int F_92 ( struct V_19 * V_20 )
{
struct V_149 * V_150 ;
struct V_19 * V_151 , * V_152 ;
V_150 = V_21 ;
V_151 = V_21 -> V_20 ;
F_93 ( V_150 , V_151 ) ;
if ( V_151 ) {
F_94 ( V_151 ) ;
F_95 ( & V_151 -> V_45 ) ;
if ( F_45 ( V_151 -> V_153 ) ) {
F_96 ( & V_151 -> V_45 ) ;
return - V_154 ;
}
}
F_97 ( V_150 ) ;
V_152 = V_150 -> V_152 ;
V_150 -> V_20 = V_20 ;
V_150 -> V_152 = V_20 ;
F_98 ( V_152 , V_20 ) ;
V_150 -> V_20 -> V_155 = 0 ;
F_99 ( V_150 ) ;
F_100 ( V_150 ) ;
if ( V_151 ) {
F_96 ( & V_151 -> V_45 ) ;
F_2 ( V_152 != V_151 ) ;
F_101 ( & V_150 -> signal -> V_156 , V_151 ) ;
F_102 ( V_151 ) ;
F_103 ( V_151 ) ;
return 0 ;
}
F_42 ( V_152 ) ;
return 0 ;
}
static int F_104 ( struct V_149 * V_150 )
{
struct V_157 * V_158 = V_150 -> signal ;
struct V_159 * V_160 = V_150 -> V_161 ;
T_7 * V_162 = & V_160 -> V_163 ;
if ( F_105 ( V_150 ) )
goto V_164;
F_106 ( V_162 ) ;
if ( F_107 ( V_158 ) ) {
F_108 ( V_162 ) ;
return - V_165 ;
}
V_158 -> V_166 = V_150 ;
V_158 -> V_167 = F_109 ( V_150 ) ;
if ( ! F_110 ( V_150 ) )
V_158 -> V_167 -- ;
while ( V_158 -> V_167 ) {
F_111 ( V_168 ) ;
F_108 ( V_162 ) ;
F_112 () ;
if ( F_45 ( F_113 ( V_150 ) ) )
goto V_169;
F_106 ( V_162 ) ;
}
F_108 ( V_162 ) ;
if ( ! F_110 ( V_150 ) ) {
struct V_149 * V_170 = V_150 -> V_171 ;
for (; ; ) {
F_114 ( V_150 ) ;
F_115 ( & V_172 ) ;
V_158 -> V_167 = - 1 ;
if ( F_116 ( V_170 -> V_173 ) )
break;
F_111 ( V_168 ) ;
F_117 ( & V_172 ) ;
F_118 ( V_150 ) ;
F_112 () ;
if ( F_45 ( F_113 ( V_150 ) ) )
goto V_169;
}
V_150 -> V_174 = V_170 -> V_174 ;
V_150 -> V_175 = V_170 -> V_175 ;
F_2 ( ! F_119 ( V_170 , V_150 ) ) ;
F_2 ( F_120 ( V_150 ) ) ;
V_150 -> V_176 = V_170 -> V_176 ;
F_121 ( V_150 , V_177 , F_122 ( V_170 ) ) ;
F_123 ( V_170 , V_150 , V_178 ) ;
F_123 ( V_170 , V_150 , V_179 ) ;
F_124 ( & V_170 -> V_180 , & V_150 -> V_180 ) ;
F_125 ( & V_170 -> V_181 , & V_150 -> V_181 ) ;
V_150 -> V_171 = V_150 ;
V_170 -> V_171 = V_150 ;
V_150 -> V_182 = V_183 ;
V_170 -> V_182 = - 1 ;
F_2 ( V_170 -> V_173 != V_184 ) ;
V_170 -> V_173 = V_185 ;
if ( F_45 ( V_170 -> V_186 ) )
F_126 ( V_170 , V_170 -> V_187 ) ;
F_117 ( & V_172 ) ;
F_118 ( V_150 ) ;
F_127 ( V_170 ) ;
}
V_158 -> V_166 = NULL ;
V_158 -> V_167 = 0 ;
V_164:
V_150 -> V_182 = V_183 ;
F_128 ( V_158 ) ;
F_129 () ;
if ( F_130 ( & V_160 -> F_49 ) != 1 ) {
struct V_159 * V_188 ;
V_188 = F_131 ( V_189 , V_43 ) ;
if ( ! V_188 )
return - V_44 ;
F_132 ( & V_188 -> F_49 , 1 ) ;
memcpy ( V_188 -> V_190 , V_160 -> V_190 ,
sizeof( V_188 -> V_190 ) ) ;
F_115 ( & V_172 ) ;
F_133 ( & V_160 -> V_163 ) ;
F_134 ( V_150 -> V_161 , V_188 ) ;
F_135 ( & V_160 -> V_163 ) ;
F_117 ( & V_172 ) ;
F_136 ( V_160 ) ;
}
F_2 ( ! F_110 ( V_150 ) ) ;
return 0 ;
V_169:
F_137 ( & V_172 ) ;
V_158 -> V_166 = NULL ;
V_158 -> V_167 = 0 ;
F_138 ( & V_172 ) ;
return - V_165 ;
}
char * F_139 ( char * V_191 , struct V_149 * V_150 )
{
F_97 ( V_150 ) ;
strncpy ( V_191 , V_150 -> V_192 , sizeof( V_150 -> V_192 ) ) ;
F_100 ( V_150 ) ;
return V_191 ;
}
void F_140 ( struct V_149 * V_150 , const char * V_191 , bool V_111 )
{
F_97 ( V_150 ) ;
F_141 ( V_150 , V_191 ) ;
F_142 ( V_150 -> V_192 , V_191 , sizeof( V_150 -> V_192 ) ) ;
F_100 ( V_150 ) ;
F_143 ( V_150 , V_111 ) ;
}
int F_144 ( struct V_16 * V_17 )
{
int V_193 ;
V_193 = F_104 ( V_21 ) ;
if ( V_193 )
goto V_78;
F_145 ( V_17 -> V_20 , V_17 -> V_118 ) ;
F_13 ( V_17 , 0 ) ;
V_193 = F_92 ( V_17 -> V_20 ) ;
if ( V_193 )
goto V_78;
V_17 -> V_20 = NULL ;
F_61 ( V_194 ) ;
V_21 -> V_122 &= ~ ( V_195 | V_196 | V_197 |
V_198 | V_199 ) ;
F_146 () ;
V_21 -> V_200 &= ~ V_17 -> V_201 ;
return 0 ;
V_78:
return V_193 ;
}
void F_147 ( struct V_16 * V_17 , struct V_118 * V_118 )
{
if ( F_148 ( F_79 ( V_118 ) , V_202 ) < 0 )
V_17 -> V_203 |= V_204 ;
}
void F_149 ( struct V_16 * V_17 )
{
F_150 ( V_21 -> V_20 ) ;
V_21 -> V_205 = V_21 -> V_206 = 0 ;
if ( F_151 ( F_152 () , F_153 () ) && F_154 ( F_155 () , F_156 () ) )
F_157 ( V_21 -> V_20 , V_207 ) ;
else
F_157 ( V_21 -> V_20 , V_208 ) ;
F_158 () ;
F_140 ( V_21 , F_159 ( V_17 -> V_120 ) , true ) ;
V_21 -> V_20 -> V_209 = V_210 ;
if ( ! F_151 ( V_17 -> V_211 -> V_212 , F_152 () ) ||
! F_154 ( V_17 -> V_211 -> V_213 , F_155 () ) ) {
V_21 -> V_214 = 0 ;
} else {
F_147 ( V_17 , V_17 -> V_118 ) ;
if ( V_17 -> V_203 & V_204 )
F_157 ( V_21 -> V_20 , V_208 ) ;
}
V_21 -> V_215 ++ ;
F_160 ( V_21 , 0 ) ;
F_161 ( V_21 -> V_216 ) ;
}
int F_162 ( struct V_16 * V_17 )
{
if ( F_163 ( & V_21 -> signal -> V_217 ) )
return - V_218 ;
V_17 -> V_211 = F_164 () ;
if ( F_116 ( V_17 -> V_211 ) )
return 0 ;
F_165 ( & V_21 -> signal -> V_217 ) ;
return - V_44 ;
}
static void F_166 ( struct V_16 * V_17 )
{
F_23 ( V_17 ) ;
if ( V_17 -> V_211 ) {
F_165 ( & V_21 -> signal -> V_217 ) ;
F_167 ( V_17 -> V_211 ) ;
}
if ( V_17 -> V_118 ) {
F_168 ( V_17 -> V_118 ) ;
F_82 ( V_17 -> V_118 ) ;
}
if ( V_17 -> V_219 != V_17 -> V_120 )
F_169 ( V_17 -> V_219 ) ;
F_169 ( V_17 ) ;
}
int F_170 ( char * V_219 , struct V_16 * V_17 )
{
if ( V_17 -> V_219 != V_17 -> V_120 )
F_169 ( V_17 -> V_219 ) ;
V_17 -> V_219 = F_171 ( V_219 , V_43 ) ;
if ( ! V_17 -> V_219 )
return - V_44 ;
return 0 ;
}
void F_172 ( struct V_16 * V_17 )
{
F_173 ( V_17 ) ;
F_174 ( V_17 -> V_211 ) ;
V_17 -> V_211 = NULL ;
if ( F_175 ( V_21 -> V_20 ) != V_207 )
F_176 ( V_21 ) ;
F_177 ( V_17 ) ;
F_165 ( & V_21 -> signal -> V_217 ) ;
}
static void F_178 ( struct V_16 * V_17 )
{
struct V_149 * V_56 = V_21 , * V_220 ;
unsigned V_221 ;
if ( V_56 -> V_186 ) {
if ( V_56 -> V_186 & V_222 )
V_17 -> V_223 |= V_224 ;
else
V_17 -> V_223 |= V_225 ;
}
if ( F_179 ( V_21 ) )
V_17 -> V_223 |= V_226 ;
V_220 = V_56 ;
V_221 = 1 ;
F_133 ( & V_56 -> V_227 -> V_162 ) ;
F_180 () ;
F_181 (p, t) {
if ( V_220 -> V_227 == V_56 -> V_227 )
V_221 ++ ;
}
F_182 () ;
if ( V_56 -> V_227 -> V_228 > V_221 )
V_17 -> V_223 |= V_229 ;
else
V_56 -> V_227 -> V_230 = 1 ;
F_135 ( & V_56 -> V_227 -> V_162 ) ;
}
static void F_183 ( struct V_16 * V_17 )
{
struct V_231 * V_231 ;
unsigned int V_232 ;
T_8 V_212 ;
T_9 V_213 ;
V_17 -> V_211 -> V_233 = F_152 () ;
V_17 -> V_211 -> V_234 = F_155 () ;
if ( V_17 -> V_118 -> V_142 . V_10 -> V_11 & V_235 )
return;
if ( F_179 ( V_21 ) )
return;
V_231 = F_79 ( V_17 -> V_118 ) ;
V_232 = F_184 ( V_231 -> V_141 ) ;
if ( ! ( V_232 & ( V_236 | V_237 ) ) )
return;
F_185 ( & V_231 -> V_238 ) ;
V_232 = V_231 -> V_141 ;
V_212 = V_231 -> V_239 ;
V_213 = V_231 -> V_240 ;
F_165 ( & V_231 -> V_238 ) ;
if ( ! F_186 ( V_17 -> V_211 -> V_241 , V_212 ) ||
! F_187 ( V_17 -> V_211 -> V_241 , V_213 ) )
return;
if ( V_232 & V_236 ) {
V_17 -> V_201 |= V_242 ;
V_17 -> V_211 -> V_233 = V_212 ;
}
if ( ( V_232 & ( V_237 | V_243 ) ) == ( V_237 | V_243 ) ) {
V_17 -> V_201 |= V_242 ;
V_17 -> V_211 -> V_234 = V_213 ;
}
}
int F_188 ( struct V_16 * V_17 )
{
int V_193 ;
F_183 ( V_17 ) ;
V_193 = F_189 ( V_17 ) ;
if ( V_193 )
return V_193 ;
V_17 -> V_244 = 1 ;
memset ( V_17 -> V_191 , 0 , V_245 ) ;
return F_87 ( V_17 -> V_118 , 0 , V_17 -> V_191 , V_245 ) ;
}
int F_190 ( struct V_16 * V_17 )
{
int V_28 = 0 ;
unsigned long V_79 ;
char * V_75 ;
struct V_25 * V_25 ;
if ( ! V_17 -> V_73 )
return 0 ;
do {
V_79 = V_17 -> V_56 & ~ V_81 ;
V_25 = F_15 ( V_17 , V_17 -> V_56 , 0 ) ;
if ( ! V_25 ) {
V_28 = - V_69 ;
goto V_78;
}
V_75 = F_191 ( V_25 ) ;
for (; V_79 < V_35 && V_75 [ V_79 ] ;
V_79 ++ , V_17 -> V_56 ++ )
;
F_192 ( V_75 ) ;
F_21 ( V_25 ) ;
if ( V_79 == V_35 )
F_22 ( V_17 , ( V_17 -> V_56 >> V_107 ) - 1 ) ;
} while ( V_79 == V_35 );
V_17 -> V_56 ++ ;
V_17 -> V_73 -- ;
V_28 = 0 ;
V_78:
return V_28 ;
}
int F_193 ( struct V_16 * V_17 )
{
bool V_246 = F_194 ( V_247 ) ;
struct V_1 * V_2 ;
int V_193 ;
if ( V_17 -> V_248 > 5 )
return - V_249 ;
V_193 = F_195 ( V_17 ) ;
if ( V_193 )
return V_193 ;
V_193 = - V_250 ;
V_251:
F_137 ( & V_5 ) ;
F_196 (fmt, &formats, lh) {
if ( ! F_197 ( V_2 -> V_8 ) )
continue;
F_138 ( & V_5 ) ;
V_17 -> V_248 ++ ;
V_193 = V_2 -> V_4 ( V_17 ) ;
F_137 ( & V_5 ) ;
F_10 ( V_2 ) ;
V_17 -> V_248 -- ;
if ( V_193 < 0 && ! V_17 -> V_20 ) {
F_138 ( & V_5 ) ;
F_198 ( V_252 , V_21 ) ;
return V_193 ;
}
if ( V_193 != - V_253 || ! V_17 -> V_118 ) {
F_138 ( & V_5 ) ;
return V_193 ;
}
}
F_138 ( & V_5 ) ;
if ( V_246 ) {
if ( F_199 ( V_17 -> V_191 [ 0 ] ) && F_199 ( V_17 -> V_191 [ 1 ] ) &&
F_199 ( V_17 -> V_191 [ 2 ] ) && F_199 ( V_17 -> V_191 [ 3 ] ) )
return V_193 ;
if ( F_200 ( L_1 , * ( V_254 * ) ( V_17 -> V_191 + 2 ) ) < 0 )
return V_193 ;
V_246 = false ;
goto V_251;
}
return V_193 ;
}
static int F_201 ( struct V_16 * V_17 )
{
T_10 V_255 , V_256 ;
int V_28 ;
V_255 = V_21 -> V_176 ;
F_180 () ;
V_256 = F_202 ( V_21 , F_203 ( V_21 -> V_187 ) ) ;
F_182 () ;
V_28 = F_193 ( V_17 ) ;
if ( V_28 >= 0 ) {
F_204 ( V_17 ) ;
F_205 ( V_21 , V_255 , V_17 ) ;
F_206 ( V_257 , V_256 ) ;
F_207 ( V_21 ) ;
}
return V_28 ;
}
static int F_208 ( int V_119 , struct V_120 * V_120 ,
struct V_62 V_63 ,
struct V_62 V_258 ,
int V_122 )
{
char * V_259 = NULL ;
struct V_16 * V_17 ;
struct V_118 * V_118 ;
struct V_260 * V_261 ;
int V_193 ;
if ( F_50 ( V_120 ) )
return F_209 ( V_120 ) ;
if ( ( V_21 -> V_122 & V_262 ) &&
F_130 ( & F_210 () -> V_263 ) > V_33 ( V_264 ) ) {
V_193 = - V_165 ;
goto V_265;
}
V_21 -> V_122 &= ~ V_262 ;
V_193 = F_211 ( & V_261 ) ;
if ( V_193 )
goto V_265;
V_193 = - V_44 ;
V_17 = F_212 ( sizeof( * V_17 ) , V_43 ) ;
if ( ! V_17 )
goto V_266;
V_193 = F_162 ( V_17 ) ;
if ( V_193 )
goto V_267;
F_178 ( V_17 ) ;
V_21 -> V_268 = 1 ;
V_118 = F_76 ( V_119 , V_120 , V_122 ) ;
V_193 = F_209 ( V_118 ) ;
if ( F_50 ( V_118 ) )
goto V_269;
F_213 () ;
V_17 -> V_118 = V_118 ;
if ( V_119 == V_144 || V_120 -> V_121 [ 0 ] == '/' ) {
V_17 -> V_120 = V_120 -> V_121 ;
} else {
if ( V_120 -> V_121 [ 0 ] == '\0' )
V_259 = F_214 ( V_270 , L_2 , V_119 ) ;
else
V_259 = F_214 ( V_270 , L_3 ,
V_119 , V_120 -> V_121 ) ;
if ( ! V_259 ) {
V_193 = - V_44 ;
goto V_269;
}
if ( F_215 ( V_119 , F_216 ( V_21 -> V_216 -> V_271 ) ) )
V_17 -> V_203 |= V_272 ;
V_17 -> V_120 = V_259 ;
}
V_17 -> V_219 = V_17 -> V_120 ;
V_193 = F_40 ( V_17 ) ;
if ( V_193 )
goto V_269;
V_17 -> V_73 = F_49 ( V_63 , V_273 ) ;
if ( ( V_193 = V_17 -> V_73 ) < 0 )
goto V_78;
V_17 -> V_274 = F_49 ( V_258 , V_273 ) ;
if ( ( V_193 = V_17 -> V_274 ) < 0 )
goto V_78;
V_193 = F_188 ( V_17 ) ;
if ( V_193 < 0 )
goto V_78;
V_193 = F_59 ( 1 , & V_17 -> V_120 , V_17 ) ;
if ( V_193 < 0 )
goto V_78;
V_17 -> V_111 = V_17 -> V_56 ;
V_193 = F_53 ( V_17 -> V_274 , V_258 , V_17 ) ;
if ( V_193 < 0 )
goto V_78;
V_193 = F_53 ( V_17 -> V_73 , V_63 , V_17 ) ;
if ( V_193 < 0 )
goto V_78;
V_193 = F_201 ( V_17 ) ;
if ( V_193 < 0 )
goto V_78;
V_21 -> V_227 -> V_230 = 0 ;
V_21 -> V_268 = 0 ;
F_217 ( V_21 ) ;
F_218 ( V_21 ) ;
F_166 ( V_17 ) ;
F_169 ( V_259 ) ;
F_86 ( V_120 ) ;
if ( V_261 )
F_219 ( V_261 ) ;
return V_193 ;
V_78:
if ( V_17 -> V_20 ) {
F_13 ( V_17 , 0 ) ;
F_103 ( V_17 -> V_20 ) ;
}
V_269:
V_21 -> V_227 -> V_230 = 0 ;
V_21 -> V_268 = 0 ;
V_267:
F_166 ( V_17 ) ;
F_169 ( V_259 ) ;
V_266:
if ( V_261 )
F_220 ( V_261 ) ;
V_265:
F_86 ( V_120 ) ;
return V_193 ;
}
int F_221 ( struct V_120 * V_120 ,
const char T_1 * const T_1 * V_82 ,
const char T_1 * const T_1 * V_275 )
{
struct V_62 V_63 = { . V_68 . V_65 = V_82 } ;
struct V_62 V_258 = { . V_68 . V_65 = V_275 } ;
return F_208 ( V_144 , V_120 , V_63 , V_258 , 0 ) ;
}
int F_222 ( int V_119 , struct V_120 * V_120 ,
const char T_1 * const T_1 * V_82 ,
const char T_1 * const T_1 * V_275 ,
int V_122 )
{
struct V_62 V_63 = { . V_68 . V_65 = V_82 } ;
struct V_62 V_258 = { . V_68 . V_65 = V_275 } ;
return F_208 ( V_119 , V_120 , V_63 , V_258 , V_122 ) ;
}
static int F_223 ( struct V_120 * V_120 ,
const T_2 T_1 * V_82 ,
const T_2 T_1 * V_275 )
{
struct V_62 V_63 = {
. V_66 = true ,
. V_68 . V_67 = V_82 ,
} ;
struct V_62 V_258 = {
. V_66 = true ,
. V_68 . V_67 = V_275 ,
} ;
return F_208 ( V_144 , V_120 , V_63 , V_258 , 0 ) ;
}
static int F_224 ( int V_119 , struct V_120 * V_120 ,
const T_2 T_1 * V_82 ,
const T_2 T_1 * V_275 ,
int V_122 )
{
struct V_62 V_63 = {
. V_66 = true ,
. V_68 . V_67 = V_82 ,
} ;
struct V_62 V_258 = {
. V_66 = true ,
. V_68 . V_67 = V_275 ,
} ;
return F_208 ( V_119 , V_120 , V_63 , V_258 , V_122 ) ;
}
void F_225 ( struct V_1 * V_276 )
{
struct V_19 * V_20 = V_21 -> V_20 ;
if ( V_20 -> V_277 )
F_11 ( V_20 -> V_277 -> V_8 ) ;
V_20 -> V_277 = V_276 ;
if ( V_276 )
F_226 ( V_276 -> V_8 ) ;
}
void F_157 ( struct V_19 * V_20 , int V_278 )
{
unsigned long V_279 , V_276 ;
if ( F_3 ( ( unsigned ) V_278 > V_280 ) )
return;
do {
V_279 = F_19 ( V_20 -> V_122 ) ;
V_276 = ( V_279 & ~ V_281 ) | V_278 ;
} while ( F_227 ( & V_20 -> V_122 , V_279 , V_276 ) != V_279 );
}
