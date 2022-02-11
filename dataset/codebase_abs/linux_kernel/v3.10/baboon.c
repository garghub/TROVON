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
static void F_3 ( unsigned int V_7 , struct V_8 * V_9 )
{
int V_10 , V_11 ;
unsigned char V_12 ;
#ifdef F_4
F_2 ( L_2 ,
( V_13 ) V_4 -> V_14 , ( V_13 ) V_4 -> V_15 ,
( V_13 ) V_4 -> V_16 ) ;
#endif
V_12 = V_4 -> V_15 & 0x07 ;
if ( ! V_12 )
return;
V_11 = V_17 ;
V_10 = 1 ;
do {
if ( V_12 & V_10 ) {
V_4 -> V_15 &= ~ V_10 ;
F_5 ( V_11 ) ;
}
V_10 <<= 1 ;
V_11 ++ ;
} while( V_12 >= V_10 );
#if 0
if (baboon->mb_ifr & 0x02) macide_ack_intr(NULL);
baboon->mb_ifr &= ~events;
#endif
}
void T_1 F_6 ( void )
{
F_7 ( V_18 , F_3 ) ;
}
void F_8 ( int V_7 )
{
#ifdef F_9
F_2 ( L_3 , V_7 ) ;
#endif
F_10 ( F_11 ( V_18 ) ) ;
}
void F_12 ( int V_7 )
{
#ifdef F_9
F_2 ( L_4 , V_7 ) ;
#endif
F_13 ( F_11 ( V_18 ) ) ;
}
