static int F_1 ( T_1 * V_1 ) {
const T_2 * error = F_2 ( V_1 , 1 ) ;
static T_2 * V_2 = NULL ;
static int V_3 = 0 ;
static int V_4 = 2 ;
T_2 * V_5 = ( V_6 ) ?
F_3 ( NULL , L_1 , V_6 -> V_7 ) :
F_3 ( NULL , L_2 ) ;
if ( ! V_2 ) {
F_4 ( L_3 , V_5 , error ) ;
V_2 = F_5 ( error ) ;
V_3 = 0 ;
V_4 = 2 ;
F_6 ( NULL , V_5 ) ;
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
F_6 ( NULL , V_5 ) ;
return 0 ;
}
static T_3 F_9 ( void * V_8 , T_4 * V_9 , T_5 * V_10 , const void * V_11 ) {
T_6 V_12 = ( T_6 ) V_8 ;
T_3 V_13 = FALSE ;
if ( V_12 -> V_14 == V_15 ) return FALSE ;
F_10 ( V_12 -> V_1 , 0 ) ;
F_11 ( V_12 -> V_1 , F_1 ) ;
F_12 ( V_12 -> V_1 , V_16 , V_12 -> V_14 ) ;
F_13 ( V_12 -> V_1 , V_9 ) ;
F_14 ( V_12 -> V_1 , V_10 -> V_17 ) ;
if ( V_12 -> V_18 ) {
V_12 -> V_18 ( V_12 -> V_1 , V_11 ) ;
} else {
F_15 ( V_12 -> V_1 ) ;
}
V_6 = V_9 ;
V_19 = V_10 -> V_17 ;
V_20 = F_16 ( V_10 -> V_21 , NULL ) ;
switch ( F_17 ( V_12 -> V_1 , 3 , 1 , 1 ) ) {
case 0 :
V_13 = F_18 ( V_12 -> V_1 , - 1 , 1 ) == 0 ? FALSE : TRUE ;
break;
case V_22 :
break;
case V_23 :
F_19 ( L_6 ) ;
break;
default:
F_20 () ;
break;
}
F_21 () ;
F_22 () ;
V_6 = NULL ;
V_19 = NULL ;
V_20 = NULL ;
return V_13 ;
}
static int F_23 ( T_1 * V_1 ) {
const T_2 * error = F_2 ( V_1 , 1 ) ;
F_4 ( L_7 , error ) ;
return 1 ;
}
static void F_24 ( void * V_8 ) {
T_6 V_12 = ( T_6 ) V_8 ;
if ( V_12 -> V_24 == V_15 ) return;
F_11 ( V_12 -> V_1 , F_23 ) ;
F_12 ( V_12 -> V_1 , V_16 , V_12 -> V_24 ) ;
switch ( F_17 ( V_12 -> V_1 , 0 , 0 , 1 ) ) {
case 0 :
break;
case V_22 :
F_19 ( L_8 ) ;
break;
case V_23 :
F_19 ( L_9 ) ;
break;
default:
F_20 () ;
break;
}
}
static void F_25 ( void * V_8 ) {
T_6 V_12 = ( T_6 ) V_8 ;
const T_2 * error ;
if ( V_12 -> V_25 == V_15 ) return;
F_11 ( V_12 -> V_1 , F_23 ) ;
F_12 ( V_12 -> V_1 , V_16 , V_12 -> V_25 ) ;
switch ( F_17 ( V_12 -> V_1 , 0 , 0 , 1 ) ) {
case 0 :
break;
case V_22 :
error = F_2 ( V_12 -> V_1 , - 1 ) ;
F_19 ( L_10 , error ) ;
break;
case V_23 :
F_19 ( L_11 ) ;
break;
default:
F_20 () ;
break;
}
}
static void F_26 ( T_1 * V_1 V_26 , T_6 V_12 ) {
if ( V_12 -> V_27 ) {
F_27 ( FALSE ) ;
V_12 -> V_27 = FALSE ;
}
F_28 ( V_12 ) ;
F_8 ( V_12 -> V_28 ) ;
F_8 ( V_12 -> V_29 ) ;
F_8 ( V_12 ) ;
}
T_7 F_29 ( T_1 * V_1 ) {
#define F_30 1
#define F_31 2
#define F_32 3
const T_2 * V_30 = F_33 ( V_1 , F_30 , L_12 ) ;
const T_2 * V_28 = F_33 ( V_1 , F_31 , NULL ) ;
const T_3 V_27 = F_34 ( V_1 , F_32 , FALSE ) ;
T_6 V_12 ;
T_8 * error ;
V_12 = ( T_6 ) F_35 ( sizeof( struct V_31 ) ) ;
V_12 -> V_29 = F_5 ( V_30 ) ;
V_12 -> V_28 = V_28 ? F_5 ( V_28 ) : NULL ;
V_12 -> V_18 = F_36 ( V_30 ) ;
V_12 -> V_1 = V_1 ;
V_12 -> V_14 = V_15 ;
V_12 -> V_25 = V_15 ;
V_12 -> V_24 = V_15 ;
V_12 -> V_27 = V_27 ;
error = F_37 ( V_30 , V_12 , V_12 -> V_28 , V_32 , F_24 , F_9 , F_25 ) ;
if ( error ) {
F_8 ( V_12 -> V_28 ) ;
F_8 ( V_12 -> V_29 ) ;
F_8 ( V_12 ) ;
F_38 ( V_1 , L_13 , error -> V_33 ) ;
F_39 ( error , TRUE ) ;
F_40 ( V_1 , F_2 ( V_1 , - 1 ) ) ;
}
if ( V_27 ) {
F_27 ( TRUE ) ;
}
F_41 ( V_34 , V_12 ) ;
F_42 ( V_1 , V_12 ) ;
F_43 ( 1 ) ;
}
static T_9
F_44 ( T_10 V_35 , T_10 V_36 )
{
return strcmp ( ( const char * ) V_35 , ( const char * ) V_36 ) ;
}
T_7 F_45 ( T_1 * V_1 ) {
T_11 * V_37 = F_46 () ;
T_11 * V_38 = NULL ;
int V_39 = 1 ;
if ( ! V_37 ) return F_40 ( V_1 , L_14 ) ;
V_37 = F_47 ( V_37 , ( V_40 ) F_44 ) ;
V_38 = F_48 ( V_37 ) ;
F_49 ( V_1 ) ;
for ( V_39 = 1 ; V_38 ; V_39 ++ , V_38 = F_50 ( V_38 ) ) {
F_51 ( V_1 , ( const char * ) V_38 -> V_11 ) ;
F_52 ( V_1 , 1 , V_39 ) ;
}
F_53 ( V_37 ) ;
F_43 ( 1 ) ;
}
T_12 F_54 ( T_1 * V_1 ) {
T_6 V_12 = F_55 ( V_1 , 1 ) ;
if ( V_34 && F_56 ( V_34 , V_12 ) ) {
F_26 ( V_1 , V_12 ) ;
}
return 0 ;
}
T_13 F_57 ( T_1 * V_1 ) {
T_6 V_12 = F_55 ( V_1 , 1 ) ;
F_38 ( V_1 , L_15 , V_12 -> V_29 , V_12 -> V_28 ? V_12 -> V_28 : L_16 ) ;
return 1 ;
}
static int F_58 ( T_1 * V_1 V_26 ) {
return 0 ;
}
int F_59 ( T_1 * V_1 ) {
F_60 ( V_1 ) ;
V_34 = F_61 () ;
F_62 ( T_6 ) ;
F_63 ( T_6 ) ;
return 0 ;
}
static void F_64 ( T_14 V_11 , T_14 V_41 ) {
T_1 * V_1 = ( T_1 * ) V_41 ;
T_6 V_12 = ( T_6 ) V_11 ;
F_26 ( V_1 , V_12 ) ;
}
int F_65 ( T_1 * V_1 ) {
F_66 ( V_34 , F_64 , V_1 ) ;
F_67 ( V_34 , FALSE ) ;
V_34 = NULL ;
return 0 ;
}
