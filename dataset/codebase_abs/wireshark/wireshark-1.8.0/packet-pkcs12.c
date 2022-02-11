static void F_1 ( T_1 * V_1 , const char * V_2 )
{
const char * V_3 = NULL ;
V_3 = F_2 ( V_2 ) ;
F_3 ( V_1 , L_1 , V_3 ? V_3 : V_2 ) ;
}
static int
F_4 ( unsigned int V_4 , T_2 * V_5 , unsigned int V_6 ,
const char * V_7 , unsigned int V_8 , char * V_9 )
{
int V_10 ;
unsigned int V_11 , V_12 ;
T_3 V_13 ;
T_4 V_14 = NULL ;
T_5 V_15 ;
char V_16 [ 20 ] , V_17 [ 64 ] , V_18 [ 128 ] , * V_19 ;
char * V_20 ;
int V_21 ;
T_5 V_22 ;
T_5 V_23 ;
T_6 V_24 ;
V_22 = 0 ;
V_21 = F_5 ( V_5 ) ;
V_20 = F_6 ( V_5 , 0 , V_21 ) ;
if ( V_7 == NULL )
V_15 = 0 ;
else
V_15 = strlen ( V_7 ) ;
if ( V_15 > 63 / 2 )
{
return FALSE ;
}
V_19 = V_18 ;
for ( V_11 = 0 ; V_11 < 64 ; V_11 ++ )
* V_19 ++ = V_20 [ V_11 % V_21 ] ;
if ( V_7 )
{
for ( V_11 = V_12 = 0 ; V_11 < 64 ; V_11 += 2 )
{
* V_19 ++ = 0 ;
* V_19 ++ = V_7 [ V_12 ] ;
if ( ++ V_12 > V_15 )
V_12 = 0 ;
}
}
else
memset ( V_19 , 0 , 64 ) ;
for (; ; ) {
V_24 = F_7 ( & V_13 , V_25 , 0 ) ;
if ( F_8 ( V_24 ) ) {
return FALSE ;
}
for ( V_11 = 0 ; V_11 < 64 ; V_11 ++ ) {
unsigned char V_26 = V_4 & 0xFF ;
F_9 ( V_13 , & V_26 , 1 ) ;
}
F_9 ( V_13 , V_18 , V_7 ? 128 : 64 ) ;
F_10 ( V_13 ) ;
memcpy ( V_16 , F_11 ( V_13 , 0 ) , 20 ) ;
F_12 ( V_13 ) ;
for ( V_11 = 1 ; V_11 < V_6 ; V_11 ++ )
F_13 ( V_25 , V_16 , V_16 , 20 ) ;
for ( V_11 = 0 ; V_11 < 20 && V_22 < V_8 ; V_11 ++ )
V_9 [ V_22 ++ ] = V_16 [ V_11 ] ;
if ( V_22 == V_8 ) {
F_14 ( V_14 ) ;
return TRUE ;
}
for ( V_11 = 0 ; V_11 < 64 ; V_11 ++ )
V_17 [ V_11 ] = V_16 [ V_11 % 20 ] ;
V_23 = 64 ;
V_10 = F_15 ( & V_14 , V_27 , V_17 , V_23 , & V_23 ) ;
if ( V_10 != 0 ) {
return FALSE ;
}
F_16 ( V_14 , V_14 , 1 ) ;
for ( V_11 = 0 ; V_11 < 128 ; V_11 += 64 ) {
T_4 V_28 ;
V_23 = 64 ;
V_10 = F_15 ( & V_28 , V_27 , V_18 + V_11 , V_23 , & V_23 ) ;
if ( V_10 != 0 ) {
return FALSE ;
}
F_17 ( V_28 , V_28 , V_14 ) ;
F_18 ( V_28 , 64 * 8 ) ;
V_23 = 64 ;
V_10 = F_19 ( V_27 , V_18 + V_11 , V_23 , & V_23 , V_28 ) ;
if ( V_10 != 0 ) {
return FALSE ;
}
F_14 ( V_28 ) ;
}
}
}
void F_20 ( void )
{
V_29 = 0 ;
V_20 = NULL ;
}
int F_21 ( const char * T_7 V_30 , T_2 * T_8 V_30 , T_9 * T_10 V_30 , T_11 * T_12 V_30 )
{
#ifdef F_22
const char * V_31 ;
T_13 V_32 ;
T_6 V_24 ;
int V_33 ;
int V_34 ;
int V_35 = 0 ;
int V_36 = 0 ;
int V_37 = 0 ;
char * V_38 = NULL ;
char * V_39 = NULL ;
char * V_40 = NULL ;
T_2 * V_41 = NULL ;
const T_14 * V_42 ;
T_15 * V_3 ;
T_1 * V_1 ;
char V_43 ;
T_16 V_44 = TRUE ;
if( ( ( V_45 == NULL ) || ( * V_45 == '\0' ) ) && ( V_46 == FALSE ) ) {
return FALSE ;
}
V_31 = F_23 () ;
if( ! strcmp ( V_31 , V_47 ) ) {
V_35 = 8 ;
V_36 = 24 ;
V_33 = V_48 ;
V_34 = V_49 ;
} else if( ! strcmp ( V_31 , V_50 ) ) {
V_35 = 0 ;
V_36 = 16 ;
V_33 = V_51 ;
V_34 = V_52 ;
} else if( ! strcmp ( V_31 , V_53 ) ) {
V_35 = 8 ;
V_36 = 5 ;
V_33 = V_54 ;
V_34 = V_49 ;
} else {
F_3 ( T_12 , L_2 ) ;
return FALSE ;
}
if( ( V_29 == 0 ) || ( V_20 == NULL ) ) {
F_3 ( T_12 , L_3 ) ;
return FALSE ;
}
V_38 = F_24 ( V_36 ) ;
if( ! F_4 ( 1 , V_20 , V_29 , V_45 , V_36 , V_38 ) )
return FALSE ;
if( V_35 ) {
V_39 = F_24 ( V_35 ) ;
if( ! F_4 ( 2 , V_20 , V_29 , V_45 , V_35 , V_39 ) )
return FALSE ;
}
V_24 = F_25 ( & V_32 , V_33 , V_34 , 0 ) ;
if ( F_8 ( V_24 ) )
return FALSE ;
V_24 = F_26 ( V_32 , V_38 , V_36 ) ;
if ( F_8 ( V_24 ) ) {
F_27 ( V_32 ) ;
return FALSE ;
}
if( V_35 ) {
V_24 = F_28 ( V_32 , V_39 , V_35 ) ;
if ( F_8 ( V_24 ) ) {
F_27 ( V_32 ) ;
return FALSE ;
}
}
V_37 = F_5 ( T_8 ) ;
V_40 = F_29 ( V_37 ) ;
V_24 = F_30 ( V_32 , V_40 , V_37 , F_6 ( T_8 , 0 , V_37 ) , V_37 ) ;
if ( F_8 ( V_24 ) ) {
F_3 ( T_12 , L_4 ) ;
F_27 ( V_32 ) ;
F_31 ( V_40 ) ;
return FALSE ;
}
F_27 ( V_32 ) ;
V_43 = V_40 [ V_37 - 1 ] ;
if( V_43 <= 0x08 ) {
int V_11 ;
for( V_11 = ( int ) V_43 ; V_11 > 0 ; V_11 -- ) {
if( V_40 [ V_37 - V_11 ] != V_43 ) {
V_44 = FALSE ;
break;
}
}
} else {
}
V_43 = V_40 [ 0 ] ;
if( ( V_43 != 0x30 ) && ( V_43 != 0x31 ) ) {
V_44 = FALSE ;
}
if( ! V_44 ) {
F_31 ( V_40 ) ;
F_3 ( T_12 , L_5 ) ;
return FALSE ;
}
F_3 ( T_12 , L_6 ) ;
V_1 = F_32 ( T_12 , V_55 ) ;
V_41 = F_33 ( T_8 , ( const V_56 * ) V_40 , V_37 , V_37 ) ;
F_34 ( V_41 , F_31 ) ;
V_3 = F_35 ( L_7 ) ;
V_42 = F_2 ( T_7 ) ;
F_36 ( V_3 , L_8 , V_42 ? V_42 : T_7 ) ;
F_37 ( T_10 -> V_57 , V_41 , V_3 -> V_58 ) ;
F_38 ( V_3 , TRUE ) ;
F_39 ( T_7 , V_41 , 0 , T_10 -> V_57 , V_1 ) ;
return TRUE ;
#else
return FALSE ;
#endif
}
static int
F_40 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_41 ( T_17 , T_10 , V_1 , T_18 , T_19 , T_20 ,
NULL ) ;
return T_19 ;
}
static int
F_42 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_43 ( T_17 , T_10 , V_1 , T_18 , T_19 ,
V_59 , T_20 , V_60 ) ;
return T_19 ;
}
static int
F_44 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_45 ( T_17 , T_10 , V_1 , T_18 , T_19 , T_20 ,
( T_20 == V_61 ? & V_20 : NULL ) ) ;
return T_19 ;
}
static int
F_46 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_41 ( T_17 , T_10 , V_1 , T_18 , T_19 , T_20 ,
( T_20 == V_62 ? & V_29 : NULL ) ) ;
return T_19 ;
}
static int
F_47 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_43 ( T_17 , T_10 , V_1 , T_18 , T_19 ,
V_63 , T_20 , V_64 ) ;
return T_19 ;
}
static int
F_48 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
#line 60 "../../asn1/pkcs12/pkcs12.cnf"
T_21 V_65 ;
V_65 = F_49 ( V_66 , V_67 ) ;
F_50 ( L_9 , L_10 , V_65 ) ;
T_19 = F_43 ( T_17 , T_10 , V_1 , T_18 , T_19 ,
V_68 , T_20 , V_69 ) ;
F_51 ( L_9 , L_10 ) ;
return T_19 ;
}
static int
F_52 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
#line 73 "../../asn1/pkcs12/pkcs12.cnf"
T_21 V_65 ;
V_65 = F_49 ( V_70 , V_67 ) ;
F_50 ( L_9 , L_10 , V_65 ) ;
T_19 = F_53 ( T_17 , T_10 , V_1 , T_18 , T_19 ,
V_71 , T_20 , V_72 ) ;
F_51 ( L_9 , L_10 ) ;
return T_19 ;
}
static int
F_54 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_55 ( T_17 , T_10 , V_1 , T_18 , T_19 , T_20 , & T_7 ) ;
#line 86 "../../asn1/pkcs12/pkcs12.cnf"
F_1 ( V_1 , T_7 ) ;
return T_19 ;
}
static int
F_56 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
#line 110 "../../asn1/pkcs12/pkcs12.cnf"
if( T_7 )
T_19 = F_39 ( T_7 , T_18 , T_19 , T_10 -> V_57 , V_1 ) ;
return T_19 ;
}
static int
F_57 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_55 ( T_17 , T_10 , V_1 , T_18 , T_19 , T_20 , & T_7 ) ;
#line 106 "../../asn1/pkcs12/pkcs12.cnf"
F_1 ( V_1 , T_7 ) ;
return T_19 ;
}
static int
F_58 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
#line 114 "../../asn1/pkcs12/pkcs12.cnf"
if( T_7 )
T_19 = F_39 ( T_7 , T_18 , T_19 , T_10 -> V_57 , V_1 ) ;
return T_19 ;
}
static int
F_59 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_60 ( T_17 , T_10 , V_1 , T_18 , T_19 ,
V_73 , T_20 , V_74 ) ;
return T_19 ;
}
static int
F_61 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_43 ( T_17 , T_10 , V_1 , T_18 , T_19 ,
V_75 , T_20 , V_76 ) ;
return T_19 ;
}
static int
F_62 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_60 ( T_17 , T_10 , V_1 , T_18 , T_19 ,
V_77 , T_20 , V_78 ) ;
return T_19 ;
}
static int
F_63 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_43 ( T_17 , T_10 , V_1 , T_18 , T_19 ,
V_79 , T_20 , V_80 ) ;
return T_19 ;
}
static int
F_64 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_53 ( T_17 , T_10 , V_1 , T_18 , T_19 ,
V_81 , T_20 , V_82 ) ;
return T_19 ;
}
static int
F_65 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_41 ( T_17 , T_10 , V_1 , T_18 , T_19 , T_20 ,
NULL ) ;
return T_19 ;
}
static int
F_66 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_45 ( T_17 , T_10 , V_1 , T_18 , T_19 , T_20 ,
NULL ) ;
return T_19 ;
}
static int
F_67 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_60 ( T_17 , T_10 , V_1 , T_18 , T_19 ,
V_83 , T_20 , V_84 ) ;
return T_19 ;
}
static int
F_68 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_43 ( T_17 , T_10 , V_1 , T_18 , T_19 ,
V_85 , T_20 , V_86 ) ;
return T_19 ;
}
static int
F_69 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_68 ( T_17 , T_18 , T_19 , T_10 , V_1 , T_20 ) ;
return T_19 ;
}
static int
F_70 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
#line 141 "../../asn1/pkcs12/pkcs12.cnf"
T_2 * T_8 ;
T_21 V_65 ;
T_19 = F_45 ( T_17 , T_10 , V_1 , T_18 , T_19 , T_20 ,
& T_8 ) ;
#line 147 "../../asn1/pkcs12/pkcs12.cnf"
V_65 = F_49 ( V_87 , V_67 ) ;
F_50 ( L_9 , T_7 , V_65 ) ;
F_21 ( T_7 , T_8 , T_10 , T_10 -> V_88 ) ;
F_51 ( L_9 , T_7 ) ;
return T_19 ;
}
static int
F_71 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_43 ( T_17 , T_10 , V_1 , T_18 , T_19 ,
V_89 , T_20 , V_90 ) ;
return T_19 ;
}
static int
F_72 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_71 ( T_17 , T_18 , T_19 , T_10 , V_1 , T_20 ) ;
return T_19 ;
}
static int
F_73 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_55 ( T_17 , T_10 , V_1 , T_18 , T_19 , T_20 , & T_7 ) ;
#line 91 "../../asn1/pkcs12/pkcs12.cnf"
F_1 ( V_1 , T_7 ) ;
return T_19 ;
}
static int
F_74 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
#line 118 "../../asn1/pkcs12/pkcs12.cnf"
if( T_7 )
T_19 = F_39 ( T_7 , T_18 , T_19 , T_10 -> V_57 , V_1 ) ;
return T_19 ;
}
static int
F_75 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_43 ( T_17 , T_10 , V_1 , T_18 , T_19 ,
V_91 , T_20 , V_92 ) ;
return T_19 ;
}
static int
F_76 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_55 ( T_17 , T_10 , V_1 , T_18 , T_19 , T_20 , & T_7 ) ;
#line 96 "../../asn1/pkcs12/pkcs12.cnf"
F_1 ( V_1 , T_7 ) ;
return T_19 ;
}
static int
F_77 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
#line 122 "../../asn1/pkcs12/pkcs12.cnf"
if( T_7 )
T_19 = F_39 ( T_7 , T_18 , T_19 , T_10 -> V_57 , V_1 ) ;
return T_19 ;
}
static int
F_78 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_43 ( T_17 , T_10 , V_1 , T_18 , T_19 ,
V_93 , T_20 , V_94 ) ;
return T_19 ;
}
static int
F_79 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_55 ( T_17 , T_10 , V_1 , T_18 , T_19 , T_20 , & T_7 ) ;
#line 101 "../../asn1/pkcs12/pkcs12.cnf"
F_1 ( V_1 , T_7 ) ;
return T_19 ;
}
static int
F_80 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
#line 126 "../../asn1/pkcs12/pkcs12.cnf"
if( T_7 )
T_19 = F_39 ( T_7 , T_18 , T_19 , T_10 -> V_57 , V_1 ) ;
return T_19 ;
}
static int
F_81 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_43 ( T_17 , T_10 , V_1 , T_18 , T_19 ,
V_95 , T_20 , V_96 ) ;
return T_19 ;
}
static int
F_82 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
#line 130 "../../asn1/pkcs12/pkcs12.cnf"
F_20 () ;
T_19 = F_43 ( T_17 , T_10 , V_1 , T_18 , T_19 ,
V_97 , T_20 , V_98 ) ;
return T_19 ;
}
static int
F_83 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_84 ( T_10 , V_1 , T_18 , T_19 ,
V_99 , T_20 , V_100 ,
NULL ) ;
return T_19 ;
}
static int
F_85 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_41 ( T_17 , T_10 , V_1 , T_18 , T_19 , T_20 ,
NULL ) ;
return T_19 ;
}
static int
F_86 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_43 ( T_17 , T_10 , V_1 , T_18 , T_19 ,
V_101 , T_20 , V_102 ) ;
return T_19 ;
}
static int
F_87 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_43 ( T_17 , T_10 , V_1 , T_18 , T_19 ,
V_103 , T_20 , V_104 ) ;
return T_19 ;
}
static int
F_88 ( T_16 T_17 V_30 , T_2 * T_18 V_30 , int T_19 V_30 , T_9 * T_10 V_30 , T_1 * V_1 V_30 , int T_20 V_30 ) {
T_19 = F_43 ( T_17 , T_10 , V_1 , T_18 , T_19 ,
V_105 , T_20 , V_106 ) ;
return T_19 ;
}
static void F_89 ( T_2 * T_18 V_30 , T_22 * V_57 V_30 , T_1 * V_1 V_30 ) {
T_9 V_107 ;
F_90 ( & V_107 , V_108 , TRUE , V_57 ) ;
F_48 ( FALSE , T_18 , 0 , & V_107 , V_1 , V_109 ) ;
}
static void F_91 ( T_2 * T_18 V_30 , T_22 * V_57 V_30 , T_1 * V_1 V_30 ) {
T_9 V_107 ;
F_90 ( & V_107 , V_108 , TRUE , V_57 ) ;
F_52 ( FALSE , T_18 , 0 , & V_107 , V_1 , V_110 ) ;
}
static void F_92 ( T_2 * T_18 V_30 , T_22 * V_57 V_30 , T_1 * V_1 V_30 ) {
T_9 V_107 ;
F_90 ( & V_107 , V_108 , TRUE , V_57 ) ;
F_64 ( FALSE , T_18 , 0 , & V_107 , V_1 , V_111 ) ;
}
static void F_93 ( T_2 * T_18 V_30 , T_22 * V_57 V_30 , T_1 * V_1 V_30 ) {
T_9 V_107 ;
F_90 ( & V_107 , V_108 , TRUE , V_57 ) ;
F_69 ( FALSE , T_18 , 0 , & V_107 , V_1 , V_112 ) ;
}
static void F_94 ( T_2 * T_18 V_30 , T_22 * V_57 V_30 , T_1 * V_1 V_30 ) {
T_9 V_107 ;
F_90 ( & V_107 , V_108 , TRUE , V_57 ) ;
F_72 ( FALSE , T_18 , 0 , & V_107 , V_1 , V_113 ) ;
}
static void F_95 ( T_2 * T_18 V_30 , T_22 * V_57 V_30 , T_1 * V_1 V_30 ) {
T_9 V_107 ;
F_90 ( & V_107 , V_108 , TRUE , V_57 ) ;
F_75 ( FALSE , T_18 , 0 , & V_107 , V_1 , V_114 ) ;
}
static void F_96 ( T_2 * T_18 V_30 , T_22 * V_57 V_30 , T_1 * V_1 V_30 ) {
T_9 V_107 ;
F_90 ( & V_107 , V_108 , TRUE , V_57 ) ;
F_78 ( FALSE , T_18 , 0 , & V_107 , V_1 , V_115 ) ;
}
static void F_97 ( T_2 * T_18 V_30 , T_22 * V_57 V_30 , T_1 * V_1 V_30 ) {
T_9 V_107 ;
F_90 ( & V_107 , V_108 , TRUE , V_57 ) ;
F_81 ( FALSE , T_18 , 0 , & V_107 , V_1 , V_116 ) ;
}
static void V_87 ( T_2 * T_18 V_30 , T_22 * V_57 V_30 , T_1 * V_1 V_30 ) {
T_9 V_107 ;
F_90 ( & V_107 , V_108 , TRUE , V_57 ) ;
F_68 ( FALSE , T_18 , 0 , & V_107 , V_1 , V_117 ) ;
}
static void F_98 ( T_2 * T_18 V_30 , T_22 * V_57 V_30 , T_1 * V_1 V_30 ) {
T_9 V_107 ;
F_90 ( & V_107 , V_108 , TRUE , V_57 ) ;
F_71 ( FALSE , T_18 , 0 , & V_107 , V_1 , V_118 ) ;
}
static void F_99 ( T_2 * T_18 V_30 , T_22 * V_57 V_30 , T_1 * V_1 V_30 ) {
T_9 V_107 ;
F_90 ( & V_107 , V_108 , TRUE , V_57 ) ;
F_82 ( FALSE , T_18 , 0 , & V_107 , V_1 , V_119 ) ;
}
static void F_100 ( T_2 * T_18 V_30 , T_22 * V_57 V_30 , T_1 * V_1 V_30 ) {
T_9 V_107 ;
F_90 ( & V_107 , V_108 , TRUE , V_57 ) ;
F_86 ( FALSE , T_18 , 0 , & V_107 , V_1 , V_120 ) ;
}
static void F_101 ( T_2 * T_18 V_30 , T_22 * V_57 V_30 , T_1 * V_1 V_30 ) {
T_9 V_107 ;
F_90 ( & V_107 , V_108 , TRUE , V_57 ) ;
F_87 ( FALSE , T_18 , 0 , & V_107 , V_1 , V_121 ) ;
}
static void F_102 ( T_2 * T_18 V_30 , T_22 * V_57 V_30 , T_1 * V_1 V_30 ) {
T_9 V_107 ;
F_90 ( & V_107 , V_108 , TRUE , V_57 ) ;
F_88 ( FALSE , T_18 , 0 , & V_107 , V_1 , V_122 ) ;
}
static int F_103 ( T_2 * T_18 )
{
T_23 V_123 ;
T_16 V_124 , V_125 ;
T_24 V_126 ;
T_25 V_127 ;
int T_19 = 0 ;
T_19 = F_104 ( T_18 , 0 , & V_123 , & V_124 , & V_126 ) ;
T_19 = F_105 ( T_18 , T_19 , & V_127 , & V_125 ) ;
if( ( V_123 == V_128 ) && ( V_126 == V_129 ) )
return T_19 ;
return 0 ;
}
static void V_66 ( T_2 * T_18 , T_22 * V_57 , T_1 * V_1 ) {
int T_19 = 0 ;
T_9 V_107 ;
F_90 ( & V_107 , V_108 , TRUE , V_57 ) ;
if( ( T_19 = F_103 ( T_18 ) ) > 0 )
F_52 ( FALSE , T_18 , T_19 , & V_107 , V_1 , V_110 ) ;
else
F_106 ( V_1 , T_18 , 0 , 1 , L_11 ) ;
}
static void V_70 ( T_2 * T_18 , T_22 * V_57 , T_1 * V_1 )
{
int T_19 = 0 ;
T_9 V_107 ;
F_90 ( & V_107 , V_108 , TRUE , V_57 ) ;
T_19 = F_103 ( T_18 ) ;
F_64 ( FALSE , T_18 , T_19 , & V_107 , V_1 , V_111 ) ;
}
static void F_107 ( T_2 * T_18 , T_22 * V_57 , T_1 * V_1 )
{
int T_19 = 0 ;
T_9 V_107 ;
F_90 ( & V_107 , V_108 , TRUE , V_57 ) ;
if( ( T_19 = F_103 ( T_18 ) ) > 0 )
F_108 ( FALSE , T_18 , T_19 , & V_107 , V_1 , V_130 ) ;
else
F_106 ( V_1 , T_18 , 0 , 1 , L_11 ) ;
}
void F_109 ( void ) {
static T_26 V_131 [] = {
{ & V_130 ,
{ L_12 , L_13 ,
V_132 , V_133 , NULL , 0 ,
L_13 , V_134 } } ,
#line 1 "../../asn1/pkcs12/packet-pkcs12-hfarr.c"
{ & V_109 ,
{ L_14 , L_15 ,
V_132 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_110 ,
{ L_16 , L_17 ,
V_135 , V_136 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_111 ,
{ L_18 , L_19 ,
V_135 , V_136 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_112 ,
{ L_20 , L_21 ,
V_132 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_113 ,
{ L_22 , L_23 ,
V_132 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_114 ,
{ L_24 , L_25 ,
V_132 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_115 ,
{ L_26 , L_27 ,
V_132 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_116 ,
{ L_28 , L_29 ,
V_132 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_117 ,
{ L_30 , L_31 ,
V_132 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_118 ,
{ L_32 , L_33 ,
V_132 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_119 ,
{ L_34 , L_35 ,
V_132 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_120 ,
{ L_36 , L_37 ,
V_132 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_121 ,
{ L_38 , L_39 ,
V_132 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_122 ,
{ L_40 , L_41 ,
V_132 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_137 ,
{ L_42 , L_43 ,
V_135 , V_136 , F_110 ( V_138 ) , 0 ,
NULL , V_134 } } ,
{ & V_139 ,
{ L_44 , L_45 ,
V_132 , V_133 , NULL , 0 ,
L_46 , V_134 } } ,
{ & V_140 ,
{ L_47 , L_48 ,
V_132 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_141 ,
{ L_49 , L_50 ,
V_132 , V_133 , NULL , 0 ,
L_51 , V_134 } } ,
{ & V_142 ,
{ L_52 , L_53 ,
V_143 , V_133 , NULL , 0 ,
L_54 , V_134 } } ,
{ & V_144 ,
{ L_55 , L_56 ,
V_145 , V_136 , NULL , 0 ,
L_57 , V_134 } } ,
{ & V_146 ,
{ L_58 , L_59 ,
V_132 , V_133 , NULL , 0 ,
L_60 , V_134 } } ,
{ & V_147 ,
{ L_61 , L_62 ,
V_143 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_148 ,
{ L_46 , L_63 ,
V_132 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_149 ,
{ L_64 , L_65 ,
V_132 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_150 ,
{ L_66 , L_67 ,
V_151 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_152 ,
{ L_68 , L_69 ,
V_132 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_153 ,
{ L_70 , L_71 ,
V_135 , V_136 , NULL , 0 ,
L_72 , V_134 } } ,
{ & V_154 ,
{ L_73 , L_74 ,
V_132 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_155 ,
{ L_75 , L_76 ,
V_151 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_156 ,
{ L_77 , L_78 ,
V_132 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_157 ,
{ L_79 , L_80 ,
V_151 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_158 ,
{ L_81 , L_82 ,
V_132 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_159 ,
{ L_83 , L_84 ,
V_151 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_160 ,
{ L_85 , L_86 ,
V_132 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_161 ,
{ L_87 , L_88 ,
V_151 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_162 ,
{ L_89 , L_90 ,
V_135 , V_136 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_163 ,
{ L_91 , L_92 ,
V_132 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_164 ,
{ L_42 , L_43 ,
V_135 , V_136 , F_110 ( V_165 ) , 0 ,
NULL , V_134 } } ,
{ & V_166 ,
{ L_93 , L_94 ,
V_132 , V_133 , NULL , 0 ,
L_95 , V_134 } } ,
{ & V_167 ,
{ L_96 , L_97 ,
V_143 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_168 ,
{ L_98 , L_99 ,
V_135 , V_136 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_169 ,
{ L_100 , L_101 ,
V_132 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_170 ,
{ L_102 , L_103 ,
V_132 , V_133 , NULL , 0 ,
L_95 , V_134 } } ,
{ & V_171 ,
{ L_104 , L_105 ,
V_143 , V_133 , NULL , 0 ,
NULL , V_134 } } ,
{ & V_61 ,
{ L_106 , L_107 ,
V_143 , V_133 , NULL , 0 ,
L_54 , V_134 } } ,
{ & V_62 ,
{ L_108 , L_109 ,
V_145 , V_136 , NULL , 0 ,
L_57 , V_134 } } ,
{ & V_172 ,
{ L_106 , L_107 ,
V_135 , V_136 , F_110 ( V_173 ) , 0 ,
L_110 , V_134 } } ,
{ & V_174 ,
{ L_111 , L_112 ,
V_143 , V_133 , NULL , 0 ,
L_54 , V_134 } } ,
{ & V_175 ,
{ L_113 , L_114 ,
V_132 , V_133 , NULL , 0 ,
L_95 , V_134 } } ,
{ & V_176 ,
{ L_115 , L_116 ,
V_135 , V_136 , NULL , 0 ,
L_117 , V_134 } } ,
{ & V_177 ,
{ L_118 , L_119 ,
V_132 , V_133 , NULL , 0 ,
L_95 , V_134 } } ,
{ & V_178 ,
{ L_120 , L_121 ,
V_132 , V_133 , NULL , 0 ,
L_95 , V_134 } } ,
{ & V_179 ,
{ L_122 , L_123 ,
V_132 , V_133 , NULL , 0 ,
L_95 , V_134 } } ,
{ & V_180 ,
{ L_124 , L_125 ,
V_132 , V_133 , NULL , 0 ,
L_95 , V_134 } } ,
#line 450 "../../asn1/pkcs12/packet-pkcs12-template.c"
} ;
static T_27 * V_181 [] = {
& V_55 ,
#line 1 "../../asn1/pkcs12/packet-pkcs12-ettarr.c"
& V_69 ,
& V_64 ,
& V_60 ,
& V_72 ,
& V_82 ,
& V_80 ,
& V_78 ,
& V_92 ,
& V_94 ,
& V_96 ,
& V_76 ,
& V_74 ,
& V_86 ,
& V_84 ,
& V_90 ,
& V_98 ,
& V_102 ,
& V_100 ,
& V_104 ,
& V_106 ,
#line 456 "../../asn1/pkcs12/packet-pkcs12-template.c"
} ;
T_28 * V_182 ;
V_67 = F_111 ( V_183 , V_184 , V_185 ) ;
F_112 ( V_67 , V_131 , F_113 ( V_131 ) ) ;
F_114 ( V_181 , F_113 ( V_181 ) ) ;
V_182 = F_115 ( V_67 , NULL ) ;
F_116 ( V_182 , L_126 ,
L_127 ,
L_128
L_129 , & V_45 ) ;
F_117 ( V_182 , L_130 ,
L_131 ,
L_132
L_133 , & V_46 ) ;
F_118 ( L_134 , V_67 , F_89 ) ;
F_119 ( L_135 , NULL , L_134 ) ;
F_119 ( L_136 , NULL , L_134 ) ;
}
void F_120 ( void ) {
#line 1 "../../asn1/pkcs12/packet-pkcs12-dis-tab.c"
F_121 ( L_137 , F_93 , V_67 , L_138 ) ;
F_121 ( L_139 , F_94 , V_67 , L_140 ) ;
F_121 ( L_141 , F_95 , V_67 , L_142 ) ;
F_121 ( L_143 , F_97 , V_67 , L_144 ) ;
F_121 ( L_145 , F_96 , V_67 , L_146 ) ;
F_121 ( L_147 , F_92 , V_67 , L_148 ) ;
F_121 ( L_149 , F_89 , V_67 , L_150 ) ;
F_121 ( L_151 , F_98 , V_67 , L_152 ) ;
F_121 ( L_153 , F_99 , V_67 , L_154 ) ;
F_121 ( L_155 , F_99 , V_67 , L_156 ) ;
F_121 ( L_157 , F_99 , V_67 , L_158 ) ;
F_121 ( L_159 , F_99 , V_67 , L_160 ) ;
F_121 ( L_161 , F_99 , V_67 , L_162 ) ;
F_121 ( L_163 , F_99 , V_67 , L_162 ) ;
F_121 ( L_164 , F_99 , V_67 , L_165 ) ;
F_121 ( L_166 , F_99 , V_67 , L_167 ) ;
F_121 ( L_168 , F_99 , V_67 , L_169 ) ;
F_121 ( L_170 , F_99 , V_67 , L_171 ) ;
F_121 ( L_172 , F_99 , V_67 , L_173 ) ;
F_121 ( L_174 , F_99 , V_67 , L_175 ) ;
F_121 ( L_176 , F_100 , V_67 , L_177 ) ;
F_121 ( L_178 , F_101 , V_67 , L_179 ) ;
F_121 ( L_180 , F_102 , V_67 , L_181 ) ;
#line 488 "../../asn1/pkcs12/packet-pkcs12-template.c"
F_121 ( L_182 , F_107 , V_67 , L_183 ) ;
}
