int MAIN ( int V_1 , char * * V_2 )
{
#ifndef F_1
T_1 * V_3 = NULL ;
#endif
T_2 * V_4 = NULL ;
int V_5 , V_6 = 0 ;
T_3 * V_7 = NULL , * V_8 = NULL ;
int V_9 , V_10 ;
char * V_11 , * V_12 , * V_13 ;
int V_14 = 0 , V_15 = 0 , V_16 = 0 , V_17 = 0 ;
int V_18 = 1 ;
#ifndef F_1
char * V_19 = NULL ;
#endif
F_2 () ;
if ( V_20 == NULL )
if ( ( V_20 = F_3 ( F_4 () ) ) != NULL )
F_5 ( V_20 , V_21 , V_22 | V_23 ) ;
if ( ! F_6 ( V_20 , NULL ) )
goto V_24;
V_11 = NULL ;
V_12 = NULL ;
V_9 = V_25 ;
V_10 = V_25 ;
V_13 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_26;
V_9 = F_7 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_26;
V_10 = F_7 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_26;
V_11 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_26;
V_12 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
V_16 = 1 ;
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_15 = 1 ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_17 = 1 ;
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_14 = 1 ;
#ifndef F_1
else if ( strcmp ( * V_2 , L_9 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_26;
V_19 = * ( ++ V_2 ) ;
}
#endif
else
{
F_8 ( V_20 , L_10 , * V_2 ) ;
V_6 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_6 )
{
V_26:
F_8 ( V_20 , L_11 , V_13 ) ;
F_8 ( V_20 , L_12 ) ;
F_8 ( V_20 , L_13 ) ;
F_8 ( V_20 , L_14 ) ;
F_8 ( V_20 , L_15 ) ;
F_8 ( V_20 , L_16 ) ;
F_8 ( V_20 , L_17 ) ;
F_8 ( V_20 , L_18 ) ;
F_8 ( V_20 , L_19 ) ;
#ifndef F_1
F_8 ( V_20 , L_20 ) ;
#endif
V_18 = 1 ;
goto V_24;
}
F_9 () ;
#ifndef F_1
V_3 = F_10 ( V_20 , V_19 , 0 ) ;
#endif
V_7 = F_3 ( F_4 () ) ;
V_8 = F_3 ( F_4 () ) ;
if ( ( V_7 == NULL ) || ( V_8 == NULL ) )
{
F_11 ( V_20 ) ;
goto V_24;
}
if ( V_11 == NULL )
F_5 ( V_7 , V_27 , V_22 ) ;
else
{
if ( F_12 ( V_7 , V_11 ) <= 0 )
if ( V_7 == NULL )
{
perror ( V_11 ) ;
goto V_24;
}
}
if ( V_9 == V_28 )
V_4 = F_13 ( V_7 , NULL ) ;
else if ( V_9 == V_25 )
V_4 = F_14 ( V_7 , NULL , NULL , NULL ) ;
else
{
F_8 ( V_20 , L_21 ) ;
goto V_24;
}
if ( V_4 == NULL )
{
F_8 ( V_20 , L_22 ) ;
F_11 ( V_20 ) ;
goto V_24;
}
if ( V_12 == NULL )
{
F_5 ( V_8 , stdout , V_22 ) ;
#ifdef F_15
{
T_3 * V_29 = F_3 ( F_16 () ) ;
V_8 = F_17 ( V_29 , V_8 ) ;
}
#endif
}
else
{
if ( F_18 ( V_8 , V_12 ) <= 0 )
{
perror ( V_12 ) ;
goto V_24;
}
}
if ( V_17 )
F_19 ( V_8 , V_4 , 0 , NULL ) ;
if ( V_14 )
{
F_20 ( V_30 ) * V_31 = NULL ;
F_20 ( V_32 ) * V_33 = NULL ;
V_5 = F_21 ( V_4 -> type ) ;
switch ( V_5 )
{
case V_34 :
V_31 = V_4 -> V_35 . V_36 -> V_37 ;
V_33 = V_4 -> V_35 . V_36 -> V_38 ;
break;
case V_39 :
V_31 = V_4 -> V_35 . V_40 -> V_37 ;
V_33 = V_4 -> V_35 . V_40 -> V_38 ;
break;
default:
break;
}
if ( V_31 != NULL )
{
V_30 * V_41 ;
for ( V_5 = 0 ; V_5 < F_22 ( V_31 ) ; V_5 ++ )
{
V_41 = F_23 ( V_31 , V_5 ) ;
if( V_15 ) F_24 ( V_8 , V_41 ) ;
else F_25 ( V_8 , V_41 ) ;
if( ! V_16 ) F_26 ( V_8 , V_41 ) ;
F_27 ( V_8 , L_23 ) ;
}
}
if ( V_33 != NULL )
{
V_32 * V_38 ;
for ( V_5 = 0 ; V_5 < F_28 ( V_33 ) ; V_5 ++ )
{
V_38 = F_29 ( V_33 , V_5 ) ;
F_30 ( V_8 , V_38 ) ;
if( ! V_16 ) F_31 ( V_8 , V_38 ) ;
F_27 ( V_8 , L_23 ) ;
}
}
V_18 = 0 ;
goto V_24;
}
if( ! V_16 ) {
if ( V_10 == V_28 )
V_5 = F_32 ( V_8 , V_4 ) ;
else if ( V_10 == V_25 )
V_5 = F_33 ( V_8 , V_4 ) ;
else {
F_8 ( V_20 , L_24 ) ;
goto V_24;
}
if ( ! V_5 )
{
F_8 ( V_20 , L_25 ) ;
F_11 ( V_20 ) ;
goto V_24;
}
}
V_18 = 0 ;
V_24:
if ( V_4 != NULL ) F_34 ( V_4 ) ;
if ( V_7 != NULL ) F_35 ( V_7 ) ;
if ( V_8 != NULL ) F_36 ( V_8 ) ;
F_37 () ;
F_38 ( V_18 ) ;
}
