struct V_1 *
F_1 ( void * V_2 , T_1 V_3 , const char * V_4 )
{
struct V_1 * V_5 ;
if ( ! V_6 ) {
F_2 ( V_7 ,
V_8 ,
V_9 ) ;
V_6 = true ;
}
V_5 = F_3 ( V_2 , V_3 , V_4 ) ;
if ( F_4 ( V_5 ) ) {
F_5 ( L_1 ) ;
return F_6 ( - V_10 ) ;
}
return V_5 ;
}
struct V_1 * F_7 ( const char * V_11 , bool V_12 )
{
struct V_1 * V_5 ;
if ( ! V_6 ) {
F_2 ( V_7 ,
V_8 ,
V_9 ) ;
V_6 = true ;
}
if ( V_12 ) {
int V_13 ;
void * V_2 ;
T_1 V_3 ;
V_13 = F_8 ( V_11 , & V_2 , & V_3 ) ;
if ( V_13 )
return F_6 ( - V_14 ) ;
V_5 = F_3 ( V_2 , V_3 , V_11 ) ;
free ( V_2 ) ;
} else
V_5 = F_9 ( V_11 ) ;
if ( F_4 ( V_5 ) ) {
F_5 ( L_2 , V_11 ) ;
return V_5 ;
}
return V_5 ;
}
void F_10 ( void )
{
struct V_1 * V_5 , * V_15 ;
F_11 (obj, tmp) {
F_12 ( V_5 ) ;
F_13 ( V_5 ) ;
}
}
static void
F_14 ( struct V_16 * T_2 V_17 ,
void * V_18 )
{
struct V_19 * V_20 = V_18 ;
F_15 ( & V_20 -> V_21 , 1 ) ;
F_16 ( & V_20 -> V_22 ) ;
F_16 ( & V_20 -> V_23 ) ;
free ( V_20 ) ;
}
static int
F_17 ( const char * V_24 , struct V_25 * V_21 )
{
V_21 -> V_26 = true ;
V_21 -> V_27 = F_18 ( V_24 ) ;
if ( ! V_21 -> V_27 )
return - V_28 ;
return 0 ;
}
static int
F_19 ( const char * V_24 , struct V_25 * V_21 )
{
V_21 -> V_26 = false ;
V_21 -> V_27 = F_18 ( V_24 ) ;
if ( ! V_21 -> V_27 )
return - V_28 ;
return 0 ;
}
static int
F_20 ( const char * V_24 , bool * V_29 , bool V_30 )
{
int V_13 ;
bool V_31 ;
if ( ! V_29 )
return - V_10 ;
V_13 = F_21 ( V_24 , & V_31 ) ;
if ( V_13 )
return V_13 ;
* V_29 = V_30 ? ! V_31 : V_31 ;
return 0 ;
}
static int
F_22 ( const char * V_24 ,
struct V_25 * V_21 V_17 )
{
return F_20 ( V_24 , & V_32 . V_33 , true ) ;
}
static int
F_23 ( const char * V_24 ,
struct V_25 * V_21 V_17 )
{
return F_20 ( V_24 , & V_32 . V_34 , false ) ;
}
static int
F_24 ( const char * V_35 , const char * V_24 ,
struct V_25 * V_21 )
{
unsigned int V_36 ;
F_5 ( L_3 , V_35 , V_24 ) ;
for ( V_36 = 0 ; V_36 < F_25 ( V_37 ) ; V_36 ++ )
if ( strcmp ( V_35 , V_37 [ V_36 ] . V_35 ) == 0 )
return V_37 [ V_36 ] . F_26 ( V_24 , V_21 ) ;
F_5 ( L_4 ,
V_35 , V_24 ) ;
F_5 ( L_5 ) ;
for ( V_36 = 0 ; V_36 < F_25 ( V_37 ) ; V_36 ++ )
F_5 ( L_6 , V_37 [ V_36 ] . V_38 ,
V_37 [ V_36 ] . V_39 ) ;
F_5 ( L_7 ) ;
return - V_40 ;
}
static const char *
F_27 ( const char * V_41 , struct V_25 * V_21 )
{
char * V_42 = F_18 ( V_41 ) ;
char * V_43 , * line ;
const char * V_44 = NULL ;
int V_13 = 0 ;
if ( ! V_42 ) {
F_5 ( L_8 ) ;
return F_6 ( - V_28 ) ;
}
line = V_42 ;
while ( ( V_43 = strchr ( line , ';' ) ) ) {
char * V_45 ;
* V_43 = '\0' ;
V_45 = strchr ( line , '=' ) ;
if ( ! V_45 ) {
F_28 ( L_9 ,
line ) ;
F_28 ( L_10 ) ;
goto V_46;
}
* V_45 = '\0' ;
V_13 = F_24 ( line , V_45 + 1 , V_21 ) ;
if ( V_13 )
break;
V_46:
line = V_43 + 1 ;
}
if ( ! V_13 )
V_44 = V_41 + ( line - V_42 ) ;
free ( V_42 ) ;
return V_13 ? F_6 ( V_13 ) : V_44 ;
}
static int
F_29 ( const char * V_41 , struct V_25 * V_21 )
{
int V_13 ;
const char * V_44 = F_27 ( V_41 , V_21 ) ;
if ( F_4 ( V_44 ) )
return F_30 ( V_44 ) ;
V_13 = F_31 ( V_44 , V_21 ) ;
if ( V_13 < 0 ) {
F_5 ( L_11 ,
V_41 ) ;
return - V_47 ;
}
return 0 ;
}
static int
F_32 ( struct V_16 * T_2 )
{
struct V_25 * V_21 = NULL ;
struct V_19 * V_20 = NULL ;
const char * V_41 ;
int V_13 ;
V_32 . V_33 = false ;
V_32 . V_34 = false ;
V_41 = F_33 ( T_2 , false ) ;
if ( F_4 ( V_41 ) ) {
F_5 ( L_12 ) ;
return F_30 ( V_41 ) ;
}
V_20 = calloc ( sizeof( * V_20 ) , 1 ) ;
if ( ! V_20 ) {
F_5 ( L_13 ) ;
return - V_28 ;
}
V_21 = & V_20 -> V_21 ;
F_5 ( L_14 , V_41 ) ;
V_13 = F_29 ( V_41 , V_21 ) ;
if ( V_13 )
goto V_48;
if ( V_21 -> V_49 && strcmp ( V_21 -> V_49 , V_50 ) ) {
F_5 ( L_15 ,
V_41 , V_50 ) ;
V_13 = - V_51 ;
goto V_48;
} else if ( ! V_21 -> V_49 )
V_21 -> V_49 = F_18 ( V_50 ) ;
if ( ! V_21 -> V_49 ) {
F_5 ( L_16 ) ;
V_13 = - V_28 ;
goto V_48;
}
if ( ! V_21 -> V_52 ) {
F_5 ( L_17 ,
V_41 ) ;
V_13 = - V_53 ;
goto V_48;
}
F_5 ( L_18 , V_41 ) ;
V_13 = F_34 ( T_2 , V_20 , F_14 ) ;
if ( V_13 ) {
F_5 ( L_19 , V_41 ) ;
goto V_48;
}
return 0 ;
V_48:
if ( V_21 )
F_35 ( V_21 ) ;
free ( V_20 ) ;
return V_13 ;
}
static int F_36 ( void )
{
static int V_13 = 0 ;
static bool V_54 = false ;
if ( V_54 )
return V_13 ;
V_54 = true ;
V_13 = F_37 ( false ) ;
if ( V_13 < 0 )
F_5 ( L_20 ) ;
V_32 . V_55 = V_56 ;
return V_13 ;
}
static int
F_38 ( struct V_16 * T_2 , int V_57 ,
struct V_58 * V_59 , int V_60 ,
struct V_61 * V_62 )
{
struct V_63 * V_64 ;
struct V_25 * V_21 ;
struct V_19 * V_20 ;
struct V_58 * V_65 ;
T_1 V_66 = 0 ;
int V_36 , V_13 ;
V_13 = F_39 ( T_2 , ( void * * ) & V_20 ) ;
if ( V_13 || ! V_20 )
goto V_48;
V_21 = & V_20 -> V_21 ;
if ( V_57 < 0 || V_57 >= V_20 -> V_67 )
goto V_48;
for ( V_36 = 0 ; V_36 < V_21 -> V_68 ; V_36 ++ ) {
if ( V_20 -> V_23 [ V_36 ] == V_57 )
break;
}
if ( V_36 >= V_21 -> V_68 ) {
F_5 ( L_21 , V_57 ) ;
return - V_69 ;
}
V_64 = & V_21 -> V_70 [ V_36 ] ;
V_65 = V_20 -> V_22 ;
V_13 = F_40 ( V_64 -> args , V_64 -> V_71 ,
V_65 , & V_66 ,
V_72 - V_60 ) ;
if ( V_13 ) {
const char * V_73 ;
V_73 = F_33 ( T_2 , false ) ;
if ( ! V_73 )
V_73 = L_22 ;
F_5 ( L_23 ,
V_73 ) ;
return V_13 ;
}
memcpy ( & V_65 [ V_66 ] , V_59 ,
sizeof( struct V_58 ) * V_60 ) ;
V_62 -> V_74 = V_65 ;
V_62 -> V_75 = V_66 + V_60 ;
V_62 -> V_76 = NULL ;
return 0 ;
V_48:
F_5 ( L_24 ) ;
return - V_69 ;
}
static int F_41 ( const void * V_77 , const void * V_78 )
{
int V_36 , V_79 ;
const struct V_63 * V_80 =
* ( const struct V_63 * * ) V_77 ;
const struct V_63 * V_81 =
* ( const struct V_63 * * ) V_78 ;
V_79 = V_81 -> V_71 - V_80 -> V_71 ;
if ( V_79 )
return V_79 ;
for ( V_36 = 0 ; V_36 < V_80 -> V_71 ; V_36 ++ ) {
struct V_82 * V_83 , * V_84 ;
struct V_85 * V_86 , * V_87 ;
V_83 = & V_80 -> args [ V_36 ] ;
V_84 = & V_81 -> args [ V_36 ] ;
V_79 = strcmp ( V_83 -> V_24 , V_84 -> V_24 ) ;
if ( V_79 )
return V_79 ;
V_86 = V_83 -> V_88 ;
V_87 = V_84 -> V_88 ;
while ( V_86 && V_87 ) {
V_79 = V_87 -> V_89 - V_86 -> V_89 ;
if ( V_79 )
return V_79 ;
V_86 = V_86 -> V_90 ;
V_87 = V_87 -> V_90 ;
}
if ( V_86 || V_87 )
return V_87 ? 1 : - 1 ;
}
return 0 ;
}
static int F_42 ( struct V_25 * V_21 , int * V_91 ,
int * V_67 )
{
int V_36 , type = 0 ;
struct V_63 * * V_92 ;
T_1 V_93 = sizeof( * V_92 ) * V_21 -> V_68 ;
V_92 = malloc ( V_93 ) ;
if ( ! V_92 ) {
F_5 ( L_25 ) ;
return - V_28 ;
}
F_5 ( L_26 , V_21 -> V_68 ) ;
for ( V_36 = 0 ; V_36 < V_21 -> V_68 ; V_36 ++ )
V_92 [ V_36 ] = & V_21 -> V_70 [ V_36 ] ;
qsort ( V_92 , V_21 -> V_68 , sizeof( * V_92 ) ,
F_41 ) ;
for ( V_36 = 0 ; V_36 < V_21 -> V_68 ; V_36 ++ ) {
int V_57 ;
V_57 = V_92 [ V_36 ] - V_21 -> V_70 ;
if ( V_36 == 0 ) {
V_91 [ V_57 ] = type ;
F_5 ( L_27 , V_57 , type ) ;
continue;
}
if ( F_41 ( V_92 + V_36 , V_92 + V_36 - 1 ) == 0 )
V_91 [ V_57 ] = type ;
else
V_91 [ V_57 ] = ++ type ;
F_5 ( L_27 , V_57 , V_91 [ V_57 ] ) ;
}
free ( V_92 ) ;
* V_67 = type + 1 ;
return 0 ;
}
static int F_43 ( struct V_16 * T_2 )
{
struct V_25 * V_21 ;
struct V_19 * V_20 ;
bool V_94 = false ;
int V_13 , V_36 ;
V_13 = F_39 ( T_2 , ( void * * ) & V_20 ) ;
if ( V_13 || ! V_20 ) {
F_5 ( L_28 ) ;
return - V_95 ;
}
V_21 = & V_20 -> V_21 ;
for ( V_36 = 0 ; V_36 < V_21 -> V_68 ; V_36 ++ ) {
struct V_63 * V_64 = & V_21 -> V_70 [ V_36 ] ;
if ( V_64 -> V_71 > 0 ) {
V_94 = true ;
break;
}
}
if ( ! V_94 ) {
V_20 -> V_94 = false ;
return 0 ;
}
V_20 -> V_94 = true ;
V_20 -> V_22 = malloc ( sizeof( struct V_58 ) * V_72 ) ;
if ( ! V_20 -> V_22 ) {
F_5 ( L_29 ) ;
return - V_28 ;
}
V_20 -> V_23 = malloc ( sizeof( int ) * V_21 -> V_68 ) ;
if ( ! V_20 -> V_23 ) {
F_5 ( L_30 ) ;
return - V_28 ;
}
memset ( V_20 -> V_23 , - 1 ,
sizeof( int ) * V_21 -> V_68 ) ;
V_13 = F_42 ( V_21 , V_20 -> V_23 , & V_20 -> V_67 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_44 ( T_2 , V_20 -> V_67 ,
F_38 ) ;
return V_13 ;
}
int F_45 ( struct V_1 * V_5 )
{
int V_13 = 0 ;
struct V_16 * T_2 ;
struct V_19 * V_20 ;
struct V_25 * V_21 ;
V_13 = F_36 () ;
if ( V_13 ) {
F_5 ( L_31 ) ;
return V_13 ;
}
F_46 (prog, obj) {
V_13 = F_32 ( T_2 ) ;
if ( V_13 )
goto V_96;
V_13 = F_39 ( T_2 , ( void * * ) & V_20 ) ;
if ( V_13 || ! V_20 )
goto V_96;
V_21 = & V_20 -> V_21 ;
V_13 = F_47 ( V_21 , 1 ) ;
if ( V_13 < 0 ) {
F_5 ( L_32 ) ;
goto V_96;
}
V_13 = F_48 ( V_21 , 1 ) ;
if ( V_13 < 0 ) {
F_5 ( L_33 ) ;
goto V_96;
}
V_13 = F_43 ( T_2 ) ;
if ( V_13 )
goto V_96;
}
V_96:
return V_13 < 0 ? V_13 : 0 ;
}
int F_12 ( struct V_1 * V_5 )
{
int V_13 , V_79 = 0 ;
struct V_16 * T_2 ;
struct V_19 * V_20 ;
F_46 (prog, obj) {
int V_36 ;
V_13 = F_39 ( T_2 , ( void * * ) & V_20 ) ;
if ( V_13 || ! V_20 )
continue;
for ( V_36 = 0 ; V_36 < V_20 -> V_21 . V_68 ; V_36 ++ ) {
struct V_63 * V_64 = & V_20 -> V_21 . V_70 [ V_36 ] ;
char V_97 [ V_98 ] ;
struct V_99 * V_100 ;
snprintf ( V_97 , V_98 ,
L_34 , V_64 -> V_49 , V_64 -> V_52 ) ;
V_97 [ V_98 - 1 ] = '\0' ;
V_100 = F_49 ( V_97 , NULL ) ;
if ( ! V_100 ) {
F_5 ( L_35 ) ;
V_79 = - V_28 ;
continue;
}
V_13 = F_50 ( V_100 ) ;
F_51 ( V_100 ) ;
if ( V_13 ) {
F_5 ( L_36 , V_97 ) ;
V_79 = V_13 ;
continue;
}
}
}
return V_79 ;
}
int F_52 ( struct V_1 * V_5 )
{
int V_13 ;
V_13 = F_53 ( V_5 ) ;
if ( V_13 ) {
F_5 ( L_37 ) ;
return V_13 ;
}
return 0 ;
}
int F_54 ( struct V_1 * V_5 ,
T_3 F_26 ,
void * V_101 )
{
struct V_16 * T_2 ;
int V_13 ;
F_46 (prog, obj) {
struct V_63 * V_64 ;
struct V_25 * V_21 ;
struct V_19 * V_20 ;
int V_36 , V_102 ;
V_13 = F_39 ( T_2 ,
( void * * ) & V_20 ) ;
if ( V_13 || ! V_20 ) {
F_5 ( L_38 ) ;
return - V_95 ;
}
V_21 = & V_20 -> V_21 ;
for ( V_36 = 0 ; V_36 < V_21 -> V_68 ; V_36 ++ ) {
V_64 = & V_21 -> V_70 [ V_36 ] ;
if ( V_20 -> V_94 ) {
int type = V_20 -> V_23 [ V_36 ] ;
V_102 = F_55 ( T_2 , type ) ;
} else {
V_102 = F_56 ( T_2 ) ;
}
if ( V_102 < 0 ) {
F_5 ( L_39 ) ;
return V_102 ;
}
V_13 = (* F_26)( V_64 , V_102 , V_101 ) ;
if ( V_13 ) {
F_5 ( L_40 ) ;
return V_13 ;
}
}
}
return 0 ;
}
static int
F_57 ( int V_13 , char * V_65 , T_1 V_103 )
{
char V_104 [ V_105 ] ;
const char * V_106 ;
if ( ! V_65 || ! V_103 )
return - 1 ;
V_13 = V_13 > 0 ? V_13 : - V_13 ;
if ( V_13 >= V_107 )
return F_58 ( V_13 , V_65 , V_103 ) ;
if ( V_13 >= V_108 && V_13 < V_109 ) {
V_106 = V_110 [ F_59 ( V_13 ) ] ;
snprintf ( V_65 , V_103 , L_41 , V_106 ) ;
V_65 [ V_103 - 1 ] = '\0' ;
return 0 ;
}
if ( V_13 >= V_109 )
snprintf ( V_65 , V_103 , L_42 , V_13 ) ;
else
snprintf ( V_65 , V_103 , L_41 ,
F_60 ( V_13 , V_104 , sizeof( V_104 ) ) ) ;
V_65 [ V_103 - 1 ] = '\0' ;
return - 1 ;
}
int F_61 ( const char * V_11 , bool V_12 ,
int V_13 , char * V_65 , T_1 V_103 )
{
T_1 V_57 ;
int V_79 ;
V_57 = snprintf ( V_65 , V_103 , L_43 ,
V_11 , V_12 ? L_44 : L_45 ) ;
if ( V_57 >= V_103 ) {
V_65 [ V_103 - 1 ] = '\0' ;
return 0 ;
}
V_65 += V_57 ;
V_103 -= V_57 ;
V_79 = F_57 ( V_13 , V_65 , V_103 ) ;
V_65 [ V_103 - 1 ] = '\0' ;
return V_79 ;
}
int F_62 ( struct V_1 * V_5 V_17 ,
int V_13 , char * V_65 , T_1 V_103 )
{
F_63 ( V_13 , V_65 , V_103 ) ;
case V_40 : {
F_64 ( V_65 , V_103 , L_46 , V_111 ) ;
break;
}
F_65 ( V_112 , L_47 ) ;
F_65 ( V_113 , L_48 ) ;
F_65 ( V_114 , L_49 ) ;
F_65 ( V_115 , L_50 ) ;
F_66 ( V_65 , V_103 ) ;
return 0 ;
}
int F_67 ( struct V_1 * V_5 ,
int V_13 , char * V_65 , T_1 V_103 )
{
F_63 ( V_13 , V_65 , V_103 ) ;
case V_116 : {
unsigned int V_117 = F_68 ( V_5 ) ;
unsigned int V_118 ;
if ( F_69 ( & V_118 , NULL , 0 ) ) {
F_64 ( V_65 , V_103 , L_51 ) ;
break;
}
if ( V_117 != V_118 ) {
F_64 ( V_65 , V_103 ,
L_52 V_119 L_53 V_119 L_54 ,
F_70 ( V_117 ) ,
F_70 ( V_118 ) ) ;
break;
}
F_64 ( V_65 , V_103 , L_55 ) ;
break;
}
F_66 ( V_65 , V_103 ) ;
return 0 ;
}
