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
static int F_25 ( struct V_5 * V_6 ,
const struct V_25 * V_59 ,
T_1 V_60 , T_1 V_61 )
{
struct V_27 * V_28 ;
struct V_25 * V_26 , * V_62 ;
F_26 ( V_63 , V_64 ) ;
F_26 ( V_65 , V_64 ) ;
T_1 V_66 ;
int V_67 , V_37 ;
if ( ! V_6 -> V_9 -> V_68 || ! V_60 )
return - V_69 ;
V_66 = V_60 - 1 ;
do {
V_37 = V_6 -> V_9 -> V_68 ( V_6 , & V_66 , V_63 , V_65 ) ;
if ( V_37 )
break;
if ( V_66 > V_61 )
break;
V_67 = F_27 ( V_63 , V_64 ) ;
if ( V_67 == V_64 )
continue;
V_26 = V_6 -> V_70 [ V_67 ] ;
V_28 = F_5 ( V_26 ) ;
V_62 = V_28 -> V_32 ;
if ( V_62 == V_59 )
continue;
F_28 ( V_62 , L_3 , V_66 ) ;
return - V_69 ;
} while ( V_66 < V_61 );
return V_37 == - V_71 ? 0 : V_37 ;
}
static int F_29 ( struct V_25 * V_26 ,
const struct V_72 * V_73 ,
struct V_74 * V_75 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_37 ;
if ( F_30 ( V_75 ) ) {
if ( ! V_6 -> V_9 -> V_76 || ! V_6 -> V_9 -> V_77 )
return - V_69 ;
V_37 = F_25 ( V_6 , V_28 -> V_32 ,
V_73 -> V_60 ,
V_73 -> V_61 ) ;
if ( V_37 )
return V_37 ;
V_37 = V_6 -> V_9 -> V_76 ( V_6 , V_28 -> V_48 , V_73 , V_75 ) ;
if ( V_37 )
return V_37 ;
} else {
V_37 = V_6 -> V_9 -> V_77 ( V_6 , V_28 -> V_48 , V_73 , V_75 ) ;
if ( V_37 )
return V_37 ;
}
return 0 ;
}
static int F_31 ( struct V_25 * V_26 ,
const struct V_72 * V_73 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( ! V_6 -> V_9 -> V_78 )
return - V_69 ;
return V_6 -> V_9 -> V_78 ( V_6 , V_28 -> V_48 , V_73 ) ;
}
static int F_32 ( struct V_25 * V_26 ,
struct V_72 * V_73 ,
T_3 * V_79 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
F_26 ( V_63 , V_64 ) ;
F_26 ( V_65 , V_64 ) ;
T_1 V_80 , V_66 = 0 ;
int V_37 ;
if ( ! V_6 -> V_9 -> V_68 || ! V_6 -> V_9 -> V_81 )
return - V_69 ;
V_37 = V_6 -> V_9 -> V_81 ( V_6 , V_28 -> V_48 , & V_80 ) ;
if ( V_37 )
return V_37 ;
for (; ; ) {
V_37 = V_6 -> V_9 -> V_68 ( V_6 , & V_66 , V_63 , V_65 ) ;
if ( V_37 )
break;
if ( ! F_33 ( V_28 -> V_48 , V_63 ) )
continue;
memset ( V_73 , 0 , sizeof( * V_73 ) ) ;
V_73 -> V_60 = V_73 -> V_61 = V_66 ;
if ( V_66 == V_80 )
V_73 -> V_38 |= V_82 ;
if ( F_33 ( V_28 -> V_48 , V_65 ) )
V_73 -> V_38 |= V_83 ;
V_37 = V_79 ( & V_73 -> V_84 ) ;
if ( V_37 )
break;
}
return V_37 == - V_71 ? 0 : V_37 ;
}
static int F_34 ( struct V_25 * V_26 ,
const struct V_85 * V_86 ,
struct V_74 * V_75 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_87 ;
if ( ! V_6 -> V_9 -> V_88 || ! V_6 -> V_9 -> V_89 )
return - V_69 ;
if ( F_30 ( V_75 ) )
V_87 = V_6 -> V_9 -> V_88 ( V_6 , V_28 -> V_48 , V_86 , V_75 ) ;
else
V_87 = V_6 -> V_9 -> V_89 ( V_6 , V_28 -> V_48 , V_86 , V_75 ) ;
return V_87 ;
}
static int F_35 ( struct V_25 * V_26 ,
const struct V_85 * V_86 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_87 = - V_69 ;
if ( V_6 -> V_9 -> V_90 )
V_87 = V_6 -> V_9 -> V_90 ( V_6 , V_28 -> V_48 , V_86 ) ;
return V_87 ;
}
static int F_36 ( struct V_25 * V_26 ,
struct V_85 * V_86 ,
T_3 * V_79 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_91 )
return V_6 -> V_9 -> V_91 ( V_6 , V_28 -> V_48 , V_86 , V_79 ) ;
return - V_69 ;
}
static int F_37 ( struct V_25 * V_26 , struct V_92 * V_93 , int V_94 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
if ( V_28 -> V_49 != NULL )
return F_38 ( V_28 -> V_49 , V_93 , V_94 ) ;
return - V_69 ;
}
static T_4 F_39 ( struct V_5 * V_6 ,
struct V_25 * V_59 )
{
struct V_27 * V_28 ;
unsigned int V_48 ;
T_4 V_95 = 0 ;
for ( V_48 = 0 ; V_48 < V_64 ; V_48 ++ ) {
if ( ! F_40 ( V_6 , V_48 ) )
continue;
V_28 = F_5 ( V_6 -> V_70 [ V_48 ] ) ;
if ( V_6 -> V_70 [ V_48 ] -> V_96 & V_97 &&
V_28 -> V_32 == V_59 )
V_95 |= 1 << V_48 ;
}
return V_95 ;
}
static int F_41 ( struct V_25 * V_26 , T_2 V_98 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_87 = - V_69 ;
if ( V_6 -> V_9 -> V_51 )
V_87 = V_6 -> V_9 -> V_51 ( V_6 , V_28 -> V_48 , V_98 ) ;
return V_87 ;
}
static int F_42 ( struct V_25 * V_26 ,
const struct V_99 * V_100 ,
struct V_74 * V_75 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_87 ;
switch ( V_100 -> V_17 ) {
case V_101 :
if ( F_30 ( V_75 ) )
V_87 = V_6 -> V_9 -> V_51 ? 0 : - V_69 ;
else
V_87 = V_6 -> V_9 -> V_51 ( V_6 , V_28 -> V_48 ,
V_100 -> V_102 . V_34 ) ;
break;
default:
V_87 = - V_69 ;
break;
}
return V_87 ;
}
static int F_43 ( struct V_25 * V_26 ,
const struct V_103 * V_84 ,
struct V_74 * V_75 )
{
int V_37 ;
switch ( V_84 -> V_17 ) {
case V_104 :
V_37 = F_34 ( V_26 ,
F_44 ( V_84 ) ,
V_75 ) ;
break;
case V_105 :
V_37 = F_29 ( V_26 ,
F_45 ( V_84 ) ,
V_75 ) ;
break;
default:
V_37 = - V_69 ;
break;
}
return V_37 ;
}
static int F_46 ( struct V_25 * V_26 ,
const struct V_103 * V_84 )
{
int V_37 ;
switch ( V_84 -> V_17 ) {
case V_104 :
V_37 = F_35 ( V_26 ,
F_44 ( V_84 ) ) ;
break;
case V_105 :
V_37 = F_31 ( V_26 ,
F_45 ( V_84 ) ) ;
break;
default:
V_37 = - V_69 ;
break;
}
return V_37 ;
}
static int F_47 ( struct V_25 * V_26 ,
struct V_103 * V_84 ,
T_3 * V_79 )
{
int V_37 ;
switch ( V_84 -> V_17 ) {
case V_104 :
V_37 = F_36 ( V_26 ,
F_44 ( V_84 ) ,
V_79 ) ;
break;
case V_105 :
V_37 = F_32 ( V_26 ,
F_45 ( V_84 ) ,
V_79 ) ;
break;
default:
V_37 = - V_69 ;
break;
}
return V_37 ;
}
static int F_48 ( struct V_25 * V_26 ,
struct V_25 * V_106 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_87 = - V_69 ;
V_28 -> V_32 = V_106 ;
if ( V_6 -> V_9 -> V_107 )
V_87 = V_6 -> V_9 -> V_107 ( V_6 , V_28 -> V_48 ,
F_39 ( V_6 , V_106 ) ) ;
return V_87 ;
}
static int F_49 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_87 = - V_69 ;
if ( V_6 -> V_9 -> V_108 )
V_87 = V_6 -> V_9 -> V_108 ( V_6 , V_28 -> V_48 ,
F_39 ( V_6 , V_28 -> V_32 ) ) ;
V_28 -> V_32 = NULL ;
F_41 ( V_26 , V_36 ) ;
return V_87 ;
}
static int F_50 ( struct V_25 * V_26 ,
struct V_99 * V_100 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
switch ( V_100 -> V_17 ) {
case V_109 :
V_100 -> V_102 . V_110 . V_111 = sizeof( V_6 -> V_19 ) ;
memcpy ( & V_100 -> V_102 . V_110 . V_17 , & V_6 -> V_19 , V_100 -> V_102 . V_110 . V_111 ) ;
break;
default:
return - V_69 ;
}
return 0 ;
}
static inline T_5 F_51 ( struct V_27 * V_28 ,
struct V_112 * V_113 )
{
#ifdef F_52
if ( V_28 -> V_114 )
F_53 ( V_28 -> V_114 , V_113 ) ;
#else
F_54 () ;
#endif
return V_115 ;
}
static T_5 F_55 ( struct V_112 * V_113 , struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_112 * V_116 ;
V_26 -> V_117 . V_118 ++ ;
V_26 -> V_117 . V_119 += V_113 -> V_120 ;
V_116 = V_28 -> V_121 ( V_113 , V_26 ) ;
if ( ! V_116 )
return V_115 ;
if ( F_56 ( F_57 ( V_26 ) ) )
return F_51 ( V_28 , V_116 ) ;
V_116 -> V_26 = V_28 -> V_22 -> V_29 -> V_30 ;
F_58 ( V_116 ) ;
return V_115 ;
}
static struct V_112 * F_59 ( struct V_112 * V_113 ,
struct V_25 * V_26 )
{
return V_113 ;
}
static int
F_60 ( struct V_25 * V_26 , struct V_122 * V_94 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
int V_37 ;
V_37 = - V_69 ;
if ( V_28 -> V_49 != NULL ) {
V_37 = F_61 ( V_28 -> V_49 ) ;
if ( V_37 == 0 )
V_37 = F_62 ( V_28 -> V_49 , V_94 ) ;
}
return V_37 ;
}
static int
F_63 ( struct V_25 * V_26 , struct V_122 * V_94 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
if ( V_28 -> V_49 != NULL )
return F_64 ( V_28 -> V_49 , V_94 ) ;
return - V_69 ;
}
static void F_65 ( struct V_25 * V_26 ,
struct V_123 * V_124 )
{
F_66 ( V_124 -> V_125 , L_4 , sizeof( V_124 -> V_125 ) ) ;
F_66 ( V_124 -> V_126 , V_127 , sizeof( V_124 -> V_126 ) ) ;
F_66 ( V_124 -> V_128 , L_5 , sizeof( V_124 -> V_128 ) ) ;
F_66 ( V_124 -> V_129 , L_6 , sizeof( V_124 -> V_129 ) ) ;
}
static int F_67 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_130 )
return V_6 -> V_9 -> V_130 ( V_6 , V_28 -> V_48 ) ;
return - V_69 ;
}
static void
F_68 ( struct V_25 * V_26 , struct V_131 * V_132 , void * V_133 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_134 )
V_6 -> V_9 -> V_134 ( V_6 , V_28 -> V_48 , V_132 , V_133 ) ;
}
static int F_69 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
if ( V_28 -> V_49 != NULL )
return F_70 ( V_28 -> V_49 ) ;
return - V_69 ;
}
static T_4 F_71 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
if ( V_28 -> V_49 != NULL ) {
F_72 ( V_28 -> V_49 ) ;
return V_28 -> V_49 -> V_135 ;
}
return - V_69 ;
}
static int F_73 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_20 -> V_136 )
return V_6 -> V_20 -> V_136 ;
if ( V_6 -> V_9 -> V_137 )
return V_6 -> V_9 -> V_137 ( V_6 ) ;
return 0 ;
}
static int F_74 ( struct V_25 * V_26 ,
struct V_138 * V_139 , T_2 * V_140 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_141 )
return V_6 -> V_9 -> V_141 ( V_6 , V_139 , V_140 ) ;
return - V_69 ;
}
static int F_75 ( struct V_25 * V_26 ,
struct V_138 * V_139 , T_2 * V_140 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_142 )
return V_6 -> V_9 -> V_142 ( V_6 , V_139 , V_140 ) ;
return - V_69 ;
}
static void F_76 ( struct V_25 * V_26 ,
T_6 V_143 , T_7 * V_140 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_143 == V_144 ) {
int V_120 = V_145 ;
strncpy ( V_140 , L_7 , V_120 ) ;
strncpy ( V_140 + V_120 , L_8 , V_120 ) ;
strncpy ( V_140 + 2 * V_120 , L_9 , V_120 ) ;
strncpy ( V_140 + 3 * V_120 , L_10 , V_120 ) ;
if ( V_6 -> V_9 -> V_146 != NULL )
V_6 -> V_9 -> V_146 ( V_6 , V_28 -> V_48 , V_140 + 4 * V_120 ) ;
}
}
static void F_77 ( struct V_25 * V_26 ,
struct V_147 * V_117 ,
T_8 * V_140 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
V_140 [ 0 ] = V_28 -> V_26 -> V_117 . V_118 ;
V_140 [ 1 ] = V_28 -> V_26 -> V_117 . V_119 ;
V_140 [ 2 ] = V_28 -> V_26 -> V_117 . V_148 ;
V_140 [ 3 ] = V_28 -> V_26 -> V_117 . V_149 ;
if ( V_6 -> V_9 -> V_150 != NULL )
V_6 -> V_9 -> V_150 ( V_6 , V_28 -> V_48 , V_140 + 4 ) ;
}
static int F_78 ( struct V_25 * V_26 , int V_151 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_151 == V_144 ) {
int V_152 ;
V_152 = 4 ;
if ( V_6 -> V_9 -> V_153 != NULL )
V_152 += V_6 -> V_9 -> V_153 ( V_6 ) ;
return V_152 ;
}
return - V_69 ;
}
static void F_79 ( struct V_25 * V_26 , struct V_154 * V_155 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_156 )
V_6 -> V_9 -> V_156 ( V_6 , V_28 -> V_48 , V_155 ) ;
}
static int F_80 ( struct V_25 * V_26 , struct V_154 * V_155 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_87 = - V_69 ;
if ( V_6 -> V_9 -> V_157 )
V_87 = V_6 -> V_9 -> V_157 ( V_6 , V_28 -> V_48 , V_155 ) ;
return V_87 ;
}
static int F_81 ( struct V_25 * V_26 , struct V_158 * V_159 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_87 ;
if ( ! V_6 -> V_9 -> V_160 )
return - V_69 ;
V_87 = V_6 -> V_9 -> V_160 ( V_6 , V_28 -> V_48 , V_28 -> V_49 , V_159 ) ;
if ( V_87 )
return V_87 ;
if ( V_28 -> V_49 )
V_87 = F_82 ( V_28 -> V_49 , V_159 ) ;
return V_87 ;
}
static int F_83 ( struct V_25 * V_26 , struct V_158 * V_159 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_87 ;
if ( ! V_6 -> V_9 -> V_161 )
return - V_69 ;
V_87 = V_6 -> V_9 -> V_161 ( V_6 , V_28 -> V_48 , V_159 ) ;
if ( V_87 )
return V_87 ;
if ( V_28 -> V_49 )
V_87 = F_84 ( V_28 -> V_49 , V_159 ) ;
return V_87 ;
}
static int F_85 ( struct V_25 * V_26 ,
struct V_162 * V_163 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
struct V_25 * V_33 = V_6 -> V_29 -> V_30 ;
struct V_114 * V_114 ;
int V_37 = 0 ;
V_114 = F_86 ( sizeof( * V_114 ) , V_164 ) ;
if ( ! V_114 )
return - V_165 ;
V_37 = F_87 ( V_114 , V_33 ) ;
if ( V_37 ) {
F_88 ( V_114 ) ;
goto V_42;
}
V_28 -> V_114 = V_114 ;
V_42:
return V_37 ;
}
static void F_89 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_114 * V_114 = V_28 -> V_114 ;
if ( ! V_114 )
return;
V_28 -> V_114 = NULL ;
F_90 ( V_114 ) ;
}
static void F_91 ( struct V_25 * V_26 )
{
}
static void F_92 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
unsigned int V_166 = 0 ;
if ( V_28 -> V_167 != V_28 -> V_49 -> V_135 ) {
V_166 = 1 ;
V_28 -> V_167 = V_28 -> V_49 -> V_135 ;
}
if ( V_28 -> V_168 != V_28 -> V_49 -> V_169 ) {
V_166 = 1 ;
V_28 -> V_168 = V_28 -> V_49 -> V_169 ;
}
if ( V_28 -> V_170 != V_28 -> V_49 -> V_171 ) {
V_166 = 1 ;
V_28 -> V_170 = V_28 -> V_49 -> V_171 ;
}
if ( V_6 -> V_9 -> V_172 && V_166 )
V_6 -> V_9 -> V_172 ( V_6 , V_28 -> V_48 , V_28 -> V_49 ) ;
if ( V_166 )
F_93 ( V_28 -> V_49 ) ;
}
static int F_94 ( struct V_25 * V_26 ,
struct V_173 * V_174 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_175 )
V_6 -> V_9 -> V_175 ( V_6 , V_28 -> V_48 , V_174 ) ;
return 0 ;
}
static int F_95 ( struct V_27 * V_28 ,
struct V_25 * V_176 ,
int V_3 )
{
struct V_5 * V_6 = V_28 -> V_22 ;
V_28 -> V_49 = F_96 ( V_6 -> V_13 , V_3 ) ;
if ( ! V_28 -> V_49 ) {
F_97 ( V_176 , L_11 , V_3 ) ;
return - V_177 ;
}
if ( V_28 -> V_178 == V_179 )
V_28 -> V_178 = V_28 -> V_49 -> V_180 ;
F_98 ( V_176 , V_28 -> V_49 , F_92 ,
V_28 -> V_178 ) ;
return 0 ;
}
static int F_99 ( struct V_27 * V_28 ,
struct V_25 * V_176 )
{
struct V_5 * V_6 = V_28 -> V_22 ;
struct V_181 * V_182 = V_6 -> V_20 ;
struct V_183 * V_184 , * V_185 ;
bool V_186 = false ;
T_4 V_187 = 0 ;
int V_188 , V_87 ;
V_185 = V_182 -> V_185 [ V_28 -> V_48 ] ;
V_188 = F_100 ( V_185 ) ;
if ( V_188 < 0 )
V_188 = V_179 ;
V_28 -> V_178 = V_188 ;
V_184 = F_101 ( V_185 , L_12 , 0 ) ;
if ( F_102 ( V_185 ) ) {
V_87 = F_103 ( V_185 ) ;
if ( V_87 ) {
F_97 ( V_176 , L_13 , V_87 ) ;
return V_87 ;
}
V_186 = true ;
V_184 = V_185 ;
}
if ( V_6 -> V_9 -> V_189 )
V_187 = V_6 -> V_9 -> V_189 ( V_6 , V_28 -> V_48 ) ;
if ( V_184 ) {
int V_190 = F_104 ( & V_176 -> V_26 , V_184 ) ;
if ( ! V_186 && V_190 >= 0 &&
( V_6 -> V_8 & ( 1 << V_190 ) ) ) {
V_87 = F_95 ( V_28 , V_176 , V_190 ) ;
if ( V_87 ) {
F_97 ( V_176 , L_14 , V_190 , V_87 ) ;
return V_87 ;
}
} else {
V_28 -> V_49 = F_105 ( V_176 , V_184 ,
F_92 ,
V_187 ,
V_28 -> V_178 ) ;
}
}
if ( V_28 -> V_49 && V_186 )
F_106 ( V_28 -> V_49 , F_94 ) ;
if ( ! V_28 -> V_49 ) {
V_87 = F_95 ( V_28 , V_176 , V_28 -> V_48 ) ;
if ( V_87 ) {
F_97 ( V_176 , L_15 , V_28 -> V_48 , V_87 ) ;
return V_87 ;
}
}
F_107 ( V_28 -> V_49 ) ;
return 0 ;
}
static void F_108 ( struct V_25 * V_26 ,
struct V_191 * V_192 ,
void * V_193 )
{
F_109 ( & V_192 -> V_194 ,
& V_195 ) ;
}
int F_110 ( struct V_25 * V_176 )
{
struct V_27 * V_28 = F_5 ( V_176 ) ;
if ( V_28 -> V_49 ) {
F_15 ( V_28 -> V_49 ) ;
V_28 -> V_170 = - 1 ;
V_28 -> V_167 = - 1 ;
V_28 -> V_168 = - 1 ;
F_111 ( V_28 -> V_49 ) ;
}
return 0 ;
}
int F_112 ( struct V_25 * V_176 )
{
struct V_27 * V_28 = F_5 ( V_176 ) ;
F_113 ( V_176 ) ;
if ( V_28 -> V_49 ) {
F_114 ( V_28 -> V_49 ) ;
F_12 ( V_28 -> V_49 ) ;
}
return 0 ;
}
int F_115 ( struct V_5 * V_6 , struct V_196 * V_22 ,
int V_48 , char * V_14 )
{
struct V_25 * V_33 = V_6 -> V_29 -> V_30 ;
struct V_25 * V_176 ;
struct V_27 * V_28 ;
int V_87 ;
V_176 = F_116 ( sizeof( struct V_27 ) , V_14 ,
V_197 , V_198 ) ;
if ( V_176 == NULL )
return - V_165 ;
V_176 -> V_199 = V_33 -> V_200 ;
V_176 -> V_201 = & V_202 ;
F_117 ( V_176 , V_33 ) ;
V_176 -> V_96 |= V_203 ;
V_176 -> V_204 = & V_205 ;
V_176 -> V_206 = & V_207 ;
F_118 ( V_176 , & V_208 ) ;
F_119 ( V_176 , F_108 ,
NULL ) ;
F_120 ( V_176 , V_22 ) ;
V_176 -> V_26 . V_209 = V_6 -> V_20 -> V_185 [ V_48 ] ;
V_176 -> V_200 = V_33 -> V_200 ;
V_28 = F_5 ( V_176 ) ;
V_28 -> V_26 = V_176 ;
V_28 -> V_22 = V_6 ;
V_28 -> V_48 = V_48 ;
switch ( V_6 -> V_29 -> V_210 ) {
#ifdef F_121
case V_211 :
V_28 -> V_121 = V_212 . V_121 ;
break;
#endif
#ifdef F_122
case V_213 :
V_28 -> V_121 = V_214 . V_121 ;
break;
#endif
#ifdef F_123
case V_215 :
V_28 -> V_121 = V_216 . V_121 ;
break;
#endif
#ifdef F_124
case V_217 :
V_28 -> V_121 = V_218 . V_121 ;
break;
#endif
default:
V_28 -> V_121 = F_59 ;
break;
}
V_28 -> V_170 = - 1 ;
V_28 -> V_167 = - 1 ;
V_28 -> V_168 = - 1 ;
V_6 -> V_70 [ V_48 ] = V_176 ;
V_87 = F_125 ( V_176 ) ;
if ( V_87 ) {
F_97 ( V_33 , L_16 ,
V_87 , V_176 -> V_14 ) ;
V_6 -> V_70 [ V_48 ] = NULL ;
F_126 ( V_176 ) ;
return V_87 ;
}
F_127 ( V_176 ) ;
V_87 = F_99 ( V_28 , V_176 ) ;
if ( V_87 ) {
F_97 ( V_33 , L_17 , V_87 ) ;
F_128 ( V_176 ) ;
F_126 ( V_176 ) ;
return V_87 ;
}
return 0 ;
}
void F_129 ( struct V_25 * V_176 )
{
struct V_27 * V_28 = F_5 ( V_176 ) ;
F_127 ( V_176 ) ;
if ( V_28 -> V_49 )
F_130 ( V_28 -> V_49 ) ;
F_128 ( V_176 ) ;
F_126 ( V_176 ) ;
}
static bool F_131 ( struct V_25 * V_26 )
{
return V_26 -> V_204 == & V_205 ;
}
static int F_132 ( struct V_25 * V_26 )
{
struct V_25 * V_33 = F_133 ( V_26 ) ;
struct V_27 * V_28 = F_5 ( V_26 ) ;
int V_37 = 0 ;
if ( V_33 && V_33 -> V_219 &&
! strcmp ( V_33 -> V_219 -> V_220 , L_18 ) )
V_37 = F_48 ( V_26 , V_33 ) ;
else if ( F_6 ( V_28 ) )
V_37 = F_49 ( V_26 ) ;
return V_37 ;
}
int F_134 ( struct V_221 * V_222 ,
unsigned long V_223 , void * V_224 )
{
struct V_25 * V_26 ;
int V_37 = 0 ;
switch ( V_223 ) {
case V_225 :
V_26 = F_135 ( V_224 ) ;
if ( ! F_131 ( V_26 ) )
goto V_42;
V_37 = F_132 ( V_26 ) ;
if ( V_37 && V_37 != - V_69 )
F_136 ( V_26 , L_19 ) ;
break;
}
V_42:
return V_226 ;
}
