static unsigned int T_1 F_1 ( void )
{
unsigned int V_1 = F_2 () & ( V_2 | V_3 ) ;
unsigned int V_4 = 0 ;
unsigned int V_5 ;
unsigned int V_6 ;
unsigned long V_7 ;
F_3 ( V_7 ) ;
V_6 = F_4 ( V_8 ) & 0x2 ;
while ( ( F_4 ( V_8 ) & 0x2 ) == V_6 )
;
V_6 = V_6 ^ 0x2 ;
F_5 ( 0 ) ;
while ( V_4 < 100 ) {
while ( ( F_4 ( V_8 ) & 0x2 ) == V_6 )
;
V_6 = V_6 ^ 0x2 ;
V_4 ++ ;
}
V_5 = F_6 () ;
F_7 ( V_7 ) ;
V_9 = V_5 ;
if ( ( V_1 != ( V_10 | V_11 ) ) &&
( V_1 != ( V_10 | V_12 ) ) )
V_5 *= 2 ;
V_5 += 5000 ;
V_5 -= V_5 % 10000 ;
return V_5 ;
}
void F_8 ( struct V_13 * V_14 )
{
V_14 -> V_15 = 0 ;
V_14 -> V_16 = 0 ;
}
int F_9 ( void )
{
if ( V_17 )
return F_10 () ;
if ( V_18 >= 0 )
return V_19 + V_18 ;
return - 1 ;
}
unsigned int F_11 ( void )
{
if ( V_17 )
return F_12 () ;
return V_19 + V_20 ;
}
void T_1 F_13 ( void )
{
unsigned int V_21 ;
V_21 = F_1 () ;
F_14 ( L_1 , ( V_21 / 1000000 ) ,
( V_21 % 1000000 ) * 100 / 1000000 ) ;
F_15 () ;
}
