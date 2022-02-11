int main ( T_1 , T_2 )
int T_1 ;
char * T_2 [] ;
{
const char * V_1 = V_2 ;
const char * V_3 = V_4 ;
char * V_5 ;
char * V_6 ;
T_3 * V_7 = NULL ;
char V_8 [ 1024 * 10 ] , * V_9 ;
T_4 * V_10 = NULL ;
T_5 * V_11 ;
T_3 * V_12 ;
int V_13 , V_14 , V_15 , V_16 = 1 ;
if ( T_1 > 1 )
V_1 = T_2 [ 1 ] ;
if ( T_1 > 2 )
V_3 = T_2 [ 2 ] ;
V_5 = F_1 ( V_1 ) ;
if ( ( V_6 = strchr ( V_5 , ':' ) ) != NULL )
* V_6 = 0 ;
#ifdef F_2
F_3 () ;
F_4 () ;
#endif
F_5 () ;
F_6 () ;
V_10 = F_7 ( F_8 () ) ;
F_9 ( V_10 , V_17 , NULL ) ;
F_10 ( V_10 , V_3 , NULL ) ;
V_11 = F_11 ( V_10 ) ;
F_12 ( V_11 ) ;
if ( F_13 ( V_11 , V_5 ) <= 0 )
goto V_18;
V_12 = F_14 ( F_15 () ) ;
F_16 ( V_12 , V_11 , V_19 ) ;
V_7 = F_14 ( F_17 () ) ;
F_18 ( V_7 , V_1 ) ;
F_19 ( V_7 , 1 ) ;
V_7 = F_20 ( V_12 , V_7 ) ;
V_9 = L_1 ;
V_14 = strlen ( V_9 ) ;
V_15 = 0 ;
for (; ; ) {
V_13 = F_21 ( V_7 , & ( V_9 [ V_15 ] ) , V_14 ) ;
if ( V_13 <= 0 ) {
if ( F_22 ( V_7 ) ) {
fprintf ( V_20 , L_2 ) ;
F_23 ( 1 ) ;
continue;
} else {
goto V_18;
}
}
V_15 += V_13 ;
V_14 -= V_13 ;
if ( V_14 <= 0 )
break;
}
for (; ; ) {
V_13 = F_24 ( V_7 , V_8 , sizeof( V_8 ) ) ;
if ( V_13 == 0 )
break;
if ( V_13 < 0 ) {
if ( F_22 ( V_7 ) ) {
fprintf ( V_20 , L_3 ) ;
F_23 ( 1 ) ;
continue;
}
goto V_18;
}
fwrite ( V_8 , 1 , V_13 , stdout ) ;
}
V_16 = 1 ;
goto V_21;
V_18:
if ( F_25 () == 0 ) {
fprintf ( V_20 , L_4 , V_22 ) ;
perror ( L_5 ) ;
} else
F_26 ( V_20 ) ;
V_21:
F_27 ( V_7 ) ;
F_28 ( V_10 ) ;
return ( V_16 == 1 ) ;
}
