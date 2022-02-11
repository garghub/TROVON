static const struct V_1 * F_1 (
const struct V_1 * V_2 , int V_3 ,
int V_4 , int V_5 , int V_6 )
{
const struct V_1 * V_7 = NULL ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_3 ; V_8 ++ ) {
if ( V_2 [ V_8 ] . V_9 != V_4 || V_2 [ V_8 ] . V_10 != V_5 )
continue;
if ( ! V_7 || abs ( V_2 [ V_8 ] . V_6 - V_6 ) <
abs ( V_7 -> V_6 - V_6 ) )
V_7 = & V_2 [ V_8 ] ;
}
return V_7 ;
}
const struct V_1 * F_2 ( int V_4 , int V_5 , int V_6 )
{
return F_1 ( V_11 , F_3 ( V_11 ) ,
V_4 , V_5 , V_6 ) ;
}
const struct V_1 * F_4 ( int V_4 , int V_5 ,
int V_6 )
{
return F_1 ( V_12 , F_3 ( V_12 ) ,
V_4 , V_5 , V_6 ) ;
}
