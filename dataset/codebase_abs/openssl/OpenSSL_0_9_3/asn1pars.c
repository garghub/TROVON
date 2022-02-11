int MAIN ( int V_1 , char * * V_2 )
{
int V_3 , V_4 = 0 , V_5 = 0 , V_6 = 1 , V_7 ;
unsigned int V_8 = 0 ;
long V_9 , V_10 ;
T_1 * V_11 = NULL , * V_12 = NULL , * V_13 = NULL , * V_14 = NULL ;
int V_15 , V_16 = 0 ;
char * V_17 = NULL , * V_18 = NULL , * V_19 , * V_20 = NULL , * V_21 = NULL ;
unsigned char * V_22 ;
T_2 * V_23 = NULL ;
T_3 * V_24 = NULL ;
T_4 * V_25 = NULL ;
V_15 = V_26 ;
F_1 () ;
if ( V_27 == NULL )
if ( ( V_27 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_27 , V_28 , V_29 | V_30 ) ;
V_19 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
if ( ( V_24 = F_5 () ) == NULL )
{
F_6 ( V_27 , L_1 ) ;
goto V_31;
}
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_32;
V_15 = F_7 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_32;
V_17 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_32;
V_21 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
V_16 = 1 ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_32;
V_20 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_32;
V_5 = atoi ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_8 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_32;
V_8 = atoi ( * ( ++ V_2 ) ) ;
if ( V_8 == 0 ) goto V_32;
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_32;
F_8 ( V_24 , * ( ++ V_2 ) ) ;
}
else
{
F_6 ( V_27 , L_10 , * V_2 ) ;
V_4 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_4 )
{
V_32:
F_6 ( V_27 , L_11 , V_19 ) ;
F_6 ( V_27 , L_12 ) ;
F_6 ( V_27 , L_13 ) ;
F_6 ( V_27 , L_14 ) ;
F_6 ( V_27 , L_15 ) ;
F_6 ( V_27 , L_16 ) ;
F_6 ( V_27 , L_17 ) ;
F_6 ( V_27 , L_18 ) ;
F_6 ( V_27 , L_19 ) ;
F_6 ( V_27 , L_20 ) ;
F_6 ( V_27 , L_21 ) ;
F_6 ( V_27 , L_22 ) ;
goto V_31;
}
F_9 () ;
V_11 = F_2 ( F_3 () ) ;
V_12 = F_2 ( F_3 () ) ;
if ( ( V_11 == NULL ) || ( V_12 == NULL ) )
{
F_10 ( V_27 ) ;
goto V_31;
}
F_4 ( V_12 , stdout , V_29 | V_30 ) ;
if ( V_20 != NULL )
{
if ( F_11 ( V_11 , V_20 ) <= 0 )
{
F_6 ( V_27 , L_23 , V_20 ) ;
F_10 ( V_27 ) ;
goto V_31;
}
F_12 ( V_11 ) ;
}
if ( V_17 == NULL )
F_4 ( V_11 , V_33 , V_29 ) ;
else
{
if ( F_11 ( V_11 , V_17 ) <= 0 )
{
perror ( V_17 ) ;
goto V_31;
}
}
if ( V_21 ) {
if( ! ( V_14 = F_13 ( V_21 , L_24 ) ) ) {
F_6 ( V_27 , L_23 , V_21 ) ;
F_10 ( V_27 ) ;
goto V_31;
}
}
if ( ( V_23 = F_14 () ) == NULL ) goto V_31;
if ( ! F_15 ( V_23 , V_34 * 8 ) ) goto V_31;
if ( V_15 == V_26 )
{
T_1 * V_35 ;
if ( ( V_13 = F_2 ( F_16 () ) ) == NULL )
goto V_31;
F_17 ( V_13 , V_11 ) ;
V_35 = V_11 ;
V_11 = V_13 ;
V_13 = V_35 ;
}
V_9 = 0 ;
for (; ; )
{
if ( ! F_15 ( V_23 , ( int ) V_9 + V_34 ) ) goto V_31;
V_3 = F_18 ( V_11 , & ( V_23 -> V_36 [ V_9 ] ) , V_34 ) ;
if ( V_3 <= 0 ) break;
V_9 += V_3 ;
}
V_18 = V_23 -> V_36 ;
if ( F_19 ( V_24 ) )
{
V_22 = ( unsigned char * ) V_18 ;
V_10 = V_9 ;
for ( V_3 = 0 ; V_3 < F_19 ( V_24 ) ; V_3 ++ )
{
T_4 * V_37 ;
V_7 = atoi ( F_20 ( V_24 , V_3 ) ) ;
if ( V_7 == 0 )
{
F_6 ( V_27 , L_25 , F_20 ( V_24 , V_3 ) ) ;
continue;
}
V_22 += V_7 ;
V_10 -= V_7 ;
V_37 = V_25 ;
V_25 = F_21 ( NULL , & V_22 , V_10 ) ;
F_22 ( V_37 ) ;
if( ! V_25 )
{
F_6 ( V_27 , L_26 ) ;
F_10 ( V_27 ) ;
goto V_31;
}
V_22 = V_25 -> V_38 . V_39 -> V_36 ;
V_10 = V_25 -> V_38 . V_39 -> V_8 ;
}
V_18 = ( char * ) V_22 ;
V_9 = V_10 ;
}
if ( V_8 == 0 ) V_8 = ( unsigned int ) V_9 ;
if( V_14 ) {
if( F_23 ( V_14 , V_18 + V_5 , V_8 ) != ( int ) V_8 ) {
F_6 ( V_27 , L_27 ) ;
F_10 ( V_27 ) ;
goto V_31;
}
}
if ( ! F_24 ( V_12 , ( unsigned char * ) & ( V_18 [ V_5 ] ) , V_8 , V_16 ) )
{
F_10 ( V_27 ) ;
goto V_31;
}
V_6 = 0 ;
V_31:
F_25 ( V_14 ) ;
if ( V_11 != NULL ) F_25 ( V_11 ) ;
if ( V_12 != NULL ) F_25 ( V_12 ) ;
if ( V_13 != NULL ) F_25 ( V_13 ) ;
if ( V_6 != 0 )
F_10 ( V_27 ) ;
if ( V_23 != NULL ) F_26 ( V_23 ) ;
if ( V_25 != NULL ) F_22 ( V_25 ) ;
if ( V_24 != NULL ) F_27 ( V_24 ) ;
F_28 () ;
EXIT ( V_6 ) ;
}
