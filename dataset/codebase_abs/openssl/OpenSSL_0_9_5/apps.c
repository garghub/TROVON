int F_1 ( char * V_1 , int * V_2 , char * * V_3 [] )
{
T_1 * V_4 ;
int V_5 , V_6 ;
unsigned int V_7 ;
static char * V_8 = NULL ;
static char * * V_9 = NULL ;
char * V_10 ;
struct V_11 V_12 ;
if ( V_11 ( V_1 , & V_12 ) < 0 ) return ( 0 ) ;
V_4 = fopen ( V_1 , L_1 ) ;
if ( V_4 == NULL )
return ( 0 ) ;
* V_2 = 0 ;
* V_3 = NULL ;
V_7 = ( unsigned int ) V_12 . V_13 ;
if ( V_8 != NULL ) Free ( V_8 ) ;
V_8 = ( char * ) Malloc ( V_7 + 1 ) ;
if ( V_8 == NULL ) return ( 0 ) ;
V_7 = fread ( V_8 , 1 , V_7 , V_4 ) ;
if ( V_7 <= 1 ) return ( 0 ) ;
V_8 [ V_7 ] = '\0' ;
V_6 = 0 ;
for ( V_10 = V_8 ; * V_10 ; V_10 ++ )
if ( * V_10 == '\n' ) V_6 ++ ;
if ( V_9 != NULL ) Free ( V_9 ) ;
V_9 = ( char * * ) Malloc ( sizeof( char * ) * ( V_6 * 2 ) ) ;
* V_3 = V_9 ;
V_5 = 0 ;
V_10 = V_8 ;
for (; ; )
{
if ( ! * V_10 ) break;
if ( * V_10 == '#' )
{
while ( * V_10 && ( * V_10 != '\n' ) ) V_10 ++ ;
continue;
}
* ( V_9 ++ ) = V_10 ;
V_5 ++ ;
while ( * V_10 && ( ( * V_10 != ' ' ) && ( * V_10 != '\t' ) && ( * V_10 != '\n' ) ) )
V_10 ++ ;
if ( ! * V_10 ) break;
if ( * V_10 == '\n' )
{
* ( V_10 ++ ) = '\0' ;
continue;
}
V_10 ++ ;
while ( * V_10 && ( ( * V_10 == ' ' ) || ( * V_10 == '\t' ) || ( * V_10 == '\n' ) ) )
V_10 ++ ;
if ( ! * V_10 ) break;
if ( * V_10 == '\n' )
{
V_10 ++ ;
continue;
}
* ( V_9 ++ ) = V_10 ++ ;
V_5 ++ ;
while ( * V_10 && ( * V_10 != '\n' ) ) V_10 ++ ;
if ( ! * V_10 ) break;
* ( V_10 ++ ) = '\0' ;
}
* V_2 = V_5 ;
return ( 1 ) ;
}
int F_2 ( char * V_14 )
{
if ( ( * V_14 == 'D' ) || ( * V_14 == 'd' ) )
return ( V_15 ) ;
else if ( ( * V_14 == 'T' ) || ( * V_14 == 't' ) )
return ( V_16 ) ;
else if ( ( * V_14 == 'P' ) || ( * V_14 == 'p' ) )
return ( V_17 ) ;
else if ( ( * V_14 == 'N' ) || ( * V_14 == 'n' ) )
return ( V_18 ) ;
else
return ( V_19 ) ;
}
void F_3 ( char * V_20 , char * V_21 , int V_22 )
{
int V_6 , V_23 ;
char * V_10 = NULL ;
V_23 = strlen ( V_20 ) ;
for ( V_6 = V_23 - 1 ; V_6 > 0 ; V_6 -- )
{
if ( ( V_20 [ V_6 ] == '/' ) || ( V_20 [ V_6 ] == '\\' ) || ( V_20 [ V_6 ] == ':' ) )
{
V_10 = & ( V_20 [ V_6 + 1 ] ) ;
break;
}
}
if ( V_10 == NULL )
V_10 = V_20 ;
V_23 = strlen ( V_10 ) ;
if ( ( V_23 > 4 ) && ( V_10 [ V_23 - 4 ] == '.' ) &&
( ( V_10 [ V_23 - 3 ] == 'e' ) || ( V_10 [ V_23 - 3 ] == 'E' ) ) &&
( ( V_10 [ V_23 - 2 ] == 'x' ) || ( V_10 [ V_23 - 2 ] == 'X' ) ) &&
( ( V_10 [ V_23 - 1 ] == 'e' ) || ( V_10 [ V_23 - 1 ] == 'E' ) ) )
V_23 -= 4 ;
if ( V_23 > V_22 - 1 )
V_23 = V_22 - 1 ;
for ( V_6 = 0 ; V_6 < V_23 ; V_6 ++ )
{
if ( ( V_10 [ V_6 ] >= 'A' ) && ( V_10 [ V_6 ] <= 'Z' ) )
V_21 [ V_6 ] = V_10 [ V_6 ] - 'A' + 'a' ;
else
V_21 [ V_6 ] = V_10 [ V_6 ] ;
}
V_21 [ V_23 ] = '\0' ;
}
void F_3 ( char * V_20 , char * V_21 , int V_22 )
{
char * V_10 = V_20 , * V_24 ;
char * V_25 = L_2 ;
while( * V_25 != '\0' )
{
V_24 = strrchr ( V_10 , * V_25 ) ;
if ( V_24 > V_10 )
V_10 = V_24 + 1 ;
V_25 ++ ;
}
V_24 = strrchr ( V_10 , '.' ) ;
if ( V_24 == NULL )
V_24 = V_20 + V_22 ;
strncpy ( V_21 , V_10 , V_24 - V_10 ) ;
V_21 [ V_24 - V_10 ] = '\0' ;
}
void F_3 ( char * V_20 , char * V_21 , int V_22 )
{
char * V_10 ;
V_10 = strrchr ( V_20 , '/' ) ;
if ( V_10 != NULL )
V_10 ++ ;
else
V_10 = V_20 ;
strncpy ( V_21 , V_10 , V_22 - 1 ) ;
V_21 [ V_22 - 1 ] = '\0' ;
}
int F_4 ( char * V_26 , char * V_27 )
{
#ifdef F_5
int V_28 ;
V_28 = F_6 ( V_26 , V_27 , V_29 | V_30 ) ;
return ( V_28 ? 0 : - 1 ) ;
#else
F_7 ( V_27 ) ;
return F_8 ( V_26 , V_27 ) ;
#endif
}
int F_9 ( ARGS * V_9 , char * V_8 , int * V_2 , char * * V_3 [] )
{
int V_5 , V_7 , V_6 ;
char * V_10 ;
* V_2 = 0 ;
* V_3 = NULL ;
V_7 = strlen ( V_8 ) ;
V_6 = 0 ;
if ( V_9 -> V_31 == 0 )
{
V_9 -> V_31 = 20 ;
V_9 -> V_32 = ( char * * ) Malloc ( sizeof( char * ) * V_9 -> V_31 ) ;
}
for ( V_6 = 0 ; V_6 < V_9 -> V_31 ; V_6 ++ )
V_9 -> V_32 [ V_6 ] = NULL ;
V_5 = 0 ;
V_10 = V_8 ;
for (; ; )
{
if ( ! * V_10 ) break;
while ( * V_10 && ( ( * V_10 == ' ' ) || ( * V_10 == '\t' ) || ( * V_10 == '\n' ) ) )
V_10 ++ ;
if ( ! * V_10 ) break;
if ( V_5 >= V_9 -> V_31 )
{
V_9 -> V_31 += 20 ;
V_9 -> V_32 = ( char * * ) Realloc ( V_9 -> V_32 ,
sizeof( char * ) * V_9 -> V_31 ) ;
if ( V_2 == 0 ) return ( 0 ) ;
}
V_9 -> V_32 [ V_5 ++ ] = V_10 ;
if ( ( * V_10 == '\'' ) || ( * V_10 == '\"' ) )
{
V_6 = * ( V_10 ++ ) ;
V_9 -> V_32 [ V_5 - 1 ] ++ ;
while ( * V_10 && ( * V_10 != V_6 ) )
V_10 ++ ;
* V_10 = '\0' ;
}
else
{
while ( * V_10 && ( ( * V_10 != ' ' ) &&
( * V_10 != '\t' ) && ( * V_10 != '\n' ) ) )
V_10 ++ ;
if ( * V_10 == '\0' )
V_10 -- ;
else
* V_10 = '\0' ;
}
V_10 ++ ;
}
* V_2 = V_5 ;
* V_3 = V_9 -> V_32 ;
return ( 1 ) ;
}
int F_10 ( long V_33 )
{
return ( 1 ) ;
}
int F_11 ( T_2 * V_21 , T_3 * V_34 )
{
char V_8 [ 256 ] ;
F_12 ( F_13 ( V_34 ) , V_8 , 256 ) ;
F_14 ( V_21 , L_3 ) ;
F_14 ( V_21 , V_8 ) ;
F_12 ( F_15 ( V_34 ) , V_8 , 256 ) ;
F_14 ( V_21 , L_4 ) ;
F_14 ( V_21 , V_8 ) ;
F_14 ( V_21 , L_5 ) ;
return 0 ;
}
int F_16 ( T_2 * V_35 , char * V_36 , char * V_37 , char * * V_38 , char * * V_39 )
{
int V_40 ;
if( ! V_37 || ! V_36 || strcmp ( V_36 , V_37 ) ) V_40 = 0 ;
else V_40 = 1 ;
if( V_36 ) {
* V_38 = F_17 ( V_35 , V_36 , V_40 ) ;
if( ! * V_38 ) return 0 ;
} else if( V_38 ) * V_38 = NULL ;
if( V_37 ) {
* V_39 = F_17 ( V_35 , V_37 , V_40 ? 2 : 0 ) ;
if( ! * V_39 ) return 0 ;
} else if( V_39 ) * V_39 = NULL ;
return 1 ;
}
static char * F_17 ( T_2 * V_35 , char * V_9 , int V_41 )
{
char * V_42 , V_43 [ V_44 ] ;
static T_2 * V_45 = NULL ;
int V_6 ;
if( ! strncmp ( V_9 , L_6 , 5 ) ) return F_18 ( V_9 + 5 ) ;
if( ! strncmp ( V_9 , L_7 , 4 ) ) {
V_42 = getenv ( V_9 + 4 ) ;
if( ! V_42 ) {
F_19 ( V_35 , L_8 , V_9 + 4 ) ;
return NULL ;
}
return F_18 ( V_42 ) ;
}
if( ! V_41 || ! V_45 ) {
if( ! strncmp ( V_9 , L_9 , 5 ) ) {
V_45 = F_20 ( V_9 + 5 , L_1 ) ;
if( ! V_45 ) {
F_19 ( V_35 , L_10 , V_9 + 5 ) ;
return NULL ;
}
} else if( ! strncmp ( V_9 , L_11 , 3 ) ) {
T_2 * V_46 ;
V_6 = atoi ( V_9 + 3 ) ;
if( V_6 >= 0 ) V_45 = F_21 ( V_6 , V_47 ) ;
if( ( V_6 < 0 ) || ! V_45 ) {
F_19 ( V_35 , L_12 , V_9 + 3 ) ;
return NULL ;
}
V_46 = F_22 ( F_23 () ) ;
V_45 = F_24 ( V_46 , V_45 ) ;
} else if( ! strcmp ( V_9 , L_13 ) ) {
V_45 = F_25 ( V_48 , V_47 ) ;
if( ! V_45 ) {
F_19 ( V_35 , L_14 ) ;
return NULL ;
}
} else {
F_19 ( V_35 , L_15 , V_9 ) ;
return NULL ;
}
}
V_6 = F_26 ( V_45 , V_43 , V_44 ) ;
if( V_41 != 1 ) {
F_27 ( V_45 ) ;
V_45 = NULL ;
}
if( V_6 <= 0 ) {
F_19 ( V_35 , L_16 ) ;
return NULL ;
}
V_42 = strchr ( V_43 , '\n' ) ;
if( V_42 ) * V_42 = 0 ;
return F_18 ( V_43 ) ;
}
