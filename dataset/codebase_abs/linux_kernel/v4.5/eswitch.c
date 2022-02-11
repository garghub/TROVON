static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 )
{
int V_5 [ F_2 ( V_6 ) ] ;
int V_7 [ F_2 ( V_8 ) ] ;
void * V_9 ;
int V_10 ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
F_3 ( V_6 , V_5 ,
V_11 , V_12 ) ;
F_3 ( V_6 , V_5 , V_13 . V_14 , 1 ) ;
F_3 ( V_6 , V_5 , V_15 , V_3 ) ;
if ( V_3 )
F_3 ( V_6 , V_5 , V_16 , 1 ) ;
V_9 = F_4 ( V_6 ,
V_5 , V_17 ) ;
F_3 ( V_17 , V_9 , V_18 , 1 ) ;
if ( V_4 & V_19 )
F_3 ( V_17 , V_9 ,
V_20 , 1 ) ;
if ( V_4 & V_21 )
F_3 ( V_17 , V_9 ,
V_22 , 1 ) ;
V_10 = F_5 ( V_2 , V_5 , sizeof( V_5 ) , V_7 , sizeof( V_7 ) ) ;
if ( V_10 )
goto V_23;
V_10 = F_6 ( V_7 ) ;
if ( V_10 )
goto V_23;
return 0 ;
V_23:
return V_10 ;
}
static int F_7 ( struct V_1 * V_24 , T_2 V_3 ,
T_2 * V_7 , int V_25 )
{
T_2 V_5 [ F_2 ( V_26 ) ] ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
F_3 ( V_27 , V_5 , V_11 ,
V_28 ) ;
F_3 ( V_26 , V_5 , V_15 , V_3 ) ;
if ( V_3 )
F_3 ( V_26 , V_5 , V_16 , 1 ) ;
return F_8 ( V_24 , V_5 , sizeof( V_5 ) , V_7 , V_25 ) ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_3 ,
T_1 * V_29 , T_3 * V_30 )
{
T_2 V_7 [ F_2 ( V_31 ) ] ;
int V_10 ;
bool V_32 ;
bool V_33 ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
* V_29 = 0 ;
* V_30 = 0 ;
if ( ! F_10 ( V_2 , V_34 ) ||
! F_10 ( V_2 , V_35 ) )
return - V_36 ;
V_10 = F_7 ( V_2 , V_3 , V_7 , sizeof( V_7 ) ) ;
if ( V_10 )
goto V_7;
V_32 = F_11 ( V_31 , V_7 ,
V_37 . V_34 ) ;
V_33 = F_11 ( V_31 , V_7 ,
V_37 . V_38 ) ;
if ( V_32 || V_33 ) {
* V_29 = F_11 ( V_31 , V_7 ,
V_37 . V_39 ) ;
* V_30 = F_11 ( V_31 , V_7 ,
V_37 . V_40 ) ;
}
F_12 ( V_2 , L_1 ,
V_3 , * V_29 , * V_30 ) ;
V_7:
return V_10 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_5 , int V_41 )
{
T_2 V_7 [ F_2 ( V_42 ) ] ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
F_3 ( V_43 , V_5 , V_15 , V_3 ) ;
if ( V_3 )
F_3 ( V_43 , V_5 , V_16 , 1 ) ;
F_3 ( V_43 , V_5 , V_11 ,
V_44 ) ;
return F_8 ( V_2 , V_5 , V_41 ,
V_7 , sizeof( V_7 ) ) ;
}
static int F_14 ( struct V_1 * V_2 , T_2 V_3 ,
T_1 V_29 , T_3 V_30 , bool V_45 )
{
T_2 V_5 [ F_2 ( V_43 ) ] ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
if ( ! F_10 ( V_2 , V_34 ) ||
! F_10 ( V_2 , V_35 ) )
return - V_36 ;
F_12 ( V_2 , L_2 ,
V_3 , V_29 , V_30 , V_45 ) ;
if ( V_45 ) {
F_3 ( V_43 , V_5 ,
V_37 . V_34 , 1 ) ;
F_3 ( V_43 , V_5 ,
V_37 . V_38 , 1 ) ;
F_3 ( V_43 , V_5 ,
V_37 . V_40 , V_30 ) ;
F_3 ( V_43 , V_5 ,
V_37 . V_39 , V_29 ) ;
}
F_3 ( V_43 , V_5 ,
V_13 . V_34 , 1 ) ;
F_3 ( V_43 , V_5 ,
V_13 . V_38 , 1 ) ;
return F_13 ( V_2 , V_3 , V_5 , sizeof( V_5 ) ) ;
}
static int F_15 ( struct V_1 * V_2 , T_2 V_46 ,
T_3 * V_47 , T_3 V_48 , T_1 V_29 )
{
T_2 V_5 [ F_2 ( V_49 ) ] ;
T_2 V_7 [ F_2 ( V_50 ) ] ;
T_3 * V_51 ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
F_3 ( V_49 , V_5 , V_11 ,
V_52 ) ;
F_3 ( V_49 , V_5 , V_53 , V_46 ) ;
F_3 ( V_49 , V_5 , V_48 , V_48 ) ;
F_3 ( V_49 , V_5 , V_29 , V_29 ) ;
V_51 = F_4 ( V_49 , V_5 , V_54 ) ;
F_16 ( & V_51 [ 2 ] , V_47 ) ;
return F_8 ( V_2 , V_5 , sizeof( V_5 ) ,
V_7 , sizeof( V_7 ) ) ;
}
static int F_17 ( struct V_1 * V_2 , T_2 V_46 )
{
T_2 V_5 [ F_2 ( V_55 ) ] ;
T_2 V_7 [ F_2 ( V_56 ) ] ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
F_3 ( V_55 , V_5 , V_11 ,
V_57 ) ;
F_3 ( V_55 , V_5 , V_53 , V_46 ) ;
return F_8 ( V_2 , V_5 , sizeof( V_5 ) ,
V_7 , sizeof( V_7 ) ) ;
}
static int F_18 ( struct V_58 * V_59 , T_2 * V_60 )
{
int V_10 = 0 ;
* V_60 = F_19 ( V_59 -> V_61 , V_59 -> V_62 ) ;
if ( * V_60 >= V_59 -> V_62 )
V_10 = - V_63 ;
else
F_20 ( * V_60 , V_59 -> V_61 ) ;
return V_10 ;
}
static void F_21 ( struct V_58 * V_59 , T_2 V_60 )
{
F_22 ( V_60 , V_59 -> V_61 ) ;
}
static int F_23 ( struct V_1 * V_2 , T_3 * V_47 ,
T_3 V_48 , T_1 V_29 ,
T_2 * V_46 )
{
struct V_58 * V_59 = & V_2 -> V_64 . V_65 -> V_59 ;
int V_10 ;
V_10 = F_18 ( V_59 , V_46 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_15 ( V_2 , * V_46 , V_47 , V_48 , V_29 ) ;
if ( V_10 )
F_21 ( V_59 , * V_46 ) ;
return V_10 ;
}
static void F_24 ( struct V_1 * V_2 , T_2 V_46 )
{
struct V_58 * V_59 = & V_2 -> V_64 . V_65 -> V_59 ;
F_17 ( V_2 , V_46 ) ;
F_21 ( V_59 , V_46 ) ;
}
static struct V_66 *
F_25 ( struct V_67 * V_68 , T_3 V_47 [ V_69 ] , T_2 V_3 )
{
int V_70 = V_71 ;
struct V_72 V_73 ;
struct V_66 * V_74 = NULL ;
T_2 * V_75 ;
T_2 * V_76 ;
T_3 * V_77 ;
T_3 * V_78 ;
V_75 = F_26 ( F_27 ( V_79 ) , V_80 ) ;
V_76 = F_26 ( F_27 ( V_79 ) , V_80 ) ;
if ( ! V_75 || ! V_76 ) {
F_28 ( L_3 ) ;
goto V_7;
}
V_77 = F_4 ( V_79 , V_75 ,
V_81 . V_82 ) ;
V_78 = F_4 ( V_79 , V_76 ,
V_81 . V_82 ) ;
F_16 ( V_77 , V_47 ) ;
memset ( V_78 , 0xff , 6 ) ;
V_73 . type = V_83 ;
V_73 . V_84 = V_3 ;
F_12 ( V_68 -> V_2 ,
L_4 ,
V_77 , V_78 , V_3 ) ;
V_74 =
F_29 ( V_68 -> V_85 . V_86 ,
V_70 ,
V_76 ,
V_75 ,
V_87 ,
0 , & V_73 ) ;
if ( F_30 ( V_74 ) ) {
F_28 (
L_5 ,
V_77 , V_78 , V_3 , F_31 ( V_74 ) ) ;
V_74 = NULL ;
}
V_7:
F_32 ( V_75 ) ;
F_32 ( V_76 ) ;
return V_74 ;
}
static int F_33 ( struct V_67 * V_68 , int V_88 )
{
int V_41 = F_27 ( V_89 ) ;
struct V_1 * V_2 = V_68 -> V_2 ;
struct V_90 * V_91 ;
struct V_92 * V_86 ;
struct V_93 * V_94 ;
void * V_95 ;
int V_96 ;
T_2 * V_97 ;
T_3 * V_98 ;
int V_10 = 0 ;
F_12 ( V_2 , L_6 ,
F_34 ( V_2 , V_99 ) ) ;
V_91 = F_35 ( V_2 , V_100 ) ;
if ( ! V_91 ) {
F_36 ( V_2 , L_7 ) ;
return - V_101 ;
}
V_97 = F_37 ( V_41 ) ;
if ( ! V_97 )
return - V_101 ;
memset ( V_97 , 0 , V_41 ) ;
V_96 = F_38 ( F_34 ( V_2 , V_99 ) ) ;
V_86 = F_39 ( V_91 , 0 , V_96 ) ;
if ( F_30 ( V_86 ) ) {
V_10 = F_31 ( V_86 ) ;
F_36 ( V_2 , L_8 , V_10 ) ;
goto V_7;
}
F_3 ( V_89 , V_97 , V_102 ,
V_71 ) ;
V_95 = F_4 ( V_89 , V_97 , V_95 ) ;
V_98 = F_4 ( V_79 , V_95 , V_81 . V_82 ) ;
F_3 ( V_89 , V_97 , V_103 , 0 ) ;
F_3 ( V_89 , V_97 , V_104 , V_96 - 1 ) ;
F_40 ( V_98 ) ;
V_94 = F_41 ( V_86 , V_97 ) ;
if ( F_30 ( V_94 ) ) {
V_10 = F_31 ( V_94 ) ;
F_36 ( V_2 , L_9 , V_10 ) ;
goto V_7;
}
V_68 -> V_85 . V_105 = V_94 ;
V_68 -> V_85 . V_86 = V_86 ;
V_7:
F_32 ( V_97 ) ;
if ( V_10 && ! F_30 ( V_86 ) )
F_42 ( V_86 ) ;
return V_10 ;
}
static void F_43 ( struct V_67 * V_68 )
{
if ( ! V_68 -> V_85 . V_86 )
return;
F_12 ( V_68 -> V_2 , L_10 ) ;
F_44 ( V_68 -> V_85 . V_105 ) ;
F_42 ( V_68 -> V_85 . V_86 ) ;
V_68 -> V_85 . V_86 = NULL ;
V_68 -> V_85 . V_105 = NULL ;
}
static int F_45 ( struct V_67 * V_68 , struct V_106 * V_107 )
{
struct V_108 * V_109 = V_68 -> V_59 . V_110 ;
struct V_111 * V_112 ;
T_3 * V_47 = V_107 -> V_113 . V_114 ;
T_2 V_3 = V_107 -> V_3 ;
int V_10 ;
V_112 = F_46 ( V_109 , V_47 , struct V_111 ) ;
if ( V_112 ) {
F_36 ( V_68 -> V_2 ,
L_11 ,
V_47 , V_3 , V_112 -> V_3 ) ;
return - V_115 ;
}
V_112 = F_47 ( V_109 , V_47 , struct V_111 , V_80 ) ;
if ( ! V_112 )
return - V_101 ;
V_112 -> V_3 = V_3 ;
V_10 = F_23 ( V_68 -> V_2 , V_47 , 0 , 0 , & V_112 -> V_53 ) ;
if ( V_10 )
goto abort;
if ( V_68 -> V_85 . V_86 )
V_107 -> V_74 = F_25 ( V_68 , V_47 , V_3 ) ;
F_12 ( V_68 -> V_2 , L_12 ,
V_3 , V_47 , V_112 -> V_53 , V_107 -> V_74 ) ;
return V_10 ;
abort:
F_48 ( V_112 ) ;
return V_10 ;
}
static int F_49 ( struct V_67 * V_68 , struct V_106 * V_107 )
{
struct V_108 * V_109 = V_68 -> V_59 . V_110 ;
struct V_111 * V_112 ;
T_3 * V_47 = V_107 -> V_113 . V_114 ;
T_2 V_3 = V_107 -> V_3 ;
V_112 = F_46 ( V_109 , V_47 , struct V_111 ) ;
if ( ! V_112 || V_112 -> V_3 != V_3 ) {
F_12 ( V_68 -> V_2 ,
L_13 ,
V_47 , V_3 ) ;
return - V_116 ;
}
F_12 ( V_68 -> V_2 , L_14 ,
V_3 , V_47 , V_112 -> V_53 , V_107 -> V_74 ) ;
F_24 ( V_68 -> V_2 , V_112 -> V_53 ) ;
if ( V_107 -> V_74 )
F_50 ( V_107 -> V_74 ) ;
V_107 -> V_74 = NULL ;
F_48 ( V_112 ) ;
return 0 ;
}
static int F_51 ( struct V_67 * V_68 , struct V_106 * V_107 )
{
struct V_108 * V_109 = V_68 -> V_117 ;
struct V_118 * V_119 ;
T_3 * V_47 = V_107 -> V_113 . V_114 ;
T_2 V_3 = V_107 -> V_3 ;
if ( ! V_68 -> V_85 . V_86 )
return 0 ;
V_119 = F_46 ( V_109 , V_47 , struct V_118 ) ;
if ( V_119 )
goto V_120;
V_119 = F_47 ( V_109 , V_47 , struct V_118 , V_80 ) ;
if ( ! V_119 )
return - V_101 ;
V_119 -> V_121 =
F_25 ( V_68 , V_47 , V_122 ) ;
V_120:
V_119 -> V_123 ++ ;
V_107 -> V_74 = F_25 ( V_68 , V_47 , V_3 ) ;
F_12 ( V_68 -> V_2 ,
L_15 ,
V_3 , V_47 , V_107 -> V_74 ,
V_119 -> V_123 , V_119 -> V_121 ) ;
return 0 ;
}
static int F_52 ( struct V_67 * V_68 , struct V_106 * V_107 )
{
struct V_108 * V_109 = V_68 -> V_117 ;
struct V_118 * V_119 ;
T_3 * V_47 = V_107 -> V_113 . V_114 ;
T_2 V_3 = V_107 -> V_3 ;
if ( ! V_68 -> V_85 . V_86 )
return 0 ;
V_119 = F_46 ( V_109 , V_47 , struct V_118 ) ;
if ( ! V_119 ) {
F_36 ( V_68 -> V_2 ,
L_16 ,
V_47 , V_3 ) ;
return - V_116 ;
}
F_12 ( V_68 -> V_2 ,
L_17 ,
V_3 , V_47 , V_107 -> V_74 , V_119 -> V_123 ,
V_119 -> V_121 ) ;
if ( V_107 -> V_74 )
F_50 ( V_107 -> V_74 ) ;
V_107 -> V_74 = NULL ;
if ( -- V_119 -> V_123 )
return 0 ;
if ( V_119 -> V_121 )
F_50 ( V_119 -> V_121 ) ;
F_48 ( V_119 ) ;
return 0 ;
}
static void F_53 ( struct V_67 * V_68 ,
T_2 V_84 , int V_124 )
{
struct V_125 * V_3 = & V_68 -> V_126 [ V_84 ] ;
bool V_127 = V_124 == V_128 ;
T_4 V_129 ;
T_4 V_130 ;
struct V_106 * V_114 ;
struct V_131 * V_113 ;
struct V_108 * V_109 ;
struct V_132 * V_133 ;
int V_134 ;
V_129 = V_127 ? F_45 :
F_51 ;
V_130 = V_127 ? F_49 :
F_52 ;
V_109 = V_127 ? V_3 -> V_135 : V_3 -> V_136 ;
F_54 (node, tmp, hash, hi) {
V_114 = F_55 ( V_113 , struct V_106 , V_113 ) ;
switch ( V_114 -> V_137 ) {
case V_138 :
V_129 ( V_68 , V_114 ) ;
V_114 -> V_137 = V_139 ;
break;
case V_140 :
V_130 ( V_68 , V_114 ) ;
F_48 ( V_114 ) ;
break;
}
}
}
static void F_56 ( struct V_67 * V_68 ,
T_2 V_84 , int V_124 )
{
struct V_125 * V_3 = & V_68 -> V_126 [ V_84 ] ;
bool V_127 = V_124 == V_128 ;
T_3 ( * V_141 ) [ V_69 ] ;
struct V_131 * V_113 ;
struct V_106 * V_114 ;
struct V_108 * V_109 ;
struct V_132 * V_133 ;
int V_62 ;
int V_10 ;
int V_134 ;
int V_142 ;
V_62 = V_127 ? F_57 ( V_68 -> V_2 ) :
F_58 ( V_68 -> V_2 ) ;
V_141 = F_59 ( V_62 , V_69 , V_80 ) ;
if ( ! V_141 )
return;
V_109 = V_127 ? V_3 -> V_135 : V_3 -> V_136 ;
F_54 (node, tmp, hash, hi) {
V_114 = F_55 ( V_113 , struct V_106 , V_113 ) ;
V_114 -> V_137 = V_140 ;
}
V_10 = F_60 ( V_68 -> V_2 , V_84 , V_124 ,
V_141 , & V_62 ) ;
if ( V_10 )
return;
F_12 ( V_68 -> V_2 , L_18 ,
V_84 , V_127 ? L_19 : L_20 , V_62 ) ;
for ( V_142 = 0 ; V_142 < V_62 ; V_142 ++ ) {
if ( V_127 && ! F_61 ( V_141 [ V_142 ] ) )
continue;
if ( ! V_127 && ! F_62 ( V_141 [ V_142 ] ) )
continue;
V_114 = F_46 ( V_109 , V_141 [ V_142 ] , struct V_106 ) ;
if ( V_114 ) {
V_114 -> V_137 = V_139 ;
continue;
}
V_114 = F_47 ( V_109 , V_141 [ V_142 ] , struct V_106 ,
V_80 ) ;
if ( ! V_114 ) {
F_36 ( V_68 -> V_2 ,
L_21 ,
V_141 [ V_142 ] , V_84 ) ;
continue;
}
V_114 -> V_3 = V_84 ;
V_114 -> V_137 = V_138 ;
}
F_32 ( V_141 ) ;
}
static void F_63 ( struct V_143 * V_144 )
{
struct V_125 * V_3 =
F_55 ( V_144 , struct V_125 , V_145 ) ;
struct V_1 * V_2 = V_3 -> V_2 ;
struct V_67 * V_68 = V_2 -> V_64 . V_65 ;
T_3 V_47 [ V_69 ] ;
F_64 ( V_2 , V_3 -> V_3 , V_47 ) ;
F_12 ( V_2 , L_22 ,
V_3 -> V_3 , V_47 ) ;
if ( V_3 -> V_146 & V_19 ) {
F_56 ( V_68 , V_3 -> V_3 ,
V_128 ) ;
F_53 ( V_68 , V_3 -> V_3 ,
V_128 ) ;
}
if ( V_3 -> V_146 & V_21 ) {
F_56 ( V_68 , V_3 -> V_3 ,
V_147 ) ;
F_53 ( V_68 , V_3 -> V_3 ,
V_147 ) ;
}
F_12 ( V_68 -> V_2 , L_23 , V_3 -> V_3 ) ;
if ( V_3 -> V_148 )
F_1 ( V_2 , V_3 -> V_3 ,
V_3 -> V_146 ) ;
}
static void F_65 ( struct V_67 * V_68 , int V_84 ,
int V_149 )
{
struct V_125 * V_3 = & V_68 -> V_126 [ V_84 ] ;
unsigned long V_150 ;
F_66 ( V_3 -> V_148 ) ;
F_12 ( V_68 -> V_2 , L_24 , V_84 ) ;
F_67 ( V_68 -> V_2 ,
V_151 ,
V_84 ,
V_152 ) ;
V_3 -> V_146 = V_149 ;
F_63 ( & V_3 -> V_145 ) ;
F_68 ( & V_3 -> V_153 , V_150 ) ;
V_3 -> V_148 = true ;
F_69 ( & V_3 -> V_153 , V_150 ) ;
F_1 ( V_68 -> V_2 , V_84 , V_149 ) ;
V_68 -> V_154 ++ ;
F_12 ( V_68 -> V_2 , L_25 , V_84 ) ;
}
static void F_70 ( struct V_67 * V_68 , T_1 V_84 )
{
struct V_125 * V_3 = & V_68 -> V_126 [ V_84 ] ;
struct V_131 * V_113 ;
struct V_106 * V_114 ;
struct V_132 * V_133 ;
int V_134 ;
F_54 (node, tmp, vport->uc_list, hi) {
V_114 = F_55 ( V_113 , struct V_106 , V_113 ) ;
V_114 -> V_137 = V_140 ;
}
F_53 ( V_68 , V_84 , V_128 ) ;
F_54 (node, tmp, vport->mc_list, hi) {
V_114 = F_55 ( V_113 , struct V_106 , V_113 ) ;
V_114 -> V_137 = V_140 ;
}
F_53 ( V_68 , V_84 , V_147 ) ;
}
static void F_71 ( struct V_67 * V_68 , int V_84 )
{
struct V_125 * V_3 = & V_68 -> V_126 [ V_84 ] ;
unsigned long V_150 ;
if ( ! V_3 -> V_148 )
return;
F_12 ( V_68 -> V_2 , L_26 , V_84 ) ;
F_68 ( & V_3 -> V_153 , V_150 ) ;
V_3 -> V_148 = false ;
V_3 -> V_146 = 0 ;
F_69 ( & V_3 -> V_153 , V_150 ) ;
F_67 ( V_68 -> V_2 ,
V_151 ,
V_84 ,
V_155 ) ;
F_72 ( V_68 -> V_156 ) ;
F_1 ( V_68 -> V_2 , V_3 -> V_3 , 0 ) ;
F_70 ( V_68 , V_84 ) ;
V_68 -> V_154 -- ;
}
int F_73 ( struct V_67 * V_68 , int V_157 )
{
int V_10 ;
int V_142 ;
if ( ! V_68 || ! F_74 ( V_68 -> V_2 , V_158 ) ||
F_74 ( V_68 -> V_2 , V_159 ) != V_160 )
return 0 ;
if ( ! F_74 ( V_68 -> V_2 , V_161 ) ||
! F_34 ( V_68 -> V_2 , V_162 ) ) {
F_36 ( V_68 -> V_2 , L_27 ) ;
return - V_36 ;
}
F_75 ( V_68 -> V_2 , L_28 , V_157 ) ;
F_71 ( V_68 , 0 ) ;
V_10 = F_33 ( V_68 , V_157 + 1 ) ;
if ( V_10 )
goto abort;
for ( V_142 = 0 ; V_142 <= V_157 ; V_142 ++ )
F_65 ( V_68 , V_142 , V_163 ) ;
F_75 ( V_68 -> V_2 , L_29 ,
V_68 -> V_154 ) ;
return 0 ;
abort:
F_65 ( V_68 , 0 , V_19 ) ;
return V_10 ;
}
void F_76 ( struct V_67 * V_68 )
{
int V_142 ;
if ( ! V_68 || ! F_74 ( V_68 -> V_2 , V_158 ) ||
F_74 ( V_68 -> V_2 , V_159 ) != V_160 )
return;
F_75 ( V_68 -> V_2 , L_30 ,
V_68 -> V_154 ) ;
for ( V_142 = 0 ; V_142 < V_68 -> V_164 ; V_142 ++ )
F_71 ( V_68 , V_142 ) ;
F_43 ( V_68 ) ;
F_65 ( V_68 , 0 , V_19 ) ;
}
int F_77 ( struct V_1 * V_2 )
{
int V_165 = 1 << F_74 ( V_2 , V_166 ) ;
int V_164 = 1 + F_78 ( V_2 -> V_167 ) ;
struct V_67 * V_68 ;
int V_84 ;
int V_10 ;
if ( ! F_74 ( V_2 , V_158 ) ||
F_74 ( V_2 , V_159 ) != V_160 )
return 0 ;
F_75 ( V_2 ,
L_31 ,
V_164 , V_165 ,
F_57 ( V_2 ) ,
F_58 ( V_2 ) ) ;
V_68 = F_26 ( sizeof( * V_68 ) , V_80 ) ;
if ( ! V_68 )
return - V_101 ;
V_68 -> V_2 = V_2 ;
V_68 -> V_59 . V_61 = F_59 ( F_79 ( V_165 ) ,
sizeof( V_168 ) , V_80 ) ;
if ( ! V_68 -> V_59 . V_61 ) {
V_10 = - V_101 ;
goto abort;
}
V_68 -> V_59 . V_62 = V_165 ;
V_68 -> V_156 = F_80 ( L_32 ) ;
if ( ! V_68 -> V_156 ) {
V_10 = - V_101 ;
goto abort;
}
V_68 -> V_126 = F_59 ( V_164 , sizeof( struct V_125 ) ,
V_80 ) ;
if ( ! V_68 -> V_126 ) {
V_10 = - V_101 ;
goto abort;
}
for ( V_84 = 0 ; V_84 < V_164 ; V_84 ++ ) {
struct V_125 * V_3 = & V_68 -> V_126 [ V_84 ] ;
V_3 -> V_3 = V_84 ;
V_3 -> V_2 = V_2 ;
F_81 ( & V_3 -> V_145 ,
F_63 ) ;
F_82 ( & V_3 -> V_153 ) ;
}
V_68 -> V_164 = V_164 ;
V_68 -> V_154 = 0 ;
V_2 -> V_64 . V_65 = V_68 ;
F_65 ( V_68 , 0 , V_19 ) ;
return 0 ;
abort:
if ( V_68 -> V_156 )
F_83 ( V_68 -> V_156 ) ;
F_32 ( V_68 -> V_59 . V_61 ) ;
F_32 ( V_68 -> V_126 ) ;
F_32 ( V_68 ) ;
return V_10 ;
}
void F_84 ( struct V_67 * V_68 )
{
if ( ! V_68 || ! F_74 ( V_68 -> V_2 , V_158 ) ||
F_74 ( V_68 -> V_2 , V_159 ) != V_160 )
return;
F_75 ( V_68 -> V_2 , L_33 ) ;
F_71 ( V_68 , 0 ) ;
V_68 -> V_2 -> V_64 . V_65 = NULL ;
F_83 ( V_68 -> V_156 ) ;
F_32 ( V_68 -> V_59 . V_61 ) ;
F_32 ( V_68 -> V_126 ) ;
F_32 ( V_68 ) ;
}
void F_85 ( struct V_67 * V_68 , struct V_169 * V_170 )
{
struct V_171 * V_172 = & V_170 -> V_173 . V_174 ;
T_1 V_84 = F_86 ( V_172 -> V_84 ) ;
struct V_125 * V_3 ;
if ( ! V_68 ) {
F_28 ( L_34 ,
V_84 ) ;
return;
}
V_3 = & V_68 -> V_126 [ V_84 ] ;
F_87 ( & V_3 -> V_153 ) ;
if ( V_3 -> V_148 )
F_88 ( V_68 -> V_156 , & V_3 -> V_145 ) ;
F_89 ( & V_3 -> V_153 ) ;
}
int F_90 ( struct V_67 * V_68 ,
int V_3 , T_3 V_47 [ V_69 ] )
{
int V_10 = 0 ;
if ( ! F_91 ( V_68 ) )
return - V_175 ;
if ( ! F_92 ( V_68 , V_3 ) )
return - V_116 ;
V_10 = F_93 ( V_68 -> V_2 , V_3 , V_47 ) ;
if ( V_10 ) {
F_94 ( V_68 -> V_2 ,
L_35 ,
V_3 , V_10 ) ;
return V_10 ;
}
return V_10 ;
}
int F_95 ( struct V_67 * V_68 ,
int V_3 , int V_176 )
{
if ( ! F_91 ( V_68 ) )
return - V_175 ;
if ( ! F_92 ( V_68 , V_3 ) )
return - V_116 ;
return F_67 ( V_68 -> V_2 ,
V_151 ,
V_3 , V_176 ) ;
}
int F_96 ( struct V_67 * V_68 ,
int V_3 , struct V_177 * V_178 )
{
T_1 V_29 ;
T_3 V_30 ;
if ( ! F_91 ( V_68 ) )
return - V_175 ;
if ( ! F_92 ( V_68 , V_3 ) )
return - V_116 ;
memset ( V_178 , 0 , sizeof( * V_178 ) ) ;
V_178 -> V_179 = V_3 - 1 ;
F_64 ( V_68 -> V_2 , V_3 , V_178 -> V_47 ) ;
V_178 -> V_180 = F_97 ( V_68 -> V_2 ,
V_151 ,
V_3 ) ;
F_9 ( V_68 -> V_2 , V_3 , & V_29 , & V_30 ) ;
V_178 -> V_29 = V_29 ;
V_178 -> V_30 = V_30 ;
V_178 -> V_181 = 0 ;
return 0 ;
}
int F_98 ( struct V_67 * V_68 ,
int V_3 , T_1 V_29 , T_3 V_30 )
{
int V_45 = 0 ;
if ( ! F_91 ( V_68 ) )
return - V_175 ;
if ( ! F_92 ( V_68 , V_3 ) || ( V_29 > 4095 ) || ( V_30 > 7 ) )
return - V_116 ;
if ( V_29 || V_30 )
V_45 = 1 ;
return F_14 ( V_68 -> V_2 , V_3 , V_29 , V_30 , V_45 ) ;
}
int F_99 ( struct V_67 * V_68 ,
int V_3 ,
struct V_182 * V_183 )
{
int V_25 = F_27 ( V_184 ) ;
T_2 V_5 [ F_2 ( V_185 ) ] ;
int V_10 = 0 ;
T_2 * V_7 ;
if ( ! F_91 ( V_68 ) )
return - V_175 ;
if ( ! F_92 ( V_68 , V_3 ) )
return - V_116 ;
V_7 = F_37 ( V_25 ) ;
if ( ! V_7 )
return - V_101 ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
F_3 ( V_185 , V_5 , V_11 ,
V_186 ) ;
F_3 ( V_185 , V_5 , V_187 , 0 ) ;
F_3 ( V_185 , V_5 , V_15 , V_3 ) ;
if ( V_3 )
F_3 ( V_185 , V_5 , V_16 , 1 ) ;
memset ( V_7 , 0 , V_25 ) ;
V_10 = F_5 ( V_68 -> V_2 , V_5 , sizeof( V_5 ) , V_7 , V_25 ) ;
if ( V_10 )
goto V_188;
#define F_100 ( T_5 , T_6 ) \
MLX5_GET64(query_vport_counter_out, p, x)
memset ( V_183 , 0 , sizeof( * V_183 ) ) ;
V_183 -> V_189 =
F_100 ( V_7 , V_190 . V_191 ) +
F_100 ( V_7 , V_192 . V_191 ) +
F_100 ( V_7 , V_193 . V_191 ) ;
V_183 -> V_194 =
F_100 ( V_7 , V_190 . V_195 ) +
F_100 ( V_7 , V_192 . V_195 ) +
F_100 ( V_7 , V_193 . V_195 ) ;
V_183 -> V_196 =
F_100 ( V_7 , V_197 . V_191 ) +
F_100 ( V_7 , V_198 . V_191 ) +
F_100 ( V_7 , V_199 . V_191 ) ;
V_183 -> V_200 =
F_100 ( V_7 , V_197 . V_195 ) +
F_100 ( V_7 , V_198 . V_195 ) +
F_100 ( V_7 , V_199 . V_195 ) ;
V_183 -> V_201 =
F_100 ( V_7 , V_192 . V_191 ) ;
V_183 -> V_202 =
F_100 ( V_7 , V_193 . V_191 ) ;
V_188:
F_101 ( V_7 ) ;
return V_10 ;
}
