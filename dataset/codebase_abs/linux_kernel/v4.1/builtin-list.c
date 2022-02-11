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
if ( ! V_5 )
printf ( L_4 ) ;
if ( V_1 == 0 ) {
F_7 ( NULL , V_5 ) ;
return 0 ;
}
for ( V_4 = 0 ; V_4 < V_1 ; ++ V_4 ) {
if ( strcmp ( V_2 [ V_4 ] , L_5 ) == 0 )
F_8 ( NULL , NULL , V_5 ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_6 ) == 0 ||
strcmp ( V_2 [ V_4 ] , L_7 ) == 0 )
F_9 ( NULL , V_11 ,
V_12 , V_13 , V_5 ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_8 ) == 0 ||
strcmp ( V_2 [ V_4 ] , L_9 ) == 0 )
F_9 ( NULL , V_14 ,
V_15 , V_16 , V_5 ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_10 ) == 0 ||
strcmp ( V_2 [ V_4 ] , L_11 ) == 0 )
F_10 ( NULL , V_5 ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_12 ) == 0 )
F_11 ( NULL , V_5 ) ;
else {
char * V_17 = strchr ( V_2 [ V_4 ] , ':' ) , * V_18 ;
int V_19 ;
if ( V_17 == NULL ) {
F_7 ( V_2 [ V_4 ] , V_5 ) ;
continue;
}
V_19 = V_17 - V_2 [ V_4 ] ;
V_18 = F_12 ( V_2 [ V_4 ] ) ;
if ( V_18 == NULL )
return - 1 ;
V_18 [ V_19 ] = '\0' ;
F_8 ( V_18 , V_18 + V_19 + 1 , V_5 ) ;
free ( V_18 ) ;
}
}
return 0 ;
}
