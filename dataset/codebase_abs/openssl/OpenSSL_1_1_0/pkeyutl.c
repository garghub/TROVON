int F_1 ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL , * V_4 = NULL ;
T_2 * V_5 = NULL ;
T_3 * V_6 = NULL ;
char * V_7 = NULL , * V_8 = NULL , * V_9 = NULL , * V_10 = NULL ;
char V_11 = 0 , V_12 = 0 , V_13 = 0 , * V_14 ;
unsigned char * V_15 = NULL , * V_16 = NULL , * V_17 = NULL ;
T_4 V_18 ;
int V_19 = 0 , V_20 = - 1 , V_21 = V_22 , V_23 =
V_22 ;
int V_24 = - 1 , V_25 = V_26 , V_27 = V_28 ;
int V_29 = 0 ;
int V_30 = 1 , V_31 = - 1 ;
T_5 V_32 ;
const char * V_33 = NULL ;
const char * V_34 = NULL ;
const char * V_35 = NULL ;
int V_36 = 0 ;
F_2 ( V_37 ) * V_38 = NULL ;
V_14 = F_3 ( V_1 , V_2 , V_39 ) ;
while ( ( V_18 = F_4 () ) != V_40 ) {
switch ( V_18 ) {
case V_40 :
case V_41 :
V_42:
F_5 ( V_43 , L_1 , V_14 ) ;
goto V_44;
case V_45 :
F_6 ( V_39 ) ;
V_30 = 0 ;
goto V_44;
case V_46 :
V_7 = F_7 () ;
break;
case V_47 :
V_8 = F_7 () ;
break;
case V_48 :
V_9 = F_7 () ;
break;
case V_49 :
V_29 = 1 ;
break;
case V_50 :
V_33 = F_7 () ;
break;
case V_51 :
V_34 = F_7 () ;
break;
case V_52 :
V_10 = F_7 () ;
break;
case V_53 :
if ( ! F_8 ( F_7 () , V_54 , & V_23 ) )
goto V_42;
break;
case V_55 :
if ( ! F_8 ( F_7 () , V_54 , & V_21 ) )
goto V_42;
break;
case V_56 :
V_5 = F_9 ( F_7 () , 0 ) ;
break;
case V_57 :
V_27 = V_58 ;
break;
case V_59 :
V_27 = V_60 ;
break;
case V_61 :
V_12 = 1 ;
break;
case V_62 :
V_11 = 1 ;
break;
case V_63 :
V_25 = V_26 ;
break;
case V_64 :
V_25 = V_65 ;
break;
case V_66 :
V_25 = V_67 ;
break;
case V_68 :
V_25 = V_69 ;
break;
case V_70 :
V_25 = V_71 ;
break;
case V_72 :
V_25 = V_73 ;
break;
case V_74 :
V_25 = V_73 ;
V_27 = V_75 ;
V_35 = F_7 () ;
break;
case V_76 :
V_36 = atoi ( F_7 () ) ;
break;
case V_77 :
V_13 = 1 ;
break;
case V_78 :
if ( ( V_38 == NULL &&
( V_38 = F_10 () ) == NULL ) ||
F_11 ( V_38 , F_7 () ) == 0 ) {
F_12 ( V_43 , L_2 ) ;
goto V_44;
}
break;
}
}
V_1 = F_13 () ;
if ( V_1 != 0 )
goto V_42;
if ( V_35 != NULL ) {
if ( V_36 == 0 )
goto V_42;
} else if ( ( V_33 == NULL )
|| ( V_34 != NULL && V_25 != V_73 ) ) {
goto V_42;
}
V_6 = F_14 ( V_35 , & V_24 , V_33 , V_21 , V_27 ,
V_10 , V_25 , V_5 , V_29 ) ;
if ( V_6 == NULL ) {
F_5 ( V_43 , L_3 , V_14 ) ;
F_15 ( V_43 ) ;
goto V_44;
}
if ( V_34 != NULL && ! F_16 ( V_6 , V_23 , V_34 , V_5 ) ) {
F_5 ( V_43 , L_4 , V_14 ) ;
F_15 ( V_43 ) ;
goto V_44;
}
if ( V_38 != NULL ) {
int V_79 = F_17 ( V_38 ) ;
int V_80 ;
for ( V_80 = 0 ; V_80 < V_79 ; ++ V_80 ) {
const char * V_81 = F_18 ( V_38 , V_80 ) ;
if ( F_19 ( V_6 , V_81 ) <= 0 ) {
F_5 ( V_43 , L_5 , V_14 ) ;
F_15 ( V_43 ) ;
goto V_44;
}
}
}
if ( V_9 && ( V_25 != V_65 ) ) {
F_5 ( V_43 ,
L_6 , V_14 ) ;
goto V_44;
}
if ( ! V_9 && ( V_25 == V_65 ) ) {
F_5 ( V_43 ,
L_7 , V_14 ) ;
goto V_44;
}
F_20 ( NULL , 0 ) ;
if ( V_25 != V_73 ) {
V_3 = F_21 ( V_7 , 'r' , V_82 ) ;
if ( V_3 == NULL )
goto V_44;
}
V_4 = F_21 ( V_8 , 'w' , V_82 ) ;
if ( V_4 == NULL )
goto V_44;
if ( V_9 ) {
T_1 * V_83 = F_22 ( V_9 , L_8 ) ;
if ( ! V_83 ) {
F_5 ( V_43 , L_9 , V_9 ) ;
goto V_44;
}
V_20 = F_23 ( & V_17 , V_24 * 10 , V_83 ) ;
F_24 ( V_83 ) ;
if ( V_20 < 0 ) {
F_5 ( V_43 , L_10 ) ;
goto V_44;
}
}
if ( V_3 ) {
V_19 = F_23 ( & V_15 , V_24 * 10 , V_3 ) ;
if ( V_19 < 0 ) {
F_5 ( V_43 , L_11 ) ;
exit ( 1 ) ;
}
if ( V_13 ) {
T_5 V_80 ;
unsigned char V_84 ;
T_5 V_85 = ( T_5 ) V_19 ;
for ( V_80 = 0 ; V_80 < V_85 / 2 ; V_80 ++ ) {
V_84 = V_15 [ V_80 ] ;
V_15 [ V_80 ] = V_15 [ V_85 - 1 - V_80 ] ;
V_15 [ V_85 - 1 - V_80 ] = V_84 ;
}
}
}
if ( V_25 == V_65 ) {
V_31 = F_25 ( V_6 , V_17 , ( T_5 ) V_20 ,
V_15 , ( T_5 ) V_19 ) ;
if ( V_31 == 1 ) {
F_12 ( V_4 , L_12 ) ;
V_30 = 0 ;
} else
F_12 ( V_4 , L_13 ) ;
goto V_44;
}
if ( V_36 != 0 ) {
V_32 = V_36 ;
V_31 = 1 ;
} else {
V_31 = F_26 ( V_6 , V_25 , NULL , ( T_5 * ) & V_32 ,
V_15 , ( T_5 ) V_19 ) ;
}
if ( V_31 > 0 && V_32 != 0 ) {
V_16 = F_27 ( V_32 , L_14 ) ;
V_31 = F_26 ( V_6 , V_25 ,
V_16 , ( T_5 * ) & V_32 ,
V_15 , ( T_5 ) V_19 ) ;
}
if ( V_31 <= 0 ) {
F_12 ( V_43 , L_15 ) ;
F_15 ( V_43 ) ;
goto V_44;
}
V_30 = 0 ;
if ( V_12 ) {
if ( ! F_28 ( V_4 , V_16 , V_32 , 1 , - 1 ) )
F_15 ( V_43 ) ;
} else if ( V_11 )
F_29 ( V_4 , ( char * ) V_16 , V_32 ) ;
else
F_30 ( V_4 , V_16 , V_32 ) ;
V_44:
F_31 ( V_6 ) ;
F_24 ( V_3 ) ;
F_32 ( V_4 ) ;
F_33 ( V_15 ) ;
F_33 ( V_16 ) ;
F_33 ( V_17 ) ;
F_34 ( V_38 ) ;
return V_30 ;
}
static T_3 * F_14 ( const char * V_35 , int * V_86 ,
const char * V_87 , int V_21 , int V_27 ,
char * V_10 , int V_25 , T_2 * V_5 ,
const int V_29 )
{
T_6 * V_88 = NULL ;
T_3 * V_6 = NULL ;
T_2 * V_89 = NULL ;
char * V_90 = NULL ;
int V_31 = - 1 ;
T_7 * V_91 ;
if ( ( ( V_25 == V_26 ) || ( V_25 == V_71 )
|| ( V_25 == V_73 ) )
&& ( V_27 != V_28 && V_35 == NULL ) ) {
F_5 ( V_43 , L_16 ) ;
goto V_44;
}
if ( ! F_35 ( V_10 , NULL , & V_90 , NULL ) ) {
F_5 ( V_43 , L_17 ) ;
goto V_44;
}
switch ( V_27 ) {
case V_28 :
V_88 = F_36 ( V_87 , V_21 , 0 , V_90 , V_5 , L_18 ) ;
break;
case V_58 :
V_88 = F_37 ( V_87 , V_21 , 0 , NULL , V_5 , L_19 ) ;
break;
case V_60 :
V_91 = F_38 ( V_87 , V_21 , L_20 ) ;
if ( V_91 ) {
V_88 = F_39 ( V_91 ) ;
F_40 ( V_91 ) ;
}
break;
case V_75 :
break;
}
#ifndef F_41
if ( V_29 )
V_89 = V_5 ;
#endif
if ( V_35 ) {
int V_92 = F_42 ( V_35 ) ;
if ( V_92 == V_93 )
goto V_44;
V_6 = F_43 ( V_92 , V_89 ) ;
} else {
if ( V_88 == NULL )
goto V_44;
* V_86 = F_44 ( V_88 ) ;
V_6 = F_45 ( V_88 , V_89 ) ;
F_46 ( V_88 ) ;
}
if ( V_6 == NULL )
goto V_44;
switch ( V_25 ) {
case V_26 :
V_31 = F_47 ( V_6 ) ;
break;
case V_65 :
V_31 = F_48 ( V_6 ) ;
break;
case V_67 :
V_31 = F_49 ( V_6 ) ;
break;
case V_69 :
V_31 = F_50 ( V_6 ) ;
break;
case V_71 :
V_31 = F_51 ( V_6 ) ;
break;
case V_73 :
V_31 = F_52 ( V_6 ) ;
break;
}
if ( V_31 <= 0 ) {
F_31 ( V_6 ) ;
V_6 = NULL ;
}
V_44:
F_33 ( V_90 ) ;
return V_6 ;
}
static int F_16 ( T_3 * V_6 , int V_23 , const char * V_94 ,
T_2 * V_5 )
{
T_6 * V_95 = NULL ;
T_2 * V_96 = NULL ;
int V_30 ;
if ( V_23 == V_97 )
V_96 = V_5 ;
V_95 = F_37 ( V_94 , V_23 , 0 , NULL , V_96 , L_21 ) ;
if ( ! V_95 ) {
F_5 ( V_43 , L_22 , V_94 ) ;
F_15 ( V_43 ) ;
return 0 ;
}
V_30 = F_53 ( V_6 , V_95 ) ;
F_46 ( V_95 ) ;
if ( V_30 <= 0 )
F_15 ( V_43 ) ;
return V_30 ;
}
static int F_26 ( T_3 * V_6 , int V_25 ,
unsigned char * V_4 , T_5 * V_98 ,
const unsigned char * V_3 , T_5 V_99 )
{
int V_31 = 0 ;
switch ( V_25 ) {
case V_67 :
V_31 = F_54 ( V_6 , V_4 , V_98 , V_3 , V_99 ) ;
break;
case V_26 :
V_31 = F_55 ( V_6 , V_4 , V_98 , V_3 , V_99 ) ;
break;
case V_69 :
V_31 = F_56 ( V_6 , V_4 , V_98 , V_3 , V_99 ) ;
break;
case V_71 :
V_31 = F_57 ( V_6 , V_4 , V_98 , V_3 , V_99 ) ;
break;
case V_73 :
V_31 = F_58 ( V_6 , V_4 , V_98 ) ;
break;
}
return V_31 ;
}
