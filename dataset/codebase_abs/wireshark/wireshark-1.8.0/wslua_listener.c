static int F_1 ( T_1 * V_1 ) {
const T_2 * error = F_2 ( V_1 , 1 ) ;
static T_2 * V_2 = NULL ;
static int V_3 = 0 ;
static int V_4 = 2 ;
const T_2 * V_5 = ( V_6 ) ?
F_3 ( L_1 , V_6 -> V_7 -> V_8 ) :
F_3 ( L_2 ) ;
if ( ! V_2 ) {
F_4 ( L_3 , V_5 , error ) ;
V_2 = F_5 ( error ) ;
V_3 = 0 ;
V_4 = 2 ;
return 0 ;
}
if ( F_6 ( V_2 , error ) ) {
V_3 ++ ;
if ( V_3 == V_4 ) {
F_4 ( L_4 , V_5 , V_3 , error ) ;
V_4 *= 2 ;
}
} else {
F_4 ( L_4 , V_5 , V_3 , V_2 ) ;
F_7 ( V_2 ) ;
V_2 = F_5 ( error ) ;
V_3 = 0 ;
V_4 = 2 ;
F_4 ( L_5 , V_5 , error ) ;
}
return 0 ;
}
static int F_8 ( void * V_9 , T_3 * V_10 , T_4 * V_11 , const void * V_12 ) {
T_5 V_13 = V_9 ;
int V_14 = 0 ;
if ( V_13 -> V_15 == V_16 ) return 0 ;
F_9 ( V_13 -> V_1 , 0 ) ;
F_10 ( V_13 -> V_1 , F_1 ) ;
F_11 ( V_13 -> V_1 , V_17 , V_13 -> V_15 ) ;
F_12 ( V_13 -> V_1 , V_10 ) ;
F_13 ( V_13 -> V_1 , V_11 -> V_18 ) ;
if ( V_13 -> V_19 ) {
V_13 -> V_19 ( V_13 -> V_1 , V_12 ) ;
} else {
F_14 ( V_13 -> V_1 ) ;
}
V_6 = V_10 ;
V_20 = V_11 -> V_18 ;
V_21 = F_15 ( sizeof( struct V_22 ) ) ;
V_21 -> V_23 = V_11 -> V_23 ;
V_21 -> V_24 = NULL ;
V_21 -> V_25 = FALSE ;
switch ( F_16 ( V_13 -> V_1 , 3 , 1 , 1 ) ) {
case 0 :
V_14 = F_17 ( V_13 -> V_1 , - 1 , 1 ) ;
break;
case V_26 :
break;
case V_27 :
F_18 ( L_6 ) ;
break;
default:
F_19 () ;
break;
}
F_20 () ;
F_21 () ;
V_6 = NULL ;
V_20 = NULL ;
V_21 = NULL ;
return V_14 ;
}
static int F_22 ( T_1 * V_1 ) {
const T_2 * error = F_2 ( V_1 , 1 ) ;
F_4 ( L_7 , error ) ;
return 1 ;
}
static void F_23 ( void * V_9 ) {
T_5 V_13 = V_9 ;
if ( V_13 -> V_28 == V_16 ) return;
F_10 ( V_13 -> V_1 , F_22 ) ;
F_11 ( V_13 -> V_1 , V_17 , V_13 -> V_28 ) ;
switch ( F_16 ( V_13 -> V_1 , 0 , 0 , 1 ) ) {
case 0 :
break;
case V_26 :
F_18 ( L_8 ) ;
break;
case V_27 :
F_18 ( L_9 ) ;
break;
default:
F_19 () ;
break;
}
}
static void F_24 ( void * V_9 ) {
T_5 V_13 = V_9 ;
const T_2 * error ;
if ( V_13 -> V_29 == V_16 ) return;
F_10 ( V_13 -> V_1 , F_22 ) ;
F_11 ( V_13 -> V_1 , V_17 , V_13 -> V_29 ) ;
switch ( F_16 ( V_13 -> V_1 , 0 , 0 , 1 ) ) {
case 0 :
break;
case V_26 :
error = F_2 ( V_13 -> V_1 , - 1 ) ;
F_18 ( L_10 , error ) ;
break;
case V_27 :
F_18 ( L_11 ) ;
break;
default:
F_19 () ;
break;
}
}
T_6 F_25 ( T_1 * V_1 ) {
#define F_26 1
#define F_27 2
const T_2 * V_30 = F_28 ( V_1 , F_26 , L_12 ) ;
const T_2 * V_31 = F_28 ( V_1 , F_27 , NULL ) ;
T_5 V_13 ;
T_7 * error ;
V_13 = F_15 ( sizeof( struct V_32 ) ) ;
V_13 -> V_33 = F_5 ( V_30 ) ;
V_13 -> V_31 = V_31 ? F_5 ( V_31 ) : NULL ;
V_13 -> V_19 = F_29 ( V_30 ) ;
V_13 -> V_1 = V_1 ;
V_13 -> V_15 = V_16 ;
V_13 -> V_29 = V_16 ;
V_13 -> V_28 = V_16 ;
error = F_30 ( V_30 , V_13 , V_13 -> V_31 , V_34 , F_23 , F_8 , F_24 ) ;
if ( error ) {
F_7 ( V_13 -> V_31 ) ;
F_7 ( V_13 -> V_33 ) ;
F_7 ( V_13 ) ;
F_31 ( V_1 , L_13 , error -> V_35 ) ;
F_32 ( error , TRUE ) ;
}
F_33 ( V_1 , V_13 ) ;
F_34 ( 1 ) ;
}
T_8 F_35 ( T_1 * V_1 ) {
T_5 V_13 = F_36 ( V_1 , 1 ) ;
if ( ! V_13 ) return 0 ;
F_37 ( V_13 ) ;
return 0 ;
}
T_9 F_38 ( T_1 * V_1 ) {
T_5 V_13 = F_36 ( V_1 , 1 ) ;
T_2 * V_35 ;
if ( ! V_13 ) return 0 ;
V_35 = F_3 ( L_14 , V_13 -> V_33 , V_13 -> V_31 ? V_13 -> V_31 : L_15 ) ;
F_39 ( V_1 , V_35 ) ;
return 1 ;
}
static int F_40 ( T_1 * V_1 ) {
T_5 V_13 = F_41 ( V_1 , 1 ) ;
const T_2 * V_36 = F_42 ( V_1 , 1 ) ;
int * V_37 = NULL ;
if ( ! V_36 ) return 0 ;
if ( F_6 ( V_36 , L_16 ) ) {
V_37 = & ( V_13 -> V_15 ) ;
} else if ( F_6 ( V_36 , L_17 ) ) {
V_37 = & ( V_13 -> V_29 ) ;
} else if ( F_6 ( V_36 , L_18 ) ) {
V_37 = & ( V_13 -> V_28 ) ;
} else {
F_31 ( V_1 , L_19 , V_36 ) ;
return 0 ;
}
if ( ! F_43 ( V_1 , 1 ) ) {
F_31 ( V_1 , L_20 ) ;
return 0 ;
}
F_44 ( V_1 , 1 ) ;
* V_37 = F_45 ( V_1 , V_17 ) ;
return 0 ;
}
int F_46 ( T_1 * V_1 ) {
F_47 ( V_1 ) ;
F_48 ( T_5 ) ;
return 1 ;
}
