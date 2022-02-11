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
V_16 ,
} ;
if ( V_12 -> V_17 >= F_4 ( V_13 ) )
return - V_18 ;
V_12 -> V_12 = V_13 [ V_12 -> V_17 ] ;
return 0 ;
}
static int F_5 ( struct V_9 * V_7 ,
struct V_4 * V_10 ,
struct V_19 * V_20 )
{
struct V_2 * V_3 = F_6 ( V_7 ) ;
return F_7 ( V_7 , V_10 , V_20 , V_21 ,
V_22 , V_3 -> V_23 ,
V_3 -> V_24 ) ;
}
static int F_8 ( struct V_9 * V_7 ,
struct V_4 * V_10 ,
struct V_25 * V_26 )
{
struct V_2 * V_3 = F_6 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_27 * V_28 ;
int V_29 = 0 ;
F_9 ( & V_3 -> V_6 . V_30 ) ;
V_5 = F_10 ( & V_3 -> V_6 , V_10 , V_26 -> V_31 ) ;
if ( ! V_5 ) {
V_29 = - V_18 ;
goto V_32;
}
if ( V_26 -> V_28 . V_12 != V_14 &&
V_26 -> V_28 . V_12 != V_15 &&
V_26 -> V_28 . V_12 != V_16 )
V_26 -> V_28 . V_12 = V_16 ;
V_28 = F_11 ( & V_3 -> V_6 , V_5 , V_26 -> V_33 ) ;
if ( V_26 -> V_33 == V_34 ) {
V_28 -> V_12 = V_26 -> V_28 . V_12 ;
V_26 -> V_28 = * V_28 ;
goto V_32;
}
V_28 -> V_12 = V_26 -> V_28 . V_12 ;
V_28 -> V_35 = F_12 (unsigned int, fmt->format.width,
RWPF_MIN_WIDTH, rwpf->max_width) ;
V_28 -> V_36 = F_12 (unsigned int, fmt->format.height,
RWPF_MIN_HEIGHT, rwpf->max_height) ;
V_28 -> V_37 = V_38 ;
V_28 -> V_39 = V_40 ;
V_26 -> V_28 = * V_28 ;
if ( V_3 -> V_6 . type == V_41 ) {
struct V_1 * V_42 ;
V_42 = F_1 ( V_3 , V_5 ) ;
V_42 -> V_43 = 0 ;
V_42 -> V_44 = 0 ;
V_42 -> V_35 = V_26 -> V_28 . V_35 ;
V_42 -> V_36 = V_26 -> V_28 . V_36 ;
}
V_28 = F_11 ( & V_3 -> V_6 , V_5 ,
V_34 ) ;
* V_28 = V_26 -> V_28 ;
V_32:
F_13 ( & V_3 -> V_6 . V_30 ) ;
return V_29 ;
}
static int F_14 ( struct V_9 * V_7 ,
struct V_4 * V_10 ,
struct V_45 * V_46 )
{
struct V_2 * V_3 = F_6 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_27 * V_28 ;
int V_29 = 0 ;
if ( V_3 -> V_6 . type == V_47 || V_46 -> V_33 != V_8 )
return - V_18 ;
F_9 ( & V_3 -> V_6 . V_30 ) ;
V_5 = F_10 ( & V_3 -> V_6 , V_10 , V_46 -> V_31 ) ;
if ( ! V_5 ) {
V_29 = - V_18 ;
goto V_32;
}
switch ( V_46 -> V_48 ) {
case V_49 :
V_46 -> V_50 = * F_1 ( V_3 , V_5 ) ;
break;
case V_51 :
V_28 = F_11 ( & V_3 -> V_6 , V_5 ,
V_8 ) ;
V_46 -> V_50 . V_43 = 0 ;
V_46 -> V_50 . V_44 = 0 ;
V_46 -> V_50 . V_35 = V_28 -> V_35 ;
V_46 -> V_50 . V_36 = V_28 -> V_36 ;
break;
default:
V_29 = - V_18 ;
break;
}
V_32:
F_13 ( & V_3 -> V_6 . V_30 ) ;
return V_29 ;
}
static int F_15 ( struct V_9 * V_7 ,
struct V_4 * V_10 ,
struct V_45 * V_46 )
{
struct V_2 * V_3 = F_6 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_27 * V_28 ;
struct V_1 * V_42 ;
int V_29 = 0 ;
if ( V_3 -> V_6 . type == V_47 || V_46 -> V_33 != V_8 )
return - V_18 ;
if ( V_46 -> V_48 != V_49 )
return - V_18 ;
F_9 ( & V_3 -> V_6 . V_30 ) ;
V_5 = F_10 ( & V_3 -> V_6 , V_10 , V_46 -> V_31 ) ;
if ( ! V_5 ) {
V_29 = - V_18 ;
goto V_32;
}
V_28 = F_11 ( & V_3 -> V_6 , V_5 ,
V_8 ) ;
if ( V_28 -> V_12 == V_16 ) {
V_46 -> V_50 . V_43 = F_16 ( V_46 -> V_50 . V_43 , 2 ) ;
V_46 -> V_50 . V_44 = F_16 ( V_46 -> V_50 . V_44 , 2 ) ;
V_46 -> V_50 . V_35 = F_17 ( V_46 -> V_50 . V_35 , 2 ) ;
V_46 -> V_50 . V_36 = F_17 ( V_46 -> V_50 . V_36 , 2 ) ;
}
V_46 -> V_50 . V_43 = F_18 (unsigned int, sel->r.left, format->width - 2 ) ;
V_46 -> V_50 . V_44 = F_18 (unsigned int, sel->r.top, format->height - 2 ) ;
V_46 -> V_50 . V_35 = F_18 (unsigned int, sel->r.width,
format->width - sel->r.left) ;
V_46 -> V_50 . V_36 = F_18 (unsigned int, sel->r.height,
format->height - sel->r.top) ;
V_42 = F_1 ( V_3 , V_5 ) ;
* V_42 = V_46 -> V_50 ;
V_28 = F_11 ( & V_3 -> V_6 , V_5 ,
V_34 ) ;
V_28 -> V_35 = V_42 -> V_35 ;
V_28 -> V_36 = V_42 -> V_36 ;
V_32:
F_13 ( & V_3 -> V_6 . V_30 ) ;
return V_29 ;
}
static int F_19 ( struct V_52 * V_53 )
{
struct V_2 * V_3 =
F_20 ( V_53 -> V_54 , struct V_2 , V_55 ) ;
switch ( V_53 -> V_56 ) {
case V_57 :
V_3 -> V_58 = V_53 -> V_59 ;
break;
}
return 0 ;
}
int F_21 ( struct V_2 * V_3 , unsigned int V_60 )
{
F_22 ( & V_3 -> V_55 , V_60 + 1 ) ;
F_23 ( & V_3 -> V_55 , & V_61 ,
V_57 , 0 , 255 , 1 , 255 ) ;
V_3 -> V_6 . V_7 . V_62 = & V_3 -> V_55 ;
return V_3 -> V_55 . error ;
}
