static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
return F_2 ( V_2 -> V_5 , V_2 -> V_6 + V_3 , V_4 , 1 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
return F_4 ( V_2 -> V_5 , V_2 -> V_6 + V_3 , V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
T_2 V_4 ;
int V_7 ;
V_7 = F_3 ( V_2 , V_8 , V_9 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_1 ( V_2 , V_10 , & V_4 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_3 ( V_2 , V_8 , V_9 ) ;
if ( V_7 )
return V_7 ;
V_4 |= V_11 ;
return F_3 ( V_2 , V_10 , V_4 ) ;
}
static int F_6 ( struct V_1 * V_2 , bool V_12 )
{
return F_3 ( V_2 , V_13 , V_12 ? V_14 : 0 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_2 V_15 , V_16 , V_17 , V_18 , V_19 , V_20 ;
int V_7 ;
V_7 = F_1 ( V_2 , V_21 , & V_15 ) ;
if ( V_7 )
return;
V_7 = F_1 ( V_2 , V_22 , & V_18 ) ;
if ( V_7 )
return;
V_7 = F_1 ( V_2 , V_23 , & V_17 ) ;
if ( V_7 )
return;
V_7 = F_1 ( V_2 , V_24 , & V_20 ) ;
if ( V_7 )
return;
V_7 = F_1 ( V_2 , V_25 , & V_16 ) ;
if ( V_7 )
return;
V_7 = F_1 ( V_2 , V_13 , & V_19 ) ;
if ( V_7 )
return;
F_8 ( V_2 -> V_26 ,
L_1 ,
V_15 , V_19 , V_17 , V_18 , V_20 , V_16 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
T_2 V_29 , V_30 ;
int V_7 ;
V_30 = ( V_31 << V_32 ) |
V_33 | V_34 ;
V_7 = F_3 ( V_2 , V_21 , V_30 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_3 ( V_2 , V_23 , V_28 -> V_35 ) ;
if ( V_7 )
return V_7 ;
V_29 = V_28 -> V_29 << V_36 ;
V_7 = F_3 ( V_2 , V_22 , V_29 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_3 ( V_2 , V_37 , V_28 -> V_38 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_3 ( V_2 , V_39 , V_28 -> V_40 ) ;
if ( V_7 )
return V_7 ;
if ( V_28 -> V_40 )
V_7 = F_3 ( V_2 , V_41 , V_42 ) ;
else
V_7 = F_3 ( V_2 , V_41 , 0 ) ;
return V_7 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_43 )
{
unsigned int V_44 , V_45 ;
T_2 V_16 ;
int V_7 ;
V_45 = V_43 / V_46 ;
for ( V_44 = 0 ; V_44 < V_45 ; V_44 ++ ) {
V_7 = F_1 ( V_2 , V_25 , & V_16 ) ;
if ( V_7 )
return V_7 ;
V_16 &= V_47 ;
if ( V_16 == V_48 )
return 0 ;
F_11 ( V_46 , V_49 ) ;
}
F_7 ( V_2 ) ;
return - V_50 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 * V_4 )
{
int V_7 ;
V_7 = F_2 ( V_2 -> V_5 , V_2 -> V_6 + V_51 , V_4 , 2 ) ;
if ( V_7 )
return V_7 ;
* V_4 = F_13 ( T_1 , * V_4 , V_52 , V_53 ) ;
return 0 ;
}
static struct V_27 * F_14 ( struct V_1 * V_2 ,
unsigned int V_54 )
{
unsigned int V_55 ;
for ( V_55 = 0 ; V_55 < V_2 -> V_56 ; V_55 ++ )
if ( V_2 -> V_57 [ V_55 ] . V_35 == V_54 )
return & V_2 -> V_57 [ V_55 ] ;
F_15 ( V_2 -> V_26 , L_2 , V_54 ) ;
return NULL ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_27 * V_28 , T_1 * V_4 )
{
unsigned int V_58 ;
int V_7 ;
F_17 ( & V_2 -> V_59 ) ;
V_7 = F_9 ( V_2 , V_28 ) ;
if ( V_7 )
goto V_60;
if ( ! V_2 -> V_61 )
F_18 ( & V_2 -> V_62 ) ;
V_7 = F_6 ( V_2 , true ) ;
if ( V_7 )
goto V_60;
V_7 = F_3 ( V_2 , V_24 , V_63 ) ;
if ( V_7 )
goto V_64;
V_58 = F_19 ( V_28 -> V_40 ) * V_46 * 2 ;
if ( V_2 -> V_61 ) {
V_7 = F_10 ( V_2 , V_58 ) ;
} else {
V_7 = F_20 ( & V_2 -> V_62 , V_58 ) ;
if ( ! V_7 ) {
V_7 = - V_50 ;
goto V_64;
}
V_7 = F_10 ( V_2 , V_46 ) ;
if ( V_7 )
goto V_64;
}
V_7 = F_12 ( V_2 , V_4 ) ;
V_64:
F_6 ( V_2 , false ) ;
if ( V_7 )
F_8 ( V_2 -> V_26 , L_3 ) ;
V_60:
F_21 ( & V_2 -> V_59 ) ;
return V_7 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_27 * V_28 ;
T_1 V_65 , V_66 ;
int V_7 ;
V_2 -> V_67 [ V_68 ] . V_69 = V_70 ;
V_2 -> V_67 [ V_71 ] . V_69 = V_72 ;
V_28 = F_14 ( V_2 , V_73 ) ;
V_7 = F_16 ( V_2 , V_28 , & V_65 ) ;
if ( V_7 )
goto V_74;
V_28 = F_14 ( V_2 , V_75 ) ;
if ( ! V_28 )
V_28 = F_14 ( V_2 , V_76 ) ;
V_7 = F_16 ( V_2 , V_28 , & V_66 ) ;
if ( V_7 )
goto V_74;
if ( V_65 == V_66 ) {
V_7 = - V_77 ;
goto V_74;
}
V_2 -> V_67 [ V_71 ] . V_78 = V_65 - V_66 ;
V_2 -> V_67 [ V_71 ] . V_79 = V_66 ;
V_28 = F_14 ( V_2 , V_80 ) ;
V_7 = F_16 ( V_2 , V_28 , & V_65 ) ;
if ( V_7 )
goto V_74;
V_28 = F_14 ( V_2 , V_81 ) ;
V_7 = F_16 ( V_2 , V_28 , & V_66 ) ;
if ( V_7 )
goto V_74;
if ( V_65 == V_66 ) {
V_7 = - V_77 ;
goto V_74;
}
V_2 -> V_67 [ V_68 ] . V_78 = V_65 - V_66 ;
V_2 -> V_67 [ V_68 ] . V_79 = V_66 ;
V_74:
if ( V_7 )
F_8 ( V_2 -> V_26 , L_4 ) ;
return V_7 ;
}
static int F_23 ( T_3 V_54 , T_3 V_82 )
{
unsigned int V_83 ;
for ( V_83 = 0 ; V_83 < F_24 ( V_84 ) ; V_83 ++ )
if ( V_84 [ V_83 ] . V_54 == V_54 &&
V_84 [ V_83 ] . V_82 == V_82 )
break;
if ( V_83 == F_24 ( V_84 ) )
return - V_77 ;
return V_83 ;
}
static int F_25 ( T_3 V_85 )
{
if ( ( V_85 <= 1000 && V_85 % 100 ) || ( V_85 > 1000 && V_85 % 2000 ) )
return - V_77 ;
if ( V_85 <= 1000 )
V_85 /= 100 ;
else
V_85 = V_85 / 2000 + 10 ;
return V_85 ;
}
static int F_26 ( T_3 V_85 )
{
if ( ! F_27 ( V_85 ) || V_85 > V_86 )
return - V_77 ;
return F_28 ( V_85 ) ;
}
static int F_29 ( struct V_87 * V_88 ,
struct V_89 const * V_17 , int * V_90 , int * V_91 ,
long V_92 )
{
struct V_1 * V_2 = F_30 ( V_88 ) ;
struct V_27 * V_28 ;
T_1 V_93 ;
int V_7 ;
switch ( V_92 ) {
case V_94 :
V_28 = & V_2 -> V_57 [ V_17 -> V_95 ] ;
V_7 = F_16 ( V_2 , V_28 , & V_93 ) ;
if ( V_7 )
break;
V_7 = F_31 ( V_28 -> V_96 ,
& V_2 -> V_67 [ V_28 -> V_97 ] ,
& V_84 [ V_28 -> V_98 ] ,
( V_28 -> V_97 == V_71 ) ,
V_93 , V_90 ) ;
if ( V_7 )
break;
return V_99 ;
case V_100 :
V_28 = & V_2 -> V_57 [ V_17 -> V_95 ] ;
V_7 = F_16 ( V_2 , V_28 , & V_93 ) ;
if ( V_7 )
break;
* V_90 = ( int ) V_93 ;
return V_99 ;
default:
V_7 = - V_77 ;
break;
}
return V_7 ;
}
static int F_32 ( struct V_87 * V_88 ,
const struct V_101 * V_102 )
{
struct V_1 * V_2 = F_30 ( V_88 ) ;
unsigned int V_55 ;
for ( V_55 = 0 ; V_55 < V_2 -> V_56 ; V_55 ++ )
if ( V_2 -> V_103 [ V_55 ] . V_35 == V_102 -> args [ 0 ] )
return V_55 ;
return - V_77 ;
}
static int F_33 ( struct V_104 * V_26 ,
struct V_27 * V_28 ,
struct V_105 * V_106 )
{
const char * V_107 = V_106 -> V_107 ;
T_3 V_17 , V_85 , V_108 [ 2 ] ;
int V_7 ;
V_7 = F_34 ( V_106 , L_5 , & V_17 ) ;
if ( V_7 ) {
F_8 ( V_26 , L_6 , V_107 ) ;
return V_7 ;
}
if ( V_17 > V_109 || V_17 < V_110 ) {
F_8 ( V_26 , L_7 , V_107 , V_17 ) ;
return - V_77 ;
}
V_28 -> V_35 = V_17 ;
V_7 = F_34 ( V_106 , L_8 , & V_85 ) ;
if ( ! V_7 ) {
V_7 = F_35 ( V_85 ) ;
if ( V_7 < 0 ) {
F_8 ( V_26 , L_9 ,
V_17 , V_85 ) ;
return V_7 ;
}
V_28 -> V_29 = V_7 ;
} else {
V_28 -> V_29 = V_111 ;
}
V_7 = F_36 ( V_106 , L_10 , V_108 , 2 ) ;
if ( ! V_7 ) {
V_7 = F_23 ( V_108 [ 0 ] , V_108 [ 1 ] ) ;
if ( V_7 < 0 ) {
F_8 ( V_26 , L_11 ,
V_17 , V_108 [ 0 ] , V_108 [ 1 ] ) ;
return V_7 ;
}
V_28 -> V_98 = V_7 ;
} else {
V_28 -> V_98 = V_112 [ V_28 -> V_35 ] . V_113 ;
}
V_7 = F_34 ( V_106 , L_12 , & V_85 ) ;
if ( ! V_7 ) {
V_7 = F_25 ( V_85 ) ;
if ( V_7 < 0 ) {
F_8 ( V_26 , L_13 ,
V_17 , V_85 ) ;
return V_7 ;
}
V_28 -> V_38 = V_7 ;
} else {
V_28 -> V_38 = V_114 ;
}
V_7 = F_34 ( V_106 , L_14 , & V_85 ) ;
if ( ! V_7 ) {
V_7 = F_26 ( V_85 ) ;
if ( V_7 < 0 ) {
F_8 ( V_26 , L_15 ,
V_17 , V_85 ) ;
return V_7 ;
}
V_28 -> V_40 = V_7 ;
} else {
V_28 -> V_40 = V_115 ;
}
if ( F_37 ( V_106 , L_16 ) )
V_28 -> V_97 = V_68 ;
else
V_28 -> V_97 = V_71 ;
F_15 ( V_26 , L_17 , V_17 , V_107 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_105 * V_106 )
{
const struct V_116 * V_117 ;
struct V_89 * V_118 ;
struct V_27 V_28 ;
struct V_105 * V_119 ;
unsigned int V_120 = 0 ;
int V_7 ;
V_2 -> V_56 = F_39 ( V_106 ) ;
if ( ! V_2 -> V_56 )
return - V_77 ;
V_2 -> V_103 = F_40 ( V_2 -> V_26 , V_2 -> V_56 ,
sizeof( * V_2 -> V_103 ) , V_121 ) ;
if ( ! V_2 -> V_103 )
return - V_122 ;
V_2 -> V_57 = F_40 ( V_2 -> V_26 , V_2 -> V_56 ,
sizeof( * V_2 -> V_57 ) , V_121 ) ;
if ( ! V_2 -> V_57 )
return - V_122 ;
V_118 = V_2 -> V_103 ;
F_41 (node, child) {
V_7 = F_33 ( V_2 -> V_26 , & V_28 , V_119 ) ;
if ( V_7 ) {
F_42 ( V_119 ) ;
return V_7 ;
}
V_28 . V_96 = V_112 [ V_28 . V_35 ] . V_96 ;
V_2 -> V_57 [ V_120 ] = V_28 ;
V_117 = & V_112 [ V_28 . V_35 ] ;
V_118 -> V_35 = V_28 . V_35 ;
V_118 -> V_123 = V_117 -> V_123 ;
V_118 -> V_124 = V_117 -> V_125 ;
V_118 -> type = V_117 -> type ;
V_118 -> V_126 = 1 ;
V_118 -> V_95 = V_120 ++ ;
V_118 ++ ;
}
if ( ! F_14 ( V_2 , V_73 ) ) {
F_8 ( V_2 -> V_26 , L_18 ) ;
return - V_127 ;
}
if ( ! F_14 ( V_2 , V_76 ) ) {
F_8 ( V_2 -> V_26 , L_19 ) ;
return - V_127 ;
}
if ( ! F_14 ( V_2 , V_80 ) ) {
F_8 ( V_2 -> V_26 , L_20 ) ;
return - V_127 ;
}
if ( ! F_14 ( V_2 , V_81 ) ) {
F_8 ( V_2 -> V_26 , L_21 ) ;
return - V_127 ;
}
return 0 ;
}
static T_4 F_43 ( int V_128 , void * V_129 )
{
struct V_1 * V_2 = V_129 ;
V_62 ( & V_2 -> V_62 ) ;
return V_130 ;
}
static int F_44 ( struct V_1 * V_2 )
{
T_2 V_90 ;
int V_7 ;
V_7 = F_1 ( V_2 , V_131 , & V_90 ) ;
if ( V_7 )
return V_7 ;
if ( V_90 < V_132 ) {
F_8 ( V_2 -> V_26 , L_22 , V_90 ) ;
return - V_127 ;
}
V_7 = F_1 ( V_2 , V_133 , & V_90 ) ;
if ( V_7 )
return V_7 ;
if ( V_90 < V_134 ) {
F_8 ( V_2 -> V_26 , L_23 , V_90 ) ;
return - V_127 ;
}
V_7 = F_1 ( V_2 , V_135 , & V_90 ) ;
if ( V_7 )
return V_7 ;
if ( V_90 < V_136 ) {
F_8 ( V_2 -> V_26 , L_24 , V_90 ) ;
return - V_127 ;
}
return 0 ;
}
static int F_45 ( struct V_137 * V_138 )
{
struct V_105 * V_106 = V_138 -> V_26 . V_139 ;
struct V_104 * V_26 = & V_138 -> V_26 ;
struct V_87 * V_88 ;
struct V_1 * V_2 ;
struct V_5 * V_5 ;
int V_7 , V_140 ;
T_3 V_141 ;
V_5 = F_46 ( V_26 -> V_142 , NULL ) ;
if ( ! V_5 )
return - V_127 ;
V_7 = F_34 ( V_106 , L_5 , & V_141 ) ;
if ( V_7 < 0 )
return V_7 ;
V_88 = F_47 ( V_26 , sizeof( * V_2 ) ) ;
if ( ! V_88 )
return - V_122 ;
V_2 = F_30 ( V_88 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_26 = V_26 ;
V_2 -> V_6 = V_141 ;
V_2 -> V_143 = false ;
F_48 ( & V_2 -> V_62 ) ;
F_49 ( & V_2 -> V_59 ) ;
V_7 = F_44 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_38 ( V_2 , V_106 ) ;
if ( V_7 )
return V_7 ;
V_140 = F_50 ( V_138 , 0 ) ;
if ( V_140 < 0 ) {
if ( V_140 == - V_144 || V_140 == - V_77 )
return V_140 ;
V_2 -> V_61 = true ;
} else {
V_7 = F_51 ( V_26 , V_140 , F_43 , 0 ,
L_25 , V_2 ) ;
if ( V_7 )
return V_7 ;
}
V_7 = F_5 ( V_2 ) ;
if ( V_7 ) {
F_8 ( V_26 , L_26 ) ;
return V_7 ;
}
V_7 = F_22 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_88 -> V_26 . V_142 = V_26 ;
V_88 -> V_26 . V_139 = V_106 ;
V_88 -> V_107 = V_138 -> V_107 ;
V_88 -> V_145 = V_146 ;
V_88 -> V_147 = & V_148 ;
V_88 -> V_149 = V_2 -> V_103 ;
V_88 -> V_150 = V_2 -> V_56 ;
return F_52 ( V_26 , V_88 ) ;
}
