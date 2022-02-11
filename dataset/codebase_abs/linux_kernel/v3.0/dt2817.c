static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static int F_5 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
int V_9 ;
int V_10 ;
int V_11 = 0 ;
if ( V_7 -> V_12 != 1 )
return - V_13 ;
V_10 = F_6 ( V_7 -> V_14 ) ;
if ( V_10 < 8 )
V_9 = 0xff ;
else if ( V_10 < 16 )
V_9 = 0xff00 ;
else if ( V_10 < 24 )
V_9 = 0xff0000 ;
else
V_9 = 0xff000000 ;
if ( V_8 [ 0 ] )
V_5 -> V_15 |= V_9 ;
else
V_5 -> V_15 &= ~ V_9 ;
if ( V_5 -> V_15 & 0x000000ff )
V_11 |= 0x1 ;
if ( V_5 -> V_15 & 0x0000ff00 )
V_11 |= 0x2 ;
if ( V_5 -> V_15 & 0x00ff0000 )
V_11 |= 0x4 ;
if ( V_5 -> V_15 & 0xff000000 )
V_11 |= 0x8 ;
F_7 ( V_11 , V_3 -> V_16 + V_17 ) ;
return 1 ;
}
static int F_8 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
unsigned int V_18 ;
if ( V_8 [ 0 ] ) {
V_18 = V_5 -> V_19 ;
V_5 -> V_19 &= ~ V_8 [ 0 ] ;
V_5 -> V_19 |= ( V_8 [ 0 ] & V_8 [ 1 ] ) ;
V_18 ^= V_5 -> V_19 ;
V_18 &= V_5 -> V_15 ;
if ( V_18 & 0x000000ff )
F_7 ( V_5 -> V_19 & 0xff , V_3 -> V_16 + V_20 + 0 ) ;
if ( V_18 & 0x0000ff00 )
F_7 ( ( V_5 -> V_19 >> 8 ) & 0xff ,
V_3 -> V_16 + V_20 + 1 ) ;
if ( V_18 & 0x00ff0000 )
F_7 ( ( V_5 -> V_19 >> 16 ) & 0xff ,
V_3 -> V_16 + V_20 + 2 ) ;
if ( V_18 & 0xff000000 )
F_7 ( ( V_5 -> V_19 >> 24 ) & 0xff ,
V_3 -> V_16 + V_20 + 3 ) ;
}
V_8 [ 1 ] = F_9 ( V_3 -> V_16 + V_20 + 0 ) ;
V_8 [ 1 ] |= ( F_9 ( V_3 -> V_16 + V_20 + 1 ) << 8 ) ;
V_8 [ 1 ] |= ( F_9 ( V_3 -> V_16 + V_20 + 2 ) << 16 ) ;
V_8 [ 1 ] |= ( F_9 ( V_3 -> V_16 + V_20 + 3 ) << 24 ) ;
return 2 ;
}
static int F_10 ( struct V_2 * V_3 , struct V_21 * V_22 )
{
int V_23 ;
struct V_4 * V_5 ;
unsigned long V_16 ;
V_16 = V_22 -> V_24 [ 0 ] ;
F_11 ( V_25 L_1 , V_3 -> V_26 , V_16 ) ;
if ( ! F_12 ( V_16 , V_27 , L_2 ) ) {
F_11 ( L_3 ) ;
return - V_28 ;
}
V_3 -> V_16 = V_16 ;
V_3 -> V_29 = L_2 ;
V_23 = F_13 ( V_3 , 1 ) ;
if ( V_23 < 0 )
return V_23 ;
V_5 = V_3 -> V_30 + 0 ;
V_5 -> V_31 = 32 ;
V_5 -> type = V_32 ;
V_5 -> V_33 = V_34 | V_35 ;
V_5 -> V_36 = & V_37 ;
V_5 -> V_38 = 1 ;
V_5 -> V_39 = F_8 ;
V_5 -> V_40 = F_5 ;
V_5 -> V_19 = 0 ;
F_7 ( 0 , V_3 -> V_16 + V_17 ) ;
F_11 ( V_25 L_4 ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 )
{
F_11 ( V_25 L_5 , V_3 -> V_26 ) ;
if ( V_3 -> V_16 )
F_15 ( V_3 -> V_16 , V_27 ) ;
return 0 ;
}
