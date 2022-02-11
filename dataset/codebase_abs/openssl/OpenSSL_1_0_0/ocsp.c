int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
char * * args ;
char * V_4 = NULL , * V_5 = NULL , * V_6 = L_1 ;
char * V_7 = NULL , * V_8 = NULL ;
char * V_9 = NULL , * V_10 = NULL ;
char * V_11 = NULL , * V_12 = NULL ;
char * V_13 = NULL , * V_14 = NULL ;
char * V_15 = NULL ;
int V_16 = 1 , V_17 = 0 , V_18 = - 1 ;
F_1 ( V_19 ) * V_20 = NULL ;
T_2 * V_21 = NULL ;
T_3 * V_22 = NULL ;
T_4 * V_23 = NULL ;
T_5 * V_24 = NULL , * V_25 = NULL ;
T_5 * V_26 = NULL , * V_27 = NULL ;
T_6 * V_28 = NULL , * V_29 = NULL ;
T_7 * V_30 = NULL , * V_31 = NULL ;
T_7 * V_32 = NULL ;
T_7 * V_33 = NULL ;
int V_34 = - 1 ;
int V_35 = 0 , V_36 = 0 ;
long V_37 = V_38 , V_39 = - 1 ;
char * V_40 = NULL , * V_41 = NULL ;
T_8 * V_42 = NULL ;
F_1 ( T_5 ) * V_43 = NULL , * V_44 = NULL , * V_45 = NULL ;
char * V_46 = NULL , * V_47 = NULL , * V_48 = NULL ;
unsigned long V_49 = 0 , V_50 = 0 , V_51 = 0 ;
int V_52 = 1 ;
int V_53 = - 1 ;
int V_54 = 0 ;
int V_55 ;
int V_56 = 0 ;
F_1 ( V_57 ) * V_58 = NULL ;
F_1 ( V_59 ) * V_60 = NULL ;
T_5 * V_61 = NULL ;
char * V_62 = NULL ;
char * V_63 = NULL ;
T_9 * V_64 = NULL ;
int V_65 = 0 , V_66 = - 1 ;
const T_10 * V_67 = NULL ;
if ( V_68 == NULL ) V_68 = F_2 ( V_69 , V_70 ) ;
if ( ! F_3 ( V_68 , NULL ) )
goto V_71;
F_4 () ;
F_5 () ;
args = V_2 + 1 ;
V_58 = F_6 () ;
V_60 = F_7 () ;
while ( ! V_54 && * args && * args [ 0 ] == '-' )
{
if ( ! strcmp ( * args , L_2 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_15 = * args ;
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_3 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_34 = atol ( * args ) ;
if ( V_34 < 0 )
{
F_8 ( V_68 ,
L_4 ,
* args ) ;
V_54 = 1 ;
}
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_5 ) )
{
if ( args [ 1 ] )
{
args ++ ;
if ( ! F_9 ( * args , & V_4 , & V_5 , & V_6 , & V_18 ) )
{
F_8 ( V_68 , L_6 ) ;
V_54 = 1 ;
}
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_7 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_4 = * args ;
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_8 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_5 = * args ;
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_9 ) )
{
if ( args [ 1 ] && args [ 2 ] )
{
if ( ! F_10 ( args [ 1 ] , args [ 2 ] , & V_20 ) )
goto V_71;
args += 2 ;
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_10 ) )
V_56 = 1 ;
else if ( ! strcmp ( * args , L_11 ) )
V_17 = 1 ;
else if ( ! strcmp ( * args , L_12 ) )
V_16 = 2 ;
else if ( ! strcmp ( * args , L_13 ) )
V_16 = 0 ;
else if ( ! strcmp ( * args , L_14 ) )
V_51 |= V_72 ;
else if ( ! strcmp ( * args , L_15 ) )
V_51 |= V_73 ;
else if ( ! strcmp ( * args , L_16 ) )
V_49 |= V_72 ;
else if ( ! strcmp ( * args , L_17 ) )
V_50 |= V_74 ;
else if ( ! strcmp ( * args , L_18 ) )
V_50 |= V_75 ;
else if ( ! strcmp ( * args , L_19 ) )
V_50 |= V_76 ;
else if ( ! strcmp ( * args , L_20 ) )
V_50 |= V_77 ;
else if ( ! strcmp ( * args , L_21 ) )
V_50 |= V_78 ;
else if ( ! strcmp ( * args , L_22 ) )
V_50 |= V_79 ;
else if ( ! strcmp ( * args , L_23 ) )
V_50 |= V_80 ;
else if ( ! strcmp ( * args , L_24 ) )
{
V_35 = 1 ;
V_36 = 1 ;
}
else if ( ! strcmp ( * args , L_25 ) )
V_35 = 1 ;
else if ( ! strcmp ( * args , L_26 ) )
V_36 = 1 ;
else if ( ! strcmp ( * args , L_27 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_7 = * args ;
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_28 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_8 = * args ;
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_29 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_11 = * args ;
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_30 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_47 = * args ;
V_50 |= V_79 ;
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_31 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_46 = * args ;
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_32 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_47 = * args ;
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_33 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_40 = * args ;
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_34 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_41 = * args ;
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_35 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_37 = atol ( * args ) ;
if ( V_37 < 0 )
{
F_8 ( V_68 ,
L_36 ,
* args ) ;
V_54 = 1 ;
}
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_37 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_39 = atol ( * args ) ;
if ( V_39 < 0 )
{
F_8 ( V_68 ,
L_38 ,
* args ) ;
V_54 = 1 ;
}
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_39 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_12 = * args ;
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_40 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_9 = * args ;
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_41 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_10 = * args ;
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_42 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_6 = * args ;
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_43 ) )
{
if ( args [ 1 ] )
{
args ++ ;
F_11 ( V_24 ) ;
V_24 = F_12 ( V_68 , * args , V_81 ,
NULL , V_3 , L_44 ) ;
if( ! V_24 ) goto V_71;
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_45 ) )
{
if ( args [ 1 ] )
{
args ++ ;
F_11 ( V_25 ) ;
V_25 = F_12 ( V_68 , * args , V_81 ,
NULL , V_3 , L_46 ) ;
if( ! V_25 ) goto V_71;
if ( ! V_67 ) V_67 = F_13 () ;
if( ! F_14 ( & V_21 , V_25 , V_67 , V_24 , V_60 ) )
goto V_71;
if( ! F_15 ( V_58 , * args ) )
goto V_71;
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_47 ) )
{
if ( args [ 1 ] )
{
args ++ ;
if ( ! V_67 ) V_67 = F_13 () ;
if( ! F_16 ( & V_21 , * args , V_67 , V_24 , V_60 ) )
goto V_71;
if( ! F_15 ( V_58 , * args ) )
goto V_71;
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_48 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_62 = * args ;
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_49 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_63 = * args ;
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_50 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_65 = atol ( * args ) ;
if ( V_65 < 0 )
{
F_8 ( V_68 ,
L_51 ,
* args ) ;
V_54 = 1 ;
}
}
if ( V_66 == - 1 )
V_66 = 0 ;
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_52 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_53 = atol ( * args ) ;
if ( V_53 < 0 )
{
F_8 ( V_68 ,
L_53 ,
* args ) ;
V_54 = 1 ;
}
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_54 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_66 = atol ( * args ) ;
if ( V_66 < 0 )
{
F_8 ( V_68 ,
L_51 ,
* args ) ;
V_54 = 1 ;
}
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_55 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_13 = * args ;
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_56 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_14 = * args ;
}
else V_54 = 1 ;
}
else if ( ! strcmp ( * args , L_57 ) )
{
if ( args [ 1 ] )
{
args ++ ;
V_48 = * args ;
}
else V_54 = 1 ;
}
else if ( ( V_67 = F_17 ( ( * args ) + 1 ) ) == NULL )
{
V_54 = 1 ;
}
args ++ ;
}
if ( ! V_21 && ! V_7 && ! V_8 && ! ( V_5 && V_62 ) ) V_54 = 1 ;
if ( V_54 )
{
F_8 ( V_68 , L_58 ) ;
F_8 ( V_68 , L_59 ) ;
F_8 ( V_68 , L_60 ) ;
F_8 ( V_68 , L_61 ) ;
F_8 ( V_68 , L_62 ) ;
F_8 ( V_68 , L_63 ) ;
F_8 ( V_68 , L_64 ) ;
F_8 ( V_68 , L_65 ) ;
F_8 ( V_68 , L_66 ) ;
F_8 ( V_68 , L_67 ) ;
F_8 ( V_68 , L_68 ) ;
F_8 ( V_68 , L_69 ) ;
F_8 ( V_68 , L_70 ) ;
F_8 ( V_68 , L_71 ) ;
F_8 ( V_68 , L_72 ) ;
F_8 ( V_68 , L_73 ) ;
F_8 ( V_68 , L_74 ) ;
F_8 ( V_68 , L_75 ) ;
F_8 ( V_68 , L_76 ) ;
F_8 ( V_68 , L_77 ) ;
F_8 ( V_68 , L_78 ) ;
F_8 ( V_68 , L_79 ) ;
F_8 ( V_68 , L_80 ) ;
F_8 ( V_68 , L_81 ) ;
F_8 ( V_68 , L_82 ) ;
F_8 ( V_68 , L_83 ) ;
F_8 ( V_68 , L_84 ) ;
F_8 ( V_68 , L_85 ) ;
F_8 ( V_68 , L_86 ) ;
F_8 ( V_68 , L_87 ) ;
F_8 ( V_68 , L_88 ) ;
F_8 ( V_68 , L_89 ) ;
F_8 ( V_68 , L_90 ) ;
F_8 ( V_68 , L_91 ) ;
F_8 ( V_68 , L_92 ) ;
F_8 ( V_68 , L_93 ) ;
F_8 ( V_68 , L_94 ) ;
F_8 ( V_68 , L_95 ) ;
F_8 ( V_68 , L_96 ) ;
F_8 ( V_68 , L_97 ) ;
F_8 ( V_68 , L_98 ) ;
F_8 ( V_68 , L_99 ) ;
F_8 ( V_68 , L_100 ) ;
F_8 ( V_68 , L_101 ) ;
F_8 ( V_68 , L_102 ) ;
F_8 ( V_68 , L_103 ) ;
F_8 ( V_68 , L_104 ) ;
F_8 ( V_68 , L_105 ) ;
goto V_71;
}
if( V_15 ) V_33 = F_18 ( V_15 , L_106 ) ;
else V_33 = F_2 ( stdout , V_70 ) ;
if( ! V_33 )
{
F_8 ( V_68 , L_107 ) ;
goto V_71;
}
if ( ! V_21 && ( V_16 != 2 ) ) V_16 = 0 ;
if ( ! V_21 && V_7 )
{
V_32 = F_18 ( V_7 , L_108 ) ;
if ( ! V_32 )
{
F_8 ( V_68 , L_109 ) ;
goto V_71;
}
V_21 = F_19 ( V_32 , NULL ) ;
F_20 ( V_32 ) ;
if( ! V_21 )
{
F_8 ( V_68 , L_110 ) ;
goto V_71;
}
}
if ( ! V_21 && V_5 )
{
V_30 = F_21 ( V_5 ) ;
if ( ! V_30 )
goto V_71;
}
if ( V_13 && ! V_64 )
{
if ( ! V_14 ) V_14 = V_13 ;
V_27 = F_12 ( V_68 , V_13 , V_81 ,
NULL , V_3 , L_111 ) ;
if ( ! V_27 )
{
F_8 ( V_68 , L_112 ) ;
goto V_71;
}
V_61 = F_12 ( V_68 , V_63 , V_81 ,
NULL , V_3 , L_113 ) ;
if ( V_48 )
{
V_45 = F_22 ( V_68 , V_48 , V_81 ,
NULL , V_3 , L_114 ) ;
if ( ! V_45 ) goto V_71;
}
V_29 = F_23 ( V_68 , V_14 , V_81 , 0 , NULL , NULL ,
L_115 ) ;
if ( ! V_29 )
goto V_71;
}
if( V_30 )
F_8 ( V_68 , L_116 ) ;
V_82:
if ( V_30 )
{
if ( ! F_24 ( & V_21 , & V_31 , V_30 , V_5 ) )
goto V_71;
if ( ! V_21 )
{
V_22 = F_25 ( V_83 , NULL ) ;
F_26 ( V_31 , V_22 ) ;
goto V_84;
}
}
if ( ! V_21 && ( V_11 || V_9 || V_4 || V_16 || V_62 ) )
{
F_8 ( V_68 , L_117 ) ;
goto V_71;
}
if ( V_21 && V_16 ) F_27 ( V_21 , NULL , - 1 ) ;
if ( V_11 )
{
if ( ! V_12 ) V_12 = V_11 ;
V_26 = F_12 ( V_68 , V_11 , V_81 ,
NULL , V_3 , L_118 ) ;
if ( ! V_26 )
{
F_8 ( V_68 , L_119 ) ;
goto V_71;
}
if ( V_46 )
{
V_43 = F_22 ( V_68 , V_46 , V_81 ,
NULL , V_3 , L_120 ) ;
if ( ! V_43 ) goto V_71;
}
V_28 = F_23 ( V_68 , V_12 , V_81 , 0 , NULL , NULL ,
L_121 ) ;
if ( ! V_28 )
goto V_71;
if ( ! F_28 ( V_21 , V_26 , V_28 , NULL , V_43 , V_49 ) )
{
F_8 ( V_68 , L_122 ) ;
goto V_71;
}
}
if ( V_35 && V_21 ) F_29 ( V_33 , V_21 , 0 ) ;
if ( V_9 )
{
V_32 = F_18 ( V_9 , L_123 ) ;
if( ! V_32 )
{
F_8 ( V_68 , L_124 , V_9 ) ;
goto V_71;
}
F_30 ( V_32 , V_21 ) ;
F_20 ( V_32 ) ;
}
if ( V_62 && ( ! V_29 || ! V_27 || ! V_61 ) )
{
F_8 ( V_68 , L_125 ) ;
goto V_71;
}
if ( V_62 && ! V_64 )
{
V_64 = F_31 ( V_62 , NULL ) ;
if ( ! V_64 ) goto V_71;
if ( ! F_32 ( V_64 ) ) goto V_71;
}
if ( V_64 )
{
V_55 = F_33 ( & V_22 , V_21 , V_64 , V_61 , V_27 , V_29 , V_45 , V_51 , V_65 , V_66 ) ;
if ( V_31 )
F_26 ( V_31 , V_22 ) ;
}
else if ( V_4 )
{
#ifndef F_34
V_22 = F_35 ( V_68 , V_21 , V_4 , V_6 ,
V_5 , V_18 , V_20 , V_34 ) ;
if ( ! V_22 )
goto V_71;
#else
F_8 ( V_68 , L_126 ) ;
goto V_71;
#endif
}
else if ( V_8 )
{
V_32 = F_18 ( V_8 , L_108 ) ;
if ( ! V_32 )
{
F_8 ( V_68 , L_127 ) ;
goto V_71;
}
V_22 = F_36 ( V_32 , NULL ) ;
F_20 ( V_32 ) ;
if( ! V_22 )
{
F_8 ( V_68 , L_128 ) ;
goto V_71;
}
}
else
{
V_52 = 0 ;
goto V_71;
}
V_84:
if ( V_10 )
{
V_32 = F_18 ( V_10 , L_123 ) ;
if( ! V_32 )
{
F_8 ( V_68 , L_124 , V_10 ) ;
goto V_71;
}
F_37 ( V_32 , V_22 ) ;
F_20 ( V_32 ) ;
}
V_55 = F_38 ( V_22 ) ;
if ( V_55 != V_85 )
{
F_8 ( V_33 , L_129 ,
F_39 ( V_55 ) , V_55 ) ;
if ( V_56 )
goto V_82;
V_52 = 0 ;
goto V_71;
}
if ( V_36 ) F_40 ( V_33 , V_22 , 0 ) ;
if ( V_31 )
{
if ( V_53 > 0 )
V_53 -- ;
if ( V_53 )
{
F_41 ( V_31 ) ;
V_31 = NULL ;
F_42 ( V_21 ) ;
V_21 = NULL ;
F_43 ( V_22 ) ;
V_22 = NULL ;
goto V_82;
}
goto V_71;
}
if ( ! V_42 )
V_42 = F_44 ( V_68 , V_40 , V_41 ) ;
if ( ! V_42 )
goto V_71;
if ( V_47 )
{
V_44 = F_22 ( V_68 , V_47 , V_81 ,
NULL , V_3 , L_130 ) ;
if ( ! V_44 ) goto V_71;
}
V_23 = F_45 ( V_22 ) ;
if ( ! V_23 )
{
F_8 ( V_68 , L_131 ) ;
goto V_71;
}
if ( ! V_17 )
{
if ( V_21 && ( ( V_55 = F_46 ( V_21 , V_23 ) ) <= 0 ) )
{
if ( V_55 == - 1 )
F_8 ( V_68 , L_132 ) ;
else
{
F_8 ( V_68 , L_133 ) ;
goto V_71;
}
}
V_55 = F_47 ( V_23 , V_44 , V_42 , V_50 ) ;
if ( V_55 < 0 ) V_55 = F_47 ( V_23 , NULL , V_42 , 0 ) ;
if( V_55 <= 0 )
{
F_8 ( V_68 , L_134 ) ;
F_48 ( V_68 ) ;
}
else
F_8 ( V_68 , L_135 ) ;
}
if ( ! F_49 ( V_33 , V_23 , V_21 , V_58 , V_60 , V_37 , V_39 ) )
goto V_71;
V_52 = 0 ;
V_71:
F_48 ( V_68 ) ;
F_11 ( V_26 ) ;
F_50 ( V_42 ) ;
F_51 ( V_28 ) ;
F_51 ( V_29 ) ;
F_11 ( V_24 ) ;
F_11 ( V_25 ) ;
F_11 ( V_27 ) ;
F_11 ( V_61 ) ;
F_52 ( V_64 ) ;
F_41 ( V_31 ) ;
F_41 ( V_30 ) ;
F_20 ( V_33 ) ;
F_42 ( V_21 ) ;
F_43 ( V_22 ) ;
F_53 ( V_23 ) ;
F_54 ( V_58 ) ;
F_55 ( V_60 ) ;
F_56 ( V_43 , F_11 ) ;
F_56 ( V_44 , F_11 ) ;
F_57 ( V_20 , V_86 ) ;
if ( V_18 != - 1 )
{
F_58 ( V_4 ) ;
F_58 ( V_5 ) ;
F_58 ( V_6 ) ;
}
F_59 ( V_52 ) ;
}
static char * * F_60 ( T_9 * V_87 , T_11 * V_88 )
{
int V_55 ;
T_12 * V_89 = NULL ;
char * V_90 , * V_91 [ V_92 ] , * * V_93 ;
for ( V_55 = 0 ; V_55 < V_92 ; V_55 ++ ) V_91 [ V_55 ] = NULL ;
V_89 = F_61 ( V_88 , NULL ) ;
F_62 ( V_89 ) ;
if ( F_63 ( V_89 ) )
V_90 = F_64 ( L_136 ) ;
else
V_90 = F_65 ( V_89 ) ;
V_91 [ V_94 ] = V_90 ;
F_66 ( V_89 ) ;
V_93 = F_67 ( V_87 -> V_87 , V_94 , V_91 ) ;
F_58 ( V_90 ) ;
return V_93 ;
}
static T_7 * F_21 ( char * V_5 )
{
T_7 * V_30 = NULL , * V_95 = NULL ;
V_95 = F_68 ( F_69 () ) ;
if ( ! V_95 )
goto V_96;
#ifndef F_34
V_30 = F_70 ( V_5 ) ;
#else
F_8 ( V_68 , L_137 ) ;
#endif
if ( ! V_30 )
goto V_96;
F_71 ( V_30 , V_95 ) ;
V_95 = NULL ;
if ( F_72 ( V_30 ) <= 0 )
{
F_8 ( V_68 , L_138 ) ;
F_48 ( V_68 ) ;
goto V_96;
}
return V_30 ;
V_96:
F_41 ( V_30 ) ;
F_20 ( V_95 ) ;
return NULL ;
}
static int F_24 ( T_2 * * V_97 , T_7 * * V_98 , T_7 * V_30 , char * V_5 )
{
int V_99 = 0 , V_100 ;
T_2 * V_21 = NULL ;
char V_101 [ 1024 ] ;
T_7 * V_31 = NULL ;
if ( F_72 ( V_30 ) <= 0 )
{
F_8 ( V_68 , L_139 ) ;
F_48 ( V_68 ) ;
return 0 ;
}
V_31 = F_73 ( V_30 ) ;
* V_98 = V_31 ;
for(; ; )
{
V_100 = F_74 ( V_31 , V_101 , sizeof V_101 ) ;
if ( V_100 <= 0 )
return 1 ;
if ( ! V_99 )
{
if( strncmp ( V_101 , L_140 , 4 ) )
{
F_8 ( V_68 , L_141 ) ;
return 1 ;
}
V_99 = 1 ;
}
if ( ( V_101 [ 0 ] == '\r' ) || ( V_101 [ 0 ] == '\n' ) )
break;
}
V_21 = F_19 ( V_31 , NULL ) ;
if ( ! V_21 )
{
F_8 ( V_68 , L_142 ) ;
F_48 ( V_68 ) ;
}
* V_97 = V_21 ;
return 1 ;
}
static int F_26 ( T_7 * V_31 , T_3 * V_22 )
{
char V_102 [] =
L_143
L_144 ;
if ( ! V_31 )
return 0 ;
F_8 ( V_31 , V_102 , F_75 ( V_22 , NULL ) ) ;
F_37 ( V_31 , V_22 ) ;
( void ) F_76 ( V_31 ) ;
return 1 ;
}
