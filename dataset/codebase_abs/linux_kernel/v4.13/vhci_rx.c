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
struct V_17 * V_17 = F_8 ( V_3 ) ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_19 * V_20 = & V_3 -> V_20 ;
struct V_1 * V_1 ;
unsigned long V_21 ;
F_9 ( & V_3 -> V_22 , V_21 ) ;
V_1 = F_1 ( V_3 , V_16 -> V_23 . V_4 ) ;
F_10 ( & V_3 -> V_22 , V_21 ) ;
if ( ! V_1 ) {
F_11 ( L_6 , V_16 -> V_23 . V_4 ) ;
F_12 ( L_7 ,
F_13 ( & V_17 -> V_4 ) ) ;
F_14 ( V_20 , V_24 ) ;
return;
}
F_15 ( V_16 , V_1 , V_25 , 0 ) ;
if ( F_16 ( V_20 , V_1 ) < 0 )
return;
if ( F_17 ( V_20 , V_1 ) < 0 )
return;
F_18 ( V_20 , V_1 ) ;
if ( V_26 )
F_19 ( V_1 ) ;
F_3 ( L_8 , V_1 ) ;
F_9 ( & V_18 -> V_27 , V_21 ) ;
F_20 ( F_21 ( V_17 ) , V_1 ) ;
F_10 ( & V_18 -> V_27 , V_21 ) ;
F_22 ( F_21 ( V_17 ) , V_1 , V_1 -> V_8 ) ;
F_3 ( L_9 ) ;
}
static struct V_28 * F_23 ( struct V_2 * V_3 ,
struct V_15 * V_16 )
{
struct V_28 * V_29 , * V_7 ;
unsigned long V_21 ;
F_9 ( & V_3 -> V_22 , V_21 ) ;
F_2 (unlink, tmp, &vdev->unlink_rx, list) {
F_12 ( L_10 , V_29 -> V_4 ) ;
if ( V_29 -> V_4 == V_16 -> V_23 . V_4 ) {
F_3 ( L_11 ,
V_29 -> V_4 ) ;
F_5 ( & V_29 -> V_13 ) ;
F_10 ( & V_3 -> V_22 , V_21 ) ;
return V_29 ;
}
}
F_10 ( & V_3 -> V_22 , V_21 ) ;
return NULL ;
}
static void F_24 ( struct V_2 * V_3 ,
struct V_15 * V_16 )
{
struct V_17 * V_17 = F_8 ( V_3 ) ;
struct V_18 * V_18 = V_17 -> V_18 ;
struct V_28 * V_29 ;
struct V_1 * V_1 ;
unsigned long V_21 ;
F_25 ( V_16 ) ;
V_29 = F_23 ( V_3 , V_16 ) ;
if ( ! V_29 ) {
F_12 ( L_12 ,
V_16 -> V_23 . V_4 ) ;
return;
}
F_9 ( & V_3 -> V_22 , V_21 ) ;
V_1 = F_1 ( V_3 , V_29 -> V_30 ) ;
F_10 ( & V_3 -> V_22 , V_21 ) ;
if ( ! V_1 ) {
F_12 ( L_13 ,
V_16 -> V_23 . V_4 ) ;
} else {
F_3 ( L_8 , V_1 ) ;
V_1 -> V_8 = V_16 -> V_31 . V_32 . V_8 ;
F_12 ( L_14 , V_1 -> V_8 ) ;
F_9 ( & V_18 -> V_27 , V_21 ) ;
F_20 ( F_21 ( V_17 ) , V_1 ) ;
F_10 ( & V_18 -> V_27 , V_21 ) ;
F_22 ( F_21 ( V_17 ) , V_1 , V_1 -> V_8 ) ;
}
F_6 ( V_29 ) ;
}
static int F_26 ( struct V_2 * V_3 )
{
int V_33 = 0 ;
unsigned long V_21 ;
F_9 ( & V_3 -> V_22 , V_21 ) ;
V_33 = F_27 ( & V_3 -> V_34 ) ;
F_10 ( & V_3 -> V_22 , V_21 ) ;
return V_33 ;
}
static void F_28 ( struct V_19 * V_20 )
{
int V_35 ;
struct V_15 V_16 ;
struct V_2 * V_3 = F_29 ( V_20 , struct V_2 , V_20 ) ;
F_3 ( L_15 ) ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_35 = F_30 ( V_20 -> V_36 , & V_16 , sizeof( V_16 ) ) ;
if ( V_35 < 0 ) {
if ( V_35 == - V_10 )
F_12 ( L_16 ) ;
else if ( V_35 == - V_37 ) {
if ( F_26 ( V_3 ) )
return;
F_12 ( L_17 ) ;
} else if ( V_35 != - V_38 )
F_12 ( L_18 , V_35 ) ;
F_14 ( V_20 , V_24 ) ;
return;
}
if ( V_35 == 0 ) {
F_12 ( L_19 ) ;
F_14 ( V_20 , V_39 ) ;
return;
}
if ( V_35 != sizeof( V_16 ) ) {
F_11 ( L_20 , V_35 ,
( unsigned int ) sizeof( V_16 ) ) ;
F_14 ( V_20 , V_24 ) ;
return;
}
F_31 ( & V_16 , 0 ) ;
if ( V_26 )
F_25 ( & V_16 ) ;
switch ( V_16 . V_23 . V_40 ) {
case V_25 :
F_7 ( V_3 , & V_16 ) ;
break;
case V_41 :
F_24 ( V_3 , & V_16 ) ;
break;
default:
F_11 ( L_21 , V_16 . V_23 . V_40 ) ;
F_25 ( & V_16 ) ;
F_14 ( V_20 , V_24 ) ;
break;
}
}
int F_32 ( void * V_42 )
{
struct V_19 * V_20 = V_42 ;
while ( ! F_33 () ) {
if ( F_34 ( V_20 ) )
break;
F_28 ( V_20 ) ;
}
return 0 ;
}
