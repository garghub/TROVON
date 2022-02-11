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
static struct V_1 * F_4 ( void )
{
struct V_1 * V_2 = NULL ;
T_2 * V_10 ;
int V_3 = 0 ;
int * V_8 = NULL , * V_11 ;
int V_12 = 0 ;
int V_13 , V_14 , V_15 ;
char V_16 ;
V_10 = fopen ( L_1 , L_2 ) ;
if ( ! V_10 )
return F_1 () ;
V_16 = 0 ;
V_15 = - 1 ;
for (; ; ) {
V_13 = fscanf ( V_10 , L_3 , & V_14 , & V_16 ) ;
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
fclose ( V_10 ) ;
return V_2 ;
}
struct V_1 * F_5 ( const char * V_20 )
{
struct V_1 * V_2 = NULL ;
unsigned long V_21 , V_22 = 0 ;
char * V_23 = NULL ;
int V_5 , V_3 = 0 ;
int * V_8 = NULL , * V_11 ;
int V_12 = 0 ;
if ( ! V_20 )
return F_4 () ;
if ( ! isdigit ( * V_20 ) )
goto V_24;
while ( isdigit ( * V_20 ) ) {
V_23 = NULL ;
V_21 = strtoul ( V_20 , & V_23 , 0 ) ;
if ( V_21 >= V_25
|| ( * V_23 != '\0' && * V_23 != ',' && * V_23 != '-' ) )
goto V_26;
if ( * V_23 == '-' ) {
V_20 = ++ V_23 ;
V_23 = NULL ;
V_22 = strtoul ( V_20 , & V_23 , 0 ) ;
if ( V_22 >= V_25 || ( * V_23 != '\0' && * V_23 != ',' ) )
goto V_26;
if ( V_22 < V_21 )
goto V_26;
} else {
V_22 = V_21 ;
}
for (; V_21 <= V_22 ; V_21 ++ ) {
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ )
if ( V_8 [ V_5 ] == ( int ) V_21 )
goto V_26;
if ( V_3 == V_12 ) {
V_12 += V_18 ;
V_11 = realloc ( V_8 , V_12 * sizeof( int ) ) ;
if ( V_11 == NULL )
goto V_26;
V_8 = V_11 ;
}
V_8 [ V_3 ++ ] = ( int ) V_21 ;
}
if ( * V_23 )
++ V_23 ;
V_20 = V_23 ;
}
if ( V_3 > 0 )
V_2 = F_3 ( V_3 , V_8 ) ;
else
V_2 = F_1 () ;
V_26:
free ( V_8 ) ;
V_24:
return V_2 ;
}
struct V_1 * F_6 ( void )
{
struct V_1 * V_2 = malloc ( sizeof( * V_2 ) + sizeof( int ) ) ;
if ( V_2 != NULL ) {
V_2 -> V_7 = 1 ;
V_2 -> V_6 [ 0 ] = - 1 ;
}
return V_2 ;
}
void F_7 ( struct V_1 * V_6 )
{
free ( V_6 ) ;
}
