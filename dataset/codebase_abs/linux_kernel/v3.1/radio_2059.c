const struct V_1
* F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
const struct V_1 * V_5 ;
unsigned int V_6 ;
V_5 = V_7 ;
for ( V_6 = 0 ; V_6 < F_2 ( V_7 ) ; V_6 ++ , V_5 ++ ) {
if ( V_5 -> V_4 == V_4 )
return V_5 ;
}
return NULL ;
}
