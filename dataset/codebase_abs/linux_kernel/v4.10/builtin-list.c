int F_1 ( int V_1 , const char * * V_2 , const char * T_1 V_3 )
{
int V_4 ;
bool V_5 = false ;
bool V_6 = false ;
struct V_7 V_8 [] = {
F_2 ( 0 , L_1 , & V_5 , L_2 ) ,
F_2 ( 'd' , L_3 , & V_9 ,
L_4 ) ,
F_2 ( 'v' , L_5 , & V_6 ,
L_6 ) ,
F_3 ()
} ;
const char * const V_10 [] = {
L_7 ,
NULL
} ;
F_4 ( V_8 , 0 , L_1 , V_11 ) ;
V_1 = F_5 ( V_1 , V_2 , V_8 , V_10 ,
V_12 ) ;
F_6 () ;
if ( ! V_5 && F_7 () )
printf ( L_8 ) ;
if ( V_1 == 0 ) {
F_8 ( NULL , V_5 , ! V_9 , V_6 ) ;
return 0 ;
}
for ( V_4 = 0 ; V_4 < V_1 ; ++ V_4 ) {
char * V_13 , * V_14 ;
if ( strcmp ( V_2 [ V_4 ] , L_9 ) == 0 )
F_9 ( NULL , NULL , V_5 ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_10 ) == 0 ||
strcmp ( V_2 [ V_4 ] , L_11 ) == 0 )
F_10 ( NULL , V_15 ,
V_16 , V_17 , V_5 ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_12 ) == 0 ||
strcmp ( V_2 [ V_4 ] , L_13 ) == 0 )
F_10 ( NULL , V_18 ,
V_19 , V_20 , V_5 ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_14 ) == 0 ||
strcmp ( V_2 [ V_4 ] , L_15 ) == 0 )
F_11 ( NULL , V_5 ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_16 ) == 0 )
F_12 ( NULL , V_5 , ! V_9 ,
V_6 ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_17 ) == 0 )
F_13 ( NULL , NULL , V_5 ) ;
else if ( ( V_13 = strchr ( V_2 [ V_4 ] , ':' ) ) != NULL ) {
int V_21 ;
if ( V_13 == NULL ) {
F_8 ( V_2 [ V_4 ] , V_5 , ! V_9 ,
V_6 ) ;
continue;
}
V_21 = V_13 - V_2 [ V_4 ] ;
V_14 = F_14 ( V_2 [ V_4 ] ) ;
if ( V_14 == NULL )
return - 1 ;
V_14 [ V_21 ] = '\0' ;
F_9 ( V_14 , V_14 + V_21 + 1 , V_5 ) ;
F_13 ( V_14 , V_14 + V_21 + 1 , V_5 ) ;
free ( V_14 ) ;
} else {
if ( F_15 ( & V_14 , L_18 , V_2 [ V_4 ] ) < 0 ) {
printf ( L_19 ) ;
continue;
}
F_10 ( V_14 , V_15 ,
V_16 , V_17 , V_5 ) ;
F_10 ( V_14 , V_18 ,
V_19 , V_20 , V_5 ) ;
F_11 ( V_14 , V_5 ) ;
F_12 ( V_14 , V_5 , ! V_9 ,
V_6 ) ;
F_9 ( NULL , V_14 , V_5 ) ;
F_13 ( NULL , V_14 , V_5 ) ;
free ( V_14 ) ;
}
}
return 0 ;
}
