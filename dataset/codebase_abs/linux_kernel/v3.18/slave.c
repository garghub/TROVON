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
}
static int F_4 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_5 ( V_25 ) ;
V_25 -> V_28 = V_27 -> V_22 -> V_29 -> V_30 -> V_31 ;
return 0 ;
}
static int F_6 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_5 ( V_25 ) ;
struct V_24 * V_32 = V_27 -> V_22 -> V_29 -> V_30 ;
struct V_5 * V_6 = V_27 -> V_22 ;
int V_33 ;
if ( ! ( V_32 -> V_34 & V_35 ) )
return - V_36 ;
if ( ! F_7 ( V_25 -> V_37 , V_32 -> V_37 ) ) {
V_33 = F_8 ( V_32 , V_25 -> V_37 ) ;
if ( V_33 < 0 )
goto V_38;
}
if ( V_25 -> V_34 & V_39 ) {
V_33 = F_9 ( V_32 , 1 ) ;
if ( V_33 < 0 )
goto V_40;
}
if ( V_25 -> V_34 & V_41 ) {
V_33 = F_10 ( V_32 , 1 ) ;
if ( V_33 < 0 )
goto V_42;
}
if ( V_6 -> V_9 -> V_43 ) {
V_33 = V_6 -> V_9 -> V_43 ( V_6 , V_27 -> V_44 , V_27 -> V_45 ) ;
if ( V_33 )
goto V_46;
}
if ( V_27 -> V_45 )
F_11 ( V_27 -> V_45 ) ;
return 0 ;
V_46:
if ( V_25 -> V_34 & V_41 )
F_10 ( V_32 , 0 ) ;
V_42:
if ( V_25 -> V_34 & V_39 )
F_9 ( V_32 , - 1 ) ;
V_40:
if ( ! F_7 ( V_25 -> V_37 , V_32 -> V_37 ) )
F_12 ( V_32 , V_25 -> V_37 ) ;
V_38:
return V_33 ;
}
static int F_13 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_5 ( V_25 ) ;
struct V_24 * V_32 = V_27 -> V_22 -> V_29 -> V_30 ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_27 -> V_45 )
F_14 ( V_27 -> V_45 ) ;
F_15 ( V_32 , V_25 ) ;
F_16 ( V_32 , V_25 ) ;
if ( V_25 -> V_34 & V_39 )
F_9 ( V_32 , - 1 ) ;
if ( V_25 -> V_34 & V_41 )
F_10 ( V_32 , - 1 ) ;
if ( ! F_7 ( V_25 -> V_37 , V_32 -> V_37 ) )
F_12 ( V_32 , V_25 -> V_37 ) ;
if ( V_6 -> V_9 -> V_47 )
V_6 -> V_9 -> V_47 ( V_6 , V_27 -> V_44 , V_27 -> V_45 ) ;
return 0 ;
}
static void F_17 ( struct V_24 * V_25 , int V_48 )
{
struct V_26 * V_27 = F_5 ( V_25 ) ;
struct V_24 * V_32 = V_27 -> V_22 -> V_29 -> V_30 ;
if ( V_48 & V_39 )
F_9 ( V_32 , V_25 -> V_34 & V_39 ? 1 : - 1 ) ;
if ( V_48 & V_41 )
F_10 ( V_32 , V_25 -> V_34 & V_41 ? 1 : - 1 ) ;
}
static void F_18 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_5 ( V_25 ) ;
struct V_24 * V_32 = V_27 -> V_22 -> V_29 -> V_30 ;
F_19 ( V_32 , V_25 ) ;
F_20 ( V_32 , V_25 ) ;
}
static int F_21 ( struct V_24 * V_25 , void * V_49 )
{
struct V_26 * V_27 = F_5 ( V_25 ) ;
struct V_24 * V_32 = V_27 -> V_22 -> V_29 -> V_30 ;
struct V_50 * V_3 = V_49 ;
int V_33 ;
if ( ! F_22 ( V_3 -> V_51 ) )
return - V_52 ;
if ( ! ( V_25 -> V_34 & V_35 ) )
goto V_38;
if ( ! F_7 ( V_3 -> V_51 , V_32 -> V_37 ) ) {
V_33 = F_8 ( V_32 , V_3 -> V_51 ) ;
if ( V_33 < 0 )
return V_33 ;
}
if ( ! F_7 ( V_25 -> V_37 , V_32 -> V_37 ) )
F_12 ( V_32 , V_25 -> V_37 ) ;
V_38:
F_23 ( V_25 -> V_37 , V_3 -> V_51 ) ;
return 0 ;
}
static int F_24 ( struct V_24 * V_25 , struct V_53 * V_54 , int V_55 )
{
struct V_26 * V_27 = F_5 ( V_25 ) ;
if ( V_27 -> V_45 != NULL )
return F_25 ( V_27 -> V_45 , V_54 , V_55 ) ;
return - V_56 ;
}
static T_2 F_26 ( struct V_57 * V_58 , struct V_24 * V_25 )
{
struct V_26 * V_27 = F_5 ( V_25 ) ;
return V_27 -> V_59 ( V_58 , V_25 ) ;
}
static T_2 F_27 ( struct V_57 * V_58 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = F_5 ( V_25 ) ;
V_58 -> V_25 = V_27 -> V_22 -> V_29 -> V_30 ;
F_28 ( V_58 ) ;
return V_60 ;
}
static int
F_29 ( struct V_24 * V_25 , struct V_61 * V_55 )
{
struct V_26 * V_27 = F_5 ( V_25 ) ;
int V_33 ;
V_33 = - V_56 ;
if ( V_27 -> V_45 != NULL ) {
V_33 = F_30 ( V_27 -> V_45 ) ;
if ( V_33 == 0 )
V_33 = F_31 ( V_27 -> V_45 , V_55 ) ;
}
return V_33 ;
}
static int
F_32 ( struct V_24 * V_25 , struct V_61 * V_55 )
{
struct V_26 * V_27 = F_5 ( V_25 ) ;
if ( V_27 -> V_45 != NULL )
return F_33 ( V_27 -> V_45 , V_55 ) ;
return - V_56 ;
}
static void F_34 ( struct V_24 * V_25 ,
struct V_62 * V_63 )
{
F_35 ( V_63 -> V_64 , L_3 , sizeof( V_63 -> V_64 ) ) ;
F_35 ( V_63 -> V_65 , V_66 , sizeof( V_63 -> V_65 ) ) ;
F_35 ( V_63 -> V_67 , L_4 , sizeof( V_63 -> V_67 ) ) ;
F_35 ( V_63 -> V_68 , L_5 , sizeof( V_63 -> V_68 ) ) ;
}
static int F_36 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_5 ( V_25 ) ;
if ( V_27 -> V_45 != NULL )
return F_37 ( V_27 -> V_45 ) ;
return - V_56 ;
}
static T_3 F_38 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_5 ( V_25 ) ;
if ( V_27 -> V_45 != NULL ) {
F_39 ( V_27 -> V_45 ) ;
return V_27 -> V_45 -> V_69 ;
}
return - V_56 ;
}
static void F_40 ( struct V_24 * V_25 ,
T_4 V_70 , T_5 * V_71 )
{
struct V_26 * V_27 = F_5 ( V_25 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_70 == V_72 ) {
int V_73 = V_74 ;
strncpy ( V_71 , L_6 , V_73 ) ;
strncpy ( V_71 + V_73 , L_7 , V_73 ) ;
strncpy ( V_71 + 2 * V_73 , L_8 , V_73 ) ;
strncpy ( V_71 + 3 * V_73 , L_9 , V_73 ) ;
if ( V_6 -> V_9 -> V_75 != NULL )
V_6 -> V_9 -> V_75 ( V_6 , V_27 -> V_44 , V_71 + 4 * V_73 ) ;
}
}
static void F_41 ( struct V_24 * V_25 ,
struct V_76 * V_77 ,
T_6 * V_71 )
{
struct V_26 * V_27 = F_5 ( V_25 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
V_71 [ 0 ] = V_27 -> V_25 -> V_77 . V_78 ;
V_71 [ 1 ] = V_27 -> V_25 -> V_77 . V_79 ;
V_71 [ 2 ] = V_27 -> V_25 -> V_77 . V_80 ;
V_71 [ 3 ] = V_27 -> V_25 -> V_77 . V_81 ;
if ( V_6 -> V_9 -> V_82 != NULL )
V_6 -> V_9 -> V_82 ( V_6 , V_27 -> V_44 , V_71 + 4 ) ;
}
static int F_42 ( struct V_24 * V_25 , int V_83 )
{
struct V_26 * V_27 = F_5 ( V_25 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_83 == V_72 ) {
int V_84 ;
V_84 = 4 ;
if ( V_6 -> V_9 -> V_85 != NULL )
V_84 += V_6 -> V_9 -> V_85 ( V_6 ) ;
return V_84 ;
}
return - V_56 ;
}
static void F_43 ( struct V_24 * V_25 , struct V_86 * V_87 )
{
struct V_26 * V_27 = F_5 ( V_25 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_88 )
V_6 -> V_9 -> V_88 ( V_6 , V_27 -> V_44 , V_87 ) ;
}
static int F_44 ( struct V_24 * V_25 , struct V_86 * V_87 )
{
struct V_26 * V_27 = F_5 ( V_25 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
int V_89 = - V_56 ;
if ( V_6 -> V_9 -> V_90 )
V_89 = V_6 -> V_9 -> V_90 ( V_6 , V_27 -> V_44 , V_87 ) ;
return V_89 ;
}
static int F_45 ( struct V_24 * V_25 , struct V_91 * V_92 )
{
struct V_26 * V_27 = F_5 ( V_25 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
int V_89 ;
if ( ! V_6 -> V_9 -> V_93 )
return - V_56 ;
V_89 = V_6 -> V_9 -> V_93 ( V_6 , V_27 -> V_44 , V_27 -> V_45 , V_92 ) ;
if ( V_89 )
return V_89 ;
if ( V_27 -> V_45 )
V_89 = F_46 ( V_27 -> V_45 , V_92 ) ;
return V_89 ;
}
static int F_47 ( struct V_24 * V_25 , struct V_91 * V_92 )
{
struct V_26 * V_27 = F_5 ( V_25 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
int V_89 ;
if ( ! V_6 -> V_9 -> V_94 )
return - V_56 ;
V_89 = V_6 -> V_9 -> V_94 ( V_6 , V_27 -> V_44 , V_92 ) ;
if ( V_89 )
return V_89 ;
if ( V_27 -> V_45 )
V_89 = F_48 ( V_27 -> V_45 , V_92 ) ;
return V_89 ;
}
static void F_49 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_5 ( V_25 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
unsigned int V_95 = 0 ;
if ( V_27 -> V_96 != V_27 -> V_45 -> V_69 ) {
V_95 = 1 ;
V_27 -> V_96 = V_27 -> V_45 -> V_69 ;
}
if ( V_27 -> V_97 != V_27 -> V_45 -> V_98 ) {
V_95 = 1 ;
V_27 -> V_97 = V_27 -> V_45 -> V_98 ;
}
if ( V_27 -> V_99 != V_27 -> V_45 -> V_100 ) {
V_95 = 1 ;
V_27 -> V_99 = V_27 -> V_45 -> V_100 ;
}
if ( V_6 -> V_9 -> V_101 && V_95 )
V_6 -> V_9 -> V_101 ( V_6 , V_27 -> V_44 , V_27 -> V_45 ) ;
if ( V_95 )
F_50 ( V_27 -> V_45 ) ;
}
static int F_51 ( struct V_24 * V_25 ,
struct V_102 * V_103 )
{
struct V_26 * V_27 = F_5 ( V_25 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_104 )
V_6 -> V_9 -> V_104 ( V_6 , V_27 -> V_44 , V_103 ) ;
return 0 ;
}
static void F_52 ( struct V_26 * V_27 ,
struct V_24 * V_105 )
{
struct V_5 * V_6 = V_27 -> V_22 ;
struct V_106 * V_107 = V_6 -> V_20 ;
struct V_108 * V_109 , * V_110 ;
bool V_111 = false ;
T_3 V_112 = 0 ;
int V_89 ;
V_110 = V_107 -> V_110 [ V_27 -> V_44 ] ;
V_27 -> V_113 = F_53 ( V_110 ) ;
V_109 = F_54 ( V_110 , L_10 , 0 ) ;
if ( F_55 ( V_110 ) ) {
V_89 = F_56 ( V_110 ) ;
if ( V_89 ) {
F_57 ( L_11 ) ;
return;
}
V_111 = true ;
V_109 = V_110 ;
}
if ( V_6 -> V_9 -> V_114 )
V_112 = V_6 -> V_9 -> V_114 ( V_6 , V_27 -> V_44 ) ;
if ( V_109 )
V_27 -> V_45 = F_58 ( V_105 , V_109 ,
F_49 , V_112 ,
V_27 -> V_113 ) ;
if ( V_27 -> V_45 && V_111 )
F_59 ( V_27 -> V_45 , F_51 ) ;
if ( ! V_27 -> V_45 ) {
V_27 -> V_45 = V_6 -> V_13 -> V_115 [ V_27 -> V_44 ] ;
F_60 ( V_105 , V_27 -> V_45 , F_49 ,
V_27 -> V_113 ) ;
} else {
F_61 ( L_12 ,
V_27 -> V_45 -> V_3 , V_27 -> V_45 -> V_9 -> V_14 ) ;
}
}
int F_62 ( struct V_24 * V_105 )
{
struct V_26 * V_27 = F_5 ( V_105 ) ;
F_63 ( V_105 ) ;
if ( V_27 -> V_45 ) {
F_14 ( V_27 -> V_45 ) ;
V_27 -> V_99 = - 1 ;
V_27 -> V_96 = - 1 ;
V_27 -> V_97 = - 1 ;
F_64 ( V_27 -> V_45 ) ;
}
return 0 ;
}
int F_65 ( struct V_24 * V_105 )
{
struct V_26 * V_27 = F_5 ( V_105 ) ;
F_66 ( V_105 ) ;
if ( V_27 -> V_45 ) {
F_67 ( V_27 -> V_45 ) ;
F_11 ( V_27 -> V_45 ) ;
}
return 0 ;
}
struct V_24 *
F_68 ( struct V_5 * V_6 , struct V_116 * V_22 ,
int V_44 , char * V_14 )
{
struct V_24 * V_32 = V_6 -> V_29 -> V_30 ;
struct V_24 * V_105 ;
struct V_26 * V_27 ;
int V_89 ;
V_105 = F_69 ( sizeof( struct V_26 ) , V_14 ,
V_117 , V_118 ) ;
if ( V_105 == NULL )
return V_105 ;
V_105 -> V_119 = V_32 -> V_120 ;
V_105 -> V_121 = & V_122 ;
F_70 ( V_105 , V_32 ) ;
V_105 -> V_123 = 0 ;
V_105 -> V_124 = & V_125 ;
F_71 ( V_105 , V_22 ) ;
V_105 -> V_25 . V_126 = V_6 -> V_20 -> V_110 [ V_44 ] ;
V_105 -> V_120 = V_32 -> V_120 ;
V_27 = F_5 ( V_105 ) ;
V_27 -> V_25 = V_105 ;
V_27 -> V_22 = V_6 ;
V_27 -> V_44 = V_44 ;
switch ( V_6 -> V_29 -> V_127 ) {
#ifdef F_72
case V_128 :
V_27 -> V_59 = V_129 . V_59 ;
break;
#endif
#ifdef F_73
case V_130 :
V_27 -> V_59 = V_131 . V_59 ;
break;
#endif
#ifdef F_74
case V_132 :
V_27 -> V_59 = V_133 . V_59 ;
break;
#endif
#ifdef F_75
case V_134 :
V_27 -> V_59 = V_135 . V_59 ;
break;
#endif
default:
V_27 -> V_59 = F_27 ;
break;
}
V_27 -> V_99 = - 1 ;
V_27 -> V_96 = - 1 ;
V_27 -> V_97 = - 1 ;
F_52 ( V_27 , V_105 ) ;
V_89 = F_76 ( V_105 ) ;
if ( V_89 ) {
F_77 ( V_136 L_13 ,
V_32 -> V_14 , V_89 , V_105 -> V_14 ) ;
F_78 ( V_105 ) ;
return NULL ;
}
F_79 ( V_105 ) ;
if ( V_27 -> V_45 != NULL ) {
if ( V_6 -> V_9 -> V_114 )
V_27 -> V_45 -> V_137 |= V_6 -> V_9 -> V_114 ( V_6 , V_44 ) ;
F_80 ( V_105 , F_81 ( & V_27 -> V_45 -> V_25 ) ,
V_138 ) ;
V_27 -> V_45 -> V_139 = V_140 ;
V_27 -> V_45 -> V_141 = 0 ;
V_27 -> V_45 -> V_98 = 0 ;
V_27 -> V_45 -> V_142 = V_27 -> V_45 -> V_143 | V_144 ;
}
return V_105 ;
}
