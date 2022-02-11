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
if ( ! V_5 && F_7 () )
printf ( L_4 ) ;
if ( V_1 == 0 ) {
F_8 ( NULL , V_5 ) ;
return 0 ;
}
for ( V_4 = 0 ; V_4 < V_1 ; ++ V_4 ) {
char * V_11 , * V_12 ;
if ( strcmp ( V_2 [ V_4 ] , L_5 ) == 0 )
F_9 ( NULL , NULL , V_5 ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_6 ) == 0 ||
strcmp ( V_2 [ V_4 ] , L_7 ) == 0 )
F_10 ( NULL , V_13 ,
V_14 , V_15 , V_5 ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_8 ) == 0 ||
strcmp ( V_2 [ V_4 ] , L_9 ) == 0 )
F_10 ( NULL , V_16 ,
V_17 , V_18 , V_5 ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_10 ) == 0 ||
strcmp ( V_2 [ V_4 ] , L_11 ) == 0 )
F_11 ( NULL , V_5 ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_12 ) == 0 )
F_12 ( NULL , V_5 ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_13 ) == 0 )
F_13 ( NULL , NULL , V_5 ) ;
else if ( ( V_11 = strchr ( V_2 [ V_4 ] , ':' ) ) != NULL ) {
int V_19 ;
if ( V_11 == NULL ) {
F_8 ( V_2 [ V_4 ] , V_5 ) ;
continue;
}
V_19 = V_11 - V_2 [ V_4 ] ;
V_12 = F_14 ( V_2 [ V_4 ] ) ;
if ( V_12 == NULL )
return - 1 ;
V_12 [ V_19 ] = '\0' ;
F_9 ( V_12 , V_12 + V_19 + 1 , V_5 ) ;
F_13 ( V_12 , V_12 + V_19 + 1 , V_5 ) ;
free ( V_12 ) ;
} else {
if ( F_15 ( & V_12 , L_14 , V_2 [ V_4 ] ) < 0 ) {
printf ( L_15 ) ;
continue;
}
F_10 ( V_12 , V_13 ,
V_14 , V_15 , V_5 ) ;
F_10 ( V_12 , V_16 ,
V_17 , V_18 , V_5 ) ;
F_11 ( V_12 , V_5 ) ;
F_12 ( V_12 , V_5 ) ;
F_9 ( NULL , V_12 , V_5 ) ;
F_13 ( NULL , V_12 , V_5 ) ;
free ( V_12 ) ;
}
}
return 0 ;
}
