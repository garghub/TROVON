void F_1 ()
{
if ( V_1 != NULL )
F_2 ( V_1 ) ;
}
int main ( T_1 , T_2 )
int T_1 ;
char * T_2 [] ;
{
char * V_2 = NULL ;
T_3 * V_3 , * V_4 ;
T_4 * V_5 ;
T_5 * V_6 ;
char V_7 [ 512 ] ;
int V_8 = 1 , V_9 ;
if ( T_1 <= 1 )
V_2 = L_1 ;
else
V_2 = T_2 [ 1 ] ;
signal ( V_10 , F_1 ) ;
F_3 () ;
#ifdef F_4
F_5 () ;
F_6 () ;
#endif
F_7 () ;
V_5 = F_8 ( F_9 () ) ;
if ( ! F_10 ( V_5 , V_11 , V_12 ) )
goto V_13;
if ( ! F_11 ( V_5 , V_11 , V_12 ) )
goto V_13;
if ( ! F_12 ( V_5 ) )
goto V_13;
V_6 = F_13 ( V_5 ) ;
V_3 = F_14 ( V_5 , 0 ) ;
if ( ( V_1 = F_15 ( V_2 ) ) == NULL )
goto V_13;
F_16 ( V_1 , V_3 ) ;
V_14:
if ( F_17 ( V_1 ) <= 0 )
goto V_13;
for (; ; ) {
V_9 = F_18 ( V_1 , V_7 , 512 ) ;
if ( V_9 == 0 ) {
printf ( L_2 ) ;
V_4 = F_19 ( V_1 ) ;
F_20 ( V_4 ) ;
goto V_14;
}
if ( V_9 < 0 )
goto V_13;
fwrite ( V_7 , 1 , V_9 , stdout ) ;
fflush ( stdout ) ;
}
V_8 = 0 ;
V_13:
if ( V_8 ) {
F_21 ( V_15 ) ;
}
if ( V_1 != NULL )
F_2 ( V_1 ) ;
exit ( V_8 ) ;
return ( ! V_8 ) ;
}
