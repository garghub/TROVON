int main ( T_1 , T_2 )
int T_1 ;
char * * T_2 ;
{
char * V_1 = NULL ;
unsigned char * V_2 = NULL , * V_3 = NULL ;
int V_4 = V_5 , V_6 = 0 ;
int V_7 = 1 , V_8 ;
unsigned char V_9 [ 24 ] , V_10 [ V_11 ] ;
char * V_12 = NULL ;
char * V_13 = NULL , * V_14 = NULL ;
int V_15 = 1 , V_16 = 0 , V_17 , V_18 = 0 ;
int V_19 = 0 ;
T_3 * V_20 = NULL , * V_21 ;
char * V_22 = NULL , * V_23 = NULL ;
T_4 * V_24 = NULL , * V_25 = NULL , * V_26 = NULL , * V_27 = NULL , * V_28 = NULL , * V_29 = NULL ;
#define F_1 16
char V_30 [ F_1 ] ;
F_2 () ;
if ( V_31 == NULL )
if ( ( V_31 = F_3 ( F_4 () ) ) != NULL )
F_5 ( V_31 , V_32 , V_33 ) ;
V_18 = 1 ;
T_1 -- ;
T_2 ++ ;
while ( T_1 >= 1 )
{
if ( strcmp ( * T_2 , L_1 ) == 0 )
V_15 = 1 ;
if ( strcmp ( * T_2 , L_2 ) == 0 )
{
if ( -- T_1 < 1 ) goto V_34;
V_22 = * ( ++ T_2 ) ;
}
else if ( strcmp ( * T_2 , L_3 ) == 0 )
{
if ( -- T_1 < 1 ) goto V_34;
V_23 = * ( ++ T_2 ) ;
}
else if ( strcmp ( * T_2 , L_4 ) == 0 )
V_15 = 0 ;
else if ( strcmp ( * T_2 , L_5 ) == 0 )
V_6 = 1 ;
else if ( strcmp ( * T_2 , L_6 ) == 0 )
V_19 = 1 ;
else if ( strcmp ( * T_2 , L_7 ) == 0 )
{
if ( -- T_1 < 1 ) goto V_34;
V_3 = ( unsigned char * ) * ( ++ T_2 ) ;
}
else
{
F_6 ( V_31 , L_8 , * T_2 ) ;
V_34:
F_6 ( V_31 , L_9 ) ;
F_6 ( V_31 , L_10 , L_11 ) ;
F_6 ( V_31 , L_12 , L_13 ) ;
F_6 ( V_31 , L_14 , L_1 ) ;
F_6 ( V_31 , L_15 , L_4 ) ;
F_6 ( V_31 , L_16 , L_17 ) ;
goto V_35;
}
T_1 -- ;
T_2 ++ ;
}
if ( V_3 != NULL )
{
int V_17 ;
unsigned long V_36 ;
for ( V_36 = 0 ; * V_3 ; V_3 ++ )
{
V_17 = * V_3 ;
if ( ( V_17 <= '9' ) && ( V_17 >= '0' ) )
V_36 = V_36 * 10 + V_17 - '0' ;
else if ( V_17 == 'k' )
{
V_36 *= 1024 ;
V_3 ++ ;
break;
}
}
if ( * V_3 != '\0' )
{
F_6 ( V_31 , L_18 ) ;
goto V_35;
}
if ( V_36 < 80 ) V_36 = 80 ;
V_4 = ( int ) V_36 ;
if ( V_6 ) F_6 ( V_31 , L_19 , V_4 ) ;
}
V_1 = Malloc ( V_37 ) ;
V_2 = ( unsigned char * ) Malloc ( F_7 ( V_4 ) ) ;
if ( ( V_2 == NULL ) || ( V_1 == NULL ) )
{
F_6 ( V_31 , L_20 ) ;
goto V_35;
}
V_24 = F_3 ( F_4 () ) ;
V_25 = F_3 ( F_4 () ) ;
if ( ( V_24 == NULL ) || ( V_25 == NULL ) )
{
F_8 ( V_31 ) ;
goto V_35;
}
if ( V_19 )
{
F_9 ( V_24 , V_38 ) ;
F_9 ( V_25 , V_38 ) ;
F_10 ( V_24 , V_31 ) ;
F_10 ( V_25 , V_31 ) ;
}
if ( V_22 == NULL )
F_5 ( V_24 , V_39 , V_33 ) ;
else
{
if ( F_11 ( V_24 , V_22 ) <= 0 )
{
perror ( V_22 ) ;
goto V_35;
}
}
if ( V_23 == NULL )
F_5 ( V_25 , stdout , V_33 ) ;
else
{
if ( F_12 ( V_25 , V_23 ) <= 0 )
{
perror ( V_23 ) ;
goto V_35;
}
}
V_28 = V_24 ;
V_29 = V_25 ;
if ( V_18 )
{
if ( ( V_26 = F_3 ( F_13 () ) ) == NULL )
goto V_35;
if ( V_19 )
{
F_9 ( V_26 , V_38 ) ;
F_10 ( V_26 , V_31 ) ;
}
if ( V_15 )
V_29 = F_14 ( V_26 , V_29 ) ;
else
V_28 = F_14 ( V_26 , V_28 ) ;
}
for (; ; )
{
V_8 = F_15 ( V_28 , ( char * ) V_2 , V_4 ) ;
if ( V_8 <= 0 ) break;
if ( F_16 ( V_29 , ( char * ) V_2 , V_8 ) != V_8 )
{
F_6 ( V_31 , L_21 ) ;
goto V_35;
}
}
F_17 ( V_29 ) ;
V_7 = 0 ;
if ( V_6 )
{
F_6 ( V_31 , L_22 , F_18 ( V_24 ) ) ;
F_6 ( V_31 , L_23 , F_19 ( V_25 ) ) ;
}
V_35:
if ( V_1 != NULL ) Free ( V_1 ) ;
if ( V_2 != NULL ) Free ( V_2 ) ;
if ( V_24 != NULL ) F_20 ( V_24 ) ;
if ( V_25 != NULL ) F_20 ( V_25 ) ;
if ( V_27 != NULL ) F_20 ( V_27 ) ;
if ( V_26 != NULL ) F_20 ( V_26 ) ;
EXIT ( V_7 ) ;
}
