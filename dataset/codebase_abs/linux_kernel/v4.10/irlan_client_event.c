void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
F_2 (self != NULL, return;) ;
F_2 (self->magic == IRLAN_MAGIC, return;) ;
(* F_3 [ V_2 -> V_6 . F_3 ]) ( V_2 , V_3 , V_5 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
F_2 (self != NULL, return -1;) ;
F_2 (self->magic == IRLAN_MAGIC, return -1;) ;
switch ( V_3 ) {
case V_7 :
if ( V_2 -> V_6 . V_8 ) {
F_5 ( L_1 ,
V_9 ) ;
return - V_10 ;
}
V_2 -> V_6 . V_8 = F_6 ( V_11 , V_12 , V_2 ,
V_13 ) ;
F_7 ( V_2 , V_14 ) ;
F_8 ( V_2 -> V_6 . V_8 ,
V_2 -> V_15 , V_2 -> V_16 ,
L_2 , L_3 ) ;
break;
case V_17 :
F_9 ( L_4 , V_9 ) ;
break;
default:
F_9 ( L_5 , V_9 , V_3 ) ;
break;
}
if ( V_5 )
F_10 ( V_5 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
F_2 (self != NULL, return -1;) ;
F_2 (self->magic == IRLAN_MAGIC, return -1;) ;
switch( V_3 ) {
case V_18 :
F_2 (self->dtsap_sel_ctrl != 0 , return -1;) ;
V_2 -> V_6 . V_19 = 0 ;
F_12 ( V_2 -> V_6 . V_20 ,
V_2 -> V_21 ,
V_2 -> V_15 , V_2 -> V_16 , NULL ,
V_22 , NULL ) ;
F_7 ( V_2 , V_23 ) ;
break;
case V_24 :
F_9 ( L_6 , V_9 ) ;
F_7 ( V_2 , V_25 ) ;
if ( ( V_2 -> V_26 . V_27 == V_28 ) &&
( V_2 -> V_26 . F_3 != V_25 ) )
F_13 ( V_2 , V_2 -> V_15 , V_2 -> V_16 ) ;
break;
case V_29 :
case V_30 :
F_7 ( V_2 , V_25 ) ;
break;
case V_17 :
F_9 ( L_4 , V_9 ) ;
break;
default:
F_9 ( L_5 , V_9 , V_3 ) ;
break;
}
if ( V_5 )
F_10 ( V_5 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
F_2 (self != NULL, return -1;) ;
switch ( V_3 ) {
case V_31 :
F_15 ( V_2 ) ;
F_7 ( V_2 , V_32 ) ;
break;
case V_29 :
case V_30 :
F_7 ( V_2 , V_25 ) ;
break;
case V_17 :
F_9 ( L_4 , V_9 ) ;
break;
default:
F_9 ( L_5 , V_9 , V_3 ) ;
break;
}
if ( V_5 )
F_10 ( V_5 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
F_2 (self != NULL, return -1;) ;
switch ( V_3 ) {
case V_33 :
F_2 (skb != NULL, return -1;) ;
F_17 ( V_2 , V_5 ) ;
F_7 ( V_2 , V_34 ) ;
F_18 ( V_2 ) ;
break;
case V_29 :
case V_30 :
F_7 ( V_2 , V_25 ) ;
break;
case V_17 :
F_9 ( L_4 , V_9 ) ;
break;
default:
F_9 ( L_5 , V_9 , V_3 ) ;
break;
}
if ( V_5 )
F_10 ( V_5 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
F_2 (self != NULL, return -1;) ;
switch( V_3 ) {
case V_33 :
F_17 ( V_2 , V_5 ) ;
F_20 ( V_2 ) ;
F_7 ( V_2 , V_35 ) ;
break;
case V_29 :
case V_30 :
F_7 ( V_2 , V_25 ) ;
break;
case V_17 :
F_9 ( L_4 , V_9 ) ;
break;
default:
F_9 ( L_5 , V_9 , V_3 ) ;
break;
}
if ( V_5 )
F_10 ( V_5 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
struct V_36 V_37 ;
F_2 (self != NULL, return -1;) ;
switch( V_3 ) {
case V_33 :
F_17 ( V_2 , V_5 ) ;
F_2 (self->dtsap_sel_data != 0 , return -1;) ;
switch ( V_2 -> V_6 . V_27 ) {
case V_28 :
if ( V_2 -> V_26 . F_3 == V_35 ) {
F_7 ( V_2 , V_38 ) ;
F_1 ( V_2 , V_39 ,
NULL ) ;
} else {
F_7 ( V_2 , V_40 ) ;
}
break;
case V_41 :
case V_42 :
V_37 . V_43 . V_44 = 0x01 ;
F_12 ( V_2 -> V_45 ,
V_2 -> V_46 ,
V_2 -> V_15 , V_2 -> V_16 , & V_37 ,
V_22 , NULL ) ;
F_7 ( V_2 , V_47 ) ;
break;
default:
F_9 ( L_7 , V_9 ) ;
break;
}
break;
case V_29 :
case V_30 :
F_7 ( V_2 , V_25 ) ;
break;
case V_17 :
F_9 ( L_4 , V_9 ) ;
break;
default:
F_9 ( L_5 , V_9 , V_3 ) ;
break;
}
if ( V_5 )
F_10 ( V_5 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
F_2 (self != NULL, return -1;) ;
switch( V_3 ) {
case V_48 :
F_7 ( V_2 , V_38 ) ;
F_1 ( V_2 , V_39 , NULL ) ;
break;
case V_29 :
case V_30 :
F_7 ( V_2 , V_25 ) ;
break;
case V_17 :
F_9 ( L_4 , V_9 ) ;
break;
default:
F_9 ( L_5 , V_9 , V_3 ) ;
break;
}
if ( V_5 )
F_10 ( V_5 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
struct V_36 V_37 ;
F_2 (self != NULL, return -1;) ;
switch( V_3 ) {
case V_39 :
if ( V_2 -> V_6 . V_49 == V_2 -> V_26 . V_50 ) {
F_7 ( V_2 , V_51 ) ;
F_24 ( V_2 ) ;
} else if ( V_2 -> V_6 . V_49 <
V_2 -> V_26 . V_50 )
{
V_37 . V_43 . V_44 = 0x01 ;
F_7 ( V_2 , V_47 ) ;
F_12 ( V_2 -> V_45 ,
V_2 -> V_46 ,
V_2 -> V_15 , V_2 -> V_16 , & V_37 ,
V_22 , NULL ) ;
} else if ( V_2 -> V_6 . V_49 >
V_2 -> V_26 . V_50 )
{
F_9 ( L_8 , V_9 ) ;
}
break;
case V_52 :
F_7 ( V_2 , V_47 ) ;
break;
case V_29 :
case V_30 :
F_7 ( V_2 , V_25 ) ;
break;
case V_17 :
F_9 ( L_4 , V_9 ) ;
break;
default:
F_9 ( L_5 , V_9 , V_3 ) ;
break;
}
if ( V_5 )
F_10 ( V_5 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
F_2 (self != NULL, return -1;) ;
F_2 (self->magic == IRLAN_MAGIC, return -1;) ;
switch( V_3 ) {
case V_33 :
F_17 ( V_2 , V_5 ) ;
break;
case V_29 :
case V_30 :
F_7 ( V_2 , V_25 ) ;
break;
default:
F_9 ( L_5 , V_9 , V_3 ) ;
break;
}
if ( V_5 )
F_10 ( V_5 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
if ( V_5 )
F_10 ( V_5 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
if ( V_5 )
F_10 ( V_5 ) ;
return 0 ;
}
