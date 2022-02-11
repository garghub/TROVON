static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
unsigned int V_8 ;
V_8 = F_2 ( V_2 -> V_9 + V_10 ) ;
if ( ( V_8 & 0x3 ) == 0x3 )
return 0 ;
return - V_11 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_12 )
{
unsigned int V_13 = F_4 ( V_6 -> V_14 ) ;
unsigned int V_15 = F_5 ( V_6 -> V_14 ) ;
unsigned int V_16 ;
int V_17 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_6 -> V_19 ; V_18 ++ ) {
F_6 ( V_13 , V_2 -> V_9 + V_20 ) ;
V_17 = F_7 ( V_2 , V_4 , V_6 , F_1 , 0 ) ;
if ( V_17 )
return V_17 ;
V_16 = F_2 ( V_2 -> V_9 + V_21 ) |
( F_2 ( V_2 -> V_9 + V_22 ) << 8 ) ;
if ( V_4 -> V_23 == 0x0fff )
V_16 >>= 4 ;
if ( F_8 ( V_4 , V_15 ) ) {
V_16 ^= ( ( V_4 -> V_23 + 1 ) >> 1 ) ;
}
V_12 [ V_18 ] = V_16 ;
}
return V_6 -> V_19 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
const struct V_26 * V_27 = V_2 -> V_28 ;
struct V_3 * V_4 ;
int V_17 ;
V_17 = F_10 ( V_2 , V_25 -> V_29 [ 0 ] , 0x04 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_11 ( V_2 , 1 ) ;
if ( V_17 )
return V_17 ;
V_4 = & V_2 -> V_30 [ 0 ] ;
V_4 -> type = V_31 ;
if ( V_25 -> V_29 [ 1 ] ) {
V_4 -> V_32 = V_33 | V_34 ;
V_4 -> V_35 = 8 ;
} else {
V_4 -> V_32 = V_33 | V_36 ;
V_4 -> V_35 = 16 ;
}
V_4 -> V_37 = 1 ;
V_4 -> V_23 = V_27 -> V_38 ;
V_4 -> V_39 = V_25 -> V_29 [ 2 ] ? & V_40 : & V_41 ;
V_4 -> V_42 = F_3 ;
return 0 ;
}
