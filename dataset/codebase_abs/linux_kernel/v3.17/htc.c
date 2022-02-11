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
struct V_10 * V_11 = F_10 ( V_9 ) ;
F_13 ( V_4 -> V_5 -> V_17 , V_11 -> V_18 , V_9 -> V_19 , V_20 ) ;
F_14 ( V_9 , sizeof( struct V_21 ) ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
F_11 ( V_14 , L_4 , V_15 ,
V_2 -> V_22 , V_9 ) ;
F_12 ( V_2 -> V_4 , V_9 ) ;
if ( ! V_2 -> V_23 . V_24 ) {
F_7 ( L_5 , V_2 -> V_22 ) ;
F_16 ( V_9 ) ;
return;
}
V_2 -> V_23 . V_24 ( V_2 -> V_4 -> V_5 , V_9 ) ;
}
static bool F_17 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_25 )
return false ;
if ( V_2 -> V_26 >= V_2 -> V_27 )
return false ;
F_11 ( V_14 , L_6 ,
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
struct V_1 * V_2 = & V_4 -> V_34 [ V_22 ] ;
struct V_10 * V_11 = F_10 ( V_9 ) ;
struct V_35 V_36 ;
struct V_37 * V_17 = V_4 -> V_5 -> V_17 ;
int V_38 = 0 ;
int V_39 ;
if ( V_4 -> V_5 -> V_40 == V_41 )
return - V_42 ;
if ( V_22 >= V_43 ) {
F_7 ( L_7 , V_22 ) ;
return - V_44 ;
}
F_20 ( & V_4 -> V_30 ) ;
if ( V_4 -> V_45 ) {
F_21 ( & V_4 -> V_30 ) ;
return - V_46 ;
}
F_21 ( & V_4 -> V_30 ) ;
F_23 ( V_9 , sizeof( struct V_21 ) ) ;
if ( V_2 -> V_25 ) {
V_38 = F_24 ( V_9 -> V_19 , V_4 -> V_47 ) ;
F_20 ( & V_4 -> V_30 ) ;
if ( V_2 -> V_26 < V_38 ) {
F_21 ( & V_4 -> V_30 ) ;
V_39 = - V_48 ;
goto V_49;
}
V_2 -> V_26 -= V_38 ;
F_11 ( V_14 ,
L_8 ,
V_22 , V_38 , V_2 -> V_26 ) ;
F_21 ( & V_4 -> V_30 ) ;
}
F_18 ( V_2 , V_9 ) ;
V_11 -> V_18 = F_25 ( V_17 , V_9 -> V_13 , V_9 -> V_19 , V_20 ) ;
V_39 = F_26 ( V_17 , V_11 -> V_18 ) ;
if ( V_39 )
goto V_50;
V_36 . V_51 = V_2 -> V_22 ;
V_36 . V_52 = V_9 ;
V_36 . V_53 = V_9 -> V_13 ;
V_36 . V_18 = V_11 -> V_18 ;
V_36 . V_19 = V_9 -> V_19 ;
V_39 = F_27 ( V_4 -> V_5 , V_2 -> V_6 , & V_36 , 1 ) ;
if ( V_39 )
goto V_54;
return 0 ;
V_54:
F_13 ( V_17 , V_11 -> V_18 , V_9 -> V_19 , V_20 ) ;
V_50:
if ( V_2 -> V_25 ) {
F_20 ( & V_4 -> V_30 ) ;
V_2 -> V_26 += V_38 ;
F_11 ( V_14 ,
L_9 ,
V_22 , V_38 , V_2 -> V_26 ) ;
F_21 ( & V_4 -> V_30 ) ;
if ( V_2 -> V_23 . V_55 )
V_2 -> V_23 . V_55 ( V_4 -> V_5 ) ;
}
V_49:
F_14 ( V_9 , sizeof( struct V_21 ) ) ;
return V_39 ;
}
static int F_28 ( struct V_7 * V_5 ,
struct V_8 * V_9 ,
unsigned int V_22 )
{
struct V_16 * V_4 = & V_5 -> V_4 ;
struct V_1 * V_2 = & V_4 -> V_34 [ V_22 ] ;
if ( F_29 ( ! V_9 ) )
return 0 ;
F_15 ( V_2 , V_9 ) ;
return 0 ;
}
static void
F_30 ( struct V_16 * V_4 ,
const struct V_56 * V_57 ,
int V_19 ,
enum V_33 V_22 )
{
struct V_1 * V_2 ;
int V_58 , V_59 ;
if ( V_19 % sizeof( * V_57 ) )
F_7 ( L_10 , V_19 ) ;
V_59 = V_19 / sizeof( * V_57 ) ;
F_20 ( & V_4 -> V_30 ) ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ , V_57 ++ ) {
if ( V_57 -> V_22 >= V_43 )
break;
V_2 = & V_4 -> V_34 [ V_57 -> V_22 ] ;
V_2 -> V_26 += V_57 -> V_38 ;
F_11 ( V_14 , L_11 ,
V_57 -> V_22 , V_57 -> V_38 , V_2 -> V_26 ) ;
if ( V_2 -> V_23 . V_55 ) {
F_21 ( & V_4 -> V_30 ) ;
V_2 -> V_23 . V_55 ( V_4 -> V_5 ) ;
F_20 ( & V_4 -> V_30 ) ;
}
}
F_21 ( & V_4 -> V_30 ) ;
}
static int F_31 ( struct V_16 * V_4 ,
T_1 * V_60 ,
int V_61 ,
enum V_33 V_62 )
{
int V_63 = 0 ;
struct V_64 * V_65 ;
T_1 * V_66 ;
int V_67 ;
T_2 V_19 ;
V_66 = V_60 ;
V_67 = V_61 ;
while ( V_61 > 0 ) {
V_65 = (struct V_64 * ) V_60 ;
if ( V_61 < sizeof( V_65 -> V_28 ) ) {
V_63 = - V_68 ;
break;
}
if ( V_65 -> V_28 . V_19 > V_61 ) {
F_7 ( L_12 ,
V_65 -> V_28 . V_19 ) ;
V_63 = - V_68 ;
break;
}
switch ( V_65 -> V_28 . V_69 ) {
case V_70 :
V_19 = sizeof( struct V_56 ) ;
if ( V_65 -> V_28 . V_19 < V_19 ) {
F_7 ( L_13 ) ;
V_63 = - V_68 ;
break;
}
F_30 ( V_4 ,
V_65 -> V_71 ,
V_65 -> V_28 . V_19 ,
V_62 ) ;
break;
default:
F_7 ( L_14 ,
V_65 -> V_28 . V_69 , V_65 -> V_28 . V_19 ) ;
break;
}
if ( V_63 )
break;
V_60 += sizeof( V_65 -> V_28 ) + V_65 -> V_28 . V_19 ;
V_61 -= sizeof( V_65 -> V_28 ) + V_65 -> V_28 . V_19 ;
}
if ( V_63 )
F_32 ( V_14 , L_15 , L_16 ,
V_66 , V_67 ) ;
return V_63 ;
}
static int F_33 ( struct V_7 * V_5 ,
struct V_8 * V_9 ,
T_1 V_72 )
{
int V_63 = 0 ;
struct V_16 * V_4 = & V_5 -> V_4 ;
struct V_21 * V_28 ;
struct V_1 * V_2 ;
T_3 V_73 ;
T_4 V_74 = 0 ;
T_2 V_75 ;
T_1 V_22 ;
bool V_76 ;
V_28 = (struct V_21 * ) V_9 -> V_13 ;
F_14 ( V_9 , sizeof( * V_28 ) ) ;
V_22 = V_28 -> V_22 ;
if ( V_22 >= V_43 ) {
F_7 ( L_17 , V_22 ) ;
F_32 ( V_14 , L_18 , L_16 ,
V_28 , sizeof( * V_28 ) ) ;
V_63 = - V_68 ;
goto V_77;
}
V_2 = & V_4 -> V_34 [ V_22 ] ;
if ( V_2 -> V_78 )
F_1 ( V_2 , 1 ) ;
V_73 = F_34 ( V_28 -> V_19 ) ;
if ( V_73 + sizeof( * V_28 ) > V_79 ) {
F_7 ( L_19 ,
V_73 + sizeof( * V_28 ) ) ;
F_32 ( V_14 , L_20 , L_16 ,
V_28 , sizeof( * V_28 ) ) ;
V_63 = - V_68 ;
goto V_77;
}
if ( V_9 -> V_19 < V_73 ) {
F_11 ( V_14 ,
L_21 ,
V_9 -> V_19 , V_73 ) ;
F_32 ( V_14 , L_20 ,
L_16 , V_28 , sizeof( * V_28 ) ) ;
V_63 = - V_68 ;
goto V_77;
}
V_76 = V_28 -> V_29 & V_80 ;
if ( V_76 ) {
T_1 * V_81 ;
V_74 = V_28 -> V_74 ;
V_75 = sizeof( struct V_82 ) ;
if ( ( V_74 < V_75 ) ||
( V_74 > V_73 ) ) {
F_7 ( L_22 ,
V_74 ) ;
V_63 = - V_83 ;
goto V_77;
}
V_81 = ( T_1 * ) V_28 ;
V_81 += sizeof( * V_28 ) ;
V_81 += V_73 ;
V_81 -= V_74 ;
V_63 = F_31 ( V_4 , V_81 ,
V_74 , V_28 -> V_22 ) ;
if ( V_63 )
goto V_77;
F_35 ( V_9 , V_9 -> V_19 - V_74 ) ;
}
if ( ( ( int ) V_73 - ( int ) V_74 ) <= 0 )
goto V_77;
if ( V_22 == V_84 ) {
struct V_85 * V_86 = (struct V_85 * ) V_9 -> V_13 ;
switch ( F_34 ( V_86 -> V_28 . V_87 ) ) {
default:
if ( F_36 ( & V_4 -> V_88 ) ) {
F_7 ( L_23 ) ;
V_63 = - V_68 ;
F_37 ( & V_4 -> V_88 ) ;
goto V_77;
}
V_4 -> V_89 =
F_38 ( int , V_9 -> V_19 ,
V_90 ) ;
memcpy ( V_4 -> V_91 , V_9 -> V_13 ,
V_4 -> V_89 ) ;
F_37 ( & V_4 -> V_88 ) ;
break;
case V_92 :
V_4 -> V_93 . V_94 ( V_5 ) ;
}
goto V_77;
}
F_11 ( V_14 , L_24 ,
V_22 , V_9 ) ;
V_2 -> V_23 . V_95 ( V_5 , V_9 ) ;
V_9 = NULL ;
V_77:
F_4 ( V_9 ) ;
return V_63 ;
}
static void F_39 ( struct V_7 * V_5 ,
struct V_8 * V_9 )
{
F_7 ( L_25 ) ;
F_4 ( V_9 ) ;
}
static const char * F_40 ( enum V_96 V_69 )
{
switch ( V_69 ) {
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
case V_107 :
return L_36 ;
}
return L_37 ;
}
static void F_41 ( struct V_16 * V_4 )
{
struct V_1 * V_2 ;
int V_58 ;
for ( V_58 = V_84 ; V_58 < V_43 ; V_58 ++ ) {
V_2 = & V_4 -> V_34 [ V_58 ] ;
V_2 -> V_108 = V_109 ;
V_2 -> V_110 = 0 ;
V_2 -> V_111 = 0 ;
V_2 -> V_22 = V_58 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_25 = true ;
}
}
static void F_42 ( struct V_16 * V_4 )
{
struct V_112 * V_113 ;
V_113 = & V_4 -> V_114 [ 0 ] ;
V_113 ++ ;
V_113 -> V_108 = V_99 ;
V_113 -> V_115 = V_4 -> V_116 ;
}
static T_1 F_43 ( struct V_16 * V_4 ,
T_3 V_108 )
{
T_1 V_117 = 0 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_43 ; V_58 ++ ) {
if ( V_4 -> V_114 [ V_58 ] . V_108 == V_108 )
V_117 =
V_4 -> V_114 [ V_58 ] . V_115 ;
}
return V_117 ;
}
int F_44 ( struct V_16 * V_4 )
{
int V_58 , V_63 = 0 ;
struct V_118 V_119 ;
struct V_120 V_121 ;
struct V_85 * V_86 ;
T_3 V_87 ;
T_3 V_122 ;
T_3 V_123 ;
V_63 = F_45 ( & V_4 -> V_88 ,
V_124 ) ;
if ( V_63 == 0 ) {
F_7 ( L_38 ) ;
for ( V_58 = 0 ; V_58 < V_125 ; V_58 ++ )
F_2 ( V_4 -> V_5 , V_58 , 1 ) ;
V_63 = F_45 ( & V_4 -> V_88 ,
V_124 ) ;
if ( V_63 == 0 )
V_63 = - V_126 ;
}
if ( V_63 < 0 ) {
F_46 ( L_39 , V_63 ) ;
return V_63 ;
}
if ( V_4 -> V_89 < sizeof( V_86 -> V_28 ) + sizeof( V_86 -> V_127 ) ) {
F_46 ( L_40 ,
V_4 -> V_89 ) ;
return - V_42 ;
}
V_86 = (struct V_85 * ) V_4 -> V_91 ;
V_87 = F_34 ( V_86 -> V_28 . V_87 ) ;
V_122 = F_34 ( V_86 -> V_127 . V_122 ) ;
V_123 = F_34 ( V_86 -> V_127 . V_123 ) ;
if ( V_87 != V_128 ) {
F_46 ( L_41 , V_87 ) ;
return - V_42 ;
}
V_4 -> V_116 = V_122 ;
V_4 -> V_47 = V_123 ;
F_11 ( V_14 ,
L_42 ,
V_4 -> V_116 ,
V_4 -> V_47 ) ;
if ( ( V_4 -> V_116 == 0 ) ||
( V_4 -> V_47 == 0 ) ) {
F_46 ( L_43 ) ;
return - V_42 ;
}
F_42 ( V_4 ) ;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
memset ( & V_121 , 0 , sizeof( V_121 ) ) ;
V_119 . V_23 . V_24 = F_3 ;
V_119 . V_23 . V_95 = F_39 ;
V_119 . V_129 = V_130 ;
V_119 . V_108 = V_98 ;
V_63 = F_47 ( V_4 , & V_119 , & V_121 ) ;
if ( V_63 ) {
F_46 ( L_44 , V_63 ) ;
return V_63 ;
}
return 0 ;
}
int F_47 ( struct V_16 * V_4 ,
struct V_118 * V_119 ,
struct V_120 * V_121 )
{
struct V_85 * V_86 ;
struct V_131 * V_132 ;
struct V_133 V_134 ;
struct V_133 * V_135 = & V_134 ;
enum V_33 V_136 = V_43 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
unsigned int V_137 = 0 ;
int V_61 , V_63 ;
bool V_138 = false ;
T_3 V_87 , V_108 , V_29 = 0 ;
T_1 V_139 = 0 ;
if ( V_119 -> V_108 == V_98 ) {
V_138 = true ;
V_136 = V_84 ;
V_137 = V_90 ;
memset ( & V_134 , 0 , sizeof( V_134 ) ) ;
goto V_140;
}
V_139 = F_43 ( V_4 ,
V_119 -> V_108 ) ;
if ( ! V_139 )
F_11 ( V_141 ,
L_45 ,
F_40 ( V_119 -> V_108 ) ) ;
V_9 = F_5 ( V_4 -> V_5 ) ;
if ( ! V_9 ) {
F_46 ( L_46 ) ;
return - V_142 ;
}
V_61 = sizeof( V_86 -> V_28 ) + sizeof( V_86 -> V_143 ) ;
F_48 ( V_9 , V_61 ) ;
memset ( V_9 -> V_13 , 0 , V_61 ) ;
V_86 = (struct V_85 * ) V_9 -> V_13 ;
V_86 -> V_28 . V_87 =
F_19 ( V_144 ) ;
V_29 |= F_49 ( V_139 , V_145 ) ;
if ( V_119 -> V_108 != V_99 ) {
V_29 |= V_146 ;
V_138 = true ;
}
V_132 = & V_86 -> V_143 ;
V_132 -> V_29 = F_19 ( V_29 ) ;
V_132 -> V_108 = F_19 ( V_119 -> V_108 ) ;
F_50 ( & V_4 -> V_88 ) ;
V_63 = F_22 ( V_4 , V_84 , V_9 ) ;
if ( V_63 ) {
F_4 ( V_9 ) ;
return V_63 ;
}
V_63 = F_45 ( & V_4 -> V_88 ,
V_147 ) ;
if ( V_63 <= 0 ) {
if ( V_63 == 0 )
V_63 = - V_126 ;
F_46 ( L_47 , V_63 ) ;
return V_63 ;
}
V_86 = (struct V_85 * ) V_4 -> V_91 ;
V_135 = & V_86 -> V_148 ;
V_87 = F_34 ( V_86 -> V_28 . V_87 ) ;
V_108 = F_34 ( V_135 -> V_108 ) ;
if ( ( V_87 != V_149 ) ||
( V_4 -> V_89 < sizeof( V_86 -> V_28 ) +
sizeof( V_86 -> V_148 ) ) ) {
F_46 ( L_48 , V_87 ) ;
return - V_83 ;
}
F_11 ( V_14 ,
L_49 ,
F_40 ( V_108 ) ,
V_135 -> V_63 , V_135 -> V_22 ) ;
V_121 -> V_150 = V_135 -> V_63 ;
if ( V_135 -> V_63 != V_151 ) {
F_46 ( L_50 ,
F_40 ( V_108 ) ,
V_135 -> V_63 ) ;
return - V_83 ;
}
V_136 = (enum V_33 ) V_135 -> V_22 ;
V_137 = F_34 ( V_135 -> V_137 ) ;
V_140:
if ( V_136 >= V_43 )
return - V_83 ;
if ( V_137 == 0 )
return - V_83 ;
V_2 = & V_4 -> V_34 [ V_136 ] ;
V_2 -> V_22 = V_136 ;
if ( V_2 -> V_108 != V_109 )
return - V_83 ;
V_121 -> V_22 = V_136 ;
V_121 -> V_152 = F_34 ( V_135 -> V_137 ) ;
V_2 -> V_108 = V_119 -> V_108 ;
V_2 -> V_111 = V_119 -> V_129 ;
V_2 -> V_110 = F_34 ( V_135 -> V_137 ) ;
V_2 -> V_26 = V_139 ;
V_2 -> V_153 = V_4 -> V_47 ;
V_2 -> V_27 = V_2 -> V_110 /
V_4 -> V_47 ;
if ( V_2 -> V_110 % V_4 -> V_47 )
V_2 -> V_27 ++ ;
V_2 -> V_23 = V_119 -> V_23 ;
V_63 = F_51 ( V_4 -> V_5 ,
V_2 -> V_108 ,
& V_2 -> V_6 ,
& V_2 -> V_154 ,
& V_2 -> V_78 ,
& V_2 -> V_155 ) ;
if ( V_63 )
return V_63 ;
F_11 ( V_141 ,
L_51 ,
F_40 ( V_2 -> V_108 ) , V_2 -> V_6 ,
V_2 -> V_154 , V_2 -> V_22 ) ;
F_11 ( V_141 ,
L_52 ,
V_2 -> V_22 , V_2 -> V_78 , V_2 -> V_155 ) ;
if ( V_138 && V_2 -> V_25 ) {
V_2 -> V_25 = false ;
F_11 ( V_141 ,
L_53 ,
F_40 ( V_2 -> V_108 ) , V_136 ) ;
}
return V_63 ;
}
struct V_8 * F_52 ( int V_156 )
{
struct V_8 * V_9 ;
V_9 = F_6 ( V_156 + sizeof( struct V_21 ) ) ;
if ( ! V_9 ) {
F_7 ( L_54 ) ;
return NULL ;
}
F_8 ( V_9 , sizeof( struct V_21 ) ) ;
if ( ! F_53 ( ( unsigned long ) V_9 -> V_13 , 4 ) )
F_7 ( L_55 ) ;
return V_9 ;
}
int F_54 ( struct V_16 * V_4 )
{
struct V_8 * V_9 ;
int V_63 = 0 ;
struct V_85 * V_86 ;
V_9 = F_5 ( V_4 -> V_5 ) ;
if ( ! V_9 )
return - V_142 ;
F_48 ( V_9 , sizeof( V_86 -> V_28 ) + sizeof( V_86 -> V_157 ) ) ;
memset ( V_9 -> V_13 , 0 , V_9 -> V_19 ) ;
V_86 = (struct V_85 * ) V_9 -> V_13 ;
V_86 -> V_28 . V_87 =
F_19 ( V_158 ) ;
F_11 ( V_14 , L_56 ) ;
V_63 = F_22 ( V_4 , V_84 , V_9 ) ;
if ( V_63 ) {
F_4 ( V_9 ) ;
return V_63 ;
}
return 0 ;
}
void F_55 ( struct V_16 * V_4 )
{
F_20 ( & V_4 -> V_30 ) ;
V_4 -> V_45 = true ;
F_21 ( & V_4 -> V_30 ) ;
}
int F_56 ( struct V_7 * V_5 )
{
struct V_159 V_160 ;
struct V_1 * V_2 = NULL ;
struct V_16 * V_4 = & V_5 -> V_4 ;
F_57 ( & V_4 -> V_30 ) ;
V_4 -> V_45 = false ;
F_41 ( V_4 ) ;
V_160 . V_161 = F_33 ;
V_160 . V_162 = F_28 ;
V_4 -> V_5 = V_5 ;
V_2 = & V_4 -> V_34 [ V_84 ] ;
F_58 ( V_5 , & V_160 ) ;
F_59 ( V_5 , & V_2 -> V_6 , & V_2 -> V_154 ) ;
F_60 ( & V_4 -> V_88 ) ;
return 0 ;
}
