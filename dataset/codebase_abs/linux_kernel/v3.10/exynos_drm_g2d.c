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
V_50 -> V_54 = NULL ;
F_10 ( V_50 -> V_56 ) ;
V_50 -> V_56 = NULL ;
F_10 ( V_50 ) ;
V_50 = NULL ;
}
static T_1 * F_27 ( struct V_46 * V_17 ,
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
F_28 ( L_4 ) ;
return F_29 ( - V_73 ) ;
}
V_2 = F_30 ( V_35 -> V_4 ) ;
F_31 (g2d_userptr, &g2d_priv->userptr_list, list) {
if ( V_50 -> V_60 == V_60 ) {
if ( V_50 -> V_61 == V_61 ) {
F_32 ( & V_50 -> V_52 ) ;
* V_47 = ( unsigned long ) V_50 ;
return & V_50 -> V_27 ;
}
V_50 -> V_59 = true ;
V_50 -> V_53 = false ;
F_16 ( & V_50 -> V_31 ) ;
break;
}
}
V_50 = F_33 ( sizeof( * V_50 ) , V_20 ) ;
if ( ! V_50 ) {
F_28 ( L_5 ) ;
return F_29 ( - V_21 ) ;
}
F_34 ( & V_50 -> V_52 , 1 ) ;
V_70 = V_60 & V_74 ;
V_72 = V_60 & ~ V_74 ;
V_71 = F_35 ( V_60 + V_61 ) ;
V_57 = ( V_71 - V_70 ) >> V_75 ;
V_50 -> V_57 = V_57 ;
V_56 = F_33 ( V_57 * sizeof( struct V_67 * ) , V_20 ) ;
if ( ! V_56 ) {
F_28 ( L_6 ) ;
F_10 ( V_50 ) ;
return F_29 ( - V_21 ) ;
}
V_58 = F_36 ( V_76 -> V_77 , V_60 ) ;
if ( ! V_58 ) {
F_28 ( L_7 ) ;
V_11 = - V_78 ;
goto V_79;
}
if ( V_58 -> V_80 < V_60 + V_61 ) {
F_28 ( L_8 ) ;
V_11 = - V_78 ;
goto V_79;
}
V_50 -> V_58 = F_37 ( V_58 ) ;
if ( ! V_50 -> V_58 ) {
F_28 ( L_9 ) ;
V_11 = - V_21 ;
goto V_79;
}
V_50 -> V_61 = V_61 ;
V_11 = F_38 ( V_70 & V_74 ,
V_57 , V_56 , V_58 ) ;
if ( V_11 < 0 ) {
F_28 ( L_10 ) ;
goto V_81;
}
V_50 -> V_56 = V_56 ;
V_54 = F_33 ( sizeof( * V_54 ) , V_20 ) ;
if ( ! V_54 ) {
F_28 ( L_11 ) ;
V_11 = - V_21 ;
goto V_82;
}
V_11 = F_39 ( V_54 , V_56 , V_57 , V_72 ,
V_61 , V_20 ) ;
if ( V_11 < 0 ) {
F_28 ( L_12 ) ;
goto V_83;
}
V_50 -> V_54 = V_54 ;
V_11 = F_40 ( V_17 , V_50 -> V_54 ,
V_55 ) ;
if ( V_11 < 0 ) {
F_28 ( L_13 ) ;
goto V_84;
}
V_50 -> V_27 = V_54 -> V_85 [ 0 ] . V_86 ;
V_50 -> V_60 = V_60 ;
F_7 ( & V_50 -> V_31 , & V_35 -> V_87 ) ;
if ( V_2 -> V_88 + ( V_57 << V_75 ) < V_2 -> V_89 ) {
V_2 -> V_88 += V_57 << V_75 ;
V_50 -> V_53 = true ;
}
* V_47 = ( unsigned long ) V_50 ;
return & V_50 -> V_27 ;
V_84:
F_26 ( V_54 ) ;
V_83:
F_10 ( V_54 ) ;
V_54 = NULL ;
V_82:
F_25 ( V_50 -> V_56 ,
V_50 -> V_57 ,
V_50 -> V_58 ) ;
V_81:
F_41 ( V_50 -> V_58 ) ;
V_79:
F_10 ( V_56 ) ;
F_10 ( V_50 ) ;
V_56 = NULL ;
V_50 = NULL ;
return F_29 ( V_11 ) ;
}
static void F_42 ( struct V_46 * V_17 ,
struct V_1 * V_2 ,
struct V_62 * V_63 )
{
struct V_64 * V_65 = V_63 -> V_66 ;
struct V_34 * V_35 = V_65 -> V_35 ;
struct V_49 * V_50 , * V_90 ;
F_43 (g2d_userptr, n, &g2d_priv->userptr_list, list)
if ( V_50 -> V_53 )
F_21 ( V_17 ,
( unsigned long ) V_50 ,
true ) ;
V_2 -> V_88 = 0 ;
}
static enum V_91 F_44 ( int V_92 )
{
enum V_91 V_93 ;
switch ( V_92 ) {
case V_94 :
case V_95 :
case V_96 :
case V_97 :
V_93 = V_98 ;
break;
case V_99 :
V_93 = V_100 ;
break;
case V_101 :
case V_102 :
case V_103 :
case V_104 :
V_93 = V_105 ;
break;
case V_106 :
V_93 = V_107 ;
break;
case V_108 :
V_93 = V_109 ;
break;
case V_110 :
V_93 = V_111 ;
break;
default:
V_93 = V_30 ;
F_28 ( L_14 , V_92 ) ;
break;
} ;
return V_93 ;
}
static unsigned long F_45 ( unsigned int V_112 )
{
unsigned long V_113 ;
switch ( V_112 ) {
case V_114 :
case V_115 :
V_113 = 4 ;
break;
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
V_113 = 2 ;
break;
case V_121 :
V_113 = 3 ;
break;
default:
V_113 = 1 ;
break;
}
return V_113 ;
}
static bool F_46 ( struct V_122 * V_123 ,
enum V_91 V_93 ,
unsigned long V_61 )
{
unsigned int V_124 , V_125 ;
unsigned long V_126 ;
if ( V_93 != V_98 && V_93 != V_105 )
return true ;
V_124 = V_123 -> V_127 - V_123 -> V_128 ;
if ( V_124 < V_129 || V_124 > V_130 ) {
F_28 ( L_15 , V_124 ) ;
return false ;
}
V_125 = V_123 -> V_131 - V_123 -> V_132 ;
if ( V_125 < V_129 || V_125 > V_130 ) {
F_28 ( L_16 , V_125 ) ;
return false ;
}
V_126 = ( unsigned long ) V_124 * ( unsigned long ) V_125 *
F_45 ( V_123 -> V_112 ) ;
if ( V_126 > V_61 ) {
F_28 ( L_17 , V_126 , V_61 ) ;
return false ;
}
return true ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_46 * V_17 ,
struct V_62 * V_133 )
{
struct V_134 * V_25 = V_6 -> V_25 ;
struct V_12 * V_13 = & V_6 -> V_13 ;
int V_72 ;
int V_11 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_13 -> V_135 ; V_24 ++ ) {
struct V_122 * V_123 ;
enum V_91 V_93 ;
int V_136 ;
unsigned long V_137 ;
T_1 * V_138 ;
V_136 = V_25 -> V_41 - 2 * ( V_24 + 1 ) ;
V_72 = V_25 -> V_40 [ V_136 ] ;
V_137 = V_25 -> V_40 [ V_136 + 1 ] ;
V_93 = F_44 ( V_72 ) ;
if ( V_93 == V_30 ) {
V_11 = - V_78 ;
goto V_23;
}
V_123 = & V_13 -> V_139 [ V_93 ] ;
if ( V_13 -> V_140 [ V_93 ] == V_141 ) {
unsigned long V_61 ;
V_61 = F_48 ( V_17 , V_137 , V_133 ) ;
if ( ! V_61 ) {
V_11 = - V_78 ;
goto V_23;
}
if ( ! F_46 ( V_123 , V_93 ,
V_61 ) ) {
V_11 = - V_78 ;
goto V_23;
}
V_138 = F_49 ( V_17 , V_137 ,
V_133 ) ;
if ( F_50 ( V_138 ) ) {
V_11 = - V_78 ;
goto V_23;
}
} else {
struct V_142 V_50 ;
if ( F_51 ( & V_50 , ( void V_143 * ) V_137 ,
sizeof( struct V_142 ) ) ) {
V_11 = - V_78 ;
goto V_23;
}
if ( ! F_46 ( V_123 , V_93 ,
V_50 . V_61 ) ) {
V_11 = - V_78 ;
goto V_23;
}
V_138 = F_27 ( V_17 ,
V_50 . V_60 ,
V_50 . V_61 ,
V_133 ,
& V_137 ) ;
if ( F_50 ( V_138 ) ) {
V_11 = - V_78 ;
goto V_23;
}
}
V_25 -> V_40 [ V_136 + 1 ] = * V_138 ;
V_13 -> V_29 [ V_24 ] = V_93 ;
V_13 -> V_144 [ V_93 ] = V_137 ;
}
return 0 ;
V_23:
V_13 -> V_135 = V_24 ;
return V_11 ;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_62 * V_63 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_12 * V_13 = & V_6 -> V_13 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_13 -> V_135 ; V_24 ++ ) {
struct V_122 * V_123 ;
enum V_91 V_93 ;
unsigned long V_137 ;
V_93 = V_13 -> V_29 [ V_24 ] ;
V_123 = & V_13 -> V_139 [ V_93 ] ;
V_137 = V_13 -> V_144 [ V_93 ] ;
if ( V_13 -> V_140 [ V_93 ] == V_141 )
F_53 ( V_9 -> V_17 , V_137 ,
V_63 ) ;
else
F_21 ( V_9 -> V_17 , V_137 ,
false ) ;
V_13 -> V_29 [ V_24 ] = V_30 ;
V_13 -> V_144 [ V_93 ] = 0 ;
V_13 -> V_140 [ V_93 ] = 0 ;
memset ( V_123 , 0x00 , sizeof( * V_123 ) ) ;
}
V_13 -> V_135 = 0 ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_145 * V_146 )
{
struct V_5 * V_6 =
F_15 ( & V_146 -> V_147 ,
struct V_5 , V_31 ) ;
F_55 ( V_2 -> V_4 ) ;
F_56 ( V_2 -> V_148 ) ;
F_57 ( V_6 -> V_27 , V_2 -> V_149 + V_150 ) ;
F_57 ( V_151 , V_2 -> V_149 + V_152 ) ;
}
static struct V_145 * F_58 ( struct V_1 * V_2 )
{
struct V_145 * V_146 ;
if ( F_13 ( & V_2 -> V_153 ) )
return NULL ;
V_146 = F_15 ( & V_2 -> V_153 ,
struct V_145 , V_31 ) ;
F_16 ( & V_146 -> V_31 ) ;
return V_146 ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_145 * V_146 )
{
struct V_5 * V_6 ;
if ( ! V_146 )
return;
F_12 ( & V_2 -> V_33 ) ;
F_31 (node, &runqueue_node->run_cmdlist, list)
F_52 ( V_2 , V_6 , V_146 -> V_63 ) ;
F_60 ( & V_146 -> V_147 , & V_2 -> V_32 ) ;
F_14 ( & V_2 -> V_33 ) ;
F_61 ( V_2 -> V_154 , V_146 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
V_2 -> V_146 = F_58 ( V_2 ) ;
if ( V_2 -> V_146 )
F_54 ( V_2 , V_2 -> V_146 ) ;
}
static void F_63 ( struct V_155 * V_156 )
{
struct V_1 * V_2 = F_64 ( V_156 , struct V_1 ,
V_157 ) ;
F_12 ( & V_2 -> V_158 ) ;
F_65 ( V_2 -> V_148 ) ;
F_66 ( V_2 -> V_4 ) ;
F_67 ( & V_2 -> V_146 -> F_67 ) ;
if ( V_2 -> V_146 -> V_159 )
F_59 ( V_2 , V_2 -> V_146 ) ;
if ( V_2 -> V_160 )
V_2 -> V_146 = NULL ;
else
F_62 ( V_2 ) ;
F_14 ( & V_2 -> V_158 ) ;
}
static void F_68 ( struct V_1 * V_2 , T_2 V_161 )
{
struct V_46 * V_17 = V_2 -> V_9 . V_17 ;
struct V_145 * V_146 = V_2 -> V_146 ;
struct V_162 * V_163 ;
struct V_164 V_165 ;
unsigned long V_166 ;
if ( F_13 ( & V_146 -> V_45 ) )
return;
V_163 = F_15 ( & V_146 -> V_45 ,
struct V_162 , V_43 . V_44 ) ;
F_69 ( & V_165 ) ;
V_163 -> V_42 . V_167 = V_165 . V_167 ;
V_163 -> V_42 . V_168 = V_165 . V_168 ;
V_163 -> V_42 . V_161 = V_161 ;
F_70 ( & V_17 -> V_169 , V_166 ) ;
F_18 ( & V_163 -> V_43 . V_44 , & V_163 -> V_43 . V_65 -> V_45 ) ;
F_71 ( & V_163 -> V_43 . V_65 -> V_170 ) ;
F_72 ( & V_17 -> V_169 , V_166 ) ;
}
static T_3 F_73 ( int V_171 , void * V_172 )
{
struct V_1 * V_2 = V_172 ;
T_2 V_173 ;
V_173 = F_74 ( V_2 -> V_149 + V_174 ) ;
if ( V_173 )
F_57 ( V_173 , V_2 -> V_149 + V_174 ) ;
if ( V_173 & V_175 ) {
T_2 V_161 = F_74 ( V_2 -> V_149 + V_176 ) ;
V_161 = ( V_161 & V_177 ) >>
V_178 ;
F_68 ( V_2 , V_161 ) ;
F_57 ( 0 , V_2 -> V_149 + V_179 ) ;
if ( ! ( V_173 & V_180 ) ) {
F_57 ( V_181 ,
V_2 -> V_149 + V_152 ) ;
}
}
if ( V_173 & V_180 )
F_75 ( V_2 -> V_182 , & V_2 -> V_157 ) ;
return V_183 ;
}
static int F_76 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
int V_10 , bool V_184 )
{
struct V_134 * V_25 = V_6 -> V_25 ;
int V_92 ;
int V_185 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_10 ; V_24 ++ ) {
struct V_12 * V_13 = & V_6 -> V_13 ;
struct V_122 * V_123 ;
enum V_91 V_93 ;
unsigned long V_186 ;
V_185 = V_25 -> V_41 - 2 * ( V_24 + 1 ) ;
V_92 = V_25 -> V_40 [ V_185 ] & ~ 0xfffff000 ;
if ( V_92 < V_187 || V_92 > V_188 )
goto V_23;
if ( V_92 % 4 )
goto V_23;
switch ( V_92 ) {
case V_94 :
case V_99 :
case V_101 :
case V_106 :
case V_108 :
case V_110 :
if ( ! V_184 )
goto V_23;
V_93 = F_44 ( V_92 ) ;
if ( V_93 == V_30 )
goto V_23;
if ( ( V_25 -> V_40 [ V_185 ] & ~ 0x7fffffff ) >> 31 ) {
V_13 -> V_140 [ V_93 ] = V_189 ;
V_25 -> V_40 [ V_185 ] &= ~ V_190 ;
} else
V_13 -> V_140 [ V_93 ] = V_141 ;
break;
case V_95 :
case V_102 :
if ( V_184 )
goto V_23;
V_93 = F_44 ( V_92 ) ;
if ( V_93 == V_30 )
goto V_23;
V_123 = & V_13 -> V_139 [ V_93 ] ;
V_186 = V_25 -> V_40 [ V_185 + 1 ] ;
V_123 -> V_112 = V_186 & 0xf ;
break;
case V_96 :
case V_103 :
if ( V_184 )
goto V_23;
V_93 = F_44 ( V_92 ) ;
if ( V_93 == V_30 )
goto V_23;
V_123 = & V_13 -> V_139 [ V_93 ] ;
V_186 = V_25 -> V_40 [ V_185 + 1 ] ;
V_123 -> V_128 = V_186 & 0x1fff ;
V_123 -> V_132 = ( V_186 & 0x1fff0000 ) >> 16 ;
break;
case V_97 :
case V_104 :
if ( V_184 )
goto V_23;
V_93 = F_44 ( V_92 ) ;
if ( V_93 == V_30 )
goto V_23;
V_123 = & V_13 -> V_139 [ V_93 ] ;
V_186 = V_25 -> V_40 [ V_185 + 1 ] ;
V_123 -> V_127 = V_186 & 0x1fff ;
V_123 -> V_131 = ( V_186 & 0x1fff0000 ) >> 16 ;
break;
default:
if ( V_184 )
goto V_23;
break;
}
}
return 0 ;
V_23:
F_5 ( V_4 , L_18 , V_25 -> V_40 [ V_185 ] ) ;
return - V_73 ;
}
int F_77 ( struct V_46 * V_17 , void * V_40 ,
struct V_62 * V_133 )
{
struct V_191 * V_192 = V_40 ;
V_192 -> V_193 = V_194 ;
V_192 -> V_195 = V_196 ;
return 0 ;
}
int F_78 ( struct V_46 * V_17 , void * V_40 ,
struct V_62 * V_133 )
{
struct V_64 * V_65 = V_133 -> V_66 ;
struct V_34 * V_35 = V_65 -> V_35 ;
struct V_3 * V_4 = V_35 -> V_4 ;
struct V_1 * V_2 ;
struct V_197 * V_198 = V_40 ;
struct V_199 * V_200 ;
struct V_162 * V_163 ;
struct V_5 * V_6 ;
struct V_134 * V_25 ;
unsigned long V_166 ;
int V_61 ;
int V_11 ;
if ( ! V_4 )
return - V_201 ;
V_2 = F_30 ( V_4 ) ;
if ( ! V_2 )
return - V_78 ;
V_6 = F_11 ( V_2 ) ;
if ( ! V_6 )
return - V_21 ;
V_6 -> V_42 = NULL ;
if ( V_198 -> V_202 != V_203 ) {
F_70 ( & V_17 -> V_169 , V_166 ) ;
if ( V_133 -> V_204 < sizeof( V_163 -> V_42 ) ) {
F_72 ( & V_17 -> V_169 , V_166 ) ;
V_11 = - V_21 ;
goto V_23;
}
V_133 -> V_204 -= sizeof( V_163 -> V_42 ) ;
F_72 ( & V_17 -> V_169 , V_166 ) ;
V_163 = F_33 ( sizeof( * V_6 -> V_42 ) , V_20 ) ;
if ( ! V_163 ) {
F_5 ( V_4 , L_19 ) ;
F_70 ( & V_17 -> V_169 , V_166 ) ;
V_133 -> V_204 += sizeof( V_163 -> V_42 ) ;
F_72 ( & V_17 -> V_169 , V_166 ) ;
V_11 = - V_21 ;
goto V_23;
}
V_163 -> V_42 . V_43 . type = V_205 ;
V_163 -> V_42 . V_43 . V_206 = sizeof( V_163 -> V_42 ) ;
V_163 -> V_42 . V_207 = V_198 -> V_207 ;
V_163 -> V_43 . V_42 = & V_163 -> V_42 . V_43 ;
V_163 -> V_43 . V_65 = V_133 ;
V_163 -> V_43 . V_208 = ( void ( * ) ( struct V_209 * ) ) F_10 ;
V_6 -> V_42 = V_163 ;
}
V_25 = V_6 -> V_25 ;
V_25 -> V_41 = 0 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_210 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_211 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_94 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = 0 ;
if ( V_6 -> V_42 ) {
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_212 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_213 | V_214 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_179 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_215 ;
} else {
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_212 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_213 ;
}
V_61 = V_25 -> V_41 + V_198 -> V_216 * 2 + V_198 -> V_217 * 2 + 2 ;
if ( V_61 > V_218 ) {
F_5 ( V_4 , L_20 ) ;
V_11 = - V_73 ;
goto V_219;
}
V_200 = (struct V_199 * ) ( V_220 ) V_198 -> V_200 ;
if ( F_51 ( V_25 -> V_40 + V_25 -> V_41 ,
( void V_143 * ) V_200 ,
sizeof( * V_200 ) * V_198 -> V_216 ) ) {
V_11 = - V_78 ;
goto V_219;
}
V_25 -> V_41 += V_198 -> V_216 * 2 ;
V_11 = F_76 ( V_4 , V_6 , V_198 -> V_216 , false ) ;
if ( V_11 < 0 )
goto V_219;
V_6 -> V_13 . V_135 = V_198 -> V_217 ;
if ( V_198 -> V_217 ) {
struct V_199 * V_221 ;
V_221 = (struct V_199 * ) ( V_220 ) V_198 -> V_221 ;
if ( F_51 ( V_25 -> V_40 + V_25 -> V_41 ,
( void V_143 * ) V_221 ,
sizeof( * V_221 ) * V_198 -> V_217 ) ) {
V_11 = - V_78 ;
goto V_219;
}
V_25 -> V_41 += V_198 -> V_217 * 2 ;
V_11 = F_76 ( V_4 , V_6 , V_198 -> V_217 , true ) ;
if ( V_11 < 0 )
goto V_219;
V_11 = F_47 ( V_2 , V_6 , V_17 , V_133 ) ;
if ( V_11 < 0 )
goto V_222;
}
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_223 ;
V_25 -> V_40 [ V_25 -> V_41 ++ ] = V_224 ;
V_25 -> V_225 = V_25 -> V_41 / 2 ;
V_25 -> V_40 [ V_25 -> V_41 ] = 0 ;
F_19 ( V_35 , V_6 ) ;
return 0 ;
V_222:
F_52 ( V_2 , V_6 , V_133 ) ;
V_219:
if ( V_6 -> V_42 ) {
F_70 ( & V_17 -> V_169 , V_166 ) ;
V_133 -> V_204 += sizeof( V_163 -> V_42 ) ;
F_72 ( & V_17 -> V_169 , V_166 ) ;
F_10 ( V_6 -> V_42 ) ;
}
V_23:
F_17 ( V_2 , V_6 ) ;
return V_11 ;
}
int F_79 ( struct V_46 * V_17 , void * V_40 ,
struct V_62 * V_133 )
{
struct V_64 * V_65 = V_133 -> V_66 ;
struct V_34 * V_35 = V_65 -> V_35 ;
struct V_3 * V_4 = V_35 -> V_4 ;
struct V_1 * V_2 ;
struct V_226 * V_198 = V_40 ;
struct V_145 * V_146 ;
struct V_227 * V_147 ;
struct V_227 * V_45 ;
if ( ! V_4 )
return - V_201 ;
V_2 = F_30 ( V_4 ) ;
if ( ! V_2 )
return - V_78 ;
V_146 = F_80 ( V_2 -> V_154 , V_20 ) ;
if ( ! V_146 ) {
F_5 ( V_4 , L_2 ) ;
return - V_21 ;
}
V_147 = & V_146 -> V_147 ;
V_45 = & V_146 -> V_45 ;
F_81 ( V_147 ) ;
F_81 ( V_45 ) ;
F_82 ( & V_146 -> F_67 ) ;
V_146 -> V_159 = V_198 -> V_159 ;
F_83 ( & V_35 -> V_37 , V_147 ) ;
F_83 ( & V_35 -> V_45 , V_45 ) ;
if ( F_13 ( V_147 ) ) {
F_5 ( V_4 , L_21 ) ;
F_61 ( V_2 -> V_154 , V_146 ) ;
return - V_228 ;
}
F_12 ( & V_2 -> V_158 ) ;
V_146 -> V_229 = V_76 -> V_229 ;
V_146 -> V_63 = V_133 ;
F_7 ( & V_146 -> V_31 , & V_2 -> V_153 ) ;
if ( ! V_2 -> V_146 )
F_62 ( V_2 ) ;
F_14 ( & V_2 -> V_158 ) ;
if ( V_146 -> V_159 )
goto V_51;
F_84 ( & V_146 -> F_67 ) ;
F_59 ( V_2 , V_146 ) ;
V_51:
return 0 ;
}
static int F_85 ( struct V_46 * V_17 , struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_11 ;
V_2 = F_30 ( V_4 ) ;
if ( ! V_2 )
return - V_78 ;
V_11 = F_1 ( V_2 ) ;
if ( V_11 < 0 ) {
F_5 ( V_4 , L_22 ) ;
return V_11 ;
}
if ( ! F_86 ( V_17 ) )
return 0 ;
V_11 = F_87 ( V_17 , V_4 ) ;
if ( V_11 < 0 ) {
F_5 ( V_4 , L_23 ) ;
F_9 ( V_2 ) ;
}
return V_11 ;
}
static void F_88 ( struct V_46 * V_17 , struct V_3 * V_4 )
{
if ( ! F_86 ( V_17 ) )
return;
F_89 ( V_17 , V_4 ) ;
}
static int F_90 ( struct V_46 * V_17 , struct V_3 * V_4 ,
struct V_62 * V_133 )
{
struct V_64 * V_65 = V_133 -> V_66 ;
struct V_34 * V_35 ;
V_35 = F_33 ( sizeof( * V_35 ) , V_20 ) ;
if ( ! V_35 ) {
F_5 ( V_4 , L_24 ) ;
return - V_21 ;
}
V_35 -> V_4 = V_4 ;
V_65 -> V_35 = V_35 ;
F_81 ( & V_35 -> V_37 ) ;
F_81 ( & V_35 -> V_45 ) ;
F_81 ( & V_35 -> V_87 ) ;
return 0 ;
}
static void F_91 ( struct V_46 * V_17 , struct V_3 * V_4 ,
struct V_62 * V_133 )
{
struct V_64 * V_65 = V_133 -> V_66 ;
struct V_34 * V_35 = V_65 -> V_35 ;
struct V_1 * V_2 ;
struct V_5 * V_6 , * V_90 ;
if ( ! V_4 )
return;
V_2 = F_30 ( V_4 ) ;
if ( ! V_2 )
return;
F_12 ( & V_2 -> V_33 ) ;
F_43 (node, n, &g2d_priv->inuse_cmdlist, list) {
F_52 ( V_2 , V_6 , V_133 ) ;
F_18 ( & V_6 -> V_31 , & V_2 -> V_32 ) ;
}
F_14 ( & V_2 -> V_33 ) ;
F_42 ( V_17 , V_2 , V_133 ) ;
F_10 ( V_65 -> V_35 ) ;
}
static int F_92 ( struct V_230 * V_231 )
{
struct V_3 * V_4 = & V_231 -> V_4 ;
struct V_232 * V_233 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_11 ;
V_2 = F_93 ( V_4 , sizeof( * V_2 ) , V_20 ) ;
if ( ! V_2 ) {
F_5 ( V_4 , L_25 ) ;
return - V_21 ;
}
V_2 -> V_154 = F_94 ( L_26 ,
sizeof( struct V_145 ) , 0 , 0 , NULL ) ;
if ( ! V_2 -> V_154 )
return - V_21 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_182 = F_95 ( L_27 ) ;
if ( ! V_2 -> V_182 ) {
F_5 ( V_4 , L_28 ) ;
V_11 = - V_73 ;
goto V_234;
}
F_96 ( & V_2 -> V_157 , F_63 ) ;
F_81 ( & V_2 -> V_32 ) ;
F_81 ( & V_2 -> V_153 ) ;
F_97 ( & V_2 -> V_33 ) ;
F_97 ( & V_2 -> V_158 ) ;
V_2 -> V_148 = F_98 ( V_4 , L_29 ) ;
if ( F_50 ( V_2 -> V_148 ) ) {
F_5 ( V_4 , L_30 ) ;
V_11 = F_99 ( V_2 -> V_148 ) ;
goto V_235;
}
F_100 ( V_4 ) ;
V_233 = F_101 ( V_231 , V_236 , 0 ) ;
V_2 -> V_149 = F_102 ( V_4 , V_233 ) ;
if ( F_50 ( V_2 -> V_149 ) ) {
V_11 = F_99 ( V_2 -> V_149 ) ;
goto V_237;
}
V_2 -> V_171 = F_103 ( V_231 , 0 ) ;
if ( V_2 -> V_171 < 0 ) {
F_5 ( V_4 , L_31 ) ;
V_11 = V_2 -> V_171 ;
goto V_237;
}
V_11 = F_104 ( V_4 , V_2 -> V_171 , F_73 , 0 ,
L_32 , V_2 ) ;
if ( V_11 < 0 ) {
F_5 ( V_4 , L_33 ) ;
goto V_237;
}
V_2 -> V_89 = V_238 ;
F_105 ( V_231 , V_2 ) ;
V_9 = & V_2 -> V_9 ;
V_9 -> V_4 = V_4 ;
V_9 -> V_239 = F_85 ;
V_9 -> remove = F_88 ;
V_9 -> V_240 = F_90 ;
V_9 -> V_241 = F_91 ;
V_11 = F_106 ( V_9 ) ;
if ( V_11 < 0 ) {
F_5 ( V_4 , L_34 ) ;
goto V_237;
}
F_107 ( V_4 , L_35 ,
V_194 , V_196 ) ;
return 0 ;
V_237:
F_108 ( V_4 ) ;
V_235:
F_109 ( V_2 -> V_182 ) ;
V_234:
F_110 ( V_2 -> V_154 ) ;
return V_11 ;
}
static int F_111 ( struct V_230 * V_231 )
{
struct V_1 * V_2 = F_112 ( V_231 ) ;
F_113 ( & V_2 -> V_157 ) ;
F_114 ( & V_2 -> V_9 ) ;
while ( V_2 -> V_146 ) {
F_59 ( V_2 , V_2 -> V_146 ) ;
V_2 -> V_146 = F_58 ( V_2 ) ;
}
F_108 ( & V_231 -> V_4 ) ;
F_9 ( V_2 ) ;
F_109 ( V_2 -> V_182 ) ;
F_110 ( V_2 -> V_154 ) ;
return 0 ;
}
static int F_115 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_30 ( V_4 ) ;
F_12 ( & V_2 -> V_158 ) ;
V_2 -> V_160 = true ;
F_14 ( & V_2 -> V_158 ) ;
while ( V_2 -> V_146 )
F_116 ( 500 , 1000 ) ;
F_117 ( & V_2 -> V_157 ) ;
return 0 ;
}
static int F_118 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_30 ( V_4 ) ;
V_2 -> V_160 = false ;
F_62 ( V_2 ) ;
return 0 ;
}
