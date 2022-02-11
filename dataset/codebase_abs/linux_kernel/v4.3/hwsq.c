static void
F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 [] )
{
memcpy ( & V_2 -> V_5 . V_4 [ V_2 -> V_5 . V_3 ] , V_4 , V_3 * sizeof( V_4 [ 0 ] ) ) ;
V_2 -> V_5 . V_3 += V_3 ;
}
int
F_2 ( struct V_6 * V_7 , struct V_1 * * V_8 )
{
struct V_1 * V_2 ;
V_2 = * V_8 = F_3 ( sizeof( * V_2 ) , V_9 ) ;
if ( V_2 ) {
V_2 -> V_7 = V_7 ;
V_2 -> V_10 = ~ 0 ;
V_2 -> V_4 = ~ 0 ;
memset ( V_2 -> V_5 . V_4 , 0x7f , sizeof( V_2 -> V_5 . V_4 ) ) ;
V_2 -> V_5 . V_3 = 0 ;
}
return V_2 ? 0 : - V_11 ;
}
int
F_4 ( struct V_1 * * V_8 , bool V_12 )
{
struct V_1 * V_2 = * V_8 ;
int V_13 = 0 , V_14 ;
if ( V_2 ) {
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_17 -> V_16 ;
V_2 -> V_5 . V_3 = ( V_2 -> V_5 . V_3 + 4 ) / 4 ;
if ( V_2 -> V_5 . V_3 <= V_16 -> V_18 -> V_19 ) {
if ( V_12 )
V_13 = V_16 -> V_18 -> V_20 ( V_16 ,
( V_21 * ) V_2 -> V_5 . V_4 ,
V_2 -> V_5 . V_3 ) ;
if ( V_13 )
F_5 ( V_7 , L_1 , V_13 ) ;
} else {
F_5 ( V_7 , L_2 ) ;
V_13 = - V_22 ;
}
for ( V_14 = 0 ; V_13 && V_14 < V_2 -> V_5 . V_3 ; V_14 ++ )
F_5 ( V_7 , L_3 , ( ( V_21 * ) V_2 -> V_5 . V_4 ) [ V_14 ] ) ;
* V_8 = NULL ;
F_6 ( V_2 ) ;
}
return V_13 ;
}
void
F_7 ( struct V_1 * V_2 , V_21 V_10 , V_21 V_4 )
{
F_8 ( V_2 -> V_7 , L_4 , V_10 , V_4 ) ;
if ( V_2 -> V_4 != V_4 ) {
if ( ( V_4 & 0xffff0000 ) != ( V_2 -> V_4 & 0xffff0000 ) ) {
F_1 (hwsq, 5 , (u8[]){ 0xe2 , data, data >> 8 ,
data >> 16 , data >> 24 }) ;
} else {
F_1 (hwsq, 3 , (u8[]){ 0x42 , data, data >> 8 }) ;
}
}
if ( ( V_10 & 0xffff0000 ) != ( V_2 -> V_10 & 0xffff0000 ) ) {
F_1 (hwsq, 5 , (u8[]){ 0xe0 , addr, addr >> 8 ,
addr >> 16 , addr >> 24 }) ;
} else {
F_1 (hwsq, 3 , (u8[]){ 0x40 , addr, addr >> 8 }) ;
}
V_2 -> V_10 = V_10 ;
V_2 -> V_4 = V_4 ;
}
void
F_9 ( struct V_1 * V_2 , T_1 V_23 , int V_4 )
{
F_8 ( V_2 -> V_7 , L_5 , V_23 , V_4 ) ;
V_23 += 0x80 ;
if ( V_4 >= 0 )
V_23 += 0x20 ;
if ( V_4 >= 1 )
V_23 += 0x20 ;
F_1 (hwsq, 1 , (u8[]){ flag }) ;
}
void
F_10 ( struct V_1 * V_2 , T_1 V_23 , T_1 V_4 )
{
F_8 ( V_2 -> V_7 , L_6 , V_23 , V_4 ) ;
F_1 (hwsq, 3 , (u8[]){ 0x5f , flag, data }) ;
}
void
F_11 ( struct V_1 * V_2 , V_21 V_24 )
{
T_1 V_25 = 0 , V_26 = V_24 / 1000 ;
while ( V_26 & ~ 3 ) {
V_26 >>= 2 ;
V_25 ++ ;
}
F_8 ( V_2 -> V_7 , L_7 , V_24 ) ;
F_1 (hwsq, 1 , (u8[]){ 0x00 | (shift << 2) | usec }) ;
}
