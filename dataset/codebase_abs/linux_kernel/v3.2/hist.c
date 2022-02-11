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
static void F_9 ( struct V_7 * V_36 )
{
V_36 -> V_27 = ( V_36 -> V_27 * 7 ) / 8 ;
V_36 -> V_37 = ( V_36 -> V_37 * 7 ) / 8 ;
}
static bool F_10 ( struct V_1 * V_1 , struct V_7 * V_36 )
{
T_2 V_38 = V_36 -> V_27 ;
if ( V_38 == 0 )
return true ;
F_9 ( V_36 ) ;
if ( ! V_36 -> V_39 )
V_1 -> V_40 . V_41 -= V_38 - V_36 -> V_27 ;
return V_36 -> V_27 == 0 ;
}
static void F_11 ( struct V_1 * V_1 , bool V_42 ,
bool V_43 , bool V_44 )
{
struct V_45 * V_46 = F_12 ( & V_1 -> V_47 ) ;
struct V_7 * V_48 ;
while ( V_46 ) {
V_48 = F_13 ( V_46 , struct V_7 , V_45 ) ;
V_46 = F_14 ( & V_48 -> V_45 ) ;
if ( ( ( V_42 && V_48 -> V_49 == '.' ) ||
( V_43 && V_48 -> V_49 != '.' ) ||
F_10 ( V_1 , V_48 ) ) &&
! V_48 -> V_50 ) {
F_15 ( & V_48 -> V_45 , & V_1 -> V_47 ) ;
if ( V_51 || V_44 )
F_15 ( & V_48 -> V_52 , & V_1 -> V_53 ) ;
F_16 ( V_48 ) ;
-- V_1 -> V_54 ;
}
}
}
void F_17 ( struct V_1 * V_1 , bool V_42 , bool V_43 )
{
return F_11 ( V_1 , V_42 , V_43 , false ) ;
}
void F_18 ( struct V_1 * V_1 ,
bool V_42 , bool V_43 )
{
return F_11 ( V_1 , V_42 , V_43 , true ) ;
}
static struct V_7 * F_19 ( struct V_7 * V_55 )
{
T_3 V_56 = V_16 . V_57 ? sizeof( struct V_58 ) : 0 ;
struct V_7 * V_25 = malloc ( sizeof( * V_25 ) + V_56 ) ;
if ( V_25 != NULL ) {
* V_25 = * V_55 ;
V_25 -> V_37 = 1 ;
if ( V_25 -> V_9 . V_23 )
V_25 -> V_9 . V_23 -> V_59 = true ;
if ( V_16 . V_57 )
F_20 ( V_25 -> V_60 ) ;
}
return V_25 ;
}
static void F_21 ( struct V_1 * V_1 , struct V_7 * V_8 )
{
if ( ! V_8 -> V_39 ) {
F_5 ( V_1 , V_8 ) ;
++ V_1 -> V_54 ;
V_1 -> V_40 . V_41 += V_8 -> V_27 ;
}
}
static T_4 F_22 ( const struct V_61 * V_62 )
{
if ( V_16 . V_63 && V_62 == NULL )
return 1 << V_64 ;
return 0 ;
}
struct V_7 * F_23 ( struct V_1 * V_1 ,
struct V_65 * V_66 ,
struct V_61 * V_67 , T_2 V_27 )
{
struct V_45 * * V_68 ;
struct V_45 * V_62 = NULL ;
struct V_7 * V_36 ;
struct V_7 V_69 = {
. V_20 = V_66 -> V_20 ,
. V_9 = {
. V_23 = V_66 -> V_23 ,
. V_10 = V_66 -> V_10 ,
} ,
. V_70 = V_66 -> V_70 ,
. V_71 = V_66 -> V_72 ,
. V_49 = V_66 -> V_49 ,
. V_27 = V_27 ,
. V_62 = V_67 ,
. V_39 = F_22 ( V_67 ) ,
} ;
int V_73 ;
F_24 ( & V_1 -> V_74 ) ;
V_68 = & V_1 -> V_75 -> V_45 ;
while ( * V_68 != NULL ) {
V_62 = * V_68 ;
V_36 = F_13 ( V_62 , struct V_7 , V_52 ) ;
V_73 = F_25 ( & V_69 , V_36 ) ;
if ( ! V_73 ) {
V_36 -> V_27 += V_27 ;
++ V_36 -> V_37 ;
goto V_76;
}
if ( V_73 < 0 )
V_68 = & ( * V_68 ) -> V_77 ;
else
V_68 = & ( * V_68 ) -> V_78 ;
}
V_36 = F_19 ( & V_69 ) ;
if ( ! V_36 )
goto V_79;
F_26 ( & V_36 -> V_52 , V_62 , V_68 ) ;
F_27 ( & V_36 -> V_52 , V_1 -> V_75 ) ;
V_76:
F_8 ( V_36 , V_66 -> V_26 , V_27 ) ;
V_79:
F_28 ( & V_1 -> V_74 ) ;
return V_36 ;
}
T_5
F_25 ( struct V_7 * V_80 , struct V_7 * V_81 )
{
struct V_82 * V_83 ;
T_5 V_73 = 0 ;
F_29 (se, &hist_entry__sort_list, list) {
V_73 = V_83 -> V_84 ( V_80 , V_81 ) ;
if ( V_73 )
break;
}
return V_73 ;
}
T_5
F_30 ( struct V_7 * V_80 , struct V_7 * V_81 )
{
struct V_82 * V_83 ;
T_5 V_73 = 0 ;
F_29 (se, &hist_entry__sort_list, list) {
T_5 (* F_31)( struct V_7 * , struct V_7 * );
F_31 = V_83 -> V_85 ? : V_83 -> V_84 ;
V_73 = F_31 ( V_80 , V_81 ) ;
if ( V_73 )
break;
}
return V_73 ;
}
void F_16 ( struct V_7 * V_36 )
{
free ( V_36 ) ;
}
static bool F_32 ( struct V_1 * V_1 ,
struct V_86 * V_87 ,
struct V_7 * V_36 )
{
struct V_45 * * V_68 = & V_87 -> V_45 ;
struct V_45 * V_62 = NULL ;
struct V_7 * V_88 ;
T_5 V_73 ;
while ( * V_68 != NULL ) {
V_62 = * V_68 ;
V_88 = F_13 ( V_62 , struct V_7 , V_52 ) ;
V_73 = F_30 ( V_88 , V_36 ) ;
if ( ! V_73 ) {
V_88 -> V_27 += V_36 -> V_27 ;
V_88 -> V_37 += V_36 -> V_37 ;
if ( V_16 . V_57 ) {
F_33 ( & V_1 -> V_89 ) ;
F_34 ( & V_1 -> V_89 , V_88 -> V_60 ,
V_36 -> V_60 ) ;
}
F_16 ( V_36 ) ;
return false ;
}
if ( V_73 < 0 )
V_68 = & ( * V_68 ) -> V_77 ;
else
V_68 = & ( * V_68 ) -> V_78 ;
}
F_26 ( & V_36 -> V_52 , V_62 , V_68 ) ;
F_27 ( & V_36 -> V_52 , V_87 ) ;
return true ;
}
static struct V_86 * F_35 ( struct V_1 * V_1 )
{
struct V_86 * V_87 ;
F_24 ( & V_1 -> V_74 ) ;
V_87 = V_1 -> V_75 ;
if ( ++ V_1 -> V_75 > & V_1 -> V_90 [ 1 ] )
V_1 -> V_75 = & V_1 -> V_90 [ 0 ] ;
F_28 ( & V_1 -> V_74 ) ;
return V_87 ;
}
static void F_36 ( struct V_1 * V_1 , struct V_7 * V_36 )
{
F_37 ( V_1 , V_36 ) ;
F_38 ( V_1 , V_36 ) ;
}
static void F_39 ( struct V_1 * V_1 , bool V_44 )
{
struct V_86 * V_87 ;
struct V_45 * V_46 ;
struct V_7 * V_48 ;
if ( ! V_51 && ! V_44 )
return;
V_87 = F_35 ( V_1 ) ;
V_46 = F_12 ( V_87 ) ;
while ( V_46 ) {
V_48 = F_13 ( V_46 , struct V_7 , V_52 ) ;
V_46 = F_14 ( & V_48 -> V_52 ) ;
F_15 ( & V_48 -> V_52 , V_87 ) ;
if ( F_32 ( V_1 , & V_1 -> V_53 , V_48 ) ) {
F_36 ( V_1 , V_48 ) ;
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
static void F_42 ( struct V_86 * V_47 ,
struct V_7 * V_36 ,
T_2 V_91 )
{
struct V_45 * * V_68 = & V_47 -> V_45 ;
struct V_45 * V_62 = NULL ;
struct V_7 * V_88 ;
if ( V_16 . V_57 )
V_92 . V_93 ( & V_36 -> V_94 , V_36 -> V_60 ,
V_91 , & V_92 ) ;
while ( * V_68 != NULL ) {
V_62 = * V_68 ;
V_88 = F_13 ( V_62 , struct V_7 , V_45 ) ;
if ( V_36 -> V_27 > V_88 -> V_27 )
V_68 = & ( * V_68 ) -> V_77 ;
else
V_68 = & ( * V_68 ) -> V_78 ;
}
F_26 ( & V_36 -> V_45 , V_62 , V_68 ) ;
F_27 ( & V_36 -> V_45 , V_47 ) ;
}
static void F_43 ( struct V_1 * V_1 , bool V_44 )
{
struct V_86 * V_87 ;
struct V_45 * V_46 ;
struct V_7 * V_48 ;
T_2 V_91 ;
V_91 = V_1 -> V_40 . V_41 * ( V_92 . V_95 / 100 ) ;
if ( V_51 || V_44 )
V_87 = & V_1 -> V_53 ;
else
V_87 = V_1 -> V_75 ;
V_46 = F_12 ( V_87 ) ;
V_1 -> V_47 = V_96 ;
V_1 -> V_54 = 0 ;
V_1 -> V_40 . V_41 = 0 ;
F_4 ( V_1 ) ;
while ( V_46 ) {
V_48 = F_13 ( V_46 , struct V_7 , V_52 ) ;
V_46 = F_14 ( & V_48 -> V_52 ) ;
F_42 ( & V_1 -> V_47 , V_48 , V_91 ) ;
F_21 ( V_1 , V_48 ) ;
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
static T_3 F_46 ( T_6 * V_97 , int V_98 )
{
int V_99 ;
int V_100 = fprintf ( V_97 , L_1 ) ;
for ( V_99 = 0 ; V_99 < V_98 ; V_99 ++ )
V_100 += fprintf ( V_97 , L_2 ) ;
return V_100 ;
}
static T_3 F_47 ( T_6 * V_97 , int V_101 , int V_102 ,
int V_98 )
{
int V_99 ;
T_3 V_100 = F_46 ( V_97 , V_98 ) ;
for ( V_99 = 0 ; V_99 < V_101 ; V_99 ++ )
if ( V_102 & ( 1 << V_99 ) )
V_100 += fprintf ( V_97 , L_3 ) ;
else
V_100 += fprintf ( V_97 , L_4 ) ;
V_100 += fprintf ( V_97 , L_5 ) ;
return V_100 ;
}
static T_3 F_48 ( T_6 * V_97 , struct V_103 * V_104 ,
int V_101 , int V_102 , int V_27 ,
T_2 V_105 , T_2 V_106 ,
int V_98 )
{
int V_99 ;
T_3 V_100 = 0 ;
V_100 += F_46 ( V_97 , V_98 ) ;
for ( V_99 = 0 ; V_99 < V_101 ; V_99 ++ ) {
if ( V_102 & ( 1 << V_99 ) )
V_100 += fprintf ( V_97 , L_6 ) ;
else
V_100 += fprintf ( V_97 , L_2 ) ;
if ( ! V_27 && V_99 == V_101 - 1 ) {
double V_107 ;
V_107 = V_106 * 100.0 / V_105 ;
V_100 += F_49 ( V_97 , L_7 , V_107 ) ;
} else
V_100 += fprintf ( V_97 , L_8 , L_9 ) ;
}
if ( V_104 -> V_9 . V_10 )
V_100 += fprintf ( V_97 , L_10 , V_104 -> V_9 . V_10 -> V_108 ) ;
else
V_100 += fprintf ( V_97 , L_11 , ( void * ) ( long ) V_104 -> V_71 ) ;
return V_100 ;
}
static void F_50 ( void )
{
V_109 = malloc ( sizeof( * V_109 ) + 6 ) ;
if ( ! V_109 ) {
fprintf ( V_110 , L_12 ) ;
return;
}
strcpy ( V_109 -> V_108 , L_13 ) ;
V_111 . V_9 . V_10 = V_109 ;
}
static T_3 F_51 ( T_6 * V_97 , struct V_112 * V_25 ,
T_2 V_105 , int V_101 ,
int V_102 , int V_98 )
{
struct V_45 * V_113 , * V_46 ;
struct V_112 * V_114 ;
struct V_103 * V_104 ;
int V_115 = V_102 ;
T_2 V_116 ;
T_2 V_117 ;
T_3 V_100 = 0 ;
int V_99 ;
T_7 V_118 = 0 ;
if ( V_92 . V_119 == V_120 )
V_116 = V_25 -> V_121 ;
else
V_116 = V_105 ;
V_117 = V_116 ;
V_113 = F_12 ( & V_25 -> V_86 ) ;
while ( V_113 ) {
T_2 V_122 ;
V_114 = F_13 ( V_113 , struct V_112 , V_45 ) ;
V_122 = F_52 ( V_114 ) ;
V_117 -= V_122 ;
V_46 = F_14 ( V_113 ) ;
if ( ! V_46 && ( V_92 . V_119 != V_120 || ! V_117 ) )
V_115 &= ~ ( 1 << ( V_101 - 1 ) ) ;
V_100 += F_47 ( V_97 , V_101 , V_102 ,
V_98 ) ;
V_99 = 0 ;
F_29 (chain, &child->val, list) {
V_100 += F_48 ( V_97 , V_104 , V_101 ,
V_115 , V_99 ++ ,
V_116 ,
V_122 ,
V_98 ) ;
}
V_100 += F_51 ( V_97 , V_114 , V_116 ,
V_101 + 1 ,
V_115 | ( 1 << V_101 ) ,
V_98 ) ;
V_113 = V_46 ;
if ( ++ V_118 == V_92 . V_123 )
break;
}
if ( V_92 . V_119 == V_120 &&
V_117 && V_117 != V_116 ) {
if ( ! V_109 )
return V_100 ;
V_115 &= ~ ( 1 << ( V_101 - 1 ) ) ;
V_100 += F_48 ( V_97 , & V_111 , V_101 ,
V_115 , 0 , V_116 ,
V_117 , V_98 ) ;
}
return V_100 ;
}
static T_3 F_53 ( T_6 * V_97 , struct V_112 * V_25 ,
T_2 V_105 , int V_98 )
{
struct V_103 * V_104 ;
bool V_124 = false ;
int V_99 = 0 ;
int V_100 = 0 ;
T_8 V_118 = 0 ;
F_29 (chain, &self->val, list) {
if ( ! V_99 ++ && V_125 == V_126 )
continue;
if ( ! V_124 ) {
V_100 += F_46 ( V_97 , V_98 ) ;
V_100 += fprintf ( V_97 , L_14 ) ;
V_100 += F_46 ( V_97 , V_98 ) ;
V_100 += fprintf ( V_97 , L_15 ) ;
V_98 += 3 ;
V_124 = true ;
} else
V_100 += F_46 ( V_97 , V_98 ) ;
if ( V_104 -> V_9 . V_10 )
V_100 += fprintf ( V_97 , L_16 , V_104 -> V_9 . V_10 -> V_108 ) ;
else
V_100 += fprintf ( V_97 , L_17 , ( void * ) ( long ) V_104 -> V_71 ) ;
if ( ++ V_118 == V_92 . V_123 )
break;
}
V_100 += F_51 ( V_97 , V_25 , V_105 , 1 , 1 , V_98 ) ;
return V_100 ;
}
static T_3 F_54 ( T_6 * V_97 , struct V_112 * V_25 ,
T_2 V_105 )
{
struct V_103 * V_104 ;
T_3 V_100 = 0 ;
if ( ! V_25 )
return 0 ;
V_100 += F_54 ( V_97 , V_25 -> V_62 , V_105 ) ;
F_29 (chain, &self->val, list) {
if ( V_104 -> V_71 >= V_127 )
continue;
if ( V_104 -> V_9 . V_10 )
V_100 += fprintf ( V_97 , L_18 , V_104 -> V_9 . V_10 -> V_108 ) ;
else
V_100 += fprintf ( V_97 , L_19 ,
( void * ) ( long ) V_104 -> V_71 ) ;
}
return V_100 ;
}
static T_3 F_55 ( T_6 * V_97 , struct V_7 * V_25 ,
T_2 V_105 , int V_98 )
{
struct V_45 * V_45 ;
struct V_112 * V_104 ;
T_3 V_100 = 0 ;
T_8 V_118 = 0 ;
V_45 = F_12 ( & V_25 -> V_94 ) ;
while ( V_45 ) {
double V_107 ;
V_104 = F_13 ( V_45 , struct V_112 , V_45 ) ;
V_107 = V_104 -> V_128 * 100.0 / V_105 ;
switch ( V_92 . V_119 ) {
case V_129 :
V_100 += F_49 ( V_97 , L_20 ,
V_107 ) ;
V_100 += F_54 ( V_97 , V_104 , V_105 ) ;
break;
case V_130 :
case V_120 :
V_100 += F_53 ( V_97 , V_104 , V_105 ,
V_98 ) ;
case V_131 :
default:
break;
}
V_100 += fprintf ( V_97 , L_5 ) ;
if ( ++ V_118 == V_92 . V_123 )
break;
V_45 = F_14 ( V_45 ) ;
}
return V_100 ;
}
void F_56 ( struct V_1 * V_1 , int V_132 )
{
struct V_45 * V_46 = F_12 ( & V_1 -> V_47 ) ;
struct V_7 * V_48 ;
int V_133 = 0 ;
F_4 ( V_1 ) ;
while ( V_46 && V_133 ++ < V_132 ) {
V_48 = F_13 ( V_46 , struct V_7 , V_45 ) ;
if ( ! V_48 -> V_39 )
F_5 ( V_1 , V_48 ) ;
V_46 = F_14 ( & V_48 -> V_45 ) ;
}
}
static int F_57 ( struct V_7 * V_25 , char * V_134 ,
T_3 V_135 , struct V_1 * V_136 ,
bool V_137 , long V_138 ,
bool V_139 , T_2 V_140 )
{
T_2 V_27 , V_141 , V_29 , V_31 , V_33 , V_35 ;
T_2 V_37 ;
const char * V_142 = V_16 . V_18 ;
int V_100 ;
if ( V_16 . V_63 && ! V_25 -> V_62 )
return 0 ;
if ( V_136 ) {
V_27 = V_25 -> V_143 ? V_25 -> V_143 -> V_27 : 0 ;
V_37 = V_25 -> V_143 ? V_25 -> V_143 -> V_37 : 0 ;
V_141 = V_136 -> V_40 . V_41 ;
V_29 = V_25 -> V_143 ? V_25 -> V_143 -> V_29 : 0 ;
V_31 = V_25 -> V_143 ? V_25 -> V_143 -> V_31 : 0 ;
V_33 = V_25 -> V_143 ? V_25 -> V_143 -> V_33 : 0 ;
V_35 = V_25 -> V_143 ? V_25 -> V_143 -> V_35 : 0 ;
} else {
V_27 = V_25 -> V_27 ;
V_37 = V_25 -> V_37 ;
V_141 = V_140 ;
V_29 = V_25 -> V_29 ;
V_31 = V_25 -> V_31 ;
V_33 = V_25 -> V_33 ;
V_35 = V_25 -> V_35 ;
}
if ( V_141 ) {
if ( V_139 )
V_100 = F_58 ( V_134 , V_135 ,
V_142 ? L_21 : L_22 ,
( V_27 * 100.0 ) / V_141 ) ;
else
V_100 = snprintf ( V_134 , V_135 , V_142 ? L_21 : L_22 ,
( V_27 * 100.0 ) / V_141 ) ;
if ( V_16 . V_144 ) {
V_100 += F_58 ( V_134 + V_100 , V_135 - V_100 ,
V_142 ? L_21 : L_22 ,
( V_29 * 100.0 ) / V_141 ) ;
V_100 += F_58 ( V_134 + V_100 , V_135 - V_100 ,
V_142 ? L_21 : L_22 ,
( V_31 * 100.0 ) / V_141 ) ;
if ( V_145 ) {
V_100 += F_58 ( V_134 + V_100 ,
V_135 - V_100 ,
V_142 ? L_21 : L_22 ,
( V_33 * 100.0 ) /
V_141 ) ;
V_100 += F_58 ( V_134 + V_100 ,
V_135 - V_100 ,
V_142 ? L_21 : L_22 ,
( V_35 * 100.0 ) /
V_141 ) ;
}
}
} else
V_100 = snprintf ( V_134 , V_135 , V_142 ? L_23 V_146 : L_24 V_146 L_2 , V_27 ) ;
if ( V_16 . V_147 ) {
if ( V_142 )
V_100 += snprintf ( V_134 + V_100 , V_135 - V_100 , L_25 V_146 , * V_142 , V_37 ) ;
else
V_100 += snprintf ( V_134 + V_100 , V_135 - V_100 , L_26 V_146 , V_37 ) ;
}
if ( V_16 . V_148 ) {
if ( V_142 )
V_100 += snprintf ( V_134 + V_100 , V_135 - V_100 , L_25 V_146 , * V_142 , V_27 ) ;
else
V_100 += snprintf ( V_134 + V_100 , V_135 - V_100 , L_27 V_146 , V_27 ) ;
}
if ( V_136 ) {
char V_149 [ 32 ] ;
double V_150 = 0 , V_151 = 0 , V_152 ;
if ( V_141 > 0 )
V_150 = ( V_27 * 100.0 ) / V_141 ;
if ( V_140 > 0 )
V_151 = ( V_25 -> V_27 * 100.0 ) / V_140 ;
V_152 = V_151 - V_150 ;
if ( fabs ( V_152 ) >= 0.01 )
snprintf ( V_149 , sizeof( V_149 ) , L_28 , V_152 ) ;
else
snprintf ( V_149 , sizeof( V_149 ) , L_2 ) ;
if ( V_142 )
V_100 += snprintf ( V_134 + V_100 , V_135 - V_100 , L_29 , * V_142 , V_149 ) ;
else
V_100 += snprintf ( V_134 + V_100 , V_135 - V_100 , L_30 , V_149 ) ;
if ( V_137 ) {
if ( V_138 )
snprintf ( V_149 , sizeof( V_149 ) , L_31 , V_138 ) ;
else
snprintf ( V_149 , sizeof( V_149 ) , L_2 ) ;
if ( V_142 )
V_100 += snprintf ( V_134 + V_100 , V_135 - V_100 , L_29 , * V_142 , V_149 ) ;
else
V_100 += snprintf ( V_134 + V_100 , V_135 - V_100 , L_32 , V_149 ) ;
}
}
return V_100 ;
}
int F_59 ( struct V_7 * V_36 , char * V_134 , T_3 V_135 ,
struct V_1 * V_1 )
{
const char * V_142 = V_16 . V_18 ;
struct V_82 * V_83 ;
int V_100 = 0 ;
F_29 (se, &hist_entry__sort_list, list) {
if ( V_83 -> V_153 )
continue;
V_100 += snprintf ( V_134 + V_100 , V_135 - V_100 , L_8 , V_142 ? : L_33 ) ;
V_100 += V_83 -> V_154 ( V_36 , V_134 + V_100 , V_135 - V_100 ,
F_1 ( V_1 , V_83 -> V_155 ) ) ;
}
return V_100 ;
}
int F_60 ( struct V_7 * V_36 , T_3 V_135 , struct V_1 * V_1 ,
struct V_1 * V_136 , bool V_137 ,
long V_138 , T_6 * V_97 , T_2 V_140 )
{
char V_149 [ 512 ] ;
int V_100 ;
if ( V_135 == 0 || V_135 > sizeof( V_149 ) )
V_135 = sizeof( V_149 ) ;
V_100 = F_57 ( V_36 , V_149 , V_135 , V_136 ,
V_137 , V_138 ,
true , V_140 ) ;
F_59 ( V_36 , V_149 + V_100 , V_135 - V_100 , V_1 ) ;
return fprintf ( V_97 , L_10 , V_149 ) ;
}
static T_3 F_61 ( struct V_7 * V_25 ,
struct V_1 * V_1 , T_6 * V_97 ,
T_2 V_140 )
{
int V_98 = 0 ;
if ( V_125 == V_156 ) {
struct V_82 * V_83 = F_62 ( & V_157 ,
F_63 ( * V_83 ) , V_158 ) ;
V_98 = F_1 ( V_1 , V_83 -> V_155 ) ;
V_98 -= F_6 ( V_25 -> V_20 ) ;
}
return F_55 ( V_97 , V_25 , V_140 ,
V_98 ) ;
}
T_3 F_64 ( struct V_1 * V_1 , struct V_1 * V_143 ,
bool V_137 , bool V_159 , int V_132 ,
int V_160 , T_6 * V_97 )
{
struct V_82 * V_83 ;
struct V_45 * V_161 ;
T_3 V_100 = 0 ;
unsigned long V_162 = 1 ;
long V_138 = 0 ;
unsigned int V_163 ;
const char * V_142 = V_16 . V_18 ;
const char * V_164 = V_16 . V_17 ;
int V_165 = 0 ;
F_50 () ;
if ( ! V_159 )
goto V_166;
fprintf ( V_97 , L_34 , V_143 ? L_35 : L_36 ) ;
if ( V_16 . V_147 ) {
if ( V_142 )
fprintf ( V_97 , L_37 , * V_142 ) ;
else
fputs ( L_38 , V_97 ) ;
}
if ( V_16 . V_148 ) {
if ( V_142 )
V_100 += fprintf ( V_97 , L_39 , * V_142 ) ;
else
V_100 += fprintf ( V_97 , L_40 ) ;
}
if ( V_16 . V_144 ) {
if ( V_142 ) {
V_100 += fprintf ( V_97 , L_41 , * V_142 ) ;
V_100 += fprintf ( V_97 , L_42 , * V_142 ) ;
if ( V_145 ) {
V_100 += fprintf ( V_97 , L_43 , * V_142 ) ;
V_100 += fprintf ( V_97 , L_44 , * V_142 ) ;
}
} else {
V_100 += fprintf ( V_97 , L_45 ) ;
V_100 += fprintf ( V_97 , L_46 ) ;
if ( V_145 ) {
V_100 += fprintf ( V_97 , L_47 ) ;
V_100 += fprintf ( V_97 , L_48 ) ;
}
}
}
if ( V_143 ) {
if ( V_142 )
V_100 += fprintf ( V_97 , L_49 , * V_142 ) ;
else
V_100 += fprintf ( V_97 , L_50 ) ;
if ( V_137 ) {
if ( V_142 )
V_100 += fprintf ( V_97 , L_51 , * V_142 ) ;
else
V_100 += fprintf ( V_97 , L_52 ) ;
}
}
F_29 (se, &hist_entry__sort_list, list) {
if ( V_83 -> V_153 )
continue;
if ( V_142 ) {
fprintf ( V_97 , L_29 , * V_142 , V_83 -> V_167 ) ;
continue;
}
V_163 = strlen ( V_83 -> V_167 ) ;
if ( V_16 . V_17 ) {
if ( V_164 ) {
F_2 ( V_1 , V_83 -> V_155 ,
atoi ( V_164 ) ) ;
V_164 = strchr ( V_164 , ',' ) ;
if ( V_164 )
++ V_164 ;
}
}
if ( ! F_3 ( V_1 , V_83 -> V_155 , V_163 ) )
V_163 = F_1 ( V_1 , V_83 -> V_155 ) ;
fprintf ( V_97 , L_53 , V_163 , V_83 -> V_167 ) ;
}
fprintf ( V_97 , L_5 ) ;
if ( V_132 && ++ V_165 >= V_132 )
goto V_76;
if ( V_142 )
goto V_166;
fprintf ( V_97 , L_54 ) ;
if ( V_16 . V_147 )
fprintf ( V_97 , L_55 ) ;
if ( V_16 . V_148 )
fprintf ( V_97 , L_56 ) ;
if ( V_143 ) {
fprintf ( V_97 , L_55 ) ;
if ( V_137 )
fprintf ( V_97 , L_57 ) ;
}
F_29 (se, &hist_entry__sort_list, list) {
unsigned int V_99 ;
if ( V_83 -> V_153 )
continue;
fprintf ( V_97 , L_33 ) ;
V_163 = F_1 ( V_1 , V_83 -> V_155 ) ;
if ( V_163 == 0 )
V_163 = strlen ( V_83 -> V_167 ) ;
for ( V_99 = 0 ; V_99 < V_163 ; V_99 ++ )
fprintf ( V_97 , L_58 ) ;
}
fprintf ( V_97 , L_5 ) ;
if ( V_132 && ++ V_165 >= V_132 )
goto V_76;
fprintf ( V_97 , L_59 ) ;
if ( V_132 && ++ V_165 >= V_132 )
goto V_76;
V_166:
for ( V_161 = F_12 ( & V_1 -> V_47 ) ; V_161 ; V_161 = F_14 ( V_161 ) ) {
struct V_7 * V_8 = F_13 ( V_161 , struct V_7 , V_45 ) ;
if ( V_8 -> V_39 )
continue;
if ( V_137 ) {
if ( V_8 -> V_143 != NULL )
V_138 = ( ( long ) V_8 -> V_143 -> V_162 -
( long ) V_162 ) ;
else
V_138 = 0 ;
++ V_162 ;
}
V_100 += F_60 ( V_8 , V_160 , V_1 , V_143 , V_137 ,
V_138 , V_97 , V_1 -> V_40 . V_41 ) ;
if ( V_16 . V_57 )
V_100 += F_61 ( V_8 , V_1 , V_97 ,
V_1 -> V_40 . V_41 ) ;
if ( V_132 && ++ V_165 >= V_132 )
goto V_76;
if ( V_8 -> V_9 . V_23 == NULL && V_168 > 1 ) {
F_65 ( & V_8 -> V_20 -> V_169 ,
V_170 , V_168 , V_97 ) ;
fprintf ( V_97 , L_60 , V_171 ) ;
}
}
V_76:
free ( V_109 ) ;
return V_100 ;
}
unsigned int F_66 ( struct V_1 * V_1 )
{
struct V_82 * V_83 ;
int V_100 = 9 ;
if ( V_16 . V_144 ) {
V_100 += 7 ;
V_100 += 6 ;
if ( V_145 ) {
V_100 += 13 ;
V_100 += 12 ;
}
}
if ( V_16 . V_147 )
V_100 += 11 ;
if ( V_16 . V_148 )
V_100 += 13 ;
F_29 (se, &hist_entry__sort_list, list)
if ( ! V_83 -> V_153 )
V_100 += 2 + F_1 ( V_1 , V_83 -> V_155 ) ;
if ( V_168 )
V_100 += 3 + V_14 / 4 ;
return V_100 ;
}
static void F_67 ( struct V_1 * V_1 , struct V_7 * V_8 ,
enum V_172 V_173 )
{
V_8 -> V_39 &= ~ ( 1 << V_173 ) ;
if ( V_8 -> V_39 )
return;
++ V_1 -> V_54 ;
if ( V_8 -> V_9 . V_174 )
V_1 -> V_54 += V_8 -> V_165 ;
V_8 -> V_175 = 0 ;
V_1 -> V_40 . V_41 += V_8 -> V_27 ;
V_1 -> V_40 . V_37 [ V_176 ] += V_8 -> V_37 ;
F_5 ( V_1 , V_8 ) ;
}
static bool F_37 ( struct V_1 * V_1 ,
struct V_7 * V_36 )
{
if ( V_1 -> V_177 != NULL &&
( V_36 -> V_9 . V_23 == NULL || V_36 -> V_9 . V_23 -> V_24 != V_1 -> V_177 ) ) {
V_36 -> V_39 |= ( 1 << V_178 ) ;
return true ;
}
return false ;
}
void F_68 ( struct V_1 * V_1 )
{
struct V_45 * V_161 ;
V_1 -> V_54 = V_1 -> V_40 . V_41 = 0 ;
V_1 -> V_40 . V_37 [ V_176 ] = 0 ;
F_4 ( V_1 ) ;
for ( V_161 = F_12 ( & V_1 -> V_47 ) ; V_161 ; V_161 = F_14 ( V_161 ) ) {
struct V_7 * V_8 = F_13 ( V_161 , struct V_7 , V_45 ) ;
if ( V_16 . V_63 && ! V_8 -> V_62 )
continue;
if ( F_37 ( V_1 , V_8 ) )
continue;
F_67 ( V_1 , V_8 , V_178 ) ;
}
}
static bool F_38 ( struct V_1 * V_1 ,
struct V_7 * V_36 )
{
if ( V_1 -> V_179 != NULL &&
V_36 -> V_20 != V_1 -> V_179 ) {
V_36 -> V_39 |= ( 1 << V_180 ) ;
return true ;
}
return false ;
}
void F_69 ( struct V_1 * V_1 )
{
struct V_45 * V_161 ;
V_1 -> V_54 = V_1 -> V_40 . V_41 = 0 ;
V_1 -> V_40 . V_37 [ V_176 ] = 0 ;
F_4 ( V_1 ) ;
for ( V_161 = F_12 ( & V_1 -> V_47 ) ; V_161 ; V_161 = F_14 ( V_161 ) ) {
struct V_7 * V_8 = F_13 ( V_161 , struct V_7 , V_45 ) ;
if ( F_38 ( V_1 , V_8 ) )
continue;
F_67 ( V_1 , V_8 , V_180 ) ;
}
}
int F_70 ( struct V_7 * V_36 , int V_181 , T_2 V_71 )
{
return F_71 ( V_36 -> V_9 . V_10 , V_36 -> V_9 . V_23 , V_181 , V_71 ) ;
}
int F_72 ( struct V_7 * V_36 , T_3 V_182 )
{
return F_73 ( V_36 -> V_9 . V_10 , V_36 -> V_9 . V_23 , V_182 ) ;
}
void F_74 ( struct V_1 * V_1 , T_8 type )
{
++ V_1 -> V_40 . V_37 [ 0 ] ;
++ V_1 -> V_40 . V_37 [ type ] ;
}
T_3 F_75 ( struct V_1 * V_1 , T_6 * V_97 )
{
int V_99 ;
T_3 V_100 = 0 ;
for ( V_99 = 0 ; V_99 < V_183 ; ++ V_99 ) {
const char * V_108 ;
if ( V_1 -> V_40 . V_37 [ V_99 ] == 0 )
continue;
V_108 = F_76 ( V_99 ) ;
if ( ! strcmp ( V_108 , L_61 ) )
continue;
V_100 += fprintf ( V_97 , L_62 , V_108 ,
V_1 -> V_40 . V_37 [ V_99 ] ) ;
}
return V_100 ;
}
