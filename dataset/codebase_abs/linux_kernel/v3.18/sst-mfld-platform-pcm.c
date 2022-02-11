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
void F_10 ( struct V_12 * V_13 ,
int V_14 )
{
unsigned long V_15 ;
F_11 ( & V_13 -> V_16 , V_15 ) ;
V_13 -> V_17 = V_14 ;
F_12 ( & V_13 -> V_16 , V_15 ) ;
}
static inline int F_13 ( struct V_12 * V_13 )
{
int V_14 ;
unsigned long V_15 ;
F_11 ( & V_13 -> V_16 , V_15 ) ;
V_14 = V_13 -> V_17 ;
F_12 ( & V_13 -> V_16 , V_15 ) ;
return V_14 ;
}
static void F_14 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
unsigned int V_22 ;
T_1 V_23 ;
T_2 V_24 ;
T_2 V_25 = F_15 ( V_19 ) ;
T_3 V_26 = F_16 ( V_19 -> V_27 . V_28 ) ;
V_22 = V_19 -> V_29 -> V_22 ;
V_23 = V_19 -> V_29 -> V_23 ;
V_24 = F_17 ( V_19 -> V_29 , V_23 ) ;
V_21 -> V_30 [ 0 ] . V_31 = V_26 ;
V_21 -> V_30 [ 0 ] . V_32 = V_25 ;
V_21 -> V_33 = 1 ;
V_21 -> V_34 = 0 ;
V_21 -> V_35 = V_24 * V_22 ;
}
static void F_18 ( struct V_18 * V_19 ,
struct V_36 * V_37 )
{
V_37 -> V_38 . V_39 . V_40 = ( V_41 ) V_19 -> V_29 -> V_22 ;
V_37 -> V_38 . V_39 . V_42 = V_19 -> V_29 -> V_43 ;
V_37 -> V_38 . V_39 . V_44 = V_19 -> V_29 -> V_45 ;
V_37 -> V_38 . V_39 . V_46 = 0 ;
V_37 -> V_38 . V_39 . V_47 = 0 ;
memset ( V_37 -> V_38 . V_39 . V_48 , 0 , sizeof( V_41 ) ) ;
}
static int F_19 ( int V_2 , int V_49 , int V_50 ,
struct V_51 * V_52 , int V_32 )
{
int V_53 ;
if ( V_52 == NULL )
return - V_3 ;
for ( V_53 = 1 ; V_53 < V_32 ; V_53 ++ ) {
if ( ( V_52 [ V_53 ] . V_54 == V_2 ) && ( V_52 [ V_53 ] . V_55 == V_50 ) )
return V_53 ;
}
return 0 ;
}
int F_20 ( void * V_19 ,
const struct V_56 * V_57 , struct V_58 * V_59 , bool V_60 )
{
int V_61 ;
int V_62 ;
struct V_51 * V_52 ;
struct V_18 * V_63 = NULL ;
struct V_64 * V_65 = NULL ;
V_52 = V_57 -> V_66 -> V_67 ;
V_61 = V_57 -> V_66 -> V_68 ;
if ( V_60 == true )
V_65 = (struct V_64 * ) V_19 ;
else
V_63 = (struct V_18 * ) V_19 ;
V_59 -> V_69 = V_70 ;
if ( V_63 ) {
V_62 = F_19 ( V_63 -> V_71 -> V_72 ,
V_63 -> V_73 , V_63 -> V_13 ,
V_52 , V_61 ) ;
if ( V_62 <= 0 )
return - V_3 ;
V_59 -> V_74 = V_62 ;
V_59 -> V_75 = V_52 [ V_62 ] . V_76 ;
V_59 -> V_77 = V_52 [ V_62 ] . V_78 ;
V_59 -> V_79 = ( V_41 ) V_63 -> V_13 ;
}
if ( V_65 ) {
V_62 = F_19 ( V_65 -> V_72 -> V_72 ,
0 , V_65 -> V_55 ,
V_52 , V_61 ) ;
if ( V_62 <= 0 )
return - V_3 ;
V_59 -> V_74 = V_62 ;
V_59 -> V_75 = V_52 [ V_62 ] . V_76 ;
V_59 -> V_77 = V_52 [ V_62 ] . V_78 ;
V_59 -> V_79 = ( V_41 ) V_65 -> V_55 ;
}
return 0 ;
}
static int F_21 ( struct V_18 * V_19 ,
struct V_80 * V_81 )
{
struct V_12 * V_13 =
V_19 -> V_29 -> V_82 ;
struct V_36 V_37 = { { { 0 ,} ,} ,} ;
struct V_58 V_59 = { 0 } ;
struct V_20 V_83 = { 0 } ;
int V_84 = 0 ;
struct V_56 * V_57 = F_22 ( V_81 ) ;
F_18 ( V_19 , & V_37 ) ;
F_14 ( V_19 , & V_83 ) ;
V_19 -> V_29 -> V_85 = V_19 -> V_27 . V_28 ;
V_59 . V_86 = V_37 ;
V_59 . V_87 = V_83 ;
V_59 . V_88 = V_89 ;
V_84 = F_20 ( V_19 , V_57 , & V_59 , false ) ;
if ( V_84 < 0 )
return V_84 ;
V_13 -> V_90 . V_91 = V_59 . V_74 ;
V_84 = V_13 -> V_79 -> V_92 ( V_8 -> V_2 , & V_59 ) ;
if ( V_84 <= 0 )
return V_84 ;
return V_84 ;
}
static void F_23 ( void * V_93 )
{
struct V_18 * V_19 = V_93 ;
struct V_12 * V_13 ;
int V_94 ;
if ( ! V_19 || ! V_19 -> V_29 )
return;
V_13 = V_19 -> V_29 -> V_82 ;
if ( ! V_13 )
return;
V_94 = F_13 ( V_13 ) ;
if ( V_94 != V_95 )
return;
F_24 ( V_19 ) ;
}
static int F_25 ( struct V_18 * V_19 )
{
struct V_12 * V_13 =
V_19 -> V_29 -> V_82 ;
struct V_96 * V_97 = V_19 -> V_82 ;
int V_84 ;
F_8 ( V_97 -> V_2 , L_4 ) ;
F_10 ( V_13 , V_98 ) ;
V_13 -> V_90 . V_99 = F_23 ;
V_13 -> V_90 . V_93 = V_19 ;
V_13 -> V_90 . V_100 = 0 ;
V_13 -> V_90 . V_44 = V_19 -> V_29 -> V_45 ;
V_84 = V_13 -> V_79 -> V_101 ( V_8 -> V_2 , & V_13 -> V_90 ) ;
if ( V_84 )
F_5 ( V_97 -> V_2 , L_5 , V_84 ) ;
return V_84 ;
}
static int F_26 ( struct V_12 * V_13 )
{
return V_13 -> V_79 -> V_102 ( V_8 -> V_2 , true ) ;
}
static void F_27 ( struct V_12 * V_13 )
{
V_13 -> V_79 -> V_102 ( V_8 -> V_2 , false ) ;
}
static int F_28 ( struct V_18 * V_19 ,
struct V_80 * V_81 )
{
int V_84 = 0 ;
struct V_103 * V_29 = V_19 -> V_29 ;
struct V_12 * V_13 ;
V_13 = F_29 ( sizeof( * V_13 ) , V_104 ) ;
if ( ! V_13 )
return - V_105 ;
F_30 ( & V_13 -> V_16 ) ;
F_4 ( & V_7 ) ;
if ( ! V_8 ||
! F_3 ( V_8 -> V_2 -> V_4 -> V_5 ) ) {
F_5 ( V_81 -> V_2 , L_6 ) ;
V_84 = - V_6 ;
goto V_106;
}
V_13 -> V_79 = V_8 -> V_79 ;
F_7 ( & V_7 ) ;
V_13 -> V_90 . V_91 = 0 ;
V_13 -> V_90 . V_93 = V_19 ;
V_29 -> V_82 = V_13 ;
V_84 = F_26 ( V_13 ) ;
if ( V_84 < 0 )
return V_84 ;
F_31 ( V_19 -> V_29 , 0 ,
V_107 , 2 ) ;
return F_32 ( V_29 ,
V_107 ) ;
V_106:
F_33 ( V_13 ) ;
F_7 ( & V_7 ) ;
return V_84 ;
}
static void F_34 ( struct V_18 * V_19 ,
struct V_80 * V_81 )
{
struct V_12 * V_13 ;
int V_84 = 0 , V_91 ;
V_13 = V_19 -> V_29 -> V_82 ;
F_27 ( V_13 ) ;
V_91 = V_13 -> V_90 . V_91 ;
if ( V_91 )
V_84 = V_13 -> V_79 -> V_108 ( V_8 -> V_2 , V_91 ) ;
F_6 ( V_8 -> V_2 -> V_4 -> V_5 ) ;
F_33 ( V_13 ) ;
}
static inline unsigned int F_35 ( struct V_80 * V_81 ,
struct V_18 * V_19 )
{
struct V_56 * V_8 = F_22 ( V_81 ) ;
struct V_51 * V_52 = V_8 -> V_66 -> V_67 ;
struct V_12 * V_13 =
V_19 -> V_29 -> V_82 ;
T_3 V_91 = V_13 -> V_90 . V_91 ;
unsigned int V_109 ;
V_109 = V_52 [ V_91 ] . V_76 ;
F_8 ( V_81 -> V_2 , L_7 ,
V_109 , V_91 ) ;
return V_109 ;
}
static int F_36 ( struct V_18 * V_19 ,
struct V_80 * V_81 )
{
struct V_12 * V_13 ;
int V_84 = 0 , V_91 ;
V_13 = V_19 -> V_29 -> V_82 ;
V_91 = V_13 -> V_90 . V_91 ;
if ( V_13 -> V_90 . V_91 ) {
V_84 = V_13 -> V_79 -> V_110 ( V_8 -> V_2 , V_91 ) ;
return V_84 ;
}
V_84 = F_21 ( V_19 , V_81 ) ;
if ( V_84 <= 0 )
return V_84 ;
snprintf ( V_19 -> V_71 -> V_111 , sizeof( V_19 -> V_71 -> V_111 ) ,
L_8 , V_13 -> V_90 . V_91 ) ;
V_84 = F_25 ( V_19 ) ;
if ( V_84 )
return V_84 ;
V_19 -> V_29 -> V_112 . V_113 = V_114 ;
return V_84 ;
}
static int F_37 ( struct V_18 * V_19 ,
struct V_115 * V_116 ,
struct V_80 * V_81 )
{
F_38 ( V_19 , F_39 ( V_116 ) ) ;
memset ( V_19 -> V_29 -> V_85 , 0 , F_39 ( V_116 ) ) ;
return 0 ;
}
static int F_40 ( struct V_18 * V_19 ,
struct V_80 * V_81 )
{
return F_41 ( V_19 ) ;
}
static int F_42 ( struct V_18 * V_19 )
{
struct V_103 * V_29 ;
if ( V_19 -> V_71 -> V_117 )
return 0 ;
V_29 = V_19 -> V_29 ;
V_29 -> V_112 = V_118 ;
return 0 ;
}
static int F_43 ( struct V_18 * V_19 ,
int V_119 )
{
int V_84 = 0 , V_91 ;
struct V_12 * V_13 ;
int V_94 ;
struct V_96 * V_97 = V_19 -> V_82 ;
F_8 ( V_97 -> V_2 , L_9 ) ;
if ( V_19 -> V_71 -> V_117 )
return 0 ;
V_13 = V_19 -> V_29 -> V_82 ;
V_91 = V_13 -> V_90 . V_91 ;
switch ( V_119 ) {
case V_120 :
F_8 ( V_97 -> V_2 , L_10 ) ;
V_94 = V_95 ;
V_13 -> V_90 . V_93 = V_19 ;
V_84 = V_13 -> V_79 -> V_121 ( V_8 -> V_2 , V_91 ) ;
break;
case V_122 :
F_8 ( V_97 -> V_2 , L_11 ) ;
V_94 = V_123 ;
V_84 = V_13 -> V_79 -> V_110 ( V_8 -> V_2 , V_91 ) ;
break;
case V_124 :
F_8 ( V_97 -> V_2 , L_12 ) ;
V_94 = V_125 ;
V_84 = V_13 -> V_79 -> V_126 ( V_8 -> V_2 , V_91 ) ;
break;
case V_127 :
F_8 ( V_97 -> V_2 , L_13 ) ;
V_94 = V_95 ;
V_84 = V_13 -> V_79 -> V_128 ( V_8 -> V_2 , V_91 ) ;
break;
default:
return - V_3 ;
}
if ( ! V_84 )
F_10 ( V_13 , V_94 ) ;
return V_84 ;
}
static T_1 F_44
( struct V_18 * V_19 )
{
struct V_12 * V_13 ;
int V_84 , V_94 ;
struct V_129 * V_130 ;
struct V_96 * V_97 = V_19 -> V_82 ;
V_13 = V_19 -> V_29 -> V_82 ;
V_94 = F_13 ( V_13 ) ;
if ( V_94 == V_98 )
return 0 ;
V_130 = & V_13 -> V_90 ;
V_84 = V_13 -> V_79 -> V_131 ( V_8 -> V_2 , V_130 ) ;
if ( V_84 ) {
F_5 ( V_97 -> V_2 , L_14 , V_84 ) ;
return V_84 ;
}
V_19 -> V_29 -> V_132 = V_130 -> V_133 ;
return V_130 -> V_100 ;
}
static void F_45 ( struct V_134 * V_71 )
{
F_8 ( V_71 -> V_2 , L_15 ) ;
F_46 ( V_71 ) ;
}
static int F_47 ( struct V_96 * V_97 )
{
struct V_80 * V_81 = V_97 -> V_135 ;
struct V_134 * V_71 = V_97 -> V_71 ;
int V_136 = 0 ;
if ( V_81 -> V_4 -> V_137 . V_138 ||
V_81 -> V_4 -> V_139 . V_138 ) {
V_136 = F_48 ( V_71 ,
V_140 ,
F_49 ( V_141 ) ,
V_142 , V_143 ) ;
if ( V_136 ) {
F_5 ( V_97 -> V_2 , L_16 ) ;
return V_136 ;
}
}
return V_136 ;
}
static int F_50 ( struct V_144 * V_145 )
{
return F_51 ( V_145 ) ;
}
static int F_52 ( struct V_146 * V_147 )
{
struct V_56 * V_148 ;
int V_149 ;
struct V_150 * V_66 ;
V_148 = F_53 ( & V_147 -> V_2 , sizeof( * V_148 ) , V_104 ) ;
if ( V_148 == NULL ) {
return - V_105 ;
}
V_66 = F_53 ( & V_147 -> V_2 , sizeof( * V_66 ) , V_104 ) ;
if ( V_66 == NULL ) {
return - V_105 ;
}
V_66 -> V_67 = V_151 ;
V_66 -> V_68 = F_54 ( V_151 ) ;
V_148 -> V_66 = V_66 ;
F_55 ( & V_148 -> V_152 ) ;
F_56 ( & V_147 -> V_2 , V_148 ) ;
V_149 = F_57 ( & V_147 -> V_2 , & V_153 ) ;
if ( V_149 ) {
F_5 ( & V_147 -> V_2 , L_17 ) ;
return V_149 ;
}
V_149 = F_58 ( & V_147 -> V_2 , & V_154 ,
V_155 , F_54 ( V_155 ) ) ;
if ( V_149 ) {
F_5 ( & V_147 -> V_2 , L_18 ) ;
F_59 ( & V_147 -> V_2 ) ;
}
return V_149 ;
}
static int F_60 ( struct V_146 * V_147 )
{
F_61 ( & V_147 -> V_2 ) ;
F_59 ( & V_147 -> V_2 ) ;
F_8 ( & V_147 -> V_2 , L_19 ) ;
return 0 ;
}
