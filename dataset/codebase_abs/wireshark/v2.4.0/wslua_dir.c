T_1 F_1 ( T_2 * V_1 ) {
#define F_2 1
const char * V_2 = F_3 ( V_1 , F_2 ) ;
T_3 V_3 ;
int V_4 ;
if ( F_4 ( V_2 , & V_3 ) != 0 && V_5 == V_6 ) {
V_4 = F_5 ( V_2 , 0755 ) ;
if ( V_4 == - 1 ) {
F_6 ( V_1 ) ;
} else {
F_7 ( V_1 , 1 ) ;
}
} else {
F_7 ( V_1 , 0 ) ;
}
F_8 ( 1 ) ;
}
T_1 F_9 ( T_2 * V_1 ) {
#define F_10 1
const char * V_2 = F_3 ( V_1 , F_10 ) ;
int V_4 ;
if ( ( V_4 = F_11 ( V_2 ) ) == V_7 ) {
F_7 ( V_1 , 1 ) ;
} else {
if ( V_4 == 0 ) {
F_7 ( V_1 , 0 ) ;
} else {
F_6 ( V_1 ) ;
}
}
F_8 ( 1 ) ;
}
T_1 F_12 ( T_2 * V_1 ) {
#define F_13 1
const char * V_2 = F_3 ( V_1 , F_13 ) ;
int V_4 ;
if ( F_11 ( V_2 ) == V_7 ) {
V_4 = F_14 ( V_2 ) ;
if ( V_4 != 0 ) {
F_6 ( V_1 ) ;
} else {
F_7 ( V_1 , 1 ) ;
}
} else {
F_7 ( V_1 , 0 ) ;
}
F_8 ( 1 ) ;
}
static int F_15 ( const char * V_8 ) {
T_4 * V_9 ;
T_5 * V_10 ;
T_6 * V_11 ;
int V_4 = 0 ;
if ( ( V_9 = F_16 ( V_8 , 0 , NULL ) ) != NULL ) {
while ( ( V_10 = F_17 ( V_9 ) ) != NULL ) {
V_11 = F_18 ( L_1 , V_8 , V_12 ,
F_19 ( V_10 ) ) ;
if ( F_11 ( V_11 ) != V_7 ) {
V_4 = F_14 ( V_11 ) ;
} else {
V_4 = F_15 ( V_11 ) ;
}
if ( V_4 != 0 ) {
break;
}
F_20 ( V_11 ) ;
}
F_21 ( V_9 ) ;
}
if ( V_4 == 0 ) {
V_4 = F_14 ( V_8 ) ;
}
return V_4 ;
}
T_1 F_22 ( T_2 * V_1 ) {
#define F_23 1
const char * V_2 = F_3 ( V_1 , F_23 ) ;
int V_4 ;
if ( F_11 ( V_2 ) == V_7 ) {
V_4 = F_15 ( V_2 ) ;
if ( V_4 != 0 ) {
F_6 ( V_1 ) ;
} else {
F_7 ( V_1 , 1 ) ;
}
} else {
F_7 ( V_1 , 0 ) ;
}
F_8 ( 1 ) ;
}
T_1 F_24 ( T_2 * V_1 ) {
#define F_25 1
#define F_26 2
const char * V_13 = F_3 ( V_1 , F_25 ) ;
const char * V_14 = F_27 ( V_1 , F_26 , NULL ) ;
T_7 V_9 ;
char * V_15 ;
V_15 = F_28 ( V_13 ) ;
if ( ! V_15 ) {
F_29 ( F_24 , V_16 , L_2 ) ;
return 0 ;
}
if ( ! F_11 ( V_15 ) ) {
F_20 ( V_15 ) ;
F_29 ( F_24 , V_16 , L_3 ) ;
return 0 ;
}
V_9 = ( T_7 ) F_30 ( sizeof( struct V_17 ) ) ;
V_9 -> V_9 = F_31 ( V_15 , 0 , V_9 -> V_18 ) ;
F_20 ( V_15 ) ;
V_9 -> V_19 = V_14 ? F_32 ( V_14 ) : NULL ;
V_9 -> V_18 = ( V_20 * * ) F_30 ( sizeof( V_20 * ) ) ;
* ( V_9 -> V_18 ) = NULL ;
if ( V_9 -> V_9 == NULL ) {
F_20 ( V_9 -> V_18 ) ;
F_20 ( V_9 ) ;
F_29 ( F_24 , V_16 , L_4 ) ;
return 0 ;
}
F_33 ( V_1 , V_9 ) ;
F_8 ( 1 ) ;
}
T_8 F_34 ( T_2 * V_1 ) {
T_7 V_9 = F_35 ( V_1 , 1 ) ;
const T_6 * V_10 ;
const T_6 * V_11 ;
const char * V_19 ;
if ( ! V_9 -> V_9 ) {
return 0 ;
}
if ( ! ( V_10 = F_36 ( V_9 -> V_9 ) ) ) {
F_37 ( V_9 -> V_9 ) ;
V_9 -> V_9 = NULL ;
return 0 ;
}
if ( ! V_9 -> V_19 ) {
F_38 ( V_1 , V_10 ) ;
return 1 ;
}
do {
V_11 = V_10 ;
if ( ( V_19 = strstr ( V_11 , V_9 -> V_19 ) ) && F_39 ( V_19 , V_9 -> V_19 ) ) {
F_38 ( V_1 , V_11 ) ;
return 1 ;
}
} while( ( V_10 = F_36 ( V_9 -> V_9 ) ) );
F_37 ( V_9 -> V_9 ) ;
V_9 -> V_9 = NULL ;
return 0 ;
}
T_9 F_40 ( T_2 * V_1 ) {
T_7 V_9 = F_35 ( V_1 , 1 ) ;
if ( V_9 -> V_9 ) {
F_37 ( V_9 -> V_9 ) ;
V_9 -> V_9 = NULL ;
}
return 0 ;
}
T_1 F_41 ( T_2 * V_1 ) {
#define F_42 1
const char * V_21 = F_27 ( V_1 , F_42 , L_5 ) ;
char * V_11 = F_43 ( V_21 , FALSE ) ;
F_38 ( V_1 , V_11 ) ;
F_20 ( V_11 ) ;
F_8 ( 1 ) ;
}
T_1 F_44 ( T_2 * V_1 ) {
#define F_45 1
const char * V_21 = F_27 ( V_1 , F_45 , L_5 ) ;
char * V_11 ;
if ( F_46 () ) {
V_11 = F_18 ( L_6 V_12 L_7 V_12 L_8
V_12 L_6 , F_47 () , V_21 ) ;
if ( ( ! F_48 ( V_11 ) ) ) {
F_20 ( V_11 ) ;
V_11 = F_49 ( V_21 ) ;
}
} else {
V_11 = F_49 ( V_21 ) ;
}
F_38 ( V_1 , V_11 ) ;
F_20 ( V_11 ) ;
F_8 ( 1 ) ;
}
T_1 F_50 ( T_2 * V_1 ) {
char * V_11 = F_51 () ;
F_38 ( V_1 , V_11 ) ;
F_20 ( V_11 ) ;
F_8 ( 1 ) ;
}
T_1 F_52 ( T_2 * V_1 ) {
F_38 ( V_1 , F_53 () ) ;
F_8 ( 1 ) ;
}
static int F_54 ( T_2 * V_1 ) {
T_7 V_9 = F_55 ( V_1 , 1 ) ;
if( ! V_9 ) return 0 ;
if ( V_9 -> V_9 ) {
F_37 ( V_9 -> V_9 ) ;
}
F_20 ( V_9 -> V_18 ) ;
if ( V_9 -> V_19 ) F_20 ( V_9 -> V_19 ) ;
F_20 ( V_9 ) ;
return 0 ;
}
int F_56 ( T_2 * V_1 ) {
F_57 ( T_7 ) ;
return 0 ;
}
