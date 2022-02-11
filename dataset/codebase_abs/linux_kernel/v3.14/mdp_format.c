T_1 F_1 ( T_1 * V_1 , T_1 V_2 )
{
T_1 V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
const struct V_5 * V_6 = & V_4 [ V_3 ] ;
if ( V_3 == V_2 )
break;
V_1 [ V_3 ] = V_6 -> V_7 . V_8 ;
}
return V_3 ;
}
const struct V_9 * F_3 ( struct V_10 * V_11 , T_1 V_12 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
const struct V_5 * V_6 = & V_4 [ V_3 ] ;
if ( V_6 -> V_7 . V_8 == V_12 )
return & V_6 -> V_7 ;
}
return NULL ;
}
