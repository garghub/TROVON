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
unsigned long V_24 ;
F_8 ( & V_8 -> V_25 , V_24 ) ;
F_9 (priv, tmp, &vdev->priv_tx, list) {
F_10 ( & V_5 -> V_26 , & V_8 -> V_27 ) ;
F_11 ( & V_8 -> V_25 , V_24 ) ;
return V_5 ;
}
F_11 ( & V_8 -> V_25 , V_24 ) ;
return NULL ;
}
static int F_12 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = NULL ;
struct V_28 V_29 ;
struct V_30 V_31 [ 3 ] ;
T_1 V_32 ;
T_1 V_33 = 0 ;
while ( ( V_5 = F_7 ( V_8 ) ) != NULL ) {
int V_34 ;
struct V_3 * V_3 = V_5 -> V_3 ;
struct V_1 V_35 ;
struct V_36 * V_37 = NULL ;
V_32 = 0 ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
F_2 ( L_2 , V_3 ) ;
F_1 ( & V_35 , V_3 ) ;
F_13 ( & V_35 , 1 ) ;
V_31 [ 0 ] . V_38 = & V_35 ;
V_31 [ 0 ] . V_39 = sizeof( V_35 ) ;
V_32 += sizeof( V_35 ) ;
if ( ! F_4 ( V_3 -> V_9 ) && V_3 -> V_40 > 0 ) {
V_31 [ 1 ] . V_38 = V_3 -> V_41 ;
V_31 [ 1 ] . V_39 = V_3 -> V_40 ;
V_32 += V_3 -> V_40 ;
}
if ( F_14 ( V_3 -> V_9 ) == V_42 ) {
T_2 V_43 = 0 ;
V_37 = F_15 ( V_3 , & V_43 ) ;
if ( ! V_37 ) {
F_16 ( & V_8 -> V_44 ,
V_45 ) ;
return - 1 ;
}
V_31 [ 2 ] . V_38 = V_37 ;
V_31 [ 2 ] . V_39 = V_43 ;
V_32 += V_43 ;
}
V_34 = F_17 ( V_8 -> V_44 . V_46 , & V_29 , V_31 , 3 , V_32 ) ;
if ( V_34 != V_32 ) {
F_18 ( L_3 , V_34 ,
V_32 ) ;
F_19 ( V_37 ) ;
F_16 ( & V_8 -> V_44 , V_47 ) ;
return - 1 ;
}
F_19 ( V_37 ) ;
F_2 ( L_4 ) ;
V_33 += V_32 ;
}
return V_33 ;
}
static struct V_48 * F_20 ( struct V_7 * V_8 )
{
struct V_48 * V_49 , * V_23 ;
unsigned long V_24 ;
F_8 ( & V_8 -> V_25 , V_24 ) ;
F_9 (unlink, tmp, &vdev->unlink_tx, list) {
F_10 ( & V_49 -> V_26 , & V_8 -> V_50 ) ;
F_11 ( & V_8 -> V_25 , V_24 ) ;
return V_49 ;
}
F_11 ( & V_8 -> V_25 , V_24 ) ;
return NULL ;
}
static int F_21 ( struct V_7 * V_8 )
{
struct V_48 * V_49 = NULL ;
struct V_28 V_29 ;
struct V_30 V_31 [ 3 ] ;
T_1 V_32 ;
T_1 V_33 = 0 ;
while ( ( V_49 = F_20 ( V_8 ) ) != NULL ) {
int V_34 ;
struct V_1 V_35 ;
V_32 = 0 ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
F_2 ( L_5 , V_49 -> V_14 ) ;
V_35 . V_11 . V_12 = V_51 ;
V_35 . V_11 . V_14 = V_49 -> V_14 ;
V_35 . V_11 . V_10 = V_8 -> V_10 ;
V_35 . V_11 . V_18 = 0 ;
V_35 . V_20 . V_52 . V_14 = V_49 -> V_53 ;
F_13 ( & V_35 , 1 ) ;
V_31 [ 0 ] . V_38 = & V_35 ;
V_31 [ 0 ] . V_39 = sizeof( V_35 ) ;
V_32 += sizeof( V_35 ) ;
V_34 = F_17 ( V_8 -> V_44 . V_46 , & V_29 , V_31 , 1 , V_32 ) ;
if ( V_34 != V_32 ) {
F_18 ( L_3 , V_34 ,
V_32 ) ;
F_16 ( & V_8 -> V_44 , V_47 ) ;
return - 1 ;
}
F_2 ( L_4 ) ;
V_33 += V_32 ;
}
return V_33 ;
}
int F_22 ( void * V_54 )
{
struct V_55 * V_44 = V_54 ;
struct V_7 * V_8 = F_23 ( V_44 , struct V_7 , V_44 ) ;
while ( ! F_24 () ) {
if ( F_12 ( V_8 ) < 0 )
break;
if ( F_21 ( V_8 ) < 0 )
break;
F_25 ( V_8 -> V_56 ,
( ! F_26 ( & V_8 -> V_57 ) ||
! F_26 ( & V_8 -> V_58 ) ||
F_24 () ) ) ;
F_2 ( L_6 ) ;
}
return 0 ;
}
