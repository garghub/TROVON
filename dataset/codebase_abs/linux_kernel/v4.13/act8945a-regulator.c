static int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 = { } ;
const struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 , V_10 ;
bool V_11 ;
V_11 = F_2 ( V_2 -> V_12 . V_13 -> V_14 ,
L_1 ) ;
if ( V_11 ) {
V_6 = V_15 ;
V_10 = F_3 ( V_15 ) ;
} else {
V_6 = V_16 ;
V_10 = F_3 ( V_16 ) ;
}
V_4 . V_12 = & V_2 -> V_12 ;
V_4 . V_12 -> V_14 = V_2 -> V_12 . V_13 -> V_14 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
V_8 = F_4 ( & V_2 -> V_12 , & V_6 [ V_9 ] , & V_4 ) ;
if ( F_5 ( V_8 ) ) {
F_6 ( & V_2 -> V_12 ,
L_2 ,
V_6 [ V_9 ] . V_17 ) ;
return F_7 ( V_8 ) ;
}
}
return 0 ;
}
