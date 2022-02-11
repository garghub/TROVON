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
}
void F_9 ( struct V_1 * V_1 , int V_46 )
{
struct V_47 * V_48 = F_10 ( & V_1 -> V_49 ) ;
struct V_14 * V_50 ;
int V_51 = 0 ;
F_4 ( V_1 ) ;
while ( V_48 && V_51 ++ < V_46 ) {
V_50 = F_11 ( V_48 , struct V_14 , V_47 ) ;
if ( ! V_50 -> V_52 )
F_6 ( V_1 , V_50 ) ;
V_48 = F_12 ( & V_50 -> V_47 ) ;
}
}
static void F_13 ( struct V_14 * V_53 ,
unsigned int V_54 , T_2 V_55 )
{
switch ( V_54 ) {
case V_56 :
V_53 -> V_57 . V_58 += V_55 ;
break;
case V_59 :
V_53 -> V_57 . V_60 += V_55 ;
break;
case V_61 :
V_53 -> V_57 . V_62 += V_55 ;
break;
case V_63 :
V_53 -> V_57 . V_64 += V_55 ;
break;
default:
break;
}
}
static void F_14 ( struct V_65 * V_65 , T_2 V_55 ,
T_2 V_66 )
{
V_65 -> V_55 += V_55 ;
V_65 -> V_66 += V_66 ;
V_65 -> V_67 += 1 ;
}
static void F_15 ( struct V_65 * V_68 , struct V_65 * V_69 )
{
V_68 -> V_55 += V_69 -> V_55 ;
V_68 -> V_58 += V_69 -> V_58 ;
V_68 -> V_60 += V_69 -> V_60 ;
V_68 -> V_62 += V_69 -> V_62 ;
V_68 -> V_64 += V_69 -> V_64 ;
V_68 -> V_67 += V_69 -> V_67 ;
V_68 -> V_66 += V_69 -> V_66 ;
}
static void F_16 ( struct V_14 * V_53 )
{
V_53 -> V_57 . V_55 = ( V_53 -> V_57 . V_55 * 7 ) / 8 ;
V_53 -> V_57 . V_67 = ( V_53 -> V_57 . V_67 * 7 ) / 8 ;
}
static bool F_17 ( struct V_1 * V_1 , struct V_14 * V_53 )
{
T_2 V_70 = V_53 -> V_57 . V_55 ;
if ( V_70 == 0 )
return true ;
F_16 ( V_53 ) ;
if ( ! V_53 -> V_52 )
V_1 -> V_71 . V_72 -= V_70 - V_53 -> V_57 . V_55 ;
return V_53 -> V_57 . V_55 == 0 ;
}
void F_18 ( struct V_1 * V_1 , bool V_73 , bool V_74 )
{
struct V_47 * V_48 = F_10 ( & V_1 -> V_49 ) ;
struct V_14 * V_50 ;
while ( V_48 ) {
V_50 = F_11 ( V_48 , struct V_14 , V_47 ) ;
V_48 = F_12 ( & V_50 -> V_47 ) ;
if ( ( ( V_73 && V_50 -> V_75 == '.' ) ||
( V_74 && V_50 -> V_75 != '.' ) ||
F_17 ( V_1 , V_50 ) ) &&
! V_50 -> V_76 ) {
F_19 ( & V_50 -> V_47 , & V_1 -> V_49 ) ;
if ( V_77 )
F_19 ( & V_50 -> V_78 , & V_1 -> V_79 ) ;
F_20 ( V_50 ) ;
-- V_1 -> V_80 ;
}
}
}
static struct V_14 * F_21 ( struct V_14 * V_81 )
{
T_3 V_82 = V_10 . V_83 ? sizeof( struct V_84 ) : 0 ;
struct V_14 * V_53 = F_22 ( sizeof( * V_53 ) + V_82 ) ;
if ( V_53 != NULL ) {
* V_53 = * V_81 ;
if ( V_53 -> V_17 . V_26 )
V_53 -> V_17 . V_26 -> V_85 = true ;
if ( V_53 -> V_29 ) {
V_53 -> V_29 = malloc ( sizeof( * V_53 -> V_29 ) ) ;
if ( V_53 -> V_29 == NULL ) {
free ( V_53 ) ;
return NULL ;
}
memcpy ( V_53 -> V_29 , V_81 -> V_29 ,
sizeof( * V_53 -> V_29 ) ) ;
if ( V_53 -> V_29 -> V_30 . V_26 )
V_53 -> V_29 -> V_30 . V_26 -> V_85 = true ;
if ( V_53 -> V_29 -> V_33 . V_26 )
V_53 -> V_29 -> V_33 . V_26 -> V_85 = true ;
}
if ( V_53 -> V_36 ) {
if ( V_53 -> V_36 -> V_86 . V_26 )
V_53 -> V_36 -> V_86 . V_26 -> V_85 = true ;
if ( V_53 -> V_36 -> V_37 . V_26 )
V_53 -> V_36 -> V_37 . V_26 -> V_85 = true ;
}
if ( V_10 . V_83 )
F_23 ( V_53 -> V_87 ) ;
F_24 ( & V_53 -> V_88 . V_89 ) ;
}
return V_53 ;
}
void F_25 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
if ( ! V_15 -> V_52 ) {
F_6 ( V_1 , V_15 ) ;
++ V_1 -> V_80 ;
V_1 -> V_71 . V_72 += V_15 -> V_57 . V_55 ;
}
}
static T_4 F_26 ( const struct V_90 * V_27 )
{
if ( V_10 . V_91 && V_27 == NULL )
return 1 << V_92 ;
return 0 ;
}
static struct V_14 * F_27 ( struct V_1 * V_1 ,
struct V_14 * V_93 ,
struct V_94 * V_95 ,
T_2 V_55 ,
T_2 V_66 )
{
struct V_47 * * V_96 ;
struct V_47 * V_27 = NULL ;
struct V_14 * V_53 ;
int V_97 ;
V_96 = & V_1 -> V_98 -> V_47 ;
while ( * V_96 != NULL ) {
V_27 = * V_96 ;
V_53 = F_11 ( V_27 , struct V_14 , V_78 ) ;
V_97 = F_28 ( V_53 , V_93 ) ;
if ( ! V_97 ) {
F_14 ( & V_53 -> V_57 , V_55 , V_66 ) ;
free ( V_93 -> V_36 ) ;
if ( V_53 -> V_17 . V_26 != V_93 -> V_17 . V_26 ) {
V_53 -> V_17 . V_26 = V_93 -> V_17 . V_26 ;
if ( V_53 -> V_17 . V_26 )
V_53 -> V_17 . V_26 -> V_85 = true ;
}
goto V_99;
}
if ( V_97 < 0 )
V_96 = & ( * V_96 ) -> V_100 ;
else
V_96 = & ( * V_96 ) -> V_101 ;
}
V_53 = F_21 ( V_93 ) ;
if ( ! V_53 )
return NULL ;
F_29 ( & V_53 -> V_78 , V_27 , V_96 ) ;
F_30 ( & V_53 -> V_78 , V_1 -> V_98 ) ;
V_99:
F_13 ( V_53 , V_95 -> V_54 , V_55 ) ;
return V_53 ;
}
struct V_14 * F_31 ( struct V_1 * V_102 ,
struct V_94 * V_95 ,
struct V_90 * V_103 ,
struct V_36 * V_104 ,
T_2 V_55 ,
T_2 V_66 )
{
struct V_14 V_93 = {
. V_23 = V_95 -> V_23 ,
. V_17 = {
. V_26 = V_95 -> V_26 ,
. V_18 = V_95 -> V_18 ,
} ,
. V_57 = {
. V_55 = V_55 ,
. V_66 = V_66 ,
. V_67 = 1 ,
} ,
. V_105 = V_95 -> V_105 ,
. V_106 = V_95 -> V_107 ,
. V_75 = V_95 -> V_75 ,
. V_27 = V_103 ,
. V_52 = F_26 ( V_103 ) ,
. V_1 = V_102 ,
. V_36 = V_104 ,
. V_29 = NULL ,
} ;
return F_27 ( V_102 , & V_93 , V_95 , V_55 , V_66 ) ;
}
struct V_14 * F_32 ( struct V_1 * V_102 ,
struct V_94 * V_95 ,
struct V_90 * V_103 ,
struct V_29 * V_108 ,
T_2 V_55 ,
T_2 V_66 )
{
struct V_14 V_93 = {
. V_23 = V_95 -> V_23 ,
. V_17 = {
. V_26 = V_108 -> V_33 . V_26 ,
. V_18 = V_108 -> V_33 . V_18 ,
} ,
. V_105 = V_95 -> V_105 ,
. V_106 = V_108 -> V_33 . V_107 ,
. V_75 = V_95 -> V_75 ,
. V_57 = {
. V_55 = V_55 ,
. V_67 = 1 ,
. V_66 = V_66 ,
} ,
. V_27 = V_103 ,
. V_52 = F_26 ( V_103 ) ,
. V_29 = V_108 ,
. V_1 = V_102 ,
. V_36 = NULL ,
} ;
return F_27 ( V_102 , & V_93 , V_95 , V_55 , V_66 ) ;
}
struct V_14 * F_33 ( struct V_1 * V_102 ,
struct V_94 * V_95 ,
struct V_90 * V_103 , T_2 V_55 ,
T_2 V_66 )
{
struct V_14 V_93 = {
. V_23 = V_95 -> V_23 ,
. V_17 = {
. V_26 = V_95 -> V_26 ,
. V_18 = V_95 -> V_18 ,
} ,
. V_105 = V_95 -> V_105 ,
. V_106 = V_95 -> V_107 ,
. V_75 = V_95 -> V_75 ,
. V_57 = {
. V_55 = V_55 ,
. V_67 = 1 ,
. V_66 = V_66 ,
} ,
. V_27 = V_103 ,
. V_52 = F_26 ( V_103 ) ,
. V_1 = V_102 ,
. V_29 = NULL ,
. V_36 = NULL ,
} ;
return F_27 ( V_102 , & V_93 , V_95 , V_55 , V_66 ) ;
}
T_5
F_28 ( struct V_14 * V_109 , struct V_14 * V_110 )
{
struct V_111 * V_112 ;
T_5 V_97 = 0 ;
F_34 (se, &hist_entry__sort_list, list) {
V_97 = V_112 -> V_113 ( V_109 , V_110 ) ;
if ( V_97 )
break;
}
return V_97 ;
}
T_5
F_35 ( struct V_14 * V_109 , struct V_14 * V_110 )
{
struct V_111 * V_112 ;
T_5 V_97 = 0 ;
F_34 (se, &hist_entry__sort_list, list) {
T_5 (* F_36)( struct V_14 * , struct V_14 * );
F_36 = V_112 -> V_114 ? : V_112 -> V_113 ;
V_97 = F_36 ( V_109 , V_110 ) ;
if ( V_97 )
break;
}
return V_97 ;
}
void F_20 ( struct V_14 * V_53 )
{
free ( V_53 -> V_29 ) ;
free ( V_53 -> V_36 ) ;
free ( V_53 ) ;
}
static bool F_37 ( struct V_1 * V_1 V_115 ,
struct V_116 * V_117 ,
struct V_14 * V_53 )
{
struct V_47 * * V_96 = & V_117 -> V_47 ;
struct V_47 * V_27 = NULL ;
struct V_14 * V_118 ;
T_5 V_97 ;
while ( * V_96 != NULL ) {
V_27 = * V_96 ;
V_118 = F_11 ( V_27 , struct V_14 , V_78 ) ;
V_97 = F_35 ( V_118 , V_53 ) ;
if ( ! V_97 ) {
F_15 ( & V_118 -> V_57 , & V_53 -> V_57 ) ;
if ( V_10 . V_83 ) {
F_38 ( & V_119 ) ;
F_39 ( & V_119 ,
V_118 -> V_87 ,
V_53 -> V_87 ) ;
}
F_20 ( V_53 ) ;
return false ;
}
if ( V_97 < 0 )
V_96 = & ( * V_96 ) -> V_100 ;
else
V_96 = & ( * V_96 ) -> V_101 ;
}
F_29 ( & V_53 -> V_78 , V_27 , V_96 ) ;
F_30 ( & V_53 -> V_78 , V_117 ) ;
return true ;
}
static struct V_116 * F_40 ( struct V_1 * V_1 )
{
struct V_116 * V_117 ;
F_41 ( & V_1 -> V_120 ) ;
V_117 = V_1 -> V_98 ;
if ( ++ V_1 -> V_98 > & V_1 -> V_121 [ 1 ] )
V_1 -> V_98 = & V_1 -> V_121 [ 0 ] ;
F_42 ( & V_1 -> V_120 ) ;
return V_117 ;
}
static void F_43 ( struct V_1 * V_1 , struct V_14 * V_53 )
{
F_44 ( V_1 , V_53 ) ;
F_45 ( V_1 , V_53 ) ;
F_46 ( V_1 , V_53 ) ;
}
void F_47 ( struct V_1 * V_1 )
{
struct V_116 * V_117 ;
struct V_47 * V_48 ;
struct V_14 * V_50 ;
if ( ! V_77 )
return;
V_117 = F_40 ( V_1 ) ;
V_48 = F_10 ( V_117 ) ;
while ( V_48 ) {
V_50 = F_11 ( V_48 , struct V_14 , V_78 ) ;
V_48 = F_12 ( & V_50 -> V_78 ) ;
F_19 ( & V_50 -> V_78 , V_117 ) ;
if ( F_37 ( V_1 , & V_1 -> V_79 , V_50 ) ) {
F_43 ( V_1 , V_50 ) ;
}
}
}
static int F_48 ( T_2 V_122 , T_2 V_123 )
{
if ( V_122 > V_123 )
return 1 ;
if ( V_122 < V_123 )
return - 1 ;
return 0 ;
}
static int F_49 ( struct V_14 * V_124 ,
struct V_14 * V_125 )
{
int V_126 ;
int V_127 , V_128 ;
struct V_129 * V_130 ;
struct V_14 * V_131 ;
T_2 * V_132 , * V_133 ;
V_126 = F_48 ( V_124 -> V_57 . V_55 , V_125 -> V_57 . V_55 ) ;
if ( V_126 || ! V_10 . V_134 )
return V_126 ;
V_130 = F_50 ( V_124 -> V_1 ) ;
V_128 = V_130 -> V_128 ;
if ( V_128 <= 1 )
return V_126 ;
V_132 = F_22 ( sizeof( V_132 ) * V_128 ) ;
V_133 = F_22 ( sizeof( V_133 ) * V_128 ) ;
if ( ! V_132 || ! V_133 )
goto V_99;
F_34 (pair, &a->pairs.head, pairs.node) {
V_130 = F_50 ( V_131 -> V_1 ) ;
V_132 [ F_51 ( V_130 ) ] = V_131 -> V_57 . V_55 ;
}
F_34 (pair, &b->pairs.head, pairs.node) {
V_130 = F_50 ( V_131 -> V_1 ) ;
V_133 [ F_51 ( V_130 ) ] = V_131 -> V_57 . V_55 ;
}
for ( V_127 = 1 ; V_127 < V_128 ; V_127 ++ ) {
V_126 = F_48 ( V_132 [ V_127 ] , V_133 [ V_127 ] ) ;
if ( V_126 )
break;
}
V_99:
free ( V_132 ) ;
free ( V_133 ) ;
return V_126 ;
}
static void F_52 ( struct V_116 * V_49 ,
struct V_14 * V_53 ,
T_2 V_135 )
{
struct V_47 * * V_96 = & V_49 -> V_47 ;
struct V_47 * V_27 = NULL ;
struct V_14 * V_118 ;
if ( V_10 . V_83 )
V_136 . V_137 ( & V_53 -> V_138 , V_53 -> V_87 ,
V_135 , & V_136 ) ;
while ( * V_96 != NULL ) {
V_27 = * V_96 ;
V_118 = F_11 ( V_27 , struct V_14 , V_47 ) ;
if ( F_49 ( V_53 , V_118 ) > 0 )
V_96 = & ( * V_96 ) -> V_100 ;
else
V_96 = & ( * V_96 ) -> V_101 ;
}
F_29 ( & V_53 -> V_47 , V_27 , V_96 ) ;
F_30 ( & V_53 -> V_47 , V_49 ) ;
}
void F_53 ( struct V_1 * V_1 )
{
struct V_116 * V_117 ;
struct V_47 * V_48 ;
struct V_14 * V_50 ;
T_2 V_135 ;
V_135 = V_1 -> V_71 . V_72 * ( V_136 . V_139 / 100 ) ;
if ( V_77 )
V_117 = & V_1 -> V_79 ;
else
V_117 = V_1 -> V_98 ;
V_48 = F_10 ( V_117 ) ;
V_1 -> V_49 = V_140 ;
V_1 -> V_80 = 0 ;
V_1 -> V_71 . V_72 = 0 ;
F_4 ( V_1 ) ;
while ( V_48 ) {
V_50 = F_11 ( V_48 , struct V_14 , V_78 ) ;
V_48 = F_12 ( & V_50 -> V_78 ) ;
F_52 ( & V_1 -> V_49 , V_50 , V_135 ) ;
F_25 ( V_1 , V_50 ) ;
}
}
static void F_54 ( struct V_1 * V_1 , struct V_14 * V_15 ,
enum V_141 V_142 )
{
V_15 -> V_52 &= ~ ( 1 << V_142 ) ;
if ( V_15 -> V_52 )
return;
++ V_1 -> V_80 ;
if ( V_15 -> V_17 . V_143 )
V_1 -> V_80 += V_15 -> V_144 ;
V_15 -> V_145 = 0 ;
V_1 -> V_71 . V_72 += V_15 -> V_57 . V_55 ;
V_1 -> V_71 . V_67 [ V_146 ] += V_15 -> V_57 . V_67 ;
F_6 ( V_1 , V_15 ) ;
}
static bool F_44 ( struct V_1 * V_1 ,
struct V_14 * V_53 )
{
if ( V_1 -> V_147 != NULL &&
( V_53 -> V_17 . V_26 == NULL || V_53 -> V_17 . V_26 -> V_7 != V_1 -> V_147 ) ) {
V_53 -> V_52 |= ( 1 << V_148 ) ;
return true ;
}
return false ;
}
void F_55 ( struct V_1 * V_1 )
{
struct V_47 * V_149 ;
V_1 -> V_80 = V_1 -> V_71 . V_72 = 0 ;
V_1 -> V_71 . V_67 [ V_146 ] = 0 ;
F_4 ( V_1 ) ;
for ( V_149 = F_10 ( & V_1 -> V_49 ) ; V_149 ; V_149 = F_12 ( V_149 ) ) {
struct V_14 * V_15 = F_11 ( V_149 , struct V_14 , V_47 ) ;
if ( V_10 . V_91 && ! V_15 -> V_27 )
continue;
if ( F_44 ( V_1 , V_15 ) )
continue;
F_54 ( V_1 , V_15 , V_148 ) ;
}
}
static bool F_45 ( struct V_1 * V_1 ,
struct V_14 * V_53 )
{
if ( V_1 -> V_150 != NULL &&
V_53 -> V_23 != V_1 -> V_150 ) {
V_53 -> V_52 |= ( 1 << V_151 ) ;
return true ;
}
return false ;
}
void F_56 ( struct V_1 * V_1 )
{
struct V_47 * V_149 ;
V_1 -> V_80 = V_1 -> V_71 . V_72 = 0 ;
V_1 -> V_71 . V_67 [ V_146 ] = 0 ;
F_4 ( V_1 ) ;
for ( V_149 = F_10 ( & V_1 -> V_49 ) ; V_149 ; V_149 = F_12 ( V_149 ) ) {
struct V_14 * V_15 = F_11 ( V_149 , struct V_14 , V_47 ) ;
if ( F_45 ( V_1 , V_15 ) )
continue;
F_54 ( V_1 , V_15 , V_151 ) ;
}
}
static bool F_46 ( struct V_1 * V_1 ,
struct V_14 * V_53 )
{
if ( V_1 -> V_152 != NULL &&
( ! V_53 -> V_17 . V_18 || strstr ( V_53 -> V_17 . V_18 -> V_153 ,
V_1 -> V_152 ) == NULL ) ) {
V_53 -> V_52 |= ( 1 << V_154 ) ;
return true ;
}
return false ;
}
void F_57 ( struct V_1 * V_1 )
{
struct V_47 * V_149 ;
V_1 -> V_80 = V_1 -> V_71 . V_72 = 0 ;
V_1 -> V_71 . V_67 [ V_146 ] = 0 ;
F_4 ( V_1 ) ;
for ( V_149 = F_10 ( & V_1 -> V_49 ) ; V_149 ; V_149 = F_12 ( V_149 ) ) {
struct V_14 * V_15 = F_11 ( V_149 , struct V_14 , V_47 ) ;
if ( F_46 ( V_1 , V_15 ) )
continue;
F_54 ( V_1 , V_15 , V_154 ) ;
}
}
int F_58 ( struct V_14 * V_53 , int V_155 , T_2 V_106 )
{
return F_59 ( V_53 -> V_17 . V_18 , V_53 -> V_17 . V_26 , V_155 , V_106 ) ;
}
int F_60 ( struct V_14 * V_53 , T_3 V_156 )
{
return F_61 ( V_53 -> V_17 . V_18 , V_53 -> V_17 . V_26 , V_156 ) ;
}
void F_62 ( struct V_157 * V_71 , T_6 type )
{
++ V_71 -> V_67 [ 0 ] ;
++ V_71 -> V_67 [ type ] ;
}
void F_63 ( struct V_1 * V_1 , T_6 type )
{
F_62 ( & V_1 -> V_71 , type ) ;
}
static struct V_14 * F_64 ( struct V_1 * V_1 ,
struct V_14 * V_131 )
{
struct V_116 * V_117 ;
struct V_47 * * V_96 ;
struct V_47 * V_27 = NULL ;
struct V_14 * V_53 ;
int V_97 ;
if ( V_77 )
V_117 = & V_1 -> V_79 ;
else
V_117 = V_1 -> V_98 ;
V_96 = & V_117 -> V_47 ;
while ( * V_96 != NULL ) {
V_27 = * V_96 ;
V_53 = F_11 ( V_27 , struct V_14 , V_78 ) ;
V_97 = F_35 ( V_53 , V_131 ) ;
if ( ! V_97 )
goto V_99;
if ( V_97 < 0 )
V_96 = & ( * V_96 ) -> V_100 ;
else
V_96 = & ( * V_96 ) -> V_101 ;
}
V_53 = F_21 ( V_131 ) ;
if ( V_53 ) {
memset ( & V_53 -> V_57 , 0 , sizeof( V_53 -> V_57 ) ) ;
V_53 -> V_1 = V_1 ;
F_29 ( & V_53 -> V_78 , V_27 , V_96 ) ;
F_30 ( & V_53 -> V_78 , V_117 ) ;
F_25 ( V_1 , V_53 ) ;
}
V_99:
return V_53 ;
}
static struct V_14 * F_65 ( struct V_1 * V_1 ,
struct V_14 * V_53 )
{
struct V_47 * V_50 ;
if ( V_77 )
V_50 = V_1 -> V_79 . V_47 ;
else
V_50 = V_1 -> V_98 -> V_47 ;
while ( V_50 ) {
struct V_14 * V_118 = F_11 ( V_50 , struct V_14 , V_78 ) ;
T_5 V_97 = F_35 ( V_118 , V_53 ) ;
if ( V_97 < 0 )
V_50 = V_50 -> V_100 ;
else if ( V_97 > 0 )
V_50 = V_50 -> V_101 ;
else
return V_118 ;
}
return NULL ;
}
void F_66 ( struct V_1 * V_158 , struct V_1 * V_159 )
{
struct V_116 * V_117 ;
struct V_47 * V_149 ;
struct V_14 * V_160 , * V_131 ;
if ( V_77 )
V_117 = & V_158 -> V_79 ;
else
V_117 = V_158 -> V_98 ;
for ( V_149 = F_10 ( V_117 ) ; V_149 ; V_149 = F_12 ( V_149 ) ) {
V_160 = F_11 ( V_149 , struct V_14 , V_78 ) ;
V_131 = F_65 ( V_159 , V_160 ) ;
if ( V_131 )
F_67 ( V_131 , V_160 ) ;
}
}
int F_68 ( struct V_1 * V_158 , struct V_1 * V_159 )
{
struct V_116 * V_117 ;
struct V_47 * V_149 ;
struct V_14 * V_160 , * V_131 ;
if ( V_77 )
V_117 = & V_159 -> V_79 ;
else
V_117 = V_159 -> V_98 ;
for ( V_149 = F_10 ( V_117 ) ; V_149 ; V_149 = F_12 ( V_149 ) ) {
V_160 = F_11 ( V_149 , struct V_14 , V_78 ) ;
if ( ! F_69 ( V_160 ) ) {
V_131 = F_64 ( V_158 , V_160 ) ;
if ( V_131 == NULL )
return - 1 ;
F_67 ( V_160 , V_131 ) ;
}
}
return 0 ;
}
