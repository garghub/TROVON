const struct V_1 * F_1 ( const struct V_1 * V_2 )
{
const struct V_1 * V_3 ;
struct V_4 * V_5 = & V_6 ;
for ( V_3 = V_2 ; V_3 -> V_7 | V_3 -> V_8 | V_3 -> V_9 | V_3 -> V_10 ; V_3 ++ ) {
if ( V_3 -> V_7 != V_11 && V_5 -> V_12 != V_3 -> V_7 )
continue;
if ( V_3 -> V_8 != V_13 && V_5 -> V_14 != V_3 -> V_8 )
continue;
if ( V_3 -> V_9 != V_15 && V_5 -> V_16 != V_3 -> V_9 )
continue;
if ( V_3 -> V_10 != V_17 && ! F_2 ( V_5 , V_3 -> V_10 ) )
continue;
return V_3 ;
}
return NULL ;
}
