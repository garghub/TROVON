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
static int F_16 ( struct V_28 * V_28 ,
struct V_45 * V_46 , T_2 V_26 ,
T_2 V_47 , T_2 V_48 )
{
if ( F_17 ( V_28 , V_46 , NULL , NULL , NULL , V_26 , V_47 ,
V_48 ) != NULL )
return 0 ;
return - V_49 ;
}
static int F_18 ( struct V_50 * T_5 V_14 ,
union V_51 * V_52 ,
struct V_53 * V_54 ,
struct V_55 * V_56 ,
struct V_57 * V_57 )
{
struct V_45 V_46 ;
if ( F_19 ( V_52 , V_57 , & V_46 , V_54 ) < 0 ) {
F_20 ( L_16 ,
V_52 -> V_58 . type ) ;
return - 1 ;
}
if ( V_46 . V_59 )
return 0 ;
if ( F_16 ( & V_56 -> V_28 , & V_46 , V_54 -> V_26 ,
V_54 -> V_47 , V_54 -> V_48 ) ) {
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
F_22 (evlist, e) {
if ( F_23 ( V_56 , V_62 ) )
return V_62 ;
}
return NULL ;
}
static void F_24 ( struct V_60 * V_61 )
{
struct V_55 * V_56 ;
F_22 (evlist, evsel) {
struct V_28 * V_28 = & V_56 -> V_28 ;
F_25 ( V_28 , NULL ) ;
}
}
static struct V_24 *
F_26 ( struct V_24 * V_25 , struct V_63 * V_64 )
{
if ( F_27 ( V_25 ) ) {
struct V_24 * V_31 ;
F_28 (pair, &he->pairs.head, pairs.node)
if ( V_31 -> V_28 == V_64 -> V_28 )
return V_31 ;
}
return NULL ;
}
static struct V_24 *
F_29 ( struct V_24 * V_25 , struct V_65 * V_66 )
{
void * V_67 = V_66 - V_66 -> V_68 ;
struct V_63 * V_64 = F_30 ( V_67 , struct V_63 , V_69 ) ;
return F_26 ( V_25 , V_64 ) ;
}
static void F_31 ( struct V_28 * V_28 )
{
struct V_70 * V_71 ;
struct V_72 * V_73 ;
if ( V_74 )
V_71 = & V_28 -> V_75 ;
else
V_71 = V_28 -> V_76 ;
V_73 = F_32 ( V_71 ) ;
while ( V_73 != NULL ) {
struct V_24 * V_25 = F_33 ( V_73 , struct V_24 , V_77 ) ;
V_73 = F_34 ( & V_25 -> V_77 ) ;
if ( ! F_35 ( V_25 ) ) {
F_36 ( & V_25 -> V_77 , V_71 ) ;
F_37 ( V_25 ) ;
}
}
}
static void F_38 ( struct V_28 * V_28 )
{
struct V_70 * V_71 ;
struct V_72 * V_73 ;
if ( V_74 )
V_71 = & V_28 -> V_75 ;
else
V_71 = V_28 -> V_76 ;
V_73 = F_32 ( V_71 ) ;
while ( V_73 != NULL ) {
struct V_24 * V_25 , * V_31 ;
V_25 = F_33 ( V_73 , struct V_24 , V_77 ) ;
V_73 = F_34 ( & V_25 -> V_77 ) ;
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
static T_6 F_39 ( double V_80 , double V_81 )
{
if ( V_80 > V_81 )
return - 1 ;
else if ( V_80 < V_81 )
return 1 ;
else
return 0 ;
}
static T_6
F_40 ( struct V_24 * V_82 , struct V_24 * V_83 ,
int V_84 )
{
switch ( V_84 ) {
case V_20 :
{
double V_80 = V_82 -> V_35 . V_36 ;
double V_81 = V_83 -> V_35 . V_36 ;
return F_39 ( V_80 , V_81 ) ;
}
case V_44 :
{
double V_80 = V_82 -> V_35 . V_40 ;
double V_81 = V_83 -> V_35 . V_40 ;
return F_39 ( V_80 , V_81 ) ;
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
F_41 ( struct V_24 * V_82 , struct V_24 * V_83 ,
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
return F_40 ( V_88 , V_87 , V_84 ) ;
}
static void F_42 ( struct V_70 * V_71 ,
struct V_24 * V_25 ,
int V_84 )
{
struct V_72 * * V_89 = & V_71 -> V_72 ;
struct V_72 * V_90 = NULL ;
struct V_24 * V_91 ;
while ( * V_89 != NULL ) {
V_90 = * V_89 ;
V_91 = F_33 ( V_90 , struct V_24 , V_72 ) ;
if ( F_41 ( V_25 , V_91 , V_84 ) < 0 )
V_89 = & ( * V_89 ) -> V_92 ;
else
V_89 = & ( * V_89 ) -> V_93 ;
}
F_43 ( & V_25 -> V_72 , V_90 , V_89 ) ;
F_44 ( & V_25 -> V_72 , V_71 ) ;
}
static void F_45 ( struct V_28 * V_28 )
{
struct V_70 * V_71 ;
struct V_72 * V_73 ;
if ( V_74 )
V_71 = & V_28 -> V_75 ;
else
V_71 = V_28 -> V_76 ;
V_28 -> V_94 = V_95 ;
V_73 = F_32 ( V_71 ) ;
V_28 -> V_96 = 0 ;
V_28 -> V_29 . V_30 = 0 ;
F_46 ( V_28 ) ;
while ( V_73 != NULL ) {
struct V_24 * V_25 ;
V_25 = F_33 ( V_73 , struct V_24 , V_77 ) ;
V_73 = F_34 ( & V_25 -> V_77 ) ;
F_42 ( & V_28 -> V_94 , V_25 , V_10 ) ;
F_47 ( V_28 , V_25 ) ;
}
}
static void F_48 ( struct V_28 * V_28 )
{
if ( V_97 )
F_31 ( V_28 ) ;
if ( V_79 ) {
F_38 ( V_28 ) ;
F_45 ( V_28 ) ;
} else {
F_49 ( V_28 ) ;
}
F_50 ( V_28 , true , 0 , 0 , 0 , stdout ) ;
}
static void F_51 ( void )
{
struct V_63 * V_64 ;
int V_19 ;
fprintf ( stdout , L_18 ) ;
F_52 (i, d)
fprintf ( stdout , L_19 ,
V_64 -> V_68 , V_64 -> V_98 . V_99 ,
! V_64 -> V_68 ? L_20 : L_21 ) ;
fprintf ( stdout , L_22 ) ;
}
static void F_53 ( void )
{
struct V_60 * V_100 = V_78 [ 0 ] . V_101 -> V_61 ;
struct V_55 * V_102 ;
bool V_103 = true ;
F_22 (evlist_base, evsel_base) {
struct V_63 * V_64 ;
int V_19 ;
F_54 (i, d) {
struct V_60 * V_61 = V_64 -> V_101 -> V_61 ;
struct V_55 * V_56 ;
V_56 = F_21 ( V_102 , V_61 ) ;
if ( ! V_56 )
continue;
V_64 -> V_28 = & V_56 -> V_28 ;
F_55 ( & V_102 -> V_28 , & V_56 -> V_28 ) ;
if ( ! V_97 )
F_56 ( & V_102 -> V_28 ,
& V_56 -> V_28 ) ;
}
fprintf ( stdout , L_23 , V_103 ? L_21 : L_24 ,
F_57 ( V_102 ) ) ;
V_103 = false ;
if ( V_104 || V_105 > 2 )
F_51 () ;
F_48 ( & V_102 -> V_28 ) ;
}
}
static void F_58 ( struct V_63 * V_64 )
{
int V_106 ;
for ( V_106 = 0 ; V_106 < V_107 ; V_106 ++ ) {
struct V_65 * V_69 = & V_64 -> V_69 [ V_106 ] ;
F_59 ( & V_69 -> V_58 ) ;
}
}
static int F_60 ( void )
{
struct V_63 * V_64 ;
int V_4 = - V_5 , V_19 ;
F_52 (i, d) {
V_64 -> V_101 = F_61 ( & V_64 -> V_98 , false , & T_5 ) ;
if ( ! V_64 -> V_101 ) {
F_3 ( L_25 , V_64 -> V_98 . V_99 ) ;
V_4 = - V_49 ;
goto V_108;
}
V_4 = F_62 ( V_64 -> V_101 , & T_5 ) ;
if ( V_4 ) {
F_3 ( L_26 , V_64 -> V_98 . V_99 ) ;
goto V_108;
}
F_24 ( V_64 -> V_101 -> V_61 ) ;
}
F_53 () ;
V_108:
F_52 (i, d) {
if ( V_64 -> V_101 )
F_63 ( V_64 -> V_101 ) ;
F_58 ( V_64 ) ;
}
free ( V_78 ) ;
return V_4 ;
}
static double F_64 ( struct V_24 * V_25 )
{
struct V_28 * V_28 = V_25 -> V_28 ;
return 100.0 * V_25 -> V_33 . V_26 / V_28 -> V_29 . V_30 ;
}
static int F_65 ( struct V_109 * V_69 ,
struct V_110 * V_111 , struct V_24 * V_25 )
{
struct V_65 * V_66 =
F_30 ( V_69 , struct V_65 , V_69 ) ;
double V_112 = F_64 ( V_25 ) ;
char V_113 [ 20 ] = L_27 ;
if ( ! V_25 -> V_114 ) {
F_11 ( V_113 , 20 , L_28 , V_66 -> V_115 - 1 ) ;
return F_66 ( V_111 -> V_18 , V_111 -> V_42 ,
V_113 , V_112 ) ;
} else
return F_11 ( V_111 -> V_18 , V_111 -> V_42 , L_29 ,
V_66 -> V_115 , V_113 ) ;
}
static int F_67 ( struct V_24 * V_25 , char * V_18 , T_4 V_42 )
{
double V_112 = F_64 ( V_25 ) ;
const char * V_69 = V_116 . V_117 ? L_30 : L_31 ;
int V_4 = 0 ;
if ( ! V_25 -> V_114 )
V_4 = F_11 ( V_18 , V_42 , V_69 , V_112 ) ;
return V_4 ;
}
static int F_68 ( struct V_109 * V_69 ,
struct V_110 * V_111 , struct V_24 * V_25 ,
int V_118 )
{
struct V_65 * V_66 =
F_30 ( V_69 , struct V_65 , V_69 ) ;
struct V_24 * V_31 = F_29 ( V_25 , V_66 ) ;
double V_35 ;
T_3 V_41 ;
char V_113 [ 20 ] = L_27 ;
if ( ! V_31 )
goto V_119;
switch ( V_118 ) {
case V_20 :
if ( V_31 -> V_35 . V_37 )
V_35 = V_31 -> V_35 . V_36 ;
else
V_35 = F_7 ( V_25 , V_31 ) ;
if ( fabs ( V_35 ) < 0.01 )
goto V_119;
F_11 ( V_113 , 20 , L_32 , V_66 -> V_115 - 1 ) ;
return F_66 ( V_111 -> V_18 , V_111 -> V_42 ,
V_113 , V_35 ) ;
case V_44 :
if ( V_25 -> V_114 )
goto V_119;
if ( V_31 -> V_35 . V_37 )
V_35 = V_31 -> V_35 . V_40 ;
else
V_35 = F_8 ( V_25 , V_31 ) ;
F_11 ( V_113 , 20 , L_33 , V_66 -> V_115 ) ;
return F_69 ( V_111 -> V_18 , V_111 -> V_42 ,
V_113 , V_35 ) ;
case V_11 :
if ( V_25 -> V_114 )
goto V_119;
if ( V_31 -> V_35 . V_37 )
V_41 = V_31 -> V_35 . V_41 ;
else
V_41 = F_9 ( V_25 , V_31 ) ;
F_11 ( V_113 , 20 , L_34 , V_66 -> V_115 ) ;
return F_70 ( V_111 -> V_18 , V_111 -> V_42 ,
F_71 ( V_41 ) ,
V_113 , V_41 ) ;
default:
F_15 ( 1 ) ;
}
V_119:
return F_11 ( V_111 -> V_18 , V_111 -> V_42 , L_29 ,
V_66 -> V_115 , V_113 ) ;
}
static int F_72 ( struct V_109 * V_69 ,
struct V_110 * V_111 , struct V_24 * V_25 )
{
return F_68 ( V_69 , V_111 , V_25 , V_20 ) ;
}
static int F_73 ( struct V_109 * V_69 ,
struct V_110 * V_111 , struct V_24 * V_25 )
{
return F_68 ( V_69 , V_111 , V_25 , V_44 ) ;
}
static int F_74 ( struct V_109 * V_69 ,
struct V_110 * V_111 , struct V_24 * V_25 )
{
return F_68 ( V_69 , V_111 , V_25 , V_11 ) ;
}
static void
F_75 ( struct V_24 * V_25 , int V_68 , char * V_18 , T_4 V_42 )
{
switch ( V_68 ) {
case V_120 :
F_11 ( V_18 , V_42 , L_14 V_43 , V_25 -> V_33 . V_26 ) ;
break;
default:
break;
}
}
static void
F_76 ( struct V_24 * V_25 , struct V_24 * V_31 ,
int V_68 , char * V_18 , T_4 V_42 )
{
double V_35 ;
double V_121 ;
T_3 V_41 ;
switch ( V_68 ) {
case V_122 :
if ( V_31 -> V_35 . V_37 )
V_35 = V_31 -> V_35 . V_36 ;
else
V_35 = F_7 ( V_25 , V_31 ) ;
if ( fabs ( V_35 ) >= 0.01 )
F_11 ( V_18 , V_42 , L_35 , V_35 ) ;
break;
case V_123 :
if ( V_25 -> V_114 )
break;
if ( V_31 -> V_35 . V_37 )
V_121 = V_31 -> V_35 . V_40 ;
else
V_121 = F_8 ( V_25 , V_31 ) ;
if ( V_121 > 0.0 )
F_11 ( V_18 , V_42 , L_36 , V_121 ) ;
break;
case V_124 :
if ( V_25 -> V_114 )
break;
if ( V_31 -> V_35 . V_37 )
V_41 = V_31 -> V_35 . V_41 ;
else
V_41 = F_9 ( V_25 , V_31 ) ;
if ( V_41 != 0 )
F_11 ( V_18 , V_42 , L_37 , V_41 ) ;
break;
case V_125 :
F_14 ( V_25 , V_31 , V_18 , V_42 ) ;
break;
case V_126 :
F_11 ( V_18 , V_42 , L_14 V_43 , V_31 -> V_33 . V_26 ) ;
break;
default:
F_15 ( 1 ) ;
} ;
}
static void
F_77 ( struct V_24 * V_25 , struct V_65 * V_66 ,
char * V_18 , T_4 V_42 )
{
struct V_24 * V_31 = F_29 ( V_25 , V_66 ) ;
int V_68 = V_66 -> V_68 ;
if ( V_68 == V_127 )
F_67 ( V_25 , V_18 , V_42 ) ;
else {
if ( V_31 )
F_76 ( V_25 , V_31 , V_68 , V_18 , V_42 ) ;
else
F_75 ( V_25 , V_68 , V_18 , V_42 ) ;
}
}
static int F_78 ( struct V_109 * V_128 , struct V_110 * V_111 ,
struct V_24 * V_25 )
{
struct V_65 * V_66 =
F_30 ( V_128 , struct V_65 , V_69 ) ;
char V_18 [ V_129 ] = L_27 ;
F_77 ( V_25 , V_66 , V_18 , V_129 ) ;
if ( V_116 . V_117 )
return F_11 ( V_111 -> V_18 , V_111 -> V_42 , L_38 , V_18 ) ;
else
return F_11 ( V_111 -> V_18 , V_111 -> V_42 , L_29 ,
V_66 -> V_115 , V_18 ) ;
}
static int F_79 ( struct V_109 * V_69 ,
struct V_110 * V_111 )
{
struct V_65 * V_66 =
F_30 ( V_69 , struct V_65 , V_69 ) ;
F_15 ( ! V_66 -> V_58 ) ;
return F_11 ( V_111 -> V_18 , V_111 -> V_42 , V_66 -> V_58 ) ;
}
static int F_80 ( struct V_109 * V_69 ,
struct V_110 * V_111 V_14 )
{
struct V_65 * V_66 =
F_30 ( V_69 , struct V_65 , V_69 ) ;
F_15 ( V_66 -> V_115 <= 0 ) ;
return V_66 -> V_115 ;
}
static void F_81 ( struct V_63 * V_64 , struct V_65 * V_66 )
{
#define F_82 100
char V_130 [ F_82 ] ;
char V_18 [ F_82 ] ;
const char * V_58 = NULL ;
int V_131 = 0 ;
F_15 ( V_66 -> V_68 >= V_107 ) ;
V_58 = V_132 [ V_66 -> V_68 ] . V_133 ;
V_131 = V_132 [ V_66 -> V_68 ] . V_131 ;
F_15 ( ! V_58 ) ;
if ( V_105 > 2 )
F_11 ( V_18 , F_82 , L_39 , V_58 , V_64 -> V_68 ) ;
#define F_83 (data__files_cnt > 2 ? buf : header)
V_66 -> V_115 = V_131 ;
V_131 = ( int ) strlen ( F_83 ) ;
if ( V_66 -> V_115 < V_131 )
V_66 -> V_115 = V_131 ;
F_11 ( V_130 , F_82 , L_29 ,
V_66 -> V_115 , F_83 ) ;
V_66 -> V_58 = F_84 ( V_130 ) ;
#undef F_82
#undef F_83
}
static void F_85 ( struct V_63 * V_64 , int V_68 )
{
struct V_65 * V_66 = & V_64 -> V_69 [ V_68 ] ;
struct V_109 * V_69 = & V_66 -> V_69 ;
V_66 -> V_68 = V_68 ;
V_69 -> V_58 = F_79 ;
V_69 -> V_131 = F_80 ;
V_69 -> V_134 = F_78 ;
switch ( V_68 ) {
case V_127 :
V_69 -> V_135 = F_65 ;
break;
case V_122 :
V_69 -> V_135 = F_72 ;
break;
case V_123 :
V_69 -> V_135 = F_73 ;
break;
case V_124 :
V_69 -> V_135 = F_74 ;
break;
default:
break;
}
F_81 ( V_64 , V_66 ) ;
F_86 ( V_69 ) ;
}
static void F_87 ( void )
{
struct V_63 * V_64 ;
int V_19 ;
F_52 (i, d) {
F_85 ( V_64 , V_19 ? V_136 [ V_10 ] :
V_127 ) ;
if ( V_137 && V_19 )
F_85 ( V_64 , V_125 ) ;
if ( V_138 )
F_85 ( V_64 , V_19 ? V_126 :
V_120 ) ;
}
}
static int F_88 ( int V_139 , const char * * V_140 )
{
struct V_63 * V_64 ;
static const char * V_141 [] = {
L_40 ,
L_41 ,
} ;
bool V_142 = true ;
int V_19 ;
V_105 = 2 ;
if ( V_139 ) {
if ( V_139 == 1 )
V_141 [ 1 ] = V_140 [ 0 ] ;
else {
V_105 = V_139 ;
V_142 = false ;
}
} else if ( V_143 ) {
V_141 [ 0 ] = L_42 ;
V_141 [ 1 ] = L_43 ;
}
if ( V_79 >= ( unsigned int ) V_105 ) {
F_3 ( L_44 ) ;
return - V_5 ;
}
V_78 = F_89 ( sizeof( * V_78 ) * V_105 ) ;
if ( ! V_78 )
return - V_49 ;
F_52 (i, d) {
struct V_144 * V_98 = & V_64 -> V_98 ;
V_98 -> V_99 = V_142 ? V_141 [ V_19 ] : V_140 [ V_19 ] ;
V_98 -> V_145 = V_146 ,
V_98 -> V_147 = V_147 ,
V_64 -> V_68 = V_19 ;
}
return 0 ;
}
int F_90 ( int V_139 , const char * * V_140 , const char * T_7 V_14 )
{
V_148 = V_149 ;
V_139 = F_91 ( V_139 , V_140 , V_150 , V_151 , 0 ) ;
if ( F_92 () < 0 )
return - 1 ;
if ( F_88 ( V_139 , V_140 ) < 0 )
return - 1 ;
F_87 () ;
if ( F_93 () < 0 )
F_94 ( V_151 , V_150 ) ;
F_95 () ;
F_96 ( NULL ) ;
return F_60 () ;
}
