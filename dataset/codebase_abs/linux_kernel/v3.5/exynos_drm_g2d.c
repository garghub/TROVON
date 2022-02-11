static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
int V_9 ;
V_2 -> V_10 = F_2 ( V_4 , V_11 ,
& V_2 -> V_12 , V_13 ) ;
if ( ! V_2 -> V_10 ) {
F_3 ( V_4 , L_1 ) ;
return - V_14 ;
}
V_6 = F_4 ( V_15 , V_15 * sizeof( * V_6 ) ,
V_13 ) ;
if ( ! V_6 ) {
F_3 ( V_4 , L_2 ) ;
V_9 = - V_14 ;
goto V_16;
}
for ( V_8 = 0 ; V_8 < V_15 ; V_8 ++ ) {
V_6 [ V_8 ] . V_17 =
V_2 -> V_10 + V_8 * V_18 ;
V_6 [ V_8 ] . V_19 =
V_2 -> V_12 + V_8 * V_18 ;
F_5 ( & V_6 [ V_8 ] . V_20 , & V_2 -> V_21 ) ;
}
return 0 ;
V_16:
F_6 ( V_4 , V_11 , V_2 -> V_10 ,
V_2 -> V_12 ) ;
return V_9 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_8 ( V_2 -> V_7 ) ;
F_6 ( V_4 , V_11 , V_2 -> V_10 ,
V_2 -> V_12 ) ;
}
static struct V_5 * F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
F_10 ( & V_2 -> V_22 ) ;
if ( F_11 ( & V_2 -> V_21 ) ) {
F_3 ( V_4 , L_3 ) ;
F_12 ( & V_2 -> V_22 ) ;
return NULL ;
}
V_6 = F_13 ( & V_2 -> V_21 , struct V_5 ,
V_20 ) ;
F_14 ( & V_6 -> V_20 ) ;
F_12 ( & V_2 -> V_22 ) ;
return V_6 ;
}
static void F_15 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
F_10 ( & V_2 -> V_22 ) ;
F_16 ( & V_6 -> V_20 , & V_2 -> V_21 ) ;
F_12 ( & V_2 -> V_22 ) ;
}
static void F_17 ( struct V_23 * V_24 ,
struct V_5 * V_6 )
{
struct V_5 * V_25 ;
if ( F_11 ( & V_24 -> V_26 ) )
goto V_27;
V_25 = F_18 ( V_24 -> V_26 . V_28 ,
struct V_5 , V_20 ) ;
V_25 -> V_17 -> V_29 [ V_25 -> V_17 -> V_30 ] = V_6 -> V_19 ;
V_27:
F_5 ( & V_6 -> V_20 , & V_24 -> V_26 ) ;
if ( V_6 -> V_31 )
F_5 ( & V_6 -> V_31 -> V_32 . V_33 , & V_24 -> V_34 ) ;
}
static int F_19 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
struct V_5 * V_6 )
{
struct V_39 * V_40 = V_38 -> V_41 ;
struct V_23 * V_24 = V_40 -> V_24 ;
struct V_42 * V_17 = V_6 -> V_17 ;
T_1 * V_43 ;
int V_44 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_6 -> V_46 ; V_45 ++ ) {
struct V_47 * V_48 ;
V_48 = F_20 ( sizeof( * V_48 ) , V_13 ) ;
if ( ! V_48 ) {
F_3 ( V_24 -> V_4 , L_4 ) ;
return - V_14 ;
}
V_44 = V_17 -> V_30 - ( V_45 * 2 + 1 ) ;
V_48 -> V_49 = V_17 -> V_29 [ V_44 ] ;
V_43 = F_21 ( V_36 , V_48 -> V_49 ,
V_38 ) ;
if ( F_22 ( V_43 ) ) {
V_6 -> V_46 = V_45 ;
F_8 ( V_48 ) ;
return F_23 ( V_43 ) ;
}
V_17 -> V_29 [ V_44 ] = * V_43 ;
F_5 ( & V_48 -> V_20 , & V_24 -> V_50 ) ;
V_24 -> V_46 ++ ;
}
return 0 ;
}
static void F_24 ( struct V_35 * V_36 ,
struct V_37 * V_38 ,
unsigned int V_8 )
{
struct V_39 * V_40 = V_38 -> V_41 ;
struct V_23 * V_24 = V_40 -> V_24 ;
struct V_47 * V_6 , * V_51 ;
F_25 (node, n, &g2d_priv->gem_list, list) {
if ( ! V_8 )
break;
F_26 ( V_36 , V_6 -> V_49 , V_38 ) ;
F_14 ( & V_6 -> V_20 ) ;
F_8 ( V_6 ) ;
V_8 -- ;
}
}
static void F_27 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_5 * V_6 =
F_13 ( & V_53 -> V_54 ,
struct V_5 , V_20 ) ;
F_28 ( V_2 -> V_4 ) ;
F_29 ( V_2 -> V_55 ) ;
F_30 ( V_56 | V_57 | V_58 ,
V_2 -> V_59 + V_60 ) ;
F_30 ( V_6 -> V_19 , V_2 -> V_59 + V_61 ) ;
F_30 ( V_62 , V_2 -> V_59 + V_63 ) ;
}
static struct V_52 * F_31 ( struct V_1 * V_2 )
{
struct V_52 * V_53 ;
if ( F_11 ( & V_2 -> V_64 ) )
return NULL ;
V_53 = F_13 ( & V_2 -> V_64 ,
struct V_52 , V_20 ) ;
F_14 ( & V_53 -> V_20 ) ;
return V_53 ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
if ( ! V_53 )
return;
F_10 ( & V_2 -> V_22 ) ;
F_33 ( & V_53 -> V_54 , & V_2 -> V_21 ) ;
F_12 ( & V_2 -> V_22 ) ;
F_34 ( V_2 -> V_65 , V_53 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
V_2 -> V_53 = F_31 ( V_2 ) ;
if ( V_2 -> V_53 )
F_27 ( V_2 , V_2 -> V_53 ) ;
}
static void F_36 ( struct V_66 * V_67 )
{
struct V_1 * V_2 = F_37 ( V_67 , struct V_1 ,
V_68 ) ;
F_10 ( & V_2 -> V_69 ) ;
F_38 ( V_2 -> V_55 ) ;
F_39 ( V_2 -> V_4 ) ;
F_40 ( & V_2 -> V_53 -> F_40 ) ;
if ( V_2 -> V_53 -> V_70 )
F_32 ( V_2 , V_2 -> V_53 ) ;
if ( V_2 -> V_71 )
V_2 -> V_53 = NULL ;
else
F_35 ( V_2 ) ;
F_12 ( & V_2 -> V_69 ) ;
}
static void F_41 ( struct V_1 * V_2 , T_2 V_72 )
{
struct V_35 * V_36 = V_2 -> V_73 . V_36 ;
struct V_52 * V_53 = V_2 -> V_53 ;
struct V_74 * V_75 ;
struct V_76 V_77 ;
unsigned long V_78 ;
if ( F_11 ( & V_53 -> V_34 ) )
return;
V_75 = F_13 ( & V_53 -> V_34 ,
struct V_74 , V_32 . V_33 ) ;
F_42 ( & V_77 ) ;
V_75 -> V_31 . V_79 = V_77 . V_79 ;
V_75 -> V_31 . V_80 = V_77 . V_80 ;
V_75 -> V_31 . V_72 = V_72 ;
F_43 ( & V_36 -> V_81 , V_78 ) ;
F_16 ( & V_75 -> V_32 . V_33 , & V_75 -> V_32 . V_40 -> V_34 ) ;
F_44 ( & V_75 -> V_32 . V_40 -> V_82 ) ;
F_45 ( & V_36 -> V_81 , V_78 ) ;
}
static T_3 F_46 ( int V_83 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
T_2 V_85 ;
V_85 = F_47 ( V_2 -> V_59 + V_86 ) ;
if ( V_85 )
F_30 ( V_85 , V_2 -> V_59 + V_86 ) ;
if ( V_85 & V_87 ) {
T_2 V_72 = F_47 ( V_2 -> V_59 + V_88 ) ;
V_72 = ( V_72 & V_89 ) >>
V_90 ;
F_41 ( V_2 , V_72 ) ;
F_30 ( 0 , V_2 -> V_59 + V_91 ) ;
if ( ! ( V_85 & V_92 ) ) {
F_30 ( V_93 ,
V_2 -> V_59 + V_63 ) ;
}
}
if ( V_85 & V_92 )
F_48 ( V_2 -> V_94 , & V_2 -> V_68 ) ;
return V_95 ;
}
static int F_49 ( struct V_3 * V_4 , struct V_42 * V_17 ,
int V_8 , bool V_96 )
{
int V_97 ;
int V_98 ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_8 ; V_45 ++ ) {
V_98 = V_17 -> V_30 - 2 * ( V_45 + 1 ) ;
V_97 = V_17 -> V_29 [ V_98 ] & ~ 0xfffff000 ;
if ( V_97 < V_99 || V_97 > V_100 )
goto V_16;
if ( V_97 % 4 )
goto V_16;
switch ( V_97 ) {
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
if ( ! V_96 )
goto V_16;
break;
default:
if ( V_96 )
goto V_16;
break;
}
}
return 0 ;
V_16:
F_3 ( V_4 , L_5 , V_17 -> V_29 [ V_98 ] ) ;
return - V_107 ;
}
int F_50 ( struct V_35 * V_36 , void * V_29 ,
struct V_37 * V_38 )
{
struct V_108 * V_109 = V_29 ;
V_109 -> V_110 = V_111 ;
V_109 -> V_112 = V_113 ;
return 0 ;
}
int F_51 ( struct V_35 * V_36 , void * V_29 ,
struct V_37 * V_38 )
{
struct V_39 * V_40 = V_38 -> V_41 ;
struct V_23 * V_24 = V_40 -> V_24 ;
struct V_3 * V_4 = V_24 -> V_4 ;
struct V_1 * V_2 ;
struct V_114 * V_115 = V_29 ;
struct V_116 * V_117 ;
struct V_74 * V_75 ;
struct V_5 * V_6 ;
struct V_42 * V_17 ;
unsigned long V_78 ;
int V_118 ;
int V_9 ;
if ( ! V_4 )
return - V_119 ;
V_2 = F_52 ( V_4 ) ;
if ( ! V_2 )
return - V_120 ;
V_6 = F_9 ( V_2 ) ;
if ( ! V_6 )
return - V_14 ;
V_6 -> V_31 = NULL ;
if ( V_115 -> V_121 != V_122 ) {
F_43 ( & V_36 -> V_81 , V_78 ) ;
if ( V_38 -> V_123 < sizeof( V_75 -> V_31 ) ) {
F_45 ( & V_36 -> V_81 , V_78 ) ;
V_9 = - V_14 ;
goto V_16;
}
V_38 -> V_123 -= sizeof( V_75 -> V_31 ) ;
F_45 ( & V_36 -> V_81 , V_78 ) ;
V_75 = F_20 ( sizeof( * V_6 -> V_31 ) , V_13 ) ;
if ( ! V_75 ) {
F_3 ( V_4 , L_6 ) ;
F_43 ( & V_36 -> V_81 , V_78 ) ;
V_38 -> V_123 += sizeof( V_75 -> V_31 ) ;
F_45 ( & V_36 -> V_81 , V_78 ) ;
V_9 = - V_14 ;
goto V_16;
}
V_75 -> V_31 . V_32 . type = V_124 ;
V_75 -> V_31 . V_32 . V_125 = sizeof( V_75 -> V_31 ) ;
V_75 -> V_31 . V_126 = V_115 -> V_126 ;
V_75 -> V_32 . V_31 = & V_75 -> V_31 . V_32 ;
V_75 -> V_32 . V_40 = V_38 ;
V_75 -> V_32 . V_127 = ( void ( * ) ( struct V_128 * ) ) F_8 ;
V_6 -> V_31 = V_75 ;
}
V_17 = V_6 -> V_17 ;
V_17 -> V_30 = 0 ;
V_17 -> V_29 [ V_17 -> V_30 ++ ] = V_129 ;
V_17 -> V_29 [ V_17 -> V_30 ++ ] = V_130 ;
V_17 -> V_29 [ V_17 -> V_30 ++ ] = V_101 ;
V_17 -> V_29 [ V_17 -> V_30 ++ ] = 0 ;
if ( V_6 -> V_31 ) {
V_17 -> V_29 [ V_17 -> V_30 ++ ] = V_91 ;
V_17 -> V_29 [ V_17 -> V_30 ++ ] = V_131 ;
}
V_118 = V_17 -> V_30 + V_115 -> V_132 * 2 + V_115 -> V_133 * 2 + 2 ;
if ( V_118 > V_134 ) {
F_3 ( V_4 , L_7 ) ;
V_9 = - V_107 ;
goto V_135;
}
V_117 = (struct V_116 * ) ( V_136 ) V_115 -> V_117 ;
if ( F_53 ( V_17 -> V_29 + V_17 -> V_30 ,
( void V_137 * ) V_117 ,
sizeof( * V_117 ) * V_115 -> V_132 ) ) {
V_9 = - V_120 ;
goto V_135;
}
V_17 -> V_30 += V_115 -> V_132 * 2 ;
V_9 = F_49 ( V_4 , V_17 , V_115 -> V_132 , false ) ;
if ( V_9 < 0 )
goto V_135;
V_6 -> V_46 = V_115 -> V_133 ;
if ( V_115 -> V_133 ) {
struct V_116 * V_138 ;
V_138 = (struct V_116 * ) ( V_136 ) V_115 -> V_138 ;
if ( F_53 ( V_17 -> V_29 + V_17 -> V_30 ,
( void V_137 * ) V_138 ,
sizeof( * V_138 ) * V_115 -> V_133 ) ) {
V_9 = - V_120 ;
goto V_135;
}
V_17 -> V_30 += V_115 -> V_133 * 2 ;
V_9 = F_49 ( V_4 , V_17 , V_115 -> V_133 , true ) ;
if ( V_9 < 0 )
goto V_135;
V_9 = F_19 ( V_36 , V_38 , V_6 ) ;
if ( V_9 < 0 )
goto V_139;
}
V_17 -> V_29 [ V_17 -> V_30 ++ ] = V_140 ;
V_17 -> V_29 [ V_17 -> V_30 ++ ] = V_141 ;
V_17 -> V_142 = V_17 -> V_30 / 2 ;
V_17 -> V_29 [ V_17 -> V_30 ] = 0 ;
F_17 ( V_24 , V_6 ) ;
return 0 ;
V_139:
F_24 ( V_36 , V_38 , V_6 -> V_46 ) ;
V_135:
if ( V_6 -> V_31 ) {
F_43 ( & V_36 -> V_81 , V_78 ) ;
V_38 -> V_123 += sizeof( V_75 -> V_31 ) ;
F_45 ( & V_36 -> V_81 , V_78 ) ;
F_8 ( V_6 -> V_31 ) ;
}
V_16:
F_15 ( V_2 , V_6 ) ;
return V_9 ;
}
int F_54 ( struct V_35 * V_36 , void * V_29 ,
struct V_37 * V_38 )
{
struct V_39 * V_40 = V_38 -> V_41 ;
struct V_23 * V_24 = V_40 -> V_24 ;
struct V_3 * V_4 = V_24 -> V_4 ;
struct V_1 * V_2 ;
struct V_143 * V_115 = V_29 ;
struct V_52 * V_53 ;
struct V_144 * V_54 ;
struct V_144 * V_34 ;
if ( ! V_4 )
return - V_119 ;
V_2 = F_52 ( V_4 ) ;
if ( ! V_2 )
return - V_120 ;
V_53 = F_55 ( V_2 -> V_65 , V_13 ) ;
if ( ! V_53 ) {
F_3 ( V_4 , L_2 ) ;
return - V_14 ;
}
V_54 = & V_53 -> V_54 ;
V_34 = & V_53 -> V_34 ;
F_56 ( V_54 ) ;
F_56 ( V_34 ) ;
F_57 ( & V_53 -> F_40 ) ;
V_53 -> V_70 = V_115 -> V_70 ;
F_58 ( & V_24 -> V_26 , V_54 ) ;
F_58 ( & V_24 -> V_34 , V_34 ) ;
if ( F_11 ( V_54 ) ) {
F_3 ( V_4 , L_8 ) ;
F_34 ( V_2 -> V_65 , V_53 ) ;
return - V_145 ;
}
F_10 ( & V_2 -> V_69 ) ;
F_5 ( & V_53 -> V_20 , & V_2 -> V_64 ) ;
if ( ! V_2 -> V_53 )
F_35 ( V_2 ) ;
F_12 ( & V_2 -> V_69 ) ;
if ( V_53 -> V_70 )
goto V_146;
F_59 ( & V_53 -> F_40 ) ;
F_32 ( V_2 , V_53 ) ;
V_146:
return 0 ;
}
static int F_60 ( struct V_35 * V_36 , struct V_3 * V_4 ,
struct V_37 * V_38 )
{
struct V_39 * V_40 = V_38 -> V_41 ;
struct V_23 * V_24 ;
V_24 = F_20 ( sizeof( * V_24 ) , V_13 ) ;
if ( ! V_24 ) {
F_3 ( V_4 , L_9 ) ;
return - V_14 ;
}
V_24 -> V_4 = V_4 ;
V_40 -> V_24 = V_24 ;
F_56 ( & V_24 -> V_26 ) ;
F_56 ( & V_24 -> V_34 ) ;
F_56 ( & V_24 -> V_50 ) ;
return 0 ;
}
static void F_61 ( struct V_35 * V_36 , struct V_3 * V_4 ,
struct V_37 * V_38 )
{
struct V_39 * V_40 = V_38 -> V_41 ;
struct V_23 * V_24 = V_40 -> V_24 ;
struct V_1 * V_2 ;
struct V_5 * V_6 , * V_51 ;
if ( ! V_4 )
return;
V_2 = F_52 ( V_4 ) ;
if ( ! V_2 )
return;
F_10 ( & V_2 -> V_22 ) ;
F_62 (node, n, &g2d_priv->inuse_cmdlist, list)
F_16 ( & V_6 -> V_20 , & V_2 -> V_21 ) ;
F_12 ( & V_2 -> V_22 ) ;
F_24 ( V_36 , V_38 , V_24 -> V_46 ) ;
F_8 ( V_40 -> V_24 ) ;
}
static int T_4 F_63 ( struct V_147 * V_148 )
{
struct V_3 * V_4 = & V_148 -> V_4 ;
struct V_149 * V_150 ;
struct V_1 * V_2 ;
struct V_151 * V_73 ;
int V_9 ;
V_2 = F_20 ( sizeof( * V_2 ) , V_13 ) ;
if ( ! V_2 ) {
F_3 ( V_4 , L_10 ) ;
return - V_14 ;
}
V_2 -> V_65 = F_64 ( L_11 ,
sizeof( struct V_52 ) , 0 , 0 , NULL ) ;
if ( ! V_2 -> V_65 ) {
V_9 = - V_14 ;
goto V_152;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_94 = F_65 ( L_12 ) ;
if ( ! V_2 -> V_94 ) {
F_3 ( V_4 , L_13 ) ;
V_9 = - V_107 ;
goto V_153;
}
F_66 ( & V_2 -> V_68 , F_36 ) ;
F_56 ( & V_2 -> V_21 ) ;
F_56 ( & V_2 -> V_64 ) ;
F_67 ( & V_2 -> V_22 ) ;
F_67 ( & V_2 -> V_69 ) ;
V_9 = F_1 ( V_2 ) ;
if ( V_9 < 0 )
goto V_154;
V_2 -> V_55 = F_68 ( V_4 , L_14 ) ;
if ( F_22 ( V_2 -> V_55 ) ) {
F_3 ( V_4 , L_15 ) ;
V_9 = F_23 ( V_2 -> V_55 ) ;
goto V_155;
}
F_69 ( V_4 ) ;
V_150 = F_70 ( V_148 , V_156 , 0 ) ;
if ( ! V_150 ) {
F_3 ( V_4 , L_16 ) ;
V_9 = - V_157 ;
goto V_158;
}
V_2 -> V_159 = F_71 ( V_150 -> V_160 , F_72 ( V_150 ) ,
F_73 ( V_4 ) ) ;
if ( ! V_2 -> V_159 ) {
F_3 ( V_4 , L_17 ) ;
V_9 = - V_157 ;
goto V_158;
}
V_2 -> V_59 = F_74 ( V_150 -> V_160 , F_72 ( V_150 ) ) ;
if ( ! V_2 -> V_59 ) {
F_3 ( V_4 , L_18 ) ;
V_9 = - V_161 ;
goto V_162;
}
V_2 -> V_83 = F_75 ( V_148 , 0 ) ;
if ( V_2 -> V_83 < 0 ) {
F_3 ( V_4 , L_19 ) ;
V_9 = V_2 -> V_83 ;
goto V_163;
}
V_9 = F_76 ( V_2 -> V_83 , F_46 , 0 , L_20 , V_2 ) ;
if ( V_9 < 0 ) {
F_3 ( V_4 , L_21 ) ;
goto V_163;
}
F_77 ( V_148 , V_2 ) ;
V_73 = & V_2 -> V_73 ;
V_73 -> V_4 = V_4 ;
V_73 -> V_164 = F_60 ;
V_73 -> V_165 = F_61 ;
V_9 = F_78 ( V_73 ) ;
if ( V_9 < 0 ) {
F_3 ( V_4 , L_22 ) ;
goto V_166;
}
F_79 ( V_4 , L_23 ,
V_111 , V_113 ) ;
return 0 ;
V_166:
F_80 ( V_2 -> V_83 , V_2 ) ;
V_163:
F_81 ( V_2 -> V_59 ) ;
V_162:
F_82 ( V_2 -> V_159 ) ;
F_8 ( V_2 -> V_159 ) ;
V_158:
F_83 ( V_4 ) ;
F_84 ( V_2 -> V_55 ) ;
V_155:
F_7 ( V_2 ) ;
V_154:
F_85 ( V_2 -> V_94 ) ;
V_153:
F_86 ( V_2 -> V_65 ) ;
V_152:
F_8 ( V_2 ) ;
return V_9 ;
}
static int T_5 F_87 ( struct V_147 * V_148 )
{
struct V_1 * V_2 = F_88 ( V_148 ) ;
F_89 ( & V_2 -> V_68 ) ;
F_90 ( & V_2 -> V_73 ) ;
F_80 ( V_2 -> V_83 , V_2 ) ;
while ( V_2 -> V_53 ) {
F_32 ( V_2 , V_2 -> V_53 ) ;
V_2 -> V_53 = F_31 ( V_2 ) ;
}
F_81 ( V_2 -> V_59 ) ;
F_82 ( V_2 -> V_159 ) ;
F_8 ( V_2 -> V_159 ) ;
F_83 ( & V_148 -> V_4 ) ;
F_84 ( V_2 -> V_55 ) ;
F_7 ( V_2 ) ;
F_85 ( V_2 -> V_94 ) ;
F_86 ( V_2 -> V_65 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
static int F_91 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_52 ( V_4 ) ;
F_10 ( & V_2 -> V_69 ) ;
V_2 -> V_71 = true ;
F_12 ( & V_2 -> V_69 ) ;
while ( V_2 -> V_53 )
F_92 ( 500 , 1000 ) ;
F_93 ( & V_2 -> V_68 ) ;
return 0 ;
}
static int F_94 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_52 ( V_4 ) ;
V_2 -> V_71 = false ;
F_35 ( V_2 ) ;
return 0 ;
}
