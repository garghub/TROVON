static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 -> V_5 -> V_6 ;
}
static void F_2 ( struct V_1 * V_1 , int V_7 )
{
void * V_8 = V_1 -> V_9 ;
F_3 ( V_7 , V_8 ) ;
}
static void F_4 ( struct V_1 * V_1 , int V_7 )
{
F_2 ( V_1 , V_7 ) ;
}
static void F_5 ( struct V_1 * V_1 , int V_7 )
{
void * V_8 = V_1 -> V_9 ;
F_6 ( V_7 , V_8 ) ;
}
static int F_7 ( struct V_1 * V_1 , int * V_7 )
{
unsigned int V_10 ;
void * V_8 = V_1 -> V_9 ;
V_10 = F_8 ( V_8 , V_1 -> V_11 ) ;
if ( V_10 >= V_1 -> V_11 )
return - V_12 ;
F_5 ( V_1 , V_10 ) ;
* V_7 = V_10 ;
return 0 ;
}
static void F_9 ( struct V_1 * V_1 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_1 -> V_11 ; ++ V_13 )
F_2 ( V_1 , V_13 ) ;
}
void F_10 ( struct V_1 * V_1 , struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_3 * V_18 = & V_1 -> V_19 -> V_18 ;
if ( ! V_17 -> V_15 )
return;
if ( ! F_11 ( V_15 -> V_20 ) )
if ( V_17 -> V_21 )
F_12 ( V_18 , V_15 -> V_22 , V_17 -> V_21 ,
V_15 -> V_23 ) ;
if ( V_17 -> V_24 )
F_13 ( V_1 -> V_25 ,
V_17 -> V_24 , V_17 -> V_26 ) ;
if ( V_17 -> V_27 )
F_13 ( V_1 -> V_28 ,
V_17 -> V_27 , V_17 -> V_29 ) ;
if ( V_17 -> V_30 )
F_13 ( V_1 -> V_31 , V_17 -> V_30 ,
V_17 -> V_32 ) ;
F_14 ( & V_17 -> V_33 ) ;
V_15 -> V_34 = NULL ;
V_17 -> V_15 = NULL ;
V_17 -> V_4 = NULL ;
F_4 ( V_1 , V_17 -> V_35 ) ;
memset ( V_17 , 0 , sizeof( * V_17 ) ) ;
}
static int F_15 ( struct V_1 * V_1 ,
struct V_16 * V_17 )
{
return V_1 -> V_36 -> V_37 ( V_1 , V_17 ) ;
}
static int F_16 ( struct V_1 * V_1 ,
struct V_16 * V_17 , int V_38 ,
struct V_39 * V_40 )
{
return V_1 -> V_36 -> V_41 ( V_1 , V_17 , V_38 , V_40 ) ;
}
static int F_17 ( struct V_1 * V_1 ,
struct V_16 * V_17 )
{
return V_1 -> V_36 -> V_42 ( V_1 , V_17 ) ;
}
static void F_18 ( struct V_43 * V_44 )
{
struct V_16 * V_45 =
F_19 ( V_44 , struct V_16 , V_45 ) ;
struct V_14 * V_15 = V_45 -> V_15 ;
struct V_1 * V_1 = F_1 ( V_15 -> V_18 ) ;
struct V_46 * V_47 = V_15 -> V_48 ;
struct V_39 V_49 ;
struct V_2 * V_3 = V_15 -> V_18 ;
struct V_50 * V_51 = V_3 -> V_52 ;
struct V_53 V_54 ;
struct V_3 * V_18 = & V_1 -> V_19 -> V_18 ;
int V_55 = V_45 -> V_35 ;
if ( ! ( V_15 -> V_20 & V_56 ) ) {
F_20 ( V_18 , L_1 ) ;
goto V_57;
}
F_21 ( V_47 -> V_3 -> V_54 , & V_54 ) ;
V_49 . V_40 = V_58 ;
V_49 . V_59 = F_22 ( V_55 ) ;
F_23 ( V_15 -> V_18 , V_54 . V_53 , & V_49 ) ;
V_57:
F_10 ( V_1 , V_15 , V_45 ) ;
if ( V_15 -> V_60 )
V_15 -> V_60 ( V_15 ) ;
if ( V_51 && V_51 -> V_61 )
V_51 -> V_61 -- ;
}
static int F_24 ( struct V_14 * V_15 , struct V_1 * V_1 ,
int V_38 , struct V_39 * V_40 ,
int * V_62 )
{
struct V_2 * V_3 = V_15 -> V_18 ;
struct V_50 * V_51 = V_3 -> V_52 ;
struct V_63 * V_4 ;
struct V_16 * V_17 ;
struct V_64 * V_65 ;
struct V_3 * V_18 = & V_1 -> V_19 -> V_18 ;
int V_66 , V_67 , V_21 = 0 , V_68 , V_7 ;
if ( ! V_3 -> V_4 ) {
struct V_69 * V_70 = & V_15 -> V_71 ;
V_70 -> V_72 = V_73 ;
V_70 -> V_74 = V_75 ;
if ( V_3 -> V_76 != V_77 )
V_15 -> V_60 ( V_15 ) ;
return 0 ;
}
if ( F_25 ( V_51 ) ) {
if ( V_51 )
F_26 ( V_18 , L_2 ,
V_51 -> V_78 ) ;
else
F_26 ( V_18 , L_3 ,
F_27 ( V_3 -> V_79 ) ) ;
V_68 = V_75 ;
return V_68 ;
}
V_4 = V_3 -> V_4 -> V_80 ;
if ( V_4 && ! V_4 -> V_81 && ! V_40 ) {
if ( F_11 ( V_15 -> V_20 ) ) {
struct V_69 * V_70 = & V_15 -> V_71 ;
F_26 ( V_18 ,
L_4 ,
V_3 -> V_4 -> V_82 ) ;
V_70 -> V_72 = V_83 ;
V_70 -> V_74 = V_75 ;
V_15 -> V_60 ( V_15 ) ;
} else {
struct V_69 * V_70 = & V_15 -> V_71 ;
F_26 ( V_18 ,
L_5 ,
V_3 -> V_4 -> V_82 ) ;
V_70 -> V_72 = V_73 ;
V_70 -> V_74 = V_75 ;
V_15 -> V_60 ( V_15 ) ;
}
return 0 ;
}
if ( ! F_11 ( V_15 -> V_20 ) ) {
if ( V_15 -> V_84 ) {
V_21 = F_28 ( V_18 , V_15 -> V_22 ,
V_15 -> V_84 , V_15 -> V_23 ) ;
if ( ! V_21 ) {
V_68 = - V_85 ;
goto V_86;
}
}
} else
V_21 = V_15 -> V_84 ;
if ( V_1 -> V_36 -> V_87 )
V_68 = V_1 -> V_36 -> V_87 ( V_1 , & V_7 ,
V_3 ) ;
else
V_68 = F_7 ( V_1 , & V_7 ) ;
if ( V_68 )
goto V_88;
V_68 = V_1 -> V_36 -> V_89 ( V_1 , & V_67 ,
& V_66 ) ;
if ( V_68 )
goto V_90;
V_17 = & V_1 -> V_91 [ V_7 ] ;
memset ( V_17 , 0 , sizeof( struct V_16 ) ) ;
V_17 -> V_35 = V_7 ;
V_17 -> V_21 = V_21 ;
V_17 -> V_67 = V_67 ;
V_17 -> V_66 = V_66 ;
V_65 = V_1 -> V_92 [ V_67 ] ;
V_17 -> V_92 = & V_65 [ V_66 ] ;
V_17 -> V_15 = V_15 ;
V_17 -> V_4 = V_4 ;
V_15 -> V_34 = V_17 ;
F_29 ( & V_17 -> V_45 , F_18 ) ;
V_17 -> V_27 = F_30 ( V_1 -> V_28 ,
V_93 ,
& V_17 -> V_29 ) ;
if ( ! V_17 -> V_27 ) {
V_68 = - V_85 ;
goto V_94;
}
memset ( V_17 -> V_27 , 0 , V_95 ) ;
V_17 -> V_24 = F_30 ( V_1 -> V_25 ,
V_93 ,
& V_17 -> V_26 ) ;
if ( ! V_17 -> V_24 ) {
V_68 = - V_85 ;
goto V_96;
}
memset ( V_17 -> V_24 , 0 , V_97 ) ;
memset ( V_17 -> V_92 , 0 , sizeof( struct V_64 ) ) ;
switch ( V_15 -> V_20 ) {
case V_98 :
V_68 = F_15 ( V_1 , V_17 ) ;
break;
case V_56 :
V_68 = F_16 ( V_1 , V_17 , V_38 , V_40 ) ;
break;
case V_99 :
case V_100 :
case V_99 | V_100 :
V_68 = F_17 ( V_1 , V_17 ) ;
break;
default:
F_20 ( V_18 , L_6 ,
V_15 -> V_20 ) ;
V_68 = - V_101 ;
break;
}
if ( V_68 ) {
F_20 ( V_18 , L_7 , V_68 ) ;
if ( V_17 -> V_30 )
goto V_102;
goto V_103;
}
F_31 ( & V_17 -> V_33 , & V_4 -> V_104 ) ;
F_32 ( & V_15 -> V_105 ) ;
V_15 -> V_106 |= V_107 ;
F_33 ( & V_15 -> V_105 ) ;
V_1 -> V_108 = V_17 ;
V_51 -> V_61 ++ ;
++ ( * V_62 ) ;
return 0 ;
V_102:
F_13 ( V_1 -> V_31 , V_17 -> V_30 ,
V_17 -> V_32 ) ;
V_103:
F_13 ( V_1 -> V_25 , V_17 -> V_24 ,
V_17 -> V_26 ) ;
V_96:
F_13 ( V_1 -> V_28 , V_17 -> V_27 ,
V_17 -> V_29 ) ;
V_94:
V_90:
F_4 ( V_1 , V_7 ) ;
V_88:
F_20 ( V_18 , L_8 , V_68 ) ;
if ( ! F_11 ( V_15 -> V_20 ) )
if ( V_21 )
F_12 ( V_18 , V_15 -> V_22 , V_21 ,
V_15 -> V_23 ) ;
V_86:
return V_68 ;
}
static int F_34 ( struct V_14 * V_15 , T_1 V_109 ,
int V_38 , struct V_39 * V_40 )
{
T_2 V_68 ;
T_2 V_62 = 0 ;
unsigned long V_110 ;
struct V_1 * V_1 = F_1 ( V_15 -> V_18 ) ;
struct V_3 * V_18 = & V_1 -> V_19 -> V_18 ;
F_35 ( & V_1 -> V_111 , V_110 ) ;
V_68 = F_24 ( V_15 , V_1 , V_38 , V_40 , & V_62 ) ;
if ( V_68 )
F_20 ( V_18 , L_9 , V_68 ) ;
if ( F_36 ( V_62 ) )
V_1 -> V_36 -> V_112 ( V_1 ) ;
F_37 ( & V_1 -> V_111 , V_110 ) ;
return V_68 ;
}
static void F_38 ( struct V_1 * V_1 , int V_113 )
{
struct V_114 * V_115 = & V_1 -> V_115 [ V_113 ] ;
struct V_116 * V_117 = & V_115 -> V_117 ;
struct V_118 * V_119 ;
if ( ! V_115 -> V_120 )
return;
V_119 = & V_1 -> V_121 ;
V_119 -> V_122 ( V_117 , V_123 ) ;
if ( V_117 -> V_115 ) {
struct V_117 * V_124 = V_117 -> V_115 ;
V_124 -> V_125 = V_117 -> V_126 ;
V_124 -> V_127 = V_115 -> V_127 ;
V_124 -> V_128 = V_129 ;
V_124 -> V_130 = V_115 -> V_130 ;
}
if ( V_115 -> V_131 & V_132 ) {
struct V_133 * V_82 ;
V_82 = (struct V_133 * ) V_115 -> V_134 ;
V_82 -> V_76 = V_115 -> V_135 . V_136 ;
V_82 -> V_137 = V_138 ;
V_82 -> V_139 = V_115 -> V_135 . V_140 ;
} else if ( V_115 -> V_131 & V_141 ) {
}
V_117 -> V_142 = V_115 -> V_142 ;
V_119 -> V_143 ( V_117 , V_144 ) ;
}
static struct V_50 * F_39 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_50 * V_51 = NULL ;
int V_13 ;
F_32 ( & V_1 -> V_111 ) ;
for ( V_13 = 0 ; V_13 < V_145 ; V_13 ++ ) {
if ( V_1 -> V_146 [ V_13 ] . V_76 == V_147 ) {
V_1 -> V_146 [ V_13 ] . V_78 = V_13 ;
V_51 = & V_1 -> V_146 [ V_13 ] ;
V_51 -> V_148 = V_149 ;
V_51 -> V_76 = V_3 -> V_76 ;
V_51 -> V_1 = V_1 ;
V_51 -> V_150 = V_3 ;
break;
}
}
F_33 ( & V_1 -> V_111 ) ;
return V_51 ;
}
static int F_40 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_2 * V_151 = V_3 -> V_152 ;
struct V_50 * V_51 ;
struct V_3 * V_18 = & V_1 -> V_19 -> V_18 ;
if ( V_1 -> V_36 -> V_153 )
V_51 = V_1 -> V_36 -> V_153 ( V_3 ) ;
else
V_51 = F_39 ( V_3 ) ;
if ( ! V_51 ) {
F_20 ( V_18 , L_10 ,
V_145 ) ;
return - V_101 ;
}
V_3 -> V_52 = V_51 ;
V_1 -> V_36 -> V_154 ( V_1 , V_51 ) ;
if ( V_151 && F_41 ( V_151 -> V_76 ) ) {
int V_113 ;
T_3 V_155 = V_151 -> V_156 . V_157 ;
struct V_158 * V_115 ;
for ( V_113 = 0 ; V_113 < V_155 ; V_113 ++ ) {
V_115 = & V_151 -> V_156 . V_158 [ V_113 ] ;
if ( F_27 ( V_115 -> V_159 ) ==
F_27 ( V_3 -> V_79 ) ) {
V_51 -> V_160 = V_113 ;
break;
}
}
if ( V_113 == V_155 ) {
F_26 ( V_18 , L_11
L_12 ,
F_27 ( V_3 -> V_79 ) ,
F_27 ( V_151 -> V_79 ) ) ;
return - V_101 ;
}
}
return 0 ;
}
static int F_42 ( struct V_161 * V_162 )
{
struct V_2 * V_18 = F_43 ( V_162 ) ;
int V_163 = F_44 ( V_162 ) ;
if ( V_163 )
return V_163 ;
if ( ! F_45 ( V_18 ) )
F_46 ( V_162 , 64 ) ;
return 0 ;
}
static void F_47 ( struct V_164 * V_165 )
{
struct V_1 * V_1 = F_48 ( V_165 ) ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_1 -> V_166 ; ++ V_13 )
F_38 ( V_1 , V_13 ) ;
V_1 -> V_167 = 1 ;
}
static int F_49 ( struct V_164 * V_165 , unsigned long time )
{
struct V_1 * V_1 = F_48 ( V_165 ) ;
struct V_118 * V_121 = & V_1 -> V_121 ;
if ( V_1 -> V_167 == 0 )
return 0 ;
F_50 ( V_121 ) ;
return 1 ;
}
static void F_51 ( struct V_43 * V_44 )
{
struct V_114 * V_115 =
F_19 ( V_44 , struct V_114 , V_168 ) ;
struct V_1 * V_1 = V_115 -> V_1 ;
struct V_116 * V_117 = & V_115 -> V_117 ;
int V_113 = V_117 -> V_82 ;
V_1 -> V_36 -> V_169 ( V_1 , V_113 ) ;
F_38 ( V_1 , V_113 ) ;
}
static void F_52 ( struct V_1 * V_1 , int V_113 )
{
struct V_114 * V_115 = & V_1 -> V_115 [ V_113 ] ;
struct V_116 * V_117 = & V_115 -> V_117 ;
V_115 -> V_1 = V_1 ;
V_115 -> V_4 = NULL ;
F_53 ( & V_115 -> V_170 ) ;
V_117 -> V_171 = ( V_113 < V_1 -> V_166 ) ? 1 : 0 ;
V_117 -> V_172 = V_173 ;
V_117 -> V_174 = V_138 ;
V_117 -> V_175 = 0 ;
V_117 -> type = V_176 ;
V_117 -> V_177 = V_178 ;
V_117 -> V_179 = V_180 ;
V_117 -> V_126 = V_181 ;
V_117 -> V_82 = V_113 ;
V_117 -> V_79 = & V_1 -> V_79 [ 0 ] ;
V_117 -> V_134 = & V_115 -> V_134 [ 0 ] ;
V_117 -> V_5 = (struct V_118 * ) V_1 -> V_165 -> V_182 ;
V_117 -> V_183 = V_115 ;
F_29 ( & V_115 -> V_168 , F_51 ) ;
}
static void F_54 ( struct V_116 * V_117 )
{
struct V_118 * V_119 = V_117 -> V_5 ;
struct V_1 * V_1 = V_119 -> V_6 ;
struct V_114 * V_115 = V_117 -> V_183 ;
struct V_184 * V_185 = V_117 -> V_4 ;
struct V_63 * V_4 = & V_1 -> V_4 [ V_117 -> V_82 ] ;
unsigned long V_110 ;
if ( ! V_185 )
return;
F_35 ( & V_1 -> V_111 , V_110 ) ;
V_4 -> V_81 = 1 ;
V_4 -> V_82 = V_115 -> V_186 ;
V_115 -> V_4 = V_4 ;
V_185 -> V_80 = V_4 ;
F_37 ( & V_1 -> V_111 , V_110 ) ;
}
static void F_55 ( struct V_1 * V_1 , int V_113 ,
struct V_2 * V_3 )
{
struct V_114 * V_115 ;
struct V_63 * V_4 ;
struct V_16 * V_17 , * V_187 ;
struct V_3 * V_18 = & V_1 -> V_19 -> V_18 ;
V_115 = & V_1 -> V_115 [ V_113 ] ;
V_4 = V_115 -> V_4 ;
if ( ! V_4 )
return;
F_56 (slot, slot2, &port->list, entry) {
struct V_14 * V_15 ;
V_15 = V_17 -> V_15 ;
if ( V_3 && V_15 -> V_18 != V_3 )
continue;
F_26 ( V_18 , L_13 ,
V_17 -> V_67 , V_17 -> V_66 , V_15 ) ;
V_1 -> V_36 -> V_188 ( V_1 , V_17 , 1 ) ;
}
}
static void F_57 ( struct V_116 * V_117 )
{
struct V_2 * V_3 ;
struct V_114 * V_115 = V_117 -> V_183 ;
struct V_184 * V_185 = V_117 -> V_4 ;
F_58 (device, &sas_port->dev_list, dev_list_node)
F_55 ( V_115 -> V_1 , V_117 -> V_82 , V_3 ) ;
}
static void F_59 ( struct V_1 * V_1 ,
struct V_2 * V_3 )
{
struct V_184 * V_4 = V_3 -> V_4 ;
struct V_116 * V_117 ;
F_58 (sas_phy, &port->phy_list, port_phy_el)
F_55 ( V_1 , V_117 -> V_82 , V_3 ) ;
}
static void F_60 ( struct V_2 * V_3 )
{
struct V_50 * V_51 = V_3 -> V_52 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_3 * V_18 = & V_1 -> V_19 -> V_18 ;
T_4 V_189 = V_51 -> V_78 ;
F_26 ( V_18 , L_14 ,
V_51 -> V_78 , V_51 -> V_76 ) ;
V_1 -> V_36 -> V_190 ( V_1 , V_51 ) ;
V_3 -> V_52 = NULL ;
memset ( V_51 , 0 , sizeof( * V_51 ) ) ;
V_51 -> V_78 = V_189 ;
V_51 -> V_76 = V_147 ;
V_51 -> V_148 = V_149 ;
}
static int F_61 ( struct V_14 * V_15 , T_1 V_109 )
{
return F_34 ( V_15 , V_109 , 0 , NULL ) ;
}
static int F_62 ( struct V_116 * V_117 , enum V_191 V_192 ,
void * V_193 )
{
struct V_118 * V_119 = V_117 -> V_5 ;
struct V_1 * V_1 = V_119 -> V_6 ;
int V_113 = V_117 -> V_82 ;
switch ( V_192 ) {
case V_194 :
V_1 -> V_36 -> V_195 ( V_1 , V_113 ) ;
break;
case V_196 :
V_1 -> V_36 -> V_197 ( V_1 , V_113 ) ;
V_1 -> V_36 -> V_195 ( V_1 , V_113 ) ;
break;
case V_198 :
V_1 -> V_36 -> V_199 ( V_1 , V_113 ) ;
break;
case V_200 :
case V_201 :
default:
return - V_202 ;
}
return 0 ;
}
static void F_63 ( struct V_14 * V_15 )
{
if ( ! F_64 ( & V_15 -> V_203 -> V_170 ) )
return;
F_65 ( & V_15 -> V_203 -> V_204 ) ;
}
static void F_66 ( unsigned long V_205 )
{
struct V_14 * V_15 = (struct V_14 * ) V_205 ;
V_15 -> V_106 |= V_206 ;
F_65 ( & V_15 -> V_203 -> V_204 ) ;
}
static int F_67 ( struct V_2 * V_3 ,
void * V_207 , T_2 V_208 ,
struct V_39 * V_40 )
{
struct V_50 * V_51 = V_3 -> V_52 ;
struct V_1 * V_1 = V_51 -> V_1 ;
struct V_3 * V_18 = & V_1 -> V_19 -> V_18 ;
struct V_14 * V_15 ;
int V_209 , V_210 ;
for ( V_210 = 0 ; V_210 < V_211 ; V_210 ++ ) {
V_15 = F_68 ( V_212 ) ;
if ( ! V_15 )
return - V_85 ;
V_15 -> V_18 = V_3 ;
V_15 -> V_20 = V_3 -> V_175 ;
memcpy ( & V_15 -> V_213 , V_207 , V_208 ) ;
V_15 -> V_60 = F_63 ;
V_15 -> V_203 -> V_170 . V_205 = ( unsigned long ) V_15 ;
V_15 -> V_203 -> V_170 . V_214 = F_66 ;
V_15 -> V_203 -> V_170 . V_215 = V_216 + V_217 * V_218 ;
F_69 ( & V_15 -> V_203 -> V_170 ) ;
V_209 = F_34 ( V_15 , V_212 , 1 , V_40 ) ;
if ( V_209 ) {
F_64 ( & V_15 -> V_203 -> V_170 ) ;
F_20 ( V_18 , L_15 ,
V_209 ) ;
goto V_219;
}
F_70 ( & V_15 -> V_203 -> V_204 ) ;
V_209 = V_220 ;
if ( ( V_15 -> V_106 & V_206 ) ) {
if ( ! ( V_15 -> V_106 & V_221 ) ) {
F_20 ( V_18 , L_16 ,
V_40 -> V_59 ) ;
if ( V_15 -> V_34 ) {
struct V_16 * V_17 =
V_15 -> V_34 ;
F_10 ( V_1 ,
V_15 , V_17 ) ;
}
goto V_219;
}
}
if ( V_15 -> V_71 . V_72 == V_83 &&
V_15 -> V_71 . V_74 == V_222 ) {
V_209 = V_222 ;
break;
}
if ( V_15 -> V_71 . V_72 == V_83 &&
V_15 -> V_71 . V_74 == V_223 ) {
F_71 ( V_18 , L_17
L_18 ,
F_27 ( V_3 -> V_79 ) ,
V_15 -> V_71 . V_72 ,
V_15 -> V_71 . V_74 ) ;
V_209 = V_15 -> V_71 . V_224 ;
break;
}
if ( V_15 -> V_71 . V_72 == V_83 &&
V_15 -> V_71 . V_74 == V_225 ) {
F_71 ( V_18 , L_19 ) ;
V_209 = - V_226 ;
break;
}
F_71 ( V_18 , L_20
L_21 ,
F_27 ( V_3 -> V_79 ) , V_15 -> V_71 . V_72 ,
V_15 -> V_71 . V_74 ) ;
F_72 ( V_15 ) ;
V_15 = NULL ;
}
V_219:
F_73 ( V_210 == V_211 ) ;
F_72 ( V_15 ) ;
return V_209 ;
}
static int F_23 ( struct V_2 * V_3 ,
T_3 * V_54 , struct V_39 * V_40 )
{
struct V_227 V_213 ;
if ( ! ( V_3 -> V_175 & V_56 ) )
return V_228 ;
memcpy ( V_213 . V_229 , V_54 , 8 ) ;
return F_67 ( V_3 , & V_213 ,
sizeof( V_213 ) , V_40 ) ;
}
static int F_74 ( struct V_14 * V_15 )
{
struct V_53 V_54 ;
struct V_39 V_49 ;
struct V_2 * V_3 = V_15 -> V_18 ;
struct V_50 * V_51 = V_3 -> V_52 ;
struct V_1 * V_1 = F_1 ( V_15 -> V_18 ) ;
struct V_3 * V_18 = & V_1 -> V_19 -> V_18 ;
int V_68 = V_220 ;
unsigned long V_110 ;
if ( ! V_51 ) {
F_71 ( V_18 , L_22 ) ;
return V_220 ;
}
F_35 ( & V_15 -> V_105 , V_110 ) ;
if ( V_15 -> V_106 & V_221 ) {
F_37 ( & V_15 -> V_105 , V_110 ) ;
V_68 = V_222 ;
goto V_57;
}
F_37 ( & V_15 -> V_105 , V_110 ) ;
V_51 -> V_148 = V_230 ;
if ( V_15 -> V_34 && V_15 -> V_20 & V_56 ) {
struct V_46 * V_47 = V_15 -> V_48 ;
struct V_16 * V_17 = V_15 -> V_34 ;
T_2 V_55 = V_17 -> V_35 ;
F_21 ( V_47 -> V_3 -> V_54 , & V_54 ) ;
V_49 . V_40 = V_58 ;
V_49 . V_59 = F_22 ( V_55 ) ;
V_68 = F_23 ( V_15 -> V_18 , V_54 . V_53 ,
& V_49 ) ;
if ( V_68 == V_222 ) {
if ( V_15 -> V_34 ) {
struct V_16 * V_17 ;
V_17 = & V_1 -> V_91
[ V_49 . V_59 ] ;
F_35 ( & V_1 -> V_111 , V_110 ) ;
V_1 -> V_36 -> V_188 ( V_1 , V_17 , 1 ) ;
F_37 ( & V_1 -> V_111 , V_110 ) ;
}
}
} else if ( V_15 -> V_20 & V_99 ||
V_15 -> V_20 & V_100 ) {
if ( V_15 -> V_18 -> V_76 == V_77 ) {
struct V_231 * V_17 = V_15 -> V_34 ;
F_75 ( V_18 , L_23 ,
V_1 , V_15 , V_17 ) ;
V_15 -> V_106 |= V_206 ;
V_68 = V_222 ;
goto V_57;
}
}
V_57:
if ( V_68 != V_222 )
F_75 ( V_18 , L_24 , V_68 ) ;
return V_68 ;
}
static int F_76 ( struct V_2 * V_3 , T_3 * V_54 )
{
struct V_39 V_49 ;
int V_68 = V_220 ;
V_49 . V_40 = V_232 ;
V_68 = F_23 ( V_3 , V_54 , & V_49 ) ;
return V_68 ;
}
static int F_77 ( struct V_2 * V_3 , T_3 * V_54 )
{
int V_68 = V_220 ;
struct V_39 V_49 ;
V_49 . V_40 = V_233 ;
V_68 = F_23 ( V_3 , V_54 , & V_49 ) ;
return V_68 ;
}
static int F_78 ( struct V_2 * V_3 )
{
struct V_117 * V_115 = F_79 ( V_3 ) ;
int V_68 , V_234 = ( V_3 -> V_76 == V_77 ||
( V_3 -> V_175 & V_100 ) ) ? 0 : 1 ;
V_68 = F_80 ( V_115 , V_234 ) ;
F_81 ( V_115 ) ;
F_82 ( 2000 ) ;
return V_68 ;
}
static int F_83 ( struct V_2 * V_3 )
{
struct V_50 * V_51 = V_3 -> V_52 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_110 ;
int V_68 = V_220 ;
if ( V_51 -> V_148 != V_230 )
return V_220 ;
V_51 -> V_148 = V_149 ;
V_68 = F_78 ( V_3 ) ;
F_35 ( & V_1 -> V_111 , V_110 ) ;
F_59 ( V_1 , V_3 ) ;
F_37 ( & V_1 -> V_111 , V_110 ) ;
return 0 ;
}
static int F_84 ( struct V_2 * V_3 , T_3 * V_54 )
{
struct V_39 V_49 ;
struct V_50 * V_51 = V_3 -> V_52 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_3 * V_18 = & V_1 -> V_19 -> V_18 ;
unsigned long V_110 ;
int V_68 = V_220 ;
V_49 . V_40 = V_235 ;
V_51 -> V_148 = V_230 ;
V_68 = F_23 ( V_3 , V_54 , & V_49 ) ;
if ( V_68 == V_222 ) {
F_35 ( & V_1 -> V_111 , V_110 ) ;
F_59 ( V_1 , V_3 ) ;
F_37 ( & V_1 -> V_111 , V_110 ) ;
}
F_20 ( V_18 , L_25 ,
V_51 -> V_78 , V_68 ) ;
return V_68 ;
}
static int F_85 ( struct V_14 * V_15 )
{
struct V_53 V_54 ;
struct V_39 V_49 ;
int V_68 = V_220 ;
if ( V_15 -> V_34 && V_15 -> V_20 & V_56 ) {
struct V_46 * V_47 = V_15 -> V_48 ;
struct V_2 * V_3 = V_15 -> V_18 ;
struct V_16 * V_17 = V_15 -> V_34 ;
T_2 V_55 = V_17 -> V_35 ;
F_21 ( V_47 -> V_3 -> V_54 , & V_54 ) ;
V_49 . V_40 = V_236 ;
V_49 . V_59 = F_22 ( V_55 ) ;
V_68 = F_23 ( V_3 ,
V_54 . V_53 ,
& V_49 ) ;
switch ( V_68 ) {
case V_237 :
case V_220 :
case V_222 :
break;
}
}
return V_68 ;
}
static void F_86 ( struct V_116 * V_117 )
{
F_54 ( V_117 ) ;
}
static void F_87 ( struct V_116 * V_117 )
{
F_57 ( V_117 ) ;
}
static void F_88 ( struct V_114 * V_115 )
{
V_115 -> V_120 = 0 ;
V_115 -> V_131 = 0 ;
V_115 -> V_4 = NULL ;
}
void F_89 ( struct V_1 * V_1 , int V_113 , int V_238 )
{
struct V_114 * V_115 = & V_1 -> V_115 [ V_113 ] ;
struct V_116 * V_117 = & V_115 -> V_117 ;
struct V_118 * V_119 = & V_1 -> V_121 ;
if ( V_238 ) {
F_38 ( V_1 , V_113 ) ;
F_54 ( V_117 ) ;
} else {
struct V_63 * V_4 = V_115 -> V_4 ;
V_119 -> V_122 ( V_117 , V_239 ) ;
F_90 ( V_117 ) ;
if ( V_4 ) {
if ( V_115 -> V_131 & V_132 ) {
int V_186 = V_4 -> V_82 ;
if ( ! V_1 -> V_36 -> V_240 ( V_1 ,
V_186 ) )
V_4 -> V_81 = 0 ;
} else if ( V_115 -> V_131 & V_141 )
V_4 -> V_81 = 0 ;
}
F_88 ( V_115 ) ;
}
}
static int F_91 ( struct V_1 * V_1 , struct V_164 * V_165 )
{
struct V_241 * V_19 = V_1 -> V_19 ;
struct V_3 * V_18 = & V_19 -> V_18 ;
int V_13 , V_242 , V_243 = V_1 -> V_36 -> V_243 ;
F_92 ( & V_1 -> V_111 ) ;
for ( V_13 = 0 ; V_13 < V_1 -> V_166 ; V_13 ++ ) {
F_52 ( V_1 , V_13 ) ;
V_1 -> V_4 [ V_13 ] . V_81 = 0 ;
V_1 -> V_4 [ V_13 ] . V_82 = - 1 ;
F_93 ( & V_1 -> V_4 [ V_13 ] . V_104 ) ;
}
for ( V_13 = 0 ; V_13 < V_145 ; V_13 ++ ) {
V_1 -> V_146 [ V_13 ] . V_76 = V_147 ;
V_1 -> V_146 [ V_13 ] . V_78 = V_13 ;
V_1 -> V_146 [ V_13 ] . V_148 = V_149 ;
}
for ( V_13 = 0 ; V_13 < V_1 -> V_244 ; V_13 ++ ) {
struct V_245 * V_246 = & V_1 -> V_246 [ V_13 ] ;
V_246 -> V_82 = V_13 ;
V_246 -> V_1 = V_1 ;
V_242 = sizeof( struct V_64 ) * V_247 ;
V_1 -> V_92 [ V_13 ] = F_94 ( V_18 , V_242 ,
& V_1 -> V_248 [ V_13 ] , V_212 ) ;
if ( ! V_1 -> V_92 [ V_13 ] )
goto V_88;
memset ( V_1 -> V_92 [ V_13 ] , 0 , V_242 ) ;
V_242 = V_1 -> V_36 -> V_249 * V_247 ;
V_1 -> V_250 [ V_13 ] = F_94 ( V_18 , V_242 ,
& V_1 -> V_251 [ V_13 ] , V_212 ) ;
if ( ! V_1 -> V_250 [ V_13 ] )
goto V_88;
memset ( V_1 -> V_250 [ V_13 ] , 0 , V_242 ) ;
}
V_242 = V_95 ;
V_1 -> V_28 = F_95 ( L_26 ,
V_18 , V_242 , 16 , 0 ) ;
if ( ! V_1 -> V_28 )
goto V_88;
V_242 = V_97 ;
V_1 -> V_25 = F_95 ( L_27 ,
V_18 , V_242 , 16 , 0 ) ;
if ( ! V_1 -> V_25 )
goto V_88;
V_242 = V_252 * sizeof( struct V_253 ) ;
V_1 -> V_254 = F_94 ( V_18 , V_242 , & V_1 -> V_255 ,
V_212 ) ;
if ( ! V_1 -> V_254 )
goto V_88;
memset ( V_1 -> V_254 , 0 , V_242 ) ;
V_1 -> V_91 = F_96 ( V_18 , V_243 ,
sizeof( struct V_16 ) ,
V_212 ) ;
if ( ! V_1 -> V_91 )
goto V_88;
V_242 = V_243 * sizeof( struct V_256 ) ;
V_1 -> V_257 = F_94 ( V_18 , V_242 , & V_1 -> V_258 ,
V_212 ) ;
if ( ! V_1 -> V_257 )
goto V_88;
memset ( V_1 -> V_257 , 0 , V_242 ) ;
V_242 = V_243 * sizeof( struct V_259 ) ;
V_1 -> V_260 = F_94 ( V_18 , V_242 ,
& V_1 -> V_261 , V_212 ) ;
if ( ! V_1 -> V_260 )
goto V_88;
memset ( V_1 -> V_260 , 0 , V_242 ) ;
V_1 -> V_11 = V_243 ;
V_242 = V_1 -> V_11 / sizeof( unsigned long ) ;
V_1 -> V_9 = F_97 ( V_18 , V_242 , V_212 ) ;
if ( ! V_1 -> V_9 )
goto V_88;
V_1 -> V_31 = F_95 ( L_28 , V_18 ,
sizeof( struct V_262 ) , 16 , 0 ) ;
if ( ! V_1 -> V_31 )
goto V_88;
V_242 = sizeof( struct V_263 ) * V_264 ;
V_1 -> V_265 = F_94 ( V_18 , V_242 ,
& V_1 -> V_266 , V_212 ) ;
if ( ! V_1 -> V_265 )
goto V_88;
memset ( V_1 -> V_265 , 0 , V_242 ) ;
V_242 = V_243 * sizeof( struct V_259 ) * 2 ;
V_1 -> V_267 = F_94 ( V_18 , V_242 ,
& V_1 -> V_268 , V_212 ) ;
if ( ! V_1 -> V_267 )
goto V_88;
memset ( V_1 -> V_267 , 0 , V_242 ) ;
F_9 ( V_1 ) ;
V_1 -> V_269 = F_98 ( F_99 ( V_18 ) ) ;
if ( ! V_1 -> V_269 ) {
F_20 ( V_18 , L_29 ) ;
goto V_88;
}
return 0 ;
V_88:
return - V_85 ;
}
static void F_100 ( struct V_1 * V_1 )
{
struct V_3 * V_18 = & V_1 -> V_19 -> V_18 ;
int V_13 , V_242 , V_243 = V_1 -> V_36 -> V_243 ;
for ( V_13 = 0 ; V_13 < V_1 -> V_244 ; V_13 ++ ) {
V_242 = sizeof( struct V_64 ) * V_247 ;
if ( V_1 -> V_92 [ V_13 ] )
F_101 ( V_18 , V_242 ,
V_1 -> V_92 [ V_13 ] ,
V_1 -> V_248 [ V_13 ] ) ;
V_242 = V_1 -> V_36 -> V_249 * V_247 ;
if ( V_1 -> V_250 [ V_13 ] )
F_101 ( V_18 , V_242 ,
V_1 -> V_250 [ V_13 ] ,
V_1 -> V_251 [ V_13 ] ) ;
}
F_102 ( V_1 -> V_28 ) ;
F_102 ( V_1 -> V_25 ) ;
F_102 ( V_1 -> V_31 ) ;
V_242 = V_252 * sizeof( struct V_253 ) ;
if ( V_1 -> V_254 )
F_101 ( V_18 , V_242 ,
V_1 -> V_254 , V_1 -> V_255 ) ;
V_242 = V_243 * sizeof( struct V_256 ) ;
if ( V_1 -> V_257 )
F_101 ( V_18 , V_242 ,
V_1 -> V_257 , V_1 -> V_258 ) ;
V_242 = V_243 * sizeof( struct V_259 ) ;
if ( V_1 -> V_260 )
F_101 ( V_18 , V_242 ,
V_1 -> V_260 ,
V_1 -> V_261 ) ;
V_242 = sizeof( struct V_263 ) * V_264 ;
if ( V_1 -> V_265 )
F_101 ( V_18 , V_242 ,
V_1 -> V_265 ,
V_1 -> V_266 ) ;
V_242 = V_243 * sizeof( struct V_259 ) * 2 ;
if ( V_1 -> V_267 )
F_101 ( V_18 , V_242 ,
V_1 -> V_267 ,
V_1 -> V_268 ) ;
if ( V_1 -> V_269 )
F_103 ( V_1 -> V_269 ) ;
}
static struct V_164 * F_104 ( struct V_241 * V_19 ,
const struct V_270 * V_36 )
{
struct V_271 * V_209 ;
struct V_164 * V_165 ;
struct V_1 * V_1 ;
struct V_3 * V_18 = & V_19 -> V_18 ;
struct V_272 * V_273 = V_19 -> V_18 . V_274 ;
V_165 = F_105 ( & V_275 , sizeof( * V_1 ) ) ;
if ( ! V_165 )
goto V_88;
V_1 = F_48 ( V_165 ) ;
V_1 -> V_36 = V_36 ;
V_1 -> V_19 = V_19 ;
V_1 -> V_165 = V_165 ;
F_106 ( V_165 ) = & V_1 -> V_121 ;
F_53 ( & V_1 -> V_170 ) ;
if ( F_107 ( V_18 , L_30 , V_1 -> V_79 ,
V_276 ) )
goto V_88;
if ( V_273 ) {
V_1 -> V_277 = F_108 ( V_273 ,
L_31 ) ;
if ( F_109 ( V_1 -> V_277 ) )
goto V_88;
if ( F_110 ( V_18 , L_32 ,
& V_1 -> V_278 ) )
goto V_88;
if ( F_110 ( V_18 , L_33 ,
& V_1 -> V_279 ) )
goto V_88;
if ( F_110 ( V_18 , L_34 ,
& V_1 -> V_280 ) )
goto V_88;
}
if ( F_110 ( V_18 , L_35 , & V_1 -> V_166 ) )
goto V_88;
if ( F_110 ( V_18 , L_36 ,
& V_1 -> V_244 ) )
goto V_88;
V_209 = F_111 ( V_19 , V_281 , 0 ) ;
V_1 -> V_282 = F_112 ( V_18 , V_209 ) ;
if ( F_109 ( V_1 -> V_282 ) )
goto V_88;
if ( F_91 ( V_1 , V_165 ) ) {
F_100 ( V_1 ) ;
goto V_88;
}
return V_165 ;
V_88:
F_20 ( V_18 , L_37 ) ;
return NULL ;
}
static void F_113 ( struct V_1 * V_1 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_1 -> V_166 ; V_13 ++ )
memcpy ( & V_1 -> V_115 [ V_13 ] . V_283 ,
V_1 -> V_79 ,
V_276 ) ;
}
int F_114 ( struct V_241 * V_19 ,
const struct V_270 * V_36 )
{
struct V_164 * V_165 ;
struct V_1 * V_1 ;
struct V_3 * V_18 = & V_19 -> V_18 ;
struct V_116 * * V_284 ;
struct V_184 * * V_285 ;
struct V_118 * V_121 ;
int V_68 , V_286 , V_287 , V_13 ;
V_165 = F_104 ( V_19 , V_36 ) ;
if ( ! V_165 ) {
V_68 = - V_85 ;
goto V_288;
}
V_121 = F_106 ( V_165 ) ;
V_1 = F_48 ( V_165 ) ;
F_115 ( V_19 , V_121 ) ;
if ( F_116 ( V_18 , F_117 ( 64 ) ) &&
F_116 ( V_18 , F_117 ( 32 ) ) ) {
F_20 ( V_18 , L_38 ) ;
V_68 = - V_289 ;
goto V_288;
}
V_286 = V_287 = V_1 -> V_166 ;
V_284 = F_96 ( V_18 , V_286 , sizeof( void * ) , V_212 ) ;
V_285 = F_96 ( V_18 , V_287 , sizeof( void * ) , V_212 ) ;
if ( ! V_284 || ! V_285 )
return - V_85 ;
V_121 -> V_117 = V_284 ;
V_121 -> V_185 = V_285 ;
V_121 -> V_290 . V_165 = V_165 ;
V_121 -> V_6 = V_1 ;
V_165 -> V_291 = V_292 ;
V_165 -> V_293 = V_145 ;
V_165 -> V_294 = ~ 0 ;
V_165 -> V_295 = 1 ;
V_165 -> V_296 = 16 ;
V_165 -> V_297 = F_118 ( V_298 , V_299 , V_300 ) ;
V_165 -> V_301 = V_1 -> V_36 -> V_243 ;
V_165 -> V_302 = V_1 -> V_36 -> V_243 ;
V_121 -> V_303 = V_304 ;
V_121 -> V_18 = & V_1 -> V_19 -> V_18 ;
V_121 -> V_305 = V_306 ;
V_121 -> V_79 = & V_1 -> V_79 [ 0 ] ;
V_121 -> V_157 = V_1 -> V_166 ;
V_121 -> V_290 . V_165 = V_1 -> V_165 ;
for ( V_13 = 0 ; V_13 < V_1 -> V_166 ; V_13 ++ ) {
V_121 -> V_117 [ V_13 ] = & V_1 -> V_115 [ V_13 ] . V_117 ;
V_121 -> V_185 [ V_13 ] = & V_1 -> V_4 [ V_13 ] . V_185 ;
}
F_113 ( V_1 ) ;
V_68 = V_1 -> V_36 -> V_307 ( V_1 ) ;
if ( V_68 )
goto V_288;
V_68 = F_119 ( V_165 , & V_19 -> V_18 ) ;
if ( V_68 )
goto V_288;
V_68 = F_120 ( V_121 ) ;
if ( V_68 )
goto V_308;
F_121 ( V_165 ) ;
return 0 ;
V_308:
F_122 ( V_165 ) ;
V_288:
F_123 ( V_165 ) ;
return V_68 ;
}
int F_124 ( struct V_241 * V_19 )
{
struct V_118 * V_121 = F_125 ( V_19 ) ;
struct V_1 * V_1 = V_121 -> V_6 ;
F_122 ( V_121 -> V_290 . V_165 ) ;
F_126 ( V_121 ) ;
F_127 ( V_121 -> V_290 . V_165 ) ;
F_100 ( V_1 ) ;
return 0 ;
}
static T_5 int F_128 ( void )
{
F_129 ( L_39 , V_309 ) ;
V_292 = F_130 ( & V_310 ) ;
if ( ! V_292 )
return - V_85 ;
return 0 ;
}
static T_6 void F_131 ( void )
{
F_132 ( V_292 ) ;
}
