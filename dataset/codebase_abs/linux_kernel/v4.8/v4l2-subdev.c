static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
#if F_2 ( V_5 )
if ( V_4 -> V_6 . V_7 ) {
V_2 -> V_8 = F_3 ( V_4 ) ;
if ( V_2 -> V_8 == NULL )
return - V_9 ;
}
#endif
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
#if F_2 ( V_5 )
F_5 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
#endif
}
static int F_6 ( struct V_10 * V_10 )
{
struct V_11 * V_12 = F_7 ( V_10 ) ;
struct V_3 * V_4 = F_8 ( V_12 ) ;
struct V_1 * V_13 ;
#if F_2 ( V_14 )
struct V_15 * V_6 = NULL ;
#endif
int V_16 ;
V_13 = F_9 ( sizeof( * V_13 ) , V_17 ) ;
if ( V_13 == NULL )
return - V_9 ;
V_16 = F_1 ( V_13 , V_4 ) ;
if ( V_16 ) {
F_10 ( V_13 ) ;
return V_16 ;
}
F_11 ( & V_13 -> V_18 , V_12 ) ;
F_12 ( & V_13 -> V_18 ) ;
V_10 -> V_19 = & V_13 -> V_18 ;
#if F_2 ( V_14 )
if ( V_4 -> V_20 -> V_21 ) {
V_6 = F_13 ( & V_4 -> V_6 ) ;
if ( ! V_6 ) {
V_16 = - V_22 ;
goto V_23;
}
}
#endif
if ( V_4 -> V_24 && V_4 -> V_24 -> V_25 ) {
V_16 = V_4 -> V_24 -> V_25 ( V_4 , V_13 ) ;
if ( V_16 < 0 )
goto V_23;
}
return 0 ;
V_23:
#if F_2 ( V_14 )
F_14 ( V_6 ) ;
#endif
F_15 ( & V_13 -> V_18 ) ;
F_16 ( & V_13 -> V_18 ) ;
F_4 ( V_13 ) ;
F_10 ( V_13 ) ;
return V_16 ;
}
static int F_17 ( struct V_10 * V_10 )
{
struct V_11 * V_12 = F_7 ( V_10 ) ;
struct V_3 * V_4 = F_8 ( V_12 ) ;
struct V_26 * V_18 = V_10 -> V_19 ;
struct V_1 * V_13 = F_18 ( V_18 ) ;
if ( V_4 -> V_24 && V_4 -> V_24 -> V_27 )
V_4 -> V_24 -> V_27 ( V_4 , V_13 ) ;
#if F_2 ( V_14 )
if ( V_4 -> V_20 -> V_21 )
F_14 ( & V_4 -> V_6 ) ;
#endif
F_15 ( V_18 ) ;
F_16 ( V_18 ) ;
F_4 ( V_13 ) ;
F_10 ( V_13 ) ;
V_10 -> V_19 = NULL ;
return 0 ;
}
static int F_19 ( struct V_3 * V_4 ,
struct V_28 * V_29 )
{
if ( V_29 -> V_30 != V_31 &&
V_29 -> V_30 != V_32 )
return - V_33 ;
if ( V_29 -> V_8 >= V_4 -> V_6 . V_7 )
return - V_33 ;
return 0 ;
}
static int F_20 ( struct V_3 * V_4 , struct V_34 * V_35 )
{
if ( V_35 -> V_30 != V_31 &&
V_35 -> V_30 != V_32 )
return - V_33 ;
if ( V_35 -> V_8 >= V_4 -> V_6 . V_7 )
return - V_33 ;
return 0 ;
}
static int F_21 ( struct V_3 * V_4 ,
struct V_36 * V_37 )
{
if ( V_37 -> V_30 != V_31 &&
V_37 -> V_30 != V_32 )
return - V_33 ;
if ( V_37 -> V_8 >= V_4 -> V_6 . V_7 )
return - V_33 ;
return 0 ;
}
static int F_22 ( struct V_3 * V_4 , struct V_38 * V_39 )
{
if ( V_39 -> V_8 >= V_4 -> V_6 . V_7 )
return - V_33 ;
if ( V_39 -> V_40 && V_39 -> V_39 == NULL )
return - V_33 ;
return 0 ;
}
static long F_23 ( struct V_10 * V_10 , unsigned int V_41 , void * V_42 )
{
struct V_11 * V_12 = F_7 ( V_10 ) ;
struct V_3 * V_4 = F_8 ( V_12 ) ;
struct V_26 * V_18 = V_10 -> V_19 ;
#if F_2 ( V_5 )
struct V_1 * V_13 = F_18 ( V_18 ) ;
int V_43 ;
#endif
switch ( V_41 ) {
case V_44 :
return F_24 ( V_18 -> V_45 , V_42 ) ;
case V_46 :
return F_25 ( V_18 -> V_45 , V_42 ) ;
case V_47 :
return F_26 ( V_18 -> V_45 , V_42 ) ;
case V_48 :
return F_27 ( V_18 -> V_45 , V_42 ) ;
case V_49 :
return F_28 ( V_18 , V_18 -> V_45 , V_42 ) ;
case V_50 :
return F_29 ( V_18 -> V_45 , V_42 ) ;
case V_51 :
return F_30 ( V_18 , V_18 -> V_45 , V_42 ) ;
case V_52 :
return F_31 ( V_18 -> V_45 , V_42 ) ;
case V_53 :
if ( ! ( V_4 -> V_54 & V_55 ) )
return - V_56 ;
return F_32 ( V_18 , V_42 , V_10 -> V_57 & V_58 ) ;
case V_59 :
return F_33 ( V_4 , V_60 , V_61 , V_18 , V_42 ) ;
case V_62 :
return F_33 ( V_4 , V_60 , V_63 , V_18 , V_42 ) ;
#ifdef F_34
case V_64 :
{
struct V_65 * V_66 = V_42 ;
if ( ! F_35 ( V_67 ) )
return - V_68 ;
return F_33 ( V_4 , V_60 , V_69 , V_66 ) ;
}
case V_70 :
{
struct V_65 * V_66 = V_42 ;
if ( ! F_35 ( V_67 ) )
return - V_68 ;
return F_33 ( V_4 , V_60 , V_71 , V_66 ) ;
}
#endif
case V_72 : {
int V_16 ;
F_36 ( L_1 ,
V_4 -> V_73 ) ;
V_16 = F_33 ( V_4 , V_60 , V_74 ) ;
F_36 ( L_2 ,
V_4 -> V_73 ) ;
return V_16 ;
}
#if F_2 ( V_5 )
case V_75 : {
struct V_28 * V_29 = V_42 ;
V_43 = F_19 ( V_4 , V_29 ) ;
if ( V_43 )
return V_43 ;
return F_33 ( V_4 , V_8 , V_76 , V_13 -> V_8 , V_29 ) ;
}
case V_77 : {
struct V_28 * V_29 = V_42 ;
V_43 = F_19 ( V_4 , V_29 ) ;
if ( V_43 )
return V_43 ;
return F_33 ( V_4 , V_8 , V_78 , V_13 -> V_8 , V_29 ) ;
}
case V_79 : {
struct V_34 * V_35 = V_42 ;
struct V_36 V_37 ;
V_43 = F_20 ( V_4 , V_35 ) ;
if ( V_43 )
return V_43 ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_30 = V_35 -> V_30 ;
V_37 . V_8 = V_35 -> V_8 ;
V_37 . V_80 = V_81 ;
V_43 = F_33 (
V_4 , V_8 , V_82 , V_13 -> V_8 , & V_37 ) ;
V_35 -> V_83 = V_37 . V_84 ;
return V_43 ;
}
case V_85 : {
struct V_34 * V_35 = V_42 ;
struct V_36 V_37 ;
V_43 = F_20 ( V_4 , V_35 ) ;
if ( V_43 )
return V_43 ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_30 = V_35 -> V_30 ;
V_37 . V_8 = V_35 -> V_8 ;
V_37 . V_80 = V_81 ;
V_37 . V_84 = V_35 -> V_83 ;
V_43 = F_33 (
V_4 , V_8 , V_86 , V_13 -> V_8 , & V_37 ) ;
V_35 -> V_83 = V_37 . V_84 ;
return V_43 ;
}
case V_87 : {
struct V_88 * V_89 = V_42 ;
if ( V_89 -> V_30 != V_31 &&
V_89 -> V_30 != V_32 )
return - V_33 ;
if ( V_89 -> V_8 >= V_4 -> V_6 . V_7 )
return - V_33 ;
return F_33 ( V_4 , V_8 , V_90 , V_13 -> V_8 ,
V_89 ) ;
}
case V_91 : {
struct V_92 * V_93 = V_42 ;
if ( V_93 -> V_30 != V_31 &&
V_93 -> V_30 != V_32 )
return - V_33 ;
if ( V_93 -> V_8 >= V_4 -> V_6 . V_7 )
return - V_33 ;
return F_33 ( V_4 , V_8 , V_94 , V_13 -> V_8 ,
V_93 ) ;
}
case V_95 : {
struct V_96 * V_97 = V_42 ;
if ( V_97 -> V_8 >= V_4 -> V_6 . V_7 )
return - V_33 ;
return F_33 ( V_4 , V_98 , V_99 , V_42 ) ;
}
case V_100 : {
struct V_96 * V_97 = V_42 ;
if ( V_97 -> V_8 >= V_4 -> V_6 . V_7 )
return - V_33 ;
return F_33 ( V_4 , V_98 , V_101 , V_42 ) ;
}
case V_102 : {
struct V_103 * V_104 = V_42 ;
if ( V_104 -> V_30 != V_31 &&
V_104 -> V_30 != V_32 )
return - V_33 ;
if ( V_104 -> V_8 >= V_4 -> V_6 . V_7 )
return - V_33 ;
return F_33 ( V_4 , V_8 , V_105 , V_13 -> V_8 ,
V_104 ) ;
}
case V_106 : {
struct V_36 * V_37 = V_42 ;
V_43 = F_21 ( V_4 , V_37 ) ;
if ( V_43 )
return V_43 ;
return F_33 (
V_4 , V_8 , V_82 , V_13 -> V_8 , V_37 ) ;
}
case V_107 : {
struct V_36 * V_37 = V_42 ;
V_43 = F_21 ( V_4 , V_37 ) ;
if ( V_43 )
return V_43 ;
return F_33 (
V_4 , V_8 , V_86 , V_13 -> V_8 , V_37 ) ;
}
case V_108 : {
struct V_38 * V_39 = V_42 ;
V_43 = F_22 ( V_4 , V_39 ) ;
if ( V_43 )
return V_43 ;
return F_33 ( V_4 , V_8 , V_109 , V_39 ) ;
}
case V_110 : {
struct V_38 * V_39 = V_42 ;
V_43 = F_22 ( V_4 , V_39 ) ;
if ( V_43 )
return V_43 ;
return F_33 ( V_4 , V_8 , V_111 , V_39 ) ;
}
case V_112 : {
struct V_113 * V_114 = V_42 ;
if ( V_114 -> V_8 >= V_4 -> V_6 . V_7 )
return - V_33 ;
return F_33 ( V_4 , V_8 , V_115 , V_114 ) ;
}
case V_116 : {
struct V_117 * V_118 = V_42 ;
if ( V_118 -> V_8 >= V_4 -> V_6 . V_7 )
return - V_33 ;
return F_33 ( V_4 , V_8 , V_119 , V_118 ) ;
}
case V_120 :
return F_33 ( V_4 , V_98 , V_121 , V_42 ) ;
case V_122 :
return F_33 ( V_4 , V_98 , V_123 , V_42 ) ;
case V_124 :
return F_33 ( V_4 , V_98 , V_125 , V_42 ) ;
#endif
default:
return F_33 ( V_4 , V_60 , V_126 , V_41 , V_42 ) ;
}
return 0 ;
}
static long F_37 ( struct V_10 * V_10 , unsigned int V_41 ,
unsigned long V_42 )
{
return F_38 ( V_10 , V_41 , V_42 , F_23 ) ;
}
static long F_39 ( struct V_10 * V_10 , unsigned int V_41 ,
unsigned long V_42 )
{
struct V_11 * V_12 = F_7 ( V_10 ) ;
struct V_3 * V_4 = F_8 ( V_12 ) ;
return F_33 ( V_4 , V_60 , V_127 , V_41 , V_42 ) ;
}
static unsigned int F_40 ( struct V_10 * V_10 , T_1 * V_128 )
{
struct V_11 * V_12 = F_7 ( V_10 ) ;
struct V_3 * V_4 = F_8 ( V_12 ) ;
struct V_26 * V_2 = V_10 -> V_19 ;
if ( ! ( V_4 -> V_54 & V_55 ) )
return V_129 ;
F_41 ( V_10 , & V_2 -> V_128 , V_128 ) ;
if ( F_42 ( V_2 ) )
return V_130 ;
return 0 ;
}
int F_43 ( struct V_3 * V_4 ,
struct V_131 * V_132 ,
struct V_28 * V_133 ,
struct V_28 * V_134 )
{
if ( V_133 -> V_29 . V_135 != V_134 -> V_29 . V_135
|| V_133 -> V_29 . V_136 != V_134 -> V_29 . V_136
|| V_133 -> V_29 . V_89 != V_134 -> V_29 . V_89 )
return - V_137 ;
if ( V_133 -> V_29 . V_138 != V_134 -> V_29 . V_138 &&
V_134 -> V_29 . V_138 != V_139 )
return - V_137 ;
return 0 ;
}
static int
F_44 ( struct V_140 * V_8 ,
struct V_28 * V_141 )
{
if ( F_45 ( V_8 -> V_6 ) ) {
struct V_3 * V_4 =
F_46 ( V_8 -> V_6 ) ;
V_141 -> V_30 = V_32 ;
V_141 -> V_8 = V_8 -> V_142 ;
return F_33 ( V_4 , V_8 , V_76 , NULL , V_141 ) ;
}
F_47 ( V_8 -> V_6 -> V_143 != V_144 ,
L_3 ,
V_8 -> V_6 -> V_143 , V_8 -> V_6 -> V_73 ) ;
return - V_33 ;
}
int F_48 ( struct V_131 * V_132 )
{
struct V_3 * V_145 ;
struct V_28 V_134 , V_133 ;
int V_43 ;
V_43 = F_44 (
V_132 -> V_146 , & V_133 ) ;
if ( V_43 < 0 )
return 0 ;
V_43 = F_44 (
V_132 -> V_145 , & V_134 ) ;
if ( V_43 < 0 )
return 0 ;
V_145 = F_46 ( V_132 -> V_145 -> V_6 ) ;
V_43 = F_33 ( V_145 , V_8 , V_147 , V_132 ,
& V_133 , & V_134 ) ;
if ( V_43 != - V_56 )
return V_43 ;
return F_43 (
V_145 , V_132 , & V_133 , & V_134 ) ;
}
struct V_148 *
F_3 ( struct V_3 * V_4 )
{
struct V_148 * V_149 ;
int V_16 ;
if ( ! V_4 -> V_6 . V_7 )
return NULL ;
V_149 = F_49 ( V_4 -> V_6 . V_7 , sizeof( * V_149 ) , V_17 ) ;
if ( ! V_149 )
return NULL ;
V_16 = F_33 ( V_4 , V_8 , V_150 , V_149 ) ;
if ( V_16 < 0 && V_16 != - V_56 ) {
F_10 ( V_149 ) ;
return NULL ;
}
return V_149 ;
}
void F_5 ( struct V_148 * V_149 )
{
F_10 ( V_149 ) ;
}
void F_50 ( struct V_3 * V_4 , const struct V_151 * V_152 )
{
F_51 ( & V_4 -> V_153 ) ;
F_52 ( ! V_152 ) ;
V_4 -> V_152 = V_152 ;
V_4 -> V_20 = NULL ;
V_4 -> V_54 = 0 ;
V_4 -> V_73 [ 0 ] = '\0' ;
V_4 -> V_154 = 0 ;
V_4 -> V_155 = NULL ;
V_4 -> V_156 = NULL ;
#if F_2 ( V_14 )
V_4 -> V_6 . V_73 = V_4 -> V_73 ;
V_4 -> V_6 . V_157 = V_158 ;
V_4 -> V_6 . V_143 = V_159 ;
#endif
}
void F_53 ( struct V_3 * V_4 ,
const struct V_160 * V_161 )
{
F_54 ( V_4 -> V_162 , V_161 ) ;
F_55 ( V_4 , V_163 , ( void * ) V_161 ) ;
}
