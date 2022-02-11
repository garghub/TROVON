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
V_7 = F_11 ( F_12 () ) ;
V_8 = F_11 ( F_12 () ) ;
if ( ! V_3 ) F_13 ( V_7 , V_45 , V_35 ) ;
else {
if ( F_14 ( V_7 , V_3 ) <= 0 ) {
perror ( V_3 ) ;
goto V_44;
}
}
if ( V_6 ) {
V_10 = F_11 ( F_12 () ) ;
if ( F_14 ( V_10 , V_6 ) <= 0 ) {
perror ( V_6 ) ;
goto V_44;
}
}
if ( V_5 ) {
V_9 = F_11 ( F_12 () ) ;
if ( F_14 ( V_9 , V_5 ) <= 0 ) {
perror ( V_5 ) ;
goto V_44;
}
}
if ( ! V_4 ) F_13 ( V_8 , stdout , V_35 ) ;
else {
if ( F_15 ( V_8 , V_4 ) <= 0 ) {
perror ( V_4 ) ;
goto V_44;
}
}
if ( V_22 ) {
if( F_16 ( V_14 , 50 , L_58 , V_15 ) ) {
F_9 ( V_33 , L_59 ) ;
goto V_44;
}
}
if ( V_15 ) {
T_4 * V_46 ;
T_3 * V_47 , * V_48 ;
T_5 * V_49 ;
T_6 * V_50 ;
T_7 * V_51 ;
T_8 * V_52 , * V_53 = NULL ;
T_3 * V_54 ;
char * V_55 ;
int V_56 , V_57 = 0 ;
unsigned char V_58 [ V_59 ] ;
unsigned int V_60 ;
V_46 = F_17 ( V_9 ? V_9 : V_7 , NULL , NULL ) ;
if ( ! V_9 ) F_18 ( V_7 ) ;
if ( ! V_46 ) {
F_9 ( V_33 , L_60 ) ;
F_19 ( V_33 ) ;
goto V_44;
}
V_54 = F_7 ( NULL ) ;
if( ! F_20 ( V_7 , V_54 ) ) {
F_9 ( V_33 , L_61 ) ;
F_19 ( V_33 ) ;
goto V_44;
}
V_47 = F_7 ( NULL ) ;
if ( V_10 ) {
if( ! F_20 ( V_10 , V_54 ) ) {
F_9 ( V_33 , L_62 ) ;
F_19 ( V_33 ) ;
goto V_44;
}
F_21 ( V_10 ) ;
}
for( V_56 = 0 ; V_56 < F_22 ( V_54 ) ; V_56 ++ ) {
V_52 = ( T_8 * ) F_23 ( V_54 , V_56 ) ;
if( F_24 ( V_52 , V_46 ) ) {
V_53 = V_52 ;
break;
}
}
if( ! V_53 ) {
F_9 ( V_33 , L_63 ) ;
goto V_44;
}
if ( V_17 ) {
int V_61 ;
T_3 * V_62 ;
V_61 = F_25 ( V_53 , & V_62 ) ;
if ( V_61 ) {
F_9 ( V_33 , L_64 ,
F_26 ( V_61 ) ) ;
goto V_44;
}
for ( V_56 = 1 ; V_56 < F_22 ( V_62 ) ; V_56 ++ )
F_8 ( V_54 , F_23 ( V_62 , V_56 ) ) ;
F_27 ( V_62 ) ;
}
for( V_56 = 0 ; V_56 < F_22 ( V_54 ) ; V_56 ++ ) {
V_52 = ( T_8 * ) F_23 ( V_54 , V_56 ) ;
V_49 = F_28 ( V_52 ) ;
if( V_52 == V_53 ) {
if( V_11 ) F_29 ( V_49 , V_11 , - 1 ) ;
F_30 ( V_52 , F_31 () , V_58 , & V_60 ) ;
F_32 ( V_49 , V_58 , V_60 ) ;
V_57 = 1 ;
} else if( ( V_55 = F_33 ( V_29 ) ) )
F_29 ( V_49 , V_55 , - 1 ) ;
F_8 ( V_47 , ( char * ) V_49 ) ;
}
if ( V_29 ) F_27 ( V_29 ) ;
if( ! V_28 &&
F_16 ( V_13 , 50 , L_65 , 1 ) ) {
F_9 ( V_33 , L_59 ) ;
goto V_44;
}
if ( ! V_22 ) strcpy ( V_14 , V_13 ) ;
V_51 = F_34 ( V_24 , V_30 , - 1 , NULL , 0 ,
V_19 , V_47 ) ;
F_35 ( V_47 , V_63 ) ;
if ( ! V_51 ) {
F_19 ( V_33 ) ;
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
if ( V_11 ) F_29 ( V_49 , V_11 , - 1 ) ;
if( V_57 ) F_32 ( V_49 , V_58 , V_60 ) ;
V_47 = F_7 ( NULL ) ;
F_8 ( V_47 , ( char * ) V_49 ) ;
V_51 = F_41 ( V_47 ) ;
F_35 ( V_47 , V_63 ) ;
F_8 ( V_48 , ( char * ) V_51 ) ;
V_12 = F_42 ( V_64 ) ;
F_43 ( V_12 , V_48 ) ;
F_35 ( V_48 , V_65 ) ;
F_44 ( V_12 , V_31 , - 1 , NULL , 0 , V_21 , NULL ) ;
F_45 ( V_8 , V_12 ) ;
F_46 ( V_12 ) ;
V_26 = 0 ;
goto V_44;
}
if ( ! ( V_12 = F_47 ( V_7 , NULL ) ) ) {
F_19 ( V_33 ) ;
goto V_44;
}
if( ! V_28 && F_16 ( V_13 , 50 , L_66 , 0 ) ) {
F_9 ( V_33 , L_59 ) ;
goto V_44;
}
if ( ! V_22 ) strcpy ( V_14 , V_13 ) ;
if ( V_16 & V_42 ) F_9 ( V_33 , L_67 , V_12 -> V_66 -> V_19 ? F_48 ( V_12 -> V_66 -> V_19 ) : 1 ) ;
if( V_27 ) {
if ( ! F_49 ( V_12 , V_31 , - 1 ) ) {
F_9 ( V_33 , L_68 ) ;
F_19 ( V_33 ) ;
goto V_44;
} else F_9 ( V_33 , L_69 ) ;
}
if ( ! F_50 ( V_8 , V_12 , V_30 , - 1 , V_16 ) ) {
F_9 ( V_33 , L_70 ) ;
F_19 ( V_33 ) ;
goto V_44;
}
F_46 ( V_12 ) ;
V_26 = 0 ;
V_44:
EXIT ( V_26 ) ;
}
int F_51 ( T_1 * V_8 , T_8 * V_67 )
{
char V_68 [ 256 ] ;
F_52 ( F_53 ( V_67 ) , V_68 , 256 ) ;
F_54 ( V_8 , L_71 ) ;
F_54 ( V_8 , V_68 ) ;
F_52 ( F_55 ( V_67 ) , V_68 , 256 ) ;
F_54 ( V_8 , L_72 ) ;
F_54 ( V_8 , V_68 ) ;
F_54 ( V_8 , L_73 ) ;
return 0 ;
}
int F_50 ( T_1 * V_8 , T_2 * V_12 , char * V_13 ,
int V_69 , int V_16 )
{
T_3 * V_70 , * V_47 ;
int V_56 , V_71 ;
T_7 * V_72 ;
if ( ! ( V_70 = F_56 ( V_12 ) ) ) return 0 ;
for ( V_56 = 0 ; V_56 < F_22 ( V_70 ) ; V_56 ++ ) {
V_72 = ( T_7 * ) F_23 ( V_70 , V_56 ) ;
V_71 = F_57 ( V_72 -> type ) ;
if ( V_71 == V_64 ) {
V_47 = F_58 ( V_72 ) ;
if ( V_16 & V_42 ) F_9 ( V_33 , L_74 ) ;
} else if ( V_71 == V_73 ) {
if ( V_16 & V_42 ) {
F_9 ( V_33 , L_75 ) ;
F_59 ( V_33 ,
V_72 -> V_74 . V_75 -> V_76 -> V_77 ) ;
}
V_47 = F_60 ( V_72 , V_13 , V_69 ) ;
} else continue;
if ( ! V_47 ) return 0 ;
if ( ! F_61 ( V_8 , V_47 , V_13 , V_69 ,
V_16 ) ) {
F_35 ( V_47 , V_63 ) ;
return 0 ;
}
F_35 ( V_47 , V_63 ) ;
}
F_35 ( V_70 , V_65 ) ;
return 1 ;
}
int F_61 ( T_1 * V_8 , T_3 * V_47 , char * V_13 ,
int V_69 , int V_16 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < F_22 ( V_47 ) ; V_56 ++ ) {
if ( ! F_62 ( V_8 ,
( T_5 * ) F_23 ( V_47 , V_56 ) , V_13 , V_69 ,
V_16 ) ) return 0 ;
}
return 1 ;
}
int F_62 ( T_1 * V_8 , T_5 * V_49 , char * V_13 ,
int V_69 , int V_16 )
{
T_4 * V_78 ;
T_6 * V_50 ;
T_8 * V_79 ;
switch ( F_63 ( V_49 ) )
{
case V_80 :
if ( V_16 & V_42 ) F_9 ( V_33 , L_76 ) ;
if ( V_16 & V_36 ) return 1 ;
F_64 ( V_8 , V_49 -> V_81 , L_77 ) ;
V_50 = V_49 -> V_82 . V_83 ;
if ( ! ( V_78 = F_65 ( V_50 ) ) ) return 0 ;
F_64 ( V_8 , V_50 -> V_84 , L_78 ) ;
F_66 ( V_8 , V_78 , V_32 , NULL , 0 , NULL ) ;
F_37 ( V_78 ) ;
break;
case V_85 :
if ( V_16 & V_42 ) {
F_9 ( V_33 , L_79 ) ;
F_59 ( V_33 , V_49 -> V_82 . V_86 -> V_87 ) ;
}
if ( V_16 & V_36 ) return 1 ;
F_64 ( V_8 , V_49 -> V_81 , L_77 ) ;
if ( ! ( V_50 = F_67 ( V_49 , V_13 , V_69 ) ) )
return 0 ;
if ( ! ( V_78 = F_65 ( V_50 ) ) ) return 0 ;
F_64 ( V_8 , V_50 -> V_84 , L_78 ) ;
F_40 ( V_50 ) ;
F_66 ( V_8 , V_78 , V_32 , NULL , 0 , NULL ) ;
F_37 ( V_78 ) ;
break;
case V_88 :
if ( V_16 & V_42 ) F_9 ( V_33 , L_80 ) ;
if ( V_16 & V_39 ) return 1 ;
if ( F_68 ( V_49 , V_89 ) ) {
if ( V_16 & V_41 ) return 1 ;
} else if ( V_16 & V_40 ) return 1 ;
F_64 ( V_8 , V_49 -> V_81 , L_77 ) ;
if ( F_69 ( V_49 ) != V_90 )
return 1 ;
if ( ! ( V_79 = F_70 ( V_49 ) ) ) return 0 ;
F_51 ( V_8 , V_79 ) ;
F_71 ( V_8 , V_79 ) ;
F_72 ( V_79 ) ;
break;
case V_91 :
if ( V_16 & V_42 ) F_9 ( V_33 , L_81 ) ;
F_64 ( V_8 , V_49 -> V_81 , L_77 ) ;
return F_61 ( V_8 , V_49 -> V_82 . V_48 , V_13 ,
V_69 , V_16 ) ;
default:
F_9 ( V_33 , L_82 ) ;
F_73 ( V_33 , V_49 -> type ) ;
F_9 ( V_33 , L_73 ) ;
return 1 ;
break;
}
return 1 ;
}
int F_25 ( T_8 * V_52 , T_3 * * V_17 )
{
T_9 * V_92 ;
T_10 V_93 ;
T_3 * V_94 ;
int V_56 ;
T_8 * V_67 ;
V_92 = F_74 () ;
F_75 ( V_92 ) ;
F_76 ( & V_93 , V_92 , V_52 , NULL ) ;
if ( F_77 ( & V_93 ) <= 0 ) {
V_56 = F_78 ( & V_93 ) ;
goto V_95;
}
V_94 = F_79 ( F_80 ( & V_93 ) ) ;
for ( V_56 = 0 ; V_56 < F_22 ( V_94 ) ; V_56 ++ ) {
V_67 = ( T_8 * ) F_23 ( V_94 , V_56 ) ;
F_81 ( & V_67 -> V_96 , 1 , V_97 ) ;
}
V_56 = 0 ;
* V_17 = V_94 ;
V_95:
F_82 ( & V_93 ) ;
F_83 ( V_92 ) ;
return V_56 ;
}
int F_59 ( T_1 * V_67 , T_11 * V_98 )
{
T_12 * V_99 ;
unsigned char * V_100 ;
V_100 = V_98 -> V_101 -> V_82 . V_102 -> V_103 ;
V_99 = F_84 ( NULL , & V_100 , V_98 -> V_101 -> V_82 . V_102 -> V_104 ) ;
F_9 ( V_33 , L_83 ,
F_85 ( F_57 ( V_98 -> V_77 ) ) , F_48 ( V_99 -> V_19 ) ) ;
F_86 ( V_99 ) ;
return 0 ;
}
int F_20 ( T_1 * V_7 , T_3 * V_105 )
{
int V_26 ;
T_8 * V_52 ;
V_26 = 0 ;
while( ( V_52 = F_87 ( V_7 , NULL , NULL ) ) ) {
V_26 = 1 ;
F_8 ( V_105 , ( char * ) V_52 ) ;
}
if( V_26 ) F_88 () ;
return V_26 ;
}
int F_64 ( T_1 * V_8 , T_3 * V_106 , char * V_11 )
{
T_13 * V_107 ;
T_14 * V_108 ;
char * V_82 ;
int V_56 , V_109 ;
if( ! V_106 ) {
F_9 ( V_8 , L_84 , V_11 ) ;
return 1 ;
}
if( ! F_22 ( V_106 ) ) {
F_9 ( V_8 , L_85 , V_11 ) ;
return 1 ;
}
F_9 ( V_8 , L_86 , V_11 ) ;
for( V_56 = 0 ; V_56 < F_22 ( V_106 ) ; V_56 ++ ) {
V_107 = ( T_13 * ) F_23 ( V_106 , V_56 ) ;
V_109 = F_57 ( V_107 -> V_110 ) ;
F_9 ( V_8 , L_87 ) ;
if( V_109 == V_111 ) {
F_73 ( V_8 , V_107 -> V_110 ) ;
F_9 ( V_8 , L_88 ) ;
} else F_9 ( V_8 , L_89 , F_85 ( V_109 ) ) ;
if( F_89 ( V_107 -> V_82 . V_112 ) ) {
V_108 = F_90 ( V_107 -> V_82 . V_112 , 0 ) ;
switch( V_108 -> type ) {
case V_113 :
V_82 = F_91 ( V_108 -> V_82 . V_114 -> V_103 ,
V_108 -> V_82 . V_114 -> V_104 ) ;
F_9 ( V_8 , L_86 , V_82 ) ;
Free ( V_82 ) ;
break;
case V_115 :
F_92 ( V_8 , V_108 -> V_82 . V_116 -> V_103 ,
V_108 -> V_82 . V_116 -> V_104 ) ;
F_9 ( V_8 , L_73 ) ;
break;
case V_117 :
F_92 ( V_8 , V_108 -> V_82 . V_118 -> V_103 ,
V_108 -> V_82 . V_118 -> V_104 ) ;
F_9 ( V_8 , L_73 ) ;
break;
default:
F_9 ( V_8 , L_90 , V_108 -> type ) ;
break;
}
} else F_9 ( V_8 , L_91 ) ;
}
return 1 ;
}
void F_92 ( T_1 * V_8 , unsigned char * V_68 , int V_119 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_119 ; V_56 ++ ) F_9 ( V_8 , L_92 , V_68 [ V_56 ] ) ;
}
