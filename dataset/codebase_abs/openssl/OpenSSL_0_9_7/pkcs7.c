int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
T_2 * V_4 = NULL ;
int V_5 , V_6 = 0 ;
T_3 * V_7 = NULL , * V_8 = NULL ;
int V_9 , V_10 ;
char * V_11 , * V_12 , * V_13 ;
int V_14 = 0 , V_15 = 0 , V_16 = 0 ;
int V_17 = 1 ;
char * V_18 = NULL ;
F_1 () ;
if ( V_19 == NULL )
if ( ( V_19 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_19 , V_20 , V_21 | V_22 ) ;
V_11 = NULL ;
V_12 = NULL ;
V_9 = V_23 ;
V_10 = V_23 ;
V_13 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_24;
V_9 = F_5 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_24;
V_10 = F_5 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_24;
V_11 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_24;
V_12 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
V_16 = 1 ;
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_15 = 1 ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_14 = 1 ;
else if ( strcmp ( * V_2 , L_8 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_24;
V_18 = * ( ++ V_2 ) ;
}
else
{
F_6 ( V_19 , L_9 , * V_2 ) ;
V_6 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_6 )
{
V_24:
F_6 ( V_19 , L_10 , V_13 ) ;
F_6 ( V_19 , L_11 ) ;
F_6 ( V_19 , L_12 ) ;
F_6 ( V_19 , L_13 ) ;
F_6 ( V_19 , L_14 ) ;
F_6 ( V_19 , L_15 ) ;
F_6 ( V_19 , L_16 ) ;
F_6 ( V_19 , L_17 ) ;
F_6 ( V_19 , L_18 ) ;
F_6 ( V_19 , L_19 ) ;
V_17 = 1 ;
goto V_25;
}
F_7 () ;
V_3 = F_8 ( V_19 , V_18 , 0 ) ;
V_7 = F_2 ( F_3 () ) ;
V_8 = F_2 ( F_3 () ) ;
if ( ( V_7 == NULL ) || ( V_8 == NULL ) )
{
F_9 ( V_19 ) ;
goto V_25;
}
if ( V_11 == NULL )
F_4 ( V_7 , V_26 , V_21 ) ;
else
{
if ( F_10 ( V_7 , V_11 ) <= 0 )
if ( V_7 == NULL )
{
perror ( V_11 ) ;
goto V_25;
}
}
if ( V_9 == V_27 )
V_4 = F_11 ( V_7 , NULL ) ;
else if ( V_9 == V_23 )
V_4 = F_12 ( V_7 , NULL , NULL , NULL ) ;
else
{
F_6 ( V_19 , L_20 ) ;
goto V_25;
}
if ( V_4 == NULL )
{
F_6 ( V_19 , L_21 ) ;
F_9 ( V_19 ) ;
goto V_25;
}
if ( V_12 == NULL )
{
F_4 ( V_8 , stdout , V_21 ) ;
#ifdef F_13
{
T_3 * V_28 = F_2 ( F_14 () ) ;
V_8 = F_15 ( V_28 , V_8 ) ;
}
#endif
}
else
{
if ( F_16 ( V_8 , V_12 ) <= 0 )
{
perror ( V_12 ) ;
goto V_25;
}
}
if ( V_14 )
{
F_17 ( V_29 ) * V_30 = NULL ;
F_17 ( V_31 ) * V_32 = NULL ;
V_5 = F_18 ( V_4 -> type ) ;
switch ( V_5 )
{
case V_33 :
V_30 = V_4 -> V_34 . V_35 -> V_36 ;
V_32 = V_4 -> V_34 . V_35 -> V_37 ;
break;
case V_38 :
V_30 = V_4 -> V_34 . V_39 -> V_36 ;
V_32 = V_4 -> V_34 . V_39 -> V_37 ;
break;
default:
break;
}
if ( V_30 != NULL )
{
V_29 * V_40 ;
for ( V_5 = 0 ; V_5 < F_19 ( V_30 ) ; V_5 ++ )
{
V_40 = F_20 ( V_30 , V_5 ) ;
if( V_15 ) F_21 ( V_8 , V_40 ) ;
else F_22 ( V_8 , V_40 ) ;
if( ! V_16 ) F_23 ( V_8 , V_40 ) ;
F_24 ( V_8 , L_22 ) ;
}
}
if ( V_32 != NULL )
{
V_31 * V_37 ;
for ( V_5 = 0 ; V_5 < F_25 ( V_32 ) ; V_5 ++ )
{
V_37 = F_26 ( V_32 , V_5 ) ;
F_27 ( V_8 , V_37 ) ;
if( ! V_16 ) F_28 ( V_8 , V_37 ) ;
F_24 ( V_8 , L_22 ) ;
}
}
V_17 = 0 ;
goto V_25;
}
if( ! V_16 ) {
if ( V_10 == V_27 )
V_5 = F_29 ( V_8 , V_4 ) ;
else if ( V_10 == V_23 )
V_5 = F_30 ( V_8 , V_4 ) ;
else {
F_6 ( V_19 , L_23 ) ;
goto V_25;
}
if ( ! V_5 )
{
F_6 ( V_19 , L_24 ) ;
F_9 ( V_19 ) ;
goto V_25;
}
}
V_17 = 0 ;
V_25:
if ( V_4 != NULL ) F_31 ( V_4 ) ;
if ( V_7 != NULL ) F_32 ( V_7 ) ;
if ( V_8 != NULL ) F_33 ( V_8 ) ;
F_34 () ;
F_35 ( V_17 ) ;
}
