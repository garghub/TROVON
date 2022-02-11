static void F_1 ( int V_1 )
{
volatile int V_2 ;
for( V_2 = V_1 * 12 ; V_2 > 0 ; V_2 -- )
;
}
static void
F_2 ( unsigned char V_3 )
{
int V_4 ;
F_3 ( 1 ) ;
for ( V_4 = 8 ; V_4 -- ; ) {
F_4 ( 0 ) ;
F_5 ( V_3 & 1 ) ;
F_1 ( 1 ) ;
F_4 ( 1 ) ;
F_1 ( 1 ) ;
V_3 >>= 1 ;
}
F_3 ( 0 ) ;
}
static unsigned char
F_6 ( void )
{
unsigned char V_3 = 0 ;
int V_4 ;
F_3 ( 0 ) ;
for ( V_4 = 8 ; V_4 -- ; ) {
F_4 ( 0 ) ;
F_1 ( 1 ) ;
V_3 >>= 1 ;
V_3 |= ( F_7 () << 7 ) ;
F_4 ( 1 ) ;
F_1 ( 1 ) ;
}
return V_3 ;
}
static void
F_8 ( void )
{
F_4 ( 0 ) ;
F_1 ( 1 ) ;
F_9 ( 0 ) ;
F_1 ( 5 ) ;
F_9 ( 1 ) ;
}
static void
F_10 ( void )
{
F_1 ( 2 ) ;
F_9 ( 0 ) ;
}
static void
F_11 ( void )
{
F_8 () ;
F_2 ( 0x8e ) ;
F_2 ( 0x00 ) ;
F_10 () ;
}
static void
F_12 ( void )
{
F_8 () ;
F_2 ( 0x8e ) ;
F_2 ( 0x80 ) ;
F_10 () ;
}
unsigned char
F_13 ( int V_5 )
{
unsigned char V_3 ;
F_8 () ;
F_2 ( 0x81 | ( V_5 << 1 ) ) ;
V_3 = F_6 () ;
F_10 () ;
return V_3 ;
}
void
F_14 ( int V_5 , unsigned char V_6 )
{
#ifndef F_15
int V_7 = 1 ;
#else
int V_7 = 0 ;
if ( V_5 == V_8 )
V_7 = 1 ;
#endif
if ( V_7 ) {
F_11 () ;
F_8 () ;
F_2 ( 0x80 | ( V_5 << 1 ) ) ;
F_2 ( V_6 ) ;
F_10 () ;
F_12 () ;
}
}
void
F_16 ( struct V_9 * V_10 )
{
unsigned long V_11 ;
F_17 ( V_11 ) ;
V_10 -> V_12 = F_18 ( V_13 ) ;
V_10 -> V_14 = F_18 ( V_15 ) ;
V_10 -> V_16 = F_18 ( V_17 ) ;
V_10 -> V_18 = F_18 ( V_19 ) ;
V_10 -> V_20 = F_18 ( V_21 ) ;
V_10 -> V_22 = F_18 ( V_23 ) ;
F_19 ( V_11 ) ;
V_10 -> V_12 = F_20 ( V_10 -> V_12 ) ;
V_10 -> V_14 = F_20 ( V_10 -> V_14 ) ;
V_10 -> V_16 = F_20 ( V_10 -> V_16 ) ;
V_10 -> V_18 = F_20 ( V_10 -> V_18 ) ;
V_10 -> V_20 = F_20 ( V_10 -> V_20 ) ;
V_10 -> V_22 = F_20 ( V_10 -> V_22 ) ;
if ( V_10 -> V_22 <= 69 )
V_10 -> V_22 += 100 ;
V_10 -> V_20 -- ;
}
static int F_21 ( struct V_24 * V_24 , unsigned int V_25 , unsigned long V_26 )
{
unsigned long V_11 ;
switch( V_25 ) {
case V_27 :
{
struct V_9 V_10 ;
memset ( & V_10 , 0 , sizeof ( struct V_9 ) ) ;
F_16 ( & V_10 ) ;
if ( F_22 ( (struct V_9 * ) V_26 , & V_10 , sizeof( struct V_9 ) ) )
return - V_28 ;
return 0 ;
}
case V_29 :
{
struct V_9 V_10 ;
unsigned char V_30 , V_31 , V_32 , V_33 , V_34 , V_35 ;
unsigned int V_36 ;
if ( ! F_23 ( V_37 ) )
return - V_38 ;
if ( F_24 ( & V_10 , (struct V_9 * ) V_26 , sizeof( struct V_9 ) ) )
return - V_28 ;
V_36 = V_10 . V_22 + 1900 ;
V_30 = V_10 . V_20 + 1 ;
V_31 = V_10 . V_18 ;
V_32 = V_10 . V_16 ;
V_33 = V_10 . V_14 ;
V_34 = V_10 . V_12 ;
if ( ( V_36 < 1970 ) || ( V_36 > 2069 ) )
return - V_39 ;
V_35 = ( ( ! ( V_36 % 4 ) && ( V_36 % 100 ) ) || ! ( V_36 % 400 ) ) ;
if ( ( V_30 > 12 ) || ( V_31 == 0 ) )
return - V_39 ;
if ( V_31 > ( V_40 [ V_30 ] + ( ( V_30 == 2 ) && V_35 ) ) )
return - V_39 ;
if ( ( V_32 >= 24 ) || ( V_33 >= 60 ) || ( V_34 >= 60 ) )
return - V_39 ;
if ( V_36 >= 2000 )
V_36 -= 2000 ;
else
V_36 -= 1900 ;
V_34 = F_25 ( V_34 ) ;
V_33 = F_25 ( V_33 ) ;
V_32 = F_25 ( V_32 ) ;
V_31 = F_25 ( V_31 ) ;
V_30 = F_25 ( V_30 ) ;
V_36 = F_25 ( V_36 ) ;
F_17 ( V_11 ) ;
F_26 ( V_36 , V_23 ) ;
F_26 ( V_30 , V_21 ) ;
F_26 ( V_31 , V_19 ) ;
F_26 ( V_32 , V_17 ) ;
F_26 ( V_33 , V_15 ) ;
F_26 ( V_34 , V_13 ) ;
F_19 ( V_11 ) ;
return 0 ;
}
case V_41 :
{
int V_42 ;
if ( ! F_23 ( V_37 ) )
return - V_38 ;
if( F_24 ( & V_42 , ( int * ) V_26 , sizeof( int ) ) )
return - V_28 ;
V_42 = V_43 | ( V_42 & 0x0F ) ;
F_14 ( V_8 , V_42 ) ;
return 0 ;
}
case V_44 :
{
F_27 ( V_45 L_1
L_2 ) ;
return 0 ;
}
case V_46 :
{
return 0 ;
}
default:
return - V_47 ;
}
}
static long F_28 ( struct V_24 * V_24 , unsigned int V_25 , unsigned long V_26 )
{
int V_48 ;
F_29 ( & V_49 ) ;
V_48 = F_21 ( V_24 , V_25 , V_26 ) ;
F_30 ( & V_49 ) ;
return V_48 ;
}
static void
F_31 ( void )
{
struct V_9 V_50 ;
F_16 ( & V_50 ) ;
F_27 ( V_51 L_3 ,
V_50 . V_16 , V_50 . V_14 , V_50 . V_12 ) ;
F_27 ( V_51 L_4 ,
V_50 . V_22 + 1900 , V_50 . V_20 + 1 , V_50 . V_18 ) ;
}
static int T_1
F_32 ( void )
{
int V_52 , V_53 ;
F_33 ( 1 ) ;
F_34 ( 1 ) ;
F_3 ( 0 ) ;
F_11 () ;
F_8 () ;
F_2 ( 0xc0 ) ;
F_2 ( V_54 ) ;
F_8 () ;
F_2 ( 0xc1 ) ;
if( ( V_53 = F_6 () ) == V_54 ) {
F_10 () ;
F_12 () ;
F_27 ( V_51 L_5 , V_55 ) ;
F_27 ( V_51 L_6 ,
V_55 ,
V_56 ,
V_57 ,
#ifdef F_35
L_7 ,
#else
L_8 ,
#endif
V_58 ) ;
F_31 () ;
V_52 = 1 ;
} else {
F_10 () ;
V_52 = 0 ;
}
return V_52 ;
}
int T_1
F_36 ( void )
{
#ifdef F_37
F_38 () ;
#endif
if ( ! F_32 () ) {
#ifdef F_35
#if V_58 == 27
if ( F_39 ( V_59 , L_9 ) ) {
F_27 ( V_45 L_10 ) ;
return - 1 ;
}
#elif V_58 == 0
if ( F_40 ( V_60 ,
'g' ,
V_58 ,
V_58 ) ) {
F_27 ( V_45 L_10 ) ;
return - 1 ;
}
V_61 = ( ( V_61 &
~ F_41 ( V_62 , V_63 ) ) |
( F_42 ( V_62 , V_63 , V_64 ) ) ) ;
* V_62 = V_61 ;
#endif
if ( ! F_32 () ) {
F_27 ( V_45 L_11 , V_55 ) ;
return - 1 ;
}
#else
F_27 ( V_45 L_11 , V_55 ) ;
return - 1 ;
#endif
}
F_14 ( V_8 ,
V_43 | ( V_65 & 0x0F ) ) ;
F_14 ( V_13 , ( F_13 ( V_13 ) & 0x7F ) ) ;
return 0 ;
}
static int T_1 F_43 ( void )
{
F_36 () ;
if ( F_44 ( V_66 , V_55 , & V_67 ) ) {
F_27 ( V_51 L_12 ,
V_55 , V_66 ) ;
return - 1 ;
}
return 0 ;
}
