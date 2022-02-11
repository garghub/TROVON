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
static int F_17 ( struct V_14 * V_15 , struct V_1 * V_1 ,
int V_38 , struct V_39 * V_40 ,
int * V_42 )
{
struct V_2 * V_3 = V_15 -> V_18 ;
struct V_43 * V_44 = V_3 -> V_45 ;
struct V_46 * V_4 ;
struct V_16 * V_17 ;
struct V_47 * V_48 ;
struct V_3 * V_18 = & V_1 -> V_19 -> V_18 ;
int V_49 , V_50 , V_21 = 0 , V_51 , V_7 ;
if ( ! V_3 -> V_4 ) {
struct V_52 * V_53 = & V_15 -> V_54 ;
V_53 -> V_55 = V_56 ;
V_53 -> V_57 = V_58 ;
if ( V_3 -> V_59 != V_60 )
V_15 -> V_61 ( V_15 ) ;
return 0 ;
}
if ( F_18 ( V_44 ) ) {
if ( V_44 )
F_19 ( V_18 , L_1 ,
V_44 -> V_62 ) ;
else
F_19 ( V_18 , L_2 ,
F_20 ( V_3 -> V_63 ) ) ;
V_51 = V_58 ;
return V_51 ;
}
V_4 = V_3 -> V_4 -> V_64 ;
if ( V_4 && ! V_4 -> V_65 && ! V_40 ) {
if ( F_11 ( V_15 -> V_20 ) ) {
struct V_52 * V_53 = & V_15 -> V_54 ;
F_19 ( V_18 ,
L_3 ,
V_3 -> V_4 -> V_66 ) ;
V_53 -> V_55 = V_67 ;
V_53 -> V_57 = V_58 ;
V_15 -> V_61 ( V_15 ) ;
} else {
struct V_52 * V_53 = & V_15 -> V_54 ;
F_19 ( V_18 ,
L_4 ,
V_3 -> V_4 -> V_66 ) ;
V_53 -> V_55 = V_56 ;
V_53 -> V_57 = V_58 ;
V_15 -> V_61 ( V_15 ) ;
}
return 0 ;
}
if ( ! F_11 ( V_15 -> V_20 ) ) {
if ( V_15 -> V_68 ) {
V_21 = F_21 ( V_18 , V_15 -> V_22 ,
V_15 -> V_68 , V_15 -> V_23 ) ;
if ( ! V_21 ) {
V_51 = - V_69 ;
goto V_70;
}
}
} else
V_21 = V_15 -> V_68 ;
V_51 = F_7 ( V_1 , & V_7 ) ;
if ( V_51 )
goto V_71;
V_51 = V_1 -> V_36 -> V_72 ( V_1 , & V_50 ,
& V_49 ) ;
if ( V_51 )
goto V_73;
V_17 = & V_1 -> V_74 [ V_7 ] ;
memset ( V_17 , 0 , sizeof( struct V_16 ) ) ;
V_17 -> V_35 = V_7 ;
V_17 -> V_21 = V_21 ;
V_17 -> V_50 = V_50 ;
V_17 -> V_49 = V_49 ;
V_48 = V_1 -> V_75 [ V_50 ] ;
V_17 -> V_75 = & V_48 [ V_49 ] ;
V_17 -> V_15 = V_15 ;
V_17 -> V_4 = V_4 ;
V_15 -> V_34 = V_17 ;
V_17 -> V_27 = F_22 ( V_1 -> V_28 ,
V_76 ,
& V_17 -> V_29 ) ;
if ( ! V_17 -> V_27 ) {
V_51 = - V_69 ;
goto V_77;
}
memset ( V_17 -> V_27 , 0 , V_78 ) ;
V_17 -> V_24 = F_22 ( V_1 -> V_25 ,
V_76 ,
& V_17 -> V_26 ) ;
if ( ! V_17 -> V_24 ) {
V_51 = - V_69 ;
goto V_79;
}
memset ( V_17 -> V_24 , 0 , V_80 ) ;
memset ( V_17 -> V_75 , 0 , sizeof( struct V_47 ) ) ;
switch ( V_15 -> V_20 ) {
case V_81 :
V_51 = F_15 ( V_1 , V_17 ) ;
break;
case V_82 :
V_51 = F_16 ( V_1 , V_17 , V_38 , V_40 ) ;
break;
case V_83 :
case V_84 :
case V_83 | V_84 :
default:
F_23 ( V_18 , L_5 ,
V_15 -> V_20 ) ;
V_51 = - V_85 ;
break;
}
if ( V_51 ) {
F_23 ( V_18 , L_6 , V_51 ) ;
if ( V_17 -> V_30 )
goto V_86;
goto V_87;
}
F_24 ( & V_17 -> V_33 , & V_4 -> V_88 ) ;
F_25 ( & V_15 -> V_89 ) ;
V_15 -> V_90 |= V_91 ;
F_26 ( & V_15 -> V_89 ) ;
V_1 -> V_92 = V_17 ;
V_44 -> V_93 ++ ;
++ ( * V_42 ) ;
return 0 ;
V_86:
F_13 ( V_1 -> V_31 , V_17 -> V_30 ,
V_17 -> V_32 ) ;
V_87:
F_13 ( V_1 -> V_25 , V_17 -> V_24 ,
V_17 -> V_26 ) ;
V_79:
F_13 ( V_1 -> V_28 , V_17 -> V_27 ,
V_17 -> V_29 ) ;
V_77:
V_73:
F_4 ( V_1 , V_7 ) ;
V_71:
F_23 ( V_18 , L_7 , V_51 ) ;
if ( ! F_11 ( V_15 -> V_20 ) )
if ( V_21 )
F_12 ( V_18 , V_15 -> V_22 , V_21 ,
V_15 -> V_23 ) ;
V_70:
return V_51 ;
}
static int F_27 ( struct V_14 * V_15 , T_1 V_94 ,
int V_38 , struct V_39 * V_40 )
{
T_2 V_51 ;
T_2 V_42 = 0 ;
unsigned long V_95 ;
struct V_1 * V_1 = F_1 ( V_15 -> V_18 ) ;
struct V_3 * V_18 = & V_1 -> V_19 -> V_18 ;
F_28 ( & V_1 -> V_96 , V_95 ) ;
V_51 = F_17 ( V_15 , V_1 , V_38 , V_40 , & V_42 ) ;
if ( V_51 )
F_23 ( V_18 , L_8 , V_51 ) ;
if ( F_29 ( V_42 ) )
V_1 -> V_36 -> V_97 ( V_1 ) ;
F_30 ( & V_1 -> V_96 , V_95 ) ;
return V_51 ;
}
static void F_31 ( struct V_1 * V_1 , int V_98 )
{
struct V_99 * V_100 = & V_1 -> V_100 [ V_98 ] ;
struct V_101 * V_102 = & V_100 -> V_102 ;
struct V_103 * V_104 ;
if ( ! V_100 -> V_105 )
return;
V_104 = & V_1 -> V_106 ;
V_104 -> V_107 ( V_102 , V_108 ) ;
if ( V_102 -> V_100 ) {
struct V_102 * V_109 = V_102 -> V_100 ;
V_109 -> V_110 = V_102 -> V_111 ;
V_109 -> V_112 = V_100 -> V_112 ;
V_109 -> V_113 = V_114 ;
V_109 -> V_115 = V_100 -> V_115 ;
}
if ( V_100 -> V_116 & V_117 ) {
struct V_118 * V_66 ;
V_66 = (struct V_118 * ) V_100 -> V_119 ;
V_66 -> V_59 = V_100 -> V_120 . V_121 ;
V_66 -> V_122 = V_123 ;
V_66 -> V_124 = V_100 -> V_120 . V_125 ;
} else if ( V_100 -> V_116 & V_126 ) {
}
V_102 -> V_127 = V_100 -> V_127 ;
V_104 -> V_128 ( V_102 , V_129 ) ;
}
static struct V_43 * F_32 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_43 * V_44 = NULL ;
int V_13 ;
F_25 ( & V_1 -> V_96 ) ;
for ( V_13 = 0 ; V_13 < V_130 ; V_13 ++ ) {
if ( V_1 -> V_131 [ V_13 ] . V_59 == V_132 ) {
V_1 -> V_131 [ V_13 ] . V_62 = V_13 ;
V_44 = & V_1 -> V_131 [ V_13 ] ;
V_44 -> V_133 = V_134 ;
V_44 -> V_59 = V_3 -> V_59 ;
V_44 -> V_1 = V_1 ;
V_44 -> V_135 = V_3 ;
break;
}
}
F_26 ( & V_1 -> V_96 ) ;
return V_44 ;
}
static int F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_2 * V_136 = V_3 -> V_137 ;
struct V_43 * V_44 ;
struct V_3 * V_18 = & V_1 -> V_19 -> V_18 ;
V_44 = F_32 ( V_3 ) ;
if ( ! V_44 ) {
F_23 ( V_18 , L_9 ,
V_130 ) ;
return - V_85 ;
}
V_3 -> V_45 = V_44 ;
V_1 -> V_36 -> V_138 ( V_1 , V_44 ) ;
if ( V_136 && F_34 ( V_136 -> V_59 ) ) {
int V_98 ;
T_3 V_139 = V_136 -> V_140 . V_141 ;
struct V_142 * V_100 ;
for ( V_98 = 0 ; V_98 < V_139 ; V_98 ++ ) {
V_100 = & V_136 -> V_140 . V_142 [ V_98 ] ;
if ( F_20 ( V_100 -> V_143 ) ==
F_20 ( V_3 -> V_63 ) ) {
V_44 -> V_144 = V_98 ;
break;
}
}
if ( V_98 == V_139 ) {
F_19 ( V_18 , L_10
L_11 ,
F_20 ( V_3 -> V_63 ) ,
F_20 ( V_136 -> V_63 ) ) ;
return - V_85 ;
}
}
return 0 ;
}
static void F_35 ( struct V_145 * V_146 )
{
struct V_1 * V_1 = F_36 ( V_146 ) ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_1 -> V_147 ; ++ V_13 )
F_31 ( V_1 , V_13 ) ;
V_1 -> V_148 = 1 ;
}
static int F_37 ( struct V_145 * V_146 , unsigned long time )
{
struct V_1 * V_1 = F_36 ( V_146 ) ;
struct V_103 * V_106 = & V_1 -> V_106 ;
if ( V_1 -> V_148 == 0 )
return 0 ;
F_38 ( V_106 ) ;
return 1 ;
}
static void F_39 ( struct V_149 * V_150 )
{
struct V_99 * V_100 =
F_40 ( V_150 , struct V_99 , V_151 ) ;
struct V_1 * V_1 = V_100 -> V_1 ;
struct V_101 * V_102 = & V_100 -> V_102 ;
int V_98 = V_102 -> V_66 ;
V_1 -> V_36 -> V_152 ( V_1 , V_98 ) ;
F_31 ( V_1 , V_98 ) ;
}
static void F_41 ( struct V_1 * V_1 , int V_98 )
{
struct V_99 * V_100 = & V_1 -> V_100 [ V_98 ] ;
struct V_101 * V_102 = & V_100 -> V_102 ;
V_100 -> V_1 = V_1 ;
V_100 -> V_4 = NULL ;
F_42 ( & V_100 -> V_153 ) ;
V_102 -> V_154 = ( V_98 < V_1 -> V_147 ) ? 1 : 0 ;
V_102 -> V_155 = V_156 ;
V_102 -> V_157 = V_123 ;
V_102 -> V_158 = 0 ;
V_102 -> type = V_159 ;
V_102 -> V_160 = V_161 ;
V_102 -> V_162 = V_163 ;
V_102 -> V_111 = V_164 ;
V_102 -> V_66 = V_98 ;
V_102 -> V_63 = & V_1 -> V_63 [ 0 ] ;
V_102 -> V_119 = & V_100 -> V_119 [ 0 ] ;
V_102 -> V_5 = (struct V_103 * ) V_1 -> V_146 -> V_165 ;
V_102 -> V_166 = V_100 ;
F_43 ( & V_100 -> V_151 , F_39 ) ;
}
static void F_44 ( struct V_101 * V_102 )
{
struct V_103 * V_104 = V_102 -> V_5 ;
struct V_1 * V_1 = V_104 -> V_6 ;
struct V_99 * V_100 = V_102 -> V_166 ;
struct V_167 * V_168 = V_102 -> V_4 ;
struct V_46 * V_4 = & V_1 -> V_4 [ V_102 -> V_66 ] ;
unsigned long V_95 ;
if ( ! V_168 )
return;
F_28 ( & V_1 -> V_96 , V_95 ) ;
V_4 -> V_65 = 1 ;
V_4 -> V_66 = V_100 -> V_169 ;
V_100 -> V_4 = V_4 ;
V_168 -> V_64 = V_4 ;
F_30 ( & V_1 -> V_96 , V_95 ) ;
}
static void F_45 ( struct V_1 * V_1 , int V_98 ,
struct V_2 * V_3 )
{
struct V_99 * V_100 ;
struct V_46 * V_4 ;
struct V_16 * V_17 , * V_170 ;
struct V_3 * V_18 = & V_1 -> V_19 -> V_18 ;
V_100 = & V_1 -> V_100 [ V_98 ] ;
V_4 = V_100 -> V_4 ;
if ( ! V_4 )
return;
F_46 (slot, slot2, &port->list, entry) {
struct V_14 * V_15 ;
V_15 = V_17 -> V_15 ;
if ( V_3 && V_15 -> V_18 != V_3 )
continue;
F_19 ( V_18 , L_12 ,
V_17 -> V_50 , V_17 -> V_49 , V_15 ) ;
V_1 -> V_36 -> V_171 ( V_1 , V_17 , 1 ) ;
}
}
static void F_47 ( struct V_101 * V_102 )
{
struct V_2 * V_3 ;
struct V_99 * V_100 = V_102 -> V_166 ;
struct V_167 * V_168 = V_102 -> V_4 ;
F_48 (device, &sas_port->dev_list, dev_list_node)
F_45 ( V_100 -> V_1 , V_102 -> V_66 , V_3 ) ;
}
static void F_49 ( struct V_1 * V_1 ,
struct V_2 * V_3 )
{
struct V_167 * V_4 = V_3 -> V_4 ;
struct V_101 * V_102 ;
F_48 (sas_phy, &port->phy_list, port_phy_el)
F_45 ( V_1 , V_102 -> V_66 , V_3 ) ;
}
static void F_50 ( struct V_2 * V_3 )
{
struct V_43 * V_44 = V_3 -> V_45 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_3 * V_18 = & V_1 -> V_19 -> V_18 ;
T_4 V_172 = V_44 -> V_62 ;
F_19 ( V_18 , L_13 ,
V_44 -> V_62 , V_44 -> V_59 ) ;
V_1 -> V_36 -> V_173 ( V_1 , V_44 ) ;
V_3 -> V_45 = NULL ;
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
V_44 -> V_62 = V_172 ;
V_44 -> V_59 = V_132 ;
V_44 -> V_133 = V_134 ;
}
static int F_51 ( struct V_14 * V_15 , T_1 V_94 )
{
return F_27 ( V_15 , V_94 , 0 , NULL ) ;
}
static int F_52 ( struct V_101 * V_102 , enum V_174 V_175 ,
void * V_176 )
{
struct V_103 * V_104 = V_102 -> V_5 ;
struct V_1 * V_1 = V_104 -> V_6 ;
int V_98 = V_102 -> V_66 ;
switch ( V_175 ) {
case V_177 :
V_1 -> V_36 -> V_178 ( V_1 , V_98 ) ;
break;
case V_179 :
V_1 -> V_36 -> V_180 ( V_1 , V_98 ) ;
V_1 -> V_36 -> V_178 ( V_1 , V_98 ) ;
break;
case V_181 :
V_1 -> V_36 -> V_182 ( V_1 , V_98 ) ;
break;
case V_183 :
case V_184 :
default:
return - V_185 ;
}
return 0 ;
}
static void F_53 ( struct V_14 * V_15 )
{
if ( ! F_54 ( & V_15 -> V_186 -> V_153 ) )
return;
F_55 ( & V_15 -> V_186 -> V_187 ) ;
}
static void F_56 ( unsigned long V_188 )
{
struct V_14 * V_15 = (struct V_14 * ) V_188 ;
V_15 -> V_90 |= V_189 ;
F_55 ( & V_15 -> V_186 -> V_187 ) ;
}
static int F_57 ( struct V_2 * V_3 ,
void * V_190 , T_2 V_191 ,
struct V_39 * V_40 )
{
struct V_43 * V_44 = V_3 -> V_45 ;
struct V_1 * V_1 = V_44 -> V_1 ;
struct V_3 * V_18 = & V_1 -> V_19 -> V_18 ;
struct V_14 * V_15 ;
int V_192 , V_193 ;
for ( V_193 = 0 ; V_193 < V_194 ; V_193 ++ ) {
V_15 = F_58 ( V_195 ) ;
if ( ! V_15 )
return - V_69 ;
V_15 -> V_18 = V_3 ;
V_15 -> V_20 = V_3 -> V_158 ;
memcpy ( & V_15 -> V_196 , V_190 , V_191 ) ;
V_15 -> V_61 = F_53 ;
V_15 -> V_186 -> V_153 . V_188 = ( unsigned long ) V_15 ;
V_15 -> V_186 -> V_153 . V_197 = F_56 ;
V_15 -> V_186 -> V_153 . V_198 = V_199 + V_200 * V_201 ;
F_59 ( & V_15 -> V_186 -> V_153 ) ;
V_192 = F_27 ( V_15 , V_195 , 1 , V_40 ) ;
if ( V_192 ) {
F_54 ( & V_15 -> V_186 -> V_153 ) ;
F_23 ( V_18 , L_14 ,
V_192 ) ;
goto V_202;
}
F_60 ( & V_15 -> V_186 -> V_187 ) ;
V_192 = V_203 ;
if ( ( V_15 -> V_90 & V_189 ) ) {
if ( ! ( V_15 -> V_90 & V_204 ) ) {
F_23 ( V_18 , L_15 ,
V_40 -> V_205 ) ;
if ( V_15 -> V_34 ) {
struct V_16 * V_17 =
V_15 -> V_34 ;
F_10 ( V_1 ,
V_15 , V_17 ) ;
}
goto V_202;
}
}
if ( V_15 -> V_54 . V_55 == V_67 &&
V_15 -> V_54 . V_57 == V_206 ) {
V_192 = V_207 ;
break;
}
if ( V_15 -> V_54 . V_55 == V_67 &&
V_15 -> V_54 . V_57 == V_208 ) {
F_61 ( V_18 , L_16
L_17 ,
F_20 ( V_3 -> V_63 ) ,
V_15 -> V_54 . V_55 ,
V_15 -> V_54 . V_57 ) ;
V_192 = V_15 -> V_54 . V_209 ;
break;
}
if ( V_15 -> V_54 . V_55 == V_67 &&
V_15 -> V_54 . V_57 == V_210 ) {
F_61 ( V_18 , L_18 ) ;
V_192 = - V_211 ;
break;
}
F_61 ( V_18 , L_19
L_20 ,
F_20 ( V_3 -> V_63 ) , V_15 -> V_54 . V_55 ,
V_15 -> V_54 . V_57 ) ;
F_62 ( V_15 ) ;
V_15 = NULL ;
}
V_202:
F_63 ( V_193 == V_194 ) ;
F_62 ( V_15 ) ;
return V_192 ;
}
static int F_64 ( struct V_2 * V_3 ,
T_3 * V_212 , struct V_39 * V_40 )
{
struct V_213 V_196 ;
if ( ! ( V_3 -> V_158 & V_82 ) )
return V_214 ;
memcpy ( V_196 . V_215 , V_212 , 8 ) ;
return F_57 ( V_3 , & V_196 ,
sizeof( V_196 ) , V_40 ) ;
}
static int F_65 ( struct V_14 * V_15 )
{
struct V_216 V_212 ;
struct V_39 V_217 ;
struct V_2 * V_3 = V_15 -> V_18 ;
struct V_43 * V_44 = V_3 -> V_45 ;
struct V_1 * V_1 = F_1 ( V_15 -> V_18 ) ;
struct V_3 * V_18 = & V_1 -> V_19 -> V_18 ;
int V_51 = V_203 ;
unsigned long V_95 ;
if ( ! V_44 ) {
F_61 ( V_18 , L_21 ) ;
return V_203 ;
}
F_28 ( & V_15 -> V_89 , V_95 ) ;
if ( V_15 -> V_90 & V_204 ) {
F_30 ( & V_15 -> V_89 , V_95 ) ;
V_51 = V_207 ;
goto V_218;
}
F_30 ( & V_15 -> V_89 , V_95 ) ;
V_44 -> V_133 = V_219 ;
if ( V_15 -> V_34 && V_15 -> V_20 & V_82 ) {
struct V_220 * V_221 = V_15 -> V_222 ;
struct V_16 * V_17 = V_15 -> V_34 ;
T_2 V_223 = V_17 -> V_35 ;
F_66 ( V_221 -> V_3 -> V_212 , & V_212 ) ;
V_217 . V_40 = V_224 ;
V_217 . V_205 = F_67 ( V_223 ) ;
V_51 = F_64 ( V_15 -> V_18 , V_212 . V_216 ,
& V_217 ) ;
if ( V_51 == V_207 ) {
if ( V_15 -> V_34 ) {
struct V_16 * V_17 ;
V_17 = & V_1 -> V_74
[ V_217 . V_205 ] ;
F_28 ( & V_1 -> V_96 , V_95 ) ;
V_1 -> V_36 -> V_171 ( V_1 , V_17 , 1 ) ;
F_30 ( & V_1 -> V_96 , V_95 ) ;
}
}
} else if ( V_15 -> V_20 & V_83 ||
V_15 -> V_20 & V_84 ) {
if ( V_15 -> V_18 -> V_59 == V_60 ) {
struct V_225 * V_17 = V_15 -> V_34 ;
F_68 ( V_18 , L_22 ,
V_1 , V_15 , V_17 ) ;
V_15 -> V_90 |= V_189 ;
V_51 = V_207 ;
goto V_218;
}
}
V_218:
if ( V_51 != V_207 )
F_68 ( V_18 , L_23 , V_51 ) ;
return V_51 ;
}
static int F_69 ( struct V_2 * V_3 , T_3 * V_212 )
{
struct V_39 V_217 ;
int V_51 = V_203 ;
V_217 . V_40 = V_226 ;
V_51 = F_64 ( V_3 , V_212 , & V_217 ) ;
return V_51 ;
}
static int F_70 ( struct V_2 * V_3 , T_3 * V_212 )
{
int V_51 = V_203 ;
struct V_39 V_217 ;
V_217 . V_40 = V_227 ;
V_51 = F_64 ( V_3 , V_212 , & V_217 ) ;
return V_51 ;
}
static int F_71 ( struct V_2 * V_3 )
{
struct V_102 * V_100 = F_72 ( V_3 ) ;
int V_51 , V_228 = ( V_3 -> V_59 == V_60 ||
( V_3 -> V_158 & V_84 ) ) ? 0 : 1 ;
V_51 = F_73 ( V_100 , V_228 ) ;
F_74 ( V_100 ) ;
F_75 ( 2000 ) ;
return V_51 ;
}
static int F_76 ( struct V_2 * V_3 )
{
struct V_43 * V_44 = V_3 -> V_45 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned long V_95 ;
int V_51 = V_203 ;
if ( V_44 -> V_133 != V_219 )
return V_203 ;
V_44 -> V_133 = V_134 ;
V_51 = F_71 ( V_3 ) ;
F_28 ( & V_1 -> V_96 , V_95 ) ;
F_49 ( V_1 , V_3 ) ;
F_30 ( & V_1 -> V_96 , V_95 ) ;
return 0 ;
}
static int F_77 ( struct V_2 * V_3 , T_3 * V_212 )
{
struct V_39 V_217 ;
struct V_43 * V_44 = V_3 -> V_45 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_3 * V_18 = & V_1 -> V_19 -> V_18 ;
unsigned long V_95 ;
int V_51 = V_203 ;
V_217 . V_40 = V_229 ;
V_44 -> V_133 = V_219 ;
V_51 = F_64 ( V_3 , V_212 , & V_217 ) ;
if ( V_51 == V_207 ) {
F_28 ( & V_1 -> V_96 , V_95 ) ;
F_49 ( V_1 , V_3 ) ;
F_30 ( & V_1 -> V_96 , V_95 ) ;
}
F_23 ( V_18 , L_24 ,
V_44 -> V_62 , V_51 ) ;
return V_51 ;
}
static int F_78 ( struct V_14 * V_15 )
{
struct V_216 V_212 ;
struct V_39 V_217 ;
int V_51 = V_203 ;
if ( V_15 -> V_34 && V_15 -> V_20 & V_82 ) {
struct V_220 * V_221 = V_15 -> V_222 ;
struct V_2 * V_3 = V_15 -> V_18 ;
struct V_16 * V_17 = V_15 -> V_34 ;
T_2 V_223 = V_17 -> V_35 ;
F_66 ( V_221 -> V_3 -> V_212 , & V_212 ) ;
V_217 . V_40 = V_230 ;
V_217 . V_205 = F_67 ( V_223 ) ;
V_51 = F_64 ( V_3 ,
V_212 . V_216 ,
& V_217 ) ;
switch ( V_51 ) {
case V_231 :
case V_203 :
case V_207 :
break;
}
}
return V_51 ;
}
static void F_79 ( struct V_101 * V_102 )
{
F_44 ( V_102 ) ;
}
static void F_80 ( struct V_101 * V_102 )
{
F_47 ( V_102 ) ;
}
static void F_81 ( struct V_99 * V_100 )
{
V_100 -> V_105 = 0 ;
V_100 -> V_116 = 0 ;
V_100 -> V_4 = NULL ;
}
void F_82 ( struct V_1 * V_1 , int V_98 , int V_232 )
{
struct V_99 * V_100 = & V_1 -> V_100 [ V_98 ] ;
struct V_101 * V_102 = & V_100 -> V_102 ;
struct V_103 * V_104 = & V_1 -> V_106 ;
if ( V_232 ) {
F_31 ( V_1 , V_98 ) ;
F_44 ( V_102 ) ;
} else {
struct V_46 * V_4 = V_100 -> V_4 ;
V_104 -> V_107 ( V_102 , V_233 ) ;
F_83 ( V_102 ) ;
if ( V_4 ) {
if ( V_100 -> V_116 & V_117 ) {
int V_169 = V_4 -> V_66 ;
if ( ! V_1 -> V_36 -> V_234 ( V_1 ,
V_169 ) )
V_4 -> V_65 = 0 ;
} else if ( V_100 -> V_116 & V_126 )
V_4 -> V_65 = 0 ;
}
F_81 ( V_100 ) ;
}
}
static int F_84 ( struct V_1 * V_1 , struct V_145 * V_146 )
{
int V_13 , V_235 ;
struct V_236 * V_19 = V_1 -> V_19 ;
struct V_3 * V_18 = & V_19 -> V_18 ;
F_85 ( & V_1 -> V_96 ) ;
for ( V_13 = 0 ; V_13 < V_1 -> V_147 ; V_13 ++ ) {
F_41 ( V_1 , V_13 ) ;
V_1 -> V_4 [ V_13 ] . V_65 = 0 ;
V_1 -> V_4 [ V_13 ] . V_66 = - 1 ;
F_86 ( & V_1 -> V_4 [ V_13 ] . V_88 ) ;
}
for ( V_13 = 0 ; V_13 < V_130 ; V_13 ++ ) {
V_1 -> V_131 [ V_13 ] . V_59 = V_132 ;
V_1 -> V_131 [ V_13 ] . V_62 = V_13 ;
V_1 -> V_131 [ V_13 ] . V_133 = V_134 ;
}
for ( V_13 = 0 ; V_13 < V_1 -> V_237 ; V_13 ++ ) {
struct V_238 * V_239 = & V_1 -> V_239 [ V_13 ] ;
V_239 -> V_66 = V_13 ;
V_239 -> V_1 = V_1 ;
V_235 = sizeof( struct V_47 ) * V_240 ;
V_1 -> V_75 [ V_13 ] = F_87 ( V_18 , V_235 ,
& V_1 -> V_241 [ V_13 ] , V_195 ) ;
if ( ! V_1 -> V_75 [ V_13 ] )
goto V_71;
memset ( V_1 -> V_75 [ V_13 ] , 0 , V_235 ) ;
V_235 = V_1 -> V_36 -> V_242 * V_240 ;
V_1 -> V_243 [ V_13 ] = F_87 ( V_18 , V_235 ,
& V_1 -> V_244 [ V_13 ] , V_195 ) ;
if ( ! V_1 -> V_243 [ V_13 ] )
goto V_71;
memset ( V_1 -> V_243 [ V_13 ] , 0 , V_235 ) ;
}
V_235 = V_78 ;
V_1 -> V_28 = F_88 ( L_25 ,
V_18 , V_235 , 16 , 0 ) ;
if ( ! V_1 -> V_28 )
goto V_71;
V_235 = V_80 ;
V_1 -> V_25 = F_88 ( L_26 ,
V_18 , V_235 , 16 , 0 ) ;
if ( ! V_1 -> V_25 )
goto V_71;
V_235 = V_245 * sizeof( struct V_246 ) ;
V_1 -> V_247 = F_87 ( V_18 , V_235 , & V_1 -> V_248 ,
V_195 ) ;
if ( ! V_1 -> V_247 )
goto V_71;
memset ( V_1 -> V_247 , 0 , V_235 ) ;
V_1 -> V_74 = F_89 ( V_18 , V_249 ,
sizeof( struct V_16 ) ,
V_195 ) ;
if ( ! V_1 -> V_74 )
goto V_71;
V_235 = V_249 * sizeof( struct V_250 ) ;
V_1 -> V_251 = F_87 ( V_18 , V_235 , & V_1 -> V_252 ,
V_195 ) ;
if ( ! V_1 -> V_251 )
goto V_71;
memset ( V_1 -> V_251 , 0 , V_235 ) ;
V_235 = V_249 * sizeof( struct V_253 ) ;
V_1 -> V_254 = F_87 ( V_18 , V_235 ,
& V_1 -> V_255 , V_195 ) ;
if ( ! V_1 -> V_254 )
goto V_71;
memset ( V_1 -> V_254 , 0 , V_235 ) ;
V_1 -> V_11 = V_249 ;
V_235 = V_1 -> V_11 / sizeof( unsigned long ) ;
V_1 -> V_9 = F_90 ( V_18 , V_235 , V_195 ) ;
if ( ! V_1 -> V_9 )
goto V_71;
V_1 -> V_31 = F_88 ( L_27 , V_18 ,
sizeof( struct V_256 ) , 16 , 0 ) ;
if ( ! V_1 -> V_31 )
goto V_71;
V_235 = sizeof( struct V_257 ) * V_258 ;
V_1 -> V_259 = F_87 ( V_18 , V_235 ,
& V_1 -> V_260 , V_195 ) ;
if ( ! V_1 -> V_259 )
goto V_71;
memset ( V_1 -> V_259 , 0 , V_235 ) ;
V_235 = V_249 * sizeof( struct V_253 ) * 2 ;
V_1 -> V_261 = F_87 ( V_18 , V_235 ,
& V_1 -> V_262 , V_195 ) ;
if ( ! V_1 -> V_261 )
goto V_71;
memset ( V_1 -> V_261 , 0 , V_235 ) ;
F_9 ( V_1 ) ;
V_1 -> V_263 = F_91 ( F_92 ( V_18 ) ) ;
if ( ! V_1 -> V_263 ) {
F_23 ( V_18 , L_28 ) ;
goto V_71;
}
return 0 ;
V_71:
return - V_69 ;
}
static void F_93 ( struct V_1 * V_1 )
{
struct V_3 * V_18 = & V_1 -> V_19 -> V_18 ;
int V_13 , V_235 ;
for ( V_13 = 0 ; V_13 < V_1 -> V_237 ; V_13 ++ ) {
V_235 = sizeof( struct V_47 ) * V_240 ;
if ( V_1 -> V_75 [ V_13 ] )
F_94 ( V_18 , V_235 ,
V_1 -> V_75 [ V_13 ] ,
V_1 -> V_241 [ V_13 ] ) ;
V_235 = V_1 -> V_36 -> V_242 * V_240 ;
if ( V_1 -> V_243 [ V_13 ] )
F_94 ( V_18 , V_235 ,
V_1 -> V_243 [ V_13 ] ,
V_1 -> V_244 [ V_13 ] ) ;
}
F_95 ( V_1 -> V_28 ) ;
F_95 ( V_1 -> V_25 ) ;
F_95 ( V_1 -> V_31 ) ;
V_235 = V_245 * sizeof( struct V_246 ) ;
if ( V_1 -> V_247 )
F_94 ( V_18 , V_235 ,
V_1 -> V_247 , V_1 -> V_248 ) ;
V_235 = V_249 * sizeof( struct V_250 ) ;
if ( V_1 -> V_251 )
F_94 ( V_18 , V_235 ,
V_1 -> V_251 , V_1 -> V_252 ) ;
V_235 = V_249 * sizeof( struct V_253 ) ;
if ( V_1 -> V_254 )
F_94 ( V_18 , V_235 ,
V_1 -> V_254 ,
V_1 -> V_255 ) ;
V_235 = sizeof( struct V_257 ) * V_258 ;
if ( V_1 -> V_259 )
F_94 ( V_18 , V_235 ,
V_1 -> V_259 ,
V_1 -> V_260 ) ;
V_235 = V_249 * sizeof( struct V_253 ) * 2 ;
if ( V_1 -> V_261 )
F_94 ( V_18 , V_235 ,
V_1 -> V_261 ,
V_1 -> V_262 ) ;
if ( V_1 -> V_263 )
F_96 ( V_1 -> V_263 ) ;
}
static struct V_145 * F_97 ( struct V_236 * V_19 ,
const struct V_264 * V_36 )
{
struct V_265 * V_192 ;
struct V_145 * V_146 ;
struct V_1 * V_1 ;
struct V_3 * V_18 = & V_19 -> V_18 ;
struct V_266 * V_267 = V_19 -> V_18 . V_268 ;
struct V_269 * V_270 ;
V_146 = F_98 ( & V_271 , sizeof( * V_1 ) ) ;
if ( ! V_146 )
goto V_71;
V_1 = F_36 ( V_146 ) ;
V_1 -> V_36 = V_36 ;
V_1 -> V_19 = V_19 ;
V_1 -> V_146 = V_146 ;
F_99 ( V_146 ) = & V_1 -> V_106 ;
F_42 ( & V_1 -> V_153 ) ;
V_270 = F_100 ( V_267 , L_29 , NULL ) ;
if ( ! V_270 || ( V_270 -> V_272 != V_273 ) )
goto V_71;
memcpy ( V_1 -> V_63 , V_270 -> V_274 , V_273 ) ;
if ( F_101 ( V_267 , L_30 ,
& V_1 -> V_275 ) )
goto V_71;
if ( F_101 ( V_267 , L_31 ,
& V_1 -> V_276 ) )
goto V_71;
if ( F_101 ( V_267 , L_32 ,
& V_1 -> V_277 ) )
goto V_71;
if ( F_101 ( V_267 , L_33 , & V_1 -> V_147 ) )
goto V_71;
if ( F_101 ( V_267 , L_34 , & V_1 -> V_237 ) )
goto V_71;
V_192 = F_102 ( V_19 , V_278 , 0 ) ;
V_1 -> V_279 = F_103 ( V_18 , V_192 ) ;
if ( F_104 ( V_1 -> V_279 ) )
goto V_71;
V_1 -> V_280 = F_105 (
V_267 , L_35 ) ;
if ( F_104 ( V_1 -> V_280 ) )
goto V_71;
if ( F_84 ( V_1 , V_146 ) ) {
F_93 ( V_1 ) ;
goto V_71;
}
return V_146 ;
V_71:
F_23 ( V_18 , L_36 ) ;
return NULL ;
}
static void F_106 ( struct V_1 * V_1 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_1 -> V_147 ; V_13 ++ )
memcpy ( & V_1 -> V_100 [ V_13 ] . V_281 ,
V_1 -> V_63 ,
V_273 ) ;
}
int F_107 ( struct V_236 * V_19 ,
const struct V_264 * V_36 )
{
struct V_145 * V_146 ;
struct V_1 * V_1 ;
struct V_3 * V_18 = & V_19 -> V_18 ;
struct V_101 * * V_282 ;
struct V_167 * * V_283 ;
struct V_103 * V_106 ;
int V_51 , V_284 , V_285 , V_13 ;
V_146 = F_97 ( V_19 , V_36 ) ;
if ( ! V_146 ) {
V_51 = - V_69 ;
goto V_286;
}
V_106 = F_99 ( V_146 ) ;
V_1 = F_36 ( V_146 ) ;
F_108 ( V_19 , V_106 ) ;
if ( F_109 ( V_18 , F_110 ( 64 ) ) &&
F_109 ( V_18 , F_110 ( 32 ) ) ) {
F_23 ( V_18 , L_37 ) ;
V_51 = - V_287 ;
goto V_286;
}
V_284 = V_285 = V_1 -> V_147 ;
V_282 = F_89 ( V_18 , V_284 , sizeof( void * ) , V_195 ) ;
V_283 = F_89 ( V_18 , V_285 , sizeof( void * ) , V_195 ) ;
if ( ! V_282 || ! V_283 )
return - V_69 ;
V_106 -> V_102 = V_282 ;
V_106 -> V_168 = V_283 ;
V_106 -> V_288 . V_146 = V_146 ;
V_106 -> V_6 = V_1 ;
V_146 -> V_289 = V_290 ;
V_146 -> V_291 = V_130 ;
V_146 -> V_292 = ~ 0 ;
V_146 -> V_293 = 1 ;
V_146 -> V_294 = 16 ;
V_146 -> V_295 = F_111 ( V_296 , V_297 , V_298 ) ;
V_146 -> V_299 = V_249 ;
V_146 -> V_300 = V_249 ;
V_106 -> V_301 = V_302 ;
V_106 -> V_18 = & V_1 -> V_19 -> V_18 ;
V_106 -> V_303 = V_304 ;
V_106 -> V_63 = & V_1 -> V_63 [ 0 ] ;
V_106 -> V_141 = V_1 -> V_147 ;
V_106 -> V_288 . V_146 = V_1 -> V_146 ;
for ( V_13 = 0 ; V_13 < V_1 -> V_147 ; V_13 ++ ) {
V_106 -> V_102 [ V_13 ] = & V_1 -> V_100 [ V_13 ] . V_102 ;
V_106 -> V_168 [ V_13 ] = & V_1 -> V_4 [ V_13 ] . V_168 ;
}
F_106 ( V_1 ) ;
V_51 = V_1 -> V_36 -> V_305 ( V_1 ) ;
if ( V_51 )
goto V_286;
V_51 = F_112 ( V_146 , & V_19 -> V_18 ) ;
if ( V_51 )
goto V_286;
V_51 = F_113 ( V_106 ) ;
if ( V_51 )
goto V_306;
F_114 ( V_146 ) ;
return 0 ;
V_306:
F_115 ( V_146 ) ;
V_286:
F_116 ( V_146 ) ;
return V_51 ;
}
int F_117 ( struct V_236 * V_19 )
{
struct V_103 * V_106 = F_118 ( V_19 ) ;
struct V_1 * V_1 = V_106 -> V_6 ;
F_115 ( V_106 -> V_288 . V_146 ) ;
F_119 ( V_106 ) ;
F_120 ( V_106 -> V_288 . V_146 ) ;
F_93 ( V_1 ) ;
return 0 ;
}
static T_5 int F_121 ( void )
{
F_122 ( L_38 , V_307 ) ;
V_290 = F_123 ( & V_308 ) ;
if ( ! V_290 )
return - V_69 ;
return 0 ;
}
static T_6 void F_124 ( void )
{
F_125 ( V_290 ) ;
}
