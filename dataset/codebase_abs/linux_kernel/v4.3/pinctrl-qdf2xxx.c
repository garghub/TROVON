static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
unsigned int V_7 ;
T_1 V_8 ;
int V_9 ;
V_9 = F_2 ( & V_2 -> V_10 , L_1 , & V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( ! V_8 ) {
F_3 ( & V_2 -> V_10 , L_2 ) ;
return - V_11 ;
}
V_4 = F_4 ( & V_2 -> V_10 , V_8 ,
sizeof( struct V_3 ) , V_12 ) ;
V_6 = F_4 ( & V_2 -> V_10 , V_8 ,
sizeof( struct V_5 ) , V_12 ) ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
V_4 [ V_7 ] . V_13 = V_7 ;
V_6 [ V_7 ] . V_14 = 1 ,
V_6 [ V_7 ] . V_4 = & V_4 [ V_7 ] . V_13 ;
V_6 [ V_7 ] . V_15 = 0x10000 * V_7 ;
V_6 [ V_7 ] . V_16 = 0x04 + 0x10000 * V_7 ;
V_6 [ V_7 ] . V_17 = 0x08 + 0x10000 * V_7 ;
V_6 [ V_7 ] . V_18 = 0x0c + 0x10000 * V_7 ;
V_6 [ V_7 ] . V_19 = 0x08 + 0x10000 * V_7 ;
V_6 [ V_7 ] . V_20 = 2 ;
V_6 [ V_7 ] . V_21 = 0 ;
V_6 [ V_7 ] . V_22 = 6 ;
V_6 [ V_7 ] . V_23 = 9 ;
V_6 [ V_7 ] . V_24 = 0 ;
V_6 [ V_7 ] . V_25 = 1 ;
V_6 [ V_7 ] . V_26 = 0 ;
V_6 [ V_7 ] . V_27 = 0 ;
V_6 [ V_7 ] . V_28 = 5 ;
V_6 [ V_7 ] . V_29 = 1 ;
V_6 [ V_7 ] . V_30 = 4 ;
V_6 [ V_7 ] . V_31 = 1 ;
V_6 [ V_7 ] . V_32 = 2 ;
V_6 [ V_7 ] . V_33 = 2 ;
}
V_34 . V_4 = V_4 ;
V_34 . V_6 = V_6 ;
V_34 . V_14 = V_8 ;
V_34 . V_35 = V_8 ;
V_34 . V_36 = V_8 ;
return F_5 ( V_2 , & V_34 ) ;
}
static int T_2 F_6 ( void )
{
return F_7 ( & V_37 ) ;
}
static void T_3 F_8 ( void )
{
F_9 ( & V_37 ) ;
}
