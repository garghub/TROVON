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
F_2 ( V_1 , V_25 , V_5 + 8 ) ;
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
static int F_26 ( struct V_14 * V_85 ,
struct V_14 * V_114 ,
bool V_115 )
{
* V_85 = * V_114 ;
if ( V_10 . V_89 ) {
V_85 -> V_90 = malloc ( sizeof( V_85 -> V_87 ) ) ;
if ( V_85 -> V_90 == NULL )
return - V_116 ;
memcpy ( V_85 -> V_90 , & V_85 -> V_87 , sizeof( V_85 -> V_87 ) ) ;
if ( ! V_115 )
memset ( & V_85 -> V_87 , 0 , sizeof( V_85 -> V_87 ) ) ;
}
F_27 ( V_85 -> V_17 . V_26 ) ;
if ( V_85 -> V_29 ) {
V_85 -> V_29 = malloc ( sizeof( * V_85 -> V_29 ) ) ;
if ( V_85 -> V_29 == NULL ) {
F_28 ( V_85 -> V_17 . V_26 ) ;
free ( V_85 -> V_90 ) ;
return - V_116 ;
}
memcpy ( V_85 -> V_29 , V_114 -> V_29 ,
sizeof( * V_85 -> V_29 ) ) ;
F_27 ( V_85 -> V_29 -> V_30 . V_26 ) ;
F_27 ( V_85 -> V_29 -> V_33 . V_26 ) ;
}
if ( V_85 -> V_40 ) {
F_27 ( V_85 -> V_40 -> V_44 . V_26 ) ;
F_27 ( V_85 -> V_40 -> V_41 . V_26 ) ;
}
if ( V_10 . V_117 )
F_29 ( V_85 -> V_91 ) ;
if ( V_85 -> V_118 ) {
V_85 -> V_118 = F_30 ( V_85 -> V_118 , V_85 -> V_119 ) ;
if ( V_85 -> V_118 == NULL ) {
F_31 ( V_85 -> V_17 . V_26 ) ;
if ( V_85 -> V_29 ) {
F_31 ( V_85 -> V_29 -> V_30 . V_26 ) ;
F_31 ( V_85 -> V_29 -> V_33 . V_26 ) ;
free ( V_85 -> V_29 ) ;
}
if ( V_85 -> V_40 ) {
F_31 ( V_85 -> V_40 -> V_44 . V_26 ) ;
F_31 ( V_85 -> V_40 -> V_41 . V_26 ) ;
}
free ( V_85 -> V_90 ) ;
return - V_116 ;
}
}
F_32 ( & V_85 -> V_120 . V_98 ) ;
F_33 ( V_85 -> V_23 ) ;
if ( ! V_10 . V_121 )
V_85 -> V_96 = true ;
return 0 ;
}
static void * F_34 ( T_3 V_122 )
{
return F_35 ( V_122 + sizeof( struct V_14 ) ) ;
}
static void F_36 ( void * V_123 )
{
free ( V_123 ) ;
}
static struct V_14 * F_37 ( struct V_14 * V_114 ,
bool V_115 )
{
struct V_124 * V_125 = V_114 -> V_125 ;
T_3 V_126 = 0 ;
struct V_14 * V_85 ;
int V_127 = 0 ;
if ( ! V_125 )
V_125 = V_114 -> V_125 = & V_128 ;
if ( V_10 . V_117 )
V_126 = sizeof( struct V_129 ) ;
V_85 = V_125 -> V_130 ( V_126 ) ;
if ( V_85 ) {
V_127 = F_26 ( V_85 , V_114 , V_115 ) ;
if ( V_127 ) {
V_125 -> free ( V_85 ) ;
V_85 = NULL ;
}
}
return V_85 ;
}
static T_4 F_38 ( const struct V_131 * V_27 )
{
if ( V_10 . V_132 && V_27 == NULL )
return 1 << V_133 ;
return 0 ;
}
static void F_39 ( struct V_14 * V_85 , T_2 V_72 )
{
if ( ! V_10 . V_117 )
return;
V_85 -> V_1 -> V_134 += V_72 ;
if ( ! V_85 -> V_69 )
V_85 -> V_1 -> V_135 += V_72 ;
}
static struct V_14 * F_40 ( struct V_1 * V_1 ,
struct V_14 * V_136 ,
struct V_137 * V_138 ,
bool V_115 )
{
struct V_64 * * V_139 ;
struct V_64 * V_27 = NULL ;
struct V_14 * V_85 ;
T_5 V_140 ;
T_2 V_72 = V_136 -> V_87 . V_72 ;
T_2 V_81 = V_136 -> V_87 . V_81 ;
V_139 = & V_1 -> V_107 -> V_64 ;
while ( * V_139 != NULL ) {
V_27 = * V_139 ;
V_85 = F_12 ( V_27 , struct V_14 , V_108 ) ;
V_140 = F_41 ( V_85 , V_136 ) ;
if ( ! V_140 ) {
if ( V_115 ) {
F_15 ( & V_85 -> V_87 , V_72 , V_81 ) ;
F_39 ( V_85 , V_72 ) ;
}
if ( V_10 . V_89 )
F_15 ( V_85 -> V_90 , V_72 , V_81 ) ;
F_42 ( & V_136 -> V_40 ) ;
if ( V_85 -> V_17 . V_26 != V_136 -> V_17 . V_26 ) {
F_31 ( V_85 -> V_17 . V_26 ) ;
V_85 -> V_17 . V_26 = F_27 ( V_136 -> V_17 . V_26 ) ;
}
goto V_141;
}
if ( V_140 < 0 )
V_139 = & ( * V_139 ) -> V_142 ;
else
V_139 = & ( * V_139 ) -> V_143 ;
}
V_85 = F_37 ( V_136 , V_115 ) ;
if ( ! V_85 )
return NULL ;
if ( V_115 )
F_39 ( V_85 , V_72 ) ;
V_1 -> V_109 ++ ;
F_43 ( & V_85 -> V_108 , V_27 , V_139 ) ;
F_44 ( & V_85 -> V_108 , V_1 -> V_107 ) ;
V_141:
if ( V_115 )
F_14 ( & V_85 -> V_87 , V_138 -> V_71 , V_72 ) ;
if ( V_10 . V_89 )
F_14 ( V_85 -> V_90 , V_138 -> V_71 , V_72 ) ;
return V_85 ;
}
static struct V_14 *
F_45 ( struct V_1 * V_1 ,
struct V_137 * V_138 ,
struct V_131 * V_144 ,
struct V_29 * V_145 ,
struct V_40 * V_146 ,
struct V_147 * V_148 ,
bool V_115 ,
struct V_124 * V_125 )
{
struct V_14 V_136 = {
. V_23 = V_138 -> V_23 ,
. V_149 = F_46 ( V_138 -> V_23 ) ,
. V_17 = {
. V_26 = V_138 -> V_26 ,
. V_18 = V_138 -> V_18 ,
} ,
. V_150 = V_138 -> V_150 ,
. V_151 = V_138 -> V_151 ,
. V_71 = V_138 -> V_71 ,
. V_152 = V_138 -> V_153 ,
. V_113 = V_138 -> V_113 ,
. V_87 = {
. V_82 = 1 ,
. V_72 = V_148 -> V_72 ,
. V_81 = V_148 -> V_81 ,
} ,
. V_27 = V_144 ,
. V_69 = F_38 ( V_144 ) | V_138 -> V_69 ,
. V_1 = V_1 ,
. V_29 = V_145 ,
. V_40 = V_146 ,
. V_59 = V_148 -> V_59 ,
. V_118 = V_148 -> V_118 ,
. V_119 = V_148 -> V_119 ,
. V_125 = V_125 ,
} ;
return F_40 ( V_1 , & V_136 , V_138 , V_115 ) ;
}
struct V_14 * F_47 ( struct V_1 * V_1 ,
struct V_137 * V_138 ,
struct V_131 * V_144 ,
struct V_29 * V_145 ,
struct V_40 * V_146 ,
struct V_147 * V_148 ,
bool V_115 )
{
return F_45 ( V_1 , V_138 , V_144 , V_145 , V_146 ,
V_148 , V_115 , NULL ) ;
}
struct V_14 * F_48 ( struct V_1 * V_1 ,
struct V_124 * V_125 ,
struct V_137 * V_138 ,
struct V_131 * V_144 ,
struct V_29 * V_145 ,
struct V_40 * V_146 ,
struct V_147 * V_148 ,
bool V_115 )
{
return F_45 ( V_1 , V_138 , V_144 , V_145 , V_146 ,
V_148 , V_115 , V_125 ) ;
}
static int
F_49 ( struct V_154 * T_6 V_155 ,
struct V_137 * V_138 V_155 )
{
return 0 ;
}
static int
F_50 ( struct V_154 * T_6 V_155 ,
struct V_137 * V_138 V_155 )
{
return 0 ;
}
static int
F_51 ( struct V_154 * T_6 , struct V_137 * V_138 )
{
struct V_147 * V_148 = T_6 -> V_148 ;
struct V_40 * V_146 ;
V_146 = F_52 ( V_148 , V_138 ) ;
if ( V_146 == NULL )
return - V_116 ;
T_6 -> V_156 = V_146 ;
return 0 ;
}
static int
F_53 ( struct V_154 * T_6 , struct V_137 * V_138 )
{
T_2 V_157 ;
struct V_40 * V_146 = T_6 -> V_156 ;
struct V_1 * V_1 = F_54 ( T_6 -> V_158 ) ;
struct V_147 * V_148 = T_6 -> V_148 ;
struct V_14 * V_85 ;
if ( V_146 == NULL )
return - V_159 ;
V_157 = V_148 -> V_81 ;
if ( ! V_157 )
V_157 = 1 ;
V_148 -> V_72 = V_157 ;
V_85 = F_47 ( V_1 , V_138 , T_6 -> V_27 , NULL , V_146 ,
V_148 , true ) ;
if ( ! V_85 )
return - V_116 ;
T_6 -> V_85 = V_85 ;
return 0 ;
}
static int
F_55 ( struct V_154 * T_6 ,
struct V_137 * V_138 V_155 )
{
struct V_160 * V_158 = T_6 -> V_158 ;
struct V_1 * V_1 = F_54 ( V_158 ) ;
struct V_14 * V_85 = T_6 -> V_85 ;
int V_127 = - V_159 ;
if ( V_85 == NULL )
goto V_141;
F_56 ( V_1 , V_85 -> V_69 ) ;
V_127 = F_57 ( V_85 , T_6 -> V_148 ) ;
V_141:
T_6 -> V_156 = NULL ;
T_6 -> V_85 = NULL ;
return V_127 ;
}
static int
F_58 ( struct V_154 * T_6 , struct V_137 * V_138 )
{
struct V_29 * V_145 ;
struct V_147 * V_148 = T_6 -> V_148 ;
V_145 = F_59 ( V_148 , V_138 ) ;
if ( ! V_145 )
return - V_116 ;
T_6 -> V_161 = 0 ;
T_6 -> V_162 = V_148 -> V_163 -> V_164 ;
T_6 -> V_156 = V_145 ;
return 0 ;
}
static int
F_60 ( struct V_154 * T_6 ,
struct V_137 * V_138 V_155 )
{
T_6 -> V_85 = NULL ;
return 0 ;
}
static int
F_61 ( struct V_154 * T_6 , struct V_137 * V_138 )
{
struct V_29 * V_145 = T_6 -> V_156 ;
int V_165 = T_6 -> V_161 ;
if ( V_145 == NULL )
return 0 ;
if ( T_6 -> V_161 >= T_6 -> V_162 )
return 0 ;
V_138 -> V_26 = V_145 [ V_165 ] . V_33 . V_26 ;
V_138 -> V_18 = V_145 [ V_165 ] . V_33 . V_18 ;
V_138 -> V_153 = V_145 [ V_165 ] . V_33 . V_153 ;
return 1 ;
}
static int
F_62 ( struct V_154 * T_6 , struct V_137 * V_138 )
{
struct V_29 * V_145 ;
struct V_160 * V_158 = T_6 -> V_158 ;
struct V_1 * V_1 = F_54 ( V_158 ) ;
struct V_147 * V_148 = T_6 -> V_148 ;
struct V_14 * V_85 = NULL ;
int V_165 = T_6 -> V_161 ;
int V_127 = 0 ;
V_145 = T_6 -> V_156 ;
if ( T_6 -> V_166 && ! ( V_145 [ V_165 ] . V_30 . V_18 && V_145 [ V_165 ] . V_33 . V_18 ) )
goto V_141;
V_148 -> V_72 = 1 ;
V_148 -> V_81 = V_145 -> V_167 . V_168 ? V_145 -> V_167 . V_168 : 1 ;
V_85 = F_47 ( V_1 , V_138 , T_6 -> V_27 , & V_145 [ V_165 ] , NULL ,
V_148 , true ) ;
if ( V_85 == NULL )
return - V_116 ;
F_56 ( V_1 , V_85 -> V_69 ) ;
V_141:
T_6 -> V_85 = V_85 ;
T_6 -> V_161 ++ ;
return V_127 ;
}
static int
F_63 ( struct V_154 * T_6 ,
struct V_137 * V_138 V_155 )
{
F_42 ( & T_6 -> V_156 ) ;
T_6 -> V_85 = NULL ;
return T_6 -> V_161 >= T_6 -> V_162 ? 0 : - 1 ;
}
static int
F_64 ( struct V_154 * T_6 V_155 ,
struct V_137 * V_138 V_155 )
{
return 0 ;
}
static int
F_65 ( struct V_154 * T_6 , struct V_137 * V_138 )
{
struct V_160 * V_158 = T_6 -> V_158 ;
struct V_147 * V_148 = T_6 -> V_148 ;
struct V_14 * V_85 ;
V_85 = F_47 ( F_54 ( V_158 ) , V_138 , T_6 -> V_27 , NULL , NULL ,
V_148 , true ) ;
if ( V_85 == NULL )
return - V_116 ;
T_6 -> V_85 = V_85 ;
return 0 ;
}
static int
F_66 ( struct V_154 * T_6 ,
struct V_137 * V_138 V_155 )
{
struct V_14 * V_85 = T_6 -> V_85 ;
struct V_160 * V_158 = T_6 -> V_158 ;
struct V_147 * V_148 = T_6 -> V_148 ;
if ( V_85 == NULL )
return 0 ;
T_6 -> V_85 = NULL ;
F_56 ( F_54 ( V_158 ) , V_85 -> V_69 ) ;
return F_57 ( V_85 , V_148 ) ;
}
static int
F_67 ( struct V_154 * T_6 ,
struct V_137 * V_138 V_155 )
{
struct V_14 * * V_169 ;
F_68 ( & V_170 ) ;
V_169 = malloc ( sizeof( * V_169 ) * ( T_6 -> V_171 + 1 ) ) ;
if ( V_169 == NULL )
return - V_116 ;
T_6 -> V_156 = V_169 ;
T_6 -> V_161 = 0 ;
return 0 ;
}
static int
F_69 ( struct V_154 * T_6 ,
struct V_137 * V_138 )
{
struct V_160 * V_158 = T_6 -> V_158 ;
struct V_1 * V_1 = F_54 ( V_158 ) ;
struct V_147 * V_148 = T_6 -> V_148 ;
struct V_14 * * V_169 = T_6 -> V_156 ;
struct V_14 * V_85 ;
int V_127 = 0 ;
V_85 = F_47 ( V_1 , V_138 , T_6 -> V_27 , NULL , NULL ,
V_148 , true ) ;
if ( V_85 == NULL )
return - V_116 ;
T_6 -> V_85 = V_85 ;
V_169 [ T_6 -> V_161 ++ ] = V_85 ;
F_57 ( V_85 , V_148 ) ;
F_68 ( & V_170 ) ;
F_56 ( V_1 , V_85 -> V_69 ) ;
return V_127 ;
}
static int
F_70 ( struct V_154 * T_6 ,
struct V_137 * V_138 )
{
struct V_172 * V_98 ;
V_98 = F_71 ( & V_170 ) ;
if ( V_98 == NULL )
return 0 ;
return F_72 ( V_138 , V_98 , T_6 -> V_166 ) ;
}
static int
F_73 ( struct V_154 * T_6 ,
struct V_137 * V_138 )
{
struct V_160 * V_158 = T_6 -> V_158 ;
struct V_147 * V_148 = T_6 -> V_148 ;
struct V_14 * * V_169 = T_6 -> V_156 ;
struct V_14 * V_85 ;
struct V_14 V_173 = {
. V_1 = F_54 ( V_158 ) ,
. V_151 = V_138 -> V_151 ,
. V_23 = V_138 -> V_23 ,
. V_149 = F_46 ( V_138 -> V_23 ) ,
. V_152 = V_138 -> V_153 ,
. V_17 = {
. V_26 = V_138 -> V_26 ,
. V_18 = V_138 -> V_18 ,
} ,
. V_27 = T_6 -> V_27 ,
. V_118 = V_148 -> V_118 ,
. V_119 = V_148 -> V_119 ,
} ;
int V_165 ;
struct V_170 V_174 ;
F_74 ( & V_174 , & V_170 ) ;
F_75 ( & V_170 ) ;
for ( V_165 = 0 ; V_165 < T_6 -> V_161 ; V_165 ++ ) {
if ( F_41 ( V_169 [ V_165 ] , & V_173 ) == 0 ) {
T_6 -> V_85 = NULL ;
return 0 ;
}
}
V_85 = F_47 ( F_54 ( V_158 ) , V_138 , T_6 -> V_27 , NULL , NULL ,
V_148 , false ) ;
if ( V_85 == NULL )
return - V_116 ;
T_6 -> V_85 = V_85 ;
V_169 [ T_6 -> V_161 ++ ] = V_85 ;
if ( V_10 . V_117 )
F_76 ( V_85 -> V_91 , & V_174 , V_148 -> V_72 ) ;
return 0 ;
}
static int
F_77 ( struct V_154 * T_6 ,
struct V_137 * V_138 V_155 )
{
F_42 ( & T_6 -> V_156 ) ;
T_6 -> V_85 = NULL ;
return 0 ;
}
int F_78 ( struct V_154 * T_6 , struct V_137 * V_138 ,
int V_175 , void * V_176 )
{
int V_127 , V_177 ;
V_127 = F_79 ( T_6 -> V_148 , & V_170 , & T_6 -> V_27 ,
T_6 -> V_158 , V_138 , V_175 ) ;
if ( V_127 )
return V_127 ;
T_6 -> V_171 = V_175 ;
V_127 = T_6 -> V_125 -> V_178 ( T_6 , V_138 ) ;
if ( V_127 )
goto V_141;
V_127 = T_6 -> V_125 -> V_179 ( T_6 , V_138 ) ;
if ( V_127 )
goto V_141;
if ( T_6 -> V_85 && T_6 -> V_180 ) {
V_127 = T_6 -> V_180 ( T_6 , V_138 , true , V_176 ) ;
if ( V_127 )
goto V_141;
}
while ( T_6 -> V_125 -> V_181 ( T_6 , V_138 ) ) {
V_127 = T_6 -> V_125 -> V_182 ( T_6 , V_138 ) ;
if ( V_127 )
break;
if ( T_6 -> V_85 && T_6 -> V_180 ) {
V_127 = T_6 -> V_180 ( T_6 , V_138 , false , V_176 ) ;
if ( V_127 )
goto V_141;
}
}
V_141:
V_177 = T_6 -> V_125 -> V_183 ( T_6 , V_138 ) ;
if ( ! V_127 )
V_127 = V_177 ;
return V_127 ;
}
T_5
F_41 ( struct V_14 * V_184 , struct V_14 * V_185 )
{
struct V_1 * V_1 = V_184 -> V_1 ;
struct V_186 * V_187 ;
T_5 V_140 = 0 ;
F_80 (hists, fmt) {
if ( F_81 ( V_187 ) &&
! F_82 ( V_187 , V_1 ) )
continue;
V_140 = V_187 -> V_140 ( V_187 , V_184 , V_185 ) ;
if ( V_140 )
break;
}
return V_140 ;
}
T_5
F_83 ( struct V_14 * V_184 , struct V_14 * V_185 )
{
struct V_1 * V_1 = V_184 -> V_1 ;
struct V_186 * V_187 ;
T_5 V_140 = 0 ;
F_80 (hists, fmt) {
if ( F_81 ( V_187 ) &&
! F_82 ( V_187 , V_1 ) )
continue;
V_140 = V_187 -> V_188 ( V_187 , V_184 , V_185 ) ;
if ( V_140 )
break;
}
return V_140 ;
}
void F_23 ( struct V_14 * V_85 )
{
struct V_124 * V_125 = V_85 -> V_125 ;
F_84 ( V_85 -> V_23 ) ;
F_28 ( V_85 -> V_17 . V_26 ) ;
if ( V_85 -> V_29 ) {
F_28 ( V_85 -> V_29 -> V_30 . V_26 ) ;
F_28 ( V_85 -> V_29 -> V_33 . V_26 ) ;
F_85 ( V_85 -> V_29 -> V_36 ) ;
F_85 ( V_85 -> V_29 -> V_38 ) ;
F_42 ( & V_85 -> V_29 ) ;
}
if ( V_85 -> V_40 ) {
F_28 ( V_85 -> V_40 -> V_44 . V_26 ) ;
F_28 ( V_85 -> V_40 -> V_41 . V_26 ) ;
F_42 ( & V_85 -> V_40 ) ;
}
F_42 ( & V_85 -> V_90 ) ;
F_85 ( V_85 -> V_55 ) ;
if ( V_85 -> V_57 && V_85 -> V_57 [ 0 ] )
free ( V_85 -> V_57 ) ;
F_86 ( V_85 -> V_91 ) ;
free ( V_85 -> V_61 ) ;
free ( V_85 -> V_118 ) ;
V_125 -> free ( V_85 ) ;
}
int F_87 ( struct V_14 * V_85 , struct V_189 * V_190 ,
struct V_186 * V_187 , int V_191 )
{
if ( ! F_88 ( & V_187 -> V_192 , & V_85 -> V_1 -> V_193 -> V_194 ) ) {
const int V_195 = V_187 -> V_195 ( V_187 , V_190 , V_85 -> V_1 ) ;
if ( V_191 < V_195 ) {
F_89 ( V_190 , V_191 ) ;
V_191 = F_90 ( V_190 -> V_196 , V_190 -> V_122 , L_1 , V_195 - V_191 , L_2 ) ;
}
}
return V_191 ;
}
static bool F_91 ( struct V_186 * V_187 )
{
return F_92 ( V_187 ) || F_93 ( V_187 ) ;
}
static void F_94 ( struct V_14 * V_85 ,
enum V_197 type ,
T_7 V_198 )
{
struct V_186 * V_187 ;
bool V_199 = false ;
struct V_14 * V_27 = V_85 -> V_103 ;
switch ( type ) {
case V_200 :
if ( V_10 . V_201 == NULL &&
V_10 . V_202 == NULL &&
V_10 . V_203 == NULL )
return;
break;
case V_204 :
if ( V_10 . V_13 == NULL )
return;
break;
case V_205 :
if ( V_10 . V_206 == NULL )
return;
break;
case V_133 :
case V_207 :
case V_208 :
case V_209 :
default:
return;
}
F_95 (he->hpp_list, fmt) {
if ( V_198 ( V_187 ) ) {
V_199 = true ;
break;
}
}
if ( V_199 ) {
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
static void F_96 ( struct V_14 * V_85 )
{
F_94 ( V_85 , V_200 ,
F_91 ) ;
F_94 ( V_85 , V_204 ,
V_210 ) ;
F_94 ( V_85 , V_205 ,
V_211 ) ;
F_97 ( V_85 -> V_1 , V_85 ) ;
}
static struct V_14 * F_98 ( struct V_1 * V_1 ,
struct V_100 * V_212 ,
struct V_14 * V_85 ,
struct V_14 * V_103 ,
struct V_213 * V_193 )
{
struct V_64 * * V_139 = & V_212 -> V_64 ;
struct V_64 * V_27 = NULL ;
struct V_14 * T_6 , * V_130 ;
struct V_186 * V_187 ;
T_5 V_140 ;
while ( * V_139 != NULL ) {
V_27 = * V_139 ;
T_6 = F_12 ( V_27 , struct V_14 , V_108 ) ;
V_140 = 0 ;
F_99 (hpp_list, fmt) {
V_140 = V_187 -> V_188 ( V_187 , T_6 , V_85 ) ;
if ( V_140 )
break;
}
if ( ! V_140 ) {
F_16 ( & T_6 -> V_87 , & V_85 -> V_87 ) ;
return T_6 ;
}
if ( V_140 < 0 )
V_139 = & V_27 -> V_142 ;
else
V_139 = & V_27 -> V_143 ;
}
V_130 = F_37 ( V_85 , true ) ;
if ( V_130 == NULL )
return NULL ;
V_1 -> V_109 ++ ;
V_130 -> V_193 = V_193 ;
V_130 -> V_103 = V_103 ;
F_96 ( V_130 ) ;
F_99 (hpp_list, fmt) {
if ( F_100 ( V_187 ) || F_81 ( V_187 ) )
V_85 -> V_61 = NULL ;
else
V_130 -> V_61 = NULL ;
if ( F_101 ( V_187 ) )
V_85 -> V_55 = NULL ;
else
V_130 -> V_55 = NULL ;
if ( F_102 ( V_187 ) )
V_85 -> V_57 = NULL ;
else
V_130 -> V_57 = NULL ;
}
F_43 ( & V_130 -> V_108 , V_27 , V_139 ) ;
F_44 ( & V_130 -> V_108 , V_212 ) ;
return V_130 ;
}
static int F_103 ( struct V_1 * V_1 ,
struct V_100 * V_212 ,
struct V_14 * V_85 )
{
struct V_214 * V_98 ;
struct V_14 * V_215 = NULL ;
struct V_14 * V_27 = NULL ;
int V_92 = 0 ;
int V_216 = 0 ;
F_104 (node, &hists->hpp_formats, list) {
if ( V_98 -> V_113 == 0 || V_98 -> V_217 )
continue;
V_215 = F_98 ( V_1 , V_212 , V_85 , V_27 , & V_98 -> V_190 ) ;
if ( V_215 == NULL ) {
V_216 = - 1 ;
break;
}
V_212 = & V_215 -> V_104 ;
V_215 -> V_92 = V_92 ++ ;
V_27 = V_215 ;
}
if ( V_215 ) {
V_215 -> V_96 = true ;
if ( V_10 . V_117 ) {
F_105 ( & V_170 ) ;
if ( F_106 ( & V_170 ,
V_215 -> V_91 ,
V_85 -> V_91 ) < 0 )
V_216 = - 1 ;
}
}
F_23 ( V_85 ) ;
return V_216 ;
}
static int F_107 ( struct V_1 * V_1 ,
struct V_100 * V_212 ,
struct V_14 * V_85 )
{
struct V_64 * * V_139 = & V_212 -> V_64 ;
struct V_64 * V_27 = NULL ;
struct V_14 * T_6 ;
T_5 V_140 ;
if ( V_10 . V_121 )
return F_103 ( V_1 , V_212 , V_85 ) ;
while ( * V_139 != NULL ) {
V_27 = * V_139 ;
T_6 = F_12 ( V_27 , struct V_14 , V_108 ) ;
V_140 = F_83 ( T_6 , V_85 ) ;
if ( ! V_140 ) {
int V_216 = 0 ;
F_16 ( & T_6 -> V_87 , & V_85 -> V_87 ) ;
if ( V_10 . V_89 )
F_16 ( T_6 -> V_90 , V_85 -> V_90 ) ;
if ( V_10 . V_117 ) {
F_105 ( & V_170 ) ;
if ( F_106 ( & V_170 ,
T_6 -> V_91 ,
V_85 -> V_91 ) < 0 )
V_216 = - 1 ;
}
F_23 ( V_85 ) ;
return V_216 ;
}
if ( V_140 < 0 )
V_139 = & ( * V_139 ) -> V_142 ;
else
V_139 = & ( * V_139 ) -> V_143 ;
}
V_1 -> V_109 ++ ;
F_43 ( & V_85 -> V_108 , V_27 , V_139 ) ;
F_44 ( & V_85 -> V_108 , V_212 ) ;
return 1 ;
}
struct V_100 * F_108 ( struct V_1 * V_1 )
{
struct V_100 * V_212 ;
F_109 ( & V_1 -> V_218 ) ;
V_212 = V_1 -> V_107 ;
if ( ++ V_1 -> V_107 > & V_1 -> V_219 [ 1 ] )
V_1 -> V_107 = & V_1 -> V_219 [ 0 ] ;
F_110 ( & V_1 -> V_218 ) ;
return V_212 ;
}
static void F_97 ( struct V_1 * V_1 , struct V_14 * V_85 )
{
F_111 ( V_1 , V_85 ) ;
F_112 ( V_1 , V_85 ) ;
F_113 ( V_1 , V_85 ) ;
F_114 ( V_1 , V_85 ) ;
}
int F_115 ( struct V_1 * V_1 , struct V_220 * V_221 )
{
struct V_100 * V_212 ;
struct V_64 * V_65 ;
struct V_14 * V_67 ;
int V_216 ;
if ( ! F_21 ( V_1 , V_105 ) )
return 0 ;
V_1 -> V_109 = 0 ;
V_212 = F_108 ( V_1 ) ;
V_65 = F_11 ( V_212 ) ;
while ( V_65 ) {
if ( F_116 () )
break;
V_67 = F_12 ( V_65 , struct V_14 , V_108 ) ;
V_65 = F_13 ( & V_67 -> V_108 ) ;
F_22 ( & V_67 -> V_108 , V_212 ) ;
V_216 = F_107 ( V_1 , & V_1 -> V_106 , V_67 ) ;
if ( V_216 < 0 )
return - 1 ;
if ( V_216 ) {
F_97 ( V_1 , V_67 ) ;
}
if ( V_221 )
F_117 ( V_221 , 1 ) ;
}
return 0 ;
}
static int F_118 ( struct V_14 * V_222 , struct V_14 * V_223 )
{
struct V_1 * V_1 = V_222 -> V_1 ;
struct V_186 * V_187 ;
T_5 V_140 = 0 ;
F_80 (hists, fmt) {
if ( F_119 ( V_187 , V_222 -> V_1 ) )
continue;
V_140 = V_187 -> V_224 ( V_187 , V_222 , V_223 ) ;
if ( V_140 )
break;
}
return V_140 ;
}
static void F_120 ( struct V_1 * V_1 )
{
V_1 -> V_110 = 0 ;
V_1 -> V_93 . V_95 = 0 ;
}
void F_121 ( struct V_1 * V_1 )
{
V_1 -> V_109 = 0 ;
V_1 -> V_93 . V_94 = 0 ;
F_120 ( V_1 ) ;
}
static void F_122 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
V_1 -> V_110 ++ ;
V_1 -> V_93 . V_95 += V_15 -> V_87 . V_72 ;
}
void F_123 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
if ( ! V_15 -> V_69 )
F_122 ( V_1 , V_15 ) ;
V_1 -> V_109 ++ ;
V_1 -> V_93 . V_94 += V_15 -> V_87 . V_72 ;
}
static void F_124 ( struct V_1 * V_1 )
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
static void F_125 ( struct V_100 * V_212 ,
struct V_14 * V_85 )
{
struct V_64 * * V_139 = & V_212 -> V_64 ;
struct V_64 * V_27 = NULL ;
struct V_14 * T_6 ;
struct V_186 * V_187 ;
while ( * V_139 != NULL ) {
V_27 = * V_139 ;
T_6 = F_12 ( V_27 , struct V_14 , V_64 ) ;
if ( F_118 ( V_85 , T_6 ) > 0 )
V_139 = & V_27 -> V_142 ;
else
V_139 = & V_27 -> V_143 ;
}
F_43 ( & V_85 -> V_64 , V_27 , V_139 ) ;
F_44 ( & V_85 -> V_64 , V_212 ) ;
F_99 (he->hpp_list, fmt) {
if ( F_81 ( V_187 ) )
V_187 -> V_224 ( V_187 , V_85 , NULL ) ;
}
}
static void F_126 ( struct V_1 * V_1 ,
struct V_220 * V_221 ,
struct V_100 * V_101 ,
struct V_100 * V_102 ,
T_2 V_225 ,
bool V_117 )
{
struct V_64 * V_98 ;
struct V_14 * V_85 ;
* V_102 = V_226 ;
V_98 = F_11 ( V_101 ) ;
while ( V_98 ) {
V_85 = F_12 ( V_98 , struct V_14 , V_108 ) ;
V_98 = F_13 ( V_98 ) ;
F_125 ( V_102 , V_85 ) ;
if ( V_221 )
F_117 ( V_221 , 1 ) ;
if ( ! V_85 -> V_96 ) {
F_126 ( V_1 , V_221 ,
& V_85 -> V_104 ,
& V_85 -> V_99 ,
V_225 ,
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
if ( V_227 . V_228 == V_229 ) {
T_2 V_162 = V_85 -> V_87 . V_72 ;
if ( V_10 . V_89 )
V_162 = V_85 -> V_90 -> V_72 ;
V_225 = V_162 * ( V_227 . V_230 / 100 ) ;
}
V_227 . V_224 ( & V_85 -> V_231 , V_85 -> V_91 ,
V_225 , & V_227 ) ;
}
}
static void F_127 ( struct V_100 * V_66 ,
struct V_14 * V_85 ,
T_2 V_225 ,
bool V_117 )
{
struct V_64 * * V_139 = & V_66 -> V_64 ;
struct V_64 * V_27 = NULL ;
struct V_14 * T_6 ;
struct V_186 * V_187 ;
if ( V_117 ) {
if ( V_227 . V_228 == V_229 ) {
T_2 V_162 = V_85 -> V_87 . V_72 ;
if ( V_10 . V_89 )
V_162 = V_85 -> V_90 -> V_72 ;
V_225 = V_162 * ( V_227 . V_230 / 100 ) ;
}
V_227 . V_224 ( & V_85 -> V_231 , V_85 -> V_91 ,
V_225 , & V_227 ) ;
}
while ( * V_139 != NULL ) {
V_27 = * V_139 ;
T_6 = F_12 ( V_27 , struct V_14 , V_64 ) ;
if ( F_118 ( V_85 , T_6 ) > 0 )
V_139 = & ( * V_139 ) -> V_142 ;
else
V_139 = & ( * V_139 ) -> V_143 ;
}
F_43 ( & V_85 -> V_64 , V_27 , V_139 ) ;
F_44 ( & V_85 -> V_64 , V_66 ) ;
F_99 (&perf_hpp_list, fmt) {
if ( F_81 ( V_187 ) &&
F_82 ( V_187 , V_85 -> V_1 ) )
V_187 -> V_224 ( V_187 , V_85 , NULL ) ;
}
}
static void F_128 ( struct V_1 * V_1 , struct V_220 * V_221 ,
bool V_117 , T_8 V_232 )
{
struct V_100 * V_212 ;
struct V_64 * V_65 ;
struct V_14 * V_67 ;
T_2 V_233 ;
T_2 V_225 ;
V_233 = V_1 -> V_134 ;
if ( V_10 . V_234 )
V_233 = V_1 -> V_135 ;
V_225 = V_233 * ( V_227 . V_230 / 100 ) ;
F_121 ( V_1 ) ;
F_4 ( V_1 ) ;
if ( V_10 . V_121 ) {
F_126 ( V_1 , V_221 ,
& V_1 -> V_106 ,
& V_1 -> V_66 ,
V_225 ,
V_117 ) ;
F_124 ( V_1 ) ;
return;
}
if ( F_21 ( V_1 , V_105 ) )
V_212 = & V_1 -> V_106 ;
else
V_212 = V_1 -> V_107 ;
V_65 = F_11 ( V_212 ) ;
V_1 -> V_66 = V_226 ;
while ( V_65 ) {
V_67 = F_12 ( V_65 , struct V_14 , V_108 ) ;
V_65 = F_13 ( & V_67 -> V_108 ) ;
if ( V_232 && V_232 ( V_67 ) )
continue;
F_127 ( & V_1 -> V_66 , V_67 , V_225 , V_117 ) ;
F_123 ( V_1 , V_67 ) ;
if ( ! V_67 -> V_69 )
F_6 ( V_1 , V_67 ) ;
if ( V_221 )
F_117 ( V_221 , 1 ) ;
}
}
void F_129 ( struct V_160 * V_158 , struct V_220 * V_221 )
{
bool V_117 ;
if ( V_158 && V_10 . V_117 && ! V_10 . V_235 )
V_117 = V_158 -> V_236 . V_237 & V_238 ;
else
V_117 = V_10 . V_117 ;
F_128 ( F_54 ( V_158 ) , V_221 , V_117 , NULL ) ;
}
void F_130 ( struct V_1 * V_1 , struct V_220 * V_221 )
{
F_128 ( V_1 , V_221 , V_10 . V_117 , NULL ) ;
}
void F_131 ( struct V_1 * V_1 , struct V_220 * V_221 ,
T_8 V_232 )
{
F_128 ( V_1 , V_221 , V_10 . V_117 , V_232 ) ;
}
static bool F_132 ( struct V_14 * V_85 , enum V_239 V_240 )
{
if ( V_85 -> V_96 || V_240 == V_241 )
return false ;
if ( V_85 -> V_242 || V_240 == V_243 )
return true ;
return false ;
}
struct V_64 * F_133 ( struct V_64 * V_98 )
{
struct V_14 * V_85 = F_12 ( V_98 , struct V_14 , V_64 ) ;
while ( F_132 ( V_85 , V_244 ) ) {
V_98 = F_134 ( & V_85 -> V_99 ) ;
V_85 = F_12 ( V_98 , struct V_14 , V_64 ) ;
}
return V_98 ;
}
struct V_64 * F_135 ( struct V_64 * V_98 , enum V_239 V_240 )
{
struct V_14 * V_85 = F_12 ( V_98 , struct V_14 , V_64 ) ;
if ( F_132 ( V_85 , V_240 ) )
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
struct V_64 * F_136 ( struct V_64 * V_98 )
{
struct V_14 * V_85 = F_12 ( V_98 , struct V_14 , V_64 ) ;
V_98 = F_137 ( V_98 ) ;
if ( V_98 )
return F_133 ( V_98 ) ;
V_85 = V_85 -> V_103 ;
if ( V_85 == NULL )
return NULL ;
return & V_85 -> V_64 ;
}
bool F_138 ( struct V_14 * V_85 , float V_245 )
{
struct V_64 * V_98 ;
struct V_14 * V_97 ;
float V_246 ;
if ( V_85 -> V_96 )
return false ;
V_98 = F_11 ( & V_85 -> V_99 ) ;
V_97 = F_12 ( V_98 , struct V_14 , V_64 ) ;
while ( V_98 && V_97 -> V_69 ) {
V_98 = F_13 ( V_98 ) ;
V_97 = F_12 ( V_98 , struct V_14 , V_64 ) ;
}
if ( V_98 )
V_246 = F_139 ( V_97 ) ;
else
V_246 = 0 ;
return V_98 && V_246 >= V_245 ;
}
static void F_140 ( struct V_1 * V_1 , struct V_14 * V_15 ,
enum V_197 V_247 )
{
V_15 -> V_69 &= ~ ( 1 << V_247 ) ;
if ( V_10 . V_121 ) {
struct V_14 * V_27 = V_15 -> V_103 ;
while ( V_27 ) {
F_16 ( & V_27 -> V_87 , & V_15 -> V_87 ) ;
V_27 -> V_69 &= ~ ( 1 << V_247 ) ;
if ( V_27 -> V_69 )
goto V_65;
V_27 -> V_242 = false ;
V_27 -> V_248 = false ;
V_27 -> V_249 = 0 ;
V_27 -> V_250 = 0 ;
V_65:
V_27 = V_27 -> V_103 ;
}
}
if ( V_15 -> V_69 )
return;
V_15 -> V_242 = false ;
V_15 -> V_248 = false ;
V_15 -> V_249 = 0 ;
V_15 -> V_250 = 0 ;
V_1 -> V_93 . V_251 += V_15 -> V_87 . V_82 ;
F_122 ( V_1 , V_15 ) ;
F_6 ( V_1 , V_15 ) ;
}
static bool F_111 ( struct V_1 * V_1 ,
struct V_14 * V_85 )
{
if ( V_1 -> V_252 != NULL &&
( V_85 -> V_17 . V_26 == NULL || V_85 -> V_17 . V_26 -> V_7 != V_1 -> V_252 ) ) {
V_85 -> V_69 |= ( 1 << V_204 ) ;
return true ;
}
return false ;
}
static bool F_112 ( struct V_1 * V_1 ,
struct V_14 * V_85 )
{
if ( V_1 -> V_253 != NULL &&
V_85 -> V_23 != V_1 -> V_253 ) {
V_85 -> V_69 |= ( 1 << V_200 ) ;
return true ;
}
return false ;
}
static bool F_113 ( struct V_1 * V_1 ,
struct V_14 * V_85 )
{
if ( V_1 -> V_254 != NULL &&
( ! V_85 -> V_17 . V_18 || strstr ( V_85 -> V_17 . V_18 -> V_255 ,
V_1 -> V_254 ) == NULL ) ) {
V_85 -> V_69 |= ( 1 << V_205 ) ;
return true ;
}
return false ;
}
static bool F_114 ( struct V_1 * V_1 ,
struct V_14 * V_85 )
{
if ( ( V_1 -> V_256 > - 1 ) &&
( V_85 -> V_150 != V_1 -> V_256 ) ) {
V_85 -> V_69 |= ( 1 << V_209 ) ;
return true ;
}
return false ;
}
static void F_141 ( struct V_1 * V_1 , int type , T_9 V_247 )
{
struct V_64 * V_257 ;
V_1 -> V_93 . V_251 = 0 ;
F_120 ( V_1 ) ;
F_4 ( V_1 ) ;
for ( V_257 = F_11 ( & V_1 -> V_66 ) ; V_257 ; V_257 = F_13 ( V_257 ) ) {
struct V_14 * V_15 = F_12 ( V_257 , struct V_14 , V_64 ) ;
if ( V_247 ( V_1 , V_15 ) )
continue;
F_140 ( V_1 , V_15 , type ) ;
}
}
static void F_142 ( struct V_100 * V_212 , struct V_14 * V_85 )
{
struct V_64 * * V_139 = & V_212 -> V_64 ;
struct V_64 * V_27 = NULL ;
struct V_14 * T_6 ;
struct V_100 V_258 = V_226 ;
struct V_64 * V_257 ;
while ( * V_139 != NULL ) {
V_27 = * V_139 ;
T_6 = F_12 ( V_27 , struct V_14 , V_64 ) ;
if ( F_118 ( V_85 , T_6 ) > 0 )
V_139 = & ( * V_139 ) -> V_142 ;
else
V_139 = & ( * V_139 ) -> V_143 ;
}
F_43 ( & V_85 -> V_64 , V_27 , V_139 ) ;
F_44 ( & V_85 -> V_64 , V_212 ) ;
if ( V_85 -> V_96 || V_85 -> V_69 )
return;
V_257 = F_11 ( & V_85 -> V_99 ) ;
while ( V_257 ) {
struct V_14 * V_15 = F_12 ( V_257 , struct V_14 , V_64 ) ;
V_257 = F_13 ( V_257 ) ;
F_22 ( & V_15 -> V_64 , & V_85 -> V_99 ) ;
F_142 ( & V_258 , V_15 ) ;
}
V_85 -> V_99 = V_258 ;
}
static void F_143 ( struct V_1 * V_1 , int type , const void * V_176 )
{
struct V_64 * V_257 ;
struct V_100 V_258 = V_226 ;
V_1 -> V_93 . V_251 = 0 ;
F_120 ( V_1 ) ;
F_4 ( V_1 ) ;
V_257 = F_11 ( & V_1 -> V_66 ) ;
while ( V_257 ) {
struct V_14 * V_15 = F_12 ( V_257 , struct V_14 , V_64 ) ;
int V_216 ;
V_216 = F_144 ( V_15 , type , V_176 ) ;
if ( V_216 < 0 ) {
memset ( & V_15 -> V_87 , 0 , sizeof( V_15 -> V_87 ) ) ;
V_15 -> V_69 |= ( 1 << type ) ;
V_257 = F_135 ( & V_15 -> V_64 , V_243 ) ;
}
else if ( V_216 == 1 ) {
V_15 -> V_69 |= ( 1 << type ) ;
V_257 = F_135 ( & V_15 -> V_64 , V_241 ) ;
}
else {
F_140 ( V_1 , V_15 , type ) ;
V_257 = F_135 ( & V_15 -> V_64 , V_241 ) ;
}
}
F_124 ( V_1 ) ;
V_257 = F_11 ( & V_1 -> V_66 ) ;
while ( V_257 ) {
struct V_14 * V_15 = F_12 ( V_257 , struct V_14 , V_64 ) ;
V_257 = F_13 ( V_257 ) ;
F_22 ( & V_15 -> V_64 , & V_1 -> V_66 ) ;
F_142 ( & V_258 , V_15 ) ;
}
V_1 -> V_66 = V_258 ;
}
void F_145 ( struct V_1 * V_1 )
{
if ( V_10 . V_121 )
F_143 ( V_1 , V_200 ,
V_1 -> V_253 ) ;
else
F_141 ( V_1 , V_200 ,
F_112 ) ;
}
void F_146 ( struct V_1 * V_1 )
{
if ( V_10 . V_121 )
F_143 ( V_1 , V_204 ,
V_1 -> V_252 ) ;
else
F_141 ( V_1 , V_204 ,
F_111 ) ;
}
void F_147 ( struct V_1 * V_1 )
{
if ( V_10 . V_121 )
F_143 ( V_1 , V_205 ,
V_1 -> V_254 ) ;
else
F_141 ( V_1 , V_205 ,
F_113 ) ;
}
void F_148 ( struct V_1 * V_1 )
{
if ( V_10 . V_121 )
F_143 ( V_1 , V_209 ,
& V_1 -> V_256 ) ;
else
F_141 ( V_1 , V_209 ,
F_114 ) ;
}
void F_149 ( struct V_259 * V_93 , T_10 type )
{
++ V_93 -> V_82 [ 0 ] ;
++ V_93 -> V_82 [ type ] ;
}
void F_150 ( struct V_1 * V_1 , T_10 type )
{
F_149 ( & V_1 -> V_93 , type ) ;
}
void F_56 ( struct V_1 * V_1 , bool V_69 )
{
F_149 ( & V_1 -> V_93 , V_260 ) ;
if ( ! V_69 )
V_1 -> V_93 . V_251 ++ ;
}
static struct V_14 * F_151 ( struct V_1 * V_1 ,
struct V_14 * V_261 )
{
struct V_100 * V_212 ;
struct V_64 * * V_139 ;
struct V_64 * V_27 = NULL ;
struct V_14 * V_85 ;
T_5 V_140 ;
if ( F_21 ( V_1 , V_105 ) )
V_212 = & V_1 -> V_106 ;
else
V_212 = V_1 -> V_107 ;
V_139 = & V_212 -> V_64 ;
while ( * V_139 != NULL ) {
V_27 = * V_139 ;
V_85 = F_12 ( V_27 , struct V_14 , V_108 ) ;
V_140 = F_83 ( V_85 , V_261 ) ;
if ( ! V_140 )
goto V_141;
if ( V_140 < 0 )
V_139 = & ( * V_139 ) -> V_142 ;
else
V_139 = & ( * V_139 ) -> V_143 ;
}
V_85 = F_37 ( V_261 , true ) ;
if ( V_85 ) {
memset ( & V_85 -> V_87 , 0 , sizeof( V_85 -> V_87 ) ) ;
V_85 -> V_1 = V_1 ;
if ( V_10 . V_89 )
memset ( V_85 -> V_90 , 0 , sizeof( V_85 -> V_87 ) ) ;
F_43 ( & V_85 -> V_108 , V_27 , V_139 ) ;
F_44 ( & V_85 -> V_108 , V_212 ) ;
F_123 ( V_1 , V_85 ) ;
V_85 -> V_262 = true ;
}
V_141:
return V_85 ;
}
static struct V_14 * F_152 ( struct V_1 * V_1 ,
struct V_14 * V_85 )
{
struct V_64 * V_67 ;
if ( F_21 ( V_1 , V_105 ) )
V_67 = V_1 -> V_106 . V_64 ;
else
V_67 = V_1 -> V_107 -> V_64 ;
while ( V_67 ) {
struct V_14 * T_6 = F_12 ( V_67 , struct V_14 , V_108 ) ;
T_5 V_140 = F_83 ( T_6 , V_85 ) ;
if ( V_140 < 0 )
V_67 = V_67 -> V_142 ;
else if ( V_140 > 0 )
V_67 = V_67 -> V_143 ;
else
return T_6 ;
}
return NULL ;
}
void F_153 ( struct V_1 * V_263 , struct V_1 * V_264 )
{
struct V_100 * V_212 ;
struct V_64 * V_257 ;
struct V_14 * V_265 , * V_261 ;
if ( F_21 ( V_263 , V_105 ) )
V_212 = & V_263 -> V_106 ;
else
V_212 = V_263 -> V_107 ;
for ( V_257 = F_11 ( V_212 ) ; V_257 ; V_257 = F_13 ( V_257 ) ) {
V_265 = F_12 ( V_257 , struct V_14 , V_108 ) ;
V_261 = F_152 ( V_264 , V_265 ) ;
if ( V_261 )
F_154 ( V_261 , V_265 ) ;
}
}
int F_155 ( struct V_1 * V_263 , struct V_1 * V_264 )
{
struct V_100 * V_212 ;
struct V_64 * V_257 ;
struct V_14 * V_265 , * V_261 ;
if ( F_21 ( V_264 , V_105 ) )
V_212 = & V_264 -> V_106 ;
else
V_212 = V_264 -> V_107 ;
for ( V_257 = F_11 ( V_212 ) ; V_257 ; V_257 = F_13 ( V_257 ) ) {
V_265 = F_12 ( V_257 , struct V_14 , V_108 ) ;
if ( ! F_156 ( V_265 ) ) {
V_261 = F_151 ( V_263 , V_265 ) ;
if ( V_261 == NULL )
return - 1 ;
F_154 ( V_265 , V_261 ) ;
}
}
return 0 ;
}
void F_157 ( struct V_163 * V_266 , struct V_137 * V_138 ,
struct V_147 * V_148 , bool V_267 )
{
struct V_29 * V_145 ;
if ( V_266 && V_266 -> V_164 && V_266 -> V_66 [ 0 ] . V_167 . V_168 ) {
int V_165 ;
V_145 = F_59 ( V_148 , V_138 ) ;
if ( V_145 ) {
struct V_268 * V_269 = NULL ;
for ( V_165 = V_266 -> V_164 - 1 ; V_165 >= 0 ; V_165 -- ) {
F_158 ( & V_145 [ V_165 ] . V_30 ,
V_267 ? NULL : V_269 ,
V_145 [ V_165 ] . V_167 . V_168 ) ;
V_269 = & V_145 [ V_165 ] . V_33 ;
}
free ( V_145 ) ;
}
}
}
T_3 F_159 ( struct V_270 * V_271 , T_11 * V_272 )
{
struct V_160 * V_265 ;
T_3 V_216 = 0 ;
F_160 (evlist, pos) {
V_216 += fprintf ( V_272 , L_3 , F_161 ( V_265 ) ) ;
V_216 += F_162 ( & F_54 ( V_265 ) -> V_93 , V_272 ) ;
}
return V_216 ;
}
T_2 F_163 ( struct V_1 * V_1 )
{
return V_10 . V_234 ? V_1 -> V_93 . V_95 :
V_1 -> V_93 . V_94 ;
}
int F_164 ( const struct V_273 * T_12 V_155 ,
const char * V_176 , int T_13 V_155 )
{
if ( ! strcmp ( V_176 , L_4 ) )
V_10 . V_234 = true ;
else if ( ! strcmp ( V_176 , L_5 ) )
V_10 . V_234 = false ;
else
return - 1 ;
return 0 ;
}
int F_165 ( const char * V_274 , const char * V_275 )
{
if ( ! strcmp ( V_274 , L_6 ) )
return F_164 ( NULL , V_275 , 0 ) ;
return 0 ;
}
int F_166 ( struct V_1 * V_1 , struct V_213 * V_193 )
{
memset ( V_1 , 0 , sizeof( * V_1 ) ) ;
V_1 -> V_219 [ 0 ] = V_1 -> V_219 [ 1 ] = V_226 ;
V_1 -> V_107 = & V_1 -> V_219 [ 0 ] ;
V_1 -> V_106 = V_226 ;
V_1 -> V_66 = V_226 ;
F_167 ( & V_1 -> V_218 , NULL ) ;
V_1 -> V_256 = - 1 ;
V_1 -> V_193 = V_193 ;
F_32 ( & V_1 -> V_276 ) ;
return 0 ;
}
static void F_168 ( struct V_100 * V_212 )
{
struct V_64 * V_98 ;
struct V_14 * V_85 ;
while ( ! F_169 ( V_212 ) ) {
V_98 = F_11 ( V_212 ) ;
F_22 ( V_98 , V_212 ) ;
V_85 = F_12 ( V_98 , struct V_14 , V_108 ) ;
F_23 ( V_85 ) ;
}
}
static void F_170 ( struct V_1 * V_1 )
{
F_25 ( V_1 ) ;
F_168 ( & V_1 -> V_219 [ 0 ] ) ;
F_168 ( & V_1 -> V_219 [ 1 ] ) ;
F_168 ( & V_1 -> V_106 ) ;
}
static void F_171 ( struct V_160 * V_158 )
{
struct V_1 * V_1 = F_54 ( V_158 ) ;
struct V_186 * V_187 , * V_265 ;
struct V_214 * V_98 , * V_277 ;
F_170 ( V_1 ) ;
F_172 (node, tmp, &hists->hpp_formats, list) {
F_173 (&node->hpp, fmt, pos) {
F_174 ( & V_187 -> V_192 ) ;
free ( V_187 ) ;
}
F_174 ( & V_98 -> V_192 ) ;
free ( V_98 ) ;
}
}
static int F_175 ( struct V_160 * V_158 )
{
struct V_1 * V_1 = F_54 ( V_158 ) ;
F_166 ( V_1 , & V_213 ) ;
return 0 ;
}
int F_176 ( void )
{
int V_127 = F_177 ( sizeof( struct V_278 ) ,
F_175 ,
F_171 ) ;
if ( V_127 )
fputs ( L_7 , V_279 ) ;
return V_127 ;
}
void F_178 ( struct V_213 * V_192 )
{
F_32 ( & V_192 -> V_194 ) ;
F_32 ( & V_192 -> V_280 ) ;
}
