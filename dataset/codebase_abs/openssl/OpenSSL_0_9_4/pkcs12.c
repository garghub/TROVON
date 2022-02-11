int MAIN ( int V_1 , char * * V_2 )
{
char * V_3 = NULL , * V_4 = NULL , * V_5 = NULL ;
char * V_6 = NULL ;
T_1 * V_7 = NULL , * V_8 = NULL , * V_9 = NULL , * V_10 = NULL ;
char * * args ;
char * V_11 = NULL ;
T_2 * V_12 = NULL ;
char V_13 [ 50 ] , V_14 [ 50 ] ;
int V_15 = 0 ;
int V_16 = 0 ;
int V_17 = 0 ;
int V_18 = 0 ;
int V_19 = V_20 ;
int V_21 = 1 ;
int V_22 = 0 ;
int V_23 = 0 ;
int V_24 = V_25 ;
int V_26 = 1 ;
int V_27 = 1 ;
int V_28 = 0 ;
T_3 * V_29 = NULL ;
char * V_30 = NULL , * V_31 = NULL ;
F_1 () ;
V_32 = F_2 () ;
if ( V_33 == NULL ) V_33 = F_3 ( V_34 , V_35 ) ;
args = V_2 + 1 ;
while ( * args ) {
if ( * args [ 0 ] == '-' ) {
if ( ! strcmp ( * args , L_1 ) ) V_16 |= V_36 ;
else if ( ! strcmp ( * args , L_2 ) ) V_23 = V_37 ;
else if ( ! strcmp ( * args , L_3 ) ) V_23 = V_38 ;
else if ( ! strcmp ( * args , L_4 ) ) V_16 |= V_39 ;
else if ( ! strcmp ( * args , L_5 ) ) V_16 |= V_40 ;
else if ( ! strcmp ( * args , L_6 ) ) V_16 |= V_41 ;
else if ( ! strcmp ( * args , L_7 ) ) V_16 |= ( V_36 | V_39 ) ;
else if ( ! strcmp ( * args , L_8 ) ) V_16 |= V_42 ;
else if ( ! strcmp ( * args , L_9 ) ) V_17 = 1 ;
else if ( ! strcmp ( * args , L_10 ) ) V_22 = 1 ;
else if ( ! strcmp ( * args , L_11 ) ) V_27 = 0 ;
else if ( ! strcmp ( * args , L_12 ) )
V_24 = V_43 ;
else if ( ! strcmp ( * args , L_13 ) ) V_15 = 1 ;
else if ( ! strcmp ( * args , L_14 ) ) V_32 = F_4 () ;
#ifndef F_5
else if ( ! strcmp ( * args , L_15 ) ) V_32 = F_6 () ;
#endif
else if ( ! strcmp ( * args , L_16 ) ) V_32 = F_2 () ;
else if ( ! strcmp ( * args , L_17 ) ) V_19 = 1 ;
else if ( ! strcmp ( * args , L_18 ) )
V_21 = V_20 ;
else if ( ! strcmp ( * args , L_19 ) ) V_32 = NULL ;
else if ( ! strcmp ( * args , L_20 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_5 = * args ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_21 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_6 = * args ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_22 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_11 = * args ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_23 ) ) {
if ( args [ 1 ] ) {
args ++ ;
if ( ! V_29 ) V_29 = F_7 ( NULL ) ;
F_8 ( V_29 , * args ) ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_24 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_3 = * args ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_25 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_4 = * args ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_26 ) ) {
if ( args [ 1 ] ) {
args ++ ;
if( ! ( V_30 = getenv ( * args ) ) ) {
F_9 ( V_33 ,
L_27 , * args ) ;
goto V_44;
}
V_28 = 1 ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_28 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_30 = * args ;
V_28 = 1 ;
} else V_18 = 1 ;
} else V_18 = 1 ;
} else V_18 = 1 ;
args ++ ;
}
if ( V_18 ) {
F_9 ( V_33 , L_29 ) ;
F_9 ( V_33 , L_30 ) ;
F_9 ( V_33 , L_31 ) ;
F_9 ( V_33 , L_32 ) ;
F_9 ( V_33 , L_33 ) ;
F_9 ( V_33 , L_34 ) ;
F_9 ( V_33 , L_35 ) ;
F_9 ( V_33 , L_36 ) ;
F_9 ( V_33 , L_37 ) ;
F_9 ( V_33 , L_38 ) ;
F_9 ( V_33 , L_39 ) ;
F_9 ( V_33 , L_40 ) ;
F_9 ( V_33 , L_41 ) ;
F_9 ( V_33 , L_42 ) ;
F_9 ( V_33 , L_43 ) ;
F_9 ( V_33 , L_44 ) ;
F_9 ( V_33 , L_45 ) ;
F_9 ( V_33 , L_46 ) ;
F_9 ( V_33 , L_47 ) ;
#ifndef F_5
F_9 ( V_33 , L_48 ) ;
#endif
F_9 ( V_33 , L_49 ) ;
F_9 ( V_33 , L_50 ) ;
F_9 ( V_33 , L_51 ) ;
F_9 ( V_33 , L_52 ) ;
F_9 ( V_33 , L_53 ) ;
F_9 ( V_33 , L_54 ) ;
F_9 ( V_33 , L_55 ) ;
F_9 ( V_33 , L_56 ) ;
F_9 ( V_33 , L_57 ) ;
goto V_44;
}
if( V_30 ) V_31 = V_30 ;
else {
V_30 = V_13 ;
V_31 = V_14 ;
}
F_10 () ;
if ( ! V_3 ) V_7 = F_3 ( V_45 , V_35 ) ;
else V_7 = F_11 ( V_3 , L_58 ) ;
if ( ! V_7 ) {
F_9 ( V_33 , L_59 ,
V_3 ? V_3 : L_60 ) ;
perror ( V_3 ) ;
goto V_44;
}
if ( V_6 ) {
if( ! ( V_10 = F_11 ( V_6 , L_61 ) ) ) {
F_9 ( V_33 , L_62 , V_6 ) ;
perror ( V_6 ) ;
goto V_44;
}
}
if ( V_5 ) {
if( ! ( V_9 = F_11 ( V_5 , L_61 ) ) ) {
F_9 ( V_33 , L_63 , V_5 ) ;
perror ( V_5 ) ;
goto V_44;
}
}
if ( ! V_4 ) V_8 = F_3 ( stdout , V_35 ) ;
else V_8 = F_11 ( V_4 , L_64 ) ;
if ( ! V_8 ) {
F_9 ( V_33 , L_65 ,
V_4 ? V_4 : L_66 ) ;
perror ( V_4 ) ;
goto V_44;
}
if ( V_22 ) {
if( F_12 ( V_14 , 50 , L_67 , V_15 ) )
{
F_9 ( V_33 , L_68 ) ;
goto V_44;
}
}
if ( V_15 ) {
T_4 * V_46 ;
T_3 * V_47 , * V_48 ;
T_5 * V_49 ;
T_6 * V_50 ;
T_7 * V_51 ;
T_8 * V_52 = NULL , * V_53 = NULL ;
F_13 ( T_8 ) * V_54 ;
char * V_55 ;
int V_56 ;
unsigned char V_57 [ V_58 ] ;
unsigned int V_59 = 0 ;
V_46 = F_14 ( V_9 ? V_9 : V_7 , NULL , NULL , NULL ) ;
if ( ! V_9 ) ( void ) F_15 ( V_7 ) ;
if ( ! V_46 ) {
F_9 ( V_33 , L_69 ) ;
F_16 ( V_33 ) ;
goto V_44;
}
V_54 = F_17 ( NULL ) ;
if( ! F_18 ( V_7 , V_54 ) ) {
F_9 ( V_33 , L_70 ) ;
F_16 ( V_33 ) ;
goto V_44;
}
for( V_56 = 0 ; V_56 < F_19 ( V_54 ) ; V_56 ++ ) {
V_53 = F_20 ( V_54 , V_56 ) ;
if( F_21 ( V_53 , V_46 ) ) {
F_22 ( V_52 , F_23 () , V_57 , & V_59 ) ;
break;
}
}
if( ! V_59 ) {
F_9 ( V_33 , L_71 ) ;
goto V_44;
}
V_47 = F_7 ( NULL ) ;
if ( V_10 ) {
if( ! F_18 ( V_10 , V_54 ) ) {
F_9 ( V_33 , L_72 ) ;
F_16 ( V_33 ) ;
goto V_44;
}
F_24 ( V_10 ) ;
}
if ( V_17 ) {
int V_60 ;
F_13 ( T_8 ) * V_61 ;
V_60 = F_25 ( V_53 , & V_61 ) ;
if ( V_60 ) {
F_9 ( V_33 , L_73 ,
F_26 ( V_60 ) ) ;
goto V_44;
}
for ( V_56 = 1 ; V_56 < F_19 ( V_61 ) ; V_56 ++ )
F_27 ( V_54 , F_20 ( V_61 , V_56 ) ) ;
F_28 ( V_61 ) ;
}
for( V_56 = 0 ; V_56 < F_19 ( V_54 ) ; V_56 ++ ) {
V_52 = F_20 ( V_54 , V_56 ) ;
V_49 = F_29 ( V_52 ) ;
if( V_52 == V_53 ) {
if( V_11 ) F_30 ( V_49 , V_11 , - 1 ) ;
F_31 ( V_49 , V_57 , V_59 ) ;
} else if( ( V_55 = F_32 ( V_29 ) ) )
F_30 ( V_49 , V_55 , - 1 ) ;
F_8 ( V_47 , ( char * ) V_49 ) ;
}
if ( V_29 ) F_33 ( V_29 ) ;
if( ! V_28 &&
F_12 ( V_13 , 50 , L_74 , 1 ) ) {
F_9 ( V_33 , L_68 ) ;
goto V_44;
}
if ( ! V_22 ) strcpy ( V_14 , V_13 ) ;
V_51 = F_34 ( V_24 , V_30 , - 1 , NULL , 0 ,
V_19 , V_47 ) ;
F_35 ( V_47 , V_62 ) ;
if ( ! V_51 ) {
F_16 ( V_33 ) ;
goto V_44;
}
V_48 = F_7 ( NULL ) ;
F_8 ( V_48 , ( char * ) V_51 ) ;
V_50 = F_36 ( V_46 ) ;
F_37 ( V_46 ) ;
if( V_23 ) F_38 ( V_50 , V_23 ) ;
V_49 = F_39 ( V_43 ,
V_30 , - 1 , NULL , 0 , V_19 , V_50 ) ;
F_40 ( V_50 ) ;
if ( V_11 ) F_30 ( V_49 , V_11 , - 1 ) ;
F_31 ( V_49 , V_57 , V_59 ) ;
V_47 = F_7 ( NULL ) ;
F_8 ( V_47 , ( char * ) V_49 ) ;
V_51 = F_41 ( V_47 ) ;
F_35 ( V_47 , V_62 ) ;
F_8 ( V_48 , ( char * ) V_51 ) ;
V_12 = F_42 ( V_63 ) ;
F_43 ( V_12 , V_48 ) ;
F_35 ( V_48 , V_64 ) ;
F_44 ( V_12 , V_31 , - 1 , NULL , 0 , V_21 , NULL ) ;
F_45 ( V_8 , V_12 ) ;
F_46 ( V_12 ) ;
V_26 = 0 ;
goto V_44;
}
if ( ! ( V_12 = F_47 ( V_7 , NULL ) ) ) {
F_16 ( V_33 ) ;
goto V_44;
}
if( ! V_28 && F_12 ( V_13 , 50 , L_75 , 0 ) ) {
F_9 ( V_33 , L_68 ) ;
goto V_44;
}
if ( ! V_22 ) strcpy ( V_14 , V_13 ) ;
if ( V_16 & V_42 ) F_9 ( V_33 , L_76 , V_12 -> V_65 -> V_19 ? F_48 ( V_12 -> V_65 -> V_19 ) : 1 ) ;
if( V_27 ) {
if ( ! F_49 ( V_12 , V_31 , - 1 ) ) {
F_9 ( V_33 , L_77 ) ;
F_16 ( V_33 ) ;
goto V_44;
} else F_9 ( V_33 , L_78 ) ;
}
if ( ! F_50 ( V_8 , V_12 , V_30 , - 1 , V_16 ) ) {
F_9 ( V_33 , L_79 ) ;
F_16 ( V_33 ) ;
goto V_44;
}
F_46 ( V_12 ) ;
V_26 = 0 ;
V_44:
F_24 ( V_8 ) ;
EXIT ( V_26 ) ;
}
int F_51 ( T_1 * V_8 , T_8 * V_66 )
{
char V_67 [ 256 ] ;
F_52 ( F_53 ( V_66 ) , V_67 , 256 ) ;
F_54 ( V_8 , L_80 ) ;
F_54 ( V_8 , V_67 ) ;
F_52 ( F_55 ( V_66 ) , V_67 , 256 ) ;
F_54 ( V_8 , L_81 ) ;
F_54 ( V_8 , V_67 ) ;
F_54 ( V_8 , L_82 ) ;
return 0 ;
}
int F_50 ( T_1 * V_8 , T_2 * V_12 , char * V_13 ,
int V_68 , int V_16 )
{
T_3 * V_69 , * V_47 ;
int V_56 , V_70 ;
T_7 * V_71 ;
if ( ! ( V_69 = F_56 ( V_12 ) ) ) return 0 ;
for ( V_56 = 0 ; V_56 < F_57 ( V_69 ) ; V_56 ++ ) {
V_71 = ( T_7 * ) F_58 ( V_69 , V_56 ) ;
V_70 = F_59 ( V_71 -> type ) ;
if ( V_70 == V_63 ) {
V_47 = F_60 ( V_71 ) ;
if ( V_16 & V_42 ) F_9 ( V_33 , L_83 ) ;
} else if ( V_70 == V_72 ) {
if ( V_16 & V_42 ) {
F_9 ( V_33 , L_84 ) ;
F_61 ( V_33 ,
V_71 -> V_73 . V_74 -> V_75 -> V_76 ) ;
}
V_47 = F_62 ( V_71 , V_13 , V_68 ) ;
} else continue;
if ( ! V_47 ) return 0 ;
if ( ! F_63 ( V_8 , V_47 , V_13 , V_68 ,
V_16 ) ) {
F_35 ( V_47 , V_62 ) ;
return 0 ;
}
F_35 ( V_47 , V_62 ) ;
}
F_35 ( V_69 , V_64 ) ;
return 1 ;
}
int F_63 ( T_1 * V_8 , T_3 * V_47 , char * V_13 ,
int V_68 , int V_16 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < F_57 ( V_47 ) ; V_56 ++ ) {
if ( ! F_64 ( V_8 ,
( T_5 * ) F_58 ( V_47 , V_56 ) , V_13 , V_68 ,
V_16 ) ) return 0 ;
}
return 1 ;
}
int F_64 ( T_1 * V_8 , T_5 * V_49 , char * V_13 ,
int V_68 , int V_16 )
{
T_4 * V_77 ;
T_6 * V_50 ;
T_8 * V_78 ;
switch ( F_65 ( V_49 ) )
{
case V_79 :
if ( V_16 & V_42 ) F_9 ( V_33 , L_85 ) ;
if ( V_16 & V_36 ) return 1 ;
F_66 ( V_8 , V_49 -> V_80 , L_86 ) ;
V_50 = V_49 -> V_81 . V_82 ;
if ( ! ( V_77 = F_67 ( V_50 ) ) ) return 0 ;
F_66 ( V_8 , V_50 -> V_83 , L_87 ) ;
F_68 ( V_8 , V_77 , V_32 , NULL , 0 , NULL , NULL ) ;
F_37 ( V_77 ) ;
break;
case V_84 :
if ( V_16 & V_42 ) {
F_9 ( V_33 , L_88 ) ;
F_61 ( V_33 , V_49 -> V_81 . V_85 -> V_86 ) ;
}
if ( V_16 & V_36 ) return 1 ;
F_66 ( V_8 , V_49 -> V_80 , L_86 ) ;
if ( ! ( V_50 = F_69 ( V_49 , V_13 , V_68 ) ) )
return 0 ;
if ( ! ( V_77 = F_67 ( V_50 ) ) ) return 0 ;
F_66 ( V_8 , V_50 -> V_83 , L_87 ) ;
F_40 ( V_50 ) ;
F_68 ( V_8 , V_77 , V_32 , NULL , 0 , NULL , NULL ) ;
F_37 ( V_77 ) ;
break;
case V_87 :
if ( V_16 & V_42 ) F_9 ( V_33 , L_89 ) ;
if ( V_16 & V_39 ) return 1 ;
if ( F_70 ( V_49 , V_88 ) ) {
if ( V_16 & V_41 ) return 1 ;
} else if ( V_16 & V_40 ) return 1 ;
F_66 ( V_8 , V_49 -> V_80 , L_86 ) ;
if ( F_71 ( V_49 ) != V_89 )
return 1 ;
if ( ! ( V_78 = F_72 ( V_49 ) ) ) return 0 ;
F_51 ( V_8 , V_78 ) ;
F_73 ( V_8 , V_78 ) ;
F_74 ( V_78 ) ;
break;
case V_90 :
if ( V_16 & V_42 ) F_9 ( V_33 , L_90 ) ;
F_66 ( V_8 , V_49 -> V_80 , L_86 ) ;
return F_63 ( V_8 , V_49 -> V_81 . V_48 , V_13 ,
V_68 , V_16 ) ;
default:
F_9 ( V_33 , L_91 ) ;
F_75 ( V_33 , V_49 -> type ) ;
F_9 ( V_33 , L_82 ) ;
return 1 ;
break;
}
return 1 ;
}
int F_61 ( T_1 * V_66 , T_9 * V_91 )
{
T_10 * V_92 ;
unsigned char * V_93 ;
V_93 = V_91 -> V_94 -> V_81 . V_95 -> V_96 ;
V_92 = F_76 ( NULL , & V_93 , V_91 -> V_94 -> V_81 . V_95 -> V_97 ) ;
F_9 ( V_33 , L_92 ,
F_77 ( F_59 ( V_91 -> V_76 ) ) , F_48 ( V_92 -> V_19 ) ) ;
F_78 ( V_92 ) ;
return 0 ;
}
void F_79 ( T_1 * V_8 , unsigned char * V_67 , int V_98 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_98 ; V_56 ++ ) F_9 ( V_8 , L_93 , V_67 [ V_56 ] ) ;
}
