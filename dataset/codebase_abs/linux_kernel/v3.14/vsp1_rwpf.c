int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
static const unsigned int V_7 [] = {
V_8 ,
V_9 ,
} ;
if ( V_6 -> V_10 >= F_2 ( V_7 ) )
return - V_11 ;
V_6 -> V_6 = V_7 [ V_6 -> V_10 ] ;
return 0 ;
}
int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_16 * V_17 ;
V_17 = F_5 ( V_4 , V_13 -> V_18 ) ;
if ( V_13 -> V_10 || V_13 -> V_6 != V_17 -> V_6 )
return - V_11 ;
if ( V_13 -> V_18 == V_19 ) {
V_13 -> V_20 = V_21 ;
V_13 -> V_22 = V_15 -> V_22 ;
V_13 -> V_23 = V_24 ;
V_13 -> V_25 = V_15 -> V_25 ;
} else {
V_13 -> V_20 = V_17 -> V_26 ;
V_13 -> V_22 = V_17 -> V_26 ;
V_13 -> V_23 = V_17 -> V_27 ;
V_13 -> V_25 = V_17 -> V_27 ;
}
return 0 ;
}
static struct V_28 *
F_6 ( struct V_14 * V_15 , struct V_3 * V_4 , T_1 V_29 )
{
switch ( V_29 ) {
case V_30 :
return F_7 ( V_4 , V_19 ) ;
case V_31 :
return & V_15 -> V_32 ;
default:
return NULL ;
}
}
int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_33 * V_34 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
V_34 -> V_17 = * F_9 ( & V_15 -> V_35 , V_4 , V_34 -> V_18 ,
V_34 -> V_29 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_33 * V_34 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_16 * V_17 ;
struct V_28 * V_32 ;
if ( V_34 -> V_17 . V_6 != V_8 &&
V_34 -> V_17 . V_6 != V_9 )
V_34 -> V_17 . V_6 = V_9 ;
V_17 = F_9 ( & V_15 -> V_35 , V_4 , V_34 -> V_18 ,
V_34 -> V_29 ) ;
if ( V_34 -> V_18 == V_36 ) {
V_17 -> V_6 = V_34 -> V_17 . V_6 ;
V_34 -> V_17 = * V_17 ;
return 0 ;
}
V_17 -> V_6 = V_34 -> V_17 . V_6 ;
V_17 -> V_26 = F_11 (unsigned int, fmt->format.width,
RWPF_MIN_WIDTH, rwpf->max_width) ;
V_17 -> V_27 = F_11 (unsigned int, fmt->format.height,
RWPF_MIN_HEIGHT, rwpf->max_height) ;
V_17 -> V_37 = V_38 ;
V_17 -> V_39 = V_40 ;
V_34 -> V_17 = * V_17 ;
V_32 = F_6 ( V_15 , V_4 , V_34 -> V_29 ) ;
V_32 -> V_41 = 0 ;
V_32 -> V_42 = 0 ;
V_32 -> V_26 = V_34 -> V_17 . V_26 ;
V_32 -> V_27 = V_34 -> V_17 . V_27 ;
V_17 = F_9 ( & V_15 -> V_35 , V_4 , V_36 ,
V_34 -> V_29 ) ;
* V_17 = V_34 -> V_17 ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_43 * V_44 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_16 * V_17 ;
if ( V_44 -> V_18 != V_19 )
return - V_11 ;
switch ( V_44 -> V_45 ) {
case V_46 :
V_44 -> V_47 = * F_6 ( V_15 , V_4 , V_44 -> V_29 ) ;
break;
case V_48 :
V_17 = F_9 ( & V_15 -> V_35 , V_4 ,
V_19 , V_44 -> V_29 ) ;
V_44 -> V_47 . V_41 = 0 ;
V_44 -> V_47 . V_42 = 0 ;
V_44 -> V_47 . V_26 = V_17 -> V_26 ;
V_44 -> V_47 . V_27 = V_17 -> V_27 ;
break;
default:
return - V_11 ;
}
return 0 ;
}
int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_43 * V_44 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_16 * V_17 ;
struct V_28 * V_32 ;
if ( V_44 -> V_18 != V_19 )
return - V_11 ;
if ( V_44 -> V_45 != V_46 )
return - V_11 ;
V_17 = F_9 ( & V_15 -> V_35 , V_4 , V_19 ,
V_44 -> V_29 ) ;
V_44 -> V_47 . V_41 = F_14 (unsigned int, sel->r.left, format->width - 2 ) ;
V_44 -> V_47 . V_42 = F_14 (unsigned int, sel->r.top, format->height - 2 ) ;
if ( V_15 -> V_35 . type == V_49 ) {
V_44 -> V_47 . V_41 = F_14 (unsigned int, sel->r.left, 255 ) ;
V_44 -> V_47 . V_42 = F_14 (unsigned int, sel->r.top, 255 ) ;
}
V_44 -> V_47 . V_26 = F_14 (unsigned int, sel->r.width,
format->width - sel->r.left) ;
V_44 -> V_47 . V_27 = F_14 (unsigned int, sel->r.height,
format->height - sel->r.top) ;
V_32 = F_6 ( V_15 , V_4 , V_44 -> V_29 ) ;
* V_32 = V_44 -> V_47 ;
V_17 = F_9 ( & V_15 -> V_35 , V_4 , V_36 ,
V_44 -> V_29 ) ;
V_17 -> V_26 = V_32 -> V_26 ;
V_17 -> V_27 = V_32 -> V_27 ;
return 0 ;
}
