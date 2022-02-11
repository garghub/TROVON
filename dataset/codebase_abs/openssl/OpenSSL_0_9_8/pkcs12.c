int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
char * V_4 = NULL , * V_5 = NULL , * V_6 = NULL ;
char * V_7 = NULL ;
T_2 * V_8 = NULL , * V_9 = NULL ;
char * * args ;
char * V_10 = NULL ;
char * V_11 = NULL ;
T_3 * V_12 = NULL ;
char V_13 [ 50 ] , V_14 [ 50 ] ;
int V_15 = 0 ;
int V_16 = 0 ;
int V_17 = 0 ;
int V_18 = 0 ;
int V_19 = V_20 ;
int V_21 = V_20 ;
int V_22 = 0 ;
int V_23 = 0 ;
int V_24 = V_25 ;
int V_26 = V_27 ;
int V_28 = 1 ;
int V_29 = 1 ;
int V_30 = 0 ;
T_4 * V_31 = NULL ;
char * V_32 = NULL , * V_33 = NULL ;
char * V_34 = NULL , * V_35 = NULL , * V_36 = NULL ;
char * V_37 = NULL , * V_38 = NULL ;
char * V_39 = NULL ;
char * V_40 = NULL , * V_41 = NULL ;
#ifndef F_1
char * V_42 = NULL ;
#endif
F_2 () ;
V_43 = F_3 () ;
if ( V_44 == NULL ) V_44 = F_4 ( V_45 , V_46 ) ;
if ( ! F_5 ( V_44 , NULL ) )
goto V_47;
args = V_2 + 1 ;
while ( * args ) {
if ( * args [ 0 ] == '-' ) {
if ( ! strcmp ( * args , L_1 ) ) V_16 |= V_48 ;
else if ( ! strcmp ( * args , L_2 ) ) V_23 = V_49 ;
else if ( ! strcmp ( * args , L_3 ) ) V_23 = V_50 ;
else if ( ! strcmp ( * args , L_4 ) ) V_16 |= V_51 ;
else if ( ! strcmp ( * args , L_5 ) ) V_16 |= V_52 ;
else if ( ! strcmp ( * args , L_6 ) ) V_16 |= V_53 ;
else if ( ! strcmp ( * args , L_7 ) ) V_16 |= ( V_48 | V_51 ) ;
else if ( ! strcmp ( * args , L_8 ) ) V_16 |= V_54 ;
else if ( ! strcmp ( * args , L_9 ) ) V_17 = 1 ;
else if ( ! strcmp ( * args , L_10 ) ) V_22 = 1 ;
else if ( ! strcmp ( * args , L_11 ) ) V_29 = 0 ;
else if ( ! strcmp ( * args , L_12 ) )
V_24 = V_27 ;
else if ( ! strcmp ( * args , L_13 ) ) V_15 = 1 ;
else if ( ! strcmp ( * args , L_14 ) ) V_43 = F_6 () ;
#ifndef F_7
else if ( ! strcmp ( * args , L_15 ) ) V_43 = F_8 () ;
#endif
else if ( ! strcmp ( * args , L_16 ) ) V_43 = F_3 () ;
#ifndef F_9
else if ( ! strcmp ( * args , L_17 ) ) V_43 = F_10 () ;
else if ( ! strcmp ( * args , L_18 ) ) V_43 = F_11 () ;
else if ( ! strcmp ( * args , L_19 ) ) V_43 = F_12 () ;
#endif
else if ( ! strcmp ( * args , L_20 ) ) V_19 = 1 ;
else if ( ! strcmp ( * args , L_21 ) )
V_21 = V_20 ;
else if ( ! strcmp ( * args , L_22 ) )
V_21 = 1 ;
else if ( ! strcmp ( * args , L_23 ) )
V_21 = - 1 ;
else if ( ! strcmp ( * args , L_24 ) ) V_43 = NULL ;
else if ( ! strcmp ( * args , L_25 ) ) {
if ( args [ 1 ] ) {
args ++ ;
if ( ! strcmp ( * args , L_26 ) )
V_24 = - 1 ;
V_24 = F_13 ( * args ) ;
if( V_24 == V_55 ) {
F_14 ( V_44 ,
L_27 , * args ) ;
V_18 = 1 ;
}
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_28 ) ) {
if ( args [ 1 ] ) {
args ++ ;
if ( ! strcmp ( * args , L_26 ) )
V_26 = - 1 ;
else
V_26 = F_13 ( * args ) ;
if( V_26 == V_55 ) {
F_14 ( V_44 ,
L_27 , * args ) ;
V_18 = 1 ;
}
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_29 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_39 = * args ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_30 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_6 = * args ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_31 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_7 = * args ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_32 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_10 = * args ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_33 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_11 = * args ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_34 ) ) {
if ( args [ 1 ] ) {
args ++ ;
if ( ! V_31 ) V_31 = F_15 () ;
F_16 ( V_31 , * args ) ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_35 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_4 = * args ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_36 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_5 = * args ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_37 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_34 = * args ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_38 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_35 = * args ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_39 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_36 = * args ;
V_30 = 1 ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_40 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_40 = * args ;
} else V_18 = 1 ;
} else if ( ! strcmp ( * args , L_41 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_41 = * args ;
} else V_18 = 1 ;
#ifndef F_1
} else if ( ! strcmp ( * args , L_42 ) ) {
if ( args [ 1 ] ) {
args ++ ;
V_42 = * args ;
} else V_18 = 1 ;
#endif
} else V_18 = 1 ;
} else V_18 = 1 ;
args ++ ;
}
if ( V_18 ) {
F_14 ( V_44 , L_43 ) ;
F_14 ( V_44 , L_44 ) ;
F_14 ( V_44 , L_45 ) ;
F_14 ( V_44 , L_46 ) ;
F_14 ( V_44 , L_47 ) ;
F_14 ( V_44 , L_48 ) ;
F_14 ( V_44 , L_49 ) ;
F_14 ( V_44 , L_50 ) ;
F_14 ( V_44 , L_51 ) ;
F_14 ( V_44 , L_52 ) ;
F_14 ( V_44 , L_53 ) ;
F_14 ( V_44 , L_54 ) ;
F_14 ( V_44 , L_55 ) ;
F_14 ( V_44 , L_56 ) ;
F_14 ( V_44 , L_57 ) ;
F_14 ( V_44 , L_58 ) ;
F_14 ( V_44 , L_59 ) ;
F_14 ( V_44 , L_60 ) ;
F_14 ( V_44 , L_61 ) ;
F_14 ( V_44 , L_62 ) ;
F_14 ( V_44 , L_63 ) ;
#ifndef F_7
F_14 ( V_44 , L_64 ) ;
#endif
#ifndef F_9
F_14 ( V_44 , L_65 ) ;
F_14 ( V_44 , L_66 ) ;
#endif
F_14 ( V_44 , L_67 ) ;
F_14 ( V_44 , L_68 ) ;
F_14 ( V_44 , L_69 ) ;
F_14 ( V_44 , L_70 ) ;
F_14 ( V_44 , L_71 ) ;
F_14 ( V_44 , L_72 ) ;
F_14 ( V_44 , L_73 ) ;
F_14 ( V_44 , L_74 ) ;
F_14 ( V_44 , L_75 ) ;
F_14 ( V_44 , L_76 ) ;
F_14 ( V_44 , L_77 ) ;
F_14 ( V_44 , L_78 ) ;
#ifndef F_1
F_14 ( V_44 , L_79 ) ;
#endif
F_14 ( V_44 , L_80 , V_56 , V_56 ) ;
F_14 ( V_44 , L_81 ) ;
F_14 ( V_44 , L_82 ) ;
goto V_47;
}
#ifndef F_1
V_3 = F_17 ( V_44 , V_42 , 0 ) ;
#endif
if( V_36 ) {
if( V_15 ) V_35 = V_36 ;
else V_34 = V_36 ;
}
if( ! F_18 ( V_44 , V_34 , V_35 , & V_37 , & V_38 ) ) {
F_14 ( V_44 , L_83 ) ;
goto V_47;
}
if( ! V_32 ) {
if( V_15 ) V_32 = V_38 ;
else V_32 = V_37 ;
}
if( V_32 ) {
V_33 = V_32 ;
V_30 = 1 ;
} else {
V_32 = V_13 ;
V_33 = V_14 ;
}
if( V_15 || V_39 ) {
F_19 ( NULL , V_44 , ( V_39 != NULL ) ) ;
if ( V_39 != NULL )
F_14 ( V_44 , L_84 ,
F_20 ( V_39 ) ) ;
}
F_21 () ;
#ifdef F_22
F_23 ( L_85 ) ;
#endif
if ( ! V_4 ) V_8 = F_4 ( V_57 , V_46 ) ;
else V_8 = F_24 ( V_4 , L_86 ) ;
if ( ! V_8 ) {
F_14 ( V_44 , L_87 ,
V_4 ? V_4 : L_88 ) ;
perror ( V_4 ) ;
goto V_47;
}
#ifdef F_22
F_25 () ;
F_23 ( L_89 ) ;
#endif
if ( ! V_5 ) {
V_9 = F_4 ( stdout , V_46 ) ;
#ifdef F_26
{
T_2 * V_58 = F_27 ( F_28 () ) ;
V_9 = F_29 ( V_58 , V_9 ) ;
}
#endif
} else V_9 = F_24 ( V_5 , L_90 ) ;
if ( ! V_9 ) {
F_14 ( V_44 , L_91 ,
V_5 ? V_5 : L_92 ) ;
perror ( V_5 ) ;
goto V_47;
}
if ( V_22 ) {
#ifdef F_22
F_23 ( L_93 ) ;
#endif
if( F_30 ( V_14 , sizeof V_14 , L_94 , V_15 ) )
{
F_14 ( V_44 , L_95 ) ;
goto V_47;
}
#ifdef F_22
F_25 () ;
#endif
}
if ( V_15 ) {
T_5 * V_59 = NULL ;
T_6 * V_60 = NULL , * V_61 = NULL ;
F_31 ( T_6 ) * V_62 = NULL ;
unsigned char * V_63 = NULL ;
int V_64 ;
if ( ( V_16 & ( V_51 | V_48 ) ) == ( V_51 | V_48 ) )
{
F_14 ( V_44 , L_96 ) ;
goto V_65;
}
if ( V_16 & V_51 )
V_17 = 0 ;
#ifdef F_22
F_23 ( L_97 ) ;
F_23 ( L_98 ) ;
#endif
if ( ! ( V_16 & V_48 ) )
{
V_59 = F_32 ( V_44 , V_6 ? V_6 : V_4 ,
V_66 , 1 , V_37 , V_3 , L_99 ) ;
if ( ! V_59 )
goto V_65;
}
#ifdef F_22
F_25 () ;
F_23 ( L_100 ) ;
#endif
if( ! ( V_16 & V_51 ) )
{
V_62 = F_33 ( V_44 , V_4 , V_66 , NULL , V_3 ,
L_101 ) ;
if ( ! V_62 )
goto V_65;
if ( V_59 )
{
for( V_64 = 0 ; V_64 < F_34 ( V_62 ) ; V_64 ++ )
{
V_61 = F_35 ( V_62 , V_64 ) ;
if( F_36 ( V_61 , V_59 ) )
{
V_60 = V_61 ;
F_37 ( V_60 , NULL , 0 ) ;
F_38 ( V_60 , NULL , 0 ) ;
F_39 ( V_62 , V_64 ) ;
break;
}
}
if ( ! V_60 )
{
F_14 ( V_44 , L_102 ) ;
goto V_65;
}
}
}
#ifdef F_22
F_25 () ;
F_23 ( L_103 ) ;
#endif
if( V_7 )
{
F_31 ( T_6 ) * V_67 = NULL ;
if( ! ( V_67 = F_33 ( V_44 , V_7 , V_66 ,
NULL , V_3 ,
L_104 ) ) )
goto V_65;
while( F_34 ( V_67 ) > 0 )
F_40 ( V_62 , F_41 ( V_67 ) ) ;
F_42 ( V_67 ) ;
}
#ifdef F_22
F_25 () ;
F_23 ( L_105 ) ;
#endif
#ifdef F_22
F_25 () ;
F_23 ( L_106 ) ;
#endif
if ( V_17 ) {
int V_68 ;
F_31 ( T_6 ) * V_69 ;
T_7 * V_70 = F_43 () ;
if ( ! V_70 )
{
F_14 ( V_44 , L_107 ) ;
goto V_65;
}
if ( ! F_44 ( V_70 , V_41 , V_40 ) )
F_45 ( V_70 ) ;
V_68 = F_46 ( V_60 , V_70 , & V_69 ) ;
F_47 ( V_70 ) ;
if ( ! V_68 ) {
for ( V_64 = 1 ; V_64 < F_34 ( V_69 ) ; V_64 ++ )
F_40 ( V_62 , F_35 ( V_69 , V_64 ) ) ;
F_48 ( F_35 ( V_69 , 0 ) ) ;
F_42 ( V_69 ) ;
} else {
F_14 ( V_44 , L_108 ,
F_49 ( V_68 ) ) ;
goto V_65;
}
}
for ( V_64 = 0 ; V_64 < F_50 ( V_31 ) ; V_64 ++ )
{
V_63 = ( unsigned char * ) F_51 ( V_31 , V_64 ) ;
F_38 ( F_35 ( V_62 , V_64 ) , V_63 , - 1 ) ;
}
if ( V_11 && V_59 )
F_52 ( V_59 , V_71 ,
V_72 , ( unsigned char * ) V_11 , - 1 ) ;
#ifdef F_22
F_25 () ;
F_23 ( L_109 ) ;
#endif
if( ! V_30 &&
F_30 ( V_13 , sizeof V_13 , L_110 , 1 ) )
{
F_14 ( V_44 , L_95 ) ;
goto V_65;
}
if ( ! V_22 ) F_53 ( V_14 , V_13 , sizeof V_14 ) ;
#ifdef F_22
F_25 () ;
F_23 ( L_111 ) ;
#endif
V_12 = F_54 ( V_32 , V_10 , V_59 , V_60 , V_62 ,
V_26 , V_24 , V_19 , - 1 , V_23 ) ;
if ( ! V_12 )
{
F_55 ( V_44 ) ;
goto V_65;
}
if ( V_21 != - 1 )
F_56 ( V_12 , V_33 , - 1 , NULL , 0 , V_21 , NULL ) ;
#ifdef F_22
F_25 () ;
F_23 ( L_112 ) ;
#endif
F_57 ( V_9 , V_12 ) ;
V_28 = 0 ;
V_65:
#ifdef F_22
F_25 () ;
F_25 () ;
F_23 ( L_113 ) ;
#endif
if ( V_59 ) F_58 ( V_59 ) ;
if ( V_62 ) F_59 ( V_62 , F_48 ) ;
if ( V_60 ) F_48 ( V_60 ) ;
#ifdef F_22
F_25 () ;
#endif
goto V_47;
}
if ( ! ( V_12 = F_60 ( V_8 , NULL ) ) ) {
F_55 ( V_44 ) ;
goto V_47;
}
#ifdef F_22
F_23 ( L_114 ) ;
#endif
if( ! V_30 && F_30 ( V_13 , sizeof V_13 , L_115 , 0 ) ) {
F_14 ( V_44 , L_95 ) ;
goto V_47;
}
#ifdef F_22
F_25 () ;
#endif
if ( ! V_22 ) F_53 ( V_14 , V_13 , sizeof V_14 ) ;
if ( V_16 & V_54 ) F_14 ( V_44 , L_116 , V_12 -> V_73 -> V_19 ? F_61 ( V_12 -> V_73 -> V_19 ) : 1 ) ;
if( V_29 ) {
#ifdef F_22
F_23 ( L_117 ) ;
#endif
if( ! V_33 [ 0 ] && F_62 ( V_12 , NULL , 0 ) ) {
if( ! V_22 ) V_32 = NULL ;
} else if ( ! F_62 ( V_12 , V_33 , - 1 ) ) {
F_14 ( V_44 , L_118 ) ;
F_55 ( V_44 ) ;
goto V_47;
}
F_14 ( V_44 , L_119 ) ;
#ifdef F_22
F_25 () ;
#endif
}
#ifdef F_22
F_23 ( L_120 ) ;
#endif
if ( ! F_63 ( V_9 , V_12 , V_32 , - 1 , V_16 , V_38 ) ) {
F_14 ( V_44 , L_121 ) ;
F_55 ( V_44 ) ;
goto V_47;
}
#ifdef F_22
F_25 () ;
#endif
V_28 = 0 ;
V_47:
if ( V_12 ) F_64 ( V_12 ) ;
if( V_15 || V_39 ) F_65 ( NULL , V_44 ) ;
#ifdef F_22
F_66 () ;
#endif
F_67 ( V_8 ) ;
F_68 ( V_9 ) ;
if ( V_31 ) F_69 ( V_31 ) ;
if( V_37 ) F_70 ( V_37 ) ;
if( V_38 ) F_70 ( V_38 ) ;
F_71 () ;
F_72 ( V_28 ) ;
}
int F_63 ( T_2 * V_9 , T_3 * V_12 , char * V_13 ,
int V_74 , int V_16 , char * V_75 )
{
F_31 ( V_76 ) * V_77 = NULL ;
F_31 ( V_78 ) * V_79 ;
int V_64 , V_80 ;
int V_28 = 0 ;
V_76 * V_81 ;
if ( ! ( V_77 = F_73 ( V_12 ) ) ) return 0 ;
for ( V_64 = 0 ; V_64 < F_74 ( V_77 ) ; V_64 ++ ) {
V_81 = F_75 ( V_77 , V_64 ) ;
V_80 = F_76 ( V_81 -> type ) ;
if ( V_80 == V_82 ) {
V_79 = F_77 ( V_81 ) ;
if ( V_16 & V_54 ) F_14 ( V_44 , L_122 ) ;
} else if ( V_80 == V_83 ) {
if ( V_16 & V_54 ) {
F_14 ( V_44 , L_123 ) ;
F_78 ( V_44 ,
V_81 -> V_84 . V_85 -> V_86 -> V_87 ) ;
}
V_79 = F_79 ( V_81 , V_13 , V_74 ) ;
} else continue;
if ( ! V_79 ) goto V_88;
if ( ! F_80 ( V_9 , V_79 , V_13 , V_74 ,
V_16 , V_75 ) ) {
F_81 ( V_79 , V_89 ) ;
goto V_88;
}
F_81 ( V_79 , V_89 ) ;
V_79 = NULL ;
}
V_28 = 1 ;
V_88:
if ( V_77 )
F_82 ( V_77 , V_90 ) ;
return V_28 ;
}
int F_83 ( T_2 * V_9 , V_78 * V_91 , char * V_13 ,
int V_74 , int V_16 , char * V_75 )
{
T_5 * V_92 ;
T_8 * V_93 ;
T_6 * V_94 ;
switch ( F_84 ( V_91 ) )
{
case V_95 :
if ( V_16 & V_54 ) F_14 ( V_44 , L_124 ) ;
if ( V_16 & V_48 ) return 1 ;
F_85 ( V_9 , V_91 -> V_96 , L_125 ) ;
V_93 = V_91 -> V_97 . V_98 ;
if ( ! ( V_92 = F_86 ( V_93 ) ) ) return 0 ;
F_85 ( V_9 , V_93 -> V_99 , L_126 ) ;
F_87 ( V_9 , V_92 , V_43 , NULL , 0 , NULL , V_75 ) ;
F_58 ( V_92 ) ;
break;
case V_100 :
if ( V_16 & V_54 ) {
F_14 ( V_44 , L_127 ) ;
F_78 ( V_44 , V_91 -> V_97 . V_101 -> V_102 ) ;
}
if ( V_16 & V_48 ) return 1 ;
F_85 ( V_9 , V_91 -> V_96 , L_125 ) ;
if ( ! ( V_93 = F_88 ( V_91 , V_13 , V_74 ) ) )
return 0 ;
if ( ! ( V_92 = F_86 ( V_93 ) ) ) {
F_89 ( V_93 ) ;
return 0 ;
}
F_85 ( V_9 , V_93 -> V_99 , L_126 ) ;
F_89 ( V_93 ) ;
F_87 ( V_9 , V_92 , V_43 , NULL , 0 , NULL , V_75 ) ;
F_58 ( V_92 ) ;
break;
case V_103 :
if ( V_16 & V_54 ) F_14 ( V_44 , L_128 ) ;
if ( V_16 & V_51 ) return 1 ;
if ( F_90 ( V_91 , V_104 ) ) {
if ( V_16 & V_53 ) return 1 ;
} else if ( V_16 & V_52 ) return 1 ;
F_85 ( V_9 , V_91 -> V_96 , L_125 ) ;
if ( F_91 ( V_91 ) != V_105 )
return 1 ;
if ( ! ( V_94 = F_92 ( V_91 ) ) ) return 0 ;
F_93 ( V_9 , V_94 ) ;
F_94 ( V_9 , V_94 ) ;
F_48 ( V_94 ) ;
break;
case V_106 :
if ( V_16 & V_54 ) F_14 ( V_44 , L_129 ) ;
F_85 ( V_9 , V_91 -> V_96 , L_125 ) ;
return F_80 ( V_9 , V_91 -> V_97 . V_107 , V_13 ,
V_74 , V_16 , V_75 ) ;
default:
F_14 ( V_44 , L_130 ) ;
F_95 ( V_44 , V_91 -> type ) ;
F_14 ( V_44 , L_131 ) ;
return 1 ;
break;
}
return 1 ;
}
int F_78 ( T_2 * V_61 , T_9 * V_108 )
{
T_10 * V_109 ;
const unsigned char * V_110 ;
V_110 = V_108 -> V_111 -> V_97 . V_112 -> V_113 ;
V_109 = F_96 ( NULL , & V_110 , V_108 -> V_111 -> V_97 . V_112 -> V_114 ) ;
F_14 ( V_44 , L_132 ,
F_97 ( F_76 ( V_108 -> V_87 ) ) ,
F_61 ( V_109 -> V_19 ) ) ;
F_98 ( V_109 ) ;
return 0 ;
}
void F_99 ( T_2 * V_9 , unsigned char * V_115 , int V_116 )
{
int V_64 ;
for ( V_64 = 0 ; V_64 < V_116 ; V_64 ++ ) F_14 ( V_9 , L_133 , V_115 [ V_64 ] ) ;
}
