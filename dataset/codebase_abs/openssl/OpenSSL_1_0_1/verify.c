int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 , V_5 = 1 , V_6 = 0 ;
char * V_7 = NULL , * V_8 = NULL ;
char * V_9 = NULL , * V_10 = NULL , * V_11 = NULL ;
F_1 ( V_12 ) * V_13 = NULL , * V_14 = NULL ;
F_1 ( V_15 ) * V_16 = NULL ;
T_2 * V_17 = NULL ;
T_3 * V_18 = NULL ;
T_4 * V_19 = NULL ;
#ifndef F_2
char * V_20 = NULL ;
#endif
V_17 = F_3 () ;
if ( V_17 == NULL ) goto V_21;
F_4 ( V_17 , V_22 ) ;
F_5 () ;
F_6 () ;
if ( V_23 == NULL )
if ( ( V_23 = F_7 ( F_8 () ) ) != NULL )
F_9 ( V_23 , V_24 , V_25 | V_26 ) ;
if ( ! F_10 ( V_23 , NULL ) )
goto V_21;
V_1 -- ;
V_2 ++ ;
for (; ; )
{
if ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( V_1 -- < 1 ) goto V_21;
V_7 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( V_1 -- < 1 ) goto V_21;
V_8 = * ( ++ V_2 ) ;
}
else if ( F_11 ( & V_2 , & V_1 , & V_6 , V_23 ,
& V_19 ) )
{
if ( V_6 )
goto V_21;
continue;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( V_1 -- < 1 ) goto V_21;
V_9 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( V_1 -- < 1 ) goto V_21;
V_10 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
{
if ( V_1 -- < 1 ) goto V_21;
V_11 = * ( ++ V_2 ) ;
}
#ifndef F_2
else if ( strcmp ( * V_2 , L_6 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_21;
V_20 = * ( ++ V_2 ) ;
}
#endif
else if ( strcmp ( * V_2 , L_7 ) == 0 )
goto V_21;
else if ( strcmp ( * V_2 , L_8 ) == 0 )
V_27 = 1 ;
else if ( V_2 [ 0 ] [ 0 ] == '-' )
goto V_21;
else
break;
V_1 -- ;
V_2 ++ ;
}
else
break;
}
#ifndef F_2
V_3 = F_12 ( V_23 , V_20 , 0 ) ;
#endif
if ( V_19 )
F_13 ( V_17 , V_19 ) ;
V_18 = F_14 ( V_17 , F_15 () ) ;
if ( V_18 == NULL ) abort () ;
if ( V_8 ) {
V_4 = F_16 ( V_18 , V_8 , V_28 ) ;
if( ! V_4 ) {
F_17 ( V_23 , L_9 , V_8 ) ;
F_18 ( V_23 ) ;
goto V_21;
}
} else F_16 ( V_18 , NULL , V_29 ) ;
V_18 = F_14 ( V_17 , F_19 () ) ;
if ( V_18 == NULL ) abort () ;
if ( V_7 ) {
V_4 = F_20 ( V_18 , V_7 , V_28 ) ;
if( ! V_4 ) {
F_17 ( V_23 , L_10 , V_7 ) ;
F_18 ( V_23 ) ;
goto V_21;
}
} else F_20 ( V_18 , NULL , V_29 ) ;
F_21 () ;
if( V_9 )
{
V_13 = F_22 ( V_23 , V_9 , V_30 ,
NULL , V_3 , L_11 ) ;
if( ! V_13 )
goto V_21;
}
if( V_10 )
{
V_14 = F_22 ( V_23 , V_10 , V_30 ,
NULL , V_3 , L_12 ) ;
if( ! V_14 )
goto V_21;
}
if( V_11 )
{
V_16 = F_23 ( V_23 , V_11 , V_30 ,
NULL , V_3 , L_13 ) ;
if( ! V_16 )
goto V_21;
}
if ( V_1 < 1 ) F_24 ( V_17 , NULL , V_13 , V_14 , V_16 , V_3 ) ;
else
for ( V_4 = 0 ; V_4 < V_1 ; V_4 ++ )
F_24 ( V_17 , V_2 [ V_4 ] , V_13 , V_14 , V_16 , V_3 ) ;
V_5 = 0 ;
V_21:
if ( V_5 == 1 ) {
F_17 ( V_23 , L_14 ) ;
F_17 ( V_23 , L_15 ) ;
#ifndef F_2
F_17 ( V_23 , L_16 ) ;
#endif
F_17 ( V_23 , L_17 ) ;
F_17 ( V_23 , L_18 ) ;
for( V_4 = 0 ; V_4 < F_25 () ; V_4 ++ ) {
T_5 * V_31 ;
V_31 = F_26 ( V_4 ) ;
F_17 ( V_23 , L_19 , F_27 ( V_31 ) ,
F_28 ( V_31 ) ) ;
}
}
if ( V_19 ) F_29 ( V_19 ) ;
if ( V_17 != NULL ) F_30 ( V_17 ) ;
F_31 ( V_13 , V_32 ) ;
F_31 ( V_14 , V_32 ) ;
F_32 ( V_16 , V_33 ) ;
F_33 () ;
F_34 ( V_5 ) ;
}
static int T_6 V_22 ( int V_34 , T_7 * V_35 )
{
int V_36 = F_35 ( V_35 ) ;
V_12 * V_37 = F_36 ( V_35 ) ;
if ( ! V_34 )
{
if ( V_37 )
{
F_37 ( stdout ,
F_38 ( V_37 ) ,
0 , V_38 ) ;
printf ( L_20 ) ;
}
printf ( L_21 ,
F_39 ( V_35 ) ? L_22 : L_23 ,
V_36 ,
F_40 ( V_35 ) ,
F_41 ( V_36 ) ) ;
switch( V_36 )
{
case V_39 :
F_42 ( NULL , V_35 ) ;
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
V_34 = 1 ;
}
return V_34 ;
}
if ( V_36 == V_49 && V_34 == 2 )
F_42 ( NULL , V_35 ) ;
if ( ! V_27 )
F_21 () ;
return ( V_34 ) ;
}
