static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_8 & ( 1 << V_3 ) )
return V_6 -> V_9 -> V_10 ( V_6 , V_3 , V_4 ) ;
return 0xffff ;
}
static int F_2 ( struct V_1 * V_2 , int V_3 , int V_4 , T_1 V_11 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_8 & ( 1 << V_3 ) )
return V_6 -> V_9 -> V_12 ( V_6 , V_3 , V_4 , V_11 ) ;
return 0 ;
}
void F_3 ( struct V_5 * V_6 )
{
V_6 -> V_13 -> V_7 = ( void * ) V_6 ;
V_6 -> V_13 -> V_14 = L_1 ;
V_6 -> V_13 -> V_15 = F_1 ;
V_6 -> V_13 -> V_16 = F_2 ;
snprintf ( V_6 -> V_13 -> V_17 , V_18 , L_2 ,
V_6 -> V_19 , V_6 -> V_20 -> V_21 ) ;
V_6 -> V_13 -> V_22 = V_6 -> V_23 ;
V_6 -> V_13 -> V_24 = ~ V_6 -> V_8 ;
}
static int F_4 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
V_26 -> V_29 = V_28 -> V_22 -> V_30 -> V_31 -> V_32 ;
return 0 ;
}
static int F_6 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_25 * V_33 = V_28 -> V_22 -> V_30 -> V_31 ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_34 ;
if ( ! ( V_33 -> V_35 & V_36 ) )
return - V_37 ;
if ( ! F_7 ( V_26 -> V_38 , V_33 -> V_38 ) ) {
V_34 = F_8 ( V_33 , V_26 -> V_38 ) ;
if ( V_34 < 0 )
goto V_39;
}
if ( V_26 -> V_35 & V_40 ) {
V_34 = F_9 ( V_33 , 1 ) ;
if ( V_34 < 0 )
goto V_41;
}
if ( V_26 -> V_35 & V_42 ) {
V_34 = F_10 ( V_33 , 1 ) ;
if ( V_34 < 0 )
goto V_43;
}
if ( V_6 -> V_9 -> V_44 ) {
V_34 = V_6 -> V_9 -> V_44 ( V_6 , V_28 -> V_45 , V_28 -> V_46 ) ;
if ( V_34 )
goto V_47;
}
if ( V_28 -> V_46 )
F_11 ( V_28 -> V_46 ) ;
return 0 ;
V_47:
if ( V_26 -> V_35 & V_42 )
F_10 ( V_33 , 0 ) ;
V_43:
if ( V_26 -> V_35 & V_40 )
F_9 ( V_33 , - 1 ) ;
V_41:
if ( ! F_7 ( V_26 -> V_38 , V_33 -> V_38 ) )
F_12 ( V_33 , V_26 -> V_38 ) ;
V_39:
return V_34 ;
}
static int F_13 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_25 * V_33 = V_28 -> V_22 -> V_30 -> V_31 ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_28 -> V_46 )
F_14 ( V_28 -> V_46 ) ;
F_15 ( V_33 , V_26 ) ;
F_16 ( V_33 , V_26 ) ;
if ( V_26 -> V_35 & V_40 )
F_9 ( V_33 , - 1 ) ;
if ( V_26 -> V_35 & V_42 )
F_10 ( V_33 , - 1 ) ;
if ( ! F_7 ( V_26 -> V_38 , V_33 -> V_38 ) )
F_12 ( V_33 , V_26 -> V_38 ) ;
if ( V_6 -> V_9 -> V_48 )
V_6 -> V_9 -> V_48 ( V_6 , V_28 -> V_45 , V_28 -> V_46 ) ;
return 0 ;
}
static void F_17 ( struct V_25 * V_26 , int V_49 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_25 * V_33 = V_28 -> V_22 -> V_30 -> V_31 ;
if ( V_49 & V_40 )
F_9 ( V_33 , V_26 -> V_35 & V_40 ? 1 : - 1 ) ;
if ( V_49 & V_42 )
F_10 ( V_33 , V_26 -> V_35 & V_42 ? 1 : - 1 ) ;
}
static void F_18 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_25 * V_33 = V_28 -> V_22 -> V_30 -> V_31 ;
F_19 ( V_33 , V_26 ) ;
F_20 ( V_33 , V_26 ) ;
}
static int F_21 ( struct V_25 * V_26 , void * V_50 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_25 * V_33 = V_28 -> V_22 -> V_30 -> V_31 ;
struct V_51 * V_3 = V_50 ;
int V_34 ;
if ( ! F_22 ( V_3 -> V_52 ) )
return - V_53 ;
if ( ! ( V_26 -> V_35 & V_36 ) )
goto V_39;
if ( ! F_7 ( V_3 -> V_52 , V_33 -> V_38 ) ) {
V_34 = F_8 ( V_33 , V_3 -> V_52 ) ;
if ( V_34 < 0 )
return V_34 ;
}
if ( ! F_7 ( V_26 -> V_38 , V_33 -> V_38 ) )
F_12 ( V_33 , V_26 -> V_38 ) ;
V_39:
F_23 ( V_26 -> V_38 , V_3 -> V_52 ) ;
return 0 ;
}
static int F_24 ( struct V_25 * V_26 , struct V_54 * V_55 , int V_56 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
if ( V_28 -> V_46 != NULL )
return F_25 ( V_28 -> V_46 , V_55 , V_56 ) ;
return - V_57 ;
}
static T_2 F_26 ( struct V_58 * V_59 , struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
return V_28 -> V_60 ( V_59 , V_26 ) ;
}
static T_2 F_27 ( struct V_58 * V_59 ,
struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
V_59 -> V_26 = V_28 -> V_22 -> V_30 -> V_31 ;
F_28 ( V_59 ) ;
return V_61 ;
}
static int
F_29 ( struct V_25 * V_26 , struct V_62 * V_56 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
int V_34 ;
V_34 = - V_57 ;
if ( V_28 -> V_46 != NULL ) {
V_34 = F_30 ( V_28 -> V_46 ) ;
if ( V_34 == 0 )
V_34 = F_31 ( V_28 -> V_46 , V_56 ) ;
}
return V_34 ;
}
static int
F_32 ( struct V_25 * V_26 , struct V_62 * V_56 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
if ( V_28 -> V_46 != NULL )
return F_33 ( V_28 -> V_46 , V_56 ) ;
return - V_57 ;
}
static void F_34 ( struct V_25 * V_26 ,
struct V_63 * V_64 )
{
F_35 ( V_64 -> V_65 , L_3 , sizeof( V_64 -> V_65 ) ) ;
F_35 ( V_64 -> V_66 , V_67 , sizeof( V_64 -> V_66 ) ) ;
F_35 ( V_64 -> V_68 , L_4 , sizeof( V_64 -> V_68 ) ) ;
F_35 ( V_64 -> V_69 , L_5 , sizeof( V_64 -> V_69 ) ) ;
}
static int F_36 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_70 )
return V_6 -> V_9 -> V_70 ( V_6 , V_28 -> V_45 ) ;
return - V_57 ;
}
static void
F_37 ( struct V_25 * V_26 , struct V_71 * V_72 , void * V_73 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_74 )
V_6 -> V_9 -> V_74 ( V_6 , V_28 -> V_45 , V_72 , V_73 ) ;
}
static int F_38 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
if ( V_28 -> V_46 != NULL )
return F_39 ( V_28 -> V_46 ) ;
return - V_57 ;
}
static T_3 F_40 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
if ( V_28 -> V_46 != NULL ) {
F_41 ( V_28 -> V_46 ) ;
return V_28 -> V_46 -> V_75 ;
}
return - V_57 ;
}
static int F_42 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_20 -> V_76 )
return V_6 -> V_20 -> V_76 ;
if ( V_6 -> V_9 -> V_77 )
return V_6 -> V_9 -> V_77 ( V_6 ) ;
return 0 ;
}
static int F_43 ( struct V_25 * V_26 ,
struct V_78 * V_79 , T_4 * V_80 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_81 )
return V_6 -> V_9 -> V_81 ( V_6 , V_79 , V_80 ) ;
return - V_57 ;
}
static int F_44 ( struct V_25 * V_26 ,
struct V_78 * V_79 , T_4 * V_80 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_82 )
return V_6 -> V_9 -> V_82 ( V_6 , V_79 , V_80 ) ;
return - V_57 ;
}
static void F_45 ( struct V_25 * V_26 ,
T_5 V_83 , T_6 * V_80 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_83 == V_84 ) {
int V_85 = V_86 ;
strncpy ( V_80 , L_6 , V_85 ) ;
strncpy ( V_80 + V_85 , L_7 , V_85 ) ;
strncpy ( V_80 + 2 * V_85 , L_8 , V_85 ) ;
strncpy ( V_80 + 3 * V_85 , L_9 , V_85 ) ;
if ( V_6 -> V_9 -> V_87 != NULL )
V_6 -> V_9 -> V_87 ( V_6 , V_28 -> V_45 , V_80 + 4 * V_85 ) ;
}
}
static void F_46 ( struct V_25 * V_26 ,
struct V_88 * V_89 ,
T_7 * V_80 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
V_80 [ 0 ] = V_28 -> V_26 -> V_89 . V_90 ;
V_80 [ 1 ] = V_28 -> V_26 -> V_89 . V_91 ;
V_80 [ 2 ] = V_28 -> V_26 -> V_89 . V_92 ;
V_80 [ 3 ] = V_28 -> V_26 -> V_89 . V_93 ;
if ( V_6 -> V_9 -> V_94 != NULL )
V_6 -> V_9 -> V_94 ( V_6 , V_28 -> V_45 , V_80 + 4 ) ;
}
static int F_47 ( struct V_25 * V_26 , int V_95 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_95 == V_84 ) {
int V_96 ;
V_96 = 4 ;
if ( V_6 -> V_9 -> V_97 != NULL )
V_96 += V_6 -> V_9 -> V_97 ( V_6 ) ;
return V_96 ;
}
return - V_57 ;
}
static void F_48 ( struct V_25 * V_26 , struct V_98 * V_99 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_100 )
V_6 -> V_9 -> V_100 ( V_6 , V_28 -> V_45 , V_99 ) ;
}
static int F_49 ( struct V_25 * V_26 , struct V_98 * V_99 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_101 = - V_57 ;
if ( V_6 -> V_9 -> V_102 )
V_101 = V_6 -> V_9 -> V_102 ( V_6 , V_28 -> V_45 , V_99 ) ;
return V_101 ;
}
static int F_50 ( struct V_25 * V_26 , struct V_103 * V_104 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_101 ;
if ( ! V_6 -> V_9 -> V_105 )
return - V_57 ;
V_101 = V_6 -> V_9 -> V_105 ( V_6 , V_28 -> V_45 , V_28 -> V_46 , V_104 ) ;
if ( V_101 )
return V_101 ;
if ( V_28 -> V_46 )
V_101 = F_51 ( V_28 -> V_46 , V_104 ) ;
return V_101 ;
}
static int F_52 ( struct V_25 * V_26 , struct V_103 * V_104 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_101 ;
if ( ! V_6 -> V_9 -> V_106 )
return - V_57 ;
V_101 = V_6 -> V_9 -> V_106 ( V_6 , V_28 -> V_45 , V_104 ) ;
if ( V_101 )
return V_101 ;
if ( V_28 -> V_46 )
V_101 = F_53 ( V_28 -> V_46 , V_104 ) ;
return V_101 ;
}
static void F_54 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
unsigned int V_107 = 0 ;
if ( V_28 -> V_108 != V_28 -> V_46 -> V_75 ) {
V_107 = 1 ;
V_28 -> V_108 = V_28 -> V_46 -> V_75 ;
}
if ( V_28 -> V_109 != V_28 -> V_46 -> V_110 ) {
V_107 = 1 ;
V_28 -> V_109 = V_28 -> V_46 -> V_110 ;
}
if ( V_28 -> V_111 != V_28 -> V_46 -> V_112 ) {
V_107 = 1 ;
V_28 -> V_111 = V_28 -> V_46 -> V_112 ;
}
if ( V_6 -> V_9 -> V_113 && V_107 )
V_6 -> V_9 -> V_113 ( V_6 , V_28 -> V_45 , V_28 -> V_46 ) ;
if ( V_107 )
F_55 ( V_28 -> V_46 ) ;
}
static int F_56 ( struct V_25 * V_26 ,
struct V_114 * V_115 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_116 )
V_6 -> V_9 -> V_116 ( V_6 , V_28 -> V_45 , V_115 ) ;
return 0 ;
}
static int F_57 ( struct V_27 * V_28 ,
struct V_25 * V_117 )
{
struct V_5 * V_6 = V_28 -> V_22 ;
struct V_118 * V_119 = V_6 -> V_20 ;
struct V_120 * V_121 , * V_122 ;
bool V_123 = false ;
T_3 V_124 = 0 ;
int V_101 ;
V_122 = V_119 -> V_122 [ V_28 -> V_45 ] ;
V_28 -> V_125 = F_58 ( V_122 ) ;
V_121 = F_59 ( V_122 , L_10 , 0 ) ;
if ( F_60 ( V_122 ) ) {
V_101 = F_61 ( V_122 ) ;
if ( V_101 ) {
F_62 ( V_117 , L_11 ) ;
return V_101 ;
}
V_123 = true ;
V_121 = V_122 ;
}
if ( V_6 -> V_9 -> V_126 )
V_124 = V_6 -> V_9 -> V_126 ( V_6 , V_28 -> V_45 ) ;
if ( V_121 )
V_28 -> V_46 = F_63 ( V_117 , V_121 ,
F_54 , V_124 ,
V_28 -> V_125 ) ;
if ( V_28 -> V_46 && V_123 )
F_64 ( V_28 -> V_46 , F_56 ) ;
if ( ! V_28 -> V_46 ) {
V_28 -> V_46 = V_6 -> V_13 -> V_127 [ V_28 -> V_45 ] ;
if ( ! V_28 -> V_46 )
return - V_128 ;
F_65 ( V_117 , V_28 -> V_46 , F_54 ,
V_28 -> V_125 ) ;
} else {
F_66 ( V_117 , L_12 ,
V_28 -> V_46 -> V_3 , V_28 -> V_46 -> V_9 -> V_14 ) ;
}
return 0 ;
}
int F_67 ( struct V_25 * V_117 )
{
struct V_27 * V_28 = F_5 ( V_117 ) ;
F_68 ( V_117 ) ;
if ( V_28 -> V_46 ) {
F_14 ( V_28 -> V_46 ) ;
V_28 -> V_111 = - 1 ;
V_28 -> V_108 = - 1 ;
V_28 -> V_109 = - 1 ;
F_69 ( V_28 -> V_46 ) ;
}
return 0 ;
}
int F_70 ( struct V_25 * V_117 )
{
struct V_27 * V_28 = F_5 ( V_117 ) ;
F_71 ( V_117 ) ;
if ( V_28 -> V_46 ) {
F_72 ( V_28 -> V_46 ) ;
F_11 ( V_28 -> V_46 ) ;
}
return 0 ;
}
struct V_25 *
F_73 ( struct V_5 * V_6 , struct V_129 * V_22 ,
int V_45 , char * V_14 )
{
struct V_25 * V_33 = V_6 -> V_30 -> V_31 ;
struct V_25 * V_117 ;
struct V_27 * V_28 ;
int V_101 ;
V_117 = F_74 ( sizeof( struct V_27 ) , V_14 ,
V_130 , V_131 ) ;
if ( V_117 == NULL )
return V_117 ;
V_117 -> V_132 = V_33 -> V_133 ;
V_117 -> V_134 = & V_135 ;
F_75 ( V_117 , V_33 ) ;
V_117 -> V_136 = 0 ;
V_117 -> V_137 = & V_138 ;
F_76 ( V_117 , V_22 ) ;
V_117 -> V_26 . V_139 = V_6 -> V_20 -> V_122 [ V_45 ] ;
V_117 -> V_133 = V_33 -> V_133 ;
V_28 = F_5 ( V_117 ) ;
V_28 -> V_26 = V_117 ;
V_28 -> V_22 = V_6 ;
V_28 -> V_45 = V_45 ;
switch ( V_6 -> V_30 -> V_140 ) {
#ifdef F_77
case V_141 :
V_28 -> V_60 = V_142 . V_60 ;
break;
#endif
#ifdef F_78
case V_143 :
V_28 -> V_60 = V_144 . V_60 ;
break;
#endif
#ifdef F_79
case V_145 :
V_28 -> V_60 = V_146 . V_60 ;
break;
#endif
#ifdef F_80
case V_147 :
V_28 -> V_60 = V_148 . V_60 ;
break;
#endif
default:
V_28 -> V_60 = F_27 ;
break;
}
V_28 -> V_111 = - 1 ;
V_28 -> V_108 = - 1 ;
V_28 -> V_109 = - 1 ;
V_101 = F_57 ( V_28 , V_117 ) ;
if ( V_101 ) {
F_81 ( V_117 ) ;
return NULL ;
}
V_101 = F_82 ( V_117 ) ;
if ( V_101 ) {
F_62 ( V_33 , L_13 ,
V_101 , V_117 -> V_14 ) ;
F_83 ( V_28 -> V_46 ) ;
F_81 ( V_117 ) ;
return NULL ;
}
F_84 ( V_117 ) ;
if ( V_28 -> V_46 != NULL ) {
if ( V_6 -> V_9 -> V_126 )
V_28 -> V_46 -> V_149 |= V_6 -> V_9 -> V_126 ( V_6 , V_45 ) ;
F_85 ( V_117 , F_86 ( & V_28 -> V_46 -> V_26 ) ,
V_150 ) ;
V_28 -> V_46 -> V_151 = V_152 ;
V_28 -> V_46 -> V_153 = 0 ;
V_28 -> V_46 -> V_110 = 0 ;
V_28 -> V_46 -> V_154 = V_28 -> V_46 -> V_155 | V_156 ;
}
return V_117 ;
}
