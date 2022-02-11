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
V_49 = F_19 ( V_47 , V_49 ) ;
V_21 += V_44 ;
V_40 += V_42 ;
}
return V_49 ;
}
static int F_20 ( struct V_14 * V_15 )
{
T_2 V_54 , V_47 ;
V_54 = F_7 ( V_15 -> V_25 + V_55 ) ;
if ( V_54 & V_56 )
return 0 ;
V_47 = F_7 ( V_15 -> V_57 + V_58 ) ;
if ( F_21 ( V_47 ) && F_22 ( V_47 ) )
return F_19 ( F_23 ( V_47 ) , F_24 ( V_47 ) ) ;
return - V_59 ;
}
static void F_25 ( void * V_60 )
{
F_26 ( V_60 ) ;
}
static int F_27 ( struct V_14 * V_15 , int V_61 , int V_62 , const void * V_21 ,
int V_22 , int V_63 )
{
void T_3 * V_64 = V_15 -> V_25 + V_65 ;
struct V_66 * V_67 = V_15 -> V_67 ;
struct V_68 * V_69 ;
struct V_70 V_71 ;
struct V_72 V_73 ;
int V_74 = - V_75 ;
T_2 V_47 , V_76 ;
F_28 ( & V_71 , V_21 , V_22 ) ;
if ( F_29 ( V_67 -> V_77 -> V_78 , & V_71 , 1 , V_61 ) != 1 )
return - V_75 ;
V_69 = F_30 ( V_67 , & V_71 , 1 , V_61 , V_79 ) ;
if ( ! V_69 )
goto V_80;
V_69 -> V_81 = F_25 ;
V_69 -> V_82 = & V_73 ;
F_31 ( & V_73 ) ;
F_15 ( V_83 , V_15 -> V_17 + V_84 ) ;
F_15 ( V_63 , V_15 -> V_25 + V_85 ) ;
F_15 ( 0 , V_15 -> V_25 + V_86 ) ;
F_15 ( V_62 , V_15 -> V_25 + V_87 ) ;
F_32 ( V_69 ) ;
F_33 ( V_67 ) ;
V_47 = F_34 ( & V_73 , V_88 ) ;
if ( V_47 > 0 )
V_74 = F_35 ( V_64 , V_76 , V_76 & V_89 , 0 , 1000 ) ;
F_15 ( V_90 , V_15 -> V_17 + V_84 ) ;
V_80:
F_36 ( V_67 -> V_77 -> V_78 , & V_71 , 1 , V_61 ) ;
return V_74 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_12 * V_13 ,
T_1 * V_21 , int V_91 , int V_63 )
{
struct V_14 * V_15 = F_6 ( V_13 -> V_16 ) ;
int V_74 , V_47 , V_22 = V_2 -> V_92 ;
if ( V_91 )
V_13 -> V_40 . V_93 ( V_2 , V_13 , V_63 ) ;
V_74 = F_27 ( V_15 , V_94 , V_95 , V_21 , V_22 , V_63 ) ;
if ( V_74 )
return V_74 ;
V_47 = F_20 ( V_15 ) ;
if ( V_47 < 0 ) {
V_13 -> V_40 . V_96 ( V_2 , V_13 , V_63 ) ;
V_47 = F_16 ( V_13 , V_21 ) ;
}
return V_47 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_12 * V_13 ,
const T_1 * V_21 , int V_91 , int V_63 )
{
struct V_14 * V_15 = F_6 ( V_13 -> V_16 ) ;
int V_74 , V_22 = V_2 -> V_92 ;
if ( V_91 )
return - V_97 ;
F_15 ( 0xffffffff , V_15 -> V_57 + V_98 ) ;
V_74 = F_27 ( V_15 , V_99 , V_100 , V_21 , V_22 , V_63 ) ;
if ( V_74 )
return V_74 ;
return 0 ;
}
static void F_39 ( struct V_12 * V_13 , T_1 * * V_21 , int V_22 , int * V_101 )
{
struct V_1 * V_2 = F_17 ( V_13 ) ;
* V_101 += V_22 ;
if ( ! * V_21 ) {
V_13 -> V_102 ( V_2 , V_103 , * V_101 , - 1 ) ;
} else {
F_10 ( V_2 , * V_21 , V_22 ) ;
* V_21 += V_22 ;
}
}
static void F_40 ( struct V_12 * V_13 , const T_1 * * V_21 , int V_22 , int * V_101 )
{
struct V_1 * V_2 = F_17 ( V_13 ) ;
* V_101 += V_22 ;
if ( ! * V_21 ) {
V_13 -> V_102 ( V_2 , V_104 , * V_101 , - 1 ) ;
} else {
F_12 ( V_2 , * V_21 , V_22 ) ;
* V_21 += V_22 ;
}
}
static void F_41 ( struct V_12 * V_13 , T_1 * V_21 , T_1 * V_105 )
{
struct V_1 * V_2 = F_17 ( V_13 ) ;
T_1 * V_106 = V_105 ;
const int V_107 = V_2 -> V_92 ;
const int V_42 = V_13 -> V_40 . V_43 ;
const int V_44 = V_13 -> V_40 . V_45 ;
int V_101 = 0 ;
int V_108 = V_107 ;
if ( V_105 )
V_105 += V_39 ;
F_39 ( V_13 , & V_105 , V_41 , & V_101 ) ;
while ( V_108 > V_44 ) {
F_39 ( V_13 , & V_21 , V_44 , & V_101 ) ;
F_39 ( V_13 , & V_105 , V_42 , & V_101 ) ;
V_108 = V_107 - V_101 ;
}
F_39 ( V_13 , & V_21 , V_108 , & V_101 ) ;
F_39 ( V_13 , & V_106 , V_39 , & V_101 ) ;
F_39 ( V_13 , & V_21 , V_44 - V_108 , & V_101 ) ;
F_39 ( V_13 , & V_105 , V_42 , & V_101 ) ;
}
static void F_42 ( struct V_12 * V_13 , const T_1 * V_21 , const T_1 * V_105 )
{
struct V_1 * V_2 = F_17 ( V_13 ) ;
const T_1 * V_106 = V_105 ;
const int V_107 = V_2 -> V_92 ;
const int V_42 = V_13 -> V_40 . V_43 ;
const int V_44 = V_13 -> V_40 . V_45 ;
int V_101 = 0 ;
int V_108 = V_107 ;
if ( V_105 )
V_105 += V_39 ;
F_40 ( V_13 , & V_105 , V_41 , & V_101 ) ;
while ( V_108 > V_44 ) {
F_40 ( V_13 , & V_21 , V_44 , & V_101 ) ;
F_40 ( V_13 , & V_105 , V_42 , & V_101 ) ;
V_108 = V_107 - V_101 ;
}
F_40 ( V_13 , & V_21 , V_108 , & V_101 ) ;
F_40 ( V_13 , & V_106 , V_39 , & V_101 ) ;
F_40 ( V_13 , & V_21 , V_44 - V_108 , & V_101 ) ;
F_40 ( V_13 , & V_105 , V_42 , & V_101 ) ;
}
static int F_43 ( struct V_1 * V_2 , struct V_12 * V_13 ,
T_1 * V_21 , int V_91 , int V_63 )
{
V_13 -> V_102 ( V_2 , V_109 , 0 , V_63 ) ;
F_41 ( V_13 , V_21 , V_13 -> V_38 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , struct V_12 * V_13 ,
const T_1 * V_21 , int V_91 , int V_63 )
{
V_13 -> V_102 ( V_2 , V_104 , 0 , V_63 ) ;
F_42 ( V_13 , V_21 , V_13 -> V_38 ) ;
V_13 -> V_102 ( V_2 , V_110 , - 1 , - 1 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , struct V_12 * V_13 ,
int V_63 )
{
V_13 -> V_102 ( V_2 , V_109 , 0 , V_63 ) ;
F_41 ( V_13 , NULL , V_13 -> V_38 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_12 * V_13 ,
int V_63 )
{
V_13 -> V_102 ( V_2 , V_104 , 0 , V_63 ) ;
F_42 ( V_13 , NULL , V_13 -> V_38 ) ;
V_13 -> V_102 ( V_2 , V_110 , - 1 , - 1 ) ;
V_13 -> V_111 ( V_2 , V_13 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 , int V_23 , struct V_112 * V_47 )
{
struct V_12 * V_13 = F_3 ( V_2 ) ;
struct V_113 * V_40 = & V_13 -> V_40 ;
if ( V_23 >= V_40 -> V_50 )
return - V_114 ;
V_47 -> V_115 = V_39 + V_41 + V_40 -> V_43 * V_23 ;
V_47 -> V_116 = V_40 -> V_43 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , int V_23 , struct V_112 * V_47 )
{
return - V_114 ;
}
static T_2 F_49 ( int V_117 , int V_118 )
{
return F_50 ( ( V_119 ) V_117 * V_118 , V_120 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
const struct V_121 * V_122 ,
bool V_123 )
{
const struct V_124 * V_125 = F_52 ( V_122 ) ;
struct V_12 * V_13 = F_3 ( V_2 ) ;
struct V_14 * V_15 = F_6 ( V_13 -> V_16 ) ;
struct V_5 * V_6 = F_2 ( V_13 ) ;
T_2 V_126 , V_127 , V_128 , V_129 , V_130 , V_131 , V_132 , V_133 ;
int V_117 = V_15 -> V_134 ;
if ( F_53 ( V_125 ) )
return F_54 ( V_125 ) ;
if ( V_123 )
return 0 ;
V_126 = F_49 ( V_117 , V_125 -> V_135 - V_125 -> V_136 ) ;
V_127 = F_49 ( V_117 , V_125 -> V_137 ) ;
V_128 = F_49 ( V_117 , V_125 -> V_138 ) ;
V_129 = F_49 ( V_117 , V_125 -> V_138 - V_125 -> V_139 ) ;
V_130 = F_49 ( V_117 , V_125 -> V_136 ) ;
V_131 = F_49 ( V_117 , V_125 -> V_140 ) ;
V_132 = F_49 ( V_117 , V_125 -> V_141 - V_125 -> V_140 ) ;
V_133 = F_49 ( V_117 , V_125 -> V_142 ) ;
V_6 -> V_24 = F_55 ( V_126 , V_127 , V_128 , V_129 ) ;
V_6 -> V_27 = F_55 ( V_130 , V_131 , V_132 , V_133 ) ;
return 0 ;
}
static int F_56 ( struct V_77 * V_78 , struct V_143 * V_144 )
{
T_2 V_145 ;
int V_74 , V_47 ;
struct V_1 * V_2 ;
struct V_12 * V_13 ;
struct V_5 * V_6 ;
struct V_113 * V_40 ;
struct V_14 * V_15 = F_57 ( V_78 ) ;
V_6 = F_58 ( V_78 , sizeof( * V_6 ) , V_146 ) ;
if ( ! V_6 )
return - V_147 ;
V_47 = F_59 ( V_144 , L_1 ) ;
if ( V_47 < 0 )
return V_47 ;
if ( V_47 != 1 )
return - V_97 ;
V_74 = F_60 ( V_144 , L_1 , 0 , & V_145 ) ;
if ( V_74 )
return V_74 ;
if ( V_145 >= V_148 )
return - V_149 ;
V_13 = & V_6 -> V_12 ;
V_40 = & V_13 -> V_40 ;
V_2 = F_17 ( V_13 ) ;
V_13 -> V_150 = F_8 ;
V_13 -> V_151 = F_12 ;
V_13 -> V_152 = F_10 ;
V_13 -> V_153 = F_14 ;
V_13 -> V_154 = F_1 ;
V_13 -> V_155 = F_5 ;
V_13 -> V_156 = F_51 ;
V_13 -> V_157 = V_158 |
V_159 |
V_160 ;
V_13 -> V_16 = & V_15 -> V_161 ;
V_6 -> V_8 = V_15 -> V_17 + ( V_145 * 256 ) ;
F_61 ( V_13 , V_144 ) ;
F_62 ( V_2 , & V_162 ) ;
V_2 -> V_78 . V_163 = V_78 ;
V_74 = F_63 ( V_2 , 1 , NULL ) ;
if ( V_74 )
return V_74 ;
V_40 -> V_164 = V_165 ;
V_40 -> V_166 = V_167 ;
V_40 -> V_43 = F_64 ( V_40 -> V_51 * V_168 , V_169 ) ;
V_40 -> V_170 = F_43 ;
V_40 -> V_171 = F_44 ;
V_40 -> V_172 = F_37 ;
V_40 -> V_173 = F_38 ;
V_40 -> V_93 = F_45 ;
V_40 -> V_174 = F_46 ;
V_40 -> V_157 = V_175 ;
V_74 = F_65 ( V_2 ) ;
if ( V_74 )
return V_74 ;
V_6 -> V_29 = F_66 ( V_145 , 1 , V_40 -> V_50 , V_41 ) ;
V_6 -> V_31 = F_67 ( V_40 -> V_45 + V_41 , V_40 -> V_51 ) ;
V_6 -> V_33 = F_67 ( V_40 -> V_45 , V_40 -> V_51 ) ;
V_6 -> V_35 = F_68 ( V_2 -> V_92 , V_39 ) ;
V_74 = F_69 ( V_2 , NULL , 0 ) ;
if ( V_74 )
return V_74 ;
V_15 -> V_176 [ V_145 ] = V_6 ;
return 0 ;
}
static int F_70 ( struct V_177 * V_178 )
{
int V_145 ;
struct V_14 * V_15 = F_71 ( V_178 ) ;
F_72 ( V_15 -> V_67 ) ;
for ( V_145 = 0 ; V_145 < V_148 ; ++ V_145 ) {
if ( V_15 -> V_176 [ V_145 ] )
F_73 ( F_17 ( & V_15 -> V_176 [ V_145 ] -> V_12 ) ) ;
}
return 0 ;
}
static int F_74 ( struct V_177 * V_178 )
{
int V_74 ;
struct V_179 * V_179 ;
struct V_180 * V_47 ;
struct V_14 * V_15 ;
struct V_143 * V_144 ;
V_15 = F_58 ( & V_178 -> V_78 , sizeof( * V_15 ) , V_146 ) ;
if ( ! V_15 )
return - V_147 ;
V_47 = F_75 ( V_178 , V_181 , 0 ) ;
V_15 -> V_25 = F_76 ( & V_178 -> V_78 , V_47 ) ;
if ( F_53 ( V_15 -> V_25 ) )
return F_54 ( V_15 -> V_25 ) ;
V_47 = F_75 ( V_178 , V_181 , 1 ) ;
V_15 -> V_57 = F_76 ( & V_178 -> V_78 , V_47 ) ;
if ( F_53 ( V_15 -> V_57 ) )
return F_54 ( V_15 -> V_57 ) ;
V_47 = F_75 ( V_178 , V_181 , 2 ) ;
V_15 -> V_17 = F_76 ( & V_178 -> V_78 , V_47 ) ;
if ( F_53 ( V_15 -> V_17 ) )
return F_54 ( V_15 -> V_17 ) ;
F_15 ( V_90 , V_15 -> V_17 + V_84 ) ;
V_179 = F_77 ( & V_178 -> V_78 , NULL ) ;
if ( F_53 ( V_179 ) )
return F_54 ( V_179 ) ;
V_15 -> V_67 = F_78 ( & V_178 -> V_78 , L_2 ) ;
if ( F_53 ( V_15 -> V_67 ) )
return F_54 ( V_15 -> V_67 ) ;
F_79 ( V_178 , V_15 ) ;
F_80 ( & V_15 -> V_161 ) ;
V_15 -> V_134 = F_81 ( V_179 ) / 1000 ;
F_82 (pdev->dev.of_node, np) {
V_74 = F_56 ( & V_178 -> V_78 , V_144 ) ;
if ( V_74 ) {
F_70 ( V_178 ) ;
return V_74 ;
}
}
return 0 ;
}
