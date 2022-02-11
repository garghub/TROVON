void * F_1 ( char * V_1 ,
char * V_2 , char V_3 )
{
struct V_4 * V_5 ;
T_1 * V_6 ;
V_5 = calloc ( 1 , sizeof( struct V_4 ) ) ;
if ( ! V_5 ) {
return ( NULL ) ;
}
V_6 = F_2 ( V_1 ) ;
if ( ! V_6 ) {
fprintf ( V_7 , L_1 , V_1 ) ;
free ( V_5 ) ;
return ( NULL ) ;
}
V_5 -> V_2 = V_2 ;
V_5 -> V_3 = V_3 ;
V_5 -> V_1 = V_1 ;
V_5 -> V_8 = V_6 ;
return ( V_5 ) ;
}
char * F_3 ( void * V_9 )
{
struct V_4 * V_5 = V_9 ;
struct V_10 * V_11 ;
char * V_12 ;
int V_13 ;
struct V_14 V_15 ;
int V_16 ;
while ( ( V_11 = F_4 ( V_5 -> V_8 ) ) ) {
if ( ! F_5
( V_5 -> V_2 , V_11 -> V_17 , 0 ) ) {
if ( V_11 -> V_17 [ 0 ] == '.' ) {
continue;
}
V_13 = strlen ( V_11 -> V_17 ) +
strlen ( V_5 -> V_1 ) + 2 ;
V_12 = calloc ( V_13 , 1 ) ;
if ( ! V_12 ) {
fprintf ( V_7 ,
L_2 ) ;
return ( NULL ) ;
}
strcpy ( V_12 , V_5 -> V_1 ) ;
strcat ( V_12 , L_3 ) ;
strcat ( V_12 , V_11 -> V_17 ) ;
V_16 = V_14 ( V_12 , & V_15 ) ;
if ( V_16 == - 1 ) {
fprintf ( V_7 ,
L_4 ,
V_12 ) ;
free ( V_12 ) ;
return ( NULL ) ;
}
free ( V_12 ) ;
if ( ( F_6 ( V_15 . V_18 )
&& ( V_5 -> V_3 ==
V_19 ) )
|| ( ( ! F_6 ( V_15 . V_18 )
&& V_5 -> V_3 ==
V_20 ) ) ) {
strcpy ( V_5 -> V_21 ,
V_11 -> V_17 ) ;
return ( V_5 -> V_21 ) ;
}
}
}
return ( NULL ) ;
}
void F_7 ( void * V_9 )
{
struct V_4 * V_5 = V_9 ;
F_8 ( V_5 -> V_8 ) ;
free ( V_9 ) ;
}
