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
static int F_4 ( const struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
return V_27 -> V_22 -> V_28 -> V_29 -> V_30 ;
}
static inline bool F_6 ( struct V_26 * V_27 )
{
return ! ! V_27 -> V_31 ;
}
static int F_7 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_25 * V_32 = V_27 -> V_22 -> V_28 -> V_29 ;
struct V_5 * V_6 = V_27 -> V_22 ;
T_2 V_33 = F_6 ( V_27 ) ?
V_34 : V_35 ;
int V_36 ;
if ( ! ( V_32 -> V_37 & V_38 ) )
return - V_39 ;
if ( ! F_8 ( V_23 -> V_40 , V_32 -> V_40 ) ) {
V_36 = F_9 ( V_32 , V_23 -> V_40 ) ;
if ( V_36 < 0 )
goto V_41;
}
if ( V_23 -> V_37 & V_42 ) {
V_36 = F_10 ( V_32 , 1 ) ;
if ( V_36 < 0 )
goto V_43;
}
if ( V_23 -> V_37 & V_44 ) {
V_36 = F_11 ( V_32 , 1 ) ;
if ( V_36 < 0 )
goto V_45;
}
if ( V_6 -> V_9 -> V_46 ) {
V_36 = V_6 -> V_9 -> V_46 ( V_6 , V_27 -> V_47 , V_27 -> V_48 ) ;
if ( V_36 )
goto V_49;
}
if ( V_6 -> V_9 -> V_50 )
V_6 -> V_9 -> V_50 ( V_6 , V_27 -> V_47 , V_33 ) ;
if ( V_27 -> V_48 )
F_12 ( V_27 -> V_48 ) ;
return 0 ;
V_49:
if ( V_23 -> V_37 & V_44 )
F_11 ( V_32 , - 1 ) ;
V_45:
if ( V_23 -> V_37 & V_42 )
F_10 ( V_32 , - 1 ) ;
V_43:
if ( ! F_8 ( V_23 -> V_40 , V_32 -> V_40 ) )
F_13 ( V_32 , V_23 -> V_40 ) ;
V_41:
return V_36 ;
}
static int F_14 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_25 * V_32 = V_27 -> V_22 -> V_28 -> V_29 ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_27 -> V_48 )
F_15 ( V_27 -> V_48 ) ;
F_16 ( V_32 , V_23 ) ;
F_17 ( V_32 , V_23 ) ;
if ( V_23 -> V_37 & V_42 )
F_10 ( V_32 , - 1 ) ;
if ( V_23 -> V_37 & V_44 )
F_11 ( V_32 , - 1 ) ;
if ( ! F_8 ( V_23 -> V_40 , V_32 -> V_40 ) )
F_13 ( V_32 , V_23 -> V_40 ) ;
if ( V_6 -> V_9 -> V_51 )
V_6 -> V_9 -> V_51 ( V_6 , V_27 -> V_47 , V_27 -> V_48 ) ;
if ( V_6 -> V_9 -> V_50 )
V_6 -> V_9 -> V_50 ( V_6 , V_27 -> V_47 , V_52 ) ;
return 0 ;
}
static void F_18 ( struct V_25 * V_23 , int V_53 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_25 * V_32 = V_27 -> V_22 -> V_28 -> V_29 ;
if ( V_53 & V_42 )
F_10 ( V_32 , V_23 -> V_37 & V_42 ? 1 : - 1 ) ;
if ( V_53 & V_44 )
F_11 ( V_32 , V_23 -> V_37 & V_44 ? 1 : - 1 ) ;
}
static void F_19 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_25 * V_32 = V_27 -> V_22 -> V_28 -> V_29 ;
F_20 ( V_32 , V_23 ) ;
F_21 ( V_32 , V_23 ) ;
}
static int F_22 ( struct V_25 * V_23 , void * V_54 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_25 * V_32 = V_27 -> V_22 -> V_28 -> V_29 ;
struct V_55 * V_3 = V_54 ;
int V_36 ;
if ( ! F_23 ( V_3 -> V_56 ) )
return - V_57 ;
if ( ! ( V_23 -> V_37 & V_38 ) )
goto V_41;
if ( ! F_8 ( V_3 -> V_56 , V_32 -> V_40 ) ) {
V_36 = F_9 ( V_32 , V_3 -> V_56 ) ;
if ( V_36 < 0 )
return V_36 ;
}
if ( ! F_8 ( V_23 -> V_40 , V_32 -> V_40 ) )
F_13 ( V_32 , V_23 -> V_40 ) ;
V_41:
F_24 ( V_23 -> V_40 , V_3 -> V_56 ) ;
return 0 ;
}
static int F_25 ( struct V_25 * V_23 ,
const struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( F_26 ( V_61 ) ) {
if ( ! V_6 -> V_9 -> V_62 || ! V_6 -> V_9 -> V_63 )
return - V_64 ;
return V_6 -> V_9 -> V_62 ( V_6 , V_27 -> V_47 , V_59 , V_61 ) ;
}
V_6 -> V_9 -> V_63 ( V_6 , V_27 -> V_47 , V_59 , V_61 ) ;
return 0 ;
}
static int F_27 ( struct V_25 * V_23 ,
const struct V_58 * V_59 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( ! V_6 -> V_9 -> V_65 )
return - V_64 ;
return V_6 -> V_9 -> V_65 ( V_6 , V_27 -> V_47 , V_59 ) ;
}
static int F_28 ( struct V_25 * V_23 ,
struct V_58 * V_59 ,
T_3 * V_66 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_67 )
return V_6 -> V_9 -> V_67 ( V_6 , V_27 -> V_47 , V_59 , V_66 ) ;
return - V_64 ;
}
static int F_29 ( struct V_25 * V_23 ,
const struct V_68 * V_69 ,
struct V_60 * V_61 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( F_26 ( V_61 ) ) {
if ( ! V_6 -> V_9 -> V_70 || ! V_6 -> V_9 -> V_71 )
return - V_64 ;
return V_6 -> V_9 -> V_70 ( V_6 , V_27 -> V_47 , V_69 , V_61 ) ;
}
V_6 -> V_9 -> V_71 ( V_6 , V_27 -> V_47 , V_69 , V_61 ) ;
return 0 ;
}
static int F_30 ( struct V_25 * V_23 ,
const struct V_68 * V_69 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
int V_72 = - V_64 ;
if ( V_6 -> V_9 -> V_73 )
V_72 = V_6 -> V_9 -> V_73 ( V_6 , V_27 -> V_47 , V_69 ) ;
return V_72 ;
}
static int F_31 ( struct V_25 * V_23 ,
struct V_68 * V_69 ,
T_3 * V_66 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_74 )
return V_6 -> V_9 -> V_74 ( V_6 , V_27 -> V_47 , V_69 , V_66 ) ;
return - V_64 ;
}
static int F_32 ( struct V_25 * V_23 , struct V_75 * V_76 , int V_77 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
if ( V_27 -> V_48 != NULL )
return F_33 ( V_27 -> V_48 , V_76 , V_77 ) ;
return - V_64 ;
}
static int F_34 ( struct V_25 * V_23 ,
const struct V_78 * V_79 ,
struct V_60 * V_61 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( F_26 ( V_61 ) )
return V_6 -> V_9 -> V_50 ? 0 : - V_64 ;
V_6 -> V_9 -> V_50 ( V_6 , V_27 -> V_47 , V_79 -> V_80 . V_33 ) ;
return 0 ;
}
static int F_35 ( struct V_25 * V_23 ,
const struct V_78 * V_79 ,
struct V_60 * V_61 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( F_26 ( V_61 ) )
return 0 ;
if ( V_6 -> V_9 -> V_81 )
return V_6 -> V_9 -> V_81 ( V_6 , V_27 -> V_47 ,
V_79 -> V_80 . V_82 ) ;
return 0 ;
}
static int F_36 ( struct V_25 * V_23 ,
const struct V_78 * V_79 ,
struct V_60 * V_61 )
{
int V_72 ;
switch ( V_79 -> V_17 ) {
case V_83 :
V_72 = F_34 ( V_23 , V_79 , V_61 ) ;
break;
case V_84 :
V_72 = F_35 ( V_23 , V_79 , V_61 ) ;
break;
default:
V_72 = - V_64 ;
break;
}
return V_72 ;
}
static int F_37 ( struct V_25 * V_23 ,
const struct V_85 * V_86 ,
struct V_60 * V_61 )
{
int V_36 ;
switch ( V_86 -> V_17 ) {
case V_87 :
V_36 = F_29 ( V_23 ,
F_38 ( V_86 ) ,
V_61 ) ;
break;
case V_88 :
V_36 = F_25 ( V_23 ,
F_39 ( V_86 ) ,
V_61 ) ;
break;
default:
V_36 = - V_64 ;
break;
}
return V_36 ;
}
static int F_40 ( struct V_25 * V_23 ,
const struct V_85 * V_86 )
{
int V_36 ;
switch ( V_86 -> V_17 ) {
case V_87 :
V_36 = F_30 ( V_23 ,
F_38 ( V_86 ) ) ;
break;
case V_88 :
V_36 = F_27 ( V_23 ,
F_39 ( V_86 ) ) ;
break;
default:
V_36 = - V_64 ;
break;
}
return V_36 ;
}
static int F_41 ( struct V_25 * V_23 ,
struct V_85 * V_86 ,
T_3 * V_66 )
{
int V_36 ;
switch ( V_86 -> V_17 ) {
case V_87 :
V_36 = F_31 ( V_23 ,
F_38 ( V_86 ) ,
V_66 ) ;
break;
case V_88 :
V_36 = F_28 ( V_23 ,
F_39 ( V_86 ) ,
V_66 ) ;
break;
default:
V_36 = - V_64 ;
break;
}
return V_36 ;
}
static int F_42 ( struct V_25 * V_23 ,
struct V_25 * V_89 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
int V_72 = - V_64 ;
V_27 -> V_31 = V_89 ;
if ( V_6 -> V_9 -> V_90 )
V_72 = V_6 -> V_9 -> V_90 ( V_6 , V_27 -> V_47 , V_89 ) ;
return V_72 == - V_64 ? 0 : V_72 ;
}
static void F_43 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_91 )
V_6 -> V_9 -> V_91 ( V_6 , V_27 -> V_47 ) ;
V_27 -> V_31 = NULL ;
if ( V_6 -> V_9 -> V_50 )
V_6 -> V_9 -> V_50 ( V_6 , V_27 -> V_47 , V_35 ) ;
}
static int F_44 ( struct V_25 * V_23 ,
struct V_78 * V_79 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
switch ( V_79 -> V_17 ) {
case V_92 :
V_79 -> V_80 . V_93 . V_94 = sizeof( V_6 -> V_19 ) ;
memcpy ( & V_79 -> V_80 . V_93 . V_17 , & V_6 -> V_19 , V_79 -> V_80 . V_93 . V_94 ) ;
break;
default:
return - V_64 ;
}
return 0 ;
}
static inline T_4 F_45 ( struct V_26 * V_27 ,
struct V_95 * V_96 )
{
#ifdef F_46
if ( V_27 -> V_97 )
F_47 ( V_27 -> V_97 , V_96 ) ;
#else
F_48 () ;
#endif
return V_98 ;
}
static T_4 F_49 ( struct V_95 * V_96 , struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_95 * V_99 ;
V_23 -> V_100 . V_101 ++ ;
V_23 -> V_100 . V_102 += V_96 -> V_103 ;
V_99 = V_27 -> V_104 ( V_96 , V_23 ) ;
if ( ! V_99 )
return V_98 ;
if ( F_50 ( F_51 ( V_23 ) ) )
return F_45 ( V_27 , V_99 ) ;
V_99 -> V_23 = V_27 -> V_22 -> V_28 -> V_29 ;
F_52 ( V_99 ) ;
return V_98 ;
}
static struct V_95 * F_53 ( struct V_95 * V_96 ,
struct V_25 * V_23 )
{
return V_96 ;
}
static int
F_54 ( struct V_25 * V_23 , struct V_105 * V_77 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
int V_36 ;
V_36 = - V_64 ;
if ( V_27 -> V_48 != NULL ) {
V_36 = F_55 ( V_27 -> V_48 ) ;
if ( V_36 == 0 )
V_36 = F_56 ( V_27 -> V_48 , V_77 ) ;
}
return V_36 ;
}
static int
F_57 ( struct V_25 * V_23 , struct V_105 * V_77 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
if ( V_27 -> V_48 != NULL )
return F_58 ( V_27 -> V_48 , V_77 ) ;
return - V_64 ;
}
static void F_59 ( struct V_25 * V_23 ,
struct V_106 * V_107 )
{
F_60 ( V_107 -> V_108 , L_3 , sizeof( V_107 -> V_108 ) ) ;
F_60 ( V_107 -> V_109 , V_110 , sizeof( V_107 -> V_109 ) ) ;
F_60 ( V_107 -> V_111 , L_4 , sizeof( V_107 -> V_111 ) ) ;
F_60 ( V_107 -> V_112 , L_5 , sizeof( V_107 -> V_112 ) ) ;
}
static int F_61 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_113 )
return V_6 -> V_9 -> V_113 ( V_6 , V_27 -> V_47 ) ;
return - V_64 ;
}
static void
F_62 ( struct V_25 * V_23 , struct V_114 * V_115 , void * V_116 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_117 )
V_6 -> V_9 -> V_117 ( V_6 , V_27 -> V_47 , V_115 , V_116 ) ;
}
static int F_63 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
if ( V_27 -> V_48 != NULL )
return F_64 ( V_27 -> V_48 ) ;
return - V_64 ;
}
static T_5 F_65 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
if ( V_27 -> V_48 != NULL ) {
F_66 ( V_27 -> V_48 ) ;
return V_27 -> V_48 -> V_118 ;
}
return - V_64 ;
}
static int F_67 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_20 -> V_119 )
return V_6 -> V_20 -> V_119 ;
if ( V_6 -> V_9 -> V_120 )
return V_6 -> V_9 -> V_120 ( V_6 ) ;
return 0 ;
}
static int F_68 ( struct V_25 * V_23 ,
struct V_121 * V_122 , T_2 * V_123 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_124 )
return V_6 -> V_9 -> V_124 ( V_6 , V_122 , V_123 ) ;
return - V_64 ;
}
static int F_69 ( struct V_25 * V_23 ,
struct V_121 * V_122 , T_2 * V_123 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_125 )
return V_6 -> V_9 -> V_125 ( V_6 , V_122 , V_123 ) ;
return - V_64 ;
}
static void F_70 ( struct V_25 * V_23 ,
T_6 V_126 , T_7 * V_123 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_126 == V_127 ) {
int V_103 = V_128 ;
strncpy ( V_123 , L_6 , V_103 ) ;
strncpy ( V_123 + V_103 , L_7 , V_103 ) ;
strncpy ( V_123 + 2 * V_103 , L_8 , V_103 ) ;
strncpy ( V_123 + 3 * V_103 , L_9 , V_103 ) ;
if ( V_6 -> V_9 -> V_129 != NULL )
V_6 -> V_9 -> V_129 ( V_6 , V_27 -> V_47 , V_123 + 4 * V_103 ) ;
}
}
static void F_71 ( struct V_25 * V_23 ,
struct V_130 * V_100 ,
T_8 * V_123 )
{
struct V_131 * V_28 = V_23 -> V_132 ;
struct V_5 * V_6 = V_28 -> V_6 [ 0 ] ;
T_9 V_133 = V_28 -> V_133 ;
int V_134 = 0 ;
if ( V_28 -> V_135 . V_136 ) {
V_134 = V_28 -> V_135 . V_136 ( V_23 ,
V_127 ) ;
V_28 -> V_135 . V_137 ( V_23 , V_100 , V_123 ) ;
}
if ( V_6 -> V_9 -> V_137 )
V_6 -> V_9 -> V_137 ( V_6 , V_133 , V_123 + V_134 ) ;
}
static int F_72 ( struct V_25 * V_23 , int V_138 )
{
struct V_131 * V_28 = V_23 -> V_132 ;
struct V_5 * V_6 = V_28 -> V_6 [ 0 ] ;
int V_134 = 0 ;
if ( V_28 -> V_135 . V_136 )
V_134 += V_28 -> V_135 . V_136 ( V_23 , V_138 ) ;
if ( V_138 == V_127 && V_6 -> V_9 -> V_136 )
V_134 += V_6 -> V_9 -> V_136 ( V_6 ) ;
return V_134 ;
}
static void F_73 ( struct V_25 * V_23 ,
T_6 V_126 , T_7 * V_123 )
{
struct V_131 * V_28 = V_23 -> V_132 ;
struct V_5 * V_6 = V_28 -> V_6 [ 0 ] ;
T_9 V_133 = V_28 -> V_133 ;
int V_103 = V_128 ;
int V_139 = 0 , V_134 ;
unsigned int V_140 ;
T_7 V_141 [ 4 ] ;
T_7 * V_142 ;
snprintf ( V_141 , sizeof( V_141 ) , L_10 , V_133 ) ;
V_141 [ sizeof( V_141 ) - 1 ] = '_' ;
if ( V_28 -> V_135 . V_136 ) {
V_139 = V_28 -> V_135 . V_136 ( V_23 ,
V_127 ) ;
V_28 -> V_135 . V_129 ( V_23 , V_126 , V_123 ) ;
}
if ( V_126 == V_127 && V_6 -> V_9 -> V_129 ) {
V_142 = V_123 + V_139 * V_103 ;
V_6 -> V_9 -> V_129 ( V_6 , V_133 , V_142 ) ;
V_134 = V_6 -> V_9 -> V_136 ( V_6 ) ;
for ( V_140 = 0 ; V_140 < V_134 ; V_140 ++ ) {
memmove ( V_142 + ( V_140 * V_103 + sizeof( V_141 ) ) ,
V_142 + V_140 * V_103 , V_103 - sizeof( V_141 ) ) ;
memcpy ( V_142 + V_140 * V_103 , V_141 , sizeof( V_141 ) ) ;
}
}
}
static void F_74 ( struct V_25 * V_23 ,
struct V_130 * V_100 ,
T_8 * V_123 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
V_123 [ 0 ] = V_23 -> V_100 . V_101 ;
V_123 [ 1 ] = V_23 -> V_100 . V_102 ;
V_123 [ 2 ] = V_23 -> V_100 . V_143 ;
V_123 [ 3 ] = V_23 -> V_100 . V_144 ;
if ( V_6 -> V_9 -> V_137 != NULL )
V_6 -> V_9 -> V_137 ( V_6 , V_27 -> V_47 , V_123 + 4 ) ;
}
static int F_75 ( struct V_25 * V_23 , int V_138 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_138 == V_127 ) {
int V_134 ;
V_134 = 4 ;
if ( V_6 -> V_9 -> V_136 != NULL )
V_134 += V_6 -> V_9 -> V_136 ( V_6 ) ;
return V_134 ;
}
return - V_64 ;
}
static void F_76 ( struct V_25 * V_23 , struct V_145 * V_146 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_147 )
V_6 -> V_9 -> V_147 ( V_6 , V_27 -> V_47 , V_146 ) ;
}
static int F_77 ( struct V_25 * V_23 , struct V_145 * V_146 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
int V_72 = - V_64 ;
if ( V_6 -> V_9 -> V_148 )
V_72 = V_6 -> V_9 -> V_148 ( V_6 , V_27 -> V_47 , V_146 ) ;
return V_72 ;
}
static int F_78 ( struct V_25 * V_23 , struct V_149 * V_150 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
int V_72 ;
if ( ! V_6 -> V_9 -> V_151 )
return - V_64 ;
V_72 = V_6 -> V_9 -> V_151 ( V_6 , V_27 -> V_47 , V_27 -> V_48 , V_150 ) ;
if ( V_72 )
return V_72 ;
if ( V_27 -> V_48 )
V_72 = F_79 ( V_27 -> V_48 , V_150 ) ;
return V_72 ;
}
static int F_80 ( struct V_25 * V_23 , struct V_149 * V_150 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
int V_72 ;
if ( ! V_6 -> V_9 -> V_152 )
return - V_64 ;
V_72 = V_6 -> V_9 -> V_152 ( V_6 , V_27 -> V_47 , V_150 ) ;
if ( V_72 )
return V_72 ;
if ( V_27 -> V_48 )
V_72 = F_81 ( V_27 -> V_48 , V_150 ) ;
return V_72 ;
}
static int F_82 ( struct V_25 * V_23 ,
struct V_153 * V_154 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
struct V_25 * V_32 = V_6 -> V_28 -> V_29 ;
struct V_97 * V_97 ;
int V_36 = 0 ;
V_97 = F_83 ( sizeof( * V_97 ) , V_155 ) ;
if ( ! V_97 )
return - V_156 ;
V_36 = F_84 ( V_97 , V_32 ) ;
if ( V_36 ) {
F_85 ( V_97 ) ;
goto V_41;
}
V_27 -> V_97 = V_97 ;
V_41:
return V_36 ;
}
static void F_86 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_97 * V_97 = V_27 -> V_97 ;
if ( ! V_97 )
return;
V_27 -> V_97 = NULL ;
F_87 ( V_97 ) ;
}
static void F_88 ( struct V_25 * V_23 )
{
}
static void F_89 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
unsigned int V_157 = 0 ;
if ( V_27 -> V_158 != V_27 -> V_48 -> V_118 ) {
V_157 = 1 ;
V_27 -> V_158 = V_27 -> V_48 -> V_118 ;
}
if ( V_27 -> V_159 != V_27 -> V_48 -> V_160 ) {
V_157 = 1 ;
V_27 -> V_159 = V_27 -> V_48 -> V_160 ;
}
if ( V_27 -> V_161 != V_27 -> V_48 -> V_162 ) {
V_157 = 1 ;
V_27 -> V_161 = V_27 -> V_48 -> V_162 ;
}
if ( V_6 -> V_9 -> V_163 && V_157 )
V_6 -> V_9 -> V_163 ( V_6 , V_27 -> V_47 , V_27 -> V_48 ) ;
if ( V_157 )
F_90 ( V_27 -> V_48 ) ;
}
static int F_91 ( struct V_25 * V_23 ,
struct V_164 * V_165 )
{
struct V_26 * V_27 ;
struct V_5 * V_6 ;
if ( V_23 ) {
V_27 = F_5 ( V_23 ) ;
V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_166 )
V_6 -> V_9 -> V_166 ( V_6 , V_27 -> V_47 , V_165 ) ;
}
return 0 ;
}
static int F_92 ( struct V_26 * V_27 ,
struct V_25 * V_167 ,
int V_3 )
{
struct V_5 * V_6 = V_27 -> V_22 ;
V_27 -> V_48 = F_93 ( V_6 -> V_13 , V_3 ) ;
if ( ! V_27 -> V_48 ) {
F_94 ( V_167 , L_11 , V_3 ) ;
return - V_168 ;
}
if ( V_27 -> V_169 == V_170 )
V_27 -> V_169 = V_27 -> V_48 -> V_171 ;
F_95 ( V_167 , V_27 -> V_48 , F_89 ,
V_27 -> V_169 ) ;
return 0 ;
}
static int F_96 ( struct V_26 * V_27 ,
struct V_25 * V_167 )
{
struct V_5 * V_6 = V_27 -> V_22 ;
struct V_172 * V_20 = V_6 -> V_20 ;
struct V_173 * V_174 , * V_175 ;
bool V_176 = false ;
T_5 V_177 = 0 ;
int V_178 , V_72 ;
V_175 = V_20 -> V_175 [ V_27 -> V_47 ] ;
V_178 = F_97 ( V_175 ) ;
if ( V_178 < 0 )
V_178 = V_170 ;
V_27 -> V_169 = V_178 ;
V_174 = F_98 ( V_175 , L_12 , 0 ) ;
if ( F_99 ( V_175 ) ) {
V_72 = F_100 ( V_175 ) ;
if ( V_72 ) {
F_94 ( V_167 , L_13 , V_72 ) ;
return V_72 ;
}
V_176 = true ;
V_174 = V_175 ;
}
if ( V_6 -> V_9 -> V_179 )
V_177 = V_6 -> V_9 -> V_179 ( V_6 , V_27 -> V_47 ) ;
if ( V_174 ) {
int V_180 = F_101 ( & V_167 -> V_23 , V_174 ) ;
if ( ! V_176 && V_180 >= 0 &&
( V_6 -> V_8 & ( 1 << V_180 ) ) ) {
V_72 = F_92 ( V_27 , V_167 , V_180 ) ;
if ( V_72 ) {
F_94 ( V_167 , L_14 , V_180 , V_72 ) ;
return V_72 ;
}
} else {
V_27 -> V_48 = F_102 ( V_167 , V_174 ,
F_89 ,
V_177 ,
V_27 -> V_169 ) ;
}
}
if ( V_27 -> V_48 && V_176 )
F_103 ( V_27 -> V_48 , F_91 ) ;
if ( ! V_27 -> V_48 ) {
V_72 = F_92 ( V_27 , V_167 , V_27 -> V_47 ) ;
if ( V_72 ) {
F_94 ( V_167 , L_15 , V_27 -> V_47 , V_72 ) ;
return V_72 ;
}
}
F_104 ( V_27 -> V_48 ) ;
return 0 ;
}
static void F_105 ( struct V_25 * V_23 ,
struct V_181 * V_182 ,
void * V_183 )
{
F_106 ( & V_182 -> V_184 ,
& V_185 ) ;
}
int F_107 ( struct V_25 * V_167 )
{
struct V_26 * V_27 = F_5 ( V_167 ) ;
if ( V_27 -> V_48 ) {
F_15 ( V_27 -> V_48 ) ;
V_27 -> V_161 = - 1 ;
V_27 -> V_158 = - 1 ;
V_27 -> V_159 = - 1 ;
F_108 ( V_27 -> V_48 ) ;
}
return 0 ;
}
int F_109 ( struct V_25 * V_167 )
{
struct V_26 * V_27 = F_5 ( V_167 ) ;
F_110 ( V_167 ) ;
if ( V_27 -> V_48 ) {
F_111 ( V_27 -> V_48 ) ;
F_12 ( V_27 -> V_48 ) ;
}
return 0 ;
}
int F_112 ( struct V_5 * V_6 , struct V_186 * V_22 ,
int V_47 , char * V_14 )
{
struct V_25 * V_32 = V_6 -> V_28 -> V_29 ;
struct V_131 * V_28 = V_6 -> V_28 ;
struct V_25 * V_167 ;
struct V_26 * V_27 ;
int V_72 ;
V_167 = F_113 ( sizeof( struct V_26 ) , V_14 ,
V_187 , V_188 ) ;
if ( V_167 == NULL )
return - V_156 ;
V_167 -> V_189 = V_32 -> V_190 ;
V_167 -> V_191 = & V_192 ;
if ( V_32 -> V_191 != & V_193 ) {
memcpy ( & V_28 -> V_135 , V_32 -> V_191 ,
sizeof( struct V_191 ) ) ;
memcpy ( & V_193 , & V_28 -> V_135 ,
sizeof( struct V_191 ) ) ;
V_193 . V_136 =
F_72 ;
V_193 . V_137 =
F_71 ;
V_193 . V_129 =
F_73 ;
V_32 -> V_191 = & V_193 ;
}
F_114 ( V_167 , V_32 ) ;
V_167 -> V_194 |= V_195 ;
V_167 -> V_196 = & V_197 ;
V_167 -> V_198 = & V_199 ;
F_115 ( V_167 , & V_200 ) ;
F_116 ( V_167 , F_105 ,
NULL ) ;
F_117 ( V_167 , V_22 ) ;
V_167 -> V_23 . V_201 = V_6 -> V_20 -> V_175 [ V_47 ] ;
V_167 -> V_190 = V_32 -> V_190 ;
V_27 = F_5 ( V_167 ) ;
V_27 -> V_22 = V_6 ;
V_27 -> V_47 = V_47 ;
switch ( V_6 -> V_28 -> V_202 ) {
#ifdef F_118
case V_203 :
V_27 -> V_104 = V_204 . V_104 ;
break;
#endif
#ifdef F_119
case V_205 :
V_27 -> V_104 = V_206 . V_104 ;
break;
#endif
#ifdef F_120
case V_207 :
V_27 -> V_104 = V_208 . V_104 ;
break;
#endif
#ifdef F_121
case V_209 :
V_27 -> V_104 = V_210 . V_104 ;
break;
#endif
default:
V_27 -> V_104 = F_53 ;
break;
}
V_27 -> V_161 = - 1 ;
V_27 -> V_158 = - 1 ;
V_27 -> V_159 = - 1 ;
V_6 -> V_211 [ V_47 ] = V_167 ;
V_72 = F_122 ( V_167 ) ;
if ( V_72 ) {
F_94 ( V_32 , L_16 ,
V_72 , V_167 -> V_14 ) ;
V_6 -> V_211 [ V_47 ] = NULL ;
F_123 ( V_167 ) ;
return V_72 ;
}
F_124 ( V_167 ) ;
V_72 = F_96 ( V_27 , V_167 ) ;
if ( V_72 ) {
F_94 ( V_32 , L_17 , V_72 ) ;
F_125 ( V_167 ) ;
F_123 ( V_167 ) ;
return V_72 ;
}
return 0 ;
}
void F_126 ( struct V_25 * V_167 )
{
struct V_26 * V_27 = F_5 ( V_167 ) ;
F_124 ( V_167 ) ;
if ( V_27 -> V_48 )
F_127 ( V_27 -> V_48 ) ;
F_125 ( V_167 ) ;
F_123 ( V_167 ) ;
}
static bool F_128 ( struct V_25 * V_23 )
{
return V_23 -> V_196 == & V_197 ;
}
static int F_129 ( struct V_25 * V_23 ,
unsigned long V_212 , void * V_213 )
{
struct V_214 * V_215 = V_213 ;
struct V_25 * V_216 = V_215 -> V_217 ;
int V_36 = 0 ;
switch ( V_212 ) {
case V_218 :
if ( F_130 ( V_216 ) ) {
if ( V_215 -> V_219 )
V_36 = F_42 ( V_23 , V_216 ) ;
else
F_43 ( V_23 ) ;
}
break;
}
return F_131 ( V_36 ) ;
}
static int F_132 ( struct V_25 * V_23 , unsigned long V_212 ,
void * V_213 )
{
switch ( V_212 ) {
case V_218 :
return F_129 ( V_23 , V_212 , V_213 ) ;
}
return V_220 ;
}
int F_133 ( struct V_221 * V_222 ,
unsigned long V_212 , void * V_213 )
{
struct V_25 * V_23 = F_134 ( V_213 ) ;
if ( F_128 ( V_23 ) )
return F_132 ( V_23 , V_212 , V_213 ) ;
return V_220 ;
}
