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
static void F_4 ( struct V_1 * V_1 )
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
static void F_6 ( struct V_1 * V_1 , struct V_14 * V_15 )
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
if ( V_15 -> V_25 ) {
int V_26 ;
if ( V_15 -> V_25 -> V_27 . V_17 ) {
V_26 = ( int ) V_15 -> V_25 -> V_27 . V_17 -> V_19 + 4 ;
F_3 ( V_1 , V_28 , V_26 ) ;
V_26 = F_8 ( V_15 -> V_25 -> V_27 . V_24 -> V_7 ) ;
F_3 ( V_1 , V_29 , V_26 ) ;
} else {
V_26 = V_8 + 4 + 2 ;
F_3 ( V_1 , V_28 , V_26 ) ;
F_5 ( V_1 , V_29 ) ;
}
if ( V_15 -> V_25 -> V_30 . V_17 ) {
V_26 = ( int ) V_15 -> V_25 -> V_30 . V_17 -> V_19 + 4 ;
F_3 ( V_1 , V_31 , V_26 ) ;
V_26 = F_8 ( V_15 -> V_25 -> V_30 . V_24 -> V_7 ) ;
F_3 ( V_1 , V_32 , V_26 ) ;
} else {
V_26 = V_8 + 4 + 2 ;
F_3 ( V_1 , V_31 , V_26 ) ;
F_5 ( V_1 , V_32 ) ;
}
}
}
static void F_9 ( struct V_14 * V_33 ,
unsigned int V_34 , T_2 V_35 )
{
switch ( V_34 ) {
case V_36 :
V_33 -> V_37 += V_35 ;
break;
case V_38 :
V_33 -> V_39 += V_35 ;
break;
case V_40 :
V_33 -> V_41 += V_35 ;
break;
case V_42 :
V_33 -> V_43 += V_35 ;
break;
default:
break;
}
}
static void F_10 ( struct V_14 * V_33 )
{
V_33 -> V_35 = ( V_33 -> V_35 * 7 ) / 8 ;
V_33 -> V_44 = ( V_33 -> V_44 * 7 ) / 8 ;
}
static bool F_11 ( struct V_1 * V_1 , struct V_14 * V_33 )
{
T_2 V_45 = V_33 -> V_35 ;
if ( V_45 == 0 )
return true ;
F_10 ( V_33 ) ;
if ( ! V_33 -> V_46 )
V_1 -> V_47 . V_48 -= V_45 - V_33 -> V_35 ;
return V_33 -> V_35 == 0 ;
}
static void F_12 ( struct V_1 * V_1 , bool V_49 ,
bool V_50 , bool V_51 )
{
struct V_52 * V_53 = F_13 ( & V_1 -> V_54 ) ;
struct V_14 * V_55 ;
while ( V_53 ) {
V_55 = F_14 ( V_53 , struct V_14 , V_52 ) ;
V_53 = F_15 ( & V_55 -> V_52 ) ;
if ( ( ( V_49 && V_55 -> V_56 == '.' ) ||
( V_50 && V_55 -> V_56 != '.' ) ||
F_11 ( V_1 , V_55 ) ) &&
! V_55 -> V_57 ) {
F_16 ( & V_55 -> V_52 , & V_1 -> V_54 ) ;
if ( V_58 || V_51 )
F_16 ( & V_55 -> V_59 , & V_1 -> V_60 ) ;
F_17 ( V_55 ) ;
-- V_1 -> V_61 ;
}
}
}
void F_18 ( struct V_1 * V_1 , bool V_49 , bool V_50 )
{
return F_12 ( V_1 , V_49 , V_50 , false ) ;
}
void F_19 ( struct V_1 * V_1 ,
bool V_49 , bool V_50 )
{
return F_12 ( V_1 , V_49 , V_50 , true ) ;
}
static struct V_14 * F_20 ( struct V_14 * V_62 )
{
T_3 V_63 = V_10 . V_64 ? sizeof( struct V_65 ) : 0 ;
struct V_14 * V_33 = malloc ( sizeof( * V_33 ) + V_63 ) ;
if ( V_33 != NULL ) {
* V_33 = * V_62 ;
V_33 -> V_44 = 1 ;
if ( V_33 -> V_16 . V_24 )
V_33 -> V_16 . V_24 -> V_66 = true ;
if ( V_10 . V_64 )
F_21 ( V_33 -> V_67 ) ;
}
return V_33 ;
}
static void F_22 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
if ( ! V_15 -> V_46 ) {
F_6 ( V_1 , V_15 ) ;
++ V_1 -> V_61 ;
V_1 -> V_47 . V_48 += V_15 -> V_35 ;
}
}
static T_4 F_23 ( const struct V_68 * V_69 )
{
if ( V_10 . V_70 && V_69 == NULL )
return 1 << V_71 ;
return 0 ;
}
static struct V_14 * F_24 ( struct V_1 * V_1 ,
struct V_14 * V_72 ,
struct V_73 * V_74 ,
T_2 V_35 )
{
struct V_52 * * V_75 ;
struct V_52 * V_69 = NULL ;
struct V_14 * V_33 ;
int V_76 ;
F_25 ( & V_1 -> V_77 ) ;
V_75 = & V_1 -> V_78 -> V_52 ;
while ( * V_75 != NULL ) {
V_69 = * V_75 ;
V_33 = F_14 ( V_69 , struct V_14 , V_59 ) ;
V_76 = F_26 ( V_72 , V_33 ) ;
if ( ! V_76 ) {
V_33 -> V_35 += V_35 ;
++ V_33 -> V_44 ;
if ( V_33 -> V_16 . V_24 != V_72 -> V_16 . V_24 ) {
V_33 -> V_16 . V_24 = V_72 -> V_16 . V_24 ;
if ( V_33 -> V_16 . V_24 )
V_33 -> V_16 . V_24 -> V_66 = true ;
}
goto V_79;
}
if ( V_76 < 0 )
V_75 = & ( * V_75 ) -> V_80 ;
else
V_75 = & ( * V_75 ) -> V_81 ;
}
V_33 = F_20 ( V_72 ) ;
if ( ! V_33 )
goto V_82;
F_27 ( & V_33 -> V_59 , V_69 , V_75 ) ;
F_28 ( & V_33 -> V_59 , V_1 -> V_78 ) ;
V_79:
F_9 ( V_33 , V_74 -> V_34 , V_35 ) ;
V_82:
F_29 ( & V_1 -> V_77 ) ;
return V_33 ;
}
struct V_14 * F_30 ( struct V_1 * V_83 ,
struct V_73 * V_74 ,
struct V_68 * V_84 ,
struct V_25 * V_85 ,
T_2 V_35 )
{
struct V_14 V_72 = {
. V_21 = V_74 -> V_21 ,
. V_16 = {
. V_24 = V_85 -> V_30 . V_24 ,
. V_17 = V_85 -> V_30 . V_17 ,
} ,
. V_86 = V_74 -> V_86 ,
. V_87 = V_85 -> V_30 . V_88 ,
. V_56 = V_74 -> V_56 ,
. V_35 = V_35 ,
. V_69 = V_84 ,
. V_46 = F_23 ( V_84 ) ,
. V_25 = V_85 ,
} ;
return F_24 ( V_83 , & V_72 , V_74 , V_35 ) ;
}
struct V_14 * F_31 ( struct V_1 * V_83 ,
struct V_73 * V_74 ,
struct V_68 * V_84 , T_2 V_35 )
{
struct V_14 V_72 = {
. V_21 = V_74 -> V_21 ,
. V_16 = {
. V_24 = V_74 -> V_24 ,
. V_17 = V_74 -> V_17 ,
} ,
. V_86 = V_74 -> V_86 ,
. V_87 = V_74 -> V_88 ,
. V_56 = V_74 -> V_56 ,
. V_35 = V_35 ,
. V_69 = V_84 ,
. V_46 = F_23 ( V_84 ) ,
} ;
return F_24 ( V_83 , & V_72 , V_74 , V_35 ) ;
}
T_5
F_26 ( struct V_14 * V_89 , struct V_14 * V_90 )
{
struct V_91 * V_92 ;
T_5 V_76 = 0 ;
F_32 (se, &hist_entry__sort_list, list) {
V_76 = V_92 -> V_93 ( V_89 , V_90 ) ;
if ( V_76 )
break;
}
return V_76 ;
}
T_5
F_33 ( struct V_14 * V_89 , struct V_14 * V_90 )
{
struct V_91 * V_92 ;
T_5 V_76 = 0 ;
F_32 (se, &hist_entry__sort_list, list) {
T_5 (* F_34)( struct V_14 * , struct V_14 * );
F_34 = V_92 -> V_94 ? : V_92 -> V_93 ;
V_76 = F_34 ( V_89 , V_90 ) ;
if ( V_76 )
break;
}
return V_76 ;
}
void F_17 ( struct V_14 * V_33 )
{
free ( V_33 ) ;
}
static bool F_35 ( struct V_1 * V_1 V_95 ,
struct V_96 * V_97 ,
struct V_14 * V_33 )
{
struct V_52 * * V_75 = & V_97 -> V_52 ;
struct V_52 * V_69 = NULL ;
struct V_14 * V_98 ;
T_5 V_76 ;
while ( * V_75 != NULL ) {
V_69 = * V_75 ;
V_98 = F_14 ( V_69 , struct V_14 , V_59 ) ;
V_76 = F_33 ( V_98 , V_33 ) ;
if ( ! V_76 ) {
V_98 -> V_35 += V_33 -> V_35 ;
V_98 -> V_44 += V_33 -> V_44 ;
if ( V_10 . V_64 ) {
F_36 ( & V_99 ) ;
F_37 ( & V_99 ,
V_98 -> V_67 ,
V_33 -> V_67 ) ;
}
F_17 ( V_33 ) ;
return false ;
}
if ( V_76 < 0 )
V_75 = & ( * V_75 ) -> V_80 ;
else
V_75 = & ( * V_75 ) -> V_81 ;
}
F_27 ( & V_33 -> V_59 , V_69 , V_75 ) ;
F_28 ( & V_33 -> V_59 , V_97 ) ;
return true ;
}
static struct V_96 * F_38 ( struct V_1 * V_1 )
{
struct V_96 * V_97 ;
F_25 ( & V_1 -> V_77 ) ;
V_97 = V_1 -> V_78 ;
if ( ++ V_1 -> V_78 > & V_1 -> V_100 [ 1 ] )
V_1 -> V_78 = & V_1 -> V_100 [ 0 ] ;
F_29 ( & V_1 -> V_77 ) ;
return V_97 ;
}
static void F_39 ( struct V_1 * V_1 , struct V_14 * V_33 )
{
F_40 ( V_1 , V_33 ) ;
F_41 ( V_1 , V_33 ) ;
F_42 ( V_1 , V_33 ) ;
}
static void F_43 ( struct V_1 * V_1 , bool V_51 )
{
struct V_96 * V_97 ;
struct V_52 * V_53 ;
struct V_14 * V_55 ;
if ( ! V_58 && ! V_51 )
return;
V_97 = F_38 ( V_1 ) ;
V_53 = F_13 ( V_97 ) ;
while ( V_53 ) {
V_55 = F_14 ( V_53 , struct V_14 , V_59 ) ;
V_53 = F_15 ( & V_55 -> V_59 ) ;
F_16 ( & V_55 -> V_59 , V_97 ) ;
if ( F_35 ( V_1 , & V_1 -> V_60 , V_55 ) ) {
F_39 ( V_1 , V_55 ) ;
}
}
}
void F_44 ( struct V_1 * V_1 )
{
return F_43 ( V_1 , false ) ;
}
void F_45 ( struct V_1 * V_1 )
{
return F_43 ( V_1 , true ) ;
}
static void F_46 ( struct V_96 * V_54 ,
struct V_14 * V_33 ,
T_2 V_101 )
{
struct V_52 * * V_75 = & V_54 -> V_52 ;
struct V_52 * V_69 = NULL ;
struct V_14 * V_98 ;
if ( V_10 . V_64 )
V_102 . V_103 ( & V_33 -> V_104 , V_33 -> V_67 ,
V_101 , & V_102 ) ;
while ( * V_75 != NULL ) {
V_69 = * V_75 ;
V_98 = F_14 ( V_69 , struct V_14 , V_52 ) ;
if ( V_33 -> V_35 > V_98 -> V_35 )
V_75 = & ( * V_75 ) -> V_80 ;
else
V_75 = & ( * V_75 ) -> V_81 ;
}
F_27 ( & V_33 -> V_52 , V_69 , V_75 ) ;
F_28 ( & V_33 -> V_52 , V_54 ) ;
}
static void F_47 ( struct V_1 * V_1 , bool V_51 )
{
struct V_96 * V_97 ;
struct V_52 * V_53 ;
struct V_14 * V_55 ;
T_2 V_101 ;
V_101 = V_1 -> V_47 . V_48 * ( V_102 . V_105 / 100 ) ;
if ( V_58 || V_51 )
V_97 = & V_1 -> V_60 ;
else
V_97 = V_1 -> V_78 ;
V_53 = F_13 ( V_97 ) ;
V_1 -> V_54 = V_106 ;
V_1 -> V_61 = 0 ;
V_1 -> V_47 . V_48 = 0 ;
F_4 ( V_1 ) ;
while ( V_53 ) {
V_55 = F_14 ( V_53 , struct V_14 , V_59 ) ;
V_53 = F_15 ( & V_55 -> V_59 ) ;
F_46 ( & V_1 -> V_54 , V_55 , V_101 ) ;
F_22 ( V_1 , V_55 ) ;
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
static T_3 F_50 ( T_6 * V_107 , int V_108 )
{
int V_109 ;
int V_110 = fprintf ( V_107 , L_1 ) ;
for ( V_109 = 0 ; V_109 < V_108 ; V_109 ++ )
V_110 += fprintf ( V_107 , L_2 ) ;
return V_110 ;
}
static T_3 F_51 ( T_6 * V_107 , int V_111 , int V_112 ,
int V_108 )
{
int V_109 ;
T_3 V_110 = F_50 ( V_107 , V_108 ) ;
for ( V_109 = 0 ; V_109 < V_111 ; V_109 ++ )
if ( V_112 & ( 1 << V_109 ) )
V_110 += fprintf ( V_107 , L_3 ) ;
else
V_110 += fprintf ( V_107 , L_4 ) ;
V_110 += fprintf ( V_107 , L_5 ) ;
return V_110 ;
}
static T_3 F_52 ( T_6 * V_107 , struct V_113 * V_114 ,
int V_111 , int V_112 , int V_35 ,
T_2 V_115 , T_2 V_116 ,
int V_108 )
{
int V_109 ;
T_3 V_110 = 0 ;
V_110 += F_50 ( V_107 , V_108 ) ;
for ( V_109 = 0 ; V_109 < V_111 ; V_109 ++ ) {
if ( V_112 & ( 1 << V_109 ) )
V_110 += fprintf ( V_107 , L_6 ) ;
else
V_110 += fprintf ( V_107 , L_2 ) ;
if ( ! V_35 && V_109 == V_111 - 1 ) {
double V_117 ;
V_117 = V_116 * 100.0 / V_115 ;
V_110 += F_53 ( V_107 , L_7 , V_117 ) ;
} else
V_110 += fprintf ( V_107 , L_8 , L_9 ) ;
}
if ( V_114 -> V_16 . V_17 )
V_110 += fprintf ( V_107 , L_10 , V_114 -> V_16 . V_17 -> V_118 ) ;
else
V_110 += fprintf ( V_107 , L_11 V_119 L_5 , V_114 -> V_87 ) ;
return V_110 ;
}
static void F_54 ( void )
{
V_120 = malloc ( sizeof( * V_120 ) + 6 ) ;
if ( ! V_120 ) {
fprintf ( V_121 , L_12 ) ;
return;
}
strcpy ( V_120 -> V_118 , L_13 ) ;
V_122 . V_16 . V_17 = V_120 ;
}
static T_3 F_55 ( T_6 * V_107 , struct V_96 * V_97 ,
T_2 V_115 , int V_111 ,
int V_112 , int V_108 )
{
struct V_52 * V_123 , * V_53 ;
struct V_124 * V_125 ;
struct V_113 * V_114 ;
int V_126 = V_112 ;
T_2 V_127 ;
T_3 V_110 = 0 ;
int V_109 ;
T_7 V_128 = 0 ;
V_127 = V_115 ;
V_123 = F_13 ( V_97 ) ;
while ( V_123 ) {
T_2 V_129 ;
T_2 V_130 ;
V_125 = F_14 ( V_123 , struct V_124 , V_52 ) ;
V_130 = F_56 ( V_125 ) ;
V_127 -= V_130 ;
V_53 = F_15 ( V_123 ) ;
if ( ! V_53 && ( V_102 . V_131 != V_132 || ! V_127 ) )
V_126 &= ~ ( 1 << ( V_111 - 1 ) ) ;
V_110 += F_51 ( V_107 , V_111 , V_112 ,
V_108 ) ;
V_109 = 0 ;
F_32 (chain, &child->val, list) {
V_110 += F_52 ( V_107 , V_114 , V_111 ,
V_126 , V_109 ++ ,
V_115 ,
V_130 ,
V_108 ) ;
}
if ( V_102 . V_131 == V_132 )
V_129 = V_125 -> V_133 ;
else
V_129 = V_115 ;
V_110 += F_55 ( V_107 , & V_125 -> V_96 , V_129 ,
V_111 + 1 ,
V_126 | ( 1 << V_111 ) ,
V_108 ) ;
V_123 = V_53 ;
if ( ++ V_128 == V_102 . V_134 )
break;
}
if ( V_102 . V_131 == V_132 &&
V_127 && V_127 != V_115 ) {
if ( ! V_120 )
return V_110 ;
V_126 &= ~ ( 1 << ( V_111 - 1 ) ) ;
V_110 += F_52 ( V_107 , & V_122 , V_111 ,
V_126 , 0 , V_115 ,
V_127 , V_108 ) ;
}
return V_110 ;
}
static T_3 F_57 ( T_6 * V_107 , struct V_96 * V_97 ,
T_2 V_115 , int V_108 )
{
struct V_124 * V_135 ;
struct V_113 * V_114 ;
T_8 V_128 = 0 ;
bool V_136 = false ;
struct V_52 * V_123 ;
int V_109 = 0 ;
int V_110 = 0 ;
V_123 = F_13 ( V_97 ) ;
if ( V_123 && ! F_15 ( V_123 ) ) {
V_135 = F_14 ( V_123 , struct V_124 , V_52 ) ;
F_32 (chain, &cnode->val, list) {
if ( ! V_109 ++ && V_137 == V_138 )
continue;
if ( ! V_136 ) {
V_110 += F_50 ( V_107 , V_108 ) ;
V_110 += fprintf ( V_107 , L_14 ) ;
V_110 += F_50 ( V_107 , V_108 ) ;
V_110 += fprintf ( V_107 , L_15 ) ;
V_108 += 3 ;
V_136 = true ;
} else
V_110 += F_50 ( V_107 , V_108 ) ;
if ( V_114 -> V_16 . V_17 )
V_110 += fprintf ( V_107 , L_16 , V_114 -> V_16 . V_17 -> V_118 ) ;
else
V_110 += fprintf ( V_107 , L_17 , ( void * ) ( long ) V_114 -> V_87 ) ;
if ( ++ V_128 == V_102 . V_134 )
break;
}
V_97 = & V_135 -> V_96 ;
}
V_110 += F_55 ( V_107 , V_97 , V_115 ,
1 , 1 , V_108 ) ;
V_110 += fprintf ( V_107 , L_5 ) ;
return V_110 ;
}
static T_3 F_58 ( T_6 * V_107 ,
struct V_124 * V_83 ,
T_2 V_115 )
{
struct V_113 * V_114 ;
T_3 V_110 = 0 ;
if ( ! V_83 )
return 0 ;
V_110 += F_58 ( V_107 , V_83 -> V_69 , V_115 ) ;
F_32 (chain, &self->val, list) {
if ( V_114 -> V_87 >= V_139 )
continue;
if ( V_114 -> V_16 . V_17 )
V_110 += fprintf ( V_107 , L_18 , V_114 -> V_16 . V_17 -> V_118 ) ;
else
V_110 += fprintf ( V_107 , L_19 ,
( void * ) ( long ) V_114 -> V_87 ) ;
}
return V_110 ;
}
static T_3 F_59 ( T_6 * V_107 , struct V_96 * V_83 ,
T_2 V_115 )
{
T_3 V_110 = 0 ;
T_8 V_128 = 0 ;
struct V_52 * V_52 ;
struct V_124 * V_114 ;
V_52 = F_13 ( V_83 ) ;
while ( V_52 ) {
double V_117 ;
V_114 = F_14 ( V_52 , struct V_124 , V_52 ) ;
V_117 = V_114 -> V_140 * 100.0 / V_115 ;
V_110 = F_53 ( V_107 , L_20 , V_117 ) ;
V_110 += F_58 ( V_107 , V_114 , V_115 ) ;
V_110 += fprintf ( V_107 , L_5 ) ;
if ( ++ V_128 == V_102 . V_134 )
break;
V_52 = F_15 ( V_52 ) ;
}
return V_110 ;
}
static T_3 F_60 ( struct V_14 * V_33 ,
T_2 V_115 , int V_108 ,
T_6 * V_107 )
{
switch ( V_102 . V_131 ) {
case V_132 :
return F_57 ( V_107 , & V_33 -> V_104 , V_33 -> V_35 ,
V_108 ) ;
break;
case V_141 :
return F_57 ( V_107 , & V_33 -> V_104 , V_115 ,
V_108 ) ;
break;
case V_142 :
return F_59 ( V_107 , & V_33 -> V_104 , V_115 ) ;
break;
case V_143 :
break;
default:
F_61 ( L_21 ) ;
}
return 0 ;
}
void F_62 ( struct V_1 * V_1 , int V_144 )
{
struct V_52 * V_53 = F_13 ( & V_1 -> V_54 ) ;
struct V_14 * V_55 ;
int V_145 = 0 ;
F_4 ( V_1 ) ;
while ( V_53 && V_145 ++ < V_144 ) {
V_55 = F_14 ( V_53 , struct V_14 , V_52 ) ;
if ( ! V_55 -> V_46 )
F_6 ( V_1 , V_55 ) ;
V_53 = F_15 ( & V_55 -> V_52 ) ;
}
}
static int F_63 ( struct V_14 * V_33 , char * V_146 ,
T_3 V_147 , struct V_1 * V_148 ,
bool V_149 , long V_150 ,
bool V_151 , T_2 V_48 )
{
T_2 V_35 , V_152 , V_37 , V_39 , V_41 , V_43 ;
T_2 V_44 ;
const char * V_153 = V_10 . V_12 ;
int V_110 ;
if ( V_10 . V_70 && ! V_33 -> V_69 )
return 0 ;
if ( V_148 ) {
V_35 = V_33 -> V_154 ? V_33 -> V_154 -> V_35 : 0 ;
V_44 = V_33 -> V_154 ? V_33 -> V_154 -> V_44 : 0 ;
V_152 = V_148 -> V_47 . V_48 ;
V_37 = V_33 -> V_154 ? V_33 -> V_154 -> V_37 : 0 ;
V_39 = V_33 -> V_154 ? V_33 -> V_154 -> V_39 : 0 ;
V_41 = V_33 -> V_154 ? V_33 -> V_154 -> V_41 : 0 ;
V_43 = V_33 -> V_154 ? V_33 -> V_154 -> V_43 : 0 ;
} else {
V_35 = V_33 -> V_35 ;
V_44 = V_33 -> V_44 ;
V_152 = V_48 ;
V_37 = V_33 -> V_37 ;
V_39 = V_33 -> V_39 ;
V_41 = V_33 -> V_41 ;
V_43 = V_33 -> V_43 ;
}
if ( V_152 ) {
if ( V_151 )
V_110 = F_64 ( V_146 , V_147 ,
V_153 ? L_22 : L_23 ,
( V_35 * 100.0 ) / V_152 ) ;
else
V_110 = F_65 ( V_146 , V_147 , V_153 ? L_22 : L_23 ,
( V_35 * 100.0 ) / V_152 ) ;
if ( V_10 . V_155 ) {
V_110 += F_64 ( V_146 + V_110 , V_147 - V_110 ,
V_153 ? L_22 : L_23 ,
( V_37 * 100.0 ) / V_152 ) ;
V_110 += F_64 ( V_146 + V_110 , V_147 - V_110 ,
V_153 ? L_22 : L_23 ,
( V_39 * 100.0 ) / V_152 ) ;
if ( V_156 ) {
V_110 += F_64 ( V_146 + V_110 ,
V_147 - V_110 ,
V_153 ? L_22 : L_23 ,
( V_41 * 100.0 ) /
V_152 ) ;
V_110 += F_64 ( V_146 + V_110 ,
V_147 - V_110 ,
V_153 ? L_22 : L_23 ,
( V_43 * 100.0 ) /
V_152 ) ;
}
}
} else
V_110 = F_65 ( V_146 , V_147 , V_153 ? L_24 V_157 : L_25 V_157 L_2 , V_35 ) ;
if ( V_10 . V_158 ) {
if ( V_153 )
V_110 += F_65 ( V_146 + V_110 , V_147 - V_110 , L_26 V_157 , * V_153 , V_44 ) ;
else
V_110 += F_65 ( V_146 + V_110 , V_147 - V_110 , L_27 V_157 , V_44 ) ;
}
if ( V_10 . V_159 ) {
if ( V_153 )
V_110 += F_65 ( V_146 + V_110 , V_147 - V_110 , L_26 V_157 , * V_153 , V_35 ) ;
else
V_110 += F_65 ( V_146 + V_110 , V_147 - V_110 , L_28 V_157 , V_35 ) ;
}
if ( V_148 ) {
char V_160 [ 32 ] ;
double V_161 = 0 , V_162 = 0 , V_163 ;
if ( V_152 > 0 )
V_161 = ( V_35 * 100.0 ) / V_152 ;
if ( V_48 > 0 )
V_162 = ( V_33 -> V_35 * 100.0 ) / V_48 ;
V_163 = V_162 - V_161 ;
if ( fabs ( V_163 ) >= 0.01 )
F_65 ( V_160 , sizeof( V_160 ) , L_29 , V_163 ) ;
else
F_65 ( V_160 , sizeof( V_160 ) , L_2 ) ;
if ( V_153 )
V_110 += F_65 ( V_146 + V_110 , V_147 - V_110 , L_30 , * V_153 , V_160 ) ;
else
V_110 += F_65 ( V_146 + V_110 , V_147 - V_110 , L_31 , V_160 ) ;
if ( V_149 ) {
if ( V_150 )
F_65 ( V_160 , sizeof( V_160 ) , L_32 , V_150 ) ;
else
F_65 ( V_160 , sizeof( V_160 ) , L_2 ) ;
if ( V_153 )
V_110 += F_65 ( V_146 + V_110 , V_147 - V_110 , L_30 , * V_153 , V_160 ) ;
else
V_110 += F_65 ( V_146 + V_110 , V_147 - V_110 , L_33 , V_160 ) ;
}
}
return V_110 ;
}
int F_66 ( struct V_14 * V_33 , char * V_146 , T_3 V_147 ,
struct V_1 * V_1 )
{
const char * V_153 = V_10 . V_12 ;
struct V_91 * V_92 ;
int V_110 = 0 ;
F_32 (se, &hist_entry__sort_list, list) {
if ( V_92 -> V_164 )
continue;
V_110 += F_65 ( V_146 + V_110 , V_147 - V_110 , L_8 , V_153 ? : L_34 ) ;
V_110 += V_92 -> V_165 ( V_33 , V_146 + V_110 , V_147 - V_110 ,
F_1 ( V_1 , V_92 -> V_166 ) ) ;
}
return V_110 ;
}
static int F_67 ( struct V_14 * V_33 , T_3 V_147 ,
struct V_1 * V_1 , struct V_1 * V_148 ,
bool V_149 , long V_150 ,
T_2 V_48 , T_6 * V_107 )
{
char V_160 [ 512 ] ;
int V_110 ;
if ( V_147 == 0 || V_147 > sizeof( V_160 ) )
V_147 = sizeof( V_160 ) ;
V_110 = F_63 ( V_33 , V_160 , V_147 , V_148 ,
V_149 , V_150 ,
true , V_48 ) ;
F_66 ( V_33 , V_160 + V_110 , V_147 - V_110 , V_1 ) ;
return fprintf ( V_107 , L_10 , V_160 ) ;
}
static T_3 F_68 ( struct V_14 * V_33 ,
struct V_1 * V_1 ,
T_2 V_48 , T_6 * V_107 )
{
int V_108 = 0 ;
if ( V_137 == V_167 ) {
struct V_91 * V_92 = F_69 ( & V_168 ,
F_70 ( * V_92 ) , V_169 ) ;
V_108 = F_1 ( V_1 , V_92 -> V_166 ) ;
V_108 -= F_7 ( V_33 -> V_21 ) ;
}
return F_60 ( V_33 , V_48 , V_108 , V_107 ) ;
}
T_3 F_71 ( struct V_1 * V_1 , struct V_1 * V_154 ,
bool V_149 , bool V_170 , int V_144 ,
int V_171 , T_6 * V_107 )
{
struct V_91 * V_92 ;
struct V_52 * V_172 ;
T_3 V_110 = 0 ;
T_2 V_48 ;
unsigned long V_173 = 1 ;
long V_150 = 0 ;
unsigned int V_174 ;
const char * V_153 = V_10 . V_12 ;
const char * V_175 = V_10 . V_11 ;
int V_176 = 0 ;
F_54 () ;
if ( ! V_170 )
goto V_177;
fprintf ( V_107 , L_35 , V_154 ? L_36 : L_37 ) ;
if ( V_10 . V_155 ) {
if ( V_153 ) {
V_110 += fprintf ( V_107 , L_38 , * V_153 ) ;
V_110 += fprintf ( V_107 , L_39 , * V_153 ) ;
if ( V_156 ) {
V_110 += fprintf ( V_107 , L_40 , * V_153 ) ;
V_110 += fprintf ( V_107 , L_41 , * V_153 ) ;
}
} else {
V_110 += fprintf ( V_107 , L_42 ) ;
V_110 += fprintf ( V_107 , L_43 ) ;
if ( V_156 ) {
V_110 += fprintf ( V_107 , L_44 ) ;
V_110 += fprintf ( V_107 , L_45 ) ;
}
}
}
if ( V_10 . V_158 ) {
if ( V_153 )
fprintf ( V_107 , L_46 , * V_153 ) ;
else
fputs ( L_47 , V_107 ) ;
}
if ( V_10 . V_159 ) {
if ( V_153 )
V_110 += fprintf ( V_107 , L_48 , * V_153 ) ;
else
V_110 += fprintf ( V_107 , L_49 ) ;
}
if ( V_154 ) {
if ( V_153 )
V_110 += fprintf ( V_107 , L_50 , * V_153 ) ;
else
V_110 += fprintf ( V_107 , L_51 ) ;
if ( V_149 ) {
if ( V_153 )
V_110 += fprintf ( V_107 , L_52 , * V_153 ) ;
else
V_110 += fprintf ( V_107 , L_53 ) ;
}
}
F_32 (se, &hist_entry__sort_list, list) {
if ( V_92 -> V_164 )
continue;
if ( V_153 ) {
fprintf ( V_107 , L_30 , * V_153 , V_92 -> V_178 ) ;
continue;
}
V_174 = strlen ( V_92 -> V_178 ) ;
if ( V_10 . V_11 ) {
if ( V_175 ) {
F_2 ( V_1 , V_92 -> V_166 ,
atoi ( V_175 ) ) ;
V_175 = strchr ( V_175 , ',' ) ;
if ( V_175 )
++ V_175 ;
}
}
if ( ! F_3 ( V_1 , V_92 -> V_166 , V_174 ) )
V_174 = F_1 ( V_1 , V_92 -> V_166 ) ;
fprintf ( V_107 , L_54 , V_174 , V_92 -> V_178 ) ;
}
fprintf ( V_107 , L_5 ) ;
if ( V_144 && ++ V_176 >= V_144 )
goto V_79;
if ( V_153 )
goto V_177;
fprintf ( V_107 , L_55 ) ;
if ( V_10 . V_155 )
fprintf ( V_107 , L_56 ) ;
if ( V_10 . V_158 )
fprintf ( V_107 , L_57 ) ;
if ( V_10 . V_159 )
fprintf ( V_107 , L_58 ) ;
if ( V_154 ) {
fprintf ( V_107 , L_57 ) ;
if ( V_149 )
fprintf ( V_107 , L_59 ) ;
}
F_32 (se, &hist_entry__sort_list, list) {
unsigned int V_109 ;
if ( V_92 -> V_164 )
continue;
fprintf ( V_107 , L_34 ) ;
V_174 = F_1 ( V_1 , V_92 -> V_166 ) ;
if ( V_174 == 0 )
V_174 = strlen ( V_92 -> V_178 ) ;
for ( V_109 = 0 ; V_109 < V_174 ; V_109 ++ )
fprintf ( V_107 , L_60 ) ;
}
fprintf ( V_107 , L_5 ) ;
if ( V_144 && ++ V_176 >= V_144 )
goto V_79;
fprintf ( V_107 , L_61 ) ;
if ( V_144 && ++ V_176 >= V_144 )
goto V_79;
V_177:
V_48 = V_1 -> V_47 . V_48 ;
for ( V_172 = F_13 ( & V_1 -> V_54 ) ; V_172 ; V_172 = F_15 ( V_172 ) ) {
struct V_14 * V_15 = F_14 ( V_172 , struct V_14 , V_52 ) ;
if ( V_15 -> V_46 )
continue;
if ( V_149 ) {
if ( V_15 -> V_154 != NULL )
V_150 = ( ( long ) V_15 -> V_154 -> V_173 -
( long ) V_173 ) ;
else
V_150 = 0 ;
++ V_173 ;
}
V_110 += F_67 ( V_15 , V_171 , V_1 , V_154 , V_149 ,
V_150 , V_48 , V_107 ) ;
if ( V_10 . V_64 )
V_110 += F_68 ( V_15 , V_1 , V_48 , V_107 ) ;
if ( V_144 && ++ V_176 >= V_144 )
goto V_79;
if ( V_15 -> V_16 . V_24 == NULL && V_179 > 1 ) {
F_72 ( & V_15 -> V_21 -> V_180 ,
V_181 , V_179 , V_107 ) ;
fprintf ( V_107 , L_62 , V_182 ) ;
}
}
V_79:
free ( V_120 ) ;
return V_110 ;
}
unsigned int F_73 ( struct V_1 * V_1 )
{
struct V_91 * V_92 ;
int V_110 = 9 ;
if ( V_10 . V_155 ) {
V_110 += 7 ;
V_110 += 6 ;
if ( V_156 ) {
V_110 += 13 ;
V_110 += 12 ;
}
}
if ( V_10 . V_158 )
V_110 += 11 ;
if ( V_10 . V_159 )
V_110 += 13 ;
F_32 (se, &hist_entry__sort_list, list)
if ( ! V_92 -> V_164 )
V_110 += 2 + F_1 ( V_1 , V_92 -> V_166 ) ;
if ( V_179 )
V_110 += 3 + V_9 / 4 ;
return V_110 ;
}
static void F_74 ( struct V_1 * V_1 , struct V_14 * V_15 ,
enum V_183 V_184 )
{
V_15 -> V_46 &= ~ ( 1 << V_184 ) ;
if ( V_15 -> V_46 )
return;
++ V_1 -> V_61 ;
if ( V_15 -> V_16 . V_185 )
V_1 -> V_61 += V_15 -> V_176 ;
V_15 -> V_186 = 0 ;
V_1 -> V_47 . V_48 += V_15 -> V_35 ;
V_1 -> V_47 . V_44 [ V_187 ] += V_15 -> V_44 ;
F_6 ( V_1 , V_15 ) ;
}
static bool F_40 ( struct V_1 * V_1 ,
struct V_14 * V_33 )
{
if ( V_1 -> V_188 != NULL &&
( V_33 -> V_16 . V_24 == NULL || V_33 -> V_16 . V_24 -> V_7 != V_1 -> V_188 ) ) {
V_33 -> V_46 |= ( 1 << V_189 ) ;
return true ;
}
return false ;
}
void F_75 ( struct V_1 * V_1 )
{
struct V_52 * V_172 ;
V_1 -> V_61 = V_1 -> V_47 . V_48 = 0 ;
V_1 -> V_47 . V_44 [ V_187 ] = 0 ;
F_4 ( V_1 ) ;
for ( V_172 = F_13 ( & V_1 -> V_54 ) ; V_172 ; V_172 = F_15 ( V_172 ) ) {
struct V_14 * V_15 = F_14 ( V_172 , struct V_14 , V_52 ) ;
if ( V_10 . V_70 && ! V_15 -> V_69 )
continue;
if ( F_40 ( V_1 , V_15 ) )
continue;
F_74 ( V_1 , V_15 , V_189 ) ;
}
}
static bool F_41 ( struct V_1 * V_1 ,
struct V_14 * V_33 )
{
if ( V_1 -> V_190 != NULL &&
V_33 -> V_21 != V_1 -> V_190 ) {
V_33 -> V_46 |= ( 1 << V_191 ) ;
return true ;
}
return false ;
}
void F_76 ( struct V_1 * V_1 )
{
struct V_52 * V_172 ;
V_1 -> V_61 = V_1 -> V_47 . V_48 = 0 ;
V_1 -> V_47 . V_44 [ V_187 ] = 0 ;
F_4 ( V_1 ) ;
for ( V_172 = F_13 ( & V_1 -> V_54 ) ; V_172 ; V_172 = F_15 ( V_172 ) ) {
struct V_14 * V_15 = F_14 ( V_172 , struct V_14 , V_52 ) ;
if ( F_41 ( V_1 , V_15 ) )
continue;
F_74 ( V_1 , V_15 , V_191 ) ;
}
}
static bool F_42 ( struct V_1 * V_1 ,
struct V_14 * V_33 )
{
if ( V_1 -> V_192 != NULL &&
( ! V_33 -> V_16 . V_17 || strstr ( V_33 -> V_16 . V_17 -> V_118 ,
V_1 -> V_192 ) == NULL ) ) {
V_33 -> V_46 |= ( 1 << V_193 ) ;
return true ;
}
return false ;
}
void F_77 ( struct V_1 * V_1 )
{
struct V_52 * V_172 ;
V_1 -> V_61 = V_1 -> V_47 . V_48 = 0 ;
V_1 -> V_47 . V_44 [ V_187 ] = 0 ;
F_4 ( V_1 ) ;
for ( V_172 = F_13 ( & V_1 -> V_54 ) ; V_172 ; V_172 = F_15 ( V_172 ) ) {
struct V_14 * V_15 = F_14 ( V_172 , struct V_14 , V_52 ) ;
if ( F_42 ( V_1 , V_15 ) )
continue;
F_74 ( V_1 , V_15 , V_193 ) ;
}
}
int F_78 ( struct V_14 * V_33 , int V_194 , T_2 V_87 )
{
return F_79 ( V_33 -> V_16 . V_17 , V_33 -> V_16 . V_24 , V_194 , V_87 ) ;
}
int F_80 ( struct V_14 * V_33 , T_3 V_195 )
{
return F_81 ( V_33 -> V_16 . V_17 , V_33 -> V_16 . V_24 , V_195 ) ;
}
void F_82 ( struct V_1 * V_1 , T_8 type )
{
++ V_1 -> V_47 . V_44 [ 0 ] ;
++ V_1 -> V_47 . V_44 [ type ] ;
}
T_3 F_83 ( struct V_1 * V_1 , T_6 * V_107 )
{
int V_109 ;
T_3 V_110 = 0 ;
for ( V_109 = 0 ; V_109 < V_196 ; ++ V_109 ) {
const char * V_118 ;
if ( V_1 -> V_47 . V_44 [ V_109 ] == 0 )
continue;
V_118 = F_84 ( V_109 ) ;
if ( ! strcmp ( V_118 , L_63 ) )
continue;
V_110 += fprintf ( V_107 , L_64 , V_118 ,
V_1 -> V_47 . V_44 [ V_109 ] ) ;
}
return V_110 ;
}
