T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int T_2 F_2 ( T_3 * V_2 )
{
V_2 -> V_3 = 1 ;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = NULL ;
F_3 ( V_2 , L_1 , V_6 ) ;
return ( 1 ) ;
}
static int T_2 F_4 ( T_3 * V_7 )
{
if ( V_7 == NULL ) return ( 0 ) ;
F_5 ( V_7 ) ;
return ( 1 ) ;
}
static int T_2 F_6 ( T_3 * V_8 , const char * V_9 , int V_10 )
{
int V_11 = V_10 ;
char * V_12 ;
char * V_13 ;
int V_14 , V_15 ;
static const struct
{
int V_16 ;
char V_17 [ 10 ] ;
int V_18 ;
}
V_19 [] =
{
{ 6 , L_2 , V_20 } ,
{ 6 , L_3 , V_20 } ,
{ 4 , L_4 , V_20 } ,
{ 6 , L_5 , V_21 } ,
{ 4 , L_6 , V_21 } ,
{ 5 , L_7 , V_22 } ,
{ 4 , L_8 , V_22 } ,
{ 6 , L_9 , V_23 } ,
{ 4 , L_10 , V_23 } ,
{ 8 , L_11 , V_24 } ,
{ 5 , L_12 , V_24 } ,
{ 4 , L_13 , V_24 } ,
{ 7 , L_14 , V_25 } ,
{ 5 , L_15 , V_25 } ,
{ 4 , L_16 , V_25 } ,
{ 5 , L_17 , V_26 } ,
{ 4 , L_18 , V_26 } ,
{ 6 , L_19 , V_27 } ,
{ 4 , L_20 , V_27 } ,
{ 0 , L_21 , V_23 }
} ;
if( ( V_12 = ( char * ) F_7 ( V_10 + 1 ) ) == NULL ) {
return ( 0 ) ;
}
strncpy ( V_12 , V_9 , V_10 ) ;
V_12 [ V_10 ] = '\0' ;
V_15 = 0 ;
while( strncmp ( V_12 , V_19 [ V_15 ] . V_17 , V_19 [ V_15 ] . V_16 ) != 0 ) V_15 ++ ;
V_14 = V_19 [ V_15 ] . V_18 ;
V_13 = V_12 + V_19 [ V_15 ] . V_16 ;
F_8 ( V_8 , V_14 , V_13 ) ;
F_9 ( V_12 ) ;
return ( V_11 ) ;
}
static long T_2 F_10 ( T_3 * V_8 , int V_28 , long V_4 , void * V_5 )
{
switch ( V_28 )
{
case V_29 :
F_5 ( V_8 ) ;
F_3 ( V_8 , V_5 , V_4 ) ;
break;
default:
break;
}
return ( 0 ) ;
}
static int T_2 F_11 ( T_3 * V_30 , const char * V_17 )
{
int V_31 , V_11 ;
V_31 = strlen ( V_17 ) ;
V_11 = F_6 ( V_30 , V_17 , V_31 ) ;
return ( V_11 ) ;
}
static void F_3 ( T_3 * V_30 , char * V_32 , int V_33 )
{
if ( F_12 () < 0x80000000 )
V_30 -> V_5 = F_13 ( NULL , V_32 ) ;
else
V_30 -> V_5 = NULL ;
}
static void F_8 ( T_3 * V_30 , int V_14 , const char * string )
{
T_4 V_34 [ 2 ] ;
T_5 V_35 = V_36 ;
char V_37 [ F_14 ( V_38 ) + 4 ] ;
if ( V_30 -> V_5 == NULL )
return;
switch ( V_14 )
{
case V_20 :
case V_21 :
case V_22 :
case V_23 :
V_35 = V_36 ;
break;
case V_24 :
V_35 = V_39 ;
break;
case V_25 :
case V_26 :
case V_27 :
V_35 = V_40 ;
break;
default:
V_35 = V_36 ;
break;
}
sprintf ( V_37 , L_22 , F_15 () ) ;
V_34 [ 0 ] = V_37 ;
V_34 [ 1 ] = string ;
F_16 ( V_30 -> V_5 , V_35 , 0 , 1024 , NULL , 2 , 0 ,
V_34 , NULL ) ;
}
static void F_5 ( T_3 * V_30 )
{
if( V_30 -> V_5 )
F_17 ( ( V_41 ) ( V_30 -> V_5 ) ) ;
V_30 -> V_5 = NULL ;
}
static void F_3 ( T_3 * V_30 , char * V_32 , int V_33 )
{
V_42 = V_33 ;
}
static void F_8 ( T_3 * V_30 , int V_14 , const char * string )
{
struct V_43 V_44 ;
#if V_45 == 64
# pragma V_46 V_47
# pragma V_46 V_48
# define F_18 __char_ptr32
# define F_19 _malloc32
#else
# define F_18 char *
# define F_19 OPENSSL_malloc
#endif
struct V_49 * V_50 ;
#if V_45 == 64
# pragma V_46 V_51
#endif
char V_12 [ 10240 ] ;
unsigned int V_52 ;
struct V_43 V_53 ;
F_20 ( V_54 , L_23 ) ;
char * V_55 ;
switch ( V_14 )
{
case V_20 : V_55 = L_24 ; break;
case V_21 : V_55 = L_25 ; break;
case V_22 : V_55 = L_26 ; break;
case V_23 : V_55 = L_27 ; break;
case V_24 : V_55 = L_28 ; break;
case V_25 : V_55 = L_29 ; break;
case V_26 : V_55 = L_30 ; break;
case V_27 : V_55 = L_31 ; break;
}
V_53 . V_56 = V_57 ;
V_53 . V_58 = V_59 ;
V_53 . V_60 = V_12 ;
V_53 . V_61 = sizeof( V_12 ) - 1 ;
F_21 ( & V_54 , & V_52 , & V_53 , V_55 , string ) ;
V_50 = F_19 ( 8 + V_52 ) ;
V_50 -> V_62 = V_63 ;
memcpy ( V_50 -> V_64 , & V_42 , 3 ) ;
V_50 -> V_65 = 0 ;
memcpy ( & V_50 -> V_66 , V_12 , V_52 ) ;
V_44 . V_56 = V_57 ;
V_44 . V_58 = V_59 ;
V_44 . V_60 = ( F_18 ) V_50 ;
V_44 . V_61 = V_52 + 8 ;
F_22 ( V_44 , 0 ) ;
F_9 ( V_50 ) ;
}
static void F_5 ( T_3 * V_30 )
{
}
static void F_3 ( T_3 * V_30 , char * V_32 , int V_33 )
{
#ifdef F_23
F_24 ( V_32 , V_67 | V_68 | V_69 , V_33 ) ;
#else
F_24 ( V_32 , V_67 | V_68 , V_33 ) ;
#endif
}
static void F_8 ( T_3 * V_30 , int V_14 , const char * string )
{
F_25 ( V_14 , L_32 , string ) ;
}
static void F_5 ( T_3 * V_30 )
{
F_26 () ;
}
