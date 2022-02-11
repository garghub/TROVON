static enum V_1 F_1 ( const T_1 * type ) {
const T_2 * V_2 ;
for ( V_2 = V_3 ; V_2 -> V_4 ; V_2 ++ ) {
if ( F_2 ( V_2 -> V_4 , type ) ) {
return V_2 -> V_5 ;
}
}
return V_6 ;
}
static const T_1 * F_3 ( enum V_1 V_7 ) {
const T_2 * V_2 ;
for ( V_2 = V_3 ; V_2 -> V_4 ; V_2 ++ ) {
if ( V_2 -> V_5 == V_7 ) {
return V_2 -> V_4 ;
}
}
return NULL ;
}
static const T_1 * F_4 ( unsigned V_8 ) {
const struct V_9 * V_10 ;
for ( V_10 = V_11 ; V_10 -> V_4 ; V_10 ++ ) {
if ( V_8 == V_10 -> V_8 )
return V_10 -> V_4 ;
}
return NULL ;
}
static unsigned F_5 ( const T_1 * V_4 ) {
const struct V_9 * V_10 ;
for ( V_10 = V_11 ; V_10 -> V_4 ; V_10 ++ ) {
if ( F_2 ( V_4 , V_10 -> V_4 ) )
return V_10 -> V_8 ;
}
return V_12 ;
}
static T_3 * F_6 ( T_4 * V_13 , int V_14 ) {
T_5 * V_15 = F_7 ( TRUE , TRUE , sizeof( T_3 ) ) ;
T_3 * V_16 ;
if( F_8 ( V_13 , V_14 ) ) {
return NULL ;
} else if ( ! F_9 ( V_13 , V_14 ) ) {
F_10 ( V_13 , V_14 , L_1 ) ;
F_11 ( V_15 , TRUE ) ;
return NULL ;
}
F_12 ( V_13 ) ;
while ( F_13 ( V_13 , V_14 ) != 0 ) {
T_3 V_17 = { 0 , NULL } ;
if ( ! F_14 ( V_13 , - 2 ) ) {
F_10 ( V_13 , V_14 , L_2 ) ;
F_11 ( V_15 , TRUE ) ;
return NULL ;
}
if ( ! F_15 ( V_13 , - 1 ) ) {
F_10 ( V_13 , V_14 , L_3 ) ;
F_11 ( V_15 , TRUE ) ;
return NULL ;
}
V_17 . V_18 = F_16 ( V_13 , - 2 ) ;
V_17 . V_19 = F_17 ( F_18 ( V_13 , - 1 ) ) ;
F_19 ( V_15 , V_17 ) ;
F_20 ( V_13 , 1 ) ;
}
V_16 = ( T_3 * ) ( void * ) V_15 -> V_20 ;
F_11 ( V_15 , FALSE ) ;
return V_16 ;
}
static T_6 * F_21 ( T_4 * V_13 , int V_14 ) {
T_5 * V_15 = F_7 ( TRUE , TRUE , sizeof( T_6 ) ) ;
T_6 * V_16 ;
if( F_8 ( V_13 , V_14 ) ) {
return NULL ;
} else if ( ! F_9 ( V_13 , V_14 ) ) {
F_10 ( V_13 , V_14 , L_1 ) ;
F_11 ( V_15 , TRUE ) ;
return NULL ;
}
F_12 ( V_13 ) ;
while ( F_13 ( V_13 , V_14 ) != 0 ) {
T_6 V_17 = { 0 , NULL } ;
if ( ! F_14 ( V_13 , - 2 ) ) {
F_10 ( V_13 , V_14 , L_4 ) ;
F_11 ( V_15 , TRUE ) ;
return NULL ;
}
if ( ! F_15 ( V_13 , - 1 ) ) {
F_10 ( V_13 , V_14 , L_5 ) ;
F_11 ( V_15 , TRUE ) ;
return NULL ;
}
V_17 . V_18 = F_22 ( V_13 , - 2 ) ;
V_17 . V_19 = F_17 ( F_18 ( V_13 , - 1 ) ) ;
F_19 ( V_15 , V_17 ) ;
F_20 ( V_13 , 1 ) ;
}
V_16 = ( T_6 * ) ( void * ) V_15 -> V_20 ;
F_11 ( V_15 , FALSE ) ;
return V_16 ;
}
static T_7 * F_23 ( T_4 * V_13 , int V_14 ) {
T_5 * V_21 = F_7 ( TRUE , TRUE , sizeof( T_7 ) ) ;
T_7 * V_16 ;
T_7 V_22 = { F_17 ( L_6 ) , F_17 ( L_7 ) } ;
if ( F_8 ( V_13 , V_14 ) ) {
return NULL ;
} else if ( ! F_9 ( V_13 , V_14 ) ) {
F_10 ( V_13 , V_14 , L_1 ) ;
F_11 ( V_21 , TRUE ) ;
return NULL ;
}
F_12 ( V_13 ) ;
while ( F_13 ( V_13 , V_14 ) ) {
if ( ! F_14 ( V_13 , - 2 ) ) {
F_10 ( V_13 , V_14 , L_8 ) ;
F_11 ( V_21 , TRUE ) ;
return NULL ;
}
if ( ! F_15 ( V_13 , - 1 ) ) {
F_10 ( V_13 , V_14 , L_9 ) ;
F_11 ( V_21 , TRUE ) ;
return NULL ;
}
if ( F_24 ( V_13 , - 2 ) == 1 ) {
F_25 ( ( T_1 * ) V_22 . V_23 ) ;
V_22 . V_23 = F_17 ( F_18 ( V_13 , - 1 ) ) ;
}
if ( F_24 ( V_13 , - 2 ) == 2 ) {
F_25 ( ( T_1 * ) V_22 . V_24 ) ;
V_22 . V_24 = F_17 ( F_18 ( V_13 , - 1 ) ) ;
}
F_20 ( V_13 , 1 ) ;
}
F_19 ( V_21 , V_22 ) ;
V_16 = ( T_7 * ) ( void * ) V_21 -> V_20 ;
F_11 ( V_21 , FALSE ) ;
return V_16 ;
}
static const T_1 * F_26 ( T_4 * V_13 , const int V_25 , const enum V_1 type ) {
const T_1 * V_26 = F_27 ( V_13 , V_25 ) ;
const T_8 * V_27 = NULL ;
if ( ! V_26 [ 0 ] ) {
F_10 ( V_13 , V_25 , L_10 ) ;
return NULL ;
}
if ( F_28 ( V_26 ) ) {
F_10 ( V_13 , V_25 , L_11 ) ;
return NULL ;
}
V_27 = F_29 ( V_26 ) ;
if ( V_27 && ! F_30 ( type , V_27 -> type ) ) {
F_10 ( V_13 , V_25 , L_12 ) ;
return NULL ;
}
return V_26 ;
}
T_9 F_31 ( T_4 * V_13 ) {
#define F_32 1
#define F_33 2
#define F_34 3
#define F_35 4
#define F_36 5
#define F_37 6
#define F_38 7
T_10 V_28 ;
int V_29 = F_39 ( V_13 ) ;
const T_1 * V_30 = F_27 ( V_13 , F_32 ) ;
const T_1 * V_26 = NULL ;
enum V_1 type ;
enum V_31 V_32 = V_33 ;
T_3 * V_34 = NULL ;
T_6 * V_35 = NULL ;
T_7 * V_21 = NULL ;
unsigned V_8 ;
T_11 V_36 = F_40 ( V_13 , F_37 , 0x0 ) ;
const T_1 * V_37 = F_41 ( V_13 , F_38 , NULL ) ;
if ( ! V_30 [ 0 ] ) {
F_42 ( F_31 , V_38 , L_13 ) ;
return 0 ;
}
if ( F_14 ( V_13 , F_34 ) ) {
type = (enum V_1 ) F_43 ( V_13 , F_34 ) ;
} else {
type = F_1 ( F_27 ( V_13 , F_34 ) ) ;
}
V_26 = F_26 ( V_13 , F_33 , type ) ;
if ( F_14 ( V_13 , F_36 ) ) {
V_8 = ( unsigned ) F_44 ( V_13 , F_36 , V_12 ) ;
} else {
V_8 = F_5 ( F_41 ( V_13 , F_36 , L_14 ) ) ;
}
switch ( type ) {
case V_39 :
if ( V_8 != V_12 ) {
F_45 ( F_31 , V_40 , L_15 ) ;
return 0 ;
}
if ( V_36 ) {
F_45 ( F_31 , V_41 , L_16 ) ;
return 0 ;
}
if ( V_29 >= F_35 && ! F_8 ( V_13 , F_35 ) ) {
V_32 = (enum V_31 ) F_43 ( V_13 , 4 ) ;
if ( V_32 >= V_42 ) {
F_45 ( F_31 , V_43 , L_17 ) ;
return 0 ;
}
}
break;
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
if ( V_8 == V_12 ) {
V_8 = V_54 ;
} else if ( V_8 < V_54 || V_8 > V_55 ) {
F_45 ( F_31 , V_40 , L_18
L_19 ) ;
return 0 ;
}
if ( ( V_8 == V_56 || V_8 == V_57 ) &&
( type == V_49 || type == V_50 || type == V_51 || type == V_52 || type == V_53 ) )
{
F_45 ( F_31 , V_40 , L_20 ) ;
return 0 ;
}
if ( V_29 >= F_35 && ! F_8 ( V_13 , F_35 ) ) {
if ( type == V_48 || type == V_53 ) {
V_35 = F_21 ( V_13 , F_35 ) ;
} else {
V_34 = F_6 ( V_13 , F_35 ) ;
}
}
break;
case V_58 :
if ( V_36 == 0x0 && V_8 != V_12 ) {
F_45 ( F_31 , V_40 , L_21 ) ;
return 0 ;
}
if ( V_36 != 0x0 && ( V_8 < 1 || V_8 > 64 ) ) {
F_45 ( F_31 , V_40 , L_22 ) ;
return 0 ;
}
if ( V_29 >= F_35 && ! F_8 ( V_13 , F_35 ) ) {
V_21 = F_23 ( V_13 , F_35 ) ;
}
break;
case V_59 :
if ( V_8 == V_12 ) {
V_8 = V_60 ;
} else if ( V_8 < V_60 || V_8 > V_61 ) {
F_45 ( F_31 , V_40 , L_23 ) ;
return 0 ;
}
if ( V_36 ) {
F_45 ( F_31 , V_41 , L_24 ) ;
return 0 ;
}
break;
case V_6 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
if ( V_8 != V_12 ) {
F_45 ( F_31 , V_40 , L_25 ) ;
return 0 ;
}
if ( V_36 ) {
F_45 ( F_31 , V_41 , L_26 ) ;
return 0 ;
}
break;
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
default:
F_42 ( F_31 , TYPE , L_27 ) ;
break;
}
V_28 = F_46 ( V_91 , 1 ) ;
V_28 -> V_92 = - 2 ;
V_28 -> V_93 = - 1 ;
V_28 -> V_30 = F_17 ( V_30 ) ;
V_28 -> V_94 = F_17 ( V_26 ) ;
V_28 -> type = type ;
V_28 -> V_8 = V_8 ;
if ( V_21 ) {
V_28 -> V_15 = F_47 ( V_21 ) ;
} else if ( V_34 ) {
V_28 -> V_15 = F_48 ( V_34 ) ;
} else if ( V_35 ) {
V_28 -> V_8 |= V_95 ;
V_28 -> V_15 = F_48 ( V_35 ) ;
} else if ( V_32 ) {
V_28 -> V_15 = F_49 ( V_32 ) ;
} else {
V_28 -> V_15 = NULL ;
}
V_28 -> V_36 = V_36 ;
if ( V_37 && strcmp ( V_37 , V_28 -> V_30 ) != 0 ) {
V_28 -> V_37 = F_17 ( V_37 ) ;
} else {
V_28 -> V_37 = NULL ;
}
F_50 ( V_13 , V_28 ) ;
F_51 ( 1 ) ;
}
static int F_52 ( T_4 * V_13 , enum V_1 type ) {
T_10 V_28 ;
const T_1 * V_26 = F_26 ( V_13 , 1 , type ) ;
const T_1 * V_30 = F_41 ( V_13 , 2 , V_26 ) ;
unsigned V_96 = ( type == V_39 ) ? V_12 : V_54 ;
unsigned V_8 = ( unsigned ) F_44 ( V_13 , 3 , V_96 ) ;
enum V_31 V_32 = V_33 ;
T_3 * V_34 = NULL ;
T_6 * V_35 = NULL ;
T_11 V_36 = F_40 ( V_13 , 5 , 0 ) ;
const T_1 * V_37 = F_41 ( V_13 , 6 , NULL ) ;
if ( ! V_30 [ 0 ] ) {
F_10 ( V_13 , 2 , L_13 ) ;
return 0 ;
}
if ( F_39 ( V_13 ) > 3 && ! F_8 ( V_13 , 4 ) ) {
if ( type == V_39 ) {
V_32 = (enum V_31 ) F_43 ( V_13 , 4 ) ;
if ( V_32 >= V_42 ) {
F_10 ( V_13 , 4 , L_17 ) ;
return 0 ;
}
} else if ( type == V_48 || type == V_53 ) {
V_35 = F_21 ( V_13 , 4 ) ;
} else {
V_34 = F_6 ( V_13 , 4 ) ;
}
}
if ( type == V_39 ) {
if ( V_8 != V_12 )
F_10 ( V_13 , 3 , L_15 ) ;
else if ( V_36 )
F_10 ( V_13 , 5 , L_16 ) ;
} else if ( V_8 < V_54 || V_8 > V_55 ) {
F_10 ( V_13 , 3 , L_18
L_19 ) ;
return 0 ;
} else if ( ( V_8 == V_56 || V_8 == V_57 ) &&
( type == V_49 || type == V_50 || type == V_51 || type == V_52 || type == V_53 ) ) {
F_10 ( V_13 , 3 , L_20 ) ;
return 0 ;
}
V_28 = F_46 ( V_91 , 1 ) ;
V_28 -> V_92 = - 2 ;
V_28 -> V_93 = - 1 ;
V_28 -> V_30 = F_17 ( V_30 ) ;
V_28 -> V_94 = F_17 ( V_26 ) ;
V_28 -> type = type ;
V_28 -> V_8 = V_8 ;
if ( V_35 ) {
V_28 -> V_8 |= V_95 ;
V_28 -> V_15 = F_48 ( V_35 ) ;
} else if ( V_34 ) {
V_28 -> V_15 = F_48 ( V_34 ) ;
} else if ( V_32 ) {
V_28 -> V_15 = F_49 ( V_32 ) ;
} else {
V_28 -> V_15 = NULL ;
}
V_28 -> V_36 = V_36 ;
if ( V_37 && strcmp ( V_37 , V_28 -> V_30 ) != 0 ) {
V_28 -> V_37 = F_17 ( V_37 ) ;
} else {
V_28 -> V_37 = NULL ;
}
F_50 ( V_13 , V_28 ) ;
return 1 ;
}
static int F_53 ( T_4 * V_13 , enum V_1 type ) {
T_10 V_28 ;
const T_1 * V_26 = F_26 ( V_13 , 1 , type ) ;
const T_1 * V_30 = F_41 ( V_13 , 2 , V_26 ) ;
unsigned V_8 = ( unsigned ) F_44 ( V_13 , 3 , V_12 ) ;
T_7 * V_21 = NULL ;
T_11 V_36 = F_40 ( V_13 , 5 , 0 ) ;
const T_1 * V_37 = F_41 ( V_13 , 6 , NULL ) ;
if ( ! V_30 [ 0 ] ) {
F_10 ( V_13 , 2 , L_13 ) ;
return 0 ;
}
if ( V_36 == 0x0 && V_8 != V_12 ) {
F_10 ( V_13 , 3 , L_28
L_29 ) ;
return 0 ;
}
if ( V_36 != 0x0 && ( V_8 < 1 || V_8 > 64 ) ) {
F_10 ( V_13 , 3 , L_30
L_31 ) ;
return 0 ;
}
if ( F_39 ( V_13 ) > 3 && ! F_8 ( V_13 , 4 ) ) {
V_21 = F_23 ( V_13 , 4 ) ;
}
V_28 = F_46 ( V_91 , 1 ) ;
V_28 -> V_92 = - 2 ;
V_28 -> V_93 = - 1 ;
V_28 -> V_30 = F_17 ( V_30 ) ;
V_28 -> V_94 = F_17 ( V_26 ) ;
V_28 -> type = type ;
V_28 -> V_15 = F_47 ( V_21 ) ;
V_28 -> V_8 = V_8 ;
V_28 -> V_36 = V_36 ;
if ( V_37 && strcmp ( V_37 , V_28 -> V_30 ) != 0 ) {
V_28 -> V_37 = F_17 ( V_37 ) ;
} else {
V_28 -> V_37 = NULL ;
}
F_50 ( V_13 , V_28 ) ;
return 1 ;
}
static int F_54 ( T_4 * V_13 , enum V_1 type ) {
T_10 V_28 ;
const T_1 * V_26 = F_26 ( V_13 , 1 , type ) ;
const T_1 * V_30 = F_41 ( V_13 , 2 , V_26 ) ;
unsigned V_8 = ( unsigned ) F_44 ( V_13 , 3 , V_60 ) ;
const T_1 * V_37 = F_41 ( V_13 , 4 , NULL ) ;
if ( ! V_30 [ 0 ] ) {
F_10 ( V_13 , 2 , L_13 ) ;
return 0 ;
}
if ( type == V_59 ) {
if ( V_8 < V_60 || V_8 > V_61 ) {
F_10 ( V_13 , 3 , L_23 ) ;
return 0 ;
}
}
V_28 = F_46 ( V_91 , 1 ) ;
V_28 -> V_92 = - 2 ;
V_28 -> V_93 = - 1 ;
V_28 -> V_30 = F_17 ( V_30 ) ;
V_28 -> V_94 = F_17 ( V_26 ) ;
V_28 -> type = type ;
V_28 -> V_15 = NULL ;
V_28 -> V_8 = V_8 ;
V_28 -> V_36 = 0 ;
if ( V_37 && strcmp ( V_37 , V_28 -> V_30 ) != 0 ) {
V_28 -> V_37 = F_17 ( V_37 ) ;
} else {
V_28 -> V_37 = NULL ;
}
F_50 ( V_13 , V_28 ) ;
return 1 ;
}
static int F_55 ( T_4 * V_13 , enum V_1 type ) {
T_10 V_28 ;
const T_1 * V_26 = F_26 ( V_13 , 1 , type ) ;
const T_1 * V_30 = F_41 ( V_13 , 2 , V_26 ) ;
const T_1 * V_37 = F_41 ( V_13 , 3 , NULL ) ;
if ( ! V_30 [ 0 ] ) {
F_10 ( V_13 , 2 , L_13 ) ;
return 0 ;
}
V_28 = F_46 ( V_91 , 1 ) ;
V_28 -> V_92 = - 2 ;
V_28 -> V_93 = - 1 ;
V_28 -> V_30 = F_17 ( V_30 ) ;
V_28 -> V_94 = F_17 ( V_26 ) ;
V_28 -> type = type ;
V_28 -> V_15 = NULL ;
V_28 -> V_8 = V_12 ;
V_28 -> V_36 = 0 ;
if ( V_37 && strcmp ( V_37 , V_28 -> V_30 ) != 0 ) {
V_28 -> V_37 = F_17 ( V_37 ) ;
} else {
V_28 -> V_37 = NULL ;
}
F_50 ( V_13 , V_28 ) ;
return 1 ;
}
T_12 F_56 ( T_4 * V_13 ) {
T_10 V_28 = F_57 ( V_13 , 1 ) ;
T_1 * V_97 = F_58 ( L_32 ,
V_28 -> V_92 , V_28 -> V_30 , V_28 -> V_94 ,
F_3 ( V_28 -> type ) ,
F_4 ( V_28 -> V_8 ) ,
V_28 -> V_15 , V_28 -> V_36 , V_28 -> V_37 ) ;
F_59 ( V_13 , V_97 ) ;
F_25 ( V_97 ) ;
return 1 ;
}
static int F_60 ( T_4 * V_13 ) {
T_10 V_28 = F_61 ( V_13 , 1 ) ;
if ( V_28 -> V_92 == - 2 ) {
F_25 ( V_28 ) ;
}
return 0 ;
}
int F_62 ( T_4 * V_13 ) {
F_63 ( T_10 ) ;
return 0 ;
}
