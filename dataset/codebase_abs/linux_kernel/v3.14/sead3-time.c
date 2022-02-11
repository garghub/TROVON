static void F_1 ( void )
{
F_2 ( V_1 ) ;
}
static void F_3 ( void )
{
F_2 ( V_2 ) ;
}
static unsigned int T_1 F_4 ( void )
{
unsigned int V_3 = F_5 () & ( V_4 | V_5 ) ;
unsigned int V_6 = 0 ;
unsigned int V_7 ;
unsigned int V_8 ;
unsigned long V_9 ;
F_6 ( V_9 ) ;
V_8 = F_7 ( V_10 ) & 0x2 ;
while ( ( F_7 ( V_10 ) & 0x2 ) == V_8 )
;
V_8 = V_8 ^ 0x2 ;
F_8 ( 0 ) ;
while ( V_6 < 100 ) {
while ( ( F_7 ( V_10 ) & 0x2 ) == V_8 )
;
V_8 = V_8 ^ 0x2 ;
V_6 ++ ;
}
V_7 = F_9 () ;
F_10 ( V_9 ) ;
V_11 = V_7 ;
if ( ( V_3 != ( V_12 | V_13 ) ) &&
( V_3 != ( V_12 | V_14 ) ) )
V_7 *= 2 ;
V_7 += 5000 ;
V_7 -= V_7 % 10000 ;
return V_7 ;
}
void F_11 ( struct V_15 * V_16 )
{
V_16 -> V_17 = 0 ;
V_16 -> V_18 = 0 ;
}
static void T_1 F_12 ( void )
{
if ( V_19 >= 0 ) {
if ( V_20 )
F_13 ( V_19 , F_3 ) ;
V_2 = V_21 + V_19 ;
}
}
unsigned int F_14 ( void )
{
if ( V_20 )
F_13 ( V_22 , F_1 ) ;
V_1 = V_21 + V_22 ;
return V_1 ;
}
void T_1 F_15 ( void )
{
unsigned int V_23 ;
V_23 = F_4 () ;
F_16 ( L_1 , ( V_23 / 1000000 ) ,
( V_23 % 1000000 ) * 100 / 1000000 ) ;
F_17 () ;
F_12 () ;
}
