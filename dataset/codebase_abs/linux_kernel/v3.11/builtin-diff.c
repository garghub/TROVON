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
struct V_47 * V_48 , T_2 V_27 ,
T_2 V_49 )
{
if ( F_17 ( V_46 , V_48 , NULL , V_27 , V_49 ) != NULL )
return 0 ;
return - V_50 ;
}
static int F_18 ( struct V_51 * T_5 V_14 ,
union V_52 * V_53 ,
struct V_54 * V_55 ,
struct V_56 * V_57 ,
struct V_58 * V_58 )
{
struct V_47 V_48 ;
if ( F_19 ( V_53 , V_58 , & V_48 , V_55 , NULL ) < 0 ) {
F_20 ( L_16 ,
V_53 -> V_59 . type ) ;
return - 1 ;
}
if ( V_48 . V_60 )
return 0 ;
if ( F_16 ( & V_57 -> V_29 , & V_48 , V_55 -> V_27 , V_55 -> V_49 ) ) {
F_20 ( L_17 ) ;
return - 1 ;
}
V_57 -> V_29 . V_30 . V_31 += V_55 -> V_27 ;
return 0 ;
}
static struct V_56 * F_21 ( struct V_56 * V_57 ,
struct V_61 * V_62 )
{
struct V_56 * V_63 ;
F_22 (e, &evlist->entries, node)
if ( F_23 ( V_57 , V_63 ) )
return V_63 ;
return NULL ;
}
static void F_24 ( struct V_61 * V_62 )
{
struct V_56 * V_57 ;
F_22 (evsel, &evlist->entries, node) {
struct V_29 * V_29 = & V_57 -> V_29 ;
F_25 ( V_29 ) ;
}
}
static void F_26 ( struct V_29 * V_29 )
{
struct V_64 * V_65 ;
struct V_66 * V_67 ;
if ( V_68 )
V_65 = & V_29 -> V_69 ;
else
V_65 = V_29 -> V_70 ;
V_67 = F_27 ( V_65 ) ;
while ( V_67 != NULL ) {
struct V_25 * V_26 = F_28 ( V_67 , struct V_25 , V_71 ) ;
V_67 = F_29 ( & V_26 -> V_71 ) ;
if ( ! F_30 ( V_26 ) ) {
F_31 ( & V_26 -> V_71 , V_65 ) ;
F_32 ( V_26 ) ;
}
}
}
static void F_33 ( struct V_29 * V_29 )
{
struct V_64 * V_65 ;
struct V_66 * V_67 ;
if ( V_68 )
V_65 = & V_29 -> V_69 ;
else
V_65 = V_29 -> V_70 ;
V_67 = F_27 ( V_65 ) ;
while ( V_67 != NULL ) {
struct V_25 * V_26 = F_28 ( V_67 , struct V_25 , V_71 ) ;
struct V_25 * V_32 = F_30 ( V_26 ) ;
V_67 = F_29 ( & V_26 -> V_71 ) ;
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
static void F_36 ( struct V_64 * V_65 ,
struct V_25 * V_26 ,
int V_76 )
{
struct V_66 * * V_77 = & V_65 -> V_66 ;
struct V_66 * V_78 = NULL ;
struct V_25 * V_79 ;
while ( * V_77 != NULL ) {
V_78 = * V_77 ;
V_79 = F_28 ( V_78 , struct V_25 , V_66 ) ;
if ( F_35 ( V_26 , V_79 , V_76 ) < 0 )
V_77 = & ( * V_77 ) -> V_80 ;
else
V_77 = & ( * V_77 ) -> V_81 ;
}
F_37 ( & V_26 -> V_66 , V_78 , V_77 ) ;
F_38 ( & V_26 -> V_66 , V_65 ) ;
}
static void F_39 ( struct V_29 * V_29 )
{
struct V_64 * V_65 ;
struct V_66 * V_67 ;
if ( V_68 )
V_65 = & V_29 -> V_69 ;
else
V_65 = V_29 -> V_70 ;
V_29 -> V_82 = V_83 ;
V_67 = F_27 ( V_65 ) ;
V_29 -> V_84 = 0 ;
V_29 -> V_30 . V_31 = 0 ;
F_40 ( V_29 ) ;
while ( V_67 != NULL ) {
struct V_25 * V_26 ;
V_26 = F_28 ( V_67 , struct V_25 , V_71 ) ;
V_67 = F_29 ( & V_26 -> V_71 ) ;
F_36 ( & V_29 -> V_82 , V_26 , V_10 ) ;
F_41 ( V_29 , V_26 ) ;
}
}
static void F_42 ( struct V_29 * V_85 , struct V_29 * V_86 )
{
F_43 ( V_86 , V_85 ) ;
if ( V_87 )
F_26 ( V_86 ) ;
else
F_44 ( V_86 , V_85 ) ;
if ( V_21 ) {
F_33 ( V_86 ) ;
F_39 ( V_86 ) ;
} else {
F_45 ( V_86 ) ;
}
F_46 ( V_86 , true , 0 , 0 , 0 , stdout ) ;
}
static int F_47 ( void )
{
int V_4 , V_19 ;
#define F_48 (session[0])
#define F_49 (session[1])
struct V_88 * V_89 [ 2 ] ;
struct V_61 * V_90 , * V_91 ;
struct V_56 * V_57 ;
bool V_92 = true ;
F_48 = F_50 ( V_93 , V_94 , V_95 , false ,
& T_5 ) ;
F_49 = F_50 ( V_96 , V_94 , V_95 , false ,
& T_5 ) ;
if ( V_89 [ 0 ] == NULL || V_89 [ 1 ] == NULL )
return - V_50 ;
for ( V_19 = 0 ; V_19 < 2 ; ++ V_19 ) {
V_4 = F_51 ( V_89 [ V_19 ] , & T_5 ) ;
if ( V_4 )
goto V_97;
}
V_91 = F_48 -> V_62 ;
V_90 = F_49 -> V_62 ;
F_24 ( V_91 ) ;
F_24 ( V_90 ) ;
F_22 (evsel, &evlist_new->entries, node) {
struct V_56 * V_98 ;
V_98 = F_21 ( V_57 , V_91 ) ;
if ( ! V_98 )
continue;
fprintf ( stdout , L_18 , V_92 ? L_19 : L_20 ,
F_52 ( V_57 ) ) ;
V_92 = false ;
F_42 ( & V_98 -> V_29 , & V_57 -> V_29 ) ;
}
V_97:
for ( V_19 = 0 ; V_19 < 2 ; ++ V_19 )
F_53 ( V_89 [ V_19 ] ) ;
return V_4 ;
#undef F_48
#undef F_49
}
static void F_54 ( void )
{
F_55 ( V_99 ) ;
switch ( V_10 ) {
case V_20 :
F_55 ( V_100 ) ;
break;
case V_45 :
F_55 ( V_101 ) ;
break;
case V_11 :
F_55 ( V_102 ) ;
break;
default:
F_15 ( 1 ) ;
} ;
if ( V_103 )
F_55 ( V_104 ) ;
if ( V_105 ) {
F_55 ( V_106 ) ;
F_55 ( V_107 ) ;
}
}
int F_56 ( int V_108 , const char * * V_109 , const char * T_7 V_14 )
{
V_110 = V_111 ;
V_108 = F_57 ( V_108 , V_109 , V_112 , V_113 , 0 ) ;
if ( V_108 ) {
if ( V_108 > 2 )
F_58 ( V_113 , V_112 ) ;
if ( V_108 == 2 ) {
V_93 = V_109 [ 0 ] ;
V_96 = V_109 [ 1 ] ;
} else
V_96 = V_109 [ 0 ] ;
} else if ( V_114 . V_115 ||
V_114 . V_116 ) {
V_93 = L_21 ;
V_96 = L_22 ;
}
if ( F_59 () < 0 )
return - 1 ;
F_54 () ;
if ( F_60 () < 0 )
F_58 ( V_113 , V_112 ) ;
F_61 () ;
F_62 ( NULL ) ;
return F_47 () ;
}
