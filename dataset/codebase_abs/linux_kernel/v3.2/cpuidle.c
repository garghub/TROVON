static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 V_7 , V_8 ;
int V_9 ;
T_1 V_10 ;
F_2 () ;
F_3 ( & V_7 ) ;
if ( V_5 == 0 )
F_4 () ;
else if ( V_5 == 1 ) {
asm("b 1f; .align 5; 1:");
asm("mcr p15, 0, r0, c7, c10, 4");
V_10 = F_5 () ;
F_4 () ;
F_6 ( V_10 ) ;
}
F_3 ( & V_8 ) ;
F_7 () ;
V_9 = ( V_8 . V_11 - V_7 . V_11 ) * V_12 +
( V_8 . V_13 - V_7 . V_13 ) ;
V_2 -> V_14 = V_9 ;
return V_5 ;
}
static int F_8 ( void )
{
struct V_1 * V_15 ;
struct V_3 * V_16 = & V_17 ;
V_15 = & F_9 ( V_18 , F_10 () ) ;
V_15 -> V_19 = V_20 ;
V_16 -> V_19 = V_20 ;
V_16 -> V_21 [ 0 ] . V_22 = F_1 ;
V_16 -> V_21 [ 0 ] . V_23 = 1 ;
V_16 -> V_21 [ 0 ] . V_24 = 10000 ;
V_16 -> V_21 [ 0 ] . V_25 = V_26 ;
strcpy ( V_16 -> V_21 [ 0 ] . V_27 , L_1 ) ;
strcpy ( V_16 -> V_21 [ 0 ] . V_28 , L_2 ) ;
V_16 -> V_21 [ 1 ] . V_22 = F_1 ;
V_16 -> V_21 [ 1 ] . V_23 = 10 ;
V_16 -> V_21 [ 1 ] . V_24 = 10000 ;
V_16 -> V_21 [ 1 ] . V_25 = V_26 ;
strcpy ( V_16 -> V_21 [ 1 ] . V_27 , L_3 ) ;
strcpy ( V_16 -> V_21 [ 1 ] . V_28 , L_4 ) ;
F_11 ( & V_17 ) ;
if ( F_12 ( V_15 ) ) {
F_13 ( V_29 L_5 ) ;
return - V_30 ;
}
return 0 ;
}
