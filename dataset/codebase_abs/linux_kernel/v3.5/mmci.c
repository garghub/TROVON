static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_4 != V_3 ) {
V_2 -> V_4 = V_3 ;
F_2 ( V_3 , V_2 -> V_5 + V_6 ) ;
}
}
static void F_3 ( struct V_1 * V_2 , T_1 V_7 )
{
if ( V_2 -> V_8 != V_7 ) {
V_2 -> V_8 = V_7 ;
F_2 ( V_7 , V_2 -> V_5 + V_9 ) ;
}
}
static void F_4 ( struct V_1 * V_2 , unsigned int V_10 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
T_1 V_3 = V_12 -> V_13 ;
if ( V_10 ) {
if ( V_10 >= V_2 -> V_14 ) {
V_3 = V_15 ;
if ( V_12 -> V_16 )
V_3 |= V_17 ;
V_2 -> V_18 = V_2 -> V_14 ;
} else if ( V_12 -> V_16 ) {
V_3 = F_5 ( V_2 -> V_14 , V_10 ) - 2 ;
if ( V_3 >= 256 )
V_3 = 255 ;
V_2 -> V_18 = V_2 -> V_14 / ( V_3 + 2 ) ;
} else {
V_3 = V_2 -> V_14 / ( 2 * V_10 ) - 1 ;
if ( V_3 >= 256 )
V_3 = 255 ;
V_2 -> V_18 = V_2 -> V_14 / ( 2 * ( V_3 + 1 ) ) ;
}
V_3 |= V_12 -> V_19 ;
V_3 |= V_20 ;
}
if ( V_2 -> V_21 -> V_22 . V_23 == V_24 )
V_3 |= V_25 ;
if ( V_2 -> V_21 -> V_22 . V_23 == V_26 )
V_3 |= V_27 ;
F_1 ( V_2 , V_3 ) ;
}
static void
F_6 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
F_2 ( 0 , V_2 -> V_5 + V_30 ) ;
F_7 ( V_2 -> V_31 ) ;
V_2 -> V_29 = NULL ;
V_2 -> V_32 = NULL ;
F_8 ( V_2 -> V_21 , V_29 ) ;
F_9 ( F_10 ( V_2 -> V_21 ) ) ;
F_11 ( F_10 ( V_2 -> V_21 ) ) ;
}
static void F_12 ( struct V_1 * V_2 , unsigned int V_33 )
{
void T_2 * V_5 = V_2 -> V_5 ;
if ( V_2 -> V_34 ) {
unsigned int V_35 = F_13 ( V_5 + V_36 ) ;
V_35 &= ~ V_37 ;
V_35 |= V_33 ;
F_2 ( V_35 , V_5 + V_36 ) ;
}
F_2 ( V_33 , V_5 + V_38 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_2 -> V_5 + V_39 ) ;
F_12 ( V_2 , 0 ) ;
V_2 -> V_31 = NULL ;
}
static void F_15 ( struct V_1 * V_2 , struct V_40 * V_31 )
{
unsigned int V_41 = V_42 ;
if ( V_31 -> V_41 & V_43 )
V_41 |= V_44 ;
else
V_41 |= V_45 ;
F_16 ( & V_2 -> V_46 , V_31 -> V_47 , V_31 -> V_48 , V_41 ) ;
}
static void T_3 F_17 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = V_2 -> V_50 ;
const char * V_51 , * V_52 ;
T_4 V_33 ;
if ( ! V_50 || ! V_50 -> V_53 ) {
F_18 ( F_10 ( V_2 -> V_21 ) , L_1 ) ;
return;
}
V_2 -> V_54 . V_55 = 1 ;
F_19 ( V_33 ) ;
F_20 ( V_56 , V_33 ) ;
if ( V_50 -> V_57 ) {
V_2 -> V_58 = F_21 ( V_33 ,
V_50 -> V_53 ,
V_50 -> V_57 ) ;
if ( ! V_2 -> V_58 )
F_22 ( F_10 ( V_2 -> V_21 ) , L_2 ) ;
}
if ( V_50 -> V_59 ) {
V_2 -> V_60 = F_21 ( V_33 ,
V_50 -> V_53 ,
V_50 -> V_59 ) ;
if ( ! V_2 -> V_60 )
F_23 ( F_10 ( V_2 -> V_21 ) , L_3 ) ;
} else {
V_2 -> V_60 = V_2 -> V_58 ;
}
if ( V_2 -> V_58 )
V_51 = F_24 ( V_2 -> V_58 ) ;
else
V_51 = L_4 ;
if ( V_2 -> V_60 )
V_52 = F_24 ( V_2 -> V_60 ) ;
else
V_52 = L_4 ;
F_18 ( F_10 ( V_2 -> V_21 ) , L_5 ,
V_51 , V_52 ) ;
if ( V_2 -> V_60 ) {
struct V_61 * V_62 = V_2 -> V_60 -> V_61 -> V_62 ;
unsigned int V_63 = F_25 ( V_62 ) ;
if ( V_63 < V_2 -> V_21 -> V_63 )
V_2 -> V_21 -> V_63 = V_63 ;
}
if ( V_2 -> V_58 ) {
struct V_61 * V_62 = V_2 -> V_58 -> V_61 -> V_62 ;
unsigned int V_63 = F_25 ( V_62 ) ;
if ( V_63 < V_2 -> V_21 -> V_63 )
V_2 -> V_21 -> V_63 = V_63 ;
}
}
static inline void F_26 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = V_2 -> V_50 ;
if ( V_2 -> V_58 )
F_27 ( V_2 -> V_58 ) ;
if ( V_2 -> V_60 && V_50 -> V_59 )
F_27 ( V_2 -> V_60 ) ;
V_2 -> V_58 = V_2 -> V_60 = NULL ;
}
static void F_28 ( struct V_1 * V_2 , struct V_40 * V_31 )
{
struct V_64 * V_65 = V_2 -> V_66 ;
enum V_67 V_68 ;
T_1 V_69 ;
int V_70 ;
for ( V_70 = 0 ; ; V_70 ++ ) {
V_69 = F_13 ( V_2 -> V_5 + V_71 ) ;
if ( ! ( V_69 & V_72 ) || V_70 >= 100 )
break;
F_29 ( 10 ) ;
}
if ( V_69 & V_72 ) {
F_30 ( V_65 ) ;
if ( ! V_31 -> error )
V_31 -> error = - V_73 ;
}
if ( V_31 -> V_41 & V_74 ) {
V_68 = V_75 ;
} else {
V_68 = V_76 ;
}
if ( ! V_31 -> V_77 )
F_31 ( V_65 -> V_61 -> V_62 , V_31 -> V_47 , V_31 -> V_48 , V_68 ) ;
if ( V_69 & V_72 ) {
F_22 ( F_10 ( V_2 -> V_21 ) , L_6 ) ;
F_26 ( V_2 ) ;
}
}
static void F_32 ( struct V_1 * V_2 )
{
F_22 ( F_10 ( V_2 -> V_21 ) , L_7 ) ;
F_30 ( V_2 -> V_66 ) ;
}
static int F_33 ( struct V_1 * V_2 , struct V_40 * V_31 ,
struct V_78 * V_79 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
struct V_80 V_81 = {
. V_82 = V_2 -> V_83 + V_84 ,
. V_85 = V_2 -> V_83 + V_84 ,
. V_86 = V_87 ,
. V_88 = V_87 ,
. V_89 = V_12 -> V_90 >> 2 ,
. V_91 = V_12 -> V_90 >> 2 ,
. V_92 = false ,
} ;
struct V_64 * V_65 ;
struct V_93 * V_61 ;
struct V_94 * V_95 ;
enum V_67 V_96 ;
int V_97 ;
if ( V_31 -> V_77 && ! V_79 &&
V_2 -> V_66 && V_2 -> V_98 )
return 0 ;
if ( ! V_79 ) {
V_2 -> V_66 = NULL ;
V_2 -> V_98 = NULL ;
}
if ( V_31 -> V_41 & V_43 ) {
V_81 . V_99 = V_100 ;
V_96 = V_76 ;
V_65 = V_2 -> V_58 ;
} else {
V_81 . V_99 = V_101 ;
V_96 = V_75 ;
V_65 = V_2 -> V_60 ;
}
if ( ! V_65 )
return - V_102 ;
if ( V_31 -> V_103 * V_31 -> V_104 <= V_12 -> V_105 )
return - V_102 ;
V_61 = V_65 -> V_61 ;
V_97 = F_34 ( V_61 -> V_62 , V_31 -> V_47 , V_31 -> V_48 , V_96 ) ;
if ( V_97 == 0 )
return - V_102 ;
F_35 ( V_65 , & V_81 ) ;
V_95 = F_36 ( V_65 , V_31 -> V_47 , V_97 ,
V_81 . V_99 , V_106 ) ;
if ( ! V_95 )
goto V_107;
if ( V_79 ) {
V_79 -> V_64 = V_65 ;
V_79 -> V_108 = V_95 ;
} else {
V_2 -> V_66 = V_65 ;
V_2 -> V_98 = V_95 ;
}
return 0 ;
V_107:
if ( ! V_79 )
F_30 ( V_65 ) ;
F_31 ( V_61 -> V_62 , V_31 -> V_47 , V_31 -> V_48 , V_96 ) ;
return - V_109 ;
}
static int F_37 ( struct V_1 * V_2 , unsigned int V_110 )
{
int V_111 ;
struct V_40 * V_31 = V_2 -> V_31 ;
V_111 = F_33 ( V_2 , V_2 -> V_31 , NULL ) ;
if ( V_111 )
return V_111 ;
F_38 ( F_10 ( V_2 -> V_21 ) ,
L_8 ,
V_31 -> V_48 , V_31 -> V_103 , V_31 -> V_104 , V_31 -> V_41 ) ;
F_39 ( V_2 -> V_98 ) ;
F_40 ( V_2 -> V_66 ) ;
V_110 |= V_112 ;
F_2 ( V_110 , V_2 -> V_5 + V_39 ) ;
F_2 ( F_13 ( V_2 -> V_5 + V_36 ) | V_113 ,
V_2 -> V_5 + V_36 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 , struct V_40 * V_31 )
{
struct V_78 * V_79 = & V_2 -> V_54 ;
if ( V_31 -> V_77 && V_31 -> V_77 != V_79 -> V_55 ) {
F_42 ( L_9
L_10 ,
V_114 , V_31 -> V_77 , V_2 -> V_54 . V_55 ) ;
V_31 -> V_77 = 0 ;
}
if ( ! V_31 -> V_77 )
return;
V_2 -> V_98 = V_79 -> V_108 ;
V_2 -> V_66 = V_79 -> V_64 ;
V_79 -> V_108 = NULL ;
V_79 -> V_64 = NULL ;
}
static void F_43 ( struct V_115 * V_21 , struct V_28 * V_29 ,
bool V_116 )
{
struct V_1 * V_2 = F_44 ( V_21 ) ;
struct V_40 * V_31 = V_29 -> V_31 ;
struct V_78 * V_117 = & V_2 -> V_54 ;
if ( ! V_31 )
return;
if ( V_31 -> V_77 ) {
V_31 -> V_77 = 0 ;
return;
}
if ( ( ( V_31 -> V_41 & V_74 ) && V_2 -> V_60 ) ||
( ( V_31 -> V_41 & V_43 ) && V_2 -> V_58 ) ) {
if ( F_33 ( V_2 , V_31 , V_117 ) )
V_31 -> V_77 = 0 ;
else
V_31 -> V_77 = ++ V_117 -> V_55 < 0 ? 1 : V_117 -> V_55 ;
}
}
static void F_45 ( struct V_115 * V_21 , struct V_28 * V_29 ,
int V_118 )
{
struct V_1 * V_2 = F_44 ( V_21 ) ;
struct V_40 * V_31 = V_29 -> V_31 ;
struct V_64 * V_65 ;
enum V_67 V_68 ;
if ( ! V_31 )
return;
if ( V_31 -> V_41 & V_43 ) {
V_68 = V_76 ;
V_65 = V_2 -> V_58 ;
} else {
V_68 = V_75 ;
V_65 = V_2 -> V_60 ;
}
if ( V_65 ) {
if ( V_118 )
F_30 ( V_65 ) ;
if ( V_31 -> V_77 )
F_31 ( F_10 ( V_2 -> V_21 ) , V_31 -> V_47 ,
V_31 -> V_48 , V_68 ) ;
V_29 -> V_31 -> V_77 = 0 ;
}
}
static void F_41 ( struct V_1 * V_2 , struct V_40 * V_31 )
{
}
static inline void F_17 ( struct V_1 * V_2 )
{
}
static inline void F_26 ( struct V_1 * V_2 )
{
}
static inline void F_28 ( struct V_1 * V_2 , struct V_40 * V_31 )
{
}
static inline void F_32 ( struct V_1 * V_2 )
{
}
static inline int F_37 ( struct V_1 * V_2 , unsigned int V_110 )
{
return - V_119 ;
}
static void F_46 ( struct V_1 * V_2 , struct V_40 * V_31 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
unsigned int V_110 , V_120 , V_121 ;
unsigned long long V_122 ;
void T_2 * V_5 ;
int V_123 ;
F_47 ( F_10 ( V_2 -> V_21 ) , L_11 ,
V_31 -> V_103 , V_31 -> V_104 , V_31 -> V_41 ) ;
V_2 -> V_31 = V_31 ;
V_2 -> V_124 = V_31 -> V_103 * V_31 -> V_104 ;
V_31 -> V_125 = 0 ;
V_122 = ( unsigned long long ) V_31 -> V_126 * V_2 -> V_18 ;
F_48 ( V_122 , 1000000000UL ) ;
V_120 = V_31 -> V_127 + ( unsigned int ) V_122 ;
V_5 = V_2 -> V_5 ;
F_2 ( V_120 , V_5 + V_128 ) ;
F_2 ( V_2 -> V_124 , V_5 + V_129 ) ;
V_123 = F_49 ( V_31 -> V_103 ) - 1 ;
F_7 ( 1 << V_123 != V_31 -> V_103 ) ;
if ( V_12 -> V_130 )
V_110 = V_131 | ( V_31 -> V_103 << 16 ) ;
else
V_110 = V_131 | V_123 << 4 ;
if ( V_31 -> V_41 & V_43 )
V_110 |= V_132 ;
if ( V_12 -> V_133 && V_2 -> V_21 -> V_134 )
if ( F_50 ( V_2 -> V_21 -> V_134 ) )
V_110 |= V_135 ;
if ( ! F_37 ( V_2 , V_110 ) )
return;
F_15 ( V_2 , V_31 ) ;
if ( V_31 -> V_41 & V_43 ) {
V_121 = V_136 ;
if ( V_2 -> V_124 < V_12 -> V_90 )
V_121 |= V_72 ;
} else {
V_121 = V_137 ;
}
F_2 ( V_110 , V_5 + V_39 ) ;
F_2 ( F_13 ( V_5 + V_36 ) & ~ V_113 , V_5 + V_36 ) ;
F_12 ( V_2 , V_121 ) ;
}
static void
F_51 ( struct V_1 * V_2 , struct V_138 * V_32 , T_1 V_139 )
{
void T_2 * V_5 = V_2 -> V_5 ;
F_47 ( F_10 ( V_2 -> V_21 ) , L_12 ,
V_32 -> V_140 , V_32 -> V_141 , V_32 -> V_41 ) ;
if ( F_13 ( V_5 + V_30 ) & V_142 ) {
F_2 ( 0 , V_5 + V_30 ) ;
F_29 ( 1 ) ;
}
V_139 |= V_32 -> V_140 | V_142 ;
if ( V_32 -> V_41 & V_143 ) {
if ( V_32 -> V_41 & V_144 )
V_139 |= V_145 ;
V_139 |= V_146 ;
}
if ( 0 )
V_139 |= V_147 ;
V_2 -> V_32 = V_32 ;
F_2 ( V_32 -> V_141 , V_5 + V_148 ) ;
F_2 ( V_139 , V_5 + V_30 ) ;
}
static void
F_52 ( struct V_1 * V_2 , struct V_40 * V_31 ,
unsigned int V_69 )
{
if ( V_69 & ( V_149 | V_150 | V_151 |
V_152 | V_153 ) ) {
T_1 V_154 , V_155 ;
if ( F_53 ( V_2 ) )
F_32 ( V_2 ) ;
V_154 = F_13 ( V_2 -> V_5 + V_156 ) ;
V_155 = V_31 -> V_103 * V_31 -> V_104 - V_154 ;
F_47 ( F_10 ( V_2 -> V_21 ) , L_13 ,
V_69 , V_155 ) ;
if ( V_69 & V_149 ) {
V_155 -= 1 ;
V_31 -> error = - V_157 ;
} else if ( V_69 & V_150 ) {
V_31 -> error = - V_158 ;
} else if ( V_69 & V_151 ) {
V_31 -> error = - V_159 ;
} else if ( V_69 & V_152 ) {
V_31 -> error = - V_73 ;
} else if ( V_69 & V_153 ) {
if ( V_155 > V_2 -> V_12 -> V_105 )
V_155 -= V_2 -> V_12 -> V_105 ;
else
V_155 = 0 ;
V_31 -> error = - V_73 ;
}
V_31 -> V_125 = F_54 ( V_155 , V_31 -> V_103 ) ;
}
if ( V_69 & V_160 )
F_22 ( F_10 ( V_2 -> V_21 ) , L_14 ) ;
if ( V_69 & V_161 || V_31 -> error ) {
if ( F_53 ( V_2 ) )
F_28 ( V_2 , V_31 ) ;
F_14 ( V_2 ) ;
if ( ! V_31 -> error )
V_31 -> V_125 = V_31 -> V_103 * V_31 -> V_104 ;
if ( ! V_31 -> V_162 ) {
F_6 ( V_2 , V_31 -> V_29 ) ;
} else {
F_51 ( V_2 , V_31 -> V_162 , 0 ) ;
}
}
}
static void
F_55 ( struct V_1 * V_2 , struct V_138 * V_32 ,
unsigned int V_69 )
{
void T_2 * V_5 = V_2 -> V_5 ;
V_2 -> V_32 = NULL ;
if ( V_69 & V_163 ) {
V_32 -> error = - V_158 ;
} else if ( V_69 & V_164 && V_32 -> V_41 & V_165 ) {
V_32 -> error = - V_157 ;
} else {
V_32 -> V_166 [ 0 ] = F_13 ( V_5 + V_167 ) ;
V_32 -> V_166 [ 1 ] = F_13 ( V_5 + V_168 ) ;
V_32 -> V_166 [ 2 ] = F_13 ( V_5 + V_169 ) ;
V_32 -> V_166 [ 3 ] = F_13 ( V_5 + V_170 ) ;
}
if ( ! V_32 -> V_31 || V_32 -> error ) {
if ( V_2 -> V_31 ) {
if ( F_53 ( V_2 ) )
F_32 ( V_2 ) ;
F_14 ( V_2 ) ;
}
F_6 ( V_2 , V_32 -> V_29 ) ;
} else if ( ! ( V_32 -> V_31 -> V_41 & V_43 ) ) {
F_46 ( V_2 , V_32 -> V_31 ) ;
}
}
static int F_56 ( struct V_1 * V_2 , char * V_171 , unsigned int V_154 )
{
void T_2 * V_5 = V_2 -> V_5 ;
char * V_172 = V_171 ;
T_1 V_69 ;
int V_173 = V_2 -> V_124 ;
do {
int V_174 = V_173 - ( F_13 ( V_5 + V_175 ) << 2 ) ;
if ( V_174 > V_154 )
V_174 = V_154 ;
if ( V_174 <= 0 )
break;
if ( F_57 ( V_174 & 0x3 ) ) {
if ( V_174 < 4 ) {
unsigned char V_176 [ 4 ] ;
F_58 ( V_5 + V_84 , V_176 , 1 ) ;
memcpy ( V_172 , V_176 , V_174 ) ;
} else {
F_58 ( V_5 + V_84 , V_172 , V_174 >> 2 ) ;
V_174 &= ~ 0x3 ;
}
} else {
F_58 ( V_5 + V_84 , V_172 , V_174 >> 2 ) ;
}
V_172 += V_174 ;
V_154 -= V_174 ;
V_173 -= V_174 ;
if ( V_154 == 0 )
break;
V_69 = F_13 ( V_5 + V_71 ) ;
} while ( V_69 & V_177 );
return V_172 - V_171 ;
}
static int F_59 ( struct V_1 * V_2 , char * V_171 , unsigned int V_154 , T_1 V_69 )
{
struct V_11 * V_12 = V_2 -> V_12 ;
void T_2 * V_5 = V_2 -> V_5 ;
char * V_172 = V_171 ;
do {
unsigned int V_174 , V_178 ;
V_178 = V_69 & V_179 ?
V_12 -> V_105 : V_12 -> V_90 ;
V_174 = F_60 ( V_154 , V_178 ) ;
if ( V_12 -> V_133 &&
F_50 ( V_2 -> V_21 -> V_134 ) ) {
T_1 V_3 ;
if ( V_174 < 8 )
V_3 = V_2 -> V_4 & ~ V_12 -> V_19 ;
else
V_3 = V_2 -> V_4 | V_12 -> V_19 ;
F_1 ( V_2 , V_3 ) ;
}
F_61 ( V_5 + V_84 , V_172 , ( V_174 + 3 ) >> 2 ) ;
V_172 += V_174 ;
V_154 -= V_174 ;
if ( V_154 == 0 )
break;
V_69 = F_13 ( V_5 + V_71 ) ;
} while ( V_69 & V_180 );
return V_172 - V_171 ;
}
static T_5 F_62 ( int V_181 , void * V_182 )
{
struct V_1 * V_2 = V_182 ;
struct V_183 * V_46 = & V_2 -> V_46 ;
struct V_11 * V_12 = V_2 -> V_12 ;
void T_2 * V_5 = V_2 -> V_5 ;
unsigned long V_41 ;
T_1 V_69 ;
V_69 = F_13 ( V_5 + V_71 ) ;
F_47 ( F_10 ( V_2 -> V_21 ) , L_15 , V_69 ) ;
F_63 ( V_41 ) ;
do {
unsigned int V_154 , V_184 ;
char * V_171 ;
if ( ! ( V_69 & ( V_180 | V_177 ) ) )
break;
if ( ! F_64 ( V_46 ) )
break;
V_171 = V_46 -> V_185 ;
V_154 = V_46 -> V_186 ;
V_184 = 0 ;
if ( V_69 & V_187 )
V_184 = F_56 ( V_2 , V_171 , V_154 ) ;
if ( V_69 & V_188 )
V_184 = F_59 ( V_2 , V_171 , V_154 , V_69 ) ;
V_46 -> V_189 = V_184 ;
V_2 -> V_124 -= V_184 ;
V_154 -= V_184 ;
if ( V_154 )
break;
V_69 = F_13 ( V_5 + V_71 ) ;
} while ( 1 );
F_65 ( V_46 ) ;
F_66 ( V_41 ) ;
if ( V_69 & V_187 && V_2 -> V_124 < V_12 -> V_90 )
F_12 ( V_2 , V_72 ) ;
if ( V_2 -> V_124 == 0 ) {
F_12 ( V_2 , 0 ) ;
F_2 ( F_13 ( V_5 + V_36 ) | V_113 , V_5 + V_36 ) ;
}
return V_190 ;
}
static T_5 F_67 ( int V_181 , void * V_182 )
{
struct V_1 * V_2 = V_182 ;
T_1 V_69 ;
int V_111 = 0 ;
F_68 ( & V_2 -> V_191 ) ;
do {
struct V_138 * V_32 ;
struct V_40 * V_31 ;
V_69 = F_13 ( V_2 -> V_5 + V_71 ) ;
if ( V_2 -> V_34 ) {
if ( V_69 & F_13 ( V_2 -> V_5 + V_38 ) )
F_62 ( V_181 , V_182 ) ;
V_69 &= ~ V_37 ;
}
V_69 &= F_13 ( V_2 -> V_5 + V_36 ) ;
F_2 ( V_69 , V_2 -> V_5 + V_192 ) ;
F_47 ( F_10 ( V_2 -> V_21 ) , L_16 , V_69 ) ;
V_31 = V_2 -> V_31 ;
if ( V_69 & ( V_149 | V_150 | V_151 |
V_152 | V_153 | V_161 |
V_160 ) && V_31 )
F_52 ( V_2 , V_31 , V_69 ) ;
V_32 = V_2 -> V_32 ;
if ( V_69 & ( V_164 | V_163 | V_193 | V_194 ) && V_32 )
F_55 ( V_2 , V_32 , V_69 ) ;
V_111 = 1 ;
} while ( V_69 );
F_69 ( & V_2 -> V_191 ) ;
return F_70 ( V_111 ) ;
}
static void F_71 ( struct V_115 * V_21 , struct V_28 * V_29 )
{
struct V_1 * V_2 = F_44 ( V_21 ) ;
unsigned long V_41 ;
F_72 ( V_2 -> V_29 != NULL ) ;
if ( V_29 -> V_31 && ! F_73 ( V_29 -> V_31 -> V_103 ) ) {
F_22 ( F_10 ( V_21 ) , L_17 ,
V_29 -> V_31 -> V_103 ) ;
V_29 -> V_32 -> error = - V_102 ;
F_8 ( V_21 , V_29 ) ;
return;
}
F_74 ( F_10 ( V_21 ) ) ;
F_75 ( & V_2 -> V_191 , V_41 ) ;
V_2 -> V_29 = V_29 ;
if ( V_29 -> V_31 )
F_41 ( V_2 , V_29 -> V_31 ) ;
if ( V_29 -> V_31 && V_29 -> V_31 -> V_41 & V_43 )
F_46 ( V_2 , V_29 -> V_31 ) ;
F_51 ( V_2 , V_29 -> V_32 , 0 ) ;
F_76 ( & V_2 -> V_191 , V_41 ) ;
}
static void F_77 ( struct V_115 * V_21 , struct V_195 * V_22 )
{
struct V_1 * V_2 = F_44 ( V_21 ) ;
struct V_11 * V_12 = V_2 -> V_12 ;
T_1 V_7 = 0 ;
unsigned long V_41 ;
int V_111 ;
F_74 ( F_10 ( V_21 ) ) ;
if ( V_2 -> V_50 -> V_196 &&
V_2 -> V_50 -> V_196 ( F_10 ( V_21 ) , V_22 ) )
F_22 ( F_10 ( V_21 ) , L_18 ) ;
switch ( V_22 -> V_197 ) {
case V_198 :
if ( V_2 -> V_199 )
V_111 = F_78 ( V_21 , V_2 -> V_199 , 0 ) ;
break;
case V_200 :
if ( V_2 -> V_199 ) {
V_111 = F_78 ( V_21 , V_2 -> V_199 , V_22 -> V_201 ) ;
if ( V_111 ) {
F_22 ( F_10 ( V_21 ) , L_19 ) ;
goto V_202;
}
}
V_7 |= V_12 -> V_203 ;
break;
case V_204 :
V_7 |= V_205 ;
break;
}
if ( V_12 -> V_206 && V_22 -> V_197 != V_198 ) {
V_7 |= V_2 -> V_50 -> V_207 ;
if ( V_22 -> V_23 == V_24 )
V_7 &= ~ V_208 ;
else if ( V_22 -> V_23 == V_209 )
V_7 &= ( ~ V_208 &
~ V_210 &
~ V_211 ) ;
}
if ( V_22 -> V_212 == V_213 ) {
if ( V_2 -> V_214 != V_215 )
V_7 |= V_216 ;
else {
V_7 |= V_217 ;
}
}
F_75 ( & V_2 -> V_191 , V_41 ) ;
F_4 ( V_2 , V_22 -> clock ) ;
F_3 ( V_2 , V_7 ) ;
F_76 ( & V_2 -> V_191 , V_41 ) ;
V_202:
F_9 ( F_10 ( V_21 ) ) ;
F_11 ( F_10 ( V_21 ) ) ;
}
static int F_79 ( struct V_115 * V_21 )
{
struct V_1 * V_2 = F_44 ( V_21 ) ;
if ( V_2 -> V_218 == - V_119 )
return - V_119 ;
return F_80 ( V_2 -> V_218 ) ;
}
static int F_81 ( struct V_115 * V_21 )
{
struct V_1 * V_2 = F_44 ( V_21 ) ;
struct V_49 * V_50 = V_2 -> V_50 ;
unsigned int V_69 ;
if ( V_2 -> V_219 == - V_119 ) {
if ( ! V_50 -> V_69 )
return 1 ;
V_69 = V_50 -> V_69 ( F_10 ( V_2 -> V_21 ) ) ;
} else
V_69 = ! ! F_80 ( V_2 -> V_219 )
^ V_50 -> V_220 ;
return V_69 ;
}
static T_5 F_82 ( int V_181 , void * V_182 )
{
struct V_1 * V_2 = V_182 ;
F_83 ( V_2 -> V_21 , F_84 ( 500 ) ) ;
return V_190 ;
}
static void F_85 ( struct V_221 * V_222 ,
struct V_49 * V_223 )
{
int V_23 = 0 ;
V_223 -> V_218 = F_86 ( V_222 , L_20 , 0 ) ;
V_223 -> V_219 = F_86 ( V_222 , L_21 , 0 ) ;
if ( F_87 ( V_222 , L_22 , NULL ) )
V_223 -> V_220 = true ;
else
V_223 -> V_220 = false ;
F_88 ( V_222 , L_23 , & V_223 -> V_224 ) ;
if ( ! V_223 -> V_224 )
F_89 ( L_24 , V_222 -> V_225 ) ;
if ( F_87 ( V_222 , L_25 , NULL ) )
V_223 -> V_226 |= V_227 ;
if ( F_87 ( V_222 , L_26 , NULL ) )
V_223 -> V_226 |= V_228 ;
F_88 ( V_222 , L_27 , & V_23 ) ;
switch ( V_23 ) {
case 0 :
break;
case 4 :
V_223 -> V_226 |= V_229 ;
break;
case 8 :
V_223 -> V_226 |= V_230 ;
break;
default :
F_89 ( L_28 , V_222 -> V_225 ) ;
}
}
static void F_85 ( struct V_221 * V_222 ,
struct V_49 * V_223 )
{
return;
}
static int T_3 F_90 ( struct V_231 * V_62 ,
const struct V_232 * V_233 )
{
struct V_49 * V_50 = V_62 -> V_62 . V_234 ;
struct V_221 * V_222 = V_62 -> V_62 . V_235 ;
struct V_11 * V_12 = V_233 -> V_31 ;
struct V_1 * V_2 ;
struct V_115 * V_21 ;
int V_111 ;
if ( ! V_50 && ! V_222 ) {
F_22 ( & V_62 -> V_62 , L_29 ) ;
return - V_102 ;
}
if ( ! V_50 ) {
V_50 = F_91 ( & V_62 -> V_62 , sizeof( * V_50 ) , V_236 ) ;
if ( ! V_50 )
return - V_109 ;
}
if ( V_222 )
F_85 ( V_222 , V_50 ) ;
V_111 = F_92 ( V_62 , V_237 ) ;
if ( V_111 )
goto V_202;
V_21 = F_93 ( sizeof( struct V_1 ) , & V_62 -> V_62 ) ;
if ( ! V_21 ) {
V_111 = - V_109 ;
goto V_238;
}
V_2 = F_44 ( V_21 ) ;
V_2 -> V_21 = V_21 ;
V_2 -> V_218 = - V_119 ;
V_2 -> V_219 = - V_119 ;
V_2 -> V_239 = - 1 ;
V_2 -> V_214 = F_94 ( V_62 ) ;
V_2 -> V_240 = F_95 ( V_62 ) ;
F_47 ( F_10 ( V_21 ) , L_30 , V_2 -> V_214 ) ;
F_47 ( F_10 ( V_21 ) , L_31 , V_2 -> V_240 ) ;
V_2 -> V_3 = F_96 ( & V_62 -> V_62 , NULL ) ;
if ( F_97 ( V_2 -> V_3 ) ) {
V_111 = F_98 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
goto V_241;
}
V_111 = F_99 ( V_2 -> V_3 ) ;
if ( V_111 )
goto V_242;
V_111 = F_100 ( V_2 -> V_3 ) ;
if ( V_111 )
goto V_243;
V_2 -> V_50 = V_50 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_14 = F_101 ( V_2 -> V_3 ) ;
if ( V_2 -> V_14 > 100000000 ) {
V_111 = F_102 ( V_2 -> V_3 , 100000000 ) ;
if ( V_111 < 0 )
goto V_244;
V_2 -> V_14 = F_101 ( V_2 -> V_3 ) ;
F_47 ( F_10 ( V_21 ) , L_32 ,
V_2 -> V_14 ) ;
}
V_2 -> V_83 = V_62 -> V_245 . V_246 ;
V_2 -> V_5 = F_103 ( V_62 -> V_245 . V_246 , F_104 ( & V_62 -> V_245 ) ) ;
if ( ! V_2 -> V_5 ) {
V_111 = - V_109 ;
goto V_244;
}
V_21 -> V_247 = & V_248 ;
if ( V_12 -> V_16 )
V_21 -> V_249 = F_5 ( V_2 -> V_14 , 257 ) ;
else
V_21 -> V_249 = F_5 ( V_2 -> V_14 , 512 ) ;
if ( V_50 -> V_224 )
V_21 -> V_224 = F_60 ( V_2 -> V_14 , V_50 -> V_224 ) ;
else
V_21 -> V_224 = F_60 ( V_2 -> V_14 , V_250 ) ;
F_47 ( F_10 ( V_21 ) , L_33 , V_21 -> V_224 ) ;
#ifdef F_105
V_2 -> V_199 = F_106 ( & V_62 -> V_62 , L_34 ) ;
if ( F_97 ( V_2 -> V_199 ) )
V_2 -> V_199 = NULL ;
else {
int V_33 = F_107 ( V_2 -> V_199 ) ;
if ( V_33 < 0 )
F_22 ( & V_62 -> V_62 , L_35 ,
V_33 ) ;
else {
V_2 -> V_21 -> V_251 = ( T_1 ) V_33 ;
if ( V_50 -> V_252 )
F_23 ( & V_62 -> V_62 ,
L_36
L_37 ) ;
}
}
#endif
if ( V_2 -> V_199 == NULL )
V_21 -> V_251 = V_50 -> V_252 ;
V_21 -> V_253 = V_50 -> V_226 ;
V_21 -> V_254 = V_50 -> V_255 ;
V_21 -> V_256 = V_257 ;
V_21 -> V_258 = ( 1 << V_12 -> V_259 ) - 1 ;
V_21 -> V_63 = V_21 -> V_258 ;
V_21 -> V_260 = 1 << 11 ;
V_21 -> V_261 = V_21 -> V_258 >> 11 ;
F_108 ( & V_2 -> V_191 ) ;
F_2 ( 0 , V_2 -> V_5 + V_36 ) ;
F_2 ( 0 , V_2 -> V_5 + V_38 ) ;
F_2 ( 0xfff , V_2 -> V_5 + V_192 ) ;
if ( V_50 -> V_219 == - V_262 ) {
V_111 = - V_262 ;
goto V_263;
}
if ( F_109 ( V_50 -> V_219 ) ) {
V_111 = F_110 ( V_50 -> V_219 , V_237 L_38 ) ;
if ( V_111 == 0 )
V_111 = F_111 ( V_50 -> V_219 ) ;
if ( V_111 == 0 )
V_2 -> V_219 = V_50 -> V_219 ;
else if ( V_111 != - V_119 )
goto V_263;
V_111 = F_112 ( F_113 ( V_50 -> V_219 ) ,
F_82 ,
V_264 | V_265 ,
V_237 L_38 , V_2 ) ;
if ( V_111 >= 0 )
V_2 -> V_239 = F_113 ( V_50 -> V_219 ) ;
}
if ( V_50 -> V_218 == - V_262 ) {
V_111 = - V_262 ;
goto V_266;
}
if ( F_109 ( V_50 -> V_218 ) ) {
V_111 = F_110 ( V_50 -> V_218 , V_237 L_39 ) ;
if ( V_111 == 0 )
V_111 = F_111 ( V_50 -> V_218 ) ;
if ( V_111 == 0 )
V_2 -> V_218 = V_50 -> V_218 ;
else if ( V_111 != - V_119 )
goto V_266;
}
if ( ( V_2 -> V_50 -> V_69 || V_2 -> V_219 != - V_119 )
&& V_2 -> V_239 < 0 )
V_21 -> V_253 |= V_267 ;
V_111 = F_114 ( V_62 -> V_181 [ 0 ] , F_67 , V_268 , V_237 L_40 , V_2 ) ;
if ( V_111 )
goto V_269;
if ( ! V_62 -> V_181 [ 1 ] )
V_2 -> V_34 = true ;
else {
V_111 = F_114 ( V_62 -> V_181 [ 1 ] , F_62 , V_268 ,
V_237 L_41 , V_2 ) ;
if ( V_111 )
goto V_270;
}
F_2 ( V_271 , V_2 -> V_5 + V_36 ) ;
F_115 ( V_62 , V_21 ) ;
F_18 ( & V_62 -> V_62 , L_42 ,
F_116 ( V_21 ) , F_117 ( V_62 ) , F_94 ( V_62 ) ,
F_95 ( V_62 ) , ( unsigned long long ) V_62 -> V_245 . V_246 ,
V_62 -> V_181 [ 0 ] , V_62 -> V_181 [ 1 ] ) ;
F_17 ( V_2 ) ;
F_118 ( & V_62 -> V_62 , 50 ) ;
F_119 ( & V_62 -> V_62 ) ;
F_120 ( & V_62 -> V_62 ) ;
F_121 ( V_21 ) ;
return 0 ;
V_270:
F_122 ( V_62 -> V_181 [ 0 ] , V_2 ) ;
V_269:
if ( V_2 -> V_218 != - V_119 )
F_123 ( V_2 -> V_218 ) ;
V_266:
if ( V_2 -> V_239 >= 0 )
F_122 ( V_2 -> V_239 , V_2 ) ;
if ( V_2 -> V_219 != - V_119 )
F_123 ( V_2 -> V_219 ) ;
V_263:
F_124 ( V_2 -> V_5 ) ;
V_244:
V_244 ( V_2 -> V_3 ) ;
V_243:
F_125 ( V_2 -> V_3 ) ;
V_242:
F_126 ( V_2 -> V_3 ) ;
V_241:
F_127 ( V_21 ) ;
V_238:
F_128 ( V_62 ) ;
V_202:
return V_111 ;
}
static int T_6 F_129 ( struct V_231 * V_62 )
{
struct V_115 * V_21 = F_130 ( V_62 ) ;
F_115 ( V_62 , NULL ) ;
if ( V_21 ) {
struct V_1 * V_2 = F_44 ( V_21 ) ;
F_74 ( & V_62 -> V_62 ) ;
F_131 ( V_21 ) ;
F_2 ( 0 , V_2 -> V_5 + V_36 ) ;
F_2 ( 0 , V_2 -> V_5 + V_38 ) ;
F_2 ( 0 , V_2 -> V_5 + V_30 ) ;
F_2 ( 0 , V_2 -> V_5 + V_39 ) ;
F_26 ( V_2 ) ;
F_122 ( V_62 -> V_181 [ 0 ] , V_2 ) ;
if ( ! V_2 -> V_34 )
F_122 ( V_62 -> V_181 [ 1 ] , V_2 ) ;
if ( V_2 -> V_218 != - V_119 )
F_123 ( V_2 -> V_218 ) ;
if ( V_2 -> V_239 >= 0 )
F_122 ( V_2 -> V_239 , V_2 ) ;
if ( V_2 -> V_219 != - V_119 )
F_123 ( V_2 -> V_219 ) ;
F_124 ( V_2 -> V_5 ) ;
V_244 ( V_2 -> V_3 ) ;
F_125 ( V_2 -> V_3 ) ;
F_126 ( V_2 -> V_3 ) ;
if ( V_2 -> V_199 )
F_78 ( V_21 , V_2 -> V_199 , 0 ) ;
F_132 ( V_2 -> V_199 ) ;
F_127 ( V_21 ) ;
F_128 ( V_62 ) ;
}
return 0 ;
}
static int F_133 ( struct V_61 * V_62 )
{
struct V_231 * V_272 = F_134 ( V_62 ) ;
struct V_115 * V_21 = F_130 ( V_272 ) ;
int V_111 = 0 ;
if ( V_21 ) {
struct V_1 * V_2 = F_44 ( V_21 ) ;
V_111 = F_135 ( V_21 ) ;
if ( V_111 == 0 ) {
F_74 ( V_62 ) ;
F_2 ( 0 , V_2 -> V_5 + V_36 ) ;
}
}
return V_111 ;
}
static int F_136 ( struct V_61 * V_62 )
{
struct V_231 * V_272 = F_134 ( V_62 ) ;
struct V_115 * V_21 = F_130 ( V_272 ) ;
int V_111 = 0 ;
if ( V_21 ) {
struct V_1 * V_2 = F_44 ( V_21 ) ;
F_2 ( V_271 , V_2 -> V_5 + V_36 ) ;
F_120 ( V_62 ) ;
V_111 = F_137 ( V_21 ) ;
}
return V_111 ;
}
