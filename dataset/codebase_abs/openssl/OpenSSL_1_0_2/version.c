int MAIN ( int V_1 , char * * V_2 )
{
int V_3 , V_4 = 0 ;
int V_5 = 0 , V_6 = 0 , V_7 = 0 , V_8 = 0 , V_9 = 0 , V_10 = 0 ;
F_1 () ;
if ( V_11 == NULL )
if ( ( V_11 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_11 , V_12 , V_13 | V_14 ) ;
if ( V_1 == 1 )
V_6 = 1 ;
for ( V_3 = 1 ; V_3 < V_1 ; V_3 ++ ) {
if ( strcmp ( V_2 [ V_3 ] , L_1 ) == 0 )
V_6 = 1 ;
else if ( strcmp ( V_2 [ V_3 ] , L_2 ) == 0 )
V_7 = 1 ;
else if ( strcmp ( V_2 [ V_3 ] , L_3 ) == 0 )
V_5 = 1 ;
else if ( strcmp ( V_2 [ V_3 ] , L_4 ) == 0 )
V_8 = 1 ;
else if ( strcmp ( V_2 [ V_3 ] , L_5 ) == 0 )
V_9 = 1 ;
else if ( strcmp ( V_2 [ V_3 ] , L_6 ) == 0 )
V_10 = 1 ;
else if ( strcmp ( V_2 [ V_3 ] , L_7 ) == 0 )
V_7 = V_6 = V_5 = V_8 = V_9 = V_10 = 1 ;
else {
F_5 ( V_11 , L_8 ) ;
V_4 = 1 ;
goto V_15;
}
}
if ( V_6 ) {
if ( F_6 () == V_16 ) {
printf ( L_9 , F_7 ( V_17 ) ) ;
} else {
printf ( L_10 ,
V_18 , F_7 ( V_17 ) ) ;
}
}
if ( V_7 )
printf ( L_9 , F_7 ( V_19 ) ) ;
if ( V_9 )
printf ( L_9 , F_7 ( V_20 ) ) ;
if ( V_8 ) {
printf ( L_11 ) ;
printf ( L_12 , F_8 () ) ;
#ifndef F_9
printf ( L_12 , F_10 () ) ;
#endif
#ifndef F_11
printf ( L_12 , F_12 () ) ;
#endif
#ifndef F_13
printf ( L_12 , F_14 () ) ;
#endif
#ifndef F_15
printf ( L_12 , F_16 () ) ;
#endif
#ifndef F_17
printf ( L_12 , F_18 () ) ;
#endif
printf ( L_13 ) ;
}
if ( V_5 )
printf ( L_9 , F_7 ( V_21 ) ) ;
if ( V_10 )
printf ( L_9 , F_7 ( V_22 ) ) ;
V_15:
F_19 () ;
F_20 ( V_4 ) ;
}
