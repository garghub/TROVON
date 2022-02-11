T_1 * F_1 ( T_2 * V_1 , struct V_2 * V_3 , T_3 * V_4 ) {
T_1 V_5 = ( T_1 ) F_2 ( sizeof( struct V_6 ) ) ;
V_5 -> V_3 = V_3 ;
V_5 -> V_4 = V_4 ;
V_5 -> V_7 = FALSE ;
return F_3 ( V_1 , V_5 ) ;
}
T_4 F_4 ( T_2 * V_1 ) {
T_1 V_8 = F_5 ( V_1 , 1 ) ;
if ( ! V_8 ) {
F_6 ( V_1 , L_1 ) ;
} else {
if ( V_8 -> V_3 )
F_7 ( V_1 , L_2 ,
V_8 -> V_3 -> V_9 , V_8 -> V_3 -> V_10 , V_8 -> V_3 -> V_11 , V_8 -> V_3 -> V_12 , V_8 -> V_3 -> V_13 , V_8 -> V_3 -> V_14 ) ;
else
F_6 ( V_1 , L_3 ) ;
}
F_8 ( 1 ) ;
}
T_5 F_9 ( T_2 * V_1 ) {
#define F_10 2
#define F_11 3
T_1 V_8 = F_12 ( V_1 , 1 ) ;
T_6 V_15 = F_13 ( V_1 , F_10 ) ;
T_7 V_12 = F_14 ( V_1 , F_11 ) ;
int V_16 = 0 ;
T_8 * V_17 = NULL ;
if ( ! V_8 -> V_4 || ! V_15 -> V_18 ) {
F_15 ( V_1 , L_4 ) ;
return 0 ;
}
if ( ! F_16 ( V_15 -> V_18 , V_8 -> V_4 , V_12 , & V_16 , & V_17 ) ) {
F_17 ( V_1 , FALSE ) ;
if ( V_17 ) {
F_6 ( V_1 , V_17 ) ;
F_18 ( V_17 ) ;
}
else F_19 ( V_1 ) ;
F_20 ( V_1 , V_16 ) ;
return 3 ;
}
F_17 ( V_1 , TRUE ) ;
F_8 ( 1 ) ;
}
static int F_21 ( T_2 * V_1 V_19 ) {
T_1 V_8 = F_5 ( V_1 , 1 ) ;
if ( V_8 )
F_18 ( V_8 ) ;
return 0 ;
}
static int F_22 ( T_2 * V_1 ) {
T_1 V_8 = F_12 ( V_1 , 1 ) ;
T_9 V_20 = F_23 ( V_1 , 2 ) ;
if ( ! V_8 -> V_3 ) return 0 ;
V_8 -> V_3 -> V_21 . V_22 = V_20 -> V_22 ;
V_8 -> V_3 -> V_21 . V_23 = V_20 -> V_23 ;
return 0 ;
}
static int F_24 ( T_2 * V_1 ) {
T_1 V_8 = F_12 ( V_1 , 1 ) ;
T_9 V_20 = ( T_9 ) F_25 ( sizeof( V_24 ) ) ;
if ( ! V_20 ) return 0 ;
V_20 -> V_22 = V_8 -> V_3 -> V_21 . V_22 ;
V_20 -> V_23 = V_8 -> V_3 -> V_21 . V_23 ;
F_26 ( V_1 , V_20 ) ;
return 1 ;
}
static int F_27 ( T_2 * V_1 ) {
T_1 V_8 = F_12 ( V_1 , 1 ) ;
if ( ! V_8 -> V_3 ) {
F_28 ( L_5 ) ;
return 0 ;
}
if ( ! V_8 -> V_4 ) {
F_28 ( L_6 ) ;
return 0 ;
}
if ( F_29 ( V_1 , 2 ) ) {
T_10 V_12 = 0 ;
const T_8 * V_25 = F_30 ( V_1 , 2 , & V_12 ) ;
F_31 ( V_8 -> V_4 , V_12 ) ;
memcpy ( F_32 ( V_8 -> V_4 ) , V_25 , V_12 ) ;
V_8 -> V_3 -> V_11 = ( T_7 ) V_12 ;
V_8 -> V_3 -> V_12 = ( T_7 ) V_12 ;
}
else
F_15 ( V_1 , L_7 ) ;
return 0 ;
}
static int F_33 ( T_2 * V_1 ) {
T_1 V_8 = F_12 ( V_1 , 1 ) ;
if ( ! V_8 -> V_4 ) return 0 ;
F_34 ( V_1 , F_32 ( V_8 -> V_4 ) , F_35 ( V_8 -> V_4 ) ) ;
F_8 ( 1 ) ;
}
int F_36 ( T_2 * V_1 ) {
F_37 ( T_1 ) ;
F_38 ( T_1 ) ;
return 0 ;
}
T_11 * F_39 ( T_2 * V_1 , const struct V_2 * V_3 , const T_12 * V_26 ) {
T_11 V_5 = ( T_11 ) F_25 ( sizeof( struct V_27 ) ) ;
V_5 -> V_3 = V_3 ;
V_5 -> V_26 = V_26 ;
V_5 -> V_7 = FALSE ;
return F_40 ( V_1 , V_5 ) ;
}
T_4 F_41 ( T_2 * V_1 ) {
T_11 V_8 = F_42 ( V_1 , 1 ) ;
if ( ! V_8 ) {
F_6 ( V_1 , L_1 ) ;
} else {
if ( V_8 -> V_3 && ! V_8 -> V_7 )
F_7 ( V_1 , L_2 ,
V_8 -> V_3 -> V_9 , V_8 -> V_3 -> V_10 , V_8 -> V_3 -> V_11 , V_8 -> V_3 -> V_12 , V_8 -> V_3 -> V_13 , V_8 -> V_3 -> V_14 ) ;
else
F_7 ( V_1 , L_8 , V_8 -> V_3 ? L_9 : L_10 ) ;
}
F_8 ( 1 ) ;
}
T_5 F_43 ( T_2 * V_1 ) {
#define F_44 2
#define F_45 3
T_11 V_8 = F_46 ( V_1 , 1 ) ;
T_6 V_15 = F_13 ( V_1 , F_44 ) ;
T_7 V_12 = F_47 ( V_1 , F_45 , V_8 -> V_3 ? V_8 -> V_3 -> V_11 : 0 ) ;
int V_16 = 0 ;
if ( ! V_8 -> V_26 || ! V_8 -> V_3 || ! V_15 -> V_28 ) {
F_15 ( V_1 , L_11 ) ;
return 0 ;
}
if ( V_12 > V_8 -> V_3 -> V_11 )
V_12 = V_8 -> V_3 -> V_11 ;
if ( ! F_48 ( V_15 -> V_28 , V_8 -> V_26 , ( T_10 ) ( V_12 ) , & V_16 ) ) {
F_17 ( V_1 , FALSE ) ;
F_7 ( V_1 , L_12 , F_49 ( V_16 ) ) ;
F_20 ( V_1 , V_16 ) ;
return 3 ;
}
F_17 ( V_1 , TRUE ) ;
F_8 ( 1 ) ;
}
static int F_50 ( T_2 * V_1 V_19 ) {
T_11 V_8 = F_42 ( V_1 , 1 ) ;
if ( V_8 )
F_18 ( V_8 ) ;
return 0 ;
}
static int F_51 ( T_2 * V_1 ) {
T_11 V_8 = F_46 ( V_1 , 1 ) ;
T_9 V_20 = ( T_9 ) F_25 ( sizeof( V_24 ) ) ;
if ( ! V_20 ) return 0 ;
V_20 -> V_22 = V_8 -> V_3 -> V_21 . V_22 ;
V_20 -> V_23 = V_8 -> V_3 -> V_21 . V_23 ;
F_26 ( V_1 , V_20 ) ;
return 1 ;
}
static int F_52 ( T_2 * V_1 ) {
T_11 V_8 = F_46 ( V_1 , 1 ) ;
if ( ! V_8 -> V_26 || ! V_8 -> V_3 ) return 0 ;
F_34 ( V_1 , V_8 -> V_26 , V_8 -> V_3 -> V_11 ) ;
return 1 ;
}
int F_53 ( T_2 * V_1 ) {
F_37 ( T_11 ) ;
F_38 ( T_11 ) ;
return 0 ;
}
