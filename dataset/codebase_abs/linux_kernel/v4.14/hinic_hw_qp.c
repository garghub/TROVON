void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
T_1 V_5 , T_1 V_6 )
{
T_1 V_7 = V_6 ;
T_1 V_8 = V_6 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_9 = V_4 ;
if ( V_4 == V_10 )
V_2 -> V_11 = F_2 ( V_7 , V_8 , 0 ) ;
else
V_2 -> V_11 = F_3 ( V_7 , V_8 , 0 ) ;
V_2 -> V_11 = F_4 ( V_2 -> V_11 ) ;
F_5 ( V_2 , sizeof( * V_2 ) ) ;
}
void F_6 ( struct V_12 * V_13 ,
struct V_14 * V_15 , T_1 V_16 )
{
T_2 V_17 , V_18 , V_19 , V_20 ;
T_3 V_21 , V_22 , V_23 ;
T_1 V_24 , V_25 ;
struct V_26 * V_27 ;
V_27 = V_15 -> V_27 ;
V_25 = F_7 ( & V_27 -> V_28 ) ;
V_24 = F_7 ( & V_27 -> V_29 ) ;
V_21 = F_8 ( * V_27 -> V_30 ) ;
V_22 = F_9 ( V_21 ) ;
V_17 = F_10 ( V_22 ) ;
V_18 = F_11 ( V_22 ) ;
V_23 = F_12 ( V_27 -> V_31 ) ;
V_19 = F_10 ( V_23 ) ;
V_20 = F_11 ( V_23 ) ;
V_13 -> V_32 = F_13 ( V_16 ,
V_33 ) |
F_13 ( 0 , V_34 ) ;
V_13 -> V_35 = F_14 ( V_25 , V_36 ) |
F_14 ( 1 , V_37 ) ;
V_13 -> V_38 =
F_15 ( V_17 , V_39 ) |
F_15 ( V_24 , V_40 ) ;
V_13 -> V_41 = V_18 ;
V_13 -> V_42 =
F_16 ( V_43 , V_44 ) |
F_16 ( V_45 , V_46 ) |
F_16 ( V_47 , V_48 ) ;
V_13 -> V_49 = 1 ;
V_13 -> V_50 =
F_16 ( V_25 , V_51 ) |
F_16 ( V_17 , V_52 ) ;
V_13 -> V_53 = V_18 ;
V_13 -> V_54 =
F_17 ( V_19 , V_39 ) ;
V_13 -> V_55 = V_20 ;
F_5 ( V_13 , sizeof( * V_13 ) ) ;
}
void F_18 ( struct V_56 * V_57 ,
struct V_58 * V_59 , T_1 V_16 )
{
T_2 V_17 , V_18 , V_19 , V_20 ;
T_3 V_21 , V_22 , V_23 ;
T_1 V_24 , V_25 ;
struct V_26 * V_27 ;
V_27 = V_59 -> V_27 ;
V_25 = F_7 ( & V_27 -> V_28 ) ;
V_24 = F_7 ( & V_27 -> V_29 ) ;
V_21 = F_8 ( * V_27 -> V_30 ) ;
V_22 = F_9 ( V_21 ) ;
V_17 = F_10 ( V_22 ) ;
V_18 = F_11 ( V_22 ) ;
V_23 = F_12 ( V_27 -> V_31 ) ;
V_19 = F_10 ( V_23 ) ;
V_20 = F_11 ( V_23 ) ;
V_57 -> V_32 = F_19 ( 0 , V_34 ) |
F_19 ( 1 , V_37 ) ;
V_57 -> V_60 = F_20 ( V_24 , V_36 ) |
F_20 ( V_59 -> V_61 , V_62 ) ;
V_57 -> V_63 = F_21 ( V_17 ,
V_39 ) |
F_21 ( V_25 , V_51 ) ;
V_57 -> V_41 = V_18 ;
V_57 -> V_42 =
F_22 ( V_43 , V_44 ) |
F_22 ( V_45 , V_46 ) |
F_22 ( V_47 , V_48 ) ;
V_57 -> V_49 = 1 ;
V_57 -> V_50 =
F_22 ( V_17 , V_52 ) |
F_22 ( V_25 , V_51 ) ;
V_57 -> V_53 = V_18 ;
V_57 -> V_64 = F_10 ( V_59 -> V_65 ) ;
V_57 -> V_66 = F_11 ( V_59 -> V_65 ) ;
V_57 -> V_54 =
F_23 ( V_19 , V_39 ) ;
V_57 -> V_55 = V_20 ;
F_5 ( V_57 , sizeof( * V_57 ) ) ;
}
static int F_24 ( struct V_14 * V_15 )
{
struct V_26 * V_27 = V_15 -> V_27 ;
T_4 V_67 ;
V_67 = V_27 -> V_68 * sizeof( * V_15 -> V_69 ) ;
V_15 -> V_69 = F_25 ( V_67 ) ;
if ( ! V_15 -> V_69 )
return - V_70 ;
return 0 ;
}
static void F_26 ( struct V_14 * V_15 )
{
F_27 ( V_15 -> V_69 ) ;
}
static int F_28 ( struct V_58 * V_59 )
{
struct V_26 * V_27 = V_59 -> V_27 ;
T_4 V_67 ;
V_67 = V_27 -> V_68 * sizeof( * V_59 -> V_69 ) ;
V_59 -> V_69 = F_25 ( V_67 ) ;
if ( ! V_59 -> V_69 )
return - V_70 ;
return 0 ;
}
static void F_29 ( struct V_58 * V_59 )
{
F_27 ( V_59 -> V_69 ) ;
}
int F_30 ( struct V_14 * V_15 , struct V_71 * V_72 ,
struct V_26 * V_27 , struct V_61 * V_73 ,
void * V_74 , T_5 V_75 ,
void T_6 * V_76 )
{
V_15 -> V_72 = V_72 ;
V_15 -> V_27 = V_27 ;
V_15 -> V_77 = V_73 -> V_78 ;
V_15 -> V_61 = V_73 -> V_73 ;
V_15 -> V_79 = V_74 ;
V_15 -> V_80 = V_75 ;
V_15 -> V_76 = V_76 + V_81 ;
return F_24 ( V_15 ) ;
}
void F_31 ( struct V_14 * V_15 )
{
F_26 ( V_15 ) ;
}
static int F_32 ( struct V_58 * V_59 )
{
struct V_71 * V_72 = V_59 -> V_72 ;
struct V_82 * V_83 = V_72 -> V_83 ;
T_4 V_84 , V_85 ;
struct V_26 * V_27 = V_59 -> V_27 ;
int V_86 , V_87 ;
V_85 = V_27 -> V_68 * sizeof( * V_59 -> V_88 ) ;
V_59 -> V_88 = F_25 ( V_85 ) ;
if ( ! V_59 -> V_88 )
return - V_70 ;
V_84 = V_27 -> V_68 * sizeof( * V_59 -> V_89 ) ;
V_59 -> V_89 = F_25 ( V_84 ) ;
if ( ! V_59 -> V_89 )
goto V_90;
for ( V_87 = 0 ; V_87 < V_27 -> V_68 ; V_87 ++ ) {
V_59 -> V_88 [ V_87 ] = F_33 ( & V_83 -> V_91 ,
sizeof( * V_59 -> V_88 [ V_87 ] ) ,
& V_59 -> V_89 [ V_87 ] , V_92 ) ;
if ( ! V_59 -> V_88 [ V_87 ] )
goto V_93;
}
return 0 ;
V_93:
for ( V_86 = 0 ; V_86 < V_87 ; V_86 ++ )
F_34 ( & V_83 -> V_91 , sizeof( * V_59 -> V_88 [ V_86 ] ) , V_59 -> V_88 [ V_86 ] ,
V_59 -> V_89 [ V_86 ] ) ;
F_27 ( V_59 -> V_89 ) ;
V_90:
F_27 ( V_59 -> V_88 ) ;
return - V_70 ;
}
static void F_35 ( struct V_58 * V_59 )
{
struct V_71 * V_72 = V_59 -> V_72 ;
struct V_82 * V_83 = V_72 -> V_83 ;
struct V_26 * V_27 = V_59 -> V_27 ;
int V_87 ;
for ( V_87 = 0 ; V_87 < V_27 -> V_68 ; V_87 ++ )
F_34 ( & V_83 -> V_91 , sizeof( * V_59 -> V_88 [ V_87 ] ) , V_59 -> V_88 [ V_87 ] ,
V_59 -> V_89 [ V_87 ] ) ;
F_27 ( V_59 -> V_89 ) ;
F_27 ( V_59 -> V_88 ) ;
}
int F_36 ( struct V_58 * V_59 , struct V_71 * V_72 ,
struct V_26 * V_27 , struct V_61 * V_73 )
{
struct V_82 * V_83 = V_72 -> V_83 ;
T_4 V_94 ;
int V_95 ;
V_59 -> V_72 = V_72 ;
V_59 -> V_27 = V_27 ;
V_59 -> V_77 = V_73 -> V_78 ;
V_59 -> V_61 = V_73 -> V_73 ;
V_59 -> V_96 = V_97 ;
V_95 = F_28 ( V_59 ) ;
if ( V_95 ) {
F_37 ( & V_83 -> V_91 , L_1 ) ;
return V_95 ;
}
V_95 = F_32 ( V_59 ) ;
if ( V_95 ) {
F_37 ( & V_83 -> V_91 , L_2 ) ;
goto V_98;
}
V_94 = F_38 ( sizeof( * V_59 -> V_99 ) , sizeof( T_2 ) ) ;
V_59 -> V_99 = F_33 ( & V_83 -> V_91 , V_94 ,
& V_59 -> V_65 , V_92 ) ;
if ( ! V_59 -> V_99 ) {
F_37 ( & V_83 -> V_91 , L_3 ) ;
V_95 = - V_70 ;
goto V_100;
}
return 0 ;
V_100:
F_35 ( V_59 ) ;
V_98:
F_29 ( V_59 ) ;
return V_95 ;
}
void F_39 ( struct V_58 * V_59 )
{
struct V_71 * V_72 = V_59 -> V_72 ;
struct V_82 * V_83 = V_72 -> V_83 ;
T_4 V_94 ;
V_94 = F_38 ( sizeof( * V_59 -> V_99 ) , sizeof( T_2 ) ) ;
F_34 ( & V_83 -> V_91 , V_94 , V_59 -> V_99 ,
V_59 -> V_65 ) ;
F_35 ( V_59 ) ;
F_29 ( V_59 ) ;
}
int F_40 ( struct V_14 * V_15 )
{
struct V_26 * V_27 = V_15 -> V_27 ;
return F_7 ( & V_27 -> V_101 ) - 1 ;
}
int F_41 ( struct V_58 * V_59 )
{
struct V_26 * V_27 = V_59 -> V_27 ;
return F_7 ( & V_27 -> V_101 ) - 1 ;
}
static void F_42 ( struct V_102 * V_103 , T_1 V_29 ,
int V_104 )
{
T_2 V_105 , V_106 , V_107 ;
V_105 = F_43 ( sizeof( struct V_102 ) ) ;
V_106 = F_43 ( sizeof( struct V_108 ) ) ;
V_107 = V_104 * sizeof( struct V_109 ) ;
V_107 = F_43 ( V_107 ) ;
V_103 -> V_110 = F_44 ( V_107 , V_111 ) |
F_44 ( V_106 , V_112 ) |
F_44 ( V_113 , V_114 ) |
F_44 ( V_105 , V_115 ) ;
V_103 -> V_116 = F_44 ( V_117 ,
V_118 ) ;
}
static void F_45 ( struct V_108 * V_119 )
{
V_119 -> V_120 =
F_46 ( 0 , V_121 ) |
F_46 ( V_122 , V_123 ) |
F_46 ( V_124 ,
V_125 ) |
F_46 ( V_126 ,
V_127 ) |
F_46 ( V_128 , V_129 ) ;
V_119 -> V_130 =
F_47 ( V_131 , V_132 ) |
F_47 ( 0 , V_133 ) |
F_47 ( 0 , V_134 ) ;
V_119 -> V_135 =
F_48 ( 0 , V_136 ) |
F_48 ( 0 , V_137 ) |
F_48 ( V_138 ,
V_139 ) |
F_48 ( V_124 ,
V_140 ) ;
V_119 -> V_141 = 0 ;
V_119 -> V_142 = F_49 ( V_143 , V_144 ) ;
V_119 -> V_145 = 0 ;
}
void F_50 ( struct V_14 * V_15 , T_1 V_29 ,
struct V_146 * V_147 , struct V_148 * V_149 ,
int V_150 )
{
int V_87 ;
F_42 ( & V_147 -> V_103 , V_29 , V_150 ) ;
F_45 ( & V_147 -> V_119 ) ;
for ( V_87 = 0 ; V_87 < V_150 ; V_87 ++ )
V_147 -> V_151 [ V_87 ] . V_152 = V_149 [ V_87 ] ;
}
static T_2 F_51 ( struct V_14 * V_15 , T_1 V_29 , unsigned int cos )
{
struct V_153 * V_154 = F_52 ( V_15 , struct V_153 , V_15 ) ;
T_7 V_155 = F_53 ( F_54 ( V_15 , V_29 ) ) ;
return F_55 ( F_56 ( V_155 , V_156 ) |
F_56 ( V_157 , TYPE ) |
F_56 ( V_158 , V_159 ) |
F_56 ( cos , COS ) |
F_56 ( V_154 -> V_160 , V_161 ) ) ;
}
void F_57 ( struct V_14 * V_15 , T_1 V_29 , unsigned int V_162 ,
unsigned int cos )
{
struct V_26 * V_27 = V_15 -> V_27 ;
V_29 += F_38 ( V_162 , V_27 -> V_163 ) / V_27 -> V_163 ;
F_58 () ;
F_59 ( F_51 ( V_15 , V_29 , cos ) , F_60 ( V_15 , V_29 ) ) ;
}
struct V_146 * F_61 ( struct V_14 * V_15 ,
unsigned int V_162 , T_1 * V_29 )
{
struct V_164 * V_165 = F_62 ( V_15 -> V_27 , V_162 ,
V_29 ) ;
if ( F_63 ( V_165 ) )
return NULL ;
return & V_165 -> V_147 ;
}
void F_64 ( struct V_14 * V_15 , T_1 V_29 ,
struct V_146 * V_147 ,
struct V_166 * V_167 , unsigned int V_162 )
{
struct V_164 * V_165 = (struct V_164 * ) V_147 ;
V_15 -> V_69 [ V_29 ] = V_167 ;
F_5 ( V_147 , V_162 ) ;
F_65 ( V_15 -> V_27 , V_165 , V_162 ) ;
}
struct V_146 * F_66 ( struct V_14 * V_15 ,
struct V_166 * * V_167 ,
unsigned int * V_162 , T_1 * V_28 )
{
struct V_164 * V_165 ;
struct V_146 * V_147 ;
struct V_102 * V_103 ;
unsigned int V_168 ;
T_2 V_110 ;
V_165 = F_67 ( V_15 -> V_27 , sizeof( * V_103 ) , V_28 ) ;
if ( F_63 ( V_165 ) )
return NULL ;
V_147 = & V_165 -> V_147 ;
V_103 = & V_147 -> V_103 ;
V_110 = F_68 ( V_103 -> V_110 ) ;
V_168 = F_69 ( V_110 , V_111 ) ;
* V_162 = sizeof( * V_103 ) + sizeof( V_147 -> V_119 ) ;
* V_162 += F_70 ( V_168 ) ;
* V_167 = V_15 -> V_69 [ * V_28 ] ;
V_165 = F_67 ( V_15 -> V_27 , * V_162 , V_28 ) ;
return & V_165 -> V_147 ;
}
void F_71 ( struct V_14 * V_15 , unsigned int V_162 )
{
F_72 ( V_15 -> V_27 , V_162 ) ;
}
void F_73 ( struct V_146 * V_147 , struct V_148 * V_149 ,
int V_150 )
{
int V_87 ;
for ( V_87 = 0 ; V_87 < V_150 && V_87 < V_169 ; V_87 ++ ) {
V_149 [ V_87 ] = V_147 -> V_151 [ V_87 ] . V_152 ;
F_74 ( & V_149 [ V_87 ] , sizeof( V_149 [ V_87 ] ) ) ;
}
}
struct V_170 * F_75 ( struct V_58 * V_59 ,
unsigned int V_162 , T_1 * V_29 )
{
struct V_164 * V_165 = F_62 ( V_59 -> V_27 , V_162 ,
V_29 ) ;
if ( F_63 ( V_165 ) )
return NULL ;
return & V_165 -> V_171 ;
}
void F_76 ( struct V_58 * V_59 , T_1 V_29 ,
struct V_170 * V_171 , struct V_166 * V_167 )
{
struct V_164 * V_165 = (struct V_164 * ) V_171 ;
V_59 -> V_69 [ V_29 ] = V_167 ;
F_5 ( V_171 , sizeof( * V_171 ) ) ;
F_65 ( V_59 -> V_27 , V_165 , sizeof( * V_171 ) ) ;
}
struct V_170 * F_77 ( struct V_58 * V_59 ,
unsigned int V_162 ,
struct V_166 * * V_167 , T_1 * V_28 )
{
struct V_164 * V_165 ;
struct V_172 * V_88 ;
int V_173 ;
T_2 V_174 ;
V_165 = F_67 ( V_59 -> V_27 , V_162 , V_28 ) ;
if ( F_63 ( V_165 ) )
return NULL ;
V_88 = V_59 -> V_88 [ * V_28 ] ;
V_174 = F_68 ( V_88 -> V_174 ) ;
V_173 = F_78 ( V_174 , V_175 ) ;
if ( ! V_173 )
return NULL ;
* V_167 = V_59 -> V_69 [ * V_28 ] ;
return & V_165 -> V_171 ;
}
struct V_170 * F_79 ( struct V_58 * V_59 ,
unsigned int V_162 ,
struct V_166 * * V_167 ,
T_1 * V_28 )
{
struct V_26 * V_27 = V_59 -> V_27 ;
struct V_164 * V_165 ;
unsigned int V_176 ;
V_162 = F_38 ( V_162 , V_27 -> V_163 ) ;
V_176 = V_162 / V_27 -> V_163 ;
* V_28 = F_80 ( V_59 , * V_28 + V_176 ) ;
* V_167 = V_59 -> V_69 [ * V_28 ] ;
V_165 = F_81 ( V_27 , * V_28 ) ;
return & V_165 -> V_171 ;
}
void F_82 ( struct V_58 * V_59 , T_1 V_28 ,
unsigned int V_162 )
{
struct V_172 * V_88 = V_59 -> V_88 [ V_28 ] ;
T_2 V_174 = F_68 ( V_88 -> V_174 ) ;
V_174 = F_83 ( V_174 , V_175 ) ;
V_88 -> V_174 = F_55 ( V_174 ) ;
F_58 () ;
F_72 ( V_59 -> V_27 , V_162 ) ;
}
void F_84 ( struct V_58 * V_59 , struct V_170 * V_171 ,
T_1 V_28 , struct V_148 * V_152 )
{
struct V_172 * V_88 = V_59 -> V_88 [ V_28 ] ;
T_2 V_177 = F_68 ( V_88 -> V_177 ) ;
V_152 -> V_178 = F_68 ( V_171 -> V_179 . V_178 ) ;
V_152 -> V_180 = F_68 ( V_171 -> V_179 . V_180 ) ;
V_152 -> V_177 = F_85 ( V_177 , V_115 ) ;
}
void F_86 ( struct V_58 * V_59 , T_1 V_29 ,
struct V_170 * V_171 , struct V_148 * V_152 )
{
struct V_181 * V_182 = & V_171 -> V_182 ;
struct V_183 * V_179 = & V_171 -> V_179 ;
struct V_172 * V_88 = V_59 -> V_88 [ V_29 ] ;
struct V_184 * V_103 = & V_171 -> V_103 ;
T_5 V_89 = V_59 -> V_89 [ V_29 ] ;
V_103 -> V_110 =
F_87 ( F_43 ( sizeof( * V_103 ) ) , V_115 ) |
F_87 ( F_43 ( sizeof( * V_182 ) ) ,
V_185 ) |
F_87 ( F_43 ( sizeof( * V_179 ) ) ,
V_111 ) |
F_87 ( V_186 , V_187 ) ;
F_88 ( & V_182 -> V_152 , V_89 , sizeof( * V_88 ) ) ;
V_179 -> V_178 = V_152 -> V_178 ;
V_179 -> V_180 = V_152 -> V_180 ;
}
void F_89 ( struct V_58 * V_59 , T_1 V_29 )
{
* V_59 -> V_99 = F_90 ( F_80 ( V_59 , V_29 + 1 ) ) ;
}
