static struct V_1 * F_1 ( struct V_1 * V_2 , int V_3 ,
int V_4 , int V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 ; V_6 ++ )
if ( V_2 [ V_6 ] . V_7 &&
V_2 [ V_6 ] . V_8 [ 0 ] . V_8 . V_9 == V_4 &&
V_2 [ V_6 ] . V_8 [ 0 ] . V_8 . V_10 == V_5 )
return & V_11 [ V_6 ] ;
return NULL ;
}
static struct V_12 * F_2 ( struct V_1 * V_2 ,
int V_13 )
{
struct V_12 * V_14 ;
int V_6 ;
if ( ! V_2 )
return NULL ;
V_14 = & V_2 -> V_8 [ 0 ] ;
for ( V_6 = 1 ; V_6 < V_2 -> V_7 ; V_6 ++ ) {
if ( abs ( V_2 -> V_8 [ V_6 ] . V_15 - V_13 )
< abs ( V_14 -> V_15 - V_13 ) )
V_14 = & V_2 -> V_8 [ V_6 ] ;
}
return V_14 ;
}
static struct V_1 * F_3 ( int V_4 , int V_5 )
{
return F_1 ( V_11 , F_4 ( V_11 ) , V_4 , V_5 ) ;
}
struct V_12 * F_5 ( int V_4 , int V_5 , int V_13 )
{
return F_2 ( F_3 ( V_4 , V_5 ) , V_13 ) ;
}
static struct V_1 * F_6 ( int V_4 , int V_5 )
{
return F_1 ( V_16 , F_4 ( V_16 ) , V_4 ,
V_5 ) ;
}
struct V_12 * F_7 ( int V_4 , int V_5 , int V_13 )
{
return F_2 ( F_6 ( V_4 , V_5 ) , V_13 ) ;
}
