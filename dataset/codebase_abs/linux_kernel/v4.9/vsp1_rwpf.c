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
int V_28 = 0 ;
F_9 ( & V_3 -> V_6 . V_29 ) ;
V_5 = F_10 ( & V_3 -> V_6 , V_10 , V_25 -> V_30 ) ;
if ( ! V_5 ) {
V_28 = - V_17 ;
goto V_31;
}
if ( V_25 -> V_27 . V_12 != V_14 &&
V_25 -> V_27 . V_12 != V_15 )
V_25 -> V_27 . V_12 = V_15 ;
V_27 = F_11 ( & V_3 -> V_6 , V_5 , V_25 -> V_32 ) ;
if ( V_25 -> V_32 == V_33 ) {
V_27 -> V_12 = V_25 -> V_27 . V_12 ;
V_25 -> V_27 = * V_27 ;
goto V_31;
}
V_27 -> V_12 = V_25 -> V_27 . V_12 ;
V_27 -> V_34 = F_12 (unsigned int, fmt->format.width,
RWPF_MIN_WIDTH, rwpf->max_width) ;
V_27 -> V_35 = F_12 (unsigned int, fmt->format.height,
RWPF_MIN_HEIGHT, rwpf->max_height) ;
V_27 -> V_36 = V_37 ;
V_27 -> V_38 = V_39 ;
V_25 -> V_27 = * V_27 ;
if ( V_3 -> V_6 . type == V_40 ) {
struct V_1 * V_41 ;
V_41 = F_1 ( V_3 , V_5 ) ;
V_41 -> V_42 = 0 ;
V_41 -> V_43 = 0 ;
V_41 -> V_34 = V_25 -> V_27 . V_34 ;
V_41 -> V_35 = V_25 -> V_27 . V_35 ;
}
V_27 = F_11 ( & V_3 -> V_6 , V_5 ,
V_33 ) ;
* V_27 = V_25 -> V_27 ;
V_31:
F_13 ( & V_3 -> V_6 . V_29 ) ;
return V_28 ;
}
static int F_14 ( struct V_9 * V_7 ,
struct V_4 * V_10 ,
struct V_44 * V_45 )
{
struct V_2 * V_3 = F_6 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_26 * V_27 ;
int V_28 = 0 ;
if ( V_3 -> V_6 . type == V_46 || V_45 -> V_32 != V_8 )
return - V_17 ;
F_9 ( & V_3 -> V_6 . V_29 ) ;
V_5 = F_10 ( & V_3 -> V_6 , V_10 , V_45 -> V_30 ) ;
if ( ! V_5 ) {
V_28 = - V_17 ;
goto V_31;
}
switch ( V_45 -> V_47 ) {
case V_48 :
V_45 -> V_49 = * F_1 ( V_3 , V_5 ) ;
break;
case V_50 :
V_27 = F_11 ( & V_3 -> V_6 , V_5 ,
V_8 ) ;
V_45 -> V_49 . V_42 = 0 ;
V_45 -> V_49 . V_43 = 0 ;
V_45 -> V_49 . V_34 = V_27 -> V_34 ;
V_45 -> V_49 . V_35 = V_27 -> V_35 ;
break;
default:
V_28 = - V_17 ;
break;
}
V_31:
F_13 ( & V_3 -> V_6 . V_29 ) ;
return V_28 ;
}
static int F_15 ( struct V_9 * V_7 ,
struct V_4 * V_10 ,
struct V_44 * V_45 )
{
struct V_2 * V_3 = F_6 ( V_7 ) ;
struct V_4 * V_5 ;
struct V_26 * V_27 ;
struct V_1 * V_41 ;
int V_28 = 0 ;
if ( V_3 -> V_6 . type == V_46 || V_45 -> V_32 != V_8 )
return - V_17 ;
if ( V_45 -> V_47 != V_48 )
return - V_17 ;
F_9 ( & V_3 -> V_6 . V_29 ) ;
V_5 = F_10 ( & V_3 -> V_6 , V_10 , V_45 -> V_30 ) ;
if ( ! V_5 ) {
V_28 = - V_17 ;
goto V_31;
}
V_27 = F_11 ( & V_3 -> V_6 , V_5 ,
V_8 ) ;
if ( V_27 -> V_12 == V_15 ) {
V_45 -> V_49 . V_42 = F_16 ( V_45 -> V_49 . V_42 , 2 ) ;
V_45 -> V_49 . V_43 = F_16 ( V_45 -> V_49 . V_43 , 2 ) ;
V_45 -> V_49 . V_34 = F_17 ( V_45 -> V_49 . V_34 , 2 ) ;
V_45 -> V_49 . V_35 = F_17 ( V_45 -> V_49 . V_35 , 2 ) ;
}
V_45 -> V_49 . V_42 = F_18 (unsigned int, sel->r.left, format->width - 2 ) ;
V_45 -> V_49 . V_43 = F_18 (unsigned int, sel->r.top, format->height - 2 ) ;
V_45 -> V_49 . V_34 = F_18 (unsigned int, sel->r.width,
format->width - sel->r.left) ;
V_45 -> V_49 . V_35 = F_18 (unsigned int, sel->r.height,
format->height - sel->r.top) ;
V_41 = F_1 ( V_3 , V_5 ) ;
* V_41 = V_45 -> V_49 ;
V_27 = F_11 ( & V_3 -> V_6 , V_5 ,
V_33 ) ;
V_27 -> V_34 = V_41 -> V_34 ;
V_27 -> V_35 = V_41 -> V_35 ;
V_31:
F_13 ( & V_3 -> V_6 . V_29 ) ;
return V_28 ;
}
static int F_19 ( struct V_51 * V_52 )
{
struct V_2 * V_3 =
F_20 ( V_52 -> V_53 , struct V_2 , V_54 ) ;
switch ( V_52 -> V_55 ) {
case V_56 :
V_3 -> V_57 = V_52 -> V_58 ;
break;
}
return 0 ;
}
int F_21 ( struct V_2 * V_3 , unsigned int V_59 )
{
F_22 ( & V_3 -> V_54 , V_59 + 1 ) ;
F_23 ( & V_3 -> V_54 , & V_60 ,
V_56 , 0 , 255 , 1 , 255 ) ;
V_3 -> V_6 . V_7 . V_61 = & V_3 -> V_54 ;
return V_3 -> V_54 . error ;
}
