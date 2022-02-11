static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_3 ( V_2 , & V_6 ) ;
if ( V_5 < 0 )
return V_5 ;
return F_4 ( V_2 -> V_7 ) ;
}
static int F_5 ( struct V_8 * V_9 ,
const struct V_3 * V_4 )
{
return F_6 ( V_9 , V_4 , L_1 ,
& V_10 [ V_4 -> V_11 ] ,
F_1 , sizeof( struct V_1 ) ) ;
}
