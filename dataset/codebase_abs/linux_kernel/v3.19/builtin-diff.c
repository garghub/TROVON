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
static struct V_24 *
F_28 ( struct V_24 * V_25 , struct V_68 * V_69 )
{
if ( F_29 ( V_25 ) ) {
struct V_24 * V_29 ;
F_30 (pair, &he->pairs.head, pairs.node)
if ( V_29 -> V_28 == V_69 -> V_28 )
return V_29 ;
}
return NULL ;
}
static struct V_24 *
F_31 ( struct V_24 * V_25 , struct V_70 * V_71 )
{
void * V_72 = V_71 - V_71 -> V_73 ;
struct V_68 * V_69 = F_32 ( V_72 , struct V_68 , V_74 ) ;
return F_28 ( V_25 , V_69 ) ;
}
static void F_33 ( struct V_28 * V_28 )
{
struct V_75 * V_76 ;
struct V_77 * V_78 ;
if ( V_79 )
V_76 = & V_28 -> V_80 ;
else
V_76 = V_28 -> V_81 ;
V_78 = F_34 ( V_76 ) ;
while ( V_78 != NULL ) {
struct V_24 * V_25 = F_35 ( V_78 , struct V_24 , V_82 ) ;
V_78 = F_36 ( & V_25 -> V_82 ) ;
if ( ! F_37 ( V_25 ) ) {
F_38 ( & V_25 -> V_82 , V_76 ) ;
F_39 ( V_25 ) ;
}
}
}
static void F_40 ( struct V_28 * V_28 )
{
struct V_75 * V_76 ;
struct V_77 * V_78 ;
if ( V_79 )
V_76 = & V_28 -> V_80 ;
else
V_76 = V_28 -> V_81 ;
V_78 = F_34 ( V_76 ) ;
while ( V_78 != NULL ) {
struct V_24 * V_25 , * V_29 ;
V_25 = F_35 ( V_78 , struct V_24 , V_82 ) ;
V_78 = F_36 ( & V_25 -> V_82 ) ;
V_29 = F_28 ( V_25 , & V_83 [ V_84 ] ) ;
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
static T_6 F_41 ( double V_85 , double V_86 )
{
if ( V_85 > V_86 )
return - 1 ;
else if ( V_85 < V_86 )
return 1 ;
else
return 0 ;
}
static T_6
F_42 ( struct V_24 * V_87 , struct V_24 * V_88 ,
int V_89 )
{
switch ( V_89 ) {
case V_20 :
{
double V_85 = V_87 -> V_33 . V_34 ;
double V_86 = V_88 -> V_33 . V_34 ;
return F_41 ( V_85 , V_86 ) ;
}
case V_49 :
{
double V_85 = V_87 -> V_33 . V_38 ;
double V_86 = V_88 -> V_33 . V_38 ;
return F_41 ( V_85 , V_86 ) ;
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
F_43 ( struct V_24 * V_87 , struct V_24 * V_88 ,
int V_89 )
{
bool V_90 = F_29 ( V_87 ) ;
bool V_91 = F_29 ( V_88 ) ;
struct V_24 * V_92 , * V_93 ;
if ( ! V_90 && ! V_91 )
return 0 ;
if ( ! V_90 || ! V_91 )
return V_90 ? - 1 : 1 ;
V_93 = F_28 ( V_87 , & V_83 [ V_84 ] ) ;
V_92 = F_28 ( V_88 , & V_83 [ V_84 ] ) ;
if ( ! V_93 && ! V_92 )
return 0 ;
if ( ! V_93 || ! V_92 )
return V_93 ? - 1 : 1 ;
return F_42 ( V_93 , V_92 , V_89 ) ;
}
static T_6
F_44 ( struct V_24 * V_87 V_14 ,
struct V_24 * V_88 V_14 )
{
return 0 ;
}
static T_6
F_45 ( struct V_24 * V_87 , struct V_24 * V_88 )
{
if ( V_84 )
return 0 ;
if ( V_87 -> V_31 . V_26 == V_88 -> V_31 . V_26 )
return 0 ;
return V_87 -> V_31 . V_26 > V_88 -> V_31 . V_26 ? 1 : - 1 ;
}
static T_6
F_46 ( struct V_24 * V_87 , struct V_24 * V_88 )
{
return F_43 ( V_88 , V_87 , V_20 ) ;
}
static T_6
F_47 ( struct V_24 * V_87 , struct V_24 * V_88 )
{
return F_43 ( V_88 , V_87 , V_49 ) ;
}
static T_6
F_48 ( struct V_24 * V_87 , struct V_24 * V_88 )
{
return F_43 ( V_88 , V_87 , V_11 ) ;
}
static void F_49 ( struct V_75 * V_76 ,
struct V_24 * V_25 ,
int V_89 )
{
struct V_77 * * V_94 = & V_76 -> V_77 ;
struct V_77 * V_95 = NULL ;
struct V_24 * V_96 ;
while ( * V_94 != NULL ) {
V_95 = * V_94 ;
V_96 = F_35 ( V_95 , struct V_24 , V_77 ) ;
if ( F_43 ( V_25 , V_96 , V_89 ) < 0 )
V_94 = & ( * V_94 ) -> V_97 ;
else
V_94 = & ( * V_94 ) -> V_98 ;
}
F_50 ( & V_25 -> V_77 , V_95 , V_94 ) ;
F_51 ( & V_25 -> V_77 , V_76 ) ;
}
static void F_52 ( struct V_28 * V_28 )
{
struct V_75 * V_76 ;
struct V_77 * V_78 ;
if ( V_79 )
V_76 = & V_28 -> V_80 ;
else
V_76 = V_28 -> V_81 ;
V_28 -> V_99 = V_100 ;
V_78 = F_34 ( V_76 ) ;
F_53 ( V_28 ) ;
F_54 ( V_28 ) ;
while ( V_78 != NULL ) {
struct V_24 * V_25 ;
V_25 = F_35 ( V_78 , struct V_24 , V_82 ) ;
V_78 = F_36 ( & V_25 -> V_82 ) ;
F_49 ( & V_28 -> V_99 , V_25 , V_10 ) ;
F_55 ( V_28 , V_25 ) ;
if ( ! V_25 -> V_64 )
F_56 ( V_28 , V_25 ) ;
}
}
static void F_57 ( struct V_28 * V_28 )
{
if ( V_101 )
F_33 ( V_28 ) ;
if ( V_84 ) {
F_40 ( V_28 ) ;
F_52 ( V_28 ) ;
} else {
F_58 ( V_28 , NULL ) ;
}
F_59 ( V_28 , true , 0 , 0 , 0 , stdout ) ;
}
static void F_60 ( void )
{
struct V_68 * V_69 ;
int V_19 ;
fprintf ( stdout , L_18 ) ;
F_61 (i, d)
fprintf ( stdout , L_19 ,
V_69 -> V_73 , V_69 -> V_102 . V_103 ,
! V_69 -> V_73 ? L_20 : L_21 ) ;
fprintf ( stdout , L_22 ) ;
}
static void F_62 ( void )
{
struct V_65 * V_104 = V_83 [ 0 ] . V_105 -> V_66 ;
struct V_60 * V_106 ;
bool V_107 = true ;
F_24 (evlist_base, evsel_base) {
struct V_28 * V_108 = F_20 ( V_106 ) ;
struct V_68 * V_69 ;
int V_19 ;
F_63 (i, d) {
struct V_65 * V_66 = V_69 -> V_105 -> V_66 ;
struct V_60 * V_61 ;
struct V_28 * V_28 ;
V_61 = F_23 ( V_106 , V_66 ) ;
if ( ! V_61 )
continue;
V_28 = F_20 ( V_61 ) ;
V_69 -> V_28 = V_28 ;
F_64 ( V_108 , V_28 ) ;
if ( ! V_101 )
F_65 ( V_108 , V_28 ) ;
}
fprintf ( stdout , L_23 , V_107 ? L_21 : L_24 ,
F_66 ( V_106 ) ) ;
V_107 = false ;
if ( V_109 || V_110 > 2 )
F_60 () ;
F_57 ( V_108 ) ;
}
}
static void F_67 ( struct V_68 * V_69 )
{
int V_111 ;
for ( V_111 = 0 ; V_111 < V_112 ; V_111 ++ ) {
struct V_70 * V_74 = & V_69 -> V_74 [ V_111 ] ;
F_68 ( & V_74 -> V_63 ) ;
}
}
static int F_69 ( void )
{
struct V_68 * V_69 ;
int V_4 = - V_5 , V_19 ;
F_61 (i, d) {
V_69 -> V_105 = F_70 ( & V_69 -> V_102 , false , & T_5 ) ;
if ( ! V_69 -> V_105 ) {
F_3 ( L_25 , V_69 -> V_102 . V_103 ) ;
V_4 = - 1 ;
goto V_113;
}
V_4 = F_71 ( V_69 -> V_105 , & T_5 ) ;
if ( V_4 ) {
F_3 ( L_26 , V_69 -> V_102 . V_103 ) ;
goto V_113;
}
F_26 ( V_69 -> V_105 -> V_66 ) ;
}
F_62 () ;
V_113:
F_61 (i, d) {
if ( V_69 -> V_105 )
F_72 ( V_69 -> V_105 ) ;
F_67 ( V_69 ) ;
}
free ( V_83 ) ;
return V_4 ;
}
static double F_73 ( struct V_24 * V_25 )
{
T_2 V_27 = F_7 ( V_25 -> V_28 ) ;
return 100.0 * V_25 -> V_31 . V_26 / V_27 ;
}
static int F_74 ( struct V_114 * V_74 ,
struct V_115 * V_116 , struct V_24 * V_25 )
{
struct V_70 * V_71 =
F_32 ( V_74 , struct V_70 , V_74 ) ;
double V_117 = F_73 ( V_25 ) ;
char V_118 [ 20 ] = L_27 ;
if ( ! V_25 -> V_119 ) {
F_12 ( V_118 , 20 , L_28 , V_71 -> V_120 - 1 ) ;
return F_75 ( V_116 -> V_18 , V_116 -> V_40 ,
V_118 , V_117 ) ;
} else
return F_12 ( V_116 -> V_18 , V_116 -> V_40 , L_29 ,
V_71 -> V_120 , V_118 ) ;
}
static int F_76 ( struct V_24 * V_25 , char * V_18 , T_4 V_40 )
{
double V_117 = F_73 ( V_25 ) ;
const char * V_74 = V_45 . V_121 ? L_30 : L_31 ;
int V_4 = 0 ;
if ( ! V_25 -> V_119 )
V_4 = F_12 ( V_18 , V_40 , V_74 , V_117 ) ;
return V_4 ;
}
static int F_77 ( struct V_114 * V_74 ,
struct V_115 * V_116 , struct V_24 * V_25 ,
int V_122 )
{
struct V_70 * V_71 =
F_32 ( V_74 , struct V_70 , V_74 ) ;
struct V_24 * V_29 = F_31 ( V_25 , V_71 ) ;
double V_33 ;
T_3 V_39 ;
char V_118 [ 20 ] = L_27 ;
if ( ! V_29 )
goto V_123;
switch ( V_122 ) {
case V_20 :
if ( V_29 -> V_33 . V_35 )
V_33 = V_29 -> V_33 . V_34 ;
else
V_33 = F_8 ( V_25 , V_29 ) ;
if ( fabs ( V_33 ) < 0.01 )
goto V_123;
F_12 ( V_118 , 20 , L_32 , V_71 -> V_120 - 1 ) ;
return F_75 ( V_116 -> V_18 , V_116 -> V_40 ,
V_118 , V_33 ) ;
case V_49 :
if ( V_25 -> V_119 )
goto V_123;
if ( V_29 -> V_33 . V_35 )
V_33 = V_29 -> V_33 . V_38 ;
else
V_33 = F_9 ( V_25 , V_29 ) ;
F_12 ( V_118 , 20 , L_33 , V_71 -> V_120 ) ;
return F_78 ( V_116 -> V_18 , V_116 -> V_40 ,
V_118 , V_33 ) ;
case V_11 :
if ( V_25 -> V_119 )
goto V_123;
if ( V_29 -> V_33 . V_35 )
V_39 = V_29 -> V_33 . V_39 ;
else
V_39 = F_10 ( V_25 , V_29 ) ;
F_12 ( V_118 , 20 , L_34 , V_71 -> V_120 ) ;
return F_79 ( V_116 -> V_18 , V_116 -> V_40 ,
F_80 ( V_39 ) ,
V_118 , V_39 ) ;
default:
F_16 ( 1 ) ;
}
V_123:
return F_12 ( V_116 -> V_18 , V_116 -> V_40 , L_29 ,
V_71 -> V_120 , V_118 ) ;
}
static int F_81 ( struct V_114 * V_74 ,
struct V_115 * V_116 , struct V_24 * V_25 )
{
return F_77 ( V_74 , V_116 , V_25 , V_20 ) ;
}
static int F_82 ( struct V_114 * V_74 ,
struct V_115 * V_116 , struct V_24 * V_25 )
{
return F_77 ( V_74 , V_116 , V_25 , V_49 ) ;
}
static int F_83 ( struct V_114 * V_74 ,
struct V_115 * V_116 , struct V_24 * V_25 )
{
return F_77 ( V_74 , V_116 , V_25 , V_11 ) ;
}
static void
F_84 ( struct V_24 * V_25 , int V_73 , char * V_18 , T_4 V_40 )
{
switch ( V_73 ) {
case V_124 :
F_12 ( V_18 , V_40 , L_14 V_48 , V_25 -> V_31 . V_26 ) ;
break;
default:
break;
}
}
static void
F_85 ( struct V_24 * V_25 , struct V_24 * V_29 ,
int V_73 , char * V_18 , T_4 V_40 )
{
double V_33 ;
double V_125 ;
T_3 V_39 ;
switch ( V_73 ) {
case V_126 :
if ( V_29 -> V_33 . V_35 )
V_33 = V_29 -> V_33 . V_34 ;
else
V_33 = F_8 ( V_25 , V_29 ) ;
if ( fabs ( V_33 ) >= 0.01 )
F_12 ( V_18 , V_40 , L_35 , V_33 ) ;
break;
case V_127 :
if ( V_25 -> V_119 )
break;
if ( V_29 -> V_33 . V_35 )
V_125 = V_29 -> V_33 . V_38 ;
else
V_125 = F_9 ( V_25 , V_29 ) ;
if ( V_125 > 0.0 )
F_12 ( V_18 , V_40 , L_36 , V_125 ) ;
break;
case V_128 :
if ( V_25 -> V_119 )
break;
if ( V_29 -> V_33 . V_35 )
V_39 = V_29 -> V_33 . V_39 ;
else
V_39 = F_10 ( V_25 , V_29 ) ;
if ( V_39 != 0 )
F_12 ( V_18 , V_40 , L_37 , V_39 ) ;
break;
case V_129 :
F_15 ( V_25 , V_29 , V_18 , V_40 ) ;
break;
case V_130 :
F_12 ( V_18 , V_40 , L_14 V_48 , V_29 -> V_31 . V_26 ) ;
break;
default:
F_16 ( 1 ) ;
} ;
}
static void
F_86 ( struct V_24 * V_25 , struct V_70 * V_71 ,
char * V_18 , T_4 V_40 )
{
struct V_24 * V_29 = F_31 ( V_25 , V_71 ) ;
int V_73 = V_71 -> V_73 ;
if ( V_73 == V_131 )
F_76 ( V_25 , V_18 , V_40 ) ;
else {
if ( V_29 )
F_85 ( V_25 , V_29 , V_73 , V_18 , V_40 ) ;
else
F_84 ( V_25 , V_73 , V_18 , V_40 ) ;
}
}
static int F_87 ( struct V_114 * V_132 , struct V_115 * V_116 ,
struct V_24 * V_25 )
{
struct V_70 * V_71 =
F_32 ( V_132 , struct V_70 , V_74 ) ;
char V_18 [ V_133 ] = L_27 ;
F_86 ( V_25 , V_71 , V_18 , V_133 ) ;
if ( V_45 . V_121 )
return F_12 ( V_116 -> V_18 , V_116 -> V_40 , L_38 , V_18 ) ;
else
return F_12 ( V_116 -> V_18 , V_116 -> V_40 , L_29 ,
V_71 -> V_120 , V_18 ) ;
}
static int F_88 ( struct V_114 * V_74 , struct V_115 * V_116 ,
struct V_60 * V_61 V_14 )
{
struct V_70 * V_71 =
F_32 ( V_74 , struct V_70 , V_74 ) ;
F_16 ( ! V_71 -> V_63 ) ;
return F_12 ( V_116 -> V_18 , V_116 -> V_40 , V_71 -> V_63 ) ;
}
static int F_89 ( struct V_114 * V_74 ,
struct V_115 * V_116 V_14 ,
struct V_60 * V_61 V_14 )
{
struct V_70 * V_71 =
F_32 ( V_74 , struct V_70 , V_74 ) ;
F_16 ( V_71 -> V_120 <= 0 ) ;
return V_71 -> V_120 ;
}
static void F_90 ( struct V_68 * V_69 , struct V_70 * V_71 )
{
#define F_91 100
char V_134 [ F_91 ] ;
char V_18 [ F_91 ] ;
const char * V_63 = NULL ;
int V_135 = 0 ;
F_16 ( V_71 -> V_73 >= V_112 ) ;
V_63 = V_136 [ V_71 -> V_73 ] . V_137 ;
V_135 = V_136 [ V_71 -> V_73 ] . V_135 ;
F_16 ( ! V_63 ) ;
if ( V_110 > 2 )
F_12 ( V_18 , F_91 , L_39 , V_63 , V_69 -> V_73 ) ;
#define F_92 (data__files_cnt > 2 ? buf : header)
V_71 -> V_120 = V_135 ;
V_135 = ( int ) strlen ( F_92 ) ;
if ( V_71 -> V_120 < V_135 )
V_71 -> V_120 = V_135 ;
F_12 ( V_134 , F_91 , L_29 ,
V_71 -> V_120 , F_92 ) ;
V_71 -> V_63 = F_93 ( V_134 ) ;
#undef F_91
#undef F_92
}
static void F_94 ( struct V_68 * V_69 , int V_73 )
{
struct V_70 * V_71 = & V_69 -> V_74 [ V_73 ] ;
struct V_114 * V_74 = & V_71 -> V_74 ;
V_71 -> V_73 = V_73 ;
V_74 -> V_63 = F_88 ;
V_74 -> V_135 = F_89 ;
V_74 -> V_138 = F_87 ;
V_74 -> V_139 = F_44 ;
V_74 -> V_140 = F_44 ;
switch ( V_73 ) {
case V_131 :
V_74 -> V_141 = F_74 ;
V_74 -> V_142 = F_45 ;
break;
case V_126 :
V_74 -> V_141 = F_81 ;
V_74 -> V_142 = F_46 ;
break;
case V_127 :
V_74 -> V_141 = F_82 ;
V_74 -> V_142 = F_47 ;
break;
case V_128 :
V_74 -> V_141 = F_83 ;
V_74 -> V_142 = F_48 ;
break;
default:
V_74 -> V_142 = F_44 ;
break;
}
F_90 ( V_69 , V_71 ) ;
F_95 ( V_74 ) ;
F_96 ( V_74 ) ;
}
static void F_97 ( void )
{
struct V_68 * V_69 ;
int V_19 ;
F_61 (i, d) {
F_94 ( V_69 , V_19 ? V_143 [ V_10 ] :
V_131 ) ;
if ( V_144 && V_19 )
F_94 ( V_69 , V_129 ) ;
if ( V_145 )
F_94 ( V_69 , V_19 ? V_130 :
V_124 ) ;
}
}
static int F_98 ( int V_146 , const char * * V_147 )
{
struct V_68 * V_69 ;
static const char * V_148 [] = {
L_40 ,
L_41 ,
} ;
bool V_149 = true ;
int V_19 ;
V_110 = 2 ;
if ( V_146 ) {
if ( V_146 == 1 )
V_148 [ 1 ] = V_147 [ 0 ] ;
else {
V_110 = V_146 ;
V_149 = false ;
}
} else if ( V_150 ) {
V_148 [ 0 ] = L_42 ;
V_148 [ 1 ] = L_43 ;
}
if ( V_84 >= ( unsigned int ) V_110 ) {
F_3 ( L_44 ) ;
return - V_5 ;
}
V_83 = F_99 ( sizeof( * V_83 ) * V_110 ) ;
if ( ! V_83 )
return - V_54 ;
F_61 (i, d) {
struct V_151 * V_102 = & V_69 -> V_102 ;
V_102 -> V_103 = V_149 ? V_148 [ V_19 ] : V_147 [ V_19 ] ;
V_102 -> V_152 = V_153 ,
V_102 -> V_154 = V_154 ,
V_69 -> V_73 = V_19 ;
}
return 0 ;
}
int F_100 ( int V_146 , const char * * V_147 , const char * T_7 V_14 )
{
int V_4 = F_101 () ;
if ( V_4 < 0 )
return V_4 ;
F_102 ( V_155 , NULL ) ;
V_146 = F_103 ( V_146 , V_147 , V_156 , V_157 , 0 ) ;
if ( F_104 ( NULL ) < 0 )
return - 1 ;
if ( F_98 ( V_146 , V_147 ) < 0 )
return - 1 ;
F_97 () ;
V_158 = V_159 ;
if ( F_105 () < 0 )
F_106 ( V_157 , V_156 ) ;
F_107 () ;
F_108 ( NULL ) ;
return F_69 () ;
}
