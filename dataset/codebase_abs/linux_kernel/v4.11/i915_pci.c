static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 =
(struct V_5 * ) V_4 -> V_7 ;
if ( F_2 ( V_6 ) && ! V_8 . V_9 ) {
F_3 ( L_1
L_2
L_3 ) ;
return - V_10 ;
}
if ( F_4 ( V_2 -> V_11 ) )
return - V_10 ;
if ( F_5 ( V_2 ) )
return - V_12 ;
return F_6 ( V_2 , V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_8 ( V_2 ) ;
F_9 ( V_14 ) ;
F_10 ( V_14 ) ;
}
static int T_1 F_11 ( void )
{
bool V_15 = true ;
if ( V_8 . V_16 == 0 )
V_15 = false ;
if ( F_12 () && V_8 . V_16 == - 1 )
V_15 = false ;
if ( ! V_15 ) {
F_13 ( L_4 ) ;
return 0 ;
}
return F_14 ( & V_17 ) ;
}
static void T_2 F_15 ( void )
{
if ( ! V_17 . V_18 . V_19 )
return;
F_16 ( & V_17 ) ;
}
