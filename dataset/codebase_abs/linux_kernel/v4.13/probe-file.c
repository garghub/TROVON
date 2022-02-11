static void F_1 ( int V_1 , bool V_2 )
{
char V_3 [ V_4 ] ;
if ( V_1 == - V_5 ) {
const char * V_6 ;
if ( V_2 )
V_6 = L_1 ;
else
V_6 = L_2 ;
F_2 ( L_3
L_4 ,
V_2 ? 'u' : 'k' , V_6 ) ;
} else if ( V_1 == - V_7 )
F_2 ( L_5 ) ;
else
F_2 ( L_6 ,
V_2 ? 'u' : 'k' ,
F_3 ( - V_1 , V_3 , sizeof( V_3 ) ) ) ;
}
static void F_4 ( int V_8 , int V_9 )
{
if ( V_8 == - V_7 && V_9 == - V_7 )
F_2 ( L_5 ) ;
else if ( V_8 == - V_5 && V_9 == - V_5 )
F_2 ( L_7
L_8 ) ;
else {
char V_3 [ V_4 ] ;
F_2 ( L_9 ,
F_3 ( - V_8 , V_3 , sizeof( V_3 ) ) ) ;
F_2 ( L_10 ,
F_3 ( - V_9 , V_3 , sizeof( V_3 ) ) ) ;
}
}
int F_5 ( const char * V_10 , bool V_11 )
{
char V_12 [ V_13 ] ;
int V_14 ;
V_14 = F_6 ( V_12 , V_13 , L_11 ,
V_15 , V_10 ) ;
if ( V_14 >= 0 ) {
F_7 ( L_12 , V_12 , V_11 ) ;
if ( V_11 && ! V_16 )
V_14 = F_8 ( V_12 , V_17 | V_18 , 0 ) ;
else
V_14 = F_8 ( V_12 , V_19 , 0 ) ;
if ( V_14 < 0 )
V_14 = - V_20 ;
}
return V_14 ;
}
static int F_9 ( bool V_11 )
{
return F_5 ( L_13 , V_11 ) ;
}
static int F_10 ( bool V_11 )
{
return F_5 ( L_14 , V_11 ) ;
}
int F_11 ( int V_21 )
{
int V_22 ;
if ( V_21 & V_23 )
V_22 = F_10 ( V_21 & V_24 ) ;
else
V_22 = F_9 ( V_21 & V_24 ) ;
if ( V_22 < 0 )
F_1 ( V_22 , V_21 & V_23 ) ;
return V_22 ;
}
int F_12 ( int * V_25 , int * V_26 , int V_21 )
{
if ( ! V_25 || ! V_26 )
return - V_27 ;
* V_25 = F_9 ( V_21 & V_24 ) ;
* V_26 = F_10 ( V_21 & V_24 ) ;
if ( * V_25 < 0 && * V_26 < 0 ) {
F_4 ( * V_25 , * V_26 ) ;
return * V_25 ;
}
return 0 ;
}
struct V_28 * F_13 ( int V_22 )
{
int V_14 , V_29 , V_30 ;
T_1 * V_31 ;
char V_12 [ V_32 ] ;
char * V_33 ;
struct V_28 * V_34 ;
if ( V_22 < 0 )
return NULL ;
V_34 = F_14 ( NULL , NULL ) ;
if ( V_34 == NULL )
return NULL ;
V_30 = F_15 ( V_22 ) ;
if ( V_30 < 0 )
goto V_35;
V_31 = fdopen ( V_30 , L_15 ) ;
if ( ! V_31 )
goto V_36;
while ( ! feof ( V_31 ) ) {
V_33 = fgets ( V_12 , V_32 , V_31 ) ;
if ( ! V_33 )
break;
V_29 = strlen ( V_33 ) - 1 ;
if ( V_33 [ V_29 ] == '\n' )
V_33 [ V_29 ] = '\0' ;
V_14 = F_16 ( V_34 , V_12 ) ;
if ( V_14 < 0 ) {
F_7 ( L_16 , V_14 ) ;
goto V_37;
}
}
fclose ( V_31 ) ;
return V_34 ;
V_37:
fclose ( V_31 ) ;
goto V_35;
V_36:
F_17 ( V_30 ) ;
V_35:
F_18 ( V_34 ) ;
return NULL ;
}
static struct V_28 * F_19 ( int V_22 , bool V_38 )
{
char V_12 [ 128 ] ;
struct V_28 * V_34 , * V_39 ;
struct V_40 * V_41 ;
struct V_42 V_43 ;
int V_14 = 0 ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_39 = F_13 ( V_22 ) ;
if ( ! V_39 )
return NULL ;
V_34 = F_14 ( NULL , NULL ) ;
F_20 (ent, rawlist) {
V_14 = F_21 ( V_41 -> V_44 , & V_43 ) ;
if ( V_14 < 0 )
break;
if ( V_38 ) {
V_14 = F_6 ( V_12 , 128 , L_17 , V_43 . V_45 ,
V_43 . V_46 ) ;
if ( V_14 >= 0 )
V_14 = F_16 ( V_34 , V_12 ) ;
} else
V_14 = F_16 ( V_34 , V_43 . V_46 ) ;
F_22 ( & V_43 ) ;
if ( V_14 < 0 )
break;
}
F_18 ( V_39 ) ;
if ( V_14 < 0 ) {
F_18 ( V_34 ) ;
return NULL ;
}
return V_34 ;
}
struct V_28 * F_23 ( int V_22 )
{
return F_19 ( V_22 , false ) ;
}
int F_24 ( int V_22 , struct V_42 * V_43 )
{
int V_14 = 0 ;
char * V_12 = F_25 ( V_43 ) ;
char V_3 [ V_4 ] ;
if ( ! V_12 ) {
F_7 ( L_18 ) ;
return - V_27 ;
}
F_7 ( L_19 , V_12 ) ;
if ( ! V_16 ) {
if ( F_26 ( V_22 , V_12 , strlen ( V_12 ) ) < ( int ) strlen ( V_12 ) ) {
V_14 = - V_20 ;
F_2 ( L_20 ,
F_3 ( V_20 , V_3 , sizeof( V_3 ) ) ) ;
}
}
free ( V_12 ) ;
return V_14 ;
}
static int F_27 ( int V_22 , struct V_40 * V_41 )
{
char * V_33 ;
char V_12 [ 128 ] ;
int V_14 ;
V_14 = F_6 ( V_12 , 128 , L_21 , V_41 -> V_44 ) ;
if ( V_14 < 0 )
goto error;
V_33 = strchr ( V_12 + 2 , ':' ) ;
if ( ! V_33 ) {
F_7 ( L_22 ,
V_41 -> V_44 ) ;
V_14 = - V_7 ;
goto error;
}
* V_33 = '/' ;
F_7 ( L_19 , V_12 ) ;
V_14 = F_26 ( V_22 , V_12 , strlen ( V_12 ) ) ;
if ( V_14 < 0 ) {
V_14 = - V_20 ;
goto error;
}
return 0 ;
error:
F_2 ( L_23 ,
F_3 ( - V_14 , V_12 , sizeof( V_12 ) ) ) ;
return V_14 ;
}
int F_28 ( int V_22 , struct V_47 * V_48 ,
struct V_28 * V_49 )
{
struct V_28 * V_50 ;
struct V_40 * V_41 ;
const char * V_33 ;
int V_14 = - V_5 ;
if ( ! V_49 )
return - V_27 ;
V_50 = F_19 ( V_22 , true ) ;
if ( ! V_50 )
return - V_5 ;
F_20 (ent, namelist) {
V_33 = strchr ( V_41 -> V_44 , ':' ) ;
if ( ( V_33 && F_29 ( V_48 , V_33 + 1 ) ) ||
F_29 ( V_48 , V_41 -> V_44 ) ) {
F_16 ( V_49 , V_41 -> V_44 ) ;
V_14 = 0 ;
}
}
F_18 ( V_50 ) ;
return V_14 ;
}
int F_30 ( int V_22 , struct V_28 * V_50 )
{
int V_14 = 0 ;
struct V_40 * V_41 ;
F_20 (ent, namelist) {
V_14 = F_27 ( V_22 , V_41 ) ;
if ( V_14 < 0 )
break;
}
return V_14 ;
}
int F_31 ( int V_22 , struct V_47 * V_48 )
{
struct V_28 * V_50 ;
int V_14 ;
V_50 = F_14 ( NULL , NULL ) ;
if ( ! V_50 )
return - V_51 ;
V_14 = F_28 ( V_22 , V_48 , V_50 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_30 ( V_22 , V_50 ) ;
F_18 ( V_50 ) ;
return V_14 ;
}
static void F_32 ( struct V_52 * V_53 )
{
if ( V_53 ) {
F_33 ( ! F_34 ( & V_53 -> V_54 ) ) ;
F_18 ( V_53 -> V_55 ) ;
F_35 ( & V_53 -> V_56 ) ;
F_36 ( & V_53 -> V_57 ) ;
free ( V_53 ) ;
}
}
static struct V_52 *
F_37 ( struct V_58 * V_56 )
{
struct V_52 * V_53 = F_38 ( sizeof( * V_53 ) ) ;
if ( V_53 ) {
F_39 ( & V_53 -> V_54 ) ;
V_53 -> V_55 = F_14 ( NULL , NULL ) ;
if ( ! V_53 -> V_55 )
F_36 ( & V_53 ) ;
else if ( V_56 ) {
V_53 -> V_57 = F_40 ( V_56 ) ;
if ( ! V_53 -> V_57 ||
F_41 ( & V_53 -> V_56 , V_56 ) < 0 ) {
F_32 ( V_53 ) ;
return NULL ;
}
}
}
return V_53 ;
}
int F_42 ( struct V_52 * V_53 ,
struct V_42 * * V_59 )
{
struct V_42 * V_43 ;
struct V_40 * V_54 ;
int V_14 , V_60 ;
V_14 = F_43 ( V_53 -> V_55 ) ;
if ( V_14 > V_61 . V_62 )
return - V_63 ;
* V_59 = F_38 ( V_14 * sizeof( * V_43 ) ) ;
if ( ! * V_59 )
return - V_51 ;
V_60 = 0 ;
F_20 (node, entry->tevlist) {
V_43 = & ( * V_59 ) [ V_60 ++ ] ;
V_14 = F_21 ( V_54 -> V_44 , V_43 ) ;
if ( V_14 < 0 )
break;
}
return V_60 ;
}
static int F_44 ( struct V_64 * V_65 , const char * V_66 )
{
char V_67 [ V_13 ] ;
char V_68 [ V_69 ] ;
char * V_70 = NULL ;
bool V_71 = false ;
int V_14 , V_22 ;
if ( V_66 && F_45 ( V_66 ) ) {
strncpy ( V_68 , V_66 , V_69 ) ;
V_70 = F_46 ( V_68 , NULL , 0 ) ;
goto V_72;
}
if ( ! V_66 || ! strcmp ( V_66 , V_73 ) ) {
V_66 = V_73 ;
V_71 = true ;
V_14 = F_47 ( L_24 , V_68 ) ;
} else
V_14 = F_48 ( V_66 , V_68 ) ;
if ( V_14 < 0 ) {
F_7 ( L_25 , V_66 ) ;
return V_14 ;
}
if ( ! F_45 ( V_68 ) ) {
V_14 = F_49 ( V_68 , V_66 ,
V_71 , NULL ) ;
if ( V_14 < 0 ) {
F_7 ( L_26 , V_66 ) ;
return V_14 ;
}
}
V_70 = F_50 ( V_68 , V_66 , V_71 ,
false ) ;
V_72:
if ( ! V_70 ) {
F_7 ( L_27 , V_66 ) ;
return - V_51 ;
}
snprintf ( V_67 , V_13 , L_28 , V_70 ) ;
V_22 = F_8 ( V_67 , V_74 | V_17 , 0644 ) ;
if ( V_22 < 0 )
F_7 ( L_29 , V_22 , V_67 ) ;
free ( V_70 ) ;
V_65 -> V_22 = V_22 ;
return V_22 ;
}
static int F_51 ( struct V_64 * V_65 )
{
struct V_52 * V_53 = NULL ;
char V_12 [ V_32 ] , * V_33 ;
int V_14 = 0 , V_30 ;
T_1 * V_31 ;
V_30 = F_15 ( V_65 -> V_22 ) ;
if ( V_30 < 0 )
return - V_20 ;
V_31 = fdopen ( V_30 , L_15 ) ;
if ( ! V_31 ) {
F_17 ( V_30 ) ;
return - V_27 ;
}
while ( ! feof ( V_31 ) ) {
if ( ! fgets ( V_12 , V_32 , V_31 ) )
break;
V_33 = strchr ( V_12 , '\n' ) ;
if ( V_33 )
* V_33 = '\0' ;
if ( V_12 [ 0 ] == '#' || V_12 [ 0 ] == '%' ) {
V_53 = F_37 ( NULL ) ;
if ( ! V_53 ) {
V_14 = - V_51 ;
goto V_75;
}
if ( V_12 [ 0 ] == '%' )
V_53 -> V_76 = true ;
V_53 -> V_57 = F_52 ( V_12 + 1 ) ;
if ( V_53 -> V_57 )
V_14 = F_53 ( V_12 + 1 ,
& V_53 -> V_56 ) ;
else
V_14 = - V_51 ;
if ( V_14 < 0 ) {
F_32 ( V_53 ) ;
goto V_75;
}
F_54 ( & V_53 -> V_54 , & V_65 -> V_77 ) ;
} else {
if ( ! V_53 ) {
V_14 = - V_27 ;
goto V_75;
}
F_16 ( V_53 -> V_55 , V_12 ) ;
}
}
V_75:
fclose ( V_31 ) ;
return V_14 ;
}
static struct V_64 * F_55 ( void )
{
struct V_64 * V_65 = F_38 ( sizeof( * V_65 ) ) ;
if ( V_65 ) {
F_39 ( & V_65 -> V_77 ) ;
V_65 -> V_22 = - V_27 ;
}
return V_65 ;
}
void F_56 ( struct V_64 * V_65 )
{
struct V_52 * V_53 , * V_78 ;
F_57 (entry, n, &pcache->entries, node) {
F_58 ( & V_53 -> V_54 ) ;
F_32 ( V_53 ) ;
}
}
void F_59 ( struct V_64 * V_65 )
{
if ( ! V_65 )
return;
F_56 ( V_65 ) ;
if ( V_65 -> V_22 > 0 )
F_17 ( V_65 -> V_22 ) ;
free ( V_65 ) ;
}
struct V_64 * F_60 ( const char * V_66 )
{
struct V_64 * V_65 = F_55 () ;
int V_14 ;
if ( ! V_65 )
return NULL ;
V_14 = F_44 ( V_65 , V_66 ) ;
if ( V_14 < 0 ) {
F_7 ( L_30 , V_14 ) ;
goto V_79;
}
V_14 = F_51 ( V_65 ) ;
if ( V_14 < 0 ) {
F_7 ( L_31 , V_14 ) ;
goto V_79;
}
return V_65 ;
V_79:
F_59 ( V_65 ) ;
return NULL ;
}
static bool F_61 ( const char * V_80 , const char * V_81 )
{
if ( V_80 == V_81 )
return true ;
if ( ! V_80 || ! V_81 )
return false ;
return ! strcmp ( V_80 , V_81 ) ;
}
struct V_52 *
F_62 ( struct V_64 * V_65 , struct V_58 * V_56 )
{
struct V_52 * V_53 = NULL ;
char * V_82 = F_40 ( V_56 ) ;
if ( ! V_82 )
return NULL ;
F_63 (entry, pcache) {
if ( V_56 -> V_76 ) {
if ( V_53 -> V_56 . V_46 &&
F_61 ( V_53 -> V_56 . V_46 , V_56 -> V_46 ) &&
( ! V_56 -> V_45 ||
F_61 ( V_53 -> V_56 . V_45 , V_56 -> V_45 ) ) )
goto V_72;
continue;
}
if ( ( V_56 -> V_46 &&
( F_61 ( V_53 -> V_56 . V_45 , V_56 -> V_45 ) &&
F_61 ( V_53 -> V_56 . V_46 , V_56 -> V_46 ) ) ) ||
( ! strcmp ( V_53 -> V_57 , V_82 ) ) )
goto V_72;
}
V_53 = NULL ;
V_72:
free ( V_82 ) ;
return V_53 ;
}
struct V_52 *
F_64 ( struct V_64 * V_65 ,
const char * V_45 , const char * V_46 )
{
struct V_52 * V_53 = NULL ;
F_63 (entry, pcache) {
if ( F_61 ( V_53 -> V_56 . V_45 , V_45 ) &&
F_61 ( V_53 -> V_56 . V_46 , V_46 ) )
goto V_72;
}
V_53 = NULL ;
V_72:
return V_53 ;
}
int F_65 ( struct V_64 * V_65 ,
struct V_58 * V_56 ,
struct V_42 * V_59 , int V_83 )
{
struct V_52 * V_53 = NULL ;
char * V_84 ;
int V_60 , V_14 = 0 ;
if ( ! V_65 || ! V_56 || ! V_59 || V_83 <= 0 ) {
V_14 = - V_27 ;
goto V_79;
}
V_53 = F_62 ( V_65 , V_56 ) ;
if ( V_53 ) {
F_58 ( & V_53 -> V_54 ) ;
F_32 ( V_53 ) ;
}
V_14 = - V_51 ;
V_53 = F_37 ( V_56 ) ;
if ( ! V_53 )
goto V_79;
for ( V_60 = 0 ; V_60 < V_83 ; V_60 ++ ) {
if ( ! V_59 [ V_60 ] . V_85 . V_86 )
continue;
V_84 = F_25 ( & V_59 [ V_60 ] ) ;
if ( ! V_84 )
goto V_79;
F_16 ( V_53 -> V_55 , V_84 ) ;
free ( V_84 ) ;
}
F_54 ( & V_53 -> V_54 , & V_65 -> V_77 ) ;
F_7 ( L_32 , V_83 ) ;
return 0 ;
V_79:
F_7 ( L_33 ) ;
F_32 ( V_53 ) ;
return V_14 ;
}
static unsigned long long F_66 ( struct V_87 * V_88 )
{
return V_88 -> V_89 ? ( unsigned long long ) V_88 -> V_90 . V_91 [ 0 ]
: ( unsigned long long ) V_88 -> V_90 . V_92 [ 0 ] ;
}
static int F_67 ( char * V_93 , const char * * V_94 )
{
long V_95 ;
V_95 = strtol ( V_93 , NULL , 10 ) ;
if ( V_95 < - 8 || V_95 > 8 ) {
F_68 ( L_34 ) ;
return - 1 ;
}
* V_94 = V_96 [ V_95 + 8 ] ;
return 0 ;
}
static int F_69 ( struct V_97 * V_12 , int V_60 , const char * V_98 )
{
char * V_99 , * V_100 = F_52 ( V_98 ) , * V_101 = NULL ;
const char * V_94 = L_35 ;
int V_14 = - 1 ;
if ( V_100 == NULL ) {
F_68 ( L_36 ) ;
return V_14 ;
}
V_99 = strchr ( V_100 , '@' ) ;
if ( V_99 ) {
V_99 [ 0 ] = '\0' ;
V_99 ++ ;
if ( F_67 ( V_100 , & V_94 ) )
goto error;
} else {
V_99 = V_100 ;
}
V_14 = F_70 ( V_99 , & V_101 ) ;
if ( V_14 < 0 )
goto error;
if ( V_14 == V_102 ) {
V_14 = F_71 ( V_12 , L_37 , V_60 + 1 , V_101 , V_94 ) ;
if ( V_14 < 0 )
goto error;
}
V_14 = 0 ;
error:
free ( V_100 ) ;
free ( V_101 ) ;
return V_14 ;
}
static char * F_72 ( struct V_87 * V_88 ,
const char * V_103 ,
const char * V_104 )
{
struct V_97 V_12 ;
char * V_14 = NULL , * * args ;
int V_60 , V_105 ;
if ( F_73 ( & V_12 , 32 ) < 0 )
return NULL ;
if ( F_71 ( & V_12 , L_38 ,
V_104 , V_88 -> V_106 , V_103 ,
F_66 ( V_88 ) ) < 0 )
goto error;
if ( ! V_88 -> args )
goto V_75;
if ( V_88 -> args ) {
args = F_74 ( V_88 -> args , & V_105 ) ;
for ( V_60 = 0 ; V_60 < V_105 ; ++ V_60 ) {
if ( F_69 ( & V_12 , V_60 , args [ V_60 ] ) < 0 )
goto error;
}
}
V_75:
V_14 = F_75 ( & V_12 , NULL ) ;
error:
F_76 ( & V_12 ) ;
return V_14 ;
}
int F_77 ( struct V_64 * V_65 , const char * V_103 )
{
struct V_52 * V_53 = NULL ;
struct V_107 V_108 ;
struct V_87 * V_88 ;
char * V_12 ;
char V_104 [ 64 ] ;
int V_14 ;
F_39 ( & V_108 ) ;
V_14 = F_78 ( & V_108 , V_103 ) ;
if ( V_14 < 0 ) {
F_68 ( L_39 , V_14 ) ;
return V_14 ;
}
F_79 (note, &sdtlist, note_list) {
V_14 = snprintf ( V_104 , 64 , L_40 , V_88 -> V_109 ) ;
if ( V_14 < 0 )
break;
V_53 = F_64 ( V_65 , V_104 , V_88 -> V_106 ) ;
if ( ! V_53 ) {
V_53 = F_37 ( NULL ) ;
if ( ! V_53 ) {
V_14 = - V_51 ;
break;
}
V_53 -> V_76 = true ;
V_14 = F_80 ( & V_53 -> V_57 , L_41 , V_104 ,
V_88 -> V_106 , V_88 -> V_106 ) ;
if ( V_14 < 0 )
break;
V_53 -> V_56 . V_46 = F_52 ( V_88 -> V_106 ) ;
V_53 -> V_56 . V_45 = F_52 ( V_104 ) ;
F_54 ( & V_53 -> V_54 , & V_65 -> V_77 ) ;
}
V_12 = F_72 ( V_88 , V_103 , V_104 ) ;
if ( ! V_12 ) {
V_14 = - V_51 ;
break;
}
F_16 ( V_53 -> V_55 , V_12 ) ;
free ( V_12 ) ;
V_53 = NULL ;
}
if ( V_53 ) {
F_58 ( & V_53 -> V_54 ) ;
F_32 ( V_53 ) ;
}
F_81 ( & V_108 ) ;
return V_14 ;
}
static int F_82 ( struct V_52 * V_53 , int V_22 )
{
struct V_40 * V_110 ;
struct V_111 V_112 ;
struct V_113 V_114 [ 3 ] ;
const char * V_115 = V_53 -> V_76 ? L_42 : L_43 ;
int V_14 ;
V_14 = F_83 ( V_22 , & V_112 ) ;
if ( V_14 < 0 )
return V_14 ;
F_7 ( L_44 , V_115 , V_53 -> V_57 ) ;
V_114 [ 0 ] . V_116 = ( void * ) V_115 ; V_114 [ 0 ] . V_117 = 1 ;
V_114 [ 1 ] . V_116 = V_53 -> V_57 ; V_114 [ 1 ] . V_117 = strlen ( V_53 -> V_57 ) ;
V_114 [ 2 ] . V_116 = ( void * ) L_45 ; V_114 [ 2 ] . V_117 = 1 ;
V_14 = F_84 ( V_22 , V_114 , 3 ) ;
if ( V_14 < ( int ) V_114 [ 1 ] . V_117 + 2 )
goto V_118;
F_20 (snode, entry->tevlist) {
V_114 [ 0 ] . V_116 = ( void * ) V_110 -> V_44 ;
V_114 [ 0 ] . V_117 = strlen ( V_110 -> V_44 ) ;
V_114 [ 1 ] . V_116 = ( void * ) L_45 ; V_114 [ 1 ] . V_117 = 1 ;
V_14 = F_84 ( V_22 , V_114 , 2 ) ;
if ( V_14 < ( int ) V_114 [ 0 ] . V_117 + 1 )
goto V_118;
}
return 0 ;
V_118:
if ( V_14 > 0 )
V_14 = - 1 ;
if ( F_85 ( V_22 , V_112 . V_119 ) < 0 )
V_14 = - 2 ;
return V_14 ;
}
int F_86 ( struct V_64 * V_65 )
{
struct V_52 * V_53 ;
int V_14 = 0 ;
V_14 = F_87 ( V_65 -> V_22 , 0 , V_120 ) ;
if ( V_14 < 0 )
goto V_75;
V_14 = F_85 ( V_65 -> V_22 , 0 ) ;
if ( V_14 < 0 )
goto V_75;
F_63 (entry, pcache) {
V_14 = F_82 ( V_53 , V_65 -> V_22 ) ;
F_7 ( L_46 , V_14 ) ;
if ( V_14 < 0 )
break;
}
V_75:
return V_14 ;
}
static bool F_88 ( struct V_52 * V_53 ,
struct V_47 * V_48 )
{
char V_12 [ 128 ] , * V_121 = V_53 -> V_57 ;
if ( V_53 -> V_56 . V_46 ) {
snprintf ( V_12 , 128 , L_17 , V_53 -> V_56 . V_45 , V_53 -> V_56 . V_46 ) ;
V_121 = V_12 ;
}
return F_29 ( V_48 , V_121 ) ;
}
int F_89 ( struct V_64 * V_65 ,
struct V_47 * V_48 )
{
struct V_52 * V_53 , * V_122 ;
F_57 (entry, tmp, &pcache->entries, node) {
if ( F_88 ( V_53 , V_48 ) ) {
F_90 ( L_47 , V_53 -> V_57 ) ;
F_58 ( & V_53 -> V_54 ) ;
F_32 ( V_53 ) ;
}
}
return 0 ;
}
static int F_91 ( struct V_64 * V_65 ,
struct V_47 * V_48 )
{
struct V_52 * V_53 ;
F_63 (entry, pcache) {
if ( F_88 ( V_53 , V_48 ) )
printf ( L_48 , V_53 -> V_57 ) ;
}
return 0 ;
}
int F_92 ( struct V_47 * V_48 )
{
struct V_64 * V_65 ;
struct V_28 * V_123 ;
struct V_40 * V_124 ;
char * V_12 = F_93 ( V_48 ) ;
F_7 ( L_49 , V_12 ) ;
free ( V_12 ) ;
V_123 = F_94 ( true ) ;
if ( ! V_123 ) {
F_7 ( L_50 , V_20 ) ;
return - V_27 ;
}
F_20 (nd, bidlist) {
V_65 = F_60 ( V_124 -> V_44 ) ;
if ( ! V_65 )
continue;
if ( ! F_34 ( & V_65 -> V_77 ) ) {
V_12 = F_95 ( V_124 -> V_44 ) ;
printf ( L_51 , V_12 , V_124 -> V_44 ) ;
free ( V_12 ) ;
F_91 ( V_65 , V_48 ) ;
}
F_59 ( V_65 ) ;
}
F_18 ( V_123 ) ;
return 0 ;
}
static bool F_96 ( enum V_125 type )
{
int V_22 ;
T_1 * V_31 ;
char * V_12 = NULL ;
T_2 V_126 = 0 ;
bool V_14 = false ;
static bool V_127 = false ;
if ( V_127 )
goto V_128;
V_22 = F_5 ( L_52 , false ) ;
if ( V_22 < 0 )
return V_14 ;
V_31 = fdopen ( V_22 , L_15 ) ;
if ( ! V_31 ) {
F_17 ( V_22 ) ;
return V_14 ;
}
while ( F_97 ( & V_12 , & V_126 , V_31 ) > 0 )
for ( enum V_125 V_60 = 0 ; V_60 < V_129 ; V_60 ++ )
if ( ! V_130 [ V_60 ] . V_131 )
V_130 [ V_60 ] . V_131 =
F_98 ( V_12 , V_130 [ V_60 ] . V_132 ) ;
V_127 = true ;
fclose ( V_31 ) ;
free ( V_12 ) ;
V_128:
if ( type >= V_129 )
return false ;
return V_130 [ type ] . V_131 ;
}
bool F_99 ( enum V_133 type )
{
if ( type >= V_134 )
return false ;
else if ( type == V_135 )
return F_96 ( V_136 ) ;
return true ;
}
bool F_100 ( void )
{
return F_96 ( V_137 ) ;
}
