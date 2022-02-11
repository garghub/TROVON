struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 , * V_7 ;
struct V_1 * V_1 = NULL ;
int V_8 ;
F_2 (priv, tmp, &vdev->priv_rx, list) {
if ( V_6 -> V_4 != V_4 )
continue;
V_1 = V_6 -> V_1 ;
V_8 = V_1 -> V_8 ;
F_3 ( L_1 ,
V_1 , V_6 , V_4 ) ;
switch ( V_8 ) {
case - V_9 :
case - V_10 :
F_4 ( & V_1 -> V_11 -> V_11 ,
L_2 , V_1 ,
V_8 == - V_9 ? L_3 : L_4 ) ;
break;
case - V_12 :
break;
default:
F_4 ( & V_1 -> V_11 -> V_11 ,
L_5 , V_1 ,
V_8 ) ;
}
F_5 ( & V_6 -> V_13 ) ;
F_6 ( V_6 ) ;
V_1 -> V_14 = NULL ;
break;
}
return V_1 ;
}
static void F_7 ( struct V_2 * V_3 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = & V_3 -> V_18 ;
struct V_1 * V_1 ;
F_8 ( & V_3 -> V_19 ) ;
V_1 = F_1 ( V_3 , V_16 -> V_20 . V_4 ) ;
F_9 ( & V_3 -> V_19 ) ;
if ( ! V_1 ) {
F_10 ( L_6 , V_16 -> V_20 . V_4 ) ;
F_11 ( L_7 ,
F_12 ( & V_21 -> V_4 ) ) ;
F_13 ( V_18 , V_22 ) ;
return;
}
F_14 ( V_16 , V_1 , V_23 , 0 ) ;
if ( F_15 ( V_18 , V_1 ) < 0 )
return;
if ( F_16 ( V_18 , V_1 ) < 0 )
return;
F_17 ( V_18 , V_1 ) ;
if ( V_24 )
F_18 ( V_1 ) ;
F_3 ( L_8 , V_1 ) ;
F_8 ( & V_21 -> V_25 ) ;
F_19 ( F_20 ( V_21 ) , V_1 ) ;
F_9 ( & V_21 -> V_25 ) ;
F_21 ( F_20 ( V_21 ) , V_1 , V_1 -> V_8 ) ;
F_3 ( L_9 ) ;
return;
}
static struct V_26 * F_22 ( struct V_2 * V_3 ,
struct V_15 * V_16 )
{
struct V_26 * V_27 , * V_7 ;
F_8 ( & V_3 -> V_19 ) ;
F_2 (unlink, tmp, &vdev->unlink_rx, list) {
F_11 ( L_10 , V_27 -> V_4 ) ;
if ( V_27 -> V_4 == V_16 -> V_20 . V_4 ) {
F_3 ( L_11 ,
V_27 -> V_4 ) ;
F_5 ( & V_27 -> V_13 ) ;
F_9 ( & V_3 -> V_19 ) ;
return V_27 ;
}
}
F_9 ( & V_3 -> V_19 ) ;
return NULL ;
}
static void F_23 ( struct V_2 * V_3 ,
struct V_15 * V_16 )
{
struct V_26 * V_27 ;
struct V_1 * V_1 ;
F_24 ( V_16 ) ;
V_27 = F_22 ( V_3 , V_16 ) ;
if ( ! V_27 ) {
F_11 ( L_12 ,
V_16 -> V_20 . V_4 ) ;
return;
}
F_8 ( & V_3 -> V_19 ) ;
V_1 = F_1 ( V_3 , V_27 -> V_28 ) ;
F_9 ( & V_3 -> V_19 ) ;
if ( ! V_1 ) {
F_11 ( L_13 ,
V_16 -> V_20 . V_4 ) ;
} else {
F_3 ( L_8 , V_1 ) ;
V_1 -> V_8 = V_16 -> V_29 . V_30 . V_8 ;
F_11 ( L_14 , V_1 -> V_8 ) ;
F_8 ( & V_21 -> V_25 ) ;
F_19 ( F_20 ( V_21 ) , V_1 ) ;
F_9 ( & V_21 -> V_25 ) ;
F_21 ( F_20 ( V_21 ) , V_1 ,
V_1 -> V_8 ) ;
}
F_6 ( V_27 ) ;
}
static int F_25 ( struct V_2 * V_3 )
{
int V_31 = 0 ;
F_8 ( & V_3 -> V_19 ) ;
V_31 = F_26 ( & V_3 -> V_32 ) ;
F_9 ( & V_3 -> V_19 ) ;
return V_31 ;
}
static void F_27 ( struct V_17 * V_18 )
{
int V_33 ;
struct V_15 V_16 ;
struct V_2 * V_3 = F_28 ( V_18 , struct V_2 , V_18 ) ;
F_3 ( L_15 ) ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_33 = F_29 ( V_18 -> V_34 , & V_16 , sizeof( V_16 ) ) ;
if ( V_33 < 0 ) {
if ( V_33 == - V_10 )
F_11 ( L_16 ) ;
else if ( V_33 == - V_35 ) {
if ( F_25 ( V_3 ) )
return;
F_11 ( L_17 ) ;
} else if ( V_33 != - V_36 )
F_11 ( L_18 , V_33 ) ;
F_13 ( V_18 , V_22 ) ;
return;
}
if ( V_33 == 0 ) {
F_11 ( L_19 ) ;
F_13 ( V_18 , V_37 ) ;
return;
}
if ( V_33 != sizeof( V_16 ) ) {
F_10 ( L_20 , V_33 ,
( unsigned int ) sizeof( V_16 ) ) ;
F_13 ( V_18 , V_22 ) ;
return;
}
F_30 ( & V_16 , 0 ) ;
if ( V_24 )
F_24 ( & V_16 ) ;
switch ( V_16 . V_20 . V_38 ) {
case V_23 :
F_7 ( V_3 , & V_16 ) ;
break;
case V_39 :
F_23 ( V_3 , & V_16 ) ;
break;
default:
F_10 ( L_21 , V_16 . V_20 . V_38 ) ;
F_24 ( & V_16 ) ;
F_13 ( V_18 , V_22 ) ;
break;
}
}
int F_31 ( void * V_40 )
{
struct V_17 * V_18 = V_40 ;
while ( ! F_32 () ) {
if ( F_33 ( V_18 ) )
break;
F_27 ( V_18 ) ;
}
return 0 ;
}
