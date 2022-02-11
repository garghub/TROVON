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
if ( V_15 -> V_55 ) {
V_5 = F_9 ( strlen ( V_15 -> V_55 ) , strlen ( V_56 . V_57 ) ) ;
F_3 ( V_1 , V_58 , V_5 ) ;
}
if ( V_15 -> V_59 )
F_3 ( V_1 , V_60 , strlen ( V_15 -> V_59 ) ) ;
if ( V_15 -> V_61 )
F_3 ( V_1 , V_62 ,
F_10 () ) ;
if ( V_15 -> V_63 )
F_3 ( V_1 , V_64 , strlen ( V_15 -> V_63 ) ) ;
}
void F_11 ( struct V_1 * V_1 , int V_65 )
{
struct V_66 * V_67 = F_12 ( & V_1 -> V_68 ) ;
struct V_14 * V_69 ;
int V_70 = 0 ;
F_4 ( V_1 ) ;
while ( V_67 && V_70 ++ < V_65 ) {
V_69 = F_13 ( V_67 , struct V_14 , V_66 ) ;
if ( ! V_69 -> V_71 )
F_6 ( V_1 , V_69 ) ;
V_67 = F_14 ( & V_69 -> V_66 ) ;
}
}
static void F_15 ( struct V_72 * V_72 ,
unsigned int V_73 , T_2 V_74 )
{
switch ( V_73 ) {
case V_75 :
V_72 -> V_76 += V_74 ;
break;
case V_77 :
V_72 -> V_78 += V_74 ;
break;
case V_79 :
V_72 -> V_80 += V_74 ;
break;
case V_81 :
V_72 -> V_82 += V_74 ;
break;
default:
break;
}
}
static void F_16 ( struct V_72 * V_72 , T_2 V_74 ,
T_2 V_83 )
{
V_72 -> V_74 += V_74 ;
V_72 -> V_83 += V_83 ;
V_72 -> V_84 += 1 ;
}
static void F_17 ( struct V_72 * V_85 , struct V_72 * V_86 )
{
V_85 -> V_74 += V_86 -> V_74 ;
V_85 -> V_76 += V_86 -> V_76 ;
V_85 -> V_78 += V_86 -> V_78 ;
V_85 -> V_80 += V_86 -> V_80 ;
V_85 -> V_82 += V_86 -> V_82 ;
V_85 -> V_84 += V_86 -> V_84 ;
V_85 -> V_83 += V_86 -> V_83 ;
}
static void F_18 ( struct V_72 * V_72 )
{
V_72 -> V_74 = ( V_72 -> V_74 * 7 ) / 8 ;
V_72 -> V_84 = ( V_72 -> V_84 * 7 ) / 8 ;
}
static bool F_19 ( struct V_1 * V_1 , struct V_14 * V_87 )
{
T_2 V_88 = V_87 -> V_89 . V_74 ;
T_2 V_90 ;
if ( V_88 == 0 )
return true ;
F_18 ( & V_87 -> V_89 ) ;
if ( V_10 . V_91 )
F_18 ( V_87 -> V_92 ) ;
F_20 ( V_87 -> V_93 ) ;
V_90 = V_88 - V_87 -> V_89 . V_74 ;
if ( ! V_87 -> V_94 ) {
V_1 -> V_95 . V_96 -= V_90 ;
if ( ! V_87 -> V_71 )
V_1 -> V_95 . V_97 -= V_90 ;
}
if ( ! V_87 -> V_98 ) {
struct V_14 * V_99 ;
struct V_66 * V_100 = F_12 ( & V_87 -> V_101 ) ;
while ( V_100 ) {
V_99 = F_13 ( V_100 , struct V_14 , V_66 ) ;
V_100 = F_14 ( V_100 ) ;
if ( F_19 ( V_1 , V_99 ) )
F_21 ( V_1 , V_99 ) ;
}
}
return V_87 -> V_89 . V_74 == 0 ;
}
static void F_21 ( struct V_1 * V_1 , struct V_14 * V_87 )
{
struct V_102 * V_103 ;
struct V_102 * V_104 ;
if ( V_87 -> V_105 ) {
V_103 = & V_87 -> V_105 -> V_106 ;
V_104 = & V_87 -> V_105 -> V_101 ;
} else {
if ( F_22 ( V_1 , V_107 ) )
V_103 = & V_1 -> V_108 ;
else
V_103 = V_1 -> V_109 ;
V_104 = & V_1 -> V_68 ;
}
F_23 ( & V_87 -> V_110 , V_103 ) ;
F_23 ( & V_87 -> V_66 , V_104 ) ;
-- V_1 -> V_111 ;
if ( ! V_87 -> V_71 )
-- V_1 -> V_112 ;
F_24 ( V_87 ) ;
}
void F_25 ( struct V_1 * V_1 , bool V_113 , bool V_114 )
{
struct V_66 * V_67 = F_12 ( & V_1 -> V_68 ) ;
struct V_14 * V_69 ;
while ( V_67 ) {
V_69 = F_13 ( V_67 , struct V_14 , V_66 ) ;
V_67 = F_14 ( & V_69 -> V_66 ) ;
if ( ( ( V_113 && V_69 -> V_115 == '.' ) ||
( V_114 && V_69 -> V_115 != '.' ) ||
F_19 ( V_1 , V_69 ) ) ) {
F_21 ( V_1 , V_69 ) ;
}
}
}
void F_26 ( struct V_1 * V_1 )
{
struct V_66 * V_67 = F_12 ( & V_1 -> V_68 ) ;
struct V_14 * V_69 ;
while ( V_67 ) {
V_69 = F_13 ( V_67 , struct V_14 , V_66 ) ;
V_67 = F_14 ( & V_69 -> V_66 ) ;
F_21 ( V_1 , V_69 ) ;
}
}
static int F_27 ( struct V_14 * V_87 ,
struct V_14 * V_116 ,
bool V_117 )
{
* V_87 = * V_116 ;
if ( V_10 . V_91 ) {
V_87 -> V_92 = malloc ( sizeof( V_87 -> V_89 ) ) ;
if ( V_87 -> V_92 == NULL )
return - V_118 ;
memcpy ( V_87 -> V_92 , & V_87 -> V_89 , sizeof( V_87 -> V_89 ) ) ;
if ( ! V_117 )
memset ( & V_87 -> V_89 , 0 , sizeof( V_87 -> V_89 ) ) ;
}
F_28 ( V_87 -> V_17 . V_26 ) ;
if ( V_87 -> V_29 ) {
V_87 -> V_29 = malloc ( sizeof( * V_87 -> V_29 ) ) ;
if ( V_87 -> V_29 == NULL ) {
F_29 ( V_87 -> V_17 . V_26 ) ;
free ( V_87 -> V_92 ) ;
return - V_118 ;
}
memcpy ( V_87 -> V_29 , V_116 -> V_29 ,
sizeof( * V_87 -> V_29 ) ) ;
F_28 ( V_87 -> V_29 -> V_30 . V_26 ) ;
F_28 ( V_87 -> V_29 -> V_33 . V_26 ) ;
}
if ( V_87 -> V_40 ) {
F_28 ( V_87 -> V_40 -> V_44 . V_26 ) ;
F_28 ( V_87 -> V_40 -> V_41 . V_26 ) ;
}
if ( V_10 . V_119 )
F_30 ( V_87 -> V_93 ) ;
if ( V_87 -> V_120 ) {
V_87 -> V_120 = F_31 ( V_87 -> V_120 , V_87 -> V_121 ) ;
if ( V_87 -> V_120 == NULL ) {
F_32 ( V_87 -> V_17 . V_26 ) ;
if ( V_87 -> V_29 ) {
F_32 ( V_87 -> V_29 -> V_30 . V_26 ) ;
F_32 ( V_87 -> V_29 -> V_33 . V_26 ) ;
free ( V_87 -> V_29 ) ;
}
if ( V_87 -> V_40 ) {
F_32 ( V_87 -> V_40 -> V_44 . V_26 ) ;
F_32 ( V_87 -> V_40 -> V_41 . V_26 ) ;
}
free ( V_87 -> V_92 ) ;
return - V_118 ;
}
}
F_33 ( & V_87 -> V_122 . V_100 ) ;
F_34 ( V_87 -> V_23 ) ;
V_87 -> V_106 = V_123 ;
V_87 -> V_101 = V_123 ;
if ( ! V_10 . V_124 )
V_87 -> V_98 = true ;
return 0 ;
}
static void * F_35 ( T_3 V_125 )
{
return F_36 ( V_125 + sizeof( struct V_14 ) ) ;
}
static void F_37 ( void * V_126 )
{
free ( V_126 ) ;
}
static struct V_14 * F_38 ( struct V_14 * V_116 ,
bool V_117 )
{
struct V_127 * V_128 = V_116 -> V_128 ;
T_3 V_129 = 0 ;
struct V_14 * V_87 ;
int V_130 = 0 ;
if ( ! V_128 )
V_128 = V_116 -> V_128 = & V_131 ;
if ( V_10 . V_119 )
V_129 = sizeof( struct V_132 ) ;
V_87 = V_128 -> V_133 ( V_129 ) ;
if ( V_87 ) {
V_130 = F_27 ( V_87 , V_116 , V_117 ) ;
if ( V_130 ) {
V_128 -> free ( V_87 ) ;
V_87 = NULL ;
}
}
return V_87 ;
}
static T_4 F_39 ( const struct V_134 * V_27 )
{
if ( V_10 . V_135 && V_27 == NULL )
return 1 << V_136 ;
return 0 ;
}
static void F_40 ( struct V_14 * V_87 , T_2 V_74 )
{
if ( ! V_10 . V_119 )
return;
V_87 -> V_1 -> V_137 += V_74 ;
if ( ! V_87 -> V_71 )
V_87 -> V_1 -> V_138 += V_74 ;
}
static struct V_14 * F_41 ( struct V_1 * V_1 ,
struct V_14 * V_139 ,
struct V_140 * V_141 ,
bool V_117 )
{
struct V_66 * * V_142 ;
struct V_66 * V_27 = NULL ;
struct V_14 * V_87 ;
T_5 V_143 ;
T_2 V_74 = V_139 -> V_89 . V_74 ;
T_2 V_83 = V_139 -> V_89 . V_83 ;
V_142 = & V_1 -> V_109 -> V_66 ;
while ( * V_142 != NULL ) {
V_27 = * V_142 ;
V_87 = F_13 ( V_27 , struct V_14 , V_110 ) ;
V_143 = F_42 ( V_87 , V_139 ) ;
if ( ! V_143 ) {
if ( V_117 ) {
F_16 ( & V_87 -> V_89 , V_74 , V_83 ) ;
F_40 ( V_87 , V_74 ) ;
}
if ( V_10 . V_91 )
F_16 ( V_87 -> V_92 , V_74 , V_83 ) ;
F_43 ( & V_139 -> V_40 ) ;
if ( V_87 -> V_17 . V_26 != V_139 -> V_17 . V_26 ) {
F_32 ( V_87 -> V_17 . V_26 ) ;
V_87 -> V_17 . V_26 = F_28 ( V_139 -> V_17 . V_26 ) ;
}
goto V_144;
}
if ( V_143 < 0 )
V_142 = & ( * V_142 ) -> V_145 ;
else
V_142 = & ( * V_142 ) -> V_146 ;
}
V_87 = F_38 ( V_139 , V_117 ) ;
if ( ! V_87 )
return NULL ;
if ( V_117 )
F_40 ( V_87 , V_74 ) ;
V_1 -> V_111 ++ ;
F_44 ( & V_87 -> V_110 , V_27 , V_142 ) ;
F_45 ( & V_87 -> V_110 , V_1 -> V_109 ) ;
V_144:
if ( V_117 )
F_15 ( & V_87 -> V_89 , V_141 -> V_73 , V_74 ) ;
if ( V_10 . V_91 )
F_15 ( V_87 -> V_92 , V_141 -> V_73 , V_74 ) ;
return V_87 ;
}
static struct V_14 *
F_46 ( struct V_1 * V_1 ,
struct V_140 * V_141 ,
struct V_134 * V_147 ,
struct V_29 * V_148 ,
struct V_40 * V_149 ,
struct V_150 * V_151 ,
bool V_117 ,
struct V_127 * V_128 )
{
struct V_14 V_139 = {
. V_23 = V_141 -> V_23 ,
. V_152 = F_47 ( V_141 -> V_23 ) ,
. V_17 = {
. V_26 = V_141 -> V_26 ,
. V_18 = V_141 -> V_18 ,
} ,
. V_153 = V_141 -> V_153 ,
. V_154 = V_141 -> V_154 ,
. V_73 = V_141 -> V_73 ,
. V_155 = V_141 -> V_156 ,
. V_115 = V_141 -> V_115 ,
. V_89 = {
. V_84 = 1 ,
. V_74 = V_151 -> V_74 ,
. V_83 = V_151 -> V_83 ,
} ,
. V_27 = V_147 ,
. V_71 = F_39 ( V_147 ) | V_141 -> V_71 ,
. V_1 = V_1 ,
. V_29 = V_148 ,
. V_40 = V_149 ,
. V_61 = V_151 -> V_61 ,
. V_120 = V_151 -> V_120 ,
. V_121 = V_151 -> V_121 ,
. V_128 = V_128 ,
} ;
return F_41 ( V_1 , & V_139 , V_141 , V_117 ) ;
}
struct V_14 * F_48 ( struct V_1 * V_1 ,
struct V_140 * V_141 ,
struct V_134 * V_147 ,
struct V_29 * V_148 ,
struct V_40 * V_149 ,
struct V_150 * V_151 ,
bool V_117 )
{
return F_46 ( V_1 , V_141 , V_147 , V_148 , V_149 ,
V_151 , V_117 , NULL ) ;
}
struct V_14 * F_49 ( struct V_1 * V_1 ,
struct V_127 * V_128 ,
struct V_140 * V_141 ,
struct V_134 * V_147 ,
struct V_29 * V_148 ,
struct V_40 * V_149 ,
struct V_150 * V_151 ,
bool V_117 )
{
return F_46 ( V_1 , V_141 , V_147 , V_148 , V_149 ,
V_151 , V_117 , V_128 ) ;
}
static int
F_50 ( struct V_157 * T_6 V_158 ,
struct V_140 * V_141 V_158 )
{
return 0 ;
}
static int
F_51 ( struct V_157 * T_6 V_158 ,
struct V_140 * V_141 V_158 )
{
return 0 ;
}
static int
F_52 ( struct V_157 * T_6 , struct V_140 * V_141 )
{
struct V_150 * V_151 = T_6 -> V_151 ;
struct V_40 * V_149 ;
V_149 = F_53 ( V_151 , V_141 ) ;
if ( V_149 == NULL )
return - V_118 ;
T_6 -> V_159 = V_149 ;
return 0 ;
}
static int
F_54 ( struct V_157 * T_6 , struct V_140 * V_141 )
{
T_2 V_160 ;
struct V_40 * V_149 = T_6 -> V_159 ;
struct V_1 * V_1 = F_55 ( T_6 -> V_161 ) ;
struct V_150 * V_151 = T_6 -> V_151 ;
struct V_14 * V_87 ;
if ( V_149 == NULL )
return - V_162 ;
V_160 = V_151 -> V_83 ;
if ( ! V_160 )
V_160 = 1 ;
V_151 -> V_74 = V_160 ;
V_87 = F_48 ( V_1 , V_141 , T_6 -> V_27 , NULL , V_149 ,
V_151 , true ) ;
if ( ! V_87 )
return - V_118 ;
T_6 -> V_87 = V_87 ;
return 0 ;
}
static int
F_56 ( struct V_157 * T_6 ,
struct V_140 * V_141 V_158 )
{
struct V_163 * V_161 = T_6 -> V_161 ;
struct V_1 * V_1 = F_55 ( V_161 ) ;
struct V_14 * V_87 = T_6 -> V_87 ;
int V_130 = - V_162 ;
if ( V_87 == NULL )
goto V_144;
F_57 ( V_1 , V_87 -> V_71 ) ;
V_130 = F_58 ( V_87 , T_6 -> V_151 ) ;
V_144:
T_6 -> V_159 = NULL ;
T_6 -> V_87 = NULL ;
return V_130 ;
}
static int
F_59 ( struct V_157 * T_6 , struct V_140 * V_141 )
{
struct V_29 * V_148 ;
struct V_150 * V_151 = T_6 -> V_151 ;
V_148 = F_60 ( V_151 , V_141 ) ;
if ( ! V_148 )
return - V_118 ;
T_6 -> V_164 = 0 ;
T_6 -> V_165 = V_151 -> V_166 -> V_167 ;
T_6 -> V_159 = V_148 ;
return 0 ;
}
static int
F_61 ( struct V_157 * T_6 ,
struct V_140 * V_141 V_158 )
{
T_6 -> V_87 = NULL ;
return 0 ;
}
static int
F_62 ( struct V_157 * T_6 , struct V_140 * V_141 )
{
struct V_29 * V_148 = T_6 -> V_159 ;
int V_168 = T_6 -> V_164 ;
if ( V_148 == NULL )
return 0 ;
if ( T_6 -> V_164 >= T_6 -> V_165 )
return 0 ;
V_141 -> V_26 = V_148 [ V_168 ] . V_33 . V_26 ;
V_141 -> V_18 = V_148 [ V_168 ] . V_33 . V_18 ;
V_141 -> V_156 = V_148 [ V_168 ] . V_33 . V_156 ;
return 1 ;
}
static int
F_63 ( struct V_157 * T_6 , struct V_140 * V_141 )
{
struct V_29 * V_148 ;
struct V_163 * V_161 = T_6 -> V_161 ;
struct V_1 * V_1 = F_55 ( V_161 ) ;
struct V_150 * V_151 = T_6 -> V_151 ;
struct V_14 * V_87 = NULL ;
int V_168 = T_6 -> V_164 ;
int V_130 = 0 ;
V_148 = T_6 -> V_159 ;
if ( T_6 -> V_169 && ! ( V_148 [ V_168 ] . V_30 . V_18 && V_148 [ V_168 ] . V_33 . V_18 ) )
goto V_144;
V_151 -> V_74 = 1 ;
V_151 -> V_83 = V_148 -> V_170 . V_171 ? V_148 -> V_170 . V_171 : 1 ;
V_87 = F_48 ( V_1 , V_141 , T_6 -> V_27 , & V_148 [ V_168 ] , NULL ,
V_151 , true ) ;
if ( V_87 == NULL )
return - V_118 ;
F_57 ( V_1 , V_87 -> V_71 ) ;
V_144:
T_6 -> V_87 = V_87 ;
T_6 -> V_164 ++ ;
return V_130 ;
}
static int
F_64 ( struct V_157 * T_6 ,
struct V_140 * V_141 V_158 )
{
F_43 ( & T_6 -> V_159 ) ;
T_6 -> V_87 = NULL ;
return T_6 -> V_164 >= T_6 -> V_165 ? 0 : - 1 ;
}
static int
F_65 ( struct V_157 * T_6 V_158 ,
struct V_140 * V_141 V_158 )
{
return 0 ;
}
static int
F_66 ( struct V_157 * T_6 , struct V_140 * V_141 )
{
struct V_163 * V_161 = T_6 -> V_161 ;
struct V_150 * V_151 = T_6 -> V_151 ;
struct V_14 * V_87 ;
V_87 = F_48 ( F_55 ( V_161 ) , V_141 , T_6 -> V_27 , NULL , NULL ,
V_151 , true ) ;
if ( V_87 == NULL )
return - V_118 ;
T_6 -> V_87 = V_87 ;
return 0 ;
}
static int
F_67 ( struct V_157 * T_6 ,
struct V_140 * V_141 V_158 )
{
struct V_14 * V_87 = T_6 -> V_87 ;
struct V_163 * V_161 = T_6 -> V_161 ;
struct V_150 * V_151 = T_6 -> V_151 ;
if ( V_87 == NULL )
return 0 ;
T_6 -> V_87 = NULL ;
F_57 ( F_55 ( V_161 ) , V_87 -> V_71 ) ;
return F_58 ( V_87 , V_151 ) ;
}
static int
F_68 ( struct V_157 * T_6 ,
struct V_140 * V_141 V_158 )
{
struct V_14 * * V_172 ;
F_69 ( & V_173 ) ;
V_172 = malloc ( sizeof( * V_172 ) * ( T_6 -> V_174 + 1 ) ) ;
if ( V_172 == NULL )
return - V_118 ;
T_6 -> V_159 = V_172 ;
T_6 -> V_164 = 0 ;
return 0 ;
}
static int
F_70 ( struct V_157 * T_6 ,
struct V_140 * V_141 )
{
struct V_163 * V_161 = T_6 -> V_161 ;
struct V_1 * V_1 = F_55 ( V_161 ) ;
struct V_150 * V_151 = T_6 -> V_151 ;
struct V_14 * * V_172 = T_6 -> V_159 ;
struct V_14 * V_87 ;
int V_130 = 0 ;
V_87 = F_48 ( V_1 , V_141 , T_6 -> V_27 , NULL , NULL ,
V_151 , true ) ;
if ( V_87 == NULL )
return - V_118 ;
T_6 -> V_87 = V_87 ;
V_172 [ T_6 -> V_164 ++ ] = V_87 ;
F_58 ( V_87 , V_151 ) ;
F_69 ( & V_173 ) ;
F_57 ( V_1 , V_87 -> V_71 ) ;
return V_130 ;
}
static int
F_71 ( struct V_157 * T_6 ,
struct V_140 * V_141 )
{
struct V_175 * V_100 ;
V_100 = F_72 ( & V_173 ) ;
if ( V_100 == NULL )
return 0 ;
return F_73 ( V_141 , V_100 , T_6 -> V_169 ) ;
}
static int
F_74 ( struct V_157 * T_6 ,
struct V_140 * V_141 )
{
struct V_163 * V_161 = T_6 -> V_161 ;
struct V_150 * V_151 = T_6 -> V_151 ;
struct V_14 * * V_172 = T_6 -> V_159 ;
struct V_14 * V_87 ;
struct V_14 V_176 = {
. V_1 = F_55 ( V_161 ) ,
. V_154 = V_141 -> V_154 ,
. V_23 = V_141 -> V_23 ,
. V_152 = F_47 ( V_141 -> V_23 ) ,
. V_155 = V_141 -> V_156 ,
. V_17 = {
. V_26 = V_141 -> V_26 ,
. V_18 = V_141 -> V_18 ,
} ,
. V_27 = T_6 -> V_27 ,
. V_120 = V_151 -> V_120 ,
. V_121 = V_151 -> V_121 ,
} ;
int V_168 ;
struct V_173 V_177 ;
F_75 ( & V_177 , & V_173 ) ;
F_76 ( & V_173 ) ;
for ( V_168 = 0 ; V_168 < T_6 -> V_164 ; V_168 ++ ) {
if ( F_42 ( V_172 [ V_168 ] , & V_176 ) == 0 ) {
T_6 -> V_87 = NULL ;
return 0 ;
}
}
V_87 = F_48 ( F_55 ( V_161 ) , V_141 , T_6 -> V_27 , NULL , NULL ,
V_151 , false ) ;
if ( V_87 == NULL )
return - V_118 ;
T_6 -> V_87 = V_87 ;
V_172 [ T_6 -> V_164 ++ ] = V_87 ;
if ( V_10 . V_119 )
F_77 ( V_87 -> V_93 , & V_177 , V_151 -> V_74 ) ;
return 0 ;
}
static int
F_78 ( struct V_157 * T_6 ,
struct V_140 * V_141 V_158 )
{
F_43 ( & T_6 -> V_159 ) ;
T_6 -> V_87 = NULL ;
return 0 ;
}
int F_79 ( struct V_157 * T_6 , struct V_140 * V_141 ,
int V_178 , void * V_179 )
{
int V_130 , V_180 ;
V_130 = F_80 ( T_6 -> V_151 , & V_173 , & T_6 -> V_27 ,
T_6 -> V_161 , V_141 , V_178 ) ;
if ( V_130 )
return V_130 ;
T_6 -> V_174 = V_178 ;
V_130 = T_6 -> V_128 -> V_181 ( T_6 , V_141 ) ;
if ( V_130 )
goto V_144;
V_130 = T_6 -> V_128 -> V_182 ( T_6 , V_141 ) ;
if ( V_130 )
goto V_144;
if ( T_6 -> V_87 && T_6 -> V_183 ) {
V_130 = T_6 -> V_183 ( T_6 , V_141 , true , V_179 ) ;
if ( V_130 )
goto V_144;
}
while ( T_6 -> V_128 -> V_184 ( T_6 , V_141 ) ) {
V_130 = T_6 -> V_128 -> V_185 ( T_6 , V_141 ) ;
if ( V_130 )
break;
if ( T_6 -> V_87 && T_6 -> V_183 ) {
V_130 = T_6 -> V_183 ( T_6 , V_141 , false , V_179 ) ;
if ( V_130 )
goto V_144;
}
}
V_144:
V_180 = T_6 -> V_128 -> V_186 ( T_6 , V_141 ) ;
if ( ! V_130 )
V_130 = V_180 ;
return V_130 ;
}
T_5
F_42 ( struct V_14 * V_187 , struct V_14 * V_188 )
{
struct V_1 * V_1 = V_187 -> V_1 ;
struct V_189 * V_190 ;
T_5 V_143 = 0 ;
F_81 (hists, fmt) {
if ( F_82 ( V_190 ) &&
! F_83 ( V_190 , V_1 ) )
continue;
V_143 = V_190 -> V_143 ( V_190 , V_187 , V_188 ) ;
if ( V_143 )
break;
}
return V_143 ;
}
T_5
F_84 ( struct V_14 * V_187 , struct V_14 * V_188 )
{
struct V_1 * V_1 = V_187 -> V_1 ;
struct V_189 * V_190 ;
T_5 V_143 = 0 ;
F_81 (hists, fmt) {
if ( F_82 ( V_190 ) &&
! F_83 ( V_190 , V_1 ) )
continue;
V_143 = V_190 -> V_191 ( V_190 , V_187 , V_188 ) ;
if ( V_143 )
break;
}
return V_143 ;
}
void F_24 ( struct V_14 * V_87 )
{
struct V_127 * V_128 = V_87 -> V_128 ;
F_85 ( V_87 -> V_23 ) ;
F_29 ( V_87 -> V_17 . V_26 ) ;
if ( V_87 -> V_29 ) {
F_29 ( V_87 -> V_29 -> V_30 . V_26 ) ;
F_29 ( V_87 -> V_29 -> V_33 . V_26 ) ;
F_86 ( V_87 -> V_29 -> V_36 ) ;
F_86 ( V_87 -> V_29 -> V_38 ) ;
F_43 ( & V_87 -> V_29 ) ;
}
if ( V_87 -> V_40 ) {
F_29 ( V_87 -> V_40 -> V_44 . V_26 ) ;
F_29 ( V_87 -> V_40 -> V_41 . V_26 ) ;
F_43 ( & V_87 -> V_40 ) ;
}
F_43 ( & V_87 -> V_92 ) ;
F_86 ( V_87 -> V_55 ) ;
if ( V_87 -> V_59 && V_87 -> V_59 [ 0 ] )
free ( V_87 -> V_59 ) ;
F_87 ( V_87 -> V_93 ) ;
free ( V_87 -> V_63 ) ;
free ( V_87 -> V_120 ) ;
V_128 -> free ( V_87 ) ;
}
int F_88 ( struct V_14 * V_87 , struct V_192 * V_193 ,
struct V_189 * V_190 , int V_194 )
{
if ( ! F_89 ( & V_190 -> V_195 , & V_87 -> V_1 -> V_196 -> V_197 ) ) {
const int V_198 = V_190 -> V_198 ( V_190 , V_193 , V_87 -> V_1 ) ;
if ( V_194 < V_198 ) {
F_90 ( V_193 , V_194 ) ;
V_194 = F_91 ( V_193 -> V_199 , V_193 -> V_125 , L_1 , V_198 - V_194 , L_2 ) ;
}
}
return V_194 ;
}
static bool F_92 ( struct V_189 * V_190 )
{
return F_93 ( V_190 ) || F_94 ( V_190 ) ;
}
static void F_95 ( struct V_14 * V_87 ,
enum V_200 type ,
T_7 V_201 )
{
struct V_189 * V_190 ;
bool V_202 = false ;
struct V_14 * V_27 = V_87 -> V_105 ;
switch ( type ) {
case V_203 :
if ( V_10 . V_204 == NULL &&
V_10 . V_205 == NULL &&
V_10 . V_206 == NULL )
return;
break;
case V_207 :
if ( V_10 . V_13 == NULL )
return;
break;
case V_208 :
if ( V_10 . V_209 == NULL )
return;
break;
case V_136 :
case V_210 :
case V_211 :
case V_212 :
default:
return;
}
F_96 (he->hpp_list, fmt) {
if ( V_201 ( V_190 ) ) {
V_202 = true ;
break;
}
}
if ( V_202 ) {
if ( ! ( V_87 -> V_71 & ( 1 << type ) ) ) {
while ( V_27 ) {
V_27 -> V_71 &= ~ ( 1 << type ) ;
V_27 = V_27 -> V_105 ;
}
}
} else {
if ( V_27 == NULL )
V_87 -> V_71 |= ( 1 << type ) ;
else
V_87 -> V_71 |= ( V_27 -> V_71 & ( 1 << type ) ) ;
}
}
static void F_97 ( struct V_14 * V_87 )
{
F_95 ( V_87 , V_203 ,
F_92 ) ;
F_95 ( V_87 , V_207 ,
V_213 ) ;
F_95 ( V_87 , V_208 ,
V_214 ) ;
F_98 ( V_87 -> V_1 , V_87 ) ;
}
static struct V_14 * F_99 ( struct V_1 * V_1 ,
struct V_102 * V_215 ,
struct V_14 * V_87 ,
struct V_14 * V_105 ,
struct V_216 * V_196 )
{
struct V_66 * * V_142 = & V_215 -> V_66 ;
struct V_66 * V_27 = NULL ;
struct V_14 * T_6 , * V_133 ;
struct V_189 * V_190 ;
T_5 V_143 ;
while ( * V_142 != NULL ) {
V_27 = * V_142 ;
T_6 = F_13 ( V_27 , struct V_14 , V_110 ) ;
V_143 = 0 ;
F_100 (hpp_list, fmt) {
V_143 = V_190 -> V_191 ( V_190 , T_6 , V_87 ) ;
if ( V_143 )
break;
}
if ( ! V_143 ) {
F_17 ( & T_6 -> V_89 , & V_87 -> V_89 ) ;
return T_6 ;
}
if ( V_143 < 0 )
V_142 = & V_27 -> V_145 ;
else
V_142 = & V_27 -> V_146 ;
}
V_133 = F_38 ( V_87 , true ) ;
if ( V_133 == NULL )
return NULL ;
V_1 -> V_111 ++ ;
V_133 -> V_196 = V_196 ;
V_133 -> V_105 = V_105 ;
F_97 ( V_133 ) ;
F_100 (hpp_list, fmt) {
if ( F_101 ( V_190 ) || F_82 ( V_190 ) )
V_87 -> V_63 = NULL ;
else
V_133 -> V_63 = NULL ;
if ( F_102 ( V_190 ) )
V_87 -> V_55 = NULL ;
else
V_133 -> V_55 = NULL ;
if ( F_103 ( V_190 ) )
V_87 -> V_59 = NULL ;
else
V_133 -> V_59 = NULL ;
}
F_44 ( & V_133 -> V_110 , V_27 , V_142 ) ;
F_45 ( & V_133 -> V_110 , V_215 ) ;
return V_133 ;
}
static int F_104 ( struct V_1 * V_1 ,
struct V_102 * V_215 ,
struct V_14 * V_87 )
{
struct V_217 * V_100 ;
struct V_14 * V_218 = NULL ;
struct V_14 * V_27 = NULL ;
int V_94 = 0 ;
int V_219 = 0 ;
F_105 (node, &hists->hpp_formats, list) {
if ( V_100 -> V_115 == 0 || V_100 -> V_220 )
continue;
V_218 = F_99 ( V_1 , V_215 , V_87 , V_27 , & V_100 -> V_193 ) ;
if ( V_218 == NULL ) {
V_219 = - 1 ;
break;
}
V_215 = & V_218 -> V_106 ;
V_218 -> V_94 = V_94 ++ ;
V_27 = V_218 ;
}
if ( V_218 ) {
V_218 -> V_98 = true ;
if ( V_10 . V_119 ) {
F_106 ( & V_173 ) ;
if ( F_107 ( & V_173 ,
V_218 -> V_93 ,
V_87 -> V_93 ) < 0 )
V_219 = - 1 ;
}
}
F_24 ( V_87 ) ;
return V_219 ;
}
static int F_108 ( struct V_1 * V_1 ,
struct V_102 * V_215 ,
struct V_14 * V_87 )
{
struct V_66 * * V_142 = & V_215 -> V_66 ;
struct V_66 * V_27 = NULL ;
struct V_14 * T_6 ;
T_5 V_143 ;
if ( V_10 . V_124 )
return F_104 ( V_1 , V_215 , V_87 ) ;
while ( * V_142 != NULL ) {
V_27 = * V_142 ;
T_6 = F_13 ( V_27 , struct V_14 , V_110 ) ;
V_143 = F_84 ( T_6 , V_87 ) ;
if ( ! V_143 ) {
int V_219 = 0 ;
F_17 ( & T_6 -> V_89 , & V_87 -> V_89 ) ;
if ( V_10 . V_91 )
F_17 ( T_6 -> V_92 , V_87 -> V_92 ) ;
if ( V_10 . V_119 ) {
F_106 ( & V_173 ) ;
if ( F_107 ( & V_173 ,
T_6 -> V_93 ,
V_87 -> V_93 ) < 0 )
V_219 = - 1 ;
}
F_24 ( V_87 ) ;
return V_219 ;
}
if ( V_143 < 0 )
V_142 = & ( * V_142 ) -> V_145 ;
else
V_142 = & ( * V_142 ) -> V_146 ;
}
V_1 -> V_111 ++ ;
F_44 ( & V_87 -> V_110 , V_27 , V_142 ) ;
F_45 ( & V_87 -> V_110 , V_215 ) ;
return 1 ;
}
struct V_102 * F_109 ( struct V_1 * V_1 )
{
struct V_102 * V_215 ;
F_110 ( & V_1 -> V_221 ) ;
V_215 = V_1 -> V_109 ;
if ( ++ V_1 -> V_109 > & V_1 -> V_222 [ 1 ] )
V_1 -> V_109 = & V_1 -> V_222 [ 0 ] ;
F_111 ( & V_1 -> V_221 ) ;
return V_215 ;
}
static void F_98 ( struct V_1 * V_1 , struct V_14 * V_87 )
{
F_112 ( V_1 , V_87 ) ;
F_113 ( V_1 , V_87 ) ;
F_114 ( V_1 , V_87 ) ;
F_115 ( V_1 , V_87 ) ;
}
int F_116 ( struct V_1 * V_1 , struct V_223 * V_224 )
{
struct V_102 * V_215 ;
struct V_66 * V_67 ;
struct V_14 * V_69 ;
int V_219 ;
if ( ! F_22 ( V_1 , V_107 ) )
return 0 ;
V_1 -> V_111 = 0 ;
V_215 = F_109 ( V_1 ) ;
V_67 = F_12 ( V_215 ) ;
while ( V_67 ) {
if ( F_117 () )
break;
V_69 = F_13 ( V_67 , struct V_14 , V_110 ) ;
V_67 = F_14 ( & V_69 -> V_110 ) ;
F_23 ( & V_69 -> V_110 , V_215 ) ;
V_219 = F_108 ( V_1 , & V_1 -> V_108 , V_69 ) ;
if ( V_219 < 0 )
return - 1 ;
if ( V_219 ) {
F_98 ( V_1 , V_69 ) ;
}
if ( V_224 )
F_118 ( V_224 , 1 ) ;
}
return 0 ;
}
static int F_119 ( struct V_14 * V_225 , struct V_14 * V_226 )
{
struct V_1 * V_1 = V_225 -> V_1 ;
struct V_189 * V_190 ;
T_5 V_143 = 0 ;
F_81 (hists, fmt) {
if ( F_120 ( V_190 , V_225 -> V_1 ) )
continue;
V_143 = V_190 -> V_227 ( V_190 , V_225 , V_226 ) ;
if ( V_143 )
break;
}
return V_143 ;
}
static void F_121 ( struct V_1 * V_1 )
{
V_1 -> V_112 = 0 ;
V_1 -> V_95 . V_97 = 0 ;
}
void F_122 ( struct V_1 * V_1 )
{
V_1 -> V_111 = 0 ;
V_1 -> V_95 . V_96 = 0 ;
F_121 ( V_1 ) ;
}
static void F_123 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
V_1 -> V_112 ++ ;
V_1 -> V_95 . V_97 += V_15 -> V_89 . V_74 ;
}
void F_124 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
if ( ! V_15 -> V_71 )
F_123 ( V_1 , V_15 ) ;
V_1 -> V_111 ++ ;
V_1 -> V_95 . V_96 += V_15 -> V_89 . V_74 ;
}
static void F_125 ( struct V_1 * V_1 )
{
struct V_66 * V_100 ;
struct V_14 * V_87 ;
V_100 = F_12 ( & V_1 -> V_68 ) ;
V_1 -> V_95 . V_96 = 0 ;
V_1 -> V_95 . V_97 = 0 ;
while ( V_100 ) {
V_87 = F_13 ( V_100 , struct V_14 , V_66 ) ;
V_100 = F_14 ( V_100 ) ;
V_1 -> V_95 . V_96 += V_87 -> V_89 . V_74 ;
if ( ! V_87 -> V_71 )
V_1 -> V_95 . V_97 += V_87 -> V_89 . V_74 ;
}
}
static void F_126 ( struct V_102 * V_215 ,
struct V_14 * V_87 )
{
struct V_66 * * V_142 = & V_215 -> V_66 ;
struct V_66 * V_27 = NULL ;
struct V_14 * T_6 ;
struct V_189 * V_190 ;
while ( * V_142 != NULL ) {
V_27 = * V_142 ;
T_6 = F_13 ( V_27 , struct V_14 , V_66 ) ;
if ( F_119 ( V_87 , T_6 ) > 0 )
V_142 = & V_27 -> V_145 ;
else
V_142 = & V_27 -> V_146 ;
}
F_44 ( & V_87 -> V_66 , V_27 , V_142 ) ;
F_45 ( & V_87 -> V_66 , V_215 ) ;
F_100 (he->hpp_list, fmt) {
if ( F_82 ( V_190 ) )
V_190 -> V_227 ( V_190 , V_87 , NULL ) ;
}
}
static void F_127 ( struct V_1 * V_1 ,
struct V_223 * V_224 ,
struct V_102 * V_103 ,
struct V_102 * V_104 ,
T_2 V_228 ,
bool V_119 )
{
struct V_66 * V_100 ;
struct V_14 * V_87 ;
* V_104 = V_123 ;
V_100 = F_12 ( V_103 ) ;
while ( V_100 ) {
V_87 = F_13 ( V_100 , struct V_14 , V_110 ) ;
V_100 = F_14 ( V_100 ) ;
F_126 ( V_104 , V_87 ) ;
if ( V_224 )
F_118 ( V_224 , 1 ) ;
V_1 -> V_111 ++ ;
if ( ! V_87 -> V_71 ) {
V_1 -> V_112 ++ ;
F_6 ( V_1 , V_87 ) ;
}
if ( ! V_87 -> V_98 ) {
F_127 ( V_1 , V_224 ,
& V_87 -> V_106 ,
& V_87 -> V_101 ,
V_228 ,
V_119 ) ;
continue;
}
if ( ! V_119 )
continue;
if ( V_229 . V_230 == V_231 ) {
T_2 V_165 = V_87 -> V_89 . V_74 ;
if ( V_10 . V_91 )
V_165 = V_87 -> V_92 -> V_74 ;
V_228 = V_165 * ( V_229 . V_232 / 100 ) ;
}
V_229 . V_227 ( & V_87 -> V_233 , V_87 -> V_93 ,
V_228 , & V_229 ) ;
}
}
static void F_128 ( struct V_102 * V_68 ,
struct V_14 * V_87 ,
T_2 V_228 ,
bool V_119 )
{
struct V_66 * * V_142 = & V_68 -> V_66 ;
struct V_66 * V_27 = NULL ;
struct V_14 * T_6 ;
struct V_189 * V_190 ;
if ( V_119 ) {
if ( V_229 . V_230 == V_231 ) {
T_2 V_165 = V_87 -> V_89 . V_74 ;
if ( V_10 . V_91 )
V_165 = V_87 -> V_92 -> V_74 ;
V_228 = V_165 * ( V_229 . V_232 / 100 ) ;
}
V_229 . V_227 ( & V_87 -> V_233 , V_87 -> V_93 ,
V_228 , & V_229 ) ;
}
while ( * V_142 != NULL ) {
V_27 = * V_142 ;
T_6 = F_13 ( V_27 , struct V_14 , V_66 ) ;
if ( F_119 ( V_87 , T_6 ) > 0 )
V_142 = & ( * V_142 ) -> V_145 ;
else
V_142 = & ( * V_142 ) -> V_146 ;
}
F_44 ( & V_87 -> V_66 , V_27 , V_142 ) ;
F_45 ( & V_87 -> V_66 , V_68 ) ;
F_100 (&perf_hpp_list, fmt) {
if ( F_82 ( V_190 ) &&
F_83 ( V_190 , V_87 -> V_1 ) )
V_190 -> V_227 ( V_190 , V_87 , NULL ) ;
}
}
static void F_129 ( struct V_1 * V_1 , struct V_223 * V_224 ,
bool V_119 , T_8 V_234 )
{
struct V_102 * V_215 ;
struct V_66 * V_67 ;
struct V_14 * V_69 ;
T_2 V_235 ;
T_2 V_228 ;
V_235 = V_1 -> V_137 ;
if ( V_10 . V_236 )
V_235 = V_1 -> V_138 ;
V_228 = V_235 * ( V_229 . V_232 / 100 ) ;
F_122 ( V_1 ) ;
F_4 ( V_1 ) ;
if ( V_10 . V_124 ) {
F_127 ( V_1 , V_224 ,
& V_1 -> V_108 ,
& V_1 -> V_68 ,
V_228 ,
V_119 ) ;
F_125 ( V_1 ) ;
return;
}
if ( F_22 ( V_1 , V_107 ) )
V_215 = & V_1 -> V_108 ;
else
V_215 = V_1 -> V_109 ;
V_67 = F_12 ( V_215 ) ;
V_1 -> V_68 = V_123 ;
while ( V_67 ) {
V_69 = F_13 ( V_67 , struct V_14 , V_110 ) ;
V_67 = F_14 ( & V_69 -> V_110 ) ;
if ( V_234 && V_234 ( V_69 ) )
continue;
F_128 ( & V_1 -> V_68 , V_69 , V_228 , V_119 ) ;
F_124 ( V_1 , V_69 ) ;
if ( ! V_69 -> V_71 )
F_6 ( V_1 , V_69 ) ;
if ( V_224 )
F_118 ( V_224 , 1 ) ;
}
}
void F_130 ( struct V_163 * V_161 , struct V_223 * V_224 )
{
bool V_119 ;
if ( V_161 && V_10 . V_119 && ! V_10 . V_237 )
V_119 = V_161 -> V_238 . V_239 & V_240 ;
else
V_119 = V_10 . V_119 ;
F_129 ( F_55 ( V_161 ) , V_224 , V_119 , NULL ) ;
}
void F_131 ( struct V_1 * V_1 , struct V_223 * V_224 )
{
F_129 ( V_1 , V_224 , V_10 . V_119 , NULL ) ;
}
void F_132 ( struct V_1 * V_1 , struct V_223 * V_224 ,
T_8 V_234 )
{
F_129 ( V_1 , V_224 , V_10 . V_119 , V_234 ) ;
}
static bool F_133 ( struct V_14 * V_87 , enum V_241 V_242 )
{
if ( V_87 -> V_98 || V_242 == V_243 )
return false ;
if ( V_87 -> V_244 || V_242 == V_245 )
return true ;
return false ;
}
struct V_66 * F_134 ( struct V_66 * V_100 )
{
struct V_14 * V_87 = F_13 ( V_100 , struct V_14 , V_66 ) ;
while ( F_133 ( V_87 , V_246 ) ) {
V_100 = F_135 ( & V_87 -> V_101 ) ;
V_87 = F_13 ( V_100 , struct V_14 , V_66 ) ;
}
return V_100 ;
}
struct V_66 * F_136 ( struct V_66 * V_100 , enum V_241 V_242 )
{
struct V_14 * V_87 = F_13 ( V_100 , struct V_14 , V_66 ) ;
if ( F_133 ( V_87 , V_242 ) )
V_100 = F_12 ( & V_87 -> V_101 ) ;
else
V_100 = F_14 ( V_100 ) ;
while ( V_100 == NULL ) {
V_87 = V_87 -> V_105 ;
if ( V_87 == NULL )
break;
V_100 = F_14 ( & V_87 -> V_66 ) ;
}
return V_100 ;
}
struct V_66 * F_137 ( struct V_66 * V_100 )
{
struct V_14 * V_87 = F_13 ( V_100 , struct V_14 , V_66 ) ;
V_100 = F_138 ( V_100 ) ;
if ( V_100 )
return F_134 ( V_100 ) ;
V_87 = V_87 -> V_105 ;
if ( V_87 == NULL )
return NULL ;
return & V_87 -> V_66 ;
}
bool F_139 ( struct V_14 * V_87 , float V_247 )
{
struct V_66 * V_100 ;
struct V_14 * V_99 ;
float V_248 ;
if ( V_87 -> V_98 )
return false ;
V_100 = F_12 ( & V_87 -> V_101 ) ;
V_99 = F_13 ( V_100 , struct V_14 , V_66 ) ;
while ( V_100 && V_99 -> V_71 ) {
V_100 = F_14 ( V_100 ) ;
V_99 = F_13 ( V_100 , struct V_14 , V_66 ) ;
}
if ( V_100 )
V_248 = F_140 ( V_99 ) ;
else
V_248 = 0 ;
return V_100 && V_248 >= V_247 ;
}
static void F_141 ( struct V_1 * V_1 , struct V_14 * V_15 ,
enum V_200 V_249 )
{
V_15 -> V_71 &= ~ ( 1 << V_249 ) ;
if ( V_10 . V_124 ) {
struct V_14 * V_27 = V_15 -> V_105 ;
while ( V_27 ) {
F_17 ( & V_27 -> V_89 , & V_15 -> V_89 ) ;
V_27 -> V_71 &= ~ ( 1 << V_249 ) ;
if ( V_27 -> V_71 )
goto V_67;
V_27 -> V_244 = false ;
V_27 -> V_250 = false ;
V_27 -> V_251 = 0 ;
V_27 -> V_252 = 0 ;
V_67:
V_27 = V_27 -> V_105 ;
}
}
if ( V_15 -> V_71 )
return;
V_15 -> V_244 = false ;
V_15 -> V_250 = false ;
V_15 -> V_251 = 0 ;
V_15 -> V_252 = 0 ;
V_1 -> V_95 . V_253 += V_15 -> V_89 . V_84 ;
F_123 ( V_1 , V_15 ) ;
F_6 ( V_1 , V_15 ) ;
}
static bool F_112 ( struct V_1 * V_1 ,
struct V_14 * V_87 )
{
if ( V_1 -> V_254 != NULL &&
( V_87 -> V_17 . V_26 == NULL || V_87 -> V_17 . V_26 -> V_7 != V_1 -> V_254 ) ) {
V_87 -> V_71 |= ( 1 << V_207 ) ;
return true ;
}
return false ;
}
static bool F_113 ( struct V_1 * V_1 ,
struct V_14 * V_87 )
{
if ( V_1 -> V_255 != NULL &&
V_87 -> V_23 != V_1 -> V_255 ) {
V_87 -> V_71 |= ( 1 << V_203 ) ;
return true ;
}
return false ;
}
static bool F_114 ( struct V_1 * V_1 ,
struct V_14 * V_87 )
{
if ( V_1 -> V_256 != NULL &&
( ! V_87 -> V_17 . V_18 || strstr ( V_87 -> V_17 . V_18 -> V_257 ,
V_1 -> V_256 ) == NULL ) ) {
V_87 -> V_71 |= ( 1 << V_208 ) ;
return true ;
}
return false ;
}
static bool F_115 ( struct V_1 * V_1 ,
struct V_14 * V_87 )
{
if ( ( V_1 -> V_258 > - 1 ) &&
( V_87 -> V_153 != V_1 -> V_258 ) ) {
V_87 -> V_71 |= ( 1 << V_212 ) ;
return true ;
}
return false ;
}
static void F_142 ( struct V_1 * V_1 , int type , T_9 V_249 )
{
struct V_66 * V_259 ;
V_1 -> V_95 . V_253 = 0 ;
F_121 ( V_1 ) ;
F_4 ( V_1 ) ;
for ( V_259 = F_12 ( & V_1 -> V_68 ) ; V_259 ; V_259 = F_14 ( V_259 ) ) {
struct V_14 * V_15 = F_13 ( V_259 , struct V_14 , V_66 ) ;
if ( V_249 ( V_1 , V_15 ) )
continue;
F_141 ( V_1 , V_15 , type ) ;
}
}
static void F_143 ( struct V_102 * V_215 , struct V_14 * V_87 )
{
struct V_66 * * V_142 = & V_215 -> V_66 ;
struct V_66 * V_27 = NULL ;
struct V_14 * T_6 ;
struct V_102 V_260 = V_123 ;
struct V_66 * V_259 ;
while ( * V_142 != NULL ) {
V_27 = * V_142 ;
T_6 = F_13 ( V_27 , struct V_14 , V_66 ) ;
if ( F_119 ( V_87 , T_6 ) > 0 )
V_142 = & ( * V_142 ) -> V_145 ;
else
V_142 = & ( * V_142 ) -> V_146 ;
}
F_44 ( & V_87 -> V_66 , V_27 , V_142 ) ;
F_45 ( & V_87 -> V_66 , V_215 ) ;
if ( V_87 -> V_98 || V_87 -> V_71 )
return;
V_259 = F_12 ( & V_87 -> V_101 ) ;
while ( V_259 ) {
struct V_14 * V_15 = F_13 ( V_259 , struct V_14 , V_66 ) ;
V_259 = F_14 ( V_259 ) ;
F_23 ( & V_15 -> V_66 , & V_87 -> V_101 ) ;
F_143 ( & V_260 , V_15 ) ;
}
V_87 -> V_101 = V_260 ;
}
static void F_144 ( struct V_1 * V_1 , int type , const void * V_179 )
{
struct V_66 * V_259 ;
struct V_102 V_260 = V_123 ;
V_1 -> V_95 . V_253 = 0 ;
F_121 ( V_1 ) ;
F_4 ( V_1 ) ;
V_259 = F_12 ( & V_1 -> V_68 ) ;
while ( V_259 ) {
struct V_14 * V_15 = F_13 ( V_259 , struct V_14 , V_66 ) ;
int V_219 ;
V_219 = F_145 ( V_15 , type , V_179 ) ;
if ( V_219 < 0 ) {
memset ( & V_15 -> V_89 , 0 , sizeof( V_15 -> V_89 ) ) ;
V_15 -> V_71 |= ( 1 << type ) ;
V_259 = F_136 ( & V_15 -> V_66 , V_245 ) ;
}
else if ( V_219 == 1 ) {
V_15 -> V_71 |= ( 1 << type ) ;
V_259 = F_136 ( & V_15 -> V_66 , V_243 ) ;
}
else {
F_141 ( V_1 , V_15 , type ) ;
V_259 = F_136 ( & V_15 -> V_66 , V_243 ) ;
}
}
F_125 ( V_1 ) ;
V_259 = F_12 ( & V_1 -> V_68 ) ;
while ( V_259 ) {
struct V_14 * V_15 = F_13 ( V_259 , struct V_14 , V_66 ) ;
V_259 = F_14 ( V_259 ) ;
F_23 ( & V_15 -> V_66 , & V_1 -> V_68 ) ;
F_143 ( & V_260 , V_15 ) ;
}
V_1 -> V_68 = V_260 ;
}
void F_146 ( struct V_1 * V_1 )
{
if ( V_10 . V_124 )
F_144 ( V_1 , V_203 ,
V_1 -> V_255 ) ;
else
F_142 ( V_1 , V_203 ,
F_113 ) ;
}
void F_147 ( struct V_1 * V_1 )
{
if ( V_10 . V_124 )
F_144 ( V_1 , V_207 ,
V_1 -> V_254 ) ;
else
F_142 ( V_1 , V_207 ,
F_112 ) ;
}
void F_148 ( struct V_1 * V_1 )
{
if ( V_10 . V_124 )
F_144 ( V_1 , V_208 ,
V_1 -> V_256 ) ;
else
F_142 ( V_1 , V_208 ,
F_114 ) ;
}
void F_149 ( struct V_1 * V_1 )
{
if ( V_10 . V_124 )
F_144 ( V_1 , V_212 ,
& V_1 -> V_258 ) ;
else
F_142 ( V_1 , V_212 ,
F_115 ) ;
}
void F_150 ( struct V_261 * V_95 , T_10 type )
{
++ V_95 -> V_84 [ 0 ] ;
++ V_95 -> V_84 [ type ] ;
}
void F_151 ( struct V_1 * V_1 , T_10 type )
{
F_150 ( & V_1 -> V_95 , type ) ;
}
void F_57 ( struct V_1 * V_1 , bool V_71 )
{
F_150 ( & V_1 -> V_95 , V_262 ) ;
if ( ! V_71 )
V_1 -> V_95 . V_253 ++ ;
}
static struct V_14 * F_152 ( struct V_1 * V_1 ,
struct V_14 * V_263 )
{
struct V_102 * V_215 ;
struct V_66 * * V_142 ;
struct V_66 * V_27 = NULL ;
struct V_14 * V_87 ;
T_5 V_143 ;
if ( F_22 ( V_1 , V_107 ) )
V_215 = & V_1 -> V_108 ;
else
V_215 = V_1 -> V_109 ;
V_142 = & V_215 -> V_66 ;
while ( * V_142 != NULL ) {
V_27 = * V_142 ;
V_87 = F_13 ( V_27 , struct V_14 , V_110 ) ;
V_143 = F_84 ( V_87 , V_263 ) ;
if ( ! V_143 )
goto V_144;
if ( V_143 < 0 )
V_142 = & ( * V_142 ) -> V_145 ;
else
V_142 = & ( * V_142 ) -> V_146 ;
}
V_87 = F_38 ( V_263 , true ) ;
if ( V_87 ) {
memset ( & V_87 -> V_89 , 0 , sizeof( V_87 -> V_89 ) ) ;
V_87 -> V_1 = V_1 ;
if ( V_10 . V_91 )
memset ( V_87 -> V_92 , 0 , sizeof( V_87 -> V_89 ) ) ;
F_44 ( & V_87 -> V_110 , V_27 , V_142 ) ;
F_45 ( & V_87 -> V_110 , V_215 ) ;
F_124 ( V_1 , V_87 ) ;
V_87 -> V_264 = true ;
}
V_144:
return V_87 ;
}
static struct V_14 * F_153 ( struct V_1 * V_1 ,
struct V_102 * V_215 ,
struct V_14 * V_263 )
{
struct V_66 * * V_142 ;
struct V_66 * V_27 = NULL ;
struct V_14 * V_87 ;
struct V_189 * V_190 ;
V_142 = & V_215 -> V_66 ;
while ( * V_142 != NULL ) {
T_5 V_143 = 0 ;
V_27 = * V_142 ;
V_87 = F_13 ( V_27 , struct V_14 , V_110 ) ;
F_100 (he->hpp_list, fmt) {
V_143 = V_190 -> V_191 ( V_190 , V_87 , V_263 ) ;
if ( V_143 )
break;
}
if ( ! V_143 )
goto V_144;
if ( V_143 < 0 )
V_142 = & V_27 -> V_145 ;
else
V_142 = & V_27 -> V_146 ;
}
V_87 = F_38 ( V_263 , true ) ;
if ( V_87 ) {
F_44 ( & V_87 -> V_110 , V_27 , V_142 ) ;
F_45 ( & V_87 -> V_110 , V_215 ) ;
V_87 -> V_264 = true ;
V_87 -> V_1 = V_1 ;
memset ( & V_87 -> V_89 , 0 , sizeof( V_87 -> V_89 ) ) ;
F_124 ( V_1 , V_87 ) ;
}
V_144:
return V_87 ;
}
static struct V_14 * F_154 ( struct V_1 * V_1 ,
struct V_14 * V_87 )
{
struct V_66 * V_69 ;
if ( F_22 ( V_1 , V_107 ) )
V_69 = V_1 -> V_108 . V_66 ;
else
V_69 = V_1 -> V_109 -> V_66 ;
while ( V_69 ) {
struct V_14 * T_6 = F_13 ( V_69 , struct V_14 , V_110 ) ;
T_5 V_143 = F_84 ( T_6 , V_87 ) ;
if ( V_143 < 0 )
V_69 = V_69 -> V_145 ;
else if ( V_143 > 0 )
V_69 = V_69 -> V_146 ;
else
return T_6 ;
}
return NULL ;
}
static struct V_14 * F_155 ( struct V_102 * V_215 ,
struct V_14 * V_87 )
{
struct V_66 * V_69 = V_215 -> V_66 ;
while ( V_69 ) {
struct V_14 * T_6 ;
struct V_189 * V_190 ;
T_5 V_143 = 0 ;
T_6 = F_13 ( V_69 , struct V_14 , V_110 ) ;
F_100 (he->hpp_list, fmt) {
V_143 = V_190 -> V_191 ( V_190 , T_6 , V_87 ) ;
if ( V_143 )
break;
}
if ( V_143 < 0 )
V_69 = V_69 -> V_145 ;
else if ( V_143 > 0 )
V_69 = V_69 -> V_146 ;
else
return T_6 ;
}
return NULL ;
}
static void F_156 ( struct V_102 * V_265 ,
struct V_102 * V_266 )
{
struct V_66 * V_259 ;
struct V_14 * V_267 , * V_263 ;
for ( V_259 = F_12 ( V_265 ) ; V_259 ; V_259 = F_14 ( V_259 ) ) {
V_267 = F_13 ( V_259 , struct V_14 , V_110 ) ;
V_263 = F_155 ( V_266 , V_267 ) ;
if ( V_263 ) {
F_157 ( V_263 , V_267 ) ;
F_156 ( & V_267 -> V_106 , & V_263 -> V_106 ) ;
}
}
}
void F_158 ( struct V_1 * V_268 , struct V_1 * V_269 )
{
struct V_102 * V_215 ;
struct V_66 * V_259 ;
struct V_14 * V_267 , * V_263 ;
if ( V_10 . V_124 ) {
return F_156 ( & V_268 -> V_108 ,
& V_269 -> V_108 ) ;
}
if ( F_22 ( V_268 , V_107 ) )
V_215 = & V_268 -> V_108 ;
else
V_215 = V_268 -> V_109 ;
for ( V_259 = F_12 ( V_215 ) ; V_259 ; V_259 = F_14 ( V_259 ) ) {
V_267 = F_13 ( V_259 , struct V_14 , V_110 ) ;
V_263 = F_154 ( V_269 , V_267 ) ;
if ( V_263 )
F_157 ( V_263 , V_267 ) ;
}
}
static int F_159 ( struct V_1 * V_270 ,
struct V_14 * V_27 ,
struct V_102 * V_265 ,
struct V_102 * V_266 )
{
struct V_66 * V_259 ;
struct V_14 * V_267 , * V_268 ;
for ( V_259 = F_12 ( V_266 ) ; V_259 ; V_259 = F_14 ( V_259 ) ) {
V_267 = F_13 ( V_259 , struct V_14 , V_110 ) ;
if ( F_160 ( V_267 ) ) {
bool V_271 = false ;
F_105 (leader, &pos->pairs.head, pairs.node) {
if ( V_268 -> V_1 == V_270 ) {
V_271 = true ;
break;
}
}
if ( ! V_271 )
return - 1 ;
} else {
V_268 = F_153 ( V_270 ,
V_265 , V_267 ) ;
if ( V_268 == NULL )
return - 1 ;
V_268 -> V_105 = V_27 ;
F_157 ( V_267 , V_268 ) ;
}
if ( ! V_267 -> V_98 ) {
if ( F_159 ( V_270 , V_268 ,
& V_268 -> V_106 ,
& V_267 -> V_106 ) < 0 )
return - 1 ;
}
}
return 0 ;
}
int F_161 ( struct V_1 * V_268 , struct V_1 * V_269 )
{
struct V_102 * V_215 ;
struct V_66 * V_259 ;
struct V_14 * V_267 , * V_263 ;
if ( V_10 . V_124 ) {
return F_159 ( V_268 , NULL ,
& V_268 -> V_108 ,
& V_269 -> V_108 ) ;
}
if ( F_22 ( V_269 , V_107 ) )
V_215 = & V_269 -> V_108 ;
else
V_215 = V_269 -> V_109 ;
for ( V_259 = F_12 ( V_215 ) ; V_259 ; V_259 = F_14 ( V_259 ) ) {
V_267 = F_13 ( V_259 , struct V_14 , V_110 ) ;
if ( ! F_160 ( V_267 ) ) {
V_263 = F_152 ( V_268 , V_267 ) ;
if ( V_263 == NULL )
return - 1 ;
F_157 ( V_267 , V_263 ) ;
}
}
return 0 ;
}
void F_162 ( struct V_166 * V_272 , struct V_140 * V_141 ,
struct V_150 * V_151 , bool V_273 )
{
struct V_29 * V_148 ;
if ( V_272 && V_272 -> V_167 && V_272 -> V_68 [ 0 ] . V_170 . V_171 ) {
int V_168 ;
V_148 = F_60 ( V_151 , V_141 ) ;
if ( V_148 ) {
struct V_274 * V_275 = NULL ;
for ( V_168 = V_272 -> V_167 - 1 ; V_168 >= 0 ; V_168 -- ) {
F_163 ( & V_148 [ V_168 ] . V_30 ,
V_273 ? NULL : V_275 ,
V_148 [ V_168 ] . V_170 . V_171 ) ;
V_275 = & V_148 [ V_168 ] . V_33 ;
}
free ( V_148 ) ;
}
}
}
T_3 F_164 ( struct V_276 * V_277 , T_11 * V_278 )
{
struct V_163 * V_267 ;
T_3 V_219 = 0 ;
F_165 (evlist, pos) {
V_219 += fprintf ( V_278 , L_3 , F_166 ( V_267 ) ) ;
V_219 += F_167 ( & F_55 ( V_267 ) -> V_95 , V_278 ) ;
}
return V_219 ;
}
T_2 F_168 ( struct V_1 * V_1 )
{
return V_10 . V_236 ? V_1 -> V_95 . V_97 :
V_1 -> V_95 . V_96 ;
}
int F_169 ( const struct V_279 * T_12 V_158 ,
const char * V_179 , int T_13 V_158 )
{
if ( ! strcmp ( V_179 , L_4 ) )
V_10 . V_236 = true ;
else if ( ! strcmp ( V_179 , L_5 ) )
V_10 . V_236 = false ;
else
return - 1 ;
return 0 ;
}
int F_170 ( const char * V_280 , const char * V_281 )
{
if ( ! strcmp ( V_280 , L_6 ) )
return F_169 ( NULL , V_281 , 0 ) ;
return 0 ;
}
int F_171 ( struct V_1 * V_1 , struct V_216 * V_196 )
{
memset ( V_1 , 0 , sizeof( * V_1 ) ) ;
V_1 -> V_222 [ 0 ] = V_1 -> V_222 [ 1 ] = V_123 ;
V_1 -> V_109 = & V_1 -> V_222 [ 0 ] ;
V_1 -> V_108 = V_123 ;
V_1 -> V_68 = V_123 ;
F_172 ( & V_1 -> V_221 , NULL ) ;
V_1 -> V_258 = - 1 ;
V_1 -> V_196 = V_196 ;
F_33 ( & V_1 -> V_282 ) ;
return 0 ;
}
static void F_173 ( struct V_102 * V_215 )
{
struct V_66 * V_100 ;
struct V_14 * V_87 ;
while ( ! F_174 ( V_215 ) ) {
V_100 = F_12 ( V_215 ) ;
F_23 ( V_100 , V_215 ) ;
V_87 = F_13 ( V_100 , struct V_14 , V_110 ) ;
F_24 ( V_87 ) ;
}
}
static void F_175 ( struct V_1 * V_1 )
{
F_26 ( V_1 ) ;
F_173 ( & V_1 -> V_222 [ 0 ] ) ;
F_173 ( & V_1 -> V_222 [ 1 ] ) ;
F_173 ( & V_1 -> V_108 ) ;
}
static void F_176 ( struct V_163 * V_161 )
{
struct V_1 * V_1 = F_55 ( V_161 ) ;
struct V_189 * V_190 , * V_267 ;
struct V_217 * V_100 , * V_283 ;
F_175 ( V_1 ) ;
F_177 (node, tmp, &hists->hpp_formats, list) {
F_178 (&node->hpp, fmt, pos) {
F_179 ( & V_190 -> V_195 ) ;
free ( V_190 ) ;
}
F_179 ( & V_100 -> V_195 ) ;
free ( V_100 ) ;
}
}
static int F_180 ( struct V_163 * V_161 )
{
struct V_1 * V_1 = F_55 ( V_161 ) ;
F_171 ( V_1 , & V_216 ) ;
return 0 ;
}
int F_181 ( void )
{
int V_130 = F_182 ( sizeof( struct V_284 ) ,
F_180 ,
F_176 ) ;
if ( V_130 )
fputs ( L_7 , V_285 ) ;
return V_130 ;
}
void F_183 ( struct V_216 * V_195 )
{
F_33 ( & V_195 -> V_197 ) ;
F_33 ( & V_195 -> V_286 ) ;
}
