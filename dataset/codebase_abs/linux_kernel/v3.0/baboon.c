void T_1 F_1 ( void )
{
if ( V_1 -> V_2 != V_3 ) {
V_4 = NULL ;
V_5 = 0 ;
return;
}
V_4 = (struct V_4 * ) V_6 ;
V_5 = 1 ;
F_2 ( L_1 , V_4 ) ;
}
static T_2 F_3 ( int V_7 , void * V_8 )
{
int V_9 , V_10 ;
unsigned char V_11 ;
#ifdef F_4
F_2 ( L_2 ,
( V_12 ) V_4 -> V_13 , ( V_12 ) V_4 -> V_14 ,
( V_12 ) V_4 -> V_15 ) ;
#endif
if ( ! ( V_11 = V_4 -> V_14 & 0x07 ) )
return V_16 ;
V_10 = V_17 ;
V_9 = 1 ;
do {
if ( V_11 & V_9 ) {
V_4 -> V_14 &= ~ V_9 ;
F_5 ( V_10 ) ;
}
V_9 <<= 1 ;
V_10 ++ ;
} while( V_11 >= V_9 );
#if 0
if (baboon->mb_ifr & 0x02) macide_ack_intr(NULL);
baboon->mb_ifr &= ~events;
#endif
return V_18 ;
}
void T_1 F_6 ( void )
{
V_19 = 0 ;
if ( F_7 ( V_20 , F_3 , 0 , L_3 , ( void * ) V_4 ) )
F_8 ( L_4 ) ;
}
void F_9 ( int V_7 )
{
int V_21 = F_10 ( V_7 ) ;
#ifdef F_11
F_2 ( L_5 , V_7 ) ;
#endif
V_19 &= ~ ( 1 << V_21 ) ;
if ( ! V_19 )
F_12 ( V_20 ) ;
}
void F_13 ( int V_7 )
{
int V_21 = F_10 ( V_7 ) ;
#ifdef F_11
F_2 ( L_6 , V_7 ) ;
#endif
V_19 |= 1 << V_21 ;
if ( V_19 )
F_14 ( V_20 ) ;
}
void F_15 ( int V_7 )
{
int V_21 = F_10 ( V_7 ) ;
V_4 -> V_14 &= ~ ( 1 << V_21 ) ;
}
int F_16 ( int V_7 )
{
int V_21 = F_10 ( V_7 ) ;
return V_4 -> V_14 & ( 1 << V_21 ) ;
}
