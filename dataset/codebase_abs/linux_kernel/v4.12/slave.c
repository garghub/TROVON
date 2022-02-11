static int F_1 ( struct V_1 * V_2 , unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = & V_6 -> V_9 -> V_10 -> V_11 -> V_8 ;
int V_12 ;
V_12 = F_3 ( V_8 , V_3 , V_4 ) ;
return F_4 ( V_12 ) ;
}
static int F_5 ( struct V_13 * V_14 , int V_15 , int V_16 )
{
struct V_17 * V_10 = V_14 -> V_18 ;
if ( V_10 -> V_19 & ( 1 << V_15 ) )
return V_10 -> V_20 -> V_21 ( V_10 , V_15 , V_16 ) ;
return 0xffff ;
}
static int F_6 ( struct V_13 * V_14 , int V_15 , int V_16 , T_1 V_22 )
{
struct V_17 * V_10 = V_14 -> V_18 ;
if ( V_10 -> V_19 & ( 1 << V_15 ) )
return V_10 -> V_20 -> V_23 ( V_10 , V_15 , V_16 , V_22 ) ;
return 0 ;
}
void F_7 ( struct V_17 * V_10 )
{
V_10 -> V_24 -> V_18 = ( void * ) V_10 ;
V_10 -> V_24 -> V_25 = L_1 ;
V_10 -> V_24 -> V_26 = F_5 ;
V_10 -> V_24 -> V_27 = F_6 ;
snprintf ( V_10 -> V_24 -> V_28 , V_29 , L_2 ,
V_10 -> V_11 -> V_30 , V_10 -> V_31 ) ;
V_10 -> V_24 -> V_32 = V_10 -> V_2 ;
V_10 -> V_24 -> V_33 = ~ V_10 -> V_19 ;
}
static int F_8 ( const struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_9 -> V_10 -> V_11 -> V_34 -> V_35 ;
}
static inline bool F_9 ( struct V_36 * V_9 )
{
return ! ! V_9 -> V_37 ;
}
static void F_10 ( struct V_1 * V_2 , T_2 V_38 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_36 * V_9 = V_6 -> V_9 ;
struct V_17 * V_10 = V_9 -> V_10 ;
int V_39 = V_9 -> V_31 ;
if ( V_10 -> V_20 -> V_40 )
V_10 -> V_20 -> V_40 ( V_10 , V_39 , V_38 ) ;
if ( V_10 -> V_20 -> V_41 ) {
if ( ( V_9 -> V_42 == V_43 ||
V_9 -> V_42 == V_44 ) &&
( V_38 == V_45 ||
V_38 == V_46 ||
V_38 == V_47 ) )
V_10 -> V_20 -> V_41 ( V_10 , V_39 ) ;
}
V_9 -> V_42 = V_38 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_1 * V_48 = V_6 -> V_9 -> V_10 -> V_11 -> V_34 ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
T_2 V_42 = F_9 ( V_6 -> V_9 ) ?
V_46 : V_44 ;
int V_12 ;
if ( ! ( V_48 -> V_49 & V_50 ) )
return - V_51 ;
if ( ! F_12 ( V_2 -> V_52 , V_48 -> V_52 ) ) {
V_12 = F_13 ( V_48 , V_2 -> V_52 ) ;
if ( V_12 < 0 )
goto V_53;
}
if ( V_2 -> V_49 & V_54 ) {
V_12 = F_14 ( V_48 , 1 ) ;
if ( V_12 < 0 )
goto V_55;
}
if ( V_2 -> V_49 & V_56 ) {
V_12 = F_15 ( V_48 , 1 ) ;
if ( V_12 < 0 )
goto V_57;
}
if ( V_10 -> V_20 -> V_58 ) {
V_12 = V_10 -> V_20 -> V_58 ( V_10 , V_6 -> V_9 -> V_31 , V_6 -> V_59 ) ;
if ( V_12 )
goto V_60;
}
F_10 ( V_2 , V_42 ) ;
if ( V_6 -> V_59 )
F_16 ( V_6 -> V_59 ) ;
return 0 ;
V_60:
if ( V_2 -> V_49 & V_56 )
F_15 ( V_48 , - 1 ) ;
V_57:
if ( V_2 -> V_49 & V_54 )
F_14 ( V_48 , - 1 ) ;
V_55:
if ( ! F_12 ( V_2 -> V_52 , V_48 -> V_52 ) )
F_17 ( V_48 , V_2 -> V_52 ) ;
V_53:
return V_12 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_1 * V_48 = V_6 -> V_9 -> V_10 -> V_11 -> V_34 ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( V_6 -> V_59 )
F_19 ( V_6 -> V_59 ) ;
F_20 ( V_48 , V_2 ) ;
F_21 ( V_48 , V_2 ) ;
if ( V_2 -> V_49 & V_54 )
F_14 ( V_48 , - 1 ) ;
if ( V_2 -> V_49 & V_56 )
F_15 ( V_48 , - 1 ) ;
if ( ! F_12 ( V_2 -> V_52 , V_48 -> V_52 ) )
F_17 ( V_48 , V_2 -> V_52 ) ;
if ( V_10 -> V_20 -> V_61 )
V_10 -> V_20 -> V_61 ( V_10 , V_6 -> V_9 -> V_31 , V_6 -> V_59 ) ;
F_10 ( V_2 , V_45 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 , int V_62 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_1 * V_48 = V_6 -> V_9 -> V_10 -> V_11 -> V_34 ;
if ( V_62 & V_54 )
F_14 ( V_48 , V_2 -> V_49 & V_54 ? 1 : - 1 ) ;
if ( V_62 & V_56 )
F_15 ( V_48 , V_2 -> V_49 & V_56 ? 1 : - 1 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_1 * V_48 = V_6 -> V_9 -> V_10 -> V_11 -> V_34 ;
F_24 ( V_48 , V_2 ) ;
F_25 ( V_48 , V_2 ) ;
}
static int F_26 ( struct V_1 * V_2 , void * V_63 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_1 * V_48 = V_6 -> V_9 -> V_10 -> V_11 -> V_34 ;
struct V_64 * V_15 = V_63 ;
int V_12 ;
if ( ! F_27 ( V_15 -> V_65 ) )
return - V_66 ;
if ( ! ( V_2 -> V_49 & V_50 ) )
goto V_53;
if ( ! F_12 ( V_15 -> V_65 , V_48 -> V_52 ) ) {
V_12 = F_13 ( V_48 , V_15 -> V_65 ) ;
if ( V_12 < 0 )
return V_12 ;
}
if ( ! F_12 ( V_2 -> V_52 , V_48 -> V_52 ) )
F_17 ( V_48 , V_2 -> V_52 ) ;
V_53:
F_28 ( V_2 -> V_52 , V_15 -> V_65 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
const struct V_67 * V_68 ,
struct V_69 * V_70 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_36 * V_9 = V_6 -> V_9 ;
struct V_17 * V_10 = V_9 -> V_10 ;
if ( F_30 ( V_70 ) ) {
if ( ! V_10 -> V_20 -> V_71 || ! V_10 -> V_20 -> V_72 )
return - V_73 ;
return V_10 -> V_20 -> V_71 ( V_10 , V_9 -> V_31 , V_68 , V_70 ) ;
}
V_10 -> V_20 -> V_72 ( V_10 , V_9 -> V_31 , V_68 , V_70 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
const struct V_67 * V_68 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( ! V_10 -> V_20 -> V_74 )
return - V_73 ;
return V_10 -> V_20 -> V_74 ( V_10 , V_6 -> V_9 -> V_31 , V_68 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
T_3 * V_75 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( V_10 -> V_20 -> V_76 )
return V_10 -> V_20 -> V_76 ( V_10 , V_6 -> V_9 -> V_31 , V_68 , V_75 ) ;
return - V_73 ;
}
static int F_33 ( struct V_1 * V_2 ,
const struct V_77 * V_78 ,
struct V_69 * V_70 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( F_30 ( V_70 ) ) {
if ( ! V_10 -> V_20 -> V_79 || ! V_10 -> V_20 -> V_80 )
return - V_73 ;
return V_10 -> V_20 -> V_79 ( V_10 , V_6 -> V_9 -> V_31 , V_78 , V_70 ) ;
}
V_10 -> V_20 -> V_80 ( V_10 , V_6 -> V_9 -> V_31 , V_78 , V_70 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
const struct V_77 * V_78 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
int V_81 = - V_73 ;
if ( V_10 -> V_20 -> V_82 )
V_81 = V_10 -> V_20 -> V_82 ( V_10 , V_6 -> V_9 -> V_31 , V_78 ) ;
return V_81 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_77 * V_78 ,
T_3 * V_75 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( V_10 -> V_20 -> V_83 )
return V_10 -> V_20 -> V_83 ( V_10 , V_6 -> V_9 -> V_31 , V_78 , V_75 ) ;
return - V_73 ;
}
static int F_36 ( struct V_1 * V_2 ,
const struct V_84 * V_85 ,
struct V_69 * V_70 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( F_30 ( V_70 ) ) {
if ( ! V_10 -> V_20 -> V_86 || ! V_10 -> V_20 -> V_87 )
return - V_73 ;
return V_10 -> V_20 -> V_86 ( V_10 , V_6 -> V_9 -> V_31 , V_85 , V_70 ) ;
}
V_10 -> V_20 -> V_87 ( V_10 , V_6 -> V_9 -> V_31 , V_85 , V_70 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
const struct V_84 * V_85 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( V_10 -> V_20 -> V_88 )
return V_10 -> V_20 -> V_88 ( V_10 , V_6 -> V_9 -> V_31 , V_85 ) ;
return - V_73 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_84 * V_85 ,
T_3 * V_75 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( V_10 -> V_20 -> V_89 )
return V_10 -> V_20 -> V_89 ( V_10 , V_6 -> V_9 -> V_31 , V_85 , V_75 ) ;
return - V_73 ;
}
static int F_39 ( struct V_1 * V_2 , struct V_90 * V_91 , int V_92 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_59 != NULL )
return F_40 ( V_6 -> V_59 , V_91 , V_92 ) ;
return - V_73 ;
}
static int F_41 ( struct V_1 * V_2 ,
const struct V_93 * V_94 ,
struct V_69 * V_70 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( F_30 ( V_70 ) )
return V_10 -> V_20 -> V_40 ? 0 : - V_73 ;
F_10 ( V_2 , V_94 -> V_95 . V_42 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
const struct V_93 * V_94 ,
struct V_69 * V_70 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( F_30 ( V_70 ) )
return 0 ;
if ( V_10 -> V_20 -> V_96 )
return V_10 -> V_20 -> V_96 ( V_10 , V_6 -> V_9 -> V_31 ,
V_94 -> V_95 . V_97 ) ;
return 0 ;
}
static unsigned int F_43 ( struct V_17 * V_10 ,
unsigned int V_98 )
{
int V_99 ;
for ( V_99 = 0 ; V_99 < V_10 -> V_100 ; ++ V_99 ) {
struct V_36 * V_9 = & V_10 -> V_101 [ V_99 ] ;
if ( V_9 && V_9 -> V_98 && V_9 -> V_98 < V_98 )
V_98 = V_9 -> V_98 ;
}
return V_98 ;
}
static int F_44 ( struct V_1 * V_2 ,
const struct V_93 * V_94 ,
struct V_69 * V_70 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
unsigned long V_102 = F_45 ( V_94 -> V_95 . V_98 ) ;
unsigned int V_98 = F_46 ( V_102 ) ;
if ( F_30 ( V_70 ) ) {
if ( V_10 -> V_103 && V_98 < V_10 -> V_103 )
return - V_104 ;
if ( V_10 -> V_105 && V_98 > V_10 -> V_105 )
return - V_104 ;
return 0 ;
}
V_6 -> V_9 -> V_98 = V_98 ;
V_98 = F_43 ( V_10 , V_98 ) ;
if ( V_10 -> V_20 -> V_106 )
return V_10 -> V_20 -> V_106 ( V_10 , V_98 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
const struct V_93 * V_94 ,
struct V_69 * V_70 )
{
int V_81 ;
switch ( V_94 -> V_28 ) {
case V_107 :
V_81 = F_41 ( V_2 , V_94 , V_70 ) ;
break;
case V_108 :
V_81 = F_42 ( V_2 , V_94 , V_70 ) ;
break;
case V_109 :
V_81 = F_44 ( V_2 , V_94 , V_70 ) ;
break;
default:
V_81 = - V_73 ;
break;
}
return V_81 ;
}
static int F_48 ( struct V_1 * V_2 ,
const struct V_110 * V_111 ,
struct V_69 * V_70 )
{
int V_12 ;
switch ( V_111 -> V_28 ) {
case V_112 :
V_12 = F_33 ( V_2 ,
F_49 ( V_111 ) ,
V_70 ) ;
break;
case V_113 :
V_12 = F_36 ( V_2 , F_50 ( V_111 ) ,
V_70 ) ;
break;
case V_114 :
V_12 = F_29 ( V_2 ,
F_51 ( V_111 ) ,
V_70 ) ;
break;
default:
V_12 = - V_73 ;
break;
}
return V_12 ;
}
static int F_52 ( struct V_1 * V_2 ,
const struct V_110 * V_111 )
{
int V_12 ;
switch ( V_111 -> V_28 ) {
case V_112 :
V_12 = F_34 ( V_2 ,
F_49 ( V_111 ) ) ;
break;
case V_113 :
V_12 = F_37 ( V_2 , F_50 ( V_111 ) ) ;
break;
case V_114 :
V_12 = F_31 ( V_2 ,
F_51 ( V_111 ) ) ;
break;
default:
V_12 = - V_73 ;
break;
}
return V_12 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_110 * V_111 ,
T_3 * V_75 )
{
int V_12 ;
switch ( V_111 -> V_28 ) {
case V_112 :
V_12 = F_35 ( V_2 ,
F_49 ( V_111 ) ,
V_75 ) ;
break;
case V_113 :
V_12 = F_38 ( V_2 , F_50 ( V_111 ) ,
V_75 ) ;
break;
case V_114 :
V_12 = F_32 ( V_2 ,
F_51 ( V_111 ) ,
V_75 ) ;
break;
default:
V_12 = - V_73 ;
break;
}
return V_12 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_1 * V_115 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_116 V_117 = {
. V_118 = V_6 -> V_9 -> V_10 -> V_31 ,
. V_39 = V_6 -> V_9 -> V_31 ,
. V_115 = V_115 ,
} ;
int V_12 ;
V_6 -> V_9 -> V_37 = V_115 ;
V_12 = F_1 ( V_2 , V_119 , & V_117 ) ;
if ( V_12 )
V_6 -> V_9 -> V_37 = NULL ;
return V_12 ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_1 * V_115 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_116 V_117 = {
. V_118 = V_6 -> V_9 -> V_10 -> V_31 ,
. V_39 = V_6 -> V_9 -> V_31 ,
. V_115 = V_115 ,
} ;
int V_12 ;
V_6 -> V_9 -> V_37 = NULL ;
V_12 = F_1 ( V_2 , V_120 , & V_117 ) ;
if ( V_12 )
F_56 ( V_2 , L_3 ) ;
F_10 ( V_2 , V_44 ) ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_93 * V_94 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
switch ( V_94 -> V_28 ) {
case V_121 :
V_94 -> V_95 . V_122 . V_123 = sizeof( V_10 -> V_31 ) ;
memcpy ( & V_94 -> V_95 . V_122 . V_28 , & V_10 -> V_31 , V_94 -> V_95 . V_122 . V_123 ) ;
break;
default:
return - V_73 ;
}
return 0 ;
}
static inline T_4 F_58 ( struct V_5 * V_6 ,
struct V_124 * V_125 )
{
#ifdef F_59
if ( V_6 -> V_126 )
F_60 ( V_6 -> V_126 , V_125 ) ;
#else
F_61 () ;
#endif
return V_127 ;
}
static T_4 F_62 ( struct V_124 * V_125 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_124 * V_128 ;
V_2 -> V_129 . V_130 ++ ;
V_2 -> V_129 . V_131 += V_125 -> V_132 ;
V_128 = V_6 -> V_133 ( V_125 , V_2 ) ;
if ( ! V_128 )
return V_127 ;
if ( F_63 ( F_64 ( V_2 ) ) )
return F_58 ( V_6 , V_128 ) ;
V_128 -> V_2 = V_6 -> V_9 -> V_10 -> V_11 -> V_34 ;
F_65 ( V_128 ) ;
return V_127 ;
}
static int
F_66 ( struct V_1 * V_2 ,
struct V_134 * V_92 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_12 = - V_73 ;
if ( V_6 -> V_59 != NULL )
V_12 = F_67 ( V_6 -> V_59 , V_92 ) ;
return V_12 ;
}
static int
F_68 ( struct V_1 * V_2 ,
const struct V_134 * V_92 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_59 != NULL )
return F_69 ( V_6 -> V_59 , V_92 ) ;
return - V_73 ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_135 * V_136 )
{
F_71 ( V_136 -> V_137 , L_4 , sizeof( V_136 -> V_137 ) ) ;
F_71 ( V_136 -> V_138 , L_5 , sizeof( V_136 -> V_138 ) ) ;
F_71 ( V_136 -> V_139 , L_6 , sizeof( V_136 -> V_139 ) ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( V_10 -> V_20 -> V_140 )
return V_10 -> V_20 -> V_140 ( V_10 , V_6 -> V_9 -> V_31 ) ;
return - V_73 ;
}
static void
F_73 ( struct V_1 * V_2 , struct V_141 * V_142 , void * V_143 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( V_10 -> V_20 -> V_144 )
V_10 -> V_20 -> V_144 ( V_10 , V_6 -> V_9 -> V_31 , V_142 , V_143 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_59 != NULL )
return F_75 ( V_6 -> V_59 ) ;
return - V_73 ;
}
static T_5 F_76 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_59 != NULL ) {
F_77 ( V_6 -> V_59 ) ;
return V_6 -> V_59 -> V_145 ;
}
return - V_73 ;
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( V_10 -> V_146 && V_10 -> V_146 -> V_147 )
return V_10 -> V_146 -> V_147 ;
if ( V_10 -> V_20 -> V_148 )
return V_10 -> V_20 -> V_148 ( V_10 ) ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_149 * V_150 , T_2 * V_151 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( V_10 -> V_20 -> V_152 )
return V_10 -> V_20 -> V_152 ( V_10 , V_150 , V_151 ) ;
return - V_73 ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_149 * V_150 , T_2 * V_151 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( V_10 -> V_20 -> V_153 )
return V_10 -> V_20 -> V_153 ( V_10 , V_150 , V_151 ) ;
return - V_73 ;
}
static void F_81 ( struct V_1 * V_2 ,
T_6 V_154 , T_7 * V_151 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( V_154 == V_155 ) {
int V_132 = V_156 ;
strncpy ( V_151 , L_7 , V_132 ) ;
strncpy ( V_151 + V_132 , L_8 , V_132 ) ;
strncpy ( V_151 + 2 * V_132 , L_9 , V_132 ) ;
strncpy ( V_151 + 3 * V_132 , L_10 , V_132 ) ;
if ( V_10 -> V_20 -> V_157 )
V_10 -> V_20 -> V_157 ( V_10 , V_6 -> V_9 -> V_31 , V_151 + 4 * V_132 ) ;
}
}
static void F_82 ( struct V_1 * V_2 ,
struct V_158 * V_129 ,
T_8 * V_151 )
{
struct V_159 * V_11 = V_2 -> V_160 ;
struct V_17 * V_10 = V_11 -> V_161 ;
T_9 V_162 = V_11 -> V_162 ;
int V_163 = 0 ;
if ( V_11 -> V_164 . V_165 ) {
V_163 = V_11 -> V_164 . V_165 ( V_2 ,
V_155 ) ;
V_11 -> V_164 . V_166 ( V_2 , V_129 , V_151 ) ;
}
if ( V_10 -> V_20 -> V_166 )
V_10 -> V_20 -> V_166 ( V_10 , V_162 , V_151 + V_163 ) ;
}
static int F_83 ( struct V_1 * V_2 , int V_167 )
{
struct V_159 * V_11 = V_2 -> V_160 ;
struct V_17 * V_10 = V_11 -> V_161 ;
int V_163 = 0 ;
if ( V_11 -> V_164 . V_165 )
V_163 += V_11 -> V_164 . V_165 ( V_2 , V_167 ) ;
if ( V_167 == V_155 && V_10 -> V_20 -> V_165 )
V_163 += V_10 -> V_20 -> V_165 ( V_10 ) ;
return V_163 ;
}
static void F_84 ( struct V_1 * V_2 ,
T_6 V_154 , T_7 * V_151 )
{
struct V_159 * V_11 = V_2 -> V_160 ;
struct V_17 * V_10 = V_11 -> V_161 ;
T_9 V_162 = V_11 -> V_162 ;
int V_132 = V_156 ;
int V_168 = 0 , V_163 ;
unsigned int V_99 ;
T_7 V_169 [ 4 ] ;
T_7 * V_170 ;
snprintf ( V_169 , sizeof( V_169 ) , L_11 , V_162 ) ;
V_169 [ sizeof( V_169 ) - 1 ] = '_' ;
if ( V_11 -> V_164 . V_165 ) {
V_168 = V_11 -> V_164 . V_165 ( V_2 ,
V_155 ) ;
V_11 -> V_164 . V_157 ( V_2 , V_154 , V_151 ) ;
}
if ( V_154 == V_155 && V_10 -> V_20 -> V_157 ) {
V_170 = V_151 + V_168 * V_132 ;
V_10 -> V_20 -> V_157 ( V_10 , V_162 , V_170 ) ;
V_163 = V_10 -> V_20 -> V_165 ( V_10 ) ;
for ( V_99 = 0 ; V_99 < V_163 ; V_99 ++ ) {
memmove ( V_170 + ( V_99 * V_132 + sizeof( V_169 ) ) ,
V_170 + V_99 * V_132 , V_132 - sizeof( V_169 ) ) ;
memcpy ( V_170 + V_99 * V_132 , V_169 , sizeof( V_169 ) ) ;
}
}
}
static void F_85 ( struct V_1 * V_2 ,
struct V_158 * V_129 ,
T_8 * V_151 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
V_151 [ 0 ] = V_2 -> V_129 . V_130 ;
V_151 [ 1 ] = V_2 -> V_129 . V_131 ;
V_151 [ 2 ] = V_2 -> V_129 . V_171 ;
V_151 [ 3 ] = V_2 -> V_129 . V_172 ;
if ( V_10 -> V_20 -> V_166 )
V_10 -> V_20 -> V_166 ( V_10 , V_6 -> V_9 -> V_31 , V_151 + 4 ) ;
}
static int F_86 ( struct V_1 * V_2 , int V_167 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( V_167 == V_155 ) {
int V_163 ;
V_163 = 4 ;
if ( V_10 -> V_20 -> V_165 )
V_163 += V_10 -> V_20 -> V_165 ( V_10 ) ;
return V_163 ;
}
return - V_73 ;
}
static void F_87 ( struct V_1 * V_2 , struct V_173 * V_174 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( V_10 -> V_20 -> V_175 )
V_10 -> V_20 -> V_175 ( V_10 , V_6 -> V_9 -> V_31 , V_174 ) ;
}
static int F_88 ( struct V_1 * V_2 , struct V_173 * V_174 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
int V_81 = - V_73 ;
if ( V_10 -> V_20 -> V_176 )
V_81 = V_10 -> V_20 -> V_176 ( V_10 , V_6 -> V_9 -> V_31 , V_174 ) ;
return V_81 ;
}
static int F_89 ( struct V_1 * V_2 , struct V_177 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
int V_81 ;
if ( ! V_10 -> V_20 -> V_178 )
return - V_73 ;
V_81 = V_10 -> V_20 -> V_178 ( V_10 , V_6 -> V_9 -> V_31 , V_6 -> V_59 , V_3 ) ;
if ( V_81 )
return V_81 ;
if ( V_6 -> V_59 )
V_81 = F_90 ( V_6 -> V_59 , V_3 ) ;
return V_81 ;
}
static int F_91 ( struct V_1 * V_2 , struct V_177 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
int V_81 ;
if ( ! V_10 -> V_20 -> V_179 )
return - V_73 ;
V_81 = V_10 -> V_20 -> V_179 ( V_10 , V_6 -> V_9 -> V_31 , V_3 ) ;
if ( V_81 )
return V_81 ;
if ( V_6 -> V_59 )
V_81 = F_92 ( V_6 -> V_59 , V_3 ) ;
return V_81 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_180 * V_181 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
struct V_1 * V_48 = V_10 -> V_11 -> V_34 ;
struct V_126 * V_126 ;
int V_12 = 0 ;
V_126 = F_94 ( sizeof( * V_126 ) , V_182 ) ;
if ( ! V_126 )
return - V_183 ;
V_12 = F_95 ( V_126 , V_48 ) ;
if ( V_12 ) {
F_96 ( V_126 ) ;
goto V_53;
}
V_6 -> V_126 = V_126 ;
V_53:
return V_12 ;
}
static void F_97 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_126 * V_126 = V_6 -> V_126 ;
if ( ! V_126 )
return;
V_6 -> V_126 = NULL ;
F_98 ( V_126 ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
}
static int F_100 ( struct V_1 * V_2 ,
char * V_25 , T_10 V_132 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( snprintf ( V_25 , V_132 , L_12 , V_6 -> V_9 -> V_31 ) >= V_132 )
return - V_184 ;
return 0 ;
}
static struct V_185 *
F_101 ( struct V_5 * V_6 ,
unsigned long V_186 )
{
struct V_185 * V_187 ;
F_102 (mall_tc_entry, &p->mall_tc_list, list)
if ( V_187 -> V_186 == V_186 )
return V_187 ;
return NULL ;
}
static int F_103 ( struct V_1 * V_2 ,
T_11 V_188 ,
struct V_189 * V_190 ,
bool V_191 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_185 * V_187 ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
struct V_192 * V_192 = F_104 ( V_2 ) ;
struct V_5 * V_193 ;
struct V_1 * V_194 ;
const struct V_195 * V_63 ;
int V_12 = - V_73 ;
F_105 ( V_196 ) ;
int V_35 ;
if ( ! V_10 -> V_20 -> V_197 )
return V_12 ;
if ( ! F_106 ( V_190 -> V_198 ) )
return V_12 ;
F_107 ( V_190 -> V_198 , & V_196 ) ;
V_63 = F_108 ( & V_196 , struct V_195 , V_199 ) ;
if ( F_109 ( V_63 ) && V_188 == F_110 ( V_200 ) ) {
struct V_201 * V_202 ;
V_35 = F_111 ( V_63 ) ;
V_194 = F_112 ( V_192 , V_35 ) ;
if ( ! V_194 )
return - V_184 ;
if ( ! F_113 ( V_194 ) )
return - V_73 ;
V_187 = F_94 ( sizeof( * V_187 ) , V_182 ) ;
if ( ! V_187 )
return - V_183 ;
V_187 -> V_186 = V_190 -> V_186 ;
V_187 -> type = V_203 ;
V_202 = & V_187 -> V_202 ;
V_193 = F_2 ( V_194 ) ;
V_202 -> V_204 = V_193 -> V_9 -> V_31 ;
V_202 -> V_191 = V_191 ;
V_12 = V_10 -> V_20 -> V_197 ( V_10 , V_6 -> V_9 -> V_31 , V_202 ,
V_191 ) ;
if ( V_12 ) {
F_96 ( V_187 ) ;
return V_12 ;
}
F_114 ( & V_187 -> V_199 , & V_6 -> V_205 ) ;
}
return 0 ;
}
static void F_115 ( struct V_1 * V_2 ,
struct V_189 * V_190 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_185 * V_187 ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( ! V_10 -> V_20 -> V_206 )
return;
V_187 = F_101 ( V_6 , V_190 -> V_186 ) ;
if ( ! V_187 )
return;
F_116 ( & V_187 -> V_199 ) ;
switch ( V_187 -> type ) {
case V_203 :
V_10 -> V_20 -> V_206 ( V_10 , V_6 -> V_9 -> V_31 ,
& V_187 -> V_202 ) ;
break;
default:
F_117 ( 1 ) ;
}
F_96 ( V_187 ) ;
}
static int F_118 ( struct V_1 * V_2 , T_5 V_207 ,
T_11 V_188 , struct V_208 * V_209 )
{
bool V_191 = F_119 ( V_207 ) == F_119 ( V_210 ) ;
int V_81 = - V_73 ;
switch ( V_209 -> type ) {
case V_211 :
switch ( V_209 -> V_212 -> V_213 ) {
case V_214 :
return F_103 ( V_2 , V_188 ,
V_209 -> V_212 ,
V_191 ) ;
case V_215 :
F_115 ( V_2 , V_209 -> V_212 ) ;
return 0 ;
}
default:
break;
}
return V_81 ;
}
void F_120 ( struct V_216 * V_20 )
{
V_20 -> V_165 = F_83 ;
V_20 -> V_166 = F_82 ;
V_20 -> V_157 = F_84 ;
}
static int F_121 ( struct V_1 * V_2 ,
struct V_217 * V_218 , T_5 * V_219 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( ! V_10 -> V_20 -> V_220 )
return - V_73 ;
return V_10 -> V_20 -> V_220 ( V_10 , V_6 -> V_9 -> V_31 , V_218 , V_219 ) ;
}
static int F_122 ( struct V_1 * V_2 ,
struct V_217 * V_218 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( ! V_10 -> V_20 -> V_221 )
return - V_73 ;
return V_10 -> V_20 -> V_221 ( V_10 , V_6 -> V_9 -> V_31 , V_218 ) ;
}
static void F_123 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
unsigned int V_222 = 0 ;
if ( V_6 -> V_223 != V_6 -> V_59 -> V_145 ) {
V_222 = 1 ;
V_6 -> V_223 = V_6 -> V_59 -> V_145 ;
}
if ( V_6 -> V_224 != V_6 -> V_59 -> V_225 ) {
V_222 = 1 ;
V_6 -> V_224 = V_6 -> V_59 -> V_225 ;
}
if ( V_6 -> V_226 != V_6 -> V_59 -> V_227 ) {
V_222 = 1 ;
V_6 -> V_226 = V_6 -> V_59 -> V_227 ;
}
if ( V_10 -> V_20 -> V_228 && V_222 )
V_10 -> V_20 -> V_228 ( V_10 , V_6 -> V_9 -> V_31 , V_6 -> V_59 ) ;
if ( V_222 )
F_124 ( V_6 -> V_59 ) ;
}
static int F_125 ( struct V_1 * V_2 ,
struct V_229 * V_230 )
{
struct V_5 * V_6 ;
struct V_17 * V_10 ;
if ( V_2 ) {
V_6 = F_2 ( V_2 ) ;
V_10 = V_6 -> V_9 -> V_10 ;
if ( V_10 -> V_20 -> V_231 )
V_10 -> V_20 -> V_231 ( V_10 , V_6 -> V_9 -> V_31 , V_230 ) ;
}
return 0 ;
}
static int F_126 ( struct V_5 * V_6 ,
struct V_1 * V_232 ,
int V_15 )
{
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
V_6 -> V_59 = F_127 ( V_10 -> V_24 , V_15 ) ;
if ( ! V_6 -> V_59 ) {
F_56 ( V_232 , L_13 , V_15 ) ;
return - V_233 ;
}
if ( V_6 -> V_234 == V_235 )
V_6 -> V_234 = V_6 -> V_59 -> V_236 ;
return F_128 ( V_232 , V_6 -> V_59 , F_123 ,
V_6 -> V_234 ) ;
}
static int F_129 ( struct V_5 * V_6 ,
struct V_1 * V_232 )
{
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
struct V_237 * V_238 , * V_239 ;
bool V_240 = false ;
T_5 V_241 = 0 ;
int V_242 , V_81 ;
V_239 = V_6 -> V_9 -> V_243 ;
V_242 = F_130 ( V_239 ) ;
if ( V_242 < 0 )
V_242 = V_235 ;
V_6 -> V_234 = V_242 ;
V_238 = F_131 ( V_239 , L_14 , 0 ) ;
if ( ! V_238 && F_132 ( V_239 ) ) {
V_81 = F_133 ( V_239 ) ;
if ( V_81 ) {
F_56 ( V_232 , L_15 , V_81 ) ;
return V_81 ;
}
V_240 = true ;
V_238 = F_134 ( V_239 ) ;
}
if ( V_10 -> V_20 -> V_244 )
V_241 = V_10 -> V_20 -> V_244 ( V_10 , V_6 -> V_9 -> V_31 ) ;
if ( V_238 ) {
int V_245 = F_135 ( & V_232 -> V_2 , V_238 ) ;
if ( ! V_240 && V_245 >= 0 &&
( V_10 -> V_19 & ( 1 << V_245 ) ) ) {
V_81 = F_126 ( V_6 , V_232 , V_245 ) ;
if ( V_81 ) {
F_56 ( V_232 , L_16 , V_245 , V_81 ) ;
F_136 ( V_238 ) ;
return V_81 ;
}
} else {
V_6 -> V_59 = F_137 ( V_232 , V_238 ,
F_123 ,
V_241 ,
V_6 -> V_234 ) ;
}
F_136 ( V_238 ) ;
}
if ( V_6 -> V_59 && V_240 )
F_138 ( V_6 -> V_59 , F_125 ) ;
if ( ! V_6 -> V_59 ) {
V_81 = F_126 ( V_6 , V_232 , V_6 -> V_9 -> V_31 ) ;
if ( V_81 ) {
F_56 ( V_232 , L_17 ,
V_6 -> V_9 -> V_31 , V_81 ) ;
if ( V_240 )
F_139 ( V_239 ) ;
return V_81 ;
}
}
F_140 ( V_6 -> V_59 ) ;
return 0 ;
}
static void F_141 ( struct V_1 * V_2 ,
struct V_246 * V_247 ,
void * V_248 )
{
F_142 ( & V_247 -> V_249 ,
& V_250 ) ;
}
int F_143 ( struct V_1 * V_232 )
{
struct V_5 * V_6 = F_2 ( V_232 ) ;
F_144 ( V_232 ) ;
if ( V_6 -> V_59 ) {
F_19 ( V_6 -> V_59 ) ;
V_6 -> V_226 = - 1 ;
V_6 -> V_223 = - 1 ;
V_6 -> V_224 = - 1 ;
F_145 ( V_6 -> V_59 ) ;
}
return 0 ;
}
int F_146 ( struct V_1 * V_232 )
{
struct V_5 * V_6 = F_2 ( V_232 ) ;
F_147 ( V_232 ) ;
if ( V_6 -> V_59 ) {
F_148 ( V_6 -> V_59 ) ;
F_16 ( V_6 -> V_59 ) ;
}
return 0 ;
}
int F_149 ( struct V_17 * V_10 , struct V_251 * V_32 ,
int V_39 , const char * V_25 )
{
struct V_159 * V_11 = V_10 -> V_11 ;
struct V_1 * V_48 ;
struct V_1 * V_232 ;
struct V_5 * V_6 ;
int V_81 ;
V_48 = V_10 -> V_11 -> V_34 ;
if ( V_10 -> V_34 )
V_48 = V_10 -> V_34 ;
V_232 = F_150 ( sizeof( struct V_5 ) , V_25 ,
V_252 , V_253 ) ;
if ( V_232 == NULL )
return - V_183 ;
V_232 -> V_254 = V_48 -> V_255 | V_256 ;
V_232 -> V_257 |= V_256 ;
V_232 -> V_216 = & V_258 ;
F_151 ( V_232 , V_48 ) ;
V_232 -> V_259 |= V_260 ;
V_232 -> V_261 = & V_262 ;
V_232 -> V_263 = & V_264 ;
V_232 -> V_265 = 0 ;
V_232 -> V_266 = V_267 ;
F_152 ( V_232 , & V_268 ) ;
F_153 ( V_232 , F_141 ,
NULL ) ;
F_154 ( V_232 , V_32 ) ;
V_232 -> V_2 . V_269 = V_10 -> V_101 [ V_39 ] . V_243 ;
V_232 -> V_255 = V_48 -> V_255 ;
V_6 = F_2 ( V_232 ) ;
V_6 -> V_9 = & V_10 -> V_101 [ V_39 ] ;
F_155 ( & V_6 -> V_205 ) ;
V_6 -> V_133 = V_11 -> V_270 -> V_133 ;
V_6 -> V_226 = - 1 ;
V_6 -> V_223 = - 1 ;
V_6 -> V_224 = - 1 ;
V_10 -> V_101 [ V_39 ] . V_271 = V_232 ;
V_81 = F_156 ( V_232 ) ;
if ( V_81 ) {
F_56 ( V_48 , L_18 ,
V_81 , V_232 -> V_25 ) ;
V_10 -> V_101 [ V_39 ] . V_271 = NULL ;
F_157 ( V_232 ) ;
return V_81 ;
}
F_158 ( V_232 ) ;
V_81 = F_129 ( V_6 , V_232 ) ;
if ( V_81 ) {
F_56 ( V_48 , L_19 , V_81 ) ;
F_159 ( V_232 ) ;
F_157 ( V_232 ) ;
return V_81 ;
}
return 0 ;
}
void F_160 ( struct V_1 * V_232 )
{
struct V_5 * V_6 = F_2 ( V_232 ) ;
struct V_237 * V_239 ;
V_239 = V_6 -> V_9 -> V_243 ;
F_158 ( V_232 ) ;
if ( V_6 -> V_59 ) {
F_161 ( V_6 -> V_59 ) ;
if ( F_132 ( V_239 ) )
F_139 ( V_239 ) ;
}
F_159 ( V_232 ) ;
F_157 ( V_232 ) ;
}
static bool F_113 ( struct V_1 * V_2 )
{
return V_2 -> V_261 == & V_262 ;
}
static int F_162 ( struct V_1 * V_2 ,
struct V_272 * V_117 )
{
int V_12 = V_273 ;
if ( F_163 ( V_117 -> V_274 ) ) {
if ( V_117 -> V_275 ) {
V_12 = F_54 ( V_2 , V_117 -> V_274 ) ;
V_12 = F_164 ( V_12 ) ;
} else {
F_55 ( V_2 , V_117 -> V_274 ) ;
V_12 = V_276 ;
}
}
return V_12 ;
}
static int F_165 ( struct V_277 * V_278 ,
unsigned long V_279 , void * V_280 )
{
struct V_1 * V_2 = F_166 ( V_280 ) ;
if ( V_2 -> V_261 != & V_262 )
return V_273 ;
if ( V_279 == V_281 )
return F_162 ( V_2 , V_280 ) ;
return V_273 ;
}
int F_167 ( void )
{
return F_168 ( & V_282 ) ;
}
void F_169 ( void )
{
int V_12 ;
V_12 = F_170 ( & V_282 ) ;
if ( V_12 )
F_171 ( L_20 , V_12 ) ;
}
