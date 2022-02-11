int main ( int V_1 , char * V_2 [] )
{
char * V_3 = L_1 ;
T_1 * V_4 = NULL ;
T_1 * V_5 , * V_6 ;
T_2 * V_7 ;
T_3 * V_8 = NULL ;
T_4 * V_9 = NULL ;
F_1 ( V_10 ) * V_11 = NULL ;
V_10 * V_12 ;
long V_13 = - 1 ;
char V_14 [ 512 ] ;
int V_15 = 1 , V_16 ;
F_2 () ;
F_3 () ;
V_9 = F_4 ( NULL ) ;
if ( F_5 ( V_9 , L_2 , & V_13 ) <= 0 ) {
if ( V_13 <= 0 )
fprintf ( V_17 , L_3 ) ;
else
fprintf ( V_17 , L_4 , V_13 ) ;
goto V_18;
}
V_11 = F_6 ( V_9 , L_5 ) ;
if ( V_11 == NULL ) {
fprintf ( V_17 , L_6 ) ;
goto V_18;
}
V_7 = F_7 ( F_8 () ) ;
V_8 = F_9 () ;
F_10 ( V_8 , V_19 ) ;
F_10 ( V_8 , V_20 ) ;
F_10 ( V_8 , V_21 ) ;
F_11 ( V_8 , V_7 ) ;
for ( V_16 = 0 ; V_16 < F_12 ( V_11 ) ; V_16 ++ ) {
int V_22 ;
V_12 = F_13 ( V_11 , V_16 ) ;
V_22 = F_14 ( V_8 , V_12 -> V_23 , V_12 -> V_24 ) ;
if ( V_22 > 0 )
continue;
if ( V_22 != - 2 ) {
fprintf ( V_17 , L_7 ,
V_12 -> V_23 , V_12 -> V_24 ) ;
F_15 ( V_17 ) ;
goto V_18;
}
if ( ! strcmp ( V_12 -> V_23 , L_8 ) ) {
V_3 = V_12 -> V_24 ;
} else {
fprintf ( V_17 , L_9 , V_12 -> V_23 ) ;
goto V_18;
}
}
if ( ! F_16 ( V_8 ) ) {
fprintf ( V_17 , L_10 ) ;
F_15 ( V_17 ) ;
goto V_18;
}
V_5 = F_17 ( V_7 , 0 ) ;
if ( ( V_4 = F_18 ( V_3 ) ) == NULL )
goto V_18;
F_19 ( V_4 , V_5 ) ;
V_25:
if ( F_20 ( V_4 ) <= 0 )
goto V_18;
for (; ; ) {
V_16 = F_21 ( V_4 , V_14 , 512 ) ;
if ( V_16 == 0 ) {
printf ( L_11 ) ;
V_6 = F_22 ( V_4 ) ;
F_23 ( V_6 ) ;
goto V_25;
}
if ( V_16 < 0 ) {
if ( F_24 ( V_4 ) )
continue;
goto V_18;
}
fwrite ( V_14 , 1 , V_16 , stdout ) ;
fflush ( stdout ) ;
}
V_15 = 0 ;
V_18:
if ( V_15 ) {
F_15 ( V_17 ) ;
}
if ( V_4 != NULL )
F_25 ( V_4 ) ;
exit ( V_15 ) ;
return ( ! V_15 ) ;
}
