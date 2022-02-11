int
F_1 ( struct V_1 * V_2 )
{
static int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_10 = 0 ;
int V_11 ;
if ( V_3 )
return 0 ;
F_3 (ring, dev_priv, i) {
F_4 (obj, &ring->active_list, ring_list[ring->id]) {
if ( V_7 -> V_12 . V_2 != V_2 ||
! F_5 ( & V_7 -> V_12 . V_13 . V_13 ) ) {
F_6 ( L_1 ,
V_9 -> V_14 , V_7 ) ;
V_10 ++ ;
break;
} else if ( ! V_7 -> V_15 ||
V_7 -> V_16 [ V_9 -> V_17 ] == NULL ) {
F_6 ( L_2 ,
V_9 -> V_14 , V_7 ) ;
V_10 ++ ;
} else if ( V_7 -> V_12 . V_18 ) {
F_6 ( L_3 ,
V_9 -> V_14 ,
V_7 , V_7 -> V_12 . V_18 ) ;
V_10 ++ ;
}
}
}
return V_3 = V_10 ;
}
