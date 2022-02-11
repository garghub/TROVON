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
int V_22 = 0 ;
const char * * V_23 ;
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
if ( ! F_6 ( V_32 , NULL ) )
goto V_36;
if ( V_37 == NULL )
if ( ( V_37 = F_3 ( F_4 () ) ) != NULL )
{
F_5 ( V_37 , stdout , V_34 ) ;
#ifdef F_7
{
T_2 * V_38 = F_3 ( F_8 () ) ;
V_37 = F_9 ( V_38 , V_37 ) ;
}
#endif
}
V_12 = V_39 ;
V_13 = V_39 ;
V_1 -- ;
V_2 ++ ;
V_9 = 0 ;
while ( V_1 >= 1 )
{
#ifdef undef
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_40;
if ( ! F_10 ( ++ V_2 , V_41 , V_42 ) ) { goto V_36; } * /
}
#endif
if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_40;
V_12 = F_11 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_40;
V_13 = F_11 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_40;
V_14 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_40;
V_15 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_40;
V_6 = * ( ++ V_2 ) ;
V_29 = 1 ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_40;
V_5 = * ( ++ V_2 ) ;
V_29 = 1 ;
}
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_29 = 1 ;
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_21 = 1 ;
else if ( strcmp ( * V_2 , L_10 ) == 0 )
V_16 = ++ V_9 ;
else if ( strcmp ( * V_2 , L_11 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_40;
if ( ! F_12 ( & V_3 , * ( ++ V_2 ) ) ) goto V_40;
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
else if ( ( V_30 = F_13 ( * V_2 + 1 ) ) )
{
V_31 = V_30 ;
}
else
{
F_14 ( V_32 , L_17 , * V_2 ) ;
V_10 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_10 )
{
V_40:
for ( V_23 = V_43 ; ( * V_23 != NULL ) ; V_23 ++ )
F_14 ( V_32 , L_18 , * V_23 ) ;
goto V_36;
}
F_15 () ;
V_4 = F_16 ( V_14 , V_12 ) ;
if ( V_4 == NULL ) { goto V_36; }
if( V_29 ) {
V_24 = F_17 () ;
V_26 = F_18 ( V_24 , F_19 () ) ;
if ( V_26 == NULL ) goto V_36;
if ( ! F_20 ( V_26 , V_5 , V_44 ) )
F_20 ( V_26 , NULL , V_45 ) ;
V_26 = F_18 ( V_24 , F_21 () ) ;
if ( V_26 == NULL ) goto V_36;
if ( ! F_22 ( V_26 , V_6 , V_44 ) )
F_22 ( V_26 , NULL , V_45 ) ;
F_23 () ;
if( ! F_24 ( & V_25 , V_24 , NULL , NULL ) ) {
F_14 ( V_32 ,
L_19 ) ;
goto V_36;
}
V_8 = F_25 ( & V_25 , V_46 ,
F_26 ( V_4 ) , & V_27 ) ;
if( V_8 <= 0 ) {
F_14 ( V_32 ,
L_20 ) ;
goto V_36;
}
V_28 = F_27 ( V_27 . V_47 . V_48 ) ;
F_28 ( & V_27 ) ;
if( ! V_28 ) {
F_14 ( V_32 ,
L_21 ) ;
goto V_36;
}
V_8 = F_29 ( V_4 , V_28 ) ;
F_30 ( V_28 ) ;
if( V_8 < 0 ) goto V_36;
if( V_8 == 0 ) F_14 ( V_32 , L_22 ) ;
else F_14 ( V_32 , L_23 ) ;
}
if ( V_9 )
{
for ( V_8 = 1 ; V_8 <= V_9 ; V_8 ++ )
{
if ( V_17 == V_8 )
{
F_31 ( V_37 , L_24 , F_26 ( V_4 ) , V_3 ) ;
}
if ( V_16 == V_8 )
{
F_14 ( V_37 , L_25 ,
F_32 ( F_26 ( V_4 ) ) ) ;
}
if ( V_18 == V_8 )
{
F_14 ( V_37 , L_26 ) ;
F_33 ( V_37 ,
F_34 ( V_4 ) ) ;
F_14 ( V_37 , L_27 ) ;
}
if ( V_19 == V_8 )
{
F_14 ( V_37 , L_28 ) ;
if ( F_35 ( V_4 ) )
F_33 ( V_37 ,
F_35 ( V_4 ) ) ;
else
F_14 ( V_37 , L_29 ) ;
F_14 ( V_37 , L_27 ) ;
}
if ( V_22 == V_8 )
{
int V_49 ;
unsigned int V_50 ;
unsigned char V_51 [ V_52 ] ;
if ( ! F_36 ( V_4 , V_31 , V_51 , & V_50 ) )
{
F_14 ( V_32 , L_30 ) ;
goto V_36;
}
F_14 ( V_37 , L_31 ,
F_37 ( F_38 ( V_31 ) ) ) ;
for ( V_49 = 0 ; V_49 < ( int ) V_50 ; V_49 ++ )
{
F_14 ( V_37 , L_32 , V_51 [ V_49 ] ,
( V_49 + 1 == ( int ) V_50 )
? '\n' : ':' ) ;
}
}
}
}
V_11 = F_3 ( F_4 () ) ;
if ( V_11 == NULL )
{
F_39 ( V_32 ) ;
goto V_36;
}
if ( V_15 == NULL )
{
F_5 ( V_11 , stdout , V_34 ) ;
#ifdef F_7
{
T_2 * V_38 = F_3 ( F_8 () ) ;
V_11 = F_9 ( V_38 , V_11 ) ;
}
#endif
}
else
{
if ( F_40 ( V_11 , V_15 ) <= 0 )
{
perror ( V_15 ) ;
goto V_36;
}
}
if ( V_21 ) F_41 ( V_11 , V_4 ) ;
if ( V_20 )
{
V_7 = 0 ;
goto V_36;
}
if ( V_13 == V_53 )
V_8 = ( int ) F_42 ( V_11 , V_4 ) ;
else if ( V_13 == V_39 )
V_8 = F_43 ( V_11 , V_4 ) ;
else
{
F_14 ( V_32 , L_33 ) ;
goto V_36;
}
if ( ! V_8 ) { F_14 ( V_32 , L_34 ) ; goto V_36; }
V_7 = 0 ;
V_36:
F_44 ( V_11 ) ;
F_44 ( V_37 ) ;
V_37 = NULL ;
F_45 ( V_4 ) ;
if( V_24 ) {
F_46 ( & V_25 ) ;
F_47 ( V_24 ) ;
}
F_48 () ;
F_49 ( V_7 ) ;
}
static T_1 * F_16 ( char * V_14 , int V_54 )
{
T_1 * V_4 = NULL ;
T_2 * V_55 = NULL ;
V_55 = F_3 ( F_4 () ) ;
if ( V_55 == NULL )
{
F_39 ( V_32 ) ;
goto V_36;
}
if ( V_14 == NULL )
F_5 ( V_55 , V_56 , V_34 ) ;
else
{
if ( F_50 ( V_55 , V_14 ) <= 0 )
{
perror ( V_14 ) ;
goto V_36;
}
}
if ( V_54 == V_53 )
V_4 = F_51 ( V_55 , NULL ) ;
else if ( V_54 == V_39 )
V_4 = F_52 ( V_55 , NULL , NULL , NULL ) ;
else {
F_14 ( V_32 , L_35 ) ;
goto V_36;
}
if ( V_4 == NULL )
{
F_14 ( V_32 , L_36 ) ;
F_39 ( V_32 ) ;
goto V_36;
}
V_36:
F_53 ( V_55 ) ;
return ( V_4 ) ;
}
