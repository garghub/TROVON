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
int F_90 ( struct V_131 * V_131 , T_4 V_87 ,
char * V_157 , unsigned long F_50 )
{
T_3 V_158 ;
T_4 V_26 = V_87 ;
int V_159 ;
V_158 = F_61 () ;
F_62 ( F_91 () ) ;
V_159 = F_92 ( V_131 , ( void T_1 * ) V_157 , F_50 , & V_26 ) ;
F_62 ( V_158 ) ;
return V_159 ;
}
int F_93 ( struct V_131 * V_131 , void * * V_160 , T_4 * V_33 ,
T_4 V_161 , enum V_162 V_163 )
{
T_4 V_164 , V_26 ;
T_5 V_165 = 0 ;
int V_28 ;
if ( ! F_81 ( F_82 ( V_131 ) -> V_153 ) || V_161 < 0 )
return - V_150 ;
V_28 = F_94 ( V_131 , V_163 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_83 ( V_131 ) ;
if ( V_28 )
return V_28 ;
V_164 = F_95 ( F_82 ( V_131 ) ) ;
if ( V_161 > 0 && V_164 > V_161 ) {
V_28 = - V_166 ;
goto V_86;
}
if ( V_164 <= 0 ) {
V_28 = - V_150 ;
goto V_86;
}
if ( V_163 != V_167 )
* V_160 = F_96 ( V_164 ) ;
if ( ! * V_160 ) {
V_28 = - V_50 ;
goto V_86;
}
V_26 = 0 ;
while ( V_26 < V_164 ) {
V_165 = F_90 ( V_131 , V_26 , ( char * ) ( * V_160 ) + V_26 ,
V_164 - V_26 ) ;
if ( V_165 < 0 ) {
V_28 = V_165 ;
goto V_86;
}
if ( V_165 == 0 )
break;
V_26 += V_165 ;
}
if ( V_26 != V_164 ) {
V_28 = - V_168 ;
goto V_169;
}
V_28 = F_97 ( V_131 , * V_160 , V_164 , V_163 ) ;
if ( ! V_28 )
* V_33 = V_26 ;
V_169:
if ( V_28 < 0 ) {
if ( V_163 != V_167 ) {
F_98 ( * V_160 ) ;
* V_160 = NULL ;
}
}
V_86:
F_99 ( V_131 ) ;
return V_28 ;
}
int F_100 ( char * V_9 , void * * V_160 , T_4 * V_33 ,
T_4 V_161 , enum V_162 V_163 )
{
struct V_131 * V_131 ;
int V_28 ;
if ( ! V_9 || ! * V_9 )
return - V_150 ;
V_131 = F_101 ( V_9 , V_140 , 0 ) ;
if ( F_51 ( V_131 ) )
return F_102 ( V_131 ) ;
V_28 = F_93 ( V_131 , V_160 , V_33 , V_161 , V_163 ) ;
F_85 ( V_131 ) ;
return V_28 ;
}
int F_103 ( int V_132 , void * * V_160 , T_4 * V_33 , T_4 V_161 ,
enum V_162 V_163 )
{
struct V_132 V_155 = F_104 ( V_132 ) ;
int V_28 = - V_170 ;
if ( ! V_155 . V_131 )
goto V_86;
V_28 = F_93 ( V_155 . V_131 , V_160 , V_33 , V_161 , V_163 ) ;
V_86:
F_105 ( V_155 ) ;
return V_28 ;
}
T_5 F_106 ( struct V_131 * V_131 , unsigned long V_157 , T_4 V_26 , T_6 V_65 )
{
T_5 V_171 = F_92 ( V_131 , ( void T_1 * ) V_157 , V_65 , & V_26 ) ;
if ( V_171 > 0 )
F_107 ( V_157 , V_157 + V_65 ) ;
return V_171 ;
}
static int F_108 ( struct V_19 * V_20 )
{
struct V_172 * V_173 ;
struct V_19 * V_174 , * V_175 ;
V_173 = V_21 ;
V_174 = V_21 -> V_20 ;
F_109 ( V_173 , V_174 ) ;
if ( V_174 ) {
F_110 ( V_174 ) ;
F_111 ( & V_174 -> V_51 ) ;
if ( F_46 ( V_174 -> V_176 ) ) {
F_112 ( & V_174 -> V_51 ) ;
return - V_52 ;
}
}
F_113 ( V_173 ) ;
V_175 = V_173 -> V_175 ;
V_173 -> V_20 = V_20 ;
V_173 -> V_175 = V_20 ;
F_114 ( V_175 , V_20 ) ;
V_173 -> V_20 -> V_177 = 0 ;
F_115 ( V_173 ) ;
F_116 ( V_173 ) ;
if ( V_174 ) {
F_112 ( & V_174 -> V_51 ) ;
F_2 ( V_175 != V_174 ) ;
F_117 ( & V_173 -> signal -> V_178 , V_174 ) ;
F_118 ( V_174 ) ;
F_119 ( V_174 ) ;
return 0 ;
}
F_43 ( V_175 ) ;
return 0 ;
}
static int F_120 ( struct V_172 * V_173 )
{
struct V_179 * V_180 = V_173 -> signal ;
struct V_181 * V_182 = V_173 -> V_183 ;
T_7 * V_184 = & V_182 -> V_185 ;
if ( F_121 ( V_173 ) )
goto V_186;
F_122 ( V_184 ) ;
if ( F_123 ( V_180 ) ) {
F_124 ( V_184 ) ;
return - V_187 ;
}
V_180 -> V_188 = V_173 ;
V_180 -> V_189 = F_125 ( V_173 ) ;
if ( ! F_126 ( V_173 ) )
V_180 -> V_189 -- ;
while ( V_180 -> V_189 ) {
F_127 ( V_190 ) ;
F_124 ( V_184 ) ;
F_128 () ;
if ( F_46 ( F_129 ( V_173 ) ) )
goto V_191;
F_122 ( V_184 ) ;
}
F_124 ( V_184 ) ;
if ( ! F_126 ( V_173 ) ) {
struct V_172 * V_192 = V_173 -> V_193 ;
for (; ; ) {
F_130 ( V_173 ) ;
F_131 ( & V_194 ) ;
V_180 -> V_189 = - 1 ;
if ( F_132 ( V_192 -> V_195 ) )
break;
F_127 ( V_190 ) ;
F_133 ( & V_194 ) ;
F_134 ( V_173 ) ;
F_128 () ;
if ( F_46 ( F_129 ( V_173 ) ) )
goto V_191;
}
V_173 -> V_196 = V_192 -> V_196 ;
V_173 -> V_197 = V_192 -> V_197 ;
F_2 ( ! F_135 ( V_192 , V_173 ) ) ;
F_2 ( F_136 ( V_173 ) ) ;
V_173 -> V_198 = V_192 -> V_198 ;
F_137 ( V_173 , V_199 , F_138 ( V_192 ) ) ;
F_139 ( V_192 , V_173 , V_200 ) ;
F_139 ( V_192 , V_173 , V_201 ) ;
F_140 ( & V_192 -> V_202 , & V_173 -> V_202 ) ;
F_141 ( & V_192 -> V_203 , & V_173 -> V_203 ) ;
V_173 -> V_193 = V_173 ;
V_192 -> V_193 = V_173 ;
V_173 -> V_204 = V_205 ;
V_192 -> V_204 = - 1 ;
F_2 ( V_192 -> V_195 != V_206 ) ;
V_192 -> V_195 = V_207 ;
if ( F_46 ( V_192 -> V_208 ) )
F_142 ( V_192 , V_192 -> V_209 ) ;
F_133 ( & V_194 ) ;
F_134 ( V_173 ) ;
F_143 ( V_192 ) ;
}
V_180 -> V_188 = NULL ;
V_180 -> V_189 = 0 ;
V_186:
V_173 -> V_204 = V_205 ;
#ifdef F_144
F_145 ( V_180 ) ;
F_146 () ;
#endif
if ( F_147 ( & V_182 -> F_50 ) != 1 ) {
struct V_181 * V_210 ;
V_210 = F_148 ( V_211 , V_49 ) ;
if ( ! V_210 )
return - V_50 ;
F_149 ( & V_210 -> F_50 , 1 ) ;
memcpy ( V_210 -> V_212 , V_182 -> V_212 ,
sizeof( V_210 -> V_212 ) ) ;
F_131 ( & V_194 ) ;
F_150 ( & V_182 -> V_185 ) ;
F_151 ( V_173 -> V_183 , V_210 ) ;
F_152 ( & V_182 -> V_185 ) ;
F_133 ( & V_194 ) ;
F_153 ( V_182 ) ;
}
F_2 ( ! F_126 ( V_173 ) ) ;
return 0 ;
V_191:
F_154 ( & V_194 ) ;
V_180 -> V_188 = NULL ;
V_180 -> V_189 = 0 ;
F_155 ( & V_194 ) ;
return - V_187 ;
}
char * F_156 ( char * V_160 , struct V_172 * V_173 )
{
F_113 ( V_173 ) ;
strncpy ( V_160 , V_173 -> V_213 , sizeof( V_173 -> V_213 ) ) ;
F_116 ( V_173 ) ;
return V_160 ;
}
void F_157 ( struct V_172 * V_173 , const char * V_160 , bool V_119 )
{
F_113 ( V_173 ) ;
F_158 ( V_173 , V_160 ) ;
F_159 ( V_173 -> V_213 , V_160 , sizeof( V_173 -> V_213 ) ) ;
F_116 ( V_173 ) ;
F_160 ( V_173 , V_119 ) ;
}
int F_161 ( struct V_16 * V_17 )
{
int V_214 ;
V_214 = F_120 ( V_21 ) ;
if ( V_214 )
goto V_86;
F_162 ( V_17 -> V_20 , V_17 -> V_131 ) ;
F_13 ( V_17 , 0 ) ;
V_214 = F_108 ( V_17 -> V_20 ) ;
if ( V_214 )
goto V_86;
V_17 -> V_20 = NULL ;
F_62 ( V_215 ) ;
V_21 -> V_135 &= ~ ( V_216 | V_217 | V_218 |
V_219 | V_220 ) ;
F_163 () ;
V_21 -> V_221 &= ~ V_17 -> V_222 ;
F_164 ( V_21 -> V_223 ) ;
return 0 ;
V_86:
return V_214 ;
}
void F_165 ( struct V_16 * V_17 , struct V_131 * V_131 )
{
struct V_224 * V_224 = F_82 ( V_131 ) ;
if ( F_166 ( V_224 , V_225 ) < 0 ) {
struct V_226 * V_227 , * V_228 ;
V_17 -> V_229 |= V_230 ;
V_228 = V_227 = V_17 -> V_20 -> V_228 ;
while ( ( V_228 != & V_231 ) &&
! F_167 ( V_228 , V_224 ) )
V_228 = V_228 -> V_209 ;
if ( V_227 != V_228 ) {
V_17 -> V_20 -> V_228 = F_168 ( V_228 ) ;
F_169 ( V_227 ) ;
}
}
}
void F_170 ( struct V_16 * V_17 )
{
F_171 ( V_21 -> V_20 ) ;
V_21 -> V_232 = V_21 -> V_233 = 0 ;
if ( F_172 ( F_173 () , F_174 () ) && F_175 ( F_176 () , F_177 () ) )
F_178 ( V_21 -> V_20 , V_234 ) ;
else
F_178 ( V_21 -> V_20 , V_235 ) ;
F_179 () ;
F_180 () ;
F_157 ( V_21 , F_181 ( V_17 -> V_133 ) , true ) ;
V_21 -> V_20 -> V_236 = V_237 ;
if ( ! F_172 ( V_17 -> V_238 -> V_239 , F_173 () ) ||
! F_175 ( V_17 -> V_238 -> V_240 , F_176 () ) ) {
V_21 -> V_241 = 0 ;
} else {
if ( V_17 -> V_229 & V_230 )
F_178 ( V_21 -> V_20 , V_235 ) ;
}
V_21 -> V_242 ++ ;
F_182 ( V_21 , 0 ) ;
}
int F_183 ( struct V_16 * V_17 )
{
if ( F_184 ( & V_21 -> signal -> V_243 ) )
return - V_244 ;
V_17 -> V_238 = F_185 () ;
if ( F_132 ( V_17 -> V_238 ) )
return 0 ;
F_186 ( & V_21 -> signal -> V_243 ) ;
return - V_50 ;
}
static void F_187 ( struct V_16 * V_17 )
{
F_23 ( V_17 ) ;
if ( V_17 -> V_238 ) {
F_186 ( & V_21 -> signal -> V_243 ) ;
F_188 ( V_17 -> V_238 ) ;
}
if ( V_17 -> V_131 ) {
F_99 ( V_17 -> V_131 ) ;
F_85 ( V_17 -> V_131 ) ;
}
if ( V_17 -> V_245 != V_17 -> V_133 )
F_189 ( V_17 -> V_245 ) ;
F_189 ( V_17 ) ;
}
int F_190 ( char * V_245 , struct V_16 * V_17 )
{
if ( V_17 -> V_245 != V_17 -> V_133 )
F_189 ( V_17 -> V_245 ) ;
V_17 -> V_245 = F_191 ( V_245 , V_49 ) ;
if ( ! V_17 -> V_245 )
return - V_50 ;
return 0 ;
}
void F_192 ( struct V_16 * V_17 )
{
F_193 ( V_17 ) ;
F_194 ( V_17 -> V_238 ) ;
V_17 -> V_238 = NULL ;
if ( F_195 ( V_21 -> V_20 ) != V_234 )
F_196 ( V_21 ) ;
F_197 ( V_17 ) ;
F_186 ( & V_21 -> signal -> V_243 ) ;
}
static void F_198 ( struct V_16 * V_17 )
{
struct V_172 * V_64 = V_21 , * V_246 ;
unsigned V_247 ;
if ( V_64 -> V_208 )
V_17 -> V_248 |= V_249 ;
if ( F_199 ( V_21 ) )
V_17 -> V_248 |= V_250 ;
V_246 = V_64 ;
V_247 = 1 ;
F_150 ( & V_64 -> V_251 -> V_184 ) ;
F_200 () ;
F_201 (p, t) {
if ( V_246 -> V_251 == V_64 -> V_251 )
V_247 ++ ;
}
F_202 () ;
if ( V_64 -> V_251 -> V_252 > V_247 )
V_17 -> V_248 |= V_253 ;
else
V_64 -> V_251 -> V_254 = 1 ;
F_152 ( & V_64 -> V_251 -> V_184 ) ;
}
static void F_203 ( struct V_16 * V_17 )
{
struct V_224 * V_224 ;
unsigned int V_255 ;
T_8 V_239 ;
T_9 V_240 ;
V_17 -> V_238 -> V_256 = F_173 () ;
V_17 -> V_238 -> V_257 = F_176 () ;
if ( ! F_204 ( V_17 -> V_131 -> V_154 . V_10 ) )
return;
if ( F_199 ( V_21 ) )
return;
V_224 = V_17 -> V_131 -> V_154 . V_258 -> V_259 ;
V_255 = F_205 ( V_224 -> V_153 ) ;
if ( ! ( V_255 & ( V_260 | V_261 ) ) )
return;
F_206 ( V_224 ) ;
V_255 = V_224 -> V_153 ;
V_239 = V_224 -> V_262 ;
V_240 = V_224 -> V_263 ;
F_207 ( V_224 ) ;
if ( ! F_208 ( V_17 -> V_238 -> V_228 , V_239 ) ||
! F_209 ( V_17 -> V_238 -> V_228 , V_240 ) )
return;
if ( V_255 & V_260 ) {
V_17 -> V_222 |= V_264 ;
V_17 -> V_238 -> V_256 = V_239 ;
}
if ( ( V_255 & ( V_261 | V_265 ) ) == ( V_261 | V_265 ) ) {
V_17 -> V_222 |= V_264 ;
V_17 -> V_238 -> V_257 = V_240 ;
}
}
int F_210 ( struct V_16 * V_17 )
{
int V_214 ;
F_203 ( V_17 ) ;
V_214 = F_211 ( V_17 ) ;
if ( V_214 )
return V_214 ;
V_17 -> V_266 = 1 ;
memset ( V_17 -> V_160 , 0 , V_267 ) ;
return F_90 ( V_17 -> V_131 , 0 , V_17 -> V_160 , V_267 ) ;
}
int F_212 ( struct V_16 * V_17 )
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
V_83 = F_213 ( V_25 ) ;
for (; V_87 < V_42 && V_83 [ V_87 ] ;
V_87 ++ , V_17 -> V_64 ++ )
;
F_214 ( V_83 ) ;
F_22 ( V_25 ) ;
} while ( V_87 == V_42 );
V_17 -> V_64 ++ ;
V_17 -> V_38 -- ;
V_28 = 0 ;
V_86:
return V_28 ;
}
int F_215 ( struct V_16 * V_17 )
{
bool V_268 = F_216 ( V_269 ) ;
struct V_1 * V_2 ;
int V_214 ;
if ( V_17 -> V_270 > 5 )
return - V_271 ;
V_214 = F_217 ( V_17 ) ;
if ( V_214 )
return V_214 ;
V_214 = - V_272 ;
V_273:
F_154 ( & V_5 ) ;
F_218 (fmt, &formats, lh) {
if ( ! F_219 ( V_2 -> V_8 ) )
continue;
F_155 ( & V_5 ) ;
V_17 -> V_270 ++ ;
V_214 = V_2 -> V_4 ( V_17 ) ;
F_154 ( & V_5 ) ;
F_10 ( V_2 ) ;
V_17 -> V_270 -- ;
if ( V_214 < 0 && ! V_17 -> V_20 ) {
F_155 ( & V_5 ) ;
F_220 ( V_274 , V_21 ) ;
return V_214 ;
}
if ( V_214 != - V_275 || ! V_17 -> V_131 ) {
F_155 ( & V_5 ) ;
return V_214 ;
}
}
F_155 ( & V_5 ) ;
if ( V_268 ) {
if ( F_221 ( V_17 -> V_160 [ 0 ] ) && F_221 ( V_17 -> V_160 [ 1 ] ) &&
F_221 ( V_17 -> V_160 [ 2 ] ) && F_221 ( V_17 -> V_160 [ 3 ] ) )
return V_214 ;
if ( F_222 ( L_1 , * ( V_276 * ) ( V_17 -> V_160 + 2 ) ) < 0 )
return V_214 ;
V_268 = false ;
goto V_273;
}
return V_214 ;
}
static int F_223 ( struct V_16 * V_17 )
{
T_10 V_277 , V_278 ;
int V_28 ;
V_277 = V_21 -> V_198 ;
F_200 () ;
V_278 = F_224 ( V_21 , F_225 ( V_21 -> V_209 ) ) ;
F_202 () ;
V_28 = F_215 ( V_17 ) ;
if ( V_28 >= 0 ) {
F_226 ( V_17 ) ;
F_227 ( V_21 , V_277 , V_17 ) ;
F_228 ( V_279 , V_278 ) ;
F_229 ( V_21 ) ;
}
return V_28 ;
}
static int F_230 ( int V_132 , struct V_133 * V_133 ,
struct V_71 V_72 ,
struct V_71 V_280 ,
int V_135 )
{
char * V_281 = NULL ;
struct V_16 * V_17 ;
struct V_131 * V_131 ;
struct V_282 * V_283 ;
int V_214 ;
if ( F_51 ( V_133 ) )
return F_102 ( V_133 ) ;
if ( ( V_21 -> V_135 & V_284 ) &&
F_147 ( & F_231 () -> V_285 ) > F_20 ( V_286 ) ) {
V_214 = - V_187 ;
goto V_287;
}
V_21 -> V_135 &= ~ V_284 ;
V_214 = F_232 ( & V_283 ) ;
if ( V_214 )
goto V_287;
V_214 = - V_50 ;
V_17 = F_233 ( sizeof( * V_17 ) , V_49 ) ;
if ( ! V_17 )
goto V_288;
V_214 = F_183 ( V_17 ) ;
if ( V_214 )
goto V_169;
F_198 ( V_17 ) ;
V_21 -> V_289 = 1 ;
V_131 = F_79 ( V_132 , V_133 , V_135 ) ;
V_214 = F_102 ( V_131 ) ;
if ( F_51 ( V_131 ) )
goto V_290;
F_234 () ;
V_17 -> V_131 = V_131 ;
if ( V_132 == V_156 || V_133 -> V_134 [ 0 ] == '/' ) {
V_17 -> V_133 = V_133 -> V_134 ;
} else {
if ( V_133 -> V_134 [ 0 ] == '\0' )
V_281 = F_235 ( V_291 , L_2 , V_132 ) ;
else
V_281 = F_235 ( V_291 , L_3 ,
V_132 , V_133 -> V_134 ) ;
if ( ! V_281 ) {
V_214 = - V_50 ;
goto V_290;
}
if ( F_236 ( V_132 , F_237 ( V_21 -> V_223 -> V_292 ) ) )
V_17 -> V_229 |= V_293 ;
V_17 -> V_133 = V_281 ;
}
V_17 -> V_245 = V_17 -> V_133 ;
V_214 = F_41 ( V_17 ) ;
if ( V_214 )
goto V_290;
V_17 -> V_38 = F_50 ( V_72 , V_294 ) ;
if ( ( V_214 = V_17 -> V_38 ) < 0 )
goto V_86;
V_17 -> V_39 = F_50 ( V_280 , V_294 ) ;
if ( ( V_214 = V_17 -> V_39 ) < 0 )
goto V_86;
V_214 = F_210 ( V_17 ) ;
if ( V_214 < 0 )
goto V_86;
V_214 = F_60 ( 1 , & V_17 -> V_133 , V_17 ) ;
if ( V_214 < 0 )
goto V_86;
V_17 -> V_119 = V_17 -> V_64 ;
V_214 = F_54 ( V_17 -> V_39 , V_280 , V_17 ) ;
if ( V_214 < 0 )
goto V_86;
V_214 = F_54 ( V_17 -> V_38 , V_72 , V_17 ) ;
if ( V_214 < 0 )
goto V_86;
F_165 ( V_17 , V_17 -> V_131 ) ;
V_214 = F_223 ( V_17 ) ;
if ( V_214 < 0 )
goto V_86;
V_21 -> V_251 -> V_254 = 0 ;
V_21 -> V_289 = 0 ;
F_238 ( V_21 ) ;
F_239 ( V_21 ) ;
F_187 ( V_17 ) ;
F_189 ( V_281 ) ;
F_89 ( V_133 ) ;
if ( V_283 )
F_240 ( V_283 ) ;
return V_214 ;
V_86:
if ( V_17 -> V_20 ) {
F_13 ( V_17 , 0 ) ;
F_119 ( V_17 -> V_20 ) ;
}
V_290:
V_21 -> V_251 -> V_254 = 0 ;
V_21 -> V_289 = 0 ;
V_169:
F_187 ( V_17 ) ;
F_189 ( V_281 ) ;
V_288:
if ( V_283 )
F_241 ( V_283 ) ;
V_287:
F_89 ( V_133 ) ;
return V_214 ;
}
int F_242 ( struct V_133 * V_133 ,
const char T_1 * const T_1 * V_90 ,
const char T_1 * const T_1 * V_295 )
{
struct V_71 V_72 = { . V_77 . V_74 = V_90 } ;
struct V_71 V_280 = { . V_77 . V_74 = V_295 } ;
return F_230 ( V_156 , V_133 , V_72 , V_280 , 0 ) ;
}
int F_243 ( int V_132 , struct V_133 * V_133 ,
const char T_1 * const T_1 * V_90 ,
const char T_1 * const T_1 * V_295 ,
int V_135 )
{
struct V_71 V_72 = { . V_77 . V_74 = V_90 } ;
struct V_71 V_280 = { . V_77 . V_74 = V_295 } ;
return F_230 ( V_132 , V_133 , V_72 , V_280 , V_135 ) ;
}
static int F_244 ( struct V_133 * V_133 ,
const T_2 T_1 * V_90 ,
const T_2 T_1 * V_295 )
{
struct V_71 V_72 = {
. V_75 = true ,
. V_77 . V_76 = V_90 ,
} ;
struct V_71 V_280 = {
. V_75 = true ,
. V_77 . V_76 = V_295 ,
} ;
return F_230 ( V_156 , V_133 , V_72 , V_280 , 0 ) ;
}
static int F_245 ( int V_132 , struct V_133 * V_133 ,
const T_2 T_1 * V_90 ,
const T_2 T_1 * V_295 ,
int V_135 )
{
struct V_71 V_72 = {
. V_75 = true ,
. V_77 . V_76 = V_90 ,
} ;
struct V_71 V_280 = {
. V_75 = true ,
. V_77 . V_76 = V_295 ,
} ;
return F_230 ( V_132 , V_133 , V_72 , V_280 , V_135 ) ;
}
void F_246 ( struct V_1 * V_296 )
{
struct V_19 * V_20 = V_21 -> V_20 ;
if ( V_20 -> V_297 )
F_11 ( V_20 -> V_297 -> V_8 ) ;
V_20 -> V_297 = V_296 ;
if ( V_296 )
F_247 ( V_296 -> V_8 ) ;
}
void F_178 ( struct V_19 * V_20 , int V_298 )
{
unsigned long V_227 , V_296 ;
if ( F_3 ( ( unsigned ) V_298 > V_299 ) )
return;
do {
V_227 = F_248 ( V_20 -> V_135 ) ;
V_296 = ( V_227 & ~ V_300 ) | V_298 ;
} while ( F_249 ( & V_20 -> V_135 , V_227 , V_296 ) != V_227 );
}
