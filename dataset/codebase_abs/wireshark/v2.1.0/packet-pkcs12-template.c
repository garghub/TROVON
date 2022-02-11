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
int F_22 ( const char * T_7 V_31 , T_2 * T_8 V_31 , T_9 * T_10 V_31 , T_11 * T_12 V_31 )
{
#ifdef F_23
const char * V_32 ;
T_13 V_33 ;
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
const T_14 * V_43 ;
T_15 * V_3 ;
T_1 * V_1 ;
char V_44 ;
T_16 V_45 = TRUE ;
if( ( ( V_46 == NULL ) || ( * V_46 == '\0' ) ) && ( V_47 == FALSE ) ) {
return FALSE ;
}
V_32 = F_24 () ;
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
F_4 ( T_12 , L_2 ) ;
return FALSE ;
}
if( ( V_29 == 0 ) || ( V_30 == NULL ) ) {
F_4 ( T_12 , L_3 ) ;
return FALSE ;
}
V_39 = ( char * ) F_25 ( F_3 () , V_37 ) ;
if( ! F_5 ( 1 , V_30 , V_29 , V_46 , V_37 , V_39 ) )
return FALSE ;
if( V_36 ) {
V_40 = ( char * ) F_25 ( F_3 () , V_36 ) ;
if( ! F_5 ( 2 , V_30 , V_29 , V_46 , V_36 , V_40 ) )
return FALSE ;
}
V_24 = F_26 ( & V_33 , V_34 , V_35 , 0 ) ;
if ( F_9 ( V_24 ) )
return FALSE ;
V_24 = F_27 ( V_33 , V_39 , V_37 ) ;
if ( F_9 ( V_24 ) ) {
F_28 ( V_33 ) ;
return FALSE ;
}
if( V_36 ) {
V_24 = F_29 ( V_33 , V_40 , V_36 ) ;
if ( F_9 ( V_24 ) ) {
F_28 ( V_33 ) ;
return FALSE ;
}
}
V_38 = F_6 ( T_8 ) ;
V_41 = ( char * ) F_30 ( V_38 ) ;
V_24 = F_31 ( V_33 , V_41 , V_38 , ( char * ) F_7 ( F_3 () , T_8 , 0 , V_38 ) , V_38 ) ;
if ( F_9 ( V_24 ) ) {
F_4 ( T_12 , L_4 ) ;
F_28 ( V_33 ) ;
F_32 ( V_41 ) ;
return FALSE ;
}
F_28 ( V_33 ) ;
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
F_32 ( V_41 ) ;
F_4 ( T_12 , L_5 ) ;
return FALSE ;
}
F_4 ( T_12 , L_6 ) ;
V_1 = F_33 ( T_12 , V_56 ) ;
V_42 = F_34 ( T_8 , ( const V_57 * ) V_41 , V_38 , V_38 ) ;
F_35 ( V_42 , F_32 ) ;
V_3 = F_36 ( L_7 ) ;
V_43 = F_2 ( F_3 () , T_7 ) ;
F_37 ( V_3 , L_8 , V_43 ? V_43 : T_7 ) ;
F_38 ( T_10 -> V_58 , V_42 , V_3 -> V_59 ) ;
F_39 ( V_3 , TRUE ) ;
F_40 ( T_7 , V_42 , 0 , T_10 -> V_58 , V_1 , NULL ) ;
return TRUE ;
#else
return FALSE ;
#endif
}
static int F_41 ( T_2 * V_60 )
{
T_17 V_61 ;
T_16 V_62 , V_63 ;
T_18 V_64 ;
T_19 V_65 ;
int V_66 = 0 ;
V_66 = F_42 ( V_60 , 0 , & V_61 , & V_62 , & V_64 ) ;
V_66 = F_43 ( V_60 , V_66 , & V_65 , & V_63 ) ;
if( ( V_61 == V_67 ) && ( V_64 == V_68 ) )
return V_66 ;
return 0 ;
}
static int F_44 ( T_2 * V_60 , T_20 * V_58 , T_1 * V_1 , void * T_21 V_31 ) {
int V_66 = 0 ;
T_9 V_69 ;
F_45 ( & V_69 , V_70 , TRUE , V_58 ) ;
if( ( V_66 = F_41 ( V_60 ) ) > 0 )
F_46 ( FALSE , V_60 , V_66 , & V_69 , V_1 , V_71 ) ;
else
F_47 ( V_1 , V_58 , & V_72 , V_60 , 0 , 1 ) ;
return F_6 ( V_60 ) ;
}
static int F_48 ( T_2 * V_60 , T_20 * V_58 , T_1 * V_1 , void * T_21 V_31 )
{
int V_66 = 0 ;
T_9 V_69 ;
F_45 ( & V_69 , V_70 , TRUE , V_58 ) ;
V_66 = F_41 ( V_60 ) ;
F_49 ( FALSE , V_60 , V_66 , & V_69 , V_1 , V_73 ) ;
return F_6 ( V_60 ) ;
}
static int F_50 ( T_2 * V_60 , T_20 * V_58 , T_1 * V_1 , void * T_21 V_31 )
{
int V_66 = 0 ;
T_9 V_69 ;
F_45 ( & V_69 , V_70 , TRUE , V_58 ) ;
if( ( V_66 = F_41 ( V_60 ) ) > 0 )
F_51 ( FALSE , V_60 , V_66 , & V_69 , V_1 , V_74 ) ;
else
F_47 ( V_1 , V_58 , & V_72 , V_60 , 0 , 1 ) ;
return F_6 ( V_60 ) ;
}
void F_52 ( void ) {
static T_22 V_75 [] = {
{ & V_74 ,
{ L_9 , L_10 ,
V_76 , V_77 , NULL , 0 ,
L_10 , V_78 } } ,
{ & V_71 ,
{ L_11 , L_12 ,
V_79 , V_80 , NULL , 0 ,
NULL , V_78 } } ,
#include "packet-pkcs12-hfarr.c"
} ;
static T_23 * V_81 [] = {
& V_56 ,
#include "packet-pkcs12-ettarr.c"
} ;
static T_24 V_82 [] = {
{ & V_72 , { L_13 , V_83 , V_84 , L_14 , V_85 } } ,
} ;
T_25 * V_86 ;
T_26 * V_87 ;
V_88 = F_53 ( V_89 , V_90 , V_91 ) ;
F_54 ( V_88 , V_75 , F_55 ( V_75 ) ) ;
F_56 ( V_81 , F_55 ( V_81 ) ) ;
V_87 = F_57 ( V_88 ) ;
F_58 ( V_87 , V_82 , F_55 ( V_82 ) ) ;
V_86 = F_59 ( V_88 , NULL ) ;
F_60 ( V_86 , L_15 ,
L_16 ,
L_17
L_18 , & V_46 ) ;
F_61 ( V_86 , L_19 ,
L_20 ,
L_21
L_22 , & V_47 ) ;
F_62 ( L_23 , V_88 , V_92 ) ;
F_63 ( L_24 , NULL , L_23 ) ;
F_63 ( L_25 , NULL , L_23 ) ;
}
void F_64 ( void ) {
#include "packet-pkcs12-dis-tab.c"
F_65 ( L_26 , F_50 , V_88 , L_27 ) ;
}
