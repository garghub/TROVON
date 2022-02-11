int main ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL , * V_4 = NULL ;
int V_5 ;
char V_6 [ 1024 ] ;
T_2 * V_7 ;
T_3 * V_8 ;
T_4 * V_9 ;
char * * args = V_2 + 1 ;
const char * V_10 = L_1 ;
int V_11 = V_1 - 1 ;
F_1 () ;
F_2 () ;
F_3 () ;
V_7 = F_4 ( F_5 () ) ;
V_8 = F_6 () ;
F_7 ( V_8 , V_12 ) ;
F_8 ( V_8 , V_7 ) ;
while ( * args && * * args == '-' ) {
int V_13 ;
V_13 = F_9 ( V_8 , & V_11 , & args ) ;
if ( V_13 == - 3 ) {
fprintf ( V_14 , L_2 , * args ) ;
goto V_15;
}
if ( V_13 < 0 ) {
fprintf ( V_14 , L_3 , * args ) ;
F_10 ( V_14 ) ;
goto V_15;
}
if ( V_13 > 0 )
continue;
if ( ! strcmp ( * args , L_4 ) ) {
V_10 = args [ 1 ] ;
if ( V_10 == NULL ) {
fprintf ( V_14 , L_5 ) ;
goto V_15;
}
args += 2 ;
V_11 -= 2 ;
continue;
} else {
fprintf ( V_14 , L_6 , * args ) ;
goto V_15;
}
}
if ( ! F_11 ( V_8 ) ) {
fprintf ( V_14 , L_7 ) ;
F_10 ( V_14 ) ;
goto V_16;
}
V_3 = F_12 ( V_7 ) ;
F_13 ( V_3 , & V_9 ) ;
if ( ! V_9 ) {
fprintf ( V_14 , L_8 ) ;
goto V_15;
}
F_14 ( V_9 , V_17 ) ;
F_15 ( V_3 , V_10 ) ;
V_4 = F_16 ( stdout , V_18 ) ;
if ( F_17 ( V_3 ) <= 0 ) {
fprintf ( V_14 , L_9 ) ;
F_10 ( V_14 ) ;
goto V_15;
}
if ( F_18 ( V_3 ) <= 0 ) {
fprintf ( V_14 , L_10 ) ;
F_10 ( V_14 ) ;
goto V_15;
}
F_19 ( V_3 , L_11 ) ;
for (; ; ) {
V_5 = F_20 ( V_3 , V_6 , 1024 ) ;
if ( V_5 <= 0 )
break;
F_21 ( V_4 , V_6 , V_5 ) ;
}
V_15:
F_22 ( V_8 ) ;
F_23 ( V_3 ) ;
F_24 ( V_4 ) ;
return 0 ;
}
