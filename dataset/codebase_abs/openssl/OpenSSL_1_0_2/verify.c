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
int V_20 = 0 ;
#ifndef F_2
char * V_21 = NULL ;
#endif
V_17 = F_3 () ;
if ( V_17 == NULL )
goto V_22;
F_4 ( V_17 , V_23 ) ;
F_5 () ;
F_6 () ;
if ( V_24 == NULL )
if ( ( V_24 = F_7 ( F_8 () ) ) != NULL )
F_9 ( V_24 , V_25 , V_26 | V_27 ) ;
if ( ! F_10 ( V_24 , NULL ) )
goto V_22;
V_1 -- ;
V_2 ++ ;
for (; ; ) {
if ( V_1 >= 1 ) {
if ( strcmp ( * V_2 , L_1 ) == 0 ) {
if ( V_1 -- < 1 )
goto V_22;
V_7 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_2 ) == 0 ) {
if ( V_1 -- < 1 )
goto V_22;
V_8 = * ( ++ V_2 ) ;
} else if ( F_11 ( & V_2 , & V_1 , & V_6 , V_24 , & V_19 ) ) {
if ( V_6 )
goto V_22;
continue;
} else if ( strcmp ( * V_2 , L_3 ) == 0 ) {
if ( V_1 -- < 1 )
goto V_22;
V_9 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_4 ) == 0 ) {
if ( V_1 -- < 1 )
goto V_22;
V_10 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_5 ) == 0 ) {
if ( V_1 -- < 1 )
goto V_22;
V_11 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_20 = 1 ;
#ifndef F_2
else if ( strcmp ( * V_2 , L_7 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_22;
V_21 = * ( ++ V_2 ) ;
}
#endif
else if ( strcmp ( * V_2 , L_8 ) == 0 )
goto V_22;
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_28 = 1 ;
else if ( V_2 [ 0 ] [ 0 ] == '-' )
goto V_22;
else
break;
V_1 -- ;
V_2 ++ ;
} else
break;
}
#ifndef F_2
V_3 = F_12 ( V_24 , V_21 , 0 ) ;
#endif
if ( V_19 )
F_13 ( V_17 , V_19 ) ;
V_18 = F_14 ( V_17 , F_15 () ) ;
if ( V_18 == NULL )
abort () ;
if ( V_8 ) {
V_4 = F_16 ( V_18 , V_8 , V_29 ) ;
if ( ! V_4 ) {
F_17 ( V_24 , L_10 , V_8 ) ;
F_18 ( V_24 ) ;
goto V_22;
}
} else
F_16 ( V_18 , NULL , V_30 ) ;
V_18 = F_14 ( V_17 , F_19 () ) ;
if ( V_18 == NULL )
abort () ;
if ( V_7 ) {
V_4 = F_20 ( V_18 , V_7 , V_29 ) ;
if ( ! V_4 ) {
F_17 ( V_24 , L_11 , V_7 ) ;
F_18 ( V_24 ) ;
goto V_22;
}
} else
F_20 ( V_18 , NULL , V_30 ) ;
F_21 () ;
if ( V_9 ) {
V_13 = F_22 ( V_24 , V_9 , V_31 ,
NULL , V_3 , L_12 ) ;
if ( ! V_13 )
goto V_22;
}
if ( V_10 ) {
V_14 = F_22 ( V_24 , V_10 , V_31 ,
NULL , V_3 , L_13 ) ;
if ( ! V_14 )
goto V_22;
}
if ( V_11 ) {
V_16 = F_23 ( V_24 , V_11 , V_31 , NULL , V_3 , L_14 ) ;
if ( ! V_16 )
goto V_22;
}
V_5 = 0 ;
if ( V_20 )
F_24 ( V_17 ) ;
if ( V_1 < 1 ) {
if ( 1 != F_25 ( V_17 , NULL , V_13 , V_14 , V_16 , V_3 ) )
V_5 = - 1 ;
} else {
for ( V_4 = 0 ; V_4 < V_1 ; V_4 ++ )
if ( 1 != F_25 ( V_17 , V_2 [ V_4 ] , V_13 , V_14 , V_16 , V_3 ) )
V_5 = - 1 ;
}
V_22:
if ( V_5 == 1 ) {
F_17 ( V_24 ,
L_15 ) ;
F_17 ( V_24 , L_16 ) ;
#ifndef F_2
F_17 ( V_24 , L_17 ) ;
#endif
F_17 ( V_24 , L_18 ) ;
F_17 ( V_24 , L_19 ) ;
for ( V_4 = 0 ; V_4 < F_26 () ; V_4 ++ ) {
T_5 * V_32 ;
V_32 = F_27 ( V_4 ) ;
F_17 ( V_24 , L_20 ,
F_28 ( V_32 ) ,
F_29 ( V_32 ) ) ;
}
}
if ( V_19 )
F_30 ( V_19 ) ;
if ( V_17 != NULL )
F_31 ( V_17 ) ;
F_32 ( V_13 , V_33 ) ;
F_32 ( V_14 , V_33 ) ;
F_33 ( V_16 , V_34 ) ;
F_34 () ;
F_35 ( V_5 < 0 ? 2 : V_5 ) ;
}
static int T_6 V_23 ( int V_35 , T_7 * V_36 )
{
int V_37 = F_36 ( V_36 ) ;
V_12 * V_38 = F_37 ( V_36 ) ;
if ( ! V_35 ) {
if ( V_38 ) {
F_38 ( stdout ,
F_39 ( V_38 ) ,
0 , V_39 ) ;
printf ( L_21 ) ;
}
printf ( L_22 ,
F_40 ( V_36 ) ? L_23 : L_24 ,
V_37 ,
F_41 ( V_36 ) ,
F_42 ( V_37 ) ) ;
switch ( V_37 ) {
case V_40 :
F_43 ( NULL , V_36 ) ;
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
V_35 = 1 ;
}
return V_35 ;
}
if ( V_37 == V_50 && V_35 == 2 )
F_43 ( NULL , V_36 ) ;
if ( ! V_28 )
F_21 () ;
return ( V_35 ) ;
}
