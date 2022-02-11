void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 * V_5 = NULL ;
T_1 V_6 , V_7 ;
switch ( V_4 -> V_8 ) {
case 1 :
V_5 = V_9 [ 0 ] ;
V_6 = F_2 ( V_9 ) ;
break;
default:
F_3 ( 1 ) ;
return;
}
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ , V_5 += 2 )
F_4 ( V_2 , V_10 | V_5 [ 0 ] , V_5 [ 1 ] ) ;
}
const struct V_11
* F_5 ( struct V_1 * V_2 , T_1 V_12 )
{
const struct V_11 * V_13 ;
unsigned int V_7 ;
V_13 = V_14 ;
for ( V_7 = 0 ; V_7 < F_2 ( V_14 ) ; V_7 ++ , V_13 ++ ) {
if ( V_13 -> V_12 == V_12 )
return V_13 ;
}
return NULL ;
}
