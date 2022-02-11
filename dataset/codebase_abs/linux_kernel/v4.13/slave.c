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
V_6 -> V_19 -> V_20 , V_6 -> V_21 ) ;
V_6 -> V_13 -> V_22 = V_6 -> V_23 ;
V_6 -> V_13 -> V_24 = ~ V_6 -> V_8 ;
}
static int F_4 ( const struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
return F_6 ( V_27 ) -> V_28 ;
}
static int F_7 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_29 * V_30 = V_27 -> V_30 ;
struct V_5 * V_6 = V_30 -> V_6 ;
struct V_25 * V_31 = F_6 ( V_27 ) ;
T_2 V_32 = V_30 -> V_33 ? V_34 : V_35 ;
int V_36 ;
if ( ! ( V_31 -> V_37 & V_38 ) )
return - V_39 ;
if ( ! F_8 ( V_23 -> V_40 , V_31 -> V_40 ) ) {
V_36 = F_9 ( V_31 , V_23 -> V_40 ) ;
if ( V_36 < 0 )
goto V_41;
}
if ( V_23 -> V_37 & V_42 ) {
V_36 = F_10 ( V_31 , 1 ) ;
if ( V_36 < 0 )
goto V_43;
}
if ( V_23 -> V_37 & V_44 ) {
V_36 = F_11 ( V_31 , 1 ) ;
if ( V_36 < 0 )
goto V_45;
}
if ( V_6 -> V_9 -> V_46 ) {
V_36 = V_6 -> V_9 -> V_46 ( V_6 , V_27 -> V_30 -> V_21 , V_27 -> V_47 ) ;
if ( V_36 )
goto V_48;
}
F_12 ( V_27 -> V_30 , V_32 ) ;
if ( V_27 -> V_47 )
F_13 ( V_27 -> V_47 ) ;
return 0 ;
V_48:
if ( V_23 -> V_37 & V_44 )
F_11 ( V_31 , - 1 ) ;
V_45:
if ( V_23 -> V_37 & V_42 )
F_10 ( V_31 , - 1 ) ;
V_43:
if ( ! F_8 ( V_23 -> V_40 , V_31 -> V_40 ) )
F_14 ( V_31 , V_23 -> V_40 ) ;
V_41:
return V_36 ;
}
static int F_15 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_25 * V_31 = F_6 ( V_27 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
if ( V_27 -> V_47 )
F_16 ( V_27 -> V_47 ) ;
F_17 ( V_31 , V_23 ) ;
F_18 ( V_31 , V_23 ) ;
if ( V_23 -> V_37 & V_42 )
F_10 ( V_31 , - 1 ) ;
if ( V_23 -> V_37 & V_44 )
F_11 ( V_31 , - 1 ) ;
if ( ! F_8 ( V_23 -> V_40 , V_31 -> V_40 ) )
F_14 ( V_31 , V_23 -> V_40 ) ;
if ( V_6 -> V_9 -> V_49 )
V_6 -> V_9 -> V_49 ( V_6 , V_27 -> V_30 -> V_21 , V_27 -> V_47 ) ;
F_12 ( V_27 -> V_30 , V_50 ) ;
return 0 ;
}
static void F_19 ( struct V_25 * V_23 , int V_51 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_25 * V_31 = F_6 ( V_27 ) ;
if ( V_51 & V_42 )
F_10 ( V_31 , V_23 -> V_37 & V_42 ? 1 : - 1 ) ;
if ( V_51 & V_44 )
F_11 ( V_31 , V_23 -> V_37 & V_44 ? 1 : - 1 ) ;
}
static void F_20 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_25 * V_31 = F_6 ( V_27 ) ;
F_21 ( V_31 , V_23 ) ;
F_22 ( V_31 , V_23 ) ;
}
static int F_23 ( struct V_25 * V_23 , void * V_52 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_25 * V_31 = F_6 ( V_27 ) ;
struct V_53 * V_3 = V_52 ;
int V_36 ;
if ( ! F_24 ( V_3 -> V_54 ) )
return - V_55 ;
if ( ! ( V_23 -> V_37 & V_38 ) )
goto V_41;
if ( ! F_8 ( V_3 -> V_54 , V_31 -> V_40 ) ) {
V_36 = F_9 ( V_31 , V_3 -> V_54 ) ;
if ( V_36 < 0 )
return V_36 ;
}
if ( ! F_8 ( V_23 -> V_40 , V_31 -> V_40 ) )
F_14 ( V_31 , V_23 -> V_40 ) ;
V_41:
F_25 ( V_23 -> V_40 , V_3 -> V_54 ) ;
return 0 ;
}
static int F_26 ( struct V_25 * V_23 , struct V_56 * V_57 , int V_58 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
if ( V_27 -> V_47 != NULL )
return F_27 ( V_27 -> V_47 , V_57 , V_58 ) ;
return - V_59 ;
}
static int F_28 ( struct V_25 * V_23 ,
const struct V_60 * V_61 ,
struct V_62 * V_63 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_29 * V_30 = V_27 -> V_30 ;
int V_64 ;
switch ( V_61 -> V_17 ) {
case V_65 :
V_64 = F_29 ( V_30 , V_61 -> V_66 . V_32 , V_63 ) ;
break;
case V_67 :
V_64 = F_30 ( V_30 , V_61 -> V_66 . V_68 ,
V_63 ) ;
break;
case V_69 :
V_64 = F_31 ( V_30 , V_61 -> V_66 . V_70 , V_63 ) ;
break;
default:
V_64 = - V_59 ;
break;
}
return V_64 ;
}
static int F_32 ( struct V_25 * V_23 ,
const struct V_71 * V_72 ,
struct V_62 * V_63 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_29 * V_30 = V_27 -> V_30 ;
int V_36 ;
switch ( V_72 -> V_17 ) {
case V_73 :
V_36 = F_33 ( V_30 , F_34 ( V_72 ) , V_63 ) ;
break;
case V_74 :
V_36 = F_35 ( V_30 , F_36 ( V_72 ) , V_63 ) ;
break;
case V_75 :
V_36 = F_37 ( V_30 , F_38 ( V_72 ) ,
V_63 ) ;
break;
default:
V_36 = - V_59 ;
break;
}
return V_36 ;
}
static int F_39 ( struct V_25 * V_23 ,
const struct V_71 * V_72 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_29 * V_30 = V_27 -> V_30 ;
int V_36 ;
switch ( V_72 -> V_17 ) {
case V_73 :
V_36 = F_40 ( V_30 , F_34 ( V_72 ) ) ;
break;
case V_74 :
V_36 = F_41 ( V_30 , F_36 ( V_72 ) ) ;
break;
case V_75 :
V_36 = F_42 ( V_30 , F_38 ( V_72 ) ) ;
break;
default:
V_36 = - V_59 ;
break;
}
return V_36 ;
}
static int F_43 ( struct V_25 * V_23 ,
struct V_71 * V_72 ,
T_3 * V_76 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_29 * V_30 = V_27 -> V_30 ;
int V_36 ;
switch ( V_72 -> V_17 ) {
case V_73 :
V_36 = F_44 ( V_30 , F_34 ( V_72 ) , V_76 ) ;
break;
case V_74 :
V_36 = F_45 ( V_30 , F_36 ( V_72 ) , V_76 ) ;
break;
case V_75 :
V_36 = F_46 ( V_30 , F_38 ( V_72 ) , V_76 ) ;
break;
default:
V_36 = - V_59 ;
break;
}
return V_36 ;
}
static int F_47 ( struct V_25 * V_23 ,
struct V_60 * V_61 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
switch ( V_61 -> V_17 ) {
case V_77 :
V_61 -> V_66 . V_78 . V_79 = sizeof( V_6 -> V_21 ) ;
memcpy ( & V_61 -> V_66 . V_78 . V_17 , & V_6 -> V_21 , V_61 -> V_66 . V_78 . V_79 ) ;
break;
default:
return - V_59 ;
}
return 0 ;
}
static inline T_4 F_48 ( struct V_26 * V_27 ,
struct V_80 * V_81 )
{
#ifdef F_49
if ( V_27 -> V_82 )
F_50 ( V_27 -> V_82 , V_81 ) ;
#else
F_51 () ;
#endif
return V_83 ;
}
static T_4 F_52 ( struct V_80 * V_81 , struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_80 * V_84 ;
V_23 -> V_85 . V_86 ++ ;
V_23 -> V_85 . V_87 += V_81 -> V_88 ;
V_84 = V_27 -> V_89 ( V_81 , V_23 ) ;
if ( ! V_84 ) {
F_53 ( V_81 ) ;
return V_83 ;
}
if ( F_54 ( F_55 ( V_23 ) ) )
return F_48 ( V_27 , V_84 ) ;
V_84 -> V_23 = F_6 ( V_27 ) ;
F_56 ( V_84 ) ;
return V_83 ;
}
static int
F_57 ( struct V_25 * V_23 ,
struct V_90 * V_58 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
if ( ! V_27 -> V_47 )
return - V_59 ;
F_58 ( V_27 -> V_47 , V_58 ) ;
return 0 ;
}
static int
F_59 ( struct V_25 * V_23 ,
const struct V_90 * V_58 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
if ( V_27 -> V_47 != NULL )
return F_60 ( V_27 -> V_47 , V_58 ) ;
return - V_59 ;
}
static void F_61 ( struct V_25 * V_23 ,
struct V_91 * V_92 )
{
F_62 ( V_92 -> V_93 , L_3 , sizeof( V_92 -> V_93 ) ) ;
F_62 ( V_92 -> V_94 , L_4 , sizeof( V_92 -> V_94 ) ) ;
F_62 ( V_92 -> V_95 , L_5 , sizeof( V_92 -> V_95 ) ) ;
}
static int F_63 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
if ( V_6 -> V_9 -> V_96 )
return V_6 -> V_9 -> V_96 ( V_6 , V_27 -> V_30 -> V_21 ) ;
return - V_59 ;
}
static void
F_64 ( struct V_25 * V_23 , struct V_97 * V_98 , void * V_99 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
if ( V_6 -> V_9 -> V_100 )
V_6 -> V_9 -> V_100 ( V_6 , V_27 -> V_30 -> V_21 , V_98 , V_99 ) ;
}
static int F_65 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
if ( V_27 -> V_47 != NULL )
return F_66 ( V_27 -> V_47 ) ;
return - V_59 ;
}
static T_5 F_67 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
if ( V_27 -> V_47 != NULL ) {
F_68 ( V_27 -> V_47 ) ;
return V_27 -> V_47 -> V_101 ;
}
return - V_59 ;
}
static int F_69 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
if ( V_6 -> V_102 && V_6 -> V_102 -> V_103 )
return V_6 -> V_102 -> V_103 ;
if ( V_6 -> V_9 -> V_104 )
return V_6 -> V_9 -> V_104 ( V_6 ) ;
return 0 ;
}
static int F_70 ( struct V_25 * V_23 ,
struct V_105 * V_106 , T_2 * V_107 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
if ( V_6 -> V_9 -> V_108 )
return V_6 -> V_9 -> V_108 ( V_6 , V_106 , V_107 ) ;
return - V_59 ;
}
static int F_71 ( struct V_25 * V_23 ,
struct V_105 * V_106 , T_2 * V_107 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
if ( V_6 -> V_9 -> V_109 )
return V_6 -> V_9 -> V_109 ( V_6 , V_106 , V_107 ) ;
return - V_59 ;
}
static void F_72 ( struct V_25 * V_23 ,
T_6 V_110 , T_7 * V_107 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
if ( V_110 == V_111 ) {
int V_88 = V_112 ;
strncpy ( V_107 , L_6 , V_88 ) ;
strncpy ( V_107 + V_88 , L_7 , V_88 ) ;
strncpy ( V_107 + 2 * V_88 , L_8 , V_88 ) ;
strncpy ( V_107 + 3 * V_88 , L_9 , V_88 ) ;
if ( V_6 -> V_9 -> V_113 )
V_6 -> V_9 -> V_113 ( V_6 , V_27 -> V_30 -> V_21 , V_107 + 4 * V_88 ) ;
}
}
static void F_73 ( struct V_25 * V_23 ,
struct V_114 * V_85 ,
T_8 * V_107 )
{
struct V_115 * V_19 = V_23 -> V_116 ;
struct V_29 * V_117 = F_74 ( V_19 ) ;
struct V_5 * V_6 = V_117 -> V_6 ;
T_9 V_118 = V_117 -> V_21 ;
int V_119 = 0 ;
if ( V_117 -> V_120 . V_121 ) {
V_119 = V_117 -> V_120 . V_121 ( V_23 , V_111 ) ;
V_117 -> V_120 . V_122 ( V_23 , V_85 , V_107 ) ;
}
if ( V_6 -> V_9 -> V_122 )
V_6 -> V_9 -> V_122 ( V_6 , V_118 , V_107 + V_119 ) ;
}
static int F_75 ( struct V_25 * V_23 , int V_123 )
{
struct V_115 * V_19 = V_23 -> V_116 ;
struct V_29 * V_117 = F_74 ( V_19 ) ;
struct V_5 * V_6 = V_117 -> V_6 ;
int V_119 = 0 ;
if ( V_117 -> V_120 . V_121 )
V_119 += V_117 -> V_120 . V_121 ( V_23 , V_123 ) ;
if ( V_123 == V_111 && V_6 -> V_9 -> V_121 )
V_119 += V_6 -> V_9 -> V_121 ( V_6 ) ;
return V_119 ;
}
static void F_76 ( struct V_25 * V_23 ,
T_6 V_110 , T_7 * V_107 )
{
struct V_115 * V_19 = V_23 -> V_116 ;
struct V_29 * V_117 = F_74 ( V_19 ) ;
struct V_5 * V_6 = V_117 -> V_6 ;
T_9 V_118 = V_117 -> V_21 ;
int V_88 = V_112 ;
int V_124 = 0 , V_119 ;
unsigned int V_125 ;
T_7 V_126 [ 4 ] ;
T_7 * V_127 ;
snprintf ( V_126 , sizeof( V_126 ) , L_10 , V_118 ) ;
V_126 [ sizeof( V_126 ) - 1 ] = '_' ;
if ( V_117 -> V_120 . V_121 ) {
V_124 = V_117 -> V_120 . V_121 ( V_23 , V_111 ) ;
V_117 -> V_120 . V_113 ( V_23 , V_110 , V_107 ) ;
}
if ( V_110 == V_111 && V_6 -> V_9 -> V_113 ) {
V_127 = V_107 + V_124 * V_88 ;
V_6 -> V_9 -> V_113 ( V_6 , V_118 , V_127 ) ;
V_119 = V_6 -> V_9 -> V_121 ( V_6 ) ;
for ( V_125 = 0 ; V_125 < V_119 ; V_125 ++ ) {
memmove ( V_127 + ( V_125 * V_88 + sizeof( V_126 ) ) ,
V_127 + V_125 * V_88 , V_88 - sizeof( V_126 ) ) ;
memcpy ( V_127 + V_125 * V_88 , V_126 , sizeof( V_126 ) ) ;
}
}
}
static void F_77 ( struct V_25 * V_23 ,
struct V_114 * V_85 ,
T_8 * V_107 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
V_107 [ 0 ] = V_23 -> V_85 . V_86 ;
V_107 [ 1 ] = V_23 -> V_85 . V_87 ;
V_107 [ 2 ] = V_23 -> V_85 . V_128 ;
V_107 [ 3 ] = V_23 -> V_85 . V_129 ;
if ( V_6 -> V_9 -> V_122 )
V_6 -> V_9 -> V_122 ( V_6 , V_27 -> V_30 -> V_21 , V_107 + 4 ) ;
}
static int F_78 ( struct V_25 * V_23 , int V_123 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
if ( V_123 == V_111 ) {
int V_119 ;
V_119 = 4 ;
if ( V_6 -> V_9 -> V_121 )
V_119 += V_6 -> V_9 -> V_121 ( V_6 ) ;
return V_119 ;
}
return - V_59 ;
}
static void F_79 ( struct V_25 * V_23 , struct V_130 * V_131 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
if ( V_6 -> V_9 -> V_132 )
V_6 -> V_9 -> V_132 ( V_6 , V_27 -> V_30 -> V_21 , V_131 ) ;
}
static int F_80 ( struct V_25 * V_23 , struct V_130 * V_131 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
int V_64 = - V_59 ;
if ( V_6 -> V_9 -> V_133 )
V_64 = V_6 -> V_9 -> V_133 ( V_6 , V_27 -> V_30 -> V_21 , V_131 ) ;
return V_64 ;
}
static int F_81 ( struct V_25 * V_23 , struct V_134 * V_135 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
int V_64 ;
if ( ! V_6 -> V_9 -> V_136 )
return - V_59 ;
V_64 = V_6 -> V_9 -> V_136 ( V_6 , V_27 -> V_30 -> V_21 , V_27 -> V_47 , V_135 ) ;
if ( V_64 )
return V_64 ;
if ( V_27 -> V_47 )
V_64 = F_82 ( V_27 -> V_47 , V_135 ) ;
return V_64 ;
}
static int F_83 ( struct V_25 * V_23 , struct V_134 * V_135 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
int V_64 ;
if ( ! V_6 -> V_9 -> V_137 )
return - V_59 ;
V_64 = V_6 -> V_9 -> V_137 ( V_6 , V_27 -> V_30 -> V_21 , V_135 ) ;
if ( V_64 )
return V_64 ;
if ( V_27 -> V_47 )
V_64 = F_84 ( V_27 -> V_47 , V_135 ) ;
return V_64 ;
}
static int F_85 ( struct V_25 * V_23 ,
struct V_138 * V_139 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_25 * V_31 = F_6 ( V_27 ) ;
struct V_82 * V_82 ;
int V_36 = 0 ;
V_82 = F_86 ( sizeof( * V_82 ) , V_140 ) ;
if ( ! V_82 )
return - V_141 ;
V_36 = F_87 ( V_82 , V_31 ) ;
if ( V_36 ) {
F_88 ( V_82 ) ;
goto V_41;
}
V_27 -> V_82 = V_82 ;
V_41:
return V_36 ;
}
static void F_89 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_82 * V_82 = V_27 -> V_82 ;
if ( ! V_82 )
return;
V_27 -> V_82 = NULL ;
F_90 ( V_82 ) ;
}
static void F_91 ( struct V_25 * V_23 )
{
}
static int F_92 ( struct V_25 * V_23 ,
char * V_14 , T_10 V_88 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
if ( snprintf ( V_14 , V_88 , L_11 , V_27 -> V_30 -> V_21 ) >= V_88 )
return - V_142 ;
return 0 ;
}
static struct V_143 *
F_93 ( struct V_26 * V_27 ,
unsigned long V_144 )
{
struct V_143 * V_145 ;
F_94 (mall_tc_entry, &p->mall_tc_list, list)
if ( V_145 -> V_144 == V_144 )
return V_145 ;
return NULL ;
}
static int F_95 ( struct V_25 * V_23 ,
T_11 V_146 ,
struct V_147 * V_148 ,
bool V_149 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_143 * V_145 ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
struct V_150 * V_150 = F_96 ( V_23 ) ;
struct V_26 * V_151 ;
struct V_25 * V_152 ;
const struct V_153 * V_52 ;
int V_36 = - V_59 ;
F_97 ( V_154 ) ;
int V_28 ;
if ( ! V_6 -> V_9 -> V_155 )
return V_36 ;
if ( ! F_98 ( V_148 -> V_156 ) )
return V_36 ;
F_99 ( V_148 -> V_156 , & V_154 ) ;
V_52 = F_100 ( & V_154 , struct V_153 , V_157 ) ;
if ( F_101 ( V_52 ) && V_146 == F_102 ( V_158 ) ) {
struct V_159 * V_160 ;
V_28 = F_103 ( V_52 ) ;
V_152 = F_104 ( V_150 , V_28 ) ;
if ( ! V_152 )
return - V_142 ;
if ( ! F_105 ( V_152 ) )
return - V_59 ;
V_145 = F_86 ( sizeof( * V_145 ) , V_140 ) ;
if ( ! V_145 )
return - V_141 ;
V_145 -> V_144 = V_148 -> V_144 ;
V_145 -> type = V_161 ;
V_160 = & V_145 -> V_160 ;
V_151 = F_5 ( V_152 ) ;
V_160 -> V_162 = V_151 -> V_30 -> V_21 ;
V_160 -> V_149 = V_149 ;
V_36 = V_6 -> V_9 -> V_155 ( V_6 , V_27 -> V_30 -> V_21 , V_160 ,
V_149 ) ;
if ( V_36 ) {
F_88 ( V_145 ) ;
return V_36 ;
}
F_106 ( & V_145 -> V_157 , & V_27 -> V_163 ) ;
}
return 0 ;
}
static void F_107 ( struct V_25 * V_23 ,
struct V_147 * V_148 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_143 * V_145 ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
if ( ! V_6 -> V_9 -> V_164 )
return;
V_145 = F_93 ( V_27 , V_148 -> V_144 ) ;
if ( ! V_145 )
return;
F_108 ( & V_145 -> V_157 ) ;
switch ( V_145 -> type ) {
case V_161 :
V_6 -> V_9 -> V_164 ( V_6 , V_27 -> V_30 -> V_21 ,
& V_145 -> V_160 ) ;
break;
default:
F_109 ( 1 ) ;
}
F_88 ( V_145 ) ;
}
static int F_110 ( struct V_25 * V_23 , T_5 V_165 ,
T_5 V_166 , T_11 V_146 ,
struct V_167 * V_168 )
{
bool V_149 = F_111 ( V_165 ) == F_111 ( V_169 ) ;
if ( V_166 )
return - V_59 ;
switch ( V_168 -> type ) {
case V_170 :
switch ( V_168 -> V_171 -> V_172 ) {
case V_173 :
return F_95 ( V_23 , V_146 ,
V_168 -> V_171 ,
V_149 ) ;
case V_174 :
F_107 ( V_23 , V_168 -> V_171 ) ;
return 0 ;
}
default:
return - V_59 ;
}
}
void F_112 ( struct V_120 * V_9 )
{
V_9 -> V_121 = F_75 ;
V_9 -> V_122 = F_73 ;
V_9 -> V_113 = F_76 ;
}
static int F_113 ( struct V_25 * V_23 ,
struct V_175 * V_176 , T_5 * V_177 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
if ( ! V_6 -> V_9 -> V_178 )
return - V_59 ;
return V_6 -> V_9 -> V_178 ( V_6 , V_27 -> V_30 -> V_21 , V_176 , V_177 ) ;
}
static int F_114 ( struct V_25 * V_23 ,
struct V_175 * V_176 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
if ( ! V_6 -> V_9 -> V_179 )
return - V_59 ;
return V_6 -> V_9 -> V_179 ( V_6 , V_27 -> V_30 -> V_21 , V_176 ) ;
}
static void F_115 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
unsigned int V_180 = 0 ;
if ( V_27 -> V_181 != V_27 -> V_47 -> V_101 ) {
V_180 = 1 ;
V_27 -> V_181 = V_27 -> V_47 -> V_101 ;
}
if ( V_27 -> V_182 != V_27 -> V_47 -> V_183 ) {
V_180 = 1 ;
V_27 -> V_182 = V_27 -> V_47 -> V_183 ;
}
if ( V_27 -> V_184 != V_27 -> V_47 -> V_185 ) {
V_180 = 1 ;
V_27 -> V_184 = V_27 -> V_47 -> V_185 ;
}
if ( V_6 -> V_9 -> V_186 && V_180 )
V_6 -> V_9 -> V_186 ( V_6 , V_27 -> V_30 -> V_21 , V_27 -> V_47 ) ;
if ( V_180 )
F_116 ( V_27 -> V_47 ) ;
}
static int F_117 ( struct V_25 * V_23 ,
struct V_187 * V_188 )
{
struct V_26 * V_27 ;
struct V_5 * V_6 ;
if ( V_23 ) {
V_27 = F_5 ( V_23 ) ;
V_6 = V_27 -> V_30 -> V_6 ;
if ( V_6 -> V_9 -> V_189 )
V_6 -> V_9 -> V_189 ( V_6 , V_27 -> V_30 -> V_21 , V_188 ) ;
}
return 0 ;
}
static int F_118 ( struct V_26 * V_27 ,
struct V_25 * V_190 ,
int V_3 )
{
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
V_27 -> V_47 = F_119 ( V_6 -> V_13 , V_3 ) ;
if ( ! V_27 -> V_47 ) {
F_120 ( V_190 , L_12 , V_3 ) ;
return - V_191 ;
}
if ( V_27 -> V_192 == V_193 )
V_27 -> V_192 = V_27 -> V_47 -> V_194 ;
return F_121 ( V_190 , V_27 -> V_47 , F_115 ,
V_27 -> V_192 ) ;
}
static int F_122 ( struct V_26 * V_27 ,
struct V_25 * V_190 )
{
struct V_5 * V_6 = V_27 -> V_30 -> V_6 ;
struct V_195 * V_196 , * V_197 ;
bool V_198 = false ;
T_5 V_199 = 0 ;
int V_200 , V_64 ;
V_197 = V_27 -> V_30 -> V_201 ;
V_200 = F_123 ( V_197 ) ;
if ( V_200 < 0 )
V_200 = V_193 ;
V_27 -> V_192 = V_200 ;
V_196 = F_124 ( V_197 , L_13 , 0 ) ;
if ( ! V_196 && F_125 ( V_197 ) ) {
V_64 = F_126 ( V_197 ) ;
if ( V_64 ) {
F_120 ( V_190 , L_14 , V_64 ) ;
return V_64 ;
}
V_198 = true ;
V_196 = F_127 ( V_197 ) ;
}
if ( V_6 -> V_9 -> V_202 )
V_199 = V_6 -> V_9 -> V_202 ( V_6 , V_27 -> V_30 -> V_21 ) ;
if ( V_196 ) {
int V_203 = F_128 ( & V_190 -> V_23 , V_196 ) ;
if ( ! V_198 && V_203 >= 0 &&
( V_6 -> V_8 & ( 1 << V_203 ) ) ) {
V_64 = F_118 ( V_27 , V_190 , V_203 ) ;
if ( V_64 ) {
F_120 ( V_190 , L_15 , V_203 , V_64 ) ;
F_129 ( V_196 ) ;
return V_64 ;
}
} else {
V_27 -> V_47 = F_130 ( V_190 , V_196 ,
F_115 ,
V_199 ,
V_27 -> V_192 ) ;
}
F_129 ( V_196 ) ;
}
if ( V_27 -> V_47 && V_198 )
F_131 ( V_27 -> V_47 , F_117 ) ;
if ( ! V_27 -> V_47 ) {
V_64 = F_118 ( V_27 , V_190 , V_27 -> V_30 -> V_21 ) ;
if ( V_64 ) {
F_120 ( V_190 , L_16 ,
V_27 -> V_30 -> V_21 , V_64 ) ;
if ( V_198 )
F_132 ( V_197 ) ;
return V_64 ;
}
}
F_133 ( V_27 -> V_47 ) ;
return 0 ;
}
static void F_134 ( struct V_25 * V_23 ,
struct V_204 * V_205 ,
void * V_206 )
{
F_135 ( & V_205 -> V_207 ,
& V_208 ) ;
}
int F_136 ( struct V_25 * V_190 )
{
struct V_26 * V_27 = F_5 ( V_190 ) ;
F_137 ( V_190 ) ;
if ( V_27 -> V_47 ) {
F_16 ( V_27 -> V_47 ) ;
V_27 -> V_184 = - 1 ;
V_27 -> V_181 = - 1 ;
V_27 -> V_182 = - 1 ;
F_138 ( V_27 -> V_47 ) ;
}
return 0 ;
}
int F_139 ( struct V_25 * V_190 )
{
struct V_26 * V_27 = F_5 ( V_190 ) ;
F_140 ( V_190 ) ;
if ( V_27 -> V_47 ) {
F_141 ( V_27 -> V_47 ) ;
F_13 ( V_27 -> V_47 ) ;
}
return 0 ;
}
int F_142 ( struct V_5 * V_6 , struct V_209 * V_22 ,
int V_210 , const char * V_14 )
{
struct V_115 * V_19 = V_6 -> V_19 ;
struct V_25 * V_31 ;
struct V_25 * V_190 ;
struct V_26 * V_27 ;
struct V_29 * V_117 ;
int V_64 ;
V_117 = V_6 -> V_19 -> V_117 ;
V_31 = V_117 -> V_211 ;
V_190 = F_143 ( sizeof( struct V_26 ) , V_14 ,
V_212 , V_213 ) ;
if ( V_190 == NULL )
return - V_141 ;
V_190 -> V_214 = V_31 -> V_215 | V_216 ;
V_190 -> V_217 |= V_216 ;
V_190 -> V_120 = & V_218 ;
F_144 ( V_190 , V_31 ) ;
V_190 -> V_219 |= V_220 ;
V_190 -> V_221 = & V_222 ;
V_190 -> V_223 = & V_224 ;
V_190 -> V_225 = 0 ;
V_190 -> V_226 = V_227 ;
F_145 ( V_190 , & V_228 ) ;
F_146 ( V_190 , F_134 ,
NULL ) ;
F_147 ( V_190 , V_22 ) ;
V_190 -> V_23 . V_229 = V_6 -> V_230 [ V_210 ] . V_201 ;
V_190 -> V_215 = V_31 -> V_215 ;
V_27 = F_5 ( V_190 ) ;
V_27 -> V_30 = & V_6 -> V_230 [ V_210 ] ;
F_148 ( & V_27 -> V_163 ) ;
V_27 -> V_89 = V_19 -> V_231 -> V_89 ;
V_27 -> V_184 = - 1 ;
V_27 -> V_181 = - 1 ;
V_27 -> V_182 = - 1 ;
V_6 -> V_230 [ V_210 ] . V_211 = V_190 ;
V_64 = F_149 ( V_190 ) ;
if ( V_64 ) {
F_120 ( V_31 , L_17 ,
V_64 , V_190 -> V_14 ) ;
V_6 -> V_230 [ V_210 ] . V_211 = NULL ;
F_150 ( V_190 ) ;
return V_64 ;
}
F_151 ( V_190 ) ;
V_64 = F_122 ( V_27 , V_190 ) ;
if ( V_64 ) {
F_120 ( V_31 , L_18 , V_64 ) ;
F_152 ( V_190 ) ;
F_150 ( V_190 ) ;
return V_64 ;
}
return 0 ;
}
void F_153 ( struct V_25 * V_190 )
{
struct V_26 * V_27 = F_5 ( V_190 ) ;
struct V_195 * V_197 ;
V_197 = V_27 -> V_30 -> V_201 ;
F_151 ( V_190 ) ;
if ( V_27 -> V_47 ) {
F_154 ( V_27 -> V_47 ) ;
if ( F_125 ( V_197 ) )
F_132 ( V_197 ) ;
}
F_152 ( V_190 ) ;
F_150 ( V_190 ) ;
}
static bool F_105 ( struct V_25 * V_23 )
{
return V_23 -> V_221 == & V_222 ;
}
static int F_155 ( struct V_25 * V_23 ,
struct V_232 * V_233 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_29 * V_30 = V_27 -> V_30 ;
int V_36 = V_234 ;
if ( F_156 ( V_233 -> V_235 ) ) {
if ( V_233 -> V_236 ) {
V_36 = F_157 ( V_30 , V_233 -> V_235 ) ;
V_36 = F_158 ( V_36 ) ;
} else {
F_159 ( V_30 , V_233 -> V_235 ) ;
V_36 = V_237 ;
}
}
return V_36 ;
}
static int F_160 ( struct V_238 * V_239 ,
unsigned long V_240 , void * V_241 )
{
struct V_25 * V_23 = F_161 ( V_241 ) ;
if ( V_23 -> V_221 != & V_222 )
return V_234 ;
if ( V_240 == V_242 )
return F_155 ( V_23 , V_241 ) ;
return V_234 ;
}
int F_162 ( void )
{
return F_163 ( & V_243 ) ;
}
void F_164 ( void )
{
int V_36 ;
V_36 = F_165 ( & V_243 ) ;
if ( V_36 )
F_166 ( L_19 , V_36 ) ;
}
