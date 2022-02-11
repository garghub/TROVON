int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
char * V_4 = NULL , * V_5 = NULL ;
int V_6 = 1 , V_7 , V_8 , V_9 = 0 ;
T_2 * V_10 = NULL ;
int V_11 , V_12 ;
char * V_13 = NULL , * V_14 = NULL ;
int V_15 = 0 , V_16 = 0 , V_17 = 0 , V_18 = 0 , V_19 = 0 , V_20 = 0 ;
char * * V_21 , V_22 [ 256 ] ;
T_3 * V_23 = NULL ;
T_4 V_24 ;
T_5 * V_25 = NULL ;
T_6 V_26 ;
T_7 * V_27 ;
int V_28 = 0 ;
F_1 () ;
if ( V_29 == NULL )
if ( ( V_29 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_29 , V_30 , V_31 | V_32 ) ;
if ( V_33 == NULL )
if ( ( V_33 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_33 , stdout , V_31 ) ;
V_11 = V_34 ;
V_12 = V_34 ;
V_1 -- ;
V_2 ++ ;
V_8 = 0 ;
while ( V_1 >= 1 )
{
#ifdef undef
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_35;
if ( ! F_5 ( ++ V_2 , V_36 , V_37 ) ) { goto V_38; } * /
}
#endif
if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_35;
V_11 = F_6 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_35;
V_12 = F_6 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_35;
V_13 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_35;
V_14 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_35;
V_5 = * ( ++ V_2 ) ;
V_28 = 1 ;
}
else if ( strcmp ( * V_2 , L_7 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_35;
V_4 = * ( ++ V_2 ) ;
V_28 = 1 ;
}
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_28 = 1 ;
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
else
{
F_7 ( V_29 , L_15 , * V_2 ) ;
V_9 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_9 )
{
V_35:
for ( V_21 = V_39 ; ( * V_21 != NULL ) ; V_21 ++ )
F_7 ( V_29 , * V_21 ) ;
goto V_38;
}
F_8 () ;
V_3 = F_9 ( V_13 , V_11 ) ;
if ( V_3 == NULL ) { goto V_38; }
if( V_28 ) {
V_23 = F_10 () ;
V_25 = F_11 ( V_23 , F_12 () ) ;
if ( V_25 == NULL ) goto V_38;
if ( ! F_13 ( V_25 , V_4 , V_40 ) )
F_13 ( V_25 , NULL , V_41 ) ;
V_25 = F_11 ( V_23 , F_14 () ) ;
if ( V_25 == NULL ) goto V_38;
if ( ! F_15 ( V_25 , V_5 , V_40 ) )
F_15 ( V_25 , NULL , V_41 ) ;
F_16 () ;
F_17 ( & V_24 , V_23 , NULL , NULL ) ;
V_7 = F_18 ( & V_24 , V_42 ,
F_19 ( V_3 ) , & V_26 ) ;
if( V_7 <= 0 ) {
F_7 ( V_29 ,
L_16 ) ;
goto V_38;
}
V_27 = F_20 ( V_26 . V_43 . V_44 ) ;
F_21 ( & V_26 ) ;
if( ! V_27 ) {
F_7 ( V_29 ,
L_17 ) ;
goto V_38;
}
V_7 = F_22 ( V_3 , V_27 ) ;
F_23 ( V_27 ) ;
if( V_7 < 0 ) goto V_38;
if( V_7 == 0 ) F_7 ( V_29 , L_18 ) ;
else F_7 ( V_29 , L_19 ) ;
}
if ( V_8 )
{
for ( V_7 = 1 ; V_7 <= V_8 ; V_7 ++ )
{
if ( V_16 == V_7 )
{
F_24 ( F_19 ( V_3 ) ,
V_22 , 256 ) ;
F_7 ( V_33 , L_20 , V_22 ) ;
}
if ( V_15 == V_7 )
{
F_7 ( V_33 , L_21 ,
F_25 ( F_19 ( V_3 ) ) ) ;
}
if ( V_17 == V_7 )
{
F_7 ( V_33 , L_22 ) ;
F_26 ( V_33 ,
F_27 ( V_3 ) ) ;
F_7 ( V_33 , L_23 ) ;
}
if ( V_18 == V_7 )
{
F_7 ( V_33 , L_24 ) ;
if ( F_28 ( V_3 ) )
F_26 ( V_33 ,
F_28 ( V_3 ) ) ;
else
F_7 ( V_33 , L_25 ) ;
F_7 ( V_33 , L_23 ) ;
}
}
}
V_10 = F_2 ( F_3 () ) ;
if ( V_10 == NULL )
{
F_29 ( V_29 ) ;
goto V_38;
}
if ( V_14 == NULL )
F_4 ( V_10 , stdout , V_31 ) ;
else
{
if ( F_30 ( V_10 , V_14 ) <= 0 )
{
perror ( V_14 ) ;
goto V_38;
}
}
if ( V_20 ) F_31 ( V_10 , V_3 ) ;
if ( V_19 ) goto V_38;
if ( V_12 == V_45 )
V_7 = ( int ) F_32 ( V_10 , V_3 ) ;
else if ( V_12 == V_34 )
V_7 = F_33 ( V_10 , V_3 ) ;
else
{
F_7 ( V_29 , L_26 ) ;
goto V_38;
}
if ( ! V_7 ) { F_7 ( V_29 , L_27 ) ; goto V_38; }
V_6 = 0 ;
V_38:
F_34 ( V_10 ) ;
F_34 ( V_33 ) ;
V_33 = NULL ;
F_35 ( V_3 ) ;
if( V_23 ) {
F_36 ( & V_24 ) ;
F_37 ( V_23 ) ;
}
EXIT ( V_6 ) ;
}
static T_1 * F_9 ( char * V_13 , int V_46 )
{
T_1 * V_3 = NULL ;
T_2 * V_47 = NULL ;
V_47 = F_2 ( F_3 () ) ;
if ( V_47 == NULL )
{
F_29 ( V_29 ) ;
goto V_38;
}
if ( V_13 == NULL )
F_4 ( V_47 , V_48 , V_31 ) ;
else
{
if ( F_38 ( V_47 , V_13 ) <= 0 )
{
perror ( V_13 ) ;
goto V_38;
}
}
if ( V_46 == V_45 )
V_3 = F_39 ( V_47 , NULL ) ;
else if ( V_46 == V_34 )
V_3 = F_40 ( V_47 , NULL , NULL , NULL ) ;
else {
F_7 ( V_29 , L_28 ) ;
goto V_38;
}
if ( V_3 == NULL )
{
F_7 ( V_29 , L_29 ) ;
F_29 ( V_29 ) ;
goto V_38;
}
V_38:
F_34 ( V_47 ) ;
return ( V_3 ) ;
}
