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
bool F_6 ( T_3 * V_7 )
{
unsigned int V_8 ;
T_3 V_9 [ F_7 ( V_10 ) ] ;
F_8 ( sizeof( V_10 ) != sizeof( V_11 ) ) ;
if ( F_9 ( V_9 , V_7 , sizeof( V_9 ) ) )
return - V_12 ;
for ( V_8 = 0 ; V_8 < F_7 ( V_10 ) ; V_8 ++ ) {
T_3 V_13 = V_9 [ V_8 ] ;
T_3 V_14 = V_10 [ V_8 ] ;
T_3 V_15 = V_11 [ V_8 ] ;
if ( ( V_13 & V_15 ) != ( V_14 & V_15 ) )
return false ;
}
return true ;
}
int F_10 ( struct V_16 * V_17 , T_3 * V_18 ,
unsigned long * V_19 )
{
T_3 V_20 [ 2 ] ;
T_4 V_21 , V_22 ;
long V_23 ;
void * V_24 ;
if ( F_9 ( V_20 , V_18 , sizeof( V_20 ) ) )
return - V_12 ;
V_21 = V_20 [ 0 ] & 0xffff ;
V_22 = V_20 [ 1 ] & 0xffff ;
V_23 = ( ( short ) V_21 << 16 ) + ( short ) V_22 ;
V_24 = ( void * ) V_17 -> V_25 . V_26 + V_23 + 32 ;
if ( F_9 ( V_19 , V_24 , sizeof( * V_19 ) ) )
return - V_12 ;
return 0 ;
}
static unsigned int F_11 ( const T_5 * V_27 , unsigned int V_28 )
{
unsigned int V_8 , V_29 , V_30 , V_31 ;
V_31 = 0 ;
V_29 = 0 ;
V_30 = 0 ;
for ( V_8 = 0 ; V_8 < V_28 ; V_8 ++ )
if ( F_12 ( V_27 [ V_8 ] . V_29 ) == V_32 &&
( V_29 != F_13 ( V_27 [ V_8 ] . V_29 ) ||
V_30 != V_27 [ V_8 ] . V_30 ) ) {
V_31 ++ ;
V_29 = F_13 ( V_27 [ V_8 ] . V_29 ) ;
V_30 = V_27 [ V_8 ] . V_30 ;
}
return V_31 ;
}
static int F_14 ( const void * V_33 , const void * V_34 )
{
const T_5 * V_35 , * V_36 ;
V_36 = ( T_5 * ) V_33 ;
V_35 = ( T_5 * ) V_34 ;
if ( V_35 -> V_29 < V_36 -> V_29 )
return - 1 ;
else if ( V_35 -> V_29 > V_36 -> V_29 )
return 1 ;
else if ( V_35 -> V_30 < V_36 -> V_30 )
return - 1 ;
else if ( V_35 -> V_30 > V_36 -> V_30 )
return 1 ;
else
return 0 ;
}
static void F_15 ( void * V_33 , void * V_34 , int V_37 )
{
T_6 * V_35 , * V_36 , V_38 ;
int V_8 ;
V_36 = ( T_6 * ) V_33 ;
V_35 = ( T_6 * ) V_34 ;
for ( V_8 = 0 ; V_8 < sizeof( T_5 ) / sizeof( T_6 ) ; V_8 ++ ) {
V_38 = V_35 [ V_8 ] ;
V_35 [ V_8 ] = V_36 [ V_8 ] ;
V_36 [ V_8 ] = V_38 ;
}
}
static unsigned long F_16 ( const T_7 * V_39 ,
const T_8 * V_40 )
{
unsigned long V_41 = 1 ;
unsigned V_8 ;
for ( V_8 = 1 ; V_8 < V_39 -> V_42 ; V_8 ++ ) {
if ( V_40 [ V_8 ] . V_43 == V_44 ) {
F_17 ( L_1 , V_8 ) ;
F_17 ( L_2 ,
( void * ) V_40 [ V_8 ] . V_45 ,
V_40 [ V_8 ] . V_46 / sizeof( T_5 ) ) ;
F_18 ( ( void * ) V_40 [ V_8 ] . V_45 ,
V_40 [ V_8 ] . V_46 / sizeof( T_5 ) ,
sizeof( T_5 ) , F_14 , F_15 ) ;
V_41 += F_11 ( ( void * ) V_40 [ V_8 ] . V_45 ,
V_40 [ V_8 ] . V_46
/ sizeof( T_5 ) ) ;
}
}
#ifdef F_19
V_41 ++ ;
#endif
F_17 ( L_3 , V_41 ) ;
return V_41 * sizeof( struct V_47 ) ;
}
static void F_20 ( struct V_48 * V_49 ,
unsigned long V_37 )
{
struct V_48 * V_50 ;
for ( V_50 = ( void * ) V_49 + V_37 ; V_49 < V_50 ; V_49 ++ )
if ( V_49 -> V_51 [ 0 ] == '.' ) {
memmove ( V_49 -> V_51 , V_49 -> V_51 + 1 , strlen ( V_49 -> V_51 ) ) ;
#ifdef F_21
if ( ! strcmp ( V_49 -> V_51 , L_4 ) )
V_49 -> V_52 = - ( unsigned long ) V_53 ;
#endif
}
}
static void F_22 ( T_2 * V_54 , unsigned int V_55 , char * V_56 )
{
unsigned int V_8 ;
for ( V_8 = 1 ; V_8 < V_55 ; V_8 ++ ) {
if ( V_54 [ V_8 ] . V_57 == V_58 ) {
char * V_51 = V_56 + V_54 [ V_8 ] . V_59 ;
if ( V_51 [ 0 ] == '.' )
memmove ( V_51 , V_51 + 1 , strlen ( V_51 ) ) ;
}
}
}
static T_2 * F_23 ( T_8 * V_40 ,
const char * V_56 ,
unsigned int V_60 )
{
unsigned int V_8 , V_55 ;
T_2 * V_54 ;
V_54 = ( T_2 * ) V_40 [ V_60 ] . V_45 ;
V_55 = V_40 [ V_60 ] . V_46 / sizeof( T_2 ) ;
for ( V_8 = 1 ; V_8 < V_55 ; V_8 ++ ) {
if ( V_54 [ V_8 ] . V_57 == V_58
&& strcmp ( V_56 + V_54 [ V_8 ] . V_59 , L_4 ) == 0 )
return & V_54 [ V_8 ] ;
}
return NULL ;
}
int F_24 ( T_7 * V_39 ,
T_8 * V_40 ,
char * V_61 ,
struct V_16 * V_62 )
{
unsigned int V_8 ;
for ( V_8 = 1 ; V_8 < V_39 -> V_42 ; V_8 ++ ) {
char * V_7 ;
if ( strcmp ( V_61 + V_40 [ V_8 ] . V_63 , L_5 ) == 0 )
V_62 -> V_25 . V_64 = V_8 ;
else if ( strcmp ( V_61 + V_40 [ V_8 ] . V_63 , L_6 ) == 0 )
V_62 -> V_25 . V_65 = V_8 ;
else if ( strcmp ( V_61 + V_40 [ V_8 ] . V_63 , L_7 ) == 0 )
F_20 ( ( void * ) V_39 + V_40 [ V_8 ] . V_66 ,
V_40 [ V_8 ] . V_46 ) ;
while ( ( V_7 = strstr ( V_61 + V_40 [ V_8 ] . V_63 , L_8 ) ) )
V_7 [ 0 ] = '_' ;
if ( V_40 [ V_8 ] . V_43 == V_67 )
F_22 ( ( void * ) V_39 + V_40 [ V_8 ] . V_66 ,
V_40 [ V_8 ] . V_46 / sizeof( T_2 ) ,
( void * ) V_39
+ V_40 [ V_40 [ V_8 ] . V_68 ] . V_66 ) ;
}
if ( ! V_62 -> V_25 . V_64 ) {
F_25 ( L_9 , V_62 -> V_51 ) ;
return - V_69 ;
}
if ( ! V_62 -> V_25 . V_65 )
V_62 -> V_25 . V_65 = V_62 -> V_25 . V_64 ;
V_40 [ V_62 -> V_25 . V_64 ] . V_46 = F_16 ( V_39 , V_40 ) ;
return 0 ;
}
static inline unsigned long F_26 ( T_8 * V_40 , struct V_16 * V_62 )
{
return V_40 [ V_62 -> V_25 . V_65 ] . V_45 + 0x8000 ;
}
static inline int F_27 ( T_8 * V_40 ,
struct V_47 * V_70 ,
unsigned long V_1 ,
struct V_16 * V_62 )
{
long V_71 ;
memcpy ( V_70 -> V_72 , V_10 , sizeof( V_10 ) ) ;
V_71 = ( unsigned long ) V_70 - F_26 ( V_40 , V_62 ) ;
if ( V_71 > 0x7FFFFFFF || V_71 < - ( 0x80000000L ) ) {
F_25 ( L_10 ,
V_62 -> V_51 , ( void * ) V_71 , ( void * ) F_26 ) ;
return 0 ;
}
F_17 ( L_11 , V_70 , V_71 ) ;
V_70 -> V_72 [ 0 ] |= F_28 ( V_71 ) ;
V_70 -> V_72 [ 1 ] |= F_29 ( V_71 ) ;
V_70 -> V_73 = F_1 ( V_1 ) ;
return 1 ;
}
static unsigned long F_30 ( T_8 * V_40 ,
unsigned long V_1 ,
struct V_16 * V_62 )
{
struct V_47 * V_74 ;
unsigned int V_8 , V_75 ;
V_75 = V_40 [ V_62 -> V_25 . V_64 ] . V_46 / sizeof( * V_74 ) ;
V_74 = ( void * ) V_40 [ V_62 -> V_25 . V_64 ] . V_45 ;
for ( V_8 = 0 ; F_3 ( V_74 [ V_8 ] . V_73 ) ; V_8 ++ ) {
F_31 ( V_8 >= V_75 ) ;
if ( F_3 ( V_74 [ V_8 ] . V_73 ) == F_2 ( V_1 ) )
return ( unsigned long ) & V_74 [ V_8 ] ;
}
if ( ! F_27 ( V_40 , & V_74 [ V_8 ] , V_1 , V_62 ) )
return 0 ;
return ( unsigned long ) & V_74 [ V_8 ] ;
}
static int F_32 ( T_3 * V_76 , struct V_16 * V_62 )
{
if ( * V_76 != V_77 ) {
F_25 ( L_12 ,
V_62 -> V_51 , * V_76 ) ;
return 0 ;
}
* V_76 = 0xe8410000 | V_78 ;
return 1 ;
}
int F_33 ( T_8 * V_40 ,
const char * V_56 ,
unsigned int V_60 ,
unsigned int V_79 ,
struct V_16 * V_62 )
{
unsigned int V_8 ;
T_5 * V_27 = ( void * ) V_40 [ V_79 ] . V_45 ;
T_2 * V_3 ;
unsigned long * V_80 ;
unsigned long V_81 ;
F_17 ( L_13 , V_79 ,
V_40 [ V_79 ] . V_82 ) ;
if ( ! V_62 -> V_25 . V_83 ) {
V_3 = F_23 ( V_40 , V_56 , V_60 ) ;
if ( V_3 )
V_3 -> V_84 = F_26 ( V_40 , V_62 ) ;
V_62 -> V_25 . V_83 = true ;
}
for ( V_8 = 0 ; V_8 < V_40 [ V_79 ] . V_46 / sizeof( * V_27 ) ; V_8 ++ ) {
V_80 = ( void * ) V_40 [ V_40 [ V_79 ] . V_82 ] . V_45
+ V_27 [ V_8 ] . V_85 ;
V_3 = ( T_2 * ) V_40 [ V_60 ] . V_45
+ F_13 ( V_27 [ V_8 ] . V_29 ) ;
F_17 ( L_14 ,
V_80 , ( long ) F_12 ( V_27 [ V_8 ] . V_29 ) ,
V_56 + V_3 -> V_59 , ( unsigned long ) V_3 -> V_84 ,
( long ) V_27 [ V_8 ] . V_30 ) ;
V_81 = V_3 -> V_84 + V_27 [ V_8 ] . V_30 ;
switch ( F_12 ( V_27 [ V_8 ] . V_29 ) ) {
case V_86 :
* ( T_3 * ) V_80 = V_81 ;
break;
case V_87 :
* ( unsigned long * ) V_80 = V_81 ;
break;
case V_88 :
* ( unsigned long * ) V_80 = F_26 ( V_40 , V_62 ) ;
break;
case V_89 :
V_81 -= F_26 ( V_40 , V_62 ) ;
if ( V_81 + 0x8000 > 0xffff ) {
F_25 ( L_15 ,
V_62 -> V_51 , V_81 ) ;
return - V_69 ;
}
* ( ( V_90 * ) V_80 )
= ( * ( ( V_90 * ) V_80 ) & ~ 0xffff )
| ( V_81 & 0xffff ) ;
break;
case V_91 :
V_81 -= F_26 ( V_40 , V_62 ) ;
* ( ( V_90 * ) V_80 )
= ( * ( ( V_90 * ) V_80 ) & ~ 0xffff )
| ( V_81 & 0xffff ) ;
break;
case V_92 :
V_81 -= F_26 ( V_40 , V_62 ) ;
if ( ( V_81 & 3 ) != 0 || V_81 + 0x8000 > 0xffff ) {
F_25 ( L_16 ,
V_62 -> V_51 , V_81 ) ;
return - V_69 ;
}
* ( ( V_90 * ) V_80 )
= ( * ( ( V_90 * ) V_80 ) & ~ 0xfffc )
| ( V_81 & 0xfffc ) ;
break;
case V_93 :
V_81 -= F_26 ( V_40 , V_62 ) ;
if ( ( V_81 & 3 ) != 0 ) {
F_25 ( L_17 ,
V_62 -> V_51 , V_81 ) ;
return - V_69 ;
}
* ( ( V_90 * ) V_80 )
= ( * ( ( V_90 * ) V_80 ) & ~ 0xfffc )
| ( V_81 & 0xfffc ) ;
break;
case V_94 :
V_81 -= F_26 ( V_40 , V_62 ) ;
V_81 = ( ( V_81 + 0x8000 ) >> 16 ) ;
* ( ( V_90 * ) V_80 )
= ( * ( ( V_90 * ) V_80 ) & ~ 0xffff )
| ( V_81 & 0xffff ) ;
break;
case V_32 :
if ( V_3 -> V_57 == V_58 ) {
V_81 = F_30 ( V_40 , V_81 , V_62 ) ;
if ( ! V_81 )
return - V_95 ;
if ( ! F_32 ( ( T_3 * ) V_80 + 1 , V_62 ) )
return - V_69 ;
} else
V_81 += F_4 ( V_3 ) ;
V_81 -= ( unsigned long ) V_80 ;
if ( V_81 + 0x2000000 > 0x3ffffff || ( V_81 & 3 ) != 0 ) {
F_25 ( L_18 ,
V_62 -> V_51 , ( long int ) V_81 ) ;
return - V_69 ;
}
* ( V_96 * ) V_80
= ( * ( V_96 * ) V_80 & ~ 0x03fffffc )
| ( V_81 & 0x03fffffc ) ;
break;
case V_97 :
* V_80 = V_81 - ( unsigned long ) V_80 ;
break;
case V_98 :
break;
case V_99 :
V_81 -= ( unsigned long ) V_80 ;
V_81 = ( ( V_81 + 0x8000 ) >> 16 ) ;
* ( ( V_90 * ) V_80 )
= ( * ( ( V_90 * ) V_80 ) & ~ 0xffff )
| ( V_81 & 0xffff ) ;
break;
case V_100 :
V_81 -= ( unsigned long ) V_80 ;
* ( ( V_90 * ) V_80 )
= ( * ( ( V_90 * ) V_80 ) & ~ 0xffff )
| ( V_81 & 0xffff ) ;
break;
default:
F_25 ( L_19 ,
V_62 -> V_51 ,
( unsigned long ) F_12 ( V_27 [ V_8 ] . V_29 ) ) ;
return - V_69 ;
}
}
#ifdef F_19
V_62 -> V_25 . V_26 = F_26 ( V_40 , V_62 ) ;
V_62 -> V_25 . V_101 = F_30 ( V_40 ,
( unsigned long ) V_102 ,
V_62 ) ;
#endif
return 0 ;
}
