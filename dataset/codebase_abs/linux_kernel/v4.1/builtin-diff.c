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
if ( F_21 ( V_57 , V_62 , & V_51 , V_59 ) < 0 ) {
F_22 ( L_16 ,
V_57 -> V_63 . type ) ;
return - 1 ;
}
if ( F_17 ( V_28 , & V_51 , V_59 -> V_26 ,
V_59 -> V_52 , V_59 -> V_53 ) ) {
F_22 ( L_17 ) ;
return - 1 ;
}
V_28 -> V_42 . V_43 += V_59 -> V_26 ;
if ( ! V_51 . V_64 )
V_28 -> V_42 . V_47 += V_59 -> V_26 ;
return 0 ;
}
static struct V_60 * F_23 ( struct V_60 * V_61 ,
struct V_65 * V_66 )
{
struct V_60 * V_67 ;
F_24 (evlist, e) {
if ( F_25 ( V_61 , V_67 ) )
return V_67 ;
}
return NULL ;
}
static void F_26 ( struct V_65 * V_66 )
{
struct V_60 * V_61 ;
F_24 (evlist, evsel) {
struct V_28 * V_28 = F_20 ( V_61 ) ;
F_27 ( V_28 , NULL ) ;
}
}
static struct V_68 * F_28 ( struct V_69 * V_70 )
{
struct V_71 * V_72 = F_29 ( V_70 , struct V_71 , V_70 ) ;
void * V_73 = V_72 - V_72 -> V_74 ;
struct V_68 * V_75 = F_29 ( V_73 , struct V_68 , V_70 ) ;
return V_75 ;
}
static struct V_24 *
F_30 ( struct V_24 * V_25 , struct V_68 * V_75 )
{
if ( F_31 ( V_25 ) ) {
struct V_24 * V_29 ;
F_32 (pair, &he->pairs.head, pairs.node)
if ( V_29 -> V_28 == V_75 -> V_28 )
return V_29 ;
}
return NULL ;
}
static struct V_24 *
F_33 ( struct V_24 * V_25 , struct V_71 * V_72 )
{
struct V_68 * V_75 = F_28 ( & V_72 -> V_70 ) ;
return F_30 ( V_25 , V_75 ) ;
}
static void F_34 ( struct V_28 * V_28 )
{
struct V_76 * V_77 ;
struct V_78 * V_79 ;
if ( V_80 )
V_77 = & V_28 -> V_81 ;
else
V_77 = V_28 -> V_82 ;
V_79 = F_35 ( V_77 ) ;
while ( V_79 != NULL ) {
struct V_24 * V_25 = F_36 ( V_79 , struct V_24 , V_83 ) ;
V_79 = F_37 ( & V_25 -> V_83 ) ;
if ( ! F_38 ( V_25 ) ) {
F_39 ( & V_25 -> V_83 , V_77 ) ;
F_40 ( V_25 ) ;
}
}
}
static void F_41 ( struct V_28 * V_28 )
{
struct V_76 * V_77 ;
struct V_78 * V_79 ;
if ( V_80 )
V_77 = & V_28 -> V_81 ;
else
V_77 = V_28 -> V_82 ;
V_79 = F_35 ( V_77 ) ;
while ( V_79 != NULL ) {
struct V_24 * V_25 , * V_29 ;
struct V_68 * V_75 ;
int V_19 ;
V_25 = F_36 ( V_79 , struct V_24 , V_83 ) ;
V_79 = F_37 ( & V_25 -> V_83 ) ;
F_42 (i, d) {
V_29 = F_30 ( V_25 , V_75 ) ;
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
static T_6 F_43 ( double V_84 , double V_85 )
{
if ( V_84 > V_85 )
return - 1 ;
else if ( V_84 < V_85 )
return 1 ;
else
return 0 ;
}
static T_6
F_44 ( struct V_24 * V_86 , struct V_24 * V_87 ,
int V_88 )
{
switch ( V_88 ) {
case V_20 :
{
double V_84 = V_86 -> V_33 . V_34 ;
double V_85 = V_87 -> V_33 . V_34 ;
return F_43 ( V_84 , V_85 ) ;
}
case V_49 :
{
double V_84 = V_86 -> V_33 . V_38 ;
double V_85 = V_87 -> V_33 . V_38 ;
return F_43 ( V_84 , V_85 ) ;
}
case V_11 :
{
T_3 V_84 = V_86 -> V_33 . V_39 ;
T_3 V_85 = V_87 -> V_33 . V_39 ;
return V_85 - V_84 ;
}
default:
F_16 ( 1 ) ;
}
return 0 ;
}
static T_6
F_45 ( struct V_24 * V_86 , struct V_24 * V_87 ,
int V_88 , int V_89 )
{
bool V_90 = F_31 ( V_86 ) ;
bool V_91 = F_31 ( V_87 ) ;
struct V_24 * V_92 , * V_93 ;
if ( ! V_90 && ! V_91 )
return 0 ;
if ( ! V_90 || ! V_91 )
return V_90 ? - 1 : 1 ;
V_93 = F_30 ( V_86 , & V_94 [ V_89 ] ) ;
V_92 = F_30 ( V_87 , & V_94 [ V_89 ] ) ;
if ( ! V_93 && ! V_92 )
return 0 ;
if ( ! V_93 || ! V_92 )
return V_93 ? - 1 : 1 ;
return F_44 ( V_93 , V_92 , V_88 ) ;
}
static T_6
F_46 ( struct V_24 * V_86 , struct V_24 * V_87 ,
int V_88 , int V_89 )
{
struct V_24 * V_92 , * V_93 ;
V_93 = F_30 ( V_86 , & V_94 [ V_89 ] ) ;
V_92 = F_30 ( V_87 , & V_94 [ V_89 ] ) ;
if ( ! V_93 && ! V_92 )
return 0 ;
if ( ! V_93 || ! V_92 )
return V_93 ? - 1 : 1 ;
if ( V_88 != V_20 ) {
if ( V_86 -> V_95 && V_87 -> V_95 )
return 0 ;
if ( V_86 -> V_95 || V_87 -> V_95 )
return V_86 -> V_95 ? 1 : - 1 ;
}
return F_44 ( V_93 , V_92 , V_88 ) ;
}
static T_6
F_47 ( struct V_69 * V_70 V_14 ,
struct V_24 * V_86 V_14 ,
struct V_24 * V_87 V_14 )
{
return 0 ;
}
static T_6
F_48 ( struct V_69 * V_70 V_14 ,
struct V_24 * V_86 , struct V_24 * V_87 )
{
if ( V_86 -> V_31 . V_26 == V_87 -> V_31 . V_26 )
return 0 ;
return V_86 -> V_31 . V_26 > V_87 -> V_31 . V_26 ? 1 : - 1 ;
}
static T_6
F_49 ( struct V_69 * V_70 ,
struct V_24 * V_86 , struct V_24 * V_87 )
{
struct V_68 * V_75 = F_28 ( V_70 ) ;
return F_45 ( V_87 , V_86 , V_20 , V_75 -> V_74 ) ;
}
static T_6
F_50 ( struct V_69 * V_70 ,
struct V_24 * V_86 , struct V_24 * V_87 )
{
struct V_68 * V_75 = F_28 ( V_70 ) ;
return F_45 ( V_87 , V_86 , V_49 , V_75 -> V_74 ) ;
}
static T_6
F_51 ( struct V_69 * V_70 ,
struct V_24 * V_86 , struct V_24 * V_87 )
{
struct V_68 * V_75 = F_28 ( V_70 ) ;
return F_45 ( V_87 , V_86 , V_11 , V_75 -> V_74 ) ;
}
static T_6
F_52 ( struct V_69 * V_70 V_14 ,
struct V_24 * V_86 , struct V_24 * V_87 )
{
return F_46 ( V_87 , V_86 , V_20 ,
V_96 ) ;
}
static T_6
F_53 ( struct V_69 * V_70 V_14 ,
struct V_24 * V_86 , struct V_24 * V_87 )
{
return F_46 ( V_87 , V_86 , V_49 ,
V_96 ) ;
}
static T_6
F_54 ( struct V_69 * V_70 V_14 ,
struct V_24 * V_86 , struct V_24 * V_87 )
{
return F_46 ( V_87 , V_86 , V_11 ,
V_96 ) ;
}
static void F_55 ( struct V_28 * V_28 )
{
if ( V_97 )
F_34 ( V_28 ) ;
F_41 ( V_28 ) ;
F_56 ( V_28 , NULL ) ;
F_57 ( V_28 , true , 0 , 0 , 0 , stdout ) ;
}
static void F_58 ( void )
{
struct V_68 * V_75 ;
int V_19 ;
fprintf ( stdout , L_18 ) ;
F_59 (i, d)
fprintf ( stdout , L_19 ,
V_75 -> V_74 , V_75 -> V_98 . V_99 ,
! V_75 -> V_74 ? L_20 : L_21 ) ;
fprintf ( stdout , L_22 ) ;
}
static void F_60 ( void )
{
struct V_65 * V_100 = V_94 [ 0 ] . V_101 -> V_66 ;
struct V_60 * V_102 ;
bool V_103 = true ;
F_24 (evlist_base, evsel_base) {
struct V_28 * V_104 = F_20 ( V_102 ) ;
struct V_68 * V_75 ;
int V_19 ;
F_42 (i, d) {
struct V_65 * V_66 = V_75 -> V_101 -> V_66 ;
struct V_60 * V_61 ;
struct V_28 * V_28 ;
V_61 = F_23 ( V_102 , V_66 ) ;
if ( ! V_61 )
continue;
V_28 = F_20 ( V_61 ) ;
V_75 -> V_28 = V_28 ;
F_61 ( V_104 , V_28 ) ;
if ( ! V_97 )
F_62 ( V_104 , V_28 ) ;
}
fprintf ( stdout , L_23 , V_103 ? L_21 : L_24 ,
F_63 ( V_102 ) ) ;
V_103 = false ;
if ( V_105 || V_106 > 2 )
F_58 () ;
F_55 ( V_104 ) ;
}
}
static void F_64 ( struct V_68 * V_75 )
{
int V_107 ;
for ( V_107 = 0 ; V_107 < V_108 ; V_107 ++ ) {
struct V_71 * V_70 = & V_75 -> V_70 [ V_107 ] ;
F_65 ( & V_70 -> V_63 ) ;
}
}
static int F_66 ( void )
{
struct V_68 * V_75 ;
int V_4 = - V_5 , V_19 ;
F_59 (i, d) {
V_75 -> V_101 = F_67 ( & V_75 -> V_98 , false , & T_5 ) ;
if ( ! V_75 -> V_101 ) {
F_3 ( L_25 , V_75 -> V_98 . V_99 ) ;
V_4 = - 1 ;
goto V_109;
}
V_4 = F_68 ( V_75 -> V_101 ) ;
if ( V_4 ) {
F_3 ( L_26 , V_75 -> V_98 . V_99 ) ;
goto V_109;
}
F_26 ( V_75 -> V_101 -> V_66 ) ;
}
F_60 () ;
V_109:
F_59 (i, d) {
if ( V_75 -> V_101 )
F_69 ( V_75 -> V_101 ) ;
F_64 ( V_75 ) ;
}
free ( V_94 ) ;
return V_4 ;
}
static double F_70 ( struct V_24 * V_25 )
{
T_2 V_27 = F_7 ( V_25 -> V_28 ) ;
return 100.0 * V_25 -> V_31 . V_26 / V_27 ;
}
static int F_71 ( struct V_69 * V_70 ,
struct V_110 * V_111 , struct V_24 * V_25 )
{
struct V_71 * V_72 =
F_29 ( V_70 , struct V_71 , V_70 ) ;
double V_112 = F_70 ( V_25 ) ;
char V_113 [ 20 ] = L_27 ;
if ( ! V_25 -> V_95 ) {
F_12 ( V_113 , 20 , L_28 , V_72 -> V_114 - 1 ) ;
return F_72 ( V_111 -> V_18 , V_111 -> V_40 ,
V_113 , V_112 ) ;
} else
return F_12 ( V_111 -> V_18 , V_111 -> V_40 , L_29 ,
V_72 -> V_114 , V_113 ) ;
}
static int F_73 ( struct V_24 * V_25 , char * V_18 , T_4 V_40 )
{
double V_112 = F_70 ( V_25 ) ;
const char * V_70 = V_45 . V_115 ? L_30 : L_31 ;
int V_4 = 0 ;
if ( ! V_25 -> V_95 )
V_4 = F_12 ( V_18 , V_40 , V_70 , V_112 ) ;
return V_4 ;
}
static int F_74 ( struct V_69 * V_70 ,
struct V_110 * V_111 , struct V_24 * V_25 ,
int V_116 )
{
struct V_71 * V_72 =
F_29 ( V_70 , struct V_71 , V_70 ) ;
struct V_24 * V_29 = F_33 ( V_25 , V_72 ) ;
double V_33 ;
T_3 V_39 ;
char V_113 [ 20 ] = L_27 ;
if ( ! V_29 )
goto V_117;
switch ( V_116 ) {
case V_20 :
if ( V_29 -> V_33 . V_35 )
V_33 = V_29 -> V_33 . V_34 ;
else
V_33 = F_8 ( V_25 , V_29 ) ;
F_12 ( V_113 , 20 , L_32 , V_72 -> V_114 - 1 ) ;
return F_72 ( V_111 -> V_18 , V_111 -> V_40 ,
V_113 , V_33 ) ;
case V_49 :
if ( V_25 -> V_95 )
goto V_118;
if ( V_29 -> V_33 . V_35 )
V_33 = V_29 -> V_33 . V_38 ;
else
V_33 = F_9 ( V_25 , V_29 ) ;
F_12 ( V_113 , 20 , L_33 , V_72 -> V_114 ) ;
return F_75 ( V_111 -> V_18 , V_111 -> V_40 ,
V_113 , V_33 ) ;
case V_11 :
if ( V_25 -> V_95 )
goto V_118;
if ( V_29 -> V_33 . V_35 )
V_39 = V_29 -> V_33 . V_39 ;
else
V_39 = F_10 ( V_25 , V_29 ) ;
F_12 ( V_113 , 20 , L_34 , V_72 -> V_114 ) ;
return F_76 ( V_111 -> V_18 , V_111 -> V_40 ,
F_77 ( V_39 ) ,
V_113 , V_39 ) ;
default:
F_16 ( 1 ) ;
}
V_118:
return F_12 ( V_111 -> V_18 , V_111 -> V_40 , L_29 ,
V_72 -> V_114 , L_35 ) ;
V_117:
return F_12 ( V_111 -> V_18 , V_111 -> V_40 , L_29 ,
V_72 -> V_114 , V_113 ) ;
}
static int F_78 ( struct V_69 * V_70 ,
struct V_110 * V_111 , struct V_24 * V_25 )
{
return F_74 ( V_70 , V_111 , V_25 , V_20 ) ;
}
static int F_79 ( struct V_69 * V_70 ,
struct V_110 * V_111 , struct V_24 * V_25 )
{
return F_74 ( V_70 , V_111 , V_25 , V_49 ) ;
}
static int F_80 ( struct V_69 * V_70 ,
struct V_110 * V_111 , struct V_24 * V_25 )
{
return F_74 ( V_70 , V_111 , V_25 , V_11 ) ;
}
static void
F_81 ( struct V_24 * V_25 , int V_74 , char * V_18 , T_4 V_40 )
{
switch ( V_74 ) {
case V_119 :
F_12 ( V_18 , V_40 , L_14 V_48 , V_25 -> V_31 . V_26 ) ;
break;
default:
break;
}
}
static void
F_82 ( struct V_24 * V_25 , struct V_24 * V_29 ,
int V_74 , char * V_18 , T_4 V_40 )
{
double V_33 ;
double V_120 ;
T_3 V_39 ;
switch ( V_74 ) {
case V_121 :
if ( V_29 -> V_33 . V_35 )
V_33 = V_29 -> V_33 . V_34 ;
else
V_33 = F_8 ( V_25 , V_29 ) ;
F_12 ( V_18 , V_40 , L_36 , V_33 ) ;
break;
case V_122 :
if ( V_25 -> V_95 ) {
F_12 ( V_18 , V_40 , L_35 ) ;
break;
}
if ( V_29 -> V_33 . V_35 )
V_120 = V_29 -> V_33 . V_38 ;
else
V_120 = F_9 ( V_25 , V_29 ) ;
if ( V_120 > 0.0 )
F_12 ( V_18 , V_40 , L_37 , V_120 ) ;
break;
case V_123 :
if ( V_25 -> V_95 ) {
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
case V_124 :
F_15 ( V_25 , V_29 , V_18 , V_40 ) ;
break;
case V_125 :
F_12 ( V_18 , V_40 , L_14 V_48 , V_29 -> V_31 . V_26 ) ;
break;
default:
F_16 ( 1 ) ;
} ;
}
static void
F_83 ( struct V_24 * V_25 , struct V_71 * V_72 ,
char * V_18 , T_4 V_40 )
{
struct V_24 * V_29 = F_33 ( V_25 , V_72 ) ;
int V_74 = V_72 -> V_74 ;
if ( V_74 == V_126 )
F_73 ( V_25 , V_18 , V_40 ) ;
else {
if ( V_29 )
F_82 ( V_25 , V_29 , V_74 , V_18 , V_40 ) ;
else
F_81 ( V_25 , V_74 , V_18 , V_40 ) ;
}
}
static int F_84 ( struct V_69 * V_127 , struct V_110 * V_111 ,
struct V_24 * V_25 )
{
struct V_71 * V_72 =
F_29 ( V_127 , struct V_71 , V_70 ) ;
char V_18 [ V_128 ] = L_27 ;
F_83 ( V_25 , V_72 , V_18 , V_128 ) ;
if ( V_45 . V_115 )
return F_12 ( V_111 -> V_18 , V_111 -> V_40 , L_39 , V_18 ) ;
else
return F_12 ( V_111 -> V_18 , V_111 -> V_40 , L_29 ,
V_72 -> V_114 , V_18 ) ;
}
static int F_85 ( struct V_69 * V_70 , struct V_110 * V_111 ,
struct V_60 * V_61 V_14 )
{
struct V_71 * V_72 =
F_29 ( V_70 , struct V_71 , V_70 ) ;
F_16 ( ! V_72 -> V_63 ) ;
return F_12 ( V_111 -> V_18 , V_111 -> V_40 , V_72 -> V_63 ) ;
}
static int F_86 ( struct V_69 * V_70 ,
struct V_110 * V_111 V_14 ,
struct V_60 * V_61 V_14 )
{
struct V_71 * V_72 =
F_29 ( V_70 , struct V_71 , V_70 ) ;
F_16 ( V_72 -> V_114 <= 0 ) ;
return V_72 -> V_114 ;
}
static void F_87 ( struct V_68 * V_75 , struct V_71 * V_72 )
{
#define F_88 100
char V_129 [ F_88 ] ;
char V_18 [ F_88 ] ;
const char * V_63 = NULL ;
int V_130 = 0 ;
F_16 ( V_72 -> V_74 >= V_108 ) ;
V_63 = V_131 [ V_72 -> V_74 ] . V_132 ;
V_130 = V_131 [ V_72 -> V_74 ] . V_130 ;
F_16 ( ! V_63 ) ;
if ( V_106 > 2 )
F_12 ( V_18 , F_88 , L_40 , V_63 , V_75 -> V_74 ) ;
#define F_89 (data__files_cnt > 2 ? buf : header)
V_72 -> V_114 = V_130 ;
V_130 = ( int ) strlen ( F_89 ) ;
if ( V_72 -> V_114 < V_130 )
V_72 -> V_114 = V_130 ;
F_12 ( V_129 , F_88 , L_29 ,
V_72 -> V_114 , F_89 ) ;
V_72 -> V_63 = F_90 ( V_129 ) ;
#undef F_88
#undef F_89
}
static void F_91 ( struct V_68 * V_75 , int V_74 )
{
struct V_71 * V_72 = & V_75 -> V_70 [ V_74 ] ;
struct V_69 * V_70 = & V_72 -> V_70 ;
V_72 -> V_74 = V_74 ;
V_70 -> V_63 = F_85 ;
V_70 -> V_130 = F_86 ;
V_70 -> V_133 = F_84 ;
V_70 -> V_134 = F_47 ;
V_70 -> V_135 = F_47 ;
switch ( V_74 ) {
case V_126 :
V_70 -> V_136 = F_71 ;
V_70 -> V_137 = F_48 ;
break;
case V_121 :
V_70 -> V_136 = F_78 ;
V_70 -> V_137 = F_49 ;
break;
case V_122 :
V_70 -> V_136 = F_79 ;
V_70 -> V_137 = F_50 ;
break;
case V_123 :
V_70 -> V_136 = F_80 ;
V_70 -> V_137 = F_51 ;
break;
default:
V_70 -> V_137 = F_47 ;
break;
}
F_87 ( V_75 , V_72 ) ;
F_92 ( V_70 ) ;
F_93 ( V_70 ) ;
}
static int F_94 ( void )
{
struct V_68 * V_75 ;
struct V_69 * V_70 ;
int V_19 ;
F_59 (i, d) {
F_91 ( V_75 , V_19 ? V_138 [ V_10 ] :
V_126 ) ;
if ( V_139 && V_19 )
F_91 ( V_75 , V_124 ) ;
if ( V_140 )
F_91 ( V_75 , V_19 ? V_125 :
V_119 ) ;
}
if ( ! V_96 )
return 0 ;
V_70 = F_95 ( sizeof( * V_70 ) ) ;
if ( V_70 == NULL ) {
F_3 ( L_41 ) ;
return - 1 ;
}
V_70 -> V_134 = F_47 ;
V_70 -> V_135 = F_47 ;
switch ( V_10 ) {
case V_20 :
V_70 -> V_137 = F_52 ;
break;
case V_49 :
V_70 -> V_137 = F_53 ;
break;
case V_11 :
V_70 -> V_137 = F_54 ;
break;
default:
F_16 ( 1 ) ;
}
F_96 ( & V_70 -> V_141 , & V_142 ) ;
return 0 ;
}
static int F_97 ( int V_143 , const char * * V_144 )
{
struct V_68 * V_75 ;
static const char * V_145 [] = {
L_42 ,
L_43 ,
} ;
bool V_146 = true ;
int V_19 ;
V_106 = 2 ;
if ( V_143 ) {
if ( V_143 == 1 )
V_145 [ 1 ] = V_144 [ 0 ] ;
else {
V_106 = V_143 ;
V_146 = false ;
}
} else if ( V_147 ) {
V_145 [ 0 ] = L_44 ;
V_145 [ 1 ] = L_45 ;
}
if ( V_96 >= ( unsigned int ) V_106 ) {
F_3 ( L_46 ) ;
return - V_5 ;
}
V_94 = F_95 ( sizeof( * V_94 ) * V_106 ) ;
if ( ! V_94 )
return - V_54 ;
F_59 (i, d) {
struct V_148 * V_98 = & V_75 -> V_98 ;
V_98 -> V_99 = V_146 ? V_145 [ V_19 ] : V_144 [ V_19 ] ;
V_98 -> V_149 = V_150 ,
V_98 -> V_151 = V_151 ,
V_75 -> V_74 = V_19 ;
}
return 0 ;
}
int F_98 ( int V_143 , const char * * V_144 , const char * T_7 V_14 )
{
int V_4 = F_99 () ;
if ( V_4 < 0 )
return V_4 ;
F_100 ( V_152 , NULL ) ;
V_143 = F_101 ( V_143 , V_144 , V_153 , V_154 , 0 ) ;
if ( F_102 ( NULL ) < 0 )
return - 1 ;
if ( F_97 ( V_143 , V_144 ) < 0 )
return - 1 ;
if ( F_94 () < 0 )
return - 1 ;
V_155 = V_156 ;
if ( F_103 () < 0 )
F_104 ( V_154 , V_153 ) ;
F_105 () ;
F_106 ( NULL ) ;
return F_66 () ;
}
