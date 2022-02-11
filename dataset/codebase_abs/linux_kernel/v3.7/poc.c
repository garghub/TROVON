static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 ;
V_8 = F_2 ( V_6 -> V_9 ) ;
V_7 [ 0 ] = ( ( unsigned int * ) V_2 -> V_10 ) [ V_8 ] ;
return 1 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_11 ;
int V_8 ;
int V_12 ;
V_8 = F_2 ( V_6 -> V_9 ) ;
( ( unsigned int * ) V_2 -> V_10 ) [ V_8 ] = V_7 [ 0 ] ;
V_12 = V_7 [ 0 ] ;
#ifdef F_4
if ( ( F_5 ( V_6 -> V_9 ) & 0x2 ) == 0 )
V_12 = ~ V_12 ;
#endif
V_11 = ( V_12 << 4 ) & 0xf0 ;
F_6 ( V_11 , V_2 -> V_13 + F_7 ( V_8 ) ) ;
V_11 = ( V_12 >> 4 ) & 0xff ;
F_6 ( V_11 , V_2 -> V_13 + F_8 ( V_8 ) ) ;
return 1 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 1 ] = F_10 ( V_2 -> V_13 + 0 ) ;
V_7 [ 1 ] |= ( F_10 ( V_2 -> V_13 + 1 ) << 8 ) ;
V_7 [ 1 ] |= ( F_10 ( V_2 -> V_13 + 2 ) << 16 ) ;
V_7 [ 1 ] |= ( F_10 ( V_2 -> V_13 + 3 ) << 24 ) ;
return V_6 -> V_14 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_7 [ 0 ] ) {
V_4 -> V_15 &= ~ V_7 [ 0 ] ;
V_4 -> V_15 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
if ( ( V_7 [ 0 ] >> 0 ) & 0xff )
F_6 ( ( V_4 -> V_15 >> 0 ) & 0xff , V_2 -> V_13 + 0 ) ;
if ( ( V_7 [ 0 ] >> 8 ) & 0xff )
F_6 ( ( V_4 -> V_15 >> 8 ) & 0xff , V_2 -> V_13 + 1 ) ;
if ( ( V_7 [ 0 ] >> 16 ) & 0xff )
F_6 ( ( V_4 -> V_15 >> 16 ) & 0xff , V_2 -> V_13 + 2 ) ;
if ( ( V_7 [ 0 ] >> 24 ) & 0xff )
F_6 ( ( V_4 -> V_15 >> 24 ) & 0xff , V_2 -> V_13 + 3 ) ;
}
V_7 [ 1 ] = V_4 -> V_15 ;
return V_6 -> V_14 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
const struct V_18 * V_19 = F_13 ( V_2 ) ;
struct V_3 * V_4 ;
unsigned long V_13 ;
unsigned int V_20 ;
int V_21 ;
V_13 = V_17 -> V_22 [ 0 ] ;
F_14 ( V_23 L_1 , V_2 -> V_24 ,
V_19 -> V_25 , V_13 ) ;
V_2 -> V_26 = V_19 -> V_25 ;
if ( V_13 == 0 ) {
F_14 ( V_27 L_2 ) ;
return - V_28 ;
}
V_20 = V_19 -> V_20 ;
if ( ! F_15 ( V_13 , V_20 , L_3 ) ) {
F_14 ( V_27 L_4
L_5 , V_13 , V_13 + V_20 - 1 ) ;
return - V_29 ;
}
V_2 -> V_13 = V_13 ;
V_21 = F_16 ( V_2 , 1 ) ;
if ( V_21 )
return V_21 ;
if ( F_17 ( V_2 , sizeof( unsigned int ) * V_19 -> V_30 ) < 0 )
return - V_31 ;
V_4 = & V_2 -> V_32 [ 0 ] ;
V_4 -> type = V_19 -> type ;
V_4 -> V_30 = V_19 -> V_30 ;
V_4 -> V_33 = ( 1 << V_19 -> V_34 ) - 1 ;
V_4 -> V_35 = V_19 -> V_36 ;
V_4 -> V_37 = V_19 -> V_38 ;
V_4 -> V_39 = V_19 -> V_40 ;
V_4 -> V_41 = V_19 -> V_42 ;
if ( V_4 -> type == V_43 || V_4 -> type == V_44 )
V_4 -> V_45 = V_46 ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
const struct V_18 * V_19 = F_13 ( V_2 ) ;
if ( V_2 -> V_13 )
F_19 ( V_2 -> V_13 , V_19 -> V_20 ) ;
}
