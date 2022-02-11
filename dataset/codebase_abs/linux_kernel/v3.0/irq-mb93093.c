static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 () ;
V_3 |= 1 << ( V_2 -> V_4 - V_5 ) ;
F_3 ( V_3 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( 1 << ( V_2 -> V_4 - V_5 ) ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 () ;
V_3 |= 1 << ( V_2 -> V_4 - V_5 ) ;
F_3 ( V_3 ) ;
F_5 ( 1 << ( V_2 -> V_4 - V_5 ) ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 () ;
V_3 &= ~ ( 1 << ( V_2 -> V_4 - V_5 ) ) ;
F_3 ( V_3 ) ;
}
static T_2 F_8 ( int V_4 , void * V_6 )
{
T_1 V_3 , V_7 = ( unsigned long ) V_6 ;
V_3 = F_2 () ;
V_7 = V_7 & ~ V_3 & F_9 () ;
while ( V_7 ) {
int V_4 ;
asm("scan %1,gr0,%0" : "=r"(irq) : "r"(mask));
V_4 = 31 - V_4 ;
V_7 &= ~ ( 1 << V_4 ) ;
F_10 ( V_5 + V_4 ) ;
}
return V_8 ;
}
void T_3 F_11 ( void )
{
int V_4 ;
F_3 ( 0x0700 ) ;
F_5 ( 0x0000 ) ;
for ( V_4 = V_5 + 8 ; V_4 <= V_5 + 10 ; V_4 ++ )
F_12 ( V_4 , & V_9 , V_10 ) ;
F_13 ( V_11 , & V_12 [ 0 ] ) ;
}
