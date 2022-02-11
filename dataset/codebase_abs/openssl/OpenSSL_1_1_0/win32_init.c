static void F_1 ( void )
{
int V_1 ;
F_2 ( V_2 ) ;
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ )
free ( V_4 [ V_1 ] ) ;
free ( V_4 ) ;
}
static int F_3 ( int V_5 )
{
static int V_6 = 0 ;
if ( V_5 >= V_6 ) {
char * * V_7 ;
while ( V_5 >= V_6 )
V_6 += 64 ;
V_7 = realloc ( V_4 , V_6 * sizeof( V_4 [ 0 ] ) ) ;
if ( V_7 == NULL )
return 0 ;
( V_4 = V_7 ) [ V_5 ] = NULL ;
} else {
V_4 [ V_5 ] = NULL ;
}
return 1 ;
}
static int F_4 ( T_1 * V_8 , int V_9 )
{
int V_1 , V_10 , V_11 ;
T_1 V_12 ;
T_2 V_13 ;
T_3 V_14 ;
for ( V_10 = 0 , V_1 = 0 ; V_1 < V_9 ; V_1 ++ )
if ( V_8 [ V_1 ] == V_15 '/' || V_8 [ V_1 ] == V_15 '\\' )
V_10 = V_1 + 1 ;
for ( V_1 = V_10 ; V_1 < V_9 ; V_1 ++ )
if ( V_8 [ V_1 ] == V_15 '*' || V_8 [ V_1 ] == V_15 '?' )
break;
if ( V_1 == V_9 )
return 0 ;
V_12 = V_8 [ V_9 ] ;
V_8 [ V_9 ] = V_15 '\0' ;
V_14 = F_5 ( V_8 , & V_13 ) ;
V_8 [ V_9 ] = V_12 ;
if ( V_14 == V_16 )
return 0 ;
if ( V_10 )
V_11 = F_6 ( V_17 , 0 , V_8 , V_10 ,
NULL , 0 , NULL , NULL ) ;
else
V_11 = 0 ;
do {
int V_18 ;
char * V_19 ;
if ( V_13 . V_20 [ 0 ] == V_15 '.' ) {
if ( ( V_13 . V_20 [ 1 ] == V_15 '\0' ) ||
( V_13 . V_20 [ 1 ] == V_15 '.' && V_13 . V_20 [ 2 ] == V_15 '\0' ) )
continue;
}
if ( ! F_3 ( V_3 + 1 ) )
break;
V_18 = F_6 ( V_17 , 0 , V_13 . V_20 , - 1 ,
NULL , 0 , NULL , NULL ) ;
V_19 = malloc ( V_11 + V_18 ) ;
if ( V_19 == NULL )
break;
if ( V_11 )
F_6 ( V_17 , 0 , V_8 , V_10 ,
V_19 , V_11 , NULL , NULL ) ;
F_6 ( V_17 , 0 , V_13 . V_20 , - 1 ,
V_19 + V_11 , V_18 , NULL , NULL ) ;
V_4 [ V_3 ++ ] = V_19 ;
} while ( F_7 ( V_14 , & V_13 ) );
F_8 ( V_14 ) ;
return 1 ;
}
void F_9 ( int * V_5 , char * * V_21 [] )
{
const T_1 * V_22 ;
T_1 * V_23 , * V_24 , * V_25 ;
int V_9 , V_26 , V_27 = 1 ;
char * V_19 ;
if ( F_10 ( L_1 , NULL , 0 ) == 0 )
return;
V_3 = 0 ;
V_4 = NULL ;
if ( ! F_3 ( V_3 ) )
return;
V_22 = F_11 () ;
if ( V_22 == NULL ) return;
V_9 = wcslen ( V_22 ) ;
V_25 = F_12 ( ( V_9 + 1 ) * sizeof( T_1 ) ) ;
wcscpy ( V_25 , V_22 ) ;
while ( * V_25 != V_15 '\0' ) {
int V_28 = 0 ;
if ( * V_25 == V_15 ' ' || * V_25 == V_15 '\t' ) {
V_25 ++ ;
continue;
}
V_23 = V_24 = V_25 ;
while ( * V_25 != V_15 '\0'
&& ( V_28 || ( * V_25 != V_15 ' ' && * V_25 != V_15 '\t' ) ) ) {
switch ( * V_25 ) {
case V_15 '\\' :
{
const T_1 * V_29 = V_25 ;
int V_1 ;
while ( * V_25 == V_15 '\\' )
V_25 ++ ;
if ( * V_25 == V_15 '"' ) {
int V_1 ;
for ( V_1 = ( V_25 - V_29 ) / 2 ; V_1 > 0 ; V_1 -- )
* V_24 ++ = V_15 '\\' ;
if ( ( V_25 - V_29 ) % 2 == 1 )
* V_24 ++ = * V_25 ++ ;
} else {
for ( V_1 = V_25 - V_29 ; V_1 > 0 ; V_1 -- )
* V_24 ++ = V_15 '\\' ;
}
}
break;
case V_15 '"' :
if ( V_28 && V_25 [ 1 ] == V_15 '"' )
* V_24 ++ = * V_25 ++ ;
else
V_28 = ! V_28 ;
V_25 ++ ;
break;
default:
* V_24 ++ = * V_25 ++ ;
}
}
V_9 = V_24 - V_23 ;
if ( V_9 == 0 || ! F_4 ( V_23 , V_9 ) ) {
if ( ! F_3 ( V_3 + 1 ) ) {
V_27 = 0 ;
break;
}
V_26 = 0 ;
if ( V_9 > 0 ) {
V_26 = F_6 ( V_17 , 0 , V_23 , V_9 ,
NULL , 0 , NULL , NULL ) ;
if ( V_26 <= 0 )
continue;
}
V_19 = malloc ( V_26 + 1 ) ;
if ( V_19 == NULL ) {
V_27 = 0 ;
break;
}
if ( V_9 > 0 )
F_6 ( V_17 , 0 , V_23 , V_9 ,
V_19 , V_26 , NULL , NULL ) ;
V_19 [ V_26 ] = '\0' ;
V_4 [ V_3 ++ ] = V_19 ;
}
}
if ( V_27 ) {
V_2 = F_13 () ;
F_2 ( V_17 ) ;
* V_5 = V_3 ;
* V_21 = V_4 ;
atexit ( F_1 ) ;
} else if ( V_4 != NULL ) {
int V_1 ;
for ( V_1 = 0 ; V_1 < V_3 ; V_1 ++ )
free ( V_4 [ V_1 ] ) ;
free ( V_4 ) ;
V_3 = 0 ;
V_4 = NULL ;
}
return;
}
void F_9 ( int & V_5 , char * * V_21 [] )
{ return; }
