static int T_1 F_1 ( T_2 V_1 )
{
int V_2 = 0 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
V_2 ^= ( V_1 & 1 ) ;
V_1 >>= 1 ;
}
return V_2 ;
}
static void T_1 F_2 ( T_2 V_1 )
{
unsigned long V_4 ;
if ( V_5 != - 1 ) {
V_1 &= ~ V_6 ;
if ( ! F_1 ( V_1 ) )
V_1 |= V_6 ;
F_3 ( V_7 L_1 ,
V_5 , V_1 ) ;
F_4 ( & V_8 , V_4 ) ;
F_5 ( V_1 , V_5 ) ;
F_6 ( & V_8 , V_4 ) ;
}
}
static T_2 T_1 F_7 ( void )
{
unsigned long V_4 ;
T_2 V_1 ;
if ( V_5 == - 1 )
return 0 ;
F_4 ( & V_8 , V_4 ) ;
V_1 = F_8 ( V_5 ) ;
F_6 ( & V_8 , V_4 ) ;
return V_1 ;
}
static int T_1 F_9 ( T_2 V_1 )
{
if ( V_1 & V_9 )
return 0 ;
if ( ! F_1 ( V_1 ) )
return 0 ;
return 1 ;
}
static int T_1 F_10 ( void )
{
T_2 V_1 ;
if ( V_5 == - 1 )
return 0 ;
V_1 = F_7 () ;
if ( ! F_9 ( V_1 ) ) {
F_3 ( V_10 L_2
L_3 , V_1 ) ;
}
V_1 &= ~ V_9 ;
V_1 &= ~ V_11 ;
V_1 &= ~ V_12 ;
#if F_11 ( V_13 )
V_1 |= V_14 ;
#endif
F_2 ( V_1 ) ;
return 0 ;
}
