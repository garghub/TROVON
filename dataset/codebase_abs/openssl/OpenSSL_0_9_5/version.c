int MAIN ( int V_1 , char * * V_2 )
{
int V_3 , V_4 = 0 ;
int V_5 = 0 , V_6 = 0 , V_7 = 0 , V_8 = 0 , V_9 = 0 ;
F_1 () ;
if ( V_10 == NULL )
if ( ( V_10 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_10 , V_11 , V_12 | V_13 ) ;
if ( V_1 == 1 ) V_6 = 1 ;
for ( V_3 = 1 ; V_3 < V_1 ; V_3 ++ )
{
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
V_7 = V_6 = V_5 = V_8 = V_9 = 1 ;
else
{
F_5 ( V_10 , L_7 ) ;
V_4 = 1 ;
goto V_14;
}
}
if ( V_6 ) printf ( L_8 , F_6 ( V_15 ) ) ;
if ( V_7 ) printf ( L_8 , F_6 ( V_16 ) ) ;
if ( V_9 ) printf ( L_8 , F_6 ( V_17 ) ) ;
if ( V_8 )
{
printf ( L_9 ) ;
printf ( L_10 , F_7 () ) ;
#ifndef F_8
printf ( L_10 , F_9 () ) ;
#endif
#ifndef F_10
printf ( L_10 , F_11 () ) ;
#endif
#ifndef F_12
printf ( L_10 , F_13 () ) ;
#endif
#ifndef F_14
printf ( L_10 , F_15 () ) ;
#endif
#ifndef F_16
printf ( L_10 , F_17 () ) ;
#endif
printf ( L_11 ) ;
}
if ( V_5 ) printf ( L_8 , F_6 ( V_18 ) ) ;
V_14:
EXIT ( V_4 ) ;
}
