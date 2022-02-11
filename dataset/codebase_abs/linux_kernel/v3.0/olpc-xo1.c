static void F_1 ( void )
{
F_2 ( V_1 L_1 ) ;
F_3 ( 0x40000000 , V_2 + V_3 ) ;
F_3 ( 0x40000000 , V_2 + V_4 ) ;
F_3 ( 0x40000000 , V_2 + V_5 ) ;
F_3 ( 0x40000000 , V_2 + V_6 ) ;
F_3 ( 0x0002ffff , V_2 + V_7 ) ;
F_3 ( 0xffffffff , V_8 + V_9 ) ;
F_3 ( 0x00002000 , V_8 + V_10 ) ;
}
static int T_1 F_4 ( struct V_11 * V_12 )
{
struct V_13 * V_14 ;
int V_15 ;
if ( ! F_5 () )
return - V_16 ;
V_15 = F_6 ( V_12 ) ;
if ( V_15 )
return V_15 ;
V_14 = F_7 ( V_12 , V_17 , 0 ) ;
if ( ! V_14 ) {
F_8 ( & V_12 -> V_18 , L_2 ) ;
return - V_19 ;
}
if ( strcmp ( V_12 -> V_20 , L_3 ) == 0 )
V_2 = V_14 -> V_21 ;
else if ( strcmp ( V_12 -> V_20 , L_4 ) == 0 )
V_8 = V_14 -> V_21 ;
if ( V_2 && V_8 ) {
V_22 = F_1 ;
F_2 ( V_1 L_5 ) ;
}
return 0 ;
}
static int T_2 F_9 ( struct V_11 * V_12 )
{
F_10 ( V_12 ) ;
if ( strcmp ( V_12 -> V_20 , L_3 ) == 0 )
V_2 = 0 ;
else if ( strcmp ( V_12 -> V_20 , L_4 ) == 0 )
V_8 = 0 ;
V_22 = NULL ;
return 0 ;
}
static int T_3 F_11 ( void )
{
int V_23 ;
V_23 = F_12 ( & V_24 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_12 ( & V_25 ) ;
if ( V_23 )
F_13 ( & V_24 ) ;
return V_23 ;
}
static void T_4 F_14 ( void )
{
F_13 ( & V_25 ) ;
F_13 ( & V_24 ) ;
}
