static const T_1 * F_1 ( T_2 V_1 ) {
int V_2 ;
for ( V_2 = F_2 ( V_3 ) - 1 ; V_2 >= 0 ; V_2 -- )
if ( V_3 [ V_2 ] . V_1 == V_1 )
return & V_3 [ V_2 ] ;
return NULL ;
}
static const T_3 * F_3 ( T_2 V_4 ) {
int V_2 ;
for ( V_2 = F_2 ( V_5 ) - 1 ; V_2 >= 0 ; V_2 -- )
if ( V_5 [ V_2 ] . V_4 == V_4 )
return & V_5 [ V_2 ] ;
return NULL ;
}
static int
F_4 ( T_4 * V_6 , T_5 * V_7 , T_6 * V_8 , void * V_9 ) {
int V_10 = 0 ;
T_7 * V_11 ;
T_2 V_1 = 0 ;
const T_8 * V_12 ;
const T_1 * V_13 ;
T_9 * V_14 ;
T_6 * V_15 ;
if ( V_9 == NULL )
return 0 ;
V_11 = F_5 ( V_9 ) ;
F_6 ( V_11 ) ;
if ( V_11 -> V_16 . V_17 != 1 )
return V_10 ;
if ( V_11 -> V_16 . V_18 == 0 ) {
V_1 = V_11 -> V_16 . V_19 ;
} else {
return V_10 ;
}
V_13 = F_1 ( V_1 ) ;
if ( ! V_13 )
return V_10 ;
V_14 = F_7 ( V_8 , V_20 , V_6 , V_10 , - 1 , V_21 ) ;
V_15 = F_8 ( V_14 , V_22 ) ;
F_9 ( V_15 , V_23 , V_6 , 0 , 0 , V_1 ) ;
V_12 = F_10 ( V_1 , F_11 ( V_24 ) ) ;
if ( V_12 ) {
F_12 ( V_14 , L_1 , V_12 ) ;
F_12 ( V_11 -> V_16 . V_25 , L_2 , V_12 ) ;
if ( V_11 -> V_26 >= 0 )
F_12 ( F_13 ( F_14 ( V_8 ) , V_11 -> V_26 ) , L_3 , V_12 ) ;
}
if ( V_13 -> V_27 )
V_10 = V_13 -> V_27 ( V_6 , V_7 , V_15 , NULL ) ;
else
if ( F_15 ( V_6 , V_10 ) > 0 ) {
F_16 ( V_8 , V_7 , & V_28 , V_6 , V_10 , - 1 ) ;
V_10 += F_15 ( V_6 , V_10 ) ;
}
return V_10 ;
}
static int
F_17 ( T_4 * V_6 , T_5 * V_7 , T_6 * V_8 , void * V_9 ) {
T_10 V_10 = 0 ;
T_7 * V_11 ;
T_2 V_1 = 0 ;
const T_8 * V_12 ;
const T_1 * V_13 ;
T_9 * V_14 ;
T_6 * V_15 ;
if ( V_9 == NULL )
return 0 ;
V_11 = F_5 ( V_9 ) ;
F_6 ( V_11 ) ;
if ( V_11 -> V_16 . V_17 != 2 )
return V_10 ;
if ( V_11 -> V_16 . V_18 != 0 )
return V_10 ;
V_1 = V_11 -> V_16 . V_19 ;
V_13 = F_1 ( V_1 ) ;
if ( ! V_13 )
return V_10 ;
V_14 = F_7 ( V_8 , V_20 , V_6 , V_10 , - 1 , V_21 ) ;
V_15 = F_8 ( V_14 , V_22 ) ;
F_9 ( V_15 , V_23 , V_6 , 0 , 0 , V_1 ) ;
V_12 = F_10 ( V_1 , F_11 ( V_24 ) ) ;
if ( V_12 ) {
F_12 ( V_14 , L_1 , V_12 ) ;
F_12 ( V_11 -> V_16 . V_25 , L_2 , V_12 ) ;
if ( V_11 -> V_26 >= 0 )
F_12 ( F_13 ( F_14 ( V_8 ) , V_11 -> V_26 ) , L_3 , V_12 ) ;
}
if ( V_13 -> V_29 )
V_10 = V_13 -> V_29 ( V_6 , V_7 , V_15 , NULL ) ;
else
if ( F_15 ( V_6 , V_10 ) > 0 ) {
F_16 ( V_8 , V_7 , & V_30 , V_6 , V_10 , - 1 ) ;
V_10 += F_15 ( V_6 , V_10 ) ;
}
return V_10 ;
}
static int
F_18 ( T_4 * V_6 , T_5 * V_7 , T_6 * V_8 , void * V_9 ) {
int V_10 = 0 ;
T_7 * V_11 ;
T_2 V_4 ;
const T_3 * V_31 ;
const T_8 * V_12 ;
T_9 * V_14 ;
T_6 * V_15 ;
if ( V_9 == NULL )
return 0 ;
V_11 = F_5 ( V_9 ) ;
F_6 ( V_11 ) ;
if ( V_11 -> V_16 . V_17 != 3 )
return V_10 ;
if ( V_11 -> V_16 . V_18 != 0 )
return V_10 ;
V_4 = V_11 -> V_16 . V_19 ;
V_31 = F_3 ( V_4 ) ;
if ( ! V_31 )
return V_10 ;
V_14 = F_7 ( V_8 , V_20 , V_6 , V_10 , - 1 , V_21 ) ;
V_15 = F_8 ( V_14 , V_22 ) ;
F_9 ( V_15 , V_32 , V_6 , 0 , 0 , V_4 ) ;
V_12 = F_10 ( V_4 , F_11 ( V_33 ) ) ;
if ( V_12 ) {
F_12 ( V_14 , L_1 , V_12 ) ;
F_12 ( V_11 -> V_16 . V_25 , L_2 , V_12 ) ;
if ( V_11 -> V_26 >= 0 )
F_12 ( F_13 ( F_14 ( V_8 ) , V_11 -> V_26 ) , L_3 , V_12 ) ;
}
if ( V_31 -> V_34 )
V_10 = V_31 -> V_34 ( V_6 , V_7 , V_15 , NULL ) ;
else
if ( F_15 ( V_6 , V_10 ) > 0 ) {
F_16 ( V_8 , V_7 , & V_28 , V_6 , V_10 , - 1 ) ;
V_10 += F_15 ( V_6 , V_10 ) ;
}
return V_10 ;
}
void F_19 ( void ) {
int V_2 ;
#if 0
dissector_handle_t q931_handle;
#endif
T_11 V_35 ;
T_11 V_36 ;
T_11 V_37 ;
#if 0
q931_handle = find_dissector("q931");
#endif
V_35 = F_20 ( F_4 , V_20 ) ;
V_36 = F_20 ( F_17 , V_20 ) ;
for ( V_2 = 0 ; V_2 < ( int ) F_2 ( V_3 ) ; V_2 ++ ) {
F_21 ( L_4 , V_3 [ V_2 ] . V_1 , V_35 ) ;
F_21 ( L_5 , V_3 [ V_2 ] . V_1 , V_36 ) ;
}
for ( V_2 = 0 ; V_2 < ( int ) F_2 ( V_38 ) ; V_2 ++ ) {
if( V_38 -> V_27 )
F_22 ( L_6 , V_38 [ V_2 ] . V_39 , F_20 ( V_38 [ V_2 ] . V_27 , V_20 ) ) ;
if( V_38 -> V_29 )
F_22 ( L_7 , V_38 [ V_2 ] . V_39 , F_20 ( V_38 [ V_2 ] . V_29 , V_20 ) ) ;
}
V_37 = F_20 ( F_18 , V_20 ) ;
for ( V_2 = 0 ; V_2 < ( int ) F_2 ( V_5 ) ; V_2 ++ ) {
F_21 ( L_8 , V_5 [ V_2 ] . V_4 , V_37 ) ;
}
}
void F_23 ( void ) {
static T_12 V_40 [] = {
{ & V_41 ,
{ L_9 , L_10 ,
V_42 , V_43 , NULL , 0 ,
NULL , V_44 }
} ,
{ & V_23 ,
{ L_11 , L_12 ,
V_45 , V_43 , F_11 ( V_24 ) , 0x0 ,
NULL , V_44 }
} ,
{ & V_32 ,
{ L_13 , L_14 ,
V_45 , V_43 , F_11 ( V_33 ) , 0x0 ,
NULL , V_44 }
} ,
#include "packet-isdn-sup-hfarr.c"
} ;
static T_10 * V_46 [] = {
& V_22 ,
#include "packet-isdn-sup-ettarr.c"
} ;
static T_13 V_47 [] = {
#if 0
{ &ei_isdn_sup_unsupported_arg_type, { "isdn_sup.unsupported.arg_type", PI_UNDECODED, PI_WARN, "UNSUPPORTED ARGUMENT TYPE (ETSI sup)", EXPFILL }},
#endif
{ & V_30 , { L_15 , V_48 , V_49 , L_16 , V_50 } } ,
{ & V_28 , { L_17 , V_48 , V_49 , L_18 , V_50 } } ,
} ;
T_14 * V_51 ;
V_20 = F_24 ( V_52 , V_53 , V_54 ) ;
F_25 ( V_20 , V_40 , F_2 ( V_40 ) ) ;
F_26 ( V_46 , F_2 ( V_46 ) ) ;
V_51 = F_27 ( V_20 ) ;
F_28 ( V_51 , V_47 , F_2 ( V_47 ) ) ;
}
