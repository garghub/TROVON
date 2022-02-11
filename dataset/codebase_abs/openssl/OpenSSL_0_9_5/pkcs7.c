int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 , V_5 = 0 ;
T_2 * V_6 = NULL , * V_7 = NULL ;
int V_8 , V_9 ;
char * V_10 , * V_11 , * V_12 ;
int V_13 = 0 , V_14 = 0 , V_15 = 0 ;
int V_16 = 0 ;
F_1 () ;
if ( V_17 == NULL )
if ( ( V_17 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_17 , V_18 , V_19 | V_20 ) ;
V_10 = NULL ;
V_11 = NULL ;
V_8 = V_21 ;
V_9 = V_21 ;
V_12 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_22;
V_8 = F_5 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_22;
V_9 = F_5 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_22;
V_10 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_22;
V_11 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
V_15 = 1 ;
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_14 = 1 ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_13 = 1 ;
else
{
F_6 ( V_17 , L_8 , * V_2 ) ;
V_5 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_5 )
{
V_22:
F_6 ( V_17 , L_9 , V_12 ) ;
F_6 ( V_17 , L_10 ) ;
F_6 ( V_17 , L_11 ) ;
F_6 ( V_17 , L_12 ) ;
F_6 ( V_17 , L_13 ) ;
F_6 ( V_17 , L_14 ) ;
F_6 ( V_17 , L_15 ) ;
F_6 ( V_17 , L_16 ) ;
F_6 ( V_17 , L_17 ) ;
EXIT ( 1 ) ;
}
F_7 () ;
V_6 = F_2 ( F_3 () ) ;
V_7 = F_2 ( F_3 () ) ;
if ( ( V_6 == NULL ) || ( V_7 == NULL ) )
{
F_8 ( V_17 ) ;
goto V_23;
}
if ( V_10 == NULL )
F_4 ( V_6 , V_24 , V_19 ) ;
else
{
if ( F_9 ( V_6 , V_10 ) <= 0 )
if ( V_6 == NULL )
{
perror ( V_10 ) ;
goto V_23;
}
}
if ( V_8 == V_25 )
V_3 = F_10 ( V_6 , NULL ) ;
else if ( V_8 == V_21 )
V_3 = F_11 ( V_6 , NULL , NULL , NULL ) ;
else
{
F_6 ( V_17 , L_18 ) ;
goto V_23;
}
if ( V_3 == NULL )
{
F_6 ( V_17 , L_19 ) ;
F_8 ( V_17 ) ;
goto V_23;
}
if ( V_11 == NULL )
F_4 ( V_7 , stdout , V_19 ) ;
else
{
if ( F_12 ( V_7 , V_11 ) <= 0 )
{
perror ( V_11 ) ;
goto V_23;
}
}
if ( V_13 )
{
F_13 ( V_26 ) * V_27 = NULL ;
F_13 ( V_28 ) * V_29 = NULL ;
V_4 = F_14 ( V_3 -> type ) ;
switch ( V_4 )
{
case V_30 :
V_27 = V_3 -> V_31 . V_32 -> V_33 ;
V_29 = V_3 -> V_31 . V_32 -> V_34 ;
break;
case V_35 :
V_27 = V_3 -> V_31 . V_36 -> V_33 ;
V_29 = V_3 -> V_31 . V_36 -> V_34 ;
break;
default:
break;
}
if ( V_27 != NULL )
{
V_26 * V_37 ;
for ( V_4 = 0 ; V_4 < F_15 ( V_27 ) ; V_4 ++ )
{
V_37 = F_16 ( V_27 , V_4 ) ;
if( V_14 ) F_17 ( V_7 , V_37 ) ;
else F_18 ( V_7 , V_37 ) ;
if( ! V_15 ) F_19 ( V_7 , V_37 ) ;
F_20 ( V_7 , L_20 ) ;
}
}
if ( V_29 != NULL )
{
V_28 * V_34 ;
for ( V_4 = 0 ; V_4 < F_21 ( V_29 ) ; V_4 ++ )
{
V_34 = F_22 ( V_29 , V_4 ) ;
F_23 ( V_7 , V_34 ) ;
if( ! V_15 ) F_24 ( V_7 , V_34 ) ;
F_20 ( V_7 , L_20 ) ;
}
}
V_16 = 0 ;
goto V_23;
}
if( ! V_15 ) {
if ( V_9 == V_25 )
V_4 = F_25 ( V_7 , V_3 ) ;
else if ( V_9 == V_21 )
V_4 = F_26 ( V_7 , V_3 ) ;
else {
F_6 ( V_17 , L_21 ) ;
goto V_23;
}
if ( ! V_4 )
{
F_6 ( V_17 , L_22 ) ;
F_8 ( V_17 ) ;
goto V_23;
}
}
V_16 = 0 ;
V_23:
if ( V_3 != NULL ) F_27 ( V_3 ) ;
if ( V_6 != NULL ) F_28 ( V_6 ) ;
if ( V_7 != NULL ) F_28 ( V_7 ) ;
EXIT ( V_16 ) ;
}
