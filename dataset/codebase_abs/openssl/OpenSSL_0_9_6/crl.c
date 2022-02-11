int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
char * V_4 = NULL , * V_5 = NULL ;
int V_6 = 1 , V_7 , V_8 , V_9 = 0 ;
T_2 * V_10 = NULL ;
int V_11 , V_12 ;
char * V_13 = NULL , * V_14 = NULL ;
int V_15 = 0 , V_16 = 0 , V_17 = 0 , V_18 = 0 , V_19 = 0 , V_20 = 0 ;
int V_21 = 0 ;
char * * V_22 , V_23 [ 256 ] ;
T_3 * V_24 = NULL ;
T_4 V_25 ;
T_5 * V_26 = NULL ;
T_6 V_27 ;
T_7 * V_28 ;
int V_29 = 0 ;
const T_8 * V_30 , * V_31 = F_1 () ;
F_2 () ;
if ( V_32 == NULL )
if ( ( V_32 = F_3 ( F_4 () ) ) != NULL )
F_5 ( V_32 , V_33 , V_34 | V_35 ) ;
if ( V_36 == NULL )
if ( ( V_36 = F_3 ( F_4 () ) ) != NULL )
{
F_5 ( V_36 , stdout , V_34 ) ;
#ifdef F_6
{
T_2 * V_37 = F_3 ( F_7 () ) ;
V_36 = F_8 ( V_37 , V_36 ) ;
}
#endif
}
V_11 = V_38 ;
V_12 = V_38 ;
V_1 -- ;
V_2 ++ ;
V_8 = 0 ;
while ( V_1 >= 1 )
{
#ifdef undef
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_39;
if ( ! F_9 ( ++ V_2 , V_40 , V_41 ) ) { goto V_42; } * /
}
#endif
if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_39;
V_11 = F_10 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_39;
V_12 = F_10 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_39;
V_13 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_39;
V_14 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_39;
V_5 = * ( ++ V_2 ) ;
V_29 = 1 ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_39;
V_4 = * ( ++ V_2 ) ;
V_29 = 1 ;
}
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_29 = 1 ;
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_20 = 1 ;
else if ( strcmp ( * V_2 , L_10 ) == 0 )
V_15 = ++ V_8 ;
else if ( strcmp ( * V_2 , L_11 ) == 0 )
V_16 = ++ V_8 ;
else if ( strcmp ( * V_2 , L_12 ) == 0 )
V_17 = ++ V_8 ;
else if ( strcmp ( * V_2 , L_13 ) == 0 )
V_18 = ++ V_8 ;
else if ( strcmp ( * V_2 , L_14 ) == 0 )
V_19 = ++ V_8 ;
else if ( strcmp ( * V_2 , L_15 ) == 0 )
V_21 = ++ V_8 ;
else if ( ( V_30 = F_11 ( * V_2 + 1 ) ) )
{
V_31 = V_30 ;
}
else
{
F_12 ( V_32 , L_16 , * V_2 ) ;
V_9 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_9 )
{
V_39:
for ( V_22 = V_43 ; ( * V_22 != NULL ) ; V_22 ++ )
F_12 ( V_32 , * V_22 ) ;
goto V_42;
}
F_13 () ;
V_3 = F_14 ( V_13 , V_11 ) ;
if ( V_3 == NULL ) { goto V_42; }
if( V_29 ) {
V_24 = F_15 () ;
V_26 = F_16 ( V_24 , F_17 () ) ;
if ( V_26 == NULL ) goto V_42;
if ( ! F_18 ( V_26 , V_4 , V_44 ) )
F_18 ( V_26 , NULL , V_45 ) ;
V_26 = F_16 ( V_24 , F_19 () ) ;
if ( V_26 == NULL ) goto V_42;
if ( ! F_20 ( V_26 , V_5 , V_44 ) )
F_20 ( V_26 , NULL , V_45 ) ;
F_21 () ;
F_22 ( & V_25 , V_24 , NULL , NULL ) ;
V_7 = F_23 ( & V_25 , V_46 ,
F_24 ( V_3 ) , & V_27 ) ;
if( V_7 <= 0 ) {
F_12 ( V_32 ,
L_17 ) ;
goto V_42;
}
V_28 = F_25 ( V_27 . V_47 . V_48 ) ;
F_26 ( & V_27 ) ;
if( ! V_28 ) {
F_12 ( V_32 ,
L_18 ) ;
goto V_42;
}
V_7 = F_27 ( V_3 , V_28 ) ;
F_28 ( V_28 ) ;
if( V_7 < 0 ) goto V_42;
if( V_7 == 0 ) F_12 ( V_32 , L_19 ) ;
else F_12 ( V_32 , L_20 ) ;
}
if ( V_8 )
{
for ( V_7 = 1 ; V_7 <= V_8 ; V_7 ++ )
{
if ( V_16 == V_7 )
{
F_29 ( F_24 ( V_3 ) ,
V_23 , 256 ) ;
F_12 ( V_36 , L_21 , V_23 ) ;
}
if ( V_15 == V_7 )
{
F_12 ( V_36 , L_22 ,
F_30 ( F_24 ( V_3 ) ) ) ;
}
if ( V_17 == V_7 )
{
F_12 ( V_36 , L_23 ) ;
F_31 ( V_36 ,
F_32 ( V_3 ) ) ;
F_12 ( V_36 , L_24 ) ;
}
if ( V_18 == V_7 )
{
F_12 ( V_36 , L_25 ) ;
if ( F_33 ( V_3 ) )
F_31 ( V_36 ,
F_33 ( V_3 ) ) ;
else
F_12 ( V_36 , L_26 ) ;
F_12 ( V_36 , L_24 ) ;
}
if ( V_21 == V_7 )
{
int V_49 ;
unsigned int V_50 ;
unsigned char V_51 [ V_52 ] ;
if ( ! F_34 ( V_3 , V_31 , V_51 , & V_50 ) )
{
F_12 ( V_32 , L_27 ) ;
goto V_42;
}
F_12 ( V_36 , L_28 ,
F_35 ( F_36 ( V_31 ) ) ) ;
for ( V_49 = 0 ; V_49 < ( int ) V_50 ; V_49 ++ )
{
F_12 ( V_36 , L_29 , V_51 [ V_49 ] ,
( V_49 + 1 == ( int ) V_50 )
? '\n' : ':' ) ;
}
}
}
}
V_10 = F_3 ( F_4 () ) ;
if ( V_10 == NULL )
{
F_37 ( V_32 ) ;
goto V_42;
}
if ( V_14 == NULL )
{
F_5 ( V_10 , stdout , V_34 ) ;
#ifdef F_6
{
T_2 * V_37 = F_3 ( F_7 () ) ;
V_10 = F_8 ( V_37 , V_10 ) ;
}
#endif
}
else
{
if ( F_38 ( V_10 , V_14 ) <= 0 )
{
perror ( V_14 ) ;
goto V_42;
}
}
if ( V_20 ) F_39 ( V_10 , V_3 ) ;
if ( V_19 ) goto V_42;
if ( V_12 == V_53 )
V_7 = ( int ) F_40 ( V_10 , V_3 ) ;
else if ( V_12 == V_38 )
V_7 = F_41 ( V_10 , V_3 ) ;
else
{
F_12 ( V_32 , L_30 ) ;
goto V_42;
}
if ( ! V_7 ) { F_12 ( V_32 , L_31 ) ; goto V_42; }
V_6 = 0 ;
V_42:
F_42 ( V_10 ) ;
F_42 ( V_36 ) ;
V_36 = NULL ;
F_43 ( V_3 ) ;
if( V_24 ) {
F_44 ( & V_25 ) ;
F_45 ( V_24 ) ;
}
EXIT ( V_6 ) ;
}
static T_1 * F_14 ( char * V_13 , int V_54 )
{
T_1 * V_3 = NULL ;
T_2 * V_55 = NULL ;
V_55 = F_3 ( F_4 () ) ;
if ( V_55 == NULL )
{
F_37 ( V_32 ) ;
goto V_42;
}
if ( V_13 == NULL )
F_5 ( V_55 , V_56 , V_34 ) ;
else
{
if ( F_46 ( V_55 , V_13 ) <= 0 )
{
perror ( V_13 ) ;
goto V_42;
}
}
if ( V_54 == V_53 )
V_3 = F_47 ( V_55 , NULL ) ;
else if ( V_54 == V_38 )
V_3 = F_48 ( V_55 , NULL , NULL , NULL ) ;
else {
F_12 ( V_32 , L_32 ) ;
goto V_42;
}
if ( V_3 == NULL )
{
F_12 ( V_32 , L_33 ) ;
F_37 ( V_32 ) ;
goto V_42;
}
V_42:
F_49 ( V_55 ) ;
return ( V_3 ) ;
}
