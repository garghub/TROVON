const struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_6 ) ; V_5 ++ ) {
const struct V_7 * V_8 = & V_6 [ V_5 ] ;
if ( V_8 -> V_9 . V_10 == V_4 )
return & V_8 -> V_9 ;
}
return NULL ;
}
