static int F_1 ( struct V_1 * V_2 ,
int V_3 , void * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_7 , V_8 ;
unsigned short * V_9 = V_4 ;
V_8 = F_3 ( V_6 , V_4 , V_3 * 2 ) ;
if ( V_8 < 0 ) {
F_4 ( & V_6 -> V_2 , L_1 ) ;
return V_8 ;
}
for ( V_7 = 0 ; V_7 < V_3 ; V_7 ++ )
V_9 [ V_7 ] = F_5 ( V_9 [ V_7 ] ) ;
return 0 ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_10 * V_11 ;
V_11 = F_7 ( & V_6 -> V_2 , V_6 -> V_12 , NULL ,
F_8 ( V_6 ) -> V_13 ,
& V_14 ) ;
if ( F_9 ( V_11 ) )
return F_10 ( V_11 ) ;
F_11 ( V_6 , V_11 ) ;
return 0 ;
}
static int F_12 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = F_13 ( & V_6 -> V_2 ) ;
return F_14 ( V_11 , V_6 -> V_12 ) ;
}
