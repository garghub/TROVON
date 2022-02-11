int MAIN ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 = 0 ;
int V_5 = 0 ;
char * * args ;
const char * V_6 = L_1 , * V_7 = L_2 ;
char * V_8 = NULL , * V_9 = NULL , * V_10 = NULL ;
char * V_11 = NULL , * V_12 = NULL ;
F_1 ( V_13 ) * V_14 = NULL , * V_15 = NULL ;
char * V_16 = NULL , * V_17 = NULL , * V_18 = NULL ;
char * V_19 = NULL ;
const T_2 * V_20 = NULL ;
T_3 * V_21 = NULL , * V_22 = NULL ;
T_4 * V_23 = NULL ;
T_5 * V_24 = NULL , * V_25 = NULL , * V_26 = NULL ;
T_6 * V_27 = NULL ;
F_1 ( T_5 ) * V_28 = NULL , * V_29 = NULL ;
T_7 * V_30 = NULL , * V_31 = NULL , * V_32 = NULL , * V_33 = NULL ;
int V_34 = 0 ;
int V_35 = V_36 , V_37 = 0 , V_38 = 0 ;
int V_39 = 0 ;
int V_40 = 0 , V_41 = - 1 ;
F_1 ( V_13 ) * V_42 = NULL , * V_43 = NULL ;
T_8 * V_44 = NULL ;
char * V_45 = NULL , * V_46 = NULL , * V_47 = NULL ;
char * V_48 = NULL , * V_49 = NULL ;
char * V_50 = NULL , * V_51 = NULL ;
char * V_52 = NULL ;
int V_53 = 0 ;
const T_9 * V_54 = NULL ;
int V_55 = V_56 , V_57 = V_56 ;
int V_58 = V_56 , V_59 = V_60 ;
#ifndef F_2
char * V_61 = NULL ;
#endif
unsigned char * V_62 = NULL , * V_63 = NULL ;
unsigned char * V_64 = NULL , * V_65 = NULL ;
T_10 V_66 = 0 , V_67 = 0 ;
T_11 * V_68 = NULL ;
T_12 * V_69 = NULL ;
args = V_2 + 1 ;
V_5 = 1 ;
F_3 () ;
if ( V_70 == NULL )
{
if ( ( V_70 = F_4 ( F_5 () ) ) != NULL )
F_6 ( V_70 , V_71 , V_72 | V_73 ) ;
}
if ( ! F_7 ( V_70 , NULL ) )
goto V_74;
while ( ! V_34 && * args && * args [ 0 ] == '-' )
{
if ( ! strcmp ( * args , L_3 ) )
V_4 = V_75 ;
else if ( ! strcmp ( * args , L_4 ) )
V_4 = V_76 ;
else if ( ! strcmp ( * args , L_5 ) )
V_4 = V_77 ;
else if ( ! strcmp ( * args , L_6 ) )
V_4 = V_78 ;
else if ( ! strcmp ( * args , L_7 ) )
V_4 = V_79 ;
else if ( ! strcmp ( * args , L_8 ) )
V_4 = V_80 ;
else if ( ! strcmp ( * args , L_9 ) )
V_39 = 1 ;
else if ( ! strcmp ( * args , L_10 ) )
{
V_4 = V_81 ;
if ( ! args [ 1 ] )
goto V_82;
args ++ ;
V_10 = * args ;
}
else if ( ! strcmp ( * args , L_11 ) )
V_4 = V_83 ;
else if ( ! strcmp ( * args , L_12 ) )
V_4 = V_84 ;
else if ( ! strcmp ( * args , L_13 ) )
V_4 = V_85 ;
else if ( ! strcmp ( * args , L_14 ) )
V_4 = V_86 ;
else if ( ! strcmp ( * args , L_15 ) )
V_4 = V_87 ;
else if ( ! strcmp ( * args , L_16 ) )
V_4 = V_88 ;
else if ( ! strcmp ( * args , L_17 ) )
V_4 = V_89 ;
else if ( ! strcmp ( * args , L_18 ) )
V_4 = V_90 ;
else if ( ! strcmp ( * args , L_19 ) )
V_4 = V_91 ;
#ifndef F_8
else if ( ! strcmp ( * args , L_20 ) )
V_20 = F_9 () ;
else if ( ! strcmp ( * args , L_21 ) )
V_20 = F_10 () ;
#endif
#ifndef F_11
else if ( ! strcmp ( * args , L_22 ) )
V_20 = F_12 () ;
#endif
#ifndef F_13
else if ( ! strcmp ( * args , L_23 ) )
V_20 = F_14 () ;
else if ( ! strcmp ( * args , L_24 ) )
V_20 = F_15 () ;
else if ( ! strcmp ( * args , L_25 ) )
V_20 = F_16 () ;
#endif
#ifndef F_17
else if ( ! strcmp ( * args , L_26 ) )
V_20 = F_18 () ;
else if ( ! strcmp ( * args , L_27 ) )
V_20 = F_19 () ;
else if ( ! strcmp ( * args , L_28 ) )
V_20 = F_20 () ;
#endif
#ifndef F_21
else if ( ! strcmp ( * args , L_29 ) )
V_20 = F_22 () ;
else if ( ! strcmp ( * args , L_30 ) )
V_20 = F_23 () ;
else if ( ! strcmp ( * args , L_31 ) )
V_20 = F_24 () ;
#endif
else if ( ! strcmp ( * args , L_32 ) )
V_35 |= V_92 ;
else if ( ! strcmp ( * args , L_33 ) )
V_35 |= V_93 ;
else if ( ! strcmp ( * args , L_34 )
|| ! strcmp ( * args , L_35 ) )
V_35 |= V_94 ;
else if ( ! strcmp ( * args , L_36 ) )
V_35 |= V_95 ;
else if ( ! strcmp ( * args , L_37 ) )
V_35 |= V_96 ;
else if ( ! strcmp ( * args , L_38 ) )
V_35 &= ~ V_36 ;
else if ( ! strcmp ( * args , L_39 ) )
V_35 |= V_97 ;
else if ( ! strcmp ( * args , L_40 ) )
V_35 |= V_98 ;
else if ( ! strcmp ( * args , L_41 ) )
V_35 |= V_99 ;
else if ( ! strcmp ( * args , L_42 ) )
V_35 |= V_100 ;
else if ( ! strcmp ( * args , L_43 ) )
V_35 |= V_101 ;
else if ( ! strcmp ( * args , L_44 ) )
V_35 |= V_102 ;
else if ( ! strcmp ( * args , L_45 ) )
V_35 |= V_103 ;
else if ( ! strcmp ( * args , L_46 ) )
V_35 |= V_103 ;
else if ( ! strcmp ( * args , L_47 ) )
V_35 &= ~ V_103 ;
else if ( ! strcmp ( * args , L_48 ) )
V_35 |= V_104 ;
else if ( ! strcmp ( * args , L_49 ) )
V_35 |= V_105 ;
else if ( ! strcmp ( * args , L_50 ) )
V_37 = 1 ;
else if ( ! strcmp ( * args , L_51 ) )
V_40 = 1 ;
else if ( ! strcmp ( * args , L_52 ) )
V_41 = 0 ;
else if ( ! strcmp ( * args , L_53 ) )
V_41 = 1 ;
else if ( ! strcmp ( * args , L_54 ) )
{
if ( ! args [ 1 ] )
goto V_82;
args ++ ;
if ( ! V_43 )
V_43 = F_25 () ;
F_26 ( V_43 , * args ) ;
}
else if ( ! strcmp ( * args , L_55 ) )
{
if ( ! args [ 1 ] )
goto V_82;
args ++ ;
if ( ! V_42 )
V_42 = F_25 () ;
F_26 ( V_42 , * args ) ;
}
else if ( ! strcmp ( * args , L_56 ) )
{
V_37 = 1 ;
V_38 = 1 ;
}
else if ( ! strcmp ( * args , L_57 ) )
{
long V_106 ;
if ( ! args [ 1 ] )
goto V_82;
args ++ ;
V_62 = F_27 ( * args , & V_106 ) ;
if ( ! V_62 )
{
F_28 ( V_70 , L_58 , * args ) ;
goto V_82;
}
V_66 = ( T_10 ) V_106 ;
}
else if ( ! strcmp ( * args , L_59 ) )
{
long V_106 ;
if ( ! args [ 1 ] )
goto V_82;
args ++ ;
V_63 = F_27 ( * args , & V_106 ) ;
if ( ! V_63 )
{
F_28 ( V_70 , L_60 , * args ) ;
goto V_82;
}
V_67 = ( T_10 ) V_106 ;
}
else if ( ! strcmp ( * args , L_61 ) )
{
if ( ! args [ 1 ] )
goto V_82;
args ++ ;
V_64 = ( unsigned char * ) * args ;
}
else if ( ! strcmp ( * args , L_62 ) )
{
if ( ! args [ 1 ] )
goto V_82;
args ++ ;
V_68 = F_29 ( * args , 0 ) ;
if ( ! V_68 )
{
F_28 ( V_70 , L_63 , * args ) ;
goto V_82;
}
}
else if ( ! strcmp ( * args , L_64 ) )
{
if ( ! args [ 1 ] )
goto V_82;
args ++ ;
V_52 = * args ;
V_53 = 1 ;
}
#ifndef F_2
else if ( ! strcmp ( * args , L_65 ) )
{
if ( ! args [ 1 ] )
goto V_82;
V_61 = * ++ args ;
}
#endif
else if ( ! strcmp ( * args , L_66 ) )
{
if ( ! args [ 1 ] )
goto V_82;
V_50 = * ++ args ;
}
else if ( ! strcmp ( * args , L_67 ) )
{
if ( ! args [ 1 ] )
goto V_82;
V_45 = * ++ args ;
}
else if ( ! strcmp ( * args , L_68 ) )
{
if ( ! args [ 1 ] )
goto V_82;
V_46 = * ++ args ;
}
else if ( ! strcmp ( * args , L_69 ) )
{
if ( ! args [ 1 ] )
goto V_82;
V_47 = * ++ args ;
}
else if ( ! strcmp ( * args , L_70 ) )
{
if ( ! args [ 1 ] )
goto V_82;
if ( V_11 )
{
if ( ! V_14 )
V_14 = F_25 () ;
F_26 ( V_14 , V_11 ) ;
if ( ! V_17 )
V_17 = V_11 ;
if ( ! V_15 )
V_15 = F_25 () ;
F_26 ( V_15 , V_17 ) ;
V_17 = NULL ;
}
V_11 = * ++ args ;
}
else if ( ! strcmp ( * args , L_71 ) )
{
if ( ! args [ 1 ] )
goto V_82;
V_12 = * ++ args ;
}
else if ( ! strcmp ( * args , L_72 ) )
{
if ( ! args [ 1 ] )
goto V_82;
V_19 = * ++ args ;
}
else if ( ! strcmp ( * args , L_73 ) )
{
if ( ! args [ 1 ] )
goto V_82;
V_54 = F_30 ( * ++ args ) ;
if ( V_54 == NULL )
{
F_28 ( V_70 , L_74 ,
* args ) ;
goto V_82;
}
}
else if ( ! strcmp ( * args , L_75 ) )
{
if ( ! args [ 1 ] )
goto V_82;
if ( V_17 )
{
if ( ! V_11 )
{
F_31 ( V_70 , L_76 ) ;
goto V_82;
}
if ( ! V_14 )
V_14 = F_25 () ;
F_26 ( V_14 , V_11 ) ;
V_11 = NULL ;
if ( ! V_15 )
V_15 = F_25 () ;
F_26 ( V_15 , V_17 ) ;
}
V_17 = * ++ args ;
}
else if ( ! strcmp ( * args , L_77 ) )
{
if ( ! args [ 1 ] )
goto V_82;
V_59 = F_32 ( * ++ args ) ;
}
else if ( ! strcmp ( * args , L_78 ) )
{
if ( ! args [ 1 ] )
goto V_82;
V_58 = F_32 ( * ++ args ) ;
}
else if ( ! strcmp ( * args , L_79 ) )
{
if ( ! args [ 1 ] )
goto V_82;
V_16 = * ++ args ;
}
else if ( ! strcmp ( * args , L_80 ) )
{
if ( ! args [ 1 ] )
goto V_82;
V_48 = * ++ args ;
}
else if ( ! strcmp ( * args , L_81 ) )
{
if ( ! args [ 1 ] )
goto V_82;
V_49 = * ++ args ;
}
else if ( ! strcmp ( * args , L_82 ) )
{
if ( ! args [ 1 ] )
goto V_82;
V_8 = * ++ args ;
}
else if ( ! strcmp ( * args , L_83 ) )
{
if ( ! args [ 1 ] )
goto V_82;
V_55 = F_32 ( * ++ args ) ;
}
else if ( ! strcmp ( * args , L_84 ) )
{
if ( ! args [ 1 ] )
goto V_82;
V_57 = F_32 ( * ++ args ) ;
}
else if ( ! strcmp ( * args , L_85 ) )
{
if ( ! args [ 1 ] )
goto V_82;
V_9 = * ++ args ;
}
else if ( ! strcmp ( * args , L_86 ) )
{
if ( ! args [ 1 ] )
goto V_82;
V_18 = * ++ args ;
}
else if ( F_33 ( & args , NULL , & V_34 , V_70 , & V_69 ) )
continue;
else if ( ( V_20 = F_34 ( * args + 1 ) ) == NULL )
V_34 = 1 ;
args ++ ;
}
if ( ( ( V_41 != - 1 ) || V_43 ) && ! V_42 )
{
F_31 ( V_70 , L_87 ) ;
goto V_82;
}
if ( ! ( V_4 & V_107 ) && ( V_42 || V_43 ) )
{
F_31 ( V_70 , L_88 ) ;
goto V_82;
}
if ( ! ( V_4 & V_107 ) && ( V_15 || V_14 ) )
{
F_31 ( V_70 , L_89 ) ;
goto V_82;
}
if ( V_4 & V_107 )
{
if ( V_17 && ! V_11 )
{
F_31 ( V_70 , L_76 ) ;
goto V_82;
}
if ( V_11 )
{
if ( ! V_14 )
V_14 = F_25 () ;
F_26 ( V_14 , V_11 ) ;
if ( ! V_15 )
V_15 = F_25 () ;
if ( ! V_17 )
V_17 = V_11 ;
F_26 ( V_15 , V_17 ) ;
}
if ( ! V_14 )
{
F_28 ( V_70 , L_90 ) ;
V_34 = 1 ;
}
V_11 = NULL ;
V_17 = NULL ;
V_53 = 1 ;
}
else if ( V_4 == V_76 )
{
if ( ! V_12 && ! V_17 && ! V_62 && ! V_64 )
{
F_28 ( V_70 , L_91 ) ;
V_34 = 1 ;
}
}
else if ( V_4 == V_75 )
{
if ( ! * args && ! V_62 && ! V_64 )
{
F_28 ( V_70 , L_92 ) ;
V_34 = 1 ;
}
V_53 = 1 ;
}
else if ( ! V_4 )
V_34 = 1 ;
if ( V_34 )
{
V_82:
F_28 ( V_70 , L_93 ) ;
F_28 ( V_70 , L_94 ) ;
F_28 ( V_70 , L_95 ) ;
F_28 ( V_70 , L_96 ) ;
F_28 ( V_70 , L_97 ) ;
F_28 ( V_70 , L_98 ) ;
F_28 ( V_70 , L_99 ) ;
#ifndef F_8
F_28 ( V_70 , L_100 ) ;
F_28 ( V_70 , L_101 ) ;
#endif
#ifndef F_11
F_28 ( V_70 , L_102 ) ;
#endif
#ifndef F_13
F_28 ( V_70 , L_103 ) ;
F_28 ( V_70 , L_104 ) ;
F_28 ( V_70 , L_105 ) ;
#endif
#ifndef F_17
F_28 ( V_70 , L_106 ) ;
F_28 ( V_70 , L_107 ) ;
#endif
#ifndef F_21
F_28 ( V_70 , L_108 ) ;
F_28 ( V_70 , L_109 ) ;
#endif
F_28 ( V_70 , L_110 ) ;
F_28 ( V_70 , L_111 ) ;
F_28 ( V_70 , L_112 ) ;
F_28 ( V_70 , L_113 ) ;
F_28 ( V_70 , L_114 ) ;
F_28 ( V_70 , L_115 ) ;
F_28 ( V_70 , L_116 ) ;
F_28 ( V_70 , L_117 ) ;
F_28 ( V_70 , L_118 ) ;
F_28 ( V_70 , L_119 ) ;
F_28 ( V_70 , L_120 ) ;
F_28 ( V_70 , L_121 ) ;
F_28 ( V_70 , L_122 ) ;
F_28 ( V_70 , L_123 ) ;
F_28 ( V_70 , L_124 ) ;
F_28 ( V_70 , L_125 ) ;
F_28 ( V_70 , L_126 ) ;
F_28 ( V_70 , L_127 ) ;
F_28 ( V_70 , L_128 ) ;
F_28 ( V_70 , L_129 ) ;
F_28 ( V_70 , L_130 ) ;
F_28 ( V_70 , L_131 ) ;
F_28 ( V_70 , L_132 ) ;
F_28 ( V_70 , L_133 ) ;
F_28 ( V_70 , L_134 ) ;
F_28 ( V_70 , L_135 ) ;
F_28 ( V_70 , L_136 ) ;
#ifndef F_2
F_28 ( V_70 , L_137 ) ;
#endif
F_28 ( V_70 , L_138 ) ;
F_28 ( V_70 , L_139 , V_108 , V_108 ) ;
F_28 ( V_70 , L_140 ) ;
F_28 ( V_70 , L_141 ) ;
F_28 ( V_70 , L_142 ) ;
goto V_74;
}
#ifndef F_2
V_3 = F_35 ( V_70 , V_61 , 0 ) ;
#endif
if ( ! F_36 ( V_70 , V_50 , NULL , & V_51 , NULL ) )
{
F_28 ( V_70 , L_143 ) ;
goto V_74;
}
if ( V_53 )
{
F_37 ( NULL , V_70 , ( V_52 != NULL ) ) ;
if ( V_52 != NULL )
F_28 ( V_70 , L_144 ,
F_38 ( V_52 ) ) ;
}
V_5 = 2 ;
if ( ! ( V_4 & V_107 ) )
V_35 &= ~ V_36 ;
if ( V_4 & V_109 )
{
if ( V_57 == V_110 )
V_7 = L_145 ;
}
else
{
if ( V_35 & V_98 )
V_7 = L_145 ;
}
if ( V_4 & V_111 )
{
if ( V_55 == V_110 )
V_6 = L_146 ;
}
else
{
if ( V_35 & V_98 )
V_6 = L_146 ;
}
if ( V_4 == V_75 )
{
if ( ! V_20 )
{
#ifndef F_8
V_20 = F_9 () ;
#else
F_28 ( V_70 , L_147 ) ;
goto V_74;
#endif
}
if ( V_62 && ! V_63 )
{
F_28 ( V_70 , L_148 ) ;
goto V_74;
}
if ( * args )
V_28 = F_39 () ;
while ( * args )
{
if ( ! ( V_24 = F_40 ( V_70 , * args , V_60 ,
NULL , V_3 , L_149 ) ) )
goto V_74;
F_41 ( V_28 , V_24 ) ;
V_24 = NULL ;
args ++ ;
}
}
if ( V_16 )
{
if ( ! ( V_29 = F_42 ( V_70 , V_16 , V_60 , NULL ,
V_3 , L_150 ) ) )
{
F_43 ( V_70 ) ;
goto V_74;
}
}
if ( V_12 && ( V_4 == V_76 ) )
{
if ( ! ( V_25 = F_40 ( V_70 , V_12 , V_60 , NULL ,
V_3 , L_149 ) ) )
{
F_43 ( V_70 ) ;
goto V_74;
}
}
if ( V_4 == V_78 )
{
if ( ! ( V_26 = F_40 ( V_70 , V_11 , V_60 , NULL ,
V_3 , L_151 ) ) )
{
F_43 ( V_70 ) ;
goto V_74;
}
}
if ( V_4 == V_76 )
{
if ( ! V_17 )
V_17 = V_12 ;
}
else if ( ( V_4 == V_77 ) || ( V_4 == V_78 ) )
{
if ( ! V_17 )
V_17 = V_11 ;
}
else V_17 = NULL ;
if ( V_17 )
{
V_27 = F_44 ( V_70 , V_17 , V_59 , 0 , V_51 , V_3 ,
L_152 ) ;
if ( ! V_27 )
goto V_74;
}
if ( V_8 )
{
if ( ! ( V_30 = F_45 ( V_8 , V_6 ) ) )
{
F_28 ( V_70 ,
L_153 , V_8 ) ;
goto V_74;
}
}
else
V_30 = F_46 ( V_112 , V_72 ) ;
if ( V_4 & V_111 )
{
if ( V_55 == V_56 )
V_21 = F_47 ( V_30 , & V_32 ) ;
else if ( V_55 == V_60 )
V_21 = F_48 ( V_30 , NULL , NULL , NULL ) ;
else if ( V_55 == V_110 )
V_21 = F_49 ( V_30 , NULL ) ;
else
{
F_28 ( V_70 , L_154 ) ;
goto V_74;
}
if ( ! V_21 )
{
F_28 ( V_70 , L_155 ) ;
goto V_74;
}
if ( V_18 )
{
F_50 ( V_32 ) ;
if ( ! ( V_32 = F_45 ( V_18 , L_146 ) ) )
{
F_28 ( V_70 , L_156 , V_18 ) ;
goto V_74;
}
}
if ( V_19 )
{
F_1 ( T_5 ) * V_113 ;
V_113 = F_51 ( V_21 ) ;
if ( ! F_52 ( V_19 , V_113 ) )
{
F_28 ( V_70 ,
L_157 ,
V_19 ) ;
V_5 = 5 ;
goto V_74;
}
F_53 ( V_113 , V_114 ) ;
}
}
if ( V_10 )
{
char * V_115 = ( V_58 == V_110 ) ? L_146 : L_1 ;
if ( ! ( V_33 = F_45 ( V_10 , V_115 ) ) )
{
F_28 ( V_70 ,
L_158 , V_10 ) ;
goto V_74;
}
if ( V_58 == V_56 )
V_22 = F_47 ( V_33 , NULL ) ;
else if ( V_58 == V_60 )
V_22 = F_48 ( V_33 , NULL , NULL , NULL ) ;
else if ( V_58 == V_110 )
V_22 = F_49 ( V_33 , NULL ) ;
else
{
F_28 ( V_70 , L_159 ) ;
goto V_74;
}
if ( ! V_22 )
{
F_28 ( V_70 , L_160 ) ;
goto V_74;
}
}
if ( V_9 )
{
if ( ! ( V_31 = F_45 ( V_9 , V_7 ) ) )
{
F_28 ( V_70 ,
L_161 , V_9 ) ;
goto V_74;
}
}
else
{
V_31 = F_46 ( stdout , V_72 ) ;
#ifdef F_54
{
T_7 * V_116 = F_4 ( F_55 () ) ;
V_31 = F_56 ( V_116 , V_31 ) ;
}
#endif
}
if ( ( V_4 == V_80 ) || ( V_4 == V_81 ) )
{
if ( ! ( V_23 = F_57 ( V_70 , V_48 , V_49 ) ) )
goto V_74;
F_58 ( V_23 , V_117 ) ;
if ( V_69 )
F_59 ( V_23 , V_69 ) ;
}
V_5 = 3 ;
if ( V_4 == V_85 )
{
V_21 = F_60 ( V_30 , V_35 ) ;
}
else if ( V_4 == V_87 )
{
V_21 = F_61 ( V_30 , V_54 , V_35 ) ;
}
else if ( V_4 == V_88 )
{
V_21 = F_62 ( V_30 , - 1 , V_35 ) ;
}
else if ( V_4 == V_75 )
{
V_35 |= V_118 ;
V_21 = F_63 ( V_28 , V_30 , V_20 , V_35 ) ;
if ( ! V_21 )
goto V_74;
if ( V_62 )
{
if ( ! F_64 ( V_21 , V_119 ,
V_62 , V_66 ,
V_63 , V_67 ,
NULL , NULL , NULL ) )
goto V_74;
V_62 = NULL ;
V_63 = NULL ;
}
if ( V_64 )
{
V_65 = ( unsigned char * ) F_65 ( ( char * ) V_64 ) ;
if ( ! V_65 )
goto V_74;
if ( ! F_66 ( V_21 ,
- 1 , V_119 , V_119 ,
V_65 , - 1 , NULL ) )
goto V_74;
V_65 = NULL ;
}
if ( ! ( V_35 & V_103 ) )
{
if ( ! F_67 ( V_21 , V_30 , NULL , V_35 ) )
goto V_74;
}
}
else if ( V_4 == V_91 )
{
V_21 = F_68 ( V_30 , V_20 ,
V_62 , V_66 ,
V_35 ) ;
}
else if ( V_4 == V_78 )
{
T_3 * V_120 = NULL ;
F_1 ( V_121 ) * V_122 ;
V_121 * V_123 ;
V_122 = F_69 ( V_21 ) ;
if ( ! V_122 )
goto V_74;
V_123 = F_70 ( V_122 , 0 ) ;
V_120 = F_71 ( V_123 , V_26 , V_27 , V_29 , V_35 ) ;
if ( ! V_120 )
goto V_74;
F_72 ( V_21 ) ;
V_21 = V_120 ;
}
else if ( V_4 & V_107 )
{
int V_124 ;
if ( V_4 == V_77 )
{
if ( V_35 & V_36 )
{
if ( V_57 == V_56 )
V_35 |= V_103 ;
}
V_35 |= V_118 ;
V_21 = F_73 ( NULL , NULL , V_29 , V_30 , V_35 ) ;
if ( ! V_21 )
goto V_74;
if ( V_68 )
F_74 ( V_21 , V_68 ) ;
if ( V_42 )
{
V_44 = F_75 ( V_42 , V_41 ,
V_43 ) ;
if ( ! V_44 )
{
F_31 ( V_70 ,
L_162 ) ;
goto V_74;
}
}
}
else
V_35 |= V_125 ;
for ( V_124 = 0 ; V_124 < F_76 ( V_14 ) ; V_124 ++ )
{
V_121 * V_123 ;
V_11 = F_77 ( V_14 , V_124 ) ;
V_17 = F_77 ( V_15 , V_124 ) ;
V_26 = F_40 ( V_70 , V_11 , V_60 , NULL ,
V_3 , L_163 ) ;
if ( ! V_26 )
goto V_74;
V_27 = F_44 ( V_70 , V_17 , V_59 , 0 , V_51 , V_3 ,
L_152 ) ;
if ( ! V_27 )
goto V_74;
V_123 = F_78 ( V_21 , V_26 , V_27 , V_54 , V_35 ) ;
if ( ! V_123 )
goto V_74;
if ( V_44 && ! F_79 ( V_123 , V_44 ) )
goto V_74;
V_114 ( V_26 ) ;
V_26 = NULL ;
F_80 ( V_27 ) ;
V_27 = NULL ;
}
if ( ( V_4 == V_77 ) && ! ( V_35 & V_103 ) )
{
if ( ! F_67 ( V_21 , V_30 , NULL , V_35 ) )
goto V_74;
}
}
if ( ! V_21 )
{
F_28 ( V_70 , L_164 ) ;
goto V_74;
}
V_5 = 4 ;
if ( V_4 == V_76 )
{
if ( V_62 )
{
if ( ! F_81 ( V_21 ,
V_62 , V_66 ,
V_63 , V_67 ) )
{
F_31 ( V_70 ,
L_165 ) ;
goto V_74;
}
}
if ( V_27 )
{
if ( ! F_82 ( V_21 , V_27 , V_25 ) )
{
F_31 ( V_70 ,
L_166 ) ;
goto V_74;
}
}
if ( V_64 )
{
if ( ! F_83 ( V_21 , V_64 , - 1 ) )
{
F_31 ( V_70 ,
L_167 ) ;
goto V_74;
}
}
if ( ! F_84 ( V_21 , NULL , NULL , V_32 , V_31 , V_35 ) )
{
F_28 ( V_70 , L_168 ) ;
goto V_74;
}
}
else if ( V_4 == V_84 )
{
if ( ! F_85 ( V_21 , V_31 , V_35 ) )
goto V_74;
}
else if ( V_4 == V_89 )
{
if ( ! F_86 ( V_21 , V_32 , V_31 , V_35 ) )
goto V_74;
}
else if ( V_4 == V_86 )
{
if ( F_87 ( V_21 , V_32 , V_31 , V_35 ) > 0 )
F_28 ( V_70 , L_169 ) ;
else
{
F_28 ( V_70 , L_170 ) ;
goto V_74;
}
}
else if ( V_4 == V_90 )
{
if ( ! F_88 ( V_21 , V_62 , V_66 ,
V_32 , V_31 , V_35 ) )
goto V_74;
}
else if ( V_4 == V_80 )
{
if ( F_89 ( V_21 , V_29 , V_23 , V_32 , V_31 , V_35 ) > 0 )
F_28 ( V_70 , L_169 ) ;
else
{
F_28 ( V_70 , L_170 ) ;
if ( V_39 )
V_5 = V_126 + 32 ;
goto V_74;
}
if ( V_11 )
{
F_1 ( T_5 ) * V_127 ;
V_127 = F_90 ( V_21 ) ;
if ( ! F_52 ( V_11 , V_127 ) )
{
F_28 ( V_70 ,
L_171 ,
V_11 ) ;
V_5 = 5 ;
goto V_74;
}
F_91 ( V_127 ) ;
}
if ( V_40 )
F_92 ( V_70 , V_21 ) ;
}
else if ( V_4 == V_81 )
{
if ( F_93 ( V_22 , V_21 , V_29 , V_23 , V_35 ) > 0 )
F_28 ( V_70 , L_169 ) ;
else
{
F_28 ( V_70 , L_170 ) ;
goto V_74;
}
}
else
{
if ( V_37 )
{
if ( V_38 )
F_94 ( V_31 , V_21 , 0 , NULL ) ;
}
else if ( V_57 == V_56 )
{
if ( V_45 )
F_28 ( V_31 , L_172 , V_45 ) ;
if ( V_46 )
F_28 ( V_31 , L_173 , V_46 ) ;
if ( V_47 )
F_28 ( V_31 , L_174 , V_47 ) ;
if ( V_4 == V_79 )
V_5 = F_95 ( V_31 , V_21 , V_32 , V_35 ) ;
else
V_5 = F_95 ( V_31 , V_21 , V_30 , V_35 ) ;
}
else if ( V_57 == V_60 )
V_5 = F_96 ( V_31 , V_21 , V_30 , V_35 ) ;
else if ( V_57 == V_110 )
V_5 = F_97 ( V_31 , V_21 , V_30 , V_35 ) ;
else
{
F_28 ( V_70 , L_175 ) ;
goto V_74;
}
if ( V_5 <= 0 )
{
V_5 = 6 ;
goto V_74;
}
}
V_5 = 0 ;
V_74:
if ( V_5 )
F_43 ( V_70 ) ;
if ( V_53 )
F_98 ( NULL , V_70 ) ;
F_53 ( V_28 , V_114 ) ;
F_53 ( V_29 , V_114 ) ;
if ( V_69 )
F_99 ( V_69 ) ;
if ( V_14 )
F_100 ( V_14 ) ;
if ( V_15 )
F_100 ( V_15 ) ;
if ( V_62 )
F_101 ( V_62 ) ;
if ( V_63 )
F_101 ( V_63 ) ;
if ( V_65 )
F_101 ( V_65 ) ;
if ( V_68 )
F_102 ( V_68 ) ;
if ( V_44 )
F_103 ( V_44 ) ;
if ( V_42 )
F_100 ( V_42 ) ;
if ( V_43 )
F_100 ( V_43 ) ;
F_104 ( V_23 ) ;
V_114 ( V_24 ) ;
V_114 ( V_25 ) ;
V_114 ( V_26 ) ;
F_80 ( V_27 ) ;
F_72 ( V_21 ) ;
F_72 ( V_22 ) ;
F_50 ( V_33 ) ;
F_50 ( V_30 ) ;
F_50 ( V_32 ) ;
F_105 ( V_31 ) ;
if ( V_51 ) F_101 ( V_51 ) ;
return ( V_5 ) ;
}
static int V_117 ( int V_128 , T_13 * V_129 )
{
int error ;
error = F_106 ( V_129 ) ;
V_126 = error ;
if ( ( error != V_130 )
&& ( ( error != V_131 ) || ( V_128 != 2 ) ) )
return V_128 ;
F_107 ( NULL , V_129 ) ;
return V_128 ;
}
static void F_92 ( T_7 * V_31 , T_3 * V_21 )
{
F_1 ( V_121 ) * V_122 ;
V_121 * V_123 ;
T_8 * V_44 ;
int V_132 ;
F_1 ( V_133 ) * V_134 , * V_135 ;
T_14 * V_136 ;
int V_124 , V_137 ;
V_122 = F_69 ( V_21 ) ;
for ( V_124 = 0 ; V_124 < F_108 ( V_122 ) ; V_124 ++ )
{
V_123 = F_70 ( V_122 , V_124 ) ;
V_137 = F_109 ( V_123 , & V_44 ) ;
F_28 ( V_70 , L_176 , V_124 + 1 ) ;
if ( V_137 == 0 )
F_31 ( V_70 , L_177 ) ;
else if ( V_137 < 0 )
{
F_31 ( V_70 , L_178 ) ;
F_43 ( V_70 ) ;
}
else
{
char * V_138 ;
int V_139 ;
F_110 ( V_44 , & V_136 , & V_132 ,
& V_135 , & V_134 ) ;
F_31 ( V_31 , L_179 ) ;
V_139 = F_111 ( V_136 ) ;
V_138 = ( char * ) F_112 ( V_136 ) ;
F_113 ( V_31 , V_138 , V_139 , 4 ) ;
F_31 ( V_31 , L_180 ) ;
if ( V_135 )
{
F_31 ( V_31 , L_181 ) ;
F_114 ( V_31 , V_135 ) ;
}
else if ( V_132 == 1 )
F_31 ( V_31 , L_182 ) ;
else if ( V_132 == 0 )
F_31 ( V_31 , L_183 ) ;
else
F_28 ( V_31 , L_184 , V_132 ) ;
F_31 ( V_31 , L_185 ) ;
F_114 ( V_31 , V_134 ) ;
}
if ( V_44 )
F_103 ( V_44 ) ;
}
}
