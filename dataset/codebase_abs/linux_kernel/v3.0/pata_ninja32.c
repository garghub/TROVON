static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
static T_1 V_5 [ 5 ] = {
0xd6 , 0x85 , 0x44 , 0x33 , 0x13
} ;
F_2 ( V_5 [ V_4 -> V_6 - V_7 ] ,
V_2 -> V_8 . V_9 + 0x1f ) ;
V_2 -> V_10 = V_4 ;
}
static void F_3 ( struct V_1 * V_2 , unsigned int V_11 )
{
struct V_3 * V_4 = & V_2 -> V_12 . V_11 [ V_11 ] ;
if ( V_2 -> V_10 != V_4 ) {
F_2 ( 0xd6 , V_2 -> V_8 . V_9 + 0x1f ) ;
F_4 ( V_2 , V_11 ) ;
F_1 ( V_2 , V_4 ) ;
}
}
static void F_5 ( void T_2 * V_13 )
{
F_2 ( 0x05 , V_13 + 0x01 ) ;
F_2 ( 0xBE , V_13 + 0x02 ) ;
F_2 ( 0x01 , V_13 + 0x03 ) ;
F_2 ( 0x20 , V_13 + 0x04 ) ;
F_2 ( 0x8f , V_13 + 0x05 ) ;
F_2 ( 0xa4 , V_13 + 0x1c ) ;
F_2 ( 0x83 , V_13 + 0x1d ) ;
}
static int F_6 ( struct V_14 * V_15 , const struct V_16 * V_17 )
{
struct V_18 * V_19 ;
struct V_1 * V_2 ;
void T_2 * V_13 ;
int V_20 ;
V_19 = F_7 ( & V_15 -> V_15 , 1 ) ;
if ( ! V_19 )
return - V_21 ;
V_2 = V_19 -> V_22 [ 0 ] ;
V_20 = F_8 ( V_15 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_9 ( V_15 , 1 << 0 , V_23 ) ;
if ( V_20 == - V_24 )
F_10 ( V_15 ) ;
if ( V_20 )
return V_20 ;
V_19 -> V_25 = F_11 ( V_15 ) ;
V_20 = F_12 ( V_15 , V_26 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_13 ( V_15 , V_26 ) ;
if ( V_20 )
return V_20 ;
F_14 ( V_15 ) ;
V_13 = V_19 -> V_25 [ 0 ] ;
if ( ! V_13 )
return - V_21 ;
V_2 -> V_27 = & V_28 ;
V_2 -> V_29 = V_30 ;
V_2 -> V_31 |= V_32 ;
V_2 -> V_8 . V_33 = V_13 + 0x10 ;
V_2 -> V_8 . V_34 = V_13 + 0x1E ;
V_2 -> V_8 . V_35 = V_13 + 0x1E ;
V_2 -> V_8 . V_9 = V_13 ;
F_15 ( & V_2 -> V_8 ) ;
V_2 -> V_36 = V_37 | V_38 ;
F_5 ( V_13 ) ;
return F_16 ( V_19 , V_15 -> V_39 , V_40 ,
V_41 , & V_42 ) ;
}
static int F_17 ( struct V_14 * V_43 )
{
struct V_18 * V_19 = F_18 ( & V_43 -> V_15 ) ;
int V_20 ;
V_20 = F_19 ( V_43 ) ;
if ( V_20 )
return V_20 ;
F_5 ( V_19 -> V_25 [ 0 ] ) ;
F_20 ( V_19 ) ;
return 0 ;
}
static int T_3 F_21 ( void )
{
return F_22 ( & V_44 ) ;
}
static void T_4 F_23 ( void )
{
F_24 ( & V_44 ) ;
}
