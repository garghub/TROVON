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
if ( F_7 ( V_19 ) ) {
V_34 = V_40 ;
F_23 ( V_19 , V_41 , V_33 -> V_42 . V_43 ) ;
} else {
V_34 = V_44 ;
}
V_34 |= V_45
| V_46
| V_47 ;
F_23 ( V_19 , V_48 , V_34 ) ;
F_20 ( F_4 ( & V_19 -> V_9 ) ,
L_2 ,
V_35 , F_14 ( V_19 , V_41 ) ,
F_14 ( V_19 , V_39 ) ,
F_14 ( V_19 , V_48 ) ,
F_14 ( V_19 , V_49 ) ,
F_14 ( V_19 , V_50 ) ,
F_14 ( V_19 , V_51 ) ) ;
F_23 ( V_19 , V_52 , 0xffffffff ) ;
V_34 = V_53 | V_54 | V_55 ;
if ( F_7 ( V_19 ) )
F_23 ( V_19 , V_56 ,
V_34 | V_57 ) ;
else
F_23 ( V_19 , V_56 ,
V_34 | V_58 ) ;
F_16 ( V_2 , V_59 , V_19 -> V_30 ) ;
F_20 ( F_4 ( & V_19 -> V_9 ) ,
L_3 , V_35 , V_19 -> V_30 ) ;
F_24 () ;
F_16 ( V_2 , V_60 , V_19 -> V_30 ) ;
F_20 ( F_4 ( & V_19 -> V_9 ) ,
L_2 ,
V_35 , F_14 ( V_19 , V_41 ) ,
F_14 ( V_19 , V_39 ) ,
F_14 ( V_19 , V_48 ) ,
F_14 ( V_19 , V_49 ) ,
F_14 ( V_19 , V_50 ) ,
F_14 ( V_19 , V_51 ) ) ;
}
static T_4 F_25 ( struct V_16 * V_61 )
{
struct V_15 * V_62 = F_6 ( V_61 ) ;
struct V_6 * V_19 = F_2 ( V_61 -> V_9 ) ;
T_4 V_63 ;
unsigned long V_64 ;
F_26 ( & V_19 -> V_65 , V_64 ) ;
V_63 = F_27 ( V_61 ) ;
F_20 ( F_4 ( V_61 -> V_9 ) , L_4 ,
V_35 , V_19 , V_62 ) ;
F_28 ( & V_62 -> V_66 , & V_19 -> V_67 ) ;
if ( F_29 ( & V_19 -> V_67 ) )
F_19 ( V_19 , V_62 ) ;
F_30 ( & V_19 -> V_65 , V_64 ) ;
return V_63 ;
}
static struct V_15 * F_31 ( struct V_7 * V_9 ,
T_5 V_68 )
{
struct V_15 * V_62 ;
struct V_1 * V_2 = F_5 ( V_9 -> V_10 ) ;
T_6 V_37 ;
V_62 = F_32 ( V_2 -> V_69 , V_68 , & V_37 ) ;
if ( V_62 ) {
memset ( V_62 , 0 , sizeof( * V_62 ) ) ;
F_33 ( & V_62 -> V_70 ) ;
F_34 ( & V_62 -> V_18 , V_9 ) ;
V_62 -> V_18 . V_71 = F_25 ;
V_62 -> V_18 . V_37 = V_37 ;
}
return V_62 ;
}
static struct V_15 * F_35 ( struct V_6 * V_19 )
{
struct V_15 * V_62 ;
if ( F_36 ( & V_19 -> V_72 ) ) {
V_62 = F_31 ( & V_19 -> V_9 , V_73 ) ;
} else {
V_62 = F_37 ( & V_19 -> V_72 ,
struct V_15 , V_74 ) ;
F_38 ( & V_62 -> V_74 ) ;
V_62 -> V_36 = false ;
}
return V_62 ;
}
static struct V_7 * F_39 ( struct V_75 * V_76 ,
struct V_77 * V_77 )
{
struct V_1 * V_2 = V_77 -> V_78 ;
struct V_6 * V_19 ;
struct V_7 * V_9 ;
struct V_10 * V_11 = V_2 -> V_14 . V_11 ;
if ( V_76 -> V_79 != 1 ) {
F_40 ( V_11 , L_5 ) ;
return NULL ;
}
V_9 = F_41 ( & V_2 -> V_14 ) ;
if ( ! V_9 ) {
F_40 ( V_11 , L_6 ) ;
return NULL ;
}
V_19 = F_2 ( V_9 ) ;
V_19 -> V_38 = F_42 ( V_76 -> args [ 0 ] ) ;
V_19 -> V_80 = F_43 ( V_76 -> args [ 0 ] ) ;
V_19 -> V_81 = F_44 ( V_76 -> args [ 0 ] ) ;
F_45 ( V_11 , L_7 ,
V_19 -> V_38 , V_19 -> V_80 , V_19 -> V_81 ) ;
return V_9 ;
}
static int F_46 ( struct V_7 * V_9 ,
enum V_82 V_83 )
{
struct V_6 * V_19 = F_2 ( V_9 ) ;
int V_24 , V_84 ;
if ( V_83 == V_85 ) {
V_19 -> V_26 =
F_47 ( V_19 -> V_81 )
| V_86
| V_87
| F_48 ( V_19 -> V_38 )
| F_49 ( V_19 -> V_80 )
| V_88
| V_89
| V_90
| V_91 ;
V_24 = F_11 ( V_19 -> V_92 . V_93 ) - 1 ;
if ( V_24 < 0 ) {
F_40 ( F_4 ( V_9 ) , L_8 ) ;
return - V_25 ;
}
V_19 -> V_26 |= F_50 ( V_24 ) ;
V_84 = F_11 ( V_19 -> V_92 . V_94 ) - 1 ;
if ( V_84 < 0 ) {
F_40 ( F_4 ( V_9 ) , L_9 ) ;
return - V_25 ;
}
V_19 -> V_26 |= F_51 ( V_84 ) ;
} else if ( V_83 == V_95 ) {
V_19 -> V_26 =
F_47 ( V_19 -> V_81 )
| V_96
| V_97
| F_48 ( V_19 -> V_80 )
| F_49 ( V_19 -> V_38 )
| V_88
| V_98
| V_90
| V_91 ;
V_24 = F_11 ( V_19 -> V_92 . V_99 ) - 1 ;
if ( V_24 < 0 ) {
F_40 ( F_4 ( V_9 ) , L_8 ) ;
return - V_25 ;
}
V_19 -> V_26 |= F_50 ( V_24 ) ;
V_84 = F_11 ( V_19 -> V_92 . V_100 ) - 1 ;
if ( V_84 < 0 ) {
F_40 ( F_4 ( V_9 ) , L_10 ) ;
return - V_25 ;
}
V_19 -> V_26 |= F_51 ( V_84 ) ;
}
F_45 ( F_4 ( V_9 ) , L_11 , V_35 , V_19 -> V_26 ) ;
return 0 ;
}
static int F_52 ( struct V_101 * V_92 )
{
if ( ( V_92 -> V_93 > V_102 )
|| ( V_92 -> V_99 > V_102 ) )
return - V_25 ;
if ( ( V_92 -> V_94 > V_103 )
|| ( V_92 -> V_100 > V_103 ) )
return - V_25 ;
return 0 ;
}
static int F_53 ( struct V_7 * V_9 ,
struct V_101 * V_92 )
{
struct V_6 * V_19 = F_2 ( V_9 ) ;
if ( F_52 ( V_92 ) ) {
F_40 ( F_4 ( V_9 ) , L_12 ) ;
return - V_25 ;
}
memcpy ( & V_19 -> V_92 , V_92 , sizeof( V_19 -> V_92 ) ) ;
return 0 ;
}
static struct V_16 *
F_54 ( struct V_7 * V_9 , struct V_104 * V_105 ,
unsigned int V_106 , enum V_82 V_83 ,
unsigned long V_107 , void * V_108 )
{
struct V_6 * V_19 = F_2 ( V_9 ) ;
struct V_15 * V_33 = NULL , * V_109 = NULL ;
struct V_104 * V_110 ;
int V_111 ;
unsigned int V_112 = 0 ;
unsigned long V_64 ;
struct V_16 * V_113 = NULL ;
if ( ! V_105 )
return NULL ;
if ( ! F_55 ( V_83 ) ) {
F_40 ( F_4 ( V_9 ) , L_13 ) ;
return NULL ;
}
F_45 ( F_4 ( V_9 ) , L_14 ,
V_35 , V_106 ,
V_83 == V_95 ? L_15 : L_16 ,
V_107 ) ;
F_26 ( & V_19 -> V_65 , V_64 ) ;
if ( F_46 ( V_9 , V_83 ) )
goto V_114;
F_56 (sgl, sg, sg_len, i) {
struct V_15 * V_62 = NULL ;
T_2 V_115 , V_116 , V_84 , V_117 ;
V_115 = F_57 ( V_110 ) ;
V_116 = F_58 ( V_110 ) ;
if ( F_59 ( ! V_115 ) ) {
F_40 ( F_4 ( V_9 ) , L_17 ) ;
goto V_114;
}
F_45 ( F_4 ( V_9 ) , L_18 ,
V_35 , V_111 , V_115 , V_116 ) ;
V_62 = F_35 ( V_19 ) ;
if ( ! V_62 ) {
F_40 ( F_4 ( V_9 ) , L_19 ) ;
if ( V_33 )
F_60 ( & V_33 -> V_70 , & V_19 -> V_72 ) ;
goto V_114;
}
if ( V_83 == V_85 ) {
V_62 -> V_42 . V_118 = V_19 -> V_92 . V_119 ;
V_62 -> V_42 . V_120 = V_116 ;
} else {
V_62 -> V_42 . V_118 = V_116 ;
V_62 -> V_42 . V_120 = V_19 -> V_92 . V_121 ;
}
V_62 -> V_42 . V_43 = V_19 -> V_26 ;
V_84 = F_12 ( V_62 -> V_42 . V_43 ) ;
V_117 = F_61 ( V_115 , 1 << V_84 )
? F_12 ( V_62 -> V_42 . V_43 )
: V_122 ;
V_62 -> V_42 . V_123 = V_124
| V_125
| V_126
| ( V_111 == V_106 - 1 ? 0 : V_127 )
| ( V_115 >> V_117 ) ;
F_45 ( F_4 ( V_9 ) ,
L_20 ,
V_35 , & V_62 -> V_42 . V_118 , & V_62 -> V_42 . V_120 , V_62 -> V_42 . V_123 ) ;
if ( V_109 ) {
V_109 -> V_42 . V_128 = V_62 -> V_18 . V_37 ;
F_45 ( F_4 ( V_9 ) ,
L_21 ,
V_35 , V_109 , & V_109 -> V_42 . V_128 ) ;
}
V_109 = V_62 ;
if ( ! V_33 )
V_33 = V_62 ;
F_45 ( F_4 ( V_9 ) , L_22 ,
V_35 , V_62 , V_33 ) ;
F_28 ( & V_62 -> V_74 , & V_33 -> V_70 ) ;
V_112 += V_115 ;
}
V_33 -> V_18 . V_107 = V_107 ;
V_33 -> V_112 = V_112 ;
V_33 -> V_83 = V_83 ;
V_113 = & V_33 -> V_18 ;
V_114:
F_30 ( & V_19 -> V_65 , V_64 ) ;
return V_113 ;
}
static struct V_16 *
F_62 ( struct V_7 * V_9 , T_6 V_129 ,
T_7 V_130 , T_7 V_131 ,
enum V_82 V_83 ,
unsigned long V_107 )
{
struct V_6 * V_19 = F_2 ( V_9 ) ;
struct V_15 * V_33 = NULL , * V_109 = NULL ;
unsigned int V_132 = V_130 / V_131 ;
int V_111 ;
unsigned long V_64 ;
F_45 ( F_4 ( V_9 ) , L_23 ,
V_35 , & V_129 , V_130 , V_131 ,
V_83 == V_95 ? L_24 : L_25 , V_107 ) ;
if ( ! F_55 ( V_83 ) ) {
F_40 ( F_4 ( V_9 ) , L_13 ) ;
return NULL ;
}
if ( F_63 ( V_20 , & V_19 -> V_21 ) ) {
F_40 ( F_4 ( V_9 ) , L_26 ) ;
return NULL ;
}
if ( F_46 ( V_9 , V_83 ) )
return NULL ;
for ( V_111 = 0 ; V_111 < V_132 ; V_111 ++ ) {
struct V_15 * V_62 = NULL ;
F_26 ( & V_19 -> V_65 , V_64 ) ;
V_62 = F_35 ( V_19 ) ;
if ( ! V_62 ) {
F_40 ( F_4 ( V_9 ) , L_19 ) ;
if ( V_33 )
F_60 ( & V_33 -> V_70 , & V_19 -> V_72 ) ;
F_30 ( & V_19 -> V_65 , V_64 ) ;
return NULL ;
}
F_30 ( & V_19 -> V_65 , V_64 ) ;
F_45 ( F_4 ( V_9 ) ,
L_27 ,
V_35 , V_62 , & V_62 -> V_18 . V_37 ) ;
if ( V_83 == V_85 ) {
V_62 -> V_42 . V_118 = V_19 -> V_92 . V_119 ;
V_62 -> V_42 . V_120 = V_129 + V_111 * V_131 ;
} else {
V_62 -> V_42 . V_118 = V_129 + V_111 * V_131 ;
V_62 -> V_42 . V_120 = V_19 -> V_92 . V_121 ;
}
V_62 -> V_42 . V_43 = V_19 -> V_26 ;
V_62 -> V_42 . V_123 = V_133
| V_125
| V_126
| V_127
| V_131 >> F_12 ( V_62 -> V_42 . V_43 ) ;
F_45 ( F_4 ( V_9 ) ,
L_20 ,
V_35 , & V_62 -> V_42 . V_118 , & V_62 -> V_42 . V_120 , V_62 -> V_42 . V_123 ) ;
if ( V_109 ) {
V_109 -> V_42 . V_128 = V_62 -> V_18 . V_37 ;
F_45 ( F_4 ( V_9 ) ,
L_21 ,
V_35 , V_109 , & V_109 -> V_42 . V_128 ) ;
}
V_109 = V_62 ;
if ( ! V_33 )
V_33 = V_62 ;
F_45 ( F_4 ( V_9 ) , L_22 ,
V_35 , V_62 , V_33 ) ;
F_28 ( & V_62 -> V_74 , & V_33 -> V_70 ) ;
}
V_109 -> V_42 . V_128 = V_33 -> V_18 . V_37 ;
F_45 ( F_4 ( V_9 ) ,
L_21 ,
V_35 , V_109 , & V_109 -> V_42 . V_128 ) ;
V_33 -> V_18 . V_107 = V_107 ;
V_33 -> V_112 = V_130 ;
V_33 -> V_83 = V_83 ;
return & V_33 -> V_18 ;
}
static struct V_16 *
F_64 ( struct V_7 * V_9 , T_6 V_134 , T_6 V_135 ,
T_7 V_115 , unsigned long V_107 )
{
struct V_6 * V_19 = F_2 ( V_9 ) ;
struct V_15 * V_33 = NULL , * V_109 = NULL ;
T_7 V_136 = V_115 , V_112 = 0 , V_137 ;
T_6 V_119 = V_135 , V_121 = V_134 ;
T_2 V_84 ;
T_2 V_138 = V_86
| V_97
| F_48 ( 0 )
| F_49 ( 0 )
| V_90
| V_139 ;
unsigned long V_64 ;
F_45 ( F_4 ( V_9 ) , L_28 ,
V_35 , & V_135 , & V_134 , V_115 , V_107 ) ;
if ( F_59 ( ! V_115 ) )
return NULL ;
if ( ! ( ( V_119 | V_121 ) & 7 ) ) {
V_84 = V_140 ;
F_45 ( F_4 ( V_9 ) , L_29 , V_35 ) ;
} else if ( ! ( ( V_119 | V_121 ) & 3 ) ) {
V_84 = V_141 ;
F_45 ( F_4 ( V_9 ) , L_30 , V_35 ) ;
} else if ( ! ( ( V_119 | V_121 ) & 1 ) ) {
V_84 = V_142 ;
F_45 ( F_4 ( V_9 ) , L_31 , V_35 ) ;
} else {
V_84 = V_122 ;
F_45 ( F_4 ( V_9 ) , L_32 , V_35 ) ;
}
while ( V_136 ) {
struct V_15 * V_62 = NULL ;
F_45 ( F_4 ( V_9 ) , L_33 , V_35 , V_136 ) ;
F_26 ( & V_19 -> V_65 , V_64 ) ;
V_62 = F_35 ( V_19 ) ;
F_30 ( & V_19 -> V_65 , V_64 ) ;
if ( ! V_62 ) {
F_40 ( F_4 ( V_9 ) , L_19 ) ;
if ( V_33 )
F_60 ( & V_33 -> V_70 , & V_19 -> V_72 ) ;
return NULL ;
}
V_119 += V_112 ;
V_121 += V_112 ;
if ( V_136 >= V_143 << V_84 )
V_112 = V_143 << V_84 ;
else
V_112 = V_136 ;
F_45 ( F_4 ( V_9 ) , L_34 , V_35 , V_112 ) ;
if ( ! ( ( V_119 | V_121 | V_112 ) & 7 ) ) {
V_84 = V_140 ;
F_45 ( F_4 ( V_9 ) , L_29 , V_35 ) ;
} else if ( ! ( ( V_119 | V_121 | V_112 ) & 3 ) ) {
V_84 = V_141 ;
F_45 ( F_4 ( V_9 ) , L_30 , V_35 ) ;
} else if ( ! ( ( V_119 | V_121 | V_112 ) & 1 ) ) {
V_84 = V_142 ;
F_45 ( F_4 ( V_9 ) , L_31 , V_35 ) ;
} else if ( ( V_119 | V_121 | V_112 ) & 1 ) {
V_84 = V_122 ;
F_45 ( F_4 ( V_9 ) , L_32 , V_35 ) ;
}
V_138 |= F_51 ( V_84 ) ;
V_137 = V_112 >> V_84 ;
V_136 -= V_112 ;
V_62 -> V_42 . V_118 = V_119 ;
V_62 -> V_42 . V_120 = V_121 ;
V_62 -> V_42 . V_123 = V_124
| V_125
| V_126
| ( V_136 ? V_127 : 0 )
| V_137 ;
V_62 -> V_42 . V_43 = V_138 ;
F_45 ( F_4 ( V_9 ) ,
L_35 ,
V_35 , & V_62 -> V_42 . V_118 , & V_62 -> V_42 . V_120 , V_62 -> V_42 . V_123 , V_62 -> V_42 . V_43 ) ;
if ( V_109 ) {
V_109 -> V_42 . V_128 = V_62 -> V_18 . V_37 ;
F_45 ( F_4 ( V_9 ) ,
L_36 ,
V_35 , V_109 , V_109 -> V_42 . V_128 ) ;
}
V_109 = V_62 ;
if ( ! V_33 )
V_33 = V_62 ;
F_45 ( F_4 ( V_9 ) , L_22 ,
V_35 , V_62 , V_33 ) ;
F_28 ( & V_62 -> V_74 , & V_33 -> V_70 ) ;
}
V_33 -> V_18 . V_107 = V_107 ;
V_33 -> V_112 = V_115 ;
return & V_33 -> V_18 ;
}
static enum V_144
F_65 ( struct V_7 * V_9 , T_4 V_63 ,
struct V_145 * V_146 )
{
struct V_6 * V_19 = F_2 ( V_9 ) ;
struct V_1 * V_2 = F_5 ( V_19 -> V_9 . V_10 ) ;
struct V_15 * V_62 , * V_147 ;
struct V_148 * V_70 ;
enum V_144 V_113 ;
int V_149 ;
T_2 V_150 , V_30 , V_151 ;
T_3 V_84 = 0 ;
unsigned long V_107 ;
V_113 = F_66 ( V_9 , V_63 , V_146 ) ;
if ( V_113 == V_152 )
return V_113 ;
if ( ! V_146 )
return V_113 ;
F_26 ( & V_19 -> V_65 , V_107 ) ;
V_62 = F_37 ( & V_19 -> V_67 , struct V_15 , V_66 ) ;
if ( ! V_62 -> V_36 ) {
F_67 ( V_146 , V_62 -> V_112 ) ;
goto V_114;
}
V_149 = V_62 -> V_112 ;
V_30 = V_153 | V_154 ;
V_151 = V_91 | V_89 ;
if ( ( V_62 -> V_42 . V_43 & V_30 ) == V_151 ) {
F_16 ( V_2 , V_155 , V_19 -> V_30 ) ;
while ( ! ( F_14 ( V_19 , V_156 ) & V_157 ) )
F_18 () ;
}
V_150 = F_14 ( V_19 , V_39 ) & 0xfffffffc ;
V_70 = & V_62 -> V_70 ;
F_68 (desc, _desc, descs_list, desc_node) {
V_84 = F_12 ( V_62 -> V_42 . V_43 ) ;
V_149 -= ( V_62 -> V_42 . V_123 & 0xffffff ) << V_84 ;
if ( ( V_62 -> V_42 . V_128 & 0xfffffffc ) == V_150 )
break;
}
V_149 += F_14 ( V_19 , V_51 ) << V_84 ;
F_67 ( V_146 , V_149 ) ;
F_45 ( F_4 ( V_9 ) ,
L_37 ,
V_35 , V_62 , & V_62 -> V_18 . V_37 , V_113 , V_63 , V_149 ) ;
V_114:
F_30 ( & V_19 -> V_65 , V_107 ) ;
return V_113 ;
}
static void F_69 ( struct V_6 * V_19 ,
struct V_15 * V_62 )
{
F_45 ( F_4 ( & V_19 -> V_9 ) , L_1 , V_35 , V_62 ) ;
F_38 ( & V_62 -> V_66 ) ;
F_60 ( & V_62 -> V_70 , & V_19 -> V_72 ) ;
}
static void F_70 ( struct V_6 * V_19 )
{
struct V_15 * V_62 ;
unsigned long V_107 ;
F_26 ( & V_19 -> V_65 , V_107 ) ;
if ( ! F_13 ( V_19 ) && ! F_36 ( & V_19 -> V_67 ) ) {
V_62 = F_37 ( & V_19 -> V_67 ,
struct V_15 ,
V_66 ) ;
F_20 ( F_4 ( & V_19 -> V_9 ) , L_1 , V_35 , V_62 ) ;
if ( ! V_62 -> V_36 )
F_19 ( V_19 , V_62 ) ;
}
F_30 ( & V_19 -> V_65 , V_107 ) ;
}
static void F_71 ( struct V_6 * V_19 )
{
struct V_15 * V_62 ;
struct V_16 * V_17 ;
V_62 = F_37 ( & V_19 -> V_67 , struct V_15 , V_66 ) ;
V_17 = & V_62 -> V_18 ;
if ( V_17 -> V_158 && ( V_17 -> V_107 & V_159 ) )
V_17 -> V_158 ( V_17 -> V_160 ) ;
}
static void F_72 ( unsigned long V_161 )
{
struct V_6 * V_19 = (struct V_6 * ) V_161 ;
struct V_15 * V_62 ;
T_2 V_162 ;
F_45 ( F_4 ( & V_19 -> V_9 ) , L_38 ,
V_35 , V_19 -> V_21 ) ;
V_162 = V_163
| V_164
| V_165 ;
if ( F_7 ( V_19 ) ) {
F_71 ( V_19 ) ;
} else if ( ( V_19 -> V_21 & V_166 )
|| ( V_19 -> V_21 & V_162 ) ) {
struct V_16 * V_17 ;
if ( V_19 -> V_21 & V_163 )
F_40 ( F_4 ( & V_19 -> V_9 ) , L_39 ) ;
if ( V_19 -> V_21 & V_164 )
F_40 ( F_4 ( & V_19 -> V_9 ) , L_40 ) ;
if ( V_19 -> V_21 & V_165 )
F_40 ( F_4 ( & V_19 -> V_9 ) , L_41 ) ;
F_73 ( & V_19 -> V_65 ) ;
V_62 = F_37 ( & V_19 -> V_67 ,
struct V_15 ,
V_66 ) ;
F_20 ( F_4 ( & V_19 -> V_9 ) , L_1 , V_35 , V_62 ) ;
F_74 ( ! V_62 -> V_36 ) ;
V_17 = & V_62 -> V_18 ;
F_69 ( V_19 , V_62 ) ;
F_75 ( & V_19 -> V_65 ) ;
if ( ! F_7 ( V_19 ) ) {
F_76 ( V_17 ) ;
if ( V_17 -> V_158 && ( V_17 -> V_107 & V_159 ) )
V_17 -> V_158 ( V_17 -> V_160 ) ;
}
F_77 ( V_17 ) ;
F_70 ( V_19 ) ;
}
}
static T_8 F_78 ( int V_167 , void * V_168 )
{
struct V_1 * V_2 = (struct V_1 * ) V_168 ;
struct V_6 * V_19 ;
T_2 V_169 , V_21 , V_170 ;
T_2 V_171 , V_172 ;
int V_111 , V_113 = V_173 ;
do {
V_169 = F_17 ( V_2 , V_174 ) ;
V_21 = F_17 ( V_2 , V_175 ) ;
V_170 = V_21 & V_169 ;
F_20 ( V_2 -> V_14 . V_11 ,
L_42 ,
V_35 , V_21 , V_169 , V_170 ) ;
if ( ! V_170 )
break;
for ( V_111 = 0 ; V_111 < V_2 -> V_14 . V_176 ; V_111 ++ ) {
if ( ! ( ( 1 << V_111 ) & V_170 ) )
continue;
V_19 = & V_2 -> V_9 [ V_111 ] ;
V_171 = F_14 ( V_19 , V_177 ) ;
V_172 = F_14 ( V_19 , V_156 ) ;
V_19 -> V_21 = V_172 & V_171 ;
F_20 ( V_2 -> V_14 . V_11 ,
L_43 ,
V_35 , V_111 , V_171 , V_172 ) ;
F_20 ( F_4 ( & V_19 -> V_9 ) ,
L_2 ,
V_35 ,
F_14 ( V_19 , V_41 ) ,
F_14 ( V_19 , V_39 ) ,
F_14 ( V_19 , V_48 ) ,
F_14 ( V_19 , V_49 ) ,
F_14 ( V_19 , V_50 ) ,
F_14 ( V_19 , V_51 ) ) ;
if ( V_19 -> V_21 & ( V_163 | V_164 ) )
F_16 ( V_2 , V_31 , V_19 -> V_30 ) ;
F_79 ( & V_19 -> V_178 ) ;
V_113 = V_179 ;
}
} while ( V_170 );
return V_113 ;
}
static void F_80 ( struct V_7 * V_9 )
{
struct V_6 * V_19 = F_2 ( V_9 ) ;
F_45 ( F_4 ( & V_19 -> V_9 ) , L_44 , V_35 ) ;
if ( ! F_7 ( V_19 ) )
F_70 ( V_19 ) ;
return;
}
static int F_81 ( struct V_7 * V_9 ,
struct V_101 * V_180 )
{
struct V_6 * V_19 = F_2 ( V_9 ) ;
int V_113 ;
unsigned long V_107 ;
F_45 ( F_4 ( V_9 ) , L_44 , V_35 ) ;
F_26 ( & V_19 -> V_65 , V_107 ) ;
V_113 = F_53 ( V_9 , V_180 ) ;
F_30 ( & V_19 -> V_65 , V_107 ) ;
return V_113 ;
}
static int F_82 ( struct V_7 * V_9 )
{
struct V_6 * V_19 = F_2 ( V_9 ) ;
struct V_1 * V_2 = F_5 ( V_19 -> V_9 . V_10 ) ;
unsigned long V_107 ;
F_45 ( F_4 ( V_9 ) , L_44 , V_35 ) ;
if ( F_63 ( V_22 , & V_19 -> V_21 ) )
return 0 ;
F_26 ( & V_19 -> V_65 , V_107 ) ;
F_16 ( V_2 , V_181 , V_19 -> V_30 ) ;
while ( F_14 ( V_19 , V_41 )
& ( V_182 | V_183 ) )
F_18 () ;
F_30 ( & V_19 -> V_65 , V_107 ) ;
return 0 ;
}
static int F_83 ( struct V_7 * V_9 )
{
struct V_6 * V_19 = F_2 ( V_9 ) ;
struct V_1 * V_2 = F_5 ( V_19 -> V_9 . V_10 ) ;
unsigned long V_107 ;
F_45 ( F_4 ( V_9 ) , L_44 , V_35 ) ;
F_26 ( & V_19 -> V_65 , V_107 ) ;
if ( ! F_9 ( V_19 ) ) {
F_30 ( & V_19 -> V_65 , V_107 ) ;
return 0 ;
}
F_16 ( V_2 , V_184 , V_19 -> V_30 ) ;
F_84 ( V_22 , & V_19 -> V_21 ) ;
F_30 ( & V_19 -> V_65 , V_107 ) ;
return 0 ;
}
static int F_85 ( struct V_7 * V_9 )
{
struct V_15 * V_62 , * V_147 ;
struct V_6 * V_19 = F_2 ( V_9 ) ;
struct V_1 * V_2 = F_5 ( V_19 -> V_9 . V_10 ) ;
unsigned long V_107 ;
F_45 ( F_4 ( V_9 ) , L_44 , V_35 ) ;
F_26 ( & V_19 -> V_65 , V_107 ) ;
F_16 ( V_2 , V_31 , V_19 -> V_30 ) ;
while ( F_17 ( V_2 , V_29 ) & V_19 -> V_30 )
F_18 () ;
F_68 (desc, _desc, &atchan->xfers_list, xfer_node)
F_69 ( V_19 , V_62 ) ;
F_84 ( V_20 , & V_19 -> V_21 ) ;
F_30 ( & V_19 -> V_65 , V_107 ) ;
return 0 ;
}
static int F_86 ( struct V_7 * V_9 )
{
struct V_6 * V_19 = F_2 ( V_9 ) ;
struct V_15 * V_62 ;
int V_111 ;
unsigned long V_107 ;
F_26 ( & V_19 -> V_65 , V_107 ) ;
if ( F_13 ( V_19 ) ) {
F_40 ( F_4 ( V_9 ) ,
L_45 ) ;
V_111 = - V_185 ;
goto V_114;
}
if ( ! F_36 ( & V_19 -> V_72 ) ) {
F_40 ( F_4 ( V_9 ) ,
L_46 ) ;
V_111 = - V_185 ;
goto V_114;
}
for ( V_111 = 0 ; V_111 < V_186 ; V_111 ++ ) {
V_62 = F_31 ( V_9 , V_187 ) ;
if ( ! V_62 ) {
F_87 ( F_4 ( V_9 ) ,
L_47 , V_111 ) ;
break;
}
F_28 ( & V_62 -> V_74 , & V_19 -> V_72 ) ;
}
F_88 ( V_9 ) ;
F_45 ( F_4 ( V_9 ) , L_48 , V_35 , V_111 ) ;
V_114:
F_30 ( & V_19 -> V_65 , V_107 ) ;
return V_111 ;
}
static void F_89 ( struct V_7 * V_9 )
{
struct V_6 * V_19 = F_2 ( V_9 ) ;
struct V_1 * V_2 = F_5 ( V_9 -> V_10 ) ;
struct V_15 * V_62 , * V_147 ;
F_68 (desc, _desc, &atchan->free_descs_list, desc_node) {
F_45 ( F_4 ( V_9 ) , L_49 , V_35 , V_62 ) ;
F_38 ( & V_62 -> V_74 ) ;
F_90 ( V_2 -> V_69 , V_62 , V_62 -> V_18 . V_37 ) ;
}
return;
}
static int F_91 ( struct V_10 * V_11 )
{
struct V_188 * V_189 = F_92 ( V_11 ) ;
struct V_1 * V_2 = F_93 ( V_189 ) ;
struct V_7 * V_9 , * V_190 ;
F_68 (chan, _chan, &atxdmac->dma.channels, device_node) {
struct V_6 * V_19 = F_2 ( V_9 ) ;
if ( F_13 ( V_19 ) && ! F_7 ( V_19 ) )
return - V_191 ;
}
return 0 ;
}
static int F_94 ( struct V_10 * V_11 )
{
struct V_188 * V_189 = F_92 ( V_11 ) ;
struct V_1 * V_2 = F_93 ( V_189 ) ;
struct V_7 * V_9 , * V_190 ;
F_68 (chan, _chan, &atxdmac->dma.channels, device_node) {
struct V_6 * V_19 = F_2 ( V_9 ) ;
V_19 -> V_192 = F_14 ( V_19 , V_41 ) ;
if ( F_7 ( V_19 ) ) {
if ( ! F_9 ( V_19 ) )
F_82 ( V_9 ) ;
V_19 -> V_193 = F_14 ( V_19 , V_177 ) ;
V_19 -> V_194 = F_14 ( V_19 , V_39 ) ;
V_19 -> V_195 = F_14 ( V_19 , V_48 ) ;
}
}
V_2 -> V_196 = F_17 ( V_2 , V_174 ) ;
F_15 ( V_2 ) ;
F_95 ( V_2 -> V_197 ) ;
return 0 ;
}
static int F_96 ( struct V_10 * V_11 )
{
struct V_188 * V_189 = F_92 ( V_11 ) ;
struct V_1 * V_2 = F_93 ( V_189 ) ;
struct V_6 * V_19 ;
struct V_7 * V_9 , * V_190 ;
int V_111 ;
F_97 ( V_2 -> V_197 ) ;
for ( V_111 = 0 ; V_111 < V_2 -> V_14 . V_176 ; V_111 ++ ) {
V_19 = & V_2 -> V_9 [ V_111 ] ;
while ( F_14 ( V_19 , V_156 ) )
F_18 () ;
}
F_16 ( V_2 , V_59 , V_2 -> V_196 ) ;
F_16 ( V_2 , V_60 , V_2 -> V_198 ) ;
F_68 (chan, _chan, &atxdmac->dma.channels, device_node) {
V_19 = F_2 ( V_9 ) ;
F_23 ( V_19 , V_41 , V_19 -> V_192 ) ;
if ( F_7 ( V_19 ) ) {
F_23 ( V_19 , V_39 , V_19 -> V_194 ) ;
F_23 ( V_19 , V_48 , V_19 -> V_195 ) ;
F_23 ( V_19 , V_56 , V_19 -> V_193 ) ;
F_24 () ;
F_16 ( V_2 , V_60 , V_19 -> V_30 ) ;
}
}
return 0 ;
}
static int F_98 ( struct V_188 * V_189 )
{
struct V_199 * V_200 ;
struct V_1 * V_2 ;
int V_167 , V_201 , V_202 , V_111 , V_113 ;
void T_1 * V_203 ;
T_2 V_34 ;
V_200 = F_99 ( V_189 , V_204 , 0 ) ;
if ( ! V_200 )
return - V_25 ;
V_167 = F_100 ( V_189 , 0 ) ;
if ( V_167 < 0 )
return V_167 ;
V_203 = F_101 ( & V_189 -> V_11 , V_200 ) ;
if ( F_102 ( V_203 ) )
return F_103 ( V_203 ) ;
V_34 = F_104 ( V_203 + V_205 ) ;
V_202 = F_105 ( V_34 ) ;
if ( V_202 > V_206 ) {
F_40 ( & V_189 -> V_11 , L_50 ,
V_202 ) ;
return - V_25 ;
}
V_201 = sizeof( * V_2 ) ;
V_201 += V_202 * sizeof( struct V_6 ) ;
V_2 = F_106 ( & V_189 -> V_11 , V_201 , V_207 ) ;
if ( ! V_2 ) {
F_40 ( & V_189 -> V_11 , L_51 ) ;
return - V_208 ;
}
V_2 -> V_4 = V_203 ;
V_2 -> V_167 = V_167 ;
V_2 -> V_197 = F_107 ( & V_189 -> V_11 , L_52 ) ;
if ( F_102 ( V_2 -> V_197 ) ) {
F_40 ( & V_189 -> V_11 , L_53 ) ;
return F_103 ( V_2 -> V_197 ) ;
}
V_113 = F_108 ( V_2 -> V_167 , F_78 , 0 , L_54 , V_2 ) ;
if ( V_113 ) {
F_40 ( & V_189 -> V_11 , L_55 ) ;
return V_113 ;
}
V_113 = F_97 ( V_2 -> V_197 ) ;
if ( V_113 ) {
F_40 ( & V_189 -> V_11 , L_56 ) ;
goto V_209;
}
V_2 -> V_69 =
F_109 ( F_110 ( & V_189 -> V_11 ) , & V_189 -> V_11 ,
sizeof( struct V_15 ) , 4 , 0 ) ;
if ( ! V_2 -> V_69 ) {
F_40 ( & V_189 -> V_11 , L_57 ) ;
V_113 = - V_208 ;
goto V_210;
}
F_111 ( V_211 , V_2 -> V_14 . V_212 ) ;
F_111 ( V_213 , V_2 -> V_14 . V_212 ) ;
F_111 ( V_214 , V_2 -> V_14 . V_212 ) ;
F_111 ( V_215 , V_2 -> V_14 . V_212 ) ;
V_2 -> V_14 . V_11 = & V_189 -> V_11 ;
V_2 -> V_14 . V_216 = F_86 ;
V_2 -> V_14 . V_217 = F_89 ;
V_2 -> V_14 . V_218 = F_65 ;
V_2 -> V_14 . V_219 = F_80 ;
V_2 -> V_14 . V_220 = F_62 ;
V_2 -> V_14 . V_221 = F_64 ;
V_2 -> V_14 . V_222 = F_54 ;
V_2 -> V_14 . V_223 = F_81 ;
V_2 -> V_14 . V_224 = F_82 ;
V_2 -> V_14 . V_225 = F_83 ;
V_2 -> V_14 . V_226 = F_85 ;
V_2 -> V_14 . V_227 = V_228 ;
V_2 -> V_14 . V_229 = V_228 ;
V_2 -> V_14 . V_230 = F_112 ( V_85 ) | F_112 ( V_95 ) ;
V_2 -> V_14 . V_231 = V_232 ;
F_15 ( V_2 ) ;
F_33 ( & V_2 -> V_14 . V_233 ) ;
for ( V_111 = 0 ; V_111 < V_202 ; V_111 ++ ) {
struct V_6 * V_19 = & V_2 -> V_9 [ V_111 ] ;
V_19 -> V_9 . V_10 = & V_2 -> V_14 ;
F_28 ( & V_19 -> V_9 . V_234 ,
& V_2 -> V_14 . V_233 ) ;
V_19 -> V_235 = F_1 ( V_2 , V_111 ) ;
V_19 -> V_30 = 1 << V_111 ;
F_113 ( & V_19 -> V_65 ) ;
F_33 ( & V_19 -> V_67 ) ;
F_33 ( & V_19 -> V_72 ) ;
F_114 ( & V_19 -> V_178 , F_72 ,
( unsigned long ) V_19 ) ;
while ( F_14 ( V_19 , V_156 ) )
F_18 () ;
}
F_115 ( V_189 , V_2 ) ;
V_113 = F_116 ( & V_2 -> V_14 ) ;
if ( V_113 ) {
F_40 ( & V_189 -> V_11 , L_58 ) ;
goto V_210;
}
V_113 = F_117 ( V_189 -> V_11 . V_236 ,
F_39 , V_2 ) ;
if ( V_113 ) {
F_40 ( & V_189 -> V_11 , L_59 ) ;
goto V_237;
}
F_118 ( & V_189 -> V_11 , L_60 ,
V_202 , V_2 -> V_4 ) ;
return 0 ;
V_237:
F_119 ( & V_2 -> V_14 ) ;
V_210:
F_95 ( V_2 -> V_197 ) ;
V_209:
F_120 ( V_2 -> V_167 , V_2 -> V_14 . V_11 ) ;
return V_113 ;
}
static int F_121 ( struct V_188 * V_189 )
{
struct V_1 * V_2 = (struct V_1 * ) F_93 ( V_189 ) ;
int V_111 ;
F_15 ( V_2 ) ;
F_122 ( V_189 -> V_11 . V_236 ) ;
F_119 ( & V_2 -> V_14 ) ;
F_95 ( V_2 -> V_197 ) ;
F_123 ( V_2 -> V_167 ) ;
F_120 ( V_2 -> V_167 , V_2 -> V_14 . V_11 ) ;
for ( V_111 = 0 ; V_111 < V_2 -> V_14 . V_176 ; V_111 ++ ) {
struct V_6 * V_19 = & V_2 -> V_9 [ V_111 ] ;
F_124 ( & V_19 -> V_178 ) ;
F_89 ( & V_19 -> V_9 ) ;
}
return 0 ;
}
static int T_9 F_125 ( void )
{
return F_126 ( & V_238 , F_98 ) ;
}
