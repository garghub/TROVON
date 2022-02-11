static int F_1 ( unsigned long * V_1 , T_1 V_2 )
{
T_2 V_3 = F_2 ( * V_1 ) ;
T_2 V_4 ;
T_2 V_5 ;
int V_6 ;
T_1 free = 0xffff ;
T_1 V_7 ;
for ( V_7 = V_2 ; V_7 ; V_7 >>= 4 , V_3 >>= 4 ) {
if ( ( V_7 & 0xf ) == V_8 )
continue;
free &= ~ ( 1 << ( V_3 & 0xf ) ) ;
}
if ( free & ( 1 << 15 ) )
return 15 ;
if ( ! free )
return - 1 ;
V_6 = free = F_3 ( free ) - 1 ;
V_4 = F_2 ( * V_1 ) ;
V_3 = V_4 ;
V_7 = V_2 ;
V_5 = 0xf ;
for (; V_7 ; V_7 >>= 4 , V_5 <<= 4 , free <<= 4 , V_4 >>= 4 ) {
if ( ( V_7 & 0xf ) == V_8 )
continue;
if ( ( V_4 & 0xf ) != 15 )
continue;
V_3 &= ~ V_5 ;
V_3 |= free & V_5 ;
}
* V_1 = F_4 ( V_3 ) ;
return V_6 ;
}
static void F_5 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
struct V_13 * V_7 )
{
T_1 V_14 = V_10 -> V_14 ;
V_12 -> V_15 = V_7 -> V_16 [ V_14 ] ;
V_7 -> V_16 [ V_14 ] = V_7 -> V_17 + 8 ;
}
static void F_6 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
struct V_13 * V_7 )
{
V_7 -> V_16 [ V_10 -> V_14 ] = V_12 -> V_15 ;
}
static void F_7 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
struct V_13 * V_7 )
{
T_1 V_14 = V_10 -> V_14 ;
F_8 ( V_7 -> V_16 [ V_14 ] , V_7 ) ;
V_7 -> V_16 [ V_14 ] = V_12 -> V_15 ;
}
static void F_9 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
struct V_13 * V_7 )
{
T_1 V_14 = V_10 -> V_14 ;
F_10 ( V_7 -> V_16 [ V_14 ] , V_7 ) ;
V_7 -> V_16 [ V_14 ] = V_12 -> V_15 ;
}
enum V_18
F_11 ( T_2 V_3 , struct V_19 * V_20 ,
const struct V_21 * V_22 )
{
struct V_9 * V_10 = F_12 ( V_20 , struct V_9 ,
V_20 ) ;
struct V_23 * V_24 = (struct V_23 * ) V_22 ;
T_1 V_7 = V_24 -> V_25 . V_26 . V_27 >> V_28 ;
int V_29 ;
V_29 = F_1 ( & V_10 -> V_30 [ 0 ] , V_7 ) ;
if ( V_29 == 15 )
return V_31 ;
if ( V_29 == - 1 )
return V_32 ;
V_10 -> V_14 = V_29 ;
V_10 -> V_33 = F_5 ;
V_10 -> V_34 = F_6 ;
return V_31 ;
}
enum V_18
F_13 ( T_2 V_3 , struct V_19 * V_20 ,
const struct V_21 * V_22 , bool V_35 )
{
struct V_9 * V_10 = F_12 ( V_20 , struct V_9 ,
V_20 ) ;
enum V_18 V_36 = F_11 ( V_3 , V_20 , V_22 ) ;
if ( ( ( V_3 >> 12 ) & 0xf ) == 15 )
V_10 -> V_34 = V_35 ? F_7
: F_9 ;
return V_36 ;
}
enum V_18
F_14 ( T_2 V_3 ,
struct V_19 * V_20 ,
const struct V_21 * V_22 )
{
return F_13 ( V_3 , V_20 , V_22 , true ) ;
}
enum V_18
F_15 ( T_2 V_3 , struct V_19 * V_20 ,
const struct V_21 * V_22 )
{
return F_13 ( V_3 , V_20 , V_22 , false ) ;
}
enum V_18
F_16 ( T_2 V_3 ,
struct V_19 * V_20 ,
const struct V_21 * V_22 )
{
struct V_9 * V_10 = F_12 ( V_20 , struct V_9 ,
V_20 ) ;
unsigned V_37 = V_3 & 0xffff ;
int V_38 = ( V_3 >> 16 ) & 0xf ;
int V_39 = V_3 & ( 1 << 20 ) ;
unsigned V_40 = V_37 | ( 1 << V_38 ) ;
if ( V_38 == 15 )
return V_32 ;
if ( ! ( V_40 & ( 1 << 15 ) ) )
return V_31 ;
if ( V_40 & ( 1 << 14 ) )
return V_32 ;
V_3 ^= 0xc000 ;
V_10 -> V_14 = 14 ;
V_10 -> V_30 [ 0 ] = F_4 ( V_3 ) ;
V_10 -> V_33 = F_5 ;
if ( V_39 )
V_10 -> V_34 = F_9 ;
else
V_10 -> V_34 = F_6 ;
return V_31 ;
}
