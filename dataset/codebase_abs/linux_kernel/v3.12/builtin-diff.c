static int F_1 ( char * V_1 )
{
char * V_2 = V_1 ;
char * V_3 ;
int V_4 = - V_5 ;
if ( ! V_1 )
goto V_6;
V_3 = strchr ( V_1 , ',' ) ;
if ( ! V_3 )
goto V_6;
* V_3 ++ = 0x0 ;
if ( ! * V_3 )
goto V_6;
V_7 = strtol ( V_2 , NULL , 10 ) ;
V_8 = strtol ( V_3 , NULL , 10 ) ;
if ( ! V_7 || ! V_8 )
goto V_6;
F_2 ( L_1 V_9 L_2 V_9 L_3 ,
V_7 , V_8 ) ;
V_4 = 0 ;
V_6:
if ( V_4 )
F_3 ( L_4 ) ;
return V_4 ;
}
static int F_4 ( char * V_1 )
{
if ( V_10 == V_11 )
return F_1 ( V_1 ) ;
if ( V_1 ) {
F_3 ( L_5 , V_1 ) ;
return - V_5 ;
}
return 0 ;
}
static int F_5 ( const struct V_12 * V_1 , const char * V_13 ,
int T_1 V_14 )
{
int * V_15 = ( int * ) V_1 -> V_16 ;
char * V_17 = ( char * ) V_13 ;
char V_18 [ 50 ] ;
unsigned V_19 ;
char * V_12 ;
if ( ! V_13 ) {
* V_15 = V_20 ;
return 0 ;
}
V_12 = strchr ( V_13 , ':' ) ;
if ( V_12 ) {
unsigned V_21 = V_12 ++ - V_13 ;
if ( V_21 >= sizeof( V_18 ) )
return - V_5 ;
strncpy ( V_18 , V_13 , V_21 ) ;
V_18 [ V_21 ] = 0x0 ;
V_17 = V_18 ;
}
for ( V_19 = 0 ; V_19 < V_22 ; V_19 ++ )
if ( ! strcmp ( V_17 , V_23 [ V_19 ] ) ) {
* V_15 = V_19 ;
return F_4 ( V_12 ) ;
}
F_3 ( L_6
L_7 , V_13 ) ;
return - V_5 ;
}
static double F_6 ( struct V_24 * V_25 , T_2 V_26 )
{
T_2 V_27 = V_25 -> V_28 -> V_29 . V_30 ;
return ( V_26 * 100.0 ) / V_27 ;
}
static double F_7 ( struct V_24 * V_25 , struct V_24 * V_31 )
{
double V_32 = F_6 ( V_25 , V_25 -> V_33 . V_26 ) ;
double V_34 = F_6 ( V_31 , V_31 -> V_33 . V_26 ) ;
V_31 -> V_35 . V_36 = V_34 - V_32 ;
V_31 -> V_35 . V_37 = true ;
return V_31 -> V_35 . V_36 ;
}
static double F_8 ( struct V_24 * V_25 , struct V_24 * V_31 )
{
double V_38 = V_25 -> V_33 . V_26 ? : 1 ;
double V_39 = V_31 -> V_33 . V_26 ;
V_31 -> V_35 . V_37 = true ;
V_31 -> V_35 . V_40 = V_39 / V_38 ;
return V_31 -> V_35 . V_40 ;
}
static T_3 F_9 ( struct V_24 * V_25 , struct V_24 * V_31 )
{
T_2 V_38 = V_25 -> V_33 . V_26 ;
T_2 V_39 = V_31 -> V_33 . V_26 ;
V_31 -> V_35 . V_37 = true ;
V_31 -> V_35 . V_41 = V_39 * V_8 -
V_38 * V_7 ;
return V_31 -> V_35 . V_41 ;
}
static int F_10 ( struct V_24 * V_25 , struct V_24 * V_31 ,
char * V_18 , T_4 V_42 )
{
return F_11 ( V_18 , V_42 ,
L_8 V_43 L_9 V_43 L_10
L_8 V_43 L_9 V_43 L_11 ,
V_31 -> V_33 . V_26 , V_31 -> V_28 -> V_29 . V_30 ,
V_25 -> V_33 . V_26 , V_25 -> V_28 -> V_29 . V_30 ) ;
}
static int F_12 ( struct V_24 * V_25 , struct V_24 * V_31 ,
char * V_18 , T_4 V_42 )
{
double V_38 = V_25 -> V_33 . V_26 ;
double V_39 = V_31 -> V_33 . V_26 ;
return F_11 ( V_18 , V_42 , L_12 , V_39 , V_38 ) ;
}
static int F_13 ( struct V_24 * V_25 , struct V_24 * V_31 ,
char * V_18 , T_4 V_42 )
{
T_2 V_38 = V_25 -> V_33 . V_26 ;
T_2 V_39 = V_31 -> V_33 . V_26 ;
return F_11 ( V_18 , V_42 ,
L_8 V_43 L_13 L_14 V_9 L_15 V_43 L_13 L_14 V_9 L_11 ,
V_39 , V_8 , V_38 , V_7 ) ;
}
static int F_14 ( struct V_24 * V_25 , struct V_24 * V_31 ,
char * V_18 , T_4 V_42 )
{
switch ( V_10 ) {
case V_20 :
return F_10 ( V_25 , V_31 , V_18 , V_42 ) ;
case V_44 :
return F_12 ( V_25 , V_31 , V_18 , V_42 ) ;
case V_11 :
return F_13 ( V_25 , V_31 , V_18 , V_42 ) ;
default:
F_15 ( 1 ) ;
}
return - 1 ;
}
static int F_16 ( struct V_28 * V_45 ,
struct V_46 * V_47 , T_2 V_26 ,
T_2 V_48 )
{
if ( F_17 ( V_45 , V_47 , NULL , V_26 , V_48 ) != NULL )
return 0 ;
return - V_49 ;
}
static int F_18 ( struct V_50 * T_5 V_14 ,
union V_51 * V_52 ,
struct V_53 * V_54 ,
struct V_55 * V_56 ,
struct V_57 * V_57 )
{
struct V_46 V_47 ;
if ( F_19 ( V_52 , V_57 , & V_47 , V_54 ) < 0 ) {
F_20 ( L_16 ,
V_52 -> V_58 . type ) ;
return - 1 ;
}
if ( V_47 . V_59 )
return 0 ;
if ( F_16 ( & V_56 -> V_28 , & V_47 , V_54 -> V_26 , V_54 -> V_48 ) ) {
F_20 ( L_17 ) ;
return - 1 ;
}
V_56 -> V_28 . V_29 . V_30 += V_54 -> V_26 ;
return 0 ;
}
static struct V_55 * F_21 ( struct V_55 * V_56 ,
struct V_60 * V_61 )
{
struct V_55 * V_62 ;
F_22 (e, &evlist->entries, node)
if ( F_23 ( V_56 , V_62 ) )
return V_62 ;
return NULL ;
}
static void F_24 ( struct V_60 * V_61 )
{
struct V_55 * V_56 ;
F_22 (evsel, &evlist->entries, node) {
struct V_28 * V_28 = & V_56 -> V_28 ;
F_25 ( V_28 ) ;
}
}
static struct V_24 *
F_26 ( struct V_24 * V_25 , struct V_63 * V_64 )
{
if ( F_27 ( V_25 ) ) {
struct V_24 * V_31 ;
F_22 (pair, &he->pairs.head, pairs.node)
if ( V_31 -> V_28 == V_64 -> V_28 )
return V_31 ;
}
return NULL ;
}
static struct V_24 *
F_28 ( struct V_24 * V_25 , struct V_65 * V_66 )
{
void * V_67 = V_66 - V_66 -> V_68 ;
struct V_63 * V_64 = F_29 ( V_67 , struct V_63 , V_69 ) ;
return F_26 ( V_25 , V_64 ) ;
}
static void F_30 ( struct V_28 * V_28 )
{
struct V_70 * V_71 ;
struct V_72 * V_73 ;
if ( V_74 )
V_71 = & V_28 -> V_75 ;
else
V_71 = V_28 -> V_76 ;
V_73 = F_31 ( V_71 ) ;
while ( V_73 != NULL ) {
struct V_24 * V_25 = F_32 ( V_73 , struct V_24 , V_77 ) ;
V_73 = F_33 ( & V_25 -> V_77 ) ;
if ( ! F_34 ( V_25 ) ) {
F_35 ( & V_25 -> V_77 , V_71 ) ;
F_36 ( V_25 ) ;
}
}
}
static void F_37 ( struct V_28 * V_28 )
{
struct V_70 * V_71 ;
struct V_72 * V_73 ;
if ( V_74 )
V_71 = & V_28 -> V_75 ;
else
V_71 = V_28 -> V_76 ;
V_73 = F_31 ( V_71 ) ;
while ( V_73 != NULL ) {
struct V_24 * V_25 , * V_31 ;
V_25 = F_32 ( V_73 , struct V_24 , V_77 ) ;
V_73 = F_33 ( & V_25 -> V_77 ) ;
V_31 = F_26 ( V_25 , & V_78 [ V_79 ] ) ;
if ( ! V_31 )
continue;
switch ( V_10 ) {
case V_20 :
F_7 ( V_25 , V_31 ) ;
break;
case V_44 :
F_8 ( V_25 , V_31 ) ;
break;
case V_11 :
F_9 ( V_25 , V_31 ) ;
break;
default:
F_15 ( 1 ) ;
}
}
}
static T_6 F_38 ( double V_80 , double V_81 )
{
if ( V_80 > V_81 )
return - 1 ;
else if ( V_80 < V_81 )
return 1 ;
else
return 0 ;
}
static T_6
F_39 ( struct V_24 * V_82 , struct V_24 * V_83 ,
int V_84 )
{
switch ( V_84 ) {
case V_20 :
{
double V_80 = V_82 -> V_35 . V_36 ;
double V_81 = V_83 -> V_35 . V_36 ;
return F_38 ( V_80 , V_81 ) ;
}
case V_44 :
{
double V_80 = V_82 -> V_35 . V_40 ;
double V_81 = V_83 -> V_35 . V_40 ;
return F_38 ( V_80 , V_81 ) ;
}
case V_11 :
{
T_3 V_80 = V_82 -> V_35 . V_41 ;
T_3 V_81 = V_83 -> V_35 . V_41 ;
return V_81 - V_80 ;
}
default:
F_15 ( 1 ) ;
}
return 0 ;
}
static T_6
F_40 ( struct V_24 * V_82 , struct V_24 * V_83 ,
int V_84 )
{
bool V_85 = F_27 ( V_82 ) ;
bool V_86 = F_27 ( V_83 ) ;
struct V_24 * V_87 , * V_88 ;
if ( ! V_85 && ! V_86 )
return 0 ;
if ( ! V_85 || ! V_86 )
return V_85 ? - 1 : 1 ;
V_88 = F_26 ( V_82 , & V_78 [ V_79 ] ) ;
V_87 = F_26 ( V_83 , & V_78 [ V_79 ] ) ;
if ( ! V_88 && ! V_87 )
return 0 ;
if ( ! V_88 || ! V_87 )
return V_88 ? - 1 : 1 ;
return F_39 ( V_88 , V_87 , V_84 ) ;
}
static void F_41 ( struct V_70 * V_71 ,
struct V_24 * V_25 ,
int V_84 )
{
struct V_72 * * V_89 = & V_71 -> V_72 ;
struct V_72 * V_90 = NULL ;
struct V_24 * V_91 ;
while ( * V_89 != NULL ) {
V_90 = * V_89 ;
V_91 = F_32 ( V_90 , struct V_24 , V_72 ) ;
if ( F_40 ( V_25 , V_91 , V_84 ) < 0 )
V_89 = & ( * V_89 ) -> V_92 ;
else
V_89 = & ( * V_89 ) -> V_93 ;
}
F_42 ( & V_25 -> V_72 , V_90 , V_89 ) ;
F_43 ( & V_25 -> V_72 , V_71 ) ;
}
static void F_44 ( struct V_28 * V_28 )
{
struct V_70 * V_71 ;
struct V_72 * V_73 ;
if ( V_74 )
V_71 = & V_28 -> V_75 ;
else
V_71 = V_28 -> V_76 ;
V_28 -> V_94 = V_95 ;
V_73 = F_31 ( V_71 ) ;
V_28 -> V_96 = 0 ;
V_28 -> V_29 . V_30 = 0 ;
F_45 ( V_28 ) ;
while ( V_73 != NULL ) {
struct V_24 * V_25 ;
V_25 = F_32 ( V_73 , struct V_24 , V_77 ) ;
V_73 = F_33 ( & V_25 -> V_77 ) ;
F_41 ( & V_28 -> V_94 , V_25 , V_10 ) ;
F_46 ( V_28 , V_25 ) ;
}
}
static void F_47 ( struct V_28 * V_28 )
{
if ( V_97 )
F_30 ( V_28 ) ;
if ( V_79 ) {
F_37 ( V_28 ) ;
F_44 ( V_28 ) ;
} else {
F_48 ( V_28 ) ;
}
F_49 ( V_28 , true , 0 , 0 , 0 , stdout ) ;
}
static void F_50 ( void )
{
struct V_63 * V_64 ;
int V_19 ;
fprintf ( stdout , L_18 ) ;
F_51 (i, d)
fprintf ( stdout , L_19 ,
V_64 -> V_68 , V_64 -> V_98 ,
! V_64 -> V_68 ? L_20 : L_21 ) ;
fprintf ( stdout , L_22 ) ;
}
static void F_52 ( void )
{
struct V_60 * V_99 = V_78 [ 0 ] . V_100 -> V_61 ;
struct V_55 * V_101 ;
bool V_102 = true ;
F_22 (evsel_base, &evlist_base->entries, node) {
struct V_63 * V_64 ;
int V_19 ;
F_53 (i, d) {
struct V_60 * V_61 = V_64 -> V_100 -> V_61 ;
struct V_55 * V_56 ;
V_56 = F_21 ( V_101 , V_61 ) ;
if ( ! V_56 )
continue;
V_64 -> V_28 = & V_56 -> V_28 ;
F_54 ( & V_101 -> V_28 , & V_56 -> V_28 ) ;
if ( ! V_97 )
F_55 ( & V_101 -> V_28 ,
& V_56 -> V_28 ) ;
}
fprintf ( stdout , L_23 , V_102 ? L_21 : L_24 ,
F_56 ( V_101 ) ) ;
V_102 = false ;
if ( V_103 || V_104 > 2 )
F_50 () ;
F_47 ( & V_101 -> V_28 ) ;
}
}
static void F_57 ( struct V_63 * V_64 )
{
int V_105 ;
for ( V_105 = 0 ; V_105 < V_106 ; V_105 ++ ) {
struct V_65 * V_69 = & V_64 -> V_69 [ V_105 ] ;
free ( V_69 -> V_58 ) ;
}
}
static int F_58 ( void )
{
struct V_63 * V_64 ;
int V_4 = - V_5 , V_19 ;
F_51 (i, d) {
V_64 -> V_100 = F_59 ( V_64 -> V_98 , V_107 , V_108 ,
false , & T_5 ) ;
if ( ! V_64 -> V_100 ) {
F_3 ( L_25 , V_64 -> V_98 ) ;
V_4 = - V_49 ;
goto V_109;
}
V_4 = F_60 ( V_64 -> V_100 , & T_5 ) ;
if ( V_4 ) {
F_3 ( L_26 , V_64 -> V_98 ) ;
goto V_109;
}
F_24 ( V_64 -> V_100 -> V_61 ) ;
}
F_52 () ;
V_109:
F_51 (i, d) {
if ( V_64 -> V_100 )
F_61 ( V_64 -> V_100 ) ;
F_57 ( V_64 ) ;
}
free ( V_78 ) ;
return V_4 ;
}
static double F_62 ( struct V_24 * V_25 )
{
struct V_28 * V_28 = V_25 -> V_28 ;
return 100.0 * V_25 -> V_33 . V_26 / V_28 -> V_29 . V_30 ;
}
static int F_63 ( struct V_110 * V_69 ,
struct V_111 * V_112 , struct V_24 * V_25 )
{
struct V_65 * V_66 =
F_29 ( V_69 , struct V_65 , V_69 ) ;
double V_113 = F_62 ( V_25 ) ;
char V_114 [ 20 ] = L_27 ;
if ( ! V_25 -> V_115 ) {
F_11 ( V_114 , 20 , L_28 , V_66 -> V_116 - 1 ) ;
return F_64 ( V_112 -> V_18 , V_112 -> V_42 ,
V_114 , V_113 ) ;
} else
return F_11 ( V_112 -> V_18 , V_112 -> V_42 , L_29 ,
V_66 -> V_116 , V_114 ) ;
}
static int F_65 ( struct V_24 * V_25 , char * V_18 , T_4 V_42 )
{
double V_113 = F_62 ( V_25 ) ;
const char * V_69 = V_117 . V_118 ? L_30 : L_31 ;
int V_4 = 0 ;
if ( ! V_25 -> V_115 )
V_4 = F_11 ( V_18 , V_42 , V_69 , V_113 ) ;
return V_4 ;
}
static void
F_66 ( struct V_24 * V_25 , int V_68 , char * V_18 , T_4 V_42 )
{
switch ( V_68 ) {
case V_119 :
F_11 ( V_18 , V_42 , L_14 V_43 , V_25 -> V_33 . V_26 ) ;
break;
default:
break;
}
}
static void
F_67 ( struct V_24 * V_25 , struct V_24 * V_31 ,
int V_68 , char * V_18 , T_4 V_42 )
{
double V_35 ;
double V_120 ;
T_3 V_41 ;
switch ( V_68 ) {
case V_121 :
if ( V_31 -> V_35 . V_37 )
V_35 = V_31 -> V_35 . V_36 ;
else
V_35 = F_7 ( V_25 , V_31 ) ;
if ( fabs ( V_35 ) >= 0.01 )
F_11 ( V_18 , V_42 , L_32 , V_35 ) ;
break;
case V_122 :
if ( V_25 -> V_115 )
break;
if ( V_31 -> V_35 . V_37 )
V_120 = V_31 -> V_35 . V_40 ;
else
V_120 = F_8 ( V_25 , V_31 ) ;
if ( V_120 > 0.0 )
F_11 ( V_18 , V_42 , L_33 , V_120 ) ;
break;
case V_123 :
if ( V_25 -> V_115 )
break;
if ( V_31 -> V_35 . V_37 )
V_41 = V_31 -> V_35 . V_41 ;
else
V_41 = F_9 ( V_25 , V_31 ) ;
if ( V_41 != 0 )
F_11 ( V_18 , V_42 , L_34 , V_41 ) ;
break;
case V_124 :
F_14 ( V_25 , V_31 , V_18 , V_42 ) ;
break;
case V_125 :
F_11 ( V_18 , V_42 , L_14 V_43 , V_31 -> V_33 . V_26 ) ;
break;
default:
F_15 ( 1 ) ;
} ;
}
static void
F_68 ( struct V_24 * V_25 , struct V_65 * V_66 ,
char * V_18 , T_4 V_42 )
{
struct V_24 * V_31 = F_28 ( V_25 , V_66 ) ;
int V_68 = V_66 -> V_68 ;
if ( V_68 == V_126 )
F_65 ( V_25 , V_18 , V_42 ) ;
else {
if ( V_31 )
F_67 ( V_25 , V_31 , V_68 , V_18 , V_42 ) ;
else
F_66 ( V_25 , V_68 , V_18 , V_42 ) ;
}
}
static int F_69 ( struct V_110 * V_127 , struct V_111 * V_112 ,
struct V_24 * V_25 )
{
struct V_65 * V_66 =
F_29 ( V_127 , struct V_65 , V_69 ) ;
char V_18 [ V_128 ] = L_27 ;
F_68 ( V_25 , V_66 , V_18 , V_128 ) ;
if ( V_117 . V_118 )
return F_11 ( V_112 -> V_18 , V_112 -> V_42 , L_35 , V_18 ) ;
else
return F_11 ( V_112 -> V_18 , V_112 -> V_42 , L_29 ,
V_66 -> V_116 , V_18 ) ;
}
static int F_70 ( struct V_110 * V_69 ,
struct V_111 * V_112 )
{
struct V_65 * V_66 =
F_29 ( V_69 , struct V_65 , V_69 ) ;
F_15 ( ! V_66 -> V_58 ) ;
return F_11 ( V_112 -> V_18 , V_112 -> V_42 , V_66 -> V_58 ) ;
}
static int F_71 ( struct V_110 * V_69 ,
struct V_111 * V_112 V_14 )
{
struct V_65 * V_66 =
F_29 ( V_69 , struct V_65 , V_69 ) ;
F_15 ( V_66 -> V_116 <= 0 ) ;
return V_66 -> V_116 ;
}
static void F_72 ( struct V_63 * V_64 , struct V_65 * V_66 )
{
#define F_73 100
char V_129 [ F_73 ] ;
char V_18 [ F_73 ] ;
const char * V_58 = NULL ;
int V_130 = 0 ;
F_15 ( V_66 -> V_68 >= V_106 ) ;
V_58 = V_131 [ V_66 -> V_68 ] . V_132 ;
V_130 = V_131 [ V_66 -> V_68 ] . V_130 ;
F_15 ( ! V_58 ) ;
if ( V_104 > 2 )
F_11 ( V_18 , F_73 , L_36 , V_58 , V_64 -> V_68 ) ;
#define F_74 (data__files_cnt > 2 ? buf : header)
V_66 -> V_116 = V_130 ;
V_130 = ( int ) strlen ( F_74 ) ;
if ( V_66 -> V_116 < V_130 )
V_66 -> V_116 = V_130 ;
F_11 ( V_129 , F_73 , L_29 ,
V_66 -> V_116 , F_74 ) ;
V_66 -> V_58 = F_75 ( V_129 ) ;
#undef F_73
#undef F_74
}
static void F_76 ( struct V_63 * V_64 , int V_68 )
{
struct V_65 * V_66 = & V_64 -> V_69 [ V_68 ] ;
struct V_110 * V_69 = & V_66 -> V_69 ;
V_66 -> V_68 = V_68 ;
V_69 -> V_58 = F_70 ;
V_69 -> V_130 = F_71 ;
V_69 -> V_133 = F_69 ;
if ( V_68 == V_126 )
V_69 -> V_134 = F_63 ;
F_72 ( V_64 , V_66 ) ;
F_77 ( V_69 ) ;
}
static void F_78 ( void )
{
struct V_63 * V_64 ;
int V_19 ;
F_51 (i, d) {
F_76 ( V_64 , V_19 ? V_135 [ V_10 ] :
V_126 ) ;
if ( V_136 && V_19 )
F_76 ( V_64 , V_124 ) ;
if ( V_137 )
F_76 ( V_64 , V_19 ? V_125 :
V_119 ) ;
}
}
static int F_79 ( int V_138 , const char * * V_139 )
{
struct V_63 * V_64 ;
static const char * V_140 [] = {
L_37 ,
L_38 ,
} ;
bool V_141 = true ;
int V_19 ;
V_104 = 2 ;
if ( V_138 ) {
if ( V_138 == 1 )
V_140 [ 1 ] = V_139 [ 0 ] ;
else {
V_104 = V_138 ;
V_141 = false ;
}
} else if ( V_117 . V_142 ||
V_117 . V_143 ) {
V_140 [ 0 ] = L_39 ;
V_140 [ 1 ] = L_40 ;
}
if ( V_79 >= ( unsigned int ) V_104 ) {
F_3 ( L_41 ) ;
return - V_5 ;
}
V_78 = F_80 ( sizeof( * V_78 ) * V_104 ) ;
if ( ! V_78 )
return - V_49 ;
F_51 (i, d) {
V_64 -> V_98 = V_141 ? V_140 [ V_19 ] : V_139 [ V_19 ] ;
V_64 -> V_68 = V_19 ;
}
return 0 ;
}
int F_81 ( int V_138 , const char * * V_139 , const char * T_7 V_14 )
{
V_144 = V_145 ;
V_138 = F_82 ( V_138 , V_139 , V_146 , V_147 , 0 ) ;
if ( F_83 () < 0 )
return - 1 ;
if ( F_79 ( V_138 , V_139 ) < 0 )
return - 1 ;
F_78 () ;
if ( F_84 () < 0 )
F_85 ( V_147 , V_146 ) ;
F_86 () ;
F_87 ( NULL ) ;
return F_58 () ;
}
