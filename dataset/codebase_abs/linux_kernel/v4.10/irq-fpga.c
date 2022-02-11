static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 - V_4 ) = 0x0001 ;
F_3 () ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 -> V_3 - V_4 ) = 0x0001 ;
F_3 () ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 - V_4 ) = 0x0001 ;
F_3 () ;
F_5 ( V_2 -> V_3 - V_4 ) = 0x0001 ;
F_3 () ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 - V_4 ) = 0x0000 ;
F_3 () ;
}
static T_1 F_8 ( int V_3 , void * V_5 )
{
if ( ( V_6 & 0x0001 ) != 0x0001 )
F_9 ( V_7 ) ;
if ( ( V_8 & 0x0001 ) != 0x0001 )
F_9 ( V_9 ) ;
if ( ( V_10 & 0x0001 ) != 0x0001 )
F_9 ( V_11 ) ;
if ( ( V_12 & 0x0001 ) != 0x0001 )
F_9 ( V_13 ) ;
if ( ( V_14 & 0x0001 ) != 0x0001 )
F_9 ( V_15 ) ;
return V_16 ;
}
void T_2 F_10 ( void )
{
int V_3 ;
V_17 = 0x0001 ;
F_3 () ;
V_18 = 0x0001 ;
F_3 () ;
V_19 = 0x0001 ;
F_3 () ;
V_20 = 0x0001 ;
F_3 () ;
V_21 = 0x0001 ;
F_3 () ;
for ( V_3 = V_4 ; V_3 < V_22 ; V_3 ++ )
F_11 ( V_3 , & V_23 ,
V_24 ) ;
F_12 ( V_25 , & V_26 [ 0 ] ) ;
}
