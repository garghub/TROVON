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
V_21 -> V_86 ? V_21 -> V_86 -> V_24 : V_87 ) ;
} else {
F_66 ( & V_84 , V_78 , V_79 , V_82 ,
V_21 -> V_86 ? V_21 -> V_86 -> V_24 : V_87 ) ;
}
F_67 ( & V_84 , V_82 , V_79 ) ;
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
. V_119 = V_120
} ;
V_106 = F_75 ( V_121 , & V_109 , & V_111 , V_122 ) ;
if ( F_48 ( V_106 ) )
goto V_69;
V_32 = - V_123 ;
if ( ! F_76 ( F_77 ( V_106 ) -> V_124 ) )
goto exit;
if ( V_106 -> V_125 . V_126 -> V_127 & V_128 )
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
char * V_129 , unsigned long F_47 )
{
T_3 V_130 ;
T_4 V_18 = V_70 ;
int V_131 ;
V_130 = F_58 () ;
F_59 ( F_82 () ) ;
V_131 = F_83 ( V_106 , ( void T_1 * ) V_129 , F_47 , & V_18 ) ;
F_59 ( V_130 ) ;
return V_131 ;
}
T_5 F_84 ( struct V_106 * V_106 , unsigned long V_129 , T_4 V_18 , T_6 V_48 )
{
T_5 V_132 = V_106 -> V_133 -> V_134 ( V_106 , ( void T_1 * ) V_129 , V_48 , & V_18 ) ;
if ( V_132 > 0 )
F_85 ( V_129 , V_129 + V_48 ) ;
return V_132 ;
}
static int F_86 ( struct V_11 * V_12 )
{
struct V_135 * V_136 ;
struct V_11 * V_137 , * V_138 ;
V_136 = V_13 ;
V_137 = V_13 -> V_12 ;
F_87 ( V_136 , V_137 ) ;
if ( V_137 ) {
F_88 ( V_137 ) ;
F_89 ( & V_137 -> V_37 ) ;
if ( F_43 ( V_137 -> V_139 ) ) {
F_90 ( & V_137 -> V_37 ) ;
return - V_140 ;
}
}
F_91 ( V_136 ) ;
V_138 = V_136 -> V_138 ;
V_136 -> V_12 = V_12 ;
V_136 -> V_138 = V_12 ;
F_92 ( V_138 , V_12 ) ;
F_93 ( V_136 ) ;
F_94 ( V_12 ) ;
if ( V_137 ) {
F_90 ( & V_137 -> V_37 ) ;
F_2 ( V_138 != V_137 ) ;
F_95 ( & V_136 -> signal -> V_141 , V_137 ) ;
F_96 ( V_137 ) ;
F_97 ( V_137 ) ;
return 0 ;
}
F_40 ( V_138 ) ;
return 0 ;
}
static int F_98 ( struct V_135 * V_136 )
{
struct V_142 * V_143 = V_136 -> signal ;
struct V_144 * V_145 = V_136 -> V_146 ;
T_7 * V_147 = & V_145 -> V_148 ;
if ( F_99 ( V_136 ) )
goto V_149;
F_100 ( V_147 ) ;
if ( F_101 ( V_143 ) ) {
F_102 ( V_147 ) ;
return - V_150 ;
}
V_143 -> V_151 = V_136 ;
V_143 -> V_152 = F_103 ( V_136 ) ;
if ( ! F_104 ( V_136 ) )
V_143 -> V_152 -- ;
while ( V_143 -> V_152 ) {
F_105 ( V_153 ) ;
F_102 ( V_147 ) ;
F_106 () ;
if ( F_43 ( F_107 ( V_136 ) ) )
goto V_154;
F_100 ( V_147 ) ;
}
F_102 ( V_147 ) ;
if ( ! F_104 ( V_136 ) ) {
struct V_135 * V_155 = V_136 -> V_156 ;
V_143 -> V_152 = - 1 ;
for (; ; ) {
F_108 ( V_136 ) ;
F_109 ( & V_157 ) ;
if ( F_110 ( V_155 -> V_158 ) )
break;
F_105 ( V_153 ) ;
F_111 ( & V_157 ) ;
F_112 ( V_136 ) ;
F_106 () ;
if ( F_43 ( F_107 ( V_136 ) ) )
goto V_154;
}
V_136 -> V_159 = V_155 -> V_159 ;
F_2 ( ! F_113 ( V_155 , V_136 ) ) ;
F_2 ( F_114 ( V_136 ) ) ;
F_115 ( V_136 , V_160 ) ;
V_136 -> V_161 = V_155 -> V_161 ;
F_116 ( V_136 , V_160 , F_117 ( V_155 ) ) ;
F_118 ( V_155 , V_136 , V_162 ) ;
F_118 ( V_155 , V_136 , V_163 ) ;
F_119 ( & V_155 -> V_164 , & V_136 -> V_164 ) ;
F_120 ( & V_155 -> V_165 , & V_136 -> V_165 ) ;
V_136 -> V_156 = V_136 ;
V_155 -> V_156 = V_136 ;
V_136 -> V_166 = V_167 ;
V_155 -> V_166 = - 1 ;
F_2 ( V_155 -> V_158 != V_168 ) ;
V_155 -> V_158 = V_169 ;
if ( F_43 ( V_155 -> V_170 ) )
F_121 ( V_155 , V_155 -> V_171 ) ;
F_111 ( & V_157 ) ;
F_112 ( V_136 ) ;
F_122 ( V_155 ) ;
}
V_143 -> V_151 = NULL ;
V_143 -> V_152 = 0 ;
V_149:
V_136 -> V_166 = V_167 ;
F_123 ( V_143 ) ;
F_124 () ;
if ( F_125 ( & V_145 -> F_47 ) != 1 ) {
struct V_144 * V_172 ;
V_172 = F_126 ( V_173 , V_35 ) ;
if ( ! V_172 )
return - V_36 ;
F_127 ( & V_172 -> F_47 , 1 ) ;
memcpy ( V_172 -> V_174 , V_145 -> V_174 ,
sizeof( V_172 -> V_174 ) ) ;
F_109 ( & V_157 ) ;
F_128 ( & V_145 -> V_148 ) ;
F_129 ( V_136 -> V_146 , V_172 ) ;
F_130 ( & V_145 -> V_148 ) ;
F_111 ( & V_157 ) ;
F_131 ( V_145 ) ;
}
F_2 ( ! F_104 ( V_136 ) ) ;
return 0 ;
V_154:
F_132 ( & V_157 ) ;
V_143 -> V_151 = NULL ;
V_143 -> V_152 = 0 ;
F_133 ( & V_157 ) ;
return - V_150 ;
}
char * F_134 ( char * V_175 , struct V_135 * V_136 )
{
F_91 ( V_136 ) ;
strncpy ( V_175 , V_136 -> V_176 , sizeof( V_136 -> V_176 ) ) ;
F_93 ( V_136 ) ;
return V_175 ;
}
void F_135 ( struct V_135 * V_136 , char * V_175 )
{
F_91 ( V_136 ) ;
F_136 ( V_136 , V_175 ) ;
F_137 ( V_136 -> V_176 , V_175 , sizeof( V_136 -> V_176 ) ) ;
F_93 ( V_136 ) ;
F_138 ( V_136 ) ;
}
static void F_139 ( char * V_177 , const char * V_178 , unsigned int V_48 )
{
int V_31 , V_179 ;
for ( V_31 = 0 ; ( V_179 = * ( V_178 ++ ) ) != '\0' ; ) {
if ( V_179 == '/' )
V_31 = 0 ;
else
if ( V_31 < V_48 - 1 )
V_177 [ V_31 ++ ] = V_179 ;
}
V_177 [ V_31 ] = '\0' ;
}
int F_140 ( struct V_8 * V_9 )
{
int V_180 ;
V_180 = F_98 ( V_13 ) ;
if ( V_180 )
goto V_69;
F_141 ( V_9 -> V_12 , V_9 -> V_106 ) ;
F_139 ( V_9 -> V_177 , V_9 -> V_108 , sizeof( V_9 -> V_177 ) ) ;
F_11 ( V_9 , 0 ) ;
V_180 = F_86 ( V_9 -> V_12 ) ;
if ( V_180 )
goto V_69;
V_9 -> V_12 = NULL ;
F_59 ( V_181 ) ;
V_13 -> V_182 &=
~ ( V_183 | V_184 | V_185 | V_186 ) ;
F_142 () ;
V_13 -> V_187 &= ~ V_9 -> V_188 ;
return 0 ;
V_69:
return V_180 ;
}
void F_143 ( struct V_8 * V_9 , struct V_106 * V_106 )
{
if ( F_144 ( F_77 ( V_106 ) , V_189 ) < 0 )
V_9 -> V_190 |= V_191 ;
}
void F_145 ( struct V_8 * V_9 )
{
F_94 ( V_13 -> V_12 ) ;
V_13 -> V_192 = V_13 -> V_193 = 0 ;
if ( F_146 ( F_147 () , F_148 () ) && F_149 ( F_150 () , F_151 () ) )
F_152 ( V_13 -> V_12 , V_194 ) ;
else
F_152 ( V_13 -> V_12 , V_195 ) ;
F_135 ( V_13 , V_9 -> V_177 ) ;
V_13 -> V_12 -> V_196 = V_197 ;
if ( ! F_146 ( V_9 -> V_198 -> V_199 , F_147 () ) ||
! F_149 ( V_9 -> V_198 -> V_200 , F_150 () ) ) {
V_13 -> V_201 = 0 ;
} else {
F_143 ( V_9 , V_9 -> V_106 ) ;
if ( V_9 -> V_190 & V_191 )
F_152 ( V_13 -> V_12 , V_195 ) ;
}
V_13 -> V_202 ++ ;
F_153 ( V_13 , 0 ) ;
F_154 ( V_13 -> V_203 ) ;
}
int F_155 ( struct V_8 * V_9 )
{
if ( F_156 ( & V_13 -> signal -> V_204 ) )
return - V_205 ;
V_9 -> V_198 = F_157 () ;
if ( F_110 ( V_9 -> V_198 ) )
return 0 ;
F_158 ( & V_13 -> signal -> V_204 ) ;
return - V_36 ;
}
void F_159 ( struct V_8 * V_9 )
{
F_21 ( V_9 ) ;
if ( V_9 -> V_198 ) {
F_158 ( & V_13 -> signal -> V_204 ) ;
F_160 ( V_9 -> V_198 ) ;
}
if ( V_9 -> V_206 != V_9 -> V_108 )
F_161 ( V_9 -> V_206 ) ;
F_161 ( V_9 ) ;
}
int F_162 ( char * V_206 , struct V_8 * V_9 )
{
if ( V_9 -> V_206 != V_9 -> V_108 )
F_161 ( V_9 -> V_206 ) ;
V_9 -> V_206 = F_163 ( V_206 , V_35 ) ;
if ( ! V_9 -> V_206 )
return - V_36 ;
return 0 ;
}
void F_164 ( struct V_8 * V_9 )
{
F_165 ( V_9 ) ;
F_166 ( V_9 -> V_198 ) ;
V_9 -> V_198 = NULL ;
if ( F_167 ( V_13 -> V_12 ) != V_194 )
F_168 ( V_13 ) ;
F_169 ( V_9 ) ;
F_158 ( & V_13 -> signal -> V_204 ) ;
}
static int F_170 ( struct V_8 * V_9 )
{
struct V_135 * V_47 = V_13 , * V_207 ;
unsigned V_208 ;
int V_132 = 0 ;
if ( V_47 -> V_170 ) {
if ( V_47 -> V_170 & V_209 )
V_9 -> V_210 |= V_211 ;
else
V_9 -> V_210 |= V_212 ;
}
if ( V_13 -> V_213 )
V_9 -> V_210 |= V_214 ;
V_208 = 1 ;
F_128 ( & V_47 -> V_215 -> V_147 ) ;
F_171 () ;
for ( V_207 = F_172 ( V_47 ) ; V_207 != V_47 ; V_207 = F_172 ( V_207 ) ) {
if ( V_207 -> V_215 == V_47 -> V_215 )
V_208 ++ ;
}
F_173 () ;
if ( V_47 -> V_215 -> V_216 > V_208 ) {
V_9 -> V_210 |= V_217 ;
} else {
V_132 = - V_150 ;
if ( ! V_47 -> V_215 -> V_218 ) {
V_47 -> V_215 -> V_218 = 1 ;
V_132 = 1 ;
}
}
F_130 ( & V_47 -> V_215 -> V_147 ) ;
return V_132 ;
}
int F_174 ( struct V_8 * V_9 )
{
T_8 V_219 ;
struct V_220 * V_220 = F_77 ( V_9 -> V_106 ) ;
int V_180 ;
V_219 = V_220 -> V_124 ;
if ( V_9 -> V_106 -> V_133 == NULL )
return - V_123 ;
V_9 -> V_198 -> V_221 = F_147 () ;
V_9 -> V_198 -> V_222 = F_150 () ;
if ( ! ( V_9 -> V_106 -> V_125 . V_126 -> V_127 & V_223 ) &&
! V_13 -> V_213 &&
F_175 ( V_9 -> V_198 -> V_224 , V_220 -> V_225 ) &&
F_176 ( V_9 -> V_198 -> V_224 , V_220 -> V_226 ) ) {
if ( V_219 & V_227 ) {
V_9 -> V_188 |= V_228 ;
V_9 -> V_198 -> V_221 = V_220 -> V_225 ;
}
if ( ( V_219 & ( V_229 | V_230 ) ) == ( V_229 | V_230 ) ) {
V_9 -> V_188 |= V_228 ;
V_9 -> V_198 -> V_222 = V_220 -> V_226 ;
}
}
V_180 = F_177 ( V_9 ) ;
if ( V_180 )
return V_180 ;
V_9 -> V_231 = 1 ;
memset ( V_9 -> V_175 , 0 , V_232 ) ;
return F_81 ( V_9 -> V_106 , 0 , V_9 -> V_175 , V_232 ) ;
}
int F_178 ( struct V_8 * V_9 )
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
V_66 = F_179 ( V_17 ) ;
for (; V_70 < V_27 && V_66 [ V_70 ] ;
V_70 ++ , V_9 -> V_47 ++ )
;
F_180 ( V_66 ) ;
F_19 ( V_17 ) ;
if ( V_70 == V_27 )
F_20 ( V_9 , ( V_9 -> V_47 >> V_233 ) - 1 ) ;
} while ( V_70 == V_27 );
V_9 -> V_47 ++ ;
V_9 -> V_64 -- ;
V_20 = 0 ;
V_69:
return V_20 ;
}
int F_181 ( struct V_8 * V_9 )
{
unsigned int V_234 = V_9 -> V_235 ;
int V_236 , V_180 ;
struct V_1 * V_2 ;
T_9 V_237 , V_238 ;
if ( V_234 > 5 )
return - V_239 ;
V_180 = F_182 ( V_9 ) ;
if ( V_180 )
return V_180 ;
V_180 = F_183 ( V_9 ) ;
if ( V_180 )
return V_180 ;
V_237 = V_13 -> V_161 ;
F_171 () ;
V_238 = F_184 ( V_13 , F_185 ( V_13 -> V_171 ) ) ;
F_173 () ;
V_180 = - V_240 ;
for ( V_236 = 0 ; V_236 < 2 ; V_236 ++ ) {
F_132 ( & V_4 ) ;
F_186 (fmt, &formats, lh) {
int (* V_178)( struct V_8 * ) = V_2 -> V_241 ;
if ( ! V_178 )
continue;
if ( ! F_187 ( V_2 -> V_7 ) )
continue;
F_133 ( & V_4 ) ;
V_9 -> V_235 = V_234 + 1 ;
V_180 = V_178 ( V_9 ) ;
V_9 -> V_235 = V_234 ;
if ( V_180 >= 0 ) {
if ( V_234 == 0 ) {
F_188 ( V_13 , V_237 , V_9 ) ;
F_189 ( V_242 , V_238 ) ;
}
F_9 ( V_2 ) ;
F_190 ( V_9 -> V_106 ) ;
if ( V_9 -> V_106 )
F_80 ( V_9 -> V_106 ) ;
V_9 -> V_106 = NULL ;
V_13 -> V_243 = 1 ;
F_191 ( V_13 ) ;
return V_180 ;
}
F_132 ( & V_4 ) ;
F_9 ( V_2 ) ;
if ( V_180 != - V_244 || V_9 -> V_12 == NULL )
break;
if ( ! V_9 -> V_106 ) {
F_133 ( & V_4 ) ;
return V_180 ;
}
}
F_133 ( & V_4 ) ;
#ifdef F_192
if ( V_180 != - V_244 || V_9 -> V_12 == NULL ) {
break;
} else {
#define F_193 ( T_10 ) (((c)=='\t') || ((c)=='\n') || (0x20<=(c) && (c)<=0x7e))
if ( F_193 ( V_9 -> V_175 [ 0 ] ) &&
F_193 ( V_9 -> V_175 [ 1 ] ) &&
F_193 ( V_9 -> V_175 [ 2 ] ) &&
F_193 ( V_9 -> V_175 [ 3 ] ) )
break;
if ( V_236 )
break;
F_194 ( L_1 , * ( unsigned short * ) ( & V_9 -> V_175 [ 2 ] ) ) ;
}
#else
break;
#endif
}
return V_180 ;
}
static int F_195 ( const char * V_108 ,
struct V_53 V_54 ,
struct V_53 V_245 )
{
struct V_8 * V_9 ;
struct V_106 * V_106 ;
struct V_246 * V_247 ;
bool V_248 ;
int V_180 ;
const struct V_198 * V_198 = F_196 () ;
if ( ( V_13 -> V_182 & V_249 ) &&
F_125 ( & V_198 -> V_250 -> V_251 ) > V_25 ( V_252 ) ) {
V_180 = - V_150 ;
goto V_253;
}
V_13 -> V_182 &= ~ V_249 ;
V_180 = F_197 ( & V_247 ) ;
if ( V_180 )
goto V_253;
V_180 = - V_36 ;
V_9 = F_198 ( sizeof( * V_9 ) , V_35 ) ;
if ( ! V_9 )
goto V_254;
V_180 = F_155 ( V_9 ) ;
if ( V_180 )
goto V_255;
V_180 = F_170 ( V_9 ) ;
if ( V_180 < 0 )
goto V_255;
V_248 = V_180 ;
V_13 -> V_256 = 1 ;
V_106 = F_74 ( V_108 ) ;
V_180 = F_199 ( V_106 ) ;
if ( F_48 ( V_106 ) )
goto V_257;
F_200 () ;
V_9 -> V_106 = V_106 ;
V_9 -> V_108 = V_108 ;
V_9 -> V_206 = V_108 ;
V_180 = F_37 ( V_9 ) ;
if ( V_180 )
goto V_258;
V_9 -> V_64 = F_47 ( V_54 , V_259 ) ;
if ( ( V_180 = V_9 -> V_64 ) < 0 )
goto V_69;
V_9 -> V_260 = F_47 ( V_245 , V_259 ) ;
if ( ( V_180 = V_9 -> V_260 ) < 0 )
goto V_69;
V_180 = F_174 ( V_9 ) ;
if ( V_180 < 0 )
goto V_69;
V_180 = F_57 ( 1 , & V_9 -> V_108 , V_9 ) ;
if ( V_180 < 0 )
goto V_69;
V_9 -> V_99 = V_9 -> V_47 ;
V_180 = F_51 ( V_9 -> V_260 , V_245 , V_9 ) ;
if ( V_180 < 0 )
goto V_69;
V_180 = F_51 ( V_9 -> V_64 , V_54 , V_9 ) ;
if ( V_180 < 0 )
goto V_69;
V_180 = F_181 ( V_9 ) ;
if ( V_180 < 0 )
goto V_69;
V_13 -> V_215 -> V_218 = 0 ;
V_13 -> V_256 = 0 ;
F_201 ( V_13 ) ;
F_159 ( V_9 ) ;
if ( V_247 )
F_202 ( V_247 ) ;
return V_180 ;
V_69:
if ( V_9 -> V_12 ) {
F_11 ( V_9 , 0 ) ;
F_97 ( V_9 -> V_12 ) ;
}
V_258:
if ( V_9 -> V_106 ) {
F_190 ( V_9 -> V_106 ) ;
F_80 ( V_9 -> V_106 ) ;
}
V_257:
if ( V_248 )
V_13 -> V_215 -> V_218 = 0 ;
V_13 -> V_256 = 0 ;
V_255:
F_159 ( V_9 ) ;
V_254:
if ( V_247 )
F_203 ( V_247 ) ;
V_253:
return V_180 ;
}
int F_204 ( const char * V_108 ,
const char T_1 * const T_1 * V_73 ,
const char T_1 * const T_1 * V_261 )
{
struct V_53 V_54 = { . V_59 . V_56 = V_73 } ;
struct V_53 V_245 = { . V_59 . V_56 = V_261 } ;
return F_195 ( V_108 , V_54 , V_245 ) ;
}
static int F_205 ( const char * V_108 ,
const T_2 T_1 * V_73 ,
const T_2 T_1 * V_261 )
{
struct V_53 V_54 = {
. V_57 = true ,
. V_59 . V_58 = V_73 ,
} ;
struct V_53 V_245 = {
. V_57 = true ,
. V_59 . V_58 = V_261 ,
} ;
return F_195 ( V_108 , V_54 , V_245 ) ;
}
void F_206 ( struct V_1 * V_262 )
{
struct V_11 * V_12 = V_13 -> V_12 ;
if ( V_12 -> V_263 )
F_10 ( V_12 -> V_263 -> V_7 ) ;
V_12 -> V_263 = V_262 ;
if ( V_262 )
F_207 ( V_262 -> V_7 ) ;
}
void F_152 ( struct V_11 * V_12 , int V_264 )
{
switch ( V_264 ) {
case V_265 :
F_208 ( V_266 , & V_12 -> V_182 ) ;
F_209 () ;
F_208 ( V_267 , & V_12 -> V_182 ) ;
break;
case V_194 :
F_210 ( V_266 , & V_12 -> V_182 ) ;
F_209 () ;
F_208 ( V_267 , & V_12 -> V_182 ) ;
break;
case V_268 :
F_210 ( V_267 , & V_12 -> V_182 ) ;
F_209 () ;
F_210 ( V_266 , & V_12 -> V_182 ) ;
break;
}
}
int F_211 ( unsigned long V_269 )
{
int V_20 ;
V_20 = V_269 & V_270 ;
return ( V_20 > V_194 ) ? V_268 : V_20 ;
}
int F_167 ( struct V_11 * V_12 )
{
return F_211 ( V_12 -> V_182 ) ;
}
T_11 long F_212 ( const char T_1 * V_108 ,
const T_2 T_1 * V_54 ,
const T_2 T_1 * V_245 )
{
struct V_108 * V_271 = F_213 ( V_108 ) ;
int error = F_199 ( V_271 ) ;
if ( ! F_48 ( V_271 ) ) {
error = F_205 ( V_271 -> V_107 , V_54 , V_245 ) ;
F_214 ( V_271 ) ;
}
return error ;
}
