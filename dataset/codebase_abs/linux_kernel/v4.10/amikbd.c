static void T_1 F_1 ( void )
{
unsigned short V_1 [ V_2 ] ;
int V_3 , V_4 ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
if ( ! V_6 [ V_3 ] )
continue;
memset ( V_1 , 0 , sizeof( V_1 ) ) ;
for ( V_4 = 0 ; V_4 < 0x78 ; V_4 ++ ) {
if ( ! V_7 [ V_4 ] )
continue;
V_1 [ V_4 ] = V_6 [ V_3 ] [ V_7 [ V_4 ] ] ;
}
for ( V_4 = 0 ; V_4 < V_2 ; V_4 ++ ) {
if ( ! V_1 [ V_4 ] )
V_1 [ V_4 ] = 0xf200 ;
}
memcpy ( V_6 [ V_3 ] , V_1 , sizeof( V_1 ) ) ;
}
}
static inline void F_1 ( void ) {}
static T_2 F_2 ( int V_8 , void * V_9 )
{
struct V_10 * V_11 = V_9 ;
unsigned char V_12 , V_13 ;
V_12 = ~ V_14 . V_15 ;
V_14 . V_16 |= 0x40 ;
F_3 ( 85 ) ;
V_14 . V_16 &= ~ 0x40 ;
V_13 = ! ( V_12 & 1 ) ;
V_12 >>= 1 ;
if ( V_12 < 0x78 ) {
if ( V_12 == 98 ) {
F_4 ( V_11 , V_12 , 1 ) ;
F_4 ( V_11 , V_12 , 0 ) ;
} else {
F_4 ( V_11 , V_12 , V_13 ) ;
}
F_5 ( V_11 ) ;
} else
F_6 ( V_17 [ V_12 - 0x78 ] ) ;
return V_18 ;
}
static int T_1 F_7 ( struct V_19 * V_20 )
{
struct V_10 * V_11 ;
int V_3 , V_21 ;
V_11 = F_8 () ;
if ( ! V_11 ) {
F_9 ( & V_20 -> V_11 , L_1 ) ;
return - V_22 ;
}
V_11 -> V_23 = V_20 -> V_23 ;
V_11 -> V_24 = L_2 ;
V_11 -> V_25 . V_26 = V_27 ;
V_11 -> V_25 . V_28 = 0x0001 ;
V_11 -> V_25 . V_29 = 0x0001 ;
V_11 -> V_25 . V_30 = 0x0100 ;
V_11 -> V_11 . V_31 = & V_20 -> V_11 ;
V_11 -> V_32 [ 0 ] = F_10 ( V_33 ) | F_10 ( V_34 ) ;
for ( V_3 = 0 ; V_3 < 0x78 ; V_3 ++ )
F_11 ( V_3 , V_11 -> V_35 ) ;
F_1 () ;
V_14 . V_16 &= ~ 0x41 ;
V_21 = F_12 ( V_36 , F_2 , 0 , L_3 ,
V_11 ) ;
if ( V_21 )
goto V_37;
V_21 = F_13 ( V_11 ) ;
if ( V_21 )
goto V_38;
F_14 ( V_20 , V_11 ) ;
return 0 ;
V_38: F_15 ( V_36 , V_11 ) ;
V_37: F_16 ( V_11 ) ;
return V_21 ;
}
static int T_3 F_17 ( struct V_19 * V_20 )
{
struct V_10 * V_11 = F_18 ( V_20 ) ;
F_15 ( V_36 , V_11 ) ;
F_19 ( V_11 ) ;
return 0 ;
}
