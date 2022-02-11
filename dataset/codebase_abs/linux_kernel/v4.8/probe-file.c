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
static int F_5 ( const char * V_10 , bool V_11 )
{
char V_12 [ V_13 ] ;
const char * V_14 = L_11 ;
int V_15 ;
V_15 = F_6 ( V_12 , V_13 , L_12 ,
V_16 , V_14 , V_10 ) ;
if ( V_15 >= 0 ) {
F_7 ( L_13 , V_12 , V_11 ) ;
if ( V_11 && ! V_17 )
V_15 = F_8 ( V_12 , V_18 | V_19 , 0 ) ;
else
V_15 = F_8 ( V_12 , V_20 , 0 ) ;
if ( V_15 < 0 )
V_15 = - V_21 ;
}
return V_15 ;
}
static int F_9 ( bool V_11 )
{
return F_5 ( L_14 , V_11 ) ;
}
static int F_10 ( bool V_11 )
{
return F_5 ( L_15 , V_11 ) ;
}
int F_11 ( int V_22 )
{
int V_23 ;
if ( V_22 & V_24 )
V_23 = F_10 ( V_22 & V_25 ) ;
else
V_23 = F_9 ( V_22 & V_25 ) ;
if ( V_23 < 0 )
F_1 ( V_23 , V_22 & V_24 ) ;
return V_23 ;
}
int F_12 ( int * V_26 , int * V_27 , int V_22 )
{
if ( ! V_26 || ! V_27 )
return - V_28 ;
* V_26 = F_9 ( V_22 & V_25 ) ;
* V_27 = F_10 ( V_22 & V_25 ) ;
if ( * V_26 < 0 && * V_27 < 0 ) {
F_4 ( * V_26 , * V_27 ) ;
return * V_26 ;
}
return 0 ;
}
struct V_29 * F_13 ( int V_23 )
{
int V_15 , V_30 , V_31 ;
T_1 * V_32 ;
char V_12 [ V_33 ] ;
char * V_34 ;
struct V_29 * V_35 ;
if ( V_23 < 0 )
return NULL ;
V_35 = F_14 ( NULL , NULL ) ;
if ( V_35 == NULL )
return NULL ;
V_31 = F_15 ( V_23 ) ;
if ( V_31 < 0 )
goto V_36;
V_32 = fdopen ( V_31 , L_16 ) ;
if ( ! V_32 )
goto V_37;
while ( ! feof ( V_32 ) ) {
V_34 = fgets ( V_12 , V_33 , V_32 ) ;
if ( ! V_34 )
break;
V_30 = strlen ( V_34 ) - 1 ;
if ( V_34 [ V_30 ] == '\n' )
V_34 [ V_30 ] = '\0' ;
V_15 = F_16 ( V_35 , V_12 ) ;
if ( V_15 < 0 ) {
F_7 ( L_17 , V_15 ) ;
goto V_38;
}
}
fclose ( V_32 ) ;
return V_35 ;
V_38:
fclose ( V_32 ) ;
goto V_36;
V_37:
F_17 ( V_31 ) ;
V_36:
F_18 ( V_35 ) ;
return NULL ;
}
static struct V_29 * F_19 ( int V_23 , bool V_39 )
{
char V_12 [ 128 ] ;
struct V_29 * V_35 , * V_40 ;
struct V_41 * V_42 ;
struct V_43 V_44 ;
int V_15 = 0 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
V_40 = F_13 ( V_23 ) ;
if ( ! V_40 )
return NULL ;
V_35 = F_14 ( NULL , NULL ) ;
F_20 (ent, rawlist) {
V_15 = F_21 ( V_42 -> V_45 , & V_44 ) ;
if ( V_15 < 0 )
break;
if ( V_39 ) {
V_15 = F_6 ( V_12 , 128 , L_18 , V_44 . V_46 ,
V_44 . V_47 ) ;
if ( V_15 >= 0 )
V_15 = F_16 ( V_35 , V_12 ) ;
} else
V_15 = F_16 ( V_35 , V_44 . V_47 ) ;
F_22 ( & V_44 ) ;
if ( V_15 < 0 )
break;
}
F_18 ( V_40 ) ;
if ( V_15 < 0 ) {
F_18 ( V_35 ) ;
return NULL ;
}
return V_35 ;
}
struct V_29 * F_23 ( int V_23 )
{
return F_19 ( V_23 , false ) ;
}
int F_24 ( int V_23 , struct V_43 * V_44 )
{
int V_15 = 0 ;
char * V_12 = F_25 ( V_44 ) ;
char V_3 [ V_4 ] ;
if ( ! V_12 ) {
F_7 ( L_19 ) ;
return - V_28 ;
}
F_7 ( L_20 , V_12 ) ;
if ( ! V_17 ) {
if ( F_26 ( V_23 , V_12 , strlen ( V_12 ) ) < ( int ) strlen ( V_12 ) ) {
V_15 = - V_21 ;
F_2 ( L_21 ,
F_3 ( V_21 , V_3 , sizeof( V_3 ) ) ) ;
}
}
free ( V_12 ) ;
return V_15 ;
}
static int F_27 ( int V_23 , struct V_41 * V_42 )
{
char * V_34 ;
char V_12 [ 128 ] ;
int V_15 ;
V_15 = F_6 ( V_12 , 128 , L_22 , V_42 -> V_45 ) ;
if ( V_15 < 0 )
goto error;
V_34 = strchr ( V_12 + 2 , ':' ) ;
if ( ! V_34 ) {
F_7 ( L_23 ,
V_42 -> V_45 ) ;
V_15 = - V_7 ;
goto error;
}
* V_34 = '/' ;
F_7 ( L_20 , V_12 ) ;
V_15 = F_26 ( V_23 , V_12 , strlen ( V_12 ) ) ;
if ( V_15 < 0 ) {
V_15 = - V_21 ;
goto error;
}
return 0 ;
error:
F_2 ( L_24 ,
F_3 ( - V_15 , V_12 , sizeof( V_12 ) ) ) ;
return V_15 ;
}
int F_28 ( int V_23 , struct V_48 * V_49 ,
struct V_29 * V_50 )
{
struct V_29 * V_51 ;
struct V_41 * V_42 ;
const char * V_34 ;
int V_15 = - V_5 ;
if ( ! V_50 )
return - V_28 ;
V_51 = F_19 ( V_23 , true ) ;
if ( ! V_51 )
return - V_5 ;
F_20 (ent, namelist) {
V_34 = strchr ( V_42 -> V_45 , ':' ) ;
if ( ( V_34 && F_29 ( V_49 , V_34 + 1 ) ) ||
F_29 ( V_49 , V_42 -> V_45 ) ) {
F_16 ( V_50 , V_42 -> V_45 ) ;
V_15 = 0 ;
}
}
F_18 ( V_51 ) ;
return V_15 ;
}
int F_30 ( int V_23 , struct V_29 * V_51 )
{
int V_15 = 0 ;
struct V_41 * V_42 ;
F_20 (ent, namelist) {
V_15 = F_27 ( V_23 , V_42 ) ;
if ( V_15 < 0 )
break;
}
return V_15 ;
}
int F_31 ( int V_23 , struct V_48 * V_49 )
{
struct V_29 * V_51 ;
int V_15 ;
V_51 = F_14 ( NULL , NULL ) ;
if ( ! V_51 )
return - V_52 ;
V_15 = F_28 ( V_23 , V_49 , V_51 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_30 ( V_23 , V_51 ) ;
F_18 ( V_51 ) ;
return V_15 ;
}
static void F_32 ( struct V_53 * V_54 )
{
if ( V_54 ) {
F_33 ( ! F_34 ( & V_54 -> V_55 ) ) ;
F_18 ( V_54 -> V_56 ) ;
F_35 ( & V_54 -> V_57 ) ;
F_36 ( & V_54 -> V_58 ) ;
free ( V_54 ) ;
}
}
static struct V_53 *
F_37 ( struct V_59 * V_57 )
{
struct V_53 * V_54 = F_38 ( sizeof( * V_54 ) ) ;
if ( V_54 ) {
F_39 ( & V_54 -> V_55 ) ;
V_54 -> V_56 = F_14 ( NULL , NULL ) ;
if ( ! V_54 -> V_56 )
F_36 ( & V_54 ) ;
else if ( V_57 ) {
V_54 -> V_58 = F_40 ( V_57 ) ;
if ( ! V_54 -> V_58 ||
F_41 ( & V_54 -> V_57 , V_57 ) < 0 ) {
F_32 ( V_54 ) ;
return NULL ;
}
}
}
return V_54 ;
}
int F_42 ( struct V_53 * V_54 ,
struct V_43 * * V_60 )
{
struct V_43 * V_44 ;
struct V_41 * V_55 ;
int V_15 , V_61 ;
V_15 = F_43 ( V_54 -> V_56 ) ;
if ( V_15 > V_62 . V_63 )
return - V_64 ;
* V_60 = F_38 ( V_15 * sizeof( * V_44 ) ) ;
if ( ! * V_60 )
return - V_52 ;
V_61 = 0 ;
F_20 (node, entry->tevlist) {
V_44 = & ( * V_60 ) [ V_61 ++ ] ;
V_15 = F_21 ( V_55 -> V_45 , V_44 ) ;
if ( V_15 < 0 )
break;
}
return V_61 ;
}
static int F_44 ( struct V_65 * V_66 , const char * V_67 )
{
char V_68 [ V_13 ] ;
char V_69 [ V_70 ] ;
char * V_71 = NULL ;
bool V_72 = false ;
int V_15 , V_23 ;
if ( V_67 && F_45 ( V_67 ) ) {
strncpy ( V_69 , V_67 , V_70 ) ;
V_71 = F_46 ( V_69 , NULL , 0 ) ;
goto V_73;
}
if ( ! V_67 || ! strcmp ( V_67 , V_74 ) ) {
V_67 = V_74 ;
V_72 = true ;
V_15 = F_47 ( L_25 , V_69 ) ;
} else
V_15 = F_48 ( V_67 , V_69 ) ;
if ( V_15 < 0 ) {
F_7 ( L_26 , V_67 ) ;
return V_15 ;
}
if ( ! F_45 ( V_69 ) ) {
V_15 = F_49 ( V_69 , V_67 ,
V_72 , NULL ) ;
if ( V_15 < 0 ) {
F_7 ( L_27 , V_67 ) ;
return V_15 ;
}
}
V_71 = F_50 ( V_69 , V_67 , V_72 ,
false ) ;
V_73:
if ( ! V_71 ) {
F_7 ( L_28 , V_67 ) ;
return - V_52 ;
}
snprintf ( V_68 , V_13 , L_29 , V_71 ) ;
V_23 = F_8 ( V_68 , V_75 | V_18 , 0644 ) ;
if ( V_23 < 0 )
F_7 ( L_30 , V_23 , V_68 ) ;
free ( V_71 ) ;
V_66 -> V_23 = V_23 ;
return V_23 ;
}
static int F_51 ( struct V_65 * V_66 )
{
struct V_53 * V_54 = NULL ;
char V_12 [ V_33 ] , * V_34 ;
int V_15 = 0 , V_31 ;
T_1 * V_32 ;
V_31 = F_15 ( V_66 -> V_23 ) ;
if ( V_31 < 0 )
return - V_21 ;
V_32 = fdopen ( V_31 , L_16 ) ;
if ( ! V_32 ) {
F_17 ( V_31 ) ;
return - V_28 ;
}
while ( ! feof ( V_32 ) ) {
if ( ! fgets ( V_12 , V_33 , V_32 ) )
break;
V_34 = strchr ( V_12 , '\n' ) ;
if ( V_34 )
* V_34 = '\0' ;
if ( V_12 [ 0 ] == '#' || V_12 [ 0 ] == '%' ) {
V_54 = F_37 ( NULL ) ;
if ( ! V_54 ) {
V_15 = - V_52 ;
goto V_76;
}
if ( V_12 [ 0 ] == '%' )
V_54 -> V_77 = true ;
V_54 -> V_58 = F_52 ( V_12 + 1 ) ;
if ( V_54 -> V_58 )
V_15 = F_53 ( V_12 + 1 ,
& V_54 -> V_57 ) ;
else
V_15 = - V_52 ;
if ( V_15 < 0 ) {
F_32 ( V_54 ) ;
goto V_76;
}
F_54 ( & V_54 -> V_55 , & V_66 -> V_78 ) ;
} else {
if ( ! V_54 ) {
V_15 = - V_28 ;
goto V_76;
}
F_16 ( V_54 -> V_56 , V_12 ) ;
}
}
V_76:
fclose ( V_32 ) ;
return V_15 ;
}
static struct V_65 * F_55 ( void )
{
struct V_65 * V_66 = F_38 ( sizeof( * V_66 ) ) ;
if ( V_66 ) {
F_39 ( & V_66 -> V_78 ) ;
V_66 -> V_23 = - V_28 ;
}
return V_66 ;
}
void F_56 ( struct V_65 * V_66 )
{
struct V_53 * V_54 , * V_79 ;
F_57 (entry, n, &pcache->entries, node) {
F_58 ( & V_54 -> V_55 ) ;
F_32 ( V_54 ) ;
}
}
void F_59 ( struct V_65 * V_66 )
{
if ( ! V_66 )
return;
F_56 ( V_66 ) ;
if ( V_66 -> V_23 > 0 )
F_17 ( V_66 -> V_23 ) ;
free ( V_66 ) ;
}
struct V_65 * F_60 ( const char * V_67 )
{
struct V_65 * V_66 = F_55 () ;
int V_15 ;
if ( ! V_66 )
return NULL ;
V_15 = F_44 ( V_66 , V_67 ) ;
if ( V_15 < 0 ) {
F_7 ( L_31 , V_15 ) ;
goto V_80;
}
V_15 = F_51 ( V_66 ) ;
if ( V_15 < 0 ) {
F_7 ( L_32 , V_15 ) ;
goto V_80;
}
return V_66 ;
V_80:
F_59 ( V_66 ) ;
return NULL ;
}
static bool F_61 ( const char * V_81 , const char * V_82 )
{
if ( V_81 == V_82 )
return true ;
if ( ! V_81 || ! V_82 )
return false ;
return ! strcmp ( V_81 , V_82 ) ;
}
struct V_53 *
F_62 ( struct V_65 * V_66 , struct V_59 * V_57 )
{
struct V_53 * V_54 = NULL ;
char * V_83 = F_40 ( V_57 ) ;
if ( ! V_83 )
return NULL ;
F_63 (entry, pcache) {
if ( V_57 -> V_77 ) {
if ( V_54 -> V_57 . V_47 &&
F_61 ( V_54 -> V_57 . V_47 , V_57 -> V_47 ) &&
( ! V_57 -> V_46 ||
F_61 ( V_54 -> V_57 . V_46 , V_57 -> V_46 ) ) )
goto V_73;
continue;
}
if ( ( V_57 -> V_47 &&
( F_61 ( V_54 -> V_57 . V_46 , V_57 -> V_46 ) &&
F_61 ( V_54 -> V_57 . V_47 , V_57 -> V_47 ) ) ) ||
( ! strcmp ( V_54 -> V_58 , V_83 ) ) )
goto V_73;
}
V_54 = NULL ;
V_73:
free ( V_83 ) ;
return V_54 ;
}
struct V_53 *
F_64 ( struct V_65 * V_66 ,
const char * V_46 , const char * V_47 )
{
struct V_53 * V_54 = NULL ;
F_63 (entry, pcache) {
if ( F_61 ( V_54 -> V_57 . V_46 , V_46 ) &&
F_61 ( V_54 -> V_57 . V_47 , V_47 ) )
goto V_73;
}
V_54 = NULL ;
V_73:
return V_54 ;
}
int F_65 ( struct V_65 * V_66 ,
struct V_59 * V_57 ,
struct V_43 * V_60 , int V_84 )
{
struct V_53 * V_54 = NULL ;
char * V_85 ;
int V_61 , V_15 = 0 ;
if ( ! V_66 || ! V_57 || ! V_60 || V_84 <= 0 ) {
V_15 = - V_28 ;
goto V_80;
}
V_54 = F_62 ( V_66 , V_57 ) ;
if ( V_54 ) {
F_58 ( & V_54 -> V_55 ) ;
F_32 ( V_54 ) ;
}
V_15 = - V_52 ;
V_54 = F_37 ( V_57 ) ;
if ( ! V_54 )
goto V_80;
for ( V_61 = 0 ; V_61 < V_84 ; V_61 ++ ) {
if ( ! V_60 [ V_61 ] . V_86 . V_87 )
continue;
V_85 = F_25 ( & V_60 [ V_61 ] ) ;
if ( ! V_85 )
goto V_80;
F_16 ( V_54 -> V_56 , V_85 ) ;
free ( V_85 ) ;
}
F_54 ( & V_54 -> V_55 , & V_66 -> V_78 ) ;
F_7 ( L_33 , V_84 ) ;
return 0 ;
V_80:
F_7 ( L_34 ) ;
F_32 ( V_54 ) ;
return V_15 ;
}
static unsigned long long F_66 ( struct V_88 * V_89 )
{
return V_89 -> V_90 ? ( unsigned long long ) V_89 -> V_91 . V_92 [ 0 ]
: ( unsigned long long ) V_89 -> V_91 . V_93 [ 0 ] ;
}
int F_67 ( struct V_65 * V_66 , const char * V_94 )
{
struct V_53 * V_54 = NULL ;
struct V_95 V_96 ;
struct V_88 * V_89 ;
char * V_12 ;
char V_97 [ 64 ] ;
int V_15 ;
F_39 ( & V_96 ) ;
V_15 = F_68 ( & V_96 , V_94 ) ;
if ( V_15 < 0 ) {
F_7 ( L_35 , V_15 ) ;
return V_15 ;
}
F_69 (note, &sdtlist, note_list) {
V_15 = snprintf ( V_97 , 64 , L_36 , V_89 -> V_98 ) ;
if ( V_15 < 0 )
break;
V_54 = F_64 ( V_66 , V_97 , V_89 -> V_99 ) ;
if ( ! V_54 ) {
V_54 = F_37 ( NULL ) ;
if ( ! V_54 ) {
V_15 = - V_52 ;
break;
}
V_54 -> V_77 = true ;
V_15 = F_70 ( & V_54 -> V_58 , L_37 , V_97 ,
V_89 -> V_99 , V_89 -> V_99 ) ;
if ( V_15 < 0 )
break;
V_54 -> V_57 . V_47 = F_52 ( V_89 -> V_99 ) ;
V_54 -> V_57 . V_46 = F_52 ( V_97 ) ;
F_54 ( & V_54 -> V_55 , & V_66 -> V_78 ) ;
}
V_15 = F_70 ( & V_12 , L_38 ,
V_97 , V_89 -> V_99 , V_94 ,
F_66 ( V_89 ) ) ;
if ( V_15 < 0 )
break;
F_16 ( V_54 -> V_56 , V_12 ) ;
free ( V_12 ) ;
V_54 = NULL ;
}
if ( V_54 ) {
F_58 ( & V_54 -> V_55 ) ;
F_32 ( V_54 ) ;
}
F_71 ( & V_96 ) ;
return V_15 ;
}
static int F_72 ( struct V_53 * V_54 , int V_23 )
{
struct V_41 * V_100 ;
struct V_101 V_102 ;
struct V_103 V_104 [ 3 ] ;
const char * V_105 = V_54 -> V_77 ? L_39 : L_40 ;
int V_15 ;
V_15 = F_73 ( V_23 , & V_102 ) ;
if ( V_15 < 0 )
return V_15 ;
F_7 ( L_41 , V_105 , V_54 -> V_58 ) ;
V_104 [ 0 ] . V_106 = ( void * ) V_105 ; V_104 [ 0 ] . V_107 = 1 ;
V_104 [ 1 ] . V_106 = V_54 -> V_58 ; V_104 [ 1 ] . V_107 = strlen ( V_54 -> V_58 ) ;
V_104 [ 2 ] . V_106 = ( void * ) L_42 ; V_104 [ 2 ] . V_107 = 1 ;
V_15 = F_74 ( V_23 , V_104 , 3 ) ;
if ( V_15 < ( int ) V_104 [ 1 ] . V_107 + 2 )
goto V_108;
F_20 (snode, entry->tevlist) {
V_104 [ 0 ] . V_106 = ( void * ) V_100 -> V_45 ;
V_104 [ 0 ] . V_107 = strlen ( V_100 -> V_45 ) ;
V_104 [ 1 ] . V_106 = ( void * ) L_42 ; V_104 [ 1 ] . V_107 = 1 ;
V_15 = F_74 ( V_23 , V_104 , 2 ) ;
if ( V_15 < ( int ) V_104 [ 0 ] . V_107 + 1 )
goto V_108;
}
return 0 ;
V_108:
if ( V_15 > 0 )
V_15 = - 1 ;
if ( F_75 ( V_23 , V_102 . V_109 ) < 0 )
V_15 = - 2 ;
return V_15 ;
}
int F_76 ( struct V_65 * V_66 )
{
struct V_53 * V_54 ;
int V_15 = 0 ;
V_15 = F_77 ( V_66 -> V_23 , 0 , V_110 ) ;
if ( V_15 < 0 )
goto V_76;
V_15 = F_75 ( V_66 -> V_23 , 0 ) ;
if ( V_15 < 0 )
goto V_76;
F_63 (entry, pcache) {
V_15 = F_72 ( V_54 , V_66 -> V_23 ) ;
F_7 ( L_43 , V_15 ) ;
if ( V_15 < 0 )
break;
}
V_76:
return V_15 ;
}
static bool F_78 ( struct V_53 * V_54 ,
struct V_48 * V_49 )
{
char V_12 [ 128 ] , * V_111 = V_54 -> V_58 ;
if ( V_54 -> V_57 . V_47 ) {
snprintf ( V_12 , 128 , L_18 , V_54 -> V_57 . V_46 , V_54 -> V_57 . V_47 ) ;
V_111 = V_12 ;
}
return F_29 ( V_49 , V_111 ) ;
}
int F_79 ( struct V_65 * V_66 ,
struct V_48 * V_49 )
{
struct V_53 * V_54 , * V_112 ;
F_57 (entry, tmp, &pcache->entries, node) {
if ( F_78 ( V_54 , V_49 ) ) {
F_80 ( L_44 , V_54 -> V_58 ) ;
F_58 ( & V_54 -> V_55 ) ;
F_32 ( V_54 ) ;
}
}
return 0 ;
}
static int F_81 ( struct V_65 * V_66 ,
struct V_48 * V_49 )
{
struct V_53 * V_54 ;
F_63 (entry, pcache) {
if ( F_78 ( V_54 , V_49 ) )
printf ( L_45 , V_54 -> V_58 ) ;
}
return 0 ;
}
int F_82 ( struct V_48 * V_49 )
{
struct V_65 * V_66 ;
struct V_29 * V_113 ;
struct V_41 * V_114 ;
char * V_12 = F_83 ( V_49 ) ;
F_7 ( L_46 , V_12 ) ;
free ( V_12 ) ;
V_113 = F_84 ( true ) ;
if ( ! V_113 ) {
F_7 ( L_47 , V_21 ) ;
return - V_28 ;
}
F_20 (nd, bidlist) {
V_66 = F_60 ( V_114 -> V_45 ) ;
if ( ! V_66 )
continue;
if ( ! F_34 ( & V_66 -> V_78 ) ) {
V_12 = F_85 ( V_114 -> V_45 ) ;
printf ( L_48 , V_12 , V_114 -> V_45 ) ;
free ( V_12 ) ;
F_81 ( V_66 , V_49 ) ;
}
F_59 ( V_66 ) ;
}
F_18 ( V_113 ) ;
return 0 ;
}
