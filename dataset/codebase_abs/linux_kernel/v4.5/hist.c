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
F_3 ( V_1 , V_39 ,
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
F_19 ( V_79 -> V_85 ) ;
V_82 = V_80 - V_79 -> V_81 . V_66 ;
V_1 -> V_86 . V_87 -= V_82 ;
if ( ! V_79 -> V_63 )
V_1 -> V_86 . V_88 -= V_82 ;
return V_79 -> V_81 . V_66 == 0 ;
}
static void F_20 ( struct V_1 * V_1 , struct V_14 * V_79 )
{
F_21 ( & V_79 -> V_58 , & V_1 -> V_60 ) ;
if ( V_89 )
F_21 ( & V_79 -> V_90 , & V_1 -> V_91 ) ;
else
F_21 ( & V_79 -> V_90 , V_1 -> V_92 ) ;
-- V_1 -> V_93 ;
if ( ! V_79 -> V_63 )
-- V_1 -> V_94 ;
F_22 ( V_79 ) ;
}
void F_23 ( struct V_1 * V_1 , bool V_95 , bool V_96 )
{
struct V_58 * V_59 = F_11 ( & V_1 -> V_60 ) ;
struct V_14 * V_61 ;
while ( V_59 ) {
V_61 = F_12 ( V_59 , struct V_14 , V_58 ) ;
V_59 = F_13 ( & V_61 -> V_58 ) ;
if ( ( ( V_95 && V_61 -> V_97 == '.' ) ||
( V_96 && V_61 -> V_97 != '.' ) ||
F_18 ( V_1 , V_61 ) ) ) {
F_20 ( V_1 , V_61 ) ;
}
}
}
void F_24 ( struct V_1 * V_1 )
{
struct V_58 * V_59 = F_11 ( & V_1 -> V_60 ) ;
struct V_14 * V_61 ;
while ( V_59 ) {
V_61 = F_12 ( V_59 , struct V_14 , V_58 ) ;
V_59 = F_13 ( & V_61 -> V_58 ) ;
F_20 ( V_1 , V_61 ) ;
}
}
static struct V_14 * F_25 ( struct V_14 * V_98 ,
bool V_99 )
{
T_3 V_100 = 0 ;
struct V_14 * V_79 ;
if ( V_10 . V_101 )
V_100 = sizeof( struct V_102 ) ;
V_79 = F_26 ( sizeof( * V_79 ) + V_100 ) ;
if ( V_79 != NULL ) {
* V_79 = * V_98 ;
if ( V_10 . V_83 ) {
V_79 -> V_84 = malloc ( sizeof( V_79 -> V_81 ) ) ;
if ( V_79 -> V_84 == NULL ) {
free ( V_79 ) ;
return NULL ;
}
memcpy ( V_79 -> V_84 , & V_79 -> V_81 , sizeof( V_79 -> V_81 ) ) ;
if ( ! V_99 )
memset ( & V_79 -> V_81 , 0 , sizeof( V_79 -> V_81 ) ) ;
}
F_27 ( V_79 -> V_17 . V_26 ) ;
if ( V_79 -> V_29 ) {
V_79 -> V_29 = malloc ( sizeof( * V_79 -> V_29 ) ) ;
if ( V_79 -> V_29 == NULL ) {
F_28 ( V_79 -> V_17 . V_26 ) ;
free ( V_79 -> V_84 ) ;
free ( V_79 ) ;
return NULL ;
}
memcpy ( V_79 -> V_29 , V_98 -> V_29 ,
sizeof( * V_79 -> V_29 ) ) ;
F_27 ( V_79 -> V_29 -> V_30 . V_26 ) ;
F_27 ( V_79 -> V_29 -> V_33 . V_26 ) ;
}
if ( V_79 -> V_36 ) {
F_27 ( V_79 -> V_36 -> V_40 . V_26 ) ;
F_27 ( V_79 -> V_36 -> V_37 . V_26 ) ;
}
if ( V_10 . V_101 )
F_29 ( V_79 -> V_85 ) ;
if ( V_79 -> V_103 ) {
V_79 -> V_103 = F_30 ( V_79 -> V_103 , V_79 -> V_104 ) ;
if ( V_79 -> V_103 == NULL ) {
F_31 ( V_79 -> V_17 . V_26 ) ;
if ( V_79 -> V_29 ) {
F_31 ( V_79 -> V_29 -> V_30 . V_26 ) ;
F_31 ( V_79 -> V_29 -> V_33 . V_26 ) ;
free ( V_79 -> V_29 ) ;
}
if ( V_79 -> V_36 ) {
F_31 ( V_79 -> V_36 -> V_40 . V_26 ) ;
F_31 ( V_79 -> V_36 -> V_37 . V_26 ) ;
}
free ( V_79 -> V_84 ) ;
free ( V_79 ) ;
return NULL ;
}
}
F_32 ( & V_79 -> V_105 . V_106 ) ;
F_33 ( V_79 -> V_23 ) ;
}
return V_79 ;
}
static T_4 F_34 ( const struct V_107 * V_27 )
{
if ( V_10 . V_108 && V_27 == NULL )
return 1 << V_109 ;
return 0 ;
}
static struct V_14 * F_35 ( struct V_1 * V_1 ,
struct V_14 * V_110 ,
struct V_111 * V_112 ,
bool V_99 )
{
struct V_58 * * V_113 ;
struct V_58 * V_27 = NULL ;
struct V_14 * V_79 ;
T_5 V_114 ;
T_2 V_66 = V_110 -> V_81 . V_66 ;
T_2 V_75 = V_110 -> V_81 . V_75 ;
V_113 = & V_1 -> V_92 -> V_58 ;
while ( * V_113 != NULL ) {
V_27 = * V_113 ;
V_79 = F_12 ( V_27 , struct V_14 , V_90 ) ;
V_114 = F_36 ( V_79 , V_110 ) ;
if ( ! V_114 ) {
if ( V_99 )
F_15 ( & V_79 -> V_81 , V_66 , V_75 ) ;
if ( V_10 . V_83 )
F_15 ( V_79 -> V_84 , V_66 , V_75 ) ;
F_37 ( & V_110 -> V_36 ) ;
if ( V_79 -> V_17 . V_26 != V_110 -> V_17 . V_26 ) {
F_31 ( V_79 -> V_17 . V_26 ) ;
V_79 -> V_17 . V_26 = F_27 ( V_110 -> V_17 . V_26 ) ;
}
goto V_115;
}
if ( V_114 < 0 )
V_113 = & ( * V_113 ) -> V_116 ;
else
V_113 = & ( * V_113 ) -> V_117 ;
}
V_79 = F_25 ( V_110 , V_99 ) ;
if ( ! V_79 )
return NULL ;
V_1 -> V_93 ++ ;
F_38 ( & V_79 -> V_90 , V_27 , V_113 ) ;
F_39 ( & V_79 -> V_90 , V_1 -> V_92 ) ;
V_115:
if ( V_99 )
F_14 ( & V_79 -> V_81 , V_112 -> V_65 , V_66 ) ;
if ( V_10 . V_83 )
F_14 ( V_79 -> V_84 , V_112 -> V_65 , V_66 ) ;
return V_79 ;
}
struct V_14 * F_40 ( struct V_1 * V_1 ,
struct V_111 * V_112 ,
struct V_107 * V_118 ,
struct V_29 * V_119 ,
struct V_36 * V_120 ,
struct V_121 * V_122 ,
bool V_99 )
{
struct V_14 V_110 = {
. V_23 = V_112 -> V_23 ,
. V_123 = F_41 ( V_112 -> V_23 ) ,
. V_17 = {
. V_26 = V_112 -> V_26 ,
. V_18 = V_112 -> V_18 ,
} ,
. V_124 = V_112 -> V_124 ,
. V_125 = V_112 -> V_125 ,
. V_65 = V_112 -> V_65 ,
. V_126 = V_112 -> V_127 ,
. V_97 = V_112 -> V_97 ,
. V_81 = {
. V_76 = 1 ,
. V_66 = V_122 -> V_66 ,
. V_75 = V_122 -> V_75 ,
} ,
. V_27 = V_118 ,
. V_63 = F_34 ( V_118 ) | V_112 -> V_63 ,
. V_1 = V_1 ,
. V_29 = V_119 ,
. V_36 = V_120 ,
. V_55 = V_122 -> V_55 ,
. V_103 = V_122 -> V_103 ,
. V_104 = V_122 -> V_104 ,
} ;
return F_35 ( V_1 , & V_110 , V_112 , V_99 ) ;
}
static int
F_42 ( struct V_128 * T_6 V_129 ,
struct V_111 * V_112 V_129 )
{
return 0 ;
}
static int
F_43 ( struct V_128 * T_6 V_129 ,
struct V_111 * V_112 V_129 )
{
return 0 ;
}
static int
F_44 ( struct V_128 * T_6 , struct V_111 * V_112 )
{
struct V_121 * V_122 = T_6 -> V_122 ;
struct V_36 * V_120 ;
V_120 = F_45 ( V_122 , V_112 ) ;
if ( V_120 == NULL )
return - V_130 ;
T_6 -> V_131 = V_120 ;
return 0 ;
}
static int
F_46 ( struct V_128 * T_6 , struct V_111 * V_112 )
{
T_2 V_132 ;
struct V_36 * V_120 = T_6 -> V_131 ;
struct V_1 * V_1 = F_47 ( T_6 -> V_133 ) ;
struct V_121 * V_122 = T_6 -> V_122 ;
struct V_14 * V_79 ;
if ( V_120 == NULL )
return - V_134 ;
V_132 = V_122 -> V_75 ;
if ( ! V_132 )
V_132 = 1 ;
V_122 -> V_66 = V_132 ;
V_79 = F_40 ( V_1 , V_112 , T_6 -> V_27 , NULL , V_120 ,
V_122 , true ) ;
if ( ! V_79 )
return - V_130 ;
T_6 -> V_79 = V_79 ;
return 0 ;
}
static int
F_48 ( struct V_128 * T_6 ,
struct V_111 * V_112 V_129 )
{
struct V_135 * V_133 = T_6 -> V_133 ;
struct V_1 * V_1 = F_47 ( V_133 ) ;
struct V_14 * V_79 = T_6 -> V_79 ;
int V_136 = - V_134 ;
if ( V_79 == NULL )
goto V_115;
F_49 ( V_1 , V_79 -> V_63 ) ;
V_136 = F_50 ( V_79 , T_6 -> V_122 ) ;
V_115:
T_6 -> V_131 = NULL ;
T_6 -> V_79 = NULL ;
return V_136 ;
}
static int
F_51 ( struct V_128 * T_6 , struct V_111 * V_112 )
{
struct V_29 * V_119 ;
struct V_121 * V_122 = T_6 -> V_122 ;
V_119 = F_52 ( V_122 , V_112 ) ;
if ( ! V_119 )
return - V_130 ;
T_6 -> V_137 = 0 ;
T_6 -> V_138 = V_122 -> V_139 -> V_140 ;
T_6 -> V_131 = V_119 ;
return 0 ;
}
static int
F_53 ( struct V_128 * T_6 V_129 ,
struct V_111 * V_112 V_129 )
{
T_6 -> V_79 = NULL ;
return 0 ;
}
static int
F_54 ( struct V_128 * T_6 , struct V_111 * V_112 )
{
struct V_29 * V_119 = T_6 -> V_131 ;
int V_141 = T_6 -> V_137 ;
if ( V_119 == NULL )
return 0 ;
if ( T_6 -> V_137 >= T_6 -> V_138 )
return 0 ;
V_112 -> V_26 = V_119 [ V_141 ] . V_33 . V_26 ;
V_112 -> V_18 = V_119 [ V_141 ] . V_33 . V_18 ;
V_112 -> V_127 = V_119 [ V_141 ] . V_33 . V_127 ;
return 1 ;
}
static int
F_55 ( struct V_128 * T_6 , struct V_111 * V_112 )
{
struct V_29 * V_119 ;
struct V_135 * V_133 = T_6 -> V_133 ;
struct V_1 * V_1 = F_47 ( V_133 ) ;
struct V_121 * V_122 = T_6 -> V_122 ;
struct V_14 * V_79 = NULL ;
int V_141 = T_6 -> V_137 ;
int V_136 = 0 ;
V_119 = T_6 -> V_131 ;
if ( T_6 -> V_142 && ! ( V_119 [ V_141 ] . V_30 . V_18 && V_119 [ V_141 ] . V_33 . V_18 ) )
goto V_115;
V_122 -> V_66 = 1 ;
V_122 -> V_75 = V_119 -> V_143 . V_144 ? V_119 -> V_143 . V_144 : 1 ;
V_79 = F_40 ( V_1 , V_112 , T_6 -> V_27 , & V_119 [ V_141 ] , NULL ,
V_122 , true ) ;
if ( V_79 == NULL )
return - V_130 ;
F_49 ( V_1 , V_79 -> V_63 ) ;
V_115:
T_6 -> V_79 = V_79 ;
T_6 -> V_137 ++ ;
return V_136 ;
}
static int
F_56 ( struct V_128 * T_6 ,
struct V_111 * V_112 V_129 )
{
F_37 ( & T_6 -> V_131 ) ;
T_6 -> V_79 = NULL ;
return T_6 -> V_137 >= T_6 -> V_138 ? 0 : - 1 ;
}
static int
F_57 ( struct V_128 * T_6 V_129 ,
struct V_111 * V_112 V_129 )
{
return 0 ;
}
static int
F_58 ( struct V_128 * T_6 , struct V_111 * V_112 )
{
struct V_135 * V_133 = T_6 -> V_133 ;
struct V_121 * V_122 = T_6 -> V_122 ;
struct V_14 * V_79 ;
V_79 = F_40 ( F_47 ( V_133 ) , V_112 , T_6 -> V_27 , NULL , NULL ,
V_122 , true ) ;
if ( V_79 == NULL )
return - V_130 ;
T_6 -> V_79 = V_79 ;
return 0 ;
}
static int
F_59 ( struct V_128 * T_6 ,
struct V_111 * V_112 V_129 )
{
struct V_14 * V_79 = T_6 -> V_79 ;
struct V_135 * V_133 = T_6 -> V_133 ;
struct V_121 * V_122 = T_6 -> V_122 ;
if ( V_79 == NULL )
return 0 ;
T_6 -> V_79 = NULL ;
F_49 ( F_47 ( V_133 ) , V_79 -> V_63 ) ;
return F_50 ( V_79 , V_122 ) ;
}
static int
F_60 ( struct V_128 * T_6 ,
struct V_111 * V_112 V_129 )
{
struct V_14 * * V_145 ;
F_61 ( & V_146 ) ;
V_145 = malloc ( sizeof( * V_145 ) * ( T_6 -> V_147 + 1 ) ) ;
if ( V_145 == NULL )
return - V_130 ;
T_6 -> V_131 = V_145 ;
T_6 -> V_137 = 0 ;
return 0 ;
}
static int
F_62 ( struct V_128 * T_6 ,
struct V_111 * V_112 )
{
struct V_135 * V_133 = T_6 -> V_133 ;
struct V_1 * V_1 = F_47 ( V_133 ) ;
struct V_121 * V_122 = T_6 -> V_122 ;
struct V_14 * * V_145 = T_6 -> V_131 ;
struct V_14 * V_79 ;
int V_136 = 0 ;
V_79 = F_40 ( V_1 , V_112 , T_6 -> V_27 , NULL , NULL ,
V_122 , true ) ;
if ( V_79 == NULL )
return - V_130 ;
T_6 -> V_79 = V_79 ;
V_145 [ T_6 -> V_137 ++ ] = V_79 ;
F_50 ( V_79 , V_122 ) ;
F_61 ( & V_146 ) ;
F_49 ( V_1 , V_79 -> V_63 ) ;
return V_136 ;
}
static int
F_63 ( struct V_128 * T_6 ,
struct V_111 * V_112 )
{
struct V_148 * V_106 ;
V_106 = F_64 ( & V_146 ) ;
if ( V_106 == NULL )
return 0 ;
return F_65 ( V_112 , V_106 , T_6 -> V_142 ) ;
}
static int
F_66 ( struct V_128 * T_6 ,
struct V_111 * V_112 )
{
struct V_135 * V_133 = T_6 -> V_133 ;
struct V_121 * V_122 = T_6 -> V_122 ;
struct V_14 * * V_145 = T_6 -> V_131 ;
struct V_14 * V_79 ;
struct V_14 V_149 = {
. V_1 = F_47 ( V_133 ) ,
. V_125 = V_112 -> V_125 ,
. V_23 = V_112 -> V_23 ,
. V_123 = F_41 ( V_112 -> V_23 ) ,
. V_126 = V_112 -> V_127 ,
. V_17 = {
. V_26 = V_112 -> V_26 ,
. V_18 = V_112 -> V_18 ,
} ,
. V_27 = T_6 -> V_27 ,
. V_103 = V_122 -> V_103 ,
. V_104 = V_122 -> V_104 ,
} ;
int V_141 ;
struct V_146 V_150 ;
F_67 ( & V_150 , & V_146 ) ;
F_68 ( & V_146 ) ;
for ( V_141 = 0 ; V_141 < T_6 -> V_137 ; V_141 ++ ) {
if ( F_36 ( V_145 [ V_141 ] , & V_149 ) == 0 ) {
T_6 -> V_79 = NULL ;
return 0 ;
}
}
V_79 = F_40 ( F_47 ( V_133 ) , V_112 , T_6 -> V_27 , NULL , NULL ,
V_122 , false ) ;
if ( V_79 == NULL )
return - V_130 ;
T_6 -> V_79 = V_79 ;
V_145 [ T_6 -> V_137 ++ ] = V_79 ;
if ( V_10 . V_101 )
F_69 ( V_79 -> V_85 , & V_150 , V_122 -> V_66 ) ;
return 0 ;
}
static int
F_70 ( struct V_128 * T_6 ,
struct V_111 * V_112 V_129 )
{
F_37 ( & T_6 -> V_131 ) ;
T_6 -> V_79 = NULL ;
return 0 ;
}
int F_71 ( struct V_128 * T_6 , struct V_111 * V_112 ,
int V_151 , void * V_152 )
{
int V_136 , V_153 ;
V_136 = F_72 ( T_6 -> V_122 , & T_6 -> V_27 ,
T_6 -> V_133 , V_112 , V_151 ) ;
if ( V_136 )
return V_136 ;
T_6 -> V_147 = V_151 ;
V_136 = T_6 -> V_154 -> V_155 ( T_6 , V_112 ) ;
if ( V_136 )
goto V_115;
V_136 = T_6 -> V_154 -> V_156 ( T_6 , V_112 ) ;
if ( V_136 )
goto V_115;
if ( T_6 -> V_79 && T_6 -> V_157 ) {
V_136 = T_6 -> V_157 ( T_6 , V_112 , true , V_152 ) ;
if ( V_136 )
goto V_115;
}
while ( T_6 -> V_154 -> V_158 ( T_6 , V_112 ) ) {
V_136 = T_6 -> V_154 -> V_159 ( T_6 , V_112 ) ;
if ( V_136 )
break;
if ( T_6 -> V_79 && T_6 -> V_157 ) {
V_136 = T_6 -> V_157 ( T_6 , V_112 , false , V_152 ) ;
if ( V_136 )
goto V_115;
}
}
V_115:
V_153 = T_6 -> V_154 -> V_160 ( T_6 , V_112 ) ;
if ( ! V_136 )
V_136 = V_153 ;
return V_136 ;
}
T_5
F_36 ( struct V_14 * V_161 , struct V_14 * V_162 )
{
struct V_163 * V_164 ;
T_5 V_114 = 0 ;
F_73 (fmt) {
V_114 = V_164 -> V_114 ( V_164 , V_161 , V_162 ) ;
if ( V_114 )
break;
}
return V_114 ;
}
T_5
F_74 ( struct V_14 * V_161 , struct V_14 * V_162 )
{
struct V_163 * V_164 ;
T_5 V_114 = 0 ;
F_73 (fmt) {
V_114 = V_164 -> V_165 ( V_164 , V_161 , V_162 ) ;
if ( V_114 )
break;
}
return V_114 ;
}
void F_22 ( struct V_14 * V_79 )
{
F_75 ( V_79 -> V_23 ) ;
F_28 ( V_79 -> V_17 . V_26 ) ;
if ( V_79 -> V_29 ) {
F_28 ( V_79 -> V_29 -> V_30 . V_26 ) ;
F_28 ( V_79 -> V_29 -> V_33 . V_26 ) ;
F_37 ( & V_79 -> V_29 ) ;
}
if ( V_79 -> V_36 ) {
F_28 ( V_79 -> V_36 -> V_40 . V_26 ) ;
F_28 ( V_79 -> V_36 -> V_37 . V_26 ) ;
F_37 ( & V_79 -> V_36 ) ;
}
F_37 ( & V_79 -> V_84 ) ;
F_76 ( V_79 -> V_51 ) ;
if ( V_79 -> V_53 && V_79 -> V_53 [ 0 ] )
free ( V_79 -> V_53 ) ;
F_77 ( V_79 -> V_85 ) ;
free ( V_79 -> V_166 ) ;
free ( V_79 -> V_103 ) ;
free ( V_79 ) ;
}
bool F_78 ( struct V_1 * V_1 V_129 ,
struct V_167 * V_168 , struct V_14 * V_79 )
{
struct V_58 * * V_113 = & V_168 -> V_58 ;
struct V_58 * V_27 = NULL ;
struct V_14 * T_6 ;
T_5 V_114 ;
while ( * V_113 != NULL ) {
V_27 = * V_113 ;
T_6 = F_12 ( V_27 , struct V_14 , V_90 ) ;
V_114 = F_74 ( T_6 , V_79 ) ;
if ( ! V_114 ) {
F_16 ( & T_6 -> V_81 , & V_79 -> V_81 ) ;
if ( V_10 . V_83 )
F_16 ( T_6 -> V_84 , V_79 -> V_84 ) ;
if ( V_10 . V_101 ) {
F_79 ( & V_146 ) ;
F_80 ( & V_146 ,
T_6 -> V_85 ,
V_79 -> V_85 ) ;
}
F_22 ( V_79 ) ;
return false ;
}
if ( V_114 < 0 )
V_113 = & ( * V_113 ) -> V_116 ;
else
V_113 = & ( * V_113 ) -> V_117 ;
}
V_1 -> V_93 ++ ;
F_38 ( & V_79 -> V_90 , V_27 , V_113 ) ;
F_39 ( & V_79 -> V_90 , V_168 ) ;
return true ;
}
struct V_167 * F_81 ( struct V_1 * V_1 )
{
struct V_167 * V_168 ;
F_82 ( & V_1 -> V_169 ) ;
V_168 = V_1 -> V_92 ;
if ( ++ V_1 -> V_92 > & V_1 -> V_170 [ 1 ] )
V_1 -> V_92 = & V_1 -> V_170 [ 0 ] ;
F_83 ( & V_1 -> V_169 ) ;
return V_168 ;
}
static void F_84 ( struct V_1 * V_1 , struct V_14 * V_79 )
{
F_85 ( V_1 , V_79 ) ;
F_86 ( V_1 , V_79 ) ;
F_87 ( V_1 , V_79 ) ;
F_88 ( V_1 , V_79 ) ;
}
void F_89 ( struct V_1 * V_1 , struct V_171 * V_172 )
{
struct V_167 * V_168 ;
struct V_58 * V_59 ;
struct V_14 * V_61 ;
if ( ! V_89 )
return;
V_1 -> V_93 = 0 ;
V_168 = F_81 ( V_1 ) ;
V_59 = F_11 ( V_168 ) ;
while ( V_59 ) {
if ( F_90 () )
break;
V_61 = F_12 ( V_59 , struct V_14 , V_90 ) ;
V_59 = F_13 ( & V_61 -> V_90 ) ;
F_21 ( & V_61 -> V_90 , V_168 ) ;
if ( F_78 ( V_1 , & V_1 -> V_91 , V_61 ) ) {
F_84 ( V_1 , V_61 ) ;
}
if ( V_172 )
F_91 ( V_172 , 1 ) ;
}
}
static int F_92 ( struct V_14 * V_173 , struct V_14 * V_174 )
{
struct V_163 * V_164 ;
T_5 V_114 = 0 ;
F_73 (fmt) {
if ( F_93 ( V_164 , V_173 -> V_1 ) )
continue;
V_114 = V_164 -> V_175 ( V_164 , V_173 , V_174 ) ;
if ( V_114 )
break;
}
return V_114 ;
}
static void F_94 ( struct V_1 * V_1 )
{
V_1 -> V_94 = 0 ;
V_1 -> V_86 . V_88 = 0 ;
}
void F_95 ( struct V_1 * V_1 )
{
V_1 -> V_93 = 0 ;
V_1 -> V_86 . V_87 = 0 ;
F_94 ( V_1 ) ;
}
static void F_96 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
V_1 -> V_94 ++ ;
V_1 -> V_86 . V_88 += V_15 -> V_81 . V_66 ;
}
void F_97 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
if ( ! V_15 -> V_63 )
F_96 ( V_1 , V_15 ) ;
V_1 -> V_93 ++ ;
V_1 -> V_86 . V_87 += V_15 -> V_81 . V_66 ;
}
static void F_98 ( struct V_167 * V_60 ,
struct V_14 * V_79 ,
T_2 V_176 ,
bool V_101 )
{
struct V_58 * * V_113 = & V_60 -> V_58 ;
struct V_58 * V_27 = NULL ;
struct V_14 * T_6 ;
if ( V_101 )
V_177 . V_175 ( & V_79 -> V_178 , V_79 -> V_85 ,
V_176 , & V_177 ) ;
while ( * V_113 != NULL ) {
V_27 = * V_113 ;
T_6 = F_12 ( V_27 , struct V_14 , V_58 ) ;
if ( F_92 ( V_79 , T_6 ) > 0 )
V_113 = & ( * V_113 ) -> V_116 ;
else
V_113 = & ( * V_113 ) -> V_117 ;
}
F_38 ( & V_79 -> V_58 , V_27 , V_113 ) ;
F_39 ( & V_79 -> V_58 , V_60 ) ;
}
void F_99 ( struct V_1 * V_1 , struct V_171 * V_172 )
{
struct V_167 * V_168 ;
struct V_58 * V_59 ;
struct V_14 * V_61 ;
T_2 V_176 ;
struct V_135 * V_133 = F_100 ( V_1 ) ;
bool V_101 ;
if ( V_133 && V_10 . V_101 && ! V_10 . V_179 )
V_101 = V_133 -> V_180 . V_181 & V_182 ;
else
V_101 = V_10 . V_101 ;
V_176 = V_1 -> V_86 . V_87 * ( V_177 . V_183 / 100 ) ;
if ( V_89 )
V_168 = & V_1 -> V_91 ;
else
V_168 = V_1 -> V_92 ;
V_59 = F_11 ( V_168 ) ;
V_1 -> V_60 = V_184 ;
F_95 ( V_1 ) ;
F_4 ( V_1 ) ;
while ( V_59 ) {
V_61 = F_12 ( V_59 , struct V_14 , V_90 ) ;
V_59 = F_13 ( & V_61 -> V_90 ) ;
F_98 ( & V_1 -> V_60 , V_61 , V_176 , V_101 ) ;
F_97 ( V_1 , V_61 ) ;
if ( ! V_61 -> V_63 )
F_6 ( V_1 , V_61 ) ;
if ( V_172 )
F_91 ( V_172 , 1 ) ;
}
}
static void F_101 ( struct V_1 * V_1 , struct V_14 * V_15 ,
enum V_185 V_186 )
{
V_15 -> V_63 &= ~ ( 1 << V_186 ) ;
if ( V_15 -> V_63 )
return;
V_15 -> V_187 = false ;
V_15 -> V_188 = 0 ;
V_15 -> V_189 = 0 ;
V_1 -> V_86 . V_190 += V_15 -> V_81 . V_76 ;
F_96 ( V_1 , V_15 ) ;
F_6 ( V_1 , V_15 ) ;
}
static bool F_85 ( struct V_1 * V_1 ,
struct V_14 * V_79 )
{
if ( V_1 -> V_191 != NULL &&
( V_79 -> V_17 . V_26 == NULL || V_79 -> V_17 . V_26 -> V_7 != V_1 -> V_191 ) ) {
V_79 -> V_63 |= ( 1 << V_192 ) ;
return true ;
}
return false ;
}
void F_102 ( struct V_1 * V_1 )
{
struct V_58 * V_193 ;
V_1 -> V_86 . V_190 = 0 ;
F_94 ( V_1 ) ;
F_4 ( V_1 ) ;
for ( V_193 = F_11 ( & V_1 -> V_60 ) ; V_193 ; V_193 = F_13 ( V_193 ) ) {
struct V_14 * V_15 = F_12 ( V_193 , struct V_14 , V_58 ) ;
if ( V_10 . V_108 && ! V_15 -> V_27 )
continue;
if ( F_85 ( V_1 , V_15 ) )
continue;
F_101 ( V_1 , V_15 , V_192 ) ;
}
}
static bool F_86 ( struct V_1 * V_1 ,
struct V_14 * V_79 )
{
if ( V_1 -> V_194 != NULL &&
V_79 -> V_23 != V_1 -> V_194 ) {
V_79 -> V_63 |= ( 1 << V_195 ) ;
return true ;
}
return false ;
}
void F_103 ( struct V_1 * V_1 )
{
struct V_58 * V_193 ;
V_1 -> V_86 . V_190 = 0 ;
F_94 ( V_1 ) ;
F_4 ( V_1 ) ;
for ( V_193 = F_11 ( & V_1 -> V_60 ) ; V_193 ; V_193 = F_13 ( V_193 ) ) {
struct V_14 * V_15 = F_12 ( V_193 , struct V_14 , V_58 ) ;
if ( F_86 ( V_1 , V_15 ) )
continue;
F_101 ( V_1 , V_15 , V_195 ) ;
}
}
static bool F_87 ( struct V_1 * V_1 ,
struct V_14 * V_79 )
{
if ( V_1 -> V_196 != NULL &&
( ! V_79 -> V_17 . V_18 || strstr ( V_79 -> V_17 . V_18 -> V_197 ,
V_1 -> V_196 ) == NULL ) ) {
V_79 -> V_63 |= ( 1 << V_198 ) ;
return true ;
}
return false ;
}
void F_104 ( struct V_1 * V_1 )
{
struct V_58 * V_193 ;
V_1 -> V_86 . V_190 = 0 ;
F_94 ( V_1 ) ;
F_4 ( V_1 ) ;
for ( V_193 = F_11 ( & V_1 -> V_60 ) ; V_193 ; V_193 = F_13 ( V_193 ) ) {
struct V_14 * V_15 = F_12 ( V_193 , struct V_14 , V_58 ) ;
if ( F_87 ( V_1 , V_15 ) )
continue;
F_101 ( V_1 , V_15 , V_198 ) ;
}
}
static bool F_88 ( struct V_1 * V_1 ,
struct V_14 * V_79 )
{
if ( ( V_1 -> V_199 > - 1 ) &&
( V_79 -> V_124 != V_1 -> V_199 ) ) {
V_79 -> V_63 |= ( 1 << V_200 ) ;
return true ;
}
return false ;
}
void F_105 ( struct V_1 * V_1 )
{
struct V_58 * V_193 ;
V_1 -> V_86 . V_190 = 0 ;
F_94 ( V_1 ) ;
F_4 ( V_1 ) ;
for ( V_193 = F_11 ( & V_1 -> V_60 ) ; V_193 ; V_193 = F_13 ( V_193 ) ) {
struct V_14 * V_15 = F_12 ( V_193 , struct V_14 , V_58 ) ;
if ( F_88 ( V_1 , V_15 ) )
continue;
F_101 ( V_1 , V_15 , V_200 ) ;
}
}
void F_106 ( struct V_201 * V_86 , T_7 type )
{
++ V_86 -> V_76 [ 0 ] ;
++ V_86 -> V_76 [ type ] ;
}
void F_107 ( struct V_1 * V_1 , T_7 type )
{
F_106 ( & V_1 -> V_86 , type ) ;
}
void F_49 ( struct V_1 * V_1 , bool V_63 )
{
F_106 ( & V_1 -> V_86 , V_202 ) ;
if ( ! V_63 )
V_1 -> V_86 . V_190 ++ ;
}
static struct V_14 * F_108 ( struct V_1 * V_1 ,
struct V_14 * V_203 )
{
struct V_167 * V_168 ;
struct V_58 * * V_113 ;
struct V_58 * V_27 = NULL ;
struct V_14 * V_79 ;
T_5 V_114 ;
if ( V_89 )
V_168 = & V_1 -> V_91 ;
else
V_168 = V_1 -> V_92 ;
V_113 = & V_168 -> V_58 ;
while ( * V_113 != NULL ) {
V_27 = * V_113 ;
V_79 = F_12 ( V_27 , struct V_14 , V_90 ) ;
V_114 = F_74 ( V_79 , V_203 ) ;
if ( ! V_114 )
goto V_115;
if ( V_114 < 0 )
V_113 = & ( * V_113 ) -> V_116 ;
else
V_113 = & ( * V_113 ) -> V_117 ;
}
V_79 = F_25 ( V_203 , true ) ;
if ( V_79 ) {
memset ( & V_79 -> V_81 , 0 , sizeof( V_79 -> V_81 ) ) ;
V_79 -> V_1 = V_1 ;
F_38 ( & V_79 -> V_90 , V_27 , V_113 ) ;
F_39 ( & V_79 -> V_90 , V_168 ) ;
F_97 ( V_1 , V_79 ) ;
V_79 -> V_204 = true ;
}
V_115:
return V_79 ;
}
static struct V_14 * F_109 ( struct V_1 * V_1 ,
struct V_14 * V_79 )
{
struct V_58 * V_61 ;
if ( V_89 )
V_61 = V_1 -> V_91 . V_58 ;
else
V_61 = V_1 -> V_92 -> V_58 ;
while ( V_61 ) {
struct V_14 * T_6 = F_12 ( V_61 , struct V_14 , V_90 ) ;
T_5 V_114 = F_74 ( T_6 , V_79 ) ;
if ( V_114 < 0 )
V_61 = V_61 -> V_116 ;
else if ( V_114 > 0 )
V_61 = V_61 -> V_117 ;
else
return T_6 ;
}
return NULL ;
}
void F_110 ( struct V_1 * V_205 , struct V_1 * V_206 )
{
struct V_167 * V_168 ;
struct V_58 * V_193 ;
struct V_14 * V_207 , * V_203 ;
if ( V_89 )
V_168 = & V_205 -> V_91 ;
else
V_168 = V_205 -> V_92 ;
for ( V_193 = F_11 ( V_168 ) ; V_193 ; V_193 = F_13 ( V_193 ) ) {
V_207 = F_12 ( V_193 , struct V_14 , V_90 ) ;
V_203 = F_109 ( V_206 , V_207 ) ;
if ( V_203 )
F_111 ( V_203 , V_207 ) ;
}
}
int F_112 ( struct V_1 * V_205 , struct V_1 * V_206 )
{
struct V_167 * V_168 ;
struct V_58 * V_193 ;
struct V_14 * V_207 , * V_203 ;
if ( V_89 )
V_168 = & V_206 -> V_91 ;
else
V_168 = V_206 -> V_92 ;
for ( V_193 = F_11 ( V_168 ) ; V_193 ; V_193 = F_13 ( V_193 ) ) {
V_207 = F_12 ( V_193 , struct V_14 , V_90 ) ;
if ( ! F_113 ( V_207 ) ) {
V_203 = F_108 ( V_205 , V_207 ) ;
if ( V_203 == NULL )
return - 1 ;
F_111 ( V_207 , V_203 ) ;
}
}
return 0 ;
}
void F_114 ( struct V_139 * V_208 , struct V_111 * V_112 ,
struct V_121 * V_122 , bool V_209 )
{
struct V_29 * V_119 ;
if ( V_208 && V_208 -> V_140 && V_208 -> V_60 [ 0 ] . V_143 . V_144 ) {
int V_141 ;
V_119 = F_52 ( V_122 , V_112 ) ;
if ( V_119 ) {
struct V_210 * V_211 = NULL ;
for ( V_141 = V_208 -> V_140 - 1 ; V_141 >= 0 ; V_141 -- ) {
F_115 ( & V_119 [ V_141 ] . V_30 ,
V_209 ? NULL : V_211 ,
V_119 [ V_141 ] . V_143 . V_144 ) ;
V_211 = & V_119 [ V_141 ] . V_33 ;
}
free ( V_119 ) ;
}
}
}
T_3 F_116 ( struct V_212 * V_213 , T_8 * V_214 )
{
struct V_135 * V_207 ;
T_3 V_215 = 0 ;
F_117 (evlist, pos) {
V_215 += fprintf ( V_214 , L_1 , F_118 ( V_207 ) ) ;
V_215 += F_119 ( & F_47 ( V_207 ) -> V_86 , V_214 ) ;
}
return V_215 ;
}
T_2 F_120 ( struct V_1 * V_1 )
{
return V_10 . V_216 ? V_1 -> V_86 . V_88 :
V_1 -> V_86 . V_87 ;
}
int F_121 ( const struct V_217 * T_9 V_129 ,
const char * V_152 , int T_10 V_129 )
{
if ( ! strcmp ( V_152 , L_2 ) )
V_10 . V_216 = true ;
else if ( ! strcmp ( V_152 , L_3 ) )
V_10 . V_216 = false ;
else
return - 1 ;
return 0 ;
}
int F_122 ( const char * V_218 , const char * V_219 )
{
if ( ! strcmp ( V_218 , L_4 ) )
return F_121 ( NULL , V_219 , 0 ) ;
return 0 ;
}
int F_123 ( struct V_1 * V_1 )
{
memset ( V_1 , 0 , sizeof( * V_1 ) ) ;
V_1 -> V_170 [ 0 ] = V_1 -> V_170 [ 1 ] = V_184 ;
V_1 -> V_92 = & V_1 -> V_170 [ 0 ] ;
V_1 -> V_91 = V_184 ;
V_1 -> V_60 = V_184 ;
F_124 ( & V_1 -> V_169 , NULL ) ;
V_1 -> V_199 = - 1 ;
return 0 ;
}
static void F_125 ( struct V_167 * V_168 )
{
struct V_58 * V_106 ;
struct V_14 * V_79 ;
while ( ! F_126 ( V_168 ) ) {
V_106 = F_11 ( V_168 ) ;
F_21 ( V_106 , V_168 ) ;
V_79 = F_12 ( V_106 , struct V_14 , V_90 ) ;
F_22 ( V_79 ) ;
}
}
static void F_127 ( struct V_1 * V_1 )
{
F_24 ( V_1 ) ;
F_125 ( & V_1 -> V_170 [ 0 ] ) ;
F_125 ( & V_1 -> V_170 [ 1 ] ) ;
F_125 ( & V_1 -> V_91 ) ;
}
static void F_128 ( struct V_135 * V_133 )
{
struct V_1 * V_1 = F_47 ( V_133 ) ;
F_127 ( V_1 ) ;
}
static int F_129 ( struct V_135 * V_133 )
{
struct V_1 * V_1 = F_47 ( V_133 ) ;
F_123 ( V_1 ) ;
return 0 ;
}
int F_130 ( void )
{
int V_136 = F_131 ( sizeof( struct V_220 ) ,
F_129 ,
F_128 ) ;
if ( V_136 )
fputs ( L_5 , V_221 ) ;
return V_136 ;
}
