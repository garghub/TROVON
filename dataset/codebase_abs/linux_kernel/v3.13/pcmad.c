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
static int F_3 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
unsigned int * V_12 )
{
unsigned int V_13 = F_4 ( V_11 -> V_14 ) ;
unsigned int V_15 = F_5 ( V_11 -> V_14 ) ;
unsigned int V_16 ;
int V_17 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_11 -> V_18 ; V_4 ++ ) {
F_6 ( V_13 , V_2 -> V_5 + V_19 ) ;
V_17 = F_1 ( V_2 , V_20 ) ;
if ( V_17 )
return V_17 ;
V_16 = F_2 ( V_2 -> V_5 + V_21 ) |
( F_2 ( V_2 -> V_5 + V_22 ) << 8 ) ;
if ( V_9 -> V_23 == 0x0fff )
V_16 >>= 4 ;
if ( F_7 ( V_9 , V_15 ) ) {
V_16 ^= ( ( V_9 -> V_23 + 1 ) >> 1 ) ;
}
V_12 [ V_4 ] = V_16 ;
}
return V_11 -> V_18 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
const struct V_26 * V_27 = F_9 ( V_2 ) ;
struct V_8 * V_9 ;
int V_17 ;
V_17 = F_10 ( V_2 , V_25 -> V_28 [ 0 ] , 0x04 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_11 ( V_2 , 1 ) ;
if ( V_17 )
return V_17 ;
V_9 = & V_2 -> V_29 [ 0 ] ;
V_9 -> type = V_30 ;
if ( V_25 -> V_28 [ 1 ] ) {
V_9 -> V_31 = V_32 | V_33 ;
V_9 -> V_34 = 8 ;
} else {
V_9 -> V_31 = V_32 | V_35 ;
V_9 -> V_34 = 16 ;
}
V_9 -> V_36 = 1 ;
V_9 -> V_23 = V_27 -> V_37 ;
V_9 -> V_38 = V_25 -> V_28 [ 2 ] ? & V_39 : & V_40 ;
V_9 -> V_41 = F_3 ;
return 0 ;
}
