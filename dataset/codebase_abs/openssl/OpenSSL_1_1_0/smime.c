int F_1 ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL , * V_4 = NULL , * V_5 = NULL ;
T_2 * V_6 = NULL ;
T_3 * V_7 = NULL ;
F_2 ( V_8 ) * V_9 = NULL , * V_10 = NULL ;
F_2 ( V_11 ) * V_12 = NULL , * V_13 = NULL ;
V_11 * V_14 = NULL , * V_15 = NULL , * V_16 = NULL ;
T_4 * V_17 = NULL ;
T_5 * V_18 = NULL ;
const T_6 * V_19 = NULL ;
const T_7 * V_20 = NULL ;
const char * V_21 = NULL , * V_22 = NULL , * V_23 = NULL ;
char * V_24 = NULL , * V_25 = NULL , * V_26 = NULL , * V_27 = NULL ;
char * V_28 = NULL , * V_29 = NULL , * V_30 = NULL , * V_31 =
NULL ;
char * V_32 = NULL , * V_33 = NULL , * V_34 = NULL , * V_35 =
NULL , * V_36 = NULL ;
T_8 V_37 ;
int V_38 = 0 , V_39 = 0 ;
int V_40 = V_41 , V_42 = 0 , V_43 = 0 , V_44 = 0 , V_45 =
0 ;
int V_46 = V_47 , V_48 = V_47 , V_49 =
V_50 ;
int V_51 = 0 , V_52 = 0 ;
T_9 * V_53 = NULL ;
const char * V_54 = L_1 ;
if ( ( V_18 = F_3 () ) == NULL )
return 1 ;
V_23 = F_4 ( V_1 , V_2 , V_55 ) ;
while ( ( V_37 = F_5 () ) != V_56 ) {
switch ( V_37 ) {
case V_56 :
case V_57 :
V_58:
F_6 ( V_59 , L_2 , V_23 ) ;
goto V_60;
case V_61 :
F_7 ( V_55 ) ;
V_43 = 0 ;
goto V_60;
case V_62 :
if ( ! F_8 ( F_9 () , V_63 , & V_46 ) )
goto V_58;
break;
case V_64 :
V_28 = F_9 () ;
break;
case V_65 :
if ( ! F_8 ( F_9 () , V_63 , & V_48 ) )
goto V_58;
break;
case V_66 :
V_29 = F_9 () ;
break;
case V_67 :
V_42 = V_68 ;
break;
case V_69 :
V_42 = V_70 ;
break;
case V_71 :
V_42 = V_72 ;
break;
case V_73 :
V_42 = V_74 ;
break;
case V_75 :
V_42 = V_76 ;
break;
case V_77 :
V_42 = V_78 ;
break;
case V_79 :
V_40 |= V_80 ;
break;
case V_81 :
V_40 |= V_82 ;
break;
case V_83 :
V_40 |= V_84 ;
break;
case V_85 :
V_40 |= V_86 ;
break;
case V_87 :
V_40 |= V_88 ;
break;
case V_89 :
V_40 |= V_90 ;
break;
case V_91 :
V_40 &= ~ V_41 ;
break;
case V_92 :
V_40 |= V_93 ;
break;
case V_94 :
V_40 |= V_95 ;
break;
case V_96 :
V_40 |= V_97 ;
break;
case V_98 :
case V_99 :
V_45 = 1 ;
break;
case V_100 :
V_45 = 0 ;
break;
case V_101 :
V_40 |= V_102 ;
break;
case V_103 :
V_40 |= V_104 ;
V_54 = L_3 ;
break;
case V_105 :
V_27 = F_9 () ;
V_44 = 1 ;
break;
case V_106 :
V_53 = F_10 ( F_9 () , 0 ) ;
break;
case V_107 :
V_32 = F_9 () ;
break;
case V_108 :
V_34 = F_9 () ;
break;
case V_109 :
V_35 = F_9 () ;
break;
case V_110 :
V_36 = F_9 () ;
break;
case V_111 :
if ( V_30 ) {
if ( V_9 == NULL
&& ( V_9 = F_11 () ) == NULL )
goto V_60;
F_12 ( V_9 , V_30 ) ;
if ( V_25 == NULL )
V_25 = V_30 ;
if ( V_10 == NULL
&& ( V_10 = F_11 () ) == NULL )
goto V_60;
F_12 ( V_10 , V_25 ) ;
V_25 = NULL ;
}
V_30 = F_9 () ;
break;
case V_112 :
V_31 = F_9 () ;
break;
case V_113 :
if ( ! F_13 ( F_9 () , & V_20 ) )
goto V_58;
break;
case V_114 :
if ( ! F_14 ( F_15 () , & V_19 ) )
goto V_58;
break;
case V_115 :
if ( V_25 ) {
if ( V_30 == NULL ) {
F_6 ( V_59 ,
L_4 , V_23 ) ;
goto V_58;
}
if ( V_9 == NULL
&& ( V_9 = F_11 () ) == NULL )
goto V_60;
F_12 ( V_9 , V_30 ) ;
V_30 = NULL ;
if ( V_10 == NULL
&& ( V_10 = F_11 () ) == NULL )
goto V_60;
F_12 ( V_10 , V_25 ) ;
}
V_25 = F_9 () ;
break;
case V_116 :
if ( ! F_8 ( F_9 () , V_117 , & V_49 ) )
goto V_58;
break;
case V_118 :
V_24 = F_9 () ;
break;
case V_119 :
V_21 = F_9 () ;
break;
case V_120 :
V_22 = F_9 () ;
break;
case V_121 :
V_39 = 1 ;
break;
case V_122 :
V_38 = 1 ;
break;
case V_123 :
V_26 = F_9 () ;
break;
case V_124 :
if ( ! F_16 ( V_37 , V_18 ) )
goto V_58;
V_51 ++ ;
break;
}
}
V_1 = F_17 () ;
V_2 = F_18 () ;
if ( ! ( V_42 & V_125 ) && ( V_10 || V_9 ) ) {
F_19 ( V_59 , L_5 ) ;
goto V_58;
}
if ( V_42 & V_125 ) {
if ( V_25 && ! V_30 ) {
F_19 ( V_59 , L_6 ) ;
goto V_58;
}
if ( V_30 ) {
if ( ! V_9
&& ( V_9 = F_11 () ) == NULL )
goto V_60;
F_12 ( V_9 , V_30 ) ;
if ( ! V_10 && ( V_10 = F_11 () ) == NULL )
goto V_60;
if ( ! V_25 )
V_25 = V_30 ;
F_12 ( V_10 , V_25 ) ;
}
if ( ! V_9 ) {
F_6 ( V_59 , L_7 ) ;
goto V_58;
}
V_30 = NULL ;
V_25 = NULL ;
V_44 = 1 ;
} else if ( V_42 == V_70 ) {
if ( ! V_31 && ! V_25 ) {
F_6 ( V_59 ,
L_8 ) ;
goto V_58;
}
} else if ( V_42 == V_68 ) {
if ( V_1 == 0 ) {
F_6 ( V_59 , L_9 ) ;
goto V_58;
}
V_44 = 1 ;
} else if ( ! V_42 )
goto V_58;
if ( ! F_20 ( V_32 , NULL , & V_33 , NULL ) ) {
F_6 ( V_59 , L_10 ) ;
goto V_60;
}
if ( V_44 ) {
F_21 ( NULL , ( V_27 != NULL ) ) ;
if ( V_27 != NULL )
F_6 ( V_59 , L_11 ,
F_22 ( V_27 ) ) ;
}
V_43 = 2 ;
if ( ! ( V_42 & V_125 ) )
V_40 &= ~ V_41 ;
if ( ! ( V_42 & V_126 ) ) {
if ( V_40 & V_95 )
V_48 = V_127 ;
}
if ( ! ( V_42 & V_128 ) ) {
if ( V_40 & V_95 )
V_46 = V_127 ;
}
if ( V_42 == V_68 ) {
if ( ! V_19 ) {
#ifndef F_23
V_19 = F_24 () ;
#else
F_6 ( V_59 , L_12 ) ;
goto V_60;
#endif
}
V_12 = F_25 () ;
if ( ! V_12 )
goto V_60;
while ( * V_2 ) {
V_14 = F_26 ( * V_2 , V_50 ,
L_13 ) ;
if ( V_14 == NULL )
goto V_60;
F_27 ( V_12 , V_14 ) ;
V_14 = NULL ;
V_2 ++ ;
}
}
if ( V_24 ) {
if ( ! F_28 ( V_24 , & V_13 , V_50 , NULL ,
L_14 ) ) {
F_29 ( V_59 ) ;
goto V_60;
}
}
if ( V_31 && ( V_42 == V_70 ) ) {
if ( ( V_15 = F_26 ( V_31 , V_50 ,
L_13 ) ) == NULL ) {
F_29 ( V_59 ) ;
goto V_60;
}
}
if ( V_42 == V_70 ) {
if ( ! V_25 )
V_25 = V_31 ;
} else if ( V_42 == V_72 ) {
if ( ! V_25 )
V_25 = V_30 ;
} else
V_25 = NULL ;
if ( V_25 ) {
V_6 = F_30 ( V_25 , V_49 , 0 , V_33 , V_53 , L_15 ) ;
if ( ! V_6 )
goto V_60;
}
V_3 = F_31 ( V_28 , 'r' , V_46 ) ;
if ( V_3 == NULL )
goto V_60;
if ( V_42 & V_128 ) {
if ( V_46 == V_47 )
V_7 = F_32 ( V_3 , & V_5 ) ;
else if ( V_46 == V_50 )
V_7 = F_33 ( V_3 , NULL , NULL , NULL ) ;
else if ( V_46 == V_129 )
V_7 = F_34 ( V_3 , NULL ) ;
else {
F_6 ( V_59 , L_16 ) ;
goto V_60;
}
if ( ! V_7 ) {
F_6 ( V_59 , L_17 ) ;
goto V_60;
}
if ( V_26 ) {
F_35 ( V_5 ) ;
if ( ( V_5 = F_36 ( V_26 , L_18 ) ) == NULL ) {
F_6 ( V_59 , L_19 , V_26 ) ;
goto V_60;
}
}
}
V_4 = F_31 ( V_29 , 'w' , V_48 ) ;
if ( V_4 == NULL )
goto V_60;
if ( V_42 == V_76 ) {
if ( ( V_17 = F_37 ( V_21 , V_22 , V_39 , V_38 ) ) == NULL )
goto V_60;
F_38 ( V_17 , V_130 ) ;
if ( V_51 )
F_39 ( V_17 , V_18 ) ;
}
V_43 = 3 ;
if ( V_42 == V_68 ) {
if ( V_45 )
V_40 |= V_131 ;
V_7 = F_40 ( V_12 , V_3 , V_19 , V_40 ) ;
} else if ( V_42 & V_125 ) {
int V_132 ;
if ( V_42 == V_72 ) {
if ( V_40 & V_41 ) {
if ( V_48 == V_47 )
V_40 |= V_131 ;
} else if ( V_45 )
V_40 |= V_131 ;
V_40 |= V_133 ;
V_7 = F_41 ( NULL , NULL , V_13 , V_3 , V_40 ) ;
if ( ! V_7 )
goto V_60;
if ( V_40 & V_88 ) {
for ( V_132 = 0 ; V_132 < F_42 ( V_13 ) ; V_132 ++ ) {
V_11 * V_134 = F_43 ( V_13 , V_132 ) ;
F_44 ( V_7 , V_134 ) ;
}
}
} else
V_40 |= V_135 ;
for ( V_132 = 0 ; V_132 < F_45 ( V_9 ) ; V_132 ++ ) {
V_30 = F_46 ( V_9 , V_132 ) ;
V_25 = F_46 ( V_10 , V_132 ) ;
V_16 = F_26 ( V_30 , V_50 ,
L_20 ) ;
if ( ! V_16 )
goto V_60;
V_6 = F_30 ( V_25 , V_49 , 0 , V_33 , V_53 , L_15 ) ;
if ( ! V_6 )
goto V_60;
if ( ! F_47 ( V_7 , V_16 , V_6 , V_20 , V_40 ) )
goto V_60;
F_48 ( V_16 ) ;
V_16 = NULL ;
F_49 ( V_6 ) ;
V_6 = NULL ;
}
if ( ( V_42 == V_72 ) && ! ( V_40 & V_131 ) ) {
if ( ! F_50 ( V_7 , V_3 , V_40 ) )
goto V_60;
}
}
if ( ! V_7 ) {
F_6 ( V_59 , L_21 ) ;
goto V_60;
}
V_43 = 4 ;
if ( V_42 == V_70 ) {
if ( ! F_51 ( V_7 , V_6 , V_15 , V_4 , V_40 ) ) {
F_6 ( V_59 , L_22 ) ;
goto V_60;
}
} else if ( V_42 == V_76 ) {
F_2 ( V_11 ) * V_136 ;
if ( F_52 ( V_7 , V_13 , V_17 , V_5 , V_4 , V_40 ) )
F_6 ( V_59 , L_23 ) ;
else {
F_6 ( V_59 , L_24 ) ;
goto V_60;
}
V_136 = F_53 ( V_7 , V_13 , V_40 ) ;
if ( ! F_54 ( V_30 , V_136 ) ) {
F_6 ( V_59 , L_25 , V_30 ) ;
V_43 = 5 ;
goto V_60;
}
F_55 ( V_136 ) ;
} else if ( V_42 == V_78 )
F_56 ( V_4 , V_7 ) ;
else {
if ( V_34 )
F_6 ( V_4 , L_26 , V_34 , V_54 ) ;
if ( V_35 )
F_6 ( V_4 , L_27 , V_35 , V_54 ) ;
if ( V_36 )
F_6 ( V_4 , L_28 , V_36 , V_54 ) ;
if ( V_48 == V_47 ) {
if ( V_42 == V_74 )
V_52 = F_57 ( V_4 , V_7 , V_5 , V_40 ) ;
else
V_52 = F_57 ( V_4 , V_7 , V_3 , V_40 ) ;
} else if ( V_48 == V_50 )
V_52 = F_58 ( V_4 , V_7 , V_3 , V_40 ) ;
else if ( V_48 == V_129 )
V_52 = F_59 ( V_4 , V_7 , V_3 , V_40 ) ;
else {
F_6 ( V_59 , L_29 ) ;
goto V_60;
}
if ( V_52 == 0 ) {
F_6 ( V_59 , L_30 ) ;
V_43 = 3 ;
goto V_60;
}
}
V_43 = 0 ;
V_60:
if ( V_44 )
F_60 ( NULL ) ;
if ( V_43 )
F_29 ( V_59 ) ;
F_61 ( V_12 , F_48 ) ;
F_61 ( V_13 , F_48 ) ;
F_62 ( V_18 ) ;
F_63 ( V_9 ) ;
F_63 ( V_10 ) ;
F_64 ( V_17 ) ;
F_48 ( V_14 ) ;
F_48 ( V_15 ) ;
F_48 ( V_16 ) ;
F_49 ( V_6 ) ;
F_65 ( V_7 ) ;
F_35 ( V_3 ) ;
F_35 ( V_5 ) ;
F_66 ( V_4 ) ;
F_67 ( V_33 ) ;
return ( V_43 ) ;
}
static int V_130 ( int V_137 , T_10 * V_138 )
{
int error ;
error = F_68 ( V_138 ) ;
if ( ( error != V_139 )
&& ( ( error != V_140 ) || ( V_137 != 2 ) ) )
return V_137 ;
F_69 ( V_138 ) ;
return V_137 ;
}
