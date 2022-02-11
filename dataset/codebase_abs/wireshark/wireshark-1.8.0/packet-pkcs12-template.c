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
static int F_40 ( T_2 * V_59 )
{
T_17 V_60 ;
T_16 V_61 , V_62 ;
T_18 V_63 ;
T_19 V_64 ;
int V_65 = 0 ;
V_65 = F_41 ( V_59 , 0 , & V_60 , & V_61 , & V_63 ) ;
V_65 = F_42 ( V_59 , V_65 , & V_64 , & V_62 ) ;
if( ( V_60 == V_66 ) && ( V_63 == V_67 ) )
return V_65 ;
return 0 ;
}
static void F_43 ( T_2 * V_59 , T_20 * V_57 , T_1 * V_1 ) {
int V_65 = 0 ;
T_9 V_68 ;
F_44 ( & V_68 , V_69 , TRUE , V_57 ) ;
if( ( V_65 = F_40 ( V_59 ) ) > 0 )
F_45 ( FALSE , V_59 , V_65 , & V_68 , V_1 , V_70 ) ;
else
F_46 ( V_1 , V_59 , 0 , 1 , L_9 ) ;
}
static void F_47 ( T_2 * V_59 , T_20 * V_57 , T_1 * V_1 )
{
int V_65 = 0 ;
T_9 V_68 ;
F_44 ( & V_68 , V_69 , TRUE , V_57 ) ;
V_65 = F_40 ( V_59 ) ;
F_48 ( FALSE , V_59 , V_65 , & V_68 , V_1 , V_71 ) ;
}
static void F_49 ( T_2 * V_59 , T_20 * V_57 , T_1 * V_1 )
{
int V_65 = 0 ;
T_9 V_68 ;
F_44 ( & V_68 , V_69 , TRUE , V_57 ) ;
if( ( V_65 = F_40 ( V_59 ) ) > 0 )
F_50 ( FALSE , V_59 , V_65 , & V_68 , V_1 , V_72 ) ;
else
F_46 ( V_1 , V_59 , 0 , 1 , L_9 ) ;
}
void F_51 ( void ) {
static T_21 V_73 [] = {
{ & V_72 ,
{ L_10 , L_11 ,
V_74 , V_75 , NULL , 0 ,
L_11 , V_76 } } ,
#include "packet-pkcs12-hfarr.c"
} ;
static T_22 * V_77 [] = {
& V_55 ,
#include "packet-pkcs12-ettarr.c"
} ;
T_23 * V_78 ;
V_79 = F_52 ( V_80 , V_81 , V_82 ) ;
F_53 ( V_79 , V_73 , F_54 ( V_73 ) ) ;
F_55 ( V_77 , F_54 ( V_77 ) ) ;
V_78 = F_56 ( V_79 , NULL ) ;
F_57 ( V_78 , L_12 ,
L_13 ,
L_14
L_15 , & V_45 ) ;
F_58 ( V_78 , L_16 ,
L_17 ,
L_18
L_19 , & V_46 ) ;
F_59 ( L_20 , V_79 , V_83 ) ;
F_60 ( L_21 , NULL , L_20 ) ;
F_60 ( L_22 , NULL , L_20 ) ;
}
void F_61 ( void ) {
#include "packet-pkcs12-dis-tab.c"
F_62 ( L_23 , F_49 , V_79 , L_24 ) ;
}
