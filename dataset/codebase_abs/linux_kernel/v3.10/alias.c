static int F_1 ( const char * V_1 , const char * V_2 ,
void * T_1 V_3 )
{
if ( ! F_2 ( V_1 , L_1 ) && ! strcmp ( V_1 + 6 , V_4 ) ) {
if ( ! V_2 )
return F_3 ( V_1 ) ;
V_5 = F_4 ( V_2 ) ;
return 0 ;
}
return 0 ;
}
char * F_5 ( const char * V_6 )
{
V_4 = V_6 ;
V_5 = NULL ;
F_6 ( F_1 , NULL ) ;
return V_5 ;
}
int F_7 ( char * V_7 , const char * * * V_8 )
{
int V_9 , V_10 , V_11 = 0 , V_12 = 16 ;
char V_13 = 0 ;
* V_8 = malloc ( sizeof( char * ) * V_12 ) ;
( * V_8 ) [ V_11 ++ ] = V_7 ;
for ( V_9 = V_10 = 0 ; V_7 [ V_9 ] ; ) {
char V_14 = V_7 [ V_9 ] ;
if ( ! V_13 && isspace ( V_14 ) ) {
V_7 [ V_10 ++ ] = 0 ;
while ( V_7 [ ++ V_9 ]
&& isspace ( V_7 [ V_9 ] ) )
;
if ( V_11 >= V_12 ) {
V_12 += 16 ;
* V_8 = realloc ( * V_8 , sizeof( char * ) * V_12 ) ;
}
( * V_8 ) [ V_11 ++ ] = V_7 + V_10 ;
} else if ( ! V_13 && ( V_14 == '\'' || V_14 == '"' ) ) {
V_13 = V_14 ;
V_9 ++ ;
} else if ( V_14 == V_13 ) {
V_13 = 0 ;
V_9 ++ ;
} else {
if ( V_14 == '\\' && V_13 != '\'' ) {
V_9 ++ ;
V_14 = V_7 [ V_9 ] ;
if ( ! V_14 ) {
free ( * V_8 ) ;
* V_8 = NULL ;
return error ( L_2 ) ;
}
}
V_7 [ V_10 ++ ] = V_14 ;
V_9 ++ ;
}
}
V_7 [ V_10 ] = 0 ;
if ( V_13 ) {
free ( * V_8 ) ;
* V_8 = NULL ;
return error ( L_3 ) ;
}
return V_11 ;
}
