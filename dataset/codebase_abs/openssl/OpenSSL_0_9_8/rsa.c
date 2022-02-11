int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 = 1 ;
T_2 * V_5 = NULL ;
int V_6 , V_7 = 0 , V_8 = 0 ;
const T_3 * V_9 = NULL ;
T_4 * V_10 = NULL ;
int V_11 , V_12 , V_13 = 0 , V_14 = 0 , V_15 = 0 ;
int V_16 = 0 , V_17 = 0 ;
char * V_18 , * V_19 , * V_20 ;
char * V_21 = NULL , * V_22 = NULL ;
char * V_23 = NULL , * V_24 = NULL ;
#ifndef F_1
char * V_25 = NULL ;
#endif
int V_26 = 0 ;
F_2 () ;
if ( V_27 == NULL )
if ( ( V_27 = F_3 ( F_4 () ) ) != NULL )
F_5 ( V_27 , V_28 , V_29 | V_30 ) ;
if ( ! F_6 ( V_27 , NULL ) )
goto V_31;
V_18 = NULL ;
V_19 = NULL ;
V_11 = V_32 ;
V_12 = V_32 ;
V_20 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_33;
V_11 = F_7 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_33;
V_12 = F_7 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_33;
V_18 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_33;
V_19 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_33;
V_21 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_33;
V_22 = * ( ++ V_2 ) ;
}
#ifndef F_1
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_33;
V_25 = * ( ++ V_2 ) ;
}
#endif
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_8 = 1 ;
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_16 = 1 ;
else if ( strcmp ( * V_2 , L_10 ) == 0 )
V_17 = 1 ;
else if ( strcmp ( * V_2 , L_11 ) == 0 )
V_15 = 1 ;
else if ( strcmp ( * V_2 , L_12 ) == 0 )
V_13 = 1 ;
else if ( strcmp ( * V_2 , L_13 ) == 0 )
V_26 = 1 ;
else if ( strcmp ( * V_2 , L_14 ) == 0 )
V_14 = 1 ;
else if ( ( V_9 = F_8 ( & ( V_2 [ 0 ] [ 1 ] ) ) ) == NULL )
{
F_9 ( V_27 , L_15 , * V_2 ) ;
V_7 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_7 )
{
V_33:
F_9 ( V_27 , L_16 , V_20 ) ;
F_9 ( V_27 , L_17 ) ;
F_9 ( V_27 , L_18 ) ;
F_9 ( V_27 , L_19 ) ;
F_9 ( V_27 , L_20 ) ;
F_9 ( V_27 , L_21 ) ;
F_9 ( V_27 , L_22 ) ;
F_9 ( V_27 , L_23 ) ;
F_9 ( V_27 , L_24 ) ;
F_9 ( V_27 , L_25 ) ;
F_9 ( V_27 , L_26 ) ;
#ifndef F_10
F_9 ( V_27 , L_27 ) ;
#endif
#ifndef F_11
F_9 ( V_27 , L_28 ) ;
F_9 ( V_27 , L_29 ) ;
#endif
F_9 ( V_27 , L_30 ) ;
F_9 ( V_27 , L_31 ) ;
F_9 ( V_27 , L_32 ) ;
F_9 ( V_27 , L_33 ) ;
F_9 ( V_27 , L_34 ) ;
F_9 ( V_27 , L_35 ) ;
#ifndef F_1
F_9 ( V_27 , L_36 ) ;
#endif
goto V_31;
}
F_12 () ;
#ifndef F_1
V_3 = F_13 ( V_27 , V_25 , 0 ) ;
#endif
if( ! F_14 ( V_27 , V_21 , V_22 , & V_23 , & V_24 ) ) {
F_9 ( V_27 , L_37 ) ;
goto V_31;
}
if( V_14 && V_16 ) {
F_9 ( V_27 , L_38 ) ;
goto V_31;
}
V_10 = F_3 ( F_4 () ) ;
{
T_5 * V_34 ;
if ( V_16 )
V_34 = F_15 ( V_27 , V_18 ,
( V_11 == V_35 && V_8 ?
V_36 : V_11 ) , 1 ,
V_23 , V_3 , L_39 ) ;
else
V_34 = F_16 ( V_27 , V_18 ,
( V_11 == V_35 && V_8 ?
V_36 : V_11 ) , 1 ,
V_23 , V_3 , L_40 ) ;
if ( V_34 != NULL )
V_5 = V_34 == NULL ? NULL : F_17 ( V_34 ) ;
F_18 ( V_34 ) ;
}
if ( V_5 == NULL )
{
F_19 ( V_27 ) ;
goto V_31;
}
if ( V_19 == NULL )
{
F_5 ( V_10 , stdout , V_29 ) ;
#ifdef F_20
{
T_4 * V_37 = F_3 ( F_21 () ) ;
V_10 = F_22 ( V_37 , V_10 ) ;
}
#endif
}
else
{
if ( F_23 ( V_10 , V_19 ) <= 0 )
{
perror ( V_19 ) ;
goto V_31;
}
}
if ( V_13 )
if ( ! F_24 ( V_10 , V_5 , 0 ) )
{
perror ( V_19 ) ;
F_19 ( V_27 ) ;
goto V_31;
}
if ( V_26 )
{
F_9 ( V_10 , L_41 ) ;
F_25 ( V_10 , V_5 -> V_38 ) ;
F_9 ( V_10 , L_42 ) ;
}
if ( V_14 )
{
int V_39 = F_26 ( V_5 ) ;
if ( V_39 == 1 )
F_9 ( V_10 , L_43 ) ;
else if ( V_39 == 0 )
{
unsigned long V_40 ;
while ( ( V_40 = F_27 () ) != 0 &&
F_28 ( V_40 ) == V_41 &&
F_29 ( V_40 ) == V_42 &&
F_30 ( V_40 ) != V_43 )
{
F_9 ( V_10 , L_44 , F_31 ( V_40 ) ) ;
F_32 () ;
}
}
if ( V_39 == - 1 || F_27 () != 0 )
{
F_19 ( V_27 ) ;
goto V_31;
}
}
if ( V_15 )
{
V_4 = 0 ;
goto V_31;
}
F_9 ( V_27 , L_45 ) ;
if ( V_12 == V_44 ) {
if( V_17 || V_16 ) V_6 = F_33 ( V_10 , V_5 ) ;
else V_6 = F_34 ( V_10 , V_5 ) ;
}
#ifndef F_35
else if ( V_12 == V_35 )
{
unsigned char * V_45 , * V_46 ;
int V_47 ;
V_6 = 1 ;
V_47 = F_36 ( V_5 , NULL , NULL , V_8 ) ;
if ( ( V_45 = ( unsigned char * ) F_37 ( V_47 ) ) == NULL )
{
F_9 ( V_27 , L_46 ) ;
goto V_31;
}
V_46 = V_45 ;
F_36 ( V_5 , & V_45 , NULL , V_8 ) ;
F_38 ( V_10 , ( char * ) V_46 , V_47 ) ;
F_39 ( V_46 ) ;
}
#endif
else if ( V_12 == V_32 ) {
if( V_17 || V_16 )
V_6 = F_40 ( V_10 , V_5 ) ;
else V_6 = F_41 ( V_10 , V_5 ,
V_9 , NULL , 0 , NULL , V_24 ) ;
} else {
F_9 ( V_27 , L_47 ) ;
goto V_31;
}
if ( ! V_6 )
{
F_9 ( V_27 , L_48 ) ;
F_19 ( V_27 ) ;
}
else
V_4 = 0 ;
V_31:
if( V_10 != NULL ) F_42 ( V_10 ) ;
if( V_5 != NULL ) F_43 ( V_5 ) ;
if( V_23 ) F_39 ( V_23 ) ;
if( V_24 ) F_39 ( V_24 ) ;
F_44 () ;
F_45 ( V_4 ) ;
}
