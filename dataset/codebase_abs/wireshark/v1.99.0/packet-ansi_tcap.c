static void F_1 ( struct V_1 * V_2 ) {
memset ( V_2 , '\0' , sizeof( * V_2 ) ) ;
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = FALSE ;
V_2 -> V_6 = NULL ;
}
static void
F_2 ( void ) {
if ( V_7 ) {
F_3 ( V_7 ) ;
V_7 = NULL ;
}
V_7 = F_4 ( V_8 , V_9 ) ;
}
static void
F_5 ( void )
{
F_2 () ;
}
static void
F_6 ( T_1 * V_10 , T_2 * T_3 V_11 , T_4 * T_5 V_11 ) {
struct V_12 * V_13 ;
T_6 * V_14 , * V_15 ;
char * V_16 ;
V_14 = F_7 ( F_8 () , & ( V_10 -> V_14 ) ) ;
V_15 = F_7 ( F_8 () , & ( V_10 -> V_15 ) ) ;
if ( ( ! V_10 -> V_17 -> V_18 . V_19 ) && ( V_20 . V_6 ) ) {
switch( V_21 ) {
case 0 :
V_16 = F_9 ( F_8 () , V_20 . V_6 ) ;
break;
case 1 :
V_16 = F_10 ( F_8 () , L_1 , V_20 . V_6 , V_14 ) ;
break;
default:
V_16 = F_10 ( F_8 () , L_2 , V_20 . V_6 , V_14 , V_15 ) ;
break;
}
V_13 = (struct V_12 * ) F_11 ( V_7 , V_16 ) ;
if( V_13 )
return;
V_13 = F_12 ( F_13 () , struct V_12 ) ;
V_13 -> V_22 = V_20 . V_23 . V_22 ;
V_13 -> V_24 = V_20 . V_23 . V_24 ;
V_13 -> V_25 = V_20 . V_23 . V_25 ;
F_14 ( V_7 ,
F_9 ( F_13 () , V_16 ) ,
V_13 ) ;
}
}
static T_7
F_15 ( T_1 * V_10 , T_2 * T_3 V_11 , T_4 * T_5 V_11 ) {
struct V_12 * V_13 ;
T_6 * V_14 , * V_15 ;
char * V_16 ;
if ( ! V_20 . V_6 ) {
return FALSE ;
}
V_14 = F_7 ( F_8 () , & ( V_10 -> V_14 ) ) ;
V_15 = F_7 ( F_8 () , & ( V_10 -> V_15 ) ) ;
V_16 = ( char * ) F_16 ( F_8 () , V_26 ) ;
V_16 [ 0 ] = '\0' ;
switch( V_21 ) {
case 0 :
F_17 ( V_16 , V_26 , L_3 , V_20 . V_6 ) ;
break;
case 1 :
F_17 ( V_16 , V_26 , L_1 , V_20 . V_6 , V_15 ) ;
break;
default:
F_17 ( V_16 , V_26 , L_2 , V_20 . V_6 , V_15 , V_14 ) ;
break;
}
V_13 = (struct V_12 * ) F_11 ( V_7 , V_16 ) ;
if( V_13 ) {
V_20 . V_23 . V_22 = V_13 -> V_22 ;
V_20 . V_23 . V_24 = V_13 -> V_24 ;
V_20 . V_23 . V_25 = V_13 -> V_25 ;
return TRUE ;
}
return FALSE ;
}
static T_7
F_18 ( T_4 * T_5 , T_8 * V_27 , T_2 * T_3 ) {
T_9 * V_28 ;
if( V_20 . V_23 . V_29 == 1 ) {
F_6 ( V_27 -> V_10 , T_3 , T_5 ) ;
} else{
if( F_15 ( V_27 -> V_10 , T_3 , T_5 ) ) {
if( V_20 . V_23 . V_22 == 0 ) {
V_28 = F_19 ( T_3 , V_30 , T_5 , 0 , 0 , V_20 . V_23 . V_24 ) ;
} else{
V_28 = F_19 ( T_3 , V_31 , T_5 , 0 , 0 , V_20 . V_23 . V_25 ) ;
}
F_20 ( V_28 ) ;
V_20 . V_23 . V_32 = V_28 ;
}
}
if( V_20 . V_23 . V_22 == 0 ) {
T_10 V_33 = ( V_20 . V_23 . V_24 & 0x7f00 ) >> 8 ;
T_10 V_34 = ( T_10 ) ( V_20 . V_23 . V_24 & 0xff ) ;
if( ! F_21 ( V_35 , V_20 . V_23 . V_24 , T_5 , V_27 -> V_10 , V_36 ) ) {
F_22 ( T_3 , V_27 -> V_10 , & V_37 , T_5 , 0 , - 1 ,
L_4
L_5 ,
V_20 . V_23 . V_24 , V_33 , V_34 ) ;
return FALSE ;
}
return TRUE ;
} else if( V_20 . V_23 . V_22 == 1 ) {
if( ( V_20 . V_23 . V_25 & 0x0900 ) != 0x0900 ) {
F_22 ( T_3 , V_27 -> V_10 , & V_37 , T_5 , 0 , - 1 ,
L_6
L_7 ,
V_20 . V_23 . V_25 ) ;
return FALSE ;
}
}
F_23 ( V_38 , T_5 , V_27 -> V_10 , V_36 , & V_20 ) ;
return TRUE ;
}
static int
F_24 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 22 "../../asn1/ansi_tcap/ansi_tcap.cnf"
T_2 * V_39 ;
T_9 * V_40 ;
int V_41 = T_12 ;
T_10 V_33 ;
T_10 V_34 ;
T_12 = F_25 ( T_11 , V_27 , T_3 , T_5 , T_12 , T_13 ,
& V_20 . V_23 . V_24 ) ;
V_20 . V_23 . V_24 = ( V_20 . V_23 . V_24 & 0x7fff ) ;
V_39 = F_26 ( V_27 -> V_42 , V_43 ) ;
V_33 = ( V_20 . V_23 . V_24 & 0x7f00 ) >> 8 ;
V_34 = ( T_10 ) ( V_20 . V_23 . V_24 & 0xff ) ;
F_27 ( V_39 , V_44 , T_5 , V_41 , 2 , V_45 ) ;
F_27 ( V_39 , V_46 , T_5 , V_41 , 2 , V_45 ) ;
V_40 = F_27 ( V_39 , V_47 , T_5 , V_41 , 2 , V_45 ) ;
switch( V_33 ) {
case 0 :
break;
case 1 :
if( V_34 == 1 ) {
F_28 ( V_40 , L_8 ) ;
} else if ( V_34 == 2 ) {
F_28 ( V_40 , L_9 ) ;
}
break;
case 2 :
if ( V_34 == 1 ) {
F_28 ( V_40 , L_10 ) ;
}
break;
case 3 :
if ( V_34 == 1 ) {
F_28 ( V_40 , L_11 ) ;
} else if ( V_34 == 2 ) {
F_28 ( V_40 , L_12 ) ;
}
break;
case 4 :
if ( V_34 == 1 ) {
F_28 ( V_40 , L_13 ) ;
} else if ( V_34 == 2 ) {
F_28 ( V_40 , L_14 ) ;
} else if ( V_34 == 3 ) {
F_28 ( V_40 , L_15 ) ;
} else if ( V_34 == 4 ) {
F_28 ( V_40 , L_16 ) ;
}
break;
default:
break;
}
return T_12 ;
}
static int
F_29 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_25 ( T_11 , V_27 , T_3 , T_5 , T_12 , T_13 ,
& V_20 . V_23 . V_25 ) ;
return T_12 ;
}
static int
F_30 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_31 ( V_27 , T_3 , T_5 , T_12 ,
V_48 , T_13 , V_49 ,
& V_20 . V_23 . V_22 ) ;
#line 18 "../../asn1/ansi_tcap/ansi_tcap.cnf"
V_20 . V_23 . V_32 = V_27 -> V_42 ;
return T_12 ;
}
static int
F_32 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_25 ( T_11 , V_27 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_33 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_25 ( T_11 , V_27 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_34 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_31 ( V_27 , T_3 , T_5 , T_12 ,
V_50 , T_13 , V_51 ,
NULL ) ;
return T_12 ;
}
static int
F_35 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 154 "../../asn1/ansi_tcap/ansi_tcap.cnf"
T_4 * V_52 ;
T_10 V_53 ;
T_12 = F_36 ( T_11 , V_27 , T_3 , T_5 , T_12 , T_13 ,
& V_52 ) ;
if( V_52 ) {
V_53 = F_37 ( V_52 , 0 ) ;
if( V_53 != 0 ) {
if ( V_53 > 4 ) {
V_20 . V_6 = F_38 ( V_52 , 4 , V_53 - 4 ) ;
} else{
V_20 . V_6 = F_38 ( V_52 , 0 , V_53 ) ;
}
}
switch( V_53 ) {
case 1 :
V_54 -> V_55 = F_39 ( V_52 , 0 ) ;
break;
case 2 :
V_54 -> V_55 = F_40 ( V_52 , 0 ) ;
break;
case 4 :
V_54 -> V_55 = F_41 ( V_52 , 0 ) ;
break;
default:
V_54 -> V_55 = 0 ;
break;
}
}
return T_12 ;
}
static int
F_42 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_43 ( T_11 , V_27 , T_3 , T_5 , T_12 ,
T_13 , V_56 , 7 , TRUE , F_35 ) ;
return T_12 ;
}
static int
F_44 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_36 ( T_11 , V_27 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_45 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_43 ( T_11 , V_27 , T_3 , T_5 , T_12 ,
T_13 , V_56 , 26 , TRUE , F_44 ) ;
return T_12 ;
}
static int
F_46 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_43 ( T_11 , V_27 , T_3 , T_5 , T_12 ,
T_13 , V_56 , 27 , TRUE , F_33 ) ;
return T_12 ;
}
static int
F_47 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_48 ( T_11 , V_27 , T_3 , T_5 , T_12 , T_13 , NULL ) ;
return T_12 ;
}
static int
F_49 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 118 "../../asn1/ansi_tcap/ansi_tcap.cnf"
static const char * V_57 ;
T_12 = F_43 ( T_11 , V_27 , T_3 , T_5 , T_12 ,
T_13 , V_56 , 28 , TRUE , F_47 ) ;
V_20 . V_58 = ( const void * ) V_57 ;
V_20 . V_5 = TRUE ;
return T_12 ;
}
static int
F_50 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_31 ( V_27 , T_3 , T_5 , T_12 ,
V_59 , T_13 , V_60 ,
NULL ) ;
return T_12 ;
}
static int
F_51 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_52 ( T_11 , T_3 , T_5 , T_12 , V_27 , T_13 , NULL ) ;
return T_12 ;
}
static int
F_53 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_54 ( T_11 , V_27 , T_3 , T_5 , T_12 ,
V_61 , T_13 , V_62 ) ;
return T_12 ;
}
static int
F_55 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_43 ( T_11 , V_27 , T_3 , T_5 , T_12 ,
T_13 , V_56 , 29 , TRUE , F_53 ) ;
return T_12 ;
}
static int
F_56 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_31 ( V_27 , T_3 , T_5 , T_12 ,
V_63 , T_13 , V_64 ,
NULL ) ;
return T_12 ;
}
static int
F_57 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_31 ( V_27 , T_3 , T_5 , T_12 ,
V_65 , T_13 , V_66 ,
NULL ) ;
return T_12 ;
}
static int
F_58 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_59 ( T_11 , V_27 , T_3 , T_5 , T_12 ,
V_67 , T_13 , V_68 ) ;
return T_12 ;
}
static int
F_60 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_59 ( T_11 , V_27 , T_3 , T_5 , T_12 ,
V_69 , T_13 , V_70 ) ;
return T_12 ;
}
static int
F_61 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_43 ( T_11 , V_27 , T_3 , T_5 , T_12 ,
T_13 , V_56 , 25 , TRUE , F_60 ) ;
return T_12 ;
}
static int
F_62 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_36 ( T_11 , V_27 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_63 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 87 "../../asn1/ansi_tcap/ansi_tcap.cnf"
if( F_18 ( T_5 , V_27 , T_3 ) )
T_12 = F_64 ( T_5 ) ;
return T_12 ;
}
static int
F_65 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 93 "../../asn1/ansi_tcap/ansi_tcap.cnf"
V_20 . V_23 . V_29 = 1 ;
T_12 = F_59 ( T_11 , V_27 , T_3 , T_5 , T_12 ,
V_71 , T_13 , V_72 ) ;
return T_12 ;
}
static int
F_66 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_36 ( T_11 , V_27 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_67 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 100 "../../asn1/ansi_tcap/ansi_tcap.cnf"
if( F_18 ( T_5 , V_27 , T_3 ) )
T_12 = F_64 ( T_5 ) ;
return T_12 ;
}
static int
F_68 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 104 "../../asn1/ansi_tcap/ansi_tcap.cnf"
V_20 . V_23 . V_29 = 2 ;
T_12 = F_59 ( T_11 , V_27 , T_3 , T_5 , T_12 ,
V_73 , T_13 , V_74 ) ;
return T_12 ;
}
static int
F_69 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_36 ( T_11 , V_27 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_70 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 110 "../../asn1/ansi_tcap/ansi_tcap.cnf"
if( F_18 ( T_5 , V_27 , T_3 ) )
T_12 = F_64 ( T_5 ) ;
return T_12 ;
}
static int
F_71 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 114 "../../asn1/ansi_tcap/ansi_tcap.cnf"
V_20 . V_23 . V_29 = 3 ;
T_12 = F_59 ( T_11 , V_27 , T_3 , T_5 , T_12 ,
V_75 , T_13 , V_76 ) ;
return T_12 ;
}
static int
F_72 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_36 ( T_11 , V_27 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_73 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_25 ( T_11 , V_27 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_74 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_59 ( T_11 , V_27 , T_3 , T_5 , T_12 ,
V_77 , T_13 , V_78 ) ;
return T_12 ;
}
static int
F_75 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_76 ( T_11 , V_27 , T_3 , T_5 , T_12 ,
V_79 , T_13 , V_80 ) ;
return T_12 ;
}
static int
F_77 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_31 ( V_27 , T_3 , T_5 , T_12 ,
V_81 , T_13 , V_82 ,
NULL ) ;
return T_12 ;
}
static int
F_78 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_59 ( T_11 , V_27 , T_3 , T_5 , T_12 ,
V_83 , T_13 , V_84 ) ;
return T_12 ;
}
static int
F_79 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_31 ( V_27 , T_3 , T_5 , T_12 ,
V_85 , T_13 , V_86 ,
NULL ) ;
return T_12 ;
}
static int
F_80 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_54 ( T_11 , V_27 , T_3 , T_5 , T_12 ,
V_87 , T_13 , V_88 ) ;
return T_12 ;
}
static int
F_81 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_43 ( T_11 , V_27 , T_3 , T_5 , T_12 ,
T_13 , V_56 , 8 , TRUE , F_80 ) ;
return T_12 ;
}
static int
F_82 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_59 ( T_11 , V_27 , T_3 , T_5 , T_12 ,
V_89 , T_13 , V_90 ) ;
return T_12 ;
}
static int
F_83 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 126 "../../asn1/ansi_tcap/ansi_tcap.cnf"
V_54 -> V_91 = V_92 ;
F_84 ( V_27 -> V_10 -> V_93 , V_94 , L_17 ) ;
T_12 = F_82 ( T_11 , T_5 , T_12 , V_27 , T_3 , T_13 ) ;
return T_12 ;
}
static int
F_85 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_59 ( T_11 , V_27 , T_3 , T_5 , T_12 ,
V_95 , T_13 , V_96 ) ;
return T_12 ;
}
static int
F_86 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 130 "../../asn1/ansi_tcap/ansi_tcap.cnf"
V_54 -> V_91 = V_92 ;
F_84 ( V_27 -> V_10 -> V_93 , V_94 , L_18 ) ;
T_12 = F_85 ( T_11 , T_5 , T_12 , V_27 , T_3 , T_13 ) ;
return T_12 ;
}
static int
F_87 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 134 "../../asn1/ansi_tcap/ansi_tcap.cnf"
V_54 -> V_91 = V_92 ;
F_84 ( V_27 -> V_10 -> V_93 , V_94 , L_19 ) ;
T_12 = F_85 ( T_11 , T_5 , T_12 , V_27 , T_3 , T_13 ) ;
return T_12 ;
}
static int
F_88 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 138 "../../asn1/ansi_tcap/ansi_tcap.cnf"
V_54 -> V_91 = V_92 ;
F_84 ( V_27 -> V_10 -> V_93 , V_94 , L_20 ) ;
T_12 = F_85 ( T_11 , T_5 , T_12 , V_27 , T_3 , T_13 ) ;
return T_12 ;
}
static int
F_89 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 142 "../../asn1/ansi_tcap/ansi_tcap.cnf"
V_54 -> V_91 = V_92 ;
F_84 ( V_27 -> V_10 -> V_93 , V_94 , L_21 ) ;
T_12 = F_85 ( T_11 , T_5 , T_12 , V_27 , T_3 , T_13 ) ;
return T_12 ;
}
static int
F_90 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 146 "../../asn1/ansi_tcap/ansi_tcap.cnf"
V_54 -> V_91 = V_92 ;
F_84 ( V_27 -> V_10 -> V_93 , V_94 , L_22 ) ;
T_12 = F_85 ( T_11 , T_5 , T_12 , V_27 , T_3 , T_13 ) ;
return T_12 ;
}
static int
F_91 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_25 ( T_11 , V_27 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_92 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_43 ( T_11 , V_27 , T_3 , T_5 , T_12 ,
T_13 , V_56 , 23 , TRUE , F_91 ) ;
return T_12 ;
}
static int
F_93 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_43 ( T_11 , V_27 , T_3 , T_5 , T_12 ,
T_13 , V_56 , 24 , FALSE , F_51 ) ;
return T_12 ;
}
static int
F_94 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_31 ( V_27 , T_3 , T_5 , T_12 ,
V_97 , T_13 , V_98 ,
NULL ) ;
return T_12 ;
}
static int
F_95 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_59 ( T_11 , V_27 , T_3 , T_5 , T_12 ,
V_99 , T_13 , V_100 ) ;
return T_12 ;
}
static int
F_96 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 150 "../../asn1/ansi_tcap/ansi_tcap.cnf"
V_54 -> V_91 = V_101 ;
F_84 ( V_27 -> V_10 -> V_93 , V_94 , L_23 ) ;
T_12 = F_95 ( T_11 , T_5 , T_12 , V_27 , T_3 , T_13 ) ;
return T_12 ;
}
static int
F_97 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_27 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_31 ( V_27 , T_3 , T_5 , T_12 ,
V_102 , T_13 , V_103 ,
NULL ) ;
return T_12 ;
}
static void
F_98 ( T_4 * T_5 , T_1 * V_10 , T_2 * V_104 )
{
T_9 * V_28 = NULL ;
T_2 * T_3 = NULL ;
#if 0
proto_item *stat_item=NULL;
proto_tree *stat_tree=NULL;
gint offset = 0;
struct tcaphash_context_t * p_tcap_context;
dissector_handle_t subdissector_handle;
#endif
T_8 V_105 ;
F_99 ( & V_105 , V_106 , TRUE , V_10 ) ;
F_1 ( & V_20 ) ;
V_36 = V_104 ;
F_84 ( V_10 -> V_93 , V_107 , L_24 ) ;
if( V_104 ) {
V_28 = F_27 ( V_104 , V_108 , T_5 , 0 , - 1 , V_109 ) ;
T_3 = F_26 ( V_28 , V_110 ) ;
V_111 = V_28 ;
V_112 = T_3 ;
}
V_113 = NULL ;
V_114 = NULL ;
V_54 = F_100 () ;
V_115 = FALSE ;
V_116 = NULL ;
F_97 ( FALSE , T_5 , 0 , & V_105 , T_3 , - 1 ) ;
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
}
void
F_101 ( void )
{
V_38 = F_102 ( L_25 ) ;
V_117 = F_103 ( L_26 ) ;
}
void
F_104 ( void )
{
T_14 * V_118 ;
static T_15 V_119 [] = {
{ & V_120 ,
{ L_27 ,
L_28 ,
V_121 , V_122 , NULL , 0x0 ,
NULL , V_123 }
} ,
{ & V_124 ,
{ L_29 ,
L_30 ,
V_125 , V_126 , NULL , 0x0 ,
L_31 , V_123 }
} ,
{ & V_127 ,
{ L_32 ,
L_33 ,
V_125 , V_126 , NULL , 0x0 ,
L_34 , V_123 }
} ,
{ & V_128 ,
{ L_35 ,
L_36 ,
V_129 , V_126 , NULL , 0x0 ,
L_37 , V_123 }
} ,
{ & V_130 ,
{ L_38 ,
L_39 ,
V_121 , V_122 , NULL , 0x0 ,
NULL , V_123 }
} ,
{ & V_44 ,
{ L_40 , L_41 ,
V_131 , 16 , NULL , 0x8000 ,
NULL , V_123 }
} ,
{ & V_46 ,
{ L_42 ,
L_43 ,
V_132 , V_122 , F_105 ( V_133 ) , 0x7f00 ,
NULL , V_123 }
} ,
{ & V_47 ,
{ L_44 ,
L_45 ,
V_132 , V_122 , NULL , 0x00ff ,
NULL , V_123 }
} ,
#line 1 "../../asn1/ansi_tcap/packet-ansi_tcap-hfarr.c"
{ & V_30 ,
{ L_46 , L_47 ,
V_134 , V_122 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_31 ,
{ L_48 , L_49 ,
V_134 , V_122 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_135 ,
{ L_46 , L_47 ,
V_134 , V_122 , NULL , 0 ,
L_50 , V_123 } } ,
{ & V_136 ,
{ L_48 , L_49 ,
V_134 , V_122 , NULL , 0 ,
L_51 , V_123 } } ,
{ & V_137 ,
{ L_52 , L_53 ,
V_138 , V_126 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_139 ,
{ L_54 , L_55 ,
V_138 , V_126 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_140 ,
{ L_56 , L_57 ,
V_138 , V_126 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_141 ,
{ L_58 , L_59 ,
V_138 , V_126 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_142 ,
{ L_60 , L_61 ,
V_138 , V_126 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_143 ,
{ L_62 , L_63 ,
V_138 , V_126 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_144 ,
{ L_64 , L_65 ,
V_138 , V_126 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_145 ,
{ L_66 , L_67 ,
V_146 , V_126 , NULL , 0 ,
L_68 , V_123 } } ,
{ & V_147 ,
{ L_69 , L_70 ,
V_138 , V_126 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_148 ,
{ L_71 , L_72 ,
V_121 , V_122 , NULL , 0 ,
L_73 , V_123 } } ,
{ & V_149 ,
{ L_74 , L_75 ,
V_138 , V_126 , NULL , 0 ,
L_76 , V_123 } } ,
{ & V_150 ,
{ L_77 , L_78 ,
V_121 , V_122 , F_105 ( V_151 ) , 0 ,
NULL , V_123 } } ,
{ & V_152 ,
{ L_79 , L_80 ,
V_134 , V_122 , F_105 ( V_153 ) , 0 ,
L_81 , V_123 } } ,
{ & V_154 ,
{ L_82 , L_83 ,
V_138 , V_126 , NULL , 0 ,
L_84 , V_123 } } ,
{ & V_155 ,
{ L_85 , L_86 ,
V_146 , V_126 , NULL , 0 ,
L_87 , V_123 } } ,
{ & V_156 ,
{ L_88 , L_89 ,
V_121 , V_122 , F_105 ( V_157 ) , 0 ,
NULL , V_123 } } ,
{ & V_158 ,
{ L_90 , L_91 ,
V_134 , V_122 , NULL , 0 ,
L_92 , V_123 } } ,
{ & V_159 ,
{ L_93 , L_94 ,
V_160 , V_126 , NULL , 0 ,
L_95 , V_123 } } ,
{ & V_161 ,
{ L_82 , L_96 ,
V_121 , V_122 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_162 ,
{ L_97 , L_98 ,
V_121 , V_122 , F_105 ( V_163 ) , 0 ,
NULL , V_123 } } ,
{ & V_164 ,
{ L_99 , L_100 ,
V_134 , V_122 , NULL , 0 ,
L_51 , V_123 } } ,
{ & V_165 ,
{ L_101 , L_102 ,
V_160 , V_126 , NULL , 0 ,
L_103 , V_123 } } ,
{ & V_166 ,
{ L_104 , L_105 ,
V_138 , V_126 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_167 ,
{ L_106 , L_107 ,
V_138 , V_126 , NULL , 0 ,
L_108 , V_123 } } ,
{ & V_168 ,
{ L_109 , L_110 ,
V_121 , V_122 , F_105 ( V_169 ) , 0 ,
NULL , V_123 } } ,
{ & V_170 ,
{ L_111 , L_112 ,
V_134 , V_122 , NULL , 0 ,
L_51 , V_123 } } ,
{ & V_171 ,
{ L_113 , L_114 ,
V_160 , V_126 , NULL , 0 ,
L_103 , V_123 } } ,
{ & V_172 ,
{ L_115 , L_116 ,
V_121 , V_122 , F_105 ( V_173 ) , 0 ,
NULL , V_123 } } ,
{ & V_174 ,
{ L_117 , L_118 ,
V_138 , V_126 , NULL , 0 ,
L_119 , V_123 } } ,
{ & V_175 ,
{ L_120 , L_121 ,
V_138 , V_126 , NULL , 0 ,
L_122 , V_123 } } ,
{ & V_176 ,
{ L_123 , L_124 ,
V_138 , V_126 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_177 ,
{ L_125 , L_126 ,
V_138 , V_126 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_178 ,
{ L_127 , L_128 ,
V_138 , V_126 , NULL , 0 ,
L_119 , V_123 } } ,
{ & V_179 ,
{ L_129 , L_130 ,
V_138 , V_126 , NULL , 0 ,
L_122 , V_123 } } ,
{ & V_180 ,
{ L_131 , L_132 ,
V_146 , V_126 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_181 ,
{ L_133 , L_134 ,
V_121 , V_122 , F_105 ( V_182 ) , 0 ,
NULL , V_123 } } ,
{ & V_183 ,
{ L_135 , L_136 ,
V_138 , V_126 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_184 ,
{ L_137 , L_138 ,
V_146 , V_126 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_185 ,
{ L_135 , L_136 ,
V_138 , V_126 , NULL , 0 ,
L_139 , V_123 } } ,
{ & V_186 ,
{ L_137 , L_138 ,
V_146 , V_126 , NULL , 0 ,
L_140 , V_123 } } ,
{ & V_187 ,
{ L_141 , L_142 ,
V_121 , V_122 , F_105 ( V_188 ) , 0 ,
NULL , V_123 } } ,
{ & V_189 ,
{ L_135 , L_136 ,
V_138 , V_126 , NULL , 0 ,
L_143 , V_123 } } ,
{ & V_190 ,
{ L_137 , L_138 ,
V_146 , V_126 , NULL , 0 ,
L_144 , V_123 } } ,
{ & V_191 ,
{ L_145 , L_146 ,
V_134 , V_122 , F_105 ( V_192 ) , 0 ,
L_147 , V_123 } } ,
{ & V_193 ,
{ L_135 , L_148 ,
V_121 , V_122 , F_105 ( V_194 ) , 0 ,
L_149 , V_123 } } ,
{ & V_195 ,
{ L_150 , L_151 ,
V_138 , V_126 , NULL , 0 ,
NULL , V_123 } } ,
{ & V_196 ,
{ L_152 , L_153 ,
V_138 , V_126 , NULL , 0 ,
NULL , V_123 } } ,
#line 494 "../../asn1/ansi_tcap/packet-ansi_tcap-template.c"
} ;
static T_16 * V_197 [] = {
& V_110 ,
& V_198 ,
& V_199 ,
& V_200 ,
& V_201 ,
& V_43 ,
#line 1 "../../asn1/ansi_tcap/packet-ansi_tcap-ettarr.c"
& V_49 ,
& V_51 ,
& V_103 ,
& V_90 ,
& V_96 ,
& V_100 ,
& V_98 ,
& V_70 ,
& V_60 ,
& V_64 ,
& V_62 ,
& V_68 ,
& V_66 ,
& V_88 ,
& V_86 ,
& V_72 ,
& V_74 ,
& V_76 ,
& V_84 ,
& V_82 ,
& V_78 ,
& V_80 ,
#line 505 "../../asn1/ansi_tcap/packet-ansi_tcap-template.c"
} ;
static T_17 V_202 [] = {
{ & V_37 , { L_154 , V_203 , V_204 , L_155 , V_205 } } ,
} ;
T_18 * V_206 ;
static const T_19 V_207 [] = {
{ L_156 , L_157 , 0 } ,
{ L_158 , L_159 , 1 } ,
{ L_160 , L_161 , 2 } ,
{ NULL , NULL , - 1 }
} ;
V_108 = F_106 ( V_208 , V_209 , V_210 ) ;
F_107 ( L_162 , F_98 , V_108 ) ;
V_35 = F_108 ( L_163 , L_164 , V_132 , V_122 ) ;
F_109 ( V_108 , V_119 , F_110 ( V_119 ) ) ;
F_111 ( V_197 , F_110 ( V_197 ) ) ;
V_206 = F_112 ( V_108 ) ;
F_113 ( V_206 , V_202 , F_110 ( V_202 ) ) ;
V_118 = F_114 ( V_108 , F_101 ) ;
F_115 ( V_118 , L_165 ,
L_166 ,
L_167 ,
& V_21 , V_207 , FALSE ) ;
F_116 ( & F_5 ) ;
}
