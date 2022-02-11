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
if ( V_15 -> V_17 . V_18 )
F_3 ( V_1 , V_19 , V_15 -> V_17 . V_18 -> V_20 + 4 ) ;
else {
V_16 = V_8 + 4 + 2 ;
F_3 ( V_1 , V_19 , V_16 ) ;
F_5 ( V_1 , V_21 ) ;
}
V_5 = F_7 ( V_15 -> V_22 ) ;
if ( F_3 ( V_1 , V_23 , V_5 ) )
F_2 ( V_1 , V_24 , V_5 + 6 ) ;
if ( V_15 -> V_17 . V_25 ) {
V_5 = F_8 ( V_15 -> V_17 . V_25 -> V_7 ) ;
F_3 ( V_1 , V_21 , V_5 ) ;
}
if ( V_15 -> V_26 )
F_3 ( V_1 , V_27 , V_15 -> V_26 -> V_20 ) ;
if ( V_15 -> V_28 ) {
if ( V_15 -> V_28 -> V_29 . V_18 ) {
V_16 = ( int ) V_15 -> V_28 -> V_29 . V_18 -> V_20 + 4 ;
F_3 ( V_1 , V_30 , V_16 ) ;
V_16 = F_8 ( V_15 -> V_28 -> V_29 . V_25 -> V_7 ) ;
F_3 ( V_1 , V_31 , V_16 ) ;
} else {
V_16 = V_8 + 4 + 2 ;
F_3 ( V_1 , V_30 , V_16 ) ;
F_5 ( V_1 , V_31 ) ;
}
if ( V_15 -> V_28 -> V_32 . V_18 ) {
V_16 = ( int ) V_15 -> V_28 -> V_32 . V_18 -> V_20 + 4 ;
F_3 ( V_1 , V_33 , V_16 ) ;
V_16 = F_8 ( V_15 -> V_28 -> V_32 . V_25 -> V_7 ) ;
F_3 ( V_1 , V_34 , V_16 ) ;
} else {
V_16 = V_8 + 4 + 2 ;
F_3 ( V_1 , V_33 , V_16 ) ;
F_5 ( V_1 , V_34 ) ;
}
}
if ( V_15 -> V_35 ) {
if ( V_15 -> V_35 -> V_36 . V_18 ) {
V_16 = ( int ) V_15 -> V_35 -> V_36 . V_18 -> V_20 + 4
+ V_8 + 2 ;
F_3 ( V_1 , V_37 ,
V_16 ) ;
} else {
V_16 = V_8 + 4 + 2 ;
F_3 ( V_1 , V_37 ,
V_16 ) ;
}
if ( V_15 -> V_35 -> V_36 . V_25 ) {
V_16 = F_8 ( V_15 -> V_35 -> V_36 . V_25 -> V_7 ) ;
F_3 ( V_1 , V_38 ,
V_16 ) ;
} else {
V_16 = V_8 + 4 + 2 ;
F_5 ( V_1 , V_38 ) ;
}
} else {
V_16 = V_8 + 4 + 2 ;
F_3 ( V_1 , V_37 , V_16 ) ;
F_5 ( V_1 , V_38 ) ;
}
F_3 ( V_1 , V_39 , 6 ) ;
F_3 ( V_1 , V_40 , 22 ) ;
F_3 ( V_1 , V_41 , 12 ) ;
F_3 ( V_1 , V_42 , 21 + 3 ) ;
F_3 ( V_1 , V_43 , 12 ) ;
F_3 ( V_1 , V_44 , 12 ) ;
}
void F_9 ( struct V_1 * V_1 , int V_45 )
{
struct V_46 * V_47 = F_10 ( & V_1 -> V_48 ) ;
struct V_14 * V_49 ;
int V_50 = 0 ;
F_4 ( V_1 ) ;
while ( V_47 && V_50 ++ < V_45 ) {
V_49 = F_11 ( V_47 , struct V_14 , V_46 ) ;
if ( ! V_49 -> V_51 )
F_6 ( V_1 , V_49 ) ;
V_47 = F_12 ( & V_49 -> V_46 ) ;
}
}
static void F_13 ( struct V_14 * V_52 ,
unsigned int V_53 , T_2 V_54 )
{
switch ( V_53 ) {
case V_55 :
V_52 -> V_56 . V_57 += V_54 ;
break;
case V_58 :
V_52 -> V_56 . V_59 += V_54 ;
break;
case V_60 :
V_52 -> V_56 . V_61 += V_54 ;
break;
case V_62 :
V_52 -> V_56 . V_63 += V_54 ;
break;
default:
break;
}
}
static void F_14 ( struct V_64 * V_64 , T_2 V_54 ,
T_2 V_65 )
{
V_64 -> V_54 += V_54 ;
V_64 -> V_65 += V_65 ;
V_64 -> V_66 += 1 ;
}
static void F_15 ( struct V_64 * V_67 , struct V_64 * V_68 )
{
V_67 -> V_54 += V_68 -> V_54 ;
V_67 -> V_57 += V_68 -> V_57 ;
V_67 -> V_59 += V_68 -> V_59 ;
V_67 -> V_61 += V_68 -> V_61 ;
V_67 -> V_63 += V_68 -> V_63 ;
V_67 -> V_66 += V_68 -> V_66 ;
V_67 -> V_65 += V_68 -> V_65 ;
}
static void F_16 ( struct V_14 * V_52 )
{
V_52 -> V_56 . V_54 = ( V_52 -> V_56 . V_54 * 7 ) / 8 ;
V_52 -> V_56 . V_66 = ( V_52 -> V_56 . V_66 * 7 ) / 8 ;
}
static bool F_17 ( struct V_1 * V_1 , struct V_14 * V_52 )
{
T_2 V_69 = V_52 -> V_56 . V_54 ;
if ( V_69 == 0 )
return true ;
F_16 ( V_52 ) ;
if ( ! V_52 -> V_51 )
V_1 -> V_70 . V_71 -= V_69 - V_52 -> V_56 . V_54 ;
return V_52 -> V_56 . V_54 == 0 ;
}
static void F_18 ( struct V_1 * V_1 , bool V_72 ,
bool V_73 , bool V_74 )
{
struct V_46 * V_47 = F_10 ( & V_1 -> V_48 ) ;
struct V_14 * V_49 ;
while ( V_47 ) {
V_49 = F_11 ( V_47 , struct V_14 , V_46 ) ;
V_47 = F_12 ( & V_49 -> V_46 ) ;
if ( ( ( V_72 && V_49 -> V_75 == '.' ) ||
( V_73 && V_49 -> V_75 != '.' ) ||
F_17 ( V_1 , V_49 ) ) &&
! V_49 -> V_76 ) {
F_19 ( & V_49 -> V_46 , & V_1 -> V_48 ) ;
if ( V_77 || V_74 )
F_19 ( & V_49 -> V_78 , & V_1 -> V_79 ) ;
F_20 ( V_49 ) ;
-- V_1 -> V_80 ;
}
}
}
void F_21 ( struct V_1 * V_1 , bool V_72 , bool V_73 )
{
return F_18 ( V_1 , V_72 , V_73 , false ) ;
}
void F_22 ( struct V_1 * V_1 ,
bool V_72 , bool V_73 )
{
return F_18 ( V_1 , V_72 , V_73 , true ) ;
}
static struct V_14 * F_23 ( struct V_14 * V_81 )
{
T_3 V_82 = V_10 . V_83 ? sizeof( struct V_84 ) : 0 ;
struct V_14 * V_52 = F_24 ( sizeof( * V_52 ) + V_82 ) ;
if ( V_52 != NULL ) {
* V_52 = * V_81 ;
if ( V_52 -> V_17 . V_25 )
V_52 -> V_17 . V_25 -> V_85 = true ;
if ( V_52 -> V_28 ) {
if ( V_52 -> V_28 -> V_29 . V_25 )
V_52 -> V_28 -> V_29 . V_25 -> V_85 = true ;
if ( V_52 -> V_28 -> V_32 . V_25 )
V_52 -> V_28 -> V_32 . V_25 -> V_85 = true ;
}
if ( V_52 -> V_35 ) {
if ( V_52 -> V_35 -> V_86 . V_25 )
V_52 -> V_35 -> V_86 . V_25 -> V_85 = true ;
if ( V_52 -> V_35 -> V_36 . V_25 )
V_52 -> V_35 -> V_36 . V_25 -> V_85 = true ;
}
if ( V_10 . V_83 )
F_25 ( V_52 -> V_87 ) ;
F_26 ( & V_52 -> V_88 . V_89 ) ;
}
return V_52 ;
}
void F_27 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
if ( ! V_15 -> V_51 ) {
F_6 ( V_1 , V_15 ) ;
++ V_1 -> V_80 ;
V_1 -> V_70 . V_71 += V_15 -> V_56 . V_54 ;
}
}
static T_4 F_28 ( const struct V_90 * V_26 )
{
if ( V_10 . V_91 && V_26 == NULL )
return 1 << V_92 ;
return 0 ;
}
static struct V_14 * F_29 ( struct V_1 * V_1 ,
struct V_14 * V_93 ,
struct V_94 * V_95 ,
T_2 V_54 ,
T_2 V_65 )
{
struct V_46 * * V_96 ;
struct V_46 * V_26 = NULL ;
struct V_14 * V_52 ;
int V_97 ;
F_30 ( & V_1 -> V_98 ) ;
V_96 = & V_1 -> V_99 -> V_46 ;
while ( * V_96 != NULL ) {
V_26 = * V_96 ;
V_52 = F_11 ( V_26 , struct V_14 , V_78 ) ;
V_97 = F_31 ( V_52 , V_93 ) ;
if ( ! V_97 ) {
F_14 ( & V_52 -> V_56 , V_54 , V_65 ) ;
if ( V_52 -> V_17 . V_25 != V_93 -> V_17 . V_25 ) {
V_52 -> V_17 . V_25 = V_93 -> V_17 . V_25 ;
if ( V_52 -> V_17 . V_25 )
V_52 -> V_17 . V_25 -> V_85 = true ;
}
goto V_100;
}
if ( V_97 < 0 )
V_96 = & ( * V_96 ) -> V_101 ;
else
V_96 = & ( * V_96 ) -> V_102 ;
}
V_52 = F_23 ( V_93 ) ;
if ( ! V_52 )
goto V_103;
F_32 ( & V_52 -> V_78 , V_26 , V_96 ) ;
F_33 ( & V_52 -> V_78 , V_1 -> V_99 ) ;
V_100:
F_13 ( V_52 , V_95 -> V_53 , V_54 ) ;
V_103:
F_34 ( & V_1 -> V_98 ) ;
return V_52 ;
}
struct V_14 * F_35 ( struct V_1 * V_104 ,
struct V_94 * V_95 ,
struct V_90 * V_105 ,
struct V_35 * V_106 ,
T_2 V_54 ,
T_2 V_65 )
{
struct V_14 V_93 = {
. V_22 = V_95 -> V_22 ,
. V_17 = {
. V_25 = V_95 -> V_25 ,
. V_18 = V_95 -> V_18 ,
} ,
. V_56 = {
. V_54 = V_54 ,
. V_65 = V_65 ,
. V_66 = 1 ,
} ,
. V_107 = V_95 -> V_107 ,
. V_108 = V_95 -> V_109 ,
. V_75 = V_95 -> V_75 ,
. V_26 = V_105 ,
. V_51 = F_28 ( V_105 ) ,
. V_1 = V_104 ,
. V_35 = V_106 ,
. V_28 = NULL ,
} ;
return F_29 ( V_104 , & V_93 , V_95 , V_54 , V_65 ) ;
}
struct V_14 * F_36 ( struct V_1 * V_104 ,
struct V_94 * V_95 ,
struct V_90 * V_105 ,
struct V_28 * V_110 ,
T_2 V_54 ,
T_2 V_65 )
{
struct V_14 V_93 = {
. V_22 = V_95 -> V_22 ,
. V_17 = {
. V_25 = V_110 -> V_32 . V_25 ,
. V_18 = V_110 -> V_32 . V_18 ,
} ,
. V_107 = V_95 -> V_107 ,
. V_108 = V_110 -> V_32 . V_109 ,
. V_75 = V_95 -> V_75 ,
. V_56 = {
. V_54 = V_54 ,
. V_66 = 1 ,
. V_65 = V_65 ,
} ,
. V_26 = V_105 ,
. V_51 = F_28 ( V_105 ) ,
. V_28 = V_110 ,
. V_1 = V_104 ,
. V_35 = NULL ,
} ;
return F_29 ( V_104 , & V_93 , V_95 , V_54 , V_65 ) ;
}
struct V_14 * F_37 ( struct V_1 * V_104 ,
struct V_94 * V_95 ,
struct V_90 * V_105 , T_2 V_54 ,
T_2 V_65 )
{
struct V_14 V_93 = {
. V_22 = V_95 -> V_22 ,
. V_17 = {
. V_25 = V_95 -> V_25 ,
. V_18 = V_95 -> V_18 ,
} ,
. V_107 = V_95 -> V_107 ,
. V_108 = V_95 -> V_109 ,
. V_75 = V_95 -> V_75 ,
. V_56 = {
. V_54 = V_54 ,
. V_66 = 1 ,
. V_65 = V_65 ,
} ,
. V_26 = V_105 ,
. V_51 = F_28 ( V_105 ) ,
. V_1 = V_104 ,
. V_28 = NULL ,
. V_35 = NULL ,
} ;
return F_29 ( V_104 , & V_93 , V_95 , V_54 , V_65 ) ;
}
T_5
F_31 ( struct V_14 * V_111 , struct V_14 * V_112 )
{
struct V_113 * V_114 ;
T_5 V_97 = 0 ;
F_38 (se, &hist_entry__sort_list, list) {
V_97 = V_114 -> V_115 ( V_111 , V_112 ) ;
if ( V_97 )
break;
}
return V_97 ;
}
T_5
F_39 ( struct V_14 * V_111 , struct V_14 * V_112 )
{
struct V_113 * V_114 ;
T_5 V_97 = 0 ;
F_38 (se, &hist_entry__sort_list, list) {
T_5 (* F_40)( struct V_14 * , struct V_14 * );
F_40 = V_114 -> V_116 ? : V_114 -> V_115 ;
V_97 = F_40 ( V_111 , V_112 ) ;
if ( V_97 )
break;
}
return V_97 ;
}
void F_20 ( struct V_14 * V_52 )
{
free ( V_52 -> V_28 ) ;
free ( V_52 -> V_35 ) ;
free ( V_52 ) ;
}
static bool F_41 ( struct V_1 * V_1 V_117 ,
struct V_118 * V_119 ,
struct V_14 * V_52 )
{
struct V_46 * * V_96 = & V_119 -> V_46 ;
struct V_46 * V_26 = NULL ;
struct V_14 * V_120 ;
T_5 V_97 ;
while ( * V_96 != NULL ) {
V_26 = * V_96 ;
V_120 = F_11 ( V_26 , struct V_14 , V_78 ) ;
V_97 = F_39 ( V_120 , V_52 ) ;
if ( ! V_97 ) {
F_15 ( & V_120 -> V_56 , & V_52 -> V_56 ) ;
if ( V_10 . V_83 ) {
F_42 ( & V_121 ) ;
F_43 ( & V_121 ,
V_120 -> V_87 ,
V_52 -> V_87 ) ;
}
F_20 ( V_52 ) ;
return false ;
}
if ( V_97 < 0 )
V_96 = & ( * V_96 ) -> V_101 ;
else
V_96 = & ( * V_96 ) -> V_102 ;
}
F_32 ( & V_52 -> V_78 , V_26 , V_96 ) ;
F_33 ( & V_52 -> V_78 , V_119 ) ;
return true ;
}
static struct V_118 * F_44 ( struct V_1 * V_1 )
{
struct V_118 * V_119 ;
F_30 ( & V_1 -> V_98 ) ;
V_119 = V_1 -> V_99 ;
if ( ++ V_1 -> V_99 > & V_1 -> V_122 [ 1 ] )
V_1 -> V_99 = & V_1 -> V_122 [ 0 ] ;
F_34 ( & V_1 -> V_98 ) ;
return V_119 ;
}
static void F_45 ( struct V_1 * V_1 , struct V_14 * V_52 )
{
F_46 ( V_1 , V_52 ) ;
F_47 ( V_1 , V_52 ) ;
F_48 ( V_1 , V_52 ) ;
}
static void F_49 ( struct V_1 * V_1 , bool V_74 )
{
struct V_118 * V_119 ;
struct V_46 * V_47 ;
struct V_14 * V_49 ;
if ( ! V_77 && ! V_74 )
return;
V_119 = F_44 ( V_1 ) ;
V_47 = F_10 ( V_119 ) ;
while ( V_47 ) {
V_49 = F_11 ( V_47 , struct V_14 , V_78 ) ;
V_47 = F_12 ( & V_49 -> V_78 ) ;
F_19 ( & V_49 -> V_78 , V_119 ) ;
if ( F_41 ( V_1 , & V_1 -> V_79 , V_49 ) ) {
F_45 ( V_1 , V_49 ) ;
}
}
}
void F_50 ( struct V_1 * V_1 )
{
return F_49 ( V_1 , false ) ;
}
void F_51 ( struct V_1 * V_1 )
{
return F_49 ( V_1 , true ) ;
}
static int F_52 ( T_2 V_123 , T_2 V_124 )
{
if ( V_123 > V_124 )
return 1 ;
if ( V_123 < V_124 )
return - 1 ;
return 0 ;
}
static int F_53 ( struct V_14 * V_125 ,
struct V_14 * V_126 )
{
int V_127 ;
int V_128 , V_129 ;
struct V_130 * V_131 ;
struct V_14 * V_132 ;
T_2 * V_133 , * V_134 ;
V_127 = F_52 ( V_125 -> V_56 . V_54 , V_126 -> V_56 . V_54 ) ;
if ( V_127 || ! V_10 . V_135 )
return V_127 ;
V_131 = F_54 ( V_125 -> V_1 ) ;
V_129 = V_131 -> V_129 ;
if ( V_129 <= 1 )
return V_127 ;
V_133 = F_24 ( sizeof( V_133 ) * V_129 ) ;
V_134 = F_24 ( sizeof( V_134 ) * V_129 ) ;
if ( ! V_133 || ! V_134 )
goto V_100;
F_38 (pair, &a->pairs.head, pairs.node) {
V_131 = F_54 ( V_132 -> V_1 ) ;
V_133 [ F_55 ( V_131 ) ] = V_132 -> V_56 . V_54 ;
}
F_38 (pair, &b->pairs.head, pairs.node) {
V_131 = F_54 ( V_132 -> V_1 ) ;
V_134 [ F_55 ( V_131 ) ] = V_132 -> V_56 . V_54 ;
}
for ( V_128 = 1 ; V_128 < V_129 ; V_128 ++ ) {
V_127 = F_52 ( V_133 [ V_128 ] , V_134 [ V_128 ] ) ;
if ( V_127 )
break;
}
V_100:
free ( V_133 ) ;
free ( V_134 ) ;
return V_127 ;
}
static void F_56 ( struct V_118 * V_48 ,
struct V_14 * V_52 ,
T_2 V_136 )
{
struct V_46 * * V_96 = & V_48 -> V_46 ;
struct V_46 * V_26 = NULL ;
struct V_14 * V_120 ;
if ( V_10 . V_83 )
V_137 . V_138 ( & V_52 -> V_139 , V_52 -> V_87 ,
V_136 , & V_137 ) ;
while ( * V_96 != NULL ) {
V_26 = * V_96 ;
V_120 = F_11 ( V_26 , struct V_14 , V_46 ) ;
if ( F_53 ( V_52 , V_120 ) > 0 )
V_96 = & ( * V_96 ) -> V_101 ;
else
V_96 = & ( * V_96 ) -> V_102 ;
}
F_32 ( & V_52 -> V_46 , V_26 , V_96 ) ;
F_33 ( & V_52 -> V_46 , V_48 ) ;
}
static void F_57 ( struct V_1 * V_1 , bool V_74 )
{
struct V_118 * V_119 ;
struct V_46 * V_47 ;
struct V_14 * V_49 ;
T_2 V_136 ;
V_136 = V_1 -> V_70 . V_71 * ( V_137 . V_140 / 100 ) ;
if ( V_77 || V_74 )
V_119 = & V_1 -> V_79 ;
else
V_119 = V_1 -> V_99 ;
V_47 = F_10 ( V_119 ) ;
V_1 -> V_48 = V_141 ;
V_1 -> V_80 = 0 ;
V_1 -> V_70 . V_71 = 0 ;
F_4 ( V_1 ) ;
while ( V_47 ) {
V_49 = F_11 ( V_47 , struct V_14 , V_78 ) ;
V_47 = F_12 ( & V_49 -> V_78 ) ;
F_56 ( & V_1 -> V_48 , V_49 , V_136 ) ;
F_27 ( V_1 , V_49 ) ;
}
}
void F_58 ( struct V_1 * V_1 )
{
return F_57 ( V_1 , false ) ;
}
void F_59 ( struct V_1 * V_1 )
{
return F_57 ( V_1 , true ) ;
}
static void F_60 ( struct V_1 * V_1 , struct V_14 * V_15 ,
enum V_142 V_143 )
{
V_15 -> V_51 &= ~ ( 1 << V_143 ) ;
if ( V_15 -> V_51 )
return;
++ V_1 -> V_80 ;
if ( V_15 -> V_17 . V_144 )
V_1 -> V_80 += V_15 -> V_145 ;
V_15 -> V_146 = 0 ;
V_1 -> V_70 . V_71 += V_15 -> V_56 . V_54 ;
V_1 -> V_70 . V_66 [ V_147 ] += V_15 -> V_56 . V_66 ;
F_6 ( V_1 , V_15 ) ;
}
static bool F_46 ( struct V_1 * V_1 ,
struct V_14 * V_52 )
{
if ( V_1 -> V_148 != NULL &&
( V_52 -> V_17 . V_25 == NULL || V_52 -> V_17 . V_25 -> V_7 != V_1 -> V_148 ) ) {
V_52 -> V_51 |= ( 1 << V_149 ) ;
return true ;
}
return false ;
}
void F_61 ( struct V_1 * V_1 )
{
struct V_46 * V_150 ;
V_1 -> V_80 = V_1 -> V_70 . V_71 = 0 ;
V_1 -> V_70 . V_66 [ V_147 ] = 0 ;
F_4 ( V_1 ) ;
for ( V_150 = F_10 ( & V_1 -> V_48 ) ; V_150 ; V_150 = F_12 ( V_150 ) ) {
struct V_14 * V_15 = F_11 ( V_150 , struct V_14 , V_46 ) ;
if ( V_10 . V_91 && ! V_15 -> V_26 )
continue;
if ( F_46 ( V_1 , V_15 ) )
continue;
F_60 ( V_1 , V_15 , V_149 ) ;
}
}
static bool F_47 ( struct V_1 * V_1 ,
struct V_14 * V_52 )
{
if ( V_1 -> V_151 != NULL &&
V_52 -> V_22 != V_1 -> V_151 ) {
V_52 -> V_51 |= ( 1 << V_152 ) ;
return true ;
}
return false ;
}
void F_62 ( struct V_1 * V_1 )
{
struct V_46 * V_150 ;
V_1 -> V_80 = V_1 -> V_70 . V_71 = 0 ;
V_1 -> V_70 . V_66 [ V_147 ] = 0 ;
F_4 ( V_1 ) ;
for ( V_150 = F_10 ( & V_1 -> V_48 ) ; V_150 ; V_150 = F_12 ( V_150 ) ) {
struct V_14 * V_15 = F_11 ( V_150 , struct V_14 , V_46 ) ;
if ( F_47 ( V_1 , V_15 ) )
continue;
F_60 ( V_1 , V_15 , V_152 ) ;
}
}
static bool F_48 ( struct V_1 * V_1 ,
struct V_14 * V_52 )
{
if ( V_1 -> V_153 != NULL &&
( ! V_52 -> V_17 . V_18 || strstr ( V_52 -> V_17 . V_18 -> V_154 ,
V_1 -> V_153 ) == NULL ) ) {
V_52 -> V_51 |= ( 1 << V_155 ) ;
return true ;
}
return false ;
}
void F_63 ( struct V_1 * V_1 )
{
struct V_46 * V_150 ;
V_1 -> V_80 = V_1 -> V_70 . V_71 = 0 ;
V_1 -> V_70 . V_66 [ V_147 ] = 0 ;
F_4 ( V_1 ) ;
for ( V_150 = F_10 ( & V_1 -> V_48 ) ; V_150 ; V_150 = F_12 ( V_150 ) ) {
struct V_14 * V_15 = F_11 ( V_150 , struct V_14 , V_46 ) ;
if ( F_48 ( V_1 , V_15 ) )
continue;
F_60 ( V_1 , V_15 , V_155 ) ;
}
}
int F_64 ( struct V_14 * V_52 , int V_156 , T_2 V_108 )
{
return F_65 ( V_52 -> V_17 . V_18 , V_52 -> V_17 . V_25 , V_156 , V_108 ) ;
}
int F_66 ( struct V_14 * V_52 , T_3 V_157 )
{
return F_67 ( V_52 -> V_17 . V_18 , V_52 -> V_17 . V_25 , V_157 ) ;
}
void F_68 ( struct V_158 * V_70 , T_6 type )
{
++ V_70 -> V_66 [ 0 ] ;
++ V_70 -> V_66 [ type ] ;
}
void F_69 ( struct V_1 * V_1 , T_6 type )
{
F_68 ( & V_1 -> V_70 , type ) ;
}
static struct V_14 * F_70 ( struct V_1 * V_1 ,
struct V_14 * V_132 )
{
struct V_118 * V_119 ;
struct V_46 * * V_96 ;
struct V_46 * V_26 = NULL ;
struct V_14 * V_52 ;
int V_97 ;
if ( V_77 )
V_119 = & V_1 -> V_79 ;
else
V_119 = V_1 -> V_99 ;
V_96 = & V_119 -> V_46 ;
while ( * V_96 != NULL ) {
V_26 = * V_96 ;
V_52 = F_11 ( V_26 , struct V_14 , V_78 ) ;
V_97 = F_39 ( V_52 , V_132 ) ;
if ( ! V_97 )
goto V_100;
if ( V_97 < 0 )
V_96 = & ( * V_96 ) -> V_101 ;
else
V_96 = & ( * V_96 ) -> V_102 ;
}
V_52 = F_23 ( V_132 ) ;
if ( V_52 ) {
memset ( & V_52 -> V_56 , 0 , sizeof( V_52 -> V_56 ) ) ;
V_52 -> V_1 = V_1 ;
F_32 ( & V_52 -> V_78 , V_26 , V_96 ) ;
F_33 ( & V_52 -> V_78 , V_119 ) ;
F_27 ( V_1 , V_52 ) ;
}
V_100:
return V_52 ;
}
static struct V_14 * F_71 ( struct V_1 * V_1 ,
struct V_14 * V_52 )
{
struct V_46 * V_49 ;
if ( V_77 )
V_49 = V_1 -> V_79 . V_46 ;
else
V_49 = V_1 -> V_99 -> V_46 ;
while ( V_49 ) {
struct V_14 * V_120 = F_11 ( V_49 , struct V_14 , V_78 ) ;
T_5 V_97 = F_39 ( V_120 , V_52 ) ;
if ( V_97 < 0 )
V_49 = V_49 -> V_101 ;
else if ( V_97 > 0 )
V_49 = V_49 -> V_102 ;
else
return V_120 ;
}
return NULL ;
}
void F_72 ( struct V_1 * V_159 , struct V_1 * V_160 )
{
struct V_118 * V_119 ;
struct V_46 * V_150 ;
struct V_14 * V_161 , * V_132 ;
if ( V_77 )
V_119 = & V_159 -> V_79 ;
else
V_119 = V_159 -> V_99 ;
for ( V_150 = F_10 ( V_119 ) ; V_150 ; V_150 = F_12 ( V_150 ) ) {
V_161 = F_11 ( V_150 , struct V_14 , V_78 ) ;
V_132 = F_71 ( V_160 , V_161 ) ;
if ( V_132 )
F_73 ( V_132 , V_161 ) ;
}
}
int F_74 ( struct V_1 * V_159 , struct V_1 * V_160 )
{
struct V_118 * V_119 ;
struct V_46 * V_150 ;
struct V_14 * V_161 , * V_132 ;
if ( V_77 )
V_119 = & V_160 -> V_79 ;
else
V_119 = V_160 -> V_99 ;
for ( V_150 = F_10 ( V_119 ) ; V_150 ; V_150 = F_12 ( V_150 ) ) {
V_161 = F_11 ( V_150 , struct V_14 , V_78 ) ;
if ( ! F_75 ( V_161 ) ) {
V_132 = F_70 ( V_159 , V_161 ) ;
if ( V_132 == NULL )
return - 1 ;
F_73 ( V_161 , V_132 ) ;
}
}
return 0 ;
}
