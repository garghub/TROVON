static int F_1 ( struct V_1 * V_2 ,
int V_3 , void * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 , V_8 ;
unsigned short * V_9 = V_4 ;
T_1 * V_10 = V_4 ;
V_8 = F_3 ( V_6 , V_4 , V_3 * 2 ) ;
if ( V_8 < 0 ) {
F_4 ( & V_6 -> V_2 , L_1 ) ;
return V_8 ;
}
for ( V_7 = 0 ; V_7 < V_3 ; V_7 ++ )
V_9 [ V_7 ] = F_5 ( V_10 [ V_7 ] ) ;
return 0 ;
}
static int F_6 ( struct V_5 * V_6 )
{
const struct V_11 * V_12 = F_7 ( V_6 ) ;
return F_8 ( & V_6 -> V_2 , V_6 -> V_13 , NULL ,
V_12 -> V_14 , V_12 -> V_15 ,
& V_16 ) ;
}
static int F_9 ( struct V_5 * V_6 )
{
return F_10 ( & V_6 -> V_2 , V_6 -> V_13 ) ;
}
