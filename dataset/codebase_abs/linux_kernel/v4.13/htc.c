static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_4 ) ;
}
static struct V_3 * F_3 ( void * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_4 = F_4 ( V_7 ) ;
if ( ! V_4 )
return NULL ;
F_5 ( V_4 , 20 ) ;
F_6 ( ( unsigned long ) V_4 -> V_8 & 3 , L_1 ) ;
V_6 = F_7 ( V_4 ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_8 ( V_2 , V_9 , L_2 , V_10 , V_4 ) ;
return V_4 ;
}
static inline void F_9 ( struct V_11 * V_12 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_7 ( V_4 ) ;
F_10 ( V_12 -> V_2 -> V_13 , V_6 -> V_14 , V_4 -> V_15 , V_16 ) ;
F_11 ( V_4 , sizeof( struct V_17 ) ) ;
}
void F_12 ( struct V_18 * V_19 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_19 -> V_12 -> V_2 ;
F_8 ( V_2 , V_9 , L_3 , V_10 ,
V_19 -> V_20 , V_4 ) ;
F_9 ( V_19 -> V_12 , V_4 ) ;
if ( ! V_19 -> V_21 . V_22 ) {
F_13 ( V_2 , L_4 , V_19 -> V_20 ) ;
F_14 ( V_4 ) ;
return;
}
V_19 -> V_21 . V_22 ( V_19 -> V_12 -> V_2 , V_4 ) ;
}
static void F_15 ( struct V_18 * V_19 ,
struct V_3 * V_4 )
{
struct V_17 * V_23 ;
V_23 = (struct V_17 * ) V_4 -> V_8 ;
V_23 -> V_20 = V_19 -> V_20 ;
V_23 -> V_15 = F_16 ( V_4 -> V_15 - sizeof( * V_23 ) ) ;
V_23 -> V_24 = 0 ;
V_23 -> V_24 |= V_25 ;
F_17 ( & V_19 -> V_12 -> V_26 ) ;
V_23 -> V_27 = V_19 -> V_27 ++ ;
F_18 ( & V_19 -> V_12 -> V_26 ) ;
}
int F_19 ( struct V_11 * V_12 ,
enum V_28 V_20 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_18 * V_19 = & V_12 -> V_29 [ V_20 ] ;
struct V_5 * V_6 = F_7 ( V_4 ) ;
struct V_30 V_31 ;
struct V_32 * V_13 = V_12 -> V_2 -> V_13 ;
int V_33 = 0 ;
int V_34 ;
if ( V_12 -> V_2 -> V_35 == V_36 )
return - V_37 ;
if ( V_20 >= V_38 ) {
F_13 ( V_2 , L_5 , V_20 ) ;
return - V_39 ;
}
F_20 ( V_4 , sizeof( struct V_17 ) ) ;
if ( V_19 -> V_40 ) {
V_33 = F_21 ( V_4 -> V_15 , V_12 -> V_41 ) ;
F_17 ( & V_12 -> V_26 ) ;
if ( V_19 -> V_42 < V_33 ) {
F_8 ( V_2 , V_9 ,
L_6 ,
V_20 , V_33 , V_19 -> V_42 ) ;
F_18 ( & V_12 -> V_26 ) ;
V_34 = - V_43 ;
goto V_44;
}
V_19 -> V_42 -= V_33 ;
F_8 ( V_2 , V_9 ,
L_7 ,
V_20 , V_33 , V_19 -> V_42 ) ;
F_18 ( & V_12 -> V_26 ) ;
}
F_15 ( V_19 , V_4 ) ;
V_6 -> V_20 = V_20 ;
V_6 -> V_14 = F_22 ( V_13 , V_4 -> V_8 , V_4 -> V_15 , V_16 ) ;
V_34 = F_23 ( V_13 , V_6 -> V_14 ) ;
if ( V_34 ) {
V_34 = - V_45 ;
goto V_46;
}
V_31 . V_47 = V_19 -> V_20 ;
V_31 . V_48 = V_4 ;
V_31 . V_49 = V_4 -> V_8 ;
V_31 . V_14 = V_6 -> V_14 ;
V_31 . V_15 = V_4 -> V_15 ;
V_34 = F_24 ( V_12 -> V_2 , V_19 -> V_50 , & V_31 , 1 ) ;
if ( V_34 )
goto V_51;
return 0 ;
V_51:
F_10 ( V_13 , V_6 -> V_14 , V_4 -> V_15 , V_16 ) ;
V_46:
if ( V_19 -> V_40 ) {
F_17 ( & V_12 -> V_26 ) ;
V_19 -> V_42 += V_33 ;
F_8 ( V_2 , V_9 ,
L_8 ,
V_20 , V_33 , V_19 -> V_42 ) ;
F_18 ( & V_12 -> V_26 ) ;
if ( V_19 -> V_21 . V_52 )
V_19 -> V_21 . V_52 ( V_12 -> V_2 ) ;
}
V_44:
F_11 ( V_4 , sizeof( struct V_17 ) ) ;
return V_34 ;
}
void F_25 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_11 * V_12 = & V_2 -> V_12 ;
struct V_5 * V_6 ;
struct V_18 * V_19 ;
if ( F_26 ( ! V_4 ) )
return;
V_6 = F_7 ( V_4 ) ;
V_19 = & V_12 -> V_29 [ V_6 -> V_20 ] ;
F_12 ( V_19 , V_4 ) ;
}
static void
F_27 ( struct V_11 * V_12 ,
const struct V_53 * V_54 ,
int V_15 ,
enum V_28 V_20 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_18 * V_19 ;
int V_55 , V_56 ;
if ( V_15 % sizeof( * V_54 ) )
F_13 ( V_2 , L_9 , V_15 ) ;
V_56 = V_15 / sizeof( * V_54 ) ;
F_17 ( & V_12 -> V_26 ) ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ , V_54 ++ ) {
if ( V_54 -> V_20 >= V_38 )
break;
V_19 = & V_12 -> V_29 [ V_54 -> V_20 ] ;
V_19 -> V_42 += V_54 -> V_33 ;
F_8 ( V_2 , V_9 , L_10 ,
V_54 -> V_20 , V_54 -> V_33 , V_19 -> V_42 ) ;
if ( V_19 -> V_21 . V_52 ) {
F_18 ( & V_12 -> V_26 ) ;
V_19 -> V_21 . V_52 ( V_12 -> V_2 ) ;
F_17 ( & V_12 -> V_26 ) ;
}
}
F_18 ( & V_12 -> V_26 ) ;
}
static int
F_28 ( struct V_11 * V_12 ,
const struct V_57 * V_54 ,
int V_15 ,
enum V_28 V_20 ,
void * V_58 ,
int * V_59 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
if ( V_54 -> V_60 != ( ( ~ V_54 -> V_61 ) & 0xFF ) )
return 0 ;
if ( V_58 && V_59 ) {
F_8 ( V_2 , V_9 ,
L_11 ,
V_54 -> V_60 , V_54 -> V_61 ) ;
memcpy ( ( V_62 * ) V_58 , V_54 -> V_63 , 4 ) ;
* V_59 = 1 ;
}
return 0 ;
}
static int
F_29 ( struct V_11 * V_12 ,
const struct V_64 * V_54 ,
int V_15 ,
enum V_28 V_20 ,
void * V_58 ,
int * V_59 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
int V_65 = V_15 / sizeof( * V_54 ) ;
if ( ! V_65 || ( V_65 > V_66 ) ) {
F_13 ( V_2 , L_12 ,
V_65 ) ;
return - V_67 ;
}
if ( V_58 && V_59 ) {
int V_55 ;
for ( V_55 = 0 ; V_55 < V_65 ; V_55 ++ ) {
memcpy ( ( ( V_62 * ) V_58 ) + 4 * V_55 ,
V_54 -> V_63 , 4 ) ;
V_54 ++ ;
}
* V_59 = V_65 ;
}
return 0 ;
}
int F_30 ( struct V_11 * V_12 ,
V_62 * V_68 ,
int V_69 ,
enum V_28 V_70 ,
void * V_58 ,
int * V_59 )
{
struct V_64 * V_71 ;
struct V_1 * V_2 = V_12 -> V_2 ;
int V_72 = 0 ;
struct V_73 * V_74 ;
V_62 * V_75 ;
int V_76 ;
T_1 V_15 ;
V_75 = V_68 ;
V_76 = V_69 ;
while ( V_69 > 0 ) {
V_74 = (struct V_73 * ) V_68 ;
if ( V_69 < sizeof( V_74 -> V_23 ) ) {
V_72 = - V_67 ;
break;
}
if ( V_74 -> V_23 . V_15 > V_69 ) {
F_13 ( V_2 , L_13 ,
V_74 -> V_23 . V_15 ) ;
V_72 = - V_67 ;
break;
}
switch ( V_74 -> V_23 . V_77 ) {
case V_78 :
V_15 = sizeof( struct V_53 ) ;
if ( V_74 -> V_23 . V_15 < V_15 ) {
F_13 ( V_2 , L_14 ) ;
V_72 = - V_67 ;
break;
}
F_27 ( V_12 ,
V_74 -> V_79 ,
V_74 -> V_23 . V_15 ,
V_70 ) ;
break;
case V_80 :
V_15 = sizeof( struct V_57 ) ;
if ( V_74 -> V_23 . V_15 < V_15 ) {
F_13 ( V_2 , L_15 ) ;
V_72 = - V_67 ;
break;
}
V_72 = F_28 ( V_12 ,
V_74 -> V_81 ,
V_74 -> V_23 . V_15 ,
V_70 ,
V_58 ,
V_59 ) ;
break;
case V_82 :
V_71 = V_74 -> V_83 ;
V_72 = F_29 ( V_12 ,
V_71 ,
V_74 -> V_23 . V_15 ,
V_70 ,
V_58 ,
V_59 ) ;
break;
default:
F_13 ( V_2 , L_16 ,
V_74 -> V_23 . V_77 , V_74 -> V_23 . V_15 ) ;
break;
}
if ( V_72 )
break;
V_68 += sizeof( V_74 -> V_23 ) + V_74 -> V_23 . V_15 ;
V_69 -= sizeof( V_74 -> V_23 ) + V_74 -> V_23 . V_15 ;
}
if ( V_72 )
F_31 ( V_2 , V_9 , L_17 , L_18 ,
V_75 , V_76 ) ;
return V_72 ;
}
void F_32 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_72 = 0 ;
struct V_11 * V_12 = & V_2 -> V_12 ;
struct V_17 * V_23 ;
struct V_18 * V_19 ;
T_2 V_84 ;
T_3 V_85 = 0 ;
T_1 V_86 ;
V_62 V_20 ;
bool V_87 ;
V_23 = (struct V_17 * ) V_4 -> V_8 ;
F_11 ( V_4 , sizeof( * V_23 ) ) ;
V_20 = V_23 -> V_20 ;
if ( V_20 >= V_38 ) {
F_13 ( V_2 , L_19 , V_20 ) ;
F_31 ( V_2 , V_9 , L_20 , L_18 ,
V_23 , sizeof( * V_23 ) ) ;
goto V_88;
}
V_19 = & V_12 -> V_29 [ V_20 ] ;
V_84 = F_33 ( V_23 -> V_15 ) ;
if ( V_84 + sizeof( * V_23 ) > V_89 ) {
F_13 ( V_2 , L_21 ,
V_84 + sizeof( * V_23 ) ) ;
F_31 ( V_2 , V_9 , L_22 , L_18 ,
V_23 , sizeof( * V_23 ) ) ;
goto V_88;
}
if ( V_4 -> V_15 < V_84 ) {
F_8 ( V_2 , V_9 ,
L_23 ,
V_4 -> V_15 , V_84 ) ;
F_31 ( V_2 , V_9 , L_22 ,
L_18 , V_23 , sizeof( * V_23 ) ) ;
goto V_88;
}
V_87 = V_23 -> V_24 & V_90 ;
if ( V_87 ) {
V_62 * V_91 ;
V_85 = V_23 -> V_85 ;
V_86 = sizeof( struct V_92 ) ;
if ( ( V_85 < V_86 ) ||
( V_85 > V_84 ) ) {
F_13 ( V_2 , L_24 ,
V_85 ) ;
goto V_88;
}
V_91 = ( V_62 * ) V_23 ;
V_91 += sizeof( * V_23 ) ;
V_91 += V_84 ;
V_91 -= V_85 ;
V_72 = F_30 ( V_12 , V_91 ,
V_85 , V_23 -> V_20 ,
NULL , NULL ) ;
if ( V_72 )
goto V_88;
F_34 ( V_4 , V_4 -> V_15 - V_85 ) ;
}
if ( ( ( int ) V_84 - ( int ) V_85 ) <= 0 )
goto V_88;
F_8 ( V_2 , V_9 , L_25 ,
V_20 , V_4 ) ;
V_19 -> V_21 . V_93 ( V_2 , V_4 ) ;
V_4 = NULL ;
V_88:
F_2 ( V_4 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_11 * V_12 = & V_2 -> V_12 ;
struct V_94 * V_95 = (struct V_94 * ) V_4 -> V_8 ;
switch ( F_33 ( V_95 -> V_23 . V_96 ) ) {
case V_97 :
case V_98 :
if ( F_36 ( & V_12 -> V_99 ) ) {
F_13 ( V_2 , L_26 ) ;
F_37 ( & V_12 -> V_99 ) ;
goto V_88;
}
V_12 -> V_100 =
F_38 ( int , V_4 -> V_15 ,
V_101 ) ;
memcpy ( V_12 -> V_102 , V_4 -> V_8 ,
V_12 -> V_100 ) ;
F_37 ( & V_12 -> V_99 ) ;
break;
case V_103 :
V_12 -> V_104 . V_105 ( V_2 ) ;
break;
default:
F_13 ( V_2 , L_27 ) ;
break;
}
V_88:
F_2 ( V_4 ) ;
}
static const char * F_39 ( enum V_106 V_77 )
{
switch ( V_77 ) {
case V_107 :
return L_28 ;
case V_108 :
return L_29 ;
case V_109 :
return L_30 ;
case V_110 :
return L_31 ;
case V_111 :
return L_32 ;
case V_112 :
return L_33 ;
case V_113 :
return L_34 ;
case V_114 :
return L_35 ;
case V_115 :
return L_36 ;
case V_116 :
return L_37 ;
case V_117 :
return L_38 ;
}
return L_39 ;
}
static void F_40 ( struct V_11 * V_12 )
{
struct V_18 * V_19 ;
int V_55 ;
for ( V_55 = V_118 ; V_55 < V_38 ; V_55 ++ ) {
V_19 = & V_12 -> V_29 [ V_55 ] ;
V_19 -> V_119 = V_120 ;
V_19 -> V_121 = 0 ;
V_19 -> V_122 = 0 ;
V_19 -> V_20 = V_55 ;
V_19 -> V_12 = V_12 ;
V_19 -> V_40 = true ;
}
}
static V_62 F_41 ( struct V_11 * V_12 ,
T_2 V_119 )
{
V_62 V_123 = 0 ;
if ( V_119 == V_109 )
V_123 = V_12 -> V_124 ;
return V_123 ;
}
int F_42 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
int V_55 , V_72 = 0 ;
unsigned long V_125 ;
struct V_94 * V_95 ;
T_2 V_96 ;
V_125 = F_43 ( & V_12 -> V_99 ,
V_126 ) ;
if ( ! V_125 ) {
F_13 ( V_2 , L_40 ) ;
for ( V_55 = 0 ; V_55 < V_127 ; V_55 ++ )
F_44 ( V_12 -> V_2 , V_55 , 1 ) ;
V_125 =
F_43 ( & V_12 -> V_99 ,
V_126 ) ;
if ( ! V_125 )
V_72 = - V_128 ;
}
if ( V_72 < 0 ) {
F_45 ( V_2 , L_41 , V_72 ) ;
return V_72 ;
}
if ( V_12 -> V_100 < sizeof( V_95 -> V_23 ) + sizeof( V_95 -> V_129 ) ) {
F_45 ( V_2 , L_42 ,
V_12 -> V_100 ) ;
return - V_37 ;
}
V_95 = (struct V_94 * ) V_12 -> V_102 ;
V_96 = F_33 ( V_95 -> V_23 . V_96 ) ;
if ( V_96 != V_97 ) {
F_45 ( V_2 , L_43 , V_96 ) ;
return - V_37 ;
}
V_12 -> V_124 = F_33 ( V_95 -> V_129 . V_130 ) ;
V_12 -> V_41 = F_33 ( V_95 -> V_129 . V_131 ) ;
F_8 ( V_2 , V_9 ,
L_44 ,
V_12 -> V_124 ,
V_12 -> V_41 ) ;
if ( ( V_12 -> V_124 == 0 ) ||
( V_12 -> V_41 == 0 ) ) {
F_45 ( V_2 , L_45 ) ;
return - V_37 ;
}
if ( V_12 -> V_100 >=
sizeof( V_95 -> V_23 ) + sizeof( V_95 -> V_132 ) ) {
V_12 -> V_133 =
F_38 ( V_62 , V_95 -> V_132 . V_133 ,
V_66 ) ;
F_8 ( V_2 , V_9 ,
L_46 ,
V_12 -> V_133 ) ;
}
return 0 ;
}
int F_46 ( struct V_11 * V_12 ,
struct V_134 * V_135 ,
struct V_136 * V_137 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_94 * V_95 ;
struct V_138 * V_139 ;
struct V_140 V_141 ;
struct V_140 * V_142 = & V_141 ;
enum V_28 V_143 = V_38 ;
struct V_18 * V_19 ;
struct V_3 * V_4 ;
unsigned int V_144 = 0 ;
int V_69 , V_72 ;
unsigned long V_125 ;
bool V_145 = false ;
T_2 V_96 , V_119 , V_24 = 0 ;
V_62 V_146 = 0 ;
if ( V_135 -> V_119 == V_108 ) {
V_145 = true ;
V_143 = V_118 ;
V_144 = V_101 ;
memset ( & V_141 , 0 , sizeof( V_141 ) ) ;
goto V_147;
}
V_146 = F_41 ( V_12 ,
V_135 -> V_119 ) ;
if ( ! V_146 )
F_8 ( V_2 , V_148 ,
L_47 ,
F_39 ( V_135 -> V_119 ) ) ;
V_4 = F_3 ( V_12 -> V_2 ) ;
if ( ! V_4 ) {
F_45 ( V_2 , L_48 ) ;
return - V_149 ;
}
V_69 = sizeof( V_95 -> V_23 ) + sizeof( V_95 -> V_150 ) ;
F_47 ( V_4 , V_69 ) ;
memset ( V_4 -> V_8 , 0 , V_69 ) ;
V_95 = (struct V_94 * ) V_4 -> V_8 ;
V_95 -> V_23 . V_96 =
F_16 ( V_151 ) ;
V_24 |= F_48 ( V_146 , V_152 ) ;
if ( V_135 -> V_119 != V_109 ) {
V_24 |= V_153 ;
V_145 = true ;
}
V_139 = & V_95 -> V_150 ;
V_139 -> V_24 = F_16 ( V_24 ) ;
V_139 -> V_119 = F_16 ( V_135 -> V_119 ) ;
F_49 ( & V_12 -> V_99 ) ;
V_72 = F_19 ( V_12 , V_118 , V_4 ) ;
if ( V_72 ) {
F_2 ( V_4 ) ;
return V_72 ;
}
V_125 = F_43 ( & V_12 -> V_99 ,
V_154 ) ;
if ( ! V_125 ) {
F_45 ( V_2 , L_49 ) ;
return - V_128 ;
}
V_95 = (struct V_94 * ) V_12 -> V_102 ;
V_142 = & V_95 -> V_155 ;
V_96 = F_33 ( V_95 -> V_23 . V_96 ) ;
V_119 = F_33 ( V_142 -> V_119 ) ;
if ( ( V_96 != V_98 ) ||
( V_12 -> V_100 < sizeof( V_95 -> V_23 ) +
sizeof( V_95 -> V_155 ) ) ) {
F_45 ( V_2 , L_50 , V_96 ) ;
return - V_156 ;
}
F_8 ( V_2 , V_9 ,
L_51 ,
F_39 ( V_119 ) ,
V_142 -> V_72 , V_142 -> V_20 ) ;
V_137 -> V_157 = V_142 -> V_72 ;
if ( V_142 -> V_72 != V_158 ) {
F_45 ( V_2 , L_52 ,
F_39 ( V_119 ) ,
V_142 -> V_72 ) ;
return - V_156 ;
}
V_143 = (enum V_28 ) V_142 -> V_20 ;
V_144 = F_33 ( V_142 -> V_144 ) ;
V_147:
if ( V_143 >= V_38 )
return - V_156 ;
if ( V_144 == 0 )
return - V_156 ;
V_19 = & V_12 -> V_29 [ V_143 ] ;
V_19 -> V_20 = V_143 ;
if ( V_19 -> V_119 != V_120 )
return - V_156 ;
V_137 -> V_20 = V_143 ;
V_137 -> V_159 = F_33 ( V_142 -> V_144 ) ;
V_19 -> V_119 = V_135 -> V_119 ;
V_19 -> V_122 = V_135 -> V_160 ;
V_19 -> V_121 = F_33 ( V_142 -> V_144 ) ;
V_19 -> V_42 = V_146 ;
V_19 -> V_21 = V_135 -> V_21 ;
V_72 = F_50 ( V_12 -> V_2 ,
V_19 -> V_119 ,
& V_19 -> V_50 ,
& V_19 -> V_161 ) ;
if ( V_72 )
return V_72 ;
F_8 ( V_2 , V_148 ,
L_53 ,
F_39 ( V_19 -> V_119 ) , V_19 -> V_50 ,
V_19 -> V_161 , V_19 -> V_20 ) ;
if ( V_145 && V_19 -> V_40 ) {
V_19 -> V_40 = false ;
F_8 ( V_2 , V_148 ,
L_54 ,
F_39 ( V_19 -> V_119 ) , V_143 ) ;
}
return V_72 ;
}
struct V_3 * F_51 ( struct V_1 * V_2 , int V_162 )
{
struct V_3 * V_4 ;
V_4 = F_4 ( V_162 + sizeof( struct V_17 ) ) ;
if ( ! V_4 )
return NULL ;
F_5 ( V_4 , sizeof( struct V_17 ) ) ;
if ( ! F_52 ( ( unsigned long ) V_4 -> V_8 , 4 ) )
F_13 ( V_2 , L_55 ) ;
return V_4 ;
}
int F_53 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_3 * V_4 ;
int V_72 = 0 ;
struct V_94 * V_95 ;
V_4 = F_3 ( V_12 -> V_2 ) ;
if ( ! V_4 )
return - V_149 ;
F_47 ( V_4 , sizeof( V_95 -> V_23 ) + sizeof( V_95 -> V_163 ) ) ;
memset ( V_4 -> V_8 , 0 , V_4 -> V_15 ) ;
V_95 = (struct V_94 * ) V_4 -> V_8 ;
V_95 -> V_23 . V_96 =
F_16 ( V_164 ) ;
if ( V_2 -> V_165 . V_166 == V_167 ) {
V_95 -> V_163 . V_24 =
F_54 ( V_168 ) ;
V_95 -> V_163 . V_169 =
V_12 -> V_133 ;
}
F_8 ( V_2 , V_9 , L_56 ) ;
V_72 = F_19 ( V_12 , V_118 , V_4 ) ;
if ( V_72 ) {
F_2 ( V_4 ) ;
return V_72 ;
}
return 0 ;
}
int F_55 ( struct V_1 * V_2 )
{
int V_72 ;
struct V_11 * V_12 = & V_2 -> V_12 ;
struct V_134 V_135 ;
struct V_136 V_137 ;
F_56 ( & V_12 -> V_26 ) ;
F_40 ( V_12 ) ;
V_12 -> V_2 = V_2 ;
memset ( & V_135 , 0 , sizeof( V_135 ) ) ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_135 . V_21 . V_22 = F_1 ;
V_135 . V_21 . V_93 = F_35 ;
V_135 . V_160 = V_170 ;
V_135 . V_119 = V_108 ;
V_72 = F_46 ( V_12 , & V_135 , & V_137 ) ;
if ( V_72 ) {
F_45 ( V_2 , L_57 ,
V_72 ) ;
return V_72 ;
}
F_57 ( & V_12 -> V_99 ) ;
return 0 ;
}
