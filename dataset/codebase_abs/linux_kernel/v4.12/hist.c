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
if ( V_20 > 0 )
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
if ( V_20 > 0 )
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
if ( V_20 > 0 )
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
F_3 ( V_1 , V_47 , 20 ) ;
F_3 ( V_1 , V_48 , 3 ) ;
F_3 ( V_1 , V_49 , 6 ) ;
F_3 ( V_1 , V_50 , 6 ) ;
F_3 ( V_1 , V_51 , 22 ) ;
F_3 ( V_1 , V_52 , 12 ) ;
F_3 ( V_1 , V_53 , 21 + 3 ) ;
F_3 ( V_1 , V_54 , 12 ) ;
F_3 ( V_1 , V_55 , 12 ) ;
if ( V_15 -> V_56 ) {
V_5 = F_9 ( strlen ( V_15 -> V_56 ) , strlen ( V_57 . V_58 ) ) ;
F_3 ( V_1 , V_59 , V_5 ) ;
}
if ( V_15 -> V_60 )
F_3 ( V_1 , V_61 , strlen ( V_15 -> V_60 ) ) ;
if ( V_15 -> V_62 )
F_3 ( V_1 , V_63 ,
F_10 () ) ;
if ( V_15 -> V_64 )
F_3 ( V_1 , V_65 , strlen ( V_15 -> V_64 ) ) ;
}
void F_11 ( struct V_1 * V_1 , int V_66 )
{
struct V_67 * V_68 = F_12 ( & V_1 -> V_69 ) ;
struct V_14 * V_70 ;
int V_71 = 0 ;
F_4 ( V_1 ) ;
while ( V_68 && V_71 ++ < V_66 ) {
V_70 = F_13 ( V_68 , struct V_14 , V_67 ) ;
if ( ! V_70 -> V_72 )
F_6 ( V_1 , V_70 ) ;
V_68 = F_14 ( & V_70 -> V_67 ) ;
}
}
static void F_15 ( struct V_73 * V_73 ,
unsigned int V_74 , T_2 V_75 )
{
switch ( V_74 ) {
case V_76 :
V_73 -> V_77 += V_75 ;
break;
case V_78 :
V_73 -> V_79 += V_75 ;
break;
case V_80 :
V_73 -> V_81 += V_75 ;
break;
case V_82 :
V_73 -> V_83 += V_75 ;
break;
default:
break;
}
}
static void F_16 ( struct V_73 * V_73 , T_2 V_75 ,
T_2 V_84 )
{
V_73 -> V_75 += V_75 ;
V_73 -> V_84 += V_84 ;
V_73 -> V_85 += 1 ;
}
static void F_17 ( struct V_73 * V_86 , struct V_73 * V_87 )
{
V_86 -> V_75 += V_87 -> V_75 ;
V_86 -> V_77 += V_87 -> V_77 ;
V_86 -> V_79 += V_87 -> V_79 ;
V_86 -> V_81 += V_87 -> V_81 ;
V_86 -> V_83 += V_87 -> V_83 ;
V_86 -> V_85 += V_87 -> V_85 ;
V_86 -> V_84 += V_87 -> V_84 ;
}
static void F_18 ( struct V_73 * V_73 )
{
V_73 -> V_75 = ( V_73 -> V_75 * 7 ) / 8 ;
V_73 -> V_85 = ( V_73 -> V_85 * 7 ) / 8 ;
}
static bool F_19 ( struct V_1 * V_1 , struct V_14 * V_88 )
{
T_2 V_89 = V_88 -> V_90 . V_75 ;
T_2 V_91 ;
if ( V_89 == 0 )
return true ;
F_18 ( & V_88 -> V_90 ) ;
if ( V_10 . V_92 )
F_18 ( V_88 -> V_93 ) ;
F_20 ( V_88 -> V_94 ) ;
V_91 = V_89 - V_88 -> V_90 . V_75 ;
if ( ! V_88 -> V_95 ) {
V_1 -> V_96 . V_97 -= V_91 ;
if ( ! V_88 -> V_72 )
V_1 -> V_96 . V_98 -= V_91 ;
}
if ( ! V_88 -> V_99 ) {
struct V_14 * V_100 ;
struct V_67 * V_101 = F_12 ( & V_88 -> V_102 ) ;
while ( V_101 ) {
V_100 = F_13 ( V_101 , struct V_14 , V_67 ) ;
V_101 = F_14 ( V_101 ) ;
if ( F_19 ( V_1 , V_100 ) )
F_21 ( V_1 , V_100 ) ;
}
}
return V_88 -> V_90 . V_75 == 0 ;
}
static void F_21 ( struct V_1 * V_1 , struct V_14 * V_88 )
{
struct V_103 * V_104 ;
struct V_103 * V_105 ;
if ( V_88 -> V_106 ) {
V_104 = & V_88 -> V_106 -> V_107 ;
V_105 = & V_88 -> V_106 -> V_102 ;
} else {
if ( F_22 ( V_1 , V_108 ) )
V_104 = & V_1 -> V_109 ;
else
V_104 = V_1 -> V_110 ;
V_105 = & V_1 -> V_69 ;
}
F_23 ( & V_88 -> V_111 , V_104 ) ;
F_23 ( & V_88 -> V_67 , V_105 ) ;
-- V_1 -> V_112 ;
if ( ! V_88 -> V_72 )
-- V_1 -> V_113 ;
F_24 ( V_88 ) ;
}
void F_25 ( struct V_1 * V_1 , bool V_114 , bool V_115 )
{
struct V_67 * V_68 = F_12 ( & V_1 -> V_69 ) ;
struct V_14 * V_70 ;
while ( V_68 ) {
V_70 = F_13 ( V_68 , struct V_14 , V_67 ) ;
V_68 = F_14 ( & V_70 -> V_67 ) ;
if ( ( ( V_114 && V_70 -> V_116 == '.' ) ||
( V_115 && V_70 -> V_116 != '.' ) ||
F_19 ( V_1 , V_70 ) ) ) {
F_21 ( V_1 , V_70 ) ;
}
}
}
void F_26 ( struct V_1 * V_1 )
{
struct V_67 * V_68 = F_12 ( & V_1 -> V_69 ) ;
struct V_14 * V_70 ;
while ( V_68 ) {
V_70 = F_13 ( V_68 , struct V_14 , V_67 ) ;
V_68 = F_14 ( & V_70 -> V_67 ) ;
F_21 ( V_1 , V_70 ) ;
}
}
static int F_27 ( struct V_14 * V_88 ,
struct V_14 * V_117 ,
bool V_118 )
{
* V_88 = * V_117 ;
if ( V_10 . V_92 ) {
V_88 -> V_93 = malloc ( sizeof( V_88 -> V_90 ) ) ;
if ( V_88 -> V_93 == NULL )
return - V_119 ;
memcpy ( V_88 -> V_93 , & V_88 -> V_90 , sizeof( V_88 -> V_90 ) ) ;
if ( ! V_118 )
memset ( & V_88 -> V_90 , 0 , sizeof( V_88 -> V_90 ) ) ;
}
F_28 ( V_88 -> V_17 . V_26 ) ;
if ( V_88 -> V_29 ) {
V_88 -> V_29 = malloc ( sizeof( * V_88 -> V_29 ) ) ;
if ( V_88 -> V_29 == NULL ) {
F_29 ( V_88 -> V_17 . V_26 ) ;
free ( V_88 -> V_93 ) ;
return - V_119 ;
}
memcpy ( V_88 -> V_29 , V_117 -> V_29 ,
sizeof( * V_88 -> V_29 ) ) ;
F_28 ( V_88 -> V_29 -> V_30 . V_26 ) ;
F_28 ( V_88 -> V_29 -> V_33 . V_26 ) ;
}
if ( V_88 -> V_40 ) {
F_28 ( V_88 -> V_40 -> V_44 . V_26 ) ;
F_28 ( V_88 -> V_40 -> V_41 . V_26 ) ;
}
if ( V_10 . V_120 )
F_30 ( V_88 -> V_94 ) ;
if ( V_88 -> V_121 ) {
V_88 -> V_121 = F_31 ( V_88 -> V_121 , V_88 -> V_122 ) ;
if ( V_88 -> V_121 == NULL ) {
F_32 ( V_88 -> V_17 . V_26 ) ;
if ( V_88 -> V_29 ) {
F_32 ( V_88 -> V_29 -> V_30 . V_26 ) ;
F_32 ( V_88 -> V_29 -> V_33 . V_26 ) ;
free ( V_88 -> V_29 ) ;
}
if ( V_88 -> V_40 ) {
F_32 ( V_88 -> V_40 -> V_44 . V_26 ) ;
F_32 ( V_88 -> V_40 -> V_41 . V_26 ) ;
}
free ( V_88 -> V_93 ) ;
return - V_119 ;
}
}
F_33 ( & V_88 -> V_123 . V_101 ) ;
F_34 ( V_88 -> V_23 ) ;
V_88 -> V_107 = V_124 ;
V_88 -> V_102 = V_124 ;
if ( ! V_10 . V_125 )
V_88 -> V_99 = true ;
return 0 ;
}
static void * F_35 ( T_3 V_126 )
{
return F_36 ( V_126 + sizeof( struct V_14 ) ) ;
}
static void F_37 ( void * V_127 )
{
free ( V_127 ) ;
}
static struct V_14 * F_38 ( struct V_14 * V_117 ,
bool V_118 )
{
struct V_128 * V_129 = V_117 -> V_129 ;
T_3 V_130 = 0 ;
struct V_14 * V_88 ;
int V_131 = 0 ;
if ( ! V_129 )
V_129 = V_117 -> V_129 = & V_132 ;
if ( V_10 . V_120 )
V_130 = sizeof( struct V_133 ) ;
V_88 = V_129 -> V_134 ( V_130 ) ;
if ( V_88 ) {
V_131 = F_27 ( V_88 , V_117 , V_118 ) ;
if ( V_131 ) {
V_129 -> free ( V_88 ) ;
V_88 = NULL ;
}
}
return V_88 ;
}
static T_4 F_39 ( const struct V_135 * V_27 )
{
if ( V_10 . V_136 && V_27 == NULL )
return 1 << V_137 ;
return 0 ;
}
static void F_40 ( struct V_14 * V_88 , T_2 V_75 )
{
if ( ! V_10 . V_120 )
return;
V_88 -> V_1 -> V_138 += V_75 ;
if ( ! V_88 -> V_72 )
V_88 -> V_1 -> V_139 += V_75 ;
}
static struct V_14 * F_41 ( struct V_1 * V_1 ,
struct V_14 * V_140 ,
struct V_141 * V_142 ,
bool V_118 )
{
struct V_67 * * V_143 ;
struct V_67 * V_27 = NULL ;
struct V_14 * V_88 ;
T_5 V_144 ;
T_2 V_75 = V_140 -> V_90 . V_75 ;
T_2 V_84 = V_140 -> V_90 . V_84 ;
V_143 = & V_1 -> V_110 -> V_67 ;
while ( * V_143 != NULL ) {
V_27 = * V_143 ;
V_88 = F_13 ( V_27 , struct V_14 , V_111 ) ;
V_144 = F_42 ( V_88 , V_140 ) ;
if ( ! V_144 ) {
if ( V_118 ) {
F_16 ( & V_88 -> V_90 , V_75 , V_84 ) ;
F_40 ( V_88 , V_75 ) ;
}
if ( V_10 . V_92 )
F_16 ( V_88 -> V_93 , V_75 , V_84 ) ;
F_43 ( & V_140 -> V_40 ) ;
if ( V_88 -> V_17 . V_26 != V_140 -> V_17 . V_26 ) {
F_32 ( V_88 -> V_17 . V_26 ) ;
V_88 -> V_17 . V_26 = F_28 ( V_140 -> V_17 . V_26 ) ;
}
goto V_145;
}
if ( V_144 < 0 )
V_143 = & ( * V_143 ) -> V_146 ;
else
V_143 = & ( * V_143 ) -> V_147 ;
}
V_88 = F_38 ( V_140 , V_118 ) ;
if ( ! V_88 )
return NULL ;
if ( V_118 )
F_40 ( V_88 , V_75 ) ;
V_1 -> V_112 ++ ;
F_44 ( & V_88 -> V_111 , V_27 , V_143 ) ;
F_45 ( & V_88 -> V_111 , V_1 -> V_110 ) ;
V_145:
if ( V_118 )
F_15 ( & V_88 -> V_90 , V_142 -> V_74 , V_75 ) ;
if ( V_10 . V_92 )
F_15 ( V_88 -> V_93 , V_142 -> V_74 , V_75 ) ;
return V_88 ;
}
static struct V_14 *
F_46 ( struct V_1 * V_1 ,
struct V_141 * V_142 ,
struct V_135 * V_148 ,
struct V_29 * V_149 ,
struct V_40 * V_150 ,
struct V_151 * V_152 ,
bool V_118 ,
struct V_128 * V_129 )
{
struct V_153 * V_154 = F_47 ( V_142 -> V_23 ) ;
struct V_14 V_140 = {
. V_23 = V_142 -> V_23 ,
. V_155 = F_48 ( V_142 -> V_23 ) ,
. V_156 = {
. V_157 = V_154 ? V_154 -> V_158 [ V_159 ] . V_157 : 0 ,
. V_160 = V_154 ? V_154 -> V_158 [ V_159 ] . V_160 : 0 ,
} ,
. V_17 = {
. V_26 = V_142 -> V_26 ,
. V_18 = V_142 -> V_18 ,
} ,
. V_161 = V_142 -> V_161 ,
. V_162 = V_142 -> V_162 ,
. V_74 = V_142 -> V_74 ,
. V_163 = V_142 -> V_164 ,
. V_116 = V_142 -> V_116 ,
. V_90 = {
. V_85 = 1 ,
. V_75 = V_152 -> V_75 ,
. V_84 = V_152 -> V_84 ,
} ,
. V_27 = V_148 ,
. V_72 = F_39 ( V_148 ) | V_142 -> V_72 ,
. V_1 = V_1 ,
. V_29 = V_149 ,
. V_40 = V_150 ,
. V_62 = V_152 -> V_62 ,
. V_121 = V_152 -> V_121 ,
. V_122 = V_152 -> V_122 ,
. V_129 = V_129 ,
} ;
return F_41 ( V_1 , & V_140 , V_142 , V_118 ) ;
}
struct V_14 * F_49 ( struct V_1 * V_1 ,
struct V_141 * V_142 ,
struct V_135 * V_148 ,
struct V_29 * V_149 ,
struct V_40 * V_150 ,
struct V_151 * V_152 ,
bool V_118 )
{
return F_46 ( V_1 , V_142 , V_148 , V_149 , V_150 ,
V_152 , V_118 , NULL ) ;
}
struct V_14 * F_50 ( struct V_1 * V_1 ,
struct V_128 * V_129 ,
struct V_141 * V_142 ,
struct V_135 * V_148 ,
struct V_29 * V_149 ,
struct V_40 * V_150 ,
struct V_151 * V_152 ,
bool V_118 )
{
return F_46 ( V_1 , V_142 , V_148 , V_149 , V_150 ,
V_152 , V_118 , V_129 ) ;
}
static int
F_51 ( struct V_165 * T_6 V_166 ,
struct V_141 * V_142 V_166 )
{
return 0 ;
}
static int
F_52 ( struct V_165 * T_6 V_166 ,
struct V_141 * V_142 V_166 )
{
return 0 ;
}
static int
F_53 ( struct V_165 * T_6 , struct V_141 * V_142 )
{
struct V_151 * V_152 = T_6 -> V_152 ;
struct V_40 * V_150 ;
V_150 = F_54 ( V_152 , V_142 ) ;
if ( V_150 == NULL )
return - V_119 ;
T_6 -> V_167 = V_150 ;
return 0 ;
}
static int
F_55 ( struct V_165 * T_6 , struct V_141 * V_142 )
{
T_2 V_168 ;
struct V_40 * V_150 = T_6 -> V_167 ;
struct V_1 * V_1 = F_56 ( T_6 -> V_169 ) ;
struct V_151 * V_152 = T_6 -> V_152 ;
struct V_14 * V_88 ;
if ( V_150 == NULL )
return - V_170 ;
V_168 = V_152 -> V_84 ;
if ( ! V_168 )
V_168 = 1 ;
V_152 -> V_75 = V_168 ;
V_88 = F_49 ( V_1 , V_142 , T_6 -> V_27 , NULL , V_150 ,
V_152 , true ) ;
if ( ! V_88 )
return - V_119 ;
T_6 -> V_88 = V_88 ;
return 0 ;
}
static int
F_57 ( struct V_165 * T_6 ,
struct V_141 * V_142 V_166 )
{
struct V_171 * V_169 = T_6 -> V_169 ;
struct V_1 * V_1 = F_56 ( V_169 ) ;
struct V_14 * V_88 = T_6 -> V_88 ;
int V_131 = - V_170 ;
if ( V_88 == NULL )
goto V_145;
F_58 ( V_1 , V_88 -> V_72 ) ;
V_131 = F_59 ( V_88 , T_6 -> V_152 ) ;
V_145:
T_6 -> V_167 = NULL ;
T_6 -> V_88 = NULL ;
return V_131 ;
}
static int
F_60 ( struct V_165 * T_6 , struct V_141 * V_142 )
{
struct V_29 * V_149 ;
struct V_151 * V_152 = T_6 -> V_152 ;
V_149 = F_61 ( V_152 , V_142 ) ;
if ( ! V_149 )
return - V_119 ;
T_6 -> V_172 = 0 ;
T_6 -> V_173 = V_152 -> V_174 -> V_175 ;
T_6 -> V_167 = V_149 ;
return 0 ;
}
static int
F_62 ( struct V_165 * T_6 ,
struct V_141 * V_142 V_166 )
{
T_6 -> V_88 = NULL ;
return 0 ;
}
static int
F_63 ( struct V_165 * T_6 , struct V_141 * V_142 )
{
struct V_29 * V_149 = T_6 -> V_167 ;
int V_176 = T_6 -> V_172 ;
if ( V_149 == NULL )
return 0 ;
if ( T_6 -> V_172 >= T_6 -> V_173 )
return 0 ;
V_142 -> V_26 = V_149 [ V_176 ] . V_33 . V_26 ;
V_142 -> V_18 = V_149 [ V_176 ] . V_33 . V_18 ;
V_142 -> V_164 = V_149 [ V_176 ] . V_33 . V_164 ;
return 1 ;
}
static int
F_64 ( struct V_165 * T_6 , struct V_141 * V_142 )
{
struct V_29 * V_149 ;
struct V_171 * V_169 = T_6 -> V_169 ;
struct V_1 * V_1 = F_56 ( V_169 ) ;
struct V_151 * V_152 = T_6 -> V_152 ;
struct V_14 * V_88 = NULL ;
int V_176 = T_6 -> V_172 ;
int V_131 = 0 ;
V_149 = T_6 -> V_167 ;
if ( T_6 -> V_177 && ! ( V_149 [ V_176 ] . V_30 . V_18 && V_149 [ V_176 ] . V_33 . V_18 ) )
goto V_145;
V_152 -> V_75 = 1 ;
V_152 -> V_84 = V_149 -> V_178 . V_179 ? V_149 -> V_178 . V_179 : 1 ;
V_88 = F_49 ( V_1 , V_142 , T_6 -> V_27 , & V_149 [ V_176 ] , NULL ,
V_152 , true ) ;
if ( V_88 == NULL )
return - V_119 ;
F_58 ( V_1 , V_88 -> V_72 ) ;
V_145:
T_6 -> V_88 = V_88 ;
T_6 -> V_172 ++ ;
return V_131 ;
}
static int
F_65 ( struct V_165 * T_6 ,
struct V_141 * V_142 V_166 )
{
F_43 ( & T_6 -> V_167 ) ;
T_6 -> V_88 = NULL ;
return T_6 -> V_172 >= T_6 -> V_173 ? 0 : - 1 ;
}
static int
F_66 ( struct V_165 * T_6 V_166 ,
struct V_141 * V_142 V_166 )
{
return 0 ;
}
static int
F_67 ( struct V_165 * T_6 , struct V_141 * V_142 )
{
struct V_171 * V_169 = T_6 -> V_169 ;
struct V_151 * V_152 = T_6 -> V_152 ;
struct V_14 * V_88 ;
V_88 = F_49 ( F_56 ( V_169 ) , V_142 , T_6 -> V_27 , NULL , NULL ,
V_152 , true ) ;
if ( V_88 == NULL )
return - V_119 ;
T_6 -> V_88 = V_88 ;
return 0 ;
}
static int
F_68 ( struct V_165 * T_6 ,
struct V_141 * V_142 V_166 )
{
struct V_14 * V_88 = T_6 -> V_88 ;
struct V_171 * V_169 = T_6 -> V_169 ;
struct V_151 * V_152 = T_6 -> V_152 ;
if ( V_88 == NULL )
return 0 ;
T_6 -> V_88 = NULL ;
F_58 ( F_56 ( V_169 ) , V_88 -> V_72 ) ;
return F_59 ( V_88 , V_152 ) ;
}
static int
F_69 ( struct V_165 * T_6 ,
struct V_141 * V_142 V_166 )
{
struct V_14 * * V_180 ;
F_70 ( & V_181 ) ;
V_180 = malloc ( sizeof( * V_180 ) * ( T_6 -> V_182 + 1 ) ) ;
if ( V_180 == NULL )
return - V_119 ;
T_6 -> V_167 = V_180 ;
T_6 -> V_172 = 0 ;
return 0 ;
}
static int
F_71 ( struct V_165 * T_6 ,
struct V_141 * V_142 )
{
struct V_171 * V_169 = T_6 -> V_169 ;
struct V_1 * V_1 = F_56 ( V_169 ) ;
struct V_151 * V_152 = T_6 -> V_152 ;
struct V_14 * * V_180 = T_6 -> V_167 ;
struct V_14 * V_88 ;
int V_131 = 0 ;
V_88 = F_49 ( V_1 , V_142 , T_6 -> V_27 , NULL , NULL ,
V_152 , true ) ;
if ( V_88 == NULL )
return - V_119 ;
T_6 -> V_88 = V_88 ;
V_180 [ T_6 -> V_172 ++ ] = V_88 ;
F_59 ( V_88 , V_152 ) ;
F_70 ( & V_181 ) ;
F_58 ( V_1 , V_88 -> V_72 ) ;
return V_131 ;
}
static int
F_72 ( struct V_165 * T_6 ,
struct V_141 * V_142 )
{
struct V_183 * V_101 ;
V_101 = F_73 ( & V_181 ) ;
if ( V_101 == NULL )
return 0 ;
return F_74 ( V_142 , V_101 , T_6 -> V_177 ) ;
}
static int
F_75 ( struct V_165 * T_6 ,
struct V_141 * V_142 )
{
struct V_171 * V_169 = T_6 -> V_169 ;
struct V_151 * V_152 = T_6 -> V_152 ;
struct V_14 * * V_180 = T_6 -> V_167 ;
struct V_14 * V_88 ;
struct V_14 V_184 = {
. V_1 = F_56 ( V_169 ) ,
. V_162 = V_142 -> V_162 ,
. V_23 = V_142 -> V_23 ,
. V_155 = F_48 ( V_142 -> V_23 ) ,
. V_163 = V_142 -> V_164 ,
. V_17 = {
. V_26 = V_142 -> V_26 ,
. V_18 = V_142 -> V_18 ,
} ,
. V_27 = T_6 -> V_27 ,
. V_121 = V_152 -> V_121 ,
. V_122 = V_152 -> V_122 ,
} ;
int V_176 ;
struct V_181 V_185 ;
F_76 ( & V_185 , & V_181 ) ;
F_77 ( & V_181 ) ;
for ( V_176 = 0 ; V_176 < T_6 -> V_172 ; V_176 ++ ) {
if ( F_42 ( V_180 [ V_176 ] , & V_184 ) == 0 ) {
T_6 -> V_88 = NULL ;
return 0 ;
}
}
V_88 = F_49 ( F_56 ( V_169 ) , V_142 , T_6 -> V_27 , NULL , NULL ,
V_152 , false ) ;
if ( V_88 == NULL )
return - V_119 ;
T_6 -> V_88 = V_88 ;
V_180 [ T_6 -> V_172 ++ ] = V_88 ;
if ( V_10 . V_120 )
F_78 ( V_88 -> V_94 , & V_185 , V_152 -> V_75 ) ;
return 0 ;
}
static int
F_79 ( struct V_165 * T_6 ,
struct V_141 * V_142 V_166 )
{
F_43 ( & T_6 -> V_167 ) ;
T_6 -> V_88 = NULL ;
return 0 ;
}
int F_80 ( struct V_165 * T_6 , struct V_141 * V_142 ,
int V_186 , void * V_187 )
{
int V_131 , V_188 ;
struct V_26 * V_189 = NULL ;
if ( V_142 && V_142 -> V_26 )
V_189 = F_28 ( V_142 -> V_26 ) ;
V_131 = F_81 ( T_6 -> V_152 , & V_181 , & T_6 -> V_27 ,
T_6 -> V_169 , V_142 , V_186 ) ;
if ( V_131 )
return V_131 ;
T_6 -> V_182 = V_186 ;
V_131 = T_6 -> V_129 -> V_190 ( T_6 , V_142 ) ;
if ( V_131 )
goto V_145;
V_131 = T_6 -> V_129 -> V_191 ( T_6 , V_142 ) ;
if ( V_131 )
goto V_145;
if ( T_6 -> V_88 && T_6 -> V_192 ) {
V_131 = T_6 -> V_192 ( T_6 , V_142 , true , V_187 ) ;
if ( V_131 )
goto V_145;
}
while ( T_6 -> V_129 -> V_193 ( T_6 , V_142 ) ) {
V_131 = T_6 -> V_129 -> V_194 ( T_6 , V_142 ) ;
if ( V_131 )
break;
if ( T_6 -> V_88 && T_6 -> V_192 ) {
V_131 = T_6 -> V_192 ( T_6 , V_142 , false , V_187 ) ;
if ( V_131 )
goto V_145;
}
}
V_145:
V_188 = T_6 -> V_129 -> V_195 ( T_6 , V_142 ) ;
if ( ! V_131 )
V_131 = V_188 ;
F_32 ( V_189 ) ;
return V_131 ;
}
T_5
F_42 ( struct V_14 * V_196 , struct V_14 * V_197 )
{
struct V_1 * V_1 = V_196 -> V_1 ;
struct V_198 * V_199 ;
T_5 V_144 = 0 ;
F_82 (hists, fmt) {
if ( F_83 ( V_199 ) &&
! F_84 ( V_199 , V_1 ) )
continue;
V_144 = V_199 -> V_144 ( V_199 , V_196 , V_197 ) ;
if ( V_144 )
break;
}
return V_144 ;
}
T_5
F_85 ( struct V_14 * V_196 , struct V_14 * V_197 )
{
struct V_1 * V_1 = V_196 -> V_1 ;
struct V_198 * V_199 ;
T_5 V_144 = 0 ;
F_82 (hists, fmt) {
if ( F_83 ( V_199 ) &&
! F_84 ( V_199 , V_1 ) )
continue;
V_144 = V_199 -> V_200 ( V_199 , V_196 , V_197 ) ;
if ( V_144 )
break;
}
return V_144 ;
}
void F_24 ( struct V_14 * V_88 )
{
struct V_128 * V_129 = V_88 -> V_129 ;
F_86 ( V_88 -> V_23 ) ;
F_29 ( V_88 -> V_17 . V_26 ) ;
if ( V_88 -> V_29 ) {
F_29 ( V_88 -> V_29 -> V_30 . V_26 ) ;
F_29 ( V_88 -> V_29 -> V_33 . V_26 ) ;
F_87 ( V_88 -> V_29 -> V_36 ) ;
F_87 ( V_88 -> V_29 -> V_38 ) ;
F_43 ( & V_88 -> V_29 ) ;
}
if ( V_88 -> V_40 ) {
F_29 ( V_88 -> V_40 -> V_44 . V_26 ) ;
F_29 ( V_88 -> V_40 -> V_41 . V_26 ) ;
F_43 ( & V_88 -> V_40 ) ;
}
if ( V_88 -> V_201 ) {
F_88 ( V_88 -> V_201 ) ;
V_88 -> V_201 = NULL ;
}
F_43 ( & V_88 -> V_93 ) ;
F_87 ( V_88 -> V_56 ) ;
if ( V_88 -> V_60 && V_88 -> V_60 [ 0 ] )
free ( V_88 -> V_60 ) ;
F_89 ( V_88 -> V_94 ) ;
free ( V_88 -> V_64 ) ;
free ( V_88 -> V_121 ) ;
V_129 -> free ( V_88 ) ;
}
int F_90 ( struct V_14 * V_88 , struct V_202 * V_203 ,
struct V_198 * V_199 , int V_204 )
{
if ( ! F_91 ( & V_199 -> V_205 , & V_88 -> V_1 -> V_206 -> V_207 ) ) {
const int V_208 = V_199 -> V_208 ( V_199 , V_203 , V_88 -> V_1 ) ;
if ( V_204 < V_208 ) {
F_92 ( V_203 , V_204 ) ;
V_204 = F_93 ( V_203 -> V_209 , V_203 -> V_126 , L_1 , V_208 - V_204 , L_2 ) ;
}
}
return V_204 ;
}
static bool F_94 ( struct V_198 * V_199 )
{
return F_95 ( V_199 ) || F_96 ( V_199 ) ;
}
static void F_97 ( struct V_14 * V_88 ,
enum V_210 type ,
T_7 V_211 )
{
struct V_198 * V_199 ;
bool V_212 = false ;
struct V_14 * V_27 = V_88 -> V_106 ;
switch ( type ) {
case V_213 :
if ( V_10 . V_214 == NULL &&
V_10 . V_215 == NULL &&
V_10 . V_216 == NULL )
return;
break;
case V_217 :
if ( V_10 . V_13 == NULL )
return;
break;
case V_218 :
if ( V_10 . V_219 == NULL )
return;
break;
case V_137 :
case V_220 :
case V_221 :
case V_222 :
case V_223 :
default:
return;
}
F_98 (he->hpp_list, fmt) {
if ( V_211 ( V_199 ) ) {
V_212 = true ;
break;
}
}
if ( V_212 ) {
if ( ! ( V_88 -> V_72 & ( 1 << type ) ) ) {
while ( V_27 ) {
V_27 -> V_72 &= ~ ( 1 << type ) ;
V_27 = V_27 -> V_106 ;
}
}
} else {
if ( V_27 == NULL )
V_88 -> V_72 |= ( 1 << type ) ;
else
V_88 -> V_72 |= ( V_27 -> V_72 & ( 1 << type ) ) ;
}
}
static void F_99 ( struct V_14 * V_88 )
{
F_97 ( V_88 , V_213 ,
F_94 ) ;
F_97 ( V_88 , V_217 ,
V_224 ) ;
F_97 ( V_88 , V_218 ,
V_225 ) ;
F_100 ( V_88 -> V_1 , V_88 ) ;
}
static struct V_14 * F_101 ( struct V_1 * V_1 ,
struct V_103 * V_226 ,
struct V_14 * V_88 ,
struct V_14 * V_106 ,
struct V_227 * V_206 )
{
struct V_67 * * V_143 = & V_226 -> V_67 ;
struct V_67 * V_27 = NULL ;
struct V_14 * T_6 , * V_134 ;
struct V_198 * V_199 ;
T_5 V_144 ;
while ( * V_143 != NULL ) {
V_27 = * V_143 ;
T_6 = F_13 ( V_27 , struct V_14 , V_111 ) ;
V_144 = 0 ;
F_102 (hpp_list, fmt) {
V_144 = V_199 -> V_200 ( V_199 , T_6 , V_88 ) ;
if ( V_144 )
break;
}
if ( ! V_144 ) {
F_17 ( & T_6 -> V_90 , & V_88 -> V_90 ) ;
return T_6 ;
}
if ( V_144 < 0 )
V_143 = & V_27 -> V_146 ;
else
V_143 = & V_27 -> V_147 ;
}
V_134 = F_38 ( V_88 , true ) ;
if ( V_134 == NULL )
return NULL ;
V_1 -> V_112 ++ ;
V_134 -> V_206 = V_206 ;
V_134 -> V_106 = V_106 ;
F_99 ( V_134 ) ;
F_102 (hpp_list, fmt) {
if ( F_103 ( V_199 ) || F_83 ( V_199 ) )
V_88 -> V_64 = NULL ;
else
V_134 -> V_64 = NULL ;
if ( F_104 ( V_199 ) )
V_88 -> V_56 = NULL ;
else
V_134 -> V_56 = NULL ;
if ( F_105 ( V_199 ) )
V_88 -> V_60 = NULL ;
else
V_134 -> V_60 = NULL ;
}
F_44 ( & V_134 -> V_111 , V_27 , V_143 ) ;
F_45 ( & V_134 -> V_111 , V_226 ) ;
return V_134 ;
}
static int F_106 ( struct V_1 * V_1 ,
struct V_103 * V_226 ,
struct V_14 * V_88 )
{
struct V_228 * V_101 ;
struct V_14 * V_229 = NULL ;
struct V_14 * V_27 = NULL ;
int V_95 = 0 ;
int V_230 = 0 ;
F_107 (node, &hists->hpp_formats, list) {
if ( V_101 -> V_116 == 0 || V_101 -> V_231 )
continue;
V_229 = F_101 ( V_1 , V_226 , V_88 , V_27 , & V_101 -> V_203 ) ;
if ( V_229 == NULL ) {
V_230 = - 1 ;
break;
}
V_226 = & V_229 -> V_107 ;
V_229 -> V_95 = V_95 ++ ;
V_27 = V_229 ;
}
if ( V_229 ) {
V_229 -> V_99 = true ;
if ( V_10 . V_120 ) {
F_108 ( & V_181 ) ;
if ( F_109 ( & V_181 ,
V_229 -> V_94 ,
V_88 -> V_94 ) < 0 )
V_230 = - 1 ;
}
}
F_24 ( V_88 ) ;
return V_230 ;
}
static int F_110 ( struct V_1 * V_1 ,
struct V_103 * V_226 ,
struct V_14 * V_88 )
{
struct V_67 * * V_143 = & V_226 -> V_67 ;
struct V_67 * V_27 = NULL ;
struct V_14 * T_6 ;
T_5 V_144 ;
if ( V_10 . V_125 )
return F_106 ( V_1 , V_226 , V_88 ) ;
while ( * V_143 != NULL ) {
V_27 = * V_143 ;
T_6 = F_13 ( V_27 , struct V_14 , V_111 ) ;
V_144 = F_85 ( T_6 , V_88 ) ;
if ( ! V_144 ) {
int V_230 = 0 ;
F_17 ( & T_6 -> V_90 , & V_88 -> V_90 ) ;
if ( V_10 . V_92 )
F_17 ( T_6 -> V_93 , V_88 -> V_93 ) ;
if ( V_10 . V_120 ) {
F_108 ( & V_181 ) ;
if ( F_109 ( & V_181 ,
T_6 -> V_94 ,
V_88 -> V_94 ) < 0 )
V_230 = - 1 ;
}
F_24 ( V_88 ) ;
return V_230 ;
}
if ( V_144 < 0 )
V_143 = & ( * V_143 ) -> V_146 ;
else
V_143 = & ( * V_143 ) -> V_147 ;
}
V_1 -> V_112 ++ ;
F_44 ( & V_88 -> V_111 , V_27 , V_143 ) ;
F_45 ( & V_88 -> V_111 , V_226 ) ;
return 1 ;
}
struct V_103 * F_111 ( struct V_1 * V_1 )
{
struct V_103 * V_226 ;
F_112 ( & V_1 -> V_232 ) ;
V_226 = V_1 -> V_110 ;
if ( ++ V_1 -> V_110 > & V_1 -> V_233 [ 1 ] )
V_1 -> V_110 = & V_1 -> V_233 [ 0 ] ;
F_113 ( & V_1 -> V_232 ) ;
return V_226 ;
}
static void F_100 ( struct V_1 * V_1 , struct V_14 * V_88 )
{
F_114 ( V_1 , V_88 ) ;
F_115 ( V_1 , V_88 ) ;
F_116 ( V_1 , V_88 ) ;
F_117 ( V_1 , V_88 ) ;
}
int F_118 ( struct V_1 * V_1 , struct V_234 * V_235 )
{
struct V_103 * V_226 ;
struct V_67 * V_68 ;
struct V_14 * V_70 ;
int V_230 ;
if ( ! F_22 ( V_1 , V_108 ) )
return 0 ;
V_1 -> V_112 = 0 ;
V_226 = F_111 ( V_1 ) ;
V_68 = F_12 ( V_226 ) ;
while ( V_68 ) {
if ( F_119 () )
break;
V_70 = F_13 ( V_68 , struct V_14 , V_111 ) ;
V_68 = F_14 ( & V_70 -> V_111 ) ;
F_23 ( & V_70 -> V_111 , V_226 ) ;
V_230 = F_110 ( V_1 , & V_1 -> V_109 , V_70 ) ;
if ( V_230 < 0 )
return - 1 ;
if ( V_230 ) {
F_100 ( V_1 , V_70 ) ;
}
if ( V_235 )
F_120 ( V_235 , 1 ) ;
}
return 0 ;
}
static int F_121 ( struct V_14 * V_236 , struct V_14 * V_237 )
{
struct V_1 * V_1 = V_236 -> V_1 ;
struct V_198 * V_199 ;
T_5 V_144 = 0 ;
F_82 (hists, fmt) {
if ( F_122 ( V_199 , V_236 -> V_1 ) )
continue;
V_144 = V_199 -> V_238 ( V_199 , V_236 , V_237 ) ;
if ( V_144 )
break;
}
return V_144 ;
}
static void F_123 ( struct V_1 * V_1 )
{
V_1 -> V_113 = 0 ;
V_1 -> V_96 . V_98 = 0 ;
}
void F_124 ( struct V_1 * V_1 )
{
V_1 -> V_112 = 0 ;
V_1 -> V_96 . V_97 = 0 ;
F_123 ( V_1 ) ;
}
static void F_125 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
V_1 -> V_113 ++ ;
V_1 -> V_96 . V_98 += V_15 -> V_90 . V_75 ;
}
void F_126 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
if ( ! V_15 -> V_72 )
F_125 ( V_1 , V_15 ) ;
V_1 -> V_112 ++ ;
V_1 -> V_96 . V_97 += V_15 -> V_90 . V_75 ;
}
static void F_127 ( struct V_1 * V_1 )
{
struct V_67 * V_101 ;
struct V_14 * V_88 ;
V_101 = F_12 ( & V_1 -> V_69 ) ;
V_1 -> V_96 . V_97 = 0 ;
V_1 -> V_96 . V_98 = 0 ;
while ( V_101 ) {
V_88 = F_13 ( V_101 , struct V_14 , V_67 ) ;
V_101 = F_14 ( V_101 ) ;
V_1 -> V_96 . V_97 += V_88 -> V_90 . V_75 ;
if ( ! V_88 -> V_72 )
V_1 -> V_96 . V_98 += V_88 -> V_90 . V_75 ;
}
}
static void F_128 ( struct V_103 * V_226 ,
struct V_14 * V_88 )
{
struct V_67 * * V_143 = & V_226 -> V_67 ;
struct V_67 * V_27 = NULL ;
struct V_14 * T_6 ;
struct V_198 * V_199 ;
while ( * V_143 != NULL ) {
V_27 = * V_143 ;
T_6 = F_13 ( V_27 , struct V_14 , V_67 ) ;
if ( F_121 ( V_88 , T_6 ) > 0 )
V_143 = & V_27 -> V_146 ;
else
V_143 = & V_27 -> V_147 ;
}
F_44 ( & V_88 -> V_67 , V_27 , V_143 ) ;
F_45 ( & V_88 -> V_67 , V_226 ) ;
F_102 (he->hpp_list, fmt) {
if ( F_83 ( V_199 ) )
V_199 -> V_238 ( V_199 , V_88 , NULL ) ;
}
}
static void F_129 ( struct V_1 * V_1 ,
struct V_234 * V_235 ,
struct V_103 * V_104 ,
struct V_103 * V_105 ,
T_2 V_239 ,
bool V_120 )
{
struct V_67 * V_101 ;
struct V_14 * V_88 ;
* V_105 = V_124 ;
V_101 = F_12 ( V_104 ) ;
while ( V_101 ) {
V_88 = F_13 ( V_101 , struct V_14 , V_111 ) ;
V_101 = F_14 ( V_101 ) ;
F_128 ( V_105 , V_88 ) ;
if ( V_235 )
F_120 ( V_235 , 1 ) ;
V_1 -> V_112 ++ ;
if ( ! V_88 -> V_72 ) {
V_1 -> V_113 ++ ;
F_6 ( V_1 , V_88 ) ;
}
if ( ! V_88 -> V_99 ) {
F_129 ( V_1 , V_235 ,
& V_88 -> V_107 ,
& V_88 -> V_102 ,
V_239 ,
V_120 ) ;
continue;
}
if ( ! V_120 )
continue;
if ( V_240 . V_241 == V_242 ) {
T_2 V_173 = V_88 -> V_90 . V_75 ;
if ( V_10 . V_92 )
V_173 = V_88 -> V_93 -> V_75 ;
V_239 = V_173 * ( V_240 . V_243 / 100 ) ;
}
V_240 . V_238 ( & V_88 -> V_244 , V_88 -> V_94 ,
V_239 , & V_240 ) ;
}
}
static void F_130 ( struct V_103 * V_69 ,
struct V_14 * V_88 ,
T_2 V_239 ,
bool V_120 )
{
struct V_67 * * V_143 = & V_69 -> V_67 ;
struct V_67 * V_27 = NULL ;
struct V_14 * T_6 ;
struct V_198 * V_199 ;
if ( V_120 ) {
if ( V_240 . V_241 == V_242 ) {
T_2 V_173 = V_88 -> V_90 . V_75 ;
if ( V_10 . V_92 )
V_173 = V_88 -> V_93 -> V_75 ;
V_239 = V_173 * ( V_240 . V_243 / 100 ) ;
}
V_240 . V_238 ( & V_88 -> V_244 , V_88 -> V_94 ,
V_239 , & V_240 ) ;
}
while ( * V_143 != NULL ) {
V_27 = * V_143 ;
T_6 = F_13 ( V_27 , struct V_14 , V_67 ) ;
if ( F_121 ( V_88 , T_6 ) > 0 )
V_143 = & ( * V_143 ) -> V_146 ;
else
V_143 = & ( * V_143 ) -> V_147 ;
}
F_44 ( & V_88 -> V_67 , V_27 , V_143 ) ;
F_45 ( & V_88 -> V_67 , V_69 ) ;
F_102 (&perf_hpp_list, fmt) {
if ( F_83 ( V_199 ) &&
F_84 ( V_199 , V_88 -> V_1 ) )
V_199 -> V_238 ( V_199 , V_88 , NULL ) ;
}
}
static void F_131 ( struct V_1 * V_1 , struct V_234 * V_235 ,
bool V_120 , T_8 V_245 )
{
struct V_103 * V_226 ;
struct V_67 * V_68 ;
struct V_14 * V_70 ;
T_2 V_246 ;
T_2 V_239 ;
V_246 = V_1 -> V_138 ;
if ( V_10 . V_247 )
V_246 = V_1 -> V_139 ;
V_239 = V_246 * ( V_240 . V_243 / 100 ) ;
F_124 ( V_1 ) ;
F_4 ( V_1 ) ;
if ( V_10 . V_125 ) {
F_129 ( V_1 , V_235 ,
& V_1 -> V_109 ,
& V_1 -> V_69 ,
V_239 ,
V_120 ) ;
F_127 ( V_1 ) ;
return;
}
if ( F_22 ( V_1 , V_108 ) )
V_226 = & V_1 -> V_109 ;
else
V_226 = V_1 -> V_110 ;
V_68 = F_12 ( V_226 ) ;
V_1 -> V_69 = V_124 ;
while ( V_68 ) {
V_70 = F_13 ( V_68 , struct V_14 , V_111 ) ;
V_68 = F_14 ( & V_70 -> V_111 ) ;
if ( V_245 && V_245 ( V_70 ) )
continue;
F_130 ( & V_1 -> V_69 , V_70 , V_239 , V_120 ) ;
F_126 ( V_1 , V_70 ) ;
if ( ! V_70 -> V_72 )
F_6 ( V_1 , V_70 ) ;
if ( V_235 )
F_120 ( V_235 , 1 ) ;
}
}
void F_132 ( struct V_171 * V_169 , struct V_234 * V_235 )
{
bool V_120 ;
if ( V_169 && V_10 . V_120 && ! V_10 . V_248 )
V_120 = V_169 -> V_249 . V_250 & V_251 ;
else
V_120 = V_10 . V_120 ;
F_131 ( F_56 ( V_169 ) , V_235 , V_120 , NULL ) ;
}
void F_133 ( struct V_1 * V_1 , struct V_234 * V_235 )
{
F_131 ( V_1 , V_235 , V_10 . V_120 , NULL ) ;
}
void F_134 ( struct V_1 * V_1 , struct V_234 * V_235 ,
T_8 V_245 )
{
F_131 ( V_1 , V_235 , V_10 . V_120 , V_245 ) ;
}
static bool F_135 ( struct V_14 * V_88 , enum V_252 V_253 )
{
if ( V_88 -> V_99 || V_253 == V_254 )
return false ;
if ( V_88 -> V_255 || V_253 == V_256 )
return true ;
return false ;
}
struct V_67 * F_136 ( struct V_67 * V_101 )
{
struct V_14 * V_88 = F_13 ( V_101 , struct V_14 , V_67 ) ;
while ( F_135 ( V_88 , V_257 ) ) {
V_101 = F_137 ( & V_88 -> V_102 ) ;
V_88 = F_13 ( V_101 , struct V_14 , V_67 ) ;
}
return V_101 ;
}
struct V_67 * F_138 ( struct V_67 * V_101 , enum V_252 V_253 )
{
struct V_14 * V_88 = F_13 ( V_101 , struct V_14 , V_67 ) ;
if ( F_135 ( V_88 , V_253 ) )
V_101 = F_12 ( & V_88 -> V_102 ) ;
else
V_101 = F_14 ( V_101 ) ;
while ( V_101 == NULL ) {
V_88 = V_88 -> V_106 ;
if ( V_88 == NULL )
break;
V_101 = F_14 ( & V_88 -> V_67 ) ;
}
return V_101 ;
}
struct V_67 * F_139 ( struct V_67 * V_101 )
{
struct V_14 * V_88 = F_13 ( V_101 , struct V_14 , V_67 ) ;
V_101 = F_140 ( V_101 ) ;
if ( V_101 )
return F_136 ( V_101 ) ;
V_88 = V_88 -> V_106 ;
if ( V_88 == NULL )
return NULL ;
return & V_88 -> V_67 ;
}
bool F_141 ( struct V_14 * V_88 , float V_258 )
{
struct V_67 * V_101 ;
struct V_14 * V_100 ;
float V_259 ;
if ( V_88 -> V_99 )
return false ;
V_101 = F_12 ( & V_88 -> V_102 ) ;
V_100 = F_13 ( V_101 , struct V_14 , V_67 ) ;
while ( V_101 && V_100 -> V_72 ) {
V_101 = F_14 ( V_101 ) ;
V_100 = F_13 ( V_101 , struct V_14 , V_67 ) ;
}
if ( V_101 )
V_259 = F_142 ( V_100 ) ;
else
V_259 = 0 ;
return V_101 && V_259 >= V_258 ;
}
static void F_143 ( struct V_1 * V_1 , struct V_14 * V_15 ,
enum V_210 V_260 )
{
V_15 -> V_72 &= ~ ( 1 << V_260 ) ;
if ( V_10 . V_125 ) {
struct V_14 * V_27 = V_15 -> V_106 ;
while ( V_27 ) {
F_17 ( & V_27 -> V_90 , & V_15 -> V_90 ) ;
V_27 -> V_72 &= ~ ( 1 << V_260 ) ;
if ( V_27 -> V_72 )
goto V_68;
V_27 -> V_255 = false ;
V_27 -> V_261 = false ;
V_27 -> V_262 = 0 ;
V_27 -> V_263 = 0 ;
V_68:
V_27 = V_27 -> V_106 ;
}
}
if ( V_15 -> V_72 )
return;
V_15 -> V_255 = false ;
V_15 -> V_261 = false ;
V_15 -> V_262 = 0 ;
V_15 -> V_263 = 0 ;
V_1 -> V_96 . V_264 += V_15 -> V_90 . V_85 ;
F_125 ( V_1 , V_15 ) ;
F_6 ( V_1 , V_15 ) ;
}
static bool F_114 ( struct V_1 * V_1 ,
struct V_14 * V_88 )
{
if ( V_1 -> V_265 != NULL &&
( V_88 -> V_17 . V_26 == NULL || V_88 -> V_17 . V_26 -> V_7 != V_1 -> V_265 ) ) {
V_88 -> V_72 |= ( 1 << V_217 ) ;
return true ;
}
return false ;
}
static bool F_115 ( struct V_1 * V_1 ,
struct V_14 * V_88 )
{
if ( V_1 -> V_266 != NULL &&
V_88 -> V_23 != V_1 -> V_266 ) {
V_88 -> V_72 |= ( 1 << V_213 ) ;
return true ;
}
return false ;
}
static bool F_116 ( struct V_1 * V_1 ,
struct V_14 * V_88 )
{
if ( V_1 -> V_267 != NULL &&
( ! V_88 -> V_17 . V_18 || strstr ( V_88 -> V_17 . V_18 -> V_268 ,
V_1 -> V_267 ) == NULL ) ) {
V_88 -> V_72 |= ( 1 << V_218 ) ;
return true ;
}
return false ;
}
static bool F_117 ( struct V_1 * V_1 ,
struct V_14 * V_88 )
{
if ( ( V_1 -> V_269 > - 1 ) &&
( V_88 -> V_161 != V_1 -> V_269 ) ) {
V_88 -> V_72 |= ( 1 << V_222 ) ;
return true ;
}
return false ;
}
static void F_144 ( struct V_1 * V_1 , int type , T_9 V_260 )
{
struct V_67 * V_270 ;
V_1 -> V_96 . V_264 = 0 ;
F_123 ( V_1 ) ;
F_4 ( V_1 ) ;
for ( V_270 = F_12 ( & V_1 -> V_69 ) ; V_270 ; V_270 = F_14 ( V_270 ) ) {
struct V_14 * V_15 = F_13 ( V_270 , struct V_14 , V_67 ) ;
if ( V_260 ( V_1 , V_15 ) )
continue;
F_143 ( V_1 , V_15 , type ) ;
}
}
static void F_145 ( struct V_103 * V_226 , struct V_14 * V_88 )
{
struct V_67 * * V_143 = & V_226 -> V_67 ;
struct V_67 * V_27 = NULL ;
struct V_14 * T_6 ;
struct V_103 V_271 = V_124 ;
struct V_67 * V_270 ;
while ( * V_143 != NULL ) {
V_27 = * V_143 ;
T_6 = F_13 ( V_27 , struct V_14 , V_67 ) ;
if ( F_121 ( V_88 , T_6 ) > 0 )
V_143 = & ( * V_143 ) -> V_146 ;
else
V_143 = & ( * V_143 ) -> V_147 ;
}
F_44 ( & V_88 -> V_67 , V_27 , V_143 ) ;
F_45 ( & V_88 -> V_67 , V_226 ) ;
if ( V_88 -> V_99 || V_88 -> V_72 )
return;
V_270 = F_12 ( & V_88 -> V_102 ) ;
while ( V_270 ) {
struct V_14 * V_15 = F_13 ( V_270 , struct V_14 , V_67 ) ;
V_270 = F_14 ( V_270 ) ;
F_23 ( & V_15 -> V_67 , & V_88 -> V_102 ) ;
F_145 ( & V_271 , V_15 ) ;
}
V_88 -> V_102 = V_271 ;
}
static void F_146 ( struct V_1 * V_1 , int type , const void * V_187 )
{
struct V_67 * V_270 ;
struct V_103 V_271 = V_124 ;
V_1 -> V_96 . V_264 = 0 ;
F_123 ( V_1 ) ;
F_4 ( V_1 ) ;
V_270 = F_12 ( & V_1 -> V_69 ) ;
while ( V_270 ) {
struct V_14 * V_15 = F_13 ( V_270 , struct V_14 , V_67 ) ;
int V_230 ;
V_230 = F_147 ( V_15 , type , V_187 ) ;
if ( V_230 < 0 ) {
memset ( & V_15 -> V_90 , 0 , sizeof( V_15 -> V_90 ) ) ;
V_15 -> V_72 |= ( 1 << type ) ;
V_270 = F_138 ( & V_15 -> V_67 , V_256 ) ;
}
else if ( V_230 == 1 ) {
V_15 -> V_72 |= ( 1 << type ) ;
V_270 = F_138 ( & V_15 -> V_67 , V_254 ) ;
}
else {
F_143 ( V_1 , V_15 , type ) ;
V_270 = F_138 ( & V_15 -> V_67 , V_254 ) ;
}
}
F_127 ( V_1 ) ;
V_270 = F_12 ( & V_1 -> V_69 ) ;
while ( V_270 ) {
struct V_14 * V_15 = F_13 ( V_270 , struct V_14 , V_67 ) ;
V_270 = F_14 ( V_270 ) ;
F_23 ( & V_15 -> V_67 , & V_1 -> V_69 ) ;
F_145 ( & V_271 , V_15 ) ;
}
V_1 -> V_69 = V_271 ;
}
void F_148 ( struct V_1 * V_1 )
{
if ( V_10 . V_125 )
F_146 ( V_1 , V_213 ,
V_1 -> V_266 ) ;
else
F_144 ( V_1 , V_213 ,
F_115 ) ;
}
void F_149 ( struct V_1 * V_1 )
{
if ( V_10 . V_125 )
F_146 ( V_1 , V_217 ,
V_1 -> V_265 ) ;
else
F_144 ( V_1 , V_217 ,
F_114 ) ;
}
void F_150 ( struct V_1 * V_1 )
{
if ( V_10 . V_125 )
F_146 ( V_1 , V_218 ,
V_1 -> V_267 ) ;
else
F_144 ( V_1 , V_218 ,
F_116 ) ;
}
void F_151 ( struct V_1 * V_1 )
{
if ( V_10 . V_125 )
F_146 ( V_1 , V_222 ,
& V_1 -> V_269 ) ;
else
F_144 ( V_1 , V_222 ,
F_117 ) ;
}
void F_152 ( struct V_272 * V_96 , T_10 type )
{
++ V_96 -> V_85 [ 0 ] ;
++ V_96 -> V_85 [ type ] ;
}
void F_153 ( struct V_1 * V_1 , T_10 type )
{
F_152 ( & V_1 -> V_96 , type ) ;
}
void F_58 ( struct V_1 * V_1 , bool V_72 )
{
F_152 ( & V_1 -> V_96 , V_273 ) ;
if ( ! V_72 )
V_1 -> V_96 . V_264 ++ ;
}
static struct V_14 * F_154 ( struct V_1 * V_1 ,
struct V_14 * V_274 )
{
struct V_103 * V_226 ;
struct V_67 * * V_143 ;
struct V_67 * V_27 = NULL ;
struct V_14 * V_88 ;
T_5 V_144 ;
if ( F_22 ( V_1 , V_108 ) )
V_226 = & V_1 -> V_109 ;
else
V_226 = V_1 -> V_110 ;
V_143 = & V_226 -> V_67 ;
while ( * V_143 != NULL ) {
V_27 = * V_143 ;
V_88 = F_13 ( V_27 , struct V_14 , V_111 ) ;
V_144 = F_85 ( V_88 , V_274 ) ;
if ( ! V_144 )
goto V_145;
if ( V_144 < 0 )
V_143 = & ( * V_143 ) -> V_146 ;
else
V_143 = & ( * V_143 ) -> V_147 ;
}
V_88 = F_38 ( V_274 , true ) ;
if ( V_88 ) {
memset ( & V_88 -> V_90 , 0 , sizeof( V_88 -> V_90 ) ) ;
V_88 -> V_1 = V_1 ;
if ( V_10 . V_92 )
memset ( V_88 -> V_93 , 0 , sizeof( V_88 -> V_90 ) ) ;
F_44 ( & V_88 -> V_111 , V_27 , V_143 ) ;
F_45 ( & V_88 -> V_111 , V_226 ) ;
F_126 ( V_1 , V_88 ) ;
V_88 -> V_275 = true ;
}
V_145:
return V_88 ;
}
static struct V_14 * F_155 ( struct V_1 * V_1 ,
struct V_103 * V_226 ,
struct V_14 * V_274 )
{
struct V_67 * * V_143 ;
struct V_67 * V_27 = NULL ;
struct V_14 * V_88 ;
struct V_198 * V_199 ;
V_143 = & V_226 -> V_67 ;
while ( * V_143 != NULL ) {
T_5 V_144 = 0 ;
V_27 = * V_143 ;
V_88 = F_13 ( V_27 , struct V_14 , V_111 ) ;
F_102 (he->hpp_list, fmt) {
V_144 = V_199 -> V_200 ( V_199 , V_88 , V_274 ) ;
if ( V_144 )
break;
}
if ( ! V_144 )
goto V_145;
if ( V_144 < 0 )
V_143 = & V_27 -> V_146 ;
else
V_143 = & V_27 -> V_147 ;
}
V_88 = F_38 ( V_274 , true ) ;
if ( V_88 ) {
F_44 ( & V_88 -> V_111 , V_27 , V_143 ) ;
F_45 ( & V_88 -> V_111 , V_226 ) ;
V_88 -> V_275 = true ;
V_88 -> V_1 = V_1 ;
memset ( & V_88 -> V_90 , 0 , sizeof( V_88 -> V_90 ) ) ;
F_126 ( V_1 , V_88 ) ;
}
V_145:
return V_88 ;
}
static struct V_14 * F_156 ( struct V_1 * V_1 ,
struct V_14 * V_88 )
{
struct V_67 * V_70 ;
if ( F_22 ( V_1 , V_108 ) )
V_70 = V_1 -> V_109 . V_67 ;
else
V_70 = V_1 -> V_110 -> V_67 ;
while ( V_70 ) {
struct V_14 * T_6 = F_13 ( V_70 , struct V_14 , V_111 ) ;
T_5 V_144 = F_85 ( T_6 , V_88 ) ;
if ( V_144 < 0 )
V_70 = V_70 -> V_146 ;
else if ( V_144 > 0 )
V_70 = V_70 -> V_147 ;
else
return T_6 ;
}
return NULL ;
}
static struct V_14 * F_157 ( struct V_103 * V_226 ,
struct V_14 * V_88 )
{
struct V_67 * V_70 = V_226 -> V_67 ;
while ( V_70 ) {
struct V_14 * T_6 ;
struct V_198 * V_199 ;
T_5 V_144 = 0 ;
T_6 = F_13 ( V_70 , struct V_14 , V_111 ) ;
F_102 (he->hpp_list, fmt) {
V_144 = V_199 -> V_200 ( V_199 , T_6 , V_88 ) ;
if ( V_144 )
break;
}
if ( V_144 < 0 )
V_70 = V_70 -> V_146 ;
else if ( V_144 > 0 )
V_70 = V_70 -> V_147 ;
else
return T_6 ;
}
return NULL ;
}
static void F_158 ( struct V_103 * V_276 ,
struct V_103 * V_277 )
{
struct V_67 * V_270 ;
struct V_14 * V_278 , * V_274 ;
for ( V_270 = F_12 ( V_276 ) ; V_270 ; V_270 = F_14 ( V_270 ) ) {
V_278 = F_13 ( V_270 , struct V_14 , V_111 ) ;
V_274 = F_157 ( V_277 , V_278 ) ;
if ( V_274 ) {
F_159 ( V_274 , V_278 ) ;
F_158 ( & V_278 -> V_107 , & V_274 -> V_107 ) ;
}
}
}
void F_160 ( struct V_1 * V_279 , struct V_1 * V_280 )
{
struct V_103 * V_226 ;
struct V_67 * V_270 ;
struct V_14 * V_278 , * V_274 ;
if ( V_10 . V_125 ) {
return F_158 ( & V_279 -> V_109 ,
& V_280 -> V_109 ) ;
}
if ( F_22 ( V_279 , V_108 ) )
V_226 = & V_279 -> V_109 ;
else
V_226 = V_279 -> V_110 ;
for ( V_270 = F_12 ( V_226 ) ; V_270 ; V_270 = F_14 ( V_270 ) ) {
V_278 = F_13 ( V_270 , struct V_14 , V_111 ) ;
V_274 = F_156 ( V_280 , V_278 ) ;
if ( V_274 )
F_159 ( V_274 , V_278 ) ;
}
}
static int F_161 ( struct V_1 * V_281 ,
struct V_14 * V_27 ,
struct V_103 * V_276 ,
struct V_103 * V_277 )
{
struct V_67 * V_270 ;
struct V_14 * V_278 , * V_279 ;
for ( V_270 = F_12 ( V_277 ) ; V_270 ; V_270 = F_14 ( V_270 ) ) {
V_278 = F_13 ( V_270 , struct V_14 , V_111 ) ;
if ( F_162 ( V_278 ) ) {
bool V_282 = false ;
F_107 (leader, &pos->pairs.head, pairs.node) {
if ( V_279 -> V_1 == V_281 ) {
V_282 = true ;
break;
}
}
if ( ! V_282 )
return - 1 ;
} else {
V_279 = F_155 ( V_281 ,
V_276 , V_278 ) ;
if ( V_279 == NULL )
return - 1 ;
V_279 -> V_106 = V_27 ;
F_159 ( V_278 , V_279 ) ;
}
if ( ! V_278 -> V_99 ) {
if ( F_161 ( V_281 , V_279 ,
& V_279 -> V_107 ,
& V_278 -> V_107 ) < 0 )
return - 1 ;
}
}
return 0 ;
}
int F_163 ( struct V_1 * V_279 , struct V_1 * V_280 )
{
struct V_103 * V_226 ;
struct V_67 * V_270 ;
struct V_14 * V_278 , * V_274 ;
if ( V_10 . V_125 ) {
return F_161 ( V_279 , NULL ,
& V_279 -> V_109 ,
& V_280 -> V_109 ) ;
}
if ( F_22 ( V_280 , V_108 ) )
V_226 = & V_280 -> V_109 ;
else
V_226 = V_280 -> V_110 ;
for ( V_270 = F_12 ( V_226 ) ; V_270 ; V_270 = F_14 ( V_270 ) ) {
V_278 = F_13 ( V_270 , struct V_14 , V_111 ) ;
if ( ! F_162 ( V_278 ) ) {
V_274 = F_154 ( V_279 , V_278 ) ;
if ( V_274 == NULL )
return - 1 ;
F_159 ( V_278 , V_274 ) ;
}
}
return 0 ;
}
void F_164 ( struct V_174 * V_283 , struct V_141 * V_142 ,
struct V_151 * V_152 , bool V_284 )
{
struct V_29 * V_149 ;
if ( V_283 && V_283 -> V_175 && V_283 -> V_69 [ 0 ] . V_178 . V_179 ) {
int V_176 ;
V_149 = F_61 ( V_152 , V_142 ) ;
if ( V_149 ) {
struct V_285 * V_286 = NULL ;
for ( V_176 = V_283 -> V_175 - 1 ; V_176 >= 0 ; V_176 -- ) {
F_165 ( & V_149 [ V_176 ] . V_30 ,
V_284 ? NULL : V_286 ,
V_149 [ V_176 ] . V_178 . V_179 ) ;
V_286 = & V_149 [ V_176 ] . V_33 ;
}
free ( V_149 ) ;
}
}
}
T_3 F_166 ( struct V_287 * V_288 , T_11 * V_289 )
{
struct V_171 * V_278 ;
T_3 V_230 = 0 ;
F_167 (evlist, pos) {
V_230 += fprintf ( V_289 , L_3 , F_168 ( V_278 ) ) ;
V_230 += F_169 ( & F_56 ( V_278 ) -> V_96 , V_289 ) ;
}
return V_230 ;
}
T_2 F_170 ( struct V_1 * V_1 )
{
return V_10 . V_247 ? V_1 -> V_96 . V_98 :
V_1 -> V_96 . V_97 ;
}
int F_171 ( const struct V_290 * T_12 V_166 ,
const char * V_187 , int T_13 V_166 )
{
if ( ! strcmp ( V_187 , L_4 ) )
V_10 . V_247 = true ;
else if ( ! strcmp ( V_187 , L_5 ) )
V_10 . V_247 = false ;
else {
F_172 ( L_6 , V_187 ) ;
return - 1 ;
}
return 0 ;
}
int F_173 ( const char * V_291 , const char * V_292 )
{
if ( ! strcmp ( V_291 , L_7 ) )
return F_171 ( NULL , V_292 , 0 ) ;
return 0 ;
}
int F_174 ( struct V_1 * V_1 , struct V_227 * V_206 )
{
memset ( V_1 , 0 , sizeof( * V_1 ) ) ;
V_1 -> V_233 [ 0 ] = V_1 -> V_233 [ 1 ] = V_124 ;
V_1 -> V_110 = & V_1 -> V_233 [ 0 ] ;
V_1 -> V_109 = V_124 ;
V_1 -> V_69 = V_124 ;
F_175 ( & V_1 -> V_232 , NULL ) ;
V_1 -> V_269 = - 1 ;
V_1 -> V_206 = V_206 ;
F_33 ( & V_1 -> V_293 ) ;
return 0 ;
}
static void F_176 ( struct V_103 * V_226 )
{
struct V_67 * V_101 ;
struct V_14 * V_88 ;
while ( ! F_177 ( V_226 ) ) {
V_101 = F_12 ( V_226 ) ;
F_23 ( V_101 , V_226 ) ;
V_88 = F_13 ( V_101 , struct V_14 , V_111 ) ;
F_24 ( V_88 ) ;
}
}
static void F_178 ( struct V_1 * V_1 )
{
F_26 ( V_1 ) ;
F_176 ( & V_1 -> V_233 [ 0 ] ) ;
F_176 ( & V_1 -> V_233 [ 1 ] ) ;
F_176 ( & V_1 -> V_109 ) ;
}
static void F_179 ( struct V_171 * V_169 )
{
struct V_1 * V_1 = F_56 ( V_169 ) ;
struct V_198 * V_199 , * V_278 ;
struct V_228 * V_101 , * V_294 ;
F_178 ( V_1 ) ;
F_180 (node, tmp, &hists->hpp_formats, list) {
F_181 (&node->hpp, fmt, pos) {
F_182 ( & V_199 -> V_205 ) ;
free ( V_199 ) ;
}
F_182 ( & V_101 -> V_205 ) ;
free ( V_101 ) ;
}
}
static int F_183 ( struct V_171 * V_169 )
{
struct V_1 * V_1 = F_56 ( V_169 ) ;
F_174 ( V_1 , & V_227 ) ;
return 0 ;
}
int F_184 ( void )
{
int V_131 = F_185 ( sizeof( struct V_295 ) ,
F_183 ,
F_179 ) ;
if ( V_131 )
fputs ( L_8 , V_296 ) ;
return V_131 ;
}
void F_186 ( struct V_227 * V_205 )
{
F_33 ( & V_205 -> V_207 ) ;
F_33 ( & V_205 -> V_297 ) ;
}
