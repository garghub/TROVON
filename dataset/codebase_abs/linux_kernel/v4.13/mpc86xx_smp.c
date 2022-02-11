static void T_1
F_1 ( int V_1 )
{
T_2 T_3 * V_2 ;
unsigned long V_3 ;
if ( V_1 < 0 || V_1 >= V_4 )
return;
V_2 = F_2 ( F_3 () + V_5 ,
V_6 ) ;
V_3 = F_4 ( V_2 + ( V_7 >> 2 ) ) ;
V_3 |= 1 << ( V_1 + 24 ) ;
F_5 ( V_2 + ( V_7 >> 2 ) , V_3 ) ;
F_6 ( V_2 ) ;
}
static int T_1
F_7 ( int V_1 )
{
unsigned int V_8 ;
unsigned long V_9 , V_10 ;
int V_11 = 0 ;
unsigned int * V_12 = ( unsigned int * ) ( V_13 + 0x100 ) ;
if ( V_1 < 0 || V_1 >= V_4 )
return - V_14 ;
F_8 ( L_1 , V_1 ) ;
F_9 ( V_10 ) ;
V_8 = * V_12 ;
V_9 = ( unsigned long ) V_15 ;
F_10 ( V_12 , V_9 , V_16 ) ;
F_1 ( V_1 ) ;
while ( ( V_17 != V_1 ) && ( V_11 ++ , V_11 < 1000 ) )
F_11 ( 1 ) ;
* V_12 = V_8 ;
F_12 ( ( unsigned long ) V_12 , ( unsigned long ) V_12 + 4 ) ;
F_13 ( V_10 ) ;
F_8 ( L_2 , V_1 , V_11 ) ;
return 0 ;
}
static void T_1
F_14 ( int V_18 )
{
F_15 () ;
}
void T_1
F_16 ( void )
{
V_19 = & V_20 ;
}
