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
static inline unsigned int F_37 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
struct V_59 * V_8 = F_24 ( V_13 ) ;
struct V_54 * V_55 = V_8 -> V_69 -> V_70 ;
struct V_16 * V_15 =
V_22 -> V_32 -> V_83 ;
T_3 V_92 = V_15 -> V_91 . V_92 ;
unsigned int V_110 ;
V_110 = V_55 [ V_92 ] . V_79 ;
F_8 ( V_13 -> V_2 , L_7 ,
V_110 , V_92 ) ;
return V_110 ;
}
static int F_38 ( struct V_21 * V_22 ,
struct V_12 * V_13 )
{
struct V_16 * V_15 ;
int V_85 = 0 , V_92 ;
V_15 = V_22 -> V_32 -> V_83 ;
V_92 = V_15 -> V_91 . V_92 ;
if ( V_15 -> V_91 . V_92 ) {
V_85 = V_15 -> V_82 -> V_111 ( V_8 -> V_2 , V_92 ) ;
return V_85 ;
}
V_85 = F_23 ( V_22 , V_13 ) ;
if ( V_85 <= 0 )
return V_85 ;
snprintf ( V_22 -> V_74 -> V_112 , sizeof( V_22 -> V_74 -> V_112 ) ,
L_8 , V_15 -> V_91 . V_92 ) ;
V_85 = F_27 ( V_22 ) ;
if ( V_85 )
return V_85 ;
V_22 -> V_32 -> V_113 . V_114 = V_115 ;
return V_85 ;
}
static int F_39 ( struct V_21 * V_22 ,
struct V_116 * V_117 ,
struct V_12 * V_13 )
{
F_40 ( V_22 , F_41 ( V_117 ) ) ;
memset ( V_22 -> V_32 -> V_86 , 0 , F_41 ( V_117 ) ) ;
return 0 ;
}
static int F_42 ( struct V_21 * V_22 ,
struct V_12 * V_13 )
{
return F_43 ( V_22 ) ;
}
static int F_44 ( struct V_21 * V_22 ,
struct V_12 * V_13 )
{
int V_118 = 0 ;
if ( ! V_13 -> V_119 ) {
V_118 = F_45 ( V_13 , true ) ;
F_46 ( V_13 ) ;
}
return V_118 ;
}
static int F_47 ( struct V_21 * V_22 ,
struct V_116 * V_117 ,
struct V_12 * V_13 )
{
int V_118 = 0 ;
if ( V_13 -> V_119 == 1 )
V_118 = F_48 ( V_13 , V_13 -> V_9 , 1 ) ;
return V_118 ;
}
static int F_49 ( struct V_12 * V_13 , unsigned int V_120 )
{
int V_118 = 0 ;
if ( ! V_13 -> V_119 )
return 0 ;
V_118 = F_50 ( V_13 , V_120 ) ;
if ( V_118 < 0 )
F_5 ( V_13 -> V_2 , L_9 ) ;
return V_118 ;
}
static int F_51 ( struct V_12 * V_13 ,
unsigned int V_121 , unsigned int V_122 ,
int V_123 , int V_124 ) {
int V_118 = 0 ;
if ( ! V_13 -> V_119 )
return V_118 ;
V_118 = F_52 ( V_13 , V_121 , V_122 , V_123 , V_124 ) ;
if ( V_118 < 0 )
F_5 ( V_13 -> V_2 , L_10 , V_118 ) ;
return V_118 ;
}
static void F_53 ( struct V_21 * V_22 ,
struct V_12 * V_13 )
{
if ( ! V_13 -> V_119 ) {
F_48 ( V_13 , V_13 -> V_9 , 0 ) ;
F_45 ( V_13 , false ) ;
}
}
static int F_54 ( struct V_21 * V_22 )
{
struct V_104 * V_32 ;
if ( V_22 -> V_74 -> V_125 )
return 0 ;
V_32 = V_22 -> V_32 ;
V_32 -> V_113 = V_126 ;
return 0 ;
}
static int F_55 ( struct V_21 * V_22 ,
int V_127 )
{
int V_85 = 0 , V_92 ;
struct V_16 * V_15 ;
int V_95 ;
struct V_97 * V_98 = V_22 -> V_83 ;
F_8 ( V_98 -> V_2 , L_11 ) ;
if ( V_22 -> V_74 -> V_125 )
return 0 ;
V_15 = V_22 -> V_32 -> V_83 ;
V_92 = V_15 -> V_91 . V_92 ;
switch ( V_127 ) {
case V_128 :
F_8 ( V_98 -> V_2 , L_12 ) ;
V_95 = V_96 ;
V_15 -> V_91 . V_94 = V_22 ;
V_85 = V_15 -> V_82 -> V_129 ( V_8 -> V_2 , V_92 ) ;
break;
case V_130 :
F_8 ( V_98 -> V_2 , L_13 ) ;
V_95 = V_131 ;
V_85 = V_15 -> V_82 -> V_111 ( V_8 -> V_2 , V_92 ) ;
break;
case V_132 :
case V_133 :
F_8 ( V_98 -> V_2 , L_14 ) ;
V_95 = V_134 ;
V_85 = V_15 -> V_82 -> V_135 ( V_8 -> V_2 , V_92 ) ;
break;
case V_136 :
case V_137 :
F_8 ( V_98 -> V_2 , L_15 ) ;
V_95 = V_96 ;
V_85 = V_15 -> V_82 -> V_138 ( V_8 -> V_2 , V_92 ) ;
break;
default:
return - V_3 ;
}
if ( ! V_85 )
F_12 ( V_15 , V_95 ) ;
return V_85 ;
}
static T_1 F_56
( struct V_21 * V_22 )
{
struct V_16 * V_15 ;
int V_85 , V_95 ;
struct V_139 * V_140 ;
struct V_97 * V_98 = V_22 -> V_83 ;
V_15 = V_22 -> V_32 -> V_83 ;
V_95 = F_15 ( V_15 ) ;
if ( V_95 == V_99 )
return 0 ;
V_140 = & V_15 -> V_91 ;
V_85 = V_15 -> V_82 -> V_141 ( V_8 -> V_2 , V_140 ) ;
if ( V_85 ) {
F_5 ( V_98 -> V_2 , L_16 , V_85 ) ;
return V_85 ;
}
V_22 -> V_32 -> V_142 = V_140 -> V_143 ;
return V_140 -> V_101 ;
}
static int F_57 ( struct V_97 * V_98 )
{
struct V_12 * V_13 = V_98 -> V_144 ;
struct V_145 * V_74 = V_98 -> V_74 ;
int V_146 = 0 ;
if ( V_13 -> V_4 -> V_147 . V_148 ||
V_13 -> V_4 -> V_149 . V_148 ) {
V_146 = F_58 ( V_74 ,
V_150 ,
F_59 ( V_151 ) ,
V_152 , V_153 ) ;
if ( V_146 ) {
F_5 ( V_98 -> V_2 , L_17 ) ;
return V_146 ;
}
}
return V_146 ;
}
static int F_60 ( struct V_154 * V_155 )
{
struct V_59 * V_156 = F_61 ( V_155 -> V_2 ) ;
V_156 -> V_157 = V_155 -> V_158 . V_159 ;
return F_62 ( V_155 ) ;
}
static int F_63 ( struct V_160 * V_161 )
{
struct V_59 * V_156 ;
int V_118 ;
struct V_162 * V_69 ;
V_156 = F_64 ( & V_161 -> V_2 , sizeof( * V_156 ) , V_105 ) ;
if ( V_156 == NULL ) {
return - V_106 ;
}
V_69 = F_64 ( & V_161 -> V_2 , sizeof( * V_69 ) , V_105 ) ;
if ( V_69 == NULL ) {
return - V_106 ;
}
V_69 -> V_70 = V_163 ;
V_69 -> V_71 = F_65 ( V_163 ) ;
V_156 -> V_69 = V_69 ;
V_156 -> V_161 = V_161 ;
F_66 ( & V_156 -> V_164 ) ;
F_67 ( & V_161 -> V_2 , V_156 ) ;
V_118 = F_68 ( & V_161 -> V_2 , & V_165 ) ;
if ( V_118 ) {
F_5 ( & V_161 -> V_2 , L_18 ) ;
return V_118 ;
}
V_118 = F_69 ( & V_161 -> V_2 , & V_166 ,
V_167 , F_65 ( V_167 ) ) ;
if ( V_118 ) {
F_5 ( & V_161 -> V_2 , L_19 ) ;
F_70 ( & V_161 -> V_2 ) ;
}
return V_118 ;
}
static int F_71 ( struct V_160 * V_161 )
{
F_72 ( & V_161 -> V_2 ) ;
F_70 ( & V_161 -> V_2 ) ;
F_8 ( & V_161 -> V_2 , L_20 ) ;
return 0 ;
}
static int F_73 ( struct V_75 * V_2 )
{
struct V_59 * V_156 = F_61 ( V_2 ) ;
int V_56 ;
F_74 ( V_156 -> V_157 -> V_2 ) ;
F_75 ( V_156 -> V_157 -> V_2 ) ;
for ( V_56 = 0 ; V_56 < V_156 -> V_157 -> V_168 ; V_56 ++ ) {
struct V_12 * V_13 = V_156 -> V_157 -> V_98 [ V_56 ] . V_144 ;
if ( V_13 -> V_119 ) {
F_48 ( V_13 , V_13 -> V_9 , 0 ) ;
F_45 ( V_13 , false ) ;
}
}
return 0 ;
}
static void F_76 ( struct V_75 * V_2 )
{
struct V_59 * V_156 = F_61 ( V_2 ) ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_156 -> V_157 -> V_168 ; V_56 ++ ) {
struct V_12 * V_13 = V_156 -> V_157 -> V_98 [ V_56 ] . V_144 ;
if ( V_13 -> V_119 ) {
F_45 ( V_13 , true ) ;
F_48 ( V_13 , V_13 -> V_9 , 1 ) ;
}
}
F_77 ( V_156 -> V_157 -> V_2 ) ;
}
