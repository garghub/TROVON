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
int V_27 = 2 ;
F_2 () ;
if ( V_28 == NULL )
if ( ( V_28 = F_3 ( F_4 () ) ) != NULL )
F_5 ( V_28 , V_29 , V_30 | V_31 ) ;
if ( ! F_6 ( V_28 , NULL ) )
goto V_32;
V_18 = NULL ;
V_19 = NULL ;
V_11 = V_33 ;
V_12 = V_33 ;
V_20 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_34;
V_11 = F_7 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_34;
V_12 = F_7 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_34;
V_18 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_34;
V_19 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_34;
V_21 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_34;
V_22 = * ( ++ V_2 ) ;
}
#ifndef F_1
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_34;
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
V_16 = 2 ;
else if ( strcmp ( * V_2 , L_12 ) == 0 )
V_17 = 2 ;
else if ( strcmp ( * V_2 , L_13 ) == 0 )
V_27 = 2 ;
else if ( strcmp ( * V_2 , L_14 ) == 0 )
V_27 = 1 ;
else if ( strcmp ( * V_2 , L_15 ) == 0 )
V_27 = 0 ;
else if ( strcmp ( * V_2 , L_16 ) == 0 )
V_15 = 1 ;
else if ( strcmp ( * V_2 , L_17 ) == 0 )
V_13 = 1 ;
else if ( strcmp ( * V_2 , L_18 ) == 0 )
V_26 = 1 ;
else if ( strcmp ( * V_2 , L_19 ) == 0 )
V_14 = 1 ;
else if ( ( V_9 = F_8 ( & ( V_2 [ 0 ] [ 1 ] ) ) ) == NULL )
{
F_9 ( V_28 , L_20 , * V_2 ) ;
V_7 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_7 )
{
V_34:
F_9 ( V_28 , L_21 , V_20 ) ;
F_9 ( V_28 , L_22 ) ;
F_9 ( V_28 , L_23 ) ;
F_9 ( V_28 , L_24 ) ;
F_9 ( V_28 , L_25 ) ;
F_9 ( V_28 , L_26 ) ;
F_9 ( V_28 , L_27 ) ;
F_9 ( V_28 , L_28 ) ;
F_9 ( V_28 , L_29 ) ;
F_9 ( V_28 , L_30 ) ;
F_9 ( V_28 , L_31 ) ;
#ifndef F_10
F_9 ( V_28 , L_32 ) ;
#endif
#ifndef F_11
F_9 ( V_28 , L_33 ) ;
#endif
#ifndef F_12
F_9 ( V_28 , L_34 ) ;
F_9 ( V_28 , L_35 ) ;
#endif
#ifndef F_13
F_9 ( V_28 , L_36 ) ;
F_9 ( V_28 , L_37 ) ;
#endif
F_9 ( V_28 , L_38 ) ;
F_9 ( V_28 , L_39 ) ;
F_9 ( V_28 , L_40 ) ;
F_9 ( V_28 , L_41 ) ;
F_9 ( V_28 , L_42 ) ;
F_9 ( V_28 , L_43 ) ;
#ifndef F_1
F_9 ( V_28 , L_44 ) ;
#endif
goto V_32;
}
F_14 () ;
#ifndef F_1
V_3 = F_15 ( V_28 , V_25 , 0 ) ;
#endif
if( ! F_16 ( V_28 , V_21 , V_22 , & V_23 , & V_24 ) ) {
F_9 ( V_28 , L_45 ) ;
goto V_32;
}
if( V_14 && V_16 ) {
F_9 ( V_28 , L_46 ) ;
goto V_32;
}
V_10 = F_3 ( F_4 () ) ;
{
T_5 * V_35 ;
if ( V_16 )
{
int V_36 = - 1 ;
if ( V_16 == 2 )
{
if ( V_11 == V_33 )
V_36 = V_37 ;
else if ( V_11 == V_38 )
V_36 = V_39 ;
}
else if ( V_11 == V_40 && V_8 )
V_36 = V_41 ;
else
V_36 = V_11 ;
V_35 = F_17 ( V_28 , V_18 , V_36 , 1 ,
V_23 , V_3 , L_47 ) ;
}
else
V_35 = F_18 ( V_28 , V_18 ,
( V_11 == V_40 && V_8 ?
V_41 : V_11 ) , 1 ,
V_23 , V_3 , L_48 ) ;
if ( V_35 != NULL )
V_5 = F_19 ( V_35 ) ;
F_20 ( V_35 ) ;
}
if ( V_5 == NULL )
{
F_21 ( V_28 ) ;
goto V_32;
}
if ( V_19 == NULL )
{
F_5 ( V_10 , stdout , V_30 ) ;
#ifdef F_22
{
T_4 * V_42 = F_3 ( F_23 () ) ;
V_10 = F_24 ( V_42 , V_10 ) ;
}
#endif
}
else
{
if ( F_25 ( V_10 , V_19 ) <= 0 )
{
perror ( V_19 ) ;
goto V_32;
}
}
if ( V_13 )
if ( ! F_26 ( V_10 , V_5 , 0 ) )
{
perror ( V_19 ) ;
F_21 ( V_28 ) ;
goto V_32;
}
if ( V_26 )
{
F_9 ( V_10 , L_49 ) ;
F_27 ( V_10 , V_5 -> V_43 ) ;
F_9 ( V_10 , L_50 ) ;
}
if ( V_14 )
{
int V_44 = F_28 ( V_5 ) ;
if ( V_44 == 1 )
F_9 ( V_10 , L_51 ) ;
else if ( V_44 == 0 )
{
unsigned long V_45 ;
while ( ( V_45 = F_29 () ) != 0 &&
F_30 ( V_45 ) == V_46 &&
F_31 ( V_45 ) == V_47 &&
F_32 ( V_45 ) != V_48 )
{
F_9 ( V_10 , L_52 , F_33 ( V_45 ) ) ;
F_34 () ;
}
}
if ( V_44 == - 1 || F_29 () != 0 )
{
F_21 ( V_28 ) ;
goto V_32;
}
}
if ( V_15 )
{
V_4 = 0 ;
goto V_32;
}
F_9 ( V_28 , L_53 ) ;
if ( V_12 == V_38 ) {
if( V_17 || V_16 )
{
if ( V_17 == 2 )
V_6 = F_35 ( V_10 , V_5 ) ;
else
V_6 = F_36 ( V_10 , V_5 ) ;
}
else V_6 = F_37 ( V_10 , V_5 ) ;
}
#ifndef F_38
else if ( V_12 == V_40 )
{
unsigned char * V_49 , * V_50 ;
int V_51 ;
V_6 = 1 ;
V_51 = F_39 ( V_5 , NULL , NULL , V_8 ) ;
if ( ( V_49 = ( unsigned char * ) F_40 ( V_51 ) ) == NULL )
{
F_9 ( V_28 , L_54 ) ;
goto V_32;
}
V_50 = V_49 ;
F_39 ( V_5 , & V_49 , NULL , V_8 ) ;
F_41 ( V_10 , ( char * ) V_50 , V_51 ) ;
F_42 ( V_50 ) ;
}
#endif
else if ( V_12 == V_33 ) {
if( V_17 || V_16 )
{
if ( V_17 == 2 )
V_6 = F_43 ( V_10 , V_5 ) ;
else
V_6 = F_44 ( V_10 , V_5 ) ;
}
else V_6 = F_45 ( V_10 , V_5 ,
V_9 , NULL , 0 , NULL , V_24 ) ;
#if ! F_46 ( V_52 ) && ! F_46 ( F_38 )
} else if ( V_12 == V_53 || V_12 == V_54 ) {
T_5 * V_55 ;
V_55 = F_47 () ;
F_48 ( V_55 , V_5 ) ;
if ( V_12 == V_54 )
V_6 = F_49 ( V_10 , V_55 , V_27 , 0 , V_24 ) ;
else if ( V_16 || V_17 )
V_6 = F_50 ( V_10 , V_55 ) ;
else
V_6 = F_51 ( V_10 , V_55 ) ;
F_20 ( V_55 ) ;
#endif
} else {
F_9 ( V_28 , L_55 ) ;
goto V_32;
}
if ( V_6 <= 0 )
{
F_9 ( V_28 , L_56 ) ;
F_21 ( V_28 ) ;
}
else
V_4 = 0 ;
V_32:
if( V_10 != NULL ) F_52 ( V_10 ) ;
if( V_5 != NULL ) F_53 ( V_5 ) ;
if( V_23 ) F_42 ( V_23 ) ;
if( V_24 ) F_42 ( V_24 ) ;
F_54 () ;
F_55 ( V_4 ) ;
}
