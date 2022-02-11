static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_4 = V_2 -> V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_7 [ V_6 ] . V_8 ; V_6 ++ )
F_2 ( V_2 , L_1 , V_7 [ V_6 ] . V_8 ,
F_3 ( V_4 -> V_9 . V_10 ,
V_7 [ V_6 ] . V_11 ) ) ;
return 0 ;
}
static int F_4 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_5 ( V_12 , V_13 , F_1 ) ;
}
int T_1 F_6 ( struct V_4 * V_4 )
{
if ( ! F_7 ( L_2 , V_14 , V_4 -> V_15 ,
& V_16 ) )
return - V_17 ;
return 0 ;
}
void F_8 ( struct V_4 * V_4 )
{
F_9 ( L_2 , V_4 -> V_15 ) ;
}
