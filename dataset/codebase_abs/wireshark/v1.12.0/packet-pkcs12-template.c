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
V_20 = ( char * ) F_6 ( F_7 () , V_5 , 0 , V_21 ) ;
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
int F_22 ( const char * V_31 , T_2 * V_32 , T_7 * V_33 , T_8 * V_34 )
{
#ifdef F_23
const char * V_35 ;
T_9 V_36 ;
T_6 V_24 ;
int V_37 ;
int V_38 ;
int V_39 = 0 ;
int V_40 = 0 ;
int V_41 = 0 ;
char * V_42 = NULL ;
char * V_43 = NULL ;
char * V_44 = NULL ;
T_2 * V_45 = NULL ;
const T_10 * V_46 ;
T_11 * V_3 ;
T_1 * V_1 ;
char V_47 ;
T_12 V_48 = TRUE ;
if( ( ( V_49 == NULL ) || ( * V_49 == '\0' ) ) && ( V_50 == FALSE ) ) {
return FALSE ;
}
V_35 = F_24 () ;
if( ! strcmp ( V_35 , V_51 ) ) {
V_39 = 8 ;
V_40 = 24 ;
V_37 = V_52 ;
V_38 = V_53 ;
} else if( ! strcmp ( V_35 , V_54 ) ) {
V_39 = 0 ;
V_40 = 16 ;
V_37 = V_55 ;
V_38 = V_56 ;
} else if( ! strcmp ( V_35 , V_57 ) ) {
V_39 = 8 ;
V_40 = 5 ;
V_37 = V_58 ;
V_38 = V_53 ;
} else {
F_3 ( V_34 , L_2 ) ;
return FALSE ;
}
if( ( V_29 == 0 ) || ( V_30 == NULL ) ) {
F_3 ( V_34 , L_3 ) ;
return FALSE ;
}
V_42 = ( char * ) F_25 ( F_7 () , V_40 ) ;
if( ! F_4 ( 1 , V_30 , V_29 , V_49 , V_40 , V_42 ) )
return FALSE ;
if( V_39 ) {
V_43 = ( char * ) F_25 ( F_7 () , V_39 ) ;
if( ! F_4 ( 2 , V_30 , V_29 , V_49 , V_39 , V_43 ) )
return FALSE ;
}
V_24 = F_26 ( & V_36 , V_37 , V_38 , 0 ) ;
if ( F_9 ( V_24 ) )
return FALSE ;
V_24 = F_27 ( V_36 , V_42 , V_40 ) ;
if ( F_9 ( V_24 ) ) {
F_28 ( V_36 ) ;
return FALSE ;
}
if( V_39 ) {
V_24 = F_29 ( V_36 , V_43 , V_39 ) ;
if ( F_9 ( V_24 ) ) {
F_28 ( V_36 ) ;
return FALSE ;
}
}
V_41 = F_5 ( V_32 ) ;
V_44 = ( char * ) F_30 ( V_41 ) ;
V_24 = F_31 ( V_36 , V_44 , V_41 , ( char * ) F_6 ( F_7 () , V_32 , 0 , V_41 ) , V_41 ) ;
if ( F_9 ( V_24 ) ) {
F_3 ( V_34 , L_4 ) ;
F_28 ( V_36 ) ;
F_32 ( V_44 ) ;
return FALSE ;
}
F_28 ( V_36 ) ;
V_47 = V_44 [ V_41 - 1 ] ;
if( V_47 <= 0x08 ) {
int V_11 ;
for( V_11 = ( int ) V_47 ; V_11 > 0 ; V_11 -- ) {
if( V_44 [ V_41 - V_11 ] != V_47 ) {
V_48 = FALSE ;
break;
}
}
} else {
}
V_47 = V_44 [ 0 ] ;
if( ( V_47 != 0x30 ) && ( V_47 != 0x31 ) ) {
V_48 = FALSE ;
}
if( ! V_48 ) {
F_32 ( V_44 ) ;
F_3 ( V_34 , L_5 ) ;
return FALSE ;
}
F_3 ( V_34 , L_6 ) ;
V_1 = F_33 ( V_34 , V_59 ) ;
V_45 = F_34 ( V_32 , ( const V_60 * ) V_44 , V_41 , V_41 ) ;
F_35 ( V_45 , F_32 ) ;
V_3 = F_36 ( L_7 ) ;
V_46 = F_2 ( V_31 ) ;
F_37 ( V_3 , L_8 , V_46 ? V_46 : V_31 ) ;
F_38 ( V_33 -> V_61 , V_45 , V_3 -> V_62 ) ;
F_39 ( V_3 , TRUE ) ;
F_40 ( V_31 , V_45 , 0 , V_33 -> V_61 , V_1 , NULL ) ;
return TRUE ;
#else
return FALSE ;
#endif
}
static int F_41 ( T_2 * V_63 )
{
T_13 V_64 ;
T_12 V_65 , V_66 ;
T_14 V_67 ;
T_15 V_68 ;
int V_69 = 0 ;
V_69 = F_42 ( V_63 , 0 , & V_64 , & V_65 , & V_67 ) ;
V_69 = F_43 ( V_63 , V_69 , & V_68 , & V_66 ) ;
if( ( V_64 == V_70 ) && ( V_67 == V_71 ) )
return V_69 ;
return 0 ;
}
static void F_44 ( T_2 * V_63 , T_16 * V_61 , T_1 * V_1 ) {
int V_69 = 0 ;
T_7 V_72 ;
F_45 ( & V_72 , V_73 , TRUE , V_61 ) ;
if( ( V_69 = F_41 ( V_63 ) ) > 0 )
F_46 ( FALSE , V_63 , V_69 , & V_72 , V_1 , V_74 ) ;
else
F_47 ( V_1 , V_63 , 0 , 1 , L_9 ) ;
}
static void F_48 ( T_2 * V_63 , T_16 * V_61 , T_1 * V_1 )
{
int V_69 = 0 ;
T_7 V_72 ;
F_45 ( & V_72 , V_73 , TRUE , V_61 ) ;
V_69 = F_41 ( V_63 ) ;
F_49 ( FALSE , V_63 , V_69 , & V_72 , V_1 , V_75 ) ;
}
static void F_50 ( T_2 * V_63 , T_16 * V_61 , T_1 * V_1 )
{
int V_69 = 0 ;
T_7 V_72 ;
F_45 ( & V_72 , V_73 , TRUE , V_61 ) ;
if( ( V_69 = F_41 ( V_63 ) ) > 0 )
F_51 ( FALSE , V_63 , V_69 , & V_72 , V_1 , V_76 ) ;
else
F_47 ( V_1 , V_63 , 0 , 1 , L_9 ) ;
}
void F_52 ( void ) {
static T_17 V_77 [] = {
{ & V_76 ,
{ L_10 , L_11 ,
V_78 , V_79 , NULL , 0 ,
L_11 , V_80 } } ,
#include "packet-pkcs12-hfarr.c"
} ;
static T_18 * V_81 [] = {
& V_59 ,
#include "packet-pkcs12-ettarr.c"
} ;
T_19 * V_82 ;
V_83 = F_53 ( V_84 , V_85 , V_86 ) ;
F_54 ( V_83 , V_77 , F_55 ( V_77 ) ) ;
F_56 ( V_81 , F_55 ( V_81 ) ) ;
V_82 = F_57 ( V_83 , NULL ) ;
F_58 ( V_82 , L_12 ,
L_13 ,
L_14
L_15 , & V_49 ) ;
F_59 ( V_82 , L_16 ,
L_17 ,
L_18
L_19 , & V_50 ) ;
F_60 ( L_20 , V_83 , V_87 ) ;
F_61 ( L_21 , NULL , L_20 ) ;
F_61 ( L_22 , NULL , L_20 ) ;
}
void F_62 ( void ) {
#include "packet-pkcs12-dis-tab.c"
F_63 ( L_23 , F_50 , V_83 , L_24 ) ;
}
