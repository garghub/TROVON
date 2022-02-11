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
V_25 -> V_19 = V_2 -> V_19 ;
V_25 -> V_26 = F_19 ( V_9 -> V_26 - sizeof( * V_25 ) ) ;
V_25 -> V_27 = 0 ;
F_20 ( & V_2 -> V_4 -> V_28 ) ;
V_25 -> V_29 = V_2 -> V_29 ++ ;
if ( F_17 ( V_2 ) )
V_25 -> V_27 |= V_30 ;
F_21 ( & V_2 -> V_4 -> V_28 ) ;
}
int F_22 ( struct V_16 * V_4 ,
enum V_31 V_19 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = & V_4 -> V_32 [ V_19 ] ;
int V_33 = 0 ;
int V_34 ;
if ( V_4 -> V_5 -> V_35 == V_36 )
return - V_37 ;
if ( V_19 >= V_38 ) {
F_7 ( L_7 , V_19 ) ;
return - V_39 ;
}
F_20 ( & V_4 -> V_28 ) ;
if ( V_4 -> V_40 ) {
F_21 ( & V_4 -> V_28 ) ;
return - V_41 ;
}
F_21 ( & V_4 -> V_28 ) ;
F_23 ( V_9 , sizeof( struct V_18 ) ) ;
if ( V_2 -> V_22 ) {
V_33 = F_24 ( V_9 -> V_26 , V_4 -> V_42 ) ;
F_20 ( & V_4 -> V_28 ) ;
if ( V_2 -> V_23 < V_33 ) {
F_21 ( & V_4 -> V_28 ) ;
V_34 = - V_43 ;
goto V_44;
}
V_2 -> V_23 -= V_33 ;
F_21 ( & V_4 -> V_28 ) ;
}
F_18 ( V_2 , V_9 ) ;
V_34 = F_25 ( V_4 -> V_5 -> V_17 , V_9 ) ;
if ( V_34 )
goto V_45;
V_34 = F_26 ( V_4 -> V_5 , V_2 -> V_6 , V_2 -> V_19 ,
V_9 -> V_26 , V_9 ) ;
if ( V_34 )
goto V_46;
return 0 ;
V_46:
F_13 ( V_4 -> V_5 -> V_17 , V_9 ) ;
V_45:
if ( V_2 -> V_22 ) {
F_20 ( & V_4 -> V_28 ) ;
V_2 -> V_23 += V_33 ;
F_21 ( & V_4 -> V_28 ) ;
if ( V_2 -> V_20 . V_47 )
V_2 -> V_20 . V_47 ( V_4 -> V_5 ) ;
}
V_44:
F_14 ( V_9 , sizeof( struct V_18 ) ) ;
return V_34 ;
}
static int F_27 ( struct V_7 * V_5 ,
struct V_8 * V_9 ,
unsigned int V_19 )
{
struct V_16 * V_4 = & V_5 -> V_4 ;
struct V_1 * V_2 = & V_4 -> V_32 [ V_19 ] ;
F_15 ( V_2 , V_9 ) ;
return 0 ;
}
static void
F_28 ( struct V_16 * V_4 ,
const struct V_48 * V_49 ,
int V_26 ,
enum V_31 V_19 )
{
struct V_1 * V_2 ;
int V_50 , V_51 ;
if ( V_26 % sizeof( * V_49 ) )
F_7 ( L_8 , V_26 ) ;
V_51 = V_26 / sizeof( * V_49 ) ;
F_20 ( & V_4 -> V_28 ) ;
for ( V_50 = 0 ; V_50 < V_51 ; V_50 ++ , V_49 ++ ) {
if ( V_49 -> V_19 >= V_38 )
break;
F_11 ( V_14 , L_9 ,
V_49 -> V_19 , V_49 -> V_33 ) ;
V_2 = & V_4 -> V_32 [ V_49 -> V_19 ] ;
V_2 -> V_23 += V_49 -> V_33 ;
if ( V_2 -> V_20 . V_47 ) {
F_21 ( & V_4 -> V_28 ) ;
V_2 -> V_20 . V_47 ( V_4 -> V_5 ) ;
F_20 ( & V_4 -> V_28 ) ;
}
}
F_21 ( & V_4 -> V_28 ) ;
}
static int F_29 ( struct V_16 * V_4 ,
T_1 * V_52 ,
int V_53 ,
enum V_31 V_54 )
{
int V_55 = 0 ;
struct V_56 * V_57 ;
T_1 * V_58 ;
int V_59 ;
T_2 V_26 ;
V_58 = V_52 ;
V_59 = V_53 ;
while ( V_53 > 0 ) {
V_57 = (struct V_56 * ) V_52 ;
if ( V_53 < sizeof( V_57 -> V_25 ) ) {
V_55 = - V_60 ;
break;
}
if ( V_57 -> V_25 . V_26 > V_53 ) {
F_7 ( L_10 ,
V_57 -> V_25 . V_26 ) ;
V_55 = - V_60 ;
break;
}
switch ( V_57 -> V_25 . V_61 ) {
case V_62 :
V_26 = sizeof( struct V_48 ) ;
if ( V_57 -> V_25 . V_26 < V_26 ) {
F_7 ( L_11 ) ;
V_55 = - V_60 ;
break;
}
F_28 ( V_4 ,
V_57 -> V_63 ,
V_57 -> V_25 . V_26 ,
V_54 ) ;
break;
default:
F_7 ( L_12 ,
V_57 -> V_25 . V_61 , V_57 -> V_25 . V_26 ) ;
break;
}
if ( V_55 )
break;
V_52 += sizeof( V_57 -> V_25 ) + V_57 -> V_25 . V_26 ;
V_53 -= sizeof( V_57 -> V_25 ) + V_57 -> V_25 . V_26 ;
}
if ( V_55 )
F_30 ( V_14 , L_13 , L_14 ,
V_58 , V_59 ) ;
return V_55 ;
}
static int F_31 ( struct V_7 * V_5 ,
struct V_8 * V_9 ,
T_1 V_64 )
{
int V_55 = 0 ;
struct V_16 * V_4 = & V_5 -> V_4 ;
struct V_18 * V_25 ;
struct V_1 * V_2 ;
T_3 V_65 ;
T_4 V_66 = 0 ;
T_2 V_67 ;
T_1 V_19 ;
bool V_68 ;
V_25 = (struct V_18 * ) V_9 -> V_13 ;
F_14 ( V_9 , sizeof( * V_25 ) ) ;
V_19 = V_25 -> V_19 ;
if ( V_19 >= V_38 ) {
F_7 ( L_15 , V_19 ) ;
F_30 ( V_14 , L_16 , L_14 ,
V_25 , sizeof( * V_25 ) ) ;
V_55 = - V_60 ;
goto V_69;
}
V_2 = & V_4 -> V_32 [ V_19 ] ;
if ( V_2 -> V_70 )
F_1 ( V_2 , 1 ) ;
V_65 = F_32 ( V_25 -> V_26 ) ;
if ( V_65 + sizeof( * V_25 ) > V_71 ) {
F_7 ( L_17 ,
V_65 + sizeof( * V_25 ) ) ;
F_30 ( V_14 , L_18 , L_14 ,
V_25 , sizeof( * V_25 ) ) ;
V_55 = - V_60 ;
goto V_69;
}
if ( V_9 -> V_26 < V_65 ) {
F_11 ( V_14 ,
L_19 ,
V_9 -> V_26 , V_65 ) ;
F_30 ( V_14 , L_18 ,
L_14 , V_25 , sizeof( * V_25 ) ) ;
V_55 = - V_60 ;
goto V_69;
}
V_68 = V_25 -> V_27 & V_72 ;
if ( V_68 ) {
T_1 * V_73 ;
V_66 = V_25 -> V_66 ;
V_67 = sizeof( struct V_74 ) ;
if ( ( V_66 < V_67 ) ||
( V_66 > V_65 ) ) {
F_7 ( L_20 ,
V_66 ) ;
V_55 = - V_75 ;
goto V_69;
}
V_73 = ( T_1 * ) V_25 ;
V_73 += sizeof( * V_25 ) ;
V_73 += V_65 ;
V_73 -= V_66 ;
V_55 = F_29 ( V_4 , V_73 ,
V_66 , V_25 -> V_19 ) ;
if ( V_55 )
goto V_69;
F_33 ( V_9 , V_9 -> V_26 - V_66 ) ;
}
if ( ( ( int ) V_65 - ( int ) V_66 ) <= 0 )
goto V_69;
if ( V_19 == V_76 ) {
struct V_77 * V_78 = (struct V_77 * ) V_9 -> V_13 ;
switch ( F_32 ( V_78 -> V_25 . V_79 ) ) {
default:
if ( F_34 ( & V_4 -> V_80 ) ) {
F_7 ( L_21 ) ;
V_55 = - V_60 ;
F_35 ( & V_4 -> V_80 ) ;
goto V_69;
}
V_4 -> V_81 =
F_36 ( int , V_9 -> V_26 ,
V_82 ) ;
memcpy ( V_4 -> V_83 , V_9 -> V_13 ,
V_4 -> V_81 ) ;
F_35 ( & V_4 -> V_80 ) ;
break;
case V_84 :
V_4 -> V_85 . V_86 ( V_5 ) ;
}
goto V_69;
}
F_11 ( V_14 , L_22 ,
V_19 , V_9 ) ;
V_2 -> V_20 . V_87 ( V_5 , V_9 ) ;
V_9 = NULL ;
V_69:
F_4 ( V_9 ) ;
return V_55 ;
}
static void F_37 ( struct V_7 * V_5 ,
struct V_8 * V_9 )
{
F_7 ( L_23 ) ;
F_4 ( V_9 ) ;
}
static const char * F_38 ( enum V_88 V_61 )
{
switch ( V_61 ) {
case V_89 :
return L_24 ;
case V_90 :
return L_25 ;
case V_91 :
return L_26 ;
case V_92 :
return L_27 ;
case V_93 :
return L_28 ;
case V_94 :
return L_29 ;
case V_95 :
return L_30 ;
case V_96 :
return L_31 ;
case V_97 :
return L_32 ;
case V_98 :
return L_33 ;
case V_99 :
return L_34 ;
}
return L_35 ;
}
static void F_39 ( struct V_16 * V_4 )
{
struct V_1 * V_2 ;
int V_50 ;
for ( V_50 = V_76 ; V_50 < V_38 ; V_50 ++ ) {
V_2 = & V_4 -> V_32 [ V_50 ] ;
V_2 -> V_100 = V_101 ;
V_2 -> V_102 = 0 ;
V_2 -> V_103 = 0 ;
V_2 -> V_19 = V_50 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_22 = true ;
}
}
static void F_40 ( struct V_16 * V_4 )
{
struct V_104 * V_105 ;
V_105 = & V_4 -> V_106 [ 0 ] ;
V_105 ++ ;
V_105 -> V_100 = V_91 ;
V_105 -> V_107 = V_4 -> V_108 ;
}
static T_1 F_41 ( struct V_16 * V_4 ,
T_3 V_100 )
{
T_1 V_109 = 0 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_38 ; V_50 ++ ) {
if ( V_4 -> V_106 [ V_50 ] . V_100 == V_100 )
V_109 =
V_4 -> V_106 [ V_50 ] . V_107 ;
}
return V_109 ;
}
int F_42 ( struct V_16 * V_4 )
{
int V_55 = 0 ;
struct V_110 V_111 ;
struct V_112 V_113 ;
struct V_77 * V_78 ;
T_3 V_79 ;
T_3 V_114 ;
T_3 V_115 ;
F_43 ( & V_4 -> V_80 ) ;
V_55 = F_44 ( V_4 -> V_5 ) ;
if ( V_55 ) {
F_45 ( L_36 , V_55 ) ;
goto V_116;
}
V_55 = F_46 ( & V_4 -> V_80 ,
V_117 ) ;
if ( V_55 <= 0 ) {
if ( V_55 == 0 )
V_55 = - V_118 ;
F_45 ( L_37 , V_55 ) ;
goto V_119;
}
if ( V_4 -> V_81 < sizeof( V_78 -> V_25 ) + sizeof( V_78 -> V_120 ) ) {
F_45 ( L_38 ,
V_4 -> V_81 ) ;
V_55 = - V_37 ;
goto V_119;
}
V_78 = (struct V_77 * ) V_4 -> V_83 ;
V_79 = F_32 ( V_78 -> V_25 . V_79 ) ;
V_114 = F_32 ( V_78 -> V_120 . V_114 ) ;
V_115 = F_32 ( V_78 -> V_120 . V_115 ) ;
if ( V_79 != V_121 ) {
F_45 ( L_39 , V_79 ) ;
V_55 = - V_37 ;
goto V_119;
}
V_4 -> V_108 = V_114 ;
V_4 -> V_42 = V_115 ;
F_11 ( V_14 ,
L_40 ,
V_4 -> V_108 ,
V_4 -> V_42 ) ;
if ( ( V_4 -> V_108 == 0 ) ||
( V_4 -> V_42 == 0 ) ) {
V_55 = - V_37 ;
F_45 ( L_41 ) ;
goto V_119;
}
F_40 ( V_4 ) ;
memset ( & V_111 , 0 , sizeof( V_111 ) ) ;
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
V_111 . V_20 . V_21 = F_3 ;
V_111 . V_20 . V_87 = F_37 ;
V_111 . V_122 = V_123 ;
V_111 . V_100 = V_90 ;
V_55 = F_47 ( V_4 , & V_111 , & V_113 ) ;
if ( V_55 ) {
F_45 ( L_42 , V_55 ) ;
goto V_119;
}
return 0 ;
V_119:
F_48 ( V_4 -> V_5 ) ;
V_116:
return V_55 ;
}
int F_47 ( struct V_16 * V_4 ,
struct V_110 * V_111 ,
struct V_112 * V_113 )
{
struct V_77 * V_78 ;
struct V_124 * V_125 ;
struct V_126 V_127 ;
struct V_126 * V_128 = & V_127 ;
enum V_31 V_129 = V_38 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
unsigned int V_130 = 0 ;
int V_53 , V_55 ;
bool V_131 = false ;
T_3 V_79 , V_100 , V_27 = 0 ;
T_1 V_132 = 0 ;
if ( V_111 -> V_100 == V_90 ) {
V_131 = true ;
V_129 = V_76 ;
V_130 = V_82 ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
goto V_133;
}
V_132 = F_41 ( V_4 ,
V_111 -> V_100 ) ;
if ( ! V_132 )
F_11 ( V_134 ,
L_43 ,
F_38 ( V_111 -> V_100 ) ) ;
V_9 = F_5 ( V_4 -> V_5 ) ;
if ( ! V_9 ) {
F_45 ( L_44 ) ;
return - V_135 ;
}
V_53 = sizeof( V_78 -> V_25 ) + sizeof( V_78 -> V_136 ) ;
F_49 ( V_9 , V_53 ) ;
memset ( V_9 -> V_13 , 0 , V_53 ) ;
V_78 = (struct V_77 * ) V_9 -> V_13 ;
V_78 -> V_25 . V_79 =
F_19 ( V_137 ) ;
V_27 |= F_50 ( V_132 , V_138 ) ;
if ( V_111 -> V_100 != V_91 ) {
V_27 |= V_139 ;
V_131 = true ;
}
V_125 = & V_78 -> V_136 ;
V_125 -> V_27 = F_19 ( V_27 ) ;
V_125 -> V_100 = F_19 ( V_111 -> V_100 ) ;
F_43 ( & V_4 -> V_80 ) ;
V_55 = F_22 ( V_4 , V_76 , V_9 ) ;
if ( V_55 ) {
F_4 ( V_9 ) ;
return V_55 ;
}
V_55 = F_46 ( & V_4 -> V_80 ,
V_140 ) ;
if ( V_55 <= 0 ) {
if ( V_55 == 0 )
V_55 = - V_118 ;
F_45 ( L_45 , V_55 ) ;
return V_55 ;
}
V_78 = (struct V_77 * ) V_4 -> V_83 ;
V_128 = & V_78 -> V_141 ;
V_79 = F_32 ( V_78 -> V_25 . V_79 ) ;
V_100 = F_32 ( V_128 -> V_100 ) ;
if ( ( V_79 != V_142 ) ||
( V_4 -> V_81 < sizeof( V_78 -> V_25 ) +
sizeof( V_78 -> V_141 ) ) ) {
F_45 ( L_46 , V_79 ) ;
return - V_75 ;
}
F_11 ( V_14 ,
L_47 ,
F_38 ( V_100 ) ,
V_128 -> V_55 , V_128 -> V_19 ) ;
V_113 -> V_143 = V_128 -> V_55 ;
if ( V_128 -> V_55 != V_144 ) {
F_45 ( L_48 ,
F_38 ( V_100 ) ,
V_128 -> V_55 ) ;
return - V_75 ;
}
V_129 = (enum V_31 ) V_128 -> V_19 ;
V_130 = F_32 ( V_128 -> V_130 ) ;
V_133:
if ( V_129 >= V_38 )
return - V_75 ;
if ( V_130 == 0 )
return - V_75 ;
V_2 = & V_4 -> V_32 [ V_129 ] ;
V_2 -> V_19 = V_129 ;
if ( V_2 -> V_100 != V_101 )
return - V_75 ;
V_113 -> V_19 = V_129 ;
V_113 -> V_145 = F_32 ( V_128 -> V_130 ) ;
V_2 -> V_100 = V_111 -> V_100 ;
V_2 -> V_103 = V_111 -> V_122 ;
V_2 -> V_102 = F_32 ( V_128 -> V_130 ) ;
V_2 -> V_23 = V_132 ;
V_2 -> V_146 = V_4 -> V_42 ;
V_2 -> V_24 = V_2 -> V_102 /
V_4 -> V_42 ;
if ( V_2 -> V_102 % V_4 -> V_42 )
V_2 -> V_24 ++ ;
V_2 -> V_20 = V_111 -> V_20 ;
V_55 = F_51 ( V_4 -> V_5 ,
V_2 -> V_100 ,
& V_2 -> V_6 ,
& V_2 -> V_147 ,
& V_2 -> V_70 ,
& V_2 -> V_148 ) ;
if ( V_55 )
return V_55 ;
F_11 ( V_134 ,
L_49 ,
F_38 ( V_2 -> V_100 ) , V_2 -> V_6 ,
V_2 -> V_147 , V_2 -> V_19 ) ;
F_11 ( V_134 ,
L_50 ,
V_2 -> V_19 , V_2 -> V_70 , V_2 -> V_148 ) ;
if ( V_131 && V_2 -> V_22 ) {
V_2 -> V_22 = false ;
F_11 ( V_134 ,
L_51 ,
F_38 ( V_2 -> V_100 ) , V_129 ) ;
}
return V_55 ;
}
struct V_8 * F_52 ( int V_149 )
{
struct V_8 * V_9 ;
V_9 = F_6 ( V_149 + sizeof( struct V_18 ) ) ;
if ( ! V_9 ) {
F_7 ( L_52 ) ;
return NULL ;
}
F_8 ( V_9 , sizeof( struct V_18 ) ) ;
if ( ! F_53 ( ( unsigned long ) V_9 -> V_13 , 4 ) )
F_7 ( L_53 ) ;
return V_9 ;
}
int F_54 ( struct V_16 * V_4 )
{
struct V_8 * V_9 ;
int V_55 = 0 ;
struct V_77 * V_78 ;
V_9 = F_5 ( V_4 -> V_5 ) ;
if ( ! V_9 )
return - V_135 ;
F_49 ( V_9 , sizeof( V_78 -> V_25 ) + sizeof( V_78 -> V_150 ) ) ;
memset ( V_9 -> V_13 , 0 , V_9 -> V_26 ) ;
V_78 = (struct V_77 * ) V_9 -> V_13 ;
V_78 -> V_25 . V_79 =
F_19 ( V_151 ) ;
F_11 ( V_14 , L_54 ) ;
V_55 = F_22 ( V_4 , V_76 , V_9 ) ;
if ( V_55 ) {
F_4 ( V_9 ) ;
return V_55 ;
}
return 0 ;
}
void F_55 ( struct V_16 * V_4 )
{
F_20 ( & V_4 -> V_28 ) ;
V_4 -> V_40 = true ;
F_21 ( & V_4 -> V_28 ) ;
F_48 ( V_4 -> V_5 ) ;
}
int F_56 ( struct V_7 * V_5 )
{
struct V_152 V_153 ;
struct V_1 * V_2 = NULL ;
struct V_16 * V_4 = & V_5 -> V_4 ;
F_57 ( & V_4 -> V_28 ) ;
V_4 -> V_40 = false ;
F_39 ( V_4 ) ;
V_153 . V_154 = F_31 ;
V_153 . V_155 = F_27 ;
V_4 -> V_5 = V_5 ;
V_2 = & V_4 -> V_32 [ V_76 ] ;
F_58 ( V_5 , & V_153 ) ;
F_59 ( V_5 , & V_2 -> V_6 , & V_2 -> V_147 ) ;
F_60 ( & V_4 -> V_80 ) ;
return 0 ;
}
