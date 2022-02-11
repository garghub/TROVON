int MAIN ( int V_1 , char * * V_2 )
{
int V_3 = 0 ;
int V_4 = 0 ;
char * * args ;
char * V_5 = L_1 , * V_6 = L_2 ;
char * V_7 = NULL , * V_8 = NULL ;
char * V_9 = NULL , * V_10 = NULL ;
char * V_11 = NULL , * V_12 = NULL , * V_13 = NULL ;
T_1 * V_14 = NULL ;
T_2 * V_15 = NULL ;
T_3 * V_16 = NULL ;
T_4 * V_17 = NULL , * V_18 = NULL , * V_19 = NULL ;
T_5 * V_20 = NULL ;
F_1 ( T_4 ) * V_21 = NULL , * V_22 = NULL ;
T_6 * V_23 = NULL , * V_24 = NULL , * V_25 = NULL ;
int V_26 = 0 ;
int V_27 = V_28 ;
char * V_29 = NULL , * V_30 = NULL , * V_31 = NULL ;
char * V_32 = NULL , * V_33 = NULL ;
char * V_34 = NULL , * V_35 = NULL ;
char * V_36 = NULL ;
int V_37 = 0 ;
int V_38 = V_39 , V_40 = V_39 ;
args = V_2 + 1 ;
V_4 = 1 ;
while ( ! V_26 && * args && * args [ 0 ] == '-' ) {
if ( ! strcmp ( * args , L_3 ) ) V_3 = V_41 ;
else if ( ! strcmp ( * args , L_4 ) ) V_3 = V_42 ;
else if ( ! strcmp ( * args , L_5 ) ) V_3 = V_43 ;
else if ( ! strcmp ( * args , L_6 ) ) V_3 = V_44 ;
else if ( ! strcmp ( * args , L_7 ) ) V_3 = V_45 ;
#ifndef F_2
else if ( ! strcmp ( * args , L_8 ) )
V_14 = F_3 () ;
else if ( ! strcmp ( * args , L_9 ) )
V_14 = F_4 () ;
#endif
#ifndef F_5
else if ( ! strcmp ( * args , L_10 ) )
V_14 = F_6 () ;
else if ( ! strcmp ( * args , L_11 ) )
V_14 = F_7 () ;
else if ( ! strcmp ( * args , L_12 ) )
V_14 = F_8 () ;
#endif
else if ( ! strcmp ( * args , L_13 ) )
V_27 |= V_46 ;
else if ( ! strcmp ( * args , L_14 ) )
V_27 |= V_47 ;
else if ( ! strcmp ( * args , L_15 ) )
V_27 |= V_48 ;
else if ( ! strcmp ( * args , L_16 ) )
V_27 |= V_49 ;
else if ( ! strcmp ( * args , L_17 ) )
V_27 |= V_50 ;
else if ( ! strcmp ( * args , L_18 ) )
V_27 |= V_51 ;
else if ( ! strcmp ( * args , L_19 ) )
V_27 &= ~ V_28 ;
else if ( ! strcmp ( * args , L_20 ) )
V_27 |= V_52 ;
else if ( ! strcmp ( * args , L_21 ) )
V_27 |= V_53 ;
else if ( ! strcmp ( * args , L_22 ) )
V_27 |= V_54 ;
else if ( ! strcmp ( * args , L_23 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_36 = * args ;
} else V_26 = 1 ;
V_37 = 1 ;
} else if ( ! strcmp ( * args , L_24 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_34 = * args ;
} else V_26 = 1 ;
} else if ( ! strcmp ( * args , L_25 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_29 = * args ;
} else V_26 = 1 ;
} else if ( ! strcmp ( * args , L_26 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_30 = * args ;
} else V_26 = 1 ;
} else if ( ! strcmp ( * args , L_27 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_31 = * args ;
} else V_26 = 1 ;
} else if ( ! strcmp ( * args , L_28 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_9 = * args ;
} else V_26 = 1 ;
} else if ( ! strcmp ( * args , L_29 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_10 = * args ;
} else V_26 = 1 ;
} else if ( ! strcmp ( * args , L_30 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_12 = * args ;
} else V_26 = 1 ;
} else if ( ! strcmp ( * args , L_31 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_11 = * args ;
} else V_26 = 1 ;
} else if ( ! strcmp ( * args , L_32 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_32 = * args ;
} else V_26 = 1 ;
} else if ( ! strcmp ( * args , L_33 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_33 = * args ;
} else V_26 = 1 ;
} else if ( ! strcmp ( * args , L_34 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_7 = * args ;
} else V_26 = 1 ;
} else if ( ! strcmp ( * args , L_35 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_38 = F_9 ( * args ) ;
} else V_26 = 1 ;
} else if ( ! strcmp ( * args , L_36 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_40 = F_9 ( * args ) ;
} else V_26 = 1 ;
} else if ( ! strcmp ( * args , L_37 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_8 = * args ;
} else V_26 = 1 ;
} else if ( ! strcmp ( * args , L_38 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_13 = * args ;
} else V_26 = 1 ;
} else V_26 = 1 ;
args ++ ;
}
if( V_3 == V_43 ) {
if( ! V_9 ) {
F_10 ( V_55 , L_39 ) ;
V_26 = 1 ;
}
V_37 = 1 ;
} else if( V_3 == V_42 ) {
if( ! V_10 ) {
F_10 ( V_55 , L_40 ) ;
V_26 = 1 ;
}
} else if( V_3 == V_41 ) {
if( ! * args ) {
F_10 ( V_55 , L_41 ) ;
V_26 = 1 ;
}
V_37 = 1 ;
} else if( ! V_3 ) V_26 = 1 ;
if ( V_26 ) {
F_10 ( V_55 , L_42 ) ;
F_10 ( V_55 , L_43 ) ;
F_10 ( V_55 , L_44 ) ;
F_10 ( V_55 , L_45 ) ;
F_10 ( V_55 , L_46 ) ;
F_10 ( V_55 , L_47 ) ;
F_10 ( V_55 , L_48 ) ;
#ifndef F_2
F_10 ( V_55 , L_49 ) ;
F_10 ( V_55 , L_50 ) ;
#endif
#ifndef F_5
F_10 ( V_55 , L_51 ) ;
F_10 ( V_55 , L_52 ) ;
F_10 ( V_55 , L_53 ) ;
#endif
F_10 ( V_55 , L_54 ) ;
F_10 ( V_55 , L_55 ) ;
F_10 ( V_55 , L_56 ) ;
F_10 ( V_55 , L_57 ) ;
F_10 ( V_55 , L_58 ) ;
F_10 ( V_55 , L_59 ) ;
F_10 ( V_55 , L_60 ) ;
F_10 ( V_55 , L_61 ) ;
F_10 ( V_55 , L_62 ) ;
F_10 ( V_55 , L_63 ) ;
F_10 ( V_55 , L_64 ) ;
F_10 ( V_55 , L_65 ) ;
F_10 ( V_55 , L_66 ) ;
F_10 ( V_55 , L_67 ) ;
F_10 ( V_55 , L_68 ) ;
F_10 ( V_55 , L_69 ) ;
F_10 ( V_55 , L_70 ) ;
F_10 ( V_55 , L_71 ) ;
F_10 ( V_55 , L_72 ) ;
F_10 ( V_55 , L_73 ) ;
F_10 ( V_55 , L_74 ) ;
F_10 ( V_55 , L_75 ) ;
F_10 ( V_55 , L_76 , V_56 , V_56 ) ;
F_10 ( V_55 , L_77 ) ;
F_10 ( V_55 , L_78 ) ;
F_10 ( V_55 , L_79 ) ;
goto V_57;
}
if( ! F_11 ( V_55 , V_34 , NULL , & V_35 , NULL ) ) {
F_10 ( V_55 , L_80 ) ;
goto V_57;
}
if ( V_37 ) {
F_12 ( NULL , V_55 , ( V_36 != NULL ) ) ;
if ( V_36 != NULL )
F_10 ( V_55 , L_81 ,
F_13 ( V_36 ) ) ;
}
V_4 = 2 ;
if( V_3 != V_43 ) V_27 &= ~ V_28 ;
if( V_3 & V_58 ) {
if( V_27 & V_53 ) V_5 = L_82 ;
if( V_40 == V_59 ) V_6 = L_83 ;
} else {
if( V_27 & V_53 ) V_6 = L_83 ;
if( V_38 == V_59 ) V_5 = L_82 ;
}
if( V_3 == V_41 ) {
if ( ! V_14 ) {
#ifndef F_5
V_14 = F_6 () ;
#else
F_10 ( V_55 , L_84 ) ;
goto V_57;
#endif
}
V_21 = F_14 () ;
while ( * args ) {
if( ! ( V_17 = F_15 ( V_55 , * args , V_60 ) ) ) {
F_10 ( V_55 , L_85 , * args ) ;
goto V_57;
}
F_16 ( V_21 , V_17 ) ;
V_17 = NULL ;
args ++ ;
}
}
if( V_9 && ( V_3 == V_43 ) ) {
if( ! ( V_19 = F_15 ( V_55 , V_9 , V_60 ) ) ) {
F_10 ( V_55 , L_86 , V_9 ) ;
goto V_57;
}
}
if( V_11 ) {
if( ! ( V_22 = F_17 ( V_55 , V_11 , V_60 ) ) ) {
F_10 ( V_55 , L_87 , V_11 ) ;
F_18 ( V_55 ) ;
goto V_57;
}
}
if( V_10 && ( V_3 == V_42 ) ) {
if( ! ( V_18 = F_15 ( V_55 , V_10 , V_60 ) ) ) {
F_10 ( V_55 , L_85 , V_10 ) ;
F_18 ( V_55 ) ;
goto V_57;
}
}
if( V_3 == V_42 ) {
if( ! V_12 ) V_12 = V_10 ;
} else if( V_3 == V_43 ) {
if( ! V_12 ) V_12 = V_9 ;
} else V_12 = NULL ;
if( V_12 ) {
if( ! ( V_20 = F_19 ( V_55 , V_12 , V_60 , V_35 ) ) ) {
F_10 ( V_55 , L_85 , V_12 ) ;
F_18 ( V_55 ) ;
goto V_57;
}
}
if ( V_7 ) {
if ( ! ( V_23 = F_20 ( V_7 , V_5 ) ) ) {
F_10 ( V_55 ,
L_88 , V_7 ) ;
goto V_57;
}
} else V_23 = F_21 ( V_61 , V_62 ) ;
if ( V_8 ) {
if ( ! ( V_24 = F_20 ( V_8 , V_6 ) ) ) {
F_10 ( V_55 ,
L_89 , V_8 ) ;
goto V_57;
}
} else {
V_24 = F_21 ( stdout , V_62 ) ;
#ifdef F_22
{
T_6 * V_63 = F_23 ( F_24 () ) ;
V_24 = F_25 ( V_63 , V_24 ) ;
}
#endif
}
if( V_3 == V_44 ) {
if( ! ( V_16 = F_26 ( V_32 , V_33 ) ) ) goto V_57;
}
V_4 = 3 ;
if( V_3 == V_41 ) {
V_15 = F_27 ( V_21 , V_23 , V_14 , V_27 ) ;
} else if( V_3 == V_43 ) {
V_15 = F_28 ( V_19 , V_20 , V_22 , V_23 , V_27 ) ;
F_29 ( V_23 ) ;
} else {
if( V_38 == V_39 )
V_15 = F_30 ( V_23 , & V_25 ) ;
else if( V_38 == V_60 )
V_15 = F_31 ( V_23 , NULL , NULL , NULL ) ;
else if( V_38 == V_59 )
V_15 = F_32 ( V_23 , NULL ) ;
else {
F_10 ( V_55 , L_90 ) ;
goto V_57;
}
if( ! V_15 ) {
F_10 ( V_55 , L_91 ) ;
goto V_57;
}
if( V_13 ) {
F_33 ( V_25 ) ;
if( ! ( V_25 = F_20 ( V_13 , L_82 ) ) ) {
F_10 ( V_55 , L_92 , V_13 ) ;
goto V_57;
}
}
}
if( ! V_15 ) {
F_10 ( V_55 , L_93 ) ;
goto V_57;
}
V_4 = 4 ;
if( V_3 == V_42 ) {
if( ! F_34 ( V_15 , V_20 , V_18 , V_24 , V_27 ) ) {
F_10 ( V_55 , L_94 ) ;
goto V_57;
}
} else if( V_3 == V_44 ) {
F_1 ( T_4 ) * V_64 ;
if( F_35 ( V_15 , V_22 , V_16 , V_25 , V_24 , V_27 ) ) {
F_10 ( V_55 , L_95 ) ;
} else {
F_10 ( V_55 , L_96 ) ;
goto V_57;
}
V_64 = F_36 ( V_15 , V_22 , V_27 ) ;
if( ! F_37 ( V_9 , V_64 ) ) {
F_10 ( V_55 , L_97 ,
V_9 ) ;
V_4 = 5 ;
goto V_57;
}
F_38 ( V_64 ) ;
} else if( V_3 == V_45 ) {
F_39 ( V_24 , V_15 ) ;
} else {
if( V_29 ) F_10 ( V_24 , L_98 , V_29 ) ;
if( V_30 ) F_10 ( V_24 , L_99 , V_30 ) ;
if( V_31 ) F_10 ( V_24 , L_100 , V_31 ) ;
if( V_40 == V_39 )
F_40 ( V_24 , V_15 , V_23 , V_27 ) ;
else if( V_40 == V_60 )
F_39 ( V_24 , V_15 ) ;
else if( V_40 == V_59 )
F_41 ( V_24 , V_15 ) ;
else {
F_10 ( V_55 , L_101 ) ;
goto V_57;
}
}
V_4 = 0 ;
V_57:
if ( V_37 )
F_42 ( NULL , V_55 ) ;
if( V_4 ) F_18 ( V_55 ) ;
F_43 ( V_21 , V_65 ) ;
F_43 ( V_22 , V_65 ) ;
F_44 ( V_16 ) ;
V_65 ( V_17 ) ;
V_65 ( V_18 ) ;
V_65 ( V_19 ) ;
F_45 ( V_20 ) ;
F_46 ( V_15 ) ;
F_33 ( V_23 ) ;
F_33 ( V_25 ) ;
F_47 ( V_24 ) ;
if( V_35 ) F_48 ( V_35 ) ;
return ( V_4 ) ;
}
static T_3 * F_26 ( char * V_32 , char * V_33 )
{
T_3 * V_16 ;
T_7 * V_66 ;
if( ! ( V_16 = F_49 () ) ) goto V_57;
V_66 = F_50 ( V_16 , F_51 () ) ;
if ( V_66 == NULL ) goto V_57;
if ( V_32 ) {
if( ! F_52 ( V_66 , V_32 , V_67 ) ) {
F_10 ( V_55 , L_102 , V_32 ) ;
goto V_57;
}
} else F_52 ( V_66 , NULL , V_68 ) ;
V_66 = F_50 ( V_16 , F_53 () ) ;
if ( V_66 == NULL ) goto V_57;
if ( V_33 ) {
if( ! F_54 ( V_66 , V_33 , V_67 ) ) {
F_10 ( V_55 , L_103 , V_33 ) ;
goto V_57;
}
} else F_54 ( V_66 , NULL , V_68 ) ;
F_55 () ;
return V_16 ;
V_57:
F_44 ( V_16 ) ;
return NULL ;
}
