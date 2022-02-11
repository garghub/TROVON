static int F_1 ( const struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 = 0 ;
int V_5 = 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_6 . V_7 ; ++ V_3 ) {
if ( F_2 ( & V_2 -> V_8 [ V_3 ] . V_6 ) )
V_4 = 1 ;
else if ( F_3 ( & V_2 -> V_8 [ V_3 ] . V_6 ) )
V_5 = 1 ;
}
return V_4 && V_5 ;
}
static int F_4 ( struct V_9 * V_10 ,
const struct V_11 * V_12 )
{
if ( ! F_1 ( V_10 -> V_2 -> V_13 ) )
return - V_14 ;
return 0 ;
}
