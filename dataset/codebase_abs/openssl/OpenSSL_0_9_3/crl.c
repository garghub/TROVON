int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 = 1 , V_5 , V_6 , V_7 = 0 ;
T_2 * V_8 = NULL ;
int V_9 , V_10 ;
char * V_11 = NULL , * V_12 = NULL ;
int V_13 = 0 , V_14 = 0 , V_15 = 0 , V_16 = 0 , V_17 = 0 , V_18 = 0 ;
char * * V_19 , V_20 [ 256 ] ;
F_1 () ;
if ( V_21 == NULL )
if ( ( V_21 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_21 , V_22 , V_23 | V_24 ) ;
if ( V_25 == NULL )
if ( ( V_25 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_25 , stdout , V_23 ) ;
V_9 = V_26 ;
V_10 = V_26 ;
V_1 -- ;
V_2 ++ ;
V_6 = 0 ;
while ( V_1 >= 1 )
{
#ifdef undef
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_27;
if ( ! F_5 ( ++ V_2 , V_28 , V_29 ) ) { goto V_30; } * /
}
#endif
if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_27;
V_9 = F_6 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_27;
V_10 = F_6 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_27;
V_11 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_27;
V_12 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_18 = 1 ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_13 = ++ V_6 ;
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_14 = ++ V_6 ;
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_15 = ++ V_6 ;
else if ( strcmp ( * V_2 , L_10 ) == 0 )
V_16 = ++ V_6 ;
else if ( strcmp ( * V_2 , L_11 ) == 0 )
V_17 = ++ V_6 ;
else
{
F_7 ( V_21 , L_12 , * V_2 ) ;
V_7 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_7 )
{
V_27:
for ( V_19 = V_31 ; ( * V_19 != NULL ) ; V_19 ++ )
F_7 ( V_21 , * V_19 ) ;
goto V_30;
}
F_8 () ;
F_9 () ;
V_3 = F_10 ( V_11 , V_9 ) ;
if ( V_3 == NULL ) { goto V_30; }
if ( V_6 )
{
for ( V_5 = 1 ; V_5 <= V_6 ; V_5 ++ )
{
if ( V_14 == V_5 )
{
F_11 ( V_3 -> V_32 -> V_14 , V_20 , 256 ) ;
F_7 ( V_25 , L_13 , V_20 ) ;
}
if ( V_13 == V_5 )
{
F_7 ( V_25 , L_14 ,
F_12 ( V_3 -> V_32 -> V_14 ) ) ;
}
if ( V_15 == V_5 )
{
F_7 ( V_25 , L_15 ) ;
F_13 ( V_25 , V_3 -> V_32 -> V_33 ) ;
F_7 ( V_25 , L_16 ) ;
}
if ( V_16 == V_5 )
{
F_7 ( V_25 , L_17 ) ;
if ( V_3 -> V_32 -> V_34 != NULL )
F_13 ( V_25 , V_3 -> V_32 -> V_34 ) ;
else
F_7 ( V_25 , L_18 ) ;
F_7 ( V_25 , L_16 ) ;
}
}
}
V_8 = F_2 ( F_3 () ) ;
if ( V_8 == NULL )
{
F_14 ( V_21 ) ;
goto V_30;
}
if ( V_12 == NULL )
F_4 ( V_8 , stdout , V_23 ) ;
else
{
if ( F_15 ( V_8 , V_12 ) <= 0 )
{
perror ( V_12 ) ;
goto V_30;
}
}
if ( V_18 ) F_16 ( V_8 , V_3 ) ;
if ( V_17 ) goto V_30;
if ( V_10 == V_35 )
V_5 = ( int ) F_17 ( V_8 , V_3 ) ;
else if ( V_10 == V_26 )
V_5 = F_18 ( V_8 , V_3 ) ;
else
{
F_7 ( V_21 , L_19 ) ;
goto V_30;
}
if ( ! V_5 ) { F_7 ( V_21 , L_20 ) ; goto V_30; }
V_4 = 0 ;
V_30:
F_19 ( V_8 ) ;
F_19 ( V_25 ) ;
F_20 ( V_3 ) ;
F_21 () ;
EXIT ( V_4 ) ;
}
static T_1 * F_10 ( char * V_11 , int V_36 )
{
T_1 * V_3 = NULL ;
T_2 * V_37 = NULL ;
V_37 = F_2 ( F_3 () ) ;
if ( V_37 == NULL )
{
F_14 ( V_21 ) ;
goto V_30;
}
if ( V_11 == NULL )
F_4 ( V_37 , V_38 , V_23 ) ;
else
{
if ( F_22 ( V_37 , V_11 ) <= 0 )
{
perror ( V_11 ) ;
goto V_30;
}
}
if ( V_36 == V_35 )
V_3 = F_23 ( V_37 , NULL ) ;
else if ( V_36 == V_26 )
V_3 = F_24 ( V_37 , NULL , NULL ) ;
else {
F_7 ( V_21 , L_21 ) ;
goto V_30;
}
if ( V_3 == NULL )
{
F_7 ( V_21 , L_22 ) ;
F_14 ( V_21 ) ;
goto V_30;
}
V_30:
F_19 ( V_37 ) ;
return ( V_3 ) ;
}
