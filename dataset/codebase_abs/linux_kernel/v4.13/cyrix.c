static void F_1 ( unsigned char * V_1 , unsigned char * V_2 )
{
unsigned char V_3 , V_4 ;
V_4 = F_2 ( V_5 ) ;
F_3 ( V_5 , V_4 ^ 0x80 ) ;
F_2 ( 0xc0 ) ;
if ( F_2 ( V_5 ) == V_4 ) {
V_3 = F_2 ( V_6 ) ;
F_3 ( V_6 , V_3 ^ 0x04 ) ;
F_2 ( 0xc0 ) ;
if ( F_2 ( V_6 ) == V_3 )
* V_1 = 0xfd ;
else {
F_3 ( V_6 , V_3 ) ;
* V_1 = 0xfe ;
}
} else {
F_3 ( V_5 , V_4 ) ;
* V_1 = F_2 ( V_7 ) ;
* V_2 = F_2 ( V_8 ) ;
}
}
static void F_4 ( unsigned char * V_1 , unsigned char * V_2 )
{
unsigned long V_9 ;
F_5 ( V_9 ) ;
F_1 ( V_1 , V_2 ) ;
F_6 ( V_9 ) ;
}
static void F_7 ( struct V_10 * V_11 )
{
unsigned long V_9 ;
if ( V_12 == 3 ) {
unsigned char V_4 , V_13 ;
F_5 ( V_9 ) ;
V_4 = F_2 ( V_5 ) ;
F_3 ( V_5 , ( V_4 & 0x0f ) | 0x10 ) ;
V_13 = F_2 ( V_14 ) ;
if ( V_13 & 2 )
F_3 ( V_14 , V_13 & 0xfd ) ;
F_3 ( V_5 , V_4 ) ;
F_6 ( V_9 ) ;
if ( V_13 & 2 ) {
F_8 ( L_1 ) ;
F_9 () ;
V_11 -> V_15 = V_15 ;
}
}
}
static void F_10 ( void )
{
T_1 V_4 ;
F_8 ( L_2 ) ;
V_4 = F_2 ( V_5 ) ;
F_3 ( V_5 , ( V_4 & 0x0f ) | 0x10 ) ;
F_11 ( V_16 , F_12 ( V_16 ) & ~ 0x80 ) ;
V_4 |= 0xe0 ;
F_3 ( V_5 , V_4 ) ;
}
static void F_13 ( void )
{
F_8 ( L_3 ) ;
F_11 ( V_6 , F_12 ( V_6 ) & ~ 0x04 ) ;
F_14 ( F_15 () | V_17 ) ;
F_11 ( V_6 , F_12 ( V_6 ) | 0x14 ) ;
}
static void F_16 ( void )
{
unsigned long V_9 ;
T_1 V_4 ;
F_5 ( V_9 ) ;
F_11 ( V_6 , F_12 ( V_6 ) | 0x88 ) ;
V_4 = F_2 ( V_5 ) ;
F_3 ( V_5 , ( V_4 & 0x0f ) | 0x10 ) ;
F_11 ( V_18 , F_12 ( V_18 ) | 0x38 ) ;
F_3 ( V_5 , V_4 ) ;
F_13 () ;
F_10 () ;
F_6 ( V_9 ) ;
}
static void F_17 ( struct V_10 * V_11 )
{
unsigned char V_1 , V_19 , V_2 = 0 ;
F_1 ( & V_1 , & V_2 ) ;
V_19 = V_1 >> 4 ;
switch ( V_19 ) {
case 3 :
F_18 ( V_11 , V_20 ) ;
break;
case 5 :
F_18 ( V_11 , V_20 ) ;
break;
}
}
static void F_19 ( struct V_10 * V_11 )
{
unsigned char V_1 , V_19 , V_21 , V_2 = 0 ;
char * V_22 = V_11 -> V_23 ;
const char * V_24 = NULL ;
F_20 ( V_11 , 0 * 32 + 31 ) ;
if ( F_21 ( V_11 , 1 * 32 + 24 ) ) {
F_20 ( V_11 , 1 * 32 + 24 ) ;
F_18 ( V_11 , V_25 ) ;
}
F_4 ( & V_1 , & V_2 ) ;
F_7 ( V_11 ) ;
V_12 = V_19 = V_1 >> 4 ;
V_21 = V_1 & 0xf ;
V_11 -> V_26 = ( V_2 >> 4 ) + 1 ;
V_11 -> V_27 = V_2 & 0xf ;
switch ( V_19 ) {
unsigned char V_28 ;
case 0 :
V_24 = V_29 [ V_21 & 7 ] ;
break;
case 1 :
V_24 = ( V_21 & 8 ) ? V_30 [ V_21 & 5 ]
: V_31 [ V_21 & 3 ] ;
break;
case 2 :
V_32 [ 2 ] = V_33 [ V_21 & 5 ] ;
V_24 = V_32 + 2 ;
break;
case 3 :
V_32 [ 1 ] = ' ' ;
V_32 [ 2 ] = V_33 [ V_21 & 5 ] ;
if ( V_2 > 0x21 ) {
V_32 [ 0 ] = 'L' ;
V_24 = V_32 ;
( V_11 -> V_26 ) ++ ;
} else
V_24 = V_32 + 1 ;
F_18 ( V_11 , V_20 ) ;
F_22 ( V_11 , V_34 ) ;
break;
case 4 :
case 11 :
#ifdef F_23
{
T_2 V_35 , V_36 ;
F_8 ( L_4 ) ;
V_37 = 2 ;
V_35 = F_24 ( 0 , 0 , 0x12 , V_38 ) ;
V_36 = F_24 ( 0 , 0 , 0x12 , V_39 ) ;
if ( V_35 == V_40 &&
( V_36 == V_41 ||
V_36 == V_42 ) )
F_25 ( L_5 ) ;
}
#endif
V_11 -> V_43 = 16 ;
if ( V_11 -> V_44 == 2 ) {
F_11 ( V_45 , F_12 ( V_45 ) | 1 ) ;
if ( ( 0x30 <= V_2 && V_2 <= 0x6f ) ||
( 0x80 <= V_2 && V_2 <= 0x8f ) )
F_16 () ;
return;
} else {
V_32 [ 2 ] = ( V_21 & 1 ) ? '3' : '4' ;
V_24 = V_32 + 2 ;
V_11 -> V_26 = ( V_2 & 0x20 ) ? 1 : 2 ;
}
break;
case 5 :
if ( V_2 > 7 ) {
V_19 ++ ;
F_11 ( V_45 , F_12 ( V_45 ) | 1 ) ;
} else {
F_22 ( V_11 , V_34 ) ;
}
V_28 = ( ! ( V_21 & 7 ) || V_21 & 1 ) ? 2 : 0 ;
V_32 [ V_28 ] = V_46 [ V_21 & 7 ] ;
V_24 = V_32 + V_28 ;
if ( ( ( V_2 & 0x0f ) > 4 ) || ( ( V_2 & 0xf0 ) == 0x20 ) )
( V_11 -> V_26 ) ++ ;
F_18 ( V_11 , V_20 ) ;
break;
case 0xf :
switch ( V_21 ) {
case 0xd :
V_19 = 0 ;
V_24 = V_29 [ ! ! F_26 ( V_47 ) ] ;
break;
case 0xe :
V_19 = 0 ;
V_24 = V_31 [ 0 ] ;
break;
}
break;
default:
V_19 = 7 ;
break;
}
strcpy ( V_22 , V_48 [ V_19 & 7 ] ) ;
if ( V_24 )
strcat ( V_22 , V_24 ) ;
return;
}
static void F_27 ( struct V_10 * V_11 )
{
if ( V_11 -> V_49 == 5 && V_11 -> V_26 == 5 )
F_28 ( V_11 ) ;
else
F_19 ( V_11 ) ;
}
static inline int F_29 ( void )
{
unsigned int V_50 ;
__asm__ __volatile__(
"sahf\n\t"
"div %b2\n\t"
"lahf"
: "=a" (test)
: "0" (5), "q" (2)
: "cc");
return ( unsigned char ) ( V_50 >> 8 ) == 0x02 ;
}
static void F_30 ( struct V_10 * V_11 )
{
if ( V_11 -> V_49 == 4 && F_29 () ) {
unsigned char V_1 , V_2 ;
strcpy ( V_11 -> V_51 , L_6 ) ;
V_11 -> V_52 = V_53 ;
F_4 ( & V_1 , & V_2 ) ;
V_1 >>= 4 ;
if ( V_1 == 5 || V_1 == 3 ) {
unsigned char V_4 ;
unsigned long V_9 ;
F_8 ( L_7 ) ;
F_5 ( V_9 ) ;
V_4 = F_2 ( V_5 ) ;
F_3 ( V_5 , ( V_4 & 0x0f ) | 0x10 ) ;
F_11 ( V_18 , F_12 ( V_18 ) | 0x80 ) ;
F_3 ( V_5 , V_4 ) ;
F_6 ( V_9 ) ;
}
}
}
