T_1 * F_1 ( T_2 * V_1 , T_3 V_2 ) {
T_1 V_3 = ( T_1 ) F_2 ( sizeof( struct V_4 ) ) ;
V_3 -> V_5 = V_2 ;
V_3 -> V_6 = NULL ;
V_3 -> V_7 = FALSE ;
return F_3 ( V_1 , V_3 ) ;
}
T_1 * F_4 ( T_2 * V_1 , T_4 * V_6 ) {
T_1 V_3 = ( T_1 ) F_2 ( sizeof( struct V_4 ) ) ;
V_3 -> V_5 = ( T_3 ) V_6 -> V_8 ;
V_3 -> V_6 = V_6 ;
V_3 -> V_7 = FALSE ;
return F_3 ( V_1 , V_3 ) ;
}
static T_5 F_5 ( T_1 V_3 ) {
return ( V_3 -> V_6 == NULL ) ;
}
static int F_6 ( T_2 * V_1 , T_3 V_2 ) {
T_6 V_9 ;
T_7 V_10 [ V_11 ] ;
int V_12 = 0 ;
int V_13 = - 1 ;
int V_14 = 0 ;
T_5 V_15 = FALSE ;
V_13 = F_7 ( V_2 ) ;
if ( V_13 == '+' || V_13 == '-' ) {
V_10 [ V_12 ++ ] = ( T_7 ) V_13 ;
V_13 = F_7 ( V_2 ) ;
if ( V_13 < '0' || V_13 > '9' ) {
F_8 ( V_1 ) ;
return 0 ;
}
F_9 ( V_2 ) ;
}
while( ( V_13 = F_7 ( V_2 ) ) > 0 && V_12 < ( V_11 - 1 ) ) {
if ( V_13 >= '0' && V_13 <= '9' ) {
V_10 [ V_12 ++ ] = ( T_7 ) V_13 ;
V_14 ++ ;
F_9 ( V_2 ) ;
}
else if ( ! V_15 && V_13 == '.' ) {
V_15 = TRUE ;
V_10 [ V_12 ++ ] = ( T_7 ) V_13 ;
F_9 ( V_2 ) ;
}
else break;
}
V_10 [ V_12 ] = '\0' ;
if ( V_12 > 0 && V_14 > 0 && sscanf ( V_10 , L_1 , & V_9 ) == 1 ) {
F_10 ( V_1 , V_9 ) ;
return 1 ;
}
else {
F_8 ( V_1 ) ;
return 0 ;
}
}
static int F_11 ( T_2 * V_1 , T_3 V_2 ) {
static T_7 V_16 [ V_17 ] ;
T_8 V_18 = F_12 ( V_2 ) ;
T_9 V_19 = 0 ;
if ( F_13 ( V_16 , V_17 , V_2 ) == NULL ) {
return 0 ;
}
V_19 = ( T_9 ) ( F_12 ( V_2 ) - V_18 ) ;
if ( V_16 [ V_19 - 1 ] == '\n' ) {
V_19 -- ;
if ( V_19 > 0 && V_16 [ V_19 - 1 ] == '\r' ) {
V_19 -- ;
}
V_16 [ V_19 ] = '\0' ;
}
F_14 ( V_1 , V_16 , V_19 ) ;
return 1 ;
}
static int F_15 ( T_2 * V_1 , T_3 V_2 , T_10 V_20 ) {
T_10 V_21 ;
T_10 V_22 ;
int V_23 ;
T_7 V_10 [ V_24 ] ;
T_11 V_25 ;
V_21 = V_24 ;
F_16 ( V_1 , & V_25 ) ;
do {
if ( V_21 > V_20 ) V_21 = V_20 ;
V_23 = F_17 ( V_10 , ( unsigned int ) V_21 , V_2 ) ;
if ( V_23 < 1 ) break;
V_22 = ( T_10 ) V_23 ;
F_18 ( & V_25 , V_10 , V_22 ) ;
V_20 -= V_22 ;
} while ( V_20 > 0 && V_22 == V_21 );
F_19 ( & V_25 ) ;
return ( V_20 == 0 || F_20 ( V_1 , - 1 ) > 0 ) ;
}
static int F_21 ( T_2 * V_1 , T_3 V_2 ) {
if ( F_22 ( V_2 ) ) {
F_8 ( V_1 ) ;
}
else {
F_14 ( V_1 , L_2 , 0 ) ;
}
return 1 ;
}
static int F_23 ( T_2 * V_1 , int V_26 , const char * V_27 ) {
int V_28 = V_29 ;
if ( V_26 ) {
F_24 ( V_1 , 1 ) ;
return 1 ;
}
else {
F_8 ( V_1 ) ;
if ( V_27 )
F_25 ( V_1 , L_3 , V_27 , F_26 ( V_28 ) ) ;
else
F_25 ( V_1 , L_4 , F_26 ( V_28 ) ) ;
F_27 ( V_1 , V_28 ) ;
return 3 ;
}
}
T_12 F_28 ( T_2 * V_1 ) {
T_1 V_3 = F_29 ( V_1 , 1 ) ;
int V_30 = F_30 ( V_1 ) ;
int V_31 ;
int V_20 = 1 ;
T_3 V_2 = NULL ;
if ( ! V_3 || ! V_3 -> V_5 ) {
return 0 ;
}
if ( V_3 -> V_7 ) {
F_31 ( L_5 ) ;
return 0 ;
}
if ( ! F_5 ( V_3 ) ) {
F_31 ( L_6 ) ;
return 0 ;
}
V_2 = V_3 -> V_5 ;
if ( V_30 == 0 ) {
V_31 = F_11 ( V_1 , V_2 ) ;
V_20 = 2 ;
}
else {
F_32 ( V_1 , V_30 + V_32 , L_7 ) ;
V_31 = 1 ;
for ( V_20 = 1 ; V_30 -- && V_31 ; V_20 ++ ) {
if ( F_33 ( V_1 , V_20 ) == V_33 ) {
T_10 V_34 = ( T_10 ) F_34 ( V_1 , V_20 ) ;
V_31 = ( V_34 == 0 ) ? F_21 ( V_1 , V_2 ) : F_15 ( V_1 , V_2 , V_34 ) ;
}
else {
const char * V_35 = F_35 ( V_1 , V_20 ) ;
if ( ! V_35 ) return F_36 ( V_1 , V_20 , L_8 ) ;
F_37 ( V_1 , V_35 [ 0 ] == '*' , V_20 , L_9 ) ;
switch ( V_35 [ 1 ] ) {
case 'n' :
V_31 = F_6 ( V_1 , V_2 ) ;
break;
case 'l' :
V_31 = F_11 ( V_1 , V_2 ) ;
break;
case 'a' :
F_15 ( V_1 , V_2 , ~ ( ( T_10 ) 0 ) ) ;
V_31 = 1 ;
break;
default:
return F_36 ( V_1 , V_20 , L_10 ) ;
}
}
}
}
if ( F_38 ( V_2 , NULL ) )
return F_23 ( V_1 , 0 , NULL ) ;
if ( ! V_31 ) {
F_39 ( V_1 , 1 ) ;
F_8 ( V_1 ) ;
}
return V_20 - 1 ;
}
T_12 F_40 ( T_2 * V_1 ) {
static const int V_36 [] = { V_37 , V_38 , V_39 } ;
static const char * const V_40 [] = { L_11 , L_12 , L_13 , NULL } ;
T_1 V_3 = F_41 ( V_1 , 1 ) ;
int V_41 = F_42 ( V_1 , 2 , L_12 , V_40 ) ;
T_8 V_42 = ( T_8 ) F_43 ( V_1 , 3 , 0 ) ;
int V_43 = V_44 ;
if ( F_5 ( V_3 ) ) {
V_42 = F_44 ( V_3 -> V_5 , V_42 , V_36 [ V_41 ] , & V_43 ) ;
if ( V_42 < 0 ) {
F_8 ( V_1 ) ;
F_45 ( V_1 , F_46 ( V_43 ) ) ;
return 2 ;
}
F_10 ( V_1 , ( T_6 ) ( F_12 ( V_3 -> V_5 ) ) ) ;
}
else {
V_42 = F_47 ( V_3 -> V_6 , V_42 , V_36 [ V_41 ] , & V_43 ) ;
if ( V_42 < 0 ) {
F_8 ( V_1 ) ;
F_45 ( V_1 , F_46 ( V_43 ) ) ;
return 2 ;
}
V_42 = F_48 ( V_3 -> V_6 , & V_43 ) ;
if ( V_42 < 0 ) {
F_8 ( V_1 ) ;
F_45 ( V_1 , F_46 ( V_43 ) ) ;
return 2 ;
}
F_10 ( V_1 , ( T_6 ) ( V_42 ) ) ;
}
F_49 ( 1 ) ;
}
static int F_50 ( T_2 * V_1 ) {
T_3 V_2 = * ( T_3 * ) F_51 ( V_1 , F_52 ( 1 ) ) ;
int V_31 ;
if ( V_2 == NULL )
return F_53 ( V_1 , L_14 ) ;
V_31 = F_11 ( V_1 , V_2 ) ;
return V_31 ;
}
T_12 F_54 ( T_2 * V_1 ) {
T_1 V_3 = F_41 ( V_1 , 1 ) ;
T_3 V_2 = NULL ;
if ( ! V_3 -> V_5 )
return F_53 ( V_1 , L_15 ) ;
if ( ! F_5 ( V_3 ) ) {
F_31 ( L_6 ) ;
return 0 ;
}
V_2 = V_3 -> V_5 ;
F_55 ( V_1 , V_2 ) ;
F_56 ( V_1 , F_50 , 1 ) ;
return 1 ;
}
T_12 F_57 ( T_2 * V_1 ) {
T_1 V_3 = F_41 ( V_1 , 1 ) ;
int V_45 = 2 ;
int V_30 = F_30 ( V_1 ) - 1 ;
int V_46 = TRUE ;
int V_43 = 0 ;
if ( ! V_3 -> V_6 ) {
F_31 ( L_16 ) ;
return 0 ;
}
F_58 ( V_1 , 1 ) ;
for (; V_30 -- ; V_45 ++ ) {
T_10 V_47 ;
const char * V_48 = F_59 ( V_1 , V_45 , & V_47 ) ;
V_46 = F_60 ( V_3 -> V_6 , V_48 , V_47 , & V_43 ) ;
if ( ! V_46 ) break;
V_3 -> V_6 -> V_49 += V_47 ;
}
if ( ! V_46 ) {
F_39 ( V_1 , 1 ) ;
F_8 ( V_1 ) ;
F_25 ( V_1 , L_17 , F_26 ( V_43 ) ) ;
F_27 ( V_1 , V_43 ) ;
return 3 ;
}
return 1 ;
}
T_13 F_61 ( T_2 * V_1 ) {
T_1 V_3 = F_62 ( V_1 , 1 ) ;
if ( ! V_3 ) {
F_45 ( V_1 , L_18 ) ;
} else {
F_25 ( V_1 , L_19 , V_3 -> V_7 ? L_20 : L_21 , V_3 -> V_5 ? L_22 : L_23 ,
V_3 -> V_6 ? L_24 : L_25 ) ;
}
F_49 ( 1 ) ;
}
static int F_63 ( T_2 * V_1 V_50 ) {
T_1 V_3 = F_62 ( V_1 , 1 ) ;
if ( V_3 )
F_64 ( V_3 ) ;
return 0 ;
}
static int F_65 ( T_2 * V_1 ) {
T_1 V_3 = F_41 ( V_1 , 1 ) ;
if ( F_5 ( V_3 ) ) {
F_24 ( V_1 , F_66 ( V_3 -> V_5 ) ) ;
} else {
F_24 ( V_1 , V_3 -> V_6 -> V_51 ) ;
}
return 1 ;
}
int F_67 ( T_2 * V_1 ) {
F_68 ( T_1 ) ;
F_69 ( T_1 ) ;
return 0 ;
}
