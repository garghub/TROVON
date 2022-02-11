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
T_5 F_10 ( T_3 * V_1 ) {
T_4 * V_7 = V_8 ;
F_11 ( V_1 , V_7 ) ;
F_12 ( 1 ) ;
}
T_5 F_13 ( T_3 * V_9 ) {
#define F_14 1
T_6 V_10 = F_15 ( V_9 , F_14 ) ;
T_7 V_11 ;
T_4 * V_7 ;
V_11 . V_12 = ( V_13 ) floor ( V_10 ) ;
V_11 . V_14 = ( V_13 ) ( ( V_10 - ( double ) ( V_11 . V_12 ) ) * 1000000000 ) ;
V_7 = F_16 ( & V_11 , V_15 , TRUE ) ;
F_11 ( V_9 , V_7 ) ;
F_12 ( 1 ) ;
}
T_5 F_17 ( T_3 * V_9 ) {
#define F_18 1
T_6 V_10 = F_15 ( V_9 , F_18 ) ;
T_7 V_11 ;
T_4 * V_7 ;
V_11 . V_12 = ( V_13 ) floor ( V_10 ) ;
V_11 . V_14 = ( V_13 ) ( ( V_10 - ( double ) ( V_11 . V_12 ) ) * 1000000000 ) ;
V_7 = F_19 ( & V_11 ) ;
F_11 ( V_9 , V_7 ) ;
F_12 ( 1 ) ;
}
T_5 F_20 ( T_3 * V_9 ) {
#define F_21 1
const T_4 * V_16 = F_8 ( V_9 , F_21 ) ;
F_22 ( L_2 , V_16 ) ;
return 0 ;
}
static int F_23 ( T_3 * V_1 , T_8 V_17 ) {
T_9 * V_7 = F_24 ( L_3 ) ;
int V_2 = F_5 ( V_1 ) ;
int V_5 ;
F_25 ( V_1 , L_4 ) ;
for ( V_5 = 1 ; V_5 <= V_2 ; V_5 ++ ) {
const char * V_16 ;
F_26 ( V_1 , - 1 ) ;
F_26 ( V_1 , V_5 ) ;
F_27 ( V_1 , 1 , 1 ) ;
V_16 = F_28 ( V_1 , - 1 ) ;
if ( V_16 == NULL )
return F_29 ( V_1 , L_5 ) ;
if ( V_5 > 1 ) F_30 ( V_7 , L_6 ) ;
F_30 ( V_7 , V_16 ) ;
F_31 ( V_1 , 1 ) ;
}
F_32 ( V_18 , V_17 , L_7 , V_7 -> V_7 ) ;
F_33 ( V_7 , TRUE ) ;
return 0 ;
}
T_5 F_34 ( T_3 * V_1 ) {
F_23 ( V_1 , V_19 ) ;
return 0 ;
}
T_5 F_35 ( T_3 * V_1 ) {
F_23 ( V_1 , V_20 ) ;
return 0 ;
}
T_5 F_36 ( T_3 * V_1 ) {
F_23 ( V_1 , V_21 ) ;
return 0 ;
}
T_5 F_37 ( T_3 * V_1 ) {
F_23 ( V_1 , V_22 ) ;
return 0 ;
}
T_5 F_38 ( T_3 * V_1 ) {
F_23 ( V_1 , V_23 ) ;
return 0 ;
}
static char * F_39 ( const char * V_24 ) {
char V_25 [ 256 ] ;
char * V_26 ;
char * V_27 ;
F_40 ( V_25 , V_24 , 255 ) ;
V_25 [ 255 ] = '\0' ;
for( V_26 = V_25 ; * V_26 ; V_26 ++ ) {
switch( * V_26 ) {
case '/' : case '\\' :
* V_26 = * ( V_28 ) ;
break;
default:
break;
}
}
if ( F_41 ( V_25 ) ) {
return F_42 ( V_25 ) ;
}
V_27 = F_43 ( V_25 , FALSE , FALSE ) ;
if ( F_41 ( V_27 ) ) {
return V_27 ;
}
F_44 ( V_27 ) ;
V_27 = F_45 ( V_25 ) ;
if ( F_41 ( V_27 ) ) {
return V_27 ;
}
F_44 ( V_27 ) ;
return NULL ;
}
T_5 F_46 ( T_3 * V_1 ) {
#define F_47 1
const char * V_29 = F_8 ( V_1 , F_47 ) ;
char * V_27 ;
V_27 = F_39 ( V_29 ) ;
if ( ! V_27 ) F_48 ( V_30 , V_31 , L_8 ) ;
if ( F_49 ( V_1 , V_27 ) == 0 ) {
F_44 ( V_27 ) ;
return 1 ;
} else {
F_44 ( V_27 ) ;
F_50 ( V_1 ) ;
F_51 ( V_1 , - 2 ) ;
return 2 ;
}
}
T_5 F_52 ( T_3 * V_1 ) {
#define F_53 1
const char * V_29 = F_8 ( V_1 , F_53 ) ;
char * V_27 ;
int V_2 ;
if ( ! V_29 ) F_48 ( V_32 , V_31 , L_9 ) ;
V_27 = F_39 ( V_29 ) ;
if ( ! V_27 ) F_48 ( V_32 , V_31 , L_8 ) ;
V_2 = F_5 ( V_1 ) ;
if ( F_49 ( V_1 , V_27 ) != 0 ) F_54 ( V_1 ) ;
F_44 ( V_27 ) ;
F_27 ( V_1 , 0 , V_33 ) ;
return F_5 ( V_1 ) - V_2 ;
}
T_5 F_55 ( T_3 * V_1 ) {
#define F_56 1
const char * V_24 = F_57 ( V_1 , F_56 , L_3 ) ;
char * V_27 = F_43 ( V_24 , FALSE , FALSE ) ;
F_11 ( V_1 , V_27 ) ;
F_44 ( V_27 ) ;
F_12 ( 1 ) ;
}
T_5 F_58 ( T_3 * V_1 ) {
#define F_59 1
const char * V_24 = F_57 ( V_1 , F_59 , L_3 ) ;
char * V_27 = F_45 ( V_24 ) ;
F_11 ( V_1 , V_27 ) ;
F_44 ( V_27 ) ;
F_12 ( 1 ) ;
}
T_10 F_60 ( T_3 * V_1 ) {
#define F_61 1
#define F_62 2
const char * V_34 = F_8 ( V_1 , F_61 ) ;
const char * V_35 = F_57 ( V_1 , F_62 , NULL ) ;
T_11 V_36 ;
char * V_37 ;
if ( ! V_34 ) F_48 ( F_60 , V_38 , L_9 ) ;
V_37 = F_39 ( V_34 ) ;
if ( ! V_37 ) F_48 ( F_60 , V_38 , L_10 ) ;
if ( ! F_63 ( V_37 ) ) {
F_44 ( V_37 ) ;
F_48 ( F_60 , V_38 , L_11 ) ;
}
V_36 = F_64 ( sizeof( struct V_39 ) ) ;
V_36 -> V_36 = F_65 ( V_37 ) ;
F_44 ( V_37 ) ;
V_36 -> V_40 = V_35 ? F_42 ( V_35 ) : NULL ;
V_36 -> V_41 = F_64 ( sizeof( V_42 * ) ) ;
* ( V_36 -> V_41 ) = NULL ;
if ( V_36 -> V_36 == NULL ) {
F_44 ( V_36 -> V_41 ) ;
F_44 ( V_36 ) ;
F_48 ( F_60 , V_38 , L_12 ) ;
}
F_66 ( V_1 , V_36 ) ;
F_12 ( 1 ) ;
}
T_12 F_67 ( T_3 * V_1 ) {
T_11 V_36 = F_68 ( V_1 , 1 ) ;
const T_13 * V_43 ;
const T_4 * V_27 ;
const char * V_40 ;
if ( ! V_36 ) {
F_6 ( V_1 , 1 , L_13 ) ;
return 0 ;
}
if ( ! V_36 -> V_36 ) {
return 0 ;
}
if ( ! ( V_43 = F_69 ( V_36 -> V_36 ) ) ) {
F_70 ( V_36 -> V_36 ) ;
V_36 -> V_36 = NULL ;
return 0 ;
}
if ( ! V_36 -> V_40 ) {
V_27 = F_71 ( V_43 ) ;
F_11 ( V_1 , V_27 ) ;
return 1 ;
}
do {
V_27 = F_71 ( V_43 ) ;
if ( ( V_40 = strstr ( V_27 , V_36 -> V_40 ) ) && F_72 ( V_40 , V_36 -> V_40 ) ) {
F_11 ( V_1 , V_27 ) ;
return 1 ;
}
} while( ( V_43 = F_69 ( V_36 -> V_36 ) ) );
F_70 ( V_36 -> V_36 ) ;
V_36 -> V_36 = NULL ;
return 0 ;
}
T_14 F_73 ( T_3 * V_1 ) {
T_11 V_36 = F_68 ( V_1 , 1 ) ;
if ( V_36 -> V_36 ) {
F_70 ( V_36 -> V_36 ) ;
V_36 -> V_36 = NULL ;
}
return 0 ;
}
static int F_74 ( T_3 * V_1 ) {
T_11 V_36 = F_68 ( V_1 , 1 ) ;
if ( V_36 -> V_36 ) {
F_70 ( V_36 -> V_36 ) ;
}
F_44 ( V_36 -> V_41 ) ;
if ( V_36 -> V_40 ) F_44 ( V_36 -> V_40 ) ;
F_44 ( V_36 ) ;
return 0 ;
}
int F_75 ( T_3 * V_1 ) {
F_76 ( T_11 ) ;
return 1 ;
}
static int F_77 ( T_3 * V_1 ) {
( void ) V_1 ;
return 0 ;
}
static void F_78 ( const char * V_44 , void * V_45 ) {
T_15 * V_46 = V_45 ;
T_3 * V_1 = V_46 -> V_1 ;
F_79 ( V_1 , 0 ) ;
F_80 ( V_1 , F_77 ) ;
F_81 ( V_1 , V_47 , V_46 -> V_48 ) ;
F_11 ( V_1 , V_44 ) ;
switch ( F_82 ( V_1 , 1 , 0 , 1 ) ) {
case 0 :
break;
case V_49 :
F_83 ( L_14 ) ;
break;
case V_50 :
F_83 ( L_15 ) ;
break;
default:
F_84 () ;
break;
}
}
T_5 F_85 ( T_3 * V_1 ) {
#define F_86 1
#define F_87 2
const char * V_51 = F_8 ( V_1 , F_86 ) ;
T_15 * V_46 = F_88 ( sizeof( T_15 ) ) ;
V_46 -> V_1 = V_1 ;
F_26 ( V_1 , F_87 ) ;
V_46 -> V_48 = F_89 ( V_1 , V_47 ) ;
F_9 ( V_1 , 1 ) ;
F_90 ( V_51 , F_78 , V_46 ) ;
return 0 ;
}
