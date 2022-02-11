static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_6 = V_5 -> V_7 ;
if ( V_3 ) {
if ( V_3 >= V_2 -> V_8 ) {
V_6 = V_9 ;
if ( V_5 -> V_10 )
V_6 |= V_11 ;
V_2 -> V_12 = V_2 -> V_8 ;
} else if ( V_5 -> V_10 ) {
V_6 = F_2 ( V_2 -> V_8 , V_3 ) - 2 ;
if ( V_6 >= 256 )
V_6 = 255 ;
V_2 -> V_12 = V_2 -> V_8 / ( V_6 + 2 ) ;
} else {
V_6 = V_2 -> V_8 / ( 2 * V_3 ) - 1 ;
if ( V_6 >= 256 )
V_6 = 255 ;
V_2 -> V_12 = V_2 -> V_8 / ( 2 * ( V_6 + 1 ) ) ;
}
V_6 |= V_5 -> V_13 ;
V_6 |= V_14 ;
}
if ( V_2 -> V_15 -> V_16 . V_17 == V_18 )
V_6 |= V_19 ;
if ( V_2 -> V_15 -> V_16 . V_17 == V_20 )
V_6 |= V_21 ;
F_3 ( V_6 , V_2 -> V_22 + V_23 ) ;
}
static void
F_4 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
F_3 ( 0 , V_2 -> V_22 + V_26 ) ;
F_5 ( V_2 -> V_27 ) ;
V_2 -> V_25 = NULL ;
V_2 -> V_28 = NULL ;
F_6 ( & V_2 -> V_29 ) ;
F_7 ( F_8 ( V_2 -> V_15 ) ) ;
F_9 ( V_2 -> V_15 , V_25 ) ;
F_10 ( & V_2 -> V_29 ) ;
}
static void F_11 ( struct V_1 * V_2 , unsigned int V_30 )
{
void T_2 * V_22 = V_2 -> V_22 ;
if ( V_2 -> V_31 ) {
unsigned int V_32 = F_12 ( V_22 + V_33 ) ;
V_32 &= ~ V_34 ;
V_32 |= V_30 ;
F_3 ( V_32 , V_22 + V_33 ) ;
}
F_3 ( V_30 , V_22 + V_35 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_3 ( 0 , V_2 -> V_22 + V_36 ) ;
F_11 ( V_2 , 0 ) ;
V_2 -> V_27 = NULL ;
}
static void F_14 ( struct V_1 * V_2 , struct V_37 * V_27 )
{
unsigned int V_38 = V_39 ;
if ( V_27 -> V_38 & V_40 )
V_38 |= V_41 ;
else
V_38 |= V_42 ;
F_15 ( & V_2 -> V_43 , V_27 -> V_44 , V_27 -> V_45 , V_38 ) ;
}
static void T_3 F_16 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_47 ;
const char * V_48 , * V_49 ;
T_4 V_30 ;
if ( ! V_47 || ! V_47 -> V_50 ) {
F_17 ( F_8 ( V_2 -> V_15 ) , L_1 ) ;
return;
}
V_2 -> V_51 . V_52 = 1 ;
F_18 ( V_30 ) ;
F_19 ( V_53 , V_30 ) ;
if ( V_47 -> V_54 ) {
V_2 -> V_55 = F_20 ( V_30 ,
V_47 -> V_50 ,
V_47 -> V_54 ) ;
if ( ! V_2 -> V_55 )
F_21 ( F_8 ( V_2 -> V_15 ) , L_2 ) ;
}
if ( V_47 -> V_56 ) {
V_2 -> V_57 = F_20 ( V_30 ,
V_47 -> V_50 ,
V_47 -> V_56 ) ;
if ( ! V_2 -> V_57 )
F_22 ( F_8 ( V_2 -> V_15 ) , L_3 ) ;
} else {
V_2 -> V_57 = V_2 -> V_55 ;
}
if ( V_2 -> V_55 )
V_48 = F_23 ( V_2 -> V_55 ) ;
else
V_48 = L_4 ;
if ( V_2 -> V_57 )
V_49 = F_23 ( V_2 -> V_57 ) ;
else
V_49 = L_4 ;
F_17 ( F_8 ( V_2 -> V_15 ) , L_5 ,
V_48 , V_49 ) ;
if ( V_2 -> V_57 ) {
struct V_58 * V_59 = V_2 -> V_57 -> V_58 -> V_59 ;
unsigned int V_60 = F_24 ( V_59 ) ;
if ( V_60 < V_2 -> V_15 -> V_60 )
V_2 -> V_15 -> V_60 = V_60 ;
}
if ( V_2 -> V_55 ) {
struct V_58 * V_59 = V_2 -> V_55 -> V_58 -> V_59 ;
unsigned int V_60 = F_24 ( V_59 ) ;
if ( V_60 < V_2 -> V_15 -> V_60 )
V_2 -> V_15 -> V_60 = V_60 ;
}
}
static inline void F_25 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_47 ;
if ( V_2 -> V_55 )
F_26 ( V_2 -> V_55 ) ;
if ( V_2 -> V_57 && V_47 -> V_56 )
F_26 ( V_2 -> V_57 ) ;
V_2 -> V_55 = V_2 -> V_57 = NULL ;
}
static void F_27 ( struct V_1 * V_2 , struct V_37 * V_27 )
{
struct V_61 * V_62 = V_2 -> V_63 ;
enum V_64 V_65 ;
T_1 V_66 ;
int V_67 ;
for ( V_67 = 0 ; ; V_67 ++ ) {
V_66 = F_12 ( V_2 -> V_22 + V_68 ) ;
if ( ! ( V_66 & V_69 ) || V_67 >= 100 )
break;
F_28 ( 10 ) ;
}
if ( V_66 & V_69 ) {
F_29 ( V_62 ) ;
if ( ! V_27 -> error )
V_27 -> error = - V_70 ;
}
if ( V_27 -> V_38 & V_71 ) {
V_65 = V_72 ;
} else {
V_65 = V_73 ;
}
if ( ! V_27 -> V_74 )
F_30 ( V_62 -> V_58 -> V_59 , V_27 -> V_44 , V_27 -> V_45 , V_65 ) ;
if ( V_66 & V_69 ) {
F_21 ( F_8 ( V_2 -> V_15 ) , L_6 ) ;
F_25 ( V_2 ) ;
}
}
static void F_31 ( struct V_1 * V_2 )
{
F_21 ( F_8 ( V_2 -> V_15 ) , L_7 ) ;
F_29 ( V_2 -> V_63 ) ;
}
static int F_32 ( struct V_1 * V_2 , struct V_37 * V_27 ,
struct V_75 * V_76 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_77 V_78 = {
. V_79 = V_2 -> V_80 + V_81 ,
. V_82 = V_2 -> V_80 + V_81 ,
. V_83 = V_84 ,
. V_85 = V_84 ,
. V_86 = V_5 -> V_87 >> 2 ,
. V_88 = V_5 -> V_87 >> 2 ,
} ;
struct V_61 * V_62 ;
struct V_89 * V_58 ;
struct V_90 * V_91 ;
enum V_64 V_92 ;
int V_93 ;
if ( V_27 -> V_74 && ! V_76 &&
V_2 -> V_63 && V_2 -> V_94 )
return 0 ;
if ( ! V_76 ) {
V_2 -> V_63 = NULL ;
V_2 -> V_94 = NULL ;
}
if ( V_27 -> V_38 & V_40 ) {
V_78 . V_95 = V_96 ;
V_92 = V_73 ;
V_62 = V_2 -> V_55 ;
} else {
V_78 . V_95 = V_97 ;
V_92 = V_72 ;
V_62 = V_2 -> V_57 ;
}
if ( ! V_62 )
return - V_98 ;
if ( V_27 -> V_99 * V_27 -> V_100 <= V_5 -> V_101 )
return - V_98 ;
V_58 = V_62 -> V_58 ;
V_93 = F_33 ( V_58 -> V_59 , V_27 -> V_44 , V_27 -> V_45 , V_92 ) ;
if ( V_93 == 0 )
return - V_98 ;
F_34 ( V_62 , & V_78 ) ;
V_91 = V_58 -> V_102 ( V_62 , V_27 -> V_44 , V_93 ,
V_78 . V_95 , V_103 ) ;
if ( ! V_91 )
goto V_104;
if ( V_76 ) {
V_76 -> V_61 = V_62 ;
V_76 -> V_105 = V_91 ;
} else {
V_2 -> V_63 = V_62 ;
V_2 -> V_94 = V_91 ;
}
return 0 ;
V_104:
if ( ! V_76 )
F_29 ( V_62 ) ;
F_30 ( V_58 -> V_59 , V_27 -> V_44 , V_27 -> V_45 , V_92 ) ;
return - V_106 ;
}
static int F_35 ( struct V_1 * V_2 , unsigned int V_107 )
{
int V_108 ;
struct V_37 * V_27 = V_2 -> V_27 ;
V_108 = F_32 ( V_2 , V_2 -> V_27 , NULL ) ;
if ( V_108 )
return V_108 ;
F_36 ( F_8 ( V_2 -> V_15 ) ,
L_8 ,
V_27 -> V_45 , V_27 -> V_99 , V_27 -> V_100 , V_27 -> V_38 ) ;
F_37 ( V_2 -> V_94 ) ;
F_38 ( V_2 -> V_63 ) ;
V_107 |= V_109 ;
F_3 ( V_107 , V_2 -> V_22 + V_36 ) ;
F_3 ( F_12 ( V_2 -> V_22 + V_33 ) | V_110 ,
V_2 -> V_22 + V_33 ) ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 , struct V_37 * V_27 )
{
struct V_75 * V_76 = & V_2 -> V_51 ;
if ( V_27 -> V_74 && V_27 -> V_74 != V_76 -> V_52 ) {
F_40 ( L_9
L_10 ,
V_111 , V_27 -> V_74 , V_2 -> V_51 . V_52 ) ;
V_27 -> V_74 = 0 ;
}
if ( ! V_27 -> V_74 )
return;
V_2 -> V_94 = V_76 -> V_105 ;
V_2 -> V_63 = V_76 -> V_61 ;
V_76 -> V_105 = NULL ;
V_76 -> V_61 = NULL ;
}
static void F_41 ( struct V_112 * V_15 , struct V_24 * V_25 ,
bool V_113 )
{
struct V_1 * V_2 = F_42 ( V_15 ) ;
struct V_37 * V_27 = V_25 -> V_27 ;
struct V_75 * V_114 = & V_2 -> V_51 ;
if ( ! V_27 )
return;
if ( V_27 -> V_74 ) {
V_27 -> V_74 = 0 ;
return;
}
if ( ( ( V_27 -> V_38 & V_71 ) && V_2 -> V_57 ) ||
( ( V_27 -> V_38 & V_40 ) && V_2 -> V_55 ) ) {
if ( F_32 ( V_2 , V_27 , V_114 ) )
V_27 -> V_74 = 0 ;
else
V_27 -> V_74 = ++ V_114 -> V_52 < 0 ? 1 : V_114 -> V_52 ;
}
}
static void F_43 ( struct V_112 * V_15 , struct V_24 * V_25 ,
int V_115 )
{
struct V_1 * V_2 = F_42 ( V_15 ) ;
struct V_37 * V_27 = V_25 -> V_27 ;
struct V_61 * V_62 ;
enum V_64 V_65 ;
if ( ! V_27 )
return;
if ( V_27 -> V_38 & V_40 ) {
V_65 = V_73 ;
V_62 = V_2 -> V_55 ;
} else {
V_65 = V_72 ;
V_62 = V_2 -> V_57 ;
}
if ( V_62 ) {
if ( V_115 )
F_29 ( V_62 ) ;
if ( V_27 -> V_74 )
F_30 ( F_8 ( V_2 -> V_15 ) , V_27 -> V_44 ,
V_27 -> V_45 , V_65 ) ;
V_25 -> V_27 -> V_74 = 0 ;
}
}
static void F_39 ( struct V_1 * V_2 , struct V_37 * V_27 )
{
}
static inline void F_16 ( struct V_1 * V_2 )
{
}
static inline void F_25 ( struct V_1 * V_2 )
{
}
static inline void F_27 ( struct V_1 * V_2 , struct V_37 * V_27 )
{
}
static inline void F_31 ( struct V_1 * V_2 )
{
}
static inline int F_35 ( struct V_1 * V_2 , unsigned int V_107 )
{
return - V_116 ;
}
static void F_44 ( struct V_1 * V_2 , struct V_37 * V_27 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_107 , V_117 , V_118 ;
unsigned long long V_119 ;
void T_2 * V_22 ;
int V_120 ;
F_45 ( F_8 ( V_2 -> V_15 ) , L_11 ,
V_27 -> V_99 , V_27 -> V_100 , V_27 -> V_38 ) ;
V_2 -> V_27 = V_27 ;
V_2 -> V_121 = V_27 -> V_99 * V_27 -> V_100 ;
V_27 -> V_122 = 0 ;
V_119 = ( unsigned long long ) V_27 -> V_123 * V_2 -> V_12 ;
F_46 ( V_119 , 1000000000UL ) ;
V_117 = V_27 -> V_124 + ( unsigned int ) V_119 ;
V_22 = V_2 -> V_22 ;
F_3 ( V_117 , V_22 + V_125 ) ;
F_3 ( V_2 -> V_121 , V_22 + V_126 ) ;
V_120 = F_47 ( V_27 -> V_99 ) - 1 ;
F_5 ( 1 << V_120 != V_27 -> V_99 ) ;
if ( V_5 -> V_127 )
V_107 = V_128 | ( V_27 -> V_99 << 16 ) ;
else
V_107 = V_128 | V_120 << 4 ;
if ( V_27 -> V_38 & V_40 )
V_107 |= V_129 ;
if ( ! F_35 ( V_2 , V_107 ) )
return;
F_14 ( V_2 , V_27 ) ;
if ( V_27 -> V_38 & V_40 ) {
V_118 = V_130 ;
if ( V_2 -> V_121 < V_5 -> V_87 )
V_118 |= V_69 ;
} else {
V_118 = V_131 ;
}
if ( V_5 -> V_132 && V_2 -> V_15 -> V_133 )
if ( F_48 ( V_2 -> V_15 -> V_133 ) )
V_107 |= V_134 ;
F_3 ( V_107 , V_22 + V_36 ) ;
F_3 ( F_12 ( V_22 + V_33 ) & ~ V_110 , V_22 + V_33 ) ;
F_11 ( V_2 , V_118 ) ;
}
static void
F_49 ( struct V_1 * V_2 , struct V_135 * V_28 , T_1 V_136 )
{
void T_2 * V_22 = V_2 -> V_22 ;
F_45 ( F_8 ( V_2 -> V_15 ) , L_12 ,
V_28 -> V_137 , V_28 -> V_138 , V_28 -> V_38 ) ;
if ( F_12 ( V_22 + V_26 ) & V_139 ) {
F_3 ( 0 , V_22 + V_26 ) ;
F_28 ( 1 ) ;
}
V_136 |= V_28 -> V_137 | V_139 ;
if ( V_28 -> V_38 & V_140 ) {
if ( V_28 -> V_38 & V_141 )
V_136 |= V_142 ;
V_136 |= V_143 ;
}
if ( 0 )
V_136 |= V_144 ;
V_2 -> V_28 = V_28 ;
F_3 ( V_28 -> V_138 , V_22 + V_145 ) ;
F_3 ( V_136 , V_22 + V_26 ) ;
}
static void
F_50 ( struct V_1 * V_2 , struct V_37 * V_27 ,
unsigned int V_66 )
{
if ( V_66 & ( V_146 | V_147 | V_148 |
V_149 | V_150 ) ) {
T_1 V_151 , V_152 ;
if ( F_51 ( V_2 ) )
F_31 ( V_2 ) ;
V_151 = F_12 ( V_2 -> V_22 + V_153 ) ;
V_152 = V_27 -> V_99 * V_27 -> V_100 - V_151 ;
F_45 ( F_8 ( V_2 -> V_15 ) , L_13 ,
V_66 , V_152 ) ;
if ( V_66 & V_146 ) {
V_152 -= 1 ;
V_27 -> error = - V_154 ;
} else if ( V_66 & V_147 ) {
V_27 -> error = - V_155 ;
} else if ( V_66 & V_148 ) {
V_27 -> error = - V_156 ;
} else if ( V_66 & V_149 ) {
V_27 -> error = - V_70 ;
} else if ( V_66 & V_150 ) {
if ( V_152 > V_2 -> V_5 -> V_101 )
V_152 -= V_2 -> V_5 -> V_101 ;
else
V_152 = 0 ;
V_27 -> error = - V_70 ;
}
V_27 -> V_122 = F_52 ( V_152 , V_27 -> V_99 ) ;
}
if ( V_66 & V_157 )
F_21 ( F_8 ( V_2 -> V_15 ) , L_14 ) ;
if ( V_66 & V_158 || V_27 -> error ) {
if ( F_51 ( V_2 ) )
F_27 ( V_2 , V_27 ) ;
F_13 ( V_2 ) ;
if ( ! V_27 -> error )
V_27 -> V_122 = V_27 -> V_99 * V_27 -> V_100 ;
if ( ! V_27 -> V_159 ) {
F_4 ( V_2 , V_27 -> V_25 ) ;
} else {
F_49 ( V_2 , V_27 -> V_159 , 0 ) ;
}
}
}
static void
F_53 ( struct V_1 * V_2 , struct V_135 * V_28 ,
unsigned int V_66 )
{
void T_2 * V_22 = V_2 -> V_22 ;
V_2 -> V_28 = NULL ;
if ( V_66 & V_160 ) {
V_28 -> error = - V_155 ;
} else if ( V_66 & V_161 && V_28 -> V_38 & V_162 ) {
V_28 -> error = - V_154 ;
} else {
V_28 -> V_163 [ 0 ] = F_12 ( V_22 + V_164 ) ;
V_28 -> V_163 [ 1 ] = F_12 ( V_22 + V_165 ) ;
V_28 -> V_163 [ 2 ] = F_12 ( V_22 + V_166 ) ;
V_28 -> V_163 [ 3 ] = F_12 ( V_22 + V_167 ) ;
}
if ( ! V_28 -> V_27 || V_28 -> error ) {
if ( V_2 -> V_27 ) {
if ( F_51 ( V_2 ) )
F_31 ( V_2 ) ;
F_13 ( V_2 ) ;
}
F_4 ( V_2 , V_28 -> V_25 ) ;
} else if ( ! ( V_28 -> V_27 -> V_38 & V_40 ) ) {
F_44 ( V_2 , V_28 -> V_27 ) ;
}
}
static int F_54 ( struct V_1 * V_2 , char * V_168 , unsigned int V_151 )
{
void T_2 * V_22 = V_2 -> V_22 ;
char * V_169 = V_168 ;
T_1 V_66 ;
int V_170 = V_2 -> V_121 ;
do {
int V_171 = V_170 - ( F_12 ( V_22 + V_172 ) << 2 ) ;
if ( V_171 > V_151 )
V_171 = V_151 ;
if ( V_171 <= 0 )
break;
F_55 ( V_22 + V_81 , V_169 , V_171 >> 2 ) ;
V_169 += V_171 ;
V_151 -= V_171 ;
V_170 -= V_171 ;
if ( V_151 == 0 )
break;
V_66 = F_12 ( V_22 + V_68 ) ;
} while ( V_66 & V_173 );
return V_169 - V_168 ;
}
static int F_56 ( struct V_1 * V_2 , char * V_168 , unsigned int V_151 , T_1 V_66 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
void T_2 * V_22 = V_2 -> V_22 ;
char * V_169 = V_168 ;
do {
unsigned int V_171 , V_174 ;
V_174 = V_66 & V_175 ?
V_5 -> V_101 : V_5 -> V_87 ;
V_171 = F_57 ( V_151 , V_174 ) ;
if ( V_5 -> V_132 &&
F_48 ( V_2 -> V_15 -> V_133 ) ) {
if ( V_171 < 8 )
F_3 ( F_12 ( V_2 -> V_22 + V_23 ) &
~ V_5 -> V_13 ,
V_2 -> V_22 + V_23 ) ;
else
F_3 ( F_12 ( V_2 -> V_22 + V_23 ) |
V_5 -> V_13 ,
V_2 -> V_22 + V_23 ) ;
}
F_58 ( V_22 + V_81 , V_169 , ( V_171 + 3 ) >> 2 ) ;
V_169 += V_171 ;
V_151 -= V_171 ;
if ( V_151 == 0 )
break;
V_66 = F_12 ( V_22 + V_68 ) ;
} while ( V_66 & V_176 );
return V_169 - V_168 ;
}
static T_5 F_59 ( int V_177 , void * V_178 )
{
struct V_1 * V_2 = V_178 ;
struct V_179 * V_43 = & V_2 -> V_43 ;
struct V_4 * V_5 = V_2 -> V_5 ;
void T_2 * V_22 = V_2 -> V_22 ;
unsigned long V_38 ;
T_1 V_66 ;
V_66 = F_12 ( V_22 + V_68 ) ;
F_45 ( F_8 ( V_2 -> V_15 ) , L_15 , V_66 ) ;
F_60 ( V_38 ) ;
do {
unsigned int V_151 , V_180 ;
char * V_168 ;
if ( ! ( V_66 & ( V_176 | V_173 ) ) )
break;
if ( ! F_61 ( V_43 ) )
break;
V_168 = V_43 -> V_181 ;
V_151 = V_43 -> V_182 ;
V_180 = 0 ;
if ( V_66 & V_183 )
V_180 = F_54 ( V_2 , V_168 , V_151 ) ;
if ( V_66 & V_184 )
V_180 = F_56 ( V_2 , V_168 , V_151 , V_66 ) ;
V_43 -> V_185 = V_180 ;
V_2 -> V_121 -= V_180 ;
V_151 -= V_180 ;
if ( V_151 )
break;
V_66 = F_12 ( V_22 + V_68 ) ;
} while ( 1 );
F_62 ( V_43 ) ;
F_63 ( V_38 ) ;
if ( V_66 & V_183 && V_2 -> V_121 < V_5 -> V_87 )
F_11 ( V_2 , V_69 ) ;
if ( V_2 -> V_121 == 0 ) {
F_11 ( V_2 , 0 ) ;
F_3 ( F_12 ( V_22 + V_33 ) | V_110 , V_22 + V_33 ) ;
}
return V_186 ;
}
static T_5 F_64 ( int V_177 , void * V_178 )
{
struct V_1 * V_2 = V_178 ;
T_1 V_66 ;
int V_108 = 0 ;
F_10 ( & V_2 -> V_29 ) ;
do {
struct V_135 * V_28 ;
struct V_37 * V_27 ;
V_66 = F_12 ( V_2 -> V_22 + V_68 ) ;
if ( V_2 -> V_31 ) {
if ( V_66 & F_12 ( V_2 -> V_22 + V_35 ) )
F_59 ( V_177 , V_178 ) ;
V_66 &= ~ V_34 ;
}
V_66 &= F_12 ( V_2 -> V_22 + V_33 ) ;
F_3 ( V_66 , V_2 -> V_22 + V_187 ) ;
F_45 ( F_8 ( V_2 -> V_15 ) , L_16 , V_66 ) ;
V_27 = V_2 -> V_27 ;
if ( V_66 & ( V_146 | V_147 | V_148 |
V_149 | V_150 | V_158 |
V_157 ) && V_27 )
F_50 ( V_2 , V_27 , V_66 ) ;
V_28 = V_2 -> V_28 ;
if ( V_66 & ( V_161 | V_160 | V_188 | V_189 ) && V_28 )
F_53 ( V_2 , V_28 , V_66 ) ;
V_108 = 1 ;
} while ( V_66 );
F_6 ( & V_2 -> V_29 ) ;
return F_65 ( V_108 ) ;
}
static void F_66 ( struct V_112 * V_15 , struct V_24 * V_25 )
{
struct V_1 * V_2 = F_42 ( V_15 ) ;
unsigned long V_38 ;
F_67 ( V_2 -> V_25 != NULL ) ;
if ( V_25 -> V_27 && ! F_68 ( V_25 -> V_27 -> V_99 ) ) {
F_21 ( F_8 ( V_15 ) , L_17 ,
V_25 -> V_27 -> V_99 ) ;
V_25 -> V_28 -> error = - V_98 ;
F_9 ( V_15 , V_25 ) ;
return;
}
F_69 ( F_8 ( V_15 ) ) ;
F_70 ( & V_2 -> V_29 , V_38 ) ;
V_2 -> V_25 = V_25 ;
if ( V_25 -> V_27 )
F_39 ( V_2 , V_25 -> V_27 ) ;
if ( V_25 -> V_27 && V_25 -> V_27 -> V_38 & V_40 )
F_44 ( V_2 , V_25 -> V_27 ) ;
F_49 ( V_2 , V_25 -> V_28 , 0 ) ;
F_71 ( & V_2 -> V_29 , V_38 ) ;
}
static void F_72 ( struct V_112 * V_15 , struct V_190 * V_16 )
{
struct V_1 * V_2 = F_42 ( V_15 ) ;
T_1 V_191 = 0 ;
unsigned long V_38 ;
int V_108 ;
switch ( V_16 -> V_192 ) {
case V_193 :
if ( V_2 -> V_194 )
V_108 = F_73 ( V_15 , V_2 -> V_194 , 0 ) ;
break;
case V_195 :
if ( V_2 -> V_194 ) {
V_108 = F_73 ( V_15 , V_2 -> V_194 , V_16 -> V_196 ) ;
if ( V_108 ) {
F_21 ( F_8 ( V_15 ) , L_18 ) ;
return;
}
}
if ( V_2 -> V_47 -> V_197 )
V_191 |= V_2 -> V_47 -> V_197 ( F_8 ( V_15 ) , V_16 -> V_196 ,
V_16 -> V_192 ) ;
if ( V_2 -> V_198 != V_199 ) {
V_191 |= V_200 ;
break;
}
case V_201 :
V_191 |= V_202 ;
break;
}
if ( V_16 -> V_203 == V_204 ) {
if ( V_2 -> V_198 != V_199 )
V_191 |= V_205 ;
else {
V_191 |= V_206 ;
}
}
F_70 ( & V_2 -> V_29 , V_38 ) ;
F_1 ( V_2 , V_16 -> clock ) ;
if ( V_2 -> V_191 != V_191 ) {
V_2 -> V_191 = V_191 ;
F_3 ( V_191 , V_2 -> V_22 + V_207 ) ;
}
F_71 ( & V_2 -> V_29 , V_38 ) ;
}
static int F_74 ( struct V_112 * V_15 )
{
struct V_1 * V_2 = F_42 ( V_15 ) ;
if ( V_2 -> V_208 == - V_116 )
return - V_116 ;
return F_75 ( V_2 -> V_208 ) ;
}
static int F_76 ( struct V_112 * V_15 )
{
struct V_1 * V_2 = F_42 ( V_15 ) ;
struct V_46 * V_47 = V_2 -> V_47 ;
unsigned int V_66 ;
if ( V_2 -> V_209 == - V_116 ) {
if ( ! V_47 -> V_66 )
return 1 ;
V_66 = V_47 -> V_66 ( F_8 ( V_2 -> V_15 ) ) ;
} else
V_66 = ! ! F_75 ( V_2 -> V_209 )
^ V_47 -> V_210 ;
return V_66 ;
}
static T_5 F_77 ( int V_177 , void * V_178 )
{
struct V_1 * V_2 = V_178 ;
F_78 ( V_2 -> V_15 , F_79 ( 500 ) ) ;
return V_186 ;
}
static int T_3 F_80 ( struct V_211 * V_59 ,
const struct V_212 * V_213 )
{
struct V_46 * V_47 = V_59 -> V_59 . V_214 ;
struct V_4 * V_5 = V_213 -> V_27 ;
struct V_1 * V_2 ;
struct V_112 * V_15 ;
int V_108 ;
if ( ! V_47 ) {
V_108 = - V_98 ;
goto V_215;
}
V_108 = F_81 ( V_59 , V_216 ) ;
if ( V_108 )
goto V_215;
V_15 = F_82 ( sizeof( struct V_1 ) , & V_59 -> V_59 ) ;
if ( ! V_15 ) {
V_108 = - V_106 ;
goto V_217;
}
V_2 = F_42 ( V_15 ) ;
V_2 -> V_15 = V_15 ;
V_2 -> V_208 = - V_116 ;
V_2 -> V_209 = - V_116 ;
V_2 -> V_218 = - 1 ;
V_2 -> V_198 = F_83 ( V_59 ) ;
V_2 -> V_219 = F_84 ( V_59 ) ;
F_45 ( F_8 ( V_15 ) , L_19 , V_2 -> V_198 ) ;
F_45 ( F_8 ( V_15 ) , L_20 , V_2 -> V_219 ) ;
V_2 -> V_6 = F_85 ( & V_59 -> V_59 , NULL ) ;
if ( F_86 ( V_2 -> V_6 ) ) {
V_108 = F_87 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
goto V_220;
}
V_108 = F_88 ( V_2 -> V_6 ) ;
if ( V_108 )
goto V_221;
V_108 = F_89 ( V_2 -> V_6 ) ;
if ( V_108 )
goto V_222;
V_2 -> V_47 = V_47 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_8 = F_90 ( V_2 -> V_6 ) ;
if ( V_2 -> V_8 > 100000000 ) {
V_108 = F_91 ( V_2 -> V_6 , 100000000 ) ;
if ( V_108 < 0 )
goto V_223;
V_2 -> V_8 = F_90 ( V_2 -> V_6 ) ;
F_45 ( F_8 ( V_15 ) , L_21 ,
V_2 -> V_8 ) ;
}
V_2 -> V_80 = V_59 -> V_224 . V_225 ;
V_2 -> V_22 = F_92 ( V_59 -> V_224 . V_225 , F_93 ( & V_59 -> V_224 ) ) ;
if ( ! V_2 -> V_22 ) {
V_108 = - V_106 ;
goto V_223;
}
V_15 -> V_226 = & V_227 ;
if ( V_5 -> V_10 )
V_15 -> V_228 = F_2 ( V_2 -> V_8 , 257 ) ;
else
V_15 -> V_228 = F_2 ( V_2 -> V_8 , 512 ) ;
if ( V_47 -> V_229 )
V_15 -> V_229 = F_57 ( V_2 -> V_8 , V_47 -> V_229 ) ;
else
V_15 -> V_229 = F_57 ( V_2 -> V_8 , V_230 ) ;
F_45 ( F_8 ( V_15 ) , L_22 , V_15 -> V_229 ) ;
#ifdef F_94
V_2 -> V_194 = F_95 ( & V_59 -> V_59 , L_23 ) ;
if ( F_86 ( V_2 -> V_194 ) )
V_2 -> V_194 = NULL ;
else {
int V_30 = F_96 ( V_2 -> V_194 ) ;
if ( V_30 < 0 )
F_21 ( & V_59 -> V_59 , L_24 ,
V_30 ) ;
else {
V_2 -> V_15 -> V_231 = ( T_1 ) V_30 ;
if ( V_47 -> V_232 )
F_22 ( & V_59 -> V_59 ,
L_25
L_26 ) ;
}
}
#endif
if ( V_2 -> V_194 == NULL )
V_15 -> V_231 = V_47 -> V_232 ;
V_15 -> V_233 = V_47 -> V_234 ;
V_15 -> V_235 = V_47 -> V_236 ;
V_15 -> V_237 = V_238 ;
V_15 -> V_239 = ( 1 << V_5 -> V_240 ) - 1 ;
V_15 -> V_60 = V_15 -> V_239 ;
V_15 -> V_241 = 1 << 11 ;
V_15 -> V_242 = V_15 -> V_239 >> 11 ;
F_97 ( & V_2 -> V_29 ) ;
F_3 ( 0 , V_2 -> V_22 + V_33 ) ;
F_3 ( 0 , V_2 -> V_22 + V_35 ) ;
F_3 ( 0xfff , V_2 -> V_22 + V_187 ) ;
if ( F_98 ( V_47 -> V_209 ) ) {
V_108 = F_99 ( V_47 -> V_209 , V_216 L_27 ) ;
if ( V_108 == 0 )
V_108 = F_100 ( V_47 -> V_209 ) ;
if ( V_108 == 0 )
V_2 -> V_209 = V_47 -> V_209 ;
else if ( V_108 != - V_116 )
goto V_243;
V_108 = F_101 ( F_102 ( V_47 -> V_209 ) ,
F_77 ,
V_244 | V_245 ,
V_216 L_27 , V_2 ) ;
if ( V_108 >= 0 )
V_2 -> V_218 = F_102 ( V_47 -> V_209 ) ;
}
if ( F_98 ( V_47 -> V_208 ) ) {
V_108 = F_99 ( V_47 -> V_208 , V_216 L_28 ) ;
if ( V_108 == 0 )
V_108 = F_100 ( V_47 -> V_208 ) ;
if ( V_108 == 0 )
V_2 -> V_208 = V_47 -> V_208 ;
else if ( V_108 != - V_116 )
goto V_246;
}
if ( ( V_2 -> V_47 -> V_66 || V_2 -> V_209 != - V_116 )
&& V_2 -> V_218 < 0 )
V_15 -> V_233 |= V_247 ;
V_108 = F_103 ( V_59 -> V_177 [ 0 ] , F_64 , V_248 , V_216 L_29 , V_2 ) ;
if ( V_108 )
goto V_249;
if ( V_59 -> V_177 [ 1 ] == V_250 )
V_2 -> V_31 = true ;
else {
V_108 = F_103 ( V_59 -> V_177 [ 1 ] , F_59 , V_248 ,
V_216 L_30 , V_2 ) ;
if ( V_108 )
goto V_251;
}
F_3 ( V_252 , V_2 -> V_22 + V_33 ) ;
F_104 ( V_59 , V_15 ) ;
F_17 ( & V_59 -> V_59 , L_31 ,
F_105 ( V_15 ) , F_106 ( V_59 ) , F_83 ( V_59 ) ,
F_84 ( V_59 ) , ( unsigned long long ) V_59 -> V_224 . V_225 ,
V_59 -> V_177 [ 0 ] , V_59 -> V_177 [ 1 ] ) ;
F_16 ( V_2 ) ;
F_7 ( & V_59 -> V_59 ) ;
F_107 ( V_15 ) ;
return 0 ;
V_251:
F_108 ( V_59 -> V_177 [ 0 ] , V_2 ) ;
V_249:
if ( V_2 -> V_208 != - V_116 )
F_109 ( V_2 -> V_208 ) ;
V_246:
if ( V_2 -> V_218 >= 0 )
F_108 ( V_2 -> V_218 , V_2 ) ;
if ( V_2 -> V_209 != - V_116 )
F_109 ( V_2 -> V_209 ) ;
V_243:
F_110 ( V_2 -> V_22 ) ;
V_223:
V_223 ( V_2 -> V_6 ) ;
V_222:
F_111 ( V_2 -> V_6 ) ;
V_221:
F_112 ( V_2 -> V_6 ) ;
V_220:
F_113 ( V_15 ) ;
V_217:
F_114 ( V_59 ) ;
V_215:
return V_108 ;
}
static int T_6 F_115 ( struct V_211 * V_59 )
{
struct V_112 * V_15 = F_116 ( V_59 ) ;
F_104 ( V_59 , NULL ) ;
if ( V_15 ) {
struct V_1 * V_2 = F_42 ( V_15 ) ;
F_69 ( & V_59 -> V_59 ) ;
F_117 ( V_15 ) ;
F_3 ( 0 , V_2 -> V_22 + V_33 ) ;
F_3 ( 0 , V_2 -> V_22 + V_35 ) ;
F_3 ( 0 , V_2 -> V_22 + V_26 ) ;
F_3 ( 0 , V_2 -> V_22 + V_36 ) ;
F_25 ( V_2 ) ;
F_108 ( V_59 -> V_177 [ 0 ] , V_2 ) ;
if ( ! V_2 -> V_31 )
F_108 ( V_59 -> V_177 [ 1 ] , V_2 ) ;
if ( V_2 -> V_208 != - V_116 )
F_109 ( V_2 -> V_208 ) ;
if ( V_2 -> V_218 >= 0 )
F_108 ( V_2 -> V_218 , V_2 ) ;
if ( V_2 -> V_209 != - V_116 )
F_109 ( V_2 -> V_209 ) ;
F_110 ( V_2 -> V_22 ) ;
V_223 ( V_2 -> V_6 ) ;
F_111 ( V_2 -> V_6 ) ;
F_112 ( V_2 -> V_6 ) ;
if ( V_2 -> V_194 )
F_73 ( V_15 , V_2 -> V_194 , 0 ) ;
F_118 ( V_2 -> V_194 ) ;
F_113 ( V_15 ) ;
F_114 ( V_59 ) ;
}
return 0 ;
}
static int F_119 ( struct V_211 * V_59 , T_7 V_253 )
{
struct V_112 * V_15 = F_116 ( V_59 ) ;
int V_108 = 0 ;
if ( V_15 ) {
struct V_1 * V_2 = F_42 ( V_15 ) ;
V_108 = F_120 ( V_15 ) ;
if ( V_108 == 0 )
F_3 ( 0 , V_2 -> V_22 + V_33 ) ;
}
return V_108 ;
}
static int F_121 ( struct V_211 * V_59 )
{
struct V_112 * V_15 = F_116 ( V_59 ) ;
int V_108 = 0 ;
if ( V_15 ) {
struct V_1 * V_2 = F_42 ( V_15 ) ;
F_3 ( V_252 , V_2 -> V_22 + V_33 ) ;
V_108 = F_122 ( V_15 ) ;
}
return V_108 ;
}
static int T_8 F_123 ( void )
{
return F_124 ( & V_254 ) ;
}
static void T_9 F_125 ( void )
{
F_126 ( & V_254 ) ;
}
