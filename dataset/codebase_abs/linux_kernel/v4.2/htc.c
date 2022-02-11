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
if ( ! V_9 )
return NULL ;
F_7 ( V_9 , 20 ) ;
F_8 ( ( unsigned long ) V_9 -> V_13 & 3 , L_1 ) ;
V_11 = F_9 ( V_9 ) ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
F_10 ( V_5 , V_14 , L_2 , V_15 , V_9 ) ;
return V_9 ;
}
static inline void F_11 ( struct V_16 * V_4 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = F_9 ( V_9 ) ;
F_12 ( V_4 -> V_5 -> V_17 , V_11 -> V_18 , V_9 -> V_19 , V_20 ) ;
F_13 ( V_9 , sizeof( struct V_21 ) ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_7 * V_5 = V_2 -> V_4 -> V_5 ;
F_10 ( V_5 , V_14 , L_3 , V_15 ,
V_2 -> V_22 , V_9 ) ;
F_11 ( V_2 -> V_4 , V_9 ) ;
if ( ! V_2 -> V_23 . V_24 ) {
F_15 ( V_5 , L_4 , V_2 -> V_22 ) ;
F_16 ( V_9 ) ;
return;
}
V_2 -> V_23 . V_24 ( V_2 -> V_4 -> V_5 , V_9 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_21 * V_25 ;
V_25 = (struct V_21 * ) V_9 -> V_13 ;
V_25 -> V_22 = V_2 -> V_22 ;
V_25 -> V_19 = F_18 ( V_9 -> V_19 - sizeof( * V_25 ) ) ;
V_25 -> V_26 = 0 ;
V_25 -> V_26 |= V_27 ;
F_19 ( & V_2 -> V_4 -> V_28 ) ;
V_25 -> V_29 = V_2 -> V_29 ++ ;
F_20 ( & V_2 -> V_4 -> V_28 ) ;
}
int F_21 ( struct V_16 * V_4 ,
enum V_30 V_22 ,
struct V_8 * V_9 )
{
struct V_7 * V_5 = V_4 -> V_5 ;
struct V_1 * V_2 = & V_4 -> V_31 [ V_22 ] ;
struct V_10 * V_11 = F_9 ( V_9 ) ;
struct V_32 V_33 ;
struct V_34 * V_17 = V_4 -> V_5 -> V_17 ;
int V_35 = 0 ;
int V_36 ;
if ( V_4 -> V_5 -> V_37 == V_38 )
return - V_39 ;
if ( V_22 >= V_40 ) {
F_15 ( V_5 , L_5 , V_22 ) ;
return - V_41 ;
}
F_22 ( V_9 , sizeof( struct V_21 ) ) ;
if ( V_2 -> V_42 ) {
V_35 = F_23 ( V_9 -> V_19 , V_4 -> V_43 ) ;
F_19 ( & V_4 -> V_28 ) ;
if ( V_2 -> V_44 < V_35 ) {
F_20 ( & V_4 -> V_28 ) ;
V_36 = - V_45 ;
goto V_46;
}
V_2 -> V_44 -= V_35 ;
F_10 ( V_5 , V_14 ,
L_6 ,
V_22 , V_35 , V_2 -> V_44 ) ;
F_20 ( & V_4 -> V_28 ) ;
}
F_17 ( V_2 , V_9 ) ;
V_11 -> V_22 = V_22 ;
V_11 -> V_18 = F_24 ( V_17 , V_9 -> V_13 , V_9 -> V_19 , V_20 ) ;
V_36 = F_25 ( V_17 , V_11 -> V_18 ) ;
if ( V_36 )
goto V_47;
V_33 . V_48 = V_2 -> V_22 ;
V_33 . V_49 = V_9 ;
V_33 . V_50 = V_9 -> V_13 ;
V_33 . V_18 = V_11 -> V_18 ;
V_33 . V_19 = V_9 -> V_19 ;
V_36 = F_26 ( V_4 -> V_5 , V_2 -> V_6 , & V_33 , 1 ) ;
if ( V_36 )
goto V_51;
return 0 ;
V_51:
F_12 ( V_17 , V_11 -> V_18 , V_9 -> V_19 , V_20 ) ;
V_47:
if ( V_2 -> V_42 ) {
F_19 ( & V_4 -> V_28 ) ;
V_2 -> V_44 += V_35 ;
F_10 ( V_5 , V_14 ,
L_7 ,
V_22 , V_35 , V_2 -> V_44 ) ;
F_20 ( & V_4 -> V_28 ) ;
if ( V_2 -> V_23 . V_52 )
V_2 -> V_23 . V_52 ( V_4 -> V_5 ) ;
}
V_46:
F_13 ( V_9 , sizeof( struct V_21 ) ) ;
return V_36 ;
}
static int F_27 ( struct V_7 * V_5 ,
struct V_8 * V_9 )
{
struct V_16 * V_4 = & V_5 -> V_4 ;
struct V_10 * V_11 ;
struct V_1 * V_2 ;
if ( F_28 ( ! V_9 ) )
return 0 ;
V_11 = F_9 ( V_9 ) ;
V_2 = & V_4 -> V_31 [ V_11 -> V_22 ] ;
F_14 ( V_2 , V_9 ) ;
return 0 ;
}
static void
F_29 ( struct V_16 * V_4 ,
const struct V_53 * V_54 ,
int V_19 ,
enum V_30 V_22 )
{
struct V_7 * V_5 = V_4 -> V_5 ;
struct V_1 * V_2 ;
int V_55 , V_56 ;
if ( V_19 % sizeof( * V_54 ) )
F_15 ( V_5 , L_8 , V_19 ) ;
V_56 = V_19 / sizeof( * V_54 ) ;
F_19 ( & V_4 -> V_28 ) ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ , V_54 ++ ) {
if ( V_54 -> V_22 >= V_40 )
break;
V_2 = & V_4 -> V_31 [ V_54 -> V_22 ] ;
V_2 -> V_44 += V_54 -> V_35 ;
F_10 ( V_5 , V_14 , L_9 ,
V_54 -> V_22 , V_54 -> V_35 , V_2 -> V_44 ) ;
if ( V_2 -> V_23 . V_52 ) {
F_20 ( & V_4 -> V_28 ) ;
V_2 -> V_23 . V_52 ( V_4 -> V_5 ) ;
F_19 ( & V_4 -> V_28 ) ;
}
}
F_20 ( & V_4 -> V_28 ) ;
}
static int F_30 ( struct V_16 * V_4 ,
T_1 * V_57 ,
int V_58 ,
enum V_30 V_59 )
{
struct V_7 * V_5 = V_4 -> V_5 ;
int V_60 = 0 ;
struct V_61 * V_62 ;
T_1 * V_63 ;
int V_64 ;
T_2 V_19 ;
V_63 = V_57 ;
V_64 = V_58 ;
while ( V_58 > 0 ) {
V_62 = (struct V_61 * ) V_57 ;
if ( V_58 < sizeof( V_62 -> V_25 ) ) {
V_60 = - V_65 ;
break;
}
if ( V_62 -> V_25 . V_19 > V_58 ) {
F_15 ( V_5 , L_10 ,
V_62 -> V_25 . V_19 ) ;
V_60 = - V_65 ;
break;
}
switch ( V_62 -> V_25 . V_66 ) {
case V_67 :
V_19 = sizeof( struct V_53 ) ;
if ( V_62 -> V_25 . V_19 < V_19 ) {
F_15 ( V_5 , L_11 ) ;
V_60 = - V_65 ;
break;
}
F_29 ( V_4 ,
V_62 -> V_68 ,
V_62 -> V_25 . V_19 ,
V_59 ) ;
break;
default:
F_15 ( V_5 , L_12 ,
V_62 -> V_25 . V_66 , V_62 -> V_25 . V_19 ) ;
break;
}
if ( V_60 )
break;
V_57 += sizeof( V_62 -> V_25 ) + V_62 -> V_25 . V_19 ;
V_58 -= sizeof( V_62 -> V_25 ) + V_62 -> V_25 . V_19 ;
}
if ( V_60 )
F_31 ( V_5 , V_14 , L_13 , L_14 ,
V_63 , V_64 ) ;
return V_60 ;
}
static int F_32 ( struct V_7 * V_5 ,
struct V_8 * V_9 )
{
int V_60 = 0 ;
struct V_16 * V_4 = & V_5 -> V_4 ;
struct V_21 * V_25 ;
struct V_1 * V_2 ;
T_3 V_69 ;
T_4 V_70 = 0 ;
T_2 V_71 ;
T_1 V_22 ;
bool V_72 ;
V_25 = (struct V_21 * ) V_9 -> V_13 ;
F_13 ( V_9 , sizeof( * V_25 ) ) ;
V_22 = V_25 -> V_22 ;
if ( V_22 >= V_40 ) {
F_15 ( V_5 , L_15 , V_22 ) ;
F_31 ( V_5 , V_14 , L_16 , L_14 ,
V_25 , sizeof( * V_25 ) ) ;
V_60 = - V_65 ;
goto V_73;
}
V_2 = & V_4 -> V_31 [ V_22 ] ;
if ( V_2 -> V_74 )
F_1 ( V_2 , 1 ) ;
V_69 = F_33 ( V_25 -> V_19 ) ;
if ( V_69 + sizeof( * V_25 ) > V_75 ) {
F_15 ( V_5 , L_17 ,
V_69 + sizeof( * V_25 ) ) ;
F_31 ( V_5 , V_14 , L_18 , L_14 ,
V_25 , sizeof( * V_25 ) ) ;
V_60 = - V_65 ;
goto V_73;
}
if ( V_9 -> V_19 < V_69 ) {
F_10 ( V_5 , V_14 ,
L_19 ,
V_9 -> V_19 , V_69 ) ;
F_31 ( V_5 , V_14 , L_18 ,
L_14 , V_25 , sizeof( * V_25 ) ) ;
V_60 = - V_65 ;
goto V_73;
}
V_72 = V_25 -> V_26 & V_76 ;
if ( V_72 ) {
T_1 * V_77 ;
V_70 = V_25 -> V_70 ;
V_71 = sizeof( struct V_78 ) ;
if ( ( V_70 < V_71 ) ||
( V_70 > V_69 ) ) {
F_15 ( V_5 , L_20 ,
V_70 ) ;
V_60 = - V_79 ;
goto V_73;
}
V_77 = ( T_1 * ) V_25 ;
V_77 += sizeof( * V_25 ) ;
V_77 += V_69 ;
V_77 -= V_70 ;
V_60 = F_30 ( V_4 , V_77 ,
V_70 , V_25 -> V_22 ) ;
if ( V_60 )
goto V_73;
F_34 ( V_9 , V_9 -> V_19 - V_70 ) ;
}
if ( ( ( int ) V_69 - ( int ) V_70 ) <= 0 )
goto V_73;
if ( V_22 == V_80 ) {
struct V_81 * V_82 = (struct V_81 * ) V_9 -> V_13 ;
switch ( F_33 ( V_82 -> V_25 . V_83 ) ) {
case V_84 :
case V_85 :
if ( F_35 ( & V_4 -> V_86 ) ) {
F_15 ( V_5 , L_21 ) ;
V_60 = - V_65 ;
F_36 ( & V_4 -> V_86 ) ;
goto V_73;
}
V_4 -> V_87 =
F_37 ( int , V_9 -> V_19 ,
V_88 ) ;
memcpy ( V_4 -> V_89 , V_9 -> V_13 ,
V_4 -> V_87 ) ;
F_36 ( & V_4 -> V_86 ) ;
break;
case V_90 :
V_4 -> V_91 . V_92 ( V_5 ) ;
break;
default:
F_15 ( V_5 , L_22 ) ;
break;
}
goto V_73;
}
F_10 ( V_5 , V_14 , L_23 ,
V_22 , V_9 ) ;
V_2 -> V_23 . V_93 ( V_5 , V_9 ) ;
V_9 = NULL ;
V_73:
F_4 ( V_9 ) ;
return V_60 ;
}
static void F_38 ( struct V_7 * V_5 ,
struct V_8 * V_9 )
{
F_15 ( V_5 , L_24 ) ;
F_4 ( V_9 ) ;
}
static const char * F_39 ( enum V_94 V_66 )
{
switch ( V_66 ) {
case V_95 :
return L_25 ;
case V_96 :
return L_26 ;
case V_97 :
return L_27 ;
case V_98 :
return L_28 ;
case V_99 :
return L_29 ;
case V_100 :
return L_30 ;
case V_101 :
return L_31 ;
case V_102 :
return L_32 ;
case V_103 :
return L_33 ;
case V_104 :
return L_34 ;
case V_105 :
return L_35 ;
}
return L_36 ;
}
static void F_40 ( struct V_16 * V_4 )
{
struct V_1 * V_2 ;
int V_55 ;
for ( V_55 = V_80 ; V_55 < V_40 ; V_55 ++ ) {
V_2 = & V_4 -> V_31 [ V_55 ] ;
V_2 -> V_106 = V_107 ;
V_2 -> V_108 = 0 ;
V_2 -> V_109 = 0 ;
V_2 -> V_22 = V_55 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_42 = true ;
}
}
static void F_41 ( struct V_16 * V_4 )
{
struct V_110 * V_111 ;
V_111 = & V_4 -> V_112 [ 0 ] ;
V_111 ++ ;
V_111 -> V_106 = V_97 ;
V_111 -> V_113 = V_4 -> V_114 ;
}
static T_1 F_42 ( struct V_16 * V_4 ,
T_3 V_106 )
{
T_1 V_115 = 0 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_40 ; V_55 ++ ) {
if ( V_4 -> V_112 [ V_55 ] . V_106 == V_106 )
V_115 =
V_4 -> V_112 [ V_55 ] . V_113 ;
}
return V_115 ;
}
int F_43 ( struct V_16 * V_4 )
{
struct V_7 * V_5 = V_4 -> V_5 ;
int V_55 , V_60 = 0 ;
unsigned long V_116 ;
struct V_117 V_118 ;
struct V_119 V_120 ;
struct V_81 * V_82 ;
T_3 V_83 ;
T_3 V_121 ;
T_3 V_122 ;
V_116 = F_44 ( & V_4 -> V_86 ,
V_123 ) ;
if ( ! V_116 ) {
F_15 ( V_5 , L_37 ) ;
for ( V_55 = 0 ; V_55 < V_124 ; V_55 ++ )
F_2 ( V_4 -> V_5 , V_55 , 1 ) ;
V_116 =
F_44 ( & V_4 -> V_86 ,
V_123 ) ;
if ( ! V_116 )
V_60 = - V_125 ;
}
if ( V_60 < 0 ) {
F_45 ( V_5 , L_38 , V_60 ) ;
return V_60 ;
}
if ( V_4 -> V_87 < sizeof( V_82 -> V_25 ) + sizeof( V_82 -> V_126 ) ) {
F_45 ( V_5 , L_39 ,
V_4 -> V_87 ) ;
return - V_39 ;
}
V_82 = (struct V_81 * ) V_4 -> V_89 ;
V_83 = F_33 ( V_82 -> V_25 . V_83 ) ;
V_121 = F_33 ( V_82 -> V_126 . V_121 ) ;
V_122 = F_33 ( V_82 -> V_126 . V_122 ) ;
if ( V_83 != V_84 ) {
F_45 ( V_5 , L_40 , V_83 ) ;
return - V_39 ;
}
V_4 -> V_114 = V_121 ;
V_4 -> V_43 = V_122 ;
F_10 ( V_5 , V_14 ,
L_41 ,
V_4 -> V_114 ,
V_4 -> V_43 ) ;
if ( ( V_4 -> V_114 == 0 ) ||
( V_4 -> V_43 == 0 ) ) {
F_45 ( V_5 , L_42 ) ;
return - V_39 ;
}
F_41 ( V_4 ) ;
memset ( & V_118 , 0 , sizeof( V_118 ) ) ;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
V_118 . V_23 . V_24 = F_3 ;
V_118 . V_23 . V_93 = F_38 ;
V_118 . V_127 = V_128 ;
V_118 . V_106 = V_96 ;
V_60 = F_46 ( V_4 , & V_118 , & V_120 ) ;
if ( V_60 ) {
F_45 ( V_5 , L_43 ,
V_60 ) ;
return V_60 ;
}
return 0 ;
}
int F_46 ( struct V_16 * V_4 ,
struct V_117 * V_118 ,
struct V_119 * V_120 )
{
struct V_7 * V_5 = V_4 -> V_5 ;
struct V_81 * V_82 ;
struct V_129 * V_130 ;
struct V_131 V_132 ;
struct V_131 * V_133 = & V_132 ;
enum V_30 V_134 = V_40 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
unsigned int V_135 = 0 ;
int V_58 , V_60 ;
unsigned long V_116 ;
bool V_136 = false ;
T_3 V_83 , V_106 , V_26 = 0 ;
T_1 V_137 = 0 ;
if ( V_118 -> V_106 == V_96 ) {
V_136 = true ;
V_134 = V_80 ;
V_135 = V_88 ;
memset ( & V_132 , 0 , sizeof( V_132 ) ) ;
goto V_138;
}
V_137 = F_42 ( V_4 ,
V_118 -> V_106 ) ;
if ( ! V_137 )
F_10 ( V_5 , V_139 ,
L_44 ,
F_39 ( V_118 -> V_106 ) ) ;
V_9 = F_5 ( V_4 -> V_5 ) ;
if ( ! V_9 ) {
F_45 ( V_5 , L_45 ) ;
return - V_140 ;
}
V_58 = sizeof( V_82 -> V_25 ) + sizeof( V_82 -> V_141 ) ;
F_47 ( V_9 , V_58 ) ;
memset ( V_9 -> V_13 , 0 , V_58 ) ;
V_82 = (struct V_81 * ) V_9 -> V_13 ;
V_82 -> V_25 . V_83 =
F_18 ( V_142 ) ;
V_26 |= F_48 ( V_137 , V_143 ) ;
if ( V_118 -> V_106 != V_97 ) {
V_26 |= V_144 ;
V_136 = true ;
}
V_130 = & V_82 -> V_141 ;
V_130 -> V_26 = F_18 ( V_26 ) ;
V_130 -> V_106 = F_18 ( V_118 -> V_106 ) ;
F_49 ( & V_4 -> V_86 ) ;
V_60 = F_21 ( V_4 , V_80 , V_9 ) ;
if ( V_60 ) {
F_4 ( V_9 ) ;
return V_60 ;
}
V_116 = F_44 ( & V_4 -> V_86 ,
V_145 ) ;
if ( ! V_116 ) {
F_45 ( V_5 , L_46 ) ;
return - V_125 ;
}
V_82 = (struct V_81 * ) V_4 -> V_89 ;
V_133 = & V_82 -> V_146 ;
V_83 = F_33 ( V_82 -> V_25 . V_83 ) ;
V_106 = F_33 ( V_133 -> V_106 ) ;
if ( ( V_83 != V_85 ) ||
( V_4 -> V_87 < sizeof( V_82 -> V_25 ) +
sizeof( V_82 -> V_146 ) ) ) {
F_45 ( V_5 , L_47 , V_83 ) ;
return - V_79 ;
}
F_10 ( V_5 , V_14 ,
L_48 ,
F_39 ( V_106 ) ,
V_133 -> V_60 , V_133 -> V_22 ) ;
V_120 -> V_147 = V_133 -> V_60 ;
if ( V_133 -> V_60 != V_148 ) {
F_45 ( V_5 , L_49 ,
F_39 ( V_106 ) ,
V_133 -> V_60 ) ;
return - V_79 ;
}
V_134 = (enum V_30 ) V_133 -> V_22 ;
V_135 = F_33 ( V_133 -> V_135 ) ;
V_138:
if ( V_134 >= V_40 )
return - V_79 ;
if ( V_135 == 0 )
return - V_79 ;
V_2 = & V_4 -> V_31 [ V_134 ] ;
V_2 -> V_22 = V_134 ;
if ( V_2 -> V_106 != V_107 )
return - V_79 ;
V_120 -> V_22 = V_134 ;
V_120 -> V_149 = F_33 ( V_133 -> V_135 ) ;
V_2 -> V_106 = V_118 -> V_106 ;
V_2 -> V_109 = V_118 -> V_127 ;
V_2 -> V_108 = F_33 ( V_133 -> V_135 ) ;
V_2 -> V_44 = V_137 ;
V_2 -> V_150 = V_4 -> V_43 ;
V_2 -> V_151 = V_2 -> V_108 /
V_4 -> V_43 ;
if ( V_2 -> V_108 % V_4 -> V_43 )
V_2 -> V_151 ++ ;
V_2 -> V_23 = V_118 -> V_23 ;
V_60 = F_50 ( V_4 -> V_5 ,
V_2 -> V_106 ,
& V_2 -> V_6 ,
& V_2 -> V_152 ,
& V_2 -> V_74 ,
& V_2 -> V_153 ) ;
if ( V_60 )
return V_60 ;
F_10 ( V_5 , V_139 ,
L_50 ,
F_39 ( V_2 -> V_106 ) , V_2 -> V_6 ,
V_2 -> V_152 , V_2 -> V_22 ) ;
F_10 ( V_5 , V_139 ,
L_51 ,
V_2 -> V_22 , V_2 -> V_74 , V_2 -> V_153 ) ;
if ( V_136 && V_2 -> V_42 ) {
V_2 -> V_42 = false ;
F_10 ( V_5 , V_139 ,
L_52 ,
F_39 ( V_2 -> V_106 ) , V_134 ) ;
}
return V_60 ;
}
struct V_8 * F_51 ( struct V_7 * V_5 , int V_154 )
{
struct V_8 * V_9 ;
V_9 = F_6 ( V_154 + sizeof( struct V_21 ) ) ;
if ( ! V_9 )
return NULL ;
F_7 ( V_9 , sizeof( struct V_21 ) ) ;
if ( ! F_52 ( ( unsigned long ) V_9 -> V_13 , 4 ) )
F_15 ( V_5 , L_53 ) ;
return V_9 ;
}
int F_53 ( struct V_16 * V_4 )
{
struct V_7 * V_5 = V_4 -> V_5 ;
struct V_8 * V_9 ;
int V_60 = 0 ;
struct V_81 * V_82 ;
V_9 = F_5 ( V_4 -> V_5 ) ;
if ( ! V_9 )
return - V_140 ;
F_47 ( V_9 , sizeof( V_82 -> V_25 ) + sizeof( V_82 -> V_155 ) ) ;
memset ( V_9 -> V_13 , 0 , V_9 -> V_19 ) ;
V_82 = (struct V_81 * ) V_9 -> V_13 ;
V_82 -> V_25 . V_83 =
F_18 ( V_156 ) ;
F_10 ( V_5 , V_14 , L_54 ) ;
V_60 = F_21 ( V_4 , V_80 , V_9 ) ;
if ( V_60 ) {
F_4 ( V_9 ) ;
return V_60 ;
}
return 0 ;
}
int F_54 ( struct V_7 * V_5 )
{
struct V_157 V_158 ;
struct V_1 * V_2 = NULL ;
struct V_16 * V_4 = & V_5 -> V_4 ;
F_55 ( & V_4 -> V_28 ) ;
F_40 ( V_4 ) ;
V_158 . V_159 = F_32 ;
V_158 . V_160 = F_27 ;
V_4 -> V_5 = V_5 ;
V_2 = & V_4 -> V_31 [ V_80 ] ;
F_56 ( V_5 , & V_158 ) ;
F_57 ( V_5 , & V_2 -> V_6 , & V_2 -> V_152 ) ;
F_58 ( & V_4 -> V_86 ) ;
return 0 ;
}
