static struct V_1 * F_1 ( void )
{
struct V_2 * V_3 = F_2 ( sizeof( * V_3 ) , V_4 ) ;
return V_3 ? & V_3 -> V_5 : NULL ;
}
static int F_3 ( struct V_1 * V_5 , T_1 V_6 )
{
unsigned long V_7 ;
unsigned long V_8 ;
V_8 = V_6 / 160 ;
V_7 = ( V_8 * V_8 + 2500 ) / 5000 ;
V_7 = ( V_7 * V_8 + 5000 ) / 10000 ;
V_7 -= ( 10 * V_8 * V_8 + 10433 ) / 20866 ;
V_7 += 4 * V_8 - 11505 ;
F_4 ( ( V_7 >> 8 ) & 0x01 , V_5 -> V_9 + 4 ) ;
F_4 ( V_7 >> 9 , V_5 -> V_9 + 6 ) ;
F_4 ( V_7 & 0xff , V_5 -> V_9 + 8 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_5 , bool V_10 , int V_11 )
{
struct V_2 * V_3 = F_6 ( V_5 , struct V_2 , V_5 ) ;
if ( V_10 )
V_11 = 0 ;
V_11 >>= 14 ;
V_11 &= 3 ;
F_4 ( V_11 / 2 , V_5 -> V_9 ) ;
F_4 ( V_11 % 2 , V_5 -> V_9 + 2 ) ;
if ( V_11 == 0 && ! V_3 -> V_12 ) {
V_3 -> V_12 = true ;
return F_3 ( V_5 , V_13 << 4 ) ;
}
if ( V_11 && V_3 -> V_12 ) {
V_3 -> V_12 = false ;
return F_3 ( V_5 , V_5 -> V_6 ) ;
}
return 0 ;
}
static int T_2 F_7 ( void )
{
if ( V_13 < 87000 || V_13 > 108000 ) {
F_8 ( V_14 L_1 ,
V_15 . V_16 . V_16 . V_17 ) ;
F_8 ( V_14 L_2 ,
V_15 . V_16 . V_16 . V_17 ) ;
return - V_18 ;
}
return F_9 ( & V_15 . V_16 , V_19 ) ;
}
static void T_3 F_10 ( void )
{
F_11 ( & V_15 . V_16 ) ;
}
