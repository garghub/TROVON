static inline void T_1 * F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_2 -> V_4 + ( V_5 + V_3 * 0x40 ) ;
}
static inline struct V_6 * F_2 ( struct V_7 * V_8 )
{
return F_3 ( V_8 , struct V_6 , V_9 ) ;
}
static struct V_10 * F_4 ( struct V_7 * V_9 )
{
return & V_9 -> V_11 -> V_10 ;
}
static inline struct V_1 * F_5 ( struct V_12 * V_13 )
{
return F_3 ( V_13 , struct V_1 , V_14 ) ;
}
static inline struct V_15 * F_6 ( struct V_16 * V_17 )
{
return F_3 ( V_17 , struct V_15 , V_18 ) ;
}
static inline int F_7 ( struct V_6 * V_19 )
{
return F_8 ( V_20 , & V_19 -> V_21 ) ;
}
static inline int F_9 ( struct V_6 * V_19 )
{
return F_8 ( V_22 , & V_19 -> V_21 ) ;
}
static inline int F_10 ( T_2 V_23 )
{
int V_24 ;
V_24 = F_11 ( V_23 ) - 1 ;
if ( V_24 > 4 )
V_24 = - V_25 ;
return V_24 ;
}
static inline T_3 F_12 ( T_2 V_26 )
{
return ( V_26 & V_27 ) >> V_28 ;
}
static bool F_13 ( struct V_6 * V_19 )
{
return F_14 ( V_19 , V_29 ) & V_19 -> V_30 ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_16 ( V_2 , V_31 , - 1L ) ;
while ( F_17 ( V_2 , V_29 ) )
F_18 () ;
F_16 ( V_2 , V_32 , - 1L ) ;
}
static void F_19 ( struct V_6 * V_19 ,
struct V_15 * V_33 )
{
struct V_1 * V_2 = F_5 ( V_19 -> V_9 . V_10 ) ;
T_2 V_34 ;
F_20 ( F_4 ( & V_19 -> V_9 ) , L_1 , V_35 , V_33 ) ;
if ( F_13 ( V_19 ) )
return;
V_33 -> V_36 = true ;
V_34 = F_21 ( V_33 -> V_18 . V_37 )
| F_22 ( V_19 -> V_38 ) ;
F_23 ( V_19 , V_39 , V_34 ) ;
if ( F_7 ( V_19 ) )
V_34 = V_40 ;
else if ( V_33 -> V_41 . V_42 & V_43 )
V_34 = V_44 ;
else
V_34 = V_45 ;
F_23 ( V_19 , V_46 , V_33 -> V_41 . V_47 ) ;
V_34 |= V_48
| V_49
| V_50 ;
F_23 ( V_19 , V_51 , V_34 ) ;
F_20 ( F_4 ( & V_19 -> V_9 ) ,
L_2 ,
V_35 , F_14 ( V_19 , V_46 ) ,
F_14 ( V_19 , V_39 ) ,
F_14 ( V_19 , V_51 ) ,
F_14 ( V_19 , V_52 ) ,
F_14 ( V_19 , V_53 ) ,
F_14 ( V_19 , V_54 ) ) ;
F_23 ( V_19 , V_55 , 0xffffffff ) ;
V_34 = V_56 | V_57 | V_58 ;
if ( F_7 ( V_19 ) )
F_23 ( V_19 , V_59 ,
V_34 | V_60 ) ;
else
F_23 ( V_19 , V_59 ,
V_34 | V_61 ) ;
F_16 ( V_2 , V_62 , V_19 -> V_30 ) ;
F_20 ( F_4 ( & V_19 -> V_9 ) ,
L_3 , V_35 , V_19 -> V_30 ) ;
F_24 () ;
F_16 ( V_2 , V_63 , V_19 -> V_30 ) ;
F_20 ( F_4 ( & V_19 -> V_9 ) ,
L_2 ,
V_35 , F_14 ( V_19 , V_46 ) ,
F_14 ( V_19 , V_39 ) ,
F_14 ( V_19 , V_51 ) ,
F_14 ( V_19 , V_52 ) ,
F_14 ( V_19 , V_53 ) ,
F_14 ( V_19 , V_54 ) ) ;
}
static T_4 F_25 ( struct V_16 * V_64 )
{
struct V_15 * V_65 = F_6 ( V_64 ) ;
struct V_6 * V_19 = F_2 ( V_64 -> V_9 ) ;
T_4 V_66 ;
unsigned long V_67 ;
F_26 ( & V_19 -> V_68 , V_67 ) ;
V_66 = F_27 ( V_64 ) ;
F_20 ( F_4 ( V_64 -> V_9 ) , L_4 ,
V_35 , V_19 , V_65 ) ;
F_28 ( & V_65 -> V_69 , & V_19 -> V_70 ) ;
if ( F_29 ( & V_19 -> V_70 ) )
F_19 ( V_19 , V_65 ) ;
F_30 ( & V_19 -> V_68 , V_67 ) ;
return V_66 ;
}
static struct V_15 * F_31 ( struct V_7 * V_9 ,
T_5 V_71 )
{
struct V_15 * V_65 ;
struct V_1 * V_2 = F_5 ( V_9 -> V_10 ) ;
T_6 V_37 ;
V_65 = F_32 ( V_2 -> V_72 , V_71 , & V_37 ) ;
if ( V_65 ) {
F_33 ( & V_65 -> V_73 ) ;
F_34 ( & V_65 -> V_18 , V_9 ) ;
V_65 -> V_18 . V_74 = F_25 ;
V_65 -> V_18 . V_37 = V_37 ;
}
return V_65 ;
}
static void F_35 ( struct V_15 * V_65 )
{
memset ( & V_65 -> V_41 , 0 , sizeof( V_65 -> V_41 ) ) ;
F_33 ( & V_65 -> V_73 ) ;
V_65 -> V_75 = V_76 ;
V_65 -> V_77 = 0 ;
V_65 -> V_36 = false ;
}
static struct V_15 * F_36 ( struct V_6 * V_19 )
{
struct V_15 * V_65 ;
if ( F_37 ( & V_19 -> V_78 ) ) {
V_65 = F_31 ( & V_19 -> V_9 , V_79 ) ;
} else {
V_65 = F_38 ( & V_19 -> V_78 ,
struct V_15 , V_80 ) ;
F_39 ( & V_65 -> V_80 ) ;
F_35 ( V_65 ) ;
}
return V_65 ;
}
static void F_40 ( struct V_7 * V_9 ,
struct V_15 * V_81 ,
struct V_15 * V_65 )
{
if ( ! V_81 || ! V_65 )
return;
V_81 -> V_41 . V_82 = V_65 -> V_18 . V_37 ;
V_81 -> V_41 . V_42 |= V_83 ;
F_41 ( F_4 ( V_9 ) , L_5 ,
V_35 , V_81 , & V_81 -> V_41 . V_82 ) ;
}
static inline void F_42 ( struct V_7 * V_9 ,
struct V_15 * V_65 )
{
if ( ! V_65 )
return;
V_65 -> V_41 . V_84 ++ ;
F_41 ( F_4 ( V_9 ) ,
L_6 ,
V_35 , V_65 ) ;
}
static struct V_7 * F_43 ( struct V_85 * V_86 ,
struct V_87 * V_87 )
{
struct V_1 * V_2 = V_87 -> V_88 ;
struct V_6 * V_19 ;
struct V_7 * V_9 ;
struct V_10 * V_11 = V_2 -> V_14 . V_11 ;
if ( V_86 -> V_89 != 1 ) {
F_44 ( V_11 , L_7 ) ;
return NULL ;
}
V_9 = F_45 ( & V_2 -> V_14 ) ;
if ( ! V_9 ) {
F_44 ( V_11 , L_8 ) ;
return NULL ;
}
V_19 = F_2 ( V_9 ) ;
V_19 -> V_38 = F_46 ( V_86 -> args [ 0 ] ) ;
V_19 -> V_90 = F_47 ( V_86 -> args [ 0 ] ) ;
V_19 -> V_91 = F_48 ( V_86 -> args [ 0 ] ) ;
F_41 ( V_11 , L_9 ,
V_19 -> V_38 , V_19 -> V_90 , V_19 -> V_91 ) ;
return V_9 ;
}
static int F_49 ( struct V_7 * V_9 ,
enum V_92 V_75 )
{
struct V_6 * V_19 = F_2 ( V_9 ) ;
int V_24 , V_93 ;
if ( V_75 == V_94 ) {
V_19 -> V_26 =
F_50 ( V_19 -> V_91 )
| V_95
| V_96
| F_51 ( V_19 -> V_38 )
| F_52 ( V_19 -> V_90 )
| V_97
| V_98
| V_99
| V_100 ;
V_24 = F_11 ( V_19 -> V_101 . V_102 ) - 1 ;
if ( V_24 < 0 ) {
F_44 ( F_4 ( V_9 ) , L_10 ) ;
return - V_25 ;
}
V_19 -> V_26 |= F_53 ( V_24 ) ;
V_93 = F_11 ( V_19 -> V_101 . V_103 ) - 1 ;
if ( V_93 < 0 ) {
F_44 ( F_4 ( V_9 ) , L_11 ) ;
return - V_25 ;
}
V_19 -> V_26 |= F_54 ( V_93 ) ;
} else if ( V_75 == V_104 ) {
V_19 -> V_26 =
F_50 ( V_19 -> V_91 )
| V_105
| V_106
| F_51 ( V_19 -> V_90 )
| F_52 ( V_19 -> V_38 )
| V_97
| V_107
| V_99
| V_100 ;
V_24 = F_11 ( V_19 -> V_101 . V_108 ) - 1 ;
if ( V_24 < 0 ) {
F_44 ( F_4 ( V_9 ) , L_10 ) ;
return - V_25 ;
}
V_19 -> V_26 |= F_53 ( V_24 ) ;
V_93 = F_11 ( V_19 -> V_101 . V_109 ) - 1 ;
if ( V_93 < 0 ) {
F_44 ( F_4 ( V_9 ) , L_12 ) ;
return - V_25 ;
}
V_19 -> V_26 |= F_54 ( V_93 ) ;
}
F_41 ( F_4 ( V_9 ) , L_13 , V_35 , V_19 -> V_26 ) ;
return 0 ;
}
static int F_55 ( struct V_110 * V_101 )
{
if ( ( V_101 -> V_102 > V_111 )
|| ( V_101 -> V_108 > V_111 ) )
return - V_25 ;
if ( ( V_101 -> V_103 > V_112 )
|| ( V_101 -> V_109 > V_112 ) )
return - V_25 ;
return 0 ;
}
static int F_56 ( struct V_7 * V_9 ,
struct V_110 * V_101 )
{
struct V_6 * V_19 = F_2 ( V_9 ) ;
if ( F_55 ( V_101 ) ) {
F_44 ( F_4 ( V_9 ) , L_14 ) ;
return - V_25 ;
}
memcpy ( & V_19 -> V_101 , V_101 , sizeof( V_19 -> V_101 ) ) ;
return 0 ;
}
static struct V_16 *
F_57 ( struct V_7 * V_9 , struct V_113 * V_114 ,
unsigned int V_115 , enum V_92 V_75 ,
unsigned long V_116 , void * V_117 )
{
struct V_6 * V_19 = F_2 ( V_9 ) ;
struct V_15 * V_33 = NULL , * V_81 = NULL ;
struct V_113 * V_118 ;
int V_119 ;
unsigned int V_77 = 0 ;
unsigned long V_67 ;
struct V_16 * V_120 = NULL ;
if ( ! V_114 )
return NULL ;
if ( ! F_58 ( V_75 ) ) {
F_44 ( F_4 ( V_9 ) , L_15 ) ;
return NULL ;
}
F_41 ( F_4 ( V_9 ) , L_16 ,
V_35 , V_115 ,
V_75 == V_104 ? L_17 : L_18 ,
V_116 ) ;
F_26 ( & V_19 -> V_68 , V_67 ) ;
if ( F_49 ( V_9 , V_75 ) )
goto V_121;
F_59 (sgl, sg, sg_len, i) {
struct V_15 * V_65 = NULL ;
T_2 V_122 , V_123 , V_93 , V_124 ;
V_122 = F_60 ( V_118 ) ;
V_123 = F_61 ( V_118 ) ;
if ( F_62 ( ! V_122 ) ) {
F_44 ( F_4 ( V_9 ) , L_19 ) ;
goto V_121;
}
F_41 ( F_4 ( V_9 ) , L_20 ,
V_35 , V_119 , V_122 , V_123 ) ;
V_65 = F_36 ( V_19 ) ;
if ( ! V_65 ) {
F_44 ( F_4 ( V_9 ) , L_21 ) ;
if ( V_33 )
F_63 ( & V_33 -> V_73 , & V_19 -> V_78 ) ;
goto V_121;
}
if ( V_75 == V_94 ) {
V_65 -> V_41 . V_125 = V_19 -> V_101 . V_126 ;
V_65 -> V_41 . V_127 = V_123 ;
} else {
V_65 -> V_41 . V_125 = V_123 ;
V_65 -> V_41 . V_127 = V_19 -> V_101 . V_128 ;
}
V_93 = F_12 ( V_19 -> V_26 ) ;
V_124 = F_64 ( V_122 , 1 << V_93 )
? V_93
: V_129 ;
V_65 -> V_41 . V_42 = V_130
| V_131
| V_132
| ( V_122 >> V_124 ) ;
V_65 -> V_41 . V_47 = ( V_19 -> V_26 & ~ V_27 ) |
F_54 ( V_124 ) ;
F_41 ( F_4 ( V_9 ) ,
L_22 ,
V_35 , & V_65 -> V_41 . V_125 , & V_65 -> V_41 . V_127 , V_65 -> V_41 . V_42 ) ;
if ( V_81 )
F_40 ( V_9 , V_81 , V_65 ) ;
V_81 = V_65 ;
if ( ! V_33 )
V_33 = V_65 ;
F_41 ( F_4 ( V_9 ) , L_23 ,
V_35 , V_65 , V_33 ) ;
F_28 ( & V_65 -> V_80 , & V_33 -> V_73 ) ;
V_77 += V_122 ;
}
V_33 -> V_18 . V_116 = V_116 ;
V_33 -> V_77 = V_77 ;
V_33 -> V_75 = V_75 ;
V_120 = & V_33 -> V_18 ;
V_121:
F_30 ( & V_19 -> V_68 , V_67 ) ;
return V_120 ;
}
static struct V_16 *
F_65 ( struct V_7 * V_9 , T_6 V_133 ,
T_7 V_134 , T_7 V_135 ,
enum V_92 V_75 ,
unsigned long V_116 )
{
struct V_6 * V_19 = F_2 ( V_9 ) ;
struct V_15 * V_33 = NULL , * V_81 = NULL ;
unsigned int V_136 = V_134 / V_135 ;
int V_119 ;
unsigned long V_67 ;
F_41 ( F_4 ( V_9 ) , L_24 ,
V_35 , & V_133 , V_134 , V_135 ,
V_75 == V_104 ? L_25 : L_26 , V_116 ) ;
if ( ! F_58 ( V_75 ) ) {
F_44 ( F_4 ( V_9 ) , L_15 ) ;
return NULL ;
}
if ( F_66 ( V_20 , & V_19 -> V_21 ) ) {
F_44 ( F_4 ( V_9 ) , L_27 ) ;
return NULL ;
}
if ( F_49 ( V_9 , V_75 ) )
return NULL ;
for ( V_119 = 0 ; V_119 < V_136 ; V_119 ++ ) {
struct V_15 * V_65 = NULL ;
F_26 ( & V_19 -> V_68 , V_67 ) ;
V_65 = F_36 ( V_19 ) ;
if ( ! V_65 ) {
F_44 ( F_4 ( V_9 ) , L_21 ) ;
if ( V_33 )
F_63 ( & V_33 -> V_73 , & V_19 -> V_78 ) ;
F_30 ( & V_19 -> V_68 , V_67 ) ;
return NULL ;
}
F_30 ( & V_19 -> V_68 , V_67 ) ;
F_41 ( F_4 ( V_9 ) ,
L_28 ,
V_35 , V_65 , & V_65 -> V_18 . V_37 ) ;
if ( V_75 == V_94 ) {
V_65 -> V_41 . V_125 = V_19 -> V_101 . V_126 ;
V_65 -> V_41 . V_127 = V_133 + V_119 * V_135 ;
} else {
V_65 -> V_41 . V_125 = V_133 + V_119 * V_135 ;
V_65 -> V_41 . V_127 = V_19 -> V_101 . V_128 ;
}
V_65 -> V_41 . V_47 = V_19 -> V_26 ;
V_65 -> V_41 . V_42 = V_137
| V_131
| V_132
| V_135 >> F_12 ( V_65 -> V_41 . V_47 ) ;
F_41 ( F_4 ( V_9 ) ,
L_22 ,
V_35 , & V_65 -> V_41 . V_125 , & V_65 -> V_41 . V_127 , V_65 -> V_41 . V_42 ) ;
if ( V_81 )
F_40 ( V_9 , V_81 , V_65 ) ;
V_81 = V_65 ;
if ( ! V_33 )
V_33 = V_65 ;
F_41 ( F_4 ( V_9 ) , L_23 ,
V_35 , V_65 , V_33 ) ;
F_28 ( & V_65 -> V_80 , & V_33 -> V_73 ) ;
}
F_40 ( V_9 , V_81 , V_33 ) ;
V_33 -> V_18 . V_116 = V_116 ;
V_33 -> V_77 = V_134 ;
V_33 -> V_75 = V_75 ;
return & V_33 -> V_18 ;
}
static inline T_2 F_67 ( struct V_7 * V_9 , T_6 V_138 )
{
T_2 V_139 ;
if ( ! ( V_138 & 7 ) ) {
V_139 = V_140 ;
F_41 ( F_4 ( V_9 ) , L_29 , V_35 ) ;
} else if ( ! ( V_138 & 3 ) ) {
V_139 = V_141 ;
F_41 ( F_4 ( V_9 ) , L_30 , V_35 ) ;
} else if ( ! ( V_138 & 1 ) ) {
V_139 = V_142 ;
F_41 ( F_4 ( V_9 ) , L_31 , V_35 ) ;
} else {
V_139 = V_129 ;
F_41 ( F_4 ( V_9 ) , L_32 , V_35 ) ;
}
return V_139 ;
}
static struct V_15 *
F_68 ( struct V_7 * V_9 ,
struct V_6 * V_19 ,
struct V_15 * V_81 ,
T_6 V_143 , T_6 V_144 ,
struct V_145 * V_146 ,
struct V_147 * V_148 )
{
struct V_15 * V_65 ;
T_2 V_93 ;
unsigned long V_116 ;
T_7 V_149 ;
T_2 V_150 = F_69 ( 0x3f )
| F_51 ( 0 )
| F_52 ( 0 )
| V_99
| V_151 ;
V_93 = F_67 ( V_9 , V_143 | V_144 | V_148 -> V_152 ) ;
if ( V_148 -> V_152 >= ( V_153 << V_93 ) ) {
F_41 ( F_4 ( V_9 ) ,
L_33 ,
V_35 , V_148 -> V_152 ,
V_153 << V_93 ) ;
return NULL ;
}
if ( V_81 )
F_41 ( F_4 ( V_9 ) ,
L_34 , V_81 ) ;
if ( V_146 -> V_154 ) {
if ( V_146 -> V_155 )
V_150 |= V_156 ;
else
V_150 |= V_106 ;
}
if ( V_146 -> V_157 ) {
if ( V_146 -> V_158 )
V_150 |= V_159 ;
else
V_150 |= V_95 ;
}
F_26 ( & V_19 -> V_68 , V_116 ) ;
V_65 = F_36 ( V_19 ) ;
F_30 ( & V_19 -> V_68 , V_116 ) ;
if ( ! V_65 ) {
F_44 ( F_4 ( V_9 ) , L_21 ) ;
return NULL ;
}
V_150 |= F_54 ( V_93 ) ;
V_149 = V_148 -> V_152 >> V_93 ;
V_65 -> V_41 . V_125 = V_143 ;
V_65 -> V_41 . V_127 = V_144 ;
V_65 -> V_41 . V_160 = F_70 ( V_146 , V_148 ) ;
V_65 -> V_41 . V_161 = F_71 ( V_146 , V_148 ) ;
V_65 -> V_41 . V_42 = V_43
| V_131
| V_132
| V_149 ;
V_65 -> V_41 . V_47 = V_150 ;
F_41 ( F_4 ( V_9 ) ,
L_35 ,
V_35 , & V_65 -> V_41 . V_125 , & V_65 -> V_41 . V_127 ,
V_65 -> V_41 . V_42 , V_65 -> V_41 . V_47 ) ;
if ( V_81 )
F_40 ( V_9 , V_81 , V_65 ) ;
return V_65 ;
}
static struct V_16 *
F_72 ( struct V_7 * V_9 ,
struct V_145 * V_146 ,
unsigned long V_116 )
{
struct V_6 * V_19 = F_2 ( V_9 ) ;
struct V_15 * V_81 = NULL , * V_33 = NULL ;
T_6 V_128 , V_126 ;
T_7 V_162 = 0 , V_163 = 0 , V_122 = 0 ;
struct V_147 * V_148 ;
int V_119 ;
if ( ! V_146 || ! V_146 -> V_164 || ( V_146 -> V_165 != V_166 ) )
return NULL ;
if ( ( V_146 -> V_164 > 1 ) && ( V_146 -> V_167 > 1 ) )
return NULL ;
F_41 ( F_4 ( V_9 ) , L_36 ,
V_35 , & V_146 -> V_168 , & V_146 -> V_169 , V_146 -> V_164 ,
V_146 -> V_167 , V_116 ) ;
V_126 = V_146 -> V_168 ;
V_128 = V_146 -> V_169 ;
if ( V_146 -> V_164 > 1 ) {
V_33 = F_68 ( V_9 , V_19 ,
NULL ,
V_126 , V_128 ,
V_146 , V_146 -> V_114 ) ;
for ( V_119 = 0 ; V_119 < V_146 -> V_164 - 1 ; V_119 ++ )
F_42 ( V_9 , V_33 ) ;
F_41 ( F_4 ( V_9 ) , L_23 ,
V_35 , V_33 , V_33 ) ;
F_28 ( & V_33 -> V_80 , & V_33 -> V_73 ) ;
} else {
for ( V_119 = 0 ; V_119 < V_146 -> V_167 ; V_119 ++ ) {
T_7 V_170 = 0 , V_171 = 0 ;
struct V_15 * V_65 ;
V_148 = V_146 -> V_114 + V_119 ;
V_171 = F_71 ( V_146 , V_148 ) ;
V_170 = F_70 ( V_146 , V_148 ) ;
V_162 = V_148 -> V_152 + V_170 ;
V_163 = V_148 -> V_152 + V_171 ;
F_41 ( F_4 ( V_9 ) ,
L_37 ,
V_35 , V_148 -> V_152 , V_170 , V_171 ) ;
V_65 = F_68 ( V_9 , V_19 ,
V_81 ,
V_126 , V_128 ,
V_146 , V_148 ) ;
if ( ! V_65 ) {
F_63 ( & V_33 -> V_73 ,
& V_19 -> V_78 ) ;
return NULL ;
}
if ( ! V_33 )
V_33 = V_65 ;
F_41 ( F_4 ( V_9 ) , L_23 ,
V_35 , V_65 , V_33 ) ;
F_28 ( & V_65 -> V_80 , & V_33 -> V_73 ) ;
if ( V_146 -> V_155 )
V_126 += V_162 ;
if ( V_146 -> V_158 )
V_128 += V_163 ;
V_122 += V_148 -> V_152 ;
V_81 = V_65 ;
}
}
V_33 -> V_18 . V_66 = - V_172 ;
V_33 -> V_18 . V_116 = V_116 ;
V_33 -> V_77 = V_122 ;
return & V_33 -> V_18 ;
}
static struct V_16 *
F_73 ( struct V_7 * V_9 , T_6 V_173 , T_6 V_143 ,
T_7 V_122 , unsigned long V_116 )
{
struct V_6 * V_19 = F_2 ( V_9 ) ;
struct V_15 * V_33 = NULL , * V_81 = NULL ;
T_7 V_174 = V_122 , V_77 = 0 , V_149 ;
T_6 V_126 = V_143 , V_128 = V_173 ;
T_2 V_93 ;
T_2 V_150 = F_69 ( 0x3f )
| V_95
| V_106
| F_51 ( 0 )
| F_52 ( 0 )
| V_99
| V_151 ;
unsigned long V_67 ;
F_41 ( F_4 ( V_9 ) , L_38 ,
V_35 , & V_143 , & V_173 , V_122 , V_116 ) ;
if ( F_62 ( ! V_122 ) )
return NULL ;
V_93 = F_67 ( V_9 , V_126 | V_128 ) ;
while ( V_174 ) {
struct V_15 * V_65 = NULL ;
F_41 ( F_4 ( V_9 ) , L_39 , V_35 , V_174 ) ;
F_26 ( & V_19 -> V_68 , V_67 ) ;
V_65 = F_36 ( V_19 ) ;
F_30 ( & V_19 -> V_68 , V_67 ) ;
if ( ! V_65 ) {
F_44 ( F_4 ( V_9 ) , L_21 ) ;
if ( V_33 )
F_63 ( & V_33 -> V_73 , & V_19 -> V_78 ) ;
return NULL ;
}
V_126 += V_77 ;
V_128 += V_77 ;
if ( V_174 >= V_153 << V_93 )
V_77 = V_153 << V_93 ;
else
V_77 = V_174 ;
F_41 ( F_4 ( V_9 ) , L_40 , V_35 , V_77 ) ;
V_93 = F_67 ( V_9 ,
V_126 | V_128 | V_77 ) ;
V_150 &= ~ V_27 ;
V_150 |= F_54 ( V_93 ) ;
V_149 = V_77 >> V_93 ;
V_174 -= V_77 ;
V_65 -> V_41 . V_125 = V_126 ;
V_65 -> V_41 . V_127 = V_128 ;
V_65 -> V_41 . V_42 = V_130
| V_131
| V_132
| V_149 ;
V_65 -> V_41 . V_47 = V_150 ;
F_41 ( F_4 ( V_9 ) ,
L_35 ,
V_35 , & V_65 -> V_41 . V_125 , & V_65 -> V_41 . V_127 , V_65 -> V_41 . V_42 , V_65 -> V_41 . V_47 ) ;
if ( V_81 )
F_40 ( V_9 , V_81 , V_65 ) ;
V_81 = V_65 ;
if ( ! V_33 )
V_33 = V_65 ;
F_41 ( F_4 ( V_9 ) , L_23 ,
V_35 , V_65 , V_33 ) ;
F_28 ( & V_65 -> V_80 , & V_33 -> V_73 ) ;
}
V_33 -> V_18 . V_116 = V_116 ;
V_33 -> V_77 = V_122 ;
return & V_33 -> V_18 ;
}
static struct V_15 * F_74 ( struct V_7 * V_9 ,
struct V_6 * V_19 ,
T_6 V_128 ,
T_7 V_122 ,
int V_175 )
{
struct V_15 * V_65 ;
unsigned long V_116 ;
T_7 V_149 ;
T_2 V_93 ;
T_2 V_150 = F_69 ( 0x3f )
| V_159
| V_106
| F_51 ( 0 )
| F_52 ( 0 )
| V_99
| V_176
| V_151 ;
V_93 = F_67 ( V_9 , V_128 ) ;
if ( V_122 >= ( V_153 << V_93 ) ) {
F_44 ( F_4 ( V_9 ) ,
L_41 ,
V_35 ) ;
return NULL ;
}
F_26 ( & V_19 -> V_68 , V_116 ) ;
V_65 = F_36 ( V_19 ) ;
F_30 ( & V_19 -> V_68 , V_116 ) ;
if ( ! V_65 ) {
F_44 ( F_4 ( V_9 ) , L_21 ) ;
return NULL ;
}
V_150 |= F_54 ( V_93 ) ;
V_149 = V_122 >> V_93 ;
V_65 -> V_41 . V_127 = V_128 ;
V_65 -> V_41 . V_177 = V_175 ;
V_65 -> V_41 . V_42 = V_43
| V_131
| V_132
| V_149 ;
V_65 -> V_41 . V_47 = V_150 ;
F_41 ( F_4 ( V_9 ) ,
L_42 ,
V_35 , & V_65 -> V_41 . V_127 , V_65 -> V_41 . V_177 , V_65 -> V_41 . V_42 ,
V_65 -> V_41 . V_47 ) ;
return V_65 ;
}
static struct V_16 *
F_75 ( struct V_7 * V_9 , T_6 V_173 , int V_175 ,
T_7 V_122 , unsigned long V_116 )
{
struct V_6 * V_19 = F_2 ( V_9 ) ;
struct V_15 * V_65 ;
F_41 ( F_4 ( V_9 ) , L_43 ,
V_35 , & V_173 , V_122 , V_175 , V_116 ) ;
if ( F_62 ( ! V_122 ) )
return NULL ;
V_65 = F_74 ( V_9 , V_19 , V_173 , V_122 , V_175 ) ;
F_28 ( & V_65 -> V_80 , & V_65 -> V_73 ) ;
V_65 -> V_18 . V_66 = - V_172 ;
V_65 -> V_18 . V_116 = V_116 ;
V_65 -> V_77 = V_122 ;
return & V_65 -> V_18 ;
}
static struct V_16 *
F_76 ( struct V_7 * V_9 , struct V_113 * V_114 ,
unsigned int V_115 , int V_175 ,
unsigned long V_116 )
{
struct V_6 * V_19 = F_2 ( V_9 ) ;
struct V_15 * V_65 , * V_178 = NULL ,
* V_179 = NULL , * V_33 = NULL ;
struct V_113 * V_118 , * V_180 = NULL , * V_181 = NULL ;
T_7 V_182 = 0 , V_183 = 0 , V_122 = 0 ;
int V_119 ;
if ( ! V_114 )
return NULL ;
F_41 ( F_4 ( V_9 ) , L_44 ,
V_35 , V_115 , V_175 , V_116 ) ;
F_59 (sgl, sg, sg_len, i) {
F_41 ( F_4 ( V_9 ) , L_43 ,
V_35 , & F_61 ( V_118 ) , F_60 ( V_118 ) ,
V_175 , V_116 ) ;
V_65 = F_74 ( V_9 , V_19 ,
F_61 ( V_118 ) ,
F_60 ( V_118 ) ,
V_175 ) ;
if ( ! V_65 && V_33 )
F_63 ( & V_33 -> V_73 ,
& V_19 -> V_78 ) ;
if ( ! V_33 )
V_33 = V_65 ;
V_183 = V_182 ;
if ( V_180 )
V_182 = F_61 ( V_118 ) -
( F_61 ( V_180 ) + F_60 ( V_180 ) ) ;
if ( V_179 && V_178 ) {
if ( ( V_182 == V_183 ) &&
( F_60 ( V_181 ) == F_60 ( V_180 ) ) ) {
F_41 ( F_4 ( V_9 ) ,
L_45 ,
V_35 , V_178 , V_179 ) ;
F_42 ( V_9 , V_179 ) ;
V_179 -> V_41 . V_161 = V_182 ;
F_28 ( & V_178 -> V_80 ,
& V_19 -> V_78 ) ;
V_178 = V_179 ;
} else if ( V_183 ||
F_61 ( V_118 ) < F_61 ( V_180 ) ) {
F_40 ( V_9 , V_179 , V_178 ) ;
F_28 ( & V_65 -> V_80 ,
& V_33 -> V_73 ) ;
F_41 ( F_4 ( V_9 ) ,
L_23 ,
V_35 , V_65 , V_33 ) ;
}
}
if ( ( V_119 == ( V_115 - 1 ) ) &&
F_60 ( V_180 ) == F_60 ( V_118 ) ) {
F_41 ( F_4 ( V_9 ) ,
L_45 ,
V_35 , V_65 , V_178 ) ;
F_42 ( V_9 , V_178 ) ;
V_178 -> V_41 . V_161 = V_182 ;
F_28 ( & V_65 -> V_80 ,
& V_19 -> V_78 ) ;
}
V_179 = V_178 ;
V_178 = V_65 ;
V_181 = V_180 ;
V_180 = V_118 ;
V_122 += F_60 ( V_118 ) ;
}
V_33 -> V_18 . V_66 = - V_172 ;
V_33 -> V_18 . V_116 = V_116 ;
V_33 -> V_77 = V_122 ;
return & V_33 -> V_18 ;
}
static enum V_184
F_77 ( struct V_7 * V_9 , T_4 V_66 ,
struct V_185 * V_186 )
{
struct V_6 * V_19 = F_2 ( V_9 ) ;
struct V_1 * V_2 = F_5 ( V_19 -> V_9 . V_10 ) ;
struct V_15 * V_65 , * V_187 ;
struct V_188 * V_73 ;
enum V_184 V_120 ;
int V_189 , V_190 ;
T_2 V_191 , V_192 , V_193 , V_30 , V_175 ;
T_3 V_93 = 0 ;
unsigned long V_116 ;
bool V_194 ;
V_120 = F_78 ( V_9 , V_66 , V_186 ) ;
if ( V_120 == V_195 )
return V_120 ;
if ( ! V_186 )
return V_120 ;
F_26 ( & V_19 -> V_68 , V_116 ) ;
V_65 = F_38 ( & V_19 -> V_70 , struct V_15 , V_69 ) ;
if ( ! V_65 -> V_36 ) {
F_79 ( V_186 , V_65 -> V_77 ) ;
goto V_121;
}
V_189 = V_65 -> V_77 ;
V_30 = V_196 | V_197 ;
V_175 = V_100 | V_98 ;
if ( ( V_65 -> V_41 . V_47 & V_30 ) == V_175 ) {
F_16 ( V_2 , V_198 , V_19 -> V_30 ) ;
while ( ! ( F_14 ( V_19 , V_199 ) & V_200 ) )
F_18 () ;
}
for ( V_190 = 0 ; V_190 < V_201 ; V_190 ++ ) {
V_192 = F_14 ( V_19 , V_39 ) & 0xfffffffc ;
F_80 () ;
V_194 = ! ! ( F_14 ( V_19 , V_46 ) & V_202 ) ;
F_80 () ;
V_193 = F_14 ( V_19 , V_54 ) ;
F_80 () ;
V_191 = F_14 ( V_19 , V_39 ) & 0xfffffffc ;
F_80 () ;
if ( ( V_192 == V_191 ) && V_194 )
break;
}
if ( F_62 ( V_190 >= V_201 ) ) {
V_120 = V_203 ;
goto V_121;
}
if ( ( V_65 -> V_41 . V_47 & V_30 ) == V_175 ) {
F_16 ( V_2 , V_198 , V_19 -> V_30 ) ;
while ( ! ( F_14 ( V_19 , V_199 ) & V_200 ) )
F_18 () ;
}
V_73 = & V_65 -> V_73 ;
F_81 (desc, _desc, descs_list, desc_node) {
V_93 = F_12 ( V_65 -> V_41 . V_47 ) ;
V_189 -= ( V_65 -> V_41 . V_42 & 0xffffff ) << V_93 ;
if ( ( V_65 -> V_41 . V_82 & 0xfffffffc ) == V_191 )
break;
}
V_189 += V_193 << V_93 ;
F_79 ( V_186 , V_189 ) ;
F_41 ( F_4 ( V_9 ) ,
L_46 ,
V_35 , V_65 , & V_65 -> V_18 . V_37 , V_120 , V_66 , V_189 ) ;
V_121:
F_30 ( & V_19 -> V_68 , V_116 ) ;
return V_120 ;
}
static void F_82 ( struct V_6 * V_19 ,
struct V_15 * V_65 )
{
F_41 ( F_4 ( & V_19 -> V_9 ) , L_1 , V_35 , V_65 ) ;
F_39 ( & V_65 -> V_69 ) ;
F_63 ( & V_65 -> V_73 , & V_19 -> V_78 ) ;
}
static void F_83 ( struct V_6 * V_19 )
{
struct V_15 * V_65 ;
unsigned long V_116 ;
F_26 ( & V_19 -> V_68 , V_116 ) ;
if ( ! F_13 ( V_19 ) && ! F_37 ( & V_19 -> V_70 ) ) {
V_65 = F_38 ( & V_19 -> V_70 ,
struct V_15 ,
V_69 ) ;
F_20 ( F_4 ( & V_19 -> V_9 ) , L_1 , V_35 , V_65 ) ;
if ( ! V_65 -> V_36 )
F_19 ( V_19 , V_65 ) ;
}
F_30 ( & V_19 -> V_68 , V_116 ) ;
}
static void F_84 ( struct V_6 * V_19 )
{
struct V_15 * V_65 ;
struct V_16 * V_17 ;
V_65 = F_38 ( & V_19 -> V_70 , struct V_15 , V_69 ) ;
V_17 = & V_65 -> V_18 ;
if ( V_17 -> V_116 & V_204 )
F_85 ( V_17 , NULL ) ;
}
static void F_86 ( unsigned long V_205 )
{
struct V_6 * V_19 = (struct V_6 * ) V_205 ;
struct V_15 * V_65 ;
T_2 V_206 ;
F_41 ( F_4 ( & V_19 -> V_9 ) , L_47 ,
V_35 , V_19 -> V_21 ) ;
V_206 = V_207
| V_208
| V_209 ;
if ( F_7 ( V_19 ) ) {
F_84 ( V_19 ) ;
} else if ( ( V_19 -> V_21 & V_210 )
|| ( V_19 -> V_21 & V_206 ) ) {
struct V_16 * V_17 ;
if ( V_19 -> V_21 & V_207 )
F_44 ( F_4 ( & V_19 -> V_9 ) , L_48 ) ;
if ( V_19 -> V_21 & V_208 )
F_44 ( F_4 ( & V_19 -> V_9 ) , L_49 ) ;
if ( V_19 -> V_21 & V_209 )
F_44 ( F_4 ( & V_19 -> V_9 ) , L_50 ) ;
F_87 ( & V_19 -> V_68 ) ;
V_65 = F_38 ( & V_19 -> V_70 ,
struct V_15 ,
V_69 ) ;
F_20 ( F_4 ( & V_19 -> V_9 ) , L_1 , V_35 , V_65 ) ;
F_88 ( ! V_65 -> V_36 ) ;
V_17 = & V_65 -> V_18 ;
F_82 ( V_19 , V_65 ) ;
F_89 ( & V_19 -> V_68 ) ;
if ( ! F_7 ( V_19 ) ) {
F_90 ( V_17 ) ;
if ( V_17 -> V_116 & V_204 )
F_85 ( V_17 , NULL ) ;
}
F_91 ( V_17 ) ;
F_83 ( V_19 ) ;
}
}
static T_8 F_92 ( int V_211 , void * V_212 )
{
struct V_1 * V_2 = (struct V_1 * ) V_212 ;
struct V_6 * V_19 ;
T_2 V_213 , V_21 , V_214 ;
T_2 V_215 , V_216 ;
int V_119 , V_120 = V_217 ;
do {
V_213 = F_17 ( V_2 , V_218 ) ;
V_21 = F_17 ( V_2 , V_219 ) ;
V_214 = V_21 & V_213 ;
F_20 ( V_2 -> V_14 . V_11 ,
L_51 ,
V_35 , V_21 , V_213 , V_214 ) ;
if ( ! V_214 )
break;
for ( V_119 = 0 ; V_119 < V_2 -> V_14 . V_220 ; V_119 ++ ) {
if ( ! ( ( 1 << V_119 ) & V_214 ) )
continue;
V_19 = & V_2 -> V_9 [ V_119 ] ;
V_215 = F_14 ( V_19 , V_221 ) ;
V_216 = F_14 ( V_19 , V_199 ) ;
V_19 -> V_21 = V_216 & V_215 ;
F_20 ( V_2 -> V_14 . V_11 ,
L_52 ,
V_35 , V_119 , V_215 , V_216 ) ;
F_20 ( F_4 ( & V_19 -> V_9 ) ,
L_2 ,
V_35 ,
F_14 ( V_19 , V_46 ) ,
F_14 ( V_19 , V_39 ) ,
F_14 ( V_19 , V_51 ) ,
F_14 ( V_19 , V_52 ) ,
F_14 ( V_19 , V_53 ) ,
F_14 ( V_19 , V_54 ) ) ;
if ( V_19 -> V_21 & ( V_207 | V_208 ) )
F_16 ( V_2 , V_31 , V_19 -> V_30 ) ;
F_93 ( & V_19 -> V_222 ) ;
V_120 = V_223 ;
}
} while ( V_214 );
return V_120 ;
}
static void F_94 ( struct V_7 * V_9 )
{
struct V_6 * V_19 = F_2 ( V_9 ) ;
F_41 ( F_4 ( & V_19 -> V_9 ) , L_53 , V_35 ) ;
if ( ! F_7 ( V_19 ) )
F_83 ( V_19 ) ;
return;
}
static int F_95 ( struct V_7 * V_9 ,
struct V_110 * V_224 )
{
struct V_6 * V_19 = F_2 ( V_9 ) ;
int V_120 ;
unsigned long V_116 ;
F_41 ( F_4 ( V_9 ) , L_53 , V_35 ) ;
F_26 ( & V_19 -> V_68 , V_116 ) ;
V_120 = F_56 ( V_9 , V_224 ) ;
F_30 ( & V_19 -> V_68 , V_116 ) ;
return V_120 ;
}
static int F_96 ( struct V_7 * V_9 )
{
struct V_6 * V_19 = F_2 ( V_9 ) ;
struct V_1 * V_2 = F_5 ( V_19 -> V_9 . V_10 ) ;
unsigned long V_116 ;
F_41 ( F_4 ( V_9 ) , L_53 , V_35 ) ;
if ( F_66 ( V_22 , & V_19 -> V_21 ) )
return 0 ;
F_26 ( & V_19 -> V_68 , V_116 ) ;
F_16 ( V_2 , V_225 , V_19 -> V_30 ) ;
while ( F_14 ( V_19 , V_46 )
& ( V_226 | V_227 ) )
F_18 () ;
F_30 ( & V_19 -> V_68 , V_116 ) ;
return 0 ;
}
static int F_97 ( struct V_7 * V_9 )
{
struct V_6 * V_19 = F_2 ( V_9 ) ;
struct V_1 * V_2 = F_5 ( V_19 -> V_9 . V_10 ) ;
unsigned long V_116 ;
F_41 ( F_4 ( V_9 ) , L_53 , V_35 ) ;
F_26 ( & V_19 -> V_68 , V_116 ) ;
if ( ! F_9 ( V_19 ) ) {
F_30 ( & V_19 -> V_68 , V_116 ) ;
return 0 ;
}
F_16 ( V_2 , V_228 , V_19 -> V_30 ) ;
F_98 ( V_22 , & V_19 -> V_21 ) ;
F_30 ( & V_19 -> V_68 , V_116 ) ;
return 0 ;
}
static int F_99 ( struct V_7 * V_9 )
{
struct V_15 * V_65 , * V_187 ;
struct V_6 * V_19 = F_2 ( V_9 ) ;
struct V_1 * V_2 = F_5 ( V_19 -> V_9 . V_10 ) ;
unsigned long V_116 ;
F_41 ( F_4 ( V_9 ) , L_53 , V_35 ) ;
F_26 ( & V_19 -> V_68 , V_116 ) ;
F_16 ( V_2 , V_31 , V_19 -> V_30 ) ;
while ( F_17 ( V_2 , V_29 ) & V_19 -> V_30 )
F_18 () ;
F_81 (desc, _desc, &atchan->xfers_list, xfer_node)
F_82 ( V_19 , V_65 ) ;
F_98 ( V_22 , & V_19 -> V_21 ) ;
F_98 ( V_20 , & V_19 -> V_21 ) ;
F_30 ( & V_19 -> V_68 , V_116 ) ;
return 0 ;
}
static int F_100 ( struct V_7 * V_9 )
{
struct V_6 * V_19 = F_2 ( V_9 ) ;
struct V_15 * V_65 ;
int V_119 ;
unsigned long V_116 ;
F_26 ( & V_19 -> V_68 , V_116 ) ;
if ( F_13 ( V_19 ) ) {
F_44 ( F_4 ( V_9 ) ,
L_54 ) ;
V_119 = - V_229 ;
goto V_121;
}
if ( ! F_37 ( & V_19 -> V_78 ) ) {
F_44 ( F_4 ( V_9 ) ,
L_55 ) ;
V_119 = - V_229 ;
goto V_121;
}
for ( V_119 = 0 ; V_119 < V_230 ; V_119 ++ ) {
V_65 = F_31 ( V_9 , V_231 ) ;
if ( ! V_65 ) {
F_101 ( F_4 ( V_9 ) ,
L_56 , V_119 ) ;
break;
}
F_28 ( & V_65 -> V_80 , & V_19 -> V_78 ) ;
}
F_102 ( V_9 ) ;
F_41 ( F_4 ( V_9 ) , L_57 , V_35 , V_119 ) ;
V_121:
F_30 ( & V_19 -> V_68 , V_116 ) ;
return V_119 ;
}
static void F_103 ( struct V_7 * V_9 )
{
struct V_6 * V_19 = F_2 ( V_9 ) ;
struct V_1 * V_2 = F_5 ( V_9 -> V_10 ) ;
struct V_15 * V_65 , * V_187 ;
F_81 (desc, _desc, &atchan->free_descs_list, desc_node) {
F_41 ( F_4 ( V_9 ) , L_58 , V_35 , V_65 ) ;
F_39 ( & V_65 -> V_80 ) ;
F_104 ( V_2 -> V_72 , V_65 , V_65 -> V_18 . V_37 ) ;
}
return;
}
static int F_105 ( struct V_10 * V_11 )
{
struct V_232 * V_233 = F_106 ( V_11 ) ;
struct V_1 * V_2 = F_107 ( V_233 ) ;
struct V_7 * V_9 , * V_234 ;
F_81 (chan, _chan, &atxdmac->dma.channels, device_node) {
struct V_6 * V_19 = F_2 ( V_9 ) ;
if ( F_13 ( V_19 ) && ! F_7 ( V_19 ) )
return - V_235 ;
}
return 0 ;
}
static int F_108 ( struct V_10 * V_11 )
{
struct V_232 * V_233 = F_106 ( V_11 ) ;
struct V_1 * V_2 = F_107 ( V_233 ) ;
struct V_7 * V_9 , * V_234 ;
F_81 (chan, _chan, &atxdmac->dma.channels, device_node) {
struct V_6 * V_19 = F_2 ( V_9 ) ;
V_19 -> V_236 = F_14 ( V_19 , V_46 ) ;
if ( F_7 ( V_19 ) ) {
if ( ! F_9 ( V_19 ) )
F_96 ( V_9 ) ;
V_19 -> V_237 = F_14 ( V_19 , V_221 ) ;
V_19 -> V_238 = F_14 ( V_19 , V_39 ) ;
V_19 -> V_239 = F_14 ( V_19 , V_51 ) ;
}
}
V_2 -> V_240 = F_17 ( V_2 , V_218 ) ;
F_15 ( V_2 ) ;
F_109 ( V_2 -> V_241 ) ;
return 0 ;
}
static int F_110 ( struct V_10 * V_11 )
{
struct V_232 * V_233 = F_106 ( V_11 ) ;
struct V_1 * V_2 = F_107 ( V_233 ) ;
struct V_6 * V_19 ;
struct V_7 * V_9 , * V_234 ;
int V_119 ;
F_111 ( V_2 -> V_241 ) ;
for ( V_119 = 0 ; V_119 < V_2 -> V_14 . V_220 ; V_119 ++ ) {
V_19 = & V_2 -> V_9 [ V_119 ] ;
while ( F_14 ( V_19 , V_199 ) )
F_18 () ;
}
F_16 ( V_2 , V_62 , V_2 -> V_240 ) ;
F_81 (chan, _chan, &atxdmac->dma.channels, device_node) {
V_19 = F_2 ( V_9 ) ;
F_23 ( V_19 , V_46 , V_19 -> V_236 ) ;
if ( F_7 ( V_19 ) ) {
if ( F_9 ( V_19 ) )
F_97 ( V_9 ) ;
F_23 ( V_19 , V_39 , V_19 -> V_238 ) ;
F_23 ( V_19 , V_51 , V_19 -> V_239 ) ;
F_23 ( V_19 , V_59 , V_19 -> V_237 ) ;
F_24 () ;
F_16 ( V_2 , V_63 , V_19 -> V_30 ) ;
}
}
return 0 ;
}
static int F_112 ( struct V_232 * V_233 )
{
struct V_242 * V_243 ;
struct V_1 * V_2 ;
int V_211 , V_152 , V_244 , V_119 , V_120 ;
void T_1 * V_245 ;
T_2 V_34 ;
V_243 = F_113 ( V_233 , V_246 , 0 ) ;
if ( ! V_243 )
return - V_25 ;
V_211 = F_114 ( V_233 , 0 ) ;
if ( V_211 < 0 )
return V_211 ;
V_245 = F_115 ( & V_233 -> V_11 , V_243 ) ;
if ( F_116 ( V_245 ) )
return F_117 ( V_245 ) ;
V_34 = F_118 ( V_245 + V_247 ) ;
V_244 = F_119 ( V_34 ) ;
if ( V_244 > V_248 ) {
F_44 ( & V_233 -> V_11 , L_59 ,
V_244 ) ;
return - V_25 ;
}
V_152 = sizeof( * V_2 ) ;
V_152 += V_244 * sizeof( struct V_6 ) ;
V_2 = F_120 ( & V_233 -> V_11 , V_152 , V_249 ) ;
if ( ! V_2 ) {
F_44 ( & V_233 -> V_11 , L_60 ) ;
return - V_250 ;
}
V_2 -> V_4 = V_245 ;
V_2 -> V_211 = V_211 ;
V_2 -> V_241 = F_121 ( & V_233 -> V_11 , L_61 ) ;
if ( F_116 ( V_2 -> V_241 ) ) {
F_44 ( & V_233 -> V_11 , L_62 ) ;
return F_117 ( V_2 -> V_241 ) ;
}
V_120 = F_122 ( V_2 -> V_211 , F_92 , 0 , L_63 , V_2 ) ;
if ( V_120 ) {
F_44 ( & V_233 -> V_11 , L_64 ) ;
return V_120 ;
}
V_120 = F_111 ( V_2 -> V_241 ) ;
if ( V_120 ) {
F_44 ( & V_233 -> V_11 , L_65 ) ;
goto V_251;
}
V_2 -> V_72 =
F_123 ( F_124 ( & V_233 -> V_11 ) , & V_233 -> V_11 ,
sizeof( struct V_15 ) , 4 , 0 ) ;
if ( ! V_2 -> V_72 ) {
F_44 ( & V_233 -> V_11 , L_66 ) ;
V_120 = - V_250 ;
goto V_252;
}
F_125 ( V_253 , V_2 -> V_14 . V_254 ) ;
F_125 ( V_255 , V_2 -> V_14 . V_254 ) ;
F_125 ( V_256 , V_2 -> V_14 . V_254 ) ;
F_125 ( V_257 , V_2 -> V_14 . V_254 ) ;
F_125 ( V_258 , V_2 -> V_14 . V_254 ) ;
F_125 ( V_259 , V_2 -> V_14 . V_254 ) ;
F_125 ( V_260 , V_2 -> V_14 . V_254 ) ;
V_2 -> V_14 . V_11 = & V_233 -> V_11 ;
V_2 -> V_14 . V_261 = F_100 ;
V_2 -> V_14 . V_262 = F_103 ;
V_2 -> V_14 . V_263 = F_77 ;
V_2 -> V_14 . V_264 = F_94 ;
V_2 -> V_14 . V_265 = F_65 ;
V_2 -> V_14 . V_266 = F_72 ;
V_2 -> V_14 . V_267 = F_73 ;
V_2 -> V_14 . V_268 = F_75 ;
V_2 -> V_14 . V_269 = F_76 ;
V_2 -> V_14 . V_270 = F_57 ;
V_2 -> V_14 . V_271 = F_95 ;
V_2 -> V_14 . V_272 = F_96 ;
V_2 -> V_14 . V_273 = F_97 ;
V_2 -> V_14 . V_274 = F_99 ;
V_2 -> V_14 . V_275 = V_276 ;
V_2 -> V_14 . V_277 = V_276 ;
V_2 -> V_14 . V_278 = F_126 ( V_94 ) | F_126 ( V_104 ) ;
V_2 -> V_14 . V_279 = V_280 ;
F_15 ( V_2 ) ;
F_33 ( & V_2 -> V_14 . V_281 ) ;
for ( V_119 = 0 ; V_119 < V_244 ; V_119 ++ ) {
struct V_6 * V_19 = & V_2 -> V_9 [ V_119 ] ;
V_19 -> V_9 . V_10 = & V_2 -> V_14 ;
F_28 ( & V_19 -> V_9 . V_282 ,
& V_2 -> V_14 . V_281 ) ;
V_19 -> V_283 = F_1 ( V_2 , V_119 ) ;
V_19 -> V_30 = 1 << V_119 ;
F_127 ( & V_19 -> V_68 ) ;
F_33 ( & V_19 -> V_70 ) ;
F_33 ( & V_19 -> V_78 ) ;
F_128 ( & V_19 -> V_222 , F_86 ,
( unsigned long ) V_19 ) ;
while ( F_14 ( V_19 , V_199 ) )
F_18 () ;
}
F_129 ( V_233 , V_2 ) ;
V_120 = F_130 ( & V_2 -> V_14 ) ;
if ( V_120 ) {
F_44 ( & V_233 -> V_11 , L_67 ) ;
goto V_252;
}
V_120 = F_131 ( V_233 -> V_11 . V_284 ,
F_43 , V_2 ) ;
if ( V_120 ) {
F_44 ( & V_233 -> V_11 , L_68 ) ;
goto V_285;
}
F_132 ( & V_233 -> V_11 , L_69 ,
V_244 , V_2 -> V_4 ) ;
return 0 ;
V_285:
F_133 ( & V_2 -> V_14 ) ;
V_252:
F_109 ( V_2 -> V_241 ) ;
V_251:
F_134 ( V_2 -> V_211 , V_2 ) ;
return V_120 ;
}
static int F_135 ( struct V_232 * V_233 )
{
struct V_1 * V_2 = (struct V_1 * ) F_107 ( V_233 ) ;
int V_119 ;
F_15 ( V_2 ) ;
F_136 ( V_233 -> V_11 . V_284 ) ;
F_133 ( & V_2 -> V_14 ) ;
F_109 ( V_2 -> V_241 ) ;
F_134 ( V_2 -> V_211 , V_2 ) ;
for ( V_119 = 0 ; V_119 < V_2 -> V_14 . V_220 ; V_119 ++ ) {
struct V_6 * V_19 = & V_2 -> V_9 [ V_119 ] ;
F_137 ( & V_19 -> V_222 ) ;
F_103 ( & V_19 -> V_9 ) ;
}
return 0 ;
}
static int T_9 F_138 ( void )
{
return F_139 ( & V_286 , F_112 ) ;
}
