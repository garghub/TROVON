static void F_1 ( void )
{
F_2 ( F_3 ( V_1 ) & ~ V_2 , V_1 ) ;
F_2 ( F_3 ( V_3 ) & ~ V_4 , V_3 ) ;
V_5 = F_3 ( V_6 ) | V_7 ;
F_2 ( V_5 , V_6 ) ;
V_5 = F_3 ( V_6 ) | V_8 ;
F_2 ( V_5 , V_6 ) ;
V_9 ;
}
static void F_4 ( unsigned char V_10 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
V_5 = ( V_5 & ~ V_12 ) |
( ( ( ( 0x80 >> V_11 ) & V_10 ) >> ( 7 - V_11 ) ) << 2 ) ;
F_2 ( V_5 , V_6 ) ;
if ( V_11 == 0 ) {
V_5 |= V_13 ;
F_2 ( V_5 , V_6 ) ;
}
F_5 ( 700 ) ;
V_5 &= ~ V_7 ;
F_2 ( V_5 , V_6 ) ;
F_5 ( 700 ) ;
V_5 |= V_7 ;
F_2 ( V_5 , V_6 ) ;
}
V_5 &= ~ V_13 ;
F_2 ( V_5 , V_6 ) ;
}
static unsigned char F_6 ( void )
{
int V_11 ;
unsigned char V_10 = 0 ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
F_5 ( 700 ) ;
V_10 |= ( ( F_3 ( V_6 ) & V_12 ) >> 2 ) << ( 7 - V_11 ) ;
V_5 &= ~ V_7 ;
F_2 ( V_5 , V_6 ) ;
F_5 ( 700 ) ;
V_5 |= V_7 ;
F_2 ( V_5 , V_6 ) ;
}
return V_10 & 0x0F ;
}
static unsigned char F_7 ( unsigned char V_14 )
{
F_4 ( V_14 | V_15 | V_16 ) ;
return F_6 () ;
}
static void F_8 ( unsigned char V_14 , unsigned char V_10 )
{
V_10 &= 0x0f ;
F_4 ( V_14 | V_16 ) ;
F_4 ( V_10 | V_17 ) ;
return;
}
static inline unsigned char F_9 ( void )
{
return F_7 ( V_18 ) ;
}
static inline void F_10 ( unsigned char V_10 )
{
F_8 ( V_18 , V_10 ) ;
}
static inline void F_11 ( unsigned char V_10 )
{
F_8 ( V_19 , V_10 ) ;
}
static int F_12 ( struct V_20 * V_21 , struct V_22 * V_23 )
{
int V_10 ;
int V_24 ;
V_24 = 0 ;
while ( 1 ) {
V_25 ;
F_10 ( 0x04 ) ;
if ( ! ( F_9 () & V_26 ) )
break;
V_9 ;
F_5 ( 700 ) ;
if ( V_24 ++ > 100 ) {
F_13 ( V_21 , L_1 , V_27 ) ;
return - V_28 ;
}
}
V_10 = F_7 ( V_29 ) ;
V_10 |= ( F_7 ( V_30 ) << 4 ) ;
V_23 -> V_31 = F_14 ( V_10 ) ;
V_10 = F_7 ( V_32 ) ;
V_10 |= ( F_7 ( V_33 ) << 4 ) ;
V_23 -> V_34 = F_14 ( V_10 ) ;
V_10 = F_7 ( V_35 ) ;
V_10 |= ( F_7 ( V_36 ) << 4 ) ;
V_23 -> V_37 = F_14 ( V_10 ) ;
V_10 = F_7 ( V_38 ) ;
V_10 |= ( F_7 ( V_39 ) << 4 ) ;
V_23 -> V_40 = F_14 ( V_10 ) ;
V_10 = F_7 ( V_41 ) ;
V_10 |= ( F_7 ( V_42 ) << 4 ) ;
V_23 -> V_43 = F_14 ( V_10 ) - 1 ;
V_10 = F_7 ( V_44 ) ;
V_10 |= ( F_7 ( V_45 ) << 4 ) ;
V_23 -> V_46 = F_14 ( V_10 ) ;
if ( V_23 -> V_46 < 70 )
V_23 -> V_46 += 100 ;
V_10 = F_7 ( V_47 ) ;
V_23 -> V_48 = F_14 ( V_10 ) ;
V_9 ;
F_5 ( 700 ) ;
return 0 ;
}
static int F_15 ( struct V_20 * V_21 , struct V_22 * V_23 )
{
int V_10 ;
int V_24 ;
V_24 = 0 ;
while ( 1 ) {
V_25 ;
F_10 ( 0x04 ) ;
if ( ! ( F_9 () & V_26 ) )
break;
V_49 ;
V_9 ;
F_5 ( 700 ) ;
if ( V_24 ++ > 100 ) {
F_13 ( V_21 , L_1 , V_27 ) ;
return - V_28 ;
}
}
V_10 = F_16 ( V_23 -> V_31 ) ;
F_8 ( V_29 , V_10 ) ;
F_8 ( V_30 , ( V_10 >> 4 ) ) ;
V_10 = F_16 ( V_23 -> V_34 ) ;
F_8 ( V_32 , V_10 ) ;
F_8 ( V_33 , ( V_10 >> 4 ) ) ;
V_10 = F_16 ( V_23 -> V_37 ) ;
F_8 ( V_35 , V_10 ) ;
F_8 ( V_36 , ( V_10 >> 4 ) ) ;
V_10 = F_16 ( V_23 -> V_40 ) ;
F_8 ( V_38 , V_10 ) ;
F_8 ( V_39 , ( V_10 >> 4 ) ) ;
V_10 = F_16 ( V_23 -> V_43 + 1 ) ;
F_8 ( V_41 , V_10 ) ;
F_8 ( V_42 , ( V_10 >> 4 ) ) ;
V_10 = F_16 ( V_23 -> V_46 % 100 ) ;
F_8 ( V_44 , V_10 ) ;
F_8 ( V_45 , ( V_10 >> 4 ) ) ;
V_10 = F_16 ( V_23 -> V_48 ) ;
F_8 ( V_47 , V_10 ) ;
V_9 ;
F_5 ( 700 ) ;
return 0 ;
}
static void F_17 ( void )
{
struct V_22 V_23 ;
int V_24 ;
V_25 ;
if ( F_9 () & V_50 ) {
F_11 ( 0x00 ) ;
F_10 ( 0x07 ) ;
for ( V_24 = 0 ; V_24 < 100 ; V_24 ++ ) {
if ( ! ( F_9 () & V_26 ) )
break;
V_49 ;
}
memset ( & V_23 , 0 , sizeof( struct V_22 ) ) ;
V_23 . V_40 = 1 ;
V_23 . V_43 = 1 - 1 ;
V_23 . V_46 = 2000 - 1900 ;
F_15 ( NULL , & V_23 ) ;
F_18 ( L_2 ) ;
}
V_9 ;
F_5 ( 700 ) ;
}
static int F_19 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = F_20 ( L_3 , & V_52 -> V_21 ,
& V_55 , V_56 ) ;
if ( F_21 ( V_54 ) )
return F_22 ( V_54 ) ;
F_23 ( V_52 , V_54 ) ;
return 0 ;
}
static int F_24 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = F_25 ( V_52 ) ;
F_26 ( V_54 ) ;
return 0 ;
}
static int T_1 F_27 ( void )
{
int V_57 ;
V_57 = F_28 ( & V_58 ) ;
if ( V_57 )
return V_57 ;
F_1 () ;
F_17 () ;
return 0 ;
}
static void T_2 F_29 ( void )
{
F_30 ( & V_58 ) ;
}
