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
T_2 V_27 = F_7 ( V_25 -> V_28 ) ;
return ( V_26 * 100.0 ) / V_27 ;
}
static double F_8 ( struct V_24 * V_25 , struct V_24 * V_29 )
{
double V_30 = F_6 ( V_25 , V_25 -> V_31 . V_26 ) ;
double V_32 = F_6 ( V_29 , V_29 -> V_31 . V_26 ) ;
V_29 -> V_33 . V_34 = V_32 - V_30 ;
V_29 -> V_33 . V_35 = true ;
return V_29 -> V_33 . V_34 ;
}
static double F_9 ( struct V_24 * V_25 , struct V_24 * V_29 )
{
double V_36 = V_25 -> V_31 . V_26 ? : 1 ;
double V_37 = V_29 -> V_31 . V_26 ;
V_29 -> V_33 . V_35 = true ;
V_29 -> V_33 . V_38 = V_37 / V_36 ;
return V_29 -> V_33 . V_38 ;
}
static T_3 F_10 ( struct V_24 * V_25 , struct V_24 * V_29 )
{
T_2 V_36 = V_25 -> V_31 . V_26 ;
T_2 V_37 = V_29 -> V_31 . V_26 ;
V_29 -> V_33 . V_35 = true ;
V_29 -> V_33 . V_39 = V_37 * V_8 -
V_36 * V_7 ;
return V_29 -> V_33 . V_39 ;
}
static int F_11 ( struct V_24 * V_25 , struct V_24 * V_29 ,
char * V_18 , T_4 V_40 )
{
T_2 V_41 = V_25 -> V_28 -> V_42 . V_43 ;
T_2 V_44 = V_29 -> V_28 -> V_42 . V_43 ;
if ( V_45 . V_46 ) {
V_41 = V_25 -> V_28 -> V_42 . V_47 ;
V_44 = V_29 -> V_28 -> V_42 . V_47 ;
}
return F_12 ( V_18 , V_40 ,
L_8 V_48 L_9 V_48 L_10
L_8 V_48 L_9 V_48 L_11 ,
V_29 -> V_31 . V_26 , V_44 ,
V_25 -> V_31 . V_26 , V_41 ) ;
}
static int F_13 ( struct V_24 * V_25 , struct V_24 * V_29 ,
char * V_18 , T_4 V_40 )
{
double V_36 = V_25 -> V_31 . V_26 ;
double V_37 = V_29 -> V_31 . V_26 ;
return F_12 ( V_18 , V_40 , L_12 , V_37 , V_36 ) ;
}
static int F_14 ( struct V_24 * V_25 , struct V_24 * V_29 ,
char * V_18 , T_4 V_40 )
{
T_2 V_36 = V_25 -> V_31 . V_26 ;
T_2 V_37 = V_29 -> V_31 . V_26 ;
return F_12 ( V_18 , V_40 ,
L_8 V_48 L_13 L_14 V_9 L_15 V_48 L_13 L_14 V_9 L_11 ,
V_37 , V_8 , V_36 , V_7 ) ;
}
static int F_15 ( struct V_24 * V_25 , struct V_24 * V_29 ,
char * V_18 , T_4 V_40 )
{
switch ( V_10 ) {
case V_20 :
case V_49 :
return F_11 ( V_25 , V_29 , V_18 , V_40 ) ;
case V_50 :
return F_13 ( V_25 , V_29 , V_18 , V_40 ) ;
case V_11 :
return F_14 ( V_25 , V_29 , V_18 , V_40 ) ;
default:
F_16 ( 1 ) ;
}
return - 1 ;
}
static int F_17 ( struct V_51 * T_5 V_14 ,
union V_52 * V_53 ,
struct V_54 * V_55 ,
struct V_56 * V_57 ,
struct V_58 * V_58 )
{
struct V_59 V_60 ;
struct V_28 * V_28 = F_18 ( V_57 ) ;
int V_4 = - 1 ;
if ( F_19 ( V_58 , & V_60 , V_55 ) < 0 ) {
F_20 ( L_16 ,
V_53 -> V_61 . type ) ;
return - 1 ;
}
if ( ! F_21 ( V_28 , & V_60 , NULL , NULL , NULL , V_55 , true ) ) {
F_20 ( L_17 ) ;
goto V_62;
}
V_28 -> V_42 . V_43 += V_55 -> V_26 ;
if ( ! V_60 . V_63 )
V_28 -> V_42 . V_47 += V_55 -> V_26 ;
V_4 = 0 ;
V_62:
F_22 ( & V_60 ) ;
return V_4 ;
}
static struct V_56 * F_23 ( struct V_56 * V_57 ,
struct V_64 * V_65 )
{
struct V_56 * V_66 ;
F_24 (evlist, e) {
if ( F_25 ( V_57 , V_66 ) )
return V_66 ;
}
return NULL ;
}
static void F_26 ( struct V_64 * V_65 )
{
struct V_56 * V_57 ;
F_24 (evlist, evsel) {
struct V_28 * V_28 = F_18 ( V_57 ) ;
F_27 ( V_28 , NULL ) ;
}
}
static struct V_67 * F_28 ( struct V_68 * V_69 )
{
struct V_70 * V_71 = F_29 ( V_69 , struct V_70 , V_69 ) ;
void * V_72 = V_71 - V_71 -> V_73 ;
struct V_67 * V_74 = F_29 ( V_72 , struct V_67 , V_69 ) ;
return V_74 ;
}
static struct V_24 *
F_30 ( struct V_24 * V_25 , struct V_67 * V_74 )
{
if ( F_31 ( V_25 ) ) {
struct V_24 * V_29 ;
F_32 (pair, &he->pairs.head, pairs.node)
if ( V_29 -> V_28 == V_74 -> V_28 )
return V_29 ;
}
return NULL ;
}
static struct V_24 *
F_33 ( struct V_24 * V_25 , struct V_70 * V_71 )
{
struct V_67 * V_74 = F_28 ( & V_71 -> V_69 ) ;
return F_30 ( V_25 , V_74 ) ;
}
static void F_34 ( struct V_28 * V_28 )
{
struct V_75 * V_76 ;
struct V_77 * V_78 ;
if ( F_35 ( V_28 , V_79 ) )
V_76 = & V_28 -> V_80 ;
else
V_76 = V_28 -> V_81 ;
V_78 = F_36 ( V_76 ) ;
while ( V_78 != NULL ) {
struct V_24 * V_25 = F_37 ( V_78 , struct V_24 , V_82 ) ;
V_78 = F_38 ( & V_25 -> V_82 ) ;
if ( ! F_39 ( V_25 ) ) {
F_40 ( & V_25 -> V_82 , V_76 ) ;
F_41 ( V_25 ) ;
}
}
}
static void F_42 ( struct V_28 * V_28 )
{
struct V_75 * V_76 ;
struct V_77 * V_78 ;
if ( F_35 ( V_28 , V_79 ) )
V_76 = & V_28 -> V_80 ;
else
V_76 = V_28 -> V_81 ;
V_78 = F_36 ( V_76 ) ;
while ( V_78 != NULL ) {
struct V_24 * V_25 , * V_29 ;
struct V_67 * V_74 ;
int V_19 ;
V_25 = F_37 ( V_78 , struct V_24 , V_82 ) ;
V_78 = F_38 ( & V_25 -> V_82 ) ;
F_43 (i, d) {
V_29 = F_30 ( V_25 , V_74 ) ;
if ( ! V_29 )
continue;
switch ( V_10 ) {
case V_20 :
case V_49 :
F_8 ( V_25 , V_29 ) ;
break;
case V_50 :
F_9 ( V_25 , V_29 ) ;
break;
case V_11 :
F_10 ( V_25 , V_29 ) ;
break;
default:
F_16 ( 1 ) ;
}
}
}
}
static T_6 F_44 ( double V_83 , double V_84 )
{
if ( V_83 > V_84 )
return - 1 ;
else if ( V_83 < V_84 )
return 1 ;
else
return 0 ;
}
static T_6
F_45 ( struct V_24 * V_85 , struct V_24 * V_86 ,
int V_87 )
{
switch ( V_87 ) {
case V_20 :
{
double V_83 = V_85 -> V_33 . V_34 ;
double V_84 = V_86 -> V_33 . V_34 ;
return F_44 ( V_83 , V_84 ) ;
}
case V_49 :
{
double V_83 = fabs ( V_85 -> V_33 . V_34 ) ;
double V_84 = fabs ( V_86 -> V_33 . V_34 ) ;
return F_44 ( V_83 , V_84 ) ;
}
case V_50 :
{
double V_83 = V_85 -> V_33 . V_38 ;
double V_84 = V_86 -> V_33 . V_38 ;
return F_44 ( V_83 , V_84 ) ;
}
case V_11 :
{
T_3 V_83 = V_85 -> V_33 . V_39 ;
T_3 V_84 = V_86 -> V_33 . V_39 ;
return V_84 - V_83 ;
}
default:
F_16 ( 1 ) ;
}
return 0 ;
}
static T_6
F_46 ( struct V_24 * V_85 , struct V_24 * V_86 ,
int V_87 , int V_88 )
{
bool V_89 = F_31 ( V_85 ) ;
bool V_90 = F_31 ( V_86 ) ;
struct V_24 * V_91 , * V_92 ;
if ( ! V_89 && ! V_90 )
return 0 ;
if ( ! V_89 || ! V_90 )
return V_89 ? - 1 : 1 ;
V_92 = F_30 ( V_85 , & V_93 [ V_88 ] ) ;
V_91 = F_30 ( V_86 , & V_93 [ V_88 ] ) ;
if ( ! V_92 && ! V_91 )
return 0 ;
if ( ! V_92 || ! V_91 )
return V_92 ? - 1 : 1 ;
return F_45 ( V_92 , V_91 , V_87 ) ;
}
static T_6
F_47 ( struct V_24 * V_85 , struct V_24 * V_86 ,
int V_87 , int V_88 )
{
struct V_24 * V_91 , * V_92 ;
V_92 = F_30 ( V_85 , & V_93 [ V_88 ] ) ;
V_91 = F_30 ( V_86 , & V_93 [ V_88 ] ) ;
if ( ! V_92 && ! V_91 )
return 0 ;
if ( ! V_92 || ! V_91 )
return V_92 ? - 1 : 1 ;
if ( V_87 != V_20 && V_87 != V_49 ) {
if ( V_85 -> V_94 && V_86 -> V_94 )
return 0 ;
if ( V_85 -> V_94 || V_86 -> V_94 )
return V_85 -> V_94 ? 1 : - 1 ;
}
return F_45 ( V_92 , V_91 , V_87 ) ;
}
static T_6
F_48 ( struct V_68 * V_69 V_14 ,
struct V_24 * V_85 V_14 ,
struct V_24 * V_86 V_14 )
{
return 0 ;
}
static T_6
F_49 ( struct V_68 * V_69 V_14 ,
struct V_24 * V_85 , struct V_24 * V_86 )
{
if ( V_85 -> V_31 . V_26 == V_86 -> V_31 . V_26 )
return 0 ;
return V_85 -> V_31 . V_26 > V_86 -> V_31 . V_26 ? 1 : - 1 ;
}
static T_6
F_50 ( struct V_68 * V_69 ,
struct V_24 * V_85 , struct V_24 * V_86 )
{
struct V_67 * V_74 = F_28 ( V_69 ) ;
return F_46 ( V_86 , V_85 , V_20 , V_74 -> V_73 ) ;
}
static T_6
F_51 ( struct V_68 * V_69 ,
struct V_24 * V_85 , struct V_24 * V_86 )
{
struct V_67 * V_74 = F_28 ( V_69 ) ;
return F_46 ( V_86 , V_85 , V_49 , V_74 -> V_73 ) ;
}
static T_6
F_52 ( struct V_68 * V_69 ,
struct V_24 * V_85 , struct V_24 * V_86 )
{
struct V_67 * V_74 = F_28 ( V_69 ) ;
return F_46 ( V_86 , V_85 , V_50 , V_74 -> V_73 ) ;
}
static T_6
F_53 ( struct V_68 * V_69 ,
struct V_24 * V_85 , struct V_24 * V_86 )
{
struct V_67 * V_74 = F_28 ( V_69 ) ;
return F_46 ( V_86 , V_85 , V_11 , V_74 -> V_73 ) ;
}
static T_6
F_54 ( struct V_68 * V_69 V_14 ,
struct V_24 * V_85 , struct V_24 * V_86 )
{
return F_47 ( V_86 , V_85 , V_20 ,
V_95 ) ;
}
static T_6
F_55 ( struct V_68 * V_69 V_14 ,
struct V_24 * V_85 , struct V_24 * V_86 )
{
return F_47 ( V_86 , V_85 , V_49 ,
V_95 ) ;
}
static T_6
F_56 ( struct V_68 * V_69 V_14 ,
struct V_24 * V_85 , struct V_24 * V_86 )
{
return F_47 ( V_86 , V_85 , V_50 ,
V_95 ) ;
}
static T_6
F_57 ( struct V_68 * V_69 V_14 ,
struct V_24 * V_85 , struct V_24 * V_86 )
{
return F_47 ( V_86 , V_85 , V_11 ,
V_95 ) ;
}
static void F_58 ( struct V_28 * V_28 )
{
if ( V_96 )
F_34 ( V_28 ) ;
F_42 ( V_28 ) ;
F_59 ( V_28 , NULL ) ;
F_60 ( V_28 , ! V_97 , 0 , 0 , 0 , stdout ,
V_45 . V_98 ) ;
}
static void F_61 ( void )
{
struct V_67 * V_74 ;
int V_19 ;
fprintf ( stdout , L_18 ) ;
F_62 (i, d)
fprintf ( stdout , L_19 ,
V_74 -> V_73 , V_74 -> V_99 . V_100 ,
! V_74 -> V_73 ? L_20 : L_21 ) ;
fprintf ( stdout , L_22 ) ;
}
static void F_63 ( void )
{
struct V_64 * V_101 = V_93 [ 0 ] . V_102 -> V_65 ;
struct V_56 * V_103 ;
bool V_104 = true ;
F_24 (evlist_base, evsel_base) {
struct V_28 * V_105 = F_18 ( V_103 ) ;
struct V_67 * V_74 ;
int V_19 ;
F_43 (i, d) {
struct V_64 * V_65 = V_74 -> V_102 -> V_65 ;
struct V_56 * V_57 ;
struct V_28 * V_28 ;
V_57 = F_23 ( V_103 , V_65 ) ;
if ( ! V_57 )
continue;
V_28 = F_18 ( V_57 ) ;
V_74 -> V_28 = V_28 ;
F_64 ( V_105 , V_28 ) ;
if ( ! V_96 )
F_65 ( V_105 , V_28 ) ;
}
if ( ! V_97 ) {
fprintf ( stdout , L_23 , V_104 ? L_21 : L_24 ,
F_66 ( V_103 ) ) ;
}
V_104 = false ;
if ( V_106 > 0 || ( ( V_107 > 2 ) && ! V_97 ) )
F_61 () ;
F_67 ( V_103 , V_108 ) ;
F_58 ( V_105 ) ;
}
}
static void F_68 ( struct V_67 * V_74 )
{
int V_109 ;
for ( V_109 = 0 ; V_109 < V_110 ; V_109 ++ ) {
struct V_70 * V_69 = & V_74 -> V_69 [ V_109 ] ;
F_69 ( & V_69 -> V_61 ) ;
}
}
static int F_70 ( void )
{
struct V_67 * V_74 ;
int V_4 = - V_5 , V_19 ;
F_62 (i, d) {
V_74 -> V_102 = F_71 ( & V_74 -> V_99 , false , & T_5 ) ;
if ( ! V_74 -> V_102 ) {
F_3 ( L_25 , V_74 -> V_99 . V_100 ) ;
V_4 = - 1 ;
goto V_111;
}
V_4 = F_72 ( V_74 -> V_102 ) ;
if ( V_4 ) {
F_3 ( L_26 , V_74 -> V_99 . V_100 ) ;
goto V_111;
}
F_26 ( V_74 -> V_102 -> V_65 ) ;
}
F_63 () ;
V_111:
F_62 (i, d) {
F_73 ( V_74 -> V_102 ) ;
F_68 ( V_74 ) ;
}
free ( V_93 ) ;
return V_4 ;
}
static double F_74 ( struct V_24 * V_25 )
{
T_2 V_27 = F_7 ( V_25 -> V_28 ) ;
return 100.0 * V_25 -> V_31 . V_26 / V_27 ;
}
static int F_75 ( struct V_68 * V_69 ,
struct V_112 * V_113 , struct V_24 * V_25 )
{
struct V_70 * V_71 =
F_29 ( V_69 , struct V_70 , V_69 ) ;
double V_114 = F_74 ( V_25 ) ;
char V_115 [ 20 ] = L_27 ;
if ( ! V_25 -> V_94 ) {
F_12 ( V_115 , 20 , L_28 , V_71 -> V_116 - 1 ) ;
return F_76 ( V_113 -> V_18 , V_113 -> V_40 ,
V_115 , V_114 ) ;
} else
return F_12 ( V_113 -> V_18 , V_113 -> V_40 , L_29 ,
V_71 -> V_116 , V_115 ) ;
}
static int F_77 ( struct V_24 * V_25 , char * V_18 , T_4 V_40 )
{
double V_114 = F_74 ( V_25 ) ;
const char * V_69 = V_45 . V_117 ? L_30 : L_31 ;
int V_4 = 0 ;
if ( ! V_25 -> V_94 )
V_4 = F_12 ( V_18 , V_40 , V_69 , V_114 ) ;
return V_4 ;
}
static int F_78 ( struct V_68 * V_69 ,
struct V_112 * V_113 , struct V_24 * V_25 ,
int V_118 )
{
struct V_70 * V_71 =
F_29 ( V_69 , struct V_70 , V_69 ) ;
struct V_24 * V_29 = F_33 ( V_25 , V_71 ) ;
double V_33 ;
T_3 V_39 ;
char V_115 [ 20 ] = L_27 ;
if ( ! V_29 )
goto V_119;
switch ( V_118 ) {
case V_20 :
if ( V_29 -> V_33 . V_35 )
V_33 = V_29 -> V_33 . V_34 ;
else
V_33 = F_8 ( V_25 , V_29 ) ;
F_12 ( V_115 , 20 , L_32 , V_71 -> V_116 - 1 ) ;
return F_76 ( V_113 -> V_18 , V_113 -> V_40 ,
V_115 , V_33 ) ;
case V_50 :
if ( V_25 -> V_94 )
goto V_120;
if ( V_29 -> V_33 . V_35 )
V_33 = V_29 -> V_33 . V_38 ;
else
V_33 = F_9 ( V_25 , V_29 ) ;
F_12 ( V_115 , 20 , L_33 , V_71 -> V_116 ) ;
return F_79 ( V_113 -> V_18 , V_113 -> V_40 ,
V_115 , V_33 ) ;
case V_11 :
if ( V_25 -> V_94 )
goto V_120;
if ( V_29 -> V_33 . V_35 )
V_39 = V_29 -> V_33 . V_39 ;
else
V_39 = F_10 ( V_25 , V_29 ) ;
F_12 ( V_115 , 20 , L_34 , V_71 -> V_116 ) ;
return F_80 ( V_113 -> V_18 , V_113 -> V_40 ,
F_81 ( V_39 ) ,
V_115 , V_39 ) ;
default:
F_16 ( 1 ) ;
}
V_120:
return F_12 ( V_113 -> V_18 , V_113 -> V_40 , L_29 ,
V_71 -> V_116 , L_35 ) ;
V_119:
return F_12 ( V_113 -> V_18 , V_113 -> V_40 , L_29 ,
V_71 -> V_116 , V_115 ) ;
}
static int F_82 ( struct V_68 * V_69 ,
struct V_112 * V_113 , struct V_24 * V_25 )
{
return F_78 ( V_69 , V_113 , V_25 , V_20 ) ;
}
static int F_83 ( struct V_68 * V_69 ,
struct V_112 * V_113 , struct V_24 * V_25 )
{
return F_78 ( V_69 , V_113 , V_25 , V_50 ) ;
}
static int F_84 ( struct V_68 * V_69 ,
struct V_112 * V_113 , struct V_24 * V_25 )
{
return F_78 ( V_69 , V_113 , V_25 , V_11 ) ;
}
static void
F_85 ( struct V_24 * V_25 , int V_73 , char * V_18 , T_4 V_40 )
{
switch ( V_73 ) {
case V_121 :
F_12 ( V_18 , V_40 , L_14 V_48 , V_25 -> V_31 . V_26 ) ;
break;
default:
break;
}
}
static void
F_86 ( struct V_24 * V_25 , struct V_24 * V_29 ,
int V_73 , char * V_18 , T_4 V_40 )
{
double V_33 ;
double V_122 ;
T_3 V_39 ;
switch ( V_73 ) {
case V_123 :
case V_124 :
if ( V_29 -> V_33 . V_35 )
V_33 = V_29 -> V_33 . V_34 ;
else
V_33 = F_8 ( V_25 , V_29 ) ;
F_12 ( V_18 , V_40 , L_36 , V_33 ) ;
break;
case V_125 :
if ( V_25 -> V_94 ) {
F_12 ( V_18 , V_40 , L_35 ) ;
break;
}
if ( V_29 -> V_33 . V_35 )
V_122 = V_29 -> V_33 . V_38 ;
else
V_122 = F_9 ( V_25 , V_29 ) ;
if ( V_122 > 0.0 )
F_12 ( V_18 , V_40 , L_37 , V_122 ) ;
break;
case V_126 :
if ( V_25 -> V_94 ) {
F_12 ( V_18 , V_40 , L_35 ) ;
break;
}
if ( V_29 -> V_33 . V_35 )
V_39 = V_29 -> V_33 . V_39 ;
else
V_39 = F_10 ( V_25 , V_29 ) ;
if ( V_39 != 0 )
F_12 ( V_18 , V_40 , L_38 , V_39 ) ;
break;
case V_127 :
F_15 ( V_25 , V_29 , V_18 , V_40 ) ;
break;
case V_128 :
F_12 ( V_18 , V_40 , L_14 V_48 , V_29 -> V_31 . V_26 ) ;
break;
default:
F_16 ( 1 ) ;
} ;
}
static void
F_87 ( struct V_24 * V_25 , struct V_70 * V_71 ,
char * V_18 , T_4 V_40 )
{
struct V_24 * V_29 = F_33 ( V_25 , V_71 ) ;
int V_73 = V_71 -> V_73 ;
if ( V_73 == V_129 )
F_77 ( V_25 , V_18 , V_40 ) ;
else {
if ( V_29 )
F_86 ( V_25 , V_29 , V_73 , V_18 , V_40 ) ;
else
F_85 ( V_25 , V_73 , V_18 , V_40 ) ;
}
}
static int F_88 ( struct V_68 * V_130 , struct V_112 * V_113 ,
struct V_24 * V_25 )
{
struct V_70 * V_71 =
F_29 ( V_130 , struct V_70 , V_69 ) ;
char V_18 [ V_131 ] = L_27 ;
F_87 ( V_25 , V_71 , V_18 , V_131 ) ;
if ( V_45 . V_117 )
return F_12 ( V_113 -> V_18 , V_113 -> V_40 , L_39 , V_18 ) ;
else
return F_12 ( V_113 -> V_18 , V_113 -> V_40 , L_29 ,
V_71 -> V_116 , V_18 ) ;
}
static int F_89 ( struct V_68 * V_69 , struct V_112 * V_113 ,
struct V_28 * V_28 V_14 ,
int line V_14 ,
int * T_7 V_14 )
{
struct V_70 * V_71 =
F_29 ( V_69 , struct V_70 , V_69 ) ;
F_16 ( ! V_71 -> V_61 ) ;
return F_12 ( V_113 -> V_18 , V_113 -> V_40 , V_71 -> V_61 ) ;
}
static int F_90 ( struct V_68 * V_69 ,
struct V_112 * V_113 V_14 ,
struct V_28 * V_28 V_14 )
{
struct V_70 * V_71 =
F_29 ( V_69 , struct V_70 , V_69 ) ;
F_16 ( V_71 -> V_116 <= 0 ) ;
return V_71 -> V_116 ;
}
static void F_91 ( struct V_67 * V_74 , struct V_70 * V_71 )
{
#define F_92 100
char V_132 [ F_92 ] ;
char V_18 [ F_92 ] ;
const char * V_61 = NULL ;
int V_133 = 0 ;
F_16 ( V_71 -> V_73 >= V_110 ) ;
V_61 = V_134 [ V_71 -> V_73 ] . V_135 ;
V_133 = V_134 [ V_71 -> V_73 ] . V_133 ;
F_16 ( ! V_61 ) ;
if ( V_107 > 2 )
F_12 ( V_18 , F_92 , L_40 , V_61 , V_74 -> V_73 ) ;
#define F_93 (data__files_cnt > 2 ? buf : header)
V_71 -> V_116 = V_133 ;
V_133 = ( int ) strlen ( F_93 ) ;
if ( V_71 -> V_116 < V_133 )
V_71 -> V_116 = V_133 ;
F_12 ( V_132 , F_92 , L_29 ,
V_71 -> V_116 , F_93 ) ;
V_71 -> V_61 = F_94 ( V_132 ) ;
#undef F_92
#undef F_93
}
static void F_95 ( struct V_67 * V_74 , int V_73 )
{
struct V_70 * V_71 = & V_74 -> V_69 [ V_73 ] ;
struct V_68 * V_69 = & V_71 -> V_69 ;
V_71 -> V_73 = V_73 ;
V_69 -> V_61 = F_89 ;
V_69 -> V_133 = F_90 ;
V_69 -> V_136 = F_88 ;
V_69 -> V_137 = F_48 ;
V_69 -> V_138 = F_48 ;
switch ( V_73 ) {
case V_129 :
V_69 -> V_139 = F_75 ;
V_69 -> V_140 = F_49 ;
break;
case V_123 :
V_69 -> V_139 = F_82 ;
V_69 -> V_140 = F_50 ;
break;
case V_125 :
V_69 -> V_139 = F_83 ;
V_69 -> V_140 = F_52 ;
break;
case V_126 :
V_69 -> V_139 = F_84 ;
V_69 -> V_140 = F_53 ;
break;
case V_124 :
V_69 -> V_139 = F_82 ;
V_69 -> V_140 = F_51 ;
break;
default:
V_69 -> V_140 = F_48 ;
break;
}
F_91 ( V_74 , V_71 ) ;
F_96 ( V_69 ) ;
F_97 ( V_69 ) ;
}
static int F_98 ( void )
{
struct V_67 * V_74 ;
struct V_68 * V_69 ;
int V_19 ;
F_62 (i, d) {
F_95 ( V_74 , V_19 ? V_141 [ V_10 ] :
V_129 ) ;
if ( V_142 && V_19 )
F_95 ( V_74 , V_127 ) ;
if ( V_143 )
F_95 ( V_74 , V_19 ? V_128 :
V_121 ) ;
}
if ( ! V_95 )
return 0 ;
V_69 = F_99 ( sizeof( * V_69 ) ) ;
if ( V_69 == NULL ) {
F_3 ( L_41 ) ;
return - 1 ;
}
V_69 -> V_137 = F_48 ;
V_69 -> V_138 = F_48 ;
switch ( V_10 ) {
case V_20 :
V_69 -> V_140 = F_54 ;
break;
case V_50 :
V_69 -> V_140 = F_56 ;
break;
case V_11 :
V_69 -> V_140 = F_57 ;
break;
case V_49 :
V_69 -> V_140 = F_55 ;
break;
default:
F_16 ( 1 ) ;
}
F_100 ( V_69 ) ;
return 0 ;
}
static int F_101 ( int V_144 , const char * * V_145 )
{
struct V_67 * V_74 ;
static const char * V_146 [] = {
L_42 ,
L_43 ,
} ;
bool V_147 = true ;
int V_19 ;
V_107 = 2 ;
if ( V_144 ) {
if ( V_144 == 1 )
V_146 [ 1 ] = V_145 [ 0 ] ;
else {
V_107 = V_144 ;
V_147 = false ;
}
} else if ( V_148 ) {
V_146 [ 0 ] = L_44 ;
V_146 [ 1 ] = L_45 ;
}
if ( V_95 >= ( unsigned int ) V_107 ) {
F_3 ( L_46 ) ;
return - V_5 ;
}
V_93 = F_99 ( sizeof( * V_93 ) * V_107 ) ;
if ( ! V_93 )
return - V_149 ;
F_62 (i, d) {
struct V_150 * V_99 = & V_74 -> V_99 ;
V_99 -> V_100 = V_147 ? V_146 [ V_19 ] : V_145 [ V_19 ] ;
V_99 -> V_151 = V_152 ,
V_99 -> V_153 = V_153 ,
V_74 -> V_73 = V_19 ;
}
return 0 ;
}
static int F_102 ( const char * V_154 , const char * V_16 ,
void * T_8 V_14 )
{
if ( ! strcmp ( V_154 , L_47 ) ) {
V_95 = F_103 ( V_154 , V_16 ) ;
return 0 ;
}
if ( ! strcmp ( V_154 , L_48 ) ) {
if ( ! strcmp ( V_16 , L_49 ) ) {
V_10 = V_20 ;
} else if ( ! strcmp ( V_16 , L_50 ) ) {
V_10 = V_49 ;
} else if ( ! strcmp ( V_16 , L_51 ) ) {
V_10 = V_50 ;
} else if ( ! strcmp ( V_16 , L_52 ) ) {
V_10 = V_11 ;
} else {
F_3 ( L_53 , V_16 ) ;
return - 1 ;
}
}
return 0 ;
}
int F_104 ( int V_144 , const char * * V_145 , const char * T_9 V_14 )
{
int V_4 = F_105 () ;
if ( V_4 < 0 )
return V_4 ;
F_106 ( F_102 , NULL ) ;
V_144 = F_107 ( V_144 , V_145 , V_155 , V_156 , 0 ) ;
if ( V_97 )
F_108 () ;
if ( F_109 ( NULL ) < 0 )
return - 1 ;
if ( F_101 ( V_144 , V_145 ) < 0 )
return - 1 ;
if ( F_98 () < 0 )
return - 1 ;
V_157 = V_158 ;
if ( F_110 ( NULL ) < 0 )
F_111 ( V_156 , V_155 ) ;
F_112 () ;
F_113 ( NULL ) ;
return F_70 () ;
}
