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
