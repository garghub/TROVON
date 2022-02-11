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
if ( V_67 < 0 || V_67 < F_46 ( long , V_70 , V_64 ) ) {
V_67 = 0 ;
goto V_71;
}
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
int V_107 = 0 ;
const char * V_113 = NULL ;
V_17 = F_74 ( V_25 , V_38 ) ;
if ( V_17 != NULL ) {
if ( V_17 -> V_25 == V_25 ) {
V_10 = F_26 ( V_4 , V_20 , V_17 -> V_38 ,
V_17 , V_47 ) ;
if ( ! F_9 ( V_10 ) ) {
V_107 = F_66 ( V_4 , V_7 , V_104 ,
V_10 , V_17 ) ;
if ( V_107 == - V_112 ) {
V_77 = V_114 ;
V_113 = L_9 ;
}
} else {
V_77 = V_115 ;
V_113 = L_10 ;
}
} else {
V_77 = V_116 ;
V_113 = L_11 ;
}
if ( V_107 != 1 )
F_75 ( V_17 ) ;
F_76 ( V_17 ) ;
} else {
V_77 = V_115 ;
V_113 = L_12 ;
}
if ( V_113 != NULL ) {
F_53 ( V_25 , V_77 ) ;
F_29 ( V_117 , L_13 , V_113 ) ;
}
return V_107 ;
}
static inline int F_77 ( struct V_86 * V_93 )
{
return V_93 -> V_118 > 1 ;
}
static unsigned long
F_78 ( T_3 V_119 , unsigned long V_120 , unsigned long V_121 ,
unsigned long V_122 , unsigned long V_123 )
{
T_2 V_84 = V_122 > V_119 ? V_122 - V_119 : 0 ;
T_2 V_85 = V_122 + V_123 > V_119 ? V_122 + V_123 - V_119 : 0 ;
unsigned long V_124 = 0 ;
unsigned long V_125 = 0 ;
unsigned long V_126 ;
if ( V_120 == 0 || V_123 == 0 || V_85 == 0 )
return V_123 ;
V_124 = F_79 ( V_84 , V_120 ) ;
if ( V_124 < V_121 )
V_124 = V_121 - V_124 ;
else
V_124 = 0 ;
V_125 = F_79 ( V_85 , V_120 ) ;
if ( V_125 > V_121 )
V_125 = V_121 ;
F_29 ( V_117 , L_14 ,
V_84 , V_85 , V_124 , V_125 ) ;
if ( V_84 == V_85 )
V_126 = V_125 - ( V_121 - V_124 ) ;
else
V_126 = V_124 + V_121 * ( V_85 - V_84 - 1 ) + V_125 ;
F_29 ( V_117 , L_15
L_16 , V_119 , V_120 , V_121 , V_122 , V_123 , V_126 ) ;
return V_126 ;
}
static int F_80 ( struct V_62 * V_63 )
{
T_2 V_123 = V_63 -> V_127 >= V_63 -> V_74 ?
V_63 -> V_127 - V_63 -> V_74 + 1 : 0 ;
return F_78 ( V_63 -> V_128 , V_63 -> V_129 ,
V_63 -> V_72 , V_63 -> V_74 ,
V_123 ) ;
}
static int F_81 ( unsigned long V_130 , struct V_62 * V_63 )
{
return V_63 -> V_129 == 0 || V_63 -> V_129 == V_63 -> V_72 ||
( V_130 >= V_63 -> V_128 && ( V_130 - V_63 -> V_128 ) %
V_63 -> V_129 < V_63 -> V_72 ) ;
}
static int F_82 ( const struct V_3 * V_4 ,
struct V_6 * V_7 , struct V_103 * V_104 ,
struct V_62 * V_63 ,
unsigned long * V_131 ,
struct V_80 * V_25 ,
unsigned long * V_132 )
{
int V_107 , V_133 = 0 , V_134 ;
unsigned long V_135 ;
F_2 ( V_63 != NULL ) ;
F_83 ( V_63 ) ;
V_134 = V_63 -> V_129 > V_63 -> V_72 && V_63 -> V_72 > 0 ;
for ( V_135 = V_63 -> V_74 ; V_135 <= V_63 -> V_127 &&
* V_131 > 0 ; V_135 ++ ) {
if ( F_81 ( V_135 , V_63 ) ) {
V_107 = F_73 ( V_4 , V_7 , V_104 ,
V_135 , V_25 ) ;
if ( V_107 == 1 ) {
( * V_131 ) -- ;
V_133 ++ ;
} else if ( V_107 == - V_112 )
break;
} else if ( V_134 ) {
T_3 V_136 ;
F_51 ( V_135 > V_63 -> V_128 , L_17
L_18 , V_135 ,
V_63 -> V_74 , V_63 -> V_127 , V_63 -> V_128 ,
V_63 -> V_129 , V_63 -> V_72 ) ;
V_136 = V_135 - V_63 -> V_128 ;
V_136 = V_136 % ( V_63 -> V_129 ) ;
if ( V_136 > V_63 -> V_72 ) {
V_135 += V_63 -> V_129 - V_136 ;
F_29 ( V_117 , L_19 , V_135 ,
V_63 -> V_129 - V_136 ) ;
continue;
}
}
}
* V_132 = V_135 ;
return V_133 ;
}
int F_84 ( const struct V_3 * V_4 , struct V_6 * V_7 ,
struct V_86 * V_93 , struct V_80 * V_25 ,
struct V_103 * V_104 , int V_137 )
{
struct V_138 * V_139 = F_85 ( V_4 ) ;
struct V_140 * V_141 = F_11 ( V_4 ) ;
struct V_142 * V_143 = F_86 ( V_4 ) ;
unsigned long V_84 = 0 , V_85 = 0 , V_144 ;
unsigned long V_132 , V_75 ;
struct V_31 * V_31 ;
struct V_91 * V_102 ;
struct V_62 * V_63 = & V_141 -> V_145 ;
struct V_146 * V_147 ;
struct V_19 * V_20 ;
int V_67 = 0 ;
T_2 V_148 ;
V_31 = V_25 -> V_26 ;
V_147 = F_7 ( V_31 ) ;
V_20 = V_147 -> V_27 ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
F_87 ( V_20 ) ;
V_67 = F_88 ( V_4 , V_20 , V_143 ) ;
F_89 ( V_20 ) ;
if ( V_67 != 0 )
return V_67 ;
V_148 = V_143 -> V_149 ;
if ( V_148 == 0 ) {
F_53 ( V_25 , V_150 ) ;
return 0 ;
}
F_58 ( & V_93 -> V_94 ) ;
if ( V_139 -> V_151 )
V_102 = & V_139 -> V_152 ;
else
V_102 = NULL ;
if ( V_102 != NULL && V_93 -> V_153 + V_93 -> V_154 <
V_102 -> V_155 + V_102 -> V_156 ) {
V_93 -> V_154 = V_102 -> V_155 + V_102 -> V_156 -
V_93 -> V_153 ;
}
if ( V_93 -> V_154 ) {
V_84 = V_93 -> V_157 ;
V_85 = V_93 -> V_153 + V_93 -> V_154 - 1 ;
}
if ( V_85 != 0 ) {
unsigned long V_158 ;
V_158 = ( ( V_85 + 1 ) & ( ~ ( V_70 - 1 ) ) ) ;
if ( V_158 > 0 )
V_158 -- ;
if ( V_158 > V_84 )
V_85 = V_158 ;
V_85 = F_44 ( V_85 , ( unsigned long ) ( ( V_148 - 1 ) >> V_39 ) ) ;
V_93 -> V_157 = F_90 ( V_85 , V_85 + 1 ) ;
F_91 ( V_93 ) ;
}
V_63 -> V_74 = V_84 ;
V_63 -> V_127 = V_85 ;
if ( F_77 ( V_93 ) ) {
V_63 -> V_128 = V_93 -> V_159 ;
V_63 -> V_129 = V_93 -> V_160 ;
V_63 -> V_72 = V_93 -> V_161 ;
}
F_60 ( & V_93 -> V_94 ) ;
if ( V_85 == 0 ) {
F_53 ( V_25 , V_162 ) ;
return 0 ;
}
V_75 = F_80 ( V_63 ) ;
if ( V_75 == 0 )
return 0 ;
V_144 = F_43 ( F_54 ( V_31 ) , V_63 , V_75 ) ;
if ( V_144 < V_75 )
F_53 ( V_25 , V_163 ) ;
F_29 ( V_117 , L_20 , V_144 ,
F_45 ( & F_54 ( V_31 ) -> V_65 . V_69 ) ,
F_54 ( V_31 ) -> V_65 . V_68 ) ;
V_67 = F_82 ( V_4 , V_7 , V_104 ,
V_63 , & V_144 , V_25 , & V_132 ) ;
F_51 ( V_144 >= 0 , L_21 , V_144 ) ;
if ( V_144 != 0 )
F_49 ( F_54 ( V_31 ) , V_144 ) ;
if ( V_132 == V_85 + 1 && V_132 == ( V_148 >> V_39 ) )
F_53 ( V_25 , V_164 ) ;
F_29 ( V_117 , L_22 ,
V_132 , V_85 , V_63 -> V_127 ) ;
if ( V_132 != V_85 + 1 ) {
F_58 ( & V_93 -> V_94 ) ;
if ( V_132 < V_93 -> V_157 &&
F_55 ( V_132 , V_93 -> V_153 , 0 ,
V_93 -> V_154 ) ) {
V_93 -> V_157 = V_132 ;
F_91 ( V_93 ) ;
}
F_60 ( & V_93 -> V_94 ) ;
}
return V_67 ;
}
static void F_92 ( struct V_31 * V_31 , struct V_86 * V_93 ,
unsigned long V_38 )
{
V_93 -> V_153 = V_38 & ( ~ ( F_93 ( V_31 ) - 1 ) ) ;
}
static void F_94 ( struct V_31 * V_31 , struct V_86 * V_93 ,
unsigned long V_38 )
{
V_93 -> V_165 = V_38 ;
V_93 -> V_97 = 0 ;
V_93 -> V_166 = 0 ;
V_93 -> V_154 = 0 ;
F_92 ( V_31 , V_93 , V_38 ) ;
V_93 -> V_157 = F_90 ( V_93 -> V_153 , V_38 ) ;
F_91 ( V_93 ) ;
}
static void F_95 ( struct V_86 * V_93 )
{
V_93 -> V_118 = 0 ;
V_93 -> V_160 = 0 ;
V_93 -> V_161 = 0 ;
F_91 ( V_93 ) ;
}
void F_96 ( struct V_31 * V_31 , struct V_86 * V_93 )
{
F_97 ( & V_93 -> V_94 ) ;
F_94 ( V_31 , V_93 , 0 ) ;
V_93 -> V_95 = 0 ;
F_98 ( & V_93 -> V_100 ) ;
}
static int F_99 ( struct V_86 * V_93 ,
unsigned long V_38 )
{
unsigned long V_167 ;
if ( V_93 -> V_160 == 0 || V_93 -> V_161 == 0 ||
V_93 -> V_161 == V_93 -> V_160 )
return 0 ;
V_167 = V_38 - V_93 -> V_165 - 1 ;
if ( V_167 == 0 )
return V_93 -> V_166 + 1 <= V_93 -> V_161 ;
return ( V_93 -> V_160 - V_93 -> V_161 ) == V_167 &&
V_93 -> V_166 == V_93 -> V_161 ;
}
static void F_100 ( struct V_86 * V_93 ,
unsigned long V_38 )
{
unsigned long V_167 = V_38 - V_93 -> V_165 - 1 ;
if ( ! F_77 ( V_93 ) && ( V_167 != 0 ||
V_93 -> V_118 == 0 ) ) {
V_93 -> V_161 = V_93 -> V_166 ;
V_93 -> V_160 = V_167 + V_93 -> V_166 ;
}
F_2 ( V_93 -> V_96 == 0 ) ;
F_2 ( V_93 -> V_118 == 0 ) ;
if ( V_38 <= V_93 -> V_165 ) {
F_95 ( V_93 ) ;
return;
}
V_93 -> V_161 = V_93 -> V_166 ;
V_93 -> V_160 = V_167 + V_93 -> V_166 ;
F_91 ( V_93 ) ;
return;
}
static unsigned long
F_101 ( struct V_86 * V_93 , unsigned long V_75 )
{
return F_78 ( V_93 -> V_159 , V_93 -> V_160 ,
V_93 -> V_161 , V_93 -> V_159 ,
V_75 ) ;
}
static void F_102 ( struct V_86 * V_93 ,
struct V_65 * V_66 ,
unsigned long V_168 )
{
unsigned long V_169 , V_170 , V_171 ;
unsigned long V_172 ;
F_2 ( V_93 -> V_160 > 0 ) ;
F_51 ( V_93 -> V_153 + V_93 -> V_154
>= V_93 -> V_159 , L_23
L_24 , V_93 -> V_153 ,
V_93 -> V_154 , V_93 -> V_159 ) ;
V_172 = V_93 -> V_153 + V_93 -> V_154 -
V_93 -> V_159 ;
V_169 = V_172 % V_93 -> V_160 ;
V_171 = V_93 -> V_154 - V_169 ;
if ( V_169 < V_93 -> V_161 )
V_169 += V_168 ;
else
V_169 = V_93 -> V_161 + V_168 ;
F_2 ( V_93 -> V_161 != 0 ) ;
V_170 = V_169 / V_93 -> V_161 ;
V_169 %= V_93 -> V_161 ;
V_171 += V_170 * V_93 -> V_160 + V_169 ;
if ( F_101 ( V_93 , V_171 ) <= V_66 -> V_173 )
V_93 -> V_154 = V_171 ;
F_91 ( V_93 ) ;
}
static void F_103 ( struct V_31 * V_31 ,
struct V_86 * V_93 ,
struct V_65 * V_66 )
{
if ( F_77 ( V_93 ) )
F_102 ( V_93 , V_66 , F_93 ( V_31 ) ) ;
else
V_93 -> V_154 = F_44 ( V_93 -> V_154 +
F_93 ( V_31 ) ,
V_66 -> V_173 ) ;
}
void F_104 ( struct V_60 * V_61 , struct V_31 * V_31 ,
struct V_86 * V_93 , unsigned long V_38 ,
unsigned V_174 )
{
struct V_65 * V_66 = & V_61 -> V_65 ;
int V_175 = 0 , V_176 = 0 , V_177 = 0 ;
F_58 ( & V_93 -> V_94 ) ;
F_50 ( V_61 , V_174 ? V_178 : V_179 ) ;
if ( ! F_55 ( V_38 , V_93 -> V_165 , 8 , 8 ) ) {
V_175 = 1 ;
F_50 ( V_61 , V_180 ) ;
} else if ( ! V_174 && V_93 -> V_154 &&
V_38 < V_93 -> V_157 &&
F_55 ( V_38 , V_93 -> V_153 , 0 ,
V_93 -> V_154 ) ) {
V_177 = 1 ;
F_50 ( V_61 , V_181 ) ;
}
if ( V_93 -> V_95 == 2 && ! V_93 -> V_96 ) {
T_2 V_182 ;
V_182 = ( F_105 ( V_31 ) + V_41 - 1 ) >>
V_39 ;
F_29 ( V_117 , L_25 , V_182 ,
V_66 -> V_183 , V_66 -> V_173 ) ;
if ( V_182 &&
V_182 <= V_66 -> V_183 ) {
V_93 -> V_153 = 0 ;
V_93 -> V_165 = 0 ;
V_93 -> V_157 = 0 ;
V_93 -> V_154 = F_44 ( V_66 -> V_173 ,
V_66 -> V_183 ) ;
goto V_184;
}
}
if ( V_175 ) {
if ( ! F_99 ( V_93 , V_38 ) ) {
if ( V_93 -> V_118 == 0 &&
V_93 -> V_96 == 0 ) {
F_100 ( V_93 , V_38 ) ;
V_93 -> V_118 ++ ;
} else {
F_95 ( V_93 ) ;
}
F_94 ( V_31 , V_93 , V_38 ) ;
V_93 -> V_166 ++ ;
goto V_184;
} else {
V_93 -> V_166 = 0 ;
V_93 -> V_97 = 0 ;
if ( ++ V_93 -> V_118 > 1 )
V_176 = 1 ;
F_91 ( V_93 ) ;
}
} else {
if ( V_177 ) {
if ( F_99 ( V_93 , V_38 ) &&
F_77 ( V_93 ) ) {
if ( V_38 != V_93 -> V_165 + 1 )
V_93 -> V_166 = 0 ;
F_94 ( V_31 , V_93 , V_38 ) ;
F_91 ( V_93 ) ;
} else {
F_94 ( V_31 , V_93 , V_38 ) ;
V_93 -> V_166 ++ ;
F_95 ( V_93 ) ;
goto V_184;
}
} else if ( F_77 ( V_93 ) ) {
if ( ! F_99 ( V_93 , V_38 ) ) {
F_95 ( V_93 ) ;
V_93 -> V_154 = 0 ;
V_93 -> V_157 = V_38 ;
}
}
}
V_93 -> V_166 ++ ;
V_93 -> V_165 = V_38 ;
F_92 ( V_31 , V_93 , V_38 ) ;
if ( F_77 ( V_93 ) )
V_93 -> V_157 = F_90 ( V_38 , V_93 -> V_157 ) ;
else
V_93 -> V_157 = F_90 ( V_93 -> V_153 ,
V_93 -> V_157 ) ;
F_91 ( V_93 ) ;
if ( ! V_93 -> V_154 && V_93 -> V_166 == 4 ) {
V_93 -> V_154 = F_93 ( V_31 ) ;
goto V_184;
}
if ( V_93 -> V_118 == 2 && V_176 ) {
V_93 -> V_157 = F_90 ( V_38 , V_93 -> V_157 ) ;
V_93 -> V_159 = V_38 ;
V_93 -> V_154 = F_93 ( V_31 ) ;
}
if ( ( V_93 -> V_97 > 1 || V_176 ) &&
! V_93 -> V_96 )
F_103 ( V_31 , V_93 , V_66 ) ;
V_184:
F_91 ( V_93 ) ;
V_93 -> V_96 ++ ;
F_60 ( & V_93 -> V_94 ) ;
return;
}
int F_106 ( struct V_10 * V_17 , struct V_185 * V_186 )
{
struct V_31 * V_31 = V_17 -> V_25 -> V_26 ;
struct V_146 * V_147 = F_7 ( V_31 ) ;
struct V_3 * V_4 ;
struct V_6 * V_7 ;
struct V_9 * V_10 ;
struct V_19 * V_20 ;
struct V_187 V_188 ;
bool V_189 = false ;
bool V_190 = false ;
int V_24 ;
F_2 ( F_107 ( V_17 ) ) ;
F_2 ( ! F_108 ( V_17 ) ) ;
F_2 ( F_109 ( V_31 ) != NULL ) ;
V_4 = F_110 ( & V_188 ) ;
if ( F_9 ( V_4 ) ) {
V_24 = F_28 ( V_4 ) ;
goto V_71;
}
V_20 = F_7 ( V_31 ) -> V_27 ;
F_2 ( V_20 != NULL ) ;
V_7 = F_19 ( V_4 ) ;
V_7 -> V_191 = V_20 ;
V_7 -> V_192 = 1 ;
V_24 = F_111 ( V_4 , V_7 , V_193 , V_20 ) ;
if ( V_24 == 0 ) {
V_10 = F_26 ( V_4 , V_20 , V_17 -> V_38 ,
V_17 , V_47 ) ;
if ( ! F_9 ( V_10 ) ) {
F_27 ( & V_10 -> V_14 , L_26 ,
V_13 ) ;
F_34 ( V_4 , V_7 , V_10 ) ;
V_24 = F_112 ( V_4 , V_7 , V_10 ) ;
if ( V_24 != 0 ) {
if ( ! F_113 ( V_17 ) ) {
F_114 ( V_186 , V_17 ) ;
V_24 = 0 ;
V_189 = true ;
}
}
F_115 ( V_4 , V_7 , V_10 ) ;
V_190 = true ;
F_3 ( & V_10 -> V_14 ,
L_26 , V_13 ) ;
F_4 ( V_4 , V_10 ) ;
} else {
V_24 = F_28 ( V_10 ) ;
}
}
F_116 ( V_4 , V_7 ) ;
if ( V_189 && V_186 -> V_194 == V_195 ) {
T_1 V_136 = F_117 ( V_20 , V_17 -> V_38 ) ;
V_24 = F_118 ( V_31 , V_136 ,
V_136 + V_41 - 1 ,
V_196 , 1 ) ;
if ( V_24 > 0 ) {
V_186 -> V_197 -= V_24 - 1 ;
V_24 = 0 ;
}
}
F_119 ( & V_188 , V_4 ) ;
goto V_71;
V_71:
if ( V_24 < 0 ) {
if ( ! V_147 -> V_198 )
V_147 -> V_198 = V_24 ;
F_120 ( V_17 ) ;
if ( ! V_190 )
F_75 ( V_17 ) ;
}
return V_24 ;
}
int F_121 ( struct V_80 * V_25 , struct V_185 * V_186 )
{
struct V_31 * V_31 = V_25 -> V_26 ;
struct V_60 * V_61 = F_54 ( V_31 ) ;
T_1 V_84 ;
T_1 V_85 ;
enum V_199 V_200 ;
int V_201 = 0 ;
int V_24 ;
int V_202 = 0 ;
if ( V_186 -> V_203 ) {
V_84 = V_25 -> V_204 << V_39 ;
V_85 = V_205 ;
} else {
V_84 = V_186 -> V_206 ;
V_85 = V_186 -> V_207 ;
if ( V_85 == V_208 ) {
V_85 = V_205 ;
V_201 = V_84 == 0 ;
}
}
V_200 = V_209 ;
if ( V_186 -> V_194 == V_195 )
V_200 = V_196 ;
if ( V_61 -> V_210 )
V_202 = 1 ;
V_24 = F_118 ( V_31 , V_84 , V_85 , V_200 , V_202 ) ;
if ( V_24 > 0 ) {
V_186 -> V_197 -= V_24 ;
V_24 = 0 ;
}
if ( V_186 -> V_203 || ( V_201 && V_186 -> V_197 > 0 ) ) {
if ( V_85 == V_205 )
V_85 = F_105 ( V_31 ) ;
V_25 -> V_204 = ( V_85 >> V_39 ) + 1 ;
}
return V_24 ;
}
int F_122 ( struct V_16 * V_16 , struct V_10 * V_17 )
{
struct V_1 * V_2 ;
int V_24 ;
V_2 = F_6 ( V_16 , V_17 , 0 ) ;
if ( ! F_9 ( V_2 ) ) {
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 ;
F_2 ( V_10 -> V_211 == V_47 ) ;
if ( F_123 ( ! F_69 ( V_17 ) ) ) {
F_34 ( V_4 , V_7 , V_10 ) ;
V_24 = F_124 ( V_4 , V_7 , V_10 ) ;
} else {
F_75 ( V_17 ) ;
V_24 = 0 ;
}
F_1 ( V_2 ) ;
} else {
F_75 ( V_17 ) ;
V_24 = F_28 ( V_2 ) ;
}
return V_24 ;
}
