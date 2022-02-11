int MAIN ( int V_1 , char * * V_2 )
{
unsigned long V_3 = 0 ;
T_1 * V_4 = NULL ;
char * V_5 = NULL , * V_6 = NULL ;
int V_7 = 1 , V_8 , V_9 , V_10 = 0 , V_11 = 0 ;
T_2 * V_12 = NULL ;
int V_13 , V_14 , V_15 ;
char * V_16 = NULL , * V_17 = NULL , * V_18 = NULL , * V_19 = NULL ;
int V_20 = 0 , V_21 = 0 , V_22 = 0 , V_23 = 0 , V_24 =
0 , V_25 = 0 ;
#ifndef F_1
int V_26 = 0 ;
#endif
int V_27 = 0 , V_28 = 0 ;
const char * * V_29 ;
T_3 * V_30 = NULL ;
T_4 V_31 ;
T_5 * V_32 = NULL ;
T_6 V_33 ;
T_7 * V_34 ;
int V_35 = 0 ;
const T_8 * V_36 , * V_37 = F_2 () ;
F_3 () ;
if ( V_38 == NULL )
if ( ( V_38 = F_4 ( F_5 () ) ) != NULL )
F_6 ( V_38 , V_39 , V_40 | V_41 ) ;
if ( ! F_7 ( V_38 , NULL ) )
goto V_42;
if ( V_43 == NULL )
if ( ( V_43 = F_4 ( F_5 () ) ) != NULL ) {
F_6 ( V_43 , stdout , V_40 ) ;
#ifdef F_8
{
T_2 * V_44 = F_4 ( F_9 () ) ;
V_43 = F_10 ( V_44 , V_43 ) ;
}
#endif
}
V_13 = V_45 ;
V_14 = V_45 ;
V_15 = V_45 ;
V_1 -- ;
V_2 ++ ;
V_9 = 0 ;
while ( V_1 >= 1 ) {
#ifdef undef
if ( strcmp ( * V_2 , L_1 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_46;
if ( ! F_11 ( ++ V_2 , V_47 , V_48 ) ) {
goto V_42;
}
* / }
#endif
if ( strcmp ( * V_2 , L_2 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_46;
V_13 = F_12 ( * ( ++ V_2 ) ) ;
} else if ( strcmp ( * V_2 , L_3 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_46;
V_14 = F_12 ( * ( ++ V_2 ) ) ;
} else if ( strcmp ( * V_2 , L_4 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_46;
V_16 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_5 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_46;
V_18 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_6 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_46;
V_19 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_7 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_46;
V_15 = F_12 ( * ( ++ V_2 ) ) ;
} else if ( strcmp ( * V_2 , L_8 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_46;
V_17 = * ( ++ V_2 ) ;
} else if ( strcmp ( * V_2 , L_9 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_46;
V_6 = * ( ++ V_2 ) ;
V_35 = 1 ;
} else if ( strcmp ( * V_2 , L_10 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_46;
V_5 = * ( ++ V_2 ) ;
V_35 = 1 ;
} else if ( strcmp ( * V_2 , L_11 ) == 0 )
V_35 = 1 ;
else if ( strcmp ( * V_2 , L_12 ) == 0 )
V_25 = 1 ;
else if ( strcmp ( * V_2 , L_13 ) == 0 )
V_20 = ++ V_9 ;
#ifndef F_1
else if ( strcmp ( * V_2 , L_14 ) == 0 )
V_26 = ++ V_9 ;
#endif
else if ( strcmp ( * V_2 , L_15 ) == 0 ) {
if ( -- V_1 < 1 )
goto V_46;
if ( ! F_13 ( & V_3 , * ( ++ V_2 ) ) )
goto V_46;
} else if ( strcmp ( * V_2 , L_16 ) == 0 )
V_21 = ++ V_9 ;
else if ( strcmp ( * V_2 , L_17 ) == 0 )
V_22 = ++ V_9 ;
else if ( strcmp ( * V_2 , L_18 ) == 0 )
V_23 = ++ V_9 ;
else if ( strcmp ( * V_2 , L_19 ) == 0 )
V_24 = ++ V_9 ;
else if ( strcmp ( * V_2 , L_20 ) == 0 )
V_27 = ++ V_9 ;
else if ( strcmp ( * V_2 , L_21 ) == 0 )
V_28 = ++ V_9 ;
else if ( strcmp ( * V_2 , L_22 ) == 0 )
V_11 = 1 ;
else if ( ( V_36 = F_14 ( * V_2 + 1 ) ) ) {
V_37 = V_36 ;
} else {
F_15 ( V_38 , L_23 , * V_2 ) ;
V_10 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_10 ) {
V_46:
for ( V_29 = V_49 ; ( * V_29 != NULL ) ; V_29 ++ )
F_15 ( V_38 , L_24 , * V_29 ) ;
goto V_42;
}
F_16 () ;
V_4 = F_17 ( V_16 , V_13 ) ;
if ( V_4 == NULL ) {
goto V_42;
}
if ( V_35 ) {
V_30 = F_18 () ;
V_32 = F_19 ( V_30 , F_20 () ) ;
if ( V_32 == NULL )
goto V_42;
if ( ! F_21 ( V_32 , V_5 , V_50 ) )
F_21 ( V_32 , NULL , V_51 ) ;
V_32 = F_19 ( V_30 , F_22 () ) ;
if ( V_32 == NULL )
goto V_42;
if ( ! F_23 ( V_32 , V_6 , V_50 ) )
F_23 ( V_32 , NULL , V_51 ) ;
F_24 () ;
if ( ! F_25 ( & V_31 , V_30 , NULL , NULL ) ) {
F_15 ( V_38 , L_25 ) ;
goto V_42;
}
V_8 = F_26 ( & V_31 , V_52 ,
F_27 ( V_4 ) , & V_33 ) ;
if ( V_8 <= 0 ) {
F_15 ( V_38 , L_26 ) ;
goto V_42;
}
V_34 = F_28 ( V_33 . V_53 . V_54 ) ;
F_29 ( & V_33 ) ;
if ( ! V_34 ) {
F_15 ( V_38 , L_27 ) ;
goto V_42;
}
V_8 = F_30 ( V_4 , V_34 ) ;
F_31 ( V_34 ) ;
if ( V_8 < 0 )
goto V_42;
if ( V_8 == 0 )
F_15 ( V_38 , L_28 ) ;
else
F_15 ( V_38 , L_29 ) ;
}
if ( V_18 ) {
T_1 * V_55 , * V_56 ;
if ( ! V_19 ) {
F_32 ( V_38 , L_30 ) ;
goto V_42;
}
V_55 = F_17 ( V_18 , V_13 ) ;
if ( ! V_55 )
goto V_42;
V_34 = F_33 ( V_38 , V_19 , V_15 , 0 , NULL , NULL ,
L_31 ) ;
if ( ! V_34 ) {
F_34 ( V_55 ) ;
goto V_42;
}
V_56 = F_35 ( V_4 , V_55 , V_34 , V_37 , 0 ) ;
F_34 ( V_55 ) ;
F_31 ( V_34 ) ;
if ( V_56 ) {
F_34 ( V_4 ) ;
V_4 = V_56 ;
} else {
F_32 ( V_38 , L_32 ) ;
goto V_42;
}
}
if ( V_9 ) {
for ( V_8 = 1 ; V_8 <= V_9 ; V_8 ++ ) {
if ( V_21 == V_8 ) {
F_36 ( V_43 , L_33 , F_27 ( V_4 ) ,
V_3 ) ;
}
if ( V_28 == V_8 ) {
T_9 * V_57 ;
V_57 = F_37 ( V_4 , V_58 , NULL , NULL ) ;
F_15 ( V_43 , L_34 ) ;
if ( V_57 ) {
F_38 ( V_43 , V_57 ) ;
F_39 ( V_57 ) ;
} else
F_32 ( V_43 , L_35 ) ;
F_15 ( V_43 , L_36 ) ;
}
if ( V_20 == V_8 ) {
F_15 ( V_43 , L_37 ,
F_40 ( F_27 ( V_4 ) ) ) ;
}
#ifndef F_1
if ( V_26 == V_8 ) {
F_15 ( V_43 , L_37 ,
F_41 ( F_27 ( V_4 ) ) ) ;
}
#endif
if ( V_22 == V_8 ) {
F_15 ( V_43 , L_38 ) ;
F_42 ( V_43 , F_43 ( V_4 ) ) ;
F_15 ( V_43 , L_36 ) ;
}
if ( V_23 == V_8 ) {
F_15 ( V_43 , L_39 ) ;
if ( F_44 ( V_4 ) )
F_42 ( V_43 , F_44 ( V_4 ) ) ;
else
F_15 ( V_43 , L_40 ) ;
F_15 ( V_43 , L_36 ) ;
}
if ( V_27 == V_8 ) {
int V_59 ;
unsigned int V_60 ;
unsigned char V_61 [ V_62 ] ;
if ( ! F_45 ( V_4 , V_37 , V_61 , & V_60 ) ) {
F_15 ( V_38 , L_41 ) ;
goto V_42;
}
F_15 ( V_43 , L_42 ,
F_46 ( F_47 ( V_37 ) ) ) ;
for ( V_59 = 0 ; V_59 < ( int ) V_60 ; V_59 ++ ) {
F_15 ( V_43 , L_43 , V_61 [ V_59 ] , ( V_59 + 1 == ( int ) V_60 )
? '\n' : ':' ) ;
}
}
}
}
V_12 = F_4 ( F_5 () ) ;
if ( V_12 == NULL ) {
F_48 ( V_38 ) ;
goto V_42;
}
if ( V_17 == NULL ) {
F_6 ( V_12 , stdout , V_40 ) ;
#ifdef F_8
{
T_2 * V_44 = F_4 ( F_9 () ) ;
V_12 = F_10 ( V_44 , V_12 ) ;
}
#endif
} else {
if ( F_49 ( V_12 , V_17 ) <= 0 ) {
perror ( V_17 ) ;
goto V_42;
}
}
if ( V_25 )
F_50 ( V_12 , V_4 ) ;
if ( V_24 ) {
V_7 = 0 ;
goto V_42;
}
if ( V_11 )
V_4 -> V_63 -> V_53 [ V_4 -> V_63 -> V_64 - 1 ] ^= 0x1 ;
if ( V_14 == V_65 )
V_8 = ( int ) F_51 ( V_12 , V_4 ) ;
else if ( V_14 == V_45 )
V_8 = F_52 ( V_12 , V_4 ) ;
else {
F_15 ( V_38 , L_44 ) ;
goto V_42;
}
if ( ! V_8 ) {
F_15 ( V_38 , L_45 ) ;
goto V_42;
}
V_7 = 0 ;
V_42:
if ( V_7 != 0 )
F_48 ( V_38 ) ;
F_53 ( V_12 ) ;
F_53 ( V_43 ) ;
V_43 = NULL ;
F_34 ( V_4 ) ;
if ( V_30 ) {
F_54 ( & V_31 ) ;
F_55 ( V_30 ) ;
}
F_56 () ;
F_57 ( V_7 ) ;
}
