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
if ( V_36 ) {
V_36 = - V_47 ;
goto V_48;
}
V_33 . V_49 = V_2 -> V_22 ;
V_33 . V_50 = V_9 ;
V_33 . V_51 = V_9 -> V_13 ;
V_33 . V_18 = V_11 -> V_18 ;
V_33 . V_19 = V_9 -> V_19 ;
V_36 = F_26 ( V_4 -> V_5 , V_2 -> V_6 , & V_33 , 1 ) ;
if ( V_36 )
goto V_52;
return 0 ;
V_52:
F_12 ( V_17 , V_11 -> V_18 , V_9 -> V_19 , V_20 ) ;
V_48:
if ( V_2 -> V_42 ) {
F_19 ( & V_4 -> V_28 ) ;
V_2 -> V_44 += V_35 ;
F_10 ( V_5 , V_14 ,
L_7 ,
V_22 , V_35 , V_2 -> V_44 ) ;
F_20 ( & V_4 -> V_28 ) ;
if ( V_2 -> V_23 . V_53 )
V_2 -> V_23 . V_53 ( V_4 -> V_5 ) ;
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
const struct V_54 * V_55 ,
int V_19 ,
enum V_30 V_22 )
{
struct V_7 * V_5 = V_4 -> V_5 ;
struct V_1 * V_2 ;
int V_56 , V_57 ;
if ( V_19 % sizeof( * V_55 ) )
F_15 ( V_5 , L_8 , V_19 ) ;
V_57 = V_19 / sizeof( * V_55 ) ;
F_19 ( & V_4 -> V_28 ) ;
for ( V_56 = 0 ; V_56 < V_57 ; V_56 ++ , V_55 ++ ) {
if ( V_55 -> V_22 >= V_40 )
break;
V_2 = & V_4 -> V_31 [ V_55 -> V_22 ] ;
V_2 -> V_44 += V_55 -> V_35 ;
F_10 ( V_5 , V_14 , L_9 ,
V_55 -> V_22 , V_55 -> V_35 , V_2 -> V_44 ) ;
if ( V_2 -> V_23 . V_53 ) {
F_20 ( & V_4 -> V_28 ) ;
V_2 -> V_23 . V_53 ( V_4 -> V_5 ) ;
F_19 ( & V_4 -> V_28 ) ;
}
}
F_20 ( & V_4 -> V_28 ) ;
}
static int F_30 ( struct V_16 * V_4 ,
T_1 * V_58 ,
int V_59 ,
enum V_30 V_60 )
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
if ( V_59 < sizeof( V_63 -> V_25 ) ) {
V_61 = - V_66 ;
break;
}
if ( V_63 -> V_25 . V_19 > V_59 ) {
F_15 ( V_5 , L_10 ,
V_63 -> V_25 . V_19 ) ;
V_61 = - V_66 ;
break;
}
switch ( V_63 -> V_25 . V_67 ) {
case V_68 :
V_19 = sizeof( struct V_54 ) ;
if ( V_63 -> V_25 . V_19 < V_19 ) {
F_15 ( V_5 , L_11 ) ;
V_61 = - V_66 ;
break;
}
F_29 ( V_4 ,
V_63 -> V_69 ,
V_63 -> V_25 . V_19 ,
V_60 ) ;
break;
default:
F_15 ( V_5 , L_12 ,
V_63 -> V_25 . V_67 , V_63 -> V_25 . V_19 ) ;
break;
}
if ( V_61 )
break;
V_58 += sizeof( V_63 -> V_25 ) + V_63 -> V_25 . V_19 ;
V_59 -= sizeof( V_63 -> V_25 ) + V_63 -> V_25 . V_19 ;
}
if ( V_61 )
F_31 ( V_5 , V_14 , L_13 , L_14 ,
V_64 , V_65 ) ;
return V_61 ;
}
static int F_32 ( struct V_7 * V_5 ,
struct V_8 * V_9 )
{
int V_61 = 0 ;
struct V_16 * V_4 = & V_5 -> V_4 ;
struct V_21 * V_25 ;
struct V_1 * V_2 ;
T_3 V_70 ;
T_4 V_71 = 0 ;
T_2 V_72 ;
T_1 V_22 ;
bool V_73 ;
V_25 = (struct V_21 * ) V_9 -> V_13 ;
F_13 ( V_9 , sizeof( * V_25 ) ) ;
V_22 = V_25 -> V_22 ;
if ( V_22 >= V_40 ) {
F_15 ( V_5 , L_15 , V_22 ) ;
F_31 ( V_5 , V_14 , L_16 , L_14 ,
V_25 , sizeof( * V_25 ) ) ;
V_61 = - V_66 ;
goto V_74;
}
V_2 = & V_4 -> V_31 [ V_22 ] ;
if ( V_2 -> V_75 )
F_1 ( V_2 , 1 ) ;
V_70 = F_33 ( V_25 -> V_19 ) ;
if ( V_70 + sizeof( * V_25 ) > V_76 ) {
F_15 ( V_5 , L_17 ,
V_70 + sizeof( * V_25 ) ) ;
F_31 ( V_5 , V_14 , L_18 , L_14 ,
V_25 , sizeof( * V_25 ) ) ;
V_61 = - V_66 ;
goto V_74;
}
if ( V_9 -> V_19 < V_70 ) {
F_10 ( V_5 , V_14 ,
L_19 ,
V_9 -> V_19 , V_70 ) ;
F_31 ( V_5 , V_14 , L_18 ,
L_14 , V_25 , sizeof( * V_25 ) ) ;
V_61 = - V_66 ;
goto V_74;
}
V_73 = V_25 -> V_26 & V_77 ;
if ( V_73 ) {
T_1 * V_78 ;
V_71 = V_25 -> V_71 ;
V_72 = sizeof( struct V_79 ) ;
if ( ( V_71 < V_72 ) ||
( V_71 > V_70 ) ) {
F_15 ( V_5 , L_20 ,
V_71 ) ;
V_61 = - V_80 ;
goto V_74;
}
V_78 = ( T_1 * ) V_25 ;
V_78 += sizeof( * V_25 ) ;
V_78 += V_70 ;
V_78 -= V_71 ;
V_61 = F_30 ( V_4 , V_78 ,
V_71 , V_25 -> V_22 ) ;
if ( V_61 )
goto V_74;
F_34 ( V_9 , V_9 -> V_19 - V_71 ) ;
}
if ( ( ( int ) V_70 - ( int ) V_71 ) <= 0 )
goto V_74;
if ( V_22 == V_81 ) {
struct V_82 * V_83 = (struct V_82 * ) V_9 -> V_13 ;
switch ( F_33 ( V_83 -> V_25 . V_84 ) ) {
case V_85 :
case V_86 :
if ( F_35 ( & V_4 -> V_87 ) ) {
F_15 ( V_5 , L_21 ) ;
V_61 = - V_66 ;
F_36 ( & V_4 -> V_87 ) ;
goto V_74;
}
V_4 -> V_88 =
F_37 ( int , V_9 -> V_19 ,
V_89 ) ;
memcpy ( V_4 -> V_90 , V_9 -> V_13 ,
V_4 -> V_88 ) ;
F_36 ( & V_4 -> V_87 ) ;
break;
case V_91 :
V_4 -> V_92 . V_93 ( V_5 ) ;
break;
default:
F_15 ( V_5 , L_22 ) ;
break;
}
goto V_74;
}
F_10 ( V_5 , V_14 , L_23 ,
V_22 , V_9 ) ;
V_2 -> V_23 . V_94 ( V_5 , V_9 ) ;
V_9 = NULL ;
V_74:
F_4 ( V_9 ) ;
return V_61 ;
}
static void F_38 ( struct V_7 * V_5 ,
struct V_8 * V_9 )
{
F_15 ( V_5 , L_24 ) ;
F_4 ( V_9 ) ;
}
static const char * F_39 ( enum V_95 V_67 )
{
switch ( V_67 ) {
case V_96 :
return L_25 ;
case V_97 :
return L_26 ;
case V_98 :
return L_27 ;
case V_99 :
return L_28 ;
case V_100 :
return L_29 ;
case V_101 :
return L_30 ;
case V_102 :
return L_31 ;
case V_103 :
return L_32 ;
case V_104 :
return L_33 ;
case V_105 :
return L_34 ;
case V_106 :
return L_35 ;
}
return L_36 ;
}
static void F_40 ( struct V_16 * V_4 )
{
struct V_1 * V_2 ;
int V_56 ;
for ( V_56 = V_81 ; V_56 < V_40 ; V_56 ++ ) {
V_2 = & V_4 -> V_31 [ V_56 ] ;
V_2 -> V_107 = V_108 ;
V_2 -> V_109 = 0 ;
V_2 -> V_110 = 0 ;
V_2 -> V_22 = V_56 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_42 = true ;
}
}
static void F_41 ( struct V_16 * V_4 )
{
struct V_111 * V_112 ;
V_112 = & V_4 -> V_113 [ 0 ] ;
V_112 ++ ;
V_112 -> V_107 = V_98 ;
V_112 -> V_114 = V_4 -> V_115 ;
}
static T_1 F_42 ( struct V_16 * V_4 ,
T_3 V_107 )
{
T_1 V_116 = 0 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_40 ; V_56 ++ ) {
if ( V_4 -> V_113 [ V_56 ] . V_107 == V_107 )
V_116 =
V_4 -> V_113 [ V_56 ] . V_114 ;
}
return V_116 ;
}
int F_43 ( struct V_16 * V_4 )
{
struct V_7 * V_5 = V_4 -> V_5 ;
int V_56 , V_61 = 0 ;
unsigned long V_117 ;
struct V_118 V_119 ;
struct V_120 V_121 ;
struct V_82 * V_83 ;
T_3 V_84 ;
T_3 V_122 ;
T_3 V_123 ;
V_117 = F_44 ( & V_4 -> V_87 ,
V_124 ) ;
if ( ! V_117 ) {
F_15 ( V_5 , L_37 ) ;
for ( V_56 = 0 ; V_56 < V_125 ; V_56 ++ )
F_2 ( V_4 -> V_5 , V_56 , 1 ) ;
V_117 =
F_44 ( & V_4 -> V_87 ,
V_124 ) ;
if ( ! V_117 )
V_61 = - V_126 ;
}
if ( V_61 < 0 ) {
F_45 ( V_5 , L_38 , V_61 ) ;
return V_61 ;
}
if ( V_4 -> V_88 < sizeof( V_83 -> V_25 ) + sizeof( V_83 -> V_127 ) ) {
F_45 ( V_5 , L_39 ,
V_4 -> V_88 ) ;
return - V_39 ;
}
V_83 = (struct V_82 * ) V_4 -> V_90 ;
V_84 = F_33 ( V_83 -> V_25 . V_84 ) ;
V_122 = F_33 ( V_83 -> V_127 . V_122 ) ;
V_123 = F_33 ( V_83 -> V_127 . V_123 ) ;
if ( V_84 != V_85 ) {
F_45 ( V_5 , L_40 , V_84 ) ;
return - V_39 ;
}
V_4 -> V_115 = V_122 ;
V_4 -> V_43 = V_123 ;
F_10 ( V_5 , V_14 ,
L_41 ,
V_4 -> V_115 ,
V_4 -> V_43 ) ;
if ( ( V_4 -> V_115 == 0 ) ||
( V_4 -> V_43 == 0 ) ) {
F_45 ( V_5 , L_42 ) ;
return - V_39 ;
}
F_41 ( V_4 ) ;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
V_119 . V_23 . V_24 = F_3 ;
V_119 . V_23 . V_94 = F_38 ;
V_119 . V_128 = V_129 ;
V_119 . V_107 = V_97 ;
V_61 = F_46 ( V_4 , & V_119 , & V_121 ) ;
if ( V_61 ) {
F_45 ( V_5 , L_43 ,
V_61 ) ;
return V_61 ;
}
return 0 ;
}
int F_46 ( struct V_16 * V_4 ,
struct V_118 * V_119 ,
struct V_120 * V_121 )
{
struct V_7 * V_5 = V_4 -> V_5 ;
struct V_82 * V_83 ;
struct V_130 * V_131 ;
struct V_132 V_133 ;
struct V_132 * V_134 = & V_133 ;
enum V_30 V_135 = V_40 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
unsigned int V_136 = 0 ;
int V_59 , V_61 ;
unsigned long V_117 ;
bool V_137 = false ;
T_3 V_84 , V_107 , V_26 = 0 ;
T_1 V_138 = 0 ;
if ( V_119 -> V_107 == V_97 ) {
V_137 = true ;
V_135 = V_81 ;
V_136 = V_89 ;
memset ( & V_133 , 0 , sizeof( V_133 ) ) ;
goto V_139;
}
V_138 = F_42 ( V_4 ,
V_119 -> V_107 ) ;
if ( ! V_138 )
F_10 ( V_5 , V_140 ,
L_44 ,
F_39 ( V_119 -> V_107 ) ) ;
V_9 = F_5 ( V_4 -> V_5 ) ;
if ( ! V_9 ) {
F_45 ( V_5 , L_45 ) ;
return - V_141 ;
}
V_59 = sizeof( V_83 -> V_25 ) + sizeof( V_83 -> V_142 ) ;
F_47 ( V_9 , V_59 ) ;
memset ( V_9 -> V_13 , 0 , V_59 ) ;
V_83 = (struct V_82 * ) V_9 -> V_13 ;
V_83 -> V_25 . V_84 =
F_18 ( V_143 ) ;
V_26 |= F_48 ( V_138 , V_144 ) ;
if ( V_119 -> V_107 != V_98 ) {
V_26 |= V_145 ;
V_137 = true ;
}
V_131 = & V_83 -> V_142 ;
V_131 -> V_26 = F_18 ( V_26 ) ;
V_131 -> V_107 = F_18 ( V_119 -> V_107 ) ;
F_49 ( & V_4 -> V_87 ) ;
V_61 = F_21 ( V_4 , V_81 , V_9 ) ;
if ( V_61 ) {
F_4 ( V_9 ) ;
return V_61 ;
}
V_117 = F_44 ( & V_4 -> V_87 ,
V_146 ) ;
if ( ! V_117 ) {
F_45 ( V_5 , L_46 ) ;
return - V_126 ;
}
V_83 = (struct V_82 * ) V_4 -> V_90 ;
V_134 = & V_83 -> V_147 ;
V_84 = F_33 ( V_83 -> V_25 . V_84 ) ;
V_107 = F_33 ( V_134 -> V_107 ) ;
if ( ( V_84 != V_86 ) ||
( V_4 -> V_88 < sizeof( V_83 -> V_25 ) +
sizeof( V_83 -> V_147 ) ) ) {
F_45 ( V_5 , L_47 , V_84 ) ;
return - V_80 ;
}
F_10 ( V_5 , V_14 ,
L_48 ,
F_39 ( V_107 ) ,
V_134 -> V_61 , V_134 -> V_22 ) ;
V_121 -> V_148 = V_134 -> V_61 ;
if ( V_134 -> V_61 != V_149 ) {
F_45 ( V_5 , L_49 ,
F_39 ( V_107 ) ,
V_134 -> V_61 ) ;
return - V_80 ;
}
V_135 = (enum V_30 ) V_134 -> V_22 ;
V_136 = F_33 ( V_134 -> V_136 ) ;
V_139:
if ( V_135 >= V_40 )
return - V_80 ;
if ( V_136 == 0 )
return - V_80 ;
V_2 = & V_4 -> V_31 [ V_135 ] ;
V_2 -> V_22 = V_135 ;
if ( V_2 -> V_107 != V_108 )
return - V_80 ;
V_121 -> V_22 = V_135 ;
V_121 -> V_150 = F_33 ( V_134 -> V_136 ) ;
V_2 -> V_107 = V_119 -> V_107 ;
V_2 -> V_110 = V_119 -> V_128 ;
V_2 -> V_109 = F_33 ( V_134 -> V_136 ) ;
V_2 -> V_44 = V_138 ;
V_2 -> V_151 = V_4 -> V_43 ;
V_2 -> V_152 = V_2 -> V_109 /
V_4 -> V_43 ;
if ( V_2 -> V_109 % V_4 -> V_43 )
V_2 -> V_152 ++ ;
V_2 -> V_23 = V_119 -> V_23 ;
V_61 = F_50 ( V_4 -> V_5 ,
V_2 -> V_107 ,
& V_2 -> V_6 ,
& V_2 -> V_153 ,
& V_2 -> V_75 ,
& V_2 -> V_154 ) ;
if ( V_61 )
return V_61 ;
F_10 ( V_5 , V_140 ,
L_50 ,
F_39 ( V_2 -> V_107 ) , V_2 -> V_6 ,
V_2 -> V_153 , V_2 -> V_22 ) ;
F_10 ( V_5 , V_140 ,
L_51 ,
V_2 -> V_22 , V_2 -> V_75 , V_2 -> V_154 ) ;
if ( V_137 && V_2 -> V_42 ) {
V_2 -> V_42 = false ;
F_10 ( V_5 , V_140 ,
L_52 ,
F_39 ( V_2 -> V_107 ) , V_135 ) ;
}
return V_61 ;
}
struct V_8 * F_51 ( struct V_7 * V_5 , int V_155 )
{
struct V_8 * V_9 ;
V_9 = F_6 ( V_155 + sizeof( struct V_21 ) ) ;
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
int V_61 = 0 ;
struct V_82 * V_83 ;
V_9 = F_5 ( V_4 -> V_5 ) ;
if ( ! V_9 )
return - V_141 ;
F_47 ( V_9 , sizeof( V_83 -> V_25 ) + sizeof( V_83 -> V_156 ) ) ;
memset ( V_9 -> V_13 , 0 , V_9 -> V_19 ) ;
V_83 = (struct V_82 * ) V_9 -> V_13 ;
V_83 -> V_25 . V_84 =
F_18 ( V_157 ) ;
F_10 ( V_5 , V_14 , L_54 ) ;
V_61 = F_21 ( V_4 , V_81 , V_9 ) ;
if ( V_61 ) {
F_4 ( V_9 ) ;
return V_61 ;
}
return 0 ;
}
int F_54 ( struct V_7 * V_5 )
{
struct V_158 V_159 ;
struct V_1 * V_2 = NULL ;
struct V_16 * V_4 = & V_5 -> V_4 ;
F_55 ( & V_4 -> V_28 ) ;
F_40 ( V_4 ) ;
V_159 . V_160 = F_32 ;
V_159 . V_161 = F_27 ;
V_4 -> V_5 = V_5 ;
V_2 = & V_4 -> V_31 [ V_81 ] ;
F_56 ( V_5 , & V_159 ) ;
F_57 ( V_5 , & V_2 -> V_6 , & V_2 -> V_153 ) ;
F_58 ( & V_4 -> V_87 ) ;
return 0 ;
}
