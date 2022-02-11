static T_1 F_1 ( unsigned long V_1 )
{
return V_1 ;
}
static unsigned long F_2 ( unsigned long V_1 )
{
return V_1 ;
}
static unsigned long F_3 ( T_1 V_2 )
{
return V_2 ;
}
static unsigned int F_4 ( const T_2 * V_3 )
{
return F_5 ( V_3 -> V_4 ) ;
}
static T_1 F_1 ( unsigned long V_1 )
{
return * (struct V_5 * ) V_1 ;
}
static unsigned long F_2 ( unsigned long V_1 )
{
return F_1 ( V_1 ) . V_6 ;
}
static unsigned long F_3 ( T_1 V_2 )
{
return V_2 . V_6 ;
}
static unsigned int F_4 ( const T_2 * V_3 )
{
return 0 ;
}
int F_6 ( struct V_7 * V_8 , unsigned long V_1 ,
unsigned long * V_9 )
{
struct V_10 * V_11 ;
T_1 V_12 ;
T_3 V_13 ;
if ( ! F_7 ( V_1 , V_8 ) ) {
F_8 ( L_1 , V_14 , V_1 , V_8 -> V_15 ) ;
return - V_16 ;
}
V_11 = (struct V_10 * ) V_1 ;
if ( F_9 ( & V_13 , & V_11 -> V_13 , sizeof( V_13 ) ) ) {
F_8 ( L_2 , V_14 , V_1 , V_8 -> V_15 ) ;
return - V_16 ;
}
if ( V_13 != V_17 ) {
F_8 ( L_3 , V_14 , V_1 , V_8 -> V_15 ) ;
return - V_16 ;
}
if ( F_9 ( & V_12 , & V_11 -> V_12 , sizeof( V_12 ) ) ) {
F_8 ( L_4 , V_14 , V_1 , V_8 -> V_15 ) ;
return - V_16 ;
}
* V_9 = F_3 ( V_12 ) ;
return 0 ;
}
static unsigned int F_10 ( const T_4 * V_18 , unsigned int V_19 )
{
unsigned int V_20 , V_21 , V_22 , V_23 ;
V_23 = 0 ;
V_21 = 0 ;
V_22 = 0 ;
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ )
if ( F_11 ( V_18 [ V_20 ] . V_21 ) == V_24 &&
( V_21 != F_12 ( V_18 [ V_20 ] . V_21 ) ||
V_22 != V_18 [ V_20 ] . V_22 ) ) {
V_23 ++ ;
V_21 = F_12 ( V_18 [ V_20 ] . V_21 ) ;
V_22 = V_18 [ V_20 ] . V_22 ;
}
return V_23 ;
}
static int F_13 ( const void * V_25 , const void * V_26 )
{
const T_4 * V_27 , * V_28 ;
V_28 = ( T_4 * ) V_25 ;
V_27 = ( T_4 * ) V_26 ;
if ( V_27 -> V_21 < V_28 -> V_21 )
return - 1 ;
else if ( V_27 -> V_21 > V_28 -> V_21 )
return 1 ;
else if ( V_27 -> V_22 < V_28 -> V_22 )
return - 1 ;
else if ( V_27 -> V_22 > V_28 -> V_22 )
return 1 ;
else
return 0 ;
}
static void F_14 ( void * V_25 , void * V_26 , int V_29 )
{
T_5 * V_27 , * V_28 , V_30 ;
int V_20 ;
V_28 = ( T_5 * ) V_25 ;
V_27 = ( T_5 * ) V_26 ;
for ( V_20 = 0 ; V_20 < sizeof( T_4 ) / sizeof( T_5 ) ; V_20 ++ ) {
V_30 = V_27 [ V_20 ] ;
V_27 [ V_20 ] = V_28 [ V_20 ] ;
V_28 [ V_20 ] = V_30 ;
}
}
static unsigned long F_15 ( const T_6 * V_31 ,
const T_7 * V_32 )
{
unsigned long V_33 = 1 ;
unsigned V_20 ;
for ( V_20 = 1 ; V_20 < V_31 -> V_34 ; V_20 ++ ) {
if ( V_32 [ V_20 ] . V_35 == V_36 ) {
F_16 ( L_5 , V_20 ) ;
F_16 ( L_6 ,
( void * ) V_32 [ V_20 ] . V_37 ,
V_32 [ V_20 ] . V_38 / sizeof( T_4 ) ) ;
F_17 ( ( void * ) V_32 [ V_20 ] . V_37 ,
V_32 [ V_20 ] . V_38 / sizeof( T_4 ) ,
sizeof( T_4 ) , F_13 , F_14 ) ;
V_33 += F_10 ( ( void * ) V_32 [ V_20 ] . V_37 ,
V_32 [ V_20 ] . V_38
/ sizeof( T_4 ) ) ;
}
}
#ifdef F_18
V_33 ++ ;
#endif
F_16 ( L_7 , V_33 ) ;
return V_33 * sizeof( struct V_10 ) ;
}
static void F_19 ( struct V_39 * V_40 ,
unsigned long V_29 )
{
struct V_39 * V_41 ;
for ( V_41 = ( void * ) V_40 + V_29 ; V_40 < V_41 ; V_40 ++ )
if ( V_40 -> V_15 [ 0 ] == '.' ) {
memmove ( V_40 -> V_15 , V_40 -> V_15 + 1 , strlen ( V_40 -> V_15 ) ) ;
#ifdef F_20
if ( ! strcmp ( V_40 -> V_15 , L_8 ) )
V_40 -> V_42 = - ( unsigned long ) V_43 ;
#endif
}
}
static void F_21 ( T_2 * V_44 , unsigned int V_45 , char * V_46 )
{
unsigned int V_20 ;
for ( V_20 = 1 ; V_20 < V_45 ; V_20 ++ ) {
if ( V_44 [ V_20 ] . V_47 == V_48 ) {
char * V_15 = V_46 + V_44 [ V_20 ] . V_49 ;
if ( V_15 [ 0 ] == '.' ) {
if ( strcmp ( V_15 + 1 , L_8 ) == 0 )
V_44 [ V_20 ] . V_47 = V_50 ;
V_44 [ V_20 ] . V_49 ++ ;
}
}
}
}
static T_2 * F_22 ( T_7 * V_32 ,
const char * V_46 ,
unsigned int V_51 )
{
unsigned int V_20 , V_45 ;
T_2 * V_44 ;
V_44 = ( T_2 * ) V_32 [ V_51 ] . V_37 ;
V_45 = V_32 [ V_51 ] . V_38 / sizeof( T_2 ) ;
for ( V_20 = 1 ; V_20 < V_45 ; V_20 ++ ) {
if ( V_44 [ V_20 ] . V_47 == V_50
&& strcmp ( V_46 + V_44 [ V_20 ] . V_49 , L_8 ) == 0 )
return & V_44 [ V_20 ] ;
}
return NULL ;
}
int F_23 ( T_6 * V_31 ,
T_7 * V_32 ,
char * V_52 ,
struct V_7 * V_53 )
{
unsigned int V_20 ;
for ( V_20 = 1 ; V_20 < V_31 -> V_34 ; V_20 ++ ) {
char * V_54 ;
if ( strcmp ( V_52 + V_32 [ V_20 ] . V_55 , L_9 ) == 0 )
V_53 -> V_56 . V_57 = V_20 ;
else if ( strcmp ( V_52 + V_32 [ V_20 ] . V_55 , L_10 ) == 0 )
V_53 -> V_56 . V_58 = V_20 ;
else if ( strcmp ( V_52 + V_32 [ V_20 ] . V_55 , L_11 ) == 0 )
F_19 ( ( void * ) V_31 + V_32 [ V_20 ] . V_59 ,
V_32 [ V_20 ] . V_38 ) ;
while ( ( V_54 = strstr ( V_52 + V_32 [ V_20 ] . V_55 , L_12 ) ) )
V_54 [ 0 ] = '_' ;
if ( V_32 [ V_20 ] . V_35 == V_60 )
F_21 ( ( void * ) V_31 + V_32 [ V_20 ] . V_59 ,
V_32 [ V_20 ] . V_38 / sizeof( T_2 ) ,
( void * ) V_31
+ V_32 [ V_32 [ V_20 ] . V_61 ] . V_59 ) ;
}
if ( ! V_53 -> V_56 . V_57 ) {
F_8 ( L_13 , V_53 -> V_15 ) ;
return - V_62 ;
}
if ( ! V_53 -> V_56 . V_58 )
V_53 -> V_56 . V_58 = V_53 -> V_56 . V_57 ;
V_32 [ V_53 -> V_56 . V_57 ] . V_38 = F_15 ( V_31 , V_32 ) ;
return 0 ;
}
static inline unsigned long F_24 ( const T_7 * V_32 , struct V_7 * V_53 )
{
return V_32 [ V_53 -> V_56 . V_58 ] . V_37 + 0x8000 ;
}
static inline int F_25 ( const T_7 * V_32 ,
struct V_10 * V_63 ,
unsigned long V_1 ,
struct V_7 * V_53 )
{
long V_64 ;
memcpy ( V_63 -> V_65 , V_66 , sizeof( V_66 ) ) ;
V_64 = ( unsigned long ) V_63 - F_24 ( V_32 , V_53 ) ;
if ( V_64 > 0x7FFFFFFF || V_64 < - ( 0x80000000L ) ) {
F_8 ( L_14 ,
V_53 -> V_15 , ( void * ) V_64 , ( void * ) F_24 ) ;
return 0 ;
}
F_16 ( L_15 , V_63 , V_64 ) ;
V_63 -> V_65 [ 0 ] |= F_26 ( V_64 ) ;
V_63 -> V_65 [ 1 ] |= F_27 ( V_64 ) ;
V_63 -> V_12 = F_1 ( V_1 ) ;
V_63 -> V_13 = V_17 ;
return 1 ;
}
static unsigned long F_28 ( const T_7 * V_32 ,
unsigned long V_1 ,
struct V_7 * V_53 )
{
struct V_10 * V_67 ;
unsigned int V_20 , V_68 ;
V_68 = V_32 [ V_53 -> V_56 . V_57 ] . V_38 / sizeof( * V_67 ) ;
V_67 = ( void * ) V_32 [ V_53 -> V_56 . V_57 ] . V_37 ;
for ( V_20 = 0 ; F_3 ( V_67 [ V_20 ] . V_12 ) ; V_20 ++ ) {
F_29 ( V_20 >= V_68 ) ;
if ( F_3 ( V_67 [ V_20 ] . V_12 ) == F_2 ( V_1 ) )
return ( unsigned long ) & V_67 [ V_20 ] ;
}
if ( ! F_25 ( V_32 , & V_67 [ V_20 ] , V_1 , V_53 ) )
return 0 ;
return ( unsigned long ) & V_67 [ V_20 ] ;
}
static bool F_30 ( T_3 * V_69 )
{
if ( V_69 [ - 1 ] == V_70 &&
V_69 [ - 2 ] == V_71 )
return true ;
if ( V_69 [ - 1 ] == V_71 )
return true ;
return false ;
}
static void F_31 ( const char * V_15 , unsigned long V_1 )
{
struct V_10 * V_11 = (struct V_10 * ) V_1 ;
if ( strcmp ( L_16 , V_15 ) != 0 )
return;
V_11 -> V_65 [ 2 ] = V_72 ;
}
static void F_31 ( const char * V_15 , unsigned long V_1 ) { }
static bool F_30 ( T_3 * V_69 )
{
return false ;
}
static int F_32 ( T_3 * V_69 , struct V_7 * V_53 )
{
if ( * V_69 != V_72 ) {
if ( F_30 ( V_69 - 1 ) )
return 1 ;
F_8 ( L_17 ,
V_53 -> V_15 , * V_69 ) ;
return 0 ;
}
* V_69 = V_73 ;
return 1 ;
}
int F_33 ( T_7 * V_32 ,
const char * V_46 ,
unsigned int V_51 ,
unsigned int V_74 ,
struct V_7 * V_53 )
{
unsigned int V_20 ;
T_4 * V_18 = ( void * ) V_32 [ V_74 ] . V_37 ;
T_2 * V_3 ;
unsigned long * V_75 ;
unsigned long V_76 ;
F_16 ( L_18 , V_74 ,
V_32 [ V_74 ] . V_77 ) ;
if ( ! V_53 -> V_56 . V_78 ) {
V_3 = F_22 ( V_32 , V_46 , V_51 ) ;
if ( V_3 )
V_3 -> V_79 = F_24 ( V_32 , V_53 ) ;
V_53 -> V_56 . V_78 = true ;
}
for ( V_20 = 0 ; V_20 < V_32 [ V_74 ] . V_38 / sizeof( * V_18 ) ; V_20 ++ ) {
V_75 = ( void * ) V_32 [ V_32 [ V_74 ] . V_77 ] . V_37
+ V_18 [ V_20 ] . V_80 ;
V_3 = ( T_2 * ) V_32 [ V_51 ] . V_37
+ F_12 ( V_18 [ V_20 ] . V_21 ) ;
F_16 ( L_19 ,
V_75 , ( long ) F_11 ( V_18 [ V_20 ] . V_21 ) ,
V_46 + V_3 -> V_49 , ( unsigned long ) V_3 -> V_79 ,
( long ) V_18 [ V_20 ] . V_22 ) ;
V_76 = V_3 -> V_79 + V_18 [ V_20 ] . V_22 ;
switch ( F_11 ( V_18 [ V_20 ] . V_21 ) ) {
case V_81 :
* ( T_3 * ) V_75 = V_76 ;
break;
case V_82 :
* ( unsigned long * ) V_75 = V_76 ;
break;
case V_83 :
* ( unsigned long * ) V_75 = F_24 ( V_32 , V_53 ) ;
break;
case V_84 :
V_76 -= F_24 ( V_32 , V_53 ) ;
if ( V_76 + 0x8000 > 0xffff ) {
F_8 ( L_20 ,
V_53 -> V_15 , V_76 ) ;
return - V_62 ;
}
* ( ( V_85 * ) V_75 )
= ( * ( ( V_85 * ) V_75 ) & ~ 0xffff )
| ( V_76 & 0xffff ) ;
break;
case V_86 :
V_76 -= F_24 ( V_32 , V_53 ) ;
* ( ( V_85 * ) V_75 )
= ( * ( ( V_85 * ) V_75 ) & ~ 0xffff )
| ( V_76 & 0xffff ) ;
break;
case V_87 :
V_76 -= F_24 ( V_32 , V_53 ) ;
if ( ( V_76 & 3 ) != 0 || V_76 + 0x8000 > 0xffff ) {
F_8 ( L_21 ,
V_53 -> V_15 , V_76 ) ;
return - V_62 ;
}
* ( ( V_85 * ) V_75 )
= ( * ( ( V_85 * ) V_75 ) & ~ 0xfffc )
| ( V_76 & 0xfffc ) ;
break;
case V_88 :
V_76 -= F_24 ( V_32 , V_53 ) ;
if ( ( V_76 & 3 ) != 0 ) {
F_8 ( L_22 ,
V_53 -> V_15 , V_76 ) ;
return - V_62 ;
}
* ( ( V_85 * ) V_75 )
= ( * ( ( V_85 * ) V_75 ) & ~ 0xfffc )
| ( V_76 & 0xfffc ) ;
break;
case V_89 :
V_76 -= F_24 ( V_32 , V_53 ) ;
V_76 = ( ( V_76 + 0x8000 ) >> 16 ) ;
* ( ( V_85 * ) V_75 )
= ( * ( ( V_85 * ) V_75 ) & ~ 0xffff )
| ( V_76 & 0xffff ) ;
break;
case V_24 :
if ( V_3 -> V_47 == V_48 ) {
V_76 = F_28 ( V_32 , V_76 , V_53 ) ;
if ( ! V_76 )
return - V_90 ;
if ( ! F_32 ( ( T_3 * ) V_75 + 1 , V_53 ) )
return - V_62 ;
F_31 ( V_46 + V_3 -> V_49 , V_76 ) ;
} else
V_76 += F_4 ( V_3 ) ;
V_76 -= ( unsigned long ) V_75 ;
if ( V_76 + 0x2000000 > 0x3ffffff || ( V_76 & 3 ) != 0 ) {
F_8 ( L_23 ,
V_53 -> V_15 , ( long int ) V_76 ) ;
return - V_62 ;
}
* ( V_91 * ) V_75
= ( * ( V_91 * ) V_75 & ~ 0x03fffffc )
| ( V_76 & 0x03fffffc ) ;
break;
case V_92 :
* V_75 = V_76 - ( unsigned long ) V_75 ;
break;
case V_93 :
break;
case V_94 :
V_76 = F_24 ( V_32 , V_53 ) - ( unsigned long ) V_75 ;
if ( V_76 + 0x80008000 > 0xffffffff )
break;
if ( ( ( ( V_91 * ) V_75 ) [ 0 ] & ~ 0xfffc )
!= 0xe84c0000 )
break;
if ( ( ( V_91 * ) V_75 ) [ 1 ] != 0x7c426214 )
break;
( ( V_91 * ) V_75 ) [ 0 ] = 0x3c4c0000 + F_26 ( V_76 ) ;
( ( V_91 * ) V_75 ) [ 1 ] = 0x38420000 + F_27 ( V_76 ) ;
break;
case V_95 :
V_76 -= ( unsigned long ) V_75 ;
V_76 = ( ( V_76 + 0x8000 ) >> 16 ) ;
* ( ( V_85 * ) V_75 )
= ( * ( ( V_85 * ) V_75 ) & ~ 0xffff )
| ( V_76 & 0xffff ) ;
break;
case V_96 :
V_76 -= ( unsigned long ) V_75 ;
* ( ( V_85 * ) V_75 )
= ( * ( ( V_85 * ) V_75 ) & ~ 0xffff )
| ( V_76 & 0xffff ) ;
break;
default:
F_8 ( L_24 ,
V_53 -> V_15 ,
( unsigned long ) F_11 ( V_18 [ V_20 ] . V_21 ) ) ;
return - V_62 ;
}
}
return 0 ;
}
static unsigned long F_34 ( const T_7 * V_32 , struct V_7 * V_53 )
{
struct V_10 * V_63 ;
unsigned int V_20 , V_68 ;
static T_3 V_97 [] = {
0xe98d0000 | V_98 ,
0x3d8c0000 ,
0x398c0000 ,
0x7d8903a6 ,
0x4e800420 ,
} ;
long V_64 ;
V_68 = V_32 [ V_53 -> V_56 . V_57 ] . V_38 / sizeof( * V_63 ) ;
V_63 = ( void * ) V_32 [ V_53 -> V_56 . V_57 ] . V_37 ;
for ( V_20 = 0 ; V_20 < V_68 && F_3 ( V_63 -> V_12 ) ; V_20 ++ , V_63 ++ ) ;
if ( V_20 >= V_68 ) {
F_8 ( L_25 , V_53 -> V_15 ) ;
return 0 ;
}
memcpy ( V_63 -> V_65 , V_97 , sizeof( V_97 ) ) ;
V_64 = ( unsigned long ) V_99 - F_35 () ;
if ( V_64 > 0x7FFFFFFF || V_64 < - ( 0x80000000L ) ) {
F_8 ( L_26 , V_53 -> V_15 ) ;
return 0 ;
}
V_63 -> V_65 [ 1 ] |= F_26 ( V_64 ) ;
V_63 -> V_65 [ 2 ] |= F_27 ( V_64 ) ;
V_63 -> V_12 = F_1 ( ( unsigned long ) V_99 ) ;
V_63 -> V_13 = V_17 ;
return ( unsigned long ) V_63 ;
}
static unsigned long F_34 ( const T_7 * V_32 , struct V_7 * V_53 )
{
return F_28 ( V_32 , ( unsigned long ) V_99 , V_53 ) ;
}
int F_36 ( struct V_7 * V_8 , const T_8 * V_32 )
{
V_8 -> V_56 . V_100 = F_24 ( V_32 , V_8 ) ;
V_8 -> V_56 . V_101 = F_34 ( V_32 , V_8 ) ;
if ( ! V_8 -> V_56 . V_101 )
return - V_90 ;
return 0 ;
}
