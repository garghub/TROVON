static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_10 ;
int V_11 ;
struct V_12 * V_13 ;
F_2 ( & V_2 -> V_14 ) ;
F_3 ( V_15 , & V_2 -> V_14 ) ;
V_2 -> V_16 = F_4 ( V_9 -> V_17 -> V_4 ,
V_18 ,
& V_2 -> V_19 , V_20 ,
& V_2 -> V_14 ) ;
if ( ! V_2 -> V_16 ) {
F_5 ( V_4 , L_1 ) ;
return - V_21 ;
}
V_6 = F_6 ( V_22 , sizeof( * V_6 ) , V_20 ) ;
if ( ! V_6 ) {
F_5 ( V_4 , L_2 ) ;
V_11 = - V_21 ;
goto V_23;
}
for ( V_10 = 0 ; V_10 < V_22 ; V_10 ++ ) {
unsigned int V_24 ;
V_6 [ V_10 ] . V_25 =
V_2 -> V_16 + V_10 * V_26 ;
V_6 [ V_10 ] . V_27 =
V_2 -> V_19 + V_10 * V_26 ;
V_13 = & V_6 [ V_10 ] . V_13 ;
for ( V_24 = 0 ; V_24 < V_28 ; V_24 ++ )
V_13 -> V_29 [ V_24 ] = V_30 ;
F_7 ( & V_6 [ V_10 ] . V_31 , & V_2 -> V_32 ) ;
}
return 0 ;
V_23:
F_8 ( V_9 -> V_17 -> V_4 , V_18 ,
V_2 -> V_16 ,
V_2 -> V_19 , & V_2 -> V_14 ) ;
return V_11 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
F_10 ( V_2 -> V_7 ) ;
F_8 ( V_9 -> V_17 -> V_4 , V_18 ,
V_2 -> V_16 ,
V_2 -> V_19 , & V_2 -> V_14 ) ;
}
static struct V_5 * F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
F_12 ( & V_2 -> V_33 ) ;
if ( F_13 ( & V_2 -> V_32 ) ) {
F_5 ( V_4 , L_3 ) ;
F_14 ( & V_2 -> V_33 ) ;
return NULL ;
}
V_6 = F_15 ( & V_2 -> V_32 , struct V_5 ,
V_31 ) ;
F_16 ( & V_6 -> V_31 ) ;
F_14 ( & V_2 -> V_33 ) ;
return V_6 ;
}
static void F_17 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
F_12 ( & V_2 -> V_33 ) ;
F_18 ( & V_6 -> V_31 , & V_2 -> V_32 ) ;
F_14 ( & V_2 -> V_33 ) ;
}
static void F_19 ( struct V_34 * V_35 ,
struct V_5 * V_6 )
{
struct V_5 * V_36 ;
if ( F_13 ( & V_35 -> V_37 ) )
goto V_38;
V_36 = F_20 ( V_35 -> V_37 . V_39 ,
struct V_5 , V_31 ) ;
V_36 -> V_25 -> V_40 [ V_36 -> V_25 -> V_41 ] = V_6 -> V_27 ;
V_38:
F_7 ( & V_6 -> V_31 , & V_35 -> V_37 ) ;
if ( V_6 -> V_42 )
F_7 ( & V_6 -> V_42 -> V_43 . V_44 , & V_35 -> V_45 ) ;
}
static void F_21 ( struct V_46 * V_17 ,
unsigned long V_47 ,
bool V_48 )
{
struct V_49 * V_50 =
(struct V_49 * ) V_47 ;
if ( ! V_47 )
return;
if ( V_48 )
goto V_51;
F_22 ( & V_50 -> V_52 ) ;
if ( F_23 ( & V_50 -> V_52 ) > 0 )
return;
if ( V_50 -> V_53 )
return;
V_51:
F_24 ( V_17 , V_50 -> V_54 ,
V_55 ) ;
F_25 ( V_50 -> V_56 ,
V_50 -> V_57 ,
V_50 -> V_58 ) ;
F_26 ( V_50 -> V_58 ) ;
if ( ! V_50 -> V_59 )
F_16 ( & V_50 -> V_31 ) ;
F_27 ( V_50 -> V_54 ) ;
F_10 ( V_50 -> V_54 ) ;
F_28 ( V_50 -> V_56 ) ;
F_10 ( V_50 ) ;
}
static T_1 * F_29 ( struct V_46 * V_17 ,
unsigned long V_60 ,
unsigned long V_61 ,
struct V_62 * V_63 ,
unsigned long * V_47 )
{
struct V_64 * V_65 = V_63 -> V_66 ;
struct V_34 * V_35 = V_65 -> V_35 ;
struct V_49 * V_50 ;
struct V_1 * V_2 ;
struct V_67 * * V_56 ;
struct V_68 * V_54 ;
struct V_69 * V_58 ;
unsigned long V_70 , V_71 ;
unsigned int V_57 , V_72 ;
int V_11 ;
if ( ! V_61 ) {
F_30 ( L_4 ) ;
return F_31 ( - V_73 ) ;
}
V_2 = F_32 ( V_35 -> V_4 ) ;
F_33 (g2d_userptr, &g2d_priv->userptr_list, list) {
if ( V_50 -> V_60 == V_60 ) {
if ( V_50 -> V_61 == V_61 ) {
F_34 ( & V_50 -> V_52 ) ;
* V_47 = ( unsigned long ) V_50 ;
return & V_50 -> V_27 ;
}
V_50 -> V_59 = true ;
V_50 -> V_53 = false ;
F_16 ( & V_50 -> V_31 ) ;
break;
}
}
V_50 = F_35 ( sizeof( * V_50 ) , V_20 ) ;
if ( ! V_50 )
return F_31 ( - V_21 ) ;
F_36 ( & V_50 -> V_52 , 1 ) ;
V_70 = V_60 & V_74 ;
V_72 = V_60 & ~ V_74 ;
V_71 = F_37 ( V_60 + V_61 ) ;
V_57 = ( V_71 - V_70 ) >> V_75 ;
V_50 -> V_57 = V_57 ;
V_56 = F_38 ( V_57 , sizeof( struct V_67 * ) ) ;
if ( ! V_56 ) {
F_30 ( L_5 ) ;
V_11 = - V_21 ;
goto V_76;
}
F_39 ( & V_77 -> V_78 -> V_79 ) ;
V_58 = F_40 ( V_77 -> V_78 , V_60 ) ;
if ( ! V_58 ) {
F_41 ( & V_77 -> V_78 -> V_79 ) ;
F_30 ( L_6 ) ;
V_11 = - V_80 ;
goto V_81;
}
if ( V_58 -> V_82 < V_60 + V_61 ) {
F_41 ( & V_77 -> V_78 -> V_79 ) ;
F_30 ( L_7 ) ;
V_11 = - V_80 ;
goto V_81;
}
V_50 -> V_58 = F_42 ( V_58 ) ;
if ( ! V_50 -> V_58 ) {
F_41 ( & V_77 -> V_78 -> V_79 ) ;
F_30 ( L_8 ) ;
V_11 = - V_21 ;
goto V_81;
}
V_50 -> V_61 = V_61 ;
V_11 = F_43 ( V_70 & V_74 ,
V_57 , V_56 , V_58 ) ;
if ( V_11 < 0 ) {
F_41 ( & V_77 -> V_78 -> V_79 ) ;
F_30 ( L_9 ) ;
goto V_83;
}
F_41 ( & V_77 -> V_78 -> V_79 ) ;
V_50 -> V_56 = V_56 ;
V_54 = F_35 ( sizeof( * V_54 ) , V_20 ) ;
if ( ! V_54 ) {
V_11 = - V_21 ;
goto V_84;
}
V_11 = F_44 ( V_54 , V_56 , V_57 , V_72 ,
V_61 , V_20 ) ;
if ( V_11 < 0 ) {
F_30 ( L_10 ) ;
goto V_85;
}
V_50 -> V_54 = V_54 ;
V_11 = F_45 ( V_17 , V_50 -> V_54 ,
V_55 ) ;
if ( V_11 < 0 ) {
F_30 ( L_11 ) ;
goto V_86;
}
V_50 -> V_27 = V_54 -> V_87 [ 0 ] . V_88 ;
V_50 -> V_60 = V_60 ;
F_7 ( & V_50 -> V_31 , & V_35 -> V_89 ) ;
if ( V_2 -> V_90 + ( V_57 << V_75 ) < V_2 -> V_91 ) {
V_2 -> V_90 += V_57 << V_75 ;
V_50 -> V_53 = true ;
}
* V_47 = ( unsigned long ) V_50 ;
return & V_50 -> V_27 ;
V_86:
F_27 ( V_54 ) ;
V_85:
F_10 ( V_54 ) ;
V_84:
F_25 ( V_50 -> V_56 ,
V_50 -> V_57 ,
V_50 -> V_58 ) ;
V_83:
F_26 ( V_50 -> V_58 ) ;
V_81:
F_28 ( V_56 ) ;
V_76:
F_10 ( V_50 ) ;
return F_31 ( V_11 ) ;
}
static void F_46 ( struct V_46 * V_17 ,
struct V_1 * V_2 ,
struct V_62 * V_63 )
{
struct V_64 * V_65 = V_63 -> V_66 ;
struct V_34 * V_35 = V_65 -> V_35 ;
struct V_49 * V_50 , * V_92 ;
F_47 (g2d_userptr, n, &g2d_priv->userptr_list, list)
if ( V_50 -> V_53 )
F_21 ( V_17 ,
( unsigned long ) V_50 ,
true ) ;
V_2 -> V_90 = 0 ;
}
static enum V_93 F_48 ( int V_94 )
{
enum V_93 V_95 ;
switch ( V_94 ) {
case V_96 :
case V_97 :
case V_98 :
case V_99 :
V_95 = V_100 ;
break;
case V_101 :
V_95 = V_102 ;
break;
case V_103 :
case V_104 :
case V_105 :
case V_106 :
V_95 = V_107 ;
break;
case V_108 :
V_95 = V_109 ;
break;
case V_110 :
V_95 = V_111 ;
break;
case V_112 :
V_95 = V_113 ;
break;
default:
V_95 = V_30 ;
F_30 ( L_12 , V_94 ) ;
break;
}
return V_95 ;
}
static unsigned long F_49 ( unsigned int V_114 )
{
unsigned long V_115 ;
switch ( V_114 ) {
case V_116 :
case V_117 :
V_115 = 4 ;
break;
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
V_115 = 2 ;
break;
case V_123 :
V_115 = 3 ;
break;
default:
V_115 = 1 ;
break;
}
return V_115 ;
}
static bool F_50 ( struct V_124 * V_125 ,
enum V_93 V_95 ,
unsigned long V_61 )
{
unsigned int V_126 , V_127 ;
unsigned long V_128 ;
if ( V_95 != V_100 && V_95 != V_107 )
return true ;
V_126 = V_125 -> V_129 - V_125 -> V_130 ;
if ( V_126 < V_131 || V_126 > V_132 ) {
F_30 ( L_13 , V_126 ) ;
return false ;
}
V_127 = V_125 -> V_133 - V_125 -> V_134 ;
if ( V_127 < V_131 || V_127 > V_132 ) {
F_30 ( L_14 , V_127 ) ;
return false ;
}
V_128 = ( unsigned long ) V_126 * ( unsigned long ) V_127 *
F_49 ( V_125 -> V_114 ) ;
if ( V_128 > V_61 ) {
F_30 ( L_15 , V_128 , V_61 ) ;
return false ;
}
return true ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_46 * V_17 ,
struct V_62 * V_135 )
{
struct V_136 * V_25 = V_6 -> V_25 ;
struct V_12 * V_13 = & V_6 -> V_13 ;
int V_72 ;
int V_11 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_13 -> V_137 ; V_24 ++ ) {
struct V_124 * V_125 ;
enum V_93 V_95 ;
int V_138 ;
unsigned long V_139 ;
T_1 * V_140 ;
V_138 = V_25 -> V_41 - 2 * ( V_24 + 1 ) ;
V_72 = V_25 -> V_40 [ V_138 ] ;
V_139 = V_25 -> V_40 [ V_138 + 1 ] ;
V_95 = F_48 ( V_72 ) ;
if ( V_95 == V_30 ) {
V_11 = - V_80 ;
goto V_23;
}
V_125 = & V_13 -> V_141 [ V_95 ] ;
if ( V_13 -> V_142 [ V_95 ] == V_143 ) {
unsigned long V_61 ;
V_61 = F_52 ( V_17 , V_139 , V_135 ) ;
if ( ! V_61 ) {
V_11 = - V_80 ;
goto V_23;
}
if ( ! F_50 ( V_125 , V_95 ,
V_61 ) ) {
V_11 = - V_80 ;
goto V_23;
}
V_140 = F_53 ( V_17 , V_139 ,
V_135 ) ;
if ( F_54 ( V_140 ) ) {
V_11 = - V_80 ;
goto V_23;
}
} else {
struct V_144 V_50 ;
if ( F_55 ( & V_50 , ( void V_145 * ) V_139 ,
sizeof( struct V_144 ) ) ) {
V_11 = - V_80 ;
goto V_23;
}
if ( ! F_50 ( V_125 , V_95 ,
V_50 . V_61 ) ) {
V_11 = - V_80 ;
goto V_23;
}
V_140 = F_29 ( V_17 ,
V_50 . V_60 ,
V_50 . V_61 ,
V_135 ,
& V_139 ) ;
if ( F_54 ( V_140 ) ) {
V_11 = - V_80 ;
goto V_23;
}
}
V_25 -> V_40 [ V_138 + 1 ] = * V_140 ;
V_13 -> V_29 [ V_24 ] = V_95 ;
V_13 -> V_146 [ V_95 ] = V_139 ;
}
return 0 ;
V_23:
V_13 -> V_137 = V_24 ;
return V_11 ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_62 * V_63 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_12 * V_13 = & V_6 -> V_13 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_13 -> V_137 ; V_24 ++ ) {
struct V_124 * V_125 ;
enum V_93 V_95 ;
unsigned long V_139 ;
V_95 = V_13 -> V_29 [ V_24 ] ;
V_125 = & V_13 -> V_141 [ V_95 ] ;
V_139 = V_13 -> V_146 [ V_95 ] ;
if ( V_13 -> V_142 [ V_95 ] == V_143 )
F_57 ( V_9 -> V_17 , V_139 ,
V_63 ) ;
else
F_21 ( V_9 -> V_17 , V_139 ,
false ) ;
V_13 -> V_29 [ V_24 ] = V_30 ;
V_13 -> V_146 [ V_95 ] = 0 ;
V_13 -> V_142 [ V_95 ] = 0 ;
memset ( V_125 , 0x00 , sizeof( * V_125 ) ) ;
}
V_13 -> V_137 = 0 ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_147 * V_148 )
{
struct V_5 * V_6 =
F_15 ( & V_148 -> V_149 ,
struct V_5 , V_31 ) ;
int V_11 ;
V_11 = F_59 ( V_2 -> V_4 ) ;
if ( V_11 < 0 )
return;
F_60 ( V_6 -> V_27 , V_2 -> V_150 + V_151 ) ;
F_60 ( V_152 , V_2 -> V_150 + V_153 ) ;
}
static struct V_147 * F_61 ( struct V_1 * V_2 )
{
struct V_147 * V_148 ;
if ( F_13 ( & V_2 -> V_154 ) )
return NULL ;
V_148 = F_15 ( & V_2 -> V_154 ,
struct V_147 , V_31 ) ;
F_16 ( & V_148 -> V_31 ) ;
return V_148 ;
}
static void F_62 ( struct V_1 * V_2 ,
struct V_147 * V_148 )
{
struct V_5 * V_6 ;
if ( ! V_148 )
return;
F_12 ( & V_2 -> V_33 ) ;
F_33 (node, &runqueue_node->run_cmdlist, list)
F_56 ( V_2 , V_6 , V_148 -> V_63 ) ;
F_63 ( & V_148 -> V_149 , & V_2 -> V_32 ) ;
F_14 ( & V_2 -> V_33 ) ;
F_64 ( V_2 -> V_155 , V_148 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
V_2 -> V_148 = F_61 ( V_2 ) ;
if ( V_2 -> V_148 )
F_58 ( V_2 , V_2 -> V_148 ) ;
}
static void F_66 ( struct V_156 * V_157 )
{
struct V_1 * V_2 = F_67 ( V_157 , struct V_1 ,
V_158 ) ;
F_12 ( & V_2 -> V_159 ) ;
F_68 ( V_2 -> V_4 ) ;
F_69 ( & V_2 -> V_148 -> F_69 ) ;
if ( V_2 -> V_148 -> V_160 )
F_62 ( V_2 , V_2 -> V_148 ) ;
if ( V_2 -> V_161 )
V_2 -> V_148 = NULL ;
else
F_65 ( V_2 ) ;
F_14 ( & V_2 -> V_159 ) ;
}
static void F_70 ( struct V_1 * V_2 , T_2 V_162 )
{
struct V_46 * V_17 = V_2 -> V_9 . V_17 ;
struct V_147 * V_148 = V_2 -> V_148 ;
struct V_163 * V_164 ;
struct V_165 V_166 ;
unsigned long V_167 ;
if ( F_13 ( & V_148 -> V_45 ) )
return;
V_164 = F_15 ( & V_148 -> V_45 ,
struct V_163 , V_43 . V_44 ) ;
F_71 ( & V_166 ) ;
V_164 -> V_42 . V_168 = V_166 . V_168 ;
V_164 -> V_42 . V_169 = V_166 . V_169 ;
V_164 -> V_42 . V_162 = V_162 ;
F_72 ( & V_17 -> V_170 , V_167 ) ;
F_18 ( & V_164 -> V_43 . V_44 , & V_164 -> V_43 . V_65 -> V_45 ) ;
F_73 ( & V_164 -> V_43 . V_65 -> V_171 ) ;
F_74 ( & V_17 -> V_170 , V_167 ) ;
}
static T_3 F_75 ( int V_172 , void * V_173 )
{
struct V_1 * V_2 = V_173 ;
T_2 V_174 ;
V_174 = F_76 ( V_2 -> V_150 + V_175 ) ;
if ( V_174 )
F_60 ( V_174 , V_2 -> V_150 + V_175 ) ;
if ( V_174 & V_176 ) {
T_2 V_162 = F_76 ( V_2 -> V_150 + V_177 ) ;
V_162 = ( V_162 & V_178 ) >>
V_179 ;
F_70 ( V_2 , V_162 ) ;
F_60 ( 0 , V_2 -> V_150 + V_180 ) ;
if ( ! ( V_174 & V_181 ) ) {
F_60 ( V_182 ,
V_2 -> V_150 + V_153 ) ;
}
}
if ( V_174 & V_181 )
F_77 ( V_2 -> V_183 , & V_2 -> V_158 ) ;
return V_184 ;
}
static int F_78 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
int V_10 , bool V_185 )
{
struct V_136 * V_25 = V_6 -> V_25 ;
int V_94 ;
int V_186 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_10 ; V_24 ++ ) {
struct V_12 * V_13 = & V_6 -> V_13 ;
struct V_124 * V_125 ;
enum V_93 V_95 ;
unsigned long V_187 ;
V_186 = V_25 -> V_41 - 2 * ( V_24 + 1 ) ;
V_94 = V_25 -> V_40 [ V_186 ] & ~ 0xfffff000 ;
if ( V_94 < V_188 || V_94 > V_189 )
goto V_23;
if ( V_94 % 4 )
goto V_23;
switch ( V_94 ) {
case V_96 :
case V_101 :
case V_103 :
case V_108 :
case V_110 :
case V_112 :
if ( ! V_185 )
goto V_23;
V_95 = F_48 ( V_94 ) ;
if ( V_95 == V_30 )
goto V_23;
if ( ( V_25 -> V_40 [ V_186 ] & ~ 0x7fffffff ) >> 31 ) {
V_13 -> V_142 [ V_95 ] = V_190 ;
V_25 -> V_40 [ V_186 ] &= ~ V_191 ;
} else
V_13 -> V_142 [ V_95 ] = V_143 ;
break;
case V_97 :
case V_104 :
if ( V_185 )
goto V_23;
V_95 = F_48 ( V_94 ) ;
if ( V_95 == V_30 )
goto V_23;
V_125 = & V_13 -> V_141 [ V_95 ] ;
V_187 = V_25 -> V_40 [ V_186 + 1 ] ;
V_125 -> V_114 = V_187 & 0xf ;
break;
case V_98 :
case V_105 :
if ( V_185 )
goto V_23;
V_95 = F_48 ( V_94 ) ;
if ( V_95 == V_30 )
goto V_23;
V_125 = & V_13 -> V_141 [ V_95 ] ;
V_187 = V_25 -> V_40 [ V_186 + 1 ] ;
V_125 -> V_130 = V_187 & 0x1fff ;
V_125 -> V_134 = ( V_187 & 0x1fff0000 ) >> 16 ;
break;
case V_99 :
case V_106 :
if ( V_185 )
goto V_23;
V_95 = F_48 ( V_94 ) ;
if ( V_95 == V_30 )
goto V_23;
V_125 = & V_13 -> V_141 [ V_95 ] ;
V_187 = V_25 -> V_40 [ V_186 + 1 ] ;
V_125 -> V_129 = V_187 & 0x1fff ;
V_125 -> V_133 = ( V_187 & 0x1fff0000 ) >> 16 ;
break;
default:
if ( V_185 )
goto V_23;
break;
}
}
return 0 ;
V_23:
F_5 ( V_4 , L_16 , V_25 -> V_40 [ V_186 ] ) ;
return - V_73 ;
}
int F_79 ( struct V_46 * V_17 , void * V_40 ,
struct V_62 * V_135 )
{
struct V_192 * V_193 = V_40 ;
V_193 -> V_194 = V_195 ;
V_193 -> V_196 = V_197 ;
return 0 ;
}
int F_80 ( struct V_46 * V_17 , void * V_40 ,
struct V_62 * V_135 )
{
struct V_64 * V_65 = V_135 -> V_66 ;
struct V_34 * V_35 = V_65 -> V_35 ;
struct V_3 * V_4 = V_35 -> V_4 ;
struct V_1 * V_2 ;
struct V_198 * V_199 = V_40 ;
struct V_200 * V_201 ;
struct V_163 * V_164 ;
struct V_5 * V_6 ;
struct V_136 * V_25 ;
unsigned long V_167 ;
int V_61 ;
int V_11 ;
if ( ! V_4 )
return - V_202 ;
V_2 = F_32 ( V_4 ) ;
if ( ! V_2 )
return - V_80 ;
V_6 = F_11 ( V_2 ) ;
if ( ! V_6 )
return - V_21 ;
V_6 -> V_42 = NULL ;
if ( V_199 -> V_203 != V_204 ) {
F_72 ( & V_17 -> V_170 , V_167 ) ;
if ( V_135 -> V_205 < sizeof( V_164 -> V_42 ) ) {
F_74 ( & V_17 -> V_170 , V_167 ) ;
V_11 = - V_21 ;
goto V_23;
}
V_135 -> V_205 -= sizeof( V_164 -> V_42 ) ;
F_74 ( & V_17 -> V_170 , V_167 ) ;
V_164 = F_35 ( sizeof( * V_6 -> V_42 ) , V_20 ) ;
if ( ! V_164 ) {
F_72 ( & V_17 -> V_170 , V_167 ) ;
V_135 -> V_205 += sizeof( V_164 -> V_42 ) ;
F_74 ( & V_17 -> V_170 , V_167 ) ;
V_11 = - V_21 ;
goto V_23;
}
V_164 -> V_42 . V_43 . type = V_206 ;
V_164 -> V_42 . V_43 . V_207 = sizeof( V_164 -> V_42 ) ;
V_164 -> V_42 . V_208 = V_199 -> V_208 ;
V_164 -> V_43 . V_42 = & V_164 -> V_42 . V_43 ;
V_164 -> V_43 . V_65 = V_135 ;
V_164 -> V_43 . V_209 = ( void ( * ) ( struct V_210 * ) ) F_10 ;
V_6 -> V_42 = V_164 ;
}
V_25 = V_6 -> V_25 ;
V_25 -> V_41 = 0 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_211 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_212 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_96 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = 0 ;
if ( V_6 -> V_42 ) {
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_213 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_214 | V_215 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_180 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_216 ;
} else {
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_213 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_214 ;
}
V_61 = V_25 -> V_41 + V_199 -> V_217 * 2 + V_199 -> V_218 * 2 + 2 ;
if ( V_61 > V_219 ) {
F_5 ( V_4 , L_17 ) ;
V_11 = - V_73 ;
goto V_220;
}
V_201 = (struct V_200 * ) ( V_221 ) V_199 -> V_201 ;
if ( F_55 ( V_25 -> V_40 + V_25 -> V_41 ,
( void V_145 * ) V_201 ,
sizeof( * V_201 ) * V_199 -> V_217 ) ) {
V_11 = - V_80 ;
goto V_220;
}
V_25 -> V_41 += V_199 -> V_217 * 2 ;
V_11 = F_78 ( V_4 , V_6 , V_199 -> V_217 , false ) ;
if ( V_11 < 0 )
goto V_220;
V_6 -> V_13 . V_137 = V_199 -> V_218 ;
if ( V_199 -> V_218 ) {
struct V_200 * V_222 ;
V_222 = (struct V_200 * ) ( V_221 ) V_199 -> V_222 ;
if ( F_55 ( V_25 -> V_40 + V_25 -> V_41 ,
( void V_145 * ) V_222 ,
sizeof( * V_222 ) * V_199 -> V_218 ) ) {
V_11 = - V_80 ;
goto V_220;
}
V_25 -> V_41 += V_199 -> V_218 * 2 ;
V_11 = F_78 ( V_4 , V_6 , V_199 -> V_218 , true ) ;
if ( V_11 < 0 )
goto V_220;
V_11 = F_51 ( V_2 , V_6 , V_17 , V_135 ) ;
if ( V_11 < 0 )
goto V_223;
}
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_224 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_225 ;
V_25 -> V_226 = V_25 -> V_41 / 2 ;
V_25 -> V_40 [ V_25 -> V_41 ] = 0 ;
F_19 ( V_35 , V_6 ) ;
return 0 ;
V_223:
F_56 ( V_2 , V_6 , V_135 ) ;
V_220:
if ( V_6 -> V_42 ) {
F_72 ( & V_17 -> V_170 , V_167 ) ;
V_135 -> V_205 += sizeof( V_164 -> V_42 ) ;
F_74 ( & V_17 -> V_170 , V_167 ) ;
F_10 ( V_6 -> V_42 ) ;
}
V_23:
F_17 ( V_2 , V_6 ) ;
return V_11 ;
}
int F_81 ( struct V_46 * V_17 , void * V_40 ,
struct V_62 * V_135 )
{
struct V_64 * V_65 = V_135 -> V_66 ;
struct V_34 * V_35 = V_65 -> V_35 ;
struct V_3 * V_4 = V_35 -> V_4 ;
struct V_1 * V_2 ;
struct V_227 * V_199 = V_40 ;
struct V_147 * V_148 ;
struct V_228 * V_149 ;
struct V_228 * V_45 ;
if ( ! V_4 )
return - V_202 ;
V_2 = F_32 ( V_4 ) ;
if ( ! V_2 )
return - V_80 ;
V_148 = F_82 ( V_2 -> V_155 , V_20 ) ;
if ( ! V_148 ) {
F_5 ( V_4 , L_2 ) ;
return - V_21 ;
}
V_149 = & V_148 -> V_149 ;
V_45 = & V_148 -> V_45 ;
F_83 ( V_149 ) ;
F_83 ( V_45 ) ;
F_84 ( & V_148 -> F_69 ) ;
V_148 -> V_160 = V_199 -> V_160 ;
F_85 ( & V_35 -> V_37 , V_149 ) ;
F_85 ( & V_35 -> V_45 , V_45 ) ;
if ( F_13 ( V_149 ) ) {
F_5 ( V_4 , L_18 ) ;
F_64 ( V_2 -> V_155 , V_148 ) ;
return - V_229 ;
}
F_12 ( & V_2 -> V_159 ) ;
V_148 -> V_230 = V_77 -> V_230 ;
V_148 -> V_63 = V_135 ;
F_7 ( & V_148 -> V_31 , & V_2 -> V_154 ) ;
if ( ! V_2 -> V_148 )
F_65 ( V_2 ) ;
F_14 ( & V_2 -> V_159 ) ;
if ( V_148 -> V_160 )
goto V_51;
F_86 ( & V_148 -> F_69 ) ;
F_62 ( V_2 , V_148 ) ;
V_51:
return 0 ;
}
static int F_87 ( struct V_46 * V_17 , struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_11 ;
V_2 = F_32 ( V_4 ) ;
if ( ! V_2 )
return - V_80 ;
V_11 = F_1 ( V_2 ) ;
if ( V_11 < 0 ) {
F_5 ( V_4 , L_19 ) ;
return V_11 ;
}
if ( ! F_88 ( V_17 ) )
return 0 ;
V_11 = F_89 ( V_17 , V_4 ) ;
if ( V_11 < 0 ) {
F_5 ( V_4 , L_20 ) ;
F_9 ( V_2 ) ;
}
return V_11 ;
}
static void F_90 ( struct V_46 * V_17 , struct V_3 * V_4 )
{
if ( ! F_88 ( V_17 ) )
return;
F_91 ( V_17 , V_4 ) ;
}
static int F_92 ( struct V_46 * V_17 , struct V_3 * V_4 ,
struct V_62 * V_135 )
{
struct V_64 * V_65 = V_135 -> V_66 ;
struct V_34 * V_35 ;
V_35 = F_35 ( sizeof( * V_35 ) , V_20 ) ;
if ( ! V_35 )
return - V_21 ;
V_35 -> V_4 = V_4 ;
V_65 -> V_35 = V_35 ;
F_83 ( & V_35 -> V_37 ) ;
F_83 ( & V_35 -> V_45 ) ;
F_83 ( & V_35 -> V_89 ) ;
return 0 ;
}
static void F_93 ( struct V_46 * V_17 , struct V_3 * V_4 ,
struct V_62 * V_135 )
{
struct V_64 * V_65 = V_135 -> V_66 ;
struct V_34 * V_35 = V_65 -> V_35 ;
struct V_1 * V_2 ;
struct V_5 * V_6 , * V_92 ;
if ( ! V_4 )
return;
V_2 = F_32 ( V_4 ) ;
if ( ! V_2 )
return;
F_12 ( & V_2 -> V_33 ) ;
F_47 (node, n, &g2d_priv->inuse_cmdlist, list) {
F_56 ( V_2 , V_6 , V_135 ) ;
F_18 ( & V_6 -> V_31 , & V_2 -> V_32 ) ;
}
F_14 ( & V_2 -> V_33 ) ;
F_46 ( V_17 , V_2 , V_135 ) ;
F_10 ( V_65 -> V_35 ) ;
}
static int F_94 ( struct V_231 * V_232 )
{
struct V_3 * V_4 = & V_232 -> V_4 ;
struct V_233 * V_234 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_11 ;
V_2 = F_95 ( V_4 , sizeof( * V_2 ) , V_20 ) ;
if ( ! V_2 )
return - V_21 ;
V_2 -> V_155 = F_96 ( L_21 ,
sizeof( struct V_147 ) , 0 , 0 , NULL ) ;
if ( ! V_2 -> V_155 )
return - V_21 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_183 = F_97 ( L_22 ) ;
if ( ! V_2 -> V_183 ) {
F_5 ( V_4 , L_23 ) ;
V_11 = - V_73 ;
goto V_235;
}
F_98 ( & V_2 -> V_158 , F_66 ) ;
F_83 ( & V_2 -> V_32 ) ;
F_83 ( & V_2 -> V_154 ) ;
F_99 ( & V_2 -> V_33 ) ;
F_99 ( & V_2 -> V_159 ) ;
V_2 -> V_236 = F_100 ( V_4 , L_24 ) ;
if ( F_54 ( V_2 -> V_236 ) ) {
F_5 ( V_4 , L_25 ) ;
V_11 = F_101 ( V_2 -> V_236 ) ;
goto V_237;
}
F_102 ( V_4 ) ;
V_234 = F_103 ( V_232 , V_238 , 0 ) ;
V_2 -> V_150 = F_104 ( V_4 , V_234 ) ;
if ( F_54 ( V_2 -> V_150 ) ) {
V_11 = F_101 ( V_2 -> V_150 ) ;
goto V_239;
}
V_2 -> V_172 = F_105 ( V_232 , 0 ) ;
if ( V_2 -> V_172 < 0 ) {
F_5 ( V_4 , L_26 ) ;
V_11 = V_2 -> V_172 ;
goto V_239;
}
V_11 = F_106 ( V_4 , V_2 -> V_172 , F_75 , 0 ,
L_27 , V_2 ) ;
if ( V_11 < 0 ) {
F_5 ( V_4 , L_28 ) ;
goto V_239;
}
V_2 -> V_91 = V_240 ;
F_107 ( V_232 , V_2 ) ;
V_9 = & V_2 -> V_9 ;
V_9 -> V_4 = V_4 ;
V_9 -> V_241 = F_87 ;
V_9 -> remove = F_90 ;
V_9 -> V_242 = F_92 ;
V_9 -> V_243 = F_93 ;
V_11 = F_108 ( V_9 ) ;
if ( V_11 < 0 ) {
F_5 ( V_4 , L_29 ) ;
goto V_239;
}
F_109 ( V_4 , L_30 ,
V_195 , V_197 ) ;
return 0 ;
V_239:
F_110 ( V_4 ) ;
V_237:
F_111 ( V_2 -> V_183 ) ;
V_235:
F_112 ( V_2 -> V_155 ) ;
return V_11 ;
}
static int F_113 ( struct V_231 * V_232 )
{
struct V_1 * V_2 = F_114 ( V_232 ) ;
F_115 ( & V_2 -> V_158 ) ;
F_116 ( & V_2 -> V_9 ) ;
while ( V_2 -> V_148 ) {
F_62 ( V_2 , V_2 -> V_148 ) ;
V_2 -> V_148 = F_61 ( V_2 ) ;
}
F_110 ( & V_232 -> V_4 ) ;
F_9 ( V_2 ) ;
F_111 ( V_2 -> V_183 ) ;
F_112 ( V_2 -> V_155 ) ;
return 0 ;
}
static int F_117 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_32 ( V_4 ) ;
F_12 ( & V_2 -> V_159 ) ;
V_2 -> V_161 = true ;
F_14 ( & V_2 -> V_159 ) ;
while ( V_2 -> V_148 )
F_118 ( 500 , 1000 ) ;
F_119 ( & V_2 -> V_158 ) ;
return 0 ;
}
static int F_120 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_32 ( V_4 ) ;
V_2 -> V_161 = false ;
F_65 ( V_2 ) ;
return 0 ;
}
static int F_121 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_32 ( V_4 ) ;
F_122 ( V_2 -> V_236 ) ;
return 0 ;
}
static int F_123 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_32 ( V_4 ) ;
int V_11 ;
V_11 = F_124 ( V_2 -> V_236 ) ;
if ( V_11 < 0 )
F_125 ( V_4 , L_31 ) ;
return V_11 ;
}
