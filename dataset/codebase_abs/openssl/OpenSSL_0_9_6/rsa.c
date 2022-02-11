int MAIN ( int V_1 , char * * V_2 )
{
int V_3 = 1 ;
T_1 * V_4 = NULL ;
int V_5 , V_6 = 0 , V_7 = 0 ;
const T_2 * V_8 = NULL ;
T_3 * V_9 = NULL , * V_10 = NULL ;
int V_11 , V_12 , V_13 = 0 , V_14 = 0 , V_15 = 0 ;
int V_16 = 0 , V_17 = 0 ;
char * V_18 , * V_19 , * V_20 ;
char * V_21 = NULL , * V_22 = NULL ;
char * V_23 = NULL , * V_24 = NULL ;
int V_25 = 0 ;
F_1 () ;
if ( V_26 == NULL )
if ( ( V_26 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_26 , V_27 , V_28 | V_29 ) ;
V_18 = NULL ;
V_19 = NULL ;
V_11 = V_30 ;
V_12 = V_30 ;
V_20 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_31;
V_11 = F_5 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_31;
V_12 = F_5 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_31;
V_18 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_31;
V_19 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_31;
V_21 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_31;
V_22 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_7 = 1 ;
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_16 = 1 ;
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_17 = 1 ;
else if ( strcmp ( * V_2 , L_10 ) == 0 )
V_15 = 1 ;
else if ( strcmp ( * V_2 , L_11 ) == 0 )
V_13 = 1 ;
else if ( strcmp ( * V_2 , L_12 ) == 0 )
V_25 = 1 ;
else if ( strcmp ( * V_2 , L_13 ) == 0 )
V_14 = 1 ;
else if ( ( V_8 = F_6 ( & ( V_2 [ 0 ] [ 1 ] ) ) ) == NULL )
{
F_7 ( V_26 , L_14 , * V_2 ) ;
V_6 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_6 )
{
V_31:
F_7 ( V_26 , L_15 , V_20 ) ;
F_7 ( V_26 , L_16 ) ;
F_7 ( V_26 , L_17 ) ;
F_7 ( V_26 , L_18 ) ;
F_7 ( V_26 , L_19 ) ;
F_7 ( V_26 , L_20 ) ;
F_7 ( V_26 , L_21 ) ;
F_7 ( V_26 , L_22 ) ;
F_7 ( V_26 , L_23 ) ;
F_7 ( V_26 , L_24 ) ;
F_7 ( V_26 , L_25 ) ;
#ifndef F_8
F_7 ( V_26 , L_26 ) ;
#endif
F_7 ( V_26 , L_27 ) ;
F_7 ( V_26 , L_28 ) ;
F_7 ( V_26 , L_29 ) ;
F_7 ( V_26 , L_30 ) ;
F_7 ( V_26 , L_31 ) ;
F_7 ( V_26 , L_32 ) ;
goto V_32;
}
F_9 () ;
if( ! F_10 ( V_26 , V_21 , V_22 , & V_23 , & V_24 ) ) {
F_7 ( V_26 , L_33 ) ;
goto V_32;
}
if( V_14 && V_16 ) {
F_7 ( V_26 , L_34 ) ;
goto V_32;
}
V_9 = F_2 ( F_3 () ) ;
V_10 = F_2 ( F_3 () ) ;
if ( ( V_9 == NULL ) || ( V_10 == NULL ) )
{
F_11 ( V_26 ) ;
goto V_32;
}
if ( V_18 == NULL )
F_4 ( V_9 , V_33 , V_28 ) ;
else
{
if ( F_12 ( V_9 , V_18 ) <= 0 )
{
perror ( V_18 ) ;
goto V_32;
}
}
F_7 ( V_26 , L_35 ) ;
if ( V_11 == V_34 ) {
if ( V_16 ) V_4 = F_13 ( V_9 , NULL ) ;
else V_4 = F_14 ( V_9 , NULL ) ;
}
#ifndef F_15
else if ( V_11 == V_35 )
{
T_4 * V_36 = NULL ;
unsigned char * V_37 ;
int V_38 = 0 ;
V_36 = F_16 () ;
for (; ; )
{
if ( ( V_36 == NULL ) || ( ! F_17 ( V_36 , V_38 + 1024 * 10 ) ) )
goto V_32;
V_5 = F_18 ( V_9 , & ( V_36 -> V_39 [ V_38 ] ) , 1024 * 10 ) ;
V_38 += V_5 ;
if ( V_5 == 0 ) break;
if ( V_5 < 0 )
{
perror ( L_36 ) ;
F_19 ( V_36 ) ;
goto V_32;
}
}
V_37 = ( unsigned char * ) V_36 -> V_39 ;
V_4 = F_20 ( NULL , & V_37 , ( long ) V_38 , NULL , V_7 ) ;
F_19 ( V_36 ) ;
}
#endif
else if ( V_11 == V_30 ) {
if( V_16 ) V_4 = F_21 ( V_9 , NULL , NULL , NULL ) ;
else V_4 = F_22 ( V_9 , NULL , NULL , V_23 ) ;
}
else
{
F_7 ( V_26 , L_37 ) ;
goto V_32;
}
if ( V_4 == NULL )
{
F_7 ( V_26 , L_38 ) ;
F_11 ( V_26 ) ;
goto V_32;
}
if ( V_19 == NULL )
{
F_4 ( V_10 , stdout , V_28 ) ;
#ifdef F_23
{
T_3 * V_40 = F_2 ( F_24 () ) ;
V_10 = F_25 ( V_40 , V_10 ) ;
}
#endif
}
else
{
if ( F_26 ( V_10 , V_19 ) <= 0 )
{
perror ( V_19 ) ;
goto V_32;
}
}
if ( V_13 )
if ( ! F_27 ( V_10 , V_4 , 0 ) )
{
perror ( V_19 ) ;
F_11 ( V_26 ) ;
goto V_32;
}
if ( V_25 )
{
F_7 ( V_10 , L_39 ) ;
F_28 ( V_10 , V_4 -> V_41 ) ;
F_7 ( V_10 , L_40 ) ;
}
if ( V_14 )
{
int V_42 = F_29 ( V_4 ) ;
if ( V_42 == 1 )
F_7 ( V_10 , L_41 ) ;
else if ( V_42 == 0 )
{
long V_43 ;
while ( ( V_43 = F_30 () ) != 0 &&
F_31 ( V_43 ) == V_44 &&
F_32 ( V_43 ) == V_45 &&
F_33 ( V_43 ) != V_46 )
{
F_7 ( V_10 , L_42 , F_34 ( V_43 ) ) ;
F_35 () ;
}
}
if ( V_42 == - 1 || F_30 () != 0 )
{
F_11 ( V_26 ) ;
goto V_32;
}
}
if ( V_15 )
{
V_3 = 0 ;
goto V_32;
}
F_7 ( V_26 , L_43 ) ;
if ( V_12 == V_34 ) {
if( V_17 || V_16 ) V_5 = F_36 ( V_10 , V_4 ) ;
else V_5 = F_37 ( V_10 , V_4 ) ;
}
#ifndef F_15
else if ( V_12 == V_35 )
{
unsigned char * V_37 , * V_47 ;
int V_38 ;
V_5 = 1 ;
V_38 = F_38 ( V_4 , NULL , NULL , V_7 ) ;
if ( ( V_37 = ( unsigned char * ) F_39 ( V_38 ) ) == NULL )
{
F_7 ( V_26 , L_44 ) ;
goto V_32;
}
V_47 = V_37 ;
F_38 ( V_4 , & V_37 , NULL , V_7 ) ;
F_40 ( V_10 , ( char * ) V_47 , V_38 ) ;
F_41 ( V_47 ) ;
}
#endif
else if ( V_12 == V_30 ) {
if( V_17 || V_16 )
V_5 = F_42 ( V_10 , V_4 ) ;
else V_5 = F_43 ( V_10 , V_4 ,
V_8 , NULL , 0 , NULL , V_24 ) ;
} else {
F_7 ( V_26 , L_45 ) ;
goto V_32;
}
if ( ! V_5 )
{
F_7 ( V_26 , L_46 ) ;
F_11 ( V_26 ) ;
}
else
V_3 = 0 ;
V_32:
if( V_9 != NULL ) F_44 ( V_9 ) ;
if( V_10 != NULL ) F_45 ( V_10 ) ;
if( V_4 != NULL ) F_46 ( V_4 ) ;
if( V_23 ) F_41 ( V_23 ) ;
if( V_24 ) F_41 ( V_24 ) ;
EXIT ( V_3 ) ;
}
