int F_1 ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL , * V_4 , * V_5 = NULL , * V_6 = NULL ;
T_2 * V_7 = NULL , * V_8 = NULL ;
T_3 * V_9 = NULL ;
F_2 ( V_10 ) * V_11 = NULL , * V_12 = NULL ;
char * V_13 = NULL ;
char * V_14 = NULL ;
char * V_15 = NULL , * V_16 = NULL ;
const T_4 * V_17 = NULL , * V_18 ;
const char * V_19 = NULL , * V_20 = NULL , * V_21 = NULL ;
const char * V_22 = NULL , * V_23 = NULL ;
T_5 V_24 ;
int V_25 = 0 , V_26 = 0 , V_27 = V_28 , V_29 = 0 ;
int V_30 , V_31 = 1 , V_32 = - 1 , V_33 = 0 , V_34 = 0 ;
unsigned char * V_35 = NULL , * V_36 = NULL ;
int V_37 = 0 ;
V_21 = F_3 ( V_2 [ 0 ] ) ;
V_35 = F_4 ( V_38 , L_1 ) ;
V_17 = F_5 ( V_21 ) ;
V_21 = F_6 ( V_1 , V_2 , V_39 ) ;
while ( ( V_24 = F_7 () ) != V_40 ) {
switch ( V_24 ) {
case V_40 :
case V_41 :
V_42:
F_8 ( V_43 , L_2 , V_21 ) ;
goto V_44;
case V_45 :
F_9 ( V_39 ) ;
V_31 = 0 ;
goto V_44;
case V_46 :
V_25 = 1 ;
break;
case V_47 :
V_25 = 2 ;
break;
case V_48 :
V_23 = F_10 () ;
break;
case V_49 :
V_19 = F_10 () ;
break;
case V_50 :
V_20 = F_10 () ;
break;
case V_51 :
V_15 = F_10 () ;
break;
case V_52 :
V_20 = F_10 () ;
V_33 = V_34 = 1 ;
break;
case V_53 :
V_20 = F_10 () ;
V_34 = 1 ;
break;
case V_54 :
V_22 = F_10 () ;
break;
case V_55 :
if ( ! F_11 ( F_10 () , V_56 , & V_27 ) )
goto V_42;
break;
case V_57 :
V_7 = F_12 ( F_10 () , 0 ) ;
break;
case V_58 :
V_37 = 1 ;
break;
case V_59 :
V_32 = 0 ;
break;
case V_60 :
V_32 = 1 ;
break;
case V_61 :
V_26 = 1 ;
break;
case V_62 :
V_13 = L_3 ;
break;
case V_63 :
V_13 = F_10 () ;
break;
case V_64 :
V_14 = F_10 () ;
break;
case V_65 :
if ( ! V_11 )
V_11 = F_13 () ;
if ( ! V_11 || ! F_14 ( V_11 , F_10 () ) )
goto V_42;
break;
case V_66 :
if ( ! V_12 )
V_12 = F_13 () ;
if ( ! V_12 || ! F_14 ( V_12 , F_10 () ) )
goto V_42;
break;
case V_67 :
if ( ! F_15 ( F_16 () , & V_18 ) )
goto V_42;
V_17 = V_18 ;
break;
}
}
V_1 = F_17 () ;
V_2 = F_18 () ;
if ( V_34 && ! V_22 ) {
F_8 ( V_43 ,
L_4 ) ;
goto V_44;
}
if ( V_37 )
V_8 = V_7 ;
V_3 = F_19 ( F_20 () ) ;
V_5 = F_19 ( F_21 () ) ;
if ( ( V_3 == NULL ) || ( V_5 == NULL ) ) {
F_22 ( V_43 ) ;
goto V_44;
}
if ( V_26 ) {
F_23 ( V_3 , V_68 ) ;
F_24 ( V_3 , ( char * ) V_43 ) ;
}
if ( ! F_25 ( V_15 , NULL , & V_16 , NULL ) ) {
F_8 ( V_43 , L_5 ) ;
goto V_44;
}
if ( V_32 == - 1 ) {
if ( V_20 )
V_32 = 1 ;
else
V_32 = 0 ;
}
if ( V_23 )
F_26 ( V_23 , 0 ) ;
V_6 = F_27 ( V_19 , 'w' , V_32 ? V_69 : V_70 ) ;
if ( V_6 == NULL )
goto V_44;
if ( ( ! ! V_14 + ! ! V_20 + ! ! V_13 ) > 1 ) {
F_8 ( V_43 , L_6 ) ;
goto V_44;
}
if ( V_20 ) {
if ( V_33 )
V_9 = F_28 ( V_20 , V_27 , 0 , NULL , V_7 , L_7 ) ;
else
V_9 = F_29 ( V_20 , V_27 , 0 , V_16 , V_7 , L_7 ) ;
if ( ! V_9 ) {
goto V_44;
}
}
if ( V_14 ) {
T_6 * V_71 = NULL ;
int V_72 = 0 ;
if ( ! F_30 ( & V_71 , V_14 , V_8 , 0 ) )
goto V_73;
if ( V_12 ) {
char * V_74 ;
for ( V_30 = 0 ; V_30 < F_31 ( V_12 ) ; V_30 ++ ) {
V_74 = F_32 ( V_12 , V_30 ) ;
if ( F_33 ( V_71 , V_74 ) <= 0 ) {
F_8 ( V_43 ,
L_8 , V_74 ) ;
F_22 ( V_43 ) ;
goto V_73;
}
}
}
if ( F_34 ( V_71 , & V_9 ) <= 0 ) {
F_35 ( V_43 , L_9 ) ;
F_22 ( V_43 ) ;
goto V_73;
}
V_72 = 1 ;
V_73:
F_36 ( V_71 ) ;
if ( V_72 == 0 )
goto V_44;
}
if ( V_13 ) {
V_9 = F_37 ( V_75 , V_8 ,
( unsigned char * ) V_13 , - 1 ) ;
if ( ! V_9 )
goto V_44;
}
if ( V_9 ) {
T_7 * V_76 = NULL ;
T_6 * V_77 = NULL ;
int V_72 ;
if ( ! F_38 ( V_5 , & V_76 ) ) {
F_8 ( V_43 , L_10 ) ;
F_22 ( V_43 ) ;
goto V_44;
}
if ( V_34 )
V_72 = F_39 ( V_76 , & V_77 , V_17 , V_8 , V_9 ) ;
else
V_72 = F_40 ( V_76 , & V_77 , V_17 , V_8 , V_9 ) ;
if ( ! V_72 ) {
F_8 ( V_43 , L_11 ) ;
F_22 ( V_43 ) ;
goto V_44;
}
if ( V_11 ) {
char * V_78 ;
for ( V_30 = 0 ; V_30 < F_31 ( V_11 ) ; V_30 ++ ) {
V_78 = F_32 ( V_11 , V_30 ) ;
if ( F_33 ( V_77 , V_78 ) <= 0 ) {
F_8 ( V_43 , L_12 , V_78 ) ;
F_22 ( V_43 ) ;
goto V_44;
}
}
}
}
else {
T_7 * V_76 = NULL ;
if ( ! F_38 ( V_5 , & V_76 ) ) {
F_8 ( V_43 , L_10 ) ;
F_22 ( V_43 ) ;
goto V_44;
}
if ( V_17 == NULL )
V_17 = F_41 () ;
if ( ! F_42 ( V_76 , V_17 , V_8 ) ) {
F_8 ( V_43 , L_13 ) ;
F_22 ( V_43 ) ;
goto V_44;
}
}
if ( V_22 && V_9 ) {
T_1 * V_79 = F_43 ( V_22 , L_14 ) ;
if ( ! V_79 ) {
F_8 ( V_43 , L_15 , V_22 ) ;
F_22 ( V_43 ) ;
goto V_44;
}
V_29 = F_44 ( V_9 ) ;
V_36 = F_4 ( V_29 , L_16 ) ;
V_29 = F_45 ( V_79 , V_36 , V_29 ) ;
F_46 ( V_79 ) ;
if ( V_29 <= 0 ) {
F_8 ( V_43 , L_17 , V_22 ) ;
F_22 ( V_43 ) ;
goto V_44;
}
}
V_4 = F_47 ( V_5 , V_3 ) ;
if ( V_17 == NULL ) {
T_7 * V_80 ;
F_38 ( V_5 , & V_80 ) ;
V_17 = F_48 ( V_80 ) ;
}
if ( V_1 == 0 ) {
F_49 ( V_3 , V_81 , V_82 ) ;
V_31 = F_50 ( V_6 , V_35 , V_4 , V_25 , V_32 , V_9 , V_36 ,
V_29 , NULL , NULL , L_18 ) ;
} else {
const char * V_83 = NULL , * V_84 = NULL ;
if ( ! V_32 ) {
if ( V_9 ) {
const T_8 * V_85 ;
V_85 = F_51 ( V_9 ) ;
if ( V_85 )
F_52 ( NULL , NULL ,
NULL , NULL , & V_84 , V_85 ) ;
}
if ( V_17 )
V_83 = F_53 ( V_17 ) ;
}
V_31 = 0 ;
for ( V_30 = 0 ; V_30 < V_1 ; V_30 ++ ) {
int V_72 ;
if ( F_54 ( V_3 , V_2 [ V_30 ] ) <= 0 ) {
perror ( V_2 [ V_30 ] ) ;
V_31 ++ ;
continue;
} else
V_72 = F_50 ( V_6 , V_35 , V_4 , V_25 , V_32 , V_9 , V_36 ,
V_29 , V_84 , V_83 , V_2 [ V_30 ] ) ;
if ( V_72 )
V_31 = V_72 ;
( void ) F_55 ( V_5 ) ;
}
}
V_44:
F_56 ( V_35 , V_38 ) ;
F_46 ( V_3 ) ;
F_57 ( V_16 ) ;
F_58 ( V_6 ) ;
F_59 ( V_9 ) ;
F_60 ( V_11 ) ;
F_60 ( V_12 ) ;
F_57 ( V_36 ) ;
F_46 ( V_5 ) ;
return ( V_31 ) ;
}
int F_50 ( T_1 * V_6 , unsigned char * V_35 , T_1 * V_86 , int V_87 , int V_88 ,
T_3 * V_89 , unsigned char * V_90 , int V_29 ,
const char * V_84 , const char * V_83 ,
const char * V_91 )
{
T_9 V_92 ;
int V_30 ;
for (; ; ) {
V_30 = F_45 ( V_86 , ( char * ) V_35 , V_38 ) ;
if ( V_30 < 0 ) {
F_8 ( V_43 , L_19 , V_91 ) ;
F_22 ( V_43 ) ;
return 1 ;
}
if ( V_30 == 0 )
break;
}
if ( V_90 ) {
T_7 * V_93 ;
F_38 ( V_86 , & V_93 ) ;
V_30 = F_61 ( V_93 , V_90 , ( unsigned int ) V_29 ) ;
if ( V_30 > 0 )
F_8 ( V_6 , L_20 ) ;
else if ( V_30 == 0 ) {
F_8 ( V_6 , L_21 ) ;
return 1 ;
} else {
F_8 ( V_43 , L_22 ) ;
F_22 ( V_43 ) ;
return 1 ;
}
return 0 ;
}
if ( V_89 ) {
T_7 * V_93 ;
F_38 ( V_86 , & V_93 ) ;
V_92 = V_38 ;
if ( ! F_62 ( V_93 , V_35 , & V_92 ) ) {
F_8 ( V_43 , L_23 ) ;
F_22 ( V_43 ) ;
return 1 ;
}
} else {
V_92 = F_63 ( V_86 , ( char * ) V_35 , V_38 ) ;
if ( ( int ) V_92 < 0 ) {
F_22 ( V_43 ) ;
return 1 ;
}
}
if ( V_88 )
F_64 ( V_6 , V_35 , V_92 ) ;
else if ( V_87 == 2 ) {
for ( V_30 = 0 ; V_30 < ( int ) V_92 ; V_30 ++ )
F_8 ( V_6 , L_24 , V_35 [ V_30 ] ) ;
F_8 ( V_6 , L_25 , V_91 ) ;
} else {
if ( V_84 ) {
F_35 ( V_6 , V_84 ) ;
if ( V_83 )
F_8 ( V_6 , L_26 , V_83 ) ;
F_8 ( V_6 , L_27 , V_91 ) ;
} else if ( V_83 )
F_8 ( V_6 , L_28 , V_83 , V_91 ) ;
else
F_8 ( V_6 , L_27 , V_91 ) ;
for ( V_30 = 0 ; V_30 < ( int ) V_92 ; V_30 ++ ) {
if ( V_87 && ( V_30 != 0 ) )
F_8 ( V_6 , L_29 ) ;
F_8 ( V_6 , L_24 , V_35 [ V_30 ] ) ;
}
F_8 ( V_6 , L_30 ) ;
}
return 0 ;
}
