T_1 * F_1 ( T_2 * V_1 , T_3 * V_2 ) {
T_1 V_3 = NULL ;
if ( V_2 ) {
V_3 = ( T_1 ) F_2 ( sizeof( struct V_4 ) ) ;
V_3 -> V_2 = V_2 ;
V_3 -> V_5 = FALSE ;
F_3 ( V_6 , V_3 ) ;
}
return F_4 ( V_1 , V_3 ) ;
}
T_4 F_5 ( T_2 * V_1 ) {
T_5 V_7 = F_6 ( V_1 , 1 ) ;
T_6 * V_8 ;
T_7 * V_9 , * V_10 ;
if ( ! V_7 ) return 0 ;
V_8 = F_7 ( L_1 ) ;
V_9 = F_8 ( V_7 -> V_11 ) ;
V_10 = F_9 ( V_9 ) ;
while ( V_10 ) {
V_8 = F_10 ( V_8 , ( const V_12 * ) V_10 -> V_13 ) ;
V_10 = F_11 ( V_10 ) ;
if ( V_10 ) {
V_8 = F_12 ( V_8 , ',' ) ;
}
}
F_13 ( V_1 , V_8 -> V_14 ) ;
F_14 ( V_8 , TRUE ) ;
F_15 ( V_9 ) ;
F_16 ( 1 ) ;
}
static int F_17 ( T_2 * V_1 ) {
T_5 V_7 = F_18 ( V_1 , 1 ) ;
const V_12 * V_15 = F_19 ( V_1 , 2 ) ;
const V_12 * string ;
string = ( const V_12 * ) ( F_20 ( V_7 -> V_11 , V_15 ) ) ;
if ( string ) {
F_13 ( V_1 , string ) ;
} else {
F_21 ( V_1 ) ;
}
return 1 ;
}
static int F_22 ( T_2 * V_1 ) {
T_5 V_7 = F_18 ( V_1 , 1 ) ;
const V_12 * V_15 = F_19 ( V_1 , 2 ) ;
const V_12 * string = NULL ;
if ( F_23 ( V_1 , 3 ) ) {
string = F_19 ( V_1 , 3 ) ;
} else if ( F_24 ( V_1 , 3 ) ) {
string = F_25 ( V_1 , 3 ) ? L_1 : NULL ;
} else if ( ! F_26 ( V_1 , 3 ) ) {
F_27 ( V_1 , L_2 , F_28 ( V_1 , 3 ) ) ;
return 0 ;
}
if ( string ) {
F_29 ( V_7 -> V_11 , ( V_16 ) F_30 ( V_15 ) , ( V_16 ) F_30 ( string ) ) ;
} else {
F_31 ( V_7 -> V_11 , ( V_17 ) V_15 ) ;
}
return 1 ;
}
static int F_32 ( T_2 * V_1 ) {
T_5 V_7 = F_6 ( V_1 , 1 ) ;
if ( ! V_7 ) return 0 ;
if ( ! V_7 -> V_5 ) {
V_7 -> V_5 = TRUE ;
} else {
if ( V_7 -> V_18 ) {
F_33 ( V_7 -> V_11 ) ;
}
F_34 ( V_7 ) ;
}
return 0 ;
}
int F_35 ( T_2 * V_1 ) {
F_36 ( T_5 ) ;
return 0 ;
}
static int F_37 ( T_2 * V_1 ) { F_13 ( V_1 , L_3 ) ; return 1 ; }
static double
F_38 ( const T_8 * V_19 )
{
return ( ( ( double ) V_19 -> V_20 ) + ( ( ( double ) V_19 -> V_21 ) / 1000000000.0 ) ) ;
}
static double
F_39 ( const T_1 V_3 , const T_9 * V_22 , T_10 V_23 )
{
T_8 V_24 ;
F_40 ( V_3 -> V_2 -> V_25 , V_22 , V_23 , & V_24 ) ;
return F_38 ( & V_24 ) ;
}
static int F_41 ( T_2 * V_1 ) {
T_1 V_3 = F_42 ( V_1 , 1 ) ;
if ( V_3 -> V_2 -> V_26 ) {
F_13 ( V_1 , V_3 -> V_2 -> V_26 ) ;
} else {
F_43 ( V_1 , ( V_27 ) ( V_3 -> V_2 -> V_28 ) ) ;
}
return 1 ;
}
static int F_44 ( T_2 * V_1 ) {
T_11 V_29 = NULL ;
T_1 V_3 = F_42 ( V_1 , 1 ) ;
const V_12 * V_30 = F_45 ( V_1 , 2 , NULL ) ;
V_29 = ( T_11 ) F_2 ( sizeof( struct V_31 ) ) ;
V_29 -> V_32 = V_3 -> V_2 -> V_32 ;
V_29 -> V_5 = FALSE ;
if ( ! V_30 ) {
F_46 ( V_1 , V_29 ) ;
} else {
F_47 ( V_1 , 0 ) ;
F_46 ( V_1 , V_29 ) ;
F_13 ( V_1 , V_30 ) ;
return F_48 ( V_1 ) ;
}
return 1 ;
}
static int F_49 ( T_2 * V_1 ) {
T_5 V_7 = NULL ;
T_1 V_3 = F_42 ( V_1 , 1 ) ;
const V_12 * V_33 = F_45 ( V_1 , 2 , NULL ) ;
T_12 V_18 = FALSE ;
if ( ! V_3 -> V_2 -> V_34 ) {
V_3 -> V_2 -> V_34 = F_50 ( V_35 , V_36 , F_34 , F_34 ) ;
V_18 = TRUE ;
}
V_7 = ( T_5 ) F_2 ( sizeof( struct V_37 ) ) ;
V_7 -> V_11 = V_3 -> V_2 -> V_34 ;
V_7 -> V_18 = V_18 ;
V_7 -> V_5 = FALSE ;
if ( ! V_33 ) {
F_51 ( V_1 , V_7 ) ;
} else {
F_47 ( V_1 , 0 ) ;
F_51 ( V_1 , V_7 ) ;
F_13 ( V_1 , V_33 ) ;
return F_17 ( V_1 ) ;
}
return 1 ;
}
static int F_52 ( T_2 * V_1 ) {
T_1 V_3 = F_42 ( V_1 , 1 ) ;
T_13 V_38 ;
V_38 = ( T_13 ) F_2 ( sizeof( V_39 ) ) ;
if ( F_53 ( & ( V_3 -> V_2 -> V_40 ) , & ( V_3 -> V_2 -> V_41 ) ) >= 0 ) {
F_54 ( V_38 , & ( V_3 -> V_2 -> V_40 ) ) ;
} else {
F_54 ( V_38 , & ( V_3 -> V_2 -> V_41 ) ) ;
}
F_55 ( V_1 , V_38 ) ;
return 1 ;
}
static int F_56 ( T_2 * V_1 ) {
T_1 V_3 = F_42 ( V_1 , 1 ) ;
T_13 V_38 ;
V_38 = ( T_13 ) F_2 ( sizeof( V_39 ) ) ;
if ( F_53 ( & ( V_3 -> V_2 -> V_40 ) , & ( V_3 -> V_2 -> V_41 ) ) < 0 ) {
F_54 ( V_38 , & ( V_3 -> V_2 -> V_40 ) ) ;
} else {
F_54 ( V_38 , & ( V_3 -> V_2 -> V_41 ) ) ;
}
F_55 ( V_1 , V_38 ) ;
return 1 ;
}
static int F_57 ( T_2 * V_1 ) {
T_1 V_3 = F_42 ( V_1 , 1 ) ;
T_14 V_42 = F_58 ( V_1 , 2 ) ;
T_15 * V_43 ;
if ( ! V_42 -> V_44 ) {
F_27 ( V_1 , L_4 , V_42 -> V_15 ? V_42 -> V_15 : L_5 ) ;
return 0 ;
}
V_43 = F_59 ( V_3 -> V_2 ) ;
F_60 ( V_43 , V_42 -> V_44 ) ;
return 0 ;
}
static int F_61 ( T_2 * V_1 ) {
T_1 V_3 = F_62 ( V_1 , 1 ) ;
if ( ! V_3 ) return 0 ;
if ( ! V_3 -> V_5 )
V_3 -> V_5 = TRUE ;
else
F_34 ( V_3 ) ;
return 0 ;
}
int F_63 ( T_2 * V_1 ) {
F_36 ( T_1 ) ;
F_64 ( T_1 ) ;
V_6 = F_65 () ;
V_45 = F_65 () ;
return 0 ;
}
