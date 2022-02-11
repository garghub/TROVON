static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_10 ;
int V_11 ;
F_2 ( & V_2 -> V_12 ) ;
F_3 ( V_13 , & V_2 -> V_12 ) ;
V_2 -> V_14 = F_4 ( V_9 -> V_15 -> V_4 ,
V_16 ,
& V_2 -> V_17 , V_18 ,
& V_2 -> V_12 ) ;
if ( ! V_2 -> V_14 ) {
F_5 ( V_4 , L_1 ) ;
return - V_19 ;
}
V_6 = F_6 ( V_20 , sizeof( * V_6 ) , V_18 ) ;
if ( ! V_6 ) {
F_5 ( V_4 , L_2 ) ;
V_11 = - V_19 ;
goto V_21;
}
for ( V_10 = 0 ; V_10 < V_20 ; V_10 ++ ) {
V_6 [ V_10 ] . V_22 =
V_2 -> V_14 + V_10 * V_23 ;
V_6 [ V_10 ] . V_24 =
V_2 -> V_17 + V_10 * V_23 ;
F_7 ( & V_6 [ V_10 ] . V_25 , & V_2 -> V_26 ) ;
}
return 0 ;
V_21:
F_8 ( V_9 -> V_15 -> V_4 , V_16 ,
V_2 -> V_14 ,
V_2 -> V_17 , & V_2 -> V_12 ) ;
return V_11 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
F_10 ( V_2 -> V_7 ) ;
F_8 ( V_9 -> V_15 -> V_4 , V_16 ,
V_2 -> V_14 ,
V_2 -> V_17 , & V_2 -> V_12 ) ;
}
static struct V_5 * F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
F_12 ( & V_2 -> V_27 ) ;
if ( F_13 ( & V_2 -> V_26 ) ) {
F_5 ( V_4 , L_3 ) ;
F_14 ( & V_2 -> V_27 ) ;
return NULL ;
}
V_6 = F_15 ( & V_2 -> V_26 , struct V_5 ,
V_25 ) ;
F_16 ( & V_6 -> V_25 ) ;
F_14 ( & V_2 -> V_27 ) ;
return V_6 ;
}
static void F_17 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
F_12 ( & V_2 -> V_27 ) ;
F_18 ( & V_6 -> V_25 , & V_2 -> V_26 ) ;
F_14 ( & V_2 -> V_27 ) ;
}
static void F_19 ( struct V_28 * V_29 ,
struct V_5 * V_6 )
{
struct V_5 * V_30 ;
if ( F_13 ( & V_29 -> V_31 ) )
goto V_32;
V_30 = F_20 ( V_29 -> V_31 . V_33 ,
struct V_5 , V_25 ) ;
V_30 -> V_22 -> V_34 [ V_30 -> V_22 -> V_35 ] = V_6 -> V_24 ;
V_32:
F_7 ( & V_6 -> V_25 , & V_29 -> V_31 ) ;
if ( V_6 -> V_36 )
F_7 ( & V_6 -> V_36 -> V_37 . V_38 , & V_29 -> V_39 ) ;
}
static void F_21 ( struct V_40 * V_15 ,
unsigned long V_41 ,
bool V_42 )
{
struct V_43 * V_44 =
(struct V_43 * ) V_41 ;
if ( ! V_41 )
return;
if ( V_42 )
goto V_45;
F_22 ( & V_44 -> V_46 ) ;
if ( F_23 ( & V_44 -> V_46 ) > 0 )
return;
if ( V_44 -> V_47 )
return;
V_45:
F_24 ( V_15 , V_44 -> V_48 ,
V_49 ) ;
F_25 ( V_44 -> V_50 ,
V_44 -> V_51 ,
V_44 -> V_52 ) ;
if ( ! V_44 -> V_53 )
F_16 ( & V_44 -> V_25 ) ;
F_26 ( V_44 -> V_48 ) ;
F_10 ( V_44 -> V_48 ) ;
V_44 -> V_48 = NULL ;
F_10 ( V_44 -> V_50 ) ;
V_44 -> V_50 = NULL ;
F_10 ( V_44 ) ;
V_44 = NULL ;
}
static T_1 * F_27 ( struct V_40 * V_15 ,
unsigned long V_54 ,
unsigned long V_55 ,
struct V_56 * V_57 ,
unsigned long * V_41 )
{
struct V_58 * V_59 = V_57 -> V_60 ;
struct V_28 * V_29 = V_59 -> V_29 ;
struct V_43 * V_44 ;
struct V_1 * V_2 ;
struct V_61 * * V_50 ;
struct V_62 * V_48 ;
struct V_63 * V_52 ;
unsigned long V_64 , V_65 ;
unsigned int V_51 , V_66 ;
int V_11 ;
if ( ! V_55 ) {
F_28 ( L_4 ) ;
return F_29 ( - V_67 ) ;
}
V_2 = F_30 ( V_29 -> V_4 ) ;
F_31 (g2d_userptr, &g2d_priv->userptr_list, list) {
if ( V_44 -> V_54 == V_54 ) {
if ( V_44 -> V_55 == V_55 ) {
F_32 ( & V_44 -> V_46 ) ;
* V_41 = ( unsigned long ) V_44 ;
return & V_44 -> V_24 ;
}
V_44 -> V_53 = true ;
V_44 -> V_47 = false ;
F_16 ( & V_44 -> V_25 ) ;
break;
}
}
V_44 = F_33 ( sizeof( * V_44 ) , V_18 ) ;
if ( ! V_44 ) {
F_28 ( L_5 ) ;
return F_29 ( - V_19 ) ;
}
F_34 ( & V_44 -> V_46 , 1 ) ;
V_64 = V_54 & V_68 ;
V_66 = V_54 & ~ V_68 ;
V_65 = F_35 ( V_54 + V_55 ) ;
V_51 = ( V_65 - V_64 ) >> V_69 ;
V_44 -> V_51 = V_51 ;
V_50 = F_33 ( V_51 * sizeof( struct V_61 * ) , V_18 ) ;
if ( ! V_50 ) {
F_28 ( L_6 ) ;
F_10 ( V_44 ) ;
return F_29 ( - V_19 ) ;
}
V_52 = F_36 ( V_70 -> V_71 , V_54 ) ;
if ( ! V_52 ) {
F_28 ( L_7 ) ;
V_11 = - V_72 ;
goto V_73;
}
if ( V_52 -> V_74 < V_54 + V_55 ) {
F_28 ( L_8 ) ;
V_11 = - V_72 ;
goto V_73;
}
V_44 -> V_52 = F_37 ( V_52 ) ;
if ( ! V_44 -> V_52 ) {
F_28 ( L_9 ) ;
V_11 = - V_19 ;
goto V_73;
}
V_44 -> V_55 = V_55 ;
V_11 = F_38 ( V_64 & V_68 ,
V_51 , V_50 , V_52 ) ;
if ( V_11 < 0 ) {
F_28 ( L_10 ) ;
goto V_75;
}
V_44 -> V_50 = V_50 ;
V_48 = F_33 ( sizeof *V_48 , V_18 ) ;
if ( ! V_48 ) {
F_28 ( L_11 ) ;
V_11 = - V_19 ;
goto V_76;
}
V_11 = F_39 ( V_48 , V_50 , V_51 , V_66 ,
V_55 , V_18 ) ;
if ( V_11 < 0 ) {
F_28 ( L_12 ) ;
goto V_77;
}
V_44 -> V_48 = V_48 ;
V_11 = F_40 ( V_15 , V_44 -> V_48 ,
V_49 ) ;
if ( V_11 < 0 ) {
F_28 ( L_13 ) ;
goto V_77;
}
V_44 -> V_24 = V_48 -> V_78 [ 0 ] . V_79 ;
V_44 -> V_54 = V_54 ;
F_7 ( & V_44 -> V_25 , & V_29 -> V_80 ) ;
if ( V_2 -> V_81 + ( V_51 << V_69 ) < V_2 -> V_82 ) {
V_2 -> V_81 += V_51 << V_69 ;
V_44 -> V_47 = true ;
}
* V_41 = ( unsigned long ) V_44 ;
return & V_44 -> V_24 ;
V_77:
F_26 ( V_48 ) ;
F_10 ( V_48 ) ;
V_48 = NULL ;
V_76:
F_25 ( V_44 -> V_50 ,
V_44 -> V_51 ,
V_44 -> V_52 ) ;
V_75:
F_41 ( V_44 -> V_52 ) ;
V_73:
F_10 ( V_50 ) ;
F_10 ( V_44 ) ;
V_50 = NULL ;
V_44 = NULL ;
return F_29 ( V_11 ) ;
}
static void F_42 ( struct V_40 * V_15 ,
struct V_1 * V_2 ,
struct V_56 * V_57 )
{
struct V_58 * V_59 = V_57 -> V_60 ;
struct V_28 * V_29 = V_59 -> V_29 ;
struct V_43 * V_44 , * V_83 ;
F_43 (g2d_userptr, n, &g2d_priv->userptr_list, list)
if ( V_44 -> V_47 )
F_21 ( V_15 ,
( unsigned long ) V_44 ,
true ) ;
V_2 -> V_81 = 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_40 * V_15 ,
struct V_56 * V_84 )
{
struct V_85 * V_22 = V_6 -> V_22 ;
int V_66 ;
int V_86 ;
for ( V_86 = 0 ; V_86 < V_6 -> V_87 ; V_86 ++ ) {
unsigned long V_88 ;
T_1 * V_89 ;
V_66 = V_22 -> V_35 - ( V_86 * 2 + 1 ) ;
V_88 = V_22 -> V_34 [ V_66 ] ;
if ( V_6 -> V_90 [ V_86 ] == V_91 ) {
V_89 = F_45 ( V_15 , V_88 ,
V_84 ) ;
if ( F_46 ( V_89 ) ) {
V_6 -> V_87 = V_86 ;
return - V_72 ;
}
} else {
struct V_92 V_44 ;
if ( F_47 ( & V_44 , ( void V_93 * ) V_88 ,
sizeof( struct V_92 ) ) ) {
V_6 -> V_87 = V_86 ;
return - V_72 ;
}
V_89 = F_27 ( V_15 ,
V_44 . V_54 ,
V_44 . V_55 ,
V_84 ,
& V_88 ) ;
if ( F_46 ( V_89 ) ) {
V_6 -> V_87 = V_86 ;
return - V_72 ;
}
}
V_22 -> V_34 [ V_66 ] = * V_89 ;
V_6 -> V_94 [ V_86 ] = V_88 ;
}
return 0 ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_56 * V_57 )
{
struct V_8 * V_9 = & V_2 -> V_9 ;
int V_86 ;
for ( V_86 = 0 ; V_86 < V_6 -> V_87 ; V_86 ++ ) {
unsigned long V_88 = V_6 -> V_94 [ V_86 ] ;
if ( V_6 -> V_90 [ V_86 ] == V_91 )
F_49 ( V_9 -> V_15 , V_88 ,
V_57 ) ;
else
F_21 ( V_9 -> V_15 , V_88 ,
false ) ;
V_6 -> V_94 [ V_86 ] = 0 ;
}
V_6 -> V_87 = 0 ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
struct V_5 * V_6 =
F_15 ( & V_96 -> V_97 ,
struct V_5 , V_25 ) ;
F_51 ( V_2 -> V_4 ) ;
F_52 ( V_2 -> V_98 ) ;
F_53 ( V_99 | V_100 | V_101 ,
V_2 -> V_102 + V_103 ) ;
F_53 ( V_6 -> V_24 , V_2 -> V_102 + V_104 ) ;
F_53 ( V_105 , V_2 -> V_102 + V_106 ) ;
}
static struct V_95 * F_54 ( struct V_1 * V_2 )
{
struct V_95 * V_96 ;
if ( F_13 ( & V_2 -> V_107 ) )
return NULL ;
V_96 = F_15 ( & V_2 -> V_107 ,
struct V_95 , V_25 ) ;
F_16 ( & V_96 -> V_25 ) ;
return V_96 ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
struct V_5 * V_6 ;
if ( ! V_96 )
return;
F_12 ( & V_2 -> V_27 ) ;
F_31 (node, &runqueue_node->run_cmdlist, list)
F_48 ( V_2 , V_6 , V_96 -> V_57 ) ;
F_56 ( & V_96 -> V_97 , & V_2 -> V_26 ) ;
F_14 ( & V_2 -> V_27 ) ;
F_57 ( V_2 -> V_108 , V_96 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
V_2 -> V_96 = F_54 ( V_2 ) ;
if ( V_2 -> V_96 )
F_50 ( V_2 , V_2 -> V_96 ) ;
}
static void F_59 ( struct V_109 * V_110 )
{
struct V_1 * V_2 = F_60 ( V_110 , struct V_1 ,
V_111 ) ;
F_12 ( & V_2 -> V_112 ) ;
F_61 ( V_2 -> V_98 ) ;
F_62 ( V_2 -> V_4 ) ;
F_63 ( & V_2 -> V_96 -> F_63 ) ;
if ( V_2 -> V_96 -> V_113 )
F_55 ( V_2 , V_2 -> V_96 ) ;
if ( V_2 -> V_114 )
V_2 -> V_96 = NULL ;
else
F_58 ( V_2 ) ;
F_14 ( & V_2 -> V_112 ) ;
}
static void F_64 ( struct V_1 * V_2 , T_2 V_115 )
{
struct V_40 * V_15 = V_2 -> V_9 . V_15 ;
struct V_95 * V_96 = V_2 -> V_96 ;
struct V_116 * V_117 ;
struct V_118 V_119 ;
unsigned long V_120 ;
if ( F_13 ( & V_96 -> V_39 ) )
return;
V_117 = F_15 ( & V_96 -> V_39 ,
struct V_116 , V_37 . V_38 ) ;
F_65 ( & V_119 ) ;
V_117 -> V_36 . V_121 = V_119 . V_121 ;
V_117 -> V_36 . V_122 = V_119 . V_122 ;
V_117 -> V_36 . V_115 = V_115 ;
F_66 ( & V_15 -> V_123 , V_120 ) ;
F_18 ( & V_117 -> V_37 . V_38 , & V_117 -> V_37 . V_59 -> V_39 ) ;
F_67 ( & V_117 -> V_37 . V_59 -> V_124 ) ;
F_68 ( & V_15 -> V_123 , V_120 ) ;
}
static T_3 F_69 ( int V_125 , void * V_126 )
{
struct V_1 * V_2 = V_126 ;
T_2 V_127 ;
V_127 = F_70 ( V_2 -> V_102 + V_128 ) ;
if ( V_127 )
F_53 ( V_127 , V_2 -> V_102 + V_128 ) ;
if ( V_127 & V_129 ) {
T_2 V_115 = F_70 ( V_2 -> V_102 + V_130 ) ;
V_115 = ( V_115 & V_131 ) >>
V_132 ;
F_64 ( V_2 , V_115 ) ;
F_53 ( 0 , V_2 -> V_102 + V_133 ) ;
if ( ! ( V_127 & V_134 ) ) {
F_53 ( V_135 ,
V_2 -> V_102 + V_106 ) ;
}
}
if ( V_127 & V_134 )
F_71 ( V_2 -> V_136 , & V_2 -> V_111 ) ;
return V_137 ;
}
static int F_72 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
int V_10 , bool V_138 )
{
struct V_85 * V_22 = V_6 -> V_22 ;
int V_139 ;
int V_140 ;
int V_86 ;
for ( V_86 = 0 ; V_86 < V_10 ; V_86 ++ ) {
V_140 = V_22 -> V_35 - 2 * ( V_86 + 1 ) ;
if ( V_138 ) {
V_139 = ( V_22 -> V_34 [ V_140 ] &
~ 0x7fffffff ) >> 31 ;
if ( V_139 ) {
V_6 -> V_90 [ V_86 ] = V_141 ;
V_22 -> V_34 [ V_140 ] &= ~ V_142 ;
}
}
V_139 = V_22 -> V_34 [ V_140 ] & ~ 0xfffff000 ;
if ( V_139 < V_143 || V_139 > V_144 )
goto V_21;
if ( V_139 % 4 )
goto V_21;
switch ( V_139 ) {
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
if ( ! V_138 )
goto V_21;
if ( V_6 -> V_90 [ V_86 ] != V_141 )
V_6 -> V_90 [ V_86 ] = V_91 ;
break;
default:
if ( V_138 )
goto V_21;
break;
}
}
return 0 ;
V_21:
F_5 ( V_4 , L_14 , V_22 -> V_34 [ V_140 ] ) ;
return - V_67 ;
}
int F_73 ( struct V_40 * V_15 , void * V_34 ,
struct V_56 * V_84 )
{
struct V_151 * V_152 = V_34 ;
V_152 -> V_153 = V_154 ;
V_152 -> V_155 = V_156 ;
return 0 ;
}
int F_74 ( struct V_40 * V_15 , void * V_34 ,
struct V_56 * V_84 )
{
struct V_58 * V_59 = V_84 -> V_60 ;
struct V_28 * V_29 = V_59 -> V_29 ;
struct V_3 * V_4 = V_29 -> V_4 ;
struct V_1 * V_2 ;
struct V_157 * V_158 = V_34 ;
struct V_159 * V_160 ;
struct V_116 * V_117 ;
struct V_5 * V_6 ;
struct V_85 * V_22 ;
unsigned long V_120 ;
int V_55 ;
int V_11 ;
if ( ! V_4 )
return - V_161 ;
V_2 = F_30 ( V_4 ) ;
if ( ! V_2 )
return - V_72 ;
V_6 = F_11 ( V_2 ) ;
if ( ! V_6 )
return - V_19 ;
V_6 -> V_36 = NULL ;
if ( V_158 -> V_162 != V_163 ) {
F_66 ( & V_15 -> V_123 , V_120 ) ;
if ( V_84 -> V_164 < sizeof( V_117 -> V_36 ) ) {
F_68 ( & V_15 -> V_123 , V_120 ) ;
V_11 = - V_19 ;
goto V_21;
}
V_84 -> V_164 -= sizeof( V_117 -> V_36 ) ;
F_68 ( & V_15 -> V_123 , V_120 ) ;
V_117 = F_33 ( sizeof( * V_6 -> V_36 ) , V_18 ) ;
if ( ! V_117 ) {
F_5 ( V_4 , L_15 ) ;
F_66 ( & V_15 -> V_123 , V_120 ) ;
V_84 -> V_164 += sizeof( V_117 -> V_36 ) ;
F_68 ( & V_15 -> V_123 , V_120 ) ;
V_11 = - V_19 ;
goto V_21;
}
V_117 -> V_36 . V_37 . type = V_165 ;
V_117 -> V_36 . V_37 . V_166 = sizeof( V_117 -> V_36 ) ;
V_117 -> V_36 . V_167 = V_158 -> V_167 ;
V_117 -> V_37 . V_36 = & V_117 -> V_36 . V_37 ;
V_117 -> V_37 . V_59 = V_84 ;
V_117 -> V_37 . V_168 = ( void ( * ) ( struct V_169 * ) ) F_10 ;
V_6 -> V_36 = V_117 ;
}
V_22 = V_6 -> V_22 ;
V_22 -> V_35 = 0 ;
V_22 -> V_34 [ V_22 -> V_35 ++ ] = V_170 ;
V_22 -> V_34 [ V_22 -> V_35 ++ ] = V_171 ;
V_22 -> V_34 [ V_22 -> V_35 ++ ] = V_145 ;
V_22 -> V_34 [ V_22 -> V_35 ++ ] = 0 ;
if ( V_6 -> V_36 ) {
V_22 -> V_34 [ V_22 -> V_35 ++ ] = V_133 ;
V_22 -> V_34 [ V_22 -> V_35 ++ ] = V_172 ;
}
V_55 = V_22 -> V_35 + V_158 -> V_173 * 2 + V_158 -> V_174 * 2 + 2 ;
if ( V_55 > V_175 ) {
F_5 ( V_4 , L_16 ) ;
V_11 = - V_67 ;
goto V_176;
}
V_160 = (struct V_159 * ) ( V_177 ) V_158 -> V_160 ;
if ( F_47 ( V_22 -> V_34 + V_22 -> V_35 ,
( void V_93 * ) V_160 ,
sizeof( * V_160 ) * V_158 -> V_173 ) ) {
V_11 = - V_72 ;
goto V_176;
}
V_22 -> V_35 += V_158 -> V_173 * 2 ;
V_11 = F_72 ( V_4 , V_6 , V_158 -> V_173 , false ) ;
if ( V_11 < 0 )
goto V_176;
V_6 -> V_87 = V_158 -> V_174 ;
if ( V_158 -> V_174 ) {
struct V_159 * V_178 ;
V_178 = (struct V_159 * ) ( V_177 ) V_158 -> V_178 ;
if ( F_47 ( V_22 -> V_34 + V_22 -> V_35 ,
( void V_93 * ) V_178 ,
sizeof( * V_178 ) * V_158 -> V_174 ) ) {
V_11 = - V_72 ;
goto V_176;
}
V_22 -> V_35 += V_158 -> V_174 * 2 ;
V_11 = F_72 ( V_4 , V_6 , V_158 -> V_174 , true ) ;
if ( V_11 < 0 )
goto V_176;
V_11 = F_44 ( V_2 , V_6 , V_15 , V_84 ) ;
if ( V_11 < 0 )
goto V_179;
}
V_22 -> V_34 [ V_22 -> V_35 ++ ] = V_180 ;
V_22 -> V_34 [ V_22 -> V_35 ++ ] = V_181 ;
V_22 -> V_182 = V_22 -> V_35 / 2 ;
V_22 -> V_34 [ V_22 -> V_35 ] = 0 ;
F_19 ( V_29 , V_6 ) ;
return 0 ;
V_179:
F_48 ( V_2 , V_6 , V_84 ) ;
V_176:
if ( V_6 -> V_36 ) {
F_66 ( & V_15 -> V_123 , V_120 ) ;
V_84 -> V_164 += sizeof( V_117 -> V_36 ) ;
F_68 ( & V_15 -> V_123 , V_120 ) ;
F_10 ( V_6 -> V_36 ) ;
}
V_21:
F_17 ( V_2 , V_6 ) ;
return V_11 ;
}
int F_75 ( struct V_40 * V_15 , void * V_34 ,
struct V_56 * V_84 )
{
struct V_58 * V_59 = V_84 -> V_60 ;
struct V_28 * V_29 = V_59 -> V_29 ;
struct V_3 * V_4 = V_29 -> V_4 ;
struct V_1 * V_2 ;
struct V_183 * V_158 = V_34 ;
struct V_95 * V_96 ;
struct V_184 * V_97 ;
struct V_184 * V_39 ;
if ( ! V_4 )
return - V_161 ;
V_2 = F_30 ( V_4 ) ;
if ( ! V_2 )
return - V_72 ;
V_96 = F_76 ( V_2 -> V_108 , V_18 ) ;
if ( ! V_96 ) {
F_5 ( V_4 , L_2 ) ;
return - V_19 ;
}
V_97 = & V_96 -> V_97 ;
V_39 = & V_96 -> V_39 ;
F_77 ( V_97 ) ;
F_77 ( V_39 ) ;
F_78 ( & V_96 -> F_63 ) ;
V_96 -> V_113 = V_158 -> V_113 ;
F_79 ( & V_29 -> V_31 , V_97 ) ;
F_79 ( & V_29 -> V_39 , V_39 ) ;
if ( F_13 ( V_97 ) ) {
F_5 ( V_4 , L_17 ) ;
F_57 ( V_2 -> V_108 , V_96 ) ;
return - V_185 ;
}
F_12 ( & V_2 -> V_112 ) ;
V_96 -> V_186 = V_70 -> V_186 ;
V_96 -> V_57 = V_84 ;
F_7 ( & V_96 -> V_25 , & V_2 -> V_107 ) ;
if ( ! V_2 -> V_96 )
F_58 ( V_2 ) ;
F_14 ( & V_2 -> V_112 ) ;
if ( V_96 -> V_113 )
goto V_45;
F_80 ( & V_96 -> F_63 ) ;
F_55 ( V_2 , V_96 ) ;
V_45:
return 0 ;
}
static int F_81 ( struct V_40 * V_15 , struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_11 ;
V_2 = F_30 ( V_4 ) ;
if ( ! V_2 )
return - V_72 ;
V_11 = F_1 ( V_2 ) ;
if ( V_11 < 0 ) {
F_5 ( V_4 , L_18 ) ;
return V_11 ;
}
if ( ! F_82 ( V_15 ) )
return 0 ;
V_11 = F_83 ( V_15 , V_4 ) ;
if ( V_11 < 0 ) {
F_5 ( V_4 , L_19 ) ;
F_9 ( V_2 ) ;
}
return V_11 ;
}
static void F_84 ( struct V_40 * V_15 , struct V_3 * V_4 )
{
if ( ! F_82 ( V_15 ) )
return;
F_85 ( V_15 , V_4 ) ;
}
static int F_86 ( struct V_40 * V_15 , struct V_3 * V_4 ,
struct V_56 * V_84 )
{
struct V_58 * V_59 = V_84 -> V_60 ;
struct V_28 * V_29 ;
V_29 = F_33 ( sizeof( * V_29 ) , V_18 ) ;
if ( ! V_29 ) {
F_5 ( V_4 , L_20 ) ;
return - V_19 ;
}
V_29 -> V_4 = V_4 ;
V_59 -> V_29 = V_29 ;
F_77 ( & V_29 -> V_31 ) ;
F_77 ( & V_29 -> V_39 ) ;
F_77 ( & V_29 -> V_80 ) ;
return 0 ;
}
static void F_87 ( struct V_40 * V_15 , struct V_3 * V_4 ,
struct V_56 * V_84 )
{
struct V_58 * V_59 = V_84 -> V_60 ;
struct V_28 * V_29 = V_59 -> V_29 ;
struct V_1 * V_2 ;
struct V_5 * V_6 , * V_83 ;
if ( ! V_4 )
return;
V_2 = F_30 ( V_4 ) ;
if ( ! V_2 )
return;
F_12 ( & V_2 -> V_27 ) ;
F_43 (node, n, &g2d_priv->inuse_cmdlist, list) {
F_48 ( V_2 , V_6 , V_84 ) ;
F_18 ( & V_6 -> V_25 , & V_2 -> V_26 ) ;
}
F_14 ( & V_2 -> V_27 ) ;
F_42 ( V_15 , V_2 , V_84 ) ;
F_10 ( V_59 -> V_29 ) ;
}
static int F_88 ( struct V_187 * V_188 )
{
struct V_3 * V_4 = & V_188 -> V_4 ;
struct V_189 * V_190 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_11 ;
V_2 = F_89 ( & V_188 -> V_4 , sizeof( * V_2 ) , V_18 ) ;
if ( ! V_2 ) {
F_5 ( V_4 , L_21 ) ;
return - V_19 ;
}
V_2 -> V_108 = F_90 ( L_22 ,
sizeof( struct V_95 ) , 0 , 0 , NULL ) ;
if ( ! V_2 -> V_108 )
return - V_19 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_136 = F_91 ( L_23 ) ;
if ( ! V_2 -> V_136 ) {
F_5 ( V_4 , L_24 ) ;
V_11 = - V_67 ;
goto V_191;
}
F_92 ( & V_2 -> V_111 , F_59 ) ;
F_77 ( & V_2 -> V_26 ) ;
F_77 ( & V_2 -> V_107 ) ;
F_93 ( & V_2 -> V_27 ) ;
F_93 ( & V_2 -> V_112 ) ;
V_2 -> V_98 = F_94 ( V_4 , L_25 ) ;
if ( F_46 ( V_2 -> V_98 ) ) {
F_5 ( V_4 , L_26 ) ;
V_11 = F_95 ( V_2 -> V_98 ) ;
goto V_192;
}
F_96 ( V_4 ) ;
V_190 = F_97 ( V_188 , V_193 , 0 ) ;
V_2 -> V_102 = F_98 ( & V_188 -> V_4 , V_190 ) ;
if ( ! V_2 -> V_102 ) {
F_5 ( V_4 , L_27 ) ;
V_11 = - V_194 ;
goto V_195;
}
V_2 -> V_125 = F_99 ( V_188 , 0 ) ;
if ( V_2 -> V_125 < 0 ) {
F_5 ( V_4 , L_28 ) ;
V_11 = V_2 -> V_125 ;
goto V_195;
}
V_11 = F_100 ( & V_188 -> V_4 , V_2 -> V_125 , F_69 , 0 ,
L_29 , V_2 ) ;
if ( V_11 < 0 ) {
F_5 ( V_4 , L_30 ) ;
goto V_195;
}
V_2 -> V_82 = V_196 ;
F_101 ( V_188 , V_2 ) ;
V_9 = & V_2 -> V_9 ;
V_9 -> V_4 = V_4 ;
V_9 -> V_197 = F_81 ;
V_9 -> remove = F_84 ;
V_9 -> V_198 = F_86 ;
V_9 -> V_199 = F_87 ;
V_11 = F_102 ( V_9 ) ;
if ( V_11 < 0 ) {
F_5 ( V_4 , L_31 ) ;
goto V_195;
}
F_103 ( V_4 , L_32 ,
V_154 , V_156 ) ;
return 0 ;
V_195:
F_104 ( V_4 ) ;
V_192:
F_105 ( V_2 -> V_136 ) ;
V_191:
F_106 ( V_2 -> V_108 ) ;
return V_11 ;
}
static int F_107 ( struct V_187 * V_188 )
{
struct V_1 * V_2 = F_108 ( V_188 ) ;
F_109 ( & V_2 -> V_111 ) ;
F_110 ( & V_2 -> V_9 ) ;
while ( V_2 -> V_96 ) {
F_55 ( V_2 , V_2 -> V_96 ) ;
V_2 -> V_96 = F_54 ( V_2 ) ;
}
F_104 ( & V_188 -> V_4 ) ;
F_9 ( V_2 ) ;
F_105 ( V_2 -> V_136 ) ;
F_106 ( V_2 -> V_108 ) ;
return 0 ;
}
static int F_111 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_30 ( V_4 ) ;
F_12 ( & V_2 -> V_112 ) ;
V_2 -> V_114 = true ;
F_14 ( & V_2 -> V_112 ) ;
while ( V_2 -> V_96 )
F_112 ( 500 , 1000 ) ;
F_113 ( & V_2 -> V_111 ) ;
return 0 ;
}
static int F_114 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_30 ( V_4 ) ;
V_2 -> V_114 = false ;
F_58 ( V_2 ) ;
return 0 ;
}
