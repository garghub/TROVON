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
return F_14 ( F_15 ( V_4 ) ) ;
V_2 = & F_16 ( V_4 ) -> V_29 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_5 = V_4 ;
V_2 -> V_16 = V_24 ;
V_2 -> V_12 = V_13 ;
V_23 = F_17 ( V_4 ) ;
V_7 = V_23 -> V_30 . V_31 ;
if ( V_7 == NULL && V_19 ) {
struct V_32 * V_32 = V_18 -> V_26 -> V_27 ;
T_1 V_33 ;
if ( F_18 ( & V_32 -> V_34 ) ) {
F_19 ( & ( V_32 ) -> V_34 ) ;
F_20 ( L_2
L_3 , V_13 -> V_35 ) ;
F_21 ( NULL ) ;
F_22 () ;
return F_14 ( - V_36 ) ;
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
V_25 = F_15 ( V_10 ) ;
}
if ( V_25 ) {
F_1 ( V_2 ) ;
V_2 = F_14 ( V_25 ) ;
}
F_32 ( V_50 , L_4 V_51 L_5 ,
V_18 -> V_39 , F_33 ( F_34 ( & V_21 -> V_52 ) ) , V_25 ,
V_4 , V_7 ) ;
return V_2 ;
}
static struct V_1 * F_35 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_24 ;
V_4 = F_12 ( & V_24 ) ;
F_2 ( ! F_13 ( V_4 ) ) ;
V_2 = & F_16 ( V_4 ) -> V_29 ;
F_2 ( V_4 == V_2 -> V_5 ) ;
F_2 ( V_13 == V_2 -> V_12 ) ;
F_9 ( V_4 , & V_24 ) ;
return V_2 ;
}
int F_36 ( struct V_17 * V_17 , struct V_10 * V_18 , unsigned V_53 ,
unsigned V_54 )
{
struct V_1 * V_2 ;
int V_25 ;
V_55 ;
V_2 = F_10 ( V_17 , V_18 , 1 ) ;
if ( ! F_13 ( V_2 ) ) {
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 ;
F_37 ( V_4 , V_7 , V_10 ) ;
V_25 = F_38 ( V_4 , V_7 , V_10 , V_53 , V_54 ) ;
if ( V_25 == 0 ) {
F_39 ( V_10 ) ;
F_31 ( & V_10 -> V_14 , L_6 ,
V_13 ) ;
} else {
F_40 ( V_4 , V_7 , V_10 ) ;
F_1 ( V_2 ) ;
}
} else {
V_25 = F_15 ( V_2 ) ;
}
RETURN ( V_25 ) ;
}
int F_41 ( struct V_17 * V_17 , struct V_10 * V_18 , unsigned V_53 ,
unsigned V_54 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_6 * V_7 ;
struct V_9 * V_10 ;
int V_25 = 0 ;
V_55 ;
V_2 = F_35 () ;
V_4 = V_2 -> V_5 ;
V_10 = V_2 -> V_11 ;
V_7 = V_2 -> V_8 ;
F_2 ( F_42 ( V_10 , V_7 ) ) ;
F_2 ( V_53 <= V_54 ) ;
if ( V_53 != V_54 )
V_25 = F_43 ( V_4 , V_7 , V_10 , V_53 , V_54 ) ;
if ( F_42 ( V_10 , V_7 ) )
F_40 ( V_4 , V_7 , V_10 ) ;
F_3 ( & V_10 -> V_14 , L_6 , V_13 ) ;
F_4 ( V_4 , V_10 ) ;
F_1 ( V_2 ) ;
RETURN ( V_25 ) ;
}
struct V_56 * F_44 ( struct V_32 * V_32 , enum V_57 V_58 )
{
T_2 V_59 ;
V_59 = V_58 == V_60 ? V_61 : V_62 ;
return F_45 ( V_32 , V_59 ) ;
}
static unsigned long F_46 ( struct V_63 * V_64 ,
struct V_65 * V_66 ,
unsigned long V_67 )
{
struct V_68 * V_69 = & V_64 -> V_68 ;
long V_70 ;
V_55 ;
V_70 = F_47 ( V_69 -> V_71 - F_48 ( & V_69 -> V_72 ) , V_67 ) ;
if ( V_70 < 0 || V_70 < F_49 ( long , V_73 , V_67 ) )
GOTO ( V_74 , V_70 = 0 ) ;
if ( V_66 -> V_75 == 0 ) {
long V_76 = ( V_66 -> V_77 + V_70 ) % V_73 ;
if ( V_76 < V_70 )
V_70 -= V_76 ;
}
if ( F_50 ( V_70 , & V_69 -> V_72 ) > V_69 -> V_71 ) {
F_51 ( V_70 , & V_69 -> V_72 ) ;
V_70 = 0 ;
}
V_74:
RETURN ( V_70 ) ;
}
void F_52 ( struct V_63 * V_64 , unsigned long V_78 )
{
struct V_68 * V_69 = & V_64 -> V_68 ;
F_51 ( V_78 , & V_69 -> V_72 ) ;
}
static void F_53 ( struct V_63 * V_64 , enum V_79 V_80 )
{
F_54 ( V_80 >= 0 && V_80 < V_81 , L_7 , V_80 ) ;
F_55 ( V_64 -> V_82 , V_80 ) ;
}
void F_56 ( struct V_83 * V_26 , enum V_79 V_80 )
{
struct V_63 * V_64 = F_57 ( V_26 -> V_27 ) ;
F_53 ( V_64 , V_80 ) ;
}
static int F_58 ( unsigned long V_39 , unsigned long V_84 ,
unsigned long V_85 , unsigned long V_86 )
{
unsigned long V_87 = V_84 - V_85 , V_88 = V_84 + V_86 ;
if ( V_87 > V_84 )
V_87 = 0 ;
if ( V_88 < V_84 )
V_88 = ~ 0 ;
return V_87 <= V_39 && V_39 <= V_88 ;
}
static struct V_89 * F_59 ( struct V_17 * V_90 )
{
struct V_91 * V_92 ;
V_92 = F_26 ( V_90 ) ;
return & V_92 -> V_93 ;
}
void F_60 ( struct V_17 * V_90 , struct V_94 * V_95 )
{
struct V_89 * V_96 ;
V_96 = F_59 ( V_90 ) ;
F_61 ( & V_96 -> V_97 ) ;
V_96 -> V_98 ++ ;
V_96 -> V_99 = 0 ;
V_96 -> V_100 ++ ;
V_95 -> V_101 = V_13 ;
F_62 ( & V_95 -> V_102 , & V_96 -> V_103 ) ;
F_63 ( & V_96 -> V_97 ) ;
}
void F_64 ( struct V_17 * V_90 , struct V_94 * V_95 )
{
struct V_89 * V_96 ;
V_96 = F_59 ( V_90 ) ;
F_61 ( & V_96 -> V_97 ) ;
F_65 ( & V_95 -> V_102 ) ;
F_63 ( & V_96 -> V_97 ) ;
}
static struct V_94 * F_66 ( struct V_89 * V_96 )
{
struct V_94 * V_104 ;
F_67 (scan, &ras->ras_read_beads, lrr_linkage) {
if ( V_104 -> V_101 == V_13 )
return V_104 ;
}
return NULL ;
}
struct V_94 * F_68 ( struct V_17 * V_90 )
{
struct V_89 * V_96 ;
struct V_94 * V_105 ;
V_96 = F_59 ( V_90 ) ;
F_61 ( & V_96 -> V_97 ) ;
V_105 = F_66 ( V_96 ) ;
F_63 ( & V_96 -> V_97 ) ;
return V_105 ;
}
static int F_69 ( const struct V_3 * V_4 , struct V_6 * V_7 ,
struct V_106 * V_107 , struct V_9 * V_10 ,
struct V_10 * V_18 )
{
struct V_108 * V_109 ;
int V_110 ;
V_55 ;
V_110 = 0 ;
F_37 ( V_4 , V_7 , V_10 ) ;
F_31 ( & V_10 -> V_14 , L_8 , V_13 ) ;
V_109 = F_70 ( F_71 ( V_10 , & V_111 ) ) ;
if ( ! V_109 -> V_112 && ! F_72 ( V_18 ) ) {
V_110 = F_73 ( V_4 , V_7 , V_10 ) ;
if ( V_110 == - V_113 ) {
V_109 -> V_112 = 1 ;
V_109 -> V_114 = 0 ;
F_74 ( V_107 , V_10 ) ;
V_110 = 1 ;
} else {
F_75 ( V_4 , V_10 ) ;
V_110 = - V_115 ;
}
} else {
F_40 ( V_4 , V_7 , V_10 ) ;
}
F_3 ( & V_10 -> V_14 , L_8 , V_13 ) ;
F_4 ( V_4 , V_10 ) ;
RETURN ( V_110 ) ;
}
static int F_76 ( const struct V_3 * V_4 , struct V_6 * V_7 ,
struct V_106 * V_107 ,
T_3 V_39 , struct V_83 * V_26 )
{
struct V_10 * V_18 ;
struct V_20 * V_21 = F_11 ( V_26 -> V_27 ) -> V_28 ;
struct V_9 * V_10 ;
enum V_79 V_80 = V_81 ;
unsigned int V_116 ;
int V_110 = 0 ;
const char * V_117 = NULL ;
V_55 ;
V_116 = V_118 & ~ V_119 ;
#ifdef F_77
V_116 |= F_77 ;
#endif
V_18 = F_78 ( V_26 , V_39 ) ;
if ( V_18 != NULL ) {
if ( V_18 -> V_26 == V_26 ) {
V_10 = F_30 ( V_4 , V_21 , V_18 -> V_39 ,
V_18 , V_49 ) ;
if ( ! F_13 ( V_10 ) ) {
V_110 = F_69 ( V_4 , V_7 , V_107 ,
V_10 , V_18 ) ;
if ( V_110 == - V_115 ) {
V_80 = V_120 ;
V_117 = L_9 ;
}
} else {
V_80 = V_121 ;
V_117 = L_10 ;
}
} else {
V_80 = V_122 ;
V_117 = L_11 ;
}
if ( V_110 != 1 )
F_79 ( V_18 ) ;
F_80 ( V_18 ) ;
} else {
V_80 = V_121 ;
V_117 = L_12 ;
}
if ( V_117 != NULL ) {
F_56 ( V_26 , V_80 ) ;
F_32 ( V_123 , L_13 , V_117 ) ;
}
RETURN ( V_110 ) ;
}
static inline int F_81 ( struct V_89 * V_96 )
{
return V_96 -> V_124 > 1 ;
}
static unsigned long
F_82 ( T_3 V_125 , unsigned long V_126 , unsigned long V_127 ,
unsigned long V_128 , unsigned long V_129 )
{
T_2 V_87 = V_128 > V_125 ? V_128 - V_125 : 0 ;
T_2 V_88 = V_128 + V_129 > V_125 ? V_128 + V_129 - V_125 : 0 ;
unsigned long V_130 = 0 ;
unsigned long V_131 = 0 ;
unsigned long V_132 ;
if ( V_126 == 0 || V_129 == 0 || V_88 == 0 )
return V_129 ;
V_130 = F_83 ( V_87 , V_126 ) ;
if ( V_130 < V_127 )
V_130 = V_127 - V_130 ;
else
V_130 = 0 ;
V_131 = F_83 ( V_88 , V_126 ) ;
if ( V_131 > V_127 )
V_131 = V_127 ;
F_32 ( V_123 , L_14 V_133 L_15 V_133 L_16 ,
V_87 , V_88 , V_130 , V_131 ) ;
if ( V_87 == V_88 )
V_132 = V_131 - ( V_127 - V_130 ) ;
else
V_132 = V_130 + V_127 * ( V_88 - V_87 - 1 ) + V_131 ;
F_32 ( V_123 , L_17
L_18 , V_125 , V_126 , V_127 , V_128 , V_129 , V_132 ) ;
return V_132 ;
}
static int F_84 ( struct V_65 * V_66 )
{
T_2 V_129 = V_66 -> V_134 >= V_66 -> V_77 ?
V_66 -> V_134 - V_66 -> V_77 + 1 : 0 ;
return F_82 ( V_66 -> V_135 , V_66 -> V_136 ,
V_66 -> V_75 , V_66 -> V_77 ,
V_129 ) ;
}
static int F_85 ( unsigned long V_137 , struct V_65 * V_66 )
{
return V_66 -> V_136 == 0 || V_66 -> V_136 == V_66 -> V_75 ||
( V_137 >= V_66 -> V_135 && ( V_137 - V_66 -> V_135 ) %
V_66 -> V_136 < V_66 -> V_75 ) ;
}
static int F_86 ( const struct V_3 * V_4 ,
struct V_6 * V_7 , struct V_106 * V_107 ,
struct V_65 * V_66 ,
unsigned long * V_138 ,
struct V_83 * V_26 ,
unsigned long * V_139 )
{
int V_110 , V_140 = 0 , V_141 ;
unsigned long V_142 ;
F_2 ( V_66 != NULL ) ;
F_87 ( V_66 ) ;
V_141 = V_66 -> V_136 > V_66 -> V_75 && V_66 -> V_75 > 0 ;
for ( V_142 = V_66 -> V_77 ; V_142 <= V_66 -> V_134 &&
* V_138 > 0 ; V_142 ++ ) {
if ( F_85 ( V_142 , V_66 ) ) {
V_110 = F_76 ( V_4 , V_7 , V_107 ,
V_142 , V_26 ) ;
if ( V_110 == 1 ) {
( * V_138 ) -- ;
V_140 ++ ;
} else if ( V_110 == - V_115 )
break;
} else if ( V_141 ) {
T_3 V_143 ;
F_54 ( V_142 > V_66 -> V_135 , L_19
L_20 , V_142 ,
V_66 -> V_77 , V_66 -> V_134 , V_66 -> V_135 ,
V_66 -> V_136 , V_66 -> V_75 ) ;
V_143 = V_142 - V_66 -> V_135 ;
V_143 = V_143 % ( V_66 -> V_136 ) ;
if ( V_143 > V_66 -> V_75 ) {
V_142 += V_66 -> V_136 - V_143 ;
F_32 ( V_123 , L_21 , V_142 ,
V_66 -> V_136 - V_143 ) ;
continue;
}
}
}
* V_139 = V_142 ;
return V_140 ;
}
int F_88 ( const struct V_3 * V_4 , struct V_6 * V_7 ,
struct V_89 * V_96 , struct V_83 * V_26 ,
struct V_106 * V_107 , int V_144 )
{
struct V_145 * V_146 = F_89 ( V_4 ) ;
struct V_147 * V_148 = F_16 ( V_4 ) ;
struct V_149 * V_150 = F_90 ( V_4 ) ;
unsigned long V_87 = 0 , V_88 = 0 , V_151 ;
unsigned long V_139 , V_78 ;
struct V_32 * V_32 ;
struct V_94 * V_105 ;
struct V_65 * V_66 = & V_148 -> V_152 ;
struct V_153 * V_154 ;
struct V_20 * V_21 ;
int V_70 = 0 ;
T_2 V_155 ;
V_55 ;
V_32 = V_26 -> V_27 ;
V_154 = F_11 ( V_32 ) ;
V_21 = V_154 -> V_28 ;
memset ( V_66 , 0 , sizeof *V_66 ) ;
F_91 ( V_21 ) ;
V_70 = F_92 ( V_4 , V_21 , V_150 ) ;
F_93 ( V_21 ) ;
if ( V_70 != 0 )
RETURN ( V_70 ) ;
V_155 = V_150 -> V_156 ;
if ( V_155 == 0 ) {
F_56 ( V_26 , V_157 ) ;
RETURN ( 0 ) ;
}
F_61 ( & V_96 -> V_97 ) ;
if ( V_146 -> V_158 )
V_105 = & V_146 -> V_159 ;
else
V_105 = NULL ;
if ( V_105 != NULL && V_96 -> V_160 + V_96 -> V_161 <
V_105 -> V_162 + V_105 -> V_163 ) {
V_96 -> V_161 = V_105 -> V_162 + V_105 -> V_163 -
V_96 -> V_160 ;
}
if ( V_96 -> V_161 ) {
V_87 = V_96 -> V_164 ;
V_88 = V_96 -> V_160 + V_96 -> V_161 - 1 ;
}
if ( V_88 != 0 ) {
unsigned long V_165 ;
V_165 = ( ( V_88 + 1 ) & ( ~ ( V_73 - 1 ) ) ) ;
if ( V_165 > 0 )
V_165 -- ;
if ( V_165 > V_87 )
V_88 = V_165 ;
V_88 = F_47 ( V_88 , ( unsigned long ) ( ( V_155 - 1 ) >> V_40 ) ) ;
V_96 -> V_164 = F_94 ( V_88 , V_88 + 1 ) ;
F_95 ( V_96 ) ;
}
V_66 -> V_77 = V_87 ;
V_66 -> V_134 = V_88 ;
if ( F_81 ( V_96 ) ) {
V_66 -> V_135 = V_96 -> V_166 ;
V_66 -> V_136 = V_96 -> V_167 ;
V_66 -> V_75 = V_96 -> V_168 ;
}
F_63 ( & V_96 -> V_97 ) ;
if ( V_88 == 0 ) {
F_56 ( V_26 , V_169 ) ;
RETURN ( 0 ) ;
}
V_78 = F_84 ( V_66 ) ;
if ( V_78 == 0 )
RETURN ( 0 ) ;
V_151 = F_46 ( F_57 ( V_32 ) , V_66 , V_78 ) ;
if ( V_151 < V_78 )
F_56 ( V_26 , V_170 ) ;
F_32 ( V_123 , L_22 , V_151 ,
F_48 ( & F_57 ( V_32 ) -> V_68 . V_72 ) ,
F_57 ( V_32 ) -> V_68 . V_71 ) ;
V_70 = F_86 ( V_4 , V_7 , V_107 ,
V_66 , & V_151 , V_26 , & V_139 ) ;
F_54 ( V_151 >= 0 , L_23 , V_151 ) ;
if ( V_151 != 0 )
F_52 ( F_57 ( V_32 ) , V_151 ) ;
if ( V_139 == V_88 + 1 && V_139 == ( V_155 >> V_40 ) )
F_56 ( V_26 , V_171 ) ;
F_32 ( V_123 , L_24 ,
V_139 , V_88 , V_66 -> V_134 ) ;
if ( V_139 != V_88 + 1 ) {
F_61 ( & V_96 -> V_97 ) ;
if ( V_139 < V_96 -> V_164 &&
F_58 ( V_139 , V_96 -> V_160 , 0 ,
V_96 -> V_161 ) ) {
V_96 -> V_164 = V_139 ;
F_95 ( V_96 ) ;
}
F_63 ( & V_96 -> V_97 ) ;
}
RETURN ( V_70 ) ;
}
static void F_96 ( struct V_32 * V_32 , struct V_89 * V_96 ,
unsigned long V_39 )
{
V_96 -> V_160 = V_39 & ( ~ ( F_97 ( V_32 ) - 1 ) ) ;
}
static void F_98 ( struct V_32 * V_32 , struct V_89 * V_96 ,
unsigned long V_39 )
{
V_96 -> V_172 = V_39 ;
V_96 -> V_100 = 0 ;
V_96 -> V_173 = 0 ;
V_96 -> V_161 = 0 ;
F_96 ( V_32 , V_96 , V_39 ) ;
V_96 -> V_164 = F_94 ( V_96 -> V_160 , V_39 ) ;
F_95 ( V_96 ) ;
}
static void F_99 ( struct V_89 * V_96 )
{
V_96 -> V_124 = 0 ;
V_96 -> V_167 = 0 ;
V_96 -> V_168 = 0 ;
F_95 ( V_96 ) ;
}
void F_100 ( struct V_32 * V_32 , struct V_89 * V_96 )
{
F_101 ( & V_96 -> V_97 ) ;
F_98 ( V_32 , V_96 , 0 ) ;
V_96 -> V_98 = 0 ;
F_102 ( & V_96 -> V_103 ) ;
}
static int F_103 ( struct V_89 * V_96 ,
unsigned long V_39 )
{
unsigned long V_174 ;
if ( V_96 -> V_167 == 0 || V_96 -> V_168 == 0 ||
V_96 -> V_168 == V_96 -> V_167 )
return 0 ;
V_174 = V_39 - V_96 -> V_172 - 1 ;
if ( V_174 == 0 )
return V_96 -> V_173 + 1 <= V_96 -> V_168 ;
return ( V_96 -> V_167 - V_96 -> V_168 ) == V_174 &&
V_96 -> V_173 == V_96 -> V_168 ;
}
static void F_104 ( struct V_89 * V_96 ,
unsigned long V_39 )
{
unsigned long V_174 = V_39 - V_96 -> V_172 - 1 ;
if ( ! F_81 ( V_96 ) && ( V_174 != 0 ||
V_96 -> V_124 == 0 ) ) {
V_96 -> V_168 = V_96 -> V_173 ;
V_96 -> V_167 = V_174 + V_96 -> V_173 ;
}
F_2 ( V_96 -> V_99 == 0 ) ;
F_2 ( V_96 -> V_124 == 0 ) ;
if ( V_39 <= V_96 -> V_172 ) {
F_99 ( V_96 ) ;
return;
}
V_96 -> V_168 = V_96 -> V_173 ;
V_96 -> V_167 = V_174 + V_96 -> V_173 ;
F_95 ( V_96 ) ;
return;
}
static unsigned long
F_105 ( struct V_89 * V_96 , unsigned long V_78 )
{
return F_82 ( V_96 -> V_166 , V_96 -> V_167 ,
V_96 -> V_168 , V_96 -> V_166 ,
V_78 ) ;
}
static void F_106 ( struct V_89 * V_96 ,
struct V_68 * V_69 ,
unsigned long V_175 )
{
unsigned long V_176 , V_177 , V_178 ;
unsigned long V_179 ;
F_2 ( V_96 -> V_167 > 0 ) ;
F_54 ( V_96 -> V_160 + V_96 -> V_161
>= V_96 -> V_166 , L_25
L_26 , V_96 -> V_160 ,
V_96 -> V_161 , V_96 -> V_166 ) ;
V_179 = V_96 -> V_160 + V_96 -> V_161 -
V_96 -> V_166 ;
V_176 = V_179 % V_96 -> V_167 ;
V_178 = V_96 -> V_161 - V_176 ;
if ( V_176 < V_96 -> V_168 )
V_176 += V_175 ;
else
V_176 = V_96 -> V_168 + V_175 ;
F_2 ( V_96 -> V_168 != 0 ) ;
V_177 = V_176 / V_96 -> V_168 ;
V_176 %= V_96 -> V_168 ;
V_178 += V_177 * V_96 -> V_167 + V_176 ;
if ( F_105 ( V_96 , V_178 ) <= V_69 -> V_180 )
V_96 -> V_161 = V_178 ;
F_95 ( V_96 ) ;
}
static void F_107 ( struct V_32 * V_32 ,
struct V_89 * V_96 ,
struct V_68 * V_69 )
{
if ( F_81 ( V_96 ) )
F_106 ( V_96 , V_69 , F_97 ( V_32 ) ) ;
else
V_96 -> V_161 = F_47 ( V_96 -> V_161 +
F_97 ( V_32 ) ,
V_69 -> V_180 ) ;
}
void F_108 ( struct V_63 * V_64 , struct V_32 * V_32 ,
struct V_89 * V_96 , unsigned long V_39 ,
unsigned V_181 )
{
struct V_68 * V_69 = & V_64 -> V_68 ;
int V_182 = 0 , V_183 = 0 , V_184 = 0 ;
V_55 ;
F_61 ( & V_96 -> V_97 ) ;
F_53 ( V_64 , V_181 ? V_185 : V_186 ) ;
if ( ! F_58 ( V_39 , V_96 -> V_172 , 8 , 8 ) ) {
V_182 = 1 ;
F_53 ( V_64 , V_187 ) ;
} else if ( ! V_181 && V_96 -> V_161 &&
V_39 < V_96 -> V_164 &&
F_58 ( V_39 , V_96 -> V_160 , 0 ,
V_96 -> V_161 ) ) {
V_184 = 1 ;
F_53 ( V_64 , V_188 ) ;
}
if ( V_96 -> V_98 == 2 && ! V_96 -> V_99 ) {
T_2 V_189 ;
V_189 = ( F_109 ( V_32 ) + V_42 - 1 ) >>
V_40 ;
F_32 ( V_123 , L_27 V_133 L_28 , V_189 ,
V_69 -> V_190 , V_69 -> V_180 ) ;
if ( V_189 &&
V_189 <= V_69 -> V_190 ) {
V_96 -> V_160 = 0 ;
V_96 -> V_172 = 0 ;
V_96 -> V_164 = 0 ;
V_96 -> V_161 = F_47 ( V_69 -> V_180 ,
V_69 -> V_190 ) ;
GOTO ( V_191 , 0 ) ;
}
}
if ( V_182 ) {
if ( ! F_103 ( V_96 , V_39 ) ) {
if ( V_96 -> V_124 == 0 &&
V_96 -> V_99 == 0 ) {
F_104 ( V_96 , V_39 ) ;
V_96 -> V_124 ++ ;
} else {
F_99 ( V_96 ) ;
}
F_98 ( V_32 , V_96 , V_39 ) ;
V_96 -> V_173 ++ ;
GOTO ( V_191 , 0 ) ;
} else {
V_96 -> V_173 = 0 ;
V_96 -> V_100 = 0 ;
if ( ++ V_96 -> V_124 > 1 )
V_183 = 1 ;
F_95 ( V_96 ) ;
}
} else {
if ( V_184 ) {
if ( F_103 ( V_96 , V_39 ) &&
F_81 ( V_96 ) ) {
if ( V_39 != V_96 -> V_172 + 1 )
V_96 -> V_173 = 0 ;
F_98 ( V_32 , V_96 , V_39 ) ;
F_95 ( V_96 ) ;
} else {
F_98 ( V_32 , V_96 , V_39 ) ;
V_96 -> V_173 ++ ;
F_99 ( V_96 ) ;
GOTO ( V_191 , 0 ) ;
}
} else if ( F_81 ( V_96 ) ) {
if ( ! F_103 ( V_96 , V_39 ) ) {
F_99 ( V_96 ) ;
V_96 -> V_161 = 0 ;
V_96 -> V_164 = V_39 ;
}
}
}
V_96 -> V_173 ++ ;
V_96 -> V_172 = V_39 ;
F_96 ( V_32 , V_96 , V_39 ) ;
if ( F_81 ( V_96 ) )
V_96 -> V_164 = F_94 ( V_39 , V_96 -> V_164 ) ;
else
V_96 -> V_164 = F_94 ( V_96 -> V_160 ,
V_96 -> V_164 ) ;
F_95 ( V_96 ) ;
if ( ! V_96 -> V_161 && V_96 -> V_173 == 4 ) {
V_96 -> V_161 = F_97 ( V_32 ) ;
GOTO ( V_191 , 0 ) ;
}
if ( V_96 -> V_124 == 2 && V_183 ) {
V_96 -> V_164 = F_94 ( V_39 , V_96 -> V_164 ) ;
V_96 -> V_166 = V_39 ;
V_96 -> V_161 = F_97 ( V_32 ) ;
}
if ( ( V_96 -> V_100 > 1 || V_183 ) &&
! V_96 -> V_99 )
F_107 ( V_32 , V_96 , V_69 ) ;
EXIT ;
V_191:
F_95 ( V_96 ) ;
V_96 -> V_99 ++ ;
F_63 ( & V_96 -> V_97 ) ;
return;
}
int F_110 ( struct V_10 * V_18 , struct V_192 * V_193 )
{
struct V_32 * V_32 = V_18 -> V_26 -> V_27 ;
struct V_153 * V_154 = F_11 ( V_32 ) ;
struct V_3 * V_4 ;
struct V_6 * V_7 ;
struct V_9 * V_10 ;
struct V_20 * V_21 ;
struct V_194 V_195 ;
bool V_196 = false ;
bool V_197 = false ;
int V_25 ;
V_55 ;
F_2 ( F_111 ( V_18 ) ) ;
F_2 ( ! F_112 ( V_18 ) ) ;
F_2 ( F_113 ( V_32 ) != NULL ) ;
V_4 = F_114 ( & V_195 ) ;
if ( F_13 ( V_4 ) )
GOTO ( V_74 , V_25 = F_15 ( V_4 ) ) ;
V_21 = F_11 ( V_32 ) -> V_28 ;
F_2 ( V_21 != NULL ) ;
V_7 = F_23 ( V_4 ) ;
V_7 -> V_198 = V_21 ;
V_7 -> V_199 = 1 ;
V_25 = F_115 ( V_4 , V_7 , V_200 , V_21 ) ;
if ( V_25 == 0 ) {
V_10 = F_30 ( V_4 , V_21 , V_18 -> V_39 ,
V_18 , V_49 ) ;
if ( ! F_13 ( V_10 ) ) {
F_31 ( & V_10 -> V_14 , L_29 ,
V_13 ) ;
F_37 ( V_4 , V_7 , V_10 ) ;
V_25 = F_116 ( V_4 , V_7 , V_10 ) ;
if ( V_25 != 0 ) {
if ( ! F_117 ( V_18 ) ) {
F_118 ( V_193 , V_18 ) ;
V_25 = 0 ;
V_196 = true ;
}
}
F_119 ( V_4 , V_7 , V_10 ) ;
V_197 = true ;
F_3 ( & V_10 -> V_14 ,
L_29 , V_13 ) ;
F_4 ( V_4 , V_10 ) ;
} else {
V_25 = F_15 ( V_10 ) ;
}
}
F_8 ( V_4 , V_7 ) ;
if ( V_196 && V_193 -> V_201 == V_202 ) {
T_1 V_143 = F_120 ( V_21 , V_18 -> V_39 ) ;
V_25 = F_121 ( V_32 , V_143 ,
V_143 + V_42 - 1 ,
V_203 , 1 ) ;
if ( V_25 > 0 ) {
V_193 -> V_204 -= V_25 - 1 ;
V_25 = 0 ;
}
}
F_122 ( & V_195 , V_4 ) ;
GOTO ( V_74 , V_25 ) ;
V_74:
if ( V_25 < 0 ) {
if ( ! V_154 -> V_205 )
V_154 -> V_205 = V_25 ;
F_123 ( V_18 ) ;
if ( ! V_197 )
F_79 ( V_18 ) ;
}
return V_25 ;
}
int F_124 ( struct V_83 * V_26 , struct V_192 * V_193 )
{
struct V_32 * V_32 = V_26 -> V_27 ;
struct V_63 * V_64 = F_57 ( V_32 ) ;
T_1 V_87 ;
T_1 V_88 ;
enum V_206 V_207 ;
int V_208 = 0 ;
int V_25 ;
int V_209 = 0 ;
V_55 ;
if ( V_193 -> V_210 ) {
V_87 = V_26 -> V_211 << V_40 ;
V_88 = V_212 ;
} else {
V_87 = V_193 -> V_213 ;
V_88 = V_193 -> V_214 ;
if ( V_88 == V_215 ) {
V_88 = V_212 ;
V_208 = V_87 == 0 ;
}
}
V_207 = V_216 ;
if ( V_193 -> V_201 == V_202 )
V_207 = V_203 ;
if ( V_64 -> V_217 )
V_209 = 1 ;
V_25 = F_121 ( V_32 , V_87 , V_88 , V_207 , V_209 ) ;
if ( V_25 > 0 ) {
V_193 -> V_204 -= V_25 ;
V_25 = 0 ;
}
if ( V_193 -> V_210 || ( V_208 && V_193 -> V_204 > 0 ) ) {
if ( V_88 == V_212 )
V_88 = F_109 ( V_32 ) ;
V_26 -> V_211 = ( V_88 >> V_40 ) + 1 ;
}
RETURN ( V_25 ) ;
}
int F_125 ( struct V_17 * V_17 , struct V_10 * V_18 )
{
struct V_1 * V_2 ;
int V_25 ;
V_55 ;
V_2 = F_10 ( V_17 , V_18 , 0 ) ;
if ( ! F_13 ( V_2 ) ) {
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 ;
F_2 ( V_10 -> V_218 == V_49 ) ;
if ( F_126 ( ! F_72 ( V_18 ) ) ) {
F_37 ( V_4 , V_7 , V_10 ) ;
V_25 = F_127 ( V_4 , V_7 , V_10 ) ;
} else {
F_79 ( V_18 ) ;
V_25 = 0 ;
}
F_1 ( V_2 ) ;
} else {
F_79 ( V_18 ) ;
V_25 = F_15 ( V_2 ) ;
}
RETURN ( V_25 ) ;
}
