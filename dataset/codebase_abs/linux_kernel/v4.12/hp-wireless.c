static int F_1 ( void )
{
int V_1 ;
V_2 = F_2 () ;
if ( ! V_2 )
return - V_3 ;
V_2 -> V_4 = L_1 ;
V_2 -> V_5 = L_2 ;
V_2 -> V_6 . V_7 = V_8 ;
V_2 -> V_9 [ 0 ] = F_3 ( V_10 ) ;
F_4 ( V_11 , V_2 -> V_12 ) ;
V_1 = F_5 ( V_2 ) ;
if ( V_1 )
goto V_13;
return 0 ;
V_13:
F_6 ( V_2 ) ;
return V_1 ;
}
static void F_7 ( void )
{
F_8 ( V_2 ) ;
}
static void F_9 ( struct V_14 * V_15 , T_1 V_16 )
{
if ( V_16 != 0x80 ) {
F_10 ( L_3 , V_16 ) ;
return;
}
F_11 ( V_2 , V_11 , 1 ) ;
F_12 ( V_2 ) ;
F_11 ( V_2 , V_11 , 0 ) ;
F_12 ( V_2 ) ;
}
static int F_13 ( struct V_14 * V_17 )
{
int V_1 ;
V_1 = F_1 () ;
if ( V_1 )
F_14 ( L_4 ) ;
return V_1 ;
}
static int F_15 ( struct V_14 * V_17 )
{
F_7 () ;
return 0 ;
}
