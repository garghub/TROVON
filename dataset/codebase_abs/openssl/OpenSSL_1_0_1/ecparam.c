int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
T_2 V_4 = V_5 ;
int V_6 = 0 ;
int V_7 = V_8 ;
int V_9 = 0 ;
char * V_10 = NULL , * V_11 = NULL ;
int V_12 = 0 , V_13 = 0 , V_14 = 0 ,
V_15 = 0 , V_16 = 0 , V_17 , V_18 = 0 , V_19 = 0 ;
char * V_20 = NULL , * V_21 = NULL , * V_22 ;
T_3 * V_23 = NULL , * V_24 = NULL ;
int V_25 , V_26 , V_27 = 0 , V_28 = 0 , V_29 = 1 ;
char * V_30 = NULL ;
T_4 * V_31 = NULL , * V_32 = NULL , * V_33 = NULL ,
* V_34 = NULL , * V_35 = NULL , * V_36 = NULL ;
unsigned char * V_37 = NULL ;
F_1 () ;
if ( V_38 == NULL )
if ( ( V_38 = F_2 ( F_3 () ) ) != NULL )
F_4 ( V_38 , V_39 , V_40 | V_41 ) ;
if ( ! F_5 ( V_38 , NULL ) )
goto V_42;
V_25 = V_43 ;
V_26 = V_43 ;
V_22 = V_2 [ 0 ] ;
V_1 -- ;
V_2 ++ ;
while ( V_1 >= 1 )
{
if ( strcmp ( * V_2 , L_1 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_44;
V_25 = F_6 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_2 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_44;
V_26 = F_6 ( * ( ++ V_2 ) ) ;
}
else if ( strcmp ( * V_2 , L_3 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_44;
V_20 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_4 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_44;
V_21 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_5 ) == 0 )
V_16 = 1 ;
else if ( strcmp ( * V_2 , L_6 ) == 0 )
V_28 = 1 ;
else if ( strcmp ( * V_2 , L_7 ) == 0 )
V_14 = 1 ;
else if ( strcmp ( * V_2 , L_8 ) == 0 )
{
if ( -- V_1 < 1 )
goto V_44;
V_10 = * ( ++ V_2 ) ;
}
else if ( strcmp ( * V_2 , L_9 ) == 0 )
V_12 = 1 ;
else if ( strcmp ( * V_2 , L_10 ) == 0 )
{
if ( -- V_1 < 1 )
goto V_44;
++ V_2 ;
V_6 = 1 ;
if ( strcmp ( * V_2 , L_11 ) == 0 )
V_4 = V_45 ;
else if ( strcmp ( * V_2 , L_12 ) == 0 )
V_4 = V_5 ;
else if ( strcmp ( * V_2 , L_13 ) == 0 )
V_4 = V_46 ;
else
goto V_44;
}
else if ( strcmp ( * V_2 , L_14 ) == 0 )
{
if ( -- V_1 < 1 )
goto V_44;
++ V_2 ;
V_9 = 1 ;
if ( strcmp ( * V_2 , L_15 ) == 0 )
V_7 = V_8 ;
else if ( strcmp ( * V_2 , L_16 ) == 0 )
V_7 = 0 ;
else
goto V_44;
}
else if ( strcmp ( * V_2 , L_17 ) == 0 )
V_13 = 1 ;
else if ( strcmp ( * V_2 , L_18 ) == 0 )
V_27 = 1 ;
else if ( strcmp ( * V_2 , L_19 ) == 0 )
{
V_19 = 1 ;
V_18 = 1 ;
}
else if ( strcmp ( * V_2 , L_20 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_44;
V_11 = * ( ++ V_2 ) ;
V_18 = 1 ;
}
else if( strcmp ( * V_2 , L_21 ) == 0 )
{
if ( -- V_1 < 1 ) goto V_44;
V_30 = * ( ++ V_2 ) ;
}
else
{
F_7 ( V_38 , L_22 , * V_2 ) ;
V_15 = 1 ;
break;
}
V_1 -- ;
V_2 ++ ;
}
if ( V_15 )
{
V_44:
F_7 ( V_38 , L_23 , V_22 ) ;
F_7 ( V_38 , L_24 ) ;
F_7 ( V_38 , L_25
L_26 ) ;
F_7 ( V_38 , L_27
L_28 ) ;
F_7 ( V_38 , L_29
L_30 ) ;
F_7 ( V_38 , L_31
L_32 ) ;
F_7 ( V_38 , L_33
L_34 ) ;
F_7 ( V_38 , L_35
L_36 ) ;
F_7 ( V_38 , L_37
L_38 ) ;
F_7 ( V_38 , L_39
L_40 ) ;
F_7 ( V_38 , L_41
L_42 ) ;
F_7 ( V_38 , L_43
L_44 ) ;
F_7 ( V_38 , L_45
L_46 ) ;
F_7 ( V_38 , L_47
L_48 ) ;
F_7 ( V_38 , L_49
L_50 ) ;
F_7 ( V_38 , L_49
L_51 ) ;
F_7 ( V_38 , L_52
L_53 ) ;
F_7 ( V_38 , L_54
L_55 ) ;
F_7 ( V_38 , L_47
L_56 ) ;
F_7 ( V_38 , L_49
L_57 ) ;
F_7 ( V_38 , L_58
L_59
L_60 ) ;
F_7 ( V_38 , L_61
L_62 ) ;
F_7 ( V_38 , L_63
L_64 ) ;
F_7 ( V_38 , L_65
L_66 ) ;
goto V_42;
}
F_8 () ;
V_23 = F_2 ( F_3 () ) ;
V_24 = F_2 ( F_3 () ) ;
if ( ( V_23 == NULL ) || ( V_24 == NULL ) )
{
F_9 ( V_38 ) ;
goto V_42;
}
if ( V_20 == NULL )
F_4 ( V_23 , V_47 , V_40 ) ;
else
{
if ( F_10 ( V_23 , V_20 ) <= 0 )
{
perror ( V_20 ) ;
goto V_42;
}
}
if ( V_21 == NULL )
{
F_4 ( V_24 , stdout , V_40 ) ;
#ifdef F_11
{
T_3 * V_48 = F_2 ( F_12 () ) ;
V_24 = F_13 ( V_48 , V_24 ) ;
}
#endif
}
else
{
if ( F_14 ( V_24 , V_21 ) <= 0 )
{
perror ( V_21 ) ;
goto V_42;
}
}
#ifndef F_15
F_16 ( V_38 , V_30 , 0 ) ;
#endif
if ( V_12 )
{
T_5 * V_49 = NULL ;
T_6 V_50 = 0 ;
T_6 V_51 = 0 ;
V_50 = F_17 ( NULL , 0 ) ;
V_49 = F_18 ( ( int ) ( sizeof( T_5 ) * V_50 ) ) ;
if ( V_49 == NULL )
goto V_42;
if ( ! F_17 ( V_49 , V_50 ) )
{
F_19 ( V_49 ) ;
goto V_42;
}
for ( V_51 = 0 ; V_51 < V_50 ; V_51 ++ )
{
const char * V_52 ;
const char * V_53 ;
V_52 = V_49 [ V_51 ] . V_52 ;
V_53 = F_20 ( V_49 [ V_51 ] . V_54 ) ;
if ( V_52 == NULL )
V_52 = L_67 ;
if ( V_53 == NULL )
V_53 = L_68 ;
F_7 ( V_24 , L_69 , V_53 ) ;
F_7 ( V_24 , L_70 , V_52 ) ;
}
F_19 ( V_49 ) ;
V_29 = 0 ;
goto V_42;
}
if ( V_10 != NULL )
{
int V_54 ;
if ( ! strcmp ( V_10 , L_71 ) )
{
F_7 ( V_38 , L_72
L_73 ) ;
V_54 = V_55 ;
}
else if ( ! strcmp ( V_10 , L_74 ) )
{
F_7 ( V_38 , L_75
L_76 ) ;
V_54 = V_56 ;
}
else
V_54 = F_21 ( V_10 ) ;
if ( V_54 == 0 )
{
F_7 ( V_38 , L_77 ,
V_10 ) ;
goto V_42;
}
V_3 = F_22 ( V_54 ) ;
if ( V_3 == NULL )
{
F_7 ( V_38 , L_78 ,
V_10 ) ;
goto V_42;
}
F_23 ( V_3 , V_7 ) ;
F_24 ( V_3 , V_4 ) ;
}
else if ( V_25 == V_57 )
{
V_3 = F_25 ( V_23 , NULL ) ;
}
else if ( V_25 == V_43 )
{
V_3 = F_26 ( V_23 , NULL , NULL , NULL ) ;
}
else
{
F_7 ( V_38 , L_79 ) ;
goto V_42;
}
if ( V_3 == NULL )
{
F_7 ( V_38 ,
L_80 ) ;
F_9 ( V_38 ) ;
goto V_42;
}
if ( V_6 )
F_24 ( V_3 , V_4 ) ;
if ( V_9 )
F_23 ( V_3 , V_7 ) ;
if ( V_13 )
{
F_27 ( V_3 , NULL , 0 ) ;
}
if ( V_16 )
{
if ( ! F_28 ( V_24 , V_3 , 0 ) )
goto V_42;
}
if ( V_14 )
{
if ( V_3 == NULL )
F_7 ( V_38 , L_81 ) ;
F_7 ( V_38 , L_82 ) ;
if ( ! F_29 ( V_3 , NULL ) )
{
F_7 ( V_38 , L_83 ) ;
F_9 ( V_38 ) ;
}
else
F_7 ( V_38 , L_84 ) ;
}
if ( V_28 )
{
T_6 V_58 = 0 , V_59 = 0 ;
const T_7 * V_60 ;
int V_61 , V_62 = 0 ;
const T_8 * V_63 = F_30 ( V_3 ) ;
if ( ( V_31 = F_31 () ) == NULL || ( V_32 = F_31 () ) == NULL ||
( V_33 = F_31 () ) == NULL || ( V_34 = F_31 () ) == NULL ||
( V_35 = F_31 () ) == NULL ||
( V_36 = F_31 () ) == NULL )
{
perror ( L_85 ) ;
goto V_42;
}
V_61 = ( F_32 ( V_63 ) ==
V_64 ) ;
if ( V_61 )
{
if ( ! F_33 ( V_3 , V_31 , V_32 ,
V_33 , NULL ) )
goto V_42;
}
else
{
goto V_42;
}
if ( ( V_60 = F_34 ( V_3 ) ) == NULL )
goto V_42;
if ( ! F_35 ( V_3 , V_60 ,
F_36 ( V_3 ) , V_34 ,
NULL ) )
goto V_42;
if ( ! F_37 ( V_3 , V_35 , NULL ) )
goto V_42;
if ( ! F_38 ( V_3 , V_36 , NULL ) )
goto V_42;
if ( ! V_31 || ! V_32 || ! V_33 || ! V_34 ||
! V_35 || ! V_36 )
goto V_42;
V_62 = F_39 ( V_35 ) ;
if ( ( V_59 = ( T_6 ) F_40 ( V_31 ) ) > V_58 )
V_58 = V_59 ;
if ( ( V_59 = ( T_6 ) F_40 ( V_32 ) ) > V_58 )
V_58 = V_59 ;
if ( ( V_59 = ( T_6 ) F_40 ( V_33 ) ) > V_58 )
V_58 = V_59 ;
if ( ( V_59 = ( T_6 ) F_40 ( V_34 ) ) > V_58 )
V_58 = V_59 ;
if ( ( V_59 = ( T_6 ) F_40 ( V_35 ) ) > V_58 )
V_58 = V_59 ;
if ( ( V_59 = ( T_6 ) F_40 ( V_36 ) ) > V_58 )
V_58 = V_59 ;
V_37 = ( unsigned char * ) F_18 ( V_58 ) ;
if ( V_37 == NULL )
{
perror ( L_85 ) ;
goto V_42;
}
F_41 ( V_24 , V_31 , L_86 , V_62 , V_37 ) ;
F_41 ( V_24 , V_32 , L_87 , V_62 , V_37 ) ;
F_41 ( V_24 , V_33 , L_88 , V_62 , V_37 ) ;
F_41 ( V_24 , V_34 , L_89 , V_62 , V_37 ) ;
F_41 ( V_24 , V_35 , L_90 , V_62 , V_37 ) ;
F_41 ( V_24 , V_36 , L_91 , V_62 ,
V_37 ) ;
F_7 ( V_24 , L_92 ) ;
F_7 ( V_24 , L_93 , V_62 ) ;
F_7 ( V_24 , L_94 ) ;
F_7 ( V_24 , L_95 ) ;
F_7 ( V_24 , L_96 ) ;
F_7 ( V_24 , L_97
L_98 ) ;
F_7 ( V_24 , L_99
L_100
L_101 , V_62 , V_62 ) ;
F_7 ( V_24 , L_102
L_103
L_101 , V_62 , V_62 ) ;
F_7 ( V_24 , L_104
L_105
L_101 , V_62 , V_62 ) ;
if ( V_61 )
{
F_7 ( V_24 , L_106
L_107
L_108 ) ;
}
else
{
goto V_42;
}
F_7 ( V_24 , L_109 ) ;
F_7 ( V_24 , L_110
L_111
L_112 , V_62 , V_62 ) ;
F_7 ( V_24 , L_113
L_114 ) ;
F_7 ( V_24 , L_115 ) ;
F_7 ( V_24 , L_116
L_117
L_112 , V_62 , V_62 ) ;
F_7 ( V_24 , L_118
L_119
L_112 , V_62 , V_62 ) ;
F_7 ( V_24 , L_120
L_121 ) ;
F_7 ( V_24 , L_122 ) ;
F_7 ( V_24 , L_123 ) ;
F_7 ( V_24 , L_124 ) ;
F_7 ( V_24 , L_125 ) ;
F_7 ( V_24 , L_126 ) ;
F_7 ( V_24 , L_127 ) ;
F_7 ( V_24 , L_128 ) ;
F_7 ( V_24 , L_129 ) ;
F_7 ( V_24 , L_130 ) ;
F_7 ( V_24 , L_131 ) ;
F_7 ( V_24 , L_132 ) ;
F_7 ( V_24 , L_133 ) ;
}
if ( ! V_27 )
{
if ( V_26 == V_57 )
V_17 = F_42 ( V_24 , V_3 ) ;
else if ( V_26 == V_43 )
V_17 = F_43 ( V_24 , V_3 ) ;
else
{
F_7 ( V_38 , L_134
L_135 ) ;
goto V_42;
}
if ( ! V_17 )
{
F_7 ( V_38 , L_136
L_137 ) ;
F_9 ( V_38 ) ;
goto V_42;
}
}
if ( V_18 )
{
F_44 ( NULL , V_38 , ( V_11 != NULL ) ) ;
if ( V_11 != NULL )
F_7 ( V_38 , L_138 ,
F_45 ( V_11 ) ) ;
}
if ( V_19 )
{
T_9 * V_65 = F_46 () ;
if ( V_65 == NULL )
goto V_42;
assert ( V_18 ) ;
if ( F_47 ( V_65 , V_3 ) == 0 )
goto V_42;
if ( ! F_48 ( V_65 ) )
{
F_49 ( V_65 ) ;
goto V_42;
}
if ( V_26 == V_57 )
V_17 = F_50 ( V_24 , V_65 ) ;
else if ( V_26 == V_43 )
V_17 = F_51 ( V_24 , V_65 , NULL ,
NULL , 0 , NULL , NULL ) ;
else
{
F_7 ( V_38 , L_139
L_140 ) ;
F_49 ( V_65 ) ;
goto V_42;
}
F_49 ( V_65 ) ;
}
if ( V_18 )
F_52 ( NULL , V_38 ) ;
V_29 = 0 ;
V_42:
if ( V_31 )
F_53 ( V_31 ) ;
if ( V_32 )
F_53 ( V_32 ) ;
if ( V_33 )
F_53 ( V_33 ) ;
if ( V_34 )
F_53 ( V_34 ) ;
if ( V_35 )
F_53 ( V_35 ) ;
if ( V_36 )
F_53 ( V_36 ) ;
if ( V_37 )
F_19 ( V_37 ) ;
if ( V_23 != NULL )
F_54 ( V_23 ) ;
if ( V_24 != NULL )
F_55 ( V_24 ) ;
if ( V_3 != NULL )
F_56 ( V_3 ) ;
F_57 () ;
F_58 ( V_29 ) ;
}
static int F_41 ( T_3 * V_24 , T_4 * V_23 , const char * V_66 ,
int V_62 , unsigned char * V_37 )
{
F_7 ( V_24 , L_141 , V_66 , V_62 ) ;
if ( F_59 ( V_23 ) )
F_7 ( V_24 , L_142 ) ;
else
{
int V_17 , V_67 ;
V_67 = F_60 ( V_23 , V_37 ) ;
for ( V_17 = 0 ; V_17 < V_67 - 1 ; V_17 ++ )
{
if ( ( V_17 % 12 ) == 0 )
F_7 ( V_24 , L_143 ) ;
F_7 ( V_24 , L_144 , V_37 [ V_17 ] ) ;
}
if ( ( V_17 % 12 ) == 0 )
F_7 ( V_24 , L_143 ) ;
F_7 ( V_24 , L_145 , V_37 [ V_17 ] ) ;
}
F_7 ( V_24 , L_146 ) ;
return 1 ;
}
