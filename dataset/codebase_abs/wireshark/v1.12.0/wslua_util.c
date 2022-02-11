T_1 F_1 ( T_2 * V_1 ) {
const T_3 * V_2 = V_3 ;
F_2 ( V_1 , V_2 ) ;
F_3 ( 1 ) ;
}
T_1 F_4 ( T_2 * V_4 ) {
#define F_5 1
T_4 V_5 = F_6 ( V_4 , F_5 ) ;
T_5 V_6 ;
T_3 * V_2 ;
V_6 . V_7 = ( V_8 ) ( floor ( V_5 ) ) ;
V_6 . V_9 = ( V_8 ) ( ( V_5 - ( double ) ( V_6 . V_7 ) ) * 1000000000 ) ;
V_2 = F_7 ( & V_6 , V_10 , TRUE ) ;
F_2 ( V_4 , V_2 ) ;
F_3 ( 1 ) ;
}
T_1 F_8 ( T_2 * V_4 ) {
#define F_9 1
T_4 V_5 = F_6 ( V_4 , F_9 ) ;
T_5 V_6 ;
T_3 * V_2 ;
V_6 . V_7 = ( V_8 ) ( floor ( V_5 ) ) ;
V_6 . V_9 = ( V_8 ) ( ( V_5 - ( double ) ( V_6 . V_7 ) ) * 1000000000 ) ;
V_2 = F_10 ( & V_6 ) ;
F_2 ( V_4 , V_2 ) ;
F_3 ( 1 ) ;
}
T_1 F_11 ( T_2 * V_4 ) {
#define F_12 1
const T_3 * V_11 = F_13 ( V_4 , F_12 ) ;
F_14 ( L_1 , V_11 ) ;
return 0 ;
}
static int F_15 ( T_2 * V_1 , T_6 V_12 ) {
T_7 * V_2 = F_16 ( L_2 ) ;
int V_13 = F_17 ( V_1 ) ;
int V_14 ;
F_18 ( V_1 , L_3 ) ;
for ( V_14 = 1 ; V_14 <= V_13 ; V_14 ++ ) {
const char * V_11 ;
F_19 ( V_1 , - 1 ) ;
F_19 ( V_1 , V_14 ) ;
F_20 ( V_1 , 1 , 1 ) ;
V_11 = F_21 ( V_1 , - 1 ) ;
if ( V_11 == NULL )
return F_22 ( V_1 , L_4 ) ;
if ( V_14 > 1 ) F_23 ( V_2 , L_5 ) ;
F_23 ( V_2 , V_11 ) ;
F_24 ( V_1 , 1 ) ;
}
F_25 ( V_15 , V_12 , L_6 , V_2 -> V_2 ) ;
F_26 ( V_2 , TRUE ) ;
return 0 ;
}
T_1 F_27 ( T_2 * V_1 ) {
F_15 ( V_1 , V_16 ) ;
return 0 ;
}
T_1 F_28 ( T_2 * V_1 ) {
F_15 ( V_1 , V_17 ) ;
return 0 ;
}
T_1 F_29 ( T_2 * V_1 ) {
F_15 ( V_1 , V_18 ) ;
return 0 ;
}
T_1 F_30 ( T_2 * V_1 ) {
F_15 ( V_1 , V_19 ) ;
return 0 ;
}
T_1 F_31 ( T_2 * V_1 ) {
F_15 ( V_1 , V_20 ) ;
return 0 ;
}
char * F_32 ( const char * V_21 ) {
char V_22 [ 256 ] ;
char * V_23 ;
char * V_24 ;
F_33 ( V_22 , V_21 , 255 ) ;
V_22 [ 255 ] = '\0' ;
for( V_23 = V_22 ; * V_23 ; V_23 ++ ) {
switch( * V_23 ) {
case '/' : case '\\' :
* V_23 = * ( V_25 ) ;
break;
default:
break;
}
}
if ( F_34 ( V_22 ) ) {
return F_35 ( V_22 ) ;
}
V_24 = F_36 ( V_22 , FALSE ) ;
if ( F_34 ( V_24 ) ) {
return V_24 ;
}
F_37 ( V_24 ) ;
V_24 = F_38 ( V_22 ) ;
if ( F_34 ( V_24 ) ) {
return V_24 ;
}
F_37 ( V_24 ) ;
if ( F_39 () ) {
V_24 = F_40 ( L_1 V_25 L_7 V_25 L_8
V_25 L_1 , F_41 () , V_22 ) ;
if ( F_34 ( V_24 ) ) {
return V_24 ;
}
F_37 ( V_24 ) ;
}
return NULL ;
}
T_1 F_42 ( T_2 * V_1 ) {
#define F_43 1
const char * V_26 = F_13 ( V_1 , F_43 ) ;
char * V_24 ;
V_24 = F_32 ( V_26 ) ;
if ( ! V_24 ) {
F_44 ( V_27 , V_28 , L_9 ) ;
return 0 ;
}
if ( F_45 ( V_1 , V_24 ) == 0 ) {
F_37 ( V_24 ) ;
return 1 ;
} else {
F_37 ( V_24 ) ;
F_46 ( V_1 ) ;
F_47 ( V_1 , - 2 ) ;
return 2 ;
}
}
T_1 F_48 ( T_2 * V_1 ) {
#define F_49 1
const char * V_26 = F_13 ( V_1 , F_49 ) ;
char * V_24 ;
int V_13 ;
if ( ! V_26 ) {
F_44 ( V_29 , V_28 , L_10 ) ;
return 0 ;
}
V_24 = F_32 ( V_26 ) ;
if ( ! V_24 ) {
F_44 ( V_29 , V_28 , L_9 ) ;
return 0 ;
}
V_13 = F_17 ( V_1 ) ;
if ( F_45 ( V_1 , V_24 ) != 0 ) F_50 ( V_1 ) ;
F_37 ( V_24 ) ;
F_20 ( V_1 , 0 , V_30 ) ;
return F_17 ( V_1 ) - V_13 ;
}
static int F_51 ( T_2 * V_1 V_31 ) {
return 0 ;
}
static void F_52 ( const char * V_32 , void * V_33 ) {
T_8 * V_34 = ( T_8 * ) V_33 ;
T_2 * V_1 = V_34 -> V_1 ;
F_53 ( V_1 , 0 ) ;
F_54 ( V_1 , F_51 ) ;
F_55 ( V_1 , V_35 , V_34 -> V_36 ) ;
F_2 ( V_1 , V_32 ) ;
switch ( F_56 ( V_1 , 1 , 0 , 1 ) ) {
case 0 :
break;
case V_37 :
F_57 ( L_11 ) ;
break;
case V_38 :
F_57 ( L_12 ) ;
break;
default:
F_58 () ;
break;
}
}
T_1 F_59 ( T_2 * V_1 ) {
#define F_60 1
#define F_61 2
const char * V_39 = F_13 ( V_1 , F_60 ) ;
T_8 * V_34 = ( T_8 * ) F_62 ( sizeof( T_8 ) ) ;
V_34 -> V_1 = V_1 ;
F_19 ( V_1 , F_61 ) ;
V_34 -> V_36 = F_63 ( V_1 , V_35 ) ;
F_64 ( V_1 , 1 ) ;
F_65 ( V_39 , F_52 , V_34 ) ;
return 0 ;
}
