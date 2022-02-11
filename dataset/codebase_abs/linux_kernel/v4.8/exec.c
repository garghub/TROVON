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
int F_76 ( struct V_16 * V_17 ,
unsigned long * V_120 )
{
unsigned long V_121 , V_122 , V_123 ;
int V_28 = 0 ;
V_122 = V_17 -> V_57 >> V_109 ;
V_123 = * V_120 ;
for ( V_121 = V_63 - 1 ; V_121 >= V_122 ; V_121 -- ) {
unsigned int V_81 = V_121 == V_122 ? V_17 -> V_57 & ~ V_83 : 0 ;
char * V_124 = F_57 ( V_17 -> V_25 [ V_121 ] ) + V_81 ;
V_123 -= V_35 - V_81 ;
if ( F_77 ( ( void * ) V_123 , V_124 , V_35 - V_81 ) != 0 )
V_28 = - V_71 ;
F_56 ( V_17 -> V_25 [ V_121 ] ) ;
if ( V_28 )
goto V_80;
}
* V_120 = V_123 ;
V_80:
return V_28 ;
}
static struct V_125 * F_78 ( int V_126 , struct V_127 * V_128 , int V_129 )
{
struct V_125 * V_125 ;
int V_39 ;
struct V_130 V_131 = {
. V_132 = V_133 | V_134 | V_135 ,
. V_136 = V_137 ,
. V_138 = V_139 ,
. V_140 = V_141 ,
} ;
if ( ( V_129 & ~ ( V_142 | V_143 ) ) != 0 )
return F_47 ( - V_144 ) ;
if ( V_129 & V_142 )
V_131 . V_140 &= ~ V_141 ;
if ( V_129 & V_143 )
V_131 . V_140 |= V_145 ;
V_125 = F_79 ( V_126 , V_128 , & V_131 ) ;
if ( F_50 ( V_125 ) )
goto V_80;
V_39 = - V_146 ;
if ( ! F_80 ( F_81 ( V_125 ) -> V_147 ) )
goto exit;
if ( F_12 ( & V_125 -> V_148 ) )
goto exit;
V_39 = F_82 ( V_125 ) ;
if ( V_39 )
goto exit;
if ( V_128 -> V_128 [ 0 ] != '\0' )
F_83 ( V_125 ) ;
V_80:
return V_125 ;
exit:
F_84 ( V_125 ) ;
return F_47 ( V_39 ) ;
}
struct V_125 * F_85 ( const char * V_128 )
{
struct V_127 * V_127 = F_86 ( V_128 ) ;
struct V_125 * V_149 = F_87 ( V_127 ) ;
if ( ! F_50 ( V_127 ) ) {
V_149 = F_78 ( V_150 , V_127 , 0 ) ;
F_88 ( V_127 ) ;
}
return V_149 ;
}
int F_89 ( struct V_125 * V_125 , T_4 V_81 ,
char * V_151 , unsigned long F_49 )
{
T_3 V_152 ;
T_4 V_26 = V_81 ;
int V_153 ;
V_152 = F_60 () ;
F_61 ( F_90 () ) ;
V_153 = F_91 ( V_125 , ( void T_1 * ) V_151 , F_49 , & V_26 ) ;
F_61 ( V_152 ) ;
return V_153 ;
}
int F_92 ( struct V_125 * V_125 , void * * V_154 , T_4 * V_30 ,
T_4 V_155 , enum V_156 V_157 )
{
T_4 V_158 , V_26 ;
T_5 V_159 = 0 ;
int V_28 ;
if ( ! F_80 ( F_81 ( V_125 ) -> V_147 ) || V_155 < 0 )
return - V_144 ;
V_28 = F_93 ( V_125 , V_157 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_82 ( V_125 ) ;
if ( V_28 )
return V_28 ;
V_158 = F_94 ( F_81 ( V_125 ) ) ;
if ( V_155 > 0 && V_158 > V_155 ) {
V_28 = - V_160 ;
goto V_80;
}
if ( V_158 <= 0 ) {
V_28 = - V_144 ;
goto V_80;
}
if ( V_157 != V_161 )
* V_154 = F_95 ( V_158 ) ;
if ( ! * V_154 ) {
V_28 = - V_43 ;
goto V_80;
}
V_26 = 0 ;
while ( V_26 < V_158 ) {
V_159 = F_89 ( V_125 , V_26 , ( char * ) ( * V_154 ) + V_26 ,
V_158 - V_26 ) ;
if ( V_159 < 0 ) {
V_28 = V_159 ;
goto V_80;
}
if ( V_159 == 0 )
break;
V_26 += V_159 ;
}
if ( V_26 != V_158 ) {
V_28 = - V_162 ;
goto V_163;
}
V_28 = F_96 ( V_125 , * V_154 , V_158 , V_157 ) ;
if ( ! V_28 )
* V_30 = V_26 ;
V_163:
if ( V_28 < 0 ) {
if ( V_157 != V_161 ) {
F_97 ( * V_154 ) ;
* V_154 = NULL ;
}
}
V_80:
F_98 ( V_125 ) ;
return V_28 ;
}
int F_99 ( char * V_9 , void * * V_154 , T_4 * V_30 ,
T_4 V_155 , enum V_156 V_157 )
{
struct V_125 * V_125 ;
int V_28 ;
if ( ! V_9 || ! * V_9 )
return - V_144 ;
V_125 = F_100 ( V_9 , V_134 , 0 ) ;
if ( F_50 ( V_125 ) )
return F_101 ( V_125 ) ;
V_28 = F_92 ( V_125 , V_154 , V_30 , V_155 , V_157 ) ;
F_84 ( V_125 ) ;
return V_28 ;
}
int F_102 ( int V_126 , void * * V_154 , T_4 * V_30 , T_4 V_155 ,
enum V_156 V_157 )
{
struct V_126 V_149 = F_103 ( V_126 ) ;
int V_28 = - V_164 ;
if ( ! V_149 . V_125 )
goto V_80;
V_28 = F_92 ( V_149 . V_125 , V_154 , V_30 , V_155 , V_157 ) ;
V_80:
F_104 ( V_149 ) ;
return V_28 ;
}
T_5 F_105 ( struct V_125 * V_125 , unsigned long V_151 , T_4 V_26 , T_6 V_58 )
{
T_5 V_165 = F_91 ( V_125 , ( void T_1 * ) V_151 , V_58 , & V_26 ) ;
if ( V_165 > 0 )
F_106 ( V_151 , V_151 + V_58 ) ;
return V_165 ;
}
static int F_107 ( struct V_19 * V_20 )
{
struct V_166 * V_167 ;
struct V_19 * V_168 , * V_169 ;
V_167 = V_21 ;
V_168 = V_21 -> V_20 ;
F_108 ( V_167 , V_168 ) ;
if ( V_168 ) {
F_109 ( V_168 ) ;
F_110 ( & V_168 -> V_44 ) ;
if ( F_45 ( V_168 -> V_170 ) ) {
F_111 ( & V_168 -> V_44 ) ;
return - V_45 ;
}
}
F_112 ( V_167 ) ;
V_169 = V_167 -> V_169 ;
V_167 -> V_20 = V_20 ;
V_167 -> V_169 = V_20 ;
F_113 ( V_169 , V_20 ) ;
V_167 -> V_20 -> V_171 = 0 ;
F_114 ( V_167 ) ;
F_115 ( V_167 ) ;
if ( V_168 ) {
F_111 ( & V_168 -> V_44 ) ;
F_2 ( V_169 != V_168 ) ;
F_116 ( & V_167 -> signal -> V_172 , V_168 ) ;
F_117 ( V_168 ) ;
F_118 ( V_168 ) ;
return 0 ;
}
F_42 ( V_169 ) ;
return 0 ;
}
static int F_119 ( struct V_166 * V_167 )
{
struct V_173 * V_174 = V_167 -> signal ;
struct V_175 * V_176 = V_167 -> V_177 ;
T_7 * V_178 = & V_176 -> V_179 ;
if ( F_120 ( V_167 ) )
goto V_180;
F_121 ( V_178 ) ;
if ( F_122 ( V_174 ) ) {
F_123 ( V_178 ) ;
return - V_181 ;
}
V_174 -> V_182 = V_167 ;
V_174 -> V_183 = F_124 ( V_167 ) ;
if ( ! F_125 ( V_167 ) )
V_174 -> V_183 -- ;
while ( V_174 -> V_183 ) {
F_126 ( V_184 ) ;
F_123 ( V_178 ) ;
F_127 () ;
if ( F_45 ( F_128 ( V_167 ) ) )
goto V_185;
F_121 ( V_178 ) ;
}
F_123 ( V_178 ) ;
if ( ! F_125 ( V_167 ) ) {
struct V_166 * V_186 = V_167 -> V_187 ;
for (; ; ) {
F_129 ( V_167 ) ;
F_130 ( & V_188 ) ;
V_174 -> V_183 = - 1 ;
if ( F_131 ( V_186 -> V_189 ) )
break;
F_126 ( V_184 ) ;
F_132 ( & V_188 ) ;
F_133 ( V_167 ) ;
F_127 () ;
if ( F_45 ( F_128 ( V_167 ) ) )
goto V_185;
}
V_167 -> V_190 = V_186 -> V_190 ;
V_167 -> V_191 = V_186 -> V_191 ;
F_2 ( ! F_134 ( V_186 , V_167 ) ) ;
F_2 ( F_135 ( V_167 ) ) ;
V_167 -> V_192 = V_186 -> V_192 ;
F_136 ( V_167 , V_193 , F_137 ( V_186 ) ) ;
F_138 ( V_186 , V_167 , V_194 ) ;
F_138 ( V_186 , V_167 , V_195 ) ;
F_139 ( & V_186 -> V_196 , & V_167 -> V_196 ) ;
F_140 ( & V_186 -> V_197 , & V_167 -> V_197 ) ;
V_167 -> V_187 = V_167 ;
V_186 -> V_187 = V_167 ;
V_167 -> V_198 = V_199 ;
V_186 -> V_198 = - 1 ;
F_2 ( V_186 -> V_189 != V_200 ) ;
V_186 -> V_189 = V_201 ;
if ( F_45 ( V_186 -> V_202 ) )
F_141 ( V_186 , V_186 -> V_203 ) ;
F_132 ( & V_188 ) ;
F_133 ( V_167 ) ;
F_142 ( V_186 ) ;
}
V_174 -> V_182 = NULL ;
V_174 -> V_183 = 0 ;
V_180:
V_167 -> V_198 = V_199 ;
F_143 ( V_174 ) ;
F_144 () ;
if ( F_145 ( & V_176 -> F_49 ) != 1 ) {
struct V_175 * V_204 ;
V_204 = F_146 ( V_205 , V_42 ) ;
if ( ! V_204 )
return - V_43 ;
F_147 ( & V_204 -> F_49 , 1 ) ;
memcpy ( V_204 -> V_206 , V_176 -> V_206 ,
sizeof( V_204 -> V_206 ) ) ;
F_130 ( & V_188 ) ;
F_148 ( & V_176 -> V_179 ) ;
F_149 ( V_167 -> V_177 , V_204 ) ;
F_150 ( & V_176 -> V_179 ) ;
F_132 ( & V_188 ) ;
F_151 ( V_176 ) ;
}
F_2 ( ! F_125 ( V_167 ) ) ;
return 0 ;
V_185:
F_152 ( & V_188 ) ;
V_174 -> V_182 = NULL ;
V_174 -> V_183 = 0 ;
F_153 ( & V_188 ) ;
return - V_181 ;
}
char * F_154 ( char * V_154 , struct V_166 * V_167 )
{
F_112 ( V_167 ) ;
strncpy ( V_154 , V_167 -> V_207 , sizeof( V_167 -> V_207 ) ) ;
F_115 ( V_167 ) ;
return V_154 ;
}
void F_155 ( struct V_166 * V_167 , const char * V_154 , bool V_113 )
{
F_112 ( V_167 ) ;
F_156 ( V_167 , V_154 ) ;
F_157 ( V_167 -> V_207 , V_154 , sizeof( V_167 -> V_207 ) ) ;
F_115 ( V_167 ) ;
F_158 ( V_167 , V_113 ) ;
}
int F_159 ( struct V_16 * V_17 )
{
int V_208 ;
V_208 = F_119 ( V_21 ) ;
if ( V_208 )
goto V_80;
F_160 ( V_17 -> V_20 , V_17 -> V_125 ) ;
F_13 ( V_17 , 0 ) ;
V_208 = F_107 ( V_17 -> V_20 ) ;
if ( V_208 )
goto V_80;
V_17 -> V_20 = NULL ;
F_61 ( V_209 ) ;
V_21 -> V_129 &= ~ ( V_210 | V_211 | V_212 |
V_213 | V_214 ) ;
F_161 () ;
V_21 -> V_215 &= ~ V_17 -> V_216 ;
return 0 ;
V_80:
return V_208 ;
}
void F_162 ( struct V_16 * V_17 , struct V_125 * V_125 )
{
if ( F_163 ( F_81 ( V_125 ) , V_217 ) < 0 )
V_17 -> V_218 |= V_219 ;
}
void F_164 ( struct V_16 * V_17 )
{
F_165 ( V_21 -> V_20 ) ;
V_21 -> V_220 = V_21 -> V_221 = 0 ;
if ( F_166 ( F_167 () , F_168 () ) && F_169 ( F_170 () , F_171 () ) )
F_172 ( V_21 -> V_20 , V_222 ) ;
else
F_172 ( V_21 -> V_20 , V_223 ) ;
F_173 () ;
F_155 ( V_21 , F_174 ( V_17 -> V_127 ) , true ) ;
V_21 -> V_20 -> V_224 = V_225 ;
if ( ! F_166 ( V_17 -> V_226 -> V_227 , F_167 () ) ||
! F_169 ( V_17 -> V_226 -> V_228 , F_170 () ) ) {
V_21 -> V_229 = 0 ;
} else {
F_162 ( V_17 , V_17 -> V_125 ) ;
if ( V_17 -> V_218 & V_219 )
F_172 ( V_21 -> V_20 , V_223 ) ;
}
V_21 -> V_230 ++ ;
F_175 ( V_21 , 0 ) ;
F_176 ( V_21 -> V_231 ) ;
}
int F_177 ( struct V_16 * V_17 )
{
if ( F_178 ( & V_21 -> signal -> V_232 ) )
return - V_233 ;
V_17 -> V_226 = F_179 () ;
if ( F_131 ( V_17 -> V_226 ) )
return 0 ;
F_180 ( & V_21 -> signal -> V_232 ) ;
return - V_43 ;
}
static void F_181 ( struct V_16 * V_17 )
{
F_22 ( V_17 ) ;
if ( V_17 -> V_226 ) {
F_180 ( & V_21 -> signal -> V_232 ) ;
F_182 ( V_17 -> V_226 ) ;
}
if ( V_17 -> V_125 ) {
F_98 ( V_17 -> V_125 ) ;
F_84 ( V_17 -> V_125 ) ;
}
if ( V_17 -> V_234 != V_17 -> V_127 )
F_183 ( V_17 -> V_234 ) ;
F_183 ( V_17 ) ;
}
int F_184 ( char * V_234 , struct V_16 * V_17 )
{
if ( V_17 -> V_234 != V_17 -> V_127 )
F_183 ( V_17 -> V_234 ) ;
V_17 -> V_234 = F_185 ( V_234 , V_42 ) ;
if ( ! V_17 -> V_234 )
return - V_43 ;
return 0 ;
}
void F_186 ( struct V_16 * V_17 )
{
F_187 ( V_17 ) ;
F_188 ( V_17 -> V_226 ) ;
V_17 -> V_226 = NULL ;
if ( F_189 ( V_21 -> V_20 ) != V_222 )
F_190 ( V_21 ) ;
F_191 ( V_17 ) ;
F_180 ( & V_21 -> signal -> V_232 ) ;
}
static void F_192 ( struct V_16 * V_17 )
{
struct V_166 * V_57 = V_21 , * V_235 ;
unsigned V_236 ;
if ( V_57 -> V_202 ) {
if ( V_57 -> V_202 & V_237 )
V_17 -> V_238 |= V_239 ;
else
V_17 -> V_238 |= V_240 ;
}
if ( F_193 ( V_21 ) )
V_17 -> V_238 |= V_241 ;
V_235 = V_57 ;
V_236 = 1 ;
F_148 ( & V_57 -> V_242 -> V_178 ) ;
F_194 () ;
F_195 (p, t) {
if ( V_235 -> V_242 == V_57 -> V_242 )
V_236 ++ ;
}
F_196 () ;
if ( V_57 -> V_242 -> V_243 > V_236 )
V_17 -> V_238 |= V_244 ;
else
V_57 -> V_242 -> V_245 = 1 ;
F_150 ( & V_57 -> V_242 -> V_178 ) ;
}
static void F_197 ( struct V_16 * V_17 )
{
struct V_246 * V_246 ;
unsigned int V_247 ;
T_8 V_227 ;
T_9 V_228 ;
V_17 -> V_226 -> V_248 = F_167 () ;
V_17 -> V_226 -> V_249 = F_170 () ;
if ( ! F_198 ( V_17 -> V_125 -> V_148 . V_10 ) )
return;
if ( F_193 ( V_21 ) )
return;
V_246 = F_81 ( V_17 -> V_125 ) ;
V_247 = F_199 ( V_246 -> V_147 ) ;
if ( ! ( V_247 & ( V_250 | V_251 ) ) )
return;
F_200 ( V_246 ) ;
V_247 = V_246 -> V_147 ;
V_227 = V_246 -> V_252 ;
V_228 = V_246 -> V_253 ;
F_201 ( V_246 ) ;
if ( ! F_202 ( V_17 -> V_226 -> V_254 , V_227 ) ||
! F_203 ( V_17 -> V_226 -> V_254 , V_228 ) )
return;
if ( V_247 & V_250 ) {
V_17 -> V_216 |= V_255 ;
V_17 -> V_226 -> V_248 = V_227 ;
}
if ( ( V_247 & ( V_251 | V_256 ) ) == ( V_251 | V_256 ) ) {
V_17 -> V_216 |= V_255 ;
V_17 -> V_226 -> V_249 = V_228 ;
}
}
int F_204 ( struct V_16 * V_17 )
{
int V_208 ;
F_197 ( V_17 ) ;
V_208 = F_205 ( V_17 ) ;
if ( V_208 )
return V_208 ;
V_17 -> V_257 = 1 ;
memset ( V_17 -> V_154 , 0 , V_258 ) ;
return F_89 ( V_17 -> V_125 , 0 , V_17 -> V_154 , V_258 ) ;
}
int F_206 ( struct V_16 * V_17 )
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
V_77 = F_207 ( V_25 ) ;
for (; V_81 < V_35 && V_77 [ V_81 ] ;
V_81 ++ , V_17 -> V_57 ++ )
;
F_208 ( V_77 ) ;
F_21 ( V_25 ) ;
} while ( V_81 == V_35 );
V_17 -> V_57 ++ ;
V_17 -> V_75 -- ;
V_28 = 0 ;
V_80:
return V_28 ;
}
int F_209 ( struct V_16 * V_17 )
{
bool V_259 = F_210 ( V_260 ) ;
struct V_1 * V_2 ;
int V_208 ;
if ( V_17 -> V_261 > 5 )
return - V_262 ;
V_208 = F_211 ( V_17 ) ;
if ( V_208 )
return V_208 ;
V_208 = - V_263 ;
V_264:
F_152 ( & V_5 ) ;
F_212 (fmt, &formats, lh) {
if ( ! F_213 ( V_2 -> V_8 ) )
continue;
F_153 ( & V_5 ) ;
V_17 -> V_261 ++ ;
V_208 = V_2 -> V_4 ( V_17 ) ;
F_152 ( & V_5 ) ;
F_10 ( V_2 ) ;
V_17 -> V_261 -- ;
if ( V_208 < 0 && ! V_17 -> V_20 ) {
F_153 ( & V_5 ) ;
F_214 ( V_265 , V_21 ) ;
return V_208 ;
}
if ( V_208 != - V_266 || ! V_17 -> V_125 ) {
F_153 ( & V_5 ) ;
return V_208 ;
}
}
F_153 ( & V_5 ) ;
if ( V_259 ) {
if ( F_215 ( V_17 -> V_154 [ 0 ] ) && F_215 ( V_17 -> V_154 [ 1 ] ) &&
F_215 ( V_17 -> V_154 [ 2 ] ) && F_215 ( V_17 -> V_154 [ 3 ] ) )
return V_208 ;
if ( F_216 ( L_1 , * ( V_267 * ) ( V_17 -> V_154 + 2 ) ) < 0 )
return V_208 ;
V_259 = false ;
goto V_264;
}
return V_208 ;
}
static int F_217 ( struct V_16 * V_17 )
{
T_10 V_268 , V_269 ;
int V_28 ;
V_268 = V_21 -> V_192 ;
F_194 () ;
V_269 = F_218 ( V_21 , F_219 ( V_21 -> V_203 ) ) ;
F_196 () ;
V_28 = F_209 ( V_17 ) ;
if ( V_28 >= 0 ) {
F_220 ( V_17 ) ;
F_221 ( V_21 , V_268 , V_17 ) ;
F_222 ( V_270 , V_269 ) ;
F_223 ( V_21 ) ;
}
return V_28 ;
}
static int F_224 ( int V_126 , struct V_127 * V_127 ,
struct V_64 V_65 ,
struct V_64 V_271 ,
int V_129 )
{
char * V_272 = NULL ;
struct V_16 * V_17 ;
struct V_125 * V_125 ;
struct V_273 * V_274 ;
int V_208 ;
if ( F_50 ( V_127 ) )
return F_101 ( V_127 ) ;
if ( ( V_21 -> V_129 & V_275 ) &&
F_145 ( & F_225 () -> V_276 ) > V_33 ( V_277 ) ) {
V_208 = - V_181 ;
goto V_278;
}
V_21 -> V_129 &= ~ V_275 ;
V_208 = F_226 ( & V_274 ) ;
if ( V_208 )
goto V_278;
V_208 = - V_43 ;
V_17 = F_227 ( sizeof( * V_17 ) , V_42 ) ;
if ( ! V_17 )
goto V_279;
V_208 = F_177 ( V_17 ) ;
if ( V_208 )
goto V_163;
F_192 ( V_17 ) ;
V_21 -> V_280 = 1 ;
V_125 = F_78 ( V_126 , V_127 , V_129 ) ;
V_208 = F_101 ( V_125 ) ;
if ( F_50 ( V_125 ) )
goto V_281;
F_228 () ;
V_17 -> V_125 = V_125 ;
if ( V_126 == V_150 || V_127 -> V_128 [ 0 ] == '/' ) {
V_17 -> V_127 = V_127 -> V_128 ;
} else {
if ( V_127 -> V_128 [ 0 ] == '\0' )
V_272 = F_229 ( V_282 , L_2 , V_126 ) ;
else
V_272 = F_229 ( V_282 , L_3 ,
V_126 , V_127 -> V_128 ) ;
if ( ! V_272 ) {
V_208 = - V_43 ;
goto V_281;
}
if ( F_230 ( V_126 , F_231 ( V_21 -> V_231 -> V_283 ) ) )
V_17 -> V_218 |= V_284 ;
V_17 -> V_127 = V_272 ;
}
V_17 -> V_234 = V_17 -> V_127 ;
V_208 = F_40 ( V_17 ) ;
if ( V_208 )
goto V_281;
V_17 -> V_75 = F_49 ( V_65 , V_285 ) ;
if ( ( V_208 = V_17 -> V_75 ) < 0 )
goto V_80;
V_17 -> V_286 = F_49 ( V_271 , V_285 ) ;
if ( ( V_208 = V_17 -> V_286 ) < 0 )
goto V_80;
V_208 = F_204 ( V_17 ) ;
if ( V_208 < 0 )
goto V_80;
V_208 = F_59 ( 1 , & V_17 -> V_127 , V_17 ) ;
if ( V_208 < 0 )
goto V_80;
V_17 -> V_113 = V_17 -> V_57 ;
V_208 = F_53 ( V_17 -> V_286 , V_271 , V_17 ) ;
if ( V_208 < 0 )
goto V_80;
V_208 = F_53 ( V_17 -> V_75 , V_65 , V_17 ) ;
if ( V_208 < 0 )
goto V_80;
V_208 = F_217 ( V_17 ) ;
if ( V_208 < 0 )
goto V_80;
V_21 -> V_242 -> V_245 = 0 ;
V_21 -> V_280 = 0 ;
F_232 ( V_21 ) ;
F_233 ( V_21 ) ;
F_181 ( V_17 ) ;
F_183 ( V_272 ) ;
F_88 ( V_127 ) ;
if ( V_274 )
F_234 ( V_274 ) ;
return V_208 ;
V_80:
if ( V_17 -> V_20 ) {
F_13 ( V_17 , 0 ) ;
F_118 ( V_17 -> V_20 ) ;
}
V_281:
V_21 -> V_242 -> V_245 = 0 ;
V_21 -> V_280 = 0 ;
V_163:
F_181 ( V_17 ) ;
F_183 ( V_272 ) ;
V_279:
if ( V_274 )
F_235 ( V_274 ) ;
V_278:
F_88 ( V_127 ) ;
return V_208 ;
}
int F_236 ( struct V_127 * V_127 ,
const char T_1 * const T_1 * V_84 ,
const char T_1 * const T_1 * V_287 )
{
struct V_64 V_65 = { . V_70 . V_67 = V_84 } ;
struct V_64 V_271 = { . V_70 . V_67 = V_287 } ;
return F_224 ( V_150 , V_127 , V_65 , V_271 , 0 ) ;
}
int F_237 ( int V_126 , struct V_127 * V_127 ,
const char T_1 * const T_1 * V_84 ,
const char T_1 * const T_1 * V_287 ,
int V_129 )
{
struct V_64 V_65 = { . V_70 . V_67 = V_84 } ;
struct V_64 V_271 = { . V_70 . V_67 = V_287 } ;
return F_224 ( V_126 , V_127 , V_65 , V_271 , V_129 ) ;
}
static int F_238 ( struct V_127 * V_127 ,
const T_2 T_1 * V_84 ,
const T_2 T_1 * V_287 )
{
struct V_64 V_65 = {
. V_68 = true ,
. V_70 . V_69 = V_84 ,
} ;
struct V_64 V_271 = {
. V_68 = true ,
. V_70 . V_69 = V_287 ,
} ;
return F_224 ( V_150 , V_127 , V_65 , V_271 , 0 ) ;
}
static int F_239 ( int V_126 , struct V_127 * V_127 ,
const T_2 T_1 * V_84 ,
const T_2 T_1 * V_287 ,
int V_129 )
{
struct V_64 V_65 = {
. V_68 = true ,
. V_70 . V_69 = V_84 ,
} ;
struct V_64 V_271 = {
. V_68 = true ,
. V_70 . V_69 = V_287 ,
} ;
return F_224 ( V_126 , V_127 , V_65 , V_271 , V_129 ) ;
}
void F_240 ( struct V_1 * V_288 )
{
struct V_19 * V_20 = V_21 -> V_20 ;
if ( V_20 -> V_289 )
F_11 ( V_20 -> V_289 -> V_8 ) ;
V_20 -> V_289 = V_288 ;
if ( V_288 )
F_241 ( V_288 -> V_8 ) ;
}
void F_172 ( struct V_19 * V_20 , int V_290 )
{
unsigned long V_291 , V_288 ;
if ( F_3 ( ( unsigned ) V_290 > V_292 ) )
return;
do {
V_291 = F_19 ( V_20 -> V_129 ) ;
V_288 = ( V_291 & ~ V_293 ) | V_290 ;
} while ( F_242 ( & V_20 -> V_129 , V_291 , V_288 ) != V_291 );
}
