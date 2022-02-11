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
F_1 ( V_29 ) * V_30 = NULL ;
T_3 * V_31 = NULL ;
V_15 = V_32 ;
F_2 () ;
if ( V_33 == NULL )
if ( ( V_33 = F_3 ( F_4 () ) ) != NULL )
F_5 ( V_33 , V_34 , V_35 | V_36 ) ;
if ( ! F_6 ( V_33 , NULL ) )
goto V_37;
V_21 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
if ( ( V_30 = F_7 () ) == NULL )
{
F_8 ( V_33 , L_1 ) ;
goto V_37;
}
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_38;
V_15 = F_9 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_38;
V_19 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_38;
V_23 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
V_16 = 1 ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 ) V_17 = 1 ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_38;
V_22 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_8 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_38;
V_5 = atoi ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_38;
V_8 = atoi ( * ( ++ V_2 ) ) ;
if ( V_8 == 0 ) goto V_38;
}
else if ( strcmp ( * V_2 , L_10 ) == 0 )
{
V_18 = - 1 ;
}
else if ( strcmp ( * V_2 , L_11 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_38;
V_18 = atoi ( * ( ++ V_2 ) ) ;
if ( V_18 <= 0 ) goto V_38;
}
else if ( strcmp ( * V_2 , L_12 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_38;
F_10 ( V_30 , * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_13 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_38;
V_24 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_14 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_38;
V_25 = * ( ++ V_2 ) ;
}
else
{
F_8 ( V_33 , L_15 , * V_2 ) ;
V_4 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_4 )
{
V_38:
F_8 ( V_33 , L_16 , V_21 ) ;
F_8 ( V_33 , L_17 ) ;
F_8 ( V_33 , L_18 ) ;
F_8 ( V_33 , L_19 ) ;
F_8 ( V_33 , L_20 ) ;
F_8 ( V_33 , L_21 ) ;
F_8 ( V_33 , L_22 ) ;
F_8 ( V_33 , L_23 ) ;
F_8 ( V_33 , L_24 ) ;
F_8 ( V_33 , L_25 ) ;
F_8 ( V_33 , L_26 ) ;
F_8 ( V_33 , L_27 ) ;
F_8 ( V_33 , L_28 ) ;
F_8 ( V_33 , L_29 ) ;
F_8 ( V_33 , L_30 ) ;
F_8 ( V_33 , L_31 ) ;
F_8 ( V_33 , L_32 ) ;
goto V_37;
}
F_11 () ;
V_11 = F_3 ( F_4 () ) ;
V_12 = F_3 ( F_4 () ) ;
if ( ( V_11 == NULL ) || ( V_12 == NULL ) )
{
F_12 ( V_33 ) ;
goto V_37;
}
F_5 ( V_12 , stdout , V_35 | V_36 ) ;
#ifdef F_13
{
T_1 * V_39 = F_3 ( F_14 () ) ;
V_12 = F_15 ( V_39 , V_12 ) ;
}
#endif
if ( V_22 != NULL )
{
if ( F_16 ( V_11 , V_22 ) <= 0 )
{
F_8 ( V_33 , L_33 , V_22 ) ;
F_12 ( V_33 ) ;
goto V_37;
}
F_17 ( V_11 ) ;
}
if ( V_19 == NULL )
F_5 ( V_11 , V_40 , V_35 ) ;
else
{
if ( F_16 ( V_11 , V_19 ) <= 0 )
{
perror ( V_19 ) ;
goto V_37;
}
}
if ( V_23 ) {
if( ! ( V_14 = F_18 ( V_23 , L_34 ) ) ) {
F_8 ( V_33 , L_33 , V_23 ) ;
F_12 ( V_33 ) ;
goto V_37;
}
}
if ( ( V_28 = F_19 () ) == NULL ) goto V_37;
if ( ! F_20 ( V_28 , V_41 * 8 ) ) goto V_37;
if ( V_24 || V_25 )
{
V_9 = F_21 ( V_33 , V_24 , V_25 , V_28 ) ;
if ( V_9 < 0 )
{
F_12 ( V_33 ) ;
goto V_37;
}
}
else
{
if ( V_15 == V_32 )
{
T_1 * V_42 ;
if ( ( V_13 = F_3 ( F_22 () ) ) == NULL )
goto V_37;
F_15 ( V_13 , V_11 ) ;
V_42 = V_11 ;
V_11 = V_13 ;
V_13 = V_42 ;
}
V_9 = 0 ;
for (; ; )
{
if ( ! F_20 ( V_28 , ( int ) V_9 + V_41 ) ) goto V_37;
V_3 = F_23 ( V_11 , & ( V_28 -> V_43 [ V_9 ] ) , V_41 ) ;
if ( V_3 <= 0 ) break;
V_9 += V_3 ;
}
}
V_20 = V_28 -> V_43 ;
if ( F_24 ( V_30 ) )
{
V_26 = ( unsigned char * ) V_20 ;
V_10 = V_9 ;
for ( V_3 = 0 ; V_3 < F_24 ( V_30 ) ; V_3 ++ )
{
T_3 * V_44 ;
int V_45 ;
V_7 = atoi ( F_25 ( V_30 , V_3 ) ) ;
if ( V_7 == 0 )
{
F_8 ( V_33 , L_35 , F_25 ( V_30 , V_3 ) ) ;
continue;
}
V_26 += V_7 ;
V_10 -= V_7 ;
V_44 = V_31 ;
V_27 = V_26 ;
V_31 = F_26 ( NULL , & V_27 , V_10 ) ;
F_27 ( V_44 ) ;
if( ! V_31 )
{
F_8 ( V_33 , L_36 ) ;
F_12 ( V_33 ) ;
goto V_37;
}
V_45 = F_28 ( V_31 ) ;
if ( ( V_45 == V_46 )
|| ( V_45 == V_47 ) )
{
F_8 ( V_33 , L_37 ,
V_45 == V_47 ? L_38 : L_39 ) ;
F_12 ( V_33 ) ;
goto V_37;
}
V_26 = V_31 -> V_48 . V_49 -> V_43 ;
V_10 = V_31 -> V_48 . V_49 -> V_8 ;
}
V_20 = ( char * ) V_26 ;
V_9 = V_10 ;
}
if ( V_5 >= V_9 )
{
F_8 ( V_33 , L_40 ) ;
goto V_37;
}
V_9 -= V_5 ;
if ( ( V_8 == 0 ) || ( ( long ) V_8 > V_9 ) ) V_8 = ( unsigned int ) V_9 ;
if( V_14 ) {
if( F_29 ( V_14 , V_20 + V_5 , V_8 ) != ( int ) V_8 ) {
F_8 ( V_33 , L_41 ) ;
F_12 ( V_33 ) ;
goto V_37;
}
}
if ( ! V_17 &&
! F_30 ( V_12 , ( unsigned char * ) & ( V_20 [ V_5 ] ) , V_8 ,
V_16 , V_18 ) )
{
F_12 ( V_33 ) ;
goto V_37;
}
V_6 = 0 ;
V_37:
F_31 ( V_14 ) ;
if ( V_11 != NULL ) F_31 ( V_11 ) ;
if ( V_12 != NULL ) F_32 ( V_12 ) ;
if ( V_13 != NULL ) F_31 ( V_13 ) ;
if ( V_6 != 0 )
F_12 ( V_33 ) ;
if ( V_28 != NULL ) F_33 ( V_28 ) ;
if ( V_31 != NULL ) F_27 ( V_31 ) ;
if ( V_30 != NULL ) F_34 ( V_30 ) ;
F_35 () ;
F_36 () ;
F_37 ( V_6 ) ;
}
static int F_21 ( T_1 * V_50 , char * V_24 , char * V_25 , T_2 * V_28 )
{
T_4 * V_51 = NULL ;
int V_52 ;
long V_53 ;
unsigned char * V_54 ;
T_3 * V_55 = NULL ;
if ( V_25 )
{
V_51 = F_38 ( NULL ) ;
if ( ! F_39 ( V_51 , V_25 , & V_53 ) )
goto V_56;
if ( ! V_24 )
V_24 = F_40 ( V_51 , L_42 , L_43 ) ;
if ( ! V_24 )
{
F_8 ( V_50 , L_44 , V_25 ) ;
goto V_57;
}
}
V_55 = F_41 ( V_24 , V_51 ) ;
F_42 ( V_51 ) ;
V_51 = NULL ;
if ( ! V_55 )
return - 1 ;
V_52 = F_43 ( V_55 , NULL ) ;
if ( V_52 <= 0 )
goto V_57;
if ( ! F_20 ( V_28 , V_52 ) )
goto V_57;
V_54 = ( unsigned char * ) V_28 -> V_43 ;
F_43 ( V_55 , & V_54 ) ;
F_27 ( V_55 ) ;
return V_52 ;
V_56:
if ( V_53 > 0 )
F_8 ( V_50 , L_45 ,
V_53 , V_25 ) ;
else
F_8 ( V_50 , L_46 , V_25 ) ;
V_57:
F_42 ( V_51 ) ;
F_27 ( V_55 ) ;
return - 1 ;
}
