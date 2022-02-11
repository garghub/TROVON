static void F_1 ( struct V_1 * V_2 ) {
memset ( V_2 , '\0' , sizeof( * V_2 ) ) ;
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = FALSE ;
V_2 -> V_6 = NULL ;
}
static void
F_2 ( T_1 V_7 , T_1 V_8 , T_1 T_2 V_9 ) {
struct V_10 * V_11 = (struct V_10 * ) V_8 ;
T_3 * V_12 = ( T_3 * ) V_7 ;
F_3 ( V_12 ) ;
F_3 ( V_11 ) ;
}
static void
F_4 ( void ) {
if ( V_13 ) {
F_5 ( V_13 , F_2 , NULL ) ;
F_6 ( V_13 ) ;
V_13 = NULL ;
}
V_13 = F_7 ( V_14 , V_15 ) ;
}
static void
F_8 ( void )
{
F_4 () ;
}
static void
F_9 ( T_4 * V_16 , T_5 * T_6 V_9 , T_7 * T_8 V_9 ) {
struct V_10 * V_11 ;
T_9 * V_17 = & ( V_16 -> V_17 ) ;
T_9 * V_18 = & ( V_16 -> V_18 ) ;
char * V_19 ;
if ( ( ! V_16 -> V_20 -> V_21 . V_22 ) && ( V_23 . V_6 ) ) {
V_19 = F_10 ( V_24 ) ;
V_19 [ 0 ] = '\0' ;
switch( V_25 ) {
case 0 :
F_11 ( V_19 , V_24 , L_1 , V_23 . V_6 ) ;
break;
case 1 :
F_11 ( V_19 , V_24 , L_2 , V_23 . V_6 , F_12 ( V_17 ) ) ;
break;
default:
F_11 ( V_19 , V_24 , L_3 , V_23 . V_6 , F_12 ( V_17 ) , F_12 ( V_18 ) ) ;
break;
}
V_11 = (struct V_10 * ) F_13 ( V_13 , V_19 ) ;
if( V_11 )
return;
V_11 = F_14 ( struct V_10 , 1 ) ;
V_11 -> V_26 = V_23 . V_27 . V_26 ;
V_11 -> V_28 = V_23 . V_27 . V_28 ;
V_11 -> V_29 = V_23 . V_27 . V_29 ;
F_15 ( V_13 ,
F_16 ( V_19 ) ,
V_11 ) ;
}
}
static T_10
F_17 ( T_4 * V_16 , T_5 * T_6 V_9 , T_7 * T_8 V_9 ) {
struct V_10 * V_11 ;
T_9 * V_17 = & ( V_16 -> V_17 ) ;
T_9 * V_18 = & ( V_16 -> V_18 ) ;
char * V_19 ;
if ( ! V_23 . V_6 ) {
return FALSE ;
}
V_19 = F_10 ( V_24 ) ;
V_19 [ 0 ] = '\0' ;
F_11 ( V_19 , V_24 , L_3 ,
V_23 . V_6 , F_12 ( V_18 ) ,
F_12 ( V_17 ) ) ;
switch( V_25 ) {
case 0 :
F_11 ( V_19 , V_24 , L_1 , V_23 . V_6 ) ;
break;
case 1 :
F_11 ( V_19 , V_24 , L_2 , V_23 . V_6 , F_12 ( V_18 ) ) ;
break;
default:
F_11 ( V_19 , V_24 , L_3 , V_23 . V_6 , F_12 ( V_18 ) , F_12 ( V_17 ) ) ;
break;
}
V_11 = (struct V_10 * ) F_13 ( V_13 , V_19 ) ;
if( V_11 ) {
V_23 . V_27 . V_26 = V_11 -> V_26 ;
V_23 . V_27 . V_28 = V_11 -> V_28 ;
V_23 . V_27 . V_29 = V_11 -> V_29 ;
return TRUE ;
}
return FALSE ;
}
static T_10
F_18 ( T_7 * T_8 , T_11 * V_30 , T_5 * T_6 ) {
T_12 * V_31 ;
if( V_23 . V_27 . V_32 == 1 ) {
F_9 ( V_30 -> V_16 , T_6 , T_8 ) ;
} else{
if( F_17 ( V_30 -> V_16 , T_6 , T_8 ) ) {
if( V_23 . V_27 . V_26 == 0 ) {
V_31 = F_19 ( T_6 , V_33 , T_8 , 0 , 0 , V_23 . V_27 . V_28 ) ;
} else{
V_31 = F_19 ( T_6 , V_34 , T_8 , 0 , 0 , V_23 . V_27 . V_29 ) ;
}
F_20 ( V_31 ) ;
V_23 . V_27 . V_35 = V_31 ;
}
}
if( V_23 . V_27 . V_26 == 0 ) {
T_13 V_36 = ( V_23 . V_27 . V_28 & 0x7f00 ) >> 8 ;
T_13 V_37 = ( T_13 ) ( V_23 . V_27 . V_28 & 0xff ) ;
if( ! F_21 ( V_38 , V_23 . V_27 . V_28 , T_8 , V_30 -> V_16 , V_39 ) ) {
V_31 = F_22 ( T_6 , T_8 , 0 , - 1 ,
L_4
L_5 ,
V_23 . V_27 . V_28 , V_36 , V_37 ) ;
F_20 ( V_31 ) ;
return FALSE ;
}
return TRUE ;
} else if( V_23 . V_27 . V_26 == 1 ) {
if( ( V_23 . V_27 . V_29 & 0x0900 ) != 0x0900 ) {
V_31 = F_22 ( T_6 , T_8 , 0 , - 1 ,
L_6
L_7 ,
V_23 . V_27 . V_29 ) ;
F_20 ( V_31 ) ;
return FALSE ;
}
}
F_23 ( V_40 , T_8 , V_30 -> V_16 , V_39 ) ;
return TRUE ;
}
static int
F_24 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
#line 20 "../../asn1/ansi_tcap/ansi_tcap.cnf"
T_5 * V_41 ;
T_12 * V_42 ;
int V_43 = T_15 ;
T_13 V_36 ;
T_13 V_37 ;
T_15 = F_25 ( T_14 , V_30 , T_6 , T_8 , T_15 , T_16 ,
& V_23 . V_27 . V_28 ) ;
V_23 . V_27 . V_28 = ( V_23 . V_27 . V_28 & 0x7fff ) ;
V_41 = F_26 ( V_30 -> V_44 , V_45 ) ;
V_36 = ( V_23 . V_27 . V_28 & 0x7f00 ) >> 8 ;
V_37 = ( T_13 ) ( V_23 . V_27 . V_28 & 0xff ) ;
F_27 ( V_41 , V_46 , T_8 , V_43 , 2 , V_47 ) ;
F_27 ( V_41 , V_48 , T_8 , V_43 , 2 , V_47 ) ;
V_42 = F_27 ( V_41 , V_49 , T_8 , V_43 , 2 , V_47 ) ;
switch( V_36 ) {
case 0 :
break;
case 1 :
if( V_37 == 1 ) {
F_28 ( V_42 , L_8 ) ;
} else if ( V_37 == 2 ) {
F_28 ( V_42 , L_9 ) ;
}
break;
case 2 :
if ( V_37 == 1 ) {
F_28 ( V_42 , L_10 ) ;
}
break;
case 3 :
if ( V_37 == 1 ) {
F_28 ( V_42 , L_11 ) ;
} else if ( V_37 == 2 ) {
F_28 ( V_42 , L_12 ) ;
}
break;
case 4 :
if ( V_37 == 1 ) {
F_28 ( V_42 , L_13 ) ;
} else if ( V_37 == 2 ) {
F_28 ( V_42 , L_14 ) ;
} else if ( V_37 == 3 ) {
F_28 ( V_42 , L_15 ) ;
} else if ( V_37 == 4 ) {
F_28 ( V_42 , L_16 ) ;
}
break;
default:
break;
}
return T_15 ;
}
static int
F_29 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_25 ( T_14 , V_30 , T_6 , T_8 , T_15 , T_16 ,
& V_23 . V_27 . V_29 ) ;
return T_15 ;
}
static int
F_30 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_31 ( V_30 , T_6 , T_8 , T_15 ,
V_50 , T_16 , V_51 ,
& V_23 . V_27 . V_26 ) ;
#line 16 "../../asn1/ansi_tcap/ansi_tcap.cnf"
V_23 . V_27 . V_35 = V_30 -> V_44 ;
return T_15 ;
}
static int
F_32 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_25 ( T_14 , V_30 , T_6 , T_8 , T_15 , T_16 ,
NULL ) ;
return T_15 ;
}
static int
F_33 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_25 ( T_14 , V_30 , T_6 , T_8 , T_15 , T_16 ,
NULL ) ;
return T_15 ;
}
static int
F_34 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_31 ( V_30 , T_6 , T_8 , T_15 ,
V_52 , T_16 , V_53 ,
NULL ) ;
return T_15 ;
}
static int
F_35 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
#line 152 "../../asn1/ansi_tcap/ansi_tcap.cnf"
T_7 * V_54 ;
T_13 V_55 ;
T_15 = F_36 ( T_14 , V_30 , T_6 , T_8 , T_15 , T_16 ,
& V_54 ) ;
if( V_54 ) {
V_55 = F_37 ( V_54 , 0 ) ;
if( V_55 != 0 ) {
if ( V_55 > 4 ) {
V_23 . V_6 = F_38 ( V_54 , 4 , V_55 - 4 ) ;
} else{
V_23 . V_6 = F_38 ( V_54 , 0 , V_55 ) ;
}
}
switch( V_55 ) {
case 1 :
V_56 -> V_57 = F_39 ( V_54 , 0 ) ;
break;
case 2 :
V_56 -> V_57 = F_40 ( V_54 , 0 ) ;
break;
case 4 :
V_56 -> V_57 = F_41 ( V_54 , 0 ) ;
break;
default:
V_56 -> V_57 = 0 ;
break;
}
}
return T_15 ;
}
static int
F_42 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_43 ( T_14 , V_30 , T_6 , T_8 , T_15 ,
T_16 , V_58 , 7 , TRUE , F_35 ) ;
return T_15 ;
}
static int
F_44 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_36 ( T_14 , V_30 , T_6 , T_8 , T_15 , T_16 ,
NULL ) ;
return T_15 ;
}
static int
F_45 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_43 ( T_14 , V_30 , T_6 , T_8 , T_15 ,
T_16 , V_58 , 26 , TRUE , F_44 ) ;
return T_15 ;
}
static int
F_46 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_43 ( T_14 , V_30 , T_6 , T_8 , T_15 ,
T_16 , V_58 , 27 , TRUE , F_33 ) ;
return T_15 ;
}
static int
F_47 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_48 ( T_14 , V_30 , T_6 , T_8 , T_15 , T_16 , NULL ) ;
return T_15 ;
}
static int
F_49 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
#line 116 "../../asn1/ansi_tcap/ansi_tcap.cnf"
static const char * V_59 ;
T_15 = F_43 ( T_14 , V_30 , T_6 , T_8 , T_15 ,
T_16 , V_58 , 28 , TRUE , F_47 ) ;
V_23 . V_60 = ( void * ) V_59 ;
V_23 . V_5 = TRUE ;
return T_15 ;
}
static int
F_50 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_31 ( V_30 , T_6 , T_8 , T_15 ,
V_61 , T_16 , V_62 ,
NULL ) ;
return T_15 ;
}
static int
F_51 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_52 ( T_14 , T_6 , T_8 , T_15 , V_30 , T_16 , NULL ) ;
return T_15 ;
}
static int
F_53 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_54 ( T_14 , V_30 , T_6 , T_8 , T_15 ,
V_63 , T_16 , V_64 ) ;
return T_15 ;
}
static int
F_55 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_43 ( T_14 , V_30 , T_6 , T_8 , T_15 ,
T_16 , V_58 , 29 , TRUE , F_53 ) ;
return T_15 ;
}
static int
F_56 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_31 ( V_30 , T_6 , T_8 , T_15 ,
V_65 , T_16 , V_66 ,
NULL ) ;
return T_15 ;
}
static int
F_57 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_31 ( V_30 , T_6 , T_8 , T_15 ,
V_67 , T_16 , V_68 ,
NULL ) ;
return T_15 ;
}
static int
F_58 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_59 ( T_14 , V_30 , T_6 , T_8 , T_15 ,
V_69 , T_16 , V_70 ) ;
return T_15 ;
}
static int
F_60 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_59 ( T_14 , V_30 , T_6 , T_8 , T_15 ,
V_71 , T_16 , V_72 ) ;
return T_15 ;
}
static int
F_61 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_43 ( T_14 , V_30 , T_6 , T_8 , T_15 ,
T_16 , V_58 , 25 , TRUE , F_60 ) ;
return T_15 ;
}
static int
F_62 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_36 ( T_14 , V_30 , T_6 , T_8 , T_15 , T_16 ,
NULL ) ;
return T_15 ;
}
static int
F_63 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
#line 85 "../../asn1/ansi_tcap/ansi_tcap.cnf"
if( F_18 ( T_8 , V_30 , T_6 ) )
T_15 = F_64 ( T_8 ) ;
return T_15 ;
}
static int
F_65 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
#line 91 "../../asn1/ansi_tcap/ansi_tcap.cnf"
V_23 . V_27 . V_32 = 1 ;
T_15 = F_59 ( T_14 , V_30 , T_6 , T_8 , T_15 ,
V_73 , T_16 , V_74 ) ;
return T_15 ;
}
static int
F_66 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_36 ( T_14 , V_30 , T_6 , T_8 , T_15 , T_16 ,
NULL ) ;
return T_15 ;
}
static int
F_67 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
#line 98 "../../asn1/ansi_tcap/ansi_tcap.cnf"
if( F_18 ( T_8 , V_30 , T_6 ) )
T_15 = F_64 ( T_8 ) ;
return T_15 ;
}
static int
F_68 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
#line 102 "../../asn1/ansi_tcap/ansi_tcap.cnf"
V_23 . V_27 . V_32 = 2 ;
T_15 = F_59 ( T_14 , V_30 , T_6 , T_8 , T_15 ,
V_75 , T_16 , V_76 ) ;
return T_15 ;
}
static int
F_69 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_36 ( T_14 , V_30 , T_6 , T_8 , T_15 , T_16 ,
NULL ) ;
return T_15 ;
}
static int
F_70 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
#line 108 "../../asn1/ansi_tcap/ansi_tcap.cnf"
if( F_18 ( T_8 , V_30 , T_6 ) )
T_15 = F_64 ( T_8 ) ;
return T_15 ;
}
static int
F_71 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
#line 112 "../../asn1/ansi_tcap/ansi_tcap.cnf"
V_23 . V_27 . V_32 = 3 ;
T_15 = F_59 ( T_14 , V_30 , T_6 , T_8 , T_15 ,
V_77 , T_16 , V_78 ) ;
return T_15 ;
}
static int
F_72 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_36 ( T_14 , V_30 , T_6 , T_8 , T_15 , T_16 ,
NULL ) ;
return T_15 ;
}
static int
F_73 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_25 ( T_14 , V_30 , T_6 , T_8 , T_15 , T_16 ,
NULL ) ;
return T_15 ;
}
static int
F_74 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_59 ( T_14 , V_30 , T_6 , T_8 , T_15 ,
V_79 , T_16 , V_80 ) ;
return T_15 ;
}
static int
F_75 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_76 ( T_14 , V_30 , T_6 , T_8 , T_15 ,
V_81 , T_16 , V_82 ) ;
return T_15 ;
}
static int
F_77 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_31 ( V_30 , T_6 , T_8 , T_15 ,
V_83 , T_16 , V_84 ,
NULL ) ;
return T_15 ;
}
static int
F_78 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_59 ( T_14 , V_30 , T_6 , T_8 , T_15 ,
V_85 , T_16 , V_86 ) ;
return T_15 ;
}
static int
F_79 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_31 ( V_30 , T_6 , T_8 , T_15 ,
V_87 , T_16 , V_88 ,
NULL ) ;
return T_15 ;
}
static int
F_80 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_54 ( T_14 , V_30 , T_6 , T_8 , T_15 ,
V_89 , T_16 , V_90 ) ;
return T_15 ;
}
static int
F_81 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_43 ( T_14 , V_30 , T_6 , T_8 , T_15 ,
T_16 , V_58 , 8 , TRUE , F_80 ) ;
return T_15 ;
}
static int
F_82 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_59 ( T_14 , V_30 , T_6 , T_8 , T_15 ,
V_91 , T_16 , V_92 ) ;
return T_15 ;
}
static int
F_83 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
#line 124 "../../asn1/ansi_tcap/ansi_tcap.cnf"
V_56 -> V_93 = V_94 ;
F_84 ( V_30 -> V_16 -> V_95 , V_96 , L_17 ) ;
T_15 = F_82 ( T_14 , T_8 , T_15 , V_30 , T_6 , T_16 ) ;
return T_15 ;
}
static int
F_85 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_59 ( T_14 , V_30 , T_6 , T_8 , T_15 ,
V_97 , T_16 , V_98 ) ;
return T_15 ;
}
static int
F_86 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
#line 128 "../../asn1/ansi_tcap/ansi_tcap.cnf"
V_56 -> V_93 = V_94 ;
F_84 ( V_30 -> V_16 -> V_95 , V_96 , L_18 ) ;
T_15 = F_85 ( T_14 , T_8 , T_15 , V_30 , T_6 , T_16 ) ;
return T_15 ;
}
static int
F_87 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
#line 132 "../../asn1/ansi_tcap/ansi_tcap.cnf"
V_56 -> V_93 = V_94 ;
F_84 ( V_30 -> V_16 -> V_95 , V_96 , L_19 ) ;
T_15 = F_85 ( T_14 , T_8 , T_15 , V_30 , T_6 , T_16 ) ;
return T_15 ;
}
static int
F_88 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
#line 136 "../../asn1/ansi_tcap/ansi_tcap.cnf"
V_56 -> V_93 = V_94 ;
F_84 ( V_30 -> V_16 -> V_95 , V_96 , L_20 ) ;
T_15 = F_85 ( T_14 , T_8 , T_15 , V_30 , T_6 , T_16 ) ;
return T_15 ;
}
static int
F_89 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
#line 140 "../../asn1/ansi_tcap/ansi_tcap.cnf"
V_56 -> V_93 = V_94 ;
F_84 ( V_30 -> V_16 -> V_95 , V_96 , L_21 ) ;
T_15 = F_85 ( T_14 , T_8 , T_15 , V_30 , T_6 , T_16 ) ;
return T_15 ;
}
static int
F_90 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
#line 144 "../../asn1/ansi_tcap/ansi_tcap.cnf"
V_56 -> V_93 = V_94 ;
F_84 ( V_30 -> V_16 -> V_95 , V_96 , L_22 ) ;
T_15 = F_85 ( T_14 , T_8 , T_15 , V_30 , T_6 , T_16 ) ;
return T_15 ;
}
static int
F_91 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_25 ( T_14 , V_30 , T_6 , T_8 , T_15 , T_16 ,
NULL ) ;
return T_15 ;
}
static int
F_92 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_43 ( T_14 , V_30 , T_6 , T_8 , T_15 ,
T_16 , V_58 , 23 , TRUE , F_91 ) ;
return T_15 ;
}
static int
F_93 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_43 ( T_14 , V_30 , T_6 , T_8 , T_15 ,
T_16 , V_58 , 24 , FALSE , F_51 ) ;
return T_15 ;
}
static int
F_94 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_31 ( V_30 , T_6 , T_8 , T_15 ,
V_99 , T_16 , V_100 ,
NULL ) ;
return T_15 ;
}
static int
F_95 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_59 ( T_14 , V_30 , T_6 , T_8 , T_15 ,
V_101 , T_16 , V_102 ) ;
return T_15 ;
}
static int
F_96 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
#line 148 "../../asn1/ansi_tcap/ansi_tcap.cnf"
V_56 -> V_93 = V_103 ;
F_84 ( V_30 -> V_16 -> V_95 , V_96 , L_23 ) ;
T_15 = F_95 ( T_14 , T_8 , T_15 , V_30 , T_6 , T_16 ) ;
return T_15 ;
}
static int
F_97 ( T_10 T_14 V_9 , T_7 * T_8 V_9 , int T_15 V_9 , T_11 * V_30 V_9 , T_5 * T_6 V_9 , int T_16 V_9 ) {
T_15 = F_31 ( V_30 , T_6 , T_8 , T_15 ,
V_104 , T_16 , V_105 ,
NULL ) ;
return T_15 ;
}
static void
F_98 ( T_7 * T_8 , T_4 * V_16 , T_5 * V_106 )
{
T_12 * V_31 = NULL ;
T_5 * T_6 = NULL ;
#if 0
proto_item *stat_item=NULL;
proto_tree *stat_tree=NULL;
gint offset = 0;
struct tcaphash_context_t * p_tcap_context;
dissector_handle_t subdissector_handle;
#endif
T_11 V_107 ;
F_99 ( & V_107 , V_108 , TRUE , V_16 ) ;
F_1 ( & V_23 ) ;
V_39 = V_106 ;
F_84 ( V_16 -> V_95 , V_109 , L_24 ) ;
if( V_106 ) {
V_31 = F_27 ( V_106 , V_110 , T_8 , 0 , - 1 , V_111 ) ;
T_6 = F_26 ( V_31 , V_112 ) ;
V_113 = V_31 ;
V_114 = T_6 ;
}
V_115 = NULL ;
V_116 = NULL ;
V_16 -> V_117 = & V_23 ;
V_56 = F_100 () ;
V_118 = FALSE ;
V_119 = NULL ;
F_97 ( FALSE , T_8 , 0 , & V_107 , T_6 , - 1 ) ;
#if 0
if (g_ansi_tcap_HandleSRT && !tcap_subdissector_used ) {
if (gtcap_DisplaySRT && tree) {
stat_item = proto_tree_add_text(tree, tvb, 0, 0, "Stat");
PROTO_ITEM_SET_GENERATED(stat_item);
stat_tree = proto_item_add_subtree(stat_item, ett_ansi_tcap_stat);
}
p_tcap_context=tcapsrt_call_matching(tvb, pinfo, stat_tree, gp_tcapsrt_info);
ansi_tcap_private.context=p_tcap_context;
if ( p_tcap_context && cur_oid && !p_tcap_context->oid_present ) {
g_strlcpy(p_tcap_context->oid, cur_oid, sizeof(p_tcap_context->oid));
if ( (subdissector_handle = dissector_get_string_handle(ber_oid_dissector_table, cur_oid)) ) {
p_tcap_context->subdissector_handle=subdissector_handle;
p_tcap_context->oid_present=TRUE;
}
}
if (g_ansi_tcap_HandleSRT && p_tcap_context && p_tcap_context->callback) {
(p_tcap_context->callback)(tvb, pinfo, stat_tree, p_tcap_context);
}
}
#endif
}
void
F_101 ( void )
{
V_40 = F_102 ( L_25 ) ;
V_120 = F_103 ( L_26 ) ;
}
void
F_104 ( void )
{
T_17 * V_121 ;
static T_18 V_122 [] = {
{ & V_123 ,
{ L_27 ,
L_28 ,
V_124 , V_125 , NULL , 0x0 ,
NULL , V_126 }
} ,
{ & V_127 ,
{ L_29 ,
L_30 ,
V_128 , V_129 , NULL , 0x0 ,
L_31 , V_126 }
} ,
{ & V_130 ,
{ L_32 ,
L_33 ,
V_128 , V_129 , NULL , 0x0 ,
L_34 , V_126 }
} ,
{ & V_131 ,
{ L_35 ,
L_36 ,
V_132 , V_129 , NULL , 0x0 ,
L_37 , V_126 }
} ,
{ & V_133 ,
{ L_38 ,
L_39 ,
V_124 , V_125 , NULL , 0x0 ,
NULL , V_126 }
} ,
{ & V_46 ,
{ L_40 , L_41 ,
V_134 , 16 , NULL , 0x8000 ,
NULL , V_126 }
} ,
{ & V_48 ,
{ L_42 ,
L_43 ,
V_135 , V_125 , F_105 ( V_136 ) , 0x7f00 ,
NULL , V_126 }
} ,
{ & V_49 ,
{ L_44 ,
L_45 ,
V_135 , V_125 , NULL , 0x00ff ,
NULL , V_126 }
} ,
#line 1 "../../asn1/ansi_tcap/packet-ansi_tcap-hfarr.c"
{ & V_33 ,
{ L_46 , L_47 ,
V_137 , V_125 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_34 ,
{ L_48 , L_49 ,
V_137 , V_125 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_138 ,
{ L_46 , L_47 ,
V_137 , V_125 , NULL , 0 ,
L_50 , V_126 } } ,
{ & V_139 ,
{ L_48 , L_49 ,
V_137 , V_125 , NULL , 0 ,
L_51 , V_126 } } ,
{ & V_140 ,
{ L_52 , L_53 ,
V_141 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_142 ,
{ L_54 , L_55 ,
V_141 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_143 ,
{ L_56 , L_57 ,
V_141 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_144 ,
{ L_58 , L_59 ,
V_141 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_145 ,
{ L_60 , L_61 ,
V_141 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_146 ,
{ L_62 , L_63 ,
V_141 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_147 ,
{ L_64 , L_65 ,
V_141 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_148 ,
{ L_66 , L_67 ,
V_149 , V_129 , NULL , 0 ,
L_68 , V_126 } } ,
{ & V_150 ,
{ L_69 , L_70 ,
V_141 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_151 ,
{ L_71 , L_72 ,
V_124 , V_125 , NULL , 0 ,
L_73 , V_126 } } ,
{ & V_152 ,
{ L_74 , L_75 ,
V_141 , V_129 , NULL , 0 ,
L_76 , V_126 } } ,
{ & V_153 ,
{ L_77 , L_78 ,
V_124 , V_125 , F_105 ( V_154 ) , 0 ,
NULL , V_126 } } ,
{ & V_155 ,
{ L_79 , L_80 ,
V_137 , V_125 , F_105 ( V_156 ) , 0 ,
L_81 , V_126 } } ,
{ & V_157 ,
{ L_82 , L_83 ,
V_141 , V_129 , NULL , 0 ,
L_84 , V_126 } } ,
{ & V_158 ,
{ L_85 , L_86 ,
V_149 , V_129 , NULL , 0 ,
L_87 , V_126 } } ,
{ & V_159 ,
{ L_88 , L_89 ,
V_124 , V_125 , F_105 ( V_160 ) , 0 ,
NULL , V_126 } } ,
{ & V_161 ,
{ L_90 , L_91 ,
V_137 , V_125 , NULL , 0 ,
L_92 , V_126 } } ,
{ & V_162 ,
{ L_93 , L_94 ,
V_163 , V_129 , NULL , 0 ,
L_95 , V_126 } } ,
{ & V_164 ,
{ L_82 , L_83 ,
V_124 , V_125 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_165 ,
{ L_96 , L_97 ,
V_124 , V_125 , F_105 ( V_166 ) , 0 ,
NULL , V_126 } } ,
{ & V_167 ,
{ L_98 , L_99 ,
V_137 , V_125 , NULL , 0 ,
L_51 , V_126 } } ,
{ & V_168 ,
{ L_100 , L_101 ,
V_163 , V_129 , NULL , 0 ,
L_102 , V_126 } } ,
{ & V_169 ,
{ L_103 , L_104 ,
V_141 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_170 ,
{ L_105 , L_106 ,
V_141 , V_129 , NULL , 0 ,
L_107 , V_126 } } ,
{ & V_171 ,
{ L_108 , L_109 ,
V_124 , V_125 , F_105 ( V_172 ) , 0 ,
NULL , V_126 } } ,
{ & V_173 ,
{ L_110 , L_111 ,
V_137 , V_125 , NULL , 0 ,
L_51 , V_126 } } ,
{ & V_174 ,
{ L_112 , L_113 ,
V_163 , V_129 , NULL , 0 ,
L_102 , V_126 } } ,
{ & V_175 ,
{ L_114 , L_115 ,
V_124 , V_125 , F_105 ( V_176 ) , 0 ,
NULL , V_126 } } ,
{ & V_177 ,
{ L_116 , L_117 ,
V_141 , V_129 , NULL , 0 ,
L_118 , V_126 } } ,
{ & V_178 ,
{ L_119 , L_120 ,
V_141 , V_129 , NULL , 0 ,
L_121 , V_126 } } ,
{ & V_179 ,
{ L_122 , L_123 ,
V_141 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_180 ,
{ L_124 , L_125 ,
V_141 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_181 ,
{ L_126 , L_127 ,
V_141 , V_129 , NULL , 0 ,
L_118 , V_126 } } ,
{ & V_182 ,
{ L_128 , L_129 ,
V_141 , V_129 , NULL , 0 ,
L_121 , V_126 } } ,
{ & V_183 ,
{ L_130 , L_131 ,
V_149 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_184 ,
{ L_132 , L_133 ,
V_124 , V_125 , F_105 ( V_185 ) , 0 ,
NULL , V_126 } } ,
{ & V_186 ,
{ L_134 , L_135 ,
V_141 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_187 ,
{ L_136 , L_137 ,
V_149 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_188 ,
{ L_134 , L_135 ,
V_141 , V_129 , NULL , 0 ,
L_138 , V_126 } } ,
{ & V_189 ,
{ L_136 , L_137 ,
V_149 , V_129 , NULL , 0 ,
L_139 , V_126 } } ,
{ & V_190 ,
{ L_140 , L_141 ,
V_124 , V_125 , F_105 ( V_191 ) , 0 ,
NULL , V_126 } } ,
{ & V_192 ,
{ L_134 , L_135 ,
V_141 , V_129 , NULL , 0 ,
L_142 , V_126 } } ,
{ & V_193 ,
{ L_136 , L_137 ,
V_149 , V_129 , NULL , 0 ,
L_143 , V_126 } } ,
{ & V_194 ,
{ L_144 , L_145 ,
V_137 , V_125 , F_105 ( V_195 ) , 0 ,
L_146 , V_126 } } ,
{ & V_196 ,
{ L_134 , L_135 ,
V_124 , V_125 , F_105 ( V_197 ) , 0 ,
L_147 , V_126 } } ,
{ & V_198 ,
{ L_148 , L_149 ,
V_141 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_199 ,
{ L_150 , L_151 ,
V_141 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
#line 503 "../../asn1/ansi_tcap/packet-ansi_tcap-template.c"
} ;
static T_19 * V_200 [] = {
& V_112 ,
& V_201 ,
& V_202 ,
& V_203 ,
& V_204 ,
& V_45 ,
#line 1 "../../asn1/ansi_tcap/packet-ansi_tcap-ettarr.c"
& V_51 ,
& V_53 ,
& V_105 ,
& V_92 ,
& V_98 ,
& V_102 ,
& V_100 ,
& V_72 ,
& V_62 ,
& V_66 ,
& V_64 ,
& V_70 ,
& V_68 ,
& V_90 ,
& V_88 ,
& V_74 ,
& V_76 ,
& V_78 ,
& V_86 ,
& V_84 ,
& V_80 ,
& V_82 ,
#line 514 "../../asn1/ansi_tcap/packet-ansi_tcap-template.c"
} ;
static T_20 V_205 [] = {
{ L_152 , L_153 , 0 } ,
{ L_154 , L_155 , 1 } ,
{ L_156 , L_157 , 2 } ,
{ NULL , NULL , - 1 }
} ;
V_110 = F_106 ( V_206 , V_207 , V_208 ) ;
F_107 ( L_158 , F_98 , V_110 ) ;
V_38 = F_108 ( L_159 , L_160 , V_135 , V_125 ) ;
F_109 ( V_110 , V_122 , F_110 ( V_122 ) ) ;
F_111 ( V_200 , F_110 ( V_200 ) ) ;
V_121 = F_112 ( V_110 , F_101 ) ;
F_113 ( V_121 , L_161 ,
L_162 ,
L_163 ,
& V_25 , V_205 , FALSE ) ;
F_114 ( & F_8 ) ;
}
