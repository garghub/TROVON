T_1 F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
return V_2 -> V_5 [ V_4 ] ;
}
void F_2 ( struct V_1 * V_2 , enum V_3 V_4 , T_1 V_6 )
{
V_2 -> V_5 [ V_4 ] = V_6 ;
}
bool F_3 ( struct V_1 * V_2 , enum V_3 V_4 , T_1 V_6 )
{
if ( V_6 > F_1 ( V_2 , V_4 ) ) {
F_2 ( V_2 , V_4 , V_6 ) ;
return true ;
}
return false ;
}
static void F_4 ( struct V_1 * V_2 )
{
enum V_3 V_4 ;
for ( V_4 = 0 ; V_4 < V_7 ; ++ V_4 )
F_2 ( V_2 , V_4 , 0 ) ;
}
static void F_5 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
T_1 V_6 ;
if ( V_9 -> V_10 . V_11 )
F_3 ( V_2 , V_12 , V_9 -> V_10 . V_11 -> V_13 ) ;
else {
const unsigned int V_14 = V_15 / 4 ;
if ( F_1 ( V_2 , V_16 ) < V_14 &&
! V_17 . V_18 && ! V_17 . V_19 &&
! V_17 . V_20 )
F_2 ( V_2 , V_16 ,
V_14 ) ;
}
V_6 = F_6 ( V_9 -> V_21 ) ;
if ( F_3 ( V_2 , V_22 , V_6 ) )
F_2 ( V_2 , V_23 , V_6 + 6 ) ;
if ( V_9 -> V_10 . V_24 ) {
V_6 = F_7 ( V_9 -> V_10 . V_24 -> V_25 ) ;
F_3 ( V_2 , V_16 , V_6 ) ;
}
}
static void F_8 ( struct V_8 * V_2 ,
unsigned int V_26 , T_2 V_27 )
{
switch ( V_26 ) {
case V_28 :
V_2 -> V_29 += V_27 ;
break;
case V_30 :
V_2 -> V_31 += V_27 ;
break;
case V_32 :
V_2 -> V_33 += V_27 ;
break;
case V_34 :
V_2 -> V_35 += V_27 ;
break;
default:
break;
}
}
static struct V_8 * F_9 ( struct V_8 * V_36 )
{
T_3 V_37 = V_17 . V_38 ? sizeof( struct V_39 ) : 0 ;
struct V_8 * V_2 = malloc ( sizeof( * V_2 ) + V_37 ) ;
if ( V_2 != NULL ) {
* V_2 = * V_36 ;
V_2 -> V_40 = 1 ;
if ( V_2 -> V_10 . V_24 )
V_2 -> V_10 . V_24 -> V_41 = true ;
if ( V_17 . V_38 )
F_10 ( V_2 -> V_42 ) ;
}
return V_2 ;
}
static void F_11 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
if ( ! V_9 -> V_43 ) {
F_5 ( V_2 , V_9 ) ;
++ V_2 -> V_44 ;
}
}
static T_4 F_12 ( const struct V_45 * V_46 )
{
if ( V_17 . V_47 && V_46 == NULL )
return 1 << V_48 ;
return 0 ;
}
struct V_8 * F_13 ( struct V_1 * V_2 ,
struct V_49 * V_50 ,
struct V_45 * V_51 , T_2 V_27 )
{
struct V_52 * * V_53 = & V_2 -> V_54 . V_52 ;
struct V_52 * V_46 = NULL ;
struct V_8 * V_55 ;
struct V_8 V_56 = {
. V_21 = V_50 -> V_21 ,
. V_10 = {
. V_24 = V_50 -> V_24 ,
. V_11 = V_50 -> V_11 ,
} ,
. V_57 = V_50 -> V_57 ,
. V_58 = V_50 -> V_59 ,
. V_60 = V_50 -> V_60 ,
. V_27 = V_27 ,
. V_46 = V_51 ,
. V_43 = F_12 ( V_51 ) ,
} ;
int V_61 ;
while ( * V_53 != NULL ) {
V_46 = * V_53 ;
V_55 = F_14 ( V_46 , struct V_8 , V_52 ) ;
V_61 = F_15 ( & V_56 , V_55 ) ;
if ( ! V_61 ) {
V_55 -> V_27 += V_27 ;
++ V_55 -> V_40 ;
goto V_62;
}
if ( V_61 < 0 )
V_53 = & ( * V_53 ) -> V_63 ;
else
V_53 = & ( * V_53 ) -> V_64 ;
}
V_55 = F_9 ( & V_56 ) ;
if ( ! V_55 )
return NULL ;
F_16 ( & V_55 -> V_52 , V_46 , V_53 ) ;
F_17 ( & V_55 -> V_52 , & V_2 -> V_54 ) ;
F_11 ( V_2 , V_55 ) ;
V_62:
F_8 ( V_55 , V_50 -> V_26 , V_27 ) ;
return V_55 ;
}
T_5
F_15 ( struct V_8 * V_65 , struct V_8 * V_66 )
{
struct V_67 * V_68 ;
T_5 V_61 = 0 ;
F_18 (se, &hist_entry__sort_list, list) {
V_61 = V_68 -> V_69 ( V_65 , V_66 ) ;
if ( V_61 )
break;
}
return V_61 ;
}
T_5
F_19 ( struct V_8 * V_65 , struct V_8 * V_66 )
{
struct V_67 * V_68 ;
T_5 V_61 = 0 ;
F_18 (se, &hist_entry__sort_list, list) {
T_5 (* F_20)( struct V_8 * , struct V_8 * );
F_20 = V_68 -> V_70 ? : V_68 -> V_69 ;
V_61 = F_20 ( V_65 , V_66 ) ;
if ( V_61 )
break;
}
return V_61 ;
}
void F_21 ( struct V_8 * V_55 )
{
free ( V_55 ) ;
}
static bool F_22 ( struct V_1 * V_2 ,
struct V_71 * V_72 ,
struct V_8 * V_55 )
{
struct V_52 * * V_53 = & V_72 -> V_52 ;
struct V_52 * V_46 = NULL ;
struct V_8 * V_73 ;
T_5 V_61 ;
while ( * V_53 != NULL ) {
V_46 = * V_53 ;
V_73 = F_14 ( V_46 , struct V_8 , V_52 ) ;
V_61 = F_19 ( V_73 , V_55 ) ;
if ( ! V_61 ) {
V_73 -> V_27 += V_55 -> V_27 ;
if ( V_17 . V_38 ) {
F_23 ( & V_2 -> V_74 ) ;
F_24 ( & V_2 -> V_74 , V_73 -> V_42 ,
V_55 -> V_42 ) ;
}
F_21 ( V_55 ) ;
return false ;
}
if ( V_61 < 0 )
V_53 = & ( * V_53 ) -> V_63 ;
else
V_53 = & ( * V_53 ) -> V_64 ;
}
F_16 ( & V_55 -> V_52 , V_46 , V_53 ) ;
F_17 ( & V_55 -> V_52 , V_72 ) ;
return true ;
}
void F_25 ( struct V_1 * V_2 )
{
struct V_71 V_75 ;
struct V_52 * V_76 ;
struct V_8 * V_77 ;
if ( ! V_78 )
return;
V_75 = V_79 ;
V_76 = F_26 ( & V_2 -> V_54 ) ;
V_2 -> V_44 = 0 ;
F_4 ( V_2 ) ;
while ( V_76 ) {
V_77 = F_14 ( V_76 , struct V_8 , V_52 ) ;
V_76 = F_27 ( & V_77 -> V_52 ) ;
F_28 ( & V_77 -> V_52 , & V_2 -> V_54 ) ;
if ( F_22 ( V_2 , & V_75 , V_77 ) )
F_11 ( V_2 , V_77 ) ;
}
V_2 -> V_54 = V_75 ;
}
static void F_29 ( struct V_71 * V_54 ,
struct V_8 * V_55 ,
T_2 V_80 )
{
struct V_52 * * V_53 = & V_54 -> V_52 ;
struct V_52 * V_46 = NULL ;
struct V_8 * V_73 ;
if ( V_17 . V_38 )
V_81 . V_82 ( & V_55 -> V_83 , V_55 -> V_42 ,
V_80 , & V_81 ) ;
while ( * V_53 != NULL ) {
V_46 = * V_53 ;
V_73 = F_14 ( V_46 , struct V_8 , V_52 ) ;
if ( V_55 -> V_27 > V_73 -> V_27 )
V_53 = & ( * V_53 ) -> V_63 ;
else
V_53 = & ( * V_53 ) -> V_64 ;
}
F_16 ( & V_55 -> V_52 , V_46 , V_53 ) ;
F_17 ( & V_55 -> V_52 , V_54 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_71 V_75 ;
struct V_52 * V_76 ;
struct V_8 * V_77 ;
T_2 V_80 ;
V_80 = V_2 -> V_84 . V_85 * ( V_81 . V_86 / 100 ) ;
V_75 = V_79 ;
V_76 = F_26 ( & V_2 -> V_54 ) ;
V_2 -> V_44 = 0 ;
F_4 ( V_2 ) ;
while ( V_76 ) {
V_77 = F_14 ( V_76 , struct V_8 , V_52 ) ;
V_76 = F_27 ( & V_77 -> V_52 ) ;
F_28 ( & V_77 -> V_52 , & V_2 -> V_54 ) ;
F_29 ( & V_75 , V_77 , V_80 ) ;
F_11 ( V_2 , V_77 ) ;
}
V_2 -> V_54 = V_75 ;
}
static T_3 F_31 ( T_6 * V_87 , int V_88 )
{
int V_89 ;
int V_90 = fprintf ( V_87 , L_1 ) ;
for ( V_89 = 0 ; V_89 < V_88 ; V_89 ++ )
V_90 += fprintf ( V_87 , L_2 ) ;
return V_90 ;
}
static T_3 F_32 ( T_6 * V_87 , int V_91 , int V_92 ,
int V_88 )
{
int V_89 ;
T_3 V_90 = F_31 ( V_87 , V_88 ) ;
for ( V_89 = 0 ; V_89 < V_91 ; V_89 ++ )
if ( V_92 & ( 1 << V_89 ) )
V_90 += fprintf ( V_87 , L_3 ) ;
else
V_90 += fprintf ( V_87 , L_4 ) ;
V_90 += fprintf ( V_87 , L_5 ) ;
return V_90 ;
}
static T_3 F_33 ( T_6 * V_87 , struct V_93 * V_94 ,
int V_91 , int V_92 , int V_27 ,
T_2 V_95 , T_2 V_96 ,
int V_88 )
{
int V_89 ;
T_3 V_90 = 0 ;
V_90 += F_31 ( V_87 , V_88 ) ;
for ( V_89 = 0 ; V_89 < V_91 ; V_89 ++ ) {
if ( V_92 & ( 1 << V_89 ) )
V_90 += fprintf ( V_87 , L_6 ) ;
else
V_90 += fprintf ( V_87 , L_2 ) ;
if ( ! V_27 && V_89 == V_91 - 1 ) {
double V_97 ;
V_97 = V_96 * 100.0 / V_95 ;
V_90 += F_34 ( V_87 , L_7 , V_97 ) ;
} else
V_90 += fprintf ( V_87 , L_8 , L_9 ) ;
}
if ( V_94 -> V_10 . V_11 )
V_90 += fprintf ( V_87 , L_10 , V_94 -> V_10 . V_11 -> V_98 ) ;
else
V_90 += fprintf ( V_87 , L_11 , ( void * ) ( long ) V_94 -> V_58 ) ;
return V_90 ;
}
static void F_35 ( void )
{
V_99 = malloc ( sizeof( * V_99 ) + 6 ) ;
if ( ! V_99 ) {
fprintf ( V_100 , L_12 ) ;
return;
}
strcpy ( V_99 -> V_98 , L_13 ) ;
V_101 . V_10 . V_11 = V_99 ;
}
static T_3 F_36 ( T_6 * V_87 , struct V_102 * V_2 ,
T_2 V_95 , int V_91 ,
int V_92 , int V_88 )
{
struct V_52 * V_103 , * V_76 ;
struct V_102 * V_104 ;
struct V_93 * V_94 ;
int V_105 = V_92 ;
T_2 V_106 ;
T_2 V_107 ;
T_3 V_90 = 0 ;
int V_89 ;
T_7 V_108 = 0 ;
if ( V_81 . V_109 == V_110 )
V_106 = V_2 -> V_111 ;
else
V_106 = V_95 ;
V_107 = V_106 ;
V_103 = F_26 ( & V_2 -> V_71 ) ;
while ( V_103 ) {
T_2 V_112 ;
V_104 = F_14 ( V_103 , struct V_102 , V_52 ) ;
V_112 = F_37 ( V_104 ) ;
V_107 -= V_112 ;
V_76 = F_27 ( V_103 ) ;
if ( ! V_76 && ( V_81 . V_109 != V_110 || ! V_107 ) )
V_105 &= ~ ( 1 << ( V_91 - 1 ) ) ;
V_90 += F_32 ( V_87 , V_91 , V_92 ,
V_88 ) ;
V_89 = 0 ;
F_18 (chain, &child->val, list) {
V_90 += F_33 ( V_87 , V_94 , V_91 ,
V_105 , V_89 ++ ,
V_106 ,
V_112 ,
V_88 ) ;
}
V_90 += F_36 ( V_87 , V_104 , V_106 ,
V_91 + 1 ,
V_105 | ( 1 << V_91 ) ,
V_88 ) ;
V_103 = V_76 ;
if ( ++ V_108 == V_81 . V_113 )
break;
}
if ( V_81 . V_109 == V_110 &&
V_107 && V_107 != V_106 ) {
if ( ! V_99 )
return V_90 ;
V_105 &= ~ ( 1 << ( V_91 - 1 ) ) ;
V_90 += F_33 ( V_87 , & V_101 , V_91 ,
V_105 , 0 , V_106 ,
V_107 , V_88 ) ;
}
return V_90 ;
}
static T_3 F_38 ( T_6 * V_87 , struct V_102 * V_2 ,
T_2 V_95 , int V_88 )
{
struct V_93 * V_94 ;
bool V_114 = false ;
int V_89 = 0 ;
int V_90 = 0 ;
T_8 V_108 = 0 ;
F_18 (chain, &self->val, list) {
if ( ! V_89 ++ && V_115 == V_116 )
continue;
if ( ! V_114 ) {
V_90 += F_31 ( V_87 , V_88 ) ;
V_90 += fprintf ( V_87 , L_14 ) ;
V_90 += F_31 ( V_87 , V_88 ) ;
V_90 += fprintf ( V_87 , L_15 ) ;
V_88 += 3 ;
V_114 = true ;
} else
V_90 += F_31 ( V_87 , V_88 ) ;
if ( V_94 -> V_10 . V_11 )
V_90 += fprintf ( V_87 , L_16 , V_94 -> V_10 . V_11 -> V_98 ) ;
else
V_90 += fprintf ( V_87 , L_17 , ( void * ) ( long ) V_94 -> V_58 ) ;
if ( ++ V_108 == V_81 . V_113 )
break;
}
V_90 += F_36 ( V_87 , V_2 , V_95 , 1 , 1 , V_88 ) ;
return V_90 ;
}
static T_3 F_39 ( T_6 * V_87 , struct V_102 * V_2 ,
T_2 V_95 )
{
struct V_93 * V_94 ;
T_3 V_90 = 0 ;
if ( ! V_2 )
return 0 ;
V_90 += F_39 ( V_87 , V_2 -> V_46 , V_95 ) ;
F_18 (chain, &self->val, list) {
if ( V_94 -> V_58 >= V_117 )
continue;
if ( V_94 -> V_10 . V_11 )
V_90 += fprintf ( V_87 , L_18 , V_94 -> V_10 . V_11 -> V_98 ) ;
else
V_90 += fprintf ( V_87 , L_19 ,
( void * ) ( long ) V_94 -> V_58 ) ;
}
return V_90 ;
}
static T_3 F_40 ( T_6 * V_87 , struct V_8 * V_2 ,
T_2 V_95 , int V_88 )
{
struct V_52 * V_52 ;
struct V_102 * V_94 ;
T_3 V_90 = 0 ;
T_8 V_108 = 0 ;
V_52 = F_26 ( & V_2 -> V_83 ) ;
while ( V_52 ) {
double V_97 ;
V_94 = F_14 ( V_52 , struct V_102 , V_52 ) ;
V_97 = V_94 -> V_118 * 100.0 / V_95 ;
switch ( V_81 . V_109 ) {
case V_119 :
V_90 += F_34 ( V_87 , L_20 ,
V_97 ) ;
V_90 += F_39 ( V_87 , V_94 , V_95 ) ;
break;
case V_120 :
case V_110 :
V_90 += F_38 ( V_87 , V_94 , V_95 ,
V_88 ) ;
case V_121 :
default:
break;
}
V_90 += fprintf ( V_87 , L_5 ) ;
if ( ++ V_108 == V_81 . V_113 )
break;
V_52 = F_27 ( V_52 ) ;
}
return V_90 ;
}
int F_41 ( struct V_8 * V_2 , char * V_122 , T_3 V_123 ,
struct V_1 * V_1 , struct V_1 * V_124 ,
bool V_125 , long V_126 ,
bool V_127 , T_2 V_128 )
{
struct V_67 * V_68 ;
T_2 V_27 , V_129 , V_29 , V_31 , V_33 , V_35 ;
T_2 V_40 ;
const char * V_130 = V_17 . V_19 ;
int V_90 ;
if ( V_17 . V_47 && ! V_2 -> V_46 )
return 0 ;
if ( V_124 ) {
V_27 = V_2 -> V_131 ? V_2 -> V_131 -> V_27 : 0 ;
V_40 = V_2 -> V_131 ? V_2 -> V_131 -> V_40 : 0 ;
V_129 = V_124 -> V_84 . V_85 ;
V_29 = V_2 -> V_131 ? V_2 -> V_131 -> V_29 : 0 ;
V_31 = V_2 -> V_131 ? V_2 -> V_131 -> V_31 : 0 ;
V_33 = V_2 -> V_131 ? V_2 -> V_131 -> V_33 : 0 ;
V_35 = V_2 -> V_131 ? V_2 -> V_131 -> V_35 : 0 ;
} else {
V_27 = V_2 -> V_27 ;
V_40 = V_2 -> V_40 ;
V_129 = V_128 ;
V_29 = V_2 -> V_29 ;
V_31 = V_2 -> V_31 ;
V_33 = V_2 -> V_33 ;
V_35 = V_2 -> V_35 ;
}
if ( V_129 ) {
if ( V_127 )
V_90 = F_42 ( V_122 , V_123 ,
V_130 ? L_21 : L_22 ,
( V_27 * 100.0 ) / V_129 ) ;
else
V_90 = snprintf ( V_122 , V_123 , V_130 ? L_21 : L_22 ,
( V_27 * 100.0 ) / V_129 ) ;
if ( V_17 . V_132 ) {
V_90 += F_42 ( V_122 + V_90 , V_123 - V_90 ,
V_130 ? L_21 : L_22 ,
( V_29 * 100.0 ) / V_129 ) ;
V_90 += F_42 ( V_122 + V_90 , V_123 - V_90 ,
V_130 ? L_21 : L_22 ,
( V_31 * 100.0 ) / V_129 ) ;
if ( V_133 ) {
V_90 += F_42 ( V_122 + V_90 ,
V_123 - V_90 ,
V_130 ? L_21 : L_22 ,
( V_33 * 100.0 ) /
V_129 ) ;
V_90 += F_42 ( V_122 + V_90 ,
V_123 - V_90 ,
V_130 ? L_21 : L_22 ,
( V_35 * 100.0 ) /
V_129 ) ;
}
}
} else
V_90 = snprintf ( V_122 , V_123 , V_130 ? L_23 V_134 : L_24 V_134 L_2 , V_27 ) ;
if ( V_17 . V_135 ) {
if ( V_130 )
V_90 += snprintf ( V_122 + V_90 , V_123 - V_90 , L_25 V_134 , * V_130 , V_40 ) ;
else
V_90 += snprintf ( V_122 + V_90 , V_123 - V_90 , L_26 V_134 , V_40 ) ;
}
if ( V_124 ) {
char V_136 [ 32 ] ;
double V_137 = 0 , V_138 = 0 , V_139 ;
if ( V_129 > 0 )
V_137 = ( V_27 * 100.0 ) / V_129 ;
if ( V_128 > 0 )
V_138 = ( V_2 -> V_27 * 100.0 ) / V_128 ;
V_139 = V_138 - V_137 ;
if ( fabs ( V_139 ) >= 0.01 )
snprintf ( V_136 , sizeof( V_136 ) , L_27 , V_139 ) ;
else
snprintf ( V_136 , sizeof( V_136 ) , L_2 ) ;
if ( V_130 )
V_90 += snprintf ( V_122 + V_90 , V_123 - V_90 , L_28 , * V_130 , V_136 ) ;
else
V_90 += snprintf ( V_122 + V_90 , V_123 - V_90 , L_29 , V_136 ) ;
if ( V_125 ) {
if ( V_126 )
snprintf ( V_136 , sizeof( V_136 ) , L_30 , V_126 ) ;
else
snprintf ( V_136 , sizeof( V_136 ) , L_2 ) ;
if ( V_130 )
V_90 += snprintf ( V_122 + V_90 , V_123 - V_90 , L_28 , * V_130 , V_136 ) ;
else
V_90 += snprintf ( V_122 + V_90 , V_123 - V_90 , L_31 , V_136 ) ;
}
}
F_18 (se, &hist_entry__sort_list, list) {
if ( V_68 -> V_140 )
continue;
V_90 += snprintf ( V_122 + V_90 , V_123 - V_90 , L_8 , V_130 ? : L_32 ) ;
V_90 += V_68 -> V_141 ( V_2 , V_122 + V_90 , V_123 - V_90 ,
F_1 ( V_1 , V_68 -> V_142 ) ) ;
}
return V_90 ;
}
int F_43 ( struct V_8 * V_2 , struct V_1 * V_1 ,
struct V_1 * V_124 , bool V_125 ,
long V_126 , T_6 * V_87 , T_2 V_128 )
{
char V_136 [ 512 ] ;
F_41 ( V_2 , V_136 , sizeof( V_136 ) , V_1 , V_124 ,
V_125 , V_126 ,
true , V_128 ) ;
return fprintf ( V_87 , L_10 , V_136 ) ;
}
static T_3 F_44 ( struct V_8 * V_2 ,
struct V_1 * V_1 , T_6 * V_87 ,
T_2 V_128 )
{
int V_88 = 0 ;
if ( V_115 == V_143 ) {
struct V_67 * V_68 = F_45 ( & V_144 ,
F_46 ( * V_68 ) , V_145 ) ;
V_88 = F_1 ( V_1 , V_68 -> V_142 ) ;
V_88 -= F_6 ( V_2 -> V_21 ) ;
}
return F_40 ( V_87 , V_2 , V_128 ,
V_88 ) ;
}
T_3 F_47 ( struct V_1 * V_2 , struct V_1 * V_131 ,
bool V_125 , T_6 * V_87 )
{
struct V_67 * V_68 ;
struct V_52 * V_146 ;
T_3 V_90 = 0 ;
unsigned long V_147 = 1 ;
long V_126 = 0 ;
unsigned int V_148 ;
const char * V_130 = V_17 . V_19 ;
const char * V_149 = V_17 . V_18 ;
F_35 () ;
fprintf ( V_87 , L_33 , V_131 ? L_34 : L_35 ) ;
if ( V_17 . V_135 ) {
if ( V_130 )
fprintf ( V_87 , L_36 , * V_130 ) ;
else
fputs ( L_37 , V_87 ) ;
}
if ( V_17 . V_132 ) {
if ( V_130 ) {
V_90 += fprintf ( V_87 , L_38 , * V_130 ) ;
V_90 += fprintf ( V_87 , L_39 , * V_130 ) ;
if ( V_133 ) {
V_90 += fprintf ( V_87 , L_40 , * V_130 ) ;
V_90 += fprintf ( V_87 , L_41 , * V_130 ) ;
}
} else {
V_90 += fprintf ( V_87 , L_42 ) ;
V_90 += fprintf ( V_87 , L_43 ) ;
if ( V_133 ) {
V_90 += fprintf ( V_87 , L_44 ) ;
V_90 += fprintf ( V_87 , L_45 ) ;
}
}
}
if ( V_131 ) {
if ( V_130 )
V_90 += fprintf ( V_87 , L_46 , * V_130 ) ;
else
V_90 += fprintf ( V_87 , L_47 ) ;
if ( V_125 ) {
if ( V_130 )
V_90 += fprintf ( V_87 , L_48 , * V_130 ) ;
else
V_90 += fprintf ( V_87 , L_49 ) ;
}
}
F_18 (se, &hist_entry__sort_list, list) {
if ( V_68 -> V_140 )
continue;
if ( V_130 ) {
fprintf ( V_87 , L_28 , * V_130 , V_68 -> V_150 ) ;
continue;
}
V_148 = strlen ( V_68 -> V_150 ) ;
if ( V_17 . V_18 ) {
if ( V_149 ) {
F_2 ( V_2 , V_68 -> V_142 ,
atoi ( V_149 ) ) ;
V_149 = strchr ( V_149 , ',' ) ;
if ( V_149 )
++ V_149 ;
}
}
if ( ! F_3 ( V_2 , V_68 -> V_142 , V_148 ) )
V_148 = F_1 ( V_2 , V_68 -> V_142 ) ;
fprintf ( V_87 , L_50 , V_148 , V_68 -> V_150 ) ;
}
fprintf ( V_87 , L_5 ) ;
if ( V_130 )
goto V_151;
fprintf ( V_87 , L_51 ) ;
if ( V_17 . V_135 )
fprintf ( V_87 , L_52 ) ;
if ( V_131 ) {
fprintf ( V_87 , L_52 ) ;
if ( V_125 )
fprintf ( V_87 , L_53 ) ;
}
F_18 (se, &hist_entry__sort_list, list) {
unsigned int V_89 ;
if ( V_68 -> V_140 )
continue;
fprintf ( V_87 , L_32 ) ;
V_148 = F_1 ( V_2 , V_68 -> V_142 ) ;
if ( V_148 == 0 )
V_148 = strlen ( V_68 -> V_150 ) ;
for ( V_89 = 0 ; V_89 < V_148 ; V_89 ++ )
fprintf ( V_87 , L_54 ) ;
}
fprintf ( V_87 , L_55 ) ;
V_151:
for ( V_146 = F_26 ( & V_2 -> V_54 ) ; V_146 ; V_146 = F_27 ( V_146 ) ) {
struct V_8 * V_9 = F_14 ( V_146 , struct V_8 , V_52 ) ;
if ( V_125 ) {
if ( V_9 -> V_131 != NULL )
V_126 = ( ( long ) V_9 -> V_131 -> V_147 -
( long ) V_147 ) ;
else
V_126 = 0 ;
++ V_147 ;
}
V_90 += F_43 ( V_9 , V_2 , V_131 , V_125 ,
V_126 , V_87 , V_2 -> V_84 . V_85 ) ;
if ( V_17 . V_38 )
V_90 += F_44 ( V_9 , V_2 , V_87 ,
V_2 -> V_84 . V_85 ) ;
if ( V_9 -> V_10 . V_24 == NULL && V_152 > 1 ) {
F_48 ( & V_9 -> V_21 -> V_153 ,
V_154 , V_152 , V_87 ) ;
fprintf ( V_87 , L_56 , V_155 ) ;
}
}
free ( V_99 ) ;
return V_90 ;
}
unsigned int F_49 ( struct V_1 * V_2 )
{
struct V_67 * V_68 ;
int V_90 = 9 ;
if ( V_17 . V_132 ) {
V_90 += 7 ;
V_90 += 6 ;
if ( V_133 ) {
V_90 += 13 ;
V_90 += 12 ;
}
}
if ( V_17 . V_135 )
V_90 += 11 ;
F_18 (se, &hist_entry__sort_list, list)
if ( ! V_68 -> V_140 )
V_90 += 2 + F_1 ( V_2 , V_68 -> V_142 ) ;
if ( V_152 )
V_90 += 3 + V_15 / 4 ;
return V_90 ;
}
static void F_50 ( struct V_1 * V_2 , struct V_8 * V_9 ,
enum V_156 V_157 )
{
V_9 -> V_43 &= ~ ( 1 << V_157 ) ;
if ( V_9 -> V_43 )
return;
++ V_2 -> V_44 ;
if ( V_9 -> V_10 . V_158 )
V_2 -> V_44 += V_9 -> V_159 ;
V_9 -> V_160 = 0 ;
V_2 -> V_84 . V_85 += V_9 -> V_27 ;
V_2 -> V_84 . V_40 [ V_161 ] += V_9 -> V_40 ;
F_5 ( V_2 , V_9 ) ;
}
void F_51 ( struct V_1 * V_2 , const struct V_25 * V_25 )
{
struct V_52 * V_146 ;
V_2 -> V_44 = V_2 -> V_84 . V_85 = 0 ;
V_2 -> V_84 . V_40 [ V_161 ] = 0 ;
F_4 ( V_2 ) ;
for ( V_146 = F_26 ( & V_2 -> V_54 ) ; V_146 ; V_146 = F_27 ( V_146 ) ) {
struct V_8 * V_9 = F_14 ( V_146 , struct V_8 , V_52 ) ;
if ( V_17 . V_47 && ! V_9 -> V_46 )
continue;
if ( V_25 != NULL && ( V_9 -> V_10 . V_24 == NULL || V_9 -> V_10 . V_24 -> V_25 != V_25 ) ) {
V_9 -> V_43 |= ( 1 << V_162 ) ;
continue;
}
F_50 ( V_2 , V_9 , V_162 ) ;
}
}
void F_52 ( struct V_1 * V_2 , const struct V_21 * V_21 )
{
struct V_52 * V_146 ;
V_2 -> V_44 = V_2 -> V_84 . V_85 = 0 ;
V_2 -> V_84 . V_40 [ V_161 ] = 0 ;
F_4 ( V_2 ) ;
for ( V_146 = F_26 ( & V_2 -> V_54 ) ; V_146 ; V_146 = F_27 ( V_146 ) ) {
struct V_8 * V_9 = F_14 ( V_146 , struct V_8 , V_52 ) ;
if ( V_21 != NULL && V_9 -> V_21 != V_21 ) {
V_9 -> V_43 |= ( 1 << V_163 ) ;
continue;
}
F_50 ( V_2 , V_9 , V_163 ) ;
}
}
int F_53 ( struct V_8 * V_55 , int V_164 , T_2 V_58 )
{
return F_54 ( V_55 -> V_10 . V_11 , V_55 -> V_10 . V_24 , V_164 , V_58 ) ;
}
int F_55 ( struct V_8 * V_55 , T_3 V_165 )
{
return F_56 ( V_55 -> V_10 . V_11 , V_55 -> V_10 . V_24 , V_165 ) ;
}
void F_57 ( struct V_1 * V_2 , T_8 type )
{
++ V_2 -> V_84 . V_40 [ 0 ] ;
++ V_2 -> V_84 . V_40 [ type ] ;
}
T_3 F_58 ( struct V_1 * V_2 , T_6 * V_87 )
{
int V_89 ;
T_3 V_90 = 0 ;
for ( V_89 = 0 ; V_89 < V_166 ; ++ V_89 ) {
const char * V_98 ;
if ( V_2 -> V_84 . V_40 [ V_89 ] == 0 )
continue;
V_98 = F_59 ( V_89 ) ;
if ( ! strcmp ( V_98 , L_57 ) )
continue;
V_90 += fprintf ( V_87 , L_58 , V_98 ,
V_2 -> V_84 . V_40 [ V_89 ] ) ;
}
return V_90 ;
}
