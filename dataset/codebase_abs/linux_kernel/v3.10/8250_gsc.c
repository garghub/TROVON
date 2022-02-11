static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
unsigned long V_5 ;
int V_6 ;
#ifdef F_2
extern int V_7 ( int V_8 ) ;
if ( ! V_2 -> V_9 && ( V_2 -> V_10 . V_11 == 0xad ) )
V_2 -> V_9 = V_7 ( V_2 -> V_12 - 1 ) ;
#endif
if ( ! V_2 -> V_9 ) {
if ( F_3 ( V_2 ) -> V_10 . V_13 != V_14 )
F_4 ( V_15
L_1
L_2 ,
( unsigned long long ) V_2 -> V_16 . V_17 ) ;
return - V_18 ;
}
V_5 = V_2 -> V_16 . V_17 ;
if ( V_2 -> V_10 . V_11 != 0x8d )
V_5 += 0x800 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_19 . V_20 = V_21 ;
V_4 . V_19 . V_22 = ( V_2 -> V_10 . V_11 != 0xad ) ?
7272727 : 1843200 ;
V_4 . V_19 . V_23 = V_5 ;
V_4 . V_19 . V_24 = F_5 ( V_5 , 16 ) ;
V_4 . V_19 . V_9 = V_2 -> V_9 ;
V_4 . V_19 . V_25 = V_26 ;
V_4 . V_19 . V_2 = & V_2 -> V_2 ;
V_6 = F_6 ( & V_4 ) ;
if ( V_6 < 0 ) {
F_4 ( V_27
L_3 , V_6 ) ;
F_7 ( V_4 . V_19 . V_24 ) ;
return V_6 ;
}
return 0 ;
}
static int T_1 F_8 ( void )
{
F_9 ( & V_28 ) ;
F_9 ( & V_29 ) ;
return 0 ;
}
