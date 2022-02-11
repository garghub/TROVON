void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
if ( ! V_2 ) {
F_3 ( L_1 ) ;
return;
}
F_4 ( V_6 -> V_7 , V_8 | V_4 ) ;
F_4 ( V_6 -> V_7 , V_3 ) ;
}
int F_5 ( struct V_1 * V_2 , T_1 V_4 )
{
T_1 V_9 ;
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_2 ) ;
if ( ! V_2 )
return 0 ;
F_4 ( V_6 -> V_7 , V_10 | V_4 ) ;
V_9 = F_6 ( V_6 -> V_7 ) ;
return V_9 ;
}
static int F_7 ( struct V_5 * V_6 )
{
int V_11 ;
int V_12 = 1 ;
struct V_13 * V_14 ;
V_14 = F_8 ( L_2 , V_12 ) ;
if ( ! V_14 ) {
V_11 = - V_15 ;
return V_11 ;
}
V_14 -> V_2 . V_16 = & V_6 -> V_2 ;
V_11 = F_9 ( V_14 ) ;
if ( V_11 )
goto V_17;
F_10 ( & V_6 -> V_2 , V_14 ) ;
goto V_18;
V_17:
F_11 ( V_14 ) ;
V_18:
return V_11 ;
}
static void F_12 ( struct V_5 * V_6 )
{
struct V_13 * V_14 = F_13 ( & V_6 -> V_2 ) ;
F_11 ( V_14 ) ;
}
static int T_2 F_14 ( void )
{
if ( V_19 )
V_20 . V_21 = V_19 ;
return F_15 ( & V_20 ) ;
}
static void T_3 F_16 ( void )
{
F_17 ( & V_20 ) ;
}
