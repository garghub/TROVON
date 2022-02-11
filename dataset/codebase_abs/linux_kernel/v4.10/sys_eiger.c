static inline void
F_1 ( unsigned long V_1 , unsigned long V_2 )
{
int V_3 ;
V_2 = ( V_1 >= 64 ? V_2 << 16 : V_2 >> ( ( V_1 - 16 ) & 0x30 ) ) ;
V_3 = 0x510 + ( ( ( V_1 - 16 ) >> 2 ) & 0x0c ) ;
F_2 ( V_2 & 0xffff0000UL , V_3 ) ;
}
static inline void
F_3 ( struct V_4 * V_5 )
{
unsigned int V_1 = V_5 -> V_1 ;
unsigned long V_2 ;
V_2 = ( V_6 [ V_1 >= 64 ] &= ~ ( 1UL << ( V_1 & 63 ) ) ) ;
F_1 ( V_1 , V_2 ) ;
}
static void
F_4 ( struct V_4 * V_5 )
{
unsigned int V_1 = V_5 -> V_1 ;
unsigned long V_2 ;
V_2 = ( V_6 [ V_1 >= 64 ] |= 1UL << ( V_1 & 63 ) ) ;
F_1 ( V_1 , V_2 ) ;
}
static void
F_5 ( unsigned long V_7 )
{
unsigned V_8 ;
V_8 = F_6 ( 0x500 ) & 15 ;
if ( V_8 ) {
if ( V_8 & 8 ) F_7 ( 16 + 3 ) ;
if ( V_8 & 4 ) F_7 ( 16 + 2 ) ;
if ( V_8 & 2 ) F_7 ( 16 + 1 ) ;
if ( V_8 & 1 ) F_7 ( 16 + 0 ) ;
} else {
F_8 ( V_7 ) ;
}
}
static void
F_9 ( unsigned long V_7 )
{
int V_1 = ( V_7 - 0x800 ) >> 4 ;
F_7 ( V_1 ) ;
}
static void T_1
F_10 ( void )
{
long V_9 ;
F_11 ( 0 , V_10 ) ;
F_11 ( 0 , V_11 ) ;
F_11 ( V_12 , V_13 ) ;
F_11 ( 0 , V_14 ) ;
if ( V_15 )
V_16 . V_17 = F_9 ;
for ( V_9 = 16 ; V_9 < 128 ; V_9 += 16 )
F_1 ( V_9 , - 1 ) ;
F_12 () ;
for ( V_9 = 16 ; V_9 < 128 ; ++ V_9 ) {
F_13 ( V_9 , & V_18 , V_19 ) ;
F_14 ( V_9 , V_20 ) ;
}
}
static int T_1
F_15 ( const struct V_21 * V_22 , T_2 V_23 , T_2 V_24 )
{
T_2 V_25 ;
F_16 ( V_22 , V_26 , & V_25 ) ;
return V_25 - 0x80 ;
}
static T_2 T_1
F_17 ( struct V_21 * V_22 , T_2 * V_27 )
{
struct V_28 * V_29 = V_22 -> V_30 ;
int V_23 , V_24 = * V_27 ;
int V_31 = 0 ;
int V_32 = F_6 ( 0x502 ) & 0x0f ;
switch ( V_32 )
{
case 0x00 : V_31 = 0 ; break;
case 0x01 : V_31 = 1 ; break;
case 0x03 : V_31 = 2 ; break;
case 0x07 : V_31 = 3 ; break;
case 0x0f : V_31 = 4 ; break;
} ;
V_23 = F_18 ( V_22 -> V_33 ) ;
while ( V_22 -> V_34 -> V_35 ) {
if ( V_29 -> V_36 == 0
&& ( F_18 ( V_22 -> V_34 -> V_35 -> V_33 )
> 20 - V_31 ) ) {
V_23 = F_18 ( V_22 -> V_33 ) ;
break;
}
V_24 = F_19 ( V_22 , V_24 ) ;
V_22 = V_22 -> V_34 -> V_35 ;
}
* V_27 = V_24 ;
return V_23 ;
}
