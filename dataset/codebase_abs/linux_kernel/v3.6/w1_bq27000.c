static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_4 ;
struct V_5 * V_6 = F_2 ( V_2 -> V_7 , struct V_5 , V_2 ) ;
F_3 ( & V_6 -> V_8 -> V_9 ) ;
F_4 ( V_6 -> V_8 , V_10 | V_3 ) ;
V_4 = F_5 ( V_6 -> V_8 ) ;
F_6 ( & V_6 -> V_8 -> V_9 ) ;
return V_4 ;
}
static int F_7 ( struct V_5 * V_6 )
{
int V_11 ;
struct V_12 * V_13 ;
V_13 = F_8 ( L_1 , - 1 ) ;
if ( ! V_13 ) {
V_11 = - V_14 ;
return V_11 ;
}
V_11 = F_9 ( V_13 ,
& V_15 ,
sizeof( V_15 ) ) ;
V_13 -> V_2 . V_7 = & V_6 -> V_2 ;
V_11 = F_10 ( V_13 ) ;
if ( V_11 )
goto V_16;
F_11 ( & V_6 -> V_2 , V_13 ) ;
goto V_17;
V_16:
F_12 ( V_13 ) ;
V_17:
return V_11 ;
}
static void F_13 ( struct V_5 * V_6 )
{
struct V_12 * V_13 = F_14 ( & V_6 -> V_2 ) ;
F_12 ( V_13 ) ;
}
static int T_2 F_15 ( void )
{
if ( V_18 )
V_19 . V_20 = V_18 ;
return F_16 ( & V_19 ) ;
}
static void T_3 F_17 ( void )
{
F_18 ( & V_19 ) ;
}
