int F_1 ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
T_2 * V_4 = NULL , * V_5 = NULL ;
T_3 * V_6 = NULL , * V_7 = NULL ;
T_4 * V_8 = NULL ;
T_5 * V_9 = NULL ;
F_2 ( V_10 ) * V_11 = NULL , * V_12 = NULL ;
T_6 * V_13 = NULL ;
T_7 * V_14 = NULL ;
const T_8 * V_15 = NULL ;
const T_9 * V_16 = NULL , * V_17 = NULL ;
char * V_18 = NULL , * V_19 = NULL ;
char * V_20 = NULL , * V_21 = NULL , * V_22 = NULL ;
char * V_23 = NULL , * V_24 , * V_25 , * V_26 = NULL , * V_27 = NULL ;
char * V_28 = NULL , * V_29 = NULL ;
char * V_30 = NULL , * V_31 = NULL ;
char * V_32 = NULL , * V_33 = NULL ;
char * V_34 = V_35 , * V_36 = NULL ;
const char * V_37 = NULL ;
T_10 V_38 ;
int V_39 = 1 , V_40 = 0 , V_41 = 30 , V_42 = 0 , V_43 = 0 , V_44 = 0 ;
int V_45 = - 1 , V_46 = 0 ;
int V_47 = V_48 , V_49 = V_48 , V_50 = V_48 ;
int V_51 = 0 , V_52 = 0 , V_53 = 0 , V_54 = 0 , V_55 = 0 ;
int V_56 = 0 , V_57 = 0 , V_58 = 0 , V_59 = 0 ;
long V_60 = - 1 ;
unsigned long V_61 = V_62 , V_63 = 0 , V_64 = 0 ;
char V_65 = 0 ;
#ifndef F_3
V_15 = F_4 () ;
#endif
V_25 = F_5 ( V_1 , V_2 , V_66 ) ;
while ( ( V_38 = F_6 () ) != V_67 ) {
switch ( V_38 ) {
case V_67 :
case V_68 :
V_69:
F_7 ( V_70 , L_1 , V_25 ) ;
goto V_71;
case V_72 :
F_8 ( V_66 ) ;
V_39 = 0 ;
goto V_71;
case V_73 :
if ( ! F_9 ( F_10 () , V_74 , & V_47 ) )
goto V_69;
break;
case V_75 :
if ( ! F_9 ( F_10 () , V_74 , & V_49 ) )
goto V_69;
break;
case V_76 :
V_6 = F_11 ( F_10 () , 0 ) ;
break;
case V_77 :
#ifndef F_12
V_7 = F_13 ( F_10 () ) ;
if ( V_7 == NULL ) {
F_7 ( V_70 , L_2 , * V_2 ) ;
goto V_69;
}
#endif
break;
case V_78 :
V_21 = F_10 () ;
break;
case V_79 :
V_59 = 1 ;
break;
case V_80 :
V_43 = 1 ;
break;
case V_81 :
V_34 = F_10 () ;
break;
case V_82 :
if ( ! F_9 ( F_10 () , V_83 , & V_50 ) )
goto V_69;
break;
case V_84 :
V_19 = F_10 () ;
break;
case V_85 :
V_20 = F_10 () ;
break;
case V_86 :
V_36 = F_10 () ;
break;
case V_87 :
V_26 = F_10 () ;
break;
case V_88 :
V_27 = F_10 () ;
break;
case V_89 :
V_22 = F_10 () ;
break;
case V_90 :
V_37 = F_10 () ;
V_43 = 1 ;
break;
case V_91 :
if ( ! V_11 )
V_11 = F_14 () ;
if ( ! V_11 || ! F_15 ( V_11 , F_10 () ) )
goto V_69;
break;
case V_92 :
if ( ! V_12 )
V_12 = F_14 () ;
if ( ! V_12 || ! F_15 ( V_12 , F_10 () ) )
goto V_69;
break;
case V_93 :
V_94 = 1 ;
break;
case V_95 :
V_57 = 1 ;
break;
case V_96 :
V_51 = 1 ;
break;
case V_97 :
V_53 = 1 ;
break;
case V_98 :
V_56 = 1 ;
break;
case V_99 :
V_54 = 1 ;
break;
case V_100 :
V_44 = 1 ;
break;
case V_101 :
V_61 = V_102 ;
break;
case V_103 :
V_65 = 1 ;
if ( ! F_16 ( & V_63 , F_10 () ) )
goto V_69;
break;
case V_104 :
if ( ! F_17 ( & V_64 , F_10 () ) )
goto V_69;
break;
case V_105 :
V_55 = 1 ;
break;
case V_106 :
V_40 = 1 ;
V_43 = 1 ;
break;
case V_107 :
V_41 = atoi ( F_10 () ) ;
break;
case V_108 :
if ( V_3 != NULL ) {
F_7 ( V_70 , L_3 ) ;
goto V_69;
}
V_3 = F_18 ( NULL , F_10 () ) ;
if ( V_3 == NULL )
goto V_69;
break;
case V_109 :
V_58 = 1 ;
break;
case V_110 :
V_33 = F_10 () ;
break;
case V_111 :
V_52 = 1 ;
break;
case V_112 :
V_18 = F_10 () ;
break;
case V_113 :
V_32 = F_10 () ;
break;
case V_114 :
if ( ! F_19 ( F_20 () , & V_16 ) )
goto V_69;
V_17 = V_16 ;
break;
}
}
V_1 = F_21 () ;
if ( V_1 != 0 )
goto V_69;
if ( ! V_65 )
V_63 = V_115 ;
V_46 = V_43 && ( V_8 == NULL ) ? 1 : 0 ;
if ( ! F_22 ( V_26 , V_27 , & V_28 , & V_29 ) ) {
F_7 ( V_70 , L_4 ) ;
goto V_71;
}
if ( V_44 )
F_7 ( V_70 , L_5 , V_34 ) ;
V_116 = F_23 ( V_34 ) ;
if ( V_34 != V_35 && ! F_24 ( V_116 ) )
goto V_71;
if ( V_116 != NULL ) {
V_24 = F_25 ( V_116 , NULL , L_6 ) ;
if ( V_24 == NULL )
F_26 () ;
if ( V_24 != NULL ) {
T_2 * V_117 ;
V_117 = F_27 ( V_24 , L_7 ) ;
if ( V_117 == NULL ) {
} else {
F_28 ( V_117 ) ;
F_29 ( V_117 ) ;
}
}
}
if ( ! F_30 ( V_116 ) )
goto V_71;
if ( V_16 == NULL ) {
V_24 = F_25 ( V_116 , V_118 , L_8 ) ;
if ( V_24 == NULL )
F_26 () ;
else {
if ( ! F_19 ( V_24 , & V_16 ) )
goto V_69;
V_17 = V_16 ;
}
}
if ( ! V_18 ) {
V_18 = F_25 ( V_116 , V_118 , V_119 ) ;
if ( ! V_18 )
F_26 () ;
}
if ( V_18 ) {
T_11 V_120 ;
F_31 ( & V_120 ) ;
F_32 ( & V_120 , V_116 ) ;
if ( ! F_33 ( V_116 , & V_120 , V_18 , NULL ) ) {
F_7 ( V_70 ,
L_9 , V_18 ) ;
goto V_71;
}
}
if ( V_28 == NULL ) {
V_28 = V_30 =
F_25 ( V_116 , V_118 , L_10 ) ;
if ( V_28 == NULL )
F_26 () ;
}
if ( V_29 == NULL ) {
V_29 = V_31 =
F_25 ( V_116 , V_118 , L_11 ) ;
if ( V_29 == NULL )
F_26 () ;
}
V_24 = F_25 ( V_116 , V_118 , V_121 ) ;
if ( ! V_24 )
F_26 () ;
if ( V_24 && ! F_34 ( V_24 ) ) {
F_7 ( V_70 , L_12 , V_24 ) ;
goto V_71;
}
if ( V_61 != V_102 ) {
V_24 = F_25 ( V_116 , V_118 , V_122 ) ;
if ( ! V_24 )
F_26 () ;
else if ( strcmp ( V_24 , L_13 ) == 0 )
V_61 = V_102 ;
}
if ( ! V_32 ) {
V_32 = F_25 ( V_116 , V_118 , V_123 ) ;
if ( ! V_32 )
F_26 () ;
}
if ( V_32 ) {
T_11 V_120 ;
F_31 ( & V_120 ) ;
F_32 ( & V_120 , V_116 ) ;
if ( ! F_33 ( V_116 , & V_120 , V_32 , NULL ) ) {
F_7 ( V_70 ,
L_14 ,
V_32 ) ;
goto V_71;
}
}
if ( V_21 != NULL ) {
V_8 = F_35 ( V_21 , V_50 , 0 , V_28 , V_6 , L_15 ) ;
if ( ! V_8 ) {
goto V_71;
} else {
char * V_124 = F_25 ( V_116 , V_118 , L_16 ) ;
if ( V_124 == NULL )
F_26 () ;
F_36 ( V_124 , 0 ) ;
}
}
if ( V_43 && ( V_8 == NULL ) ) {
char * V_124 = F_25 ( V_116 , V_118 , L_16 ) ;
if ( V_124 == NULL )
F_26 () ;
F_36 ( V_124 , 0 ) ;
if ( V_22 )
F_37 ( V_22 ) ;
if ( ! F_38 ( V_116 , V_118 , V_125 , & V_60 ) ) {
V_60 = V_126 ;
}
if ( V_37 ) {
V_9 = F_39 ( V_37 , & V_45 , & V_60 ,
& V_23 , V_7 ) ;
if ( ! V_9 )
goto V_71;
}
if ( V_60 < V_127
&& ( V_45 == V_128 || V_45 == V_129 ) ) {
F_7 ( V_70 , L_17 ) ;
F_7 ( V_70 , L_18 ,
V_127 , V_60 ) ;
goto V_71;
}
if ( ! V_9 ) {
V_9 = F_39 ( NULL , & V_45 , & V_60 ,
& V_23 , V_7 ) ;
if ( ! V_9 )
goto V_71;
}
if ( V_11 ) {
char * V_130 ;
for ( V_42 = 0 ; V_42 < F_40 ( V_11 ) ; V_42 ++ ) {
V_130 = F_41 ( V_11 , V_42 ) ;
if ( F_42 ( V_9 , V_130 ) <= 0 ) {
F_7 ( V_70 , L_19 , V_130 ) ;
F_43 ( V_70 ) ;
goto V_71;
}
}
}
if ( V_45 == V_131 ) {
F_7 ( V_70 , L_20 ) ;
} else {
F_7 ( V_70 , L_21 ,
V_60 , V_23 ) ;
}
F_44 ( V_9 , V_132 ) ;
F_45 ( V_9 , V_70 ) ;
if ( F_46 ( V_9 , & V_8 ) <= 0 ) {
F_47 ( V_70 , L_22 ) ;
goto V_71;
}
F_48 ( V_9 ) ;
V_9 = NULL ;
F_49 ( V_124 ) ;
if ( V_36 == NULL ) {
V_36 = F_25 ( V_116 , V_118 , V_133 ) ;
if ( V_36 == NULL )
F_26 () ;
}
if ( V_36 == NULL )
F_7 ( V_70 , L_23 ) ;
else
F_7 ( V_70 , L_24 , V_36 ) ;
V_5 = F_50 ( V_36 , V_49 , V_46 ) ;
if ( V_5 == NULL )
goto V_71;
V_24 = F_25 ( V_116 , V_118 , L_25 ) ;
if ( V_24 == NULL ) {
F_26 () ;
V_24 = F_25 ( V_116 , V_118 , L_26 ) ;
if ( V_24 == NULL )
F_26 () ;
}
if ( ( V_24 != NULL ) && ( strcmp ( V_24 , L_27 ) == 0 ) )
V_15 = NULL ;
if ( V_56 )
V_15 = NULL ;
V_42 = 0 ;
V_134:
assert ( V_46 ) ;
if ( ! F_51 ( V_5 , V_8 , V_15 ,
NULL , 0 , NULL , V_29 ) ) {
if ( ( F_52 ( F_53 () ) ==
V_135 ) && ( V_42 < 3 ) ) {
F_26 () ;
V_42 ++ ;
goto V_134;
}
goto V_71;
}
F_29 ( V_5 ) ;
V_5 = NULL ;
F_7 ( V_70 , L_28 ) ;
}
if ( ! V_43 ) {
V_4 = F_54 ( V_19 , 'r' , V_47 ) ;
if ( V_4 == NULL )
goto V_71;
if ( V_47 == V_136 )
V_14 = F_55 ( V_4 , NULL ) ;
else
V_14 = F_56 ( V_4 , NULL , NULL , NULL ) ;
if ( V_14 == NULL ) {
F_7 ( V_70 , L_29 ) ;
goto V_71;
}
}
if ( V_43 ) {
if ( V_8 == NULL ) {
F_7 ( V_70 , L_30 ) ;
goto V_71;
}
if ( V_14 == NULL ) {
V_14 = F_57 () ;
if ( V_14 == NULL ) {
goto V_71;
}
V_42 = F_58 ( V_14 , V_8 , V_33 , V_52 , ! V_40 , V_61 ) ;
V_33 = NULL ;
if ( ! V_42 ) {
F_7 ( V_70 , L_31 ) ;
goto V_71;
}
}
if ( V_40 ) {
T_4 * V_137 ;
T_11 V_138 ;
if ( ( V_13 = F_59 () ) == NULL )
goto V_71;
if ( V_18 && ! F_60 ( V_13 , 2 ) )
goto V_71;
if ( V_3 ) {
if ( ! F_61 ( V_13 , V_3 ) )
goto V_71;
} else {
if ( ! F_62 ( NULL , F_63 ( V_13 ) ) )
goto V_71;
}
if ( ! F_64 ( V_13 , F_65 ( V_14 ) ) )
goto V_71;
if ( ! F_66 ( V_13 , NULL , NULL , V_41 ) )
goto V_71;
if ( ! F_67
( V_13 , F_65 ( V_14 ) ) )
goto V_71;
V_137 = F_68 ( V_14 ) ;
if ( ! V_137 || ! F_69 ( V_13 , V_137 ) )
goto V_71;
F_70 ( & V_138 , V_13 , V_13 , NULL , NULL , 0 ) ;
F_32 ( & V_138 , V_116 ) ;
if ( V_18 && ! F_33 ( V_116 ,
& V_138 , V_18 ,
V_13 ) ) {
F_7 ( V_70 , L_9 ,
V_18 ) ;
goto V_71;
}
V_42 = F_71 ( V_13 , V_8 , V_17 , V_12 ) ;
if ( ! V_42 ) {
F_43 ( V_70 ) ;
goto V_71;
}
} else {
T_11 V_138 ;
F_70 ( & V_138 , NULL , NULL , V_14 , NULL , 0 ) ;
F_32 ( & V_138 , V_116 ) ;
if ( V_32 && ! F_72 ( V_116 ,
& V_138 , V_32 ,
V_14 ) ) {
F_7 ( V_70 , L_9 ,
V_32 ) ;
goto V_71;
}
V_42 = F_73 ( V_14 , V_8 , V_17 , V_12 ) ;
if ( ! V_42 ) {
F_43 ( V_70 ) ;
goto V_71;
}
}
}
if ( V_33 && V_40 ) {
F_7 ( V_70 , L_32 ) ;
goto V_71;
}
if ( V_33 && ! V_40 ) {
if ( V_44 ) {
F_7 ( V_70 , L_33 ) ;
F_74 ( V_70 , L_34 ,
F_65 ( V_14 ) , V_63 ) ;
}
if ( F_75 ( V_14 , V_33 , V_61 , V_52 ) == 0 ) {
F_7 ( V_70 , L_35 ) ;
V_39 = 1 ;
goto V_71;
}
if ( V_44 ) {
F_74 ( V_70 , L_36 ,
F_65 ( V_14 ) , V_63 ) ;
}
}
if ( V_53 && ! V_40 ) {
T_4 * V_139 = V_8 ;
if ( V_139 == NULL ) {
V_139 = F_68 ( V_14 ) ;
if ( V_139 == NULL )
goto V_71;
}
V_42 = F_76 ( V_14 , V_139 ) ;
if ( V_42 < 0 ) {
goto V_71;
} else if ( V_42 == 0 ) {
F_7 ( V_70 , L_37 ) ;
F_43 ( V_70 ) ;
} else
F_7 ( V_70 , L_38 ) ;
}
if ( V_54 && ! V_55 && ! V_51 && ! V_58 && ! V_59 ) {
V_39 = 0 ;
goto V_71;
}
V_5 = F_54 ( V_20 ,
V_36 != NULL && V_20 != NULL &&
strcmp ( V_36 , V_20 ) == 0 ? 'a' : 'w' ,
V_49 ) ;
if ( V_5 == NULL )
goto V_71;
if ( V_59 ) {
T_4 * V_139 = F_68 ( V_14 ) ;
if ( V_139 == NULL ) {
F_7 ( V_70 , L_39 ) ;
F_43 ( V_70 ) ;
goto V_71;
}
F_77 ( V_5 , V_139 ) ;
}
if ( V_55 ) {
if ( V_40 )
F_78 ( V_5 , V_13 , V_63 , V_64 ) ;
else
F_79 ( V_5 , V_14 , V_63 , V_64 ) ;
}
if ( V_58 ) {
if ( V_40 )
F_74 ( V_5 , L_40 , F_80 ( V_13 ) ,
V_63 ) ;
else
F_74 ( V_5 , L_40 , F_65 ( V_14 ) ,
V_63 ) ;
}
if ( V_51 ) {
T_4 * V_139 ;
if ( V_40 )
V_139 = F_81 ( V_13 ) ;
else
V_139 = F_68 ( V_14 ) ;
if ( V_139 == NULL ) {
fprintf ( stdout , L_41 ) ;
goto V_71;
}
fprintf ( stdout , L_42 ) ;
#ifndef F_82
if ( F_83 ( V_139 ) == V_128 ) {
const T_12 * V_140 ;
F_84 ( F_85 ( V_139 ) , & V_140 , NULL , NULL ) ;
F_86 ( V_5 , V_140 ) ;
} else
#endif
fprintf ( stdout , L_43 ) ;
fprintf ( stdout , L_44 ) ;
}
if ( ! V_54 && ! V_40 ) {
if ( V_49 == V_136 )
V_42 = F_87 ( V_5 , V_14 ) ;
else if ( V_57 )
V_42 = F_88 ( V_5 , V_14 ) ;
else
V_42 = F_89 ( V_5 , V_14 ) ;
if ( ! V_42 ) {
F_7 ( V_70 , L_45 ) ;
goto V_71;
}
}
if ( ! V_54 && V_40 && ( V_13 != NULL ) ) {
if ( V_49 == V_136 )
V_42 = F_90 ( V_5 , V_13 ) ;
else
V_42 = F_91 ( V_5 , V_13 ) ;
if ( ! V_42 ) {
F_7 ( V_70 , L_46 ) ;
goto V_71;
}
}
V_39 = 0 ;
V_71:
if ( V_39 ) {
F_43 ( V_70 ) ;
}
F_92 ( V_116 ) ;
F_29 ( V_4 ) ;
F_93 ( V_5 ) ;
F_94 ( V_8 ) ;
F_48 ( V_9 ) ;
F_95 ( V_11 ) ;
F_95 ( V_12 ) ;
#ifndef F_12
F_96 ( V_7 ) ;
#endif
F_97 ( V_23 ) ;
F_98 ( V_14 ) ;
F_99 ( V_13 ) ;
F_100 ( V_3 ) ;
if ( V_28 != V_30 )
F_97 ( V_28 ) ;
if ( V_29 != V_31 )
F_97 ( V_29 ) ;
return ( V_39 ) ;
}
static int F_58 ( T_7 * V_14 , T_4 * V_8 , char * V_33 , int V_52 ,
int V_141 , unsigned long V_61 )
{
int V_39 = 0 , V_42 ;
char V_142 = 0 ;
F_2 ( V_143 ) * V_144 , * V_145 = NULL ;
char * V_146 , * V_147 , * V_148 ;
V_146 = F_25 ( V_116 , V_118 , V_149 ) ;
if ( V_146 == NULL )
F_26 () ;
if ( ( V_146 != NULL ) && strcmp ( V_146 , L_27 ) == 0 )
V_142 = 1 ;
V_147 = F_25 ( V_116 , V_118 , V_150 ) ;
if ( V_147 == NULL ) {
F_7 ( V_70 , L_47 ,
V_150 ) ;
goto V_151;
}
V_144 = F_101 ( V_116 , V_147 ) ;
if ( V_144 == NULL ) {
F_7 ( V_70 , L_48 , V_147 ) ;
goto V_151;
}
V_148 = F_25 ( V_116 , V_118 , V_152 ) ;
if ( V_148 == NULL ) {
F_26 () ;
V_145 = NULL ;
} else {
V_145 = F_101 ( V_116 , V_148 ) ;
if ( V_145 == NULL ) {
F_7 ( V_70 , L_48 , V_148 ) ;
goto V_151;
}
}
if ( ! F_102 ( V_14 , 0L ) )
goto V_151;
if ( V_33 )
V_42 = F_75 ( V_14 , V_33 , V_61 , V_52 ) ;
else if ( V_142 )
V_42 = F_103 ( V_14 , V_144 , V_145 , V_141 , V_61 ) ;
else
V_42 = F_104 ( V_14 , V_144 , V_147 , V_145 , V_148 , V_141 ,
V_61 ) ;
if ( ! V_42 )
goto V_151;
if ( ! F_105 ( V_14 , V_8 ) )
goto V_151;
V_39 = 1 ;
V_151:
return ( V_39 ) ;
}
static int F_75 ( T_7 * V_14 , const char * V_58 , unsigned long V_61 ,
int V_52 )
{
T_13 * V_140 ;
if ( ( V_140 = F_106 ( V_58 , V_61 , V_52 ) ) == NULL )
return 0 ;
if ( ! F_107 ( V_14 , V_140 ) ) {
F_108 ( V_140 ) ;
return 0 ;
}
F_108 ( V_140 ) ;
return 1 ;
}
static int F_109 ( T_13 * V_140 , char * V_55 , const char * V_153 ,
char * V_154 , int V_155 , int V_156 , int V_157 ,
unsigned long V_61 , int V_158 )
{
int V_42 , V_39 = 0 ;
char V_159 [ 1024 ] ;
V_160:
if ( ! V_94 )
F_7 ( V_70 , L_49 , V_55 , V_153 ) ;
( void ) F_110 ( V_70 ) ;
if ( V_154 != NULL ) {
F_111 ( V_159 , V_154 , sizeof V_159 ) ;
F_112 ( V_159 , L_44 , sizeof V_159 ) ;
F_7 ( V_70 , L_50 , V_154 ) ;
} else {
V_159 [ 0 ] = '\0' ;
if ( ! V_94 ) {
if ( ! fgets ( V_159 , sizeof V_159 , V_161 ) )
return 0 ;
} else {
V_159 [ 0 ] = '\n' ;
V_159 [ 1 ] = '\0' ;
}
}
if ( V_159 [ 0 ] == '\0' )
return ( 0 ) ;
else if ( V_159 [ 0 ] == '\n' ) {
if ( ( V_153 == NULL ) || ( V_153 [ 0 ] == '\0' ) )
return ( 1 ) ;
F_111 ( V_159 , V_153 , sizeof V_159 ) ;
F_112 ( V_159 , L_44 , sizeof V_159 ) ;
} else if ( ( V_159 [ 0 ] == '.' ) && ( V_159 [ 1 ] == '\n' ) )
return ( 1 ) ;
V_42 = strlen ( V_159 ) ;
if ( V_159 [ V_42 - 1 ] != '\n' ) {
F_7 ( V_70 , L_51 ) ;
return ( 0 ) ;
}
V_159 [ -- V_42 ] = '\0' ;
#ifdef F_113
F_114 ( V_159 , V_159 , V_42 ) ;
#endif
if ( ! F_115 ( V_42 , V_156 , V_157 ) ) {
if ( V_94 || V_154 )
return 0 ;
goto V_160;
}
if ( ! F_116 ( V_140 , V_155 , V_61 ,
( unsigned char * ) V_159 , - 1 , - 1 , V_158 ) )
goto V_151;
V_39 = 1 ;
V_151:
return ( V_39 ) ;
}
static int F_117 ( T_7 * V_14 , char * V_55 , const char * V_153 ,
char * V_154 , int V_155 , int V_156 ,
int V_157 , unsigned long V_61 )
{
int V_42 ;
static char V_159 [ 1024 ] ;
V_160:
if ( ! V_94 )
F_7 ( V_70 , L_49 , V_55 , V_153 ) ;
( void ) F_110 ( V_70 ) ;
if ( V_154 != NULL ) {
F_111 ( V_159 , V_154 , sizeof V_159 ) ;
F_112 ( V_159 , L_44 , sizeof V_159 ) ;
F_7 ( V_70 , L_50 , V_154 ) ;
} else {
V_159 [ 0 ] = '\0' ;
if ( ! V_94 ) {
if ( ! fgets ( V_159 , sizeof V_159 , V_161 ) )
return 0 ;
} else {
V_159 [ 0 ] = '\n' ;
V_159 [ 1 ] = '\0' ;
}
}
if ( V_159 [ 0 ] == '\0' )
return ( 0 ) ;
else if ( V_159 [ 0 ] == '\n' ) {
if ( ( V_153 == NULL ) || ( V_153 [ 0 ] == '\0' ) )
return ( 1 ) ;
F_111 ( V_159 , V_153 , sizeof V_159 ) ;
F_112 ( V_159 , L_44 , sizeof V_159 ) ;
} else if ( ( V_159 [ 0 ] == '.' ) && ( V_159 [ 1 ] == '\n' ) )
return ( 1 ) ;
V_42 = strlen ( V_159 ) ;
if ( V_159 [ V_42 - 1 ] != '\n' ) {
F_7 ( V_70 , L_51 ) ;
return ( 0 ) ;
}
V_159 [ -- V_42 ] = '\0' ;
#ifdef F_113
F_114 ( V_159 , V_159 , V_42 ) ;
#endif
if ( ! F_115 ( V_42 , V_156 , V_157 ) ) {
if ( V_94 || V_154 )
return 0 ;
goto V_160;
}
if ( ! F_118 ( V_14 , V_155 , V_61 ,
( unsigned char * ) V_159 , - 1 ) ) {
F_7 ( V_70 , L_52 ) ;
F_43 ( V_70 ) ;
goto V_151;
}
return ( 1 ) ;
V_151:
return ( 0 ) ;
}
static int F_115 ( int V_162 , int V_156 , int V_157 )
{
if ( ( V_156 > 0 ) && ( V_162 < V_156 ) ) {
F_7 ( V_70 ,
L_53 ,
V_156 ) ;
return ( 0 ) ;
}
if ( ( V_157 >= 0 ) && ( V_162 > V_157 ) ) {
F_7 ( V_70 ,
L_54 ,
V_157 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int F_119 ( const char * V_163 , const char * V_71 )
{
int V_164 , V_165 ;
const char * V_146 ;
V_164 = strlen ( V_71 ) ;
V_165 = strlen ( V_163 ) ;
if ( V_164 > V_165 )
return 1 ;
V_146 = V_163 + V_165 - V_164 ;
return strcmp ( V_146 , V_71 ) ;
}
static T_5 * F_39 ( const char * V_166 ,
int * V_45 , long * V_167 ,
char * * V_168 , T_3 * V_169 )
{
T_5 * V_170 = NULL ;
T_4 * V_171 = NULL ;
long V_172 = - 1 ;
T_2 * V_173 = NULL ;
const char * V_174 = NULL ;
if ( V_166 == NULL ) {
* V_45 = V_128 ;
V_172 = * V_167 ;
} else if ( V_166 [ 0 ] >= '0' && V_166 [ 0 ] <= '9' ) {
* V_45 = V_128 ;
V_172 = atol ( V_166 ) ;
* V_167 = V_172 ;
} else if ( strncmp ( V_166 , L_55 , 6 ) == 0 )
V_174 = V_166 + 6 ;
else {
const char * V_24 = strchr ( V_166 , ':' ) ;
int V_162 ;
T_3 * V_175 ;
const T_14 * V_176 ;
if ( V_24 )
V_162 = V_24 - V_166 ;
else
V_162 = strlen ( V_166 ) ;
V_176 = F_120 ( & V_175 , V_166 , V_162 ) ;
if ( ! V_176 ) {
F_7 ( V_70 , L_56 , V_162 , V_166 ) ;
return NULL ;
}
F_121 ( NULL , V_45 , NULL , NULL , NULL , V_176 ) ;
#ifndef F_12
F_122 ( V_175 ) ;
#endif
if ( * V_45 == V_128 ) {
if ( V_24 ) {
V_172 = atol ( V_24 + 1 ) ;
* V_167 = V_172 ;
} else
V_172 = * V_167 ;
} else if ( V_24 )
V_174 = V_24 + 1 ;
}
if ( V_174 ) {
V_173 = F_27 ( V_174 , L_7 ) ;
if ( ! V_173 ) {
F_7 ( V_70 , L_57 , V_174 ) ;
return NULL ;
}
V_171 = F_123 ( V_173 , NULL ) ;
if ( ! V_171 ) {
T_6 * V_177 ;
( void ) F_124 ( V_173 ) ;
V_177 = F_125 ( V_173 , NULL , NULL , NULL ) ;
if ( V_177 ) {
V_171 = F_126 ( V_177 ) ;
F_99 ( V_177 ) ;
}
}
F_29 ( V_173 ) ;
if ( ! V_171 ) {
F_7 ( V_70 , L_58 , V_174 ) ;
return NULL ;
}
if ( * V_45 == - 1 )
* V_45 = F_127 ( V_171 ) ;
else if ( * V_45 != F_83 ( V_171 ) ) {
F_7 ( V_70 , L_59 ) ;
F_94 ( V_171 ) ;
return NULL ;
}
}
if ( V_168 ) {
const T_14 * V_176 ;
T_3 * V_175 ;
const char * V_178 ;
V_176 = F_128 ( & V_175 , * V_45 ) ;
if ( ! V_176 ) {
F_47 ( V_70 , L_60 ) ;
return NULL ;
}
F_121 ( NULL , NULL , NULL , NULL , & V_178 , V_176 ) ;
* V_168 = F_129 ( V_178 ) ;
#ifndef F_12
F_122 ( V_175 ) ;
#endif
}
if ( V_171 ) {
V_170 = F_130 ( V_171 , V_169 ) ;
* V_167 = F_131 ( V_171 ) ;
F_94 ( V_171 ) ;
} else
V_170 = F_132 ( * V_45 , V_169 ) ;
if ( V_170 == NULL ) {
F_47 ( V_70 , L_61 ) ;
F_43 ( V_70 ) ;
return NULL ;
}
if ( F_133 ( V_170 ) <= 0 ) {
F_47 ( V_70 , L_62 ) ;
F_43 ( V_70 ) ;
F_48 ( V_170 ) ;
return NULL ;
}
#ifndef F_82
if ( ( * V_45 == V_128 ) && ( V_172 != - 1 ) ) {
if ( F_134 ( V_170 , V_172 ) <= 0 ) {
F_47 ( V_70 , L_63 ) ;
F_43 ( V_70 ) ;
F_48 ( V_170 ) ;
return NULL ;
}
}
#endif
return V_170 ;
}
static int V_132 ( T_5 * V_120 )
{
char V_179 = '*' ;
T_2 * V_180 = F_135 ( V_120 ) ;
int V_24 ;
V_24 = F_136 ( V_120 , 0 ) ;
if ( V_24 == 0 )
V_179 = '.' ;
if ( V_24 == 1 )
V_179 = '+' ;
if ( V_24 == 2 )
V_179 = '*' ;
if ( V_24 == 3 )
V_179 = '\n' ;
F_137 ( V_180 , & V_179 , 1 ) ;
( void ) F_110 ( V_180 ) ;
return 1 ;
}
