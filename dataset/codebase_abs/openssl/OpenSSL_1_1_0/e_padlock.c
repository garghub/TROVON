void F_1 ( void )
{
# ifdef F_2
T_1 * V_1 = F_3 () ;
if ( ! V_1 )
return;
F_4 ( V_1 ) ;
F_5 ( V_1 ) ;
F_6 () ;
# endif
}
static int F_7 ( T_1 * V_2 )
{
F_8 () ;
V_3 = 0 ;
F_9 ( V_4 , sizeof( V_4 ) ,
L_1 ,
V_3 ? L_2 : L_3 ,
V_5 ? L_4 : L_5 ) ;
if ( ! F_10 ( V_2 , V_6 ) ||
! F_11 ( V_2 , V_4 ) ||
! F_12 ( V_2 , V_7 ) ||
( V_5 && ! F_13 ( V_2 , V_8 ) ) ||
( V_3 && ! F_14 ( V_2 , & V_9 ) ) ) {
return 0 ;
}
return 1 ;
}
static T_1 * F_3 ( void )
{
T_1 * V_10 = F_15 () ;
if ( V_10 == NULL ) {
return NULL ;
}
if ( ! F_7 ( V_10 ) ) {
F_5 ( V_10 ) ;
return NULL ;
}
return V_10 ;
}
static int V_7 ( T_1 * V_2 )
{
return ( V_3 || V_5 ) ;
}
static int F_16 ( T_1 * V_2 , const char * V_11 )
{
if ( V_11 && ( strcmp ( V_11 , V_6 ) != 0 ) ) {
return 0 ;
}
if ( ! F_7 ( V_2 ) ) {
return 0 ;
}
return 1 ;
}
static int F_8 ( void )
{
unsigned int V_12 = F_17 () ;
V_5 = ( ( V_12 & ( 0x3 << 6 ) ) == ( 0x3 << 6 ) ) ;
V_3 = ( ( V_12 & ( 0x3 << 2 ) ) == ( 0x3 << 2 ) ) ;
return V_5 + V_3 ;
}
static int
F_18 ( T_2 * V_13 , unsigned char * V_14 ,
const unsigned char * V_15 , T_3 V_16 )
{
return F_19 ( V_14 , V_15 ,
F_20 ( V_13 ) , V_16 ) ;
}
static int
F_21 ( T_2 * V_13 , unsigned char * V_14 ,
const unsigned char * V_15 , T_3 V_16 )
{
struct V_17 * V_18 = F_20 ( V_13 ) ;
int V_19 ;
memcpy ( V_18 -> V_20 , F_22 ( V_13 ) , V_21 ) ;
if ( ( V_19 = F_23 ( V_14 , V_15 , V_18 , V_16 ) ) )
memcpy ( F_24 ( V_13 ) , V_18 -> V_20 , V_21 ) ;
return V_19 ;
}
static int
F_25 ( T_2 * V_13 , unsigned char * V_14 ,
const unsigned char * V_15 , T_3 V_16 )
{
struct V_17 * V_18 = F_20 ( V_13 ) ;
T_3 V_22 ;
if ( ( V_22 = F_26 ( V_13 ) ) ) {
unsigned char * V_23 = F_24 ( V_13 ) ;
if ( V_22 >= V_21 )
return 0 ;
if ( F_27 ( V_13 ) )
while ( V_22 < V_21 && V_16 != 0 ) {
V_23 [ V_22 ] = * ( V_14 ++ ) = * ( V_15 ++ ) ^ V_23 [ V_22 ] ;
V_22 ++ , V_16 -- ;
} else
while ( V_22 < V_21 && V_16 != 0 ) {
unsigned char V_24 = * ( V_15 ++ ) ;
* ( V_14 ++ ) = V_24 ^ V_23 [ V_22 ] ;
V_23 [ V_22 ++ ] = V_24 , V_16 -- ;
}
F_28 ( V_13 , V_22 % V_21 ) ;
}
if ( V_16 == 0 )
return 1 ;
memcpy ( V_18 -> V_20 , F_22 ( V_13 ) , V_21 ) ;
if ( ( V_22 = V_16 & ~ ( V_21 - 1 ) ) ) {
if ( ! F_29 ( V_14 , V_15 , V_18 , V_22 ) )
return 0 ;
V_16 -= V_22 ;
}
if ( V_16 ) {
unsigned char * V_23 = V_18 -> V_20 ;
V_14 += V_22 ;
V_15 += V_22 ;
F_28 ( V_13 , V_16 ) ;
if ( V_18 -> V_25 . V_26 . V_27 ) {
V_18 -> V_25 . V_26 . V_27 = 0 ;
F_30 () ;
F_31 ( V_23 , V_23 , V_18 ) ;
V_18 -> V_25 . V_26 . V_27 = 1 ;
F_30 () ;
while ( V_16 ) {
unsigned char V_24 = * ( V_15 ++ ) ;
* ( V_14 ++ ) = V_24 ^ * V_23 ;
* ( V_23 ++ ) = V_24 , V_16 -- ;
}
} else {
F_30 () ;
F_31 ( V_23 , V_23 , V_18 ) ;
F_30 () ;
while ( V_16 ) {
* V_23 = * ( V_14 ++ ) = * ( V_15 ++ ) ^ * V_23 ;
V_23 ++ , V_16 -- ;
}
}
}
memcpy ( F_24 ( V_13 ) , V_18 -> V_20 , V_21 ) ;
return 1 ;
}
static int
F_32 ( T_2 * V_13 , unsigned char * V_14 ,
const unsigned char * V_15 , T_3 V_16 )
{
struct V_17 * V_18 = F_20 ( V_13 ) ;
T_3 V_22 ;
if ( ( V_22 = F_26 ( V_13 ) ) ) {
unsigned char * V_23 = F_24 ( V_13 ) ;
if ( V_22 >= V_21 )
return 0 ;
while ( V_22 < V_21 && V_16 != 0 ) {
* ( V_14 ++ ) = * ( V_15 ++ ) ^ V_23 [ V_22 ] ;
V_22 ++ , V_16 -- ;
}
F_28 ( V_13 , V_22 % V_21 ) ;
}
if ( V_16 == 0 )
return 1 ;
memcpy ( V_18 -> V_20 , F_22 ( V_13 ) , V_21 ) ;
if ( ( V_22 = V_16 & ~ ( V_21 - 1 ) ) ) {
if ( ! F_33 ( V_14 , V_15 , V_18 , V_22 ) )
return 0 ;
V_16 -= V_22 ;
}
if ( V_16 ) {
unsigned char * V_23 = V_18 -> V_20 ;
V_14 += V_22 ;
V_15 += V_22 ;
F_28 ( V_13 , V_16 ) ;
F_30 () ;
F_31 ( V_23 , V_23 , V_18 ) ;
F_30 () ;
while ( V_16 ) {
* ( V_14 ++ ) = * ( V_15 ++ ) ^ * V_23 ;
V_23 ++ , V_16 -- ;
}
}
memcpy ( F_24 ( V_13 ) , V_18 -> V_20 , V_21 ) ;
return 1 ;
}
static void F_34 ( const unsigned char * V_28 ,
unsigned char * V_29 , T_3 V_30 ,
struct V_17 * V_13 ,
const unsigned char * V_31 )
{
memcpy ( V_13 -> V_20 , V_31 , V_21 ) ;
F_35 ( V_29 , V_28 , V_13 , V_21 * V_30 ) ;
}
static int
F_36 ( T_2 * V_13 , unsigned char * V_14 ,
const unsigned char * V_15 , T_3 V_16 )
{
struct V_17 * V_18 = F_20 ( V_13 ) ;
unsigned int V_32 = F_26 ( V_13 ) ;
F_37 ( V_15 , V_14 , V_16 ,
V_18 , F_24 ( V_13 ) ,
F_38 ( V_13 ) , & V_32 ,
( V_33 ) F_34 ) ;
F_28 ( V_13 , ( T_3 ) V_32 ) ;
return 1 ;
}
static int
V_8 ( T_1 * V_2 , const T_4 * * V_34 , const int * * V_35 ,
int V_36 )
{
if ( ! V_34 ) {
* V_35 = V_37 ;
return V_38 ;
}
switch ( V_36 ) {
case V_39 :
* V_34 = F_39 () ;
break;
case V_40 :
* V_34 = F_40 () ;
break;
case V_41 :
* V_34 = F_41 () ;
break;
case V_42 :
* V_34 = F_42 () ;
break;
case V_43 :
* V_34 = F_43 () ;
break;
case V_44 :
* V_34 = F_44 () ;
break;
case V_45 :
* V_34 = F_45 () ;
break;
case V_46 :
* V_34 = F_46 () ;
break;
case V_47 :
* V_34 = F_47 () ;
break;
case V_48 :
* V_34 = F_48 () ;
break;
case V_49 :
* V_34 = F_49 () ;
break;
case V_50 :
* V_34 = F_50 () ;
break;
case V_51 :
* V_34 = F_51 () ;
break;
case V_52 :
* V_34 = F_52 () ;
break;
case V_53 :
* V_34 = F_53 () ;
break;
default:
* V_34 = NULL ;
return 0 ;
}
return 1 ;
}
static int
F_54 ( T_2 * V_13 , const unsigned char * V_54 ,
const unsigned char * V_20 , int V_55 )
{
struct V_17 * V_18 ;
int V_56 = F_55 ( V_13 ) * 8 ;
unsigned long V_57 = F_56 ( V_13 ) ;
if ( V_54 == NULL )
return 0 ;
V_18 = F_20 ( V_13 ) ;
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
if ( V_57 == V_58 || V_57 == V_59 )
V_18 -> V_25 . V_26 . V_27 = 0 ;
else
V_18 -> V_25 . V_26 . V_27 = ( F_27 ( V_13 ) == 0 ) ;
V_18 -> V_25 . V_26 . V_60 = 10 + ( V_56 - 128 ) / 32 ;
V_18 -> V_25 . V_26 . V_61 = ( V_56 - 128 ) / 64 ;
switch ( V_56 ) {
case 128 :
memcpy ( V_18 -> V_62 . V_63 , V_54 , V_64 ) ;
V_18 -> V_25 . V_26 . V_65 = 0 ;
break;
case 192 :
case 256 :
if ( ( V_57 == V_66 || V_57 == V_67 )
&& ! V_55 )
F_57 ( V_54 , V_56 , & V_18 -> V_62 ) ;
else
F_58 ( V_54 , V_56 , & V_18 -> V_62 ) ;
# ifndef F_59
F_60 ( & V_18 -> V_62 ) ;
# endif
V_18 -> V_25 . V_26 . V_65 = 1 ;
break;
default:
return 0 ;
}
F_30 () ;
return 1 ;
}
static int F_61 ( unsigned char * V_68 , int V_69 )
{
unsigned int V_70 , V_71 ;
while ( V_69 >= 8 ) {
V_70 = F_62 ( V_68 , 0 ) ;
if ( ! ( V_70 & ( 1 << 6 ) ) )
return 0 ;
if ( V_70 & ( 0x1F << 10 ) )
return 0 ;
if ( ( V_70 & 0x1F ) == 0 )
continue;
if ( ( V_70 & 0x1F ) != 8 )
return 0 ;
V_68 += 8 ;
V_69 -= 8 ;
}
while ( V_69 > 0 ) {
V_70 = F_62 ( & V_71 , 3 ) ;
if ( ! ( V_70 & ( 1 << 6 ) ) )
return 0 ;
if ( V_70 & ( 0x1F << 10 ) )
return 0 ;
if ( ( V_70 & 0x1F ) == 0 )
continue;
if ( ( V_70 & 0x1F ) != 1 )
return 0 ;
* V_68 ++ = ( unsigned char ) V_71 ;
V_69 -- ;
}
F_63 ( & V_71 , sizeof( V_71 ) ) ;
return 1 ;
}
static int F_64 ( void )
{
return 1 ;
}
T_5
int F_65 ( T_1 * V_2 , const char * V_11 , const T_6 * V_72 )
{
return 0 ;
}
