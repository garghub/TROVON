const struct V_1 * F_1 ( T_1 V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < F_2 ( V_7 ) ; V_6 ++ ) {
const struct V_8 * V_9 = & V_7 [ V_6 ] ;
if ( V_2 == V_9 -> V_2 &&
V_3 == V_9 -> V_3 &&
V_4 == V_9 -> V_4 &&
( ( V_5 == V_9 -> V_5 ) ||
( V_9 -> V_5 == 0xffff ) ) )
return V_9 -> V_10 ;
}
return & V_11 ;
}
