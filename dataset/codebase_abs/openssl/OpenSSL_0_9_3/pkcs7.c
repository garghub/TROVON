int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 , V_5 = 0 ;
#if ! F_1 ( V_6 ) || ! F_1 ( V_7 )
T_2 * V_8 = NULL ;
#endif
T_3 * V_9 = NULL , * V_10 = NULL ;
int V_11 , V_12 ;
char * V_13 , * V_14 , * V_15 , V_16 [ 256 ] ;
int V_17 = 0 ;
int V_18 = 0 ;
F_2 () ;
if ( V_19 == NULL )
if ( ( V_19 = F_3 ( F_4 () ) ) != NULL )
F_5 ( V_19 , V_20 , V_21 | V_22 ) ;
V_13 = NULL ;
V_14 = NULL ;
V_11 = V_23 ;
V_12 = V_23 ;
V_15 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_24;
V_11 = F_6 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_24;
V_12 = F_6 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_24;
V_13 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_24;
V_14 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
V_17 = 1 ;
#ifndef V_6
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_8 = F_7 () ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_8 = F_8 () ;
#endif
#ifndef V_7
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_8 = F_9 () ;
#endif
else
{
F_10 ( V_19 , L_9 , * V_2 ) ;
V_5 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_5 )
{
V_24:
F_10 ( V_19 , L_10 , V_15 ) ;
F_10 ( V_19 , L_11 ) ;
F_10 ( V_19 , L_12 ) ;
F_10 ( V_19 , L_13 ) ;
F_10 ( V_19 , L_14 ) ;
F_10 ( V_19 , L_15 ) ;
F_10 ( V_19 , L_16 ) ;
F_10 ( V_19 , L_17 ) ;
F_10 ( V_19 , L_18 ) ;
#ifndef V_7
F_10 ( V_19 , L_19 ) ;
#endif
EXIT ( 1 ) ;
}
F_11 () ;
V_9 = F_3 ( F_4 () ) ;
V_10 = F_3 ( F_4 () ) ;
if ( ( V_9 == NULL ) || ( V_10 == NULL ) )
{
F_12 ( V_19 ) ;
goto V_25;
}
if ( V_13 == NULL )
F_5 ( V_9 , V_26 , V_21 ) ;
else
{
if ( F_13 ( V_9 , V_13 ) <= 0 )
if ( V_9 == NULL )
{
perror ( V_13 ) ;
goto V_25;
}
}
if ( V_11 == V_27 )
V_3 = F_14 ( V_9 , NULL ) ;
else if ( V_11 == V_23 )
V_3 = F_15 ( V_9 , NULL , NULL ) ;
else
{
F_10 ( V_19 , L_20 ) ;
goto V_25;
}
if ( V_3 == NULL )
{
F_10 ( V_19 , L_21 ) ;
F_12 ( V_19 ) ;
goto V_25;
}
if ( V_14 == NULL )
F_5 ( V_10 , stdout , V_21 ) ;
else
{
if ( F_16 ( V_10 , V_14 ) <= 0 )
{
perror ( V_14 ) ;
goto V_25;
}
}
if ( V_17 )
{
F_17 ( V_28 ) * V_29 = NULL ;
T_4 * V_30 = NULL ;
V_4 = F_18 ( V_3 -> type ) ;
switch ( V_4 )
{
case V_31 :
V_29 = V_3 -> V_32 . V_33 -> V_34 ;
V_30 = V_3 -> V_32 . V_33 -> V_35 ;
break;
case V_36 :
V_29 = V_3 -> V_32 . V_37 -> V_34 ;
V_30 = V_3 -> V_32 . V_37 -> V_35 ;
break;
default:
break;
}
if ( V_29 != NULL )
{
V_28 * V_38 ;
for ( V_4 = 0 ; V_4 < F_19 ( V_29 ) ; V_4 ++ )
{
V_38 = F_20 ( V_29 , V_4 ) ;
F_21 ( F_22 ( V_38 ) ,
V_16 , 256 ) ;
F_23 ( V_10 , L_22 ) ;
F_23 ( V_10 , V_16 ) ;
F_21 ( F_24 ( V_38 ) ,
V_16 , 256 ) ;
F_23 ( V_10 , L_23 ) ;
F_23 ( V_10 , V_16 ) ;
F_23 ( V_10 , L_24 ) ;
F_25 ( V_10 , V_38 ) ;
F_23 ( V_10 , L_24 ) ;
}
}
if ( V_30 != NULL )
{
T_5 * V_35 ;
for ( V_4 = 0 ; V_4 < F_26 ( V_30 ) ; V_4 ++ )
{
V_35 = ( T_5 * ) F_27 ( V_30 , V_4 ) ;
F_21 ( V_35 -> V_35 -> V_39 , V_16 , 256 ) ;
F_23 ( V_10 , L_25 ) ;
F_23 ( V_10 , V_16 ) ;
F_23 ( V_10 , L_26 ) ;
F_28 ( V_10 , V_35 -> V_35 -> V_40 ) ;
F_23 ( V_10 , L_27 ) ;
F_28 ( V_10 , V_35 -> V_35 -> V_41 ) ;
F_23 ( V_10 , L_24 ) ;
F_29 ( V_10 , V_35 ) ;
F_23 ( V_10 , L_24 ) ;
}
}
V_18 = 0 ;
goto V_25;
}
if ( V_12 == V_27 )
V_4 = F_30 ( V_10 , V_3 ) ;
else if ( V_12 == V_23 )
V_4 = F_31 ( V_10 , V_3 ) ;
else {
F_10 ( V_19 , L_28 ) ;
goto V_25;
}
if ( ! V_4 )
{
F_10 ( V_19 , L_29 ) ;
F_12 ( V_19 ) ;
goto V_25;
}
V_18 = 0 ;
V_25:
if ( V_3 != NULL ) F_32 ( V_3 ) ;
if ( V_9 != NULL ) F_33 ( V_9 ) ;
if ( V_10 != NULL ) F_33 ( V_10 ) ;
EXIT ( V_18 ) ;
}
