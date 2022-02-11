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
unsigned int V_29 = V_30 ;
#ifdef F_16
if ( V_27 ) {
V_28 = F_17 ( V_17 -> V_31 , V_26 ) ;
if ( V_28 < 0 )
return NULL ;
}
#endif
if ( V_27 )
V_29 |= V_32 ;
V_28 = F_18 ( V_21 , V_17 -> V_20 , V_26 , 1 , V_29 ,
& V_25 , NULL , NULL ) ;
if ( V_28 <= 0 )
return NULL ;
if ( V_27 ) {
unsigned long V_33 = V_17 -> V_31 -> V_34 - V_17 -> V_31 -> V_35 ;
unsigned long V_36 , V_37 ;
V_36 = ( V_17 -> V_38 + V_17 -> V_39 ) * sizeof( void * ) ;
if ( V_36 > V_40 - V_33 )
goto V_41;
V_33 += V_36 ;
F_13 ( V_17 , V_33 / V_42 ) ;
if ( V_33 <= V_43 )
return V_25 ;
V_37 = V_44 / 4 * 3 ;
V_37 = F_19 ( V_37 , F_20 ( V_45 ) / 4 ) ;
if ( V_33 > V_37 )
goto V_41;
}
return V_25 ;
V_41:
F_21 ( V_25 ) ;
return NULL ;
}
static void F_22 ( struct V_25 * V_25 )
{
F_21 ( V_25 ) ;
}
static void F_23 ( struct V_16 * V_17 )
{
}
static void F_24 ( struct V_16 * V_17 , unsigned long V_26 ,
struct V_25 * V_25 )
{
F_25 ( V_17 -> V_31 , V_26 , F_26 ( V_25 ) ) ;
}
static int F_27 ( struct V_16 * V_17 )
{
int V_46 ;
struct V_47 * V_31 = NULL ;
struct V_19 * V_20 = V_17 -> V_20 ;
V_17 -> V_31 = V_31 = F_28 ( V_48 , V_49 ) ;
if ( ! V_31 )
return - V_50 ;
if ( F_29 ( & V_20 -> V_51 ) ) {
V_46 = - V_52 ;
goto V_53;
}
V_31 -> V_54 = V_20 ;
F_30 ( V_55 & V_56 ) ;
V_31 -> V_34 = V_57 ;
V_31 -> V_35 = V_31 -> V_34 - V_42 ;
V_31 -> V_58 = V_59 | V_55 | V_56 ;
V_31 -> V_60 = F_31 ( V_31 -> V_58 ) ;
F_32 ( & V_31 -> V_61 ) ;
V_46 = F_33 ( V_20 , V_31 ) ;
if ( V_46 )
goto V_46;
V_20 -> V_62 = V_20 -> V_63 = 1 ;
F_34 ( V_20 , V_31 ) ;
F_35 ( & V_20 -> V_51 ) ;
V_17 -> V_64 = V_31 -> V_34 - sizeof( void * ) ;
return 0 ;
V_46:
F_35 ( & V_20 -> V_51 ) ;
V_53:
V_17 -> V_31 = NULL ;
F_36 ( V_48 , V_31 ) ;
return V_46 ;
}
static bool F_37 ( struct V_16 * V_17 , long V_65 )
{
return V_65 <= V_66 ;
}
static inline void F_13 ( struct V_16 * V_17 , unsigned long V_18 )
{
}
static struct V_25 * F_15 ( struct V_16 * V_17 , unsigned long V_26 ,
int V_27 )
{
struct V_25 * V_25 ;
V_25 = V_17 -> V_25 [ V_26 / V_42 ] ;
if ( ! V_25 && V_27 ) {
V_25 = F_38 ( V_67 | V_68 ) ;
if ( ! V_25 )
return NULL ;
V_17 -> V_25 [ V_26 / V_42 ] = V_25 ;
}
return V_25 ;
}
static void F_22 ( struct V_25 * V_25 )
{
}
static void F_39 ( struct V_16 * V_17 , int V_69 )
{
if ( V_17 -> V_25 [ V_69 ] ) {
F_40 ( V_17 -> V_25 [ V_69 ] ) ;
V_17 -> V_25 [ V_69 ] = NULL ;
}
}
static void F_23 ( struct V_16 * V_17 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_70 ; V_69 ++ )
F_39 ( V_17 , V_69 ) ;
}
static void F_24 ( struct V_16 * V_17 , unsigned long V_26 ,
struct V_25 * V_25 )
{
}
static int F_27 ( struct V_16 * V_17 )
{
V_17 -> V_64 = V_42 * V_70 - sizeof( void * ) ;
return 0 ;
}
static bool F_37 ( struct V_16 * V_17 , long V_65 )
{
return V_65 <= V_17 -> V_64 ;
}
static int F_41 ( struct V_16 * V_17 )
{
int V_46 ;
struct V_19 * V_20 = NULL ;
V_17 -> V_20 = V_20 = F_42 () ;
V_46 = - V_50 ;
if ( ! V_20 )
goto V_46;
V_46 = F_27 ( V_17 ) ;
if ( V_46 )
goto V_46;
return 0 ;
V_46:
if ( V_20 ) {
V_17 -> V_20 = NULL ;
F_43 ( V_20 ) ;
}
return V_46 ;
}
static const char T_1 * F_44 ( struct V_71 V_72 , int V_73 )
{
const char T_1 * V_74 ;
#ifdef F_45
if ( F_46 ( V_72 . V_75 ) ) {
T_2 V_76 ;
if ( F_47 ( V_76 , V_72 . V_77 . V_76 + V_73 ) )
return F_48 ( - V_78 ) ;
return F_49 ( V_76 ) ;
}
#endif
if ( F_47 ( V_74 , V_72 . V_77 . V_74 + V_73 ) )
return F_48 ( - V_78 ) ;
return V_74 ;
}
static int F_50 ( struct V_71 V_72 , int V_79 )
{
int V_69 = 0 ;
if ( V_72 . V_77 . V_74 != NULL ) {
for (; ; ) {
const char T_1 * V_64 = F_44 ( V_72 , V_69 ) ;
if ( ! V_64 )
break;
if ( F_51 ( V_64 ) )
return - V_78 ;
if ( V_69 >= V_79 )
return - V_80 ;
++ V_69 ;
if ( F_52 ( V_21 ) )
return - V_81 ;
F_53 () ;
}
}
return V_69 ;
}
static int F_54 ( int V_38 , struct V_71 V_72 ,
struct V_16 * V_17 )
{
struct V_25 * V_82 = NULL ;
char * V_83 = NULL ;
unsigned long V_84 = 0 ;
int V_28 ;
while ( V_38 -- > 0 ) {
const char T_1 * V_85 ;
int V_65 ;
unsigned long V_26 ;
V_28 = - V_78 ;
V_85 = F_44 ( V_72 , V_38 ) ;
if ( F_51 ( V_85 ) )
goto V_86;
V_65 = F_55 ( V_85 , V_66 ) ;
if ( ! V_65 )
goto V_86;
V_28 = - V_80 ;
if ( ! F_37 ( V_17 , V_65 ) )
goto V_86;
V_26 = V_17 -> V_64 ;
V_85 += V_65 ;
V_17 -> V_64 -= V_65 ;
while ( V_65 > 0 ) {
int V_87 , V_88 ;
if ( F_52 ( V_21 ) ) {
V_28 = - V_81 ;
goto V_86;
}
F_53 () ;
V_87 = V_26 % V_42 ;
if ( V_87 == 0 )
V_87 = V_42 ;
V_88 = V_87 ;
if ( V_88 > V_65 )
V_88 = V_65 ;
V_87 -= V_88 ;
V_26 -= V_88 ;
V_85 -= V_88 ;
V_65 -= V_88 ;
if ( ! V_82 || V_84 != ( V_26 & V_89 ) ) {
struct V_25 * V_25 ;
V_25 = F_15 ( V_17 , V_26 , 1 ) ;
if ( ! V_25 ) {
V_28 = - V_80 ;
goto V_86;
}
if ( V_82 ) {
F_56 ( V_82 ) ;
F_57 ( V_82 ) ;
F_22 ( V_82 ) ;
}
V_82 = V_25 ;
V_83 = F_58 ( V_82 ) ;
V_84 = V_26 & V_89 ;
F_24 ( V_17 , V_84 , V_82 ) ;
}
if ( F_59 ( V_83 + V_87 , V_85 , V_88 ) ) {
V_28 = - V_78 ;
goto V_86;
}
}
}
V_28 = 0 ;
V_86:
if ( V_82 ) {
F_56 ( V_82 ) ;
F_57 ( V_82 ) ;
F_22 ( V_82 ) ;
}
return V_28 ;
}
int F_60 ( int V_38 , const char * const * V_90 ,
struct V_16 * V_17 )
{
int V_91 ;
T_3 V_92 = F_61 () ;
struct V_71 V_72 = {
. V_77 . V_74 = ( const char T_1 * const T_1 * ) V_90 ,
} ;
F_62 ( V_93 ) ;
V_91 = F_54 ( V_38 , V_72 , V_17 ) ;
F_62 ( V_92 ) ;
return V_91 ;
}
static int F_63 ( struct V_47 * V_31 , unsigned long V_94 )
{
struct V_19 * V_20 = V_31 -> V_54 ;
unsigned long V_95 = V_31 -> V_35 ;
unsigned long V_96 = V_31 -> V_34 ;
unsigned long V_97 = V_96 - V_95 ;
unsigned long V_98 = V_95 - V_94 ;
unsigned long V_99 = V_96 - V_94 ;
struct V_100 V_101 ;
F_2 ( V_98 > V_99 ) ;
if ( V_31 != F_64 ( V_20 , V_98 ) )
return - V_78 ;
if ( F_65 ( V_31 , V_98 , V_96 , V_31 -> V_102 , NULL ) )
return - V_50 ;
if ( V_97 != F_66 ( V_31 , V_95 ,
V_31 , V_98 , V_97 , false ) )
return - V_50 ;
F_67 () ;
F_68 ( & V_101 , V_20 , V_95 , V_96 ) ;
if ( V_99 > V_95 ) {
F_69 ( & V_101 , V_99 , V_96 , V_99 ,
V_31 -> V_103 ? V_31 -> V_103 -> V_35 : V_104 ) ;
} else {
F_69 ( & V_101 , V_95 , V_96 , V_99 ,
V_31 -> V_103 ? V_31 -> V_103 -> V_35 : V_104 ) ;
}
F_70 ( & V_101 , V_95 , V_96 ) ;
F_65 ( V_31 , V_98 , V_99 , V_31 -> V_102 , NULL ) ;
return 0 ;
}
int F_71 ( struct V_16 * V_17 ,
unsigned long V_105 ,
int V_106 )
{
unsigned long V_28 ;
unsigned long V_107 ;
struct V_19 * V_20 = V_21 -> V_20 ;
struct V_47 * V_31 = V_17 -> V_31 ;
struct V_47 * V_108 = NULL ;
unsigned long V_58 ;
unsigned long V_109 ;
unsigned long V_110 ;
unsigned long V_111 ;
unsigned long V_112 ;
#ifdef F_16
V_109 = F_72 ( V_45 ) ;
if ( V_109 > V_113 )
V_109 = V_113 ;
V_109 += ( V_114 << V_115 ) ;
if ( V_31 -> V_34 - V_31 -> V_35 > V_109 )
return - V_50 ;
V_109 = F_73 ( V_105 - V_109 ) ;
V_107 = V_31 -> V_35 - V_109 ;
V_20 -> V_116 = V_17 -> V_64 - V_107 ;
V_17 -> V_64 = V_31 -> V_34 - V_107 ;
#else
V_105 = F_74 ( V_105 ) ;
V_105 = F_73 ( V_105 ) ;
if ( F_46 ( V_105 < V_117 ) ||
F_46 ( V_31 -> V_34 - V_31 -> V_35 >= V_105 - V_117 ) )
return - V_50 ;
V_107 = V_31 -> V_34 - V_105 ;
V_17 -> V_64 -= V_107 ;
V_20 -> V_116 = V_17 -> V_64 ;
#endif
if ( V_17 -> V_118 )
V_17 -> V_118 -= V_107 ;
V_17 -> V_119 -= V_107 ;
if ( F_29 ( & V_20 -> V_51 ) )
return - V_52 ;
V_58 = V_55 ;
if ( F_46 ( V_106 == V_120 ) )
V_58 |= V_121 ;
else if ( V_106 == V_122 )
V_58 &= ~ V_121 ;
V_58 |= V_20 -> V_123 ;
V_58 |= V_56 ;
V_28 = F_75 ( V_31 , & V_108 , V_31 -> V_35 , V_31 -> V_34 ,
V_58 ) ;
if ( V_28 )
goto V_124;
F_2 ( V_108 != V_31 ) ;
if ( V_107 ) {
V_28 = F_63 ( V_31 , V_107 ) ;
if ( V_28 )
goto V_124;
}
V_31 -> V_58 &= ~ V_56 ;
V_111 = 131072UL ;
V_110 = V_31 -> V_34 - V_31 -> V_35 ;
V_112 = F_20 ( V_45 ) & V_89 ;
#ifdef F_16
if ( V_110 + V_111 > V_112 )
V_109 = V_31 -> V_35 + V_112 ;
else
V_109 = V_31 -> V_34 + V_111 ;
#else
if ( V_110 + V_111 > V_112 )
V_109 = V_31 -> V_34 - V_112 ;
else
V_109 = V_31 -> V_35 - V_111 ;
#endif
V_21 -> V_20 -> V_125 = V_17 -> V_64 ;
V_28 = F_76 ( V_31 , V_109 ) ;
if ( V_28 )
V_28 = - V_78 ;
V_124:
F_35 ( & V_20 -> V_51 ) ;
return V_28 ;
}
int F_77 ( struct V_16 * V_17 ,
unsigned long * V_126 )
{
unsigned long V_127 , V_128 , V_129 ;
int V_28 = 0 ;
V_128 = V_17 -> V_64 >> V_115 ;
V_129 = * V_126 ;
for ( V_127 = V_70 - 1 ; V_127 >= V_128 ; V_127 -- ) {
unsigned int V_87 = V_127 == V_128 ? V_17 -> V_64 & ~ V_89 : 0 ;
char * V_130 = F_58 ( V_17 -> V_25 [ V_127 ] ) + V_87 ;
V_129 -= V_42 - V_87 ;
if ( F_78 ( ( void * ) V_129 , V_130 , V_42 - V_87 ) != 0 )
V_28 = - V_78 ;
F_57 ( V_17 -> V_25 [ V_127 ] ) ;
if ( V_28 )
goto V_86;
}
* V_126 = V_129 ;
V_86:
return V_28 ;
}
static struct V_131 * F_79 ( int V_132 , struct V_133 * V_134 , int V_135 )
{
struct V_131 * V_131 ;
int V_46 ;
struct V_136 V_137 = {
. V_138 = V_139 | V_140 | V_141 ,
. V_142 = V_143 ,
. V_144 = V_145 ,
. V_146 = V_147 ,
} ;
if ( ( V_135 & ~ ( V_148 | V_149 ) ) != 0 )
return F_48 ( - V_150 ) ;
if ( V_135 & V_148 )
V_137 . V_146 &= ~ V_147 ;
if ( V_135 & V_149 )
V_137 . V_146 |= V_151 ;
V_131 = F_80 ( V_132 , V_134 , & V_137 ) ;
if ( F_51 ( V_131 ) )
goto V_86;
V_46 = - V_152 ;
if ( ! F_81 ( F_82 ( V_131 ) -> V_153 ) )
goto exit;
if ( F_12 ( & V_131 -> V_154 ) )
goto exit;
V_46 = F_83 ( V_131 ) ;
if ( V_46 )
goto exit;
if ( V_134 -> V_134 [ 0 ] != '\0' )
F_84 ( V_131 ) ;
V_86:
return V_131 ;
exit:
F_85 ( V_131 ) ;
return F_48 ( V_46 ) ;
}
struct V_131 * F_86 ( const char * V_134 )
{
struct V_133 * V_133 = F_87 ( V_134 ) ;
struct V_131 * V_155 = F_88 ( V_133 ) ;
if ( ! F_51 ( V_133 ) ) {
V_155 = F_79 ( V_156 , V_133 , 0 ) ;
F_89 ( V_133 ) ;
}
return V_155 ;
}
int F_90 ( struct V_131 * V_131 , void * * V_157 , T_4 * V_33 ,
T_4 V_158 , enum V_159 V_160 )
{
T_4 V_161 , V_26 ;
T_5 V_162 = 0 ;
int V_28 ;
if ( ! F_81 ( F_82 ( V_131 ) -> V_153 ) || V_158 < 0 )
return - V_150 ;
V_28 = F_91 ( V_131 , V_160 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_83 ( V_131 ) ;
if ( V_28 )
return V_28 ;
V_161 = F_92 ( F_82 ( V_131 ) ) ;
if ( V_158 > 0 && V_161 > V_158 ) {
V_28 = - V_163 ;
goto V_86;
}
if ( V_161 <= 0 ) {
V_28 = - V_150 ;
goto V_86;
}
if ( V_160 != V_164 )
* V_157 = F_93 ( V_161 ) ;
if ( ! * V_157 ) {
V_28 = - V_50 ;
goto V_86;
}
V_26 = 0 ;
while ( V_26 < V_161 ) {
V_162 = F_94 ( V_131 , * V_157 + V_26 , V_161 - V_26 , & V_26 ) ;
if ( V_162 < 0 ) {
V_28 = V_162 ;
goto V_86;
}
if ( V_162 == 0 )
break;
}
if ( V_26 != V_161 ) {
V_28 = - V_165 ;
goto V_166;
}
V_28 = F_95 ( V_131 , * V_157 , V_161 , V_160 ) ;
if ( ! V_28 )
* V_33 = V_26 ;
V_166:
if ( V_28 < 0 ) {
if ( V_160 != V_164 ) {
F_96 ( * V_157 ) ;
* V_157 = NULL ;
}
}
V_86:
F_97 ( V_131 ) ;
return V_28 ;
}
int F_98 ( const char * V_9 , void * * V_157 , T_4 * V_33 ,
T_4 V_158 , enum V_159 V_160 )
{
struct V_131 * V_131 ;
int V_28 ;
if ( ! V_9 || ! * V_9 )
return - V_150 ;
V_131 = F_99 ( V_9 , V_140 , 0 ) ;
if ( F_51 ( V_131 ) )
return F_100 ( V_131 ) ;
V_28 = F_90 ( V_131 , V_157 , V_33 , V_158 , V_160 ) ;
F_85 ( V_131 ) ;
return V_28 ;
}
int F_101 ( int V_132 , void * * V_157 , T_4 * V_33 , T_4 V_158 ,
enum V_159 V_160 )
{
struct V_132 V_155 = F_102 ( V_132 ) ;
int V_28 = - V_167 ;
if ( ! V_155 . V_131 )
goto V_86;
V_28 = F_90 ( V_155 . V_131 , V_157 , V_33 , V_158 , V_160 ) ;
V_86:
F_103 ( V_155 ) ;
return V_28 ;
}
T_5 F_104 ( struct V_131 * V_131 , unsigned long V_168 , T_4 V_26 , T_6 V_65 )
{
T_5 V_169 = F_105 ( V_131 , ( void T_1 * ) V_168 , V_65 , & V_26 ) ;
if ( V_169 > 0 )
F_106 ( V_168 , V_168 + V_65 ) ;
return V_169 ;
}
static int F_107 ( struct V_19 * V_20 )
{
struct V_170 * V_171 ;
struct V_19 * V_172 , * V_173 ;
V_171 = V_21 ;
V_172 = V_21 -> V_20 ;
F_108 ( V_171 , V_172 ) ;
if ( V_172 ) {
F_109 ( V_172 ) ;
F_110 ( & V_172 -> V_51 ) ;
if ( F_46 ( V_172 -> V_174 ) ) {
F_111 ( & V_172 -> V_51 ) ;
return - V_52 ;
}
}
F_112 ( V_171 ) ;
V_173 = V_171 -> V_173 ;
V_171 -> V_20 = V_20 ;
V_171 -> V_173 = V_20 ;
F_113 ( V_173 , V_20 ) ;
V_171 -> V_20 -> V_175 = 0 ;
F_114 ( V_171 ) ;
F_115 ( V_171 ) ;
if ( V_172 ) {
F_111 ( & V_172 -> V_51 ) ;
F_2 ( V_173 != V_172 ) ;
F_116 ( & V_171 -> signal -> V_176 , V_172 ) ;
F_117 ( V_172 ) ;
F_118 ( V_172 ) ;
return 0 ;
}
F_43 ( V_173 ) ;
return 0 ;
}
static int F_119 ( struct V_170 * V_171 )
{
struct V_177 * V_178 = V_171 -> signal ;
struct V_179 * V_180 = V_171 -> V_181 ;
T_7 * V_182 = & V_180 -> V_183 ;
if ( F_120 ( V_171 ) )
goto V_184;
F_121 ( V_182 ) ;
if ( F_122 ( V_178 ) ) {
F_123 ( V_182 ) ;
return - V_185 ;
}
V_178 -> V_186 = V_171 ;
V_178 -> V_187 = F_124 ( V_171 ) ;
if ( ! F_125 ( V_171 ) )
V_178 -> V_187 -- ;
while ( V_178 -> V_187 ) {
F_126 ( V_188 ) ;
F_123 ( V_182 ) ;
F_127 () ;
if ( F_46 ( F_128 ( V_171 ) ) )
goto V_189;
F_121 ( V_182 ) ;
}
F_123 ( V_182 ) ;
if ( ! F_125 ( V_171 ) ) {
struct V_170 * V_190 = V_171 -> V_191 ;
for (; ; ) {
F_129 ( V_171 ) ;
F_130 ( & V_192 ) ;
V_178 -> V_187 = - 1 ;
if ( F_131 ( V_190 -> V_193 ) )
break;
F_126 ( V_188 ) ;
F_132 ( & V_192 ) ;
F_133 ( V_171 ) ;
F_127 () ;
if ( F_46 ( F_128 ( V_171 ) ) )
goto V_189;
}
V_171 -> V_194 = V_190 -> V_194 ;
V_171 -> V_195 = V_190 -> V_195 ;
F_2 ( ! F_134 ( V_190 , V_171 ) ) ;
F_2 ( F_135 ( V_171 ) ) ;
V_171 -> V_196 = V_190 -> V_196 ;
F_136 ( V_171 , V_197 , F_137 ( V_190 ) ) ;
F_138 ( V_190 , V_171 , V_198 ) ;
F_138 ( V_190 , V_171 , V_199 ) ;
F_139 ( & V_190 -> V_200 , & V_171 -> V_200 ) ;
F_140 ( & V_190 -> V_201 , & V_171 -> V_201 ) ;
V_171 -> V_191 = V_171 ;
V_190 -> V_191 = V_171 ;
V_171 -> V_202 = V_203 ;
V_190 -> V_202 = - 1 ;
F_2 ( V_190 -> V_193 != V_204 ) ;
V_190 -> V_193 = V_205 ;
if ( F_46 ( V_190 -> V_206 ) )
F_141 ( V_190 , V_190 -> V_207 ) ;
F_132 ( & V_192 ) ;
F_133 ( V_171 ) ;
F_142 ( V_190 ) ;
}
V_178 -> V_186 = NULL ;
V_178 -> V_187 = 0 ;
V_184:
V_171 -> V_202 = V_203 ;
#ifdef F_143
F_144 ( V_178 ) ;
F_145 () ;
#endif
if ( F_146 ( & V_180 -> F_50 ) != 1 ) {
struct V_179 * V_208 ;
V_208 = F_147 ( V_209 , V_49 ) ;
if ( ! V_208 )
return - V_50 ;
F_148 ( & V_208 -> F_50 , 1 ) ;
memcpy ( V_208 -> V_210 , V_180 -> V_210 ,
sizeof( V_208 -> V_210 ) ) ;
F_130 ( & V_192 ) ;
F_149 ( & V_180 -> V_183 ) ;
F_150 ( V_171 -> V_181 , V_208 ) ;
F_151 ( & V_180 -> V_183 ) ;
F_132 ( & V_192 ) ;
F_152 ( V_180 ) ;
}
F_2 ( ! F_125 ( V_171 ) ) ;
return 0 ;
V_189:
F_153 ( & V_192 ) ;
V_178 -> V_186 = NULL ;
V_178 -> V_187 = 0 ;
F_154 ( & V_192 ) ;
return - V_185 ;
}
char * F_155 ( char * V_157 , struct V_170 * V_171 )
{
F_112 ( V_171 ) ;
strncpy ( V_157 , V_171 -> V_211 , sizeof( V_171 -> V_211 ) ) ;
F_115 ( V_171 ) ;
return V_157 ;
}
void F_156 ( struct V_170 * V_171 , const char * V_157 , bool V_119 )
{
F_112 ( V_171 ) ;
F_157 ( V_171 , V_157 ) ;
F_158 ( V_171 -> V_211 , V_157 , sizeof( V_171 -> V_211 ) ) ;
F_115 ( V_171 ) ;
F_159 ( V_171 , V_119 ) ;
}
int F_160 ( struct V_16 * V_17 )
{
int V_212 ;
V_212 = F_119 ( V_21 ) ;
if ( V_212 )
goto V_86;
F_161 ( V_17 -> V_20 , V_17 -> V_131 ) ;
F_13 ( V_17 , 0 ) ;
V_212 = F_107 ( V_17 -> V_20 ) ;
if ( V_212 )
goto V_86;
V_17 -> V_20 = NULL ;
F_62 ( V_213 ) ;
V_21 -> V_135 &= ~ ( V_214 | V_215 | V_216 |
V_217 | V_218 ) ;
F_162 () ;
V_21 -> V_219 &= ~ V_17 -> V_220 ;
F_163 ( V_21 -> V_221 ) ;
return 0 ;
V_86:
return V_212 ;
}
void F_164 ( struct V_16 * V_17 , struct V_131 * V_131 )
{
struct V_222 * V_222 = F_82 ( V_131 ) ;
if ( F_165 ( V_222 , V_223 ) < 0 ) {
struct V_224 * V_225 , * V_226 ;
V_17 -> V_227 |= V_228 ;
V_226 = V_225 = V_17 -> V_20 -> V_226 ;
while ( ( V_226 != & V_229 ) &&
! F_166 ( V_226 , V_222 ) )
V_226 = V_226 -> V_207 ;
if ( V_225 != V_226 ) {
V_17 -> V_20 -> V_226 = F_167 ( V_226 ) ;
F_168 ( V_225 ) ;
}
}
}
void F_169 ( struct V_16 * V_17 )
{
V_17 -> V_230 |= V_17 -> V_231 ;
if ( V_17 -> V_230 ) {
V_21 -> V_232 = 0 ;
if ( V_21 -> signal -> V_233 [ V_45 ] . V_234 > V_44 )
V_21 -> signal -> V_233 [ V_45 ] . V_234 = V_44 ;
}
F_170 ( V_21 -> V_20 ) ;
V_21 -> V_235 = V_21 -> V_236 = 0 ;
if ( V_17 -> V_227 & V_228 ||
V_17 -> V_230 )
F_171 ( V_21 -> V_20 , V_237 ) ;
else
F_171 ( V_21 -> V_20 , V_238 ) ;
F_172 () ;
F_173 () ;
F_156 ( V_21 , F_174 ( V_17 -> V_133 ) , true ) ;
V_21 -> V_20 -> V_239 = V_240 ;
V_21 -> V_241 ++ ;
F_175 ( V_21 , 0 ) ;
}
int F_176 ( struct V_16 * V_17 )
{
if ( F_177 ( & V_21 -> signal -> V_242 ) )
return - V_243 ;
V_17 -> V_244 = F_178 () ;
if ( F_131 ( V_17 -> V_244 ) )
return 0 ;
F_179 ( & V_21 -> signal -> V_242 ) ;
return - V_50 ;
}
static void F_180 ( struct V_16 * V_17 )
{
F_23 ( V_17 ) ;
if ( V_17 -> V_244 ) {
F_179 ( & V_21 -> signal -> V_242 ) ;
F_181 ( V_17 -> V_244 ) ;
}
if ( V_17 -> V_131 ) {
F_97 ( V_17 -> V_131 ) ;
F_85 ( V_17 -> V_131 ) ;
}
if ( V_17 -> V_245 != V_17 -> V_133 )
F_182 ( V_17 -> V_245 ) ;
F_182 ( V_17 ) ;
}
int F_183 ( const char * V_245 , struct V_16 * V_17 )
{
if ( V_17 -> V_245 != V_17 -> V_133 )
F_182 ( V_17 -> V_245 ) ;
V_17 -> V_245 = F_184 ( V_245 , V_49 ) ;
if ( ! V_17 -> V_245 )
return - V_50 ;
return 0 ;
}
void F_185 ( struct V_16 * V_17 )
{
F_186 ( V_17 ) ;
F_187 ( V_17 -> V_244 ) ;
V_17 -> V_244 = NULL ;
if ( F_188 ( V_21 -> V_20 ) != V_238 )
F_189 ( V_21 ) ;
F_190 ( V_17 ) ;
F_179 ( & V_21 -> signal -> V_242 ) ;
}
static void F_191 ( struct V_16 * V_17 )
{
struct V_170 * V_64 = V_21 , * V_246 ;
unsigned V_247 ;
if ( V_64 -> V_206 )
V_17 -> V_248 |= V_249 ;
if ( F_192 ( V_21 ) )
V_17 -> V_248 |= V_250 ;
V_246 = V_64 ;
V_247 = 1 ;
F_149 ( & V_64 -> V_251 -> V_182 ) ;
F_193 () ;
F_194 (p, t) {
if ( V_246 -> V_251 == V_64 -> V_251 )
V_247 ++ ;
}
F_195 () ;
if ( V_64 -> V_251 -> V_252 > V_247 )
V_17 -> V_248 |= V_253 ;
else
V_64 -> V_251 -> V_254 = 1 ;
F_151 ( & V_64 -> V_251 -> V_182 ) ;
}
static void F_196 ( struct V_16 * V_17 )
{
struct V_222 * V_222 ;
unsigned int V_255 ;
T_8 V_256 ;
T_9 V_257 ;
V_17 -> V_244 -> V_258 = F_197 () ;
V_17 -> V_244 -> V_259 = F_198 () ;
if ( ! F_199 ( V_17 -> V_131 -> V_154 . V_10 ) )
return;
if ( F_192 ( V_21 ) )
return;
V_222 = V_17 -> V_131 -> V_154 . V_260 -> V_261 ;
V_255 = F_200 ( V_222 -> V_153 ) ;
if ( ! ( V_255 & ( V_262 | V_263 ) ) )
return;
F_201 ( V_222 ) ;
V_255 = V_222 -> V_153 ;
V_256 = V_222 -> V_264 ;
V_257 = V_222 -> V_265 ;
F_202 ( V_222 ) ;
if ( ! F_203 ( V_17 -> V_244 -> V_226 , V_256 ) ||
! F_204 ( V_17 -> V_244 -> V_226 , V_257 ) )
return;
if ( V_255 & V_262 ) {
V_17 -> V_220 |= V_266 ;
V_17 -> V_244 -> V_258 = V_256 ;
}
if ( ( V_255 & ( V_263 | V_267 ) ) == ( V_263 | V_267 ) ) {
V_17 -> V_220 |= V_266 ;
V_17 -> V_244 -> V_259 = V_257 ;
}
}
int F_205 ( struct V_16 * V_17 )
{
int V_212 ;
T_4 V_26 = 0 ;
F_196 ( V_17 ) ;
V_212 = F_206 ( V_17 ) ;
if ( V_212 )
return V_212 ;
V_17 -> V_268 = 1 ;
memset ( V_17 -> V_157 , 0 , V_269 ) ;
return F_94 ( V_17 -> V_131 , V_17 -> V_157 , V_269 , & V_26 ) ;
}
int F_207 ( struct V_16 * V_17 )
{
int V_28 = 0 ;
unsigned long V_87 ;
char * V_83 ;
struct V_25 * V_25 ;
if ( ! V_17 -> V_38 )
return 0 ;
do {
V_87 = V_17 -> V_64 & ~ V_89 ;
V_25 = F_15 ( V_17 , V_17 -> V_64 , 0 ) ;
if ( ! V_25 ) {
V_28 = - V_78 ;
goto V_86;
}
V_83 = F_208 ( V_25 ) ;
for (; V_87 < V_42 && V_83 [ V_87 ] ;
V_87 ++ , V_17 -> V_64 ++ )
;
F_209 ( V_83 ) ;
F_22 ( V_25 ) ;
} while ( V_87 == V_42 );
V_17 -> V_64 ++ ;
V_17 -> V_38 -- ;
V_28 = 0 ;
V_86:
return V_28 ;
}
int F_210 ( struct V_16 * V_17 )
{
bool V_270 = F_211 ( V_271 ) ;
struct V_1 * V_2 ;
int V_212 ;
if ( V_17 -> V_272 > 5 )
return - V_273 ;
V_212 = F_212 ( V_17 ) ;
if ( V_212 )
return V_212 ;
V_212 = - V_274 ;
V_275:
F_153 ( & V_5 ) ;
F_213 (fmt, &formats, lh) {
if ( ! F_214 ( V_2 -> V_8 ) )
continue;
F_154 ( & V_5 ) ;
V_17 -> V_272 ++ ;
V_212 = V_2 -> V_4 ( V_17 ) ;
F_153 ( & V_5 ) ;
F_10 ( V_2 ) ;
V_17 -> V_272 -- ;
if ( V_212 < 0 && ! V_17 -> V_20 ) {
F_154 ( & V_5 ) ;
F_215 ( V_276 , V_21 ) ;
return V_212 ;
}
if ( V_212 != - V_277 || ! V_17 -> V_131 ) {
F_154 ( & V_5 ) ;
return V_212 ;
}
}
F_154 ( & V_5 ) ;
if ( V_270 ) {
if ( F_216 ( V_17 -> V_157 [ 0 ] ) && F_216 ( V_17 -> V_157 [ 1 ] ) &&
F_216 ( V_17 -> V_157 [ 2 ] ) && F_216 ( V_17 -> V_157 [ 3 ] ) )
return V_212 ;
if ( F_217 ( L_1 , * ( V_278 * ) ( V_17 -> V_157 + 2 ) ) < 0 )
return V_212 ;
V_270 = false ;
goto V_275;
}
return V_212 ;
}
static int F_218 ( struct V_16 * V_17 )
{
T_10 V_279 , V_280 ;
int V_28 ;
V_279 = V_21 -> V_196 ;
F_193 () ;
V_280 = F_219 ( V_21 , F_220 ( V_21 -> V_207 ) ) ;
F_195 () ;
V_28 = F_210 ( V_17 ) ;
if ( V_28 >= 0 ) {
F_221 ( V_17 ) ;
F_222 ( V_21 , V_279 , V_17 ) ;
F_223 ( V_281 , V_280 ) ;
F_224 ( V_21 ) ;
}
return V_28 ;
}
static int F_225 ( int V_132 , struct V_133 * V_133 ,
struct V_71 V_72 ,
struct V_71 V_282 ,
int V_135 )
{
char * V_283 = NULL ;
struct V_16 * V_17 ;
struct V_131 * V_131 ;
struct V_284 * V_285 ;
int V_212 ;
if ( F_51 ( V_133 ) )
return F_100 ( V_133 ) ;
if ( ( V_21 -> V_135 & V_286 ) &&
F_146 ( & F_226 () -> V_287 ) > F_20 ( V_288 ) ) {
V_212 = - V_185 ;
goto V_289;
}
V_21 -> V_135 &= ~ V_286 ;
V_212 = F_227 ( & V_285 ) ;
if ( V_212 )
goto V_289;
V_212 = - V_50 ;
V_17 = F_228 ( sizeof( * V_17 ) , V_49 ) ;
if ( ! V_17 )
goto V_290;
V_212 = F_176 ( V_17 ) ;
if ( V_212 )
goto V_166;
F_191 ( V_17 ) ;
V_21 -> V_291 = 1 ;
V_131 = F_79 ( V_132 , V_133 , V_135 ) ;
V_212 = F_100 ( V_131 ) ;
if ( F_51 ( V_131 ) )
goto V_292;
F_229 () ;
V_17 -> V_131 = V_131 ;
if ( V_132 == V_156 || V_133 -> V_134 [ 0 ] == '/' ) {
V_17 -> V_133 = V_133 -> V_134 ;
} else {
if ( V_133 -> V_134 [ 0 ] == '\0' )
V_283 = F_230 ( V_49 , L_2 , V_132 ) ;
else
V_283 = F_230 ( V_49 , L_3 ,
V_132 , V_133 -> V_134 ) ;
if ( ! V_283 ) {
V_212 = - V_50 ;
goto V_292;
}
if ( F_231 ( V_132 , F_232 ( V_21 -> V_221 -> V_293 ) ) )
V_17 -> V_227 |= V_294 ;
V_17 -> V_133 = V_283 ;
}
V_17 -> V_245 = V_17 -> V_133 ;
V_212 = F_41 ( V_17 ) ;
if ( V_212 )
goto V_292;
V_17 -> V_38 = F_50 ( V_72 , V_295 ) ;
if ( ( V_212 = V_17 -> V_38 ) < 0 )
goto V_86;
V_17 -> V_39 = F_50 ( V_282 , V_295 ) ;
if ( ( V_212 = V_17 -> V_39 ) < 0 )
goto V_86;
V_212 = F_205 ( V_17 ) ;
if ( V_212 < 0 )
goto V_86;
V_212 = F_60 ( 1 , & V_17 -> V_133 , V_17 ) ;
if ( V_212 < 0 )
goto V_86;
V_17 -> V_119 = V_17 -> V_64 ;
V_212 = F_54 ( V_17 -> V_39 , V_282 , V_17 ) ;
if ( V_212 < 0 )
goto V_86;
V_212 = F_54 ( V_17 -> V_38 , V_72 , V_17 ) ;
if ( V_212 < 0 )
goto V_86;
F_164 ( V_17 , V_17 -> V_131 ) ;
V_212 = F_218 ( V_17 ) ;
if ( V_212 < 0 )
goto V_86;
V_21 -> V_251 -> V_254 = 0 ;
V_21 -> V_291 = 0 ;
F_233 ( V_21 ) ;
F_234 ( V_21 ) ;
F_235 ( V_21 ) ;
F_180 ( V_17 ) ;
F_182 ( V_283 ) ;
F_89 ( V_133 ) ;
if ( V_285 )
F_236 ( V_285 ) ;
return V_212 ;
V_86:
if ( V_17 -> V_20 ) {
F_13 ( V_17 , 0 ) ;
F_118 ( V_17 -> V_20 ) ;
}
V_292:
V_21 -> V_251 -> V_254 = 0 ;
V_21 -> V_291 = 0 ;
V_166:
F_180 ( V_17 ) ;
F_182 ( V_283 ) ;
V_290:
if ( V_285 )
F_237 ( V_285 ) ;
V_289:
F_89 ( V_133 ) ;
return V_212 ;
}
int F_238 ( struct V_133 * V_133 ,
const char T_1 * const T_1 * V_90 ,
const char T_1 * const T_1 * V_296 )
{
struct V_71 V_72 = { . V_77 . V_74 = V_90 } ;
struct V_71 V_282 = { . V_77 . V_74 = V_296 } ;
return F_225 ( V_156 , V_133 , V_72 , V_282 , 0 ) ;
}
int F_239 ( int V_132 , struct V_133 * V_133 ,
const char T_1 * const T_1 * V_90 ,
const char T_1 * const T_1 * V_296 ,
int V_135 )
{
struct V_71 V_72 = { . V_77 . V_74 = V_90 } ;
struct V_71 V_282 = { . V_77 . V_74 = V_296 } ;
return F_225 ( V_132 , V_133 , V_72 , V_282 , V_135 ) ;
}
static int F_240 ( struct V_133 * V_133 ,
const T_2 T_1 * V_90 ,
const T_2 T_1 * V_296 )
{
struct V_71 V_72 = {
. V_75 = true ,
. V_77 . V_76 = V_90 ,
} ;
struct V_71 V_282 = {
. V_75 = true ,
. V_77 . V_76 = V_296 ,
} ;
return F_225 ( V_156 , V_133 , V_72 , V_282 , 0 ) ;
}
static int F_241 ( int V_132 , struct V_133 * V_133 ,
const T_2 T_1 * V_90 ,
const T_2 T_1 * V_296 ,
int V_135 )
{
struct V_71 V_72 = {
. V_75 = true ,
. V_77 . V_76 = V_90 ,
} ;
struct V_71 V_282 = {
. V_75 = true ,
. V_77 . V_76 = V_296 ,
} ;
return F_225 ( V_132 , V_133 , V_72 , V_282 , V_135 ) ;
}
void F_242 ( struct V_1 * V_297 )
{
struct V_19 * V_20 = V_21 -> V_20 ;
if ( V_20 -> V_298 )
F_11 ( V_20 -> V_298 -> V_8 ) ;
V_20 -> V_298 = V_297 ;
if ( V_297 )
F_243 ( V_297 -> V_8 ) ;
}
void F_171 ( struct V_19 * V_20 , int V_299 )
{
unsigned long V_225 , V_297 ;
if ( F_3 ( ( unsigned ) V_299 > V_300 ) )
return;
do {
V_225 = F_244 ( V_20 -> V_135 ) ;
V_297 = ( V_225 & ~ V_301 ) | V_299 ;
} while ( F_245 ( & V_20 -> V_135 , V_225 , V_297 ) != V_225 );
}
