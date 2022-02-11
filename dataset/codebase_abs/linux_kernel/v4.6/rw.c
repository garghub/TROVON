static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 ;
F_2 ( V_2 -> V_12 == V_13 ) ;
F_2 ( V_4 ) ;
if ( V_10 ) {
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
F_2 ( V_20 ) ;
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
if ( ! V_7 && V_18 ) {
struct V_31 * V_31 = V_17 -> V_25 -> V_26 ;
T_1 V_32 ;
if ( F_13 ( V_31 ) ) {
F_14 ( ( V_31 ) ) ;
F_15 ( L_2 ,
V_13 -> V_33 ) ;
F_16 () ;
F_17 () ;
return F_18 ( - V_34 ) ;
}
V_7 = F_19 ( V_4 ) ;
F_20 ( V_7 , V_16 , 1 ) ;
V_7 -> V_35 = V_36 ;
V_32 = V_17 -> V_37 << V_38 ;
V_24 = F_21 ( V_4 , V_7 , V_39 , V_32 , V_40 ) ;
if ( V_24 == 0 ) {
V_22 -> V_41 = F_22 ( V_16 ) ;
V_22 -> V_42 = NULL ;
V_24 = F_23 ( V_4 , V_7 ) ;
if ( V_24 == 0 ) {
V_24 = F_24 ( V_4 , V_7 ) ;
if ( V_24 == 0 )
V_24 = F_25 ( V_4 , V_7 ) ;
}
} else
V_24 = V_7 -> V_43 ;
}
V_2 -> V_8 = V_7 ;
if ( ! V_7 )
V_24 = - V_34 ;
if ( V_24 == 0 ) {
struct V_9 * V_10 ;
F_2 ( V_7 -> V_44 == V_45 ) ;
F_2 ( V_22 -> V_41 == F_22 ( V_16 ) ) ;
V_10 = F_26 ( V_4 , V_20 , V_17 -> V_37 , V_17 ,
V_46 ) ;
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
F_29 ( V_47 , L_3 V_48 L_4 ,
V_17 -> V_37 , F_30 ( F_31 ( & V_20 -> V_49 ) ) , V_24 ,
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
int F_33 ( struct V_16 * V_16 , struct V_10 * V_17 , unsigned V_50 ,
unsigned V_51 )
{
struct V_1 * V_2 ;
int V_24 ;
V_2 = F_6 ( V_16 , V_17 , 1 ) ;
if ( ! F_9 ( V_2 ) ) {
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 ;
F_34 ( V_4 , V_7 , V_10 ) ;
V_24 = F_35 ( V_4 , V_7 , V_10 , V_50 , V_51 ) ;
if ( V_24 == 0 ) {
F_36 ( V_10 ) ;
F_27 ( & V_10 -> V_14 , L_5 ,
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
int F_38 ( struct V_16 * V_16 , struct V_10 * V_17 , unsigned V_50 ,
unsigned V_51 )
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
F_2 ( V_50 <= V_51 ) ;
if ( V_50 != V_51 )
V_24 = F_40 ( V_4 , V_7 , V_10 , V_50 , V_51 ) ;
if ( F_39 ( V_10 , V_7 ) )
F_37 ( V_4 , V_7 , V_10 ) ;
F_3 ( & V_10 -> V_14 , L_5 , V_13 ) ;
F_4 ( V_4 , V_10 ) ;
F_1 ( V_2 ) ;
return V_24 ;
}
static unsigned long F_41 ( struct V_52 * V_53 ,
struct V_54 * V_55 ,
unsigned long V_56 )
{
struct V_57 * V_58 = & V_53 -> V_57 ;
long V_59 ;
V_59 = F_42 ( V_58 -> V_60 - F_43 ( & V_58 -> V_61 ) , V_56 ) ;
if ( V_59 < 0 || V_59 < F_44 ( long , V_62 , V_56 ) ) {
V_59 = 0 ;
goto V_63;
}
if ( V_55 -> V_64 == 0 ) {
long V_65 = ( V_55 -> V_66 + V_59 ) % V_62 ;
if ( V_65 < V_59 )
V_59 -= V_65 ;
}
if ( F_45 ( V_59 , & V_58 -> V_61 ) > V_58 -> V_60 ) {
F_46 ( V_59 , & V_58 -> V_61 ) ;
V_59 = 0 ;
}
V_63:
return V_59 ;
}
void F_47 ( struct V_52 * V_53 , unsigned long V_67 )
{
struct V_57 * V_58 = & V_53 -> V_57 ;
F_46 ( V_67 , & V_58 -> V_61 ) ;
}
static void F_48 ( struct V_52 * V_53 , enum V_68 V_69 )
{
F_49 ( V_69 >= 0 && V_69 < V_70 , L_6 , V_69 ) ;
F_50 ( V_53 -> V_71 , V_69 ) ;
}
void F_51 ( struct V_72 * V_25 , enum V_68 V_69 )
{
struct V_52 * V_53 = F_52 ( V_25 -> V_26 ) ;
F_48 ( V_53 , V_69 ) ;
}
static int F_53 ( unsigned long V_37 , unsigned long V_73 ,
unsigned long V_74 , unsigned long V_75 )
{
unsigned long V_76 = V_73 - V_74 , V_77 = V_73 + V_75 ;
if ( V_76 > V_73 )
V_76 = 0 ;
if ( V_77 < V_73 )
V_77 = ~ 0 ;
return V_76 <= V_37 && V_37 <= V_77 ;
}
static struct V_78 * F_54 ( struct V_16 * V_79 )
{
struct V_80 * V_81 ;
V_81 = F_22 ( V_79 ) ;
return & V_81 -> V_82 ;
}
void F_55 ( struct V_16 * V_79 , struct V_83 * V_84 )
{
struct V_78 * V_85 ;
V_85 = F_54 ( V_79 ) ;
F_56 ( & V_85 -> V_86 ) ;
V_85 -> V_87 ++ ;
V_85 -> V_88 = 0 ;
V_85 -> V_89 ++ ;
V_84 -> V_90 = V_13 ;
F_57 ( & V_84 -> V_91 , & V_85 -> V_92 ) ;
F_58 ( & V_85 -> V_86 ) ;
}
void F_59 ( struct V_16 * V_79 , struct V_83 * V_84 )
{
struct V_78 * V_85 ;
V_85 = F_54 ( V_79 ) ;
F_56 ( & V_85 -> V_86 ) ;
F_60 ( & V_84 -> V_91 ) ;
F_58 ( & V_85 -> V_86 ) ;
}
static int F_61 ( const struct V_3 * V_4 , struct V_6 * V_7 ,
struct V_93 * V_94 , struct V_9 * V_10 ,
struct V_10 * V_17 )
{
struct V_95 * V_96 ;
int V_97 ;
V_97 = 0 ;
F_34 ( V_4 , V_7 , V_10 ) ;
F_27 ( & V_10 -> V_14 , L_7 , V_13 ) ;
V_96 = F_62 ( F_63 ( V_10 , & V_98 ) ) ;
if ( ! V_96 -> V_99 && ! F_64 ( V_17 ) ) {
V_97 = F_65 ( V_4 , V_7 , V_10 ) ;
if ( V_97 == - V_100 ) {
V_96 -> V_99 = 1 ;
V_96 -> V_101 = 0 ;
F_66 ( V_94 , V_10 ) ;
V_97 = 1 ;
} else {
F_67 ( V_4 , V_10 ) ;
V_97 = - V_102 ;
}
} else {
F_37 ( V_4 , V_7 , V_10 ) ;
}
F_3 ( & V_10 -> V_14 , L_7 , V_13 ) ;
F_4 ( V_4 , V_10 ) ;
return V_97 ;
}
static int F_68 ( const struct V_3 * V_4 , struct V_6 * V_7 ,
struct V_93 * V_94 ,
T_2 V_37 , struct V_72 * V_25 )
{
struct V_10 * V_17 ;
struct V_19 * V_20 = F_7 ( V_25 -> V_26 ) -> V_27 ;
struct V_9 * V_10 ;
enum V_68 V_69 = V_70 ;
int V_97 = 0 ;
const char * V_103 = NULL ;
V_17 = F_69 ( V_25 , V_37 ) ;
if ( V_17 ) {
if ( V_17 -> V_25 == V_25 ) {
V_10 = F_26 ( V_4 , V_20 , V_17 -> V_37 ,
V_17 , V_46 ) ;
if ( ! F_9 ( V_10 ) ) {
V_97 = F_61 ( V_4 , V_7 , V_94 ,
V_10 , V_17 ) ;
if ( V_97 == - V_102 ) {
V_69 = V_104 ;
V_103 = L_8 ;
}
} else {
V_69 = V_105 ;
V_103 = L_9 ;
}
} else {
V_69 = V_106 ;
V_103 = L_10 ;
}
if ( V_97 != 1 )
F_70 ( V_17 ) ;
F_71 ( V_17 ) ;
} else {
V_69 = V_105 ;
V_103 = L_11 ;
}
if ( V_103 ) {
F_51 ( V_25 , V_69 ) ;
F_29 ( V_107 , L_12 , V_103 ) ;
}
return V_97 ;
}
static inline int F_72 ( struct V_78 * V_85 )
{
return V_85 -> V_108 > 1 ;
}
static unsigned long
F_73 ( T_2 V_109 , unsigned long V_110 , unsigned long V_111 ,
unsigned long V_112 , unsigned long V_113 )
{
T_3 V_76 = V_112 > V_109 ? V_112 - V_109 : 0 ;
T_3 V_77 = V_112 + V_113 > V_109 ? V_112 + V_113 - V_109 : 0 ;
unsigned long V_114 = 0 ;
unsigned long V_115 = 0 ;
unsigned long V_116 ;
if ( V_110 == 0 || V_113 == 0 || V_77 == 0 )
return V_113 ;
V_114 = F_74 ( V_76 , V_110 ) ;
if ( V_114 < V_111 )
V_114 = V_111 - V_114 ;
else
V_114 = 0 ;
V_115 = F_74 ( V_77 , V_110 ) ;
if ( V_115 > V_111 )
V_115 = V_111 ;
F_29 ( V_107 , L_13 ,
V_76 , V_77 , V_114 , V_115 ) ;
if ( V_76 == V_77 )
V_116 = V_115 - ( V_111 - V_114 ) ;
else
V_116 = V_114 + V_111 * ( V_77 - V_76 - 1 ) + V_115 ;
F_29 ( V_107 , L_14 ,
V_109 , V_110 , V_111 , V_112 , V_113 , V_116 ) ;
return V_116 ;
}
static int F_75 ( struct V_54 * V_55 )
{
T_3 V_113 = V_55 -> V_117 >= V_55 -> V_66 ?
V_55 -> V_117 - V_55 -> V_66 + 1 : 0 ;
return F_73 ( V_55 -> V_118 , V_55 -> V_119 ,
V_55 -> V_64 , V_55 -> V_66 ,
V_113 ) ;
}
static int F_76 ( unsigned long V_120 , struct V_54 * V_55 )
{
return V_55 -> V_119 == 0 || V_55 -> V_119 == V_55 -> V_64 ||
( V_120 >= V_55 -> V_118 && ( V_120 - V_55 -> V_118 ) %
V_55 -> V_119 < V_55 -> V_64 ) ;
}
static int F_77 ( const struct V_3 * V_4 ,
struct V_6 * V_7 , struct V_93 * V_94 ,
struct V_54 * V_55 ,
unsigned long * V_121 ,
struct V_72 * V_25 ,
unsigned long * V_122 )
{
int V_97 , V_123 = 0 , V_124 ;
unsigned long V_125 ;
F_2 ( V_55 ) ;
F_78 ( V_55 ) ;
V_124 = V_55 -> V_119 > V_55 -> V_64 && V_55 -> V_64 > 0 ;
for ( V_125 = V_55 -> V_66 ;
V_125 <= V_55 -> V_117 && * V_121 > 0 ; V_125 ++ ) {
if ( F_76 ( V_125 , V_55 ) ) {
V_97 = F_68 ( V_4 , V_7 , V_94 ,
V_125 , V_25 ) ;
if ( V_97 == 1 ) {
( * V_121 ) -- ;
V_123 ++ ;
} else if ( V_97 == - V_102 )
break;
} else if ( V_124 ) {
T_2 V_126 ;
F_49 ( V_125 > V_55 -> V_118 , L_15 ,
V_125 ,
V_55 -> V_66 , V_55 -> V_117 , V_55 -> V_118 ,
V_55 -> V_119 , V_55 -> V_64 ) ;
V_126 = V_125 - V_55 -> V_118 ;
V_126 = V_126 % ( V_55 -> V_119 ) ;
if ( V_126 > V_55 -> V_64 ) {
V_125 += V_55 -> V_119 - V_126 ;
F_29 ( V_107 , L_16 , V_125 ,
V_55 -> V_119 - V_126 ) ;
continue;
}
}
}
* V_122 = V_125 ;
return V_123 ;
}
int F_79 ( const struct V_3 * V_4 , struct V_6 * V_7 ,
struct V_78 * V_85 , struct V_72 * V_25 ,
struct V_93 * V_94 , int V_127 )
{
struct V_128 * V_129 = F_80 ( V_4 ) ;
struct V_130 * V_131 = F_11 ( V_4 ) ;
struct V_132 * V_133 = F_81 ( V_4 ) ;
unsigned long V_76 = 0 , V_77 = 0 , V_134 ;
unsigned long V_122 , V_67 ;
struct V_31 * V_31 ;
struct V_83 * V_135 ;
struct V_54 * V_55 = & V_131 -> V_136 ;
struct V_137 * V_138 ;
struct V_19 * V_20 ;
int V_59 = 0 ;
T_3 V_139 ;
V_31 = V_25 -> V_26 ;
V_138 = F_7 ( V_31 ) ;
V_20 = V_138 -> V_27 ;
memset ( V_55 , 0 , sizeof( * V_55 ) ) ;
F_82 ( V_20 ) ;
V_59 = F_83 ( V_4 , V_20 , V_133 ) ;
F_84 ( V_20 ) ;
if ( V_59 != 0 )
return V_59 ;
V_139 = V_133 -> V_140 ;
if ( V_139 == 0 ) {
F_51 ( V_25 , V_141 ) ;
return 0 ;
}
F_56 ( & V_85 -> V_86 ) ;
if ( V_129 -> V_142 )
V_135 = & V_129 -> V_143 ;
else
V_135 = NULL ;
if ( V_135 && V_85 -> V_144 + V_85 -> V_145 <
V_135 -> V_146 + V_135 -> V_147 ) {
V_85 -> V_145 = V_135 -> V_146 + V_135 -> V_147 -
V_85 -> V_144 ;
}
if ( V_85 -> V_145 ) {
V_76 = V_85 -> V_148 ;
V_77 = V_85 -> V_144 + V_85 -> V_145 - 1 ;
}
if ( V_77 != 0 ) {
unsigned long V_149 ;
V_149 = ( V_77 + 1 ) & ( ~ ( V_62 - 1 ) ) ;
if ( V_149 > 0 )
V_149 -- ;
if ( V_149 > V_76 )
V_77 = V_149 ;
V_77 = F_42 ( V_77 , ( unsigned long ) ( ( V_139 - 1 ) >> V_38 ) ) ;
V_85 -> V_148 = F_85 ( V_77 , V_77 + 1 ) ;
F_86 ( V_85 ) ;
}
V_55 -> V_66 = V_76 ;
V_55 -> V_117 = V_77 ;
if ( F_72 ( V_85 ) ) {
V_55 -> V_118 = V_85 -> V_150 ;
V_55 -> V_119 = V_85 -> V_151 ;
V_55 -> V_64 = V_85 -> V_152 ;
}
F_58 ( & V_85 -> V_86 ) ;
if ( V_77 == 0 ) {
F_51 ( V_25 , V_153 ) ;
return 0 ;
}
V_67 = F_75 ( V_55 ) ;
if ( V_67 == 0 )
return 0 ;
V_134 = F_41 ( F_52 ( V_31 ) , V_55 , V_67 ) ;
if ( V_134 < V_67 )
F_51 ( V_25 , V_154 ) ;
F_29 ( V_107 , L_17 , V_134 ,
F_43 ( & F_52 ( V_31 ) -> V_57 . V_61 ) ,
F_52 ( V_31 ) -> V_57 . V_60 ) ;
V_59 = F_77 ( V_4 , V_7 , V_94 ,
V_55 , & V_134 , V_25 , & V_122 ) ;
if ( V_134 != 0 )
F_47 ( F_52 ( V_31 ) , V_134 ) ;
if ( V_122 == V_77 + 1 && V_122 == ( V_139 >> V_38 ) )
F_51 ( V_25 , V_155 ) ;
F_29 ( V_107 , L_18 ,
V_122 , V_77 , V_55 -> V_117 ) ;
if ( V_122 != V_77 + 1 ) {
F_56 ( & V_85 -> V_86 ) ;
if ( V_122 < V_85 -> V_148 &&
F_53 ( V_122 , V_85 -> V_144 , 0 ,
V_85 -> V_145 ) ) {
V_85 -> V_148 = V_122 ;
F_86 ( V_85 ) ;
}
F_58 ( & V_85 -> V_86 ) ;
}
return V_59 ;
}
static void F_87 ( struct V_31 * V_31 , struct V_78 * V_85 ,
unsigned long V_37 )
{
V_85 -> V_144 = V_37 & ( ~ ( F_88 ( V_31 ) - 1 ) ) ;
}
static void F_89 ( struct V_31 * V_31 , struct V_78 * V_85 ,
unsigned long V_37 )
{
V_85 -> V_156 = V_37 ;
V_85 -> V_89 = 0 ;
V_85 -> V_157 = 0 ;
V_85 -> V_145 = 0 ;
F_87 ( V_31 , V_85 , V_37 ) ;
V_85 -> V_148 = F_85 ( V_85 -> V_144 , V_37 ) ;
F_86 ( V_85 ) ;
}
static void F_90 ( struct V_78 * V_85 )
{
V_85 -> V_108 = 0 ;
V_85 -> V_151 = 0 ;
V_85 -> V_152 = 0 ;
F_86 ( V_85 ) ;
}
void F_91 ( struct V_31 * V_31 , struct V_78 * V_85 )
{
F_92 ( & V_85 -> V_86 ) ;
F_89 ( V_31 , V_85 , 0 ) ;
V_85 -> V_87 = 0 ;
F_93 ( & V_85 -> V_92 ) ;
}
static int F_94 ( struct V_78 * V_85 ,
unsigned long V_37 )
{
unsigned long V_158 ;
if ( V_85 -> V_151 == 0 || V_85 -> V_152 == 0 ||
V_85 -> V_152 == V_85 -> V_151 )
return 0 ;
V_158 = V_37 - V_85 -> V_156 - 1 ;
if ( V_158 == 0 )
return V_85 -> V_157 + 1 <= V_85 -> V_152 ;
return ( V_85 -> V_151 - V_85 -> V_152 ) == V_158 &&
V_85 -> V_157 == V_85 -> V_152 ;
}
static void F_95 ( struct V_78 * V_85 ,
unsigned long V_37 )
{
unsigned long V_158 = V_37 - V_85 -> V_156 - 1 ;
if ( ! F_72 ( V_85 ) && ( V_158 != 0 ||
V_85 -> V_108 == 0 ) ) {
V_85 -> V_152 = V_85 -> V_157 ;
V_85 -> V_151 = V_158 + V_85 -> V_157 ;
}
F_2 ( V_85 -> V_88 == 0 ) ;
F_2 ( V_85 -> V_108 == 0 ) ;
if ( V_37 <= V_85 -> V_156 ) {
F_90 ( V_85 ) ;
return;
}
V_85 -> V_152 = V_85 -> V_157 ;
V_85 -> V_151 = V_158 + V_85 -> V_157 ;
F_86 ( V_85 ) ;
return;
}
static void F_96 ( struct V_78 * V_85 ,
struct V_57 * V_58 ,
unsigned long V_159 )
{
unsigned long V_160 , V_161 , V_162 ;
unsigned long V_163 ;
F_2 ( V_85 -> V_151 > 0 ) ;
F_49 ( V_85 -> V_144 + V_85 -> V_145
>= V_85 -> V_150 , L_19 ,
V_85 -> V_144 ,
V_85 -> V_145 , V_85 -> V_150 ) ;
V_163 = V_85 -> V_144 + V_85 -> V_145 -
V_85 -> V_150 ;
V_160 = V_163 % V_85 -> V_151 ;
V_162 = V_85 -> V_145 - V_160 ;
if ( V_160 < V_85 -> V_152 )
V_160 += V_159 ;
else
V_160 = V_85 -> V_152 + V_159 ;
F_2 ( V_85 -> V_152 != 0 ) ;
V_161 = V_160 / V_85 -> V_152 ;
V_160 %= V_85 -> V_152 ;
V_162 += V_161 * V_85 -> V_151 + V_160 ;
if ( F_73 ( V_85 -> V_150 , V_85 -> V_151 ,
V_85 -> V_152 , V_85 -> V_150 ,
V_162 ) <= V_58 -> V_164 )
V_85 -> V_145 = V_162 ;
F_86 ( V_85 ) ;
}
static void F_97 ( struct V_31 * V_31 ,
struct V_78 * V_85 ,
struct V_57 * V_58 )
{
if ( F_72 ( V_85 ) )
F_96 ( V_85 , V_58 , F_88 ( V_31 ) ) ;
else
V_85 -> V_145 = F_42 ( V_85 -> V_145 +
F_88 ( V_31 ) ,
V_58 -> V_164 ) ;
}
void F_98 ( struct V_52 * V_53 , struct V_31 * V_31 ,
struct V_78 * V_85 , unsigned long V_37 ,
unsigned V_165 )
{
struct V_57 * V_58 = & V_53 -> V_57 ;
int V_166 = 0 , V_167 = 0 , V_168 = 0 ;
F_56 ( & V_85 -> V_86 ) ;
F_48 ( V_53 , V_165 ? V_169 : V_170 ) ;
if ( ! F_53 ( V_37 , V_85 -> V_156 , 8 , 8 ) ) {
V_166 = 1 ;
F_48 ( V_53 , V_171 ) ;
} else if ( ! V_165 && V_85 -> V_145 &&
V_37 < V_85 -> V_148 &&
F_53 ( V_37 , V_85 -> V_144 , 0 ,
V_85 -> V_145 ) ) {
V_168 = 1 ;
F_48 ( V_53 , V_172 ) ;
}
if ( V_85 -> V_87 == 2 && ! V_85 -> V_88 ) {
T_3 V_173 ;
V_173 = ( F_99 ( V_31 ) + V_40 - 1 ) >>
V_38 ;
F_29 ( V_107 , L_20 , V_173 ,
V_58 -> V_174 , V_58 -> V_164 ) ;
if ( V_173 &&
V_173 <= V_58 -> V_174 ) {
V_85 -> V_144 = 0 ;
V_85 -> V_156 = 0 ;
V_85 -> V_148 = 0 ;
V_85 -> V_145 = F_42 ( V_58 -> V_164 ,
V_58 -> V_174 ) ;
goto V_175;
}
}
if ( V_166 ) {
if ( ! F_94 ( V_85 , V_37 ) ) {
if ( V_85 -> V_108 == 0 &&
V_85 -> V_88 == 0 ) {
F_95 ( V_85 , V_37 ) ;
V_85 -> V_108 ++ ;
} else {
F_90 ( V_85 ) ;
}
F_89 ( V_31 , V_85 , V_37 ) ;
V_85 -> V_157 ++ ;
goto V_175;
} else {
V_85 -> V_157 = 0 ;
V_85 -> V_89 = 0 ;
if ( ++ V_85 -> V_108 > 1 )
V_167 = 1 ;
F_86 ( V_85 ) ;
}
} else {
if ( V_168 ) {
if ( F_94 ( V_85 , V_37 ) &&
F_72 ( V_85 ) ) {
if ( V_37 != V_85 -> V_156 + 1 )
V_85 -> V_157 = 0 ;
F_89 ( V_31 , V_85 , V_37 ) ;
F_86 ( V_85 ) ;
} else {
F_89 ( V_31 , V_85 , V_37 ) ;
V_85 -> V_157 ++ ;
F_90 ( V_85 ) ;
goto V_175;
}
} else if ( F_72 ( V_85 ) ) {
if ( ! F_94 ( V_85 , V_37 ) ) {
F_90 ( V_85 ) ;
V_85 -> V_145 = 0 ;
V_85 -> V_148 = V_37 ;
}
}
}
V_85 -> V_157 ++ ;
V_85 -> V_156 = V_37 ;
F_87 ( V_31 , V_85 , V_37 ) ;
if ( F_72 ( V_85 ) )
V_85 -> V_148 = F_85 ( V_37 , V_85 -> V_148 ) ;
else
V_85 -> V_148 = F_85 ( V_85 -> V_144 ,
V_85 -> V_148 ) ;
F_86 ( V_85 ) ;
if ( ! V_85 -> V_145 && V_85 -> V_157 == 4 ) {
V_85 -> V_145 = F_88 ( V_31 ) ;
goto V_175;
}
if ( V_85 -> V_108 == 2 && V_167 ) {
V_85 -> V_148 = F_85 ( V_37 , V_85 -> V_148 ) ;
V_85 -> V_150 = V_37 ;
V_85 -> V_145 = F_88 ( V_31 ) ;
}
if ( ( V_85 -> V_89 > 1 || V_167 ) &&
! V_85 -> V_88 )
F_97 ( V_31 , V_85 , V_58 ) ;
V_175:
F_86 ( V_85 ) ;
V_85 -> V_88 ++ ;
F_58 ( & V_85 -> V_86 ) ;
return;
}
int F_100 ( struct V_10 * V_17 , struct V_176 * V_177 )
{
struct V_31 * V_31 = V_17 -> V_25 -> V_26 ;
struct V_137 * V_138 = F_7 ( V_31 ) ;
struct V_3 * V_4 ;
struct V_6 * V_7 ;
struct V_9 * V_10 ;
struct V_19 * V_20 ;
struct V_178 V_179 ;
bool V_180 = false ;
bool V_181 = false ;
int V_24 ;
F_2 ( F_101 ( V_17 ) ) ;
F_2 ( ! F_102 ( V_17 ) ) ;
F_2 ( F_103 ( V_31 ) ) ;
V_4 = F_104 ( & V_179 ) ;
if ( F_9 ( V_4 ) ) {
V_24 = F_28 ( V_4 ) ;
goto V_63;
}
V_20 = F_7 ( V_31 ) -> V_27 ;
F_2 ( V_20 ) ;
V_7 = F_19 ( V_4 ) ;
V_7 -> V_182 = V_20 ;
V_7 -> V_183 = 1 ;
V_24 = F_105 ( V_4 , V_7 , V_184 , V_20 ) ;
if ( V_24 == 0 ) {
V_10 = F_26 ( V_4 , V_20 , V_17 -> V_37 ,
V_17 , V_46 ) ;
if ( ! F_9 ( V_10 ) ) {
F_27 ( & V_10 -> V_14 , L_21 ,
V_13 ) ;
F_34 ( V_4 , V_7 , V_10 ) ;
V_24 = F_106 ( V_4 , V_7 , V_10 ) ;
if ( V_24 != 0 ) {
if ( ! F_107 ( V_17 ) ) {
F_108 ( V_177 , V_17 ) ;
V_24 = 0 ;
V_180 = true ;
}
}
F_109 ( V_4 , V_7 , V_10 ) ;
V_181 = true ;
F_3 ( & V_10 -> V_14 ,
L_21 , V_13 ) ;
F_4 ( V_4 , V_10 ) ;
} else {
V_24 = F_28 ( V_10 ) ;
}
}
F_110 ( V_4 , V_7 ) ;
if ( V_180 && V_177 -> V_185 == V_186 ) {
T_1 V_126 = F_111 ( V_20 , V_17 -> V_37 ) ;
V_24 = F_112 ( V_31 , V_126 ,
V_126 + V_40 - 1 ,
V_187 , 1 ) ;
if ( V_24 > 0 ) {
V_177 -> V_188 -= V_24 - 1 ;
V_24 = 0 ;
}
}
F_113 ( & V_179 , V_4 ) ;
goto V_63;
V_63:
if ( V_24 < 0 ) {
if ( ! V_138 -> V_189 )
V_138 -> V_189 = V_24 ;
F_114 ( V_17 ) ;
if ( ! V_181 )
F_70 ( V_17 ) ;
}
return V_24 ;
}
int F_115 ( struct V_72 * V_25 , struct V_176 * V_177 )
{
struct V_31 * V_31 = V_25 -> V_26 ;
struct V_52 * V_53 = F_52 ( V_31 ) ;
T_1 V_76 ;
T_1 V_77 ;
enum V_190 V_191 ;
int V_192 = 0 ;
int V_24 ;
int V_193 = 0 ;
if ( V_177 -> V_194 ) {
V_76 = V_25 -> V_195 << V_38 ;
V_77 = V_196 ;
} else {
V_76 = V_177 -> V_197 ;
V_77 = V_177 -> V_198 ;
if ( V_77 == V_199 ) {
V_77 = V_196 ;
V_192 = V_76 == 0 ;
}
}
V_191 = V_200 ;
if ( V_177 -> V_185 == V_186 )
V_191 = V_187 ;
if ( V_53 -> V_201 )
V_193 = 1 ;
V_24 = F_112 ( V_31 , V_76 , V_77 , V_191 , V_193 ) ;
if ( V_24 > 0 ) {
V_177 -> V_188 -= V_24 ;
V_24 = 0 ;
}
if ( V_177 -> V_194 || ( V_192 && V_177 -> V_188 > 0 ) ) {
if ( V_77 == V_196 )
V_77 = F_99 ( V_31 ) ;
V_25 -> V_195 = ( V_77 >> V_38 ) + 1 ;
}
return V_24 ;
}
int F_116 ( struct V_16 * V_16 , struct V_10 * V_17 )
{
struct V_1 * V_2 ;
int V_24 ;
V_2 = F_6 ( V_16 , V_17 , 0 ) ;
if ( ! F_9 ( V_2 ) ) {
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 ;
F_2 ( V_10 -> V_202 == V_46 ) ;
if ( F_117 ( ! F_64 ( V_17 ) ) ) {
F_34 ( V_4 , V_7 , V_10 ) ;
V_24 = F_118 ( V_4 , V_7 , V_10 ) ;
} else {
F_70 ( V_17 ) ;
V_24 = 0 ;
}
F_1 ( V_2 ) ;
} else {
F_70 ( V_17 ) ;
V_24 = F_28 ( V_2 ) ;
}
return V_24 ;
}
