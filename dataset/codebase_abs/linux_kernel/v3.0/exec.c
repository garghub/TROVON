int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( ! V_2 )
return - V_4 ;
F_2 ( & V_5 ) ;
V_3 ? F_3 ( & V_2 -> V_6 , & V_7 ) :
F_4 ( & V_2 -> V_6 , & V_7 ) ;
F_5 ( & V_5 ) ;
return 0 ;
}
void F_6 ( struct V_1 * V_2 )
{
F_2 ( & V_5 ) ;
F_7 ( & V_2 -> V_6 ) ;
F_5 ( & V_5 ) ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_8 ) ;
}
static void F_10 ( struct V_9 * V_10 , unsigned long V_11 )
{
struct V_12 * V_13 = V_14 -> V_13 ;
long V_15 = ( long ) ( V_11 - V_10 -> V_16 ) ;
if ( ! V_13 || ! V_15 )
return;
V_10 -> V_16 = V_11 ;
#ifdef F_11
F_12 ( V_13 , V_17 , V_15 ) ;
#else
F_13 ( & V_13 -> V_18 ) ;
F_12 ( V_13 , V_17 , V_15 ) ;
F_14 ( & V_13 -> V_18 ) ;
#endif
}
static struct V_19 * F_15 ( struct V_9 * V_10 , unsigned long V_20 ,
int V_21 )
{
struct V_19 * V_19 ;
int V_22 ;
#ifdef F_16
if ( V_21 ) {
V_22 = F_17 ( V_10 -> V_23 , V_20 ) ;
if ( V_22 < 0 )
return NULL ;
}
#endif
V_22 = F_18 ( V_14 , V_10 -> V_13 , V_20 ,
1 , V_21 , 1 , & V_19 , NULL ) ;
if ( V_22 <= 0 )
return NULL ;
if ( V_21 ) {
unsigned long V_24 = V_10 -> V_23 -> V_25 - V_10 -> V_23 -> V_26 ;
struct V_27 * V_28 ;
F_10 ( V_10 , V_24 / V_29 ) ;
if ( V_24 <= V_30 )
return V_19 ;
V_28 = V_14 -> signal -> V_28 ;
if ( V_24 > F_19 ( V_28 [ V_31 ] . V_32 ) / 4 ) {
F_20 ( V_19 ) ;
return NULL ;
}
}
return V_19 ;
}
static void F_21 ( struct V_19 * V_19 )
{
F_20 ( V_19 ) ;
}
static void F_22 ( struct V_9 * V_10 , int V_33 )
{
}
static void F_23 ( struct V_9 * V_10 )
{
}
static void F_24 ( struct V_9 * V_10 , unsigned long V_20 ,
struct V_19 * V_19 )
{
F_25 ( V_10 -> V_23 , V_20 , F_26 ( V_19 ) ) ;
}
static int F_27 ( struct V_9 * V_10 )
{
int V_34 ;
struct V_35 * V_23 = NULL ;
struct V_12 * V_13 = V_10 -> V_13 ;
V_10 -> V_23 = V_23 = F_28 ( V_36 , V_37 ) ;
if ( ! V_23 )
return - V_38 ;
F_29 ( & V_13 -> V_39 ) ;
V_23 -> V_40 = V_13 ;
F_30 ( V_41 & V_42 ) ;
V_23 -> V_25 = V_43 ;
V_23 -> V_26 = V_23 -> V_25 - V_29 ;
V_23 -> V_44 = V_41 | V_42 ;
V_23 -> V_45 = F_31 ( V_23 -> V_44 ) ;
F_32 ( & V_23 -> V_46 ) ;
V_34 = F_33 ( NULL , 0 , 0 , 0 , V_23 -> V_26 , 1 ) ;
if ( V_34 )
goto V_34;
V_34 = F_34 ( V_13 , V_23 ) ;
if ( V_34 )
goto V_34;
V_13 -> V_47 = V_13 -> V_48 = 1 ;
F_35 ( & V_13 -> V_39 ) ;
V_10 -> V_49 = V_23 -> V_25 - sizeof( void * ) ;
return 0 ;
V_34:
F_35 ( & V_13 -> V_39 ) ;
V_10 -> V_23 = NULL ;
F_36 ( V_36 , V_23 ) ;
return V_34 ;
}
static bool F_37 ( struct V_9 * V_10 , long V_50 )
{
return V_50 <= V_51 ;
}
static inline void F_10 ( struct V_9 * V_10 , unsigned long V_11 )
{
}
static struct V_19 * F_15 ( struct V_9 * V_10 , unsigned long V_20 ,
int V_21 )
{
struct V_19 * V_19 ;
V_19 = V_10 -> V_19 [ V_20 / V_29 ] ;
if ( ! V_19 && V_21 ) {
V_19 = F_38 ( V_52 | V_53 ) ;
if ( ! V_19 )
return NULL ;
V_10 -> V_19 [ V_20 / V_29 ] = V_19 ;
}
return V_19 ;
}
static void F_21 ( struct V_19 * V_19 )
{
}
static void F_22 ( struct V_9 * V_10 , int V_33 )
{
if ( V_10 -> V_19 [ V_33 ] ) {
F_39 ( V_10 -> V_19 [ V_33 ] ) ;
V_10 -> V_19 [ V_33 ] = NULL ;
}
}
static void F_23 ( struct V_9 * V_10 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < V_54 ; V_33 ++ )
F_22 ( V_10 , V_33 ) ;
}
static void F_24 ( struct V_9 * V_10 , unsigned long V_20 ,
struct V_19 * V_19 )
{
}
static int F_27 ( struct V_9 * V_10 )
{
V_10 -> V_49 = V_29 * V_54 - sizeof( void * ) ;
return 0 ;
}
static bool F_37 ( struct V_9 * V_10 , long V_50 )
{
return V_50 <= V_10 -> V_49 ;
}
int F_40 ( struct V_9 * V_10 )
{
int V_34 ;
struct V_12 * V_13 = NULL ;
V_10 -> V_13 = V_13 = F_41 () ;
V_34 = - V_38 ;
if ( ! V_13 )
goto V_34;
V_34 = F_42 ( V_14 , V_13 ) ;
if ( V_34 )
goto V_34;
V_34 = F_27 ( V_10 ) ;
if ( V_34 )
goto V_34;
return 0 ;
V_34:
if ( V_13 ) {
V_10 -> V_13 = NULL ;
F_43 ( V_13 ) ;
}
return V_34 ;
}
static const char T_1 * F_44 ( struct V_55 V_56 , int V_57 )
{
const char T_1 * V_58 ;
#ifdef F_45
if ( F_46 ( V_56 . V_59 ) ) {
T_2 V_60 ;
if ( F_47 ( V_60 , V_56 . V_61 . V_60 + V_57 ) )
return F_48 ( - V_62 ) ;
return F_49 ( V_60 ) ;
}
#endif
if ( F_47 ( V_58 , V_56 . V_61 . V_58 + V_57 ) )
return F_48 ( - V_62 ) ;
return V_58 ;
}
static int F_50 ( struct V_55 V_56 , int V_63 )
{
int V_33 = 0 ;
if ( V_56 . V_61 . V_58 != NULL ) {
for (; ; ) {
const char T_1 * V_49 = F_44 ( V_56 , V_33 ) ;
if ( ! V_49 )
break;
if ( F_51 ( V_49 ) )
return - V_62 ;
if ( V_33 ++ >= V_63 )
return - V_64 ;
if ( F_52 ( V_14 ) )
return - V_65 ;
F_53 () ;
}
}
return V_33 ;
}
static int F_54 ( int V_66 , struct V_55 V_56 ,
struct V_9 * V_10 )
{
struct V_19 * V_67 = NULL ;
char * V_68 = NULL ;
unsigned long V_69 = 0 ;
int V_22 ;
while ( V_66 -- > 0 ) {
const char T_1 * V_70 ;
int V_50 ;
unsigned long V_20 ;
V_22 = - V_62 ;
V_70 = F_44 ( V_56 , V_66 ) ;
if ( F_51 ( V_70 ) )
goto V_71;
V_50 = F_55 ( V_70 , V_51 ) ;
if ( ! V_50 )
goto V_71;
V_22 = - V_64 ;
if ( ! F_37 ( V_10 , V_50 ) )
goto V_71;
V_20 = V_10 -> V_49 ;
V_70 += V_50 ;
V_10 -> V_49 -= V_50 ;
while ( V_50 > 0 ) {
int V_72 , V_73 ;
if ( F_52 ( V_14 ) ) {
V_22 = - V_65 ;
goto V_71;
}
F_53 () ;
V_72 = V_20 % V_29 ;
if ( V_72 == 0 )
V_72 = V_29 ;
V_73 = V_72 ;
if ( V_73 > V_50 )
V_73 = V_50 ;
V_72 -= V_73 ;
V_20 -= V_73 ;
V_70 -= V_73 ;
V_50 -= V_73 ;
if ( ! V_67 || V_69 != ( V_20 & V_74 ) ) {
struct V_19 * V_19 ;
V_19 = F_15 ( V_10 , V_20 , 1 ) ;
if ( ! V_19 ) {
V_22 = - V_64 ;
goto V_71;
}
if ( V_67 ) {
F_56 ( V_67 ) ;
F_57 ( V_67 ) ;
F_21 ( V_67 ) ;
}
V_67 = V_19 ;
V_68 = F_58 ( V_67 ) ;
V_69 = V_20 & V_74 ;
F_24 ( V_10 , V_69 , V_67 ) ;
}
if ( F_59 ( V_68 + V_72 , V_70 , V_73 ) ) {
V_22 = - V_62 ;
goto V_71;
}
}
}
V_22 = 0 ;
V_71:
if ( V_67 ) {
F_56 ( V_67 ) ;
F_57 ( V_67 ) ;
F_21 ( V_67 ) ;
}
return V_22 ;
}
int F_60 ( int V_66 , const char * const * V_75 ,
struct V_9 * V_10 )
{
int V_76 ;
T_3 V_77 = F_61 () ;
struct V_55 V_56 = {
. V_61 . V_58 = ( const char T_1 * const T_1 * ) V_75 ,
} ;
F_62 ( V_78 ) ;
V_76 = F_54 ( V_66 , V_56 , V_10 ) ;
F_62 ( V_77 ) ;
return V_76 ;
}
static int F_63 ( struct V_35 * V_23 , unsigned long V_79 )
{
struct V_12 * V_13 = V_23 -> V_40 ;
unsigned long V_80 = V_23 -> V_26 ;
unsigned long V_81 = V_23 -> V_25 ;
unsigned long V_82 = V_81 - V_80 ;
unsigned long V_83 = V_80 - V_79 ;
unsigned long V_84 = V_81 - V_79 ;
struct V_85 V_86 ;
F_30 ( V_83 > V_84 ) ;
if ( V_23 != F_64 ( V_13 , V_83 ) )
return - V_62 ;
if ( F_65 ( V_23 , V_83 , V_81 , V_23 -> V_87 , NULL ) )
return - V_38 ;
if ( V_82 != F_66 ( V_23 , V_80 ,
V_23 , V_83 , V_82 ) )
return - V_38 ;
F_67 () ;
F_68 ( & V_86 , V_13 , 0 ) ;
if ( V_84 > V_80 ) {
F_69 ( & V_86 , V_84 , V_81 , V_84 ,
V_23 -> V_88 ? V_23 -> V_88 -> V_26 : 0 ) ;
} else {
F_69 ( & V_86 , V_80 , V_81 , V_84 ,
V_23 -> V_88 ? V_23 -> V_88 -> V_26 : 0 ) ;
}
F_70 ( & V_86 , V_84 , V_81 ) ;
F_65 ( V_23 , V_83 , V_84 , V_23 -> V_87 , NULL ) ;
return 0 ;
}
int F_71 ( struct V_9 * V_10 ,
unsigned long V_89 ,
int V_90 )
{
unsigned long V_22 ;
unsigned long V_91 ;
struct V_12 * V_13 = V_14 -> V_13 ;
struct V_35 * V_23 = V_10 -> V_23 ;
struct V_35 * V_92 = NULL ;
unsigned long V_44 ;
unsigned long V_93 ;
unsigned long V_94 ;
unsigned long V_95 ;
unsigned long V_96 ;
#ifdef F_16
V_93 = F_72 ( V_31 ) ;
if ( V_93 > ( 1 << 30 ) )
V_93 = 1 << 30 ;
if ( V_23 -> V_25 - V_23 -> V_26 > V_93 )
return - V_38 ;
V_93 = F_73 ( V_89 - V_93 ) ;
V_91 = V_23 -> V_26 - V_93 ;
V_13 -> V_97 = V_10 -> V_49 - V_91 ;
V_10 -> V_49 = V_23 -> V_25 - V_91 ;
#else
V_89 = F_74 ( V_89 ) ;
V_89 = F_73 ( V_89 ) ;
if ( F_46 ( V_89 < V_98 ) ||
F_46 ( V_23 -> V_25 - V_23 -> V_26 >= V_89 - V_98 ) )
return - V_38 ;
V_91 = V_23 -> V_25 - V_89 ;
V_10 -> V_49 -= V_91 ;
V_13 -> V_97 = V_10 -> V_49 ;
#endif
if ( V_10 -> V_99 )
V_10 -> V_99 -= V_91 ;
V_10 -> V_100 -= V_91 ;
F_29 ( & V_13 -> V_39 ) ;
V_44 = V_41 ;
if ( F_46 ( V_90 == V_101 ) )
V_44 |= V_102 ;
else if ( V_90 == V_103 )
V_44 &= ~ V_102 ;
V_44 |= V_13 -> V_104 ;
V_44 |= V_42 ;
V_22 = F_75 ( V_23 , & V_92 , V_23 -> V_26 , V_23 -> V_25 ,
V_44 ) ;
if ( V_22 )
goto V_105;
F_30 ( V_92 != V_23 ) ;
if ( V_91 ) {
V_22 = F_63 ( V_23 , V_91 ) ;
if ( V_22 )
goto V_105;
}
V_23 -> V_44 &= ~ V_42 ;
V_95 = 131072UL ;
V_94 = V_23 -> V_25 - V_23 -> V_26 ;
V_96 = V_27 ( V_31 ) & V_74 ;
#ifdef F_16
if ( V_94 + V_95 > V_96 )
V_93 = V_23 -> V_26 + V_96 ;
else
V_93 = V_23 -> V_25 + V_95 ;
#else
if ( V_94 + V_95 > V_96 )
V_93 = V_23 -> V_25 - V_96 ;
else
V_93 = V_23 -> V_26 - V_95 ;
#endif
V_14 -> V_13 -> V_106 = V_10 -> V_49 ;
V_22 = F_76 ( V_23 , V_93 ) ;
if ( V_22 )
V_22 = - V_62 ;
V_105:
F_35 ( & V_13 -> V_39 ) ;
return V_22 ;
}
struct V_107 * F_77 ( const char * V_108 )
{
struct V_107 * V_107 ;
int V_34 ;
static const struct V_109 V_110 = {
. V_111 = V_112 | V_113 | V_114 ,
. V_115 = V_116 | V_117 ,
. V_118 = V_119
} ;
V_107 = F_78 ( V_120 , V_108 , & V_110 , V_121 ) ;
if ( F_51 ( V_107 ) )
goto V_71;
V_34 = - V_122 ;
if ( ! F_79 ( V_107 -> V_123 . V_124 -> V_125 -> V_126 ) )
goto exit;
if ( V_107 -> V_123 . V_127 -> V_128 & V_129 )
goto exit;
F_80 ( V_107 ) ;
V_34 = F_81 ( V_107 ) ;
if ( V_34 )
goto exit;
V_71:
return V_107 ;
exit:
F_82 ( V_107 ) ;
return F_48 ( V_34 ) ;
}
int F_83 ( struct V_107 * V_107 , T_4 V_72 ,
char * V_130 , unsigned long F_50 )
{
T_3 V_131 ;
T_4 V_20 = V_72 ;
int V_132 ;
V_131 = F_61 () ;
F_62 ( F_84 () ) ;
V_132 = F_85 ( V_107 , ( void T_1 * ) V_130 , F_50 , & V_20 ) ;
F_62 ( V_131 ) ;
return V_132 ;
}
static int F_86 ( struct V_12 * V_13 )
{
struct V_133 * V_134 ;
struct V_12 * V_135 , * V_136 ;
V_134 = V_14 ;
V_135 = V_14 -> V_13 ;
F_87 ( V_134 , V_135 ) ;
F_88 ( V_134 , V_135 ) ;
if ( V_135 ) {
F_89 ( & V_135 -> V_39 ) ;
if ( F_46 ( V_135 -> V_137 ) ) {
F_90 ( & V_135 -> V_39 ) ;
return - V_138 ;
}
}
F_91 ( V_134 ) ;
V_136 = V_134 -> V_136 ;
V_134 -> V_13 = V_13 ;
V_134 -> V_136 = V_13 ;
F_92 ( V_136 , V_13 ) ;
if ( V_135 && V_134 -> signal -> V_139 == V_140 ) {
F_93 ( & V_135 -> V_141 ) ;
F_94 ( & V_134 -> V_13 -> V_141 ) ;
}
F_95 ( V_134 ) ;
F_96 ( V_13 ) ;
if ( V_135 ) {
F_90 ( & V_135 -> V_39 ) ;
F_30 ( V_136 != V_135 ) ;
F_97 ( V_135 ) ;
F_98 ( V_135 ) ;
return 0 ;
}
F_43 ( V_136 ) ;
return 0 ;
}
static int F_99 ( struct V_133 * V_134 )
{
struct V_142 * V_143 = V_134 -> signal ;
struct V_144 * V_145 = V_134 -> V_146 ;
T_5 * V_147 = & V_145 -> V_148 ;
if ( F_100 ( V_134 ) )
goto V_149;
F_101 ( V_147 ) ;
if ( F_102 ( V_143 ) ) {
F_103 ( V_147 ) ;
return - V_150 ;
}
V_143 -> V_151 = V_134 ;
V_143 -> V_152 = F_104 ( V_134 ) ;
if ( ! F_105 ( V_134 ) )
V_143 -> V_152 -- ;
while ( V_143 -> V_152 ) {
F_106 ( V_153 ) ;
F_103 ( V_147 ) ;
F_107 () ;
F_101 ( V_147 ) ;
}
F_103 ( V_147 ) ;
if ( ! F_105 ( V_134 ) ) {
struct V_133 * V_154 = V_134 -> V_155 ;
V_143 -> V_152 = - 1 ;
for (; ; ) {
F_108 ( & V_156 ) ;
if ( F_109 ( V_154 -> V_157 ) )
break;
F_106 ( V_153 ) ;
F_110 ( & V_156 ) ;
F_107 () ;
}
V_134 -> V_158 = V_154 -> V_158 ;
F_30 ( ! F_111 ( V_154 , V_134 ) ) ;
F_30 ( F_112 ( V_134 ) ) ;
F_113 ( V_134 , V_159 ) ;
V_134 -> V_160 = V_154 -> V_160 ;
F_114 ( V_134 , V_159 , F_115 ( V_154 ) ) ;
F_116 ( V_154 , V_134 , V_161 ) ;
F_116 ( V_154 , V_134 , V_162 ) ;
F_117 ( & V_154 -> V_163 , & V_134 -> V_163 ) ;
F_118 ( & V_154 -> V_164 , & V_134 -> V_164 ) ;
V_134 -> V_155 = V_134 ;
V_154 -> V_155 = V_134 ;
V_134 -> V_165 = V_166 ;
F_30 ( V_154 -> V_157 != V_167 ) ;
V_154 -> V_157 = V_168 ;
F_110 ( & V_156 ) ;
F_119 ( V_154 ) ;
}
V_143 -> V_151 = NULL ;
V_143 -> V_152 = 0 ;
V_149:
if ( V_14 -> V_13 )
F_120 ( & V_143 -> V_169 , V_14 -> V_13 ) ;
F_121 ( V_143 ) ;
F_122 () ;
if ( F_123 ( & V_145 -> F_50 ) != 1 ) {
struct V_144 * V_170 ;
V_170 = F_124 ( V_171 , V_37 ) ;
if ( ! V_170 )
return - V_38 ;
F_125 ( & V_170 -> F_50 , 1 ) ;
memcpy ( V_170 -> V_172 , V_145 -> V_172 ,
sizeof( V_170 -> V_172 ) ) ;
F_108 ( & V_156 ) ;
F_13 ( & V_145 -> V_148 ) ;
F_126 ( V_134 -> V_146 , V_170 ) ;
F_14 ( & V_145 -> V_148 ) ;
F_110 ( & V_156 ) ;
F_127 ( V_145 ) ;
}
F_30 ( ! F_105 ( V_134 ) ) ;
return 0 ;
}
static void F_128 ( struct V_173 * V_174 )
{
long V_175 = - 1 ;
struct V_176 * V_177 ;
F_13 ( & V_174 -> V_178 ) ;
for (; ; ) {
unsigned long V_179 , V_33 ;
V_175 ++ ;
V_33 = V_175 * V_180 ;
V_177 = F_129 ( V_174 ) ;
if ( V_33 >= V_177 -> V_181 )
break;
V_179 = V_177 -> V_182 -> V_183 [ V_175 ] ;
if ( ! V_179 )
continue;
V_177 -> V_182 -> V_183 [ V_175 ] = 0 ;
F_14 ( & V_174 -> V_178 ) ;
for ( ; V_179 ; V_33 ++ , V_179 >>= 1 ) {
if ( V_179 & 1 ) {
F_130 ( V_33 ) ;
}
}
F_13 ( & V_174 -> V_178 ) ;
}
F_14 ( & V_174 -> V_178 ) ;
}
char * F_131 ( char * V_184 , struct V_133 * V_134 )
{
F_91 ( V_134 ) ;
strncpy ( V_184 , V_134 -> V_185 , sizeof( V_134 -> V_185 ) ) ;
F_95 ( V_134 ) ;
return V_184 ;
}
void F_132 ( struct V_133 * V_134 , char * V_184 )
{
F_91 ( V_134 ) ;
memset ( V_134 -> V_185 , 0 , V_186 ) ;
F_133 () ;
F_134 ( V_134 -> V_185 , V_184 , sizeof( V_134 -> V_185 ) ) ;
F_95 ( V_134 ) ;
F_135 ( V_134 ) ;
}
int F_136 ( struct V_9 * V_10 )
{
int V_187 ;
V_187 = F_99 ( V_14 ) ;
if ( V_187 )
goto V_71;
F_137 ( V_10 -> V_13 , V_10 -> V_107 ) ;
F_10 ( V_10 , 0 ) ;
V_187 = F_86 ( V_10 -> V_13 ) ;
if ( V_187 )
goto V_71;
V_10 -> V_13 = NULL ;
F_62 ( V_188 ) ;
V_14 -> V_189 &= ~ ( V_190 | V_191 ) ;
F_138 () ;
V_14 -> V_192 &= ~ V_10 -> V_193 ;
return 0 ;
V_71:
return V_187 ;
}
void F_139 ( struct V_9 * V_10 )
{
int V_33 , V_194 ;
const char * V_108 ;
char V_195 [ sizeof( V_14 -> V_185 ) ] ;
F_96 ( V_14 -> V_13 ) ;
V_14 -> V_196 = V_14 -> V_197 = 0 ;
if ( F_140 () == F_141 () && F_142 () == F_143 () )
F_144 ( V_14 -> V_13 , 1 ) ;
else
F_144 ( V_14 -> V_13 , V_198 ) ;
V_108 = V_10 -> V_199 ;
for ( V_33 = 0 ; ( V_194 = * ( V_108 ++ ) ) != '\0' ; ) {
if ( V_194 == '/' )
V_33 = 0 ;
else
if ( V_33 < ( sizeof( V_195 ) - 1 ) )
V_195 [ V_33 ++ ] = V_194 ;
}
V_195 [ V_33 ] = '\0' ;
F_132 ( V_14 , V_195 ) ;
V_14 -> V_13 -> V_200 = V_201 ;
if ( V_10 -> V_202 -> V_203 != F_140 () ||
V_10 -> V_202 -> V_204 != F_142 () ) {
V_14 -> V_205 = 0 ;
} else if ( F_145 ( V_10 -> V_107 , V_206 ) ||
V_10 -> V_207 & V_208 ) {
F_144 ( V_14 -> V_13 , V_198 ) ;
}
if ( ! F_146 ( V_14 -> V_13 ) )
F_147 ( V_14 ) ;
V_14 -> V_209 ++ ;
F_148 ( V_14 , 0 ) ;
F_128 ( V_14 -> V_174 ) ;
}
int F_149 ( struct V_9 * V_10 )
{
if ( F_150 ( & V_14 -> signal -> V_210 ) )
return - V_211 ;
V_10 -> V_202 = F_151 () ;
if ( F_109 ( V_10 -> V_202 ) )
return 0 ;
F_152 ( & V_14 -> signal -> V_210 ) ;
return - V_38 ;
}
void F_153 ( struct V_9 * V_10 )
{
F_23 ( V_10 ) ;
if ( V_10 -> V_202 ) {
F_152 ( & V_14 -> signal -> V_210 ) ;
F_154 ( V_10 -> V_202 ) ;
}
F_155 ( V_10 ) ;
}
void F_156 ( struct V_9 * V_10 )
{
F_157 ( V_10 ) ;
F_158 ( V_10 -> V_202 ) ;
V_10 -> V_202 = NULL ;
F_159 ( V_10 ) ;
F_152 ( & V_14 -> signal -> V_210 ) ;
}
int F_160 ( struct V_9 * V_10 )
{
struct V_133 * V_49 = V_14 , * V_212 ;
unsigned V_213 ;
int V_214 = 0 ;
V_10 -> V_215 = F_161 ( V_49 ) ;
V_213 = 1 ;
F_13 ( & V_49 -> V_216 -> V_147 ) ;
F_162 () ;
for ( V_212 = F_163 ( V_49 ) ; V_212 != V_49 ; V_212 = F_163 ( V_212 ) ) {
if ( V_212 -> V_216 == V_49 -> V_216 )
V_213 ++ ;
}
F_164 () ;
if ( V_49 -> V_216 -> V_217 > V_213 ) {
V_10 -> V_215 |= V_218 ;
} else {
V_214 = - V_150 ;
if ( ! V_49 -> V_216 -> V_219 ) {
V_49 -> V_216 -> V_219 = 1 ;
V_214 = 1 ;
}
}
F_14 ( & V_49 -> V_216 -> V_147 ) ;
return V_214 ;
}
int F_165 ( struct V_9 * V_10 )
{
T_6 V_220 ;
struct V_221 * V_221 = V_10 -> V_107 -> V_123 . V_124 -> V_125 ;
int V_187 ;
V_220 = V_221 -> V_126 ;
if ( V_10 -> V_107 -> V_222 == NULL )
return - V_122 ;
V_10 -> V_202 -> V_223 = F_140 () ;
V_10 -> V_202 -> V_224 = F_142 () ;
if ( ! ( V_10 -> V_107 -> V_123 . V_127 -> V_128 & V_225 ) ) {
if ( V_220 & V_226 ) {
V_10 -> V_193 |= V_227 ;
V_10 -> V_202 -> V_223 = V_221 -> V_228 ;
}
if ( ( V_220 & ( V_229 | V_230 ) ) == ( V_229 | V_230 ) ) {
V_10 -> V_193 |= V_227 ;
V_10 -> V_202 -> V_224 = V_221 -> V_231 ;
}
}
V_187 = F_166 ( V_10 ) ;
if ( V_187 )
return V_187 ;
V_10 -> V_232 = 1 ;
memset ( V_10 -> V_184 , 0 , V_233 ) ;
return F_83 ( V_10 -> V_107 , 0 , V_10 -> V_184 , V_233 ) ;
}
int F_167 ( struct V_9 * V_10 )
{
int V_22 = 0 ;
unsigned long V_72 ;
char * V_68 ;
struct V_19 * V_19 ;
if ( ! V_10 -> V_66 )
return 0 ;
do {
V_72 = V_10 -> V_49 & ~ V_74 ;
V_19 = F_15 ( V_10 , V_10 -> V_49 , 0 ) ;
if ( ! V_19 ) {
V_22 = - V_62 ;
goto V_71;
}
V_68 = F_168 ( V_19 , V_234 ) ;
for (; V_72 < V_29 && V_68 [ V_72 ] ;
V_72 ++ , V_10 -> V_49 ++ )
;
F_169 ( V_68 , V_234 ) ;
F_21 ( V_19 ) ;
if ( V_72 == V_29 )
F_22 ( V_10 , ( V_10 -> V_49 >> V_235 ) - 1 ) ;
} while ( V_72 == V_29 );
V_10 -> V_49 ++ ;
V_10 -> V_66 -- ;
V_22 = 0 ;
V_71:
return V_22 ;
}
int F_170 ( struct V_9 * V_10 , struct V_236 * V_237 )
{
unsigned int V_238 = V_10 -> V_239 ;
int V_240 , V_187 ;
struct V_1 * V_2 ;
V_187 = F_171 ( V_10 ) ;
if ( V_187 )
return V_187 ;
V_187 = F_172 ( V_10 ) ;
if ( V_187 )
return V_187 ;
V_187 = - V_241 ;
for ( V_240 = 0 ; V_240 < 2 ; V_240 ++ ) {
F_173 ( & V_5 ) ;
F_174 (fmt, &formats, lh) {
int (* F_175)( struct V_9 * , struct V_236 * ) = V_2 -> V_242 ;
if ( ! F_175 )
continue;
if ( ! F_176 ( V_2 -> V_8 ) )
continue;
F_177 ( & V_5 ) ;
V_187 = F_175 ( V_10 , V_237 ) ;
V_10 -> V_239 = V_238 ;
if ( V_187 >= 0 ) {
if ( V_238 == 0 )
F_178 ( V_2 , V_10 , V_237 ) ;
F_8 ( V_2 ) ;
F_179 ( V_10 -> V_107 ) ;
if ( V_10 -> V_107 )
F_82 ( V_10 -> V_107 ) ;
V_10 -> V_107 = NULL ;
V_14 -> V_243 = 1 ;
F_180 ( V_14 ) ;
return V_187 ;
}
F_173 ( & V_5 ) ;
F_8 ( V_2 ) ;
if ( V_187 != - V_244 || V_10 -> V_13 == NULL )
break;
if ( ! V_10 -> V_107 ) {
F_177 ( & V_5 ) ;
return V_187 ;
}
}
F_177 ( & V_5 ) ;
if ( V_187 != - V_244 || V_10 -> V_13 == NULL ) {
break;
#ifdef F_181
} else {
#define F_182 ( T_7 ) (((c)=='\t') || ((c)=='\n') || (0x20<=(c) && (c)<=0x7e))
if ( F_182 ( V_10 -> V_184 [ 0 ] ) &&
F_182 ( V_10 -> V_184 [ 1 ] ) &&
F_182 ( V_10 -> V_184 [ 2 ] ) &&
F_182 ( V_10 -> V_184 [ 3 ] ) )
break;
F_183 ( L_1 , * ( unsigned short * ) ( & V_10 -> V_184 [ 2 ] ) ) ;
#endif
}
}
return V_187 ;
}
static int F_184 ( const char * V_199 ,
struct V_55 V_56 ,
struct V_55 V_245 ,
struct V_236 * V_237 )
{
struct V_9 * V_10 ;
struct V_107 * V_107 ;
struct V_173 * V_246 ;
bool V_247 ;
int V_187 ;
V_187 = F_185 ( & V_246 ) ;
if ( V_187 )
goto V_248;
V_187 = - V_38 ;
V_10 = F_186 ( sizeof( * V_10 ) , V_37 ) ;
if ( ! V_10 )
goto V_249;
V_187 = F_149 ( V_10 ) ;
if ( V_187 )
goto V_250;
V_187 = F_160 ( V_10 ) ;
if ( V_187 < 0 )
goto V_250;
V_247 = V_187 ;
V_14 -> V_251 = 1 ;
V_107 = F_77 ( V_199 ) ;
V_187 = F_187 ( V_107 ) ;
if ( F_51 ( V_107 ) )
goto V_252;
F_188 () ;
V_10 -> V_107 = V_107 ;
V_10 -> V_199 = V_199 ;
V_10 -> V_253 = V_199 ;
V_187 = F_40 ( V_10 ) ;
if ( V_187 )
goto V_254;
V_10 -> V_66 = F_50 ( V_56 , V_255 ) ;
if ( ( V_187 = V_10 -> V_66 ) < 0 )
goto V_71;
V_10 -> V_256 = F_50 ( V_245 , V_255 ) ;
if ( ( V_187 = V_10 -> V_256 ) < 0 )
goto V_71;
V_187 = F_165 ( V_10 ) ;
if ( V_187 < 0 )
goto V_71;
V_187 = F_60 ( 1 , & V_10 -> V_199 , V_10 ) ;
if ( V_187 < 0 )
goto V_71;
V_10 -> V_100 = V_10 -> V_49 ;
V_187 = F_54 ( V_10 -> V_256 , V_245 , V_10 ) ;
if ( V_187 < 0 )
goto V_71;
V_187 = F_54 ( V_10 -> V_66 , V_56 , V_10 ) ;
if ( V_187 < 0 )
goto V_71;
V_187 = F_170 ( V_10 , V_237 ) ;
if ( V_187 < 0 )
goto V_71;
V_14 -> V_216 -> V_219 = 0 ;
V_14 -> V_251 = 0 ;
F_189 ( V_14 ) ;
F_153 ( V_10 ) ;
if ( V_246 )
F_190 ( V_246 ) ;
return V_187 ;
V_71:
if ( V_10 -> V_13 ) {
F_10 ( V_10 , 0 ) ;
F_98 ( V_10 -> V_13 ) ;
}
V_254:
if ( V_10 -> V_107 ) {
F_179 ( V_10 -> V_107 ) ;
F_82 ( V_10 -> V_107 ) ;
}
V_252:
if ( V_247 )
V_14 -> V_216 -> V_219 = 0 ;
V_14 -> V_251 = 0 ;
V_250:
F_153 ( V_10 ) ;
V_249:
if ( V_246 )
F_191 ( V_246 ) ;
V_248:
return V_187 ;
}
int F_192 ( const char * V_199 ,
const char T_1 * const T_1 * V_75 ,
const char T_1 * const T_1 * V_257 ,
struct V_236 * V_237 )
{
struct V_55 V_56 = { . V_61 . V_58 = V_75 } ;
struct V_55 V_245 = { . V_61 . V_58 = V_257 } ;
return F_184 ( V_199 , V_56 , V_245 , V_237 ) ;
}
int F_193 ( char * V_199 ,
T_2 T_1 * V_75 ,
T_2 T_1 * V_257 ,
struct V_236 * V_237 )
{
struct V_55 V_56 = {
. V_59 = true ,
. V_61 . V_60 = V_75 ,
} ;
struct V_55 V_245 = {
. V_59 = true ,
. V_61 . V_60 = V_257 ,
} ;
return F_184 ( V_199 , V_56 , V_245 , V_237 ) ;
}
void F_194 ( struct V_1 * V_258 )
{
struct V_12 * V_13 = V_14 -> V_13 ;
if ( V_13 -> V_259 )
F_9 ( V_13 -> V_259 -> V_8 ) ;
V_13 -> V_259 = V_258 ;
if ( V_258 )
F_195 ( V_258 -> V_8 ) ;
}
static int F_196 ( struct V_260 * V_261 )
{
char * V_262 = V_261 -> V_263 ;
V_261 -> V_24 = V_264 * F_197 ( & V_265 ) ;
V_261 -> V_263 = F_198 ( V_262 , V_261 -> V_24 , V_37 ) ;
if ( ! V_261 -> V_263 ) {
F_155 ( V_262 ) ;
return - V_38 ;
}
return 0 ;
}
static int F_199 ( struct V_260 * V_261 , const char * V_2 , ... )
{
char * V_266 ;
int V_267 ;
int V_22 ;
T_8 V_268 ;
va_start ( V_268 , V_2 ) ;
V_267 = vsnprintf ( NULL , 0 , V_2 , V_268 ) ;
va_end ( V_268 ) ;
if ( F_109 ( V_267 < V_261 -> V_24 - V_261 -> V_269 - 1 ) )
goto V_270;
V_22 = F_196 ( V_261 ) ;
if ( V_22 )
goto V_271;
V_270:
V_266 = V_261 -> V_263 + V_261 -> V_269 ;
va_start ( V_268 , V_2 ) ;
vsnprintf ( V_266 , V_267 + 1 , V_2 , V_268 ) ;
va_end ( V_268 ) ;
V_261 -> V_269 += V_267 ;
return 0 ;
V_271:
return V_22 ;
}
static int F_200 ( struct V_260 * V_261 )
{
struct V_107 * V_272 ;
char * V_273 , * V_274 , * V_49 ;
int V_22 ;
V_272 = F_201 ( V_14 -> V_13 ) ;
if ( ! V_272 )
return F_199 ( V_261 , L_2 ) ;
V_273 = F_202 ( V_275 , V_276 ) ;
if ( ! V_273 ) {
V_22 = - V_38 ;
goto V_277;
}
V_274 = F_203 ( & V_272 -> V_123 , V_273 , V_275 ) ;
if ( F_51 ( V_274 ) ) {
V_22 = F_187 ( V_274 ) ;
goto V_278;
}
for ( V_49 = V_274 ; * V_49 ; V_49 ++ )
if ( * V_49 == '/' )
* V_49 = '!' ;
V_22 = F_199 ( V_261 , L_3 , V_274 ) ;
V_278:
F_155 ( V_273 ) ;
V_277:
F_82 ( V_272 ) ;
return V_22 ;
}
static int F_204 ( struct V_260 * V_261 , long V_279 )
{
const struct V_202 * V_202 = F_205 () ;
const char * V_280 = V_281 ;
int V_282 = ( * V_280 == '|' ) ;
int V_283 = 0 ;
int V_34 = 0 ;
V_261 -> V_24 = V_264 * F_123 ( & V_265 ) ;
V_261 -> V_263 = F_202 ( V_261 -> V_24 , V_37 ) ;
V_261 -> V_269 = 0 ;
if ( ! V_261 -> V_263 )
return - V_38 ;
while ( * V_280 ) {
if ( * V_280 != '%' ) {
if ( * V_280 == 0 )
goto V_71;
V_34 = F_199 ( V_261 , L_4 , * V_280 ++ ) ;
} else {
switch ( * ++ V_280 ) {
case 0 :
goto V_71;
case '%' :
V_34 = F_199 ( V_261 , L_4 , '%' ) ;
break;
case 'p' :
V_283 = 1 ;
V_34 = F_199 ( V_261 , L_5 ,
F_206 ( V_14 ) ) ;
break;
case 'u' :
V_34 = F_199 ( V_261 , L_5 , V_202 -> V_203 ) ;
break;
case 'g' :
V_34 = F_199 ( V_261 , L_5 , V_202 -> V_204 ) ;
break;
case 's' :
V_34 = F_199 ( V_261 , L_6 , V_279 ) ;
break;
case 't' : {
struct V_284 V_285 ;
F_207 ( & V_285 ) ;
V_34 = F_199 ( V_261 , L_7 , V_285 . V_286 ) ;
break;
}
case 'h' :
F_89 ( & V_287 ) ;
V_34 = F_199 ( V_261 , L_3 ,
F_208 () -> V_288 ) ;
F_90 ( & V_287 ) ;
break;
case 'e' :
V_34 = F_199 ( V_261 , L_3 , V_14 -> V_185 ) ;
break;
case 'E' :
V_34 = F_200 ( V_261 ) ;
break;
case 'c' :
V_34 = F_199 ( V_261 , L_7 ,
V_27 ( V_289 ) ) ;
break;
default:
break;
}
++ V_280 ;
}
if ( V_34 )
return V_34 ;
}
if ( ! V_282 && ! V_283 && V_290 ) {
V_34 = F_199 ( V_261 , L_8 , F_206 ( V_14 ) ) ;
if ( V_34 )
return V_34 ;
}
V_71:
return V_282 ;
}
static int F_209 ( struct V_133 * V_291 , int V_292 )
{
struct V_133 * V_212 ;
int V_57 = 0 ;
V_291 -> signal -> V_189 = V_293 ;
V_291 -> signal -> V_294 = V_292 ;
V_291 -> signal -> V_295 = 0 ;
V_212 = V_291 ;
do {
F_210 ( V_212 ) ;
if ( V_212 != V_14 && V_212 -> V_13 ) {
F_211 ( & V_212 -> V_296 . signal , V_297 ) ;
F_212 ( V_212 , 1 ) ;
V_57 ++ ;
}
} while_each_thread(start, t) ;
inline int F_213 ( struct V_133 * V_134 , struct V_12 * V_13 ,
struct V_137 * V_137 , int V_292 )
{
struct V_133 * V_298 , * V_49 ;
unsigned long V_189 ;
int V_57 = - V_150 ;
F_101 ( & V_134 -> V_146 -> V_148 ) ;
if ( ! F_102 ( V_134 -> signal ) ) {
V_13 -> V_137 = V_137 ;
V_57 = F_209 ( V_134 , V_292 ) ;
}
F_103 ( & V_134 -> V_146 -> V_148 ) ;
if ( F_46 ( V_57 < 0 ) )
return V_57 ;
if ( F_123 ( & V_13 -> V_299 ) == V_57 + 1 )
goto V_300;
F_162 () ;
F_214 (g) {
if ( V_298 == V_134 -> V_155 )
continue;
if ( V_298 -> V_189 & V_191 )
continue;
V_49 = V_298 ;
do {
if ( V_49 -> V_13 ) {
if ( F_46 ( V_49 -> V_13 == V_13 ) ) {
F_215 ( V_49 , & V_189 ) ;
V_57 += F_209 ( V_49 , V_292 ) ;
F_216 ( V_49 , & V_189 ) ;
}
break;
}
} while_each_thread(g, p) ;
}
int F_217 ( int V_292 , struct V_137 * V_137 )
{
struct V_133 * V_134 = V_14 ;
struct V_12 * V_13 = V_134 -> V_13 ;
struct V_301 * V_302 ;
int V_303 = - V_304 ;
F_218 ( & V_137 -> V_305 ) ;
V_137 -> V_306 . V_307 = V_134 ;
V_137 -> V_306 . V_308 = NULL ;
F_29 ( & V_13 -> V_39 ) ;
if ( ! V_13 -> V_137 )
V_303 = F_213 ( V_134 , V_13 , V_137 , V_292 ) ;
F_35 ( & V_13 -> V_39 ) ;
if ( F_46 ( V_303 < 0 ) )
goto V_309;
V_302 = V_134 -> V_302 ;
if ( V_302 ) {
V_134 -> V_302 = NULL ;
F_219 ( V_302 ) ;
}
if ( V_303 )
F_220 ( & V_137 -> V_305 ) ;
V_309:
return V_303 ;
}
static void F_221 ( struct V_12 * V_13 )
{
struct V_310 * V_311 , * V_308 ;
struct V_133 * V_307 ;
V_308 = V_13 -> V_137 -> V_306 . V_308 ;
while ( ( V_311 = V_308 ) != NULL ) {
V_308 = V_311 -> V_308 ;
V_307 = V_311 -> V_307 ;
F_222 () ;
V_311 -> V_307 = NULL ;
F_223 ( V_307 ) ;
}
V_13 -> V_137 = NULL ;
}
void F_144 ( struct V_12 * V_13 , int V_312 )
{
switch ( V_312 ) {
case 0 :
F_224 ( V_313 , & V_13 -> V_189 ) ;
F_225 () ;
F_224 ( V_314 , & V_13 -> V_189 ) ;
break;
case 1 :
F_226 ( V_313 , & V_13 -> V_189 ) ;
F_225 () ;
F_224 ( V_314 , & V_13 -> V_189 ) ;
break;
case 2 :
F_226 ( V_314 , & V_13 -> V_189 ) ;
F_225 () ;
F_226 ( V_313 , & V_13 -> V_189 ) ;
break;
}
}
static int F_227 ( unsigned long V_315 )
{
int V_22 ;
V_22 = V_315 & V_316 ;
return ( V_22 >= 2 ) ? 2 : V_22 ;
}
int F_146 ( struct V_12 * V_13 )
{
return F_227 ( V_13 -> V_189 ) ;
}
static void F_228 ( struct V_107 * V_107 )
{
struct V_317 * V_318 ;
V_318 = V_107 -> V_123 . V_124 -> V_125 -> V_319 ;
F_229 ( V_318 ) ;
V_318 -> V_320 ++ ;
V_318 -> V_321 -- ;
while ( ( V_318 -> V_320 > 1 ) && ( ! F_230 ( V_14 ) ) ) {
F_231 ( & V_318 -> V_322 ) ;
F_232 ( & V_318 -> V_323 , V_324 , V_325 ) ;
F_233 ( V_318 ) ;
}
V_318 -> V_320 -- ;
V_318 -> V_321 ++ ;
F_234 ( V_318 ) ;
}
static int F_235 ( struct V_326 * V_327 , struct V_202 * V_258 )
{
struct V_107 * V_328 , * V_329 ;
struct V_176 * V_177 ;
struct V_330 * V_331 = (struct V_330 * ) V_327 -> V_332 ;
struct V_173 * V_333 = V_14 -> V_174 ;
V_329 = F_236 ( 0 ) ;
if ( F_51 ( V_329 ) )
return F_187 ( V_329 ) ;
V_328 = F_237 ( V_329 , 0 ) ;
if ( F_51 ( V_328 ) ) {
F_238 ( V_329 ) ;
return F_187 ( V_328 ) ;
}
V_331 -> V_107 = V_329 ;
F_130 ( 0 ) ;
F_239 ( 0 , V_328 ) ;
F_13 ( & V_333 -> V_178 ) ;
V_177 = F_129 ( V_333 ) ;
F_240 ( 0 , V_177 -> V_334 ) ;
F_241 ( 0 , V_177 -> V_182 ) ;
F_14 ( & V_333 -> V_178 ) ;
V_14 -> signal -> V_28 [ V_289 ] = (struct V_27 ) { 1 , 1 } ;
return 0 ;
}
void F_242 ( long V_279 , int V_292 , struct V_236 * V_237 )
{
struct V_137 V_137 ;
struct V_260 V_261 ;
struct V_12 * V_13 = V_14 -> V_13 ;
struct V_1 * V_259 ;
const struct V_202 * V_335 ;
struct V_202 * V_202 ;
int V_187 = 0 ;
int V_336 = 0 ;
int V_282 ;
static T_9 V_337 = F_243 ( 0 ) ;
struct V_330 V_338 = {
. V_279 = V_279 ,
. V_237 = V_237 ,
. V_339 = V_27 ( V_289 ) ,
. V_315 = V_13 -> V_189 ,
} ;
F_244 ( V_279 ) ;
V_259 = V_13 -> V_259 ;
if ( ! V_259 || ! V_259 -> V_340 )
goto V_309;
if ( ! F_227 ( V_338 . V_315 ) )
goto V_309;
V_202 = F_245 () ;
if ( ! V_202 )
goto V_309;
if ( F_227 ( V_338 . V_315 ) == 2 ) {
V_336 = V_341 ;
V_202 -> V_342 = 0 ;
}
V_187 = F_217 ( V_292 , & V_137 ) ;
if ( V_187 < 0 )
goto V_343;
V_335 = F_246 ( V_202 ) ;
F_247 ( V_344 ) ;
V_282 = F_204 ( & V_261 , V_279 ) ;
if ( V_282 == - V_38 ) {
F_248 ( V_345 L_9 ) ;
F_248 ( V_345 L_10 ) ;
goto V_346;
}
if ( V_282 ) {
int V_347 ;
char * * V_348 ;
if ( V_338 . V_339 == 1 ) {
F_248 ( V_345
L_11 ,
F_206 ( V_14 ) , V_14 -> V_185 ) ;
F_248 ( V_345 L_10 ) ;
goto V_349;
}
V_338 . V_339 = V_350 ;
V_347 = F_197 ( & V_337 ) ;
if ( V_351 && ( V_351 < V_347 ) ) {
F_248 ( V_345 L_12 ,
F_206 ( V_14 ) , V_14 -> V_185 ) ;
F_248 ( V_345 L_13 ) ;
goto V_352;
}
V_348 = F_249 ( V_37 , V_261 . V_263 + 1 , NULL ) ;
if ( ! V_348 ) {
F_248 ( V_345 L_14 ,
V_353 ) ;
goto V_352;
}
V_187 = F_250 ( V_348 [ 0 ] , V_348 ,
NULL , V_354 , F_235 ,
NULL , & V_338 ) ;
F_251 ( V_348 ) ;
if ( V_187 ) {
F_248 ( V_355 L_15 ,
V_261 . V_263 ) ;
goto V_356;
}
} else {
struct V_221 * V_221 ;
if ( V_338 . V_339 < V_259 -> V_357 )
goto V_349;
V_338 . V_107 = F_252 ( V_261 . V_263 ,
V_358 | 2 | V_359 | V_112 | V_336 ,
0600 ) ;
if ( F_51 ( V_338 . V_107 ) )
goto V_349;
V_221 = V_338 . V_107 -> V_123 . V_124 -> V_125 ;
if ( V_221 -> V_360 > 1 )
goto V_356;
if ( F_253 ( V_338 . V_107 -> V_123 . V_124 ) )
goto V_356;
if ( ! F_79 ( V_221 -> V_126 ) )
goto V_356;
if ( V_221 -> V_228 != F_254 () )
goto V_356;
if ( ! V_338 . V_107 -> V_222 || ! V_338 . V_107 -> V_222 -> V_21 )
goto V_356;
if ( F_255 ( V_338 . V_107 -> V_123 . V_124 , 0 , 0 , V_338 . V_107 ) )
goto V_356;
}
V_187 = V_259 -> V_340 ( & V_338 ) ;
if ( V_187 )
V_14 -> signal -> V_294 |= 0x80 ;
if ( V_282 && V_351 )
F_228 ( V_338 . V_107 ) ;
V_356:
if ( V_338 . V_107 )
F_256 ( V_338 . V_107 , NULL ) ;
V_352:
if ( V_282 )
F_93 ( & V_337 ) ;
V_349:
F_155 ( V_261 . V_263 ) ;
V_346:
F_221 ( V_13 ) ;
F_257 ( V_335 ) ;
V_343:
F_258 ( V_202 ) ;
V_309:
return;
}
int F_259 ( struct V_107 * V_107 , const void * V_130 , int V_57 )
{
return F_260 ( V_361 , V_130 , V_57 ) && V_107 -> V_222 -> V_21 ( V_107 , V_130 , V_57 , & V_107 -> V_362 ) == V_57 ;
}
int F_261 ( struct V_107 * V_107 , T_4 V_363 )
{
int V_22 = 1 ;
if ( V_107 -> V_222 -> V_364 && V_107 -> V_222 -> V_364 != V_365 ) {
if ( V_107 -> V_222 -> V_364 ( V_107 , V_363 , V_366 ) < 0 )
return 0 ;
} else {
char * V_184 = ( char * ) F_262 ( V_37 ) ;
if ( ! V_184 )
return 0 ;
while ( V_363 > 0 ) {
unsigned long V_367 = V_363 ;
if ( V_367 > V_29 )
V_367 = V_29 ;
if ( ! F_259 ( V_107 , V_184 , V_367 ) ) {
V_22 = 0 ;
break;
}
V_363 -= V_367 ;
}
F_263 ( ( unsigned long ) V_184 ) ;
}
return V_22 ;
}
