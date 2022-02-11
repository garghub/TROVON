static bool T_1
F_1 ( struct V_1 * V_2 )
{
T_2 V_3 = F_2 () ;
if ( ( V_3 & V_4 ) != V_2 -> V_5 )
return false ;
V_3 &= V_6 | V_7 ;
return ( V_3 >= V_2 -> V_8 && V_3 <= V_2 -> V_9 ) ;
}
void F_3 ( void )
{
struct V_1 * V_10 = V_11 ;
int V_12 ;
for ( V_12 = 0 ; V_10 [ V_12 ] . V_13 ; V_12 ++ ) {
if ( ! V_10 [ V_12 ] . F_4 ( & V_10 [ V_12 ] ) )
continue;
if ( ! F_5 ( V_10 [ V_12 ] . V_14 ) )
F_6 ( L_1 , V_10 [ V_12 ] . V_13 ) ;
F_7 ( V_10 [ V_12 ] . V_14 ) ;
}
}
