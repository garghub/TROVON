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
V_28 = F_18 ( V_21 , V_17 -> V_20 , V_26 , 1 , V_27 ,
1 , & V_25 , NULL ) ;
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
. V_129 = V_130 ,
. V_131 = V_132 ,
. V_133 = V_134 ,
} ;
if ( ( V_122 & ~ ( V_135 | V_136 ) ) != 0 )
return F_47 ( - V_137 ) ;
if ( V_122 & V_135 )
V_124 . V_133 &= ~ V_134 ;
if ( V_122 & V_136 )
V_124 . V_133 |= V_138 ;
V_118 = F_77 ( V_119 , V_121 , & V_124 ) ;
if ( F_50 ( V_118 ) )
goto V_78;
V_40 = - V_139 ;
if ( ! F_78 ( F_79 ( V_118 ) -> V_140 ) )
goto exit;
if ( F_12 ( & V_118 -> V_141 ) )
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
struct V_118 * V_142 = F_85 ( V_120 ) ;
if ( ! F_50 ( V_120 ) ) {
V_142 = F_76 ( V_143 , V_120 , 0 ) ;
F_86 ( V_120 ) ;
}
return V_142 ;
}
int F_87 ( struct V_118 * V_118 , T_4 V_79 ,
char * V_144 , unsigned long F_49 )
{
T_3 V_145 ;
T_4 V_26 = V_79 ;
int V_146 ;
V_145 = F_60 () ;
F_61 ( F_88 () ) ;
V_146 = F_89 ( V_118 , ( void T_1 * ) V_144 , F_49 , & V_26 ) ;
F_61 ( V_145 ) ;
return V_146 ;
}
int F_90 ( struct V_118 * V_118 , void * * V_147 , T_4 * V_30 ,
T_4 V_148 , enum V_149 V_150 )
{
T_4 V_151 , V_26 ;
T_5 V_152 = 0 ;
int V_28 ;
if ( ! F_78 ( F_79 ( V_118 ) -> V_140 ) || V_148 < 0 )
return - V_137 ;
V_28 = F_91 ( V_118 , V_150 ) ;
if ( V_28 )
return V_28 ;
V_151 = F_92 ( F_79 ( V_118 ) ) ;
if ( V_148 > 0 && V_151 > V_148 )
return - V_153 ;
if ( V_151 <= 0 )
return - V_137 ;
* V_147 = F_93 ( V_151 ) ;
if ( ! * V_147 )
return - V_44 ;
V_26 = 0 ;
while ( V_26 < V_151 ) {
V_152 = F_87 ( V_118 , V_26 , ( char * ) ( * V_147 ) + V_26 ,
V_151 - V_26 ) ;
if ( V_152 < 0 ) {
V_28 = V_152 ;
goto V_78;
}
if ( V_152 == 0 )
break;
V_26 += V_152 ;
}
if ( V_26 != V_151 ) {
V_28 = - V_154 ;
goto V_78;
}
V_28 = F_94 ( V_118 , * V_147 , V_151 , V_150 ) ;
if ( ! V_28 )
* V_30 = V_26 ;
V_78:
if ( V_28 < 0 ) {
F_95 ( * V_147 ) ;
* V_147 = NULL ;
}
return V_28 ;
}
int F_96 ( char * V_9 , void * * V_147 , T_4 * V_30 ,
T_4 V_148 , enum V_149 V_150 )
{
struct V_118 * V_118 ;
int V_28 ;
if ( ! V_9 || ! * V_9 )
return - V_137 ;
V_118 = F_97 ( V_9 , V_127 , 0 ) ;
if ( F_50 ( V_118 ) )
return F_98 ( V_118 ) ;
V_28 = F_90 ( V_118 , V_147 , V_30 , V_148 , V_150 ) ;
F_82 ( V_118 ) ;
return V_28 ;
}
int F_99 ( int V_119 , void * * V_147 , T_4 * V_30 , T_4 V_148 ,
enum V_149 V_150 )
{
struct V_119 V_142 = F_100 ( V_119 ) ;
int V_28 = - V_155 ;
if ( ! V_142 . V_118 )
goto V_78;
V_28 = F_90 ( V_142 . V_118 , V_147 , V_30 , V_148 , V_150 ) ;
V_78:
F_101 ( V_142 ) ;
return V_28 ;
}
T_5 F_102 ( struct V_118 * V_118 , unsigned long V_144 , T_4 V_26 , T_6 V_57 )
{
T_5 V_156 = F_89 ( V_118 , ( void T_1 * ) V_144 , V_57 , & V_26 ) ;
if ( V_156 > 0 )
F_103 ( V_144 , V_144 + V_57 ) ;
return V_156 ;
}
static int F_104 ( struct V_19 * V_20 )
{
struct V_157 * V_158 ;
struct V_19 * V_159 , * V_160 ;
V_158 = V_21 ;
V_159 = V_21 -> V_20 ;
F_105 ( V_158 , V_159 ) ;
if ( V_159 ) {
F_106 ( V_159 ) ;
F_107 ( & V_159 -> V_45 ) ;
if ( F_45 ( V_159 -> V_161 ) ) {
F_108 ( & V_159 -> V_45 ) ;
return - V_162 ;
}
}
F_109 ( V_158 ) ;
V_160 = V_158 -> V_160 ;
V_158 -> V_20 = V_20 ;
V_158 -> V_160 = V_20 ;
F_110 ( V_160 , V_20 ) ;
V_158 -> V_20 -> V_163 = 0 ;
F_111 ( V_158 ) ;
F_112 ( V_158 ) ;
if ( V_159 ) {
F_108 ( & V_159 -> V_45 ) ;
F_2 ( V_160 != V_159 ) ;
F_113 ( & V_158 -> signal -> V_164 , V_159 ) ;
F_114 ( V_159 ) ;
F_115 ( V_159 ) ;
return 0 ;
}
F_42 ( V_160 ) ;
return 0 ;
}
static int F_116 ( struct V_157 * V_158 )
{
struct V_165 * V_166 = V_158 -> signal ;
struct V_167 * V_168 = V_158 -> V_169 ;
T_7 * V_170 = & V_168 -> V_171 ;
if ( F_117 ( V_158 ) )
goto V_172;
F_118 ( V_170 ) ;
if ( F_119 ( V_166 ) ) {
F_120 ( V_170 ) ;
return - V_173 ;
}
V_166 -> V_174 = V_158 ;
V_166 -> V_175 = F_121 ( V_158 ) ;
if ( ! F_122 ( V_158 ) )
V_166 -> V_175 -- ;
while ( V_166 -> V_175 ) {
F_123 ( V_176 ) ;
F_120 ( V_170 ) ;
F_124 () ;
if ( F_45 ( F_125 ( V_158 ) ) )
goto V_177;
F_118 ( V_170 ) ;
}
F_120 ( V_170 ) ;
if ( ! F_122 ( V_158 ) ) {
struct V_157 * V_178 = V_158 -> V_179 ;
for (; ; ) {
F_126 ( V_158 ) ;
F_127 ( & V_180 ) ;
V_166 -> V_175 = - 1 ;
if ( F_128 ( V_178 -> V_181 ) )
break;
F_123 ( V_176 ) ;
F_129 ( & V_180 ) ;
F_130 ( V_158 ) ;
F_124 () ;
if ( F_45 ( F_125 ( V_158 ) ) )
goto V_177;
}
V_158 -> V_182 = V_178 -> V_182 ;
V_158 -> V_183 = V_178 -> V_183 ;
F_2 ( ! F_131 ( V_178 , V_158 ) ) ;
F_2 ( F_132 ( V_158 ) ) ;
V_158 -> V_184 = V_178 -> V_184 ;
F_133 ( V_158 , V_185 , F_134 ( V_178 ) ) ;
F_135 ( V_178 , V_158 , V_186 ) ;
F_135 ( V_178 , V_158 , V_187 ) ;
F_136 ( & V_178 -> V_188 , & V_158 -> V_188 ) ;
F_137 ( & V_178 -> V_189 , & V_158 -> V_189 ) ;
V_158 -> V_179 = V_158 ;
V_178 -> V_179 = V_158 ;
V_158 -> V_190 = V_191 ;
V_178 -> V_190 = - 1 ;
F_2 ( V_178 -> V_181 != V_192 ) ;
V_178 -> V_181 = V_193 ;
if ( F_45 ( V_178 -> V_194 ) )
F_138 ( V_178 , V_178 -> V_195 ) ;
F_129 ( & V_180 ) ;
F_130 ( V_158 ) ;
F_139 ( V_178 ) ;
}
V_166 -> V_174 = NULL ;
V_166 -> V_175 = 0 ;
V_172:
V_158 -> V_190 = V_191 ;
F_140 ( V_166 ) ;
F_141 () ;
if ( F_142 ( & V_168 -> F_49 ) != 1 ) {
struct V_167 * V_196 ;
V_196 = F_143 ( V_197 , V_43 ) ;
if ( ! V_196 )
return - V_44 ;
F_144 ( & V_196 -> F_49 , 1 ) ;
memcpy ( V_196 -> V_198 , V_168 -> V_198 ,
sizeof( V_196 -> V_198 ) ) ;
F_127 ( & V_180 ) ;
F_145 ( & V_168 -> V_171 ) ;
F_146 ( V_158 -> V_169 , V_196 ) ;
F_147 ( & V_168 -> V_171 ) ;
F_129 ( & V_180 ) ;
F_148 ( V_168 ) ;
}
F_2 ( ! F_122 ( V_158 ) ) ;
return 0 ;
V_177:
F_149 ( & V_180 ) ;
V_166 -> V_174 = NULL ;
V_166 -> V_175 = 0 ;
F_150 ( & V_180 ) ;
return - V_173 ;
}
char * F_151 ( char * V_147 , struct V_157 * V_158 )
{
F_109 ( V_158 ) ;
strncpy ( V_147 , V_158 -> V_199 , sizeof( V_158 -> V_199 ) ) ;
F_112 ( V_158 ) ;
return V_147 ;
}
void F_152 ( struct V_157 * V_158 , const char * V_147 , bool V_111 )
{
F_109 ( V_158 ) ;
F_153 ( V_158 , V_147 ) ;
F_154 ( V_158 -> V_199 , V_147 , sizeof( V_158 -> V_199 ) ) ;
F_112 ( V_158 ) ;
F_155 ( V_158 , V_111 ) ;
}
int F_156 ( struct V_16 * V_17 )
{
int V_200 ;
V_200 = F_116 ( V_21 ) ;
if ( V_200 )
goto V_78;
F_157 ( V_17 -> V_20 , V_17 -> V_118 ) ;
F_13 ( V_17 , 0 ) ;
V_200 = F_104 ( V_17 -> V_20 ) ;
if ( V_200 )
goto V_78;
V_17 -> V_20 = NULL ;
F_61 ( V_201 ) ;
V_21 -> V_122 &= ~ ( V_202 | V_203 | V_204 |
V_205 | V_206 ) ;
F_158 () ;
V_21 -> V_207 &= ~ V_17 -> V_208 ;
return 0 ;
V_78:
return V_200 ;
}
void F_159 ( struct V_16 * V_17 , struct V_118 * V_118 )
{
if ( F_160 ( F_79 ( V_118 ) , V_209 ) < 0 )
V_17 -> V_210 |= V_211 ;
}
void F_161 ( struct V_16 * V_17 )
{
F_162 ( V_21 -> V_20 ) ;
V_21 -> V_212 = V_21 -> V_213 = 0 ;
if ( F_163 ( F_164 () , F_165 () ) && F_166 ( F_167 () , F_168 () ) )
F_169 ( V_21 -> V_20 , V_214 ) ;
else
F_169 ( V_21 -> V_20 , V_215 ) ;
F_170 () ;
F_152 ( V_21 , F_171 ( V_17 -> V_120 ) , true ) ;
V_21 -> V_20 -> V_216 = V_217 ;
if ( ! F_163 ( V_17 -> V_218 -> V_219 , F_164 () ) ||
! F_166 ( V_17 -> V_218 -> V_220 , F_167 () ) ) {
V_21 -> V_221 = 0 ;
} else {
F_159 ( V_17 , V_17 -> V_118 ) ;
if ( V_17 -> V_210 & V_211 )
F_169 ( V_21 -> V_20 , V_215 ) ;
}
V_21 -> V_222 ++ ;
F_172 ( V_21 , 0 ) ;
F_173 ( V_21 -> V_223 ) ;
}
int F_174 ( struct V_16 * V_17 )
{
if ( F_175 ( & V_21 -> signal -> V_224 ) )
return - V_225 ;
V_17 -> V_218 = F_176 () ;
if ( F_128 ( V_17 -> V_218 ) )
return 0 ;
F_177 ( & V_21 -> signal -> V_224 ) ;
return - V_44 ;
}
static void F_178 ( struct V_16 * V_17 )
{
F_23 ( V_17 ) ;
if ( V_17 -> V_218 ) {
F_177 ( & V_21 -> signal -> V_224 ) ;
F_179 ( V_17 -> V_218 ) ;
}
if ( V_17 -> V_118 ) {
F_180 ( V_17 -> V_118 ) ;
F_82 ( V_17 -> V_118 ) ;
}
if ( V_17 -> V_226 != V_17 -> V_120 )
F_181 ( V_17 -> V_226 ) ;
F_181 ( V_17 ) ;
}
int F_182 ( char * V_226 , struct V_16 * V_17 )
{
if ( V_17 -> V_226 != V_17 -> V_120 )
F_181 ( V_17 -> V_226 ) ;
V_17 -> V_226 = F_183 ( V_226 , V_43 ) ;
if ( ! V_17 -> V_226 )
return - V_44 ;
return 0 ;
}
void F_184 ( struct V_16 * V_17 )
{
F_185 ( V_17 ) ;
F_186 ( V_17 -> V_218 ) ;
V_17 -> V_218 = NULL ;
if ( F_187 ( V_21 -> V_20 ) != V_214 )
F_188 ( V_21 ) ;
F_189 ( V_17 ) ;
F_177 ( & V_21 -> signal -> V_224 ) ;
}
static void F_190 ( struct V_16 * V_17 )
{
struct V_157 * V_56 = V_21 , * V_227 ;
unsigned V_228 ;
if ( V_56 -> V_194 ) {
if ( V_56 -> V_194 & V_229 )
V_17 -> V_230 |= V_231 ;
else
V_17 -> V_230 |= V_232 ;
}
if ( F_191 ( V_21 ) )
V_17 -> V_230 |= V_233 ;
V_227 = V_56 ;
V_228 = 1 ;
F_145 ( & V_56 -> V_234 -> V_170 ) ;
F_192 () ;
F_193 (p, t) {
if ( V_227 -> V_234 == V_56 -> V_234 )
V_228 ++ ;
}
F_194 () ;
if ( V_56 -> V_234 -> V_235 > V_228 )
V_17 -> V_230 |= V_236 ;
else
V_56 -> V_234 -> V_237 = 1 ;
F_147 ( & V_56 -> V_234 -> V_170 ) ;
}
static void F_195 ( struct V_16 * V_17 )
{
struct V_238 * V_238 ;
unsigned int V_239 ;
T_8 V_219 ;
T_9 V_220 ;
V_17 -> V_218 -> V_240 = F_164 () ;
V_17 -> V_218 -> V_241 = F_167 () ;
if ( V_17 -> V_118 -> V_141 . V_10 -> V_11 & V_242 )
return;
if ( F_191 ( V_21 ) )
return;
V_238 = F_79 ( V_17 -> V_118 ) ;
V_239 = F_196 ( V_238 -> V_140 ) ;
if ( ! ( V_239 & ( V_243 | V_244 ) ) )
return;
F_197 ( V_238 ) ;
V_239 = V_238 -> V_140 ;
V_219 = V_238 -> V_245 ;
V_220 = V_238 -> V_246 ;
F_198 ( V_238 ) ;
if ( ! F_199 ( V_17 -> V_218 -> V_247 , V_219 ) ||
! F_200 ( V_17 -> V_218 -> V_247 , V_220 ) )
return;
if ( V_239 & V_243 ) {
V_17 -> V_208 |= V_248 ;
V_17 -> V_218 -> V_240 = V_219 ;
}
if ( ( V_239 & ( V_244 | V_249 ) ) == ( V_244 | V_249 ) ) {
V_17 -> V_208 |= V_248 ;
V_17 -> V_218 -> V_241 = V_220 ;
}
}
int F_201 ( struct V_16 * V_17 )
{
int V_200 ;
F_195 ( V_17 ) ;
V_200 = F_202 ( V_17 ) ;
if ( V_200 )
return V_200 ;
V_17 -> V_250 = 1 ;
memset ( V_17 -> V_147 , 0 , V_251 ) ;
return F_87 ( V_17 -> V_118 , 0 , V_17 -> V_147 , V_251 ) ;
}
int F_203 ( struct V_16 * V_17 )
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
V_75 = F_204 ( V_25 ) ;
for (; V_79 < V_35 && V_75 [ V_79 ] ;
V_79 ++ , V_17 -> V_56 ++ )
;
F_205 ( V_75 ) ;
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
int F_206 ( struct V_16 * V_17 )
{
bool V_252 = F_207 ( V_253 ) ;
struct V_1 * V_2 ;
int V_200 ;
if ( V_17 -> V_254 > 5 )
return - V_255 ;
V_200 = F_208 ( V_17 ) ;
if ( V_200 )
return V_200 ;
V_200 = - V_256 ;
V_257:
F_149 ( & V_5 ) ;
F_209 (fmt, &formats, lh) {
if ( ! F_210 ( V_2 -> V_8 ) )
continue;
F_150 ( & V_5 ) ;
V_17 -> V_254 ++ ;
V_200 = V_2 -> V_4 ( V_17 ) ;
F_149 ( & V_5 ) ;
F_10 ( V_2 ) ;
V_17 -> V_254 -- ;
if ( V_200 < 0 && ! V_17 -> V_20 ) {
F_150 ( & V_5 ) ;
F_211 ( V_258 , V_21 ) ;
return V_200 ;
}
if ( V_200 != - V_259 || ! V_17 -> V_118 ) {
F_150 ( & V_5 ) ;
return V_200 ;
}
}
F_150 ( & V_5 ) ;
if ( V_252 ) {
if ( F_212 ( V_17 -> V_147 [ 0 ] ) && F_212 ( V_17 -> V_147 [ 1 ] ) &&
F_212 ( V_17 -> V_147 [ 2 ] ) && F_212 ( V_17 -> V_147 [ 3 ] ) )
return V_200 ;
if ( F_213 ( L_1 , * ( V_260 * ) ( V_17 -> V_147 + 2 ) ) < 0 )
return V_200 ;
V_252 = false ;
goto V_257;
}
return V_200 ;
}
static int F_214 ( struct V_16 * V_17 )
{
T_10 V_261 , V_262 ;
int V_28 ;
V_261 = V_21 -> V_184 ;
F_192 () ;
V_262 = F_215 ( V_21 , F_216 ( V_21 -> V_195 ) ) ;
F_194 () ;
V_28 = F_206 ( V_17 ) ;
if ( V_28 >= 0 ) {
F_217 ( V_17 ) ;
F_218 ( V_21 , V_261 , V_17 ) ;
F_219 ( V_263 , V_262 ) ;
F_220 ( V_21 ) ;
}
return V_28 ;
}
static int F_221 ( int V_119 , struct V_120 * V_120 ,
struct V_62 V_63 ,
struct V_62 V_264 ,
int V_122 )
{
char * V_265 = NULL ;
struct V_16 * V_17 ;
struct V_118 * V_118 ;
struct V_266 * V_267 ;
int V_200 ;
if ( F_50 ( V_120 ) )
return F_98 ( V_120 ) ;
if ( ( V_21 -> V_122 & V_268 ) &&
F_142 ( & F_222 () -> V_269 ) > V_33 ( V_270 ) ) {
V_200 = - V_173 ;
goto V_271;
}
V_21 -> V_122 &= ~ V_268 ;
V_200 = F_223 ( & V_267 ) ;
if ( V_200 )
goto V_271;
V_200 = - V_44 ;
V_17 = F_224 ( sizeof( * V_17 ) , V_43 ) ;
if ( ! V_17 )
goto V_272;
V_200 = F_174 ( V_17 ) ;
if ( V_200 )
goto V_273;
F_190 ( V_17 ) ;
V_21 -> V_274 = 1 ;
V_118 = F_76 ( V_119 , V_120 , V_122 ) ;
V_200 = F_98 ( V_118 ) ;
if ( F_50 ( V_118 ) )
goto V_275;
F_225 () ;
V_17 -> V_118 = V_118 ;
if ( V_119 == V_143 || V_120 -> V_121 [ 0 ] == '/' ) {
V_17 -> V_120 = V_120 -> V_121 ;
} else {
if ( V_120 -> V_121 [ 0 ] == '\0' )
V_265 = F_226 ( V_276 , L_2 , V_119 ) ;
else
V_265 = F_226 ( V_276 , L_3 ,
V_119 , V_120 -> V_121 ) ;
if ( ! V_265 ) {
V_200 = - V_44 ;
goto V_275;
}
if ( F_227 ( V_119 , F_228 ( V_21 -> V_223 -> V_277 ) ) )
V_17 -> V_210 |= V_278 ;
V_17 -> V_120 = V_265 ;
}
V_17 -> V_226 = V_17 -> V_120 ;
V_200 = F_40 ( V_17 ) ;
if ( V_200 )
goto V_275;
V_17 -> V_73 = F_49 ( V_63 , V_279 ) ;
if ( ( V_200 = V_17 -> V_73 ) < 0 )
goto V_78;
V_17 -> V_280 = F_49 ( V_264 , V_279 ) ;
if ( ( V_200 = V_17 -> V_280 ) < 0 )
goto V_78;
V_200 = F_201 ( V_17 ) ;
if ( V_200 < 0 )
goto V_78;
V_200 = F_59 ( 1 , & V_17 -> V_120 , V_17 ) ;
if ( V_200 < 0 )
goto V_78;
V_17 -> V_111 = V_17 -> V_56 ;
V_200 = F_53 ( V_17 -> V_280 , V_264 , V_17 ) ;
if ( V_200 < 0 )
goto V_78;
V_200 = F_53 ( V_17 -> V_73 , V_63 , V_17 ) ;
if ( V_200 < 0 )
goto V_78;
V_200 = F_214 ( V_17 ) ;
if ( V_200 < 0 )
goto V_78;
V_21 -> V_234 -> V_237 = 0 ;
V_21 -> V_274 = 0 ;
F_229 ( V_21 ) ;
F_230 ( V_21 ) ;
F_178 ( V_17 ) ;
F_181 ( V_265 ) ;
F_86 ( V_120 ) ;
if ( V_267 )
F_231 ( V_267 ) ;
return V_200 ;
V_78:
if ( V_17 -> V_20 ) {
F_13 ( V_17 , 0 ) ;
F_115 ( V_17 -> V_20 ) ;
}
V_275:
V_21 -> V_234 -> V_237 = 0 ;
V_21 -> V_274 = 0 ;
V_273:
F_178 ( V_17 ) ;
F_181 ( V_265 ) ;
V_272:
if ( V_267 )
F_232 ( V_267 ) ;
V_271:
F_86 ( V_120 ) ;
return V_200 ;
}
int F_233 ( struct V_120 * V_120 ,
const char T_1 * const T_1 * V_82 ,
const char T_1 * const T_1 * V_281 )
{
struct V_62 V_63 = { . V_68 . V_65 = V_82 } ;
struct V_62 V_264 = { . V_68 . V_65 = V_281 } ;
return F_221 ( V_143 , V_120 , V_63 , V_264 , 0 ) ;
}
int F_234 ( int V_119 , struct V_120 * V_120 ,
const char T_1 * const T_1 * V_82 ,
const char T_1 * const T_1 * V_281 ,
int V_122 )
{
struct V_62 V_63 = { . V_68 . V_65 = V_82 } ;
struct V_62 V_264 = { . V_68 . V_65 = V_281 } ;
return F_221 ( V_119 , V_120 , V_63 , V_264 , V_122 ) ;
}
static int F_235 ( struct V_120 * V_120 ,
const T_2 T_1 * V_82 ,
const T_2 T_1 * V_281 )
{
struct V_62 V_63 = {
. V_66 = true ,
. V_68 . V_67 = V_82 ,
} ;
struct V_62 V_264 = {
. V_66 = true ,
. V_68 . V_67 = V_281 ,
} ;
return F_221 ( V_143 , V_120 , V_63 , V_264 , 0 ) ;
}
static int F_236 ( int V_119 , struct V_120 * V_120 ,
const T_2 T_1 * V_82 ,
const T_2 T_1 * V_281 ,
int V_122 )
{
struct V_62 V_63 = {
. V_66 = true ,
. V_68 . V_67 = V_82 ,
} ;
struct V_62 V_264 = {
. V_66 = true ,
. V_68 . V_67 = V_281 ,
} ;
return F_221 ( V_119 , V_120 , V_63 , V_264 , V_122 ) ;
}
void F_237 ( struct V_1 * V_282 )
{
struct V_19 * V_20 = V_21 -> V_20 ;
if ( V_20 -> V_283 )
F_11 ( V_20 -> V_283 -> V_8 ) ;
V_20 -> V_283 = V_282 ;
if ( V_282 )
F_238 ( V_282 -> V_8 ) ;
}
void F_169 ( struct V_19 * V_20 , int V_284 )
{
unsigned long V_285 , V_282 ;
if ( F_3 ( ( unsigned ) V_284 > V_286 ) )
return;
do {
V_285 = F_19 ( V_20 -> V_122 ) ;
V_282 = ( V_285 & ~ V_287 ) | V_284 ;
} while ( F_239 ( & V_20 -> V_122 , V_285 , V_282 ) != V_285 );
}
