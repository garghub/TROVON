static unsigned int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
F_2 ( V_2 ) ;
F_3 ( V_3 ) ;
F_4 ( V_3 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_3 ;
F_6 ( V_3 ) ;
F_7 ( V_3 ) ;
F_8 ( V_2 ) ;
if ( V_3 == V_4 )
V_5 [ V_6 ] = V_7 ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_3 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_3 ) ;
}
static T_1 F_11 ( int V_3 , void * V_8 )
{
struct V_9 * V_10 = V_8 ;
int V_11 ;
unsigned char V_12 ;
V_11 = V_10 -> V_13 ;
V_12 = V_10 -> V_14 ;
for (; V_12 ; V_11 ++ , V_12 >>= 1 ) {
if ( V_12 & 1 )
F_12 ( V_11 ) ;
}
return V_15 ;
}
static void F_13 ( struct V_1 * V_2 )
{
int V_16 = V_2 -> V_3 - V_17 ;
V_18 . V_14 |= 1 << V_16 ;
F_4 ( V_19 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
int V_16 = V_2 -> V_3 - V_17 ;
V_18 . V_14 &= ~ ( 1 << V_16 ) ;
if ( ! V_18 . V_14 )
F_6 ( V_19 ) ;
}
static unsigned int F_15 ( struct V_1 * V_2 )
{
int V_20 = 140 - V_2 -> V_3 + 1 ;
F_2 ( V_2 ) ;
if ( ! V_21 )
V_21 = ( unsigned char * ) F_16 ( ( V_22 + 0x23 ) , 0x2 ) ;
if ( V_20 == 1 )
* V_21 |= 1 << V_20 ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
int V_20 = 140 - V_2 -> V_3 + 1 ;
if ( ! V_21 )
V_21 = ( unsigned char * ) F_16 ( ( V_22 + 0x23 ) , 0x2 ) ;
* V_21 |= 1 << V_20 ;
}
static void F_18 ( struct V_1 * V_2 )
{
int V_20 = 140 - V_2 -> V_3 + 1 ;
if ( ! V_21 )
V_21 = ( unsigned char * ) F_16 ( ( V_22 + 0x23 ) , 0x2 ) ;
* V_21 &= ~ ( 1 << V_20 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
int V_20 = 140 - V_2 -> V_3 + 1 ;
if ( V_21 ) {
* V_21 &= ~ ( 1 << V_20 ) ;
F_20 ( V_21 ) ;
V_21 = NULL ;
}
}
void T_2 F_21 ( void )
{
F_22 ( V_23 , V_24 - V_25 ) ;
F_23 ( & V_26 , V_27 , 1 ,
V_24 - 1 ) ;
#ifdef F_24
V_28 . V_29 = 0x48 ;
#else
V_28 . V_29 = 0x40 ;
#endif
V_28 . V_30 = 0x00 ;
V_28 . V_31 = 0x00 ;
V_28 . V_32 = 0xff ;
V_28 . V_33 = 0xff ;
if ( F_25 ( V_34 ) ) {
#ifdef F_24
V_35 . V_29 = 0x58 ;
#else
V_35 . V_29 = 0x50 ;
#endif
V_35 . V_30 = 0x00 ;
V_35 . V_31 = 0x00 ;
V_35 . V_32 = 0xff ;
V_35 . V_33 = 0xff ;
}
if ( F_25 ( V_36 ) && ! V_37 ) {
V_38 . V_39 = 9 ;
F_26 () ;
V_38 . V_39 = ( char ) 0xc0 ;
}
if ( F_25 ( V_40 ) ) {
V_41 . V_42 = 0x10 ;
V_41 . V_43 = 0x60 ;
} else {
V_5 [ V_44 ] = V_7 ;
V_5 [ V_6 ] = V_7 ;
}
if ( F_25 ( V_45 ) && F_25 ( V_46 ) ) {
F_27 ( V_47 ) ;
}
F_28 () ;
V_48 . V_49 = 7 ;
V_48 . V_50 = 0xff ;
F_23 ( & V_51 , V_27 ,
V_17 , 8 ) ;
V_28 . V_52 = 254 ;
V_28 . V_53 = ( V_28 . V_53 & 0xf0 ) | 0x6 ;
if ( F_29 ( V_19 , F_11 , V_54 ,
V_18 . V_55 , & V_18 ) )
F_30 ( L_1 , V_18 . V_55 ) ;
F_23 ( & V_56 , V_27 ,
139 , 2 ) ;
}
unsigned int F_31 ( void )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < 32 ; V_57 ++ )
if ( ( V_58 & ( 1 << V_57 ) ) == 0 )
break;
if ( V_57 == 16 )
return 0 ;
V_58 |= 1 << V_57 ;
return V_59 + V_57 ;
}
void F_32 ( unsigned int V_3 )
{
if ( V_3 >= V_59 && V_3 < V_59 + V_60 ) {
V_3 -= V_59 ;
V_58 &= ~ ( 1 << V_3 ) ;
}
}
