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
if ( V_15 -> V_57 )
F_3 ( V_1 , V_58 , strlen ( V_15 -> V_57 ) ) ;
}
void F_10 ( struct V_1 * V_1 , int V_59 )
{
struct V_60 * V_61 = F_11 ( & V_1 -> V_62 ) ;
struct V_14 * V_63 ;
int V_64 = 0 ;
F_4 ( V_1 ) ;
while ( V_61 && V_64 ++ < V_59 ) {
V_63 = F_12 ( V_61 , struct V_14 , V_60 ) ;
if ( ! V_63 -> V_65 )
F_6 ( V_1 , V_63 ) ;
V_61 = F_13 ( & V_63 -> V_60 ) ;
}
}
static void F_14 ( struct V_66 * V_66 ,
unsigned int V_67 , T_2 V_68 )
{
switch ( V_67 ) {
case V_69 :
V_66 -> V_70 += V_68 ;
break;
case V_71 :
V_66 -> V_72 += V_68 ;
break;
case V_73 :
V_66 -> V_74 += V_68 ;
break;
case V_75 :
V_66 -> V_76 += V_68 ;
break;
default:
break;
}
}
static void F_15 ( struct V_66 * V_66 , T_2 V_68 ,
T_2 V_77 )
{
V_66 -> V_68 += V_68 ;
V_66 -> V_77 += V_77 ;
V_66 -> V_78 += 1 ;
}
static void F_16 ( struct V_66 * V_79 , struct V_66 * V_80 )
{
V_79 -> V_68 += V_80 -> V_68 ;
V_79 -> V_70 += V_80 -> V_70 ;
V_79 -> V_72 += V_80 -> V_72 ;
V_79 -> V_74 += V_80 -> V_74 ;
V_79 -> V_76 += V_80 -> V_76 ;
V_79 -> V_78 += V_80 -> V_78 ;
V_79 -> V_77 += V_80 -> V_77 ;
}
static void F_17 ( struct V_66 * V_66 )
{
V_66 -> V_68 = ( V_66 -> V_68 * 7 ) / 8 ;
V_66 -> V_78 = ( V_66 -> V_78 * 7 ) / 8 ;
}
static bool F_18 ( struct V_1 * V_1 , struct V_14 * V_81 )
{
T_2 V_82 = V_81 -> V_83 . V_68 ;
T_2 V_84 ;
if ( V_82 == 0 )
return true ;
F_17 ( & V_81 -> V_83 ) ;
if ( V_10 . V_85 )
F_17 ( V_81 -> V_86 ) ;
F_19 ( V_81 -> V_87 ) ;
V_84 = V_82 - V_81 -> V_83 . V_68 ;
if ( ! V_81 -> V_88 ) {
V_1 -> V_89 . V_90 -= V_84 ;
if ( ! V_81 -> V_65 )
V_1 -> V_89 . V_91 -= V_84 ;
}
if ( ! V_81 -> V_92 ) {
struct V_14 * V_93 ;
struct V_60 * V_94 = F_11 ( & V_81 -> V_95 ) ;
while ( V_94 ) {
V_93 = F_12 ( V_94 , struct V_14 , V_60 ) ;
V_94 = F_13 ( V_94 ) ;
if ( F_18 ( V_1 , V_93 ) )
F_20 ( V_1 , V_93 ) ;
}
}
return V_81 -> V_83 . V_68 == 0 ;
}
static void F_20 ( struct V_1 * V_1 , struct V_14 * V_81 )
{
struct V_96 * V_97 ;
struct V_96 * V_98 ;
if ( V_81 -> V_99 ) {
V_97 = & V_81 -> V_99 -> V_100 ;
V_98 = & V_81 -> V_99 -> V_95 ;
} else {
if ( V_101 )
V_97 = & V_1 -> V_102 ;
else
V_97 = V_1 -> V_103 ;
V_98 = & V_1 -> V_62 ;
}
F_21 ( & V_81 -> V_104 , V_97 ) ;
F_21 ( & V_81 -> V_60 , V_98 ) ;
-- V_1 -> V_105 ;
if ( ! V_81 -> V_65 )
-- V_1 -> V_106 ;
F_22 ( V_81 ) ;
}
void F_23 ( struct V_1 * V_1 , bool V_107 , bool V_108 )
{
struct V_60 * V_61 = F_11 ( & V_1 -> V_62 ) ;
struct V_14 * V_63 ;
while ( V_61 ) {
V_63 = F_12 ( V_61 , struct V_14 , V_60 ) ;
V_61 = F_13 ( & V_63 -> V_60 ) ;
if ( ( ( V_107 && V_63 -> V_109 == '.' ) ||
( V_108 && V_63 -> V_109 != '.' ) ||
F_18 ( V_1 , V_63 ) ) ) {
F_20 ( V_1 , V_63 ) ;
}
}
}
void F_24 ( struct V_1 * V_1 )
{
struct V_60 * V_61 = F_11 ( & V_1 -> V_62 ) ;
struct V_14 * V_63 ;
while ( V_61 ) {
V_63 = F_12 ( V_61 , struct V_14 , V_60 ) ;
V_61 = F_13 ( & V_63 -> V_60 ) ;
F_20 ( V_1 , V_63 ) ;
}
}
static struct V_14 * F_25 ( struct V_14 * V_110 ,
bool V_111 )
{
T_3 V_112 = 0 ;
struct V_14 * V_81 ;
if ( V_10 . V_113 )
V_112 = sizeof( struct V_114 ) ;
V_81 = F_26 ( sizeof( * V_81 ) + V_112 ) ;
if ( V_81 != NULL ) {
* V_81 = * V_110 ;
if ( V_10 . V_85 ) {
V_81 -> V_86 = malloc ( sizeof( V_81 -> V_83 ) ) ;
if ( V_81 -> V_86 == NULL ) {
free ( V_81 ) ;
return NULL ;
}
memcpy ( V_81 -> V_86 , & V_81 -> V_83 , sizeof( V_81 -> V_83 ) ) ;
if ( ! V_111 )
memset ( & V_81 -> V_83 , 0 , sizeof( V_81 -> V_83 ) ) ;
}
F_27 ( V_81 -> V_17 . V_26 ) ;
if ( V_81 -> V_29 ) {
V_81 -> V_29 = malloc ( sizeof( * V_81 -> V_29 ) ) ;
if ( V_81 -> V_29 == NULL ) {
F_28 ( V_81 -> V_17 . V_26 ) ;
free ( V_81 -> V_86 ) ;
free ( V_81 ) ;
return NULL ;
}
memcpy ( V_81 -> V_29 , V_110 -> V_29 ,
sizeof( * V_81 -> V_29 ) ) ;
F_27 ( V_81 -> V_29 -> V_30 . V_26 ) ;
F_27 ( V_81 -> V_29 -> V_33 . V_26 ) ;
}
if ( V_81 -> V_36 ) {
F_27 ( V_81 -> V_36 -> V_40 . V_26 ) ;
F_27 ( V_81 -> V_36 -> V_37 . V_26 ) ;
}
if ( V_10 . V_113 )
F_29 ( V_81 -> V_87 ) ;
if ( V_81 -> V_115 ) {
V_81 -> V_115 = F_30 ( V_81 -> V_115 , V_81 -> V_116 ) ;
if ( V_81 -> V_115 == NULL ) {
F_31 ( V_81 -> V_17 . V_26 ) ;
if ( V_81 -> V_29 ) {
F_31 ( V_81 -> V_29 -> V_30 . V_26 ) ;
F_31 ( V_81 -> V_29 -> V_33 . V_26 ) ;
free ( V_81 -> V_29 ) ;
}
if ( V_81 -> V_36 ) {
F_31 ( V_81 -> V_36 -> V_40 . V_26 ) ;
F_31 ( V_81 -> V_36 -> V_37 . V_26 ) ;
}
free ( V_81 -> V_86 ) ;
free ( V_81 ) ;
return NULL ;
}
}
F_32 ( & V_81 -> V_117 . V_94 ) ;
F_33 ( V_81 -> V_23 ) ;
if ( ! V_10 . V_118 )
V_81 -> V_92 = true ;
}
return V_81 ;
}
static T_4 F_34 ( const struct V_119 * V_27 )
{
if ( V_10 . V_120 && V_27 == NULL )
return 1 << V_121 ;
return 0 ;
}
static void F_35 ( struct V_14 * V_81 , T_2 V_68 )
{
if ( ! V_10 . V_113 )
return;
V_81 -> V_1 -> V_122 += V_68 ;
if ( ! V_81 -> V_65 )
V_81 -> V_1 -> V_123 += V_68 ;
}
static struct V_14 * F_36 ( struct V_1 * V_1 ,
struct V_14 * V_124 ,
struct V_125 * V_126 ,
bool V_111 )
{
struct V_60 * * V_127 ;
struct V_60 * V_27 = NULL ;
struct V_14 * V_81 ;
T_5 V_128 ;
T_2 V_68 = V_124 -> V_83 . V_68 ;
T_2 V_77 = V_124 -> V_83 . V_77 ;
V_127 = & V_1 -> V_103 -> V_60 ;
while ( * V_127 != NULL ) {
V_27 = * V_127 ;
V_81 = F_12 ( V_27 , struct V_14 , V_104 ) ;
V_128 = F_37 ( V_81 , V_124 ) ;
if ( ! V_128 ) {
if ( V_111 ) {
F_15 ( & V_81 -> V_83 , V_68 , V_77 ) ;
F_35 ( V_81 , V_68 ) ;
}
if ( V_10 . V_85 )
F_15 ( V_81 -> V_86 , V_68 , V_77 ) ;
F_38 ( & V_124 -> V_36 ) ;
if ( V_81 -> V_17 . V_26 != V_124 -> V_17 . V_26 ) {
F_31 ( V_81 -> V_17 . V_26 ) ;
V_81 -> V_17 . V_26 = F_27 ( V_124 -> V_17 . V_26 ) ;
}
goto V_129;
}
if ( V_128 < 0 )
V_127 = & ( * V_127 ) -> V_130 ;
else
V_127 = & ( * V_127 ) -> V_131 ;
}
V_81 = F_25 ( V_124 , V_111 ) ;
if ( ! V_81 )
return NULL ;
if ( V_111 )
F_35 ( V_81 , V_68 ) ;
V_1 -> V_105 ++ ;
F_39 ( & V_81 -> V_104 , V_27 , V_127 ) ;
F_40 ( & V_81 -> V_104 , V_1 -> V_103 ) ;
V_129:
if ( V_111 )
F_14 ( & V_81 -> V_83 , V_126 -> V_67 , V_68 ) ;
if ( V_10 . V_85 )
F_14 ( V_81 -> V_86 , V_126 -> V_67 , V_68 ) ;
return V_81 ;
}
struct V_14 * F_41 ( struct V_1 * V_1 ,
struct V_125 * V_126 ,
struct V_119 * V_132 ,
struct V_29 * V_133 ,
struct V_36 * V_134 ,
struct V_135 * V_136 ,
bool V_111 )
{
struct V_14 V_124 = {
. V_23 = V_126 -> V_23 ,
. V_137 = F_42 ( V_126 -> V_23 ) ,
. V_17 = {
. V_26 = V_126 -> V_26 ,
. V_18 = V_126 -> V_18 ,
} ,
. V_138 = V_126 -> V_138 ,
. V_139 = V_126 -> V_139 ,
. V_67 = V_126 -> V_67 ,
. V_140 = V_126 -> V_141 ,
. V_109 = V_126 -> V_109 ,
. V_83 = {
. V_78 = 1 ,
. V_68 = V_136 -> V_68 ,
. V_77 = V_136 -> V_77 ,
} ,
. V_27 = V_132 ,
. V_65 = F_34 ( V_132 ) | V_126 -> V_65 ,
. V_1 = V_1 ,
. V_29 = V_133 ,
. V_36 = V_134 ,
. V_55 = V_136 -> V_55 ,
. V_115 = V_136 -> V_115 ,
. V_116 = V_136 -> V_116 ,
} ;
return F_36 ( V_1 , & V_124 , V_126 , V_111 ) ;
}
static int
F_43 ( struct V_142 * T_6 V_143 ,
struct V_125 * V_126 V_143 )
{
return 0 ;
}
static int
F_44 ( struct V_142 * T_6 V_143 ,
struct V_125 * V_126 V_143 )
{
return 0 ;
}
static int
F_45 ( struct V_142 * T_6 , struct V_125 * V_126 )
{
struct V_135 * V_136 = T_6 -> V_136 ;
struct V_36 * V_134 ;
V_134 = F_46 ( V_136 , V_126 ) ;
if ( V_134 == NULL )
return - V_144 ;
T_6 -> V_145 = V_134 ;
return 0 ;
}
static int
F_47 ( struct V_142 * T_6 , struct V_125 * V_126 )
{
T_2 V_146 ;
struct V_36 * V_134 = T_6 -> V_145 ;
struct V_1 * V_1 = F_48 ( T_6 -> V_147 ) ;
struct V_135 * V_136 = T_6 -> V_136 ;
struct V_14 * V_81 ;
if ( V_134 == NULL )
return - V_148 ;
V_146 = V_136 -> V_77 ;
if ( ! V_146 )
V_146 = 1 ;
V_136 -> V_68 = V_146 ;
V_81 = F_41 ( V_1 , V_126 , T_6 -> V_27 , NULL , V_134 ,
V_136 , true ) ;
if ( ! V_81 )
return - V_144 ;
T_6 -> V_81 = V_81 ;
return 0 ;
}
static int
F_49 ( struct V_142 * T_6 ,
struct V_125 * V_126 V_143 )
{
struct V_149 * V_147 = T_6 -> V_147 ;
struct V_1 * V_1 = F_48 ( V_147 ) ;
struct V_14 * V_81 = T_6 -> V_81 ;
int V_150 = - V_148 ;
if ( V_81 == NULL )
goto V_129;
F_50 ( V_1 , V_81 -> V_65 ) ;
V_150 = F_51 ( V_81 , T_6 -> V_136 ) ;
V_129:
T_6 -> V_145 = NULL ;
T_6 -> V_81 = NULL ;
return V_150 ;
}
static int
F_52 ( struct V_142 * T_6 , struct V_125 * V_126 )
{
struct V_29 * V_133 ;
struct V_135 * V_136 = T_6 -> V_136 ;
V_133 = F_53 ( V_136 , V_126 ) ;
if ( ! V_133 )
return - V_144 ;
T_6 -> V_151 = 0 ;
T_6 -> V_152 = V_136 -> V_153 -> V_154 ;
T_6 -> V_145 = V_133 ;
return 0 ;
}
static int
F_54 ( struct V_142 * T_6 ,
struct V_125 * V_126 V_143 )
{
T_6 -> V_81 = NULL ;
return 0 ;
}
static int
F_55 ( struct V_142 * T_6 , struct V_125 * V_126 )
{
struct V_29 * V_133 = T_6 -> V_145 ;
int V_155 = T_6 -> V_151 ;
if ( V_133 == NULL )
return 0 ;
if ( T_6 -> V_151 >= T_6 -> V_152 )
return 0 ;
V_126 -> V_26 = V_133 [ V_155 ] . V_33 . V_26 ;
V_126 -> V_18 = V_133 [ V_155 ] . V_33 . V_18 ;
V_126 -> V_141 = V_133 [ V_155 ] . V_33 . V_141 ;
return 1 ;
}
static int
F_56 ( struct V_142 * T_6 , struct V_125 * V_126 )
{
struct V_29 * V_133 ;
struct V_149 * V_147 = T_6 -> V_147 ;
struct V_1 * V_1 = F_48 ( V_147 ) ;
struct V_135 * V_136 = T_6 -> V_136 ;
struct V_14 * V_81 = NULL ;
int V_155 = T_6 -> V_151 ;
int V_150 = 0 ;
V_133 = T_6 -> V_145 ;
if ( T_6 -> V_156 && ! ( V_133 [ V_155 ] . V_30 . V_18 && V_133 [ V_155 ] . V_33 . V_18 ) )
goto V_129;
V_136 -> V_68 = 1 ;
V_136 -> V_77 = V_133 -> V_157 . V_158 ? V_133 -> V_157 . V_158 : 1 ;
V_81 = F_41 ( V_1 , V_126 , T_6 -> V_27 , & V_133 [ V_155 ] , NULL ,
V_136 , true ) ;
if ( V_81 == NULL )
return - V_144 ;
F_50 ( V_1 , V_81 -> V_65 ) ;
V_129:
T_6 -> V_81 = V_81 ;
T_6 -> V_151 ++ ;
return V_150 ;
}
static int
F_57 ( struct V_142 * T_6 ,
struct V_125 * V_126 V_143 )
{
F_38 ( & T_6 -> V_145 ) ;
T_6 -> V_81 = NULL ;
return T_6 -> V_151 >= T_6 -> V_152 ? 0 : - 1 ;
}
static int
F_58 ( struct V_142 * T_6 V_143 ,
struct V_125 * V_126 V_143 )
{
return 0 ;
}
static int
F_59 ( struct V_142 * T_6 , struct V_125 * V_126 )
{
struct V_149 * V_147 = T_6 -> V_147 ;
struct V_135 * V_136 = T_6 -> V_136 ;
struct V_14 * V_81 ;
V_81 = F_41 ( F_48 ( V_147 ) , V_126 , T_6 -> V_27 , NULL , NULL ,
V_136 , true ) ;
if ( V_81 == NULL )
return - V_144 ;
T_6 -> V_81 = V_81 ;
return 0 ;
}
static int
F_60 ( struct V_142 * T_6 ,
struct V_125 * V_126 V_143 )
{
struct V_14 * V_81 = T_6 -> V_81 ;
struct V_149 * V_147 = T_6 -> V_147 ;
struct V_135 * V_136 = T_6 -> V_136 ;
if ( V_81 == NULL )
return 0 ;
T_6 -> V_81 = NULL ;
F_50 ( F_48 ( V_147 ) , V_81 -> V_65 ) ;
return F_51 ( V_81 , V_136 ) ;
}
static int
F_61 ( struct V_142 * T_6 ,
struct V_125 * V_126 V_143 )
{
struct V_14 * * V_159 ;
F_62 ( & V_160 ) ;
V_159 = malloc ( sizeof( * V_159 ) * ( T_6 -> V_161 + 1 ) ) ;
if ( V_159 == NULL )
return - V_144 ;
T_6 -> V_145 = V_159 ;
T_6 -> V_151 = 0 ;
return 0 ;
}
static int
F_63 ( struct V_142 * T_6 ,
struct V_125 * V_126 )
{
struct V_149 * V_147 = T_6 -> V_147 ;
struct V_1 * V_1 = F_48 ( V_147 ) ;
struct V_135 * V_136 = T_6 -> V_136 ;
struct V_14 * * V_159 = T_6 -> V_145 ;
struct V_14 * V_81 ;
int V_150 = 0 ;
V_81 = F_41 ( V_1 , V_126 , T_6 -> V_27 , NULL , NULL ,
V_136 , true ) ;
if ( V_81 == NULL )
return - V_144 ;
T_6 -> V_81 = V_81 ;
V_159 [ T_6 -> V_151 ++ ] = V_81 ;
F_51 ( V_81 , V_136 ) ;
F_62 ( & V_160 ) ;
F_50 ( V_1 , V_81 -> V_65 ) ;
return V_150 ;
}
static int
F_64 ( struct V_142 * T_6 ,
struct V_125 * V_126 )
{
struct V_162 * V_94 ;
V_94 = F_65 ( & V_160 ) ;
if ( V_94 == NULL )
return 0 ;
return F_66 ( V_126 , V_94 , T_6 -> V_156 ) ;
}
static int
F_67 ( struct V_142 * T_6 ,
struct V_125 * V_126 )
{
struct V_149 * V_147 = T_6 -> V_147 ;
struct V_135 * V_136 = T_6 -> V_136 ;
struct V_14 * * V_159 = T_6 -> V_145 ;
struct V_14 * V_81 ;
struct V_14 V_163 = {
. V_1 = F_48 ( V_147 ) ,
. V_139 = V_126 -> V_139 ,
. V_23 = V_126 -> V_23 ,
. V_137 = F_42 ( V_126 -> V_23 ) ,
. V_140 = V_126 -> V_141 ,
. V_17 = {
. V_26 = V_126 -> V_26 ,
. V_18 = V_126 -> V_18 ,
} ,
. V_27 = T_6 -> V_27 ,
. V_115 = V_136 -> V_115 ,
. V_116 = V_136 -> V_116 ,
} ;
int V_155 ;
struct V_160 V_164 ;
F_68 ( & V_164 , & V_160 ) ;
F_69 ( & V_160 ) ;
for ( V_155 = 0 ; V_155 < T_6 -> V_151 ; V_155 ++ ) {
if ( F_37 ( V_159 [ V_155 ] , & V_163 ) == 0 ) {
T_6 -> V_81 = NULL ;
return 0 ;
}
}
V_81 = F_41 ( F_48 ( V_147 ) , V_126 , T_6 -> V_27 , NULL , NULL ,
V_136 , false ) ;
if ( V_81 == NULL )
return - V_144 ;
T_6 -> V_81 = V_81 ;
V_159 [ T_6 -> V_151 ++ ] = V_81 ;
if ( V_10 . V_113 )
F_70 ( V_81 -> V_87 , & V_164 , V_136 -> V_68 ) ;
return 0 ;
}
static int
F_71 ( struct V_142 * T_6 ,
struct V_125 * V_126 V_143 )
{
F_38 ( & T_6 -> V_145 ) ;
T_6 -> V_81 = NULL ;
return 0 ;
}
int F_72 ( struct V_142 * T_6 , struct V_125 * V_126 ,
int V_165 , void * V_166 )
{
int V_150 , V_167 ;
V_150 = F_73 ( T_6 -> V_136 , & T_6 -> V_27 ,
T_6 -> V_147 , V_126 , V_165 ) ;
if ( V_150 )
return V_150 ;
T_6 -> V_161 = V_165 ;
V_150 = T_6 -> V_168 -> V_169 ( T_6 , V_126 ) ;
if ( V_150 )
goto V_129;
V_150 = T_6 -> V_168 -> V_170 ( T_6 , V_126 ) ;
if ( V_150 )
goto V_129;
if ( T_6 -> V_81 && T_6 -> V_171 ) {
V_150 = T_6 -> V_171 ( T_6 , V_126 , true , V_166 ) ;
if ( V_150 )
goto V_129;
}
while ( T_6 -> V_168 -> V_172 ( T_6 , V_126 ) ) {
V_150 = T_6 -> V_168 -> V_173 ( T_6 , V_126 ) ;
if ( V_150 )
break;
if ( T_6 -> V_81 && T_6 -> V_171 ) {
V_150 = T_6 -> V_171 ( T_6 , V_126 , false , V_166 ) ;
if ( V_150 )
goto V_129;
}
}
V_129:
V_167 = T_6 -> V_168 -> V_174 ( T_6 , V_126 ) ;
if ( ! V_150 )
V_150 = V_167 ;
return V_150 ;
}
T_5
F_37 ( struct V_14 * V_175 , struct V_14 * V_176 )
{
struct V_1 * V_1 = V_175 -> V_1 ;
struct V_177 * V_178 ;
T_5 V_128 = 0 ;
F_74 (hists, fmt) {
if ( F_75 ( V_178 ) &&
! F_76 ( V_178 , V_1 ) )
continue;
V_128 = V_178 -> V_128 ( V_178 , V_175 , V_176 ) ;
if ( V_128 )
break;
}
return V_128 ;
}
T_5
F_77 ( struct V_14 * V_175 , struct V_14 * V_176 )
{
struct V_1 * V_1 = V_175 -> V_1 ;
struct V_177 * V_178 ;
T_5 V_128 = 0 ;
F_74 (hists, fmt) {
if ( F_75 ( V_178 ) &&
! F_76 ( V_178 , V_1 ) )
continue;
V_128 = V_178 -> V_179 ( V_178 , V_175 , V_176 ) ;
if ( V_128 )
break;
}
return V_128 ;
}
void F_22 ( struct V_14 * V_81 )
{
F_78 ( V_81 -> V_23 ) ;
F_28 ( V_81 -> V_17 . V_26 ) ;
if ( V_81 -> V_29 ) {
F_28 ( V_81 -> V_29 -> V_30 . V_26 ) ;
F_28 ( V_81 -> V_29 -> V_33 . V_26 ) ;
F_38 ( & V_81 -> V_29 ) ;
}
if ( V_81 -> V_36 ) {
F_28 ( V_81 -> V_36 -> V_40 . V_26 ) ;
F_28 ( V_81 -> V_36 -> V_37 . V_26 ) ;
F_38 ( & V_81 -> V_36 ) ;
}
F_38 ( & V_81 -> V_86 ) ;
F_79 ( V_81 -> V_51 ) ;
if ( V_81 -> V_53 && V_81 -> V_53 [ 0 ] )
free ( V_81 -> V_53 ) ;
F_80 ( V_81 -> V_87 ) ;
free ( V_81 -> V_57 ) ;
free ( V_81 -> V_115 ) ;
free ( V_81 ) ;
}
int F_81 ( struct V_14 * V_81 , struct V_180 * V_181 ,
struct V_177 * V_178 , int V_182 )
{
if ( ! F_82 ( & V_178 -> V_183 , & V_81 -> V_1 -> V_184 -> V_185 ) ) {
const int V_186 = V_178 -> V_186 ( V_178 , V_181 , F_83 ( V_81 -> V_1 ) ) ;
if ( V_182 < V_186 ) {
F_84 ( V_181 , V_182 ) ;
V_182 = F_85 ( V_181 -> V_187 , V_181 -> V_188 , L_1 , V_186 - V_182 , L_2 ) ;
}
}
return V_182 ;
}
static bool F_86 ( struct V_177 * V_178 )
{
return F_87 ( V_178 ) || F_88 ( V_178 ) ;
}
static void F_89 ( struct V_14 * V_81 ,
enum V_189 type ,
T_7 V_190 )
{
struct V_177 * V_178 ;
bool V_191 = false ;
struct V_14 * V_27 = V_81 -> V_99 ;
switch ( type ) {
case V_192 :
if ( V_10 . V_193 == NULL &&
V_10 . V_194 == NULL &&
V_10 . V_195 == NULL )
return;
break;
case V_196 :
if ( V_10 . V_13 == NULL )
return;
break;
case V_197 :
if ( V_10 . V_198 == NULL )
return;
break;
case V_121 :
case V_199 :
case V_200 :
case V_201 :
default:
return;
}
F_90 (he->hpp_list, fmt) {
if ( V_190 ( V_178 ) ) {
V_191 = true ;
break;
}
}
if ( V_191 ) {
if ( ! ( V_81 -> V_65 & ( 1 << type ) ) ) {
while ( V_27 ) {
V_27 -> V_65 &= ~ ( 1 << type ) ;
V_27 = V_27 -> V_99 ;
}
}
} else {
if ( V_27 == NULL )
V_81 -> V_65 |= ( 1 << type ) ;
else
V_81 -> V_65 |= ( V_27 -> V_65 & ( 1 << type ) ) ;
}
}
static void F_91 ( struct V_14 * V_81 )
{
F_89 ( V_81 , V_192 ,
F_86 ) ;
F_89 ( V_81 , V_196 ,
V_202 ) ;
F_89 ( V_81 , V_197 ,
V_203 ) ;
F_92 ( V_81 -> V_1 , V_81 ) ;
}
static struct V_14 * F_93 ( struct V_1 * V_1 ,
struct V_96 * V_204 ,
struct V_14 * V_81 ,
struct V_14 * V_99 ,
struct V_205 * V_184 )
{
struct V_60 * * V_127 = & V_204 -> V_60 ;
struct V_60 * V_27 = NULL ;
struct V_14 * T_6 , * V_206 ;
struct V_177 * V_178 ;
T_5 V_128 ;
while ( * V_127 != NULL ) {
V_27 = * V_127 ;
T_6 = F_12 ( V_27 , struct V_14 , V_104 ) ;
V_128 = 0 ;
F_94 (hpp_list, fmt) {
V_128 = V_178 -> V_179 ( V_178 , T_6 , V_81 ) ;
if ( V_128 )
break;
}
if ( ! V_128 ) {
F_16 ( & T_6 -> V_83 , & V_81 -> V_83 ) ;
return T_6 ;
}
if ( V_128 < 0 )
V_127 = & V_27 -> V_130 ;
else
V_127 = & V_27 -> V_131 ;
}
V_206 = F_25 ( V_81 , true ) ;
if ( V_206 == NULL )
return NULL ;
V_1 -> V_105 ++ ;
V_206 -> V_184 = V_184 ;
V_206 -> V_99 = V_99 ;
F_91 ( V_206 ) ;
F_94 (hpp_list, fmt) {
if ( F_95 ( V_178 ) || F_75 ( V_178 ) )
V_81 -> V_57 = NULL ;
else
V_206 -> V_57 = NULL ;
if ( F_96 ( V_178 ) )
V_81 -> V_51 = NULL ;
else
V_206 -> V_51 = NULL ;
if ( F_97 ( V_178 ) )
V_81 -> V_53 = NULL ;
else
V_206 -> V_53 = NULL ;
}
F_39 ( & V_206 -> V_104 , V_27 , V_127 ) ;
F_40 ( & V_206 -> V_104 , V_204 ) ;
return V_206 ;
}
static int F_98 ( struct V_1 * V_1 ,
struct V_96 * V_204 ,
struct V_14 * V_81 )
{
struct V_207 * V_94 ;
struct V_14 * V_208 = NULL ;
struct V_14 * V_27 = NULL ;
int V_88 = 0 ;
int V_209 = 0 ;
F_99 (node, &hists->hpp_formats, list) {
if ( V_94 -> V_109 == 0 || V_94 -> V_210 )
continue;
V_208 = F_93 ( V_1 , V_204 , V_81 , V_27 , & V_94 -> V_181 ) ;
if ( V_208 == NULL ) {
V_209 = - 1 ;
break;
}
V_204 = & V_208 -> V_100 ;
V_208 -> V_88 = V_88 ++ ;
V_27 = V_208 ;
}
if ( V_208 ) {
V_208 -> V_92 = true ;
if ( V_10 . V_113 ) {
F_100 ( & V_160 ) ;
if ( F_101 ( & V_160 ,
V_208 -> V_87 ,
V_81 -> V_87 ) < 0 )
V_209 = - 1 ;
}
}
F_22 ( V_81 ) ;
return V_209 ;
}
int F_102 ( struct V_1 * V_1 , struct V_96 * V_204 ,
struct V_14 * V_81 )
{
struct V_60 * * V_127 = & V_204 -> V_60 ;
struct V_60 * V_27 = NULL ;
struct V_14 * T_6 ;
T_5 V_128 ;
if ( V_10 . V_118 )
return F_98 ( V_1 , V_204 , V_81 ) ;
while ( * V_127 != NULL ) {
V_27 = * V_127 ;
T_6 = F_12 ( V_27 , struct V_14 , V_104 ) ;
V_128 = F_77 ( T_6 , V_81 ) ;
if ( ! V_128 ) {
int V_209 = 0 ;
F_16 ( & T_6 -> V_83 , & V_81 -> V_83 ) ;
if ( V_10 . V_85 )
F_16 ( T_6 -> V_86 , V_81 -> V_86 ) ;
if ( V_10 . V_113 ) {
F_100 ( & V_160 ) ;
if ( F_101 ( & V_160 ,
T_6 -> V_87 ,
V_81 -> V_87 ) < 0 )
V_209 = - 1 ;
}
F_22 ( V_81 ) ;
return V_209 ;
}
if ( V_128 < 0 )
V_127 = & ( * V_127 ) -> V_130 ;
else
V_127 = & ( * V_127 ) -> V_131 ;
}
V_1 -> V_105 ++ ;
F_39 ( & V_81 -> V_104 , V_27 , V_127 ) ;
F_40 ( & V_81 -> V_104 , V_204 ) ;
return 1 ;
}
struct V_96 * F_103 ( struct V_1 * V_1 )
{
struct V_96 * V_204 ;
F_104 ( & V_1 -> V_211 ) ;
V_204 = V_1 -> V_103 ;
if ( ++ V_1 -> V_103 > & V_1 -> V_212 [ 1 ] )
V_1 -> V_103 = & V_1 -> V_212 [ 0 ] ;
F_105 ( & V_1 -> V_211 ) ;
return V_204 ;
}
static void F_92 ( struct V_1 * V_1 , struct V_14 * V_81 )
{
F_106 ( V_1 , V_81 ) ;
F_107 ( V_1 , V_81 ) ;
F_108 ( V_1 , V_81 ) ;
F_109 ( V_1 , V_81 ) ;
}
int F_110 ( struct V_1 * V_1 , struct V_213 * V_214 )
{
struct V_96 * V_204 ;
struct V_60 * V_61 ;
struct V_14 * V_63 ;
int V_209 ;
if ( ! V_101 )
return 0 ;
V_1 -> V_105 = 0 ;
V_204 = F_103 ( V_1 ) ;
V_61 = F_11 ( V_204 ) ;
while ( V_61 ) {
if ( F_111 () )
break;
V_63 = F_12 ( V_61 , struct V_14 , V_104 ) ;
V_61 = F_13 ( & V_63 -> V_104 ) ;
F_21 ( & V_63 -> V_104 , V_204 ) ;
V_209 = F_102 ( V_1 , & V_1 -> V_102 , V_63 ) ;
if ( V_209 < 0 )
return - 1 ;
if ( V_209 ) {
F_92 ( V_1 , V_63 ) ;
}
if ( V_214 )
F_112 ( V_214 , 1 ) ;
}
return 0 ;
}
static int F_113 ( struct V_14 * V_215 , struct V_14 * V_216 )
{
struct V_1 * V_1 = V_215 -> V_1 ;
struct V_177 * V_178 ;
T_5 V_128 = 0 ;
F_74 (hists, fmt) {
if ( F_114 ( V_178 , V_215 -> V_1 ) )
continue;
V_128 = V_178 -> V_217 ( V_178 , V_215 , V_216 ) ;
if ( V_128 )
break;
}
return V_128 ;
}
static void F_115 ( struct V_1 * V_1 )
{
V_1 -> V_106 = 0 ;
V_1 -> V_89 . V_91 = 0 ;
}
void F_116 ( struct V_1 * V_1 )
{
V_1 -> V_105 = 0 ;
V_1 -> V_89 . V_90 = 0 ;
F_115 ( V_1 ) ;
}
static void F_117 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
V_1 -> V_106 ++ ;
V_1 -> V_89 . V_91 += V_15 -> V_83 . V_68 ;
}
void F_118 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
if ( ! V_15 -> V_65 )
F_117 ( V_1 , V_15 ) ;
V_1 -> V_105 ++ ;
V_1 -> V_89 . V_90 += V_15 -> V_83 . V_68 ;
}
static void F_119 ( struct V_1 * V_1 )
{
struct V_60 * V_94 ;
struct V_14 * V_81 ;
V_94 = F_11 ( & V_1 -> V_62 ) ;
V_1 -> V_89 . V_90 = 0 ;
V_1 -> V_89 . V_91 = 0 ;
while ( V_94 ) {
V_81 = F_12 ( V_94 , struct V_14 , V_60 ) ;
V_94 = F_13 ( V_94 ) ;
V_1 -> V_89 . V_90 += V_81 -> V_83 . V_68 ;
if ( ! V_81 -> V_65 )
V_1 -> V_89 . V_91 += V_81 -> V_83 . V_68 ;
}
}
static void F_120 ( struct V_96 * V_204 ,
struct V_14 * V_81 )
{
struct V_60 * * V_127 = & V_204 -> V_60 ;
struct V_60 * V_27 = NULL ;
struct V_14 * T_6 ;
struct V_177 * V_178 ;
while ( * V_127 != NULL ) {
V_27 = * V_127 ;
T_6 = F_12 ( V_27 , struct V_14 , V_60 ) ;
if ( F_113 ( V_81 , T_6 ) > 0 )
V_127 = & V_27 -> V_130 ;
else
V_127 = & V_27 -> V_131 ;
}
F_39 ( & V_81 -> V_60 , V_27 , V_127 ) ;
F_40 ( & V_81 -> V_60 , V_204 ) ;
F_94 (he->hpp_list, fmt) {
if ( F_75 ( V_178 ) )
V_178 -> V_217 ( V_178 , V_81 , NULL ) ;
}
}
static void F_121 ( struct V_1 * V_1 ,
struct V_213 * V_214 ,
struct V_96 * V_97 ,
struct V_96 * V_98 ,
T_2 V_218 ,
bool V_113 )
{
struct V_60 * V_94 ;
struct V_14 * V_81 ;
* V_98 = V_219 ;
V_94 = F_11 ( V_97 ) ;
while ( V_94 ) {
V_81 = F_12 ( V_94 , struct V_14 , V_104 ) ;
V_94 = F_13 ( V_94 ) ;
F_120 ( V_98 , V_81 ) ;
if ( V_214 )
F_112 ( V_214 , 1 ) ;
if ( ! V_81 -> V_92 ) {
F_121 ( V_1 , V_214 ,
& V_81 -> V_100 ,
& V_81 -> V_95 ,
V_218 ,
V_113 ) ;
V_1 -> V_105 ++ ;
if ( ! V_81 -> V_65 ) {
V_1 -> V_106 ++ ;
F_6 ( V_1 , V_81 ) ;
}
continue;
}
if ( ! V_113 )
continue;
if ( V_220 . V_221 == V_222 ) {
T_2 V_152 = V_81 -> V_83 . V_68 ;
if ( V_10 . V_85 )
V_152 = V_81 -> V_86 -> V_68 ;
V_218 = V_152 * ( V_220 . V_223 / 100 ) ;
}
V_220 . V_217 ( & V_81 -> V_224 , V_81 -> V_87 ,
V_218 , & V_220 ) ;
}
}
static void F_122 ( struct V_96 * V_62 ,
struct V_14 * V_81 ,
T_2 V_218 ,
bool V_113 )
{
struct V_60 * * V_127 = & V_62 -> V_60 ;
struct V_60 * V_27 = NULL ;
struct V_14 * T_6 ;
struct V_177 * V_178 ;
if ( V_113 ) {
if ( V_220 . V_221 == V_222 ) {
T_2 V_152 = V_81 -> V_83 . V_68 ;
if ( V_10 . V_85 )
V_152 = V_81 -> V_86 -> V_68 ;
V_218 = V_152 * ( V_220 . V_223 / 100 ) ;
}
V_220 . V_217 ( & V_81 -> V_224 , V_81 -> V_87 ,
V_218 , & V_220 ) ;
}
while ( * V_127 != NULL ) {
V_27 = * V_127 ;
T_6 = F_12 ( V_27 , struct V_14 , V_60 ) ;
if ( F_113 ( V_81 , T_6 ) > 0 )
V_127 = & ( * V_127 ) -> V_130 ;
else
V_127 = & ( * V_127 ) -> V_131 ;
}
F_39 ( & V_81 -> V_60 , V_27 , V_127 ) ;
F_40 ( & V_81 -> V_60 , V_62 ) ;
F_94 (&perf_hpp_list, fmt) {
if ( F_75 ( V_178 ) &&
F_76 ( V_178 , V_81 -> V_1 ) )
V_178 -> V_217 ( V_178 , V_81 , NULL ) ;
}
}
static void F_123 ( struct V_1 * V_1 , struct V_213 * V_214 ,
bool V_113 )
{
struct V_96 * V_204 ;
struct V_60 * V_61 ;
struct V_14 * V_63 ;
T_2 V_225 ;
T_2 V_218 ;
V_225 = V_1 -> V_122 ;
if ( V_10 . V_226 )
V_225 = V_1 -> V_123 ;
V_218 = V_225 * ( V_220 . V_223 / 100 ) ;
F_116 ( V_1 ) ;
F_4 ( V_1 ) ;
if ( V_10 . V_118 ) {
F_121 ( V_1 , V_214 ,
& V_1 -> V_102 ,
& V_1 -> V_62 ,
V_218 ,
V_113 ) ;
F_119 ( V_1 ) ;
return;
}
if ( V_101 )
V_204 = & V_1 -> V_102 ;
else
V_204 = V_1 -> V_103 ;
V_61 = F_11 ( V_204 ) ;
V_1 -> V_62 = V_219 ;
while ( V_61 ) {
V_63 = F_12 ( V_61 , struct V_14 , V_104 ) ;
V_61 = F_13 ( & V_63 -> V_104 ) ;
F_122 ( & V_1 -> V_62 , V_63 , V_218 , V_113 ) ;
F_118 ( V_1 , V_63 ) ;
if ( ! V_63 -> V_65 )
F_6 ( V_1 , V_63 ) ;
if ( V_214 )
F_112 ( V_214 , 1 ) ;
}
}
void F_124 ( struct V_149 * V_147 , struct V_213 * V_214 )
{
bool V_113 ;
if ( V_147 && V_10 . V_113 && ! V_10 . V_227 )
V_113 = V_147 -> V_228 . V_229 & V_230 ;
else
V_113 = V_10 . V_113 ;
F_123 ( F_48 ( V_147 ) , V_214 , V_113 ) ;
}
void F_125 ( struct V_1 * V_1 , struct V_213 * V_214 )
{
F_123 ( V_1 , V_214 , V_10 . V_113 ) ;
}
static bool F_126 ( struct V_14 * V_81 , enum V_231 V_232 )
{
if ( V_81 -> V_92 || V_232 == V_233 )
return false ;
if ( V_81 -> V_234 || V_232 == V_235 )
return true ;
return false ;
}
struct V_60 * F_127 ( struct V_60 * V_94 )
{
struct V_14 * V_81 = F_12 ( V_94 , struct V_14 , V_60 ) ;
while ( F_126 ( V_81 , V_236 ) ) {
V_94 = F_128 ( & V_81 -> V_95 ) ;
V_81 = F_12 ( V_94 , struct V_14 , V_60 ) ;
}
return V_94 ;
}
struct V_60 * F_129 ( struct V_60 * V_94 , enum V_231 V_232 )
{
struct V_14 * V_81 = F_12 ( V_94 , struct V_14 , V_60 ) ;
if ( F_126 ( V_81 , V_232 ) )
V_94 = F_11 ( & V_81 -> V_95 ) ;
else
V_94 = F_13 ( V_94 ) ;
while ( V_94 == NULL ) {
V_81 = V_81 -> V_99 ;
if ( V_81 == NULL )
break;
V_94 = F_13 ( & V_81 -> V_60 ) ;
}
return V_94 ;
}
struct V_60 * F_130 ( struct V_60 * V_94 )
{
struct V_14 * V_81 = F_12 ( V_94 , struct V_14 , V_60 ) ;
V_94 = F_131 ( V_94 ) ;
if ( V_94 )
return F_127 ( V_94 ) ;
V_81 = V_81 -> V_99 ;
if ( V_81 == NULL )
return NULL ;
return & V_81 -> V_60 ;
}
bool F_132 ( struct V_14 * V_81 , float V_237 )
{
struct V_60 * V_94 ;
struct V_14 * V_93 ;
float V_238 ;
if ( V_81 -> V_92 )
return false ;
V_94 = F_11 ( & V_81 -> V_95 ) ;
V_93 = F_12 ( V_94 , struct V_14 , V_60 ) ;
while ( V_94 && V_93 -> V_65 ) {
V_94 = F_13 ( V_94 ) ;
V_93 = F_12 ( V_94 , struct V_14 , V_60 ) ;
}
if ( V_94 )
V_238 = F_133 ( V_93 ) ;
else
V_238 = 0 ;
return V_94 && V_238 >= V_237 ;
}
static void F_134 ( struct V_1 * V_1 , struct V_14 * V_15 ,
enum V_189 V_239 )
{
V_15 -> V_65 &= ~ ( 1 << V_239 ) ;
if ( V_10 . V_118 ) {
struct V_14 * V_27 = V_15 -> V_99 ;
while ( V_27 ) {
F_16 ( & V_27 -> V_83 , & V_15 -> V_83 ) ;
V_27 -> V_65 &= ~ ( 1 << V_239 ) ;
if ( V_27 -> V_65 )
goto V_61;
V_27 -> V_234 = false ;
V_27 -> V_240 = false ;
V_27 -> V_241 = 0 ;
V_27 -> V_242 = 0 ;
V_61:
V_27 = V_27 -> V_99 ;
}
}
if ( V_15 -> V_65 )
return;
V_15 -> V_234 = false ;
V_15 -> V_240 = false ;
V_15 -> V_241 = 0 ;
V_15 -> V_242 = 0 ;
V_1 -> V_89 . V_243 += V_15 -> V_83 . V_78 ;
F_117 ( V_1 , V_15 ) ;
F_6 ( V_1 , V_15 ) ;
}
static bool F_106 ( struct V_1 * V_1 ,
struct V_14 * V_81 )
{
if ( V_1 -> V_244 != NULL &&
( V_81 -> V_17 . V_26 == NULL || V_81 -> V_17 . V_26 -> V_7 != V_1 -> V_244 ) ) {
V_81 -> V_65 |= ( 1 << V_196 ) ;
return true ;
}
return false ;
}
static bool F_107 ( struct V_1 * V_1 ,
struct V_14 * V_81 )
{
if ( V_1 -> V_245 != NULL &&
V_81 -> V_23 != V_1 -> V_245 ) {
V_81 -> V_65 |= ( 1 << V_192 ) ;
return true ;
}
return false ;
}
static bool F_108 ( struct V_1 * V_1 ,
struct V_14 * V_81 )
{
if ( V_1 -> V_246 != NULL &&
( ! V_81 -> V_17 . V_18 || strstr ( V_81 -> V_17 . V_18 -> V_247 ,
V_1 -> V_246 ) == NULL ) ) {
V_81 -> V_65 |= ( 1 << V_197 ) ;
return true ;
}
return false ;
}
static bool F_109 ( struct V_1 * V_1 ,
struct V_14 * V_81 )
{
if ( ( V_1 -> V_248 > - 1 ) &&
( V_81 -> V_138 != V_1 -> V_248 ) ) {
V_81 -> V_65 |= ( 1 << V_201 ) ;
return true ;
}
return false ;
}
static void F_135 ( struct V_1 * V_1 , int type , T_8 V_239 )
{
struct V_60 * V_249 ;
V_1 -> V_89 . V_243 = 0 ;
F_115 ( V_1 ) ;
F_4 ( V_1 ) ;
for ( V_249 = F_11 ( & V_1 -> V_62 ) ; V_249 ; V_249 = F_13 ( V_249 ) ) {
struct V_14 * V_15 = F_12 ( V_249 , struct V_14 , V_60 ) ;
if ( V_239 ( V_1 , V_15 ) )
continue;
F_134 ( V_1 , V_15 , type ) ;
}
}
static void F_136 ( struct V_96 * V_204 , struct V_14 * V_81 )
{
struct V_60 * * V_127 = & V_204 -> V_60 ;
struct V_60 * V_27 = NULL ;
struct V_14 * T_6 ;
struct V_96 V_250 = V_219 ;
struct V_60 * V_249 ;
while ( * V_127 != NULL ) {
V_27 = * V_127 ;
T_6 = F_12 ( V_27 , struct V_14 , V_60 ) ;
if ( F_113 ( V_81 , T_6 ) > 0 )
V_127 = & ( * V_127 ) -> V_130 ;
else
V_127 = & ( * V_127 ) -> V_131 ;
}
F_39 ( & V_81 -> V_60 , V_27 , V_127 ) ;
F_40 ( & V_81 -> V_60 , V_204 ) ;
if ( V_81 -> V_92 || V_81 -> V_65 )
return;
V_249 = F_11 ( & V_81 -> V_95 ) ;
while ( V_249 ) {
struct V_14 * V_15 = F_12 ( V_249 , struct V_14 , V_60 ) ;
V_249 = F_13 ( V_249 ) ;
F_21 ( & V_15 -> V_60 , & V_81 -> V_95 ) ;
F_136 ( & V_250 , V_15 ) ;
}
V_81 -> V_95 = V_250 ;
}
static void F_137 ( struct V_1 * V_1 , int type , const void * V_166 )
{
struct V_60 * V_249 ;
struct V_96 V_250 = V_219 ;
V_1 -> V_89 . V_243 = 0 ;
F_115 ( V_1 ) ;
F_4 ( V_1 ) ;
V_249 = F_11 ( & V_1 -> V_62 ) ;
while ( V_249 ) {
struct V_14 * V_15 = F_12 ( V_249 , struct V_14 , V_60 ) ;
int V_209 ;
V_209 = F_138 ( V_15 , type , V_166 ) ;
if ( V_209 < 0 ) {
memset ( & V_15 -> V_83 , 0 , sizeof( V_15 -> V_83 ) ) ;
V_15 -> V_65 |= ( 1 << type ) ;
V_249 = F_129 ( & V_15 -> V_60 , V_235 ) ;
}
else if ( V_209 == 1 ) {
V_15 -> V_65 |= ( 1 << type ) ;
V_249 = F_129 ( & V_15 -> V_60 , V_233 ) ;
}
else {
F_134 ( V_1 , V_15 , type ) ;
V_249 = F_129 ( & V_15 -> V_60 , V_233 ) ;
}
}
F_119 ( V_1 ) ;
V_249 = F_11 ( & V_1 -> V_62 ) ;
while ( V_249 ) {
struct V_14 * V_15 = F_12 ( V_249 , struct V_14 , V_60 ) ;
V_249 = F_13 ( V_249 ) ;
F_21 ( & V_15 -> V_60 , & V_1 -> V_62 ) ;
F_136 ( & V_250 , V_15 ) ;
}
V_1 -> V_62 = V_250 ;
}
void F_139 ( struct V_1 * V_1 )
{
if ( V_10 . V_118 )
F_137 ( V_1 , V_192 ,
V_1 -> V_245 ) ;
else
F_135 ( V_1 , V_192 ,
F_107 ) ;
}
void F_140 ( struct V_1 * V_1 )
{
if ( V_10 . V_118 )
F_137 ( V_1 , V_196 ,
V_1 -> V_244 ) ;
else
F_135 ( V_1 , V_196 ,
F_106 ) ;
}
void F_141 ( struct V_1 * V_1 )
{
if ( V_10 . V_118 )
F_137 ( V_1 , V_197 ,
V_1 -> V_246 ) ;
else
F_135 ( V_1 , V_197 ,
F_108 ) ;
}
void F_142 ( struct V_1 * V_1 )
{
if ( V_10 . V_118 )
F_137 ( V_1 , V_201 ,
& V_1 -> V_248 ) ;
else
F_135 ( V_1 , V_201 ,
F_109 ) ;
}
void F_143 ( struct V_251 * V_89 , T_9 type )
{
++ V_89 -> V_78 [ 0 ] ;
++ V_89 -> V_78 [ type ] ;
}
void F_144 ( struct V_1 * V_1 , T_9 type )
{
F_143 ( & V_1 -> V_89 , type ) ;
}
void F_50 ( struct V_1 * V_1 , bool V_65 )
{
F_143 ( & V_1 -> V_89 , V_252 ) ;
if ( ! V_65 )
V_1 -> V_89 . V_243 ++ ;
}
static struct V_14 * F_145 ( struct V_1 * V_1 ,
struct V_14 * V_253 )
{
struct V_96 * V_204 ;
struct V_60 * * V_127 ;
struct V_60 * V_27 = NULL ;
struct V_14 * V_81 ;
T_5 V_128 ;
if ( V_101 )
V_204 = & V_1 -> V_102 ;
else
V_204 = V_1 -> V_103 ;
V_127 = & V_204 -> V_60 ;
while ( * V_127 != NULL ) {
V_27 = * V_127 ;
V_81 = F_12 ( V_27 , struct V_14 , V_104 ) ;
V_128 = F_77 ( V_81 , V_253 ) ;
if ( ! V_128 )
goto V_129;
if ( V_128 < 0 )
V_127 = & ( * V_127 ) -> V_130 ;
else
V_127 = & ( * V_127 ) -> V_131 ;
}
V_81 = F_25 ( V_253 , true ) ;
if ( V_81 ) {
memset ( & V_81 -> V_83 , 0 , sizeof( V_81 -> V_83 ) ) ;
V_81 -> V_1 = V_1 ;
F_39 ( & V_81 -> V_104 , V_27 , V_127 ) ;
F_40 ( & V_81 -> V_104 , V_204 ) ;
F_118 ( V_1 , V_81 ) ;
V_81 -> V_254 = true ;
}
V_129:
return V_81 ;
}
static struct V_14 * F_146 ( struct V_1 * V_1 ,
struct V_14 * V_81 )
{
struct V_60 * V_63 ;
if ( V_101 )
V_63 = V_1 -> V_102 . V_60 ;
else
V_63 = V_1 -> V_103 -> V_60 ;
while ( V_63 ) {
struct V_14 * T_6 = F_12 ( V_63 , struct V_14 , V_104 ) ;
T_5 V_128 = F_77 ( T_6 , V_81 ) ;
if ( V_128 < 0 )
V_63 = V_63 -> V_130 ;
else if ( V_128 > 0 )
V_63 = V_63 -> V_131 ;
else
return T_6 ;
}
return NULL ;
}
void F_147 ( struct V_1 * V_255 , struct V_1 * V_256 )
{
struct V_96 * V_204 ;
struct V_60 * V_249 ;
struct V_14 * V_257 , * V_253 ;
if ( V_101 )
V_204 = & V_255 -> V_102 ;
else
V_204 = V_255 -> V_103 ;
for ( V_249 = F_11 ( V_204 ) ; V_249 ; V_249 = F_13 ( V_249 ) ) {
V_257 = F_12 ( V_249 , struct V_14 , V_104 ) ;
V_253 = F_146 ( V_256 , V_257 ) ;
if ( V_253 )
F_148 ( V_253 , V_257 ) ;
}
}
int F_149 ( struct V_1 * V_255 , struct V_1 * V_256 )
{
struct V_96 * V_204 ;
struct V_60 * V_249 ;
struct V_14 * V_257 , * V_253 ;
if ( V_101 )
V_204 = & V_256 -> V_102 ;
else
V_204 = V_256 -> V_103 ;
for ( V_249 = F_11 ( V_204 ) ; V_249 ; V_249 = F_13 ( V_249 ) ) {
V_257 = F_12 ( V_249 , struct V_14 , V_104 ) ;
if ( ! F_150 ( V_257 ) ) {
V_253 = F_145 ( V_255 , V_257 ) ;
if ( V_253 == NULL )
return - 1 ;
F_148 ( V_257 , V_253 ) ;
}
}
return 0 ;
}
void F_151 ( struct V_153 * V_258 , struct V_125 * V_126 ,
struct V_135 * V_136 , bool V_259 )
{
struct V_29 * V_133 ;
if ( V_258 && V_258 -> V_154 && V_258 -> V_62 [ 0 ] . V_157 . V_158 ) {
int V_155 ;
V_133 = F_53 ( V_136 , V_126 ) ;
if ( V_133 ) {
struct V_260 * V_261 = NULL ;
for ( V_155 = V_258 -> V_154 - 1 ; V_155 >= 0 ; V_155 -- ) {
F_152 ( & V_133 [ V_155 ] . V_30 ,
V_259 ? NULL : V_261 ,
V_133 [ V_155 ] . V_157 . V_158 ) ;
V_261 = & V_133 [ V_155 ] . V_33 ;
}
free ( V_133 ) ;
}
}
}
T_3 F_153 ( struct V_262 * V_263 , T_10 * V_264 )
{
struct V_149 * V_257 ;
T_3 V_209 = 0 ;
F_154 (evlist, pos) {
V_209 += fprintf ( V_264 , L_3 , F_155 ( V_257 ) ) ;
V_209 += F_156 ( & F_48 ( V_257 ) -> V_89 , V_264 ) ;
}
return V_209 ;
}
T_2 F_157 ( struct V_1 * V_1 )
{
return V_10 . V_226 ? V_1 -> V_89 . V_91 :
V_1 -> V_89 . V_90 ;
}
int F_158 ( const struct V_265 * T_11 V_143 ,
const char * V_166 , int T_12 V_143 )
{
if ( ! strcmp ( V_166 , L_4 ) )
V_10 . V_226 = true ;
else if ( ! strcmp ( V_166 , L_5 ) )
V_10 . V_226 = false ;
else
return - 1 ;
return 0 ;
}
int F_159 ( const char * V_266 , const char * V_267 )
{
if ( ! strcmp ( V_266 , L_6 ) )
return F_158 ( NULL , V_267 , 0 ) ;
return 0 ;
}
int F_160 ( struct V_1 * V_1 , struct V_205 * V_184 )
{
memset ( V_1 , 0 , sizeof( * V_1 ) ) ;
V_1 -> V_212 [ 0 ] = V_1 -> V_212 [ 1 ] = V_219 ;
V_1 -> V_103 = & V_1 -> V_212 [ 0 ] ;
V_1 -> V_102 = V_219 ;
V_1 -> V_62 = V_219 ;
F_161 ( & V_1 -> V_211 , NULL ) ;
V_1 -> V_248 = - 1 ;
V_1 -> V_184 = V_184 ;
F_32 ( & V_1 -> V_268 ) ;
return 0 ;
}
static void F_162 ( struct V_96 * V_204 )
{
struct V_60 * V_94 ;
struct V_14 * V_81 ;
while ( ! F_163 ( V_204 ) ) {
V_94 = F_11 ( V_204 ) ;
F_21 ( V_94 , V_204 ) ;
V_81 = F_12 ( V_94 , struct V_14 , V_104 ) ;
F_22 ( V_81 ) ;
}
}
static void F_164 ( struct V_1 * V_1 )
{
F_24 ( V_1 ) ;
F_162 ( & V_1 -> V_212 [ 0 ] ) ;
F_162 ( & V_1 -> V_212 [ 1 ] ) ;
F_162 ( & V_1 -> V_102 ) ;
}
static void F_165 ( struct V_149 * V_147 )
{
struct V_1 * V_1 = F_48 ( V_147 ) ;
struct V_177 * V_178 , * V_257 ;
struct V_207 * V_94 , * V_269 ;
F_164 ( V_1 ) ;
F_166 (node, tmp, &hists->hpp_formats, list) {
F_167 (&node->hpp, fmt, pos) {
F_168 ( & V_178 -> V_183 ) ;
free ( V_178 ) ;
}
F_168 ( & V_94 -> V_183 ) ;
free ( V_94 ) ;
}
}
static int F_169 ( struct V_149 * V_147 )
{
struct V_1 * V_1 = F_48 ( V_147 ) ;
F_160 ( V_1 , & V_205 ) ;
return 0 ;
}
int F_170 ( void )
{
int V_150 = F_171 ( sizeof( struct V_270 ) ,
F_169 ,
F_165 ) ;
if ( V_150 )
fputs ( L_7 , V_271 ) ;
return V_150 ;
}
void F_172 ( struct V_205 * V_183 )
{
F_32 ( & V_183 -> V_185 ) ;
F_32 ( & V_183 -> V_272 ) ;
}
