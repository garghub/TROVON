int MAIN ( int V_1 , char * * V_2 )
{
int V_3 , V_4 = 0 , V_5 = 0 , V_6 = 1 , V_7 ;
unsigned int V_8 = 0 ;
long V_9 , V_10 ;
T_1 * V_11 = NULL , * V_12 = NULL , * V_13 = NULL , * V_14 = NULL ;
int V_15 , V_16 = 0 , V_17 = 0 , V_18 = 0 ;
char * V_19 = NULL , * V_20 = NULL , * V_21 , * V_22 = NULL , * V_23 = NULL ;
char * V_24 = NULL , * V_25 = NULL ;
unsigned char * V_26 ;
const unsigned char * V_27 ;
T_2 * V_28 = NULL ;
T_3 * V_29 = NULL ;
T_4 * V_30 = NULL ;
V_15 = V_31 ;
F_1 () ;
if ( V_32 == NULL )
if ( ( V_32 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_32 , V_33 , V_34 | V_35 ) ;
if ( ! F_5 ( V_32 , NULL ) )
goto V_36;
V_21 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
if ( ( V_29 = F_6 () ) == NULL )
{
F_7 ( V_32 , L_1 ) ;
goto V_36;
}
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_37;
V_15 = F_8 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_37;
V_19 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_37;
V_23 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
V_16 = 1 ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 ) V_17 = 1 ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_37;
V_22 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_8 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_37;
V_5 = atoi ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_37;
V_8 = atoi ( * ( ++ V_2 ) ) ;
if ( V_8 == 0 ) goto V_37;
}
else if ( strcmp ( * V_2 , L_10 ) == 0 )
{
V_18 = - 1 ;
}
else if ( strcmp ( * V_2 , L_11 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_37;
V_18 = atoi ( * ( ++ V_2 ) ) ;
if ( V_18 <= 0 ) goto V_37;
}
else if ( strcmp ( * V_2 , L_12 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_37;
F_9 ( V_29 , * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_13 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_37;
V_24 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_14 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_37;
V_25 = * ( ++ V_2 ) ;
}
else
{
F_7 ( V_32 , L_15 , * V_2 ) ;
V_4 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_4 )
{
V_37:
F_7 ( V_32 , L_16 , V_21 ) ;
F_7 ( V_32 , L_17 ) ;
F_7 ( V_32 , L_18 ) ;
F_7 ( V_32 , L_19 ) ;
F_7 ( V_32 , L_20 ) ;
F_7 ( V_32 , L_21 ) ;
F_7 ( V_32 , L_22 ) ;
F_7 ( V_32 , L_23 ) ;
F_7 ( V_32 , L_24 ) ;
F_7 ( V_32 , L_25 ) ;
F_7 ( V_32 , L_26 ) ;
F_7 ( V_32 , L_27 ) ;
F_7 ( V_32 , L_28 ) ;
F_7 ( V_32 , L_29 ) ;
F_7 ( V_32 , L_30 ) ;
F_7 ( V_32 , L_31 ) ;
F_7 ( V_32 , L_32 ) ;
goto V_36;
}
F_10 () ;
V_11 = F_2 ( F_3 () ) ;
V_12 = F_2 ( F_3 () ) ;
if ( ( V_11 == NULL ) || ( V_12 == NULL ) )
{
F_11 ( V_32 ) ;
goto V_36;
}
F_4 ( V_12 , stdout , V_34 | V_35 ) ;
#ifdef F_12
{
T_1 * V_38 = F_2 ( F_13 () ) ;
V_12 = F_14 ( V_38 , V_12 ) ;
}
#endif
if ( V_22 != NULL )
{
if ( F_15 ( V_11 , V_22 ) <= 0 )
{
F_7 ( V_32 , L_33 , V_22 ) ;
F_11 ( V_32 ) ;
goto V_36;
}
F_16 ( V_11 ) ;
}
if ( V_19 == NULL )
F_4 ( V_11 , V_39 , V_34 ) ;
else
{
if ( F_15 ( V_11 , V_19 ) <= 0 )
{
perror ( V_19 ) ;
goto V_36;
}
}
if ( V_23 ) {
if( ! ( V_14 = F_17 ( V_23 , L_34 ) ) ) {
F_7 ( V_32 , L_33 , V_23 ) ;
F_11 ( V_32 ) ;
goto V_36;
}
}
if ( ( V_28 = F_18 () ) == NULL ) goto V_36;
if ( ! F_19 ( V_28 , V_40 * 8 ) ) goto V_36;
if ( V_24 || V_25 )
{
V_9 = F_20 ( V_32 , V_24 , V_25 , V_28 ) ;
if ( V_9 < 0 )
{
F_11 ( V_32 ) ;
goto V_36;
}
}
else
{
if ( V_15 == V_31 )
{
T_1 * V_41 ;
if ( ( V_13 = F_2 ( F_21 () ) ) == NULL )
goto V_36;
F_14 ( V_13 , V_11 ) ;
V_41 = V_11 ;
V_11 = V_13 ;
V_13 = V_41 ;
}
V_9 = 0 ;
for (; ; )
{
if ( ! F_19 ( V_28 , ( int ) V_9 + V_40 ) ) goto V_36;
V_3 = F_22 ( V_11 , & ( V_28 -> V_42 [ V_9 ] ) , V_40 ) ;
if ( V_3 <= 0 ) break;
V_9 += V_3 ;
}
}
V_20 = V_28 -> V_42 ;
if ( F_23 ( V_29 ) )
{
V_26 = ( unsigned char * ) V_20 ;
V_10 = V_9 ;
for ( V_3 = 0 ; V_3 < F_23 ( V_29 ) ; V_3 ++ )
{
T_4 * V_43 ;
int V_44 ;
V_7 = atoi ( F_24 ( V_29 , V_3 ) ) ;
if ( V_7 == 0 )
{
F_7 ( V_32 , L_35 , F_24 ( V_29 , V_3 ) ) ;
continue;
}
V_26 += V_7 ;
V_10 -= V_7 ;
V_43 = V_30 ;
V_27 = V_26 ;
V_30 = F_25 ( NULL , & V_27 , V_10 ) ;
F_26 ( V_43 ) ;
if( ! V_30 )
{
F_7 ( V_32 , L_36 ) ;
F_11 ( V_32 ) ;
goto V_36;
}
V_44 = F_27 ( V_30 ) ;
if ( ( V_44 == V_45 )
|| ( V_44 == V_46 ) )
{
F_7 ( V_32 , L_37 ,
V_44 == V_46 ? L_38 : L_39 ) ;
F_11 ( V_32 ) ;
goto V_36;
}
V_26 = V_30 -> V_47 . V_48 -> V_42 ;
V_10 = V_30 -> V_47 . V_48 -> V_8 ;
}
V_20 = ( char * ) V_26 ;
V_9 = V_10 ;
}
if ( V_5 >= V_9 )
{
F_7 ( V_32 , L_40 ) ;
goto V_36;
}
V_9 -= V_5 ;
if ( ( V_8 == 0 ) || ( ( long ) V_8 > V_9 ) ) V_8 = ( unsigned int ) V_9 ;
if( V_14 ) {
if( F_28 ( V_14 , V_20 + V_5 , V_8 ) != ( int ) V_8 ) {
F_7 ( V_32 , L_41 ) ;
F_11 ( V_32 ) ;
goto V_36;
}
}
if ( ! V_17 &&
! F_29 ( V_12 , ( unsigned char * ) & ( V_20 [ V_5 ] ) , V_8 ,
V_16 , V_18 ) )
{
F_11 ( V_32 ) ;
goto V_36;
}
V_6 = 0 ;
V_36:
F_30 ( V_14 ) ;
if ( V_11 != NULL ) F_30 ( V_11 ) ;
if ( V_12 != NULL ) F_31 ( V_12 ) ;
if ( V_13 != NULL ) F_30 ( V_13 ) ;
if ( V_6 != 0 )
F_11 ( V_32 ) ;
if ( V_28 != NULL ) F_32 ( V_28 ) ;
if ( V_30 != NULL ) F_26 ( V_30 ) ;
if ( V_29 != NULL ) F_33 ( V_29 ) ;
F_34 () ;
F_35 () ;
F_36 ( V_6 ) ;
}
static int F_20 ( T_1 * V_49 , char * V_24 , char * V_25 , T_2 * V_28 )
{
T_5 * V_50 = NULL ;
int V_51 ;
long V_52 ;
unsigned char * V_53 ;
T_4 * V_54 = NULL ;
if ( V_25 )
{
V_50 = F_37 ( NULL ) ;
if ( ! F_38 ( V_50 , V_25 , & V_52 ) )
goto V_55;
if ( ! V_24 )
V_24 = F_39 ( V_50 , L_42 , L_43 ) ;
if ( ! V_24 )
{
F_7 ( V_49 , L_44 , V_25 ) ;
goto V_56;
}
}
V_54 = F_40 ( V_24 , V_50 ) ;
F_41 ( V_50 ) ;
if ( ! V_54 )
return - 1 ;
V_51 = F_42 ( V_54 , NULL ) ;
if ( V_51 <= 0 )
goto V_56;
if ( ! F_19 ( V_28 , V_51 ) )
goto V_56;
V_53 = ( unsigned char * ) V_28 -> V_42 ;
F_42 ( V_54 , & V_53 ) ;
F_26 ( V_54 ) ;
return V_51 ;
V_55:
if ( V_52 > 0 )
F_7 ( V_49 , L_45 ,
V_52 , V_25 ) ;
else
F_7 ( V_49 , L_46 , V_25 ) ;
V_56:
F_41 ( V_50 ) ;
F_26 ( V_54 ) ;
return - 1 ;
}
