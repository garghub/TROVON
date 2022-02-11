static T_1 F_1 ( int V_1 )
{
T_1 V_2 ;
V_2 = * ( ( volatile T_1 * ) ( V_3 + V_1 ) ) ;
return V_2 ;
}
static void F_2 ( int V_1 , T_1 V_2 )
{
T_1 V_4 ;
* ( ( volatile T_1 * ) ( V_3 + V_1 ) ) = V_2 ;
V_4 = * ( ( volatile T_1 * ) V_3 ) ;
__asm__ __volatile__("mov %0, %0" : "+r" (dummy));
}
void F_3 ( void )
{
F_2 ( V_5 , 0x02 ) ;
F_4 ( 1 ) ;
F_2 ( V_6 , 0xff ) ;
F_2 ( V_7 , 0x07 ) ;
F_2 ( V_8 , 0x11 ) ;
F_2 ( V_9 , 0x11 ) ;
F_2 ( V_10 , 0x11 ) ;
F_2 ( V_11 , 0x11 ) ;
F_2 ( V_12 , 0 ) ;
}
void F_5 ( int V_13 )
{
T_1 V_14 ;
V_14 = F_1 ( V_15 ) ;
V_14 |= 1 << V_13 ;
F_2 ( V_15 , V_14 ) ;
}
void F_6 ( int V_13 )
{
T_1 V_14 ;
V_14 = F_1 ( V_15 ) ;
V_14 &= ~ ( 1 << V_13 ) ;
F_2 ( V_15 , V_14 ) ;
}
void F_7 ( int V_13 )
{
T_1 V_14 ;
V_14 = F_1 ( V_15 ) ;
V_14 |= 1 << ( V_13 + 4 ) ;
F_2 ( V_15 , V_14 ) ;
}
void F_8 ( int V_13 )
{
T_1 V_14 ;
V_14 = F_1 ( V_15 ) ;
V_14 &= ~ ( 1 << ( V_13 + 4 ) ) ;
F_2 ( V_15 , V_14 ) ;
}
