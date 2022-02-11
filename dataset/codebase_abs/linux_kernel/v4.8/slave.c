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
static int F_7 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_25 * V_31 = V_27 -> V_22 -> V_19 -> V_28 ;
struct V_5 * V_6 = V_27 -> V_22 ;
T_2 V_32 = F_6 ( V_27 ) ?
V_33 : V_34 ;
int V_35 ;
if ( ! ( V_31 -> V_36 & V_37 ) )
return - V_38 ;
if ( ! F_8 ( V_23 -> V_39 , V_31 -> V_39 ) ) {
V_35 = F_9 ( V_31 , V_23 -> V_39 ) ;
if ( V_35 < 0 )
goto V_40;
}
if ( V_23 -> V_36 & V_41 ) {
V_35 = F_10 ( V_31 , 1 ) ;
if ( V_35 < 0 )
goto V_42;
}
if ( V_23 -> V_36 & V_43 ) {
V_35 = F_11 ( V_31 , 1 ) ;
if ( V_35 < 0 )
goto V_44;
}
if ( V_6 -> V_9 -> V_45 ) {
V_35 = V_6 -> V_9 -> V_45 ( V_6 , V_27 -> V_46 , V_27 -> V_47 ) ;
if ( V_35 )
goto V_48;
}
if ( V_6 -> V_9 -> V_49 )
V_6 -> V_9 -> V_49 ( V_6 , V_27 -> V_46 , V_32 ) ;
if ( V_27 -> V_47 )
F_12 ( V_27 -> V_47 ) ;
return 0 ;
V_48:
if ( V_23 -> V_36 & V_43 )
F_11 ( V_31 , - 1 ) ;
V_44:
if ( V_23 -> V_36 & V_41 )
F_10 ( V_31 , - 1 ) ;
V_42:
if ( ! F_8 ( V_23 -> V_39 , V_31 -> V_39 ) )
F_13 ( V_31 , V_23 -> V_39 ) ;
V_40:
return V_35 ;
}
static int F_14 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_25 * V_31 = V_27 -> V_22 -> V_19 -> V_28 ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_27 -> V_47 )
F_15 ( V_27 -> V_47 ) ;
F_16 ( V_31 , V_23 ) ;
F_17 ( V_31 , V_23 ) ;
if ( V_23 -> V_36 & V_41 )
F_10 ( V_31 , - 1 ) ;
if ( V_23 -> V_36 & V_43 )
F_11 ( V_31 , - 1 ) ;
if ( ! F_8 ( V_23 -> V_39 , V_31 -> V_39 ) )
F_13 ( V_31 , V_23 -> V_39 ) ;
if ( V_6 -> V_9 -> V_50 )
V_6 -> V_9 -> V_50 ( V_6 , V_27 -> V_46 , V_27 -> V_47 ) ;
if ( V_6 -> V_9 -> V_49 )
V_6 -> V_9 -> V_49 ( V_6 , V_27 -> V_46 , V_51 ) ;
return 0 ;
}
static void F_18 ( struct V_25 * V_23 , int V_52 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_25 * V_31 = V_27 -> V_22 -> V_19 -> V_28 ;
if ( V_52 & V_41 )
F_10 ( V_31 , V_23 -> V_36 & V_41 ? 1 : - 1 ) ;
if ( V_52 & V_43 )
F_11 ( V_31 , V_23 -> V_36 & V_43 ? 1 : - 1 ) ;
}
static void F_19 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_25 * V_31 = V_27 -> V_22 -> V_19 -> V_28 ;
F_20 ( V_31 , V_23 ) ;
F_21 ( V_31 , V_23 ) ;
}
static int F_22 ( struct V_25 * V_23 , void * V_53 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_25 * V_31 = V_27 -> V_22 -> V_19 -> V_28 ;
struct V_54 * V_3 = V_53 ;
int V_35 ;
if ( ! F_23 ( V_3 -> V_55 ) )
return - V_56 ;
if ( ! ( V_23 -> V_36 & V_37 ) )
goto V_40;
if ( ! F_8 ( V_3 -> V_55 , V_31 -> V_39 ) ) {
V_35 = F_9 ( V_31 , V_3 -> V_55 ) ;
if ( V_35 < 0 )
return V_35 ;
}
if ( ! F_8 ( V_23 -> V_39 , V_31 -> V_39 ) )
F_13 ( V_31 , V_23 -> V_39 ) ;
V_40:
F_24 ( V_23 -> V_39 , V_3 -> V_55 ) ;
return 0 ;
}
static int F_25 ( struct V_25 * V_23 ,
const struct V_57 * V_58 ,
struct V_59 * V_60 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( F_26 ( V_60 ) ) {
if ( ! V_6 -> V_9 -> V_61 || ! V_6 -> V_9 -> V_62 )
return - V_63 ;
return V_6 -> V_9 -> V_61 ( V_6 , V_27 -> V_46 , V_58 , V_60 ) ;
}
V_6 -> V_9 -> V_62 ( V_6 , V_27 -> V_46 , V_58 , V_60 ) ;
return 0 ;
}
static int F_27 ( struct V_25 * V_23 ,
const struct V_57 * V_58 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( ! V_6 -> V_9 -> V_64 )
return - V_63 ;
return V_6 -> V_9 -> V_64 ( V_6 , V_27 -> V_46 , V_58 ) ;
}
static int F_28 ( struct V_25 * V_23 ,
struct V_57 * V_58 ,
T_3 * V_65 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_66 )
return V_6 -> V_9 -> V_66 ( V_6 , V_27 -> V_46 , V_58 , V_65 ) ;
return - V_63 ;
}
static int F_29 ( struct V_25 * V_23 ,
const struct V_67 * V_68 ,
struct V_59 * V_60 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( F_26 ( V_60 ) ) {
if ( ! V_6 -> V_9 -> V_69 || ! V_6 -> V_9 -> V_70 )
return - V_63 ;
return V_6 -> V_9 -> V_69 ( V_6 , V_27 -> V_46 , V_68 , V_60 ) ;
}
V_6 -> V_9 -> V_70 ( V_6 , V_27 -> V_46 , V_68 , V_60 ) ;
return 0 ;
}
static int F_30 ( struct V_25 * V_23 ,
const struct V_67 * V_68 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
int V_71 = - V_63 ;
if ( V_6 -> V_9 -> V_72 )
V_71 = V_6 -> V_9 -> V_72 ( V_6 , V_27 -> V_46 , V_68 ) ;
return V_71 ;
}
static int F_31 ( struct V_25 * V_23 ,
struct V_67 * V_68 ,
T_3 * V_65 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_73 )
return V_6 -> V_9 -> V_73 ( V_6 , V_27 -> V_46 , V_68 , V_65 ) ;
return - V_63 ;
}
static int F_32 ( struct V_25 * V_23 , struct V_74 * V_75 , int V_76 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
if ( V_27 -> V_47 != NULL )
return F_33 ( V_27 -> V_47 , V_75 , V_76 ) ;
return - V_63 ;
}
static int F_34 ( struct V_25 * V_23 ,
const struct V_77 * V_78 ,
struct V_59 * V_60 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( F_26 ( V_60 ) )
return V_6 -> V_9 -> V_49 ? 0 : - V_63 ;
V_6 -> V_9 -> V_49 ( V_6 , V_27 -> V_46 , V_78 -> V_79 . V_32 ) ;
return 0 ;
}
static int F_35 ( struct V_25 * V_23 ,
const struct V_77 * V_78 ,
struct V_59 * V_60 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( F_26 ( V_60 ) )
return 0 ;
if ( V_6 -> V_9 -> V_80 )
return V_6 -> V_9 -> V_80 ( V_6 , V_27 -> V_46 ,
V_78 -> V_79 . V_81 ) ;
return 0 ;
}
static int F_36 ( struct V_5 * V_6 ,
unsigned int V_82 )
{
int V_83 ;
for ( V_83 = 0 ; V_83 < V_84 ; ++ V_83 ) {
struct V_85 * V_86 = & V_6 -> V_87 [ V_83 ] ;
if ( V_86 && V_86 -> V_82 && V_86 -> V_82 < V_82 )
V_82 = V_86 -> V_82 ;
}
return V_82 ;
}
static int F_37 ( struct V_25 * V_23 ,
const struct V_77 * V_78 ,
struct V_59 * V_60 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
unsigned long V_88 = F_38 ( V_78 -> V_79 . V_82 ) ;
unsigned int V_82 = F_39 ( V_88 ) ;
if ( F_26 ( V_60 ) )
return 0 ;
V_6 -> V_87 [ V_27 -> V_46 ] . V_82 = V_82 ;
V_82 = F_36 ( V_6 , V_82 ) ;
if ( V_6 -> V_9 -> V_89 )
return V_6 -> V_9 -> V_89 ( V_6 , V_82 ) ;
return 0 ;
}
static int F_40 ( struct V_25 * V_23 ,
const struct V_77 * V_78 ,
struct V_59 * V_60 )
{
int V_71 ;
switch ( V_78 -> V_17 ) {
case V_90 :
V_71 = F_34 ( V_23 , V_78 , V_60 ) ;
break;
case V_91 :
V_71 = F_35 ( V_23 , V_78 , V_60 ) ;
break;
case V_92 :
V_71 = F_37 ( V_23 , V_78 , V_60 ) ;
break;
default:
V_71 = - V_63 ;
break;
}
return V_71 ;
}
static int F_41 ( struct V_25 * V_23 ,
const struct V_93 * V_94 ,
struct V_59 * V_60 )
{
int V_35 ;
switch ( V_94 -> V_17 ) {
case V_95 :
V_35 = F_29 ( V_23 ,
F_42 ( V_94 ) ,
V_60 ) ;
break;
case V_96 :
V_35 = F_25 ( V_23 ,
F_43 ( V_94 ) ,
V_60 ) ;
break;
default:
V_35 = - V_63 ;
break;
}
return V_35 ;
}
static int F_44 ( struct V_25 * V_23 ,
const struct V_93 * V_94 )
{
int V_35 ;
switch ( V_94 -> V_17 ) {
case V_95 :
V_35 = F_30 ( V_23 ,
F_42 ( V_94 ) ) ;
break;
case V_96 :
V_35 = F_27 ( V_23 ,
F_43 ( V_94 ) ) ;
break;
default:
V_35 = - V_63 ;
break;
}
return V_35 ;
}
static int F_45 ( struct V_25 * V_23 ,
struct V_93 * V_94 ,
T_3 * V_65 )
{
int V_35 ;
switch ( V_94 -> V_17 ) {
case V_95 :
V_35 = F_31 ( V_23 ,
F_42 ( V_94 ) ,
V_65 ) ;
break;
case V_96 :
V_35 = F_28 ( V_23 ,
F_43 ( V_94 ) ,
V_65 ) ;
break;
default:
V_35 = - V_63 ;
break;
}
return V_35 ;
}
static int F_46 ( struct V_25 * V_23 ,
struct V_25 * V_97 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
int V_71 = - V_63 ;
V_27 -> V_30 = V_97 ;
if ( V_6 -> V_9 -> V_98 )
V_71 = V_6 -> V_9 -> V_98 ( V_6 , V_27 -> V_46 , V_97 ) ;
return V_71 == - V_63 ? 0 : V_71 ;
}
static void F_47 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_99 )
V_6 -> V_9 -> V_99 ( V_6 , V_27 -> V_46 ) ;
V_27 -> V_30 = NULL ;
if ( V_6 -> V_9 -> V_49 )
V_6 -> V_9 -> V_49 ( V_6 , V_27 -> V_46 , V_34 ) ;
}
static int F_48 ( struct V_25 * V_23 ,
struct V_77 * V_78 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
switch ( V_78 -> V_17 ) {
case V_100 :
V_78 -> V_79 . V_101 . V_102 = sizeof( V_6 -> V_21 ) ;
memcpy ( & V_78 -> V_79 . V_101 . V_17 , & V_6 -> V_21 , V_78 -> V_79 . V_101 . V_102 ) ;
break;
default:
return - V_63 ;
}
return 0 ;
}
static inline T_4 F_49 ( struct V_26 * V_27 ,
struct V_103 * V_104 )
{
#ifdef F_50
if ( V_27 -> V_105 )
F_51 ( V_27 -> V_105 , V_104 ) ;
#else
F_52 () ;
#endif
return V_106 ;
}
static T_4 F_53 ( struct V_103 * V_104 , struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_103 * V_107 ;
V_23 -> V_108 . V_109 ++ ;
V_23 -> V_108 . V_110 += V_104 -> V_111 ;
V_107 = V_27 -> V_112 ( V_104 , V_23 ) ;
if ( ! V_107 )
return V_106 ;
if ( F_54 ( F_55 ( V_23 ) ) )
return F_49 ( V_27 , V_107 ) ;
V_107 -> V_23 = V_27 -> V_22 -> V_19 -> V_28 ;
F_56 ( V_107 ) ;
return V_106 ;
}
static int
F_57 ( struct V_25 * V_23 , struct V_113 * V_76 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
int V_35 ;
V_35 = - V_63 ;
if ( V_27 -> V_47 != NULL ) {
V_35 = F_58 ( V_27 -> V_47 ) ;
if ( V_35 == 0 )
V_35 = F_59 ( V_27 -> V_47 , V_76 ) ;
}
return V_35 ;
}
static int
F_60 ( struct V_25 * V_23 , struct V_113 * V_76 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
if ( V_27 -> V_47 != NULL )
return F_61 ( V_27 -> V_47 , V_76 ) ;
return - V_63 ;
}
static void F_62 ( struct V_25 * V_23 ,
struct V_114 * V_115 )
{
F_63 ( V_115 -> V_116 , L_3 , sizeof( V_115 -> V_116 ) ) ;
F_63 ( V_115 -> V_117 , V_118 , sizeof( V_115 -> V_117 ) ) ;
F_63 ( V_115 -> V_119 , L_4 , sizeof( V_115 -> V_119 ) ) ;
F_63 ( V_115 -> V_120 , L_5 , sizeof( V_115 -> V_120 ) ) ;
}
static int F_64 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_121 )
return V_6 -> V_9 -> V_121 ( V_6 , V_27 -> V_46 ) ;
return - V_63 ;
}
static void
F_65 ( struct V_25 * V_23 , struct V_122 * V_123 , void * V_124 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_125 )
V_6 -> V_9 -> V_125 ( V_6 , V_27 -> V_46 , V_123 , V_124 ) ;
}
static int F_66 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
if ( V_27 -> V_47 != NULL )
return F_67 ( V_27 -> V_47 ) ;
return - V_63 ;
}
static T_5 F_68 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
if ( V_27 -> V_47 != NULL ) {
F_69 ( V_27 -> V_47 ) ;
return V_27 -> V_47 -> V_126 ;
}
return - V_63 ;
}
static int F_70 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_127 && V_6 -> V_127 -> V_128 )
return V_6 -> V_127 -> V_128 ;
if ( V_6 -> V_9 -> V_129 )
return V_6 -> V_9 -> V_129 ( V_6 ) ;
return 0 ;
}
static int F_71 ( struct V_25 * V_23 ,
struct V_130 * V_131 , T_2 * V_132 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_133 )
return V_6 -> V_9 -> V_133 ( V_6 , V_131 , V_132 ) ;
return - V_63 ;
}
static int F_72 ( struct V_25 * V_23 ,
struct V_130 * V_131 , T_2 * V_132 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_134 )
return V_6 -> V_9 -> V_134 ( V_6 , V_131 , V_132 ) ;
return - V_63 ;
}
static void F_73 ( struct V_25 * V_23 ,
T_6 V_135 , T_7 * V_132 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_135 == V_136 ) {
int V_111 = V_137 ;
strncpy ( V_132 , L_6 , V_111 ) ;
strncpy ( V_132 + V_111 , L_7 , V_111 ) ;
strncpy ( V_132 + 2 * V_111 , L_8 , V_111 ) ;
strncpy ( V_132 + 3 * V_111 , L_9 , V_111 ) ;
if ( V_6 -> V_9 -> V_138 != NULL )
V_6 -> V_9 -> V_138 ( V_6 , V_27 -> V_46 , V_132 + 4 * V_111 ) ;
}
}
static void F_74 ( struct V_25 * V_23 ,
struct V_139 * V_108 ,
T_8 * V_132 )
{
struct V_140 * V_19 = V_23 -> V_141 ;
struct V_5 * V_6 = V_19 -> V_6 [ 0 ] ;
T_9 V_142 = V_19 -> V_142 ;
int V_143 = 0 ;
if ( V_19 -> V_144 . V_145 ) {
V_143 = V_19 -> V_144 . V_145 ( V_23 ,
V_136 ) ;
V_19 -> V_144 . V_146 ( V_23 , V_108 , V_132 ) ;
}
if ( V_6 -> V_9 -> V_146 )
V_6 -> V_9 -> V_146 ( V_6 , V_142 , V_132 + V_143 ) ;
}
static int F_75 ( struct V_25 * V_23 , int V_147 )
{
struct V_140 * V_19 = V_23 -> V_141 ;
struct V_5 * V_6 = V_19 -> V_6 [ 0 ] ;
int V_143 = 0 ;
if ( V_19 -> V_144 . V_145 )
V_143 += V_19 -> V_144 . V_145 ( V_23 , V_147 ) ;
if ( V_147 == V_136 && V_6 -> V_9 -> V_145 )
V_143 += V_6 -> V_9 -> V_145 ( V_6 ) ;
return V_143 ;
}
static void F_76 ( struct V_25 * V_23 ,
T_6 V_135 , T_7 * V_132 )
{
struct V_140 * V_19 = V_23 -> V_141 ;
struct V_5 * V_6 = V_19 -> V_6 [ 0 ] ;
T_9 V_142 = V_19 -> V_142 ;
int V_111 = V_137 ;
int V_148 = 0 , V_143 ;
unsigned int V_83 ;
T_7 V_149 [ 4 ] ;
T_7 * V_150 ;
snprintf ( V_149 , sizeof( V_149 ) , L_10 , V_142 ) ;
V_149 [ sizeof( V_149 ) - 1 ] = '_' ;
if ( V_19 -> V_144 . V_145 ) {
V_148 = V_19 -> V_144 . V_145 ( V_23 ,
V_136 ) ;
V_19 -> V_144 . V_138 ( V_23 , V_135 , V_132 ) ;
}
if ( V_135 == V_136 && V_6 -> V_9 -> V_138 ) {
V_150 = V_132 + V_148 * V_111 ;
V_6 -> V_9 -> V_138 ( V_6 , V_142 , V_150 ) ;
V_143 = V_6 -> V_9 -> V_145 ( V_6 ) ;
for ( V_83 = 0 ; V_83 < V_143 ; V_83 ++ ) {
memmove ( V_150 + ( V_83 * V_111 + sizeof( V_149 ) ) ,
V_150 + V_83 * V_111 , V_111 - sizeof( V_149 ) ) ;
memcpy ( V_150 + V_83 * V_111 , V_149 , sizeof( V_149 ) ) ;
}
}
}
static void F_77 ( struct V_25 * V_23 ,
struct V_139 * V_108 ,
T_8 * V_132 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
V_132 [ 0 ] = V_23 -> V_108 . V_109 ;
V_132 [ 1 ] = V_23 -> V_108 . V_110 ;
V_132 [ 2 ] = V_23 -> V_108 . V_151 ;
V_132 [ 3 ] = V_23 -> V_108 . V_152 ;
if ( V_6 -> V_9 -> V_146 != NULL )
V_6 -> V_9 -> V_146 ( V_6 , V_27 -> V_46 , V_132 + 4 ) ;
}
static int F_78 ( struct V_25 * V_23 , int V_147 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_147 == V_136 ) {
int V_143 ;
V_143 = 4 ;
if ( V_6 -> V_9 -> V_145 != NULL )
V_143 += V_6 -> V_9 -> V_145 ( V_6 ) ;
return V_143 ;
}
return - V_63 ;
}
static void F_79 ( struct V_25 * V_23 , struct V_153 * V_154 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_155 )
V_6 -> V_9 -> V_155 ( V_6 , V_27 -> V_46 , V_154 ) ;
}
static int F_80 ( struct V_25 * V_23 , struct V_153 * V_154 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
int V_71 = - V_63 ;
if ( V_6 -> V_9 -> V_156 )
V_71 = V_6 -> V_9 -> V_156 ( V_6 , V_27 -> V_46 , V_154 ) ;
return V_71 ;
}
static int F_81 ( struct V_25 * V_23 , struct V_157 * V_158 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
int V_71 ;
if ( ! V_6 -> V_9 -> V_159 )
return - V_63 ;
V_71 = V_6 -> V_9 -> V_159 ( V_6 , V_27 -> V_46 , V_27 -> V_47 , V_158 ) ;
if ( V_71 )
return V_71 ;
if ( V_27 -> V_47 )
V_71 = F_82 ( V_27 -> V_47 , V_158 ) ;
return V_71 ;
}
static int F_83 ( struct V_25 * V_23 , struct V_157 * V_158 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
int V_71 ;
if ( ! V_6 -> V_9 -> V_160 )
return - V_63 ;
V_71 = V_6 -> V_9 -> V_160 ( V_6 , V_27 -> V_46 , V_158 ) ;
if ( V_71 )
return V_71 ;
if ( V_27 -> V_47 )
V_71 = F_84 ( V_27 -> V_47 , V_158 ) ;
return V_71 ;
}
static int F_85 ( struct V_25 * V_23 ,
struct V_161 * V_162 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
struct V_25 * V_31 = V_6 -> V_19 -> V_28 ;
struct V_105 * V_105 ;
int V_35 = 0 ;
V_105 = F_86 ( sizeof( * V_105 ) , V_163 ) ;
if ( ! V_105 )
return - V_164 ;
V_35 = F_87 ( V_105 , V_31 ) ;
if ( V_35 ) {
F_88 ( V_105 ) ;
goto V_40;
}
V_27 -> V_105 = V_105 ;
V_40:
return V_35 ;
}
static void F_89 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_105 * V_105 = V_27 -> V_105 ;
if ( ! V_105 )
return;
V_27 -> V_105 = NULL ;
F_90 ( V_105 ) ;
}
static void F_91 ( struct V_25 * V_23 )
{
}
void F_92 ( struct V_165 * V_166 )
{
V_166 -> V_145 = F_75 ;
V_166 -> V_146 = F_74 ;
V_166 -> V_138 = F_76 ;
}
static void F_93 ( struct V_25 * V_23 )
{
struct V_26 * V_27 = F_5 ( V_23 ) ;
struct V_5 * V_6 = V_27 -> V_22 ;
unsigned int V_167 = 0 ;
if ( V_27 -> V_168 != V_27 -> V_47 -> V_126 ) {
V_167 = 1 ;
V_27 -> V_168 = V_27 -> V_47 -> V_126 ;
}
if ( V_27 -> V_169 != V_27 -> V_47 -> V_170 ) {
V_167 = 1 ;
V_27 -> V_169 = V_27 -> V_47 -> V_170 ;
}
if ( V_27 -> V_171 != V_27 -> V_47 -> V_172 ) {
V_167 = 1 ;
V_27 -> V_171 = V_27 -> V_47 -> V_172 ;
}
if ( V_6 -> V_9 -> V_173 && V_167 )
V_6 -> V_9 -> V_173 ( V_6 , V_27 -> V_46 , V_27 -> V_47 ) ;
if ( V_167 )
F_94 ( V_27 -> V_47 ) ;
}
static int F_95 ( struct V_25 * V_23 ,
struct V_174 * V_175 )
{
struct V_26 * V_27 ;
struct V_5 * V_6 ;
if ( V_23 ) {
V_27 = F_5 ( V_23 ) ;
V_6 = V_27 -> V_22 ;
if ( V_6 -> V_9 -> V_176 )
V_6 -> V_9 -> V_176 ( V_6 , V_27 -> V_46 , V_175 ) ;
}
return 0 ;
}
static int F_96 ( struct V_26 * V_27 ,
struct V_25 * V_177 ,
int V_3 )
{
struct V_5 * V_6 = V_27 -> V_22 ;
V_27 -> V_47 = F_97 ( V_6 -> V_13 , V_3 ) ;
if ( ! V_27 -> V_47 ) {
F_98 ( V_177 , L_11 , V_3 ) ;
return - V_178 ;
}
if ( V_27 -> V_179 == V_180 )
V_27 -> V_179 = V_27 -> V_47 -> V_181 ;
F_99 ( V_177 , V_27 -> V_47 , F_93 ,
V_27 -> V_179 ) ;
return 0 ;
}
static int F_100 ( struct V_26 * V_27 ,
struct V_25 * V_177 )
{
struct V_5 * V_6 = V_27 -> V_22 ;
struct V_182 * V_183 , * V_184 ;
bool V_185 = false ;
T_5 V_186 = 0 ;
int V_187 , V_71 ;
V_184 = V_6 -> V_87 [ V_27 -> V_46 ] . V_188 ;
V_187 = F_101 ( V_184 ) ;
if ( V_187 < 0 )
V_187 = V_180 ;
V_27 -> V_179 = V_187 ;
V_183 = F_102 ( V_184 , L_12 , 0 ) ;
if ( F_103 ( V_184 ) ) {
V_71 = F_104 ( V_184 ) ;
if ( V_71 ) {
F_98 ( V_177 , L_13 , V_71 ) ;
return V_71 ;
}
V_185 = true ;
V_183 = V_184 ;
}
if ( V_6 -> V_9 -> V_189 )
V_186 = V_6 -> V_9 -> V_189 ( V_6 , V_27 -> V_46 ) ;
if ( V_183 ) {
int V_190 = F_105 ( & V_177 -> V_23 , V_183 ) ;
if ( ! V_185 && V_190 >= 0 &&
( V_6 -> V_8 & ( 1 << V_190 ) ) ) {
V_71 = F_96 ( V_27 , V_177 , V_190 ) ;
if ( V_71 ) {
F_98 ( V_177 , L_14 , V_190 , V_71 ) ;
return V_71 ;
}
} else {
V_27 -> V_47 = F_106 ( V_177 , V_183 ,
F_93 ,
V_186 ,
V_27 -> V_179 ) ;
}
}
if ( V_27 -> V_47 && V_185 )
F_107 ( V_27 -> V_47 , F_95 ) ;
if ( ! V_27 -> V_47 ) {
V_71 = F_96 ( V_27 , V_177 , V_27 -> V_46 ) ;
if ( V_71 ) {
F_98 ( V_177 , L_15 , V_27 -> V_46 , V_71 ) ;
return V_71 ;
}
}
F_108 ( V_27 -> V_47 ) ;
return 0 ;
}
static void F_109 ( struct V_25 * V_23 ,
struct V_191 * V_192 ,
void * V_193 )
{
F_110 ( & V_192 -> V_194 ,
& V_195 ) ;
}
int F_111 ( struct V_25 * V_177 )
{
struct V_26 * V_27 = F_5 ( V_177 ) ;
if ( V_27 -> V_47 ) {
F_15 ( V_27 -> V_47 ) ;
V_27 -> V_171 = - 1 ;
V_27 -> V_168 = - 1 ;
V_27 -> V_169 = - 1 ;
F_112 ( V_27 -> V_47 ) ;
}
return 0 ;
}
int F_113 ( struct V_25 * V_177 )
{
struct V_26 * V_27 = F_5 ( V_177 ) ;
F_114 ( V_177 ) ;
if ( V_27 -> V_47 ) {
F_115 ( V_27 -> V_47 ) ;
F_12 ( V_27 -> V_47 ) ;
}
return 0 ;
}
int F_116 ( struct V_5 * V_6 , struct V_196 * V_22 ,
int V_46 , const char * V_14 )
{
struct V_140 * V_19 = V_6 -> V_19 ;
struct V_25 * V_31 ;
struct V_25 * V_177 ;
struct V_26 * V_27 ;
int V_71 ;
V_31 = V_6 -> V_19 -> V_28 ;
if ( V_6 -> V_28 )
V_31 = V_6 -> V_28 ;
V_177 = F_117 ( sizeof( struct V_26 ) , V_14 ,
V_197 , V_198 ) ;
if ( V_177 == NULL )
return - V_164 ;
V_177 -> V_199 = V_31 -> V_200 ;
V_177 -> V_165 = & V_201 ;
F_118 ( V_177 , V_31 ) ;
V_177 -> V_202 |= V_203 ;
V_177 -> V_204 = & V_205 ;
V_177 -> V_206 = & V_207 ;
F_119 ( V_177 , & V_208 ) ;
F_120 ( V_177 , F_109 ,
NULL ) ;
F_121 ( V_177 , V_22 ) ;
V_177 -> V_23 . V_209 = V_6 -> V_87 [ V_46 ] . V_188 ;
V_177 -> V_200 = V_31 -> V_200 ;
V_27 = F_5 ( V_177 ) ;
V_27 -> V_22 = V_6 ;
V_27 -> V_46 = V_46 ;
V_27 -> V_112 = V_19 -> V_210 -> V_112 ;
V_27 -> V_171 = - 1 ;
V_27 -> V_168 = - 1 ;
V_27 -> V_169 = - 1 ;
V_6 -> V_87 [ V_46 ] . V_211 = V_177 ;
V_71 = F_122 ( V_177 ) ;
if ( V_71 ) {
F_98 ( V_31 , L_16 ,
V_71 , V_177 -> V_14 ) ;
V_6 -> V_87 [ V_46 ] . V_211 = NULL ;
F_123 ( V_177 ) ;
return V_71 ;
}
F_124 ( V_177 ) ;
V_71 = F_100 ( V_27 , V_177 ) ;
if ( V_71 ) {
F_98 ( V_31 , L_17 , V_71 ) ;
F_125 ( V_177 ) ;
F_123 ( V_177 ) ;
return V_71 ;
}
return 0 ;
}
void F_126 ( struct V_25 * V_177 )
{
struct V_26 * V_27 = F_5 ( V_177 ) ;
F_124 ( V_177 ) ;
if ( V_27 -> V_47 )
F_127 ( V_27 -> V_47 ) ;
F_125 ( V_177 ) ;
F_123 ( V_177 ) ;
}
static bool F_128 ( struct V_25 * V_23 )
{
return V_23 -> V_204 == & V_205 ;
}
static int F_129 ( struct V_25 * V_23 ,
unsigned long V_212 , void * V_213 )
{
struct V_214 * V_215 = V_213 ;
struct V_25 * V_216 = V_215 -> V_217 ;
int V_35 = 0 ;
switch ( V_212 ) {
case V_218 :
if ( F_130 ( V_216 ) ) {
if ( V_215 -> V_219 )
V_35 = F_46 ( V_23 , V_216 ) ;
else
F_47 ( V_23 ) ;
}
break;
}
return F_131 ( V_35 ) ;
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
