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
static int F_4 ( const struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
return V_28 -> V_22 -> V_29 -> V_30 -> V_31 ;
}
static inline bool F_6 ( struct V_27 * V_28 )
{
return ! ! V_28 -> V_32 ;
}
static int F_7 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_25 * V_33 = V_28 -> V_22 -> V_29 -> V_30 ;
struct V_5 * V_6 = V_28 -> V_22 ;
T_2 V_34 = F_6 ( V_28 ) ?
V_35 : V_36 ;
int V_37 ;
if ( ! ( V_33 -> V_38 & V_39 ) )
return - V_40 ;
if ( ! F_8 ( V_26 -> V_41 , V_33 -> V_41 ) ) {
V_37 = F_9 ( V_33 , V_26 -> V_41 ) ;
if ( V_37 < 0 )
goto V_42;
}
if ( V_26 -> V_38 & V_43 ) {
V_37 = F_10 ( V_33 , 1 ) ;
if ( V_37 < 0 )
goto V_44;
}
if ( V_26 -> V_38 & V_45 ) {
V_37 = F_11 ( V_33 , 1 ) ;
if ( V_37 < 0 )
goto V_46;
}
if ( V_6 -> V_9 -> V_47 ) {
V_37 = V_6 -> V_9 -> V_47 ( V_6 , V_28 -> V_48 , V_28 -> V_49 ) ;
if ( V_37 )
goto V_50;
}
if ( V_6 -> V_9 -> V_51 )
V_6 -> V_9 -> V_51 ( V_6 , V_28 -> V_48 , V_34 ) ;
if ( V_28 -> V_49 )
F_12 ( V_28 -> V_49 ) ;
return 0 ;
V_50:
if ( V_26 -> V_38 & V_45 )
F_11 ( V_33 , - 1 ) ;
V_46:
if ( V_26 -> V_38 & V_43 )
F_10 ( V_33 , - 1 ) ;
V_44:
if ( ! F_8 ( V_26 -> V_41 , V_33 -> V_41 ) )
F_13 ( V_33 , V_26 -> V_41 ) ;
V_42:
return V_37 ;
}
static int F_14 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_25 * V_33 = V_28 -> V_22 -> V_29 -> V_30 ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_28 -> V_49 )
F_15 ( V_28 -> V_49 ) ;
F_16 ( V_33 , V_26 ) ;
F_17 ( V_33 , V_26 ) ;
if ( V_26 -> V_38 & V_43 )
F_10 ( V_33 , - 1 ) ;
if ( V_26 -> V_38 & V_45 )
F_11 ( V_33 , - 1 ) ;
if ( ! F_8 ( V_26 -> V_41 , V_33 -> V_41 ) )
F_13 ( V_33 , V_26 -> V_41 ) ;
if ( V_6 -> V_9 -> V_52 )
V_6 -> V_9 -> V_52 ( V_6 , V_28 -> V_48 , V_28 -> V_49 ) ;
if ( V_6 -> V_9 -> V_51 )
V_6 -> V_9 -> V_51 ( V_6 , V_28 -> V_48 , V_53 ) ;
return 0 ;
}
static void F_18 ( struct V_25 * V_26 , int V_54 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_25 * V_33 = V_28 -> V_22 -> V_29 -> V_30 ;
if ( V_54 & V_43 )
F_10 ( V_33 , V_26 -> V_38 & V_43 ? 1 : - 1 ) ;
if ( V_54 & V_45 )
F_11 ( V_33 , V_26 -> V_38 & V_45 ? 1 : - 1 ) ;
}
static void F_19 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_25 * V_33 = V_28 -> V_22 -> V_29 -> V_30 ;
F_20 ( V_33 , V_26 ) ;
F_21 ( V_33 , V_26 ) ;
}
static int F_22 ( struct V_25 * V_26 , void * V_55 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_25 * V_33 = V_28 -> V_22 -> V_29 -> V_30 ;
struct V_56 * V_3 = V_55 ;
int V_37 ;
if ( ! F_23 ( V_3 -> V_57 ) )
return - V_58 ;
if ( ! ( V_26 -> V_38 & V_39 ) )
goto V_42;
if ( ! F_8 ( V_3 -> V_57 , V_33 -> V_41 ) ) {
V_37 = F_9 ( V_33 , V_3 -> V_57 ) ;
if ( V_37 < 0 )
return V_37 ;
}
if ( ! F_8 ( V_26 -> V_41 , V_33 -> V_41 ) )
F_13 ( V_33 , V_26 -> V_41 ) ;
V_42:
F_24 ( V_26 -> V_41 , V_3 -> V_57 ) ;
return 0 ;
}
static int F_25 ( struct V_25 * V_26 ,
const struct V_59 * V_60 ,
struct V_61 * V_62 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_37 ;
if ( F_26 ( V_62 ) ) {
if ( ! V_6 -> V_9 -> V_63 || ! V_6 -> V_9 -> V_64 )
return - V_65 ;
V_37 = V_6 -> V_9 -> V_63 ( V_6 , V_28 -> V_48 , V_60 , V_62 ) ;
if ( V_37 )
return V_37 ;
} else {
V_37 = V_6 -> V_9 -> V_64 ( V_6 , V_28 -> V_48 , V_60 , V_62 ) ;
if ( V_37 )
return V_37 ;
}
return 0 ;
}
static int F_27 ( struct V_25 * V_26 ,
const struct V_59 * V_60 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( ! V_6 -> V_9 -> V_66 )
return - V_65 ;
return V_6 -> V_9 -> V_66 ( V_6 , V_28 -> V_48 , V_60 ) ;
}
static int F_28 ( struct V_25 * V_26 ,
struct V_59 * V_60 ,
T_3 * V_67 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_68 )
return V_6 -> V_9 -> V_68 ( V_6 , V_28 -> V_48 , V_60 , V_67 ) ;
return - V_65 ;
}
static int F_29 ( struct V_25 * V_26 ,
const struct V_69 * V_70 ,
struct V_61 * V_62 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_71 ;
if ( ! V_6 -> V_9 -> V_72 || ! V_6 -> V_9 -> V_73 )
return - V_65 ;
if ( F_26 ( V_62 ) )
V_71 = V_6 -> V_9 -> V_72 ( V_6 , V_28 -> V_48 , V_70 , V_62 ) ;
else
V_71 = V_6 -> V_9 -> V_73 ( V_6 , V_28 -> V_48 , V_70 , V_62 ) ;
return V_71 ;
}
static int F_30 ( struct V_25 * V_26 ,
const struct V_69 * V_70 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_71 = - V_65 ;
if ( V_6 -> V_9 -> V_74 )
V_71 = V_6 -> V_9 -> V_74 ( V_6 , V_28 -> V_48 , V_70 ) ;
return V_71 ;
}
static int F_31 ( struct V_25 * V_26 ,
struct V_69 * V_70 ,
T_3 * V_67 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_75 )
return V_6 -> V_9 -> V_75 ( V_6 , V_28 -> V_48 , V_70 , V_67 ) ;
return - V_65 ;
}
static int F_32 ( struct V_25 * V_26 , struct V_76 * V_77 , int V_78 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
if ( V_28 -> V_49 != NULL )
return F_33 ( V_28 -> V_49 , V_77 , V_78 ) ;
return - V_65 ;
}
static int F_34 ( struct V_25 * V_26 , T_2 V_79 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_71 = - V_65 ;
if ( V_6 -> V_9 -> V_51 )
V_71 = V_6 -> V_9 -> V_51 ( V_6 , V_28 -> V_48 , V_79 ) ;
return V_71 ;
}
static int F_35 ( struct V_25 * V_26 ,
const struct V_80 * V_81 ,
struct V_61 * V_62 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( F_26 ( V_62 ) )
return 0 ;
if ( V_6 -> V_9 -> V_82 )
return V_6 -> V_9 -> V_82 ( V_6 , V_28 -> V_48 ,
V_81 -> V_83 . V_84 ) ;
return 0 ;
}
static int F_36 ( struct V_25 * V_26 ,
const struct V_80 * V_81 ,
struct V_61 * V_62 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_71 ;
switch ( V_81 -> V_17 ) {
case V_85 :
if ( F_26 ( V_62 ) )
V_71 = V_6 -> V_9 -> V_51 ? 0 : - V_65 ;
else
V_71 = V_6 -> V_9 -> V_51 ( V_6 , V_28 -> V_48 ,
V_81 -> V_83 . V_34 ) ;
break;
case V_86 :
V_71 = F_35 ( V_26 , V_81 , V_62 ) ;
break;
default:
V_71 = - V_65 ;
break;
}
return V_71 ;
}
static int F_37 ( struct V_25 * V_26 ,
const struct V_87 * V_88 ,
struct V_61 * V_62 )
{
int V_37 ;
switch ( V_88 -> V_17 ) {
case V_89 :
V_37 = F_29 ( V_26 ,
F_38 ( V_88 ) ,
V_62 ) ;
break;
case V_90 :
V_37 = F_25 ( V_26 ,
F_39 ( V_88 ) ,
V_62 ) ;
break;
default:
V_37 = - V_65 ;
break;
}
return V_37 ;
}
static int F_40 ( struct V_25 * V_26 ,
const struct V_87 * V_88 )
{
int V_37 ;
switch ( V_88 -> V_17 ) {
case V_89 :
V_37 = F_30 ( V_26 ,
F_38 ( V_88 ) ) ;
break;
case V_90 :
V_37 = F_27 ( V_26 ,
F_39 ( V_88 ) ) ;
break;
default:
V_37 = - V_65 ;
break;
}
return V_37 ;
}
static int F_41 ( struct V_25 * V_26 ,
struct V_87 * V_88 ,
T_3 * V_67 )
{
int V_37 ;
switch ( V_88 -> V_17 ) {
case V_89 :
V_37 = F_31 ( V_26 ,
F_38 ( V_88 ) ,
V_67 ) ;
break;
case V_90 :
V_37 = F_28 ( V_26 ,
F_39 ( V_88 ) ,
V_67 ) ;
break;
default:
V_37 = - V_65 ;
break;
}
return V_37 ;
}
static int F_42 ( struct V_25 * V_26 ,
struct V_25 * V_91 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_71 = - V_65 ;
V_28 -> V_32 = V_91 ;
if ( V_6 -> V_9 -> V_92 )
V_71 = V_6 -> V_9 -> V_92 ( V_6 , V_28 -> V_48 , V_91 ) ;
return V_71 == - V_65 ? 0 : V_71 ;
}
static void F_43 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_93 )
V_6 -> V_9 -> V_93 ( V_6 , V_28 -> V_48 ) ;
V_28 -> V_32 = NULL ;
F_34 ( V_26 , V_36 ) ;
}
static int F_44 ( struct V_25 * V_26 ,
struct V_80 * V_81 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
switch ( V_81 -> V_17 ) {
case V_94 :
V_81 -> V_83 . V_95 . V_96 = sizeof( V_6 -> V_19 ) ;
memcpy ( & V_81 -> V_83 . V_95 . V_17 , & V_6 -> V_19 , V_81 -> V_83 . V_95 . V_96 ) ;
break;
default:
return - V_65 ;
}
return 0 ;
}
static inline T_4 F_45 ( struct V_27 * V_28 ,
struct V_97 * V_98 )
{
#ifdef F_46
if ( V_28 -> V_99 )
F_47 ( V_28 -> V_99 , V_98 ) ;
#else
F_48 () ;
#endif
return V_100 ;
}
static T_4 F_49 ( struct V_97 * V_98 , struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_97 * V_101 ;
V_26 -> V_102 . V_103 ++ ;
V_26 -> V_102 . V_104 += V_98 -> V_105 ;
V_101 = V_28 -> V_106 ( V_98 , V_26 ) ;
if ( ! V_101 )
return V_100 ;
if ( F_50 ( F_51 ( V_26 ) ) )
return F_45 ( V_28 , V_101 ) ;
V_101 -> V_26 = V_28 -> V_22 -> V_29 -> V_30 ;
F_52 ( V_101 ) ;
return V_100 ;
}
static struct V_97 * F_53 ( struct V_97 * V_98 ,
struct V_25 * V_26 )
{
return V_98 ;
}
static int
F_54 ( struct V_25 * V_26 , struct V_107 * V_78 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
int V_37 ;
V_37 = - V_65 ;
if ( V_28 -> V_49 != NULL ) {
V_37 = F_55 ( V_28 -> V_49 ) ;
if ( V_37 == 0 )
V_37 = F_56 ( V_28 -> V_49 , V_78 ) ;
}
return V_37 ;
}
static int
F_57 ( struct V_25 * V_26 , struct V_107 * V_78 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
if ( V_28 -> V_49 != NULL )
return F_58 ( V_28 -> V_49 , V_78 ) ;
return - V_65 ;
}
static void F_59 ( struct V_25 * V_26 ,
struct V_108 * V_109 )
{
F_60 ( V_109 -> V_110 , L_3 , sizeof( V_109 -> V_110 ) ) ;
F_60 ( V_109 -> V_111 , V_112 , sizeof( V_109 -> V_111 ) ) ;
F_60 ( V_109 -> V_113 , L_4 , sizeof( V_109 -> V_113 ) ) ;
F_60 ( V_109 -> V_114 , L_5 , sizeof( V_109 -> V_114 ) ) ;
}
static int F_61 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_115 )
return V_6 -> V_9 -> V_115 ( V_6 , V_28 -> V_48 ) ;
return - V_65 ;
}
static void
F_62 ( struct V_25 * V_26 , struct V_116 * V_117 , void * V_118 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_119 )
V_6 -> V_9 -> V_119 ( V_6 , V_28 -> V_48 , V_117 , V_118 ) ;
}
static int F_63 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
if ( V_28 -> V_49 != NULL )
return F_64 ( V_28 -> V_49 ) ;
return - V_65 ;
}
static T_5 F_65 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
if ( V_28 -> V_49 != NULL ) {
F_66 ( V_28 -> V_49 ) ;
return V_28 -> V_49 -> V_120 ;
}
return - V_65 ;
}
static int F_67 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_20 -> V_121 )
return V_6 -> V_20 -> V_121 ;
if ( V_6 -> V_9 -> V_122 )
return V_6 -> V_9 -> V_122 ( V_6 ) ;
return 0 ;
}
static int F_68 ( struct V_25 * V_26 ,
struct V_123 * V_124 , T_2 * V_125 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_126 )
return V_6 -> V_9 -> V_126 ( V_6 , V_124 , V_125 ) ;
return - V_65 ;
}
static int F_69 ( struct V_25 * V_26 ,
struct V_123 * V_124 , T_2 * V_125 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_127 )
return V_6 -> V_9 -> V_127 ( V_6 , V_124 , V_125 ) ;
return - V_65 ;
}
static void F_70 ( struct V_25 * V_26 ,
T_6 V_128 , T_7 * V_125 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_128 == V_129 ) {
int V_105 = V_130 ;
strncpy ( V_125 , L_6 , V_105 ) ;
strncpy ( V_125 + V_105 , L_7 , V_105 ) ;
strncpy ( V_125 + 2 * V_105 , L_8 , V_105 ) ;
strncpy ( V_125 + 3 * V_105 , L_9 , V_105 ) ;
if ( V_6 -> V_9 -> V_131 != NULL )
V_6 -> V_9 -> V_131 ( V_6 , V_28 -> V_48 , V_125 + 4 * V_105 ) ;
}
}
static void F_71 ( struct V_25 * V_26 ,
struct V_132 * V_102 ,
T_8 * V_125 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
V_125 [ 0 ] = V_28 -> V_26 -> V_102 . V_103 ;
V_125 [ 1 ] = V_28 -> V_26 -> V_102 . V_104 ;
V_125 [ 2 ] = V_28 -> V_26 -> V_102 . V_133 ;
V_125 [ 3 ] = V_28 -> V_26 -> V_102 . V_134 ;
if ( V_6 -> V_9 -> V_135 != NULL )
V_6 -> V_9 -> V_135 ( V_6 , V_28 -> V_48 , V_125 + 4 ) ;
}
static int F_72 ( struct V_25 * V_26 , int V_136 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_136 == V_129 ) {
int V_137 ;
V_137 = 4 ;
if ( V_6 -> V_9 -> V_138 != NULL )
V_137 += V_6 -> V_9 -> V_138 ( V_6 ) ;
return V_137 ;
}
return - V_65 ;
}
static void F_73 ( struct V_25 * V_26 , struct V_139 * V_140 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_141 )
V_6 -> V_9 -> V_141 ( V_6 , V_28 -> V_48 , V_140 ) ;
}
static int F_74 ( struct V_25 * V_26 , struct V_139 * V_140 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_71 = - V_65 ;
if ( V_6 -> V_9 -> V_142 )
V_71 = V_6 -> V_9 -> V_142 ( V_6 , V_28 -> V_48 , V_140 ) ;
return V_71 ;
}
static int F_75 ( struct V_25 * V_26 , struct V_143 * V_144 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_71 ;
if ( ! V_6 -> V_9 -> V_145 )
return - V_65 ;
V_71 = V_6 -> V_9 -> V_145 ( V_6 , V_28 -> V_48 , V_28 -> V_49 , V_144 ) ;
if ( V_71 )
return V_71 ;
if ( V_28 -> V_49 )
V_71 = F_76 ( V_28 -> V_49 , V_144 ) ;
return V_71 ;
}
static int F_77 ( struct V_25 * V_26 , struct V_143 * V_144 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_71 ;
if ( ! V_6 -> V_9 -> V_146 )
return - V_65 ;
V_71 = V_6 -> V_9 -> V_146 ( V_6 , V_28 -> V_48 , V_144 ) ;
if ( V_71 )
return V_71 ;
if ( V_28 -> V_49 )
V_71 = F_78 ( V_28 -> V_49 , V_144 ) ;
return V_71 ;
}
static int F_79 ( struct V_25 * V_26 ,
struct V_147 * V_148 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
struct V_25 * V_33 = V_6 -> V_29 -> V_30 ;
struct V_99 * V_99 ;
int V_37 = 0 ;
V_99 = F_80 ( sizeof( * V_99 ) , V_149 ) ;
if ( ! V_99 )
return - V_150 ;
V_37 = F_81 ( V_99 , V_33 ) ;
if ( V_37 ) {
F_82 ( V_99 ) ;
goto V_42;
}
V_28 -> V_99 = V_99 ;
V_42:
return V_37 ;
}
static void F_83 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_99 * V_99 = V_28 -> V_99 ;
if ( ! V_99 )
return;
V_28 -> V_99 = NULL ;
F_84 ( V_99 ) ;
}
static void F_85 ( struct V_25 * V_26 )
{
}
static void F_86 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
unsigned int V_151 = 0 ;
if ( V_28 -> V_152 != V_28 -> V_49 -> V_120 ) {
V_151 = 1 ;
V_28 -> V_152 = V_28 -> V_49 -> V_120 ;
}
if ( V_28 -> V_153 != V_28 -> V_49 -> V_154 ) {
V_151 = 1 ;
V_28 -> V_153 = V_28 -> V_49 -> V_154 ;
}
if ( V_28 -> V_155 != V_28 -> V_49 -> V_156 ) {
V_151 = 1 ;
V_28 -> V_155 = V_28 -> V_49 -> V_156 ;
}
if ( V_6 -> V_9 -> V_157 && V_151 )
V_6 -> V_9 -> V_157 ( V_6 , V_28 -> V_48 , V_28 -> V_49 ) ;
if ( V_151 )
F_87 ( V_28 -> V_49 ) ;
}
static int F_88 ( struct V_25 * V_26 ,
struct V_158 * V_159 )
{
struct V_27 * V_28 ;
struct V_5 * V_6 ;
if ( V_26 ) {
V_28 = F_5 ( V_26 ) ;
V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_160 )
V_6 -> V_9 -> V_160 ( V_6 , V_28 -> V_48 , V_159 ) ;
}
return 0 ;
}
static int F_89 ( struct V_27 * V_28 ,
struct V_25 * V_161 ,
int V_3 )
{
struct V_5 * V_6 = V_28 -> V_22 ;
V_28 -> V_49 = F_90 ( V_6 -> V_13 , V_3 ) ;
if ( ! V_28 -> V_49 ) {
F_91 ( V_161 , L_10 , V_3 ) ;
return - V_162 ;
}
if ( V_28 -> V_163 == V_164 )
V_28 -> V_163 = V_28 -> V_49 -> V_165 ;
F_92 ( V_161 , V_28 -> V_49 , F_86 ,
V_28 -> V_163 ) ;
return 0 ;
}
static int F_93 ( struct V_27 * V_28 ,
struct V_25 * V_161 )
{
struct V_5 * V_6 = V_28 -> V_22 ;
struct V_166 * V_167 = V_6 -> V_20 ;
struct V_168 * V_169 , * V_170 ;
bool V_171 = false ;
T_5 V_172 = 0 ;
int V_173 , V_71 ;
V_170 = V_167 -> V_170 [ V_28 -> V_48 ] ;
V_173 = F_94 ( V_170 ) ;
if ( V_173 < 0 )
V_173 = V_164 ;
V_28 -> V_163 = V_173 ;
V_169 = F_95 ( V_170 , L_11 , 0 ) ;
if ( F_96 ( V_170 ) ) {
V_71 = F_97 ( V_170 ) ;
if ( V_71 ) {
F_91 ( V_161 , L_12 , V_71 ) ;
return V_71 ;
}
V_171 = true ;
V_169 = V_170 ;
}
if ( V_6 -> V_9 -> V_174 )
V_172 = V_6 -> V_9 -> V_174 ( V_6 , V_28 -> V_48 ) ;
if ( V_169 ) {
int V_175 = F_98 ( & V_161 -> V_26 , V_169 ) ;
if ( ! V_171 && V_175 >= 0 &&
( V_6 -> V_8 & ( 1 << V_175 ) ) ) {
V_71 = F_89 ( V_28 , V_161 , V_175 ) ;
if ( V_71 ) {
F_91 ( V_161 , L_13 , V_175 , V_71 ) ;
return V_71 ;
}
} else {
V_28 -> V_49 = F_99 ( V_161 , V_169 ,
F_86 ,
V_172 ,
V_28 -> V_163 ) ;
}
}
if ( V_28 -> V_49 && V_171 )
F_100 ( V_28 -> V_49 , F_88 ) ;
if ( ! V_28 -> V_49 ) {
V_71 = F_89 ( V_28 , V_161 , V_28 -> V_48 ) ;
if ( V_71 ) {
F_91 ( V_161 , L_14 , V_28 -> V_48 , V_71 ) ;
return V_71 ;
}
}
F_101 ( V_28 -> V_49 ) ;
return 0 ;
}
static void F_102 ( struct V_25 * V_26 ,
struct V_176 * V_177 ,
void * V_178 )
{
F_103 ( & V_177 -> V_179 ,
& V_180 ) ;
}
int F_104 ( struct V_25 * V_161 )
{
struct V_27 * V_28 = F_5 ( V_161 ) ;
if ( V_28 -> V_49 ) {
F_15 ( V_28 -> V_49 ) ;
V_28 -> V_155 = - 1 ;
V_28 -> V_152 = - 1 ;
V_28 -> V_153 = - 1 ;
F_105 ( V_28 -> V_49 ) ;
}
return 0 ;
}
int F_106 ( struct V_25 * V_161 )
{
struct V_27 * V_28 = F_5 ( V_161 ) ;
F_107 ( V_161 ) ;
if ( V_28 -> V_49 ) {
F_108 ( V_28 -> V_49 ) ;
F_12 ( V_28 -> V_49 ) ;
}
return 0 ;
}
int F_109 ( struct V_5 * V_6 , struct V_181 * V_22 ,
int V_48 , char * V_14 )
{
struct V_25 * V_33 = V_6 -> V_29 -> V_30 ;
struct V_25 * V_161 ;
struct V_27 * V_28 ;
int V_71 ;
V_161 = F_110 ( sizeof( struct V_27 ) , V_14 ,
V_182 , V_183 ) ;
if ( V_161 == NULL )
return - V_150 ;
V_161 -> V_184 = V_33 -> V_185 ;
V_161 -> V_186 = & V_187 ;
F_111 ( V_161 , V_33 ) ;
V_161 -> V_188 |= V_189 ;
V_161 -> V_190 = & V_191 ;
V_161 -> V_192 = & V_193 ;
F_112 ( V_161 , & V_194 ) ;
F_113 ( V_161 , F_102 ,
NULL ) ;
F_114 ( V_161 , V_22 ) ;
V_161 -> V_26 . V_195 = V_6 -> V_20 -> V_170 [ V_48 ] ;
V_161 -> V_185 = V_33 -> V_185 ;
V_28 = F_5 ( V_161 ) ;
V_28 -> V_26 = V_161 ;
V_28 -> V_22 = V_6 ;
V_28 -> V_48 = V_48 ;
switch ( V_6 -> V_29 -> V_196 ) {
#ifdef F_115
case V_197 :
V_28 -> V_106 = V_198 . V_106 ;
break;
#endif
#ifdef F_116
case V_199 :
V_28 -> V_106 = V_200 . V_106 ;
break;
#endif
#ifdef F_117
case V_201 :
V_28 -> V_106 = V_202 . V_106 ;
break;
#endif
#ifdef F_118
case V_203 :
V_28 -> V_106 = V_204 . V_106 ;
break;
#endif
default:
V_28 -> V_106 = F_53 ;
break;
}
V_28 -> V_155 = - 1 ;
V_28 -> V_152 = - 1 ;
V_28 -> V_153 = - 1 ;
V_6 -> V_205 [ V_48 ] = V_161 ;
V_71 = F_119 ( V_161 ) ;
if ( V_71 ) {
F_91 ( V_33 , L_15 ,
V_71 , V_161 -> V_14 ) ;
V_6 -> V_205 [ V_48 ] = NULL ;
F_120 ( V_161 ) ;
return V_71 ;
}
F_121 ( V_161 ) ;
V_71 = F_93 ( V_28 , V_161 ) ;
if ( V_71 ) {
F_91 ( V_33 , L_16 , V_71 ) ;
F_122 ( V_161 ) ;
F_120 ( V_161 ) ;
return V_71 ;
}
return 0 ;
}
void F_123 ( struct V_25 * V_161 )
{
struct V_27 * V_28 = F_5 ( V_161 ) ;
F_121 ( V_161 ) ;
if ( V_28 -> V_49 )
F_124 ( V_28 -> V_49 ) ;
F_122 ( V_161 ) ;
F_120 ( V_161 ) ;
}
static bool F_125 ( struct V_25 * V_26 )
{
return V_26 -> V_190 == & V_191 ;
}
static int F_126 ( struct V_25 * V_26 ,
unsigned long V_206 , void * V_207 )
{
struct V_208 * V_209 = V_207 ;
struct V_25 * V_210 = V_209 -> V_211 ;
int V_37 = 0 ;
switch ( V_206 ) {
case V_212 :
if ( F_127 ( V_210 ) ) {
if ( V_209 -> V_213 )
V_37 = F_42 ( V_26 , V_210 ) ;
else
F_43 ( V_26 ) ;
}
break;
}
return F_128 ( V_37 ) ;
}
static int F_129 ( struct V_25 * V_26 , unsigned long V_206 ,
void * V_207 )
{
switch ( V_206 ) {
case V_212 :
return F_126 ( V_26 , V_206 , V_207 ) ;
}
return V_214 ;
}
int F_130 ( struct V_215 * V_216 ,
unsigned long V_206 , void * V_207 )
{
struct V_25 * V_26 = F_131 ( V_207 ) ;
if ( F_125 ( V_26 ) )
return F_129 ( V_26 , V_206 , V_207 ) ;
return V_214 ;
}
