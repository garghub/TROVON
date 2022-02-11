static T_1 F_1 ( unsigned long V_1 )
{
T_1 V_2 ;
int V_3 = V_4 ;
do {
V_2 = F_2 ( V_1 ) ;
if ( V_2 == 0 )
F_3 ( 50 ) ;
} while ( V_2 == 0 && V_3 -- > 0 );
return V_2 ;
}
static T_1 F_4 ( T_2 * V_5 )
{
return F_1 ( V_5 -> V_6 . V_7 ) ;
}
static T_1 F_5 ( T_2 * V_5 )
{
return F_1 ( V_5 -> V_8 + V_9 ) ;
}
static void F_6 ( T_3 * V_10 , struct V_11 * V_12 ,
T_1 V_13 )
{
struct V_14 * V_6 = & V_10 -> V_5 -> V_6 ;
if ( V_13 & V_15 )
V_12 -> error = F_2 ( V_6 -> V_16 ) ;
if ( V_13 & V_17 )
V_12 -> V_18 = F_2 ( V_6 -> V_19 ) ;
if ( V_13 & V_20 )
V_12 -> V_21 = F_2 ( V_6 -> V_22 ) ;
if ( V_13 & V_23 )
V_12 -> V_24 = F_2 ( V_6 -> V_25 ) ;
if ( V_13 & V_26 )
V_12 -> V_27 = F_2 ( V_6 -> V_28 ) ;
if ( V_13 & V_29 )
V_12 -> V_30 = F_1 ( V_6 -> V_31 ) ;
}
static void F_7 ( struct V_32 * V_5 )
{
struct V_33 * V_34 = F_8 ( V_5 -> V_35 ) ;
T_4 V_36 ;
T_1 V_1 = V_5 -> V_37 , V_2 ;
V_36 = ( F_9 ( V_34 , 4 ) & ~ 3 ) + ( ! V_1 ? 2 : 0xa ) ;
V_2 = F_1 ( V_36 ) ;
F_10 ( V_2 | 0x66 , V_36 ) ;
}
static void F_11 ( T_3 * V_10 , unsigned int V_38 )
{
T_2 * V_5 = V_10 -> V_5 ;
struct V_33 * V_35 = F_8 ( V_5 -> V_35 ) ;
unsigned int V_39 , V_40 , V_41 , * V_42 = ( unsigned int * ) V_5 -> V_43 ;
unsigned long V_44 ;
F_12 ( V_44 ) ;
V_41 = * V_42 ;
V_39 = 1 << ( 8 + V_5 -> V_37 ) ;
if ( V_10 -> V_45 & V_46 )
V_41 &= ~ V_39 ;
else
V_41 |= V_39 ;
V_39 = 1 << ( 20 + ( V_10 -> V_47 & 1 ) + ( V_5 -> V_37 << 1 ) ) ;
V_40 = 1 << ( 20 + ( 1 - ( V_10 -> V_47 & 1 ) ) + ( V_5 -> V_37 << 1 ) ) ;
V_41 = V_38 ? ( ( V_41 & ~ V_40 ) | V_39 ) : ( V_41 & ~ V_39 ) ;
if ( V_41 != * V_42 ) {
unsigned char V_48 ;
( void ) F_13 ( V_35 , 0x43 , & V_48 ) ;
while ( V_48 & 0x03 ) {
F_3 ( 1 ) ;
( void ) F_13 ( V_35 , 0x43 , & V_48 ) ;
}
* V_42 = V_41 ;
( void ) F_14 ( V_35 , 0x40 , V_41 ) ;
F_3 ( 10 ) ;
}
F_15 ( V_44 ) ;
}
static void F_16 ( T_3 * V_10 )
{
F_11 ( V_10 ,
! ! ( V_10 -> V_45 & V_49 ) ) ;
F_10 ( V_10 -> V_50 | V_51 , V_10 -> V_5 -> V_6 . V_31 ) ;
}
static void F_17 ( T_3 * V_10 )
{
F_11 ( V_10 , 1 ) ;
F_18 ( V_10 ) ;
}
static int F_19 ( T_3 * V_10 )
{
T_2 * V_5 = V_10 -> V_5 ;
T_1 V_36 = 0 , V_52 = 0 ;
V_36 = V_5 -> V_53 -> V_54 ( V_5 ) ;
V_52 = F_2 ( V_5 -> V_8 + V_55 ) ;
F_10 ( V_52 & ~ 1 , V_5 -> V_8 + V_55 ) ;
V_52 = F_2 ( V_5 -> V_8 + V_55 ) ;
F_10 ( V_52 | 6 , V_5 -> V_8 + V_55 ) ;
F_11 ( V_10 , 0 ) ;
return ( V_36 & 7 ) != 4 ;
}
static void F_20 ( T_2 * V_5 )
{
struct V_33 * V_35 = F_8 ( V_5 -> V_35 ) ;
unsigned int V_56 , V_57 ;
T_1 V_58 ;
#ifdef F_21
int V_59 ;
T_1 V_48 ;
#endif
( void ) F_22 ( V_35 , 0x40 , & V_56 ) ;
( void ) F_13 ( V_35 , 0x09 , & V_58 ) ;
V_57 = V_58 & ( 1 << ( V_5 -> V_37 << 1 ) ) ;
if ( ! V_57 )
V_57 = V_56 & ( 1 << ( 4 + V_5 -> V_37 ) ) ;
if ( V_5 -> V_60 ) {
V_5 -> V_43 = V_5 -> V_60 -> V_43 ;
} else {
V_5 -> V_43 = ( unsigned long )
& V_61 [ V_62 ++ ] ;
V_56 |= ( 1 << 8 ) | ( 1 << 9 ) ;
if ( V_57 )
V_56 &= ~ ( 1 << 6 ) ;
* ( ( unsigned int * ) V_5 -> V_43 ) = V_56 ;
( void ) F_14 ( V_35 , 0x40 , V_56 ) ;
F_23 ( V_35 , 0x55 , 0xee ) ;
#ifdef F_21
V_59 = 10000 ;
F_10 ( 12 , V_5 -> V_6 . V_63 ) ;
F_3 ( 10 ) ;
F_10 ( 8 , V_5 -> V_6 . V_63 ) ;
do {
F_3 ( 50 ) ;
V_48 = V_5 -> V_64 -> V_65 ( V_5 ) ;
if ( V_48 == 0xff )
break;
} while ( ( V_48 & V_66 ) && -- V_59 );
#endif
}
if ( ! V_57 )
V_5 -> V_67 = F_24 ( V_35 , V_5 -> V_37 ) ;
if ( ! V_5 -> V_8 )
return;
F_10 ( 0x60 , V_5 -> V_8 + V_9 ) ;
}
static int F_25 ( struct V_33 * V_35 , const struct V_68 * V_69 )
{
struct V_70 V_71 = V_72 ;
#ifdef F_26
if ( F_27 ( V_35 -> V_73 ) == 0xE ) {
V_71 . V_74 = F_7 ;
V_71 . V_64 = & V_75 ;
}
#endif
return F_28 ( V_35 , & V_71 , NULL ) ;
}
static int T_5 F_29 ( void )
{
return F_30 ( & V_76 ) ;
}
static void T_6 F_31 ( void )
{
F_32 ( & V_76 ) ;
}
