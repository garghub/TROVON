int main ( int V_1 , char * V_2 [] )
{
unsigned char V_3 [ 512 ] ;
char * V_4 = L_1 ;
T_1 * V_5 = NULL ;
T_1 * V_6 , * V_7 ;
T_2 * V_8 ;
int V_9 = 1 , V_10 ;
F_1 () ;
F_2 () ;
if ( F_3 ( L_2 , L_3 , 0 ) <= 0 ) {
fprintf ( V_11 , L_4 ) ;
goto V_12;
}
V_8 = F_4 ( F_5 () ) ;
if ( F_6 ( V_8 , L_5 ) == 0 ) {
fprintf ( V_11 , L_6 ) ;
goto V_12;
}
V_6 = F_7 ( V_8 , 0 ) ;
if ( ( V_5 = F_8 ( V_4 ) ) == NULL )
goto V_12;
F_9 ( V_5 , V_6 ) ;
V_13:
if ( F_10 ( V_5 ) <= 0 )
goto V_12;
for (; ; ) {
V_10 = F_11 ( V_5 , V_3 , sizeof( V_3 ) ) ;
if ( V_10 == 0 ) {
printf ( L_7 ) ;
V_7 = F_12 ( V_5 ) ;
F_13 ( V_7 ) ;
goto V_13;
}
if ( V_10 < 0 ) {
if ( F_14 ( V_5 ) )
continue;
goto V_12;
}
fwrite ( V_3 , 1 , V_10 , stdout ) ;
fflush ( stdout ) ;
}
V_9 = 0 ;
V_12:
if ( V_9 ) {
F_15 ( V_11 ) ;
}
F_16 ( V_5 ) ;
exit ( V_9 ) ;
return ( ! V_9 ) ;
}
