const struct V_1 * F_1 ( T_1 * V_2 )
{
int V_3 ;
struct V_1 * V_4 ;
if ( ! V_2 )
{
const char * V_5 = F_2 ( V_6 ) ;
if ( ! V_5 || ! strlen ( V_5 ) )
return & V_7 [ 1 ] ;
V_3 = F_3 ( V_5 ) ;
if ( V_3 == V_8 )
{
F_4 ( V_9 ,
V_10 ) ;
return NULL ;
}
}
else
{
V_3 = F_5 ( V_2 ) ;
}
for ( V_4 = V_7 ; V_4 -> V_11 != NULL && V_4 -> V_3 != V_3 ;
V_4 ++ ) ;
if ( ! V_4 -> V_11 )
{
F_4 ( V_9 , V_12 ) ;
return NULL ;
}
return V_4 ;
}
static int F_6 ( struct V_13 * V_14 , int V_3 )
{
const struct V_1 * V_4 ;
V_4 = F_1 ( ( V_3 == V_8 ? NULL : F_7 ( V_3 ) ) ) ;
if ( ! V_4 ) return 0 ;
V_14 -> V_15 = V_4 -> V_3 ;
V_14 -> V_16 = V_4 -> V_16 ;
V_14 -> V_17 = 0 ;
F_8 ( & ( V_14 -> V_18 ) , V_4 -> V_11 ) ;
return 1 ;
}
static int F_9 ( T_2 * V_19 , const unsigned char * V_20 ,
const unsigned char * V_21 , int V_22 , int V_15 , int V_23 )
{
struct V_13 * V_14 = V_19 -> V_24 ;
if ( V_19 -> V_25 == NULL )
{
if ( ! F_6 ( V_14 , V_15 ) ) return 0 ;
V_19 -> V_25 = V_19 -> V_24 ;
}
if ( V_20 ) F_10 ( & ( V_14 -> V_18 ) , V_20 ) ;
if( V_21 ) memcpy ( V_19 -> V_26 , V_21 , F_11 ( V_19 ) ) ;
memcpy ( V_19 -> V_21 , V_19 -> V_26 , F_11 ( V_19 ) ) ;
return 1 ;
}
static int F_12 ( T_2 * V_19 , const unsigned char * V_20 ,
const unsigned char * V_21 , int V_22 )
{
struct V_13 * V_14 = V_19 -> V_24 ;
F_8 ( & ( V_14 -> V_18 ) , & V_27 ) ;
V_14 -> V_16 = 1 ;
V_14 -> V_17 = 0 ;
if( V_20 ) F_10 ( & ( V_14 -> V_18 ) , V_20 ) ;
if( V_21 ) memcpy ( V_19 -> V_26 , V_21 , F_11 ( V_19 ) ) ;
memcpy ( V_19 -> V_21 , V_19 -> V_26 , F_11 ( V_19 ) ) ;
return 1 ;
}
int F_13 ( T_2 * V_19 , const unsigned char * V_20 ,
const unsigned char * V_21 , int V_22 )
{
return F_9 ( V_19 , V_20 , V_21 , V_22 , V_8 , V_28 ) ;
}
static void F_14 ( void * V_19 , unsigned char * V_21 , unsigned char * V_29 )
{
struct V_13 * V_14 = V_19 ;
if ( V_14 -> V_17 && V_14 -> V_16 && V_14 -> V_17 % 1024 == 0 )
{
F_15 ( & ( V_14 -> V_18 ) , V_21 ) ;
}
F_16 ( & ( V_14 -> V_18 ) , V_21 , V_29 ) ;
V_14 -> V_17 += 8 ;
}
static void F_17 ( void * V_19 , unsigned char * V_21 , unsigned char * V_29 )
{
struct V_13 * V_14 = V_19 ;
T_3 V_30 , V_31 ;
unsigned char V_32 [ 8 ] ;
if ( V_14 -> V_17 && V_14 -> V_16 && V_14 -> V_17 % 1024 == 0 )
{
F_15 ( & ( V_14 -> V_18 ) , V_21 ) ;
}
if ( V_14 -> V_17 == 0 )
{
F_16 ( & ( V_14 -> V_18 ) , V_21 , V_32 ) ;
}
else
{
memcpy ( V_32 , V_21 , 8 ) ;
}
V_30 = V_32 [ 0 ] | ( V_32 [ 1 ] << 8 ) | ( V_32 [ 2 ] << 16 ) | ( V_32 [ 3 ] << 24 ) ;
V_30 += 0x01010101 ;
V_32 [ 0 ] = ( unsigned char ) ( V_30 & 0xff ) ;
V_32 [ 1 ] = ( unsigned char ) ( ( V_30 >> 8 ) & 0xff ) ;
V_32 [ 2 ] = ( unsigned char ) ( ( V_30 >> 16 ) & 0xff ) ;
V_32 [ 3 ] = ( unsigned char ) ( ( V_30 >> 24 ) & 0xff ) ;
V_30 = V_32 [ 4 ] | ( V_32 [ 5 ] << 8 ) | ( V_32 [ 6 ] << 16 ) | ( V_32 [ 7 ] << 24 ) ;
V_31 = V_30 ;
V_30 += 0x01010104 ;
if ( V_31 > V_30 )
V_30 ++ ;
V_32 [ 4 ] = ( unsigned char ) ( V_30 & 0xff ) ;
V_32 [ 5 ] = ( unsigned char ) ( ( V_30 >> 8 ) & 0xff ) ;
V_32 [ 6 ] = ( unsigned char ) ( ( V_30 >> 16 ) & 0xff ) ;
V_32 [ 7 ] = ( unsigned char ) ( ( V_30 >> 24 ) & 0xff ) ;
memcpy ( V_21 , V_32 , 8 ) ;
F_16 ( & ( V_14 -> V_18 ) , V_32 , V_29 ) ;
V_14 -> V_17 += 8 ;
}
int F_18 ( T_2 * V_19 , unsigned char * V_33 ,
const unsigned char * V_34 , T_4 V_35 )
{
const unsigned char * V_36 = V_34 ;
unsigned char * V_37 = V_33 ;
T_4 V_38 = 0 ;
T_4 V_39 = 0 ;
if ( V_19 -> V_40 )
{
for ( V_39 = V_19 -> V_40 , V_38 = 0 ; V_39 < 8 && V_38 < V_35 ; V_39 ++ , V_38 ++ , V_36 ++ , V_37 ++ )
{
if ( ! V_19 -> V_41 ) V_19 -> V_29 [ V_39 + 8 ] = * V_36 ;
* V_37 = V_19 -> V_29 [ V_39 ] ^ ( * V_36 ) ;
if ( V_19 -> V_41 ) V_19 -> V_29 [ V_39 + 8 ] = * V_37 ;
}
if ( V_39 == 8 )
{
memcpy ( V_19 -> V_21 , V_19 -> V_29 + 8 , 8 ) ;
V_19 -> V_40 = 0 ;
}
else
{
V_19 -> V_40 = V_39 ;
return 1 ;
}
}
for (; V_38 + 8 < V_35 ; V_38 += 8 , V_36 += 8 , V_37 += 8 )
{
F_14 ( V_19 -> V_24 , V_19 -> V_21 , V_19 -> V_29 ) ;
if ( ! V_19 -> V_41 ) memcpy ( V_19 -> V_21 , V_36 , 8 ) ;
for ( V_39 = 0 ; V_39 < 8 ; V_39 ++ )
{
V_37 [ V_39 ] = V_19 -> V_29 [ V_39 ] ^ V_36 [ V_39 ] ;
}
if ( V_19 -> V_41 ) memcpy ( V_19 -> V_21 , V_37 , 8 ) ;
}
if ( V_38 < V_35 )
{
F_14 ( V_19 -> V_24 , V_19 -> V_21 , V_19 -> V_29 ) ;
if ( ! V_19 -> V_41 ) memcpy ( V_19 -> V_29 + 8 , V_36 , V_39 ) ;
for ( V_39 = 0 ; V_38 < V_35 ; V_39 ++ , V_38 ++ )
{
V_37 [ V_39 ] = V_19 -> V_29 [ V_39 ] ^ V_36 [ V_39 ] ;
}
V_19 -> V_40 = V_39 ;
if ( V_19 -> V_41 ) memcpy ( V_19 -> V_29 + 8 , V_37 , V_39 ) ;
}
else
{
V_19 -> V_40 = 0 ;
}
return 1 ;
}
static int F_19 ( T_2 * V_19 , unsigned char * V_33 ,
const unsigned char * V_34 , T_4 V_35 )
{
const unsigned char * V_36 = V_34 ;
unsigned char * V_37 = V_33 ;
T_4 V_38 = 0 ;
T_4 V_39 ;
if ( V_19 -> V_40 )
{
for ( V_39 = V_19 -> V_40 , V_38 = 0 ; V_39 < 8 && V_38 < V_35 ; V_39 ++ , V_38 ++ , V_36 ++ , V_37 ++ )
{
* V_37 = V_19 -> V_29 [ V_39 ] ^ ( * V_36 ) ;
}
if ( V_39 == 8 )
{
V_19 -> V_40 = 0 ;
}
else
{
V_19 -> V_40 = V_39 ;
return 1 ;
}
}
for (; V_38 + 8 < V_35 ; V_38 += 8 , V_36 += 8 , V_37 += 8 )
{
F_17 ( V_19 -> V_24 , V_19 -> V_21 , V_19 -> V_29 ) ;
for ( V_39 = 0 ; V_39 < 8 ; V_39 ++ )
{
V_37 [ V_39 ] = V_19 -> V_29 [ V_39 ] ^ V_36 [ V_39 ] ;
}
}
if ( V_38 < V_35 )
{
F_17 ( V_19 -> V_24 , V_19 -> V_21 , V_19 -> V_29 ) ;
for ( V_39 = 0 ; V_38 < V_35 ; V_39 ++ , V_38 ++ )
{
V_37 [ V_39 ] = V_19 -> V_29 [ V_39 ] ^ V_36 [ V_39 ] ;
}
V_19 -> V_40 = V_39 ;
}
else
{
V_19 -> V_40 = 0 ;
}
return 1 ;
}
int F_20 ( T_2 * V_19 )
{
F_21 ( & ( (struct V_13 * ) V_19 -> V_24 ) -> V_18 ) ;
V_19 -> V_25 = NULL ;
return 1 ;
}
int F_22 ( T_2 * V_19 , int type , int V_42 , void * V_43 )
{
switch ( type )
{
case V_44 :
{
if ( F_23 ( ( unsigned char * ) V_43 , V_19 -> V_45 ) <= 0 )
{
F_4 ( V_46 , V_47 ) ;
return - 1 ;
}
break;
}
case V_48 :
if ( V_43 ) {
* ( ( int * ) V_43 ) = V_49 ;
return 1 ;
} else {
return 0 ;
}
default:
F_4 ( V_46 , V_50 ) ;
return - 1 ;
}
return 1 ;
}
int F_24 ( T_2 * V_19 , T_5 * V_5 )
{
int V_51 = 0 ;
unsigned char * V_29 = NULL ;
unsigned char * V_52 = NULL ;
struct V_13 * V_14 = V_19 -> V_24 ;
T_6 * V_53 = F_25 () ;
T_7 * V_54 = NULL ;
if ( ! V_53 )
{
F_4 ( V_55 , V_56 ) ;
return 0 ;
}
if ( ! F_26 ( V_53 -> V_21 , V_19 -> V_21 , V_19 -> V_57 -> V_58 ) )
{
F_27 ( V_53 ) ;
F_4 ( V_55 , V_56 ) ;
return 0 ;
}
F_28 ( V_53 -> V_59 ) ;
V_53 -> V_59 = F_7 ( V_14 -> V_15 ) ;
V_51 = F_29 ( V_53 , NULL ) ;
V_52 = V_29 = ( unsigned char * ) F_30 ( V_51 ) ;
if ( ! V_29 )
{
F_27 ( V_53 ) ;
F_4 ( V_55 , V_56 ) ;
return 0 ;
}
F_29 ( V_53 , & V_52 ) ;
F_27 ( V_53 ) ;
V_54 = F_31 () ;
if( ! V_54 || ! F_26 ( V_54 , V_29 , V_51 ) )
{
F_32 ( V_29 ) ;
F_4 ( V_55 , V_56 ) ;
return 0 ;
}
F_32 ( V_29 ) ;
F_33 ( V_5 , V_60 , V_54 ) ;
return 1 ;
}
int F_34 ( T_2 * V_19 , T_5 * V_5 )
{
int V_61 = - 1 ;
int V_51 ;
T_6 * V_53 = NULL ;
unsigned char * V_52 = V_5 -> V_62 . V_63 -> V_64 ;
struct V_13 * V_14 = V_19 -> V_24 ;
if ( F_35 ( V_5 ) != V_60 )
{
return V_61 ;
}
V_53 = F_36 ( NULL , ( const unsigned char * * ) & V_52 ,
V_5 -> V_62 . V_63 -> V_65 ) ;
V_51 = V_53 -> V_21 -> V_65 ;
if ( V_51 != V_19 -> V_57 -> V_58 )
{
F_27 ( V_53 ) ;
F_4 ( V_66 ,
V_67 ) ;
return - 1 ;
}
if ( ! F_6 ( V_14 , F_5 ( V_53 -> V_59 ) ) )
{
F_27 ( V_53 ) ;
return - 1 ;
}
memcpy ( V_19 -> V_26 , V_53 -> V_21 -> V_64 , V_51 ) ;
F_27 ( V_53 ) ;
return 1 ;
}
int F_37 ( T_8 * V_19 )
{
struct V_68 * V_14 = V_19 -> V_69 ;
memset ( V_14 -> V_70 , 0 , 16 ) ;
V_14 -> V_17 = 0 ;
V_14 -> V_71 = 0 ;
V_14 -> V_16 = 1 ;
F_8 ( & ( V_14 -> V_18 ) , & V_27 ) ;
return 1 ;
}
static void F_38 ( struct V_68 * V_14 , const unsigned char * V_64 )
{
unsigned char V_70 [ 8 ] ;
if ( V_14 -> V_16 && V_14 -> V_17 && V_14 -> V_17 % 1024 == 0 )
{
F_15 ( & ( V_14 -> V_18 ) , V_70 ) ;
}
F_39 ( & ( V_14 -> V_18 ) , V_14 -> V_70 , V_64 ) ;
V_14 -> V_17 += 8 ;
}
int F_40 ( T_8 * V_19 , const void * V_64 , T_4 V_17 )
{
struct V_68 * V_14 = V_19 -> V_69 ;
const unsigned char * V_52 = V_64 ;
T_4 V_72 = V_17 , V_38 ;
if ( ! ( V_14 -> V_73 ) ) {
F_4 ( V_74 , V_75 ) ;
return 0 ;
}
if ( V_14 -> V_71 )
{
for ( V_38 = V_14 -> V_71 ; V_38 < 8 && V_72 > 0 ; V_72 -- , V_38 ++ , V_52 ++ )
{
V_14 -> V_76 [ V_38 ] = * V_52 ;
}
if ( V_38 == 8 )
{
F_38 ( V_14 , V_14 -> V_76 ) ;
}
else
{
V_14 -> V_71 = V_38 ;
return 1 ;
}
}
while ( V_72 > 8 )
{
F_38 ( V_14 , V_52 ) ;
V_52 += 8 ;
V_72 -= 8 ;
}
if ( V_72 > 0 )
{
memcpy ( V_14 -> V_76 , V_52 , V_72 ) ;
}
V_14 -> V_71 = V_72 ;
return 1 ;
}
int F_41 ( T_8 * V_19 , unsigned char * V_77 )
{
struct V_68 * V_14 = V_19 -> V_69 ;
if ( ! V_14 -> V_73 ) {
F_4 ( V_78 , V_75 ) ;
return 0 ;
}
if ( V_14 -> V_71 )
{
int V_38 ;
for ( V_38 = V_14 -> V_71 ; V_38 < 8 ; V_38 ++ )
{
V_14 -> V_76 [ V_38 ] = 0 ;
}
F_38 ( V_14 , V_14 -> V_76 ) ;
}
F_42 ( V_14 -> V_70 , 32 , V_77 ) ;
return 1 ;
}
int F_43 ( T_8 * V_19 , int type , int V_42 , void * V_43 )
{
switch ( type )
{
case V_79 :
* ( ( unsigned int * ) ( V_43 ) ) = 32 ;
return 1 ;
case V_80 :
{
if ( V_42 != 32 ) {
F_4 ( V_81 , V_82 ) ;
return 0 ;
}
F_10 ( & ( ( (struct V_68 * ) ( V_19 -> V_69 ) ) -> V_18 ) , V_43 ) ;
( (struct V_68 * ) ( V_19 -> V_69 ) ) -> V_73 = 1 ;
return 1 ;
}
default:
return 0 ;
}
}
int F_44 ( T_8 * V_83 , const T_8 * V_84 )
{
memcpy ( V_83 -> V_69 , V_84 -> V_69 , sizeof( struct V_68 ) ) ;
return 1 ;
}
int F_45 ( T_8 * V_19 )
{
memset ( V_19 -> V_69 , 0 , sizeof( struct V_68 ) ) ;
return 1 ;
}
