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
static bool F_35 ( struct V_1 * V_1 ,
struct V_95 * V_96 ,
struct V_14 * V_33 )
{
struct V_52 * * V_75 = & V_96 -> V_52 ;
struct V_52 * V_69 = NULL ;
struct V_14 * V_97 ;
T_5 V_76 ;
while ( * V_75 != NULL ) {
V_69 = * V_75 ;
V_97 = F_14 ( V_69 , struct V_14 , V_59 ) ;
V_76 = F_33 ( V_97 , V_33 ) ;
if ( ! V_76 ) {
V_97 -> V_35 += V_33 -> V_35 ;
V_97 -> V_44 += V_33 -> V_44 ;
if ( V_10 . V_64 ) {
F_36 ( & V_1 -> V_98 ) ;
F_37 ( & V_1 -> V_98 , V_97 -> V_67 ,
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
F_28 ( & V_33 -> V_59 , V_96 ) ;
return true ;
}
static struct V_95 * F_38 ( struct V_1 * V_1 )
{
struct V_95 * V_96 ;
F_25 ( & V_1 -> V_77 ) ;
V_96 = V_1 -> V_78 ;
if ( ++ V_1 -> V_78 > & V_1 -> V_99 [ 1 ] )
V_1 -> V_78 = & V_1 -> V_99 [ 0 ] ;
F_29 ( & V_1 -> V_77 ) ;
return V_96 ;
}
static void F_39 ( struct V_1 * V_1 , struct V_14 * V_33 )
{
F_40 ( V_1 , V_33 ) ;
F_41 ( V_1 , V_33 ) ;
F_42 ( V_1 , V_33 ) ;
}
static void F_43 ( struct V_1 * V_1 , bool V_51 )
{
struct V_95 * V_96 ;
struct V_52 * V_53 ;
struct V_14 * V_55 ;
if ( ! V_58 && ! V_51 )
return;
V_96 = F_38 ( V_1 ) ;
V_53 = F_13 ( V_96 ) ;
while ( V_53 ) {
V_55 = F_14 ( V_53 , struct V_14 , V_59 ) ;
V_53 = F_15 ( & V_55 -> V_59 ) ;
F_16 ( & V_55 -> V_59 , V_96 ) ;
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
static void F_46 ( struct V_95 * V_54 ,
struct V_14 * V_33 ,
T_2 V_100 )
{
struct V_52 * * V_75 = & V_54 -> V_52 ;
struct V_52 * V_69 = NULL ;
struct V_14 * V_97 ;
if ( V_10 . V_64 )
V_101 . V_102 ( & V_33 -> V_103 , V_33 -> V_67 ,
V_100 , & V_101 ) ;
while ( * V_75 != NULL ) {
V_69 = * V_75 ;
V_97 = F_14 ( V_69 , struct V_14 , V_52 ) ;
if ( V_33 -> V_35 > V_97 -> V_35 )
V_75 = & ( * V_75 ) -> V_80 ;
else
V_75 = & ( * V_75 ) -> V_81 ;
}
F_27 ( & V_33 -> V_52 , V_69 , V_75 ) ;
F_28 ( & V_33 -> V_52 , V_54 ) ;
}
static void F_47 ( struct V_1 * V_1 , bool V_51 )
{
struct V_95 * V_96 ;
struct V_52 * V_53 ;
struct V_14 * V_55 ;
T_2 V_100 ;
V_100 = V_1 -> V_47 . V_48 * ( V_101 . V_104 / 100 ) ;
if ( V_58 || V_51 )
V_96 = & V_1 -> V_60 ;
else
V_96 = V_1 -> V_78 ;
V_53 = F_13 ( V_96 ) ;
V_1 -> V_54 = V_105 ;
V_1 -> V_61 = 0 ;
V_1 -> V_47 . V_48 = 0 ;
F_4 ( V_1 ) ;
while ( V_53 ) {
V_55 = F_14 ( V_53 , struct V_14 , V_59 ) ;
V_53 = F_15 ( & V_55 -> V_59 ) ;
F_46 ( & V_1 -> V_54 , V_55 , V_100 ) ;
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
static T_3 F_50 ( T_6 * V_106 , int V_107 )
{
int V_108 ;
int V_109 = fprintf ( V_106 , L_1 ) ;
for ( V_108 = 0 ; V_108 < V_107 ; V_108 ++ )
V_109 += fprintf ( V_106 , L_2 ) ;
return V_109 ;
}
static T_3 F_51 ( T_6 * V_106 , int V_110 , int V_111 ,
int V_107 )
{
int V_108 ;
T_3 V_109 = F_50 ( V_106 , V_107 ) ;
for ( V_108 = 0 ; V_108 < V_110 ; V_108 ++ )
if ( V_111 & ( 1 << V_108 ) )
V_109 += fprintf ( V_106 , L_3 ) ;
else
V_109 += fprintf ( V_106 , L_4 ) ;
V_109 += fprintf ( V_106 , L_5 ) ;
return V_109 ;
}
static T_3 F_52 ( T_6 * V_106 , struct V_112 * V_113 ,
int V_110 , int V_111 , int V_35 ,
T_2 V_114 , T_2 V_115 ,
int V_107 )
{
int V_108 ;
T_3 V_109 = 0 ;
V_109 += F_50 ( V_106 , V_107 ) ;
for ( V_108 = 0 ; V_108 < V_110 ; V_108 ++ ) {
if ( V_111 & ( 1 << V_108 ) )
V_109 += fprintf ( V_106 , L_6 ) ;
else
V_109 += fprintf ( V_106 , L_2 ) ;
if ( ! V_35 && V_108 == V_110 - 1 ) {
double V_116 ;
V_116 = V_115 * 100.0 / V_114 ;
V_109 += F_53 ( V_106 , L_7 , V_116 ) ;
} else
V_109 += fprintf ( V_106 , L_8 , L_9 ) ;
}
if ( V_113 -> V_16 . V_17 )
V_109 += fprintf ( V_106 , L_10 , V_113 -> V_16 . V_17 -> V_117 ) ;
else
V_109 += fprintf ( V_106 , L_11 , ( void * ) ( long ) V_113 -> V_87 ) ;
return V_109 ;
}
static void F_54 ( void )
{
V_118 = malloc ( sizeof( * V_118 ) + 6 ) ;
if ( ! V_118 ) {
fprintf ( V_119 , L_12 ) ;
return;
}
strcpy ( V_118 -> V_117 , L_13 ) ;
V_120 . V_16 . V_17 = V_118 ;
}
static T_3 F_55 ( T_6 * V_106 , struct V_95 * V_96 ,
T_2 V_114 , int V_110 ,
int V_111 , int V_107 )
{
struct V_52 * V_121 , * V_53 ;
struct V_122 * V_123 ;
struct V_112 * V_113 ;
int V_124 = V_111 ;
T_2 V_125 ;
T_3 V_109 = 0 ;
int V_108 ;
T_7 V_126 = 0 ;
V_125 = V_114 ;
V_121 = F_13 ( V_96 ) ;
while ( V_121 ) {
T_2 V_127 ;
T_2 V_128 ;
V_123 = F_14 ( V_121 , struct V_122 , V_52 ) ;
V_128 = F_56 ( V_123 ) ;
V_125 -= V_128 ;
V_53 = F_15 ( V_121 ) ;
if ( ! V_53 && ( V_101 . V_129 != V_130 || ! V_125 ) )
V_124 &= ~ ( 1 << ( V_110 - 1 ) ) ;
V_109 += F_51 ( V_106 , V_110 , V_111 ,
V_107 ) ;
V_108 = 0 ;
F_32 (chain, &child->val, list) {
V_109 += F_52 ( V_106 , V_113 , V_110 ,
V_124 , V_108 ++ ,
V_114 ,
V_128 ,
V_107 ) ;
}
if ( V_101 . V_129 == V_130 )
V_127 = V_123 -> V_131 ;
else
V_127 = V_114 ;
V_109 += F_55 ( V_106 , & V_123 -> V_95 , V_127 ,
V_110 + 1 ,
V_124 | ( 1 << V_110 ) ,
V_107 ) ;
V_121 = V_53 ;
if ( ++ V_126 == V_101 . V_132 )
break;
}
if ( V_101 . V_129 == V_130 &&
V_125 && V_125 != V_114 ) {
if ( ! V_118 )
return V_109 ;
V_124 &= ~ ( 1 << ( V_110 - 1 ) ) ;
V_109 += F_52 ( V_106 , & V_120 , V_110 ,
V_124 , 0 , V_114 ,
V_125 , V_107 ) ;
}
return V_109 ;
}
static T_3 F_57 ( T_6 * V_106 , struct V_95 * V_96 ,
T_2 V_114 , int V_107 )
{
struct V_122 * V_133 ;
struct V_112 * V_113 ;
T_8 V_126 = 0 ;
bool V_134 = false ;
struct V_52 * V_121 ;
int V_108 = 0 ;
int V_109 ;
V_121 = F_13 ( V_96 ) ;
if ( V_121 && ! F_15 ( V_121 ) ) {
V_133 = F_14 ( V_121 , struct V_122 , V_52 ) ;
F_32 (chain, &cnode->val, list) {
if ( ! V_108 ++ && V_135 == V_136 )
continue;
if ( ! V_134 ) {
V_109 += F_50 ( V_106 , V_107 ) ;
V_109 += fprintf ( V_106 , L_14 ) ;
V_109 += F_50 ( V_106 , V_107 ) ;
V_109 += fprintf ( V_106 , L_15 ) ;
V_107 += 3 ;
V_134 = true ;
} else
V_109 += F_50 ( V_106 , V_107 ) ;
if ( V_113 -> V_16 . V_17 )
V_109 += fprintf ( V_106 , L_16 , V_113 -> V_16 . V_17 -> V_117 ) ;
else
V_109 += fprintf ( V_106 , L_17 , ( void * ) ( long ) V_113 -> V_87 ) ;
if ( ++ V_126 == V_101 . V_132 )
break;
}
V_96 = & V_133 -> V_95 ;
}
return F_55 ( V_106 , V_96 , V_114 ,
1 , 1 , V_107 ) ;
}
static T_3 F_58 ( T_6 * V_106 ,
struct V_122 * V_83 ,
T_2 V_114 )
{
struct V_112 * V_113 ;
T_3 V_109 = 0 ;
if ( ! V_83 )
return 0 ;
V_109 += F_58 ( V_106 , V_83 -> V_69 , V_114 ) ;
F_32 (chain, &self->val, list) {
if ( V_113 -> V_87 >= V_137 )
continue;
if ( V_113 -> V_16 . V_17 )
V_109 += fprintf ( V_106 , L_18 , V_113 -> V_16 . V_17 -> V_117 ) ;
else
V_109 += fprintf ( V_106 , L_19 ,
( void * ) ( long ) V_113 -> V_87 ) ;
}
return V_109 ;
}
static T_3 F_59 ( T_6 * V_106 , struct V_95 * V_83 ,
T_2 V_114 )
{
T_3 V_109 = 0 ;
T_8 V_126 = 0 ;
struct V_52 * V_52 ;
struct V_122 * V_113 ;
V_52 = F_13 ( V_83 ) ;
while ( V_52 ) {
double V_116 ;
V_113 = F_14 ( V_52 , struct V_122 , V_52 ) ;
V_116 = V_113 -> V_138 * 100.0 / V_114 ;
V_109 = F_53 ( V_106 , L_20 , V_116 ) ;
V_109 += F_58 ( V_106 , V_113 , V_114 ) ;
V_109 += fprintf ( V_106 , L_5 ) ;
if ( ++ V_126 == V_101 . V_132 )
break;
V_52 = F_15 ( V_52 ) ;
}
return V_109 ;
}
static T_3 F_60 ( struct V_14 * V_33 ,
T_2 V_114 , int V_107 ,
T_6 * V_106 )
{
switch ( V_101 . V_129 ) {
case V_130 :
return F_57 ( V_106 , & V_33 -> V_103 , V_33 -> V_35 ,
V_107 ) ;
break;
case V_139 :
return F_57 ( V_106 , & V_33 -> V_103 , V_114 ,
V_107 ) ;
break;
case V_140 :
return F_59 ( V_106 , & V_33 -> V_103 , V_114 ) ;
break;
case V_141 :
break;
default:
F_61 ( L_21 ) ;
}
return 0 ;
}
void F_62 ( struct V_1 * V_1 , int V_142 )
{
struct V_52 * V_53 = F_13 ( & V_1 -> V_54 ) ;
struct V_14 * V_55 ;
int V_143 = 0 ;
F_4 ( V_1 ) ;
while ( V_53 && V_143 ++ < V_142 ) {
V_55 = F_14 ( V_53 , struct V_14 , V_52 ) ;
if ( ! V_55 -> V_46 )
F_6 ( V_1 , V_55 ) ;
V_53 = F_15 ( & V_55 -> V_52 ) ;
}
}
static int F_63 ( struct V_14 * V_33 , char * V_144 ,
T_3 V_145 , struct V_1 * V_146 ,
bool V_147 , long V_148 ,
bool V_149 , T_2 V_48 )
{
T_2 V_35 , V_150 , V_37 , V_39 , V_41 , V_43 ;
T_2 V_44 ;
const char * V_151 = V_10 . V_12 ;
int V_109 ;
if ( V_10 . V_70 && ! V_33 -> V_69 )
return 0 ;
if ( V_146 ) {
V_35 = V_33 -> V_152 ? V_33 -> V_152 -> V_35 : 0 ;
V_44 = V_33 -> V_152 ? V_33 -> V_152 -> V_44 : 0 ;
V_150 = V_146 -> V_47 . V_48 ;
V_37 = V_33 -> V_152 ? V_33 -> V_152 -> V_37 : 0 ;
V_39 = V_33 -> V_152 ? V_33 -> V_152 -> V_39 : 0 ;
V_41 = V_33 -> V_152 ? V_33 -> V_152 -> V_41 : 0 ;
V_43 = V_33 -> V_152 ? V_33 -> V_152 -> V_43 : 0 ;
} else {
V_35 = V_33 -> V_35 ;
V_44 = V_33 -> V_44 ;
V_150 = V_48 ;
V_37 = V_33 -> V_37 ;
V_39 = V_33 -> V_39 ;
V_41 = V_33 -> V_41 ;
V_43 = V_33 -> V_43 ;
}
if ( V_150 ) {
if ( V_149 )
V_109 = F_64 ( V_144 , V_145 ,
V_151 ? L_22 : L_23 ,
( V_35 * 100.0 ) / V_150 ) ;
else
V_109 = F_65 ( V_144 , V_145 , V_151 ? L_22 : L_23 ,
( V_35 * 100.0 ) / V_150 ) ;
if ( V_10 . V_153 ) {
V_109 += F_64 ( V_144 + V_109 , V_145 - V_109 ,
V_151 ? L_22 : L_23 ,
( V_37 * 100.0 ) / V_150 ) ;
V_109 += F_64 ( V_144 + V_109 , V_145 - V_109 ,
V_151 ? L_22 : L_23 ,
( V_39 * 100.0 ) / V_150 ) ;
if ( V_154 ) {
V_109 += F_64 ( V_144 + V_109 ,
V_145 - V_109 ,
V_151 ? L_22 : L_23 ,
( V_41 * 100.0 ) /
V_150 ) ;
V_109 += F_64 ( V_144 + V_109 ,
V_145 - V_109 ,
V_151 ? L_22 : L_23 ,
( V_43 * 100.0 ) /
V_150 ) ;
}
}
} else
V_109 = F_65 ( V_144 , V_145 , V_151 ? L_24 V_155 : L_25 V_155 L_2 , V_35 ) ;
if ( V_10 . V_156 ) {
if ( V_151 )
V_109 += F_65 ( V_144 + V_109 , V_145 - V_109 , L_26 V_155 , * V_151 , V_44 ) ;
else
V_109 += F_65 ( V_144 + V_109 , V_145 - V_109 , L_27 V_155 , V_44 ) ;
}
if ( V_10 . V_157 ) {
if ( V_151 )
V_109 += F_65 ( V_144 + V_109 , V_145 - V_109 , L_26 V_155 , * V_151 , V_35 ) ;
else
V_109 += F_65 ( V_144 + V_109 , V_145 - V_109 , L_28 V_155 , V_35 ) ;
}
if ( V_146 ) {
char V_158 [ 32 ] ;
double V_159 = 0 , V_160 = 0 , V_161 ;
if ( V_150 > 0 )
V_159 = ( V_35 * 100.0 ) / V_150 ;
if ( V_48 > 0 )
V_160 = ( V_33 -> V_35 * 100.0 ) / V_48 ;
V_161 = V_160 - V_159 ;
if ( fabs ( V_161 ) >= 0.01 )
F_65 ( V_158 , sizeof( V_158 ) , L_29 , V_161 ) ;
else
F_65 ( V_158 , sizeof( V_158 ) , L_2 ) ;
if ( V_151 )
V_109 += F_65 ( V_144 + V_109 , V_145 - V_109 , L_30 , * V_151 , V_158 ) ;
else
V_109 += F_65 ( V_144 + V_109 , V_145 - V_109 , L_31 , V_158 ) ;
if ( V_147 ) {
if ( V_148 )
F_65 ( V_158 , sizeof( V_158 ) , L_32 , V_148 ) ;
else
F_65 ( V_158 , sizeof( V_158 ) , L_2 ) ;
if ( V_151 )
V_109 += F_65 ( V_144 + V_109 , V_145 - V_109 , L_30 , * V_151 , V_158 ) ;
else
V_109 += F_65 ( V_144 + V_109 , V_145 - V_109 , L_33 , V_158 ) ;
}
}
return V_109 ;
}
int F_66 ( struct V_14 * V_33 , char * V_144 , T_3 V_145 ,
struct V_1 * V_1 )
{
const char * V_151 = V_10 . V_12 ;
struct V_91 * V_92 ;
int V_109 = 0 ;
F_32 (se, &hist_entry__sort_list, list) {
if ( V_92 -> V_162 )
continue;
V_109 += F_65 ( V_144 + V_109 , V_145 - V_109 , L_8 , V_151 ? : L_34 ) ;
V_109 += V_92 -> V_163 ( V_33 , V_144 + V_109 , V_145 - V_109 ,
F_1 ( V_1 , V_92 -> V_164 ) ) ;
}
return V_109 ;
}
static int F_67 ( struct V_14 * V_33 , T_3 V_145 ,
struct V_1 * V_1 , struct V_1 * V_146 ,
bool V_147 , long V_148 ,
T_2 V_48 , T_6 * V_106 )
{
char V_158 [ 512 ] ;
int V_109 ;
if ( V_145 == 0 || V_145 > sizeof( V_158 ) )
V_145 = sizeof( V_158 ) ;
V_109 = F_63 ( V_33 , V_158 , V_145 , V_146 ,
V_147 , V_148 ,
true , V_48 ) ;
F_66 ( V_33 , V_158 + V_109 , V_145 - V_109 , V_1 ) ;
return fprintf ( V_106 , L_10 , V_158 ) ;
}
static T_3 F_68 ( struct V_14 * V_33 ,
struct V_1 * V_1 ,
T_2 V_48 , T_6 * V_106 )
{
int V_107 = 0 ;
if ( V_135 == V_165 ) {
struct V_91 * V_92 = F_69 ( & V_166 ,
F_70 ( * V_92 ) , V_167 ) ;
V_107 = F_1 ( V_1 , V_92 -> V_164 ) ;
V_107 -= F_7 ( V_33 -> V_21 ) ;
}
return F_60 ( V_33 , V_48 , V_107 , V_106 ) ;
}
T_3 F_71 ( struct V_1 * V_1 , struct V_1 * V_152 ,
bool V_147 , bool V_168 , int V_142 ,
int V_169 , T_6 * V_106 )
{
struct V_91 * V_92 ;
struct V_52 * V_170 ;
T_3 V_109 = 0 ;
T_2 V_48 ;
unsigned long V_171 = 1 ;
long V_148 = 0 ;
unsigned int V_172 ;
const char * V_151 = V_10 . V_12 ;
const char * V_173 = V_10 . V_11 ;
int V_174 = 0 ;
F_54 () ;
if ( ! V_168 )
goto V_175;
fprintf ( V_106 , L_35 , V_152 ? L_36 : L_37 ) ;
if ( V_10 . V_153 ) {
if ( V_151 ) {
V_109 += fprintf ( V_106 , L_38 , * V_151 ) ;
V_109 += fprintf ( V_106 , L_39 , * V_151 ) ;
if ( V_154 ) {
V_109 += fprintf ( V_106 , L_40 , * V_151 ) ;
V_109 += fprintf ( V_106 , L_41 , * V_151 ) ;
}
} else {
V_109 += fprintf ( V_106 , L_42 ) ;
V_109 += fprintf ( V_106 , L_43 ) ;
if ( V_154 ) {
V_109 += fprintf ( V_106 , L_44 ) ;
V_109 += fprintf ( V_106 , L_45 ) ;
}
}
}
if ( V_10 . V_156 ) {
if ( V_151 )
fprintf ( V_106 , L_46 , * V_151 ) ;
else
fputs ( L_47 , V_106 ) ;
}
if ( V_10 . V_157 ) {
if ( V_151 )
V_109 += fprintf ( V_106 , L_48 , * V_151 ) ;
else
V_109 += fprintf ( V_106 , L_49 ) ;
}
if ( V_152 ) {
if ( V_151 )
V_109 += fprintf ( V_106 , L_50 , * V_151 ) ;
else
V_109 += fprintf ( V_106 , L_51 ) ;
if ( V_147 ) {
if ( V_151 )
V_109 += fprintf ( V_106 , L_52 , * V_151 ) ;
else
V_109 += fprintf ( V_106 , L_53 ) ;
}
}
F_32 (se, &hist_entry__sort_list, list) {
if ( V_92 -> V_162 )
continue;
if ( V_151 ) {
fprintf ( V_106 , L_30 , * V_151 , V_92 -> V_176 ) ;
continue;
}
V_172 = strlen ( V_92 -> V_176 ) ;
if ( V_10 . V_11 ) {
if ( V_173 ) {
F_2 ( V_1 , V_92 -> V_164 ,
atoi ( V_173 ) ) ;
V_173 = strchr ( V_173 , ',' ) ;
if ( V_173 )
++ V_173 ;
}
}
if ( ! F_3 ( V_1 , V_92 -> V_164 , V_172 ) )
V_172 = F_1 ( V_1 , V_92 -> V_164 ) ;
fprintf ( V_106 , L_54 , V_172 , V_92 -> V_176 ) ;
}
fprintf ( V_106 , L_5 ) ;
if ( V_142 && ++ V_174 >= V_142 )
goto V_79;
if ( V_151 )
goto V_175;
fprintf ( V_106 , L_55 ) ;
if ( V_10 . V_153 )
fprintf ( V_106 , L_56 ) ;
if ( V_10 . V_156 )
fprintf ( V_106 , L_57 ) ;
if ( V_10 . V_157 )
fprintf ( V_106 , L_58 ) ;
if ( V_152 ) {
fprintf ( V_106 , L_57 ) ;
if ( V_147 )
fprintf ( V_106 , L_59 ) ;
}
F_32 (se, &hist_entry__sort_list, list) {
unsigned int V_108 ;
if ( V_92 -> V_162 )
continue;
fprintf ( V_106 , L_34 ) ;
V_172 = F_1 ( V_1 , V_92 -> V_164 ) ;
if ( V_172 == 0 )
V_172 = strlen ( V_92 -> V_176 ) ;
for ( V_108 = 0 ; V_108 < V_172 ; V_108 ++ )
fprintf ( V_106 , L_60 ) ;
}
fprintf ( V_106 , L_5 ) ;
if ( V_142 && ++ V_174 >= V_142 )
goto V_79;
fprintf ( V_106 , L_61 ) ;
if ( V_142 && ++ V_174 >= V_142 )
goto V_79;
V_175:
V_48 = V_1 -> V_47 . V_48 ;
for ( V_170 = F_13 ( & V_1 -> V_54 ) ; V_170 ; V_170 = F_15 ( V_170 ) ) {
struct V_14 * V_15 = F_14 ( V_170 , struct V_14 , V_52 ) ;
if ( V_15 -> V_46 )
continue;
if ( V_147 ) {
if ( V_15 -> V_152 != NULL )
V_148 = ( ( long ) V_15 -> V_152 -> V_171 -
( long ) V_171 ) ;
else
V_148 = 0 ;
++ V_171 ;
}
V_109 += F_67 ( V_15 , V_169 , V_1 , V_152 , V_147 ,
V_148 , V_48 , V_106 ) ;
if ( V_10 . V_64 )
V_109 += F_68 ( V_15 , V_1 , V_48 , V_106 ) ;
if ( V_142 && ++ V_174 >= V_142 )
goto V_79;
if ( V_15 -> V_16 . V_24 == NULL && V_177 > 1 ) {
F_72 ( & V_15 -> V_21 -> V_178 ,
V_179 , V_177 , V_106 ) ;
fprintf ( V_106 , L_62 , V_180 ) ;
}
}
V_79:
free ( V_118 ) ;
return V_109 ;
}
unsigned int F_73 ( struct V_1 * V_1 )
{
struct V_91 * V_92 ;
int V_109 = 9 ;
if ( V_10 . V_153 ) {
V_109 += 7 ;
V_109 += 6 ;
if ( V_154 ) {
V_109 += 13 ;
V_109 += 12 ;
}
}
if ( V_10 . V_156 )
V_109 += 11 ;
if ( V_10 . V_157 )
V_109 += 13 ;
F_32 (se, &hist_entry__sort_list, list)
if ( ! V_92 -> V_162 )
V_109 += 2 + F_1 ( V_1 , V_92 -> V_164 ) ;
if ( V_177 )
V_109 += 3 + V_9 / 4 ;
return V_109 ;
}
static void F_74 ( struct V_1 * V_1 , struct V_14 * V_15 ,
enum V_181 V_182 )
{
V_15 -> V_46 &= ~ ( 1 << V_182 ) ;
if ( V_15 -> V_46 )
return;
++ V_1 -> V_61 ;
if ( V_15 -> V_16 . V_183 )
V_1 -> V_61 += V_15 -> V_174 ;
V_15 -> V_184 = 0 ;
V_1 -> V_47 . V_48 += V_15 -> V_35 ;
V_1 -> V_47 . V_44 [ V_185 ] += V_15 -> V_44 ;
F_6 ( V_1 , V_15 ) ;
}
static bool F_40 ( struct V_1 * V_1 ,
struct V_14 * V_33 )
{
if ( V_1 -> V_186 != NULL &&
( V_33 -> V_16 . V_24 == NULL || V_33 -> V_16 . V_24 -> V_7 != V_1 -> V_186 ) ) {
V_33 -> V_46 |= ( 1 << V_187 ) ;
return true ;
}
return false ;
}
void F_75 ( struct V_1 * V_1 )
{
struct V_52 * V_170 ;
V_1 -> V_61 = V_1 -> V_47 . V_48 = 0 ;
V_1 -> V_47 . V_44 [ V_185 ] = 0 ;
F_4 ( V_1 ) ;
for ( V_170 = F_13 ( & V_1 -> V_54 ) ; V_170 ; V_170 = F_15 ( V_170 ) ) {
struct V_14 * V_15 = F_14 ( V_170 , struct V_14 , V_52 ) ;
if ( V_10 . V_70 && ! V_15 -> V_69 )
continue;
if ( F_40 ( V_1 , V_15 ) )
continue;
F_74 ( V_1 , V_15 , V_187 ) ;
}
}
static bool F_41 ( struct V_1 * V_1 ,
struct V_14 * V_33 )
{
if ( V_1 -> V_188 != NULL &&
V_33 -> V_21 != V_1 -> V_188 ) {
V_33 -> V_46 |= ( 1 << V_189 ) ;
return true ;
}
return false ;
}
void F_76 ( struct V_1 * V_1 )
{
struct V_52 * V_170 ;
V_1 -> V_61 = V_1 -> V_47 . V_48 = 0 ;
V_1 -> V_47 . V_44 [ V_185 ] = 0 ;
F_4 ( V_1 ) ;
for ( V_170 = F_13 ( & V_1 -> V_54 ) ; V_170 ; V_170 = F_15 ( V_170 ) ) {
struct V_14 * V_15 = F_14 ( V_170 , struct V_14 , V_52 ) ;
if ( F_41 ( V_1 , V_15 ) )
continue;
F_74 ( V_1 , V_15 , V_189 ) ;
}
}
static bool F_42 ( struct V_1 * V_1 ,
struct V_14 * V_33 )
{
if ( V_1 -> V_190 != NULL &&
( ! V_33 -> V_16 . V_17 || strstr ( V_33 -> V_16 . V_17 -> V_117 ,
V_1 -> V_190 ) == NULL ) ) {
V_33 -> V_46 |= ( 1 << V_191 ) ;
return true ;
}
return false ;
}
void F_77 ( struct V_1 * V_1 )
{
struct V_52 * V_170 ;
V_1 -> V_61 = V_1 -> V_47 . V_48 = 0 ;
V_1 -> V_47 . V_44 [ V_185 ] = 0 ;
F_4 ( V_1 ) ;
for ( V_170 = F_13 ( & V_1 -> V_54 ) ; V_170 ; V_170 = F_15 ( V_170 ) ) {
struct V_14 * V_15 = F_14 ( V_170 , struct V_14 , V_52 ) ;
if ( F_42 ( V_1 , V_15 ) )
continue;
F_74 ( V_1 , V_15 , V_191 ) ;
}
}
int F_78 ( struct V_14 * V_33 , int V_192 , T_2 V_87 )
{
return F_79 ( V_33 -> V_16 . V_17 , V_33 -> V_16 . V_24 , V_192 , V_87 ) ;
}
int F_80 ( struct V_14 * V_33 , T_3 V_193 )
{
return F_81 ( V_33 -> V_16 . V_17 , V_33 -> V_16 . V_24 , V_193 ) ;
}
void F_82 ( struct V_1 * V_1 , T_8 type )
{
++ V_1 -> V_47 . V_44 [ 0 ] ;
++ V_1 -> V_47 . V_44 [ type ] ;
}
T_3 F_83 ( struct V_1 * V_1 , T_6 * V_106 )
{
int V_108 ;
T_3 V_109 = 0 ;
for ( V_108 = 0 ; V_108 < V_194 ; ++ V_108 ) {
const char * V_117 ;
if ( V_1 -> V_47 . V_44 [ V_108 ] == 0 )
continue;
V_117 = F_84 ( V_108 ) ;
if ( ! strcmp ( V_117 , L_63 ) )
continue;
V_109 += fprintf ( V_106 , L_64 , V_117 ,
V_1 -> V_47 . V_44 [ V_108 ] ) ;
}
return V_109 ;
}
