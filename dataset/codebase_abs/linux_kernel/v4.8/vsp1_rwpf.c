struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
return F_2 ( & V_3 -> V_6 . V_7 , V_5 ,
V_8 ) ;
}
static int F_3 ( struct V_9 * V_7 ,
struct V_4 * V_10 ,
struct V_11 * V_12 )
{
static const unsigned int V_13 [] = {
V_14 ,
V_15 ,
} ;
if ( V_12 -> V_16 >= F_4 ( V_13 ) )
return - V_17 ;
V_12 -> V_12 = V_13 [ V_12 -> V_16 ] ;
return 0 ;
}
static int F_5 ( struct V_9 * V_7 ,
struct V_4 * V_10 ,
struct V_18 * V_19 )
{
struct V_2 * V_3 = F_6 ( V_7 ) ;
return F_7 ( V_7 , V_10 , V_19 , V_20 ,
V_21 , V_3 -> V_22 ,
V_3 -> V_23 ) ;
}
static int F_8 ( struct V_9 * V_7 ,
struct V_4 * V_10 ,
struct V_24 * V_25 )
{
struct V_2 * V_3 = F_6 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_26 * V_27 ;
struct V_1 * V_28 ;
V_5 = F_9 ( & V_3 -> V_6 , V_10 , V_25 -> V_29 ) ;
if ( ! V_5 )
return - V_17 ;
if ( V_25 -> V_27 . V_12 != V_14 &&
V_25 -> V_27 . V_12 != V_15 )
V_25 -> V_27 . V_12 = V_15 ;
V_27 = F_10 ( & V_3 -> V_6 , V_5 , V_25 -> V_30 ) ;
if ( V_25 -> V_30 == V_31 ) {
V_27 -> V_12 = V_25 -> V_27 . V_12 ;
V_25 -> V_27 = * V_27 ;
return 0 ;
}
V_27 -> V_12 = V_25 -> V_27 . V_12 ;
V_27 -> V_32 = F_11 (unsigned int, fmt->format.width,
RWPF_MIN_WIDTH, rwpf->max_width) ;
V_27 -> V_33 = F_11 (unsigned int, fmt->format.height,
RWPF_MIN_HEIGHT, rwpf->max_height) ;
V_27 -> V_34 = V_35 ;
V_27 -> V_36 = V_37 ;
V_25 -> V_27 = * V_27 ;
V_28 = F_1 ( V_3 , V_5 ) ;
V_28 -> V_38 = 0 ;
V_28 -> V_39 = 0 ;
V_28 -> V_32 = V_25 -> V_27 . V_32 ;
V_28 -> V_33 = V_25 -> V_27 . V_33 ;
V_27 = F_10 ( & V_3 -> V_6 , V_5 ,
V_31 ) ;
* V_27 = V_25 -> V_27 ;
return 0 ;
}
static int F_12 ( struct V_9 * V_7 ,
struct V_4 * V_10 ,
struct V_40 * V_41 )
{
struct V_2 * V_3 = F_6 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_26 * V_27 ;
if ( V_41 -> V_30 != V_8 )
return - V_17 ;
V_5 = F_9 ( & V_3 -> V_6 , V_10 , V_41 -> V_29 ) ;
if ( ! V_5 )
return - V_17 ;
switch ( V_41 -> V_42 ) {
case V_43 :
V_41 -> V_44 = * F_1 ( V_3 , V_5 ) ;
break;
case V_45 :
V_27 = F_10 ( & V_3 -> V_6 , V_5 ,
V_8 ) ;
V_41 -> V_44 . V_38 = 0 ;
V_41 -> V_44 . V_39 = 0 ;
V_41 -> V_44 . V_32 = V_27 -> V_32 ;
V_41 -> V_44 . V_33 = V_27 -> V_33 ;
break;
default:
return - V_17 ;
}
return 0 ;
}
static int F_13 ( struct V_9 * V_7 ,
struct V_4 * V_10 ,
struct V_40 * V_41 )
{
struct V_2 * V_3 = F_6 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_26 * V_27 ;
struct V_1 * V_28 ;
if ( V_41 -> V_30 != V_8 )
return - V_17 ;
if ( V_41 -> V_42 != V_43 )
return - V_17 ;
V_5 = F_9 ( & V_3 -> V_6 , V_10 , V_41 -> V_29 ) ;
if ( ! V_5 )
return - V_17 ;
V_27 = F_10 ( & V_3 -> V_6 , V_5 ,
V_8 ) ;
if ( V_27 -> V_12 == V_15 ) {
V_41 -> V_44 . V_38 = F_14 ( V_41 -> V_44 . V_38 , 2 ) ;
V_41 -> V_44 . V_39 = F_14 ( V_41 -> V_44 . V_39 , 2 ) ;
V_41 -> V_44 . V_32 = F_15 ( V_41 -> V_44 . V_32 , 2 ) ;
V_41 -> V_44 . V_33 = F_15 ( V_41 -> V_44 . V_33 , 2 ) ;
}
V_41 -> V_44 . V_38 = F_16 (unsigned int, sel->r.left, format->width - 2 ) ;
V_41 -> V_44 . V_39 = F_16 (unsigned int, sel->r.top, format->height - 2 ) ;
if ( V_3 -> V_6 . type == V_46 ) {
V_41 -> V_44 . V_38 = F_16 (unsigned int, sel->r.left, 255 ) ;
V_41 -> V_44 . V_39 = F_16 (unsigned int, sel->r.top, 255 ) ;
}
V_41 -> V_44 . V_32 = F_16 (unsigned int, sel->r.width,
format->width - sel->r.left) ;
V_41 -> V_44 . V_33 = F_16 (unsigned int, sel->r.height,
format->height - sel->r.top) ;
V_28 = F_1 ( V_3 , V_5 ) ;
* V_28 = V_41 -> V_44 ;
V_27 = F_10 ( & V_3 -> V_6 , V_5 ,
V_31 ) ;
V_27 -> V_32 = V_28 -> V_32 ;
V_27 -> V_33 = V_28 -> V_33 ;
return 0 ;
}
static int F_17 ( struct V_47 * V_48 )
{
struct V_2 * V_3 =
F_18 ( V_48 -> V_49 , struct V_2 , V_50 ) ;
switch ( V_48 -> V_51 ) {
case V_52 :
V_3 -> V_53 = V_48 -> V_54 ;
break;
}
return 0 ;
}
int F_19 ( struct V_2 * V_3 , unsigned int V_55 )
{
F_20 ( & V_3 -> V_50 , V_55 + 1 ) ;
F_21 ( & V_3 -> V_50 , & V_56 ,
V_52 , 0 , 255 , 1 , 255 ) ;
V_3 -> V_6 . V_7 . V_57 = & V_3 -> V_50 ;
return V_3 -> V_50 . error ;
}
