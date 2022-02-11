static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
#if F_2 ( V_5 )
V_2 -> V_6 = F_3 ( sizeof( * V_2 -> V_6 ) * V_4 -> V_7 . V_8 , V_9 ) ;
if ( V_2 -> V_6 == NULL )
return - V_10 ;
#endif
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
#if F_2 ( V_5 )
F_5 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
#endif
}
static int F_6 ( struct V_11 * V_11 )
{
struct V_12 * V_13 = F_7 ( V_11 ) ;
struct V_3 * V_4 = F_8 ( V_13 ) ;
struct V_1 * V_14 ;
#if F_2 ( V_15 )
struct V_16 * V_7 = NULL ;
#endif
int V_17 ;
V_14 = F_3 ( sizeof( * V_14 ) , V_9 ) ;
if ( V_14 == NULL )
return - V_10 ;
V_17 = F_1 ( V_14 , V_4 ) ;
if ( V_17 ) {
F_5 ( V_14 ) ;
return V_17 ;
}
F_9 ( & V_14 -> V_18 , V_13 ) ;
F_10 ( & V_14 -> V_18 ) ;
V_11 -> V_19 = & V_14 -> V_18 ;
#if F_2 ( V_15 )
if ( V_4 -> V_20 -> V_21 ) {
V_7 = F_11 ( & V_4 -> V_7 ) ;
if ( ! V_7 ) {
V_17 = - V_22 ;
goto V_23;
}
}
#endif
if ( V_4 -> V_24 && V_4 -> V_24 -> V_25 ) {
V_17 = V_4 -> V_24 -> V_25 ( V_4 , V_14 ) ;
if ( V_17 < 0 )
goto V_23;
}
return 0 ;
V_23:
#if F_2 ( V_15 )
if ( V_7 )
F_12 ( V_7 ) ;
#endif
F_13 ( & V_14 -> V_18 ) ;
F_14 ( & V_14 -> V_18 ) ;
F_4 ( V_14 ) ;
F_5 ( V_14 ) ;
return V_17 ;
}
static int F_15 ( struct V_11 * V_11 )
{
struct V_12 * V_13 = F_7 ( V_11 ) ;
struct V_3 * V_4 = F_8 ( V_13 ) ;
struct V_26 * V_18 = V_11 -> V_19 ;
struct V_1 * V_14 = F_16 ( V_18 ) ;
if ( V_4 -> V_24 && V_4 -> V_24 -> V_27 )
V_4 -> V_24 -> V_27 ( V_4 , V_14 ) ;
#if F_2 ( V_15 )
if ( V_4 -> V_20 -> V_21 )
F_12 ( & V_4 -> V_7 ) ;
#endif
F_13 ( V_18 ) ;
F_14 ( V_18 ) ;
F_4 ( V_14 ) ;
F_5 ( V_14 ) ;
V_11 -> V_19 = NULL ;
return 0 ;
}
static int F_17 ( struct V_3 * V_4 ,
struct V_28 * V_29 )
{
if ( V_29 -> V_30 != V_31 &&
V_29 -> V_30 != V_32 )
return - V_33 ;
if ( V_29 -> V_6 >= V_4 -> V_7 . V_8 )
return - V_33 ;
return 0 ;
}
static int F_18 ( struct V_3 * V_4 , struct V_34 * V_35 )
{
if ( V_35 -> V_30 != V_31 &&
V_35 -> V_30 != V_32 )
return - V_33 ;
if ( V_35 -> V_6 >= V_4 -> V_7 . V_8 )
return - V_33 ;
return 0 ;
}
static int F_19 ( struct V_3 * V_4 ,
struct V_36 * V_37 )
{
if ( V_37 -> V_30 != V_31 &&
V_37 -> V_30 != V_32 )
return - V_33 ;
if ( V_37 -> V_6 >= V_4 -> V_7 . V_8 )
return - V_33 ;
return 0 ;
}
static int F_20 ( struct V_3 * V_4 , struct V_38 * V_39 )
{
if ( V_39 -> V_6 >= V_4 -> V_7 . V_8 )
return - V_33 ;
if ( V_39 -> V_40 && V_39 -> V_39 == NULL )
return - V_33 ;
return 0 ;
}
static long F_21 ( struct V_11 * V_11 , unsigned int V_41 , void * V_42 )
{
struct V_12 * V_13 = F_7 ( V_11 ) ;
struct V_3 * V_4 = F_8 ( V_13 ) ;
struct V_26 * V_18 = V_11 -> V_19 ;
#if F_2 ( V_5 )
struct V_1 * V_14 = F_16 ( V_18 ) ;
int V_43 ;
#endif
switch ( V_41 ) {
case V_44 :
return F_22 ( V_18 -> V_45 , V_42 ) ;
case V_46 :
return F_23 ( V_18 -> V_45 , V_42 ) ;
case V_47 :
return F_24 ( V_18 -> V_45 , V_42 ) ;
case V_48 :
return F_25 ( V_18 -> V_45 , V_42 ) ;
case V_49 :
return F_26 ( V_18 , V_18 -> V_45 , V_42 ) ;
case V_50 :
return F_27 ( V_18 -> V_45 , V_42 ) ;
case V_51 :
return F_28 ( V_18 , V_18 -> V_45 , V_42 ) ;
case V_52 :
return F_29 ( V_18 -> V_45 , V_42 ) ;
case V_53 :
if ( ! ( V_4 -> V_54 & V_55 ) )
return - V_56 ;
return F_30 ( V_18 , V_42 , V_11 -> V_57 & V_58 ) ;
case V_59 :
return F_31 ( V_4 , V_60 , V_61 , V_18 , V_42 ) ;
case V_62 :
return F_31 ( V_4 , V_60 , V_63 , V_18 , V_42 ) ;
#ifdef F_32
case V_64 :
{
struct V_65 * V_66 = V_42 ;
if ( ! F_33 ( V_67 ) )
return - V_68 ;
return F_31 ( V_4 , V_60 , V_69 , V_66 ) ;
}
case V_70 :
{
struct V_65 * V_66 = V_42 ;
if ( ! F_33 ( V_67 ) )
return - V_68 ;
return F_31 ( V_4 , V_60 , V_71 , V_66 ) ;
}
#endif
case V_72 : {
int V_17 ;
F_34 ( L_1 ,
V_4 -> V_73 ) ;
V_17 = F_31 ( V_4 , V_60 , V_74 ) ;
F_34 ( L_2 ,
V_4 -> V_73 ) ;
return V_17 ;
}
#if F_2 ( V_5 )
case V_75 : {
struct V_28 * V_29 = V_42 ;
V_43 = F_17 ( V_4 , V_29 ) ;
if ( V_43 )
return V_43 ;
return F_31 ( V_4 , V_6 , V_76 , V_14 , V_29 ) ;
}
case V_77 : {
struct V_28 * V_29 = V_42 ;
V_43 = F_17 ( V_4 , V_29 ) ;
if ( V_43 )
return V_43 ;
return F_31 ( V_4 , V_6 , V_78 , V_14 , V_29 ) ;
}
case V_79 : {
struct V_34 * V_35 = V_42 ;
struct V_36 V_37 ;
V_43 = F_18 ( V_4 , V_35 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_31 ( V_4 , V_6 , V_80 , V_14 , V_35 ) ;
if ( V_43 != - V_56 )
return V_43 ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_30 = V_35 -> V_30 ;
V_37 . V_6 = V_35 -> V_6 ;
V_37 . V_81 = V_82 ;
V_43 = F_31 (
V_4 , V_6 , V_83 , V_14 , & V_37 ) ;
V_35 -> V_84 = V_37 . V_85 ;
return V_43 ;
}
case V_86 : {
struct V_34 * V_35 = V_42 ;
struct V_36 V_37 ;
V_43 = F_18 ( V_4 , V_35 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_31 ( V_4 , V_6 , V_87 , V_14 , V_35 ) ;
if ( V_43 != - V_56 )
return V_43 ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_30 = V_35 -> V_30 ;
V_37 . V_6 = V_35 -> V_6 ;
V_37 . V_81 = V_82 ;
V_37 . V_85 = V_35 -> V_84 ;
V_43 = F_31 (
V_4 , V_6 , V_88 , V_14 , & V_37 ) ;
V_35 -> V_84 = V_37 . V_85 ;
return V_43 ;
}
case V_89 : {
struct V_90 * V_91 = V_42 ;
if ( V_91 -> V_6 >= V_4 -> V_7 . V_8 )
return - V_33 ;
return F_31 ( V_4 , V_6 , V_92 , V_14 ,
V_91 ) ;
}
case V_93 : {
struct V_94 * V_95 = V_42 ;
if ( V_95 -> V_6 >= V_4 -> V_7 . V_8 )
return - V_33 ;
return F_31 ( V_4 , V_6 , V_96 , V_14 ,
V_95 ) ;
}
case V_97 : {
struct V_98 * V_99 = V_42 ;
if ( V_99 -> V_6 >= V_4 -> V_7 . V_8 )
return - V_33 ;
return F_31 ( V_4 , V_100 , V_101 , V_42 ) ;
}
case V_102 : {
struct V_98 * V_99 = V_42 ;
if ( V_99 -> V_6 >= V_4 -> V_7 . V_8 )
return - V_33 ;
return F_31 ( V_4 , V_100 , V_103 , V_42 ) ;
}
case V_104 : {
struct V_105 * V_106 = V_42 ;
if ( V_106 -> V_6 >= V_4 -> V_7 . V_8 )
return - V_33 ;
return F_31 ( V_4 , V_6 , V_107 , V_14 ,
V_106 ) ;
}
case V_108 : {
struct V_36 * V_37 = V_42 ;
V_43 = F_19 ( V_4 , V_37 ) ;
if ( V_43 )
return V_43 ;
return F_31 (
V_4 , V_6 , V_83 , V_14 , V_37 ) ;
}
case V_109 : {
struct V_36 * V_37 = V_42 ;
V_43 = F_19 ( V_4 , V_37 ) ;
if ( V_43 )
return V_43 ;
return F_31 (
V_4 , V_6 , V_88 , V_14 , V_37 ) ;
}
case V_110 : {
struct V_38 * V_39 = V_42 ;
V_43 = F_20 ( V_4 , V_39 ) ;
if ( V_43 )
return V_43 ;
return F_31 ( V_4 , V_6 , V_111 , V_39 ) ;
}
case V_112 : {
struct V_38 * V_39 = V_42 ;
V_43 = F_20 ( V_4 , V_39 ) ;
if ( V_43 )
return V_43 ;
return F_31 ( V_4 , V_6 , V_113 , V_39 ) ;
}
case V_114 : {
struct V_115 * V_116 = V_42 ;
if ( V_116 -> V_6 >= V_4 -> V_7 . V_8 )
return - V_33 ;
return F_31 ( V_4 , V_6 , V_117 , V_116 ) ;
}
case V_118 : {
struct V_119 * V_120 = V_42 ;
if ( V_120 -> V_6 >= V_4 -> V_7 . V_8 )
return - V_33 ;
return F_31 ( V_4 , V_6 , V_121 , V_120 ) ;
}
case V_122 :
return F_31 ( V_4 , V_100 , V_123 , V_42 ) ;
case V_124 :
return F_31 ( V_4 , V_100 , V_125 , V_42 ) ;
case V_126 :
return F_31 ( V_4 , V_100 , V_127 , V_42 ) ;
#endif
default:
return F_31 ( V_4 , V_60 , V_128 , V_41 , V_42 ) ;
}
return 0 ;
}
static long F_35 ( struct V_11 * V_11 , unsigned int V_41 ,
unsigned long V_42 )
{
return F_36 ( V_11 , V_41 , V_42 , F_21 ) ;
}
static long F_37 ( struct V_11 * V_11 , unsigned int V_41 ,
unsigned long V_42 )
{
struct V_12 * V_13 = F_7 ( V_11 ) ;
struct V_3 * V_4 = F_8 ( V_13 ) ;
return F_31 ( V_4 , V_60 , V_129 , V_41 , V_42 ) ;
}
static unsigned int F_38 ( struct V_11 * V_11 , T_1 * V_130 )
{
struct V_12 * V_13 = F_7 ( V_11 ) ;
struct V_3 * V_4 = F_8 ( V_13 ) ;
struct V_26 * V_2 = V_11 -> V_19 ;
if ( ! ( V_4 -> V_54 & V_55 ) )
return V_131 ;
F_39 ( V_11 , & V_2 -> V_130 , V_130 ) ;
if ( F_40 ( V_2 ) )
return V_132 ;
return 0 ;
}
int F_41 ( struct V_3 * V_4 ,
struct V_133 * V_134 ,
struct V_28 * V_135 ,
struct V_28 * V_136 )
{
if ( V_135 -> V_29 . V_137 != V_136 -> V_29 . V_137
|| V_135 -> V_29 . V_138 != V_136 -> V_29 . V_138
|| V_135 -> V_29 . V_91 != V_136 -> V_29 . V_91 )
return - V_33 ;
if ( V_135 -> V_29 . V_139 != V_136 -> V_29 . V_139 &&
V_136 -> V_29 . V_139 != V_140 )
return - V_33 ;
return 0 ;
}
static int
F_42 ( struct V_141 * V_6 ,
struct V_28 * V_142 )
{
if ( F_43 ( V_6 -> V_7 ) == V_143 ) {
struct V_3 * V_4 =
F_44 ( V_6 -> V_7 ) ;
V_142 -> V_30 = V_32 ;
V_142 -> V_6 = V_6 -> V_144 ;
return F_31 ( V_4 , V_6 , V_76 , NULL , V_142 ) ;
}
F_45 ( V_6 -> V_7 -> type != V_145 ,
L_3 ,
V_6 -> V_7 -> type , V_6 -> V_7 -> V_73 ) ;
return - V_33 ;
}
int F_46 ( struct V_133 * V_134 )
{
struct V_3 * V_146 ;
struct V_28 V_136 , V_135 ;
int V_43 ;
V_43 = F_42 (
V_134 -> V_147 , & V_135 ) ;
if ( V_43 < 0 )
return 0 ;
V_43 = F_42 (
V_134 -> V_146 , & V_136 ) ;
if ( V_43 < 0 )
return 0 ;
V_146 = F_44 ( V_134 -> V_146 -> V_7 ) ;
V_43 = F_31 ( V_146 , V_6 , V_148 , V_134 ,
& V_135 , & V_136 ) ;
if ( V_43 != - V_56 )
return V_43 ;
return F_41 (
V_146 , V_134 , & V_135 , & V_136 ) ;
}
void F_47 ( struct V_3 * V_4 , const struct V_149 * V_150 )
{
F_48 ( & V_4 -> V_151 ) ;
F_49 ( ! V_150 ) ;
V_4 -> V_150 = V_150 ;
V_4 -> V_20 = NULL ;
V_4 -> V_54 = 0 ;
V_4 -> V_73 [ 0 ] = '\0' ;
V_4 -> V_152 = 0 ;
V_4 -> V_153 = NULL ;
V_4 -> V_154 = NULL ;
#if F_2 ( V_15 )
V_4 -> V_7 . V_73 = V_4 -> V_73 ;
V_4 -> V_7 . type = V_143 ;
#endif
}
