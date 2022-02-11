static void F_1 ( struct V_1 * V_2 ) {
memset ( V_2 , '\0' , sizeof( * V_2 ) ) ;
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = FALSE ;
V_2 -> V_6 = NULL ;
}
static void
F_2 ( T_1 * V_7 , T_2 * T_3 V_8 , T_4 * T_5 V_8 ) {
struct V_9 * V_10 ;
T_6 * V_11 , * V_12 ;
char * V_13 ;
V_11 = F_3 ( F_4 () , & ( V_7 -> V_11 ) ) ;
V_12 = F_3 ( F_4 () , & ( V_7 -> V_12 ) ) ;
if ( ( ! V_7 -> V_14 -> V_15 . V_16 ) && ( V_17 . V_6 ) ) {
switch( V_18 ) {
case V_19 :
V_13 = F_5 ( F_4 () , V_17 . V_6 ) ;
break;
case V_20 :
V_13 = F_6 ( F_4 () , L_1 , V_17 . V_6 , V_11 ) ;
break;
case V_21 :
default:
V_13 = F_6 ( F_4 () , L_2 , V_17 . V_6 , V_11 , V_12 ) ;
break;
}
V_10 = (struct V_9 * ) F_7 ( V_22 , V_13 ) ;
if( V_10 )
return;
V_10 = F_8 ( F_9 () , struct V_9 ) ;
V_10 -> V_23 = V_17 . V_24 . V_23 ;
V_10 -> V_25 = V_17 . V_24 . V_25 ;
V_10 -> V_26 = V_17 . V_24 . V_26 ;
F_10 ( V_22 ,
F_5 ( F_9 () , V_13 ) ,
V_10 ) ;
}
}
static T_7
F_11 ( T_1 * V_7 , T_2 * T_3 V_8 , T_4 * T_5 V_8 ) {
struct V_9 * V_10 ;
T_6 * V_11 , * V_12 ;
char * V_13 ;
if ( ! V_17 . V_6 ) {
return FALSE ;
}
V_11 = F_3 ( F_4 () , & ( V_7 -> V_11 ) ) ;
V_12 = F_3 ( F_4 () , & ( V_7 -> V_12 ) ) ;
V_13 = ( char * ) F_12 ( F_4 () , V_27 ) ;
V_13 [ 0 ] = '\0' ;
switch( V_18 ) {
case V_19 :
F_13 ( V_13 , V_27 , L_3 , V_17 . V_6 ) ;
break;
case V_20 :
F_13 ( V_13 , V_27 , L_1 , V_17 . V_6 , V_12 ) ;
break;
case V_21 :
default:
F_13 ( V_13 , V_27 , L_2 , V_17 . V_6 , V_12 , V_11 ) ;
break;
}
V_10 = (struct V_9 * ) F_7 ( V_22 , V_13 ) ;
if( V_10 ) {
V_17 . V_24 . V_23 = V_10 -> V_23 ;
V_17 . V_24 . V_25 = V_10 -> V_25 ;
V_17 . V_24 . V_26 = V_10 -> V_26 ;
return TRUE ;
}
return FALSE ;
}
static T_7
F_14 ( T_4 * T_5 , T_8 * V_28 , T_2 * T_3 ) {
T_9 * V_29 ;
if( V_17 . V_24 . V_30 == 1 ) {
F_2 ( V_28 -> V_7 , T_3 , T_5 ) ;
} else{
if( F_11 ( V_28 -> V_7 , T_3 , T_5 ) ) {
if( V_17 . V_24 . V_23 == 0 ) {
V_29 = F_15 ( T_3 , V_31 , T_5 , 0 , 0 , V_17 . V_24 . V_25 ) ;
} else{
V_29 = F_15 ( T_3 , V_32 , T_5 , 0 , 0 , V_17 . V_24 . V_26 ) ;
}
F_16 ( V_29 ) ;
V_17 . V_24 . V_33 = V_29 ;
}
}
if( V_17 . V_24 . V_23 == 0 ) {
T_10 V_34 = ( V_17 . V_24 . V_25 & 0x7f00 ) >> 8 ;
T_10 V_35 = ( T_10 ) ( V_17 . V_24 . V_25 & 0xff ) ;
if( ! F_17 ( V_36 , V_17 . V_24 . V_25 , T_5 , V_28 -> V_7 , V_37 ) ) {
F_18 ( T_3 , V_28 -> V_7 , & V_38 , T_5 , 0 , - 1 ,
L_4
L_5 ,
V_17 . V_24 . V_25 , V_34 , V_35 ) ;
return FALSE ;
}
return TRUE ;
} else if( V_17 . V_24 . V_23 == 1 ) {
if( ( V_17 . V_24 . V_26 & 0x0900 ) != 0x0900 ) {
F_18 ( T_3 , V_28 -> V_7 , & V_38 , T_5 , 0 , - 1 ,
L_6
L_7 ,
V_17 . V_24 . V_26 ) ;
return FALSE ;
}
}
F_19 ( V_39 , T_5 , V_28 -> V_7 , V_37 , & V_17 ) ;
return TRUE ;
}
static int
F_20 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
#line 22 "./asn1/ansi_tcap/ansi_tcap.cnf"
T_2 * V_40 ;
T_9 * V_41 ;
int V_42 = T_12 ;
T_10 V_34 ;
T_10 V_35 ;
T_12 = F_21 ( T_11 , V_28 , T_3 , T_5 , T_12 , T_13 ,
& V_17 . V_24 . V_25 ) ;
V_17 . V_24 . V_25 = ( V_17 . V_24 . V_25 & 0x7fff ) ;
V_40 = F_22 ( V_28 -> V_43 , V_44 ) ;
V_34 = ( V_17 . V_24 . V_25 & 0x7f00 ) >> 8 ;
V_35 = ( T_10 ) ( V_17 . V_24 . V_25 & 0xff ) ;
F_23 ( V_40 , V_45 , T_5 , V_42 , 2 , V_46 ) ;
F_23 ( V_40 , V_47 , T_5 , V_42 , 2 , V_46 ) ;
V_41 = F_23 ( V_40 , V_48 , T_5 , V_42 , 2 , V_46 ) ;
switch( V_34 ) {
case 0 :
break;
case 1 :
if( V_35 == 1 ) {
F_24 ( V_41 , L_8 ) ;
} else if ( V_35 == 2 ) {
F_24 ( V_41 , L_9 ) ;
}
break;
case 2 :
if ( V_35 == 1 ) {
F_24 ( V_41 , L_10 ) ;
}
break;
case 3 :
if ( V_35 == 1 ) {
F_24 ( V_41 , L_11 ) ;
} else if ( V_35 == 2 ) {
F_24 ( V_41 , L_12 ) ;
}
break;
case 4 :
if ( V_35 == 1 ) {
F_24 ( V_41 , L_13 ) ;
} else if ( V_35 == 2 ) {
F_24 ( V_41 , L_14 ) ;
} else if ( V_35 == 3 ) {
F_24 ( V_41 , L_15 ) ;
} else if ( V_35 == 4 ) {
F_24 ( V_41 , L_16 ) ;
}
break;
default:
break;
}
return T_12 ;
}
static int
F_25 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_21 ( T_11 , V_28 , T_3 , T_5 , T_12 , T_13 ,
& V_17 . V_24 . V_26 ) ;
return T_12 ;
}
static int
F_26 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_27 ( V_28 , T_3 , T_5 , T_12 ,
V_49 , T_13 , V_50 ,
& V_17 . V_24 . V_23 ) ;
#line 18 "./asn1/ansi_tcap/ansi_tcap.cnf"
V_17 . V_24 . V_33 = V_28 -> V_43 ;
return T_12 ;
}
static int
F_28 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_21 ( T_11 , V_28 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_29 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_21 ( T_11 , V_28 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_30 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_27 ( V_28 , T_3 , T_5 , T_12 ,
V_51 , T_13 , V_52 ,
NULL ) ;
return T_12 ;
}
static int
F_31 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
#line 154 "./asn1/ansi_tcap/ansi_tcap.cnf"
T_4 * V_53 ;
T_10 V_54 ;
T_12 = F_32 ( T_11 , V_28 , T_3 , T_5 , T_12 , T_13 ,
& V_53 ) ;
if( V_53 ) {
V_54 = F_33 ( V_53 , 0 ) ;
if( V_54 != 0 ) {
if ( V_54 > 4 ) {
V_17 . V_6 = F_34 ( F_4 () , V_53 , 4 , V_54 - 4 ) ;
} else{
V_17 . V_6 = F_34 ( F_4 () , V_53 , 0 , V_54 ) ;
}
}
switch( V_54 ) {
case 1 :
V_55 -> V_56 = F_35 ( V_53 , 0 ) ;
break;
case 2 :
V_55 -> V_56 = F_36 ( V_53 , 0 ) ;
break;
case 4 :
V_55 -> V_56 = F_37 ( V_53 , 0 ) ;
break;
default:
V_55 -> V_56 = 0 ;
break;
}
}
return T_12 ;
}
static int
F_38 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_39 ( T_11 , V_28 , T_3 , T_5 , T_12 ,
T_13 , V_57 , 7 , TRUE , F_31 ) ;
return T_12 ;
}
static int
F_40 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_32 ( T_11 , V_28 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_41 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_39 ( T_11 , V_28 , T_3 , T_5 , T_12 ,
T_13 , V_57 , 26 , TRUE , F_40 ) ;
return T_12 ;
}
static int
F_42 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_21 ( T_11 , V_28 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_43 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_39 ( T_11 , V_28 , T_3 , T_5 , T_12 ,
T_13 , V_57 , 27 , TRUE , F_42 ) ;
return T_12 ;
}
static int
F_44 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_45 ( T_11 , V_28 , T_3 , T_5 , T_12 , T_13 , NULL ) ;
return T_12 ;
}
static int
F_46 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
#line 118 "./asn1/ansi_tcap/ansi_tcap.cnf"
static const char * V_58 ;
T_12 = F_39 ( T_11 , V_28 , T_3 , T_5 , T_12 ,
T_13 , V_57 , 28 , TRUE , F_44 ) ;
V_17 . V_59 = ( const void * ) V_58 ;
V_17 . V_5 = TRUE ;
return T_12 ;
}
static int
F_47 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_27 ( V_28 , T_3 , T_5 , T_12 ,
V_60 , T_13 , V_61 ,
NULL ) ;
return T_12 ;
}
static int
F_48 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_49 ( T_11 , T_3 , T_5 , T_12 , V_28 , T_13 , NULL ) ;
return T_12 ;
}
static int
F_50 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_51 ( T_11 , V_28 , T_3 , T_5 , T_12 ,
V_62 , T_13 , V_63 ) ;
return T_12 ;
}
static int
F_52 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_39 ( T_11 , V_28 , T_3 , T_5 , T_12 ,
T_13 , V_57 , 29 , TRUE , F_50 ) ;
return T_12 ;
}
static int
F_53 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_27 ( V_28 , T_3 , T_5 , T_12 ,
V_64 , T_13 , V_65 ,
NULL ) ;
return T_12 ;
}
static int
F_54 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_27 ( V_28 , T_3 , T_5 , T_12 ,
V_66 , T_13 , V_67 ,
NULL ) ;
return T_12 ;
}
static int
F_55 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_56 ( T_11 , V_28 , T_3 , T_5 , T_12 ,
V_68 , T_13 , V_69 ) ;
return T_12 ;
}
static int
F_57 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_56 ( T_11 , V_28 , T_3 , T_5 , T_12 ,
V_70 , T_13 , V_71 ) ;
return T_12 ;
}
static int
F_58 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_39 ( T_11 , V_28 , T_3 , T_5 , T_12 ,
T_13 , V_57 , 25 , TRUE , F_57 ) ;
return T_12 ;
}
static int
F_59 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_32 ( T_11 , V_28 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_60 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
#line 87 "./asn1/ansi_tcap/ansi_tcap.cnf"
if( F_14 ( T_5 , V_28 , T_3 ) )
T_12 = F_61 ( T_5 ) ;
return T_12 ;
}
static int
F_62 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
#line 93 "./asn1/ansi_tcap/ansi_tcap.cnf"
V_17 . V_24 . V_30 = 1 ;
T_12 = F_56 ( T_11 , V_28 , T_3 , T_5 , T_12 ,
V_72 , T_13 , V_73 ) ;
return T_12 ;
}
static int
F_63 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_32 ( T_11 , V_28 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_64 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
#line 100 "./asn1/ansi_tcap/ansi_tcap.cnf"
if( F_14 ( T_5 , V_28 , T_3 ) )
T_12 = F_61 ( T_5 ) ;
return T_12 ;
}
static int
F_65 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
#line 104 "./asn1/ansi_tcap/ansi_tcap.cnf"
V_17 . V_24 . V_30 = 2 ;
T_12 = F_56 ( T_11 , V_28 , T_3 , T_5 , T_12 ,
V_74 , T_13 , V_75 ) ;
return T_12 ;
}
static int
F_66 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_32 ( T_11 , V_28 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_67 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
#line 110 "./asn1/ansi_tcap/ansi_tcap.cnf"
if( F_14 ( T_5 , V_28 , T_3 ) )
T_12 = F_61 ( T_5 ) ;
return T_12 ;
}
static int
F_68 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
#line 114 "./asn1/ansi_tcap/ansi_tcap.cnf"
V_17 . V_24 . V_30 = 3 ;
T_12 = F_56 ( T_11 , V_28 , T_3 , T_5 , T_12 ,
V_76 , T_13 , V_77 ) ;
return T_12 ;
}
static int
F_69 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_32 ( T_11 , V_28 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_70 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_21 ( T_11 , V_28 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_71 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_56 ( T_11 , V_28 , T_3 , T_5 , T_12 ,
V_78 , T_13 , V_79 ) ;
return T_12 ;
}
static int
F_72 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_73 ( T_11 , V_28 , T_3 , T_5 , T_12 ,
V_80 , T_13 , V_81 ) ;
return T_12 ;
}
static int
F_74 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_27 ( V_28 , T_3 , T_5 , T_12 ,
V_82 , T_13 , V_83 ,
NULL ) ;
return T_12 ;
}
static int
F_75 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_56 ( T_11 , V_28 , T_3 , T_5 , T_12 ,
V_84 , T_13 , V_85 ) ;
return T_12 ;
}
static int
F_76 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_27 ( V_28 , T_3 , T_5 , T_12 ,
V_86 , T_13 , V_87 ,
NULL ) ;
return T_12 ;
}
static int
F_77 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_51 ( T_11 , V_28 , T_3 , T_5 , T_12 ,
V_88 , T_13 , V_89 ) ;
return T_12 ;
}
static int
F_78 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_39 ( T_11 , V_28 , T_3 , T_5 , T_12 ,
T_13 , V_57 , 8 , TRUE , F_77 ) ;
return T_12 ;
}
static int
F_79 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_56 ( T_11 , V_28 , T_3 , T_5 , T_12 ,
V_90 , T_13 , V_91 ) ;
return T_12 ;
}
static int
F_80 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
#line 126 "./asn1/ansi_tcap/ansi_tcap.cnf"
V_55 -> V_92 = V_93 ;
F_81 ( V_28 -> V_7 -> V_94 , V_95 , L_17 ) ;
T_12 = F_79 ( T_11 , T_5 , T_12 , V_28 , T_3 , T_13 ) ;
return T_12 ;
}
static int
F_82 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_56 ( T_11 , V_28 , T_3 , T_5 , T_12 ,
V_96 , T_13 , V_97 ) ;
return T_12 ;
}
static int
F_83 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
#line 130 "./asn1/ansi_tcap/ansi_tcap.cnf"
V_55 -> V_92 = V_93 ;
F_81 ( V_28 -> V_7 -> V_94 , V_95 , L_18 ) ;
T_12 = F_82 ( T_11 , T_5 , T_12 , V_28 , T_3 , T_13 ) ;
return T_12 ;
}
static int
F_84 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
#line 134 "./asn1/ansi_tcap/ansi_tcap.cnf"
V_55 -> V_92 = V_93 ;
F_81 ( V_28 -> V_7 -> V_94 , V_95 , L_19 ) ;
T_12 = F_82 ( T_11 , T_5 , T_12 , V_28 , T_3 , T_13 ) ;
return T_12 ;
}
static int
F_85 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
#line 138 "./asn1/ansi_tcap/ansi_tcap.cnf"
V_55 -> V_92 = V_93 ;
F_81 ( V_28 -> V_7 -> V_94 , V_95 , L_20 ) ;
T_12 = F_82 ( T_11 , T_5 , T_12 , V_28 , T_3 , T_13 ) ;
return T_12 ;
}
static int
F_86 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
#line 142 "./asn1/ansi_tcap/ansi_tcap.cnf"
V_55 -> V_92 = V_93 ;
F_81 ( V_28 -> V_7 -> V_94 , V_95 , L_21 ) ;
T_12 = F_82 ( T_11 , T_5 , T_12 , V_28 , T_3 , T_13 ) ;
return T_12 ;
}
static int
F_87 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
#line 146 "./asn1/ansi_tcap/ansi_tcap.cnf"
V_55 -> V_92 = V_93 ;
F_81 ( V_28 -> V_7 -> V_94 , V_95 , L_22 ) ;
T_12 = F_82 ( T_11 , T_5 , T_12 , V_28 , T_3 , T_13 ) ;
return T_12 ;
}
static int
F_88 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_21 ( T_11 , V_28 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_89 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_39 ( T_11 , V_28 , T_3 , T_5 , T_12 ,
T_13 , V_57 , 23 , TRUE , F_88 ) ;
return T_12 ;
}
static int
F_90 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_39 ( T_11 , V_28 , T_3 , T_5 , T_12 ,
T_13 , V_57 , 24 , FALSE , F_48 ) ;
return T_12 ;
}
static int
F_91 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_27 ( V_28 , T_3 , T_5 , T_12 ,
V_98 , T_13 , V_99 ,
NULL ) ;
return T_12 ;
}
static int
F_92 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_56 ( T_11 , V_28 , T_3 , T_5 , T_12 ,
V_100 , T_13 , V_101 ) ;
return T_12 ;
}
static int
F_93 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
#line 150 "./asn1/ansi_tcap/ansi_tcap.cnf"
V_55 -> V_92 = V_102 ;
F_81 ( V_28 -> V_7 -> V_94 , V_95 , L_23 ) ;
T_12 = F_92 ( T_11 , T_5 , T_12 , V_28 , T_3 , T_13 ) ;
return T_12 ;
}
static int
F_94 ( T_7 T_11 V_8 , T_4 * T_5 V_8 , int T_12 V_8 , T_8 * V_28 V_8 , T_2 * T_3 V_8 , int T_13 V_8 ) {
T_12 = F_27 ( V_28 , T_3 , T_5 , T_12 ,
V_103 , T_13 , V_104 ,
NULL ) ;
return T_12 ;
}
static int
F_95 ( T_4 * T_5 , T_1 * V_7 , T_2 * V_105 , void * T_14 V_8 )
{
T_9 * V_29 = NULL ;
T_2 * T_3 = NULL ;
#if 0
proto_item *stat_item=NULL;
proto_tree *stat_tree=NULL;
gint offset = 0;
struct tcaphash_context_t * p_tcap_context;
dissector_handle_t subdissector_handle;
#endif
T_8 V_106 ;
F_96 ( & V_106 , V_107 , TRUE , V_7 ) ;
F_1 ( & V_17 ) ;
V_37 = V_105 ;
F_81 ( V_7 -> V_94 , V_108 , L_24 ) ;
if( V_105 ) {
V_29 = F_23 ( V_105 , V_109 , T_5 , 0 , - 1 , V_110 ) ;
T_3 = F_22 ( V_29 , V_111 ) ;
V_112 = V_29 ;
V_113 = T_3 ;
}
V_114 = NULL ;
V_115 = NULL ;
V_55 = F_97 () ;
V_116 = FALSE ;
V_117 = NULL ;
F_94 ( FALSE , T_5 , 0 , & V_106 , T_3 , - 1 ) ;
#if 0
if (g_ansi_tcap_HandleSRT && !tcap_subdissector_used ) {
if (gtcap_DisplaySRT && tree) {
stat_tree = proto_tree_add_subtree(tree, tvb, 0, 0, ett_ansi_tcap_stat, &stat_item, "Stat");
PROTO_ITEM_SET_GENERATED(stat_item);
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
return F_98 ( T_5 ) ;
}
void
F_99 ( void )
{
V_39 = F_100 ( L_25 , V_109 ) ;
V_118 = F_101 ( L_26 ) ;
}
void
F_102 ( void )
{
T_15 * V_119 ;
static T_16 V_120 [] = {
{ & V_121 ,
{ L_27 ,
L_28 ,
V_122 , V_123 , NULL , 0x0 ,
NULL , V_124 }
} ,
{ & V_125 ,
{ L_29 ,
L_30 ,
V_126 , V_127 , NULL , 0x0 ,
L_31 , V_124 }
} ,
{ & V_128 ,
{ L_32 ,
L_33 ,
V_126 , V_127 , NULL , 0x0 ,
L_34 , V_124 }
} ,
{ & V_129 ,
{ L_35 ,
L_36 ,
V_130 , V_127 , NULL , 0x0 ,
L_37 , V_124 }
} ,
{ & V_131 ,
{ L_38 ,
L_39 ,
V_122 , V_123 , NULL , 0x0 ,
NULL , V_124 }
} ,
{ & V_45 ,
{ L_40 , L_41 ,
V_132 , 16 , NULL , 0x8000 ,
NULL , V_124 }
} ,
{ & V_47 ,
{ L_42 ,
L_43 ,
V_133 , V_123 , F_103 ( V_134 ) , 0x7f00 ,
NULL , V_124 }
} ,
{ & V_48 ,
{ L_44 ,
L_45 ,
V_133 , V_123 , NULL , 0x00ff ,
NULL , V_124 }
} ,
#line 1 "./asn1/ansi_tcap/packet-ansi_tcap-hfarr.c"
{ & V_31 ,
{ L_46 , L_47 ,
V_135 , V_123 , NULL , 0 ,
NULL , V_124 } } ,
{ & V_32 ,
{ L_48 , L_49 ,
V_135 , V_123 , NULL , 0 ,
NULL , V_124 } } ,
{ & V_136 ,
{ L_46 , L_47 ,
V_135 , V_123 , NULL , 0 ,
L_50 , V_124 } } ,
{ & V_137 ,
{ L_48 , L_49 ,
V_122 , V_123 , F_103 ( V_138 ) , 0 ,
L_51 , V_124 } } ,
{ & V_139 ,
{ L_52 , L_53 ,
V_140 , V_127 , NULL , 0 ,
NULL , V_124 } } ,
{ & V_141 ,
{ L_54 , L_55 ,
V_140 , V_127 , NULL , 0 ,
NULL , V_124 } } ,
{ & V_142 ,
{ L_56 , L_57 ,
V_140 , V_127 , NULL , 0 ,
NULL , V_124 } } ,
{ & V_143 ,
{ L_58 , L_59 ,
V_140 , V_127 , NULL , 0 ,
NULL , V_124 } } ,
{ & V_144 ,
{ L_60 , L_61 ,
V_140 , V_127 , NULL , 0 ,
NULL , V_124 } } ,
{ & V_145 ,
{ L_62 , L_63 ,
V_140 , V_127 , NULL , 0 ,
NULL , V_124 } } ,
{ & V_146 ,
{ L_64 , L_65 ,
V_140 , V_127 , NULL , 0 ,
NULL , V_124 } } ,
{ & V_147 ,
{ L_66 , L_67 ,
V_148 , V_127 , NULL , 0 ,
L_68 , V_124 } } ,
{ & V_149 ,
{ L_69 , L_70 ,
V_140 , V_127 , NULL , 0 ,
NULL , V_124 } } ,
{ & V_150 ,
{ L_71 , L_72 ,
V_122 , V_123 , NULL , 0 ,
L_73 , V_124 } } ,
{ & V_151 ,
{ L_74 , L_75 ,
V_140 , V_127 , NULL , 0 ,
L_76 , V_124 } } ,
{ & V_152 ,
{ L_77 , L_78 ,
V_122 , V_123 , F_103 ( V_153 ) , 0 ,
NULL , V_124 } } ,
{ & V_154 ,
{ L_79 , L_80 ,
V_135 , V_123 , F_103 ( V_155 ) , 0 ,
L_81 , V_124 } } ,
{ & V_156 ,
{ L_82 , L_83 ,
V_140 , V_127 , NULL , 0 ,
L_84 , V_124 } } ,
{ & V_157 ,
{ L_85 , L_86 ,
V_148 , V_127 , NULL , 0 ,
L_87 , V_124 } } ,
{ & V_158 ,
{ L_88 , L_89 ,
V_122 , V_123 , F_103 ( V_159 ) , 0 ,
NULL , V_124 } } ,
{ & V_160 ,
{ L_90 , L_91 ,
V_135 , V_123 , NULL , 0 ,
L_92 , V_124 } } ,
{ & V_161 ,
{ L_93 , L_94 ,
V_162 , V_127 , NULL , 0 ,
L_95 , V_124 } } ,
{ & V_163 ,
{ L_82 , L_96 ,
V_122 , V_123 , NULL , 0 ,
NULL , V_124 } } ,
{ & V_164 ,
{ L_97 , L_98 ,
V_122 , V_123 , F_103 ( V_165 ) , 0 ,
NULL , V_124 } } ,
{ & V_166 ,
{ L_99 , L_100 ,
V_135 , V_123 , NULL , 0 ,
L_101 , V_124 } } ,
{ & V_167 ,
{ L_102 , L_103 ,
V_162 , V_127 , NULL , 0 ,
L_104 , V_124 } } ,
{ & V_168 ,
{ L_105 , L_106 ,
V_140 , V_127 , NULL , 0 ,
NULL , V_124 } } ,
{ & V_169 ,
{ L_107 , L_108 ,
V_140 , V_127 , NULL , 0 ,
L_109 , V_124 } } ,
{ & V_170 ,
{ L_110 , L_111 ,
V_122 , V_123 , F_103 ( V_171 ) , 0 ,
NULL , V_124 } } ,
{ & V_172 ,
{ L_112 , L_113 ,
V_135 , V_123 , NULL , 0 ,
L_101 , V_124 } } ,
{ & V_173 ,
{ L_114 , L_115 ,
V_162 , V_127 , NULL , 0 ,
L_104 , V_124 } } ,
{ & V_174 ,
{ L_116 , L_117 ,
V_122 , V_123 , F_103 ( V_175 ) , 0 ,
NULL , V_124 } } ,
{ & V_176 ,
{ L_118 , L_119 ,
V_140 , V_127 , NULL , 0 ,
L_120 , V_124 } } ,
{ & V_177 ,
{ L_121 , L_122 ,
V_140 , V_127 , NULL , 0 ,
L_123 , V_124 } } ,
{ & V_178 ,
{ L_124 , L_125 ,
V_140 , V_127 , NULL , 0 ,
NULL , V_124 } } ,
{ & V_179 ,
{ L_126 , L_127 ,
V_140 , V_127 , NULL , 0 ,
NULL , V_124 } } ,
{ & V_180 ,
{ L_128 , L_129 ,
V_140 , V_127 , NULL , 0 ,
L_120 , V_124 } } ,
{ & V_181 ,
{ L_130 , L_131 ,
V_140 , V_127 , NULL , 0 ,
L_123 , V_124 } } ,
{ & V_182 ,
{ L_132 , L_133 ,
V_148 , V_127 , NULL , 0 ,
NULL , V_124 } } ,
{ & V_183 ,
{ L_134 , L_135 ,
V_122 , V_123 , F_103 ( V_184 ) , 0 ,
NULL , V_124 } } ,
{ & V_185 ,
{ L_136 , L_137 ,
V_140 , V_127 , NULL , 0 ,
NULL , V_124 } } ,
{ & V_186 ,
{ L_138 , L_139 ,
V_148 , V_127 , NULL , 0 ,
NULL , V_124 } } ,
{ & V_187 ,
{ L_136 , L_137 ,
V_140 , V_127 , NULL , 0 ,
L_140 , V_124 } } ,
{ & V_188 ,
{ L_138 , L_139 ,
V_148 , V_127 , NULL , 0 ,
L_141 , V_124 } } ,
{ & V_189 ,
{ L_142 , L_143 ,
V_122 , V_123 , F_103 ( V_190 ) , 0 ,
NULL , V_124 } } ,
{ & V_191 ,
{ L_136 , L_137 ,
V_140 , V_127 , NULL , 0 ,
L_144 , V_124 } } ,
{ & V_192 ,
{ L_138 , L_139 ,
V_148 , V_127 , NULL , 0 ,
L_145 , V_124 } } ,
{ & V_193 ,
{ L_146 , L_147 ,
V_135 , V_123 , F_103 ( V_194 ) , 0 ,
L_148 , V_124 } } ,
{ & V_195 ,
{ L_136 , L_149 ,
V_122 , V_123 , F_103 ( V_196 ) , 0 ,
L_150 , V_124 } } ,
{ & V_197 ,
{ L_151 , L_152 ,
V_140 , V_127 , NULL , 0 ,
NULL , V_124 } } ,
{ & V_198 ,
{ L_153 , L_154 ,
V_140 , V_127 , NULL , 0 ,
NULL , V_124 } } ,
#line 453 "./asn1/ansi_tcap/packet-ansi_tcap-template.c"
} ;
static T_17 * V_199 [] = {
& V_111 ,
& V_200 ,
& V_201 ,
& V_202 ,
& V_203 ,
& V_44 ,
#line 1 "./asn1/ansi_tcap/packet-ansi_tcap-ettarr.c"
& V_50 ,
& V_52 ,
& V_104 ,
& V_91 ,
& V_97 ,
& V_101 ,
& V_99 ,
& V_71 ,
& V_61 ,
& V_65 ,
& V_63 ,
& V_69 ,
& V_67 ,
& V_89 ,
& V_87 ,
& V_73 ,
& V_75 ,
& V_77 ,
& V_85 ,
& V_83 ,
& V_79 ,
& V_81 ,
#line 464 "./asn1/ansi_tcap/packet-ansi_tcap-template.c"
} ;
static T_18 V_204 [] = {
{ & V_38 , { L_155 , V_205 , V_206 , L_156 , V_207 } } ,
} ;
T_19 * V_208 ;
static const T_20 V_209 [] = {
{ L_157 , L_158 , V_19 } ,
{ L_159 , L_160 , V_20 } ,
{ L_161 , L_162 , V_21 } ,
{ NULL , NULL , - 1 }
} ;
V_109 = F_104 ( V_210 , V_211 , V_212 ) ;
F_105 ( L_163 , F_95 , V_109 ) ;
V_36 = F_106 ( L_164 , L_165 , V_109 , V_133 , V_123 ) ;
F_107 ( V_109 , V_120 , F_108 ( V_120 ) ) ;
F_109 ( V_199 , F_108 ( V_199 ) ) ;
V_208 = F_110 ( V_109 ) ;
F_111 ( V_208 , V_204 , F_108 ( V_204 ) ) ;
V_119 = F_112 ( V_109 , F_99 ) ;
F_113 ( V_119 , L_166 ,
L_167 ,
L_168 ,
& V_18 , V_209 , FALSE ) ;
V_22 = F_114 ( F_115 () , F_9 () , V_213 , V_214 ) ;
}
