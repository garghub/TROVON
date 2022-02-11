static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
unsigned long V_5 ;
int V_6 ;
#ifdef F_2
if ( ! V_2 -> V_7 && ( V_2 -> V_8 . V_9 == 0xad ) )
V_2 -> V_7 = F_3 ( V_2 ) ;
#endif
if ( ! V_2 -> V_7 ) {
if ( F_4 ( V_2 ) -> V_8 . V_10 != V_11 )
F_5 ( & V_2 -> V_2 ,
L_1
L_2 ,
( unsigned long long ) V_2 -> V_12 . V_13 ) ;
return - V_14 ;
}
V_5 = V_2 -> V_12 . V_13 ;
if ( V_2 -> V_8 . V_9 != 0x8d )
V_5 += 0x800 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_15 . V_16 = V_17 ;
V_4 . V_15 . V_18 = ( V_2 -> V_8 . V_9 != 0xad ) ?
7272727 : 1843200 ;
V_4 . V_15 . V_19 = V_5 ;
V_4 . V_15 . V_20 = F_6 ( V_5 , 16 ) ;
if ( ! V_4 . V_15 . V_20 ) {
F_7 ( & V_2 -> V_2 , L_3 ) ;
return - V_21 ;
}
V_4 . V_15 . V_7 = V_2 -> V_7 ;
V_4 . V_15 . V_22 = V_23 ;
V_4 . V_15 . V_2 = & V_2 -> V_2 ;
V_6 = F_8 ( & V_4 ) ;
if ( V_6 < 0 ) {
F_7 ( & V_2 -> V_2 ,
L_4 ,
V_6 ) ;
F_9 ( V_4 . V_15 . V_20 ) ;
return V_6 ;
}
return 0 ;
}
static int T_1 F_10 ( void )
{
F_11 ( & V_24 ) ;
F_11 ( & V_25 ) ;
return 0 ;
}
