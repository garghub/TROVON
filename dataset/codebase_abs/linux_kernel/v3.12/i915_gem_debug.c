int
F_1 ( struct V_1 * V_2 )
{
static int V_3 ;
T_1 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 ;
int V_8 = 0 ;
if ( V_3 )
return 0 ;
F_2 (obj, &dev_priv->render_ring.active_list, list) {
if ( V_7 -> V_9 . V_2 != V_2 ||
! F_3 ( & V_7 -> V_9 . V_10 . V_10 ) ) {
F_4 ( L_1 , V_7 ) ;
V_8 ++ ;
break;
} else if ( ! V_7 -> V_11 ||
( V_7 -> V_9 . V_12 & V_13 ) == 0 ) {
F_4 ( L_2 ,
V_7 ,
V_7 -> V_11 ,
V_7 -> V_9 . V_12 ) ;
V_8 ++ ;
} else if ( V_7 -> V_9 . V_14 && F_5 ( & V_7 -> V_15 ) ) {
F_4 ( L_3 ,
V_7 ,
V_7 -> V_9 . V_14 ,
! F_5 ( & V_7 -> V_15 ) ) ;
V_8 ++ ;
}
}
F_2 (obj, &dev_priv->mm.flushing_list, list) {
if ( V_7 -> V_9 . V_2 != V_2 ||
! F_3 ( & V_7 -> V_9 . V_10 . V_10 ) ) {
F_4 ( L_4 , V_7 ) ;
V_8 ++ ;
break;
} else if ( ! V_7 -> V_11 ||
( V_7 -> V_9 . V_14 & V_13 ) == 0 ||
F_5 ( & V_7 -> V_15 ) ) {
F_4 ( L_5 ,
V_7 ,
V_7 -> V_11 ,
V_7 -> V_9 . V_14 ,
! F_5 ( & V_7 -> V_15 ) ) ;
V_8 ++ ;
}
}
F_2 (obj, &dev_priv->mm.gpu_write_list, gpu_write_list) {
if ( V_7 -> V_9 . V_2 != V_2 ||
! F_3 ( & V_7 -> V_9 . V_10 . V_10 ) ) {
F_4 ( L_6 , V_7 ) ;
V_8 ++ ;
break;
} else if ( ! V_7 -> V_11 ||
( V_7 -> V_9 . V_14 & V_13 ) == 0 ) {
F_4 ( L_7 ,
V_7 ,
V_7 -> V_11 ,
V_7 -> V_9 . V_14 ) ;
V_8 ++ ;
}
}
F_2 (obj, &i915_gtt_vm->inactive_list, list) {
if ( V_7 -> V_9 . V_2 != V_2 ||
! F_3 ( & V_7 -> V_9 . V_10 . V_10 ) ) {
F_4 ( L_8 , V_7 ) ;
V_8 ++ ;
break;
} else if ( V_7 -> V_16 || V_7 -> V_11 ||
( V_7 -> V_9 . V_14 & V_13 ) ) {
F_4 ( L_9 ,
V_7 ,
V_7 -> V_16 , V_7 -> V_11 ,
V_7 -> V_9 . V_14 ) ;
V_8 ++ ;
}
}
return V_3 = V_8 ;
}
