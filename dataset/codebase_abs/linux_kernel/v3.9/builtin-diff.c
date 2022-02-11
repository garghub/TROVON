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
if ( * V_13 == '+' ) {
V_21 = true ;
V_17 = ( char * ) ++ V_13 ;
if ( ! * V_13 )
return 0 ;
}
V_12 = strchr ( V_13 , ':' ) ;
if ( V_12 ) {
unsigned V_22 = V_12 ++ - V_13 ;
if ( V_22 >= sizeof( V_18 ) )
return - V_5 ;
strncpy ( V_18 , V_13 , V_22 ) ;
V_18 [ V_22 ] = 0x0 ;
V_17 = V_18 ;
}
for ( V_19 = 0 ; V_19 < V_23 ; V_19 ++ )
if ( ! strcmp ( V_17 , V_24 [ V_19 ] ) ) {
* V_15 = V_19 ;
return F_4 ( V_12 ) ;
}
F_3 ( L_6
L_7 , V_13 ) ;
return - V_5 ;
}
double F_6 ( struct V_25 * V_26 , T_2 V_27 )
{
T_2 V_28 = V_26 -> V_29 -> V_30 . V_31 ;
return ( V_27 * 100.0 ) / V_28 ;
}
double F_7 ( struct V_25 * V_26 , struct V_25 * V_32 )
{
double V_33 = F_6 ( V_26 , V_26 -> V_34 . V_27 ) ;
double V_35 = F_6 ( V_32 , V_32 -> V_34 . V_27 ) ;
V_26 -> V_36 . V_37 = V_33 - V_35 ;
V_26 -> V_36 . V_38 = true ;
return V_26 -> V_36 . V_37 ;
}
double F_8 ( struct V_25 * V_26 , struct V_25 * V_32 )
{
double V_39 = V_26 -> V_34 . V_27 ;
double V_40 = V_32 -> V_34 . V_27 ;
V_26 -> V_36 . V_38 = true ;
V_26 -> V_36 . V_41 = V_39 / V_40 ;
return V_26 -> V_36 . V_41 ;
}
T_3 F_9 ( struct V_25 * V_26 , struct V_25 * V_32 )
{
T_2 V_39 = V_26 -> V_34 . V_27 ;
T_2 V_40 = V_32 -> V_34 . V_27 ;
V_26 -> V_36 . V_38 = true ;
V_26 -> V_36 . V_42 = V_39 * V_8 -
V_40 * V_7 ;
return V_26 -> V_36 . V_42 ;
}
static int F_10 ( struct V_25 * V_26 , struct V_25 * V_32 ,
char * V_18 , T_4 V_43 )
{
return F_11 ( V_18 , V_43 ,
L_8 V_44 L_9 V_44 L_10
L_8 V_44 L_9 V_44 L_11 ,
V_26 -> V_34 . V_27 , V_26 -> V_29 -> V_30 . V_31 ,
V_32 -> V_34 . V_27 , V_32 -> V_29 -> V_30 . V_31 ) ;
}
static int F_12 ( struct V_25 * V_26 , struct V_25 * V_32 ,
char * V_18 , T_4 V_43 )
{
double V_39 = V_26 -> V_34 . V_27 ;
double V_40 = V_32 -> V_34 . V_27 ;
return F_11 ( V_18 , V_43 , L_12 , V_39 , V_40 ) ;
}
static int F_13 ( struct V_25 * V_26 , struct V_25 * V_32 ,
char * V_18 , T_4 V_43 )
{
T_2 V_39 = V_26 -> V_34 . V_27 ;
T_2 V_40 = V_32 -> V_34 . V_27 ;
return F_11 ( V_18 , V_43 ,
L_8 V_44 L_13 L_14 V_9 L_15 V_44 L_13 L_14 V_9 L_11 ,
V_39 , V_8 , V_40 , V_7 ) ;
}
int F_14 ( struct V_25 * V_26 , struct V_25 * V_32 ,
char * V_18 , T_4 V_43 )
{
switch ( V_10 ) {
case V_20 :
return F_10 ( V_26 , V_32 , V_18 , V_43 ) ;
case V_45 :
return F_12 ( V_26 , V_32 , V_18 , V_43 ) ;
case V_11 :
return F_13 ( V_26 , V_32 , V_18 , V_43 ) ;
default:
F_15 ( 1 ) ;
}
return - 1 ;
}
static int F_16 ( struct V_29 * V_46 ,
struct V_47 * V_48 , T_2 V_27 )
{
if ( F_17 ( V_46 , V_48 , NULL , V_27 ) != NULL )
return 0 ;
return - V_49 ;
}
static int F_18 ( struct V_50 * T_5 V_14 ,
union V_51 * V_52 ,
struct V_53 * V_54 ,
struct V_55 * V_56 ,
struct V_57 * V_57 )
{
struct V_47 V_48 ;
if ( F_19 ( V_52 , V_57 , & V_48 , V_54 , NULL ) < 0 ) {
F_20 ( L_16 ,
V_52 -> V_58 . type ) ;
return - 1 ;
}
if ( V_48 . V_59 )
return 0 ;
if ( F_16 ( & V_56 -> V_29 , & V_48 , V_54 -> V_27 ) ) {
F_20 ( L_17 ) ;
return - 1 ;
}
V_56 -> V_29 . V_30 . V_31 += V_54 -> V_27 ;
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
struct V_29 * V_29 = & V_56 -> V_29 ;
F_25 ( V_29 ) ;
}
}
static void F_26 ( struct V_29 * V_29 )
{
struct V_63 * V_64 ;
struct V_65 * V_66 ;
if ( V_67 )
V_64 = & V_29 -> V_68 ;
else
V_64 = V_29 -> V_69 ;
V_66 = F_27 ( V_64 ) ;
while ( V_66 != NULL ) {
struct V_25 * V_26 = F_28 ( V_66 , struct V_25 , V_70 ) ;
V_66 = F_29 ( & V_26 -> V_70 ) ;
if ( ! F_30 ( V_26 ) ) {
F_31 ( & V_26 -> V_70 , V_64 ) ;
F_32 ( V_26 ) ;
}
}
}
static void F_33 ( struct V_29 * V_29 )
{
struct V_65 * V_66 = F_27 ( & V_29 -> V_71 ) ;
while ( V_66 != NULL ) {
struct V_25 * V_26 = F_28 ( V_66 , struct V_25 , V_65 ) ;
struct V_25 * V_32 = F_30 ( V_26 ) ;
V_66 = F_29 ( & V_26 -> V_65 ) ;
if ( ! V_32 )
continue;
switch ( V_10 ) {
case V_20 :
F_7 ( V_26 , V_32 ) ;
break;
case V_45 :
F_8 ( V_26 , V_32 ) ;
break;
case V_11 :
F_9 ( V_26 , V_32 ) ;
break;
default:
F_15 ( 1 ) ;
}
}
}
static T_6 F_34 ( double V_72 , double V_73 )
{
if ( V_72 > V_73 )
return - 1 ;
else if ( V_72 < V_73 )
return 1 ;
else
return 0 ;
}
static T_6
F_35 ( struct V_25 * V_74 , struct V_25 * V_75 ,
int V_76 )
{
switch ( V_76 ) {
case V_20 :
{
double V_72 = V_74 -> V_36 . V_37 ;
double V_73 = V_75 -> V_36 . V_37 ;
return F_34 ( V_72 , V_73 ) ;
}
case V_45 :
{
double V_72 = V_74 -> V_36 . V_41 ;
double V_73 = V_75 -> V_36 . V_41 ;
return F_34 ( V_72 , V_73 ) ;
}
case V_11 :
{
T_3 V_72 = V_74 -> V_36 . V_42 ;
T_3 V_73 = V_75 -> V_36 . V_42 ;
return V_73 - V_72 ;
}
default:
F_15 ( 1 ) ;
}
return 0 ;
}
static void F_36 ( struct V_63 * V_64 ,
struct V_25 * V_26 ,
int V_76 )
{
struct V_65 * * V_77 = & V_64 -> V_65 ;
struct V_65 * V_78 = NULL ;
struct V_25 * V_79 ;
while ( * V_77 != NULL ) {
V_78 = * V_77 ;
V_79 = F_28 ( V_78 , struct V_25 , V_65 ) ;
if ( F_35 ( V_26 , V_79 , V_76 ) < 0 )
V_77 = & ( * V_77 ) -> V_80 ;
else
V_77 = & ( * V_77 ) -> V_81 ;
}
F_37 ( & V_26 -> V_65 , V_78 , V_77 ) ;
F_38 ( & V_26 -> V_65 , V_64 ) ;
}
static void F_39 ( struct V_29 * V_29 )
{
struct V_63 * V_64 ;
struct V_65 * V_66 ;
if ( V_67 )
V_64 = & V_29 -> V_68 ;
else
V_64 = V_29 -> V_69 ;
V_29 -> V_71 = V_82 ;
V_66 = F_27 ( V_64 ) ;
V_29 -> V_83 = 0 ;
V_29 -> V_30 . V_31 = 0 ;
F_40 ( V_29 ) ;
while ( V_66 != NULL ) {
struct V_25 * V_26 ;
V_26 = F_28 ( V_66 , struct V_25 , V_70 ) ;
V_66 = F_29 ( & V_26 -> V_70 ) ;
F_36 ( & V_29 -> V_71 , V_26 , V_10 ) ;
F_41 ( V_29 , V_26 ) ;
}
}
static void F_42 ( struct V_29 * V_84 , struct V_29 * V_85 )
{
F_43 ( V_85 , V_84 ) ;
if ( V_86 )
F_26 ( V_85 ) ;
else
F_44 ( V_85 , V_84 ) ;
if ( V_21 ) {
F_33 ( V_85 ) ;
F_39 ( V_85 ) ;
} else {
F_45 ( V_85 ) ;
}
F_46 ( V_85 , true , 0 , 0 , stdout ) ;
}
static int F_47 ( void )
{
int V_4 , V_19 ;
#define F_48 (session[0])
#define F_49 (session[1])
struct V_87 * V_88 [ 2 ] ;
struct V_60 * V_89 , * V_90 ;
struct V_55 * V_56 ;
bool V_91 = true ;
F_48 = F_50 ( V_92 , V_93 , V_94 , false ,
& T_5 ) ;
F_49 = F_50 ( V_95 , V_93 , V_94 , false ,
& T_5 ) ;
if ( V_88 [ 0 ] == NULL || V_88 [ 1 ] == NULL )
return - V_49 ;
for ( V_19 = 0 ; V_19 < 2 ; ++ V_19 ) {
V_4 = F_51 ( V_88 [ V_19 ] , & T_5 ) ;
if ( V_4 )
goto V_96;
}
V_90 = F_48 -> V_61 ;
V_89 = F_49 -> V_61 ;
F_24 ( V_90 ) ;
F_24 ( V_89 ) ;
F_22 (evsel, &evlist_new->entries, node) {
struct V_55 * V_97 ;
V_97 = F_21 ( V_56 , V_90 ) ;
if ( ! V_97 )
continue;
fprintf ( stdout , L_18 , V_91 ? L_19 : L_20 ,
F_52 ( V_56 ) ) ;
V_91 = false ;
F_42 ( & V_97 -> V_29 , & V_56 -> V_29 ) ;
}
V_96:
for ( V_19 = 0 ; V_19 < 2 ; ++ V_19 )
F_53 ( V_88 [ V_19 ] ) ;
return V_4 ;
#undef F_48
#undef F_49
}
static void F_54 ( void )
{
F_55 ( V_98 ) ;
switch ( V_10 ) {
case V_20 :
F_55 ( V_99 ) ;
break;
case V_45 :
F_55 ( V_100 ) ;
break;
case V_11 :
F_55 ( V_101 ) ;
break;
default:
F_15 ( 1 ) ;
} ;
if ( V_102 )
F_55 ( V_103 ) ;
if ( V_104 ) {
F_55 ( V_105 ) ;
F_55 ( V_106 ) ;
}
}
int F_56 ( int V_107 , const char * * V_108 , const char * T_7 V_14 )
{
V_109 = V_110 ;
V_107 = F_57 ( V_107 , V_108 , V_111 , V_112 , 0 ) ;
if ( V_107 ) {
if ( V_107 > 2 )
F_58 ( V_112 , V_111 ) ;
if ( V_107 == 2 ) {
V_92 = V_108 [ 0 ] ;
V_95 = V_108 [ 1 ] ;
} else
V_95 = V_108 [ 0 ] ;
} else if ( V_113 . V_114 ||
V_113 . V_115 ) {
V_92 = L_21 ;
V_95 = L_22 ;
}
V_113 . V_116 = false ;
if ( F_59 () < 0 )
return - 1 ;
F_54 () ;
if ( F_60 () < 0 )
F_58 ( V_112 , V_111 ) ;
F_61 () ;
F_62 ( & V_117 , V_113 . V_118 , L_23 , NULL ) ;
F_62 ( & V_119 , V_113 . V_120 , L_24 , NULL ) ;
F_62 ( & V_121 , V_113 . V_122 , L_25 , NULL ) ;
return F_47 () ;
}
