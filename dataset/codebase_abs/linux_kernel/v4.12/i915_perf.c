static bool F_1 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 . V_5 . V_6 . V_7 ;
T_1 V_8 = F_2 ( V_9 ) ;
T_1 V_10 = F_2 ( V_11 ) ;
T_1 V_12 = V_8 & V_13 ;
T_1 V_14 = V_10 & V_15 ;
return F_3 ( V_14 , V_12 ) <
V_2 -> V_4 . V_5 . V_16 + V_3 ;
}
static int F_4 ( struct V_17 * V_18 ,
char T_2 * V_19 ,
T_3 V_20 ,
T_3 * V_21 ,
enum V_22 type )
{
struct V_23 V_24 = { type , 0 , sizeof( V_24 ) } ;
if ( ( V_20 - * V_21 ) < V_24 . V_25 )
return - V_26 ;
if ( F_5 ( V_19 + * V_21 , & V_24 , sizeof( V_24 ) ) )
return - V_27 ;
( * V_21 ) += V_24 . V_25 ;
return 0 ;
}
static int F_6 ( struct V_17 * V_18 ,
char T_2 * V_19 ,
T_3 V_20 ,
T_3 * V_21 ,
const T_4 * V_28 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
int V_3 = V_2 -> V_4 . V_5 . V_6 . V_7 ;
struct V_23 V_24 ;
T_1 V_29 = V_18 -> V_29 ;
V_24 . type = V_30 ;
V_24 . V_31 = 0 ;
V_24 . V_25 = V_18 -> V_32 ;
if ( ( V_20 - * V_21 ) < V_24 . V_25 )
return - V_26 ;
V_19 += * V_21 ;
if ( F_5 ( V_19 , & V_24 , sizeof( V_24 ) ) )
return - V_27 ;
V_19 += sizeof( V_24 ) ;
if ( V_29 & V_33 ) {
if ( F_5 ( V_19 , V_28 , V_3 ) )
return - V_27 ;
}
( * V_21 ) += V_24 . V_25 ;
return 0 ;
}
static int F_7 ( struct V_17 * V_18 ,
char T_2 * V_19 ,
T_3 V_20 ,
T_3 * V_21 ,
T_1 * V_34 ,
T_1 V_14 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
int V_3 = V_2 -> V_4 . V_5 . V_6 . V_7 ;
T_4 * V_35 = V_2 -> V_4 . V_5 . V_6 . V_36 ;
int V_16 = V_2 -> V_4 . V_5 . V_16 ;
T_1 V_37 = F_8 ( V_2 -> V_4 . V_5 . V_6 . V_38 ) ;
T_1 V_39 = ( V_40 - 1 ) ;
T_1 V_12 ;
T_1 V_41 ;
int V_42 = 0 ;
if ( F_9 ( ! V_18 -> V_43 ) )
return - V_44 ;
V_12 = * V_34 - V_37 ;
V_14 -= V_37 ;
if ( V_14 > V_40 || V_12 > V_40 ||
V_12 % V_3 ) {
F_10 ( L_1 ,
V_12 , V_14 ) ;
V_2 -> V_4 . V_5 . V_45 . V_46 ( V_2 ) ;
V_2 -> V_4 . V_5 . V_45 . V_47 ( V_2 ) ;
* V_34 = F_2 ( V_9 ) &
V_13 ;
return - V_44 ;
}
V_14 &= ~ ( V_3 - 1 ) ;
if ( F_3 ( V_14 , V_12 ) < V_3 + V_16 )
return - V_48 ;
V_14 -= V_16 ;
V_14 &= V_39 ;
for (;
( V_41 = F_3 ( V_14 , V_12 ) ) ;
V_12 = ( V_12 + V_3 ) & V_39 ) {
T_4 * V_28 = V_35 + V_12 ;
T_1 * V_49 = ( void * ) V_28 ;
if ( F_9 ( ( V_40 - V_12 ) < V_3 ) ) {
F_10 ( L_2 ) ;
break;
}
if ( V_49 [ 0 ] == 0 ) {
F_11 ( L_3 ) ;
continue;
}
V_42 = F_6 ( V_18 , V_19 , V_20 , V_21 , V_28 ) ;
if ( V_42 )
break;
V_49 [ 0 ] = 0 ;
}
* V_34 = V_37 + V_12 ;
return V_42 ;
}
static int F_12 ( struct V_17 * V_18 ,
char T_2 * V_19 ,
T_3 V_20 ,
T_3 * V_21 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
int V_3 = V_2 -> V_4 . V_5 . V_6 . V_7 ;
T_1 V_8 ;
T_1 V_10 ;
T_1 V_12 ;
T_1 V_14 ;
int V_42 ;
if ( F_9 ( ! V_2 -> V_4 . V_5 . V_6 . V_36 ) )
return - V_44 ;
V_8 = F_2 ( V_9 ) ;
V_10 = F_2 ( V_11 ) ;
V_12 = V_8 & V_13 ;
V_14 = V_10 & V_15 ;
V_10 &= ~ V_2 -> V_4 . V_5 . V_50 ;
if ( F_13 ( V_10 & V_51 ) ) {
V_42 = F_4 ( V_18 , V_19 , V_20 , V_21 ,
V_52 ) ;
if ( V_42 )
return V_42 ;
F_14 ( L_4 ) ;
V_2 -> V_4 . V_5 . V_45 . V_46 ( V_2 ) ;
V_2 -> V_4 . V_5 . V_45 . V_47 ( V_2 ) ;
V_8 = F_2 ( V_9 ) ;
V_10 = F_2 ( V_11 ) ;
V_12 = V_8 & V_13 ;
V_14 = V_10 & V_15 ;
}
if ( F_13 ( V_10 & V_53 ) ) {
V_42 = F_4 ( V_18 , V_19 , V_20 , V_21 ,
V_54 ) ;
if ( V_42 )
return V_42 ;
V_2 -> V_4 . V_5 . V_50 |=
V_53 ;
}
V_42 = F_7 ( V_18 , V_19 , V_20 , V_21 ,
& V_12 , V_14 ) ;
F_15 ( V_12 & ( V_3 - 1 ) ,
L_5 ) ;
F_16 ( V_9 ,
( ( V_12 & V_13 ) |
V_55 ) ) ;
return V_42 ;
}
static int F_17 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
if ( ! V_2 -> V_4 . V_5 . V_56 )
return - V_44 ;
return F_18 ( V_2 -> V_4 . V_5 . V_57 ,
! V_2 -> V_4 . V_5 . V_45 . V_58 ( V_2 ) ) ;
}
static void F_19 ( struct V_17 * V_18 ,
struct V_59 * V_59 ,
T_5 * V_60 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
F_20 ( V_59 , & V_2 -> V_4 . V_5 . V_57 , V_60 ) ;
}
static int F_21 ( struct V_17 * V_18 ,
char T_2 * V_19 ,
T_3 V_20 ,
T_3 * V_21 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
return V_2 -> V_4 . V_5 . V_45 . V_61 ( V_18 , V_19 , V_20 , V_21 ) ;
}
static int F_22 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_62 * V_63 = V_2 -> V_63 [ V_64 ] ;
int V_42 ;
V_42 = F_23 ( & V_2 -> V_65 ) ;
if ( V_42 )
return V_42 ;
V_42 = V_63 -> V_66 ( V_63 , V_18 -> V_67 ) ;
if ( V_42 )
goto V_68;
V_2 -> V_4 . V_5 . V_69 =
F_8 ( V_18 -> V_67 -> V_63 [ V_63 -> V_70 ] . V_71 ) ;
V_68:
F_24 ( & V_2 -> V_65 . V_72 ) ;
return V_42 ;
}
static void F_25 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_62 * V_63 = V_2 -> V_63 [ V_64 ] ;
F_26 ( & V_2 -> V_65 . V_72 ) ;
V_2 -> V_4 . V_5 . V_69 = V_73 ;
V_63 -> V_74 ( V_63 , V_18 -> V_67 ) ;
F_24 ( & V_2 -> V_65 . V_72 ) ;
}
static void
F_27 ( struct V_1 * V_75 )
{
F_26 ( & V_75 -> V_65 . V_72 ) ;
F_28 ( V_75 -> V_4 . V_5 . V_6 . V_38 -> V_76 ) ;
F_29 ( V_75 -> V_4 . V_5 . V_6 . V_38 ) ;
F_30 ( V_75 -> V_4 . V_5 . V_6 . V_38 -> V_76 ) ;
V_75 -> V_4 . V_5 . V_6 . V_38 = NULL ;
V_75 -> V_4 . V_5 . V_6 . V_36 = NULL ;
F_24 ( & V_75 -> V_65 . V_72 ) ;
}
static void F_31 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
F_32 ( V_18 != V_2 -> V_4 . V_5 . V_77 ) ;
V_2 -> V_4 . V_5 . V_45 . V_78 ( V_2 ) ;
F_27 ( V_2 ) ;
F_33 ( V_2 , V_79 ) ;
F_34 ( V_2 ) ;
if ( V_18 -> V_67 )
F_25 ( V_18 ) ;
V_2 -> V_4 . V_5 . V_77 = NULL ;
}
static void F_35 ( struct V_1 * V_2 )
{
T_1 V_37 = F_8 ( V_2 -> V_4 . V_5 . V_6 . V_38 ) ;
F_16 ( V_9 , V_37 | V_55 ) ;
F_16 ( V_80 , V_37 ) ;
F_16 ( V_11 , V_37 | V_81 ) ;
V_2 -> V_4 . V_5 . V_50 = 0 ;
memset ( V_2 -> V_4 . V_5 . V_6 . V_36 , 0 , V_40 ) ;
V_2 -> V_4 . V_5 . V_82 = false ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_83 * V_84 ;
struct V_85 * V_38 ;
int V_42 ;
if ( F_9 ( V_2 -> V_4 . V_5 . V_6 . V_38 ) )
return - V_86 ;
V_42 = F_23 ( & V_2 -> V_65 ) ;
if ( V_42 )
return V_42 ;
F_37 ( V_40 ) ;
F_38 ( V_40 < V_87 || V_40 > V_88 ) ;
V_84 = F_39 ( V_2 , V_40 ) ;
if ( F_40 ( V_84 ) ) {
F_10 ( L_6 ) ;
V_42 = F_41 ( V_84 ) ;
goto V_68;
}
V_42 = F_42 ( V_84 , V_89 ) ;
if ( V_42 )
goto V_90;
V_38 = F_43 ( V_84 , NULL , 0 , V_88 , 0 ) ;
if ( F_40 ( V_38 ) ) {
V_42 = F_41 ( V_38 ) ;
goto V_90;
}
V_2 -> V_4 . V_5 . V_6 . V_38 = V_38 ;
V_2 -> V_4 . V_5 . V_6 . V_36 =
F_44 ( V_84 , V_91 ) ;
if ( F_40 ( V_2 -> V_4 . V_5 . V_6 . V_36 ) ) {
V_42 = F_41 ( V_2 -> V_4 . V_5 . V_6 . V_36 ) ;
goto V_92;
}
V_2 -> V_4 . V_5 . V_45 . V_93 ( V_2 ) ;
F_45 ( L_7 ,
F_8 ( V_2 -> V_4 . V_5 . V_6 . V_38 ) ,
V_2 -> V_4 . V_5 . V_6 . V_36 ) ;
goto V_68;
V_92:
F_46 ( V_38 ) ;
V_90:
F_30 ( V_84 ) ;
V_2 -> V_4 . V_5 . V_6 . V_36 = NULL ;
V_2 -> V_4 . V_5 . V_6 . V_38 = NULL ;
V_68:
F_24 ( & V_2 -> V_65 . V_72 ) ;
return V_42 ;
}
static void F_47 ( struct V_1 * V_2 ,
const struct V_94 * V_95 ,
int V_96 )
{
int V_97 ;
for ( V_97 = 0 ; V_97 < V_96 ; V_97 ++ ) {
const struct V_94 * V_98 = V_95 + V_97 ;
F_16 ( V_98 -> V_99 , V_98 -> V_100 ) ;
}
}
static int F_48 ( struct V_1 * V_2 )
{
int V_42 = F_49 ( V_2 ) ;
if ( V_42 )
return V_42 ;
F_16 ( V_101 , ( F_2 ( V_101 ) |
V_102 ) ) ;
F_16 ( V_103 , ( F_2 ( V_103 ) &
~ V_104 ) ) ;
F_16 ( V_105 , ( F_2 ( V_105 ) |
V_106 ) ) ;
F_47 ( V_2 , V_2 -> V_4 . V_5 . V_107 ,
V_2 -> V_4 . V_5 . V_108 ) ;
F_50 ( 15000 , 20000 ) ;
F_47 ( V_2 , V_2 -> V_4 . V_5 . V_109 ,
V_2 -> V_4 . V_5 . V_110 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_16 ( V_105 , ( F_2 ( V_105 ) &
~ V_106 ) ) ;
F_16 ( V_103 , ( F_2 ( V_103 ) |
V_104 ) ) ;
F_16 ( V_101 , ( F_2 ( V_101 ) &
~ V_102 ) ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
F_53 ( & V_2 -> V_4 . V_111 ) ;
if ( V_2 -> V_4 . V_5 . V_77 -> V_43 ) {
struct V_112 * V_67 =
V_2 -> V_4 . V_5 . V_77 -> V_67 ;
T_1 V_113 = V_2 -> V_4 . V_5 . V_69 ;
bool V_56 = V_2 -> V_4 . V_5 . V_56 ;
T_1 V_114 = V_2 -> V_4 . V_5 . V_114 ;
T_1 V_115 = V_2 -> V_4 . V_5 . V_6 . V_116 ;
F_16 ( V_117 ,
( V_113 & V_118 ) |
( V_114 <<
V_119 ) |
( V_56 ? V_120 : 0 ) |
( V_115 << V_121 ) |
( V_67 ? V_122 : 0 ) |
V_123 ) ;
} else
F_16 ( V_117 , 0 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
unsigned long V_124 ;
F_35 ( V_2 ) ;
F_55 ( & V_2 -> V_4 . V_111 , V_124 ) ;
F_52 ( V_2 ) ;
F_56 ( & V_2 -> V_4 . V_111 , V_124 ) ;
}
static void F_57 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
V_2 -> V_4 . V_5 . V_45 . V_47 ( V_2 ) ;
if ( V_2 -> V_4 . V_5 . V_56 )
F_58 ( & V_2 -> V_4 . V_5 . V_125 ,
F_59 ( V_126 ) ,
V_127 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
F_16 ( V_117 , 0 ) ;
}
static void F_61 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
V_2 -> V_4 . V_5 . V_45 . V_46 ( V_2 ) ;
if ( V_2 -> V_4 . V_5 . V_56 )
F_62 ( & V_2 -> V_4 . V_5 . V_125 ) ;
}
static T_6 F_63 ( struct V_1 * V_2 , int V_128 )
{
return F_64 ( 1000000000ULL * ( 2ULL << V_128 ) ,
V_2 -> V_4 . V_5 . V_129 ) ;
}
static int F_65 ( struct V_17 * V_18 ,
struct V_130 * V_131 ,
struct V_132 * V_133 )
{
struct V_1 * V_2 = V_18 -> V_2 ;
int V_7 ;
int V_42 ;
if ( ! V_2 -> V_4 . V_134 ) {
F_14 ( L_8 ) ;
return - V_135 ;
}
if ( ! ( V_133 -> V_29 & V_33 ) ) {
F_14 ( L_9 ) ;
return - V_135 ;
}
if ( ! V_2 -> V_4 . V_5 . V_45 . V_93 ) {
F_14 ( L_10 ) ;
return - V_86 ;
}
if ( V_2 -> V_4 . V_5 . V_77 ) {
F_14 ( L_11 ) ;
return - V_136 ;
}
if ( ! V_133 -> V_137 ) {
F_14 ( L_12 ) ;
return - V_135 ;
}
if ( ! V_133 -> V_138 ) {
F_14 ( L_13 ) ;
return - V_135 ;
}
V_18 -> V_32 = sizeof( struct V_23 ) ;
V_7 = V_2 -> V_4 . V_5 . V_139 [ V_133 -> V_138 ] . V_25 ;
V_18 -> V_29 |= V_33 ;
V_18 -> V_32 += V_7 ;
V_2 -> V_4 . V_5 . V_6 . V_7 = V_7 ;
if ( F_9 ( V_2 -> V_4 . V_5 . V_6 . V_7 == 0 ) )
return - V_135 ;
V_2 -> V_4 . V_5 . V_6 . V_116 =
V_2 -> V_4 . V_5 . V_139 [ V_133 -> V_138 ] . V_116 ;
V_2 -> V_4 . V_5 . V_137 = V_133 -> V_137 ;
V_2 -> V_4 . V_5 . V_56 = V_133 -> V_140 ;
if ( V_2 -> V_4 . V_5 . V_56 ) {
T_1 V_14 ;
V_2 -> V_4 . V_5 . V_114 = V_133 -> V_141 ;
V_14 = F_66 ( V_142 ,
F_63 ( V_2 ,
V_133 -> V_141 ) ) ;
V_2 -> V_4 . V_5 . V_16 = ( V_14 + 1 ) * V_7 ;
}
if ( V_18 -> V_67 ) {
V_42 = F_22 ( V_18 ) ;
if ( V_42 )
return V_42 ;
}
V_42 = F_36 ( V_2 ) ;
if ( V_42 )
goto V_143;
F_67 ( V_2 ) ;
F_68 ( V_2 , V_79 ) ;
V_42 = V_2 -> V_4 . V_5 . V_45 . V_144 ( V_2 ) ;
if ( V_42 )
goto V_145;
V_18 -> V_45 = & V_146 ;
V_2 -> V_4 . V_5 . V_77 = V_18 ;
return 0 ;
V_145:
F_33 ( V_2 , V_79 ) ;
F_34 ( V_2 ) ;
F_27 ( V_2 ) ;
V_143:
if ( V_18 -> V_67 )
F_25 ( V_18 ) ;
return V_42 ;
}
static T_7 F_69 ( struct V_17 * V_18 ,
struct V_59 * V_59 ,
char T_2 * V_19 ,
T_3 V_20 ,
T_8 * V_147 )
{
T_3 V_21 = 0 ;
int V_42 = V_18 -> V_45 -> V_61 ( V_18 , V_19 , V_20 , & V_21 ) ;
return V_21 ? : ( V_42 ? : - V_48 ) ;
}
static T_7 F_70 ( struct V_59 * V_59 ,
char T_2 * V_19 ,
T_3 V_20 ,
T_8 * V_147 )
{
struct V_17 * V_18 = V_59 -> V_148 ;
struct V_1 * V_2 = V_18 -> V_2 ;
T_7 V_42 ;
if ( ! V_18 -> V_43 )
return - V_44 ;
if ( ! ( V_59 -> V_149 & V_150 ) ) {
do {
V_42 = V_18 -> V_45 -> V_151 ( V_18 ) ;
if ( V_42 )
return V_42 ;
F_26 ( & V_2 -> V_4 . V_152 ) ;
V_42 = F_69 ( V_18 , V_59 ,
V_19 , V_20 , V_147 ) ;
F_24 ( & V_2 -> V_4 . V_152 ) ;
} while ( V_42 == - V_48 );
} else {
F_26 ( & V_2 -> V_4 . V_152 ) ;
V_42 = F_69 ( V_18 , V_59 , V_19 , V_20 , V_147 ) ;
F_24 ( & V_2 -> V_4 . V_152 ) ;
}
if ( V_42 >= 0 ) {
V_2 -> V_4 . V_5 . V_82 = false ;
}
return V_42 ;
}
static enum V_153 F_71 ( struct V_154 * V_154 )
{
struct V_1 * V_2 =
F_72 ( V_154 , F_73 ( * V_2 ) ,
V_4 . V_5 . V_125 ) ;
if ( ! V_2 -> V_4 . V_5 . V_45 . V_58 ( V_2 ) ) {
V_2 -> V_4 . V_5 . V_82 = true ;
F_74 ( & V_2 -> V_4 . V_5 . V_57 ) ;
}
F_75 ( V_154 , F_59 ( V_126 ) ) ;
return V_155 ;
}
static unsigned int F_76 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_59 * V_59 ,
T_5 * V_60 )
{
unsigned int V_156 = 0 ;
V_18 -> V_45 -> F_20 ( V_18 , V_59 , V_60 ) ;
if ( V_2 -> V_4 . V_5 . V_82 )
V_156 |= V_157 ;
return V_156 ;
}
static unsigned int F_77 ( struct V_59 * V_59 , T_5 * V_60 )
{
struct V_17 * V_18 = V_59 -> V_148 ;
struct V_1 * V_2 = V_18 -> V_2 ;
int V_42 ;
F_26 ( & V_2 -> V_4 . V_152 ) ;
V_42 = F_76 ( V_2 , V_18 , V_59 , V_60 ) ;
F_24 ( & V_2 -> V_4 . V_152 ) ;
return V_42 ;
}
static void F_78 ( struct V_17 * V_18 )
{
if ( V_18 -> V_43 )
return;
V_18 -> V_43 = true ;
if ( V_18 -> V_45 -> V_158 )
V_18 -> V_45 -> V_158 ( V_18 ) ;
}
static void F_79 ( struct V_17 * V_18 )
{
if ( ! V_18 -> V_43 )
return;
V_18 -> V_43 = false ;
if ( V_18 -> V_45 -> V_159 )
V_18 -> V_45 -> V_159 ( V_18 ) ;
}
static long F_80 ( struct V_17 * V_18 ,
unsigned int V_160 ,
unsigned long V_161 )
{
switch ( V_160 ) {
case V_162 :
F_78 ( V_18 ) ;
return 0 ;
case V_163 :
F_79 ( V_18 ) ;
return 0 ;
}
return - V_135 ;
}
static long F_81 ( struct V_59 * V_59 ,
unsigned int V_160 ,
unsigned long V_161 )
{
struct V_17 * V_18 = V_59 -> V_148 ;
struct V_1 * V_2 = V_18 -> V_2 ;
long V_42 ;
F_26 ( & V_2 -> V_4 . V_152 ) ;
V_42 = F_80 ( V_18 , V_160 , V_161 ) ;
F_24 ( & V_2 -> V_4 . V_152 ) ;
return V_42 ;
}
static void F_82 ( struct V_17 * V_18 )
{
if ( V_18 -> V_43 )
F_79 ( V_18 ) ;
if ( V_18 -> V_45 -> V_164 )
V_18 -> V_45 -> V_164 ( V_18 ) ;
F_83 ( & V_18 -> V_165 ) ;
if ( V_18 -> V_67 )
F_84 ( V_18 -> V_67 ) ;
F_85 ( V_18 ) ;
}
static int F_86 ( struct V_166 * V_166 , struct V_59 * V_59 )
{
struct V_17 * V_18 = V_59 -> V_148 ;
struct V_1 * V_2 = V_18 -> V_2 ;
F_26 ( & V_2 -> V_4 . V_152 ) ;
F_82 ( V_18 ) ;
F_24 ( & V_2 -> V_4 . V_152 ) ;
return 0 ;
}
static struct V_112 *
F_87 ( struct V_1 * V_2 ,
struct V_167 * V_168 ,
T_1 V_169 )
{
struct V_112 * V_67 ;
int V_42 ;
V_42 = F_23 ( & V_2 -> V_65 ) ;
if ( V_42 )
return F_88 ( V_42 ) ;
V_67 = F_89 ( V_168 , V_169 ) ;
if ( ! F_40 ( V_67 ) )
F_90 ( V_67 ) ;
F_24 ( & V_2 -> V_65 . V_72 ) ;
return V_67 ;
}
static int
F_91 ( struct V_1 * V_2 ,
struct V_130 * V_131 ,
struct V_132 * V_133 ,
struct V_170 * V_59 )
{
struct V_112 * V_171 = NULL ;
struct V_17 * V_18 = NULL ;
unsigned long V_149 = 0 ;
int V_172 ;
int V_42 ;
if ( V_133 -> V_173 ) {
T_1 V_174 = V_133 -> V_174 ;
struct V_167 * V_168 = V_59 -> V_175 ;
V_171 = F_87 ( V_2 , V_168 , V_174 ) ;
if ( F_40 ( V_171 ) ) {
V_42 = F_41 ( V_171 ) ;
if ( V_42 != - V_176 )
F_14 ( L_14 ,
V_174 ) ;
goto V_177;
}
}
if ( ! V_171 &&
V_178 && ! F_92 ( V_179 ) ) {
F_14 ( L_15 ) ;
V_42 = - V_180 ;
goto V_181;
}
V_18 = F_93 ( sizeof( * V_18 ) , V_182 ) ;
if ( ! V_18 ) {
V_42 = - V_183 ;
goto V_181;
}
V_18 -> V_2 = V_2 ;
V_18 -> V_67 = V_171 ;
V_42 = F_65 ( V_18 , V_131 , V_133 ) ;
if ( V_42 )
goto V_184;
if ( F_9 ( V_18 -> V_29 != V_133 -> V_29 ) ) {
V_42 = - V_86 ;
goto V_185;
}
F_94 ( & V_18 -> V_165 , & V_2 -> V_4 . V_186 ) ;
if ( V_131 -> V_124 & V_187 )
V_149 |= V_188 ;
if ( V_131 -> V_124 & V_189 )
V_149 |= V_150 ;
V_172 = F_95 ( L_16 , & V_190 , V_18 , V_149 ) ;
if ( V_172 < 0 ) {
V_42 = V_172 ;
goto V_191;
}
if ( ! ( V_131 -> V_124 & V_192 ) )
F_78 ( V_18 ) ;
return V_172 ;
V_191:
F_83 ( & V_18 -> V_165 ) ;
V_185:
if ( V_18 -> V_45 -> V_164 )
V_18 -> V_45 -> V_164 ( V_18 ) ;
V_184:
F_85 ( V_18 ) ;
V_181:
if ( V_171 )
F_84 ( V_171 ) ;
V_177:
return V_42 ;
}
static int F_96 ( struct V_1 * V_2 ,
T_6 T_2 * V_193 ,
T_1 V_194 ,
struct V_132 * V_133 )
{
T_6 T_2 * V_195 = V_193 ;
int V_97 ;
memset ( V_133 , 0 , sizeof( struct V_132 ) ) ;
if ( ! V_194 ) {
F_14 ( L_17 ) ;
return - V_135 ;
}
if ( V_194 >= V_196 ) {
F_14 ( L_18 ) ;
return - V_135 ;
}
for ( V_97 = 0 ; V_97 < V_194 ; V_97 ++ ) {
T_6 V_197 , V_198 ;
T_6 V_70 , V_100 ;
int V_42 ;
V_42 = F_97 ( V_70 , V_195 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_97 ( V_100 , V_195 + 1 ) ;
if ( V_42 )
return V_42 ;
if ( V_70 == 0 || V_70 >= V_196 ) {
F_14 ( L_19 ) ;
return - V_135 ;
}
switch ( (enum V_199 ) V_70 ) {
case V_200 :
V_133 -> V_173 = 1 ;
V_133 -> V_174 = V_100 ;
break;
case V_201 :
V_133 -> V_29 |= V_33 ;
break;
case V_202 :
if ( V_100 == 0 ||
V_100 > V_2 -> V_4 . V_5 . V_203 ) {
F_14 ( L_20 ) ;
return - V_135 ;
}
V_133 -> V_137 = V_100 ;
break;
case V_204 :
if ( V_100 == 0 || V_100 >= V_205 ) {
F_14 ( L_21 ) ;
return - V_135 ;
}
if ( ! V_2 -> V_4 . V_5 . V_139 [ V_100 ] . V_25 ) {
F_14 ( L_21 ) ;
return - V_135 ;
}
V_133 -> V_138 = V_100 ;
break;
case V_206 :
if ( V_100 > V_207 ) {
F_14 ( L_22 ,
V_207 ) ;
return - V_135 ;
}
F_38 ( sizeof( V_197 ) != 8 ) ;
V_197 = 80ull * ( 2ull << V_100 ) ;
if ( V_197 <= V_208 ) {
T_6 V_209 = V_208 ;
F_98 ( V_209 , V_197 ) ;
V_198 = V_209 ;
} else
V_198 = 0 ;
if ( V_198 > V_210 &&
! F_92 ( V_179 ) ) {
F_14 ( L_23 ,
V_210 ) ;
return - V_180 ;
}
V_133 -> V_140 = true ;
V_133 -> V_141 = V_100 ;
break;
case V_196 :
F_99 ( V_70 ) ;
return - V_135 ;
}
V_195 += 2 ;
}
return 0 ;
}
int F_100 ( struct V_211 * V_212 , void * V_213 ,
struct V_170 * V_59 )
{
struct V_1 * V_2 = V_212 -> V_214 ;
struct V_130 * V_131 = V_213 ;
struct V_132 V_133 ;
T_1 V_215 ;
int V_42 ;
if ( ! V_2 -> V_4 . V_216 ) {
F_14 ( L_24 ) ;
return - V_217 ;
}
V_215 = V_187 |
V_189 |
V_192 ;
if ( V_131 -> V_124 & ~ V_215 ) {
F_14 ( L_25 ) ;
return - V_135 ;
}
V_42 = F_96 ( V_2 ,
F_101 ( V_131 -> V_218 ) ,
V_131 -> V_219 ,
& V_133 ) ;
if ( V_42 )
return V_42 ;
F_26 ( & V_2 -> V_4 . V_152 ) ;
V_42 = F_91 ( V_2 , V_131 , & V_133 , V_59 ) ;
F_24 ( & V_2 -> V_4 . V_152 ) ;
return V_42 ;
}
void F_102 ( struct V_1 * V_2 )
{
if ( ! F_103 ( V_2 ) )
return;
if ( ! V_2 -> V_4 . V_216 )
return;
F_26 ( & V_2 -> V_4 . V_152 ) ;
V_2 -> V_4 . V_134 =
F_104 ( L_26 ,
& V_2 -> V_65 . V_220 -> V_221 -> V_222 ) ;
if ( ! V_2 -> V_4 . V_134 )
goto exit;
if ( F_105 ( V_2 ) ) {
F_106 ( V_2 -> V_4 . V_134 ) ;
V_2 -> V_4 . V_134 = NULL ;
}
exit:
F_24 ( & V_2 -> V_4 . V_152 ) ;
}
void F_107 ( struct V_1 * V_2 )
{
if ( ! F_103 ( V_2 ) )
return;
if ( ! V_2 -> V_4 . V_134 )
return;
F_108 ( V_2 ) ;
F_106 ( V_2 -> V_4 . V_134 ) ;
V_2 -> V_4 . V_134 = NULL ;
}
void F_109 ( struct V_1 * V_2 )
{
if ( ! F_103 ( V_2 ) )
return;
F_110 ( & V_2 -> V_4 . V_5 . V_125 ,
V_223 , V_224 ) ;
V_2 -> V_4 . V_5 . V_125 . V_225 = F_71 ;
F_111 ( & V_2 -> V_4 . V_5 . V_57 ) ;
F_112 ( & V_2 -> V_4 . V_186 ) ;
F_113 ( & V_2 -> V_4 . V_152 ) ;
F_114 ( & V_2 -> V_4 . V_111 ) ;
V_2 -> V_4 . V_5 . V_45 . V_93 = F_35 ;
V_2 -> V_4 . V_5 . V_45 . V_144 = F_48 ;
V_2 -> V_4 . V_5 . V_45 . V_78 = F_51 ;
V_2 -> V_4 . V_5 . V_45 . V_47 = F_54 ;
V_2 -> V_4 . V_5 . V_45 . V_46 = F_60 ;
V_2 -> V_4 . V_5 . V_45 . V_61 = F_12 ;
V_2 -> V_4 . V_5 . V_45 . V_58 =
F_1 ;
V_2 -> V_4 . V_5 . V_129 = 12500000 ;
V_2 -> V_4 . V_5 . V_139 = V_226 ;
V_2 -> V_4 . V_5 . V_203 =
V_227 ;
V_2 -> V_4 . V_228 = F_115 ( V_229 ) ;
V_2 -> V_4 . V_216 = true ;
}
void F_116 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_4 . V_216 )
return;
F_117 ( V_2 -> V_4 . V_228 ) ;
memset ( & V_2 -> V_4 . V_5 . V_45 , 0 , sizeof( V_2 -> V_4 . V_5 . V_45 ) ) ;
V_2 -> V_4 . V_216 = false ;
}
