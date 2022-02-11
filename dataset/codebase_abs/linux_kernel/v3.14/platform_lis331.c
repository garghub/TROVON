static void T_1 * F_1 ( void * V_1 )
{
static short V_2 ;
struct V_3 * V_4 = V_1 ;
int V_5 = F_2 ( L_1 ) ;
int V_6 = F_2 ( L_2 ) ;
if ( V_5 < 0 )
return NULL ;
if ( V_6 < 0 )
return NULL ;
V_4 -> V_7 = V_5 + V_8 ;
V_2 = V_6 + V_8 ;
return & V_2 ;
}
