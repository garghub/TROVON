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
F_15 ( L_2 ,
V_13 -> V_34 ) ;
F_16 () ;
F_17 () ;
return F_18 ( - V_35 ) ;
}
V_7 = F_19 ( V_4 ) ;
F_20 ( V_7 , V_16 , 1 ) ;
V_7 -> V_36 = V_37 ;
V_32 = V_17 -> V_38 << V_39 ;
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
F_29 ( V_48 , L_3 V_49 L_4 ,
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
F_3 ( & V_10 -> V_14 , L_5 , V_13 ) ;
F_4 ( V_4 , V_10 ) ;
F_1 ( V_2 ) ;
return V_24 ;
}
static unsigned long F_41 ( struct V_53 * V_54 ,
struct V_55 * V_56 ,
unsigned long V_57 )
{
struct V_58 * V_59 = & V_54 -> V_58 ;
long V_60 ;
V_60 = F_42 ( V_59 -> V_61 - F_43 ( & V_59 -> V_62 ) , V_57 ) ;
if ( V_60 < 0 || V_60 < F_44 ( long , V_63 , V_57 ) ) {
V_60 = 0 ;
goto V_64;
}
if ( V_56 -> V_65 == 0 ) {
long V_66 = ( V_56 -> V_67 + V_60 ) % V_63 ;
if ( V_66 < V_60 )
V_60 -= V_66 ;
}
if ( F_45 ( V_60 , & V_59 -> V_62 ) > V_59 -> V_61 ) {
F_46 ( V_60 , & V_59 -> V_62 ) ;
V_60 = 0 ;
}
V_64:
return V_60 ;
}
void F_47 ( struct V_53 * V_54 , unsigned long V_68 )
{
struct V_58 * V_59 = & V_54 -> V_58 ;
F_46 ( V_68 , & V_59 -> V_62 ) ;
}
static void F_48 ( struct V_53 * V_54 , enum V_69 V_70 )
{
F_49 ( V_70 >= 0 && V_70 < V_71 , L_6 , V_70 ) ;
F_50 ( V_54 -> V_72 , V_70 ) ;
}
void F_51 ( struct V_73 * V_25 , enum V_69 V_70 )
{
struct V_53 * V_54 = F_52 ( V_25 -> V_26 ) ;
F_48 ( V_54 , V_70 ) ;
}
static int F_53 ( unsigned long V_38 , unsigned long V_74 ,
unsigned long V_75 , unsigned long V_76 )
{
unsigned long V_77 = V_74 - V_75 , V_78 = V_74 + V_76 ;
if ( V_77 > V_74 )
V_77 = 0 ;
if ( V_78 < V_74 )
V_78 = ~ 0 ;
return V_77 <= V_38 && V_38 <= V_78 ;
}
static struct V_79 * F_54 ( struct V_16 * V_80 )
{
struct V_81 * V_82 ;
V_82 = F_22 ( V_80 ) ;
return & V_82 -> V_83 ;
}
void F_55 ( struct V_16 * V_80 , struct V_84 * V_85 )
{
struct V_79 * V_86 ;
V_86 = F_54 ( V_80 ) ;
F_56 ( & V_86 -> V_87 ) ;
V_86 -> V_88 ++ ;
V_86 -> V_89 = 0 ;
V_86 -> V_90 ++ ;
V_85 -> V_91 = V_13 ;
F_57 ( & V_85 -> V_92 , & V_86 -> V_93 ) ;
F_58 ( & V_86 -> V_87 ) ;
}
void F_59 ( struct V_16 * V_80 , struct V_84 * V_85 )
{
struct V_79 * V_86 ;
V_86 = F_54 ( V_80 ) ;
F_56 ( & V_86 -> V_87 ) ;
F_60 ( & V_85 -> V_92 ) ;
F_58 ( & V_86 -> V_87 ) ;
}
static int F_61 ( const struct V_3 * V_4 , struct V_6 * V_7 ,
struct V_94 * V_95 , struct V_9 * V_10 ,
struct V_10 * V_17 )
{
struct V_96 * V_97 ;
int V_98 ;
V_98 = 0 ;
F_34 ( V_4 , V_7 , V_10 ) ;
F_27 ( & V_10 -> V_14 , L_7 , V_13 ) ;
V_97 = F_62 ( F_63 ( V_10 , & V_99 ) ) ;
if ( ! V_97 -> V_100 && ! F_64 ( V_17 ) ) {
V_98 = F_65 ( V_4 , V_7 , V_10 ) ;
if ( V_98 == - V_101 ) {
V_97 -> V_100 = 1 ;
V_97 -> V_102 = 0 ;
F_66 ( V_95 , V_10 ) ;
V_98 = 1 ;
} else {
F_67 ( V_4 , V_10 ) ;
V_98 = - V_103 ;
}
} else {
F_37 ( V_4 , V_7 , V_10 ) ;
}
F_3 ( & V_10 -> V_14 , L_7 , V_13 ) ;
F_4 ( V_4 , V_10 ) ;
return V_98 ;
}
static int F_68 ( const struct V_3 * V_4 , struct V_6 * V_7 ,
struct V_94 * V_95 ,
T_2 V_38 , struct V_73 * V_25 )
{
struct V_10 * V_17 ;
struct V_19 * V_20 = F_7 ( V_25 -> V_26 ) -> V_27 ;
struct V_9 * V_10 ;
enum V_69 V_70 = V_71 ;
int V_98 = 0 ;
const char * V_104 = NULL ;
V_17 = F_69 ( V_25 , V_38 ) ;
if ( V_17 != NULL ) {
if ( V_17 -> V_25 == V_25 ) {
V_10 = F_26 ( V_4 , V_20 , V_17 -> V_38 ,
V_17 , V_47 ) ;
if ( ! F_9 ( V_10 ) ) {
V_98 = F_61 ( V_4 , V_7 , V_95 ,
V_10 , V_17 ) ;
if ( V_98 == - V_103 ) {
V_70 = V_105 ;
V_104 = L_8 ;
}
} else {
V_70 = V_106 ;
V_104 = L_9 ;
}
} else {
V_70 = V_107 ;
V_104 = L_10 ;
}
if ( V_98 != 1 )
F_70 ( V_17 ) ;
F_71 ( V_17 ) ;
} else {
V_70 = V_106 ;
V_104 = L_11 ;
}
if ( V_104 != NULL ) {
F_51 ( V_25 , V_70 ) ;
F_29 ( V_108 , L_12 , V_104 ) ;
}
return V_98 ;
}
static inline int F_72 ( struct V_79 * V_86 )
{
return V_86 -> V_109 > 1 ;
}
static unsigned long
F_73 ( T_2 V_110 , unsigned long V_111 , unsigned long V_112 ,
unsigned long V_113 , unsigned long V_114 )
{
T_3 V_77 = V_113 > V_110 ? V_113 - V_110 : 0 ;
T_3 V_78 = V_113 + V_114 > V_110 ? V_113 + V_114 - V_110 : 0 ;
unsigned long V_115 = 0 ;
unsigned long V_116 = 0 ;
unsigned long V_117 ;
if ( V_111 == 0 || V_114 == 0 || V_78 == 0 )
return V_114 ;
V_115 = F_74 ( V_77 , V_111 ) ;
if ( V_115 < V_112 )
V_115 = V_112 - V_115 ;
else
V_115 = 0 ;
V_116 = F_74 ( V_78 , V_111 ) ;
if ( V_116 > V_112 )
V_116 = V_112 ;
F_29 ( V_108 , L_13 ,
V_77 , V_78 , V_115 , V_116 ) ;
if ( V_77 == V_78 )
V_117 = V_116 - ( V_112 - V_115 ) ;
else
V_117 = V_115 + V_112 * ( V_78 - V_77 - 1 ) + V_116 ;
F_29 ( V_108 , L_14 ,
V_110 , V_111 , V_112 , V_113 , V_114 , V_117 ) ;
return V_117 ;
}
static int F_75 ( struct V_55 * V_56 )
{
T_3 V_114 = V_56 -> V_118 >= V_56 -> V_67 ?
V_56 -> V_118 - V_56 -> V_67 + 1 : 0 ;
return F_73 ( V_56 -> V_119 , V_56 -> V_120 ,
V_56 -> V_65 , V_56 -> V_67 ,
V_114 ) ;
}
static int F_76 ( unsigned long V_121 , struct V_55 * V_56 )
{
return V_56 -> V_120 == 0 || V_56 -> V_120 == V_56 -> V_65 ||
( V_121 >= V_56 -> V_119 && ( V_121 - V_56 -> V_119 ) %
V_56 -> V_120 < V_56 -> V_65 ) ;
}
static int F_77 ( const struct V_3 * V_4 ,
struct V_6 * V_7 , struct V_94 * V_95 ,
struct V_55 * V_56 ,
unsigned long * V_122 ,
struct V_73 * V_25 ,
unsigned long * V_123 )
{
int V_98 , V_124 = 0 , V_125 ;
unsigned long V_126 ;
F_2 ( V_56 != NULL ) ;
F_78 ( V_56 ) ;
V_125 = V_56 -> V_120 > V_56 -> V_65 && V_56 -> V_65 > 0 ;
for ( V_126 = V_56 -> V_67 ; V_126 <= V_56 -> V_118 &&
* V_122 > 0 ; V_126 ++ ) {
if ( F_76 ( V_126 , V_56 ) ) {
V_98 = F_68 ( V_4 , V_7 , V_95 ,
V_126 , V_25 ) ;
if ( V_98 == 1 ) {
( * V_122 ) -- ;
V_124 ++ ;
} else if ( V_98 == - V_103 )
break;
} else if ( V_125 ) {
T_2 V_127 ;
F_49 ( V_126 > V_56 -> V_119 , L_15 ,
V_126 ,
V_56 -> V_67 , V_56 -> V_118 , V_56 -> V_119 ,
V_56 -> V_120 , V_56 -> V_65 ) ;
V_127 = V_126 - V_56 -> V_119 ;
V_127 = V_127 % ( V_56 -> V_120 ) ;
if ( V_127 > V_56 -> V_65 ) {
V_126 += V_56 -> V_120 - V_127 ;
F_29 ( V_108 , L_16 , V_126 ,
V_56 -> V_120 - V_127 ) ;
continue;
}
}
}
* V_123 = V_126 ;
return V_124 ;
}
int F_79 ( const struct V_3 * V_4 , struct V_6 * V_7 ,
struct V_79 * V_86 , struct V_73 * V_25 ,
struct V_94 * V_95 , int V_128 )
{
struct V_129 * V_130 = F_80 ( V_4 ) ;
struct V_131 * V_132 = F_11 ( V_4 ) ;
struct V_133 * V_134 = F_81 ( V_4 ) ;
unsigned long V_77 = 0 , V_78 = 0 , V_135 ;
unsigned long V_123 , V_68 ;
struct V_31 * V_31 ;
struct V_84 * V_136 ;
struct V_55 * V_56 = & V_132 -> V_137 ;
struct V_138 * V_139 ;
struct V_19 * V_20 ;
int V_60 = 0 ;
T_3 V_140 ;
V_31 = V_25 -> V_26 ;
V_139 = F_7 ( V_31 ) ;
V_20 = V_139 -> V_27 ;
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
F_82 ( V_20 ) ;
V_60 = F_83 ( V_4 , V_20 , V_134 ) ;
F_84 ( V_20 ) ;
if ( V_60 != 0 )
return V_60 ;
V_140 = V_134 -> V_141 ;
if ( V_140 == 0 ) {
F_51 ( V_25 , V_142 ) ;
return 0 ;
}
F_56 ( & V_86 -> V_87 ) ;
if ( V_130 -> V_143 )
V_136 = & V_130 -> V_144 ;
else
V_136 = NULL ;
if ( V_136 != NULL && V_86 -> V_145 + V_86 -> V_146 <
V_136 -> V_147 + V_136 -> V_148 ) {
V_86 -> V_146 = V_136 -> V_147 + V_136 -> V_148 -
V_86 -> V_145 ;
}
if ( V_86 -> V_146 ) {
V_77 = V_86 -> V_149 ;
V_78 = V_86 -> V_145 + V_86 -> V_146 - 1 ;
}
if ( V_78 != 0 ) {
unsigned long V_150 ;
V_150 = ( V_78 + 1 ) & ( ~ ( V_63 - 1 ) ) ;
if ( V_150 > 0 )
V_150 -- ;
if ( V_150 > V_77 )
V_78 = V_150 ;
V_78 = F_42 ( V_78 , ( unsigned long ) ( ( V_140 - 1 ) >> V_39 ) ) ;
V_86 -> V_149 = F_85 ( V_78 , V_78 + 1 ) ;
F_86 ( V_86 ) ;
}
V_56 -> V_67 = V_77 ;
V_56 -> V_118 = V_78 ;
if ( F_72 ( V_86 ) ) {
V_56 -> V_119 = V_86 -> V_151 ;
V_56 -> V_120 = V_86 -> V_152 ;
V_56 -> V_65 = V_86 -> V_153 ;
}
F_58 ( & V_86 -> V_87 ) ;
if ( V_78 == 0 ) {
F_51 ( V_25 , V_154 ) ;
return 0 ;
}
V_68 = F_75 ( V_56 ) ;
if ( V_68 == 0 )
return 0 ;
V_135 = F_41 ( F_52 ( V_31 ) , V_56 , V_68 ) ;
if ( V_135 < V_68 )
F_51 ( V_25 , V_155 ) ;
F_29 ( V_108 , L_17 , V_135 ,
F_43 ( & F_52 ( V_31 ) -> V_58 . V_62 ) ,
F_52 ( V_31 ) -> V_58 . V_61 ) ;
V_60 = F_77 ( V_4 , V_7 , V_95 ,
V_56 , & V_135 , V_25 , & V_123 ) ;
F_49 ( V_135 >= 0 , L_18 , V_135 ) ;
if ( V_135 != 0 )
F_47 ( F_52 ( V_31 ) , V_135 ) ;
if ( V_123 == V_78 + 1 && V_123 == ( V_140 >> V_39 ) )
F_51 ( V_25 , V_156 ) ;
F_29 ( V_108 , L_19 ,
V_123 , V_78 , V_56 -> V_118 ) ;
if ( V_123 != V_78 + 1 ) {
F_56 ( & V_86 -> V_87 ) ;
if ( V_123 < V_86 -> V_149 &&
F_53 ( V_123 , V_86 -> V_145 , 0 ,
V_86 -> V_146 ) ) {
V_86 -> V_149 = V_123 ;
F_86 ( V_86 ) ;
}
F_58 ( & V_86 -> V_87 ) ;
}
return V_60 ;
}
static void F_87 ( struct V_31 * V_31 , struct V_79 * V_86 ,
unsigned long V_38 )
{
V_86 -> V_145 = V_38 & ( ~ ( F_88 ( V_31 ) - 1 ) ) ;
}
static void F_89 ( struct V_31 * V_31 , struct V_79 * V_86 ,
unsigned long V_38 )
{
V_86 -> V_157 = V_38 ;
V_86 -> V_90 = 0 ;
V_86 -> V_158 = 0 ;
V_86 -> V_146 = 0 ;
F_87 ( V_31 , V_86 , V_38 ) ;
V_86 -> V_149 = F_85 ( V_86 -> V_145 , V_38 ) ;
F_86 ( V_86 ) ;
}
static void F_90 ( struct V_79 * V_86 )
{
V_86 -> V_109 = 0 ;
V_86 -> V_152 = 0 ;
V_86 -> V_153 = 0 ;
F_86 ( V_86 ) ;
}
void F_91 ( struct V_31 * V_31 , struct V_79 * V_86 )
{
F_92 ( & V_86 -> V_87 ) ;
F_89 ( V_31 , V_86 , 0 ) ;
V_86 -> V_88 = 0 ;
F_93 ( & V_86 -> V_93 ) ;
}
static int F_94 ( struct V_79 * V_86 ,
unsigned long V_38 )
{
unsigned long V_159 ;
if ( V_86 -> V_152 == 0 || V_86 -> V_153 == 0 ||
V_86 -> V_153 == V_86 -> V_152 )
return 0 ;
V_159 = V_38 - V_86 -> V_157 - 1 ;
if ( V_159 == 0 )
return V_86 -> V_158 + 1 <= V_86 -> V_153 ;
return ( V_86 -> V_152 - V_86 -> V_153 ) == V_159 &&
V_86 -> V_158 == V_86 -> V_153 ;
}
static void F_95 ( struct V_79 * V_86 ,
unsigned long V_38 )
{
unsigned long V_159 = V_38 - V_86 -> V_157 - 1 ;
if ( ! F_72 ( V_86 ) && ( V_159 != 0 ||
V_86 -> V_109 == 0 ) ) {
V_86 -> V_153 = V_86 -> V_158 ;
V_86 -> V_152 = V_159 + V_86 -> V_158 ;
}
F_2 ( V_86 -> V_89 == 0 ) ;
F_2 ( V_86 -> V_109 == 0 ) ;
if ( V_38 <= V_86 -> V_157 ) {
F_90 ( V_86 ) ;
return;
}
V_86 -> V_153 = V_86 -> V_158 ;
V_86 -> V_152 = V_159 + V_86 -> V_158 ;
F_86 ( V_86 ) ;
return;
}
static unsigned long
F_96 ( struct V_79 * V_86 , unsigned long V_68 )
{
return F_73 ( V_86 -> V_151 , V_86 -> V_152 ,
V_86 -> V_153 , V_86 -> V_151 ,
V_68 ) ;
}
static void F_97 ( struct V_79 * V_86 ,
struct V_58 * V_59 ,
unsigned long V_160 )
{
unsigned long V_161 , V_162 , V_163 ;
unsigned long V_164 ;
F_2 ( V_86 -> V_152 > 0 ) ;
F_49 ( V_86 -> V_145 + V_86 -> V_146
>= V_86 -> V_151 , L_20 ,
V_86 -> V_145 ,
V_86 -> V_146 , V_86 -> V_151 ) ;
V_164 = V_86 -> V_145 + V_86 -> V_146 -
V_86 -> V_151 ;
V_161 = V_164 % V_86 -> V_152 ;
V_163 = V_86 -> V_146 - V_161 ;
if ( V_161 < V_86 -> V_153 )
V_161 += V_160 ;
else
V_161 = V_86 -> V_153 + V_160 ;
F_2 ( V_86 -> V_153 != 0 ) ;
V_162 = V_161 / V_86 -> V_153 ;
V_161 %= V_86 -> V_153 ;
V_163 += V_162 * V_86 -> V_152 + V_161 ;
if ( F_96 ( V_86 , V_163 ) <= V_59 -> V_165 )
V_86 -> V_146 = V_163 ;
F_86 ( V_86 ) ;
}
static void F_98 ( struct V_31 * V_31 ,
struct V_79 * V_86 ,
struct V_58 * V_59 )
{
if ( F_72 ( V_86 ) )
F_97 ( V_86 , V_59 , F_88 ( V_31 ) ) ;
else
V_86 -> V_146 = F_42 ( V_86 -> V_146 +
F_88 ( V_31 ) ,
V_59 -> V_165 ) ;
}
void F_99 ( struct V_53 * V_54 , struct V_31 * V_31 ,
struct V_79 * V_86 , unsigned long V_38 ,
unsigned V_166 )
{
struct V_58 * V_59 = & V_54 -> V_58 ;
int V_167 = 0 , V_168 = 0 , V_169 = 0 ;
F_56 ( & V_86 -> V_87 ) ;
F_48 ( V_54 , V_166 ? V_170 : V_171 ) ;
if ( ! F_53 ( V_38 , V_86 -> V_157 , 8 , 8 ) ) {
V_167 = 1 ;
F_48 ( V_54 , V_172 ) ;
} else if ( ! V_166 && V_86 -> V_146 &&
V_38 < V_86 -> V_149 &&
F_53 ( V_38 , V_86 -> V_145 , 0 ,
V_86 -> V_146 ) ) {
V_169 = 1 ;
F_48 ( V_54 , V_173 ) ;
}
if ( V_86 -> V_88 == 2 && ! V_86 -> V_89 ) {
T_3 V_174 ;
V_174 = ( F_100 ( V_31 ) + V_41 - 1 ) >>
V_39 ;
F_29 ( V_108 , L_21 , V_174 ,
V_59 -> V_175 , V_59 -> V_165 ) ;
if ( V_174 &&
V_174 <= V_59 -> V_175 ) {
V_86 -> V_145 = 0 ;
V_86 -> V_157 = 0 ;
V_86 -> V_149 = 0 ;
V_86 -> V_146 = F_42 ( V_59 -> V_165 ,
V_59 -> V_175 ) ;
goto V_176;
}
}
if ( V_167 ) {
if ( ! F_94 ( V_86 , V_38 ) ) {
if ( V_86 -> V_109 == 0 &&
V_86 -> V_89 == 0 ) {
F_95 ( V_86 , V_38 ) ;
V_86 -> V_109 ++ ;
} else {
F_90 ( V_86 ) ;
}
F_89 ( V_31 , V_86 , V_38 ) ;
V_86 -> V_158 ++ ;
goto V_176;
} else {
V_86 -> V_158 = 0 ;
V_86 -> V_90 = 0 ;
if ( ++ V_86 -> V_109 > 1 )
V_168 = 1 ;
F_86 ( V_86 ) ;
}
} else {
if ( V_169 ) {
if ( F_94 ( V_86 , V_38 ) &&
F_72 ( V_86 ) ) {
if ( V_38 != V_86 -> V_157 + 1 )
V_86 -> V_158 = 0 ;
F_89 ( V_31 , V_86 , V_38 ) ;
F_86 ( V_86 ) ;
} else {
F_89 ( V_31 , V_86 , V_38 ) ;
V_86 -> V_158 ++ ;
F_90 ( V_86 ) ;
goto V_176;
}
} else if ( F_72 ( V_86 ) ) {
if ( ! F_94 ( V_86 , V_38 ) ) {
F_90 ( V_86 ) ;
V_86 -> V_146 = 0 ;
V_86 -> V_149 = V_38 ;
}
}
}
V_86 -> V_158 ++ ;
V_86 -> V_157 = V_38 ;
F_87 ( V_31 , V_86 , V_38 ) ;
if ( F_72 ( V_86 ) )
V_86 -> V_149 = F_85 ( V_38 , V_86 -> V_149 ) ;
else
V_86 -> V_149 = F_85 ( V_86 -> V_145 ,
V_86 -> V_149 ) ;
F_86 ( V_86 ) ;
if ( ! V_86 -> V_146 && V_86 -> V_158 == 4 ) {
V_86 -> V_146 = F_88 ( V_31 ) ;
goto V_176;
}
if ( V_86 -> V_109 == 2 && V_168 ) {
V_86 -> V_149 = F_85 ( V_38 , V_86 -> V_149 ) ;
V_86 -> V_151 = V_38 ;
V_86 -> V_146 = F_88 ( V_31 ) ;
}
if ( ( V_86 -> V_90 > 1 || V_168 ) &&
! V_86 -> V_89 )
F_98 ( V_31 , V_86 , V_59 ) ;
V_176:
F_86 ( V_86 ) ;
V_86 -> V_89 ++ ;
F_58 ( & V_86 -> V_87 ) ;
return;
}
int F_101 ( struct V_10 * V_17 , struct V_177 * V_178 )
{
struct V_31 * V_31 = V_17 -> V_25 -> V_26 ;
struct V_138 * V_139 = F_7 ( V_31 ) ;
struct V_3 * V_4 ;
struct V_6 * V_7 ;
struct V_9 * V_10 ;
struct V_19 * V_20 ;
struct V_179 V_180 ;
bool V_181 = false ;
bool V_182 = false ;
int V_24 ;
F_2 ( F_102 ( V_17 ) ) ;
F_2 ( ! F_103 ( V_17 ) ) ;
F_2 ( F_104 ( V_31 ) != NULL ) ;
V_4 = F_105 ( & V_180 ) ;
if ( F_9 ( V_4 ) ) {
V_24 = F_28 ( V_4 ) ;
goto V_64;
}
V_20 = F_7 ( V_31 ) -> V_27 ;
F_2 ( V_20 != NULL ) ;
V_7 = F_19 ( V_4 ) ;
V_7 -> V_183 = V_20 ;
V_7 -> V_184 = 1 ;
V_24 = F_106 ( V_4 , V_7 , V_185 , V_20 ) ;
if ( V_24 == 0 ) {
V_10 = F_26 ( V_4 , V_20 , V_17 -> V_38 ,
V_17 , V_47 ) ;
if ( ! F_9 ( V_10 ) ) {
F_27 ( & V_10 -> V_14 , L_22 ,
V_13 ) ;
F_34 ( V_4 , V_7 , V_10 ) ;
V_24 = F_107 ( V_4 , V_7 , V_10 ) ;
if ( V_24 != 0 ) {
if ( ! F_108 ( V_17 ) ) {
F_109 ( V_178 , V_17 ) ;
V_24 = 0 ;
V_181 = true ;
}
}
F_110 ( V_4 , V_7 , V_10 ) ;
V_182 = true ;
F_3 ( & V_10 -> V_14 ,
L_22 , V_13 ) ;
F_4 ( V_4 , V_10 ) ;
} else {
V_24 = F_28 ( V_10 ) ;
}
}
F_111 ( V_4 , V_7 ) ;
if ( V_181 && V_178 -> V_186 == V_187 ) {
T_1 V_127 = F_112 ( V_20 , V_17 -> V_38 ) ;
V_24 = F_113 ( V_31 , V_127 ,
V_127 + V_41 - 1 ,
V_188 , 1 ) ;
if ( V_24 > 0 ) {
V_178 -> V_189 -= V_24 - 1 ;
V_24 = 0 ;
}
}
F_114 ( & V_180 , V_4 ) ;
goto V_64;
V_64:
if ( V_24 < 0 ) {
if ( ! V_139 -> V_190 )
V_139 -> V_190 = V_24 ;
F_115 ( V_17 ) ;
if ( ! V_182 )
F_70 ( V_17 ) ;
}
return V_24 ;
}
int F_116 ( struct V_73 * V_25 , struct V_177 * V_178 )
{
struct V_31 * V_31 = V_25 -> V_26 ;
struct V_53 * V_54 = F_52 ( V_31 ) ;
T_1 V_77 ;
T_1 V_78 ;
enum V_191 V_192 ;
int V_193 = 0 ;
int V_24 ;
int V_194 = 0 ;
if ( V_178 -> V_195 ) {
V_77 = V_25 -> V_196 << V_39 ;
V_78 = V_197 ;
} else {
V_77 = V_178 -> V_198 ;
V_78 = V_178 -> V_199 ;
if ( V_78 == V_200 ) {
V_78 = V_197 ;
V_193 = V_77 == 0 ;
}
}
V_192 = V_201 ;
if ( V_178 -> V_186 == V_187 )
V_192 = V_188 ;
if ( V_54 -> V_202 )
V_194 = 1 ;
V_24 = F_113 ( V_31 , V_77 , V_78 , V_192 , V_194 ) ;
if ( V_24 > 0 ) {
V_178 -> V_189 -= V_24 ;
V_24 = 0 ;
}
if ( V_178 -> V_195 || ( V_193 && V_178 -> V_189 > 0 ) ) {
if ( V_78 == V_197 )
V_78 = F_100 ( V_31 ) ;
V_25 -> V_196 = ( V_78 >> V_39 ) + 1 ;
}
return V_24 ;
}
int F_117 ( struct V_16 * V_16 , struct V_10 * V_17 )
{
struct V_1 * V_2 ;
int V_24 ;
V_2 = F_6 ( V_16 , V_17 , 0 ) ;
if ( ! F_9 ( V_2 ) ) {
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 ;
F_2 ( V_10 -> V_203 == V_47 ) ;
if ( F_118 ( ! F_64 ( V_17 ) ) ) {
F_34 ( V_4 , V_7 , V_10 ) ;
V_24 = F_119 ( V_4 , V_7 , V_10 ) ;
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
