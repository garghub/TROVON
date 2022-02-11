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
F_3 ( & V_2 -> V_8 , 1 ) ;
}
return V_2 ;
}
static struct V_1 * F_4 ( int V_3 , int * V_9 )
{
T_1 V_10 = V_3 * sizeof( int ) ;
struct V_1 * V_2 = malloc ( sizeof( * V_2 ) + V_10 ) ;
if ( V_2 != NULL ) {
V_2 -> V_7 = V_3 ;
memcpy ( V_2 -> V_6 , V_9 , V_10 ) ;
F_3 ( & V_2 -> V_8 , 1 ) ;
}
return V_2 ;
}
struct V_1 * F_5 ( T_2 * V_11 )
{
struct V_1 * V_2 = NULL ;
int V_3 = 0 ;
int * V_9 = NULL , * V_12 ;
int V_13 = 0 ;
int V_14 , V_15 , V_16 ;
char V_17 ;
V_17 = 0 ;
V_16 = - 1 ;
for (; ; ) {
V_14 = fscanf ( V_11 , L_1 , & V_15 , & V_17 ) ;
if ( V_14 <= 0 )
break;
if ( V_16 >= 0 ) {
int V_18 = V_3 + V_15 - V_16 - 1 ;
if ( V_18 >= V_13 ) {
V_13 = V_18 + V_19 / 2 ;
V_12 = realloc ( V_9 , V_13 * sizeof( int ) ) ;
if ( V_12 == NULL )
goto V_20;
V_9 = V_12 ;
}
while ( ++ V_16 < V_15 )
V_9 [ V_3 ++ ] = V_16 ;
}
if ( V_3 == V_13 ) {
V_13 += V_19 ;
V_12 = realloc ( V_9 , V_13 * sizeof( int ) ) ;
if ( V_12 == NULL )
goto V_20;
V_9 = V_12 ;
}
V_9 [ V_3 ++ ] = V_15 ;
if ( V_14 == 2 && V_17 == '-' )
V_16 = V_15 ;
else
V_16 = - 1 ;
if ( V_14 == 1 || V_17 == '\n' )
break;
}
if ( V_3 > 0 )
V_2 = F_4 ( V_3 , V_9 ) ;
else
V_2 = F_1 () ;
V_20:
free ( V_9 ) ;
return V_2 ;
}
static struct V_1 * F_6 ( void )
{
struct V_1 * V_2 = NULL ;
T_2 * V_21 ;
V_21 = fopen ( L_2 , L_3 ) ;
if ( ! V_21 )
return F_1 () ;
V_2 = F_5 ( V_21 ) ;
fclose ( V_21 ) ;
return V_2 ;
}
struct V_1 * F_7 ( const char * V_22 )
{
struct V_1 * V_2 = NULL ;
unsigned long V_23 , V_24 = 0 ;
char * V_25 = NULL ;
int V_5 , V_3 = 0 ;
int * V_9 = NULL , * V_12 ;
int V_13 = 0 ;
if ( ! V_22 )
return F_6 () ;
if ( ! isdigit ( * V_22 ) )
goto V_26;
while ( isdigit ( * V_22 ) ) {
V_25 = NULL ;
V_23 = strtoul ( V_22 , & V_25 , 0 ) ;
if ( V_23 >= V_27
|| ( * V_25 != '\0' && * V_25 != ',' && * V_25 != '-' ) )
goto V_28;
if ( * V_25 == '-' ) {
V_22 = ++ V_25 ;
V_25 = NULL ;
V_24 = strtoul ( V_22 , & V_25 , 0 ) ;
if ( V_24 >= V_27 || ( * V_25 != '\0' && * V_25 != ',' ) )
goto V_28;
if ( V_24 < V_23 )
goto V_28;
} else {
V_24 = V_23 ;
}
for (; V_23 <= V_24 ; V_23 ++ ) {
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ )
if ( V_9 [ V_5 ] == ( int ) V_23 )
goto V_28;
if ( V_3 == V_13 ) {
V_13 += V_19 ;
V_12 = realloc ( V_9 , V_13 * sizeof( int ) ) ;
if ( V_12 == NULL )
goto V_28;
V_9 = V_12 ;
}
V_9 [ V_3 ++ ] = ( int ) V_23 ;
}
if ( * V_25 )
++ V_25 ;
V_22 = V_25 ;
}
if ( V_3 > 0 )
V_2 = F_4 ( V_3 , V_9 ) ;
else
V_2 = F_1 () ;
V_28:
free ( V_9 ) ;
V_26:
return V_2 ;
}
T_1 F_8 ( struct V_1 * V_6 , T_2 * V_29 )
{
int V_5 ;
T_1 V_30 = fprintf ( V_29 , L_4 ,
V_6 -> V_7 , V_6 -> V_7 > 1 ? L_5 : L_6 ) ;
for ( V_5 = 0 ; V_5 < V_6 -> V_7 ; ++ V_5 )
V_30 += fprintf ( V_29 , L_7 , V_5 ? L_8 : L_6 , V_6 -> V_6 [ V_5 ] ) ;
return V_30 + fprintf ( V_29 , L_9 ) ;
}
struct V_1 * F_9 ( void )
{
struct V_1 * V_2 = malloc ( sizeof( * V_2 ) + sizeof( int ) ) ;
if ( V_2 != NULL ) {
V_2 -> V_7 = 1 ;
V_2 -> V_6 [ 0 ] = - 1 ;
F_3 ( & V_2 -> V_8 , 1 ) ;
}
return V_2 ;
}
static void F_10 ( struct V_1 * V_6 )
{
if ( V_6 ) {
F_11 ( F_12 ( & V_6 -> V_8 ) != 0 ,
L_10 ) ;
free ( V_6 ) ;
}
}
struct V_1 * F_13 ( struct V_1 * V_6 )
{
if ( V_6 )
F_14 ( & V_6 -> V_8 ) ;
return V_6 ;
}
void F_15 ( struct V_1 * V_6 )
{
if ( V_6 && F_16 ( & V_6 -> V_8 ) )
F_10 ( V_6 ) ;
}
int F_17 ( struct V_1 * V_6 , int V_31 )
{
T_2 * V_29 ;
const char * V_32 ;
char V_33 [ V_34 ] ;
int V_15 , V_35 ;
if ( V_31 > V_6 -> V_7 )
return - 1 ;
V_15 = V_6 -> V_6 [ V_31 ] ;
V_32 = F_18 () ;
if ( ! V_32 )
return - 1 ;
snprintf ( V_33 , V_34 ,
L_11 ,
V_32 , V_15 ) ;
V_29 = fopen ( V_33 , L_3 ) ;
if ( ! V_29 )
return - 1 ;
V_35 = fscanf ( V_29 , L_12 , & V_15 ) ;
fclose ( V_29 ) ;
return V_35 == 1 ? V_15 : - 1 ;
}
static int F_19 ( const void * V_36 , const void * V_37 )
{
return * ( int * ) V_36 - * ( int * ) V_37 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_1 * * V_38 ,
int (* F_21)( struct V_1 * V_6 , int V_15 ) )
{
struct V_1 * V_39 ;
int V_7 = V_2 -> V_7 ;
int V_15 , V_40 , V_41 ;
V_39 = calloc ( 1 , sizeof( * V_39 ) + V_7 * sizeof( int ) ) ;
if ( ! V_39 )
return - 1 ;
for ( V_15 = 0 ; V_15 < V_7 ; V_15 ++ ) {
V_40 = F_21 ( V_2 , V_15 ) ;
for ( V_41 = 0 ; V_41 < V_39 -> V_7 ; V_41 ++ ) {
if ( V_40 == V_39 -> V_6 [ V_41 ] )
break;
}
if ( V_41 == V_39 -> V_7 ) {
V_39 -> V_6 [ V_39 -> V_7 ] = V_40 ;
V_39 -> V_7 ++ ;
}
}
qsort ( V_39 -> V_6 , V_39 -> V_7 , sizeof( int ) , F_19 ) ;
F_3 ( & V_2 -> V_8 , 1 ) ;
* V_38 = V_39 ;
return 0 ;
}
int F_22 ( struct V_1 * V_6 , int V_31 )
{
T_2 * V_29 ;
const char * V_32 ;
char V_33 [ V_34 ] ;
int V_15 , V_35 , V_42 ;
if ( V_31 > V_6 -> V_7 )
return - 1 ;
V_15 = V_6 -> V_6 [ V_31 ] ;
V_32 = F_18 () ;
if ( ! V_32 )
return - 1 ;
snprintf ( V_33 , V_34 ,
L_13 ,
V_32 , V_15 ) ;
V_29 = fopen ( V_33 , L_3 ) ;
if ( ! V_29 )
return - 1 ;
V_35 = fscanf ( V_29 , L_12 , & V_15 ) ;
fclose ( V_29 ) ;
if ( V_35 != 1 )
return - 1 ;
V_42 = F_17 ( V_6 , V_31 ) ;
if ( V_42 == - 1 )
return - 1 ;
return ( V_42 << 16 ) | ( V_15 & 0xffff ) ;
}
int F_23 ( struct V_1 * V_2 , struct V_1 * * V_43 )
{
return F_20 ( V_2 , V_43 , F_17 ) ;
}
int F_24 ( struct V_1 * V_2 , struct V_1 * * V_44 )
{
return F_20 ( V_2 , V_44 , F_22 ) ;
}
static int F_25 ( char * V_33 , int * V_45 )
{
T_1 V_46 ;
char * V_47 ;
int V_48 = 0 ;
if ( F_26 ( V_33 , & V_47 , & V_46 ) )
return - 1 ;
V_47 [ V_46 ] = '\0' ;
while ( -- V_46 ) {
if ( ( V_47 [ V_46 ] == ',' ) || ( V_47 [ V_46 ] == '-' ) ) {
V_46 ++ ;
break;
}
}
if ( sscanf ( & V_47 [ V_46 ] , L_12 , V_45 ) < 1 ) {
V_48 = - 1 ;
goto V_26;
}
( * V_45 ) ++ ;
V_26:
free ( V_47 ) ;
return V_48 ;
}
static void F_27 ( void )
{
const char * V_32 ;
char V_33 [ V_34 ] ;
int V_35 = - 1 ;
V_49 = 4096 ;
V_32 = F_18 () ;
if ( ! V_32 )
goto V_26;
V_35 = snprintf ( V_33 , V_34 , L_14 , V_32 ) ;
if ( V_35 == V_34 ) {
F_28 ( L_15 , V_34 ) ;
goto V_26;
}
V_35 = F_25 ( V_33 , & V_49 ) ;
V_26:
if ( V_35 )
F_28 ( L_16 , V_49 ) ;
}
static void F_29 ( void )
{
const char * V_32 ;
char V_33 [ V_34 ] ;
int V_35 = - 1 ;
V_50 = 8 ;
V_32 = F_18 () ;
if ( ! V_32 )
goto V_26;
V_35 = snprintf ( V_33 , V_34 , L_17 , V_32 ) ;
if ( V_35 == V_34 ) {
F_28 ( L_15 , V_34 ) ;
goto V_26;
}
V_35 = F_25 ( V_33 , & V_50 ) ;
V_26:
if ( V_35 )
F_28 ( L_18 , V_50 ) ;
}
static int F_30 ( void )
{
int V_5 ;
F_27 () ;
F_29 () ;
V_51 = calloc ( V_49 , sizeof( int ) ) ;
if ( ! V_51 ) {
F_28 ( L_19 , V_52 ) ;
return - 1 ;
}
for ( V_5 = 0 ; V_5 < V_49 ; V_5 ++ )
V_51 [ V_5 ] = - 1 ;
return 0 ;
}
int F_31 ( void )
{
struct V_53 * V_54 , * V_55 ;
T_3 * V_56 , * V_57 ;
unsigned int V_15 , V_58 ;
char V_47 [ V_34 ] ;
char V_33 [ V_34 ] ;
const char * V_32 ;
int V_14 ;
if ( F_30 () )
return - 1 ;
V_32 = F_18 () ;
if ( ! V_32 )
return 0 ;
V_14 = snprintf ( V_33 , V_34 , L_20 , V_32 ) ;
if ( V_14 == V_34 ) {
F_28 ( L_15 , V_34 ) ;
return - 1 ;
}
V_56 = F_32 ( V_33 ) ;
if ( ! V_56 )
return 0 ;
while ( ( V_54 = F_33 ( V_56 ) ) != NULL ) {
if ( V_54 -> V_59 != V_60 || sscanf ( V_54 -> V_61 , L_21 , & V_58 ) < 1 )
continue;
V_14 = snprintf ( V_47 , V_34 , L_22 , V_33 , V_54 -> V_61 ) ;
if ( V_14 == V_34 ) {
F_28 ( L_15 , V_34 ) ;
continue;
}
V_57 = F_32 ( V_47 ) ;
if ( ! V_57 )
continue;
while ( ( V_55 = F_33 ( V_57 ) ) != NULL ) {
if ( V_55 -> V_59 != V_62 || sscanf ( V_55 -> V_61 , L_23 , & V_15 ) < 1 )
continue;
V_51 [ V_15 ] = V_58 ;
}
F_34 ( V_57 ) ;
}
F_34 ( V_56 ) ;
return 0 ;
}
