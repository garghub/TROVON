static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
char ( * V_7 ) [ V_8 ] ;
unsigned int V_9 ;
T_1 V_10 ;
int V_11 ;
V_11 = F_2 ( & V_2 -> V_12 , L_1 , & V_10 ) ;
if ( V_11 < 0 ) {
F_3 ( & V_2 -> V_12 , L_2 ) ;
return V_11 ;
}
if ( ! V_10 || V_10 > V_13 ) {
F_3 ( & V_2 -> V_12 , L_3 ) ;
return - V_14 ;
}
V_4 = F_4 ( & V_2 -> V_12 , V_10 ,
sizeof( struct V_3 ) , V_15 ) ;
V_6 = F_4 ( & V_2 -> V_12 , V_10 ,
sizeof( struct V_5 ) , V_15 ) ;
V_7 = F_4 ( & V_2 -> V_12 , V_10 , V_8 , V_15 ) ;
if ( ! V_4 || ! V_6 || ! V_7 )
return - V_16 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
snprintf ( V_7 [ V_9 ] , V_8 , L_4 , V_9 ) ;
V_4 [ V_9 ] . V_17 = V_9 ;
V_4 [ V_9 ] . V_18 = V_7 [ V_9 ] ;
V_6 [ V_9 ] . V_19 = 1 ;
V_6 [ V_9 ] . V_18 = V_7 [ V_9 ] ;
V_6 [ V_9 ] . V_4 = & V_4 [ V_9 ] . V_17 ;
V_6 [ V_9 ] . V_20 = 0x10000 * V_9 ;
V_6 [ V_9 ] . V_21 = 0x04 + 0x10000 * V_9 ;
V_6 [ V_9 ] . V_22 = 0x08 + 0x10000 * V_9 ;
V_6 [ V_9 ] . V_23 = 0x0c + 0x10000 * V_9 ;
V_6 [ V_9 ] . V_24 = 0x08 + 0x10000 * V_9 ;
V_6 [ V_9 ] . V_25 = 2 ;
V_6 [ V_9 ] . V_26 = 0 ;
V_6 [ V_9 ] . V_27 = 6 ;
V_6 [ V_9 ] . V_28 = 9 ;
V_6 [ V_9 ] . V_29 = 0 ;
V_6 [ V_9 ] . V_30 = 1 ;
V_6 [ V_9 ] . V_31 = 0 ;
V_6 [ V_9 ] . V_32 = 0 ;
V_6 [ V_9 ] . V_33 = 5 ;
V_6 [ V_9 ] . V_34 = 1 ;
V_6 [ V_9 ] . V_35 = 4 ;
V_6 [ V_9 ] . V_36 = 1 ;
V_6 [ V_9 ] . V_37 = 2 ;
V_6 [ V_9 ] . V_38 = 2 ;
}
V_39 . V_4 = V_4 ;
V_39 . V_6 = V_6 ;
V_39 . V_19 = V_10 ;
V_39 . V_40 = V_10 ;
V_39 . V_41 = V_10 ;
return F_5 ( V_2 , & V_39 ) ;
}
static int T_2 F_6 ( void )
{
return F_7 ( & V_42 ) ;
}
static void T_3 F_8 ( void )
{
F_9 ( & V_42 ) ;
}
