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
F_5 ( V_4 , & V_2 -> V_15 ) ;
}
static struct V_1 * F_6 ( struct V_16 * V_16 ,
struct V_10 * V_17 , int V_18 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_6 * V_7 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_23 ;
int V_24 = 0 ;
V_20 = F_7 ( V_17 -> V_25 -> V_26 ) -> V_27 ;
F_2 ( V_20 != NULL ) ;
V_4 = F_8 ( & V_23 ) ;
if ( F_9 ( V_4 ) )
return F_10 ( V_4 ) ;
V_2 = & F_11 ( V_4 ) -> V_28 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_5 = V_4 ;
V_2 -> V_15 = V_23 ;
V_2 -> V_12 = V_13 ;
V_22 = F_12 ( V_4 ) ;
V_7 = V_22 -> V_29 . V_30 ;
if ( V_7 == NULL && V_18 ) {
struct V_31 * V_31 = V_17 -> V_25 -> V_26 ;
T_1 V_32 ;
if ( F_13 ( & V_31 -> V_33 ) ) {
F_14 ( & ( V_31 ) -> V_33 ) ;
F_15 ( L_2
L_3 , V_13 -> V_34 ) ;
F_16 () ;
F_17 () ;
return F_18 ( - V_35 ) ;
}
V_7 = F_19 ( V_4 ) ;
F_20 ( V_7 , V_16 , 1 ) ;
V_7 -> V_36 = V_37 ;
V_32 = ( V_17 -> V_38 << V_39 ) ;
V_24 = F_21 ( V_4 , V_7 , V_40 , V_32 , V_41 ) ;
if ( V_24 == 0 ) {
V_22 -> V_42 = F_22 ( V_16 ) ;
V_22 -> V_43 = NULL ;
V_24 = F_23 ( V_4 , V_7 ) ;
if ( V_24 == 0 ) {
V_24 = F_24 ( V_4 , V_7 ) ;
if ( V_24 == 0 )
V_24 = F_25 ( V_4 , V_7 ) ;
}
} else
V_24 = V_7 -> V_44 ;
}
V_2 -> V_8 = V_7 ;
if ( V_7 == NULL )
V_24 = - V_35 ;
if ( V_24 == 0 ) {
struct V_9 * V_10 ;
F_2 ( V_7 != NULL ) ;
F_2 ( V_7 -> V_45 == V_46 ) ;
F_2 ( V_22 -> V_42 == F_22 ( V_16 ) ) ;
V_10 = F_26 ( V_4 , V_20 , V_17 -> V_38 , V_17 ,
V_47 ) ;
if ( ! F_9 ( V_10 ) ) {
V_2 -> V_11 = V_10 ;
F_27 ( & V_10 -> V_14 , L_1 , V_7 ) ;
V_24 = 0 ;
} else
V_24 = F_28 ( V_10 ) ;
}
if ( V_24 ) {
F_1 ( V_2 ) ;
V_2 = F_18 ( V_24 ) ;
}
F_29 ( V_48 , L_4 V_49 L_5 ,
V_17 -> V_38 , F_30 ( F_31 ( & V_20 -> V_50 ) ) , V_24 ,
V_4 , V_7 ) ;
return V_2 ;
}
static struct V_1 * F_32 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_23 ;
V_4 = F_8 ( & V_23 ) ;
F_2 ( ! F_9 ( V_4 ) ) ;
V_2 = & F_11 ( V_4 ) -> V_28 ;
F_2 ( V_4 == V_2 -> V_5 ) ;
F_2 ( V_13 == V_2 -> V_12 ) ;
F_5 ( V_4 , & V_23 ) ;
return V_2 ;
}
int F_33 ( struct V_16 * V_16 , struct V_10 * V_17 , unsigned V_51 ,
unsigned V_52 )
{
struct V_1 * V_2 ;
int V_24 ;
V_2 = F_6 ( V_16 , V_17 , 1 ) ;
if ( ! F_9 ( V_2 ) ) {
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 ;
F_34 ( V_4 , V_7 , V_10 ) ;
V_24 = F_35 ( V_4 , V_7 , V_10 , V_51 , V_52 ) ;
if ( V_24 == 0 ) {
F_36 ( V_10 ) ;
F_27 ( & V_10 -> V_14 , L_6 ,
V_13 ) ;
} else {
F_37 ( V_4 , V_7 , V_10 ) ;
F_1 ( V_2 ) ;
}
} else {
V_24 = F_28 ( V_2 ) ;
}
return V_24 ;
}
int F_38 ( struct V_16 * V_16 , struct V_10 * V_17 , unsigned V_51 ,
unsigned V_52 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_6 * V_7 ;
struct V_9 * V_10 ;
int V_24 = 0 ;
V_2 = F_32 () ;
V_4 = V_2 -> V_5 ;
V_10 = V_2 -> V_11 ;
V_7 = V_2 -> V_8 ;
F_2 ( F_39 ( V_10 , V_7 ) ) ;
F_2 ( V_51 <= V_52 ) ;
if ( V_51 != V_52 )
V_24 = F_40 ( V_4 , V_7 , V_10 , V_51 , V_52 ) ;
if ( F_39 ( V_10 , V_7 ) )
F_37 ( V_4 , V_7 , V_10 ) ;
F_3 ( & V_10 -> V_14 , L_6 , V_13 ) ;
F_4 ( V_4 , V_10 ) ;
F_1 ( V_2 ) ;
return V_24 ;
}
struct V_53 * F_41 ( struct V_31 * V_31 , enum V_54 V_55 )
{
T_2 V_56 ;
V_56 = V_55 == V_57 ? V_58 : V_59 ;
return F_42 ( V_31 , V_56 ) ;
}
static unsigned long F_43 ( struct V_60 * V_61 ,
struct V_62 * V_63 ,
unsigned long V_64 )
{
struct V_65 * V_66 = & V_61 -> V_65 ;
long V_67 ;
V_67 = F_44 ( V_66 -> V_68 - F_45 ( & V_66 -> V_69 ) , V_64 ) ;
if ( V_67 < 0 || V_67 < F_46 ( long , V_70 , V_64 ) )
GOTO ( V_71 , V_67 = 0 ) ;
if ( V_63 -> V_72 == 0 ) {
long V_73 = ( V_63 -> V_74 + V_67 ) % V_70 ;
if ( V_73 < V_67 )
V_67 -= V_73 ;
}
if ( F_47 ( V_67 , & V_66 -> V_69 ) > V_66 -> V_68 ) {
F_48 ( V_67 , & V_66 -> V_69 ) ;
V_67 = 0 ;
}
V_71:
return V_67 ;
}
void F_49 ( struct V_60 * V_61 , unsigned long V_75 )
{
struct V_65 * V_66 = & V_61 -> V_65 ;
F_48 ( V_75 , & V_66 -> V_69 ) ;
}
static void F_50 ( struct V_60 * V_61 , enum V_76 V_77 )
{
F_51 ( V_77 >= 0 && V_77 < V_78 , L_7 , V_77 ) ;
F_52 ( V_61 -> V_79 , V_77 ) ;
}
void F_53 ( struct V_80 * V_25 , enum V_76 V_77 )
{
struct V_60 * V_61 = F_54 ( V_25 -> V_26 ) ;
F_50 ( V_61 , V_77 ) ;
}
static int F_55 ( unsigned long V_38 , unsigned long V_81 ,
unsigned long V_82 , unsigned long V_83 )
{
unsigned long V_84 = V_81 - V_82 , V_85 = V_81 + V_83 ;
if ( V_84 > V_81 )
V_84 = 0 ;
if ( V_85 < V_81 )
V_85 = ~ 0 ;
return V_84 <= V_38 && V_38 <= V_85 ;
}
static struct V_86 * F_56 ( struct V_16 * V_87 )
{
struct V_88 * V_89 ;
V_89 = F_22 ( V_87 ) ;
return & V_89 -> V_90 ;
}
void F_57 ( struct V_16 * V_87 , struct V_91 * V_92 )
{
struct V_86 * V_93 ;
V_93 = F_56 ( V_87 ) ;
F_58 ( & V_93 -> V_94 ) ;
V_93 -> V_95 ++ ;
V_93 -> V_96 = 0 ;
V_93 -> V_97 ++ ;
V_92 -> V_98 = V_13 ;
F_59 ( & V_92 -> V_99 , & V_93 -> V_100 ) ;
F_60 ( & V_93 -> V_94 ) ;
}
void F_61 ( struct V_16 * V_87 , struct V_91 * V_92 )
{
struct V_86 * V_93 ;
V_93 = F_56 ( V_87 ) ;
F_58 ( & V_93 -> V_94 ) ;
F_62 ( & V_92 -> V_99 ) ;
F_60 ( & V_93 -> V_94 ) ;
}
static struct V_91 * F_63 ( struct V_86 * V_93 )
{
struct V_91 * V_101 ;
F_64 (scan, &ras->ras_read_beads, lrr_linkage) {
if ( V_101 -> V_98 == V_13 )
return V_101 ;
}
return NULL ;
}
struct V_91 * F_65 ( struct V_16 * V_87 )
{
struct V_86 * V_93 ;
struct V_91 * V_102 ;
V_93 = F_56 ( V_87 ) ;
F_58 ( & V_93 -> V_94 ) ;
V_102 = F_63 ( V_93 ) ;
F_60 ( & V_93 -> V_94 ) ;
return V_102 ;
}
static int F_66 ( const struct V_3 * V_4 , struct V_6 * V_7 ,
struct V_103 * V_104 , struct V_9 * V_10 ,
struct V_10 * V_17 )
{
struct V_105 * V_106 ;
int V_107 ;
V_107 = 0 ;
F_34 ( V_4 , V_7 , V_10 ) ;
F_27 ( & V_10 -> V_14 , L_8 , V_13 ) ;
V_106 = F_67 ( F_68 ( V_10 , & V_108 ) ) ;
if ( ! V_106 -> V_109 && ! F_69 ( V_17 ) ) {
V_107 = F_70 ( V_4 , V_7 , V_10 ) ;
if ( V_107 == - V_110 ) {
V_106 -> V_109 = 1 ;
V_106 -> V_111 = 0 ;
F_71 ( V_104 , V_10 ) ;
V_107 = 1 ;
} else {
F_72 ( V_4 , V_10 ) ;
V_107 = - V_112 ;
}
} else {
F_37 ( V_4 , V_7 , V_10 ) ;
}
F_3 ( & V_10 -> V_14 , L_8 , V_13 ) ;
F_4 ( V_4 , V_10 ) ;
return V_107 ;
}
static int F_73 ( const struct V_3 * V_4 , struct V_6 * V_7 ,
struct V_103 * V_104 ,
T_3 V_38 , struct V_80 * V_25 )
{
struct V_10 * V_17 ;
struct V_19 * V_20 = F_7 ( V_25 -> V_26 ) -> V_27 ;
struct V_9 * V_10 ;
enum V_76 V_77 = V_78 ;
unsigned int V_113 ;
int V_107 = 0 ;
const char * V_114 = NULL ;
V_113 = V_115 & ~ V_116 ;
#ifdef F_74
V_113 |= F_74 ;
#endif
V_17 = F_75 ( V_25 , V_38 ) ;
if ( V_17 != NULL ) {
if ( V_17 -> V_25 == V_25 ) {
V_10 = F_26 ( V_4 , V_20 , V_17 -> V_38 ,
V_17 , V_47 ) ;
if ( ! F_9 ( V_10 ) ) {
V_107 = F_66 ( V_4 , V_7 , V_104 ,
V_10 , V_17 ) ;
if ( V_107 == - V_112 ) {
V_77 = V_117 ;
V_114 = L_9 ;
}
} else {
V_77 = V_118 ;
V_114 = L_10 ;
}
} else {
V_77 = V_119 ;
V_114 = L_11 ;
}
if ( V_107 != 1 )
F_76 ( V_17 ) ;
F_77 ( V_17 ) ;
} else {
V_77 = V_118 ;
V_114 = L_12 ;
}
if ( V_114 != NULL ) {
F_53 ( V_25 , V_77 ) ;
F_29 ( V_120 , L_13 , V_114 ) ;
}
return V_107 ;
}
static inline int F_78 ( struct V_86 * V_93 )
{
return V_93 -> V_121 > 1 ;
}
static unsigned long
F_79 ( T_3 V_122 , unsigned long V_123 , unsigned long V_124 ,
unsigned long V_125 , unsigned long V_126 )
{
T_2 V_84 = V_125 > V_122 ? V_125 - V_122 : 0 ;
T_2 V_85 = V_125 + V_126 > V_122 ? V_125 + V_126 - V_122 : 0 ;
unsigned long V_127 = 0 ;
unsigned long V_128 = 0 ;
unsigned long V_129 ;
if ( V_123 == 0 || V_126 == 0 || V_85 == 0 )
return V_126 ;
V_127 = F_80 ( V_84 , V_123 ) ;
if ( V_127 < V_124 )
V_127 = V_124 - V_127 ;
else
V_127 = 0 ;
V_128 = F_80 ( V_85 , V_123 ) ;
if ( V_128 > V_124 )
V_128 = V_124 ;
F_29 ( V_120 , L_14 V_130 L_15 V_130 L_16 ,
V_84 , V_85 , V_127 , V_128 ) ;
if ( V_84 == V_85 )
V_129 = V_128 - ( V_124 - V_127 ) ;
else
V_129 = V_127 + V_124 * ( V_85 - V_84 - 1 ) + V_128 ;
F_29 ( V_120 , L_17
L_18 , V_122 , V_123 , V_124 , V_125 , V_126 , V_129 ) ;
return V_129 ;
}
static int F_81 ( struct V_62 * V_63 )
{
T_2 V_126 = V_63 -> V_131 >= V_63 -> V_74 ?
V_63 -> V_131 - V_63 -> V_74 + 1 : 0 ;
return F_79 ( V_63 -> V_132 , V_63 -> V_133 ,
V_63 -> V_72 , V_63 -> V_74 ,
V_126 ) ;
}
static int F_82 ( unsigned long V_134 , struct V_62 * V_63 )
{
return V_63 -> V_133 == 0 || V_63 -> V_133 == V_63 -> V_72 ||
( V_134 >= V_63 -> V_132 && ( V_134 - V_63 -> V_132 ) %
V_63 -> V_133 < V_63 -> V_72 ) ;
}
static int F_83 ( const struct V_3 * V_4 ,
struct V_6 * V_7 , struct V_103 * V_104 ,
struct V_62 * V_63 ,
unsigned long * V_135 ,
struct V_80 * V_25 ,
unsigned long * V_136 )
{
int V_107 , V_137 = 0 , V_138 ;
unsigned long V_139 ;
F_2 ( V_63 != NULL ) ;
F_84 ( V_63 ) ;
V_138 = V_63 -> V_133 > V_63 -> V_72 && V_63 -> V_72 > 0 ;
for ( V_139 = V_63 -> V_74 ; V_139 <= V_63 -> V_131 &&
* V_135 > 0 ; V_139 ++ ) {
if ( F_82 ( V_139 , V_63 ) ) {
V_107 = F_73 ( V_4 , V_7 , V_104 ,
V_139 , V_25 ) ;
if ( V_107 == 1 ) {
( * V_135 ) -- ;
V_137 ++ ;
} else if ( V_107 == - V_112 )
break;
} else if ( V_138 ) {
T_3 V_140 ;
F_51 ( V_139 > V_63 -> V_132 , L_19
L_20 , V_139 ,
V_63 -> V_74 , V_63 -> V_131 , V_63 -> V_132 ,
V_63 -> V_133 , V_63 -> V_72 ) ;
V_140 = V_139 - V_63 -> V_132 ;
V_140 = V_140 % ( V_63 -> V_133 ) ;
if ( V_140 > V_63 -> V_72 ) {
V_139 += V_63 -> V_133 - V_140 ;
F_29 ( V_120 , L_21 , V_139 ,
V_63 -> V_133 - V_140 ) ;
continue;
}
}
}
* V_136 = V_139 ;
return V_137 ;
}
int F_85 ( const struct V_3 * V_4 , struct V_6 * V_7 ,
struct V_86 * V_93 , struct V_80 * V_25 ,
struct V_103 * V_104 , int V_141 )
{
struct V_142 * V_143 = F_86 ( V_4 ) ;
struct V_144 * V_145 = F_11 ( V_4 ) ;
struct V_146 * V_147 = F_87 ( V_4 ) ;
unsigned long V_84 = 0 , V_85 = 0 , V_148 ;
unsigned long V_136 , V_75 ;
struct V_31 * V_31 ;
struct V_91 * V_102 ;
struct V_62 * V_63 = & V_145 -> V_149 ;
struct V_150 * V_151 ;
struct V_19 * V_20 ;
int V_67 = 0 ;
T_2 V_152 ;
V_31 = V_25 -> V_26 ;
V_151 = F_7 ( V_31 ) ;
V_20 = V_151 -> V_27 ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
F_88 ( V_20 ) ;
V_67 = F_89 ( V_4 , V_20 , V_147 ) ;
F_90 ( V_20 ) ;
if ( V_67 != 0 )
return V_67 ;
V_152 = V_147 -> V_153 ;
if ( V_152 == 0 ) {
F_53 ( V_25 , V_154 ) ;
return 0 ;
}
F_58 ( & V_93 -> V_94 ) ;
if ( V_143 -> V_155 )
V_102 = & V_143 -> V_156 ;
else
V_102 = NULL ;
if ( V_102 != NULL && V_93 -> V_157 + V_93 -> V_158 <
V_102 -> V_159 + V_102 -> V_160 ) {
V_93 -> V_158 = V_102 -> V_159 + V_102 -> V_160 -
V_93 -> V_157 ;
}
if ( V_93 -> V_158 ) {
V_84 = V_93 -> V_161 ;
V_85 = V_93 -> V_157 + V_93 -> V_158 - 1 ;
}
if ( V_85 != 0 ) {
unsigned long V_162 ;
V_162 = ( ( V_85 + 1 ) & ( ~ ( V_70 - 1 ) ) ) ;
if ( V_162 > 0 )
V_162 -- ;
if ( V_162 > V_84 )
V_85 = V_162 ;
V_85 = F_44 ( V_85 , ( unsigned long ) ( ( V_152 - 1 ) >> V_39 ) ) ;
V_93 -> V_161 = F_91 ( V_85 , V_85 + 1 ) ;
F_92 ( V_93 ) ;
}
V_63 -> V_74 = V_84 ;
V_63 -> V_131 = V_85 ;
if ( F_78 ( V_93 ) ) {
V_63 -> V_132 = V_93 -> V_163 ;
V_63 -> V_133 = V_93 -> V_164 ;
V_63 -> V_72 = V_93 -> V_165 ;
}
F_60 ( & V_93 -> V_94 ) ;
if ( V_85 == 0 ) {
F_53 ( V_25 , V_166 ) ;
return 0 ;
}
V_75 = F_81 ( V_63 ) ;
if ( V_75 == 0 )
return 0 ;
V_148 = F_43 ( F_54 ( V_31 ) , V_63 , V_75 ) ;
if ( V_148 < V_75 )
F_53 ( V_25 , V_167 ) ;
F_29 ( V_120 , L_22 , V_148 ,
F_45 ( & F_54 ( V_31 ) -> V_65 . V_69 ) ,
F_54 ( V_31 ) -> V_65 . V_68 ) ;
V_67 = F_83 ( V_4 , V_7 , V_104 ,
V_63 , & V_148 , V_25 , & V_136 ) ;
F_51 ( V_148 >= 0 , L_23 , V_148 ) ;
if ( V_148 != 0 )
F_49 ( F_54 ( V_31 ) , V_148 ) ;
if ( V_136 == V_85 + 1 && V_136 == ( V_152 >> V_39 ) )
F_53 ( V_25 , V_168 ) ;
F_29 ( V_120 , L_24 ,
V_136 , V_85 , V_63 -> V_131 ) ;
if ( V_136 != V_85 + 1 ) {
F_58 ( & V_93 -> V_94 ) ;
if ( V_136 < V_93 -> V_161 &&
F_55 ( V_136 , V_93 -> V_157 , 0 ,
V_93 -> V_158 ) ) {
V_93 -> V_161 = V_136 ;
F_92 ( V_93 ) ;
}
F_60 ( & V_93 -> V_94 ) ;
}
return V_67 ;
}
static void F_93 ( struct V_31 * V_31 , struct V_86 * V_93 ,
unsigned long V_38 )
{
V_93 -> V_157 = V_38 & ( ~ ( F_94 ( V_31 ) - 1 ) ) ;
}
static void F_95 ( struct V_31 * V_31 , struct V_86 * V_93 ,
unsigned long V_38 )
{
V_93 -> V_169 = V_38 ;
V_93 -> V_97 = 0 ;
V_93 -> V_170 = 0 ;
V_93 -> V_158 = 0 ;
F_93 ( V_31 , V_93 , V_38 ) ;
V_93 -> V_161 = F_91 ( V_93 -> V_157 , V_38 ) ;
F_92 ( V_93 ) ;
}
static void F_96 ( struct V_86 * V_93 )
{
V_93 -> V_121 = 0 ;
V_93 -> V_164 = 0 ;
V_93 -> V_165 = 0 ;
F_92 ( V_93 ) ;
}
void F_97 ( struct V_31 * V_31 , struct V_86 * V_93 )
{
F_98 ( & V_93 -> V_94 ) ;
F_95 ( V_31 , V_93 , 0 ) ;
V_93 -> V_95 = 0 ;
F_99 ( & V_93 -> V_100 ) ;
}
static int F_100 ( struct V_86 * V_93 ,
unsigned long V_38 )
{
unsigned long V_171 ;
if ( V_93 -> V_164 == 0 || V_93 -> V_165 == 0 ||
V_93 -> V_165 == V_93 -> V_164 )
return 0 ;
V_171 = V_38 - V_93 -> V_169 - 1 ;
if ( V_171 == 0 )
return V_93 -> V_170 + 1 <= V_93 -> V_165 ;
return ( V_93 -> V_164 - V_93 -> V_165 ) == V_171 &&
V_93 -> V_170 == V_93 -> V_165 ;
}
static void F_101 ( struct V_86 * V_93 ,
unsigned long V_38 )
{
unsigned long V_171 = V_38 - V_93 -> V_169 - 1 ;
if ( ! F_78 ( V_93 ) && ( V_171 != 0 ||
V_93 -> V_121 == 0 ) ) {
V_93 -> V_165 = V_93 -> V_170 ;
V_93 -> V_164 = V_171 + V_93 -> V_170 ;
}
F_2 ( V_93 -> V_96 == 0 ) ;
F_2 ( V_93 -> V_121 == 0 ) ;
if ( V_38 <= V_93 -> V_169 ) {
F_96 ( V_93 ) ;
return;
}
V_93 -> V_165 = V_93 -> V_170 ;
V_93 -> V_164 = V_171 + V_93 -> V_170 ;
F_92 ( V_93 ) ;
return;
}
static unsigned long
F_102 ( struct V_86 * V_93 , unsigned long V_75 )
{
return F_79 ( V_93 -> V_163 , V_93 -> V_164 ,
V_93 -> V_165 , V_93 -> V_163 ,
V_75 ) ;
}
static void F_103 ( struct V_86 * V_93 ,
struct V_65 * V_66 ,
unsigned long V_172 )
{
unsigned long V_173 , V_174 , V_175 ;
unsigned long V_176 ;
F_2 ( V_93 -> V_164 > 0 ) ;
F_51 ( V_93 -> V_157 + V_93 -> V_158
>= V_93 -> V_163 , L_25
L_26 , V_93 -> V_157 ,
V_93 -> V_158 , V_93 -> V_163 ) ;
V_176 = V_93 -> V_157 + V_93 -> V_158 -
V_93 -> V_163 ;
V_173 = V_176 % V_93 -> V_164 ;
V_175 = V_93 -> V_158 - V_173 ;
if ( V_173 < V_93 -> V_165 )
V_173 += V_172 ;
else
V_173 = V_93 -> V_165 + V_172 ;
F_2 ( V_93 -> V_165 != 0 ) ;
V_174 = V_173 / V_93 -> V_165 ;
V_173 %= V_93 -> V_165 ;
V_175 += V_174 * V_93 -> V_164 + V_173 ;
if ( F_102 ( V_93 , V_175 ) <= V_66 -> V_177 )
V_93 -> V_158 = V_175 ;
F_92 ( V_93 ) ;
}
static void F_104 ( struct V_31 * V_31 ,
struct V_86 * V_93 ,
struct V_65 * V_66 )
{
if ( F_78 ( V_93 ) )
F_103 ( V_93 , V_66 , F_94 ( V_31 ) ) ;
else
V_93 -> V_158 = F_44 ( V_93 -> V_158 +
F_94 ( V_31 ) ,
V_66 -> V_177 ) ;
}
void F_105 ( struct V_60 * V_61 , struct V_31 * V_31 ,
struct V_86 * V_93 , unsigned long V_38 ,
unsigned V_178 )
{
struct V_65 * V_66 = & V_61 -> V_65 ;
int V_179 = 0 , V_180 = 0 , V_181 = 0 ;
F_58 ( & V_93 -> V_94 ) ;
F_50 ( V_61 , V_178 ? V_182 : V_183 ) ;
if ( ! F_55 ( V_38 , V_93 -> V_169 , 8 , 8 ) ) {
V_179 = 1 ;
F_50 ( V_61 , V_184 ) ;
} else if ( ! V_178 && V_93 -> V_158 &&
V_38 < V_93 -> V_161 &&
F_55 ( V_38 , V_93 -> V_157 , 0 ,
V_93 -> V_158 ) ) {
V_181 = 1 ;
F_50 ( V_61 , V_185 ) ;
}
if ( V_93 -> V_95 == 2 && ! V_93 -> V_96 ) {
T_2 V_186 ;
V_186 = ( F_106 ( V_31 ) + V_41 - 1 ) >>
V_39 ;
F_29 ( V_120 , L_27 V_130 L_28 , V_186 ,
V_66 -> V_187 , V_66 -> V_177 ) ;
if ( V_186 &&
V_186 <= V_66 -> V_187 ) {
V_93 -> V_157 = 0 ;
V_93 -> V_169 = 0 ;
V_93 -> V_161 = 0 ;
V_93 -> V_158 = F_44 ( V_66 -> V_177 ,
V_66 -> V_187 ) ;
GOTO ( V_188 , 0 ) ;
}
}
if ( V_179 ) {
if ( ! F_100 ( V_93 , V_38 ) ) {
if ( V_93 -> V_121 == 0 &&
V_93 -> V_96 == 0 ) {
F_101 ( V_93 , V_38 ) ;
V_93 -> V_121 ++ ;
} else {
F_96 ( V_93 ) ;
}
F_95 ( V_31 , V_93 , V_38 ) ;
V_93 -> V_170 ++ ;
GOTO ( V_188 , 0 ) ;
} else {
V_93 -> V_170 = 0 ;
V_93 -> V_97 = 0 ;
if ( ++ V_93 -> V_121 > 1 )
V_180 = 1 ;
F_92 ( V_93 ) ;
}
} else {
if ( V_181 ) {
if ( F_100 ( V_93 , V_38 ) &&
F_78 ( V_93 ) ) {
if ( V_38 != V_93 -> V_169 + 1 )
V_93 -> V_170 = 0 ;
F_95 ( V_31 , V_93 , V_38 ) ;
F_92 ( V_93 ) ;
} else {
F_95 ( V_31 , V_93 , V_38 ) ;
V_93 -> V_170 ++ ;
F_96 ( V_93 ) ;
GOTO ( V_188 , 0 ) ;
}
} else if ( F_78 ( V_93 ) ) {
if ( ! F_100 ( V_93 , V_38 ) ) {
F_96 ( V_93 ) ;
V_93 -> V_158 = 0 ;
V_93 -> V_161 = V_38 ;
}
}
}
V_93 -> V_170 ++ ;
V_93 -> V_169 = V_38 ;
F_93 ( V_31 , V_93 , V_38 ) ;
if ( F_78 ( V_93 ) )
V_93 -> V_161 = F_91 ( V_38 , V_93 -> V_161 ) ;
else
V_93 -> V_161 = F_91 ( V_93 -> V_157 ,
V_93 -> V_161 ) ;
F_92 ( V_93 ) ;
if ( ! V_93 -> V_158 && V_93 -> V_170 == 4 ) {
V_93 -> V_158 = F_94 ( V_31 ) ;
GOTO ( V_188 , 0 ) ;
}
if ( V_93 -> V_121 == 2 && V_180 ) {
V_93 -> V_161 = F_91 ( V_38 , V_93 -> V_161 ) ;
V_93 -> V_163 = V_38 ;
V_93 -> V_158 = F_94 ( V_31 ) ;
}
if ( ( V_93 -> V_97 > 1 || V_180 ) &&
! V_93 -> V_96 )
F_104 ( V_31 , V_93 , V_66 ) ;
V_188:
F_92 ( V_93 ) ;
V_93 -> V_96 ++ ;
F_60 ( & V_93 -> V_94 ) ;
return;
}
int F_107 ( struct V_10 * V_17 , struct V_189 * V_190 )
{
struct V_31 * V_31 = V_17 -> V_25 -> V_26 ;
struct V_150 * V_151 = F_7 ( V_31 ) ;
struct V_3 * V_4 ;
struct V_6 * V_7 ;
struct V_9 * V_10 ;
struct V_19 * V_20 ;
struct V_191 V_192 ;
bool V_193 = false ;
bool V_194 = false ;
int V_24 ;
F_2 ( F_108 ( V_17 ) ) ;
F_2 ( ! F_109 ( V_17 ) ) ;
F_2 ( F_110 ( V_31 ) != NULL ) ;
V_4 = F_111 ( & V_192 ) ;
if ( F_9 ( V_4 ) )
GOTO ( V_71 , V_24 = F_28 ( V_4 ) ) ;
V_20 = F_7 ( V_31 ) -> V_27 ;
F_2 ( V_20 != NULL ) ;
V_7 = F_19 ( V_4 ) ;
V_7 -> V_195 = V_20 ;
V_7 -> V_196 = 1 ;
V_24 = F_112 ( V_4 , V_7 , V_197 , V_20 ) ;
if ( V_24 == 0 ) {
V_10 = F_26 ( V_4 , V_20 , V_17 -> V_38 ,
V_17 , V_47 ) ;
if ( ! F_9 ( V_10 ) ) {
F_27 ( & V_10 -> V_14 , L_29 ,
V_13 ) ;
F_34 ( V_4 , V_7 , V_10 ) ;
V_24 = F_113 ( V_4 , V_7 , V_10 ) ;
if ( V_24 != 0 ) {
if ( ! F_114 ( V_17 ) ) {
F_115 ( V_190 , V_17 ) ;
V_24 = 0 ;
V_193 = true ;
}
}
F_116 ( V_4 , V_7 , V_10 ) ;
V_194 = true ;
F_3 ( & V_10 -> V_14 ,
L_29 , V_13 ) ;
F_4 ( V_4 , V_10 ) ;
} else {
V_24 = F_28 ( V_10 ) ;
}
}
F_117 ( V_4 , V_7 ) ;
if ( V_193 && V_190 -> V_198 == V_199 ) {
T_1 V_140 = F_118 ( V_20 , V_17 -> V_38 ) ;
V_24 = F_119 ( V_31 , V_140 ,
V_140 + V_41 - 1 ,
V_200 , 1 ) ;
if ( V_24 > 0 ) {
V_190 -> V_201 -= V_24 - 1 ;
V_24 = 0 ;
}
}
F_120 ( & V_192 , V_4 ) ;
GOTO ( V_71 , V_24 ) ;
V_71:
if ( V_24 < 0 ) {
if ( ! V_151 -> V_202 )
V_151 -> V_202 = V_24 ;
F_121 ( V_17 ) ;
if ( ! V_194 )
F_76 ( V_17 ) ;
}
return V_24 ;
}
int F_122 ( struct V_80 * V_25 , struct V_189 * V_190 )
{
struct V_31 * V_31 = V_25 -> V_26 ;
struct V_60 * V_61 = F_54 ( V_31 ) ;
T_1 V_84 ;
T_1 V_85 ;
enum V_203 V_204 ;
int V_205 = 0 ;
int V_24 ;
int V_206 = 0 ;
if ( V_190 -> V_207 ) {
V_84 = V_25 -> V_208 << V_39 ;
V_85 = V_209 ;
} else {
V_84 = V_190 -> V_210 ;
V_85 = V_190 -> V_211 ;
if ( V_85 == V_212 ) {
V_85 = V_209 ;
V_205 = V_84 == 0 ;
}
}
V_204 = V_213 ;
if ( V_190 -> V_198 == V_199 )
V_204 = V_200 ;
if ( V_61 -> V_214 )
V_206 = 1 ;
V_24 = F_119 ( V_31 , V_84 , V_85 , V_204 , V_206 ) ;
if ( V_24 > 0 ) {
V_190 -> V_201 -= V_24 ;
V_24 = 0 ;
}
if ( V_190 -> V_207 || ( V_205 && V_190 -> V_201 > 0 ) ) {
if ( V_85 == V_209 )
V_85 = F_106 ( V_31 ) ;
V_25 -> V_208 = ( V_85 >> V_39 ) + 1 ;
}
return V_24 ;
}
int F_123 ( struct V_16 * V_16 , struct V_10 * V_17 )
{
struct V_1 * V_2 ;
int V_24 ;
V_2 = F_6 ( V_16 , V_17 , 0 ) ;
if ( ! F_9 ( V_2 ) ) {
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 ;
F_2 ( V_10 -> V_215 == V_47 ) ;
if ( F_124 ( ! F_69 ( V_17 ) ) ) {
F_34 ( V_4 , V_7 , V_10 ) ;
V_24 = F_125 ( V_4 , V_7 , V_10 ) ;
} else {
F_76 ( V_17 ) ;
V_24 = 0 ;
}
F_1 ( V_2 ) ;
} else {
F_76 ( V_17 ) ;
V_24 = F_28 ( V_2 ) ;
}
return V_24 ;
}
