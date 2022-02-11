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
static long F_17 ( struct V_11 * V_11 , unsigned int V_28 , void * V_29 )
{
struct V_12 * V_13 = F_7 ( V_11 ) ;
struct V_3 * V_4 = F_8 ( V_13 ) ;
struct V_26 * V_18 = V_11 -> V_19 ;
#if F_2 ( V_5 )
struct V_1 * V_14 = F_16 ( V_18 ) ;
#endif
switch ( V_28 ) {
case V_30 :
return F_18 ( V_18 -> V_31 , V_29 ) ;
case V_32 :
return F_19 ( V_18 -> V_31 , V_29 ) ;
case V_33 :
return F_20 ( V_18 -> V_31 , V_29 ) ;
case V_34 :
return F_21 ( V_18 , V_18 -> V_31 , V_29 ) ;
case V_35 :
return F_22 ( V_18 -> V_31 , V_29 ) ;
case V_36 :
return F_23 ( V_18 , V_18 -> V_31 , V_29 ) ;
case V_37 :
return F_24 ( V_18 -> V_31 , V_29 ) ;
case V_38 :
if ( ! ( V_4 -> V_39 & V_40 ) )
return - V_41 ;
return F_25 ( V_18 , V_29 , V_11 -> V_42 & V_43 ) ;
case V_44 :
return F_26 ( V_4 , V_45 , V_46 , V_18 , V_29 ) ;
case V_47 :
return F_26 ( V_4 , V_45 , V_48 , V_18 , V_29 ) ;
#ifdef F_27
case V_49 :
{
struct V_50 * V_51 = V_29 ;
if ( ! F_28 ( V_52 ) )
return - V_53 ;
return F_26 ( V_4 , V_45 , V_54 , V_51 ) ;
}
case V_55 :
{
struct V_50 * V_51 = V_29 ;
if ( ! F_28 ( V_52 ) )
return - V_53 ;
return F_26 ( V_4 , V_45 , V_56 , V_51 ) ;
}
#endif
case V_57 : {
int V_17 ;
F_29 ( L_1 ,
V_4 -> V_58 ) ;
V_17 = F_26 ( V_4 , V_45 , V_59 ) ;
F_29 ( L_2 ,
V_4 -> V_58 ) ;
return V_17 ;
}
#if F_2 ( V_5 )
case V_60 : {
struct V_61 * V_62 = V_29 ;
if ( V_62 -> V_63 != V_64 &&
V_62 -> V_63 != V_65 )
return - V_66 ;
if ( V_62 -> V_6 >= V_4 -> V_7 . V_8 )
return - V_66 ;
return F_26 ( V_4 , V_6 , V_67 , V_14 , V_62 ) ;
}
case V_68 : {
struct V_61 * V_62 = V_29 ;
if ( V_62 -> V_63 != V_64 &&
V_62 -> V_63 != V_65 )
return - V_66 ;
if ( V_62 -> V_6 >= V_4 -> V_7 . V_8 )
return - V_66 ;
return F_26 ( V_4 , V_6 , V_69 , V_14 , V_62 ) ;
}
case V_70 : {
struct V_71 * V_72 = V_29 ;
struct V_73 V_74 ;
int V_75 ;
if ( V_72 -> V_63 != V_64 &&
V_72 -> V_63 != V_65 )
return - V_66 ;
if ( V_72 -> V_6 >= V_4 -> V_7 . V_8 )
return - V_66 ;
V_75 = F_26 ( V_4 , V_6 , V_76 , V_14 , V_72 ) ;
if ( V_75 != - V_41 )
return V_75 ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_63 = V_72 -> V_63 ;
V_74 . V_6 = V_72 -> V_6 ;
V_74 . V_77 = V_78 ;
V_75 = F_26 (
V_4 , V_6 , V_79 , V_14 , & V_74 ) ;
V_72 -> V_80 = V_74 . V_81 ;
return V_75 ;
}
case V_82 : {
struct V_71 * V_72 = V_29 ;
struct V_73 V_74 ;
int V_75 ;
if ( V_72 -> V_63 != V_64 &&
V_72 -> V_63 != V_65 )
return - V_66 ;
if ( V_72 -> V_6 >= V_4 -> V_7 . V_8 )
return - V_66 ;
V_75 = F_26 ( V_4 , V_6 , V_83 , V_14 , V_72 ) ;
if ( V_75 != - V_41 )
return V_75 ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_63 = V_72 -> V_63 ;
V_74 . V_6 = V_72 -> V_6 ;
V_74 . V_77 = V_78 ;
V_74 . V_81 = V_72 -> V_80 ;
V_75 = F_26 (
V_4 , V_6 , V_84 , V_14 , & V_74 ) ;
V_72 -> V_80 = V_74 . V_81 ;
return V_75 ;
}
case V_85 : {
struct V_86 * V_87 = V_29 ;
if ( V_87 -> V_6 >= V_4 -> V_7 . V_8 )
return - V_66 ;
return F_26 ( V_4 , V_6 , V_88 , V_14 ,
V_87 ) ;
}
case V_89 : {
struct V_90 * V_91 = V_29 ;
if ( V_91 -> V_6 >= V_4 -> V_7 . V_8 )
return - V_66 ;
return F_26 ( V_4 , V_6 , V_92 , V_14 ,
V_91 ) ;
}
case V_93 : {
struct V_94 * V_95 = V_29 ;
if ( V_95 -> V_6 >= V_4 -> V_7 . V_8 )
return - V_66 ;
return F_26 ( V_4 , V_96 , V_97 , V_29 ) ;
}
case V_98 : {
struct V_94 * V_95 = V_29 ;
if ( V_95 -> V_6 >= V_4 -> V_7 . V_8 )
return - V_66 ;
return F_26 ( V_4 , V_96 , V_99 , V_29 ) ;
}
case V_100 : {
struct V_101 * V_102 = V_29 ;
if ( V_102 -> V_6 >= V_4 -> V_7 . V_8 )
return - V_66 ;
return F_26 ( V_4 , V_6 , V_103 , V_14 ,
V_102 ) ;
}
case V_104 : {
struct V_73 * V_74 = V_29 ;
if ( V_74 -> V_63 != V_64 &&
V_74 -> V_63 != V_65 )
return - V_66 ;
if ( V_74 -> V_6 >= V_4 -> V_7 . V_8 )
return - V_66 ;
return F_26 (
V_4 , V_6 , V_79 , V_14 , V_74 ) ;
}
case V_105 : {
struct V_73 * V_74 = V_29 ;
if ( V_74 -> V_63 != V_64 &&
V_74 -> V_63 != V_65 )
return - V_66 ;
if ( V_74 -> V_6 >= V_4 -> V_7 . V_8 )
return - V_66 ;
return F_26 (
V_4 , V_6 , V_84 , V_14 , V_74 ) ;
}
case V_106 : {
struct V_107 * V_108 = V_29 ;
if ( V_108 -> V_6 >= V_4 -> V_7 . V_8 )
return - V_66 ;
if ( V_108 -> V_109 && V_108 -> V_108 == NULL )
return - V_66 ;
return F_26 ( V_4 , V_6 , V_110 , V_108 ) ;
}
case V_111 : {
struct V_107 * V_108 = V_29 ;
if ( V_108 -> V_6 >= V_4 -> V_7 . V_8 )
return - V_66 ;
if ( V_108 -> V_109 && V_108 -> V_108 == NULL )
return - V_66 ;
return F_26 ( V_4 , V_6 , V_112 , V_108 ) ;
}
case V_113 : {
struct V_114 * V_115 = V_29 ;
if ( V_115 -> V_6 >= V_4 -> V_7 . V_8 )
return - V_66 ;
return F_26 ( V_4 , V_6 , V_116 , V_115 ) ;
}
case V_117 : {
struct V_118 * V_119 = V_29 ;
if ( V_119 -> V_6 >= V_4 -> V_7 . V_8 )
return - V_66 ;
return F_26 ( V_4 , V_6 , V_120 , V_119 ) ;
}
case V_121 :
return F_26 ( V_4 , V_96 , V_122 , V_29 ) ;
case V_123 :
return F_26 ( V_4 , V_96 , V_124 , V_29 ) ;
case V_125 :
return F_26 ( V_4 , V_96 , V_126 , V_29 ) ;
#endif
default:
return F_26 ( V_4 , V_45 , V_127 , V_28 , V_29 ) ;
}
return 0 ;
}
static long F_30 ( struct V_11 * V_11 , unsigned int V_28 ,
unsigned long V_29 )
{
return F_31 ( V_11 , V_28 , V_29 , F_17 ) ;
}
static long F_32 ( struct V_11 * V_11 , unsigned int V_28 ,
unsigned long V_29 )
{
struct V_12 * V_13 = F_7 ( V_11 ) ;
struct V_3 * V_4 = F_8 ( V_13 ) ;
return F_26 ( V_4 , V_45 , V_128 , V_28 , V_29 ) ;
}
static unsigned int F_33 ( struct V_11 * V_11 , T_1 * V_129 )
{
struct V_12 * V_13 = F_7 ( V_11 ) ;
struct V_3 * V_4 = F_8 ( V_13 ) ;
struct V_26 * V_2 = V_11 -> V_19 ;
if ( ! ( V_4 -> V_39 & V_40 ) )
return V_130 ;
F_34 ( V_11 , & V_2 -> V_129 , V_129 ) ;
if ( F_35 ( V_2 ) )
return V_131 ;
return 0 ;
}
int F_36 ( struct V_3 * V_4 ,
struct V_132 * V_133 ,
struct V_61 * V_134 ,
struct V_61 * V_135 )
{
if ( V_134 -> V_62 . V_136 != V_135 -> V_62 . V_136
|| V_134 -> V_62 . V_137 != V_135 -> V_62 . V_137
|| V_134 -> V_62 . V_87 != V_135 -> V_62 . V_87 )
return - V_66 ;
return 0 ;
}
static int
F_37 ( struct V_138 * V_6 ,
struct V_61 * V_139 )
{
if ( F_38 ( V_6 -> V_7 ) == V_140 ) {
struct V_3 * V_4 =
F_39 ( V_6 -> V_7 ) ;
V_139 -> V_63 = V_65 ;
V_139 -> V_6 = V_6 -> V_141 ;
return F_26 ( V_4 , V_6 , V_67 , NULL , V_139 ) ;
}
F_40 ( V_6 -> V_7 -> type != V_142 ,
L_3 ,
V_6 -> V_7 -> type , V_6 -> V_7 -> V_58 ) ;
return - V_66 ;
}
int F_41 ( struct V_132 * V_133 )
{
struct V_3 * V_143 ;
struct V_61 V_135 , V_134 ;
int V_75 ;
V_75 = F_37 (
V_133 -> V_144 , & V_134 ) ;
if ( V_75 < 0 )
return 0 ;
V_75 = F_37 (
V_133 -> V_143 , & V_135 ) ;
if ( V_75 < 0 )
return 0 ;
V_143 = F_39 ( V_133 -> V_143 -> V_7 ) ;
V_75 = F_26 ( V_143 , V_6 , V_145 , V_133 ,
& V_134 , & V_135 ) ;
if ( V_75 != - V_41 )
return V_75 ;
return F_36 (
V_143 , V_133 , & V_134 , & V_135 ) ;
}
void F_42 ( struct V_3 * V_4 , const struct V_146 * V_147 )
{
F_43 ( & V_4 -> V_148 ) ;
F_44 ( ! V_147 ) ;
V_4 -> V_147 = V_147 ;
V_4 -> V_20 = NULL ;
V_4 -> V_39 = 0 ;
V_4 -> V_58 [ 0 ] = '\0' ;
V_4 -> V_149 = 0 ;
V_4 -> V_150 = NULL ;
V_4 -> V_151 = NULL ;
#if F_2 ( V_15 )
V_4 -> V_7 . V_58 = V_4 -> V_58 ;
V_4 -> V_7 . type = V_140 ;
#endif
}
