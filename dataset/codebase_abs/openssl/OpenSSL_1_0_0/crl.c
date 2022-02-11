int MAIN ( int V_1 , char * * V_2 )
{
unsigned long V_3 = 0 ;
T_1 * V_4 = NULL ;
char * V_5 = NULL , * V_6 = NULL ;
int V_7 = 1 , V_8 , V_9 , V_10 = 0 ;
T_2 * V_11 = NULL ;
int V_12 , V_13 ;
char * V_14 = NULL , * V_15 = NULL ;
int V_16 = 0 , V_17 = 0 , V_18 = 0 , V_19 = 0 , V_20 = 0 , V_21 = 0 ;
int V_22 = 0 , V_23 = 0 ;
const char * * V_24 ;
T_3 * V_25 = NULL ;
T_4 V_26 ;
T_5 * V_27 = NULL ;
T_6 V_28 ;
T_7 * V_29 ;
int V_30 = 0 ;
const T_8 * V_31 , * V_32 = F_1 () ;
F_2 () ;
if ( V_33 == NULL )
if ( ( V_33 = F_3 ( F_4 () ) ) != NULL )
F_5 ( V_33 , V_34 , V_35 | V_36 ) ;
if ( ! F_6 ( V_33 , NULL ) )
goto V_37;
if ( V_38 == NULL )
if ( ( V_38 = F_3 ( F_4 () ) ) != NULL )
{
F_5 ( V_38 , stdout , V_35 ) ;
#ifdef F_7
{
T_2 * V_39 = F_3 ( F_8 () ) ;
V_38 = F_9 ( V_39 , V_38 ) ;
}
#endif
}
V_12 = V_40 ;
V_13 = V_40 ;
V_1 -- ;
V_2 ++ ;
V_9 = 0 ;
while ( V_1 >= 1 )
{
#ifdef undef
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_41;
if ( ! F_10 ( ++ V_2 , V_42 , V_43 ) ) { goto V_37; } * /
}
#endif
if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_41;
V_12 = F_11 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_41;
V_13 = F_11 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_41;
V_14 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_41;
V_15 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_41;
V_6 = * ( ++ V_2 ) ;
V_30 = 1 ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_41;
V_5 = * ( ++ V_2 ) ;
V_30 = 1 ;
}
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_30 = 1 ;
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_21 = 1 ;
else if ( strcmp ( * V_2 , L_10 ) == 0 )
V_16 = ++ V_9 ;
else if ( strcmp ( * V_2 , L_11 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_41;
if ( ! F_12 ( & V_3 , * ( ++ V_2 ) ) ) goto V_41;
}
else if ( strcmp ( * V_2 , L_12 ) == 0 )
V_17 = ++ V_9 ;
else if ( strcmp ( * V_2 , L_13 ) == 0 )
V_18 = ++ V_9 ;
else if ( strcmp ( * V_2 , L_14 ) == 0 )
V_19 = ++ V_9 ;
else if ( strcmp ( * V_2 , L_15 ) == 0 )
V_20 = ++ V_9 ;
else if ( strcmp ( * V_2 , L_16 ) == 0 )
V_22 = ++ V_9 ;
else if ( strcmp ( * V_2 , L_17 ) == 0 )
V_23 = ++ V_9 ;
else if ( ( V_31 = F_13 ( * V_2 + 1 ) ) )
{
V_32 = V_31 ;
}
else
{
F_14 ( V_33 , L_18 , * V_2 ) ;
V_10 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_10 )
{
V_41:
for ( V_24 = V_44 ; ( * V_24 != NULL ) ; V_24 ++ )
F_14 ( V_33 , L_19 , * V_24 ) ;
goto V_37;
}
F_15 () ;
V_4 = F_16 ( V_14 , V_12 ) ;
if ( V_4 == NULL ) { goto V_37; }
if( V_30 ) {
V_25 = F_17 () ;
V_27 = F_18 ( V_25 , F_19 () ) ;
if ( V_27 == NULL ) goto V_37;
if ( ! F_20 ( V_27 , V_5 , V_45 ) )
F_20 ( V_27 , NULL , V_46 ) ;
V_27 = F_18 ( V_25 , F_21 () ) ;
if ( V_27 == NULL ) goto V_37;
if ( ! F_22 ( V_27 , V_6 , V_45 ) )
F_22 ( V_27 , NULL , V_46 ) ;
F_23 () ;
if( ! F_24 ( & V_26 , V_25 , NULL , NULL ) ) {
F_14 ( V_33 ,
L_20 ) ;
goto V_37;
}
V_8 = F_25 ( & V_26 , V_47 ,
F_26 ( V_4 ) , & V_28 ) ;
if( V_8 <= 0 ) {
F_14 ( V_33 ,
L_21 ) ;
goto V_37;
}
V_29 = F_27 ( V_28 . V_48 . V_49 ) ;
F_28 ( & V_28 ) ;
if( ! V_29 ) {
F_14 ( V_33 ,
L_22 ) ;
goto V_37;
}
V_8 = F_29 ( V_4 , V_29 ) ;
F_30 ( V_29 ) ;
if( V_8 < 0 ) goto V_37;
if( V_8 == 0 ) F_14 ( V_33 , L_23 ) ;
else F_14 ( V_33 , L_24 ) ;
}
if ( V_9 )
{
for ( V_8 = 1 ; V_8 <= V_9 ; V_8 ++ )
{
if ( V_17 == V_8 )
{
F_31 ( V_38 , L_25 , F_26 ( V_4 ) , V_3 ) ;
}
if ( V_23 == V_8 )
{
T_9 * V_50 ;
V_50 = F_32 ( V_4 , V_51 ,
NULL , NULL ) ;
F_14 ( V_38 , L_26 ) ;
if ( V_50 )
{
F_33 ( V_38 , V_50 ) ;
F_34 ( V_50 ) ;
}
else
F_35 ( V_38 , L_27 ) ;
F_14 ( V_38 , L_28 ) ;
}
if ( V_16 == V_8 )
{
F_14 ( V_38 , L_29 ,
F_36 ( F_26 ( V_4 ) ) ) ;
}
if ( V_18 == V_8 )
{
F_14 ( V_38 , L_30 ) ;
F_37 ( V_38 ,
F_38 ( V_4 ) ) ;
F_14 ( V_38 , L_28 ) ;
}
if ( V_19 == V_8 )
{
F_14 ( V_38 , L_31 ) ;
if ( F_39 ( V_4 ) )
F_37 ( V_38 ,
F_39 ( V_4 ) ) ;
else
F_14 ( V_38 , L_32 ) ;
F_14 ( V_38 , L_28 ) ;
}
if ( V_22 == V_8 )
{
int V_52 ;
unsigned int V_53 ;
unsigned char V_54 [ V_55 ] ;
if ( ! F_40 ( V_4 , V_32 , V_54 , & V_53 ) )
{
F_14 ( V_33 , L_33 ) ;
goto V_37;
}
F_14 ( V_38 , L_34 ,
F_41 ( F_42 ( V_32 ) ) ) ;
for ( V_52 = 0 ; V_52 < ( int ) V_53 ; V_52 ++ )
{
F_14 ( V_38 , L_35 , V_54 [ V_52 ] ,
( V_52 + 1 == ( int ) V_53 )
? '\n' : ':' ) ;
}
}
}
}
V_11 = F_3 ( F_4 () ) ;
if ( V_11 == NULL )
{
F_43 ( V_33 ) ;
goto V_37;
}
if ( V_15 == NULL )
{
F_5 ( V_11 , stdout , V_35 ) ;
#ifdef F_7
{
T_2 * V_39 = F_3 ( F_8 () ) ;
V_11 = F_9 ( V_39 , V_11 ) ;
}
#endif
}
else
{
if ( F_44 ( V_11 , V_15 ) <= 0 )
{
perror ( V_15 ) ;
goto V_37;
}
}
if ( V_21 ) F_45 ( V_11 , V_4 ) ;
if ( V_20 )
{
V_7 = 0 ;
goto V_37;
}
if ( V_13 == V_56 )
V_8 = ( int ) F_46 ( V_11 , V_4 ) ;
else if ( V_13 == V_40 )
V_8 = F_47 ( V_11 , V_4 ) ;
else
{
F_14 ( V_33 , L_36 ) ;
goto V_37;
}
if ( ! V_8 ) { F_14 ( V_33 , L_37 ) ; goto V_37; }
V_7 = 0 ;
V_37:
F_48 ( V_11 ) ;
F_48 ( V_38 ) ;
V_38 = NULL ;
F_49 ( V_4 ) ;
if( V_25 ) {
F_50 ( & V_26 ) ;
F_51 ( V_25 ) ;
}
F_52 () ;
F_53 ( V_7 ) ;
}
static T_1 * F_16 ( char * V_14 , int V_57 )
{
T_1 * V_4 = NULL ;
T_2 * V_58 = NULL ;
V_58 = F_3 ( F_4 () ) ;
if ( V_58 == NULL )
{
F_43 ( V_33 ) ;
goto V_37;
}
if ( V_14 == NULL )
F_5 ( V_58 , V_59 , V_35 ) ;
else
{
if ( F_54 ( V_58 , V_14 ) <= 0 )
{
perror ( V_14 ) ;
goto V_37;
}
}
if ( V_57 == V_56 )
V_4 = F_55 ( V_58 , NULL ) ;
else if ( V_57 == V_40 )
V_4 = F_56 ( V_58 , NULL , NULL , NULL ) ;
else {
F_14 ( V_33 , L_38 ) ;
goto V_37;
}
if ( V_4 == NULL )
{
F_14 ( V_33 , L_39 ) ;
F_43 ( V_33 ) ;
goto V_37;
}
V_37:
F_57 ( V_58 ) ;
return ( V_4 ) ;
}
