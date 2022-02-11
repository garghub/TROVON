static unsigned int F_1 ( const T_1 * V_1 , unsigned int V_2 )
{
unsigned int V_3 , V_4 , V_5 , V_6 ;
V_6 = 0 ;
V_4 = 0 ;
V_5 = 0 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ )
if ( F_2 ( V_1 [ V_3 ] . V_4 ) == V_7 &&
( V_4 != F_3 ( V_1 [ V_3 ] . V_4 ) ||
V_5 != V_1 [ V_3 ] . V_5 ) ) {
V_6 ++ ;
V_4 = F_3 ( V_1 [ V_3 ] . V_4 ) ;
V_5 = V_1 [ V_3 ] . V_5 ;
}
return V_6 ;
}
static int F_4 ( const void * V_8 , const void * V_9 )
{
const T_1 * V_10 , * V_11 ;
V_11 = ( T_1 * ) V_8 ;
V_10 = ( T_1 * ) V_9 ;
if ( V_10 -> V_4 < V_11 -> V_4 )
return - 1 ;
else if ( V_10 -> V_4 > V_11 -> V_4 )
return 1 ;
else if ( V_10 -> V_5 < V_11 -> V_5 )
return - 1 ;
else if ( V_10 -> V_5 > V_11 -> V_5 )
return 1 ;
else
return 0 ;
}
static void F_5 ( void * V_8 , void * V_9 , int V_12 )
{
T_2 * V_10 , * V_11 , V_13 ;
int V_3 ;
V_11 = ( T_2 * ) V_8 ;
V_10 = ( T_2 * ) V_9 ;
for ( V_3 = 0 ; V_3 < sizeof( T_1 ) / sizeof( T_2 ) ; V_3 ++ ) {
V_13 = V_10 [ V_3 ] ;
V_10 [ V_3 ] = V_11 [ V_3 ] ;
V_11 [ V_3 ] = V_13 ;
}
}
static unsigned long F_6 ( const T_3 * V_14 ,
const T_4 * V_15 )
{
unsigned long V_16 = 1 ;
unsigned V_3 ;
for ( V_3 = 1 ; V_3 < V_14 -> V_17 ; V_3 ++ ) {
if ( V_15 [ V_3 ] . V_18 == V_19 ) {
F_7 ( L_1 , V_3 ) ;
F_7 ( L_2 ,
( void * ) V_15 [ V_3 ] . V_20 ,
V_15 [ V_3 ] . V_21 / sizeof( T_1 ) ) ;
F_8 ( ( void * ) V_15 [ V_3 ] . V_20 ,
V_15 [ V_3 ] . V_21 / sizeof( T_1 ) ,
sizeof( T_1 ) , F_4 , F_5 ) ;
V_16 += F_1 ( ( void * ) V_15 [ V_3 ] . V_20 ,
V_15 [ V_3 ] . V_21
/ sizeof( T_1 ) ) ;
}
}
#ifdef F_9
V_16 ++ ;
#endif
F_7 ( L_3 , V_16 ) ;
return V_16 * sizeof( struct V_22 ) ;
}
static void F_10 ( struct V_23 * V_24 ,
unsigned long V_12 )
{
struct V_23 * V_25 ;
for ( V_25 = ( void * ) V_24 + V_12 ; V_24 < V_25 ; V_24 ++ )
if ( V_24 -> V_26 [ 0 ] == '.' )
memmove ( V_24 -> V_26 , V_24 -> V_26 + 1 , strlen ( V_24 -> V_26 ) ) ;
}
static void F_11 ( T_5 * V_27 , unsigned int V_28 , char * V_29 )
{
unsigned int V_3 ;
for ( V_3 = 1 ; V_3 < V_28 ; V_3 ++ ) {
if ( V_27 [ V_3 ] . V_30 == V_31 ) {
char * V_26 = V_29 + V_27 [ V_3 ] . V_32 ;
if ( V_26 [ 0 ] == '.' )
memmove ( V_26 , V_26 + 1 , strlen ( V_26 ) ) ;
}
}
}
int F_12 ( T_3 * V_14 ,
T_4 * V_15 ,
char * V_33 ,
struct V_34 * V_35 )
{
unsigned int V_3 ;
for ( V_3 = 1 ; V_3 < V_14 -> V_17 ; V_3 ++ ) {
char * V_36 ;
if ( strcmp ( V_33 + V_15 [ V_3 ] . V_37 , L_4 ) == 0 )
V_35 -> V_38 . V_39 = V_3 ;
else if ( strcmp ( V_33 + V_15 [ V_3 ] . V_37 , L_5 ) == 0 )
V_35 -> V_38 . V_40 = V_3 ;
else if ( strcmp ( V_33 + V_15 [ V_3 ] . V_37 , L_6 ) == 0 )
F_10 ( ( void * ) V_14 + V_15 [ V_3 ] . V_41 ,
V_15 [ V_3 ] . V_21 ) ;
while ( ( V_36 = strstr ( V_33 + V_15 [ V_3 ] . V_37 , L_7 ) ) )
V_36 [ 0 ] = '_' ;
if ( V_15 [ V_3 ] . V_18 == V_42 )
F_11 ( ( void * ) V_14 + V_15 [ V_3 ] . V_41 ,
V_15 [ V_3 ] . V_21 / sizeof( T_5 ) ,
( void * ) V_14
+ V_15 [ V_15 [ V_3 ] . V_43 ] . V_41 ) ;
}
if ( ! V_35 -> V_38 . V_39 ) {
F_13 ( L_8 , V_35 -> V_26 ) ;
return - V_44 ;
}
if ( ! V_35 -> V_38 . V_40 )
V_35 -> V_38 . V_40 = V_35 -> V_38 . V_39 ;
V_15 [ V_35 -> V_38 . V_39 ] . V_21 = F_6 ( V_14 , V_15 ) ;
return 0 ;
}
static inline unsigned long F_14 ( T_4 * V_15 , struct V_34 * V_35 )
{
return V_15 [ V_35 -> V_38 . V_40 ] . V_20 + 0x8000 ;
}
static inline int F_15 ( T_4 * V_15 ,
struct V_22 * V_45 ,
struct V_46 * V_47 ,
struct V_34 * V_35 )
{
T_6 * V_48 , * V_49 ;
long V_50 ;
* V_45 = V_51 ;
V_48 = ( T_6 * ) & V_45 -> V_52 [ 2 ] ;
V_49 = ( T_6 * ) & V_45 -> V_52 [ 6 ] ;
V_50 = ( unsigned long ) V_45 - F_14 ( V_15 , V_35 ) ;
if ( V_50 > 0x7FFFFFFF || V_50 < - ( 0x80000000L ) ) {
F_13 ( L_9 ,
V_35 -> V_26 , ( void * ) V_50 , ( void * ) F_14 ) ;
return 0 ;
}
F_7 ( L_10 , V_45 , V_50 ) ;
* V_48 = F_16 ( V_50 ) ;
* V_49 = F_17 ( V_50 ) ;
V_45 -> V_47 . V_53 = V_47 -> V_53 ;
V_45 -> V_47 . V_54 = V_47 -> V_54 ;
return 1 ;
}
static unsigned long F_18 ( T_4 * V_15 ,
unsigned long V_55 ,
struct V_34 * V_35 )
{
struct V_22 * V_56 ;
struct V_46 * V_47 = ( void * ) V_55 ;
unsigned int V_3 , V_57 ;
V_57 = V_15 [ V_35 -> V_38 . V_39 ] . V_21 / sizeof( * V_56 ) ;
V_56 = ( void * ) V_15 [ V_35 -> V_38 . V_39 ] . V_20 ;
for ( V_3 = 0 ; V_56 [ V_3 ] . V_47 . V_53 ; V_3 ++ ) {
F_19 ( V_3 >= V_57 ) ;
if ( V_56 [ V_3 ] . V_47 . V_53 == V_47 -> V_53 )
return ( unsigned long ) & V_56 [ V_3 ] ;
}
if ( ! F_15 ( V_15 , & V_56 [ V_3 ] , V_47 , V_35 ) )
return 0 ;
return ( unsigned long ) & V_56 [ V_3 ] ;
}
static int F_20 ( T_7 * V_58 , struct V_34 * V_35 )
{
if ( * V_58 != V_59 ) {
F_13 ( L_11 ,
V_35 -> V_26 , * V_58 ) ;
return 0 ;
}
* V_58 = 0xe8410028 ;
return 1 ;
}
int F_21 ( T_4 * V_15 ,
const char * V_29 ,
unsigned int V_60 ,
unsigned int V_61 ,
struct V_34 * V_35 )
{
unsigned int V_3 ;
T_1 * V_1 = ( void * ) V_15 [ V_61 ] . V_20 ;
T_5 * V_62 ;
unsigned long * V_63 ;
unsigned long V_64 ;
F_7 ( L_12 , V_61 ,
V_15 [ V_61 ] . V_65 ) ;
for ( V_3 = 0 ; V_3 < V_15 [ V_61 ] . V_21 / sizeof( * V_1 ) ; V_3 ++ ) {
V_63 = ( void * ) V_15 [ V_15 [ V_61 ] . V_65 ] . V_20
+ V_1 [ V_3 ] . V_66 ;
V_62 = ( T_5 * ) V_15 [ V_60 ] . V_20
+ F_3 ( V_1 [ V_3 ] . V_4 ) ;
F_7 ( L_13 ,
V_63 , ( long ) F_2 ( V_1 [ V_3 ] . V_4 ) ,
V_29 + V_62 -> V_32 , ( unsigned long ) V_62 -> V_67 ,
( long ) V_1 [ V_3 ] . V_5 ) ;
V_64 = V_62 -> V_67 + V_1 [ V_3 ] . V_5 ;
switch ( F_2 ( V_1 [ V_3 ] . V_4 ) ) {
case V_68 :
* ( T_7 * ) V_63 = V_64 ;
break;
case V_69 :
* ( unsigned long * ) V_63 = V_64 ;
break;
case V_70 :
* ( unsigned long * ) V_63 = F_14 ( V_15 , V_35 ) ;
break;
case V_71 :
V_64 -= F_14 ( V_15 , V_35 ) ;
if ( V_64 + 0x8000 > 0xffff ) {
F_13 ( L_14 ,
V_35 -> V_26 , V_64 ) ;
return - V_44 ;
}
* ( ( V_72 * ) V_63 )
= ( * ( ( V_72 * ) V_63 ) & ~ 0xffff )
| ( V_64 & 0xffff ) ;
break;
case V_73 :
V_64 -= F_14 ( V_15 , V_35 ) ;
if ( ( V_64 & 3 ) != 0 || V_64 + 0x8000 > 0xffff ) {
F_13 ( L_15 ,
V_35 -> V_26 , V_64 ) ;
return - V_44 ;
}
* ( ( V_72 * ) V_63 )
= ( * ( ( V_72 * ) V_63 ) & ~ 0xfffc )
| ( V_64 & 0xfffc ) ;
break;
case V_7 :
if ( V_62 -> V_30 == V_31 ) {
V_64 = F_18 ( V_15 , V_64 , V_35 ) ;
if ( ! V_64 )
return - V_74 ;
if ( ! F_20 ( ( T_7 * ) V_63 + 1 , V_35 ) )
return - V_44 ;
}
V_64 -= ( unsigned long ) V_63 ;
if ( V_64 + 0x2000000 > 0x3ffffff || ( V_64 & 3 ) != 0 ) {
F_13 ( L_16 ,
V_35 -> V_26 , ( long int ) V_64 ) ;
return - V_44 ;
}
* ( V_75 * ) V_63
= ( * ( V_75 * ) V_63 & ~ 0x03fffffc )
| ( V_64 & 0x03fffffc ) ;
break;
case V_76 :
* V_63 = V_64 - ( unsigned long ) V_63 ;
break;
default:
F_13 ( L_17 ,
V_35 -> V_26 ,
( unsigned long ) F_2 ( V_1 [ V_3 ] . V_4 ) ) ;
return - V_44 ;
}
}
#ifdef F_9
V_35 -> V_38 . V_77 = F_14 ( V_15 , V_35 ) ;
V_35 -> V_38 . V_78 = F_18 ( V_15 ,
( unsigned long ) V_79 ,
V_35 ) ;
#endif
return 0 ;
}
