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
return V_27 -> V_22 -> V_19 -> V_28 -> V_29 ;
}
static inline bool F_6 ( struct V_26 * V_27 )
{
return ! ! V_27 -> V_30 ;
}
static void F_7 ( struct V_5 * V_6 , int V_31 , T_2 V_32 )
{
struct V_33 * V_34 = & V_6 -> V_35 [ V_31 ] ;
if ( V_6 -> V_9 -> V_36 )
V_6 -> V_9 -> V_36 ( V_6 , V_31 , V_32 ) ;
if ( V_6 -> V_9 -> V_37 ) {
if ( ( V_34 -> V_38 == V_39 ||
V_34 -> V_38 == V_40 ) &&
( V_32 == V_41 ||
V_32 == V_42 ||
V_32 == V_43 ) )
V_6 -> V_9 -> V_37 ( V_6 , V_31 ) ;
}
V_34 -> V_38 = V_32 ;
}
static int F_8 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_25 * V_44 = V_27 -> V_22 -> V_19 -> V_28 ;
struct V_5 * V_6 = V_27 -> V_22 ;
T_2 V_38 = F_6 ( V_27 ) ?
V_42 : V_40 ;
int V_45 ;
if ( ! ( V_44 -> V_46 & V_47 ) )
return - V_48 ;
if ( ! F_9 ( V_23 -> V_49 , V_44 -> V_49 ) ) {
V_45 = F_10 ( V_44 , V_23 -> V_49 ) ;
if ( V_45 < 0 )
goto V_50;
}
if ( V_23 -> V_46 & V_51 ) {
V_45 = F_11 ( V_44 , 1 ) ;
if ( V_45 < 0 )
goto V_52;
}
if ( V_23 -> V_46 & V_53 ) {
V_45 = F_12 ( V_44 , 1 ) ;
if ( V_45 < 0 )
goto V_54;
}
if ( V_6 -> V_9 -> V_55 ) {
V_45 = V_6 -> V_9 -> V_55 ( V_6 , V_27 -> V_31 , V_27 -> V_56 ) ;
if ( V_45 )
goto V_57;
}
F_7 ( V_6 , V_27 -> V_31 , V_38 ) ;
if ( V_27 -> V_56 )
F_13 ( V_27 -> V_56 ) ;
return 0 ;
V_57:
if ( V_23 -> V_46 & V_53 )
F_12 ( V_44 , - 1 ) ;
V_54:
if ( V_23 -> V_46 & V_51 )
F_11 ( V_44 , - 1 ) ;
V_52:
if ( ! F_9 ( V_23 -> V_49 , V_44 -> V_49 ) )
F_14 ( V_44 , V_23 -> V_49 ) ;
V_50:
return V_45 ;
}
static int F_15 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_25 * V_44 = V_27 -> V_22 -> V_19 -> V_28 ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_27 -> V_56 )
F_16 ( V_27 -> V_56 ) ;
F_17 ( V_44 , V_23 ) ;
F_18 ( V_44 , V_23 ) ;
if ( V_23 -> V_46 & V_51 )
F_11 ( V_44 , - 1 ) ;
if ( V_23 -> V_46 & V_53 )
F_12 ( V_44 , - 1 ) ;
if ( ! F_9 ( V_23 -> V_49 , V_44 -> V_49 ) )
F_14 ( V_44 , V_23 -> V_49 ) ;
if ( V_6 -> V_9 -> V_58 )
V_6 -> V_9 -> V_58 ( V_6 , V_27 -> V_31 , V_27 -> V_56 ) ;
F_7 ( V_6 , V_27 -> V_31 , V_41 ) ;
return 0 ;
}
static void F_19 ( struct V_25 * V_23 , int V_59 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_25 * V_44 = V_27 -> V_22 -> V_19 -> V_28 ;
if ( V_59 & V_51 )
F_11 ( V_44 , V_23 -> V_46 & V_51 ? 1 : - 1 ) ;
if ( V_59 & V_53 )
F_12 ( V_44 , V_23 -> V_46 & V_53 ? 1 : - 1 ) ;
}
static void F_20 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_25 * V_44 = V_27 -> V_22 -> V_19 -> V_28 ;
F_21 ( V_44 , V_23 ) ;
F_22 ( V_44 , V_23 ) ;
}
static int F_23 ( struct V_25 * V_23 , void * V_60 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_25 * V_44 = V_27 -> V_22 -> V_19 -> V_28 ;
struct V_61 * V_3 = V_60 ;
int V_45 ;
if ( ! F_24 ( V_3 -> V_62 ) )
return - V_63 ;
if ( ! ( V_23 -> V_46 & V_47 ) )
goto V_50;
if ( ! F_9 ( V_3 -> V_62 , V_44 -> V_49 ) ) {
V_45 = F_10 ( V_44 , V_3 -> V_62 ) ;
if ( V_45 < 0 )
return V_45 ;
}
if ( ! F_9 ( V_23 -> V_49 , V_44 -> V_49 ) )
F_14 ( V_44 , V_23 -> V_49 ) ;
V_50:
F_25 ( V_23 -> V_49 , V_3 -> V_62 ) ;
return 0 ;
}
static int F_26 ( struct V_25 * V_23 ,
const struct V_64 * V_65 ,
struct V_66 * V_67 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( F_27 ( V_67 ) ) {
if ( ! V_6 -> V_9 -> V_68 || ! V_6 -> V_9 -> V_69 )
return - V_70 ;
return V_6 -> V_9 -> V_68 ( V_6 , V_27 -> V_31 , V_65 , V_67 ) ;
}
V_6 -> V_9 -> V_69 ( V_6 , V_27 -> V_31 , V_65 , V_67 ) ;
return 0 ;
}
static int F_28 ( struct V_25 * V_23 ,
const struct V_64 * V_65 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( ! V_6 -> V_9 -> V_71 )
return - V_70 ;
return V_6 -> V_9 -> V_71 ( V_6 , V_27 -> V_31 , V_65 ) ;
}
static int F_29 ( struct V_25 * V_23 ,
struct V_64 * V_65 ,
T_3 * V_72 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_73 )
return V_6 -> V_9 -> V_73 ( V_6 , V_27 -> V_31 , V_65 , V_72 ) ;
return - V_70 ;
}
static int F_30 ( struct V_25 * V_23 ,
const struct V_74 * V_75 ,
struct V_66 * V_67 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( F_27 ( V_67 ) ) {
if ( ! V_6 -> V_9 -> V_76 || ! V_6 -> V_9 -> V_77 )
return - V_70 ;
return V_6 -> V_9 -> V_76 ( V_6 , V_27 -> V_31 , V_75 , V_67 ) ;
}
V_6 -> V_9 -> V_77 ( V_6 , V_27 -> V_31 , V_75 , V_67 ) ;
return 0 ;
}
static int F_31 ( struct V_25 * V_23 ,
const struct V_74 * V_75 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
int V_78 = - V_70 ;
if ( V_6 -> V_9 -> V_79 )
V_78 = V_6 -> V_9 -> V_79 ( V_6 , V_27 -> V_31 , V_75 ) ;
return V_78 ;
}
static int F_32 ( struct V_25 * V_23 ,
struct V_74 * V_75 ,
T_3 * V_72 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_80 )
return V_6 -> V_9 -> V_80 ( V_6 , V_27 -> V_31 , V_75 , V_72 ) ;
return - V_70 ;
}
static int F_33 ( struct V_25 * V_23 ,
const struct V_81 * V_82 ,
struct V_66 * V_67 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( F_27 ( V_67 ) ) {
if ( ! V_6 -> V_9 -> V_83 || ! V_6 -> V_9 -> V_84 )
return - V_70 ;
return V_6 -> V_9 -> V_83 ( V_6 , V_27 -> V_31 , V_82 , V_67 ) ;
}
V_6 -> V_9 -> V_84 ( V_6 , V_27 -> V_31 , V_82 , V_67 ) ;
return 0 ;
}
static int F_34 ( struct V_25 * V_23 ,
const struct V_81 * V_82 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_85 )
return V_6 -> V_9 -> V_85 ( V_6 , V_27 -> V_31 , V_82 ) ;
return - V_70 ;
}
static int F_35 ( struct V_25 * V_23 ,
struct V_81 * V_82 ,
T_3 * V_72 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_86 )
return V_6 -> V_9 -> V_86 ( V_6 , V_27 -> V_31 , V_82 , V_72 ) ;
return - V_70 ;
}
static int F_36 ( struct V_25 * V_23 , struct V_87 * V_88 , int V_89 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
if ( V_27 -> V_56 != NULL )
return F_37 ( V_27 -> V_56 , V_88 , V_89 ) ;
return - V_70 ;
}
static int F_38 ( struct V_25 * V_23 ,
const struct V_90 * V_91 ,
struct V_66 * V_67 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( F_27 ( V_67 ) )
return V_6 -> V_9 -> V_36 ? 0 : - V_70 ;
F_7 ( V_6 , V_27 -> V_31 , V_91 -> V_92 . V_38 ) ;
return 0 ;
}
static int F_39 ( struct V_25 * V_23 ,
const struct V_90 * V_91 ,
struct V_66 * V_67 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( F_27 ( V_67 ) )
return 0 ;
if ( V_6 -> V_9 -> V_93 )
return V_6 -> V_9 -> V_93 ( V_6 , V_27 -> V_31 ,
V_91 -> V_92 . V_94 ) ;
return 0 ;
}
static int F_40 ( struct V_5 * V_6 ,
unsigned int V_95 )
{
int V_96 ;
for ( V_96 = 0 ; V_96 < V_97 ; ++ V_96 ) {
struct V_33 * V_34 = & V_6 -> V_35 [ V_96 ] ;
if ( V_34 && V_34 -> V_95 && V_34 -> V_95 < V_95 )
V_95 = V_34 -> V_95 ;
}
return V_95 ;
}
static int F_41 ( struct V_25 * V_23 ,
const struct V_90 * V_91 ,
struct V_66 * V_67 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
unsigned long V_98 = F_42 ( V_91 -> V_92 . V_95 ) ;
unsigned int V_95 = F_43 ( V_98 ) ;
if ( F_27 ( V_67 ) )
return 0 ;
V_6 -> V_35 [ V_27 -> V_31 ] . V_95 = V_95 ;
V_95 = F_40 ( V_6 , V_95 ) ;
if ( V_6 -> V_9 -> V_99 )
return V_6 -> V_9 -> V_99 ( V_6 , V_95 ) ;
return 0 ;
}
static int F_44 ( struct V_25 * V_23 ,
const struct V_90 * V_91 ,
struct V_66 * V_67 )
{
int V_78 ;
switch ( V_91 -> V_17 ) {
case V_100 :
V_78 = F_38 ( V_23 , V_91 , V_67 ) ;
break;
case V_101 :
V_78 = F_39 ( V_23 , V_91 , V_67 ) ;
break;
case V_102 :
V_78 = F_41 ( V_23 , V_91 , V_67 ) ;
break;
default:
V_78 = - V_70 ;
break;
}
return V_78 ;
}
static int F_45 ( struct V_25 * V_23 ,
const struct V_103 * V_104 ,
struct V_66 * V_67 )
{
int V_45 ;
switch ( V_104 -> V_17 ) {
case V_105 :
V_45 = F_30 ( V_23 ,
F_46 ( V_104 ) ,
V_67 ) ;
break;
case V_106 :
V_45 = F_33 ( V_23 , F_47 ( V_104 ) ,
V_67 ) ;
break;
case V_107 :
V_45 = F_26 ( V_23 ,
F_48 ( V_104 ) ,
V_67 ) ;
break;
default:
V_45 = - V_70 ;
break;
}
return V_45 ;
}
static int F_49 ( struct V_25 * V_23 ,
const struct V_103 * V_104 )
{
int V_45 ;
switch ( V_104 -> V_17 ) {
case V_105 :
V_45 = F_31 ( V_23 ,
F_46 ( V_104 ) ) ;
break;
case V_106 :
V_45 = F_34 ( V_23 , F_47 ( V_104 ) ) ;
break;
case V_107 :
V_45 = F_28 ( V_23 ,
F_48 ( V_104 ) ) ;
break;
default:
V_45 = - V_70 ;
break;
}
return V_45 ;
}
static int F_50 ( struct V_25 * V_23 ,
struct V_103 * V_104 ,
T_3 * V_72 )
{
int V_45 ;
switch ( V_104 -> V_17 ) {
case V_105 :
V_45 = F_32 ( V_23 ,
F_46 ( V_104 ) ,
V_72 ) ;
break;
case V_106 :
V_45 = F_35 ( V_23 , F_47 ( V_104 ) ,
V_72 ) ;
break;
case V_107 :
V_45 = F_29 ( V_23 ,
F_48 ( V_104 ) ,
V_72 ) ;
break;
default:
V_45 = - V_70 ;
break;
}
return V_45 ;
}
static int F_51 ( struct V_25 * V_23 ,
struct V_25 * V_108 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
int V_78 = - V_70 ;
V_27 -> V_30 = V_108 ;
if ( V_6 -> V_9 -> V_109 )
V_78 = V_6 -> V_9 -> V_109 ( V_6 , V_27 -> V_31 , V_108 ) ;
return V_78 == - V_70 ? 0 : V_78 ;
}
static void F_52 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_110 )
V_6 -> V_9 -> V_110 ( V_6 , V_27 -> V_31 ) ;
V_27 -> V_30 = NULL ;
F_7 ( V_6 , V_27 -> V_31 , V_40 ) ;
}
static int F_53 ( struct V_25 * V_23 ,
struct V_90 * V_91 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
switch ( V_91 -> V_17 ) {
case V_111 :
V_91 -> V_92 . V_112 . V_113 = sizeof( V_6 -> V_21 ) ;
memcpy ( & V_91 -> V_92 . V_112 . V_17 , & V_6 -> V_21 , V_91 -> V_92 . V_112 . V_113 ) ;
break;
default:
return - V_70 ;
}
return 0 ;
}
static inline T_4 F_54 ( struct V_26 * V_27 ,
struct V_114 * V_115 )
{
#ifdef F_55
if ( V_27 -> V_116 )
F_56 ( V_27 -> V_116 , V_115 ) ;
#else
F_57 () ;
#endif
return V_117 ;
}
static T_4 F_58 ( struct V_114 * V_115 , struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_114 * V_118 ;
V_23 -> V_119 . V_120 ++ ;
V_23 -> V_119 . V_121 += V_115 -> V_122 ;
V_118 = V_27 -> V_123 ( V_115 , V_23 ) ;
if ( ! V_118 )
return V_117 ;
if ( F_59 ( F_60 ( V_23 ) ) )
return F_54 ( V_27 , V_118 ) ;
V_118 -> V_23 = V_27 -> V_22 -> V_19 -> V_28 ;
F_61 ( V_118 ) ;
return V_117 ;
}
static int
F_62 ( struct V_25 * V_23 ,
struct V_124 * V_89 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
int V_45 ;
V_45 = - V_70 ;
if ( V_27 -> V_56 != NULL ) {
V_45 = F_63 ( V_27 -> V_56 ) ;
if ( V_45 == 0 )
V_45 = F_64 ( V_27 -> V_56 , V_89 ) ;
}
return V_45 ;
}
static int
F_65 ( struct V_25 * V_23 ,
const struct V_124 * V_89 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
if ( V_27 -> V_56 != NULL )
return F_66 ( V_27 -> V_56 , V_89 ) ;
return - V_70 ;
}
static void F_67 ( struct V_25 * V_23 ,
struct V_125 * V_126 )
{
F_68 ( V_126 -> V_127 , L_3 , sizeof( V_126 -> V_127 ) ) ;
F_68 ( V_126 -> V_128 , V_129 , sizeof( V_126 -> V_128 ) ) ;
F_68 ( V_126 -> V_130 , L_4 , sizeof( V_126 -> V_130 ) ) ;
F_68 ( V_126 -> V_131 , L_5 , sizeof( V_126 -> V_131 ) ) ;
}
static int F_69 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_132 )
return V_6 -> V_9 -> V_132 ( V_6 , V_27 -> V_31 ) ;
return - V_70 ;
}
static void
F_70 ( struct V_25 * V_23 , struct V_133 * V_134 , void * V_135 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_136 )
V_6 -> V_9 -> V_136 ( V_6 , V_27 -> V_31 , V_134 , V_135 ) ;
}
static int F_71 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
if ( V_27 -> V_56 != NULL )
return F_72 ( V_27 -> V_56 ) ;
return - V_70 ;
}
static T_5 F_73 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
if ( V_27 -> V_56 != NULL ) {
F_74 ( V_27 -> V_56 ) ;
return V_27 -> V_56 -> V_137 ;
}
return - V_70 ;
}
static int F_75 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_138 && V_6 -> V_138 -> V_139 )
return V_6 -> V_138 -> V_139 ;
if ( V_6 -> V_9 -> V_140 )
return V_6 -> V_9 -> V_140 ( V_6 ) ;
return 0 ;
}
static int F_76 ( struct V_25 * V_23 ,
struct V_141 * V_142 , T_2 * V_143 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_144 )
return V_6 -> V_9 -> V_144 ( V_6 , V_142 , V_143 ) ;
return - V_70 ;
}
static int F_77 ( struct V_25 * V_23 ,
struct V_141 * V_142 , T_2 * V_143 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_145 )
return V_6 -> V_9 -> V_145 ( V_6 , V_142 , V_143 ) ;
return - V_70 ;
}
static void F_78 ( struct V_25 * V_23 ,
T_6 V_146 , T_7 * V_143 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_146 == V_147 ) {
int V_122 = V_148 ;
strncpy ( V_143 , L_6 , V_122 ) ;
strncpy ( V_143 + V_122 , L_7 , V_122 ) ;
strncpy ( V_143 + 2 * V_122 , L_8 , V_122 ) ;
strncpy ( V_143 + 3 * V_122 , L_9 , V_122 ) ;
if ( V_6 -> V_9 -> V_149 )
V_6 -> V_9 -> V_149 ( V_6 , V_27 -> V_31 , V_143 + 4 * V_122 ) ;
}
}
static void F_79 ( struct V_25 * V_23 ,
struct V_150 * V_119 ,
T_8 * V_143 )
{
struct V_151 * V_19 = V_23 -> V_152 ;
struct V_5 * V_6 = V_19 -> V_6 [ 0 ] ;
T_9 V_153 = V_19 -> V_153 ;
int V_154 = 0 ;
if ( V_19 -> V_155 . V_156 ) {
V_154 = V_19 -> V_155 . V_156 ( V_23 ,
V_147 ) ;
V_19 -> V_155 . V_157 ( V_23 , V_119 , V_143 ) ;
}
if ( V_6 -> V_9 -> V_157 )
V_6 -> V_9 -> V_157 ( V_6 , V_153 , V_143 + V_154 ) ;
}
static int F_80 ( struct V_25 * V_23 , int V_158 )
{
struct V_151 * V_19 = V_23 -> V_152 ;
struct V_5 * V_6 = V_19 -> V_6 [ 0 ] ;
int V_154 = 0 ;
if ( V_19 -> V_155 . V_156 )
V_154 += V_19 -> V_155 . V_156 ( V_23 , V_158 ) ;
if ( V_158 == V_147 && V_6 -> V_9 -> V_156 )
V_154 += V_6 -> V_9 -> V_156 ( V_6 ) ;
return V_154 ;
}
static void F_81 ( struct V_25 * V_23 ,
T_6 V_146 , T_7 * V_143 )
{
struct V_151 * V_19 = V_23 -> V_152 ;
struct V_5 * V_6 = V_19 -> V_6 [ 0 ] ;
T_9 V_153 = V_19 -> V_153 ;
int V_122 = V_148 ;
int V_159 = 0 , V_154 ;
unsigned int V_96 ;
T_7 V_160 [ 4 ] ;
T_7 * V_161 ;
snprintf ( V_160 , sizeof( V_160 ) , L_10 , V_153 ) ;
V_160 [ sizeof( V_160 ) - 1 ] = '_' ;
if ( V_19 -> V_155 . V_156 ) {
V_159 = V_19 -> V_155 . V_156 ( V_23 ,
V_147 ) ;
V_19 -> V_155 . V_149 ( V_23 , V_146 , V_143 ) ;
}
if ( V_146 == V_147 && V_6 -> V_9 -> V_149 ) {
V_161 = V_143 + V_159 * V_122 ;
V_6 -> V_9 -> V_149 ( V_6 , V_153 , V_161 ) ;
V_154 = V_6 -> V_9 -> V_156 ( V_6 ) ;
for ( V_96 = 0 ; V_96 < V_154 ; V_96 ++ ) {
memmove ( V_161 + ( V_96 * V_122 + sizeof( V_160 ) ) ,
V_161 + V_96 * V_122 , V_122 - sizeof( V_160 ) ) ;
memcpy ( V_161 + V_96 * V_122 , V_160 , sizeof( V_160 ) ) ;
}
}
}
static void F_82 ( struct V_25 * V_23 ,
struct V_150 * V_119 ,
T_8 * V_143 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
V_143 [ 0 ] = V_23 -> V_119 . V_120 ;
V_143 [ 1 ] = V_23 -> V_119 . V_121 ;
V_143 [ 2 ] = V_23 -> V_119 . V_162 ;
V_143 [ 3 ] = V_23 -> V_119 . V_163 ;
if ( V_6 -> V_9 -> V_157 )
V_6 -> V_9 -> V_157 ( V_6 , V_27 -> V_31 , V_143 + 4 ) ;
}
static int F_83 ( struct V_25 * V_23 , int V_158 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_158 == V_147 ) {
int V_154 ;
V_154 = 4 ;
if ( V_6 -> V_9 -> V_156 )
V_154 += V_6 -> V_9 -> V_156 ( V_6 ) ;
return V_154 ;
}
return - V_70 ;
}
static void F_84 ( struct V_25 * V_23 , struct V_164 * V_165 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_166 )
V_6 -> V_9 -> V_166 ( V_6 , V_27 -> V_31 , V_165 ) ;
}
static int F_85 ( struct V_25 * V_23 , struct V_164 * V_165 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
int V_78 = - V_70 ;
if ( V_6 -> V_9 -> V_167 )
V_78 = V_6 -> V_9 -> V_167 ( V_6 , V_27 -> V_31 , V_165 ) ;
return V_78 ;
}
static int F_86 ( struct V_25 * V_23 , struct V_168 * V_169 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
int V_78 ;
if ( ! V_6 -> V_9 -> V_170 )
return - V_70 ;
V_78 = V_6 -> V_9 -> V_170 ( V_6 , V_27 -> V_31 , V_27 -> V_56 , V_169 ) ;
if ( V_78 )
return V_78 ;
if ( V_27 -> V_56 )
V_78 = F_87 ( V_27 -> V_56 , V_169 ) ;
return V_78 ;
}
static int F_88 ( struct V_25 * V_23 , struct V_168 * V_169 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
int V_78 ;
if ( ! V_6 -> V_9 -> V_171 )
return - V_70 ;
V_78 = V_6 -> V_9 -> V_171 ( V_6 , V_27 -> V_31 , V_169 ) ;
if ( V_78 )
return V_78 ;
if ( V_27 -> V_56 )
V_78 = F_89 ( V_27 -> V_56 , V_169 ) ;
return V_78 ;
}
static int F_90 ( struct V_25 * V_23 ,
struct V_172 * V_173 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
struct V_25 * V_44 = V_6 -> V_19 -> V_28 ;
struct V_116 * V_116 ;
int V_45 = 0 ;
V_116 = F_91 ( sizeof( * V_116 ) , V_174 ) ;
if ( ! V_116 )
return - V_175 ;
V_45 = F_92 ( V_116 , V_44 ) ;
if ( V_45 ) {
F_93 ( V_116 ) ;
goto V_50;
}
V_27 -> V_116 = V_116 ;
V_50:
return V_45 ;
}
static void F_94 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_116 * V_116 = V_27 -> V_116 ;
if ( ! V_116 )
return;
V_27 -> V_116 = NULL ;
F_95 ( V_116 ) ;
}
static void F_96 ( struct V_25 * V_23 )
{
}
void F_97 ( struct V_176 * V_9 )
{
V_9 -> V_156 = F_80 ;
V_9 -> V_157 = F_79 ;
V_9 -> V_149 = F_81 ;
}
static void F_98 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
unsigned int V_177 = 0 ;
if ( V_27 -> V_178 != V_27 -> V_56 -> V_137 ) {
V_177 = 1 ;
V_27 -> V_178 = V_27 -> V_56 -> V_137 ;
}
if ( V_27 -> V_179 != V_27 -> V_56 -> V_180 ) {
V_177 = 1 ;
V_27 -> V_179 = V_27 -> V_56 -> V_180 ;
}
if ( V_27 -> V_181 != V_27 -> V_56 -> V_182 ) {
V_177 = 1 ;
V_27 -> V_181 = V_27 -> V_56 -> V_182 ;
}
if ( V_6 -> V_9 -> V_183 && V_177 )
V_6 -> V_9 -> V_183 ( V_6 , V_27 -> V_31 , V_27 -> V_56 ) ;
if ( V_177 )
F_99 ( V_27 -> V_56 ) ;
}
static int F_100 ( struct V_25 * V_23 ,
struct V_184 * V_185 )
{
struct V_26 * V_27 ;
struct V_5 * V_6 ;
if ( V_23 ) {
V_27 = F_5 ( V_23 ) ;
V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_186 )
V_6 -> V_9 -> V_186 ( V_6 , V_27 -> V_31 , V_185 ) ;
}
return 0 ;
}
static int F_101 ( struct V_26 * V_27 ,
struct V_25 * V_187 ,
int V_3 )
{
struct V_5 * V_6 = V_27 -> V_22 ;
V_27 -> V_56 = F_102 ( V_6 -> V_13 , V_3 ) ;
if ( ! V_27 -> V_56 ) {
F_103 ( V_187 , L_11 , V_3 ) ;
return - V_188 ;
}
if ( V_27 -> V_189 == V_190 )
V_27 -> V_189 = V_27 -> V_56 -> V_191 ;
return F_104 ( V_187 , V_27 -> V_56 , F_98 ,
V_27 -> V_189 ) ;
}
static int F_105 ( struct V_26 * V_27 ,
struct V_25 * V_187 )
{
struct V_5 * V_6 = V_27 -> V_22 ;
struct V_192 * V_193 , * V_194 ;
bool V_195 = false ;
T_5 V_196 = 0 ;
int V_197 , V_78 ;
V_194 = V_6 -> V_35 [ V_27 -> V_31 ] . V_198 ;
V_197 = F_106 ( V_194 ) ;
if ( V_197 < 0 )
V_197 = V_190 ;
V_27 -> V_189 = V_197 ;
V_193 = F_107 ( V_194 , L_12 , 0 ) ;
if ( ! V_193 && F_108 ( V_194 ) ) {
V_78 = F_109 ( V_194 ) ;
if ( V_78 ) {
F_103 ( V_187 , L_13 , V_78 ) ;
return V_78 ;
}
V_195 = true ;
V_193 = F_110 ( V_194 ) ;
}
if ( V_6 -> V_9 -> V_199 )
V_196 = V_6 -> V_9 -> V_199 ( V_6 , V_27 -> V_31 ) ;
if ( V_193 ) {
int V_200 = F_111 ( & V_187 -> V_23 , V_193 ) ;
if ( ! V_195 && V_200 >= 0 &&
( V_6 -> V_8 & ( 1 << V_200 ) ) ) {
V_78 = F_101 ( V_27 , V_187 , V_200 ) ;
if ( V_78 ) {
F_103 ( V_187 , L_14 , V_200 , V_78 ) ;
F_112 ( V_193 ) ;
return V_78 ;
}
} else {
V_27 -> V_56 = F_113 ( V_187 , V_193 ,
F_98 ,
V_196 ,
V_27 -> V_189 ) ;
}
F_112 ( V_193 ) ;
}
if ( V_27 -> V_56 && V_195 )
F_114 ( V_27 -> V_56 , F_100 ) ;
if ( ! V_27 -> V_56 ) {
V_78 = F_101 ( V_27 , V_187 , V_27 -> V_31 ) ;
if ( V_78 ) {
F_103 ( V_187 , L_15 , V_27 -> V_31 , V_78 ) ;
if ( V_195 )
F_115 ( V_194 ) ;
return V_78 ;
}
}
F_116 ( V_27 -> V_56 ) ;
return 0 ;
}
static void F_117 ( struct V_25 * V_23 ,
struct V_201 * V_202 ,
void * V_203 )
{
F_118 ( & V_202 -> V_204 ,
& V_205 ) ;
}
int F_119 ( struct V_25 * V_187 )
{
struct V_26 * V_27 = F_5 ( V_187 ) ;
F_120 ( V_187 ) ;
if ( V_27 -> V_56 ) {
F_16 ( V_27 -> V_56 ) ;
V_27 -> V_181 = - 1 ;
V_27 -> V_178 = - 1 ;
V_27 -> V_179 = - 1 ;
F_121 ( V_27 -> V_56 ) ;
}
return 0 ;
}
int F_122 ( struct V_25 * V_187 )
{
struct V_26 * V_27 = F_5 ( V_187 ) ;
F_123 ( V_187 ) ;
if ( V_27 -> V_56 ) {
F_124 ( V_27 -> V_56 ) ;
F_13 ( V_27 -> V_56 ) ;
}
return 0 ;
}
int F_125 ( struct V_5 * V_6 , struct V_206 * V_22 ,
int V_31 , const char * V_14 )
{
struct V_151 * V_19 = V_6 -> V_19 ;
struct V_25 * V_44 ;
struct V_25 * V_187 ;
struct V_26 * V_27 ;
int V_78 ;
V_44 = V_6 -> V_19 -> V_28 ;
if ( V_6 -> V_28 )
V_44 = V_6 -> V_28 ;
V_187 = F_126 ( sizeof( struct V_26 ) , V_14 ,
V_207 , V_208 ) ;
if ( V_187 == NULL )
return - V_175 ;
V_187 -> V_209 = V_44 -> V_210 ;
V_187 -> V_176 = & V_211 ;
F_127 ( V_187 , V_44 ) ;
V_187 -> V_212 |= V_213 ;
V_187 -> V_214 = & V_215 ;
V_187 -> V_216 = & V_217 ;
V_187 -> V_218 = 0 ;
V_187 -> V_219 = V_220 ;
F_128 ( V_187 , & V_221 ) ;
F_129 ( V_187 , F_117 ,
NULL ) ;
F_130 ( V_187 , V_22 ) ;
V_187 -> V_23 . V_222 = V_6 -> V_35 [ V_31 ] . V_198 ;
V_187 -> V_210 = V_44 -> V_210 ;
V_27 = F_5 ( V_187 ) ;
V_27 -> V_22 = V_6 ;
V_27 -> V_31 = V_31 ;
V_27 -> V_123 = V_19 -> V_223 -> V_123 ;
V_27 -> V_181 = - 1 ;
V_27 -> V_178 = - 1 ;
V_27 -> V_179 = - 1 ;
V_6 -> V_35 [ V_31 ] . V_224 = V_187 ;
V_78 = F_131 ( V_187 ) ;
if ( V_78 ) {
F_103 ( V_44 , L_16 ,
V_78 , V_187 -> V_14 ) ;
V_6 -> V_35 [ V_31 ] . V_224 = NULL ;
F_132 ( V_187 ) ;
return V_78 ;
}
F_133 ( V_187 ) ;
V_78 = F_105 ( V_27 , V_187 ) ;
if ( V_78 ) {
F_103 ( V_44 , L_17 , V_78 ) ;
F_134 ( V_187 ) ;
F_132 ( V_187 ) ;
return V_78 ;
}
return 0 ;
}
void F_135 ( struct V_25 * V_187 )
{
struct V_26 * V_27 = F_5 ( V_187 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
struct V_192 * V_194 ;
V_194 = V_6 -> V_35 [ V_27 -> V_31 ] . V_198 ;
F_133 ( V_187 ) ;
if ( V_27 -> V_56 ) {
F_136 ( V_27 -> V_56 ) ;
if ( F_108 ( V_194 ) )
F_115 ( V_194 ) ;
}
F_134 ( V_187 ) ;
F_132 ( V_187 ) ;
}
static bool F_137 ( struct V_25 * V_23 )
{
return V_23 -> V_214 == & V_215 ;
}
static int F_138 ( struct V_25 * V_23 ,
unsigned long V_225 , void * V_226 )
{
struct V_227 * V_228 = V_226 ;
struct V_25 * V_229 = V_228 -> V_230 ;
int V_45 = 0 ;
switch ( V_225 ) {
case V_231 :
if ( F_139 ( V_229 ) ) {
if ( V_228 -> V_232 )
V_45 = F_51 ( V_23 , V_229 ) ;
else
F_52 ( V_23 ) ;
}
break;
}
return F_140 ( V_45 ) ;
}
static int F_141 ( struct V_25 * V_23 , unsigned long V_225 ,
void * V_226 )
{
switch ( V_225 ) {
case V_231 :
return F_138 ( V_23 , V_225 , V_226 ) ;
}
return V_233 ;
}
int F_142 ( struct V_234 * V_235 ,
unsigned long V_225 , void * V_226 )
{
struct V_25 * V_23 = F_143 ( V_226 ) ;
if ( F_137 ( V_23 ) )
return F_141 ( V_23 , V_225 , V_226 ) ;
return V_233 ;
}
