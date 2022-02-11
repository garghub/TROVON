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
if ( V_4 -> V_15 -> V_54 ) {
F_17 ( V_4 -> V_6 , V_55 ,
V_56 ,
V_56 ) ;
do {
F_9 ( 1 ) ;
F_3 ( V_4 -> V_6 , V_55 , & V_9 ) ;
} while ( V_9 & V_57 && V_17 -- );
if ( V_17 < 0 )
return - V_19 ;
}
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_15 -> V_54 )
F_17 ( V_4 -> V_6 , V_55 ,
V_56 , 0 ) ;
F_32 ( & V_2 -> V_53 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_24 , V_10 ;
for ( V_24 = 0 ; V_24 < V_58 ; V_24 ++ ) {
if ( ! F_1 ( V_2 ) )
break;
F_3 ( V_4 -> V_6 , V_29 , & V_10 ) ;
}
}
static int F_34 ( struct V_1 * V_2 ,
const struct V_20 * V_21 ,
enum V_33 V_59 ,
enum V_35 V_60 ,
int * V_9 )
{
int V_61 ;
V_61 = F_29 ( V_2 ) ;
if ( V_61 )
return V_61 ;
F_33 ( V_2 ) ;
F_15 ( V_2 , V_21 , V_59 , V_60 ) ;
F_21 ( V_2 , V_21 ) ;
F_26 ( V_2 ) ;
V_61 = F_10 ( V_2 , V_21 , V_9 ) ;
F_28 ( V_2 ) ;
F_31 ( V_2 ) ;
if ( V_61 ) {
F_35 ( V_2 -> V_27 . V_62 ,
L_3 ,
V_21 -> V_31 , V_61 ) ;
return V_61 ;
}
return V_63 ;
}
static int F_36 ( struct V_1 * V_2 ,
const struct V_20 * V_21 ,
int * V_9 , int * V_64 , long V_65 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_61 ;
switch ( V_65 ) {
case V_66 :
return F_34 ( V_2 , V_21 , V_67 ,
V_68 , V_9 ) ;
break;
case V_69 :
return F_34 ( V_2 , V_21 ,
V_70 , V_71 ,
V_9 ) ;
break;
case V_72 :
V_61 = F_37 ( V_4 -> V_73 ) ;
if ( V_61 < 0 ) {
F_13 ( V_2 -> V_27 . V_62 ,
L_4 , V_61 ) ;
return V_61 ;
}
* V_9 = V_61 / 1000 ;
* V_64 = V_4 -> V_15 -> V_16 ;
return V_74 ;
case V_75 :
* V_9 = V_4 -> V_14 ;
return V_63 ;
case V_76 :
* V_9 = V_4 -> V_12 / V_13 ;
* V_64 = V_4 -> V_12 % V_13 ;
return V_77 ;
default:
return - V_28 ;
}
}
static int F_38 ( struct V_1 * V_2 ,
void T_2 * V_78 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_79 V_80 ;
const char * V_81 [ 1 ] ;
V_80 . V_82 = F_39 ( & V_2 -> V_27 , V_83 , L_5 ,
V_2 -> V_27 . V_84 ) ;
V_80 . V_85 = 0 ;
V_80 . V_86 = & V_87 ;
V_81 [ 0 ] = F_40 ( V_4 -> V_88 ) ;
V_80 . V_89 = V_81 ;
V_80 . V_90 = 1 ;
V_4 -> V_91 . V_92 = V_78 + V_48 ;
V_4 -> V_91 . V_93 = V_94 ;
V_4 -> V_91 . V_95 = V_96 ;
V_4 -> V_91 . V_97 . V_80 = & V_80 ;
V_4 -> V_91 . V_85 = 0 ;
V_4 -> V_98 = F_41 ( & V_2 -> V_27 ,
& V_4 -> V_91 . V_97 ) ;
if ( F_42 ( F_43 ( V_4 -> V_98 ) ) )
return F_44 ( V_4 -> V_98 ) ;
V_80 . V_82 = F_39 ( & V_2 -> V_27 , V_83 , L_6 ,
V_2 -> V_27 . V_84 ) ;
V_80 . V_85 = V_99 ;
V_80 . V_86 = & V_100 ;
V_81 [ 0 ] = F_40 ( V_4 -> V_98 ) ;
V_80 . V_89 = V_81 ;
V_80 . V_90 = 1 ;
V_4 -> V_101 . V_92 = V_78 + V_48 ;
V_4 -> V_101 . V_102 = F_45 ( V_103 ) ;
V_4 -> V_101 . V_97 . V_80 = & V_80 ;
V_4 -> V_104 = F_41 ( & V_2 -> V_27 , & V_4 -> V_101 . V_97 ) ;
if ( F_42 ( F_43 ( V_4 -> V_104 ) ) )
return F_44 ( V_4 -> V_104 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_61 ;
F_24 ( V_2 , V_105 ) ;
if ( V_4 -> V_15 -> V_54 ) {
F_3 ( V_4 -> V_6 , V_48 , & V_5 ) ;
if ( V_5 & V_106 )
return 0 ;
}
F_28 ( V_2 ) ;
F_17 ( V_4 -> V_6 , V_7 ,
V_107 ,
V_107 ) ;
F_47 ( V_4 -> V_6 , V_39 , 0x0 ) ;
F_17 ( V_4 -> V_6 , V_48 ,
V_108 , 0 ) ;
F_17 ( V_4 -> V_6 , V_48 ,
V_109 ,
V_109 ) ;
F_17 ( V_4 -> V_6 , V_55 ,
V_110 ,
F_22 ( V_111 ,
10 ) ) ;
F_17 ( V_4 -> V_6 , V_55 ,
V_112 ,
F_22 ( V_112 ,
0 ) ) ;
F_17 ( V_4 -> V_6 , V_55 ,
V_110 ,
F_22 ( V_110 ,
10 ) ) ;
F_17 ( V_4 -> V_6 , V_55 ,
V_113 ,
F_22 ( V_113 ,
1 ) ) ;
V_61 = F_48 ( V_4 -> V_114 , V_4 -> V_88 ) ;
if ( V_61 ) {
F_13 ( V_2 -> V_27 . V_62 ,
L_7 ) ;
return V_61 ;
}
V_61 = F_49 ( V_4 -> V_104 , 1200000 ) ;
if ( V_61 ) {
F_13 ( V_2 -> V_27 . V_62 ,
L_8 ) ;
return V_61 ;
}
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_61 ;
T_1 V_5 ;
V_61 = F_29 ( V_2 ) ;
if ( V_61 )
goto V_115;
V_61 = F_51 ( V_4 -> V_73 ) ;
if ( V_61 < 0 ) {
F_13 ( V_2 -> V_27 . V_62 ,
L_9 ) ;
goto V_116;
}
V_61 = F_52 ( V_4 -> V_117 ) ;
if ( V_61 ) {
F_13 ( V_2 -> V_27 . V_62 , L_10 ) ;
goto V_118;
}
V_61 = F_52 ( V_4 -> V_119 ) ;
if ( V_61 ) {
F_13 ( V_2 -> V_27 . V_62 , L_11 ) ;
goto V_120;
}
V_5 = F_22 ( V_121 , 1 ) ;
F_17 ( V_4 -> V_6 , V_7 ,
V_121 , V_5 ) ;
F_17 ( V_4 -> V_6 , V_122 ,
V_123 ,
V_123 ) ;
F_17 ( V_4 -> V_6 , V_48 ,
V_124 ,
V_124 ) ;
F_9 ( 5 ) ;
V_61 = F_52 ( V_4 -> V_104 ) ;
if ( V_61 ) {
F_13 ( V_2 -> V_27 . V_62 , L_12 ) ;
goto V_125;
}
F_31 ( V_2 ) ;
return 0 ;
V_125:
F_17 ( V_4 -> V_6 , V_48 ,
V_124 , 0 ) ;
F_17 ( V_4 -> V_6 , V_122 ,
V_123 , 0 ) ;
F_53 ( V_4 -> V_119 ) ;
V_120:
F_53 ( V_4 -> V_117 ) ;
V_118:
F_54 ( V_4 -> V_73 ) ;
V_116:
F_31 ( V_2 ) ;
V_115:
return V_61 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_61 ;
V_61 = F_29 ( V_2 ) ;
if ( V_61 )
return V_61 ;
F_53 ( V_4 -> V_104 ) ;
F_17 ( V_4 -> V_6 , V_48 ,
V_124 , 0 ) ;
F_17 ( V_4 -> V_6 , V_122 ,
V_123 , 0 ) ;
F_53 ( V_4 -> V_119 ) ;
F_53 ( V_4 -> V_117 ) ;
F_54 ( V_4 -> V_73 ) ;
F_31 ( V_2 ) ;
return 0 ;
}
static T_3 F_56 ( int V_126 , void * V_15 )
{
struct V_1 * V_2 = V_15 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_127 , V_128 ;
T_1 V_5 ;
F_3 ( V_4 -> V_6 , V_7 , & V_5 ) ;
V_127 = F_4 ( V_8 , V_5 ) ;
V_128 = F_4 ( V_121 , V_5 ) ;
if ( V_127 < V_128 )
return V_129 ;
F_57 ( & V_4 -> V_25 ) ;
return V_130 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_61 , V_131 , V_132 , V_133 , V_134 ;
V_131 = ( 1 << V_4 -> V_15 -> V_16 ) / 4 ;
V_132 = ( 1 << V_4 -> V_15 -> V_16 ) * 3 / 4 ;
F_24 ( V_2 , V_135 ) ;
F_25 ( 10 , 20 ) ;
V_61 = F_34 ( V_2 ,
& V_136 [ 7 ] ,
V_70 , V_71 , & V_133 ) ;
if ( V_61 < 0 )
goto V_137;
F_24 ( V_2 , V_138 ) ;
F_25 ( 10 , 20 ) ;
V_61 = F_34 ( V_2 ,
& V_136 [ 7 ] ,
V_70 , V_71 , & V_134 ) ;
if ( V_61 < 0 )
goto V_137;
if ( V_134 <= V_133 ) {
V_61 = - V_28 ;
goto V_137;
}
V_4 -> V_12 = F_6 ( ( V_132 - V_131 ) * ( V_11 ) V_13 ,
V_134 - V_133 ) ;
V_4 -> V_14 = V_131 - F_6 ( ( V_11 ) V_133 * V_4 -> V_12 ,
V_13 ) ;
V_61 = 0 ;
V_137:
F_24 ( V_2 , V_105 ) ;
return V_61 ;
}
static int F_59 ( struct V_139 * V_140 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_141 * V_142 ;
void T_2 * V_78 ;
const struct V_143 * V_144 ;
int V_126 , V_61 ;
V_2 = F_60 ( & V_140 -> V_27 , sizeof( * V_4 ) ) ;
if ( ! V_2 ) {
F_13 ( & V_140 -> V_27 , L_13 ) ;
return - V_145 ;
}
V_4 = F_2 ( V_2 ) ;
F_61 ( & V_4 -> V_25 ) ;
V_144 = F_62 ( V_146 , & V_140 -> V_27 ) ;
if ( ! V_144 ) {
F_13 ( & V_140 -> V_27 , L_14 ) ;
return - V_147 ;
}
V_4 -> V_15 = V_144 -> V_15 ;
V_2 -> V_82 = V_4 -> V_15 -> V_82 ;
V_2 -> V_27 . V_62 = & V_140 -> V_27 ;
V_2 -> V_27 . V_84 = V_140 -> V_27 . V_84 ;
V_2 -> V_148 = V_149 ;
V_2 -> V_150 = & V_151 ;
V_2 -> V_152 = V_136 ;
V_2 -> V_153 = F_63 ( V_136 ) ;
V_142 = F_64 ( V_140 , V_154 , 0 ) ;
V_78 = F_65 ( & V_140 -> V_27 , V_142 ) ;
if ( F_43 ( V_78 ) )
return F_44 ( V_78 ) ;
V_126 = F_66 ( V_140 -> V_27 . V_84 , 0 ) ;
if ( ! V_126 )
return - V_28 ;
V_61 = F_67 ( & V_140 -> V_27 , V_126 , F_56 , V_155 ,
F_68 ( & V_140 -> V_27 ) , V_2 ) ;
if ( V_61 )
return V_61 ;
V_4 -> V_6 = F_69 ( & V_140 -> V_27 , V_78 ,
& V_156 ) ;
if ( F_43 ( V_4 -> V_6 ) )
return F_44 ( V_4 -> V_6 ) ;
V_4 -> V_88 = F_70 ( & V_140 -> V_27 , L_15 ) ;
if ( F_43 ( V_4 -> V_88 ) ) {
F_13 ( & V_140 -> V_27 , L_16 ) ;
return F_44 ( V_4 -> V_88 ) ;
}
V_4 -> V_117 = F_70 ( & V_140 -> V_27 , L_17 ) ;
if ( F_43 ( V_4 -> V_117 ) ) {
F_13 ( & V_140 -> V_27 , L_18 ) ;
return F_44 ( V_4 -> V_117 ) ;
}
V_4 -> V_119 = F_70 ( & V_140 -> V_27 , L_19 ) ;
if ( F_43 ( V_4 -> V_119 ) ) {
if ( F_44 ( V_4 -> V_119 ) == - V_157 ) {
V_4 -> V_119 = NULL ;
} else {
F_13 ( & V_140 -> V_27 , L_20 ) ;
return F_44 ( V_4 -> V_119 ) ;
}
}
V_4 -> V_104 = F_70 ( & V_140 -> V_27 , L_21 ) ;
if ( F_43 ( V_4 -> V_104 ) ) {
if ( F_44 ( V_4 -> V_104 ) == - V_157 ) {
V_4 -> V_104 = NULL ;
} else {
F_13 ( & V_140 -> V_27 , L_22 ) ;
return F_44 ( V_4 -> V_104 ) ;
}
}
V_4 -> V_114 = F_70 ( & V_140 -> V_27 , L_23 ) ;
if ( F_43 ( V_4 -> V_114 ) ) {
if ( F_44 ( V_4 -> V_114 ) == - V_157 ) {
V_4 -> V_114 = NULL ;
} else {
F_13 ( & V_140 -> V_27 , L_24 ) ;
return F_44 ( V_4 -> V_114 ) ;
}
}
if ( ! V_4 -> V_104 ) {
V_61 = F_38 ( V_2 , V_78 ) ;
if ( V_61 )
return V_61 ;
}
V_4 -> V_73 = F_71 ( & V_140 -> V_27 , L_25 ) ;
if ( F_43 ( V_4 -> V_73 ) ) {
F_13 ( & V_140 -> V_27 , L_26 ) ;
return F_44 ( V_4 -> V_73 ) ;
}
V_4 -> V_12 = V_13 ;
V_61 = F_46 ( V_2 ) ;
if ( V_61 )
goto V_158;
V_61 = F_50 ( V_2 ) ;
if ( V_61 )
goto V_158;
V_61 = F_58 ( V_2 ) ;
if ( V_61 )
F_35 ( & V_140 -> V_27 , L_27 ) ;
F_72 ( V_140 , V_2 ) ;
V_61 = F_73 ( V_2 ) ;
if ( V_61 )
goto V_159;
return 0 ;
V_159:
F_55 ( V_2 ) ;
V_158:
return V_61 ;
}
static int F_74 ( struct V_139 * V_140 )
{
struct V_1 * V_2 = F_75 ( V_140 ) ;
F_76 ( V_2 ) ;
return F_55 ( V_2 ) ;
}
static int T_4 F_77 ( struct V_160 * V_27 )
{
struct V_1 * V_2 = F_78 ( V_27 ) ;
return F_55 ( V_2 ) ;
}
static int T_4 F_79 ( struct V_160 * V_27 )
{
struct V_1 * V_2 = F_78 ( V_27 ) ;
return F_50 ( V_2 ) ;
}
