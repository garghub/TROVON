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
T_1 V_5 ;
if ( V_15 -> V_16 . V_17 )
F_3 ( V_1 , V_18 , V_15 -> V_16 . V_17 -> V_19 + 4 ) ;
else
F_5 ( V_1 , V_20 ) ;
V_5 = F_7 ( V_15 -> V_21 ) ;
if ( F_3 ( V_1 , V_22 , V_5 ) )
F_2 ( V_1 , V_23 , V_5 + 6 ) ;
if ( V_15 -> V_16 . V_24 ) {
V_5 = F_8 ( V_15 -> V_16 . V_24 -> V_7 ) ;
F_3 ( V_1 , V_20 , V_5 ) ;
}
if ( V_15 -> V_25 )
F_3 ( V_1 , V_26 , V_15 -> V_25 -> V_19 ) ;
if ( V_15 -> V_27 ) {
int V_28 ;
if ( V_15 -> V_27 -> V_29 . V_17 ) {
V_28 = ( int ) V_15 -> V_27 -> V_29 . V_17 -> V_19 + 4 ;
F_3 ( V_1 , V_30 , V_28 ) ;
V_28 = F_8 ( V_15 -> V_27 -> V_29 . V_24 -> V_7 ) ;
F_3 ( V_1 , V_31 , V_28 ) ;
} else {
V_28 = V_8 + 4 + 2 ;
F_3 ( V_1 , V_30 , V_28 ) ;
F_5 ( V_1 , V_31 ) ;
}
if ( V_15 -> V_27 -> V_32 . V_17 ) {
V_28 = ( int ) V_15 -> V_27 -> V_32 . V_17 -> V_19 + 4 ;
F_3 ( V_1 , V_33 , V_28 ) ;
V_28 = F_8 ( V_15 -> V_27 -> V_32 . V_24 -> V_7 ) ;
F_3 ( V_1 , V_34 , V_28 ) ;
} else {
V_28 = V_8 + 4 + 2 ;
F_3 ( V_1 , V_33 , V_28 ) ;
F_5 ( V_1 , V_34 ) ;
}
}
}
void F_9 ( struct V_1 * V_1 , int V_35 )
{
struct V_36 * V_37 = F_10 ( & V_1 -> V_38 ) ;
struct V_14 * V_39 ;
int V_40 = 0 ;
F_4 ( V_1 ) ;
while ( V_37 && V_40 ++ < V_35 ) {
V_39 = F_11 ( V_37 , struct V_14 , V_36 ) ;
if ( ! V_39 -> V_41 )
F_6 ( V_1 , V_39 ) ;
V_37 = F_12 ( & V_39 -> V_36 ) ;
}
}
static void F_13 ( struct V_14 * V_42 ,
unsigned int V_43 , T_2 V_44 )
{
switch ( V_43 ) {
case V_45 :
V_42 -> V_46 . V_47 += V_44 ;
break;
case V_48 :
V_42 -> V_46 . V_49 += V_44 ;
break;
case V_50 :
V_42 -> V_46 . V_51 += V_44 ;
break;
case V_52 :
V_42 -> V_46 . V_53 += V_44 ;
break;
default:
break;
}
}
static void F_14 ( struct V_54 * V_54 , T_2 V_44 )
{
V_54 -> V_44 += V_44 ;
V_54 -> V_55 += 1 ;
}
static void F_15 ( struct V_54 * V_56 , struct V_54 * V_57 )
{
V_56 -> V_44 += V_57 -> V_44 ;
V_56 -> V_47 += V_57 -> V_47 ;
V_56 -> V_49 += V_57 -> V_49 ;
V_56 -> V_51 += V_57 -> V_51 ;
V_56 -> V_53 += V_57 -> V_53 ;
V_56 -> V_55 += V_57 -> V_55 ;
}
static void F_16 ( struct V_14 * V_42 )
{
V_42 -> V_46 . V_44 = ( V_42 -> V_46 . V_44 * 7 ) / 8 ;
V_42 -> V_46 . V_55 = ( V_42 -> V_46 . V_55 * 7 ) / 8 ;
}
static bool F_17 ( struct V_1 * V_1 , struct V_14 * V_42 )
{
T_2 V_58 = V_42 -> V_46 . V_44 ;
if ( V_58 == 0 )
return true ;
F_16 ( V_42 ) ;
if ( ! V_42 -> V_41 )
V_1 -> V_59 . V_60 -= V_58 - V_42 -> V_46 . V_44 ;
return V_42 -> V_46 . V_44 == 0 ;
}
static void F_18 ( struct V_1 * V_1 , bool V_61 ,
bool V_62 , bool V_63 )
{
struct V_36 * V_37 = F_10 ( & V_1 -> V_38 ) ;
struct V_14 * V_39 ;
while ( V_37 ) {
V_39 = F_11 ( V_37 , struct V_14 , V_36 ) ;
V_37 = F_12 ( & V_39 -> V_36 ) ;
if ( ( ( V_61 && V_39 -> V_64 == '.' ) ||
( V_62 && V_39 -> V_64 != '.' ) ||
F_17 ( V_1 , V_39 ) ) &&
! V_39 -> V_65 ) {
F_19 ( & V_39 -> V_36 , & V_1 -> V_38 ) ;
if ( V_66 || V_63 )
F_19 ( & V_39 -> V_67 , & V_1 -> V_68 ) ;
F_20 ( V_39 ) ;
-- V_1 -> V_69 ;
}
}
}
void F_21 ( struct V_1 * V_1 , bool V_61 , bool V_62 )
{
return F_18 ( V_1 , V_61 , V_62 , false ) ;
}
void F_22 ( struct V_1 * V_1 ,
bool V_61 , bool V_62 )
{
return F_18 ( V_1 , V_61 , V_62 , true ) ;
}
static struct V_14 * F_23 ( struct V_14 * V_70 )
{
T_3 V_71 = V_10 . V_72 ? sizeof( struct V_73 ) : 0 ;
struct V_14 * V_42 = malloc ( sizeof( * V_42 ) + V_71 ) ;
if ( V_42 != NULL ) {
* V_42 = * V_70 ;
if ( V_42 -> V_16 . V_24 )
V_42 -> V_16 . V_24 -> V_74 = true ;
if ( V_42 -> V_27 ) {
if ( V_42 -> V_27 -> V_29 . V_24 )
V_42 -> V_27 -> V_29 . V_24 -> V_74 = true ;
if ( V_42 -> V_27 -> V_32 . V_24 )
V_42 -> V_27 -> V_32 . V_24 -> V_74 = true ;
}
if ( V_10 . V_72 )
F_24 ( V_42 -> V_75 ) ;
F_25 ( & V_42 -> V_76 . V_77 ) ;
}
return V_42 ;
}
void F_26 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
if ( ! V_15 -> V_41 ) {
F_6 ( V_1 , V_15 ) ;
++ V_1 -> V_69 ;
V_1 -> V_59 . V_60 += V_15 -> V_46 . V_44 ;
}
}
static T_4 F_27 ( const struct V_78 * V_25 )
{
if ( V_10 . V_79 && V_25 == NULL )
return 1 << V_80 ;
return 0 ;
}
static struct V_14 * F_28 ( struct V_1 * V_1 ,
struct V_14 * V_81 ,
struct V_82 * V_83 ,
T_2 V_44 )
{
struct V_36 * * V_84 ;
struct V_36 * V_25 = NULL ;
struct V_14 * V_42 ;
int V_85 ;
F_29 ( & V_1 -> V_86 ) ;
V_84 = & V_1 -> V_87 -> V_36 ;
while ( * V_84 != NULL ) {
V_25 = * V_84 ;
V_42 = F_11 ( V_25 , struct V_14 , V_67 ) ;
V_85 = F_30 ( V_42 , V_81 ) ;
if ( ! V_85 ) {
F_14 ( & V_42 -> V_46 , V_44 ) ;
if ( V_42 -> V_16 . V_24 != V_81 -> V_16 . V_24 ) {
V_42 -> V_16 . V_24 = V_81 -> V_16 . V_24 ;
if ( V_42 -> V_16 . V_24 )
V_42 -> V_16 . V_24 -> V_74 = true ;
}
goto V_88;
}
if ( V_85 < 0 )
V_84 = & ( * V_84 ) -> V_89 ;
else
V_84 = & ( * V_84 ) -> V_90 ;
}
V_42 = F_23 ( V_81 ) ;
if ( ! V_42 )
goto V_91;
F_31 ( & V_42 -> V_67 , V_25 , V_84 ) ;
F_32 ( & V_42 -> V_67 , V_1 -> V_87 ) ;
V_88:
F_13 ( V_42 , V_83 -> V_43 , V_44 ) ;
V_91:
F_33 ( & V_1 -> V_86 ) ;
return V_42 ;
}
struct V_14 * F_34 ( struct V_1 * V_92 ,
struct V_82 * V_83 ,
struct V_78 * V_93 ,
struct V_27 * V_94 ,
T_2 V_44 )
{
struct V_14 V_81 = {
. V_21 = V_83 -> V_21 ,
. V_16 = {
. V_24 = V_94 -> V_32 . V_24 ,
. V_17 = V_94 -> V_32 . V_17 ,
} ,
. V_95 = V_83 -> V_95 ,
. V_96 = V_94 -> V_32 . V_97 ,
. V_64 = V_83 -> V_64 ,
. V_46 = {
. V_44 = V_44 ,
. V_55 = 1 ,
} ,
. V_25 = V_93 ,
. V_41 = F_27 ( V_93 ) ,
. V_27 = V_94 ,
. V_1 = V_92 ,
} ;
return F_28 ( V_92 , & V_81 , V_83 , V_44 ) ;
}
struct V_14 * F_35 ( struct V_1 * V_92 ,
struct V_82 * V_83 ,
struct V_78 * V_93 , T_2 V_44 )
{
struct V_14 V_81 = {
. V_21 = V_83 -> V_21 ,
. V_16 = {
. V_24 = V_83 -> V_24 ,
. V_17 = V_83 -> V_17 ,
} ,
. V_95 = V_83 -> V_95 ,
. V_96 = V_83 -> V_97 ,
. V_64 = V_83 -> V_64 ,
. V_46 = {
. V_44 = V_44 ,
. V_55 = 1 ,
} ,
. V_25 = V_93 ,
. V_41 = F_27 ( V_93 ) ,
. V_1 = V_92 ,
} ;
return F_28 ( V_92 , & V_81 , V_83 , V_44 ) ;
}
T_5
F_30 ( struct V_14 * V_98 , struct V_14 * V_99 )
{
struct V_100 * V_101 ;
T_5 V_85 = 0 ;
F_36 (se, &hist_entry__sort_list, list) {
V_85 = V_101 -> V_102 ( V_98 , V_99 ) ;
if ( V_85 )
break;
}
return V_85 ;
}
T_5
F_37 ( struct V_14 * V_98 , struct V_14 * V_99 )
{
struct V_100 * V_101 ;
T_5 V_85 = 0 ;
F_36 (se, &hist_entry__sort_list, list) {
T_5 (* F_38)( struct V_14 * , struct V_14 * );
F_38 = V_101 -> V_103 ? : V_101 -> V_102 ;
V_85 = F_38 ( V_98 , V_99 ) ;
if ( V_85 )
break;
}
return V_85 ;
}
void F_20 ( struct V_14 * V_42 )
{
free ( V_42 -> V_27 ) ;
free ( V_42 ) ;
}
static bool F_39 ( struct V_1 * V_1 V_104 ,
struct V_105 * V_106 ,
struct V_14 * V_42 )
{
struct V_36 * * V_84 = & V_106 -> V_36 ;
struct V_36 * V_25 = NULL ;
struct V_14 * V_107 ;
T_5 V_85 ;
while ( * V_84 != NULL ) {
V_25 = * V_84 ;
V_107 = F_11 ( V_25 , struct V_14 , V_67 ) ;
V_85 = F_37 ( V_107 , V_42 ) ;
if ( ! V_85 ) {
F_15 ( & V_107 -> V_46 , & V_42 -> V_46 ) ;
if ( V_10 . V_72 ) {
F_40 ( & V_108 ) ;
F_41 ( & V_108 ,
V_107 -> V_75 ,
V_42 -> V_75 ) ;
}
F_20 ( V_42 ) ;
return false ;
}
if ( V_85 < 0 )
V_84 = & ( * V_84 ) -> V_89 ;
else
V_84 = & ( * V_84 ) -> V_90 ;
}
F_31 ( & V_42 -> V_67 , V_25 , V_84 ) ;
F_32 ( & V_42 -> V_67 , V_106 ) ;
return true ;
}
static struct V_105 * F_42 ( struct V_1 * V_1 )
{
struct V_105 * V_106 ;
F_29 ( & V_1 -> V_86 ) ;
V_106 = V_1 -> V_87 ;
if ( ++ V_1 -> V_87 > & V_1 -> V_109 [ 1 ] )
V_1 -> V_87 = & V_1 -> V_109 [ 0 ] ;
F_33 ( & V_1 -> V_86 ) ;
return V_106 ;
}
static void F_43 ( struct V_1 * V_1 , struct V_14 * V_42 )
{
F_44 ( V_1 , V_42 ) ;
F_45 ( V_1 , V_42 ) ;
F_46 ( V_1 , V_42 ) ;
}
static void F_47 ( struct V_1 * V_1 , bool V_63 )
{
struct V_105 * V_106 ;
struct V_36 * V_37 ;
struct V_14 * V_39 ;
if ( ! V_66 && ! V_63 )
return;
V_106 = F_42 ( V_1 ) ;
V_37 = F_10 ( V_106 ) ;
while ( V_37 ) {
V_39 = F_11 ( V_37 , struct V_14 , V_67 ) ;
V_37 = F_12 ( & V_39 -> V_67 ) ;
F_19 ( & V_39 -> V_67 , V_106 ) ;
if ( F_39 ( V_1 , & V_1 -> V_68 , V_39 ) ) {
F_43 ( V_1 , V_39 ) ;
}
}
}
void F_48 ( struct V_1 * V_1 )
{
return F_47 ( V_1 , false ) ;
}
void F_49 ( struct V_1 * V_1 )
{
return F_47 ( V_1 , true ) ;
}
static int F_50 ( T_2 V_110 , T_2 V_111 )
{
if ( V_110 > V_111 )
return 1 ;
if ( V_110 < V_111 )
return - 1 ;
return 0 ;
}
static int F_51 ( struct V_14 * V_112 ,
struct V_14 * V_113 )
{
int V_114 ;
int V_115 , V_116 ;
struct V_117 * V_118 ;
struct V_14 * V_119 ;
T_2 * V_120 , * V_121 ;
V_114 = F_50 ( V_112 -> V_46 . V_44 , V_113 -> V_46 . V_44 ) ;
if ( V_114 || ! V_10 . V_122 )
return V_114 ;
V_118 = F_52 ( V_112 -> V_1 ) ;
V_116 = V_118 -> V_116 ;
if ( V_116 <= 1 )
return V_114 ;
V_120 = F_53 ( sizeof( V_120 ) * V_116 ) ;
V_121 = F_53 ( sizeof( V_121 ) * V_116 ) ;
if ( ! V_120 || ! V_121 )
goto V_88;
F_36 (pair, &a->pairs.head, pairs.node) {
V_118 = F_52 ( V_119 -> V_1 ) ;
V_120 [ F_54 ( V_118 ) ] = V_119 -> V_46 . V_44 ;
}
F_36 (pair, &b->pairs.head, pairs.node) {
V_118 = F_52 ( V_119 -> V_1 ) ;
V_121 [ F_54 ( V_118 ) ] = V_119 -> V_46 . V_44 ;
}
for ( V_115 = 1 ; V_115 < V_116 ; V_115 ++ ) {
V_114 = F_50 ( V_120 [ V_115 ] , V_121 [ V_115 ] ) ;
if ( V_114 )
break;
}
V_88:
free ( V_120 ) ;
free ( V_121 ) ;
return V_114 ;
}
static void F_55 ( struct V_105 * V_38 ,
struct V_14 * V_42 ,
T_2 V_123 )
{
struct V_36 * * V_84 = & V_38 -> V_36 ;
struct V_36 * V_25 = NULL ;
struct V_14 * V_107 ;
if ( V_10 . V_72 )
V_124 . V_125 ( & V_42 -> V_126 , V_42 -> V_75 ,
V_123 , & V_124 ) ;
while ( * V_84 != NULL ) {
V_25 = * V_84 ;
V_107 = F_11 ( V_25 , struct V_14 , V_36 ) ;
if ( F_51 ( V_42 , V_107 ) > 0 )
V_84 = & ( * V_84 ) -> V_89 ;
else
V_84 = & ( * V_84 ) -> V_90 ;
}
F_31 ( & V_42 -> V_36 , V_25 , V_84 ) ;
F_32 ( & V_42 -> V_36 , V_38 ) ;
}
static void F_56 ( struct V_1 * V_1 , bool V_63 )
{
struct V_105 * V_106 ;
struct V_36 * V_37 ;
struct V_14 * V_39 ;
T_2 V_123 ;
V_123 = V_1 -> V_59 . V_60 * ( V_124 . V_127 / 100 ) ;
if ( V_66 || V_63 )
V_106 = & V_1 -> V_68 ;
else
V_106 = V_1 -> V_87 ;
V_37 = F_10 ( V_106 ) ;
V_1 -> V_38 = V_128 ;
V_1 -> V_69 = 0 ;
V_1 -> V_59 . V_60 = 0 ;
F_4 ( V_1 ) ;
while ( V_37 ) {
V_39 = F_11 ( V_37 , struct V_14 , V_67 ) ;
V_37 = F_12 ( & V_39 -> V_67 ) ;
F_55 ( & V_1 -> V_38 , V_39 , V_123 ) ;
F_26 ( V_1 , V_39 ) ;
}
}
void F_57 ( struct V_1 * V_1 )
{
return F_56 ( V_1 , false ) ;
}
void F_58 ( struct V_1 * V_1 )
{
return F_56 ( V_1 , true ) ;
}
static void F_59 ( struct V_1 * V_1 , struct V_14 * V_15 ,
enum V_129 V_130 )
{
V_15 -> V_41 &= ~ ( 1 << V_130 ) ;
if ( V_15 -> V_41 )
return;
++ V_1 -> V_69 ;
if ( V_15 -> V_16 . V_131 )
V_1 -> V_69 += V_15 -> V_132 ;
V_15 -> V_133 = 0 ;
V_1 -> V_59 . V_60 += V_15 -> V_46 . V_44 ;
V_1 -> V_59 . V_55 [ V_134 ] += V_15 -> V_46 . V_55 ;
F_6 ( V_1 , V_15 ) ;
}
static bool F_44 ( struct V_1 * V_1 ,
struct V_14 * V_42 )
{
if ( V_1 -> V_135 != NULL &&
( V_42 -> V_16 . V_24 == NULL || V_42 -> V_16 . V_24 -> V_7 != V_1 -> V_135 ) ) {
V_42 -> V_41 |= ( 1 << V_136 ) ;
return true ;
}
return false ;
}
void F_60 ( struct V_1 * V_1 )
{
struct V_36 * V_137 ;
V_1 -> V_69 = V_1 -> V_59 . V_60 = 0 ;
V_1 -> V_59 . V_55 [ V_134 ] = 0 ;
F_4 ( V_1 ) ;
for ( V_137 = F_10 ( & V_1 -> V_38 ) ; V_137 ; V_137 = F_12 ( V_137 ) ) {
struct V_14 * V_15 = F_11 ( V_137 , struct V_14 , V_36 ) ;
if ( V_10 . V_79 && ! V_15 -> V_25 )
continue;
if ( F_44 ( V_1 , V_15 ) )
continue;
F_59 ( V_1 , V_15 , V_136 ) ;
}
}
static bool F_45 ( struct V_1 * V_1 ,
struct V_14 * V_42 )
{
if ( V_1 -> V_138 != NULL &&
V_42 -> V_21 != V_1 -> V_138 ) {
V_42 -> V_41 |= ( 1 << V_139 ) ;
return true ;
}
return false ;
}
void F_61 ( struct V_1 * V_1 )
{
struct V_36 * V_137 ;
V_1 -> V_69 = V_1 -> V_59 . V_60 = 0 ;
V_1 -> V_59 . V_55 [ V_134 ] = 0 ;
F_4 ( V_1 ) ;
for ( V_137 = F_10 ( & V_1 -> V_38 ) ; V_137 ; V_137 = F_12 ( V_137 ) ) {
struct V_14 * V_15 = F_11 ( V_137 , struct V_14 , V_36 ) ;
if ( F_45 ( V_1 , V_15 ) )
continue;
F_59 ( V_1 , V_15 , V_139 ) ;
}
}
static bool F_46 ( struct V_1 * V_1 ,
struct V_14 * V_42 )
{
if ( V_1 -> V_140 != NULL &&
( ! V_42 -> V_16 . V_17 || strstr ( V_42 -> V_16 . V_17 -> V_141 ,
V_1 -> V_140 ) == NULL ) ) {
V_42 -> V_41 |= ( 1 << V_142 ) ;
return true ;
}
return false ;
}
void F_62 ( struct V_1 * V_1 )
{
struct V_36 * V_137 ;
V_1 -> V_69 = V_1 -> V_59 . V_60 = 0 ;
V_1 -> V_59 . V_55 [ V_134 ] = 0 ;
F_4 ( V_1 ) ;
for ( V_137 = F_10 ( & V_1 -> V_38 ) ; V_137 ; V_137 = F_12 ( V_137 ) ) {
struct V_14 * V_15 = F_11 ( V_137 , struct V_14 , V_36 ) ;
if ( F_46 ( V_1 , V_15 ) )
continue;
F_59 ( V_1 , V_15 , V_142 ) ;
}
}
int F_63 ( struct V_14 * V_42 , int V_143 , T_2 V_96 )
{
return F_64 ( V_42 -> V_16 . V_17 , V_42 -> V_16 . V_24 , V_143 , V_96 ) ;
}
int F_65 ( struct V_14 * V_42 , T_3 V_144 )
{
return F_66 ( V_42 -> V_16 . V_17 , V_42 -> V_16 . V_24 , V_144 ) ;
}
void F_67 ( struct V_145 * V_59 , T_6 type )
{
++ V_59 -> V_55 [ 0 ] ;
++ V_59 -> V_55 [ type ] ;
}
void F_68 ( struct V_1 * V_1 , T_6 type )
{
F_67 ( & V_1 -> V_59 , type ) ;
}
static struct V_14 * F_69 ( struct V_1 * V_1 ,
struct V_14 * V_119 )
{
struct V_105 * V_106 ;
struct V_36 * * V_84 ;
struct V_36 * V_25 = NULL ;
struct V_14 * V_42 ;
int V_85 ;
if ( V_66 )
V_106 = & V_1 -> V_68 ;
else
V_106 = V_1 -> V_87 ;
V_84 = & V_106 -> V_36 ;
while ( * V_84 != NULL ) {
V_25 = * V_84 ;
V_42 = F_11 ( V_25 , struct V_14 , V_67 ) ;
V_85 = F_37 ( V_42 , V_119 ) ;
if ( ! V_85 )
goto V_88;
if ( V_85 < 0 )
V_84 = & ( * V_84 ) -> V_89 ;
else
V_84 = & ( * V_84 ) -> V_90 ;
}
V_42 = F_23 ( V_119 ) ;
if ( V_42 ) {
memset ( & V_42 -> V_46 , 0 , sizeof( V_42 -> V_46 ) ) ;
V_42 -> V_1 = V_1 ;
F_31 ( & V_42 -> V_67 , V_25 , V_84 ) ;
F_32 ( & V_42 -> V_67 , V_106 ) ;
F_26 ( V_1 , V_42 ) ;
}
V_88:
return V_42 ;
}
static struct V_14 * F_70 ( struct V_1 * V_1 ,
struct V_14 * V_42 )
{
struct V_36 * V_39 ;
if ( V_66 )
V_39 = V_1 -> V_68 . V_36 ;
else
V_39 = V_1 -> V_87 -> V_36 ;
while ( V_39 ) {
struct V_14 * V_107 = F_11 ( V_39 , struct V_14 , V_67 ) ;
T_5 V_85 = F_37 ( V_107 , V_42 ) ;
if ( V_85 < 0 )
V_39 = V_39 -> V_89 ;
else if ( V_85 > 0 )
V_39 = V_39 -> V_90 ;
else
return V_107 ;
}
return NULL ;
}
void F_71 ( struct V_1 * V_146 , struct V_1 * V_147 )
{
struct V_105 * V_106 ;
struct V_36 * V_137 ;
struct V_14 * V_148 , * V_119 ;
if ( V_66 )
V_106 = & V_146 -> V_68 ;
else
V_106 = V_146 -> V_87 ;
for ( V_137 = F_10 ( V_106 ) ; V_137 ; V_137 = F_12 ( V_137 ) ) {
V_148 = F_11 ( V_137 , struct V_14 , V_67 ) ;
V_119 = F_70 ( V_147 , V_148 ) ;
if ( V_119 )
F_72 ( V_119 , V_148 ) ;
}
}
int F_73 ( struct V_1 * V_146 , struct V_1 * V_147 )
{
struct V_105 * V_106 ;
struct V_36 * V_137 ;
struct V_14 * V_148 , * V_119 ;
if ( V_66 )
V_106 = & V_147 -> V_68 ;
else
V_106 = V_147 -> V_87 ;
for ( V_137 = F_10 ( V_106 ) ; V_137 ; V_137 = F_12 ( V_137 ) ) {
V_148 = F_11 ( V_137 , struct V_14 , V_67 ) ;
if ( ! F_74 ( V_148 ) ) {
V_119 = F_69 ( V_146 , V_148 ) ;
if ( V_119 == NULL )
return - 1 ;
F_72 ( V_148 , V_119 ) ;
}
}
return 0 ;
}
