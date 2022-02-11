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
F_65 ( & V_84 , V_12 , V_78 , V_79 ) ;
if ( V_82 > V_78 ) {
F_66 ( & V_84 , V_82 , V_79 , V_82 ,
V_21 -> V_86 ? V_21 -> V_86 -> V_24 : V_87 ) ;
} else {
F_66 ( & V_84 , V_78 , V_79 , V_82 ,
V_21 -> V_86 ? V_21 -> V_86 -> V_24 : V_87 ) ;
}
F_67 ( & V_84 , V_78 , V_79 ) ;
F_62 ( V_21 , V_81 , V_82 , V_21 -> V_85 , NULL ) ;
return 0 ;
}
int F_68 ( struct V_8 * V_9 ,
unsigned long V_88 ,
int V_89 )
{
unsigned long V_20 ;
unsigned long V_90 ;
struct V_11 * V_12 = V_13 -> V_12 ;
struct V_33 * V_21 = V_9 -> V_21 ;
struct V_33 * V_91 = NULL ;
unsigned long V_42 ;
unsigned long V_92 ;
unsigned long V_93 ;
unsigned long V_94 ;
unsigned long V_95 ;
#ifdef F_14
V_92 = F_69 ( V_29 ) ;
if ( V_92 > ( 1 << 30 ) )
V_92 = 1 << 30 ;
if ( V_21 -> V_23 - V_21 -> V_24 > V_92 )
return - V_36 ;
V_92 = F_70 ( V_88 - V_92 ) ;
V_90 = V_21 -> V_24 - V_92 ;
V_12 -> V_96 = V_9 -> V_47 - V_90 ;
V_9 -> V_47 = V_21 -> V_23 - V_90 ;
#else
V_88 = F_71 ( V_88 ) ;
V_88 = F_70 ( V_88 ) ;
if ( F_43 ( V_88 < V_97 ) ||
F_43 ( V_21 -> V_23 - V_21 -> V_24 >= V_88 - V_97 ) )
return - V_36 ;
V_90 = V_21 -> V_23 - V_88 ;
V_9 -> V_47 -= V_90 ;
V_12 -> V_96 = V_9 -> V_47 ;
#endif
if ( V_9 -> V_98 )
V_9 -> V_98 -= V_90 ;
V_9 -> V_99 -= V_90 ;
F_27 ( & V_12 -> V_37 ) ;
V_42 = V_39 ;
if ( F_43 ( V_89 == V_100 ) )
V_42 |= V_101 ;
else if ( V_89 == V_102 )
V_42 &= ~ V_101 ;
V_42 |= V_12 -> V_103 ;
V_42 |= V_40 ;
V_20 = F_72 ( V_21 , & V_91 , V_21 -> V_24 , V_21 -> V_23 ,
V_42 ) ;
if ( V_20 )
goto V_104;
F_2 ( V_91 != V_21 ) ;
if ( V_90 ) {
V_20 = F_60 ( V_21 , V_90 ) ;
if ( V_20 )
goto V_104;
}
V_21 -> V_42 &= ~ V_40 ;
V_94 = 131072UL ;
V_93 = V_21 -> V_23 - V_21 -> V_24 ;
V_95 = V_25 ( V_29 ) & V_72 ;
#ifdef F_14
if ( V_93 + V_94 > V_95 )
V_92 = V_21 -> V_24 + V_95 ;
else
V_92 = V_21 -> V_23 + V_94 ;
#else
if ( V_93 + V_94 > V_95 )
V_92 = V_21 -> V_23 - V_95 ;
else
V_92 = V_21 -> V_24 - V_94 ;
#endif
V_13 -> V_12 -> V_105 = V_9 -> V_47 ;
V_20 = F_73 ( V_21 , V_92 ) ;
if ( V_20 )
V_20 = - V_60 ;
V_104:
F_32 ( & V_12 -> V_37 ) ;
return V_20 ;
}
struct V_106 * F_74 ( const char * V_107 )
{
struct V_106 * V_106 ;
int V_32 ;
struct V_108 V_109 = { . V_107 = V_107 } ;
static const struct V_110 V_111 = {
. V_112 = V_113 | V_114 | V_115 ,
. V_116 = V_117 | V_118 ,
. V_119 = V_120 ,
. V_121 = V_122 ,
} ;
V_106 = F_75 ( V_123 , & V_109 , & V_111 ) ;
if ( F_48 ( V_106 ) )
goto V_69;
V_32 = - V_124 ;
if ( ! F_76 ( F_77 ( V_106 ) -> V_125 ) )
goto exit;
if ( V_106 -> V_126 . V_127 -> V_128 & V_129 )
goto exit;
F_78 ( V_106 ) ;
V_32 = F_79 ( V_106 ) ;
if ( V_32 )
goto exit;
V_69:
return V_106 ;
exit:
F_80 ( V_106 ) ;
return F_45 ( V_32 ) ;
}
int F_81 ( struct V_106 * V_106 , T_4 V_70 ,
char * V_130 , unsigned long F_47 )
{
T_3 V_131 ;
T_4 V_18 = V_70 ;
int V_132 ;
V_131 = F_58 () ;
F_59 ( F_82 () ) ;
V_132 = F_83 ( V_106 , ( void T_1 * ) V_130 , F_47 , & V_18 ) ;
F_59 ( V_131 ) ;
return V_132 ;
}
T_5 F_84 ( struct V_106 * V_106 , unsigned long V_130 , T_4 V_18 , T_6 V_48 )
{
T_5 V_133 = V_106 -> V_134 -> V_135 ( V_106 , ( void T_1 * ) V_130 , V_48 , & V_18 ) ;
if ( V_133 > 0 )
F_85 ( V_130 , V_130 + V_48 ) ;
return V_133 ;
}
static int F_86 ( struct V_11 * V_12 )
{
struct V_136 * V_137 ;
struct V_11 * V_138 , * V_139 ;
V_137 = V_13 ;
V_138 = V_13 -> V_12 ;
F_87 ( V_137 , V_138 ) ;
if ( V_138 ) {
F_88 ( V_138 ) ;
F_89 ( & V_138 -> V_37 ) ;
if ( F_43 ( V_138 -> V_140 ) ) {
F_90 ( & V_138 -> V_37 ) ;
return - V_141 ;
}
}
F_91 ( V_137 ) ;
V_139 = V_137 -> V_139 ;
V_137 -> V_12 = V_12 ;
V_137 -> V_139 = V_12 ;
F_92 ( V_139 , V_12 ) ;
F_93 ( V_137 ) ;
F_94 ( V_12 ) ;
if ( V_138 ) {
F_90 ( & V_138 -> V_37 ) ;
F_2 ( V_139 != V_138 ) ;
F_95 ( & V_137 -> signal -> V_142 , V_138 ) ;
F_96 ( V_138 ) ;
F_97 ( V_138 ) ;
return 0 ;
}
F_40 ( V_139 ) ;
return 0 ;
}
static int F_98 ( struct V_136 * V_137 )
{
struct V_143 * V_144 = V_137 -> signal ;
struct V_145 * V_146 = V_137 -> V_147 ;
T_7 * V_148 = & V_146 -> V_149 ;
if ( F_99 ( V_137 ) )
goto V_150;
F_100 ( V_148 ) ;
if ( F_101 ( V_144 ) ) {
F_102 ( V_148 ) ;
return - V_151 ;
}
V_144 -> V_152 = V_137 ;
V_144 -> V_153 = F_103 ( V_137 ) ;
if ( ! F_104 ( V_137 ) )
V_144 -> V_153 -- ;
while ( V_144 -> V_153 ) {
F_105 ( V_154 ) ;
F_102 ( V_148 ) ;
F_106 () ;
if ( F_43 ( F_107 ( V_137 ) ) )
goto V_155;
F_100 ( V_148 ) ;
}
F_102 ( V_148 ) ;
if ( ! F_104 ( V_137 ) ) {
struct V_136 * V_156 = V_137 -> V_157 ;
V_144 -> V_153 = - 1 ;
for (; ; ) {
F_108 ( V_137 ) ;
F_109 ( & V_158 ) ;
if ( F_110 ( V_156 -> V_159 ) )
break;
F_105 ( V_154 ) ;
F_111 ( & V_158 ) ;
F_112 ( V_137 ) ;
F_106 () ;
if ( F_43 ( F_107 ( V_137 ) ) )
goto V_155;
}
V_137 -> V_160 = V_156 -> V_160 ;
V_137 -> V_161 = V_156 -> V_161 ;
F_2 ( ! F_113 ( V_156 , V_137 ) ) ;
F_2 ( F_114 ( V_137 ) ) ;
V_137 -> V_162 = V_156 -> V_162 ;
F_115 ( V_137 , V_163 , F_116 ( V_156 ) ) ;
F_117 ( V_156 , V_137 , V_164 ) ;
F_117 ( V_156 , V_137 , V_165 ) ;
F_118 ( & V_156 -> V_166 , & V_137 -> V_166 ) ;
F_119 ( & V_156 -> V_167 , & V_137 -> V_167 ) ;
V_137 -> V_157 = V_137 ;
V_156 -> V_157 = V_137 ;
V_137 -> V_168 = V_169 ;
V_156 -> V_168 = - 1 ;
F_2 ( V_156 -> V_159 != V_170 ) ;
V_156 -> V_159 = V_171 ;
if ( F_43 ( V_156 -> V_172 ) )
F_120 ( V_156 , V_156 -> V_173 ) ;
F_111 ( & V_158 ) ;
F_112 ( V_137 ) ;
F_121 ( V_156 ) ;
}
V_144 -> V_152 = NULL ;
V_144 -> V_153 = 0 ;
V_150:
V_137 -> V_168 = V_169 ;
F_122 ( V_144 ) ;
F_123 () ;
if ( F_124 ( & V_146 -> F_47 ) != 1 ) {
struct V_145 * V_174 ;
V_174 = F_125 ( V_175 , V_35 ) ;
if ( ! V_174 )
return - V_36 ;
F_126 ( & V_174 -> F_47 , 1 ) ;
memcpy ( V_174 -> V_176 , V_146 -> V_176 ,
sizeof( V_174 -> V_176 ) ) ;
F_109 ( & V_158 ) ;
F_127 ( & V_146 -> V_149 ) ;
F_128 ( V_137 -> V_147 , V_174 ) ;
F_129 ( & V_146 -> V_149 ) ;
F_111 ( & V_158 ) ;
F_130 ( V_146 ) ;
}
F_2 ( ! F_104 ( V_137 ) ) ;
return 0 ;
V_155:
F_131 ( & V_158 ) ;
V_144 -> V_152 = NULL ;
V_144 -> V_153 = 0 ;
F_132 ( & V_158 ) ;
return - V_151 ;
}
char * F_133 ( char * V_177 , struct V_136 * V_137 )
{
F_91 ( V_137 ) ;
strncpy ( V_177 , V_137 -> V_178 , sizeof( V_137 -> V_178 ) ) ;
F_93 ( V_137 ) ;
return V_177 ;
}
void F_134 ( struct V_136 * V_137 , char * V_177 )
{
F_91 ( V_137 ) ;
F_135 ( V_137 , V_177 ) ;
F_136 ( V_137 -> V_178 , V_177 , sizeof( V_137 -> V_178 ) ) ;
F_93 ( V_137 ) ;
F_137 ( V_137 ) ;
}
static void F_138 ( char * V_179 , const char * V_180 , unsigned int V_48 )
{
int V_31 , V_181 ;
for ( V_31 = 0 ; ( V_181 = * ( V_180 ++ ) ) != '\0' ; ) {
if ( V_181 == '/' )
V_31 = 0 ;
else
if ( V_31 < V_48 - 1 )
V_179 [ V_31 ++ ] = V_181 ;
}
V_179 [ V_31 ] = '\0' ;
}
int F_139 ( struct V_8 * V_9 )
{
int V_182 ;
V_182 = F_98 ( V_13 ) ;
if ( V_182 )
goto V_69;
F_140 ( V_9 -> V_12 , V_9 -> V_106 ) ;
F_138 ( V_9 -> V_179 , V_9 -> V_108 , sizeof( V_9 -> V_179 ) ) ;
F_11 ( V_9 , 0 ) ;
V_182 = F_86 ( V_9 -> V_12 ) ;
if ( V_182 )
goto V_69;
V_9 -> V_12 = NULL ;
F_59 ( V_183 ) ;
V_13 -> V_184 &=
~ ( V_185 | V_186 | V_187 | V_188 ) ;
F_141 () ;
V_13 -> V_189 &= ~ V_9 -> V_190 ;
return 0 ;
V_69:
return V_182 ;
}
void F_142 ( struct V_8 * V_9 , struct V_106 * V_106 )
{
if ( F_143 ( F_77 ( V_106 ) , V_191 ) < 0 )
V_9 -> V_192 |= V_193 ;
}
void F_144 ( struct V_8 * V_9 )
{
F_94 ( V_13 -> V_12 ) ;
V_13 -> V_194 = V_13 -> V_195 = 0 ;
if ( F_145 ( F_146 () , F_147 () ) && F_148 ( F_149 () , F_150 () ) )
F_151 ( V_13 -> V_12 , V_196 ) ;
else
F_151 ( V_13 -> V_12 , V_197 ) ;
F_134 ( V_13 , V_9 -> V_179 ) ;
V_13 -> V_12 -> V_198 = V_199 ;
if ( ! F_145 ( V_9 -> V_200 -> V_201 , F_146 () ) ||
! F_148 ( V_9 -> V_200 -> V_202 , F_149 () ) ) {
V_13 -> V_203 = 0 ;
} else {
F_142 ( V_9 , V_9 -> V_106 ) ;
if ( V_9 -> V_192 & V_193 )
F_151 ( V_13 -> V_12 , V_197 ) ;
}
V_13 -> V_204 ++ ;
F_152 ( V_13 , 0 ) ;
F_153 ( V_13 -> V_205 ) ;
}
int F_154 ( struct V_8 * V_9 )
{
if ( F_155 ( & V_13 -> signal -> V_206 ) )
return - V_207 ;
V_9 -> V_200 = F_156 () ;
if ( F_110 ( V_9 -> V_200 ) )
return 0 ;
F_157 ( & V_13 -> signal -> V_206 ) ;
return - V_36 ;
}
void F_158 ( struct V_8 * V_9 )
{
F_21 ( V_9 ) ;
if ( V_9 -> V_200 ) {
F_157 ( & V_13 -> signal -> V_206 ) ;
F_159 ( V_9 -> V_200 ) ;
}
if ( V_9 -> V_208 != V_9 -> V_108 )
F_160 ( V_9 -> V_208 ) ;
F_160 ( V_9 ) ;
}
int F_161 ( char * V_208 , struct V_8 * V_9 )
{
if ( V_9 -> V_208 != V_9 -> V_108 )
F_160 ( V_9 -> V_208 ) ;
V_9 -> V_208 = F_162 ( V_208 , V_35 ) ;
if ( ! V_9 -> V_208 )
return - V_36 ;
return 0 ;
}
void F_163 ( struct V_8 * V_9 )
{
F_164 ( V_9 ) ;
F_165 ( V_9 -> V_200 ) ;
V_9 -> V_200 = NULL ;
if ( F_166 ( V_13 -> V_12 ) != V_196 )
F_167 ( V_13 ) ;
F_168 ( V_9 ) ;
F_157 ( & V_13 -> signal -> V_206 ) ;
}
static int F_169 ( struct V_8 * V_9 )
{
struct V_136 * V_47 = V_13 , * V_209 ;
unsigned V_210 ;
int V_133 = 0 ;
if ( V_47 -> V_172 ) {
if ( V_47 -> V_172 & V_211 )
V_9 -> V_212 |= V_213 ;
else
V_9 -> V_212 |= V_214 ;
}
if ( V_13 -> V_215 )
V_9 -> V_212 |= V_216 ;
V_210 = 1 ;
F_127 ( & V_47 -> V_217 -> V_148 ) ;
F_170 () ;
for ( V_209 = F_171 ( V_47 ) ; V_209 != V_47 ; V_209 = F_171 ( V_209 ) ) {
if ( V_209 -> V_217 == V_47 -> V_217 )
V_210 ++ ;
}
F_172 () ;
if ( V_47 -> V_217 -> V_218 > V_210 ) {
V_9 -> V_212 |= V_219 ;
} else {
V_133 = - V_151 ;
if ( ! V_47 -> V_217 -> V_220 ) {
V_47 -> V_217 -> V_220 = 1 ;
V_133 = 1 ;
}
}
F_129 ( & V_47 -> V_217 -> V_148 ) ;
return V_133 ;
}
int F_173 ( struct V_8 * V_9 )
{
T_8 V_221 ;
struct V_222 * V_222 = F_77 ( V_9 -> V_106 ) ;
int V_182 ;
V_221 = V_222 -> V_125 ;
if ( V_9 -> V_106 -> V_134 == NULL )
return - V_124 ;
V_9 -> V_200 -> V_223 = F_146 () ;
V_9 -> V_200 -> V_224 = F_149 () ;
if ( ! ( V_9 -> V_106 -> V_126 . V_127 -> V_128 & V_225 ) &&
! V_13 -> V_215 &&
F_174 ( V_9 -> V_200 -> V_226 , V_222 -> V_227 ) &&
F_175 ( V_9 -> V_200 -> V_226 , V_222 -> V_228 ) ) {
if ( V_221 & V_229 ) {
V_9 -> V_190 |= V_230 ;
V_9 -> V_200 -> V_223 = V_222 -> V_227 ;
}
if ( ( V_221 & ( V_231 | V_232 ) ) == ( V_231 | V_232 ) ) {
V_9 -> V_190 |= V_230 ;
V_9 -> V_200 -> V_224 = V_222 -> V_228 ;
}
}
V_182 = F_176 ( V_9 ) ;
if ( V_182 )
return V_182 ;
V_9 -> V_233 = 1 ;
memset ( V_9 -> V_177 , 0 , V_234 ) ;
return F_81 ( V_9 -> V_106 , 0 , V_9 -> V_177 , V_234 ) ;
}
int F_177 ( struct V_8 * V_9 )
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
V_66 = F_178 ( V_17 ) ;
for (; V_70 < V_27 && V_66 [ V_70 ] ;
V_70 ++ , V_9 -> V_47 ++ )
;
F_179 ( V_66 ) ;
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
int F_180 ( struct V_8 * V_9 )
{
unsigned int V_236 = V_9 -> V_237 ;
int V_238 , V_182 ;
struct V_1 * V_2 ;
T_9 V_239 , V_240 ;
if ( V_236 > 5 )
return - V_241 ;
V_182 = F_181 ( V_9 ) ;
if ( V_182 )
return V_182 ;
V_182 = F_182 ( V_9 ) ;
if ( V_182 )
return V_182 ;
V_239 = V_13 -> V_162 ;
F_170 () ;
V_240 = F_183 ( V_13 , F_184 ( V_13 -> V_173 ) ) ;
F_172 () ;
V_182 = - V_242 ;
for ( V_238 = 0 ; V_238 < 2 ; V_238 ++ ) {
F_131 ( & V_4 ) ;
F_185 (fmt, &formats, lh) {
int (* V_180)( struct V_8 * ) = V_2 -> V_243 ;
if ( ! V_180 )
continue;
if ( ! F_186 ( V_2 -> V_7 ) )
continue;
F_132 ( & V_4 ) ;
V_9 -> V_237 = V_236 + 1 ;
V_182 = V_180 ( V_9 ) ;
V_9 -> V_237 = V_236 ;
if ( V_182 >= 0 ) {
if ( V_236 == 0 ) {
F_187 ( V_13 , V_239 , V_9 ) ;
F_188 ( V_244 , V_240 ) ;
}
F_9 ( V_2 ) ;
F_189 ( V_9 -> V_106 ) ;
if ( V_9 -> V_106 )
F_80 ( V_9 -> V_106 ) ;
V_9 -> V_106 = NULL ;
V_13 -> V_245 = 1 ;
F_190 ( V_13 ) ;
return V_182 ;
}
F_131 ( & V_4 ) ;
F_9 ( V_2 ) ;
if ( V_182 != - V_246 || V_9 -> V_12 == NULL )
break;
if ( ! V_9 -> V_106 ) {
F_132 ( & V_4 ) ;
return V_182 ;
}
}
F_132 ( & V_4 ) ;
#ifdef F_191
if ( V_182 != - V_246 || V_9 -> V_12 == NULL ) {
break;
} else {
#define F_192 ( T_10 ) (((c)=='\t') || ((c)=='\n') || (0x20<=(c) && (c)<=0x7e))
if ( F_192 ( V_9 -> V_177 [ 0 ] ) &&
F_192 ( V_9 -> V_177 [ 1 ] ) &&
F_192 ( V_9 -> V_177 [ 2 ] ) &&
F_192 ( V_9 -> V_177 [ 3 ] ) )
break;
if ( V_238 )
break;
F_193 ( L_1 , * ( unsigned short * ) ( & V_9 -> V_177 [ 2 ] ) ) ;
}
#else
break;
#endif
}
return V_182 ;
}
static int F_194 ( const char * V_108 ,
struct V_53 V_54 ,
struct V_53 V_247 )
{
struct V_8 * V_9 ;
struct V_106 * V_106 ;
struct V_248 * V_249 ;
bool V_250 ;
int V_182 ;
if ( ( V_13 -> V_184 & V_251 ) &&
F_124 ( & F_195 () -> V_252 ) > V_25 ( V_253 ) ) {
V_182 = - V_151 ;
goto V_254;
}
V_13 -> V_184 &= ~ V_251 ;
V_182 = F_196 ( & V_249 ) ;
if ( V_182 )
goto V_254;
V_182 = - V_36 ;
V_9 = F_197 ( sizeof( * V_9 ) , V_35 ) ;
if ( ! V_9 )
goto V_255;
V_182 = F_154 ( V_9 ) ;
if ( V_182 )
goto V_256;
V_182 = F_169 ( V_9 ) ;
if ( V_182 < 0 )
goto V_256;
V_250 = V_182 ;
V_13 -> V_257 = 1 ;
V_106 = F_74 ( V_108 ) ;
V_182 = F_198 ( V_106 ) ;
if ( F_48 ( V_106 ) )
goto V_258;
F_199 () ;
V_9 -> V_106 = V_106 ;
V_9 -> V_108 = V_108 ;
V_9 -> V_208 = V_108 ;
V_182 = F_37 ( V_9 ) ;
if ( V_182 )
goto V_259;
V_9 -> V_64 = F_47 ( V_54 , V_260 ) ;
if ( ( V_182 = V_9 -> V_64 ) < 0 )
goto V_69;
V_9 -> V_261 = F_47 ( V_247 , V_260 ) ;
if ( ( V_182 = V_9 -> V_261 ) < 0 )
goto V_69;
V_182 = F_173 ( V_9 ) ;
if ( V_182 < 0 )
goto V_69;
V_182 = F_57 ( 1 , & V_9 -> V_108 , V_9 ) ;
if ( V_182 < 0 )
goto V_69;
V_9 -> V_99 = V_9 -> V_47 ;
V_182 = F_51 ( V_9 -> V_261 , V_247 , V_9 ) ;
if ( V_182 < 0 )
goto V_69;
V_182 = F_51 ( V_9 -> V_64 , V_54 , V_9 ) ;
if ( V_182 < 0 )
goto V_69;
V_182 = F_180 ( V_9 ) ;
if ( V_182 < 0 )
goto V_69;
V_13 -> V_217 -> V_220 = 0 ;
V_13 -> V_257 = 0 ;
F_200 ( V_13 ) ;
F_158 ( V_9 ) ;
if ( V_249 )
F_201 ( V_249 ) ;
return V_182 ;
V_69:
if ( V_9 -> V_12 ) {
F_11 ( V_9 , 0 ) ;
F_97 ( V_9 -> V_12 ) ;
}
V_259:
if ( V_9 -> V_106 ) {
F_189 ( V_9 -> V_106 ) ;
F_80 ( V_9 -> V_106 ) ;
}
V_258:
if ( V_250 )
V_13 -> V_217 -> V_220 = 0 ;
V_13 -> V_257 = 0 ;
V_256:
F_158 ( V_9 ) ;
V_255:
if ( V_249 )
F_202 ( V_249 ) ;
V_254:
return V_182 ;
}
int F_203 ( const char * V_108 ,
const char T_1 * const T_1 * V_73 ,
const char T_1 * const T_1 * V_262 )
{
struct V_53 V_54 = { . V_59 . V_56 = V_73 } ;
struct V_53 V_247 = { . V_59 . V_56 = V_262 } ;
return F_194 ( V_108 , V_54 , V_247 ) ;
}
static int F_204 ( const char * V_108 ,
const T_2 T_1 * V_73 ,
const T_2 T_1 * V_262 )
{
struct V_53 V_54 = {
. V_57 = true ,
. V_59 . V_58 = V_73 ,
} ;
struct V_53 V_247 = {
. V_57 = true ,
. V_59 . V_58 = V_262 ,
} ;
return F_194 ( V_108 , V_54 , V_247 ) ;
}
void F_205 ( struct V_1 * V_263 )
{
struct V_11 * V_12 = V_13 -> V_12 ;
if ( V_12 -> V_264 )
F_10 ( V_12 -> V_264 -> V_7 ) ;
V_12 -> V_264 = V_263 ;
if ( V_263 )
F_206 ( V_263 -> V_7 ) ;
}
void F_151 ( struct V_11 * V_12 , int V_265 )
{
switch ( V_265 ) {
case V_266 :
F_207 ( V_267 , & V_12 -> V_184 ) ;
F_208 () ;
F_207 ( V_268 , & V_12 -> V_184 ) ;
break;
case V_196 :
F_209 ( V_267 , & V_12 -> V_184 ) ;
F_208 () ;
F_207 ( V_268 , & V_12 -> V_184 ) ;
break;
case V_269 :
F_209 ( V_268 , & V_12 -> V_184 ) ;
F_208 () ;
F_209 ( V_267 , & V_12 -> V_184 ) ;
break;
}
}
int F_210 ( unsigned long V_270 )
{
int V_20 ;
V_20 = V_270 & V_271 ;
return ( V_20 > V_196 ) ? V_269 : V_20 ;
}
int F_166 ( struct V_11 * V_12 )
{
return F_210 ( V_12 -> V_184 ) ;
}
T_11 long F_211 ( const char T_1 * V_108 ,
const T_2 T_1 * V_54 ,
const T_2 T_1 * V_247 )
{
struct V_108 * V_272 = F_212 ( V_108 ) ;
int error = F_198 ( V_272 ) ;
if ( ! F_48 ( V_272 ) ) {
error = F_204 ( V_272 -> V_107 , V_54 , V_247 ) ;
F_213 ( V_272 ) ;
}
return error ;
}
