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
V_14 = F_7 ( V_8 , V_20 , V_6 , V_10 , F_8 ( V_6 ) , V_21 ) ;
V_15 = F_9 ( V_14 , V_22 ) ;
F_10 ( V_15 , V_23 , V_6 , 0 , 0 , V_1 ) ;
V_12 = F_11 ( V_1 , F_12 ( V_24 ) ) ;
if ( V_12 ) {
F_13 ( V_14 , L_1 , V_12 ) ;
F_13 ( V_11 -> V_16 . V_25 , L_2 , V_12 ) ;
if ( V_11 -> V_26 >= 0 )
F_13 ( F_14 ( F_15 ( V_8 ) , V_11 -> V_26 ) , L_3 , V_12 ) ;
}
if ( V_13 -> V_27 )
V_10 = V_13 -> V_27 ( V_6 , V_7 , V_15 , NULL ) ;
else
if ( F_16 ( V_6 , V_10 ) > 0 ) {
F_17 ( V_15 , V_6 , V_10 , - 1 , L_4 ) ;
V_10 += F_16 ( V_6 , V_10 ) ;
}
return V_10 ;
}
static int
F_18 ( T_4 * V_6 , T_5 * V_7 , T_6 * V_8 , void * V_9 ) {
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
V_14 = F_7 ( V_8 , V_20 , V_6 , V_10 , F_8 ( V_6 ) , V_21 ) ;
V_15 = F_9 ( V_14 , V_22 ) ;
F_10 ( V_15 , V_23 , V_6 , 0 , 0 , V_1 ) ;
V_12 = F_11 ( V_1 , F_12 ( V_24 ) ) ;
if ( V_12 ) {
F_13 ( V_14 , L_1 , V_12 ) ;
F_13 ( V_11 -> V_16 . V_25 , L_2 , V_12 ) ;
if ( V_11 -> V_26 >= 0 )
F_13 ( F_14 ( F_15 ( V_8 ) , V_11 -> V_26 ) , L_3 , V_12 ) ;
}
if ( V_13 -> V_28 )
V_10 = V_13 -> V_28 ( V_6 , V_7 , V_15 , NULL ) ;
else
if ( F_16 ( V_6 , V_10 ) > 0 ) {
F_17 ( V_15 , V_6 , V_10 , - 1 , L_5 ) ;
V_10 += F_16 ( V_6 , V_10 ) ;
}
return V_10 ;
}
static int
F_19 ( T_4 * V_6 , T_5 * V_7 , T_6 * V_8 , void * V_9 ) {
int V_10 = 0 ;
T_7 * V_11 ;
T_2 V_4 ;
const T_3 * V_29 ;
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
V_29 = F_3 ( V_4 ) ;
if ( ! V_29 )
return V_10 ;
V_14 = F_7 ( V_8 , V_20 , V_6 , V_10 , F_8 ( V_6 ) , V_21 ) ;
V_15 = F_9 ( V_14 , V_22 ) ;
F_10 ( V_15 , V_30 , V_6 , 0 , 0 , V_4 ) ;
V_12 = F_11 ( V_4 , F_12 ( V_31 ) ) ;
if ( V_12 ) {
F_13 ( V_14 , L_1 , V_12 ) ;
F_13 ( V_11 -> V_16 . V_25 , L_2 , V_12 ) ;
if ( V_11 -> V_26 >= 0 )
F_13 ( F_14 ( F_15 ( V_8 ) , V_11 -> V_26 ) , L_3 , V_12 ) ;
}
if ( V_29 -> V_32 )
V_10 = V_29 -> V_32 ( V_6 , V_7 , V_15 , NULL ) ;
else
if ( F_16 ( V_6 , V_10 ) > 0 ) {
F_17 ( V_15 , V_6 , V_10 , - 1 , L_6 ) ;
V_10 += F_16 ( V_6 , V_10 ) ;
}
return V_10 ;
}
void F_20 ( void ) {
int V_2 ;
#if 0
dissector_handle_t q931_handle;
#endif
T_11 V_33 ;
T_11 V_34 ;
T_11 V_35 ;
#if 0
q931_handle = find_dissector("q931");
#endif
V_33 = F_21 ( F_4 , V_20 ) ;
V_34 = F_21 ( F_18 , V_20 ) ;
for ( V_2 = 0 ; V_2 < ( int ) F_2 ( V_3 ) ; V_2 ++ ) {
F_22 ( L_7 , V_3 [ V_2 ] . V_1 , V_33 ) ;
F_22 ( L_8 , V_3 [ V_2 ] . V_1 , V_34 ) ;
}
for ( V_2 = 0 ; V_2 < ( int ) F_2 ( V_36 ) ; V_2 ++ ) {
if( V_36 -> V_27 )
F_23 ( L_9 , V_36 [ V_2 ] . V_37 , F_21 ( V_36 [ V_2 ] . V_27 , V_20 ) ) ;
if( V_36 -> V_28 )
F_23 ( L_10 , V_36 [ V_2 ] . V_37 , F_21 ( V_36 [ V_2 ] . V_28 , V_20 ) ) ;
}
V_35 = F_21 ( F_19 , V_20 ) ;
for ( V_2 = 0 ; V_2 < ( int ) F_2 ( V_5 ) ; V_2 ++ ) {
F_22 ( L_11 , V_5 [ V_2 ] . V_4 , V_35 ) ;
}
}
void F_24 ( void ) {
static T_12 V_38 [] = {
{ & V_39 ,
{ L_12 , L_13 ,
V_40 , V_41 , NULL , 0 ,
NULL , V_42 }
} ,
{ & V_23 ,
{ L_14 , L_15 ,
V_43 , V_41 , F_12 ( V_24 ) , 0x0 ,
NULL , V_42 }
} ,
{ & V_30 ,
{ L_16 , L_17 ,
V_43 , V_41 , F_12 ( V_31 ) , 0x0 ,
NULL , V_42 }
} ,
#include "packet-isdn-sup-hfarr.c"
} ;
static T_10 * V_44 [] = {
& V_22 ,
#include "packet-isdn-sup-ettarr.c"
} ;
F_25 ( V_20 , V_38 , F_2 ( V_38 ) ) ;
F_26 ( V_44 , F_2 ( V_44 ) ) ;
V_20 = F_27 ( V_45 , V_46 , V_47 ) ;
}
