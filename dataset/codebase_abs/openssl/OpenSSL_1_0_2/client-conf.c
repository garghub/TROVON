int main ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL , * V_4 = NULL ;
int V_5 , V_6 , V_7 ;
char V_8 [ 1024 ] ;
T_2 * V_9 = NULL ;
T_3 * V_10 = NULL ;
T_4 * V_11 = NULL ;
T_5 * V_12 = NULL ;
F_1 ( V_13 ) * V_14 = NULL ;
V_13 * V_15 ;
const char * V_16 = L_1 ;
long V_17 = - 1 ;
F_2 () ;
F_3 () ;
F_4 () ;
V_12 = F_5 ( NULL ) ;
if ( F_6 ( V_12 , L_2 , & V_17 ) <= 0 ) {
if ( V_17 <= 0 )
fprintf ( V_18 , L_3 ) ;
else
fprintf ( V_18 , L_4 , V_17 ) ;
goto V_19;
}
V_14 = F_7 ( V_12 , L_5 ) ;
if ( V_14 == NULL ) {
fprintf ( V_18 , L_6 ) ;
goto V_19;
}
V_9 = F_8 ( F_9 () ) ;
V_10 = F_10 () ;
F_11 ( V_10 , V_20 ) ;
F_11 ( V_10 , V_21 ) ;
F_12 ( V_10 , V_9 ) ;
for ( V_5 = 0 ; V_5 < F_13 ( V_14 ) ; V_5 ++ ) {
V_15 = F_14 ( V_14 , V_5 ) ;
V_7 = F_15 ( V_10 , V_15 -> V_22 , V_15 -> V_23 ) ;
if ( V_7 > 0 )
continue;
if ( V_7 != - 2 ) {
fprintf ( V_18 , L_7 ,
V_15 -> V_22 , V_15 -> V_23 ) ;
F_16 ( V_18 ) ;
goto V_19;
}
if ( ! strcmp ( V_15 -> V_22 , L_8 ) ) {
V_16 = V_15 -> V_23 ;
} else {
fprintf ( V_18 , L_9 , V_15 -> V_22 ) ;
goto V_19;
}
}
if ( ! F_17 ( V_10 ) ) {
fprintf ( V_18 , L_10 ) ;
F_16 ( V_18 ) ;
goto V_24;
}
V_3 = F_18 ( V_9 ) ;
F_19 ( V_3 , & V_11 ) ;
if ( ! V_11 ) {
fprintf ( V_18 , L_11 ) ;
goto V_19;
}
F_20 ( V_11 , V_25 ) ;
F_21 ( V_3 , V_16 ) ;
V_4 = F_22 ( stdout , V_26 ) ;
if ( F_23 ( V_3 ) <= 0 ) {
fprintf ( V_18 , L_12 ) ;
F_16 ( V_18 ) ;
goto V_19;
}
if ( F_24 ( V_3 ) <= 0 ) {
fprintf ( V_18 , L_13 ) ;
F_16 ( V_18 ) ;
goto V_19;
}
F_25 ( V_3 , L_14 ) ;
for (; ; ) {
V_6 = F_26 ( V_3 , V_8 , 1024 ) ;
if ( V_6 <= 0 )
break;
F_27 ( V_4 , V_8 , V_6 ) ;
}
V_19:
F_28 ( V_10 ) ;
F_29 ( V_3 ) ;
F_30 ( V_4 ) ;
F_31 ( V_12 ) ;
return 0 ;
}
