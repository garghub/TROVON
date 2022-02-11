static void F_1 ( struct V_1 * V_2 ,
void * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_3 = * (struct V_6 * ) V_3 ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_4 ( V_2 -> V_7 , V_5 -> V_8 ) ;
F_5 ( V_5 ) ;
F_6 ( V_2 ) -> V_9 = NULL ;
F_7 ( V_2 ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_10 )
{
struct V_11 * V_12 = F_9 ( V_2 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_13 * V_14 = & V_5 -> V_14 ;
F_10 ( V_12 , L_1 ) ;
if ( V_10 == V_5 -> V_15 )
return;
V_5 -> V_15 = V_10 ;
F_11 ( V_2 ) ;
F_12 ( V_12 , V_14 , V_16 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_9 ( V_2 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_10 ( V_12 , L_1 ) ;
F_14 ( V_12 , & V_5 -> V_17 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_9 ( V_2 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_10 ( V_12 , L_1 ) ;
F_16 ( V_12 , & V_5 -> V_17 ) ;
}
static bool F_17 ( struct V_1 * V_2 ,
const struct V_18 * V_10 ,
struct V_18 * V_19 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_10 = F_18 ( V_2 , V_10 ) ;
return ! ! V_5 -> V_10 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_18 * V_10 )
{
if ( F_18 ( V_2 , V_10 ) )
return V_20 ;
else
return V_21 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_18 * V_22 ,
struct V_18 * V_19 )
{
struct V_11 * V_12 = F_9 ( V_2 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_3 = & V_5 -> V_3 ;
struct V_13 * V_14 = & V_5 -> V_14 ;
T_1 * V_23 = V_14 -> V_23 ;
struct V_24 * V_10 = V_5 -> V_10 ;
struct V_25 * V_26 = & V_27 [ V_5 -> V_26 ] ;
int V_28 ;
F_10 ( V_12 , L_1 ) ;
V_23 [ V_29 ] = V_26 -> V_30 | V_10 -> V_30 ;
V_23 [ V_31 ] = 0 ;
V_23 [ V_32 ] = F_21 ( V_33 ,
V_3 -> V_34 ) ;
V_23 [ V_35 ] = V_36
| F_21 ( V_37 , V_3 -> V_38 )
| F_21 ( V_39 , V_3 -> V_40 ) ;
if ( V_3 -> V_41 )
V_23 [ V_35 ] |= V_42 ;
if ( V_3 -> V_43 )
V_23 [ V_35 ] |= V_44 ;
V_28 = ( V_22 -> V_45 & ~ 0x7 ) - ( V_22 -> V_46 & ~ 0x7 ) ;
V_23 [ V_47 ] = F_21 ( V_48 , V_28 ) ;
V_23 [ V_49 ] = F_21 ( V_50 , V_28 ) ;
V_23 [ V_51 ] = 0 ;
if ( V_3 -> V_52 )
V_23 [ V_51 ] |= V_53 ;
if ( V_3 -> V_54 )
V_23 [ V_51 ] |= V_55 ;
if ( V_22 -> V_56 & V_57 )
V_23 [ V_51 ] |= V_58 ;
if ( V_22 -> V_56 & V_59 )
V_23 [ V_51 ] |= V_60 ;
V_23 [ V_61 ] = 0 ;
V_23 [ V_62 ] = 0 ;
V_23 [ V_63 ] = 0 ;
if ( V_3 -> V_64 )
V_23 [ V_63 ] |= V_65 ;
V_23 [ V_66 ] = 0 ;
if ( V_3 -> V_67 )
V_23 [ V_66 ] |= V_68 ;
V_23 [ V_69 ] = V_5 -> V_17 . V_23 [ V_69 ] ;
F_22 ( V_2 ) ;
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
F_11 ( V_2 ) ;
F_25 ( V_2 ) ;
F_16 ( V_12 , V_14 ) ;
}
static enum V_70 F_26 ( struct V_1 * V_2 ,
struct V_71 * V_72 )
{
struct V_11 * V_12 = F_9 ( V_2 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_13 * V_14 = & V_5 -> V_14 ;
int V_73 ;
F_10 ( V_12 , L_1 ) ;
F_27 ( V_12 , V_14 , V_61 ) ;
F_27 ( V_12 , V_14 , V_16 ) ;
F_27 ( V_12 , V_14 , V_35 ) ;
F_28 ( V_12 , V_16 , V_74 |
F_29 ( V_75 , V_76 ) ) ;
F_28 ( V_12 , V_35 , V_42 ) ;
F_28 ( V_12 , V_61 , V_77 ) ;
F_28 ( V_12 , V_61 , 0 ) ;
V_73 = F_30 ( V_12 , V_61 ) ;
F_12 ( V_12 , V_14 , V_35 ) ;
F_12 ( V_12 , V_14 , V_16 ) ;
F_12 ( V_12 , V_14 , V_61 ) ;
if ( ( V_73 & ( V_78 |
V_79 |
V_80 ) ) == 0 )
V_5 -> V_81 = V_82 ;
else if ( ( V_73 & ( V_78 |
V_79 ) ) == 0 )
V_5 -> V_81 = V_83 ;
else if ( ( V_73 & V_80 ) == 0 )
V_5 -> V_81 = V_84 ;
else
V_5 -> V_81 = V_85 ;
F_31 ( & V_72 -> V_86 ,
V_2 -> V_7 -> V_87 . V_88 ,
V_5 -> V_81 ) ;
return V_5 -> V_81 ? V_89 :
V_90 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_71 * V_72 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_24 * V_10 ;
int V_91 = 0 ;
for ( V_10 = V_92 ; V_10 -> V_10 . clock ; V_10 ++ ) {
if ( ~ V_10 -> V_93 & 1 << V_5 -> V_94 ||
~ V_10 -> V_95 & 1 << V_5 -> V_26 )
continue;
F_33 ( V_72 ,
F_34 ( V_2 -> V_7 , & V_10 -> V_10 ) ) ;
V_91 ++ ;
}
return V_91 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_71 * V_72 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_96 * V_7 = V_2 -> V_7 ;
struct V_97 * V_98 = & V_7 -> V_87 ;
F_36 ( V_7 , V_99 , V_100 ) ;
V_5 -> V_8 = F_37 ( V_7 , 0 , L_2 , 0 , 2 ) ;
F_38 ( & V_72 -> V_86 , V_98 -> V_101 ,
V_5 -> V_102 ) ;
F_38 ( & V_72 -> V_86 , V_98 -> V_88 ,
V_5 -> V_81 ) ;
F_38 ( & V_72 -> V_86 , V_98 -> V_103 ,
V_5 -> V_104 ) ;
F_38 ( & V_72 -> V_86 , V_98 -> V_105 ,
V_5 -> V_106 ) ;
F_38 ( & V_72 -> V_86 , V_98 -> V_107 ,
V_5 -> V_26 ) ;
F_38 ( & V_72 -> V_86 , V_98 -> V_108 ,
V_5 -> V_109 ) ;
F_38 ( & V_72 -> V_86 , V_98 -> V_110 ,
V_5 -> V_111 ) ;
F_38 ( & V_72 -> V_86 , V_98 -> V_112 ,
V_5 -> V_113 ) ;
F_38 ( & V_72 -> V_86 , V_5 -> V_8 ,
V_5 -> V_94 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_71 * V_72 ,
struct V_114 * V_115 ,
T_2 V_116 )
{
struct V_11 * V_12 = F_9 ( V_2 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_13 * V_14 = & V_5 -> V_14 ;
struct V_97 * V_98 = & V_2 -> V_7 -> V_87 ;
struct V_117 * V_118 = V_2 -> V_118 ;
bool V_119 = false ;
F_10 ( V_12 , L_1 ) ;
if ( V_115 == V_98 -> V_101 ) {
V_5 -> V_102 = V_116 ;
F_11 ( V_2 ) ;
F_12 ( V_12 , V_14 , V_16 ) ;
} else if ( V_115 == V_98 -> V_103 ) {
V_5 -> V_104 = V_116 ;
F_25 ( V_2 ) ;
F_12 ( V_12 , V_14 , V_47 ) ;
F_12 ( V_12 , V_14 , V_120 ) ;
} else if ( V_115 == V_98 -> V_105 ) {
V_5 -> V_106 = V_116 ;
F_25 ( V_2 ) ;
F_12 ( V_12 , V_14 , V_47 ) ;
F_12 ( V_12 , V_14 , V_121 ) ;
} else if ( V_115 == V_98 -> V_107 ) {
if ( V_72 -> V_122 != V_123 )
return - V_124 ;
V_5 -> V_26 = V_116 ;
V_119 = true ;
} else if ( V_115 == V_98 -> V_108 ) {
V_5 -> V_109 = V_116 ;
F_22 ( V_2 ) ;
F_12 ( V_12 , V_14 , V_125 ) ;
} else if ( V_115 == V_98 -> V_110 ) {
V_5 -> V_111 = V_116 ;
F_25 ( V_2 ) ;
F_12 ( V_12 , V_14 , V_126 ) ;
} else if ( V_115 == V_98 -> V_112 ) {
V_5 -> V_113 = V_116 ;
F_25 ( V_2 ) ;
F_12 ( V_12 , V_14 , V_127 ) ;
} else if ( V_115 == V_5 -> V_8 ) {
if ( V_72 -> V_122 != V_123 )
return - V_124 ;
V_5 -> V_94 = V_116 ;
V_119 = true ;
} else {
return - V_124 ;
}
if ( V_119 ) {
F_40 ( V_72 , 0 , 0 ) ;
if ( V_118 ) {
struct V_128 V_129 = {
. V_118 = V_118 ,
} ;
F_41 ( & V_129 ) ;
}
}
return 0 ;
}
static int F_42 ( struct V_11 * V_12 , const struct V_130 * V_131 )
{
T_1 V_132 = V_133 ;
T_1 V_116 ;
int V_134 ;
F_10 ( V_12 , L_1 ) ;
V_134 = F_43 ( V_12 , & V_132 , sizeof( V_132 ) ) ;
if ( V_134 < 0 )
goto V_135;
V_134 = F_44 ( V_12 , & V_116 , sizeof( V_116 ) ) ;
if ( V_134 < 0 )
goto V_135;
F_45 ( V_12 , L_3 , V_116 ) ;
F_28 ( V_12 , 0x3d , 0x0 ) ;
return 0 ;
V_135:
F_46 ( V_12 , L_4 , V_134 ) ;
return - V_136 ;
}
static int F_47 ( struct V_11 * V_12 )
{
F_10 ( V_12 , L_1 ) ;
return 0 ;
}
static int F_48 ( struct V_137 * V_7 )
{
struct V_11 * V_12 = F_49 ( V_7 ) ;
F_10 ( V_12 , L_1 ) ;
F_28 ( V_12 , 0x3d , 0x0 ) ;
return 0 ;
}
static int F_50 ( struct V_11 * V_12 ,
struct V_96 * V_7 ,
struct V_138 * V_2 )
{
struct V_4 * V_5 ;
int V_139 ;
F_10 ( V_12 , L_1 ) ;
V_5 = F_51 ( sizeof( * V_5 ) , V_140 ) ;
if ( ! V_5 )
return - V_141 ;
V_2 -> V_9 = V_5 ;
V_2 -> V_142 = & V_143 ;
V_5 -> V_26 = V_144 ;
V_5 -> V_102 = V_145 ;
V_5 -> V_81 = V_85 ;
V_5 -> V_94 = 1 ;
V_5 -> V_111 = 50 ;
V_5 -> V_109 = 50 ;
V_5 -> V_113 = 50 ;
V_5 -> V_104 = 50 ;
V_5 -> V_106 = 50 ;
V_5 -> V_15 = - 1 ;
V_5 -> V_146 = F_30 ( V_12 , V_133 ) ;
if ( V_147 ) {
for ( V_139 = 0 ; V_139 < V_99 ; V_139 ++ ) {
if ( ! strcmp ( V_100 [ V_139 ] , V_147 ) ) {
V_5 -> V_26 = V_139 ;
break;
}
}
if ( V_139 == V_99 )
F_46 ( V_12 , L_5 ,
V_147 ) ;
}
if ( V_148 >= 0 && V_148 <= 2 )
V_5 -> V_94 = V_148 ;
else
F_46 ( V_12 , L_6 ,
V_148 ) ;
return 0 ;
}
static int T_3 F_52 ( void )
{
return F_53 ( V_149 , & V_150 ) ;
}
static void T_4 F_54 ( void )
{
F_55 ( & V_150 ) ;
}
