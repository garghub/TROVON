static unsigned int F_1 ( unsigned int V_1 )
{
T_1 V_2 ;
F_2 () ;
F_3 ( 0x80 , V_3 ) ;
V_2 = F_4 ( V_4 ) ;
F_5 () ;
if ( ( V_2 & 0xE0 ) == 0xE0 )
return 0 ;
if ( ( V_2 & 0xE0 ) == 0xC0 ) {
if ( ( V_2 & 0x01 ) == 0 )
return 66000 ;
else
return 99000 ;
}
if ( ( V_2 & 0xE0 ) == 0xA0 )
return 33000 ;
return ( 1 << ( ( V_2 & 0xE0 ) >> 5 ) ) * 1000 ;
}
static void F_6 ( unsigned int V_5 )
{
struct V_6 V_7 ;
V_7 . V_8 = F_1 ( 0 ) ;
V_7 . V_9 = V_10 [ V_5 ] . clock ;
V_7 . V_1 = 0 ;
F_7 ( & V_7 , V_11 ) ;
F_8 ( V_12 L_1 ,
V_10 [ V_5 ] . clock ) ;
F_2 () ;
F_3 ( 0x40 , V_3 ) ;
F_3 ( 0x00 , V_4 ) ;
F_5 () ;
F_9 ( 1000 ) ;
F_2 () ;
F_3 ( 0x80 , V_3 ) ;
F_3 ( V_10 [ V_5 ] . V_13 , V_4 ) ;
F_3 ( 0x40 , V_3 ) ;
F_3 ( V_10 [ V_5 ] . V_14 , V_4 ) ;
F_9 ( 10000 ) ;
F_5 () ;
F_7 ( & V_7 , V_15 ) ;
}
static int F_10 ( struct V_16 * V_17 )
{
return F_11 ( V_17 , & V_18 [ 0 ] ) ;
}
static int F_12 ( struct V_16 * V_17 ,
unsigned int V_19 ,
unsigned int V_20 )
{
unsigned int V_21 = 0 ;
if ( F_13 ( V_17 , & V_18 [ 0 ] ,
V_19 , V_20 , & V_21 ) )
return - V_22 ;
F_6 ( V_21 ) ;
return 0 ;
}
static int F_14 ( struct V_16 * V_17 )
{
struct V_23 * V_24 = & F_15 ( 0 ) ;
unsigned int V_25 ;
int V_26 ;
if ( ( V_24 -> V_27 != V_28 ) ||
( V_24 -> V_29 != 4 ) || ( V_24 -> V_30 != 10 ) )
return - V_31 ;
if ( ! V_32 )
V_32 = F_1 ( 0 ) ;
for ( V_25 = 0 ; ( V_18 [ V_25 ] . V_33 != V_34 ) ; V_25 ++ ) {
if ( V_18 [ V_25 ] . V_33 > V_32 )
V_18 [ V_25 ] . V_33 = V_35 ;
}
V_17 -> V_36 . V_37 = V_38 ;
V_17 -> V_39 = F_1 ( 0 ) ;
V_26 = F_16 ( V_17 , V_18 ) ;
if ( V_26 )
return V_26 ;
F_17 ( V_18 , V_17 -> V_1 ) ;
return 0 ;
}
static int F_18 ( struct V_16 * V_17 )
{
F_19 ( V_17 -> V_1 ) ;
return 0 ;
}
static int T_2 F_20 ( char * V_40 )
{
V_32 = F_21 ( V_40 , & V_40 , 0 ) ;
F_8 ( V_41 L_2 ) ;
return 1 ;
}
static int T_2 F_22 ( void )
{
if ( ! F_23 ( V_42 ) )
return - V_31 ;
return F_24 ( & V_43 ) ;
}
static void T_3 F_25 ( void )
{
F_26 ( & V_43 ) ;
}
