static void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
unsigned long V_7 , V_8 , V_9 , V_10 ;
V_7 = 0 ;
if ( V_4 [ 0 ] . V_11 && V_4 [ 0 ] . V_12 )
V_7 |= ( V_4 [ 0 ] . V_12 & 1 ) << 4 ;
if ( V_4 [ 1 ] . V_11 )
V_7 |= ( V_4 [ 1 ] . V_12 - 2 ) & 15 ;
V_2 -> V_13 = V_7 ;
V_2 -> V_14 = 0 ;
V_8 = V_9 = 0 ;
for ( V_10 = 0 ; V_10 < 2 ; ++ V_10 ) {
unsigned long V_15 = V_4 [ V_10 ] . V_15 ;
if ( ! V_4 [ V_10 ] . V_11 )
continue;
if ( V_15 > 0x100000 )
V_15 = 0x100000 ;
V_4 [ V_10 ] . V_15 = V_15 ;
V_8 |= ( 0x100000 - V_15 ) << ( V_10 ? 6 : 28 ) ;
if ( V_15 != 0x100000 )
V_9 |= 1 << V_10 ;
}
V_2 -> V_16 = V_8 ;
V_2 -> V_9 = V_9 ;
}
static void
F_2 ( void * V_17 )
{
struct V_1 * V_2 = V_17 ;
F_3 ( 2 , V_2 -> V_13 ) ;
F_3 ( 3 , V_2 -> V_14 ) ;
F_3 ( 6 , V_2 -> V_16 | 3 ) ;
}
static void
F_4 ( struct V_1 * V_2 , unsigned long V_4 )
{
F_3 ( 6 , V_2 -> V_16 | ( 1 << V_4 ) ) ;
}
static void
F_5 ( unsigned long V_18 , struct V_19 * V_20 ,
struct V_3 * V_4 )
{
F_6 ( V_20 , V_18 ) ;
}
