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
F_33 ( V_13 , V_22 ) ;
F_34 ( & V_13 -> V_38 ) ;
V_10 -> V_49 = V_22 -> V_24 - sizeof( void * ) ;
return 0 ;
V_33:
F_34 ( & V_13 -> V_38 ) ;
V_10 -> V_22 = NULL ;
F_35 ( V_35 , V_22 ) ;
return V_33 ;
}
static bool F_36 ( struct V_9 * V_10 , long V_50 )
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
V_18 = F_37 ( V_52 | V_53 ) ;
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
F_38 ( V_10 -> V_18 [ V_32 ] ) ;
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
static bool F_36 ( struct V_9 * V_10 , long V_50 )
{
return V_50 <= V_10 -> V_49 ;
}
static int F_39 ( struct V_9 * V_10 )
{
int V_33 ;
struct V_12 * V_13 = NULL ;
V_10 -> V_13 = V_13 = F_40 () ;
V_33 = - V_37 ;
if ( ! V_13 )
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
if ( ! F_36 ( V_10 , V_50 ) )
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
V_94 += ( V_99 << V_100 ) ;
if ( V_22 -> V_24 - V_22 -> V_25 > V_94 )
return - V_37 ;
V_94 = F_71 ( V_90 - V_94 ) ;
V_92 = V_22 -> V_25 - V_94 ;
V_13 -> V_101 = V_10 -> V_49 - V_92 ;
V_10 -> V_49 = V_22 -> V_24 - V_92 ;
#else
V_90 = F_72 ( V_90 ) ;
V_90 = F_71 ( V_90 ) ;
if ( F_44 ( V_90 < V_102 ) ||
F_44 ( V_22 -> V_24 - V_22 -> V_25 >= V_90 - V_102 ) )
return - V_37 ;
V_92 = V_22 -> V_24 - V_90 ;
V_10 -> V_49 -= V_92 ;
V_13 -> V_101 = V_10 -> V_49 ;
#endif
if ( V_10 -> V_103 )
V_10 -> V_103 -= V_92 ;
V_10 -> V_104 -= V_92 ;
F_28 ( & V_13 -> V_38 ) ;
V_43 = V_40 ;
if ( F_44 ( V_91 == V_105 ) )
V_43 |= V_106 ;
else if ( V_91 == V_107 )
V_43 &= ~ V_106 ;
V_43 |= V_13 -> V_108 ;
V_43 |= V_41 ;
V_21 = F_73 ( V_22 , & V_93 , V_22 -> V_25 , V_22 -> V_24 ,
V_43 ) ;
if ( V_21 )
goto V_109;
F_2 ( V_93 != V_22 ) ;
if ( V_92 ) {
V_21 = F_61 ( V_22 , V_92 ) ;
if ( V_21 )
goto V_109;
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
V_14 -> V_13 -> V_110 = V_10 -> V_49 ;
V_21 = F_74 ( V_22 , V_94 ) ;
if ( V_21 )
V_21 = - V_62 ;
V_109:
F_34 ( & V_13 -> V_38 ) ;
return V_21 ;
}
static struct V_111 * F_75 ( int V_112 , struct V_113 * V_114 , int V_115 )
{
struct V_111 * V_111 ;
int V_33 ;
struct V_116 V_117 = {
. V_118 = V_119 | V_120 | V_121 ,
. V_122 = V_123 | V_124 ,
. V_125 = V_126 ,
. V_127 = V_128 ,
} ;
if ( ( V_115 & ~ ( V_129 | V_130 ) ) != 0 )
return F_46 ( - V_131 ) ;
if ( V_115 & V_129 )
V_117 . V_127 &= ~ V_128 ;
if ( V_115 & V_130 )
V_117 . V_127 |= V_132 ;
V_111 = F_76 ( V_112 , V_114 , & V_117 ) ;
if ( F_49 ( V_111 ) )
goto V_71;
V_33 = - V_133 ;
if ( ! F_77 ( F_78 ( V_111 ) -> V_134 ) )
goto exit;
if ( V_111 -> V_135 . V_136 -> V_137 & V_138 )
goto exit;
V_33 = F_79 ( V_111 ) ;
if ( V_33 )
goto exit;
if ( V_114 -> V_114 [ 0 ] != '\0' )
F_80 ( V_111 ) ;
V_71:
return V_111 ;
exit:
F_81 ( V_111 ) ;
return F_46 ( V_33 ) ;
}
struct V_111 * F_82 ( const char * V_114 )
{
struct V_113 * V_113 = F_83 ( V_114 ) ;
struct V_111 * V_139 = F_84 ( V_113 ) ;
if ( ! F_49 ( V_113 ) ) {
V_139 = F_75 ( V_140 , V_113 , 0 ) ;
F_85 ( V_113 ) ;
}
return V_139 ;
}
int F_86 ( struct V_111 * V_111 , T_4 V_72 ,
char * V_141 , unsigned long F_48 )
{
T_3 V_142 ;
T_4 V_19 = V_72 ;
int V_143 ;
V_142 = F_59 () ;
F_60 ( F_87 () ) ;
V_143 = F_88 ( V_111 , ( void T_1 * ) V_141 , F_48 , & V_19 ) ;
F_60 ( V_142 ) ;
return V_143 ;
}
T_5 F_89 ( struct V_111 * V_111 , unsigned long V_141 , T_4 V_19 , T_6 V_50 )
{
T_5 V_144 = F_88 ( V_111 , ( void T_1 * ) V_141 , V_50 , & V_19 ) ;
if ( V_144 > 0 )
F_90 ( V_141 , V_141 + V_50 ) ;
return V_144 ;
}
static int F_91 ( struct V_12 * V_13 )
{
struct V_145 * V_146 ;
struct V_12 * V_147 , * V_148 ;
V_146 = V_14 ;
V_147 = V_14 -> V_13 ;
F_92 ( V_146 , V_147 ) ;
if ( V_147 ) {
F_93 ( V_147 ) ;
F_94 ( & V_147 -> V_38 ) ;
if ( F_44 ( V_147 -> V_149 ) ) {
F_95 ( & V_147 -> V_38 ) ;
return - V_150 ;
}
}
F_96 ( V_146 ) ;
V_148 = V_146 -> V_148 ;
V_146 -> V_13 = V_13 ;
V_146 -> V_148 = V_13 ;
F_97 ( V_148 , V_13 ) ;
V_146 -> V_13 -> V_151 = 0 ;
F_98 ( V_146 ) ;
F_99 ( V_146 ) ;
if ( V_147 ) {
F_95 ( & V_147 -> V_38 ) ;
F_2 ( V_148 != V_147 ) ;
F_100 ( & V_146 -> signal -> V_152 , V_147 ) ;
F_101 ( V_147 ) ;
F_102 ( V_147 ) ;
return 0 ;
}
F_41 ( V_148 ) ;
return 0 ;
}
static int F_103 ( struct V_145 * V_146 )
{
struct V_153 * V_154 = V_146 -> signal ;
struct V_155 * V_156 = V_146 -> V_157 ;
T_7 * V_158 = & V_156 -> V_159 ;
if ( F_104 ( V_146 ) )
goto V_160;
F_105 ( V_158 ) ;
if ( F_106 ( V_154 ) ) {
F_107 ( V_158 ) ;
return - V_161 ;
}
V_154 -> V_162 = V_146 ;
V_154 -> V_163 = F_108 ( V_146 ) ;
if ( ! F_109 ( V_146 ) )
V_154 -> V_163 -- ;
while ( V_154 -> V_163 ) {
F_110 ( V_164 ) ;
F_107 ( V_158 ) ;
F_111 () ;
if ( F_44 ( F_112 ( V_146 ) ) )
goto V_165;
F_105 ( V_158 ) ;
}
F_107 ( V_158 ) ;
if ( ! F_109 ( V_146 ) ) {
struct V_145 * V_166 = V_146 -> V_167 ;
for (; ; ) {
F_113 ( V_146 ) ;
F_114 ( & V_168 ) ;
V_154 -> V_163 = - 1 ;
if ( F_115 ( V_166 -> V_169 ) )
break;
F_110 ( V_164 ) ;
F_116 ( & V_168 ) ;
F_117 ( V_146 ) ;
F_111 () ;
if ( F_44 ( F_112 ( V_146 ) ) )
goto V_165;
}
V_146 -> V_170 = V_166 -> V_170 ;
V_146 -> V_171 = V_166 -> V_171 ;
F_2 ( ! F_118 ( V_166 , V_146 ) ) ;
F_2 ( F_119 ( V_146 ) ) ;
V_146 -> V_172 = V_166 -> V_172 ;
F_120 ( V_146 , V_173 , F_121 ( V_166 ) ) ;
F_122 ( V_166 , V_146 , V_174 ) ;
F_122 ( V_166 , V_146 , V_175 ) ;
F_123 ( & V_166 -> V_176 , & V_146 -> V_176 ) ;
F_124 ( & V_166 -> V_177 , & V_146 -> V_177 ) ;
V_146 -> V_167 = V_146 ;
V_166 -> V_167 = V_146 ;
V_146 -> V_178 = V_179 ;
V_166 -> V_178 = - 1 ;
F_2 ( V_166 -> V_169 != V_180 ) ;
V_166 -> V_169 = V_181 ;
if ( F_44 ( V_166 -> V_182 ) )
F_125 ( V_166 , V_166 -> V_183 ) ;
F_116 ( & V_168 ) ;
F_117 ( V_146 ) ;
F_126 ( V_166 ) ;
}
V_154 -> V_162 = NULL ;
V_154 -> V_163 = 0 ;
V_160:
V_146 -> V_178 = V_179 ;
F_127 ( V_154 ) ;
F_128 () ;
if ( F_129 ( & V_156 -> F_48 ) != 1 ) {
struct V_155 * V_184 ;
V_184 = F_130 ( V_185 , V_36 ) ;
if ( ! V_184 )
return - V_37 ;
F_131 ( & V_184 -> F_48 , 1 ) ;
memcpy ( V_184 -> V_186 , V_156 -> V_186 ,
sizeof( V_184 -> V_186 ) ) ;
F_114 ( & V_168 ) ;
F_132 ( & V_156 -> V_159 ) ;
F_133 ( V_146 -> V_157 , V_184 ) ;
F_134 ( & V_156 -> V_159 ) ;
F_116 ( & V_168 ) ;
F_135 ( V_156 ) ;
}
F_2 ( ! F_109 ( V_146 ) ) ;
return 0 ;
V_165:
F_136 ( & V_168 ) ;
V_154 -> V_162 = NULL ;
V_154 -> V_163 = 0 ;
F_137 ( & V_168 ) ;
return - V_161 ;
}
char * F_138 ( char * V_187 , struct V_145 * V_146 )
{
F_96 ( V_146 ) ;
strncpy ( V_187 , V_146 -> V_188 , sizeof( V_146 -> V_188 ) ) ;
F_99 ( V_146 ) ;
return V_187 ;
}
void F_139 ( struct V_145 * V_146 , const char * V_187 , bool V_104 )
{
F_96 ( V_146 ) ;
F_140 ( V_146 , V_187 ) ;
F_141 ( V_146 -> V_188 , V_187 , sizeof( V_146 -> V_188 ) ) ;
F_99 ( V_146 ) ;
F_142 ( V_146 , V_104 ) ;
}
int F_143 ( struct V_9 * V_10 )
{
int V_189 ;
V_189 = F_103 ( V_14 ) ;
if ( V_189 )
goto V_71;
F_144 ( V_10 -> V_13 , V_10 -> V_111 ) ;
F_12 ( V_10 , 0 ) ;
V_189 = F_91 ( V_10 -> V_13 ) ;
if ( V_189 )
goto V_71;
V_10 -> V_13 = NULL ;
F_60 ( V_190 ) ;
V_14 -> V_115 &= ~ ( V_191 | V_192 | V_193 |
V_194 | V_195 ) ;
F_145 () ;
V_14 -> V_196 &= ~ V_10 -> V_197 ;
return 0 ;
V_71:
return V_189 ;
}
void F_146 ( struct V_9 * V_10 , struct V_111 * V_111 )
{
if ( F_147 ( F_78 ( V_111 ) , V_198 ) < 0 )
V_10 -> V_199 |= V_200 ;
}
void F_148 ( struct V_9 * V_10 )
{
F_149 ( V_14 -> V_13 ) ;
V_14 -> V_201 = V_14 -> V_202 = 0 ;
if ( F_150 ( F_151 () , F_152 () ) && F_153 ( F_154 () , F_155 () ) )
F_156 ( V_14 -> V_13 , V_203 ) ;
else
F_156 ( V_14 -> V_13 , V_204 ) ;
F_157 () ;
F_139 ( V_14 , F_158 ( V_10 -> V_113 ) , true ) ;
V_14 -> V_13 -> V_205 = V_206 ;
if ( ! F_150 ( V_10 -> V_207 -> V_208 , F_151 () ) ||
! F_153 ( V_10 -> V_207 -> V_209 , F_154 () ) ) {
V_14 -> V_210 = 0 ;
} else {
F_146 ( V_10 , V_10 -> V_111 ) ;
if ( V_10 -> V_199 & V_200 )
F_156 ( V_14 -> V_13 , V_204 ) ;
}
V_14 -> V_211 ++ ;
F_159 ( V_14 , 0 ) ;
F_160 ( V_14 -> V_212 ) ;
}
int F_161 ( struct V_9 * V_10 )
{
if ( F_162 ( & V_14 -> signal -> V_213 ) )
return - V_214 ;
V_10 -> V_207 = F_163 () ;
if ( F_115 ( V_10 -> V_207 ) )
return 0 ;
F_164 ( & V_14 -> signal -> V_213 ) ;
return - V_37 ;
}
static void F_165 ( struct V_9 * V_10 )
{
F_22 ( V_10 ) ;
if ( V_10 -> V_207 ) {
F_164 ( & V_14 -> signal -> V_213 ) ;
F_166 ( V_10 -> V_207 ) ;
}
if ( V_10 -> V_111 ) {
F_167 ( V_10 -> V_111 ) ;
F_81 ( V_10 -> V_111 ) ;
}
if ( V_10 -> V_215 != V_10 -> V_113 )
F_168 ( V_10 -> V_215 ) ;
F_168 ( V_10 ) ;
}
int F_169 ( char * V_215 , struct V_9 * V_10 )
{
if ( V_10 -> V_215 != V_10 -> V_113 )
F_168 ( V_10 -> V_215 ) ;
V_10 -> V_215 = F_170 ( V_215 , V_36 ) ;
if ( ! V_10 -> V_215 )
return - V_37 ;
return 0 ;
}
void F_171 ( struct V_9 * V_10 )
{
F_172 ( V_10 ) ;
F_173 ( V_10 -> V_207 ) ;
V_10 -> V_207 = NULL ;
if ( F_174 ( V_14 -> V_13 ) != V_203 )
F_175 ( V_14 ) ;
F_176 ( V_10 ) ;
F_164 ( & V_14 -> signal -> V_213 ) ;
}
static void F_177 ( struct V_9 * V_10 )
{
struct V_145 * V_49 = V_14 , * V_216 ;
unsigned V_217 ;
if ( V_49 -> V_182 ) {
if ( V_49 -> V_182 & V_218 )
V_10 -> V_219 |= V_220 ;
else
V_10 -> V_219 |= V_221 ;
}
if ( F_178 ( V_14 ) )
V_10 -> V_219 |= V_222 ;
V_216 = V_49 ;
V_217 = 1 ;
F_132 ( & V_49 -> V_223 -> V_158 ) ;
F_179 () ;
F_180 (p, t) {
if ( V_216 -> V_223 == V_49 -> V_223 )
V_217 ++ ;
}
F_181 () ;
if ( V_49 -> V_223 -> V_224 > V_217 )
V_10 -> V_219 |= V_225 ;
else
V_49 -> V_223 -> V_226 = 1 ;
F_134 ( & V_49 -> V_223 -> V_158 ) ;
}
static void F_182 ( struct V_9 * V_10 )
{
struct V_227 * V_227 ;
unsigned int V_228 ;
T_8 V_208 ;
T_9 V_209 ;
V_10 -> V_207 -> V_229 = F_151 () ;
V_10 -> V_207 -> V_230 = F_154 () ;
if ( V_10 -> V_111 -> V_135 . V_136 -> V_137 & V_231 )
return;
if ( F_178 ( V_14 ) )
return;
V_227 = F_78 ( V_10 -> V_111 ) ;
V_228 = F_183 ( V_227 -> V_134 ) ;
if ( ! ( V_228 & ( V_232 | V_233 ) ) )
return;
F_184 ( & V_227 -> V_234 ) ;
V_228 = V_227 -> V_134 ;
V_208 = V_227 -> V_235 ;
V_209 = V_227 -> V_236 ;
F_164 ( & V_227 -> V_234 ) ;
if ( ! F_185 ( V_10 -> V_207 -> V_237 , V_208 ) ||
! F_186 ( V_10 -> V_207 -> V_237 , V_209 ) )
return;
if ( V_228 & V_232 ) {
V_10 -> V_197 |= V_238 ;
V_10 -> V_207 -> V_229 = V_208 ;
}
if ( ( V_228 & ( V_233 | V_239 ) ) == ( V_233 | V_239 ) ) {
V_10 -> V_197 |= V_238 ;
V_10 -> V_207 -> V_230 = V_209 ;
}
}
int F_187 ( struct V_9 * V_10 )
{
int V_189 ;
F_182 ( V_10 ) ;
V_189 = F_188 ( V_10 ) ;
if ( V_189 )
return V_189 ;
V_10 -> V_240 = 1 ;
memset ( V_10 -> V_187 , 0 , V_241 ) ;
return F_86 ( V_10 -> V_111 , 0 , V_10 -> V_187 , V_241 ) ;
}
int F_189 ( struct V_9 * V_10 )
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
V_68 = F_190 ( V_18 ) ;
for (; V_72 < V_28 && V_68 [ V_72 ] ;
V_72 ++ , V_10 -> V_49 ++ )
;
F_191 ( V_68 ) ;
F_20 ( V_18 ) ;
if ( V_72 == V_28 )
F_21 ( V_10 , ( V_10 -> V_49 >> V_100 ) - 1 ) ;
} while ( V_72 == V_28 );
V_10 -> V_49 ++ ;
V_10 -> V_66 -- ;
V_21 = 0 ;
V_71:
return V_21 ;
}
int F_192 ( struct V_9 * V_10 )
{
bool V_242 = F_193 ( V_243 ) ;
struct V_1 * V_2 ;
int V_189 ;
if ( V_10 -> V_244 > 5 )
return - V_245 ;
V_189 = F_194 ( V_10 ) ;
if ( V_189 )
return V_189 ;
V_189 = - V_246 ;
V_247:
F_136 ( & V_5 ) ;
F_195 (fmt, &formats, lh) {
if ( ! F_196 ( V_2 -> V_8 ) )
continue;
F_137 ( & V_5 ) ;
V_10 -> V_244 ++ ;
V_189 = V_2 -> V_4 ( V_10 ) ;
F_136 ( & V_5 ) ;
F_10 ( V_2 ) ;
V_10 -> V_244 -- ;
if ( V_189 < 0 && ! V_10 -> V_13 ) {
F_137 ( & V_5 ) ;
F_197 ( V_248 , V_14 ) ;
return V_189 ;
}
if ( V_189 != - V_249 || ! V_10 -> V_111 ) {
F_137 ( & V_5 ) ;
return V_189 ;
}
}
F_137 ( & V_5 ) ;
if ( V_242 ) {
if ( F_198 ( V_10 -> V_187 [ 0 ] ) && F_198 ( V_10 -> V_187 [ 1 ] ) &&
F_198 ( V_10 -> V_187 [ 2 ] ) && F_198 ( V_10 -> V_187 [ 3 ] ) )
return V_189 ;
if ( F_199 ( L_1 , * ( V_250 * ) ( V_10 -> V_187 + 2 ) ) < 0 )
return V_189 ;
V_242 = false ;
goto V_247;
}
return V_189 ;
}
static int F_200 ( struct V_9 * V_10 )
{
T_10 V_251 , V_252 ;
int V_21 ;
V_251 = V_14 -> V_172 ;
F_179 () ;
V_252 = F_201 ( V_14 , F_202 ( V_14 -> V_183 ) ) ;
F_181 () ;
V_21 = F_192 ( V_10 ) ;
if ( V_21 >= 0 ) {
F_203 ( V_10 ) ;
F_204 ( V_14 , V_251 , V_10 ) ;
F_205 ( V_253 , V_252 ) ;
F_206 ( V_14 ) ;
}
return V_21 ;
}
static int F_207 ( int V_112 , struct V_113 * V_113 ,
struct V_55 V_56 ,
struct V_55 V_254 ,
int V_115 )
{
char * V_255 = NULL ;
struct V_9 * V_10 ;
struct V_111 * V_111 ;
struct V_256 * V_257 ;
int V_189 ;
if ( F_49 ( V_113 ) )
return F_208 ( V_113 ) ;
if ( ( V_14 -> V_115 & V_258 ) &&
F_129 ( & F_209 () -> V_259 ) > V_26 ( V_260 ) ) {
V_189 = - V_161 ;
goto V_261;
}
V_14 -> V_115 &= ~ V_258 ;
V_189 = F_210 ( & V_257 ) ;
if ( V_189 )
goto V_261;
V_189 = - V_37 ;
V_10 = F_211 ( sizeof( * V_10 ) , V_36 ) ;
if ( ! V_10 )
goto V_262;
V_189 = F_161 ( V_10 ) ;
if ( V_189 )
goto V_263;
F_177 ( V_10 ) ;
V_14 -> V_264 = 1 ;
V_111 = F_75 ( V_112 , V_113 , V_115 ) ;
V_189 = F_208 ( V_111 ) ;
if ( F_49 ( V_111 ) )
goto V_265;
F_212 () ;
V_10 -> V_111 = V_111 ;
if ( V_112 == V_140 || V_113 -> V_114 [ 0 ] == '/' ) {
V_10 -> V_113 = V_113 -> V_114 ;
} else {
if ( V_113 -> V_114 [ 0 ] == '\0' )
V_255 = F_213 ( V_266 , L_2 , V_112 ) ;
else
V_255 = F_213 ( V_266 , L_3 ,
V_112 , V_113 -> V_114 ) ;
if ( ! V_255 ) {
V_189 = - V_37 ;
goto V_265;
}
if ( F_214 ( V_112 , F_215 ( V_14 -> V_212 -> V_267 ) ) )
V_10 -> V_199 |= V_268 ;
V_10 -> V_113 = V_255 ;
}
V_10 -> V_215 = V_10 -> V_113 ;
V_189 = F_39 ( V_10 ) ;
if ( V_189 )
goto V_265;
V_10 -> V_66 = F_48 ( V_56 , V_269 ) ;
if ( ( V_189 = V_10 -> V_66 ) < 0 )
goto V_71;
V_10 -> V_270 = F_48 ( V_254 , V_269 ) ;
if ( ( V_189 = V_10 -> V_270 ) < 0 )
goto V_71;
V_189 = F_187 ( V_10 ) ;
if ( V_189 < 0 )
goto V_71;
V_189 = F_58 ( 1 , & V_10 -> V_113 , V_10 ) ;
if ( V_189 < 0 )
goto V_71;
V_10 -> V_104 = V_10 -> V_49 ;
V_189 = F_52 ( V_10 -> V_270 , V_254 , V_10 ) ;
if ( V_189 < 0 )
goto V_71;
V_189 = F_52 ( V_10 -> V_66 , V_56 , V_10 ) ;
if ( V_189 < 0 )
goto V_71;
V_189 = F_200 ( V_10 ) ;
if ( V_189 < 0 )
goto V_71;
V_14 -> V_223 -> V_226 = 0 ;
V_14 -> V_264 = 0 ;
F_216 ( V_14 ) ;
F_217 ( V_14 ) ;
F_165 ( V_10 ) ;
F_168 ( V_255 ) ;
F_85 ( V_113 ) ;
if ( V_257 )
F_218 ( V_257 ) ;
return V_189 ;
V_71:
if ( V_10 -> V_13 ) {
F_12 ( V_10 , 0 ) ;
F_102 ( V_10 -> V_13 ) ;
}
V_265:
V_14 -> V_223 -> V_226 = 0 ;
V_14 -> V_264 = 0 ;
V_263:
F_165 ( V_10 ) ;
F_168 ( V_255 ) ;
V_262:
if ( V_257 )
F_219 ( V_257 ) ;
V_261:
F_85 ( V_113 ) ;
return V_189 ;
}
int F_220 ( struct V_113 * V_113 ,
const char T_1 * const T_1 * V_75 ,
const char T_1 * const T_1 * V_271 )
{
struct V_55 V_56 = { . V_61 . V_58 = V_75 } ;
struct V_55 V_254 = { . V_61 . V_58 = V_271 } ;
return F_207 ( V_140 , V_113 , V_56 , V_254 , 0 ) ;
}
int F_221 ( int V_112 , struct V_113 * V_113 ,
const char T_1 * const T_1 * V_75 ,
const char T_1 * const T_1 * V_271 ,
int V_115 )
{
struct V_55 V_56 = { . V_61 . V_58 = V_75 } ;
struct V_55 V_254 = { . V_61 . V_58 = V_271 } ;
return F_207 ( V_112 , V_113 , V_56 , V_254 , V_115 ) ;
}
static int F_222 ( struct V_113 * V_113 ,
const T_2 T_1 * V_75 ,
const T_2 T_1 * V_271 )
{
struct V_55 V_56 = {
. V_59 = true ,
. V_61 . V_60 = V_75 ,
} ;
struct V_55 V_254 = {
. V_59 = true ,
. V_61 . V_60 = V_271 ,
} ;
return F_207 ( V_140 , V_113 , V_56 , V_254 , 0 ) ;
}
static int F_223 ( int V_112 , struct V_113 * V_113 ,
const T_2 T_1 * V_75 ,
const T_2 T_1 * V_271 ,
int V_115 )
{
struct V_55 V_56 = {
. V_59 = true ,
. V_61 . V_60 = V_75 ,
} ;
struct V_55 V_254 = {
. V_59 = true ,
. V_61 . V_60 = V_271 ,
} ;
return F_207 ( V_112 , V_113 , V_56 , V_254 , V_115 ) ;
}
void F_224 ( struct V_1 * V_272 )
{
struct V_12 * V_13 = V_14 -> V_13 ;
if ( V_13 -> V_273 )
F_11 ( V_13 -> V_273 -> V_8 ) ;
V_13 -> V_273 = V_272 ;
if ( V_272 )
F_225 ( V_272 -> V_8 ) ;
}
void F_156 ( struct V_12 * V_13 , int V_274 )
{
unsigned long V_275 , V_272 ;
if ( F_3 ( ( unsigned ) V_274 > V_276 ) )
return;
do {
V_275 = F_18 ( V_13 -> V_115 ) ;
V_272 = ( V_275 & ~ V_277 ) | V_274 ;
} while ( F_226 ( & V_13 -> V_115 , V_275 , V_272 ) != V_275 );
}
