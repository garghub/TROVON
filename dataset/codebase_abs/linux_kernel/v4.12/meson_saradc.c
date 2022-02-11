static unsigned int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
F_3 ( V_4 -> V_6 , V_7 , & V_5 ) ;
return F_4 ( V_8 , V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 , int V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 ;
V_10 = F_6 ( ( V_11 ) V_9 * V_4 -> V_12 , V_13 ) + V_4 -> V_14 ;
return F_7 ( V_10 , 0 , ( 1 << V_4 -> V_15 -> V_16 ) - 1 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_17 = 10000 ;
do {
F_9 ( 1 ) ;
F_3 ( V_4 -> V_6 , V_7 , & V_5 ) ;
} while ( F_4 ( V_18 , V_5 ) && V_17 -- );
if ( V_17 < 0 )
return - V_19 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
const struct V_20 * V_21 ,
int * V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_22 , V_23 , V_24 ;
if( ! F_11 ( & V_4 -> V_25 ,
F_12 ( V_26 ) ) )
return - V_19 ;
V_24 = F_1 ( V_2 ) ;
if ( V_24 != 1 ) {
F_13 ( & V_2 -> V_27 ,
L_1 , V_24 ) ;
return - V_28 ;
}
F_3 ( V_4 -> V_6 , V_29 , & V_5 ) ;
V_22 = F_4 ( V_30 , V_5 ) ;
if ( V_22 != V_21 -> V_31 ) {
F_13 ( & V_2 -> V_27 ,
L_2 ,
V_22 , V_21 -> V_31 ) ;
return - V_28 ;
}
V_23 = F_4 ( V_32 , V_5 ) ;
V_23 &= F_14 ( V_4 -> V_15 -> V_16 - 1 , 0 ) ;
* V_9 = F_5 ( V_2 , V_23 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 ,
const struct V_20 * V_21 ,
enum V_33 V_34 ,
enum V_35 V_36 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_9 , V_31 = V_21 -> V_31 ;
V_9 = V_36 << F_16 ( V_31 ) ;
F_17 ( V_4 -> V_6 , V_37 ,
F_18 ( V_31 ) ,
V_9 ) ;
V_9 = V_34 << F_19 ( V_31 ) ;
F_17 ( V_4 -> V_6 , V_37 ,
F_20 ( V_31 ) , V_9 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
const struct V_20 * V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
V_5 = F_22 ( V_38 , 0 ) ;
F_17 ( V_4 -> V_6 , V_39 ,
V_38 , V_5 ) ;
V_5 = F_22 ( F_23 ( 0 ) ,
V_21 -> V_31 ) ;
F_17 ( V_4 -> V_6 , V_39 ,
F_23 ( 0 ) , V_5 ) ;
V_5 = F_22 ( V_40 ,
V_21 -> V_31 ) ;
F_17 ( V_4 -> V_6 , V_41 ,
V_40 ,
V_5 ) ;
V_5 = F_22 ( V_42 ,
V_21 -> V_31 ) ;
F_17 ( V_4 -> V_6 , V_41 ,
V_42 ,
V_5 ) ;
if ( V_21 -> V_31 == 6 )
F_17 ( V_4 -> V_6 , V_43 ,
V_44 , 0 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
enum V_45 V_46 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
V_5 = F_22 ( V_47 , V_46 ) ;
F_17 ( V_4 -> V_6 , V_48 ,
V_47 , V_5 ) ;
F_25 ( 10 , 20 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_27 ( & V_4 -> V_25 ) ;
F_17 ( V_4 -> V_6 , V_7 ,
V_49 ,
V_49 ) ;
F_17 ( V_4 -> V_6 , V_7 ,
V_50 ,
V_50 ) ;
F_17 ( V_4 -> V_6 , V_7 ,
V_51 ,
V_51 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_17 ( V_4 -> V_6 , V_7 ,
V_49 , 0 ) ;
F_17 ( V_4 -> V_6 , V_7 ,
V_52 ,
V_52 ) ;
F_8 ( V_2 ) ;
F_17 ( V_4 -> V_6 , V_7 ,
V_50 , 0 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_9 , V_17 = 10000 ;
F_30 ( & V_2 -> V_53 ) ;
F_17 ( V_4 -> V_6 , V_54 ,
V_55 ,
V_55 ) ;
do {
F_9 ( 1 ) ;
F_3 ( V_4 -> V_6 , V_54 , & V_9 ) ;
} while ( V_9 & V_56 && V_17 -- );
if ( V_17 < 0 )
return - V_19 ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_17 ( V_4 -> V_6 , V_54 ,
V_55 , 0 ) ;
F_32 ( & V_2 -> V_53 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_24 , V_10 ;
for ( V_24 = 0 ; V_24 < V_57 ; V_24 ++ ) {
if ( ! F_1 ( V_2 ) )
break;
F_3 ( V_4 -> V_6 , V_29 , & V_10 ) ;
}
}
static int F_34 ( struct V_1 * V_2 ,
const struct V_20 * V_21 ,
enum V_33 V_58 ,
enum V_35 V_59 ,
int * V_9 )
{
int V_60 ;
V_60 = F_29 ( V_2 ) ;
if ( V_60 )
return V_60 ;
F_33 ( V_2 ) ;
F_15 ( V_2 , V_21 , V_58 , V_59 ) ;
F_21 ( V_2 , V_21 ) ;
F_26 ( V_2 ) ;
V_60 = F_10 ( V_2 , V_21 , V_9 ) ;
F_28 ( V_2 ) ;
F_31 ( V_2 ) ;
if ( V_60 ) {
F_35 ( V_2 -> V_27 . V_61 ,
L_3 ,
V_21 -> V_31 , V_60 ) ;
return V_60 ;
}
return V_62 ;
}
static int F_36 ( struct V_1 * V_2 ,
const struct V_20 * V_21 ,
int * V_9 , int * V_63 , long V_64 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_60 ;
switch ( V_64 ) {
case V_65 :
return F_34 ( V_2 , V_21 , V_66 ,
V_67 , V_9 ) ;
break;
case V_68 :
return F_34 ( V_2 , V_21 ,
V_69 , V_70 ,
V_9 ) ;
break;
case V_71 :
V_60 = F_37 ( V_4 -> V_72 ) ;
if ( V_60 < 0 ) {
F_13 ( V_2 -> V_27 . V_61 ,
L_4 , V_60 ) ;
return V_60 ;
}
* V_9 = V_60 / 1000 ;
* V_63 = V_4 -> V_15 -> V_16 ;
return V_73 ;
case V_74 :
* V_9 = V_4 -> V_14 ;
return V_62 ;
case V_75 :
* V_9 = V_4 -> V_12 / V_13 ;
* V_63 = V_4 -> V_12 % V_13 ;
return V_76 ;
default:
return - V_28 ;
}
}
static int F_38 ( struct V_1 * V_2 ,
void T_2 * V_77 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_78 V_79 ;
const char * V_80 [ 1 ] ;
V_79 . V_81 = F_39 ( & V_2 -> V_27 , V_82 , L_5 ,
F_40 ( V_2 -> V_27 . V_83 ) ) ;
V_79 . V_84 = 0 ;
V_79 . V_85 = & V_86 ;
V_80 [ 0 ] = F_41 ( V_4 -> V_87 ) ;
V_79 . V_88 = V_80 ;
V_79 . V_89 = 1 ;
V_4 -> V_90 . V_91 = V_77 + V_48 ;
V_4 -> V_90 . V_92 = V_93 ;
V_4 -> V_90 . V_94 = V_95 ;
V_4 -> V_90 . V_96 . V_79 = & V_79 ;
V_4 -> V_90 . V_84 = 0 ;
V_4 -> V_97 = F_42 ( & V_2 -> V_27 ,
& V_4 -> V_90 . V_96 ) ;
if ( F_43 ( F_44 ( V_4 -> V_97 ) ) )
return F_45 ( V_4 -> V_97 ) ;
V_79 . V_81 = F_39 ( & V_2 -> V_27 , V_82 , L_6 ,
F_40 ( V_2 -> V_27 . V_83 ) ) ;
V_79 . V_84 = V_98 ;
V_79 . V_85 = & V_99 ;
V_80 [ 0 ] = F_41 ( V_4 -> V_97 ) ;
V_79 . V_88 = V_80 ;
V_79 . V_89 = 1 ;
V_4 -> V_100 . V_91 = V_77 + V_48 ;
V_4 -> V_100 . V_101 = F_46 ( V_102 ) ;
V_4 -> V_100 . V_96 . V_79 = & V_79 ;
V_4 -> V_103 = F_42 ( & V_2 -> V_27 , & V_4 -> V_100 . V_96 ) ;
if ( F_43 ( F_44 ( V_4 -> V_103 ) ) )
return F_45 ( V_4 -> V_103 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_60 ;
F_24 ( V_2 , V_104 ) ;
F_3 ( V_4 -> V_6 , V_48 , & V_5 ) ;
if ( V_5 & V_105 )
return 0 ;
F_28 ( V_2 ) ;
F_17 ( V_4 -> V_6 , V_7 ,
V_106 ,
V_106 ) ;
F_48 ( V_4 -> V_6 , V_39 , 0x0 ) ;
F_17 ( V_4 -> V_6 , V_48 ,
V_107 , 0 ) ;
F_17 ( V_4 -> V_6 , V_48 ,
V_108 ,
V_108 ) ;
F_17 ( V_4 -> V_6 , V_54 ,
V_109 ,
F_22 ( V_110 ,
10 ) ) ;
F_17 ( V_4 -> V_6 , V_54 ,
V_111 ,
F_22 ( V_111 ,
0 ) ) ;
F_17 ( V_4 -> V_6 , V_54 ,
V_109 ,
F_22 ( V_109 ,
10 ) ) ;
F_17 ( V_4 -> V_6 , V_54 ,
V_112 ,
F_22 ( V_112 ,
1 ) ) ;
V_60 = F_49 ( V_4 -> V_113 , V_4 -> V_87 ) ;
if ( V_60 ) {
F_13 ( V_2 -> V_27 . V_61 ,
L_7 ) ;
return V_60 ;
}
V_60 = F_50 ( V_4 -> V_103 , 1200000 ) ;
if ( V_60 ) {
F_13 ( V_2 -> V_27 . V_61 ,
L_8 ) ;
return V_60 ;
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_60 ;
T_1 V_5 ;
V_60 = F_29 ( V_2 ) ;
if ( V_60 )
goto V_114;
V_60 = F_52 ( V_4 -> V_72 ) ;
if ( V_60 < 0 ) {
F_13 ( V_2 -> V_27 . V_61 ,
L_9 ) ;
goto V_115;
}
V_60 = F_53 ( V_4 -> V_116 ) ;
if ( V_60 ) {
F_13 ( V_2 -> V_27 . V_61 , L_10 ) ;
goto V_117;
}
V_60 = F_53 ( V_4 -> V_118 ) ;
if ( V_60 ) {
F_13 ( V_2 -> V_27 . V_61 , L_11 ) ;
goto V_119;
}
V_5 = F_22 ( V_120 , 1 ) ;
F_17 ( V_4 -> V_6 , V_7 ,
V_120 , V_5 ) ;
F_17 ( V_4 -> V_6 , V_121 ,
V_122 ,
V_122 ) ;
F_17 ( V_4 -> V_6 , V_48 ,
V_123 ,
V_123 ) ;
F_9 ( 5 ) ;
V_60 = F_53 ( V_4 -> V_103 ) ;
if ( V_60 ) {
F_13 ( V_2 -> V_27 . V_61 , L_12 ) ;
goto V_124;
}
F_31 ( V_2 ) ;
return 0 ;
V_124:
F_17 ( V_4 -> V_6 , V_48 ,
V_123 , 0 ) ;
F_17 ( V_4 -> V_6 , V_121 ,
V_122 , 0 ) ;
F_54 ( V_4 -> V_118 ) ;
V_119:
F_54 ( V_4 -> V_116 ) ;
V_117:
F_55 ( V_4 -> V_72 ) ;
V_115:
F_31 ( V_2 ) ;
V_114:
return V_60 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_60 ;
V_60 = F_29 ( V_2 ) ;
if ( V_60 )
return V_60 ;
F_54 ( V_4 -> V_103 ) ;
F_17 ( V_4 -> V_6 , V_48 ,
V_123 , 0 ) ;
F_17 ( V_4 -> V_6 , V_121 ,
V_122 , 0 ) ;
F_54 ( V_4 -> V_118 ) ;
F_54 ( V_4 -> V_116 ) ;
F_55 ( V_4 -> V_72 ) ;
F_31 ( V_2 ) ;
return 0 ;
}
static T_3 F_57 ( int V_125 , void * V_15 )
{
struct V_1 * V_2 = V_15 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_126 , V_127 ;
T_1 V_5 ;
F_3 ( V_4 -> V_6 , V_7 , & V_5 ) ;
V_126 = F_4 ( V_8 , V_5 ) ;
V_127 = F_4 ( V_120 , V_5 ) ;
if ( V_126 < V_127 )
return V_128 ;
F_58 ( & V_4 -> V_25 ) ;
return V_129 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_60 , V_130 , V_131 , V_132 , V_133 ;
V_130 = ( 1 << V_4 -> V_15 -> V_16 ) / 4 ;
V_131 = ( 1 << V_4 -> V_15 -> V_16 ) * 3 / 4 ;
F_24 ( V_2 , V_134 ) ;
F_25 ( 10 , 20 ) ;
V_60 = F_34 ( V_2 ,
& V_135 [ 7 ] ,
V_69 , V_70 , & V_132 ) ;
if ( V_60 < 0 )
goto V_136;
F_24 ( V_2 , V_137 ) ;
F_25 ( 10 , 20 ) ;
V_60 = F_34 ( V_2 ,
& V_135 [ 7 ] ,
V_69 , V_70 , & V_133 ) ;
if ( V_60 < 0 )
goto V_136;
if ( V_133 <= V_132 ) {
V_60 = - V_28 ;
goto V_136;
}
V_4 -> V_12 = F_6 ( ( V_131 - V_130 ) * ( V_11 ) V_13 ,
V_133 - V_132 ) ;
V_4 -> V_14 = V_130 - F_6 ( ( V_11 ) V_132 * V_4 -> V_12 ,
V_13 ) ;
V_60 = 0 ;
V_136:
F_24 ( V_2 , V_104 ) ;
return V_60 ;
}
static int F_60 ( struct V_138 * V_139 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_140 * V_141 ;
void T_2 * V_77 ;
const struct V_142 * V_143 ;
int V_125 , V_60 ;
V_2 = F_61 ( & V_139 -> V_27 , sizeof( * V_4 ) ) ;
if ( ! V_2 ) {
F_13 ( & V_139 -> V_27 , L_13 ) ;
return - V_144 ;
}
V_4 = F_2 ( V_2 ) ;
F_62 ( & V_4 -> V_25 ) ;
V_143 = F_63 ( V_145 , & V_139 -> V_27 ) ;
V_4 -> V_15 = V_143 -> V_15 ;
V_2 -> V_81 = V_4 -> V_15 -> V_81 ;
V_2 -> V_27 . V_61 = & V_139 -> V_27 ;
V_2 -> V_27 . V_83 = V_139 -> V_27 . V_83 ;
V_2 -> V_146 = V_147 ;
V_2 -> V_148 = & V_149 ;
V_2 -> V_150 = V_135 ;
V_2 -> V_151 = F_64 ( V_135 ) ;
V_141 = F_65 ( V_139 , V_152 , 0 ) ;
V_77 = F_66 ( & V_139 -> V_27 , V_141 ) ;
if ( F_44 ( V_77 ) )
return F_45 ( V_77 ) ;
V_125 = F_67 ( V_139 -> V_27 . V_83 , 0 ) ;
if ( ! V_125 )
return - V_28 ;
V_60 = F_68 ( & V_139 -> V_27 , V_125 , F_57 , V_153 ,
F_69 ( & V_139 -> V_27 ) , V_2 ) ;
if ( V_60 )
return V_60 ;
V_4 -> V_6 = F_70 ( & V_139 -> V_27 , V_77 ,
& V_154 ) ;
if ( F_44 ( V_4 -> V_6 ) )
return F_45 ( V_4 -> V_6 ) ;
V_4 -> V_87 = F_71 ( & V_139 -> V_27 , L_14 ) ;
if ( F_44 ( V_4 -> V_87 ) ) {
F_13 ( & V_139 -> V_27 , L_15 ) ;
return F_45 ( V_4 -> V_87 ) ;
}
V_4 -> V_116 = F_71 ( & V_139 -> V_27 , L_16 ) ;
if ( F_44 ( V_4 -> V_116 ) ) {
F_13 ( & V_139 -> V_27 , L_17 ) ;
return F_45 ( V_4 -> V_116 ) ;
}
V_4 -> V_118 = F_71 ( & V_139 -> V_27 , L_18 ) ;
if ( F_44 ( V_4 -> V_118 ) ) {
if ( F_45 ( V_4 -> V_118 ) == - V_155 ) {
V_4 -> V_118 = NULL ;
} else {
F_13 ( & V_139 -> V_27 , L_19 ) ;
return F_45 ( V_4 -> V_118 ) ;
}
}
V_4 -> V_103 = F_71 ( & V_139 -> V_27 , L_20 ) ;
if ( F_44 ( V_4 -> V_103 ) ) {
if ( F_45 ( V_4 -> V_103 ) == - V_155 ) {
V_4 -> V_103 = NULL ;
} else {
F_13 ( & V_139 -> V_27 , L_21 ) ;
return F_45 ( V_4 -> V_103 ) ;
}
}
V_4 -> V_113 = F_71 ( & V_139 -> V_27 , L_22 ) ;
if ( F_44 ( V_4 -> V_113 ) ) {
if ( F_45 ( V_4 -> V_113 ) == - V_155 ) {
V_4 -> V_113 = NULL ;
} else {
F_13 ( & V_139 -> V_27 , L_23 ) ;
return F_45 ( V_4 -> V_113 ) ;
}
}
if ( ! V_4 -> V_103 ) {
V_60 = F_38 ( V_2 , V_77 ) ;
if ( V_60 )
return V_60 ;
}
V_4 -> V_72 = F_72 ( & V_139 -> V_27 , L_24 ) ;
if ( F_44 ( V_4 -> V_72 ) ) {
F_13 ( & V_139 -> V_27 , L_25 ) ;
return F_45 ( V_4 -> V_72 ) ;
}
V_4 -> V_12 = V_13 ;
V_60 = F_47 ( V_2 ) ;
if ( V_60 )
goto V_156;
V_60 = F_51 ( V_2 ) ;
if ( V_60 )
goto V_156;
V_60 = F_59 ( V_2 ) ;
if ( V_60 )
F_35 ( & V_139 -> V_27 , L_26 ) ;
F_73 ( V_139 , V_2 ) ;
V_60 = F_74 ( V_2 ) ;
if ( V_60 )
goto V_157;
return 0 ;
V_157:
F_56 ( V_2 ) ;
V_156:
return V_60 ;
}
static int F_75 ( struct V_138 * V_139 )
{
struct V_1 * V_2 = F_76 ( V_139 ) ;
F_77 ( V_2 ) ;
return F_56 ( V_2 ) ;
}
static int T_4 F_78 ( struct V_158 * V_27 )
{
struct V_1 * V_2 = F_79 ( V_27 ) ;
return F_56 ( V_2 ) ;
}
static int T_4 F_80 ( struct V_158 * V_27 )
{
struct V_1 * V_2 = F_79 ( V_27 ) ;
return F_51 ( V_2 ) ;
}
