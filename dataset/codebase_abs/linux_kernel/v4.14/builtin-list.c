int F_1 ( int V_1 , const char * * V_2 )
{
int V_3 ;
bool V_4 = false ;
bool V_5 = false ;
struct V_6 V_7 [] = {
F_2 ( 0 , L_1 , & V_4 , L_2 ) ,
F_2 ( 'd' , L_3 , & V_8 ,
L_4 ) ,
F_2 ( 'v' , L_5 , & V_5 ,
L_6 ) ,
F_2 ( 0 , L_7 , & V_9 ,
L_8 ) ,
F_3 ( 0 , L_9 , & V_10 ,
L_10 ) ,
F_4 ()
} ;
const char * const V_11 [] = {
L_11 ,
NULL
} ;
F_5 ( V_7 , 0 , L_1 , V_12 ) ;
V_1 = F_6 ( V_1 , V_2 , V_7 , V_11 ,
V_13 ) ;
F_7 () ;
if ( ! V_4 && F_8 () )
printf ( L_12 ) ;
if ( V_1 == 0 ) {
F_9 ( NULL , V_4 , ! V_8 , V_5 ,
V_9 ) ;
return 0 ;
}
for ( V_3 = 0 ; V_3 < V_1 ; ++ V_3 ) {
char * V_14 , * V_15 ;
if ( strcmp ( V_2 [ V_3 ] , L_13 ) == 0 )
F_10 ( NULL , NULL , V_4 ) ;
else if ( strcmp ( V_2 [ V_3 ] , L_14 ) == 0 ||
strcmp ( V_2 [ V_3 ] , L_15 ) == 0 )
F_11 ( NULL , V_16 ,
V_17 , V_18 , V_4 ) ;
else if ( strcmp ( V_2 [ V_3 ] , L_16 ) == 0 ||
strcmp ( V_2 [ V_3 ] , L_17 ) == 0 )
F_11 ( NULL , V_19 ,
V_20 , V_21 , V_4 ) ;
else if ( strcmp ( V_2 [ V_3 ] , L_18 ) == 0 ||
strcmp ( V_2 [ V_3 ] , L_19 ) == 0 )
F_12 ( NULL , V_4 ) ;
else if ( strcmp ( V_2 [ V_3 ] , L_20 ) == 0 )
F_13 ( NULL , V_4 , ! V_8 ,
V_5 , V_9 ) ;
else if ( strcmp ( V_2 [ V_3 ] , L_21 ) == 0 )
F_14 ( NULL , NULL , V_4 ) ;
else if ( ( V_14 = strchr ( V_2 [ V_3 ] , ':' ) ) != NULL ) {
int V_22 ;
if ( V_14 == NULL ) {
F_9 ( V_2 [ V_3 ] , V_4 , ! V_8 ,
V_5 ,
V_9 ) ;
continue;
}
V_22 = V_14 - V_2 [ V_3 ] ;
V_15 = F_15 ( V_2 [ V_3 ] ) ;
if ( V_15 == NULL )
return - 1 ;
V_15 [ V_22 ] = '\0' ;
F_10 ( V_15 , V_15 + V_22 + 1 , V_4 ) ;
F_14 ( V_15 , V_15 + V_22 + 1 , V_4 ) ;
free ( V_15 ) ;
} else {
if ( F_16 ( & V_15 , L_22 , V_2 [ V_3 ] ) < 0 ) {
printf ( L_23 ) ;
continue;
}
F_11 ( V_15 , V_16 ,
V_17 , V_18 , V_4 ) ;
F_11 ( V_15 , V_19 ,
V_20 , V_21 , V_4 ) ;
F_12 ( V_15 , V_4 ) ;
F_13 ( V_15 , V_4 , ! V_8 ,
V_5 ,
V_9 ) ;
F_10 ( NULL , V_15 , V_4 ) ;
F_14 ( NULL , V_15 , V_4 ) ;
free ( V_15 ) ;
}
}
return 0 ;
}
