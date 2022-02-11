static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
int V_3 ;
V_3 = F_2 ( V_4 ) ;
if ( V_3 < 0 )
return NULL ;
V_2 = malloc ( sizeof( * V_2 ) + V_3 * sizeof( int ) ) ;
if ( V_2 != NULL ) {
int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 ; ++ V_5 )
V_2 -> V_6 [ V_5 ] = V_5 ;
V_2 -> V_7 = V_3 ;
}
return V_2 ;
}
static struct V_1 * F_3 ( int V_3 , int * V_8 )
{
T_1 V_9 = V_3 * sizeof( int ) ;
struct V_1 * V_2 = malloc ( sizeof( * V_2 ) + V_9 ) ;
if ( V_2 != NULL ) {
V_2 -> V_7 = V_3 ;
memcpy ( V_2 -> V_6 , V_8 , V_9 ) ;
}
return V_2 ;
}
struct V_1 * F_4 ( T_2 * V_10 )
{
struct V_1 * V_2 = NULL ;
int V_3 = 0 ;
int * V_8 = NULL , * V_11 ;
int V_12 = 0 ;
int V_13 , V_14 , V_15 ;
char V_16 ;
V_16 = 0 ;
V_15 = - 1 ;
for (; ; ) {
V_13 = fscanf ( V_10 , L_1 , & V_14 , & V_16 ) ;
if ( V_13 <= 0 )
break;
if ( V_15 >= 0 ) {
int V_17 = V_3 + V_14 - V_15 - 1 ;
if ( V_17 >= V_12 ) {
V_12 = V_17 + V_18 / 2 ;
V_11 = realloc ( V_8 , V_12 * sizeof( int ) ) ;
if ( V_11 == NULL )
goto V_19;
V_8 = V_11 ;
}
while ( ++ V_15 < V_14 )
V_8 [ V_3 ++ ] = V_15 ;
}
if ( V_3 == V_12 ) {
V_12 += V_18 ;
V_11 = realloc ( V_8 , V_12 * sizeof( int ) ) ;
if ( V_11 == NULL )
goto V_19;
V_8 = V_11 ;
}
V_8 [ V_3 ++ ] = V_14 ;
if ( V_13 == 2 && V_16 == '-' )
V_15 = V_14 ;
else
V_15 = - 1 ;
if ( V_13 == 1 || V_16 == '\n' )
break;
}
if ( V_3 > 0 )
V_2 = F_3 ( V_3 , V_8 ) ;
else
V_2 = F_1 () ;
V_19:
free ( V_8 ) ;
return V_2 ;
}
static struct V_1 * F_5 ( void )
{
struct V_1 * V_2 = NULL ;
T_2 * V_20 ;
V_20 = fopen ( L_2 , L_3 ) ;
if ( ! V_20 )
return F_1 () ;
V_2 = F_4 ( V_20 ) ;
fclose ( V_20 ) ;
return V_2 ;
}
struct V_1 * F_6 ( const char * V_21 )
{
struct V_1 * V_2 = NULL ;
unsigned long V_22 , V_23 = 0 ;
char * V_24 = NULL ;
int V_5 , V_3 = 0 ;
int * V_8 = NULL , * V_11 ;
int V_12 = 0 ;
if ( ! V_21 )
return F_5 () ;
if ( ! isdigit ( * V_21 ) )
goto V_25;
while ( isdigit ( * V_21 ) ) {
V_24 = NULL ;
V_22 = strtoul ( V_21 , & V_24 , 0 ) ;
if ( V_22 >= V_26
|| ( * V_24 != '\0' && * V_24 != ',' && * V_24 != '-' ) )
goto V_27;
if ( * V_24 == '-' ) {
V_21 = ++ V_24 ;
V_24 = NULL ;
V_23 = strtoul ( V_21 , & V_24 , 0 ) ;
if ( V_23 >= V_26 || ( * V_24 != '\0' && * V_24 != ',' ) )
goto V_27;
if ( V_23 < V_22 )
goto V_27;
} else {
V_23 = V_22 ;
}
for (; V_22 <= V_23 ; V_22 ++ ) {
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ )
if ( V_8 [ V_5 ] == ( int ) V_22 )
goto V_27;
if ( V_3 == V_12 ) {
V_12 += V_18 ;
V_11 = realloc ( V_8 , V_12 * sizeof( int ) ) ;
if ( V_11 == NULL )
goto V_27;
V_8 = V_11 ;
}
V_8 [ V_3 ++ ] = ( int ) V_22 ;
}
if ( * V_24 )
++ V_24 ;
V_21 = V_24 ;
}
if ( V_3 > 0 )
V_2 = F_3 ( V_3 , V_8 ) ;
else
V_2 = F_1 () ;
V_27:
free ( V_8 ) ;
V_25:
return V_2 ;
}
T_1 F_7 ( struct V_1 * V_6 , T_2 * V_28 )
{
int V_5 ;
T_1 V_29 = fprintf ( V_28 , L_4 ,
V_6 -> V_7 , V_6 -> V_7 > 1 ? L_5 : L_6 ) ;
for ( V_5 = 0 ; V_5 < V_6 -> V_7 ; ++ V_5 )
V_29 += fprintf ( V_28 , L_7 , V_5 ? L_8 : L_6 , V_6 -> V_6 [ V_5 ] ) ;
return V_29 + fprintf ( V_28 , L_9 ) ;
}
struct V_1 * F_8 ( void )
{
struct V_1 * V_2 = malloc ( sizeof( * V_2 ) + sizeof( int ) ) ;
if ( V_2 != NULL ) {
V_2 -> V_7 = 1 ;
V_2 -> V_6 [ 0 ] = - 1 ;
}
return V_2 ;
}
void F_9 ( struct V_1 * V_6 )
{
free ( V_6 ) ;
}
int F_10 ( struct V_1 * V_6 , int V_30 )
{
T_2 * V_28 ;
const char * V_31 ;
char V_32 [ V_33 ] ;
int V_14 , V_34 ;
if ( V_30 > V_6 -> V_7 )
return - 1 ;
V_14 = V_6 -> V_6 [ V_30 ] ;
V_31 = F_11 () ;
if ( ! V_31 )
return - 1 ;
snprintf ( V_32 , V_33 ,
L_10 ,
V_31 , V_14 ) ;
V_28 = fopen ( V_32 , L_3 ) ;
if ( ! V_28 )
return - 1 ;
V_34 = fscanf ( V_28 , L_11 , & V_14 ) ;
fclose ( V_28 ) ;
return V_34 == 1 ? V_14 : - 1 ;
}
static int F_12 ( const void * V_35 , const void * V_36 )
{
return * ( int * ) V_35 - * ( int * ) V_36 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_1 * * V_37 ,
int (* F_14)( struct V_1 * V_6 , int V_14 ) )
{
struct V_1 * V_38 ;
int V_7 = V_2 -> V_7 ;
int V_14 , V_39 , V_40 ;
V_38 = calloc ( 1 , sizeof( * V_38 ) + V_7 * sizeof( int ) ) ;
if ( ! V_38 )
return - 1 ;
for ( V_14 = 0 ; V_14 < V_7 ; V_14 ++ ) {
V_39 = F_14 ( V_2 , V_14 ) ;
for ( V_40 = 0 ; V_40 < V_38 -> V_7 ; V_40 ++ ) {
if ( V_39 == V_38 -> V_6 [ V_40 ] )
break;
}
if ( V_40 == V_38 -> V_7 ) {
V_38 -> V_6 [ V_38 -> V_7 ] = V_39 ;
V_38 -> V_7 ++ ;
}
}
qsort ( V_38 -> V_6 , V_38 -> V_7 , sizeof( int ) , F_12 ) ;
* V_37 = V_38 ;
return 0 ;
}
int F_15 ( struct V_1 * V_6 , int V_30 )
{
T_2 * V_28 ;
const char * V_31 ;
char V_32 [ V_33 ] ;
int V_14 , V_34 , V_41 ;
if ( V_30 > V_6 -> V_7 )
return - 1 ;
V_14 = V_6 -> V_6 [ V_30 ] ;
V_31 = F_11 () ;
if ( ! V_31 )
return - 1 ;
snprintf ( V_32 , V_33 ,
L_12 ,
V_31 , V_14 ) ;
V_28 = fopen ( V_32 , L_3 ) ;
if ( ! V_28 )
return - 1 ;
V_34 = fscanf ( V_28 , L_11 , & V_14 ) ;
fclose ( V_28 ) ;
if ( V_34 != 1 )
return - 1 ;
V_41 = F_10 ( V_6 , V_30 ) ;
if ( V_41 == - 1 )
return - 1 ;
return ( V_41 << 16 ) | ( V_14 & 0xffff ) ;
}
int F_16 ( struct V_1 * V_2 , struct V_1 * * V_42 )
{
return F_13 ( V_2 , V_42 , F_10 ) ;
}
int F_17 ( struct V_1 * V_2 , struct V_1 * * V_43 )
{
return F_13 ( V_2 , V_43 , F_15 ) ;
}
static int F_18 ( char * V_32 , int * V_44 )
{
T_1 V_45 ;
char * V_46 ;
int V_47 = 0 ;
if ( F_19 ( V_32 , & V_46 , & V_45 ) )
return - 1 ;
V_46 [ V_45 ] = '\0' ;
while ( -- V_45 ) {
if ( ( V_46 [ V_45 ] == ',' ) || ( V_46 [ V_45 ] == '-' ) ) {
V_45 ++ ;
break;
}
}
if ( sscanf ( & V_46 [ V_45 ] , L_11 , V_44 ) < 1 ) {
V_47 = - 1 ;
goto V_25;
}
( * V_44 ) ++ ;
V_25:
free ( V_46 ) ;
return V_47 ;
}
static void F_20 ( void )
{
const char * V_31 ;
char V_32 [ V_33 ] ;
int V_34 = - 1 ;
V_48 = 4096 ;
V_31 = F_11 () ;
if ( ! V_31 )
goto V_25;
V_34 = snprintf ( V_32 , V_33 , L_13 , V_31 ) ;
if ( V_34 == V_33 ) {
F_21 ( L_14 , V_33 ) ;
goto V_25;
}
V_34 = F_18 ( V_32 , & V_48 ) ;
V_25:
if ( V_34 )
F_21 ( L_15 , V_48 ) ;
}
static void F_22 ( void )
{
const char * V_31 ;
char V_32 [ V_33 ] ;
int V_34 = - 1 ;
V_49 = 8 ;
V_31 = F_11 () ;
if ( ! V_31 )
goto V_25;
V_34 = snprintf ( V_32 , V_33 , L_16 , V_31 ) ;
if ( V_34 == V_33 ) {
F_21 ( L_14 , V_33 ) ;
goto V_25;
}
V_34 = F_18 ( V_32 , & V_49 ) ;
V_25:
if ( V_34 )
F_21 ( L_17 , V_49 ) ;
}
static int F_23 ( void )
{
int V_5 ;
F_20 () ;
F_22 () ;
V_50 = calloc ( V_48 , sizeof( int ) ) ;
if ( ! V_50 ) {
F_21 ( L_18 , V_51 ) ;
return - 1 ;
}
for ( V_5 = 0 ; V_5 < V_48 ; V_5 ++ )
V_50 [ V_5 ] = - 1 ;
return 0 ;
}
int F_24 ( void )
{
struct V_52 * V_53 , * V_54 ;
T_3 * V_55 , * V_56 ;
unsigned int V_14 , V_57 ;
char V_46 [ V_33 ] ;
char V_32 [ V_33 ] ;
const char * V_31 ;
int V_13 ;
if ( F_23 () )
return - 1 ;
V_31 = F_11 () ;
if ( ! V_31 )
return 0 ;
V_13 = snprintf ( V_32 , V_33 , L_19 , V_31 ) ;
if ( V_13 == V_33 ) {
F_21 ( L_14 , V_33 ) ;
return - 1 ;
}
V_55 = F_25 ( V_32 ) ;
if ( ! V_55 )
return 0 ;
while ( ( V_53 = F_26 ( V_55 ) ) != NULL ) {
if ( V_53 -> V_58 != V_59 || sscanf ( V_53 -> V_60 , L_20 , & V_57 ) < 1 )
continue;
V_13 = snprintf ( V_46 , V_33 , L_21 , V_32 , V_53 -> V_60 ) ;
if ( V_13 == V_33 ) {
F_21 ( L_14 , V_33 ) ;
continue;
}
V_56 = F_25 ( V_46 ) ;
if ( ! V_56 )
continue;
while ( ( V_54 = F_26 ( V_56 ) ) != NULL ) {
if ( V_54 -> V_58 != V_61 || sscanf ( V_54 -> V_60 , L_22 , & V_14 ) < 1 )
continue;
V_50 [ V_14 ] = V_57 ;
}
F_27 ( V_56 ) ;
}
F_27 ( V_55 ) ;
return 0 ;
}
