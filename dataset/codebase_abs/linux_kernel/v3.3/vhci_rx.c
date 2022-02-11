struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 , * V_7 ;
struct V_1 * V_1 = NULL ;
int V_8 ;
F_2 (priv, tmp, &vdev->priv_rx, list) {
if ( V_6 -> V_4 == V_4 ) {
V_1 = V_6 -> V_1 ;
V_8 = V_1 -> V_8 ;
F_3 ( L_1 ,
V_1 , V_6 , V_4 ) ;
if ( V_8 != - V_9 ) {
if ( V_8 == - V_10 ||
V_8 == - V_11 )
F_4 ( & V_1 -> V_12 -> V_12 ,
L_2
L_3 , V_1 ,
V_8 == - V_10 ? L_4 : L_5 ) ;
else
F_4 ( & V_1 -> V_12 -> V_12 ,
L_6
L_7 , V_1 , V_8 ) ;
}
F_5 ( & V_6 -> V_13 ) ;
F_6 ( V_6 ) ;
V_1 -> V_14 = NULL ;
break;
}
}
return V_1 ;
}
static void F_7 ( struct V_2 * V_3 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = & V_3 -> V_18 ;
struct V_1 * V_1 ;
unsigned long V_19 ;
F_8 ( & V_3 -> V_20 ) ;
V_1 = F_1 ( V_3 , V_16 -> V_21 . V_4 ) ;
F_9 ( & V_3 -> V_20 ) ;
if ( ! V_1 ) {
F_10 ( L_8 , V_16 -> V_21 . V_4 ) ;
F_11 ( L_9 ,
F_12 ( & V_22 -> V_4 ) ) ;
F_13 ( V_18 , V_23 ) ;
return;
}
F_14 ( V_16 , V_1 , V_24 , 0 ) ;
if ( F_15 ( V_18 , V_1 ) < 0 )
return;
if ( F_16 ( V_18 , V_1 ) < 0 )
return;
if ( F_17 ( V_18 , V_1 ) < 0 )
return;
if ( V_25 )
F_18 ( V_1 ) ;
F_3 ( L_10 , V_1 ) ;
F_19 ( & V_22 -> V_26 , V_19 ) ;
F_20 ( F_21 ( V_22 ) , V_1 ) ;
F_22 ( & V_22 -> V_26 , V_19 ) ;
F_23 ( F_21 ( V_22 ) , V_1 , V_1 -> V_8 ) ;
F_3 ( L_11 ) ;
return;
}
static struct V_27 * F_24 ( struct V_2 * V_3 ,
struct V_15 * V_16 )
{
struct V_27 * V_28 , * V_7 ;
F_8 ( & V_3 -> V_20 ) ;
F_2 (unlink, tmp, &vdev->unlink_rx, list) {
F_11 ( L_12 , V_28 -> V_4 ) ;
if ( V_28 -> V_4 == V_16 -> V_21 . V_4 ) {
F_3 ( L_13 ,
V_28 -> V_4 ) ;
F_5 ( & V_28 -> V_13 ) ;
F_9 ( & V_3 -> V_20 ) ;
return V_28 ;
}
}
F_9 ( & V_3 -> V_20 ) ;
return NULL ;
}
static void F_25 ( struct V_2 * V_3 ,
struct V_15 * V_16 )
{
struct V_27 * V_28 ;
struct V_1 * V_1 ;
unsigned long V_19 ;
F_26 ( V_16 ) ;
V_28 = F_24 ( V_3 , V_16 ) ;
if ( ! V_28 ) {
F_11 ( L_14 ,
V_16 -> V_21 . V_4 ) ;
return;
}
F_8 ( & V_3 -> V_20 ) ;
V_1 = F_1 ( V_3 , V_28 -> V_29 ) ;
F_9 ( & V_3 -> V_20 ) ;
if ( ! V_1 ) {
F_11 ( L_15 ,
V_16 -> V_21 . V_4 ) ;
} else {
F_3 ( L_10 , V_1 ) ;
V_1 -> V_8 = V_16 -> V_30 . V_31 . V_8 ;
F_11 ( L_16 , V_1 -> V_8 ) ;
F_19 ( & V_22 -> V_26 , V_19 ) ;
F_20 ( F_21 ( V_22 ) , V_1 ) ;
F_22 ( & V_22 -> V_26 , V_19 ) ;
F_23 ( F_21 ( V_22 ) , V_1 ,
V_1 -> V_8 ) ;
}
F_6 ( V_28 ) ;
}
static int F_27 ( struct V_2 * V_3 )
{
int V_32 = 0 ;
F_8 ( & V_3 -> V_20 ) ;
V_32 = F_28 ( & V_3 -> V_33 ) ;
F_9 ( & V_3 -> V_20 ) ;
return V_32 ;
}
static void F_29 ( struct V_17 * V_18 )
{
int V_34 ;
struct V_15 V_16 ;
struct V_2 * V_3 = F_30 ( V_18 , struct V_2 , V_18 ) ;
F_3 ( L_17 ) ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_34 = F_31 ( V_18 -> V_35 , & V_16 , sizeof( V_16 ) ) ;
if ( V_34 < 0 ) {
if ( V_34 == - V_11 )
F_11 ( L_18 ) ;
else if ( V_34 == - V_36 ) {
if ( F_27 ( V_3 ) )
return;
F_11 ( L_19 ) ;
} else if ( V_34 != - V_37 )
F_11 ( L_20 , V_34 ) ;
F_13 ( V_18 , V_23 ) ;
return;
}
if ( V_34 == 0 ) {
F_11 ( L_21 ) ;
F_13 ( V_18 , V_38 ) ;
return;
}
if ( V_34 != sizeof( V_16 ) ) {
F_10 ( L_22 , V_34 ,
( unsigned int ) sizeof( V_16 ) ) ;
F_13 ( V_18 , V_23 ) ;
return;
}
F_32 ( & V_16 , 0 ) ;
if ( V_25 )
F_26 ( & V_16 ) ;
switch ( V_16 . V_21 . V_39 ) {
case V_24 :
F_7 ( V_3 , & V_16 ) ;
break;
case V_40 :
F_25 ( V_3 , & V_16 ) ;
break;
default:
F_10 ( L_23 , V_16 . V_21 . V_39 ) ;
F_26 ( & V_16 ) ;
F_13 ( V_18 , V_23 ) ;
break;
}
}
int F_33 ( void * V_41 )
{
struct V_17 * V_18 = V_41 ;
while ( ! F_34 () ) {
if ( F_35 ( V_18 ) )
break;
F_29 ( V_18 ) ;
}
return 0 ;
}
