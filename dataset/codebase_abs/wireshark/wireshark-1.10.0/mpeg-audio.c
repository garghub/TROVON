int
F_1 ( const struct V_1 * V_1 )
{
return V_2 [ V_1 -> V_3 ] ;
}
int
F_2 ( const struct V_1 * V_1 )
{
return V_4 [ V_1 -> V_5 ] ;
}
unsigned
F_3 ( const struct V_1 * V_1 )
{
return V_6 [ V_2 [ V_1 -> V_3 ] ] [ F_2 ( V_1 ) ] ;
}
unsigned
F_4 ( const struct V_1 * V_1 )
{
return ( 1000 * ( V_7 [ V_2 [ V_1 -> V_3 ] ] [ V_4 [ V_1 -> V_5 ] ] [ V_1 -> V_8 ] ) ) ;
}
unsigned
F_5 ( const struct V_1 * V_1 )
{
return ( V_9 [ V_2 [ V_1 -> V_3 ] ] [ V_1 -> V_10 ] ) ;
}
unsigned
F_6 ( const struct V_1 * V_1 )
{
return ( V_1 -> V_11 ? V_12 [ V_4 [ V_1 -> V_5 ] ] : 0 ) ;
}
