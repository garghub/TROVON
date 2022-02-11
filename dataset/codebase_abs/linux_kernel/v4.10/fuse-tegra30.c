static T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( V_2 -> V_4 + V_5 + V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_6 ;
int V_7 ;
V_7 = F_4 ( V_2 -> V_8 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_9 , L_1 , V_7 ) ;
return 0 ;
}
V_6 = F_2 ( V_2 -> V_4 + V_5 + V_3 ) ;
F_6 ( V_2 -> V_8 ) ;
return V_6 ;
}
static void T_2 F_7 ( void )
{
T_1 V_10 [ 12 ] ;
V_10 [ 0 ] = V_11 . V_12 ;
V_10 [ 1 ] = F_8 () ;
V_10 [ 2 ] = F_9 () ;
V_10 [ 3 ] = V_11 . V_13 << 16 ;
V_10 [ 3 ] |= V_11 . V_14 ;
V_10 [ 4 ] = V_11 . V_15 << 16 ;
V_10 [ 4 ] |= V_11 . V_16 ;
V_10 [ 5 ] = F_10 ( V_17 ) ;
V_10 [ 6 ] = F_10 ( V_18 ) ;
V_10 [ 7 ] = F_10 ( V_19 ) ;
V_10 [ 8 ] = F_10 ( V_20 ) ;
V_10 [ 9 ] = F_10 ( V_21 ) ;
V_10 [ 10 ] = F_10 ( V_22 ) ;
V_10 [ 11 ] = F_10 ( V_23 ) ;
F_11 ( V_10 , sizeof( V_10 ) ) ;
}
static void T_2 F_12 ( struct V_1 * V_2 )
{
V_2 -> V_24 = F_1 ;
V_2 -> V_25 = F_3 ;
F_13 () ;
V_2 -> V_26 -> V_27 ( & V_11 ) ;
F_7 () ;
}
