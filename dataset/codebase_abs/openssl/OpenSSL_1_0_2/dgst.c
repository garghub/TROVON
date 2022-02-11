static void F_1 ( const T_1 * V_1 ,
const char * V_2 , const char * V_3 , void * V_4 )
{
const char * V_5 ;
if ( ! V_1 )
return;
V_5 = F_2 ( F_3 ( V_1 ) ) ;
if ( strcmp ( V_2 , V_5 ) )
return;
if ( F_4 ( V_1 ) & V_6 )
return;
if ( strchr ( V_5 , ' ' ) )
V_5 = F_5 ( V_1 ) ;
F_6 ( V_4 , L_1 ,
V_5 , V_5 ) ;
}
int MAIN ( int V_7 , char * * V_8 )
{
T_2 * V_9 = NULL , * V_10 = NULL ;
unsigned char * V_11 = NULL ;
int V_12 , V_13 = 1 ;
const T_1 * V_14 = NULL , * V_1 ;
T_3 * V_15 = NULL , * V_16 ;
T_3 * V_17 = NULL ;
T_3 * V_18 = NULL ;
#define F_7 39
char V_19 [ F_7 + 1 ] ;
int V_20 = 0 ;
int V_21 = 0 ;
int V_22 = V_23 ;
const char * V_24 = NULL , * V_25 = NULL ;
const char * V_26 = NULL , * V_27 = NULL ;
int V_28 = - 1 , V_29 = 0 , V_30 = 0 ;
T_4 * V_31 = NULL ;
unsigned char * V_32 = NULL ;
int V_33 = 0 ;
char * V_34 = NULL , * V_35 = NULL ;
#ifndef F_8
char * V_36 = NULL ;
int V_37 = 0 ;
#endif
char * V_38 = NULL ;
char * V_39 = NULL ;
int V_40 = 0 ;
F_9 ( V_41 ) * V_42 = NULL , * V_43 = NULL ;
F_10 () ;
if ( ( V_11 = ( unsigned char * ) F_11 ( V_44 ) ) == NULL ) {
F_6 ( V_45 , L_2 ) ;
goto V_46;
}
if ( V_45 == NULL )
if ( ( V_45 = F_12 ( F_13 () ) ) != NULL )
F_14 ( V_45 , V_47 , V_48 | V_49 ) ;
if ( ! F_15 ( V_45 , NULL ) )
goto V_46;
F_16 ( V_8 [ 0 ] , V_19 , sizeof V_19 ) ;
V_14 = F_17 ( V_19 ) ;
V_7 -- ;
V_8 ++ ;
while ( V_7 > 0 ) {
if ( ( * V_8 ) [ 0 ] != '-' )
break;
if ( strcmp ( * V_8 , L_3 ) == 0 )
V_20 = 1 ;
else if ( strcmp ( * V_8 , L_4 ) == 0 )
V_20 = 2 ;
else if ( strcmp ( * V_8 , L_5 ) == 0 ) {
if ( -- V_7 < 1 )
break;
V_27 = * ( ++ V_8 ) ;
} else if ( strcmp ( * V_8 , L_6 ) == 0 ) {
if ( -- V_7 < 1 )
break;
V_24 = * ( ++ V_8 ) ;
} else if ( strcmp ( * V_8 , L_7 ) == 0 ) {
if ( -- V_7 < 1 )
break;
V_25 = * ( ++ V_8 ) ;
} else if ( ! strcmp ( * V_8 , L_8 ) ) {
if ( -- V_7 < 1 )
break;
V_34 = * ++ V_8 ;
} else if ( strcmp ( * V_8 , L_9 ) == 0 ) {
if ( -- V_7 < 1 )
break;
V_25 = * ( ++ V_8 ) ;
V_29 = 1 ;
V_30 = 1 ;
} else if ( strcmp ( * V_8 , L_10 ) == 0 ) {
if ( -- V_7 < 1 )
break;
V_25 = * ( ++ V_8 ) ;
V_30 = 1 ;
} else if ( strcmp ( * V_8 , L_11 ) == 0 ) {
if ( -- V_7 < 1 )
break;
V_26 = * ( ++ V_8 ) ;
} else if ( strcmp ( * V_8 , L_12 ) == 0 ) {
if ( -- V_7 < 1 )
break;
V_22 = F_18 ( * ( ++ V_8 ) ) ;
}
#ifndef F_8
else if ( strcmp ( * V_8 , L_13 ) == 0 ) {
if ( -- V_7 < 1 )
break;
V_36 = * ( ++ V_8 ) ;
V_9 = F_19 ( V_45 , V_36 , 0 ) ;
} else if ( strcmp ( * V_8 , L_14 ) == 0 )
V_37 = 1 ;
#endif
else if ( strcmp ( * V_8 , L_15 ) == 0 )
V_28 = 0 ;
else if ( strcmp ( * V_8 , L_16 ) == 0 )
V_28 = 1 ;
else if ( strcmp ( * V_8 , L_17 ) == 0 )
V_21 = 1 ;
else if ( ! strcmp ( * V_8 , L_18 ) )
V_38 = L_19 ;
else if ( strcmp ( * V_8 , L_20 ) == 0 )
V_40 = 1 ;
else if ( ! strcmp ( * V_8 , L_21 ) ) {
if ( -- V_7 < 1 )
break;
V_38 = * ++ V_8 ;
} else if ( ! strcmp ( * V_8 , L_22 ) ) {
if ( -- V_7 < 1 )
break;
V_39 = * ++ V_8 ;
} else if ( strcmp ( * V_8 , L_23 ) == 0 ) {
if ( -- V_7 < 1 )
break;
if ( ! V_42 )
V_42 = F_20 () ;
if ( ! V_42 || ! F_21 ( V_42 , * ( ++ V_8 ) ) )
break;
} else if ( strcmp ( * V_8 , L_24 ) == 0 ) {
if ( -- V_7 < 1 )
break;
if ( ! V_43 )
V_43 = F_20 () ;
if ( ! V_43 || ! F_21 ( V_43 , * ( ++ V_8 ) ) )
break;
} else if ( ( V_1 = F_17 ( & ( ( * V_8 ) [ 1 ] ) ) ) != NULL )
V_14 = V_1 ;
else
break;
V_7 -- ;
V_8 ++ ;
}
if ( V_30 && ! V_26 ) {
F_6 ( V_45 ,
L_25 ) ;
goto V_46;
}
if ( ( V_7 > 0 ) && ( V_8 [ 0 ] [ 0 ] == '-' ) ) {
F_6 ( V_45 , L_26 , * V_8 ) ;
F_6 ( V_45 , L_27 ) ;
F_6 ( V_45 ,
L_28 ) ;
F_6 ( V_45 ,
L_29 ) ;
F_6 ( V_45 , L_30 ) ;
F_6 ( V_45 , L_31 ) ;
F_6 ( V_45 , L_32 ) ;
F_6 ( V_45 , L_33 ) ;
F_6 ( V_45 , L_34 ) ;
F_6 ( V_45 ,
L_35 ) ;
F_6 ( V_45 ,
L_36 ) ;
F_6 ( V_45 ,
L_37 ) ;
F_6 ( V_45 ,
L_38 ) ;
F_6 ( V_45 ,
L_39 ) ;
F_6 ( V_45 , L_40 ) ;
F_6 ( V_45 , L_41 ) ;
F_6 ( V_45 , L_42 ) ;
F_6 ( V_45 ,
L_43 ) ;
F_6 ( V_45 ,
L_44 ) ;
#ifndef F_8
F_6 ( V_45 ,
L_45 ) ;
#endif
F_22 ( F_1 , V_45 ) ;
goto V_46;
}
#ifndef F_8
if ( V_37 )
V_10 = V_9 ;
#endif
V_15 = F_12 ( F_13 () ) ;
V_17 = F_12 ( F_23 () ) ;
if ( V_21 ) {
F_24 ( V_15 , V_50 ) ;
F_25 ( V_15 , ( char * ) V_45 ) ;
}
if ( ! F_26 ( V_45 , V_34 , NULL , & V_35 , NULL ) ) {
F_6 ( V_45 , L_46 ) ;
goto V_46;
}
if ( ( V_15 == NULL ) || ( V_17 == NULL ) ) {
F_27 ( V_45 ) ;
goto V_46;
}
if ( V_28 == - 1 ) {
if ( V_25 )
V_28 = 1 ;
else
V_28 = 0 ;
}
if ( V_27 )
F_28 ( V_27 , V_45 , 0 ) ;
if ( V_24 ) {
if ( V_28 )
V_18 = F_29 ( V_24 , L_47 ) ;
else
V_18 = F_29 ( V_24 , L_48 ) ;
} else {
V_18 = F_30 ( stdout , V_48 ) ;
#ifdef F_31
{
T_3 * V_51 = F_12 ( F_32 () ) ;
V_18 = F_33 ( V_51 , V_18 ) ;
}
#endif
}
if ( ! V_18 ) {
F_6 ( V_45 , L_49 ,
V_24 ? V_24 : L_50 ) ;
F_27 ( V_45 ) ;
goto V_46;
}
if ( ( ! ! V_39 + ! ! V_25 + ! ! V_38 ) > 1 ) {
F_6 ( V_45 , L_51 ) ;
goto V_46;
}
if ( V_25 ) {
if ( V_29 )
V_31 = F_34 ( V_45 , V_25 , V_22 , 0 , NULL ,
V_9 , L_52 ) ;
else
V_31 = F_35 ( V_45 , V_25 , V_22 , 0 , V_35 ,
V_9 , L_52 ) ;
if ( ! V_31 ) {
goto V_46;
}
}
if ( V_39 ) {
T_5 * V_52 = NULL ;
int V_53 = 0 ;
if ( ! F_36 ( V_45 , & V_52 , V_39 , V_10 , 0 ) )
goto V_54;
if ( V_43 ) {
char * V_55 ;
for ( V_12 = 0 ; V_12 < F_37 ( V_43 ) ; V_12 ++ ) {
V_55 = F_38 ( V_43 , V_12 ) ;
if ( F_39 ( V_52 , V_55 ) <= 0 ) {
F_6 ( V_45 ,
L_53 , V_55 ) ;
F_27 ( V_45 ) ;
goto V_54;
}
}
}
if ( F_40 ( V_52 , & V_31 ) <= 0 ) {
F_41 ( V_45 , L_54 ) ;
F_27 ( V_45 ) ;
goto V_54;
}
V_53 = 1 ;
V_54:
if ( V_52 )
F_42 ( V_52 ) ;
if ( V_53 == 0 )
goto V_46;
}
if ( V_40 ) {
T_6 * V_56 ;
F_43 ( V_17 , & V_56 ) ;
F_44 ( V_56 , V_57 ) ;
}
if ( V_38 ) {
V_31 = F_45 ( V_58 , V_10 ,
( unsigned char * ) V_38 , - 1 ) ;
if ( ! V_31 )
goto V_46;
}
if ( V_31 ) {
T_6 * V_59 = NULL ;
T_5 * V_60 = NULL ;
int V_53 ;
if ( ! F_43 ( V_17 , & V_59 ) ) {
F_6 ( V_45 , L_55 ) ;
F_27 ( V_45 ) ;
goto V_46;
}
if ( V_30 )
V_53 = F_46 ( V_59 , & V_60 , V_14 , V_10 , V_31 ) ;
else
V_53 = F_47 ( V_59 , & V_60 , V_14 , V_10 , V_31 ) ;
if ( ! V_53 ) {
F_6 ( V_45 , L_56 ) ;
F_27 ( V_45 ) ;
goto V_46;
}
if ( V_42 ) {
char * V_61 ;
for ( V_12 = 0 ; V_12 < F_37 ( V_42 ) ; V_12 ++ ) {
V_61 = F_38 ( V_42 , V_12 ) ;
if ( F_39 ( V_60 , V_61 ) <= 0 ) {
F_6 ( V_45 , L_57 , V_61 ) ;
F_27 ( V_45 ) ;
goto V_46;
}
}
}
}
else {
T_6 * V_59 = NULL ;
if ( ! F_43 ( V_17 , & V_59 ) ) {
F_6 ( V_45 , L_55 ) ;
F_27 ( V_45 ) ;
goto V_46;
}
if ( V_14 == NULL )
V_14 = F_48 () ;
if ( ! F_49 ( V_59 , V_14 , V_10 ) ) {
F_6 ( V_45 , L_58 , V_19 ) ;
F_27 ( V_45 ) ;
goto V_46;
}
}
if ( V_26 && V_31 ) {
T_3 * V_62 ;
V_62 = F_29 ( V_26 , L_59 ) ;
V_33 = F_50 ( V_31 ) ;
V_32 = F_11 ( V_33 ) ;
if ( ! V_62 ) {
F_6 ( V_45 , L_60 , V_26 ) ;
F_27 ( V_45 ) ;
goto V_46;
}
V_33 = F_51 ( V_62 , V_32 , V_33 ) ;
F_52 ( V_62 ) ;
if ( V_33 <= 0 ) {
F_6 ( V_45 , L_61 , V_26 ) ;
F_27 ( V_45 ) ;
goto V_46;
}
}
V_16 = F_33 ( V_17 , V_15 ) ;
if ( V_14 == NULL ) {
T_6 * V_63 ;
F_43 ( V_17 , & V_63 ) ;
V_14 = F_53 ( V_63 ) ;
}
if ( V_7 == 0 ) {
F_14 ( V_15 , V_64 , V_48 ) ;
V_13 = F_54 ( V_18 , V_11 , V_16 , V_20 , V_28 , V_31 , V_32 ,
V_33 , NULL , NULL , L_62 , V_17 ) ;
} else {
const char * V_65 = NULL , * V_66 = NULL ;
if ( ! V_28 ) {
if ( V_31 ) {
const T_7 * V_67 ;
V_67 = F_55 ( V_31 ) ;
if ( V_67 )
F_56 ( NULL , NULL ,
NULL , NULL , & V_66 , V_67 ) ;
}
if ( V_14 )
V_65 = F_5 ( V_14 ) ;
}
V_13 = 0 ;
for ( V_12 = 0 ; V_12 < V_7 ; V_12 ++ ) {
int V_53 ;
if ( F_57 ( V_15 , V_8 [ V_12 ] ) <= 0 ) {
perror ( V_8 [ V_12 ] ) ;
V_13 ++ ;
continue;
} else
V_53 = F_54 ( V_18 , V_11 , V_16 , V_20 , V_28 , V_31 , V_32 ,
V_33 , V_66 , V_65 , V_8 [ V_12 ] , V_17 ) ;
if ( V_53 )
V_13 = V_53 ;
( void ) F_58 ( V_17 ) ;
}
}
V_46:
if ( V_11 != NULL ) {
F_59 ( V_11 , V_44 ) ;
F_60 ( V_11 ) ;
}
if ( V_15 != NULL )
F_52 ( V_15 ) ;
if ( V_35 )
F_60 ( V_35 ) ;
F_61 ( V_18 ) ;
F_62 ( V_31 ) ;
if ( V_42 )
F_63 ( V_42 ) ;
if ( V_43 )
F_63 ( V_43 ) ;
if ( V_32 )
F_60 ( V_32 ) ;
if ( V_17 != NULL )
F_52 ( V_17 ) ;
F_64 () ;
F_65 ( V_13 ) ;
}
int F_54 ( T_3 * V_18 , unsigned char * V_11 , T_3 * V_68 , int V_69 , int V_70 ,
T_4 * V_71 , unsigned char * V_72 , int V_33 ,
const char * V_66 , const char * V_65 ,
const char * V_73 , T_3 * V_17 )
{
T_8 V_74 ;
int V_12 ;
for (; ; ) {
V_12 = F_51 ( V_68 , ( char * ) V_11 , V_44 ) ;
if ( V_12 < 0 ) {
F_6 ( V_45 , L_63 , V_73 ) ;
F_27 ( V_45 ) ;
return 1 ;
}
if ( V_12 == 0 )
break;
}
if ( V_72 ) {
T_6 * V_75 ;
F_43 ( V_68 , & V_75 ) ;
V_12 = F_66 ( V_75 , V_72 , ( unsigned int ) V_33 ) ;
if ( V_12 > 0 )
F_6 ( V_18 , L_64 ) ;
else if ( V_12 == 0 ) {
F_6 ( V_18 , L_65 ) ;
return 1 ;
} else {
F_6 ( V_45 , L_66 ) ;
F_27 ( V_45 ) ;
return 1 ;
}
return 0 ;
}
if ( V_71 ) {
T_6 * V_75 ;
F_43 ( V_68 , & V_75 ) ;
V_74 = V_44 ;
if ( ! F_67 ( V_75 , V_11 , & V_74 ) ) {
F_6 ( V_45 , L_67 ) ;
F_27 ( V_45 ) ;
return 1 ;
}
} else {
V_74 = F_68 ( V_68 , ( char * ) V_11 , V_44 ) ;
if ( ( int ) V_74 < 0 ) {
F_27 ( V_45 ) ;
return 1 ;
}
}
if ( V_70 )
F_69 ( V_18 , V_11 , V_74 ) ;
else if ( V_69 == 2 ) {
for ( V_12 = 0 ; V_12 < ( int ) V_74 ; V_12 ++ )
F_6 ( V_18 , L_68 , V_11 [ V_12 ] ) ;
F_6 ( V_18 , L_69 , V_73 ) ;
} else {
if ( V_66 ) {
F_41 ( V_18 , V_66 ) ;
if ( V_65 )
F_6 ( V_18 , L_70 , V_65 ) ;
F_6 ( V_18 , L_71 , V_73 ) ;
} else if ( V_65 )
F_6 ( V_18 , L_72 , V_65 , V_73 ) ;
else
F_6 ( V_18 , L_71 , V_73 ) ;
for ( V_12 = 0 ; V_12 < ( int ) V_74 ; V_12 ++ ) {
if ( V_69 && ( V_12 != 0 ) )
F_6 ( V_18 , L_73 ) ;
F_6 ( V_18 , L_68 , V_11 [ V_12 ] ) ;
}
F_6 ( V_18 , L_74 ) ;
}
return 0 ;
}
