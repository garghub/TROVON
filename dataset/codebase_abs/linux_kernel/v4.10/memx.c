static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 . V_4 ;
int V_7 ;
if ( V_2 -> V_8 . V_9 ) {
F_2 ( V_4 , 0x10a1c4 , ( V_2 -> V_8 . V_10 << 16 ) | V_2 -> V_8 . V_9 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_8 . V_10 ; V_7 ++ )
F_2 ( V_4 , 0x10a1c4 , V_2 -> V_8 . V_11 [ V_7 ] ) ;
V_2 -> V_8 . V_9 = 0 ;
V_2 -> V_8 . V_10 = 0 ;
}
}
static void
F_3 ( struct V_1 * V_2 , T_1 V_9 , T_1 V_10 , T_1 V_11 [] )
{
if ( ( V_2 -> V_8 . V_10 + V_10 >= F_4 ( V_2 -> V_8 . V_11 ) ) ||
( V_2 -> V_8 . V_9 && V_2 -> V_8 . V_9 != V_9 ) )
F_1 ( V_2 ) ;
memcpy ( & V_2 -> V_8 . V_11 [ V_2 -> V_8 . V_10 ] , V_11 , V_10 * sizeof( V_11 [ 0 ] ) ) ;
V_2 -> V_8 . V_10 += V_10 ;
V_2 -> V_8 . V_9 = V_9 ;
}
int
F_5 ( struct V_12 * V_5 , struct V_1 * * V_13 )
{
struct V_3 * V_4 = V_5 -> V_6 . V_4 ;
struct V_1 * V_2 ;
T_1 V_14 [ 2 ] ;
int V_15 ;
V_15 = F_6 ( V_5 , V_14 , V_16 , V_17 ,
V_18 , 0 ) ;
if ( V_15 )
return V_15 ;
V_2 = * V_13 = F_7 ( sizeof( * V_2 ) , V_19 ) ;
if ( ! V_2 )
return - V_20 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_21 = V_14 [ 0 ] ;
V_2 -> V_10 = V_14 [ 1 ] ;
do {
F_2 ( V_4 , 0x10a580 , 0x00000003 ) ;
} while ( F_8 ( V_4 , 0x10a580 ) != 0x00000003 );
F_2 ( V_4 , 0x10a1c0 , 0x01000000 | V_2 -> V_21 ) ;
return 0 ;
}
int
F_9 ( struct V_1 * * V_13 , bool V_22 )
{
struct V_1 * V_2 = * V_13 ;
struct V_12 * V_5 = V_2 -> V_5 ;
struct V_23 * V_6 = & V_5 -> V_6 ;
struct V_3 * V_4 = V_6 -> V_4 ;
T_1 V_24 , V_14 [ 2 ] ;
F_1 ( V_2 ) ;
V_24 = F_8 ( V_4 , 0x10a1c0 ) & 0x00ffffff ;
F_2 ( V_4 , 0x10a580 , 0x00000000 ) ;
if ( V_22 ) {
F_6 ( V_5 , V_14 , V_16 , V_25 ,
V_2 -> V_21 , V_24 ) ;
}
F_10 ( V_6 , L_1 ,
V_14 [ 0 ] , V_14 [ 1 ] ) ;
F_11 ( V_2 ) ;
return 0 ;
}
void
F_12 ( struct V_1 * V_2 , T_1 V_26 , T_1 V_11 )
{
F_10 ( & V_2 -> V_5 -> V_6 , L_2 , V_26 , V_11 ) ;
F_3 (memx, MEMX_WR32, 2 , (u32[]){ addr, data }) ;
}
void
F_13 ( struct V_1 * V_2 ,
T_1 V_26 , T_1 V_27 , T_1 V_11 , T_1 V_28 )
{
F_10 ( & V_2 -> V_5 -> V_6 , L_3 ,
V_26 , V_27 , V_11 , V_28 ) ;
F_3 (memx, MEMX_WAIT, 4 , (u32[]){ addr, mask, data, nsec }) ;
F_1 ( V_2 ) ;
}
void
F_14 ( struct V_1 * V_2 , T_1 V_28 )
{
F_10 ( & V_2 -> V_5 -> V_6 , L_4 , V_28 ) ;
F_3 (memx, MEMX_DELAY, 1 , (u32[]){ nsec }) ;
F_1 ( V_2 ) ;
}
void
F_15 ( struct V_1 * V_2 )
{
struct V_23 * V_6 = & V_2 -> V_5 -> V_6 ;
struct V_3 * V_4 = V_6 -> V_4 ;
T_1 V_29 , V_30 , V_31 , V_32 = 0 ;
int V_7 , V_33 ;
if ( V_4 -> V_34 < 0xd0 ) {
V_29 = F_8 ( V_4 , 0x610050 ) ;
for ( V_7 = 0 ; V_7 < 2 ; V_7 ++ ) {
if ( V_29 & ( 2 << ( V_7 << 3 ) ) ) {
V_30 = F_8 ( V_4 , 0x610b40 + ( 0x540 * V_7 ) ) ;
V_31 = ( V_30 & 0xffff0000 ) >> 16 ;
V_30 &= 0x0000ffff ;
if ( ( V_30 * V_31 ) > V_32 ) {
V_32 = ( V_30 * V_31 ) ;
V_33 = V_7 ;
}
}
}
}
if ( V_32 == 0 ) {
F_10 ( V_6 , L_5 ) ;
return;
}
F_10 ( V_6 , L_6 , V_33 ) ;
F_3 (memx, MEMX_VBLANK, 1 , (u32[]){ head_sync }) ;
F_1 ( V_2 ) ;
}
void
F_16 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_5 -> V_6 , L_7 ) ;
F_3 ( V_2 , V_35 , 0 , NULL ) ;
}
int
F_17 ( struct V_12 * V_5 , T_1 * V_36 , int V_37 )
{
struct V_3 * V_4 = V_5 -> V_6 . V_4 ;
T_1 V_14 [ 2 ] , V_21 , V_10 , V_7 ;
int V_15 ;
V_15 = F_6 ( V_5 , V_14 , V_16 , V_17 ,
V_38 , 0 ) ;
if ( V_15 )
return V_15 ;
V_21 = V_14 [ 0 ] ;
V_10 = V_14 [ 1 ] >> 2 ;
if ( V_10 > V_37 )
return - V_20 ;
F_2 ( V_4 , 0x10a1c0 , 0x02000000 | V_21 ) ;
for ( V_7 = 0 ; V_7 < V_10 ; V_7 ++ )
V_36 [ V_7 ] = F_8 ( V_4 , 0x10a1c4 ) ;
return 0 ;
}
void
F_18 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_5 -> V_6 , L_8 ) ;
F_3 ( V_2 , V_39 , 0 , NULL ) ;
}
void
F_19 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_5 -> V_6 , L_9 ) ;
F_3 ( V_2 , V_40 , 0 , NULL ) ;
}
