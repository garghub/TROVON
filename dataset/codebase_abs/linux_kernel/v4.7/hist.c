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
if ( V_15 -> V_29 -> V_36 )
F_3 ( V_1 , V_37 ,
strlen ( V_15 -> V_29 -> V_36 ) ) ;
if ( V_15 -> V_29 -> V_38 )
F_3 ( V_1 , V_39 ,
strlen ( V_15 -> V_29 -> V_38 ) ) ;
}
if ( V_15 -> V_40 ) {
if ( V_15 -> V_40 -> V_41 . V_18 ) {
V_16 = ( int ) V_15 -> V_40 -> V_41 . V_18 -> V_19 + 4
+ V_8 + 2 ;
F_3 ( V_1 , V_42 ,
V_16 ) ;
F_3 ( V_1 , V_43 ,
V_16 + 1 ) ;
} else {
V_16 = V_8 + 4 + 2 ;
F_3 ( V_1 , V_42 ,
V_16 ) ;
F_3 ( V_1 , V_43 ,
V_16 ) ;
}
if ( V_15 -> V_40 -> V_44 . V_18 ) {
V_16 = ( int ) V_15 -> V_40 -> V_44 . V_18 -> V_19 + 4
+ V_8 + 2 ;
F_3 ( V_1 , V_45 ,
V_16 ) ;
} else {
V_16 = V_8 + 4 + 2 ;
F_3 ( V_1 , V_45 ,
V_16 ) ;
}
if ( V_15 -> V_40 -> V_41 . V_26 ) {
V_16 = F_8 ( V_15 -> V_40 -> V_41 . V_26 -> V_7 ) ;
F_3 ( V_1 , V_46 ,
V_16 ) ;
} else {
V_16 = V_8 + 4 + 2 ;
F_5 ( V_1 , V_46 ) ;
}
} else {
V_16 = V_8 + 4 + 2 ;
F_3 ( V_1 , V_42 , V_16 ) ;
F_3 ( V_1 , V_45 , V_16 ) ;
F_5 ( V_1 , V_46 ) ;
}
F_3 ( V_1 , V_47 , 3 ) ;
F_3 ( V_1 , V_48 , 6 ) ;
F_3 ( V_1 , V_49 , 6 ) ;
F_3 ( V_1 , V_50 , 22 ) ;
F_3 ( V_1 , V_51 , 12 ) ;
F_3 ( V_1 , V_52 , 21 + 3 ) ;
F_3 ( V_1 , V_53 , 12 ) ;
F_3 ( V_1 , V_54 , 12 ) ;
if ( V_15 -> V_55 )
F_3 ( V_1 , V_56 , strlen ( V_15 -> V_55 ) ) ;
if ( V_15 -> V_57 )
F_3 ( V_1 , V_58 , strlen ( V_15 -> V_57 ) ) ;
if ( V_15 -> V_59 )
F_3 ( V_1 , V_60 ,
F_9 () ) ;
if ( V_15 -> V_61 )
F_3 ( V_1 , V_62 , strlen ( V_15 -> V_61 ) ) ;
}
void F_10 ( struct V_1 * V_1 , int V_63 )
{
struct V_64 * V_65 = F_11 ( & V_1 -> V_66 ) ;
struct V_14 * V_67 ;
int V_68 = 0 ;
F_4 ( V_1 ) ;
while ( V_65 && V_68 ++ < V_63 ) {
V_67 = F_12 ( V_65 , struct V_14 , V_64 ) ;
if ( ! V_67 -> V_69 )
F_6 ( V_1 , V_67 ) ;
V_65 = F_13 ( & V_67 -> V_64 ) ;
}
}
static void F_14 ( struct V_70 * V_70 ,
unsigned int V_71 , T_2 V_72 )
{
switch ( V_71 ) {
case V_73 :
V_70 -> V_74 += V_72 ;
break;
case V_75 :
V_70 -> V_76 += V_72 ;
break;
case V_77 :
V_70 -> V_78 += V_72 ;
break;
case V_79 :
V_70 -> V_80 += V_72 ;
break;
default:
break;
}
}
static void F_15 ( struct V_70 * V_70 , T_2 V_72 ,
T_2 V_81 )
{
V_70 -> V_72 += V_72 ;
V_70 -> V_81 += V_81 ;
V_70 -> V_82 += 1 ;
}
static void F_16 ( struct V_70 * V_83 , struct V_70 * V_84 )
{
V_83 -> V_72 += V_84 -> V_72 ;
V_83 -> V_74 += V_84 -> V_74 ;
V_83 -> V_76 += V_84 -> V_76 ;
V_83 -> V_78 += V_84 -> V_78 ;
V_83 -> V_80 += V_84 -> V_80 ;
V_83 -> V_82 += V_84 -> V_82 ;
V_83 -> V_81 += V_84 -> V_81 ;
}
static void F_17 ( struct V_70 * V_70 )
{
V_70 -> V_72 = ( V_70 -> V_72 * 7 ) / 8 ;
V_70 -> V_82 = ( V_70 -> V_82 * 7 ) / 8 ;
}
static bool F_18 ( struct V_1 * V_1 , struct V_14 * V_85 )
{
T_2 V_86 = V_85 -> V_87 . V_72 ;
T_2 V_88 ;
if ( V_86 == 0 )
return true ;
F_17 ( & V_85 -> V_87 ) ;
if ( V_10 . V_89 )
F_17 ( V_85 -> V_90 ) ;
F_19 ( V_85 -> V_91 ) ;
V_88 = V_86 - V_85 -> V_87 . V_72 ;
if ( ! V_85 -> V_92 ) {
V_1 -> V_93 . V_94 -= V_88 ;
if ( ! V_85 -> V_69 )
V_1 -> V_93 . V_95 -= V_88 ;
}
if ( ! V_85 -> V_96 ) {
struct V_14 * V_97 ;
struct V_64 * V_98 = F_11 ( & V_85 -> V_99 ) ;
while ( V_98 ) {
V_97 = F_12 ( V_98 , struct V_14 , V_64 ) ;
V_98 = F_13 ( V_98 ) ;
if ( F_18 ( V_1 , V_97 ) )
F_20 ( V_1 , V_97 ) ;
}
}
return V_85 -> V_87 . V_72 == 0 ;
}
static void F_20 ( struct V_1 * V_1 , struct V_14 * V_85 )
{
struct V_100 * V_101 ;
struct V_100 * V_102 ;
if ( V_85 -> V_103 ) {
V_101 = & V_85 -> V_103 -> V_104 ;
V_102 = & V_85 -> V_103 -> V_99 ;
} else {
if ( F_21 ( V_1 , V_105 ) )
V_101 = & V_1 -> V_106 ;
else
V_101 = V_1 -> V_107 ;
V_102 = & V_1 -> V_66 ;
}
F_22 ( & V_85 -> V_108 , V_101 ) ;
F_22 ( & V_85 -> V_64 , V_102 ) ;
-- V_1 -> V_109 ;
if ( ! V_85 -> V_69 )
-- V_1 -> V_110 ;
F_23 ( V_85 ) ;
}
void F_24 ( struct V_1 * V_1 , bool V_111 , bool V_112 )
{
struct V_64 * V_65 = F_11 ( & V_1 -> V_66 ) ;
struct V_14 * V_67 ;
while ( V_65 ) {
V_67 = F_12 ( V_65 , struct V_14 , V_64 ) ;
V_65 = F_13 ( & V_67 -> V_64 ) ;
if ( ( ( V_111 && V_67 -> V_113 == '.' ) ||
( V_112 && V_67 -> V_113 != '.' ) ||
F_18 ( V_1 , V_67 ) ) ) {
F_20 ( V_1 , V_67 ) ;
}
}
}
void F_25 ( struct V_1 * V_1 )
{
struct V_64 * V_65 = F_11 ( & V_1 -> V_66 ) ;
struct V_14 * V_67 ;
while ( V_65 ) {
V_67 = F_12 ( V_65 , struct V_14 , V_64 ) ;
V_65 = F_13 ( & V_67 -> V_64 ) ;
F_20 ( V_1 , V_67 ) ;
}
}
static struct V_14 * F_26 ( struct V_14 * V_114 ,
bool V_115 )
{
T_3 V_116 = 0 ;
struct V_14 * V_85 ;
if ( V_10 . V_117 )
V_116 = sizeof( struct V_118 ) ;
V_85 = F_27 ( sizeof( * V_85 ) + V_116 ) ;
if ( V_85 != NULL ) {
* V_85 = * V_114 ;
if ( V_10 . V_89 ) {
V_85 -> V_90 = malloc ( sizeof( V_85 -> V_87 ) ) ;
if ( V_85 -> V_90 == NULL ) {
free ( V_85 ) ;
return NULL ;
}
memcpy ( V_85 -> V_90 , & V_85 -> V_87 , sizeof( V_85 -> V_87 ) ) ;
if ( ! V_115 )
memset ( & V_85 -> V_87 , 0 , sizeof( V_85 -> V_87 ) ) ;
}
F_28 ( V_85 -> V_17 . V_26 ) ;
if ( V_85 -> V_29 ) {
V_85 -> V_29 = malloc ( sizeof( * V_85 -> V_29 ) ) ;
if ( V_85 -> V_29 == NULL ) {
F_29 ( V_85 -> V_17 . V_26 ) ;
free ( V_85 -> V_90 ) ;
free ( V_85 ) ;
return NULL ;
}
memcpy ( V_85 -> V_29 , V_114 -> V_29 ,
sizeof( * V_85 -> V_29 ) ) ;
F_28 ( V_85 -> V_29 -> V_30 . V_26 ) ;
F_28 ( V_85 -> V_29 -> V_33 . V_26 ) ;
}
if ( V_85 -> V_40 ) {
F_28 ( V_85 -> V_40 -> V_44 . V_26 ) ;
F_28 ( V_85 -> V_40 -> V_41 . V_26 ) ;
}
if ( V_10 . V_117 )
F_30 ( V_85 -> V_91 ) ;
if ( V_85 -> V_119 ) {
V_85 -> V_119 = F_31 ( V_85 -> V_119 , V_85 -> V_120 ) ;
if ( V_85 -> V_119 == NULL ) {
F_32 ( V_85 -> V_17 . V_26 ) ;
if ( V_85 -> V_29 ) {
F_32 ( V_85 -> V_29 -> V_30 . V_26 ) ;
F_32 ( V_85 -> V_29 -> V_33 . V_26 ) ;
free ( V_85 -> V_29 ) ;
}
if ( V_85 -> V_40 ) {
F_32 ( V_85 -> V_40 -> V_44 . V_26 ) ;
F_32 ( V_85 -> V_40 -> V_41 . V_26 ) ;
}
free ( V_85 -> V_90 ) ;
free ( V_85 ) ;
return NULL ;
}
}
F_33 ( & V_85 -> V_121 . V_98 ) ;
F_34 ( V_85 -> V_23 ) ;
if ( ! V_10 . V_122 )
V_85 -> V_96 = true ;
}
return V_85 ;
}
static T_4 F_35 ( const struct V_123 * V_27 )
{
if ( V_10 . V_124 && V_27 == NULL )
return 1 << V_125 ;
return 0 ;
}
static void F_36 ( struct V_14 * V_85 , T_2 V_72 )
{
if ( ! V_10 . V_117 )
return;
V_85 -> V_1 -> V_126 += V_72 ;
if ( ! V_85 -> V_69 )
V_85 -> V_1 -> V_127 += V_72 ;
}
static struct V_14 * F_37 ( struct V_1 * V_1 ,
struct V_14 * V_128 ,
struct V_129 * V_130 ,
bool V_115 )
{
struct V_64 * * V_131 ;
struct V_64 * V_27 = NULL ;
struct V_14 * V_85 ;
T_5 V_132 ;
T_2 V_72 = V_128 -> V_87 . V_72 ;
T_2 V_81 = V_128 -> V_87 . V_81 ;
V_131 = & V_1 -> V_107 -> V_64 ;
while ( * V_131 != NULL ) {
V_27 = * V_131 ;
V_85 = F_12 ( V_27 , struct V_14 , V_108 ) ;
V_132 = F_38 ( V_85 , V_128 ) ;
if ( ! V_132 ) {
if ( V_115 ) {
F_15 ( & V_85 -> V_87 , V_72 , V_81 ) ;
F_36 ( V_85 , V_72 ) ;
}
if ( V_10 . V_89 )
F_15 ( V_85 -> V_90 , V_72 , V_81 ) ;
F_39 ( & V_128 -> V_40 ) ;
if ( V_85 -> V_17 . V_26 != V_128 -> V_17 . V_26 ) {
F_32 ( V_85 -> V_17 . V_26 ) ;
V_85 -> V_17 . V_26 = F_28 ( V_128 -> V_17 . V_26 ) ;
}
goto V_133;
}
if ( V_132 < 0 )
V_131 = & ( * V_131 ) -> V_134 ;
else
V_131 = & ( * V_131 ) -> V_135 ;
}
V_85 = F_26 ( V_128 , V_115 ) ;
if ( ! V_85 )
return NULL ;
if ( V_115 )
F_36 ( V_85 , V_72 ) ;
V_1 -> V_109 ++ ;
F_40 ( & V_85 -> V_108 , V_27 , V_131 ) ;
F_41 ( & V_85 -> V_108 , V_1 -> V_107 ) ;
V_133:
if ( V_115 )
F_14 ( & V_85 -> V_87 , V_130 -> V_71 , V_72 ) ;
if ( V_10 . V_89 )
F_14 ( V_85 -> V_90 , V_130 -> V_71 , V_72 ) ;
return V_85 ;
}
struct V_14 * F_42 ( struct V_1 * V_1 ,
struct V_129 * V_130 ,
struct V_123 * V_136 ,
struct V_29 * V_137 ,
struct V_40 * V_138 ,
struct V_139 * V_140 ,
bool V_115 )
{
struct V_14 V_128 = {
. V_23 = V_130 -> V_23 ,
. V_141 = F_43 ( V_130 -> V_23 ) ,
. V_17 = {
. V_26 = V_130 -> V_26 ,
. V_18 = V_130 -> V_18 ,
} ,
. V_142 = V_130 -> V_142 ,
. V_143 = V_130 -> V_143 ,
. V_71 = V_130 -> V_71 ,
. V_144 = V_130 -> V_145 ,
. V_113 = V_130 -> V_113 ,
. V_87 = {
. V_82 = 1 ,
. V_72 = V_140 -> V_72 ,
. V_81 = V_140 -> V_81 ,
} ,
. V_27 = V_136 ,
. V_69 = F_35 ( V_136 ) | V_130 -> V_69 ,
. V_1 = V_1 ,
. V_29 = V_137 ,
. V_40 = V_138 ,
. V_59 = V_140 -> V_59 ,
. V_119 = V_140 -> V_119 ,
. V_120 = V_140 -> V_120 ,
} ;
return F_37 ( V_1 , & V_128 , V_130 , V_115 ) ;
}
static int
F_44 ( struct V_146 * T_6 V_147 ,
struct V_129 * V_130 V_147 )
{
return 0 ;
}
static int
F_45 ( struct V_146 * T_6 V_147 ,
struct V_129 * V_130 V_147 )
{
return 0 ;
}
static int
F_46 ( struct V_146 * T_6 , struct V_129 * V_130 )
{
struct V_139 * V_140 = T_6 -> V_140 ;
struct V_40 * V_138 ;
V_138 = F_47 ( V_140 , V_130 ) ;
if ( V_138 == NULL )
return - V_148 ;
T_6 -> V_149 = V_138 ;
return 0 ;
}
static int
F_48 ( struct V_146 * T_6 , struct V_129 * V_130 )
{
T_2 V_150 ;
struct V_40 * V_138 = T_6 -> V_149 ;
struct V_1 * V_1 = F_49 ( T_6 -> V_151 ) ;
struct V_139 * V_140 = T_6 -> V_140 ;
struct V_14 * V_85 ;
if ( V_138 == NULL )
return - V_152 ;
V_150 = V_140 -> V_81 ;
if ( ! V_150 )
V_150 = 1 ;
V_140 -> V_72 = V_150 ;
V_85 = F_42 ( V_1 , V_130 , T_6 -> V_27 , NULL , V_138 ,
V_140 , true ) ;
if ( ! V_85 )
return - V_148 ;
T_6 -> V_85 = V_85 ;
return 0 ;
}
static int
F_50 ( struct V_146 * T_6 ,
struct V_129 * V_130 V_147 )
{
struct V_153 * V_151 = T_6 -> V_151 ;
struct V_1 * V_1 = F_49 ( V_151 ) ;
struct V_14 * V_85 = T_6 -> V_85 ;
int V_154 = - V_152 ;
if ( V_85 == NULL )
goto V_133;
F_51 ( V_1 , V_85 -> V_69 ) ;
V_154 = F_52 ( V_85 , T_6 -> V_140 ) ;
V_133:
T_6 -> V_149 = NULL ;
T_6 -> V_85 = NULL ;
return V_154 ;
}
static int
F_53 ( struct V_146 * T_6 , struct V_129 * V_130 )
{
struct V_29 * V_137 ;
struct V_139 * V_140 = T_6 -> V_140 ;
V_137 = F_54 ( V_140 , V_130 ) ;
if ( ! V_137 )
return - V_148 ;
T_6 -> V_155 = 0 ;
T_6 -> V_156 = V_140 -> V_157 -> V_158 ;
T_6 -> V_149 = V_137 ;
return 0 ;
}
static int
F_55 ( struct V_146 * T_6 ,
struct V_129 * V_130 V_147 )
{
T_6 -> V_85 = NULL ;
return 0 ;
}
static int
F_56 ( struct V_146 * T_6 , struct V_129 * V_130 )
{
struct V_29 * V_137 = T_6 -> V_149 ;
int V_159 = T_6 -> V_155 ;
if ( V_137 == NULL )
return 0 ;
if ( T_6 -> V_155 >= T_6 -> V_156 )
return 0 ;
V_130 -> V_26 = V_137 [ V_159 ] . V_33 . V_26 ;
V_130 -> V_18 = V_137 [ V_159 ] . V_33 . V_18 ;
V_130 -> V_145 = V_137 [ V_159 ] . V_33 . V_145 ;
return 1 ;
}
static int
F_57 ( struct V_146 * T_6 , struct V_129 * V_130 )
{
struct V_29 * V_137 ;
struct V_153 * V_151 = T_6 -> V_151 ;
struct V_1 * V_1 = F_49 ( V_151 ) ;
struct V_139 * V_140 = T_6 -> V_140 ;
struct V_14 * V_85 = NULL ;
int V_159 = T_6 -> V_155 ;
int V_154 = 0 ;
V_137 = T_6 -> V_149 ;
if ( T_6 -> V_160 && ! ( V_137 [ V_159 ] . V_30 . V_18 && V_137 [ V_159 ] . V_33 . V_18 ) )
goto V_133;
V_140 -> V_72 = 1 ;
V_140 -> V_81 = V_137 -> V_161 . V_162 ? V_137 -> V_161 . V_162 : 1 ;
V_85 = F_42 ( V_1 , V_130 , T_6 -> V_27 , & V_137 [ V_159 ] , NULL ,
V_140 , true ) ;
if ( V_85 == NULL )
return - V_148 ;
F_51 ( V_1 , V_85 -> V_69 ) ;
V_133:
T_6 -> V_85 = V_85 ;
T_6 -> V_155 ++ ;
return V_154 ;
}
static int
F_58 ( struct V_146 * T_6 ,
struct V_129 * V_130 V_147 )
{
F_39 ( & T_6 -> V_149 ) ;
T_6 -> V_85 = NULL ;
return T_6 -> V_155 >= T_6 -> V_156 ? 0 : - 1 ;
}
static int
F_59 ( struct V_146 * T_6 V_147 ,
struct V_129 * V_130 V_147 )
{
return 0 ;
}
static int
F_60 ( struct V_146 * T_6 , struct V_129 * V_130 )
{
struct V_153 * V_151 = T_6 -> V_151 ;
struct V_139 * V_140 = T_6 -> V_140 ;
struct V_14 * V_85 ;
V_85 = F_42 ( F_49 ( V_151 ) , V_130 , T_6 -> V_27 , NULL , NULL ,
V_140 , true ) ;
if ( V_85 == NULL )
return - V_148 ;
T_6 -> V_85 = V_85 ;
return 0 ;
}
static int
F_61 ( struct V_146 * T_6 ,
struct V_129 * V_130 V_147 )
{
struct V_14 * V_85 = T_6 -> V_85 ;
struct V_153 * V_151 = T_6 -> V_151 ;
struct V_139 * V_140 = T_6 -> V_140 ;
if ( V_85 == NULL )
return 0 ;
T_6 -> V_85 = NULL ;
F_51 ( F_49 ( V_151 ) , V_85 -> V_69 ) ;
return F_52 ( V_85 , V_140 ) ;
}
static int
F_62 ( struct V_146 * T_6 ,
struct V_129 * V_130 V_147 )
{
struct V_14 * * V_163 ;
F_63 ( & V_164 ) ;
V_163 = malloc ( sizeof( * V_163 ) * ( T_6 -> V_165 + 1 ) ) ;
if ( V_163 == NULL )
return - V_148 ;
T_6 -> V_149 = V_163 ;
T_6 -> V_155 = 0 ;
return 0 ;
}
static int
F_64 ( struct V_146 * T_6 ,
struct V_129 * V_130 )
{
struct V_153 * V_151 = T_6 -> V_151 ;
struct V_1 * V_1 = F_49 ( V_151 ) ;
struct V_139 * V_140 = T_6 -> V_140 ;
struct V_14 * * V_163 = T_6 -> V_149 ;
struct V_14 * V_85 ;
int V_154 = 0 ;
V_85 = F_42 ( V_1 , V_130 , T_6 -> V_27 , NULL , NULL ,
V_140 , true ) ;
if ( V_85 == NULL )
return - V_148 ;
T_6 -> V_85 = V_85 ;
V_163 [ T_6 -> V_155 ++ ] = V_85 ;
F_52 ( V_85 , V_140 ) ;
F_63 ( & V_164 ) ;
F_51 ( V_1 , V_85 -> V_69 ) ;
return V_154 ;
}
static int
F_65 ( struct V_146 * T_6 ,
struct V_129 * V_130 )
{
struct V_166 * V_98 ;
V_98 = F_66 ( & V_164 ) ;
if ( V_98 == NULL )
return 0 ;
return F_67 ( V_130 , V_98 , T_6 -> V_160 ) ;
}
static int
F_68 ( struct V_146 * T_6 ,
struct V_129 * V_130 )
{
struct V_153 * V_151 = T_6 -> V_151 ;
struct V_139 * V_140 = T_6 -> V_140 ;
struct V_14 * * V_163 = T_6 -> V_149 ;
struct V_14 * V_85 ;
struct V_14 V_167 = {
. V_1 = F_49 ( V_151 ) ,
. V_143 = V_130 -> V_143 ,
. V_23 = V_130 -> V_23 ,
. V_141 = F_43 ( V_130 -> V_23 ) ,
. V_144 = V_130 -> V_145 ,
. V_17 = {
. V_26 = V_130 -> V_26 ,
. V_18 = V_130 -> V_18 ,
} ,
. V_27 = T_6 -> V_27 ,
. V_119 = V_140 -> V_119 ,
. V_120 = V_140 -> V_120 ,
} ;
int V_159 ;
struct V_164 V_168 ;
F_69 ( & V_168 , & V_164 ) ;
F_70 ( & V_164 ) ;
for ( V_159 = 0 ; V_159 < T_6 -> V_155 ; V_159 ++ ) {
if ( F_38 ( V_163 [ V_159 ] , & V_167 ) == 0 ) {
T_6 -> V_85 = NULL ;
return 0 ;
}
}
V_85 = F_42 ( F_49 ( V_151 ) , V_130 , T_6 -> V_27 , NULL , NULL ,
V_140 , false ) ;
if ( V_85 == NULL )
return - V_148 ;
T_6 -> V_85 = V_85 ;
V_163 [ T_6 -> V_155 ++ ] = V_85 ;
if ( V_10 . V_117 )
F_71 ( V_85 -> V_91 , & V_168 , V_140 -> V_72 ) ;
return 0 ;
}
static int
F_72 ( struct V_146 * T_6 ,
struct V_129 * V_130 V_147 )
{
F_39 ( & T_6 -> V_149 ) ;
T_6 -> V_85 = NULL ;
return 0 ;
}
int F_73 ( struct V_146 * T_6 , struct V_129 * V_130 ,
int V_169 , void * V_170 )
{
int V_154 , V_171 ;
V_154 = F_74 ( T_6 -> V_140 , & V_164 , & T_6 -> V_27 ,
T_6 -> V_151 , V_130 , V_169 ) ;
if ( V_154 )
return V_154 ;
T_6 -> V_165 = V_169 ;
V_154 = T_6 -> V_172 -> V_173 ( T_6 , V_130 ) ;
if ( V_154 )
goto V_133;
V_154 = T_6 -> V_172 -> V_174 ( T_6 , V_130 ) ;
if ( V_154 )
goto V_133;
if ( T_6 -> V_85 && T_6 -> V_175 ) {
V_154 = T_6 -> V_175 ( T_6 , V_130 , true , V_170 ) ;
if ( V_154 )
goto V_133;
}
while ( T_6 -> V_172 -> V_176 ( T_6 , V_130 ) ) {
V_154 = T_6 -> V_172 -> V_177 ( T_6 , V_130 ) ;
if ( V_154 )
break;
if ( T_6 -> V_85 && T_6 -> V_175 ) {
V_154 = T_6 -> V_175 ( T_6 , V_130 , false , V_170 ) ;
if ( V_154 )
goto V_133;
}
}
V_133:
V_171 = T_6 -> V_172 -> V_178 ( T_6 , V_130 ) ;
if ( ! V_154 )
V_154 = V_171 ;
return V_154 ;
}
T_5
F_38 ( struct V_14 * V_179 , struct V_14 * V_180 )
{
struct V_1 * V_1 = V_179 -> V_1 ;
struct V_181 * V_182 ;
T_5 V_132 = 0 ;
F_75 (hists, fmt) {
if ( F_76 ( V_182 ) &&
! F_77 ( V_182 , V_1 ) )
continue;
V_132 = V_182 -> V_132 ( V_182 , V_179 , V_180 ) ;
if ( V_132 )
break;
}
return V_132 ;
}
T_5
F_78 ( struct V_14 * V_179 , struct V_14 * V_180 )
{
struct V_1 * V_1 = V_179 -> V_1 ;
struct V_181 * V_182 ;
T_5 V_132 = 0 ;
F_75 (hists, fmt) {
if ( F_76 ( V_182 ) &&
! F_77 ( V_182 , V_1 ) )
continue;
V_132 = V_182 -> V_183 ( V_182 , V_179 , V_180 ) ;
if ( V_132 )
break;
}
return V_132 ;
}
void F_23 ( struct V_14 * V_85 )
{
F_79 ( V_85 -> V_23 ) ;
F_29 ( V_85 -> V_17 . V_26 ) ;
if ( V_85 -> V_29 ) {
F_29 ( V_85 -> V_29 -> V_30 . V_26 ) ;
F_29 ( V_85 -> V_29 -> V_33 . V_26 ) ;
F_80 ( V_85 -> V_29 -> V_36 ) ;
F_80 ( V_85 -> V_29 -> V_38 ) ;
F_39 ( & V_85 -> V_29 ) ;
}
if ( V_85 -> V_40 ) {
F_29 ( V_85 -> V_40 -> V_44 . V_26 ) ;
F_29 ( V_85 -> V_40 -> V_41 . V_26 ) ;
F_39 ( & V_85 -> V_40 ) ;
}
F_39 ( & V_85 -> V_90 ) ;
F_80 ( V_85 -> V_55 ) ;
if ( V_85 -> V_57 && V_85 -> V_57 [ 0 ] )
free ( V_85 -> V_57 ) ;
F_81 ( V_85 -> V_91 ) ;
free ( V_85 -> V_61 ) ;
free ( V_85 -> V_119 ) ;
free ( V_85 ) ;
}
int F_82 ( struct V_14 * V_85 , struct V_184 * V_185 ,
struct V_181 * V_182 , int V_186 )
{
if ( ! F_83 ( & V_182 -> V_187 , & V_85 -> V_1 -> V_188 -> V_189 ) ) {
const int V_190 = V_182 -> V_190 ( V_182 , V_185 , F_84 ( V_85 -> V_1 ) ) ;
if ( V_186 < V_190 ) {
F_85 ( V_185 , V_186 ) ;
V_186 = F_86 ( V_185 -> V_191 , V_185 -> V_192 , L_1 , V_190 - V_186 , L_2 ) ;
}
}
return V_186 ;
}
static bool F_87 ( struct V_181 * V_182 )
{
return F_88 ( V_182 ) || F_89 ( V_182 ) ;
}
static void F_90 ( struct V_14 * V_85 ,
enum V_193 type ,
T_7 V_194 )
{
struct V_181 * V_182 ;
bool V_195 = false ;
struct V_14 * V_27 = V_85 -> V_103 ;
switch ( type ) {
case V_196 :
if ( V_10 . V_197 == NULL &&
V_10 . V_198 == NULL &&
V_10 . V_199 == NULL )
return;
break;
case V_200 :
if ( V_10 . V_13 == NULL )
return;
break;
case V_201 :
if ( V_10 . V_202 == NULL )
return;
break;
case V_125 :
case V_203 :
case V_204 :
case V_205 :
default:
return;
}
F_91 (he->hpp_list, fmt) {
if ( V_194 ( V_182 ) ) {
V_195 = true ;
break;
}
}
if ( V_195 ) {
if ( ! ( V_85 -> V_69 & ( 1 << type ) ) ) {
while ( V_27 ) {
V_27 -> V_69 &= ~ ( 1 << type ) ;
V_27 = V_27 -> V_103 ;
}
}
} else {
if ( V_27 == NULL )
V_85 -> V_69 |= ( 1 << type ) ;
else
V_85 -> V_69 |= ( V_27 -> V_69 & ( 1 << type ) ) ;
}
}
static void F_92 ( struct V_14 * V_85 )
{
F_90 ( V_85 , V_196 ,
F_87 ) ;
F_90 ( V_85 , V_200 ,
V_206 ) ;
F_90 ( V_85 , V_201 ,
V_207 ) ;
F_93 ( V_85 -> V_1 , V_85 ) ;
}
static struct V_14 * F_94 ( struct V_1 * V_1 ,
struct V_100 * V_208 ,
struct V_14 * V_85 ,
struct V_14 * V_103 ,
struct V_209 * V_188 )
{
struct V_64 * * V_131 = & V_208 -> V_64 ;
struct V_64 * V_27 = NULL ;
struct V_14 * T_6 , * V_210 ;
struct V_181 * V_182 ;
T_5 V_132 ;
while ( * V_131 != NULL ) {
V_27 = * V_131 ;
T_6 = F_12 ( V_27 , struct V_14 , V_108 ) ;
V_132 = 0 ;
F_95 (hpp_list, fmt) {
V_132 = V_182 -> V_183 ( V_182 , T_6 , V_85 ) ;
if ( V_132 )
break;
}
if ( ! V_132 ) {
F_16 ( & T_6 -> V_87 , & V_85 -> V_87 ) ;
return T_6 ;
}
if ( V_132 < 0 )
V_131 = & V_27 -> V_134 ;
else
V_131 = & V_27 -> V_135 ;
}
V_210 = F_26 ( V_85 , true ) ;
if ( V_210 == NULL )
return NULL ;
V_1 -> V_109 ++ ;
V_210 -> V_188 = V_188 ;
V_210 -> V_103 = V_103 ;
F_92 ( V_210 ) ;
F_95 (hpp_list, fmt) {
if ( F_96 ( V_182 ) || F_76 ( V_182 ) )
V_85 -> V_61 = NULL ;
else
V_210 -> V_61 = NULL ;
if ( F_97 ( V_182 ) )
V_85 -> V_55 = NULL ;
else
V_210 -> V_55 = NULL ;
if ( F_98 ( V_182 ) )
V_85 -> V_57 = NULL ;
else
V_210 -> V_57 = NULL ;
}
F_40 ( & V_210 -> V_108 , V_27 , V_131 ) ;
F_41 ( & V_210 -> V_108 , V_208 ) ;
return V_210 ;
}
static int F_99 ( struct V_1 * V_1 ,
struct V_100 * V_208 ,
struct V_14 * V_85 )
{
struct V_211 * V_98 ;
struct V_14 * V_212 = NULL ;
struct V_14 * V_27 = NULL ;
int V_92 = 0 ;
int V_213 = 0 ;
F_100 (node, &hists->hpp_formats, list) {
if ( V_98 -> V_113 == 0 || V_98 -> V_214 )
continue;
V_212 = F_94 ( V_1 , V_208 , V_85 , V_27 , & V_98 -> V_185 ) ;
if ( V_212 == NULL ) {
V_213 = - 1 ;
break;
}
V_208 = & V_212 -> V_104 ;
V_212 -> V_92 = V_92 ++ ;
V_27 = V_212 ;
}
if ( V_212 ) {
V_212 -> V_96 = true ;
if ( V_10 . V_117 ) {
F_101 ( & V_164 ) ;
if ( F_102 ( & V_164 ,
V_212 -> V_91 ,
V_85 -> V_91 ) < 0 )
V_213 = - 1 ;
}
}
F_23 ( V_85 ) ;
return V_213 ;
}
static int F_103 ( struct V_1 * V_1 ,
struct V_100 * V_208 ,
struct V_14 * V_85 )
{
struct V_64 * * V_131 = & V_208 -> V_64 ;
struct V_64 * V_27 = NULL ;
struct V_14 * T_6 ;
T_5 V_132 ;
if ( V_10 . V_122 )
return F_99 ( V_1 , V_208 , V_85 ) ;
while ( * V_131 != NULL ) {
V_27 = * V_131 ;
T_6 = F_12 ( V_27 , struct V_14 , V_108 ) ;
V_132 = F_78 ( T_6 , V_85 ) ;
if ( ! V_132 ) {
int V_213 = 0 ;
F_16 ( & T_6 -> V_87 , & V_85 -> V_87 ) ;
if ( V_10 . V_89 )
F_16 ( T_6 -> V_90 , V_85 -> V_90 ) ;
if ( V_10 . V_117 ) {
F_101 ( & V_164 ) ;
if ( F_102 ( & V_164 ,
T_6 -> V_91 ,
V_85 -> V_91 ) < 0 )
V_213 = - 1 ;
}
F_23 ( V_85 ) ;
return V_213 ;
}
if ( V_132 < 0 )
V_131 = & ( * V_131 ) -> V_134 ;
else
V_131 = & ( * V_131 ) -> V_135 ;
}
V_1 -> V_109 ++ ;
F_40 ( & V_85 -> V_108 , V_27 , V_131 ) ;
F_41 ( & V_85 -> V_108 , V_208 ) ;
return 1 ;
}
struct V_100 * F_104 ( struct V_1 * V_1 )
{
struct V_100 * V_208 ;
F_105 ( & V_1 -> V_215 ) ;
V_208 = V_1 -> V_107 ;
if ( ++ V_1 -> V_107 > & V_1 -> V_216 [ 1 ] )
V_1 -> V_107 = & V_1 -> V_216 [ 0 ] ;
F_106 ( & V_1 -> V_215 ) ;
return V_208 ;
}
static void F_93 ( struct V_1 * V_1 , struct V_14 * V_85 )
{
F_107 ( V_1 , V_85 ) ;
F_108 ( V_1 , V_85 ) ;
F_109 ( V_1 , V_85 ) ;
F_110 ( V_1 , V_85 ) ;
}
int F_111 ( struct V_1 * V_1 , struct V_217 * V_218 )
{
struct V_100 * V_208 ;
struct V_64 * V_65 ;
struct V_14 * V_67 ;
int V_213 ;
if ( ! F_21 ( V_1 , V_105 ) )
return 0 ;
V_1 -> V_109 = 0 ;
V_208 = F_104 ( V_1 ) ;
V_65 = F_11 ( V_208 ) ;
while ( V_65 ) {
if ( F_112 () )
break;
V_67 = F_12 ( V_65 , struct V_14 , V_108 ) ;
V_65 = F_13 ( & V_67 -> V_108 ) ;
F_22 ( & V_67 -> V_108 , V_208 ) ;
V_213 = F_103 ( V_1 , & V_1 -> V_106 , V_67 ) ;
if ( V_213 < 0 )
return - 1 ;
if ( V_213 ) {
F_93 ( V_1 , V_67 ) ;
}
if ( V_218 )
F_113 ( V_218 , 1 ) ;
}
return 0 ;
}
static int F_114 ( struct V_14 * V_219 , struct V_14 * V_220 )
{
struct V_1 * V_1 = V_219 -> V_1 ;
struct V_181 * V_182 ;
T_5 V_132 = 0 ;
F_75 (hists, fmt) {
if ( F_115 ( V_182 , V_219 -> V_1 ) )
continue;
V_132 = V_182 -> V_221 ( V_182 , V_219 , V_220 ) ;
if ( V_132 )
break;
}
return V_132 ;
}
static void F_116 ( struct V_1 * V_1 )
{
V_1 -> V_110 = 0 ;
V_1 -> V_93 . V_95 = 0 ;
}
void F_117 ( struct V_1 * V_1 )
{
V_1 -> V_109 = 0 ;
V_1 -> V_93 . V_94 = 0 ;
F_116 ( V_1 ) ;
}
static void F_118 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
V_1 -> V_110 ++ ;
V_1 -> V_93 . V_95 += V_15 -> V_87 . V_72 ;
}
void F_119 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
if ( ! V_15 -> V_69 )
F_118 ( V_1 , V_15 ) ;
V_1 -> V_109 ++ ;
V_1 -> V_93 . V_94 += V_15 -> V_87 . V_72 ;
}
static void F_120 ( struct V_1 * V_1 )
{
struct V_64 * V_98 ;
struct V_14 * V_85 ;
V_98 = F_11 ( & V_1 -> V_66 ) ;
V_1 -> V_93 . V_94 = 0 ;
V_1 -> V_93 . V_95 = 0 ;
while ( V_98 ) {
V_85 = F_12 ( V_98 , struct V_14 , V_64 ) ;
V_98 = F_13 ( V_98 ) ;
V_1 -> V_93 . V_94 += V_85 -> V_87 . V_72 ;
if ( ! V_85 -> V_69 )
V_1 -> V_93 . V_95 += V_85 -> V_87 . V_72 ;
}
}
static void F_121 ( struct V_100 * V_208 ,
struct V_14 * V_85 )
{
struct V_64 * * V_131 = & V_208 -> V_64 ;
struct V_64 * V_27 = NULL ;
struct V_14 * T_6 ;
struct V_181 * V_182 ;
while ( * V_131 != NULL ) {
V_27 = * V_131 ;
T_6 = F_12 ( V_27 , struct V_14 , V_64 ) ;
if ( F_114 ( V_85 , T_6 ) > 0 )
V_131 = & V_27 -> V_134 ;
else
V_131 = & V_27 -> V_135 ;
}
F_40 ( & V_85 -> V_64 , V_27 , V_131 ) ;
F_41 ( & V_85 -> V_64 , V_208 ) ;
F_95 (he->hpp_list, fmt) {
if ( F_76 ( V_182 ) )
V_182 -> V_221 ( V_182 , V_85 , NULL ) ;
}
}
static void F_122 ( struct V_1 * V_1 ,
struct V_217 * V_218 ,
struct V_100 * V_101 ,
struct V_100 * V_102 ,
T_2 V_222 ,
bool V_117 )
{
struct V_64 * V_98 ;
struct V_14 * V_85 ;
* V_102 = V_223 ;
V_98 = F_11 ( V_101 ) ;
while ( V_98 ) {
V_85 = F_12 ( V_98 , struct V_14 , V_108 ) ;
V_98 = F_13 ( V_98 ) ;
F_121 ( V_102 , V_85 ) ;
if ( V_218 )
F_113 ( V_218 , 1 ) ;
if ( ! V_85 -> V_96 ) {
F_122 ( V_1 , V_218 ,
& V_85 -> V_104 ,
& V_85 -> V_99 ,
V_222 ,
V_117 ) ;
V_1 -> V_109 ++ ;
if ( ! V_85 -> V_69 ) {
V_1 -> V_110 ++ ;
F_6 ( V_1 , V_85 ) ;
}
continue;
}
if ( ! V_117 )
continue;
if ( V_224 . V_225 == V_226 ) {
T_2 V_156 = V_85 -> V_87 . V_72 ;
if ( V_10 . V_89 )
V_156 = V_85 -> V_90 -> V_72 ;
V_222 = V_156 * ( V_224 . V_227 / 100 ) ;
}
V_224 . V_221 ( & V_85 -> V_228 , V_85 -> V_91 ,
V_222 , & V_224 ) ;
}
}
static void F_123 ( struct V_100 * V_66 ,
struct V_14 * V_85 ,
T_2 V_222 ,
bool V_117 )
{
struct V_64 * * V_131 = & V_66 -> V_64 ;
struct V_64 * V_27 = NULL ;
struct V_14 * T_6 ;
struct V_181 * V_182 ;
if ( V_117 ) {
if ( V_224 . V_225 == V_226 ) {
T_2 V_156 = V_85 -> V_87 . V_72 ;
if ( V_10 . V_89 )
V_156 = V_85 -> V_90 -> V_72 ;
V_222 = V_156 * ( V_224 . V_227 / 100 ) ;
}
V_224 . V_221 ( & V_85 -> V_228 , V_85 -> V_91 ,
V_222 , & V_224 ) ;
}
while ( * V_131 != NULL ) {
V_27 = * V_131 ;
T_6 = F_12 ( V_27 , struct V_14 , V_64 ) ;
if ( F_114 ( V_85 , T_6 ) > 0 )
V_131 = & ( * V_131 ) -> V_134 ;
else
V_131 = & ( * V_131 ) -> V_135 ;
}
F_40 ( & V_85 -> V_64 , V_27 , V_131 ) ;
F_41 ( & V_85 -> V_64 , V_66 ) ;
F_95 (&perf_hpp_list, fmt) {
if ( F_76 ( V_182 ) &&
F_77 ( V_182 , V_85 -> V_1 ) )
V_182 -> V_221 ( V_182 , V_85 , NULL ) ;
}
}
static void F_124 ( struct V_1 * V_1 , struct V_217 * V_218 ,
bool V_117 )
{
struct V_100 * V_208 ;
struct V_64 * V_65 ;
struct V_14 * V_67 ;
T_2 V_229 ;
T_2 V_222 ;
V_229 = V_1 -> V_126 ;
if ( V_10 . V_230 )
V_229 = V_1 -> V_127 ;
V_222 = V_229 * ( V_224 . V_227 / 100 ) ;
F_117 ( V_1 ) ;
F_4 ( V_1 ) ;
if ( V_10 . V_122 ) {
F_122 ( V_1 , V_218 ,
& V_1 -> V_106 ,
& V_1 -> V_66 ,
V_222 ,
V_117 ) ;
F_120 ( V_1 ) ;
return;
}
if ( F_21 ( V_1 , V_105 ) )
V_208 = & V_1 -> V_106 ;
else
V_208 = V_1 -> V_107 ;
V_65 = F_11 ( V_208 ) ;
V_1 -> V_66 = V_223 ;
while ( V_65 ) {
V_67 = F_12 ( V_65 , struct V_14 , V_108 ) ;
V_65 = F_13 ( & V_67 -> V_108 ) ;
F_123 ( & V_1 -> V_66 , V_67 , V_222 , V_117 ) ;
F_119 ( V_1 , V_67 ) ;
if ( ! V_67 -> V_69 )
F_6 ( V_1 , V_67 ) ;
if ( V_218 )
F_113 ( V_218 , 1 ) ;
}
}
void F_125 ( struct V_153 * V_151 , struct V_217 * V_218 )
{
bool V_117 ;
if ( V_151 && V_10 . V_117 && ! V_10 . V_231 )
V_117 = V_151 -> V_232 . V_233 & V_234 ;
else
V_117 = V_10 . V_117 ;
F_124 ( F_49 ( V_151 ) , V_218 , V_117 ) ;
}
void F_126 ( struct V_1 * V_1 , struct V_217 * V_218 )
{
F_124 ( V_1 , V_218 , V_10 . V_117 ) ;
}
static bool F_127 ( struct V_14 * V_85 , enum V_235 V_236 )
{
if ( V_85 -> V_96 || V_236 == V_237 )
return false ;
if ( V_85 -> V_238 || V_236 == V_239 )
return true ;
return false ;
}
struct V_64 * F_128 ( struct V_64 * V_98 )
{
struct V_14 * V_85 = F_12 ( V_98 , struct V_14 , V_64 ) ;
while ( F_127 ( V_85 , V_240 ) ) {
V_98 = F_129 ( & V_85 -> V_99 ) ;
V_85 = F_12 ( V_98 , struct V_14 , V_64 ) ;
}
return V_98 ;
}
struct V_64 * F_130 ( struct V_64 * V_98 , enum V_235 V_236 )
{
struct V_14 * V_85 = F_12 ( V_98 , struct V_14 , V_64 ) ;
if ( F_127 ( V_85 , V_236 ) )
V_98 = F_11 ( & V_85 -> V_99 ) ;
else
V_98 = F_13 ( V_98 ) ;
while ( V_98 == NULL ) {
V_85 = V_85 -> V_103 ;
if ( V_85 == NULL )
break;
V_98 = F_13 ( & V_85 -> V_64 ) ;
}
return V_98 ;
}
struct V_64 * F_131 ( struct V_64 * V_98 )
{
struct V_14 * V_85 = F_12 ( V_98 , struct V_14 , V_64 ) ;
V_98 = F_132 ( V_98 ) ;
if ( V_98 )
return F_128 ( V_98 ) ;
V_85 = V_85 -> V_103 ;
if ( V_85 == NULL )
return NULL ;
return & V_85 -> V_64 ;
}
bool F_133 ( struct V_14 * V_85 , float V_241 )
{
struct V_64 * V_98 ;
struct V_14 * V_97 ;
float V_242 ;
if ( V_85 -> V_96 )
return false ;
V_98 = F_11 ( & V_85 -> V_99 ) ;
V_97 = F_12 ( V_98 , struct V_14 , V_64 ) ;
while ( V_98 && V_97 -> V_69 ) {
V_98 = F_13 ( V_98 ) ;
V_97 = F_12 ( V_98 , struct V_14 , V_64 ) ;
}
if ( V_98 )
V_242 = F_134 ( V_97 ) ;
else
V_242 = 0 ;
return V_98 && V_242 >= V_241 ;
}
static void F_135 ( struct V_1 * V_1 , struct V_14 * V_15 ,
enum V_193 V_243 )
{
V_15 -> V_69 &= ~ ( 1 << V_243 ) ;
if ( V_10 . V_122 ) {
struct V_14 * V_27 = V_15 -> V_103 ;
while ( V_27 ) {
F_16 ( & V_27 -> V_87 , & V_15 -> V_87 ) ;
V_27 -> V_69 &= ~ ( 1 << V_243 ) ;
if ( V_27 -> V_69 )
goto V_65;
V_27 -> V_238 = false ;
V_27 -> V_244 = false ;
V_27 -> V_245 = 0 ;
V_27 -> V_246 = 0 ;
V_65:
V_27 = V_27 -> V_103 ;
}
}
if ( V_15 -> V_69 )
return;
V_15 -> V_238 = false ;
V_15 -> V_244 = false ;
V_15 -> V_245 = 0 ;
V_15 -> V_246 = 0 ;
V_1 -> V_93 . V_247 += V_15 -> V_87 . V_82 ;
F_118 ( V_1 , V_15 ) ;
F_6 ( V_1 , V_15 ) ;
}
static bool F_107 ( struct V_1 * V_1 ,
struct V_14 * V_85 )
{
if ( V_1 -> V_248 != NULL &&
( V_85 -> V_17 . V_26 == NULL || V_85 -> V_17 . V_26 -> V_7 != V_1 -> V_248 ) ) {
V_85 -> V_69 |= ( 1 << V_200 ) ;
return true ;
}
return false ;
}
static bool F_108 ( struct V_1 * V_1 ,
struct V_14 * V_85 )
{
if ( V_1 -> V_249 != NULL &&
V_85 -> V_23 != V_1 -> V_249 ) {
V_85 -> V_69 |= ( 1 << V_196 ) ;
return true ;
}
return false ;
}
static bool F_109 ( struct V_1 * V_1 ,
struct V_14 * V_85 )
{
if ( V_1 -> V_250 != NULL &&
( ! V_85 -> V_17 . V_18 || strstr ( V_85 -> V_17 . V_18 -> V_251 ,
V_1 -> V_250 ) == NULL ) ) {
V_85 -> V_69 |= ( 1 << V_201 ) ;
return true ;
}
return false ;
}
static bool F_110 ( struct V_1 * V_1 ,
struct V_14 * V_85 )
{
if ( ( V_1 -> V_252 > - 1 ) &&
( V_85 -> V_142 != V_1 -> V_252 ) ) {
V_85 -> V_69 |= ( 1 << V_205 ) ;
return true ;
}
return false ;
}
static void F_136 ( struct V_1 * V_1 , int type , T_8 V_243 )
{
struct V_64 * V_253 ;
V_1 -> V_93 . V_247 = 0 ;
F_116 ( V_1 ) ;
F_4 ( V_1 ) ;
for ( V_253 = F_11 ( & V_1 -> V_66 ) ; V_253 ; V_253 = F_13 ( V_253 ) ) {
struct V_14 * V_15 = F_12 ( V_253 , struct V_14 , V_64 ) ;
if ( V_243 ( V_1 , V_15 ) )
continue;
F_135 ( V_1 , V_15 , type ) ;
}
}
static void F_137 ( struct V_100 * V_208 , struct V_14 * V_85 )
{
struct V_64 * * V_131 = & V_208 -> V_64 ;
struct V_64 * V_27 = NULL ;
struct V_14 * T_6 ;
struct V_100 V_254 = V_223 ;
struct V_64 * V_253 ;
while ( * V_131 != NULL ) {
V_27 = * V_131 ;
T_6 = F_12 ( V_27 , struct V_14 , V_64 ) ;
if ( F_114 ( V_85 , T_6 ) > 0 )
V_131 = & ( * V_131 ) -> V_134 ;
else
V_131 = & ( * V_131 ) -> V_135 ;
}
F_40 ( & V_85 -> V_64 , V_27 , V_131 ) ;
F_41 ( & V_85 -> V_64 , V_208 ) ;
if ( V_85 -> V_96 || V_85 -> V_69 )
return;
V_253 = F_11 ( & V_85 -> V_99 ) ;
while ( V_253 ) {
struct V_14 * V_15 = F_12 ( V_253 , struct V_14 , V_64 ) ;
V_253 = F_13 ( V_253 ) ;
F_22 ( & V_15 -> V_64 , & V_85 -> V_99 ) ;
F_137 ( & V_254 , V_15 ) ;
}
V_85 -> V_99 = V_254 ;
}
static void F_138 ( struct V_1 * V_1 , int type , const void * V_170 )
{
struct V_64 * V_253 ;
struct V_100 V_254 = V_223 ;
V_1 -> V_93 . V_247 = 0 ;
F_116 ( V_1 ) ;
F_4 ( V_1 ) ;
V_253 = F_11 ( & V_1 -> V_66 ) ;
while ( V_253 ) {
struct V_14 * V_15 = F_12 ( V_253 , struct V_14 , V_64 ) ;
int V_213 ;
V_213 = F_139 ( V_15 , type , V_170 ) ;
if ( V_213 < 0 ) {
memset ( & V_15 -> V_87 , 0 , sizeof( V_15 -> V_87 ) ) ;
V_15 -> V_69 |= ( 1 << type ) ;
V_253 = F_130 ( & V_15 -> V_64 , V_239 ) ;
}
else if ( V_213 == 1 ) {
V_15 -> V_69 |= ( 1 << type ) ;
V_253 = F_130 ( & V_15 -> V_64 , V_237 ) ;
}
else {
F_135 ( V_1 , V_15 , type ) ;
V_253 = F_130 ( & V_15 -> V_64 , V_237 ) ;
}
}
F_120 ( V_1 ) ;
V_253 = F_11 ( & V_1 -> V_66 ) ;
while ( V_253 ) {
struct V_14 * V_15 = F_12 ( V_253 , struct V_14 , V_64 ) ;
V_253 = F_13 ( V_253 ) ;
F_22 ( & V_15 -> V_64 , & V_1 -> V_66 ) ;
F_137 ( & V_254 , V_15 ) ;
}
V_1 -> V_66 = V_254 ;
}
void F_140 ( struct V_1 * V_1 )
{
if ( V_10 . V_122 )
F_138 ( V_1 , V_196 ,
V_1 -> V_249 ) ;
else
F_136 ( V_1 , V_196 ,
F_108 ) ;
}
void F_141 ( struct V_1 * V_1 )
{
if ( V_10 . V_122 )
F_138 ( V_1 , V_200 ,
V_1 -> V_248 ) ;
else
F_136 ( V_1 , V_200 ,
F_107 ) ;
}
void F_142 ( struct V_1 * V_1 )
{
if ( V_10 . V_122 )
F_138 ( V_1 , V_201 ,
V_1 -> V_250 ) ;
else
F_136 ( V_1 , V_201 ,
F_109 ) ;
}
void F_143 ( struct V_1 * V_1 )
{
if ( V_10 . V_122 )
F_138 ( V_1 , V_205 ,
& V_1 -> V_252 ) ;
else
F_136 ( V_1 , V_205 ,
F_110 ) ;
}
void F_144 ( struct V_255 * V_93 , T_9 type )
{
++ V_93 -> V_82 [ 0 ] ;
++ V_93 -> V_82 [ type ] ;
}
void F_145 ( struct V_1 * V_1 , T_9 type )
{
F_144 ( & V_1 -> V_93 , type ) ;
}
void F_51 ( struct V_1 * V_1 , bool V_69 )
{
F_144 ( & V_1 -> V_93 , V_256 ) ;
if ( ! V_69 )
V_1 -> V_93 . V_247 ++ ;
}
static struct V_14 * F_146 ( struct V_1 * V_1 ,
struct V_14 * V_257 )
{
struct V_100 * V_208 ;
struct V_64 * * V_131 ;
struct V_64 * V_27 = NULL ;
struct V_14 * V_85 ;
T_5 V_132 ;
if ( F_21 ( V_1 , V_105 ) )
V_208 = & V_1 -> V_106 ;
else
V_208 = V_1 -> V_107 ;
V_131 = & V_208 -> V_64 ;
while ( * V_131 != NULL ) {
V_27 = * V_131 ;
V_85 = F_12 ( V_27 , struct V_14 , V_108 ) ;
V_132 = F_78 ( V_85 , V_257 ) ;
if ( ! V_132 )
goto V_133;
if ( V_132 < 0 )
V_131 = & ( * V_131 ) -> V_134 ;
else
V_131 = & ( * V_131 ) -> V_135 ;
}
V_85 = F_26 ( V_257 , true ) ;
if ( V_85 ) {
memset ( & V_85 -> V_87 , 0 , sizeof( V_85 -> V_87 ) ) ;
V_85 -> V_1 = V_1 ;
if ( V_10 . V_89 )
memset ( V_85 -> V_90 , 0 , sizeof( V_85 -> V_87 ) ) ;
F_40 ( & V_85 -> V_108 , V_27 , V_131 ) ;
F_41 ( & V_85 -> V_108 , V_208 ) ;
F_119 ( V_1 , V_85 ) ;
V_85 -> V_258 = true ;
}
V_133:
return V_85 ;
}
static struct V_14 * F_147 ( struct V_1 * V_1 ,
struct V_14 * V_85 )
{
struct V_64 * V_67 ;
if ( F_21 ( V_1 , V_105 ) )
V_67 = V_1 -> V_106 . V_64 ;
else
V_67 = V_1 -> V_107 -> V_64 ;
while ( V_67 ) {
struct V_14 * T_6 = F_12 ( V_67 , struct V_14 , V_108 ) ;
T_5 V_132 = F_78 ( T_6 , V_85 ) ;
if ( V_132 < 0 )
V_67 = V_67 -> V_134 ;
else if ( V_132 > 0 )
V_67 = V_67 -> V_135 ;
else
return T_6 ;
}
return NULL ;
}
void F_148 ( struct V_1 * V_259 , struct V_1 * V_260 )
{
struct V_100 * V_208 ;
struct V_64 * V_253 ;
struct V_14 * V_261 , * V_257 ;
if ( F_21 ( V_259 , V_105 ) )
V_208 = & V_259 -> V_106 ;
else
V_208 = V_259 -> V_107 ;
for ( V_253 = F_11 ( V_208 ) ; V_253 ; V_253 = F_13 ( V_253 ) ) {
V_261 = F_12 ( V_253 , struct V_14 , V_108 ) ;
V_257 = F_147 ( V_260 , V_261 ) ;
if ( V_257 )
F_149 ( V_257 , V_261 ) ;
}
}
int F_150 ( struct V_1 * V_259 , struct V_1 * V_260 )
{
struct V_100 * V_208 ;
struct V_64 * V_253 ;
struct V_14 * V_261 , * V_257 ;
if ( F_21 ( V_260 , V_105 ) )
V_208 = & V_260 -> V_106 ;
else
V_208 = V_260 -> V_107 ;
for ( V_253 = F_11 ( V_208 ) ; V_253 ; V_253 = F_13 ( V_253 ) ) {
V_261 = F_12 ( V_253 , struct V_14 , V_108 ) ;
if ( ! F_151 ( V_261 ) ) {
V_257 = F_146 ( V_259 , V_261 ) ;
if ( V_257 == NULL )
return - 1 ;
F_149 ( V_261 , V_257 ) ;
}
}
return 0 ;
}
void F_152 ( struct V_157 * V_262 , struct V_129 * V_130 ,
struct V_139 * V_140 , bool V_263 )
{
struct V_29 * V_137 ;
if ( V_262 && V_262 -> V_158 && V_262 -> V_66 [ 0 ] . V_161 . V_162 ) {
int V_159 ;
V_137 = F_54 ( V_140 , V_130 ) ;
if ( V_137 ) {
struct V_264 * V_265 = NULL ;
for ( V_159 = V_262 -> V_158 - 1 ; V_159 >= 0 ; V_159 -- ) {
F_153 ( & V_137 [ V_159 ] . V_30 ,
V_263 ? NULL : V_265 ,
V_137 [ V_159 ] . V_161 . V_162 ) ;
V_265 = & V_137 [ V_159 ] . V_33 ;
}
free ( V_137 ) ;
}
}
}
T_3 F_154 ( struct V_266 * V_267 , T_10 * V_268 )
{
struct V_153 * V_261 ;
T_3 V_213 = 0 ;
F_155 (evlist, pos) {
V_213 += fprintf ( V_268 , L_3 , F_156 ( V_261 ) ) ;
V_213 += F_157 ( & F_49 ( V_261 ) -> V_93 , V_268 ) ;
}
return V_213 ;
}
T_2 F_158 ( struct V_1 * V_1 )
{
return V_10 . V_230 ? V_1 -> V_93 . V_95 :
V_1 -> V_93 . V_94 ;
}
int F_159 ( const struct V_269 * T_11 V_147 ,
const char * V_170 , int T_12 V_147 )
{
if ( ! strcmp ( V_170 , L_4 ) )
V_10 . V_230 = true ;
else if ( ! strcmp ( V_170 , L_5 ) )
V_10 . V_230 = false ;
else
return - 1 ;
return 0 ;
}
int F_160 ( const char * V_270 , const char * V_271 )
{
if ( ! strcmp ( V_270 , L_6 ) )
return F_159 ( NULL , V_271 , 0 ) ;
return 0 ;
}
int F_161 ( struct V_1 * V_1 , struct V_209 * V_188 )
{
memset ( V_1 , 0 , sizeof( * V_1 ) ) ;
V_1 -> V_216 [ 0 ] = V_1 -> V_216 [ 1 ] = V_223 ;
V_1 -> V_107 = & V_1 -> V_216 [ 0 ] ;
V_1 -> V_106 = V_223 ;
V_1 -> V_66 = V_223 ;
F_162 ( & V_1 -> V_215 , NULL ) ;
V_1 -> V_252 = - 1 ;
V_1 -> V_188 = V_188 ;
F_33 ( & V_1 -> V_272 ) ;
return 0 ;
}
static void F_163 ( struct V_100 * V_208 )
{
struct V_64 * V_98 ;
struct V_14 * V_85 ;
while ( ! F_164 ( V_208 ) ) {
V_98 = F_11 ( V_208 ) ;
F_22 ( V_98 , V_208 ) ;
V_85 = F_12 ( V_98 , struct V_14 , V_108 ) ;
F_23 ( V_85 ) ;
}
}
static void F_165 ( struct V_1 * V_1 )
{
F_25 ( V_1 ) ;
F_163 ( & V_1 -> V_216 [ 0 ] ) ;
F_163 ( & V_1 -> V_216 [ 1 ] ) ;
F_163 ( & V_1 -> V_106 ) ;
}
static void F_166 ( struct V_153 * V_151 )
{
struct V_1 * V_1 = F_49 ( V_151 ) ;
struct V_181 * V_182 , * V_261 ;
struct V_211 * V_98 , * V_273 ;
F_165 ( V_1 ) ;
F_167 (node, tmp, &hists->hpp_formats, list) {
F_168 (&node->hpp, fmt, pos) {
F_169 ( & V_182 -> V_187 ) ;
free ( V_182 ) ;
}
F_169 ( & V_98 -> V_187 ) ;
free ( V_98 ) ;
}
}
static int F_170 ( struct V_153 * V_151 )
{
struct V_1 * V_1 = F_49 ( V_151 ) ;
F_161 ( V_1 , & V_209 ) ;
return 0 ;
}
int F_171 ( void )
{
int V_154 = F_172 ( sizeof( struct V_274 ) ,
F_170 ,
F_166 ) ;
if ( V_154 )
fputs ( L_7 , V_275 ) ;
return V_154 ;
}
void F_173 ( struct V_209 * V_187 )
{
F_33 ( & V_187 -> V_189 ) ;
F_33 ( & V_187 -> V_276 ) ;
}
