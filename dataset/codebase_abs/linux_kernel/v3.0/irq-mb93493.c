static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
volatile void * V_4 ;
if ( V_5 & ( 1 << ( V_2 -> V_6 - V_7 ) ) )
V_4 = F_2 ( 1 ) ;
else
V_4 = F_2 ( 0 ) ;
V_3 = F_3 ( V_4 ) ;
V_3 &= ~ ( 1 << ( V_2 -> V_6 - V_7 + 16 ) ) ;
F_4 ( V_3 , V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 V_3 ;
volatile void * V_4 ;
if ( V_5 & ( 1 << ( V_2 -> V_6 - V_7 ) ) )
V_4 = F_2 ( 1 ) ;
else
V_4 = F_2 ( 0 ) ;
V_3 = F_3 ( V_4 ) ;
V_3 |= 1 << ( V_2 -> V_6 - V_7 + 16 ) ;
F_4 ( V_3 , V_4 ) ;
}
static T_2 F_7 ( int V_6 , void * V_8 )
{
volatile void * V_4 = V_8 ;
T_1 V_3 ;
V_3 = F_3 ( V_4 ) ;
V_3 = V_3 & ( V_3 >> 16 ) & 0xffff ;
while ( V_3 ) {
int V_6 ;
asm("scan %1,gr0,%0" : "=r"(irq) : "r"(iqsr));
V_6 = 31 - V_6 ;
V_3 &= ~ ( 1 << V_6 ) ;
F_8 ( V_7 + V_6 ) ;
}
return V_9 ;
}
void T_3 F_9 ( void )
{
int V_6 ;
for ( V_6 = V_7 + 0 ; V_6 <= V_7 + 10 ; V_6 ++ )
F_10 ( V_6 , & V_10 ,
V_11 ) ;
F_11 ( V_12 , & V_13 [ 0 ] ) ;
F_11 ( V_14 , & V_13 [ 1 ] ) ;
}
