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
return F_11 ( V_25 , V_29 , V_18 , V_40 ) ;
case V_49 :
return F_13 ( V_25 , V_29 , V_18 , V_40 ) ;
case V_11 :
return F_14 ( V_25 , V_29 , V_18 , V_40 ) ;
default:
F_16 ( 1 ) ;
}
return - 1 ;
}
static int F_17 ( struct V_28 * V_28 ,
struct V_50 * V_51 , T_2 V_26 ,
T_2 V_52 , T_2 V_53 )
{
if ( F_18 ( V_28 , V_51 , NULL , NULL , NULL , V_26 , V_52 ,
V_53 , true ) != NULL )
return 0 ;
return - V_54 ;
}
static int F_19 ( struct V_55 * T_5 V_14 ,
union V_56 * V_57 ,
struct V_58 * V_59 ,
struct V_60 * V_61 ,
struct V_62 * V_62 )
{
struct V_50 V_51 ;
struct V_28 * V_28 = F_20 ( V_61 ) ;
int V_4 = - 1 ;
if ( F_21 ( V_57 , V_62 , & V_51 , V_59 ) < 0 ) {
F_22 ( L_16 ,
V_57 -> V_63 . type ) ;
return - 1 ;
}
if ( F_17 ( V_28 , & V_51 , V_59 -> V_26 ,
V_59 -> V_52 , V_59 -> V_53 ) ) {
F_22 ( L_17 ) ;
goto V_64;
}
V_28 -> V_42 . V_43 += V_59 -> V_26 ;
if ( ! V_51 . V_65 )
V_28 -> V_42 . V_47 += V_59 -> V_26 ;
V_4 = 0 ;
V_64:
F_23 ( & V_51 ) ;
return V_4 ;
}
static struct V_60 * F_24 ( struct V_60 * V_61 ,
struct V_66 * V_67 )
{
struct V_60 * V_68 ;
F_25 (evlist, e) {
if ( F_26 ( V_61 , V_68 ) )
return V_68 ;
}
return NULL ;
}
static void F_27 ( struct V_66 * V_67 )
{
struct V_60 * V_61 ;
F_25 (evlist, evsel) {
struct V_28 * V_28 = F_20 ( V_61 ) ;
F_28 ( V_28 , NULL ) ;
}
}
static struct V_69 * F_29 ( struct V_70 * V_71 )
{
struct V_72 * V_73 = F_30 ( V_71 , struct V_72 , V_71 ) ;
void * V_74 = V_73 - V_73 -> V_75 ;
struct V_69 * V_76 = F_30 ( V_74 , struct V_69 , V_71 ) ;
return V_76 ;
}
static struct V_24 *
F_31 ( struct V_24 * V_25 , struct V_69 * V_76 )
{
if ( F_32 ( V_25 ) ) {
struct V_24 * V_29 ;
F_33 (pair, &he->pairs.head, pairs.node)
if ( V_29 -> V_28 == V_76 -> V_28 )
return V_29 ;
}
return NULL ;
}
static struct V_24 *
F_34 ( struct V_24 * V_25 , struct V_72 * V_73 )
{
struct V_69 * V_76 = F_29 ( & V_73 -> V_71 ) ;
return F_31 ( V_25 , V_76 ) ;
}
static void F_35 ( struct V_28 * V_28 )
{
struct V_77 * V_78 ;
struct V_79 * V_80 ;
if ( V_81 )
V_78 = & V_28 -> V_82 ;
else
V_78 = V_28 -> V_83 ;
V_80 = F_36 ( V_78 ) ;
while ( V_80 != NULL ) {
struct V_24 * V_25 = F_37 ( V_80 , struct V_24 , V_84 ) ;
V_80 = F_38 ( & V_25 -> V_84 ) ;
if ( ! F_39 ( V_25 ) ) {
F_40 ( & V_25 -> V_84 , V_78 ) ;
F_41 ( V_25 ) ;
}
}
}
static void F_42 ( struct V_28 * V_28 )
{
struct V_77 * V_78 ;
struct V_79 * V_80 ;
if ( V_81 )
V_78 = & V_28 -> V_82 ;
else
V_78 = V_28 -> V_83 ;
V_80 = F_36 ( V_78 ) ;
while ( V_80 != NULL ) {
struct V_24 * V_25 , * V_29 ;
struct V_69 * V_76 ;
int V_19 ;
V_25 = F_37 ( V_80 , struct V_24 , V_84 ) ;
V_80 = F_38 ( & V_25 -> V_84 ) ;
F_43 (i, d) {
V_29 = F_31 ( V_25 , V_76 ) ;
if ( ! V_29 )
continue;
switch ( V_10 ) {
case V_20 :
F_8 ( V_25 , V_29 ) ;
break;
case V_49 :
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
static T_6 F_44 ( double V_85 , double V_86 )
{
if ( V_85 > V_86 )
return - 1 ;
else if ( V_85 < V_86 )
return 1 ;
else
return 0 ;
}
static T_6
F_45 ( struct V_24 * V_87 , struct V_24 * V_88 ,
int V_89 )
{
switch ( V_89 ) {
case V_20 :
{
double V_85 = V_87 -> V_33 . V_34 ;
double V_86 = V_88 -> V_33 . V_34 ;
return F_44 ( V_85 , V_86 ) ;
}
case V_49 :
{
double V_85 = V_87 -> V_33 . V_38 ;
double V_86 = V_88 -> V_33 . V_38 ;
return F_44 ( V_85 , V_86 ) ;
}
case V_11 :
{
T_3 V_85 = V_87 -> V_33 . V_39 ;
T_3 V_86 = V_88 -> V_33 . V_39 ;
return V_86 - V_85 ;
}
default:
F_16 ( 1 ) ;
}
return 0 ;
}
static T_6
F_46 ( struct V_24 * V_87 , struct V_24 * V_88 ,
int V_89 , int V_90 )
{
bool V_91 = F_32 ( V_87 ) ;
bool V_92 = F_32 ( V_88 ) ;
struct V_24 * V_93 , * V_94 ;
if ( ! V_91 && ! V_92 )
return 0 ;
if ( ! V_91 || ! V_92 )
return V_91 ? - 1 : 1 ;
V_94 = F_31 ( V_87 , & V_95 [ V_90 ] ) ;
V_93 = F_31 ( V_88 , & V_95 [ V_90 ] ) ;
if ( ! V_94 && ! V_93 )
return 0 ;
if ( ! V_94 || ! V_93 )
return V_94 ? - 1 : 1 ;
return F_45 ( V_94 , V_93 , V_89 ) ;
}
static T_6
F_47 ( struct V_24 * V_87 , struct V_24 * V_88 ,
int V_89 , int V_90 )
{
struct V_24 * V_93 , * V_94 ;
V_94 = F_31 ( V_87 , & V_95 [ V_90 ] ) ;
V_93 = F_31 ( V_88 , & V_95 [ V_90 ] ) ;
if ( ! V_94 && ! V_93 )
return 0 ;
if ( ! V_94 || ! V_93 )
return V_94 ? - 1 : 1 ;
if ( V_89 != V_20 ) {
if ( V_87 -> V_96 && V_88 -> V_96 )
return 0 ;
if ( V_87 -> V_96 || V_88 -> V_96 )
return V_87 -> V_96 ? 1 : - 1 ;
}
return F_45 ( V_94 , V_93 , V_89 ) ;
}
static T_6
F_48 ( struct V_70 * V_71 V_14 ,
struct V_24 * V_87 V_14 ,
struct V_24 * V_88 V_14 )
{
return 0 ;
}
static T_6
F_49 ( struct V_70 * V_71 V_14 ,
struct V_24 * V_87 , struct V_24 * V_88 )
{
if ( V_87 -> V_31 . V_26 == V_88 -> V_31 . V_26 )
return 0 ;
return V_87 -> V_31 . V_26 > V_88 -> V_31 . V_26 ? 1 : - 1 ;
}
static T_6
F_50 ( struct V_70 * V_71 ,
struct V_24 * V_87 , struct V_24 * V_88 )
{
struct V_69 * V_76 = F_29 ( V_71 ) ;
return F_46 ( V_88 , V_87 , V_20 , V_76 -> V_75 ) ;
}
static T_6
F_51 ( struct V_70 * V_71 ,
struct V_24 * V_87 , struct V_24 * V_88 )
{
struct V_69 * V_76 = F_29 ( V_71 ) ;
return F_46 ( V_88 , V_87 , V_49 , V_76 -> V_75 ) ;
}
static T_6
F_52 ( struct V_70 * V_71 ,
struct V_24 * V_87 , struct V_24 * V_88 )
{
struct V_69 * V_76 = F_29 ( V_71 ) ;
return F_46 ( V_88 , V_87 , V_11 , V_76 -> V_75 ) ;
}
static T_6
F_53 ( struct V_70 * V_71 V_14 ,
struct V_24 * V_87 , struct V_24 * V_88 )
{
return F_47 ( V_88 , V_87 , V_20 ,
V_97 ) ;
}
static T_6
F_54 ( struct V_70 * V_71 V_14 ,
struct V_24 * V_87 , struct V_24 * V_88 )
{
return F_47 ( V_88 , V_87 , V_49 ,
V_97 ) ;
}
static T_6
F_55 ( struct V_70 * V_71 V_14 ,
struct V_24 * V_87 , struct V_24 * V_88 )
{
return F_47 ( V_88 , V_87 , V_11 ,
V_97 ) ;
}
static void F_56 ( struct V_28 * V_28 )
{
if ( V_98 )
F_35 ( V_28 ) ;
F_42 ( V_28 ) ;
F_57 ( V_28 , NULL ) ;
F_58 ( V_28 , true , 0 , 0 , 0 , stdout ) ;
}
static void F_59 ( void )
{
struct V_69 * V_76 ;
int V_19 ;
fprintf ( stdout , L_18 ) ;
F_60 (i, d)
fprintf ( stdout , L_19 ,
V_76 -> V_75 , V_76 -> V_99 . V_100 ,
! V_76 -> V_75 ? L_20 : L_21 ) ;
fprintf ( stdout , L_22 ) ;
}
static void F_61 ( void )
{
struct V_66 * V_101 = V_95 [ 0 ] . V_102 -> V_67 ;
struct V_60 * V_103 ;
bool V_104 = true ;
F_25 (evlist_base, evsel_base) {
struct V_28 * V_105 = F_20 ( V_103 ) ;
struct V_69 * V_76 ;
int V_19 ;
F_43 (i, d) {
struct V_66 * V_67 = V_76 -> V_102 -> V_67 ;
struct V_60 * V_61 ;
struct V_28 * V_28 ;
V_61 = F_24 ( V_103 , V_67 ) ;
if ( ! V_61 )
continue;
V_28 = F_20 ( V_61 ) ;
V_76 -> V_28 = V_28 ;
F_62 ( V_105 , V_28 ) ;
if ( ! V_98 )
F_63 ( V_105 , V_28 ) ;
}
fprintf ( stdout , L_23 , V_104 ? L_21 : L_24 ,
F_64 ( V_103 ) ) ;
V_104 = false ;
if ( V_106 || V_107 > 2 )
F_59 () ;
F_65 ( V_103 , V_108 ) ;
F_56 ( V_105 ) ;
}
}
static void F_66 ( struct V_69 * V_76 )
{
int V_109 ;
for ( V_109 = 0 ; V_109 < V_110 ; V_109 ++ ) {
struct V_72 * V_71 = & V_76 -> V_71 [ V_109 ] ;
F_67 ( & V_71 -> V_63 ) ;
}
}
static int F_68 ( void )
{
struct V_69 * V_76 ;
int V_4 = - V_5 , V_19 ;
F_60 (i, d) {
V_76 -> V_102 = F_69 ( & V_76 -> V_99 , false , & T_5 ) ;
if ( ! V_76 -> V_102 ) {
F_3 ( L_25 , V_76 -> V_99 . V_100 ) ;
V_4 = - 1 ;
goto V_111;
}
V_4 = F_70 ( V_76 -> V_102 ) ;
if ( V_4 ) {
F_3 ( L_26 , V_76 -> V_99 . V_100 ) ;
goto V_111;
}
F_27 ( V_76 -> V_102 -> V_67 ) ;
}
F_61 () ;
V_111:
F_60 (i, d) {
if ( V_76 -> V_102 )
F_71 ( V_76 -> V_102 ) ;
F_66 ( V_76 ) ;
}
free ( V_95 ) ;
return V_4 ;
}
static double F_72 ( struct V_24 * V_25 )
{
T_2 V_27 = F_7 ( V_25 -> V_28 ) ;
return 100.0 * V_25 -> V_31 . V_26 / V_27 ;
}
static int F_73 ( struct V_70 * V_71 ,
struct V_112 * V_113 , struct V_24 * V_25 )
{
struct V_72 * V_73 =
F_30 ( V_71 , struct V_72 , V_71 ) ;
double V_114 = F_72 ( V_25 ) ;
char V_115 [ 20 ] = L_27 ;
if ( ! V_25 -> V_96 ) {
F_12 ( V_115 , 20 , L_28 , V_73 -> V_116 - 1 ) ;
return F_74 ( V_113 -> V_18 , V_113 -> V_40 ,
V_115 , V_114 ) ;
} else
return F_12 ( V_113 -> V_18 , V_113 -> V_40 , L_29 ,
V_73 -> V_116 , V_115 ) ;
}
static int F_75 ( struct V_24 * V_25 , char * V_18 , T_4 V_40 )
{
double V_114 = F_72 ( V_25 ) ;
const char * V_71 = V_45 . V_117 ? L_30 : L_31 ;
int V_4 = 0 ;
if ( ! V_25 -> V_96 )
V_4 = F_12 ( V_18 , V_40 , V_71 , V_114 ) ;
return V_4 ;
}
static int F_76 ( struct V_70 * V_71 ,
struct V_112 * V_113 , struct V_24 * V_25 ,
int V_118 )
{
struct V_72 * V_73 =
F_30 ( V_71 , struct V_72 , V_71 ) ;
struct V_24 * V_29 = F_34 ( V_25 , V_73 ) ;
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
F_12 ( V_115 , 20 , L_32 , V_73 -> V_116 - 1 ) ;
return F_74 ( V_113 -> V_18 , V_113 -> V_40 ,
V_115 , V_33 ) ;
case V_49 :
if ( V_25 -> V_96 )
goto V_120;
if ( V_29 -> V_33 . V_35 )
V_33 = V_29 -> V_33 . V_38 ;
else
V_33 = F_9 ( V_25 , V_29 ) ;
F_12 ( V_115 , 20 , L_33 , V_73 -> V_116 ) ;
return F_77 ( V_113 -> V_18 , V_113 -> V_40 ,
V_115 , V_33 ) ;
case V_11 :
if ( V_25 -> V_96 )
goto V_120;
if ( V_29 -> V_33 . V_35 )
V_39 = V_29 -> V_33 . V_39 ;
else
V_39 = F_10 ( V_25 , V_29 ) ;
F_12 ( V_115 , 20 , L_34 , V_73 -> V_116 ) ;
return F_78 ( V_113 -> V_18 , V_113 -> V_40 ,
F_79 ( V_39 ) ,
V_115 , V_39 ) ;
default:
F_16 ( 1 ) ;
}
V_120:
return F_12 ( V_113 -> V_18 , V_113 -> V_40 , L_29 ,
V_73 -> V_116 , L_35 ) ;
V_119:
return F_12 ( V_113 -> V_18 , V_113 -> V_40 , L_29 ,
V_73 -> V_116 , V_115 ) ;
}
static int F_80 ( struct V_70 * V_71 ,
struct V_112 * V_113 , struct V_24 * V_25 )
{
return F_76 ( V_71 , V_113 , V_25 , V_20 ) ;
}
static int F_81 ( struct V_70 * V_71 ,
struct V_112 * V_113 , struct V_24 * V_25 )
{
return F_76 ( V_71 , V_113 , V_25 , V_49 ) ;
}
static int F_82 ( struct V_70 * V_71 ,
struct V_112 * V_113 , struct V_24 * V_25 )
{
return F_76 ( V_71 , V_113 , V_25 , V_11 ) ;
}
static void
F_83 ( struct V_24 * V_25 , int V_75 , char * V_18 , T_4 V_40 )
{
switch ( V_75 ) {
case V_121 :
F_12 ( V_18 , V_40 , L_14 V_48 , V_25 -> V_31 . V_26 ) ;
break;
default:
break;
}
}
static void
F_84 ( struct V_24 * V_25 , struct V_24 * V_29 ,
int V_75 , char * V_18 , T_4 V_40 )
{
double V_33 ;
double V_122 ;
T_3 V_39 ;
switch ( V_75 ) {
case V_123 :
if ( V_29 -> V_33 . V_35 )
V_33 = V_29 -> V_33 . V_34 ;
else
V_33 = F_8 ( V_25 , V_29 ) ;
F_12 ( V_18 , V_40 , L_36 , V_33 ) ;
break;
case V_124 :
if ( V_25 -> V_96 ) {
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
case V_125 :
if ( V_25 -> V_96 ) {
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
case V_126 :
F_15 ( V_25 , V_29 , V_18 , V_40 ) ;
break;
case V_127 :
F_12 ( V_18 , V_40 , L_14 V_48 , V_29 -> V_31 . V_26 ) ;
break;
default:
F_16 ( 1 ) ;
} ;
}
static void
F_85 ( struct V_24 * V_25 , struct V_72 * V_73 ,
char * V_18 , T_4 V_40 )
{
struct V_24 * V_29 = F_34 ( V_25 , V_73 ) ;
int V_75 = V_73 -> V_75 ;
if ( V_75 == V_128 )
F_75 ( V_25 , V_18 , V_40 ) ;
else {
if ( V_29 )
F_84 ( V_25 , V_29 , V_75 , V_18 , V_40 ) ;
else
F_83 ( V_25 , V_75 , V_18 , V_40 ) ;
}
}
static int F_86 ( struct V_70 * V_129 , struct V_112 * V_113 ,
struct V_24 * V_25 )
{
struct V_72 * V_73 =
F_30 ( V_129 , struct V_72 , V_71 ) ;
char V_18 [ V_130 ] = L_27 ;
F_85 ( V_25 , V_73 , V_18 , V_130 ) ;
if ( V_45 . V_117 )
return F_12 ( V_113 -> V_18 , V_113 -> V_40 , L_39 , V_18 ) ;
else
return F_12 ( V_113 -> V_18 , V_113 -> V_40 , L_29 ,
V_73 -> V_116 , V_18 ) ;
}
static int F_87 ( struct V_70 * V_71 , struct V_112 * V_113 ,
struct V_60 * V_61 V_14 )
{
struct V_72 * V_73 =
F_30 ( V_71 , struct V_72 , V_71 ) ;
F_16 ( ! V_73 -> V_63 ) ;
return F_12 ( V_113 -> V_18 , V_113 -> V_40 , V_73 -> V_63 ) ;
}
static int F_88 ( struct V_70 * V_71 ,
struct V_112 * V_113 V_14 ,
struct V_60 * V_61 V_14 )
{
struct V_72 * V_73 =
F_30 ( V_71 , struct V_72 , V_71 ) ;
F_16 ( V_73 -> V_116 <= 0 ) ;
return V_73 -> V_116 ;
}
static void F_89 ( struct V_69 * V_76 , struct V_72 * V_73 )
{
#define F_90 100
char V_131 [ F_90 ] ;
char V_18 [ F_90 ] ;
const char * V_63 = NULL ;
int V_132 = 0 ;
F_16 ( V_73 -> V_75 >= V_110 ) ;
V_63 = V_133 [ V_73 -> V_75 ] . V_134 ;
V_132 = V_133 [ V_73 -> V_75 ] . V_132 ;
F_16 ( ! V_63 ) ;
if ( V_107 > 2 )
F_12 ( V_18 , F_90 , L_40 , V_63 , V_76 -> V_75 ) ;
#define F_91 (data__files_cnt > 2 ? buf : header)
V_73 -> V_116 = V_132 ;
V_132 = ( int ) strlen ( F_91 ) ;
if ( V_73 -> V_116 < V_132 )
V_73 -> V_116 = V_132 ;
F_12 ( V_131 , F_90 , L_29 ,
V_73 -> V_116 , F_91 ) ;
V_73 -> V_63 = F_92 ( V_131 ) ;
#undef F_90
#undef F_91
}
static void F_93 ( struct V_69 * V_76 , int V_75 )
{
struct V_72 * V_73 = & V_76 -> V_71 [ V_75 ] ;
struct V_70 * V_71 = & V_73 -> V_71 ;
V_73 -> V_75 = V_75 ;
V_71 -> V_63 = F_87 ;
V_71 -> V_132 = F_88 ;
V_71 -> V_135 = F_86 ;
V_71 -> V_136 = F_48 ;
V_71 -> V_137 = F_48 ;
switch ( V_75 ) {
case V_128 :
V_71 -> V_138 = F_73 ;
V_71 -> V_139 = F_49 ;
break;
case V_123 :
V_71 -> V_138 = F_80 ;
V_71 -> V_139 = F_50 ;
break;
case V_124 :
V_71 -> V_138 = F_81 ;
V_71 -> V_139 = F_51 ;
break;
case V_125 :
V_71 -> V_138 = F_82 ;
V_71 -> V_139 = F_52 ;
break;
default:
V_71 -> V_139 = F_48 ;
break;
}
F_89 ( V_76 , V_73 ) ;
F_94 ( V_71 ) ;
F_95 ( V_71 ) ;
}
static int F_96 ( void )
{
struct V_69 * V_76 ;
struct V_70 * V_71 ;
int V_19 ;
F_60 (i, d) {
F_93 ( V_76 , V_19 ? V_140 [ V_10 ] :
V_128 ) ;
if ( V_141 && V_19 )
F_93 ( V_76 , V_126 ) ;
if ( V_142 )
F_93 ( V_76 , V_19 ? V_127 :
V_121 ) ;
}
if ( ! V_97 )
return 0 ;
V_71 = F_97 ( sizeof( * V_71 ) ) ;
if ( V_71 == NULL ) {
F_3 ( L_41 ) ;
return - 1 ;
}
V_71 -> V_136 = F_48 ;
V_71 -> V_137 = F_48 ;
switch ( V_10 ) {
case V_20 :
V_71 -> V_139 = F_53 ;
break;
case V_49 :
V_71 -> V_139 = F_54 ;
break;
case V_11 :
V_71 -> V_139 = F_55 ;
break;
default:
F_16 ( 1 ) ;
}
F_98 ( & V_71 -> V_143 , & V_144 ) ;
return 0 ;
}
static int F_99 ( int V_145 , const char * * V_146 )
{
struct V_69 * V_76 ;
static const char * V_147 [] = {
L_42 ,
L_43 ,
} ;
bool V_148 = true ;
int V_19 ;
V_107 = 2 ;
if ( V_145 ) {
if ( V_145 == 1 )
V_147 [ 1 ] = V_146 [ 0 ] ;
else {
V_107 = V_145 ;
V_148 = false ;
}
} else if ( V_149 ) {
V_147 [ 0 ] = L_44 ;
V_147 [ 1 ] = L_45 ;
}
if ( V_97 >= ( unsigned int ) V_107 ) {
F_3 ( L_46 ) ;
return - V_5 ;
}
V_95 = F_97 ( sizeof( * V_95 ) * V_107 ) ;
if ( ! V_95 )
return - V_54 ;
F_60 (i, d) {
struct V_150 * V_99 = & V_76 -> V_99 ;
V_99 -> V_100 = V_148 ? V_147 [ V_19 ] : V_146 [ V_19 ] ;
V_99 -> V_151 = V_152 ,
V_99 -> V_153 = V_153 ,
V_76 -> V_75 = V_19 ;
}
return 0 ;
}
int F_100 ( int V_145 , const char * * V_146 , const char * T_7 V_14 )
{
int V_4 = F_101 () ;
if ( V_4 < 0 )
return V_4 ;
F_102 ( V_154 , NULL ) ;
V_145 = F_103 ( V_145 , V_146 , V_155 , V_156 , 0 ) ;
if ( F_104 ( NULL ) < 0 )
return - 1 ;
if ( F_99 ( V_145 , V_146 ) < 0 )
return - 1 ;
if ( F_96 () < 0 )
return - 1 ;
V_157 = V_158 ;
if ( F_105 () < 0 )
F_106 ( V_156 , V_155 ) ;
F_107 () ;
F_108 ( NULL ) ;
return F_68 () ;
}
