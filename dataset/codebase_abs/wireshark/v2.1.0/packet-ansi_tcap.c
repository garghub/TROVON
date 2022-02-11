static void F_1 ( struct V_1 * V_2 ) {
memset ( V_2 , '\0' , sizeof( * V_2 ) ) ;
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = FALSE ;
V_2 -> V_6 = NULL ;
}
static void
F_2 ( void )
{
V_7 = F_3 ( V_8 , V_9 ) ;
}
static void
F_4 ( void )
{
F_5 ( V_7 ) ;
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
case V_22 :
V_16 = F_9 ( F_8 () , V_20 . V_6 ) ;
break;
case V_23 :
V_16 = F_10 ( F_8 () , L_1 , V_20 . V_6 , V_14 ) ;
break;
case V_24 :
default:
V_16 = F_10 ( F_8 () , L_2 , V_20 . V_6 , V_14 , V_15 ) ;
break;
}
V_13 = (struct V_12 * ) F_11 ( V_7 , V_16 ) ;
if( V_13 )
return;
V_13 = F_12 ( F_13 () , struct V_12 ) ;
V_13 -> V_25 = V_20 . V_26 . V_25 ;
V_13 -> V_27 = V_20 . V_26 . V_27 ;
V_13 -> V_28 = V_20 . V_26 . V_28 ;
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
V_16 = ( char * ) F_16 ( F_8 () , V_29 ) ;
V_16 [ 0 ] = '\0' ;
switch( V_21 ) {
case V_22 :
F_17 ( V_16 , V_29 , L_3 , V_20 . V_6 ) ;
break;
case V_23 :
F_17 ( V_16 , V_29 , L_1 , V_20 . V_6 , V_15 ) ;
break;
case V_24 :
default:
F_17 ( V_16 , V_29 , L_2 , V_20 . V_6 , V_15 , V_14 ) ;
break;
}
V_13 = (struct V_12 * ) F_11 ( V_7 , V_16 ) ;
if( V_13 ) {
V_20 . V_26 . V_25 = V_13 -> V_25 ;
V_20 . V_26 . V_27 = V_13 -> V_27 ;
V_20 . V_26 . V_28 = V_13 -> V_28 ;
return TRUE ;
}
return FALSE ;
}
static T_7
F_18 ( T_4 * T_5 , T_8 * V_30 , T_2 * T_3 ) {
T_9 * V_31 ;
if( V_20 . V_26 . V_32 == 1 ) {
F_6 ( V_30 -> V_10 , T_3 , T_5 ) ;
} else{
if( F_15 ( V_30 -> V_10 , T_3 , T_5 ) ) {
if( V_20 . V_26 . V_25 == 0 ) {
V_31 = F_19 ( T_3 , V_33 , T_5 , 0 , 0 , V_20 . V_26 . V_27 ) ;
} else{
V_31 = F_19 ( T_3 , V_34 , T_5 , 0 , 0 , V_20 . V_26 . V_28 ) ;
}
F_20 ( V_31 ) ;
V_20 . V_26 . V_35 = V_31 ;
}
}
if( V_20 . V_26 . V_25 == 0 ) {
T_10 V_36 = ( V_20 . V_26 . V_27 & 0x7f00 ) >> 8 ;
T_10 V_37 = ( T_10 ) ( V_20 . V_26 . V_27 & 0xff ) ;
if( ! F_21 ( V_38 , V_20 . V_26 . V_27 , T_5 , V_30 -> V_10 , V_39 ) ) {
F_22 ( T_3 , V_30 -> V_10 , & V_40 , T_5 , 0 , - 1 ,
L_4
L_5 ,
V_20 . V_26 . V_27 , V_36 , V_37 ) ;
return FALSE ;
}
return TRUE ;
} else if( V_20 . V_26 . V_25 == 1 ) {
if( ( V_20 . V_26 . V_28 & 0x0900 ) != 0x0900 ) {
F_22 ( T_3 , V_30 -> V_10 , & V_40 , T_5 , 0 , - 1 ,
L_6
L_7 ,
V_20 . V_26 . V_28 ) ;
return FALSE ;
}
}
F_23 ( V_41 , T_5 , V_30 -> V_10 , V_39 , & V_20 ) ;
return TRUE ;
}
static int
F_24 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 22 "./asn1/ansi_tcap/ansi_tcap.cnf"
T_2 * V_42 ;
T_9 * V_43 ;
int V_44 = T_12 ;
T_10 V_36 ;
T_10 V_37 ;
T_12 = F_25 ( T_11 , V_30 , T_3 , T_5 , T_12 , T_13 ,
& V_20 . V_26 . V_27 ) ;
V_20 . V_26 . V_27 = ( V_20 . V_26 . V_27 & 0x7fff ) ;
V_42 = F_26 ( V_30 -> V_45 , V_46 ) ;
V_36 = ( V_20 . V_26 . V_27 & 0x7f00 ) >> 8 ;
V_37 = ( T_10 ) ( V_20 . V_26 . V_27 & 0xff ) ;
F_27 ( V_42 , V_47 , T_5 , V_44 , 2 , V_48 ) ;
F_27 ( V_42 , V_49 , T_5 , V_44 , 2 , V_48 ) ;
V_43 = F_27 ( V_42 , V_50 , T_5 , V_44 , 2 , V_48 ) ;
switch( V_36 ) {
case 0 :
break;
case 1 :
if( V_37 == 1 ) {
F_28 ( V_43 , L_8 ) ;
} else if ( V_37 == 2 ) {
F_28 ( V_43 , L_9 ) ;
}
break;
case 2 :
if ( V_37 == 1 ) {
F_28 ( V_43 , L_10 ) ;
}
break;
case 3 :
if ( V_37 == 1 ) {
F_28 ( V_43 , L_11 ) ;
} else if ( V_37 == 2 ) {
F_28 ( V_43 , L_12 ) ;
}
break;
case 4 :
if ( V_37 == 1 ) {
F_28 ( V_43 , L_13 ) ;
} else if ( V_37 == 2 ) {
F_28 ( V_43 , L_14 ) ;
} else if ( V_37 == 3 ) {
F_28 ( V_43 , L_15 ) ;
} else if ( V_37 == 4 ) {
F_28 ( V_43 , L_16 ) ;
}
break;
default:
break;
}
return T_12 ;
}
static int
F_29 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_25 ( T_11 , V_30 , T_3 , T_5 , T_12 , T_13 ,
& V_20 . V_26 . V_28 ) ;
return T_12 ;
}
static int
F_30 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_31 ( V_30 , T_3 , T_5 , T_12 ,
V_51 , T_13 , V_52 ,
& V_20 . V_26 . V_25 ) ;
#line 18 "./asn1/ansi_tcap/ansi_tcap.cnf"
V_20 . V_26 . V_35 = V_30 -> V_45 ;
return T_12 ;
}
static int
F_32 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_25 ( T_11 , V_30 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_33 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_25 ( T_11 , V_30 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_34 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_31 ( V_30 , T_3 , T_5 , T_12 ,
V_53 , T_13 , V_54 ,
NULL ) ;
return T_12 ;
}
static int
F_35 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 154 "./asn1/ansi_tcap/ansi_tcap.cnf"
T_4 * V_55 ;
T_10 V_56 ;
T_12 = F_36 ( T_11 , V_30 , T_3 , T_5 , T_12 , T_13 ,
& V_55 ) ;
if( V_55 ) {
V_56 = F_37 ( V_55 , 0 ) ;
if( V_56 != 0 ) {
if ( V_56 > 4 ) {
V_20 . V_6 = F_38 ( F_8 () , V_55 , 4 , V_56 - 4 ) ;
} else{
V_20 . V_6 = F_38 ( F_8 () , V_55 , 0 , V_56 ) ;
}
}
switch( V_56 ) {
case 1 :
V_57 -> V_58 = F_39 ( V_55 , 0 ) ;
break;
case 2 :
V_57 -> V_58 = F_40 ( V_55 , 0 ) ;
break;
case 4 :
V_57 -> V_58 = F_41 ( V_55 , 0 ) ;
break;
default:
V_57 -> V_58 = 0 ;
break;
}
}
return T_12 ;
}
static int
F_42 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_43 ( T_11 , V_30 , T_3 , T_5 , T_12 ,
T_13 , V_59 , 7 , TRUE , F_35 ) ;
return T_12 ;
}
static int
F_44 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_36 ( T_11 , V_30 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_45 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_43 ( T_11 , V_30 , T_3 , T_5 , T_12 ,
T_13 , V_59 , 26 , TRUE , F_44 ) ;
return T_12 ;
}
static int
F_46 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_25 ( T_11 , V_30 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_47 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_43 ( T_11 , V_30 , T_3 , T_5 , T_12 ,
T_13 , V_59 , 27 , TRUE , F_46 ) ;
return T_12 ;
}
static int
F_48 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_49 ( T_11 , V_30 , T_3 , T_5 , T_12 , T_13 , NULL ) ;
return T_12 ;
}
static int
F_50 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 118 "./asn1/ansi_tcap/ansi_tcap.cnf"
static const char * V_60 ;
T_12 = F_43 ( T_11 , V_30 , T_3 , T_5 , T_12 ,
T_13 , V_59 , 28 , TRUE , F_48 ) ;
V_20 . V_61 = ( const void * ) V_60 ;
V_20 . V_5 = TRUE ;
return T_12 ;
}
static int
F_51 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_31 ( V_30 , T_3 , T_5 , T_12 ,
V_62 , T_13 , V_63 ,
NULL ) ;
return T_12 ;
}
static int
F_52 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_53 ( T_11 , T_3 , T_5 , T_12 , V_30 , T_13 , NULL ) ;
return T_12 ;
}
static int
F_54 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_55 ( T_11 , V_30 , T_3 , T_5 , T_12 ,
V_64 , T_13 , V_65 ) ;
return T_12 ;
}
static int
F_56 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_43 ( T_11 , V_30 , T_3 , T_5 , T_12 ,
T_13 , V_59 , 29 , TRUE , F_54 ) ;
return T_12 ;
}
static int
F_57 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_31 ( V_30 , T_3 , T_5 , T_12 ,
V_66 , T_13 , V_67 ,
NULL ) ;
return T_12 ;
}
static int
F_58 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_31 ( V_30 , T_3 , T_5 , T_12 ,
V_68 , T_13 , V_69 ,
NULL ) ;
return T_12 ;
}
static int
F_59 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_60 ( T_11 , V_30 , T_3 , T_5 , T_12 ,
V_70 , T_13 , V_71 ) ;
return T_12 ;
}
static int
F_61 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_60 ( T_11 , V_30 , T_3 , T_5 , T_12 ,
V_72 , T_13 , V_73 ) ;
return T_12 ;
}
static int
F_62 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_43 ( T_11 , V_30 , T_3 , T_5 , T_12 ,
T_13 , V_59 , 25 , TRUE , F_61 ) ;
return T_12 ;
}
static int
F_63 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_36 ( T_11 , V_30 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_64 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 87 "./asn1/ansi_tcap/ansi_tcap.cnf"
if( F_18 ( T_5 , V_30 , T_3 ) )
T_12 = F_65 ( T_5 ) ;
return T_12 ;
}
static int
F_66 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 93 "./asn1/ansi_tcap/ansi_tcap.cnf"
V_20 . V_26 . V_32 = 1 ;
T_12 = F_60 ( T_11 , V_30 , T_3 , T_5 , T_12 ,
V_74 , T_13 , V_75 ) ;
return T_12 ;
}
static int
F_67 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_36 ( T_11 , V_30 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_68 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 100 "./asn1/ansi_tcap/ansi_tcap.cnf"
if( F_18 ( T_5 , V_30 , T_3 ) )
T_12 = F_65 ( T_5 ) ;
return T_12 ;
}
static int
F_69 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 104 "./asn1/ansi_tcap/ansi_tcap.cnf"
V_20 . V_26 . V_32 = 2 ;
T_12 = F_60 ( T_11 , V_30 , T_3 , T_5 , T_12 ,
V_76 , T_13 , V_77 ) ;
return T_12 ;
}
static int
F_70 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_36 ( T_11 , V_30 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_71 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 110 "./asn1/ansi_tcap/ansi_tcap.cnf"
if( F_18 ( T_5 , V_30 , T_3 ) )
T_12 = F_65 ( T_5 ) ;
return T_12 ;
}
static int
F_72 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 114 "./asn1/ansi_tcap/ansi_tcap.cnf"
V_20 . V_26 . V_32 = 3 ;
T_12 = F_60 ( T_11 , V_30 , T_3 , T_5 , T_12 ,
V_78 , T_13 , V_79 ) ;
return T_12 ;
}
static int
F_73 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_36 ( T_11 , V_30 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_74 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_25 ( T_11 , V_30 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_75 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_60 ( T_11 , V_30 , T_3 , T_5 , T_12 ,
V_80 , T_13 , V_81 ) ;
return T_12 ;
}
static int
F_76 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_77 ( T_11 , V_30 , T_3 , T_5 , T_12 ,
V_82 , T_13 , V_83 ) ;
return T_12 ;
}
static int
F_78 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_31 ( V_30 , T_3 , T_5 , T_12 ,
V_84 , T_13 , V_85 ,
NULL ) ;
return T_12 ;
}
static int
F_79 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_60 ( T_11 , V_30 , T_3 , T_5 , T_12 ,
V_86 , T_13 , V_87 ) ;
return T_12 ;
}
static int
F_80 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_31 ( V_30 , T_3 , T_5 , T_12 ,
V_88 , T_13 , V_89 ,
NULL ) ;
return T_12 ;
}
static int
F_81 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_55 ( T_11 , V_30 , T_3 , T_5 , T_12 ,
V_90 , T_13 , V_91 ) ;
return T_12 ;
}
static int
F_82 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_43 ( T_11 , V_30 , T_3 , T_5 , T_12 ,
T_13 , V_59 , 8 , TRUE , F_81 ) ;
return T_12 ;
}
static int
F_83 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_60 ( T_11 , V_30 , T_3 , T_5 , T_12 ,
V_92 , T_13 , V_93 ) ;
return T_12 ;
}
static int
F_84 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 126 "./asn1/ansi_tcap/ansi_tcap.cnf"
V_57 -> V_94 = V_95 ;
F_85 ( V_30 -> V_10 -> V_96 , V_97 , L_17 ) ;
T_12 = F_83 ( T_11 , T_5 , T_12 , V_30 , T_3 , T_13 ) ;
return T_12 ;
}
static int
F_86 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_60 ( T_11 , V_30 , T_3 , T_5 , T_12 ,
V_98 , T_13 , V_99 ) ;
return T_12 ;
}
static int
F_87 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 130 "./asn1/ansi_tcap/ansi_tcap.cnf"
V_57 -> V_94 = V_95 ;
F_85 ( V_30 -> V_10 -> V_96 , V_97 , L_18 ) ;
T_12 = F_86 ( T_11 , T_5 , T_12 , V_30 , T_3 , T_13 ) ;
return T_12 ;
}
static int
F_88 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 134 "./asn1/ansi_tcap/ansi_tcap.cnf"
V_57 -> V_94 = V_95 ;
F_85 ( V_30 -> V_10 -> V_96 , V_97 , L_19 ) ;
T_12 = F_86 ( T_11 , T_5 , T_12 , V_30 , T_3 , T_13 ) ;
return T_12 ;
}
static int
F_89 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 138 "./asn1/ansi_tcap/ansi_tcap.cnf"
V_57 -> V_94 = V_95 ;
F_85 ( V_30 -> V_10 -> V_96 , V_97 , L_20 ) ;
T_12 = F_86 ( T_11 , T_5 , T_12 , V_30 , T_3 , T_13 ) ;
return T_12 ;
}
static int
F_90 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 142 "./asn1/ansi_tcap/ansi_tcap.cnf"
V_57 -> V_94 = V_95 ;
F_85 ( V_30 -> V_10 -> V_96 , V_97 , L_21 ) ;
T_12 = F_86 ( T_11 , T_5 , T_12 , V_30 , T_3 , T_13 ) ;
return T_12 ;
}
static int
F_91 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 146 "./asn1/ansi_tcap/ansi_tcap.cnf"
V_57 -> V_94 = V_95 ;
F_85 ( V_30 -> V_10 -> V_96 , V_97 , L_22 ) ;
T_12 = F_86 ( T_11 , T_5 , T_12 , V_30 , T_3 , T_13 ) ;
return T_12 ;
}
static int
F_92 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_25 ( T_11 , V_30 , T_3 , T_5 , T_12 , T_13 ,
NULL ) ;
return T_12 ;
}
static int
F_93 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_43 ( T_11 , V_30 , T_3 , T_5 , T_12 ,
T_13 , V_59 , 23 , TRUE , F_92 ) ;
return T_12 ;
}
static int
F_94 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_43 ( T_11 , V_30 , T_3 , T_5 , T_12 ,
T_13 , V_59 , 24 , FALSE , F_52 ) ;
return T_12 ;
}
static int
F_95 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_31 ( V_30 , T_3 , T_5 , T_12 ,
V_100 , T_13 , V_101 ,
NULL ) ;
return T_12 ;
}
static int
F_96 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_60 ( T_11 , V_30 , T_3 , T_5 , T_12 ,
V_102 , T_13 , V_103 ) ;
return T_12 ;
}
static int
F_97 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
#line 150 "./asn1/ansi_tcap/ansi_tcap.cnf"
V_57 -> V_94 = V_104 ;
F_85 ( V_30 -> V_10 -> V_96 , V_97 , L_23 ) ;
T_12 = F_96 ( T_11 , T_5 , T_12 , V_30 , T_3 , T_13 ) ;
return T_12 ;
}
static int
F_98 ( T_7 T_11 V_11 , T_4 * T_5 V_11 , int T_12 V_11 , T_8 * V_30 V_11 , T_2 * T_3 V_11 , int T_13 V_11 ) {
T_12 = F_31 ( V_30 , T_3 , T_5 , T_12 ,
V_105 , T_13 , V_106 ,
NULL ) ;
return T_12 ;
}
static int
F_99 ( T_4 * T_5 , T_1 * V_10 , T_2 * V_107 , void * T_14 V_11 )
{
T_9 * V_31 = NULL ;
T_2 * T_3 = NULL ;
#if 0
proto_item *stat_item=NULL;
proto_tree *stat_tree=NULL;
gint offset = 0;
struct tcaphash_context_t * p_tcap_context;
dissector_handle_t subdissector_handle;
#endif
T_8 V_108 ;
F_100 ( & V_108 , V_109 , TRUE , V_10 ) ;
F_1 ( & V_20 ) ;
V_39 = V_107 ;
F_85 ( V_10 -> V_96 , V_110 , L_24 ) ;
if( V_107 ) {
V_31 = F_27 ( V_107 , V_111 , T_5 , 0 , - 1 , V_112 ) ;
T_3 = F_26 ( V_31 , V_113 ) ;
V_114 = V_31 ;
V_115 = T_3 ;
}
V_116 = NULL ;
V_117 = NULL ;
V_57 = F_101 () ;
V_118 = FALSE ;
V_119 = NULL ;
F_98 ( FALSE , T_5 , 0 , & V_108 , T_3 , - 1 ) ;
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
return F_102 ( T_5 ) ;
}
void
F_103 ( void )
{
V_41 = F_104 ( L_25 , V_111 ) ;
V_120 = F_105 ( L_26 ) ;
}
void
F_106 ( void )
{
T_15 * V_121 ;
static T_16 V_122 [] = {
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
{ & V_47 ,
{ L_40 , L_41 ,
V_134 , 16 , NULL , 0x8000 ,
NULL , V_126 }
} ,
{ & V_49 ,
{ L_42 ,
L_43 ,
V_135 , V_125 , F_107 ( V_136 ) , 0x7f00 ,
NULL , V_126 }
} ,
{ & V_50 ,
{ L_44 ,
L_45 ,
V_135 , V_125 , NULL , 0x00ff ,
NULL , V_126 }
} ,
#line 1 "./asn1/ansi_tcap/packet-ansi_tcap-hfarr.c"
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
V_124 , V_125 , F_107 ( V_140 ) , 0 ,
L_51 , V_126 } } ,
{ & V_141 ,
{ L_52 , L_53 ,
V_142 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_143 ,
{ L_54 , L_55 ,
V_142 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_144 ,
{ L_56 , L_57 ,
V_142 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_145 ,
{ L_58 , L_59 ,
V_142 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_146 ,
{ L_60 , L_61 ,
V_142 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_147 ,
{ L_62 , L_63 ,
V_142 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_148 ,
{ L_64 , L_65 ,
V_142 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_149 ,
{ L_66 , L_67 ,
V_150 , V_129 , NULL , 0 ,
L_68 , V_126 } } ,
{ & V_151 ,
{ L_69 , L_70 ,
V_142 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_152 ,
{ L_71 , L_72 ,
V_124 , V_125 , NULL , 0 ,
L_73 , V_126 } } ,
{ & V_153 ,
{ L_74 , L_75 ,
V_142 , V_129 , NULL , 0 ,
L_76 , V_126 } } ,
{ & V_154 ,
{ L_77 , L_78 ,
V_124 , V_125 , F_107 ( V_155 ) , 0 ,
NULL , V_126 } } ,
{ & V_156 ,
{ L_79 , L_80 ,
V_137 , V_125 , F_107 ( V_157 ) , 0 ,
L_81 , V_126 } } ,
{ & V_158 ,
{ L_82 , L_83 ,
V_142 , V_129 , NULL , 0 ,
L_84 , V_126 } } ,
{ & V_159 ,
{ L_85 , L_86 ,
V_150 , V_129 , NULL , 0 ,
L_87 , V_126 } } ,
{ & V_160 ,
{ L_88 , L_89 ,
V_124 , V_125 , F_107 ( V_161 ) , 0 ,
NULL , V_126 } } ,
{ & V_162 ,
{ L_90 , L_91 ,
V_137 , V_125 , NULL , 0 ,
L_92 , V_126 } } ,
{ & V_163 ,
{ L_93 , L_94 ,
V_164 , V_129 , NULL , 0 ,
L_95 , V_126 } } ,
{ & V_165 ,
{ L_82 , L_96 ,
V_124 , V_125 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_166 ,
{ L_97 , L_98 ,
V_124 , V_125 , F_107 ( V_167 ) , 0 ,
NULL , V_126 } } ,
{ & V_168 ,
{ L_99 , L_100 ,
V_137 , V_125 , NULL , 0 ,
L_101 , V_126 } } ,
{ & V_169 ,
{ L_102 , L_103 ,
V_164 , V_129 , NULL , 0 ,
L_104 , V_126 } } ,
{ & V_170 ,
{ L_105 , L_106 ,
V_142 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_171 ,
{ L_107 , L_108 ,
V_142 , V_129 , NULL , 0 ,
L_109 , V_126 } } ,
{ & V_172 ,
{ L_110 , L_111 ,
V_124 , V_125 , F_107 ( V_173 ) , 0 ,
NULL , V_126 } } ,
{ & V_174 ,
{ L_112 , L_113 ,
V_137 , V_125 , NULL , 0 ,
L_101 , V_126 } } ,
{ & V_175 ,
{ L_114 , L_115 ,
V_164 , V_129 , NULL , 0 ,
L_104 , V_126 } } ,
{ & V_176 ,
{ L_116 , L_117 ,
V_124 , V_125 , F_107 ( V_177 ) , 0 ,
NULL , V_126 } } ,
{ & V_178 ,
{ L_118 , L_119 ,
V_142 , V_129 , NULL , 0 ,
L_120 , V_126 } } ,
{ & V_179 ,
{ L_121 , L_122 ,
V_142 , V_129 , NULL , 0 ,
L_123 , V_126 } } ,
{ & V_180 ,
{ L_124 , L_125 ,
V_142 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_181 ,
{ L_126 , L_127 ,
V_142 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_182 ,
{ L_128 , L_129 ,
V_142 , V_129 , NULL , 0 ,
L_120 , V_126 } } ,
{ & V_183 ,
{ L_130 , L_131 ,
V_142 , V_129 , NULL , 0 ,
L_123 , V_126 } } ,
{ & V_184 ,
{ L_132 , L_133 ,
V_150 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_185 ,
{ L_134 , L_135 ,
V_124 , V_125 , F_107 ( V_186 ) , 0 ,
NULL , V_126 } } ,
{ & V_187 ,
{ L_136 , L_137 ,
V_142 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_188 ,
{ L_138 , L_139 ,
V_150 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_189 ,
{ L_136 , L_137 ,
V_142 , V_129 , NULL , 0 ,
L_140 , V_126 } } ,
{ & V_190 ,
{ L_138 , L_139 ,
V_150 , V_129 , NULL , 0 ,
L_141 , V_126 } } ,
{ & V_191 ,
{ L_142 , L_143 ,
V_124 , V_125 , F_107 ( V_192 ) , 0 ,
NULL , V_126 } } ,
{ & V_193 ,
{ L_136 , L_137 ,
V_142 , V_129 , NULL , 0 ,
L_144 , V_126 } } ,
{ & V_194 ,
{ L_138 , L_139 ,
V_150 , V_129 , NULL , 0 ,
L_145 , V_126 } } ,
{ & V_195 ,
{ L_146 , L_147 ,
V_137 , V_125 , F_107 ( V_196 ) , 0 ,
L_148 , V_126 } } ,
{ & V_197 ,
{ L_136 , L_149 ,
V_124 , V_125 , F_107 ( V_198 ) , 0 ,
L_150 , V_126 } } ,
{ & V_199 ,
{ L_151 , L_152 ,
V_142 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
{ & V_200 ,
{ L_153 , L_154 ,
V_142 , V_129 , NULL , 0 ,
NULL , V_126 } } ,
#line 488 "./asn1/ansi_tcap/packet-ansi_tcap-template.c"
} ;
static T_17 * V_201 [] = {
& V_113 ,
& V_202 ,
& V_203 ,
& V_204 ,
& V_205 ,
& V_46 ,
#line 1 "./asn1/ansi_tcap/packet-ansi_tcap-ettarr.c"
& V_52 ,
& V_54 ,
& V_106 ,
& V_93 ,
& V_99 ,
& V_103 ,
& V_101 ,
& V_73 ,
& V_63 ,
& V_67 ,
& V_65 ,
& V_71 ,
& V_69 ,
& V_91 ,
& V_89 ,
& V_75 ,
& V_77 ,
& V_79 ,
& V_87 ,
& V_85 ,
& V_81 ,
& V_83 ,
#line 499 "./asn1/ansi_tcap/packet-ansi_tcap-template.c"
} ;
static T_18 V_206 [] = {
{ & V_40 , { L_155 , V_207 , V_208 , L_156 , V_209 } } ,
} ;
T_19 * V_210 ;
static const T_20 V_211 [] = {
{ L_157 , L_158 , V_22 } ,
{ L_159 , L_160 , V_23 } ,
{ L_161 , L_162 , V_24 } ,
{ NULL , NULL , - 1 }
} ;
V_111 = F_108 ( V_212 , V_213 , V_214 ) ;
F_109 ( L_163 , F_99 , V_111 ) ;
V_38 = F_110 ( L_164 , L_165 , V_111 , V_135 , V_125 , V_215 ) ;
F_111 ( V_111 , V_122 , F_112 ( V_122 ) ) ;
F_113 ( V_201 , F_112 ( V_201 ) ) ;
V_210 = F_114 ( V_111 ) ;
F_115 ( V_210 , V_206 , F_112 ( V_206 ) ) ;
V_121 = F_116 ( V_111 , F_103 ) ;
F_117 ( V_121 , L_166 ,
L_167 ,
L_168 ,
& V_21 , V_211 , FALSE ) ;
F_118 ( & F_2 ) ;
F_119 ( & F_4 ) ;
}
