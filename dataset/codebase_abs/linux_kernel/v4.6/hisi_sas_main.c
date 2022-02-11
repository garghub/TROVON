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
V_68 = F_7 ( V_1 , & V_7 ) ;
if ( V_68 )
goto V_87;
V_68 = V_1 -> V_36 -> V_88 ( V_1 , & V_67 ,
& V_66 ) ;
if ( V_68 )
goto V_89;
V_17 = & V_1 -> V_90 [ V_7 ] ;
memset ( V_17 , 0 , sizeof( struct V_16 ) ) ;
V_17 -> V_35 = V_7 ;
V_17 -> V_21 = V_21 ;
V_17 -> V_67 = V_67 ;
V_17 -> V_66 = V_66 ;
V_65 = V_1 -> V_91 [ V_67 ] ;
V_17 -> V_91 = & V_65 [ V_66 ] ;
V_17 -> V_15 = V_15 ;
V_17 -> V_4 = V_4 ;
V_15 -> V_34 = V_17 ;
F_29 ( & V_17 -> V_45 , F_18 ) ;
V_17 -> V_27 = F_30 ( V_1 -> V_28 ,
V_92 ,
& V_17 -> V_29 ) ;
if ( ! V_17 -> V_27 ) {
V_68 = - V_85 ;
goto V_93;
}
memset ( V_17 -> V_27 , 0 , V_94 ) ;
V_17 -> V_24 = F_30 ( V_1 -> V_25 ,
V_92 ,
& V_17 -> V_26 ) ;
if ( ! V_17 -> V_24 ) {
V_68 = - V_85 ;
goto V_95;
}
memset ( V_17 -> V_24 , 0 , V_96 ) ;
memset ( V_17 -> V_91 , 0 , sizeof( struct V_64 ) ) ;
switch ( V_15 -> V_20 ) {
case V_97 :
V_68 = F_15 ( V_1 , V_17 ) ;
break;
case V_56 :
V_68 = F_16 ( V_1 , V_17 , V_38 , V_40 ) ;
break;
case V_98 :
case V_99 :
case V_98 | V_99 :
V_68 = F_17 ( V_1 , V_17 ) ;
break;
default:
F_20 ( V_18 , L_6 ,
V_15 -> V_20 ) ;
V_68 = - V_100 ;
break;
}
if ( V_68 ) {
F_20 ( V_18 , L_7 , V_68 ) ;
if ( V_17 -> V_30 )
goto V_101;
goto V_102;
}
F_31 ( & V_17 -> V_33 , & V_4 -> V_103 ) ;
F_32 ( & V_15 -> V_104 ) ;
V_15 -> V_105 |= V_106 ;
F_33 ( & V_15 -> V_104 ) ;
V_1 -> V_107 = V_17 ;
V_51 -> V_61 ++ ;
++ ( * V_62 ) ;
return 0 ;
V_101:
F_13 ( V_1 -> V_31 , V_17 -> V_30 ,
V_17 -> V_32 ) ;
V_102:
F_13 ( V_1 -> V_25 , V_17 -> V_24 ,
V_17 -> V_26 ) ;
V_95:
F_13 ( V_1 -> V_28 , V_17 -> V_27 ,
V_17 -> V_29 ) ;
V_93:
V_89:
F_4 ( V_1 , V_7 ) ;
V_87:
F_20 ( V_18 , L_8 , V_68 ) ;
if ( ! F_11 ( V_15 -> V_20 ) )
if ( V_21 )
F_12 ( V_18 , V_15 -> V_22 , V_21 ,
V_15 -> V_23 ) ;
V_86:
return V_68 ;
}
static int F_34 ( struct V_14 * V_15 , T_1 V_108 ,
int V_38 , struct V_39 * V_40 )
{
T_2 V_68 ;
T_2 V_62 = 0 ;
unsigned long V_109 ;
struct V_1 * V_1 = F_1 ( V_15 -> V_18 ) ;
struct V_3 * V_18 = & V_1 -> V_19 -> V_18 ;
F_35 ( & V_1 -> V_110 , V_109 ) ;
V_68 = F_24 ( V_15 , V_1 , V_38 , V_40 , & V_62 ) ;
if ( V_68 )
F_20 ( V_18 , L_9 , V_68 ) ;
if ( F_36 ( V_62 ) )
V_1 -> V_36 -> V_111 ( V_1 ) ;
F_37 ( & V_1 -> V_110 , V_109 ) ;
return V_68 ;
}
static void F_38 ( struct V_1 * V_1 , int V_112 )
{
struct V_113 * V_114 = & V_1 -> V_114 [ V_112 ] ;
struct V_115 * V_116 = & V_114 -> V_116 ;
struct V_117 * V_118 ;
if ( ! V_114 -> V_119 )
return;
V_118 = & V_1 -> V_120 ;
V_118 -> V_121 ( V_116 , V_122 ) ;
if ( V_116 -> V_114 ) {
struct V_116 * V_123 = V_116 -> V_114 ;
V_123 -> V_124 = V_116 -> V_125 ;
V_123 -> V_126 = V_114 -> V_126 ;
V_123 -> V_127 = V_128 ;
V_123 -> V_129 = V_114 -> V_129 ;
}
if ( V_114 -> V_130 & V_131 ) {
struct V_132 * V_82 ;
V_82 = (struct V_132 * ) V_114 -> V_133 ;
V_82 -> V_76 = V_114 -> V_134 . V_135 ;
V_82 -> V_136 = V_137 ;
V_82 -> V_138 = V_114 -> V_134 . V_139 ;
} else if ( V_114 -> V_130 & V_140 ) {
}
V_116 -> V_141 = V_114 -> V_141 ;
V_118 -> V_142 ( V_116 , V_143 ) ;
}
static struct V_50 * F_39 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_50 * V_51 = NULL ;
int V_13 ;
F_32 ( & V_1 -> V_110 ) ;
for ( V_13 = 0 ; V_13 < V_144 ; V_13 ++ ) {
if ( V_1 -> V_145 [ V_13 ] . V_76 == V_146 ) {
V_1 -> V_145 [ V_13 ] . V_78 = V_13 ;
V_51 = & V_1 -> V_145 [ V_13 ] ;
V_51 -> V_147 = V_148 ;
V_51 -> V_76 = V_3 -> V_76 ;
V_51 -> V_1 = V_1 ;
V_51 -> V_149 = V_3 ;
break;
}
}
F_33 ( & V_1 -> V_110 ) ;
return V_51 ;
}
static int F_40 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_2 * V_150 = V_3 -> V_151 ;
struct V_50 * V_51 ;
struct V_3 * V_18 = & V_1 -> V_19 -> V_18 ;
V_51 = F_39 ( V_3 ) ;
if ( ! V_51 ) {
F_20 ( V_18 , L_10 ,
V_144 ) ;
return - V_100 ;
}
V_3 -> V_52 = V_51 ;
V_1 -> V_36 -> V_152 ( V_1 , V_51 ) ;
if ( V_150 && F_41 ( V_150 -> V_76 ) ) {
int V_112 ;
T_3 V_153 = V_150 -> V_154 . V_155 ;
struct V_156 * V_114 ;
for ( V_112 = 0 ; V_112 < V_153 ; V_112 ++ ) {
V_114 = & V_150 -> V_154 . V_156 [ V_112 ] ;
if ( F_27 ( V_114 -> V_157 ) ==
F_27 ( V_3 -> V_79 ) ) {
V_51 -> V_158 = V_112 ;
break;
}
}
if ( V_112 == V_153 ) {
F_26 ( V_18 , L_11
L_12 ,
F_27 ( V_3 -> V_79 ) ,
F_27 ( V_150 -> V_79 ) ) ;
return - V_100 ;
}
}
return 0 ;
}
static int F_42 ( struct V_159 * V_160 )
{
struct V_2 * V_18 = F_43 ( V_160 ) ;
int V_161 = F_44 ( V_160 ) ;
if ( V_161 )
return V_161 ;
if ( ! F_45 ( V_18 ) )
F_46 ( V_160 , 64 ) ;
return 0 ;
}
static void F_47 ( struct V_162 * V_163 )
{
struct V_1 * V_1 = F_48 ( V_163 ) ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_1 -> V_164 ; ++ V_13 )
F_38 ( V_1 , V_13 ) ;
V_1 -> V_165 = 1 ;
}
static int F_49 ( struct V_162 * V_163 , unsigned long time )
{
struct V_1 * V_1 = F_48 ( V_163 ) ;
struct V_117 * V_120 = & V_1 -> V_120 ;
if ( V_1 -> V_165 == 0 )
return 0 ;
F_50 ( V_120 ) ;
return 1 ;
}
static void F_51 ( struct V_43 * V_44 )
{
struct V_113 * V_114 =
F_19 ( V_44 , struct V_113 , V_166 ) ;
struct V_1 * V_1 = V_114 -> V_1 ;
struct V_115 * V_116 = & V_114 -> V_116 ;
int V_112 = V_116 -> V_82 ;
V_1 -> V_36 -> V_167 ( V_1 , V_112 ) ;
F_38 ( V_1 , V_112 ) ;
}
static void F_52 ( struct V_1 * V_1 , int V_112 )
{
struct V_113 * V_114 = & V_1 -> V_114 [ V_112 ] ;
struct V_115 * V_116 = & V_114 -> V_116 ;
V_114 -> V_1 = V_1 ;
V_114 -> V_4 = NULL ;
F_53 ( & V_114 -> V_168 ) ;
V_116 -> V_169 = ( V_112 < V_1 -> V_164 ) ? 1 : 0 ;
V_116 -> V_170 = V_171 ;
V_116 -> V_172 = V_137 ;
V_116 -> V_173 = 0 ;
V_116 -> type = V_174 ;
V_116 -> V_175 = V_176 ;
V_116 -> V_177 = V_178 ;
V_116 -> V_125 = V_179 ;
V_116 -> V_82 = V_112 ;
V_116 -> V_79 = & V_1 -> V_79 [ 0 ] ;
V_116 -> V_133 = & V_114 -> V_133 [ 0 ] ;
V_116 -> V_5 = (struct V_117 * ) V_1 -> V_163 -> V_180 ;
V_116 -> V_181 = V_114 ;
F_29 ( & V_114 -> V_166 , F_51 ) ;
}
static void F_54 ( struct V_115 * V_116 )
{
struct V_117 * V_118 = V_116 -> V_5 ;
struct V_1 * V_1 = V_118 -> V_6 ;
struct V_113 * V_114 = V_116 -> V_181 ;
struct V_182 * V_183 = V_116 -> V_4 ;
struct V_63 * V_4 = & V_1 -> V_4 [ V_116 -> V_82 ] ;
unsigned long V_109 ;
if ( ! V_183 )
return;
F_35 ( & V_1 -> V_110 , V_109 ) ;
V_4 -> V_81 = 1 ;
V_4 -> V_82 = V_114 -> V_184 ;
V_114 -> V_4 = V_4 ;
V_183 -> V_80 = V_4 ;
F_37 ( & V_1 -> V_110 , V_109 ) ;
}
static void F_55 ( struct V_1 * V_1 , int V_112 ,
struct V_2 * V_3 )
{
struct V_113 * V_114 ;
struct V_63 * V_4 ;
struct V_16 * V_17 , * V_185 ;
struct V_3 * V_18 = & V_1 -> V_19 -> V_18 ;
V_114 = & V_1 -> V_114 [ V_112 ] ;
V_4 = V_114 -> V_4 ;
if ( ! V_4 )
return;
F_56 (slot, slot2, &port->list, entry) {
struct V_14 * V_15 ;
V_15 = V_17 -> V_15 ;
if ( V_3 && V_15 -> V_18 != V_3 )
continue;
F_26 ( V_18 , L_13 ,
V_17 -> V_67 , V_17 -> V_66 , V_15 ) ;
V_1 -> V_36 -> V_186 ( V_1 , V_17 , 1 ) ;
}
}
static void F_57 ( struct V_115 * V_116 )
{
struct V_2 * V_3 ;
struct V_113 * V_114 = V_116 -> V_181 ;
struct V_182 * V_183 = V_116 -> V_4 ;
F_58 (device, &sas_port->dev_list, dev_list_node)
F_55 ( V_114 -> V_1 , V_116 -> V_82 , V_3 ) ;
}
static void F_59 ( struct V_1 * V_1 ,
struct V_2 * V_3 )
{
struct V_182 * V_4 = V_3 -> V_4 ;
struct V_115 * V_116 ;
F_58 (sas_phy, &port->phy_list, port_phy_el)
F_55 ( V_1 , V_116 -> V_82 , V_3 ) ;
}
static void F_60 ( struct V_2 * V_3 )
{
struct V_50 * V_51 = V_3 -> V_52 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_3 * V_18 = & V_1 -> V_19 -> V_18 ;
T_4 V_187 = V_51 -> V_78 ;
F_26 ( V_18 , L_14 ,
V_51 -> V_78 , V_51 -> V_76 ) ;
V_1 -> V_36 -> V_188 ( V_1 , V_51 ) ;
V_3 -> V_52 = NULL ;
memset ( V_51 , 0 , sizeof( * V_51 ) ) ;
V_51 -> V_78 = V_187 ;
V_51 -> V_76 = V_146 ;
V_51 -> V_147 = V_148 ;
}
static int F_61 ( struct V_14 * V_15 , T_1 V_108 )
{
return F_34 ( V_15 , V_108 , 0 , NULL ) ;
}
static int F_62 ( struct V_115 * V_116 , enum V_189 V_190 ,
void * V_191 )
{
struct V_117 * V_118 = V_116 -> V_5 ;
struct V_1 * V_1 = V_118 -> V_6 ;
int V_112 = V_116 -> V_82 ;
switch ( V_190 ) {
case V_192 :
V_1 -> V_36 -> V_193 ( V_1 , V_112 ) ;
break;
case V_194 :
V_1 -> V_36 -> V_195 ( V_1 , V_112 ) ;
V_1 -> V_36 -> V_193 ( V_1 , V_112 ) ;
break;
case V_196 :
V_1 -> V_36 -> V_197 ( V_1 , V_112 ) ;
break;
case V_198 :
case V_199 :
default:
return - V_200 ;
}
return 0 ;
}
static void F_63 ( struct V_14 * V_15 )
{
if ( ! F_64 ( & V_15 -> V_201 -> V_168 ) )
return;
F_65 ( & V_15 -> V_201 -> V_202 ) ;
}
static void F_66 ( unsigned long V_203 )
{
struct V_14 * V_15 = (struct V_14 * ) V_203 ;
V_15 -> V_105 |= V_204 ;
F_65 ( & V_15 -> V_201 -> V_202 ) ;
}
static int F_67 ( struct V_2 * V_3 ,
void * V_205 , T_2 V_206 ,
struct V_39 * V_40 )
{
struct V_50 * V_51 = V_3 -> V_52 ;
struct V_1 * V_1 = V_51 -> V_1 ;
struct V_3 * V_18 = & V_1 -> V_19 -> V_18 ;
struct V_14 * V_15 ;
int V_207 , V_208 ;
for ( V_208 = 0 ; V_208 < V_209 ; V_208 ++ ) {
V_15 = F_68 ( V_210 ) ;
if ( ! V_15 )
return - V_85 ;
V_15 -> V_18 = V_3 ;
V_15 -> V_20 = V_3 -> V_173 ;
memcpy ( & V_15 -> V_211 , V_205 , V_206 ) ;
V_15 -> V_60 = F_63 ;
V_15 -> V_201 -> V_168 . V_203 = ( unsigned long ) V_15 ;
V_15 -> V_201 -> V_168 . V_212 = F_66 ;
V_15 -> V_201 -> V_168 . V_213 = V_214 + V_215 * V_216 ;
F_69 ( & V_15 -> V_201 -> V_168 ) ;
V_207 = F_34 ( V_15 , V_210 , 1 , V_40 ) ;
if ( V_207 ) {
F_64 ( & V_15 -> V_201 -> V_168 ) ;
F_20 ( V_18 , L_15 ,
V_207 ) ;
goto V_217;
}
F_70 ( & V_15 -> V_201 -> V_202 ) ;
V_207 = V_218 ;
if ( ( V_15 -> V_105 & V_204 ) ) {
if ( ! ( V_15 -> V_105 & V_219 ) ) {
F_20 ( V_18 , L_16 ,
V_40 -> V_59 ) ;
if ( V_15 -> V_34 ) {
struct V_16 * V_17 =
V_15 -> V_34 ;
F_10 ( V_1 ,
V_15 , V_17 ) ;
}
goto V_217;
}
}
if ( V_15 -> V_71 . V_72 == V_83 &&
V_15 -> V_71 . V_74 == V_220 ) {
V_207 = V_220 ;
break;
}
if ( V_15 -> V_71 . V_72 == V_83 &&
V_15 -> V_71 . V_74 == V_221 ) {
F_71 ( V_18 , L_17
L_18 ,
F_27 ( V_3 -> V_79 ) ,
V_15 -> V_71 . V_72 ,
V_15 -> V_71 . V_74 ) ;
V_207 = V_15 -> V_71 . V_222 ;
break;
}
if ( V_15 -> V_71 . V_72 == V_83 &&
V_15 -> V_71 . V_74 == V_223 ) {
F_71 ( V_18 , L_19 ) ;
V_207 = - V_224 ;
break;
}
F_71 ( V_18 , L_20
L_21 ,
F_27 ( V_3 -> V_79 ) , V_15 -> V_71 . V_72 ,
V_15 -> V_71 . V_74 ) ;
F_72 ( V_15 ) ;
V_15 = NULL ;
}
V_217:
F_73 ( V_208 == V_209 ) ;
F_72 ( V_15 ) ;
return V_207 ;
}
static int F_23 ( struct V_2 * V_3 ,
T_3 * V_54 , struct V_39 * V_40 )
{
struct V_225 V_211 ;
if ( ! ( V_3 -> V_173 & V_56 ) )
return V_226 ;
memcpy ( V_211 . V_227 , V_54 , 8 ) ;
return F_67 ( V_3 , & V_211 ,
sizeof( V_211 ) , V_40 ) ;
}
static int F_74 ( struct V_14 * V_15 )
{
struct V_53 V_54 ;
struct V_39 V_49 ;
struct V_2 * V_3 = V_15 -> V_18 ;
struct V_50 * V_51 = V_3 -> V_52 ;
struct V_1 * V_1 = F_1 ( V_15 -> V_18 ) ;
struct V_3 * V_18 = & V_1 -> V_19 -> V_18 ;
int V_68 = V_218 ;
unsigned long V_109 ;
if ( ! V_51 ) {
F_71 ( V_18 , L_22 ) ;
return V_218 ;
}
F_35 ( & V_15 -> V_104 , V_109 ) ;
if ( V_15 -> V_105 & V_219 ) {
F_37 ( & V_15 -> V_104 , V_109 ) ;
V_68 = V_220 ;
goto V_57;
}
F_37 ( & V_15 -> V_104 , V_109 ) ;
V_51 -> V_147 = V_228 ;
if ( V_15 -> V_34 && V_15 -> V_20 & V_56 ) {
struct V_46 * V_47 = V_15 -> V_48 ;
struct V_16 * V_17 = V_15 -> V_34 ;
T_2 V_55 = V_17 -> V_35 ;
F_21 ( V_47 -> V_3 -> V_54 , & V_54 ) ;
V_49 . V_40 = V_58 ;
V_49 . V_59 = F_22 ( V_55 ) ;
V_68 = F_23 ( V_15 -> V_18 , V_54 . V_53 ,
& V_49 ) ;
if ( V_68 == V_220 ) {
if ( V_15 -> V_34 ) {
struct V_16 * V_17 ;
V_17 = & V_1 -> V_90
[ V_49 . V_59 ] ;
F_35 ( & V_1 -> V_110 , V_109 ) ;
V_1 -> V_36 -> V_186 ( V_1 , V_17 , 1 ) ;
F_37 ( & V_1 -> V_110 , V_109 ) ;
}
}
} else if ( V_15 -> V_20 & V_98 ||
V_15 -> V_20 & V_99 ) {
if ( V_15 -> V_18 -> V_76 == V_77 ) {
struct V_229 * V_17 = V_15 -> V_34 ;
F_75 ( V_18 , L_23 ,
V_1 , V_15 , V_17 ) ;
V_15 -> V_105 |= V_204 ;
V_68 = V_220 ;
goto V_57;
}
}
V_57:
if ( V_68 != V_220 )
F_75 ( V_18 , L_24 , V_68 ) ;
return V_68 ;
}
static int F_76 ( struct V_2 * V_3 , T_3 * V_54 )
{
struct V_39 V_49 ;
int V_68 = V_218 ;
V_49 . V_40 = V_230 ;
V_68 = F_23 ( V_3 , V_54 , & V_49 ) ;
return V_68 ;
}
static int F_77 ( struct V_2 * V_3 , T_3 * V_54 )
{
int V_68 = V_218 ;
struct V_39 V_49 ;
V_49 . V_40 = V_231 ;
V_68 = F_23 ( V_3 , V_54 , & V_49 ) ;
return V_68 ;
}
static int F_78 ( struct V_2 * V_3 )
{
struct V_116 * V_114 = F_79 ( V_3 ) ;
int V_68 , V_232 = ( V_3 -> V_76 == V_77 ||
( V_3 -> V_173 & V_99 ) ) ? 0 : 1 ;
V_68 = F_80 ( V_114 , V_232 ) ;
F_81 ( V_114 ) ;
F_82 ( 2000 ) ;
return V_68 ;
}
static int F_83 ( struct V_2 * V_3 )
{
struct V_50 * V_51 = V_3 -> V_52 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_109 ;
int V_68 = V_218 ;
if ( V_51 -> V_147 != V_228 )
return V_218 ;
V_51 -> V_147 = V_148 ;
V_68 = F_78 ( V_3 ) ;
F_35 ( & V_1 -> V_110 , V_109 ) ;
F_59 ( V_1 , V_3 ) ;
F_37 ( & V_1 -> V_110 , V_109 ) ;
return 0 ;
}
static int F_84 ( struct V_2 * V_3 , T_3 * V_54 )
{
struct V_39 V_49 ;
struct V_50 * V_51 = V_3 -> V_52 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_3 * V_18 = & V_1 -> V_19 -> V_18 ;
unsigned long V_109 ;
int V_68 = V_218 ;
V_49 . V_40 = V_233 ;
V_51 -> V_147 = V_228 ;
V_68 = F_23 ( V_3 , V_54 , & V_49 ) ;
if ( V_68 == V_220 ) {
F_35 ( & V_1 -> V_110 , V_109 ) ;
F_59 ( V_1 , V_3 ) ;
F_37 ( & V_1 -> V_110 , V_109 ) ;
}
F_20 ( V_18 , L_25 ,
V_51 -> V_78 , V_68 ) ;
return V_68 ;
}
static int F_85 ( struct V_14 * V_15 )
{
struct V_53 V_54 ;
struct V_39 V_49 ;
int V_68 = V_218 ;
if ( V_15 -> V_34 && V_15 -> V_20 & V_56 ) {
struct V_46 * V_47 = V_15 -> V_48 ;
struct V_2 * V_3 = V_15 -> V_18 ;
struct V_16 * V_17 = V_15 -> V_34 ;
T_2 V_55 = V_17 -> V_35 ;
F_21 ( V_47 -> V_3 -> V_54 , & V_54 ) ;
V_49 . V_40 = V_234 ;
V_49 . V_59 = F_22 ( V_55 ) ;
V_68 = F_23 ( V_3 ,
V_54 . V_53 ,
& V_49 ) ;
switch ( V_68 ) {
case V_235 :
case V_218 :
case V_220 :
break;
}
}
return V_68 ;
}
static void F_86 ( struct V_115 * V_116 )
{
F_54 ( V_116 ) ;
}
static void F_87 ( struct V_115 * V_116 )
{
F_57 ( V_116 ) ;
}
static void F_88 ( struct V_113 * V_114 )
{
V_114 -> V_119 = 0 ;
V_114 -> V_130 = 0 ;
V_114 -> V_4 = NULL ;
}
void F_89 ( struct V_1 * V_1 , int V_112 , int V_236 )
{
struct V_113 * V_114 = & V_1 -> V_114 [ V_112 ] ;
struct V_115 * V_116 = & V_114 -> V_116 ;
struct V_117 * V_118 = & V_1 -> V_120 ;
if ( V_236 ) {
F_38 ( V_1 , V_112 ) ;
F_54 ( V_116 ) ;
} else {
struct V_63 * V_4 = V_114 -> V_4 ;
V_118 -> V_121 ( V_116 , V_237 ) ;
F_90 ( V_116 ) ;
if ( V_4 ) {
if ( V_114 -> V_130 & V_131 ) {
int V_184 = V_4 -> V_82 ;
if ( ! V_1 -> V_36 -> V_238 ( V_1 ,
V_184 ) )
V_4 -> V_81 = 0 ;
} else if ( V_114 -> V_130 & V_140 )
V_4 -> V_81 = 0 ;
}
F_88 ( V_114 ) ;
}
}
static int F_91 ( struct V_1 * V_1 , struct V_162 * V_163 )
{
struct V_239 * V_19 = V_1 -> V_19 ;
struct V_3 * V_18 = & V_19 -> V_18 ;
int V_13 , V_240 , V_241 = V_1 -> V_36 -> V_241 ;
F_92 ( & V_1 -> V_110 ) ;
for ( V_13 = 0 ; V_13 < V_1 -> V_164 ; V_13 ++ ) {
F_52 ( V_1 , V_13 ) ;
V_1 -> V_4 [ V_13 ] . V_81 = 0 ;
V_1 -> V_4 [ V_13 ] . V_82 = - 1 ;
F_93 ( & V_1 -> V_4 [ V_13 ] . V_103 ) ;
}
for ( V_13 = 0 ; V_13 < V_144 ; V_13 ++ ) {
V_1 -> V_145 [ V_13 ] . V_76 = V_146 ;
V_1 -> V_145 [ V_13 ] . V_78 = V_13 ;
V_1 -> V_145 [ V_13 ] . V_147 = V_148 ;
}
for ( V_13 = 0 ; V_13 < V_1 -> V_242 ; V_13 ++ ) {
struct V_243 * V_244 = & V_1 -> V_244 [ V_13 ] ;
V_244 -> V_82 = V_13 ;
V_244 -> V_1 = V_1 ;
V_240 = sizeof( struct V_64 ) * V_245 ;
V_1 -> V_91 [ V_13 ] = F_94 ( V_18 , V_240 ,
& V_1 -> V_246 [ V_13 ] , V_210 ) ;
if ( ! V_1 -> V_91 [ V_13 ] )
goto V_87;
memset ( V_1 -> V_91 [ V_13 ] , 0 , V_240 ) ;
V_240 = V_1 -> V_36 -> V_247 * V_245 ;
V_1 -> V_248 [ V_13 ] = F_94 ( V_18 , V_240 ,
& V_1 -> V_249 [ V_13 ] , V_210 ) ;
if ( ! V_1 -> V_248 [ V_13 ] )
goto V_87;
memset ( V_1 -> V_248 [ V_13 ] , 0 , V_240 ) ;
}
V_240 = V_94 ;
V_1 -> V_28 = F_95 ( L_26 ,
V_18 , V_240 , 16 , 0 ) ;
if ( ! V_1 -> V_28 )
goto V_87;
V_240 = V_96 ;
V_1 -> V_25 = F_95 ( L_27 ,
V_18 , V_240 , 16 , 0 ) ;
if ( ! V_1 -> V_25 )
goto V_87;
V_240 = V_250 * sizeof( struct V_251 ) ;
V_1 -> V_252 = F_94 ( V_18 , V_240 , & V_1 -> V_253 ,
V_210 ) ;
if ( ! V_1 -> V_252 )
goto V_87;
memset ( V_1 -> V_252 , 0 , V_240 ) ;
V_1 -> V_90 = F_96 ( V_18 , V_241 ,
sizeof( struct V_16 ) ,
V_210 ) ;
if ( ! V_1 -> V_90 )
goto V_87;
V_240 = V_241 * sizeof( struct V_254 ) ;
V_1 -> V_255 = F_94 ( V_18 , V_240 , & V_1 -> V_256 ,
V_210 ) ;
if ( ! V_1 -> V_255 )
goto V_87;
memset ( V_1 -> V_255 , 0 , V_240 ) ;
V_240 = V_241 * sizeof( struct V_257 ) ;
V_1 -> V_258 = F_94 ( V_18 , V_240 ,
& V_1 -> V_259 , V_210 ) ;
if ( ! V_1 -> V_258 )
goto V_87;
memset ( V_1 -> V_258 , 0 , V_240 ) ;
V_1 -> V_11 = V_241 ;
V_240 = V_1 -> V_11 / sizeof( unsigned long ) ;
V_1 -> V_9 = F_97 ( V_18 , V_240 , V_210 ) ;
if ( ! V_1 -> V_9 )
goto V_87;
V_1 -> V_31 = F_95 ( L_28 , V_18 ,
sizeof( struct V_260 ) , 16 , 0 ) ;
if ( ! V_1 -> V_31 )
goto V_87;
V_240 = sizeof( struct V_261 ) * V_262 ;
V_1 -> V_263 = F_94 ( V_18 , V_240 ,
& V_1 -> V_264 , V_210 ) ;
if ( ! V_1 -> V_263 )
goto V_87;
memset ( V_1 -> V_263 , 0 , V_240 ) ;
V_240 = V_241 * sizeof( struct V_257 ) * 2 ;
V_1 -> V_265 = F_94 ( V_18 , V_240 ,
& V_1 -> V_266 , V_210 ) ;
if ( ! V_1 -> V_265 )
goto V_87;
memset ( V_1 -> V_265 , 0 , V_240 ) ;
F_9 ( V_1 ) ;
V_1 -> V_267 = F_98 ( F_99 ( V_18 ) ) ;
if ( ! V_1 -> V_267 ) {
F_20 ( V_18 , L_29 ) ;
goto V_87;
}
return 0 ;
V_87:
return - V_85 ;
}
static void F_100 ( struct V_1 * V_1 )
{
struct V_3 * V_18 = & V_1 -> V_19 -> V_18 ;
int V_13 , V_240 , V_241 = V_1 -> V_36 -> V_241 ;
for ( V_13 = 0 ; V_13 < V_1 -> V_242 ; V_13 ++ ) {
V_240 = sizeof( struct V_64 ) * V_245 ;
if ( V_1 -> V_91 [ V_13 ] )
F_101 ( V_18 , V_240 ,
V_1 -> V_91 [ V_13 ] ,
V_1 -> V_246 [ V_13 ] ) ;
V_240 = V_1 -> V_36 -> V_247 * V_245 ;
if ( V_1 -> V_248 [ V_13 ] )
F_101 ( V_18 , V_240 ,
V_1 -> V_248 [ V_13 ] ,
V_1 -> V_249 [ V_13 ] ) ;
}
F_102 ( V_1 -> V_28 ) ;
F_102 ( V_1 -> V_25 ) ;
F_102 ( V_1 -> V_31 ) ;
V_240 = V_250 * sizeof( struct V_251 ) ;
if ( V_1 -> V_252 )
F_101 ( V_18 , V_240 ,
V_1 -> V_252 , V_1 -> V_253 ) ;
V_240 = V_241 * sizeof( struct V_254 ) ;
if ( V_1 -> V_255 )
F_101 ( V_18 , V_240 ,
V_1 -> V_255 , V_1 -> V_256 ) ;
V_240 = V_241 * sizeof( struct V_257 ) ;
if ( V_1 -> V_258 )
F_101 ( V_18 , V_240 ,
V_1 -> V_258 ,
V_1 -> V_259 ) ;
V_240 = sizeof( struct V_261 ) * V_262 ;
if ( V_1 -> V_263 )
F_101 ( V_18 , V_240 ,
V_1 -> V_263 ,
V_1 -> V_264 ) ;
V_240 = V_241 * sizeof( struct V_257 ) * 2 ;
if ( V_1 -> V_265 )
F_101 ( V_18 , V_240 ,
V_1 -> V_265 ,
V_1 -> V_266 ) ;
if ( V_1 -> V_267 )
F_103 ( V_1 -> V_267 ) ;
}
static struct V_162 * F_104 ( struct V_239 * V_19 ,
const struct V_268 * V_36 )
{
struct V_269 * V_207 ;
struct V_162 * V_163 ;
struct V_1 * V_1 ;
struct V_3 * V_18 = & V_19 -> V_18 ;
struct V_270 * V_271 = V_19 -> V_18 . V_272 ;
V_163 = F_105 ( & V_273 , sizeof( * V_1 ) ) ;
if ( ! V_163 )
goto V_87;
V_1 = F_48 ( V_163 ) ;
V_1 -> V_36 = V_36 ;
V_1 -> V_19 = V_19 ;
V_1 -> V_163 = V_163 ;
F_106 ( V_163 ) = & V_1 -> V_120 ;
F_53 ( & V_1 -> V_168 ) ;
if ( F_107 ( V_18 , L_30 , V_1 -> V_79 ,
V_274 ) )
goto V_87;
if ( V_271 ) {
V_1 -> V_275 = F_108 ( V_271 ,
L_31 ) ;
if ( F_109 ( V_1 -> V_275 ) )
goto V_87;
if ( F_110 ( V_18 , L_32 ,
& V_1 -> V_276 ) )
goto V_87;
if ( F_110 ( V_18 , L_33 ,
& V_1 -> V_277 ) )
goto V_87;
if ( F_110 ( V_18 , L_34 ,
& V_1 -> V_278 ) )
goto V_87;
}
if ( F_110 ( V_18 , L_35 , & V_1 -> V_164 ) )
goto V_87;
if ( F_110 ( V_18 , L_36 ,
& V_1 -> V_242 ) )
goto V_87;
V_207 = F_111 ( V_19 , V_279 , 0 ) ;
V_1 -> V_280 = F_112 ( V_18 , V_207 ) ;
if ( F_109 ( V_1 -> V_280 ) )
goto V_87;
if ( F_91 ( V_1 , V_163 ) ) {
F_100 ( V_1 ) ;
goto V_87;
}
return V_163 ;
V_87:
F_20 ( V_18 , L_37 ) ;
return NULL ;
}
static void F_113 ( struct V_1 * V_1 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_1 -> V_164 ; V_13 ++ )
memcpy ( & V_1 -> V_114 [ V_13 ] . V_281 ,
V_1 -> V_79 ,
V_274 ) ;
}
int F_114 ( struct V_239 * V_19 ,
const struct V_268 * V_36 )
{
struct V_162 * V_163 ;
struct V_1 * V_1 ;
struct V_3 * V_18 = & V_19 -> V_18 ;
struct V_115 * * V_282 ;
struct V_182 * * V_283 ;
struct V_117 * V_120 ;
int V_68 , V_284 , V_285 , V_13 ;
V_163 = F_104 ( V_19 , V_36 ) ;
if ( ! V_163 ) {
V_68 = - V_85 ;
goto V_286;
}
V_120 = F_106 ( V_163 ) ;
V_1 = F_48 ( V_163 ) ;
F_115 ( V_19 , V_120 ) ;
if ( F_116 ( V_18 , F_117 ( 64 ) ) &&
F_116 ( V_18 , F_117 ( 32 ) ) ) {
F_20 ( V_18 , L_38 ) ;
V_68 = - V_287 ;
goto V_286;
}
V_284 = V_285 = V_1 -> V_164 ;
V_282 = F_96 ( V_18 , V_284 , sizeof( void * ) , V_210 ) ;
V_283 = F_96 ( V_18 , V_285 , sizeof( void * ) , V_210 ) ;
if ( ! V_282 || ! V_283 )
return - V_85 ;
V_120 -> V_116 = V_282 ;
V_120 -> V_183 = V_283 ;
V_120 -> V_288 . V_163 = V_163 ;
V_120 -> V_6 = V_1 ;
V_163 -> V_289 = V_290 ;
V_163 -> V_291 = V_144 ;
V_163 -> V_292 = ~ 0 ;
V_163 -> V_293 = 1 ;
V_163 -> V_294 = 16 ;
V_163 -> V_295 = F_118 ( V_296 , V_297 , V_298 ) ;
V_163 -> V_299 = V_1 -> V_36 -> V_241 ;
V_163 -> V_300 = V_1 -> V_36 -> V_241 ;
V_120 -> V_301 = V_302 ;
V_120 -> V_18 = & V_1 -> V_19 -> V_18 ;
V_120 -> V_303 = V_304 ;
V_120 -> V_79 = & V_1 -> V_79 [ 0 ] ;
V_120 -> V_155 = V_1 -> V_164 ;
V_120 -> V_288 . V_163 = V_1 -> V_163 ;
for ( V_13 = 0 ; V_13 < V_1 -> V_164 ; V_13 ++ ) {
V_120 -> V_116 [ V_13 ] = & V_1 -> V_114 [ V_13 ] . V_116 ;
V_120 -> V_183 [ V_13 ] = & V_1 -> V_4 [ V_13 ] . V_183 ;
}
F_113 ( V_1 ) ;
V_68 = V_1 -> V_36 -> V_305 ( V_1 ) ;
if ( V_68 )
goto V_286;
V_68 = F_119 ( V_163 , & V_19 -> V_18 ) ;
if ( V_68 )
goto V_286;
V_68 = F_120 ( V_120 ) ;
if ( V_68 )
goto V_306;
F_121 ( V_163 ) ;
return 0 ;
V_306:
F_122 ( V_163 ) ;
V_286:
F_123 ( V_163 ) ;
return V_68 ;
}
int F_124 ( struct V_239 * V_19 )
{
struct V_117 * V_120 = F_125 ( V_19 ) ;
struct V_1 * V_1 = V_120 -> V_6 ;
F_122 ( V_120 -> V_288 . V_163 ) ;
F_126 ( V_120 ) ;
F_127 ( V_120 -> V_288 . V_163 ) ;
F_100 ( V_1 ) ;
return 0 ;
}
static T_5 int F_128 ( void )
{
F_129 ( L_39 , V_307 ) ;
V_290 = F_130 ( & V_308 ) ;
if ( ! V_290 )
return - V_85 ;
return 0 ;
}
static T_6 void F_131 ( void )
{
F_132 ( V_290 ) ;
}
