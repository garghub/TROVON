int main ( int V_1 , char * V_2 [] )
{
char * V_3 = L_1 ;
T_1 * V_4 , * V_5 ;
T_2 * V_6 ;
T_3 * V_7 ;
char V_8 [ 512 ] ;
T_1 * V_9 = NULL ;
int V_10 = 1 , V_11 ;
char * * args = V_2 + 1 ;
int V_12 = V_1 - 1 ;
F_1 () ;
F_2 () ;
V_6 = F_3 ( F_4 () ) ;
V_7 = F_5 () ;
F_6 ( V_7 , V_13 ) ;
F_6 ( V_7 , V_14 ) ;
F_7 ( V_7 , V_6 ) ;
while ( * args && * * args == '-' ) {
int V_15 ;
V_15 = F_8 ( V_7 , & V_12 , & args ) ;
if ( V_15 == - 3 ) {
fprintf ( V_16 , L_2 , * args ) ;
goto V_17;
}
if ( V_15 < 0 ) {
fprintf ( V_16 , L_3 , * args ) ;
F_9 ( V_16 ) ;
goto V_17;
}
if ( V_15 > 0 )
continue;
if ( strcmp ( * args , L_4 ) == 0 ) {
V_3 = args [ 1 ] ;
if ( V_3 == NULL ) {
fprintf ( V_16 , L_5 ) ;
goto V_17;
}
args += 2 ;
V_12 -= 2 ;
continue;
} else {
fprintf ( V_16 , L_6 , * args ) ;
goto V_17;
}
}
if ( ! F_10 ( V_7 ) ) {
fprintf ( V_16 , L_7 ) ;
F_9 ( V_16 ) ;
goto V_17;
}
#ifdef F_11
{
T_4 * V_18 ;
int V_15 ;
V_15 = F_12 ( V_6 , V_19 ) ;
while ( V_15 ) {
T_4 * V_18 = F_13 ( V_6 ) ;
F_14 ( stdout , F_15 ( V_18 ) , 0 ,
V_20 ) ;
printf ( L_8 ) ;
V_15 = F_12 ( V_6 , V_21 ) ;
}
fflush ( stdout ) ;
}
#endif
V_4 = F_16 ( V_6 , 0 ) ;
if ( ( V_9 = F_17 ( V_3 ) ) == NULL )
goto V_17;
F_18 ( V_9 , V_4 ) ;
V_22:
if ( F_19 ( V_9 ) <= 0 )
goto V_17;
for (; ; ) {
V_11 = F_20 ( V_9 , V_8 , 512 ) ;
if ( V_11 == 0 ) {
printf ( L_9 ) ;
V_5 = F_21 ( V_9 ) ;
F_22 ( V_5 ) ;
goto V_22;
}
if ( V_11 < 0 )
goto V_17;
fwrite ( V_8 , 1 , V_11 , stdout ) ;
fflush ( stdout ) ;
}
V_10 = 0 ;
V_17:
if ( V_10 ) {
F_9 ( V_16 ) ;
}
F_23 ( V_9 ) ;
exit ( V_10 ) ;
return ( ! V_10 ) ;
}
