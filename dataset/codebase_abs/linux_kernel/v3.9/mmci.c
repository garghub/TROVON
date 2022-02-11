static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ! V_4 )
return 0 ;
if ( ! F_2 ( V_4 -> V_5 ) ) {
F_3 ( F_4 ( V_2 -> V_6 ) ,
L_1 , V_4 -> V_5 ) ;
return - V_7 ;
}
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_8 )
{
if ( V_2 -> V_9 != V_8 ) {
V_2 -> V_9 = V_8 ;
F_6 ( V_8 , V_2 -> V_10 + V_11 ) ;
}
}
static void F_7 ( struct V_1 * V_2 , T_1 V_12 )
{
if ( V_2 -> V_13 != V_12 ) {
V_2 -> V_13 = V_12 ;
F_6 ( V_12 , V_2 -> V_10 + V_14 ) ;
}
}
static void F_8 ( struct V_1 * V_2 , unsigned int V_15 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
T_1 V_8 = V_17 -> V_18 ;
if ( V_15 ) {
if ( V_15 >= V_2 -> V_19 ) {
V_8 = V_20 ;
if ( V_17 -> V_21 )
V_8 |= V_22 ;
V_2 -> V_23 = V_2 -> V_19 ;
} else if ( V_17 -> V_21 ) {
V_8 = F_9 ( V_2 -> V_19 , V_15 ) - 2 ;
if ( V_8 >= 256 )
V_8 = 255 ;
V_2 -> V_23 = V_2 -> V_19 / ( V_8 + 2 ) ;
} else {
V_8 = V_2 -> V_19 / ( 2 * V_15 ) - 1 ;
if ( V_8 >= 256 )
V_8 = 255 ;
V_2 -> V_23 = V_2 -> V_19 / ( 2 * ( V_8 + 1 ) ) ;
}
V_8 |= V_17 -> V_24 ;
V_8 |= V_25 ;
}
if ( V_2 -> V_6 -> V_26 . V_27 == V_28 )
V_8 |= V_29 ;
if ( V_2 -> V_6 -> V_26 . V_27 == V_30 )
V_8 |= V_31 ;
if ( V_2 -> V_6 -> V_26 . V_32 == V_33 )
V_8 |= V_22 ;
F_5 ( V_2 , V_8 ) ;
}
static void
F_10 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
F_6 ( 0 , V_2 -> V_10 + V_36 ) ;
F_11 ( V_2 -> V_4 ) ;
V_2 -> V_35 = NULL ;
V_2 -> V_37 = NULL ;
F_12 ( V_2 -> V_6 , V_35 ) ;
F_13 ( F_4 ( V_2 -> V_6 ) ) ;
F_14 ( F_4 ( V_2 -> V_6 ) ) ;
}
static void F_15 ( struct V_1 * V_2 , unsigned int V_38 )
{
void T_2 * V_10 = V_2 -> V_10 ;
if ( V_2 -> V_39 ) {
unsigned int V_40 = F_16 ( V_10 + V_41 ) ;
V_40 &= ~ V_42 ;
V_40 |= V_38 ;
F_6 ( V_40 , V_10 + V_41 ) ;
}
F_6 ( V_38 , V_10 + V_43 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_6 ( 0 , V_2 -> V_10 + V_44 ) ;
F_15 ( V_2 , 0 ) ;
V_2 -> V_4 = NULL ;
}
static void F_18 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_45 = V_46 ;
if ( V_4 -> V_45 & V_47 )
V_45 |= V_48 ;
else
V_45 |= V_49 ;
F_19 ( & V_2 -> V_50 , V_4 -> V_51 , V_4 -> V_52 , V_45 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = V_2 -> V_54 ;
const char * V_55 , * V_56 ;
T_3 V_38 ;
if ( ! V_54 || ! V_54 -> V_57 ) {
F_21 ( F_4 ( V_2 -> V_6 ) , L_2 ) ;
return;
}
V_2 -> V_58 . V_59 = 1 ;
F_22 ( V_38 ) ;
F_23 ( V_60 , V_38 ) ;
if ( V_54 -> V_61 ) {
V_2 -> V_62 = F_24 ( V_38 ,
V_54 -> V_57 ,
V_54 -> V_61 ) ;
if ( ! V_2 -> V_62 )
F_3 ( F_4 ( V_2 -> V_6 ) , L_3 ) ;
}
if ( V_54 -> V_63 ) {
V_2 -> V_64 = F_24 ( V_38 ,
V_54 -> V_57 ,
V_54 -> V_63 ) ;
if ( ! V_2 -> V_64 )
F_25 ( F_4 ( V_2 -> V_6 ) , L_4 ) ;
} else {
V_2 -> V_64 = V_2 -> V_62 ;
}
if ( V_2 -> V_62 )
V_55 = F_26 ( V_2 -> V_62 ) ;
else
V_55 = L_5 ;
if ( V_2 -> V_64 )
V_56 = F_26 ( V_2 -> V_64 ) ;
else
V_56 = L_5 ;
F_21 ( F_4 ( V_2 -> V_6 ) , L_6 ,
V_55 , V_56 ) ;
if ( V_2 -> V_64 ) {
struct V_65 * V_66 = V_2 -> V_64 -> V_65 -> V_66 ;
unsigned int V_67 = F_27 ( V_66 ) ;
if ( V_67 < V_2 -> V_6 -> V_67 )
V_2 -> V_6 -> V_67 = V_67 ;
}
if ( V_2 -> V_62 ) {
struct V_65 * V_66 = V_2 -> V_62 -> V_65 -> V_66 ;
unsigned int V_67 = F_27 ( V_66 ) ;
if ( V_67 < V_2 -> V_6 -> V_67 )
V_2 -> V_6 -> V_67 = V_67 ;
}
}
static inline void F_28 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = V_2 -> V_54 ;
if ( V_2 -> V_62 )
F_29 ( V_2 -> V_62 ) ;
if ( V_2 -> V_64 && V_54 -> V_63 )
F_29 ( V_2 -> V_64 ) ;
V_2 -> V_62 = V_2 -> V_64 = NULL ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_3 ( F_4 ( V_2 -> V_6 ) , L_7 ) ;
F_31 ( V_2 -> V_68 ) ;
V_2 -> V_68 = NULL ;
V_2 -> V_69 = NULL ;
V_2 -> V_4 -> V_70 = 0 ;
}
static void F_32 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_71 * V_72 ;
enum V_73 V_74 ;
if ( V_4 -> V_45 & V_47 ) {
V_74 = V_75 ;
V_72 = V_2 -> V_62 ;
} else {
V_74 = V_76 ;
V_72 = V_2 -> V_64 ;
}
F_33 ( V_72 -> V_65 -> V_66 , V_4 -> V_51 , V_4 -> V_52 , V_74 ) ;
}
static void F_34 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_77 ;
int V_78 ;
for ( V_78 = 0 ; ; V_78 ++ ) {
V_77 = F_16 ( V_2 -> V_10 + V_79 ) ;
if ( ! ( V_77 & V_80 ) || V_78 >= 100 )
break;
F_35 ( 10 ) ;
}
if ( V_77 & V_80 ) {
F_30 ( V_2 ) ;
if ( ! V_4 -> error )
V_4 -> error = - V_81 ;
}
if ( ! V_4 -> V_70 )
F_32 ( V_2 , V_4 ) ;
if ( V_77 & V_80 ) {
F_3 ( F_4 ( V_2 -> V_6 ) , L_8 ) ;
F_28 ( V_2 ) ;
}
V_2 -> V_68 = NULL ;
V_2 -> V_69 = NULL ;
}
static int F_36 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_71 * * V_71 ,
struct V_82 * * V_83 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
struct V_84 V_85 = {
. V_86 = V_2 -> V_87 + V_88 ,
. V_89 = V_2 -> V_87 + V_88 ,
. V_90 = V_91 ,
. V_92 = V_91 ,
. V_93 = V_17 -> V_94 >> 2 ,
. V_95 = V_17 -> V_94 >> 2 ,
. V_96 = false ,
} ;
struct V_71 * V_72 ;
struct V_97 * V_65 ;
struct V_82 * V_98 ;
enum V_73 V_99 ;
int V_100 ;
if ( V_4 -> V_45 & V_47 ) {
V_85 . V_101 = V_102 ;
V_99 = V_75 ;
V_72 = V_2 -> V_62 ;
} else {
V_85 . V_101 = V_103 ;
V_99 = V_76 ;
V_72 = V_2 -> V_64 ;
}
if ( ! V_72 )
return - V_7 ;
if ( V_4 -> V_5 * V_4 -> V_104 <= V_17 -> V_105 )
return - V_7 ;
V_65 = V_72 -> V_65 ;
V_100 = F_37 ( V_65 -> V_66 , V_4 -> V_51 , V_4 -> V_52 , V_99 ) ;
if ( V_100 == 0 )
return - V_7 ;
F_38 ( V_72 , & V_85 ) ;
V_98 = F_39 ( V_72 , V_4 -> V_51 , V_100 ,
V_85 . V_101 , V_106 ) ;
if ( ! V_98 )
goto V_107;
* V_71 = V_72 ;
* V_83 = V_98 ;
return 0 ;
V_107:
F_33 ( V_65 -> V_66 , V_4 -> V_51 , V_4 -> V_52 , V_99 ) ;
return - V_108 ;
}
static inline int F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 -> V_68 && V_2 -> V_69 )
return 0 ;
return F_36 ( V_2 , V_4 , & V_2 -> V_68 ,
& V_2 -> V_69 ) ;
}
static inline int F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_109 * V_110 = & V_2 -> V_58 ;
return F_36 ( V_2 , V_4 , & V_110 -> V_71 , & V_110 -> V_83 ) ;
}
static int F_42 ( struct V_1 * V_2 , unsigned int V_111 )
{
int V_112 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_112 = F_40 ( V_2 , V_2 -> V_4 ) ;
if ( V_112 )
return V_112 ;
F_43 ( F_4 ( V_2 -> V_6 ) ,
L_9 ,
V_4 -> V_52 , V_4 -> V_5 , V_4 -> V_104 , V_4 -> V_45 ) ;
F_44 ( V_2 -> V_69 ) ;
F_45 ( V_2 -> V_68 ) ;
V_111 |= V_113 ;
F_6 ( V_111 , V_2 -> V_10 + V_44 ) ;
F_6 ( F_16 ( V_2 -> V_10 + V_41 ) | V_114 ,
V_2 -> V_10 + V_41 ) ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_109 * V_115 = & V_2 -> V_58 ;
F_47 ( V_4 -> V_70 && V_4 -> V_70 != V_115 -> V_59 ) ;
F_47 ( ! V_4 -> V_70 && ( V_115 -> V_83 || V_115 -> V_71 ) ) ;
V_2 -> V_69 = V_115 -> V_83 ;
V_2 -> V_68 = V_115 -> V_71 ;
V_115 -> V_83 = NULL ;
V_115 -> V_71 = NULL ;
}
static void F_48 ( struct V_116 * V_6 , struct V_34 * V_35 ,
bool V_117 )
{
struct V_1 * V_2 = F_49 ( V_6 ) ;
struct V_3 * V_4 = V_35 -> V_4 ;
struct V_109 * V_110 = & V_2 -> V_58 ;
if ( ! V_4 )
return;
F_11 ( V_4 -> V_70 ) ;
if ( F_1 ( V_2 , V_4 ) )
return;
if ( ! F_41 ( V_2 , V_4 ) )
V_4 -> V_70 = ++ V_110 -> V_59 < 0 ? 1 : V_110 -> V_59 ;
}
static void F_50 ( struct V_116 * V_6 , struct V_34 * V_35 ,
int V_118 )
{
struct V_1 * V_2 = F_49 ( V_6 ) ;
struct V_3 * V_4 = V_35 -> V_4 ;
if ( ! V_4 || ! V_4 -> V_70 )
return;
F_32 ( V_2 , V_4 ) ;
if ( V_118 ) {
struct V_109 * V_115 = & V_2 -> V_58 ;
struct V_71 * V_72 ;
if ( V_4 -> V_45 & V_47 )
V_72 = V_2 -> V_62 ;
else
V_72 = V_2 -> V_64 ;
F_31 ( V_72 ) ;
V_115 -> V_83 = NULL ;
V_115 -> V_71 = NULL ;
}
}
static void F_46 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
}
static inline void F_20 ( struct V_1 * V_2 )
{
}
static inline void F_28 ( struct V_1 * V_2 )
{
}
static inline void F_32 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
}
static inline void F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
}
static inline void F_30 ( struct V_1 * V_2 )
{
}
static inline int F_42 ( struct V_1 * V_2 , unsigned int V_111 )
{
return - V_119 ;
}
static void F_51 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
unsigned int V_111 , V_120 , V_121 ;
unsigned long long V_122 ;
void T_2 * V_10 ;
int V_123 ;
F_52 ( F_4 ( V_2 -> V_6 ) , L_10 ,
V_4 -> V_5 , V_4 -> V_104 , V_4 -> V_45 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_124 = V_4 -> V_5 * V_4 -> V_104 ;
V_4 -> V_125 = 0 ;
V_122 = ( unsigned long long ) V_4 -> V_126 * V_2 -> V_23 ;
F_53 ( V_122 , 1000000000UL ) ;
V_120 = V_4 -> V_127 + ( unsigned int ) V_122 ;
V_10 = V_2 -> V_10 ;
F_6 ( V_120 , V_10 + V_128 ) ;
F_6 ( V_2 -> V_124 , V_10 + V_129 ) ;
V_123 = F_54 ( V_4 -> V_5 ) - 1 ;
F_11 ( 1 << V_123 != V_4 -> V_5 ) ;
if ( V_17 -> V_130 )
V_111 = V_131 | ( V_4 -> V_5 << 16 ) ;
else
V_111 = V_131 | V_123 << 4 ;
if ( V_4 -> V_45 & V_47 )
V_111 |= V_132 ;
if ( V_17 -> V_133 && V_2 -> V_6 -> V_134 )
if ( F_55 ( V_2 -> V_6 -> V_134 ) ) {
T_1 V_8 ;
V_111 |= V_135 ;
if ( V_4 -> V_45 & V_136 &&
( V_2 -> V_124 < 8 ||
( V_2 -> V_124 <= 8 && V_2 -> V_19 > 50000000 ) ) )
V_8 = V_2 -> V_9 & ~ V_17 -> V_24 ;
else
V_8 = V_2 -> V_9 | V_17 -> V_24 ;
F_5 ( V_2 , V_8 ) ;
}
if ( V_2 -> V_6 -> V_26 . V_32 == V_33 )
V_111 |= V_137 ;
if ( ! F_42 ( V_2 , V_111 ) )
return;
F_18 ( V_2 , V_4 ) ;
if ( V_4 -> V_45 & V_47 ) {
V_121 = V_138 ;
if ( V_2 -> V_124 < V_17 -> V_94 )
V_121 |= V_80 ;
} else {
V_121 = V_139 ;
}
F_6 ( V_111 , V_10 + V_44 ) ;
F_6 ( F_16 ( V_10 + V_41 ) & ~ V_114 , V_10 + V_41 ) ;
F_15 ( V_2 , V_121 ) ;
}
static void
F_56 ( struct V_1 * V_2 , struct V_140 * V_37 , T_1 V_141 )
{
void T_2 * V_10 = V_2 -> V_10 ;
F_52 ( F_4 ( V_2 -> V_6 ) , L_11 ,
V_37 -> V_142 , V_37 -> V_143 , V_37 -> V_45 ) ;
if ( F_16 ( V_10 + V_36 ) & V_144 ) {
F_6 ( 0 , V_10 + V_36 ) ;
F_35 ( 1 ) ;
}
V_141 |= V_37 -> V_142 | V_144 ;
if ( V_37 -> V_45 & V_145 ) {
if ( V_37 -> V_45 & V_146 )
V_141 |= V_147 ;
V_141 |= V_148 ;
}
if ( 0 )
V_141 |= V_149 ;
V_2 -> V_37 = V_37 ;
F_6 ( V_37 -> V_143 , V_10 + V_150 ) ;
F_6 ( V_141 , V_10 + V_36 ) ;
}
static void
F_57 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_77 )
{
if ( V_77 & ( V_151 | V_152 | V_153 |
V_154 | V_155 ) ) {
T_1 V_156 , V_157 ;
if ( F_58 ( V_2 ) ) {
F_30 ( V_2 ) ;
F_32 ( V_2 , V_4 ) ;
}
V_156 = F_16 ( V_2 -> V_10 + V_158 ) ;
V_157 = V_4 -> V_5 * V_4 -> V_104 - V_156 ;
F_52 ( F_4 ( V_2 -> V_6 ) , L_12 ,
V_77 , V_157 ) ;
if ( V_77 & V_151 ) {
V_157 -= 1 ;
V_4 -> error = - V_159 ;
} else if ( V_77 & V_152 ) {
V_4 -> error = - V_160 ;
} else if ( V_77 & V_153 ) {
V_4 -> error = - V_161 ;
} else if ( V_77 & V_154 ) {
V_4 -> error = - V_81 ;
} else if ( V_77 & V_155 ) {
if ( V_157 > V_2 -> V_17 -> V_105 )
V_157 -= V_2 -> V_17 -> V_105 ;
else
V_157 = 0 ;
V_4 -> error = - V_81 ;
}
V_4 -> V_125 = F_59 ( V_157 , V_4 -> V_5 ) ;
}
if ( V_77 & V_162 )
F_3 ( F_4 ( V_2 -> V_6 ) , L_13 ) ;
if ( V_77 & V_163 || V_4 -> error ) {
if ( F_58 ( V_2 ) )
F_34 ( V_2 , V_4 ) ;
F_17 ( V_2 ) ;
if ( ! V_4 -> error )
V_4 -> V_125 = V_4 -> V_5 * V_4 -> V_104 ;
if ( ! V_4 -> V_164 ) {
F_10 ( V_2 , V_4 -> V_35 ) ;
} else {
F_56 ( V_2 , V_4 -> V_164 , 0 ) ;
}
}
}
static void
F_60 ( struct V_1 * V_2 , struct V_140 * V_37 ,
unsigned int V_77 )
{
void T_2 * V_10 = V_2 -> V_10 ;
V_2 -> V_37 = NULL ;
if ( V_77 & V_165 ) {
V_37 -> error = - V_160 ;
} else if ( V_77 & V_166 && V_37 -> V_45 & V_167 ) {
V_37 -> error = - V_159 ;
} else {
V_37 -> V_168 [ 0 ] = F_16 ( V_10 + V_169 ) ;
V_37 -> V_168 [ 1 ] = F_16 ( V_10 + V_170 ) ;
V_37 -> V_168 [ 2 ] = F_16 ( V_10 + V_171 ) ;
V_37 -> V_168 [ 3 ] = F_16 ( V_10 + V_172 ) ;
}
if ( ! V_37 -> V_4 || V_37 -> error ) {
if ( V_2 -> V_4 ) {
if ( F_58 ( V_2 ) ) {
F_30 ( V_2 ) ;
F_32 ( V_2 , V_2 -> V_4 ) ;
}
F_17 ( V_2 ) ;
}
F_10 ( V_2 , V_37 -> V_35 ) ;
} else if ( ! ( V_37 -> V_4 -> V_45 & V_47 ) ) {
F_51 ( V_2 , V_37 -> V_4 ) ;
}
}
static int F_61 ( struct V_1 * V_2 , char * V_173 , unsigned int V_156 )
{
void T_2 * V_10 = V_2 -> V_10 ;
char * V_174 = V_173 ;
T_1 V_77 ;
int V_175 = V_2 -> V_124 ;
do {
int V_176 = V_175 - ( F_16 ( V_10 + V_177 ) << 2 ) ;
if ( V_176 > V_156 )
V_176 = V_156 ;
if ( V_176 <= 0 )
break;
if ( F_62 ( V_176 & 0x3 ) ) {
if ( V_176 < 4 ) {
unsigned char V_178 [ 4 ] ;
F_63 ( V_10 + V_88 , V_178 , 1 ) ;
memcpy ( V_174 , V_178 , V_176 ) ;
} else {
F_63 ( V_10 + V_88 , V_174 , V_176 >> 2 ) ;
V_176 &= ~ 0x3 ;
}
} else {
F_63 ( V_10 + V_88 , V_174 , V_176 >> 2 ) ;
}
V_174 += V_176 ;
V_156 -= V_176 ;
V_175 -= V_176 ;
if ( V_156 == 0 )
break;
V_77 = F_16 ( V_10 + V_79 ) ;
} while ( V_77 & V_179 );
return V_174 - V_173 ;
}
static int F_64 ( struct V_1 * V_2 , char * V_173 , unsigned int V_156 , T_1 V_77 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
void T_2 * V_10 = V_2 -> V_10 ;
char * V_174 = V_173 ;
do {
unsigned int V_176 , V_180 ;
V_180 = V_77 & V_181 ?
V_17 -> V_105 : V_17 -> V_94 ;
V_176 = F_65 ( V_156 , V_180 ) ;
F_66 ( V_10 + V_88 , V_174 , ( V_176 + 3 ) >> 2 ) ;
V_174 += V_176 ;
V_156 -= V_176 ;
if ( V_156 == 0 )
break;
V_77 = F_16 ( V_10 + V_79 ) ;
} while ( V_77 & V_182 );
return V_174 - V_173 ;
}
static T_4 F_67 ( int V_183 , void * V_184 )
{
struct V_1 * V_2 = V_184 ;
struct V_185 * V_50 = & V_2 -> V_50 ;
struct V_16 * V_17 = V_2 -> V_17 ;
void T_2 * V_10 = V_2 -> V_10 ;
unsigned long V_45 ;
T_1 V_77 ;
V_77 = F_16 ( V_10 + V_79 ) ;
F_52 ( F_4 ( V_2 -> V_6 ) , L_14 , V_77 ) ;
F_68 ( V_45 ) ;
do {
unsigned int V_156 , V_186 ;
char * V_173 ;
if ( ! ( V_77 & ( V_182 | V_179 ) ) )
break;
if ( ! F_69 ( V_50 ) )
break;
V_173 = V_50 -> V_187 ;
V_156 = V_50 -> V_188 ;
V_186 = 0 ;
if ( V_77 & V_189 )
V_186 = F_61 ( V_2 , V_173 , V_156 ) ;
if ( V_77 & V_190 )
V_186 = F_64 ( V_2 , V_173 , V_156 , V_77 ) ;
V_50 -> V_191 = V_186 ;
V_2 -> V_124 -= V_186 ;
V_156 -= V_186 ;
if ( V_156 )
break;
V_77 = F_16 ( V_10 + V_79 ) ;
} while ( 1 );
F_70 ( V_50 ) ;
F_71 ( V_45 ) ;
if ( V_77 & V_189 && V_2 -> V_124 < V_17 -> V_94 )
F_15 ( V_2 , V_80 ) ;
if ( V_2 -> V_124 == 0 ) {
F_15 ( V_2 , 0 ) ;
F_6 ( F_16 ( V_10 + V_41 ) | V_114 , V_10 + V_41 ) ;
}
return V_192 ;
}
static T_4 F_72 ( int V_183 , void * V_184 )
{
struct V_1 * V_2 = V_184 ;
T_1 V_77 ;
int V_112 = 0 ;
F_73 ( & V_2 -> V_193 ) ;
do {
struct V_140 * V_37 ;
struct V_3 * V_4 ;
V_77 = F_16 ( V_2 -> V_10 + V_79 ) ;
if ( V_2 -> V_39 ) {
if ( V_77 & F_16 ( V_2 -> V_10 + V_43 ) )
F_67 ( V_183 , V_184 ) ;
V_77 &= ~ V_42 ;
}
V_77 &= F_16 ( V_2 -> V_10 + V_41 ) ;
F_6 ( V_77 , V_2 -> V_10 + V_194 ) ;
F_52 ( F_4 ( V_2 -> V_6 ) , L_15 , V_77 ) ;
V_4 = V_2 -> V_4 ;
if ( V_77 & ( V_151 | V_152 | V_153 |
V_154 | V_155 | V_163 |
V_162 ) && V_4 )
F_57 ( V_2 , V_4 , V_77 ) ;
V_37 = V_2 -> V_37 ;
if ( V_77 & ( V_166 | V_165 | V_195 | V_196 ) && V_37 )
F_60 ( V_2 , V_37 , V_77 ) ;
V_112 = 1 ;
} while ( V_77 );
F_74 ( & V_2 -> V_193 ) ;
return F_75 ( V_112 ) ;
}
static void F_76 ( struct V_116 * V_6 , struct V_34 * V_35 )
{
struct V_1 * V_2 = F_49 ( V_6 ) ;
unsigned long V_45 ;
F_47 ( V_2 -> V_35 != NULL ) ;
V_35 -> V_37 -> error = F_1 ( V_2 , V_35 -> V_4 ) ;
if ( V_35 -> V_37 -> error ) {
F_12 ( V_6 , V_35 ) ;
return;
}
F_77 ( F_4 ( V_6 ) ) ;
F_78 ( & V_2 -> V_193 , V_45 ) ;
V_2 -> V_35 = V_35 ;
if ( V_35 -> V_4 )
F_46 ( V_2 , V_35 -> V_4 ) ;
if ( V_35 -> V_4 && V_35 -> V_4 -> V_45 & V_47 )
F_51 ( V_2 , V_35 -> V_4 ) ;
F_56 ( V_2 , V_35 -> V_37 , 0 ) ;
F_79 ( & V_2 -> V_193 , V_45 ) ;
}
static void F_80 ( struct V_116 * V_6 , struct V_197 * V_26 )
{
struct V_1 * V_2 = F_49 ( V_6 ) ;
struct V_16 * V_17 = V_2 -> V_17 ;
T_1 V_12 = 0 ;
unsigned long V_45 ;
F_77 ( F_4 ( V_6 ) ) ;
if ( V_2 -> V_54 -> V_198 &&
V_2 -> V_54 -> V_198 ( F_4 ( V_6 ) , V_26 ) )
F_3 ( F_4 ( V_6 ) , L_16 ) ;
switch ( V_26 -> V_199 ) {
case V_200 :
if ( ! F_81 ( V_6 -> V_201 . V_202 ) )
F_82 ( V_6 , V_6 -> V_201 . V_202 , 0 ) ;
break;
case V_203 :
if ( ! F_81 ( V_6 -> V_201 . V_202 ) )
F_82 ( V_6 , V_6 -> V_201 . V_202 , V_26 -> V_204 ) ;
V_12 |= V_17 -> V_205 ;
break;
case V_206 :
V_12 |= V_207 ;
break;
}
if ( V_17 -> V_208 && V_26 -> V_199 != V_200 ) {
V_12 |= V_2 -> V_54 -> V_209 ;
if ( V_26 -> V_27 == V_28 )
V_12 &= ~ V_210 ;
else if ( V_26 -> V_27 == V_211 )
V_12 &= ( ~ V_210 &
~ V_212 &
~ V_213 ) ;
}
if ( V_26 -> V_214 == V_215 ) {
if ( V_2 -> V_216 != V_217 )
V_12 |= V_218 ;
else {
V_12 |= V_219 ;
}
}
if ( ! V_26 -> clock && V_17 -> V_220 )
V_12 &= ~ V_207 ;
F_78 ( & V_2 -> V_193 , V_45 ) ;
F_8 ( V_2 , V_26 -> clock ) ;
F_7 ( V_2 , V_12 ) ;
F_79 ( & V_2 -> V_193 , V_45 ) ;
F_13 ( F_4 ( V_6 ) ) ;
F_14 ( F_4 ( V_6 ) ) ;
}
static int F_83 ( struct V_116 * V_6 )
{
struct V_1 * V_2 = F_49 ( V_6 ) ;
if ( V_2 -> V_221 == - V_119 )
return - V_119 ;
return F_84 ( V_2 -> V_221 ) ;
}
static int F_85 ( struct V_116 * V_6 )
{
struct V_1 * V_2 = F_49 ( V_6 ) ;
struct V_53 * V_54 = V_2 -> V_54 ;
unsigned int V_77 ;
if ( V_2 -> V_222 == - V_119 ) {
if ( ! V_54 -> V_77 )
return 1 ;
V_77 = V_54 -> V_77 ( F_4 ( V_2 -> V_6 ) ) ;
} else
V_77 = ! ! F_84 ( V_2 -> V_222 )
^ V_54 -> V_223 ;
return V_77 ;
}
static T_4 F_86 ( int V_183 , void * V_184 )
{
struct V_1 * V_2 = V_184 ;
F_87 ( V_2 -> V_6 , F_88 ( 500 ) ) ;
return V_192 ;
}
static void F_89 ( struct V_224 * V_225 ,
struct V_53 * V_226 )
{
int V_27 = 0 ;
V_226 -> V_221 = F_90 ( V_225 , L_17 , 0 ) ;
V_226 -> V_222 = F_90 ( V_225 , L_18 , 0 ) ;
if ( F_91 ( V_225 , L_19 , NULL ) )
V_226 -> V_223 = true ;
else
V_226 -> V_223 = false ;
F_92 ( V_225 , L_20 , & V_226 -> V_227 ) ;
if ( ! V_226 -> V_227 )
F_93 ( L_21 , V_225 -> V_228 ) ;
if ( F_91 ( V_225 , L_22 , NULL ) )
V_226 -> V_229 |= V_230 ;
if ( F_91 ( V_225 , L_23 , NULL ) )
V_226 -> V_229 |= V_231 ;
F_92 ( V_225 , L_24 , & V_27 ) ;
switch ( V_27 ) {
case 0 :
break;
case 4 :
V_226 -> V_229 |= V_232 ;
break;
case 8 :
V_226 -> V_229 |= V_233 ;
break;
default :
F_93 ( L_25 , V_225 -> V_228 ) ;
}
}
static void F_89 ( struct V_224 * V_225 ,
struct V_53 * V_226 )
{
return;
}
static int F_94 ( struct V_234 * V_66 ,
const struct V_235 * V_236 )
{
struct V_53 * V_54 = V_66 -> V_66 . V_237 ;
struct V_224 * V_225 = V_66 -> V_66 . V_238 ;
struct V_16 * V_17 = V_236 -> V_4 ;
struct V_1 * V_2 ;
struct V_116 * V_6 ;
int V_112 ;
if ( ! V_54 && ! V_225 ) {
F_3 ( & V_66 -> V_66 , L_26 ) ;
return - V_7 ;
}
if ( ! V_54 ) {
V_54 = F_95 ( & V_66 -> V_66 , sizeof( * V_54 ) , V_239 ) ;
if ( ! V_54 )
return - V_108 ;
}
if ( V_225 )
F_89 ( V_225 , V_54 ) ;
V_112 = F_96 ( V_66 , V_240 ) ;
if ( V_112 )
goto V_241;
V_6 = F_97 ( sizeof( struct V_1 ) , & V_66 -> V_66 ) ;
if ( ! V_6 ) {
V_112 = - V_108 ;
goto V_242;
}
V_2 = F_49 ( V_6 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_221 = - V_119 ;
V_2 -> V_222 = - V_119 ;
V_2 -> V_243 = - 1 ;
V_2 -> V_216 = F_98 ( V_66 ) ;
V_2 -> V_244 = F_99 ( V_66 ) ;
F_52 ( F_4 ( V_6 ) , L_27 , V_2 -> V_216 ) ;
F_52 ( F_4 ( V_6 ) , L_28 , V_2 -> V_244 ) ;
V_2 -> V_8 = F_100 ( & V_66 -> V_66 , NULL ) ;
if ( F_81 ( V_2 -> V_8 ) ) {
V_112 = F_101 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
goto V_245;
}
V_112 = F_102 ( V_2 -> V_8 ) ;
if ( V_112 )
goto V_246;
V_2 -> V_54 = V_54 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_19 = F_103 ( V_2 -> V_8 ) ;
if ( V_2 -> V_19 > 100000000 ) {
V_112 = F_104 ( V_2 -> V_8 , 100000000 ) ;
if ( V_112 < 0 )
goto V_247;
V_2 -> V_19 = F_103 ( V_2 -> V_8 ) ;
F_52 ( F_4 ( V_6 ) , L_29 ,
V_2 -> V_19 ) ;
}
V_2 -> V_87 = V_66 -> V_248 . V_249 ;
V_2 -> V_10 = F_105 ( V_66 -> V_248 . V_249 , F_106 ( & V_66 -> V_248 ) ) ;
if ( ! V_2 -> V_10 ) {
V_112 = - V_108 ;
goto V_247;
}
V_6 -> V_250 = & V_251 ;
if ( V_17 -> V_21 )
V_6 -> V_252 = F_9 ( V_2 -> V_19 , 257 ) ;
else
V_6 -> V_252 = F_9 ( V_2 -> V_19 , 512 ) ;
if ( V_54 -> V_227 )
V_6 -> V_227 = F_65 ( V_2 -> V_19 , V_54 -> V_227 ) ;
else
V_6 -> V_227 = F_65 ( V_2 -> V_19 , V_253 ) ;
F_52 ( F_4 ( V_6 ) , L_30 , V_6 -> V_227 ) ;
V_2 -> V_254 = F_107 ( & V_66 -> V_66 ) ;
if ( F_81 ( V_2 -> V_254 ) ) {
V_112 = F_101 ( V_2 -> V_254 ) ;
goto V_247;
}
V_2 -> V_255 = F_108 ( V_2 -> V_254 ,
V_256 ) ;
if ( ! F_81 ( V_2 -> V_255 ) ) {
V_112 = F_109 ( V_2 -> V_254 , V_2 -> V_255 ) ;
if ( V_112 )
F_25 ( & V_66 -> V_66 , L_31 ) ;
} else
F_25 ( & V_66 -> V_66 , L_32 ) ;
F_110 ( V_6 ) ;
if ( ! V_6 -> V_257 )
V_6 -> V_257 = V_54 -> V_258 ;
else if ( V_54 -> V_258 )
F_25 ( F_4 ( V_6 ) , L_33 ) ;
V_6 -> V_259 = V_54 -> V_229 ;
V_6 -> V_260 = V_54 -> V_261 ;
V_6 -> V_262 = V_263 ;
V_6 -> V_264 = V_265 ;
V_6 -> V_266 = ( 1 << V_17 -> V_267 ) - 1 ;
V_6 -> V_67 = V_6 -> V_266 ;
V_6 -> V_268 = 1 << 11 ;
V_6 -> V_269 = V_6 -> V_266 >> 11 ;
F_111 ( & V_2 -> V_193 ) ;
F_6 ( 0 , V_2 -> V_10 + V_41 ) ;
F_6 ( 0 , V_2 -> V_10 + V_43 ) ;
F_6 ( 0xfff , V_2 -> V_10 + V_194 ) ;
if ( V_54 -> V_222 == - V_270 ) {
V_112 = - V_270 ;
goto V_271;
}
if ( F_112 ( V_54 -> V_222 ) ) {
V_112 = F_113 ( V_54 -> V_222 , V_240 L_34 ) ;
if ( V_112 == 0 )
V_112 = F_114 ( V_54 -> V_222 ) ;
if ( V_112 == 0 )
V_2 -> V_222 = V_54 -> V_222 ;
else if ( V_112 != - V_119 )
goto V_271;
V_112 = F_115 ( F_116 ( V_54 -> V_222 ) ,
F_86 ,
V_272 | V_273 ,
V_240 L_34 , V_2 ) ;
if ( V_112 >= 0 )
V_2 -> V_243 = F_116 ( V_54 -> V_222 ) ;
}
if ( V_54 -> V_221 == - V_270 ) {
V_112 = - V_270 ;
goto V_274;
}
if ( F_112 ( V_54 -> V_221 ) ) {
V_112 = F_113 ( V_54 -> V_221 , V_240 L_35 ) ;
if ( V_112 == 0 )
V_112 = F_114 ( V_54 -> V_221 ) ;
if ( V_112 == 0 )
V_2 -> V_221 = V_54 -> V_221 ;
else if ( V_112 != - V_119 )
goto V_274;
}
if ( ( V_2 -> V_54 -> V_77 || V_2 -> V_222 != - V_119 )
&& V_2 -> V_243 < 0 )
V_6 -> V_259 |= V_275 ;
V_112 = F_117 ( V_66 -> V_183 [ 0 ] , F_72 , V_276 , V_240 L_36 , V_2 ) ;
if ( V_112 )
goto V_277;
if ( ! V_66 -> V_183 [ 1 ] )
V_2 -> V_39 = true ;
else {
V_112 = F_117 ( V_66 -> V_183 [ 1 ] , F_67 , V_276 ,
V_240 L_37 , V_2 ) ;
if ( V_112 )
goto V_278;
}
F_6 ( V_279 , V_2 -> V_10 + V_41 ) ;
F_118 ( V_66 , V_6 ) ;
F_21 ( & V_66 -> V_66 , L_38 ,
F_119 ( V_6 ) , F_120 ( V_66 ) , F_98 ( V_66 ) ,
F_99 ( V_66 ) , ( unsigned long long ) V_66 -> V_248 . V_249 ,
V_66 -> V_183 [ 0 ] , V_66 -> V_183 [ 1 ] ) ;
F_20 ( V_2 ) ;
F_121 ( & V_66 -> V_66 , 50 ) ;
F_122 ( & V_66 -> V_66 ) ;
F_123 ( & V_66 -> V_66 ) ;
F_124 ( V_6 ) ;
return 0 ;
V_278:
F_125 ( V_66 -> V_183 [ 0 ] , V_2 ) ;
V_277:
if ( V_2 -> V_221 != - V_119 )
F_126 ( V_2 -> V_221 ) ;
V_274:
if ( V_2 -> V_243 >= 0 )
F_125 ( V_2 -> V_243 , V_2 ) ;
if ( V_2 -> V_222 != - V_119 )
F_126 ( V_2 -> V_222 ) ;
V_271:
F_127 ( V_2 -> V_10 ) ;
V_247:
F_128 ( V_2 -> V_8 ) ;
V_246:
F_129 ( V_2 -> V_8 ) ;
V_245:
F_130 ( V_6 ) ;
V_242:
F_131 ( V_66 ) ;
V_241:
return V_112 ;
}
static int F_132 ( struct V_234 * V_66 )
{
struct V_116 * V_6 = F_133 ( V_66 ) ;
F_118 ( V_66 , NULL ) ;
if ( V_6 ) {
struct V_1 * V_2 = F_49 ( V_6 ) ;
F_77 ( & V_66 -> V_66 ) ;
F_134 ( V_6 ) ;
F_6 ( 0 , V_2 -> V_10 + V_41 ) ;
F_6 ( 0 , V_2 -> V_10 + V_43 ) ;
F_6 ( 0 , V_2 -> V_10 + V_36 ) ;
F_6 ( 0 , V_2 -> V_10 + V_44 ) ;
F_28 ( V_2 ) ;
F_125 ( V_66 -> V_183 [ 0 ] , V_2 ) ;
if ( ! V_2 -> V_39 )
F_125 ( V_66 -> V_183 [ 1 ] , V_2 ) ;
if ( V_2 -> V_221 != - V_119 )
F_126 ( V_2 -> V_221 ) ;
if ( V_2 -> V_243 >= 0 )
F_125 ( V_2 -> V_243 , V_2 ) ;
if ( V_2 -> V_222 != - V_119 )
F_126 ( V_2 -> V_222 ) ;
F_127 ( V_2 -> V_10 ) ;
F_128 ( V_2 -> V_8 ) ;
F_129 ( V_2 -> V_8 ) ;
F_130 ( V_6 ) ;
F_131 ( V_66 ) ;
}
return 0 ;
}
static int F_135 ( struct V_65 * V_66 )
{
struct V_234 * V_280 = F_136 ( V_66 ) ;
struct V_116 * V_6 = F_133 ( V_280 ) ;
int V_112 = 0 ;
if ( V_6 ) {
struct V_1 * V_2 = F_49 ( V_6 ) ;
V_112 = F_137 ( V_6 ) ;
if ( V_112 == 0 ) {
F_77 ( V_66 ) ;
F_6 ( 0 , V_2 -> V_10 + V_41 ) ;
}
}
return V_112 ;
}
static int F_138 ( struct V_65 * V_66 )
{
struct V_234 * V_280 = F_136 ( V_66 ) ;
struct V_116 * V_6 = F_133 ( V_280 ) ;
int V_112 = 0 ;
if ( V_6 ) {
struct V_1 * V_2 = F_49 ( V_6 ) ;
F_6 ( V_279 , V_2 -> V_10 + V_41 ) ;
F_123 ( V_66 ) ;
V_112 = F_139 ( V_6 ) ;
}
return V_112 ;
}
static int F_140 ( struct V_65 * V_66 )
{
struct V_234 * V_280 = F_136 ( V_66 ) ;
struct V_116 * V_6 = F_133 ( V_280 ) ;
if ( V_6 ) {
struct V_1 * V_2 = F_49 ( V_6 ) ;
F_128 ( V_2 -> V_8 ) ;
}
return 0 ;
}
static int F_141 ( struct V_65 * V_66 )
{
struct V_234 * V_280 = F_136 ( V_66 ) ;
struct V_116 * V_6 = F_133 ( V_280 ) ;
if ( V_6 ) {
struct V_1 * V_2 = F_49 ( V_6 ) ;
F_102 ( V_2 -> V_8 ) ;
}
return 0 ;
}
