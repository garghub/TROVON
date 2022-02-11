static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned int * V_4 ;
V_2 -> V_4 = F_2 ( V_2 -> V_5 + 1 , sizeof( unsigned int ) ,
V_6 ) ;
if ( ! V_2 -> V_4 )
return - V_7 ;
V_4 = V_2 -> V_4 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_8 ; V_3 ++ )
V_4 [ V_2 -> V_9 [ V_3 ] . V_10 ] = V_2 -> V_9 [ V_3 ] . V_11 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_10 , unsigned int * V_12 )
{
unsigned int * V_4 = V_2 -> V_4 ;
* V_12 = V_4 [ V_10 ] ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_10 ,
unsigned int V_12 )
{
unsigned int * V_4 = V_2 -> V_4 ;
V_4 [ V_10 ] = V_12 ;
return 0 ;
}
