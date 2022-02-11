static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
if ( V_2 -> V_6 . V_7 ) {
F_2 ( V_4 , 0x10a1c4 , ( V_2 -> V_6 . V_7 << 16 ) | V_2 -> V_6 . V_8 ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 . V_7 ; V_5 ++ )
F_2 ( V_4 , 0x10a1c4 , V_2 -> V_6 . V_9 [ V_5 ] ) ;
V_2 -> V_6 . V_7 = 0 ;
}
}
static void
F_3 ( struct V_1 * V_2 , T_1 V_8 , T_1 V_7 , T_1 V_9 [] )
{
if ( ( V_2 -> V_6 . V_7 + V_7 >= F_4 ( V_2 -> V_6 . V_9 ) ) ||
( V_2 -> V_6 . V_7 && V_2 -> V_6 . V_8 != V_8 ) )
F_1 ( V_2 ) ;
memcpy ( & V_2 -> V_6 . V_9 [ V_2 -> V_6 . V_7 ] , V_9 , V_7 * sizeof( V_9 [ 0 ] ) ) ;
V_2 -> V_6 . V_7 += V_7 ;
V_2 -> V_6 . V_8 = V_8 ;
}
int
F_5 ( struct V_3 * V_4 , struct V_1 * * V_10 )
{
struct V_1 * V_2 ;
T_1 V_11 [ 2 ] ;
int V_12 ;
V_12 = V_4 -> V_13 ( V_4 , V_11 , V_14 , V_15 , 0 , 0 ) ;
if ( V_12 )
return V_12 ;
V_2 = * V_10 = F_6 ( sizeof( * V_2 ) , V_16 ) ;
if ( ! V_2 )
return - V_17 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_18 = V_11 [ 0 ] ;
V_2 -> V_7 = V_11 [ 1 ] ;
do {
F_2 ( V_4 , 0x10a580 , 0x00000003 ) ;
} while ( F_7 ( V_4 , 0x10a580 ) != 0x00000003 );
F_2 ( V_4 , 0x10a1c0 , 0x01000000 | V_2 -> V_18 ) ;
F_2 ( V_4 , 0x10a1c4 , 0x00010000 | V_19 ) ;
F_2 ( V_4 , 0x10a1c4 , 0x00000000 ) ;
return 0 ;
}
int
F_8 ( struct V_1 * * V_10 , bool V_20 )
{
struct V_1 * V_2 = * V_10 ;
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_21 , V_11 [ 2 ] ;
F_1 ( V_2 ) ;
F_2 ( V_4 , 0x10a1c4 , 0x00000000 | V_22 ) ;
V_21 = F_7 ( V_4 , 0x10a1c0 ) & 0x00ffffff ;
F_2 ( V_4 , 0x10a580 , 0x00000000 ) ;
if ( V_20 ) {
V_4 -> V_13 ( V_4 , V_11 , V_14 , V_23 ,
V_2 -> V_18 , V_21 ) ;
}
F_9 ( V_2 ) ;
return 0 ;
}
void
F_10 ( struct V_1 * V_2 , T_1 V_24 , T_1 V_9 )
{
F_11 ( V_2 -> V_4 , L_1 , V_24 , V_9 ) ;
F_3 (memx, MEMX_WR32, 2 , (u32[]){ addr, data }) ;
}
void
F_12 ( struct V_1 * V_2 ,
T_1 V_24 , T_1 V_25 , T_1 V_9 , T_1 V_26 )
{
F_11 ( V_2 -> V_4 , L_2 ,
V_24 , V_25 , V_9 , V_26 ) ;
F_3 (memx, MEMX_WAIT, 4 , (u32[]){ addr, ~mask, data, nsec }) ;
F_1 ( V_2 ) ;
}
void
F_13 ( struct V_1 * V_2 , T_1 V_26 )
{
F_11 ( V_2 -> V_4 , L_3 , V_26 ) ;
F_3 (memx, MEMX_DELAY, 1 , (u32[]){ nsec }) ;
F_1 ( V_2 ) ;
}
