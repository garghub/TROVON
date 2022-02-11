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
void T_1 F_11 ( void )
{
F_12 ( V_8 , V_9 - V_10 ) ;
F_13 ( & V_11 , V_12 , 1 ,
V_9 - 1 ) ;
#ifdef F_14
V_13 . V_14 = 0x48 ;
#else
V_13 . V_14 = 0x40 ;
#endif
V_13 . V_15 = 0x00 ;
V_13 . V_16 = 0x00 ;
V_13 . V_17 = 0xff ;
V_13 . V_18 = 0xff ;
if ( F_15 ( V_19 ) ) {
#ifdef F_14
V_20 . V_14 = 0x58 ;
#else
V_20 . V_14 = 0x50 ;
#endif
V_20 . V_15 = 0x00 ;
V_20 . V_16 = 0x00 ;
V_20 . V_17 = 0xff ;
V_20 . V_18 = 0xff ;
}
if ( F_15 ( V_21 ) && ! V_22 ) {
V_23 . V_24 = 9 ;
F_16 () ;
V_23 . V_24 = ( char ) 0xc0 ;
}
if ( F_15 ( V_25 ) ) {
V_26 . V_27 = 0x10 ;
V_26 . V_28 = 0x60 ;
} else {
V_5 [ V_29 ] = V_7 ;
V_5 [ V_6 ] = V_7 ;
}
if ( F_15 ( V_30 ) && F_15 ( V_31 ) ) {
F_17 ( V_32 ) ;
}
F_18 () ;
V_33 . V_34 = 7 ;
V_33 . V_35 = 0xff ;
}
unsigned long F_19 ( void )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < 32 ; V_36 ++ )
if ( ( V_37 & ( 1 << V_36 ) ) == 0 )
break;
if ( V_36 == 16 )
return 0 ;
V_37 |= 1 << V_36 ;
return V_38 + V_36 ;
}
void F_20 ( unsigned long V_3 )
{
if ( V_3 >= V_38 && V_3 < V_38 + V_39 ) {
V_3 -= V_38 ;
V_37 &= ~ ( 1 << V_3 ) ;
}
}
