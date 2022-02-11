static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 ;
F_2 ( V_2 -> V_12 == V_13 ) ;
F_2 ( V_4 != NULL ) ;
if ( V_10 != NULL ) {
F_3 ( & V_10 -> V_14 , L_1 , V_7 ) ;
F_4 ( V_4 , V_10 ) ;
}
if ( V_7 && V_2 -> V_15 ) {
F_5 ( V_4 , V_7 ) ;
F_6 ( V_4 , V_7 ) ;
F_7 ( V_4 , V_7 ) ;
F_8 ( V_4 , V_7 ) ;
}
F_9 ( V_4 , & V_2 -> V_16 ) ;
}
static struct V_1 * F_10 ( struct V_17 * V_17 ,
struct V_10 * V_18 , int V_19 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_6 * V_7 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
int V_24 ;
int V_25 = 0 ;
V_21 = F_11 ( V_18 -> V_26 -> V_27 ) -> V_28 ;
F_2 ( V_21 != NULL ) ;
V_4 = F_12 ( & V_24 ) ;
if ( F_13 ( V_4 ) )
return F_14 ( V_4 ) ;
V_2 = & F_15 ( V_4 ) -> V_29 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_5 = V_4 ;
V_2 -> V_16 = V_24 ;
V_2 -> V_12 = V_13 ;
V_23 = F_16 ( V_4 ) ;
V_7 = V_23 -> V_30 . V_31 ;
if ( V_7 == NULL && V_19 ) {
struct V_32 * V_32 = V_18 -> V_26 -> V_27 ;
T_1 V_33 ;
if ( F_17 ( & V_32 -> V_34 ) ) {
F_18 ( & ( V_32 ) -> V_34 ) ;
F_19 ( L_2
L_3 , V_13 -> V_35 ) ;
F_20 () ;
F_21 () ;
return F_22 ( - V_36 ) ;
}
V_7 = F_23 ( V_4 ) ;
F_24 ( V_7 , V_17 , 1 ) ;
V_7 -> V_37 = V_38 ;
V_33 = ( V_18 -> V_39 << V_40 ) ;
V_25 = F_25 ( V_4 , V_7 , V_41 , V_33 , V_42 ) ;
if ( V_25 == 0 ) {
V_23 -> V_43 = F_26 ( V_17 ) ;
V_23 -> V_44 = NULL ;
V_23 -> V_45 = 0 ;
V_25 = F_27 ( V_4 , V_7 ) ;
if ( V_25 == 0 ) {
V_25 = F_28 ( V_4 , V_7 ) ;
if ( V_25 == 0 )
V_25 = F_29 ( V_4 , V_7 ) ;
}
} else
V_25 = V_7 -> V_46 ;
V_2 -> V_15 = 1 ;
}
V_2 -> V_8 = V_7 ;
if ( V_7 == NULL )
V_25 = - V_36 ;
if ( V_25 == 0 ) {
struct V_9 * V_10 ;
F_2 ( V_7 != NULL ) ;
F_2 ( V_7 -> V_47 == V_48 ) ;
F_2 ( V_23 -> V_43 == F_26 ( V_17 ) ) ;
V_10 = F_30 ( V_4 , V_21 , V_18 -> V_39 , V_18 ,
V_49 ) ;
if ( ! F_13 ( V_10 ) ) {
V_2 -> V_11 = V_10 ;
F_31 ( & V_10 -> V_14 , L_1 , V_7 ) ;
V_25 = 0 ;
} else
V_25 = F_32 ( V_10 ) ;
}
if ( V_25 ) {
F_1 ( V_2 ) ;
V_2 = F_22 ( V_25 ) ;
}
F_33 ( V_50 , L_4 V_51 L_5 ,
V_18 -> V_39 , F_34 ( F_35 ( & V_21 -> V_52 ) ) , V_25 ,
V_4 , V_7 ) ;
return V_2 ;
}
static struct V_1 * F_36 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_24 ;
V_4 = F_12 ( & V_24 ) ;
F_2 ( ! F_13 ( V_4 ) ) ;
V_2 = & F_15 ( V_4 ) -> V_29 ;
F_2 ( V_4 == V_2 -> V_5 ) ;
F_2 ( V_13 == V_2 -> V_12 ) ;
F_9 ( V_4 , & V_24 ) ;
return V_2 ;
}
int F_37 ( struct V_17 * V_17 , struct V_10 * V_18 , unsigned V_53 ,
unsigned V_54 )
{
struct V_1 * V_2 ;
int V_25 ;
V_2 = F_10 ( V_17 , V_18 , 1 ) ;
if ( ! F_13 ( V_2 ) ) {
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 ;
F_38 ( V_4 , V_7 , V_10 ) ;
V_25 = F_39 ( V_4 , V_7 , V_10 , V_53 , V_54 ) ;
if ( V_25 == 0 ) {
F_40 ( V_10 ) ;
F_31 ( & V_10 -> V_14 , L_6 ,
V_13 ) ;
} else {
F_41 ( V_4 , V_7 , V_10 ) ;
F_1 ( V_2 ) ;
}
} else {
V_25 = F_32 ( V_2 ) ;
}
return V_25 ;
}
int F_42 ( struct V_17 * V_17 , struct V_10 * V_18 , unsigned V_53 ,
unsigned V_54 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_6 * V_7 ;
struct V_9 * V_10 ;
int V_25 = 0 ;
V_2 = F_36 () ;
V_4 = V_2 -> V_5 ;
V_10 = V_2 -> V_11 ;
V_7 = V_2 -> V_8 ;
F_2 ( F_43 ( V_10 , V_7 ) ) ;
F_2 ( V_53 <= V_54 ) ;
if ( V_53 != V_54 )
V_25 = F_44 ( V_4 , V_7 , V_10 , V_53 , V_54 ) ;
if ( F_43 ( V_10 , V_7 ) )
F_41 ( V_4 , V_7 , V_10 ) ;
F_3 ( & V_10 -> V_14 , L_6 , V_13 ) ;
F_4 ( V_4 , V_10 ) ;
F_1 ( V_2 ) ;
return V_25 ;
}
struct V_55 * F_45 ( struct V_32 * V_32 , enum V_56 V_57 )
{
T_2 V_58 ;
V_58 = V_57 == V_59 ? V_60 : V_61 ;
return F_46 ( V_32 , V_58 ) ;
}
static unsigned long F_47 ( struct V_62 * V_63 ,
struct V_64 * V_65 ,
unsigned long V_66 )
{
struct V_67 * V_68 = & V_63 -> V_67 ;
long V_69 ;
V_69 = F_48 ( V_68 -> V_70 - F_49 ( & V_68 -> V_71 ) , V_66 ) ;
if ( V_69 < 0 || V_69 < F_50 ( long , V_72 , V_66 ) )
GOTO ( V_73 , V_69 = 0 ) ;
if ( V_65 -> V_74 == 0 ) {
long V_75 = ( V_65 -> V_76 + V_69 ) % V_72 ;
if ( V_75 < V_69 )
V_69 -= V_75 ;
}
if ( F_51 ( V_69 , & V_68 -> V_71 ) > V_68 -> V_70 ) {
F_52 ( V_69 , & V_68 -> V_71 ) ;
V_69 = 0 ;
}
V_73:
return V_69 ;
}
void F_53 ( struct V_62 * V_63 , unsigned long V_77 )
{
struct V_67 * V_68 = & V_63 -> V_67 ;
F_52 ( V_77 , & V_68 -> V_71 ) ;
}
static void F_54 ( struct V_62 * V_63 , enum V_78 V_79 )
{
F_55 ( V_79 >= 0 && V_79 < V_80 , L_7 , V_79 ) ;
F_56 ( V_63 -> V_81 , V_79 ) ;
}
void F_57 ( struct V_82 * V_26 , enum V_78 V_79 )
{
struct V_62 * V_63 = F_58 ( V_26 -> V_27 ) ;
F_54 ( V_63 , V_79 ) ;
}
static int F_59 ( unsigned long V_39 , unsigned long V_83 ,
unsigned long V_84 , unsigned long V_85 )
{
unsigned long V_86 = V_83 - V_84 , V_87 = V_83 + V_85 ;
if ( V_86 > V_83 )
V_86 = 0 ;
if ( V_87 < V_83 )
V_87 = ~ 0 ;
return V_86 <= V_39 && V_39 <= V_87 ;
}
static struct V_88 * F_60 ( struct V_17 * V_89 )
{
struct V_90 * V_91 ;
V_91 = F_26 ( V_89 ) ;
return & V_91 -> V_92 ;
}
void F_61 ( struct V_17 * V_89 , struct V_93 * V_94 )
{
struct V_88 * V_95 ;
V_95 = F_60 ( V_89 ) ;
F_62 ( & V_95 -> V_96 ) ;
V_95 -> V_97 ++ ;
V_95 -> V_98 = 0 ;
V_95 -> V_99 ++ ;
V_94 -> V_100 = V_13 ;
F_63 ( & V_94 -> V_101 , & V_95 -> V_102 ) ;
F_64 ( & V_95 -> V_96 ) ;
}
void F_65 ( struct V_17 * V_89 , struct V_93 * V_94 )
{
struct V_88 * V_95 ;
V_95 = F_60 ( V_89 ) ;
F_62 ( & V_95 -> V_96 ) ;
F_66 ( & V_94 -> V_101 ) ;
F_64 ( & V_95 -> V_96 ) ;
}
static struct V_93 * F_67 ( struct V_88 * V_95 )
{
struct V_93 * V_103 ;
F_68 (scan, &ras->ras_read_beads, lrr_linkage) {
if ( V_103 -> V_100 == V_13 )
return V_103 ;
}
return NULL ;
}
struct V_93 * F_69 ( struct V_17 * V_89 )
{
struct V_88 * V_95 ;
struct V_93 * V_104 ;
V_95 = F_60 ( V_89 ) ;
F_62 ( & V_95 -> V_96 ) ;
V_104 = F_67 ( V_95 ) ;
F_64 ( & V_95 -> V_96 ) ;
return V_104 ;
}
static int F_70 ( const struct V_3 * V_4 , struct V_6 * V_7 ,
struct V_105 * V_106 , struct V_9 * V_10 ,
struct V_10 * V_18 )
{
struct V_107 * V_108 ;
int V_109 ;
V_109 = 0 ;
F_38 ( V_4 , V_7 , V_10 ) ;
F_31 ( & V_10 -> V_14 , L_8 , V_13 ) ;
V_108 = F_71 ( F_72 ( V_10 , & V_110 ) ) ;
if ( ! V_108 -> V_111 && ! F_73 ( V_18 ) ) {
V_109 = F_74 ( V_4 , V_7 , V_10 ) ;
if ( V_109 == - V_112 ) {
V_108 -> V_111 = 1 ;
V_108 -> V_113 = 0 ;
F_75 ( V_106 , V_10 ) ;
V_109 = 1 ;
} else {
F_76 ( V_4 , V_10 ) ;
V_109 = - V_114 ;
}
} else {
F_41 ( V_4 , V_7 , V_10 ) ;
}
F_3 ( & V_10 -> V_14 , L_8 , V_13 ) ;
F_4 ( V_4 , V_10 ) ;
return V_109 ;
}
static int F_77 ( const struct V_3 * V_4 , struct V_6 * V_7 ,
struct V_105 * V_106 ,
T_3 V_39 , struct V_82 * V_26 )
{
struct V_10 * V_18 ;
struct V_20 * V_21 = F_11 ( V_26 -> V_27 ) -> V_28 ;
struct V_9 * V_10 ;
enum V_78 V_79 = V_80 ;
unsigned int V_115 ;
int V_109 = 0 ;
const char * V_116 = NULL ;
V_115 = V_117 & ~ V_118 ;
#ifdef F_78
V_115 |= F_78 ;
#endif
V_18 = F_79 ( V_26 , V_39 ) ;
if ( V_18 != NULL ) {
if ( V_18 -> V_26 == V_26 ) {
V_10 = F_30 ( V_4 , V_21 , V_18 -> V_39 ,
V_18 , V_49 ) ;
if ( ! F_13 ( V_10 ) ) {
V_109 = F_70 ( V_4 , V_7 , V_106 ,
V_10 , V_18 ) ;
if ( V_109 == - V_114 ) {
V_79 = V_119 ;
V_116 = L_9 ;
}
} else {
V_79 = V_120 ;
V_116 = L_10 ;
}
} else {
V_79 = V_121 ;
V_116 = L_11 ;
}
if ( V_109 != 1 )
F_80 ( V_18 ) ;
F_81 ( V_18 ) ;
} else {
V_79 = V_120 ;
V_116 = L_12 ;
}
if ( V_116 != NULL ) {
F_57 ( V_26 , V_79 ) ;
F_33 ( V_122 , L_13 , V_116 ) ;
}
return V_109 ;
}
static inline int F_82 ( struct V_88 * V_95 )
{
return V_95 -> V_123 > 1 ;
}
static unsigned long
F_83 ( T_3 V_124 , unsigned long V_125 , unsigned long V_126 ,
unsigned long V_127 , unsigned long V_128 )
{
T_2 V_86 = V_127 > V_124 ? V_127 - V_124 : 0 ;
T_2 V_87 = V_127 + V_128 > V_124 ? V_127 + V_128 - V_124 : 0 ;
unsigned long V_129 = 0 ;
unsigned long V_130 = 0 ;
unsigned long V_131 ;
if ( V_125 == 0 || V_128 == 0 || V_87 == 0 )
return V_128 ;
V_129 = F_84 ( V_86 , V_125 ) ;
if ( V_129 < V_126 )
V_129 = V_126 - V_129 ;
else
V_129 = 0 ;
V_130 = F_84 ( V_87 , V_125 ) ;
if ( V_130 > V_126 )
V_130 = V_126 ;
F_33 ( V_122 , L_14 V_132 L_15 V_132 L_16 ,
V_86 , V_87 , V_129 , V_130 ) ;
if ( V_86 == V_87 )
V_131 = V_130 - ( V_126 - V_129 ) ;
else
V_131 = V_129 + V_126 * ( V_87 - V_86 - 1 ) + V_130 ;
F_33 ( V_122 , L_17
L_18 , V_124 , V_125 , V_126 , V_127 , V_128 , V_131 ) ;
return V_131 ;
}
static int F_85 ( struct V_64 * V_65 )
{
T_2 V_128 = V_65 -> V_133 >= V_65 -> V_76 ?
V_65 -> V_133 - V_65 -> V_76 + 1 : 0 ;
return F_83 ( V_65 -> V_134 , V_65 -> V_135 ,
V_65 -> V_74 , V_65 -> V_76 ,
V_128 ) ;
}
static int F_86 ( unsigned long V_136 , struct V_64 * V_65 )
{
return V_65 -> V_135 == 0 || V_65 -> V_135 == V_65 -> V_74 ||
( V_136 >= V_65 -> V_134 && ( V_136 - V_65 -> V_134 ) %
V_65 -> V_135 < V_65 -> V_74 ) ;
}
static int F_87 ( const struct V_3 * V_4 ,
struct V_6 * V_7 , struct V_105 * V_106 ,
struct V_64 * V_65 ,
unsigned long * V_137 ,
struct V_82 * V_26 ,
unsigned long * V_138 )
{
int V_109 , V_139 = 0 , V_140 ;
unsigned long V_141 ;
F_2 ( V_65 != NULL ) ;
F_88 ( V_65 ) ;
V_140 = V_65 -> V_135 > V_65 -> V_74 && V_65 -> V_74 > 0 ;
for ( V_141 = V_65 -> V_76 ; V_141 <= V_65 -> V_133 &&
* V_137 > 0 ; V_141 ++ ) {
if ( F_86 ( V_141 , V_65 ) ) {
V_109 = F_77 ( V_4 , V_7 , V_106 ,
V_141 , V_26 ) ;
if ( V_109 == 1 ) {
( * V_137 ) -- ;
V_139 ++ ;
} else if ( V_109 == - V_114 )
break;
} else if ( V_140 ) {
T_3 V_142 ;
F_55 ( V_141 > V_65 -> V_134 , L_19
L_20 , V_141 ,
V_65 -> V_76 , V_65 -> V_133 , V_65 -> V_134 ,
V_65 -> V_135 , V_65 -> V_74 ) ;
V_142 = V_141 - V_65 -> V_134 ;
V_142 = V_142 % ( V_65 -> V_135 ) ;
if ( V_142 > V_65 -> V_74 ) {
V_141 += V_65 -> V_135 - V_142 ;
F_33 ( V_122 , L_21 , V_141 ,
V_65 -> V_135 - V_142 ) ;
continue;
}
}
}
* V_138 = V_141 ;
return V_139 ;
}
int F_89 ( const struct V_3 * V_4 , struct V_6 * V_7 ,
struct V_88 * V_95 , struct V_82 * V_26 ,
struct V_105 * V_106 , int V_143 )
{
struct V_144 * V_145 = F_90 ( V_4 ) ;
struct V_146 * V_147 = F_15 ( V_4 ) ;
struct V_148 * V_149 = F_91 ( V_4 ) ;
unsigned long V_86 = 0 , V_87 = 0 , V_150 ;
unsigned long V_138 , V_77 ;
struct V_32 * V_32 ;
struct V_93 * V_104 ;
struct V_64 * V_65 = & V_147 -> V_151 ;
struct V_152 * V_153 ;
struct V_20 * V_21 ;
int V_69 = 0 ;
T_2 V_154 ;
V_32 = V_26 -> V_27 ;
V_153 = F_11 ( V_32 ) ;
V_21 = V_153 -> V_28 ;
memset ( V_65 , 0 , sizeof( * V_65 ) ) ;
F_92 ( V_21 ) ;
V_69 = F_93 ( V_4 , V_21 , V_149 ) ;
F_94 ( V_21 ) ;
if ( V_69 != 0 )
return V_69 ;
V_154 = V_149 -> V_155 ;
if ( V_154 == 0 ) {
F_57 ( V_26 , V_156 ) ;
return 0 ;
}
F_62 ( & V_95 -> V_96 ) ;
if ( V_145 -> V_157 )
V_104 = & V_145 -> V_158 ;
else
V_104 = NULL ;
if ( V_104 != NULL && V_95 -> V_159 + V_95 -> V_160 <
V_104 -> V_161 + V_104 -> V_162 ) {
V_95 -> V_160 = V_104 -> V_161 + V_104 -> V_162 -
V_95 -> V_159 ;
}
if ( V_95 -> V_160 ) {
V_86 = V_95 -> V_163 ;
V_87 = V_95 -> V_159 + V_95 -> V_160 - 1 ;
}
if ( V_87 != 0 ) {
unsigned long V_164 ;
V_164 = ( ( V_87 + 1 ) & ( ~ ( V_72 - 1 ) ) ) ;
if ( V_164 > 0 )
V_164 -- ;
if ( V_164 > V_86 )
V_87 = V_164 ;
V_87 = F_48 ( V_87 , ( unsigned long ) ( ( V_154 - 1 ) >> V_40 ) ) ;
V_95 -> V_163 = F_95 ( V_87 , V_87 + 1 ) ;
F_96 ( V_95 ) ;
}
V_65 -> V_76 = V_86 ;
V_65 -> V_133 = V_87 ;
if ( F_82 ( V_95 ) ) {
V_65 -> V_134 = V_95 -> V_165 ;
V_65 -> V_135 = V_95 -> V_166 ;
V_65 -> V_74 = V_95 -> V_167 ;
}
F_64 ( & V_95 -> V_96 ) ;
if ( V_87 == 0 ) {
F_57 ( V_26 , V_168 ) ;
return 0 ;
}
V_77 = F_85 ( V_65 ) ;
if ( V_77 == 0 )
return 0 ;
V_150 = F_47 ( F_58 ( V_32 ) , V_65 , V_77 ) ;
if ( V_150 < V_77 )
F_57 ( V_26 , V_169 ) ;
F_33 ( V_122 , L_22 , V_150 ,
F_49 ( & F_58 ( V_32 ) -> V_67 . V_71 ) ,
F_58 ( V_32 ) -> V_67 . V_70 ) ;
V_69 = F_87 ( V_4 , V_7 , V_106 ,
V_65 , & V_150 , V_26 , & V_138 ) ;
F_55 ( V_150 >= 0 , L_23 , V_150 ) ;
if ( V_150 != 0 )
F_53 ( F_58 ( V_32 ) , V_150 ) ;
if ( V_138 == V_87 + 1 && V_138 == ( V_154 >> V_40 ) )
F_57 ( V_26 , V_170 ) ;
F_33 ( V_122 , L_24 ,
V_138 , V_87 , V_65 -> V_133 ) ;
if ( V_138 != V_87 + 1 ) {
F_62 ( & V_95 -> V_96 ) ;
if ( V_138 < V_95 -> V_163 &&
F_59 ( V_138 , V_95 -> V_159 , 0 ,
V_95 -> V_160 ) ) {
V_95 -> V_163 = V_138 ;
F_96 ( V_95 ) ;
}
F_64 ( & V_95 -> V_96 ) ;
}
return V_69 ;
}
static void F_97 ( struct V_32 * V_32 , struct V_88 * V_95 ,
unsigned long V_39 )
{
V_95 -> V_159 = V_39 & ( ~ ( F_98 ( V_32 ) - 1 ) ) ;
}
static void F_99 ( struct V_32 * V_32 , struct V_88 * V_95 ,
unsigned long V_39 )
{
V_95 -> V_171 = V_39 ;
V_95 -> V_99 = 0 ;
V_95 -> V_172 = 0 ;
V_95 -> V_160 = 0 ;
F_97 ( V_32 , V_95 , V_39 ) ;
V_95 -> V_163 = F_95 ( V_95 -> V_159 , V_39 ) ;
F_96 ( V_95 ) ;
}
static void F_100 ( struct V_88 * V_95 )
{
V_95 -> V_123 = 0 ;
V_95 -> V_166 = 0 ;
V_95 -> V_167 = 0 ;
F_96 ( V_95 ) ;
}
void F_101 ( struct V_32 * V_32 , struct V_88 * V_95 )
{
F_102 ( & V_95 -> V_96 ) ;
F_99 ( V_32 , V_95 , 0 ) ;
V_95 -> V_97 = 0 ;
F_103 ( & V_95 -> V_102 ) ;
}
static int F_104 ( struct V_88 * V_95 ,
unsigned long V_39 )
{
unsigned long V_173 ;
if ( V_95 -> V_166 == 0 || V_95 -> V_167 == 0 ||
V_95 -> V_167 == V_95 -> V_166 )
return 0 ;
V_173 = V_39 - V_95 -> V_171 - 1 ;
if ( V_173 == 0 )
return V_95 -> V_172 + 1 <= V_95 -> V_167 ;
return ( V_95 -> V_166 - V_95 -> V_167 ) == V_173 &&
V_95 -> V_172 == V_95 -> V_167 ;
}
static void F_105 ( struct V_88 * V_95 ,
unsigned long V_39 )
{
unsigned long V_173 = V_39 - V_95 -> V_171 - 1 ;
if ( ! F_82 ( V_95 ) && ( V_173 != 0 ||
V_95 -> V_123 == 0 ) ) {
V_95 -> V_167 = V_95 -> V_172 ;
V_95 -> V_166 = V_173 + V_95 -> V_172 ;
}
F_2 ( V_95 -> V_98 == 0 ) ;
F_2 ( V_95 -> V_123 == 0 ) ;
if ( V_39 <= V_95 -> V_171 ) {
F_100 ( V_95 ) ;
return;
}
V_95 -> V_167 = V_95 -> V_172 ;
V_95 -> V_166 = V_173 + V_95 -> V_172 ;
F_96 ( V_95 ) ;
return;
}
static unsigned long
F_106 ( struct V_88 * V_95 , unsigned long V_77 )
{
return F_83 ( V_95 -> V_165 , V_95 -> V_166 ,
V_95 -> V_167 , V_95 -> V_165 ,
V_77 ) ;
}
static void F_107 ( struct V_88 * V_95 ,
struct V_67 * V_68 ,
unsigned long V_174 )
{
unsigned long V_175 , V_176 , V_177 ;
unsigned long V_178 ;
F_2 ( V_95 -> V_166 > 0 ) ;
F_55 ( V_95 -> V_159 + V_95 -> V_160
>= V_95 -> V_165 , L_25
L_26 , V_95 -> V_159 ,
V_95 -> V_160 , V_95 -> V_165 ) ;
V_178 = V_95 -> V_159 + V_95 -> V_160 -
V_95 -> V_165 ;
V_175 = V_178 % V_95 -> V_166 ;
V_177 = V_95 -> V_160 - V_175 ;
if ( V_175 < V_95 -> V_167 )
V_175 += V_174 ;
else
V_175 = V_95 -> V_167 + V_174 ;
F_2 ( V_95 -> V_167 != 0 ) ;
V_176 = V_175 / V_95 -> V_167 ;
V_175 %= V_95 -> V_167 ;
V_177 += V_176 * V_95 -> V_166 + V_175 ;
if ( F_106 ( V_95 , V_177 ) <= V_68 -> V_179 )
V_95 -> V_160 = V_177 ;
F_96 ( V_95 ) ;
}
static void F_108 ( struct V_32 * V_32 ,
struct V_88 * V_95 ,
struct V_67 * V_68 )
{
if ( F_82 ( V_95 ) )
F_107 ( V_95 , V_68 , F_98 ( V_32 ) ) ;
else
V_95 -> V_160 = F_48 ( V_95 -> V_160 +
F_98 ( V_32 ) ,
V_68 -> V_179 ) ;
}
void F_109 ( struct V_62 * V_63 , struct V_32 * V_32 ,
struct V_88 * V_95 , unsigned long V_39 ,
unsigned V_180 )
{
struct V_67 * V_68 = & V_63 -> V_67 ;
int V_181 = 0 , V_182 = 0 , V_183 = 0 ;
F_62 ( & V_95 -> V_96 ) ;
F_54 ( V_63 , V_180 ? V_184 : V_185 ) ;
if ( ! F_59 ( V_39 , V_95 -> V_171 , 8 , 8 ) ) {
V_181 = 1 ;
F_54 ( V_63 , V_186 ) ;
} else if ( ! V_180 && V_95 -> V_160 &&
V_39 < V_95 -> V_163 &&
F_59 ( V_39 , V_95 -> V_159 , 0 ,
V_95 -> V_160 ) ) {
V_183 = 1 ;
F_54 ( V_63 , V_187 ) ;
}
if ( V_95 -> V_97 == 2 && ! V_95 -> V_98 ) {
T_2 V_188 ;
V_188 = ( F_110 ( V_32 ) + V_42 - 1 ) >>
V_40 ;
F_33 ( V_122 , L_27 V_132 L_28 , V_188 ,
V_68 -> V_189 , V_68 -> V_179 ) ;
if ( V_188 &&
V_188 <= V_68 -> V_189 ) {
V_95 -> V_159 = 0 ;
V_95 -> V_171 = 0 ;
V_95 -> V_163 = 0 ;
V_95 -> V_160 = F_48 ( V_68 -> V_179 ,
V_68 -> V_189 ) ;
GOTO ( V_190 , 0 ) ;
}
}
if ( V_181 ) {
if ( ! F_104 ( V_95 , V_39 ) ) {
if ( V_95 -> V_123 == 0 &&
V_95 -> V_98 == 0 ) {
F_105 ( V_95 , V_39 ) ;
V_95 -> V_123 ++ ;
} else {
F_100 ( V_95 ) ;
}
F_99 ( V_32 , V_95 , V_39 ) ;
V_95 -> V_172 ++ ;
GOTO ( V_190 , 0 ) ;
} else {
V_95 -> V_172 = 0 ;
V_95 -> V_99 = 0 ;
if ( ++ V_95 -> V_123 > 1 )
V_182 = 1 ;
F_96 ( V_95 ) ;
}
} else {
if ( V_183 ) {
if ( F_104 ( V_95 , V_39 ) &&
F_82 ( V_95 ) ) {
if ( V_39 != V_95 -> V_171 + 1 )
V_95 -> V_172 = 0 ;
F_99 ( V_32 , V_95 , V_39 ) ;
F_96 ( V_95 ) ;
} else {
F_99 ( V_32 , V_95 , V_39 ) ;
V_95 -> V_172 ++ ;
F_100 ( V_95 ) ;
GOTO ( V_190 , 0 ) ;
}
} else if ( F_82 ( V_95 ) ) {
if ( ! F_104 ( V_95 , V_39 ) ) {
F_100 ( V_95 ) ;
V_95 -> V_160 = 0 ;
V_95 -> V_163 = V_39 ;
}
}
}
V_95 -> V_172 ++ ;
V_95 -> V_171 = V_39 ;
F_97 ( V_32 , V_95 , V_39 ) ;
if ( F_82 ( V_95 ) )
V_95 -> V_163 = F_95 ( V_39 , V_95 -> V_163 ) ;
else
V_95 -> V_163 = F_95 ( V_95 -> V_159 ,
V_95 -> V_163 ) ;
F_96 ( V_95 ) ;
if ( ! V_95 -> V_160 && V_95 -> V_172 == 4 ) {
V_95 -> V_160 = F_98 ( V_32 ) ;
GOTO ( V_190 , 0 ) ;
}
if ( V_95 -> V_123 == 2 && V_182 ) {
V_95 -> V_163 = F_95 ( V_39 , V_95 -> V_163 ) ;
V_95 -> V_165 = V_39 ;
V_95 -> V_160 = F_98 ( V_32 ) ;
}
if ( ( V_95 -> V_99 > 1 || V_182 ) &&
! V_95 -> V_98 )
F_108 ( V_32 , V_95 , V_68 ) ;
V_190:
F_96 ( V_95 ) ;
V_95 -> V_98 ++ ;
F_64 ( & V_95 -> V_96 ) ;
return;
}
int F_111 ( struct V_10 * V_18 , struct V_191 * V_192 )
{
struct V_32 * V_32 = V_18 -> V_26 -> V_27 ;
struct V_152 * V_153 = F_11 ( V_32 ) ;
struct V_3 * V_4 ;
struct V_6 * V_7 ;
struct V_9 * V_10 ;
struct V_20 * V_21 ;
struct V_193 V_194 ;
bool V_195 = false ;
bool V_196 = false ;
int V_25 ;
F_2 ( F_112 ( V_18 ) ) ;
F_2 ( ! F_113 ( V_18 ) ) ;
F_2 ( F_114 ( V_32 ) != NULL ) ;
V_4 = F_115 ( & V_194 ) ;
if ( F_13 ( V_4 ) )
GOTO ( V_73 , V_25 = F_32 ( V_4 ) ) ;
V_21 = F_11 ( V_32 ) -> V_28 ;
F_2 ( V_21 != NULL ) ;
V_7 = F_23 ( V_4 ) ;
V_7 -> V_197 = V_21 ;
V_7 -> V_198 = 1 ;
V_25 = F_116 ( V_4 , V_7 , V_199 , V_21 ) ;
if ( V_25 == 0 ) {
V_10 = F_30 ( V_4 , V_21 , V_18 -> V_39 ,
V_18 , V_49 ) ;
if ( ! F_13 ( V_10 ) ) {
F_31 ( & V_10 -> V_14 , L_29 ,
V_13 ) ;
F_38 ( V_4 , V_7 , V_10 ) ;
V_25 = F_117 ( V_4 , V_7 , V_10 ) ;
if ( V_25 != 0 ) {
if ( ! F_118 ( V_18 ) ) {
F_119 ( V_192 , V_18 ) ;
V_25 = 0 ;
V_195 = true ;
}
}
F_120 ( V_4 , V_7 , V_10 ) ;
V_196 = true ;
F_3 ( & V_10 -> V_14 ,
L_29 , V_13 ) ;
F_4 ( V_4 , V_10 ) ;
} else {
V_25 = F_32 ( V_10 ) ;
}
}
F_8 ( V_4 , V_7 ) ;
if ( V_195 && V_192 -> V_200 == V_201 ) {
T_1 V_142 = F_121 ( V_21 , V_18 -> V_39 ) ;
V_25 = F_122 ( V_32 , V_142 ,
V_142 + V_42 - 1 ,
V_202 , 1 ) ;
if ( V_25 > 0 ) {
V_192 -> V_203 -= V_25 - 1 ;
V_25 = 0 ;
}
}
F_123 ( & V_194 , V_4 ) ;
GOTO ( V_73 , V_25 ) ;
V_73:
if ( V_25 < 0 ) {
if ( ! V_153 -> V_204 )
V_153 -> V_204 = V_25 ;
F_124 ( V_18 ) ;
if ( ! V_196 )
F_80 ( V_18 ) ;
}
return V_25 ;
}
int F_125 ( struct V_82 * V_26 , struct V_191 * V_192 )
{
struct V_32 * V_32 = V_26 -> V_27 ;
struct V_62 * V_63 = F_58 ( V_32 ) ;
T_1 V_86 ;
T_1 V_87 ;
enum V_205 V_206 ;
int V_207 = 0 ;
int V_25 ;
int V_208 = 0 ;
if ( V_192 -> V_209 ) {
V_86 = V_26 -> V_210 << V_40 ;
V_87 = V_211 ;
} else {
V_86 = V_192 -> V_212 ;
V_87 = V_192 -> V_213 ;
if ( V_87 == V_214 ) {
V_87 = V_211 ;
V_207 = V_86 == 0 ;
}
}
V_206 = V_215 ;
if ( V_192 -> V_200 == V_201 )
V_206 = V_202 ;
if ( V_63 -> V_216 )
V_208 = 1 ;
V_25 = F_122 ( V_32 , V_86 , V_87 , V_206 , V_208 ) ;
if ( V_25 > 0 ) {
V_192 -> V_203 -= V_25 ;
V_25 = 0 ;
}
if ( V_192 -> V_209 || ( V_207 && V_192 -> V_203 > 0 ) ) {
if ( V_87 == V_211 )
V_87 = F_110 ( V_32 ) ;
V_26 -> V_210 = ( V_87 >> V_40 ) + 1 ;
}
return V_25 ;
}
int F_126 ( struct V_17 * V_17 , struct V_10 * V_18 )
{
struct V_1 * V_2 ;
int V_25 ;
V_2 = F_10 ( V_17 , V_18 , 0 ) ;
if ( ! F_13 ( V_2 ) ) {
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 ;
F_2 ( V_10 -> V_217 == V_49 ) ;
if ( F_127 ( ! F_73 ( V_18 ) ) ) {
F_38 ( V_4 , V_7 , V_10 ) ;
V_25 = F_128 ( V_4 , V_7 , V_10 ) ;
} else {
F_80 ( V_18 ) ;
V_25 = 0 ;
}
F_1 ( V_2 ) ;
} else {
F_80 ( V_18 ) ;
V_25 = F_32 ( V_2 ) ;
}
return V_25 ;
}
