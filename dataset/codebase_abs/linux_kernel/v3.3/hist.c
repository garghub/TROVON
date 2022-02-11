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
static void F_5 ( struct V_1 * V_1 , struct V_7 * V_8 )
{
T_1 V_5 ;
if ( V_8 -> V_9 . V_10 )
F_3 ( V_1 , V_11 , V_8 -> V_9 . V_10 -> V_12 ) ;
else {
const unsigned int V_13 = V_14 / 4 ;
if ( F_1 ( V_1 , V_15 ) < V_13 &&
! V_16 . V_17 && ! V_16 . V_18 &&
! V_16 . V_19 )
F_2 ( V_1 , V_15 ,
V_13 ) ;
}
V_5 = F_6 ( V_8 -> V_20 ) ;
if ( F_3 ( V_1 , V_21 , V_5 ) )
F_2 ( V_1 , V_22 , V_5 + 6 ) ;
if ( V_8 -> V_9 . V_23 ) {
V_5 = F_7 ( V_8 -> V_9 . V_23 -> V_24 ) ;
F_3 ( V_1 , V_15 , V_5 ) ;
}
}
static void F_8 ( struct V_7 * V_25 ,
unsigned int V_26 , T_2 V_27 )
{
switch ( V_26 ) {
case V_28 :
V_25 -> V_29 += V_27 ;
break;
case V_30 :
V_25 -> V_31 += V_27 ;
break;
case V_32 :
V_25 -> V_33 += V_27 ;
break;
case V_34 :
V_25 -> V_35 += V_27 ;
break;
default:
break;
}
}
static void F_9 ( struct V_7 * V_25 )
{
V_25 -> V_27 = ( V_25 -> V_27 * 7 ) / 8 ;
V_25 -> V_36 = ( V_25 -> V_36 * 7 ) / 8 ;
}
static bool F_10 ( struct V_1 * V_1 , struct V_7 * V_25 )
{
T_2 V_37 = V_25 -> V_27 ;
if ( V_37 == 0 )
return true ;
F_9 ( V_25 ) ;
if ( ! V_25 -> V_38 )
V_1 -> V_39 . V_40 -= V_37 - V_25 -> V_27 ;
return V_25 -> V_27 == 0 ;
}
static void F_11 ( struct V_1 * V_1 , bool V_41 ,
bool V_42 , bool V_43 )
{
struct V_44 * V_45 = F_12 ( & V_1 -> V_46 ) ;
struct V_7 * V_47 ;
while ( V_45 ) {
V_47 = F_13 ( V_45 , struct V_7 , V_44 ) ;
V_45 = F_14 ( & V_47 -> V_44 ) ;
if ( ( ( V_41 && V_47 -> V_48 == '.' ) ||
( V_42 && V_47 -> V_48 != '.' ) ||
F_10 ( V_1 , V_47 ) ) &&
! V_47 -> V_49 ) {
F_15 ( & V_47 -> V_44 , & V_1 -> V_46 ) ;
if ( V_50 || V_43 )
F_15 ( & V_47 -> V_51 , & V_1 -> V_52 ) ;
F_16 ( V_47 ) ;
-- V_1 -> V_53 ;
}
}
}
void F_17 ( struct V_1 * V_1 , bool V_41 , bool V_42 )
{
return F_11 ( V_1 , V_41 , V_42 , false ) ;
}
void F_18 ( struct V_1 * V_1 ,
bool V_41 , bool V_42 )
{
return F_11 ( V_1 , V_41 , V_42 , true ) ;
}
static struct V_7 * F_19 ( struct V_7 * V_54 )
{
T_3 V_55 = V_16 . V_56 ? sizeof( struct V_57 ) : 0 ;
struct V_7 * V_25 = malloc ( sizeof( * V_25 ) + V_55 ) ;
if ( V_25 != NULL ) {
* V_25 = * V_54 ;
V_25 -> V_36 = 1 ;
if ( V_25 -> V_9 . V_23 )
V_25 -> V_9 . V_23 -> V_58 = true ;
if ( V_16 . V_56 )
F_20 ( V_25 -> V_59 ) ;
}
return V_25 ;
}
static void F_21 ( struct V_1 * V_1 , struct V_7 * V_8 )
{
if ( ! V_8 -> V_38 ) {
F_5 ( V_1 , V_8 ) ;
++ V_1 -> V_53 ;
V_1 -> V_39 . V_40 += V_8 -> V_27 ;
}
}
static T_4 F_22 ( const struct V_60 * V_61 )
{
if ( V_16 . V_62 && V_61 == NULL )
return 1 << V_63 ;
return 0 ;
}
struct V_7 * F_23 ( struct V_1 * V_1 ,
struct V_64 * V_65 ,
struct V_60 * V_66 , T_2 V_27 )
{
struct V_44 * * V_67 ;
struct V_44 * V_61 = NULL ;
struct V_7 * V_25 ;
struct V_7 V_68 = {
. V_20 = V_65 -> V_20 ,
. V_9 = {
. V_23 = V_65 -> V_23 ,
. V_10 = V_65 -> V_10 ,
} ,
. V_69 = V_65 -> V_69 ,
. V_70 = V_65 -> V_71 ,
. V_48 = V_65 -> V_48 ,
. V_27 = V_27 ,
. V_61 = V_66 ,
. V_38 = F_22 ( V_66 ) ,
} ;
int V_72 ;
F_24 ( & V_1 -> V_73 ) ;
V_67 = & V_1 -> V_74 -> V_44 ;
while ( * V_67 != NULL ) {
V_61 = * V_67 ;
V_25 = F_13 ( V_61 , struct V_7 , V_51 ) ;
V_72 = F_25 ( & V_68 , V_25 ) ;
if ( ! V_72 ) {
V_25 -> V_27 += V_27 ;
++ V_25 -> V_36 ;
goto V_75;
}
if ( V_72 < 0 )
V_67 = & ( * V_67 ) -> V_76 ;
else
V_67 = & ( * V_67 ) -> V_77 ;
}
V_25 = F_19 ( & V_68 ) ;
if ( ! V_25 )
goto V_78;
F_26 ( & V_25 -> V_51 , V_61 , V_67 ) ;
F_27 ( & V_25 -> V_51 , V_1 -> V_74 ) ;
V_75:
F_8 ( V_25 , V_65 -> V_26 , V_27 ) ;
V_78:
F_28 ( & V_1 -> V_73 ) ;
return V_25 ;
}
T_5
F_25 ( struct V_7 * V_79 , struct V_7 * V_80 )
{
struct V_81 * V_82 ;
T_5 V_72 = 0 ;
F_29 (se, &hist_entry__sort_list, list) {
V_72 = V_82 -> V_83 ( V_79 , V_80 ) ;
if ( V_72 )
break;
}
return V_72 ;
}
T_5
F_30 ( struct V_7 * V_79 , struct V_7 * V_80 )
{
struct V_81 * V_82 ;
T_5 V_72 = 0 ;
F_29 (se, &hist_entry__sort_list, list) {
T_5 (* F_31)( struct V_7 * , struct V_7 * );
F_31 = V_82 -> V_84 ? : V_82 -> V_83 ;
V_72 = F_31 ( V_79 , V_80 ) ;
if ( V_72 )
break;
}
return V_72 ;
}
void F_16 ( struct V_7 * V_25 )
{
free ( V_25 ) ;
}
static bool F_32 ( struct V_1 * V_1 ,
struct V_85 * V_86 ,
struct V_7 * V_25 )
{
struct V_44 * * V_67 = & V_86 -> V_44 ;
struct V_44 * V_61 = NULL ;
struct V_7 * V_87 ;
T_5 V_72 ;
while ( * V_67 != NULL ) {
V_61 = * V_67 ;
V_87 = F_13 ( V_61 , struct V_7 , V_51 ) ;
V_72 = F_30 ( V_87 , V_25 ) ;
if ( ! V_72 ) {
V_87 -> V_27 += V_25 -> V_27 ;
V_87 -> V_36 += V_25 -> V_36 ;
if ( V_16 . V_56 ) {
F_33 ( & V_1 -> V_88 ) ;
F_34 ( & V_1 -> V_88 , V_87 -> V_59 ,
V_25 -> V_59 ) ;
}
F_16 ( V_25 ) ;
return false ;
}
if ( V_72 < 0 )
V_67 = & ( * V_67 ) -> V_76 ;
else
V_67 = & ( * V_67 ) -> V_77 ;
}
F_26 ( & V_25 -> V_51 , V_61 , V_67 ) ;
F_27 ( & V_25 -> V_51 , V_86 ) ;
return true ;
}
static struct V_85 * F_35 ( struct V_1 * V_1 )
{
struct V_85 * V_86 ;
F_24 ( & V_1 -> V_73 ) ;
V_86 = V_1 -> V_74 ;
if ( ++ V_1 -> V_74 > & V_1 -> V_89 [ 1 ] )
V_1 -> V_74 = & V_1 -> V_89 [ 0 ] ;
F_28 ( & V_1 -> V_73 ) ;
return V_86 ;
}
static void F_36 ( struct V_1 * V_1 , struct V_7 * V_25 )
{
F_37 ( V_1 , V_25 ) ;
F_38 ( V_1 , V_25 ) ;
}
static void F_39 ( struct V_1 * V_1 , bool V_43 )
{
struct V_85 * V_86 ;
struct V_44 * V_45 ;
struct V_7 * V_47 ;
if ( ! V_50 && ! V_43 )
return;
V_86 = F_35 ( V_1 ) ;
V_45 = F_12 ( V_86 ) ;
while ( V_45 ) {
V_47 = F_13 ( V_45 , struct V_7 , V_51 ) ;
V_45 = F_14 ( & V_47 -> V_51 ) ;
F_15 ( & V_47 -> V_51 , V_86 ) ;
if ( F_32 ( V_1 , & V_1 -> V_52 , V_47 ) ) {
F_36 ( V_1 , V_47 ) ;
}
}
}
void F_40 ( struct V_1 * V_1 )
{
return F_39 ( V_1 , false ) ;
}
void F_41 ( struct V_1 * V_1 )
{
return F_39 ( V_1 , true ) ;
}
static void F_42 ( struct V_85 * V_46 ,
struct V_7 * V_25 ,
T_2 V_90 )
{
struct V_44 * * V_67 = & V_46 -> V_44 ;
struct V_44 * V_61 = NULL ;
struct V_7 * V_87 ;
if ( V_16 . V_56 )
V_91 . V_92 ( & V_25 -> V_93 , V_25 -> V_59 ,
V_90 , & V_91 ) ;
while ( * V_67 != NULL ) {
V_61 = * V_67 ;
V_87 = F_13 ( V_61 , struct V_7 , V_44 ) ;
if ( V_25 -> V_27 > V_87 -> V_27 )
V_67 = & ( * V_67 ) -> V_76 ;
else
V_67 = & ( * V_67 ) -> V_77 ;
}
F_26 ( & V_25 -> V_44 , V_61 , V_67 ) ;
F_27 ( & V_25 -> V_44 , V_46 ) ;
}
static void F_43 ( struct V_1 * V_1 , bool V_43 )
{
struct V_85 * V_86 ;
struct V_44 * V_45 ;
struct V_7 * V_47 ;
T_2 V_90 ;
V_90 = V_1 -> V_39 . V_40 * ( V_91 . V_94 / 100 ) ;
if ( V_50 || V_43 )
V_86 = & V_1 -> V_52 ;
else
V_86 = V_1 -> V_74 ;
V_45 = F_12 ( V_86 ) ;
V_1 -> V_46 = V_95 ;
V_1 -> V_53 = 0 ;
V_1 -> V_39 . V_40 = 0 ;
F_4 ( V_1 ) ;
while ( V_45 ) {
V_47 = F_13 ( V_45 , struct V_7 , V_51 ) ;
V_45 = F_14 ( & V_47 -> V_51 ) ;
F_42 ( & V_1 -> V_46 , V_47 , V_90 ) ;
F_21 ( V_1 , V_47 ) ;
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
static T_3 F_46 ( T_6 * V_96 , int V_97 )
{
int V_98 ;
int V_99 = fprintf ( V_96 , L_1 ) ;
for ( V_98 = 0 ; V_98 < V_97 ; V_98 ++ )
V_99 += fprintf ( V_96 , L_2 ) ;
return V_99 ;
}
static T_3 F_47 ( T_6 * V_96 , int V_100 , int V_101 ,
int V_97 )
{
int V_98 ;
T_3 V_99 = F_46 ( V_96 , V_97 ) ;
for ( V_98 = 0 ; V_98 < V_100 ; V_98 ++ )
if ( V_101 & ( 1 << V_98 ) )
V_99 += fprintf ( V_96 , L_3 ) ;
else
V_99 += fprintf ( V_96 , L_4 ) ;
V_99 += fprintf ( V_96 , L_5 ) ;
return V_99 ;
}
static T_3 F_48 ( T_6 * V_96 , struct V_102 * V_103 ,
int V_100 , int V_101 , int V_27 ,
T_2 V_104 , T_2 V_105 ,
int V_97 )
{
int V_98 ;
T_3 V_99 = 0 ;
V_99 += F_46 ( V_96 , V_97 ) ;
for ( V_98 = 0 ; V_98 < V_100 ; V_98 ++ ) {
if ( V_101 & ( 1 << V_98 ) )
V_99 += fprintf ( V_96 , L_6 ) ;
else
V_99 += fprintf ( V_96 , L_2 ) ;
if ( ! V_27 && V_98 == V_100 - 1 ) {
double V_106 ;
V_106 = V_105 * 100.0 / V_104 ;
V_99 += F_49 ( V_96 , L_7 , V_106 ) ;
} else
V_99 += fprintf ( V_96 , L_8 , L_9 ) ;
}
if ( V_103 -> V_9 . V_10 )
V_99 += fprintf ( V_96 , L_10 , V_103 -> V_9 . V_10 -> V_107 ) ;
else
V_99 += fprintf ( V_96 , L_11 , ( void * ) ( long ) V_103 -> V_70 ) ;
return V_99 ;
}
static void F_50 ( void )
{
V_108 = malloc ( sizeof( * V_108 ) + 6 ) ;
if ( ! V_108 ) {
fprintf ( V_109 , L_12 ) ;
return;
}
strcpy ( V_108 -> V_107 , L_13 ) ;
V_110 . V_9 . V_10 = V_108 ;
}
static T_3 F_51 ( T_6 * V_96 , struct V_111 * V_112 ,
T_2 V_104 , int V_100 ,
int V_101 , int V_97 )
{
struct V_44 * V_113 , * V_45 ;
struct V_111 * V_114 ;
struct V_102 * V_103 ;
int V_115 = V_101 ;
T_2 V_116 ;
T_2 V_117 ;
T_3 V_99 = 0 ;
int V_98 ;
T_7 V_118 = 0 ;
if ( V_91 . V_119 == V_120 )
V_116 = V_112 -> V_121 ;
else
V_116 = V_104 ;
V_117 = V_116 ;
V_113 = F_12 ( & V_112 -> V_85 ) ;
while ( V_113 ) {
T_2 V_122 ;
V_114 = F_13 ( V_113 , struct V_111 , V_44 ) ;
V_122 = F_52 ( V_114 ) ;
V_117 -= V_122 ;
V_45 = F_14 ( V_113 ) ;
if ( ! V_45 && ( V_91 . V_119 != V_120 || ! V_117 ) )
V_115 &= ~ ( 1 << ( V_100 - 1 ) ) ;
V_99 += F_47 ( V_96 , V_100 , V_101 ,
V_97 ) ;
V_98 = 0 ;
F_29 (chain, &child->val, list) {
V_99 += F_48 ( V_96 , V_103 , V_100 ,
V_115 , V_98 ++ ,
V_116 ,
V_122 ,
V_97 ) ;
}
V_99 += F_51 ( V_96 , V_114 , V_116 ,
V_100 + 1 ,
V_115 | ( 1 << V_100 ) ,
V_97 ) ;
V_113 = V_45 ;
if ( ++ V_118 == V_91 . V_123 )
break;
}
if ( V_91 . V_119 == V_120 &&
V_117 && V_117 != V_116 ) {
if ( ! V_108 )
return V_99 ;
V_115 &= ~ ( 1 << ( V_100 - 1 ) ) ;
V_99 += F_48 ( V_96 , & V_110 , V_100 ,
V_115 , 0 , V_116 ,
V_117 , V_97 ) ;
}
return V_99 ;
}
static T_3 F_53 ( T_6 * V_96 , struct V_111 * V_112 ,
T_2 V_104 , int V_97 )
{
struct V_102 * V_103 ;
bool V_124 = false ;
int V_98 = 0 ;
int V_99 = 0 ;
T_8 V_118 = 0 ;
F_29 (chain, &self->val, list) {
if ( ! V_98 ++ && V_125 == V_126 )
continue;
if ( ! V_124 ) {
V_99 += F_46 ( V_96 , V_97 ) ;
V_99 += fprintf ( V_96 , L_14 ) ;
V_99 += F_46 ( V_96 , V_97 ) ;
V_99 += fprintf ( V_96 , L_15 ) ;
V_97 += 3 ;
V_124 = true ;
} else
V_99 += F_46 ( V_96 , V_97 ) ;
if ( V_103 -> V_9 . V_10 )
V_99 += fprintf ( V_96 , L_16 , V_103 -> V_9 . V_10 -> V_107 ) ;
else
V_99 += fprintf ( V_96 , L_17 , ( void * ) ( long ) V_103 -> V_70 ) ;
if ( ++ V_118 == V_91 . V_123 )
break;
}
V_99 += F_51 ( V_96 , V_112 , V_104 , 1 , 1 , V_97 ) ;
return V_99 ;
}
static T_3 F_54 ( T_6 * V_96 , struct V_111 * V_112 ,
T_2 V_104 )
{
struct V_102 * V_103 ;
T_3 V_99 = 0 ;
if ( ! V_112 )
return 0 ;
V_99 += F_54 ( V_96 , V_112 -> V_61 , V_104 ) ;
F_29 (chain, &self->val, list) {
if ( V_103 -> V_70 >= V_127 )
continue;
if ( V_103 -> V_9 . V_10 )
V_99 += fprintf ( V_96 , L_18 , V_103 -> V_9 . V_10 -> V_107 ) ;
else
V_99 += fprintf ( V_96 , L_19 ,
( void * ) ( long ) V_103 -> V_70 ) ;
}
return V_99 ;
}
static T_3 F_55 ( struct V_7 * V_25 ,
T_2 V_104 , int V_97 ,
T_6 * V_96 )
{
struct V_44 * V_44 ;
struct V_111 * V_103 ;
T_3 V_99 = 0 ;
T_8 V_118 = 0 ;
V_44 = F_12 ( & V_25 -> V_93 ) ;
while ( V_44 ) {
double V_106 ;
V_103 = F_13 ( V_44 , struct V_111 , V_44 ) ;
V_106 = V_103 -> V_128 * 100.0 / V_104 ;
switch ( V_91 . V_119 ) {
case V_129 :
V_99 += F_49 ( V_96 , L_20 ,
V_106 ) ;
V_99 += F_54 ( V_96 , V_103 , V_104 ) ;
break;
case V_130 :
case V_120 :
V_99 += F_53 ( V_96 , V_103 , V_104 ,
V_97 ) ;
case V_131 :
default:
break;
}
V_99 += fprintf ( V_96 , L_5 ) ;
if ( ++ V_118 == V_91 . V_123 )
break;
V_44 = F_14 ( V_44 ) ;
}
return V_99 ;
}
void F_56 ( struct V_1 * V_1 , int V_132 )
{
struct V_44 * V_45 = F_12 ( & V_1 -> V_46 ) ;
struct V_7 * V_47 ;
int V_133 = 0 ;
F_4 ( V_1 ) ;
while ( V_45 && V_133 ++ < V_132 ) {
V_47 = F_13 ( V_45 , struct V_7 , V_44 ) ;
if ( ! V_47 -> V_38 )
F_5 ( V_1 , V_47 ) ;
V_45 = F_14 ( & V_47 -> V_44 ) ;
}
}
static int F_57 ( struct V_7 * V_25 , char * V_134 ,
T_3 V_135 , struct V_1 * V_136 ,
bool V_137 , long V_138 ,
bool V_139 , T_2 V_40 )
{
T_2 V_27 , V_140 , V_29 , V_31 , V_33 , V_35 ;
T_2 V_36 ;
const char * V_141 = V_16 . V_18 ;
int V_99 ;
if ( V_16 . V_62 && ! V_25 -> V_61 )
return 0 ;
if ( V_136 ) {
V_27 = V_25 -> V_142 ? V_25 -> V_142 -> V_27 : 0 ;
V_36 = V_25 -> V_142 ? V_25 -> V_142 -> V_36 : 0 ;
V_140 = V_136 -> V_39 . V_40 ;
V_29 = V_25 -> V_142 ? V_25 -> V_142 -> V_29 : 0 ;
V_31 = V_25 -> V_142 ? V_25 -> V_142 -> V_31 : 0 ;
V_33 = V_25 -> V_142 ? V_25 -> V_142 -> V_33 : 0 ;
V_35 = V_25 -> V_142 ? V_25 -> V_142 -> V_35 : 0 ;
} else {
V_27 = V_25 -> V_27 ;
V_36 = V_25 -> V_36 ;
V_140 = V_40 ;
V_29 = V_25 -> V_29 ;
V_31 = V_25 -> V_31 ;
V_33 = V_25 -> V_33 ;
V_35 = V_25 -> V_35 ;
}
if ( V_140 ) {
if ( V_139 )
V_99 = F_58 ( V_134 , V_135 ,
V_141 ? L_21 : L_22 ,
( V_27 * 100.0 ) / V_140 ) ;
else
V_99 = F_59 ( V_134 , V_135 , V_141 ? L_21 : L_22 ,
( V_27 * 100.0 ) / V_140 ) ;
if ( V_16 . V_143 ) {
V_99 += F_58 ( V_134 + V_99 , V_135 - V_99 ,
V_141 ? L_21 : L_22 ,
( V_29 * 100.0 ) / V_140 ) ;
V_99 += F_58 ( V_134 + V_99 , V_135 - V_99 ,
V_141 ? L_21 : L_22 ,
( V_31 * 100.0 ) / V_140 ) ;
if ( V_144 ) {
V_99 += F_58 ( V_134 + V_99 ,
V_135 - V_99 ,
V_141 ? L_21 : L_22 ,
( V_33 * 100.0 ) /
V_140 ) ;
V_99 += F_58 ( V_134 + V_99 ,
V_135 - V_99 ,
V_141 ? L_21 : L_22 ,
( V_35 * 100.0 ) /
V_140 ) ;
}
}
} else
V_99 = F_59 ( V_134 , V_135 , V_141 ? L_23 V_145 : L_24 V_145 L_2 , V_27 ) ;
if ( V_16 . V_146 ) {
if ( V_141 )
V_99 += F_59 ( V_134 + V_99 , V_135 - V_99 , L_25 V_145 , * V_141 , V_36 ) ;
else
V_99 += F_59 ( V_134 + V_99 , V_135 - V_99 , L_26 V_145 , V_36 ) ;
}
if ( V_16 . V_147 ) {
if ( V_141 )
V_99 += F_59 ( V_134 + V_99 , V_135 - V_99 , L_25 V_145 , * V_141 , V_27 ) ;
else
V_99 += F_59 ( V_134 + V_99 , V_135 - V_99 , L_27 V_145 , V_27 ) ;
}
if ( V_136 ) {
char V_148 [ 32 ] ;
double V_149 = 0 , V_150 = 0 , V_151 ;
if ( V_140 > 0 )
V_149 = ( V_27 * 100.0 ) / V_140 ;
if ( V_40 > 0 )
V_150 = ( V_25 -> V_27 * 100.0 ) / V_40 ;
V_151 = V_150 - V_149 ;
if ( fabs ( V_151 ) >= 0.01 )
V_99 += F_59 ( V_148 , sizeof( V_148 ) , L_28 , V_151 ) ;
else
V_99 += F_59 ( V_148 , sizeof( V_148 ) , L_2 ) ;
if ( V_141 )
V_99 += F_59 ( V_134 + V_99 , V_135 - V_99 , L_29 , * V_141 , V_148 ) ;
else
V_99 += F_59 ( V_134 + V_99 , V_135 - V_99 , L_30 , V_148 ) ;
if ( V_137 ) {
if ( V_138 )
V_99 += F_59 ( V_148 , sizeof( V_148 ) , L_31 , V_138 ) ;
else
V_99 += F_59 ( V_148 , sizeof( V_148 ) , L_2 ) ;
if ( V_141 )
V_99 += F_59 ( V_134 + V_99 , V_135 - V_99 , L_29 , * V_141 , V_148 ) ;
else
V_99 += F_59 ( V_134 + V_99 , V_135 - V_99 , L_32 , V_148 ) ;
}
}
return V_99 ;
}
int F_60 ( struct V_7 * V_25 , char * V_134 , T_3 V_135 ,
struct V_1 * V_1 )
{
const char * V_141 = V_16 . V_18 ;
struct V_81 * V_82 ;
int V_99 = 0 ;
F_29 (se, &hist_entry__sort_list, list) {
if ( V_82 -> V_152 )
continue;
V_99 += F_59 ( V_134 + V_99 , V_135 - V_99 , L_8 , V_141 ? : L_33 ) ;
V_99 += V_82 -> V_153 ( V_25 , V_134 + V_99 , V_135 - V_99 ,
F_1 ( V_1 , V_82 -> V_154 ) ) ;
}
return V_99 ;
}
static int F_61 ( struct V_7 * V_25 , T_3 V_135 ,
struct V_1 * V_1 , struct V_1 * V_136 ,
bool V_137 , long V_138 ,
T_2 V_40 , T_6 * V_96 )
{
char V_148 [ 512 ] ;
int V_99 ;
if ( V_135 == 0 || V_135 > sizeof( V_148 ) )
V_135 = sizeof( V_148 ) ;
V_99 = F_57 ( V_25 , V_148 , V_135 , V_136 ,
V_137 , V_138 ,
true , V_40 ) ;
F_60 ( V_25 , V_148 + V_99 , V_135 - V_99 , V_1 ) ;
return fprintf ( V_96 , L_10 , V_148 ) ;
}
static T_3 F_62 ( struct V_7 * V_25 ,
struct V_1 * V_1 ,
T_2 V_40 , T_6 * V_96 )
{
int V_97 = 0 ;
if ( V_125 == V_155 ) {
struct V_81 * V_82 = F_63 ( & V_156 ,
F_64 ( * V_82 ) , V_157 ) ;
V_97 = F_1 ( V_1 , V_82 -> V_154 ) ;
V_97 -= F_6 ( V_25 -> V_20 ) ;
}
return F_55 ( V_25 , V_40 , V_97 , V_96 ) ;
}
T_3 F_65 ( struct V_1 * V_1 , struct V_1 * V_142 ,
bool V_137 , bool V_158 , int V_132 ,
int V_159 , T_6 * V_96 )
{
struct V_81 * V_82 ;
struct V_44 * V_160 ;
T_3 V_99 = 0 ;
T_2 V_40 ;
unsigned long V_161 = 1 ;
long V_138 = 0 ;
unsigned int V_162 ;
const char * V_141 = V_16 . V_18 ;
const char * V_163 = V_16 . V_17 ;
int V_164 = 0 ;
F_50 () ;
if ( ! V_158 )
goto V_165;
fprintf ( V_96 , L_34 , V_142 ? L_35 : L_36 ) ;
if ( V_16 . V_143 ) {
if ( V_141 ) {
V_99 += fprintf ( V_96 , L_37 , * V_141 ) ;
V_99 += fprintf ( V_96 , L_38 , * V_141 ) ;
if ( V_144 ) {
V_99 += fprintf ( V_96 , L_39 , * V_141 ) ;
V_99 += fprintf ( V_96 , L_40 , * V_141 ) ;
}
} else {
V_99 += fprintf ( V_96 , L_41 ) ;
V_99 += fprintf ( V_96 , L_42 ) ;
if ( V_144 ) {
V_99 += fprintf ( V_96 , L_43 ) ;
V_99 += fprintf ( V_96 , L_44 ) ;
}
}
}
if ( V_16 . V_146 ) {
if ( V_141 )
fprintf ( V_96 , L_45 , * V_141 ) ;
else
fputs ( L_46 , V_96 ) ;
}
if ( V_16 . V_147 ) {
if ( V_141 )
V_99 += fprintf ( V_96 , L_47 , * V_141 ) ;
else
V_99 += fprintf ( V_96 , L_48 ) ;
}
if ( V_142 ) {
if ( V_141 )
V_99 += fprintf ( V_96 , L_49 , * V_141 ) ;
else
V_99 += fprintf ( V_96 , L_50 ) ;
if ( V_137 ) {
if ( V_141 )
V_99 += fprintf ( V_96 , L_51 , * V_141 ) ;
else
V_99 += fprintf ( V_96 , L_52 ) ;
}
}
F_29 (se, &hist_entry__sort_list, list) {
if ( V_82 -> V_152 )
continue;
if ( V_141 ) {
fprintf ( V_96 , L_29 , * V_141 , V_82 -> V_166 ) ;
continue;
}
V_162 = strlen ( V_82 -> V_166 ) ;
if ( V_16 . V_17 ) {
if ( V_163 ) {
F_2 ( V_1 , V_82 -> V_154 ,
atoi ( V_163 ) ) ;
V_163 = strchr ( V_163 , ',' ) ;
if ( V_163 )
++ V_163 ;
}
}
if ( ! F_3 ( V_1 , V_82 -> V_154 , V_162 ) )
V_162 = F_1 ( V_1 , V_82 -> V_154 ) ;
fprintf ( V_96 , L_53 , V_162 , V_82 -> V_166 ) ;
}
fprintf ( V_96 , L_5 ) ;
if ( V_132 && ++ V_164 >= V_132 )
goto V_75;
if ( V_141 )
goto V_165;
fprintf ( V_96 , L_54 ) ;
if ( V_16 . V_143 )
fprintf ( V_96 , L_55 ) ;
if ( V_16 . V_146 )
fprintf ( V_96 , L_56 ) ;
if ( V_16 . V_147 )
fprintf ( V_96 , L_57 ) ;
if ( V_142 ) {
fprintf ( V_96 , L_56 ) ;
if ( V_137 )
fprintf ( V_96 , L_58 ) ;
}
F_29 (se, &hist_entry__sort_list, list) {
unsigned int V_98 ;
if ( V_82 -> V_152 )
continue;
fprintf ( V_96 , L_33 ) ;
V_162 = F_1 ( V_1 , V_82 -> V_154 ) ;
if ( V_162 == 0 )
V_162 = strlen ( V_82 -> V_166 ) ;
for ( V_98 = 0 ; V_98 < V_162 ; V_98 ++ )
fprintf ( V_96 , L_59 ) ;
}
fprintf ( V_96 , L_5 ) ;
if ( V_132 && ++ V_164 >= V_132 )
goto V_75;
fprintf ( V_96 , L_60 ) ;
if ( V_132 && ++ V_164 >= V_132 )
goto V_75;
V_165:
V_40 = V_1 -> V_39 . V_40 ;
for ( V_160 = F_12 ( & V_1 -> V_46 ) ; V_160 ; V_160 = F_14 ( V_160 ) ) {
struct V_7 * V_8 = F_13 ( V_160 , struct V_7 , V_44 ) ;
if ( V_8 -> V_38 )
continue;
if ( V_137 ) {
if ( V_8 -> V_142 != NULL )
V_138 = ( ( long ) V_8 -> V_142 -> V_161 -
( long ) V_161 ) ;
else
V_138 = 0 ;
++ V_161 ;
}
V_99 += F_61 ( V_8 , V_159 , V_1 , V_142 , V_137 ,
V_138 , V_40 , V_96 ) ;
if ( V_16 . V_56 )
V_99 += F_62 ( V_8 , V_1 , V_40 , V_96 ) ;
if ( V_132 && ++ V_164 >= V_132 )
goto V_75;
if ( V_8 -> V_9 . V_23 == NULL && V_167 > 1 ) {
F_66 ( & V_8 -> V_20 -> V_168 ,
V_169 , V_167 , V_96 ) ;
fprintf ( V_96 , L_61 , V_170 ) ;
}
}
V_75:
free ( V_108 ) ;
return V_99 ;
}
unsigned int F_67 ( struct V_1 * V_1 )
{
struct V_81 * V_82 ;
int V_99 = 9 ;
if ( V_16 . V_143 ) {
V_99 += 7 ;
V_99 += 6 ;
if ( V_144 ) {
V_99 += 13 ;
V_99 += 12 ;
}
}
if ( V_16 . V_146 )
V_99 += 11 ;
if ( V_16 . V_147 )
V_99 += 13 ;
F_29 (se, &hist_entry__sort_list, list)
if ( ! V_82 -> V_152 )
V_99 += 2 + F_1 ( V_1 , V_82 -> V_154 ) ;
if ( V_167 )
V_99 += 3 + V_14 / 4 ;
return V_99 ;
}
static void F_68 ( struct V_1 * V_1 , struct V_7 * V_8 ,
enum V_171 V_172 )
{
V_8 -> V_38 &= ~ ( 1 << V_172 ) ;
if ( V_8 -> V_38 )
return;
++ V_1 -> V_53 ;
if ( V_8 -> V_9 . V_173 )
V_1 -> V_53 += V_8 -> V_164 ;
V_8 -> V_174 = 0 ;
V_1 -> V_39 . V_40 += V_8 -> V_27 ;
V_1 -> V_39 . V_36 [ V_175 ] += V_8 -> V_36 ;
F_5 ( V_1 , V_8 ) ;
}
static bool F_37 ( struct V_1 * V_1 ,
struct V_7 * V_25 )
{
if ( V_1 -> V_176 != NULL &&
( V_25 -> V_9 . V_23 == NULL || V_25 -> V_9 . V_23 -> V_24 != V_1 -> V_176 ) ) {
V_25 -> V_38 |= ( 1 << V_177 ) ;
return true ;
}
return false ;
}
void F_69 ( struct V_1 * V_1 )
{
struct V_44 * V_160 ;
V_1 -> V_53 = V_1 -> V_39 . V_40 = 0 ;
V_1 -> V_39 . V_36 [ V_175 ] = 0 ;
F_4 ( V_1 ) ;
for ( V_160 = F_12 ( & V_1 -> V_46 ) ; V_160 ; V_160 = F_14 ( V_160 ) ) {
struct V_7 * V_8 = F_13 ( V_160 , struct V_7 , V_44 ) ;
if ( V_16 . V_62 && ! V_8 -> V_61 )
continue;
if ( F_37 ( V_1 , V_8 ) )
continue;
F_68 ( V_1 , V_8 , V_177 ) ;
}
}
static bool F_38 ( struct V_1 * V_1 ,
struct V_7 * V_25 )
{
if ( V_1 -> V_178 != NULL &&
V_25 -> V_20 != V_1 -> V_178 ) {
V_25 -> V_38 |= ( 1 << V_179 ) ;
return true ;
}
return false ;
}
void F_70 ( struct V_1 * V_1 )
{
struct V_44 * V_160 ;
V_1 -> V_53 = V_1 -> V_39 . V_40 = 0 ;
V_1 -> V_39 . V_36 [ V_175 ] = 0 ;
F_4 ( V_1 ) ;
for ( V_160 = F_12 ( & V_1 -> V_46 ) ; V_160 ; V_160 = F_14 ( V_160 ) ) {
struct V_7 * V_8 = F_13 ( V_160 , struct V_7 , V_44 ) ;
if ( F_38 ( V_1 , V_8 ) )
continue;
F_68 ( V_1 , V_8 , V_179 ) ;
}
}
int F_71 ( struct V_7 * V_25 , int V_180 , T_2 V_70 )
{
return F_72 ( V_25 -> V_9 . V_10 , V_25 -> V_9 . V_23 , V_180 , V_70 ) ;
}
int F_73 ( struct V_7 * V_25 , T_3 V_181 )
{
return F_74 ( V_25 -> V_9 . V_10 , V_25 -> V_9 . V_23 , V_181 ) ;
}
void F_75 ( struct V_1 * V_1 , T_8 type )
{
++ V_1 -> V_39 . V_36 [ 0 ] ;
++ V_1 -> V_39 . V_36 [ type ] ;
}
T_3 F_76 ( struct V_1 * V_1 , T_6 * V_96 )
{
int V_98 ;
T_3 V_99 = 0 ;
for ( V_98 = 0 ; V_98 < V_182 ; ++ V_98 ) {
const char * V_107 ;
if ( V_1 -> V_39 . V_36 [ V_98 ] == 0 )
continue;
V_107 = F_77 ( V_98 ) ;
if ( ! strcmp ( V_107 , L_62 ) )
continue;
V_99 += fprintf ( V_96 , L_63 , V_107 ,
V_1 -> V_39 . V_36 [ V_98 ] ) ;
}
return V_99 ;
}
