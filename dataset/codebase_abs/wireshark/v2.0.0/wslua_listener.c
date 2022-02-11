static int F_1 ( T_1 * V_1 ) {
const T_2 * error = F_2 ( V_1 , 1 ) ;
static T_2 * V_2 = NULL ;
static int V_3 = 0 ;
static int V_4 = 2 ;
const T_2 * V_5 = ( V_6 ) ?
F_3 ( NULL , L_1 , V_6 -> V_7 -> V_8 ) :
F_3 ( NULL , L_2 ) ;
if ( ! V_2 ) {
F_4 ( L_3 , V_5 , error ) ;
V_2 = F_5 ( error ) ;
V_3 = 0 ;
V_4 = 2 ;
F_6 ( NULL , ( void * ) V_5 ) ;
V_5 = NULL ;
return 0 ;
}
if ( F_7 ( V_2 , error ) ) {
V_3 ++ ;
if ( V_3 == V_4 ) {
F_4 ( L_4 , V_5 , V_3 , error ) ;
V_4 *= 2 ;
}
} else {
F_4 ( L_4 , V_5 , V_3 , V_2 ) ;
F_8 ( V_2 ) ;
V_2 = F_5 ( error ) ;
V_3 = 0 ;
V_4 = 2 ;
F_4 ( L_5 , V_5 , error ) ;
}
F_6 ( NULL , ( void * ) V_5 ) ;
return 0 ;
}
static T_3 F_9 ( void * V_9 , T_4 * V_10 , T_5 * V_11 , const void * V_12 ) {
T_6 V_13 = ( T_6 ) V_9 ;
T_3 V_14 = FALSE ;
if ( V_13 -> V_15 == V_16 ) return FALSE ;
F_10 ( V_13 -> V_1 , 0 ) ;
F_11 ( V_13 -> V_1 , F_1 ) ;
F_12 ( V_13 -> V_1 , V_17 , V_13 -> V_15 ) ;
F_13 ( V_13 -> V_1 , V_10 ) ;
F_14 ( V_13 -> V_1 , V_11 -> V_18 ) ;
if ( V_13 -> V_19 ) {
V_13 -> V_19 ( V_13 -> V_1 , V_12 ) ;
} else {
F_15 ( V_13 -> V_1 ) ;
}
V_6 = V_10 ;
V_20 = V_11 -> V_18 ;
V_21 = F_16 ( V_11 -> V_22 , NULL ) ;
switch ( F_17 ( V_13 -> V_1 , 3 , 1 , 1 ) ) {
case 0 :
V_14 = F_18 ( V_13 -> V_1 , - 1 , 1 ) == 0 ? FALSE : TRUE ;
break;
case V_23 :
break;
case V_24 :
F_19 ( L_6 ) ;
break;
default:
F_20 () ;
break;
}
F_21 () ;
F_22 () ;
V_6 = NULL ;
V_20 = NULL ;
V_21 = NULL ;
return V_14 ;
}
static int F_23 ( T_1 * V_1 ) {
const T_2 * error = F_2 ( V_1 , 1 ) ;
F_4 ( L_7 , error ) ;
return 1 ;
}
static void F_24 ( void * V_9 ) {
T_6 V_13 = ( T_6 ) V_9 ;
if ( V_13 -> V_25 == V_16 ) return;
F_11 ( V_13 -> V_1 , F_23 ) ;
F_12 ( V_13 -> V_1 , V_17 , V_13 -> V_25 ) ;
switch ( F_17 ( V_13 -> V_1 , 0 , 0 , 1 ) ) {
case 0 :
break;
case V_23 :
F_19 ( L_8 ) ;
break;
case V_24 :
F_19 ( L_9 ) ;
break;
default:
F_20 () ;
break;
}
}
static void F_25 ( void * V_9 ) {
T_6 V_13 = ( T_6 ) V_9 ;
const T_2 * error ;
if ( V_13 -> V_26 == V_16 ) return;
F_11 ( V_13 -> V_1 , F_23 ) ;
F_12 ( V_13 -> V_1 , V_17 , V_13 -> V_26 ) ;
switch ( F_17 ( V_13 -> V_1 , 0 , 0 , 1 ) ) {
case 0 :
break;
case V_23 :
error = F_2 ( V_13 -> V_1 , - 1 ) ;
F_19 ( L_10 , error ) ;
break;
case V_24 :
F_19 ( L_11 ) ;
break;
default:
F_20 () ;
break;
}
}
static void F_26 ( T_1 * V_1 V_27 , T_6 V_13 ) {
if ( V_13 -> V_28 ) {
F_27 ( FALSE ) ;
V_13 -> V_28 = FALSE ;
}
F_28 ( V_13 ) ;
F_8 ( V_13 -> V_29 ) ;
F_8 ( V_13 -> V_30 ) ;
F_8 ( V_13 ) ;
}
T_7 F_29 ( T_1 * V_1 ) {
#define F_30 1
#define F_31 2
#define F_32 3
const T_2 * V_31 = F_33 ( V_1 , F_30 , L_12 ) ;
const T_2 * V_29 = F_33 ( V_1 , F_31 , NULL ) ;
const T_3 V_28 = F_34 ( V_1 , F_32 , FALSE ) ;
T_6 V_13 ;
T_8 * error ;
V_13 = ( T_6 ) F_35 ( sizeof( struct V_32 ) ) ;
V_13 -> V_30 = F_5 ( V_31 ) ;
V_13 -> V_29 = V_29 ? F_5 ( V_29 ) : NULL ;
V_13 -> V_19 = F_36 ( V_31 ) ;
V_13 -> V_1 = V_1 ;
V_13 -> V_15 = V_16 ;
V_13 -> V_26 = V_16 ;
V_13 -> V_25 = V_16 ;
V_13 -> V_28 = V_28 ;
error = F_37 ( V_31 , V_13 , V_13 -> V_29 , V_33 , F_24 , F_9 , F_25 ) ;
if ( error ) {
F_8 ( V_13 -> V_29 ) ;
F_8 ( V_13 -> V_30 ) ;
F_8 ( V_13 ) ;
F_38 ( V_1 , L_13 , error -> V_34 ) ;
F_39 ( error , TRUE ) ;
F_40 ( V_1 , F_2 ( V_1 , - 1 ) ) ;
}
if ( V_28 ) {
F_27 ( TRUE ) ;
}
F_41 ( V_35 , V_13 ) ;
F_42 ( V_1 , V_13 ) ;
F_43 ( 1 ) ;
}
static T_9
F_44 ( T_10 V_36 , T_10 V_37 )
{
return strcmp ( ( const char * ) V_36 , ( const char * ) V_37 ) ;
}
T_7 F_45 ( T_1 * V_1 ) {
T_11 * V_38 = F_46 () ;
T_11 * V_39 = NULL ;
int V_40 = 1 ;
if ( ! V_38 ) return F_40 ( V_1 , L_14 ) ;
V_38 = F_47 ( V_38 , ( V_41 ) F_44 ) ;
V_39 = F_48 ( V_38 ) ;
F_49 ( V_1 ) ;
for ( V_40 = 1 ; V_39 ; V_40 ++ , V_39 = F_50 ( V_39 ) ) {
F_51 ( V_1 , ( const char * ) V_39 -> V_12 ) ;
F_52 ( V_1 , 1 , V_40 ) ;
}
F_53 ( V_38 ) ;
F_43 ( 1 ) ;
}
T_12 F_54 ( T_1 * V_1 ) {
T_6 V_13 = F_55 ( V_1 , 1 ) ;
if ( V_35 && F_56 ( V_35 , V_13 ) ) {
F_26 ( V_1 , V_13 ) ;
}
return 0 ;
}
T_13 F_57 ( T_1 * V_1 ) {
T_6 V_13 = F_55 ( V_1 , 1 ) ;
F_38 ( V_1 , L_15 , V_13 -> V_30 , V_13 -> V_29 ? V_13 -> V_29 : L_16 ) ;
return 1 ;
}
static int F_58 ( T_1 * V_1 V_27 ) {
return 0 ;
}
int F_59 ( T_1 * V_1 ) {
F_60 ( V_1 ) ;
V_35 = F_61 () ;
F_62 ( T_6 ) ;
F_63 ( T_6 ) ;
return 0 ;
}
static void F_64 ( T_14 V_12 , T_14 V_42 ) {
T_1 * V_1 = ( T_1 * ) V_42 ;
T_6 V_13 = ( T_6 ) V_12 ;
F_26 ( V_1 , V_13 ) ;
}
int F_65 ( T_1 * V_1 ) {
F_66 ( V_35 , F_64 , V_1 ) ;
F_67 ( V_35 , FALSE ) ;
V_35 = NULL ;
return 0 ;
}
