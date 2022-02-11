static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_7 ;
F_2 ( V_8 L_1 , V_2 -> V_9 ) ;
V_2 -> V_10 = V_11 -> V_12 ;
V_5 = V_4 -> V_13 [ 0 ] ;
if ( ! F_3 ( V_5 , V_14 , V_2 -> V_10 ) ) {
F_2 ( L_2 ) ;
return - V_15 ;
}
V_2 -> V_5 = V_5 ;
if ( F_4 ( V_2 , sizeof( struct V_16 ) ) < 0 )
return - V_17 ;
if ( F_5 ( V_2 , 2 ) < 0 )
return - V_17 ;
V_7 = V_2 -> V_18 + 0 ;
V_7 -> type = V_19 ;
V_7 -> V_20 = V_21 ;
V_7 -> V_22 = 16 ;
V_7 -> V_23 = 1 ;
V_7 -> V_24 = & V_25 ;
V_7 -> V_26 = V_27 ;
V_7 = V_2 -> V_18 + 1 ;
V_7 -> type = V_19 ;
V_7 -> V_20 = V_28 ;
V_7 -> V_22 = 16 ;
V_7 -> V_23 = 1 ;
V_7 -> V_24 = & V_25 ;
V_7 -> V_26 = V_29 ;
F_2 ( L_3 ) ;
return 1 ;
}
static int F_6 ( struct V_1 * V_2 )
{
F_2 ( V_8 L_4 , V_2 -> V_9 ) ;
if ( V_2 -> V_5 )
F_7 ( V_2 -> V_5 , V_14 ) ;
return 0 ;
}
static int V_27 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_30 * V_31 ,
unsigned int * V_32 )
{
if ( V_31 -> V_33 != 2 )
return - V_34 ;
if ( V_32 [ 0 ] ) {
V_7 -> V_35 &= ~ V_32 [ 0 ] ;
V_7 -> V_35 |= V_32 [ 0 ] & V_32 [ 1 ] ;
F_8 ( V_7 -> V_35 & 0xff , V_2 -> V_5 + V_36 ) ;
F_8 ( ( V_7 -> V_35 >> 8 ) & 0xff ,
V_2 -> V_5 + V_37 ) ;
}
V_32 [ 1 ] = V_7 -> V_35 ;
return 2 ;
}
static int V_29 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_30 * V_31 ,
unsigned int * V_32 )
{
if ( V_31 -> V_33 != 2 )
return - V_34 ;
V_32 [ 1 ] = 0 ;
V_32 [ 1 ] |= F_9 ( V_2 -> V_5 + V_38 ) ;
V_32 [ 1 ] |= F_9 ( V_2 -> V_5 + V_39 ) << 8 ;
return 2 ;
}
static int T_1 F_10 ( void )
{
return F_11 ( & V_40 ) ;
}
static void T_2 F_12 ( void )
{
F_13 ( & V_40 ) ;
}
