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
unsigned long V_36 ;
struct V_37 * V_38 ;
V_36 = ( V_17 -> V_39 + V_17 -> V_40 ) * sizeof( void * ) ;
if ( V_36 > V_41 - V_33 )
goto V_42;
V_33 += V_36 ;
F_13 ( V_17 , V_33 / V_43 ) ;
if ( V_33 <= V_44 )
return V_25 ;
V_38 = V_21 -> signal -> V_38 ;
if ( V_33 > F_19 ( V_38 [ V_45 ] . V_46 ) / 4 )
goto V_42;
}
return V_25 ;
V_42:
F_20 ( V_25 ) ;
return NULL ;
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
int V_47 ;
struct V_48 * V_31 = NULL ;
struct V_19 * V_20 = V_17 -> V_20 ;
V_17 -> V_31 = V_31 = F_27 ( V_49 , V_50 ) ;
if ( ! V_31 )
return - V_51 ;
if ( F_28 ( & V_20 -> V_52 ) ) {
V_47 = - V_53 ;
goto V_54;
}
V_31 -> V_55 = V_20 ;
F_29 ( V_56 & V_57 ) ;
V_31 -> V_34 = V_58 ;
V_31 -> V_35 = V_31 -> V_34 - V_43 ;
V_31 -> V_59 = V_60 | V_56 | V_57 ;
V_31 -> V_61 = F_30 ( V_31 -> V_59 ) ;
F_31 ( & V_31 -> V_62 ) ;
V_47 = F_32 ( V_20 , V_31 ) ;
if ( V_47 )
goto V_47;
V_20 -> V_63 = V_20 -> V_64 = 1 ;
F_33 ( V_20 , V_31 ) ;
F_34 ( & V_20 -> V_52 ) ;
V_17 -> V_65 = V_31 -> V_34 - sizeof( void * ) ;
return 0 ;
V_47:
F_34 ( & V_20 -> V_52 ) ;
V_54:
V_17 -> V_31 = NULL ;
F_35 ( V_49 , V_31 ) ;
return V_47 ;
}
static bool F_36 ( struct V_16 * V_17 , long V_66 )
{
return V_66 <= V_67 ;
}
static inline void F_13 ( struct V_16 * V_17 , unsigned long V_18 )
{
}
static struct V_25 * F_15 ( struct V_16 * V_17 , unsigned long V_26 ,
int V_27 )
{
struct V_25 * V_25 ;
V_25 = V_17 -> V_25 [ V_26 / V_43 ] ;
if ( ! V_25 && V_27 ) {
V_25 = F_37 ( V_68 | V_69 ) ;
if ( ! V_25 )
return NULL ;
V_17 -> V_25 [ V_26 / V_43 ] = V_25 ;
}
return V_25 ;
}
static void F_21 ( struct V_25 * V_25 )
{
}
static void F_38 ( struct V_16 * V_17 , int V_70 )
{
if ( V_17 -> V_25 [ V_70 ] ) {
F_39 ( V_17 -> V_25 [ V_70 ] ) ;
V_17 -> V_25 [ V_70 ] = NULL ;
}
}
static void F_22 ( struct V_16 * V_17 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ )
F_38 ( V_17 , V_70 ) ;
}
static void F_23 ( struct V_16 * V_17 , unsigned long V_26 ,
struct V_25 * V_25 )
{
}
static int F_26 ( struct V_16 * V_17 )
{
V_17 -> V_65 = V_43 * V_71 - sizeof( void * ) ;
return 0 ;
}
static bool F_36 ( struct V_16 * V_17 , long V_66 )
{
return V_66 <= V_17 -> V_65 ;
}
static int F_40 ( struct V_16 * V_17 )
{
int V_47 ;
struct V_19 * V_20 = NULL ;
V_17 -> V_20 = V_20 = F_41 () ;
V_47 = - V_51 ;
if ( ! V_20 )
goto V_47;
V_47 = F_26 ( V_17 ) ;
if ( V_47 )
goto V_47;
return 0 ;
V_47:
if ( V_20 ) {
V_17 -> V_20 = NULL ;
F_42 ( V_20 ) ;
}
return V_47 ;
}
static const char T_1 * F_43 ( struct V_72 V_73 , int V_74 )
{
const char T_1 * V_75 ;
#ifdef F_44
if ( F_45 ( V_73 . V_76 ) ) {
T_2 V_77 ;
if ( F_46 ( V_77 , V_73 . V_78 . V_77 + V_74 ) )
return F_47 ( - V_79 ) ;
return F_48 ( V_77 ) ;
}
#endif
if ( F_46 ( V_75 , V_73 . V_78 . V_75 + V_74 ) )
return F_47 ( - V_79 ) ;
return V_75 ;
}
static int F_49 ( struct V_72 V_73 , int V_80 )
{
int V_70 = 0 ;
if ( V_73 . V_78 . V_75 != NULL ) {
for (; ; ) {
const char T_1 * V_65 = F_43 ( V_73 , V_70 ) ;
if ( ! V_65 )
break;
if ( F_50 ( V_65 ) )
return - V_79 ;
if ( V_70 >= V_80 )
return - V_81 ;
++ V_70 ;
if ( F_51 ( V_21 ) )
return - V_82 ;
F_52 () ;
}
}
return V_70 ;
}
static int F_53 ( int V_39 , struct V_72 V_73 ,
struct V_16 * V_17 )
{
struct V_25 * V_83 = NULL ;
char * V_84 = NULL ;
unsigned long V_85 = 0 ;
int V_28 ;
while ( V_39 -- > 0 ) {
const char T_1 * V_86 ;
int V_66 ;
unsigned long V_26 ;
V_28 = - V_79 ;
V_86 = F_43 ( V_73 , V_39 ) ;
if ( F_50 ( V_86 ) )
goto V_87;
V_66 = F_54 ( V_86 , V_67 ) ;
if ( ! V_66 )
goto V_87;
V_28 = - V_81 ;
if ( ! F_36 ( V_17 , V_66 ) )
goto V_87;
V_26 = V_17 -> V_65 ;
V_86 += V_66 ;
V_17 -> V_65 -= V_66 ;
while ( V_66 > 0 ) {
int V_88 , V_89 ;
if ( F_51 ( V_21 ) ) {
V_28 = - V_82 ;
goto V_87;
}
F_52 () ;
V_88 = V_26 % V_43 ;
if ( V_88 == 0 )
V_88 = V_43 ;
V_89 = V_88 ;
if ( V_89 > V_66 )
V_89 = V_66 ;
V_88 -= V_89 ;
V_26 -= V_89 ;
V_86 -= V_89 ;
V_66 -= V_89 ;
if ( ! V_83 || V_85 != ( V_26 & V_90 ) ) {
struct V_25 * V_25 ;
V_25 = F_15 ( V_17 , V_26 , 1 ) ;
if ( ! V_25 ) {
V_28 = - V_81 ;
goto V_87;
}
if ( V_83 ) {
F_55 ( V_83 ) ;
F_56 ( V_83 ) ;
F_21 ( V_83 ) ;
}
V_83 = V_25 ;
V_84 = F_57 ( V_83 ) ;
V_85 = V_26 & V_90 ;
F_23 ( V_17 , V_85 , V_83 ) ;
}
if ( F_58 ( V_84 + V_88 , V_86 , V_89 ) ) {
V_28 = - V_79 ;
goto V_87;
}
}
}
V_28 = 0 ;
V_87:
if ( V_83 ) {
F_55 ( V_83 ) ;
F_56 ( V_83 ) ;
F_21 ( V_83 ) ;
}
return V_28 ;
}
int F_59 ( int V_39 , const char * const * V_91 ,
struct V_16 * V_17 )
{
int V_92 ;
T_3 V_93 = F_60 () ;
struct V_72 V_73 = {
. V_78 . V_75 = ( const char T_1 * const T_1 * ) V_91 ,
} ;
F_61 ( V_94 ) ;
V_92 = F_53 ( V_39 , V_73 , V_17 ) ;
F_61 ( V_93 ) ;
return V_92 ;
}
static int F_62 ( struct V_48 * V_31 , unsigned long V_95 )
{
struct V_19 * V_20 = V_31 -> V_55 ;
unsigned long V_96 = V_31 -> V_35 ;
unsigned long V_97 = V_31 -> V_34 ;
unsigned long V_98 = V_97 - V_96 ;
unsigned long V_99 = V_96 - V_95 ;
unsigned long V_100 = V_97 - V_95 ;
struct V_101 V_102 ;
F_2 ( V_99 > V_100 ) ;
if ( V_31 != F_63 ( V_20 , V_99 ) )
return - V_79 ;
if ( F_64 ( V_31 , V_99 , V_97 , V_31 -> V_103 , NULL ) )
return - V_51 ;
if ( V_98 != F_65 ( V_31 , V_96 ,
V_31 , V_99 , V_98 , false ) )
return - V_51 ;
F_66 () ;
F_67 ( & V_102 , V_20 , V_96 , V_97 ) ;
if ( V_100 > V_96 ) {
F_68 ( & V_102 , V_100 , V_97 , V_100 ,
V_31 -> V_104 ? V_31 -> V_104 -> V_35 : V_105 ) ;
} else {
F_68 ( & V_102 , V_96 , V_97 , V_100 ,
V_31 -> V_104 ? V_31 -> V_104 -> V_35 : V_105 ) ;
}
F_69 ( & V_102 , V_96 , V_97 ) ;
F_64 ( V_31 , V_99 , V_100 , V_31 -> V_103 , NULL ) ;
return 0 ;
}
int F_70 ( struct V_16 * V_17 ,
unsigned long V_106 ,
int V_107 )
{
unsigned long V_28 ;
unsigned long V_108 ;
struct V_19 * V_20 = V_21 -> V_20 ;
struct V_48 * V_31 = V_17 -> V_31 ;
struct V_48 * V_109 = NULL ;
unsigned long V_59 ;
unsigned long V_110 ;
unsigned long V_111 ;
unsigned long V_112 ;
unsigned long V_113 ;
#ifdef F_16
V_110 = F_71 ( V_45 ) ;
if ( V_110 > V_114 )
V_110 = V_114 ;
V_110 += ( V_115 << V_116 ) ;
if ( V_31 -> V_34 - V_31 -> V_35 > V_110 )
return - V_51 ;
V_110 = F_72 ( V_106 - V_110 ) ;
V_108 = V_31 -> V_35 - V_110 ;
V_20 -> V_117 = V_17 -> V_65 - V_108 ;
V_17 -> V_65 = V_31 -> V_34 - V_108 ;
#else
V_106 = F_73 ( V_106 ) ;
V_106 = F_72 ( V_106 ) ;
if ( F_45 ( V_106 < V_118 ) ||
F_45 ( V_31 -> V_34 - V_31 -> V_35 >= V_106 - V_118 ) )
return - V_51 ;
V_108 = V_31 -> V_34 - V_106 ;
V_17 -> V_65 -= V_108 ;
V_20 -> V_117 = V_17 -> V_65 ;
#endif
if ( V_17 -> V_119 )
V_17 -> V_119 -= V_108 ;
V_17 -> V_120 -= V_108 ;
if ( F_28 ( & V_20 -> V_52 ) )
return - V_53 ;
V_59 = V_56 ;
if ( F_45 ( V_107 == V_121 ) )
V_59 |= V_122 ;
else if ( V_107 == V_123 )
V_59 &= ~ V_122 ;
V_59 |= V_20 -> V_124 ;
V_59 |= V_57 ;
V_28 = F_74 ( V_31 , & V_109 , V_31 -> V_35 , V_31 -> V_34 ,
V_59 ) ;
if ( V_28 )
goto V_125;
F_2 ( V_109 != V_31 ) ;
if ( V_108 ) {
V_28 = F_62 ( V_31 , V_108 ) ;
if ( V_28 )
goto V_125;
}
V_31 -> V_59 &= ~ V_57 ;
V_112 = 131072UL ;
V_111 = V_31 -> V_34 - V_31 -> V_35 ;
V_113 = V_37 ( V_45 ) & V_90 ;
#ifdef F_16
if ( V_111 + V_112 > V_113 )
V_110 = V_31 -> V_35 + V_113 ;
else
V_110 = V_31 -> V_34 + V_112 ;
#else
if ( V_111 + V_112 > V_113 )
V_110 = V_31 -> V_34 - V_113 ;
else
V_110 = V_31 -> V_35 - V_112 ;
#endif
V_21 -> V_20 -> V_126 = V_17 -> V_65 ;
V_28 = F_75 ( V_31 , V_110 ) ;
if ( V_28 )
V_28 = - V_79 ;
V_125:
F_34 ( & V_20 -> V_52 ) ;
return V_28 ;
}
int F_76 ( struct V_16 * V_17 ,
unsigned long * V_127 )
{
unsigned long V_128 , V_129 , V_130 ;
int V_28 = 0 ;
V_129 = V_17 -> V_65 >> V_116 ;
V_130 = * V_127 ;
for ( V_128 = V_71 - 1 ; V_128 >= V_129 ; V_128 -- ) {
unsigned int V_88 = V_128 == V_129 ? V_17 -> V_65 & ~ V_90 : 0 ;
char * V_131 = F_57 ( V_17 -> V_25 [ V_128 ] ) + V_88 ;
V_130 -= V_43 - V_88 ;
if ( F_77 ( ( void * ) V_130 , V_131 , V_43 - V_88 ) != 0 )
V_28 = - V_79 ;
F_56 ( V_17 -> V_25 [ V_128 ] ) ;
if ( V_28 )
goto V_87;
}
* V_127 = V_130 ;
V_87:
return V_28 ;
}
static struct V_132 * F_78 ( int V_133 , struct V_134 * V_135 , int V_136 )
{
struct V_132 * V_132 ;
int V_47 ;
struct V_137 V_138 = {
. V_139 = V_140 | V_141 | V_142 ,
. V_143 = V_144 ,
. V_145 = V_146 ,
. V_147 = V_148 ,
} ;
if ( ( V_136 & ~ ( V_149 | V_150 ) ) != 0 )
return F_47 ( - V_151 ) ;
if ( V_136 & V_149 )
V_138 . V_147 &= ~ V_148 ;
if ( V_136 & V_150 )
V_138 . V_147 |= V_152 ;
V_132 = F_79 ( V_133 , V_135 , & V_138 ) ;
if ( F_50 ( V_132 ) )
goto V_87;
V_47 = - V_153 ;
if ( ! F_80 ( F_81 ( V_132 ) -> V_154 ) )
goto exit;
if ( F_12 ( & V_132 -> V_155 ) )
goto exit;
V_47 = F_82 ( V_132 ) ;
if ( V_47 )
goto exit;
if ( V_135 -> V_135 [ 0 ] != '\0' )
F_83 ( V_132 ) ;
V_87:
return V_132 ;
exit:
F_84 ( V_132 ) ;
return F_47 ( V_47 ) ;
}
struct V_132 * F_85 ( const char * V_135 )
{
struct V_134 * V_134 = F_86 ( V_135 ) ;
struct V_132 * V_156 = F_87 ( V_134 ) ;
if ( ! F_50 ( V_134 ) ) {
V_156 = F_78 ( V_157 , V_134 , 0 ) ;
F_88 ( V_134 ) ;
}
return V_156 ;
}
int F_89 ( struct V_132 * V_132 , T_4 V_88 ,
char * V_158 , unsigned long F_49 )
{
T_3 V_159 ;
T_4 V_26 = V_88 ;
int V_160 ;
V_159 = F_60 () ;
F_61 ( F_90 () ) ;
V_160 = F_91 ( V_132 , ( void T_1 * ) V_158 , F_49 , & V_26 ) ;
F_61 ( V_159 ) ;
return V_160 ;
}
int F_92 ( struct V_132 * V_132 , void * * V_161 , T_4 * V_33 ,
T_4 V_162 , enum V_163 V_164 )
{
T_4 V_165 , V_26 ;
T_5 V_166 = 0 ;
int V_28 ;
if ( ! F_80 ( F_81 ( V_132 ) -> V_154 ) || V_162 < 0 )
return - V_151 ;
V_28 = F_93 ( V_132 , V_164 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_82 ( V_132 ) ;
if ( V_28 )
return V_28 ;
V_165 = F_94 ( F_81 ( V_132 ) ) ;
if ( V_162 > 0 && V_165 > V_162 ) {
V_28 = - V_167 ;
goto V_87;
}
if ( V_165 <= 0 ) {
V_28 = - V_151 ;
goto V_87;
}
if ( V_164 != V_168 )
* V_161 = F_95 ( V_165 ) ;
if ( ! * V_161 ) {
V_28 = - V_51 ;
goto V_87;
}
V_26 = 0 ;
while ( V_26 < V_165 ) {
V_166 = F_89 ( V_132 , V_26 , ( char * ) ( * V_161 ) + V_26 ,
V_165 - V_26 ) ;
if ( V_166 < 0 ) {
V_28 = V_166 ;
goto V_87;
}
if ( V_166 == 0 )
break;
V_26 += V_166 ;
}
if ( V_26 != V_165 ) {
V_28 = - V_169 ;
goto V_170;
}
V_28 = F_96 ( V_132 , * V_161 , V_165 , V_164 ) ;
if ( ! V_28 )
* V_33 = V_26 ;
V_170:
if ( V_28 < 0 ) {
if ( V_164 != V_168 ) {
F_97 ( * V_161 ) ;
* V_161 = NULL ;
}
}
V_87:
F_98 ( V_132 ) ;
return V_28 ;
}
int F_99 ( char * V_9 , void * * V_161 , T_4 * V_33 ,
T_4 V_162 , enum V_163 V_164 )
{
struct V_132 * V_132 ;
int V_28 ;
if ( ! V_9 || ! * V_9 )
return - V_151 ;
V_132 = F_100 ( V_9 , V_141 , 0 ) ;
if ( F_50 ( V_132 ) )
return F_101 ( V_132 ) ;
V_28 = F_92 ( V_132 , V_161 , V_33 , V_162 , V_164 ) ;
F_84 ( V_132 ) ;
return V_28 ;
}
int F_102 ( int V_133 , void * * V_161 , T_4 * V_33 , T_4 V_162 ,
enum V_163 V_164 )
{
struct V_133 V_156 = F_103 ( V_133 ) ;
int V_28 = - V_171 ;
if ( ! V_156 . V_132 )
goto V_87;
V_28 = F_92 ( V_156 . V_132 , V_161 , V_33 , V_162 , V_164 ) ;
V_87:
F_104 ( V_156 ) ;
return V_28 ;
}
T_5 F_105 ( struct V_132 * V_132 , unsigned long V_158 , T_4 V_26 , T_6 V_66 )
{
T_5 V_172 = F_91 ( V_132 , ( void T_1 * ) V_158 , V_66 , & V_26 ) ;
if ( V_172 > 0 )
F_106 ( V_158 , V_158 + V_66 ) ;
return V_172 ;
}
static int F_107 ( struct V_19 * V_20 )
{
struct V_173 * V_174 ;
struct V_19 * V_175 , * V_176 ;
V_174 = V_21 ;
V_175 = V_21 -> V_20 ;
F_108 ( V_174 , V_175 ) ;
if ( V_175 ) {
F_109 ( V_175 ) ;
F_110 ( & V_175 -> V_52 ) ;
if ( F_45 ( V_175 -> V_177 ) ) {
F_111 ( & V_175 -> V_52 ) ;
return - V_53 ;
}
}
F_112 ( V_174 ) ;
V_176 = V_174 -> V_176 ;
V_174 -> V_20 = V_20 ;
V_174 -> V_176 = V_20 ;
F_113 ( V_176 , V_20 ) ;
V_174 -> V_20 -> V_178 = 0 ;
F_114 ( V_174 ) ;
F_115 ( V_174 ) ;
if ( V_175 ) {
F_111 ( & V_175 -> V_52 ) ;
F_2 ( V_176 != V_175 ) ;
F_116 ( & V_174 -> signal -> V_179 , V_175 ) ;
F_117 ( V_175 ) ;
F_118 ( V_175 ) ;
return 0 ;
}
F_42 ( V_176 ) ;
return 0 ;
}
static int F_119 ( struct V_173 * V_174 )
{
struct V_180 * V_181 = V_174 -> signal ;
struct V_182 * V_183 = V_174 -> V_184 ;
T_7 * V_185 = & V_183 -> V_186 ;
if ( F_120 ( V_174 ) )
goto V_187;
F_121 ( V_185 ) ;
if ( F_122 ( V_181 ) ) {
F_123 ( V_185 ) ;
return - V_188 ;
}
V_181 -> V_189 = V_174 ;
V_181 -> V_190 = F_124 ( V_174 ) ;
if ( ! F_125 ( V_174 ) )
V_181 -> V_190 -- ;
while ( V_181 -> V_190 ) {
F_126 ( V_191 ) ;
F_123 ( V_185 ) ;
F_127 () ;
if ( F_45 ( F_128 ( V_174 ) ) )
goto V_192;
F_121 ( V_185 ) ;
}
F_123 ( V_185 ) ;
if ( ! F_125 ( V_174 ) ) {
struct V_173 * V_193 = V_174 -> V_194 ;
for (; ; ) {
F_129 ( V_174 ) ;
F_130 ( & V_195 ) ;
V_181 -> V_190 = - 1 ;
if ( F_131 ( V_193 -> V_196 ) )
break;
F_126 ( V_191 ) ;
F_132 ( & V_195 ) ;
F_133 ( V_174 ) ;
F_127 () ;
if ( F_45 ( F_128 ( V_174 ) ) )
goto V_192;
}
V_174 -> V_197 = V_193 -> V_197 ;
V_174 -> V_198 = V_193 -> V_198 ;
F_2 ( ! F_134 ( V_193 , V_174 ) ) ;
F_2 ( F_135 ( V_174 ) ) ;
V_174 -> V_199 = V_193 -> V_199 ;
F_136 ( V_174 , V_200 , F_137 ( V_193 ) ) ;
F_138 ( V_193 , V_174 , V_201 ) ;
F_138 ( V_193 , V_174 , V_202 ) ;
F_139 ( & V_193 -> V_203 , & V_174 -> V_203 ) ;
F_140 ( & V_193 -> V_204 , & V_174 -> V_204 ) ;
V_174 -> V_194 = V_174 ;
V_193 -> V_194 = V_174 ;
V_174 -> V_205 = V_206 ;
V_193 -> V_205 = - 1 ;
F_2 ( V_193 -> V_196 != V_207 ) ;
V_193 -> V_196 = V_208 ;
if ( F_45 ( V_193 -> V_209 ) )
F_141 ( V_193 , V_193 -> V_210 ) ;
F_132 ( & V_195 ) ;
F_133 ( V_174 ) ;
F_142 ( V_193 ) ;
}
V_181 -> V_189 = NULL ;
V_181 -> V_190 = 0 ;
V_187:
V_174 -> V_205 = V_206 ;
#ifdef F_143
F_144 ( V_181 ) ;
F_145 () ;
#endif
if ( F_146 ( & V_183 -> F_49 ) != 1 ) {
struct V_182 * V_211 ;
V_211 = F_147 ( V_212 , V_50 ) ;
if ( ! V_211 )
return - V_51 ;
F_148 ( & V_211 -> F_49 , 1 ) ;
memcpy ( V_211 -> V_213 , V_183 -> V_213 ,
sizeof( V_211 -> V_213 ) ) ;
F_130 ( & V_195 ) ;
F_149 ( & V_183 -> V_186 ) ;
F_150 ( V_174 -> V_184 , V_211 ) ;
F_151 ( & V_183 -> V_186 ) ;
F_132 ( & V_195 ) ;
F_152 ( V_183 ) ;
}
F_2 ( ! F_125 ( V_174 ) ) ;
return 0 ;
V_192:
F_153 ( & V_195 ) ;
V_181 -> V_189 = NULL ;
V_181 -> V_190 = 0 ;
F_154 ( & V_195 ) ;
return - V_188 ;
}
char * F_155 ( char * V_161 , struct V_173 * V_174 )
{
F_112 ( V_174 ) ;
strncpy ( V_161 , V_174 -> V_214 , sizeof( V_174 -> V_214 ) ) ;
F_115 ( V_174 ) ;
return V_161 ;
}
void F_156 ( struct V_173 * V_174 , const char * V_161 , bool V_120 )
{
F_112 ( V_174 ) ;
F_157 ( V_174 , V_161 ) ;
F_158 ( V_174 -> V_214 , V_161 , sizeof( V_174 -> V_214 ) ) ;
F_115 ( V_174 ) ;
F_159 ( V_174 , V_120 ) ;
}
int F_160 ( struct V_16 * V_17 )
{
int V_215 ;
V_215 = F_119 ( V_21 ) ;
if ( V_215 )
goto V_87;
F_161 ( V_17 -> V_20 , V_17 -> V_132 ) ;
F_13 ( V_17 , 0 ) ;
V_215 = F_107 ( V_17 -> V_20 ) ;
if ( V_215 )
goto V_87;
V_17 -> V_20 = NULL ;
F_61 ( V_216 ) ;
V_21 -> V_136 &= ~ ( V_217 | V_218 | V_219 |
V_220 | V_221 ) ;
F_162 () ;
V_21 -> V_222 &= ~ V_17 -> V_223 ;
F_163 ( V_21 -> V_224 ) ;
return 0 ;
V_87:
return V_215 ;
}
void F_164 ( struct V_16 * V_17 , struct V_132 * V_132 )
{
struct V_225 * V_225 = F_81 ( V_132 ) ;
if ( F_165 ( V_225 , V_226 ) < 0 ) {
struct V_227 * V_228 , * V_229 ;
V_17 -> V_230 |= V_231 ;
V_229 = V_228 = V_17 -> V_20 -> V_229 ;
while ( ( V_229 != & V_232 ) &&
! F_166 ( V_229 , V_225 ) )
V_229 = V_229 -> V_210 ;
if ( V_228 != V_229 ) {
V_17 -> V_20 -> V_229 = F_167 ( V_229 ) ;
F_168 ( V_228 ) ;
}
}
}
void F_169 ( struct V_16 * V_17 )
{
F_170 ( V_21 -> V_20 ) ;
V_21 -> V_233 = V_21 -> V_234 = 0 ;
if ( F_171 ( F_172 () , F_173 () ) && F_174 ( F_175 () , F_176 () ) )
F_177 ( V_21 -> V_20 , V_235 ) ;
else
F_177 ( V_21 -> V_20 , V_236 ) ;
F_178 () ;
F_179 () ;
F_156 ( V_21 , F_180 ( V_17 -> V_134 ) , true ) ;
V_21 -> V_20 -> V_237 = V_238 ;
if ( ! F_171 ( V_17 -> V_239 -> V_240 , F_172 () ) ||
! F_174 ( V_17 -> V_239 -> V_241 , F_175 () ) ) {
V_21 -> V_242 = 0 ;
} else {
if ( V_17 -> V_230 & V_231 )
F_177 ( V_21 -> V_20 , V_236 ) ;
}
V_21 -> V_243 ++ ;
F_181 ( V_21 , 0 ) ;
}
int F_182 ( struct V_16 * V_17 )
{
if ( F_183 ( & V_21 -> signal -> V_244 ) )
return - V_245 ;
V_17 -> V_239 = F_184 () ;
if ( F_131 ( V_17 -> V_239 ) )
return 0 ;
F_185 ( & V_21 -> signal -> V_244 ) ;
return - V_51 ;
}
static void F_186 ( struct V_16 * V_17 )
{
F_22 ( V_17 ) ;
if ( V_17 -> V_239 ) {
F_185 ( & V_21 -> signal -> V_244 ) ;
F_187 ( V_17 -> V_239 ) ;
}
if ( V_17 -> V_132 ) {
F_98 ( V_17 -> V_132 ) ;
F_84 ( V_17 -> V_132 ) ;
}
if ( V_17 -> V_246 != V_17 -> V_134 )
F_188 ( V_17 -> V_246 ) ;
F_188 ( V_17 ) ;
}
int F_189 ( char * V_246 , struct V_16 * V_17 )
{
if ( V_17 -> V_246 != V_17 -> V_134 )
F_188 ( V_17 -> V_246 ) ;
V_17 -> V_246 = F_190 ( V_246 , V_50 ) ;
if ( ! V_17 -> V_246 )
return - V_51 ;
return 0 ;
}
void F_191 ( struct V_16 * V_17 )
{
F_192 ( V_17 ) ;
F_193 ( V_17 -> V_239 ) ;
V_17 -> V_239 = NULL ;
if ( F_194 ( V_21 -> V_20 ) != V_235 )
F_195 ( V_21 ) ;
F_196 ( V_17 ) ;
F_185 ( & V_21 -> signal -> V_244 ) ;
}
static void F_197 ( struct V_16 * V_17 )
{
struct V_173 * V_65 = V_21 , * V_247 ;
unsigned V_248 ;
if ( V_65 -> V_209 )
V_17 -> V_249 |= V_250 ;
if ( F_198 ( V_21 ) )
V_17 -> V_249 |= V_251 ;
V_247 = V_65 ;
V_248 = 1 ;
F_149 ( & V_65 -> V_252 -> V_185 ) ;
F_199 () ;
F_200 (p, t) {
if ( V_247 -> V_252 == V_65 -> V_252 )
V_248 ++ ;
}
F_201 () ;
if ( V_65 -> V_252 -> V_253 > V_248 )
V_17 -> V_249 |= V_254 ;
else
V_65 -> V_252 -> V_255 = 1 ;
F_151 ( & V_65 -> V_252 -> V_185 ) ;
}
static void F_202 ( struct V_16 * V_17 )
{
struct V_225 * V_225 ;
unsigned int V_256 ;
T_8 V_240 ;
T_9 V_241 ;
V_17 -> V_239 -> V_257 = F_172 () ;
V_17 -> V_239 -> V_258 = F_175 () ;
if ( ! F_203 ( V_17 -> V_132 -> V_155 . V_10 ) )
return;
if ( F_198 ( V_21 ) )
return;
V_225 = V_17 -> V_132 -> V_155 . V_259 -> V_260 ;
V_256 = F_19 ( V_225 -> V_154 ) ;
if ( ! ( V_256 & ( V_261 | V_262 ) ) )
return;
F_204 ( V_225 ) ;
V_256 = V_225 -> V_154 ;
V_240 = V_225 -> V_263 ;
V_241 = V_225 -> V_264 ;
F_205 ( V_225 ) ;
if ( ! F_206 ( V_17 -> V_239 -> V_229 , V_240 ) ||
! F_207 ( V_17 -> V_239 -> V_229 , V_241 ) )
return;
if ( V_256 & V_261 ) {
V_17 -> V_223 |= V_265 ;
V_17 -> V_239 -> V_257 = V_240 ;
}
if ( ( V_256 & ( V_262 | V_266 ) ) == ( V_262 | V_266 ) ) {
V_17 -> V_223 |= V_265 ;
V_17 -> V_239 -> V_258 = V_241 ;
}
}
int F_208 ( struct V_16 * V_17 )
{
int V_215 ;
F_202 ( V_17 ) ;
V_215 = F_209 ( V_17 ) ;
if ( V_215 )
return V_215 ;
V_17 -> V_267 = 1 ;
memset ( V_17 -> V_161 , 0 , V_268 ) ;
return F_89 ( V_17 -> V_132 , 0 , V_17 -> V_161 , V_268 ) ;
}
int F_210 ( struct V_16 * V_17 )
{
int V_28 = 0 ;
unsigned long V_88 ;
char * V_84 ;
struct V_25 * V_25 ;
if ( ! V_17 -> V_39 )
return 0 ;
do {
V_88 = V_17 -> V_65 & ~ V_90 ;
V_25 = F_15 ( V_17 , V_17 -> V_65 , 0 ) ;
if ( ! V_25 ) {
V_28 = - V_79 ;
goto V_87;
}
V_84 = F_211 ( V_25 ) ;
for (; V_88 < V_43 && V_84 [ V_88 ] ;
V_88 ++ , V_17 -> V_65 ++ )
;
F_212 ( V_84 ) ;
F_21 ( V_25 ) ;
} while ( V_88 == V_43 );
V_17 -> V_65 ++ ;
V_17 -> V_39 -- ;
V_28 = 0 ;
V_87:
return V_28 ;
}
int F_213 ( struct V_16 * V_17 )
{
bool V_269 = F_214 ( V_270 ) ;
struct V_1 * V_2 ;
int V_215 ;
if ( V_17 -> V_271 > 5 )
return - V_272 ;
V_215 = F_215 ( V_17 ) ;
if ( V_215 )
return V_215 ;
V_215 = - V_273 ;
V_274:
F_153 ( & V_5 ) ;
F_216 (fmt, &formats, lh) {
if ( ! F_217 ( V_2 -> V_8 ) )
continue;
F_154 ( & V_5 ) ;
V_17 -> V_271 ++ ;
V_215 = V_2 -> V_4 ( V_17 ) ;
F_153 ( & V_5 ) ;
F_10 ( V_2 ) ;
V_17 -> V_271 -- ;
if ( V_215 < 0 && ! V_17 -> V_20 ) {
F_154 ( & V_5 ) ;
F_218 ( V_275 , V_21 ) ;
return V_215 ;
}
if ( V_215 != - V_276 || ! V_17 -> V_132 ) {
F_154 ( & V_5 ) ;
return V_215 ;
}
}
F_154 ( & V_5 ) ;
if ( V_269 ) {
if ( F_219 ( V_17 -> V_161 [ 0 ] ) && F_219 ( V_17 -> V_161 [ 1 ] ) &&
F_219 ( V_17 -> V_161 [ 2 ] ) && F_219 ( V_17 -> V_161 [ 3 ] ) )
return V_215 ;
if ( F_220 ( L_1 , * ( V_277 * ) ( V_17 -> V_161 + 2 ) ) < 0 )
return V_215 ;
V_269 = false ;
goto V_274;
}
return V_215 ;
}
static int F_221 ( struct V_16 * V_17 )
{
T_10 V_278 , V_279 ;
int V_28 ;
V_278 = V_21 -> V_199 ;
F_199 () ;
V_279 = F_222 ( V_21 , F_223 ( V_21 -> V_210 ) ) ;
F_201 () ;
V_28 = F_213 ( V_17 ) ;
if ( V_28 >= 0 ) {
F_224 ( V_17 ) ;
F_225 ( V_21 , V_278 , V_17 ) ;
F_226 ( V_280 , V_279 ) ;
F_227 ( V_21 ) ;
}
return V_28 ;
}
static int F_228 ( int V_133 , struct V_134 * V_134 ,
struct V_72 V_73 ,
struct V_72 V_281 ,
int V_136 )
{
char * V_282 = NULL ;
struct V_16 * V_17 ;
struct V_132 * V_132 ;
struct V_283 * V_284 ;
int V_215 ;
if ( F_50 ( V_134 ) )
return F_101 ( V_134 ) ;
if ( ( V_21 -> V_136 & V_285 ) &&
F_146 ( & F_229 () -> V_286 ) > V_37 ( V_287 ) ) {
V_215 = - V_188 ;
goto V_288;
}
V_21 -> V_136 &= ~ V_285 ;
V_215 = F_230 ( & V_284 ) ;
if ( V_215 )
goto V_288;
V_215 = - V_51 ;
V_17 = F_231 ( sizeof( * V_17 ) , V_50 ) ;
if ( ! V_17 )
goto V_289;
V_215 = F_182 ( V_17 ) ;
if ( V_215 )
goto V_170;
F_197 ( V_17 ) ;
V_21 -> V_290 = 1 ;
V_132 = F_78 ( V_133 , V_134 , V_136 ) ;
V_215 = F_101 ( V_132 ) ;
if ( F_50 ( V_132 ) )
goto V_291;
F_232 () ;
V_17 -> V_132 = V_132 ;
if ( V_133 == V_157 || V_134 -> V_135 [ 0 ] == '/' ) {
V_17 -> V_134 = V_134 -> V_135 ;
} else {
if ( V_134 -> V_135 [ 0 ] == '\0' )
V_282 = F_233 ( V_292 , L_2 , V_133 ) ;
else
V_282 = F_233 ( V_292 , L_3 ,
V_133 , V_134 -> V_135 ) ;
if ( ! V_282 ) {
V_215 = - V_51 ;
goto V_291;
}
if ( F_234 ( V_133 , F_235 ( V_21 -> V_224 -> V_293 ) ) )
V_17 -> V_230 |= V_294 ;
V_17 -> V_134 = V_282 ;
}
V_17 -> V_246 = V_17 -> V_134 ;
V_215 = F_40 ( V_17 ) ;
if ( V_215 )
goto V_291;
V_17 -> V_39 = F_49 ( V_73 , V_295 ) ;
if ( ( V_215 = V_17 -> V_39 ) < 0 )
goto V_87;
V_17 -> V_40 = F_49 ( V_281 , V_295 ) ;
if ( ( V_215 = V_17 -> V_40 ) < 0 )
goto V_87;
V_215 = F_208 ( V_17 ) ;
if ( V_215 < 0 )
goto V_87;
V_215 = F_59 ( 1 , & V_17 -> V_134 , V_17 ) ;
if ( V_215 < 0 )
goto V_87;
V_17 -> V_120 = V_17 -> V_65 ;
V_215 = F_53 ( V_17 -> V_40 , V_281 , V_17 ) ;
if ( V_215 < 0 )
goto V_87;
V_215 = F_53 ( V_17 -> V_39 , V_73 , V_17 ) ;
if ( V_215 < 0 )
goto V_87;
F_164 ( V_17 , V_17 -> V_132 ) ;
V_215 = F_221 ( V_17 ) ;
if ( V_215 < 0 )
goto V_87;
V_21 -> V_252 -> V_255 = 0 ;
V_21 -> V_290 = 0 ;
F_236 ( V_21 ) ;
F_237 ( V_21 ) ;
F_186 ( V_17 ) ;
F_188 ( V_282 ) ;
F_88 ( V_134 ) ;
if ( V_284 )
F_238 ( V_284 ) ;
return V_215 ;
V_87:
if ( V_17 -> V_20 ) {
F_13 ( V_17 , 0 ) ;
F_118 ( V_17 -> V_20 ) ;
}
V_291:
V_21 -> V_252 -> V_255 = 0 ;
V_21 -> V_290 = 0 ;
V_170:
F_186 ( V_17 ) ;
F_188 ( V_282 ) ;
V_289:
if ( V_284 )
F_239 ( V_284 ) ;
V_288:
F_88 ( V_134 ) ;
return V_215 ;
}
int F_240 ( struct V_134 * V_134 ,
const char T_1 * const T_1 * V_91 ,
const char T_1 * const T_1 * V_296 )
{
struct V_72 V_73 = { . V_78 . V_75 = V_91 } ;
struct V_72 V_281 = { . V_78 . V_75 = V_296 } ;
return F_228 ( V_157 , V_134 , V_73 , V_281 , 0 ) ;
}
int F_241 ( int V_133 , struct V_134 * V_134 ,
const char T_1 * const T_1 * V_91 ,
const char T_1 * const T_1 * V_296 ,
int V_136 )
{
struct V_72 V_73 = { . V_78 . V_75 = V_91 } ;
struct V_72 V_281 = { . V_78 . V_75 = V_296 } ;
return F_228 ( V_133 , V_134 , V_73 , V_281 , V_136 ) ;
}
static int F_242 ( struct V_134 * V_134 ,
const T_2 T_1 * V_91 ,
const T_2 T_1 * V_296 )
{
struct V_72 V_73 = {
. V_76 = true ,
. V_78 . V_77 = V_91 ,
} ;
struct V_72 V_281 = {
. V_76 = true ,
. V_78 . V_77 = V_296 ,
} ;
return F_228 ( V_157 , V_134 , V_73 , V_281 , 0 ) ;
}
static int F_243 ( int V_133 , struct V_134 * V_134 ,
const T_2 T_1 * V_91 ,
const T_2 T_1 * V_296 ,
int V_136 )
{
struct V_72 V_73 = {
. V_76 = true ,
. V_78 . V_77 = V_91 ,
} ;
struct V_72 V_281 = {
. V_76 = true ,
. V_78 . V_77 = V_296 ,
} ;
return F_228 ( V_133 , V_134 , V_73 , V_281 , V_136 ) ;
}
void F_244 ( struct V_1 * V_297 )
{
struct V_19 * V_20 = V_21 -> V_20 ;
if ( V_20 -> V_298 )
F_11 ( V_20 -> V_298 -> V_8 ) ;
V_20 -> V_298 = V_297 ;
if ( V_297 )
F_245 ( V_297 -> V_8 ) ;
}
void F_177 ( struct V_19 * V_20 , int V_299 )
{
unsigned long V_228 , V_297 ;
if ( F_3 ( ( unsigned ) V_299 > V_300 ) )
return;
do {
V_228 = F_246 ( V_20 -> V_136 ) ;
V_297 = ( V_228 & ~ V_301 ) | V_299 ;
} while ( F_247 ( & V_20 -> V_136 , V_228 , V_297 ) != V_228 );
}
