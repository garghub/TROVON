int F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( ! V_2 ) )
return - V_3 ;
if ( ! F_3 ( V_2 -> V_2 -> V_4 -> V_5 ) )
return - V_6 ;
F_4 ( & V_7 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_2 , L_1 , V_8 -> V_9 ) ;
F_6 ( V_2 -> V_2 -> V_4 -> V_5 ) ;
F_7 ( & V_7 ) ;
return - V_10 ;
}
F_8 ( V_2 -> V_2 , L_2 , V_2 -> V_9 ) ;
V_8 = V_2 ;
F_7 ( & V_7 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
if ( F_2 ( ! V_2 ) )
return - V_3 ;
if ( V_2 != V_8 )
return - V_3 ;
F_4 ( & V_7 ) ;
if ( ! V_8 ) {
F_7 ( & V_7 ) ;
return - V_11 ;
}
F_6 ( V_8 -> V_2 -> V_4 -> V_5 ) ;
F_8 ( V_2 -> V_2 , L_3 , V_8 -> V_9 ) ;
V_8 = NULL ;
F_7 ( & V_7 ) ;
return 0 ;
}
static int F_10 ( struct V_12 * V_13 , int V_14 , int V_15 )
{
return F_11 ( V_13 , V_15 , V_14 ) ;
}
void F_12 ( struct V_16 * V_15 ,
int V_17 )
{
unsigned long V_18 ;
F_13 ( & V_15 -> V_19 , V_18 ) ;
V_15 -> V_20 = V_17 ;
F_14 ( & V_15 -> V_19 , V_18 ) ;
}
static inline int F_15 ( struct V_16 * V_15 )
{
int V_17 ;
unsigned long V_18 ;
F_13 ( & V_15 -> V_19 , V_18 ) ;
V_17 = V_15 -> V_20 ;
F_14 ( & V_15 -> V_19 , V_18 ) ;
return V_17 ;
}
static void F_16 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
unsigned int V_25 ;
T_1 V_26 ;
T_2 V_27 ;
T_2 V_28 = F_17 ( V_22 ) ;
T_3 V_29 = F_18 ( V_22 -> V_30 . V_31 ) ;
V_25 = V_22 -> V_32 -> V_25 ;
V_26 = V_22 -> V_32 -> V_26 ;
V_27 = F_19 ( V_22 -> V_32 , V_26 ) ;
V_24 -> V_33 [ 0 ] . V_34 = V_29 ;
V_24 -> V_33 [ 0 ] . V_35 = V_28 ;
V_24 -> V_36 = 1 ;
V_24 -> V_37 = 0 ;
V_24 -> V_38 = V_27 * V_25 ;
}
static void F_20 ( struct V_21 * V_22 ,
struct V_39 * V_40 )
{
V_40 -> V_41 . V_42 . V_43 = ( V_44 ) V_22 -> V_32 -> V_25 ;
V_40 -> V_41 . V_42 . V_45 = V_22 -> V_32 -> V_46 ;
V_40 -> V_41 . V_42 . V_47 = V_22 -> V_32 -> V_48 ;
V_40 -> V_41 . V_42 . V_49 = 0 ;
V_40 -> V_41 . V_42 . V_50 = 0 ;
memset ( V_40 -> V_41 . V_42 . V_51 , 0 , sizeof( V_44 ) ) ;
}
static int F_21 ( int V_2 , int V_52 , int V_53 ,
struct V_54 * V_55 , int V_35 )
{
int V_56 ;
if ( V_55 == NULL )
return - V_3 ;
for ( V_56 = 1 ; V_56 < V_35 ; V_56 ++ ) {
if ( ( V_55 [ V_56 ] . V_57 == V_2 ) && ( V_55 [ V_56 ] . V_58 == V_53 ) )
return V_56 ;
}
return 0 ;
}
int F_22 ( void * V_22 ,
const struct V_59 * V_60 , struct V_61 * V_62 , bool V_63 )
{
int V_64 ;
int V_65 ;
struct V_54 * V_55 ;
struct V_21 * V_66 = NULL ;
struct V_67 * V_68 = NULL ;
V_55 = V_60 -> V_69 -> V_70 ;
V_64 = V_60 -> V_69 -> V_71 ;
if ( V_63 == true )
V_68 = (struct V_67 * ) V_22 ;
else
V_66 = (struct V_21 * ) V_22 ;
V_62 -> V_72 = V_73 ;
if ( V_66 ) {
V_65 = F_21 ( V_66 -> V_74 -> V_75 ,
V_66 -> V_76 , V_66 -> V_15 ,
V_55 , V_64 ) ;
if ( V_65 <= 0 )
return - V_3 ;
V_62 -> V_77 = V_65 ;
V_62 -> V_78 = V_55 [ V_65 ] . V_79 ;
V_62 -> V_80 = V_55 [ V_65 ] . V_81 ;
V_62 -> V_82 = ( V_44 ) V_66 -> V_15 ;
}
if ( V_68 ) {
V_65 = F_21 ( V_68 -> V_75 -> V_75 ,
0 , V_68 -> V_58 ,
V_55 , V_64 ) ;
if ( V_65 <= 0 )
return - V_3 ;
V_62 -> V_77 = V_65 ;
V_62 -> V_78 = V_55 [ V_65 ] . V_79 ;
V_62 -> V_80 = V_55 [ V_65 ] . V_81 ;
V_62 -> V_82 = ( V_44 ) V_68 -> V_58 ;
}
return 0 ;
}
static int F_23 ( struct V_21 * V_22 ,
struct V_12 * V_13 )
{
struct V_16 * V_15 =
V_22 -> V_32 -> V_83 ;
struct V_39 V_40 = { { { 0 ,} ,} ,} ;
struct V_61 V_62 = { 0 } ;
struct V_23 V_84 = { 0 } ;
int V_85 = 0 ;
struct V_59 * V_60 = F_24 ( V_13 ) ;
F_20 ( V_22 , & V_40 ) ;
F_16 ( V_22 , & V_84 ) ;
V_22 -> V_32 -> V_86 = V_22 -> V_30 . V_31 ;
V_62 . V_87 = V_40 ;
V_62 . V_88 = V_84 ;
V_62 . V_89 = V_90 ;
V_85 = F_22 ( V_22 , V_60 , & V_62 , false ) ;
if ( V_85 < 0 )
return V_85 ;
V_15 -> V_91 . V_92 = V_62 . V_77 ;
V_85 = V_15 -> V_82 -> V_93 ( V_8 -> V_2 , & V_62 ) ;
if ( V_85 <= 0 )
return V_85 ;
return V_85 ;
}
static void F_25 ( void * V_94 )
{
struct V_21 * V_22 = V_94 ;
struct V_16 * V_15 ;
int V_95 ;
if ( ! V_22 || ! V_22 -> V_32 )
return;
V_15 = V_22 -> V_32 -> V_83 ;
if ( ! V_15 )
return;
V_95 = F_15 ( V_15 ) ;
if ( V_95 != V_96 )
return;
F_26 ( V_22 ) ;
}
static int F_27 ( struct V_21 * V_22 )
{
struct V_16 * V_15 =
V_22 -> V_32 -> V_83 ;
struct V_97 * V_98 = V_22 -> V_83 ;
int V_85 ;
F_8 ( V_98 -> V_2 , L_4 ) ;
F_12 ( V_15 , V_99 ) ;
V_15 -> V_91 . V_100 = F_25 ;
V_15 -> V_91 . V_94 = V_22 ;
V_15 -> V_91 . V_101 = 0 ;
V_15 -> V_91 . V_47 = V_22 -> V_32 -> V_48 ;
V_85 = V_15 -> V_82 -> V_102 ( V_8 -> V_2 , & V_15 -> V_91 ) ;
if ( V_85 )
F_5 ( V_98 -> V_2 , L_5 , V_85 ) ;
return V_85 ;
}
static int F_28 ( struct V_16 * V_15 )
{
return V_15 -> V_82 -> V_103 ( V_8 -> V_2 , true ) ;
}
static void F_29 ( struct V_16 * V_15 )
{
V_15 -> V_82 -> V_103 ( V_8 -> V_2 , false ) ;
}
static int F_30 ( struct V_21 * V_22 ,
struct V_12 * V_13 )
{
int V_85 = 0 ;
struct V_104 * V_32 = V_22 -> V_32 ;
struct V_16 * V_15 ;
V_15 = F_31 ( sizeof( * V_15 ) , V_105 ) ;
if ( ! V_15 )
return - V_106 ;
F_32 ( & V_15 -> V_19 ) ;
F_4 ( & V_7 ) ;
if ( ! V_8 ||
! F_3 ( V_8 -> V_2 -> V_4 -> V_5 ) ) {
F_5 ( V_13 -> V_2 , L_6 ) ;
V_85 = - V_6 ;
goto V_107;
}
V_15 -> V_82 = V_8 -> V_82 ;
F_7 ( & V_7 ) ;
V_15 -> V_91 . V_92 = 0 ;
V_15 -> V_91 . V_94 = V_22 ;
V_32 -> V_83 = V_15 ;
V_85 = F_28 ( V_15 ) ;
if ( V_85 < 0 )
return V_85 ;
F_33 ( V_22 -> V_32 , 0 ,
V_108 , 2 ) ;
return F_34 ( V_32 ,
V_108 ) ;
V_107:
F_35 ( V_15 ) ;
F_7 ( & V_7 ) ;
return V_85 ;
}
static void F_36 ( struct V_21 * V_22 ,
struct V_12 * V_13 )
{
struct V_16 * V_15 ;
int V_85 = 0 , V_92 ;
V_15 = V_22 -> V_32 -> V_83 ;
F_29 ( V_15 ) ;
V_92 = V_15 -> V_91 . V_92 ;
if ( V_92 )
V_85 = V_15 -> V_82 -> V_109 ( V_8 -> V_2 , V_92 ) ;
F_6 ( V_8 -> V_2 -> V_4 -> V_5 ) ;
F_35 ( V_15 ) ;
}
static int F_37 ( struct V_21 * V_22 ,
struct V_12 * V_13 )
{
struct V_16 * V_15 ;
int V_85 = 0 , V_92 ;
V_15 = V_22 -> V_32 -> V_83 ;
V_92 = V_15 -> V_91 . V_92 ;
if ( V_15 -> V_91 . V_92 ) {
V_85 = V_15 -> V_82 -> V_110 ( V_8 -> V_2 , V_92 ) ;
return V_85 ;
}
V_85 = F_23 ( V_22 , V_13 ) ;
if ( V_85 <= 0 )
return V_85 ;
snprintf ( V_22 -> V_74 -> V_111 , sizeof( V_22 -> V_74 -> V_111 ) ,
L_7 , V_15 -> V_91 . V_92 ) ;
V_85 = F_27 ( V_22 ) ;
if ( V_85 )
return V_85 ;
V_22 -> V_32 -> V_112 . V_113 = V_114 ;
return V_85 ;
}
static int F_38 ( struct V_21 * V_22 ,
struct V_115 * V_116 ,
struct V_12 * V_13 )
{
F_39 ( V_22 , F_40 ( V_116 ) ) ;
memset ( V_22 -> V_32 -> V_86 , 0 , F_40 ( V_116 ) ) ;
return 0 ;
}
static int F_41 ( struct V_21 * V_22 ,
struct V_12 * V_13 )
{
return F_42 ( V_22 ) ;
}
static int F_43 ( struct V_21 * V_22 ,
struct V_12 * V_13 )
{
int V_117 = 0 ;
if ( ! V_13 -> V_118 ) {
V_117 = F_44 ( V_13 , true ) ;
F_45 ( V_13 ) ;
}
return V_117 ;
}
static int F_46 ( struct V_21 * V_22 ,
struct V_115 * V_116 ,
struct V_12 * V_13 )
{
int V_117 = 0 ;
if ( V_13 -> V_118 == 1 )
V_117 = F_47 ( V_13 , V_13 -> V_9 , 1 ) ;
return V_117 ;
}
static int F_48 ( struct V_12 * V_13 , unsigned int V_119 )
{
int V_117 = 0 ;
if ( ! V_13 -> V_118 )
return 0 ;
V_117 = F_49 ( V_13 , V_119 ) ;
if ( V_117 < 0 )
F_5 ( V_13 -> V_2 , L_8 ) ;
return V_117 ;
}
static int F_50 ( struct V_12 * V_13 ,
unsigned int V_120 , unsigned int V_121 ,
int V_122 , int V_123 ) {
int V_117 = 0 ;
if ( ! V_13 -> V_118 )
return V_117 ;
V_117 = F_51 ( V_13 , V_120 , V_121 , V_122 , V_123 ) ;
if ( V_117 < 0 )
F_5 ( V_13 -> V_2 , L_9 , V_117 ) ;
return V_117 ;
}
static void F_52 ( struct V_21 * V_22 ,
struct V_12 * V_13 )
{
if ( ! V_13 -> V_118 ) {
F_47 ( V_13 , V_13 -> V_9 , 0 ) ;
F_44 ( V_13 , false ) ;
}
}
static int F_53 ( struct V_21 * V_22 )
{
struct V_104 * V_32 ;
if ( V_22 -> V_74 -> V_124 )
return 0 ;
V_32 = V_22 -> V_32 ;
V_32 -> V_112 = V_125 ;
return 0 ;
}
static int F_54 ( struct V_21 * V_22 ,
int V_126 )
{
int V_85 = 0 , V_92 ;
struct V_16 * V_15 ;
int V_95 ;
struct V_97 * V_98 = V_22 -> V_83 ;
F_8 ( V_98 -> V_2 , L_10 ) ;
if ( V_22 -> V_74 -> V_124 )
return 0 ;
V_15 = V_22 -> V_32 -> V_83 ;
V_92 = V_15 -> V_91 . V_92 ;
switch ( V_126 ) {
case V_127 :
F_8 ( V_98 -> V_2 , L_11 ) ;
V_95 = V_96 ;
V_15 -> V_91 . V_94 = V_22 ;
V_85 = V_15 -> V_82 -> V_128 ( V_8 -> V_2 , V_92 ) ;
break;
case V_129 :
F_8 ( V_98 -> V_2 , L_12 ) ;
V_95 = V_130 ;
V_85 = V_15 -> V_82 -> V_110 ( V_8 -> V_2 , V_92 ) ;
break;
case V_131 :
case V_132 :
F_8 ( V_98 -> V_2 , L_13 ) ;
V_95 = V_133 ;
V_85 = V_15 -> V_82 -> V_134 ( V_8 -> V_2 , V_92 ) ;
break;
case V_135 :
case V_136 :
F_8 ( V_98 -> V_2 , L_14 ) ;
V_95 = V_96 ;
V_85 = V_15 -> V_82 -> V_137 ( V_8 -> V_2 , V_92 ) ;
break;
default:
return - V_3 ;
}
if ( ! V_85 )
F_12 ( V_15 , V_95 ) ;
return V_85 ;
}
static T_1 F_55
( struct V_21 * V_22 )
{
struct V_16 * V_15 ;
int V_85 , V_95 ;
struct V_138 * V_139 ;
struct V_97 * V_98 = V_22 -> V_83 ;
V_15 = V_22 -> V_32 -> V_83 ;
V_95 = F_15 ( V_15 ) ;
if ( V_95 == V_99 )
return 0 ;
V_139 = & V_15 -> V_91 ;
V_85 = V_15 -> V_82 -> V_140 ( V_8 -> V_2 , V_139 ) ;
if ( V_85 ) {
F_5 ( V_98 -> V_2 , L_15 , V_85 ) ;
return V_85 ;
}
V_22 -> V_32 -> V_141 = V_139 -> V_142 ;
return V_139 -> V_101 ;
}
static int F_56 ( struct V_97 * V_98 )
{
struct V_12 * V_13 = V_98 -> V_143 ;
struct V_144 * V_74 = V_98 -> V_74 ;
int V_145 = 0 ;
if ( V_13 -> V_4 -> V_146 . V_147 ||
V_13 -> V_4 -> V_148 . V_147 ) {
V_145 = F_57 ( V_74 ,
V_149 ,
F_58 ( V_150 ) ,
V_151 , V_152 ) ;
if ( V_145 ) {
F_5 ( V_98 -> V_2 , L_16 ) ;
return V_145 ;
}
}
return V_145 ;
}
static int F_59 ( struct V_153 * V_154 )
{
struct V_59 * V_155 = F_60 ( V_154 -> V_2 ) ;
V_155 -> V_156 = V_154 -> V_157 . V_158 ;
return F_61 ( V_154 ) ;
}
static int F_62 ( struct V_159 * V_160 )
{
struct V_59 * V_155 ;
int V_117 ;
struct V_161 * V_69 ;
V_155 = F_63 ( & V_160 -> V_2 , sizeof( * V_155 ) , V_105 ) ;
if ( V_155 == NULL ) {
return - V_106 ;
}
V_69 = F_63 ( & V_160 -> V_2 , sizeof( * V_69 ) , V_105 ) ;
if ( V_69 == NULL ) {
return - V_106 ;
}
V_69 -> V_70 = V_162 ;
V_69 -> V_71 = F_64 ( V_162 ) ;
V_155 -> V_69 = V_69 ;
V_155 -> V_160 = V_160 ;
F_65 ( & V_155 -> V_163 ) ;
F_66 ( & V_160 -> V_2 , V_155 ) ;
V_117 = F_67 ( & V_160 -> V_2 , & V_164 ) ;
if ( V_117 ) {
F_5 ( & V_160 -> V_2 , L_17 ) ;
return V_117 ;
}
V_117 = F_68 ( & V_160 -> V_2 , & V_165 ,
V_166 , F_64 ( V_166 ) ) ;
if ( V_117 ) {
F_5 ( & V_160 -> V_2 , L_18 ) ;
F_69 ( & V_160 -> V_2 ) ;
}
return V_117 ;
}
static int F_70 ( struct V_159 * V_160 )
{
F_71 ( & V_160 -> V_2 ) ;
F_69 ( & V_160 -> V_2 ) ;
F_8 ( & V_160 -> V_2 , L_19 ) ;
return 0 ;
}
static int F_72 ( struct V_75 * V_2 )
{
struct V_59 * V_155 = F_60 ( V_2 ) ;
struct V_97 * V_98 ;
if ( ! V_155 -> V_156 )
return 0 ;
F_73 ( V_155 -> V_156 -> V_2 ) ;
F_74 ( V_155 -> V_156 -> V_2 ) ;
F_75 (rtd, &drv->soc_card->rtd_list, list) {
struct V_12 * V_13 = V_98 -> V_143 ;
if ( V_13 -> V_118 ) {
F_47 ( V_13 , V_13 -> V_9 , 0 ) ;
F_44 ( V_13 , false ) ;
}
}
return 0 ;
}
static void F_76 ( struct V_75 * V_2 )
{
struct V_59 * V_155 = F_60 ( V_2 ) ;
struct V_97 * V_98 ;
if ( ! V_155 -> V_156 )
return;
F_75 (rtd, &drv->soc_card->rtd_list, list) {
struct V_12 * V_13 = V_98 -> V_143 ;
if ( V_13 -> V_118 ) {
F_44 ( V_13 , true ) ;
F_47 ( V_13 , V_13 -> V_9 , 1 ) ;
}
}
F_77 ( V_155 -> V_156 -> V_2 ) ;
}
