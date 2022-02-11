static int F_1 ( struct V_1 * V_2 ,
int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
if ( ( F_2 ( V_2 -> V_5 + V_6 ) & 0x3 ) == 0x3 )
return 0 ;
}
return - V_7 ;
}
static bool F_3 ( struct V_8 * V_9 ,
unsigned int V_10 )
{
return V_9 -> V_11 -> V_10 [ V_10 ] . V_12 < 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_13 * V_14 ,
unsigned int * V_15 )
{
unsigned int V_16 = F_5 ( V_14 -> V_17 ) ;
unsigned int V_10 = F_6 ( V_14 -> V_17 ) ;
unsigned int V_18 ;
int V_19 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_14 -> V_20 ; V_4 ++ ) {
F_7 ( V_16 , V_2 -> V_5 + V_21 ) ;
V_19 = F_1 ( V_2 , V_22 ) ;
if ( V_19 )
return V_19 ;
V_18 = F_2 ( V_2 -> V_5 + V_23 ) |
( F_2 ( V_2 -> V_5 + V_24 ) << 8 ) ;
if ( V_9 -> V_25 == 0x0fff )
V_18 >>= 4 ;
if ( F_3 ( V_9 , V_10 ) ) {
V_18 ^= ( ( V_9 -> V_25 + 1 ) >> 1 ) ;
}
V_15 [ V_4 ] = V_18 ;
}
return V_14 -> V_20 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
const struct V_28 * V_29 = F_9 ( V_2 ) ;
struct V_8 * V_9 ;
int V_19 ;
V_19 = F_10 ( V_2 , V_27 -> V_30 [ 0 ] , 0x04 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_11 ( V_2 , 1 ) ;
if ( V_19 )
return V_19 ;
V_9 = & V_2 -> V_31 [ 0 ] ;
V_9 -> type = V_32 ;
if ( V_27 -> V_30 [ 1 ] ) {
V_9 -> V_33 = V_34 | V_35 ;
V_9 -> V_36 = 8 ;
} else {
V_9 -> V_33 = V_34 | V_37 ;
V_9 -> V_36 = 16 ;
}
V_9 -> V_38 = 1 ;
V_9 -> V_25 = V_29 -> V_39 ;
V_9 -> V_11 = V_27 -> V_30 [ 2 ] ? & V_40 : & V_41 ;
V_9 -> V_42 = F_4 ;
return 0 ;
}
