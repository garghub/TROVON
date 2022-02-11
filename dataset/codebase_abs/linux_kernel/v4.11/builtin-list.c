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
F_3 ( 0 , L_7 , & V_10 ,
L_8 ) ,
F_4 ()
} ;
const char * const V_11 [] = {
L_9 ,
NULL
} ;
F_5 ( V_8 , 0 , L_1 , V_12 ) ;
V_1 = F_6 ( V_1 , V_2 , V_8 , V_11 ,
V_13 ) ;
F_7 () ;
if ( ! V_5 && F_8 () )
printf ( L_10 ) ;
if ( V_1 == 0 ) {
F_9 ( NULL , V_5 , ! V_9 , V_6 ) ;
return 0 ;
}
for ( V_4 = 0 ; V_4 < V_1 ; ++ V_4 ) {
char * V_14 , * V_15 ;
if ( strcmp ( V_2 [ V_4 ] , L_11 ) == 0 )
F_10 ( NULL , NULL , V_5 ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_12 ) == 0 ||
strcmp ( V_2 [ V_4 ] , L_13 ) == 0 )
F_11 ( NULL , V_16 ,
V_17 , V_18 , V_5 ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_14 ) == 0 ||
strcmp ( V_2 [ V_4 ] , L_15 ) == 0 )
F_11 ( NULL , V_19 ,
V_20 , V_21 , V_5 ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_16 ) == 0 ||
strcmp ( V_2 [ V_4 ] , L_17 ) == 0 )
F_12 ( NULL , V_5 ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_18 ) == 0 )
F_13 ( NULL , V_5 , ! V_9 ,
V_6 ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_19 ) == 0 )
F_14 ( NULL , NULL , V_5 ) ;
else if ( ( V_14 = strchr ( V_2 [ V_4 ] , ':' ) ) != NULL ) {
int V_22 ;
if ( V_14 == NULL ) {
F_9 ( V_2 [ V_4 ] , V_5 , ! V_9 ,
V_6 ) ;
continue;
}
V_22 = V_14 - V_2 [ V_4 ] ;
V_15 = F_15 ( V_2 [ V_4 ] ) ;
if ( V_15 == NULL )
return - 1 ;
V_15 [ V_22 ] = '\0' ;
F_10 ( V_15 , V_15 + V_22 + 1 , V_5 ) ;
F_14 ( V_15 , V_15 + V_22 + 1 , V_5 ) ;
free ( V_15 ) ;
} else {
if ( F_16 ( & V_15 , L_20 , V_2 [ V_4 ] ) < 0 ) {
printf ( L_21 ) ;
continue;
}
F_11 ( V_15 , V_16 ,
V_17 , V_18 , V_5 ) ;
F_11 ( V_15 , V_19 ,
V_20 , V_21 , V_5 ) ;
F_12 ( V_15 , V_5 ) ;
F_13 ( V_15 , V_5 , ! V_9 ,
V_6 ) ;
F_10 ( NULL , V_15 , V_5 ) ;
F_14 ( NULL , V_15 , V_5 ) ;
free ( V_15 ) ;
}
}
return 0 ;
}
