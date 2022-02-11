static int F_1 ( int V_1 , int V_2 ,
void * V_3 )
{
struct V_4 * V_5 = V_3 ;
int V_6 [ V_5 -> V_7 -> V_8 ] ;
unsigned int V_9 ;
if ( V_1 == V_2 )
return 0 ;
for ( V_9 = 0 ; V_9 < V_5 -> V_7 -> V_8 ; V_9 ++ )
V_6 [ V_9 ] = ( V_2 >> V_9 ) & 1 ;
F_2 ( V_5 -> V_7 -> V_8 , V_5 -> V_7 -> V_10 ,
V_6 ) ;
return 0 ;
}
static int F_3 ( struct V_11 * V_12 )
{
struct V_4 * V_5 ;
int V_13 ;
V_5 = F_4 ( & V_12 -> V_14 , sizeof( * V_5 ) , V_15 ) ;
if ( ! V_5 )
return - V_16 ;
V_5 -> V_7 = F_5 ( & V_12 -> V_14 , NULL , V_17 ) ;
if ( F_6 ( V_5 -> V_7 ) )
return F_7 ( V_5 -> V_7 ) ;
V_13 = F_8 ( & V_12 -> V_14 ,
F_1 , & V_5 -> V_18 , V_5 ) ;
if ( V_13 != 0 ) {
F_9 ( V_5 -> V_7 ) ;
return V_13 ;
}
V_12 -> V_14 . V_19 = V_5 ;
return 0 ;
}
static int F_10 ( struct V_11 * V_12 )
{
struct V_4 * V_5 = F_11 ( & V_12 -> V_14 ) ;
F_12 ( V_5 -> V_18 ) ;
F_9 ( V_5 -> V_7 ) ;
return 0 ;
}
