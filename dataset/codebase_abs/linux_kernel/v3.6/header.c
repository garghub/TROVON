int F_1 ( T_1 V_1 , const char * V_2 )
{
struct V_3 * V_4 ;
if ( strlen ( V_2 ) > V_5 )
F_2 ( L_1 , V_2 ) ;
V_4 = realloc ( V_6 , ( V_7 + 1 ) * sizeof( * V_6 ) ) ;
if ( V_4 == NULL )
return - V_8 ;
V_6 = V_4 ;
memset ( & V_6 [ V_7 ] , 0 , sizeof( struct V_3 ) ) ;
V_6 [ V_7 ] . V_9 = V_1 ;
strncpy ( V_6 [ V_7 ] . V_2 , V_2 , V_5 - 1 ) ;
V_7 ++ ;
return 0 ;
}
char * F_3 ( T_1 V_1 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_7 ; V_10 ++ ) {
if ( V_6 [ V_10 ] . V_9 == V_1 )
return V_6 [ V_10 ] . V_2 ;
}
return NULL ;
}
void F_4 ( struct V_11 * V_12 , int V_13 )
{
F_5 ( V_13 , V_12 -> V_14 ) ;
}
void F_6 ( struct V_11 * V_12 , int V_13 )
{
F_7 ( V_13 , V_12 -> V_14 ) ;
}
bool F_8 ( const struct V_11 * V_12 , int V_13 )
{
return F_9 ( V_13 , V_12 -> V_14 ) ;
}
static int F_10 ( int V_15 , const void * V_16 , T_2 V_17 )
{
while ( V_17 ) {
int V_18 = F_11 ( V_15 , V_16 , V_17 ) ;
if ( V_18 < 0 )
return - V_19 ;
V_17 -= V_18 ;
V_16 += V_18 ;
}
return 0 ;
}
static int F_12 ( int V_15 , const void * V_20 , T_2 V_21 ,
T_2 V_22 )
{
static const char V_23 [ V_24 ] ;
int V_25 = F_10 ( V_15 , V_20 , V_21 ) ;
if ( ! V_25 )
V_25 = F_10 ( V_15 , V_23 , V_22 - V_21 ) ;
return V_25 ;
}
static int F_13 ( int V_15 , const char * V_26 )
{
T_3 V_27 , V_28 ;
int V_18 ;
V_28 = strlen ( V_26 ) + 1 ;
V_27 = F_14 ( V_28 , V_24 ) ;
V_18 = F_10 ( V_15 , & V_27 , sizeof( V_27 ) ) ;
if ( V_18 < 0 )
return V_18 ;
return F_12 ( V_15 , V_26 , V_28 , V_27 ) ;
}
static char * F_15 ( int V_15 , struct V_11 * V_29 )
{
T_4 V_30 , V_18 ;
T_3 V_27 ;
char * V_16 ;
V_30 = F_16 ( V_15 , & V_27 , sizeof( V_27 ) ) ;
if ( V_30 < ( T_4 ) sizeof( V_27 ) )
return NULL ;
if ( V_29 -> V_31 )
V_27 = F_17 ( V_27 ) ;
V_16 = malloc ( V_27 ) ;
if ( ! V_16 )
return NULL ;
V_18 = F_16 ( V_15 , V_16 , V_27 ) ;
if ( V_18 == ( T_4 ) V_27 ) {
return V_16 ;
}
free ( V_16 ) ;
return NULL ;
}
int
F_18 ( int V_32 , const char * * V_33 )
{
int V_10 ;
if ( V_34 )
return 0 ;
V_35 = ( T_3 ) V_32 ;
V_34 = calloc ( V_32 , sizeof( char * ) ) ;
if ( ! V_34 )
return - V_8 ;
for ( V_10 = 0 ; V_10 < V_32 ; V_10 ++ )
V_34 [ V_10 ] = V_33 [ V_10 ] ;
return 0 ;
}
static int F_19 ( struct V_36 * V_37 , T_5 V_38 ,
T_6 V_39 , int V_15 )
{
struct V_40 * V_41 ;
F_20 (pos, head) {
int V_25 ;
struct V_42 V_43 ;
T_2 V_27 ;
if ( ! V_41 -> V_44 )
continue;
V_27 = V_41 -> V_45 + 1 ;
V_27 = F_14 ( V_27 , V_24 ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
memcpy ( & V_43 . V_46 , V_41 -> V_46 , sizeof( V_41 -> V_46 ) ) ;
V_43 . V_38 = V_38 ;
V_43 . V_12 . V_39 = V_39 ;
V_43 . V_12 . V_17 = sizeof( V_43 ) + V_27 ;
V_25 = F_10 ( V_15 , & V_43 , sizeof( V_43 ) ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_12 ( V_15 , V_41 -> V_47 ,
V_41 -> V_45 + 1 , V_27 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_21 ( struct V_48 * V_48 , int V_15 )
{
int V_25 ;
T_6 V_49 = V_50 ,
V_51 = V_52 ;
if ( ! F_22 ( V_48 ) ) {
V_49 = V_53 ;
V_51 = V_54 ;
}
V_25 = F_19 ( & V_48 -> V_55 , V_48 -> V_38 ,
V_49 , V_15 ) ;
if ( V_25 == 0 )
V_25 = F_19 ( & V_48 -> V_56 ,
V_48 -> V_38 , V_51 , V_15 ) ;
return V_25 ;
}
static int F_23 ( struct V_11 * V_12 , int V_15 )
{
struct V_57 * V_58 = F_24 ( V_12 ,
struct V_57 , V_12 ) ;
struct V_59 * V_60 ;
int V_25 = F_21 ( & V_58 -> V_61 , V_15 ) ;
if ( V_25 )
return V_25 ;
for ( V_60 = F_25 ( & V_58 -> V_62 ) ; V_60 ; V_60 = F_26 ( V_60 ) ) {
struct V_48 * V_41 = F_27 ( V_60 , struct V_48 , V_59 ) ;
V_25 = F_21 ( V_41 , V_15 ) ;
if ( V_25 )
break;
}
return V_25 ;
}
int F_28 ( const char * V_63 , const char * V_64 ,
const char * V_2 , bool V_65 )
{
const T_2 V_17 = V_66 ;
char * V_67 , * V_68 = F_29 ( V_17 ) ,
* V_69 = F_29 ( V_17 ) , * V_70 ;
int V_27 , V_25 = - 1 ;
if ( V_65 ) {
if ( V_71 . V_72 ) {
F_30 ( L_2 ) ;
return 0 ;
}
V_67 = ( char * ) V_2 ;
} else
V_67 = F_31 ( V_2 , NULL ) ;
if ( V_67 == NULL || V_68 == NULL || V_69 == NULL )
goto V_73;
V_27 = F_32 ( V_68 , V_17 , L_3 ,
V_64 , V_65 ? L_4 : L_5 , V_67 ) ;
if ( F_33 ( V_68 , 0755 ) )
goto V_73;
snprintf ( V_68 + V_27 , V_17 - V_27 , L_6 , V_63 ) ;
if ( F_34 ( V_68 , V_74 ) ) {
if ( V_65 ) {
if ( F_35 ( L_7 , V_68 ) )
goto V_73;
} else if ( F_36 ( V_67 , V_68 ) && F_35 ( V_2 , V_68 ) )
goto V_73;
}
V_27 = F_32 ( V_69 , V_17 , L_8 ,
V_64 , V_63 ) ;
if ( F_34 ( V_69 , V_75 ) && F_33 ( V_69 , 0755 ) )
goto V_73;
snprintf ( V_69 + V_27 , V_17 - V_27 , L_6 , V_63 + 2 ) ;
V_70 = V_68 + strlen ( V_64 ) - 5 ;
memcpy ( V_70 , L_9 , 5 ) ;
if ( F_37 ( V_70 , V_69 ) == 0 )
V_25 = 0 ;
V_73:
if ( ! V_65 )
free ( V_67 ) ;
free ( V_68 ) ;
free ( V_69 ) ;
return V_25 ;
}
static int F_38 ( const T_7 * V_46 , T_2 V_76 ,
const char * V_2 , const char * V_64 ,
bool V_65 )
{
char V_63 [ V_77 * 2 + 1 ] ;
F_39 ( V_46 , V_76 , V_63 ) ;
return F_28 ( V_63 , V_64 , V_2 , V_65 ) ;
}
int F_40 ( const char * V_63 , const char * V_64 )
{
const T_2 V_17 = V_66 ;
char * V_68 = F_29 ( V_17 ) ,
* V_69 = F_29 ( V_17 ) ;
int V_25 = - 1 ;
if ( V_68 == NULL || V_69 == NULL )
goto V_73;
snprintf ( V_69 , V_17 , L_10 ,
V_64 , V_63 , V_63 + 2 ) ;
if ( F_34 ( V_69 , V_74 ) )
goto V_73;
if ( F_41 ( V_69 , V_68 , V_17 - 1 ) < 0 )
goto V_73;
if ( F_42 ( V_69 ) )
goto V_73;
snprintf ( V_69 , V_17 , L_10 ,
V_64 , V_63 , V_68 ) ;
if ( F_42 ( V_69 ) )
goto V_73;
V_25 = 0 ;
V_73:
free ( V_68 ) ;
free ( V_69 ) ;
return V_25 ;
}
static int F_43 ( struct V_40 * V_40 , const char * V_64 )
{
bool V_65 = V_40 -> V_78 && V_40 -> V_47 [ 0 ] != '/' ;
return F_38 ( V_40 -> V_46 , sizeof( V_40 -> V_46 ) ,
V_40 -> V_47 , V_64 , V_65 ) ;
}
static int F_44 ( struct V_36 * V_37 , const char * V_64 )
{
struct V_40 * V_41 ;
int V_25 = 0 ;
F_20 (pos, head)
if ( F_43 ( V_41 , V_64 ) )
V_25 = - 1 ;
return V_25 ;
}
static int F_45 ( struct V_48 * V_48 , const char * V_64 )
{
int V_18 = F_44 ( & V_48 -> V_55 , V_64 ) ;
V_18 |= F_44 ( & V_48 -> V_56 , V_64 ) ;
return V_18 ;
}
static int F_46 ( struct V_57 * V_58 )
{
struct V_59 * V_60 ;
int V_18 ;
char V_64 [ V_66 ] ;
snprintf ( V_64 , sizeof( V_64 ) , L_11 , V_79 ) ;
if ( F_47 ( V_64 , 0755 ) != 0 && V_19 != V_80 )
return - 1 ;
V_18 = F_45 ( & V_58 -> V_61 , V_64 ) ;
for ( V_60 = F_25 ( & V_58 -> V_62 ) ; V_60 ; V_60 = F_26 ( V_60 ) ) {
struct V_48 * V_41 = F_27 ( V_60 , struct V_48 , V_59 ) ;
V_18 |= F_45 ( V_41 , V_64 ) ;
}
return V_18 ? - 1 : 0 ;
}
static bool F_48 ( struct V_48 * V_48 , bool V_81 )
{
bool V_18 = F_49 ( & V_48 -> V_55 , V_81 ) ;
V_18 |= F_49 ( & V_48 -> V_56 , V_81 ) ;
return V_18 ;
}
static bool F_50 ( struct V_57 * V_58 , bool V_81 )
{
struct V_59 * V_60 ;
bool V_18 = F_48 ( & V_58 -> V_61 , V_81 ) ;
for ( V_60 = F_25 ( & V_58 -> V_62 ) ; V_60 ; V_60 = F_26 ( V_60 ) ) {
struct V_48 * V_41 = F_27 ( V_60 , struct V_48 , V_59 ) ;
V_18 |= F_48 ( V_41 , V_81 ) ;
}
return V_18 ;
}
static int F_51 ( int V_15 , struct V_11 * T_8 V_82 ,
struct V_83 * V_84 )
{
return F_52 ( V_15 , & V_84 -> V_85 ) ;
}
static int F_53 ( int V_15 , struct V_11 * T_8 ,
struct V_83 * V_84 V_82 )
{
struct V_57 * V_58 ;
int V_25 ;
V_58 = F_24 ( T_8 , struct V_57 , V_12 ) ;
if ( ! F_50 ( V_58 , true ) )
return - 1 ;
V_25 = F_23 ( T_8 , V_15 ) ;
if ( V_25 < 0 ) {
F_30 ( L_12 ) ;
return V_25 ;
}
if ( ! V_86 )
F_46 ( V_58 ) ;
return 0 ;
}
static int F_54 ( int V_15 , struct V_11 * T_8 V_82 ,
struct V_83 * V_84 V_82 )
{
struct V_87 V_88 ;
int V_18 ;
V_18 = F_55 ( & V_88 ) ;
if ( V_18 < 0 )
return - 1 ;
return F_13 ( V_15 , V_88 . V_89 ) ;
}
static int F_56 ( int V_15 , struct V_11 * T_8 V_82 ,
struct V_83 * V_84 V_82 )
{
struct V_87 V_88 ;
int V_18 ;
V_18 = F_55 ( & V_88 ) ;
if ( V_18 < 0 )
return - 1 ;
return F_13 ( V_15 , V_88 . V_90 ) ;
}
static int F_57 ( int V_15 , struct V_11 * T_8 V_82 ,
struct V_83 * V_84 V_82 )
{
struct V_87 V_88 ;
int V_18 ;
V_18 = F_55 ( & V_88 ) ;
if ( V_18 < 0 )
return - 1 ;
return F_13 ( V_15 , V_88 . V_48 ) ;
}
static int F_58 ( int V_15 , struct V_11 * T_8 V_82 ,
struct V_83 * V_84 V_82 )
{
return F_13 ( V_15 , V_91 ) ;
}
static int F_59 ( int V_15 , struct V_11 * T_8 V_82 ,
struct V_83 * V_84 V_82 )
{
#ifndef F_60
#define F_60 NULL
#endif
T_9 * V_92 ;
char * V_16 = NULL ;
char * V_93 , * V_94 ;
const char * V_95 = F_60 ;
T_2 V_27 = 0 ;
int V_18 = - 1 ;
if ( ! V_95 )
return - 1 ;
V_92 = fopen ( L_13 , L_14 ) ;
if ( ! V_92 )
return - 1 ;
while ( F_61 ( & V_16 , & V_27 , V_92 ) > 0 ) {
V_18 = strncmp ( V_16 , V_95 , strlen ( V_95 ) ) ;
if ( ! V_18 )
break;
}
if ( V_18 )
goto V_96;
V_93 = V_16 ;
V_94 = strchr ( V_16 , ':' ) ;
if ( V_94 && * ( V_94 + 1 ) == ' ' && * ( V_94 + 2 ) )
V_93 = V_94 + 2 ;
V_94 = strchr ( V_93 , '\n' ) ;
if ( V_94 )
* V_94 = '\0' ;
V_94 = V_93 ;
while ( * V_94 ) {
if ( isspace ( * V_94 ) ) {
char * V_97 = V_94 + 1 ;
char * V_98 = V_97 ;
* V_94 = ' ' ;
while ( * V_98 && isspace ( * V_98 ) )
V_98 ++ ;
if ( V_98 != ( V_94 + 1 ) )
while ( ( * V_97 ++ = * V_98 ++ ) ) ;
}
V_94 ++ ;
}
V_18 = F_13 ( V_15 , V_93 ) ;
V_96:
free ( V_16 ) ;
fclose ( V_92 ) ;
return V_18 ;
}
static int F_62 ( int V_15 , struct V_11 * T_8 V_82 ,
struct V_83 * V_84 V_82 )
{
long V_99 ;
T_3 V_100 , V_101 ;
int V_18 ;
V_99 = F_63 ( V_102 ) ;
if ( V_99 < 0 )
return - 1 ;
V_100 = ( T_3 ) ( V_99 & V_103 ) ;
V_99 = F_63 ( V_104 ) ;
if ( V_99 < 0 )
return - 1 ;
V_101 = ( T_3 ) ( V_99 & V_103 ) ;
V_18 = F_10 ( V_15 , & V_100 , sizeof( V_100 ) ) ;
if ( V_18 < 0 )
return V_18 ;
return F_10 ( V_15 , & V_101 , sizeof( V_101 ) ) ;
}
static int F_64 ( int V_15 , struct V_11 * T_8 V_82 ,
struct V_83 * V_84 )
{
struct V_105 * V_106 ;
T_3 V_107 = 0 , V_108 , V_30 ;
int V_18 ;
F_65 (attr, &evlist->entries, node)
V_107 ++ ;
V_18 = F_10 ( V_15 , & V_107 , sizeof( V_107 ) ) ;
if ( V_18 < 0 )
return V_18 ;
V_30 = ( T_3 ) sizeof( V_106 -> V_106 ) ;
V_18 = F_10 ( V_15 , & V_30 , sizeof( V_30 ) ) ;
if ( V_18 < 0 )
return V_18 ;
F_65 (attr, &evlist->entries, node) {
V_18 = F_10 ( V_15 , & V_106 -> V_106 , V_30 ) ;
if ( V_18 < 0 )
return V_18 ;
V_108 = V_106 -> V_109 ;
V_18 = F_10 ( V_15 , & V_108 , sizeof( V_108 ) ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_13 ( V_15 , F_66 ( V_106 ) ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_10 ( V_15 , V_106 -> V_1 , V_106 -> V_109 * sizeof( T_1 ) ) ;
if ( V_18 < 0 )
return V_18 ;
}
return 0 ;
}
static int F_67 ( int V_15 , struct V_11 * T_8 V_82 ,
struct V_83 * V_84 V_82 )
{
char V_16 [ V_110 ] ;
char V_111 [ 32 ] ;
T_3 V_10 , V_112 ;
int V_18 ;
sprintf ( V_111 , L_15 , F_68 () ) ;
V_18 = F_41 ( V_111 , V_16 , sizeof( V_16 ) ) ;
if ( V_18 <= 0 )
return - 1 ;
V_16 [ V_18 ] = '\0' ;
V_112 = V_35 + 1 ;
V_18 = F_10 ( V_15 , & V_112 , sizeof( V_112 ) ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_13 ( V_15 , V_16 ) ;
if ( V_18 < 0 )
return V_18 ;
for ( V_10 = 0 ; V_10 < V_35 ; V_10 ++ ) {
V_18 = F_13 ( V_15 , V_34 [ V_10 ] ) ;
if ( V_18 < 0 )
return V_18 ;
}
return 0 ;
}
static int F_69 ( struct V_113 * V_114 , int V_115 )
{
T_9 * V_116 ;
char V_68 [ V_110 ] ;
char * V_16 = NULL , * V_94 ;
T_2 V_27 = 0 ;
T_3 V_10 = 0 ;
int V_18 = - 1 ;
sprintf ( V_68 , V_117 , V_115 ) ;
V_116 = fopen ( V_68 , L_14 ) ;
if ( ! V_116 )
return - 1 ;
if ( F_61 ( & V_16 , & V_27 , V_116 ) <= 0 )
goto V_96;
fclose ( V_116 ) ;
V_94 = strchr ( V_16 , '\n' ) ;
if ( V_94 )
* V_94 = '\0' ;
for ( V_10 = 0 ; V_10 < V_114 -> V_118 ; V_10 ++ ) {
if ( ! strcmp ( V_16 , V_114 -> V_119 [ V_10 ] ) )
break;
}
if ( V_10 == V_114 -> V_118 ) {
V_114 -> V_119 [ V_10 ] = V_16 ;
V_114 -> V_118 ++ ;
V_16 = NULL ;
V_27 = 0 ;
}
sprintf ( V_68 , V_120 , V_115 ) ;
V_116 = fopen ( V_68 , L_14 ) ;
if ( ! V_116 )
goto V_96;
if ( F_61 ( & V_16 , & V_27 , V_116 ) <= 0 )
goto V_96;
V_94 = strchr ( V_16 , '\n' ) ;
if ( V_94 )
* V_94 = '\0' ;
for ( V_10 = 0 ; V_10 < V_114 -> V_121 ; V_10 ++ ) {
if ( ! strcmp ( V_16 , V_114 -> V_122 [ V_10 ] ) )
break;
}
if ( V_10 == V_114 -> V_121 ) {
V_114 -> V_122 [ V_10 ] = V_16 ;
V_114 -> V_121 ++ ;
V_16 = NULL ;
}
V_18 = 0 ;
V_96:
if( V_116 )
fclose ( V_116 ) ;
free ( V_16 ) ;
return V_18 ;
}
static void F_70 ( struct V_113 * V_114 )
{
T_3 V_10 ;
if ( ! V_114 )
return;
for ( V_10 = 0 ; V_10 < V_114 -> V_118 ; V_10 ++ )
free ( V_114 -> V_119 [ V_10 ] ) ;
for ( V_10 = 0 ; V_10 < V_114 -> V_121 ; V_10 ++ )
free ( V_114 -> V_122 [ V_10 ] ) ;
free ( V_114 ) ;
}
static struct V_113 * F_71 ( void )
{
struct V_113 * V_114 ;
void * V_123 ;
T_3 V_99 , V_10 ;
T_2 V_30 ;
long V_124 ;
int V_18 = - 1 ;
V_124 = F_63 ( V_102 ) ;
if ( V_124 < 0 )
return NULL ;
V_99 = ( T_3 ) ( V_124 & V_103 ) ;
V_30 = V_99 * sizeof( char * ) ;
V_123 = calloc ( 1 , sizeof( * V_114 ) + 2 * V_30 ) ;
if ( ! V_123 )
return NULL ;
V_114 = V_123 ;
V_123 += sizeof( * V_114 ) ;
V_114 -> V_119 = V_123 ;
V_123 += V_30 ;
V_114 -> V_122 = V_123 ;
for ( V_10 = 0 ; V_10 < V_99 ; V_10 ++ ) {
V_18 = F_69 ( V_114 , V_10 ) ;
if ( V_18 < 0 )
break;
}
if ( V_18 ) {
F_70 ( V_114 ) ;
V_114 = NULL ;
}
return V_114 ;
}
static int F_72 ( int V_15 , struct V_11 * T_8 V_82 ,
struct V_83 * V_84 V_82 )
{
struct V_113 * V_114 ;
T_3 V_10 ;
int V_18 ;
V_114 = F_71 () ;
if ( ! V_114 )
return - 1 ;
V_18 = F_10 ( V_15 , & V_114 -> V_118 , sizeof( V_114 -> V_118 ) ) ;
if ( V_18 < 0 )
goto V_96;
for ( V_10 = 0 ; V_10 < V_114 -> V_118 ; V_10 ++ ) {
V_18 = F_13 ( V_15 , V_114 -> V_119 [ V_10 ] ) ;
if ( V_18 < 0 )
goto V_96;
}
V_18 = F_10 ( V_15 , & V_114 -> V_121 , sizeof( V_114 -> V_121 ) ) ;
if ( V_18 < 0 )
goto V_96;
for ( V_10 = 0 ; V_10 < V_114 -> V_121 ; V_10 ++ ) {
V_18 = F_13 ( V_15 , V_114 -> V_122 [ V_10 ] ) ;
if ( V_18 < 0 )
break;
}
V_96:
F_70 ( V_114 ) ;
return V_18 ;
}
static int F_73 ( int V_15 , struct V_11 * T_8 V_82 ,
struct V_83 * V_84 V_82 )
{
char * V_16 = NULL ;
T_9 * V_116 ;
T_2 V_27 = 0 ;
int V_18 = - 1 , V_112 ;
T_10 V_125 ;
V_116 = fopen ( L_16 , L_14 ) ;
if ( ! V_116 )
return - 1 ;
while ( F_61 ( & V_16 , & V_27 , V_116 ) > 0 ) {
V_18 = strncmp ( V_16 , L_17 , 9 ) ;
if ( ! V_18 )
break;
}
if ( ! V_18 ) {
V_112 = sscanf ( V_16 , L_18 V_126 , & V_125 ) ;
if ( V_112 == 1 )
V_18 = F_10 ( V_15 , & V_125 , sizeof( V_125 ) ) ;
}
free ( V_16 ) ;
fclose ( V_116 ) ;
return V_18 ;
}
static int F_74 ( int V_15 , int V_127 )
{
char V_26 [ V_110 ] ;
char V_128 [ 32 ] ;
char * V_16 = NULL , * V_94 ;
T_2 V_27 = 0 ;
T_9 * V_116 ;
T_1 V_129 , V_130 , V_125 ;
int V_18 = - 1 ;
sprintf ( V_26 , L_19 , V_127 ) ;
V_116 = fopen ( V_26 , L_14 ) ;
if ( ! V_116 )
return - 1 ;
while ( F_61 ( & V_16 , & V_27 , V_116 ) > 0 ) {
if ( ! strchr ( V_16 , ':' ) )
continue;
if ( sscanf ( V_16 , L_20 V_126 , V_128 , & V_125 ) != 2 )
goto V_96;
if ( ! strcmp ( V_128 , L_17 ) )
V_129 = V_125 ;
if ( ! strcmp ( V_128 , L_21 ) )
V_130 = V_125 ;
}
fclose ( V_116 ) ;
V_18 = F_10 ( V_15 , & V_129 , sizeof( T_1 ) ) ;
if ( V_18 )
goto V_96;
V_18 = F_10 ( V_15 , & V_130 , sizeof( T_1 ) ) ;
if ( V_18 )
goto V_96;
V_18 = - 1 ;
sprintf ( V_26 , L_22 , V_127 ) ;
V_116 = fopen ( V_26 , L_14 ) ;
if ( ! V_116 )
goto V_96;
if ( F_61 ( & V_16 , & V_27 , V_116 ) <= 0 )
goto V_96;
V_94 = strchr ( V_16 , '\n' ) ;
if ( V_94 )
* V_94 = '\0' ;
V_18 = F_13 ( V_15 , V_16 ) ;
V_96:
free ( V_16 ) ;
fclose ( V_116 ) ;
return V_18 ;
}
static int F_75 ( int V_15 , struct V_11 * T_8 V_82 ,
struct V_83 * V_84 V_82 )
{
char * V_16 = NULL ;
T_2 V_27 = 0 ;
T_9 * V_116 ;
struct V_131 * V_132 = NULL ;
char * V_133 ;
T_3 V_99 , V_10 , V_134 ;
int V_18 = - 1 ;
V_116 = fopen ( L_23 , L_14 ) ;
if ( ! V_116 )
return - 1 ;
if ( F_61 ( & V_16 , & V_27 , V_116 ) <= 0 )
goto V_96;
V_133 = strchr ( V_16 , '\n' ) ;
if ( V_133 )
* V_133 = '\0' ;
V_132 = F_76 ( V_16 ) ;
if ( ! V_132 )
goto V_96;
V_99 = ( T_3 ) V_132 -> V_99 ;
V_18 = F_10 ( V_15 , & V_99 , sizeof( V_99 ) ) ;
if ( V_18 < 0 )
goto V_96;
for ( V_10 = 0 ; V_10 < V_99 ; V_10 ++ ) {
V_134 = ( T_3 ) V_132 -> V_135 [ V_10 ] ;
V_18 = F_10 ( V_15 , & V_134 , sizeof( V_134 ) ) ;
if ( V_18 < 0 )
break;
V_18 = F_74 ( V_15 , V_10 ) ;
if ( V_18 < 0 )
break;
}
V_96:
free ( V_16 ) ;
fclose ( V_116 ) ;
free ( V_132 ) ;
return V_18 ;
}
static int F_77 ( int V_15 , struct V_11 * T_8 V_82 ,
struct V_83 * V_84 V_82 )
{
char V_136 [ 64 ] ;
int V_18 ;
V_18 = F_78 ( V_136 , sizeof( V_136 ) ) ;
if ( ! V_18 )
goto V_137;
return - 1 ;
V_137:
return F_13 ( V_15 , V_136 ) ;
}
static int F_79 ( int V_15 V_82 , struct V_11 * T_8 V_82 ,
struct V_83 * V_84 V_82 )
{
return 0 ;
}
static void F_80 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
{
char * V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_116 , L_24 , V_26 ) ;
free ( V_26 ) ;
}
static void F_81 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
{
char * V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_116 , L_25 , V_26 ) ;
free ( V_26 ) ;
}
static void F_82 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
{
char * V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_116 , L_26 , V_26 ) ;
free ( V_26 ) ;
}
static void F_83 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
{
char * V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_116 , L_27 , V_26 ) ;
free ( V_26 ) ;
}
static void F_84 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
{
T_4 V_18 ;
T_3 V_99 ;
V_18 = F_16 ( V_15 , & V_99 , sizeof( V_99 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_99 ) )
V_99 = - 1 ;
if ( V_29 -> V_31 )
V_99 = F_17 ( V_99 ) ;
fprintf ( V_116 , L_28 , V_99 ) ;
V_18 = F_16 ( V_15 , & V_99 , sizeof( V_99 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_99 ) )
V_99 = - 1 ;
if ( V_29 -> V_31 )
V_99 = F_17 ( V_99 ) ;
fprintf ( V_116 , L_29 , V_99 ) ;
}
static void F_85 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
{
char * V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_116 , L_30 , V_26 ) ;
free ( V_26 ) ;
}
static void F_86 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
{
T_4 V_18 ;
char * V_26 ;
T_3 V_99 , V_10 ;
V_18 = F_16 ( V_15 , & V_99 , sizeof( V_99 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_99 ) )
return;
if ( V_29 -> V_31 )
V_99 = F_17 ( V_99 ) ;
fprintf ( V_116 , L_31 ) ;
for ( V_10 = 0 ; V_10 < V_99 ; V_10 ++ ) {
V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_116 , L_32 , V_26 ) ;
free ( V_26 ) ;
}
fputc ( '\n' , V_116 ) ;
}
static void F_87 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
{
T_4 V_18 ;
T_3 V_99 , V_10 ;
char * V_26 ;
V_18 = F_16 ( V_15 , & V_99 , sizeof( V_99 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_99 ) )
return;
if ( V_29 -> V_31 )
V_99 = F_17 ( V_99 ) ;
for ( V_10 = 0 ; V_10 < V_99 ; V_10 ++ ) {
V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_116 , L_33 , V_26 ) ;
free ( V_26 ) ;
}
V_18 = F_16 ( V_15 , & V_99 , sizeof( V_99 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_99 ) )
return;
if ( V_29 -> V_31 )
V_99 = F_17 ( V_99 ) ;
for ( V_10 = 0 ; V_10 < V_99 ; V_10 ++ ) {
V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_116 , L_34 , V_26 ) ;
free ( V_26 ) ;
}
}
static void F_88 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
{
struct V_138 V_106 ;
T_10 V_1 ;
void * V_16 = NULL ;
char * V_26 ;
T_3 V_107 , V_30 , V_99 , V_10 , V_134 ;
T_4 V_18 ;
T_2 V_139 ;
V_18 = F_16 ( V_15 , & V_107 , sizeof( V_107 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_107 ) )
goto error;
if ( V_29 -> V_31 )
V_107 = F_17 ( V_107 ) ;
V_18 = F_16 ( V_15 , & V_30 , sizeof( V_30 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_30 ) )
goto error;
if ( V_29 -> V_31 )
V_30 = F_17 ( V_30 ) ;
memset ( & V_106 , 0 , sizeof( V_106 ) ) ;
V_16 = malloc ( V_30 ) ;
if ( ! V_16 )
goto error;
V_139 = sizeof( V_106 ) ;
if ( V_30 < V_139 )
V_139 = V_30 ;
for ( V_10 = 0 ; V_10 < V_107 ; V_10 ++ ) {
V_18 = F_16 ( V_15 , V_16 , V_30 ) ;
if ( V_18 != ( T_4 ) V_30 )
goto error;
if ( V_29 -> V_31 )
F_89 ( V_16 ) ;
memcpy ( & V_106 , V_16 , V_139 ) ;
V_18 = F_16 ( V_15 , & V_99 , sizeof( V_99 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_99 ) )
goto error;
if ( V_29 -> V_31 )
V_99 = F_17 ( V_99 ) ;
V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_116 , L_35 , V_26 ) ;
free ( V_26 ) ;
fprintf ( V_116 , L_36 V_140
L_37 V_140 L_38 V_140 ,
V_106 . type ,
( T_1 ) V_106 . V_141 ,
( T_1 ) V_106 . V_142 ,
( T_1 ) V_106 . V_143 ) ;
fprintf ( V_116 , L_39 ,
V_106 . V_144 ,
V_106 . V_145 ) ;
fprintf ( V_116 , L_40 ,
V_106 . V_146 ,
V_106 . V_147 ) ;
fprintf ( V_116 , L_41 , V_106 . V_148 ) ;
if ( V_99 )
fprintf ( V_116 , L_42 ) ;
for ( V_134 = 0 ; V_134 < V_99 ; V_134 ++ ) {
V_18 = F_16 ( V_15 , & V_1 , sizeof( V_1 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_1 ) )
goto error;
if ( V_29 -> V_31 )
V_1 = F_90 ( V_1 ) ;
if ( V_134 )
fputc ( ',' , V_116 ) ;
fprintf ( V_116 , L_43 V_126 , V_1 ) ;
}
if ( V_99 && V_134 == V_99 )
fprintf ( V_116 , L_44 ) ;
fputc ( '\n' , V_116 ) ;
}
free ( V_16 ) ;
return;
error:
fprintf ( V_116 , L_45 ) ;
}
static void F_91 ( struct V_11 * T_8 V_82 , int V_15 , T_9 * V_116 )
{
T_10 V_125 ;
T_4 V_18 ;
V_18 = F_16 ( V_15 , & V_125 , sizeof( V_125 ) ) ;
if ( V_18 != sizeof( V_125 ) )
goto error;
if ( T_8 -> V_31 )
V_125 = F_90 ( V_125 ) ;
fprintf ( V_116 , L_46 V_126 L_47 , V_125 ) ;
return;
error:
fprintf ( V_116 , L_48 ) ;
}
static void F_92 ( struct V_11 * T_8 V_82 , int V_15 , T_9 * V_116 )
{
T_4 V_18 ;
T_3 V_99 , V_133 , V_10 ;
char * V_26 ;
T_10 V_129 , V_130 ;
V_18 = F_16 ( V_15 , & V_99 , sizeof( V_99 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_99 ) )
goto error;
if ( T_8 -> V_31 )
V_99 = F_17 ( V_99 ) ;
for ( V_10 = 0 ; V_10 < V_99 ; V_10 ++ ) {
V_18 = F_16 ( V_15 , & V_133 , sizeof( V_133 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_133 ) )
goto error;
if ( T_8 -> V_31 )
V_133 = F_17 ( V_133 ) ;
V_18 = F_16 ( V_15 , & V_129 , sizeof( T_1 ) ) ;
if ( V_18 != sizeof( T_1 ) )
goto error;
V_18 = F_16 ( V_15 , & V_130 , sizeof( T_1 ) ) ;
if ( V_18 != sizeof( T_1 ) )
goto error;
if ( T_8 -> V_31 ) {
V_129 = F_90 ( V_129 ) ;
V_130 = F_90 ( V_130 ) ;
}
fprintf ( V_116 , L_49 V_126 L_50
L_51 V_126 L_47 ,
V_133 ,
V_129 ,
V_130 ) ;
V_26 = F_15 ( V_15 , T_8 ) ;
fprintf ( V_116 , L_52 , V_133 , V_26 ) ;
free ( V_26 ) ;
}
return;
error:
fprintf ( V_116 , L_53 ) ;
}
static void F_93 ( struct V_11 * V_29 , int V_15 , T_9 * V_116 )
{
char * V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_116 , L_54 , V_26 ) ;
free ( V_26 ) ;
}
static void F_94 ( struct V_11 * V_29 V_82 , int V_15 V_82 ,
T_9 * V_116 )
{
fprintf ( V_116 , L_55 ) ;
}
static int F_95 ( struct V_42 * V_149 ,
char * V_68 ,
struct V_57 * V_58 )
{
int V_25 = - 1 ;
struct V_36 * V_37 ;
struct V_48 * V_48 ;
T_6 V_39 ;
struct V_40 * V_40 ;
enum V_150 V_151 ;
V_48 = F_96 ( V_58 , V_149 -> V_38 ) ;
if ( ! V_48 )
goto V_152;
V_39 = V_149 -> V_12 . V_39 & V_153 ;
switch ( V_39 ) {
case V_50 :
V_151 = V_154 ;
V_37 = & V_48 -> V_55 ;
break;
case V_53 :
V_151 = V_155 ;
V_37 = & V_48 -> V_55 ;
break;
case V_52 :
case V_54 :
V_151 = V_156 ;
V_37 = & V_48 -> V_56 ;
break;
default:
goto V_152;
}
V_40 = F_97 ( V_37 , V_68 ) ;
if ( V_40 != NULL ) {
char V_63 [ V_77 * 2 + 1 ] ;
F_98 ( V_40 , & V_149 -> V_46 ) ;
if ( V_68 [ 0 ] == '[' )
V_40 -> V_78 = V_151 ;
F_39 ( V_40 -> V_46 , sizeof( V_40 -> V_46 ) ,
V_63 ) ;
F_30 ( L_56 ,
V_40 -> V_47 , V_63 ) ;
}
V_25 = 0 ;
V_152:
return V_25 ;
}
static int F_99 ( struct V_11 * V_12 ,
int V_157 , T_1 V_158 , T_1 V_17 )
{
struct V_57 * V_58 = F_24 ( V_12 , struct V_57 , V_12 ) ;
struct {
struct V_159 V_12 ;
T_7 V_46 [ F_14 ( V_77 , sizeof( T_1 ) ) ] ;
char V_68 [ 0 ] ;
} V_160 ;
struct V_42 V_149 ;
char V_68 [ V_66 ] ;
T_1 V_161 = V_158 + V_17 ;
while ( V_158 < V_161 ) {
T_4 V_27 ;
if ( F_16 ( V_157 , & V_160 , sizeof( V_160 ) ) != sizeof( V_160 ) )
return - 1 ;
if ( V_12 -> V_31 )
F_100 ( & V_160 . V_12 ) ;
V_27 = V_160 . V_12 . V_17 - sizeof( V_160 ) ;
if ( F_16 ( V_157 , V_68 , V_27 ) != V_27 )
return - 1 ;
V_149 . V_12 = V_160 . V_12 ;
V_149 . V_38 = V_162 ;
if ( V_149 . V_12 . V_39 == V_54 ||
V_149 . V_12 . V_39 == V_53 )
V_149 . V_38 = V_163 ;
memcpy ( V_149 . V_46 , V_160 . V_46 , sizeof( V_149 . V_46 ) ) ;
F_95 ( & V_149 , V_68 , V_58 ) ;
V_158 += V_149 . V_12 . V_17 ;
}
return 0 ;
}
static int F_101 ( struct V_11 * V_12 ,
int V_157 , T_1 V_158 , T_1 V_17 )
{
struct V_57 * V_58 = F_24 ( V_12 , struct V_57 , V_12 ) ;
struct V_42 V_149 ;
char V_68 [ V_66 ] ;
T_1 V_161 = V_158 + V_17 , V_164 = V_158 ;
int V_25 = - 1 ;
while ( V_158 < V_161 ) {
T_4 V_27 ;
if ( F_16 ( V_157 , & V_149 , sizeof( V_149 ) ) != sizeof( V_149 ) )
goto V_152;
if ( V_12 -> V_31 )
F_100 ( & V_149 . V_12 ) ;
V_27 = V_149 . V_12 . V_17 - sizeof( V_149 ) ;
if ( F_16 ( V_157 , V_68 , V_27 ) != V_27 )
goto V_152;
if ( memcmp ( V_68 , L_57 , 13 ) == 0 ) {
if ( F_102 ( V_157 , V_164 , V_165 ) == ( V_166 ) - 1 )
return - 1 ;
return F_99 ( V_12 , V_157 , V_158 , V_17 ) ;
}
F_95 ( & V_149 , V_68 , V_58 ) ;
V_158 += V_149 . V_12 . V_17 ;
}
V_25 = 0 ;
V_152:
return V_25 ;
}
static int F_103 ( struct V_167 * T_11 V_168 ,
struct V_11 * V_29 V_168 ,
int V_13 V_168 , int V_15 , void * V_169 )
{
F_104 ( V_15 , V_169 , false ) ;
return 0 ;
}
static int F_105 ( struct V_167 * T_11 ,
struct V_11 * V_29 ,
int V_13 V_168 , int V_15 , void * V_169 V_82 )
{
if ( F_101 ( V_29 , V_15 , T_11 -> V_158 , T_11 -> V_17 ) )
F_30 ( L_58 ) ;
return 0 ;
}
static int F_106 ( struct V_167 * T_11 ,
struct V_11 * V_29 ,
int V_13 , int V_15 , void * V_169 )
{
struct V_170 * V_171 = V_169 ;
if ( F_102 ( V_15 , T_11 -> V_158 , V_165 ) == ( V_166 ) - 1 ) {
F_30 ( L_59 V_126 L_60
L_61 , T_11 -> V_158 , V_13 ) ;
return 0 ;
}
if ( V_13 >= V_172 ) {
F_2 ( L_62 , V_13 ) ;
return 0 ;
}
if ( ! V_173 [ V_13 ] . V_174 )
return 0 ;
if ( ! V_173 [ V_13 ] . V_175 || V_171 -> V_176 )
V_173 [ V_13 ] . V_174 ( V_29 , V_15 , V_171 -> V_116 ) ;
else
fprintf ( V_171 -> V_116 , L_63 ,
V_173 [ V_13 ] . V_2 ) ;
return 0 ;
}
int F_107 ( struct V_57 * V_58 , T_9 * V_116 , bool V_176 )
{
struct V_170 V_171 ;
struct V_11 * V_12 = & V_58 -> V_12 ;
int V_15 = V_58 -> V_15 ;
V_171 . V_116 = V_116 ;
V_171 . V_176 = V_176 ;
F_108 ( V_12 , V_15 , & V_171 ,
F_106 ) ;
return 0 ;
}
static int F_109 ( int V_15 , struct V_11 * T_8 , int type ,
struct V_167 * * V_94 ,
struct V_83 * V_84 )
{
int V_25 ;
int V_18 = 0 ;
if ( F_8 ( T_8 , type ) ) {
if ( ! V_173 [ type ] . F_11 )
return - 1 ;
( * V_94 ) -> V_158 = F_102 ( V_15 , 0 , V_177 ) ;
V_25 = V_173 [ type ] . F_11 ( V_15 , T_8 , V_84 ) ;
if ( V_25 < 0 ) {
F_30 ( L_64 , type ) ;
F_102 ( V_15 , ( * V_94 ) -> V_158 , V_165 ) ;
return - 1 ;
}
( * V_94 ) -> V_17 = F_102 ( V_15 , 0 , V_177 ) - ( * V_94 ) -> V_158 ;
( * V_94 ) ++ ;
}
return V_18 ;
}
static int F_110 ( struct V_11 * V_12 ,
struct V_83 * V_84 , int V_15 )
{
int V_178 ;
struct V_167 * V_179 , * V_94 ;
int V_180 ;
T_1 V_181 ;
int V_13 ;
int V_25 ;
V_178 = F_111 ( V_12 -> V_14 , V_182 ) ;
if ( ! V_178 )
return 0 ;
V_179 = V_94 = calloc ( sizeof( * V_179 ) , V_178 ) ;
if ( V_179 == NULL )
return - V_8 ;
V_180 = sizeof( * V_179 ) * V_178 ;
V_181 = V_12 -> V_183 + V_12 -> V_184 ;
F_102 ( V_15 , V_181 + V_180 , V_165 ) ;
F_112 (feat, header->adds_features, HEADER_FEAT_BITS) {
if ( F_109 ( V_15 , V_12 , V_13 , & V_94 , V_84 ) )
F_6 ( V_12 , V_13 ) ;
}
F_102 ( V_15 , V_181 , V_165 ) ;
V_25 = F_10 ( V_15 , V_179 , V_180 ) ;
if ( V_25 < 0 )
F_30 ( L_65 ) ;
free ( V_179 ) ;
return V_25 ;
}
int F_113 ( int V_15 )
{
struct V_185 V_186 ;
int V_25 ;
V_186 = (struct V_185 ) {
. V_187 = V_188 ,
. V_17 = sizeof( V_186 ) ,
} ;
V_25 = F_10 ( V_15 , & V_186 , sizeof( V_186 ) ) ;
if ( V_25 < 0 ) {
F_30 ( L_66 ) ;
return V_25 ;
}
return 0 ;
}
int F_114 ( struct V_57 * V_58 ,
struct V_83 * V_84 ,
int V_15 , bool V_189 )
{
struct V_190 V_186 ;
struct V_191 V_192 ;
struct V_11 * V_12 = & V_58 -> V_12 ;
struct V_105 * V_106 , * V_193 = NULL ;
int V_25 ;
F_102 ( V_15 , sizeof( V_186 ) , V_165 ) ;
if ( V_58 -> V_84 != V_84 )
V_193 = F_115 ( V_58 -> V_84 -> V_85 . V_194 , struct V_105 , V_127 ) ;
F_65 (attr, &evlist->entries, node) {
V_106 -> V_195 = F_102 ( V_15 , 0 , V_177 ) ;
V_25 = F_10 ( V_15 , V_106 -> V_1 , V_106 -> V_109 * sizeof( T_1 ) ) ;
if ( V_25 < 0 ) {
V_196:
F_30 ( L_67 ) ;
return V_25 ;
}
if ( V_58 -> V_84 != V_84 ) {
V_25 = F_10 ( V_15 , V_193 -> V_1 , V_193 -> V_109 * sizeof( T_1 ) ) ;
if ( V_25 < 0 )
goto V_196;
V_106 -> V_109 += V_193 -> V_109 ;
V_193 = F_115 ( V_193 -> V_127 . V_194 , struct V_105 , V_127 ) ;
}
}
V_12 -> V_197 = F_102 ( V_15 , 0 , V_177 ) ;
F_65 (attr, &evlist->entries, node) {
V_192 = (struct V_191 ) {
. V_106 = V_106 -> V_106 ,
. V_109 = {
. V_158 = V_106 -> V_195 ,
. V_17 = V_106 -> V_109 * sizeof( T_1 ) ,
}
} ;
V_25 = F_10 ( V_15 , & V_192 , sizeof( V_192 ) ) ;
if ( V_25 < 0 ) {
F_30 ( L_68 ) ;
return V_25 ;
}
}
V_12 -> V_198 = F_102 ( V_15 , 0 , V_177 ) ;
V_12 -> V_199 = V_7 * sizeof( struct V_3 ) ;
if ( V_6 ) {
V_25 = F_10 ( V_15 , V_6 , V_12 -> V_199 ) ;
if ( V_25 < 0 ) {
F_30 ( L_69 ) ;
return V_25 ;
}
}
V_12 -> V_183 = F_102 ( V_15 , 0 , V_177 ) ;
if ( V_189 ) {
V_25 = F_110 ( V_12 , V_84 , V_15 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_186 = (struct V_190 ) {
. V_187 = V_188 ,
. V_17 = sizeof( V_186 ) ,
. V_200 = sizeof( V_192 ) ,
. V_201 = {
. V_158 = V_12 -> V_197 ,
. V_17 = V_84 -> V_202 * sizeof( V_192 ) ,
} ,
. V_169 = {
. V_158 = V_12 -> V_183 ,
. V_17 = V_12 -> V_184 ,
} ,
. V_203 = {
. V_158 = V_12 -> V_198 ,
. V_17 = V_12 -> V_199 ,
} ,
} ;
memcpy ( & V_186 . V_14 , & V_12 -> V_14 , sizeof( V_12 -> V_14 ) ) ;
F_102 ( V_15 , 0 , V_165 ) ;
V_25 = F_10 ( V_15 , & V_186 , sizeof( V_186 ) ) ;
if ( V_25 < 0 ) {
F_30 ( L_67 ) ;
return V_25 ;
}
F_102 ( V_15 , V_12 -> V_183 + V_12 -> V_184 , V_165 ) ;
V_12 -> V_204 = 1 ;
return 0 ;
}
static int F_116 ( struct V_11 * V_12 ,
int V_15 , void * V_16 , T_2 V_17 )
{
if ( F_117 ( V_15 , V_16 , V_17 ) <= 0 )
return - 1 ;
if ( V_12 -> V_31 )
F_118 ( V_16 , V_17 ) ;
return 0 ;
}
int F_108 ( struct V_11 * V_12 , int V_15 ,
void * V_169 ,
int (* F_119)( struct V_167 * T_11 ,
struct V_11 * V_29 ,
int V_13 , int V_15 , void * V_169 ) )
{
struct V_167 * V_179 , * V_205 ;
int V_178 ;
int V_180 ;
int V_13 ;
int V_25 ;
V_178 = F_111 ( V_12 -> V_14 , V_182 ) ;
if ( ! V_178 )
return 0 ;
V_179 = V_205 = calloc ( sizeof( * V_179 ) , V_178 ) ;
if ( ! V_179 )
return - 1 ;
V_180 = sizeof( * V_179 ) * V_178 ;
F_102 ( V_15 , V_12 -> V_183 + V_12 -> V_184 , V_165 ) ;
V_25 = F_116 ( V_12 , V_15 , V_179 , V_180 ) ;
if ( V_25 < 0 )
goto V_73;
F_112 (feat, header->adds_features, HEADER_LAST_FEATURE) {
V_25 = F_119 ( V_205 ++ , V_12 , V_13 , V_15 , V_169 ) ;
if ( V_25 < 0 )
goto V_73;
}
V_25 = 0 ;
V_73:
free ( V_179 ) ;
return V_25 ;
}
static int F_120 ( T_10 V_206 , struct V_11 * V_29 )
{
T_10 V_207 , V_200 ;
int V_10 ;
for ( V_10 = 0 ; V_208 [ V_10 ] ; V_10 ++ ) {
V_207 = V_208 [ V_10 ]
+ sizeof( struct V_167 ) ;
if ( V_206 != V_207 ) {
V_200 = F_90 ( V_206 ) ;
if ( V_200 != V_207 )
continue;
V_29 -> V_31 = true ;
}
F_30 ( L_70 ,
V_10 ,
V_29 -> V_31 ) ;
return 0 ;
}
return - 1 ;
}
static int F_121 ( T_10 V_206 , struct V_11 * V_29 )
{
T_1 V_200 ;
int V_10 ;
for ( V_10 = 0 ; V_209 [ V_10 ] ; V_10 ++ ) {
if ( V_206 != V_209 [ V_10 ] ) {
V_200 = F_90 ( V_206 ) ;
if ( V_200 != V_206 )
continue;
V_29 -> V_31 = true ;
}
F_30 ( L_71 , V_10 ) ;
return 0 ;
}
return - 1 ;
}
static int F_122 ( T_1 V_187 , T_10 V_206 ,
bool V_210 , struct V_11 * V_29 )
{
int V_18 ;
V_18 = memcmp ( & V_187 , V_211 , sizeof( V_187 ) ) ;
if ( V_18 == 0 ) {
F_30 ( L_72 ) ;
if ( V_210 )
return F_121 ( V_206 , V_29 ) ;
return F_120 ( V_206 , V_29 ) ;
}
if ( V_187 == V_212 )
return 0 ;
if ( V_187 != V_213 )
return - 1 ;
V_29 -> V_31 = true ;
return 0 ;
}
int F_123 ( struct V_190 * V_12 ,
struct V_11 * V_29 , int V_15 )
{
int V_18 ;
F_102 ( V_15 , 0 , V_165 ) ;
V_18 = F_117 ( V_15 , V_12 , sizeof( * V_12 ) ) ;
if ( V_18 <= 0 )
return - 1 ;
if ( F_122 ( V_12 -> V_187 ,
V_12 -> V_200 , false , V_29 ) < 0 ) {
F_30 ( L_73 ) ;
return - 1 ;
}
if ( V_29 -> V_31 ) {
F_118 ( V_12 , F_124 ( struct V_190 ,
V_14 ) ) ;
}
if ( V_12 -> V_17 != sizeof( * V_12 ) ) {
if ( V_12 -> V_17 == F_124 ( F_125 ( * V_12 ) , V_14 ) )
F_126 ( V_12 -> V_14 , V_182 ) ;
else
return - 1 ;
} else if ( V_29 -> V_31 ) {
F_118 ( & V_12 -> V_14 ,
F_127 ( V_182 ) ) ;
if ( ! F_9 ( V_214 , V_12 -> V_14 ) ) {
F_118 ( & V_12 -> V_14 ,
F_127 ( V_182 ) ) ;
F_128 ( & V_12 -> V_14 ,
F_129 ( V_182 ) ) ;
}
if ( ! F_9 ( V_214 , V_12 -> V_14 ) ) {
F_126 ( V_12 -> V_14 , V_182 ) ;
F_5 ( V_215 , V_12 -> V_14 ) ;
}
}
memcpy ( & V_29 -> V_14 , & V_12 -> V_14 ,
sizeof( V_29 -> V_14 ) ) ;
V_29 -> V_198 = V_12 -> V_203 . V_158 ;
V_29 -> V_199 = V_12 -> V_203 . V_17 ;
V_29 -> V_183 = V_12 -> V_169 . V_158 ;
V_29 -> V_184 = V_12 -> V_169 . V_17 ;
return 0 ;
}
static int F_130 ( struct V_167 * T_11 ,
struct V_11 * V_29 ,
int V_13 , int V_15 , void * V_169 )
{
if ( F_102 ( V_15 , T_11 -> V_158 , V_165 ) == ( V_166 ) - 1 ) {
F_30 ( L_59 V_126 L_60
L_61 , T_11 -> V_158 , V_13 ) ;
return 0 ;
}
if ( V_13 >= V_172 ) {
F_30 ( L_74 , V_13 ) ;
return 0 ;
}
if ( ! V_173 [ V_13 ] . F_119 )
return 0 ;
return V_173 [ V_13 ] . F_119 ( T_11 , V_29 , V_13 , V_15 , V_169 ) ;
}
static int F_131 ( struct V_185 * V_12 ,
struct V_11 * V_29 , int V_15 ,
bool V_216 )
{
int V_18 ;
V_18 = F_117 ( V_15 , V_12 , sizeof( * V_12 ) ) ;
if ( V_18 <= 0 )
return - 1 ;
if ( F_122 ( V_12 -> V_187 , V_12 -> V_17 , true , V_29 ) < 0 ) {
F_30 ( L_75 ) ;
return - 1 ;
}
if ( V_29 -> V_31 )
V_12 -> V_17 = F_90 ( V_12 -> V_17 ) ;
if ( V_216 && F_10 ( V_217 , V_12 , sizeof( * V_12 ) ) < 0 )
return - 1 ;
return 0 ;
}
static int F_132 ( struct V_57 * V_58 , int V_15 )
{
struct V_11 * V_12 = & V_58 -> V_12 ;
struct V_185 V_186 ;
if ( F_131 ( & V_186 , V_12 , V_15 ,
V_58 -> V_216 ) < 0 ) {
F_30 ( L_76 ) ;
return - V_218 ;
}
V_58 -> V_15 = V_15 ;
return 0 ;
}
static int F_133 ( int V_15 , struct V_11 * V_29 ,
struct V_191 * V_192 )
{
struct V_138 * V_106 = & V_192 -> V_106 ;
T_2 V_30 , V_219 ;
T_2 V_220 = sizeof( V_192 -> V_106 ) ;
int V_18 ;
memset ( V_192 , 0 , sizeof( * V_192 ) ) ;
V_18 = F_117 ( V_15 , V_106 , V_221 ) ;
if ( V_18 <= 0 ) {
F_30 ( L_77 ,
V_221 ) ;
return - 1 ;
}
V_30 = V_106 -> V_17 ;
if ( V_29 -> V_31 )
V_30 = F_17 ( V_30 ) ;
if ( V_30 == 0 ) {
V_30 = V_221 ;
} else if ( V_30 > V_220 ) {
F_30 ( L_78
L_79 , V_30 - V_220 ) ;
return - 1 ;
}
V_219 = V_30 - V_221 ;
if ( V_219 ) {
void * V_222 = V_106 ;
V_222 += V_221 ;
V_18 = F_117 ( V_15 , V_222 , V_219 ) ;
}
V_18 = F_117 ( V_15 , & V_192 -> V_109 , sizeof( V_192 -> V_109 ) ) ;
return V_18 <= 0 ? - 1 : 0 ;
}
static int F_134 ( struct V_105 * V_223 ,
struct V_224 * V_224 )
{
struct V_225 * V_226 = F_135 ( V_224 ,
V_223 -> V_106 . V_141 ) ;
char V_20 [ 128 ] ;
if ( V_226 == NULL )
return - 1 ;
snprintf ( V_20 , sizeof( V_20 ) , L_80 , V_226 -> system , V_226 -> V_2 ) ;
V_223 -> V_2 = F_136 ( V_20 ) ;
if ( V_226 -> V_2 == NULL )
return - 1 ;
return 0 ;
}
static int F_137 ( struct V_83 * V_84 ,
struct V_224 * V_224 )
{
struct V_105 * V_41 ;
F_65 (pos, &evlist->entries, node) {
if ( V_41 -> V_106 . type == V_227 &&
F_134 ( V_41 , V_224 ) )
return - 1 ;
}
return 0 ;
}
int F_138 ( struct V_57 * V_58 , int V_15 )
{
struct V_11 * V_12 = & V_58 -> V_12 ;
struct V_190 V_186 ;
struct V_191 V_192 ;
T_1 V_228 ;
int V_229 , V_230 , V_10 , V_134 ;
V_58 -> V_84 = F_139 ( NULL , NULL ) ;
if ( V_58 -> V_84 == NULL )
return - V_8 ;
if ( V_58 -> V_231 )
return F_132 ( V_58 , V_15 ) ;
if ( F_123 ( & V_186 , V_12 , V_15 ) < 0 )
return - V_218 ;
V_229 = V_186 . V_201 . V_17 / V_186 . V_200 ;
F_102 ( V_15 , V_186 . V_201 . V_158 , V_165 ) ;
for ( V_10 = 0 ; V_10 < V_229 ; V_10 ++ ) {
struct V_105 * V_223 ;
V_166 V_232 ;
if ( F_133 ( V_15 , V_12 , & V_192 ) < 0 )
goto V_233;
if ( V_12 -> V_31 )
F_89 ( & V_192 . V_106 ) ;
V_232 = F_102 ( V_15 , 0 , V_177 ) ;
V_223 = F_140 ( & V_192 . V_106 , V_10 ) ;
if ( V_223 == NULL )
goto V_234;
F_141 ( V_58 -> V_84 , V_223 ) ;
V_230 = V_192 . V_109 . V_17 / sizeof( T_1 ) ;
if ( F_142 ( V_223 , 1 , V_230 ) )
goto V_234;
F_102 ( V_15 , V_192 . V_109 . V_158 , V_165 ) ;
for ( V_134 = 0 ; V_134 < V_230 ; V_134 ++ ) {
if ( F_116 ( V_12 , V_15 , & V_228 , sizeof( V_228 ) ) )
goto V_233;
F_143 ( V_58 -> V_84 , V_223 , 0 , V_134 , V_228 ) ;
}
F_102 ( V_15 , V_232 , V_165 ) ;
}
V_71 . V_235 = V_229 ;
if ( V_186 . V_203 . V_17 ) {
F_102 ( V_15 , V_186 . V_203 . V_158 , V_165 ) ;
V_6 = malloc ( V_186 . V_203 . V_17 ) ;
if ( V_6 == NULL )
return - V_8 ;
if ( F_116 ( V_12 , V_15 , V_6 ,
V_186 . V_203 . V_17 ) )
goto V_233;
V_7 = V_186 . V_203 . V_17 / sizeof( struct V_3 ) ;
}
F_108 ( V_12 , V_15 , & V_58 -> V_224 ,
F_130 ) ;
F_102 ( V_15 , V_12 -> V_183 , V_165 ) ;
if ( F_137 ( V_58 -> V_84 , V_58 -> V_224 ) )
goto V_234;
V_12 -> V_204 = 1 ;
return 0 ;
V_233:
return - V_19 ;
V_234:
F_144 ( V_58 -> V_84 ) ;
V_58 -> V_84 = NULL ;
return - V_8 ;
}
int F_145 ( struct V_236 * V_237 ,
struct V_138 * V_106 , T_6 V_109 , T_1 * V_1 ,
T_12 F_119 )
{
union V_238 * V_239 ;
T_2 V_17 ;
int V_25 ;
V_17 = sizeof( struct V_138 ) ;
V_17 = F_14 ( V_17 , sizeof( T_1 ) ) ;
V_17 += sizeof( struct V_159 ) ;
V_17 += V_109 * sizeof( T_1 ) ;
V_239 = malloc ( V_17 ) ;
if ( V_239 == NULL )
return - V_8 ;
V_239 -> V_106 . V_106 = * V_106 ;
memcpy ( V_239 -> V_106 . V_1 , V_1 , V_109 * sizeof( T_1 ) ) ;
V_239 -> V_106 . V_12 . type = V_240 ;
V_239 -> V_106 . V_12 . V_17 = V_17 ;
V_25 = F_119 ( V_237 , V_239 , NULL , NULL ) ;
free ( V_239 ) ;
return V_25 ;
}
int F_146 ( struct V_236 * V_237 ,
struct V_57 * V_58 ,
T_12 F_119 )
{
struct V_105 * V_106 ;
int V_25 = 0 ;
F_65 (attr, &session->evlist->entries, node) {
V_25 = F_145 ( V_237 , & V_106 -> V_106 , V_106 -> V_109 ,
V_106 -> V_1 , F_119 ) ;
if ( V_25 ) {
F_30 ( L_81 ) ;
return V_25 ;
}
}
return V_25 ;
}
int F_147 ( union V_238 * V_226 ,
struct V_83 * * V_241 )
{
unsigned int V_10 , V_109 , V_242 ;
struct V_105 * V_223 ;
struct V_83 * V_84 = * V_241 ;
if ( V_84 == NULL ) {
* V_241 = V_84 = F_139 ( NULL , NULL ) ;
if ( V_84 == NULL )
return - V_8 ;
}
V_223 = F_140 ( & V_226 -> V_106 . V_106 , V_84 -> V_202 ) ;
if ( V_223 == NULL )
return - V_8 ;
F_141 ( V_84 , V_223 ) ;
V_109 = V_226 -> V_12 . V_17 ;
V_109 -= ( void * ) & V_226 -> V_106 . V_1 - ( void * ) V_226 ;
V_242 = V_109 / sizeof( T_1 ) ;
if ( F_142 ( V_223 , 1 , V_242 ) )
return - V_8 ;
for ( V_10 = 0 ; V_10 < V_242 ; V_10 ++ ) {
F_143 ( V_84 , V_223 , 0 , V_10 , V_226 -> V_106 . V_1 [ V_10 ] ) ;
}
return 0 ;
}
int F_148 ( struct V_236 * V_237 ,
T_1 V_9 , char * V_2 ,
T_12 F_119 ,
struct V_48 * V_48 )
{
union V_238 V_239 ;
T_2 V_17 = 0 ;
int V_25 = 0 ;
memset ( & V_239 , 0 , sizeof( V_239 ) ) ;
V_239 . V_243 . V_243 . V_9 = V_9 ;
memset ( V_239 . V_243 . V_243 . V_2 , 0 , V_5 ) ;
strncpy ( V_239 . V_243 . V_243 . V_2 , V_2 , V_5 - 1 ) ;
V_239 . V_243 . V_12 . type = V_244 ;
V_17 = strlen ( V_239 . V_243 . V_243 . V_2 ) ;
V_17 = F_14 ( V_17 , sizeof( T_1 ) ) ;
V_239 . V_243 . V_12 . V_17 = sizeof( V_239 . V_243 ) -
( sizeof( V_239 . V_243 . V_243 . V_2 ) - V_17 ) ;
V_25 = F_119 ( V_237 , & V_239 , NULL , V_48 ) ;
return V_25 ;
}
int F_149 ( struct V_236 * V_237 ,
T_12 F_119 ,
struct V_48 * V_48 )
{
struct V_3 * type ;
int V_10 , V_25 = 0 ;
for ( V_10 = 0 ; V_10 < V_7 ; V_10 ++ ) {
type = & V_6 [ V_10 ] ;
V_25 = F_148 ( V_237 , type -> V_9 ,
type -> V_2 , F_119 ,
V_48 ) ;
if ( V_25 ) {
F_30 ( L_82 ) ;
return V_25 ;
}
}
return V_25 ;
}
int F_150 ( struct V_236 * V_237 V_168 ,
union V_238 * V_226 )
{
if ( F_1 ( V_226 -> V_243 . V_243 . V_9 ,
V_226 -> V_243 . V_243 . V_2 ) < 0 )
return - V_8 ;
return 0 ;
}
int F_151 ( struct V_236 * V_237 , int V_15 ,
struct V_83 * V_84 ,
T_12 F_119 )
{
union V_238 V_239 ;
struct V_245 * V_246 ;
T_4 V_17 = 0 , V_247 = 0 , V_248 ;
int V_25 V_82 = 0 ;
V_246 = F_152 ( & V_84 -> V_85 , V_15 , true ) ;
if ( ! V_246 )
return - 1 ;
memset ( & V_239 , 0 , sizeof( V_239 ) ) ;
V_239 . V_245 . V_12 . type = V_249 ;
V_17 = V_246 -> V_17 ;
V_247 = F_14 ( V_17 , sizeof( T_1 ) ) ;
V_248 = V_247 - V_17 ;
V_239 . V_245 . V_12 . V_17 = sizeof( V_239 . V_245 ) ;
V_239 . V_245 . V_17 = V_247 ;
F_119 ( V_237 , & V_239 , NULL , NULL ) ;
F_153 ( V_246 ) ;
F_12 ( V_15 , NULL , 0 , V_248 ) ;
return V_247 ;
}
int F_154 ( union V_238 * V_226 ,
struct V_57 * V_58 )
{
T_4 V_250 , V_248 , V_17 = V_226 -> V_245 . V_17 ;
V_166 V_158 = F_102 ( V_58 -> V_15 , 0 , V_177 ) ;
char V_16 [ V_251 ] ;
F_102 ( V_58 -> V_15 , V_158 + sizeof( struct V_252 ) ,
V_165 ) ;
V_250 = F_104 ( V_58 -> V_15 , & V_58 -> V_224 ,
V_58 -> V_216 ) ;
V_248 = F_14 ( V_250 , sizeof( T_1 ) ) - V_250 ;
if ( F_16 ( V_58 -> V_15 , V_16 , V_248 ) < 0 )
F_155 ( L_83 ) ;
if ( V_58 -> V_216 ) {
int V_253 = F_11 ( V_217 , V_16 , V_248 ) ;
if ( V_253 <= 0 || V_253 != V_248 )
F_155 ( L_84 ) ;
}
if ( V_250 + V_248 != V_17 )
F_155 ( L_85 ) ;
return V_250 + V_248 ;
}
int F_156 ( struct V_236 * V_237 ,
struct V_40 * V_41 , T_6 V_39 ,
T_12 F_119 ,
struct V_48 * V_48 )
{
union V_238 V_239 ;
T_2 V_27 ;
int V_25 = 0 ;
if ( ! V_41 -> V_44 )
return V_25 ;
memset ( & V_239 , 0 , sizeof( V_239 ) ) ;
V_27 = V_41 -> V_45 + 1 ;
V_27 = F_14 ( V_27 , V_24 ) ;
memcpy ( & V_239 . V_46 . V_46 , V_41 -> V_46 , sizeof( V_41 -> V_46 ) ) ;
V_239 . V_46 . V_12 . type = V_254 ;
V_239 . V_46 . V_12 . V_39 = V_39 ;
V_239 . V_46 . V_38 = V_48 -> V_38 ;
V_239 . V_46 . V_12 . V_17 = sizeof( V_239 . V_46 ) + V_27 ;
memcpy ( & V_239 . V_46 . V_68 , V_41 -> V_47 , V_41 -> V_45 ) ;
V_25 = F_119 ( V_237 , & V_239 , NULL , V_48 ) ;
return V_25 ;
}
int F_157 ( struct V_236 * V_237 V_82 ,
union V_238 * V_226 ,
struct V_57 * V_58 )
{
F_95 ( & V_226 -> V_46 ,
V_226 -> V_46 . V_68 ,
V_58 ) ;
return 0 ;
}
void F_158 ( void )
{
V_86 = true ;
}
