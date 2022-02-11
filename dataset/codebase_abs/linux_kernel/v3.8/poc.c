static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 ;
V_11 = F_2 ( V_6 -> V_12 ) ;
V_7 [ 0 ] = V_9 -> V_13 [ V_11 ] ;
return 1 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_14 ;
int V_11 ;
int V_15 ;
V_11 = F_2 ( V_6 -> V_12 ) ;
V_9 -> V_13 [ V_11 ] = V_7 [ 0 ] ;
V_15 = V_7 [ 0 ] ;
#ifdef F_4
if ( ( F_5 ( V_6 -> V_12 ) & 0x2 ) == 0 )
V_15 = ~ V_15 ;
#endif
V_14 = ( V_15 << 4 ) & 0xf0 ;
F_6 ( V_14 , V_2 -> V_16 + F_7 ( V_11 ) ) ;
V_14 = ( V_15 >> 4 ) & 0xff ;
F_6 ( V_14 , V_2 -> V_16 + F_8 ( V_11 ) ) ;
return 1 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 1 ] = F_10 ( V_2 -> V_16 + 0 ) ;
V_7 [ 1 ] |= ( F_10 ( V_2 -> V_16 + 1 ) << 8 ) ;
V_7 [ 1 ] |= ( F_10 ( V_2 -> V_16 + 2 ) << 16 ) ;
V_7 [ 1 ] |= ( F_10 ( V_2 -> V_16 + 3 ) << 24 ) ;
return V_6 -> V_17 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_7 [ 0 ] ) {
V_4 -> V_18 &= ~ V_7 [ 0 ] ;
V_4 -> V_18 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
if ( ( V_7 [ 0 ] >> 0 ) & 0xff )
F_6 ( ( V_4 -> V_18 >> 0 ) & 0xff , V_2 -> V_16 + 0 ) ;
if ( ( V_7 [ 0 ] >> 8 ) & 0xff )
F_6 ( ( V_4 -> V_18 >> 8 ) & 0xff , V_2 -> V_16 + 1 ) ;
if ( ( V_7 [ 0 ] >> 16 ) & 0xff )
F_6 ( ( V_4 -> V_18 >> 16 ) & 0xff , V_2 -> V_16 + 2 ) ;
if ( ( V_7 [ 0 ] >> 24 ) & 0xff )
F_6 ( ( V_4 -> V_18 >> 24 ) & 0xff , V_2 -> V_16 + 3 ) ;
}
V_7 [ 1 ] = V_4 -> V_18 ;
return V_6 -> V_17 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
const struct V_21 * V_22 = F_13 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
unsigned long V_16 ;
unsigned int V_23 ;
int V_24 ;
V_16 = V_20 -> V_25 [ 0 ] ;
F_14 ( V_26 L_1 , V_2 -> V_27 ,
V_22 -> V_28 , V_16 ) ;
V_2 -> V_29 = V_22 -> V_28 ;
if ( V_16 == 0 ) {
F_14 ( V_30 L_2 ) ;
return - V_31 ;
}
V_23 = V_22 -> V_23 ;
if ( ! F_15 ( V_16 , V_23 , L_3 ) ) {
F_14 ( V_30 L_4
L_5 , V_16 , V_16 + V_23 - 1 ) ;
return - V_32 ;
}
V_2 -> V_16 = V_16 ;
V_24 = F_16 ( V_2 , 1 ) ;
if ( V_24 )
return V_24 ;
V_9 = F_17 ( sizeof( * V_9 ) , V_33 ) ;
if ( ! V_9 )
return - V_34 ;
V_2 -> V_10 = V_9 ;
V_4 = & V_2 -> V_35 [ 0 ] ;
V_4 -> type = V_22 -> type ;
V_4 -> V_36 = V_22 -> V_36 ;
V_4 -> V_37 = ( 1 << V_22 -> V_38 ) - 1 ;
V_4 -> V_39 = V_22 -> V_40 ;
V_4 -> V_41 = V_22 -> V_42 ;
V_4 -> V_43 = V_22 -> V_44 ;
V_4 -> V_45 = V_22 -> V_46 ;
if ( V_4 -> type == V_47 || V_4 -> type == V_48 )
V_4 -> V_49 = V_50 ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
const struct V_21 * V_22 = F_13 ( V_2 ) ;
if ( V_2 -> V_16 )
F_19 ( V_2 -> V_16 , V_22 -> V_23 ) ;
}
