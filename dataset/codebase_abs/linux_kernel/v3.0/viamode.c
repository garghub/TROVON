struct V_1 * F_1 ( int V_2 , int V_3 )
{
T_1 V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ )
if ( V_5 [ V_4 ] . V_6 &&
V_5 [ V_4 ] . V_7 [ 0 ] . V_7 . V_8 == V_2 &&
V_5 [ V_4 ] . V_7 [ 0 ] . V_7 . V_9 == V_3 )
return & V_5 [ V_4 ] ;
return NULL ;
}
struct V_1 * F_3 ( int V_2 , int V_3 )
{
T_1 V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_10 ) ; V_4 ++ )
if ( V_10 [ V_4 ] . V_6 &&
V_10 [ V_4 ] . V_7 [ 0 ] . V_7 . V_8 == V_2 &&
V_10 [ V_4 ] . V_7 [ 0 ] . V_7 . V_9 == V_3 )
return & V_10 [ V_4 ] ;
return NULL ;
}
