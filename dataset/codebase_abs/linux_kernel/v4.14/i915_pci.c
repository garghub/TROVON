static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 ) ;
F_4 ( V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 , const struct V_5 * V_6 )
{
struct V_7 * V_8 =
(struct V_7 * ) V_6 -> V_9 ;
int V_10 ;
if ( F_6 ( V_8 ) && ! V_11 . V_12 ) {
F_7 ( L_1
L_2
L_3 ) ;
return - V_13 ;
}
if ( F_8 ( V_2 -> V_14 ) )
return - V_13 ;
if ( F_9 ( V_2 ) )
return - V_15 ;
V_10 = F_10 ( V_2 , V_6 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_11 ( V_2 ) ;
if ( V_10 ) {
F_1 ( V_2 ) ;
return V_10 > 0 ? - V_16 : V_10 ;
}
return 0 ;
}
static int T_1 F_12 ( void )
{
bool V_17 = true ;
int V_10 ;
V_10 = F_13 () ;
if ( V_10 )
return V_10 > 0 ? 0 : V_10 ;
if ( V_11 . V_18 == 0 )
V_17 = false ;
if ( F_14 () && V_11 . V_18 == - 1 )
V_17 = false ;
if ( ! V_17 ) {
F_15 ( L_4 ) ;
return 0 ;
}
return F_16 ( & V_19 ) ;
}
static void T_2 F_17 ( void )
{
if ( ! V_19 . V_20 . V_21 )
return;
F_18 ( & V_19 ) ;
}
