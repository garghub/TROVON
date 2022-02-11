T_1 T_2 F_1 ( T_3 * V_1 , int V_2 , T_2 V_3 ) {
T_2 V_4 = FALSE ;
if ( F_2 ( V_1 , V_2 ) ) {
V_4 = F_3 ( V_1 , V_2 ) ;
} else if ( F_4 ( V_1 , V_2 ) || F_5 ( V_1 ) < V_2 ) {
V_4 = V_3 ;
} else {
F_6 ( V_1 , V_2 , L_1 ) ;
}
return V_4 ;
}
T_1 const T_4 * F_7 ( T_3 * V_1 , int V_5 ) {
const T_4 * V_6 = F_8 ( V_1 , V_5 ) ;
if ( V_6 ) {
F_9 ( V_1 , V_5 ) ;
return V_6 ;
} else {
return NULL ;
}
}
T_1 void F_10 ( T_3 * V_1 , const T_5 * V_7 , int V_8 ) {
F_11 ( V_1 , V_8 , L_2 ) ;
for (; V_7 -> V_9 != NULL ; V_7 ++ ) {
int V_5 ;
for ( V_5 = 0 ; V_5 < V_8 ; V_5 ++ )
F_12 ( V_1 , - V_8 ) ;
F_13 ( V_1 , V_7 -> V_10 , V_8 ) ;
F_14 ( V_1 , - ( V_8 + 2 ) , V_7 -> V_9 ) ;
}
F_15 ( V_1 , V_8 ) ;
}
T_6 F_16 ( T_3 * V_1 ) {
const T_4 * V_11 = V_12 ;
F_17 ( V_1 , V_11 ) ;
F_18 ( 1 ) ;
}
T_6 F_19 ( T_3 * V_13 ) {
#define F_20 1
T_7 V_14 = F_21 ( V_13 , F_20 ) ;
T_8 V_15 ;
T_4 * V_11 ;
V_15 . V_16 = ( V_17 ) floor ( V_14 ) ;
V_15 . V_18 = ( V_17 ) ( ( V_14 - ( double ) ( V_15 . V_16 ) ) * 1000000000 ) ;
V_11 = F_22 ( & V_15 , V_19 , TRUE ) ;
F_17 ( V_13 , V_11 ) ;
F_18 ( 1 ) ;
}
T_6 F_23 ( T_3 * V_13 ) {
#define F_24 1
T_7 V_14 = F_21 ( V_13 , F_24 ) ;
T_8 V_15 ;
T_4 * V_11 ;
V_15 . V_16 = ( V_17 ) floor ( V_14 ) ;
V_15 . V_18 = ( V_17 ) ( ( V_14 - ( double ) ( V_15 . V_16 ) ) * 1000000000 ) ;
V_11 = F_25 ( & V_15 ) ;
F_17 ( V_13 , V_11 ) ;
F_18 ( 1 ) ;
}
T_6 F_26 ( T_3 * V_13 ) {
#define F_27 1
const T_4 * V_20 = F_8 ( V_13 , F_27 ) ;
F_28 ( L_3 , V_20 ) ;
return 0 ;
}
static int F_29 ( T_3 * V_1 , T_9 V_21 ) {
T_10 * V_11 = F_30 ( L_4 ) ;
int V_2 = F_5 ( V_1 ) ;
int V_5 ;
F_31 ( V_1 , L_5 ) ;
for ( V_5 = 1 ; V_5 <= V_2 ; V_5 ++ ) {
const char * V_20 ;
F_12 ( V_1 , - 1 ) ;
F_12 ( V_1 , V_5 ) ;
F_32 ( V_1 , 1 , 1 ) ;
V_20 = F_33 ( V_1 , - 1 ) ;
if ( V_20 == NULL )
return F_34 ( V_1 , L_6 ) ;
if ( V_5 > 1 ) F_35 ( V_11 , L_7 ) ;
F_35 ( V_11 , V_20 ) ;
F_15 ( V_1 , 1 ) ;
}
F_36 ( V_22 , V_21 , L_8 , V_11 -> V_11 ) ;
F_37 ( V_11 , TRUE ) ;
return 0 ;
}
T_6 F_38 ( T_3 * V_1 ) {
F_29 ( V_1 , V_23 ) ;
return 0 ;
}
T_6 F_39 ( T_3 * V_1 ) {
F_29 ( V_1 , V_24 ) ;
return 0 ;
}
T_6 F_40 ( T_3 * V_1 ) {
F_29 ( V_1 , V_25 ) ;
return 0 ;
}
T_6 F_41 ( T_3 * V_1 ) {
F_29 ( V_1 , V_26 ) ;
return 0 ;
}
T_6 F_42 ( T_3 * V_1 ) {
F_29 ( V_1 , V_27 ) ;
return 0 ;
}
static char * F_43 ( const char * V_28 ) {
char V_29 [ 256 ] ;
char * V_30 ;
char * V_31 ;
F_44 ( V_29 , V_28 , 255 ) ;
V_29 [ 255 ] = '\0' ;
for( V_30 = V_29 ; * V_30 ; V_30 ++ ) {
switch( * V_30 ) {
case '/' : case '\\' :
* V_30 = * ( V_32 ) ;
break;
default:
break;
}
}
if ( F_45 ( V_29 ) ) {
return F_46 ( V_29 ) ;
}
V_31 = F_47 ( V_29 , FALSE ) ;
if ( F_45 ( V_31 ) ) {
return V_31 ;
}
F_48 ( V_31 ) ;
V_31 = F_49 ( V_29 ) ;
if ( F_45 ( V_31 ) ) {
return V_31 ;
}
F_48 ( V_31 ) ;
return NULL ;
}
T_6 F_50 ( T_3 * V_1 ) {
#define F_51 1
const char * V_33 = F_8 ( V_1 , F_51 ) ;
char * V_31 ;
V_31 = F_43 ( V_33 ) ;
if ( ! V_31 ) F_52 ( V_34 , V_35 , L_9 ) ;
if ( F_53 ( V_1 , V_31 ) == 0 ) {
F_48 ( V_31 ) ;
return 1 ;
} else {
F_48 ( V_31 ) ;
F_54 ( V_1 ) ;
F_55 ( V_1 , - 2 ) ;
return 2 ;
}
}
T_6 F_56 ( T_3 * V_1 ) {
#define F_57 1
const char * V_33 = F_8 ( V_1 , F_57 ) ;
char * V_31 ;
int V_2 ;
if ( ! V_33 ) F_52 ( V_36 , V_35 , L_10 ) ;
V_31 = F_43 ( V_33 ) ;
if ( ! V_31 ) F_52 ( V_36 , V_35 , L_9 ) ;
V_2 = F_5 ( V_1 ) ;
if ( F_53 ( V_1 , V_31 ) != 0 ) F_58 ( V_1 ) ;
F_48 ( V_31 ) ;
F_32 ( V_1 , 0 , V_37 ) ;
return F_5 ( V_1 ) - V_2 ;
}
T_6 F_59 ( T_3 * V_1 ) {
#define F_60 1
const char * V_28 = F_61 ( V_1 , F_60 , L_4 ) ;
char * V_31 = F_47 ( V_28 , FALSE ) ;
F_17 ( V_1 , V_31 ) ;
F_48 ( V_31 ) ;
F_18 ( 1 ) ;
}
T_6 F_62 ( T_3 * V_1 ) {
#define F_63 1
const char * V_28 = F_61 ( V_1 , F_63 , L_4 ) ;
char * V_31 = F_49 ( V_28 ) ;
F_17 ( V_1 , V_31 ) ;
F_48 ( V_31 ) ;
F_18 ( 1 ) ;
}
T_11 F_64 ( T_3 * V_1 ) {
#define F_65 1
#define F_66 2
const char * V_38 = F_8 ( V_1 , F_65 ) ;
const char * V_39 = F_61 ( V_1 , F_66 , NULL ) ;
T_12 V_40 ;
char * V_41 ;
if ( ! V_38 ) F_52 ( F_64 , V_42 , L_10 ) ;
V_41 = F_43 ( V_38 ) ;
if ( ! V_41 ) F_52 ( F_64 , V_42 , L_11 ) ;
if ( ! F_67 ( V_41 ) ) {
F_48 ( V_41 ) ;
F_52 ( F_64 , V_42 , L_12 ) ;
}
V_40 = ( T_12 ) F_68 ( sizeof( struct V_43 ) ) ;
V_40 -> V_40 = F_69 ( V_41 ) ;
F_48 ( V_41 ) ;
V_40 -> V_44 = V_39 ? F_46 ( V_39 ) : NULL ;
V_40 -> V_45 = ( V_46 * * ) F_68 ( sizeof( V_46 * ) ) ;
* ( V_40 -> V_45 ) = NULL ;
if ( V_40 -> V_40 == NULL ) {
F_48 ( V_40 -> V_45 ) ;
F_48 ( V_40 ) ;
F_52 ( F_64 , V_42 , L_13 ) ;
}
F_70 ( V_1 , V_40 ) ;
F_18 ( 1 ) ;
}
T_13 F_71 ( T_3 * V_1 ) {
T_12 V_40 = F_72 ( V_1 , 1 ) ;
const T_14 * V_47 ;
const T_4 * V_31 ;
const char * V_44 ;
if ( ! V_40 ) {
F_6 ( V_1 , 1 , L_14 ) ;
return 0 ;
}
if ( ! V_40 -> V_40 ) {
return 0 ;
}
if ( ! ( V_47 = F_73 ( V_40 -> V_40 ) ) ) {
F_74 ( V_40 -> V_40 ) ;
V_40 -> V_40 = NULL ;
return 0 ;
}
if ( ! V_40 -> V_44 ) {
V_31 = F_75 ( V_47 ) ;
F_17 ( V_1 , V_31 ) ;
return 1 ;
}
do {
V_31 = F_75 ( V_47 ) ;
if ( ( V_44 = strstr ( V_31 , V_40 -> V_44 ) ) && F_76 ( V_44 , V_40 -> V_44 ) ) {
F_17 ( V_1 , V_31 ) ;
return 1 ;
}
} while( ( V_47 = F_73 ( V_40 -> V_40 ) ) );
F_74 ( V_40 -> V_40 ) ;
V_40 -> V_40 = NULL ;
return 0 ;
}
T_15 F_77 ( T_3 * V_1 ) {
T_12 V_40 = F_72 ( V_1 , 1 ) ;
if ( V_40 -> V_40 ) {
F_74 ( V_40 -> V_40 ) ;
V_40 -> V_40 = NULL ;
}
return 0 ;
}
static int F_78 ( T_3 * V_1 ) {
T_12 V_40 = F_72 ( V_1 , 1 ) ;
if ( V_40 -> V_40 ) {
F_74 ( V_40 -> V_40 ) ;
}
F_48 ( V_40 -> V_45 ) ;
if ( V_40 -> V_44 ) F_48 ( V_40 -> V_44 ) ;
F_48 ( V_40 ) ;
return 0 ;
}
int F_79 ( T_3 * V_1 ) {
F_80 ( T_12 ) ;
return 1 ;
}
static int F_81 ( T_3 * V_1 V_48 ) {
return 0 ;
}
static void F_82 ( const char * V_49 , void * V_50 ) {
T_16 * V_51 = ( T_16 * ) V_50 ;
T_3 * V_1 = V_51 -> V_1 ;
F_83 ( V_1 , 0 ) ;
F_84 ( V_1 , F_81 ) ;
F_85 ( V_1 , V_52 , V_51 -> V_53 ) ;
F_17 ( V_1 , V_49 ) ;
switch ( F_86 ( V_1 , 1 , 0 , 1 ) ) {
case 0 :
break;
case V_54 :
F_87 ( L_15 ) ;
break;
case V_55 :
F_87 ( L_16 ) ;
break;
default:
F_88 () ;
break;
}
}
T_6 F_89 ( T_3 * V_1 ) {
#define F_90 1
#define F_91 2
const char * V_56 = F_8 ( V_1 , F_90 ) ;
T_16 * V_51 = ( T_16 * ) F_92 ( sizeof( T_16 ) ) ;
V_51 -> V_1 = V_1 ;
F_12 ( V_1 , F_91 ) ;
V_51 -> V_53 = F_93 ( V_1 , V_52 ) ;
F_9 ( V_1 , 1 ) ;
F_94 ( V_56 , F_82 , V_51 ) ;
return 0 ;
}
