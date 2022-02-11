int F_1 ( int V_1 , const char * * V_2 , const char * T_1 V_3 )
{
F_2 () ;
if ( V_1 == 1 )
F_3 ( NULL ) ;
else {
int V_4 ;
for ( V_4 = 1 ; V_4 < V_1 ; ++ V_4 ) {
if ( V_4 > 1 )
putchar ( '\n' ) ;
if ( strncmp ( V_2 [ V_4 ] , L_1 , 10 ) == 0 )
F_4 ( NULL , NULL ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_2 ) == 0 ||
strcmp ( V_2 [ V_4 ] , L_3 ) == 0 )
F_5 ( V_5 ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_4 ) == 0 ||
strcmp ( V_2 [ V_4 ] , L_5 ) == 0 )
F_5 ( V_6 ) ;
else if ( strcmp ( V_2 [ V_4 ] , L_6 ) == 0 ||
strcmp ( V_2 [ V_4 ] , L_7 ) == 0 )
F_6 ( NULL ) ;
else {
char * V_7 = strchr ( V_2 [ V_4 ] , ':' ) , * V_8 ;
int V_9 ;
if ( V_7 == NULL ) {
F_3 ( V_2 [ V_4 ] ) ;
continue;
}
V_9 = V_7 - V_2 [ V_4 ] ;
V_8 = F_7 ( V_2 [ V_4 ] ) ;
if ( V_8 == NULL )
return - 1 ;
V_8 [ V_9 ] = '\0' ;
F_4 ( V_8 , V_8 + V_9 + 1 ) ;
free ( V_8 ) ;
}
}
}
return 0 ;
}
