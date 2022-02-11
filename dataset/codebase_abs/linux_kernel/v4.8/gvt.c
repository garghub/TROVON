int F_1 ( void )
{
if ( V_1 . V_2 )
return 0 ;
if ( F_2 () && ! F_3 () )
return - V_3 ;
if ( F_3 () ) {
V_1 . V_4 = F_4 (
F_5 ( V_5 ) , L_1 ) ;
V_1 . V_6 = V_7 ;
} else {
V_1 . V_4 = F_4 (
F_5 ( V_8 ) , L_2 ) ;
V_1 . V_6 = V_9 ;
}
if ( ! V_1 . V_4 )
return - V_10 ;
if ( ! F_6 () )
return - V_3 ;
F_7 ( L_3 ,
V_11 [ V_1 . V_6 ] ) ;
V_1 . V_2 = true ;
return 0 ;
}
static void F_8 ( struct V_12 * V_13 )
{
if ( F_9 ( V_13 -> V_14 ) )
V_13 -> V_15 . V_16 = 8 ;
}
void F_10 ( struct V_17 * V_14 )
{
struct V_12 * V_13 = & V_14 -> V_13 ;
if ( F_11 ( ! V_13 -> V_2 ) )
return;
V_13 -> V_2 = false ;
}
int F_12 ( struct V_17 * V_14 )
{
struct V_12 * V_13 = & V_14 -> V_13 ;
if ( F_11 ( ! V_1 . V_2 ) )
return - V_10 ;
if ( F_11 ( V_13 -> V_2 ) )
return - V_18 ;
F_7 ( L_4 ) ;
F_8 ( V_13 ) ;
F_7 ( L_5 ) ;
V_13 -> V_2 = true ;
return 0 ;
}
