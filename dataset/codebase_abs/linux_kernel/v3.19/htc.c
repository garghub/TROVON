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
static bool F_17 ( struct V_1 * V_2 )
{
struct V_7 * V_5 = V_2 -> V_4 -> V_5 ;
if ( ! V_2 -> V_25 )
return false ;
if ( V_2 -> V_26 >= V_2 -> V_27 )
return false ;
F_10 ( V_5 , V_14 , L_5 ,
V_2 -> V_22 ) ;
return true ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_21 * V_28 ;
V_28 = (struct V_21 * ) V_9 -> V_13 ;
V_28 -> V_22 = V_2 -> V_22 ;
V_28 -> V_19 = F_19 ( V_9 -> V_19 - sizeof( * V_28 ) ) ;
V_28 -> V_29 = 0 ;
F_20 ( & V_2 -> V_4 -> V_30 ) ;
V_28 -> V_31 = V_2 -> V_31 ++ ;
if ( F_17 ( V_2 ) )
V_28 -> V_29 |= V_32 ;
F_21 ( & V_2 -> V_4 -> V_30 ) ;
}
int F_22 ( struct V_16 * V_4 ,
enum V_33 V_22 ,
struct V_8 * V_9 )
{
struct V_7 * V_5 = V_4 -> V_5 ;
struct V_1 * V_2 = & V_4 -> V_34 [ V_22 ] ;
struct V_10 * V_11 = F_9 ( V_9 ) ;
struct V_35 V_36 ;
struct V_37 * V_17 = V_4 -> V_5 -> V_17 ;
int V_38 = 0 ;
int V_39 ;
if ( V_4 -> V_5 -> V_40 == V_41 )
return - V_42 ;
if ( V_22 >= V_43 ) {
F_15 ( V_5 , L_6 , V_22 ) ;
return - V_44 ;
}
F_23 ( V_9 , sizeof( struct V_21 ) ) ;
if ( V_2 -> V_25 ) {
V_38 = F_24 ( V_9 -> V_19 , V_4 -> V_45 ) ;
F_20 ( & V_4 -> V_30 ) ;
if ( V_2 -> V_26 < V_38 ) {
F_21 ( & V_4 -> V_30 ) ;
V_39 = - V_46 ;
goto V_47;
}
V_2 -> V_26 -= V_38 ;
F_10 ( V_5 , V_14 ,
L_7 ,
V_22 , V_38 , V_2 -> V_26 ) ;
F_21 ( & V_4 -> V_30 ) ;
}
F_18 ( V_2 , V_9 ) ;
V_11 -> V_22 = V_22 ;
V_11 -> V_18 = F_25 ( V_17 , V_9 -> V_13 , V_9 -> V_19 , V_20 ) ;
V_39 = F_26 ( V_17 , V_11 -> V_18 ) ;
if ( V_39 )
goto V_48;
V_36 . V_49 = V_2 -> V_22 ;
V_36 . V_50 = V_9 ;
V_36 . V_51 = V_9 -> V_13 ;
V_36 . V_18 = V_11 -> V_18 ;
V_36 . V_19 = V_9 -> V_19 ;
V_39 = F_27 ( V_4 -> V_5 , V_2 -> V_6 , & V_36 , 1 ) ;
if ( V_39 )
goto V_52;
return 0 ;
V_52:
F_12 ( V_17 , V_11 -> V_18 , V_9 -> V_19 , V_20 ) ;
V_48:
if ( V_2 -> V_25 ) {
F_20 ( & V_4 -> V_30 ) ;
V_2 -> V_26 += V_38 ;
F_10 ( V_5 , V_14 ,
L_8 ,
V_22 , V_38 , V_2 -> V_26 ) ;
F_21 ( & V_4 -> V_30 ) ;
if ( V_2 -> V_23 . V_53 )
V_2 -> V_23 . V_53 ( V_4 -> V_5 ) ;
}
V_47:
F_13 ( V_9 , sizeof( struct V_21 ) ) ;
return V_39 ;
}
static int F_28 ( struct V_7 * V_5 ,
struct V_8 * V_9 )
{
struct V_16 * V_4 = & V_5 -> V_4 ;
struct V_10 * V_11 ;
struct V_1 * V_2 ;
if ( F_29 ( ! V_9 ) )
return 0 ;
V_11 = F_9 ( V_9 ) ;
V_2 = & V_4 -> V_34 [ V_11 -> V_22 ] ;
F_14 ( V_2 , V_9 ) ;
return 0 ;
}
static void
F_30 ( struct V_16 * V_4 ,
const struct V_54 * V_55 ,
int V_19 ,
enum V_33 V_22 )
{
struct V_7 * V_5 = V_4 -> V_5 ;
struct V_1 * V_2 ;
int V_56 , V_57 ;
if ( V_19 % sizeof( * V_55 ) )
F_15 ( V_5 , L_9 , V_19 ) ;
V_57 = V_19 / sizeof( * V_55 ) ;
F_20 ( & V_4 -> V_30 ) ;
for ( V_56 = 0 ; V_56 < V_57 ; V_56 ++ , V_55 ++ ) {
if ( V_55 -> V_22 >= V_43 )
break;
V_2 = & V_4 -> V_34 [ V_55 -> V_22 ] ;
V_2 -> V_26 += V_55 -> V_38 ;
F_10 ( V_5 , V_14 , L_10 ,
V_55 -> V_22 , V_55 -> V_38 , V_2 -> V_26 ) ;
if ( V_2 -> V_23 . V_53 ) {
F_21 ( & V_4 -> V_30 ) ;
V_2 -> V_23 . V_53 ( V_4 -> V_5 ) ;
F_20 ( & V_4 -> V_30 ) ;
}
}
F_21 ( & V_4 -> V_30 ) ;
}
static int F_31 ( struct V_16 * V_4 ,
T_1 * V_58 ,
int V_59 ,
enum V_33 V_60 )
{
struct V_7 * V_5 = V_4 -> V_5 ;
int V_61 = 0 ;
struct V_62 * V_63 ;
T_1 * V_64 ;
int V_65 ;
T_2 V_19 ;
V_64 = V_58 ;
V_65 = V_59 ;
while ( V_59 > 0 ) {
V_63 = (struct V_62 * ) V_58 ;
if ( V_59 < sizeof( V_63 -> V_28 ) ) {
V_61 = - V_66 ;
break;
}
if ( V_63 -> V_28 . V_19 > V_59 ) {
F_15 ( V_5 , L_11 ,
V_63 -> V_28 . V_19 ) ;
V_61 = - V_66 ;
break;
}
switch ( V_63 -> V_28 . V_67 ) {
case V_68 :
V_19 = sizeof( struct V_54 ) ;
if ( V_63 -> V_28 . V_19 < V_19 ) {
F_15 ( V_5 , L_12 ) ;
V_61 = - V_66 ;
break;
}
F_30 ( V_4 ,
V_63 -> V_69 ,
V_63 -> V_28 . V_19 ,
V_60 ) ;
break;
default:
F_15 ( V_5 , L_13 ,
V_63 -> V_28 . V_67 , V_63 -> V_28 . V_19 ) ;
break;
}
if ( V_61 )
break;
V_58 += sizeof( V_63 -> V_28 ) + V_63 -> V_28 . V_19 ;
V_59 -= sizeof( V_63 -> V_28 ) + V_63 -> V_28 . V_19 ;
}
if ( V_61 )
F_32 ( V_5 , V_14 , L_14 , L_15 ,
V_64 , V_65 ) ;
return V_61 ;
}
static int F_33 ( struct V_7 * V_5 ,
struct V_8 * V_9 )
{
int V_61 = 0 ;
struct V_16 * V_4 = & V_5 -> V_4 ;
struct V_21 * V_28 ;
struct V_1 * V_2 ;
T_3 V_70 ;
T_4 V_71 = 0 ;
T_2 V_72 ;
T_1 V_22 ;
bool V_73 ;
V_28 = (struct V_21 * ) V_9 -> V_13 ;
F_13 ( V_9 , sizeof( * V_28 ) ) ;
V_22 = V_28 -> V_22 ;
if ( V_22 >= V_43 ) {
F_15 ( V_5 , L_16 , V_22 ) ;
F_32 ( V_5 , V_14 , L_17 , L_15 ,
V_28 , sizeof( * V_28 ) ) ;
V_61 = - V_66 ;
goto V_74;
}
V_2 = & V_4 -> V_34 [ V_22 ] ;
if ( V_2 -> V_75 )
F_1 ( V_2 , 1 ) ;
V_70 = F_34 ( V_28 -> V_19 ) ;
if ( V_70 + sizeof( * V_28 ) > V_76 ) {
F_15 ( V_5 , L_18 ,
V_70 + sizeof( * V_28 ) ) ;
F_32 ( V_5 , V_14 , L_19 , L_15 ,
V_28 , sizeof( * V_28 ) ) ;
V_61 = - V_66 ;
goto V_74;
}
if ( V_9 -> V_19 < V_70 ) {
F_10 ( V_5 , V_14 ,
L_20 ,
V_9 -> V_19 , V_70 ) ;
F_32 ( V_5 , V_14 , L_19 ,
L_15 , V_28 , sizeof( * V_28 ) ) ;
V_61 = - V_66 ;
goto V_74;
}
V_73 = V_28 -> V_29 & V_77 ;
if ( V_73 ) {
T_1 * V_78 ;
V_71 = V_28 -> V_71 ;
V_72 = sizeof( struct V_79 ) ;
if ( ( V_71 < V_72 ) ||
( V_71 > V_70 ) ) {
F_15 ( V_5 , L_21 ,
V_71 ) ;
V_61 = - V_80 ;
goto V_74;
}
V_78 = ( T_1 * ) V_28 ;
V_78 += sizeof( * V_28 ) ;
V_78 += V_70 ;
V_78 -= V_71 ;
V_61 = F_31 ( V_4 , V_78 ,
V_71 , V_28 -> V_22 ) ;
if ( V_61 )
goto V_74;
F_35 ( V_9 , V_9 -> V_19 - V_71 ) ;
}
if ( ( ( int ) V_70 - ( int ) V_71 ) <= 0 )
goto V_74;
if ( V_22 == V_81 ) {
struct V_82 * V_83 = (struct V_82 * ) V_9 -> V_13 ;
switch ( F_34 ( V_83 -> V_28 . V_84 ) ) {
default:
if ( F_36 ( & V_4 -> V_85 ) ) {
F_15 ( V_5 , L_22 ) ;
V_61 = - V_66 ;
F_37 ( & V_4 -> V_85 ) ;
goto V_74;
}
V_4 -> V_86 =
F_38 ( int , V_9 -> V_19 ,
V_87 ) ;
memcpy ( V_4 -> V_88 , V_9 -> V_13 ,
V_4 -> V_86 ) ;
F_37 ( & V_4 -> V_85 ) ;
break;
case V_89 :
V_4 -> V_90 . V_91 ( V_5 ) ;
}
goto V_74;
}
F_10 ( V_5 , V_14 , L_23 ,
V_22 , V_9 ) ;
V_2 -> V_23 . V_92 ( V_5 , V_9 ) ;
V_9 = NULL ;
V_74:
F_4 ( V_9 ) ;
return V_61 ;
}
static void F_39 ( struct V_7 * V_5 ,
struct V_8 * V_9 )
{
F_15 ( V_5 , L_24 ) ;
F_4 ( V_9 ) ;
}
static const char * F_40 ( enum V_93 V_67 )
{
switch ( V_67 ) {
case V_94 :
return L_25 ;
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
}
return L_36 ;
}
static void F_41 ( struct V_16 * V_4 )
{
struct V_1 * V_2 ;
int V_56 ;
for ( V_56 = V_81 ; V_56 < V_43 ; V_56 ++ ) {
V_2 = & V_4 -> V_34 [ V_56 ] ;
V_2 -> V_105 = V_106 ;
V_2 -> V_107 = 0 ;
V_2 -> V_108 = 0 ;
V_2 -> V_22 = V_56 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_25 = true ;
}
}
static void F_42 ( struct V_16 * V_4 )
{
struct V_109 * V_110 ;
V_110 = & V_4 -> V_111 [ 0 ] ;
V_110 ++ ;
V_110 -> V_105 = V_96 ;
V_110 -> V_112 = V_4 -> V_113 ;
}
static T_1 F_43 ( struct V_16 * V_4 ,
T_3 V_105 )
{
T_1 V_114 = 0 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_43 ; V_56 ++ ) {
if ( V_4 -> V_111 [ V_56 ] . V_105 == V_105 )
V_114 =
V_4 -> V_111 [ V_56 ] . V_112 ;
}
return V_114 ;
}
int F_44 ( struct V_16 * V_4 )
{
struct V_7 * V_5 = V_4 -> V_5 ;
int V_56 , V_61 = 0 ;
struct V_115 V_116 ;
struct V_117 V_118 ;
struct V_82 * V_83 ;
T_3 V_84 ;
T_3 V_119 ;
T_3 V_120 ;
V_61 = F_45 ( & V_4 -> V_85 ,
V_121 ) ;
if ( V_61 == 0 ) {
F_15 ( V_5 , L_37 ) ;
for ( V_56 = 0 ; V_56 < V_122 ; V_56 ++ )
F_2 ( V_4 -> V_5 , V_56 , 1 ) ;
V_61 = F_45 ( & V_4 -> V_85 ,
V_121 ) ;
if ( V_61 == 0 )
V_61 = - V_123 ;
}
if ( V_61 < 0 ) {
F_46 ( V_5 , L_38 , V_61 ) ;
return V_61 ;
}
if ( V_4 -> V_86 < sizeof( V_83 -> V_28 ) + sizeof( V_83 -> V_124 ) ) {
F_46 ( V_5 , L_39 ,
V_4 -> V_86 ) ;
return - V_42 ;
}
V_83 = (struct V_82 * ) V_4 -> V_88 ;
V_84 = F_34 ( V_83 -> V_28 . V_84 ) ;
V_119 = F_34 ( V_83 -> V_124 . V_119 ) ;
V_120 = F_34 ( V_83 -> V_124 . V_120 ) ;
if ( V_84 != V_125 ) {
F_46 ( V_5 , L_40 , V_84 ) ;
return - V_42 ;
}
V_4 -> V_113 = V_119 ;
V_4 -> V_45 = V_120 ;
F_10 ( V_5 , V_14 ,
L_41 ,
V_4 -> V_113 ,
V_4 -> V_45 ) ;
if ( ( V_4 -> V_113 == 0 ) ||
( V_4 -> V_45 == 0 ) ) {
F_46 ( V_5 , L_42 ) ;
return - V_42 ;
}
F_42 ( V_4 ) ;
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
memset ( & V_118 , 0 , sizeof( V_118 ) ) ;
V_116 . V_23 . V_24 = F_3 ;
V_116 . V_23 . V_92 = F_39 ;
V_116 . V_126 = V_127 ;
V_116 . V_105 = V_95 ;
V_61 = F_47 ( V_4 , & V_116 , & V_118 ) ;
if ( V_61 ) {
F_46 ( V_5 , L_43 ,
V_61 ) ;
return V_61 ;
}
return 0 ;
}
int F_47 ( struct V_16 * V_4 ,
struct V_115 * V_116 ,
struct V_117 * V_118 )
{
struct V_7 * V_5 = V_4 -> V_5 ;
struct V_82 * V_83 ;
struct V_128 * V_129 ;
struct V_130 V_131 ;
struct V_130 * V_132 = & V_131 ;
enum V_33 V_133 = V_43 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
unsigned int V_134 = 0 ;
int V_59 , V_61 ;
bool V_135 = false ;
T_3 V_84 , V_105 , V_29 = 0 ;
T_1 V_136 = 0 ;
if ( V_116 -> V_105 == V_95 ) {
V_135 = true ;
V_133 = V_81 ;
V_134 = V_87 ;
memset ( & V_131 , 0 , sizeof( V_131 ) ) ;
goto V_137;
}
V_136 = F_43 ( V_4 ,
V_116 -> V_105 ) ;
if ( ! V_136 )
F_10 ( V_5 , V_138 ,
L_44 ,
F_40 ( V_116 -> V_105 ) ) ;
V_9 = F_5 ( V_4 -> V_5 ) ;
if ( ! V_9 ) {
F_46 ( V_5 , L_45 ) ;
return - V_139 ;
}
V_59 = sizeof( V_83 -> V_28 ) + sizeof( V_83 -> V_140 ) ;
F_48 ( V_9 , V_59 ) ;
memset ( V_9 -> V_13 , 0 , V_59 ) ;
V_83 = (struct V_82 * ) V_9 -> V_13 ;
V_83 -> V_28 . V_84 =
F_19 ( V_141 ) ;
V_29 |= F_49 ( V_136 , V_142 ) ;
if ( V_116 -> V_105 != V_96 ) {
V_29 |= V_143 ;
V_135 = true ;
}
V_129 = & V_83 -> V_140 ;
V_129 -> V_29 = F_19 ( V_29 ) ;
V_129 -> V_105 = F_19 ( V_116 -> V_105 ) ;
F_50 ( & V_4 -> V_85 ) ;
V_61 = F_22 ( V_4 , V_81 , V_9 ) ;
if ( V_61 ) {
F_4 ( V_9 ) ;
return V_61 ;
}
V_61 = F_45 ( & V_4 -> V_85 ,
V_144 ) ;
if ( V_61 <= 0 ) {
if ( V_61 == 0 )
V_61 = - V_123 ;
F_46 ( V_5 , L_46 , V_61 ) ;
return V_61 ;
}
V_83 = (struct V_82 * ) V_4 -> V_88 ;
V_132 = & V_83 -> V_145 ;
V_84 = F_34 ( V_83 -> V_28 . V_84 ) ;
V_105 = F_34 ( V_132 -> V_105 ) ;
if ( ( V_84 != V_146 ) ||
( V_4 -> V_86 < sizeof( V_83 -> V_28 ) +
sizeof( V_83 -> V_145 ) ) ) {
F_46 ( V_5 , L_47 , V_84 ) ;
return - V_80 ;
}
F_10 ( V_5 , V_14 ,
L_48 ,
F_40 ( V_105 ) ,
V_132 -> V_61 , V_132 -> V_22 ) ;
V_118 -> V_147 = V_132 -> V_61 ;
if ( V_132 -> V_61 != V_148 ) {
F_46 ( V_5 , L_49 ,
F_40 ( V_105 ) ,
V_132 -> V_61 ) ;
return - V_80 ;
}
V_133 = (enum V_33 ) V_132 -> V_22 ;
V_134 = F_34 ( V_132 -> V_134 ) ;
V_137:
if ( V_133 >= V_43 )
return - V_80 ;
if ( V_134 == 0 )
return - V_80 ;
V_2 = & V_4 -> V_34 [ V_133 ] ;
V_2 -> V_22 = V_133 ;
if ( V_2 -> V_105 != V_106 )
return - V_80 ;
V_118 -> V_22 = V_133 ;
V_118 -> V_149 = F_34 ( V_132 -> V_134 ) ;
V_2 -> V_105 = V_116 -> V_105 ;
V_2 -> V_108 = V_116 -> V_126 ;
V_2 -> V_107 = F_34 ( V_132 -> V_134 ) ;
V_2 -> V_26 = V_136 ;
V_2 -> V_150 = V_4 -> V_45 ;
V_2 -> V_27 = V_2 -> V_107 /
V_4 -> V_45 ;
if ( V_2 -> V_107 % V_4 -> V_45 )
V_2 -> V_27 ++ ;
V_2 -> V_23 = V_116 -> V_23 ;
V_61 = F_51 ( V_4 -> V_5 ,
V_2 -> V_105 ,
& V_2 -> V_6 ,
& V_2 -> V_151 ,
& V_2 -> V_75 ,
& V_2 -> V_152 ) ;
if ( V_61 )
return V_61 ;
F_10 ( V_5 , V_138 ,
L_50 ,
F_40 ( V_2 -> V_105 ) , V_2 -> V_6 ,
V_2 -> V_151 , V_2 -> V_22 ) ;
F_10 ( V_5 , V_138 ,
L_51 ,
V_2 -> V_22 , V_2 -> V_75 , V_2 -> V_152 ) ;
if ( V_135 && V_2 -> V_25 ) {
V_2 -> V_25 = false ;
F_10 ( V_5 , V_138 ,
L_52 ,
F_40 ( V_2 -> V_105 ) , V_133 ) ;
}
return V_61 ;
}
struct V_8 * F_52 ( struct V_7 * V_5 , int V_153 )
{
struct V_8 * V_9 ;
V_9 = F_6 ( V_153 + sizeof( struct V_21 ) ) ;
if ( ! V_9 )
return NULL ;
F_7 ( V_9 , sizeof( struct V_21 ) ) ;
if ( ! F_53 ( ( unsigned long ) V_9 -> V_13 , 4 ) )
F_15 ( V_5 , L_53 ) ;
return V_9 ;
}
int F_54 ( struct V_16 * V_4 )
{
struct V_7 * V_5 = V_4 -> V_5 ;
struct V_8 * V_9 ;
int V_61 = 0 ;
struct V_82 * V_83 ;
V_9 = F_5 ( V_4 -> V_5 ) ;
if ( ! V_9 )
return - V_139 ;
F_48 ( V_9 , sizeof( V_83 -> V_28 ) + sizeof( V_83 -> V_154 ) ) ;
memset ( V_9 -> V_13 , 0 , V_9 -> V_19 ) ;
V_83 = (struct V_82 * ) V_9 -> V_13 ;
V_83 -> V_28 . V_84 =
F_19 ( V_155 ) ;
F_10 ( V_5 , V_14 , L_54 ) ;
V_61 = F_22 ( V_4 , V_81 , V_9 ) ;
if ( V_61 ) {
F_4 ( V_9 ) ;
return V_61 ;
}
return 0 ;
}
int F_55 ( struct V_7 * V_5 )
{
struct V_156 V_157 ;
struct V_1 * V_2 = NULL ;
struct V_16 * V_4 = & V_5 -> V_4 ;
F_56 ( & V_4 -> V_30 ) ;
F_41 ( V_4 ) ;
V_157 . V_158 = F_33 ;
V_157 . V_159 = F_28 ;
V_4 -> V_5 = V_5 ;
V_2 = & V_4 -> V_34 [ V_81 ] ;
F_57 ( V_5 , & V_157 ) ;
F_58 ( V_5 , & V_2 -> V_6 , & V_2 -> V_151 ) ;
F_59 ( & V_4 -> V_85 ) ;
return 0 ;
}
