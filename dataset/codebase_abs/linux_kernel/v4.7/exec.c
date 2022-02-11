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
static void F_22 ( struct V_16 * V_17 )
{
}
static void F_23 ( struct V_16 * V_17 , unsigned long V_26 ,
struct V_25 * V_25 )
{
F_24 ( V_17 -> V_29 , V_26 , F_25 ( V_25 ) ) ;
}
static int F_26 ( struct V_16 * V_17 )
{
int V_39 ;
struct V_40 * V_29 = NULL ;
struct V_19 * V_20 = V_17 -> V_20 ;
V_17 -> V_29 = V_29 = F_27 ( V_41 , V_42 ) ;
if ( ! V_29 )
return - V_43 ;
if ( F_28 ( & V_20 -> V_44 ) ) {
V_39 = - V_45 ;
goto V_46;
}
V_29 -> V_47 = V_20 ;
F_29 ( V_48 & V_49 ) ;
V_29 -> V_31 = V_50 ;
V_29 -> V_32 = V_29 -> V_31 - V_35 ;
V_29 -> V_51 = V_52 | V_48 | V_49 ;
V_29 -> V_53 = F_30 ( V_29 -> V_51 ) ;
F_31 ( & V_29 -> V_54 ) ;
V_39 = F_32 ( V_20 , V_29 ) ;
if ( V_39 )
goto V_39;
V_20 -> V_55 = V_20 -> V_56 = 1 ;
F_33 ( V_20 , V_29 ) ;
F_34 ( & V_20 -> V_44 ) ;
V_17 -> V_57 = V_29 -> V_31 - sizeof( void * ) ;
return 0 ;
V_39:
F_34 ( & V_20 -> V_44 ) ;
V_46:
V_17 -> V_29 = NULL ;
F_35 ( V_41 , V_29 ) ;
return V_39 ;
}
static bool F_36 ( struct V_16 * V_17 , long V_58 )
{
return V_58 <= V_59 ;
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
V_25 = F_37 ( V_60 | V_61 ) ;
if ( ! V_25 )
return NULL ;
V_17 -> V_25 [ V_26 / V_35 ] = V_25 ;
}
return V_25 ;
}
static void F_21 ( struct V_25 * V_25 )
{
}
static void F_38 ( struct V_16 * V_17 , int V_62 )
{
if ( V_17 -> V_25 [ V_62 ] ) {
F_39 ( V_17 -> V_25 [ V_62 ] ) ;
V_17 -> V_25 [ V_62 ] = NULL ;
}
}
static void F_22 ( struct V_16 * V_17 )
{
int V_62 ;
for ( V_62 = 0 ; V_62 < V_63 ; V_62 ++ )
F_38 ( V_17 , V_62 ) ;
}
static void F_23 ( struct V_16 * V_17 , unsigned long V_26 ,
struct V_25 * V_25 )
{
}
static int F_26 ( struct V_16 * V_17 )
{
V_17 -> V_57 = V_35 * V_63 - sizeof( void * ) ;
return 0 ;
}
static bool F_36 ( struct V_16 * V_17 , long V_58 )
{
return V_58 <= V_17 -> V_57 ;
}
static int F_40 ( struct V_16 * V_17 )
{
int V_39 ;
struct V_19 * V_20 = NULL ;
V_17 -> V_20 = V_20 = F_41 () ;
V_39 = - V_43 ;
if ( ! V_20 )
goto V_39;
V_39 = F_26 ( V_17 ) ;
if ( V_39 )
goto V_39;
return 0 ;
V_39:
if ( V_20 ) {
V_17 -> V_20 = NULL ;
F_42 ( V_20 ) ;
}
return V_39 ;
}
static const char T_1 * F_43 ( struct V_64 V_65 , int V_66 )
{
const char T_1 * V_67 ;
#ifdef F_44
if ( F_45 ( V_65 . V_68 ) ) {
T_2 V_69 ;
if ( F_46 ( V_69 , V_65 . V_70 . V_69 + V_66 ) )
return F_47 ( - V_71 ) ;
return F_48 ( V_69 ) ;
}
#endif
if ( F_46 ( V_67 , V_65 . V_70 . V_67 + V_66 ) )
return F_47 ( - V_71 ) ;
return V_67 ;
}
static int F_49 ( struct V_64 V_65 , int V_72 )
{
int V_62 = 0 ;
if ( V_65 . V_70 . V_67 != NULL ) {
for (; ; ) {
const char T_1 * V_57 = F_43 ( V_65 , V_62 ) ;
if ( ! V_57 )
break;
if ( F_50 ( V_57 ) )
return - V_71 ;
if ( V_62 >= V_72 )
return - V_73 ;
++ V_62 ;
if ( F_51 ( V_21 ) )
return - V_74 ;
F_52 () ;
}
}
return V_62 ;
}
static int F_53 ( int V_75 , struct V_64 V_65 ,
struct V_16 * V_17 )
{
struct V_25 * V_76 = NULL ;
char * V_77 = NULL ;
unsigned long V_78 = 0 ;
int V_28 ;
while ( V_75 -- > 0 ) {
const char T_1 * V_79 ;
int V_58 ;
unsigned long V_26 ;
V_28 = - V_71 ;
V_79 = F_43 ( V_65 , V_75 ) ;
if ( F_50 ( V_79 ) )
goto V_80;
V_58 = F_54 ( V_79 , V_59 ) ;
if ( ! V_58 )
goto V_80;
V_28 = - V_73 ;
if ( ! F_36 ( V_17 , V_58 ) )
goto V_80;
V_26 = V_17 -> V_57 ;
V_79 += V_58 ;
V_17 -> V_57 -= V_58 ;
while ( V_58 > 0 ) {
int V_81 , V_82 ;
if ( F_51 ( V_21 ) ) {
V_28 = - V_74 ;
goto V_80;
}
F_52 () ;
V_81 = V_26 % V_35 ;
if ( V_81 == 0 )
V_81 = V_35 ;
V_82 = V_81 ;
if ( V_82 > V_58 )
V_82 = V_58 ;
V_81 -= V_82 ;
V_26 -= V_82 ;
V_79 -= V_82 ;
V_58 -= V_82 ;
if ( ! V_76 || V_78 != ( V_26 & V_83 ) ) {
struct V_25 * V_25 ;
V_25 = F_15 ( V_17 , V_26 , 1 ) ;
if ( ! V_25 ) {
V_28 = - V_73 ;
goto V_80;
}
if ( V_76 ) {
F_55 ( V_76 ) ;
F_56 ( V_76 ) ;
F_21 ( V_76 ) ;
}
V_76 = V_25 ;
V_77 = F_57 ( V_76 ) ;
V_78 = V_26 & V_83 ;
F_23 ( V_17 , V_78 , V_76 ) ;
}
if ( F_58 ( V_77 + V_81 , V_79 , V_82 ) ) {
V_28 = - V_71 ;
goto V_80;
}
}
}
V_28 = 0 ;
V_80:
if ( V_76 ) {
F_55 ( V_76 ) ;
F_56 ( V_76 ) ;
F_21 ( V_76 ) ;
}
return V_28 ;
}
int F_59 ( int V_75 , const char * const * V_84 ,
struct V_16 * V_17 )
{
int V_85 ;
T_3 V_86 = F_60 () ;
struct V_64 V_65 = {
. V_70 . V_67 = ( const char T_1 * const T_1 * ) V_84 ,
} ;
F_61 ( V_87 ) ;
V_85 = F_53 ( V_75 , V_65 , V_17 ) ;
F_61 ( V_86 ) ;
return V_85 ;
}
static int F_62 ( struct V_40 * V_29 , unsigned long V_88 )
{
struct V_19 * V_20 = V_29 -> V_47 ;
unsigned long V_89 = V_29 -> V_32 ;
unsigned long V_90 = V_29 -> V_31 ;
unsigned long V_91 = V_90 - V_89 ;
unsigned long V_92 = V_89 - V_88 ;
unsigned long V_93 = V_90 - V_88 ;
struct V_94 V_95 ;
F_2 ( V_92 > V_93 ) ;
if ( V_29 != F_63 ( V_20 , V_92 ) )
return - V_71 ;
if ( F_64 ( V_29 , V_92 , V_90 , V_29 -> V_96 , NULL ) )
return - V_43 ;
if ( V_91 != F_65 ( V_29 , V_89 ,
V_29 , V_92 , V_91 , false ) )
return - V_43 ;
F_66 () ;
F_67 ( & V_95 , V_20 , V_89 , V_90 ) ;
if ( V_93 > V_89 ) {
F_68 ( & V_95 , V_93 , V_90 , V_93 ,
V_29 -> V_97 ? V_29 -> V_97 -> V_32 : V_98 ) ;
} else {
F_68 ( & V_95 , V_89 , V_90 , V_93 ,
V_29 -> V_97 ? V_29 -> V_97 -> V_32 : V_98 ) ;
}
F_69 ( & V_95 , V_89 , V_90 ) ;
F_64 ( V_29 , V_92 , V_93 , V_29 -> V_96 , NULL ) ;
return 0 ;
}
int F_70 ( struct V_16 * V_17 ,
unsigned long V_99 ,
int V_100 )
{
unsigned long V_28 ;
unsigned long V_101 ;
struct V_19 * V_20 = V_21 -> V_20 ;
struct V_40 * V_29 = V_17 -> V_29 ;
struct V_40 * V_102 = NULL ;
unsigned long V_51 ;
unsigned long V_103 ;
unsigned long V_104 ;
unsigned long V_105 ;
unsigned long V_106 ;
#ifdef F_16
V_103 = F_71 ( V_37 ) ;
if ( V_103 > V_107 )
V_103 = V_107 ;
V_103 += ( V_108 << V_109 ) ;
if ( V_29 -> V_31 - V_29 -> V_32 > V_103 )
return - V_43 ;
V_103 = F_72 ( V_99 - V_103 ) ;
V_101 = V_29 -> V_32 - V_103 ;
V_20 -> V_110 = V_17 -> V_57 - V_101 ;
V_17 -> V_57 = V_29 -> V_31 - V_101 ;
#else
V_99 = F_73 ( V_99 ) ;
V_99 = F_72 ( V_99 ) ;
if ( F_45 ( V_99 < V_111 ) ||
F_45 ( V_29 -> V_31 - V_29 -> V_32 >= V_99 - V_111 ) )
return - V_43 ;
V_101 = V_29 -> V_31 - V_99 ;
V_17 -> V_57 -= V_101 ;
V_20 -> V_110 = V_17 -> V_57 ;
#endif
if ( V_17 -> V_112 )
V_17 -> V_112 -= V_101 ;
V_17 -> V_113 -= V_101 ;
if ( F_28 ( & V_20 -> V_44 ) )
return - V_45 ;
V_51 = V_48 ;
if ( F_45 ( V_100 == V_114 ) )
V_51 |= V_115 ;
else if ( V_100 == V_116 )
V_51 &= ~ V_115 ;
V_51 |= V_20 -> V_117 ;
V_51 |= V_49 ;
V_28 = F_74 ( V_29 , & V_102 , V_29 -> V_32 , V_29 -> V_31 ,
V_51 ) ;
if ( V_28 )
goto V_118;
F_2 ( V_102 != V_29 ) ;
if ( V_101 ) {
V_28 = F_62 ( V_29 , V_101 ) ;
if ( V_28 )
goto V_118;
}
V_29 -> V_51 &= ~ V_49 ;
V_105 = 131072UL ;
V_104 = V_29 -> V_31 - V_29 -> V_32 ;
V_106 = V_33 ( V_37 ) & V_83 ;
#ifdef F_16
if ( V_104 + V_105 > V_106 )
V_103 = V_29 -> V_32 + V_106 ;
else
V_103 = V_29 -> V_31 + V_105 ;
#else
if ( V_104 + V_105 > V_106 )
V_103 = V_29 -> V_31 - V_106 ;
else
V_103 = V_29 -> V_32 - V_105 ;
#endif
V_21 -> V_20 -> V_119 = V_17 -> V_57 ;
V_28 = F_75 ( V_29 , V_103 ) ;
if ( V_28 )
V_28 = - V_71 ;
V_118:
F_34 ( & V_20 -> V_44 ) ;
return V_28 ;
}
static struct V_120 * F_76 ( int V_121 , struct V_122 * V_123 , int V_124 )
{
struct V_120 * V_120 ;
int V_39 ;
struct V_125 V_126 = {
. V_127 = V_128 | V_129 | V_130 ,
. V_131 = V_132 ,
. V_133 = V_134 ,
. V_135 = V_136 ,
} ;
if ( ( V_124 & ~ ( V_137 | V_138 ) ) != 0 )
return F_47 ( - V_139 ) ;
if ( V_124 & V_137 )
V_126 . V_135 &= ~ V_136 ;
if ( V_124 & V_138 )
V_126 . V_135 |= V_140 ;
V_120 = F_77 ( V_121 , V_123 , & V_126 ) ;
if ( F_50 ( V_120 ) )
goto V_80;
V_39 = - V_141 ;
if ( ! F_78 ( F_79 ( V_120 ) -> V_142 ) )
goto exit;
if ( F_12 ( & V_120 -> V_143 ) )
goto exit;
V_39 = F_80 ( V_120 ) ;
if ( V_39 )
goto exit;
if ( V_123 -> V_123 [ 0 ] != '\0' )
F_81 ( V_120 ) ;
V_80:
return V_120 ;
exit:
F_82 ( V_120 ) ;
return F_47 ( V_39 ) ;
}
struct V_120 * F_83 ( const char * V_123 )
{
struct V_122 * V_122 = F_84 ( V_123 ) ;
struct V_120 * V_144 = F_85 ( V_122 ) ;
if ( ! F_50 ( V_122 ) ) {
V_144 = F_76 ( V_145 , V_122 , 0 ) ;
F_86 ( V_122 ) ;
}
return V_144 ;
}
int F_87 ( struct V_120 * V_120 , T_4 V_81 ,
char * V_146 , unsigned long F_49 )
{
T_3 V_147 ;
T_4 V_26 = V_81 ;
int V_148 ;
V_147 = F_60 () ;
F_61 ( F_88 () ) ;
V_148 = F_89 ( V_120 , ( void T_1 * ) V_146 , F_49 , & V_26 ) ;
F_61 ( V_147 ) ;
return V_148 ;
}
int F_90 ( struct V_120 * V_120 , void * * V_149 , T_4 * V_30 ,
T_4 V_150 , enum V_151 V_152 )
{
T_4 V_153 , V_26 ;
T_5 V_154 = 0 ;
int V_28 ;
if ( ! F_78 ( F_79 ( V_120 ) -> V_142 ) || V_150 < 0 )
return - V_139 ;
V_28 = F_91 ( V_120 , V_152 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_80 ( V_120 ) ;
if ( V_28 )
return V_28 ;
V_153 = F_92 ( F_79 ( V_120 ) ) ;
if ( V_150 > 0 && V_153 > V_150 ) {
V_28 = - V_155 ;
goto V_80;
}
if ( V_153 <= 0 ) {
V_28 = - V_139 ;
goto V_80;
}
* V_149 = F_93 ( V_153 ) ;
if ( ! * V_149 ) {
V_28 = - V_43 ;
goto V_80;
}
V_26 = 0 ;
while ( V_26 < V_153 ) {
V_154 = F_87 ( V_120 , V_26 , ( char * ) ( * V_149 ) + V_26 ,
V_153 - V_26 ) ;
if ( V_154 < 0 ) {
V_28 = V_154 ;
goto V_80;
}
if ( V_154 == 0 )
break;
V_26 += V_154 ;
}
if ( V_26 != V_153 ) {
V_28 = - V_156 ;
goto V_157;
}
V_28 = F_94 ( V_120 , * V_149 , V_153 , V_152 ) ;
if ( ! V_28 )
* V_30 = V_26 ;
V_157:
if ( V_28 < 0 ) {
F_95 ( * V_149 ) ;
* V_149 = NULL ;
}
V_80:
F_96 ( V_120 ) ;
return V_28 ;
}
int F_97 ( char * V_9 , void * * V_149 , T_4 * V_30 ,
T_4 V_150 , enum V_151 V_152 )
{
struct V_120 * V_120 ;
int V_28 ;
if ( ! V_9 || ! * V_9 )
return - V_139 ;
V_120 = F_98 ( V_9 , V_129 , 0 ) ;
if ( F_50 ( V_120 ) )
return F_99 ( V_120 ) ;
V_28 = F_90 ( V_120 , V_149 , V_30 , V_150 , V_152 ) ;
F_82 ( V_120 ) ;
return V_28 ;
}
int F_100 ( int V_121 , void * * V_149 , T_4 * V_30 , T_4 V_150 ,
enum V_151 V_152 )
{
struct V_121 V_144 = F_101 ( V_121 ) ;
int V_28 = - V_158 ;
if ( ! V_144 . V_120 )
goto V_80;
V_28 = F_90 ( V_144 . V_120 , V_149 , V_30 , V_150 , V_152 ) ;
V_80:
F_102 ( V_144 ) ;
return V_28 ;
}
T_5 F_103 ( struct V_120 * V_120 , unsigned long V_146 , T_4 V_26 , T_6 V_58 )
{
T_5 V_159 = F_89 ( V_120 , ( void T_1 * ) V_146 , V_58 , & V_26 ) ;
if ( V_159 > 0 )
F_104 ( V_146 , V_146 + V_58 ) ;
return V_159 ;
}
static int F_105 ( struct V_19 * V_20 )
{
struct V_160 * V_161 ;
struct V_19 * V_162 , * V_163 ;
V_161 = V_21 ;
V_162 = V_21 -> V_20 ;
F_106 ( V_161 , V_162 ) ;
if ( V_162 ) {
F_107 ( V_162 ) ;
F_108 ( & V_162 -> V_44 ) ;
if ( F_45 ( V_162 -> V_164 ) ) {
F_109 ( & V_162 -> V_44 ) ;
return - V_45 ;
}
}
F_110 ( V_161 ) ;
V_163 = V_161 -> V_163 ;
V_161 -> V_20 = V_20 ;
V_161 -> V_163 = V_20 ;
F_111 ( V_163 , V_20 ) ;
V_161 -> V_20 -> V_165 = 0 ;
F_112 ( V_161 ) ;
F_113 ( V_161 ) ;
if ( V_162 ) {
F_109 ( & V_162 -> V_44 ) ;
F_2 ( V_163 != V_162 ) ;
F_114 ( & V_161 -> signal -> V_166 , V_162 ) ;
F_115 ( V_162 ) ;
F_116 ( V_162 ) ;
return 0 ;
}
F_42 ( V_163 ) ;
return 0 ;
}
static int F_117 ( struct V_160 * V_161 )
{
struct V_167 * V_168 = V_161 -> signal ;
struct V_169 * V_170 = V_161 -> V_171 ;
T_7 * V_172 = & V_170 -> V_173 ;
if ( F_118 ( V_161 ) )
goto V_174;
F_119 ( V_172 ) ;
if ( F_120 ( V_168 ) ) {
F_121 ( V_172 ) ;
return - V_175 ;
}
V_168 -> V_176 = V_161 ;
V_168 -> V_177 = F_122 ( V_161 ) ;
if ( ! F_123 ( V_161 ) )
V_168 -> V_177 -- ;
while ( V_168 -> V_177 ) {
F_124 ( V_178 ) ;
F_121 ( V_172 ) ;
F_125 () ;
if ( F_45 ( F_126 ( V_161 ) ) )
goto V_179;
F_119 ( V_172 ) ;
}
F_121 ( V_172 ) ;
if ( ! F_123 ( V_161 ) ) {
struct V_160 * V_180 = V_161 -> V_181 ;
for (; ; ) {
F_127 ( V_161 ) ;
F_128 ( & V_182 ) ;
V_168 -> V_177 = - 1 ;
if ( F_129 ( V_180 -> V_183 ) )
break;
F_124 ( V_178 ) ;
F_130 ( & V_182 ) ;
F_131 ( V_161 ) ;
F_125 () ;
if ( F_45 ( F_126 ( V_161 ) ) )
goto V_179;
}
V_161 -> V_184 = V_180 -> V_184 ;
V_161 -> V_185 = V_180 -> V_185 ;
F_2 ( ! F_132 ( V_180 , V_161 ) ) ;
F_2 ( F_133 ( V_161 ) ) ;
V_161 -> V_186 = V_180 -> V_186 ;
F_134 ( V_161 , V_187 , F_135 ( V_180 ) ) ;
F_136 ( V_180 , V_161 , V_188 ) ;
F_136 ( V_180 , V_161 , V_189 ) ;
F_137 ( & V_180 -> V_190 , & V_161 -> V_190 ) ;
F_138 ( & V_180 -> V_191 , & V_161 -> V_191 ) ;
V_161 -> V_181 = V_161 ;
V_180 -> V_181 = V_161 ;
V_161 -> V_192 = V_193 ;
V_180 -> V_192 = - 1 ;
F_2 ( V_180 -> V_183 != V_194 ) ;
V_180 -> V_183 = V_195 ;
if ( F_45 ( V_180 -> V_196 ) )
F_139 ( V_180 , V_180 -> V_197 ) ;
F_130 ( & V_182 ) ;
F_131 ( V_161 ) ;
F_140 ( V_180 ) ;
}
V_168 -> V_176 = NULL ;
V_168 -> V_177 = 0 ;
V_174:
V_161 -> V_192 = V_193 ;
F_141 ( V_168 ) ;
F_142 () ;
if ( F_143 ( & V_170 -> F_49 ) != 1 ) {
struct V_169 * V_198 ;
V_198 = F_144 ( V_199 , V_42 ) ;
if ( ! V_198 )
return - V_43 ;
F_145 ( & V_198 -> F_49 , 1 ) ;
memcpy ( V_198 -> V_200 , V_170 -> V_200 ,
sizeof( V_198 -> V_200 ) ) ;
F_128 ( & V_182 ) ;
F_146 ( & V_170 -> V_173 ) ;
F_147 ( V_161 -> V_171 , V_198 ) ;
F_148 ( & V_170 -> V_173 ) ;
F_130 ( & V_182 ) ;
F_149 ( V_170 ) ;
}
F_2 ( ! F_123 ( V_161 ) ) ;
return 0 ;
V_179:
F_150 ( & V_182 ) ;
V_168 -> V_176 = NULL ;
V_168 -> V_177 = 0 ;
F_151 ( & V_182 ) ;
return - V_175 ;
}
char * F_152 ( char * V_149 , struct V_160 * V_161 )
{
F_110 ( V_161 ) ;
strncpy ( V_149 , V_161 -> V_201 , sizeof( V_161 -> V_201 ) ) ;
F_113 ( V_161 ) ;
return V_149 ;
}
void F_153 ( struct V_160 * V_161 , const char * V_149 , bool V_113 )
{
F_110 ( V_161 ) ;
F_154 ( V_161 , V_149 ) ;
F_155 ( V_161 -> V_201 , V_149 , sizeof( V_161 -> V_201 ) ) ;
F_113 ( V_161 ) ;
F_156 ( V_161 , V_113 ) ;
}
int F_157 ( struct V_16 * V_17 )
{
int V_202 ;
V_202 = F_117 ( V_21 ) ;
if ( V_202 )
goto V_80;
F_158 ( V_17 -> V_20 , V_17 -> V_120 ) ;
F_13 ( V_17 , 0 ) ;
V_202 = F_105 ( V_17 -> V_20 ) ;
if ( V_202 )
goto V_80;
V_17 -> V_20 = NULL ;
F_61 ( V_203 ) ;
V_21 -> V_124 &= ~ ( V_204 | V_205 | V_206 |
V_207 | V_208 ) ;
F_159 () ;
V_21 -> V_209 &= ~ V_17 -> V_210 ;
return 0 ;
V_80:
return V_202 ;
}
void F_160 ( struct V_16 * V_17 , struct V_120 * V_120 )
{
if ( F_161 ( F_79 ( V_120 ) , V_211 ) < 0 )
V_17 -> V_212 |= V_213 ;
}
void F_162 ( struct V_16 * V_17 )
{
F_163 ( V_21 -> V_20 ) ;
V_21 -> V_214 = V_21 -> V_215 = 0 ;
if ( F_164 ( F_165 () , F_166 () ) && F_167 ( F_168 () , F_169 () ) )
F_170 ( V_21 -> V_20 , V_216 ) ;
else
F_170 ( V_21 -> V_20 , V_217 ) ;
F_171 () ;
F_153 ( V_21 , F_172 ( V_17 -> V_122 ) , true ) ;
V_21 -> V_20 -> V_218 = V_219 ;
if ( ! F_164 ( V_17 -> V_220 -> V_221 , F_165 () ) ||
! F_167 ( V_17 -> V_220 -> V_222 , F_168 () ) ) {
V_21 -> V_223 = 0 ;
} else {
F_160 ( V_17 , V_17 -> V_120 ) ;
if ( V_17 -> V_212 & V_213 )
F_170 ( V_21 -> V_20 , V_217 ) ;
}
V_21 -> V_224 ++ ;
F_173 ( V_21 , 0 ) ;
F_174 ( V_21 -> V_225 ) ;
}
int F_175 ( struct V_16 * V_17 )
{
if ( F_176 ( & V_21 -> signal -> V_226 ) )
return - V_227 ;
V_17 -> V_220 = F_177 () ;
if ( F_129 ( V_17 -> V_220 ) )
return 0 ;
F_178 ( & V_21 -> signal -> V_226 ) ;
return - V_43 ;
}
static void F_179 ( struct V_16 * V_17 )
{
F_22 ( V_17 ) ;
if ( V_17 -> V_220 ) {
F_178 ( & V_21 -> signal -> V_226 ) ;
F_180 ( V_17 -> V_220 ) ;
}
if ( V_17 -> V_120 ) {
F_96 ( V_17 -> V_120 ) ;
F_82 ( V_17 -> V_120 ) ;
}
if ( V_17 -> V_228 != V_17 -> V_122 )
F_181 ( V_17 -> V_228 ) ;
F_181 ( V_17 ) ;
}
int F_182 ( char * V_228 , struct V_16 * V_17 )
{
if ( V_17 -> V_228 != V_17 -> V_122 )
F_181 ( V_17 -> V_228 ) ;
V_17 -> V_228 = F_183 ( V_228 , V_42 ) ;
if ( ! V_17 -> V_228 )
return - V_43 ;
return 0 ;
}
void F_184 ( struct V_16 * V_17 )
{
F_185 ( V_17 ) ;
F_186 ( V_17 -> V_220 ) ;
V_17 -> V_220 = NULL ;
if ( F_187 ( V_21 -> V_20 ) != V_216 )
F_188 ( V_21 ) ;
F_189 ( V_17 ) ;
F_178 ( & V_21 -> signal -> V_226 ) ;
}
static void F_190 ( struct V_16 * V_17 )
{
struct V_160 * V_57 = V_21 , * V_229 ;
unsigned V_230 ;
if ( V_57 -> V_196 ) {
if ( V_57 -> V_196 & V_231 )
V_17 -> V_232 |= V_233 ;
else
V_17 -> V_232 |= V_234 ;
}
if ( F_191 ( V_21 ) )
V_17 -> V_232 |= V_235 ;
V_229 = V_57 ;
V_230 = 1 ;
F_146 ( & V_57 -> V_236 -> V_172 ) ;
F_192 () ;
F_193 (p, t) {
if ( V_229 -> V_236 == V_57 -> V_236 )
V_230 ++ ;
}
F_194 () ;
if ( V_57 -> V_236 -> V_237 > V_230 )
V_17 -> V_232 |= V_238 ;
else
V_57 -> V_236 -> V_239 = 1 ;
F_148 ( & V_57 -> V_236 -> V_172 ) ;
}
static void F_195 ( struct V_16 * V_17 )
{
struct V_240 * V_240 ;
unsigned int V_241 ;
T_8 V_221 ;
T_9 V_222 ;
V_17 -> V_220 -> V_242 = F_165 () ;
V_17 -> V_220 -> V_243 = F_168 () ;
if ( V_17 -> V_120 -> V_143 . V_10 -> V_11 & V_244 )
return;
if ( F_191 ( V_21 ) )
return;
V_240 = F_79 ( V_17 -> V_120 ) ;
V_241 = F_196 ( V_240 -> V_142 ) ;
if ( ! ( V_241 & ( V_245 | V_246 ) ) )
return;
F_197 ( V_240 ) ;
V_241 = V_240 -> V_142 ;
V_221 = V_240 -> V_247 ;
V_222 = V_240 -> V_248 ;
F_198 ( V_240 ) ;
if ( ! F_199 ( V_17 -> V_220 -> V_249 , V_221 ) ||
! F_200 ( V_17 -> V_220 -> V_249 , V_222 ) )
return;
if ( V_241 & V_245 ) {
V_17 -> V_210 |= V_250 ;
V_17 -> V_220 -> V_242 = V_221 ;
}
if ( ( V_241 & ( V_246 | V_251 ) ) == ( V_246 | V_251 ) ) {
V_17 -> V_210 |= V_250 ;
V_17 -> V_220 -> V_243 = V_222 ;
}
}
int F_201 ( struct V_16 * V_17 )
{
int V_202 ;
F_195 ( V_17 ) ;
V_202 = F_202 ( V_17 ) ;
if ( V_202 )
return V_202 ;
V_17 -> V_252 = 1 ;
memset ( V_17 -> V_149 , 0 , V_253 ) ;
return F_87 ( V_17 -> V_120 , 0 , V_17 -> V_149 , V_253 ) ;
}
int F_203 ( struct V_16 * V_17 )
{
int V_28 = 0 ;
unsigned long V_81 ;
char * V_77 ;
struct V_25 * V_25 ;
if ( ! V_17 -> V_75 )
return 0 ;
do {
V_81 = V_17 -> V_57 & ~ V_83 ;
V_25 = F_15 ( V_17 , V_17 -> V_57 , 0 ) ;
if ( ! V_25 ) {
V_28 = - V_71 ;
goto V_80;
}
V_77 = F_204 ( V_25 ) ;
for (; V_81 < V_35 && V_77 [ V_81 ] ;
V_81 ++ , V_17 -> V_57 ++ )
;
F_205 ( V_77 ) ;
F_21 ( V_25 ) ;
} while ( V_81 == V_35 );
V_17 -> V_57 ++ ;
V_17 -> V_75 -- ;
V_28 = 0 ;
V_80:
return V_28 ;
}
int F_206 ( struct V_16 * V_17 )
{
bool V_254 = F_207 ( V_255 ) ;
struct V_1 * V_2 ;
int V_202 ;
if ( V_17 -> V_256 > 5 )
return - V_257 ;
V_202 = F_208 ( V_17 ) ;
if ( V_202 )
return V_202 ;
V_202 = - V_258 ;
V_259:
F_150 ( & V_5 ) ;
F_209 (fmt, &formats, lh) {
if ( ! F_210 ( V_2 -> V_8 ) )
continue;
F_151 ( & V_5 ) ;
V_17 -> V_256 ++ ;
V_202 = V_2 -> V_4 ( V_17 ) ;
F_150 ( & V_5 ) ;
F_10 ( V_2 ) ;
V_17 -> V_256 -- ;
if ( V_202 < 0 && ! V_17 -> V_20 ) {
F_151 ( & V_5 ) ;
F_211 ( V_260 , V_21 ) ;
return V_202 ;
}
if ( V_202 != - V_261 || ! V_17 -> V_120 ) {
F_151 ( & V_5 ) ;
return V_202 ;
}
}
F_151 ( & V_5 ) ;
if ( V_254 ) {
if ( F_212 ( V_17 -> V_149 [ 0 ] ) && F_212 ( V_17 -> V_149 [ 1 ] ) &&
F_212 ( V_17 -> V_149 [ 2 ] ) && F_212 ( V_17 -> V_149 [ 3 ] ) )
return V_202 ;
if ( F_213 ( L_1 , * ( V_262 * ) ( V_17 -> V_149 + 2 ) ) < 0 )
return V_202 ;
V_254 = false ;
goto V_259;
}
return V_202 ;
}
static int F_214 ( struct V_16 * V_17 )
{
T_10 V_263 , V_264 ;
int V_28 ;
V_263 = V_21 -> V_186 ;
F_192 () ;
V_264 = F_215 ( V_21 , F_216 ( V_21 -> V_197 ) ) ;
F_194 () ;
V_28 = F_206 ( V_17 ) ;
if ( V_28 >= 0 ) {
F_217 ( V_17 ) ;
F_218 ( V_21 , V_263 , V_17 ) ;
F_219 ( V_265 , V_264 ) ;
F_220 ( V_21 ) ;
}
return V_28 ;
}
static int F_221 ( int V_121 , struct V_122 * V_122 ,
struct V_64 V_65 ,
struct V_64 V_266 ,
int V_124 )
{
char * V_267 = NULL ;
struct V_16 * V_17 ;
struct V_120 * V_120 ;
struct V_268 * V_269 ;
int V_202 ;
if ( F_50 ( V_122 ) )
return F_99 ( V_122 ) ;
if ( ( V_21 -> V_124 & V_270 ) &&
F_143 ( & F_222 () -> V_271 ) > V_33 ( V_272 ) ) {
V_202 = - V_175 ;
goto V_273;
}
V_21 -> V_124 &= ~ V_270 ;
V_202 = F_223 ( & V_269 ) ;
if ( V_202 )
goto V_273;
V_202 = - V_43 ;
V_17 = F_224 ( sizeof( * V_17 ) , V_42 ) ;
if ( ! V_17 )
goto V_274;
V_202 = F_175 ( V_17 ) ;
if ( V_202 )
goto V_157;
F_190 ( V_17 ) ;
V_21 -> V_275 = 1 ;
V_120 = F_76 ( V_121 , V_122 , V_124 ) ;
V_202 = F_99 ( V_120 ) ;
if ( F_50 ( V_120 ) )
goto V_276;
F_225 () ;
V_17 -> V_120 = V_120 ;
if ( V_121 == V_145 || V_122 -> V_123 [ 0 ] == '/' ) {
V_17 -> V_122 = V_122 -> V_123 ;
} else {
if ( V_122 -> V_123 [ 0 ] == '\0' )
V_267 = F_226 ( V_277 , L_2 , V_121 ) ;
else
V_267 = F_226 ( V_277 , L_3 ,
V_121 , V_122 -> V_123 ) ;
if ( ! V_267 ) {
V_202 = - V_43 ;
goto V_276;
}
if ( F_227 ( V_121 , F_228 ( V_21 -> V_225 -> V_278 ) ) )
V_17 -> V_212 |= V_279 ;
V_17 -> V_122 = V_267 ;
}
V_17 -> V_228 = V_17 -> V_122 ;
V_202 = F_40 ( V_17 ) ;
if ( V_202 )
goto V_276;
V_17 -> V_75 = F_49 ( V_65 , V_280 ) ;
if ( ( V_202 = V_17 -> V_75 ) < 0 )
goto V_80;
V_17 -> V_281 = F_49 ( V_266 , V_280 ) ;
if ( ( V_202 = V_17 -> V_281 ) < 0 )
goto V_80;
V_202 = F_201 ( V_17 ) ;
if ( V_202 < 0 )
goto V_80;
V_202 = F_59 ( 1 , & V_17 -> V_122 , V_17 ) ;
if ( V_202 < 0 )
goto V_80;
V_17 -> V_113 = V_17 -> V_57 ;
V_202 = F_53 ( V_17 -> V_281 , V_266 , V_17 ) ;
if ( V_202 < 0 )
goto V_80;
V_202 = F_53 ( V_17 -> V_75 , V_65 , V_17 ) ;
if ( V_202 < 0 )
goto V_80;
V_202 = F_214 ( V_17 ) ;
if ( V_202 < 0 )
goto V_80;
V_21 -> V_236 -> V_239 = 0 ;
V_21 -> V_275 = 0 ;
F_229 ( V_21 ) ;
F_230 ( V_21 ) ;
F_179 ( V_17 ) ;
F_181 ( V_267 ) ;
F_86 ( V_122 ) ;
if ( V_269 )
F_231 ( V_269 ) ;
return V_202 ;
V_80:
if ( V_17 -> V_20 ) {
F_13 ( V_17 , 0 ) ;
F_116 ( V_17 -> V_20 ) ;
}
V_276:
V_21 -> V_236 -> V_239 = 0 ;
V_21 -> V_275 = 0 ;
V_157:
F_179 ( V_17 ) ;
F_181 ( V_267 ) ;
V_274:
if ( V_269 )
F_232 ( V_269 ) ;
V_273:
F_86 ( V_122 ) ;
return V_202 ;
}
int F_233 ( struct V_122 * V_122 ,
const char T_1 * const T_1 * V_84 ,
const char T_1 * const T_1 * V_282 )
{
struct V_64 V_65 = { . V_70 . V_67 = V_84 } ;
struct V_64 V_266 = { . V_70 . V_67 = V_282 } ;
return F_221 ( V_145 , V_122 , V_65 , V_266 , 0 ) ;
}
int F_234 ( int V_121 , struct V_122 * V_122 ,
const char T_1 * const T_1 * V_84 ,
const char T_1 * const T_1 * V_282 ,
int V_124 )
{
struct V_64 V_65 = { . V_70 . V_67 = V_84 } ;
struct V_64 V_266 = { . V_70 . V_67 = V_282 } ;
return F_221 ( V_121 , V_122 , V_65 , V_266 , V_124 ) ;
}
static int F_235 ( struct V_122 * V_122 ,
const T_2 T_1 * V_84 ,
const T_2 T_1 * V_282 )
{
struct V_64 V_65 = {
. V_68 = true ,
. V_70 . V_69 = V_84 ,
} ;
struct V_64 V_266 = {
. V_68 = true ,
. V_70 . V_69 = V_282 ,
} ;
return F_221 ( V_145 , V_122 , V_65 , V_266 , 0 ) ;
}
static int F_236 ( int V_121 , struct V_122 * V_122 ,
const T_2 T_1 * V_84 ,
const T_2 T_1 * V_282 ,
int V_124 )
{
struct V_64 V_65 = {
. V_68 = true ,
. V_70 . V_69 = V_84 ,
} ;
struct V_64 V_266 = {
. V_68 = true ,
. V_70 . V_69 = V_282 ,
} ;
return F_221 ( V_121 , V_122 , V_65 , V_266 , V_124 ) ;
}
void F_237 ( struct V_1 * V_283 )
{
struct V_19 * V_20 = V_21 -> V_20 ;
if ( V_20 -> V_284 )
F_11 ( V_20 -> V_284 -> V_8 ) ;
V_20 -> V_284 = V_283 ;
if ( V_283 )
F_238 ( V_283 -> V_8 ) ;
}
void F_170 ( struct V_19 * V_20 , int V_285 )
{
unsigned long V_286 , V_283 ;
if ( F_3 ( ( unsigned ) V_285 > V_287 ) )
return;
do {
V_286 = F_19 ( V_20 -> V_124 ) ;
V_283 = ( V_286 & ~ V_288 ) | V_285 ;
} while ( F_239 ( & V_20 -> V_124 , V_286 , V_283 ) != V_286 );
}
