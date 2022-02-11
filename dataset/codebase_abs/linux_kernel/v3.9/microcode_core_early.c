static int T_1 F_1 ( void )
{
T_2 V_1 = 0x00000000 ;
T_2 V_2 , V_3 = 0 , V_4 ;
F_2 ( & V_1 , & V_2 , & V_3 , & V_4 ) ;
if ( F_3 ( V_5 , V_6 , V_7 , V_2 , V_3 , V_4 ) )
return V_8 ;
if ( F_3 ( V_9 , V_10 , V_11 , V_2 , V_3 , V_4 ) )
return V_12 ;
return V_13 ;
}
static int T_1 F_4 ( void )
{
T_2 V_1 = 0x00000001 ;
T_2 V_2 , V_3 = 0 , V_4 ;
int V_14 ;
F_2 ( & V_1 , & V_2 , & V_3 , & V_4 ) ;
V_14 = ( V_1 >> 8 ) & 0xf ;
if ( V_14 == 15 )
V_14 += ( V_1 >> 20 ) & 0xff ;
return V_14 ;
}
void T_3 F_5 ( void )
{
int V_15 , V_14 ;
if ( ! F_6 () )
return;
V_15 = F_1 () ;
V_14 = F_4 () ;
if ( V_15 == V_8 && V_14 >= 6 )
F_7 () ;
}
void T_1 F_8 ( void )
{
int V_15 , V_14 ;
if ( ! F_6 () )
return;
V_15 = F_1 () ;
V_14 = F_4 () ;
if ( V_15 == V_8 && V_14 >= 6 )
F_9 () ;
}
