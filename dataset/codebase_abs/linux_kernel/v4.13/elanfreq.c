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
static int F_6 ( struct V_5 * V_6 ,
unsigned int V_7 )
{
F_2 () ;
F_3 ( 0x40 , V_3 ) ;
F_3 ( 0x00 , V_4 ) ;
F_5 () ;
F_7 ( 1000 ) ;
F_2 () ;
F_3 ( 0x80 , V_3 ) ;
F_3 ( V_8 [ V_7 ] . V_9 , V_4 ) ;
F_3 ( 0x40 , V_3 ) ;
F_3 ( V_8 [ V_7 ] . V_10 , V_4 ) ;
F_7 ( 10000 ) ;
F_5 () ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = & F_9 ( 0 ) ;
struct V_13 * V_14 ;
if ( ( V_12 -> V_15 != V_16 ) ||
( V_12 -> V_17 != 4 ) || ( V_12 -> V_18 != 10 ) )
return - V_19 ;
if ( ! V_20 )
V_20 = F_1 ( 0 ) ;
F_10 (pos, elanfreq_table)
if ( V_14 -> V_21 > V_20 )
V_14 -> V_21 = V_22 ;
V_6 -> V_23 . V_24 = V_25 ;
return F_11 ( V_6 , V_26 ) ;
}
static int T_2 F_12 ( char * V_27 )
{
V_20 = F_13 ( V_27 , & V_27 , 0 ) ;
F_14 ( L_1 ) ;
return 1 ;
}
static int T_2 F_15 ( void )
{
if ( ! F_16 ( V_28 ) )
return - V_19 ;
return F_17 ( & V_29 ) ;
}
static void T_3 F_18 ( void )
{
F_19 ( & V_29 ) ;
}
