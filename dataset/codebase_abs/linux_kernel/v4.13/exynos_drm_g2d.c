static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 | V_4 , V_2 -> V_5 + V_6 ) ;
F_3 ( V_7 , & V_2 -> V_8 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_14 * V_15 = & V_2 -> V_15 ;
int V_16 ;
int V_17 ;
struct V_18 * V_19 ;
V_2 -> V_20 = V_21 ;
V_2 -> V_22 = F_5 ( F_6 ( V_15 -> V_23 ) ,
V_24 ,
& V_2 -> V_25 , V_26 ,
V_2 -> V_20 ) ;
if ( ! V_2 -> V_22 ) {
F_7 ( V_10 , L_1 ) ;
return - V_27 ;
}
V_12 = F_8 ( V_28 , sizeof( * V_12 ) , V_26 ) ;
if ( ! V_12 ) {
F_7 ( V_10 , L_2 ) ;
V_17 = - V_27 ;
goto V_29;
}
for ( V_16 = 0 ; V_16 < V_28 ; V_16 ++ ) {
unsigned int V_30 ;
V_12 [ V_16 ] . V_31 =
V_2 -> V_22 + V_16 * V_32 ;
V_12 [ V_16 ] . V_33 =
V_2 -> V_25 + V_16 * V_32 ;
V_19 = & V_12 [ V_16 ] . V_19 ;
for ( V_30 = 0 ; V_30 < V_34 ; V_30 ++ )
V_19 -> V_35 [ V_30 ] = V_36 ;
F_9 ( & V_12 [ V_16 ] . V_37 , & V_2 -> V_38 ) ;
}
return 0 ;
V_29:
F_10 ( F_6 ( V_15 -> V_23 ) , V_24 ,
V_2 -> V_22 ,
V_2 -> V_25 , V_2 -> V_20 ) ;
return V_17 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_15 ;
F_12 ( V_2 -> V_13 ) ;
if ( V_2 -> V_22 && V_2 -> V_25 ) {
F_10 ( F_6 ( V_15 -> V_23 ) ,
V_24 ,
V_2 -> V_22 ,
V_2 -> V_25 , V_2 -> V_20 ) ;
}
}
static struct V_11 * F_13 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_11 * V_12 ;
F_14 ( & V_2 -> V_39 ) ;
if ( F_15 ( & V_2 -> V_38 ) ) {
F_7 ( V_10 , L_3 ) ;
F_16 ( & V_2 -> V_39 ) ;
return NULL ;
}
V_12 = F_17 ( & V_2 -> V_38 , struct V_11 ,
V_37 ) ;
F_18 ( & V_12 -> V_37 ) ;
F_16 ( & V_2 -> V_39 ) ;
return V_12 ;
}
static void F_19 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
F_14 ( & V_2 -> V_39 ) ;
F_20 ( & V_12 -> V_37 , & V_2 -> V_38 ) ;
F_16 ( & V_2 -> V_39 ) ;
}
static void F_21 ( struct V_40 * V_41 ,
struct V_11 * V_12 )
{
struct V_11 * V_42 ;
if ( F_15 ( & V_41 -> V_43 ) )
goto V_44;
V_42 = F_22 ( V_41 -> V_43 . V_45 ,
struct V_11 , V_37 ) ;
V_42 -> V_31 -> V_46 [ V_42 -> V_31 -> V_47 ] = V_12 -> V_33 ;
V_44:
F_9 ( & V_12 -> V_37 , & V_41 -> V_43 ) ;
if ( V_12 -> V_48 )
F_9 ( & V_12 -> V_48 -> V_49 . V_50 , & V_41 -> V_51 ) ;
}
static void F_23 ( struct V_52 * V_23 ,
unsigned long V_53 ,
bool V_54 )
{
struct V_55 * V_56 =
(struct V_55 * ) V_53 ;
struct V_57 * * V_58 ;
if ( ! V_53 )
return;
if ( V_54 )
goto V_59;
F_24 ( & V_56 -> V_60 ) ;
if ( F_25 ( & V_56 -> V_60 ) > 0 )
return;
if ( V_56 -> V_61 )
return;
V_59:
F_26 ( F_6 ( V_23 ) , V_56 -> V_62 -> V_63 ,
V_56 -> V_62 -> V_64 , V_65 ) ;
V_58 = F_27 ( V_56 -> V_66 ) ;
if ( ! F_28 ( V_58 ) ) {
int V_30 ;
for ( V_30 = 0 ; V_30 < F_29 ( V_56 -> V_66 ) ; V_30 ++ )
F_30 ( V_58 [ V_30 ] ) ;
}
F_31 ( V_56 -> V_66 ) ;
F_32 ( V_56 -> V_66 ) ;
if ( ! V_56 -> V_67 )
F_18 ( & V_56 -> V_37 ) ;
F_33 ( V_56 -> V_62 ) ;
F_12 ( V_56 -> V_62 ) ;
F_12 ( V_56 ) ;
}
static T_1 * F_34 ( struct V_52 * V_23 ,
unsigned long V_68 ,
unsigned long V_69 ,
struct V_70 * V_71 ,
unsigned long * V_53 )
{
struct V_72 * V_73 = V_71 -> V_74 ;
struct V_40 * V_41 = V_73 -> V_41 ;
struct V_55 * V_56 ;
struct V_1 * V_2 ;
struct V_75 * V_62 ;
unsigned long V_76 , V_77 ;
unsigned int V_78 , V_79 ;
int V_17 ;
if ( ! V_69 ) {
F_35 ( L_4 ) ;
return F_36 ( - V_80 ) ;
}
V_2 = F_37 ( V_41 -> V_10 ) ;
F_38 (g2d_userptr, &g2d_priv->userptr_list, list) {
if ( V_56 -> V_68 == V_68 ) {
if ( V_56 -> V_69 == V_69 ) {
F_39 ( & V_56 -> V_60 ) ;
* V_53 = ( unsigned long ) V_56 ;
return & V_56 -> V_33 ;
}
V_56 -> V_67 = true ;
V_56 -> V_61 = false ;
F_18 ( & V_56 -> V_37 ) ;
break;
}
}
V_56 = F_40 ( sizeof( * V_56 ) , V_26 ) ;
if ( ! V_56 )
return F_36 ( - V_27 ) ;
F_41 ( & V_56 -> V_60 , 1 ) ;
V_56 -> V_69 = V_69 ;
V_76 = V_68 & V_81 ;
V_79 = V_68 & ~ V_81 ;
V_77 = F_42 ( V_68 + V_69 ) ;
V_78 = ( V_77 - V_76 ) >> V_82 ;
V_56 -> V_66 = F_43 ( V_78 ) ;
if ( ! V_56 -> V_66 ) {
V_17 = - V_27 ;
goto V_83;
}
V_17 = F_44 ( V_76 , V_78 , V_84 | V_85 ,
V_56 -> V_66 ) ;
if ( V_17 != V_78 ) {
F_35 ( L_5 ) ;
if ( V_17 < 0 )
goto V_86;
V_17 = - V_87 ;
goto V_88;
}
if ( F_45 ( V_56 -> V_66 ) < 0 ) {
V_17 = - V_87 ;
goto V_88;
}
V_62 = F_40 ( sizeof( * V_62 ) , V_26 ) ;
if ( ! V_62 ) {
V_17 = - V_27 ;
goto V_88;
}
V_17 = F_46 ( V_62 ,
F_27 ( V_56 -> V_66 ) ,
V_78 , V_79 , V_69 , V_26 ) ;
if ( V_17 < 0 ) {
F_35 ( L_6 ) ;
goto V_89;
}
V_56 -> V_62 = V_62 ;
if ( ! F_47 ( F_6 ( V_23 ) , V_62 -> V_63 , V_62 -> V_64 ,
V_65 ) ) {
F_35 ( L_7 ) ;
V_17 = - V_27 ;
goto V_90;
}
V_56 -> V_33 = V_62 -> V_63 [ 0 ] . V_91 ;
V_56 -> V_68 = V_68 ;
F_9 ( & V_56 -> V_37 , & V_41 -> V_92 ) ;
if ( V_2 -> V_93 + ( V_78 << V_82 ) < V_2 -> V_94 ) {
V_2 -> V_93 += V_78 << V_82 ;
V_56 -> V_61 = true ;
}
* V_53 = ( unsigned long ) V_56 ;
return & V_56 -> V_33 ;
V_90:
F_33 ( V_62 ) ;
V_89:
F_12 ( V_62 ) ;
V_88:
F_31 ( V_56 -> V_66 ) ;
V_86:
F_32 ( V_56 -> V_66 ) ;
V_83:
F_12 ( V_56 ) ;
return F_36 ( V_17 ) ;
}
static void F_48 ( struct V_52 * V_23 ,
struct V_1 * V_2 ,
struct V_70 * V_71 )
{
struct V_72 * V_73 = V_71 -> V_74 ;
struct V_40 * V_41 = V_73 -> V_41 ;
struct V_55 * V_56 , * V_95 ;
F_49 (g2d_userptr, n, &g2d_priv->userptr_list, list)
if ( V_56 -> V_61 )
F_23 ( V_23 ,
( unsigned long ) V_56 ,
true ) ;
V_2 -> V_93 = 0 ;
}
static enum V_96 F_50 ( int V_97 )
{
enum V_96 V_98 ;
switch ( V_97 ) {
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_103 :
V_98 = V_104 ;
break;
case V_105 :
V_98 = V_106 ;
break;
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
V_98 = V_112 ;
break;
case V_113 :
V_98 = V_114 ;
break;
case V_115 :
V_98 = V_116 ;
break;
case V_117 :
V_98 = V_118 ;
break;
default:
V_98 = V_36 ;
F_35 ( L_8 , V_97 ) ;
break;
}
return V_98 ;
}
static unsigned long F_51 ( unsigned int V_119 )
{
unsigned long V_120 ;
switch ( V_119 ) {
case V_121 :
case V_122 :
V_120 = 4 ;
break;
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
V_120 = 2 ;
break;
case V_128 :
V_120 = 3 ;
break;
default:
V_120 = 1 ;
break;
}
return V_120 ;
}
static bool F_52 ( struct V_129 * V_130 ,
enum V_96 V_98 ,
unsigned long V_69 )
{
int V_131 , V_132 ;
unsigned long V_120 , V_133 ;
if ( V_98 != V_104 && V_98 != V_112 )
return true ;
V_131 = ( int ) V_130 -> V_134 - ( int ) V_130 -> V_135 ;
if ( V_131 < V_136 || V_131 > V_137 ) {
F_35 ( L_9 , V_131 ) ;
return false ;
}
V_132 = ( int ) V_130 -> V_138 - ( int ) V_130 -> V_139 ;
if ( V_132 < V_136 || V_132 > V_137 ) {
F_35 ( L_10 , V_132 ) ;
return false ;
}
V_120 = F_51 ( V_130 -> V_119 ) ;
V_133 = ( ( unsigned long ) V_130 -> V_138 - 1 ) *
( unsigned long ) V_130 -> V_140 +
( unsigned long ) V_130 -> V_134 * V_120 - 1 ;
if ( V_133 >= V_69 ) {
F_35 ( L_11
L_12 , V_133 , V_69 ) ;
return false ;
}
return true ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_52 * V_23 ,
struct V_70 * V_141 )
{
struct V_142 * V_31 = V_12 -> V_31 ;
struct V_18 * V_19 = & V_12 -> V_19 ;
int V_79 ;
int V_17 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_19 -> V_143 ; V_30 ++ ) {
struct V_129 * V_130 ;
enum V_96 V_98 ;
int V_144 ;
unsigned long V_145 ;
T_1 * V_146 ;
V_144 = V_31 -> V_47 - 2 * ( V_30 + 1 ) ;
V_79 = V_31 -> V_46 [ V_144 ] ;
V_145 = V_31 -> V_46 [ V_144 + 1 ] ;
V_98 = F_50 ( V_79 ) ;
if ( V_98 == V_36 ) {
V_17 = - V_87 ;
goto V_29;
}
V_130 = & V_19 -> V_147 [ V_98 ] ;
if ( V_19 -> V_148 [ V_98 ] == V_149 ) {
unsigned long V_69 ;
V_69 = F_54 ( V_23 , V_145 , V_141 ) ;
if ( ! V_69 ) {
V_17 = - V_87 ;
goto V_29;
}
if ( ! F_52 ( V_130 , V_98 ,
V_69 ) ) {
V_17 = - V_87 ;
goto V_29;
}
V_146 = F_55 ( V_23 , V_145 ,
V_141 ) ;
if ( F_28 ( V_146 ) ) {
V_17 = - V_87 ;
goto V_29;
}
} else {
struct V_150 V_56 ;
if ( F_56 ( & V_56 , ( void V_151 * ) V_145 ,
sizeof( struct V_150 ) ) ) {
V_17 = - V_87 ;
goto V_29;
}
if ( ! F_52 ( V_130 , V_98 ,
V_56 . V_69 ) ) {
V_17 = - V_87 ;
goto V_29;
}
V_146 = F_34 ( V_23 ,
V_56 . V_68 ,
V_56 . V_69 ,
V_141 ,
& V_145 ) ;
if ( F_28 ( V_146 ) ) {
V_17 = - V_87 ;
goto V_29;
}
}
V_31 -> V_46 [ V_144 + 1 ] = * V_146 ;
V_19 -> V_35 [ V_30 ] = V_98 ;
V_19 -> V_152 [ V_98 ] = V_145 ;
}
return 0 ;
V_29:
V_19 -> V_143 = V_30 ;
return V_17 ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_70 * V_71 )
{
struct V_14 * V_15 = & V_2 -> V_15 ;
struct V_18 * V_19 = & V_12 -> V_19 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_19 -> V_143 ; V_30 ++ ) {
struct V_129 * V_130 ;
enum V_96 V_98 ;
unsigned long V_145 ;
V_98 = V_19 -> V_35 [ V_30 ] ;
V_130 = & V_19 -> V_147 [ V_98 ] ;
V_145 = V_19 -> V_152 [ V_98 ] ;
if ( V_19 -> V_148 [ V_98 ] == V_149 )
F_58 ( V_15 -> V_23 , V_145 ,
V_71 ) ;
else
F_23 ( V_15 -> V_23 , V_145 ,
false ) ;
V_19 -> V_35 [ V_30 ] = V_36 ;
V_19 -> V_152 [ V_98 ] = 0 ;
V_19 -> V_148 [ V_98 ] = 0 ;
memset ( V_130 , 0x00 , sizeof( * V_130 ) ) ;
}
V_19 -> V_143 = 0 ;
}
static void F_59 ( struct V_1 * V_2 ,
struct V_153 * V_154 )
{
struct V_11 * V_12 =
F_17 ( & V_154 -> V_155 ,
struct V_11 , V_37 ) ;
F_60 ( V_7 , & V_2 -> V_8 ) ;
F_61 ( V_12 -> V_33 , V_2 -> V_5 + V_156 ) ;
F_61 ( V_157 , V_2 -> V_5 + V_158 ) ;
}
static struct V_153 * F_62 ( struct V_1 * V_2 )
{
struct V_153 * V_154 ;
if ( F_15 ( & V_2 -> V_159 ) )
return NULL ;
V_154 = F_17 ( & V_2 -> V_159 ,
struct V_153 , V_37 ) ;
F_18 ( & V_154 -> V_37 ) ;
return V_154 ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_153 * V_154 )
{
struct V_11 * V_12 ;
F_14 ( & V_2 -> V_39 ) ;
F_38 (node, &runqueue_node->run_cmdlist, list)
F_57 ( V_2 , V_12 , V_154 -> V_71 ) ;
F_64 ( & V_154 -> V_155 , & V_2 -> V_38 ) ;
F_16 ( & V_2 -> V_39 ) ;
F_65 ( V_2 -> V_160 , V_154 ) ;
}
static void F_66 ( struct V_1 * V_2 , struct V_70 * V_141 )
{
struct V_153 * V_12 , * V_95 ;
if ( F_15 ( & V_2 -> V_159 ) )
return;
F_49 (node, n, &g2d->runqueue, list) {
if ( V_141 && V_12 -> V_71 != V_141 )
continue;
F_18 ( & V_12 -> V_37 ) ;
F_63 ( V_2 , V_12 ) ;
}
}
static void F_67 ( struct V_161 * V_162 )
{
struct V_1 * V_2 = F_68 ( V_162 , struct V_1 ,
V_163 ) ;
struct V_153 * V_154 ;
if ( F_69 ( V_7 , & V_2 -> V_8 ) )
return;
F_14 ( & V_2 -> V_164 ) ;
V_154 = V_2 -> V_154 ;
V_2 -> V_154 = NULL ;
if ( V_154 ) {
F_70 ( V_2 -> V_10 ) ;
F_71 ( V_2 -> V_10 ) ;
F_72 ( & V_154 -> F_72 ) ;
if ( V_154 -> V_165 )
F_63 ( V_2 , V_154 ) ;
}
if ( ! F_69 ( V_166 , & V_2 -> V_8 ) ) {
V_2 -> V_154 = F_62 ( V_2 ) ;
if ( V_2 -> V_154 ) {
F_73 ( V_2 -> V_10 ) ;
F_59 ( V_2 , V_2 -> V_154 ) ;
}
}
F_16 ( & V_2 -> V_164 ) ;
}
static void F_74 ( struct V_1 * V_2 , T_2 V_167 )
{
struct V_52 * V_23 = V_2 -> V_15 . V_23 ;
struct V_153 * V_154 = V_2 -> V_154 ;
struct V_168 * V_169 ;
struct V_170 V_171 ;
if ( F_15 ( & V_154 -> V_51 ) )
return;
V_169 = F_17 ( & V_154 -> V_51 ,
struct V_168 , V_49 . V_50 ) ;
F_75 ( & V_171 ) ;
V_169 -> V_48 . V_172 = V_171 . V_172 ;
V_169 -> V_48 . V_173 = V_171 . V_173 ;
V_169 -> V_48 . V_167 = V_167 ;
F_76 ( V_23 , & V_169 -> V_49 ) ;
}
static T_3 F_77 ( int V_174 , void * V_175 )
{
struct V_1 * V_2 = V_175 ;
T_2 V_176 ;
V_176 = F_78 ( V_2 -> V_5 + V_177 ) ;
if ( V_176 )
F_61 ( V_176 , V_2 -> V_5 + V_177 ) ;
if ( V_176 & V_178 ) {
T_2 V_167 = F_78 ( V_2 -> V_5 + V_179 ) ;
V_167 = ( V_167 & V_180 ) >>
V_181 ;
F_74 ( V_2 , V_167 ) ;
F_61 ( 0 , V_2 -> V_5 + V_182 ) ;
if ( ! ( V_176 & V_183 ) ) {
F_61 ( V_184 ,
V_2 -> V_5 + V_158 ) ;
}
}
if ( V_176 & V_183 ) {
F_3 ( V_7 , & V_2 -> V_8 ) ;
F_79 ( V_2 -> V_185 , & V_2 -> V_163 ) ;
}
return V_186 ;
}
static void F_80 ( struct V_1 * V_2 , struct V_70 * V_141 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_153 * V_154 = NULL ;
unsigned int V_187 = 10 ;
F_14 ( & V_2 -> V_164 ) ;
if ( ! V_2 -> V_154 )
goto V_59;
V_154 = V_2 -> V_154 ;
if ( V_141 && V_154 -> V_71 != V_141 )
goto V_59;
F_16 ( & V_2 -> V_164 ) ;
while ( V_187 -- && ( V_2 -> V_154 == V_154 ) )
F_81 ( 10 ) ;
F_14 ( & V_2 -> V_164 ) ;
if ( V_2 -> V_154 != V_154 )
goto V_59;
F_7 ( V_10 , L_13 ) ;
F_1 ( V_2 ) ;
F_70 ( V_10 ) ;
F_71 ( V_10 ) ;
F_72 ( & V_154 -> F_72 ) ;
if ( V_154 -> V_165 )
F_63 ( V_2 , V_154 ) ;
V_59:
F_16 ( & V_2 -> V_164 ) ;
}
static int F_82 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
int V_16 , bool V_188 )
{
struct V_142 * V_31 = V_12 -> V_31 ;
int V_97 ;
int V_189 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_16 ; V_30 ++ ) {
struct V_18 * V_19 = & V_12 -> V_19 ;
struct V_129 * V_130 ;
enum V_96 V_98 ;
unsigned long V_190 ;
V_189 = V_31 -> V_47 - 2 * ( V_30 + 1 ) ;
V_97 = V_31 -> V_46 [ V_189 ] & ~ 0xfffff000 ;
if ( V_97 < V_191 || V_97 > V_192 )
goto V_29;
if ( V_97 % 4 )
goto V_29;
switch ( V_97 ) {
case V_99 :
case V_105 :
case V_107 :
case V_113 :
case V_115 :
case V_117 :
if ( ! V_188 )
goto V_29;
V_98 = F_50 ( V_97 ) ;
if ( ( V_31 -> V_46 [ V_189 ] & ~ 0x7fffffff ) >> 31 ) {
V_19 -> V_148 [ V_98 ] = V_193 ;
V_31 -> V_46 [ V_189 ] &= ~ V_194 ;
} else
V_19 -> V_148 [ V_98 ] = V_149 ;
break;
case V_100 :
case V_108 :
if ( V_188 )
goto V_29;
V_98 = F_50 ( V_97 ) ;
V_130 = & V_19 -> V_147 [ V_98 ] ;
V_130 -> V_140 = V_31 -> V_46 [ V_189 + 1 ] ;
break;
case V_101 :
case V_109 :
if ( V_188 )
goto V_29;
V_98 = F_50 ( V_97 ) ;
V_130 = & V_19 -> V_147 [ V_98 ] ;
V_190 = V_31 -> V_46 [ V_189 + 1 ] ;
V_130 -> V_119 = V_190 & 0xf ;
break;
case V_102 :
case V_110 :
if ( V_188 )
goto V_29;
V_98 = F_50 ( V_97 ) ;
V_130 = & V_19 -> V_147 [ V_98 ] ;
V_190 = V_31 -> V_46 [ V_189 + 1 ] ;
V_130 -> V_135 = V_190 & 0x1fff ;
V_130 -> V_139 = ( V_190 & 0x1fff0000 ) >> 16 ;
break;
case V_103 :
case V_111 :
if ( V_188 )
goto V_29;
V_98 = F_50 ( V_97 ) ;
V_130 = & V_19 -> V_147 [ V_98 ] ;
V_190 = V_31 -> V_46 [ V_189 + 1 ] ;
V_130 -> V_134 = V_190 & 0x1fff ;
V_130 -> V_138 = ( V_190 & 0x1fff0000 ) >> 16 ;
break;
default:
if ( V_188 )
goto V_29;
break;
}
}
return 0 ;
V_29:
F_7 ( V_10 , L_14 , V_31 -> V_46 [ V_189 ] ) ;
return - V_80 ;
}
int F_83 ( struct V_52 * V_23 , void * V_46 ,
struct V_70 * V_141 )
{
struct V_72 * V_73 = V_141 -> V_74 ;
struct V_40 * V_41 = V_73 -> V_41 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_195 * V_196 = V_46 ;
if ( ! V_41 )
return - V_197 ;
V_10 = V_41 -> V_10 ;
if ( ! V_10 )
return - V_197 ;
V_2 = F_37 ( V_10 ) ;
if ( ! V_2 )
return - V_87 ;
V_196 -> V_198 = V_199 ;
V_196 -> V_200 = V_201 ;
return 0 ;
}
int F_84 ( struct V_52 * V_23 , void * V_46 ,
struct V_70 * V_141 )
{
struct V_72 * V_73 = V_141 -> V_74 ;
struct V_40 * V_41 = V_73 -> V_41 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_202 * V_203 = V_46 ;
struct V_204 * V_205 ;
struct V_168 * V_169 ;
struct V_11 * V_12 ;
struct V_142 * V_31 ;
int V_69 ;
int V_17 ;
if ( ! V_41 )
return - V_197 ;
V_10 = V_41 -> V_10 ;
if ( ! V_10 )
return - V_197 ;
V_2 = F_37 ( V_10 ) ;
if ( ! V_2 )
return - V_87 ;
V_12 = F_13 ( V_2 ) ;
if ( ! V_12 )
return - V_27 ;
if ( V_203 -> V_206 > V_207 ||
V_203 -> V_208 > V_207 ) {
F_7 ( V_10 , L_15 ) ;
return - V_80 ;
}
V_12 -> V_48 = NULL ;
if ( V_203 -> V_209 != V_210 ) {
V_169 = F_40 ( sizeof( * V_12 -> V_48 ) , V_26 ) ;
if ( ! V_169 ) {
V_17 = - V_27 ;
goto V_29;
}
V_169 -> V_48 . V_49 . type = V_211 ;
V_169 -> V_48 . V_49 . V_212 = sizeof( V_169 -> V_48 ) ;
V_169 -> V_48 . V_213 = V_203 -> V_213 ;
V_17 = F_85 ( V_23 , V_141 , & V_169 -> V_49 , & V_169 -> V_48 . V_49 ) ;
if ( V_17 ) {
F_12 ( V_169 ) ;
goto V_29;
}
V_12 -> V_48 = V_169 ;
}
V_31 = V_12 -> V_31 ;
V_31 -> V_47 = 0 ;
V_31 -> V_46 [ V_31 -> V_47 ++ ] = V_6 ;
V_31 -> V_46 [ V_31 -> V_47 ++ ] = V_4 ;
V_31 -> V_46 [ V_31 -> V_47 ++ ] = V_99 ;
V_31 -> V_46 [ V_31 -> V_47 ++ ] = 0 ;
if ( V_12 -> V_48 ) {
V_31 -> V_46 [ V_31 -> V_47 ++ ] = V_214 ;
V_31 -> V_46 [ V_31 -> V_47 ++ ] = V_215 | V_216 ;
V_31 -> V_46 [ V_31 -> V_47 ++ ] = V_182 ;
V_31 -> V_46 [ V_31 -> V_47 ++ ] = V_217 ;
} else {
V_31 -> V_46 [ V_31 -> V_47 ++ ] = V_214 ;
V_31 -> V_46 [ V_31 -> V_47 ++ ] = V_215 ;
}
V_69 = V_31 -> V_47 + V_203 -> V_206 * 2 + V_203 -> V_208 * 2 + 2 ;
if ( V_69 > V_207 ) {
F_7 ( V_10 , L_16 ) ;
V_17 = - V_80 ;
goto V_218;
}
V_205 = (struct V_204 * ) ( unsigned long ) V_203 -> V_205 ;
if ( F_56 ( V_31 -> V_46 + V_31 -> V_47 ,
( void V_151 * ) V_205 ,
sizeof( * V_205 ) * V_203 -> V_206 ) ) {
V_17 = - V_87 ;
goto V_218;
}
V_31 -> V_47 += V_203 -> V_206 * 2 ;
V_17 = F_82 ( V_10 , V_12 , V_203 -> V_206 , false ) ;
if ( V_17 < 0 )
goto V_218;
V_12 -> V_19 . V_143 = V_203 -> V_208 ;
if ( V_203 -> V_208 ) {
struct V_204 * V_219 ;
V_219 = (struct V_204 * )
( unsigned long ) V_203 -> V_219 ;
if ( F_56 ( V_31 -> V_46 + V_31 -> V_47 ,
( void V_151 * ) V_219 ,
sizeof( * V_219 ) * V_203 -> V_208 ) ) {
V_17 = - V_87 ;
goto V_218;
}
V_31 -> V_47 += V_203 -> V_208 * 2 ;
V_17 = F_82 ( V_10 , V_12 , V_203 -> V_208 , true ) ;
if ( V_17 < 0 )
goto V_218;
V_17 = F_53 ( V_2 , V_12 , V_23 , V_141 ) ;
if ( V_17 < 0 )
goto V_220;
}
V_31 -> V_46 [ V_31 -> V_47 ++ ] = V_221 ;
V_31 -> V_46 [ V_31 -> V_47 ++ ] = V_222 ;
V_31 -> V_223 = V_31 -> V_47 / 2 ;
V_31 -> V_46 [ V_31 -> V_47 ] = 0 ;
F_21 ( V_41 , V_12 ) ;
return 0 ;
V_220:
F_57 ( V_2 , V_12 , V_141 ) ;
V_218:
if ( V_12 -> V_48 )
F_86 ( V_23 , & V_12 -> V_48 -> V_49 ) ;
V_29:
F_19 ( V_2 , V_12 ) ;
return V_17 ;
}
int F_87 ( struct V_52 * V_23 , void * V_46 ,
struct V_70 * V_141 )
{
struct V_72 * V_73 = V_141 -> V_74 ;
struct V_40 * V_41 = V_73 -> V_41 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_224 * V_203 = V_46 ;
struct V_153 * V_154 ;
struct V_225 * V_155 ;
struct V_225 * V_51 ;
if ( ! V_41 )
return - V_197 ;
V_10 = V_41 -> V_10 ;
if ( ! V_10 )
return - V_197 ;
V_2 = F_37 ( V_10 ) ;
if ( ! V_2 )
return - V_87 ;
V_154 = F_88 ( V_2 -> V_160 , V_26 ) ;
if ( ! V_154 ) {
F_7 ( V_10 , L_2 ) ;
return - V_27 ;
}
V_155 = & V_154 -> V_155 ;
V_51 = & V_154 -> V_51 ;
F_89 ( V_155 ) ;
F_89 ( V_51 ) ;
F_90 ( & V_154 -> F_72 ) ;
V_154 -> V_165 = V_203 -> V_165 ;
F_91 ( & V_41 -> V_43 , V_155 ) ;
F_91 ( & V_41 -> V_51 , V_51 ) ;
if ( F_15 ( V_155 ) ) {
F_7 ( V_10 , L_17 ) ;
F_65 ( V_2 -> V_160 , V_154 ) ;
return - V_226 ;
}
F_14 ( & V_2 -> V_164 ) ;
V_154 -> V_227 = V_228 -> V_227 ;
V_154 -> V_71 = V_141 ;
F_9 ( & V_154 -> V_37 , & V_2 -> V_159 ) ;
F_16 ( & V_2 -> V_164 ) ;
F_79 ( V_2 -> V_185 , & V_2 -> V_163 ) ;
if ( V_154 -> V_165 )
goto V_59;
F_92 ( & V_154 -> F_72 ) ;
F_63 ( V_2 , V_154 ) ;
V_59:
return 0 ;
}
static int F_93 ( struct V_52 * V_23 , struct V_9 * V_10 )
{
struct V_1 * V_2 ;
int V_17 ;
V_2 = F_37 ( V_10 ) ;
if ( ! V_2 )
return - V_87 ;
V_17 = F_4 ( V_2 ) ;
if ( V_17 < 0 ) {
F_7 ( V_10 , L_18 ) ;
return V_17 ;
}
V_17 = F_94 ( V_23 , V_10 ) ;
if ( V_17 < 0 ) {
F_7 ( V_10 , L_19 ) ;
F_11 ( V_2 ) ;
}
return V_17 ;
}
static void F_95 ( struct V_52 * V_23 , struct V_9 * V_10 )
{
F_96 ( V_23 , V_10 ) ;
}
static int F_97 ( struct V_52 * V_23 , struct V_9 * V_10 ,
struct V_70 * V_141 )
{
struct V_72 * V_73 = V_141 -> V_74 ;
struct V_40 * V_41 ;
V_41 = F_40 ( sizeof( * V_41 ) , V_26 ) ;
if ( ! V_41 )
return - V_27 ;
V_41 -> V_10 = V_10 ;
V_73 -> V_41 = V_41 ;
F_89 ( & V_41 -> V_43 ) ;
F_89 ( & V_41 -> V_51 ) ;
F_89 ( & V_41 -> V_92 ) ;
return 0 ;
}
static void F_98 ( struct V_52 * V_23 , struct V_9 * V_10 ,
struct V_70 * V_141 )
{
struct V_72 * V_73 = V_141 -> V_74 ;
struct V_40 * V_41 = V_73 -> V_41 ;
struct V_1 * V_2 ;
struct V_11 * V_12 , * V_95 ;
if ( ! V_10 )
return;
V_2 = F_37 ( V_10 ) ;
if ( ! V_2 )
return;
F_14 ( & V_2 -> V_164 ) ;
F_66 ( V_2 , V_141 ) ;
F_16 ( & V_2 -> V_164 ) ;
F_80 ( V_2 , V_141 ) ;
F_14 ( & V_2 -> V_39 ) ;
F_49 (node, n, &g2d_priv->inuse_cmdlist, list) {
F_57 ( V_2 , V_12 , V_141 ) ;
F_20 ( & V_12 -> V_37 , & V_2 -> V_38 ) ;
}
F_16 ( & V_2 -> V_39 ) ;
F_48 ( V_23 , V_2 , V_141 ) ;
F_12 ( V_73 -> V_41 ) ;
}
static int F_99 ( struct V_229 * V_230 )
{
struct V_9 * V_10 = & V_230 -> V_10 ;
struct V_231 * V_232 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
int V_17 ;
V_2 = F_100 ( V_10 , sizeof( * V_2 ) , V_26 ) ;
if ( ! V_2 )
return - V_27 ;
V_2 -> V_160 = F_101 ( L_20 ,
sizeof( struct V_153 ) , 0 , 0 , NULL ) ;
if ( ! V_2 -> V_160 )
return - V_27 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_185 = F_102 ( L_21 ) ;
if ( ! V_2 -> V_185 ) {
F_7 ( V_10 , L_22 ) ;
V_17 = - V_80 ;
goto V_233;
}
F_103 ( & V_2 -> V_163 , F_67 ) ;
F_89 ( & V_2 -> V_38 ) ;
F_89 ( & V_2 -> V_159 ) ;
F_104 ( & V_2 -> V_39 ) ;
F_104 ( & V_2 -> V_164 ) ;
V_2 -> V_234 = F_105 ( V_10 , L_23 ) ;
if ( F_28 ( V_2 -> V_234 ) ) {
F_7 ( V_10 , L_24 ) ;
V_17 = F_106 ( V_2 -> V_234 ) ;
goto V_235;
}
F_107 ( V_10 ) ;
F_108 ( V_10 , 2000 ) ;
F_109 ( V_10 ) ;
F_3 ( V_166 , & V_2 -> V_8 ) ;
F_3 ( V_7 , & V_2 -> V_8 ) ;
V_232 = F_110 ( V_230 , V_236 , 0 ) ;
V_2 -> V_5 = F_111 ( V_10 , V_232 ) ;
if ( F_28 ( V_2 -> V_5 ) ) {
V_17 = F_106 ( V_2 -> V_5 ) ;
goto V_237;
}
V_2 -> V_174 = F_112 ( V_230 , 0 ) ;
if ( V_2 -> V_174 < 0 ) {
F_7 ( V_10 , L_25 ) ;
V_17 = V_2 -> V_174 ;
goto V_237;
}
V_17 = F_113 ( V_10 , V_2 -> V_174 , F_77 , 0 ,
L_26 , V_2 ) ;
if ( V_17 < 0 ) {
F_7 ( V_10 , L_27 ) ;
goto V_237;
}
V_2 -> V_94 = V_238 ;
F_114 ( V_230 , V_2 ) ;
V_15 = & V_2 -> V_15 ;
V_15 -> V_10 = V_10 ;
V_15 -> V_239 = F_93 ;
V_15 -> remove = F_95 ;
V_15 -> V_240 = F_97 ;
V_15 -> V_241 = F_98 ;
V_17 = F_115 ( V_15 ) ;
if ( V_17 < 0 ) {
F_7 ( V_10 , L_28 ) ;
goto V_237;
}
F_116 ( V_10 , L_29 ,
V_199 , V_201 ) ;
return 0 ;
V_237:
F_117 ( V_10 ) ;
V_235:
F_118 ( V_2 -> V_185 ) ;
V_233:
F_119 ( V_2 -> V_160 ) ;
return V_17 ;
}
static int F_120 ( struct V_229 * V_230 )
{
struct V_1 * V_2 = F_121 ( V_230 ) ;
F_60 ( V_166 , & V_2 -> V_8 ) ;
F_80 ( V_2 , NULL ) ;
F_122 ( & V_2 -> V_163 ) ;
F_123 ( & V_2 -> V_15 ) ;
F_66 ( V_2 , NULL ) ;
F_124 ( & V_230 -> V_10 ) ;
F_117 ( & V_230 -> V_10 ) ;
F_11 ( V_2 ) ;
F_118 ( V_2 -> V_185 ) ;
F_119 ( V_2 -> V_160 ) ;
return 0 ;
}
static int F_125 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_37 ( V_10 ) ;
F_60 ( V_166 , & V_2 -> V_8 ) ;
F_80 ( V_2 , NULL ) ;
F_126 ( & V_2 -> V_163 ) ;
return 0 ;
}
static int F_127 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_37 ( V_10 ) ;
F_3 ( V_166 , & V_2 -> V_8 ) ;
F_79 ( V_2 -> V_185 , & V_2 -> V_163 ) ;
return 0 ;
}
static int F_128 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_37 ( V_10 ) ;
F_129 ( V_2 -> V_234 ) ;
return 0 ;
}
static int F_130 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_37 ( V_10 ) ;
int V_17 ;
V_17 = F_131 ( V_2 -> V_234 ) ;
if ( V_17 < 0 )
F_132 ( V_10 , L_30 ) ;
return V_17 ;
}
