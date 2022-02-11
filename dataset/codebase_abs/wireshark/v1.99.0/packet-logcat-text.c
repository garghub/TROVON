static int F_1 ( const T_1 * V_1 , const T_1 * V_2 , T_2 * V_3 ,
T_3 * V_4 , T_4 V_5 , T_5 * T_6 V_6 ) {
int V_7 ;
T_1 * V_8 = F_2 ( V_1 + V_5 , - 1 , V_2 ) ;
int V_9 = ( int ) ( V_8 - V_1 ) ;
switch ( * V_8 ) {
case 'I' :
V_7 = 4 ;
break;
case 'V' :
V_7 = 2 ;
break;
case 'D' :
V_7 = 3 ;
break;
case 'W' :
V_7 = 5 ;
break;
case 'E' :
V_7 = 6 ;
break;
case 'F' :
V_7 = 7 ;
break;
default:
V_7 = 0 ;
}
F_3 ( V_4 , V_10 , V_3 , V_9 , 1 , V_7 ) ;
return V_9 + 1 ;
}
static int F_4 ( const T_1 * V_1 , const T_1 * V_2 , T_2 * V_3 ,
T_3 * V_4 , T_4 V_5 , T_5 * T_6 ) {
T_1 * V_8 = F_2 ( V_1 + V_5 , - 1 , V_2 ) ;
int V_9 = ( int ) ( V_8 - V_1 ) ;
T_7 * V_11 = F_5 ( F_6 () , V_2 ) ;
T_4 V_12 = ( T_4 ) strlen ( V_2 ) ;
F_7 ( V_4 , V_13 , V_3 , V_9 , V_12 ,
V_2 ) ;
F_8 ( & T_6 -> V_14 , V_15 , V_12 + 1 , V_11 ) ;
F_8 ( & T_6 -> V_16 , V_15 , sizeof( V_17 ) , V_17 ) ;
return V_9 + V_12 ;
}
static int F_9 ( const T_1 * V_1 , const T_1 * V_2 , T_2 * V_3 ,
T_3 * V_4 , T_4 V_18 , T_4 V_5 ) {
T_1 * V_8 = F_2 ( V_1 + V_5 , - 1 , V_2 ) ;
int V_9 = ( int ) ( V_8 - V_1 ) ;
F_3 ( V_4 , V_18 , V_3 , V_9 , ( T_4 ) strlen ( V_2 ) ,
( V_19 ) F_10 ( V_2 , NULL , 10 ) ) ;
return V_9 + ( int ) strlen ( V_2 ) ;
}
static int F_11 ( const T_1 * V_1 , const T_1 * V_2 , T_2 * V_3 ,
T_3 * V_4 , T_4 V_5 , T_5 * T_6 V_6 ) {
return F_9 ( V_1 , V_2 , V_3 , V_4 , V_20 , V_5 ) ;
}
static int F_12 ( const T_1 * V_1 , const T_1 * V_2 , T_2 * V_3 ,
T_3 * V_4 , T_4 V_5 , T_5 * T_6 V_6 ) {
return F_9 ( V_1 , V_2 , V_3 , V_4 , V_21 , V_5 ) ;
}
static int F_13 ( const T_1 * V_1 , const T_1 * V_2 , T_2 * V_3 ,
T_3 * V_4 , T_4 V_5 , T_5 * T_6 ) {
T_1 * V_8 = F_2 ( V_1 + V_5 , - 1 , V_2 ) ;
int V_9 = ( int ) ( V_8 - V_1 ) ;
F_7 ( V_4 , V_22 , V_3 , V_9 ,
( int ) strlen ( V_2 ) , V_2 ) ;
F_14 ( T_6 -> V_23 , V_24 , V_2 ) ;
return V_9 + ( int ) strlen ( V_2 ) ;
}
static int F_15 ( const T_1 * V_1 , const T_1 * V_2 , T_2 * V_3 ,
T_3 * V_4 , T_4 V_5 , T_5 * T_6 ) {
T_4 V_9 ;
T_1 * V_8 ;
T_4 V_25 ;
struct V_26 V_27 ;
T_8 V_28 ;
T_9 V_29 ;
V_8 = F_2 ( V_1 + V_5 , - 1 , V_2 ) ;
V_9 = ( int ) ( V_8 - V_1 ) ;
if ( 6 == sscanf ( V_2 , L_1 , & V_27 . V_30 , & V_27 . V_31 ,
& V_27 . V_32 , & V_27 . V_33 , & V_27 . V_34 , & V_25 ) ) {
V_27 . V_35 = 70 ;
V_27 . V_30 -= 1 ;
V_28 = mktime ( & V_27 ) ;
V_29 . V_36 = V_28 ;
V_29 . V_37 = ( int ) ( V_25 * 1e6 ) ;
F_16 ( V_4 , V_38 , V_3 , V_9 ,
( int ) strlen ( V_2 ) , & V_29 ) ;
} else {
F_17 ( V_4 , T_6 , & V_39 , V_3 , V_9 , - 1 ) ;
}
return V_9 + ( int ) strlen ( V_2 ) ;
}
static int F_18 ( T_2 * V_3 , T_3 * V_40 , T_5 * T_6 ,
const T_10 * V_41 ) {
T_1 * * V_42 ;
T_11 V_43 ;
T_1 * V_1 = F_19 ( F_6 () , V_3 , 0 , F_20 ( V_3 ) ,
V_44 ) ;
T_12 * V_45 = F_21 ( V_40 , V_46 , V_3 , 0 , - 1 , V_47 ) ;
T_3 * V_4 = F_22 ( V_45 , V_48 ) ;
T_4 V_9 = 0 ;
F_23 ( T_6 -> V_23 , V_49 , V_17 ) ;
if ( ! F_24 ( V_50 , V_1 , V_51 , NULL ) ) {
V_42 = F_25 ( * V_41 -> V_52 , V_1 , V_51 ) ;
if ( NULL == V_42 ) return 0 ;
if ( F_26 ( V_42 ) != V_41 -> V_53 + 2 ) {
F_17 ( V_4 , T_6 , & V_54 , V_3 , V_9 , - 1 ) ;
F_27 ( V_42 ) ;
return 0 ;
}
for ( V_43 = 0 ; V_43 < V_41 -> V_53 ; ++ V_43 ) {
V_9 = ( (* V_41 -> V_55 [ V_43 ])( V_1 , V_42 [ V_43 + 1 ] , V_3 , V_4 , V_9 , T_6 ) ) ;
}
} else {
V_42 = F_25 ( V_50 , V_1 , V_51 ) ;
if ( NULL == V_42 ) return 0 ;
V_9 = F_13 ( V_1 , V_42 [ 1 ] , V_3 , V_4 , 0 , T_6 ) ;
}
F_27 ( V_42 ) ;
return V_9 ;
}
static int F_28 ( T_2 * V_3 , T_5 * T_6 , T_3 * V_40 ,
void * T_13 V_6 ) {
static const T_14 V_55 [] = { F_1 , F_4 , F_11 , F_13 } ;
T_10 V_41 = { & V_56 , V_55 , F_29 (getters) } ;
return F_18 ( V_3 , V_40 , T_6 , & V_41 ) ;
}
static int F_30 ( T_2 * V_3 , T_5 * T_6 , T_3 * V_40 ,
void * T_13 V_6 ) {
static const T_14 V_55 [] = { F_1 , F_4 , F_13 } ;
T_10 V_41 = { & V_57 , V_55 , F_29 (getters) } ;
return F_18 ( V_3 , V_40 , T_6 , & V_41 ) ;
}
static int F_31 ( T_2 * V_3 , T_5 * T_6 , T_3 * V_40 ,
void * T_13 V_6 ) {
static const T_14 V_55 [] = { F_1 , F_11 , F_13 } ;
T_10 V_41 = { & V_58 , V_55 , F_29 (getters) } ;
F_8 ( & T_6 -> V_16 , V_15 , 0 , L_2 ) ;
F_8 ( & T_6 -> V_14 , V_15 , 0 , L_2 ) ;
return F_18 ( V_3 , V_40 , T_6 , & V_41 ) ;
}
static int F_32 ( T_2 * V_3 , T_5 * T_6 , T_3 * V_40 ,
void * T_13 V_6 ) {
static const T_14 V_55 [] = { F_15 , F_1 , F_4 , F_11 , F_13 } ;
T_10 V_41 = { & V_59 , V_55 , F_29 (getters) } ;
return F_18 ( V_3 , V_40 , T_6 , & V_41 ) ;
}
static int F_33 ( T_2 * V_3 , T_5 * T_6 , T_3 * V_40 ,
void * T_13 V_6 ) {
static const T_14 V_55 [] = { F_1 , F_11 , F_12 , F_13 } ;
T_10 V_41 = { & V_60 , V_55 , F_29 (getters) } ;
F_8 ( & T_6 -> V_16 , V_15 , 0 , L_2 ) ;
F_8 ( & T_6 -> V_14 , V_15 , 0 , L_2 ) ;
return F_18 ( V_3 , V_40 , T_6 , & V_41 ) ;
}
static int F_34 ( T_2 * V_3 , T_5 * T_6 , T_3 * V_40 ,
void * T_13 V_6 ) {
static const T_14 V_55 [] = { F_15 , F_11 , F_12 , F_1 , F_4 , F_13 } ;
T_10 V_41 = { & V_61 , V_55 , F_29 (getters) } ;
return F_18 ( V_3 , V_40 , T_6 , & V_41 ) ;
}
static int F_35 ( T_2 * V_3 , T_5 * T_6 , T_3 * V_40 ,
void * T_13 V_6 ) {
static const T_14 V_55 [] = { F_15 , F_11 , F_12 , F_1 , F_4 , F_13 } ;
T_10 V_41 = { & V_62 , V_55 , F_29 (getters) } ;
return F_18 ( V_3 , V_40 , T_6 , & V_41 ) ;
}
void F_36 ( void ) {
T_15 * V_63 ;
static T_16 V_64 [] = {
{ & V_38 ,
{ L_3 , L_4 ,
V_65 , V_66 , NULL , 0x00 , NULL , V_67
}
} ,
{ & V_13 ,
{ L_5 , L_6 ,
V_68 , V_69 , NULL , 0x00 , NULL , V_67
}
} ,
{ & V_22 ,
{ L_7 , L_8 ,
V_68 , V_69 , NULL , 0x00 , NULL , V_67
}
} ,
{ & V_10 ,
{ L_9 , L_10 ,
V_70 , V_71 , F_37 ( V_72 ) , 0x00 , NULL , V_67
}
} ,
{ & V_20 ,
{ L_11 , L_12 ,
V_73 , V_71 , NULL , 0x00 , L_13 , V_67
}
} ,
{ & V_21 ,
{ L_14 , L_15 ,
V_73 , V_71 , NULL , 0x00 , L_16 , V_67
}
}
} ;
static T_17 V_74 [] = {
{ & V_39 , { L_17 , V_75 , V_76 , L_18 , V_77 } } ,
{ & V_54 , { L_19 , V_75 , V_76 , L_20 , V_77 } } ,
} ;
static T_4 * V_78 [] = { & V_48 } ;
V_46 = F_38 ( L_21 , V_17 ,
L_22 ) ;
F_39 ( V_46 , V_64 , F_29 ( V_64 ) ) ;
F_40 ( V_78 , F_29 ( V_78 ) ) ;
V_79 = F_41 ( L_23 ,
F_28 , V_46 ) ;
V_80 = F_41 ( L_24 ,
F_30 , V_46 ) ;
V_81 = F_41 ( L_25 ,
F_32 , V_46 ) ;
V_82 = F_41 ( L_26 ,
F_31 , V_46 ) ;
V_83 = F_41 ( L_27 ,
F_33 , V_46 ) ;
V_84 = F_41 ( L_28 ,
F_34 , V_46 ) ;
V_85 = F_41 ( L_29 ,
F_35 , V_46 ) ;
V_50 = F_42 ( V_86 , V_87 , V_51 , NULL ) ;
V_56 = F_42 ( V_88 , V_87 , V_51 , NULL ) ;
V_57 = F_42 ( V_89 , V_87 , V_51 , NULL ) ;
V_59 = F_42 ( V_90 , V_87 , V_51 , NULL ) ;
V_60 = F_42 ( V_91 , V_87 , V_51 , NULL ) ;
V_61 = F_42 ( V_92 , V_87 , V_51 , NULL ) ;
V_58 = F_42 ( V_93 , V_87 , V_51 , NULL ) ;
V_62 = F_42 ( V_94 , V_95 , V_51 , NULL ) ;
V_63 = F_43 ( V_46 ) ;
F_44 ( V_63 , V_74 , F_29 ( V_74 ) ) ;
}
void F_45 ( void ) {
F_46 ( L_30 , V_96 ,
V_79 ) ;
F_46 ( L_30 , V_97 ,
V_80 ) ;
F_46 ( L_30 , V_98 ,
V_81 ) ;
F_46 ( L_30 , V_99 ,
V_83 ) ;
F_46 ( L_30 , V_100 ,
V_84 ) ;
F_46 ( L_30 , V_101 ,
V_82 ) ;
F_46 ( L_30 , V_102 ,
V_85 ) ;
}
