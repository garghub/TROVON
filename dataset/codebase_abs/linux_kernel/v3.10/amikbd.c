static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned char V_5 , V_6 ;
V_5 = ~ V_7 . V_8 ;
V_7 . V_9 |= 0x40 ;
F_2 ( 85 ) ;
V_7 . V_9 &= ~ 0x40 ;
V_6 = ! ( V_5 & 1 ) ;
V_5 >>= 1 ;
if ( V_5 < 0x78 ) {
if ( V_5 == 98 ) {
F_3 ( V_4 , V_5 , 1 ) ;
F_3 ( V_4 , V_5 , 0 ) ;
} else {
F_3 ( V_4 , V_5 , V_6 ) ;
}
F_4 ( V_4 ) ;
} else
F_5 ( V_10 [ V_5 - 0x78 ] ) ;
return V_11 ;
}
static int T_2 F_6 ( struct V_12 * V_13 )
{
struct V_3 * V_4 ;
int V_14 , V_15 , V_16 ;
V_4 = F_7 () ;
if ( ! V_4 ) {
F_8 ( & V_13 -> V_4 , L_1 ) ;
return - V_17 ;
}
V_4 -> V_18 = V_13 -> V_18 ;
V_4 -> V_19 = L_2 ;
V_4 -> V_20 . V_21 = V_22 ;
V_4 -> V_20 . V_23 = 0x0001 ;
V_4 -> V_20 . V_24 = 0x0001 ;
V_4 -> V_20 . V_25 = 0x0100 ;
V_4 -> V_4 . V_26 = & V_13 -> V_4 ;
V_4 -> V_27 [ 0 ] = F_9 ( V_28 ) | F_9 ( V_29 ) ;
for ( V_14 = 0 ; V_14 < 0x78 ; V_14 ++ )
F_10 ( V_14 , V_4 -> V_30 ) ;
for ( V_14 = 0 ; V_14 < V_31 ; V_14 ++ ) {
static T_3 V_32 [ V_33 ] V_34 ;
if ( ! V_35 [ V_14 ] )
continue;
memset ( V_32 , 0 , sizeof( V_32 ) ) ;
for ( V_15 = 0 ; V_15 < 0x78 ; V_15 ++ ) {
if ( ! V_36 [ V_15 ] )
continue;
V_32 [ V_15 ] = V_35 [ V_14 ] [ V_36 [ V_15 ] ] ;
}
for ( V_15 = 0 ; V_15 < V_33 ; V_15 ++ ) {
if ( ! V_32 [ V_15 ] )
V_32 [ V_15 ] = 0xf200 ;
}
memcpy ( V_35 [ V_14 ] , V_32 , sizeof( V_32 ) ) ;
}
V_7 . V_9 &= ~ 0x41 ;
V_16 = F_11 ( V_37 , F_1 , 0 , L_3 ,
V_4 ) ;
if ( V_16 )
goto V_38;
V_16 = F_12 ( V_4 ) ;
if ( V_16 )
goto V_39;
F_13 ( V_13 , V_4 ) ;
return 0 ;
V_39: F_14 ( V_37 , V_4 ) ;
V_38: F_15 ( V_4 ) ;
return V_16 ;
}
static int T_4 F_16 ( struct V_12 * V_13 )
{
struct V_3 * V_4 = F_17 ( V_13 ) ;
F_13 ( V_13 , NULL ) ;
F_14 ( V_37 , V_4 ) ;
F_18 ( V_4 ) ;
return 0 ;
}
