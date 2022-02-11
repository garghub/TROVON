static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_3 [ V_4 ] != 0xFF ; V_4 += 2 )
if ( F_2 ( V_2 , V_3 [ V_4 ] , V_3 [ V_4 + 1 ] ) < 0 )
return - 1 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
if ( ! F_4 ( V_8 , V_9 ) )
return - V_10 ;
V_2 -> V_11 = V_12 ;
F_5 ( & V_2 -> V_13 ,
L_1 ,
V_2 -> V_14 , V_8 -> V_15 ) ;
if ( F_1 ( V_2 , V_16 ) < 0 ) {
F_6 ( & V_2 -> V_13 , L_2 ) ;
return - V_10 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
return 0 ;
}
