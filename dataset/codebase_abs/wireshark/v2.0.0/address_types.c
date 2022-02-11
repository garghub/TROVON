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
static void
F_26 ( const T_14 * V_31 , char * V_24 , int T_11 )
{
struct { int V_32 , V_33 ; } V_34 , V_35 ;
T_15 V_36 [ 8 ] ;
int V_37 ;
if ( T_11 < V_38 ) {
F_27 ( V_24 , V_39 , T_11 ) ;
return;
}
for ( V_37 = 0 ; V_37 < 16 ; V_37 += 2 ) {
V_36 [ V_37 / 2 ] = ( V_31 [ V_37 + 1 ] << 0 ) ;
V_36 [ V_37 / 2 ] |= ( V_31 [ V_37 ] << 8 ) ;
}
V_34 . V_32 = - 1 ; V_34 . V_33 = 0 ;
V_35 . V_32 = - 1 ; V_35 . V_33 = 0 ;
for ( V_37 = 0 ; V_37 < 8 ; V_37 ++ ) {
if ( V_36 [ V_37 ] == 0 ) {
if ( V_35 . V_32 == - 1 ) {
V_35 . V_32 = V_37 ;
V_35 . V_33 = 1 ;
} else
V_35 . V_33 ++ ;
} else {
if ( V_35 . V_32 != - 1 ) {
if ( V_34 . V_32 == - 1 || V_35 . V_33 > V_34 . V_33 )
V_34 = V_35 ;
V_35 . V_32 = - 1 ;
}
}
}
if ( V_35 . V_32 != - 1 ) {
if ( V_34 . V_32 == - 1 || V_35 . V_33 > V_34 . V_33 )
V_34 = V_35 ;
}
if ( V_34 . V_32 != - 1 && V_34 . V_33 < 2 )
V_34 . V_32 = - 1 ;
if ( V_34 . V_32 == 0 && ( V_34 . V_33 == 6 || ( V_34 . V_33 == 5 && V_36 [ 5 ] == 0xffff ) ) )
{
V_24 = F_28 ( V_24 , L_6 ) ;
if ( V_34 . V_33 == 5 )
V_24 = F_28 ( V_24 , L_7 ) ;
F_19 ( V_31 + 12 , V_24 , V_29 ) ;
return;
}
for ( V_37 = 0 ; V_37 < 8 ; V_37 ++ ) {
if ( V_37 == V_34 . V_32 ) {
* V_24 ++ = ':' ;
V_37 += V_34 . V_33 ;
if ( V_37 == 8 ) {
* V_24 ++ = ':' ;
break;
}
}
if ( V_37 != 0 )
* V_24 ++ = ':' ;
V_24 = F_29 ( V_24 , V_36 [ V_37 ] ) ;
}
* V_24 = '\0' ;
}
void
F_30 ( const struct V_40 * V_41 , T_10 * V_24 )
{
F_26 ( ( const T_14 * ) V_41 , V_24 , V_38 ) ;
}
static int F_31 ( const T_8 * T_9 , T_10 * V_24 , int T_11 )
{
F_26 ( ( const T_14 * ) T_9 -> V_26 , V_24 , T_11 ) ;
return ( int ) ( strlen ( V_24 ) + 1 ) ;
}
static int F_32 ( const T_8 * T_9 V_23 )
{
return V_38 ;
}
static const char * F_33 ( const T_8 * T_9 V_23 , T_12 V_27 )
{
if ( V_27 )
return L_8 ;
return L_9 ;
}
static int F_34 ( void )
{
return 16 ;
}
static const T_10 * F_35 ( const T_8 * T_9 )
{
struct V_40 V_42 ;
memcpy ( & V_42 . V_43 , T_9 -> V_26 , sizeof V_42 . V_43 ) ;
return F_36 ( & V_42 ) ;
}
static int F_37 ( void )
{
return V_28 ;
}
static int F_38 ( const T_8 * T_9 , T_10 * V_24 , int T_11 V_23 )
{
const V_25 * V_44 = ( const V_25 * ) T_9 -> V_26 ;
T_10 * V_45 = V_24 ;
V_45 = F_39 ( V_45 , & V_44 [ 0 ] , 4 ) ;
* V_45 ++ = '.' ;
V_45 = F_39 ( V_45 , & V_44 [ 4 ] , 6 ) ;
* V_45 ++ = '\0' ;
return ( int ) ( V_45 - V_24 ) ;
}
static int F_40 ( const T_8 * T_9 V_23 )
{
return 22 ;
}
static int F_41 ( void )
{
return 10 ;
}
static int F_42 ( const T_8 * T_9 , T_10 * V_24 , int T_11 V_23 )
{
const V_25 * V_46 = ( const V_25 * ) T_9 -> V_26 ;
T_10 * V_45 = V_24 ;
V_45 = F_43 ( V_45 , F_44 ( & V_46 [ 0 ] ) ) ;
* V_45 ++ = '.' ;
V_45 = F_45 ( V_45 , F_46 ( & V_46 [ 4 ] ) ) ;
* V_45 ++ = '\0' ;
return ( int ) ( V_45 - V_24 ) ;
}
static int F_47 ( const T_8 * T_9 V_23 )
{
return 14 ;
}
static int F_48 ( void )
{
return V_47 ;
}
static int F_49 ( const T_8 * T_9 , T_10 * V_24 , int T_11 V_23 )
{
T_10 * V_45 = V_24 ;
V_45 = F_11 ( V_45 , ( const V_25 * ) T_9 -> V_26 , 3 , '.' ) ;
* V_45 ++ = '\0' ;
return ( int ) ( V_45 - V_24 ) ;
}
static int F_50 ( const T_8 * T_9 V_23 )
{
return 9 ;
}
static int F_51 ( void )
{
return 3 ;
}
static int F_52 ( const T_8 * T_9 V_23 )
{
return 24 ;
}
static int F_53 ( const T_8 * T_9 , T_10 * V_24 , int T_11 V_23 )
{
const V_25 * V_48 = ( const V_25 * ) T_9 -> V_26 ;
V_24 = F_11 ( V_24 , V_48 , 8 , ':' ) ;
* V_24 = '\0' ;
return F_52 ( T_9 ) ;
}
static int F_54 ( void )
{
return V_49 ;
}
static const T_10 * F_55 ( const T_8 * T_9 )
{
const V_25 * V_48 = ( const V_25 * ) T_9 -> V_26 ;
int V_50 ;
V_25 V_51 [ 6 ] ;
V_50 = ( V_48 [ 0 ] & 0xF0 ) >> 4 ;
switch ( V_50 ) {
case V_52 :
case V_53 :
memcpy ( V_51 , & V_48 [ 2 ] , 6 ) ;
return F_56 ( V_51 ) ;
case V_54 :
V_51 [ 0 ] = ( ( V_48 [ 0 ] & 0x0F ) << 4 ) | ( ( V_48 [ 1 ] & 0xF0 ) >> 4 ) ;
V_51 [ 1 ] = ( ( V_48 [ 1 ] & 0x0F ) << 4 ) | ( ( V_48 [ 2 ] & 0xF0 ) >> 4 ) ;
V_51 [ 2 ] = ( ( V_48 [ 2 ] & 0x0F ) << 4 ) | ( ( V_48 [ 3 ] & 0xF0 ) >> 4 ) ;
V_51 [ 3 ] = ( ( V_48 [ 3 ] & 0x0F ) << 4 ) | ( ( V_48 [ 4 ] & 0xF0 ) >> 4 ) ;
V_51 [ 4 ] = ( ( V_48 [ 4 ] & 0x0F ) << 4 ) | ( ( V_48 [ 5 ] & 0xF0 ) >> 4 ) ;
V_51 [ 5 ] = ( ( V_48 [ 5 ] & 0x0F ) << 4 ) | ( ( V_48 [ 6 ] & 0xF0 ) >> 4 ) ;
return F_56 ( V_51 ) ;
}
return L_10 ;
}
static int F_57 ( void )
{
return V_28 ;
}
static int F_58 ( const T_8 * T_9 , T_10 * V_24 , int T_11 )
{
F_59 ( ( const V_55 * ) T_9 -> V_26 , V_24 , T_11 ) ;
return ( int ) ( strlen ( V_24 ) + 1 ) ;
}
static int F_60 ( const T_8 * T_9 V_23 )
{
return 50 ;
}
static int F_61 ( const T_8 * T_9 , T_10 * V_24 , int T_11 )
{
F_27 ( V_24 , ( const T_10 * ) T_9 -> V_26 , T_11 ) ;
return ( int ) ( strlen ( V_24 ) + 1 ) ;
}
static int F_62 ( const T_8 * T_9 )
{
return T_9 -> V_33 + 1 ;
}
static int F_63 ( const T_8 * T_9 , T_10 * V_24 , int T_11 V_23 )
{
V_24 = F_11 ( V_24 , ( const V_25 * ) T_9 -> V_26 , 8 , ':' ) ;
* V_24 = '\0' ;
return sizeof( V_24 ) + 1 ;
}
static int F_64 ( const T_8 * T_9 V_23 )
{
return V_56 ;
}
static int F_65 ( void )
{
return 8 ;
}
static int
F_66 ( const T_8 * T_9 , T_10 * V_24 , int T_11 ) {
if ( T_9 -> V_33 >= 16 ) {
#define F_67 ((int)(sizeof("GID: ") - 1))
F_27 ( V_24 , L_11 , T_11 ) ;
if ( T_11 < F_67 ||
F_68 ( V_57 , T_9 -> V_26 , V_24 + F_67 ,
T_11 - F_67 ) == NULL )
F_27 ( V_24 , V_39 , T_11 ) ;
} else {
T_16 V_58 ;
memcpy ( ( void * ) & V_58 , T_9 -> V_26 , sizeof V_58 ) ;
F_69 ( V_24 , T_11 , L_12 , V_58 ) ;
}
return sizeof( V_24 ) + 1 ;
}
static int F_70 ( const T_8 * T_9 V_23 )
{
return V_28 ;
}
static int F_71 ( const T_8 * T_9 , T_10 * V_24 , int T_11 V_23 )
{
const V_25 * V_48 = ( const V_25 * ) T_9 -> V_26 ;
if( F_72 ( & V_48 [ 0 ] ) == 0xffffffff ) {
F_27 ( V_24 , L_13 , T_11 ) ;
} else {
F_69 ( V_24 , T_11 , L_14 , F_73 ( & V_48 [ 8 ] ) ,
F_72 ( & V_48 [ 0 ] ) , F_72 ( & V_48 [ 4 ] ) ) ;
}
return ( int ) ( strlen ( V_24 ) + 1 ) ;
}
static int F_74 ( const T_8 * T_9 V_23 )
{
return 50 ;
}
static int F_75 ( const T_8 * T_9 , T_10 * V_24 , int T_11 V_23 )
{
const V_25 * V_44 = ( const V_25 * ) T_9 -> V_26 ;
T_10 * V_45 = V_24 ;
* V_45 ++ = F_76 ( V_44 [ 0 ] >> 1 ) ;
* V_45 ++ = F_76 ( V_44 [ 1 ] >> 1 ) ;
* V_45 ++ = F_76 ( V_44 [ 2 ] >> 1 ) ;
* V_45 ++ = F_76 ( V_44 [ 3 ] >> 1 ) ;
* V_45 ++ = F_76 ( V_44 [ 4 ] >> 1 ) ;
* V_45 ++ = F_76 ( V_44 [ 5 ] >> 1 ) ;
* V_45 ++ = '-' ;
V_45 = F_77 ( V_45 , ( V_44 [ 6 ] >> 1 ) & 0x0f ) ;
* V_45 ++ = '\0' ;
return ( int ) ( V_45 - V_24 ) ;
}
static int F_78 ( const T_8 * T_9 V_23 )
{
return 21 ;
}
static const char * F_79 ( const T_8 * T_9 V_23 , T_12 V_27 )
{
if ( V_27 )
return L_15 ;
return L_16 ;
}
static int F_80 ( void )
{
return V_59 ;
}
void F_81 ( void )
{
static T_1 V_60 = {
V_61 ,
L_17 ,
L_18 ,
F_5 ,
F_6 ,
NULL ,
F_7 ,
F_9 ,
F_8 ,
} ;
static T_1 V_62 = {
V_63 ,
L_19 ,
L_20 ,
F_10 ,
F_12 ,
F_13 ,
F_14 ,
F_15 ,
F_17 ,
} ;
static T_1 V_64 = {
V_65 ,
L_21 ,
L_22 ,
F_18 ,
F_20 ,
F_21 ,
F_22 ,
F_23 ,
F_25 ,
} ;
static T_1 V_66 = {
V_67 ,
L_23 ,
L_24 ,
F_31 ,
F_32 ,
F_33 ,
F_34 ,
F_35 ,
F_37 ,
} ;
static T_1 V_68 = {
V_69 ,
L_25 ,
L_26 ,
F_38 ,
F_40 ,
NULL ,
F_41 ,
NULL ,
NULL ,
} ;
static T_1 V_70 = {
V_71 ,
L_27 ,
L_28 ,
F_42 ,
F_47 ,
NULL ,
F_48 ,
NULL ,
NULL ,
} ;
static T_1 V_72 = {
V_73 ,
L_29 ,
L_30 ,
F_49 ,
F_50 ,
NULL ,
F_51 ,
NULL ,
NULL ,
} ;
static T_1 V_74 = {
V_75 ,
L_31 ,
L_32 ,
F_53 ,
F_52 ,
NULL ,
F_54 ,
F_55 ,
F_57 ,
} ;
static T_1 V_76 = {
V_77 ,
L_33 ,
L_34 ,
F_58 ,
F_60 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_1 V_78 = {
V_79 ,
L_35 ,
L_36 ,
F_61 ,
F_62 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_1 V_80 = {
V_81 ,
L_37 ,
L_38 ,
F_63 ,
F_64 ,
NULL ,
F_65 ,
NULL ,
NULL ,
} ;
static T_1 V_82 = {
V_83 ,
L_39 ,
L_40 ,
F_66 ,
F_70 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_1 V_84 = {
V_85 ,
L_41 ,
L_42 ,
F_71 ,
F_74 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
static T_1 V_86 = {
V_87 ,
L_43 ,
L_44 ,
F_75 ,
F_78 ,
F_79 ,
F_80 ,
NULL ,
NULL ,
} ;
V_17 = 0 ;
memset ( V_4 , 0 , V_3 * sizeof( T_1 * ) ) ;
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
F_1 ( V_81 , & V_80 ) ;
F_1 ( V_83 , & V_82 ) ;
F_1 ( V_85 , & V_84 ) ;
F_1 ( V_87 , & V_86 ) ;
}
static int F_82 ( const T_8 * T_9 )
{
T_1 * V_2 ;
F_83 ( T_9 -> type , V_2 ) ;
if ( V_2 == NULL )
return 0 ;
return V_2 -> V_8 ( T_9 ) ;
}
T_10 *
F_84 ( T_17 * V_88 , const T_8 * T_9 )
{
T_10 * V_89 ;
int V_33 = F_82 ( T_9 ) ;
if ( V_33 <= 0 )
V_33 = V_28 ;
V_89 = ( T_10 * ) F_85 ( V_88 , V_33 ) ;
F_86 ( T_9 , V_89 , V_33 ) ;
return V_89 ;
}
void F_86 ( const T_8 * T_9 , T_10 * V_24 , int T_11 )
{
T_1 * V_2 ;
if ( ! V_24 || ! T_11 )
return;
F_83 ( T_9 -> type , V_2 ) ;
if ( ( V_2 == NULL ) || ( V_2 -> V_7 == NULL ) )
{
V_24 [ 0 ] = '\0' ;
return;
}
V_2 -> V_7 ( T_9 , V_24 , T_11 ) ;
}
const T_10 *
F_87 ( const T_8 * T_9 )
{
T_1 * V_2 ;
F_83 ( T_9 -> type , V_2 ) ;
if ( V_2 == NULL )
{
return NULL ;
}
switch ( T_9 -> type ) {
case V_79 :
return ( const T_10 * ) T_9 -> V_26 ;
default:
if ( V_2 -> V_9 != NULL )
return V_2 -> V_9 ( T_9 ) ;
else
return NULL ;
}
}
const T_10 *
F_88 ( T_17 * V_90 , const T_8 * T_9 )
{
T_10 * V_89 = NULL ;
const T_10 * V_91 = F_87 ( T_9 ) ;
if ( V_91 != NULL ) {
V_89 = F_89 ( V_90 , V_91 ) ;
}
else if ( T_9 -> type == V_61 ) {
V_89 = F_89 ( V_90 , L_1 ) ;
}
else {
V_89 = ( T_10 * ) F_85 ( V_90 , V_28 ) ;
F_86 ( T_9 , V_89 , V_28 ) ;
}
return V_89 ;
}
static void F_90 ( const T_8 * T_9 , T_10 * V_24 , int T_11 )
{
T_1 * V_2 ;
int V_92 ;
T_18 V_93 ;
T_12 V_94 ;
if ( ! V_24 || ! T_11 )
return;
F_83 ( T_9 -> type , V_2 ) ;
if ( V_2 == NULL )
{
V_24 [ 0 ] = '\0' ;
return;
}
#if 0
if (at->addr_name_res_str == NULL)
return address_to_str_buf(addr, buf, buf_len);
#endif
V_93 = F_27 ( V_24 , V_2 -> V_9 ( T_9 ) , T_11 ) ;
if ( T_9 -> type == V_61 )
return;
if ( ( int ) ( V_93 + 4 + V_2 -> V_8 ( T_9 ) ) >= T_11 )
return;
V_94 = ( V_93 <= 1 ) ? TRUE : FALSE ;
if ( ! V_94 )
{
V_24 [ V_93 ++ ] = ' ' ;
V_24 [ V_93 ++ ] = '(' ;
}
V_92 = V_2 -> V_7 ( T_9 , & V_24 [ V_93 ] , ( int ) ( T_11 - V_93 ) ) ;
V_93 += V_92 - 1 ;
if ( ! V_94 )
{
V_24 [ V_93 ++ ] = ')' ;
V_24 [ V_93 ++ ] = '\0' ;
}
}
T_10 * F_91 ( T_17 * V_88 , const T_8 * T_9 )
{
T_1 * V_2 ;
int V_33 ;
T_10 * V_89 ;
F_83 ( T_9 -> type , V_2 ) ;
if ( V_2 == NULL )
return F_89 ( V_88 , L_10 ) ;
if ( ( V_2 -> V_9 == NULL ) ||
( F_92 ( T_9 ) && ! V_95 . V_96 ) ||
( F_93 ( T_9 ) && ! V_95 . V_97 ) ) {
return F_84 ( V_88 , T_9 ) ;
}
V_33 = V_2 -> V_10 () + V_2 -> V_8 ( T_9 ) + 4 ;
V_89 = ( T_10 * ) F_85 ( V_88 , V_33 ) ;
F_90 ( T_9 , V_89 , V_33 ) ;
return V_89 ;
}
const char * F_94 ( const T_8 * T_9 , T_12 V_31 )
{
T_1 * V_2 ;
F_83 ( T_9 -> type , V_2 ) ;
if ( ( V_2 == NULL ) || ( V_2 -> V_21 == NULL ) )
{
return L_10 ;
}
return V_2 -> V_21 ( T_9 , V_31 ) ;
}
T_10 *
F_95 ( T_17 * V_88 , T_19 * V_98 , int type , const T_20 V_99 )
{
T_8 T_9 ;
T_1 * V_2 ;
F_83 ( type , V_2 ) ;
if ( V_2 == NULL )
{
return NULL ;
}
if ( V_2 -> V_22 == NULL )
{
F_96 () ;
return NULL ;
}
F_97 ( & T_9 , type , V_98 , V_99 , V_2 -> V_22 () ) ;
return F_84 ( V_88 , & T_9 ) ;
}
T_10 * F_98 ( T_17 * V_88 , T_19 * V_98 , T_21 type , const T_20 V_99 , int V_100 )
{
T_8 T_9 ;
F_97 ( & T_9 , type , V_98 , V_99 , V_100 ) ;
return F_84 ( V_88 , & T_9 ) ;
}
T_10 *
F_99 ( T_17 * V_88 , T_19 * V_98 , int type , const T_20 V_99 )
{
T_8 T_9 ;
T_1 * V_2 ;
F_83 ( type , V_2 ) ;
if ( V_2 == NULL )
{
return NULL ;
}
if ( V_2 -> V_22 == NULL )
{
F_96 () ;
return NULL ;
}
F_97 ( & T_9 , type , V_98 , V_99 , V_2 -> V_22 () ) ;
return F_91 ( V_88 , & T_9 ) ;
}
