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
static struct
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
if ( ! V_34 )
{
T_4 V_35 ;
if ( ! ( V_35 = F_12 ( L_22 ) ) )
return;
V_34 = ( T_4 ( V_36 * ) () ) F_13 ( V_35 ,
L_23 ) ;
V_37 = ( BOOL ( V_36 * ) () ) F_14 ( V_35 ,
L_24 ) ;
V_38 = ( BOOL ( V_36 * ) () ) F_13 ( V_35 ,
L_25 ) ;
if ( ! ( V_34 && V_37 &&
V_38 ) )
{
V_34 = NULL ;
V_37 = NULL ;
V_38 = NULL ;
return;
}
}
V_30 -> V_5 = ( char * ) V_34 ( NULL , V_32 ) ;
}
static void F_8 ( T_3 * V_30 , int V_14 , const char * string )
{
T_5 V_39 [ 2 ] ;
T_6 V_40 = V_41 ;
int V_42 = F_15 () ;
char V_43 [ F_16 ( V_42 ) + 4 ] ;
switch ( V_14 )
{
case V_20 :
case V_21 :
case V_22 :
case V_23 :
V_40 = V_41 ;
break;
case V_24 :
V_40 = V_44 ;
break;
case V_25 :
case V_26 :
case V_27 :
V_40 = V_45 ;
break;
default:
V_40 = V_41 ;
break;
}
sprintf ( V_43 , L_26 , V_42 ) ;
V_39 [ 0 ] = V_43 ;
V_39 [ 1 ] = string ;
if( V_38 && V_30 -> V_5 )
V_38 ( V_30 -> V_5 , V_40 , 0 , 1024 , NULL , 2 , 0 ,
V_39 , NULL ) ;
}
static void F_5 ( T_3 * V_30 )
{
if( V_37 && V_30 -> V_5 )
V_37 ( ( T_4 ) ( V_30 -> V_5 ) ) ;
V_30 -> V_5 = NULL ;
}
static void F_3 ( T_3 * V_30 , char * V_32 , int V_33 )
{
V_46 = V_33 ;
}
static void F_8 ( T_3 * V_30 , int V_14 , const char * string )
{
struct V_47 V_48 ;
struct V_49 * V_50 ;
char V_12 [ 10240 ] ;
unsigned int V_51 ;
struct V_47 V_52 ;
F_17 ( V_53 , L_27 ) ;
char * V_54 ;
switch ( V_14 )
{
case V_20 : V_54 = L_28 ; break;
case V_21 : V_54 = L_29 ; break;
case V_22 : V_54 = L_30 ; break;
case V_23 : V_54 = L_31 ; break;
case V_24 : V_54 = L_32 ; break;
case V_25 : V_54 = L_33 ; break;
case V_26 : V_54 = L_34 ; break;
case V_27 : V_54 = L_35 ; break;
}
V_52 . V_55 = V_56 ;
V_52 . V_57 = V_58 ;
V_52 . V_59 = V_12 ;
V_52 . V_60 = sizeof( V_12 ) - 1 ;
F_18 ( & V_53 , & V_51 , & V_52 , V_54 , string ) ;
V_50 = (struct V_49 * ) F_7 ( 8 + V_51 ) ;
V_50 -> V_61 = V_62 ;
memcpy ( V_50 -> V_63 , & V_46 , 3 ) ;
V_50 -> V_64 = 0 ;
memcpy ( & V_50 -> V_65 , V_12 , V_51 ) ;
V_48 . V_55 = V_56 ;
V_48 . V_57 = V_58 ;
V_48 . V_59 = ( char * ) V_50 ;
V_48 . V_60 = V_51 + 8 ;
F_19 ( V_48 , 0 ) ;
F_9 ( V_50 ) ;
}
static void F_5 ( T_3 * V_30 )
{
}
static void F_3 ( T_3 * V_30 , char * V_32 , int V_33 )
{
#ifdef F_20
F_21 ( V_32 , V_66 | V_67 | V_68 , V_33 ) ;
#else
F_21 ( V_32 , V_66 | V_67 , V_33 ) ;
#endif
}
static void F_8 ( T_3 * V_30 , int V_14 , const char * string )
{
F_22 ( V_14 , L_36 , string ) ;
}
static void F_5 ( T_3 * V_30 )
{
F_23 () ;
}
