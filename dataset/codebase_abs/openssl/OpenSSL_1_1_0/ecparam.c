int F_1 ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL , * V_4 = NULL , * V_5 = NULL ;
T_1 * V_6 = NULL , * V_7 = NULL , * V_8 = NULL ;
T_2 * V_9 = NULL , * V_10 = NULL ;
T_3 * V_11 = NULL ;
T_4 V_12 = V_13 ;
char * V_14 = NULL , * V_15 = NULL ;
char * V_16 = NULL , * V_17 = NULL , * V_18 ;
unsigned char * V_19 = NULL ;
T_5 V_20 ;
int V_21 = V_22 , V_23 = 0 ;
int V_24 = V_25 , V_26 = V_25 , V_27 = 0 , V_28 = 0 ;
int V_29 = 1 , V_30 = 0 ;
int V_31 = 0 , V_32 = 0 , V_33 = 0 , V_34 = 0 ;
int V_35 = 0 , V_36 , V_37 = 0 , V_38 = 0 ;
V_18 = F_2 ( V_1 , V_2 , V_39 ) ;
while ( ( V_20 = F_3 () ) != V_40 ) {
switch ( V_20 ) {
case V_40 :
case V_41 :
V_42:
F_4 ( V_43 , L_1 , V_18 ) ;
goto V_44;
case V_45 :
F_5 ( V_39 ) ;
V_29 = 0 ;
goto V_44;
case V_46 :
if ( ! F_6 ( F_7 () , V_47 , & V_24 ) )
goto V_42;
break;
case V_48 :
V_16 = F_7 () ;
break;
case V_49 :
if ( ! F_6 ( F_7 () , V_47 , & V_26 ) )
goto V_42;
break;
case V_50 :
V_17 = F_7 () ;
break;
case V_51 :
V_35 = 1 ;
break;
case V_52 :
V_28 = 1 ;
break;
case V_53 :
V_33 = 1 ;
break;
case V_54 :
V_31 = 1 ;
break;
case V_55 :
V_32 = 1 ;
break;
case V_56 :
V_27 = 1 ;
break;
case V_57 :
V_14 = F_7 () ;
break;
case V_58 :
if ( ! F_8 ( F_7 () , V_59 , & V_34 ) )
goto V_42;
V_12 = V_34 ;
V_34 = 1 ;
break;
case V_60 :
if ( ! F_8 ( F_7 () , V_61 , & V_21 ) )
goto V_42;
V_23 = 1 ;
break;
case V_62 :
V_38 = V_37 = 1 ;
break;
case V_63 :
V_15 = F_7 () ;
V_37 = 1 ;
break;
case V_64 :
( void ) F_9 ( F_7 () , 0 ) ;
break;
}
}
V_1 = F_10 () ;
if ( V_1 != 0 )
goto V_42;
V_30 = V_38 ? 1 : 0 ;
V_9 = F_11 ( V_16 , 'r' , V_24 ) ;
if ( V_9 == NULL )
goto V_44;
V_10 = F_12 ( V_17 , V_26 , V_30 ) ;
if ( V_10 == NULL )
goto V_44;
if ( V_31 ) {
T_6 * V_65 = NULL ;
T_7 V_66 = F_13 ( NULL , 0 ) ;
T_7 V_67 ;
V_65 = F_14 ( ( int ) sizeof( * V_65 ) * V_66 , L_2 ) ;
if ( ! F_13 ( V_65 , V_66 ) ) {
F_15 ( V_65 ) ;
goto V_44;
}
for ( V_67 = 0 ; V_67 < V_66 ; V_67 ++ ) {
const char * V_68 ;
const char * V_69 ;
V_68 = V_65 [ V_67 ] . V_68 ;
V_69 = F_16 ( V_65 [ V_67 ] . V_70 ) ;
if ( V_68 == NULL )
V_68 = L_3 ;
if ( V_69 == NULL )
V_69 = L_4 ;
F_4 ( V_10 , L_5 , V_69 ) ;
F_4 ( V_10 , L_6 , V_68 ) ;
}
F_15 ( V_65 ) ;
V_29 = 0 ;
goto V_44;
}
if ( V_14 != NULL ) {
int V_70 ;
if ( strcmp ( V_14 , L_7 ) == 0 ) {
F_4 ( V_43 , L_8
L_9 ) ;
V_70 = V_71 ;
} else if ( strcmp ( V_14 , L_10 ) == 0 ) {
F_4 ( V_43 , L_11
L_12 ) ;
V_70 = V_72 ;
} else
V_70 = F_17 ( V_14 ) ;
if ( V_70 == 0 )
V_70 = F_18 ( V_14 ) ;
if ( V_70 == 0 ) {
F_4 ( V_43 , L_13 , V_14 ) ;
goto V_44;
}
V_11 = F_19 ( V_70 ) ;
if ( V_11 == NULL ) {
F_4 ( V_43 , L_14 , V_14 ) ;
goto V_44;
}
F_20 ( V_11 , V_21 ) ;
F_21 ( V_11 , V_12 ) ;
} else if ( V_24 == V_73 )
V_11 = F_22 ( V_9 , NULL ) ;
else
V_11 = F_23 ( V_9 , NULL , NULL , NULL ) ;
if ( V_11 == NULL ) {
F_4 ( V_43 , L_15 ) ;
F_24 ( V_43 ) ;
goto V_44;
}
if ( V_34 )
F_21 ( V_11 , V_12 ) ;
if ( V_23 )
F_20 ( V_11 , V_21 ) ;
if ( V_32 ) {
F_25 ( V_11 , NULL , 0 ) ;
}
if ( V_35 ) {
if ( ! F_26 ( V_10 , V_11 , 0 ) )
goto V_44;
}
if ( V_33 ) {
F_4 ( V_43 , L_16 ) ;
if ( ! F_27 ( V_11 , NULL ) ) {
F_4 ( V_43 , L_17 ) ;
F_24 ( V_43 ) ;
goto V_44;
}
F_4 ( V_43 , L_18 ) ;
}
if ( V_28 ) {
T_7 V_74 = 0 , V_75 = 0 ;
const T_8 * V_76 ;
int V_77 , V_78 = 0 ;
const T_9 * V_79 = F_28 ( V_11 ) ;
if ( ( V_6 = F_29 () ) == NULL
|| ( V_7 = F_29 () ) == NULL
|| ( V_8 = F_29 () ) == NULL
|| ( V_3 = F_29 () ) == NULL
|| ( V_4 = F_29 () ) == NULL
|| ( V_5 = F_29 () ) == NULL ) {
perror ( L_19 ) ;
goto V_44;
}
V_77 = ( F_30 ( V_79 ) == V_80 ) ;
if ( ! V_77 ) {
F_4 ( V_43 , L_20 ) ;
goto V_44;
}
if ( ! F_31 ( V_11 , V_6 , V_7 , V_8 , NULL ) )
goto V_44;
if ( ( V_76 = F_32 ( V_11 ) ) == NULL )
goto V_44;
if ( ! F_33 ( V_11 , V_76 ,
F_34 ( V_11 ) ,
V_3 , NULL ) )
goto V_44;
if ( ! F_35 ( V_11 , V_4 , NULL ) )
goto V_44;
if ( ! F_36 ( V_11 , V_5 , NULL ) )
goto V_44;
if ( ! V_6 || ! V_7 || ! V_8 || ! V_3 || ! V_4 || ! V_5 )
goto V_44;
V_78 = F_37 ( V_4 ) ;
if ( ( V_75 = ( T_7 ) F_38 ( V_6 ) ) > V_74 )
V_74 = V_75 ;
if ( ( V_75 = ( T_7 ) F_38 ( V_7 ) ) > V_74 )
V_74 = V_75 ;
if ( ( V_75 = ( T_7 ) F_38 ( V_8 ) ) > V_74 )
V_74 = V_75 ;
if ( ( V_75 = ( T_7 ) F_38 ( V_3 ) ) > V_74 )
V_74 = V_75 ;
if ( ( V_75 = ( T_7 ) F_38 ( V_4 ) ) > V_74 )
V_74 = V_75 ;
if ( ( V_75 = ( T_7 ) F_38 ( V_5 ) ) > V_74 )
V_74 = V_75 ;
V_19 = F_14 ( V_74 , L_21 ) ;
F_4 ( V_10 , L_22 , V_78 ) ;
F_39 ( V_10 , V_6 , L_23 , V_78 , V_19 ) ;
F_39 ( V_10 , V_7 , L_24 , V_78 , V_19 ) ;
F_39 ( V_10 , V_8 , L_25 , V_78 , V_19 ) ;
F_39 ( V_10 , V_3 , L_26 , V_78 , V_19 ) ;
F_39 ( V_10 , V_4 , L_27 , V_78 , V_19 ) ;
F_39 ( V_10 , V_5 , L_28 , V_78 , V_19 ) ;
F_4 ( V_10 , L_29
L_30
L_31
L_32
L_33
L_34
L_35 ) ;
F_4 ( V_10 , L_36
L_37 , V_78 , V_78 ) ;
F_4 ( V_10 , L_38
L_37 , V_78 , V_78 ) ;
F_4 ( V_10 , L_39
L_37 , V_78 , V_78 ) ;
F_4 ( V_10 , L_40
L_37
L_35 ) ;
F_4 ( V_10 , L_41 ) ;
F_4 ( V_10 , L_42
L_37 , V_78 , V_78 ) ;
F_4 ( V_10 , L_43 ) ;
F_4 ( V_10 , L_44
L_37 ) ;
F_4 ( V_10 , L_45
L_37 , V_78 , V_78 ) ;
F_4 ( V_10 , L_46
L_37 , V_78 , V_78 ) ;
F_4 ( V_10 , L_47
L_37
L_48
L_35 ) ;
F_4 ( V_10 , L_49
L_50
L_51
L_52
L_53
L_54
L_55
L_56
L_57
L_58
L_59 ) ;
}
if ( ! V_27 ) {
if ( V_26 == V_73 )
V_36 = F_40 ( V_10 , V_11 ) ;
else
V_36 = F_41 ( V_10 , V_11 ) ;
if ( ! V_36 ) {
F_4 ( V_43 , L_60
L_61 ) ;
F_24 ( V_43 ) ;
goto V_44;
}
}
if ( V_37 ) {
F_42 ( NULL , ( V_15 != NULL ) ) ;
if ( V_15 != NULL )
F_4 ( V_43 , L_62 ,
F_43 ( V_15 ) ) ;
}
if ( V_38 ) {
T_10 * V_81 = F_44 () ;
if ( V_81 == NULL )
goto V_44;
assert ( V_37 ) ;
if ( F_45 ( V_81 , V_11 ) == 0 ) {
F_4 ( V_43 , L_63 ) ;
F_46 ( V_81 ) ;
F_24 ( V_43 ) ;
goto V_44;
}
if ( ! F_47 ( V_81 ) ) {
F_4 ( V_43 , L_64 ) ;
F_46 ( V_81 ) ;
F_24 ( V_43 ) ;
goto V_44;
}
assert ( V_30 ) ;
if ( V_26 == V_73 )
V_36 = F_48 ( V_10 , V_81 ) ;
else
V_36 = F_49 ( V_10 , V_81 , NULL ,
NULL , 0 , NULL , NULL ) ;
F_46 ( V_81 ) ;
}
if ( V_37 )
F_50 ( NULL ) ;
V_29 = 0 ;
V_44:
F_51 ( V_6 ) ;
F_51 ( V_7 ) ;
F_51 ( V_8 ) ;
F_51 ( V_3 ) ;
F_51 ( V_4 ) ;
F_51 ( V_5 ) ;
F_15 ( V_19 ) ;
F_52 ( V_9 ) ;
F_53 ( V_10 ) ;
F_54 ( V_11 ) ;
return ( V_29 ) ;
}
