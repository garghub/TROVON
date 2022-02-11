int MAIN ( int V_1 , char * * V_2 )
{
int V_3 = 1 ;
T_1 * V_4 = NULL ;
int V_5 , V_6 = 0 ;
const T_2 * V_7 = NULL ;
T_3 * V_8 = NULL , * V_9 = NULL ;
int V_10 , V_11 , V_12 = 0 , V_13 = 0 , V_14 = 0 ;
int V_15 = 0 , V_16 = 0 ;
char * V_17 , * V_18 , * V_19 ;
char * V_20 = NULL , * V_21 = NULL ;
char * V_22 = NULL , * V_23 = NULL ;
int V_24 = 0 ;
F_1 () ;
if ( V_25 == NULL )
if ( ( V_25 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_25 , V_26 , V_27 | V_28 ) ;
V_17 = NULL ;
V_18 = NULL ;
V_10 = V_29 ;
V_11 = V_29 ;
V_19 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_30;
V_10 = F_5 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_30;
V_11 = F_5 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_30;
V_17 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_30;
V_18 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_30;
V_20 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_30;
V_21 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_15 = 1 ;
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_16 = 1 ;
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_14 = 1 ;
else if ( strcmp ( * V_2 , L_10 ) == 0 )
V_12 = 1 ;
else if ( strcmp ( * V_2 , L_11 ) == 0 )
V_24 = 1 ;
else if ( strcmp ( * V_2 , L_12 ) == 0 )
V_13 = 1 ;
else if ( ( V_7 = F_6 ( & ( V_2 [ 0 ] [ 1 ] ) ) ) == NULL )
{
F_7 ( V_25 , L_13 , * V_2 ) ;
V_6 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_6 )
{
V_30:
F_7 ( V_25 , L_14 , V_19 ) ;
F_7 ( V_25 , L_15 ) ;
F_7 ( V_25 , L_16 ) ;
F_7 ( V_25 , L_17 ) ;
F_7 ( V_25 , L_18 ) ;
F_7 ( V_25 , L_19 ) ;
F_7 ( V_25 , L_18 ) ;
F_7 ( V_25 , L_20 ) ;
F_7 ( V_25 , L_21 ) ;
F_7 ( V_25 , L_22 ) ;
F_7 ( V_25 , L_23 ) ;
#ifndef F_8
F_7 ( V_25 , L_24 ) ;
#endif
F_7 ( V_25 , L_25 ) ;
F_7 ( V_25 , L_26 ) ;
F_7 ( V_25 , L_27 ) ;
F_7 ( V_25 , L_28 ) ;
F_7 ( V_25 , L_29 ) ;
F_7 ( V_25 , L_30 ) ;
goto V_31;
}
F_9 () ;
if( ! F_10 ( V_25 , V_20 , V_21 , & V_22 , & V_23 ) ) {
F_7 ( V_25 , L_31 ) ;
goto V_31;
}
if( V_13 && V_15 ) {
F_7 ( V_25 , L_32 ) ;
goto V_31;
}
V_8 = F_2 ( F_3 () ) ;
V_9 = F_2 ( F_3 () ) ;
if ( ( V_8 == NULL ) || ( V_9 == NULL ) )
{
F_11 ( V_25 ) ;
goto V_31;
}
if ( V_17 == NULL )
F_4 ( V_8 , V_32 , V_27 ) ;
else
{
if ( F_12 ( V_8 , V_17 ) <= 0 )
{
perror ( V_17 ) ;
goto V_31;
}
}
F_7 ( V_25 , L_33 ) ;
if ( V_10 == V_33 ) {
if ( V_15 ) V_4 = F_13 ( V_8 , NULL ) ;
else V_4 = F_14 ( V_8 , NULL ) ;
}
#ifndef F_15
else if ( V_10 == V_34 )
{
T_4 * V_35 = NULL ;
unsigned char * V_36 ;
int V_37 = 0 ;
V_35 = F_16 () ;
for (; ; )
{
if ( ( V_35 == NULL ) || ( ! F_17 ( V_35 , V_37 + 1024 * 10 ) ) )
goto V_31;
V_5 = F_18 ( V_8 , & ( V_35 -> V_38 [ V_37 ] ) , 1024 * 10 ) ;
V_37 += V_5 ;
if ( V_5 == 0 ) break;
if ( V_5 < 0 )
{
perror ( L_34 ) ;
F_19 ( V_35 ) ;
goto V_31;
}
}
V_36 = ( unsigned char * ) V_35 -> V_38 ;
V_4 = F_20 ( NULL , & V_36 , ( long ) V_37 , NULL ) ;
F_19 ( V_35 ) ;
}
#endif
else if ( V_10 == V_29 ) {
if( V_15 ) V_4 = F_21 ( V_8 , NULL , NULL , NULL ) ;
else V_4 = F_22 ( V_8 , NULL , NULL , V_22 ) ;
}
else
{
F_7 ( V_25 , L_35 ) ;
goto V_31;
}
if ( V_4 == NULL )
{
F_7 ( V_25 , L_36 ) ;
F_11 ( V_25 ) ;
goto V_31;
}
if ( V_18 == NULL )
F_4 ( V_9 , stdout , V_27 ) ;
else
{
if ( F_23 ( V_9 , V_18 ) <= 0 )
{
perror ( V_18 ) ;
goto V_31;
}
}
if ( V_12 )
if ( ! F_24 ( V_9 , V_4 , 0 ) )
{
perror ( V_18 ) ;
F_11 ( V_25 ) ;
goto V_31;
}
if ( V_24 )
{
F_7 ( V_9 , L_37 ) ;
F_25 ( V_9 , V_4 -> V_39 ) ;
F_7 ( V_9 , L_38 ) ;
}
if ( V_13 )
{
int V_40 = F_26 ( V_4 ) ;
if ( V_40 == 1 )
F_7 ( V_9 , L_39 ) ;
else if ( V_40 == 0 )
{
long V_41 ;
while ( ( V_41 = F_27 () ) != 0 &&
F_28 ( V_41 ) == V_42 &&
F_29 ( V_41 ) == V_43 &&
F_30 ( V_41 ) != V_44 )
{
F_7 ( V_9 , L_40 , F_31 ( V_41 ) ) ;
F_32 () ;
}
}
if ( V_40 == - 1 || F_27 () != 0 )
{
F_11 ( V_25 ) ;
goto V_31;
}
}
if ( V_14 )
{
V_3 = 0 ;
goto V_31;
}
F_7 ( V_25 , L_41 ) ;
if ( V_11 == V_33 ) {
if( V_16 || V_15 ) V_5 = F_33 ( V_9 , V_4 ) ;
else V_5 = F_34 ( V_9 , V_4 ) ;
}
#ifndef F_15
else if ( V_11 == V_34 )
{
unsigned char * V_36 , * V_45 ;
int V_37 ;
V_5 = 1 ;
V_37 = F_35 ( V_4 , NULL , NULL ) ;
if ( ( V_36 = ( unsigned char * ) Malloc ( V_37 ) ) == NULL )
{
F_7 ( V_25 , L_42 ) ;
goto V_31;
}
V_45 = V_36 ;
F_35 ( V_4 , & V_36 , NULL ) ;
F_36 ( V_9 , ( char * ) V_45 , V_37 ) ;
Free ( V_45 ) ;
}
#endif
else if ( V_11 == V_29 ) {
if( V_16 || V_15 )
V_5 = F_37 ( V_9 , V_4 ) ;
else V_5 = F_38 ( V_9 , V_4 ,
V_7 , NULL , 0 , NULL , V_23 ) ;
} else {
F_7 ( V_25 , L_43 ) ;
goto V_31;
}
if ( ! V_5 )
{
F_7 ( V_25 , L_44 ) ;
F_11 ( V_25 ) ;
}
else
V_3 = 0 ;
V_31:
if( V_8 != NULL ) F_39 ( V_8 ) ;
if( V_9 != NULL ) F_39 ( V_9 ) ;
if( V_4 != NULL ) F_40 ( V_4 ) ;
if( V_22 ) Free ( V_22 ) ;
if( V_23 ) Free ( V_23 ) ;
EXIT ( V_3 ) ;
}
