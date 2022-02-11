static void F_1 ( int V_1 , T_1 * V_2 )
{
F_2 ( V_1 < V_3 ) ;
F_2 ( V_1 == V_2 -> V_1 ) ;
F_2 ( V_4 [ V_1 ] == NULL ) ;
F_3 ( V_2 -> V_5 ) ;
F_3 ( V_2 -> V_6 ) ;
F_3 ( V_2 -> V_7 ) ;
F_3 ( V_2 -> V_8 ) ;
F_3 ( ( ( V_2 -> V_9 != NULL ) && ( V_2 -> V_10 != NULL ) ) ||
( ( V_2 -> V_9 == NULL ) && ( V_2 -> V_10 == NULL ) ) ) ;
V_4 [ V_1 ] = V_2 ;
}
int F_4 ( const char * V_5 , const char * V_6 ,
T_2 V_11 , T_3 V_12 ,
T_4 V_13 , T_5 V_14 , T_6 V_15 ,
T_7 V_16 , T_8 V_17 )
{
int V_1 ;
F_3 ( V_5 ) ;
F_3 ( V_6 ) ;
F_3 ( V_11 ) ;
F_3 ( V_12 ) ;
F_3 ( ( ( V_16 != NULL ) && ( V_17 != NULL ) ) ||
( ( V_16 == NULL ) && ( V_17 == NULL ) ) ) ;
F_3 ( V_18 < V_19 ) ;
V_1 = V_20 + V_18 ;
V_21 [ V_18 ] . V_1 = V_1 ;
V_21 [ V_18 ] . V_5 = V_5 ;
V_21 [ V_18 ] . V_6 = V_6 ;
V_21 [ V_18 ] . V_7 = V_11 ;
V_21 [ V_18 ] . V_8 = V_12 ;
V_21 [ V_18 ] . V_22 = V_13 ;
V_21 [ V_18 ] . V_23 = V_14 ;
V_21 [ V_18 ] . V_24 = V_15 ;
V_21 [ V_18 ] . V_9 = V_16 ;
V_21 [ V_18 ] . V_10 = V_17 ;
V_4 [ V_1 ] = & V_21 [ V_18 ] ;
V_18 ++ ;
return V_1 ;
}
int F_5 ( const char * V_5 )
{
T_1 * * V_25 ;
for ( V_25 = V_4 ; * V_25 != NULL ; V_25 ++ )
{
if ( ! strcmp ( ( * V_25 ) -> V_5 , V_5 ) )
{
return ( * V_25 ) -> V_1 ;
}
}
return - 1 ;
}
int F_6 ( const T_9 * V_25 V_26 , T_10 * V_27 , int T_11 V_26 )
{
V_27 [ 0 ] = '\0' ;
return F_7 ( V_25 ) ;
}
int F_7 ( const T_9 * V_25 V_26 )
{
return 1 ;
}
int F_8 ( void )
{
return 0 ;
}
static int F_9 ( void )
{
return 5 ;
}
static const T_10 * F_10 ( const T_9 * V_25 V_26 )
{
return L_1 ;
}
int F_11 ( const T_9 * V_25 , T_10 * V_27 , int T_11 V_26 )
{
F_12 ( V_27 , ( const V_28 * ) V_25 -> V_29 , 6 , ':' ) ;
V_27 [ 17 ] = '\0' ;
return F_13 ( V_25 ) ;
}
int F_13 ( const T_9 * V_25 V_26 )
{
return 18 ;
}
static const char * F_14 ( const T_9 * V_25 V_26 , T_12 V_30 )
{
if ( V_30 )
return L_2 ;
return L_3 ;
}
int F_15 ( void )
{
return 6 ;
}
const T_10 * F_16 ( const T_9 * V_25 )
{
return F_17 ( ( const V_28 * ) V_25 -> V_29 ) ;
}
int F_18 ( void )
{
return V_31 ;
}
static int F_19 ( const T_9 * V_25 , T_10 * V_27 , int T_11 )
{
F_20 ( ( const V_28 * ) V_25 -> V_29 , V_27 , T_11 ) ;
return ( int ) ( strlen ( V_27 ) + 1 ) ;
}
static int F_21 ( const T_9 * V_25 V_26 )
{
return V_32 ;
}
static const char * F_22 ( const T_9 * V_25 V_26 , T_12 V_30 )
{
if ( V_30 )
return L_4 ;
return L_5 ;
}
static int F_23 ( void )
{
return 4 ;
}
static const T_10 * F_24 ( const T_9 * V_25 )
{
T_13 V_33 ;
memcpy ( & V_33 , V_25 -> V_29 , sizeof V_33 ) ;
return F_25 ( V_33 ) ;
}
static int F_26 ( void )
{
return V_31 ;
}
static int F_27 ( const T_9 * V_25 , T_10 * V_27 , int T_11 )
{
F_28 ( ( const struct V_34 * ) V_25 -> V_29 , V_27 , T_11 ) ;
return ( int ) ( strlen ( V_27 ) + 1 ) ;
}
static int F_29 ( const T_9 * V_25 V_26 )
{
return V_35 ;
}
static const char * F_30 ( const T_9 * V_25 V_26 , T_12 V_30 )
{
if ( V_30 )
return L_6 ;
return L_7 ;
}
static int F_31 ( void )
{
return 16 ;
}
static const T_10 * F_32 ( const T_9 * V_25 )
{
struct V_34 V_36 ;
memcpy ( & V_36 . V_37 , V_25 -> V_29 , sizeof V_36 . V_37 ) ;
return F_33 ( & V_36 ) ;
}
static int F_34 ( void )
{
return V_31 ;
}
static int F_35 ( const T_9 * V_25 , T_10 * V_27 , int T_11 V_26 )
{
const V_28 * V_38 = ( const V_28 * ) V_25 -> V_29 ;
T_10 * V_39 = V_27 ;
V_39 = F_36 ( V_39 , & V_38 [ 0 ] , 4 ) ;
* V_39 ++ = '.' ;
V_39 = F_36 ( V_39 , & V_38 [ 4 ] , 6 ) ;
* V_39 ++ = '\0' ;
return ( int ) ( V_39 - V_27 ) ;
}
static int F_37 ( const T_9 * V_25 V_26 )
{
return 22 ;
}
static int F_38 ( void )
{
return 10 ;
}
static int F_39 ( const T_9 * V_25 , T_10 * V_27 , int T_11 V_26 )
{
T_10 * V_39 = V_27 ;
V_39 = F_12 ( V_39 , ( const V_28 * ) V_25 -> V_29 , 3 , '.' ) ;
* V_39 ++ = '\0' ;
return ( int ) ( V_39 - V_27 ) ;
}
static int F_40 ( const T_9 * V_25 V_26 )
{
return 9 ;
}
static int F_41 ( void )
{
return 3 ;
}
static int F_42 ( const T_9 * V_25 V_26 )
{
return 24 ;
}
static int F_43 ( const T_9 * V_25 , T_10 * V_27 , int T_11 V_26 )
{
const V_28 * V_40 = ( const V_28 * ) V_25 -> V_29 ;
V_27 = F_12 ( V_27 , V_40 , 8 , ':' ) ;
* V_27 = '\0' ;
return F_42 ( V_25 ) ;
}
static int F_44 ( void )
{
return V_41 ;
}
static const T_10 * F_45 ( const T_9 * V_25 )
{
const V_28 * V_40 = ( const V_28 * ) V_25 -> V_29 ;
int V_42 ;
V_28 V_43 [ 6 ] ;
V_42 = ( V_40 [ 0 ] & 0xF0 ) >> 4 ;
switch ( V_42 ) {
case V_44 :
case V_45 :
memcpy ( V_43 , & V_40 [ 2 ] , 6 ) ;
return F_46 ( V_43 ) ;
case V_46 :
V_43 [ 0 ] = ( ( V_40 [ 0 ] & 0x0F ) << 4 ) | ( ( V_40 [ 1 ] & 0xF0 ) >> 4 ) ;
V_43 [ 1 ] = ( ( V_40 [ 1 ] & 0x0F ) << 4 ) | ( ( V_40 [ 2 ] & 0xF0 ) >> 4 ) ;
V_43 [ 2 ] = ( ( V_40 [ 2 ] & 0x0F ) << 4 ) | ( ( V_40 [ 3 ] & 0xF0 ) >> 4 ) ;
V_43 [ 3 ] = ( ( V_40 [ 3 ] & 0x0F ) << 4 ) | ( ( V_40 [ 4 ] & 0xF0 ) >> 4 ) ;
V_43 [ 4 ] = ( ( V_40 [ 4 ] & 0x0F ) << 4 ) | ( ( V_40 [ 5 ] & 0xF0 ) >> 4 ) ;
V_43 [ 5 ] = ( ( V_40 [ 5 ] & 0x0F ) << 4 ) | ( ( V_40 [ 6 ] & 0xF0 ) >> 4 ) ;
return F_46 ( V_43 ) ;
}
return L_8 ;
}
static int F_47 ( void )
{
return V_31 ;
}
static int F_48 ( const T_9 * V_25 , T_10 * V_27 , int T_11 )
{
F_49 ( V_27 , ( const T_10 * ) V_25 -> V_29 , T_11 ) ;
return ( int ) ( strlen ( V_27 ) + 1 ) ;
}
static int F_50 ( const T_9 * V_25 )
{
return V_25 -> V_47 + 1 ;
}
static int F_51 ( const T_9 * V_25 , T_10 * V_27 , int T_11 V_26 )
{
V_27 = F_12 ( V_27 , ( const V_28 * ) V_25 -> V_29 , 8 , ':' ) ;
* V_27 = '\0' ;
return sizeof( V_27 ) + 1 ;
}
static int F_52 ( const T_9 * V_25 V_26 )
{
return V_48 ;
}
static int F_53 ( void )
{
return 8 ;
}
static int
F_54 ( const T_9 * V_25 , T_10 * V_27 , int T_11 ) {
if ( V_25 -> V_47 >= 16 ) {
#define F_55 ((int)(sizeof("GID: ") - 1))
F_49 ( V_27 , L_9 , T_11 ) ;
if ( T_11 < F_55 ||
F_56 ( V_25 -> V_29 , V_27 + F_55 ,
T_11 - F_55 ) == NULL )
F_49 ( V_27 , V_49 , T_11 ) ;
} else {
T_14 V_50 ;
memcpy ( ( void * ) & V_50 , V_25 -> V_29 , sizeof V_50 ) ;
F_57 ( V_27 , T_11 , L_10 , V_50 ) ;
}
return sizeof( V_27 ) + 1 ;
}
static int F_58 ( const T_9 * V_25 V_26 )
{
return V_31 ;
}
static int F_59 ( const T_9 * V_25 , T_10 * V_27 , int T_11 V_26 )
{
const V_28 * V_38 = ( const V_28 * ) V_25 -> V_29 ;
T_10 * V_39 = V_27 ;
* V_39 ++ = F_60 ( V_38 [ 0 ] >> 1 ) ;
* V_39 ++ = F_60 ( V_38 [ 1 ] >> 1 ) ;
* V_39 ++ = F_60 ( V_38 [ 2 ] >> 1 ) ;
* V_39 ++ = F_60 ( V_38 [ 3 ] >> 1 ) ;
* V_39 ++ = F_60 ( V_38 [ 4 ] >> 1 ) ;
* V_39 ++ = F_60 ( V_38 [ 5 ] >> 1 ) ;
* V_39 ++ = '-' ;
V_39 = F_61 ( V_39 , ( V_38 [ 6 ] >> 1 ) & 0x0f ) ;
* V_39 ++ = '\0' ;
return ( int ) ( V_39 - V_27 ) ;
}
static int F_62 ( const T_9 * V_25 V_26 )
{
return 21 ;
}
static const char * F_63 ( const T_9 * V_25 V_26 , T_12 V_30 )
{
if ( V_30 )
return L_11 ;
return L_12 ;
}
static int F_64 ( void )
{
return V_51 ;
}
void F_65 ( void )
{
static T_1 V_52 = {
V_53 ,
L_13 ,
L_14 ,
F_6 ,
F_7 ,
NULL ,
NULL ,
F_8 ,
F_10 ,
F_9 ,
} ;
static T_1 V_54 = {
V_55 ,
L_15 ,
L_16 ,
F_11 ,
F_13 ,
NULL ,
F_14 ,
F_15 ,
F_16 ,
F_18 ,
} ;
static T_1 V_56 = {
V_57 ,
L_17 ,
L_18 ,
F_19 ,
F_21 ,
NULL ,
F_22 ,
F_23 ,
F_24 ,
F_26 ,
} ;
static T_1 V_58 = {
V_59 ,
L_19 ,
L_20 ,
F_27 ,
F_29 ,
NULL ,
F_30 ,
F_31 ,
F_32 ,
F_34 ,
} ;
static T_1 V_60 = {
V_61 ,
L_21 ,
L_22 ,
F_35 ,
F_37 ,
NULL ,
NULL ,
F_38 ,
NULL ,
NULL ,
} ;
static T_1 V_62 = {
V_63 ,
L_23 ,
L_24 ,
F_39 ,
F_40 ,
NULL ,
NULL ,
F_41 ,
NULL ,
NULL ,
} ;
static T_1 V_64 = {
V_65 ,
L_25 ,
L_26 ,
F_43 ,
F_42 ,
NULL ,
NULL ,
F_44 ,
F_45 ,
F_47 ,
} ;
static T_1 V_66 = {
V_67 ,
L_27 ,
L_28 ,
F_48 ,
F_50 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_1 V_68 = {
V_69 ,
L_29 ,
L_30 ,
F_51 ,
F_52 ,
NULL ,
NULL ,
F_53 ,
NULL ,
NULL ,
} ;
static T_1 V_70 = {
V_71 ,
L_31 ,
L_32 ,
F_54 ,
F_58 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_1 V_72 = {
V_73 ,
L_33 ,
L_34 ,
F_59 ,
F_62 ,
NULL ,
F_63 ,
F_64 ,
NULL ,
NULL ,
} ;
V_18 = 0 ;
memset ( V_4 , 0 , ( V_3 + 1 ) * sizeof( T_1 * ) ) ;
F_1 ( V_53 , & V_52 ) ;
F_1 ( V_55 , & V_54 ) ;
F_1 ( V_57 , & V_56 ) ;
F_1 ( V_59 , & V_58 ) ;
F_1 ( V_61 , & V_60 ) ;
F_1 ( V_63 , & V_62 ) ;
F_1 ( V_65 , & V_64 ) ;
F_1 ( V_67 , & V_66 ) ;
F_1 ( V_69 , & V_68 ) ;
F_1 ( V_71 , & V_70 ) ;
F_1 ( V_73 , & V_72 ) ;
}
static int F_66 ( const T_9 * V_25 )
{
T_1 * V_2 ;
F_67 ( V_25 -> type , V_2 ) ;
if ( V_2 == NULL )
return 0 ;
return V_2 -> V_8 ( V_25 ) ;
}
T_10 *
F_68 ( T_15 * V_74 , const T_9 * V_25 )
{
T_10 * V_75 ;
int V_47 = F_66 ( V_25 ) ;
if ( V_47 <= 0 )
V_47 = V_31 ;
V_75 = ( T_10 * ) F_69 ( V_74 , V_47 ) ;
F_70 ( V_25 , V_75 , V_47 ) ;
return V_75 ;
}
void F_70 ( const T_9 * V_25 , T_10 * V_27 , int T_11 )
{
T_1 * V_2 ;
if ( ! V_27 || ! T_11 )
return;
F_67 ( V_25 -> type , V_2 ) ;
if ( ( V_2 == NULL ) || ( V_2 -> V_7 == NULL ) )
{
V_27 [ 0 ] = '\0' ;
return;
}
V_2 -> V_7 ( V_25 , V_27 , T_11 ) ;
}
T_16 F_71 ( const T_9 * V_25 , V_28 * V_27 , T_16 T_11 )
{
T_1 * V_2 ;
T_16 V_76 = 0 ;
if ( ! V_27 || ! T_11 )
return 0 ;
F_67 ( V_25 -> type , V_2 ) ;
if ( V_2 == NULL )
return 0 ;
if ( V_2 -> V_22 == NULL )
{
V_76 = F_72 ( ( ( T_16 ) V_25 -> V_47 ) , T_11 ) ;
memcpy ( V_27 , V_25 -> V_29 , V_76 ) ;
}
else
{
V_76 = V_2 -> V_22 ( V_25 , V_27 , T_11 ) ;
}
return V_76 ;
}
const T_10 *
F_73 ( const T_9 * V_25 )
{
T_1 * V_2 ;
F_67 ( V_25 -> type , V_2 ) ;
if ( V_2 == NULL )
{
return NULL ;
}
switch ( V_25 -> type ) {
case V_67 :
return ( const T_10 * ) V_25 -> V_29 ;
default:
if ( V_2 -> V_9 != NULL )
return V_2 -> V_9 ( V_25 ) ;
else
return NULL ;
}
}
T_10 *
F_74 ( T_15 * V_77 , const T_9 * V_25 )
{
T_10 * V_75 = NULL ;
const T_10 * V_78 = F_73 ( V_25 ) ;
if ( V_78 != NULL ) {
V_75 = F_75 ( V_77 , V_78 ) ;
}
else if ( V_25 -> type == V_53 ) {
V_75 = F_75 ( V_77 , L_1 ) ;
}
else {
V_75 = ( T_10 * ) F_69 ( V_77 , V_31 ) ;
F_70 ( V_25 , V_75 , V_31 ) ;
}
return V_75 ;
}
static void F_76 ( const T_9 * V_25 , T_10 * V_27 , int T_11 )
{
T_1 * V_2 ;
int V_79 ;
T_17 V_80 ;
T_12 V_81 ;
if ( ! V_27 || ! T_11 )
return;
F_67 ( V_25 -> type , V_2 ) ;
if ( V_2 == NULL )
{
V_27 [ 0 ] = '\0' ;
return;
}
#if 0
if (at->addr_name_res_str == NULL)
return address_to_str_buf(addr, buf, buf_len);
#endif
V_80 = F_49 ( V_27 , V_2 -> V_9 ( V_25 ) , T_11 ) ;
if ( V_25 -> type == V_53 )
return;
if ( ( int ) ( V_80 + 4 + V_2 -> V_8 ( V_25 ) ) >= T_11 )
return;
V_81 = ( V_80 <= 1 ) ? TRUE : FALSE ;
if ( ! V_81 )
{
V_27 [ V_80 ++ ] = ' ' ;
V_27 [ V_80 ++ ] = '(' ;
}
V_79 = V_2 -> V_7 ( V_25 , & V_27 [ V_80 ] , ( int ) ( T_11 - V_80 ) ) ;
V_80 += V_79 - 1 ;
if ( ! V_81 )
{
V_27 [ V_80 ++ ] = ')' ;
V_27 [ V_80 ++ ] = '\0' ;
}
}
T_10 * F_77 ( T_15 * V_74 , const T_9 * V_25 )
{
T_1 * V_2 ;
int V_47 ;
T_10 * V_75 ;
F_67 ( V_25 -> type , V_2 ) ;
if ( V_2 == NULL )
return F_75 ( V_74 , L_8 ) ;
if ( ( V_2 -> V_9 == NULL ) ||
( F_78 ( V_25 ) && ! V_82 . V_83 ) ||
( F_79 ( V_25 ) && ! V_82 . V_84 ) ) {
return F_68 ( V_74 , V_25 ) ;
}
V_47 = V_2 -> V_10 () + V_2 -> V_8 ( V_25 ) + 4 ;
V_75 = ( T_10 * ) F_69 ( V_74 , V_47 ) ;
F_76 ( V_25 , V_75 , V_47 ) ;
return V_75 ;
}
const char * F_80 ( const T_9 * V_25 , T_12 V_85 )
{
T_1 * V_2 ;
F_67 ( V_25 -> type , V_2 ) ;
if ( ( V_2 == NULL ) || ( V_2 -> V_23 == NULL ) )
{
return L_8 ;
}
return V_2 -> V_23 ( V_25 , V_85 ) ;
}
T_10 *
F_81 ( T_15 * V_74 , T_18 * V_86 , int type , const T_19 V_87 )
{
T_9 V_25 ;
T_1 * V_2 ;
F_67 ( type , V_2 ) ;
if ( V_2 == NULL )
{
return NULL ;
}
if ( V_2 -> V_24 == NULL )
{
F_82 () ;
return NULL ;
}
F_83 ( & V_25 , type , V_2 -> V_24 () , V_86 , V_87 ) ;
return F_68 ( V_74 , & V_25 ) ;
}
T_10 * F_84 ( T_15 * V_74 , T_18 * V_86 , T_20 type , const T_19 V_87 , int V_88 )
{
T_9 V_25 ;
F_83 ( & V_25 , type , V_88 , V_86 , V_87 ) ;
return F_68 ( V_74 , & V_25 ) ;
}
T_10 *
F_85 ( T_15 * V_74 , T_18 * V_86 , int type , const T_19 V_87 )
{
T_9 V_25 ;
T_1 * V_2 ;
F_67 ( type , V_2 ) ;
if ( V_2 == NULL )
{
return NULL ;
}
if ( V_2 -> V_24 == NULL )
{
F_82 () ;
return NULL ;
}
F_83 ( & V_25 , type , V_2 -> V_24 () , V_86 , V_87 ) ;
return F_77 ( V_74 , & V_25 ) ;
}
