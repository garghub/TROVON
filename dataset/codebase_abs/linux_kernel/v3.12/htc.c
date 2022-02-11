static inline void F_1 ( struct V_1 * V_2 ,
int V_3 )
{
F_2 ( V_2 -> V_4 -> V_5 , V_2 -> V_6 , V_3 ) ;
}
static void F_3 ( struct V_7 * V_5 ,
struct V_8 * V_9 )
{
F_4 ( V_9 ) ;
}
static struct V_8 * F_5 ( void * V_5 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
V_9 = F_6 ( V_12 ) ;
if ( ! V_9 ) {
F_7 ( L_1 ) ;
return NULL ;
}
F_8 ( V_9 , 20 ) ;
F_9 ( ( unsigned long ) V_9 -> V_13 & 3 , L_2 ) ;
V_11 = F_10 ( V_9 ) ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
F_11 ( V_14 , L_3 , V_15 , V_9 ) ;
return V_9 ;
}
static inline void F_12 ( struct V_16 * V_4 ,
struct V_8 * V_9 )
{
F_13 ( V_4 -> V_5 -> V_17 , V_9 ) ;
F_14 ( V_9 , sizeof( struct V_18 ) ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
F_11 ( V_14 , L_4 , V_15 ,
V_2 -> V_19 , V_9 ) ;
F_12 ( V_2 -> V_4 , V_9 ) ;
if ( ! V_2 -> V_20 . V_21 ) {
F_7 ( L_5 , V_2 -> V_19 ) ;
F_16 ( V_9 ) ;
return;
}
V_2 -> V_20 . V_21 ( V_2 -> V_4 -> V_5 , V_9 ) ;
}
static bool F_17 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_22 )
return false ;
if ( V_2 -> V_23 >= V_2 -> V_24 )
return false ;
F_11 ( V_14 , L_6 ,
V_2 -> V_19 ) ;
return true ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_18 * V_25 ;
V_25 = (struct V_18 * ) V_9 -> V_13 ;
memset ( V_25 , 0 , sizeof( * V_25 ) ) ;
V_25 -> V_19 = V_2 -> V_19 ;
V_25 -> V_26 = F_19 ( V_9 -> V_26 - sizeof( * V_25 ) ) ;
F_20 ( & V_2 -> V_4 -> V_27 ) ;
V_25 -> V_28 = V_2 -> V_28 ++ ;
if ( F_17 ( V_2 ) )
V_25 -> V_29 |= V_30 ;
F_21 ( & V_2 -> V_4 -> V_27 ) ;
}
static int F_22 ( struct V_16 * V_4 ,
struct V_1 * V_2 ,
struct V_8 * V_9 ,
T_1 V_31 )
{
struct V_10 * V_11 = F_10 ( V_9 ) ;
int V_32 ;
F_11 ( V_14 , L_4 , V_15 ,
V_2 -> V_19 , V_9 ) ;
F_18 ( V_2 , V_9 ) ;
V_32 = F_23 ( V_4 -> V_5 -> V_17 , V_9 ) ;
if ( V_32 )
goto V_33;
V_32 = F_24 ( V_4 -> V_5 ,
V_2 -> V_6 ,
V_2 -> V_19 ,
V_9 -> V_26 ,
V_9 ) ;
if ( F_25 ( V_32 ) )
goto V_33;
return 0 ;
V_33:
F_7 ( L_7 , V_32 ) ;
F_20 ( & V_4 -> V_27 ) ;
V_2 -> V_23 += V_31 ;
F_21 ( & V_4 -> V_27 ) ;
if ( V_32 == - V_34 ) {
F_20 ( & V_4 -> V_27 ) ;
F_26 ( & V_2 -> V_35 , V_9 ) ;
F_21 ( & V_4 -> V_27 ) ;
return V_32 ;
}
V_11 -> V_36 = true ;
F_15 ( V_2 , V_9 ) ;
return V_32 ;
}
static struct V_8 * F_27 ( struct V_16 * V_4 ,
struct V_1 * V_2 ,
T_1 * V_31 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int V_37 ;
int V_38 ;
unsigned int V_39 ;
F_28 ( & V_4 -> V_27 ) ;
V_9 = F_29 ( & V_2 -> V_35 ) ;
if ( ! V_9 )
return NULL ;
V_11 = F_10 ( V_9 ) ;
V_39 = V_9 -> V_26 ;
if ( F_30 ( V_39 <= V_4 -> V_40 ) ) {
V_37 = 1 ;
} else {
V_37 = V_39 / V_4 -> V_40 ;
V_38 = V_39 % V_4 -> V_40 ;
if ( V_38 )
V_37 ++ ;
}
F_11 ( V_14 , L_8 ,
V_37 , V_2 -> V_23 ) ;
if ( V_2 -> V_23 < V_37 ) {
F_26 ( & V_2 -> V_35 , V_9 ) ;
return NULL ;
}
V_2 -> V_23 -= V_37 ;
* V_31 = V_37 ;
return V_9 ;
}
static void F_31 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_32 ( V_42 ,
struct V_1 , V_43 ) ;
struct V_16 * V_4 = V_2 -> V_4 ;
struct V_8 * V_9 ;
T_1 V_31 = 0 ;
int V_32 ;
while ( true ) {
if ( V_2 -> V_44 )
F_1 ( V_2 , 0 ) ;
F_20 ( & V_4 -> V_27 ) ;
if ( V_2 -> V_22 )
V_9 = F_27 ( V_4 , V_2 ,
& V_31 ) ;
else
V_9 = F_29 ( & V_2 -> V_35 ) ;
F_21 ( & V_4 -> V_27 ) ;
if ( ! V_9 )
break;
V_32 = F_22 ( V_4 , V_2 , V_9 , V_31 ) ;
if ( V_32 == - V_34 )
break;
}
}
int F_33 ( struct V_16 * V_4 ,
enum V_45 V_19 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_4 -> V_46 [ V_19 ] ;
if ( V_4 -> V_5 -> V_47 == V_48 )
return - V_49 ;
if ( V_19 >= V_50 ) {
F_7 ( L_9 , V_19 ) ;
return - V_51 ;
}
F_20 ( & V_4 -> V_27 ) ;
if ( V_4 -> V_52 ) {
F_21 ( & V_4 -> V_27 ) ;
return - V_53 ;
}
F_34 ( & V_2 -> V_35 , V_9 ) ;
F_35 ( V_9 , sizeof( struct V_18 ) ) ;
F_21 ( & V_4 -> V_27 ) ;
F_36 ( V_4 -> V_5 -> V_54 , & V_2 -> V_43 ) ;
return 0 ;
}
static int F_37 ( struct V_7 * V_5 ,
struct V_8 * V_9 ,
unsigned int V_19 )
{
struct V_16 * V_4 = & V_5 -> V_4 ;
struct V_1 * V_2 = & V_4 -> V_46 [ V_19 ] ;
F_15 ( V_2 , V_9 ) ;
F_20 ( & V_4 -> V_27 ) ;
if ( ! V_2 -> V_22 && ! V_4 -> V_52 )
F_36 ( V_5 -> V_54 , & V_2 -> V_43 ) ;
F_21 ( & V_4 -> V_27 ) ;
return 0 ;
}
static void F_38 ( struct V_16 * V_4 ,
struct V_1 * V_2 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
F_20 ( & V_4 -> V_27 ) ;
for (; ; ) {
V_9 = F_29 ( & V_2 -> V_35 ) ;
if ( ! V_9 )
break;
V_11 = F_10 ( V_9 ) ;
V_11 -> V_36 = true ;
F_15 ( V_2 , V_9 ) ;
}
F_21 ( & V_4 -> V_27 ) ;
F_39 ( & V_2 -> V_43 ) ;
}
static void
F_40 ( struct V_16 * V_4 ,
const struct V_55 * V_56 ,
int V_26 ,
enum V_45 V_19 )
{
struct V_1 * V_2 ;
int V_57 , V_58 ;
if ( V_26 % sizeof( * V_56 ) )
F_7 ( L_10 , V_26 ) ;
V_58 = V_26 / sizeof( * V_56 ) ;
F_20 ( & V_4 -> V_27 ) ;
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ , V_56 ++ ) {
if ( V_56 -> V_19 >= V_50 )
break;
F_11 ( V_14 , L_11 ,
V_56 -> V_19 , V_56 -> V_31 ) ;
V_2 = & V_4 -> V_46 [ V_56 -> V_19 ] ;
V_2 -> V_23 += V_56 -> V_31 ;
if ( V_2 -> V_23 && ! F_41 ( & V_2 -> V_35 ) )
F_36 ( V_4 -> V_5 -> V_54 , & V_2 -> V_43 ) ;
}
F_21 ( & V_4 -> V_27 ) ;
}
static int F_42 ( struct V_16 * V_4 ,
T_1 * V_59 ,
int V_60 ,
enum V_45 V_61 )
{
int V_62 = 0 ;
struct V_63 * V_64 ;
T_1 * V_65 ;
int V_66 ;
T_2 V_26 ;
V_65 = V_59 ;
V_66 = V_60 ;
while ( V_60 > 0 ) {
V_64 = (struct V_63 * ) V_59 ;
if ( V_60 < sizeof( V_64 -> V_25 ) ) {
V_62 = - V_67 ;
break;
}
if ( V_64 -> V_25 . V_26 > V_60 ) {
F_7 ( L_12 ,
V_64 -> V_25 . V_26 ) ;
V_62 = - V_67 ;
break;
}
switch ( V_64 -> V_25 . V_68 ) {
case V_69 :
V_26 = sizeof( struct V_55 ) ;
if ( V_64 -> V_25 . V_26 < V_26 ) {
F_7 ( L_13 ) ;
V_62 = - V_67 ;
break;
}
F_40 ( V_4 ,
V_64 -> V_70 ,
V_64 -> V_25 . V_26 ,
V_61 ) ;
break;
default:
F_7 ( L_14 ,
V_64 -> V_25 . V_68 , V_64 -> V_25 . V_26 ) ;
break;
}
if ( V_62 )
break;
V_59 += sizeof( V_64 -> V_25 ) + V_64 -> V_25 . V_26 ;
V_60 -= sizeof( V_64 -> V_25 ) + V_64 -> V_25 . V_26 ;
}
if ( V_62 )
F_43 ( V_14 , L_15 , L_16 ,
V_65 , V_66 ) ;
return V_62 ;
}
static int F_44 ( struct V_7 * V_5 ,
struct V_8 * V_9 ,
T_1 V_71 )
{
int V_62 = 0 ;
struct V_16 * V_4 = & V_5 -> V_4 ;
struct V_18 * V_25 ;
struct V_1 * V_2 ;
T_3 V_72 ;
T_4 V_73 = 0 ;
T_2 V_74 ;
T_1 V_19 ;
bool V_75 ;
V_25 = (struct V_18 * ) V_9 -> V_13 ;
F_14 ( V_9 , sizeof( * V_25 ) ) ;
V_19 = V_25 -> V_19 ;
if ( V_19 >= V_50 ) {
F_7 ( L_17 , V_19 ) ;
F_43 ( V_14 , L_18 , L_16 ,
V_25 , sizeof( * V_25 ) ) ;
V_62 = - V_67 ;
goto V_76;
}
V_2 = & V_4 -> V_46 [ V_19 ] ;
if ( V_2 -> V_44 )
F_1 ( V_2 , 1 ) ;
V_72 = F_45 ( V_25 -> V_26 ) ;
if ( V_72 + sizeof( * V_25 ) > V_77 ) {
F_7 ( L_19 ,
V_72 + sizeof( * V_25 ) ) ;
F_43 ( V_14 , L_20 , L_16 ,
V_25 , sizeof( * V_25 ) ) ;
V_62 = - V_67 ;
goto V_76;
}
if ( V_9 -> V_26 < V_72 ) {
F_11 ( V_14 ,
L_21 ,
V_9 -> V_26 , V_72 ) ;
F_43 ( V_14 , L_20 ,
L_16 , V_25 , sizeof( * V_25 ) ) ;
V_62 = - V_67 ;
goto V_76;
}
V_75 = V_25 -> V_29 & V_78 ;
if ( V_75 ) {
T_1 * V_79 ;
V_73 = V_25 -> V_73 ;
V_74 = sizeof( struct V_80 ) ;
if ( ( V_73 < V_74 ) ||
( V_73 > V_72 ) ) {
F_7 ( L_22 ,
V_73 ) ;
V_62 = - V_81 ;
goto V_76;
}
V_79 = ( T_1 * ) V_25 ;
V_79 += sizeof( * V_25 ) ;
V_79 += V_72 ;
V_79 -= V_73 ;
V_62 = F_42 ( V_4 , V_79 ,
V_73 , V_25 -> V_19 ) ;
if ( V_62 )
goto V_76;
F_46 ( V_9 , V_9 -> V_26 - V_73 ) ;
}
if ( ( ( int ) V_72 - ( int ) V_73 ) <= 0 )
goto V_76;
if ( V_19 == V_82 ) {
struct V_83 * V_84 = (struct V_83 * ) V_9 -> V_13 ;
switch ( F_45 ( V_84 -> V_25 . V_85 ) ) {
default:
if ( F_47 ( & V_4 -> V_86 ) ) {
F_7 ( L_23 ) ;
V_62 = - V_67 ;
F_48 ( & V_4 -> V_86 ) ;
goto V_76;
}
V_4 -> V_87 =
F_49 ( int , V_9 -> V_26 ,
V_88 ) ;
memcpy ( V_4 -> V_89 , V_9 -> V_13 ,
V_4 -> V_87 ) ;
F_48 ( & V_4 -> V_86 ) ;
break;
case V_90 :
V_4 -> V_91 . V_92 ( V_5 ) ;
}
goto V_76;
}
F_11 ( V_14 , L_24 ,
V_19 , V_9 ) ;
V_2 -> V_20 . V_93 ( V_5 , V_9 ) ;
V_9 = NULL ;
V_76:
F_4 ( V_9 ) ;
return V_62 ;
}
static void F_50 ( struct V_7 * V_5 ,
struct V_8 * V_9 )
{
F_7 ( L_25 ) ;
F_4 ( V_9 ) ;
}
static const char * F_51 ( enum V_94 V_68 )
{
switch ( V_68 ) {
case V_95 :
return L_26 ;
case V_96 :
return L_27 ;
case V_97 :
return L_28 ;
case V_98 :
return L_29 ;
case V_99 :
return L_30 ;
case V_100 :
return L_31 ;
case V_101 :
return L_32 ;
case V_102 :
return L_33 ;
case V_103 :
return L_34 ;
case V_104 :
return L_35 ;
case V_105 :
return L_36 ;
}
return L_37 ;
}
static void F_52 ( struct V_16 * V_4 )
{
struct V_1 * V_2 ;
int V_57 ;
for ( V_57 = V_82 ; V_57 < V_50 ; V_57 ++ ) {
V_2 = & V_4 -> V_46 [ V_57 ] ;
V_2 -> V_106 = V_107 ;
V_2 -> V_108 = 0 ;
V_2 -> V_109 = 0 ;
V_2 -> V_19 = V_57 ;
F_53 ( & V_2 -> V_35 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_22 = true ;
F_54 ( & V_2 -> V_43 , F_31 ) ;
}
}
static void F_55 ( struct V_16 * V_4 )
{
struct V_110 * V_111 ;
V_111 = & V_4 -> V_112 [ 0 ] ;
V_111 ++ ;
V_111 -> V_106 = V_97 ;
V_111 -> V_113 = V_4 -> V_114 ;
}
static T_1 F_56 ( struct V_16 * V_4 ,
T_3 V_106 )
{
T_1 V_115 = 0 ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_50 ; V_57 ++ ) {
if ( V_4 -> V_112 [ V_57 ] . V_106 == V_106 )
V_115 =
V_4 -> V_112 [ V_57 ] . V_113 ;
}
return V_115 ;
}
int F_57 ( struct V_16 * V_4 )
{
int V_62 = 0 ;
struct V_116 V_117 ;
struct V_118 V_119 ;
struct V_83 * V_84 ;
T_3 V_85 ;
T_3 V_120 ;
T_3 V_121 ;
F_58 ( V_4 -> V_86 ) ;
V_62 = F_59 ( V_4 -> V_5 ) ;
if ( V_62 ) {
F_60 ( L_38 , V_62 ) ;
goto V_122;
}
V_62 = F_61 ( & V_4 -> V_86 ,
V_123 ) ;
if ( V_62 <= 0 ) {
if ( V_62 == 0 )
V_62 = - V_124 ;
F_60 ( L_39 , V_62 ) ;
goto V_125;
}
if ( V_4 -> V_87 < sizeof( V_84 -> V_25 ) + sizeof( V_84 -> V_126 ) ) {
F_60 ( L_40 ,
V_4 -> V_87 ) ;
V_62 = - V_49 ;
goto V_125;
}
V_84 = (struct V_83 * ) V_4 -> V_89 ;
V_85 = F_45 ( V_84 -> V_25 . V_85 ) ;
V_120 = F_45 ( V_84 -> V_126 . V_120 ) ;
V_121 = F_45 ( V_84 -> V_126 . V_121 ) ;
if ( V_85 != V_127 ) {
F_60 ( L_41 , V_85 ) ;
V_62 = - V_49 ;
goto V_125;
}
V_4 -> V_114 = V_120 ;
V_4 -> V_40 = V_121 ;
F_11 ( V_14 ,
L_42 ,
V_4 -> V_114 ,
V_4 -> V_40 ) ;
if ( ( V_4 -> V_114 == 0 ) ||
( V_4 -> V_40 == 0 ) ) {
V_62 = - V_49 ;
F_60 ( L_43 ) ;
goto V_125;
}
F_55 ( V_4 ) ;
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
V_117 . V_20 . V_21 = F_3 ;
V_117 . V_20 . V_93 = F_50 ;
V_117 . V_128 = V_129 ;
V_117 . V_106 = V_96 ;
V_62 = F_62 ( V_4 , & V_117 , & V_119 ) ;
if ( V_62 ) {
F_60 ( L_44 , V_62 ) ;
goto V_125;
}
return 0 ;
V_125:
F_63 ( V_4 -> V_5 ) ;
V_122:
return V_62 ;
}
int F_62 ( struct V_16 * V_4 ,
struct V_116 * V_117 ,
struct V_118 * V_119 )
{
struct V_83 * V_84 ;
struct V_130 * V_131 ;
struct V_132 V_133 ;
struct V_132 * V_134 = & V_133 ;
enum V_45 V_135 = V_50 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
unsigned int V_136 = 0 ;
int V_60 , V_62 ;
bool V_137 = false ;
T_3 V_85 , V_106 , V_29 = 0 ;
T_1 V_138 = 0 ;
if ( V_117 -> V_106 == V_96 ) {
V_137 = true ;
V_135 = V_82 ;
V_136 = V_88 ;
memset ( & V_133 , 0 , sizeof( V_133 ) ) ;
goto V_139;
}
V_138 = F_56 ( V_4 ,
V_117 -> V_106 ) ;
if ( ! V_138 )
F_11 ( V_14 ,
L_45 ,
F_51 ( V_117 -> V_106 ) ) ;
V_9 = F_5 ( V_4 -> V_5 ) ;
if ( ! V_9 ) {
F_60 ( L_46 ) ;
return - V_140 ;
}
V_60 = sizeof( V_84 -> V_25 ) + sizeof( V_84 -> V_141 ) ;
F_64 ( V_9 , V_60 ) ;
memset ( V_9 -> V_13 , 0 , V_60 ) ;
V_84 = (struct V_83 * ) V_9 -> V_13 ;
V_84 -> V_25 . V_85 =
F_19 ( V_142 ) ;
V_29 |= F_65 ( V_138 , V_143 ) ;
V_131 = & V_84 -> V_141 ;
V_131 -> V_29 = F_19 ( V_29 ) ;
V_131 -> V_106 = F_19 ( V_117 -> V_106 ) ;
if ( V_117 -> V_106 != V_97 ) {
V_29 |= V_144 ;
V_137 = true ;
}
F_58 ( V_4 -> V_86 ) ;
V_62 = F_33 ( V_4 , V_82 , V_9 ) ;
if ( V_62 ) {
F_4 ( V_9 ) ;
return V_62 ;
}
V_62 = F_61 ( & V_4 -> V_86 ,
V_145 ) ;
if ( V_62 <= 0 ) {
if ( V_62 == 0 )
V_62 = - V_124 ;
F_60 ( L_47 , V_62 ) ;
return V_62 ;
}
V_84 = (struct V_83 * ) V_4 -> V_89 ;
V_134 = & V_84 -> V_146 ;
V_85 = F_45 ( V_84 -> V_25 . V_85 ) ;
V_106 = F_45 ( V_134 -> V_106 ) ;
if ( ( V_85 != V_147 ) ||
( V_4 -> V_87 < sizeof( V_84 -> V_25 ) +
sizeof( V_84 -> V_146 ) ) ) {
F_60 ( L_48 , V_85 ) ;
return - V_81 ;
}
F_11 ( V_14 ,
L_49 ,
F_51 ( V_106 ) ,
V_134 -> V_62 , V_134 -> V_19 ) ;
V_119 -> V_148 = V_134 -> V_62 ;
if ( V_134 -> V_62 != V_149 ) {
F_60 ( L_50 ,
F_51 ( V_106 ) ,
V_134 -> V_62 ) ;
return - V_81 ;
}
V_135 = (enum V_45 ) V_134 -> V_19 ;
V_136 = F_45 ( V_134 -> V_136 ) ;
V_139:
if ( V_135 >= V_50 )
return - V_81 ;
if ( V_136 == 0 )
return - V_81 ;
V_2 = & V_4 -> V_46 [ V_135 ] ;
V_2 -> V_19 = V_135 ;
if ( V_2 -> V_106 != V_107 )
return - V_81 ;
V_119 -> V_19 = V_135 ;
V_119 -> V_150 = F_45 ( V_134 -> V_136 ) ;
V_2 -> V_106 = V_117 -> V_106 ;
V_2 -> V_109 = V_117 -> V_128 ;
V_2 -> V_108 = F_45 ( V_134 -> V_136 ) ;
V_2 -> V_23 = V_138 ;
V_2 -> V_151 = V_4 -> V_40 ;
V_2 -> V_24 = V_2 -> V_108 /
V_4 -> V_40 ;
if ( V_2 -> V_108 % V_4 -> V_40 )
V_2 -> V_24 ++ ;
V_2 -> V_20 = V_117 -> V_20 ;
V_62 = F_66 ( V_4 -> V_5 ,
V_2 -> V_106 ,
& V_2 -> V_6 ,
& V_2 -> V_152 ,
& V_2 -> V_44 ,
& V_2 -> V_153 ) ;
if ( V_62 )
return V_62 ;
F_11 ( V_14 ,
L_51 ,
F_51 ( V_2 -> V_106 ) , V_2 -> V_6 ,
V_2 -> V_152 , V_2 -> V_19 ) ;
F_11 ( V_14 ,
L_52 ,
V_2 -> V_19 , V_2 -> V_44 , V_2 -> V_153 ) ;
if ( V_137 && V_2 -> V_22 ) {
V_2 -> V_22 = false ;
F_11 ( V_14 ,
L_53 ,
F_51 ( V_2 -> V_106 ) , V_135 ) ;
}
return V_62 ;
}
struct V_8 * F_67 ( int V_154 )
{
struct V_8 * V_9 ;
V_9 = F_6 ( V_154 + sizeof( struct V_18 ) ) ;
if ( ! V_9 ) {
F_7 ( L_54 ) ;
return NULL ;
}
F_8 ( V_9 , sizeof( struct V_18 ) ) ;
if ( ! F_68 ( ( unsigned long ) V_9 -> V_13 , 4 ) )
F_7 ( L_55 ) ;
return V_9 ;
}
int F_69 ( struct V_16 * V_4 )
{
struct V_8 * V_9 ;
int V_62 = 0 ;
struct V_83 * V_84 ;
V_9 = F_5 ( V_4 -> V_5 ) ;
if ( ! V_9 )
return - V_140 ;
F_64 ( V_9 , sizeof( V_84 -> V_25 ) + sizeof( V_84 -> V_155 ) ) ;
memset ( V_9 -> V_13 , 0 , V_9 -> V_26 ) ;
V_84 = (struct V_83 * ) V_9 -> V_13 ;
V_84 -> V_25 . V_85 =
F_19 ( V_156 ) ;
F_11 ( V_14 , L_56 ) ;
V_62 = F_33 ( V_4 , V_82 , V_9 ) ;
if ( V_62 ) {
F_4 ( V_9 ) ;
return V_62 ;
}
return 0 ;
}
void F_70 ( struct V_16 * V_4 )
{
int V_57 ;
struct V_1 * V_2 ;
F_20 ( & V_4 -> V_27 ) ;
V_4 -> V_52 = true ;
F_21 ( & V_4 -> V_27 ) ;
for ( V_57 = V_82 ; V_57 < V_50 ; V_57 ++ ) {
V_2 = & V_4 -> V_46 [ V_57 ] ;
F_38 ( V_4 , V_2 ) ;
}
F_63 ( V_4 -> V_5 ) ;
}
int F_71 ( struct V_7 * V_5 )
{
struct V_157 V_158 ;
struct V_1 * V_2 = NULL ;
struct V_16 * V_4 = & V_5 -> V_4 ;
F_72 ( & V_4 -> V_27 ) ;
V_4 -> V_52 = false ;
F_52 ( V_4 ) ;
V_158 . V_159 = F_44 ;
V_158 . V_160 = F_37 ;
V_4 -> V_5 = V_5 ;
V_2 = & V_4 -> V_46 [ V_82 ] ;
F_73 ( V_5 , & V_158 ) ;
F_74 ( V_5 , & V_2 -> V_6 , & V_2 -> V_152 ) ;
F_75 ( & V_4 -> V_86 ) ;
return 0 ;
}
