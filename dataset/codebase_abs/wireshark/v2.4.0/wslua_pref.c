static T_1 * F_1 ( T_2 * V_1 , int V_2 )
{
double V_3 ;
const T_3 * V_4 , * V_5 ;
T_1 * V_6 , V_7 = { NULL , NULL , - 1 } ;
T_4 * V_8 = F_2 ( TRUE , TRUE , sizeof( T_1 ) ) ;
F_3 ( V_1 , V_2 , V_9 ) ;
F_4 ( V_1 ) ;
while ( F_5 ( V_1 , V_2 ) ) {
T_1 V_10 = { NULL , NULL , - 1 } ;
F_3 ( V_1 , - 1 , V_9 ) ;
F_4 ( V_1 ) ;
F_5 ( V_1 , - 2 ) ;
if ( ! F_6 ( V_1 , - 1 ) ) {
F_7 ( V_1 , V_2 , L_1 ) ;
F_8 ( V_8 , TRUE ) ;
return NULL ;
}
V_4 = F_9 ( V_1 , - 1 ) ;
F_10 ( V_1 , 1 ) ;
F_5 ( V_1 , - 2 ) ;
if ( ! F_6 ( V_1 , - 1 ) ) {
F_7 ( V_1 , V_2 , L_2 ) ;
F_8 ( V_8 , TRUE ) ;
return NULL ;
}
V_5 = F_9 ( V_1 , - 1 ) ;
F_10 ( V_1 , 1 ) ;
F_5 ( V_1 , - 2 ) ;
if ( ! F_11 ( V_1 , - 1 ) ) {
F_7 ( V_1 , V_2 , L_3 ) ;
F_8 ( V_8 , TRUE ) ;
return NULL ;
}
V_3 = F_12 ( V_1 , - 1 ) ;
V_10 . V_11 = F_13 ( V_4 ) ;
V_10 . V_12 = F_13 ( V_5 ) ;
V_10 . V_13 = ( V_14 ) V_3 ;
F_14 ( V_8 , V_10 ) ;
F_10 ( V_1 , 3 ) ;
}
F_14 ( V_8 , V_7 ) ;
V_6 = ( T_1 * ) ( void * ) V_8 -> V_15 ;
F_8 ( V_8 , FALSE ) ;
return V_6 ;
}
static int F_15 ( T_2 * V_1 , T_5 type ) {
const T_3 * V_16 = F_16 ( V_1 , 1 , NULL ) ;
const T_3 * V_17 = F_16 ( V_1 , 3 , L_4 ) ;
T_6 V_18 = ( V_19 * ) F_17 ( sizeof( V_19 ) ) ;
V_18 -> V_16 = F_13 ( V_16 ) ;
V_18 -> V_20 = F_13 ( V_17 ) ;
V_18 -> type = type ;
switch( type ) {
case V_21 : {
T_7 V_22 = F_18 ( V_1 , 2 ) ;
V_18 -> V_13 . V_23 = V_22 ;
break;
}
case V_24 : {
V_14 V_22 = F_19 ( V_1 , 2 , 0 ) ;
V_18 -> V_13 . V_25 = V_22 ;
break;
}
case V_26 : {
T_3 * V_22 = F_13 ( F_16 ( V_1 , 2 , L_4 ) ) ;
V_18 -> V_13 . V_27 = V_22 ;
V_18 -> V_28 . V_29 = V_22 ;
break;
}
case V_30 : {
V_14 V_22 = F_19 ( V_1 , 2 , 0 ) ;
T_1 * V_31 = F_1 ( V_1 , 4 ) ;
T_7 V_32 = F_18 ( V_1 , 5 ) ;
V_18 -> V_13 . V_10 = V_22 ;
V_18 -> V_28 . V_33 . V_34 = V_31 ;
V_18 -> V_28 . V_33 . V_35 = V_32 ;
break;
}
case V_36 : {
T_8 * V_37 = F_20 ( V_1 , 2 , 4 ) ;
V_14 V_38 = F_19 ( V_1 , 4 , 0 ) ;
V_18 -> V_13 . V_39 = V_37 ;
V_18 -> V_28 . V_40 = V_38 ;
break;
}
case V_41 : {
break;
}
default:
F_21 () ;
break;
}
F_22 ( V_1 , V_18 ) ;
return 1 ;
}
T_9 F_23 ( T_2 * V_1 ) {
#define F_24 1
#define F_25 2
#define F_26 3
return F_15 ( V_1 , V_21 ) ;
}
T_9 F_27 ( T_2 * V_1 ) {
#define F_28 1
#define F_29 2
#define F_30 3
return F_15 ( V_1 , V_24 ) ;
}
T_9 F_31 ( T_2 * V_1 ) {
#define F_32 1
#define F_33 2
#define F_34 3
return F_15 ( V_1 , V_26 ) ;
}
T_9 F_35 ( T_2 * V_1 ) {
#define F_36 1
#define F_37 2
#define F_38 3
#define F_39 4
#define F_40 5
return F_15 ( V_1 , V_30 ) ;
}
T_9 F_41 ( T_2 * V_1 ) {
#define F_42 1
#define F_43 2
#define F_44 3
#define F_45 4
return F_15 ( V_1 , V_36 ) ;
}
T_9 F_46 ( T_2 * V_1 ) {
#define F_47 1
#define F_48 2
return F_15 ( V_1 , V_41 ) ;
}
static T_8 * F_20 ( T_2 * V_1 , int V_42 , int V_43 )
{
static T_8 * V_6 = NULL ;
const T_3 * V_44 = F_49 ( V_1 , V_42 ) ;
switch ( F_50 ( F_51 () , & V_6 , V_44 , F_52 ( V_1 , V_43 ) ) ) {
case V_45 :
break;
case V_46 :
F_53 ( F_41 , DEFAULT , L_5 ) ;
return 0 ;
case V_47 :
F_53 ( F_41 , DEFAULT , L_6 ) ;
return 0 ;
default:
F_53 ( F_41 , DEFAULT , L_7 ) ;
return 0 ;
}
return V_6 ;
}
static int F_54 ( T_2 * V_1 ) {
T_6 V_18 = F_55 ( V_1 , 1 ) ;
if ( ! V_18 -> V_11 ) {
F_56 ( V_18 -> V_16 ) ;
F_56 ( V_18 -> V_20 ) ;
switch ( V_18 -> type ) {
case V_26 :
F_56 ( V_18 -> V_28 . V_29 ) ;
break;
case V_30 : {
const T_1 * V_48 = V_18 -> V_28 . V_33 . V_34 ;
while ( V_48 -> V_11 ) {
F_56 ( ( char * ) V_48 -> V_11 ) ;
F_56 ( ( char * ) V_48 -> V_12 ) ;
V_48 ++ ;
}
F_56 ( ( T_1 * ) V_18 -> V_28 . V_33 . V_34 ) ;
break;
}
default:
break;
}
F_56 ( V_18 ) ;
}
return 0 ;
}
T_10 F_57 ( T_2 * V_1 ) {
F_58 ( T_6 ) ;
return 0 ;
}
T_11 F_59 ( T_2 * V_1 ) {
#define F_60 2
#define F_61 3
T_6 V_49 = F_62 ( V_1 , 1 ) ;
const T_3 * V_11 = F_49 ( V_1 , F_60 ) ;
T_6 V_18 = F_63 ( V_1 , F_61 ) ;
T_6 V_50 ;
const T_3 * V_51 ;
if ( ! V_49 ) return 0 ;
if ( ! V_18 ) {
F_53 ( F_59 , V_52 , L_8 ) ;
return 0 ;
}
if ( V_18 -> V_11 ) {
F_53 ( F_59 , V_53 , L_9 ) ;
return 0 ;
}
if ( V_18 -> V_54 ) {
F_53 ( F_59 , V_52 , L_10 ) ;
return 0 ;
}
V_50 = V_49 ;
do {
if ( V_50 -> V_11 && F_64 ( V_50 -> V_11 , V_11 ) ) {
F_65 ( V_1 , L_11 , V_11 ) ;
return 0 ;
}
for ( V_51 = V_11 ; * V_51 != '\0' ; V_51 ++ ) {
if ( ! F_66 ( * V_51 ) && ! F_67 ( * V_51 ) && * V_51 != '_' && * V_51 != '.' )
{
F_65 ( V_1 , L_12
L_13 , V_11 ) ;
return 0 ;
}
}
if ( ! V_50 -> V_55 ) {
V_50 -> V_55 = V_18 ;
V_18 -> V_11 = F_13 ( V_11 ) ;
if ( ! V_18 -> V_16 )
V_18 -> V_16 = F_13 ( V_11 ) ;
if ( ! V_49 -> V_54 -> V_56 ) {
V_49 -> V_54 -> V_56 = F_68 ( V_49 -> V_54 -> V_57 ,
V_58 ) ;
}
switch( V_18 -> type ) {
case V_21 :
F_69 ( V_49 -> V_54 -> V_56 ,
V_18 -> V_11 ,
V_18 -> V_16 ,
V_18 -> V_20 ,
& ( V_18 -> V_13 . V_23 ) ) ;
break;
case V_24 :
F_70 ( V_49 -> V_54 -> V_56 ,
V_18 -> V_11 ,
V_18 -> V_16 ,
V_18 -> V_20 ,
10 ,
& ( V_18 -> V_13 . V_25 ) ) ;
break;
case V_26 :
F_71 ( V_49 -> V_54 -> V_56 ,
V_18 -> V_11 ,
V_18 -> V_16 ,
V_18 -> V_20 ,
( const char * * ) ( & ( V_18 -> V_13 . V_27 ) ) ) ;
F_56 ( V_18 -> V_28 . V_29 ) ;
V_18 -> V_28 . V_29 = NULL ;
break;
case V_30 :
F_72 ( V_49 -> V_54 -> V_56 ,
V_18 -> V_11 ,
V_18 -> V_16 ,
V_18 -> V_20 ,
& ( V_18 -> V_13 . V_10 ) ,
V_18 -> V_28 . V_33 . V_34 ,
V_18 -> V_28 . V_33 . V_35 ) ;
break;
case V_36 :
F_73 ( V_49 -> V_54 -> V_56 ,
V_18 -> V_11 ,
V_18 -> V_16 ,
V_18 -> V_20 ,
& ( V_18 -> V_13 . V_39 ) ,
V_18 -> V_28 . V_40 ) ;
break;
case V_41 :
F_74 ( V_49 -> V_54 -> V_56 ,
V_18 -> V_11 ,
V_18 -> V_16 ,
V_18 -> V_20 ) ;
break;
default:
F_75 ( F_59 , L_14 ) ;
break;
}
V_18 -> V_54 = V_50 -> V_54 ;
F_76 ( 0 ) ;
}
} while ( ( V_50 = V_50 -> V_55 ) );
F_65 ( V_1 , L_15 ) ;
F_76 ( 0 ) ;
}
T_11 F_77 ( T_2 * V_1 ) {
#define F_78 2
T_6 V_49 = F_62 ( V_1 , 1 ) ;
const T_3 * V_11 = F_49 ( V_1 , F_78 ) ;
if ( ! V_49 ) return 0 ;
if ( ! V_49 -> V_55 ) {
F_65 ( V_1 , L_16 ) ;
return 0 ;
}
V_49 = V_49 -> V_55 ;
do {
if ( F_64 ( V_49 -> V_11 , V_11 ) ) {
switch ( V_49 -> type ) {
case V_21 : F_79 ( V_1 , V_49 -> V_13 . V_23 ) ; break;
case V_24 : F_80 ( V_1 , ( V_59 ) V_49 -> V_13 . V_25 ) ; break;
case V_26 : F_81 ( V_1 , V_49 -> V_13 . V_27 ) ; break;
case V_30 : F_80 ( V_1 , ( V_59 ) V_49 -> V_13 . V_10 ) ; break;
case V_36 :
{
char * V_60 = F_82 ( NULL , V_49 -> V_13 . V_39 ) ;
F_81 ( V_1 , V_60 ) ;
F_83 ( NULL , V_60 ) ;
}
break;
default: F_75 ( F_77 , L_14 ) ; return 0 ;
}
F_76 ( 1 ) ;
}
} while ( ( V_49 = V_49 -> V_55 ) );
F_53 ( F_77 , V_53 , L_17 ) ;
return 0 ;
}
static int F_84 ( T_2 * V_1 V_61 ) {
return 0 ;
}
T_10 F_85 ( T_2 * V_1 ) {
F_86 ( V_62 ) ;
return 0 ;
}
