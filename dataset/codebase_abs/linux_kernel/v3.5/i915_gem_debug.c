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
F_2 (obj, &dev_priv->mm.inactive_list, list) {
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
void
F_6 ( struct V_6 * V_7 , int V_17 )
{
struct V_1 * V_2 = V_7 -> V_9 . V_2 ;
int V_18 ;
T_2 * V_19 ;
T_2 * V_20 = NULL ;
int V_21 = 0 ;
F_7 ( L_10 ,
V_22 , V_7 , V_7 -> V_23 , V_17 ,
V_7 -> V_24 / 1024 ) ;
V_19 = F_8 ( V_2 -> V_25 -> V_9 + V_7 -> V_23 , V_7 -> V_9 . V_24 ) ;
if ( V_19 == NULL ) {
F_4 ( L_11 ) ;
return;
}
for ( V_18 = 0 ; V_18 < V_7 -> V_24 / V_26 ; V_18 ++ ) {
int V_27 ;
V_20 = F_9 ( V_7 -> V_28 [ V_18 ] ) ;
if ( V_20 == NULL ) {
F_4 ( L_12 ) ;
goto V_29;
}
for ( V_27 = 0 ; V_27 < V_26 / 4 ; V_27 ++ ) {
T_2 V_30 = V_20 [ V_27 ] ;
T_2 V_31 = F_10 ( V_19 +
V_18 * 1024 + V_27 ) ;
if ( V_30 != V_31 ) {
F_7 ( L_13
L_14 ,
( int ) ( V_7 -> V_23 +
V_18 * V_26 + V_27 * 4 ) ,
V_30 , V_31 ) ;
if ( V_21 ++ >= 8 ) {
F_7 ( L_15 ) ;
goto V_29;
}
}
}
F_11 ( V_20 ) ;
V_20 = NULL ;
}
V_29:
if ( V_20 != NULL )
F_11 ( V_20 ) ;
F_12 ( V_19 ) ;
F_13 ( 1 ) ;
F_14 ( V_7 ) ;
}
