static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_5 ;
int V_6 ;
V_5 = F_2 ( & V_2 -> V_7 , sizeof( struct V_5 ) , V_8 ) ;
if ( V_5 == NULL )
return - V_9 ;
F_3 ( V_2 , V_5 ) ;
V_5 -> V_7 = & V_2 -> V_7 ;
V_5 -> V_10 = V_2 -> V_11 ;
V_5 -> V_12 = F_4 ( V_2 , & V_13 ) ;
if ( F_5 ( V_5 -> V_12 ) ) {
V_6 = F_6 ( V_5 -> V_12 ) ;
F_7 ( V_5 -> V_7 , L_1 ,
V_6 ) ;
return V_6 ;
}
return F_8 ( V_5 , V_2 -> V_11 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_10 ( V_2 ) ;
F_11 ( V_5 ) ;
return 0 ;
}
