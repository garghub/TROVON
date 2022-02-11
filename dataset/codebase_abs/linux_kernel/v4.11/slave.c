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
static int F_43 ( struct V_17 * V_10 ,
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
if ( F_30 ( V_70 ) )
return 0 ;
V_6 -> V_9 -> V_98 = V_98 ;
V_98 = F_43 ( V_10 , V_98 ) ;
if ( V_10 -> V_20 -> V_103 )
return V_10 -> V_20 -> V_103 ( V_10 , V_98 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
const struct V_93 * V_94 ,
struct V_69 * V_70 )
{
int V_81 ;
switch ( V_94 -> V_28 ) {
case V_104 :
V_81 = F_41 ( V_2 , V_94 , V_70 ) ;
break;
case V_105 :
V_81 = F_42 ( V_2 , V_94 , V_70 ) ;
break;
case V_106 :
V_81 = F_44 ( V_2 , V_94 , V_70 ) ;
break;
default:
V_81 = - V_73 ;
break;
}
return V_81 ;
}
static int F_48 ( struct V_1 * V_2 ,
const struct V_107 * V_108 ,
struct V_69 * V_70 )
{
int V_12 ;
switch ( V_108 -> V_28 ) {
case V_109 :
V_12 = F_33 ( V_2 ,
F_49 ( V_108 ) ,
V_70 ) ;
break;
case V_110 :
V_12 = F_36 ( V_2 , F_50 ( V_108 ) ,
V_70 ) ;
break;
case V_111 :
V_12 = F_29 ( V_2 ,
F_51 ( V_108 ) ,
V_70 ) ;
break;
default:
V_12 = - V_73 ;
break;
}
return V_12 ;
}
static int F_52 ( struct V_1 * V_2 ,
const struct V_107 * V_108 )
{
int V_12 ;
switch ( V_108 -> V_28 ) {
case V_109 :
V_12 = F_34 ( V_2 ,
F_49 ( V_108 ) ) ;
break;
case V_110 :
V_12 = F_37 ( V_2 , F_50 ( V_108 ) ) ;
break;
case V_111 :
V_12 = F_31 ( V_2 ,
F_51 ( V_108 ) ) ;
break;
default:
V_12 = - V_73 ;
break;
}
return V_12 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_107 * V_108 ,
T_3 * V_75 )
{
int V_12 ;
switch ( V_108 -> V_28 ) {
case V_109 :
V_12 = F_35 ( V_2 ,
F_49 ( V_108 ) ,
V_75 ) ;
break;
case V_110 :
V_12 = F_38 ( V_2 , F_50 ( V_108 ) ,
V_75 ) ;
break;
case V_111 :
V_12 = F_32 ( V_2 ,
F_51 ( V_108 ) ,
V_75 ) ;
break;
default:
V_12 = - V_73 ;
break;
}
return V_12 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_1 * V_112 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_113 V_114 = {
. V_115 = V_6 -> V_9 -> V_10 -> V_31 ,
. V_39 = V_6 -> V_9 -> V_31 ,
. V_112 = V_112 ,
} ;
int V_12 ;
V_6 -> V_9 -> V_37 = V_112 ;
V_12 = F_1 ( V_2 , V_116 , & V_114 ) ;
if ( V_12 )
V_6 -> V_9 -> V_37 = NULL ;
return V_12 ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_1 * V_112 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_113 V_114 = {
. V_115 = V_6 -> V_9 -> V_10 -> V_31 ,
. V_39 = V_6 -> V_9 -> V_31 ,
. V_112 = V_112 ,
} ;
int V_12 ;
V_6 -> V_9 -> V_37 = NULL ;
V_12 = F_1 ( V_2 , V_117 , & V_114 ) ;
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
case V_118 :
V_94 -> V_95 . V_119 . V_120 = sizeof( V_10 -> V_31 ) ;
memcpy ( & V_94 -> V_95 . V_119 . V_28 , & V_10 -> V_31 , V_94 -> V_95 . V_119 . V_120 ) ;
break;
default:
return - V_73 ;
}
return 0 ;
}
static inline T_4 F_58 ( struct V_5 * V_6 ,
struct V_121 * V_122 )
{
#ifdef F_59
if ( V_6 -> V_123 )
F_60 ( V_6 -> V_123 , V_122 ) ;
#else
F_61 () ;
#endif
return V_124 ;
}
static T_4 F_62 ( struct V_121 * V_122 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_121 * V_125 ;
V_2 -> V_126 . V_127 ++ ;
V_2 -> V_126 . V_128 += V_122 -> V_129 ;
V_125 = V_6 -> V_130 ( V_122 , V_2 ) ;
if ( ! V_125 )
return V_124 ;
if ( F_63 ( F_64 ( V_2 ) ) )
return F_58 ( V_6 , V_125 ) ;
V_125 -> V_2 = V_6 -> V_9 -> V_10 -> V_11 -> V_34 ;
F_65 ( V_125 ) ;
return V_124 ;
}
static int
F_66 ( struct V_1 * V_2 ,
struct V_131 * V_92 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_12 = - V_73 ;
if ( V_6 -> V_59 != NULL )
V_12 = F_67 ( V_6 -> V_59 , V_92 ) ;
return V_12 ;
}
static int
F_68 ( struct V_1 * V_2 ,
const struct V_131 * V_92 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_59 != NULL )
return F_69 ( V_6 -> V_59 , V_92 ) ;
return - V_73 ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_132 * V_133 )
{
F_71 ( V_133 -> V_134 , L_4 , sizeof( V_133 -> V_134 ) ) ;
F_71 ( V_133 -> V_135 , L_5 , sizeof( V_133 -> V_135 ) ) ;
F_71 ( V_133 -> V_136 , L_6 , sizeof( V_133 -> V_136 ) ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( V_10 -> V_20 -> V_137 )
return V_10 -> V_20 -> V_137 ( V_10 , V_6 -> V_9 -> V_31 ) ;
return - V_73 ;
}
static void
F_73 ( struct V_1 * V_2 , struct V_138 * V_139 , void * V_140 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( V_10 -> V_20 -> V_141 )
V_10 -> V_20 -> V_141 ( V_10 , V_6 -> V_9 -> V_31 , V_139 , V_140 ) ;
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
return V_6 -> V_59 -> V_142 ;
}
return - V_73 ;
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( V_10 -> V_143 && V_10 -> V_143 -> V_144 )
return V_10 -> V_143 -> V_144 ;
if ( V_10 -> V_20 -> V_145 )
return V_10 -> V_20 -> V_145 ( V_10 ) ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_146 * V_147 , T_2 * V_148 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( V_10 -> V_20 -> V_149 )
return V_10 -> V_20 -> V_149 ( V_10 , V_147 , V_148 ) ;
return - V_73 ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_146 * V_147 , T_2 * V_148 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( V_10 -> V_20 -> V_150 )
return V_10 -> V_20 -> V_150 ( V_10 , V_147 , V_148 ) ;
return - V_73 ;
}
static void F_81 ( struct V_1 * V_2 ,
T_6 V_151 , T_7 * V_148 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( V_151 == V_152 ) {
int V_129 = V_153 ;
strncpy ( V_148 , L_7 , V_129 ) ;
strncpy ( V_148 + V_129 , L_8 , V_129 ) ;
strncpy ( V_148 + 2 * V_129 , L_9 , V_129 ) ;
strncpy ( V_148 + 3 * V_129 , L_10 , V_129 ) ;
if ( V_10 -> V_20 -> V_154 )
V_10 -> V_20 -> V_154 ( V_10 , V_6 -> V_9 -> V_31 , V_148 + 4 * V_129 ) ;
}
}
static void F_82 ( struct V_1 * V_2 ,
struct V_155 * V_126 ,
T_8 * V_148 )
{
struct V_156 * V_11 = V_2 -> V_157 ;
struct V_17 * V_10 = V_11 -> V_158 ;
T_9 V_159 = V_11 -> V_159 ;
int V_160 = 0 ;
if ( V_11 -> V_161 . V_162 ) {
V_160 = V_11 -> V_161 . V_162 ( V_2 ,
V_152 ) ;
V_11 -> V_161 . V_163 ( V_2 , V_126 , V_148 ) ;
}
if ( V_10 -> V_20 -> V_163 )
V_10 -> V_20 -> V_163 ( V_10 , V_159 , V_148 + V_160 ) ;
}
static int F_83 ( struct V_1 * V_2 , int V_164 )
{
struct V_156 * V_11 = V_2 -> V_157 ;
struct V_17 * V_10 = V_11 -> V_158 ;
int V_160 = 0 ;
if ( V_11 -> V_161 . V_162 )
V_160 += V_11 -> V_161 . V_162 ( V_2 , V_164 ) ;
if ( V_164 == V_152 && V_10 -> V_20 -> V_162 )
V_160 += V_10 -> V_20 -> V_162 ( V_10 ) ;
return V_160 ;
}
static void F_84 ( struct V_1 * V_2 ,
T_6 V_151 , T_7 * V_148 )
{
struct V_156 * V_11 = V_2 -> V_157 ;
struct V_17 * V_10 = V_11 -> V_158 ;
T_9 V_159 = V_11 -> V_159 ;
int V_129 = V_153 ;
int V_165 = 0 , V_160 ;
unsigned int V_99 ;
T_7 V_166 [ 4 ] ;
T_7 * V_167 ;
snprintf ( V_166 , sizeof( V_166 ) , L_11 , V_159 ) ;
V_166 [ sizeof( V_166 ) - 1 ] = '_' ;
if ( V_11 -> V_161 . V_162 ) {
V_165 = V_11 -> V_161 . V_162 ( V_2 ,
V_152 ) ;
V_11 -> V_161 . V_154 ( V_2 , V_151 , V_148 ) ;
}
if ( V_151 == V_152 && V_10 -> V_20 -> V_154 ) {
V_167 = V_148 + V_165 * V_129 ;
V_10 -> V_20 -> V_154 ( V_10 , V_159 , V_167 ) ;
V_160 = V_10 -> V_20 -> V_162 ( V_10 ) ;
for ( V_99 = 0 ; V_99 < V_160 ; V_99 ++ ) {
memmove ( V_167 + ( V_99 * V_129 + sizeof( V_166 ) ) ,
V_167 + V_99 * V_129 , V_129 - sizeof( V_166 ) ) ;
memcpy ( V_167 + V_99 * V_129 , V_166 , sizeof( V_166 ) ) ;
}
}
}
static void F_85 ( struct V_1 * V_2 ,
struct V_155 * V_126 ,
T_8 * V_148 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
V_148 [ 0 ] = V_2 -> V_126 . V_127 ;
V_148 [ 1 ] = V_2 -> V_126 . V_128 ;
V_148 [ 2 ] = V_2 -> V_126 . V_168 ;
V_148 [ 3 ] = V_2 -> V_126 . V_169 ;
if ( V_10 -> V_20 -> V_163 )
V_10 -> V_20 -> V_163 ( V_10 , V_6 -> V_9 -> V_31 , V_148 + 4 ) ;
}
static int F_86 ( struct V_1 * V_2 , int V_164 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( V_164 == V_152 ) {
int V_160 ;
V_160 = 4 ;
if ( V_10 -> V_20 -> V_162 )
V_160 += V_10 -> V_20 -> V_162 ( V_10 ) ;
return V_160 ;
}
return - V_73 ;
}
static void F_87 ( struct V_1 * V_2 , struct V_170 * V_171 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( V_10 -> V_20 -> V_172 )
V_10 -> V_20 -> V_172 ( V_10 , V_6 -> V_9 -> V_31 , V_171 ) ;
}
static int F_88 ( struct V_1 * V_2 , struct V_170 * V_171 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
int V_81 = - V_73 ;
if ( V_10 -> V_20 -> V_173 )
V_81 = V_10 -> V_20 -> V_173 ( V_10 , V_6 -> V_9 -> V_31 , V_171 ) ;
return V_81 ;
}
static int F_89 ( struct V_1 * V_2 , struct V_174 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
int V_81 ;
if ( ! V_10 -> V_20 -> V_175 )
return - V_73 ;
V_81 = V_10 -> V_20 -> V_175 ( V_10 , V_6 -> V_9 -> V_31 , V_6 -> V_59 , V_3 ) ;
if ( V_81 )
return V_81 ;
if ( V_6 -> V_59 )
V_81 = F_90 ( V_6 -> V_59 , V_3 ) ;
return V_81 ;
}
static int F_91 ( struct V_1 * V_2 , struct V_174 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
int V_81 ;
if ( ! V_10 -> V_20 -> V_176 )
return - V_73 ;
V_81 = V_10 -> V_20 -> V_176 ( V_10 , V_6 -> V_9 -> V_31 , V_3 ) ;
if ( V_81 )
return V_81 ;
if ( V_6 -> V_59 )
V_81 = F_92 ( V_6 -> V_59 , V_3 ) ;
return V_81 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_177 * V_178 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
struct V_1 * V_48 = V_10 -> V_11 -> V_34 ;
struct V_123 * V_123 ;
int V_12 = 0 ;
V_123 = F_94 ( sizeof( * V_123 ) , V_179 ) ;
if ( ! V_123 )
return - V_180 ;
V_12 = F_95 ( V_123 , V_48 ) ;
if ( V_12 ) {
F_96 ( V_123 ) ;
goto V_53;
}
V_6 -> V_123 = V_123 ;
V_53:
return V_12 ;
}
static void F_97 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_123 * V_123 = V_6 -> V_123 ;
if ( ! V_123 )
return;
V_6 -> V_123 = NULL ;
F_98 ( V_123 ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
}
static int F_100 ( struct V_1 * V_2 ,
char * V_25 , T_10 V_129 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( snprintf ( V_25 , V_129 , L_12 , V_6 -> V_9 -> V_31 ) >= V_129 )
return - V_181 ;
return 0 ;
}
static struct V_182 *
F_101 ( struct V_5 * V_6 ,
unsigned long V_183 )
{
struct V_182 * V_184 ;
F_102 (mall_tc_entry, &p->mall_tc_list, list)
if ( V_184 -> V_183 == V_183 )
return V_184 ;
return NULL ;
}
static int F_103 ( struct V_1 * V_2 ,
T_11 V_185 ,
struct V_186 * V_187 ,
bool V_188 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_182 * V_184 ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
struct V_189 * V_189 = F_104 ( V_2 ) ;
struct V_5 * V_190 ;
struct V_1 * V_191 ;
const struct V_192 * V_63 ;
int V_12 = - V_73 ;
F_105 ( V_193 ) ;
int V_35 ;
if ( ! V_10 -> V_20 -> V_194 )
return V_12 ;
if ( ! F_106 ( V_187 -> V_195 ) )
return V_12 ;
F_107 ( V_187 -> V_195 , & V_193 ) ;
V_63 = F_108 ( & V_193 , struct V_192 , V_196 ) ;
if ( F_109 ( V_63 ) && V_185 == F_110 ( V_197 ) ) {
struct V_198 * V_199 ;
V_35 = F_111 ( V_63 ) ;
V_191 = F_112 ( V_189 , V_35 ) ;
if ( ! V_191 )
return - V_181 ;
if ( ! F_113 ( V_191 ) )
return - V_73 ;
V_184 = F_94 ( sizeof( * V_184 ) , V_179 ) ;
if ( ! V_184 )
return - V_180 ;
V_184 -> V_183 = V_187 -> V_183 ;
V_184 -> type = V_200 ;
V_199 = & V_184 -> V_199 ;
V_190 = F_2 ( V_191 ) ;
V_199 -> V_201 = V_190 -> V_9 -> V_31 ;
V_199 -> V_188 = V_188 ;
V_12 = V_10 -> V_20 -> V_194 ( V_10 , V_6 -> V_9 -> V_31 , V_199 ,
V_188 ) ;
if ( V_12 ) {
F_96 ( V_184 ) ;
return V_12 ;
}
F_114 ( & V_184 -> V_196 , & V_6 -> V_202 ) ;
}
return 0 ;
}
static void F_115 ( struct V_1 * V_2 ,
struct V_186 * V_187 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_182 * V_184 ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( ! V_10 -> V_20 -> V_203 )
return;
V_184 = F_101 ( V_6 , V_187 -> V_183 ) ;
if ( ! V_184 )
return;
F_116 ( & V_184 -> V_196 ) ;
switch ( V_184 -> type ) {
case V_200 :
V_10 -> V_20 -> V_203 ( V_10 , V_6 -> V_9 -> V_31 ,
& V_184 -> V_199 ) ;
break;
default:
F_117 ( 1 ) ;
}
F_96 ( V_184 ) ;
}
static int F_118 ( struct V_1 * V_2 , T_5 V_204 ,
T_11 V_185 , struct V_205 * V_206 )
{
bool V_188 = F_119 ( V_204 ) == F_119 ( V_207 ) ;
int V_81 = - V_73 ;
switch ( V_206 -> type ) {
case V_208 :
switch ( V_206 -> V_209 -> V_210 ) {
case V_211 :
return F_103 ( V_2 , V_185 ,
V_206 -> V_209 ,
V_188 ) ;
case V_212 :
F_115 ( V_2 , V_206 -> V_209 ) ;
return 0 ;
}
default:
break;
}
return V_81 ;
}
void F_120 ( struct V_213 * V_20 )
{
V_20 -> V_162 = F_83 ;
V_20 -> V_163 = F_82 ;
V_20 -> V_154 = F_84 ;
}
static int F_121 ( struct V_1 * V_2 ,
struct V_214 * V_215 , T_5 * V_216 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( ! V_10 -> V_20 -> V_217 )
return - V_73 ;
return V_10 -> V_20 -> V_217 ( V_10 , V_6 -> V_9 -> V_31 , V_215 , V_216 ) ;
}
static int F_122 ( struct V_1 * V_2 ,
struct V_214 * V_215 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
if ( ! V_10 -> V_20 -> V_218 )
return - V_73 ;
return V_10 -> V_20 -> V_218 ( V_10 , V_6 -> V_9 -> V_31 , V_215 ) ;
}
static void F_123 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
unsigned int V_219 = 0 ;
if ( V_6 -> V_220 != V_6 -> V_59 -> V_142 ) {
V_219 = 1 ;
V_6 -> V_220 = V_6 -> V_59 -> V_142 ;
}
if ( V_6 -> V_221 != V_6 -> V_59 -> V_222 ) {
V_219 = 1 ;
V_6 -> V_221 = V_6 -> V_59 -> V_222 ;
}
if ( V_6 -> V_223 != V_6 -> V_59 -> V_224 ) {
V_219 = 1 ;
V_6 -> V_223 = V_6 -> V_59 -> V_224 ;
}
if ( V_10 -> V_20 -> V_225 && V_219 )
V_10 -> V_20 -> V_225 ( V_10 , V_6 -> V_9 -> V_31 , V_6 -> V_59 ) ;
if ( V_219 )
F_124 ( V_6 -> V_59 ) ;
}
static int F_125 ( struct V_1 * V_2 ,
struct V_226 * V_227 )
{
struct V_5 * V_6 ;
struct V_17 * V_10 ;
if ( V_2 ) {
V_6 = F_2 ( V_2 ) ;
V_10 = V_6 -> V_9 -> V_10 ;
if ( V_10 -> V_20 -> V_228 )
V_10 -> V_20 -> V_228 ( V_10 , V_6 -> V_9 -> V_31 , V_227 ) ;
}
return 0 ;
}
static int F_126 ( struct V_5 * V_6 ,
struct V_1 * V_229 ,
int V_15 )
{
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
V_6 -> V_59 = F_127 ( V_10 -> V_24 , V_15 ) ;
if ( ! V_6 -> V_59 ) {
F_56 ( V_229 , L_13 , V_15 ) ;
return - V_230 ;
}
if ( V_6 -> V_231 == V_232 )
V_6 -> V_231 = V_6 -> V_59 -> V_233 ;
return F_128 ( V_229 , V_6 -> V_59 , F_123 ,
V_6 -> V_231 ) ;
}
static int F_129 ( struct V_5 * V_6 ,
struct V_1 * V_229 )
{
struct V_17 * V_10 = V_6 -> V_9 -> V_10 ;
struct V_234 * V_235 , * V_236 ;
bool V_237 = false ;
T_5 V_238 = 0 ;
int V_239 , V_81 ;
V_236 = V_6 -> V_9 -> V_240 ;
V_239 = F_130 ( V_236 ) ;
if ( V_239 < 0 )
V_239 = V_232 ;
V_6 -> V_231 = V_239 ;
V_235 = F_131 ( V_236 , L_14 , 0 ) ;
if ( ! V_235 && F_132 ( V_236 ) ) {
V_81 = F_133 ( V_236 ) ;
if ( V_81 ) {
F_56 ( V_229 , L_15 , V_81 ) ;
return V_81 ;
}
V_237 = true ;
V_235 = F_134 ( V_236 ) ;
}
if ( V_10 -> V_20 -> V_241 )
V_238 = V_10 -> V_20 -> V_241 ( V_10 , V_6 -> V_9 -> V_31 ) ;
if ( V_235 ) {
int V_242 = F_135 ( & V_229 -> V_2 , V_235 ) ;
if ( ! V_237 && V_242 >= 0 &&
( V_10 -> V_19 & ( 1 << V_242 ) ) ) {
V_81 = F_126 ( V_6 , V_229 , V_242 ) ;
if ( V_81 ) {
F_56 ( V_229 , L_16 , V_242 , V_81 ) ;
F_136 ( V_235 ) ;
return V_81 ;
}
} else {
V_6 -> V_59 = F_137 ( V_229 , V_235 ,
F_123 ,
V_238 ,
V_6 -> V_231 ) ;
}
F_136 ( V_235 ) ;
}
if ( V_6 -> V_59 && V_237 )
F_138 ( V_6 -> V_59 , F_125 ) ;
if ( ! V_6 -> V_59 ) {
V_81 = F_126 ( V_6 , V_229 , V_6 -> V_9 -> V_31 ) ;
if ( V_81 ) {
F_56 ( V_229 , L_17 ,
V_6 -> V_9 -> V_31 , V_81 ) ;
if ( V_237 )
F_139 ( V_236 ) ;
return V_81 ;
}
}
F_140 ( V_6 -> V_59 ) ;
return 0 ;
}
static void F_141 ( struct V_1 * V_2 ,
struct V_243 * V_244 ,
void * V_245 )
{
F_142 ( & V_244 -> V_246 ,
& V_247 ) ;
}
int F_143 ( struct V_1 * V_229 )
{
struct V_5 * V_6 = F_2 ( V_229 ) ;
F_144 ( V_229 ) ;
if ( V_6 -> V_59 ) {
F_19 ( V_6 -> V_59 ) ;
V_6 -> V_223 = - 1 ;
V_6 -> V_220 = - 1 ;
V_6 -> V_221 = - 1 ;
F_145 ( V_6 -> V_59 ) ;
}
return 0 ;
}
int F_146 ( struct V_1 * V_229 )
{
struct V_5 * V_6 = F_2 ( V_229 ) ;
F_147 ( V_229 ) ;
if ( V_6 -> V_59 ) {
F_148 ( V_6 -> V_59 ) ;
F_16 ( V_6 -> V_59 ) ;
}
return 0 ;
}
int F_149 ( struct V_17 * V_10 , struct V_248 * V_32 ,
int V_39 , const char * V_25 )
{
struct V_156 * V_11 = V_10 -> V_11 ;
struct V_1 * V_48 ;
struct V_1 * V_229 ;
struct V_5 * V_6 ;
int V_81 ;
V_48 = V_10 -> V_11 -> V_34 ;
if ( V_10 -> V_34 )
V_48 = V_10 -> V_34 ;
V_229 = F_150 ( sizeof( struct V_5 ) , V_25 ,
V_249 , V_250 ) ;
if ( V_229 == NULL )
return - V_180 ;
V_229 -> V_251 = V_48 -> V_252 | V_253 ;
V_229 -> V_254 |= V_253 ;
V_229 -> V_213 = & V_255 ;
F_151 ( V_229 , V_48 ) ;
V_229 -> V_256 |= V_257 ;
V_229 -> V_258 = & V_259 ;
V_229 -> V_260 = & V_261 ;
V_229 -> V_262 = 0 ;
V_229 -> V_263 = V_264 ;
F_152 ( V_229 , & V_265 ) ;
F_153 ( V_229 , F_141 ,
NULL ) ;
F_154 ( V_229 , V_32 ) ;
V_229 -> V_2 . V_266 = V_10 -> V_101 [ V_39 ] . V_240 ;
V_229 -> V_252 = V_48 -> V_252 ;
V_6 = F_2 ( V_229 ) ;
V_6 -> V_9 = & V_10 -> V_101 [ V_39 ] ;
F_155 ( & V_6 -> V_202 ) ;
V_6 -> V_130 = V_11 -> V_267 -> V_130 ;
V_6 -> V_223 = - 1 ;
V_6 -> V_220 = - 1 ;
V_6 -> V_221 = - 1 ;
V_10 -> V_101 [ V_39 ] . V_268 = V_229 ;
V_81 = F_156 ( V_229 ) ;
if ( V_81 ) {
F_56 ( V_48 , L_18 ,
V_81 , V_229 -> V_25 ) ;
V_10 -> V_101 [ V_39 ] . V_268 = NULL ;
F_157 ( V_229 ) ;
return V_81 ;
}
F_158 ( V_229 ) ;
V_81 = F_129 ( V_6 , V_229 ) ;
if ( V_81 ) {
F_56 ( V_48 , L_19 , V_81 ) ;
F_159 ( V_229 ) ;
F_157 ( V_229 ) ;
return V_81 ;
}
return 0 ;
}
void F_160 ( struct V_1 * V_229 )
{
struct V_5 * V_6 = F_2 ( V_229 ) ;
struct V_234 * V_236 ;
V_236 = V_6 -> V_9 -> V_240 ;
F_158 ( V_229 ) ;
if ( V_6 -> V_59 ) {
F_161 ( V_6 -> V_59 ) ;
if ( F_132 ( V_236 ) )
F_139 ( V_236 ) ;
}
F_159 ( V_229 ) ;
F_157 ( V_229 ) ;
}
static bool F_113 ( struct V_1 * V_2 )
{
return V_2 -> V_258 == & V_259 ;
}
static int F_162 ( struct V_1 * V_2 ,
struct V_269 * V_114 )
{
int V_12 = V_270 ;
if ( F_163 ( V_114 -> V_271 ) ) {
if ( V_114 -> V_272 ) {
V_12 = F_54 ( V_2 , V_114 -> V_271 ) ;
V_12 = F_164 ( V_12 ) ;
} else {
F_55 ( V_2 , V_114 -> V_271 ) ;
V_12 = V_273 ;
}
}
return V_12 ;
}
static int F_165 ( struct V_274 * V_275 ,
unsigned long V_276 , void * V_277 )
{
struct V_1 * V_2 = F_166 ( V_277 ) ;
if ( V_2 -> V_258 != & V_259 )
return V_270 ;
if ( V_276 == V_278 )
return F_162 ( V_2 , V_277 ) ;
return V_270 ;
}
int F_167 ( void )
{
return F_168 ( & V_279 ) ;
}
void F_169 ( void )
{
int V_12 ;
V_12 = F_170 ( & V_279 ) ;
if ( V_12 )
F_171 ( L_20 , V_12 ) ;
}
