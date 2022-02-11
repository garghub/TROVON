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
}
}
static void F_20 ( T_2 * V_42 , unsigned int V_43 , char * V_44 )
{
unsigned int V_20 ;
for ( V_20 = 1 ; V_20 < V_43 ; V_20 ++ ) {
if ( V_42 [ V_20 ] . V_45 == V_46 ) {
char * V_15 = V_44 + V_42 [ V_20 ] . V_47 ;
if ( V_15 [ 0 ] == '.' ) {
if ( strcmp ( V_15 + 1 , L_8 ) == 0 )
V_42 [ V_20 ] . V_45 = V_48 ;
V_42 [ V_20 ] . V_47 ++ ;
}
}
}
}
static T_2 * F_21 ( T_7 * V_32 ,
const char * V_44 ,
unsigned int V_49 )
{
unsigned int V_20 , V_43 ;
T_2 * V_42 ;
V_42 = ( T_2 * ) V_32 [ V_49 ] . V_37 ;
V_43 = V_32 [ V_49 ] . V_38 / sizeof( T_2 ) ;
for ( V_20 = 1 ; V_20 < V_43 ; V_20 ++ ) {
if ( V_42 [ V_20 ] . V_45 == V_48
&& strcmp ( V_44 + V_42 [ V_20 ] . V_47 , L_8 ) == 0 )
return & V_42 [ V_20 ] ;
}
return NULL ;
}
int F_22 ( T_6 * V_31 ,
T_7 * V_32 ,
char * V_50 ,
struct V_7 * V_51 )
{
unsigned int V_20 ;
for ( V_20 = 1 ; V_20 < V_31 -> V_34 ; V_20 ++ ) {
char * V_52 ;
if ( strcmp ( V_50 + V_32 [ V_20 ] . V_53 , L_9 ) == 0 )
V_51 -> V_54 . V_55 = V_20 ;
else if ( strcmp ( V_50 + V_32 [ V_20 ] . V_53 , L_10 ) == 0 )
V_51 -> V_54 . V_56 = V_20 ;
else if ( strcmp ( V_50 + V_32 [ V_20 ] . V_53 , L_11 ) == 0 )
F_19 ( ( void * ) V_31 + V_32 [ V_20 ] . V_57 ,
V_32 [ V_20 ] . V_38 ) ;
while ( ( V_52 = strstr ( V_50 + V_32 [ V_20 ] . V_53 , L_12 ) ) )
V_52 [ 0 ] = '_' ;
if ( V_32 [ V_20 ] . V_35 == V_58 )
F_20 ( ( void * ) V_31 + V_32 [ V_20 ] . V_57 ,
V_32 [ V_20 ] . V_38 / sizeof( T_2 ) ,
( void * ) V_31
+ V_32 [ V_32 [ V_20 ] . V_59 ] . V_57 ) ;
}
if ( ! V_51 -> V_54 . V_55 ) {
F_8 ( L_13 , V_51 -> V_15 ) ;
return - V_60 ;
}
if ( ! V_51 -> V_54 . V_56 )
V_51 -> V_54 . V_56 = V_51 -> V_54 . V_55 ;
V_32 [ V_51 -> V_54 . V_55 ] . V_38 = F_15 ( V_31 , V_32 ) ;
return 0 ;
}
static inline unsigned long F_23 ( const T_7 * V_32 , struct V_7 * V_51 )
{
return V_32 [ V_51 -> V_54 . V_56 ] . V_37 + 0x8000 ;
}
static inline int F_24 ( const T_7 * V_32 ,
struct V_10 * V_61 ,
unsigned long V_1 ,
struct V_7 * V_51 )
{
long V_62 ;
memcpy ( V_61 -> V_63 , V_64 , sizeof( V_64 ) ) ;
V_62 = ( unsigned long ) V_61 - F_23 ( V_32 , V_51 ) ;
if ( V_62 > 0x7FFFFFFF || V_62 < - ( 0x80000000L ) ) {
F_8 ( L_14 ,
V_51 -> V_15 , ( void * ) V_62 , ( void * ) F_23 ) ;
return 0 ;
}
F_16 ( L_15 , V_61 , V_62 ) ;
V_61 -> V_63 [ 0 ] |= F_25 ( V_62 ) ;
V_61 -> V_63 [ 1 ] |= F_26 ( V_62 ) ;
V_61 -> V_12 = F_1 ( V_1 ) ;
V_61 -> V_13 = V_17 ;
return 1 ;
}
static unsigned long F_27 ( const T_7 * V_32 ,
unsigned long V_1 ,
struct V_7 * V_51 )
{
struct V_10 * V_65 ;
unsigned int V_20 , V_66 ;
V_66 = V_32 [ V_51 -> V_54 . V_55 ] . V_38 / sizeof( * V_65 ) ;
V_65 = ( void * ) V_32 [ V_51 -> V_54 . V_55 ] . V_37 ;
for ( V_20 = 0 ; F_3 ( V_65 [ V_20 ] . V_12 ) ; V_20 ++ ) {
F_28 ( V_20 >= V_66 ) ;
if ( F_3 ( V_65 [ V_20 ] . V_12 ) == F_2 ( V_1 ) )
return ( unsigned long ) & V_65 [ V_20 ] ;
}
if ( ! F_24 ( V_32 , & V_65 [ V_20 ] , V_1 , V_51 ) )
return 0 ;
return ( unsigned long ) & V_65 [ V_20 ] ;
}
static bool F_29 ( T_3 * V_67 )
{
if ( V_67 [ - 1 ] == V_68 &&
V_67 [ - 2 ] == V_69 )
return true ;
if ( V_67 [ - 1 ] == V_69 )
return true ;
return false ;
}
static void F_30 ( const char * V_15 , unsigned long V_1 )
{
struct V_10 * V_11 = (struct V_10 * ) V_1 ;
if ( strcmp ( L_16 , V_15 ) != 0 )
return;
V_11 -> V_63 [ 2 ] = V_70 ;
}
static void F_30 ( const char * V_15 , unsigned long V_1 ) { }
static bool F_29 ( T_3 * V_67 )
{
return false ;
}
static int F_31 ( T_3 * V_67 , struct V_7 * V_51 )
{
if ( F_29 ( V_67 - 1 ) )
return 1 ;
if ( * V_67 != V_70 ) {
F_8 ( L_17 ,
V_51 -> V_15 , * V_67 ) ;
return 0 ;
}
* V_67 = V_71 ;
return 1 ;
}
int F_32 ( T_7 * V_32 ,
const char * V_44 ,
unsigned int V_49 ,
unsigned int V_72 ,
struct V_7 * V_51 )
{
unsigned int V_20 ;
T_4 * V_18 = ( void * ) V_32 [ V_72 ] . V_37 ;
T_2 * V_3 ;
unsigned long * V_73 ;
unsigned long V_74 ;
F_16 ( L_18 , V_72 ,
V_32 [ V_72 ] . V_75 ) ;
if ( ! V_51 -> V_54 . V_76 ) {
V_3 = F_21 ( V_32 , V_44 , V_49 ) ;
if ( V_3 )
V_3 -> V_77 = F_23 ( V_32 , V_51 ) ;
V_51 -> V_54 . V_76 = true ;
}
for ( V_20 = 0 ; V_20 < V_32 [ V_72 ] . V_38 / sizeof( * V_18 ) ; V_20 ++ ) {
V_73 = ( void * ) V_32 [ V_32 [ V_72 ] . V_75 ] . V_37
+ V_18 [ V_20 ] . V_78 ;
V_3 = ( T_2 * ) V_32 [ V_49 ] . V_37
+ F_12 ( V_18 [ V_20 ] . V_21 ) ;
F_16 ( L_19 ,
V_73 , ( long ) F_11 ( V_18 [ V_20 ] . V_21 ) ,
V_44 + V_3 -> V_47 , ( unsigned long ) V_3 -> V_77 ,
( long ) V_18 [ V_20 ] . V_22 ) ;
V_74 = V_3 -> V_77 + V_18 [ V_20 ] . V_22 ;
switch ( F_11 ( V_18 [ V_20 ] . V_21 ) ) {
case V_79 :
* ( T_3 * ) V_73 = V_74 ;
break;
case V_80 :
* ( unsigned long * ) V_73 = V_74 ;
break;
case V_81 :
* ( unsigned long * ) V_73 = F_23 ( V_32 , V_51 ) ;
break;
case V_82 :
V_74 -= F_23 ( V_32 , V_51 ) ;
if ( V_74 + 0x8000 > 0xffff ) {
F_8 ( L_20 ,
V_51 -> V_15 , V_74 ) ;
return - V_60 ;
}
* ( ( V_83 * ) V_73 )
= ( * ( ( V_83 * ) V_73 ) & ~ 0xffff )
| ( V_74 & 0xffff ) ;
break;
case V_84 :
V_74 -= F_23 ( V_32 , V_51 ) ;
* ( ( V_83 * ) V_73 )
= ( * ( ( V_83 * ) V_73 ) & ~ 0xffff )
| ( V_74 & 0xffff ) ;
break;
case V_85 :
V_74 -= F_23 ( V_32 , V_51 ) ;
if ( ( V_74 & 3 ) != 0 || V_74 + 0x8000 > 0xffff ) {
F_8 ( L_21 ,
V_51 -> V_15 , V_74 ) ;
return - V_60 ;
}
* ( ( V_83 * ) V_73 )
= ( * ( ( V_83 * ) V_73 ) & ~ 0xfffc )
| ( V_74 & 0xfffc ) ;
break;
case V_86 :
V_74 -= F_23 ( V_32 , V_51 ) ;
if ( ( V_74 & 3 ) != 0 ) {
F_8 ( L_22 ,
V_51 -> V_15 , V_74 ) ;
return - V_60 ;
}
* ( ( V_83 * ) V_73 )
= ( * ( ( V_83 * ) V_73 ) & ~ 0xfffc )
| ( V_74 & 0xfffc ) ;
break;
case V_87 :
V_74 -= F_23 ( V_32 , V_51 ) ;
V_74 = ( ( V_74 + 0x8000 ) >> 16 ) ;
* ( ( V_83 * ) V_73 )
= ( * ( ( V_83 * ) V_73 ) & ~ 0xffff )
| ( V_74 & 0xffff ) ;
break;
case V_24 :
if ( V_3 -> V_45 == V_46 ) {
V_74 = F_27 ( V_32 , V_74 , V_51 ) ;
if ( ! V_74 )
return - V_88 ;
if ( ! F_31 ( ( T_3 * ) V_73 + 1 , V_51 ) )
return - V_60 ;
F_30 ( V_44 + V_3 -> V_47 , V_74 ) ;
} else
V_74 += F_4 ( V_3 ) ;
V_74 -= ( unsigned long ) V_73 ;
if ( V_74 + 0x2000000 > 0x3ffffff || ( V_74 & 3 ) != 0 ) {
F_8 ( L_23 ,
V_51 -> V_15 , ( long int ) V_74 ) ;
return - V_60 ;
}
* ( V_89 * ) V_73
= ( * ( V_89 * ) V_73 & ~ 0x03fffffc )
| ( V_74 & 0x03fffffc ) ;
break;
case V_90 :
* V_73 = V_74 - ( unsigned long ) V_73 ;
break;
case V_91 :
* ( T_3 * ) V_73 = V_74 - ( unsigned long ) V_73 ;
break;
case V_92 :
break;
case V_93 :
V_74 = F_23 ( V_32 , V_51 ) - ( unsigned long ) V_73 ;
if ( V_74 + 0x80008000 > 0xffffffff )
break;
if ( ( ( ( V_89 * ) V_73 ) [ 0 ] & ~ 0xfffc )
!= 0xe84c0000 )
break;
if ( ( ( V_89 * ) V_73 ) [ 1 ] != 0x7c426214 )
break;
( ( V_89 * ) V_73 ) [ 0 ] = 0x3c4c0000 + F_25 ( V_74 ) ;
( ( V_89 * ) V_73 ) [ 1 ] = 0x38420000 + F_26 ( V_74 ) ;
break;
case V_94 :
V_74 -= ( unsigned long ) V_73 ;
V_74 = ( ( V_74 + 0x8000 ) >> 16 ) ;
* ( ( V_83 * ) V_73 )
= ( * ( ( V_83 * ) V_73 ) & ~ 0xffff )
| ( V_74 & 0xffff ) ;
break;
case V_95 :
V_74 -= ( unsigned long ) V_73 ;
* ( ( V_83 * ) V_73 )
= ( * ( ( V_83 * ) V_73 ) & ~ 0xffff )
| ( V_74 & 0xffff ) ;
break;
default:
F_8 ( L_24 ,
V_51 -> V_15 ,
( unsigned long ) F_11 ( V_18 [ V_20 ] . V_21 ) ) ;
return - V_60 ;
}
}
return 0 ;
}
static unsigned long F_33 ( const T_7 * V_32 , struct V_7 * V_51 )
{
struct V_10 * V_61 ;
unsigned int V_20 , V_66 ;
static T_3 V_96 [] = {
0xe98d0000 | V_97 ,
0x3d8c0000 ,
0x398c0000 ,
0x7d8903a6 ,
0x4e800420 ,
} ;
long V_62 ;
V_66 = V_32 [ V_51 -> V_54 . V_55 ] . V_38 / sizeof( * V_61 ) ;
V_61 = ( void * ) V_32 [ V_51 -> V_54 . V_55 ] . V_37 ;
for ( V_20 = 0 ; V_20 < V_66 && F_3 ( V_61 -> V_12 ) ; V_20 ++ , V_61 ++ ) ;
if ( V_20 >= V_66 ) {
F_8 ( L_25 , V_51 -> V_15 ) ;
return 0 ;
}
memcpy ( V_61 -> V_63 , V_96 , sizeof( V_96 ) ) ;
V_62 = ( unsigned long ) V_98 - F_34 () ;
if ( V_62 > 0x7FFFFFFF || V_62 < - ( 0x80000000L ) ) {
F_8 ( L_26 , V_51 -> V_15 ) ;
return 0 ;
}
V_61 -> V_63 [ 1 ] |= F_25 ( V_62 ) ;
V_61 -> V_63 [ 2 ] |= F_26 ( V_62 ) ;
V_61 -> V_12 = F_1 ( ( unsigned long ) V_98 ) ;
V_61 -> V_13 = V_17 ;
return ( unsigned long ) V_61 ;
}
static unsigned long F_33 ( const T_7 * V_32 , struct V_7 * V_51 )
{
return F_27 ( V_32 , ( unsigned long ) V_98 , V_51 ) ;
}
int F_35 ( struct V_7 * V_8 , const T_8 * V_32 )
{
V_8 -> V_54 . V_99 = F_23 ( V_32 , V_8 ) ;
V_8 -> V_54 . V_100 = F_33 ( V_32 , V_8 ) ;
if ( ! V_8 -> V_54 . V_100 )
return - V_88 ;
return 0 ;
}
