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
} else {
V_16 = V_8 + 4 + 2 ;
F_3 ( V_1 , V_38 ,
V_16 ) ;
}
if ( V_15 -> V_36 -> V_37 . V_26 ) {
V_16 = F_8 ( V_15 -> V_36 -> V_37 . V_26 -> V_7 ) ;
F_3 ( V_1 , V_39 ,
V_16 ) ;
} else {
V_16 = V_8 + 4 + 2 ;
F_5 ( V_1 , V_39 ) ;
}
} else {
V_16 = V_8 + 4 + 2 ;
F_3 ( V_1 , V_38 , V_16 ) ;
F_5 ( V_1 , V_39 ) ;
}
F_3 ( V_1 , V_40 , 6 ) ;
F_3 ( V_1 , V_41 , 22 ) ;
F_3 ( V_1 , V_42 , 12 ) ;
F_3 ( V_1 , V_43 , 21 + 3 ) ;
F_3 ( V_1 , V_44 , 12 ) ;
F_3 ( V_1 , V_45 , 12 ) ;
if ( V_15 -> V_46 )
F_3 ( V_1 , V_47 ,
F_9 () ) ;
}
void F_10 ( struct V_1 * V_1 , int V_48 )
{
struct V_49 * V_50 = F_11 ( & V_1 -> V_51 ) ;
struct V_14 * V_52 ;
int V_53 = 0 ;
F_4 ( V_1 ) ;
while ( V_50 && V_53 ++ < V_48 ) {
V_52 = F_12 ( V_50 , struct V_14 , V_49 ) ;
if ( ! V_52 -> V_54 )
F_6 ( V_1 , V_52 ) ;
V_50 = F_13 ( & V_52 -> V_49 ) ;
}
}
static void F_14 ( struct V_14 * V_55 ,
unsigned int V_56 , T_2 V_57 )
{
switch ( V_56 ) {
case V_58 :
V_55 -> V_59 . V_60 += V_57 ;
break;
case V_61 :
V_55 -> V_59 . V_62 += V_57 ;
break;
case V_63 :
V_55 -> V_59 . V_64 += V_57 ;
break;
case V_65 :
V_55 -> V_59 . V_66 += V_57 ;
break;
default:
break;
}
}
static void F_15 ( struct V_67 * V_67 , T_2 V_57 ,
T_2 V_68 )
{
V_67 -> V_57 += V_57 ;
V_67 -> V_68 += V_68 ;
V_67 -> V_69 += 1 ;
}
static void F_16 ( struct V_67 * V_70 , struct V_67 * V_71 )
{
V_70 -> V_57 += V_71 -> V_57 ;
V_70 -> V_60 += V_71 -> V_60 ;
V_70 -> V_62 += V_71 -> V_62 ;
V_70 -> V_64 += V_71 -> V_64 ;
V_70 -> V_66 += V_71 -> V_66 ;
V_70 -> V_69 += V_71 -> V_69 ;
V_70 -> V_68 += V_71 -> V_68 ;
}
static void F_17 ( struct V_14 * V_55 )
{
V_55 -> V_59 . V_57 = ( V_55 -> V_59 . V_57 * 7 ) / 8 ;
V_55 -> V_59 . V_69 = ( V_55 -> V_59 . V_69 * 7 ) / 8 ;
}
static bool F_18 ( struct V_1 * V_1 , struct V_14 * V_55 )
{
T_2 V_72 = V_55 -> V_59 . V_57 ;
if ( V_72 == 0 )
return true ;
F_17 ( V_55 ) ;
if ( ! V_55 -> V_54 )
V_1 -> V_73 . V_74 -= V_72 - V_55 -> V_59 . V_57 ;
return V_55 -> V_59 . V_57 == 0 ;
}
void F_19 ( struct V_1 * V_1 , bool V_75 , bool V_76 )
{
struct V_49 * V_50 = F_11 ( & V_1 -> V_51 ) ;
struct V_14 * V_52 ;
while ( V_50 ) {
V_52 = F_12 ( V_50 , struct V_14 , V_49 ) ;
V_50 = F_13 ( & V_52 -> V_49 ) ;
if ( ( ( V_75 && V_52 -> V_77 == '.' ) ||
( V_76 && V_52 -> V_77 != '.' ) ||
F_18 ( V_1 , V_52 ) ) &&
! V_52 -> V_78 ) {
F_20 ( & V_52 -> V_49 , & V_1 -> V_51 ) ;
if ( V_79 )
F_20 ( & V_52 -> V_80 , & V_1 -> V_81 ) ;
F_21 ( V_52 ) ;
-- V_1 -> V_82 ;
}
}
}
static struct V_14 * F_22 ( struct V_14 * V_83 )
{
T_3 V_84 = V_10 . V_85 ? sizeof( struct V_86 ) : 0 ;
struct V_14 * V_55 = F_23 ( sizeof( * V_55 ) + V_84 ) ;
if ( V_55 != NULL ) {
* V_55 = * V_83 ;
if ( V_55 -> V_17 . V_26 )
V_55 -> V_17 . V_26 -> V_87 = true ;
if ( V_55 -> V_29 ) {
V_55 -> V_29 = malloc ( sizeof( * V_55 -> V_29 ) ) ;
if ( V_55 -> V_29 == NULL ) {
free ( V_55 ) ;
return NULL ;
}
memcpy ( V_55 -> V_29 , V_83 -> V_29 ,
sizeof( * V_55 -> V_29 ) ) ;
if ( V_55 -> V_29 -> V_30 . V_26 )
V_55 -> V_29 -> V_30 . V_26 -> V_87 = true ;
if ( V_55 -> V_29 -> V_33 . V_26 )
V_55 -> V_29 -> V_33 . V_26 -> V_87 = true ;
}
if ( V_55 -> V_36 ) {
if ( V_55 -> V_36 -> V_88 . V_26 )
V_55 -> V_36 -> V_88 . V_26 -> V_87 = true ;
if ( V_55 -> V_36 -> V_37 . V_26 )
V_55 -> V_36 -> V_37 . V_26 -> V_87 = true ;
}
if ( V_10 . V_85 )
F_24 ( V_55 -> V_89 ) ;
F_25 ( & V_55 -> V_90 . V_91 ) ;
}
return V_55 ;
}
void F_26 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
if ( ! V_15 -> V_54 ) {
F_6 ( V_1 , V_15 ) ;
++ V_1 -> V_82 ;
V_1 -> V_73 . V_74 += V_15 -> V_59 . V_57 ;
}
}
static T_4 F_27 ( const struct V_92 * V_27 )
{
if ( V_10 . V_93 && V_27 == NULL )
return 1 << V_94 ;
return 0 ;
}
static struct V_14 * F_28 ( struct V_1 * V_1 ,
struct V_14 * V_95 ,
struct V_96 * V_97 ,
T_2 V_57 ,
T_2 V_68 )
{
struct V_49 * * V_98 ;
struct V_49 * V_27 = NULL ;
struct V_14 * V_55 ;
T_5 V_99 ;
V_98 = & V_1 -> V_100 -> V_49 ;
while ( * V_98 != NULL ) {
V_27 = * V_98 ;
V_55 = F_12 ( V_27 , struct V_14 , V_80 ) ;
V_99 = F_29 ( V_55 , V_95 ) ;
if ( ! V_99 ) {
F_15 ( & V_55 -> V_59 , V_57 , V_68 ) ;
free ( V_95 -> V_36 ) ;
if ( V_55 -> V_17 . V_26 != V_95 -> V_17 . V_26 ) {
V_55 -> V_17 . V_26 = V_95 -> V_17 . V_26 ;
if ( V_55 -> V_17 . V_26 )
V_55 -> V_17 . V_26 -> V_87 = true ;
}
goto V_101;
}
if ( V_99 < 0 )
V_98 = & ( * V_98 ) -> V_102 ;
else
V_98 = & ( * V_98 ) -> V_103 ;
}
V_55 = F_22 ( V_95 ) ;
if ( ! V_55 )
return NULL ;
V_1 -> V_82 ++ ;
F_30 ( & V_55 -> V_80 , V_27 , V_98 ) ;
F_31 ( & V_55 -> V_80 , V_1 -> V_100 ) ;
V_101:
F_14 ( V_55 , V_97 -> V_56 , V_57 ) ;
return V_55 ;
}
struct V_14 * F_32 ( struct V_1 * V_1 ,
struct V_96 * V_97 ,
struct V_92 * V_104 ,
struct V_29 * V_105 ,
struct V_36 * V_106 ,
T_2 V_57 , T_2 V_68 , T_2 V_46 )
{
struct V_14 V_95 = {
. V_23 = V_97 -> V_23 ,
. V_107 = F_33 ( V_97 -> V_23 ) ,
. V_17 = {
. V_26 = V_97 -> V_26 ,
. V_18 = V_97 -> V_18 ,
} ,
. V_108 = V_97 -> V_108 ,
. V_109 = V_97 -> V_110 ,
. V_77 = V_97 -> V_77 ,
. V_59 = {
. V_69 = 1 ,
. V_57 = V_57 ,
. V_68 = V_68 ,
} ,
. V_27 = V_104 ,
. V_54 = F_27 ( V_104 ) ,
. V_1 = V_1 ,
. V_29 = V_105 ,
. V_36 = V_106 ,
. V_46 = V_46 ,
} ;
return F_28 ( V_1 , & V_95 , V_97 , V_57 , V_68 ) ;
}
T_5
F_29 ( struct V_14 * V_111 , struct V_14 * V_112 )
{
struct V_113 * V_114 ;
T_5 V_99 = 0 ;
F_34 (se, &hist_entry__sort_list, list) {
V_99 = V_114 -> V_115 ( V_111 , V_112 ) ;
if ( V_99 )
break;
}
return V_99 ;
}
T_5
F_35 ( struct V_14 * V_111 , struct V_14 * V_112 )
{
struct V_113 * V_114 ;
T_5 V_99 = 0 ;
F_34 (se, &hist_entry__sort_list, list) {
T_5 (* F_36)( struct V_14 * , struct V_14 * );
F_36 = V_114 -> V_116 ? : V_114 -> V_115 ;
V_99 = F_36 ( V_111 , V_112 ) ;
if ( V_99 )
break;
}
return V_99 ;
}
void F_21 ( struct V_14 * V_55 )
{
free ( V_55 -> V_29 ) ;
free ( V_55 -> V_36 ) ;
F_37 ( V_55 -> V_117 ) ;
free ( V_55 ) ;
}
static bool F_38 ( struct V_1 * V_1 V_118 ,
struct V_119 * V_120 ,
struct V_14 * V_55 )
{
struct V_49 * * V_98 = & V_120 -> V_49 ;
struct V_49 * V_27 = NULL ;
struct V_14 * V_121 ;
T_5 V_99 ;
while ( * V_98 != NULL ) {
V_27 = * V_98 ;
V_121 = F_12 ( V_27 , struct V_14 , V_80 ) ;
V_99 = F_35 ( V_121 , V_55 ) ;
if ( ! V_99 ) {
F_16 ( & V_121 -> V_59 , & V_55 -> V_59 ) ;
if ( V_10 . V_85 ) {
F_39 ( & V_122 ) ;
F_40 ( & V_122 ,
V_121 -> V_89 ,
V_55 -> V_89 ) ;
}
F_21 ( V_55 ) ;
return false ;
}
if ( V_99 < 0 )
V_98 = & ( * V_98 ) -> V_102 ;
else
V_98 = & ( * V_98 ) -> V_103 ;
}
F_30 ( & V_55 -> V_80 , V_27 , V_98 ) ;
F_31 ( & V_55 -> V_80 , V_120 ) ;
return true ;
}
static struct V_119 * F_41 ( struct V_1 * V_1 )
{
struct V_119 * V_120 ;
F_42 ( & V_1 -> V_123 ) ;
V_120 = V_1 -> V_100 ;
if ( ++ V_1 -> V_100 > & V_1 -> V_124 [ 1 ] )
V_1 -> V_100 = & V_1 -> V_124 [ 0 ] ;
F_43 ( & V_1 -> V_123 ) ;
return V_120 ;
}
static void F_44 ( struct V_1 * V_1 , struct V_14 * V_55 )
{
F_45 ( V_1 , V_55 ) ;
F_46 ( V_1 , V_55 ) ;
F_47 ( V_1 , V_55 ) ;
}
void F_48 ( struct V_1 * V_1 , struct V_125 * V_126 )
{
struct V_119 * V_120 ;
struct V_49 * V_50 ;
struct V_14 * V_52 ;
if ( ! V_79 )
return;
V_120 = F_41 ( V_1 ) ;
V_50 = F_11 ( V_120 ) ;
while ( V_50 ) {
if ( F_49 () )
break;
V_52 = F_12 ( V_50 , struct V_14 , V_80 ) ;
V_50 = F_13 ( & V_52 -> V_80 ) ;
F_20 ( & V_52 -> V_80 , V_120 ) ;
if ( F_38 ( V_1 , & V_1 -> V_81 , V_52 ) ) {
F_44 ( V_1 , V_52 ) ;
}
if ( V_126 )
F_50 ( V_126 , 1 ) ;
}
}
static int F_51 ( T_2 V_127 , T_2 V_128 )
{
if ( V_127 > V_128 )
return 1 ;
if ( V_127 < V_128 )
return - 1 ;
return 0 ;
}
static int F_52 ( struct V_14 * V_129 ,
struct V_14 * V_130 )
{
int V_131 ;
int V_132 , V_133 ;
struct V_134 * V_135 ;
struct V_14 * V_136 ;
T_2 * V_137 , * V_138 ;
V_131 = F_51 ( V_129 -> V_59 . V_57 , V_130 -> V_59 . V_57 ) ;
if ( V_131 || ! V_10 . V_139 )
return V_131 ;
V_135 = F_53 ( V_129 -> V_1 ) ;
V_133 = V_135 -> V_133 ;
if ( V_133 <= 1 )
return V_131 ;
V_137 = F_23 ( sizeof( V_137 ) * V_133 ) ;
V_138 = F_23 ( sizeof( V_138 ) * V_133 ) ;
if ( ! V_137 || ! V_138 )
goto V_101;
F_34 (pair, &a->pairs.head, pairs.node) {
V_135 = F_53 ( V_136 -> V_1 ) ;
V_137 [ F_54 ( V_135 ) ] = V_136 -> V_59 . V_57 ;
}
F_34 (pair, &b->pairs.head, pairs.node) {
V_135 = F_53 ( V_136 -> V_1 ) ;
V_138 [ F_54 ( V_135 ) ] = V_136 -> V_59 . V_57 ;
}
for ( V_132 = 1 ; V_132 < V_133 ; V_132 ++ ) {
V_131 = F_51 ( V_137 [ V_132 ] , V_138 [ V_132 ] ) ;
if ( V_131 )
break;
}
V_101:
free ( V_137 ) ;
free ( V_138 ) ;
return V_131 ;
}
static void F_55 ( struct V_119 * V_51 ,
struct V_14 * V_55 ,
T_2 V_140 )
{
struct V_49 * * V_98 = & V_51 -> V_49 ;
struct V_49 * V_27 = NULL ;
struct V_14 * V_121 ;
if ( V_10 . V_85 )
V_141 . V_142 ( & V_55 -> V_143 , V_55 -> V_89 ,
V_140 , & V_141 ) ;
while ( * V_98 != NULL ) {
V_27 = * V_98 ;
V_121 = F_12 ( V_27 , struct V_14 , V_49 ) ;
if ( F_52 ( V_55 , V_121 ) > 0 )
V_98 = & ( * V_98 ) -> V_102 ;
else
V_98 = & ( * V_98 ) -> V_103 ;
}
F_30 ( & V_55 -> V_49 , V_27 , V_98 ) ;
F_31 ( & V_55 -> V_49 , V_51 ) ;
}
void F_56 ( struct V_1 * V_1 )
{
struct V_119 * V_120 ;
struct V_49 * V_50 ;
struct V_14 * V_52 ;
T_2 V_140 ;
V_140 = V_1 -> V_73 . V_74 * ( V_141 . V_144 / 100 ) ;
if ( V_79 )
V_120 = & V_1 -> V_81 ;
else
V_120 = V_1 -> V_100 ;
V_50 = F_11 ( V_120 ) ;
V_1 -> V_51 = V_145 ;
V_1 -> V_82 = 0 ;
V_1 -> V_73 . V_74 = 0 ;
F_4 ( V_1 ) ;
while ( V_50 ) {
V_52 = F_12 ( V_50 , struct V_14 , V_80 ) ;
V_50 = F_13 ( & V_52 -> V_80 ) ;
F_55 ( & V_1 -> V_51 , V_52 , V_140 ) ;
F_26 ( V_1 , V_52 ) ;
}
}
static void F_57 ( struct V_1 * V_1 , struct V_14 * V_15 ,
enum V_146 V_147 )
{
V_15 -> V_54 &= ~ ( 1 << V_147 ) ;
if ( V_15 -> V_54 )
return;
++ V_1 -> V_82 ;
if ( V_15 -> V_17 . V_148 )
V_1 -> V_82 += V_15 -> V_149 ;
V_15 -> V_150 = 0 ;
V_1 -> V_73 . V_74 += V_15 -> V_59 . V_57 ;
V_1 -> V_73 . V_69 [ V_151 ] += V_15 -> V_59 . V_69 ;
F_6 ( V_1 , V_15 ) ;
}
static bool F_45 ( struct V_1 * V_1 ,
struct V_14 * V_55 )
{
if ( V_1 -> V_152 != NULL &&
( V_55 -> V_17 . V_26 == NULL || V_55 -> V_17 . V_26 -> V_7 != V_1 -> V_152 ) ) {
V_55 -> V_54 |= ( 1 << V_153 ) ;
return true ;
}
return false ;
}
void F_58 ( struct V_1 * V_1 )
{
struct V_49 * V_154 ;
V_1 -> V_82 = V_1 -> V_73 . V_74 = 0 ;
V_1 -> V_73 . V_69 [ V_151 ] = 0 ;
F_4 ( V_1 ) ;
for ( V_154 = F_11 ( & V_1 -> V_51 ) ; V_154 ; V_154 = F_13 ( V_154 ) ) {
struct V_14 * V_15 = F_12 ( V_154 , struct V_14 , V_49 ) ;
if ( V_10 . V_93 && ! V_15 -> V_27 )
continue;
if ( F_45 ( V_1 , V_15 ) )
continue;
F_57 ( V_1 , V_15 , V_153 ) ;
}
}
static bool F_46 ( struct V_1 * V_1 ,
struct V_14 * V_55 )
{
if ( V_1 -> V_155 != NULL &&
V_55 -> V_23 != V_1 -> V_155 ) {
V_55 -> V_54 |= ( 1 << V_156 ) ;
return true ;
}
return false ;
}
void F_59 ( struct V_1 * V_1 )
{
struct V_49 * V_154 ;
V_1 -> V_82 = V_1 -> V_73 . V_74 = 0 ;
V_1 -> V_73 . V_69 [ V_151 ] = 0 ;
F_4 ( V_1 ) ;
for ( V_154 = F_11 ( & V_1 -> V_51 ) ; V_154 ; V_154 = F_13 ( V_154 ) ) {
struct V_14 * V_15 = F_12 ( V_154 , struct V_14 , V_49 ) ;
if ( F_46 ( V_1 , V_15 ) )
continue;
F_57 ( V_1 , V_15 , V_156 ) ;
}
}
static bool F_47 ( struct V_1 * V_1 ,
struct V_14 * V_55 )
{
if ( V_1 -> V_157 != NULL &&
( ! V_55 -> V_17 . V_18 || strstr ( V_55 -> V_17 . V_18 -> V_158 ,
V_1 -> V_157 ) == NULL ) ) {
V_55 -> V_54 |= ( 1 << V_159 ) ;
return true ;
}
return false ;
}
void F_60 ( struct V_1 * V_1 )
{
struct V_49 * V_154 ;
V_1 -> V_82 = V_1 -> V_73 . V_74 = 0 ;
V_1 -> V_73 . V_69 [ V_151 ] = 0 ;
F_4 ( V_1 ) ;
for ( V_154 = F_11 ( & V_1 -> V_51 ) ; V_154 ; V_154 = F_13 ( V_154 ) ) {
struct V_14 * V_15 = F_12 ( V_154 , struct V_14 , V_49 ) ;
if ( F_47 ( V_1 , V_15 ) )
continue;
F_57 ( V_1 , V_15 , V_159 ) ;
}
}
int F_61 ( struct V_14 * V_55 , int V_160 , T_2 V_109 )
{
return F_62 ( V_55 -> V_17 . V_18 , V_55 -> V_17 . V_26 , V_160 , V_109 ) ;
}
int F_63 ( struct V_14 * V_55 , T_3 V_161 )
{
return F_64 ( V_55 -> V_17 . V_18 , V_55 -> V_17 . V_26 , V_161 ) ;
}
void F_65 ( struct V_162 * V_73 , T_6 type )
{
++ V_73 -> V_69 [ 0 ] ;
++ V_73 -> V_69 [ type ] ;
}
void F_66 ( struct V_1 * V_1 , T_6 type )
{
F_65 ( & V_1 -> V_73 , type ) ;
}
static struct V_14 * F_67 ( struct V_1 * V_1 ,
struct V_14 * V_136 )
{
struct V_119 * V_120 ;
struct V_49 * * V_98 ;
struct V_49 * V_27 = NULL ;
struct V_14 * V_55 ;
T_5 V_99 ;
if ( V_79 )
V_120 = & V_1 -> V_81 ;
else
V_120 = V_1 -> V_100 ;
V_98 = & V_120 -> V_49 ;
while ( * V_98 != NULL ) {
V_27 = * V_98 ;
V_55 = F_12 ( V_27 , struct V_14 , V_80 ) ;
V_99 = F_35 ( V_55 , V_136 ) ;
if ( ! V_99 )
goto V_101;
if ( V_99 < 0 )
V_98 = & ( * V_98 ) -> V_102 ;
else
V_98 = & ( * V_98 ) -> V_103 ;
}
V_55 = F_22 ( V_136 ) ;
if ( V_55 ) {
memset ( & V_55 -> V_59 , 0 , sizeof( V_55 -> V_59 ) ) ;
V_55 -> V_1 = V_1 ;
F_30 ( & V_55 -> V_80 , V_27 , V_98 ) ;
F_31 ( & V_55 -> V_80 , V_120 ) ;
F_26 ( V_1 , V_55 ) ;
V_55 -> V_163 = true ;
}
V_101:
return V_55 ;
}
static struct V_14 * F_68 ( struct V_1 * V_1 ,
struct V_14 * V_55 )
{
struct V_49 * V_52 ;
if ( V_79 )
V_52 = V_1 -> V_81 . V_49 ;
else
V_52 = V_1 -> V_100 -> V_49 ;
while ( V_52 ) {
struct V_14 * V_121 = F_12 ( V_52 , struct V_14 , V_80 ) ;
T_5 V_99 = F_35 ( V_121 , V_55 ) ;
if ( V_99 < 0 )
V_52 = V_52 -> V_102 ;
else if ( V_99 > 0 )
V_52 = V_52 -> V_103 ;
else
return V_121 ;
}
return NULL ;
}
void F_69 ( struct V_1 * V_164 , struct V_1 * V_165 )
{
struct V_119 * V_120 ;
struct V_49 * V_154 ;
struct V_14 * V_166 , * V_136 ;
if ( V_79 )
V_120 = & V_164 -> V_81 ;
else
V_120 = V_164 -> V_100 ;
for ( V_154 = F_11 ( V_120 ) ; V_154 ; V_154 = F_13 ( V_154 ) ) {
V_166 = F_12 ( V_154 , struct V_14 , V_80 ) ;
V_136 = F_68 ( V_165 , V_166 ) ;
if ( V_136 )
F_70 ( V_136 , V_166 ) ;
}
}
int F_71 ( struct V_1 * V_164 , struct V_1 * V_165 )
{
struct V_119 * V_120 ;
struct V_49 * V_154 ;
struct V_14 * V_166 , * V_136 ;
if ( V_79 )
V_120 = & V_165 -> V_81 ;
else
V_120 = V_165 -> V_100 ;
for ( V_154 = F_11 ( V_120 ) ; V_154 ; V_154 = F_13 ( V_154 ) ) {
V_166 = F_12 ( V_154 , struct V_14 , V_80 ) ;
if ( ! F_72 ( V_166 ) ) {
V_136 = F_67 ( V_164 , V_166 ) ;
if ( V_136 == NULL )
return - 1 ;
F_70 ( V_166 , V_136 ) ;
}
}
return 0 ;
}
