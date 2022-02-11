static void F_1 ( struct V_1 * V_2 , int V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( F_3 ( V_2 ) ) ;
if ( V_4 & V_7 )
F_4 ( V_3 , V_6 -> V_8 + V_9 ) ;
if ( V_4 & V_10 )
F_4 ( V_3 , V_6 -> V_8 + V_11 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = F_3 ( V_2 ) ;
struct V_14 * V_15 = F_6 ( V_13 -> V_16 ) ;
return F_7 ( V_15 -> V_17 + V_18 ) & V_19 ;
}
static T_1 F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( F_3 ( V_2 ) ) ;
return F_9 ( V_6 -> V_8 + V_20 ) ;
}
static void F_10 ( struct V_1 * V_2 , T_1 * V_21 , int V_22 )
{
struct V_5 * V_6 = F_2 ( F_3 ( V_2 ) ) ;
F_11 ( V_6 -> V_8 + V_20 , V_21 , V_22 ) ;
}
static void F_12 ( struct V_1 * V_2 , const T_1 * V_21 , int V_22 )
{
struct V_5 * V_6 = F_2 ( F_3 ( V_2 ) ) ;
F_13 ( V_6 -> V_8 + V_20 , V_21 , V_22 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_23 )
{
struct V_12 * V_13 = F_3 ( V_2 ) ;
struct V_14 * V_15 = F_6 ( V_13 -> V_16 ) ;
struct V_5 * V_6 = F_2 ( V_13 ) ;
if ( V_23 < 0 )
return;
F_15 ( V_6 -> V_24 , V_15 -> V_25 + V_26 ) ;
F_15 ( V_6 -> V_27 , V_15 -> V_25 + V_28 ) ;
F_15 ( V_6 -> V_29 , V_15 -> V_25 + V_30 ) ;
F_15 ( V_6 -> V_31 , V_15 -> V_25 + V_32 ) ;
F_15 ( V_6 -> V_33 , V_15 -> V_25 + V_34 ) ;
F_15 ( V_6 -> V_35 , V_15 -> V_25 + V_36 ) ;
}
static int F_16 ( struct V_12 * V_13 , T_1 * V_21 )
{
struct V_1 * V_2 = F_17 ( V_13 ) ;
T_1 * V_37 = V_13 -> V_38 + V_39 ;
T_1 * V_40 = V_13 -> V_38 + V_39 + V_41 ;
const int V_42 = V_13 -> V_40 . V_43 ;
const int V_44 = V_13 -> V_40 . V_45 ;
int V_46 , V_47 , V_48 , V_49 = 0 ;
for ( V_46 = 0 ; V_46 < V_13 -> V_40 . V_50 ; ++ V_46 ) {
V_48 = V_46 ? 0 : V_41 ;
V_47 = F_18 ( V_21 , V_44 , V_40 , V_42 ,
V_37 , V_48 ,
V_13 -> V_40 . V_51 ) ;
if ( V_47 < 0 )
V_2 -> V_52 . V_53 ++ ;
else
V_2 -> V_52 . V_54 += V_47 ;
V_49 = F_19 ( V_47 , V_49 ) ;
V_21 += V_44 ;
V_40 += V_42 ;
}
return V_49 ;
}
static int F_20 ( struct V_12 * V_13 )
{
T_2 V_55 , V_47 ;
struct V_1 * V_2 = F_17 ( V_13 ) ;
struct V_14 * V_15 = F_6 ( V_13 -> V_16 ) ;
V_55 = F_7 ( V_15 -> V_25 + V_56 ) ;
if ( V_55 & V_57 )
return 0 ;
V_47 = F_7 ( V_15 -> V_58 + V_59 ) ;
if ( F_21 ( V_47 ) || F_22 ( V_47 ) )
return - V_60 ;
V_2 -> V_52 . V_54 +=
F_23 ( V_47 ) + F_24 ( V_47 ) ;
return F_19 ( F_23 ( V_47 ) , F_24 ( V_47 ) ) ;
}
static void F_25 ( void * V_61 )
{
F_26 ( V_61 ) ;
}
static int F_27 ( struct V_14 * V_15 , enum V_62 V_63 , int V_64 ,
const void * V_21 , int V_22 , int V_65 )
{
void T_3 * V_66 = V_15 -> V_25 + V_67 ;
struct V_68 * V_69 = V_15 -> V_69 ;
struct V_70 * V_71 ;
enum V_72 V_73 ;
struct V_74 V_75 ;
struct V_76 V_77 ;
int V_78 = - V_79 ;
T_2 V_47 , V_80 ;
F_28 ( & V_75 , V_21 , V_22 ) ;
if ( F_29 ( V_69 -> V_81 -> V_82 , & V_75 , 1 , V_63 ) != 1 )
return - V_79 ;
V_73 = V_63 == V_83 ? V_84 : V_85 ;
V_71 = F_30 ( V_69 , & V_75 , 1 , V_73 , V_86 ) ;
if ( ! V_71 )
goto V_87;
V_71 -> V_88 = F_25 ;
V_71 -> V_89 = & V_77 ;
F_31 ( & V_77 ) ;
F_15 ( V_90 , V_15 -> V_17 + V_91 ) ;
F_15 ( V_65 , V_15 -> V_25 + V_92 ) ;
F_15 ( 0 , V_15 -> V_25 + V_93 ) ;
F_15 ( V_64 , V_15 -> V_25 + V_94 ) ;
F_32 ( V_71 ) ;
F_33 ( V_69 ) ;
V_47 = F_34 ( & V_77 , V_95 ) ;
if ( V_47 > 0 )
V_78 = F_35 ( V_66 , V_80 , V_80 & V_96 , 0 , 1000 ) ;
F_15 ( V_97 , V_15 -> V_17 + V_91 ) ;
V_87:
F_36 ( V_69 -> V_81 -> V_82 , & V_75 , 1 , V_63 ) ;
return V_78 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_12 * V_13 ,
T_1 * V_21 , int V_98 , int V_65 )
{
struct V_14 * V_15 = F_6 ( V_13 -> V_16 ) ;
int V_78 , V_47 , V_22 = V_2 -> V_99 ;
if ( V_98 )
V_13 -> V_40 . V_100 ( V_2 , V_13 , V_65 ) ;
V_78 = F_27 ( V_15 , V_101 , V_102 , V_21 , V_22 , V_65 ) ;
if ( V_78 )
return V_78 ;
V_47 = F_20 ( V_13 ) ;
if ( V_47 < 0 ) {
V_13 -> V_40 . V_103 ( V_2 , V_13 , V_65 ) ;
V_47 = F_16 ( V_13 , V_21 ) ;
}
return V_47 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_12 * V_13 ,
const T_1 * V_21 , int V_98 , int V_65 )
{
struct V_14 * V_15 = F_6 ( V_13 -> V_16 ) ;
int V_78 , V_55 , V_22 = V_2 -> V_99 ;
if ( V_98 )
return - V_104 ;
F_15 ( 0xffffffff , V_15 -> V_58 + V_105 ) ;
V_78 = F_27 ( V_15 , V_83 , V_106 , V_21 , V_22 , V_65 ) ;
if ( V_78 )
return V_78 ;
V_55 = V_13 -> V_107 ( V_2 , V_13 ) ;
if ( V_55 & V_108 )
return - V_79 ;
return 0 ;
}
static void F_39 ( struct V_12 * V_13 , T_1 * * V_21 , int V_22 , int * V_109 )
{
struct V_1 * V_2 = F_17 ( V_13 ) ;
* V_109 += V_22 ;
if ( ! * V_21 ) {
V_13 -> V_110 ( V_2 , V_111 , * V_109 , - 1 ) ;
} else {
F_10 ( V_2 , * V_21 , V_22 ) ;
* V_21 += V_22 ;
}
}
static void F_40 ( struct V_12 * V_13 , const T_1 * * V_21 , int V_22 , int * V_109 )
{
struct V_1 * V_2 = F_17 ( V_13 ) ;
* V_109 += V_22 ;
if ( ! * V_21 ) {
V_13 -> V_110 ( V_2 , V_112 , * V_109 , - 1 ) ;
} else {
F_12 ( V_2 , * V_21 , V_22 ) ;
* V_21 += V_22 ;
}
}
static void F_41 ( struct V_12 * V_13 , T_1 * V_21 , T_1 * V_113 )
{
struct V_1 * V_2 = F_17 ( V_13 ) ;
T_1 * V_114 = V_113 ;
const int V_115 = V_2 -> V_99 ;
const int V_42 = V_13 -> V_40 . V_43 ;
const int V_44 = V_13 -> V_40 . V_45 ;
int V_109 = 0 ;
int V_116 = V_115 ;
if ( V_113 )
V_113 += V_39 ;
F_39 ( V_13 , & V_113 , V_41 , & V_109 ) ;
while ( V_116 > V_44 ) {
F_39 ( V_13 , & V_21 , V_44 , & V_109 ) ;
F_39 ( V_13 , & V_113 , V_42 , & V_109 ) ;
V_116 = V_115 - V_109 ;
}
F_39 ( V_13 , & V_21 , V_116 , & V_109 ) ;
F_39 ( V_13 , & V_114 , V_39 , & V_109 ) ;
F_39 ( V_13 , & V_21 , V_44 - V_116 , & V_109 ) ;
F_39 ( V_13 , & V_113 , V_42 , & V_109 ) ;
}
static void F_42 ( struct V_12 * V_13 , const T_1 * V_21 , const T_1 * V_113 )
{
struct V_1 * V_2 = F_17 ( V_13 ) ;
const T_1 * V_114 = V_113 ;
const int V_115 = V_2 -> V_99 ;
const int V_42 = V_13 -> V_40 . V_43 ;
const int V_44 = V_13 -> V_40 . V_45 ;
int V_109 = 0 ;
int V_116 = V_115 ;
if ( V_113 )
V_113 += V_39 ;
F_40 ( V_13 , & V_113 , V_41 , & V_109 ) ;
while ( V_116 > V_44 ) {
F_40 ( V_13 , & V_21 , V_44 , & V_109 ) ;
F_40 ( V_13 , & V_113 , V_42 , & V_109 ) ;
V_116 = V_115 - V_109 ;
}
F_40 ( V_13 , & V_21 , V_116 , & V_109 ) ;
F_40 ( V_13 , & V_114 , V_39 , & V_109 ) ;
F_40 ( V_13 , & V_21 , V_44 - V_116 , & V_109 ) ;
F_40 ( V_13 , & V_113 , V_42 , & V_109 ) ;
}
static int F_43 ( struct V_1 * V_2 , struct V_12 * V_13 ,
T_1 * V_21 , int V_98 , int V_65 )
{
V_13 -> V_110 ( V_2 , V_117 , 0 , V_65 ) ;
F_41 ( V_13 , V_21 , V_13 -> V_38 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , struct V_12 * V_13 ,
const T_1 * V_21 , int V_98 , int V_65 )
{
int V_55 ;
V_13 -> V_110 ( V_2 , V_118 , 0 , V_65 ) ;
F_42 ( V_13 , V_21 , V_13 -> V_38 ) ;
V_13 -> V_110 ( V_2 , V_119 , - 1 , - 1 ) ;
V_55 = V_13 -> V_107 ( V_2 , V_13 ) ;
if ( V_55 & V_108 )
return - V_79 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , struct V_12 * V_13 ,
int V_65 )
{
V_13 -> V_110 ( V_2 , V_117 , 0 , V_65 ) ;
F_41 ( V_13 , NULL , V_13 -> V_38 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_12 * V_13 ,
int V_65 )
{
V_13 -> V_110 ( V_2 , V_118 , 0 , V_65 ) ;
F_42 ( V_13 , NULL , V_13 -> V_38 ) ;
V_13 -> V_110 ( V_2 , V_119 , - 1 , - 1 ) ;
V_13 -> V_107 ( V_2 , V_13 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 , int V_23 , struct V_120 * V_47 )
{
struct V_12 * V_13 = F_3 ( V_2 ) ;
struct V_121 * V_40 = & V_13 -> V_40 ;
if ( V_23 >= V_40 -> V_50 )
return - V_122 ;
V_47 -> V_123 = V_39 + V_41 + V_40 -> V_43 * V_23 ;
V_47 -> V_124 = V_40 -> V_43 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , int V_23 , struct V_120 * V_47 )
{
return - V_122 ;
}
static T_2 F_49 ( int V_125 , int V_126 )
{
return F_50 ( ( V_127 ) V_125 * V_126 , V_128 ) ;
}
static int F_51 ( struct V_1 * V_2 , int V_129 ,
const struct V_130 * V_131 )
{
const struct V_132 * V_133 = F_52 ( V_131 ) ;
struct V_12 * V_13 = F_3 ( V_2 ) ;
struct V_14 * V_15 = F_6 ( V_13 -> V_16 ) ;
struct V_5 * V_6 = F_2 ( V_13 ) ;
T_2 V_134 , V_135 , V_136 , V_137 , V_138 , V_139 , V_140 , V_141 ;
int V_125 = V_15 -> V_142 ;
if ( F_53 ( V_133 ) )
return F_54 ( V_133 ) ;
if ( V_129 == V_143 )
return 0 ;
V_134 = F_49 ( V_125 , V_133 -> V_144 - V_133 -> V_145 ) ;
V_135 = F_49 ( V_125 , V_133 -> V_146 ) ;
V_136 = F_49 ( V_125 , V_133 -> V_147 ) ;
V_137 = F_49 ( V_125 , V_133 -> V_147 - V_133 -> V_148 ) ;
V_138 = F_49 ( V_125 , V_133 -> V_145 ) ;
V_139 = F_49 ( V_125 , V_133 -> V_149 ) ;
V_140 = F_49 ( V_125 , V_133 -> V_150 - V_133 -> V_149 ) ;
V_141 = F_49 ( V_125 , V_133 -> V_151 ) ;
V_6 -> V_24 = F_55 ( V_134 , V_135 , V_136 , V_137 ) ;
V_6 -> V_27 = F_55 ( V_138 , V_139 , V_140 , V_141 ) ;
return 0 ;
}
static int F_56 ( struct V_81 * V_82 , struct V_152 * V_153 )
{
T_2 V_154 ;
int V_78 , V_47 ;
struct V_1 * V_2 ;
struct V_12 * V_13 ;
struct V_5 * V_6 ;
struct V_121 * V_40 ;
struct V_14 * V_15 = F_57 ( V_82 ) ;
V_6 = F_58 ( V_82 , sizeof( * V_6 ) , V_155 ) ;
if ( ! V_6 )
return - V_156 ;
V_47 = F_59 ( V_153 , L_1 ) ;
if ( V_47 < 0 )
return V_47 ;
if ( V_47 != 1 )
return - V_104 ;
V_78 = F_60 ( V_153 , L_1 , 0 , & V_154 ) ;
if ( V_78 )
return V_78 ;
if ( V_154 >= V_157 )
return - V_158 ;
V_13 = & V_6 -> V_12 ;
V_40 = & V_13 -> V_40 ;
V_2 = F_17 ( V_13 ) ;
V_13 -> V_159 = F_8 ;
V_13 -> V_160 = F_12 ;
V_13 -> V_161 = F_10 ;
V_13 -> V_162 = F_14 ;
V_13 -> V_163 = F_1 ;
V_13 -> V_164 = F_5 ;
V_13 -> V_165 = F_51 ;
V_13 -> V_166 = V_167 |
V_168 |
V_169 ;
V_13 -> V_16 = & V_15 -> V_170 ;
V_6 -> V_8 = V_15 -> V_17 + ( V_154 * 256 ) ;
F_61 ( V_13 , V_153 ) ;
F_62 ( V_2 , & V_171 ) ;
V_2 -> V_82 . V_172 = V_82 ;
V_78 = F_63 ( V_2 , 1 , NULL ) ;
if ( V_78 )
return V_78 ;
V_40 -> V_173 = V_174 ;
V_40 -> V_175 = V_176 ;
V_40 -> V_43 = F_64 ( V_40 -> V_51 * V_177 , V_178 ) ;
V_40 -> V_179 = F_43 ;
V_40 -> V_180 = F_44 ;
V_40 -> V_181 = F_37 ;
V_40 -> V_182 = F_38 ;
V_40 -> V_100 = F_45 ;
V_40 -> V_183 = F_46 ;
V_40 -> V_166 = V_184 ;
V_78 = F_65 ( V_2 ) ;
if ( V_78 )
return V_78 ;
V_6 -> V_29 = F_66 ( V_154 , 1 , V_40 -> V_50 , V_41 ) ;
V_6 -> V_31 = F_67 ( V_40 -> V_45 + V_41 , V_40 -> V_51 ) ;
V_6 -> V_33 = F_67 ( V_40 -> V_45 , V_40 -> V_51 ) ;
V_6 -> V_35 = F_68 ( V_2 -> V_99 , V_39 ) ;
V_78 = F_69 ( V_2 , NULL , 0 ) ;
if ( V_78 )
return V_78 ;
V_15 -> V_185 [ V_154 ] = V_6 ;
return 0 ;
}
static int F_70 ( struct V_186 * V_187 )
{
int V_154 ;
struct V_14 * V_15 = F_71 ( V_187 ) ;
F_72 ( V_15 -> V_69 ) ;
for ( V_154 = 0 ; V_154 < V_157 ; ++ V_154 ) {
if ( V_15 -> V_185 [ V_154 ] )
F_73 ( F_17 ( & V_15 -> V_185 [ V_154 ] -> V_12 ) ) ;
}
return 0 ;
}
static int F_74 ( struct V_186 * V_187 )
{
int V_78 ;
struct V_188 * V_188 ;
struct V_189 * V_47 ;
struct V_14 * V_15 ;
struct V_152 * V_153 ;
V_15 = F_58 ( & V_187 -> V_82 , sizeof( * V_15 ) , V_155 ) ;
if ( ! V_15 )
return - V_156 ;
V_47 = F_75 ( V_187 , V_190 , 0 ) ;
V_15 -> V_25 = F_76 ( & V_187 -> V_82 , V_47 ) ;
if ( F_53 ( V_15 -> V_25 ) )
return F_54 ( V_15 -> V_25 ) ;
V_47 = F_75 ( V_187 , V_190 , 1 ) ;
V_15 -> V_58 = F_76 ( & V_187 -> V_82 , V_47 ) ;
if ( F_53 ( V_15 -> V_58 ) )
return F_54 ( V_15 -> V_58 ) ;
V_47 = F_75 ( V_187 , V_190 , 2 ) ;
V_15 -> V_17 = F_76 ( & V_187 -> V_82 , V_47 ) ;
if ( F_53 ( V_15 -> V_17 ) )
return F_54 ( V_15 -> V_17 ) ;
F_15 ( V_97 , V_15 -> V_17 + V_91 ) ;
V_188 = F_77 ( & V_187 -> V_82 , NULL ) ;
if ( F_53 ( V_188 ) )
return F_54 ( V_188 ) ;
V_15 -> V_69 = F_78 ( & V_187 -> V_82 , L_2 ) ;
if ( F_53 ( V_15 -> V_69 ) )
return F_54 ( V_15 -> V_69 ) ;
F_79 ( V_187 , V_15 ) ;
F_80 ( & V_15 -> V_170 ) ;
V_15 -> V_142 = F_81 ( V_188 ) / 1000 ;
F_82 (pdev->dev.of_node, np) {
V_78 = F_56 ( & V_187 -> V_82 , V_153 ) ;
if ( V_78 ) {
F_70 ( V_187 ) ;
return V_78 ;
}
}
return 0 ;
}
