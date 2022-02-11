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
int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_28 * V_29 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
V_29 -> V_17 = * F_7 ( & V_15 -> V_30 , V_4 , V_29 -> V_18 ,
V_29 -> V_31 ) ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_28 * V_29 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_16 * V_17 ;
if ( V_29 -> V_17 . V_6 != V_8 &&
V_29 -> V_17 . V_6 != V_9 )
V_29 -> V_17 . V_6 = V_9 ;
V_17 = F_7 ( & V_15 -> V_30 , V_4 , V_29 -> V_18 ,
V_29 -> V_31 ) ;
if ( V_29 -> V_18 == V_32 ) {
V_17 -> V_6 = V_29 -> V_17 . V_6 ;
V_29 -> V_17 = * V_17 ;
return 0 ;
}
V_17 -> V_6 = V_29 -> V_17 . V_6 ;
V_17 -> V_26 = F_9 (unsigned int, fmt->format.width,
RWPF_MIN_WIDTH, rwpf->max_width) ;
V_17 -> V_27 = F_9 (unsigned int, fmt->format.height,
RWPF_MIN_HEIGHT, rwpf->max_height) ;
V_17 -> V_33 = V_34 ;
V_17 -> V_35 = V_36 ;
V_29 -> V_17 = * V_17 ;
V_17 = F_7 ( & V_15 -> V_30 , V_4 , V_32 ,
V_29 -> V_31 ) ;
* V_17 = V_29 -> V_17 ;
return 0 ;
}
