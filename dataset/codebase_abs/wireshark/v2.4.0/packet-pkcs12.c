static void F_1 ( T_1 * V_1 , const char * V_2 )
{
const char * V_3 = NULL ;
V_3 = F_2 ( F_3 () , V_2 ) ;
F_4 ( V_1 , L_1 , V_3 ? V_3 : V_2 ) ;
}
static int
F_5 ( unsigned int V_4 , T_2 * V_5 , unsigned int V_6 ,
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
V_21 = F_6 ( V_5 ) ;
V_20 = ( char * ) F_7 ( F_3 () , V_5 , 0 , V_21 ) ;
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
V_24 = F_8 ( & V_13 , V_25 , 0 ) ;
if ( F_9 ( V_24 ) )
{
return FALSE ;
}
for ( V_11 = 0 ; V_11 < 64 ; V_11 ++ )
{
unsigned char V_26 = V_4 & 0xFF ;
F_10 ( V_13 , & V_26 , 1 ) ;
}
F_10 ( V_13 , V_18 , V_7 ? 128 : 64 ) ;
F_11 ( V_13 ) ;
memcpy ( V_16 , F_12 ( V_13 , 0 ) , 20 ) ;
F_13 ( V_13 ) ;
for ( V_11 = 1 ; V_11 < V_6 ; V_11 ++ )
F_14 ( V_25 , V_16 , V_16 , 20 ) ;
for ( V_11 = 0 ; V_11 < 20 && V_22 < V_8 ; V_11 ++ )
V_9 [ V_22 ++ ] = V_16 [ V_11 ] ;
if ( V_22 == V_8 )
{
F_15 ( V_14 ) ;
return TRUE ;
}
for ( V_11 = 0 ; V_11 < 64 ; V_11 ++ )
V_17 [ V_11 ] = V_16 [ V_11 % 20 ] ;
V_23 = 64 ;
V_10 = F_16 ( & V_14 , V_27 , V_17 , V_23 , & V_23 ) ;
if ( V_10 != 0 )
{
return FALSE ;
}
F_17 ( V_14 , V_14 , 1 ) ;
for ( V_11 = 0 ; V_11 < 128 ; V_11 += 64 )
{
T_4 V_28 ;
V_23 = 64 ;
V_10 = F_16 ( & V_28 , V_27 , V_18 + V_11 , V_23 , & V_23 ) ;
if ( V_10 != 0 )
{
return FALSE ;
}
F_18 ( V_28 , V_28 , V_14 ) ;
F_19 ( V_28 , 64 * 8 ) ;
V_23 = 64 ;
V_10 = F_20 ( V_27 , V_18 + V_11 , V_23 , & V_23 , V_28 ) ;
if ( V_10 != 0 )
{
return FALSE ;
}
F_15 ( V_28 ) ;
}
}
}
void F_21 ( void )
{
V_29 = 0 ;
V_30 = NULL ;
}
int F_22 ( const char * T_7 V_31 , T_2 * T_8 V_31 , T_9 * T_10 V_31 , T_11 * T_12 V_31 , T_13 * T_14 V_31 )
{
const char * V_32 ;
T_15 V_33 ;
T_6 V_24 ;
int V_34 ;
int V_35 ;
int V_36 = 0 ;
int V_37 = 0 ;
int V_38 = 0 ;
char * V_39 = NULL ;
char * V_40 = NULL ;
char * V_41 = NULL ;
T_2 * V_42 = NULL ;
const T_16 * V_43 ;
T_17 * V_3 ;
T_1 * V_1 ;
char V_44 ;
T_18 V_45 = TRUE ;
if( ( ( V_46 == NULL ) || ( * V_46 == '\0' ) ) && ( V_47 == FALSE ) ) {
return FALSE ;
}
V_32 = F_23 () ;
if( ! strcmp ( V_32 , V_48 ) ) {
V_36 = 8 ;
V_37 = 24 ;
V_34 = V_49 ;
V_35 = V_50 ;
} else if( ! strcmp ( V_32 , V_51 ) ) {
V_36 = 0 ;
V_37 = 16 ;
V_34 = V_52 ;
V_35 = V_53 ;
} else if( ! strcmp ( V_32 , V_54 ) ) {
V_36 = 8 ;
V_37 = 5 ;
V_34 = V_55 ;
V_35 = V_50 ;
} else {
F_4 ( T_14 , L_2 ) ;
return FALSE ;
}
if( ( V_29 == 0 ) || ( V_30 == NULL ) ) {
F_4 ( T_14 , L_3 ) ;
return FALSE ;
}
V_39 = ( char * ) F_24 ( F_3 () , V_37 ) ;
if( ! F_5 ( 1 , V_30 , V_29 , V_46 , V_37 , V_39 ) )
return FALSE ;
if( V_36 ) {
V_40 = ( char * ) F_24 ( F_3 () , V_36 ) ;
if( ! F_5 ( 2 , V_30 , V_29 , V_46 , V_36 , V_40 ) )
return FALSE ;
}
V_24 = F_25 ( & V_33 , V_34 , V_35 , 0 ) ;
if ( F_9 ( V_24 ) )
return FALSE ;
V_24 = F_26 ( V_33 , V_39 , V_37 ) ;
if ( F_9 ( V_24 ) ) {
F_27 ( V_33 ) ;
return FALSE ;
}
if( V_36 ) {
V_24 = F_28 ( V_33 , V_40 , V_36 ) ;
if ( F_9 ( V_24 ) ) {
F_27 ( V_33 ) ;
return FALSE ;
}
}
V_38 = F_6 ( T_8 ) ;
V_41 = ( char * ) F_24 ( T_10 -> V_56 , V_38 ) ;
V_24 = F_29 ( V_33 , V_41 , V_38 , ( char * ) F_7 ( F_3 () , T_8 , 0 , V_38 ) , V_38 ) ;
if ( F_9 ( V_24 ) ) {
F_4 ( T_14 , L_4 ) ;
F_27 ( V_33 ) ;
return FALSE ;
}
F_27 ( V_33 ) ;
V_44 = V_41 [ V_38 - 1 ] ;
if( V_44 <= 0x08 ) {
int V_11 ;
for( V_11 = ( int ) V_44 ; V_11 > 0 ; V_11 -- ) {
if( V_41 [ V_38 - V_11 ] != V_44 ) {
V_45 = FALSE ;
break;
}
}
} else {
}
V_44 = V_41 [ 0 ] ;
if( ( V_44 != 0x30 ) && ( V_44 != 0x31 ) ) {
V_45 = FALSE ;
}
if( ! V_45 ) {
F_4 ( T_14 , L_5 ) ;
return FALSE ;
}
F_4 ( T_14 , L_6 ) ;
V_1 = F_30 ( T_14 , V_57 ) ;
V_42 = F_31 ( T_8 , ( const V_58 * ) V_41 , V_38 , V_38 ) ;
V_3 = F_32 ( L_7 ) ;
V_43 = F_2 ( F_3 () , T_7 ) ;
F_33 ( V_3 , L_8 , V_43 ? V_43 : T_7 ) ;
F_34 ( T_12 -> T_10 , V_42 , V_3 -> V_59 ) ;
F_35 ( V_3 , TRUE ) ;
F_36 ( T_7 , V_42 , 0 , T_12 -> T_10 , V_1 , NULL ) ;
return TRUE ;
}
static int
F_37 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_38 ( T_19 , T_12 , V_1 , T_20 , T_21 , T_22 ,
NULL ) ;
return T_21 ;
}
static int
F_39 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_40 ( T_19 , T_12 , V_1 , T_20 , T_21 , T_22 ,
( T_22 == V_60 ? & V_30 : NULL ) ) ;
return T_21 ;
}
static int
F_41 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_38 ( T_19 , T_12 , V_1 , T_20 , T_21 , T_22 ,
( T_22 == V_61 ? & V_29 : NULL ) ) ;
return T_21 ;
}
static int
F_42 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_43 ( T_19 , T_12 , V_1 , T_20 , T_21 ,
V_62 , T_22 , V_63 ) ;
return T_21 ;
}
static int
F_44 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
#line 58 "./asn1/pkcs12/pkcs12.cnf"
T_23 V_64 ;
V_64 = F_45 ( V_65 , V_66 ) ;
F_46 ( L_9 , L_10 , V_64 ) ;
T_21 = F_43 ( T_19 , T_12 , V_1 , T_20 , T_21 ,
V_67 , T_22 , V_68 ) ;
F_47 ( L_9 , L_10 ) ;
return T_21 ;
}
static int
F_48 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
#line 71 "./asn1/pkcs12/pkcs12.cnf"
T_23 V_64 ;
V_64 = F_45 ( V_69 , V_66 ) ;
F_46 ( L_9 , L_10 , V_64 ) ;
T_21 = F_49 ( T_19 , T_12 , V_1 , T_20 , T_21 ,
V_70 , T_22 , V_71 ) ;
F_47 ( L_9 , L_10 ) ;
return T_21 ;
}
static int
F_50 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_51 ( T_19 , T_12 , V_1 , T_20 , T_21 , T_22 , & V_72 ) ;
#line 84 "./asn1/pkcs12/pkcs12.cnf"
F_1 ( V_1 , V_72 ) ;
return T_21 ;
}
static int
F_52 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
#line 108 "./asn1/pkcs12/pkcs12.cnf"
if( V_72 )
T_21 = F_36 ( V_72 , T_20 , T_21 , T_12 -> T_10 , V_1 , NULL ) ;
return T_21 ;
}
static int
F_53 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_51 ( T_19 , T_12 , V_1 , T_20 , T_21 , T_22 , & V_72 ) ;
#line 104 "./asn1/pkcs12/pkcs12.cnf"
F_1 ( V_1 , V_72 ) ;
return T_21 ;
}
static int
F_54 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
#line 112 "./asn1/pkcs12/pkcs12.cnf"
if( V_72 )
T_21 = F_36 ( V_72 , T_20 , T_21 , T_12 -> T_10 , V_1 , NULL ) ;
return T_21 ;
}
static int
F_55 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_56 ( T_19 , T_12 , V_1 , T_20 , T_21 ,
V_73 , T_22 , V_74 ) ;
return T_21 ;
}
static int
F_57 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_43 ( T_19 , T_12 , V_1 , T_20 , T_21 ,
V_75 , T_22 , V_76 ) ;
return T_21 ;
}
static int
F_58 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_56 ( T_19 , T_12 , V_1 , T_20 , T_21 ,
V_77 , T_22 , V_78 ) ;
return T_21 ;
}
static int
F_59 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_43 ( T_19 , T_12 , V_1 , T_20 , T_21 ,
V_79 , T_22 , V_80 ) ;
return T_21 ;
}
static int
F_60 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_49 ( T_19 , T_12 , V_1 , T_20 , T_21 ,
V_81 , T_22 , V_82 ) ;
return T_21 ;
}
static int
F_61 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_38 ( T_19 , T_12 , V_1 , T_20 , T_21 , T_22 ,
NULL ) ;
return T_21 ;
}
static int
F_62 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_40 ( T_19 , T_12 , V_1 , T_20 , T_21 , T_22 ,
NULL ) ;
return T_21 ;
}
static int
F_63 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_56 ( T_19 , T_12 , V_1 , T_20 , T_21 ,
V_83 , T_22 , V_84 ) ;
return T_21 ;
}
static int
F_64 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_43 ( T_19 , T_12 , V_1 , T_20 , T_21 ,
V_85 , T_22 , V_86 ) ;
return T_21 ;
}
static int
F_65 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_64 ( T_19 , T_20 , T_21 , T_12 , V_1 , T_22 ) ;
return T_21 ;
}
static int
F_66 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
#line 139 "./asn1/pkcs12/pkcs12.cnf"
T_2 * T_8 ;
T_23 V_64 ;
T_21 = F_40 ( T_19 , T_12 , V_1 , T_20 , T_21 , T_22 ,
& T_8 ) ;
#line 145 "./asn1/pkcs12/pkcs12.cnf"
V_64 = F_45 ( V_87 , V_66 ) ;
F_46 ( L_9 , V_72 , V_64 ) ;
F_22 ( V_72 , T_8 , T_12 -> T_10 , T_12 , T_12 -> V_88 ) ;
F_47 ( L_9 , V_72 ) ;
return T_21 ;
}
static int
F_67 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_43 ( T_19 , T_12 , V_1 , T_20 , T_21 ,
V_89 , T_22 , V_90 ) ;
return T_21 ;
}
static int
F_68 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_67 ( T_19 , T_20 , T_21 , T_12 , V_1 , T_22 ) ;
return T_21 ;
}
static int
F_69 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_51 ( T_19 , T_12 , V_1 , T_20 , T_21 , T_22 , & V_72 ) ;
#line 89 "./asn1/pkcs12/pkcs12.cnf"
F_1 ( V_1 , V_72 ) ;
return T_21 ;
}
static int
F_70 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
#line 116 "./asn1/pkcs12/pkcs12.cnf"
if( V_72 )
T_21 = F_36 ( V_72 , T_20 , T_21 , T_12 -> T_10 , V_1 , NULL ) ;
return T_21 ;
}
static int
F_71 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_43 ( T_19 , T_12 , V_1 , T_20 , T_21 ,
V_91 , T_22 , V_92 ) ;
return T_21 ;
}
static int
F_72 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_51 ( T_19 , T_12 , V_1 , T_20 , T_21 , T_22 , & V_72 ) ;
#line 94 "./asn1/pkcs12/pkcs12.cnf"
F_1 ( V_1 , V_72 ) ;
return T_21 ;
}
static int
F_73 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
#line 120 "./asn1/pkcs12/pkcs12.cnf"
if( V_72 )
T_21 = F_36 ( V_72 , T_20 , T_21 , T_12 -> T_10 , V_1 , NULL ) ;
return T_21 ;
}
static int
F_74 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_43 ( T_19 , T_12 , V_1 , T_20 , T_21 ,
V_93 , T_22 , V_94 ) ;
return T_21 ;
}
static int
F_75 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_51 ( T_19 , T_12 , V_1 , T_20 , T_21 , T_22 , & V_72 ) ;
#line 99 "./asn1/pkcs12/pkcs12.cnf"
F_1 ( V_1 , V_72 ) ;
return T_21 ;
}
static int
F_76 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
#line 124 "./asn1/pkcs12/pkcs12.cnf"
if( V_72 )
T_21 = F_36 ( V_72 , T_20 , T_21 , T_12 -> T_10 , V_1 , NULL ) ;
return T_21 ;
}
static int
F_77 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_43 ( T_19 , T_12 , V_1 , T_20 , T_21 ,
V_95 , T_22 , V_96 ) ;
return T_21 ;
}
static int
F_78 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
#line 128 "./asn1/pkcs12/pkcs12.cnf"
F_21 () ;
T_21 = F_43 ( T_19 , T_12 , V_1 , T_20 , T_21 ,
V_97 , T_22 , V_98 ) ;
return T_21 ;
}
static int
F_79 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_80 ( T_12 , V_1 , T_20 , T_21 ,
V_99 , T_22 , V_100 ,
NULL ) ;
return T_21 ;
}
static int
F_81 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_38 ( T_19 , T_12 , V_1 , T_20 , T_21 , T_22 ,
NULL ) ;
return T_21 ;
}
static int
F_82 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_43 ( T_19 , T_12 , V_1 , T_20 , T_21 ,
V_101 , T_22 , V_102 ) ;
return T_21 ;
}
static int
F_83 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_43 ( T_19 , T_12 , V_1 , T_20 , T_21 ,
V_103 , T_22 , V_104 ) ;
return T_21 ;
}
static int
F_84 ( T_18 T_19 V_31 , T_2 * T_20 V_31 , int T_21 V_31 , T_11 * T_12 V_31 , T_1 * V_1 V_31 , int T_22 V_31 ) {
T_21 = F_43 ( T_19 , T_12 , V_1 , T_20 , T_21 ,
V_105 , T_22 , V_106 ) ;
return T_21 ;
}
static int F_85 ( T_2 * T_20 V_31 , T_9 * T_10 V_31 , T_1 * V_1 V_31 , void * T_24 V_31 ) {
int T_21 = 0 ;
T_11 V_107 ;
F_86 ( & V_107 , V_108 , TRUE , T_10 ) ;
T_21 = F_44 ( FALSE , T_20 , T_21 , & V_107 , V_1 , V_109 ) ;
return T_21 ;
}
static int F_87 ( T_2 * T_20 V_31 , T_9 * T_10 V_31 , T_1 * V_1 V_31 , void * T_24 V_31 ) {
int T_21 = 0 ;
T_11 V_107 ;
F_86 ( & V_107 , V_108 , TRUE , T_10 ) ;
T_21 = F_60 ( FALSE , T_20 , T_21 , & V_107 , V_1 , V_110 ) ;
return T_21 ;
}
static int F_88 ( T_2 * T_20 V_31 , T_9 * T_10 V_31 , T_1 * V_1 V_31 , void * T_24 V_31 ) {
int T_21 = 0 ;
T_11 V_107 ;
F_86 ( & V_107 , V_108 , TRUE , T_10 ) ;
T_21 = F_65 ( FALSE , T_20 , T_21 , & V_107 , V_1 , V_111 ) ;
return T_21 ;
}
static int F_89 ( T_2 * T_20 V_31 , T_9 * T_10 V_31 , T_1 * V_1 V_31 , void * T_24 V_31 ) {
int T_21 = 0 ;
T_11 V_107 ;
F_86 ( & V_107 , V_108 , TRUE , T_10 ) ;
T_21 = F_68 ( FALSE , T_20 , T_21 , & V_107 , V_1 , V_112 ) ;
return T_21 ;
}
static int F_90 ( T_2 * T_20 V_31 , T_9 * T_10 V_31 , T_1 * V_1 V_31 , void * T_24 V_31 ) {
int T_21 = 0 ;
T_11 V_107 ;
F_86 ( & V_107 , V_108 , TRUE , T_10 ) ;
T_21 = F_71 ( FALSE , T_20 , T_21 , & V_107 , V_1 , V_113 ) ;
return T_21 ;
}
static int F_91 ( T_2 * T_20 V_31 , T_9 * T_10 V_31 , T_1 * V_1 V_31 , void * T_24 V_31 ) {
int T_21 = 0 ;
T_11 V_107 ;
F_86 ( & V_107 , V_108 , TRUE , T_10 ) ;
T_21 = F_74 ( FALSE , T_20 , T_21 , & V_107 , V_1 , V_114 ) ;
return T_21 ;
}
static int F_92 ( T_2 * T_20 V_31 , T_9 * T_10 V_31 , T_1 * V_1 V_31 , void * T_24 V_31 ) {
int T_21 = 0 ;
T_11 V_107 ;
F_86 ( & V_107 , V_108 , TRUE , T_10 ) ;
T_21 = F_77 ( FALSE , T_20 , T_21 , & V_107 , V_1 , V_115 ) ;
return T_21 ;
}
static int V_87 ( T_2 * T_20 V_31 , T_9 * T_10 V_31 , T_1 * V_1 V_31 , void * T_24 V_31 ) {
int T_21 = 0 ;
T_11 V_107 ;
F_86 ( & V_107 , V_108 , TRUE , T_10 ) ;
T_21 = F_64 ( FALSE , T_20 , T_21 , & V_107 , V_1 , V_116 ) ;
return T_21 ;
}
static int F_93 ( T_2 * T_20 V_31 , T_9 * T_10 V_31 , T_1 * V_1 V_31 , void * T_24 V_31 ) {
int T_21 = 0 ;
T_11 V_107 ;
F_86 ( & V_107 , V_108 , TRUE , T_10 ) ;
T_21 = F_67 ( FALSE , T_20 , T_21 , & V_107 , V_1 , V_117 ) ;
return T_21 ;
}
static int F_94 ( T_2 * T_20 V_31 , T_9 * T_10 V_31 , T_1 * V_1 V_31 , void * T_24 V_31 ) {
int T_21 = 0 ;
T_11 V_107 ;
F_86 ( & V_107 , V_108 , TRUE , T_10 ) ;
T_21 = F_78 ( FALSE , T_20 , T_21 , & V_107 , V_1 , V_118 ) ;
return T_21 ;
}
static int F_95 ( T_2 * T_20 V_31 , T_9 * T_10 V_31 , T_1 * V_1 V_31 , void * T_24 V_31 ) {
int T_21 = 0 ;
T_11 V_107 ;
F_86 ( & V_107 , V_108 , TRUE , T_10 ) ;
T_21 = F_82 ( FALSE , T_20 , T_21 , & V_107 , V_1 , V_119 ) ;
return T_21 ;
}
static int F_96 ( T_2 * T_20 V_31 , T_9 * T_10 V_31 , T_1 * V_1 V_31 , void * T_24 V_31 ) {
int T_21 = 0 ;
T_11 V_107 ;
F_86 ( & V_107 , V_108 , TRUE , T_10 ) ;
T_21 = F_83 ( FALSE , T_20 , T_21 , & V_107 , V_1 , V_120 ) ;
return T_21 ;
}
static int F_97 ( T_2 * T_20 V_31 , T_9 * T_10 V_31 , T_1 * V_1 V_31 , void * T_24 V_31 ) {
int T_21 = 0 ;
T_11 V_107 ;
F_86 ( & V_107 , V_108 , TRUE , T_10 ) ;
T_21 = F_84 ( FALSE , T_20 , T_21 , & V_107 , V_1 , V_121 ) ;
return T_21 ;
}
static int F_98 ( T_2 * T_20 )
{
T_25 V_122 ;
T_18 V_123 , V_124 ;
T_26 V_125 ;
T_27 V_126 ;
int T_21 = 0 ;
T_21 = F_99 ( T_20 , 0 , & V_122 , & V_123 , & V_125 ) ;
T_21 = F_100 ( T_20 , T_21 , & V_126 , & V_124 ) ;
if( ( V_122 == V_127 ) && ( V_125 == V_128 ) )
return T_21 ;
return 0 ;
}
static int V_65 ( T_2 * T_20 , T_9 * T_10 , T_1 * V_1 , void * T_24 V_31 ) {
int T_21 = 0 ;
T_11 V_107 ;
F_86 ( & V_107 , V_108 , TRUE , T_10 ) ;
if( ( T_21 = F_98 ( T_20 ) ) > 0 )
F_48 ( FALSE , T_20 , T_21 , & V_107 , V_1 , V_129 ) ;
else
F_101 ( V_1 , T_10 , & V_130 , T_20 , 0 , 1 ) ;
return F_6 ( T_20 ) ;
}
static int V_69 ( T_2 * T_20 , T_9 * T_10 , T_1 * V_1 , void * T_24 V_31 )
{
int T_21 = 0 ;
T_11 V_107 ;
F_86 ( & V_107 , V_108 , TRUE , T_10 ) ;
T_21 = F_98 ( T_20 ) ;
F_60 ( FALSE , T_20 , T_21 , & V_107 , V_1 , V_110 ) ;
return F_6 ( T_20 ) ;
}
static int F_102 ( T_2 * T_20 , T_9 * T_10 , T_1 * V_1 , void * T_24 V_31 )
{
int T_21 = 0 ;
T_11 V_107 ;
F_86 ( & V_107 , V_108 , TRUE , T_10 ) ;
if( ( T_21 = F_98 ( T_20 ) ) > 0 )
F_103 ( FALSE , T_20 , T_21 , & V_107 , V_1 , V_131 ) ;
else
F_101 ( V_1 , T_10 , & V_130 , T_20 , 0 , 1 ) ;
return F_6 ( T_20 ) ;
}
void F_104 ( void ) {
static T_28 V_132 [] = {
{ & V_131 ,
{ L_11 , L_12 ,
V_133 , V_134 , NULL , 0 ,
L_12 , V_135 } } ,
{ & V_129 ,
{ L_13 , L_14 ,
V_136 , V_137 , NULL , 0 ,
NULL , V_135 } } ,
#line 1 "./asn1/pkcs12/packet-pkcs12-hfarr.c"
{ & V_109 ,
{ L_15 , L_16 ,
V_133 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_110 ,
{ L_17 , L_18 ,
V_136 , V_137 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_111 ,
{ L_19 , L_20 ,
V_133 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_112 ,
{ L_21 , L_22 ,
V_133 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_113 ,
{ L_23 , L_24 ,
V_133 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_114 ,
{ L_25 , L_26 ,
V_133 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_115 ,
{ L_27 , L_28 ,
V_133 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_116 ,
{ L_29 , L_30 ,
V_133 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_117 ,
{ L_31 , L_32 ,
V_133 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_118 ,
{ L_33 , L_34 ,
V_133 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_119 ,
{ L_35 , L_36 ,
V_133 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_120 ,
{ L_37 , L_38 ,
V_133 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_121 ,
{ L_39 , L_40 ,
V_133 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_138 ,
{ L_41 , L_42 ,
V_136 , V_137 , F_105 ( V_139 ) , 0 ,
NULL , V_135 } } ,
{ & V_140 ,
{ L_43 , L_44 ,
V_133 , V_134 , NULL , 0 ,
L_45 , V_135 } } ,
{ & V_141 ,
{ L_46 , L_47 ,
V_133 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_142 ,
{ L_48 , L_49 ,
V_133 , V_134 , NULL , 0 ,
L_50 , V_135 } } ,
{ & V_143 ,
{ L_51 , L_52 ,
V_144 , V_134 , NULL , 0 ,
L_53 , V_135 } } ,
{ & V_145 ,
{ L_54 , L_55 ,
V_146 , V_137 , NULL , 0 ,
L_56 , V_135 } } ,
{ & V_147 ,
{ L_45 , L_57 ,
V_133 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_148 ,
{ L_58 , L_59 ,
V_133 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_149 ,
{ L_60 , L_61 ,
V_150 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_151 ,
{ L_62 , L_63 ,
V_133 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_152 ,
{ L_64 , L_65 ,
V_136 , V_137 , NULL , 0 ,
L_66 , V_135 } } ,
{ & V_153 ,
{ L_67 , L_68 ,
V_133 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_154 ,
{ L_69 , L_70 ,
V_150 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_155 ,
{ L_71 , L_72 ,
V_133 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_156 ,
{ L_73 , L_74 ,
V_150 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_157 ,
{ L_75 , L_76 ,
V_133 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_158 ,
{ L_77 , L_78 ,
V_150 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_159 ,
{ L_79 , L_80 ,
V_133 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_160 ,
{ L_81 , L_82 ,
V_150 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_161 ,
{ L_83 , L_84 ,
V_136 , V_137 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_162 ,
{ L_85 , L_86 ,
V_133 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_163 ,
{ L_41 , L_42 ,
V_136 , V_137 , F_105 ( V_164 ) , 0 ,
NULL , V_135 } } ,
{ & V_165 ,
{ L_87 , L_88 ,
V_133 , V_134 , NULL , 0 ,
L_89 , V_135 } } ,
{ & V_166 ,
{ L_90 , L_91 ,
V_144 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_167 ,
{ L_92 , L_93 ,
V_136 , V_137 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_168 ,
{ L_94 , L_95 ,
V_133 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_169 ,
{ L_96 , L_97 ,
V_133 , V_134 , NULL , 0 ,
L_89 , V_135 } } ,
{ & V_170 ,
{ L_98 , L_99 ,
V_144 , V_134 , NULL , 0 ,
NULL , V_135 } } ,
{ & V_60 ,
{ L_100 , L_101 ,
V_144 , V_134 , NULL , 0 ,
L_53 , V_135 } } ,
{ & V_61 ,
{ L_102 , L_103 ,
V_146 , V_137 , NULL , 0 ,
L_56 , V_135 } } ,
{ & V_171 ,
{ L_100 , L_101 ,
V_136 , V_137 , F_105 ( V_172 ) , 0 ,
L_104 , V_135 } } ,
{ & V_173 ,
{ L_105 , L_106 ,
V_144 , V_134 , NULL , 0 ,
L_53 , V_135 } } ,
{ & V_174 ,
{ L_107 , L_108 ,
V_133 , V_134 , NULL , 0 ,
L_89 , V_135 } } ,
{ & V_175 ,
{ L_109 , L_110 ,
V_136 , V_137 , NULL , 0 ,
L_111 , V_135 } } ,
{ & V_176 ,
{ L_112 , L_113 ,
V_133 , V_134 , NULL , 0 ,
L_89 , V_135 } } ,
{ & V_177 ,
{ L_114 , L_115 ,
V_133 , V_134 , NULL , 0 ,
L_89 , V_135 } } ,
{ & V_178 ,
{ L_116 , L_117 ,
V_133 , V_134 , NULL , 0 ,
L_89 , V_135 } } ,
{ & V_179 ,
{ L_118 , L_119 ,
V_133 , V_134 , NULL , 0 ,
L_89 , V_135 } } ,
#line 450 "./asn1/pkcs12/packet-pkcs12-template.c"
} ;
static T_29 * V_180 [] = {
& V_57 ,
#line 1 "./asn1/pkcs12/packet-pkcs12-ettarr.c"
& V_68 ,
& V_63 ,
& V_71 ,
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
#line 456 "./asn1/pkcs12/packet-pkcs12-template.c"
} ;
static T_30 V_181 [] = {
{ & V_130 , { L_120 , V_182 , V_183 , L_121 , V_184 } } ,
} ;
T_31 * V_185 ;
T_32 * V_186 ;
V_66 = F_106 ( V_187 , V_188 , V_189 ) ;
F_107 ( V_66 , V_132 , F_108 ( V_132 ) ) ;
F_109 ( V_180 , F_108 ( V_180 ) ) ;
V_186 = F_110 ( V_66 ) ;
F_111 ( V_186 , V_181 , F_108 ( V_181 ) ) ;
V_185 = F_112 ( V_66 , NULL ) ;
F_113 ( V_185 , L_122 ,
L_123 ,
L_124
L_125 , & V_46 ) ;
F_114 ( V_185 , L_126 ,
L_127 ,
L_128
L_129 , & V_47 ) ;
F_115 ( L_130 , V_66 , F_85 ) ;
F_116 ( L_131 , NULL , L_130 ) ;
F_116 ( L_132 , NULL , L_130 ) ;
}
void F_117 ( void ) {
#line 1 "./asn1/pkcs12/packet-pkcs12-dis-tab.c"
F_118 ( L_133 , F_88 , V_66 , L_134 ) ;
F_118 ( L_135 , F_89 , V_66 , L_136 ) ;
F_118 ( L_137 , F_90 , V_66 , L_138 ) ;
F_118 ( L_139 , F_92 , V_66 , L_140 ) ;
F_118 ( L_141 , F_91 , V_66 , L_142 ) ;
F_118 ( L_143 , F_87 , V_66 , L_144 ) ;
F_118 ( L_145 , F_85 , V_66 , L_146 ) ;
F_118 ( L_147 , F_93 , V_66 , L_148 ) ;
F_118 ( L_149 , F_94 , V_66 , L_150 ) ;
F_118 ( L_151 , F_94 , V_66 , L_152 ) ;
F_118 ( L_153 , F_94 , V_66 , L_154 ) ;
F_118 ( L_155 , F_94 , V_66 , L_156 ) ;
F_118 ( L_157 , F_94 , V_66 , L_158 ) ;
F_118 ( L_159 , F_94 , V_66 , L_160 ) ;
F_118 ( L_161 , F_94 , V_66 , L_162 ) ;
F_118 ( L_163 , F_94 , V_66 , L_164 ) ;
F_118 ( L_165 , F_94 , V_66 , L_166 ) ;
F_118 ( L_167 , F_94 , V_66 , L_168 ) ;
F_118 ( L_169 , F_94 , V_66 , L_170 ) ;
F_118 ( L_171 , F_94 , V_66 , L_172 ) ;
F_118 ( L_173 , F_95 , V_66 , L_174 ) ;
F_118 ( L_175 , F_96 , V_66 , L_176 ) ;
F_118 ( L_177 , F_97 , V_66 , L_178 ) ;
#line 495 "./asn1/pkcs12/packet-pkcs12-template.c"
F_118 ( L_179 , F_102 , V_66 , L_180 ) ;
}
