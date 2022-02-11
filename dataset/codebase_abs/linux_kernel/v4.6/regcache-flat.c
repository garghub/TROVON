static inline unsigned int F_1 ( const struct V_1 * V_2 ,
unsigned int V_3 )
{
return F_2 ( V_2 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_4 ;
unsigned int * V_5 ;
if ( ! V_2 || V_2 -> V_6 < 0 )
return - V_7 ;
V_2 -> V_5 = F_4 ( F_1 ( V_2 , V_2 -> V_8 )
+ 1 , sizeof( unsigned int ) , V_9 ) ;
if ( ! V_2 -> V_5 )
return - V_10 ;
V_5 = V_2 -> V_5 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_11 ; V_4 ++ )
V_5 [ F_1 ( V_2 , V_2 -> V_12 [ V_4 ] . V_3 ) ] =
V_2 -> V_12 [ V_4 ] . V_13 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int * V_14 )
{
unsigned int * V_5 = V_2 -> V_5 ;
* V_14 = V_5 [ F_1 ( V_2 , V_3 ) ] ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_14 )
{
unsigned int * V_5 = V_2 -> V_5 ;
V_5 [ F_1 ( V_2 , V_3 ) ] = V_14 ;
return 0 ;
}
