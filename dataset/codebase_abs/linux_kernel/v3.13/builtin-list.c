int F_1 ( int V_1 , const char * * V_2 , const char * T_1 V_3 )
{
int V_4 ;
const struct V_5 V_6 [] = {
F_2 ()
} ;
const char * const V_7 [] = {
L_1 ,
NULL
} ;
V_1 = F_3 ( V_1 , V_2 , V_6 , V_7 ,
V_8 ) ;
F_4 () ;
if ( V_1 == 0 ) {
F_5 ( NULL , false ) ;
return 0 ;
}
for ( V_4 = 0 ; V_4 < V_1 ; ++ V_4 ) {
if ( V_4 )
putchar ( '\n' ) ;
if ( strncmp ( V_2 [ V_4 ] , L_2 , 10 ) == 0 )
F_6 ( NULL , NULL , false ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_3 ) == 0 ||
strcmp ( V_2 [ V_4 ] , L_4 ) == 0 )
F_7 ( V_9 ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_5 ) == 0 ||
strcmp ( V_2 [ V_4 ] , L_6 ) == 0 )
F_7 ( V_10 ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_7 ) == 0 ||
strcmp ( V_2 [ V_4 ] , L_8 ) == 0 )
F_8 ( NULL , false ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_9 ) == 0 )
F_9 ( NULL , false ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_10 ) == 0 )
F_5 ( NULL , true ) ;
else {
char * V_11 = strchr ( V_2 [ V_4 ] , ':' ) , * V_12 ;
int V_13 ;
if ( V_11 == NULL ) {
F_5 ( V_2 [ V_4 ] , false ) ;
continue;
}
V_13 = V_11 - V_2 [ V_4 ] ;
V_12 = F_10 ( V_2 [ V_4 ] ) ;
if ( V_12 == NULL )
return - 1 ;
V_12 [ V_13 ] = '\0' ;
F_6 ( V_12 , V_12 + V_13 + 1 , false ) ;
free ( V_12 ) ;
}
}
return 0 ;
}
