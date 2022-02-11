static int T_1 F_1 ( char * V_1 )
{
struct V_2 * V_3 ;
int V_4 = strlen ( V_1 ) ;
if ( V_5 )
return 1 ;
V_3 = F_2 ( V_1 ) ;
if ( ! V_3 ) {
F_3 ( L_1 ,
V_1 , V_6 ) ;
return 1 ;
}
if ( V_4 == 3 && strcmp ( V_1 , V_7 ) == 0 &&
V_8 != V_9 && V_8 != V_10 ) {
F_3 ( L_2 ) ;
return 1 ;
}
V_5 = V_3 ;
return 1 ;
}
static int T_1 F_4 ( char * V_1 )
{
int V_11 = F_5 ( V_12 ) ;
if ( V_5 )
return 1 ;
if ( F_6 ( V_1 , NULL , NULL ) < 0 ) {
F_3 ( L_3 ,
V_1 , V_6 ) ;
return 1 ;
}
V_12 [ V_11 - 1 ] . V_13 = V_1 ;
V_5 = V_12 + V_11 - 1 ;
return 1 ;
}
static struct V_2 * F_2 ( const char * V_14 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < F_5 ( V_12 ) ; V_15 ++ ) {
if ( strcmp ( V_12 [ V_15 ] . V_14 , V_14 ) == 0 )
return V_12 + V_15 ;
}
return NULL ;
}
static struct V_16 * F_7 ( const char * V_17 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < F_5 ( V_18 ) ; V_15 ++ )
if ( strncmp ( V_18 [ V_15 ] . V_17 , V_17 ,
V_19 ) == 0 )
return & V_18 [ V_15 ] ;
return NULL ;
}
static int F_8 ( const char * V_20 )
{
char V_21 ;
int V_22 = strlen ( V_20 ) ;
int V_15 = 0 , V_23 = 0 ;
while ( V_15 < V_22 ) {
V_21 = V_20 [ V_15 ] ;
if ( V_21 == '|' )
V_23 ++ ;
V_15 ++ ;
}
return V_23 + 1 ;
}
static int F_6 ( const char * V_20 ,
struct V_16 * * * V_24 ,
int * V_25 )
{
const char * V_26 ;
struct V_16 * V_27 [ V_28 ] ;
int V_29 = F_8 ( V_20 ) ;
int V_15 , V_30 ;
if ( V_29 > V_28 ) {
F_3 ( L_4 ,
V_20 ) ;
return - V_31 ;
}
for ( V_15 = 0 , V_26 = V_20 ; V_15 < V_29 ;
V_15 ++ , V_26 += V_30 + 1 ) {
char V_32 [ V_19 + 1 ] ;
V_30 = F_9 ( V_26 , '|' ) - V_26 ;
if ( V_30 == 0 || V_30 > V_19 ) {
F_3 ( L_5 , V_30 ) ;
return - V_31 ;
}
memcpy ( V_32 , V_26 , V_30 ) ;
V_32 [ V_30 ] = '\0' ;
V_27 [ V_15 ] = F_7 ( V_32 ) ;
if ( ! V_27 [ V_15 ] ) {
F_3 ( L_6 , V_32 ) ;
return - V_33 ;
}
}
if ( V_24 && V_25 ) {
* V_24 = F_10 ( V_15 , sizeof( * V_24 ) , V_34 ) ;
if ( * V_24 == NULL )
return - V_35 ;
memcpy ( * V_24 , V_27 , V_15 * sizeof( * V_24 ) ) ;
* V_25 = V_15 ;
}
return 0 ;
}
struct V_2 * F_11 ( void )
{
if ( ! V_5 )
V_5 =
F_2 ( V_6 ) ;
return V_5 ;
}
int T_1 F_12 ( void )
{
struct V_2 * V_36 = F_11 () ;
int V_37 ;
V_37 = F_6 ( V_36 -> V_13 ,
& ( V_36 -> V_24 ) ,
& ( V_36 -> V_25 ) ) ;
if ( V_37 < 0 )
F_3 ( L_7 ,
( strlen ( V_36 -> V_14 ) ?
V_36 -> V_14 : V_36 -> V_13 ) , V_37 ) ;
return V_37 ;
}
