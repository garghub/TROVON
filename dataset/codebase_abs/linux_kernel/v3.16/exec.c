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
if ( V_94 > V_98 )
V_94 = V_98 ;
if ( V_22 -> V_24 - V_22 -> V_25 > V_94 )
return - V_37 ;
V_94 = F_71 ( V_90 - V_94 ) ;
V_92 = V_22 -> V_25 - V_94 ;
V_13 -> V_99 = V_10 -> V_49 - V_92 ;
V_10 -> V_49 = V_22 -> V_24 - V_92 ;
#else
V_90 = F_72 ( V_90 ) ;
V_90 = F_71 ( V_90 ) ;
if ( F_44 ( V_90 < V_100 ) ||
F_44 ( V_22 -> V_24 - V_22 -> V_25 >= V_90 - V_100 ) )
return - V_37 ;
V_92 = V_22 -> V_24 - V_90 ;
V_10 -> V_49 -= V_92 ;
V_13 -> V_99 = V_10 -> V_49 ;
#endif
if ( V_10 -> V_101 )
V_10 -> V_101 -= V_92 ;
V_10 -> V_102 -= V_92 ;
F_28 ( & V_13 -> V_38 ) ;
V_43 = V_40 ;
if ( F_44 ( V_91 == V_103 ) )
V_43 |= V_104 ;
else if ( V_91 == V_105 )
V_43 &= ~ V_104 ;
V_43 |= V_13 -> V_106 ;
V_43 |= V_41 ;
V_21 = F_73 ( V_22 , & V_93 , V_22 -> V_25 , V_22 -> V_24 ,
V_43 ) ;
if ( V_21 )
goto V_107;
F_2 ( V_93 != V_22 ) ;
if ( V_92 ) {
V_21 = F_61 ( V_22 , V_92 ) ;
if ( V_21 )
goto V_107;
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
V_14 -> V_13 -> V_108 = V_10 -> V_49 ;
V_21 = F_74 ( V_22 , V_94 ) ;
if ( V_21 )
V_21 = - V_62 ;
V_107:
F_33 ( & V_13 -> V_38 ) ;
return V_21 ;
}
static struct V_109 * F_75 ( struct V_110 * V_111 )
{
struct V_109 * V_109 ;
int V_33 ;
static const struct V_112 V_113 = {
. V_114 = V_115 | V_116 | V_117 ,
. V_118 = V_119 | V_120 ,
. V_121 = V_122 ,
. V_123 = V_124 ,
} ;
V_109 = F_76 ( V_125 , V_111 , & V_113 ) ;
if ( F_49 ( V_109 ) )
goto V_71;
V_33 = - V_126 ;
if ( ! F_77 ( F_78 ( V_109 ) -> V_127 ) )
goto exit;
if ( V_109 -> V_128 . V_129 -> V_130 & V_131 )
goto exit;
F_79 ( V_109 ) ;
V_33 = F_80 ( V_109 ) ;
if ( V_33 )
goto exit;
V_71:
return V_109 ;
exit:
F_81 ( V_109 ) ;
return F_46 ( V_33 ) ;
}
struct V_109 * F_82 ( const char * V_111 )
{
struct V_110 V_132 = { . V_111 = V_111 } ;
return F_75 ( & V_132 ) ;
}
int F_83 ( struct V_109 * V_109 , T_4 V_72 ,
char * V_133 , unsigned long F_48 )
{
T_3 V_134 ;
T_4 V_19 = V_72 ;
int V_135 ;
V_134 = F_59 () ;
F_60 ( F_84 () ) ;
V_135 = F_85 ( V_109 , ( void T_1 * ) V_133 , F_48 , & V_19 ) ;
F_60 ( V_134 ) ;
return V_135 ;
}
T_5 F_86 ( struct V_109 * V_109 , unsigned long V_133 , T_4 V_19 , T_6 V_50 )
{
T_5 V_136 = F_85 ( V_109 , ( void T_1 * ) V_133 , V_50 , & V_19 ) ;
if ( V_136 > 0 )
F_87 ( V_133 , V_133 + V_50 ) ;
return V_136 ;
}
static int F_88 ( struct V_12 * V_13 )
{
struct V_137 * V_138 ;
struct V_12 * V_139 , * V_140 ;
V_138 = V_14 ;
V_139 = V_14 -> V_13 ;
F_89 ( V_138 , V_139 ) ;
if ( V_139 ) {
F_90 ( V_139 ) ;
F_91 ( & V_139 -> V_38 ) ;
if ( F_44 ( V_139 -> V_141 ) ) {
F_92 ( & V_139 -> V_38 ) ;
return - V_142 ;
}
}
F_93 ( V_138 ) ;
V_140 = V_138 -> V_140 ;
V_138 -> V_13 = V_13 ;
V_138 -> V_140 = V_13 ;
F_94 ( V_140 , V_13 ) ;
V_138 -> V_13 -> V_143 = 0 ;
F_95 ( V_138 ) ;
F_96 ( V_138 ) ;
if ( V_139 ) {
F_92 ( & V_139 -> V_38 ) ;
F_2 ( V_140 != V_139 ) ;
F_97 ( & V_138 -> signal -> V_144 , V_139 ) ;
F_98 ( V_139 ) ;
F_99 ( V_139 ) ;
return 0 ;
}
F_41 ( V_140 ) ;
return 0 ;
}
static int F_100 ( struct V_137 * V_138 )
{
struct V_145 * V_146 = V_138 -> signal ;
struct V_147 * V_148 = V_138 -> V_149 ;
T_7 * V_150 = & V_148 -> V_151 ;
if ( F_101 ( V_138 ) )
goto V_152;
F_102 ( V_150 ) ;
if ( F_103 ( V_146 ) ) {
F_104 ( V_150 ) ;
return - V_153 ;
}
V_146 -> V_154 = V_138 ;
V_146 -> V_155 = F_105 ( V_138 ) ;
if ( ! F_106 ( V_138 ) )
V_146 -> V_155 -- ;
while ( V_146 -> V_155 ) {
F_107 ( V_156 ) ;
F_104 ( V_150 ) ;
F_108 () ;
if ( F_44 ( F_109 ( V_138 ) ) )
goto V_157;
F_102 ( V_150 ) ;
}
F_104 ( V_150 ) ;
if ( ! F_106 ( V_138 ) ) {
struct V_137 * V_158 = V_138 -> V_159 ;
V_146 -> V_155 = - 1 ;
for (; ; ) {
F_110 ( V_138 ) ;
F_111 ( & V_160 ) ;
if ( F_112 ( V_158 -> V_161 ) )
break;
F_107 ( V_156 ) ;
F_113 ( & V_160 ) ;
F_114 ( V_138 ) ;
F_108 () ;
if ( F_44 ( F_109 ( V_138 ) ) )
goto V_157;
}
V_138 -> V_162 = V_158 -> V_162 ;
V_138 -> V_163 = V_158 -> V_163 ;
F_2 ( ! F_115 ( V_158 , V_138 ) ) ;
F_2 ( F_116 ( V_138 ) ) ;
V_138 -> V_164 = V_158 -> V_164 ;
F_117 ( V_138 , V_165 , F_118 ( V_158 ) ) ;
F_119 ( V_158 , V_138 , V_166 ) ;
F_119 ( V_158 , V_138 , V_167 ) ;
F_120 ( & V_158 -> V_168 , & V_138 -> V_168 ) ;
F_121 ( & V_158 -> V_169 , & V_138 -> V_169 ) ;
V_138 -> V_159 = V_138 ;
V_158 -> V_159 = V_138 ;
V_138 -> V_170 = V_171 ;
V_158 -> V_170 = - 1 ;
F_2 ( V_158 -> V_161 != V_172 ) ;
V_158 -> V_161 = V_173 ;
if ( F_44 ( V_158 -> V_174 ) )
F_122 ( V_158 , V_158 -> V_175 ) ;
F_113 ( & V_160 ) ;
F_114 ( V_138 ) ;
F_123 ( V_158 ) ;
}
V_146 -> V_154 = NULL ;
V_146 -> V_155 = 0 ;
V_152:
V_138 -> V_170 = V_171 ;
F_124 ( V_146 ) ;
F_125 () ;
if ( F_126 ( & V_148 -> F_48 ) != 1 ) {
struct V_147 * V_176 ;
V_176 = F_127 ( V_177 , V_36 ) ;
if ( ! V_176 )
return - V_37 ;
F_128 ( & V_176 -> F_48 , 1 ) ;
memcpy ( V_176 -> V_178 , V_148 -> V_178 ,
sizeof( V_176 -> V_178 ) ) ;
F_111 ( & V_160 ) ;
F_129 ( & V_148 -> V_151 ) ;
F_130 ( V_138 -> V_149 , V_176 ) ;
F_131 ( & V_148 -> V_151 ) ;
F_113 ( & V_160 ) ;
F_132 ( V_148 ) ;
}
F_2 ( ! F_106 ( V_138 ) ) ;
return 0 ;
V_157:
F_133 ( & V_160 ) ;
V_146 -> V_154 = NULL ;
V_146 -> V_155 = 0 ;
F_134 ( & V_160 ) ;
return - V_153 ;
}
char * F_135 ( char * V_179 , struct V_137 * V_138 )
{
F_93 ( V_138 ) ;
strncpy ( V_179 , V_138 -> V_180 , sizeof( V_138 -> V_180 ) ) ;
F_96 ( V_138 ) ;
return V_179 ;
}
void F_136 ( struct V_137 * V_138 , const char * V_179 , bool V_102 )
{
F_93 ( V_138 ) ;
F_137 ( V_138 , V_179 ) ;
F_138 ( V_138 -> V_180 , V_179 , sizeof( V_138 -> V_180 ) ) ;
F_96 ( V_138 ) ;
F_139 ( V_138 , V_102 ) ;
}
int F_140 ( struct V_9 * V_10 )
{
int V_181 ;
V_181 = F_100 ( V_14 ) ;
if ( V_181 )
goto V_71;
F_141 ( V_10 -> V_13 , V_10 -> V_109 ) ;
F_12 ( V_10 , 0 ) ;
V_181 = F_88 ( V_10 -> V_13 ) ;
if ( V_181 )
goto V_71;
V_10 -> V_13 = NULL ;
F_60 ( V_182 ) ;
V_14 -> V_183 &= ~ ( V_184 | V_185 | V_186 |
V_187 | V_188 ) ;
F_142 () ;
V_14 -> V_189 &= ~ V_10 -> V_190 ;
return 0 ;
V_71:
return V_181 ;
}
void F_143 ( struct V_9 * V_10 , struct V_109 * V_109 )
{
if ( F_144 ( F_78 ( V_109 ) , V_191 ) < 0 )
V_10 -> V_192 |= V_193 ;
}
void F_145 ( struct V_9 * V_10 )
{
F_146 ( V_14 -> V_13 ) ;
V_14 -> V_194 = V_14 -> V_195 = 0 ;
if ( F_147 ( F_148 () , F_149 () ) && F_150 ( F_151 () , F_152 () ) )
F_153 ( V_14 -> V_13 , V_196 ) ;
else
F_153 ( V_14 -> V_13 , V_197 ) ;
F_154 () ;
F_136 ( V_14 , F_155 ( V_10 -> V_110 ) , true ) ;
V_14 -> V_13 -> V_198 = V_199 ;
if ( ! F_147 ( V_10 -> V_200 -> V_201 , F_148 () ) ||
! F_150 ( V_10 -> V_200 -> V_202 , F_151 () ) ) {
V_14 -> V_203 = 0 ;
} else {
F_143 ( V_10 , V_10 -> V_109 ) ;
if ( V_10 -> V_192 & V_193 )
F_153 ( V_14 -> V_13 , V_197 ) ;
}
V_14 -> V_204 ++ ;
F_156 ( V_14 , 0 ) ;
F_157 ( V_14 -> V_205 ) ;
}
int F_158 ( struct V_9 * V_10 )
{
if ( F_159 ( & V_14 -> signal -> V_206 ) )
return - V_207 ;
V_10 -> V_200 = F_160 () ;
if ( F_112 ( V_10 -> V_200 ) )
return 0 ;
F_161 ( & V_14 -> signal -> V_206 ) ;
return - V_37 ;
}
static void F_162 ( struct V_9 * V_10 )
{
F_22 ( V_10 ) ;
if ( V_10 -> V_200 ) {
F_161 ( & V_14 -> signal -> V_206 ) ;
F_163 ( V_10 -> V_200 ) ;
}
if ( V_10 -> V_109 ) {
F_164 ( V_10 -> V_109 ) ;
F_81 ( V_10 -> V_109 ) ;
}
if ( V_10 -> V_208 != V_10 -> V_110 )
F_165 ( V_10 -> V_208 ) ;
F_165 ( V_10 ) ;
}
int F_166 ( char * V_208 , struct V_9 * V_10 )
{
if ( V_10 -> V_208 != V_10 -> V_110 )
F_165 ( V_10 -> V_208 ) ;
V_10 -> V_208 = F_167 ( V_208 , V_36 ) ;
if ( ! V_10 -> V_208 )
return - V_37 ;
return 0 ;
}
void F_168 ( struct V_9 * V_10 )
{
F_169 ( V_10 ) ;
F_170 ( V_10 -> V_200 ) ;
V_10 -> V_200 = NULL ;
if ( F_171 ( V_14 -> V_13 ) != V_196 )
F_172 ( V_14 ) ;
F_173 ( V_10 ) ;
F_161 ( & V_14 -> signal -> V_206 ) ;
}
static void F_174 ( struct V_9 * V_10 )
{
struct V_137 * V_49 = V_14 , * V_209 ;
unsigned V_210 ;
if ( V_49 -> V_174 ) {
if ( V_49 -> V_174 & V_211 )
V_10 -> V_212 |= V_213 ;
else
V_10 -> V_212 |= V_214 ;
}
if ( V_14 -> V_215 )
V_10 -> V_212 |= V_216 ;
V_209 = V_49 ;
V_210 = 1 ;
F_129 ( & V_49 -> V_217 -> V_150 ) ;
F_175 () ;
F_176 (p, t) {
if ( V_209 -> V_217 == V_49 -> V_217 )
V_210 ++ ;
}
F_177 () ;
if ( V_49 -> V_217 -> V_218 > V_210 )
V_10 -> V_212 |= V_219 ;
else
V_49 -> V_217 -> V_220 = 1 ;
F_131 ( & V_49 -> V_217 -> V_150 ) ;
}
int F_178 ( struct V_9 * V_10 )
{
struct V_221 * V_221 = F_78 ( V_10 -> V_109 ) ;
T_8 V_222 = V_221 -> V_127 ;
int V_181 ;
V_10 -> V_200 -> V_223 = F_148 () ;
V_10 -> V_200 -> V_224 = F_151 () ;
if ( ! ( V_10 -> V_109 -> V_128 . V_129 -> V_130 & V_225 ) &&
! V_14 -> V_215 &&
F_179 ( V_10 -> V_200 -> V_226 , V_221 -> V_227 ) &&
F_180 ( V_10 -> V_200 -> V_226 , V_221 -> V_228 ) ) {
if ( V_222 & V_229 ) {
V_10 -> V_190 |= V_230 ;
V_10 -> V_200 -> V_223 = V_221 -> V_227 ;
}
if ( ( V_222 & ( V_231 | V_232 ) ) == ( V_231 | V_232 ) ) {
V_10 -> V_190 |= V_230 ;
V_10 -> V_200 -> V_224 = V_221 -> V_228 ;
}
}
V_181 = F_181 ( V_10 ) ;
if ( V_181 )
return V_181 ;
V_10 -> V_233 = 1 ;
memset ( V_10 -> V_179 , 0 , V_234 ) ;
return F_83 ( V_10 -> V_109 , 0 , V_10 -> V_179 , V_234 ) ;
}
int F_182 ( struct V_9 * V_10 )
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
V_68 = F_183 ( V_18 ) ;
for (; V_72 < V_28 && V_68 [ V_72 ] ;
V_72 ++ , V_10 -> V_49 ++ )
;
F_184 ( V_68 ) ;
F_20 ( V_18 ) ;
if ( V_72 == V_28 )
F_21 ( V_10 , ( V_10 -> V_49 >> V_235 ) - 1 ) ;
} while ( V_72 == V_28 );
V_10 -> V_49 ++ ;
V_10 -> V_66 -- ;
V_21 = 0 ;
V_71:
return V_21 ;
}
int F_185 ( struct V_9 * V_10 )
{
bool V_236 = F_186 ( V_237 ) ;
struct V_1 * V_2 ;
int V_181 ;
if ( V_10 -> V_238 > 5 )
return - V_239 ;
V_181 = F_187 ( V_10 ) ;
if ( V_181 )
return V_181 ;
V_181 = - V_240 ;
V_241:
F_133 ( & V_5 ) ;
F_188 (fmt, &formats, lh) {
if ( ! F_189 ( V_2 -> V_8 ) )
continue;
F_134 ( & V_5 ) ;
V_10 -> V_238 ++ ;
V_181 = V_2 -> V_4 ( V_10 ) ;
V_10 -> V_238 -- ;
if ( V_181 >= 0 || V_181 != - V_242 ||
V_10 -> V_13 == NULL || V_10 -> V_109 == NULL ) {
F_10 ( V_2 ) ;
return V_181 ;
}
F_133 ( & V_5 ) ;
F_10 ( V_2 ) ;
}
F_134 ( & V_5 ) ;
if ( V_236 && V_181 == - V_242 ) {
if ( F_190 ( V_10 -> V_179 [ 0 ] ) && F_190 ( V_10 -> V_179 [ 1 ] ) &&
F_190 ( V_10 -> V_179 [ 2 ] ) && F_190 ( V_10 -> V_179 [ 3 ] ) )
return V_181 ;
if ( F_191 ( L_1 , * ( V_243 * ) ( V_10 -> V_179 + 2 ) ) < 0 )
return V_181 ;
V_236 = false ;
goto V_241;
}
return V_181 ;
}
static int F_192 ( struct V_9 * V_10 )
{
T_9 V_244 , V_245 ;
int V_21 ;
V_244 = V_14 -> V_164 ;
F_175 () ;
V_245 = F_193 ( V_14 , F_194 ( V_14 -> V_175 ) ) ;
F_177 () ;
V_21 = F_185 ( V_10 ) ;
if ( V_21 >= 0 ) {
F_195 ( V_10 ) ;
F_196 ( V_14 , V_244 , V_10 ) ;
F_197 ( V_246 , V_245 ) ;
F_198 ( V_14 ) ;
}
return V_21 ;
}
static int F_199 ( struct V_110 * V_110 ,
struct V_55 V_56 ,
struct V_55 V_247 )
{
struct V_9 * V_10 ;
struct V_109 * V_109 ;
struct V_248 * V_249 ;
int V_181 ;
if ( F_49 ( V_110 ) )
return F_200 ( V_110 ) ;
if ( ( V_14 -> V_183 & V_250 ) &&
F_126 ( & F_201 () -> V_251 ) > V_26 ( V_252 ) ) {
V_181 = - V_153 ;
goto V_253;
}
V_14 -> V_183 &= ~ V_250 ;
V_181 = F_202 ( & V_249 ) ;
if ( V_181 )
goto V_253;
V_181 = - V_37 ;
V_10 = F_203 ( sizeof( * V_10 ) , V_36 ) ;
if ( ! V_10 )
goto V_254;
V_181 = F_158 ( V_10 ) ;
if ( V_181 )
goto V_255;
F_174 ( V_10 ) ;
V_14 -> V_256 = 1 ;
V_109 = F_75 ( V_110 ) ;
V_181 = F_200 ( V_109 ) ;
if ( F_49 ( V_109 ) )
goto V_257;
F_204 () ;
V_10 -> V_109 = V_109 ;
V_10 -> V_110 = V_10 -> V_208 = V_110 -> V_111 ;
V_181 = F_38 ( V_10 ) ;
if ( V_181 )
goto V_257;
V_10 -> V_66 = F_48 ( V_56 , V_258 ) ;
if ( ( V_181 = V_10 -> V_66 ) < 0 )
goto V_71;
V_10 -> V_259 = F_48 ( V_247 , V_258 ) ;
if ( ( V_181 = V_10 -> V_259 ) < 0 )
goto V_71;
V_181 = F_178 ( V_10 ) ;
if ( V_181 < 0 )
goto V_71;
V_181 = F_58 ( 1 , & V_10 -> V_110 , V_10 ) ;
if ( V_181 < 0 )
goto V_71;
V_10 -> V_102 = V_10 -> V_49 ;
V_181 = F_52 ( V_10 -> V_259 , V_247 , V_10 ) ;
if ( V_181 < 0 )
goto V_71;
V_181 = F_52 ( V_10 -> V_66 , V_56 , V_10 ) ;
if ( V_181 < 0 )
goto V_71;
V_181 = F_192 ( V_10 ) ;
if ( V_181 < 0 )
goto V_71;
V_14 -> V_217 -> V_220 = 0 ;
V_14 -> V_256 = 0 ;
F_205 ( V_14 ) ;
F_206 ( V_14 ) ;
F_162 ( V_10 ) ;
F_207 ( V_110 ) ;
if ( V_249 )
F_208 ( V_249 ) ;
return V_181 ;
V_71:
if ( V_10 -> V_13 ) {
F_12 ( V_10 , 0 ) ;
F_99 ( V_10 -> V_13 ) ;
}
V_257:
V_14 -> V_217 -> V_220 = 0 ;
V_14 -> V_256 = 0 ;
V_255:
F_162 ( V_10 ) ;
V_254:
if ( V_249 )
F_209 ( V_249 ) ;
V_253:
F_207 ( V_110 ) ;
return V_181 ;
}
int F_210 ( struct V_110 * V_110 ,
const char T_1 * const T_1 * V_75 ,
const char T_1 * const T_1 * V_260 )
{
struct V_55 V_56 = { . V_61 . V_58 = V_75 } ;
struct V_55 V_247 = { . V_61 . V_58 = V_260 } ;
return F_199 ( V_110 , V_56 , V_247 ) ;
}
static int F_211 ( struct V_110 * V_110 ,
const T_2 T_1 * V_75 ,
const T_2 T_1 * V_260 )
{
struct V_55 V_56 = {
. V_59 = true ,
. V_61 . V_60 = V_75 ,
} ;
struct V_55 V_247 = {
. V_59 = true ,
. V_61 . V_60 = V_260 ,
} ;
return F_199 ( V_110 , V_56 , V_247 ) ;
}
void F_212 ( struct V_1 * V_261 )
{
struct V_12 * V_13 = V_14 -> V_13 ;
if ( V_13 -> V_262 )
F_11 ( V_13 -> V_262 -> V_8 ) ;
V_13 -> V_262 = V_261 ;
if ( V_261 )
F_213 ( V_261 -> V_8 ) ;
}
void F_153 ( struct V_12 * V_13 , int V_263 )
{
unsigned long V_264 , V_261 ;
if ( F_3 ( ( unsigned ) V_263 > V_265 ) )
return;
do {
V_264 = F_18 ( V_13 -> V_183 ) ;
V_261 = ( V_264 & ~ V_266 ) | V_263 ;
} while ( F_214 ( & V_13 -> V_183 , V_264 , V_261 ) != V_264 );
}
