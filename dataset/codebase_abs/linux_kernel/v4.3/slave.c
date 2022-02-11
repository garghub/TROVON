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
struct V_72 * V_73 )
{
struct V_74 * V_75 = & V_73 -> V_76 . V_75 ;
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
T_1 V_66 ;
int V_37 ;
switch ( V_73 -> V_77 ) {
case V_78 :
if ( ! V_6 -> V_9 -> V_79 || ! V_6 -> V_9 -> V_80 )
return - V_69 ;
V_37 = F_25 ( V_6 , V_28 -> V_32 ,
V_75 -> V_60 ,
V_75 -> V_61 ) ;
if ( V_37 )
return V_37 ;
break;
case V_81 :
for ( V_66 = V_75 -> V_60 ; V_66 <= V_75 -> V_61 ; ++ V_66 ) {
V_37 = V_6 -> V_9 -> V_79 ( V_6 , V_28 -> V_48 , V_66 ,
V_75 -> V_38 &
V_82 ) ;
if ( ! V_37 && V_75 -> V_38 & V_83 )
V_37 = V_6 -> V_9 -> V_80 ( V_6 , V_28 -> V_48 , V_66 ) ;
if ( V_37 )
return V_37 ;
}
break;
default:
return - V_69 ;
}
return 0 ;
}
static int F_30 ( struct V_25 * V_26 ,
struct V_72 * V_73 )
{
struct V_74 * V_75 = & V_73 -> V_76 . V_75 ;
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
T_1 V_66 ;
int V_37 ;
if ( ! V_6 -> V_9 -> V_84 )
return - V_69 ;
for ( V_66 = V_75 -> V_60 ; V_66 <= V_75 -> V_61 ; ++ V_66 ) {
V_37 = V_6 -> V_9 -> V_84 ( V_6 , V_28 -> V_48 , V_66 ) ;
if ( V_37 )
return V_37 ;
}
return 0 ;
}
static int F_31 ( struct V_25 * V_26 ,
struct V_72 * V_73 )
{
struct V_74 * V_75 = & V_73 -> V_76 . V_75 ;
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
F_26 ( V_63 , V_64 ) ;
F_26 ( V_65 , V_64 ) ;
T_1 V_85 , V_66 = 0 ;
int V_37 ;
if ( ! V_6 -> V_9 -> V_68 || ! V_6 -> V_9 -> V_86 )
return - V_69 ;
V_37 = V_6 -> V_9 -> V_86 ( V_6 , V_28 -> V_48 , & V_85 ) ;
if ( V_37 )
return V_37 ;
for (; ; ) {
V_37 = V_6 -> V_9 -> V_68 ( V_6 , & V_66 , V_63 , V_65 ) ;
if ( V_37 )
break;
if ( ! F_32 ( V_28 -> V_48 , V_63 ) )
continue;
memset ( V_75 , 0 , sizeof( * V_75 ) ) ;
V_75 -> V_60 = V_75 -> V_61 = V_66 ;
if ( V_66 == V_85 )
V_75 -> V_38 |= V_83 ;
if ( F_32 ( V_28 -> V_48 , V_65 ) )
V_75 -> V_38 |= V_82 ;
V_37 = V_73 -> V_87 ( V_26 , V_73 ) ;
if ( V_37 )
break;
}
return V_37 == - V_71 ? 0 : V_37 ;
}
static int F_33 ( struct V_25 * V_26 ,
struct V_72 * V_73 )
{
struct V_88 * V_89 = & V_73 -> V_76 . V_89 ;
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_90 = - V_69 ;
if ( V_73 -> V_77 == V_78 )
V_90 = V_6 -> V_9 -> V_91 ? 0 : - V_69 ;
else if ( V_73 -> V_77 == V_81 )
V_90 = V_6 -> V_9 -> V_91 ( V_6 , V_28 -> V_48 , V_89 -> V_3 , V_89 -> V_66 ) ;
return V_90 ;
}
static int F_34 ( struct V_25 * V_26 ,
struct V_72 * V_73 )
{
struct V_88 * V_89 = & V_73 -> V_76 . V_89 ;
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_90 = - V_69 ;
if ( V_6 -> V_9 -> V_92 )
V_90 = V_6 -> V_9 -> V_92 ( V_6 , V_28 -> V_48 , V_89 -> V_3 , V_89 -> V_66 ) ;
return V_90 ;
}
static int F_35 ( struct V_25 * V_26 ,
struct V_72 * V_73 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
unsigned char V_3 [ V_93 ] = { 0 } ;
T_1 V_66 = 0 ;
int V_90 ;
if ( ! V_6 -> V_9 -> V_94 )
return - V_69 ;
for (; ; ) {
bool V_95 ;
V_90 = V_6 -> V_9 -> V_94 ( V_6 , V_28 -> V_48 , V_3 , & V_66 ,
& V_95 ) ;
if ( V_90 < 0 )
break;
V_73 -> V_76 . V_89 . V_3 = V_3 ;
V_73 -> V_76 . V_89 . V_66 = V_66 ;
V_73 -> V_76 . V_89 . V_96 = V_95 ? V_97 : V_98 ;
V_90 = V_73 -> V_87 ( V_26 , V_73 ) ;
if ( V_90 < 0 )
break;
}
return V_90 == - V_71 ? 0 : V_90 ;
}
static int F_36 ( struct V_25 * V_26 , struct V_99 * V_100 , int V_101 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
if ( V_28 -> V_49 != NULL )
return F_37 ( V_28 -> V_49 , V_100 , V_101 ) ;
return - V_69 ;
}
static T_3 F_38 ( struct V_5 * V_6 ,
struct V_25 * V_59 )
{
struct V_27 * V_28 ;
unsigned int V_48 ;
T_3 V_102 = 0 ;
for ( V_48 = 0 ; V_48 < V_64 ; V_48 ++ ) {
if ( ! F_39 ( V_6 , V_48 ) )
continue;
V_28 = F_5 ( V_6 -> V_70 [ V_48 ] ) ;
if ( V_6 -> V_70 [ V_48 ] -> V_103 & V_104 &&
V_28 -> V_32 == V_59 )
V_102 |= 1 << V_48 ;
}
return V_102 ;
}
static int F_40 ( struct V_25 * V_26 , T_2 V_105 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_90 = - V_69 ;
if ( V_6 -> V_9 -> V_51 )
V_90 = V_6 -> V_9 -> V_51 ( V_6 , V_28 -> V_48 , V_105 ) ;
return V_90 ;
}
static int F_41 ( struct V_25 * V_26 ,
struct V_106 * V_107 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_90 ;
switch ( V_107 -> V_17 ) {
case V_108 :
if ( V_107 -> V_77 == V_78 )
V_90 = V_6 -> V_9 -> V_51 ? 0 : - V_69 ;
else
V_90 = V_6 -> V_9 -> V_51 ( V_6 , V_28 -> V_48 ,
V_107 -> V_76 . V_34 ) ;
break;
default:
V_90 = - V_69 ;
break;
}
return V_90 ;
}
static int F_42 ( struct V_25 * V_26 ,
struct V_72 * V_73 )
{
int V_37 ;
switch ( V_73 -> V_17 ) {
case V_109 :
V_37 = F_33 ( V_26 , V_73 ) ;
break;
case V_110 :
V_37 = F_29 ( V_26 , V_73 ) ;
break;
default:
V_37 = - V_69 ;
break;
}
return V_37 ;
}
static int F_43 ( struct V_25 * V_26 ,
struct V_72 * V_73 )
{
int V_37 ;
switch ( V_73 -> V_17 ) {
case V_109 :
V_37 = F_34 ( V_26 , V_73 ) ;
break;
case V_110 :
V_37 = F_30 ( V_26 , V_73 ) ;
break;
default:
V_37 = - V_69 ;
break;
}
return V_37 ;
}
static int F_44 ( struct V_25 * V_26 ,
struct V_72 * V_73 )
{
int V_37 ;
switch ( V_73 -> V_17 ) {
case V_109 :
V_37 = F_35 ( V_26 , V_73 ) ;
break;
case V_110 :
V_37 = F_31 ( V_26 , V_73 ) ;
break;
default:
V_37 = - V_69 ;
break;
}
return V_37 ;
}
static int F_45 ( struct V_25 * V_26 ,
struct V_25 * V_111 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_90 = - V_69 ;
V_28 -> V_32 = V_111 ;
if ( V_6 -> V_9 -> V_112 )
V_90 = V_6 -> V_9 -> V_112 ( V_6 , V_28 -> V_48 ,
F_38 ( V_6 , V_111 ) ) ;
return V_90 ;
}
static int F_46 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_90 = - V_69 ;
if ( V_6 -> V_9 -> V_113 )
V_90 = V_6 -> V_9 -> V_113 ( V_6 , V_28 -> V_48 ,
F_38 ( V_6 , V_28 -> V_32 ) ) ;
V_28 -> V_32 = NULL ;
F_40 ( V_26 , V_36 ) ;
return V_90 ;
}
static int F_47 ( struct V_25 * V_26 ,
struct V_106 * V_107 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
switch ( V_107 -> V_17 ) {
case V_114 :
V_107 -> V_76 . V_115 . V_116 = sizeof( V_6 -> V_19 ) ;
memcpy ( & V_107 -> V_76 . V_115 . V_17 , & V_6 -> V_19 , V_107 -> V_76 . V_115 . V_116 ) ;
break;
default:
return - V_69 ;
}
return 0 ;
}
static inline T_4 F_48 ( struct V_27 * V_28 ,
struct V_117 * V_118 )
{
#ifdef F_49
if ( V_28 -> V_119 )
F_50 ( V_28 -> V_119 , V_118 ) ;
#else
F_51 () ;
#endif
return V_120 ;
}
static T_4 F_52 ( struct V_117 * V_118 , struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_117 * V_121 ;
V_26 -> V_122 . V_123 ++ ;
V_26 -> V_122 . V_124 += V_118 -> V_125 ;
V_121 = V_28 -> V_126 ( V_118 , V_26 ) ;
if ( ! V_121 )
return V_120 ;
if ( F_53 ( F_54 ( V_26 ) ) )
return F_48 ( V_28 , V_121 ) ;
V_121 -> V_26 = V_28 -> V_22 -> V_29 -> V_30 ;
F_55 ( V_121 ) ;
return V_120 ;
}
static struct V_117 * F_56 ( struct V_117 * V_118 ,
struct V_25 * V_26 )
{
return V_118 ;
}
static int
F_57 ( struct V_25 * V_26 , struct V_127 * V_101 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
int V_37 ;
V_37 = - V_69 ;
if ( V_28 -> V_49 != NULL ) {
V_37 = F_58 ( V_28 -> V_49 ) ;
if ( V_37 == 0 )
V_37 = F_59 ( V_28 -> V_49 , V_101 ) ;
}
return V_37 ;
}
static int
F_60 ( struct V_25 * V_26 , struct V_127 * V_101 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
if ( V_28 -> V_49 != NULL )
return F_61 ( V_28 -> V_49 , V_101 ) ;
return - V_69 ;
}
static void F_62 ( struct V_25 * V_26 ,
struct V_128 * V_129 )
{
F_63 ( V_129 -> V_130 , L_4 , sizeof( V_129 -> V_130 ) ) ;
F_63 ( V_129 -> V_131 , V_132 , sizeof( V_129 -> V_131 ) ) ;
F_63 ( V_129 -> V_133 , L_5 , sizeof( V_129 -> V_133 ) ) ;
F_63 ( V_129 -> V_134 , L_6 , sizeof( V_129 -> V_134 ) ) ;
}
static int F_64 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_135 )
return V_6 -> V_9 -> V_135 ( V_6 , V_28 -> V_48 ) ;
return - V_69 ;
}
static void
F_65 ( struct V_25 * V_26 , struct V_136 * V_137 , void * V_138 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_139 )
V_6 -> V_9 -> V_139 ( V_6 , V_28 -> V_48 , V_137 , V_138 ) ;
}
static int F_66 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
if ( V_28 -> V_49 != NULL )
return F_67 ( V_28 -> V_49 ) ;
return - V_69 ;
}
static T_3 F_68 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
if ( V_28 -> V_49 != NULL ) {
F_69 ( V_28 -> V_49 ) ;
return V_28 -> V_49 -> V_140 ;
}
return - V_69 ;
}
static int F_70 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_20 -> V_141 )
return V_6 -> V_20 -> V_141 ;
if ( V_6 -> V_9 -> V_142 )
return V_6 -> V_9 -> V_142 ( V_6 ) ;
return 0 ;
}
static int F_71 ( struct V_25 * V_26 ,
struct V_143 * V_144 , T_2 * V_145 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_146 )
return V_6 -> V_9 -> V_146 ( V_6 , V_144 , V_145 ) ;
return - V_69 ;
}
static int F_72 ( struct V_25 * V_26 ,
struct V_143 * V_144 , T_2 * V_145 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_147 )
return V_6 -> V_9 -> V_147 ( V_6 , V_144 , V_145 ) ;
return - V_69 ;
}
static void F_73 ( struct V_25 * V_26 ,
T_5 V_148 , T_6 * V_145 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_148 == V_149 ) {
int V_125 = V_150 ;
strncpy ( V_145 , L_7 , V_125 ) ;
strncpy ( V_145 + V_125 , L_8 , V_125 ) ;
strncpy ( V_145 + 2 * V_125 , L_9 , V_125 ) ;
strncpy ( V_145 + 3 * V_125 , L_10 , V_125 ) ;
if ( V_6 -> V_9 -> V_151 != NULL )
V_6 -> V_9 -> V_151 ( V_6 , V_28 -> V_48 , V_145 + 4 * V_125 ) ;
}
}
static void F_74 ( struct V_25 * V_26 ,
struct V_152 * V_122 ,
T_7 * V_145 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
V_145 [ 0 ] = V_28 -> V_26 -> V_122 . V_123 ;
V_145 [ 1 ] = V_28 -> V_26 -> V_122 . V_124 ;
V_145 [ 2 ] = V_28 -> V_26 -> V_122 . V_153 ;
V_145 [ 3 ] = V_28 -> V_26 -> V_122 . V_154 ;
if ( V_6 -> V_9 -> V_155 != NULL )
V_6 -> V_9 -> V_155 ( V_6 , V_28 -> V_48 , V_145 + 4 ) ;
}
static int F_75 ( struct V_25 * V_26 , int V_156 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_156 == V_149 ) {
int V_157 ;
V_157 = 4 ;
if ( V_6 -> V_9 -> V_158 != NULL )
V_157 += V_6 -> V_9 -> V_158 ( V_6 ) ;
return V_157 ;
}
return - V_69 ;
}
static void F_76 ( struct V_25 * V_26 , struct V_159 * V_160 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_161 )
V_6 -> V_9 -> V_161 ( V_6 , V_28 -> V_48 , V_160 ) ;
}
static int F_77 ( struct V_25 * V_26 , struct V_159 * V_160 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_90 = - V_69 ;
if ( V_6 -> V_9 -> V_162 )
V_90 = V_6 -> V_9 -> V_162 ( V_6 , V_28 -> V_48 , V_160 ) ;
return V_90 ;
}
static int F_78 ( struct V_25 * V_26 , struct V_163 * V_164 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_90 ;
if ( ! V_6 -> V_9 -> V_165 )
return - V_69 ;
V_90 = V_6 -> V_9 -> V_165 ( V_6 , V_28 -> V_48 , V_28 -> V_49 , V_164 ) ;
if ( V_90 )
return V_90 ;
if ( V_28 -> V_49 )
V_90 = F_79 ( V_28 -> V_49 , V_164 ) ;
return V_90 ;
}
static int F_80 ( struct V_25 * V_26 , struct V_163 * V_164 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
int V_90 ;
if ( ! V_6 -> V_9 -> V_166 )
return - V_69 ;
V_90 = V_6 -> V_9 -> V_166 ( V_6 , V_28 -> V_48 , V_164 ) ;
if ( V_90 )
return V_90 ;
if ( V_28 -> V_49 )
V_90 = F_81 ( V_28 -> V_49 , V_164 ) ;
return V_90 ;
}
static int F_82 ( struct V_25 * V_26 ,
struct V_167 * V_168 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
struct V_25 * V_33 = V_6 -> V_29 -> V_30 ;
struct V_119 * V_119 ;
int V_37 = 0 ;
V_119 = F_83 ( sizeof( * V_119 ) , V_169 ) ;
if ( ! V_119 )
return - V_170 ;
V_37 = F_84 ( V_119 , V_33 ) ;
if ( V_37 ) {
F_85 ( V_119 ) ;
goto V_42;
}
V_28 -> V_119 = V_119 ;
V_42:
return V_37 ;
}
static void F_86 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_119 * V_119 = V_28 -> V_119 ;
if ( ! V_119 )
return;
V_28 -> V_119 = NULL ;
F_87 ( V_119 ) ;
}
static void F_88 ( struct V_25 * V_26 )
{
}
static void F_89 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
unsigned int V_171 = 0 ;
if ( V_28 -> V_172 != V_28 -> V_49 -> V_140 ) {
V_171 = 1 ;
V_28 -> V_172 = V_28 -> V_49 -> V_140 ;
}
if ( V_28 -> V_173 != V_28 -> V_49 -> V_174 ) {
V_171 = 1 ;
V_28 -> V_173 = V_28 -> V_49 -> V_174 ;
}
if ( V_28 -> V_175 != V_28 -> V_49 -> V_176 ) {
V_171 = 1 ;
V_28 -> V_175 = V_28 -> V_49 -> V_176 ;
}
if ( V_6 -> V_9 -> V_177 && V_171 )
V_6 -> V_9 -> V_177 ( V_6 , V_28 -> V_48 , V_28 -> V_49 ) ;
if ( V_171 )
F_90 ( V_28 -> V_49 ) ;
}
static int F_91 ( struct V_25 * V_26 ,
struct V_178 * V_179 )
{
struct V_27 * V_28 = F_5 ( V_26 ) ;
struct V_5 * V_6 = V_28 -> V_22 ;
if ( V_6 -> V_9 -> V_180 )
V_6 -> V_9 -> V_180 ( V_6 , V_28 -> V_48 , V_179 ) ;
return 0 ;
}
static int F_92 ( struct V_27 * V_28 ,
struct V_25 * V_181 ,
int V_3 )
{
struct V_5 * V_6 = V_28 -> V_22 ;
V_28 -> V_49 = V_6 -> V_13 -> V_182 [ V_3 ] ;
if ( ! V_28 -> V_49 )
return - V_183 ;
if ( V_28 -> V_184 == V_185 )
V_28 -> V_184 = V_28 -> V_49 -> V_186 ;
F_93 ( V_181 , V_28 -> V_49 , F_89 ,
V_28 -> V_184 ) ;
return 0 ;
}
static int F_94 ( struct V_27 * V_28 ,
struct V_25 * V_181 )
{
struct V_5 * V_6 = V_28 -> V_22 ;
struct V_187 * V_188 = V_6 -> V_20 ;
struct V_189 * V_190 , * V_191 ;
bool V_192 = false ;
T_3 V_193 = 0 ;
int V_194 , V_90 ;
V_191 = V_188 -> V_191 [ V_28 -> V_48 ] ;
V_194 = F_95 ( V_191 ) ;
if ( V_194 < 0 )
V_194 = V_185 ;
V_28 -> V_184 = V_194 ;
V_190 = F_96 ( V_191 , L_11 , 0 ) ;
if ( F_97 ( V_191 ) ) {
V_90 = F_98 ( V_191 ) ;
if ( V_90 ) {
F_99 ( V_181 , L_12 ) ;
return V_90 ;
}
V_192 = true ;
V_190 = V_191 ;
}
if ( V_6 -> V_9 -> V_195 )
V_193 = V_6 -> V_9 -> V_195 ( V_6 , V_28 -> V_48 ) ;
if ( V_190 ) {
V_90 = F_100 ( & V_181 -> V_26 , V_190 ) ;
if ( ! V_192 && V_90 >= 0 &&
( V_6 -> V_8 & ( 1 << V_90 ) ) ) {
V_90 = F_92 ( V_28 , V_181 , V_90 ) ;
if ( V_90 )
return V_90 ;
} else {
V_28 -> V_49 = F_101 ( V_181 , V_190 ,
F_89 ,
V_193 ,
V_28 -> V_184 ) ;
}
}
if ( V_28 -> V_49 && V_192 )
F_102 ( V_28 -> V_49 , F_91 ) ;
if ( ! V_28 -> V_49 ) {
V_90 = F_92 ( V_28 , V_181 , V_28 -> V_48 ) ;
if ( V_90 )
return V_90 ;
} else {
F_103 ( V_181 , L_13 ,
V_28 -> V_49 -> V_3 , V_28 -> V_49 -> V_9 -> V_14 ) ;
}
return 0 ;
}
static void F_104 ( struct V_25 * V_26 ,
struct V_196 * V_197 ,
void * V_198 )
{
F_105 ( & V_197 -> V_199 ,
& V_200 ) ;
}
int F_106 ( struct V_25 * V_181 )
{
struct V_27 * V_28 = F_5 ( V_181 ) ;
if ( V_28 -> V_49 ) {
F_15 ( V_28 -> V_49 ) ;
V_28 -> V_175 = - 1 ;
V_28 -> V_172 = - 1 ;
V_28 -> V_173 = - 1 ;
F_107 ( V_28 -> V_49 ) ;
}
return 0 ;
}
int F_108 ( struct V_25 * V_181 )
{
struct V_27 * V_28 = F_5 ( V_181 ) ;
F_109 ( V_181 ) ;
if ( V_28 -> V_49 ) {
F_110 ( V_28 -> V_49 ) ;
F_12 ( V_28 -> V_49 ) ;
}
return 0 ;
}
int F_111 ( struct V_5 * V_6 , struct V_201 * V_22 ,
int V_48 , char * V_14 )
{
struct V_25 * V_33 = V_6 -> V_29 -> V_30 ;
struct V_25 * V_181 ;
struct V_27 * V_28 ;
int V_90 ;
V_181 = F_112 ( sizeof( struct V_27 ) , V_14 ,
V_202 , V_203 ) ;
if ( V_181 == NULL )
return - V_170 ;
V_181 -> V_204 = V_33 -> V_205 ;
V_181 -> V_206 = & V_207 ;
F_113 ( V_181 , V_33 ) ;
V_181 -> V_103 |= V_208 ;
V_181 -> V_209 = & V_210 ;
V_181 -> V_211 = & V_212 ;
F_114 ( V_181 , F_104 ,
NULL ) ;
F_115 ( V_181 , V_22 ) ;
V_181 -> V_26 . V_213 = V_6 -> V_20 -> V_191 [ V_48 ] ;
V_181 -> V_205 = V_33 -> V_205 ;
V_28 = F_5 ( V_181 ) ;
V_28 -> V_26 = V_181 ;
V_28 -> V_22 = V_6 ;
V_28 -> V_48 = V_48 ;
switch ( V_6 -> V_29 -> V_214 ) {
#ifdef F_116
case V_215 :
V_28 -> V_126 = V_216 . V_126 ;
break;
#endif
#ifdef F_117
case V_217 :
V_28 -> V_126 = V_218 . V_126 ;
break;
#endif
#ifdef F_118
case V_219 :
V_28 -> V_126 = V_220 . V_126 ;
break;
#endif
#ifdef F_119
case V_221 :
V_28 -> V_126 = V_222 . V_126 ;
break;
#endif
default:
V_28 -> V_126 = F_56 ;
break;
}
V_28 -> V_175 = - 1 ;
V_28 -> V_172 = - 1 ;
V_28 -> V_173 = - 1 ;
V_90 = F_94 ( V_28 , V_181 ) ;
if ( V_90 ) {
F_120 ( V_181 ) ;
return V_90 ;
}
V_6 -> V_70 [ V_48 ] = V_181 ;
V_90 = F_121 ( V_181 ) ;
if ( V_90 ) {
F_99 ( V_33 , L_14 ,
V_90 , V_181 -> V_14 ) ;
F_122 ( V_28 -> V_49 ) ;
V_6 -> V_70 [ V_48 ] = NULL ;
F_120 ( V_181 ) ;
return V_90 ;
}
F_123 ( V_181 ) ;
return 0 ;
}
static bool F_124 ( struct V_25 * V_26 )
{
return V_26 -> V_209 == & V_210 ;
}
static int F_125 ( struct V_25 * V_26 )
{
struct V_25 * V_33 = F_126 ( V_26 ) ;
struct V_27 * V_28 = F_5 ( V_26 ) ;
int V_37 = 0 ;
if ( V_33 && V_33 -> V_223 &&
! strcmp ( V_33 -> V_223 -> V_224 , L_15 ) )
V_37 = F_45 ( V_26 , V_33 ) ;
else if ( F_6 ( V_28 ) )
V_37 = F_46 ( V_26 ) ;
return V_37 ;
}
int F_127 ( struct V_225 * V_226 ,
unsigned long V_227 , void * V_228 )
{
struct V_25 * V_26 ;
int V_37 = 0 ;
switch ( V_227 ) {
case V_229 :
V_26 = F_128 ( V_228 ) ;
if ( ! F_124 ( V_26 ) )
goto V_42;
V_37 = F_125 ( V_26 ) ;
if ( V_37 )
F_129 ( V_26 , L_16 ) ;
break;
}
V_42:
return V_230 ;
}
