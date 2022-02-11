static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned long V_7 ;
unsigned int V_8 ;
V_7 = V_4 -> V_9 [ 0 ] ;
F_2 ( V_10 L_1 , V_2 -> V_11 ,
V_12 -> V_13 , V_7 ) ;
V_2 -> V_14 = V_12 -> V_13 ;
if ( V_7 == 0 ) {
F_2 ( V_15 L_2 ) ;
return - V_16 ;
}
V_8 = V_12 -> V_8 ;
if ( ! F_3 ( V_7 , V_8 , L_3 ) ) {
F_2 ( V_15 L_4
L_5 , V_7 , V_7 + V_8 - 1 ) ;
return - V_17 ;
}
V_2 -> V_7 = V_7 ;
if ( F_4 ( V_2 , 1 ) < 0 )
return - V_18 ;
if ( F_5 ( V_2 , sizeof( unsigned int ) * V_12 -> V_19 ) < 0 )
return - V_18 ;
V_6 = V_2 -> V_20 + 0 ;
V_6 -> type = V_12 -> type ;
V_6 -> V_19 = V_12 -> V_19 ;
V_6 -> V_21 = ( 1 << V_12 -> V_22 ) - 1 ;
V_6 -> V_23 = V_12 -> V_24 ;
V_6 -> V_25 = V_12 -> V_26 ;
V_6 -> V_27 = V_12 -> V_28 ;
V_6 -> V_29 = V_12 -> V_30 ;
if ( V_6 -> type == V_31 || V_6 -> type == V_32 )
V_6 -> V_33 = V_34 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 )
F_7 ( V_2 -> V_7 , V_12 -> V_8 ) ;
F_2 ( V_10 L_6 , V_2 -> V_11 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_35 * V_36 , unsigned int * V_37 )
{
int V_38 ;
V_38 = F_9 ( V_36 -> V_39 ) ;
V_37 [ 0 ] = ( ( unsigned int * ) V_2 -> V_40 ) [ V_38 ] ;
return 1 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_5 * V_6 ,
struct V_35 * V_36 , unsigned int * V_37 )
{
int V_41 ;
int V_38 ;
int V_42 ;
V_38 = F_9 ( V_36 -> V_39 ) ;
( ( unsigned int * ) V_2 -> V_40 ) [ V_38 ] = V_37 [ 0 ] ;
V_42 = V_37 [ 0 ] ;
#ifdef F_11
if ( ( F_12 ( V_36 -> V_39 ) & 0x2 ) == 0 )
V_42 = ~ V_42 ;
#endif
V_41 = ( V_42 << 4 ) & 0xf0 ;
F_13 ( V_41 , V_2 -> V_7 + F_14 ( V_38 ) ) ;
V_41 = ( V_42 >> 4 ) & 0xff ;
F_13 ( V_41 , V_2 -> V_7 + F_15 ( V_38 ) ) ;
return 1 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_35 * V_36 , unsigned int * V_37 )
{
if ( V_36 -> V_43 != 2 )
return - V_16 ;
V_37 [ 1 ] = F_17 ( V_2 -> V_7 + 0 ) ;
V_37 [ 1 ] |= ( F_17 ( V_2 -> V_7 + 1 ) << 8 ) ;
V_37 [ 1 ] |= ( F_17 ( V_2 -> V_7 + 2 ) << 16 ) ;
V_37 [ 1 ] |= ( F_17 ( V_2 -> V_7 + 3 ) << 24 ) ;
return 2 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_35 * V_36 , unsigned int * V_37 )
{
if ( V_36 -> V_43 != 2 )
return - V_16 ;
if ( V_37 [ 0 ] ) {
V_6 -> V_44 &= ~ V_37 [ 0 ] ;
V_6 -> V_44 |= ( V_37 [ 0 ] & V_37 [ 1 ] ) ;
if ( ( V_37 [ 0 ] >> 0 ) & 0xff )
F_13 ( ( V_6 -> V_44 >> 0 ) & 0xff , V_2 -> V_7 + 0 ) ;
if ( ( V_37 [ 0 ] >> 8 ) & 0xff )
F_13 ( ( V_6 -> V_44 >> 8 ) & 0xff , V_2 -> V_7 + 1 ) ;
if ( ( V_37 [ 0 ] >> 16 ) & 0xff )
F_13 ( ( V_6 -> V_44 >> 16 ) & 0xff , V_2 -> V_7 + 2 ) ;
if ( ( V_37 [ 0 ] >> 24 ) & 0xff )
F_13 ( ( V_6 -> V_44 >> 24 ) & 0xff , V_2 -> V_7 + 3 ) ;
}
V_37 [ 1 ] = V_6 -> V_44 ;
return 2 ;
}
static int T_1 F_19 ( void )
{
return F_20 ( & V_45 ) ;
}
static void T_2 F_21 ( void )
{
F_22 ( & V_45 ) ;
}
