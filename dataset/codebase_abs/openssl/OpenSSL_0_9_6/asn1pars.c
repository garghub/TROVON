int MAIN ( int V_1 , char * * V_2 )
{
int V_3 , V_4 = 0 , V_5 = 0 , V_6 = 1 , V_7 ;
unsigned int V_8 = 0 ;
long V_9 , V_10 ;
T_1 * V_11 = NULL , * V_12 = NULL , * V_13 = NULL , * V_14 = NULL ;
int V_15 , V_16 = 0 , V_17 = 0 , V_18 = 0 ;
char * V_19 = NULL , * V_20 = NULL , * V_21 , * V_22 = NULL , * V_23 = NULL ;
unsigned char * V_24 ;
T_2 * V_25 = NULL ;
T_3 * V_26 = NULL ;
T_4 * V_27 = NULL ;
V_15 = V_28 ;
F_1 () ;
if ( V_29 == NULL )
if ( ( V_29 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_29 , V_30 , V_31 | V_32 ) ;
V_21 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
if ( ( V_26 = F_5 () ) == NULL )
{
F_6 ( V_29 , L_1 ) ;
goto V_33;
}
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_34;
V_15 = F_7 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_34;
V_19 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_34;
V_23 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
V_16 = 1 ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 ) V_17 = 1 ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_34;
V_22 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_8 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_34;
V_5 = atoi ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_34;
V_8 = atoi ( * ( ++ V_2 ) ) ;
if ( V_8 == 0 ) goto V_34;
}
else if ( strcmp ( * V_2 , L_10 ) == 0 )
{
V_18 = - 1 ;
}
else if ( strcmp ( * V_2 , L_11 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_34;
V_18 = atoi ( * ( ++ V_2 ) ) ;
if ( V_18 <= 0 ) goto V_34;
}
else if ( strcmp ( * V_2 , L_12 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_34;
F_8 ( V_26 , * ( ++ V_2 ) ) ;
}
else
{
F_6 ( V_29 , L_13 , * V_2 ) ;
V_4 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_4 )
{
V_34:
F_6 ( V_29 , L_14 , V_21 ) ;
F_6 ( V_29 , L_15 ) ;
F_6 ( V_29 , L_16 ) ;
F_6 ( V_29 , L_17 ) ;
F_6 ( V_29 , L_18 ) ;
F_6 ( V_29 , L_19 ) ;
F_6 ( V_29 , L_20 ) ;
F_6 ( V_29 , L_21 ) ;
F_6 ( V_29 , L_22 ) ;
F_6 ( V_29 , L_23 ) ;
F_6 ( V_29 , L_24 ) ;
F_6 ( V_29 , L_25 ) ;
F_6 ( V_29 , L_26 ) ;
F_6 ( V_29 , L_27 ) ;
F_6 ( V_29 , L_28 ) ;
F_6 ( V_29 , L_29 ) ;
goto V_33;
}
F_9 () ;
V_11 = F_2 ( F_3 () ) ;
V_12 = F_2 ( F_3 () ) ;
if ( ( V_11 == NULL ) || ( V_12 == NULL ) )
{
F_10 ( V_29 ) ;
goto V_33;
}
F_4 ( V_12 , stdout , V_31 | V_32 ) ;
#ifdef F_11
{
T_1 * V_35 = F_2 ( F_12 () ) ;
V_12 = F_13 ( V_35 , V_12 ) ;
}
#endif
if ( V_22 != NULL )
{
if ( F_14 ( V_11 , V_22 ) <= 0 )
{
F_6 ( V_29 , L_30 , V_22 ) ;
F_10 ( V_29 ) ;
goto V_33;
}
F_15 ( V_11 ) ;
}
if ( V_19 == NULL )
F_4 ( V_11 , V_36 , V_31 ) ;
else
{
if ( F_14 ( V_11 , V_19 ) <= 0 )
{
perror ( V_19 ) ;
goto V_33;
}
}
if ( V_23 ) {
if( ! ( V_14 = F_16 ( V_23 , L_31 ) ) ) {
F_6 ( V_29 , L_30 , V_23 ) ;
F_10 ( V_29 ) ;
goto V_33;
}
}
if ( ( V_25 = F_17 () ) == NULL ) goto V_33;
if ( ! F_18 ( V_25 , V_37 * 8 ) ) goto V_33;
if ( V_15 == V_28 )
{
T_1 * V_38 ;
if ( ( V_13 = F_2 ( F_19 () ) ) == NULL )
goto V_33;
F_13 ( V_13 , V_11 ) ;
V_38 = V_11 ;
V_11 = V_13 ;
V_13 = V_38 ;
}
V_9 = 0 ;
for (; ; )
{
if ( ! F_18 ( V_25 , ( int ) V_9 + V_37 ) ) goto V_33;
V_3 = F_20 ( V_11 , & ( V_25 -> V_39 [ V_9 ] ) , V_37 ) ;
if ( V_3 <= 0 ) break;
V_9 += V_3 ;
}
V_20 = V_25 -> V_39 ;
if ( F_21 ( V_26 ) )
{
V_24 = ( unsigned char * ) V_20 ;
V_10 = V_9 ;
for ( V_3 = 0 ; V_3 < F_21 ( V_26 ) ; V_3 ++ )
{
T_4 * V_40 ;
V_7 = atoi ( F_22 ( V_26 , V_3 ) ) ;
if ( V_7 == 0 )
{
F_6 ( V_29 , L_32 , F_22 ( V_26 , V_3 ) ) ;
continue;
}
V_24 += V_7 ;
V_10 -= V_7 ;
V_40 = V_27 ;
V_27 = F_23 ( NULL , & V_24 , V_10 ) ;
F_24 ( V_40 ) ;
if( ! V_27 )
{
F_6 ( V_29 , L_33 ) ;
F_10 ( V_29 ) ;
goto V_33;
}
V_24 = V_27 -> V_41 . V_42 -> V_39 ;
V_10 = V_27 -> V_41 . V_42 -> V_8 ;
}
V_20 = ( char * ) V_24 ;
V_9 = V_10 ;
}
if ( V_8 == 0 ) V_8 = ( unsigned int ) V_9 ;
if( V_14 ) {
if( F_25 ( V_14 , V_20 + V_5 , V_8 ) != ( int ) V_8 ) {
F_6 ( V_29 , L_34 ) ;
F_10 ( V_29 ) ;
goto V_33;
}
}
if ( ! V_17 &&
! F_26 ( V_12 , ( unsigned char * ) & ( V_20 [ V_5 ] ) , V_8 ,
V_16 , V_18 ) )
{
F_10 ( V_29 ) ;
goto V_33;
}
V_6 = 0 ;
V_33:
F_27 ( V_14 ) ;
if ( V_11 != NULL ) F_27 ( V_11 ) ;
if ( V_12 != NULL ) F_28 ( V_12 ) ;
if ( V_13 != NULL ) F_27 ( V_13 ) ;
if ( V_6 != 0 )
F_10 ( V_29 ) ;
if ( V_25 != NULL ) F_29 ( V_25 ) ;
if ( V_27 != NULL ) F_24 ( V_27 ) ;
if ( V_26 != NULL ) F_30 ( V_26 ) ;
F_31 () ;
EXIT ( V_6 ) ;
}
