static void F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_4 * V_5 = ( (struct V_4 * ) V_3 -> V_6 ) ;
struct V_7 * V_8 = V_5 -> V_8 ;
F_2 ( L_1 ,
F_3 ( V_3 -> V_9 ) , V_8 -> V_10 ) ;
V_2 -> V_11 . V_12 = V_13 ;
V_2 -> V_11 . V_14 = V_5 -> V_14 ;
V_2 -> V_11 . V_10 = V_8 -> V_10 ;
V_2 -> V_11 . V_15 = F_4 ( V_3 -> V_9 ) ?
V_16 : V_17 ;
V_2 -> V_11 . V_18 = F_5 ( V_3 -> V_9 ) ;
F_6 ( V_2 , V_3 , V_13 , 1 ) ;
if ( V_3 -> V_19 )
memcpy ( V_2 -> V_20 . V_21 . V_22 , V_3 -> V_19 , 8 ) ;
}
static struct V_4 * F_7 ( struct V_7 * V_8 )
{
struct V_4 * V_5 , * V_23 ;
F_8 ( & V_8 -> V_24 ) ;
F_9 (priv, tmp, &vdev->priv_tx, list) {
F_10 ( & V_5 -> V_25 , & V_8 -> V_26 ) ;
F_11 ( & V_8 -> V_24 ) ;
return V_5 ;
}
F_11 ( & V_8 -> V_24 ) ;
return NULL ;
}
static int F_12 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = NULL ;
struct V_27 V_28 ;
struct V_29 V_30 [ 3 ] ;
T_1 V_31 ;
T_1 V_32 = 0 ;
while ( ( V_5 = F_7 ( V_8 ) ) != NULL ) {
int V_33 ;
struct V_3 * V_3 = V_5 -> V_3 ;
struct V_1 V_34 ;
struct V_35 * V_36 = NULL ;
V_31 = 0 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
F_2 ( L_2 , V_3 ) ;
F_1 ( & V_34 , V_3 ) ;
F_13 ( & V_34 , 1 ) ;
V_30 [ 0 ] . V_37 = & V_34 ;
V_30 [ 0 ] . V_38 = sizeof( V_34 ) ;
V_31 += sizeof( V_34 ) ;
if ( ! F_4 ( V_3 -> V_9 ) && V_3 -> V_39 > 0 ) {
V_30 [ 1 ] . V_37 = V_3 -> V_40 ;
V_30 [ 1 ] . V_38 = V_3 -> V_39 ;
V_31 += V_3 -> V_39 ;
}
if ( F_14 ( V_3 -> V_9 ) == V_41 ) {
T_2 V_42 = 0 ;
V_36 = F_15 ( V_3 , & V_42 ) ;
if ( ! V_36 ) {
F_16 ( & V_8 -> V_43 ,
V_44 ) ;
return - 1 ;
}
V_30 [ 2 ] . V_37 = V_36 ;
V_30 [ 2 ] . V_38 = V_42 ;
V_31 += V_42 ;
}
V_33 = F_17 ( V_8 -> V_43 . V_45 , & V_28 , V_30 , 3 , V_31 ) ;
if ( V_33 != V_31 ) {
F_18 ( L_3 , V_33 ,
V_31 ) ;
F_19 ( V_36 ) ;
F_16 ( & V_8 -> V_43 , V_46 ) ;
return - 1 ;
}
F_19 ( V_36 ) ;
F_2 ( L_4 ) ;
V_32 += V_31 ;
}
return V_32 ;
}
static struct V_47 * F_20 ( struct V_7 * V_8 )
{
struct V_47 * V_48 , * V_23 ;
F_8 ( & V_8 -> V_24 ) ;
F_9 (unlink, tmp, &vdev->unlink_tx, list) {
F_10 ( & V_48 -> V_25 , & V_8 -> V_49 ) ;
F_11 ( & V_8 -> V_24 ) ;
return V_48 ;
}
F_11 ( & V_8 -> V_24 ) ;
return NULL ;
}
static int F_21 ( struct V_7 * V_8 )
{
struct V_47 * V_48 = NULL ;
struct V_27 V_28 ;
struct V_29 V_30 [ 3 ] ;
T_1 V_31 ;
T_1 V_32 = 0 ;
while ( ( V_48 = F_20 ( V_8 ) ) != NULL ) {
int V_33 ;
struct V_1 V_34 ;
V_31 = 0 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
F_2 ( L_5 , V_48 -> V_14 ) ;
V_34 . V_11 . V_12 = V_50 ;
V_34 . V_11 . V_14 = V_48 -> V_14 ;
V_34 . V_11 . V_10 = V_8 -> V_10 ;
V_34 . V_11 . V_18 = 0 ;
V_34 . V_20 . V_51 . V_14 = V_48 -> V_52 ;
F_13 ( & V_34 , 1 ) ;
V_30 [ 0 ] . V_37 = & V_34 ;
V_30 [ 0 ] . V_38 = sizeof( V_34 ) ;
V_31 += sizeof( V_34 ) ;
V_33 = F_17 ( V_8 -> V_43 . V_45 , & V_28 , V_30 , 1 , V_31 ) ;
if ( V_33 != V_31 ) {
F_18 ( L_3 , V_33 ,
V_31 ) ;
F_16 ( & V_8 -> V_43 , V_46 ) ;
return - 1 ;
}
F_2 ( L_4 ) ;
V_32 += V_31 ;
}
return V_32 ;
}
int F_22 ( void * V_53 )
{
struct V_54 * V_43 = V_53 ;
struct V_7 * V_8 = F_23 ( V_43 , struct V_7 , V_43 ) ;
while ( ! F_24 () ) {
if ( F_12 ( V_8 ) < 0 )
break;
if ( F_21 ( V_8 ) < 0 )
break;
F_25 ( V_8 -> V_55 ,
( ! F_26 ( & V_8 -> V_56 ) ||
! F_26 ( & V_8 -> V_57 ) ||
F_24 () ) ) ;
F_2 ( L_6 ) ;
}
return 0 ;
}
