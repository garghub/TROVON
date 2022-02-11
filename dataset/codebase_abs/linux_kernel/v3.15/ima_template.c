static int T_1 F_1 ( char * V_1 )
{
struct V_2 * V_3 ;
int V_4 = strlen ( V_1 ) ;
V_3 = F_2 ( V_1 ) ;
if ( ! V_3 )
return 1 ;
if ( V_4 == 3 && strcmp ( V_1 , V_5 ) == 0 &&
V_6 != V_7 && V_6 != V_8 ) {
F_3 ( L_1 ) ;
return 1 ;
}
V_9 = V_3 ;
return 1 ;
}
static struct V_2 * F_2 ( const char * V_10 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_4 ( V_12 ) ; V_11 ++ ) {
if ( strcmp ( V_12 [ V_11 ] . V_10 , V_10 ) == 0 )
return V_12 + V_11 ;
}
return NULL ;
}
static struct V_13 * F_5 ( const char * V_14 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_4 ( V_15 ) ; V_11 ++ )
if ( strncmp ( V_15 [ V_11 ] . V_14 , V_14 ,
V_16 ) == 0 )
return & V_15 [ V_11 ] ;
return NULL ;
}
static int F_6 ( const char * V_17 )
{
char V_18 ;
int V_19 = strlen ( V_17 ) ;
int V_11 = 0 , V_20 = 0 ;
while ( V_11 < V_19 ) {
V_18 = V_17 [ V_11 ] ;
if ( V_18 == '|' )
V_20 ++ ;
V_11 ++ ;
}
return V_20 + 1 ;
}
static int F_7 ( const char * V_17 ,
struct V_13 * * * V_21 ,
int * V_22 )
{
char * V_18 , * V_23 , * V_24 ;
int V_25 = F_6 ( V_17 ) ;
int V_11 , V_26 = 0 ;
if ( V_25 > V_27 )
return - V_28 ;
V_23 = F_8 ( V_17 , V_29 ) ;
if ( V_23 == NULL )
return - V_30 ;
* V_21 = F_9 ( V_25 * sizeof( * V_21 ) , V_29 ) ;
if ( * V_21 == NULL ) {
V_26 = - V_30 ;
goto V_31;
}
V_24 = V_23 ;
for ( V_11 = 0 ; ( V_18 = F_10 ( & V_24 , L_2 ) ) != NULL &&
V_11 < V_25 ; V_11 ++ ) {
struct V_13 * V_32 = F_5 ( V_18 ) ;
if ( ! V_32 ) {
V_26 = - V_33 ;
goto V_31;
}
( * V_21 ) [ V_11 ] = V_32 ;
}
* V_22 = V_11 ;
V_31:
if ( V_26 < 0 ) {
F_11 ( * V_21 ) ;
* V_21 = NULL ;
}
F_11 ( V_23 ) ;
return V_26 ;
}
static int F_12 ( void )
{
int V_11 = 0 ;
int V_26 = 0 ;
for ( V_11 = 0 ; V_11 < F_4 ( V_12 ) ; V_11 ++ ) {
struct V_2 * V_34 = & V_12 [ V_11 ] ;
V_26 = F_7 ( V_34 -> V_35 ,
& ( V_34 -> V_21 ) ,
& ( V_34 -> V_22 ) ) ;
if ( V_26 < 0 )
return V_26 ;
}
return V_26 ;
}
struct V_2 * F_13 ( void )
{
if ( ! V_9 )
V_9 =
F_2 ( V_36 ) ;
return V_9 ;
}
int F_14 ( void )
{
int V_26 ;
V_26 = F_12 () ;
if ( V_26 < 0 )
return V_26 ;
return 0 ;
}
