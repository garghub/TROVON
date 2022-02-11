static bool F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
bool V_8 ;
if ( V_2 -> V_9 == NULL || V_2 -> V_9 -> type != V_10 )
return false ;
if ( F_2 ( V_2 ) < V_2 -> V_11 )
return false ;
if ( F_2 ( V_2 ) + V_12 > V_2 -> V_13 )
return false ;
V_8 = F_3 ( F_4 ( V_2 ) -> V_14 , V_6 -> V_15 ) ;
V_8 ^= V_6 -> V_16 ;
return V_8 ;
}
static int T_1 F_5 ( void )
{
return F_6 ( & V_17 ) ;
}
static void T_2 F_7 ( void )
{
F_8 ( & V_17 ) ;
}
