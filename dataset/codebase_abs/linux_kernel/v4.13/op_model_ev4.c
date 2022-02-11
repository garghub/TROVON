static void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
unsigned long V_7 = 0 , V_8 , V_9 ;
V_7 |= ( V_4 [ 0 ] . V_10 ? V_4 [ 0 ] . V_11 << 8 : 14 << 8 ) ;
V_7 |= ( V_4 [ 1 ] . V_10 ? ( V_4 [ 1 ] . V_11 - 16 ) << 32 : 7ul << 32 ) ;
V_8 = V_4 [ 0 ] . V_8 ;
if ( V_8 <= 4096 )
V_8 = 4096 , V_9 = 1 ;
else
V_8 = 65536 , V_9 = 0 ;
V_4 [ 0 ] . V_8 = V_8 ;
V_7 |= ( V_4 [ 0 ] . V_10 && V_9 ) << 3 ;
V_8 = V_4 [ 1 ] . V_8 ;
if ( V_8 <= 256 )
V_8 = 256 , V_9 = 1 ;
else
V_8 = 4096 , V_9 = 0 ;
V_4 [ 1 ] . V_8 = V_8 ;
V_7 |= ( V_4 [ 1 ] . V_10 && V_9 ) ;
V_2 -> V_12 = V_7 ;
V_2 -> V_13 = 0 ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = 0 ;
}
static void
F_2 ( void * V_17 )
{
struct V_1 * V_2 = V_17 ;
F_3 ( 2 , V_2 -> V_12 ) ;
F_3 ( 3 , V_2 -> V_13 ) ;
}
static void
F_4 ( unsigned long V_18 , struct V_19 * V_20 ,
struct V_3 * V_4 )
{
if ( ! V_4 [ V_18 ] . V_10 )
return;
F_5 ( V_20 , V_18 ) ;
}
