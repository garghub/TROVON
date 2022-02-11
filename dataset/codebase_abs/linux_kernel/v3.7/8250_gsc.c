static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
unsigned long V_5 ;
int V_6 ;
if ( ! V_2 -> V_7 ) {
if ( F_2 ( V_2 ) -> V_8 . V_9 != V_10 )
F_3 ( V_11
L_1
L_2 ,
( unsigned long long ) V_2 -> V_12 . V_13 ) ;
return - V_14 ;
}
V_5 = V_2 -> V_12 . V_13 ;
if ( V_2 -> V_8 . V_15 != 0x8d )
V_5 += 0x800 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_16 . V_17 = V_18 ;
V_4 . V_16 . V_19 = 7272727 ;
V_4 . V_16 . V_20 = V_5 ;
V_4 . V_16 . V_21 = F_4 ( V_5 , 16 ) ;
V_4 . V_16 . V_7 = V_2 -> V_7 ;
V_4 . V_16 . V_22 = V_23 ;
V_4 . V_16 . V_2 = & V_2 -> V_2 ;
V_6 = F_5 ( & V_4 ) ;
if ( V_6 < 0 ) {
F_3 ( V_24
L_3 , V_6 ) ;
F_6 ( V_4 . V_16 . V_21 ) ;
return V_6 ;
}
return 0 ;
}
static int T_1 F_7 ( void )
{
F_8 ( & V_25 ) ;
F_8 ( & V_26 ) ;
return 0 ;
}
