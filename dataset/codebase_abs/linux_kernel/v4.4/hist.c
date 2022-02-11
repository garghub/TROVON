T_1 F_1 ( struct V_1 * V_1 , enum V_2 V_3 )
{
return V_1 -> V_4 [ V_3 ] ;
}
void F_2 ( struct V_1 * V_1 , enum V_2 V_3 , T_1 V_5 )
{
V_1 -> V_4 [ V_3 ] = V_5 ;
}
bool F_3 ( struct V_1 * V_1 , enum V_2 V_3 , T_1 V_5 )
{
if ( V_5 > F_1 ( V_1 , V_3 ) ) {
F_2 ( V_1 , V_3 , V_5 ) ;
return true ;
}
return false ;
}
void F_4 ( struct V_1 * V_1 )
{
enum V_2 V_3 ;
for ( V_3 = 0 ; V_3 < V_6 ; ++ V_3 )
F_2 ( V_1 , V_3 , 0 ) ;
}
static void F_5 ( struct V_1 * V_1 , int V_7 )
{
const unsigned int V_8 = V_9 / 4 ;
if ( F_1 ( V_1 , V_7 ) < V_8 &&
! V_10 . V_11 && ! V_10 . V_12 &&
! V_10 . V_13 )
F_2 ( V_1 , V_7 , V_8 ) ;
}
void F_6 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
const unsigned int V_8 = V_9 / 4 ;
int V_16 ;
T_1 V_5 ;
if ( V_15 -> V_17 . V_18 ) {
V_16 = V_15 -> V_17 . V_18 -> V_19 + 4 ;
if ( V_20 )
V_16 += V_9 / 4 + 2 + 3 ;
F_3 ( V_1 , V_21 , V_16 ) ;
} else {
V_16 = V_8 + 4 + 2 ;
F_3 ( V_1 , V_21 , V_16 ) ;
F_5 ( V_1 , V_22 ) ;
}
V_5 = F_7 ( V_15 -> V_23 ) ;
if ( F_3 ( V_1 , V_24 , V_5 ) )
F_2 ( V_1 , V_25 , V_5 + 6 ) ;
if ( V_15 -> V_17 . V_26 ) {
V_5 = F_8 ( V_15 -> V_17 . V_26 -> V_7 ) ;
F_3 ( V_1 , V_22 , V_5 ) ;
}
if ( V_15 -> V_27 )
F_3 ( V_1 , V_28 , V_15 -> V_27 -> V_19 ) ;
if ( V_15 -> V_29 ) {
if ( V_15 -> V_29 -> V_30 . V_18 ) {
V_16 = ( int ) V_15 -> V_29 -> V_30 . V_18 -> V_19 + 4 ;
if ( V_20 )
V_16 += V_9 / 4 + 2 + 3 ;
F_3 ( V_1 , V_31 , V_16 ) ;
V_16 = F_8 ( V_15 -> V_29 -> V_30 . V_26 -> V_7 ) ;
F_3 ( V_1 , V_32 , V_16 ) ;
} else {
V_16 = V_8 + 4 + 2 ;
F_3 ( V_1 , V_31 , V_16 ) ;
F_5 ( V_1 , V_32 ) ;
}
if ( V_15 -> V_29 -> V_33 . V_18 ) {
V_16 = ( int ) V_15 -> V_29 -> V_33 . V_18 -> V_19 + 4 ;
if ( V_20 )
V_16 += V_9 / 4 + 2 + 3 ;
F_3 ( V_1 , V_34 , V_16 ) ;
V_16 = F_8 ( V_15 -> V_29 -> V_33 . V_26 -> V_7 ) ;
F_3 ( V_1 , V_35 , V_16 ) ;
} else {
V_16 = V_8 + 4 + 2 ;
F_3 ( V_1 , V_34 , V_16 ) ;
F_5 ( V_1 , V_35 ) ;
}
}
if ( V_15 -> V_36 ) {
if ( V_15 -> V_36 -> V_37 . V_18 ) {
V_16 = ( int ) V_15 -> V_36 -> V_37 . V_18 -> V_19 + 4
+ V_8 + 2 ;
F_3 ( V_1 , V_38 ,
V_16 ) ;
F_3 ( V_1 , V_39 ,
V_16 + 1 ) ;
} else {
V_16 = V_8 + 4 + 2 ;
F_3 ( V_1 , V_38 ,
V_16 ) ;
}
if ( V_15 -> V_36 -> V_40 . V_18 ) {
V_16 = ( int ) V_15 -> V_36 -> V_40 . V_18 -> V_19 + 4
+ V_8 + 2 ;
F_3 ( V_1 , V_41 ,
V_16 ) ;
} else {
V_16 = V_8 + 4 + 2 ;
F_3 ( V_1 , V_41 ,
V_16 ) ;
}
if ( V_15 -> V_36 -> V_37 . V_26 ) {
V_16 = F_8 ( V_15 -> V_36 -> V_37 . V_26 -> V_7 ) ;
F_3 ( V_1 , V_42 ,
V_16 ) ;
} else {
V_16 = V_8 + 4 + 2 ;
F_5 ( V_1 , V_42 ) ;
}
} else {
V_16 = V_8 + 4 + 2 ;
F_3 ( V_1 , V_38 , V_16 ) ;
F_3 ( V_1 , V_41 , V_16 ) ;
F_5 ( V_1 , V_42 ) ;
}
F_3 ( V_1 , V_43 , 3 ) ;
F_3 ( V_1 , V_44 , 6 ) ;
F_3 ( V_1 , V_45 , 6 ) ;
F_3 ( V_1 , V_46 , 22 ) ;
F_3 ( V_1 , V_47 , 12 ) ;
F_3 ( V_1 , V_48 , 21 + 3 ) ;
F_3 ( V_1 , V_49 , 12 ) ;
F_3 ( V_1 , V_50 , 12 ) ;
if ( V_15 -> V_51 )
F_3 ( V_1 , V_52 , strlen ( V_15 -> V_51 ) ) ;
if ( V_15 -> V_53 )
F_3 ( V_1 , V_54 , strlen ( V_15 -> V_53 ) ) ;
if ( V_15 -> V_55 )
F_3 ( V_1 , V_56 ,
F_9 () ) ;
}
void F_10 ( struct V_1 * V_1 , int V_57 )
{
struct V_58 * V_59 = F_11 ( & V_1 -> V_60 ) ;
struct V_14 * V_61 ;
int V_62 = 0 ;
F_4 ( V_1 ) ;
while ( V_59 && V_62 ++ < V_57 ) {
V_61 = F_12 ( V_59 , struct V_14 , V_58 ) ;
if ( ! V_61 -> V_63 )
F_6 ( V_1 , V_61 ) ;
V_59 = F_13 ( & V_61 -> V_58 ) ;
}
}
static void F_14 ( struct V_64 * V_64 ,
unsigned int V_65 , T_2 V_66 )
{
switch ( V_65 ) {
case V_67 :
V_64 -> V_68 += V_66 ;
break;
case V_69 :
V_64 -> V_70 += V_66 ;
break;
case V_71 :
V_64 -> V_72 += V_66 ;
break;
case V_73 :
V_64 -> V_74 += V_66 ;
break;
default:
break;
}
}
static void F_15 ( struct V_64 * V_64 , T_2 V_66 ,
T_2 V_75 )
{
V_64 -> V_66 += V_66 ;
V_64 -> V_75 += V_75 ;
V_64 -> V_76 += 1 ;
}
static void F_16 ( struct V_64 * V_77 , struct V_64 * V_78 )
{
V_77 -> V_66 += V_78 -> V_66 ;
V_77 -> V_68 += V_78 -> V_68 ;
V_77 -> V_70 += V_78 -> V_70 ;
V_77 -> V_72 += V_78 -> V_72 ;
V_77 -> V_74 += V_78 -> V_74 ;
V_77 -> V_76 += V_78 -> V_76 ;
V_77 -> V_75 += V_78 -> V_75 ;
}
static void F_17 ( struct V_64 * V_64 )
{
V_64 -> V_66 = ( V_64 -> V_66 * 7 ) / 8 ;
V_64 -> V_76 = ( V_64 -> V_76 * 7 ) / 8 ;
}
static bool F_18 ( struct V_1 * V_1 , struct V_14 * V_79 )
{
T_2 V_80 = V_79 -> V_81 . V_66 ;
T_2 V_82 ;
if ( V_80 == 0 )
return true ;
F_17 ( & V_79 -> V_81 ) ;
if ( V_10 . V_83 )
F_17 ( V_79 -> V_84 ) ;
V_82 = V_80 - V_79 -> V_81 . V_66 ;
V_1 -> V_85 . V_86 -= V_82 ;
if ( ! V_79 -> V_63 )
V_1 -> V_85 . V_87 -= V_82 ;
return V_79 -> V_81 . V_66 == 0 ;
}
static void F_19 ( struct V_1 * V_1 , struct V_14 * V_79 )
{
F_20 ( & V_79 -> V_58 , & V_1 -> V_60 ) ;
if ( V_88 )
F_20 ( & V_79 -> V_89 , & V_1 -> V_90 ) ;
-- V_1 -> V_91 ;
if ( ! V_79 -> V_63 )
-- V_1 -> V_92 ;
F_21 ( V_79 ) ;
}
void F_22 ( struct V_1 * V_1 , bool V_93 , bool V_94 )
{
struct V_58 * V_59 = F_11 ( & V_1 -> V_60 ) ;
struct V_14 * V_61 ;
while ( V_59 ) {
V_61 = F_12 ( V_59 , struct V_14 , V_58 ) ;
V_59 = F_13 ( & V_61 -> V_58 ) ;
if ( ( ( V_93 && V_61 -> V_95 == '.' ) ||
( V_94 && V_61 -> V_95 != '.' ) ||
F_18 ( V_1 , V_61 ) ) ) {
F_19 ( V_1 , V_61 ) ;
}
}
}
void F_23 ( struct V_1 * V_1 )
{
struct V_58 * V_59 = F_11 ( & V_1 -> V_60 ) ;
struct V_14 * V_61 ;
while ( V_59 ) {
V_61 = F_12 ( V_59 , struct V_14 , V_58 ) ;
V_59 = F_13 ( & V_61 -> V_58 ) ;
F_19 ( V_1 , V_61 ) ;
}
}
static struct V_14 * F_24 ( struct V_14 * V_96 ,
bool V_97 )
{
T_3 V_98 = 0 ;
struct V_14 * V_79 ;
if ( V_10 . V_99 )
V_98 = sizeof( struct V_100 ) ;
V_79 = F_25 ( sizeof( * V_79 ) + V_98 ) ;
if ( V_79 != NULL ) {
* V_79 = * V_96 ;
if ( V_10 . V_83 ) {
V_79 -> V_84 = malloc ( sizeof( V_79 -> V_81 ) ) ;
if ( V_79 -> V_84 == NULL ) {
free ( V_79 ) ;
return NULL ;
}
memcpy ( V_79 -> V_84 , & V_79 -> V_81 , sizeof( V_79 -> V_81 ) ) ;
if ( ! V_97 )
memset ( & V_79 -> V_81 , 0 , sizeof( V_79 -> V_81 ) ) ;
}
F_26 ( V_79 -> V_17 . V_26 ) ;
if ( V_79 -> V_29 ) {
V_79 -> V_29 = malloc ( sizeof( * V_79 -> V_29 ) ) ;
if ( V_79 -> V_29 == NULL ) {
F_27 ( V_79 -> V_17 . V_26 ) ;
free ( V_79 -> V_84 ) ;
free ( V_79 ) ;
return NULL ;
}
memcpy ( V_79 -> V_29 , V_96 -> V_29 ,
sizeof( * V_79 -> V_29 ) ) ;
F_26 ( V_79 -> V_29 -> V_30 . V_26 ) ;
F_26 ( V_79 -> V_29 -> V_33 . V_26 ) ;
}
if ( V_79 -> V_36 ) {
F_26 ( V_79 -> V_36 -> V_40 . V_26 ) ;
F_26 ( V_79 -> V_36 -> V_37 . V_26 ) ;
}
if ( V_10 . V_99 )
F_28 ( V_79 -> V_101 ) ;
F_29 ( & V_79 -> V_102 . V_103 ) ;
F_30 ( V_79 -> V_23 ) ;
}
return V_79 ;
}
static T_4 F_31 ( const struct V_104 * V_27 )
{
if ( V_10 . V_105 && V_27 == NULL )
return 1 << V_106 ;
return 0 ;
}
static struct V_14 * F_32 ( struct V_1 * V_1 ,
struct V_14 * V_107 ,
struct V_108 * V_109 ,
bool V_97 )
{
struct V_58 * * V_110 ;
struct V_58 * V_27 = NULL ;
struct V_14 * V_79 ;
T_5 V_111 ;
T_2 V_66 = V_107 -> V_81 . V_66 ;
T_2 V_75 = V_107 -> V_81 . V_75 ;
V_110 = & V_1 -> V_112 -> V_58 ;
while ( * V_110 != NULL ) {
V_27 = * V_110 ;
V_79 = F_12 ( V_27 , struct V_14 , V_89 ) ;
V_111 = F_33 ( V_79 , V_107 ) ;
if ( ! V_111 ) {
if ( V_97 )
F_15 ( & V_79 -> V_81 , V_66 , V_75 ) ;
if ( V_10 . V_83 )
F_15 ( V_79 -> V_84 , V_66 , V_75 ) ;
F_34 ( & V_107 -> V_36 ) ;
if ( V_79 -> V_17 . V_26 != V_107 -> V_17 . V_26 ) {
F_35 ( V_79 -> V_17 . V_26 ) ;
V_79 -> V_17 . V_26 = F_26 ( V_107 -> V_17 . V_26 ) ;
}
goto V_113;
}
if ( V_111 < 0 )
V_110 = & ( * V_110 ) -> V_114 ;
else
V_110 = & ( * V_110 ) -> V_115 ;
}
V_79 = F_24 ( V_107 , V_97 ) ;
if ( ! V_79 )
return NULL ;
V_1 -> V_91 ++ ;
F_36 ( & V_79 -> V_89 , V_27 , V_110 ) ;
F_37 ( & V_79 -> V_89 , V_1 -> V_112 ) ;
V_113:
if ( V_97 )
F_14 ( & V_79 -> V_81 , V_109 -> V_65 , V_66 ) ;
if ( V_10 . V_83 )
F_14 ( V_79 -> V_84 , V_109 -> V_65 , V_66 ) ;
return V_79 ;
}
struct V_14 * F_38 ( struct V_1 * V_1 ,
struct V_108 * V_109 ,
struct V_104 * V_116 ,
struct V_29 * V_117 ,
struct V_36 * V_118 ,
T_2 V_66 , T_2 V_75 , T_2 V_55 ,
bool V_97 )
{
struct V_14 V_107 = {
. V_23 = V_109 -> V_23 ,
. V_119 = F_39 ( V_109 -> V_23 ) ,
. V_17 = {
. V_26 = V_109 -> V_26 ,
. V_18 = V_109 -> V_18 ,
} ,
. V_120 = V_109 -> V_120 ,
. V_121 = V_109 -> V_121 ,
. V_65 = V_109 -> V_65 ,
. V_122 = V_109 -> V_123 ,
. V_95 = V_109 -> V_95 ,
. V_81 = {
. V_76 = 1 ,
. V_66 = V_66 ,
. V_75 = V_75 ,
} ,
. V_27 = V_116 ,
. V_63 = F_31 ( V_116 ) | V_109 -> V_63 ,
. V_1 = V_1 ,
. V_29 = V_117 ,
. V_36 = V_118 ,
. V_55 = V_55 ,
} ;
return F_32 ( V_1 , & V_107 , V_109 , V_97 ) ;
}
static int
F_40 ( struct V_124 * T_6 V_125 ,
struct V_108 * V_109 V_125 )
{
return 0 ;
}
static int
F_41 ( struct V_124 * T_6 V_125 ,
struct V_108 * V_109 V_125 )
{
return 0 ;
}
static int
F_42 ( struct V_124 * T_6 , struct V_108 * V_109 )
{
struct V_126 * V_127 = T_6 -> V_127 ;
struct V_36 * V_118 ;
V_118 = F_43 ( V_127 , V_109 ) ;
if ( V_118 == NULL )
return - V_128 ;
T_6 -> V_129 = V_118 ;
return 0 ;
}
static int
F_44 ( struct V_124 * T_6 , struct V_108 * V_109 )
{
T_2 V_130 ;
struct V_36 * V_118 = T_6 -> V_129 ;
struct V_1 * V_1 = F_45 ( T_6 -> V_131 ) ;
struct V_14 * V_79 ;
if ( V_118 == NULL )
return - V_132 ;
V_130 = T_6 -> V_127 -> V_75 ;
if ( ! V_130 )
V_130 = 1 ;
V_79 = F_38 ( V_1 , V_109 , T_6 -> V_27 , NULL , V_118 ,
V_130 , V_130 , 0 , true ) ;
if ( ! V_79 )
return - V_128 ;
T_6 -> V_79 = V_79 ;
return 0 ;
}
static int
F_46 ( struct V_124 * T_6 ,
struct V_108 * V_109 V_125 )
{
struct V_133 * V_131 = T_6 -> V_131 ;
struct V_1 * V_1 = F_45 ( V_131 ) ;
struct V_14 * V_79 = T_6 -> V_79 ;
int V_134 = - V_132 ;
if ( V_79 == NULL )
goto V_113;
F_47 ( V_1 , V_79 -> V_63 ) ;
V_134 = F_48 ( V_79 , T_6 -> V_127 ) ;
V_113:
T_6 -> V_129 = NULL ;
T_6 -> V_79 = NULL ;
return V_134 ;
}
static int
F_49 ( struct V_124 * T_6 , struct V_108 * V_109 )
{
struct V_29 * V_117 ;
struct V_126 * V_127 = T_6 -> V_127 ;
V_117 = F_50 ( V_127 , V_109 ) ;
if ( ! V_117 )
return - V_128 ;
T_6 -> V_135 = 0 ;
T_6 -> V_136 = V_127 -> V_137 -> V_138 ;
T_6 -> V_129 = V_117 ;
return 0 ;
}
static int
F_51 ( struct V_124 * T_6 V_125 ,
struct V_108 * V_109 V_125 )
{
T_6 -> V_79 = NULL ;
return 0 ;
}
static int
F_52 ( struct V_124 * T_6 , struct V_108 * V_109 )
{
struct V_29 * V_117 = T_6 -> V_129 ;
int V_139 = T_6 -> V_135 ;
if ( V_117 == NULL )
return 0 ;
if ( T_6 -> V_135 >= T_6 -> V_136 )
return 0 ;
V_109 -> V_26 = V_117 [ V_139 ] . V_33 . V_26 ;
V_109 -> V_18 = V_117 [ V_139 ] . V_33 . V_18 ;
V_109 -> V_123 = V_117 [ V_139 ] . V_33 . V_123 ;
return 1 ;
}
static int
F_53 ( struct V_124 * T_6 , struct V_108 * V_109 )
{
struct V_29 * V_117 ;
struct V_133 * V_131 = T_6 -> V_131 ;
struct V_1 * V_1 = F_45 ( V_131 ) ;
struct V_14 * V_79 = NULL ;
int V_139 = T_6 -> V_135 ;
int V_134 = 0 ;
V_117 = T_6 -> V_129 ;
if ( T_6 -> V_140 && ! ( V_117 [ V_139 ] . V_30 . V_18 && V_117 [ V_139 ] . V_33 . V_18 ) )
goto V_113;
V_79 = F_38 ( V_1 , V_109 , T_6 -> V_27 , & V_117 [ V_139 ] , NULL ,
1 , V_117 -> V_141 . V_142 ? V_117 -> V_141 . V_142 : 1 ,
0 , true ) ;
if ( V_79 == NULL )
return - V_128 ;
F_47 ( V_1 , V_79 -> V_63 ) ;
V_113:
T_6 -> V_79 = V_79 ;
T_6 -> V_135 ++ ;
return V_134 ;
}
static int
F_54 ( struct V_124 * T_6 ,
struct V_108 * V_109 V_125 )
{
F_34 ( & T_6 -> V_129 ) ;
T_6 -> V_79 = NULL ;
return T_6 -> V_135 >= T_6 -> V_136 ? 0 : - 1 ;
}
static int
F_55 ( struct V_124 * T_6 V_125 ,
struct V_108 * V_109 V_125 )
{
return 0 ;
}
static int
F_56 ( struct V_124 * T_6 , struct V_108 * V_109 )
{
struct V_133 * V_131 = T_6 -> V_131 ;
struct V_126 * V_127 = T_6 -> V_127 ;
struct V_14 * V_79 ;
V_79 = F_38 ( F_45 ( V_131 ) , V_109 , T_6 -> V_27 , NULL , NULL ,
V_127 -> V_66 , V_127 -> V_75 ,
V_127 -> V_55 , true ) ;
if ( V_79 == NULL )
return - V_128 ;
T_6 -> V_79 = V_79 ;
return 0 ;
}
static int
F_57 ( struct V_124 * T_6 ,
struct V_108 * V_109 V_125 )
{
struct V_14 * V_79 = T_6 -> V_79 ;
struct V_133 * V_131 = T_6 -> V_131 ;
struct V_126 * V_127 = T_6 -> V_127 ;
if ( V_79 == NULL )
return 0 ;
T_6 -> V_79 = NULL ;
F_47 ( F_45 ( V_131 ) , V_79 -> V_63 ) ;
return F_48 ( V_79 , V_127 ) ;
}
static int
F_58 ( struct V_124 * T_6 ,
struct V_108 * V_109 V_125 )
{
struct V_14 * * V_143 ;
F_59 ( & V_144 ) ;
V_143 = malloc ( sizeof( * V_143 ) * ( T_6 -> V_145 + 1 ) ) ;
if ( V_143 == NULL )
return - V_128 ;
T_6 -> V_129 = V_143 ;
T_6 -> V_135 = 0 ;
return 0 ;
}
static int
F_60 ( struct V_124 * T_6 ,
struct V_108 * V_109 )
{
struct V_133 * V_131 = T_6 -> V_131 ;
struct V_1 * V_1 = F_45 ( V_131 ) ;
struct V_126 * V_127 = T_6 -> V_127 ;
struct V_14 * * V_143 = T_6 -> V_129 ;
struct V_14 * V_79 ;
int V_134 = 0 ;
V_79 = F_38 ( V_1 , V_109 , T_6 -> V_27 , NULL , NULL ,
V_127 -> V_66 , V_127 -> V_75 ,
V_127 -> V_55 , true ) ;
if ( V_79 == NULL )
return - V_128 ;
T_6 -> V_79 = V_79 ;
V_143 [ T_6 -> V_135 ++ ] = V_79 ;
F_48 ( V_79 , V_127 ) ;
F_59 ( & V_144 ) ;
F_47 ( V_1 , V_79 -> V_63 ) ;
return V_134 ;
}
static int
F_61 ( struct V_124 * T_6 ,
struct V_108 * V_109 )
{
struct V_146 * V_103 ;
V_103 = F_62 ( & V_144 ) ;
if ( V_103 == NULL )
return 0 ;
return F_63 ( V_109 , V_103 , T_6 -> V_140 ) ;
}
static int
F_64 ( struct V_124 * T_6 ,
struct V_108 * V_109 )
{
struct V_133 * V_131 = T_6 -> V_131 ;
struct V_126 * V_127 = T_6 -> V_127 ;
struct V_14 * * V_143 = T_6 -> V_129 ;
struct V_14 * V_79 ;
struct V_14 V_147 = {
. V_1 = F_45 ( V_131 ) ,
. V_121 = V_109 -> V_121 ,
. V_23 = V_109 -> V_23 ,
. V_119 = F_39 ( V_109 -> V_23 ) ,
. V_122 = V_109 -> V_123 ,
. V_17 = {
. V_26 = V_109 -> V_26 ,
. V_18 = V_109 -> V_18 ,
} ,
. V_27 = T_6 -> V_27 ,
} ;
int V_139 ;
struct V_144 V_148 ;
F_65 ( & V_148 , & V_144 ) ;
F_66 ( & V_144 ) ;
for ( V_139 = 0 ; V_139 < T_6 -> V_135 ; V_139 ++ ) {
if ( F_33 ( V_143 [ V_139 ] , & V_147 ) == 0 ) {
T_6 -> V_79 = NULL ;
return 0 ;
}
}
V_79 = F_38 ( F_45 ( V_131 ) , V_109 , T_6 -> V_27 , NULL , NULL ,
V_127 -> V_66 , V_127 -> V_75 ,
V_127 -> V_55 , false ) ;
if ( V_79 == NULL )
return - V_128 ;
T_6 -> V_79 = V_79 ;
V_143 [ T_6 -> V_135 ++ ] = V_79 ;
if ( V_10 . V_99 )
F_67 ( V_79 -> V_101 , & V_148 , V_127 -> V_66 ) ;
return 0 ;
}
static int
F_68 ( struct V_124 * T_6 ,
struct V_108 * V_109 V_125 )
{
F_34 ( & T_6 -> V_129 ) ;
T_6 -> V_79 = NULL ;
return 0 ;
}
int F_69 ( struct V_124 * T_6 , struct V_108 * V_109 ,
int V_149 , void * V_150 )
{
int V_134 , V_151 ;
V_134 = F_70 ( T_6 -> V_127 , & T_6 -> V_27 ,
T_6 -> V_131 , V_109 , V_149 ) ;
if ( V_134 )
return V_134 ;
T_6 -> V_145 = V_149 ;
V_134 = T_6 -> V_152 -> V_153 ( T_6 , V_109 ) ;
if ( V_134 )
goto V_113;
V_134 = T_6 -> V_152 -> V_154 ( T_6 , V_109 ) ;
if ( V_134 )
goto V_113;
if ( T_6 -> V_79 && T_6 -> V_155 ) {
V_134 = T_6 -> V_155 ( T_6 , V_109 , true , V_150 ) ;
if ( V_134 )
goto V_113;
}
while ( T_6 -> V_152 -> V_156 ( T_6 , V_109 ) ) {
V_134 = T_6 -> V_152 -> V_157 ( T_6 , V_109 ) ;
if ( V_134 )
break;
if ( T_6 -> V_79 && T_6 -> V_155 ) {
V_134 = T_6 -> V_155 ( T_6 , V_109 , false , V_150 ) ;
if ( V_134 )
goto V_113;
}
}
V_113:
V_151 = T_6 -> V_152 -> V_158 ( T_6 , V_109 ) ;
if ( ! V_134 )
V_134 = V_151 ;
return V_134 ;
}
T_5
F_33 ( struct V_14 * V_159 , struct V_14 * V_160 )
{
struct V_161 * V_162 ;
T_5 V_111 = 0 ;
F_71 (fmt) {
if ( F_72 ( V_162 ) )
continue;
V_111 = V_162 -> V_111 ( V_162 , V_159 , V_160 ) ;
if ( V_111 )
break;
}
return V_111 ;
}
T_5
F_73 ( struct V_14 * V_159 , struct V_14 * V_160 )
{
struct V_161 * V_162 ;
T_5 V_111 = 0 ;
F_71 (fmt) {
if ( F_72 ( V_162 ) )
continue;
V_111 = V_162 -> V_163 ( V_162 , V_159 , V_160 ) ;
if ( V_111 )
break;
}
return V_111 ;
}
void F_21 ( struct V_14 * V_79 )
{
F_74 ( V_79 -> V_23 ) ;
F_27 ( V_79 -> V_17 . V_26 ) ;
if ( V_79 -> V_29 ) {
F_27 ( V_79 -> V_29 -> V_30 . V_26 ) ;
F_27 ( V_79 -> V_29 -> V_33 . V_26 ) ;
F_34 ( & V_79 -> V_29 ) ;
}
if ( V_79 -> V_36 ) {
F_27 ( V_79 -> V_36 -> V_40 . V_26 ) ;
F_27 ( V_79 -> V_36 -> V_37 . V_26 ) ;
F_34 ( & V_79 -> V_36 ) ;
}
F_34 ( & V_79 -> V_84 ) ;
F_75 ( V_79 -> V_51 ) ;
if ( V_79 -> V_53 && V_79 -> V_53 [ 0 ] )
free ( V_79 -> V_53 ) ;
F_76 ( V_79 -> V_101 ) ;
free ( V_79 ) ;
}
static bool F_77 ( struct V_1 * V_1 V_125 ,
struct V_164 * V_165 ,
struct V_14 * V_79 )
{
struct V_58 * * V_110 = & V_165 -> V_58 ;
struct V_58 * V_27 = NULL ;
struct V_14 * T_6 ;
T_5 V_111 ;
while ( * V_110 != NULL ) {
V_27 = * V_110 ;
T_6 = F_12 ( V_27 , struct V_14 , V_89 ) ;
V_111 = F_73 ( T_6 , V_79 ) ;
if ( ! V_111 ) {
F_16 ( & T_6 -> V_81 , & V_79 -> V_81 ) ;
if ( V_10 . V_83 )
F_16 ( T_6 -> V_84 , V_79 -> V_84 ) ;
if ( V_10 . V_99 ) {
F_78 ( & V_144 ) ;
F_79 ( & V_144 ,
T_6 -> V_101 ,
V_79 -> V_101 ) ;
}
F_21 ( V_79 ) ;
return false ;
}
if ( V_111 < 0 )
V_110 = & ( * V_110 ) -> V_114 ;
else
V_110 = & ( * V_110 ) -> V_115 ;
}
V_1 -> V_91 ++ ;
F_36 ( & V_79 -> V_89 , V_27 , V_110 ) ;
F_37 ( & V_79 -> V_89 , V_165 ) ;
return true ;
}
static struct V_164 * F_80 ( struct V_1 * V_1 )
{
struct V_164 * V_165 ;
F_81 ( & V_1 -> V_166 ) ;
V_165 = V_1 -> V_112 ;
if ( ++ V_1 -> V_112 > & V_1 -> V_167 [ 1 ] )
V_1 -> V_112 = & V_1 -> V_167 [ 0 ] ;
F_82 ( & V_1 -> V_166 ) ;
return V_165 ;
}
static void F_83 ( struct V_1 * V_1 , struct V_14 * V_79 )
{
F_84 ( V_1 , V_79 ) ;
F_85 ( V_1 , V_79 ) ;
F_86 ( V_1 , V_79 ) ;
F_87 ( V_1 , V_79 ) ;
}
void F_88 ( struct V_1 * V_1 , struct V_168 * V_169 )
{
struct V_164 * V_165 ;
struct V_58 * V_59 ;
struct V_14 * V_61 ;
if ( ! V_88 )
return;
V_1 -> V_91 = 0 ;
V_165 = F_80 ( V_1 ) ;
V_59 = F_11 ( V_165 ) ;
while ( V_59 ) {
if ( F_89 () )
break;
V_61 = F_12 ( V_59 , struct V_14 , V_89 ) ;
V_59 = F_13 ( & V_61 -> V_89 ) ;
F_20 ( & V_61 -> V_89 , V_165 ) ;
if ( F_77 ( V_1 , & V_1 -> V_90 , V_61 ) ) {
F_83 ( V_1 , V_61 ) ;
}
if ( V_169 )
F_90 ( V_169 , 1 ) ;
}
}
static int F_91 ( struct V_14 * V_170 , struct V_14 * V_171 )
{
struct V_161 * V_162 ;
T_5 V_111 = 0 ;
F_71 (fmt) {
if ( F_72 ( V_162 ) )
continue;
V_111 = V_162 -> V_172 ( V_162 , V_170 , V_171 ) ;
if ( V_111 )
break;
}
return V_111 ;
}
static void F_92 ( struct V_1 * V_1 )
{
V_1 -> V_92 = 0 ;
V_1 -> V_85 . V_87 = 0 ;
}
void F_93 ( struct V_1 * V_1 )
{
V_1 -> V_91 = 0 ;
V_1 -> V_85 . V_86 = 0 ;
F_92 ( V_1 ) ;
}
static void F_94 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
V_1 -> V_92 ++ ;
V_1 -> V_85 . V_87 += V_15 -> V_81 . V_66 ;
}
void F_95 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
if ( ! V_15 -> V_63 )
F_94 ( V_1 , V_15 ) ;
V_1 -> V_91 ++ ;
V_1 -> V_85 . V_86 += V_15 -> V_81 . V_66 ;
}
static void F_96 ( struct V_164 * V_60 ,
struct V_14 * V_79 ,
T_2 V_173 ,
bool V_99 )
{
struct V_58 * * V_110 = & V_60 -> V_58 ;
struct V_58 * V_27 = NULL ;
struct V_14 * T_6 ;
if ( V_99 )
V_174 . V_172 ( & V_79 -> V_175 , V_79 -> V_101 ,
V_173 , & V_174 ) ;
while ( * V_110 != NULL ) {
V_27 = * V_110 ;
T_6 = F_12 ( V_27 , struct V_14 , V_58 ) ;
if ( F_91 ( V_79 , T_6 ) > 0 )
V_110 = & ( * V_110 ) -> V_114 ;
else
V_110 = & ( * V_110 ) -> V_115 ;
}
F_36 ( & V_79 -> V_58 , V_27 , V_110 ) ;
F_37 ( & V_79 -> V_58 , V_60 ) ;
}
void F_97 ( struct V_1 * V_1 , struct V_168 * V_169 )
{
struct V_164 * V_165 ;
struct V_58 * V_59 ;
struct V_14 * V_61 ;
T_2 V_173 ;
struct V_133 * V_131 = F_98 ( V_1 ) ;
bool V_99 ;
if ( V_131 && V_10 . V_99 && ! V_10 . V_176 )
V_99 = V_131 -> V_177 . V_178 & V_179 ;
else
V_99 = V_10 . V_99 ;
V_173 = V_1 -> V_85 . V_86 * ( V_174 . V_180 / 100 ) ;
if ( V_88 )
V_165 = & V_1 -> V_90 ;
else
V_165 = V_1 -> V_112 ;
V_59 = F_11 ( V_165 ) ;
V_1 -> V_60 = V_181 ;
F_93 ( V_1 ) ;
F_4 ( V_1 ) ;
while ( V_59 ) {
V_61 = F_12 ( V_59 , struct V_14 , V_89 ) ;
V_59 = F_13 ( & V_61 -> V_89 ) ;
F_96 ( & V_1 -> V_60 , V_61 , V_173 , V_99 ) ;
F_95 ( V_1 , V_61 ) ;
if ( ! V_61 -> V_63 )
F_6 ( V_1 , V_61 ) ;
if ( V_169 )
F_90 ( V_169 , 1 ) ;
}
}
static void F_99 ( struct V_1 * V_1 , struct V_14 * V_15 ,
enum V_182 V_183 )
{
V_15 -> V_63 &= ~ ( 1 << V_183 ) ;
if ( V_15 -> V_63 )
return;
V_15 -> V_184 = false ;
V_15 -> V_185 = 0 ;
V_15 -> V_186 = 0 ;
V_1 -> V_85 . V_187 += V_15 -> V_81 . V_76 ;
F_94 ( V_1 , V_15 ) ;
F_6 ( V_1 , V_15 ) ;
}
static bool F_84 ( struct V_1 * V_1 ,
struct V_14 * V_79 )
{
if ( V_1 -> V_188 != NULL &&
( V_79 -> V_17 . V_26 == NULL || V_79 -> V_17 . V_26 -> V_7 != V_1 -> V_188 ) ) {
V_79 -> V_63 |= ( 1 << V_189 ) ;
return true ;
}
return false ;
}
void F_100 ( struct V_1 * V_1 )
{
struct V_58 * V_190 ;
V_1 -> V_85 . V_187 = 0 ;
F_92 ( V_1 ) ;
F_4 ( V_1 ) ;
for ( V_190 = F_11 ( & V_1 -> V_60 ) ; V_190 ; V_190 = F_13 ( V_190 ) ) {
struct V_14 * V_15 = F_12 ( V_190 , struct V_14 , V_58 ) ;
if ( V_10 . V_105 && ! V_15 -> V_27 )
continue;
if ( F_84 ( V_1 , V_15 ) )
continue;
F_99 ( V_1 , V_15 , V_189 ) ;
}
}
static bool F_85 ( struct V_1 * V_1 ,
struct V_14 * V_79 )
{
if ( V_1 -> V_191 != NULL &&
V_79 -> V_23 != V_1 -> V_191 ) {
V_79 -> V_63 |= ( 1 << V_192 ) ;
return true ;
}
return false ;
}
void F_101 ( struct V_1 * V_1 )
{
struct V_58 * V_190 ;
V_1 -> V_85 . V_187 = 0 ;
F_92 ( V_1 ) ;
F_4 ( V_1 ) ;
for ( V_190 = F_11 ( & V_1 -> V_60 ) ; V_190 ; V_190 = F_13 ( V_190 ) ) {
struct V_14 * V_15 = F_12 ( V_190 , struct V_14 , V_58 ) ;
if ( F_85 ( V_1 , V_15 ) )
continue;
F_99 ( V_1 , V_15 , V_192 ) ;
}
}
static bool F_86 ( struct V_1 * V_1 ,
struct V_14 * V_79 )
{
if ( V_1 -> V_193 != NULL &&
( ! V_79 -> V_17 . V_18 || strstr ( V_79 -> V_17 . V_18 -> V_194 ,
V_1 -> V_193 ) == NULL ) ) {
V_79 -> V_63 |= ( 1 << V_195 ) ;
return true ;
}
return false ;
}
void F_102 ( struct V_1 * V_1 )
{
struct V_58 * V_190 ;
V_1 -> V_85 . V_187 = 0 ;
F_92 ( V_1 ) ;
F_4 ( V_1 ) ;
for ( V_190 = F_11 ( & V_1 -> V_60 ) ; V_190 ; V_190 = F_13 ( V_190 ) ) {
struct V_14 * V_15 = F_12 ( V_190 , struct V_14 , V_58 ) ;
if ( F_86 ( V_1 , V_15 ) )
continue;
F_99 ( V_1 , V_15 , V_195 ) ;
}
}
static bool F_87 ( struct V_1 * V_1 ,
struct V_14 * V_79 )
{
if ( ( V_1 -> V_196 > - 1 ) &&
( V_79 -> V_120 != V_1 -> V_196 ) ) {
V_79 -> V_63 |= ( 1 << V_197 ) ;
return true ;
}
return false ;
}
void F_103 ( struct V_1 * V_1 )
{
struct V_58 * V_190 ;
V_1 -> V_85 . V_187 = 0 ;
F_92 ( V_1 ) ;
F_4 ( V_1 ) ;
for ( V_190 = F_11 ( & V_1 -> V_60 ) ; V_190 ; V_190 = F_13 ( V_190 ) ) {
struct V_14 * V_15 = F_12 ( V_190 , struct V_14 , V_58 ) ;
if ( F_87 ( V_1 , V_15 ) )
continue;
F_99 ( V_1 , V_15 , V_197 ) ;
}
}
void F_104 ( struct V_198 * V_85 , T_7 type )
{
++ V_85 -> V_76 [ 0 ] ;
++ V_85 -> V_76 [ type ] ;
}
void F_105 ( struct V_1 * V_1 , T_7 type )
{
F_104 ( & V_1 -> V_85 , type ) ;
}
void F_47 ( struct V_1 * V_1 , bool V_63 )
{
F_104 ( & V_1 -> V_85 , V_199 ) ;
if ( ! V_63 )
V_1 -> V_85 . V_187 ++ ;
}
static struct V_14 * F_106 ( struct V_1 * V_1 ,
struct V_14 * V_200 )
{
struct V_164 * V_165 ;
struct V_58 * * V_110 ;
struct V_58 * V_27 = NULL ;
struct V_14 * V_79 ;
T_5 V_111 ;
if ( V_88 )
V_165 = & V_1 -> V_90 ;
else
V_165 = V_1 -> V_112 ;
V_110 = & V_165 -> V_58 ;
while ( * V_110 != NULL ) {
V_27 = * V_110 ;
V_79 = F_12 ( V_27 , struct V_14 , V_89 ) ;
V_111 = F_73 ( V_79 , V_200 ) ;
if ( ! V_111 )
goto V_113;
if ( V_111 < 0 )
V_110 = & ( * V_110 ) -> V_114 ;
else
V_110 = & ( * V_110 ) -> V_115 ;
}
V_79 = F_24 ( V_200 , true ) ;
if ( V_79 ) {
memset ( & V_79 -> V_81 , 0 , sizeof( V_79 -> V_81 ) ) ;
V_79 -> V_1 = V_1 ;
F_36 ( & V_79 -> V_89 , V_27 , V_110 ) ;
F_37 ( & V_79 -> V_89 , V_165 ) ;
F_95 ( V_1 , V_79 ) ;
V_79 -> V_201 = true ;
}
V_113:
return V_79 ;
}
static struct V_14 * F_107 ( struct V_1 * V_1 ,
struct V_14 * V_79 )
{
struct V_58 * V_61 ;
if ( V_88 )
V_61 = V_1 -> V_90 . V_58 ;
else
V_61 = V_1 -> V_112 -> V_58 ;
while ( V_61 ) {
struct V_14 * T_6 = F_12 ( V_61 , struct V_14 , V_89 ) ;
T_5 V_111 = F_73 ( T_6 , V_79 ) ;
if ( V_111 < 0 )
V_61 = V_61 -> V_114 ;
else if ( V_111 > 0 )
V_61 = V_61 -> V_115 ;
else
return T_6 ;
}
return NULL ;
}
void F_108 ( struct V_1 * V_202 , struct V_1 * V_203 )
{
struct V_164 * V_165 ;
struct V_58 * V_190 ;
struct V_14 * V_204 , * V_200 ;
if ( V_88 )
V_165 = & V_202 -> V_90 ;
else
V_165 = V_202 -> V_112 ;
for ( V_190 = F_11 ( V_165 ) ; V_190 ; V_190 = F_13 ( V_190 ) ) {
V_204 = F_12 ( V_190 , struct V_14 , V_89 ) ;
V_200 = F_107 ( V_203 , V_204 ) ;
if ( V_200 )
F_109 ( V_200 , V_204 ) ;
}
}
int F_110 ( struct V_1 * V_202 , struct V_1 * V_203 )
{
struct V_164 * V_165 ;
struct V_58 * V_190 ;
struct V_14 * V_204 , * V_200 ;
if ( V_88 )
V_165 = & V_203 -> V_90 ;
else
V_165 = V_203 -> V_112 ;
for ( V_190 = F_11 ( V_165 ) ; V_190 ; V_190 = F_13 ( V_190 ) ) {
V_204 = F_12 ( V_190 , struct V_14 , V_89 ) ;
if ( ! F_111 ( V_204 ) ) {
V_200 = F_106 ( V_202 , V_204 ) ;
if ( V_200 == NULL )
return - 1 ;
F_109 ( V_204 , V_200 ) ;
}
}
return 0 ;
}
void F_112 ( struct V_137 * V_205 , struct V_108 * V_109 ,
struct V_126 * V_127 , bool V_206 )
{
struct V_29 * V_117 ;
if ( V_205 && V_205 -> V_138 && V_205 -> V_60 [ 0 ] . V_141 . V_142 ) {
int V_139 ;
V_117 = F_50 ( V_127 , V_109 ) ;
if ( V_117 ) {
struct V_207 * V_208 = NULL ;
for ( V_139 = V_205 -> V_138 - 1 ; V_139 >= 0 ; V_139 -- ) {
F_113 ( & V_117 [ V_139 ] . V_30 ,
V_206 ? NULL : V_208 ,
V_117 [ V_139 ] . V_141 . V_142 ) ;
V_208 = & V_117 [ V_139 ] . V_33 ;
}
free ( V_117 ) ;
}
}
}
T_3 F_114 ( struct V_209 * V_210 , T_8 * V_211 )
{
struct V_133 * V_204 ;
T_3 V_212 = 0 ;
F_115 (evlist, pos) {
V_212 += fprintf ( V_211 , L_1 , F_116 ( V_204 ) ) ;
V_212 += F_117 ( & F_45 ( V_204 ) -> V_85 , V_211 ) ;
}
return V_212 ;
}
T_2 F_118 ( struct V_1 * V_1 )
{
return V_10 . V_213 ? V_1 -> V_85 . V_87 :
V_1 -> V_85 . V_86 ;
}
int F_119 ( const struct V_214 * T_9 V_125 ,
const char * V_150 , int T_10 V_125 )
{
if ( ! strcmp ( V_150 , L_2 ) )
V_10 . V_213 = true ;
else if ( ! strcmp ( V_150 , L_3 ) )
V_10 . V_213 = false ;
else
return - 1 ;
return 0 ;
}
int F_120 ( const char * V_215 , const char * V_216 )
{
if ( ! strcmp ( V_215 , L_4 ) )
return F_119 ( NULL , V_216 , 0 ) ;
return 0 ;
}
static int F_121 ( struct V_133 * V_131 )
{
struct V_1 * V_1 = F_45 ( V_131 ) ;
memset ( V_1 , 0 , sizeof( * V_1 ) ) ;
V_1 -> V_167 [ 0 ] = V_1 -> V_167 [ 1 ] = V_181 ;
V_1 -> V_112 = & V_1 -> V_167 [ 0 ] ;
V_1 -> V_90 = V_181 ;
V_1 -> V_60 = V_181 ;
F_122 ( & V_1 -> V_166 , NULL ) ;
V_1 -> V_196 = - 1 ;
return 0 ;
}
int F_123 ( void )
{
int V_134 = F_124 ( sizeof( struct V_217 ) ,
F_121 , NULL ) ;
if ( V_134 )
fputs ( L_5 , V_218 ) ;
return V_134 ;
}
