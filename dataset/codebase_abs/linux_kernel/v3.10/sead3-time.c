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
unsigned int V_3 = F_5 () & 0xffff00 ;
unsigned int V_4 = 0 ;
unsigned int V_5 ;
unsigned int V_6 ;
unsigned long V_7 ;
F_6 ( V_7 ) ;
V_6 = F_7 ( V_8 ) & 0x2 ;
while ( ( F_7 ( V_8 ) & 0x2 ) == V_6 )
;
V_6 = V_6 ^ 0x2 ;
F_8 ( 0 ) ;
while ( V_4 < 100 ) {
while ( ( F_7 ( V_8 ) & 0x2 ) == V_6 )
;
V_6 = V_6 ^ 0x2 ;
V_4 ++ ;
}
V_5 = F_9 () ;
F_10 ( V_7 ) ;
V_9 = V_5 ;
if ( ( V_3 != ( V_10 | V_11 ) ) &&
( V_3 != ( V_10 | V_12 ) ) )
V_5 *= 2 ;
V_5 += 5000 ;
V_5 -= V_5 % 10000 ;
return V_5 ;
}
void F_11 ( struct V_13 * V_14 )
{
V_14 -> V_15 = 0 ;
V_14 -> V_16 = 0 ;
}
static void T_1 F_12 ( void )
{
if ( V_17 >= 0 ) {
if ( V_18 )
F_13 ( V_17 , F_3 ) ;
V_2 = V_19 + V_17 ;
}
}
unsigned int T_2 F_14 ( void )
{
if ( V_18 )
F_13 ( V_20 , F_1 ) ;
V_1 = V_19 + V_20 ;
return V_1 ;
}
void T_1 F_15 ( void )
{
unsigned int V_21 ;
V_21 = F_4 () ;
F_16 ( L_1 , ( V_21 / 1000000 ) ,
( V_21 % 1000000 ) * 100 / 1000000 ) ;
V_22 = V_21 / 1000 ;
F_17 () ;
F_12 () ;
}
