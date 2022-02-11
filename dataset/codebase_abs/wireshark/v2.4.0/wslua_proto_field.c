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
T_5 * V_15 ;
T_3 * V_16 ;
if ( F_7 ( V_13 , V_14 ) ) {
return NULL ;
} else if ( ! F_8 ( V_13 , V_14 ) ) {
F_9 ( V_13 , V_14 , L_1 ) ;
return NULL ;
}
V_15 = F_10 ( TRUE , TRUE , sizeof( T_3 ) ) ;
F_11 ( V_13 ) ;
while ( F_12 ( V_13 , V_14 ) != 0 ) {
T_3 V_17 = { 0 , NULL } ;
if ( ! F_13 ( V_13 , - 2 ) ) {
V_16 = ( T_3 * ) ( void * ) V_15 -> V_18 ;
while ( V_16 -> V_19 ) {
F_14 ( ( T_1 * ) V_16 -> V_19 ) ;
V_16 ++ ;
}
F_15 ( V_15 , TRUE ) ;
F_9 ( V_13 , V_14 , L_2 ) ;
return NULL ;
}
if ( ! F_16 ( V_13 , - 1 ) ) {
V_16 = ( T_3 * ) ( void * ) V_15 -> V_18 ;
while ( V_16 -> V_19 ) {
F_14 ( ( T_1 * ) V_16 -> V_19 ) ;
V_16 ++ ;
}
F_15 ( V_15 , TRUE ) ;
F_9 ( V_13 , V_14 , L_3 ) ;
return NULL ;
}
V_17 . V_20 = F_17 ( V_13 , - 2 ) ;
V_17 . V_19 = F_18 ( F_19 ( V_13 , - 1 ) ) ;
F_20 ( V_15 , V_17 ) ;
F_21 ( V_13 , 1 ) ;
}
V_16 = ( T_3 * ) ( void * ) V_15 -> V_18 ;
F_15 ( V_15 , FALSE ) ;
return V_16 ;
}
static T_6 * F_22 ( T_4 * V_13 , int V_14 ) {
T_5 * V_15 ;
T_6 * V_21 ;
if ( F_7 ( V_13 , V_14 ) ) {
return NULL ;
} else if ( ! F_8 ( V_13 , V_14 ) ) {
F_9 ( V_13 , V_14 , L_1 ) ;
return NULL ;
}
V_15 = F_10 ( TRUE , TRUE , sizeof( T_6 ) ) ;
F_11 ( V_13 ) ;
while ( F_12 ( V_13 , V_14 ) != 0 ) {
T_6 V_17 = { 0 , NULL } ;
if ( ! F_13 ( V_13 , - 2 ) ) {
V_21 = ( T_6 * ) ( void * ) V_15 -> V_18 ;
while ( V_21 -> V_19 ) {
F_14 ( ( T_1 * ) V_21 -> V_19 ) ;
V_21 ++ ;
}
F_15 ( V_15 , TRUE ) ;
F_9 ( V_13 , V_14 , L_4 ) ;
return NULL ;
}
if ( ! F_16 ( V_13 , - 1 ) ) {
V_21 = ( T_6 * ) ( void * ) V_15 -> V_18 ;
while ( V_21 -> V_19 ) {
F_14 ( ( T_1 * ) V_21 -> V_19 ) ;
V_21 ++ ;
}
F_15 ( V_15 , TRUE ) ;
F_9 ( V_13 , V_14 , L_5 ) ;
return NULL ;
}
V_17 . V_20 = F_23 ( V_13 , - 2 ) ;
V_17 . V_19 = F_18 ( F_19 ( V_13 , - 1 ) ) ;
F_20 ( V_15 , V_17 ) ;
F_21 ( V_13 , 1 ) ;
}
V_21 = ( T_6 * ) ( void * ) V_15 -> V_18 ;
F_15 ( V_15 , FALSE ) ;
return V_21 ;
}
static T_7 * F_24 ( T_4 * V_13 , int V_14 ) {
T_7 * V_22 ;
if ( F_7 ( V_13 , V_14 ) ) {
return NULL ;
} else if ( ! F_8 ( V_13 , V_14 ) ) {
F_9 ( V_13 , V_14 , L_1 ) ;
return NULL ;
}
V_22 = ( T_7 * ) F_25 ( sizeof( T_7 ) ) ;
V_22 -> V_23 = F_18 ( L_6 ) ;
V_22 -> V_24 = F_18 ( L_7 ) ;
F_11 ( V_13 ) ;
while ( F_12 ( V_13 , V_14 ) ) {
if ( ! F_13 ( V_13 , - 2 ) ) {
F_14 ( ( T_1 * ) V_22 -> V_23 ) ;
F_14 ( ( T_1 * ) V_22 -> V_24 ) ;
F_14 ( V_22 ) ;
F_9 ( V_13 , V_14 , L_8 ) ;
return NULL ;
}
if ( ! F_16 ( V_13 , - 1 ) ) {
F_14 ( ( T_1 * ) V_22 -> V_23 ) ;
F_14 ( ( T_1 * ) V_22 -> V_24 ) ;
F_14 ( V_22 ) ;
F_9 ( V_13 , V_14 , L_9 ) ;
return NULL ;
}
switch ( F_26 ( V_13 , - 2 ) ) {
case 1 :
F_14 ( ( T_1 * ) V_22 -> V_23 ) ;
V_22 -> V_23 = F_18 ( F_19 ( V_13 , - 1 ) ) ;
break;
case 2 :
F_14 ( ( T_1 * ) V_22 -> V_24 ) ;
V_22 -> V_24 = F_18 ( F_19 ( V_13 , - 1 ) ) ;
break;
default:
F_14 ( ( T_1 * ) V_22 -> V_23 ) ;
F_14 ( ( T_1 * ) V_22 -> V_24 ) ;
F_14 ( V_22 ) ;
F_9 ( V_13 , V_14 , L_10 ) ;
return NULL ;
}
F_21 ( V_13 , 1 ) ;
}
return V_22 ;
}
static T_8 * F_27 ( T_4 * V_13 , int V_14 ) {
T_8 * V_25 ;
if ( F_7 ( V_13 , V_14 ) ) {
return NULL ;
} else if ( ! F_8 ( V_13 , V_14 ) ) {
F_9 ( V_13 , V_14 , L_1 ) ;
return NULL ;
}
V_25 = ( T_8 * ) F_28 ( sizeof( T_8 ) ) ;
F_11 ( V_13 ) ;
while ( F_12 ( V_13 , V_14 ) ) {
if ( ! F_13 ( V_13 , - 2 ) ) {
F_14 ( V_25 -> V_26 ) ;
F_14 ( V_25 -> V_27 ) ;
F_14 ( V_25 ) ;
F_9 ( V_13 , V_14 , L_11 ) ;
return NULL ;
}
if ( ! F_16 ( V_13 , - 1 ) ) {
F_14 ( V_25 -> V_26 ) ;
F_14 ( V_25 -> V_27 ) ;
F_14 ( V_25 ) ;
F_9 ( V_13 , V_14 , L_12 ) ;
return NULL ;
}
switch ( F_26 ( V_13 , - 2 ) ) {
case 1 :
F_14 ( ( T_1 * ) V_25 -> V_26 ) ;
V_25 -> V_26 = F_18 ( F_19 ( V_13 , - 1 ) ) ;
break;
case 2 :
F_14 ( ( T_1 * ) V_25 -> V_27 ) ;
V_25 -> V_27 = F_18 ( F_19 ( V_13 , - 1 ) ) ;
break;
default:
F_14 ( V_25 -> V_26 ) ;
F_14 ( V_25 -> V_27 ) ;
F_14 ( V_25 ) ;
F_9 ( V_13 , V_14 , L_13 ) ;
return NULL ;
}
F_21 ( V_13 , 1 ) ;
}
if ( ! V_25 -> V_26 ) {
F_14 ( V_25 -> V_27 ) ;
F_14 ( V_25 ) ;
F_9 ( V_13 , V_14 , L_14 ) ;
return NULL ;
}
return V_25 ;
}
static const T_1 * F_29 ( T_4 * V_13 , const int V_28 , const enum V_1 type ) {
const T_1 * V_29 = F_30 ( V_13 , V_28 ) ;
const T_9 * V_30 = NULL ;
if ( ! V_29 [ 0 ] ) {
F_9 ( V_13 , V_28 , L_15 ) ;
return NULL ;
}
if ( F_31 ( V_29 ) ) {
F_9 ( V_13 , V_28 , L_16 ) ;
return NULL ;
}
V_30 = F_32 ( V_29 ) ;
if ( V_30 && ! F_33 ( type , V_30 -> type ) ) {
F_9 ( V_13 , V_28 , L_17 ) ;
return NULL ;
}
return V_29 ;
}
T_10 F_34 ( T_4 * V_13 ) {
#define F_35 1
#define F_36 2
#define F_37 3
#define F_38 4
#define F_39 5
#define F_40 6
#define F_41 7
T_11 V_31 ;
int V_32 = F_42 ( V_13 ) ;
const T_1 * V_33 = F_30 ( V_13 , F_35 ) ;
const T_1 * V_29 = NULL ;
enum V_1 type ;
enum V_34 V_35 = V_36 ;
T_3 * V_16 = NULL ;
T_6 * V_21 = NULL ;
T_7 * V_22 = NULL ;
T_8 * V_37 = NULL ;
unsigned V_8 ;
T_12 V_38 = F_43 ( V_13 , F_40 , 0x0 ) ;
const T_1 * V_39 = F_44 ( V_13 , F_41 , NULL ) ;
T_13 V_40 = FALSE ;
if ( ! V_33 [ 0 ] ) {
F_45 ( F_34 , V_41 , L_18 ) ;
return 0 ;
}
if ( F_13 ( V_13 , F_37 ) ) {
type = (enum V_1 ) F_46 ( V_13 , F_37 ) ;
} else {
type = F_1 ( F_30 ( V_13 , F_37 ) ) ;
}
V_29 = F_29 ( V_13 , F_36 , type ) ;
if ( F_13 ( V_13 , F_39 ) ) {
V_8 = ( unsigned ) F_47 ( V_13 , F_39 , V_12 ) ;
} else {
V_8 = F_5 ( F_44 ( V_13 , F_39 , L_19 ) ) ;
}
switch ( type ) {
case V_42 :
if ( V_8 != V_12 ) {
F_48 ( F_34 , V_43 , L_20 ) ;
return 0 ;
}
if ( V_38 ) {
F_48 ( F_34 , V_44 , L_21 ) ;
return 0 ;
}
if ( V_32 >= F_38 && ! F_7 ( V_13 , F_38 ) ) {
V_35 = (enum V_34 ) F_46 ( V_13 , 4 ) ;
if ( V_35 >= V_45 ) {
F_48 ( F_34 , V_46 , L_22 ) ;
return 0 ;
}
}
break;
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
if ( type != V_47 && V_8 & V_58 ) {
V_40 = TRUE ;
V_8 &= ~ V_58 ;
}
if ( V_8 == V_12 ) {
if ( type == V_47 )
V_8 = V_59 ;
else
V_8 = V_60 ;
}
if ( ( V_8 != V_60 ) &&
( type == V_53 || type == V_54 || type == V_55 || type == V_56 || type == V_57 ) )
{
F_48 ( F_34 , V_43 , L_23 ) ;
return 0 ;
} else if ( V_8 < V_60 || V_8 > V_61 ) {
F_48 ( F_34 , V_43 , L_24
L_25 ) ;
return 0 ;
}
if ( V_32 >= F_38 ) {
if ( V_40 ) {
V_37 = F_27 ( V_13 , F_38 ) ;
} else if ( type == V_52 || type == V_57 ) {
V_21 = F_22 ( V_13 , F_38 ) ;
} else {
V_16 = F_6 ( V_13 , F_38 ) ;
}
}
break;
case V_62 :
if ( V_38 == 0x0 && V_8 != V_12 ) {
F_48 ( F_34 , V_43 , L_26 ) ;
return 0 ;
}
if ( V_38 != 0x0 && ( V_8 < 1 || V_8 > 64 ) ) {
F_48 ( F_34 , V_43 , L_27 ) ;
return 0 ;
}
if ( V_32 >= F_38 && ! F_7 ( V_13 , F_38 ) ) {
V_22 = F_24 ( V_13 , F_38 ) ;
}
break;
case V_63 :
if ( V_8 == V_12 ) {
V_8 = V_64 ;
} else if ( V_8 < V_64 || V_8 > V_65 ) {
F_48 ( F_34 , V_43 , L_28 ) ;
return 0 ;
}
if ( V_38 ) {
F_48 ( F_34 , V_44 , L_29 ) ;
return 0 ;
}
break;
case V_66 :
case V_67 :
if ( V_8 != V_68 && V_8 != V_69 ) {
F_48 ( F_34 , V_43 , L_30 ) ;
return 0 ;
}
if ( V_38 ) {
F_48 ( F_34 , V_44 , L_31 ) ;
return 0 ;
}
break;
case V_70 :
case V_71 :
if ( V_8 != V_12 && ( V_8 < V_72 || V_8 > V_73 ) ) {
F_48 ( F_34 , V_43 , L_32 ) ;
return 0 ;
}
if ( V_38 ) {
F_48 ( F_34 , V_44 , L_31 ) ;
return 0 ;
}
break;
case V_74 :
case V_75 :
if ( V_8 & V_58 ) {
V_40 = TRUE ;
V_8 &= ~ V_58 ;
}
if ( V_32 >= F_38 ) {
V_37 = F_27 ( V_13 , F_38 ) ;
}
case V_6 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
if ( V_8 != V_12 ) {
F_48 ( F_34 , V_43 , L_33 ) ;
return 0 ;
}
if ( V_38 ) {
F_48 ( F_34 , V_44 , L_31 ) ;
return 0 ;
}
break;
case V_89 :
case V_90 :
case V_91 :
case V_92 :
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
F_45 ( F_34 , TYPE , L_34 ) ;
break;
case V_100 :
default:
F_45 ( F_34 , TYPE , L_35 ) ;
break;
}
if ( V_40 && ! V_37 ) {
F_48 ( F_34 , V_46 , L_36 ) ;
return 0 ;
}
V_31 = F_49 ( V_101 , 1 ) ;
V_31 -> V_102 = - 2 ;
V_31 -> V_103 = - 1 ;
V_31 -> V_33 = F_18 ( V_33 ) ;
V_31 -> V_104 = F_18 ( V_29 ) ;
V_31 -> type = type ;
V_31 -> V_8 = V_8 ;
if ( V_22 ) {
V_31 -> V_15 = F_50 ( V_22 ) ;
} else if ( V_16 ) {
V_31 -> V_15 = F_51 ( V_16 ) ;
} else if ( V_21 ) {
V_31 -> V_8 |= V_105 ;
V_31 -> V_15 = F_51 ( V_21 ) ;
} else if ( V_37 ) {
V_31 -> V_8 |= V_58 ;
V_31 -> V_15 = V_37 ;
} else if ( V_35 ) {
V_31 -> V_15 = F_52 ( V_35 ) ;
} else {
V_31 -> V_15 = NULL ;
}
V_31 -> V_38 = V_38 ;
if ( V_39 && strcmp ( V_39 , V_31 -> V_33 ) != 0 ) {
V_31 -> V_39 = F_18 ( V_39 ) ;
} else {
V_31 -> V_39 = NULL ;
}
F_53 ( V_13 , V_31 ) ;
F_54 ( 1 ) ;
}
static int F_55 ( T_4 * V_13 , enum V_1 type ) {
T_11 V_31 ;
const T_1 * V_29 = F_29 ( V_13 , 1 , type ) ;
const T_1 * V_33 = F_44 ( V_13 , 2 , V_29 ) ;
unsigned V_106 = ( type == V_42 ) ? V_12 : V_60 ;
unsigned V_8 = ( unsigned ) F_47 ( V_13 , 3 , V_106 ) ;
enum V_34 V_35 = V_36 ;
T_3 * V_16 = NULL ;
T_6 * V_21 = NULL ;
T_8 * V_37 = NULL ;
T_12 V_38 = F_43 ( V_13 , 5 , 0 ) ;
const T_1 * V_39 = F_44 ( V_13 , 6 , NULL ) ;
T_13 V_40 = FALSE ;
if ( ! V_33 [ 0 ] ) {
F_9 ( V_13 , 2 , L_18 ) ;
return 0 ;
}
if ( V_8 & V_58 ) {
V_40 = TRUE ;
V_8 &= ~ V_58 ;
if ( V_8 == V_12 ) {
V_8 = V_60 ;
}
}
if ( F_42 ( V_13 ) > 3 && ! F_7 ( V_13 , 4 ) ) {
if ( type == V_42 ) {
V_35 = (enum V_34 ) F_46 ( V_13 , 4 ) ;
if ( V_35 >= V_45 ) {
F_9 ( V_13 , 4 , L_22 ) ;
return 0 ;
}
} else if ( V_40 ) {
V_37 = F_27 ( V_13 , 4 ) ;
} else if ( type == V_52 || type == V_57 ) {
V_21 = F_22 ( V_13 , 4 ) ;
} else {
V_16 = F_6 ( V_13 , 4 ) ;
}
}
if ( type == V_42 ) {
if ( V_8 != V_12 )
F_9 ( V_13 , 3 , L_20 ) ;
else if ( V_38 )
F_9 ( V_13 , 5 , L_21 ) ;
} else if ( ( V_8 != V_60 ) &&
( type == V_53 || type == V_54 || type == V_55 || type == V_56 || type == V_57 ) ) {
F_9 ( V_13 , 3 , L_23 ) ;
return 0 ;
} else if ( V_8 < V_60 || V_8 > V_61 ) {
F_9 ( V_13 , 3 , L_24
L_25 ) ;
return 0 ;
}
if ( V_40 && ! V_37 ) {
F_9 ( V_13 , 4 , L_36 ) ;
return 0 ;
}
V_31 = F_49 ( V_101 , 1 ) ;
V_31 -> V_102 = - 2 ;
V_31 -> V_103 = - 1 ;
V_31 -> V_33 = F_18 ( V_33 ) ;
V_31 -> V_104 = F_18 ( V_29 ) ;
V_31 -> type = type ;
V_31 -> V_8 = V_8 ;
if ( V_21 ) {
V_31 -> V_8 |= V_105 ;
V_31 -> V_15 = F_51 ( V_21 ) ;
} else if ( V_16 ) {
V_31 -> V_15 = F_51 ( V_16 ) ;
} else if ( V_37 ) {
V_31 -> V_8 |= V_58 ;
V_31 -> V_15 = V_37 ;
} else if ( V_35 ) {
V_31 -> V_15 = F_52 ( V_35 ) ;
} else {
V_31 -> V_15 = NULL ;
}
V_31 -> V_38 = V_38 ;
if ( V_39 && strcmp ( V_39 , V_31 -> V_33 ) != 0 ) {
V_31 -> V_39 = F_18 ( V_39 ) ;
} else {
V_31 -> V_39 = NULL ;
}
F_53 ( V_13 , V_31 ) ;
return 1 ;
}
static int F_56 ( T_4 * V_13 , enum V_1 type ) {
T_11 V_31 ;
const T_1 * V_29 = F_29 ( V_13 , 1 , type ) ;
const T_1 * V_33 = F_44 ( V_13 , 2 , V_29 ) ;
unsigned V_8 = ( unsigned ) F_47 ( V_13 , 3 , V_12 ) ;
T_7 * V_22 = NULL ;
T_12 V_38 = F_43 ( V_13 , 5 , 0 ) ;
const T_1 * V_39 = F_44 ( V_13 , 6 , NULL ) ;
if ( ! V_33 [ 0 ] ) {
F_9 ( V_13 , 2 , L_18 ) ;
return 0 ;
}
if ( V_38 == 0x0 && V_8 != V_12 ) {
F_9 ( V_13 , 3 , L_37
L_38 ) ;
return 0 ;
}
if ( V_38 != 0x0 && ( V_8 < 1 || V_8 > 64 ) ) {
F_9 ( V_13 , 3 , L_39
L_40 ) ;
return 0 ;
}
if ( F_42 ( V_13 ) > 3 && ! F_7 ( V_13 , 4 ) ) {
V_22 = F_24 ( V_13 , 4 ) ;
}
V_31 = F_49 ( V_101 , 1 ) ;
V_31 -> V_102 = - 2 ;
V_31 -> V_103 = - 1 ;
V_31 -> V_33 = F_18 ( V_33 ) ;
V_31 -> V_104 = F_18 ( V_29 ) ;
V_31 -> type = type ;
V_31 -> V_15 = F_50 ( V_22 ) ;
V_31 -> V_8 = V_8 ;
V_31 -> V_38 = V_38 ;
if ( V_39 && strcmp ( V_39 , V_31 -> V_33 ) != 0 ) {
V_31 -> V_39 = F_18 ( V_39 ) ;
} else {
V_31 -> V_39 = NULL ;
}
F_53 ( V_13 , V_31 ) ;
return 1 ;
}
static int F_57 ( T_4 * V_13 , enum V_1 type ) {
T_11 V_31 ;
const T_1 * V_29 = F_29 ( V_13 , 1 , type ) ;
const T_1 * V_33 = F_44 ( V_13 , 2 , V_29 ) ;
unsigned V_8 = ( unsigned ) F_47 ( V_13 , 3 , V_64 ) ;
const T_1 * V_39 = F_44 ( V_13 , 4 , NULL ) ;
if ( ! V_33 [ 0 ] ) {
F_9 ( V_13 , 2 , L_18 ) ;
return 0 ;
}
if ( type == V_63 ) {
if ( V_8 < V_64 || V_8 > V_65 ) {
F_9 ( V_13 , 3 , L_28 ) ;
return 0 ;
}
}
V_31 = F_49 ( V_101 , 1 ) ;
V_31 -> V_102 = - 2 ;
V_31 -> V_103 = - 1 ;
V_31 -> V_33 = F_18 ( V_33 ) ;
V_31 -> V_104 = F_18 ( V_29 ) ;
V_31 -> type = type ;
V_31 -> V_15 = NULL ;
V_31 -> V_8 = V_8 ;
V_31 -> V_38 = 0 ;
if ( V_39 && strcmp ( V_39 , V_31 -> V_33 ) != 0 ) {
V_31 -> V_39 = F_18 ( V_39 ) ;
} else {
V_31 -> V_39 = NULL ;
}
F_53 ( V_13 , V_31 ) ;
return 1 ;
}
static int F_58 ( T_4 * V_13 , enum V_1 type ) {
T_11 V_31 ;
const T_1 * V_29 = F_29 ( V_13 , 1 , type ) ;
const T_1 * V_33 = F_44 ( V_13 , 2 , V_29 ) ;
T_8 * V_37 = NULL ;
const T_1 * V_39 ;
if ( ! V_33 [ 0 ] ) {
F_9 ( V_13 , 2 , L_18 ) ;
return 0 ;
}
if ( F_8 ( V_13 , 3 ) ) {
V_37 = F_27 ( V_13 , 3 ) ;
V_39 = F_44 ( V_13 , 4 , NULL ) ;
} else {
V_39 = F_44 ( V_13 , 3 , NULL ) ;
}
V_31 = F_49 ( V_101 , 1 ) ;
V_31 -> V_102 = - 2 ;
V_31 -> V_103 = - 1 ;
V_31 -> V_33 = F_18 ( V_33 ) ;
V_31 -> V_104 = F_18 ( V_29 ) ;
V_31 -> type = type ;
if ( V_37 ) {
V_31 -> V_15 = V_37 ;
V_31 -> V_8 = V_12 | V_58 ;
} else {
V_31 -> V_15 = NULL ;
V_31 -> V_8 = V_12 ;
}
V_31 -> V_38 = 0 ;
if ( V_39 && strcmp ( V_39 , V_31 -> V_33 ) != 0 ) {
V_31 -> V_39 = F_18 ( V_39 ) ;
} else {
V_31 -> V_39 = NULL ;
}
F_53 ( V_13 , V_31 ) ;
return 1 ;
}
static int F_59 ( T_4 * V_13 , enum V_1 type ) {
T_11 V_31 ;
const T_1 * V_29 = F_29 ( V_13 , 1 , type ) ;
const T_1 * V_33 = F_44 ( V_13 , 2 , V_29 ) ;
unsigned V_8 = V_12 ;
const T_1 * V_39 ;
if ( ! V_33 [ 0 ] ) {
F_9 ( V_13 , 2 , L_18 ) ;
return 0 ;
}
if ( F_13 ( V_13 , 3 ) ) {
V_8 = ( unsigned ) F_47 ( V_13 , 3 , V_12 ) ;
if ( type == V_66 || type == V_67 ) {
if ( V_8 != V_68 && V_8 != V_69 ) {
F_9 ( V_13 , 3 , L_30 ) ;
return 0 ;
}
} else if ( type == V_70 || type == V_71 ) {
if ( V_8 != V_12 && ( V_8 < V_72 || V_8 > V_73 ) ) {
F_9 ( V_13 , 3 , L_32 ) ;
return 0 ;
}
}
V_39 = F_44 ( V_13 , 4 , NULL ) ;
} else {
V_39 = F_44 ( V_13 , 3 , NULL ) ;
}
V_31 = F_49 ( V_101 , 1 ) ;
V_31 -> V_102 = - 2 ;
V_31 -> V_103 = - 1 ;
V_31 -> V_33 = F_18 ( V_33 ) ;
V_31 -> V_104 = F_18 ( V_29 ) ;
V_31 -> type = type ;
V_31 -> V_15 = NULL ;
V_31 -> V_8 = V_8 ;
V_31 -> V_38 = 0 ;
if ( V_39 && strcmp ( V_39 , V_31 -> V_33 ) != 0 ) {
V_31 -> V_39 = F_18 ( V_39 ) ;
} else {
V_31 -> V_39 = NULL ;
}
F_53 ( V_13 , V_31 ) ;
return 1 ;
}
static int F_60 ( T_4 * V_13 , enum V_1 type ) {
T_11 V_31 ;
const T_1 * V_29 = F_29 ( V_13 , 1 , type ) ;
const T_1 * V_33 = F_44 ( V_13 , 2 , V_29 ) ;
const T_1 * V_39 = F_44 ( V_13 , 3 , NULL ) ;
if ( ! V_33 [ 0 ] ) {
F_9 ( V_13 , 2 , L_18 ) ;
return 0 ;
}
V_31 = F_49 ( V_101 , 1 ) ;
V_31 -> V_102 = - 2 ;
V_31 -> V_103 = - 1 ;
V_31 -> V_33 = F_18 ( V_33 ) ;
V_31 -> V_104 = F_18 ( V_29 ) ;
V_31 -> type = type ;
V_31 -> V_15 = NULL ;
V_31 -> V_8 = V_12 ;
V_31 -> V_38 = 0 ;
if ( V_39 && strcmp ( V_39 , V_31 -> V_33 ) != 0 ) {
V_31 -> V_39 = F_18 ( V_39 ) ;
} else {
V_31 -> V_39 = NULL ;
}
F_53 ( V_13 , V_31 ) ;
return 1 ;
}
T_14 F_61 ( T_4 * V_13 ) {
T_11 V_31 = F_62 ( V_13 , 1 ) ;
T_1 * V_107 = F_63 ( L_41 ,
V_31 -> V_102 , V_31 -> V_33 , V_31 -> V_104 ,
F_3 ( V_31 -> type ) ,
F_4 ( V_31 -> V_8 ) ,
V_31 -> V_15 , V_31 -> V_38 , V_31 -> V_39 ) ;
F_64 ( V_13 , V_107 ) ;
F_14 ( V_107 ) ;
return 1 ;
}
static int F_65 ( T_4 * V_13 ) {
T_11 V_31 = F_66 ( V_13 , 1 ) ;
if ( V_31 -> V_102 == - 2 ) {
F_14 ( V_31 ) ;
}
return 0 ;
}
int F_67 ( T_4 * V_13 ) {
F_68 ( T_11 ) ;
return 0 ;
}
