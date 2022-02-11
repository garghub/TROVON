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
F_7 ( V_2 -> V_15 , V_25 ) ;
F_8 ( & V_2 -> V_29 ) ;
}
static void F_9 ( struct V_1 * V_2 , unsigned int V_30 )
{
void T_2 * V_22 = V_2 -> V_22 ;
if ( V_2 -> V_31 ) {
unsigned int V_32 = F_10 ( V_22 + V_33 ) ;
V_32 &= ~ V_34 ;
V_32 |= V_30 ;
F_3 ( V_32 , V_22 + V_33 ) ;
}
F_3 ( V_30 , V_22 + V_35 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_3 ( 0 , V_2 -> V_22 + V_36 ) ;
F_9 ( V_2 , 0 ) ;
V_2 -> V_27 = NULL ;
}
static void F_12 ( struct V_1 * V_2 , struct V_37 * V_27 )
{
unsigned int V_38 = V_39 ;
if ( V_27 -> V_38 & V_40 )
V_38 |= V_41 ;
else
V_38 |= V_42 ;
F_13 ( & V_2 -> V_43 , V_27 -> V_44 , V_27 -> V_45 , V_38 ) ;
}
static void T_3 F_14 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_47 ;
const char * V_48 , * V_49 ;
T_4 V_30 ;
if ( ! V_47 || ! V_47 -> V_50 ) {
F_15 ( F_16 ( V_2 -> V_15 ) , L_1 ) ;
return;
}
V_2 -> V_51 . V_52 = 1 ;
F_17 ( V_30 ) ;
F_18 ( V_53 , V_30 ) ;
if ( V_47 -> V_54 ) {
V_2 -> V_55 = F_19 ( V_30 ,
V_47 -> V_50 ,
V_47 -> V_54 ) ;
if ( ! V_2 -> V_55 )
F_20 ( F_16 ( V_2 -> V_15 ) , L_2 ) ;
}
if ( V_47 -> V_56 ) {
V_2 -> V_57 = F_19 ( V_30 ,
V_47 -> V_50 ,
V_47 -> V_56 ) ;
if ( ! V_2 -> V_57 )
F_21 ( F_16 ( V_2 -> V_15 ) , L_3 ) ;
} else {
V_2 -> V_57 = V_2 -> V_55 ;
}
if ( V_2 -> V_55 )
V_48 = F_22 ( V_2 -> V_55 ) ;
else
V_48 = L_4 ;
if ( V_2 -> V_57 )
V_49 = F_22 ( V_2 -> V_57 ) ;
else
V_49 = L_4 ;
F_15 ( F_16 ( V_2 -> V_15 ) , L_5 ,
V_48 , V_49 ) ;
if ( V_2 -> V_57 ) {
struct V_58 * V_59 = V_2 -> V_57 -> V_58 -> V_59 ;
unsigned int V_60 = F_23 ( V_59 ) ;
if ( V_60 < V_2 -> V_15 -> V_60 )
V_2 -> V_15 -> V_60 = V_60 ;
}
if ( V_2 -> V_55 ) {
struct V_58 * V_59 = V_2 -> V_55 -> V_58 -> V_59 ;
unsigned int V_60 = F_23 ( V_59 ) ;
if ( V_60 < V_2 -> V_15 -> V_60 )
V_2 -> V_15 -> V_60 = V_60 ;
}
}
static inline void F_24 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_47 ;
if ( V_2 -> V_55 )
F_25 ( V_2 -> V_55 ) ;
if ( V_2 -> V_57 && V_47 -> V_56 )
F_25 ( V_2 -> V_57 ) ;
V_2 -> V_55 = V_2 -> V_57 = NULL ;
}
static void F_26 ( struct V_1 * V_2 , struct V_37 * V_27 )
{
struct V_61 * V_62 = V_2 -> V_63 ;
enum V_64 V_65 ;
T_1 V_66 ;
int V_67 ;
for ( V_67 = 0 ; ; V_67 ++ ) {
V_66 = F_10 ( V_2 -> V_22 + V_68 ) ;
if ( ! ( V_66 & V_69 ) || V_67 >= 100 )
break;
F_27 ( 10 ) ;
}
if ( V_66 & V_69 ) {
F_28 ( V_62 ) ;
if ( ! V_27 -> error )
V_27 -> error = - V_70 ;
}
if ( V_27 -> V_38 & V_71 ) {
V_65 = V_72 ;
} else {
V_65 = V_73 ;
}
if ( ! V_27 -> V_74 )
F_29 ( V_62 -> V_58 -> V_59 , V_27 -> V_44 , V_27 -> V_45 , V_65 ) ;
if ( V_66 & V_69 ) {
F_20 ( F_16 ( V_2 -> V_15 ) , L_6 ) ;
F_24 ( V_2 ) ;
}
}
static void F_30 ( struct V_1 * V_2 )
{
F_20 ( F_16 ( V_2 -> V_15 ) , L_7 ) ;
F_28 ( V_2 -> V_63 ) ;
}
static int F_31 ( struct V_1 * V_2 , struct V_37 * V_27 ,
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
int V_92 ;
if ( V_27 -> V_74 && ! V_76 &&
V_2 -> V_63 && V_2 -> V_93 )
return 0 ;
if ( ! V_76 ) {
V_2 -> V_63 = NULL ;
V_2 -> V_93 = NULL ;
}
if ( V_27 -> V_38 & V_40 ) {
V_78 . V_94 = V_73 ;
V_62 = V_2 -> V_55 ;
} else {
V_78 . V_94 = V_72 ;
V_62 = V_2 -> V_57 ;
}
if ( ! V_62 )
return - V_95 ;
if ( V_27 -> V_96 * V_27 -> V_97 <= V_5 -> V_98 )
return - V_95 ;
V_58 = V_62 -> V_58 ;
V_92 = F_32 ( V_58 -> V_59 , V_27 -> V_44 , V_27 -> V_45 , V_78 . V_94 ) ;
if ( V_92 == 0 )
return - V_95 ;
F_33 ( V_62 , & V_78 ) ;
V_91 = V_58 -> V_99 ( V_62 , V_27 -> V_44 , V_92 ,
V_78 . V_94 , V_100 ) ;
if ( ! V_91 )
goto V_101;
if ( V_76 ) {
V_76 -> V_61 = V_62 ;
V_76 -> V_102 = V_91 ;
} else {
V_2 -> V_63 = V_62 ;
V_2 -> V_93 = V_91 ;
}
return 0 ;
V_101:
if ( ! V_76 )
F_28 ( V_62 ) ;
F_29 ( V_58 -> V_59 , V_27 -> V_44 , V_27 -> V_45 , V_78 . V_94 ) ;
return - V_103 ;
}
static int F_34 ( struct V_1 * V_2 , unsigned int V_104 )
{
int V_105 ;
struct V_37 * V_27 = V_2 -> V_27 ;
V_105 = F_31 ( V_2 , V_2 -> V_27 , NULL ) ;
if ( V_105 )
return V_105 ;
F_35 ( F_16 ( V_2 -> V_15 ) ,
L_8 ,
V_27 -> V_45 , V_27 -> V_96 , V_27 -> V_97 , V_27 -> V_38 ) ;
F_36 ( V_2 -> V_93 ) ;
F_37 ( V_2 -> V_63 ) ;
V_104 |= V_106 ;
F_3 ( V_104 , V_2 -> V_22 + V_36 ) ;
F_3 ( F_10 ( V_2 -> V_22 + V_33 ) | V_107 ,
V_2 -> V_22 + V_33 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 , struct V_37 * V_27 )
{
struct V_75 * V_76 = & V_2 -> V_51 ;
if ( V_27 -> V_74 && V_27 -> V_74 != V_76 -> V_52 ) {
F_39 ( V_108 L_9
L_10 ,
V_109 , V_27 -> V_74 , V_2 -> V_51 . V_52 ) ;
V_27 -> V_74 = 0 ;
}
if ( ! V_27 -> V_74 )
return;
V_2 -> V_93 = V_76 -> V_102 ;
V_2 -> V_63 = V_76 -> V_61 ;
V_76 -> V_102 = NULL ;
V_76 -> V_61 = NULL ;
}
static void F_40 ( struct V_110 * V_15 , struct V_24 * V_25 ,
bool V_111 )
{
struct V_1 * V_2 = F_41 ( V_15 ) ;
struct V_37 * V_27 = V_25 -> V_27 ;
struct V_75 * V_112 = & V_2 -> V_51 ;
if ( ! V_27 )
return;
if ( V_27 -> V_74 ) {
V_27 -> V_74 = 0 ;
return;
}
if ( ( ( V_27 -> V_38 & V_71 ) && V_2 -> V_57 ) ||
( ( V_27 -> V_38 & V_40 ) && V_2 -> V_55 ) ) {
if ( F_31 ( V_2 , V_27 , V_112 ) )
V_27 -> V_74 = 0 ;
else
V_27 -> V_74 = ++ V_112 -> V_52 < 0 ? 1 : V_112 -> V_52 ;
}
}
static void F_42 ( struct V_110 * V_15 , struct V_24 * V_25 ,
int V_113 )
{
struct V_1 * V_2 = F_41 ( V_15 ) ;
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
if ( V_113 )
F_28 ( V_62 ) ;
if ( V_113 || V_27 -> V_74 )
F_29 ( F_16 ( V_2 -> V_15 ) , V_27 -> V_44 ,
V_27 -> V_45 , V_65 ) ;
V_25 -> V_27 -> V_74 = 0 ;
}
}
static void F_38 ( struct V_1 * V_2 , struct V_37 * V_27 )
{
}
static inline void F_14 ( struct V_1 * V_2 )
{
}
static inline void F_24 ( struct V_1 * V_2 )
{
}
static inline void F_26 ( struct V_1 * V_2 , struct V_37 * V_27 )
{
}
static inline void F_30 ( struct V_1 * V_2 )
{
}
static inline int F_34 ( struct V_1 * V_2 , unsigned int V_104 )
{
return - V_114 ;
}
static void F_43 ( struct V_1 * V_2 , struct V_37 * V_27 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_104 , V_115 , V_116 ;
unsigned long long V_117 ;
void T_2 * V_22 ;
int V_118 ;
F_44 ( F_16 ( V_2 -> V_15 ) , L_11 ,
V_27 -> V_96 , V_27 -> V_97 , V_27 -> V_38 ) ;
V_2 -> V_27 = V_27 ;
V_2 -> V_119 = V_27 -> V_96 * V_27 -> V_97 ;
V_27 -> V_120 = 0 ;
V_117 = ( unsigned long long ) V_27 -> V_121 * V_2 -> V_12 ;
F_45 ( V_117 , 1000000000UL ) ;
V_115 = V_27 -> V_122 + ( unsigned int ) V_117 ;
V_22 = V_2 -> V_22 ;
F_3 ( V_115 , V_22 + V_123 ) ;
F_3 ( V_2 -> V_119 , V_22 + V_124 ) ;
V_118 = F_46 ( V_27 -> V_96 ) - 1 ;
F_5 ( 1 << V_118 != V_27 -> V_96 ) ;
if ( V_5 -> V_125 )
V_104 = V_126 | ( V_27 -> V_96 << 16 ) ;
else
V_104 = V_126 | V_118 << 4 ;
if ( V_27 -> V_38 & V_40 )
V_104 |= V_127 ;
if ( ! F_34 ( V_2 , V_104 ) )
return;
F_12 ( V_2 , V_27 ) ;
if ( V_27 -> V_38 & V_40 ) {
V_116 = V_128 ;
if ( V_2 -> V_119 < V_5 -> V_87 )
V_116 |= V_69 ;
} else {
V_116 = V_129 ;
}
if ( V_5 -> V_130 && V_2 -> V_15 -> V_131 )
if ( F_47 ( V_2 -> V_15 -> V_131 ) )
V_104 |= V_132 ;
F_3 ( V_104 , V_22 + V_36 ) ;
F_3 ( F_10 ( V_22 + V_33 ) & ~ V_107 , V_22 + V_33 ) ;
F_9 ( V_2 , V_116 ) ;
}
static void
F_48 ( struct V_1 * V_2 , struct V_133 * V_28 , T_1 V_134 )
{
void T_2 * V_22 = V_2 -> V_22 ;
F_44 ( F_16 ( V_2 -> V_15 ) , L_12 ,
V_28 -> V_135 , V_28 -> V_136 , V_28 -> V_38 ) ;
if ( F_10 ( V_22 + V_26 ) & V_137 ) {
F_3 ( 0 , V_22 + V_26 ) ;
F_27 ( 1 ) ;
}
V_134 |= V_28 -> V_135 | V_137 ;
if ( V_28 -> V_38 & V_138 ) {
if ( V_28 -> V_38 & V_139 )
V_134 |= V_140 ;
V_134 |= V_141 ;
}
if ( 0 )
V_134 |= V_142 ;
V_2 -> V_28 = V_28 ;
F_3 ( V_28 -> V_136 , V_22 + V_143 ) ;
F_3 ( V_134 , V_22 + V_26 ) ;
}
static void
F_49 ( struct V_1 * V_2 , struct V_37 * V_27 ,
unsigned int V_66 )
{
if ( V_66 & ( V_144 | V_145 | V_146 | V_147 ) ) {
T_1 V_148 , V_149 ;
if ( F_50 ( V_2 ) )
F_30 ( V_2 ) ;
V_148 = F_10 ( V_2 -> V_22 + V_150 ) ;
V_149 = V_27 -> V_96 * V_27 -> V_97 - V_148 ;
F_44 ( F_16 ( V_2 -> V_15 ) , L_13 ,
V_66 , V_149 ) ;
if ( V_66 & V_144 ) {
V_149 -= 1 ;
V_27 -> error = - V_151 ;
} else if ( V_66 & V_145 ) {
V_27 -> error = - V_152 ;
} else if ( V_66 & V_153 ) {
V_27 -> error = - V_154 ;
} else if ( V_66 & V_146 ) {
V_27 -> error = - V_70 ;
} else if ( V_66 & V_147 ) {
if ( V_149 > V_2 -> V_5 -> V_98 )
V_149 -= V_2 -> V_5 -> V_98 ;
else
V_149 = 0 ;
V_27 -> error = - V_70 ;
}
V_27 -> V_120 = F_51 ( V_149 , V_27 -> V_96 ) ;
}
if ( V_66 & V_155 )
F_20 ( F_16 ( V_2 -> V_15 ) , L_14 ) ;
if ( V_66 & V_156 || V_27 -> error ) {
if ( F_50 ( V_2 ) )
F_26 ( V_2 , V_27 ) ;
F_11 ( V_2 ) ;
if ( ! V_27 -> error )
V_27 -> V_120 = V_27 -> V_96 * V_27 -> V_97 ;
if ( ! V_27 -> V_157 ) {
F_4 ( V_2 , V_27 -> V_25 ) ;
} else {
F_48 ( V_2 , V_27 -> V_157 , 0 ) ;
}
}
}
static void
F_52 ( struct V_1 * V_2 , struct V_133 * V_28 ,
unsigned int V_66 )
{
void T_2 * V_22 = V_2 -> V_22 ;
V_2 -> V_28 = NULL ;
if ( V_66 & V_158 ) {
V_28 -> error = - V_152 ;
} else if ( V_66 & V_159 && V_28 -> V_38 & V_160 ) {
V_28 -> error = - V_151 ;
} else {
V_28 -> V_161 [ 0 ] = F_10 ( V_22 + V_162 ) ;
V_28 -> V_161 [ 1 ] = F_10 ( V_22 + V_163 ) ;
V_28 -> V_161 [ 2 ] = F_10 ( V_22 + V_164 ) ;
V_28 -> V_161 [ 3 ] = F_10 ( V_22 + V_165 ) ;
}
if ( ! V_28 -> V_27 || V_28 -> error ) {
if ( V_2 -> V_27 )
F_11 ( V_2 ) ;
F_4 ( V_2 , V_28 -> V_25 ) ;
} else if ( ! ( V_28 -> V_27 -> V_38 & V_40 ) ) {
F_43 ( V_2 , V_28 -> V_27 ) ;
}
}
static int F_53 ( struct V_1 * V_2 , char * V_166 , unsigned int V_148 )
{
void T_2 * V_22 = V_2 -> V_22 ;
char * V_167 = V_166 ;
T_1 V_66 ;
int V_168 = V_2 -> V_119 ;
do {
int V_169 = V_168 - ( F_10 ( V_22 + V_170 ) << 2 ) ;
if ( V_169 > V_148 )
V_169 = V_148 ;
if ( V_169 <= 0 )
break;
F_54 ( V_22 + V_81 , V_167 , V_169 >> 2 ) ;
V_167 += V_169 ;
V_148 -= V_169 ;
V_168 -= V_169 ;
if ( V_148 == 0 )
break;
V_66 = F_10 ( V_22 + V_68 ) ;
} while ( V_66 & V_171 );
return V_167 - V_166 ;
}
static int F_55 ( struct V_1 * V_2 , char * V_166 , unsigned int V_148 , T_1 V_66 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
void T_2 * V_22 = V_2 -> V_22 ;
char * V_167 = V_166 ;
do {
unsigned int V_169 , V_172 ;
V_172 = V_66 & V_173 ?
V_5 -> V_98 : V_5 -> V_87 ;
V_169 = F_56 ( V_148 , V_172 ) ;
if ( V_5 -> V_130 &&
F_47 ( V_2 -> V_15 -> V_131 ) ) {
if ( V_169 < 8 )
F_3 ( F_10 ( V_2 -> V_22 + V_23 ) &
~ V_5 -> V_13 ,
V_2 -> V_22 + V_23 ) ;
else
F_3 ( F_10 ( V_2 -> V_22 + V_23 ) |
V_5 -> V_13 ,
V_2 -> V_22 + V_23 ) ;
}
F_57 ( V_22 + V_81 , V_167 , ( V_169 + 3 ) >> 2 ) ;
V_167 += V_169 ;
V_148 -= V_169 ;
if ( V_148 == 0 )
break;
V_66 = F_10 ( V_22 + V_68 ) ;
} while ( V_66 & V_174 );
return V_167 - V_166 ;
}
static T_5 F_58 ( int V_175 , void * V_176 )
{
struct V_1 * V_2 = V_176 ;
struct V_177 * V_43 = & V_2 -> V_43 ;
struct V_4 * V_5 = V_2 -> V_5 ;
void T_2 * V_22 = V_2 -> V_22 ;
unsigned long V_38 ;
T_1 V_66 ;
V_66 = F_10 ( V_22 + V_68 ) ;
F_44 ( F_16 ( V_2 -> V_15 ) , L_15 , V_66 ) ;
F_59 ( V_38 ) ;
do {
unsigned int V_148 , V_178 ;
char * V_166 ;
if ( ! ( V_66 & ( V_174 | V_171 ) ) )
break;
if ( ! F_60 ( V_43 ) )
break;
V_166 = V_43 -> V_179 ;
V_148 = V_43 -> V_180 ;
V_178 = 0 ;
if ( V_66 & V_181 )
V_178 = F_53 ( V_2 , V_166 , V_148 ) ;
if ( V_66 & V_182 )
V_178 = F_55 ( V_2 , V_166 , V_148 , V_66 ) ;
V_43 -> V_183 = V_178 ;
V_2 -> V_119 -= V_178 ;
V_148 -= V_178 ;
if ( V_148 )
break;
V_66 = F_10 ( V_22 + V_68 ) ;
} while ( 1 );
F_61 ( V_43 ) ;
F_62 ( V_38 ) ;
if ( V_66 & V_181 && V_2 -> V_119 < V_5 -> V_87 )
F_9 ( V_2 , V_69 ) ;
if ( V_2 -> V_119 == 0 ) {
F_9 ( V_2 , 0 ) ;
F_3 ( F_10 ( V_22 + V_33 ) | V_107 , V_22 + V_33 ) ;
}
return V_184 ;
}
static T_5 F_63 ( int V_175 , void * V_176 )
{
struct V_1 * V_2 = V_176 ;
T_1 V_66 ;
int V_105 = 0 ;
F_8 ( & V_2 -> V_29 ) ;
do {
struct V_133 * V_28 ;
struct V_37 * V_27 ;
V_66 = F_10 ( V_2 -> V_22 + V_68 ) ;
if ( V_2 -> V_31 ) {
if ( V_66 & F_10 ( V_2 -> V_22 + V_35 ) )
F_58 ( V_175 , V_176 ) ;
V_66 &= ~ V_34 ;
}
V_66 &= F_10 ( V_2 -> V_22 + V_33 ) ;
F_3 ( V_66 , V_2 -> V_22 + V_185 ) ;
F_44 ( F_16 ( V_2 -> V_15 ) , L_16 , V_66 ) ;
V_27 = V_2 -> V_27 ;
if ( V_66 & ( V_144 | V_145 | V_146 |
V_147 | V_156 | V_155 ) && V_27 )
F_49 ( V_2 , V_27 , V_66 ) ;
V_28 = V_2 -> V_28 ;
if ( V_66 & ( V_159 | V_158 | V_186 | V_187 ) && V_28 )
F_52 ( V_2 , V_28 , V_66 ) ;
V_105 = 1 ;
} while ( V_66 );
F_6 ( & V_2 -> V_29 ) ;
return F_64 ( V_105 ) ;
}
static void F_65 ( struct V_110 * V_15 , struct V_24 * V_25 )
{
struct V_1 * V_2 = F_41 ( V_15 ) ;
unsigned long V_38 ;
F_66 ( V_2 -> V_25 != NULL ) ;
if ( V_25 -> V_27 && ! F_67 ( V_25 -> V_27 -> V_96 ) ) {
F_20 ( F_16 ( V_15 ) , L_17 ,
V_25 -> V_27 -> V_96 ) ;
V_25 -> V_28 -> error = - V_95 ;
F_7 ( V_15 , V_25 ) ;
return;
}
F_68 ( & V_2 -> V_29 , V_38 ) ;
V_2 -> V_25 = V_25 ;
if ( V_25 -> V_27 )
F_38 ( V_2 , V_25 -> V_27 ) ;
if ( V_25 -> V_27 && V_25 -> V_27 -> V_38 & V_40 )
F_43 ( V_2 , V_25 -> V_27 ) ;
F_48 ( V_2 , V_25 -> V_28 , 0 ) ;
F_69 ( & V_2 -> V_29 , V_38 ) ;
}
static void F_70 ( struct V_110 * V_15 , struct V_188 * V_16 )
{
struct V_1 * V_2 = F_41 ( V_15 ) ;
T_1 V_189 = 0 ;
unsigned long V_38 ;
int V_105 ;
switch ( V_16 -> V_190 ) {
case V_191 :
if ( V_2 -> V_192 )
V_105 = F_71 ( V_15 , V_2 -> V_192 , 0 ) ;
break;
case V_193 :
if ( V_2 -> V_192 ) {
V_105 = F_71 ( V_15 , V_2 -> V_192 , V_16 -> V_194 ) ;
if ( V_105 ) {
F_20 ( F_16 ( V_15 ) , L_18 ) ;
return;
}
}
if ( V_2 -> V_47 -> V_195 )
V_189 |= V_2 -> V_47 -> V_195 ( F_16 ( V_15 ) , V_16 -> V_194 ,
V_16 -> V_190 ) ;
if ( V_2 -> V_196 != V_197 ) {
V_189 |= V_198 ;
break;
}
case V_199 :
V_189 |= V_200 ;
break;
}
if ( V_16 -> V_201 == V_202 ) {
if ( V_2 -> V_196 != V_197 )
V_189 |= V_203 ;
else {
V_189 |= V_204 ;
}
}
F_68 ( & V_2 -> V_29 , V_38 ) ;
F_1 ( V_2 , V_16 -> clock ) ;
if ( V_2 -> V_189 != V_189 ) {
V_2 -> V_189 = V_189 ;
F_3 ( V_189 , V_2 -> V_22 + V_205 ) ;
}
F_69 ( & V_2 -> V_29 , V_38 ) ;
}
static int F_72 ( struct V_110 * V_15 )
{
struct V_1 * V_2 = F_41 ( V_15 ) ;
if ( V_2 -> V_206 == - V_114 )
return - V_114 ;
return F_73 ( V_2 -> V_206 ) ;
}
static int F_74 ( struct V_110 * V_15 )
{
struct V_1 * V_2 = F_41 ( V_15 ) ;
struct V_46 * V_47 = V_2 -> V_47 ;
unsigned int V_66 ;
if ( V_2 -> V_207 == - V_114 ) {
if ( ! V_47 -> V_66 )
return 1 ;
V_66 = V_47 -> V_66 ( F_16 ( V_2 -> V_15 ) ) ;
} else
V_66 = ! ! F_73 ( V_2 -> V_207 )
^ V_47 -> V_208 ;
return V_66 ;
}
static T_5 F_75 ( int V_175 , void * V_176 )
{
struct V_1 * V_2 = V_176 ;
F_76 ( V_2 -> V_15 , F_77 ( 500 ) ) ;
return V_184 ;
}
static int T_3 F_78 ( struct V_209 * V_59 ,
const struct V_210 * V_211 )
{
struct V_46 * V_47 = V_59 -> V_59 . V_212 ;
struct V_4 * V_5 = V_211 -> V_27 ;
struct V_1 * V_2 ;
struct V_110 * V_15 ;
int V_105 ;
if ( ! V_47 ) {
V_105 = - V_95 ;
goto V_213;
}
V_105 = F_79 ( V_59 , V_214 ) ;
if ( V_105 )
goto V_213;
V_15 = F_80 ( sizeof( struct V_1 ) , & V_59 -> V_59 ) ;
if ( ! V_15 ) {
V_105 = - V_103 ;
goto V_215;
}
V_2 = F_41 ( V_15 ) ;
V_2 -> V_15 = V_15 ;
V_2 -> V_206 = - V_114 ;
V_2 -> V_207 = - V_114 ;
V_2 -> V_216 = - 1 ;
V_2 -> V_196 = F_81 ( V_59 ) ;
V_2 -> V_217 = F_82 ( V_59 ) ;
F_44 ( F_16 ( V_15 ) , L_19 , V_2 -> V_196 ) ;
F_44 ( F_16 ( V_15 ) , L_20 , V_2 -> V_217 ) ;
V_2 -> V_6 = F_83 ( & V_59 -> V_59 , NULL ) ;
if ( F_84 ( V_2 -> V_6 ) ) {
V_105 = F_85 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
goto V_218;
}
V_105 = F_86 ( V_2 -> V_6 ) ;
if ( V_105 )
goto V_219;
V_2 -> V_47 = V_47 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_8 = F_87 ( V_2 -> V_6 ) ;
if ( V_2 -> V_8 > 100000000 ) {
V_105 = F_88 ( V_2 -> V_6 , 100000000 ) ;
if ( V_105 < 0 )
goto V_220;
V_2 -> V_8 = F_87 ( V_2 -> V_6 ) ;
F_44 ( F_16 ( V_15 ) , L_21 ,
V_2 -> V_8 ) ;
}
V_2 -> V_80 = V_59 -> V_221 . V_222 ;
V_2 -> V_22 = F_89 ( V_59 -> V_221 . V_222 , F_90 ( & V_59 -> V_221 ) ) ;
if ( ! V_2 -> V_22 ) {
V_105 = - V_103 ;
goto V_220;
}
V_15 -> V_223 = & V_224 ;
if ( V_5 -> V_10 )
V_15 -> V_225 = F_2 ( V_2 -> V_8 , 257 ) ;
else
V_15 -> V_225 = F_2 ( V_2 -> V_8 , 512 ) ;
if ( V_47 -> V_226 )
V_15 -> V_226 = F_56 ( V_2 -> V_8 , V_47 -> V_226 ) ;
else
V_15 -> V_226 = F_56 ( V_2 -> V_8 , V_227 ) ;
F_44 ( F_16 ( V_15 ) , L_22 , V_15 -> V_226 ) ;
#ifdef F_91
V_2 -> V_192 = F_92 ( & V_59 -> V_59 , L_23 ) ;
if ( F_84 ( V_2 -> V_192 ) )
V_2 -> V_192 = NULL ;
else {
int V_30 = F_93 ( V_2 -> V_192 ) ;
if ( V_30 < 0 )
F_20 ( & V_59 -> V_59 , L_24 ,
V_30 ) ;
else {
V_2 -> V_15 -> V_228 = ( T_1 ) V_30 ;
if ( V_47 -> V_229 )
F_21 ( & V_59 -> V_59 ,
L_25
L_26 ) ;
}
}
#endif
if ( V_2 -> V_192 == NULL )
V_15 -> V_228 = V_47 -> V_229 ;
V_15 -> V_230 = V_47 -> V_231 ;
V_15 -> V_232 = V_233 ;
V_15 -> V_234 = ( 1 << V_5 -> V_235 ) - 1 ;
V_15 -> V_60 = V_15 -> V_234 ;
V_15 -> V_236 = 2048 ;
V_15 -> V_237 = V_15 -> V_234 ;
F_94 ( & V_2 -> V_29 ) ;
F_3 ( 0 , V_2 -> V_22 + V_33 ) ;
F_3 ( 0 , V_2 -> V_22 + V_35 ) ;
F_3 ( 0xfff , V_2 -> V_22 + V_185 ) ;
if ( F_95 ( V_47 -> V_207 ) ) {
V_105 = F_96 ( V_47 -> V_207 , V_214 L_27 ) ;
if ( V_105 == 0 )
V_105 = F_97 ( V_47 -> V_207 ) ;
if ( V_105 == 0 )
V_2 -> V_207 = V_47 -> V_207 ;
else if ( V_105 != - V_114 )
goto V_238;
V_105 = F_98 ( F_99 ( V_47 -> V_207 ) ,
F_75 ,
V_239 | V_240 ,
V_214 L_27 , V_2 ) ;
if ( V_105 >= 0 )
V_2 -> V_216 = F_99 ( V_47 -> V_207 ) ;
}
if ( F_95 ( V_47 -> V_206 ) ) {
V_105 = F_96 ( V_47 -> V_206 , V_214 L_28 ) ;
if ( V_105 == 0 )
V_105 = F_97 ( V_47 -> V_206 ) ;
if ( V_105 == 0 )
V_2 -> V_206 = V_47 -> V_206 ;
else if ( V_105 != - V_114 )
goto V_241;
}
if ( ( V_2 -> V_47 -> V_66 || V_2 -> V_207 != - V_114 )
&& V_2 -> V_216 < 0 )
V_15 -> V_230 |= V_242 ;
V_105 = F_100 ( V_59 -> V_175 [ 0 ] , F_63 , V_243 , V_214 L_29 , V_2 ) ;
if ( V_105 )
goto V_244;
if ( V_59 -> V_175 [ 1 ] == V_245 )
V_2 -> V_31 = true ;
else {
V_105 = F_100 ( V_59 -> V_175 [ 1 ] , F_58 , V_243 ,
V_214 L_30 , V_2 ) ;
if ( V_105 )
goto V_246;
}
F_3 ( V_247 , V_2 -> V_22 + V_33 ) ;
F_101 ( V_59 , V_15 ) ;
F_15 ( & V_59 -> V_59 , L_31 ,
F_102 ( V_15 ) , F_103 ( V_59 ) , F_81 ( V_59 ) ,
F_82 ( V_59 ) , ( unsigned long long ) V_59 -> V_221 . V_222 ,
V_59 -> V_175 [ 0 ] , V_59 -> V_175 [ 1 ] ) ;
F_14 ( V_2 ) ;
F_104 ( V_15 ) ;
return 0 ;
V_246:
F_105 ( V_59 -> V_175 [ 0 ] , V_2 ) ;
V_244:
if ( V_2 -> V_206 != - V_114 )
F_106 ( V_2 -> V_206 ) ;
V_241:
if ( V_2 -> V_216 >= 0 )
F_105 ( V_2 -> V_216 , V_2 ) ;
if ( V_2 -> V_207 != - V_114 )
F_106 ( V_2 -> V_207 ) ;
V_238:
F_107 ( V_2 -> V_22 ) ;
V_220:
V_220 ( V_2 -> V_6 ) ;
V_219:
F_108 ( V_2 -> V_6 ) ;
V_218:
F_109 ( V_15 ) ;
V_215:
F_110 ( V_59 ) ;
V_213:
return V_105 ;
}
static int T_6 F_111 ( struct V_209 * V_59 )
{
struct V_110 * V_15 = F_112 ( V_59 ) ;
F_101 ( V_59 , NULL ) ;
if ( V_15 ) {
struct V_1 * V_2 = F_41 ( V_15 ) ;
F_113 ( V_15 ) ;
F_3 ( 0 , V_2 -> V_22 + V_33 ) ;
F_3 ( 0 , V_2 -> V_22 + V_35 ) ;
F_3 ( 0 , V_2 -> V_22 + V_26 ) ;
F_3 ( 0 , V_2 -> V_22 + V_36 ) ;
F_24 ( V_2 ) ;
F_105 ( V_59 -> V_175 [ 0 ] , V_2 ) ;
if ( ! V_2 -> V_31 )
F_105 ( V_59 -> V_175 [ 1 ] , V_2 ) ;
if ( V_2 -> V_206 != - V_114 )
F_106 ( V_2 -> V_206 ) ;
if ( V_2 -> V_216 >= 0 )
F_105 ( V_2 -> V_216 , V_2 ) ;
if ( V_2 -> V_207 != - V_114 )
F_106 ( V_2 -> V_207 ) ;
F_107 ( V_2 -> V_22 ) ;
V_220 ( V_2 -> V_6 ) ;
F_108 ( V_2 -> V_6 ) ;
if ( V_2 -> V_192 )
F_71 ( V_15 , V_2 -> V_192 , 0 ) ;
F_114 ( V_2 -> V_192 ) ;
F_109 ( V_15 ) ;
F_110 ( V_59 ) ;
}
return 0 ;
}
static int F_115 ( struct V_209 * V_59 , T_7 V_248 )
{
struct V_110 * V_15 = F_112 ( V_59 ) ;
int V_105 = 0 ;
if ( V_15 ) {
struct V_1 * V_2 = F_41 ( V_15 ) ;
V_105 = F_116 ( V_15 ) ;
if ( V_105 == 0 )
F_3 ( 0 , V_2 -> V_22 + V_33 ) ;
}
return V_105 ;
}
static int F_117 ( struct V_209 * V_59 )
{
struct V_110 * V_15 = F_112 ( V_59 ) ;
int V_105 = 0 ;
if ( V_15 ) {
struct V_1 * V_2 = F_41 ( V_15 ) ;
F_3 ( V_247 , V_2 -> V_22 + V_33 ) ;
V_105 = F_118 ( V_15 ) ;
}
return V_105 ;
}
static int T_8 F_119 ( void )
{
return F_120 ( & V_249 ) ;
}
static void T_9 F_121 ( void )
{
F_122 ( & V_249 ) ;
}
