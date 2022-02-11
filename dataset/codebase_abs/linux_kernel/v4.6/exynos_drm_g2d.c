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
F_25 ( V_17 , V_50 -> V_56 ,
V_57 ) ;
V_52 = F_26 ( V_50 -> V_58 ) ;
if ( ! F_27 ( V_52 ) ) {
int V_24 ;
for ( V_24 = 0 ; V_24 < F_28 ( V_50 -> V_58 ) ; V_24 ++ )
F_29 ( V_52 [ V_24 ] ) ;
}
F_30 ( V_50 -> V_58 ) ;
F_31 ( V_50 -> V_58 ) ;
if ( ! V_50 -> V_59 )
F_17 ( & V_50 -> V_31 ) ;
F_32 ( V_50 -> V_56 ) ;
F_11 ( V_50 -> V_56 ) ;
F_11 ( V_50 ) ;
}
static T_1 * F_33 ( struct V_46 * V_17 ,
unsigned long V_60 ,
unsigned long V_61 ,
struct V_62 * V_63 ,
unsigned long * V_47 )
{
struct V_64 * V_65 = V_63 -> V_66 ;
struct V_34 * V_35 = V_65 -> V_35 ;
struct V_49 * V_50 ;
struct V_1 * V_2 ;
struct V_67 * V_56 ;
unsigned long V_68 , V_69 ;
unsigned int V_70 , V_71 ;
int V_11 ;
if ( ! V_61 ) {
F_34 ( L_4 ) ;
return F_35 ( - V_72 ) ;
}
V_2 = F_36 ( V_35 -> V_4 ) ;
F_37 (g2d_userptr, &g2d_priv->userptr_list, list) {
if ( V_50 -> V_60 == V_60 ) {
if ( V_50 -> V_61 == V_61 ) {
F_38 ( & V_50 -> V_54 ) ;
* V_47 = ( unsigned long ) V_50 ;
return & V_50 -> V_27 ;
}
V_50 -> V_59 = true ;
V_50 -> V_55 = false ;
F_17 ( & V_50 -> V_31 ) ;
break;
}
}
V_50 = F_39 ( sizeof( * V_50 ) , V_20 ) ;
if ( ! V_50 )
return F_35 ( - V_21 ) ;
F_40 ( & V_50 -> V_54 , 1 ) ;
V_50 -> V_61 = V_61 ;
V_68 = V_60 & V_73 ;
V_71 = V_60 & ~ V_73 ;
V_69 = F_41 ( V_60 + V_61 ) ;
V_70 = ( V_69 - V_68 ) >> V_74 ;
V_50 -> V_58 = F_42 ( V_70 ) ;
if ( ! V_50 -> V_58 ) {
V_11 = - V_21 ;
goto V_75;
}
V_11 = F_43 ( V_68 , V_70 , true , true , V_50 -> V_58 ) ;
if ( V_11 != V_70 ) {
F_34 ( L_5 ) ;
if ( V_11 < 0 )
goto V_76;
V_11 = - V_77 ;
goto V_78;
}
if ( F_44 ( V_50 -> V_58 ) < 0 ) {
V_11 = - V_77 ;
goto V_78;
}
V_56 = F_39 ( sizeof( * V_56 ) , V_20 ) ;
if ( ! V_56 ) {
V_11 = - V_21 ;
goto V_78;
}
V_11 = F_45 ( V_56 ,
F_26 ( V_50 -> V_58 ) ,
V_70 , V_71 , V_61 , V_20 ) ;
if ( V_11 < 0 ) {
F_34 ( L_6 ) ;
goto V_79;
}
V_50 -> V_56 = V_56 ;
V_11 = F_46 ( V_17 , V_50 -> V_56 ,
V_57 ) ;
if ( V_11 < 0 ) {
F_34 ( L_7 ) ;
goto V_80;
}
V_50 -> V_27 = V_56 -> V_81 [ 0 ] . V_82 ;
V_50 -> V_60 = V_60 ;
F_8 ( & V_50 -> V_31 , & V_35 -> V_83 ) ;
if ( V_2 -> V_84 + ( V_70 << V_74 ) < V_2 -> V_85 ) {
V_2 -> V_84 += V_70 << V_74 ;
V_50 -> V_55 = true ;
}
* V_47 = ( unsigned long ) V_50 ;
return & V_50 -> V_27 ;
V_80:
F_32 ( V_56 ) ;
V_79:
F_11 ( V_56 ) ;
V_78:
F_30 ( V_50 -> V_58 ) ;
V_76:
F_31 ( V_50 -> V_58 ) ;
V_75:
F_11 ( V_50 ) ;
return F_35 ( V_11 ) ;
}
static void F_47 ( struct V_46 * V_17 ,
struct V_1 * V_2 ,
struct V_62 * V_63 )
{
struct V_64 * V_65 = V_63 -> V_66 ;
struct V_34 * V_35 = V_65 -> V_35 ;
struct V_49 * V_50 , * V_86 ;
F_48 (g2d_userptr, n, &g2d_priv->userptr_list, list)
if ( V_50 -> V_55 )
F_22 ( V_17 ,
( unsigned long ) V_50 ,
true ) ;
V_2 -> V_84 = 0 ;
}
static enum V_87 F_49 ( int V_88 )
{
enum V_87 V_89 ;
switch ( V_88 ) {
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
V_89 = V_95 ;
break;
case V_96 :
V_89 = V_97 ;
break;
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
V_89 = V_103 ;
break;
case V_104 :
V_89 = V_105 ;
break;
case V_106 :
V_89 = V_107 ;
break;
case V_108 :
V_89 = V_109 ;
break;
default:
V_89 = V_30 ;
F_34 ( L_8 , V_88 ) ;
break;
}
return V_89 ;
}
static unsigned long F_50 ( unsigned int V_110 )
{
unsigned long V_111 ;
switch ( V_110 ) {
case V_112 :
case V_113 :
V_111 = 4 ;
break;
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
V_111 = 2 ;
break;
case V_119 :
V_111 = 3 ;
break;
default:
V_111 = 1 ;
break;
}
return V_111 ;
}
static bool F_51 ( struct V_120 * V_121 ,
enum V_87 V_89 ,
unsigned long V_61 )
{
int V_122 , V_123 ;
unsigned long V_111 , V_124 ;
if ( V_89 != V_95 && V_89 != V_103 )
return true ;
V_122 = ( int ) V_121 -> V_125 - ( int ) V_121 -> V_126 ;
if ( V_122 < V_127 || V_122 > V_128 ) {
F_34 ( L_9 , V_122 ) ;
return false ;
}
V_123 = ( int ) V_121 -> V_129 - ( int ) V_121 -> V_130 ;
if ( V_123 < V_127 || V_123 > V_128 ) {
F_34 ( L_10 , V_123 ) ;
return false ;
}
V_111 = F_50 ( V_121 -> V_110 ) ;
V_124 = ( ( unsigned long ) V_121 -> V_129 - 1 ) *
( unsigned long ) V_121 -> V_131 +
( unsigned long ) V_121 -> V_125 * V_111 - 1 ;
if ( V_124 >= V_61 ) {
F_34 ( L_11
L_12 , V_124 , V_61 ) ;
return false ;
}
return true ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_46 * V_17 ,
struct V_62 * V_132 )
{
struct V_133 * V_25 = V_6 -> V_25 ;
struct V_12 * V_13 = & V_6 -> V_13 ;
int V_71 ;
int V_11 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_13 -> V_134 ; V_24 ++ ) {
struct V_120 * V_121 ;
enum V_87 V_89 ;
int V_135 ;
unsigned long V_136 ;
T_1 * V_137 ;
V_135 = V_25 -> V_41 - 2 * ( V_24 + 1 ) ;
V_71 = V_25 -> V_40 [ V_135 ] ;
V_136 = V_25 -> V_40 [ V_135 + 1 ] ;
V_89 = F_49 ( V_71 ) ;
if ( V_89 == V_30 ) {
V_11 = - V_77 ;
goto V_23;
}
V_121 = & V_13 -> V_138 [ V_89 ] ;
if ( V_13 -> V_139 [ V_89 ] == V_140 ) {
unsigned long V_61 ;
V_61 = F_53 ( V_17 , V_136 , V_132 ) ;
if ( ! V_61 ) {
V_11 = - V_77 ;
goto V_23;
}
if ( ! F_51 ( V_121 , V_89 ,
V_61 ) ) {
V_11 = - V_77 ;
goto V_23;
}
V_137 = F_54 ( V_17 , V_136 ,
V_132 ) ;
if ( F_27 ( V_137 ) ) {
V_11 = - V_77 ;
goto V_23;
}
} else {
struct V_141 V_50 ;
if ( F_55 ( & V_50 , ( void V_142 * ) V_136 ,
sizeof( struct V_141 ) ) ) {
V_11 = - V_77 ;
goto V_23;
}
if ( ! F_51 ( V_121 , V_89 ,
V_50 . V_61 ) ) {
V_11 = - V_77 ;
goto V_23;
}
V_137 = F_33 ( V_17 ,
V_50 . V_60 ,
V_50 . V_61 ,
V_132 ,
& V_136 ) ;
if ( F_27 ( V_137 ) ) {
V_11 = - V_77 ;
goto V_23;
}
}
V_25 -> V_40 [ V_135 + 1 ] = * V_137 ;
V_13 -> V_29 [ V_24 ] = V_89 ;
V_13 -> V_143 [ V_89 ] = V_136 ;
}
return 0 ;
V_23:
V_13 -> V_134 = V_24 ;
return V_11 ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_62 * V_63 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_12 * V_13 = & V_6 -> V_13 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_13 -> V_134 ; V_24 ++ ) {
struct V_120 * V_121 ;
enum V_87 V_89 ;
unsigned long V_136 ;
V_89 = V_13 -> V_29 [ V_24 ] ;
V_121 = & V_13 -> V_138 [ V_89 ] ;
V_136 = V_13 -> V_143 [ V_89 ] ;
if ( V_13 -> V_139 [ V_89 ] == V_140 )
F_57 ( V_9 -> V_17 , V_136 ,
V_63 ) ;
else
F_22 ( V_9 -> V_17 , V_136 ,
false ) ;
V_13 -> V_29 [ V_24 ] = V_30 ;
V_13 -> V_143 [ V_89 ] = 0 ;
V_13 -> V_139 [ V_89 ] = 0 ;
memset ( V_121 , 0x00 , sizeof( * V_121 ) ) ;
}
V_13 -> V_134 = 0 ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_144 * V_145 )
{
struct V_5 * V_6 =
F_16 ( & V_145 -> V_146 ,
struct V_5 , V_31 ) ;
int V_11 ;
V_11 = F_59 ( V_2 -> V_4 ) ;
if ( V_11 < 0 )
return;
F_60 ( V_6 -> V_27 , V_2 -> V_147 + V_148 ) ;
F_60 ( V_149 , V_2 -> V_147 + V_150 ) ;
}
static struct V_144 * F_61 ( struct V_1 * V_2 )
{
struct V_144 * V_145 ;
if ( F_14 ( & V_2 -> V_151 ) )
return NULL ;
V_145 = F_16 ( & V_2 -> V_151 ,
struct V_144 , V_31 ) ;
F_17 ( & V_145 -> V_31 ) ;
return V_145 ;
}
static void F_62 ( struct V_1 * V_2 ,
struct V_144 * V_145 )
{
struct V_5 * V_6 ;
if ( ! V_145 )
return;
F_13 ( & V_2 -> V_33 ) ;
F_37 (node, &runqueue_node->run_cmdlist, list)
F_56 ( V_2 , V_6 , V_145 -> V_63 ) ;
F_63 ( & V_145 -> V_146 , & V_2 -> V_32 ) ;
F_15 ( & V_2 -> V_33 ) ;
F_64 ( V_2 -> V_152 , V_145 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
V_2 -> V_145 = F_61 ( V_2 ) ;
if ( V_2 -> V_145 )
F_58 ( V_2 , V_2 -> V_145 ) ;
}
static void F_66 ( struct V_153 * V_154 )
{
struct V_1 * V_2 = F_67 ( V_154 , struct V_1 ,
V_155 ) ;
F_13 ( & V_2 -> V_156 ) ;
F_68 ( V_2 -> V_4 ) ;
F_69 ( & V_2 -> V_145 -> F_69 ) ;
if ( V_2 -> V_145 -> V_157 )
F_62 ( V_2 , V_2 -> V_145 ) ;
if ( V_2 -> V_158 )
V_2 -> V_145 = NULL ;
else
F_65 ( V_2 ) ;
F_15 ( & V_2 -> V_156 ) ;
}
static void F_70 ( struct V_1 * V_2 , T_2 V_159 )
{
struct V_46 * V_17 = V_2 -> V_9 . V_17 ;
struct V_144 * V_145 = V_2 -> V_145 ;
struct V_160 * V_161 ;
struct V_162 V_163 ;
if ( F_14 ( & V_145 -> V_45 ) )
return;
V_161 = F_16 ( & V_145 -> V_45 ,
struct V_160 , V_43 . V_44 ) ;
F_71 ( & V_163 ) ;
V_161 -> V_42 . V_164 = V_163 . V_164 ;
V_161 -> V_42 . V_165 = V_163 . V_165 ;
V_161 -> V_42 . V_159 = V_159 ;
F_72 ( V_17 , & V_161 -> V_43 ) ;
}
static T_3 F_73 ( int V_166 , void * V_167 )
{
struct V_1 * V_2 = V_167 ;
T_2 V_168 ;
V_168 = F_74 ( V_2 -> V_147 + V_169 ) ;
if ( V_168 )
F_60 ( V_168 , V_2 -> V_147 + V_169 ) ;
if ( V_168 & V_170 ) {
T_2 V_159 = F_74 ( V_2 -> V_147 + V_171 ) ;
V_159 = ( V_159 & V_172 ) >>
V_173 ;
F_70 ( V_2 , V_159 ) ;
F_60 ( 0 , V_2 -> V_147 + V_174 ) ;
if ( ! ( V_168 & V_175 ) ) {
F_60 ( V_176 ,
V_2 -> V_147 + V_150 ) ;
}
}
if ( V_168 & V_175 )
F_75 ( V_2 -> V_177 , & V_2 -> V_155 ) ;
return V_178 ;
}
static int F_76 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
int V_10 , bool V_179 )
{
struct V_133 * V_25 = V_6 -> V_25 ;
int V_88 ;
int V_180 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_10 ; V_24 ++ ) {
struct V_12 * V_13 = & V_6 -> V_13 ;
struct V_120 * V_121 ;
enum V_87 V_89 ;
unsigned long V_181 ;
V_180 = V_25 -> V_41 - 2 * ( V_24 + 1 ) ;
V_88 = V_25 -> V_40 [ V_180 ] & ~ 0xfffff000 ;
if ( V_88 < V_182 || V_88 > V_183 )
goto V_23;
if ( V_88 % 4 )
goto V_23;
switch ( V_88 ) {
case V_90 :
case V_96 :
case V_98 :
case V_104 :
case V_106 :
case V_108 :
if ( ! V_179 )
goto V_23;
V_89 = F_49 ( V_88 ) ;
if ( ( V_25 -> V_40 [ V_180 ] & ~ 0x7fffffff ) >> 31 ) {
V_13 -> V_139 [ V_89 ] = V_184 ;
V_25 -> V_40 [ V_180 ] &= ~ V_185 ;
} else
V_13 -> V_139 [ V_89 ] = V_140 ;
break;
case V_91 :
case V_99 :
if ( V_179 )
goto V_23;
V_89 = F_49 ( V_88 ) ;
V_121 = & V_13 -> V_138 [ V_89 ] ;
V_121 -> V_131 = V_25 -> V_40 [ V_180 + 1 ] ;
break;
case V_92 :
case V_100 :
if ( V_179 )
goto V_23;
V_89 = F_49 ( V_88 ) ;
V_121 = & V_13 -> V_138 [ V_89 ] ;
V_181 = V_25 -> V_40 [ V_180 + 1 ] ;
V_121 -> V_110 = V_181 & 0xf ;
break;
case V_93 :
case V_101 :
if ( V_179 )
goto V_23;
V_89 = F_49 ( V_88 ) ;
V_121 = & V_13 -> V_138 [ V_89 ] ;
V_181 = V_25 -> V_40 [ V_180 + 1 ] ;
V_121 -> V_126 = V_181 & 0x1fff ;
V_121 -> V_130 = ( V_181 & 0x1fff0000 ) >> 16 ;
break;
case V_94 :
case V_102 :
if ( V_179 )
goto V_23;
V_89 = F_49 ( V_88 ) ;
V_121 = & V_13 -> V_138 [ V_89 ] ;
V_181 = V_25 -> V_40 [ V_180 + 1 ] ;
V_121 -> V_125 = V_181 & 0x1fff ;
V_121 -> V_129 = ( V_181 & 0x1fff0000 ) >> 16 ;
break;
default:
if ( V_179 )
goto V_23;
break;
}
}
return 0 ;
V_23:
F_6 ( V_4 , L_13 , V_25 -> V_40 [ V_180 ] ) ;
return - V_72 ;
}
int F_77 ( struct V_46 * V_17 , void * V_40 ,
struct V_62 * V_132 )
{
struct V_64 * V_65 = V_132 -> V_66 ;
struct V_34 * V_35 = V_65 -> V_35 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_186 * V_187 = V_40 ;
if ( ! V_35 )
return - V_188 ;
V_4 = V_35 -> V_4 ;
if ( ! V_4 )
return - V_188 ;
V_2 = F_36 ( V_4 ) ;
if ( ! V_2 )
return - V_77 ;
V_187 -> V_189 = V_190 ;
V_187 -> V_191 = V_192 ;
return 0 ;
}
int F_78 ( struct V_46 * V_17 , void * V_40 ,
struct V_62 * V_132 )
{
struct V_64 * V_65 = V_132 -> V_66 ;
struct V_34 * V_35 = V_65 -> V_35 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_193 * V_194 = V_40 ;
struct V_195 * V_196 ;
struct V_160 * V_161 ;
struct V_5 * V_6 ;
struct V_133 * V_25 ;
int V_61 ;
int V_11 ;
if ( ! V_35 )
return - V_188 ;
V_4 = V_35 -> V_4 ;
if ( ! V_4 )
return - V_188 ;
V_2 = F_36 ( V_4 ) ;
if ( ! V_2 )
return - V_77 ;
V_6 = F_12 ( V_2 ) ;
if ( ! V_6 )
return - V_21 ;
V_6 -> V_42 = NULL ;
if ( V_194 -> V_197 != V_198 ) {
V_161 = F_39 ( sizeof( * V_6 -> V_42 ) , V_20 ) ;
if ( ! V_161 ) {
V_11 = - V_21 ;
goto V_23;
}
V_161 -> V_42 . V_43 . type = V_199 ;
V_161 -> V_42 . V_43 . V_200 = sizeof( V_161 -> V_42 ) ;
V_161 -> V_42 . V_201 = V_194 -> V_201 ;
V_11 = F_79 ( V_17 , V_132 , & V_161 -> V_43 , & V_161 -> V_42 . V_43 ) ;
if ( V_11 ) {
F_11 ( V_161 ) ;
goto V_23;
}
V_6 -> V_42 = V_161 ;
}
V_25 = V_6 -> V_25 ;
V_25 -> V_41 = 0 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_202 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_203 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_90 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = 0 ;
if ( V_6 -> V_42 ) {
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_204 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_205 | V_206 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_174 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_207 ;
} else {
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_204 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_205 ;
}
V_61 = V_25 -> V_41 + V_194 -> V_208 * 2 + V_194 -> V_209 * 2 + 2 ;
if ( V_61 > V_210 ) {
F_6 ( V_4 , L_14 ) ;
V_11 = - V_72 ;
goto V_211;
}
V_196 = (struct V_195 * ) ( unsigned long ) V_194 -> V_196 ;
if ( F_55 ( V_25 -> V_40 + V_25 -> V_41 ,
( void V_142 * ) V_196 ,
sizeof( * V_196 ) * V_194 -> V_208 ) ) {
V_11 = - V_77 ;
goto V_211;
}
V_25 -> V_41 += V_194 -> V_208 * 2 ;
V_11 = F_76 ( V_4 , V_6 , V_194 -> V_208 , false ) ;
if ( V_11 < 0 )
goto V_211;
V_6 -> V_13 . V_134 = V_194 -> V_209 ;
if ( V_194 -> V_209 ) {
struct V_195 * V_212 ;
V_212 = (struct V_195 * )
( unsigned long ) V_194 -> V_212 ;
if ( F_55 ( V_25 -> V_40 + V_25 -> V_41 ,
( void V_142 * ) V_212 ,
sizeof( * V_212 ) * V_194 -> V_209 ) ) {
V_11 = - V_77 ;
goto V_211;
}
V_25 -> V_41 += V_194 -> V_209 * 2 ;
V_11 = F_76 ( V_4 , V_6 , V_194 -> V_209 , true ) ;
if ( V_11 < 0 )
goto V_211;
V_11 = F_52 ( V_2 , V_6 , V_17 , V_132 ) ;
if ( V_11 < 0 )
goto V_213;
}
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_214 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_215 ;
V_25 -> V_216 = V_25 -> V_41 / 2 ;
V_25 -> V_40 [ V_25 -> V_41 ] = 0 ;
F_20 ( V_35 , V_6 ) ;
return 0 ;
V_213:
F_56 ( V_2 , V_6 , V_132 ) ;
V_211:
if ( V_6 -> V_42 )
F_80 ( V_17 , & V_6 -> V_42 -> V_43 ) ;
V_23:
F_18 ( V_2 , V_6 ) ;
return V_11 ;
}
int F_81 ( struct V_46 * V_17 , void * V_40 ,
struct V_62 * V_132 )
{
struct V_64 * V_65 = V_132 -> V_66 ;
struct V_34 * V_35 = V_65 -> V_35 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_217 * V_194 = V_40 ;
struct V_144 * V_145 ;
struct V_218 * V_146 ;
struct V_218 * V_45 ;
if ( ! V_35 )
return - V_188 ;
V_4 = V_35 -> V_4 ;
if ( ! V_4 )
return - V_188 ;
V_2 = F_36 ( V_4 ) ;
if ( ! V_2 )
return - V_77 ;
V_145 = F_82 ( V_2 -> V_152 , V_20 ) ;
if ( ! V_145 ) {
F_6 ( V_4 , L_2 ) ;
return - V_21 ;
}
V_146 = & V_145 -> V_146 ;
V_45 = & V_145 -> V_45 ;
F_83 ( V_146 ) ;
F_83 ( V_45 ) ;
F_84 ( & V_145 -> F_69 ) ;
V_145 -> V_157 = V_194 -> V_157 ;
F_85 ( & V_35 -> V_37 , V_146 ) ;
F_85 ( & V_35 -> V_45 , V_45 ) ;
if ( F_14 ( V_146 ) ) {
F_6 ( V_4 , L_15 ) ;
F_64 ( V_2 -> V_152 , V_145 ) ;
return - V_219 ;
}
F_13 ( & V_2 -> V_156 ) ;
V_145 -> V_220 = V_221 -> V_220 ;
V_145 -> V_63 = V_132 ;
F_8 ( & V_145 -> V_31 , & V_2 -> V_151 ) ;
if ( ! V_2 -> V_145 )
F_65 ( V_2 ) ;
F_15 ( & V_2 -> V_156 ) ;
if ( V_145 -> V_157 )
goto V_53;
F_86 ( & V_145 -> F_69 ) ;
F_62 ( V_2 , V_145 ) ;
V_53:
return 0 ;
}
static int F_87 ( struct V_46 * V_17 , struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_11 ;
V_2 = F_36 ( V_4 ) ;
if ( ! V_2 )
return - V_77 ;
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
struct V_62 * V_132 )
{
struct V_64 * V_65 = V_132 -> V_66 ;
struct V_34 * V_35 ;
V_35 = F_39 ( sizeof( * V_35 ) , V_20 ) ;
if ( ! V_35 )
return - V_21 ;
V_35 -> V_4 = V_4 ;
V_65 -> V_35 = V_35 ;
F_83 ( & V_35 -> V_37 ) ;
F_83 ( & V_35 -> V_45 ) ;
F_83 ( & V_35 -> V_83 ) ;
return 0 ;
}
static void F_92 ( struct V_46 * V_17 , struct V_3 * V_4 ,
struct V_62 * V_132 )
{
struct V_64 * V_65 = V_132 -> V_66 ;
struct V_34 * V_35 = V_65 -> V_35 ;
struct V_1 * V_2 ;
struct V_5 * V_6 , * V_86 ;
if ( ! V_4 )
return;
V_2 = F_36 ( V_4 ) ;
if ( ! V_2 )
return;
F_13 ( & V_2 -> V_33 ) ;
F_48 (node, n, &g2d_priv->inuse_cmdlist, list) {
F_56 ( V_2 , V_6 , V_132 ) ;
F_19 ( & V_6 -> V_31 , & V_2 -> V_32 ) ;
}
F_15 ( & V_2 -> V_33 ) ;
F_47 ( V_17 , V_2 , V_132 ) ;
F_11 ( V_65 -> V_35 ) ;
}
static int F_93 ( struct V_222 * V_223 )
{
struct V_3 * V_4 = & V_223 -> V_4 ;
struct V_224 * V_225 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_11 ;
V_2 = F_94 ( V_4 , sizeof( * V_2 ) , V_20 ) ;
if ( ! V_2 )
return - V_21 ;
V_2 -> V_152 = F_95 ( L_18 ,
sizeof( struct V_144 ) , 0 , 0 , NULL ) ;
if ( ! V_2 -> V_152 )
return - V_21 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_177 = F_96 ( L_19 ) ;
if ( ! V_2 -> V_177 ) {
F_6 ( V_4 , L_20 ) ;
V_11 = - V_72 ;
goto V_226;
}
F_97 ( & V_2 -> V_155 , F_66 ) ;
F_83 ( & V_2 -> V_32 ) ;
F_83 ( & V_2 -> V_151 ) ;
F_98 ( & V_2 -> V_33 ) ;
F_98 ( & V_2 -> V_156 ) ;
V_2 -> V_227 = F_99 ( V_4 , L_21 ) ;
if ( F_27 ( V_2 -> V_227 ) ) {
F_6 ( V_4 , L_22 ) ;
V_11 = F_100 ( V_2 -> V_227 ) ;
goto V_228;
}
F_101 ( V_4 ) ;
V_225 = F_102 ( V_223 , V_229 , 0 ) ;
V_2 -> V_147 = F_103 ( V_4 , V_225 ) ;
if ( F_27 ( V_2 -> V_147 ) ) {
V_11 = F_100 ( V_2 -> V_147 ) ;
goto V_230;
}
V_2 -> V_166 = F_104 ( V_223 , 0 ) ;
if ( V_2 -> V_166 < 0 ) {
F_6 ( V_4 , L_23 ) ;
V_11 = V_2 -> V_166 ;
goto V_230;
}
V_11 = F_105 ( V_4 , V_2 -> V_166 , F_73 , 0 ,
L_24 , V_2 ) ;
if ( V_11 < 0 ) {
F_6 ( V_4 , L_25 ) ;
goto V_230;
}
V_2 -> V_85 = V_231 ;
F_106 ( V_223 , V_2 ) ;
V_9 = & V_2 -> V_9 ;
V_9 -> V_4 = V_4 ;
V_9 -> V_232 = F_87 ;
V_9 -> remove = F_89 ;
V_9 -> V_233 = F_91 ;
V_9 -> V_234 = F_92 ;
V_11 = F_107 ( V_9 ) ;
if ( V_11 < 0 ) {
F_6 ( V_4 , L_26 ) ;
goto V_230;
}
F_108 ( V_4 , L_27 ,
V_190 , V_192 ) ;
return 0 ;
V_230:
F_109 ( V_4 ) ;
V_228:
F_110 ( V_2 -> V_177 ) ;
V_226:
F_111 ( V_2 -> V_152 ) ;
return V_11 ;
}
static int F_112 ( struct V_222 * V_223 )
{
struct V_1 * V_2 = F_113 ( V_223 ) ;
F_114 ( & V_2 -> V_155 ) ;
F_115 ( & V_2 -> V_9 ) ;
while ( V_2 -> V_145 ) {
F_62 ( V_2 , V_2 -> V_145 ) ;
V_2 -> V_145 = F_61 ( V_2 ) ;
}
F_109 ( & V_223 -> V_4 ) ;
F_10 ( V_2 ) ;
F_110 ( V_2 -> V_177 ) ;
F_111 ( V_2 -> V_152 ) ;
return 0 ;
}
static int F_116 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_36 ( V_4 ) ;
F_13 ( & V_2 -> V_156 ) ;
V_2 -> V_158 = true ;
F_15 ( & V_2 -> V_156 ) ;
while ( V_2 -> V_145 )
F_117 ( 500 , 1000 ) ;
F_118 ( & V_2 -> V_155 ) ;
return 0 ;
}
static int F_119 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_36 ( V_4 ) ;
V_2 -> V_158 = false ;
F_65 ( V_2 ) ;
return 0 ;
}
static int F_120 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_36 ( V_4 ) ;
F_121 ( V_2 -> V_227 ) ;
return 0 ;
}
static int F_122 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_36 ( V_4 ) ;
int V_11 ;
V_11 = F_123 ( V_2 -> V_227 ) ;
if ( V_11 < 0 )
F_124 ( V_4 , L_28 ) ;
return V_11 ;
}
