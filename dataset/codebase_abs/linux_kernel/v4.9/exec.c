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
& V_25 , NULL ) ;
if ( V_28 <= 0 )
return NULL ;
if ( V_27 ) {
unsigned long V_33 = V_17 -> V_31 -> V_34 - V_17 -> V_31 -> V_35 ;
struct V_36 * V_37 ;
F_13 ( V_17 , V_33 / V_38 ) ;
if ( V_33 <= V_39 )
return V_25 ;
V_37 = V_21 -> signal -> V_37 ;
if ( V_33 > F_19 ( V_37 [ V_40 ] . V_41 ) / 4 ) {
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
F_24 ( V_17 -> V_31 , V_26 , F_25 ( V_25 ) ) ;
}
static int F_26 ( struct V_16 * V_17 )
{
int V_42 ;
struct V_43 * V_31 = NULL ;
struct V_19 * V_20 = V_17 -> V_20 ;
V_17 -> V_31 = V_31 = F_27 ( V_44 , V_45 ) ;
if ( ! V_31 )
return - V_46 ;
if ( F_28 ( & V_20 -> V_47 ) ) {
V_42 = - V_48 ;
goto V_49;
}
V_31 -> V_50 = V_20 ;
F_29 ( V_51 & V_52 ) ;
V_31 -> V_34 = V_53 ;
V_31 -> V_35 = V_31 -> V_34 - V_38 ;
V_31 -> V_54 = V_55 | V_51 | V_52 ;
V_31 -> V_56 = F_30 ( V_31 -> V_54 ) ;
F_31 ( & V_31 -> V_57 ) ;
V_42 = F_32 ( V_20 , V_31 ) ;
if ( V_42 )
goto V_42;
V_20 -> V_58 = V_20 -> V_59 = 1 ;
F_33 ( V_20 , V_31 ) ;
F_34 ( & V_20 -> V_47 ) ;
V_17 -> V_60 = V_31 -> V_34 - sizeof( void * ) ;
return 0 ;
V_42:
F_34 ( & V_20 -> V_47 ) ;
V_49:
V_17 -> V_31 = NULL ;
F_35 ( V_44 , V_31 ) ;
return V_42 ;
}
static bool F_36 ( struct V_16 * V_17 , long V_61 )
{
return V_61 <= V_62 ;
}
static inline void F_13 ( struct V_16 * V_17 , unsigned long V_18 )
{
}
static struct V_25 * F_15 ( struct V_16 * V_17 , unsigned long V_26 ,
int V_27 )
{
struct V_25 * V_25 ;
V_25 = V_17 -> V_25 [ V_26 / V_38 ] ;
if ( ! V_25 && V_27 ) {
V_25 = F_37 ( V_63 | V_64 ) ;
if ( ! V_25 )
return NULL ;
V_17 -> V_25 [ V_26 / V_38 ] = V_25 ;
}
return V_25 ;
}
static void F_21 ( struct V_25 * V_25 )
{
}
static void F_38 ( struct V_16 * V_17 , int V_65 )
{
if ( V_17 -> V_25 [ V_65 ] ) {
F_39 ( V_17 -> V_25 [ V_65 ] ) ;
V_17 -> V_25 [ V_65 ] = NULL ;
}
}
static void F_22 ( struct V_16 * V_17 )
{
int V_65 ;
for ( V_65 = 0 ; V_65 < V_66 ; V_65 ++ )
F_38 ( V_17 , V_65 ) ;
}
static void F_23 ( struct V_16 * V_17 , unsigned long V_26 ,
struct V_25 * V_25 )
{
}
static int F_26 ( struct V_16 * V_17 )
{
V_17 -> V_60 = V_38 * V_66 - sizeof( void * ) ;
return 0 ;
}
static bool F_36 ( struct V_16 * V_17 , long V_61 )
{
return V_61 <= V_17 -> V_60 ;
}
static int F_40 ( struct V_16 * V_17 )
{
int V_42 ;
struct V_19 * V_20 = NULL ;
V_17 -> V_20 = V_20 = F_41 () ;
V_42 = - V_46 ;
if ( ! V_20 )
goto V_42;
V_42 = F_26 ( V_17 ) ;
if ( V_42 )
goto V_42;
return 0 ;
V_42:
if ( V_20 ) {
V_17 -> V_20 = NULL ;
F_42 ( V_20 ) ;
}
return V_42 ;
}
static const char T_1 * F_43 ( struct V_67 V_68 , int V_69 )
{
const char T_1 * V_70 ;
#ifdef F_44
if ( F_45 ( V_68 . V_71 ) ) {
T_2 V_72 ;
if ( F_46 ( V_72 , V_68 . V_73 . V_72 + V_69 ) )
return F_47 ( - V_74 ) ;
return F_48 ( V_72 ) ;
}
#endif
if ( F_46 ( V_70 , V_68 . V_73 . V_70 + V_69 ) )
return F_47 ( - V_74 ) ;
return V_70 ;
}
static int F_49 ( struct V_67 V_68 , int V_75 )
{
int V_65 = 0 ;
if ( V_68 . V_73 . V_70 != NULL ) {
for (; ; ) {
const char T_1 * V_60 = F_43 ( V_68 , V_65 ) ;
if ( ! V_60 )
break;
if ( F_50 ( V_60 ) )
return - V_74 ;
if ( V_65 >= V_75 )
return - V_76 ;
++ V_65 ;
if ( F_51 ( V_21 ) )
return - V_77 ;
F_52 () ;
}
}
return V_65 ;
}
static int F_53 ( int V_78 , struct V_67 V_68 ,
struct V_16 * V_17 )
{
struct V_25 * V_79 = NULL ;
char * V_80 = NULL ;
unsigned long V_81 = 0 ;
int V_28 ;
while ( V_78 -- > 0 ) {
const char T_1 * V_82 ;
int V_61 ;
unsigned long V_26 ;
V_28 = - V_74 ;
V_82 = F_43 ( V_68 , V_78 ) ;
if ( F_50 ( V_82 ) )
goto V_83;
V_61 = F_54 ( V_82 , V_62 ) ;
if ( ! V_61 )
goto V_83;
V_28 = - V_76 ;
if ( ! F_36 ( V_17 , V_61 ) )
goto V_83;
V_26 = V_17 -> V_60 ;
V_82 += V_61 ;
V_17 -> V_60 -= V_61 ;
while ( V_61 > 0 ) {
int V_84 , V_85 ;
if ( F_51 ( V_21 ) ) {
V_28 = - V_77 ;
goto V_83;
}
F_52 () ;
V_84 = V_26 % V_38 ;
if ( V_84 == 0 )
V_84 = V_38 ;
V_85 = V_84 ;
if ( V_85 > V_61 )
V_85 = V_61 ;
V_84 -= V_85 ;
V_26 -= V_85 ;
V_82 -= V_85 ;
V_61 -= V_85 ;
if ( ! V_79 || V_81 != ( V_26 & V_86 ) ) {
struct V_25 * V_25 ;
V_25 = F_15 ( V_17 , V_26 , 1 ) ;
if ( ! V_25 ) {
V_28 = - V_76 ;
goto V_83;
}
if ( V_79 ) {
F_55 ( V_79 ) ;
F_56 ( V_79 ) ;
F_21 ( V_79 ) ;
}
V_79 = V_25 ;
V_80 = F_57 ( V_79 ) ;
V_81 = V_26 & V_86 ;
F_23 ( V_17 , V_81 , V_79 ) ;
}
if ( F_58 ( V_80 + V_84 , V_82 , V_85 ) ) {
V_28 = - V_74 ;
goto V_83;
}
}
}
V_28 = 0 ;
V_83:
if ( V_79 ) {
F_55 ( V_79 ) ;
F_56 ( V_79 ) ;
F_21 ( V_79 ) ;
}
return V_28 ;
}
int F_59 ( int V_78 , const char * const * V_87 ,
struct V_16 * V_17 )
{
int V_88 ;
T_3 V_89 = F_60 () ;
struct V_67 V_68 = {
. V_73 . V_70 = ( const char T_1 * const T_1 * ) V_87 ,
} ;
F_61 ( V_90 ) ;
V_88 = F_53 ( V_78 , V_68 , V_17 ) ;
F_61 ( V_89 ) ;
return V_88 ;
}
static int F_62 ( struct V_43 * V_31 , unsigned long V_91 )
{
struct V_19 * V_20 = V_31 -> V_50 ;
unsigned long V_92 = V_31 -> V_35 ;
unsigned long V_93 = V_31 -> V_34 ;
unsigned long V_94 = V_93 - V_92 ;
unsigned long V_95 = V_92 - V_91 ;
unsigned long V_96 = V_93 - V_91 ;
struct V_97 V_98 ;
F_2 ( V_95 > V_96 ) ;
if ( V_31 != F_63 ( V_20 , V_95 ) )
return - V_74 ;
if ( F_64 ( V_31 , V_95 , V_93 , V_31 -> V_99 , NULL ) )
return - V_46 ;
if ( V_94 != F_65 ( V_31 , V_92 ,
V_31 , V_95 , V_94 , false ) )
return - V_46 ;
F_66 () ;
F_67 ( & V_98 , V_20 , V_92 , V_93 ) ;
if ( V_96 > V_92 ) {
F_68 ( & V_98 , V_96 , V_93 , V_96 ,
V_31 -> V_100 ? V_31 -> V_100 -> V_35 : V_101 ) ;
} else {
F_68 ( & V_98 , V_92 , V_93 , V_96 ,
V_31 -> V_100 ? V_31 -> V_100 -> V_35 : V_101 ) ;
}
F_69 ( & V_98 , V_92 , V_93 ) ;
F_64 ( V_31 , V_95 , V_96 , V_31 -> V_99 , NULL ) ;
return 0 ;
}
int F_70 ( struct V_16 * V_17 ,
unsigned long V_102 ,
int V_103 )
{
unsigned long V_28 ;
unsigned long V_104 ;
struct V_19 * V_20 = V_21 -> V_20 ;
struct V_43 * V_31 = V_17 -> V_31 ;
struct V_43 * V_105 = NULL ;
unsigned long V_54 ;
unsigned long V_106 ;
unsigned long V_107 ;
unsigned long V_108 ;
unsigned long V_109 ;
#ifdef F_16
V_106 = F_71 ( V_40 ) ;
if ( V_106 > V_110 )
V_106 = V_110 ;
V_106 += ( V_111 << V_112 ) ;
if ( V_31 -> V_34 - V_31 -> V_35 > V_106 )
return - V_46 ;
V_106 = F_72 ( V_102 - V_106 ) ;
V_104 = V_31 -> V_35 - V_106 ;
V_20 -> V_113 = V_17 -> V_60 - V_104 ;
V_17 -> V_60 = V_31 -> V_34 - V_104 ;
#else
V_102 = F_73 ( V_102 ) ;
V_102 = F_72 ( V_102 ) ;
if ( F_45 ( V_102 < V_114 ) ||
F_45 ( V_31 -> V_34 - V_31 -> V_35 >= V_102 - V_114 ) )
return - V_46 ;
V_104 = V_31 -> V_34 - V_102 ;
V_17 -> V_60 -= V_104 ;
V_20 -> V_113 = V_17 -> V_60 ;
#endif
if ( V_17 -> V_115 )
V_17 -> V_115 -= V_104 ;
V_17 -> V_116 -= V_104 ;
if ( F_28 ( & V_20 -> V_47 ) )
return - V_48 ;
V_54 = V_51 ;
if ( F_45 ( V_103 == V_117 ) )
V_54 |= V_118 ;
else if ( V_103 == V_119 )
V_54 &= ~ V_118 ;
V_54 |= V_20 -> V_120 ;
V_54 |= V_52 ;
V_28 = F_74 ( V_31 , & V_105 , V_31 -> V_35 , V_31 -> V_34 ,
V_54 ) ;
if ( V_28 )
goto V_121;
F_2 ( V_105 != V_31 ) ;
if ( V_104 ) {
V_28 = F_62 ( V_31 , V_104 ) ;
if ( V_28 )
goto V_121;
}
V_31 -> V_54 &= ~ V_52 ;
V_108 = 131072UL ;
V_107 = V_31 -> V_34 - V_31 -> V_35 ;
V_109 = V_36 ( V_40 ) & V_86 ;
#ifdef F_16
if ( V_107 + V_108 > V_109 )
V_106 = V_31 -> V_35 + V_109 ;
else
V_106 = V_31 -> V_34 + V_108 ;
#else
if ( V_107 + V_108 > V_109 )
V_106 = V_31 -> V_34 - V_109 ;
else
V_106 = V_31 -> V_35 - V_108 ;
#endif
V_21 -> V_20 -> V_122 = V_17 -> V_60 ;
V_28 = F_75 ( V_31 , V_106 ) ;
if ( V_28 )
V_28 = - V_74 ;
V_121:
F_34 ( & V_20 -> V_47 ) ;
return V_28 ;
}
int F_76 ( struct V_16 * V_17 ,
unsigned long * V_123 )
{
unsigned long V_124 , V_125 , V_126 ;
int V_28 = 0 ;
V_125 = V_17 -> V_60 >> V_112 ;
V_126 = * V_123 ;
for ( V_124 = V_66 - 1 ; V_124 >= V_125 ; V_124 -- ) {
unsigned int V_84 = V_124 == V_125 ? V_17 -> V_60 & ~ V_86 : 0 ;
char * V_127 = F_57 ( V_17 -> V_25 [ V_124 ] ) + V_84 ;
V_126 -= V_38 - V_84 ;
if ( F_77 ( ( void * ) V_126 , V_127 , V_38 - V_84 ) != 0 )
V_28 = - V_74 ;
F_56 ( V_17 -> V_25 [ V_124 ] ) ;
if ( V_28 )
goto V_83;
}
* V_123 = V_126 ;
V_83:
return V_28 ;
}
static struct V_128 * F_78 ( int V_129 , struct V_130 * V_131 , int V_132 )
{
struct V_128 * V_128 ;
int V_42 ;
struct V_133 V_134 = {
. V_135 = V_136 | V_137 | V_138 ,
. V_139 = V_140 ,
. V_141 = V_142 ,
. V_143 = V_144 ,
} ;
if ( ( V_132 & ~ ( V_145 | V_146 ) ) != 0 )
return F_47 ( - V_147 ) ;
if ( V_132 & V_145 )
V_134 . V_143 &= ~ V_144 ;
if ( V_132 & V_146 )
V_134 . V_143 |= V_148 ;
V_128 = F_79 ( V_129 , V_131 , & V_134 ) ;
if ( F_50 ( V_128 ) )
goto V_83;
V_42 = - V_149 ;
if ( ! F_80 ( F_81 ( V_128 ) -> V_150 ) )
goto exit;
if ( F_12 ( & V_128 -> V_151 ) )
goto exit;
V_42 = F_82 ( V_128 ) ;
if ( V_42 )
goto exit;
if ( V_131 -> V_131 [ 0 ] != '\0' )
F_83 ( V_128 ) ;
V_83:
return V_128 ;
exit:
F_84 ( V_128 ) ;
return F_47 ( V_42 ) ;
}
struct V_128 * F_85 ( const char * V_131 )
{
struct V_130 * V_130 = F_86 ( V_131 ) ;
struct V_128 * V_152 = F_87 ( V_130 ) ;
if ( ! F_50 ( V_130 ) ) {
V_152 = F_78 ( V_153 , V_130 , 0 ) ;
F_88 ( V_130 ) ;
}
return V_152 ;
}
int F_89 ( struct V_128 * V_128 , T_4 V_84 ,
char * V_154 , unsigned long F_49 )
{
T_3 V_155 ;
T_4 V_26 = V_84 ;
int V_156 ;
V_155 = F_60 () ;
F_61 ( F_90 () ) ;
V_156 = F_91 ( V_128 , ( void T_1 * ) V_154 , F_49 , & V_26 ) ;
F_61 ( V_155 ) ;
return V_156 ;
}
int F_92 ( struct V_128 * V_128 , void * * V_157 , T_4 * V_33 ,
T_4 V_158 , enum V_159 V_160 )
{
T_4 V_161 , V_26 ;
T_5 V_162 = 0 ;
int V_28 ;
if ( ! F_80 ( F_81 ( V_128 ) -> V_150 ) || V_158 < 0 )
return - V_147 ;
V_28 = F_93 ( V_128 , V_160 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_82 ( V_128 ) ;
if ( V_28 )
return V_28 ;
V_161 = F_94 ( F_81 ( V_128 ) ) ;
if ( V_158 > 0 && V_161 > V_158 ) {
V_28 = - V_163 ;
goto V_83;
}
if ( V_161 <= 0 ) {
V_28 = - V_147 ;
goto V_83;
}
if ( V_160 != V_164 )
* V_157 = F_95 ( V_161 ) ;
if ( ! * V_157 ) {
V_28 = - V_46 ;
goto V_83;
}
V_26 = 0 ;
while ( V_26 < V_161 ) {
V_162 = F_89 ( V_128 , V_26 , ( char * ) ( * V_157 ) + V_26 ,
V_161 - V_26 ) ;
if ( V_162 < 0 ) {
V_28 = V_162 ;
goto V_83;
}
if ( V_162 == 0 )
break;
V_26 += V_162 ;
}
if ( V_26 != V_161 ) {
V_28 = - V_165 ;
goto V_166;
}
V_28 = F_96 ( V_128 , * V_157 , V_161 , V_160 ) ;
if ( ! V_28 )
* V_33 = V_26 ;
V_166:
if ( V_28 < 0 ) {
if ( V_160 != V_164 ) {
F_97 ( * V_157 ) ;
* V_157 = NULL ;
}
}
V_83:
F_98 ( V_128 ) ;
return V_28 ;
}
int F_99 ( char * V_9 , void * * V_157 , T_4 * V_33 ,
T_4 V_158 , enum V_159 V_160 )
{
struct V_128 * V_128 ;
int V_28 ;
if ( ! V_9 || ! * V_9 )
return - V_147 ;
V_128 = F_100 ( V_9 , V_137 , 0 ) ;
if ( F_50 ( V_128 ) )
return F_101 ( V_128 ) ;
V_28 = F_92 ( V_128 , V_157 , V_33 , V_158 , V_160 ) ;
F_84 ( V_128 ) ;
return V_28 ;
}
int F_102 ( int V_129 , void * * V_157 , T_4 * V_33 , T_4 V_158 ,
enum V_159 V_160 )
{
struct V_129 V_152 = F_103 ( V_129 ) ;
int V_28 = - V_167 ;
if ( ! V_152 . V_128 )
goto V_83;
V_28 = F_92 ( V_152 . V_128 , V_157 , V_33 , V_158 , V_160 ) ;
V_83:
F_104 ( V_152 ) ;
return V_28 ;
}
T_5 F_105 ( struct V_128 * V_128 , unsigned long V_154 , T_4 V_26 , T_6 V_61 )
{
T_5 V_168 = F_91 ( V_128 , ( void T_1 * ) V_154 , V_61 , & V_26 ) ;
if ( V_168 > 0 )
F_106 ( V_154 , V_154 + V_61 ) ;
return V_168 ;
}
static int F_107 ( struct V_19 * V_20 )
{
struct V_169 * V_170 ;
struct V_19 * V_171 , * V_172 ;
V_170 = V_21 ;
V_171 = V_21 -> V_20 ;
F_108 ( V_170 , V_171 ) ;
if ( V_171 ) {
F_109 ( V_171 ) ;
F_110 ( & V_171 -> V_47 ) ;
if ( F_45 ( V_171 -> V_173 ) ) {
F_111 ( & V_171 -> V_47 ) ;
return - V_48 ;
}
}
F_112 ( V_170 ) ;
V_172 = V_170 -> V_172 ;
V_170 -> V_20 = V_20 ;
V_170 -> V_172 = V_20 ;
F_113 ( V_172 , V_20 ) ;
V_170 -> V_20 -> V_174 = 0 ;
F_114 ( V_170 ) ;
F_115 ( V_170 ) ;
if ( V_171 ) {
F_111 ( & V_171 -> V_47 ) ;
F_2 ( V_172 != V_171 ) ;
F_116 ( & V_170 -> signal -> V_175 , V_171 ) ;
F_117 ( V_171 ) ;
F_118 ( V_171 ) ;
return 0 ;
}
F_42 ( V_172 ) ;
return 0 ;
}
static int F_119 ( struct V_169 * V_170 )
{
struct V_176 * V_177 = V_170 -> signal ;
struct V_178 * V_179 = V_170 -> V_180 ;
T_7 * V_181 = & V_179 -> V_182 ;
if ( F_120 ( V_170 ) )
goto V_183;
F_121 ( V_181 ) ;
if ( F_122 ( V_177 ) ) {
F_123 ( V_181 ) ;
return - V_184 ;
}
V_177 -> V_185 = V_170 ;
V_177 -> V_186 = F_124 ( V_170 ) ;
if ( ! F_125 ( V_170 ) )
V_177 -> V_186 -- ;
while ( V_177 -> V_186 ) {
F_126 ( V_187 ) ;
F_123 ( V_181 ) ;
F_127 () ;
if ( F_45 ( F_128 ( V_170 ) ) )
goto V_188;
F_121 ( V_181 ) ;
}
F_123 ( V_181 ) ;
if ( ! F_125 ( V_170 ) ) {
struct V_169 * V_189 = V_170 -> V_190 ;
for (; ; ) {
F_129 ( V_170 ) ;
F_130 ( & V_191 ) ;
V_177 -> V_186 = - 1 ;
if ( F_131 ( V_189 -> V_192 ) )
break;
F_126 ( V_187 ) ;
F_132 ( & V_191 ) ;
F_133 ( V_170 ) ;
F_127 () ;
if ( F_45 ( F_128 ( V_170 ) ) )
goto V_188;
}
V_170 -> V_193 = V_189 -> V_193 ;
V_170 -> V_194 = V_189 -> V_194 ;
F_2 ( ! F_134 ( V_189 , V_170 ) ) ;
F_2 ( F_135 ( V_170 ) ) ;
V_170 -> V_195 = V_189 -> V_195 ;
F_136 ( V_170 , V_196 , F_137 ( V_189 ) ) ;
F_138 ( V_189 , V_170 , V_197 ) ;
F_138 ( V_189 , V_170 , V_198 ) ;
F_139 ( & V_189 -> V_199 , & V_170 -> V_199 ) ;
F_140 ( & V_189 -> V_200 , & V_170 -> V_200 ) ;
V_170 -> V_190 = V_170 ;
V_189 -> V_190 = V_170 ;
V_170 -> V_201 = V_202 ;
V_189 -> V_201 = - 1 ;
F_2 ( V_189 -> V_192 != V_203 ) ;
V_189 -> V_192 = V_204 ;
if ( F_45 ( V_189 -> V_205 ) )
F_141 ( V_189 , V_189 -> V_206 ) ;
F_132 ( & V_191 ) ;
F_133 ( V_170 ) ;
F_142 ( V_189 ) ;
}
V_177 -> V_185 = NULL ;
V_177 -> V_186 = 0 ;
V_183:
V_170 -> V_201 = V_202 ;
F_143 ( V_177 ) ;
F_144 () ;
if ( F_145 ( & V_179 -> F_49 ) != 1 ) {
struct V_178 * V_207 ;
V_207 = F_146 ( V_208 , V_45 ) ;
if ( ! V_207 )
return - V_46 ;
F_147 ( & V_207 -> F_49 , 1 ) ;
memcpy ( V_207 -> V_209 , V_179 -> V_209 ,
sizeof( V_207 -> V_209 ) ) ;
F_130 ( & V_191 ) ;
F_148 ( & V_179 -> V_182 ) ;
F_149 ( V_170 -> V_180 , V_207 ) ;
F_150 ( & V_179 -> V_182 ) ;
F_132 ( & V_191 ) ;
F_151 ( V_179 ) ;
}
F_2 ( ! F_125 ( V_170 ) ) ;
return 0 ;
V_188:
F_152 ( & V_191 ) ;
V_177 -> V_185 = NULL ;
V_177 -> V_186 = 0 ;
F_153 ( & V_191 ) ;
return - V_184 ;
}
char * F_154 ( char * V_157 , struct V_169 * V_170 )
{
F_112 ( V_170 ) ;
strncpy ( V_157 , V_170 -> V_210 , sizeof( V_170 -> V_210 ) ) ;
F_115 ( V_170 ) ;
return V_157 ;
}
void F_155 ( struct V_169 * V_170 , const char * V_157 , bool V_116 )
{
F_112 ( V_170 ) ;
F_156 ( V_170 , V_157 ) ;
F_157 ( V_170 -> V_210 , V_157 , sizeof( V_170 -> V_210 ) ) ;
F_115 ( V_170 ) ;
F_158 ( V_170 , V_116 ) ;
}
int F_159 ( struct V_16 * V_17 )
{
int V_211 ;
V_211 = F_119 ( V_21 ) ;
if ( V_211 )
goto V_83;
F_160 ( V_17 -> V_20 , V_17 -> V_128 ) ;
F_13 ( V_17 , 0 ) ;
V_211 = F_107 ( V_17 -> V_20 ) ;
if ( V_211 )
goto V_83;
V_17 -> V_20 = NULL ;
F_61 ( V_212 ) ;
V_21 -> V_132 &= ~ ( V_213 | V_214 | V_215 |
V_216 | V_217 ) ;
F_161 () ;
V_21 -> V_218 &= ~ V_17 -> V_219 ;
return 0 ;
V_83:
return V_211 ;
}
void F_162 ( struct V_16 * V_17 , struct V_128 * V_128 )
{
if ( F_163 ( F_81 ( V_128 ) , V_220 ) < 0 )
V_17 -> V_221 |= V_222 ;
}
void F_164 ( struct V_16 * V_17 )
{
F_165 ( V_21 -> V_20 ) ;
V_21 -> V_223 = V_21 -> V_224 = 0 ;
if ( F_166 ( F_167 () , F_168 () ) && F_169 ( F_170 () , F_171 () ) )
F_172 ( V_21 -> V_20 , V_225 ) ;
else
F_172 ( V_21 -> V_20 , V_226 ) ;
F_173 () ;
F_155 ( V_21 , F_174 ( V_17 -> V_130 ) , true ) ;
V_21 -> V_20 -> V_227 = V_228 ;
if ( ! F_166 ( V_17 -> V_229 -> V_230 , F_167 () ) ||
! F_169 ( V_17 -> V_229 -> V_231 , F_170 () ) ) {
V_21 -> V_232 = 0 ;
} else {
F_162 ( V_17 , V_17 -> V_128 ) ;
if ( V_17 -> V_221 & V_222 )
F_172 ( V_21 -> V_20 , V_226 ) ;
}
V_21 -> V_233 ++ ;
F_175 ( V_21 , 0 ) ;
F_176 ( V_21 -> V_234 ) ;
}
int F_177 ( struct V_16 * V_17 )
{
if ( F_178 ( & V_21 -> signal -> V_235 ) )
return - V_236 ;
V_17 -> V_229 = F_179 () ;
if ( F_131 ( V_17 -> V_229 ) )
return 0 ;
F_180 ( & V_21 -> signal -> V_235 ) ;
return - V_46 ;
}
static void F_181 ( struct V_16 * V_17 )
{
F_22 ( V_17 ) ;
if ( V_17 -> V_229 ) {
F_180 ( & V_21 -> signal -> V_235 ) ;
F_182 ( V_17 -> V_229 ) ;
}
if ( V_17 -> V_128 ) {
F_98 ( V_17 -> V_128 ) ;
F_84 ( V_17 -> V_128 ) ;
}
if ( V_17 -> V_237 != V_17 -> V_130 )
F_183 ( V_17 -> V_237 ) ;
F_183 ( V_17 ) ;
}
int F_184 ( char * V_237 , struct V_16 * V_17 )
{
if ( V_17 -> V_237 != V_17 -> V_130 )
F_183 ( V_17 -> V_237 ) ;
V_17 -> V_237 = F_185 ( V_237 , V_45 ) ;
if ( ! V_17 -> V_237 )
return - V_46 ;
return 0 ;
}
void F_186 ( struct V_16 * V_17 )
{
F_187 ( V_17 ) ;
F_188 ( V_17 -> V_229 ) ;
V_17 -> V_229 = NULL ;
if ( F_189 ( V_21 -> V_20 ) != V_225 )
F_190 ( V_21 ) ;
F_191 ( V_17 ) ;
F_180 ( & V_21 -> signal -> V_235 ) ;
}
static void F_192 ( struct V_16 * V_17 )
{
struct V_169 * V_60 = V_21 , * V_238 ;
unsigned V_239 ;
if ( V_60 -> V_205 ) {
if ( V_60 -> V_205 & V_240 )
V_17 -> V_241 |= V_242 ;
else
V_17 -> V_241 |= V_243 ;
}
if ( F_193 ( V_21 ) )
V_17 -> V_241 |= V_244 ;
V_238 = V_60 ;
V_239 = 1 ;
F_148 ( & V_60 -> V_245 -> V_181 ) ;
F_194 () ;
F_195 (p, t) {
if ( V_238 -> V_245 == V_60 -> V_245 )
V_239 ++ ;
}
F_196 () ;
if ( V_60 -> V_245 -> V_246 > V_239 )
V_17 -> V_241 |= V_247 ;
else
V_60 -> V_245 -> V_248 = 1 ;
F_150 ( & V_60 -> V_245 -> V_181 ) ;
}
static void F_197 ( struct V_16 * V_17 )
{
struct V_249 * V_249 ;
unsigned int V_250 ;
T_8 V_230 ;
T_9 V_231 ;
V_17 -> V_229 -> V_251 = F_167 () ;
V_17 -> V_229 -> V_252 = F_170 () ;
if ( ! F_198 ( V_17 -> V_128 -> V_151 . V_10 ) )
return;
if ( F_193 ( V_21 ) )
return;
V_249 = F_81 ( V_17 -> V_128 ) ;
V_250 = F_199 ( V_249 -> V_150 ) ;
if ( ! ( V_250 & ( V_253 | V_254 ) ) )
return;
F_200 ( V_249 ) ;
V_250 = V_249 -> V_150 ;
V_230 = V_249 -> V_255 ;
V_231 = V_249 -> V_256 ;
F_201 ( V_249 ) ;
if ( ! F_202 ( V_17 -> V_229 -> V_257 , V_230 ) ||
! F_203 ( V_17 -> V_229 -> V_257 , V_231 ) )
return;
if ( V_250 & V_253 ) {
V_17 -> V_219 |= V_258 ;
V_17 -> V_229 -> V_251 = V_230 ;
}
if ( ( V_250 & ( V_254 | V_259 ) ) == ( V_254 | V_259 ) ) {
V_17 -> V_219 |= V_258 ;
V_17 -> V_229 -> V_252 = V_231 ;
}
}
int F_204 ( struct V_16 * V_17 )
{
int V_211 ;
F_197 ( V_17 ) ;
V_211 = F_205 ( V_17 ) ;
if ( V_211 )
return V_211 ;
V_17 -> V_260 = 1 ;
memset ( V_17 -> V_157 , 0 , V_261 ) ;
return F_89 ( V_17 -> V_128 , 0 , V_17 -> V_157 , V_261 ) ;
}
int F_206 ( struct V_16 * V_17 )
{
int V_28 = 0 ;
unsigned long V_84 ;
char * V_80 ;
struct V_25 * V_25 ;
if ( ! V_17 -> V_78 )
return 0 ;
do {
V_84 = V_17 -> V_60 & ~ V_86 ;
V_25 = F_15 ( V_17 , V_17 -> V_60 , 0 ) ;
if ( ! V_25 ) {
V_28 = - V_74 ;
goto V_83;
}
V_80 = F_207 ( V_25 ) ;
for (; V_84 < V_38 && V_80 [ V_84 ] ;
V_84 ++ , V_17 -> V_60 ++ )
;
F_208 ( V_80 ) ;
F_21 ( V_25 ) ;
} while ( V_84 == V_38 );
V_17 -> V_60 ++ ;
V_17 -> V_78 -- ;
V_28 = 0 ;
V_83:
return V_28 ;
}
int F_209 ( struct V_16 * V_17 )
{
bool V_262 = F_210 ( V_263 ) ;
struct V_1 * V_2 ;
int V_211 ;
if ( V_17 -> V_264 > 5 )
return - V_265 ;
V_211 = F_211 ( V_17 ) ;
if ( V_211 )
return V_211 ;
V_211 = - V_266 ;
V_267:
F_152 ( & V_5 ) ;
F_212 (fmt, &formats, lh) {
if ( ! F_213 ( V_2 -> V_8 ) )
continue;
F_153 ( & V_5 ) ;
V_17 -> V_264 ++ ;
V_211 = V_2 -> V_4 ( V_17 ) ;
F_152 ( & V_5 ) ;
F_10 ( V_2 ) ;
V_17 -> V_264 -- ;
if ( V_211 < 0 && ! V_17 -> V_20 ) {
F_153 ( & V_5 ) ;
F_214 ( V_268 , V_21 ) ;
return V_211 ;
}
if ( V_211 != - V_269 || ! V_17 -> V_128 ) {
F_153 ( & V_5 ) ;
return V_211 ;
}
}
F_153 ( & V_5 ) ;
if ( V_262 ) {
if ( F_215 ( V_17 -> V_157 [ 0 ] ) && F_215 ( V_17 -> V_157 [ 1 ] ) &&
F_215 ( V_17 -> V_157 [ 2 ] ) && F_215 ( V_17 -> V_157 [ 3 ] ) )
return V_211 ;
if ( F_216 ( L_1 , * ( V_270 * ) ( V_17 -> V_157 + 2 ) ) < 0 )
return V_211 ;
V_262 = false ;
goto V_267;
}
return V_211 ;
}
static int F_217 ( struct V_16 * V_17 )
{
T_10 V_271 , V_272 ;
int V_28 ;
V_271 = V_21 -> V_195 ;
F_194 () ;
V_272 = F_218 ( V_21 , F_219 ( V_21 -> V_206 ) ) ;
F_196 () ;
V_28 = F_209 ( V_17 ) ;
if ( V_28 >= 0 ) {
F_220 ( V_17 ) ;
F_221 ( V_21 , V_271 , V_17 ) ;
F_222 ( V_273 , V_272 ) ;
F_223 ( V_21 ) ;
}
return V_28 ;
}
static int F_224 ( int V_129 , struct V_130 * V_130 ,
struct V_67 V_68 ,
struct V_67 V_274 ,
int V_132 )
{
char * V_275 = NULL ;
struct V_16 * V_17 ;
struct V_128 * V_128 ;
struct V_276 * V_277 ;
int V_211 ;
if ( F_50 ( V_130 ) )
return F_101 ( V_130 ) ;
if ( ( V_21 -> V_132 & V_278 ) &&
F_145 ( & F_225 () -> V_279 ) > V_36 ( V_280 ) ) {
V_211 = - V_184 ;
goto V_281;
}
V_21 -> V_132 &= ~ V_278 ;
V_211 = F_226 ( & V_277 ) ;
if ( V_211 )
goto V_281;
V_211 = - V_46 ;
V_17 = F_227 ( sizeof( * V_17 ) , V_45 ) ;
if ( ! V_17 )
goto V_282;
V_211 = F_177 ( V_17 ) ;
if ( V_211 )
goto V_166;
F_192 ( V_17 ) ;
V_21 -> V_283 = 1 ;
V_128 = F_78 ( V_129 , V_130 , V_132 ) ;
V_211 = F_101 ( V_128 ) ;
if ( F_50 ( V_128 ) )
goto V_284;
F_228 () ;
V_17 -> V_128 = V_128 ;
if ( V_129 == V_153 || V_130 -> V_131 [ 0 ] == '/' ) {
V_17 -> V_130 = V_130 -> V_131 ;
} else {
if ( V_130 -> V_131 [ 0 ] == '\0' )
V_275 = F_229 ( V_285 , L_2 , V_129 ) ;
else
V_275 = F_229 ( V_285 , L_3 ,
V_129 , V_130 -> V_131 ) ;
if ( ! V_275 ) {
V_211 = - V_46 ;
goto V_284;
}
if ( F_230 ( V_129 , F_231 ( V_21 -> V_234 -> V_286 ) ) )
V_17 -> V_221 |= V_287 ;
V_17 -> V_130 = V_275 ;
}
V_17 -> V_237 = V_17 -> V_130 ;
V_211 = F_40 ( V_17 ) ;
if ( V_211 )
goto V_284;
V_17 -> V_78 = F_49 ( V_68 , V_288 ) ;
if ( ( V_211 = V_17 -> V_78 ) < 0 )
goto V_83;
V_17 -> V_289 = F_49 ( V_274 , V_288 ) ;
if ( ( V_211 = V_17 -> V_289 ) < 0 )
goto V_83;
V_211 = F_204 ( V_17 ) ;
if ( V_211 < 0 )
goto V_83;
V_211 = F_59 ( 1 , & V_17 -> V_130 , V_17 ) ;
if ( V_211 < 0 )
goto V_83;
V_17 -> V_116 = V_17 -> V_60 ;
V_211 = F_53 ( V_17 -> V_289 , V_274 , V_17 ) ;
if ( V_211 < 0 )
goto V_83;
V_211 = F_53 ( V_17 -> V_78 , V_68 , V_17 ) ;
if ( V_211 < 0 )
goto V_83;
V_211 = F_217 ( V_17 ) ;
if ( V_211 < 0 )
goto V_83;
V_21 -> V_245 -> V_248 = 0 ;
V_21 -> V_283 = 0 ;
F_232 ( V_21 ) ;
F_233 ( V_21 ) ;
F_181 ( V_17 ) ;
F_183 ( V_275 ) ;
F_88 ( V_130 ) ;
if ( V_277 )
F_234 ( V_277 ) ;
return V_211 ;
V_83:
if ( V_17 -> V_20 ) {
F_13 ( V_17 , 0 ) ;
F_118 ( V_17 -> V_20 ) ;
}
V_284:
V_21 -> V_245 -> V_248 = 0 ;
V_21 -> V_283 = 0 ;
V_166:
F_181 ( V_17 ) ;
F_183 ( V_275 ) ;
V_282:
if ( V_277 )
F_235 ( V_277 ) ;
V_281:
F_88 ( V_130 ) ;
return V_211 ;
}
int F_236 ( struct V_130 * V_130 ,
const char T_1 * const T_1 * V_87 ,
const char T_1 * const T_1 * V_290 )
{
struct V_67 V_68 = { . V_73 . V_70 = V_87 } ;
struct V_67 V_274 = { . V_73 . V_70 = V_290 } ;
return F_224 ( V_153 , V_130 , V_68 , V_274 , 0 ) ;
}
int F_237 ( int V_129 , struct V_130 * V_130 ,
const char T_1 * const T_1 * V_87 ,
const char T_1 * const T_1 * V_290 ,
int V_132 )
{
struct V_67 V_68 = { . V_73 . V_70 = V_87 } ;
struct V_67 V_274 = { . V_73 . V_70 = V_290 } ;
return F_224 ( V_129 , V_130 , V_68 , V_274 , V_132 ) ;
}
static int F_238 ( struct V_130 * V_130 ,
const T_2 T_1 * V_87 ,
const T_2 T_1 * V_290 )
{
struct V_67 V_68 = {
. V_71 = true ,
. V_73 . V_72 = V_87 ,
} ;
struct V_67 V_274 = {
. V_71 = true ,
. V_73 . V_72 = V_290 ,
} ;
return F_224 ( V_153 , V_130 , V_68 , V_274 , 0 ) ;
}
static int F_239 ( int V_129 , struct V_130 * V_130 ,
const T_2 T_1 * V_87 ,
const T_2 T_1 * V_290 ,
int V_132 )
{
struct V_67 V_68 = {
. V_71 = true ,
. V_73 . V_72 = V_87 ,
} ;
struct V_67 V_274 = {
. V_71 = true ,
. V_73 . V_72 = V_290 ,
} ;
return F_224 ( V_129 , V_130 , V_68 , V_274 , V_132 ) ;
}
void F_240 ( struct V_1 * V_291 )
{
struct V_19 * V_20 = V_21 -> V_20 ;
if ( V_20 -> V_292 )
F_11 ( V_20 -> V_292 -> V_8 ) ;
V_20 -> V_292 = V_291 ;
if ( V_291 )
F_241 ( V_291 -> V_8 ) ;
}
void F_172 ( struct V_19 * V_20 , int V_293 )
{
unsigned long V_294 , V_291 ;
if ( F_3 ( ( unsigned ) V_293 > V_295 ) )
return;
do {
V_294 = F_19 ( V_20 -> V_132 ) ;
V_291 = ( V_294 & ~ V_296 ) | V_293 ;
} while ( F_242 ( & V_20 -> V_132 , V_294 , V_291 ) != V_294 );
}
