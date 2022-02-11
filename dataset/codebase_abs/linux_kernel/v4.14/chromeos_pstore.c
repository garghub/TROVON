static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_2 V_5 ;
V_4 = F_2 ( V_2 , V_6 , 0 ) ;
if ( ! V_4 )
return - V_7 ;
V_5 = F_3 ( V_4 ) ;
if ( ! V_4 -> V_8 || ! V_5 )
return - V_7 ;
F_4 ( L_1 ) ;
V_9 . V_10 = V_5 ;
V_9 . V_11 = V_4 -> V_8 ;
return 0 ;
}
static bool T_1 F_5 ( void )
{
if ( ! F_6 ( & V_12 , F_1 ) )
return true ;
return false ;
}
static inline bool F_5 ( void ) { return false ; }
static int T_1 F_7 ( void )
{
bool V_13 ;
V_13 = F_5 () ;
if ( V_13 || F_8 ( V_14 ) )
return F_9 ( & V_15 ) ;
return - V_16 ;
}
static void T_3 F_10 ( void )
{
F_11 ( & V_15 ) ;
}
