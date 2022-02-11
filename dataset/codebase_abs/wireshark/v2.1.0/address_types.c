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
T_4 V_13 , T_5 V_14 ,
T_6 V_15 , T_7 V_16 )
{
int V_1 ;
F_3 ( V_5 ) ;
F_3 ( V_6 ) ;
F_3 ( V_11 ) ;
F_3 ( V_12 ) ;
F_3 ( ( ( V_15 != NULL ) && ( V_16 != NULL ) ) ||
( ( V_15 == NULL ) && ( V_16 == NULL ) ) ) ;
F_3 ( V_17 < V_18 ) ;
V_1 = V_19 + V_17 ;
V_20 [ V_17 ] . V_1 = V_1 ;
V_20 [ V_17 ] . V_5 = V_5 ;
V_20 [ V_17 ] . V_6 = V_6 ;
V_20 [ V_17 ] . V_7 = V_11 ;
V_20 [ V_17 ] . V_8 = V_12 ;
V_20 [ V_17 ] . V_21 = V_13 ;
V_20 [ V_17 ] . V_22 = V_14 ;
V_20 [ V_17 ] . V_9 = V_15 ;
V_20 [ V_17 ] . V_10 = V_16 ;
V_4 [ V_1 ] = & V_20 [ V_17 ] ;
V_17 ++ ;
return V_1 ;
}
int F_5 ( const T_8 * T_9 V_23 , T_10 * V_24 , int T_11 V_23 )
{
V_24 [ 0 ] = '\0' ;
return F_6 ( T_9 ) ;
}
int F_6 ( const T_8 * T_9 V_23 )
{
return 1 ;
}
int F_7 ( void )
{
return 0 ;
}
static int F_8 ( void )
{
return 5 ;
}
static const T_10 * F_9 ( const T_8 * T_9 V_23 )
{
return L_1 ;
}
int F_10 ( const T_8 * T_9 , T_10 * V_24 , int T_11 V_23 )
{
F_11 ( V_24 , ( const V_25 * ) T_9 -> V_26 , 6 , ':' ) ;
V_24 [ 17 ] = '\0' ;
return F_12 ( T_9 ) ;
}
int F_12 ( const T_8 * T_9 V_23 )
{
return 18 ;
}
static const char * F_13 ( const T_8 * T_9 V_23 , T_12 V_27 )
{
if ( V_27 )
return L_2 ;
return L_3 ;
}
int F_14 ( void )
{
return 6 ;
}
const T_10 * F_15 ( const T_8 * T_9 )
{
return F_16 ( ( const V_25 * ) T_9 -> V_26 ) ;
}
int F_17 ( void )
{
return V_28 ;
}
static int F_18 ( const T_8 * T_9 , T_10 * V_24 , int T_11 )
{
F_19 ( ( const V_25 * ) T_9 -> V_26 , V_24 , T_11 ) ;
return ( int ) ( strlen ( V_24 ) + 1 ) ;
}
static int F_20 ( const T_8 * T_9 V_23 )
{
return V_29 ;
}
static const char * F_21 ( const T_8 * T_9 V_23 , T_12 V_27 )
{
if ( V_27 )
return L_4 ;
return L_5 ;
}
static int F_22 ( void )
{
return 4 ;
}
static const T_10 * F_23 ( const T_8 * T_9 )
{
T_13 V_30 ;
memcpy ( & V_30 , T_9 -> V_26 , sizeof V_30 ) ;
return F_24 ( V_30 ) ;
}
static int F_25 ( void )
{
return V_28 ;
}
static int F_26 ( const T_8 * T_9 , T_10 * V_24 , int T_11 )
{
F_27 ( ( const struct V_31 * ) T_9 -> V_26 , V_24 , T_11 ) ;
return ( int ) ( strlen ( V_24 ) + 1 ) ;
}
static int F_28 ( const T_8 * T_9 V_23 )
{
return V_32 ;
}
static const char * F_29 ( const T_8 * T_9 V_23 , T_12 V_27 )
{
if ( V_27 )
return L_6 ;
return L_7 ;
}
static int F_30 ( void )
{
return 16 ;
}
static const T_10 * F_31 ( const T_8 * T_9 )
{
struct V_31 V_33 ;
memcpy ( & V_33 . V_34 , T_9 -> V_26 , sizeof V_33 . V_34 ) ;
return F_32 ( & V_33 ) ;
}
static int F_33 ( void )
{
return V_28 ;
}
static int F_34 ( const T_8 * T_9 , T_10 * V_24 , int T_11 V_23 )
{
const V_25 * V_35 = ( const V_25 * ) T_9 -> V_26 ;
T_10 * V_36 = V_24 ;
V_36 = F_35 ( V_36 , & V_35 [ 0 ] , 4 ) ;
* V_36 ++ = '.' ;
V_36 = F_35 ( V_36 , & V_35 [ 4 ] , 6 ) ;
* V_36 ++ = '\0' ;
return ( int ) ( V_36 - V_24 ) ;
}
static int F_36 ( const T_8 * T_9 V_23 )
{
return 22 ;
}
static int F_37 ( void )
{
return 10 ;
}
static int F_38 ( const T_8 * T_9 , T_10 * V_24 , int T_11 V_23 )
{
const V_25 * V_37 = ( const V_25 * ) T_9 -> V_26 ;
T_10 * V_36 = V_24 ;
V_36 = F_39 ( V_36 , F_40 ( & V_37 [ 0 ] ) ) ;
* V_36 ++ = '.' ;
V_36 = F_41 ( V_36 , F_42 ( & V_37 [ 4 ] ) ) ;
* V_36 ++ = '\0' ;
return ( int ) ( V_36 - V_24 ) ;
}
static int F_43 ( const T_8 * T_9 V_23 )
{
return 14 ;
}
static int F_44 ( void )
{
return V_38 ;
}
static int F_45 ( const T_8 * T_9 , T_10 * V_24 , int T_11 V_23 )
{
T_10 * V_36 = V_24 ;
V_36 = F_11 ( V_36 , ( const V_25 * ) T_9 -> V_26 , 3 , '.' ) ;
* V_36 ++ = '\0' ;
return ( int ) ( V_36 - V_24 ) ;
}
static int F_46 ( const T_8 * T_9 V_23 )
{
return 9 ;
}
static int F_47 ( void )
{
return 3 ;
}
static int F_48 ( const T_8 * T_9 V_23 )
{
return 24 ;
}
static int F_49 ( const T_8 * T_9 , T_10 * V_24 , int T_11 V_23 )
{
const V_25 * V_39 = ( const V_25 * ) T_9 -> V_26 ;
V_24 = F_11 ( V_24 , V_39 , 8 , ':' ) ;
* V_24 = '\0' ;
return F_48 ( T_9 ) ;
}
static int F_50 ( void )
{
return V_40 ;
}
static const T_10 * F_51 ( const T_8 * T_9 )
{
const V_25 * V_39 = ( const V_25 * ) T_9 -> V_26 ;
int V_41 ;
V_25 V_42 [ 6 ] ;
V_41 = ( V_39 [ 0 ] & 0xF0 ) >> 4 ;
switch ( V_41 ) {
case V_43 :
case V_44 :
memcpy ( V_42 , & V_39 [ 2 ] , 6 ) ;
return F_52 ( V_42 ) ;
case V_45 :
V_42 [ 0 ] = ( ( V_39 [ 0 ] & 0x0F ) << 4 ) | ( ( V_39 [ 1 ] & 0xF0 ) >> 4 ) ;
V_42 [ 1 ] = ( ( V_39 [ 1 ] & 0x0F ) << 4 ) | ( ( V_39 [ 2 ] & 0xF0 ) >> 4 ) ;
V_42 [ 2 ] = ( ( V_39 [ 2 ] & 0x0F ) << 4 ) | ( ( V_39 [ 3 ] & 0xF0 ) >> 4 ) ;
V_42 [ 3 ] = ( ( V_39 [ 3 ] & 0x0F ) << 4 ) | ( ( V_39 [ 4 ] & 0xF0 ) >> 4 ) ;
V_42 [ 4 ] = ( ( V_39 [ 4 ] & 0x0F ) << 4 ) | ( ( V_39 [ 5 ] & 0xF0 ) >> 4 ) ;
V_42 [ 5 ] = ( ( V_39 [ 5 ] & 0x0F ) << 4 ) | ( ( V_39 [ 6 ] & 0xF0 ) >> 4 ) ;
return F_52 ( V_42 ) ;
}
return L_8 ;
}
static int F_53 ( void )
{
return V_28 ;
}
static int F_54 ( const T_8 * T_9 , T_10 * V_24 , int T_11 )
{
F_55 ( ( const V_46 * ) T_9 -> V_26 , V_24 , T_11 ) ;
return ( int ) ( strlen ( V_24 ) + 1 ) ;
}
static int F_56 ( const T_8 * T_9 V_23 )
{
return 50 ;
}
static int F_57 ( const T_8 * T_9 , T_10 * V_24 , int T_11 )
{
F_58 ( V_24 , ( const T_10 * ) T_9 -> V_26 , T_11 ) ;
return ( int ) ( strlen ( V_24 ) + 1 ) ;
}
static int F_59 ( const T_8 * T_9 )
{
return T_9 -> V_47 + 1 ;
}
static int F_60 ( const T_8 * T_9 , T_10 * V_24 , int T_11 V_23 )
{
V_24 = F_11 ( V_24 , ( const V_25 * ) T_9 -> V_26 , 8 , ':' ) ;
* V_24 = '\0' ;
return sizeof( V_24 ) + 1 ;
}
static int F_61 ( const T_8 * T_9 V_23 )
{
return V_48 ;
}
static int F_62 ( void )
{
return 8 ;
}
static int
F_63 ( const T_8 * T_9 , T_10 * V_24 , int T_11 ) {
if ( T_9 -> V_47 >= 16 ) {
#define F_64 ((int)(sizeof("GID: ") - 1))
F_58 ( V_24 , L_9 , T_11 ) ;
if ( T_11 < F_64 ||
F_65 ( T_9 -> V_26 , V_24 + F_64 ,
T_11 - F_64 ) == NULL )
F_58 ( V_24 , V_49 , T_11 ) ;
} else {
T_14 V_50 ;
memcpy ( ( void * ) & V_50 , T_9 -> V_26 , sizeof V_50 ) ;
F_66 ( V_24 , T_11 , L_10 , V_50 ) ;
}
return sizeof( V_24 ) + 1 ;
}
static int F_67 ( const T_8 * T_9 V_23 )
{
return V_28 ;
}
static int F_68 ( const T_8 * T_9 , T_10 * V_24 , int T_11 V_23 )
{
const V_25 * V_39 = ( const V_25 * ) T_9 -> V_26 ;
if( F_69 ( & V_39 [ 0 ] ) == 0xffffffff ) {
F_58 ( V_24 , L_11 , T_11 ) ;
} else {
F_66 ( V_24 , T_11 , L_12 , F_70 ( & V_39 [ 8 ] ) ,
F_69 ( & V_39 [ 0 ] ) , F_69 ( & V_39 [ 4 ] ) ) ;
}
return ( int ) ( strlen ( V_24 ) + 1 ) ;
}
static int F_71 ( const T_8 * T_9 V_23 )
{
return 50 ;
}
static int F_72 ( const T_8 * T_9 , T_10 * V_24 , int T_11 V_23 )
{
const V_25 * V_35 = ( const V_25 * ) T_9 -> V_26 ;
T_10 * V_36 = V_24 ;
* V_36 ++ = F_73 ( V_35 [ 0 ] >> 1 ) ;
* V_36 ++ = F_73 ( V_35 [ 1 ] >> 1 ) ;
* V_36 ++ = F_73 ( V_35 [ 2 ] >> 1 ) ;
* V_36 ++ = F_73 ( V_35 [ 3 ] >> 1 ) ;
* V_36 ++ = F_73 ( V_35 [ 4 ] >> 1 ) ;
* V_36 ++ = F_73 ( V_35 [ 5 ] >> 1 ) ;
* V_36 ++ = '-' ;
V_36 = F_74 ( V_36 , ( V_35 [ 6 ] >> 1 ) & 0x0f ) ;
* V_36 ++ = '\0' ;
return ( int ) ( V_36 - V_24 ) ;
}
static int F_75 ( const T_8 * T_9 V_23 )
{
return 21 ;
}
static const char * F_76 ( const T_8 * T_9 V_23 , T_12 V_27 )
{
if ( V_27 )
return L_13 ;
return L_14 ;
}
static int F_77 ( void )
{
return V_51 ;
}
void F_78 ( void )
{
static T_1 V_52 = {
V_53 ,
L_15 ,
L_16 ,
F_5 ,
F_6 ,
NULL ,
F_7 ,
F_9 ,
F_8 ,
} ;
static T_1 V_54 = {
V_55 ,
L_17 ,
L_18 ,
F_10 ,
F_12 ,
F_13 ,
F_14 ,
F_15 ,
F_17 ,
} ;
static T_1 V_56 = {
V_57 ,
L_19 ,
L_20 ,
F_18 ,
F_20 ,
F_21 ,
F_22 ,
F_23 ,
F_25 ,
} ;
static T_1 V_58 = {
V_59 ,
L_21 ,
L_22 ,
F_26 ,
F_28 ,
F_29 ,
F_30 ,
F_31 ,
F_33 ,
} ;
static T_1 V_60 = {
V_61 ,
L_23 ,
L_24 ,
F_34 ,
F_36 ,
NULL ,
F_37 ,
NULL ,
NULL ,
} ;
static T_1 V_62 = {
V_63 ,
L_25 ,
L_26 ,
F_38 ,
F_43 ,
NULL ,
F_44 ,
NULL ,
NULL ,
} ;
static T_1 V_64 = {
V_65 ,
L_27 ,
L_28 ,
F_45 ,
F_46 ,
NULL ,
F_47 ,
NULL ,
NULL ,
} ;
static T_1 V_66 = {
V_67 ,
L_29 ,
L_30 ,
F_49 ,
F_48 ,
NULL ,
F_50 ,
F_51 ,
F_53 ,
} ;
static T_1 V_68 = {
V_69 ,
L_31 ,
L_32 ,
F_54 ,
F_56 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_1 V_70 = {
V_71 ,
L_33 ,
L_34 ,
F_57 ,
F_59 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_1 V_72 = {
V_73 ,
L_35 ,
L_36 ,
F_60 ,
F_61 ,
NULL ,
F_62 ,
NULL ,
NULL ,
} ;
static T_1 V_74 = {
V_75 ,
L_37 ,
L_38 ,
F_63 ,
F_67 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_1 V_76 = {
V_77 ,
L_39 ,
L_40 ,
F_68 ,
F_71 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_1 V_78 = {
V_79 ,
L_41 ,
L_42 ,
F_72 ,
F_75 ,
F_76 ,
F_77 ,
NULL ,
NULL ,
} ;
V_17 = 0 ;
memset ( V_4 , 0 , V_3 * sizeof( T_1 * ) ) ;
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
F_1 ( V_75 , & V_74 ) ;
F_1 ( V_77 , & V_76 ) ;
F_1 ( V_79 , & V_78 ) ;
}
static int F_79 ( const T_8 * T_9 )
{
T_1 * V_2 ;
F_80 ( T_9 -> type , V_2 ) ;
if ( V_2 == NULL )
return 0 ;
return V_2 -> V_8 ( T_9 ) ;
}
T_10 *
F_81 ( T_15 * V_80 , const T_8 * T_9 )
{
T_10 * V_81 ;
int V_47 = F_79 ( T_9 ) ;
if ( V_47 <= 0 )
V_47 = V_28 ;
V_81 = ( T_10 * ) F_82 ( V_80 , V_47 ) ;
F_83 ( T_9 , V_81 , V_47 ) ;
return V_81 ;
}
void F_83 ( const T_8 * T_9 , T_10 * V_24 , int T_11 )
{
T_1 * V_2 ;
if ( ! V_24 || ! T_11 )
return;
F_80 ( T_9 -> type , V_2 ) ;
if ( ( V_2 == NULL ) || ( V_2 -> V_7 == NULL ) )
{
V_24 [ 0 ] = '\0' ;
return;
}
V_2 -> V_7 ( T_9 , V_24 , T_11 ) ;
}
const T_10 *
F_84 ( const T_8 * T_9 )
{
T_1 * V_2 ;
F_80 ( T_9 -> type , V_2 ) ;
if ( V_2 == NULL )
{
return NULL ;
}
switch ( T_9 -> type ) {
case V_71 :
return ( const T_10 * ) T_9 -> V_26 ;
default:
if ( V_2 -> V_9 != NULL )
return V_2 -> V_9 ( T_9 ) ;
else
return NULL ;
}
}
T_10 *
F_85 ( T_15 * V_82 , const T_8 * T_9 )
{
T_10 * V_81 = NULL ;
const T_10 * V_83 = F_84 ( T_9 ) ;
if ( V_83 != NULL ) {
V_81 = F_86 ( V_82 , V_83 ) ;
}
else if ( T_9 -> type == V_53 ) {
V_81 = F_86 ( V_82 , L_1 ) ;
}
else {
V_81 = ( T_10 * ) F_82 ( V_82 , V_28 ) ;
F_83 ( T_9 , V_81 , V_28 ) ;
}
return V_81 ;
}
static void F_87 ( const T_8 * T_9 , T_10 * V_24 , int T_11 )
{
T_1 * V_2 ;
int V_84 ;
T_16 V_85 ;
T_12 V_86 ;
if ( ! V_24 || ! T_11 )
return;
F_80 ( T_9 -> type , V_2 ) ;
if ( V_2 == NULL )
{
V_24 [ 0 ] = '\0' ;
return;
}
#if 0
if (at->addr_name_res_str == NULL)
return address_to_str_buf(addr, buf, buf_len);
#endif
V_85 = F_58 ( V_24 , V_2 -> V_9 ( T_9 ) , T_11 ) ;
if ( T_9 -> type == V_53 )
return;
if ( ( int ) ( V_85 + 4 + V_2 -> V_8 ( T_9 ) ) >= T_11 )
return;
V_86 = ( V_85 <= 1 ) ? TRUE : FALSE ;
if ( ! V_86 )
{
V_24 [ V_85 ++ ] = ' ' ;
V_24 [ V_85 ++ ] = '(' ;
}
V_84 = V_2 -> V_7 ( T_9 , & V_24 [ V_85 ] , ( int ) ( T_11 - V_85 ) ) ;
V_85 += V_84 - 1 ;
if ( ! V_86 )
{
V_24 [ V_85 ++ ] = ')' ;
V_24 [ V_85 ++ ] = '\0' ;
}
}
T_10 * F_88 ( T_15 * V_80 , const T_8 * T_9 )
{
T_1 * V_2 ;
int V_47 ;
T_10 * V_81 ;
F_80 ( T_9 -> type , V_2 ) ;
if ( V_2 == NULL )
return F_86 ( V_80 , L_8 ) ;
if ( ( V_2 -> V_9 == NULL ) ||
( F_89 ( T_9 ) && ! V_87 . V_88 ) ||
( F_90 ( T_9 ) && ! V_87 . V_89 ) ) {
return F_81 ( V_80 , T_9 ) ;
}
V_47 = V_2 -> V_10 () + V_2 -> V_8 ( T_9 ) + 4 ;
V_81 = ( T_10 * ) F_82 ( V_80 , V_47 ) ;
F_87 ( T_9 , V_81 , V_47 ) ;
return V_81 ;
}
const char * F_91 ( const T_8 * T_9 , T_12 V_90 )
{
T_1 * V_2 ;
F_80 ( T_9 -> type , V_2 ) ;
if ( ( V_2 == NULL ) || ( V_2 -> V_21 == NULL ) )
{
return L_8 ;
}
return V_2 -> V_21 ( T_9 , V_90 ) ;
}
T_10 *
F_92 ( T_15 * V_80 , T_17 * V_91 , int type , const T_18 V_92 )
{
T_8 T_9 ;
T_1 * V_2 ;
F_80 ( type , V_2 ) ;
if ( V_2 == NULL )
{
return NULL ;
}
if ( V_2 -> V_22 == NULL )
{
F_93 () ;
return NULL ;
}
F_94 ( & T_9 , type , V_2 -> V_22 () , V_91 , V_92 ) ;
return F_81 ( V_80 , & T_9 ) ;
}
T_10 * F_95 ( T_15 * V_80 , T_17 * V_91 , T_19 type , const T_18 V_92 , int V_93 )
{
T_8 T_9 ;
F_94 ( & T_9 , type , V_93 , V_91 , V_92 ) ;
return F_81 ( V_80 , & T_9 ) ;
}
T_10 *
F_96 ( T_15 * V_80 , T_17 * V_91 , int type , const T_18 V_92 )
{
T_8 T_9 ;
T_1 * V_2 ;
F_80 ( type , V_2 ) ;
if ( V_2 == NULL )
{
return NULL ;
}
if ( V_2 -> V_22 == NULL )
{
F_93 () ;
return NULL ;
}
F_94 ( & T_9 , type , V_2 -> V_22 () , V_91 , V_92 ) ;
return F_88 ( V_80 , & T_9 ) ;
}
