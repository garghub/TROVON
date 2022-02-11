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
if ( ! V_50 -> V_59 )
F_16 ( & V_50 -> V_31 ) ;
F_26 ( V_50 -> V_54 ) ;
F_10 ( V_50 -> V_54 ) ;
F_27 ( V_50 -> V_56 ) ;
F_10 ( V_50 ) ;
}
static T_1 * F_28 ( struct V_46 * V_17 ,
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
F_29 ( L_4 ) ;
return F_30 ( - V_73 ) ;
}
V_2 = F_31 ( V_35 -> V_4 ) ;
F_32 (g2d_userptr, &g2d_priv->userptr_list, list) {
if ( V_50 -> V_60 == V_60 ) {
if ( V_50 -> V_61 == V_61 ) {
F_33 ( & V_50 -> V_52 ) ;
* V_47 = ( unsigned long ) V_50 ;
return & V_50 -> V_27 ;
}
V_50 -> V_59 = true ;
V_50 -> V_53 = false ;
F_16 ( & V_50 -> V_31 ) ;
break;
}
}
V_50 = F_34 ( sizeof( * V_50 ) , V_20 ) ;
if ( ! V_50 ) {
F_29 ( L_5 ) ;
return F_30 ( - V_21 ) ;
}
F_35 ( & V_50 -> V_52 , 1 ) ;
V_70 = V_60 & V_74 ;
V_72 = V_60 & ~ V_74 ;
V_71 = F_36 ( V_60 + V_61 ) ;
V_57 = ( V_71 - V_70 ) >> V_75 ;
V_50 -> V_57 = V_57 ;
V_56 = F_37 ( V_57 , sizeof( struct V_67 * ) ) ;
if ( ! V_56 ) {
F_29 ( L_6 ) ;
V_11 = - V_21 ;
goto V_76;
}
V_58 = F_38 ( V_77 -> V_78 , V_60 ) ;
if ( ! V_58 ) {
F_29 ( L_7 ) ;
V_11 = - V_79 ;
goto V_80;
}
if ( V_58 -> V_81 < V_60 + V_61 ) {
F_29 ( L_8 ) ;
V_11 = - V_79 ;
goto V_80;
}
V_50 -> V_58 = F_39 ( V_58 ) ;
if ( ! V_50 -> V_58 ) {
F_29 ( L_9 ) ;
V_11 = - V_21 ;
goto V_80;
}
V_50 -> V_61 = V_61 ;
V_11 = F_40 ( V_70 & V_74 ,
V_57 , V_56 , V_58 ) ;
if ( V_11 < 0 ) {
F_29 ( L_10 ) ;
goto V_82;
}
V_50 -> V_56 = V_56 ;
V_54 = F_34 ( sizeof( * V_54 ) , V_20 ) ;
if ( ! V_54 ) {
F_29 ( L_11 ) ;
V_11 = - V_21 ;
goto V_83;
}
V_11 = F_41 ( V_54 , V_56 , V_57 , V_72 ,
V_61 , V_20 ) ;
if ( V_11 < 0 ) {
F_29 ( L_12 ) ;
goto V_84;
}
V_50 -> V_54 = V_54 ;
V_11 = F_42 ( V_17 , V_50 -> V_54 ,
V_55 ) ;
if ( V_11 < 0 ) {
F_29 ( L_13 ) ;
goto V_85;
}
V_50 -> V_27 = V_54 -> V_86 [ 0 ] . V_87 ;
V_50 -> V_60 = V_60 ;
F_7 ( & V_50 -> V_31 , & V_35 -> V_88 ) ;
if ( V_2 -> V_89 + ( V_57 << V_75 ) < V_2 -> V_90 ) {
V_2 -> V_89 += V_57 << V_75 ;
V_50 -> V_53 = true ;
}
* V_47 = ( unsigned long ) V_50 ;
return & V_50 -> V_27 ;
V_85:
F_26 ( V_54 ) ;
V_84:
F_10 ( V_54 ) ;
V_83:
F_25 ( V_50 -> V_56 ,
V_50 -> V_57 ,
V_50 -> V_58 ) ;
V_82:
F_43 ( V_50 -> V_58 ) ;
V_80:
F_27 ( V_56 ) ;
V_76:
F_10 ( V_50 ) ;
return F_30 ( V_11 ) ;
}
static void F_44 ( struct V_46 * V_17 ,
struct V_1 * V_2 ,
struct V_62 * V_63 )
{
struct V_64 * V_65 = V_63 -> V_66 ;
struct V_34 * V_35 = V_65 -> V_35 ;
struct V_49 * V_50 , * V_91 ;
F_45 (g2d_userptr, n, &g2d_priv->userptr_list, list)
if ( V_50 -> V_53 )
F_21 ( V_17 ,
( unsigned long ) V_50 ,
true ) ;
V_2 -> V_89 = 0 ;
}
static enum V_92 F_46 ( int V_93 )
{
enum V_92 V_94 ;
switch ( V_93 ) {
case V_95 :
case V_96 :
case V_97 :
case V_98 :
V_94 = V_99 ;
break;
case V_100 :
V_94 = V_101 ;
break;
case V_102 :
case V_103 :
case V_104 :
case V_105 :
V_94 = V_106 ;
break;
case V_107 :
V_94 = V_108 ;
break;
case V_109 :
V_94 = V_110 ;
break;
case V_111 :
V_94 = V_112 ;
break;
default:
V_94 = V_30 ;
F_29 ( L_14 , V_93 ) ;
break;
} ;
return V_94 ;
}
static unsigned long F_47 ( unsigned int V_113 )
{
unsigned long V_114 ;
switch ( V_113 ) {
case V_115 :
case V_116 :
V_114 = 4 ;
break;
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
V_114 = 2 ;
break;
case V_122 :
V_114 = 3 ;
break;
default:
V_114 = 1 ;
break;
}
return V_114 ;
}
static bool F_48 ( struct V_123 * V_124 ,
enum V_92 V_94 ,
unsigned long V_61 )
{
unsigned int V_125 , V_126 ;
unsigned long V_127 ;
if ( V_94 != V_99 && V_94 != V_106 )
return true ;
V_125 = V_124 -> V_128 - V_124 -> V_129 ;
if ( V_125 < V_130 || V_125 > V_131 ) {
F_29 ( L_15 , V_125 ) ;
return false ;
}
V_126 = V_124 -> V_132 - V_124 -> V_133 ;
if ( V_126 < V_130 || V_126 > V_131 ) {
F_29 ( L_16 , V_126 ) ;
return false ;
}
V_127 = ( unsigned long ) V_125 * ( unsigned long ) V_126 *
F_47 ( V_124 -> V_113 ) ;
if ( V_127 > V_61 ) {
F_29 ( L_17 , V_127 , V_61 ) ;
return false ;
}
return true ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_46 * V_17 ,
struct V_62 * V_134 )
{
struct V_135 * V_25 = V_6 -> V_25 ;
struct V_12 * V_13 = & V_6 -> V_13 ;
int V_72 ;
int V_11 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_13 -> V_136 ; V_24 ++ ) {
struct V_123 * V_124 ;
enum V_92 V_94 ;
int V_137 ;
unsigned long V_138 ;
T_1 * V_139 ;
V_137 = V_25 -> V_41 - 2 * ( V_24 + 1 ) ;
V_72 = V_25 -> V_40 [ V_137 ] ;
V_138 = V_25 -> V_40 [ V_137 + 1 ] ;
V_94 = F_46 ( V_72 ) ;
if ( V_94 == V_30 ) {
V_11 = - V_79 ;
goto V_23;
}
V_124 = & V_13 -> V_140 [ V_94 ] ;
if ( V_13 -> V_141 [ V_94 ] == V_142 ) {
unsigned long V_61 ;
V_61 = F_50 ( V_17 , V_138 , V_134 ) ;
if ( ! V_61 ) {
V_11 = - V_79 ;
goto V_23;
}
if ( ! F_48 ( V_124 , V_94 ,
V_61 ) ) {
V_11 = - V_79 ;
goto V_23;
}
V_139 = F_51 ( V_17 , V_138 ,
V_134 ) ;
if ( F_52 ( V_139 ) ) {
V_11 = - V_79 ;
goto V_23;
}
} else {
struct V_143 V_50 ;
if ( F_53 ( & V_50 , ( void V_144 * ) V_138 ,
sizeof( struct V_143 ) ) ) {
V_11 = - V_79 ;
goto V_23;
}
if ( ! F_48 ( V_124 , V_94 ,
V_50 . V_61 ) ) {
V_11 = - V_79 ;
goto V_23;
}
V_139 = F_28 ( V_17 ,
V_50 . V_60 ,
V_50 . V_61 ,
V_134 ,
& V_138 ) ;
if ( F_52 ( V_139 ) ) {
V_11 = - V_79 ;
goto V_23;
}
}
V_25 -> V_40 [ V_137 + 1 ] = * V_139 ;
V_13 -> V_29 [ V_24 ] = V_94 ;
V_13 -> V_145 [ V_94 ] = V_138 ;
}
return 0 ;
V_23:
V_13 -> V_136 = V_24 ;
return V_11 ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_62 * V_63 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_12 * V_13 = & V_6 -> V_13 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_13 -> V_136 ; V_24 ++ ) {
struct V_123 * V_124 ;
enum V_92 V_94 ;
unsigned long V_138 ;
V_94 = V_13 -> V_29 [ V_24 ] ;
V_124 = & V_13 -> V_140 [ V_94 ] ;
V_138 = V_13 -> V_145 [ V_94 ] ;
if ( V_13 -> V_141 [ V_94 ] == V_142 )
F_55 ( V_9 -> V_17 , V_138 ,
V_63 ) ;
else
F_21 ( V_9 -> V_17 , V_138 ,
false ) ;
V_13 -> V_29 [ V_24 ] = V_30 ;
V_13 -> V_145 [ V_94 ] = 0 ;
V_13 -> V_141 [ V_94 ] = 0 ;
memset ( V_124 , 0x00 , sizeof( * V_124 ) ) ;
}
V_13 -> V_136 = 0 ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_146 * V_147 )
{
struct V_5 * V_6 =
F_15 ( & V_147 -> V_148 ,
struct V_5 , V_31 ) ;
int V_11 ;
V_11 = F_57 ( V_2 -> V_4 ) ;
if ( V_11 < 0 ) {
F_58 ( V_2 -> V_4 , L_18 ) ;
return;
}
V_11 = F_59 ( V_2 -> V_149 ) ;
if ( V_11 < 0 ) {
F_58 ( V_2 -> V_4 , L_19 ) ;
F_60 ( V_2 -> V_4 ) ;
return;
}
F_61 ( V_6 -> V_27 , V_2 -> V_150 + V_151 ) ;
F_61 ( V_152 , V_2 -> V_150 + V_153 ) ;
}
static struct V_146 * F_62 ( struct V_1 * V_2 )
{
struct V_146 * V_147 ;
if ( F_13 ( & V_2 -> V_154 ) )
return NULL ;
V_147 = F_15 ( & V_2 -> V_154 ,
struct V_146 , V_31 ) ;
F_16 ( & V_147 -> V_31 ) ;
return V_147 ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_146 * V_147 )
{
struct V_5 * V_6 ;
if ( ! V_147 )
return;
F_12 ( & V_2 -> V_33 ) ;
F_32 (node, &runqueue_node->run_cmdlist, list)
F_54 ( V_2 , V_6 , V_147 -> V_63 ) ;
F_64 ( & V_147 -> V_148 , & V_2 -> V_32 ) ;
F_14 ( & V_2 -> V_33 ) ;
F_65 ( V_2 -> V_155 , V_147 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
V_2 -> V_147 = F_62 ( V_2 ) ;
if ( V_2 -> V_147 )
F_56 ( V_2 , V_2 -> V_147 ) ;
}
static void F_67 ( struct V_156 * V_157 )
{
struct V_1 * V_2 = F_68 ( V_157 , struct V_1 ,
V_158 ) ;
F_12 ( & V_2 -> V_159 ) ;
F_69 ( V_2 -> V_149 ) ;
F_60 ( V_2 -> V_4 ) ;
F_70 ( & V_2 -> V_147 -> F_70 ) ;
if ( V_2 -> V_147 -> V_160 )
F_63 ( V_2 , V_2 -> V_147 ) ;
if ( V_2 -> V_161 )
V_2 -> V_147 = NULL ;
else
F_66 ( V_2 ) ;
F_14 ( & V_2 -> V_159 ) ;
}
static void F_71 ( struct V_1 * V_2 , T_2 V_162 )
{
struct V_46 * V_17 = V_2 -> V_9 . V_17 ;
struct V_146 * V_147 = V_2 -> V_147 ;
struct V_163 * V_164 ;
struct V_165 V_166 ;
unsigned long V_167 ;
if ( F_13 ( & V_147 -> V_45 ) )
return;
V_164 = F_15 ( & V_147 -> V_45 ,
struct V_163 , V_43 . V_44 ) ;
F_72 ( & V_166 ) ;
V_164 -> V_42 . V_168 = V_166 . V_168 ;
V_164 -> V_42 . V_169 = V_166 . V_169 ;
V_164 -> V_42 . V_162 = V_162 ;
F_73 ( & V_17 -> V_170 , V_167 ) ;
F_18 ( & V_164 -> V_43 . V_44 , & V_164 -> V_43 . V_65 -> V_45 ) ;
F_74 ( & V_164 -> V_43 . V_65 -> V_171 ) ;
F_75 ( & V_17 -> V_170 , V_167 ) ;
}
static T_3 F_76 ( int V_172 , void * V_173 )
{
struct V_1 * V_2 = V_173 ;
T_2 V_174 ;
V_174 = F_77 ( V_2 -> V_150 + V_175 ) ;
if ( V_174 )
F_61 ( V_174 , V_2 -> V_150 + V_175 ) ;
if ( V_174 & V_176 ) {
T_2 V_162 = F_77 ( V_2 -> V_150 + V_177 ) ;
V_162 = ( V_162 & V_178 ) >>
V_179 ;
F_71 ( V_2 , V_162 ) ;
F_61 ( 0 , V_2 -> V_150 + V_180 ) ;
if ( ! ( V_174 & V_181 ) ) {
F_61 ( V_182 ,
V_2 -> V_150 + V_153 ) ;
}
}
if ( V_174 & V_181 )
F_78 ( V_2 -> V_183 , & V_2 -> V_158 ) ;
return V_184 ;
}
static int F_79 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
int V_10 , bool V_185 )
{
struct V_135 * V_25 = V_6 -> V_25 ;
int V_93 ;
int V_186 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_10 ; V_24 ++ ) {
struct V_12 * V_13 = & V_6 -> V_13 ;
struct V_123 * V_124 ;
enum V_92 V_94 ;
unsigned long V_187 ;
V_186 = V_25 -> V_41 - 2 * ( V_24 + 1 ) ;
V_93 = V_25 -> V_40 [ V_186 ] & ~ 0xfffff000 ;
if ( V_93 < V_188 || V_93 > V_189 )
goto V_23;
if ( V_93 % 4 )
goto V_23;
switch ( V_93 ) {
case V_95 :
case V_100 :
case V_102 :
case V_107 :
case V_109 :
case V_111 :
if ( ! V_185 )
goto V_23;
V_94 = F_46 ( V_93 ) ;
if ( V_94 == V_30 )
goto V_23;
if ( ( V_25 -> V_40 [ V_186 ] & ~ 0x7fffffff ) >> 31 ) {
V_13 -> V_141 [ V_94 ] = V_190 ;
V_25 -> V_40 [ V_186 ] &= ~ V_191 ;
} else
V_13 -> V_141 [ V_94 ] = V_142 ;
break;
case V_96 :
case V_103 :
if ( V_185 )
goto V_23;
V_94 = F_46 ( V_93 ) ;
if ( V_94 == V_30 )
goto V_23;
V_124 = & V_13 -> V_140 [ V_94 ] ;
V_187 = V_25 -> V_40 [ V_186 + 1 ] ;
V_124 -> V_113 = V_187 & 0xf ;
break;
case V_97 :
case V_104 :
if ( V_185 )
goto V_23;
V_94 = F_46 ( V_93 ) ;
if ( V_94 == V_30 )
goto V_23;
V_124 = & V_13 -> V_140 [ V_94 ] ;
V_187 = V_25 -> V_40 [ V_186 + 1 ] ;
V_124 -> V_129 = V_187 & 0x1fff ;
V_124 -> V_133 = ( V_187 & 0x1fff0000 ) >> 16 ;
break;
case V_98 :
case V_105 :
if ( V_185 )
goto V_23;
V_94 = F_46 ( V_93 ) ;
if ( V_94 == V_30 )
goto V_23;
V_124 = & V_13 -> V_140 [ V_94 ] ;
V_187 = V_25 -> V_40 [ V_186 + 1 ] ;
V_124 -> V_128 = V_187 & 0x1fff ;
V_124 -> V_132 = ( V_187 & 0x1fff0000 ) >> 16 ;
break;
default:
if ( V_185 )
goto V_23;
break;
}
}
return 0 ;
V_23:
F_5 ( V_4 , L_20 , V_25 -> V_40 [ V_186 ] ) ;
return - V_73 ;
}
int F_80 ( struct V_46 * V_17 , void * V_40 ,
struct V_62 * V_134 )
{
struct V_192 * V_193 = V_40 ;
V_193 -> V_194 = V_195 ;
V_193 -> V_196 = V_197 ;
return 0 ;
}
int F_81 ( struct V_46 * V_17 , void * V_40 ,
struct V_62 * V_134 )
{
struct V_64 * V_65 = V_134 -> V_66 ;
struct V_34 * V_35 = V_65 -> V_35 ;
struct V_3 * V_4 = V_35 -> V_4 ;
struct V_1 * V_2 ;
struct V_198 * V_199 = V_40 ;
struct V_200 * V_201 ;
struct V_163 * V_164 ;
struct V_5 * V_6 ;
struct V_135 * V_25 ;
unsigned long V_167 ;
int V_61 ;
int V_11 ;
if ( ! V_4 )
return - V_202 ;
V_2 = F_31 ( V_4 ) ;
if ( ! V_2 )
return - V_79 ;
V_6 = F_11 ( V_2 ) ;
if ( ! V_6 )
return - V_21 ;
V_6 -> V_42 = NULL ;
if ( V_199 -> V_203 != V_204 ) {
F_73 ( & V_17 -> V_170 , V_167 ) ;
if ( V_134 -> V_205 < sizeof( V_164 -> V_42 ) ) {
F_75 ( & V_17 -> V_170 , V_167 ) ;
V_11 = - V_21 ;
goto V_23;
}
V_134 -> V_205 -= sizeof( V_164 -> V_42 ) ;
F_75 ( & V_17 -> V_170 , V_167 ) ;
V_164 = F_34 ( sizeof( * V_6 -> V_42 ) , V_20 ) ;
if ( ! V_164 ) {
F_5 ( V_4 , L_21 ) ;
F_73 ( & V_17 -> V_170 , V_167 ) ;
V_134 -> V_205 += sizeof( V_164 -> V_42 ) ;
F_75 ( & V_17 -> V_170 , V_167 ) ;
V_11 = - V_21 ;
goto V_23;
}
V_164 -> V_42 . V_43 . type = V_206 ;
V_164 -> V_42 . V_43 . V_207 = sizeof( V_164 -> V_42 ) ;
V_164 -> V_42 . V_208 = V_199 -> V_208 ;
V_164 -> V_43 . V_42 = & V_164 -> V_42 . V_43 ;
V_164 -> V_43 . V_65 = V_134 ;
V_164 -> V_43 . V_209 = ( void ( * ) ( struct V_210 * ) ) F_10 ;
V_6 -> V_42 = V_164 ;
}
V_25 = V_6 -> V_25 ;
V_25 -> V_41 = 0 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_211 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_212 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_95 ;
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
F_5 ( V_4 , L_22 ) ;
V_11 = - V_73 ;
goto V_220;
}
V_201 = (struct V_200 * ) ( V_221 ) V_199 -> V_201 ;
if ( F_53 ( V_25 -> V_40 + V_25 -> V_41 ,
( void V_144 * ) V_201 ,
sizeof( * V_201 ) * V_199 -> V_217 ) ) {
V_11 = - V_79 ;
goto V_220;
}
V_25 -> V_41 += V_199 -> V_217 * 2 ;
V_11 = F_79 ( V_4 , V_6 , V_199 -> V_217 , false ) ;
if ( V_11 < 0 )
goto V_220;
V_6 -> V_13 . V_136 = V_199 -> V_218 ;
if ( V_199 -> V_218 ) {
struct V_200 * V_222 ;
V_222 = (struct V_200 * ) ( V_221 ) V_199 -> V_222 ;
if ( F_53 ( V_25 -> V_40 + V_25 -> V_41 ,
( void V_144 * ) V_222 ,
sizeof( * V_222 ) * V_199 -> V_218 ) ) {
V_11 = - V_79 ;
goto V_220;
}
V_25 -> V_41 += V_199 -> V_218 * 2 ;
V_11 = F_79 ( V_4 , V_6 , V_199 -> V_218 , true ) ;
if ( V_11 < 0 )
goto V_220;
V_11 = F_49 ( V_2 , V_6 , V_17 , V_134 ) ;
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
F_54 ( V_2 , V_6 , V_134 ) ;
V_220:
if ( V_6 -> V_42 ) {
F_73 ( & V_17 -> V_170 , V_167 ) ;
V_134 -> V_205 += sizeof( V_164 -> V_42 ) ;
F_75 ( & V_17 -> V_170 , V_167 ) ;
F_10 ( V_6 -> V_42 ) ;
}
V_23:
F_17 ( V_2 , V_6 ) ;
return V_11 ;
}
int F_82 ( struct V_46 * V_17 , void * V_40 ,
struct V_62 * V_134 )
{
struct V_64 * V_65 = V_134 -> V_66 ;
struct V_34 * V_35 = V_65 -> V_35 ;
struct V_3 * V_4 = V_35 -> V_4 ;
struct V_1 * V_2 ;
struct V_227 * V_199 = V_40 ;
struct V_146 * V_147 ;
struct V_228 * V_148 ;
struct V_228 * V_45 ;
if ( ! V_4 )
return - V_202 ;
V_2 = F_31 ( V_4 ) ;
if ( ! V_2 )
return - V_79 ;
V_147 = F_83 ( V_2 -> V_155 , V_20 ) ;
if ( ! V_147 ) {
F_5 ( V_4 , L_2 ) ;
return - V_21 ;
}
V_148 = & V_147 -> V_148 ;
V_45 = & V_147 -> V_45 ;
F_84 ( V_148 ) ;
F_84 ( V_45 ) ;
F_85 ( & V_147 -> F_70 ) ;
V_147 -> V_160 = V_199 -> V_160 ;
F_86 ( & V_35 -> V_37 , V_148 ) ;
F_86 ( & V_35 -> V_45 , V_45 ) ;
if ( F_13 ( V_148 ) ) {
F_5 ( V_4 , L_23 ) ;
F_65 ( V_2 -> V_155 , V_147 ) ;
return - V_229 ;
}
F_12 ( & V_2 -> V_159 ) ;
V_147 -> V_230 = V_77 -> V_230 ;
V_147 -> V_63 = V_134 ;
F_7 ( & V_147 -> V_31 , & V_2 -> V_154 ) ;
if ( ! V_2 -> V_147 )
F_66 ( V_2 ) ;
F_14 ( & V_2 -> V_159 ) ;
if ( V_147 -> V_160 )
goto V_51;
F_87 ( & V_147 -> F_70 ) ;
F_63 ( V_2 , V_147 ) ;
V_51:
return 0 ;
}
static int F_88 ( struct V_46 * V_17 , struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_11 ;
V_2 = F_31 ( V_4 ) ;
if ( ! V_2 )
return - V_79 ;
V_11 = F_1 ( V_2 ) ;
if ( V_11 < 0 ) {
F_5 ( V_4 , L_24 ) ;
return V_11 ;
}
if ( ! F_89 ( V_17 ) )
return 0 ;
V_11 = F_90 ( V_17 , V_4 ) ;
if ( V_11 < 0 ) {
F_5 ( V_4 , L_25 ) ;
F_9 ( V_2 ) ;
}
return V_11 ;
}
static void F_91 ( struct V_46 * V_17 , struct V_3 * V_4 )
{
if ( ! F_89 ( V_17 ) )
return;
F_92 ( V_17 , V_4 ) ;
}
static int F_93 ( struct V_46 * V_17 , struct V_3 * V_4 ,
struct V_62 * V_134 )
{
struct V_64 * V_65 = V_134 -> V_66 ;
struct V_34 * V_35 ;
V_35 = F_34 ( sizeof( * V_35 ) , V_20 ) ;
if ( ! V_35 ) {
F_5 ( V_4 , L_26 ) ;
return - V_21 ;
}
V_35 -> V_4 = V_4 ;
V_65 -> V_35 = V_35 ;
F_84 ( & V_35 -> V_37 ) ;
F_84 ( & V_35 -> V_45 ) ;
F_84 ( & V_35 -> V_88 ) ;
return 0 ;
}
static void F_94 ( struct V_46 * V_17 , struct V_3 * V_4 ,
struct V_62 * V_134 )
{
struct V_64 * V_65 = V_134 -> V_66 ;
struct V_34 * V_35 = V_65 -> V_35 ;
struct V_1 * V_2 ;
struct V_5 * V_6 , * V_91 ;
if ( ! V_4 )
return;
V_2 = F_31 ( V_4 ) ;
if ( ! V_2 )
return;
F_12 ( & V_2 -> V_33 ) ;
F_45 (node, n, &g2d_priv->inuse_cmdlist, list) {
F_54 ( V_2 , V_6 , V_134 ) ;
F_18 ( & V_6 -> V_31 , & V_2 -> V_32 ) ;
}
F_14 ( & V_2 -> V_33 ) ;
F_44 ( V_17 , V_2 , V_134 ) ;
F_10 ( V_65 -> V_35 ) ;
}
static int F_95 ( struct V_231 * V_232 )
{
struct V_3 * V_4 = & V_232 -> V_4 ;
struct V_233 * V_234 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_11 ;
V_2 = F_96 ( V_4 , sizeof( * V_2 ) , V_20 ) ;
if ( ! V_2 ) {
F_5 ( V_4 , L_27 ) ;
return - V_21 ;
}
V_2 -> V_155 = F_97 ( L_28 ,
sizeof( struct V_146 ) , 0 , 0 , NULL ) ;
if ( ! V_2 -> V_155 )
return - V_21 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_183 = F_98 ( L_29 ) ;
if ( ! V_2 -> V_183 ) {
F_5 ( V_4 , L_30 ) ;
V_11 = - V_73 ;
goto V_235;
}
F_99 ( & V_2 -> V_158 , F_67 ) ;
F_84 ( & V_2 -> V_32 ) ;
F_84 ( & V_2 -> V_154 ) ;
F_100 ( & V_2 -> V_33 ) ;
F_100 ( & V_2 -> V_159 ) ;
V_2 -> V_149 = F_101 ( V_4 , L_31 ) ;
if ( F_52 ( V_2 -> V_149 ) ) {
F_5 ( V_4 , L_32 ) ;
V_11 = F_102 ( V_2 -> V_149 ) ;
goto V_236;
}
F_103 ( V_4 ) ;
V_234 = F_104 ( V_232 , V_237 , 0 ) ;
V_2 -> V_150 = F_105 ( V_4 , V_234 ) ;
if ( F_52 ( V_2 -> V_150 ) ) {
V_11 = F_102 ( V_2 -> V_150 ) ;
goto V_238;
}
V_2 -> V_172 = F_106 ( V_232 , 0 ) ;
if ( V_2 -> V_172 < 0 ) {
F_5 ( V_4 , L_33 ) ;
V_11 = V_2 -> V_172 ;
goto V_238;
}
V_11 = F_107 ( V_4 , V_2 -> V_172 , F_76 , 0 ,
L_34 , V_2 ) ;
if ( V_11 < 0 ) {
F_5 ( V_4 , L_35 ) ;
goto V_238;
}
V_2 -> V_90 = V_239 ;
F_108 ( V_232 , V_2 ) ;
V_9 = & V_2 -> V_9 ;
V_9 -> V_4 = V_4 ;
V_9 -> V_240 = F_88 ;
V_9 -> remove = F_91 ;
V_9 -> V_241 = F_93 ;
V_9 -> V_242 = F_94 ;
V_11 = F_109 ( V_9 ) ;
if ( V_11 < 0 ) {
F_5 ( V_4 , L_36 ) ;
goto V_238;
}
F_110 ( V_4 , L_37 ,
V_195 , V_197 ) ;
return 0 ;
V_238:
F_111 ( V_4 ) ;
V_236:
F_112 ( V_2 -> V_183 ) ;
V_235:
F_113 ( V_2 -> V_155 ) ;
return V_11 ;
}
static int F_114 ( struct V_231 * V_232 )
{
struct V_1 * V_2 = F_115 ( V_232 ) ;
F_116 ( & V_2 -> V_158 ) ;
F_117 ( & V_2 -> V_9 ) ;
while ( V_2 -> V_147 ) {
F_63 ( V_2 , V_2 -> V_147 ) ;
V_2 -> V_147 = F_62 ( V_2 ) ;
}
F_111 ( & V_232 -> V_4 ) ;
F_9 ( V_2 ) ;
F_112 ( V_2 -> V_183 ) ;
F_113 ( V_2 -> V_155 ) ;
return 0 ;
}
static int F_118 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_31 ( V_4 ) ;
F_12 ( & V_2 -> V_159 ) ;
V_2 -> V_161 = true ;
F_14 ( & V_2 -> V_159 ) ;
while ( V_2 -> V_147 )
F_119 ( 500 , 1000 ) ;
F_120 ( & V_2 -> V_158 ) ;
return 0 ;
}
static int F_121 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_31 ( V_4 ) ;
V_2 -> V_161 = false ;
F_66 ( V_2 ) ;
return 0 ;
}
