int main ( T_1 , T_2 )
int T_1 ;
char * * T_2 ;
{
char * V_1 = NULL ;
unsigned char * V_2 = NULL , * V_3 = NULL ;
int V_4 = V_5 , V_6 = 0 ;
int V_7 = 1 , V_8 ;
char * V_9 = NULL ;
char * V_10 = NULL , * V_11 = NULL ;
int V_12 = 1 , V_13 = 0 , V_14 , V_15 = 0 ;
int V_16 = 0 ;
T_3 * V_17 = NULL , * V_18 ;
char * V_19 = NULL , * V_20 = NULL ;
T_4 * V_21 = NULL , * V_22 = NULL , * V_23 = NULL , * V_24 = NULL , * V_25 =
NULL , * V_26 = NULL ;
#define F_1 39
F_2 () ;
if ( V_27 == NULL )
if ( ( V_27 = F_3 ( F_4 () ) ) != NULL )
F_5 ( V_27 , V_28 , V_29 ) ;
V_15 = 1 ;
T_1 -- ;
T_2 ++ ;
while ( T_1 >= 1 ) {
if ( strcmp ( * T_2 , L_1 ) == 0 )
V_12 = 1 ;
if ( strcmp ( * T_2 , L_2 ) == 0 ) {
if ( -- T_1 < 1 )
goto V_30;
V_19 = * ( ++ T_2 ) ;
} else if ( strcmp ( * T_2 , L_3 ) == 0 ) {
if ( -- T_1 < 1 )
goto V_30;
V_20 = * ( ++ T_2 ) ;
} else if ( strcmp ( * T_2 , L_4 ) == 0 )
V_12 = 0 ;
else if ( strcmp ( * T_2 , L_5 ) == 0 )
V_6 = 1 ;
else if ( strcmp ( * T_2 , L_6 ) == 0 )
V_16 = 1 ;
else if ( strcmp ( * T_2 , L_7 ) == 0 ) {
if ( -- T_1 < 1 )
goto V_30;
V_3 = ( unsigned char * ) * ( ++ T_2 ) ;
} else {
F_6 ( V_27 , L_8 , * T_2 ) ;
V_30:
F_6 ( V_27 , L_9 ) ;
F_6 ( V_27 , L_10 , L_11 ) ;
F_6 ( V_27 , L_12 , L_13 ) ;
F_6 ( V_27 , L_14 , L_1 ) ;
F_6 ( V_27 , L_15 , L_4 ) ;
F_6 ( V_27 , L_16 , L_17 ) ;
goto V_31;
}
T_1 -- ;
T_2 ++ ;
}
if ( V_3 != NULL ) {
int V_14 ;
unsigned long V_32 ;
for ( V_32 = 0 ; * V_3 ; V_3 ++ ) {
V_14 = * V_3 ;
if ( ( V_14 <= '9' ) && ( V_14 >= '0' ) )
V_32 = V_32 * 10 + V_14 - '0' ;
else if ( V_14 == 'k' ) {
V_32 *= 1024 ;
V_3 ++ ;
break;
}
}
if ( * V_3 != '\0' ) {
F_6 ( V_27 , L_18 ) ;
goto V_31;
}
if ( V_32 < 80 )
V_32 = 80 ;
V_4 = ( int ) V_32 ;
if ( V_6 )
F_6 ( V_27 , L_19 , V_4 ) ;
}
V_1 = F_7 ( V_33 ) ;
V_2 = ( unsigned char * ) F_7 ( F_8 ( V_4 ) ) ;
if ( ( V_2 == NULL ) || ( V_1 == NULL ) ) {
F_6 ( V_27 , L_20 ) ;
goto V_31;
}
V_21 = F_3 ( F_4 () ) ;
V_22 = F_3 ( F_4 () ) ;
if ( ( V_21 == NULL ) || ( V_22 == NULL ) ) {
F_9 ( V_27 ) ;
goto V_31;
}
if ( V_16 ) {
F_10 ( V_21 , V_34 ) ;
F_10 ( V_22 , V_34 ) ;
F_11 ( V_21 , V_27 ) ;
F_11 ( V_22 , V_27 ) ;
}
if ( V_19 == NULL )
F_5 ( V_21 , V_35 , V_29 ) ;
else {
if ( F_12 ( V_21 , V_19 ) <= 0 ) {
perror ( V_19 ) ;
goto V_31;
}
}
if ( V_20 == NULL )
F_5 ( V_22 , stdout , V_29 ) ;
else {
if ( F_13 ( V_22 , V_20 ) <= 0 ) {
perror ( V_20 ) ;
goto V_31;
}
}
V_25 = V_21 ;
V_26 = V_22 ;
if ( V_15 ) {
if ( ( V_23 = F_3 ( F_14 () ) ) == NULL )
goto V_31;
if ( V_16 ) {
F_10 ( V_23 , V_34 ) ;
F_11 ( V_23 , V_27 ) ;
}
if ( V_12 )
V_26 = F_15 ( V_23 , V_26 ) ;
else
V_25 = F_15 ( V_23 , V_25 ) ;
}
for (; ; ) {
V_8 = F_16 ( V_25 , ( char * ) V_2 , V_4 ) ;
if ( V_8 <= 0 )
break;
if ( F_17 ( V_26 , ( char * ) V_2 , V_8 ) != V_8 ) {
F_6 ( V_27 , L_21 ) ;
goto V_31;
}
}
F_18 ( V_26 ) ;
V_7 = 0 ;
if ( V_6 ) {
F_6 ( V_27 , L_22 , F_19 ( V_21 ) ) ;
F_6 ( V_27 , L_23 , F_20 ( V_22 ) ) ;
}
V_31:
if ( V_1 != NULL )
F_21 ( V_1 ) ;
if ( V_2 != NULL )
F_21 ( V_2 ) ;
if ( V_21 != NULL )
F_22 ( V_21 ) ;
if ( V_22 != NULL )
F_22 ( V_22 ) ;
if ( V_24 != NULL )
F_22 ( V_24 ) ;
if ( V_23 != NULL )
F_22 ( V_23 ) ;
EXIT ( V_7 ) ;
}
