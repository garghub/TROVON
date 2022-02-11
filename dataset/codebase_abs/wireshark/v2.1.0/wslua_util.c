T_1 F_1 ( T_2 * V_1 ) {
const T_3 * V_2 = V_3 ;
F_2 ( V_1 , V_2 ) ;
F_3 ( 1 ) ;
}
const T_3 * F_4 ( void ) {
return V_4 ? V_4 : L_1 ;
}
void F_5 ( void ) {
if ( V_4 != NULL ) {
F_6 ( V_4 ) ;
V_4 = NULL ;
}
}
T_1 F_7 ( T_2 * V_1 ) {
#define F_8 1
if ( F_9 ( V_1 , F_8 ) ) {
int V_5 ;
F_10 ( V_1 , F_8 , L_2 ) ;
V_5 = F_11 ( V_1 ) ;
if ( F_12 ( V_1 , V_5 ) ) {
F_5 () ;
V_4 = F_13 ( F_14 ( V_1 , V_5 ) ) ;
F_15 ( V_1 , 1 ) ;
}
else {
return F_16 ( V_1 , L_3 ) ;
}
} else {
return F_16 ( V_1 , L_4 ) ;
}
return 0 ;
}
T_1 F_17 ( T_2 * V_6 ) {
#define F_18 1
T_4 V_7 = F_19 ( V_6 , F_18 ) ;
T_5 V_8 ;
T_3 * V_2 ;
V_8 . V_9 = ( V_10 ) ( floor ( V_7 ) ) ;
V_8 . V_11 = ( V_10 ) ( ( V_7 - ( double ) ( V_8 . V_9 ) ) * 1000000000 ) ;
V_2 = F_20 ( NULL , & V_8 , V_12 , TRUE ) ;
F_2 ( V_6 , V_2 ) ;
F_21 ( NULL , V_2 ) ;
F_3 ( 1 ) ;
}
T_1 F_22 ( T_2 * V_6 ) {
#define F_23 1
T_4 V_7 = F_19 ( V_6 , F_23 ) ;
T_5 V_8 ;
T_3 * V_2 ;
V_8 . V_9 = ( V_10 ) ( floor ( V_7 ) ) ;
V_8 . V_11 = ( V_10 ) ( ( V_7 - ( double ) ( V_8 . V_9 ) ) * 1000000000 ) ;
V_2 = F_24 ( NULL , & V_8 ) ;
F_2 ( V_6 , V_2 ) ;
F_21 ( NULL , V_2 ) ;
F_3 ( 1 ) ;
}
T_1 F_25 ( T_2 * V_6 ) {
#define F_26 1
const T_3 * V_13 = F_14 ( V_6 , F_26 ) ;
F_27 ( L_5 , V_13 ) ;
return 0 ;
}
static int F_28 ( T_2 * V_1 , T_6 V_14 ) {
T_7 * V_2 = F_29 ( L_1 ) ;
int V_15 = F_11 ( V_1 ) ;
int V_16 ;
F_30 ( V_1 , L_6 ) ;
for ( V_16 = 1 ; V_16 <= V_15 ; V_16 ++ ) {
const char * V_13 ;
F_31 ( V_1 , - 1 ) ;
F_31 ( V_1 , V_16 ) ;
F_32 ( V_1 , 1 , 1 ) ;
V_13 = F_33 ( V_1 , - 1 ) ;
if ( V_13 == NULL )
return F_16 ( V_1 , L_7 ) ;
if ( V_16 > 1 ) F_34 ( V_2 , L_8 ) ;
F_34 ( V_2 , V_13 ) ;
F_15 ( V_1 , 1 ) ;
}
F_35 ( V_17 , V_14 , L_9 , V_2 -> V_2 ) ;
F_36 ( V_2 , TRUE ) ;
return 0 ;
}
T_1 F_37 ( T_2 * V_1 ) {
F_28 ( V_1 , V_18 ) ;
return 0 ;
}
T_1 F_38 ( T_2 * V_1 ) {
F_28 ( V_1 , V_19 ) ;
return 0 ;
}
T_1 F_39 ( T_2 * V_1 ) {
F_28 ( V_1 , V_20 ) ;
return 0 ;
}
T_1 F_40 ( T_2 * V_1 ) {
F_28 ( V_1 , V_21 ) ;
return 0 ;
}
T_1 F_41 ( T_2 * V_1 ) {
F_28 ( V_1 , V_22 ) ;
return 0 ;
}
char * F_42 ( const char * V_23 ) {
char V_24 [ 256 ] ;
char * V_25 ;
char * V_26 ;
F_43 ( V_24 , V_23 , 255 ) ;
V_24 [ 255 ] = '\0' ;
for( V_25 = V_24 ; * V_25 ; V_25 ++ ) {
switch( * V_25 ) {
case '/' : case '\\' :
* V_25 = * ( V_27 ) ;
break;
default:
break;
}
}
if ( F_44 ( V_24 ) ) {
return F_13 ( V_24 ) ;
}
V_26 = F_45 ( V_24 , FALSE ) ;
if ( F_44 ( V_26 ) ) {
return V_26 ;
}
F_6 ( V_26 ) ;
V_26 = F_46 ( V_24 ) ;
if ( F_44 ( V_26 ) ) {
return V_26 ;
}
F_6 ( V_26 ) ;
if ( F_47 () ) {
V_26 = F_48 ( L_5 V_27 L_10 V_27 L_11
V_27 L_5 , F_49 () , V_24 ) ;
if ( ( ! F_44 ( V_26 ) ) ) {
F_6 ( V_26 ) ;
V_26 = F_48 ( L_5 V_27 L_5 ,
F_50 () , V_24 ) ;
}
if ( F_44 ( V_26 ) ) {
return V_26 ;
}
F_6 ( V_26 ) ;
}
return NULL ;
}
T_1 F_51 ( T_2 * V_1 ) {
#define F_52 1
const char * V_28 = F_14 ( V_1 , F_52 ) ;
char * V_26 ;
V_26 = F_42 ( V_28 ) ;
if ( ! V_26 ) {
F_53 ( V_29 , V_30 , L_12 ) ;
return 0 ;
}
if ( F_54 ( V_1 , V_26 ) == 0 ) {
F_6 ( V_26 ) ;
return 1 ;
} else {
F_6 ( V_26 ) ;
F_55 ( V_1 ) ;
F_56 ( V_1 , - 2 ) ;
return 2 ;
}
}
T_1 F_57 ( T_2 * V_1 ) {
#define F_58 1
const char * V_28 = F_14 ( V_1 , F_58 ) ;
char * V_26 = F_42 ( V_28 ) ;
int V_15 ;
if ( ! V_26 ) {
F_53 ( V_31 , V_30 , L_12 ) ;
return 0 ;
}
V_15 = F_11 ( V_1 ) ;
if ( F_54 ( V_1 , V_26 ) != 0 ) F_59 ( V_1 ) ;
F_6 ( V_26 ) ;
F_32 ( V_1 , 0 , V_32 ) ;
return F_11 ( V_1 ) - V_15 ;
}
static int F_60 ( T_2 * V_1 V_33 ) {
return 0 ;
}
static void F_61 ( const char * V_34 , void * V_35 ) {
T_8 * V_36 = ( T_8 * ) V_35 ;
T_2 * V_1 = V_36 -> V_1 ;
F_62 ( V_1 , 0 ) ;
F_63 ( V_1 , F_60 ) ;
F_64 ( V_1 , V_37 , V_36 -> V_38 ) ;
F_2 ( V_1 , V_34 ) ;
switch ( F_65 ( V_1 , 1 , 0 , 1 ) ) {
case 0 :
break;
case V_39 :
F_66 ( L_13 ) ;
break;
case V_40 :
F_66 ( L_14 ) ;
break;
default:
F_67 () ;
break;
}
}
T_1 F_68 ( T_2 * V_1 ) {
#define F_69 1
#define F_70 2
const char * V_41 = F_14 ( V_1 , F_69 ) ;
T_8 * V_36 = ( T_8 * ) F_71 ( sizeof( T_8 ) ) ;
T_9 V_42 ;
V_36 -> V_1 = V_1 ;
F_31 ( V_1 , F_70 ) ;
V_36 -> V_38 = F_72 ( V_1 , V_37 ) ;
F_73 ( V_1 , 1 ) ;
V_42 . V_43 = V_44 ;
V_42 . V_45 = NULL ;
V_42 . V_46 = V_41 ;
V_42 . V_47 = F_61 ;
V_42 . V_48 = 0 ;
V_42 . V_49 = NULL ;
F_74 ( & V_42 , V_36 ) ;
return 0 ;
}
