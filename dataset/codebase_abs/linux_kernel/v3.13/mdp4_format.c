T_1 F_1 ( enum V_1 V_2 , T_1 * V_3 ,
T_1 V_4 )
{
T_1 V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_6 ) ; V_5 ++ ) {
const struct V_7 * V_8 = & V_6 [ V_5 ] ;
if ( V_5 == V_4 )
break;
V_3 [ V_5 ] = V_8 -> V_9 . V_10 ;
}
return V_5 ;
}
const struct V_11 * F_3 ( struct V_12 * V_13 , T_1 V_14 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_6 ) ; V_5 ++ ) {
const struct V_7 * V_8 = & V_6 [ V_5 ] ;
if ( V_8 -> V_9 . V_10 == V_14 )
return & V_8 -> V_9 ;
}
return NULL ;
}
