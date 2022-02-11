int F_1 ( int V_1 , const char * * V_2 , const char * T_1 V_3 )
{
int V_4 ;
bool V_5 = false ;
struct V_6 V_7 [] = {
F_2 ( 0 , L_1 , & V_5 , L_2 ) ,
F_3 ()
} ;
const char * const V_8 [] = {
L_3 ,
NULL
} ;
F_4 ( V_7 , 0 , L_1 , V_9 ) ;
V_1 = F_5 ( V_1 , V_2 , V_7 , V_8 ,
V_10 ) ;
F_6 () ;
if ( V_5 ) {
F_7 ( NULL , true ) ;
return 0 ;
}
if ( V_1 == 0 ) {
F_7 ( NULL , false ) ;
return 0 ;
}
for ( V_4 = 0 ; V_4 < V_1 ; ++ V_4 ) {
if ( V_4 )
putchar ( '\n' ) ;
if ( strncmp ( V_2 [ V_4 ] , L_4 , 10 ) == 0 )
F_8 ( NULL , NULL , false ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_5 ) == 0 ||
strcmp ( V_2 [ V_4 ] , L_6 ) == 0 )
F_9 ( V_11 ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_7 ) == 0 ||
strcmp ( V_2 [ V_4 ] , L_8 ) == 0 )
F_9 ( V_12 ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_9 ) == 0 ||
strcmp ( V_2 [ V_4 ] , L_10 ) == 0 )
F_10 ( NULL , false ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_11 ) == 0 )
F_11 ( NULL , false ) ;
else {
char * V_13 = strchr ( V_2 [ V_4 ] , ':' ) , * V_14 ;
int V_15 ;
if ( V_13 == NULL ) {
F_7 ( V_2 [ V_4 ] , false ) ;
continue;
}
V_15 = V_13 - V_2 [ V_4 ] ;
V_14 = F_12 ( V_2 [ V_4 ] ) ;
if ( V_14 == NULL )
return - 1 ;
V_14 [ V_15 ] = '\0' ;
F_8 ( V_14 , V_14 + V_15 + 1 , false ) ;
free ( V_14 ) ;
}
}
return 0 ;
}
