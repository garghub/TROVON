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
V_2 -> V_16 = F_4 ( F_5 ( V_9 -> V_17 ) ,
V_18 ,
& V_2 -> V_19 , V_20 ,
& V_2 -> V_14 ) ;
if ( ! V_2 -> V_16 ) {
F_6 ( V_4 , L_1 ) ;
return - V_21 ;
}
V_6 = F_7 ( V_22 , sizeof( * V_6 ) , V_20 ) ;
if ( ! V_6 ) {
F_6 ( V_4 , L_2 ) ;
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
F_8 ( & V_6 [ V_10 ] . V_31 , & V_2 -> V_32 ) ;
}
return 0 ;
V_23:
F_9 ( F_5 ( V_9 -> V_17 ) , V_18 ,
V_2 -> V_16 ,
V_2 -> V_19 , & V_2 -> V_14 ) ;
return V_11 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
F_11 ( V_2 -> V_7 ) ;
if ( V_2 -> V_16 && V_2 -> V_19 ) {
F_9 ( F_5 ( V_9 -> V_17 ) ,
V_18 ,
V_2 -> V_16 ,
V_2 -> V_19 , & V_2 -> V_14 ) ;
}
}
static struct V_5 * F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
F_13 ( & V_2 -> V_33 ) ;
if ( F_14 ( & V_2 -> V_32 ) ) {
F_6 ( V_4 , L_3 ) ;
F_15 ( & V_2 -> V_33 ) ;
return NULL ;
}
V_6 = F_16 ( & V_2 -> V_32 , struct V_5 ,
V_31 ) ;
F_17 ( & V_6 -> V_31 ) ;
F_15 ( & V_2 -> V_33 ) ;
return V_6 ;
}
static void F_18 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
F_13 ( & V_2 -> V_33 ) ;
F_19 ( & V_6 -> V_31 , & V_2 -> V_32 ) ;
F_15 ( & V_2 -> V_33 ) ;
}
static void F_20 ( struct V_34 * V_35 ,
struct V_5 * V_6 )
{
struct V_5 * V_36 ;
if ( F_14 ( & V_35 -> V_37 ) )
goto V_38;
V_36 = F_21 ( V_35 -> V_37 . V_39 ,
struct V_5 , V_31 ) ;
V_36 -> V_25 -> V_40 [ V_36 -> V_25 -> V_41 ] = V_6 -> V_27 ;
V_38:
F_8 ( & V_6 -> V_31 , & V_35 -> V_37 ) ;
if ( V_6 -> V_42 )
F_8 ( & V_6 -> V_42 -> V_43 . V_44 , & V_35 -> V_45 ) ;
}
static void F_22 ( struct V_46 * V_17 ,
unsigned long V_47 ,
bool V_48 )
{
struct V_49 * V_50 =
(struct V_49 * ) V_47 ;
struct V_51 * * V_52 ;
if ( ! V_47 )
return;
if ( V_48 )
goto V_53;
F_23 ( & V_50 -> V_54 ) ;
if ( F_24 ( & V_50 -> V_54 ) > 0 )
return;
if ( V_50 -> V_55 )
return;
V_53:
F_25 ( F_5 ( V_17 ) , V_50 -> V_56 -> V_57 ,
V_50 -> V_56 -> V_58 , V_59 ) ;
V_52 = F_26 ( V_50 -> V_60 ) ;
if ( ! F_27 ( V_52 ) ) {
int V_24 ;
for ( V_24 = 0 ; V_24 < F_28 ( V_50 -> V_60 ) ; V_24 ++ )
F_29 ( V_52 [ V_24 ] ) ;
}
F_30 ( V_50 -> V_60 ) ;
F_31 ( V_50 -> V_60 ) ;
if ( ! V_50 -> V_61 )
F_17 ( & V_50 -> V_31 ) ;
F_32 ( V_50 -> V_56 ) ;
F_11 ( V_50 -> V_56 ) ;
F_11 ( V_50 ) ;
}
static T_1 * F_33 ( struct V_46 * V_17 ,
unsigned long V_62 ,
unsigned long V_63 ,
struct V_64 * V_65 ,
unsigned long * V_47 )
{
struct V_66 * V_67 = V_65 -> V_68 ;
struct V_34 * V_35 = V_67 -> V_35 ;
struct V_49 * V_50 ;
struct V_1 * V_2 ;
struct V_69 * V_56 ;
unsigned long V_70 , V_71 ;
unsigned int V_72 , V_73 ;
int V_11 ;
if ( ! V_63 ) {
F_34 ( L_4 ) ;
return F_35 ( - V_74 ) ;
}
V_2 = F_36 ( V_35 -> V_4 ) ;
F_37 (g2d_userptr, &g2d_priv->userptr_list, list) {
if ( V_50 -> V_62 == V_62 ) {
if ( V_50 -> V_63 == V_63 ) {
F_38 ( & V_50 -> V_54 ) ;
* V_47 = ( unsigned long ) V_50 ;
return & V_50 -> V_27 ;
}
V_50 -> V_61 = true ;
V_50 -> V_55 = false ;
F_17 ( & V_50 -> V_31 ) ;
break;
}
}
V_50 = F_39 ( sizeof( * V_50 ) , V_20 ) ;
if ( ! V_50 )
return F_35 ( - V_21 ) ;
F_40 ( & V_50 -> V_54 , 1 ) ;
V_50 -> V_63 = V_63 ;
V_70 = V_62 & V_75 ;
V_73 = V_62 & ~ V_75 ;
V_71 = F_41 ( V_62 + V_63 ) ;
V_72 = ( V_71 - V_70 ) >> V_76 ;
V_50 -> V_60 = F_42 ( V_72 ) ;
if ( ! V_50 -> V_60 ) {
V_11 = - V_21 ;
goto V_77;
}
V_11 = F_43 ( V_70 , V_72 , true , true , V_50 -> V_60 ) ;
if ( V_11 != V_72 ) {
F_34 ( L_5 ) ;
if ( V_11 < 0 )
goto V_78;
V_11 = - V_79 ;
goto V_80;
}
if ( F_44 ( V_50 -> V_60 ) < 0 ) {
V_11 = - V_79 ;
goto V_80;
}
V_56 = F_39 ( sizeof( * V_56 ) , V_20 ) ;
if ( ! V_56 ) {
V_11 = - V_21 ;
goto V_80;
}
V_11 = F_45 ( V_56 ,
F_26 ( V_50 -> V_60 ) ,
V_72 , V_73 , V_63 , V_20 ) ;
if ( V_11 < 0 ) {
F_34 ( L_6 ) ;
goto V_81;
}
V_50 -> V_56 = V_56 ;
if ( ! F_46 ( F_5 ( V_17 ) , V_56 -> V_57 , V_56 -> V_58 ,
V_59 ) ) {
F_34 ( L_7 ) ;
V_11 = - V_21 ;
goto V_82;
}
V_50 -> V_27 = V_56 -> V_57 [ 0 ] . V_83 ;
V_50 -> V_62 = V_62 ;
F_8 ( & V_50 -> V_31 , & V_35 -> V_84 ) ;
if ( V_2 -> V_85 + ( V_72 << V_76 ) < V_2 -> V_86 ) {
V_2 -> V_85 += V_72 << V_76 ;
V_50 -> V_55 = true ;
}
* V_47 = ( unsigned long ) V_50 ;
return & V_50 -> V_27 ;
V_82:
F_32 ( V_56 ) ;
V_81:
F_11 ( V_56 ) ;
V_80:
F_30 ( V_50 -> V_60 ) ;
V_78:
F_31 ( V_50 -> V_60 ) ;
V_77:
F_11 ( V_50 ) ;
return F_35 ( V_11 ) ;
}
static void F_47 ( struct V_46 * V_17 ,
struct V_1 * V_2 ,
struct V_64 * V_65 )
{
struct V_66 * V_67 = V_65 -> V_68 ;
struct V_34 * V_35 = V_67 -> V_35 ;
struct V_49 * V_50 , * V_87 ;
F_48 (g2d_userptr, n, &g2d_priv->userptr_list, list)
if ( V_50 -> V_55 )
F_22 ( V_17 ,
( unsigned long ) V_50 ,
true ) ;
V_2 -> V_85 = 0 ;
}
static enum V_88 F_49 ( int V_89 )
{
enum V_88 V_90 ;
switch ( V_89 ) {
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
V_90 = V_96 ;
break;
case V_97 :
V_90 = V_98 ;
break;
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
V_90 = V_104 ;
break;
case V_105 :
V_90 = V_106 ;
break;
case V_107 :
V_90 = V_108 ;
break;
case V_109 :
V_90 = V_110 ;
break;
default:
V_90 = V_30 ;
F_34 ( L_8 , V_89 ) ;
break;
}
return V_90 ;
}
static unsigned long F_50 ( unsigned int V_111 )
{
unsigned long V_112 ;
switch ( V_111 ) {
case V_113 :
case V_114 :
V_112 = 4 ;
break;
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
V_112 = 2 ;
break;
case V_120 :
V_112 = 3 ;
break;
default:
V_112 = 1 ;
break;
}
return V_112 ;
}
static bool F_51 ( struct V_121 * V_122 ,
enum V_88 V_90 ,
unsigned long V_63 )
{
int V_123 , V_124 ;
unsigned long V_112 , V_125 ;
if ( V_90 != V_96 && V_90 != V_104 )
return true ;
V_123 = ( int ) V_122 -> V_126 - ( int ) V_122 -> V_127 ;
if ( V_123 < V_128 || V_123 > V_129 ) {
F_34 ( L_9 , V_123 ) ;
return false ;
}
V_124 = ( int ) V_122 -> V_130 - ( int ) V_122 -> V_131 ;
if ( V_124 < V_128 || V_124 > V_129 ) {
F_34 ( L_10 , V_124 ) ;
return false ;
}
V_112 = F_50 ( V_122 -> V_111 ) ;
V_125 = ( ( unsigned long ) V_122 -> V_130 - 1 ) *
( unsigned long ) V_122 -> V_132 +
( unsigned long ) V_122 -> V_126 * V_112 - 1 ;
if ( V_125 >= V_63 ) {
F_34 ( L_11
L_12 , V_125 , V_63 ) ;
return false ;
}
return true ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_46 * V_17 ,
struct V_64 * V_133 )
{
struct V_134 * V_25 = V_6 -> V_25 ;
struct V_12 * V_13 = & V_6 -> V_13 ;
int V_73 ;
int V_11 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_13 -> V_135 ; V_24 ++ ) {
struct V_121 * V_122 ;
enum V_88 V_90 ;
int V_136 ;
unsigned long V_137 ;
T_1 * V_138 ;
V_136 = V_25 -> V_41 - 2 * ( V_24 + 1 ) ;
V_73 = V_25 -> V_40 [ V_136 ] ;
V_137 = V_25 -> V_40 [ V_136 + 1 ] ;
V_90 = F_49 ( V_73 ) ;
if ( V_90 == V_30 ) {
V_11 = - V_79 ;
goto V_23;
}
V_122 = & V_13 -> V_139 [ V_90 ] ;
if ( V_13 -> V_140 [ V_90 ] == V_141 ) {
unsigned long V_63 ;
V_63 = F_53 ( V_17 , V_137 , V_133 ) ;
if ( ! V_63 ) {
V_11 = - V_79 ;
goto V_23;
}
if ( ! F_51 ( V_122 , V_90 ,
V_63 ) ) {
V_11 = - V_79 ;
goto V_23;
}
V_138 = F_54 ( V_17 , V_137 ,
V_133 ) ;
if ( F_27 ( V_138 ) ) {
V_11 = - V_79 ;
goto V_23;
}
} else {
struct V_142 V_50 ;
if ( F_55 ( & V_50 , ( void V_143 * ) V_137 ,
sizeof( struct V_142 ) ) ) {
V_11 = - V_79 ;
goto V_23;
}
if ( ! F_51 ( V_122 , V_90 ,
V_50 . V_63 ) ) {
V_11 = - V_79 ;
goto V_23;
}
V_138 = F_33 ( V_17 ,
V_50 . V_62 ,
V_50 . V_63 ,
V_133 ,
& V_137 ) ;
if ( F_27 ( V_138 ) ) {
V_11 = - V_79 ;
goto V_23;
}
}
V_25 -> V_40 [ V_136 + 1 ] = * V_138 ;
V_13 -> V_29 [ V_24 ] = V_90 ;
V_13 -> V_144 [ V_90 ] = V_137 ;
}
return 0 ;
V_23:
V_13 -> V_135 = V_24 ;
return V_11 ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_64 * V_65 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_12 * V_13 = & V_6 -> V_13 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_13 -> V_135 ; V_24 ++ ) {
struct V_121 * V_122 ;
enum V_88 V_90 ;
unsigned long V_137 ;
V_90 = V_13 -> V_29 [ V_24 ] ;
V_122 = & V_13 -> V_139 [ V_90 ] ;
V_137 = V_13 -> V_144 [ V_90 ] ;
if ( V_13 -> V_140 [ V_90 ] == V_141 )
F_57 ( V_9 -> V_17 , V_137 ,
V_65 ) ;
else
F_22 ( V_9 -> V_17 , V_137 ,
false ) ;
V_13 -> V_29 [ V_24 ] = V_30 ;
V_13 -> V_144 [ V_90 ] = 0 ;
V_13 -> V_140 [ V_90 ] = 0 ;
memset ( V_122 , 0x00 , sizeof( * V_122 ) ) ;
}
V_13 -> V_135 = 0 ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_145 * V_146 )
{
struct V_5 * V_6 =
F_16 ( & V_146 -> V_147 ,
struct V_5 , V_31 ) ;
int V_11 ;
V_11 = F_59 ( V_2 -> V_4 ) ;
if ( V_11 < 0 )
return;
F_60 ( V_6 -> V_27 , V_2 -> V_148 + V_149 ) ;
F_60 ( V_150 , V_2 -> V_148 + V_151 ) ;
}
static struct V_145 * F_61 ( struct V_1 * V_2 )
{
struct V_145 * V_146 ;
if ( F_14 ( & V_2 -> V_152 ) )
return NULL ;
V_146 = F_16 ( & V_2 -> V_152 ,
struct V_145 , V_31 ) ;
F_17 ( & V_146 -> V_31 ) ;
return V_146 ;
}
static void F_62 ( struct V_1 * V_2 ,
struct V_145 * V_146 )
{
struct V_5 * V_6 ;
if ( ! V_146 )
return;
F_13 ( & V_2 -> V_33 ) ;
F_37 (node, &runqueue_node->run_cmdlist, list)
F_56 ( V_2 , V_6 , V_146 -> V_65 ) ;
F_63 ( & V_146 -> V_147 , & V_2 -> V_32 ) ;
F_15 ( & V_2 -> V_33 ) ;
F_64 ( V_2 -> V_153 , V_146 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
V_2 -> V_146 = F_61 ( V_2 ) ;
if ( V_2 -> V_146 )
F_58 ( V_2 , V_2 -> V_146 ) ;
}
static void F_66 ( struct V_154 * V_155 )
{
struct V_1 * V_2 = F_67 ( V_155 , struct V_1 ,
V_156 ) ;
F_13 ( & V_2 -> V_157 ) ;
F_68 ( V_2 -> V_4 ) ;
F_69 ( & V_2 -> V_146 -> F_69 ) ;
if ( V_2 -> V_146 -> V_158 )
F_62 ( V_2 , V_2 -> V_146 ) ;
if ( V_2 -> V_159 )
V_2 -> V_146 = NULL ;
else
F_65 ( V_2 ) ;
F_15 ( & V_2 -> V_157 ) ;
}
static void F_70 ( struct V_1 * V_2 , T_2 V_160 )
{
struct V_46 * V_17 = V_2 -> V_9 . V_17 ;
struct V_145 * V_146 = V_2 -> V_146 ;
struct V_161 * V_162 ;
struct V_163 V_164 ;
if ( F_14 ( & V_146 -> V_45 ) )
return;
V_162 = F_16 ( & V_146 -> V_45 ,
struct V_161 , V_43 . V_44 ) ;
F_71 ( & V_164 ) ;
V_162 -> V_42 . V_165 = V_164 . V_165 ;
V_162 -> V_42 . V_166 = V_164 . V_166 ;
V_162 -> V_42 . V_160 = V_160 ;
F_72 ( V_17 , & V_162 -> V_43 ) ;
}
static T_3 F_73 ( int V_167 , void * V_168 )
{
struct V_1 * V_2 = V_168 ;
T_2 V_169 ;
V_169 = F_74 ( V_2 -> V_148 + V_170 ) ;
if ( V_169 )
F_60 ( V_169 , V_2 -> V_148 + V_170 ) ;
if ( V_169 & V_171 ) {
T_2 V_160 = F_74 ( V_2 -> V_148 + V_172 ) ;
V_160 = ( V_160 & V_173 ) >>
V_174 ;
F_70 ( V_2 , V_160 ) ;
F_60 ( 0 , V_2 -> V_148 + V_175 ) ;
if ( ! ( V_169 & V_176 ) ) {
F_60 ( V_177 ,
V_2 -> V_148 + V_151 ) ;
}
}
if ( V_169 & V_176 )
F_75 ( V_2 -> V_178 , & V_2 -> V_156 ) ;
return V_179 ;
}
static int F_76 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
int V_10 , bool V_180 )
{
struct V_134 * V_25 = V_6 -> V_25 ;
int V_89 ;
int V_181 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_10 ; V_24 ++ ) {
struct V_12 * V_13 = & V_6 -> V_13 ;
struct V_121 * V_122 ;
enum V_88 V_90 ;
unsigned long V_182 ;
V_181 = V_25 -> V_41 - 2 * ( V_24 + 1 ) ;
V_89 = V_25 -> V_40 [ V_181 ] & ~ 0xfffff000 ;
if ( V_89 < V_183 || V_89 > V_184 )
goto V_23;
if ( V_89 % 4 )
goto V_23;
switch ( V_89 ) {
case V_91 :
case V_97 :
case V_99 :
case V_105 :
case V_107 :
case V_109 :
if ( ! V_180 )
goto V_23;
V_90 = F_49 ( V_89 ) ;
if ( ( V_25 -> V_40 [ V_181 ] & ~ 0x7fffffff ) >> 31 ) {
V_13 -> V_140 [ V_90 ] = V_185 ;
V_25 -> V_40 [ V_181 ] &= ~ V_186 ;
} else
V_13 -> V_140 [ V_90 ] = V_141 ;
break;
case V_92 :
case V_100 :
if ( V_180 )
goto V_23;
V_90 = F_49 ( V_89 ) ;
V_122 = & V_13 -> V_139 [ V_90 ] ;
V_122 -> V_132 = V_25 -> V_40 [ V_181 + 1 ] ;
break;
case V_93 :
case V_101 :
if ( V_180 )
goto V_23;
V_90 = F_49 ( V_89 ) ;
V_122 = & V_13 -> V_139 [ V_90 ] ;
V_182 = V_25 -> V_40 [ V_181 + 1 ] ;
V_122 -> V_111 = V_182 & 0xf ;
break;
case V_94 :
case V_102 :
if ( V_180 )
goto V_23;
V_90 = F_49 ( V_89 ) ;
V_122 = & V_13 -> V_139 [ V_90 ] ;
V_182 = V_25 -> V_40 [ V_181 + 1 ] ;
V_122 -> V_127 = V_182 & 0x1fff ;
V_122 -> V_131 = ( V_182 & 0x1fff0000 ) >> 16 ;
break;
case V_95 :
case V_103 :
if ( V_180 )
goto V_23;
V_90 = F_49 ( V_89 ) ;
V_122 = & V_13 -> V_139 [ V_90 ] ;
V_182 = V_25 -> V_40 [ V_181 + 1 ] ;
V_122 -> V_126 = V_182 & 0x1fff ;
V_122 -> V_130 = ( V_182 & 0x1fff0000 ) >> 16 ;
break;
default:
if ( V_180 )
goto V_23;
break;
}
}
return 0 ;
V_23:
F_6 ( V_4 , L_13 , V_25 -> V_40 [ V_181 ] ) ;
return - V_74 ;
}
int F_77 ( struct V_46 * V_17 , void * V_40 ,
struct V_64 * V_133 )
{
struct V_66 * V_67 = V_133 -> V_68 ;
struct V_34 * V_35 = V_67 -> V_35 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_187 * V_188 = V_40 ;
if ( ! V_35 )
return - V_189 ;
V_4 = V_35 -> V_4 ;
if ( ! V_4 )
return - V_189 ;
V_2 = F_36 ( V_4 ) ;
if ( ! V_2 )
return - V_79 ;
V_188 -> V_190 = V_191 ;
V_188 -> V_192 = V_193 ;
return 0 ;
}
int F_78 ( struct V_46 * V_17 , void * V_40 ,
struct V_64 * V_133 )
{
struct V_66 * V_67 = V_133 -> V_68 ;
struct V_34 * V_35 = V_67 -> V_35 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_194 * V_195 = V_40 ;
struct V_196 * V_197 ;
struct V_161 * V_162 ;
struct V_5 * V_6 ;
struct V_134 * V_25 ;
int V_63 ;
int V_11 ;
if ( ! V_35 )
return - V_189 ;
V_4 = V_35 -> V_4 ;
if ( ! V_4 )
return - V_189 ;
V_2 = F_36 ( V_4 ) ;
if ( ! V_2 )
return - V_79 ;
V_6 = F_12 ( V_2 ) ;
if ( ! V_6 )
return - V_21 ;
V_6 -> V_42 = NULL ;
if ( V_195 -> V_198 != V_199 ) {
V_162 = F_39 ( sizeof( * V_6 -> V_42 ) , V_20 ) ;
if ( ! V_162 ) {
V_11 = - V_21 ;
goto V_23;
}
V_162 -> V_42 . V_43 . type = V_200 ;
V_162 -> V_42 . V_43 . V_201 = sizeof( V_162 -> V_42 ) ;
V_162 -> V_42 . V_202 = V_195 -> V_202 ;
V_11 = F_79 ( V_17 , V_133 , & V_162 -> V_43 , & V_162 -> V_42 . V_43 ) ;
if ( V_11 ) {
F_11 ( V_162 ) ;
goto V_23;
}
V_6 -> V_42 = V_162 ;
}
V_25 = V_6 -> V_25 ;
V_25 -> V_41 = 0 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_203 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_204 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_91 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = 0 ;
if ( V_6 -> V_42 ) {
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_205 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_206 | V_207 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_175 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_208 ;
} else {
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_205 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_206 ;
}
V_63 = V_25 -> V_41 + V_195 -> V_209 * 2 + V_195 -> V_210 * 2 + 2 ;
if ( V_63 > V_211 ) {
F_6 ( V_4 , L_14 ) ;
V_11 = - V_74 ;
goto V_212;
}
V_197 = (struct V_196 * ) ( unsigned long ) V_195 -> V_197 ;
if ( F_55 ( V_25 -> V_40 + V_25 -> V_41 ,
( void V_143 * ) V_197 ,
sizeof( * V_197 ) * V_195 -> V_209 ) ) {
V_11 = - V_79 ;
goto V_212;
}
V_25 -> V_41 += V_195 -> V_209 * 2 ;
V_11 = F_76 ( V_4 , V_6 , V_195 -> V_209 , false ) ;
if ( V_11 < 0 )
goto V_212;
V_6 -> V_13 . V_135 = V_195 -> V_210 ;
if ( V_195 -> V_210 ) {
struct V_196 * V_213 ;
V_213 = (struct V_196 * )
( unsigned long ) V_195 -> V_213 ;
if ( F_55 ( V_25 -> V_40 + V_25 -> V_41 ,
( void V_143 * ) V_213 ,
sizeof( * V_213 ) * V_195 -> V_210 ) ) {
V_11 = - V_79 ;
goto V_212;
}
V_25 -> V_41 += V_195 -> V_210 * 2 ;
V_11 = F_76 ( V_4 , V_6 , V_195 -> V_210 , true ) ;
if ( V_11 < 0 )
goto V_212;
V_11 = F_52 ( V_2 , V_6 , V_17 , V_133 ) ;
if ( V_11 < 0 )
goto V_214;
}
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_215 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_216 ;
V_25 -> V_217 = V_25 -> V_41 / 2 ;
V_25 -> V_40 [ V_25 -> V_41 ] = 0 ;
F_20 ( V_35 , V_6 ) ;
return 0 ;
V_214:
F_56 ( V_2 , V_6 , V_133 ) ;
V_212:
if ( V_6 -> V_42 )
F_80 ( V_17 , & V_6 -> V_42 -> V_43 ) ;
V_23:
F_18 ( V_2 , V_6 ) ;
return V_11 ;
}
int F_81 ( struct V_46 * V_17 , void * V_40 ,
struct V_64 * V_133 )
{
struct V_66 * V_67 = V_133 -> V_68 ;
struct V_34 * V_35 = V_67 -> V_35 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_218 * V_195 = V_40 ;
struct V_145 * V_146 ;
struct V_219 * V_147 ;
struct V_219 * V_45 ;
if ( ! V_35 )
return - V_189 ;
V_4 = V_35 -> V_4 ;
if ( ! V_4 )
return - V_189 ;
V_2 = F_36 ( V_4 ) ;
if ( ! V_2 )
return - V_79 ;
V_146 = F_82 ( V_2 -> V_153 , V_20 ) ;
if ( ! V_146 ) {
F_6 ( V_4 , L_2 ) ;
return - V_21 ;
}
V_147 = & V_146 -> V_147 ;
V_45 = & V_146 -> V_45 ;
F_83 ( V_147 ) ;
F_83 ( V_45 ) ;
F_84 ( & V_146 -> F_69 ) ;
V_146 -> V_158 = V_195 -> V_158 ;
F_85 ( & V_35 -> V_37 , V_147 ) ;
F_85 ( & V_35 -> V_45 , V_45 ) ;
if ( F_14 ( V_147 ) ) {
F_6 ( V_4 , L_15 ) ;
F_64 ( V_2 -> V_153 , V_146 ) ;
return - V_220 ;
}
F_13 ( & V_2 -> V_157 ) ;
V_146 -> V_221 = V_222 -> V_221 ;
V_146 -> V_65 = V_133 ;
F_8 ( & V_146 -> V_31 , & V_2 -> V_152 ) ;
if ( ! V_2 -> V_146 )
F_65 ( V_2 ) ;
F_15 ( & V_2 -> V_157 ) ;
if ( V_146 -> V_158 )
goto V_53;
F_86 ( & V_146 -> F_69 ) ;
F_62 ( V_2 , V_146 ) ;
V_53:
return 0 ;
}
static int F_87 ( struct V_46 * V_17 , struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_11 ;
V_2 = F_36 ( V_4 ) ;
if ( ! V_2 )
return - V_79 ;
V_11 = F_1 ( V_2 ) ;
if ( V_11 < 0 ) {
F_6 ( V_4 , L_16 ) ;
return V_11 ;
}
V_11 = F_88 ( V_17 , V_4 ) ;
if ( V_11 < 0 ) {
F_6 ( V_4 , L_17 ) ;
F_10 ( V_2 ) ;
}
return V_11 ;
}
static void F_89 ( struct V_46 * V_17 , struct V_3 * V_4 )
{
F_90 ( V_17 , V_4 ) ;
}
static int F_91 ( struct V_46 * V_17 , struct V_3 * V_4 ,
struct V_64 * V_133 )
{
struct V_66 * V_67 = V_133 -> V_68 ;
struct V_34 * V_35 ;
V_35 = F_39 ( sizeof( * V_35 ) , V_20 ) ;
if ( ! V_35 )
return - V_21 ;
V_35 -> V_4 = V_4 ;
V_67 -> V_35 = V_35 ;
F_83 ( & V_35 -> V_37 ) ;
F_83 ( & V_35 -> V_45 ) ;
F_83 ( & V_35 -> V_84 ) ;
return 0 ;
}
static void F_92 ( struct V_46 * V_17 , struct V_3 * V_4 ,
struct V_64 * V_133 )
{
struct V_66 * V_67 = V_133 -> V_68 ;
struct V_34 * V_35 = V_67 -> V_35 ;
struct V_1 * V_2 ;
struct V_5 * V_6 , * V_87 ;
if ( ! V_4 )
return;
V_2 = F_36 ( V_4 ) ;
if ( ! V_2 )
return;
F_13 ( & V_2 -> V_33 ) ;
F_48 (node, n, &g2d_priv->inuse_cmdlist, list) {
F_56 ( V_2 , V_6 , V_133 ) ;
F_19 ( & V_6 -> V_31 , & V_2 -> V_32 ) ;
}
F_15 ( & V_2 -> V_33 ) ;
F_47 ( V_17 , V_2 , V_133 ) ;
F_11 ( V_67 -> V_35 ) ;
}
static int F_93 ( struct V_223 * V_224 )
{
struct V_3 * V_4 = & V_224 -> V_4 ;
struct V_225 * V_226 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_11 ;
V_2 = F_94 ( V_4 , sizeof( * V_2 ) , V_20 ) ;
if ( ! V_2 )
return - V_21 ;
V_2 -> V_153 = F_95 ( L_18 ,
sizeof( struct V_145 ) , 0 , 0 , NULL ) ;
if ( ! V_2 -> V_153 )
return - V_21 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_178 = F_96 ( L_19 ) ;
if ( ! V_2 -> V_178 ) {
F_6 ( V_4 , L_20 ) ;
V_11 = - V_74 ;
goto V_227;
}
F_97 ( & V_2 -> V_156 , F_66 ) ;
F_83 ( & V_2 -> V_32 ) ;
F_83 ( & V_2 -> V_152 ) ;
F_98 ( & V_2 -> V_33 ) ;
F_98 ( & V_2 -> V_157 ) ;
V_2 -> V_228 = F_99 ( V_4 , L_21 ) ;
if ( F_27 ( V_2 -> V_228 ) ) {
F_6 ( V_4 , L_22 ) ;
V_11 = F_100 ( V_2 -> V_228 ) ;
goto V_229;
}
F_101 ( V_4 ) ;
V_226 = F_102 ( V_224 , V_230 , 0 ) ;
V_2 -> V_148 = F_103 ( V_4 , V_226 ) ;
if ( F_27 ( V_2 -> V_148 ) ) {
V_11 = F_100 ( V_2 -> V_148 ) ;
goto V_231;
}
V_2 -> V_167 = F_104 ( V_224 , 0 ) ;
if ( V_2 -> V_167 < 0 ) {
F_6 ( V_4 , L_23 ) ;
V_11 = V_2 -> V_167 ;
goto V_231;
}
V_11 = F_105 ( V_4 , V_2 -> V_167 , F_73 , 0 ,
L_24 , V_2 ) ;
if ( V_11 < 0 ) {
F_6 ( V_4 , L_25 ) ;
goto V_231;
}
V_2 -> V_86 = V_232 ;
F_106 ( V_224 , V_2 ) ;
V_9 = & V_2 -> V_9 ;
V_9 -> V_4 = V_4 ;
V_9 -> V_233 = F_87 ;
V_9 -> remove = F_89 ;
V_9 -> V_234 = F_91 ;
V_9 -> V_235 = F_92 ;
V_11 = F_107 ( V_9 ) ;
if ( V_11 < 0 ) {
F_6 ( V_4 , L_26 ) ;
goto V_231;
}
F_108 ( V_4 , L_27 ,
V_191 , V_193 ) ;
return 0 ;
V_231:
F_109 ( V_4 ) ;
V_229:
F_110 ( V_2 -> V_178 ) ;
V_227:
F_111 ( V_2 -> V_153 ) ;
return V_11 ;
}
static int F_112 ( struct V_223 * V_224 )
{
struct V_1 * V_2 = F_113 ( V_224 ) ;
F_114 ( & V_2 -> V_156 ) ;
F_115 ( & V_2 -> V_9 ) ;
while ( V_2 -> V_146 ) {
F_62 ( V_2 , V_2 -> V_146 ) ;
V_2 -> V_146 = F_61 ( V_2 ) ;
}
F_109 ( & V_224 -> V_4 ) ;
F_10 ( V_2 ) ;
F_110 ( V_2 -> V_178 ) ;
F_111 ( V_2 -> V_153 ) ;
return 0 ;
}
static int F_116 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_36 ( V_4 ) ;
F_13 ( & V_2 -> V_157 ) ;
V_2 -> V_159 = true ;
F_15 ( & V_2 -> V_157 ) ;
while ( V_2 -> V_146 )
F_117 ( 500 , 1000 ) ;
F_118 ( & V_2 -> V_156 ) ;
return 0 ;
}
static int F_119 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_36 ( V_4 ) ;
V_2 -> V_159 = false ;
F_65 ( V_2 ) ;
return 0 ;
}
static int F_120 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_36 ( V_4 ) ;
F_121 ( V_2 -> V_228 ) ;
return 0 ;
}
static int F_122 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_36 ( V_4 ) ;
int V_11 ;
V_11 = F_123 ( V_2 -> V_228 ) ;
if ( V_11 < 0 )
F_124 ( V_4 , L_28 ) ;
return V_11 ;
}
