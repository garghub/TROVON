static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 . V_5 , V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
F_4 ( V_2 -> V_4 . V_5 , V_3 , V_6 ) ;
}
static void F_5 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
F_6 ( V_2 -> V_4 . V_5 -> V_9 + V_10 , V_8 -> V_2 ,
sizeof( V_8 -> V_2 ) ) ;
}
static long F_7 ( struct V_11 * V_12 , unsigned int V_13 , void * V_14 )
{
struct V_1 * V_2 = F_8 ( V_12 ) ;
switch ( V_13 ) {
case V_15 :
F_5 ( V_2 , V_14 ) ;
return 0 ;
default:
return - V_16 ;
}
}
static int F_9 ( struct V_11 * V_12 , int V_17 )
{
struct V_1 * V_2 = F_8 ( V_12 ) ;
if ( ! V_17 )
return 0 ;
F_3 ( V_2 , V_18 , V_19 ) ;
return 0 ;
}
static int F_10 ( struct V_11 * V_12 ,
struct V_20 * V_21 ,
struct V_22 * V_23 )
{
static const unsigned int V_24 [] = {
V_25 ,
V_26 ,
V_27 ,
} ;
struct V_28 * V_29 ;
if ( V_23 -> V_30 == V_31 ) {
if ( V_23 -> V_32 >= F_11 ( V_24 ) )
return - V_33 ;
V_23 -> V_23 = V_24 [ V_23 -> V_32 ] ;
} else {
if ( V_23 -> V_32 )
return - V_33 ;
V_29 = F_12 ( V_21 , V_31 ) ;
V_23 -> V_23 = V_29 -> V_23 ;
}
return 0 ;
}
static int F_13 ( struct V_11 * V_12 ,
struct V_20 * V_21 ,
struct V_34 * V_35 )
{
struct V_28 * V_29 ;
V_29 = F_12 ( V_21 , V_35 -> V_30 ) ;
if ( V_35 -> V_32 || V_35 -> V_23 != V_29 -> V_23 )
return - V_33 ;
if ( V_35 -> V_30 == V_31 ) {
V_35 -> V_36 = V_37 ;
V_35 -> V_38 = V_39 ;
V_35 -> V_40 = V_37 ;
V_35 -> V_41 = V_39 ;
} else {
V_35 -> V_36 = V_29 -> V_42 ;
V_35 -> V_38 = V_29 -> V_42 ;
V_35 -> V_40 = V_29 -> V_43 ;
V_35 -> V_41 = V_29 -> V_43 ;
}
return 0 ;
}
static int F_14 ( struct V_11 * V_12 , struct V_20 * V_21 ,
struct V_44 * V_45 )
{
struct V_1 * V_2 = F_8 ( V_12 ) ;
V_45 -> V_29 = * F_15 ( & V_2 -> V_4 , V_21 , V_45 -> V_30 ,
V_45 -> V_46 ) ;
return 0 ;
}
static int F_16 ( struct V_11 * V_12 , struct V_20 * V_21 ,
struct V_44 * V_45 )
{
struct V_1 * V_2 = F_8 ( V_12 ) ;
struct V_28 * V_29 ;
if ( V_45 -> V_29 . V_23 != V_25 &&
V_45 -> V_29 . V_23 != V_26 &&
V_45 -> V_29 . V_23 != V_27 )
V_45 -> V_29 . V_23 = V_27 ;
V_29 = F_15 ( & V_2 -> V_4 , V_21 , V_45 -> V_30 ,
V_45 -> V_46 ) ;
if ( V_45 -> V_30 == V_47 ) {
V_45 -> V_29 = * V_29 ;
return 0 ;
}
V_29 -> V_42 = F_17 (unsigned int, fmt->format.width,
LUT_MIN_SIZE, LUT_MAX_SIZE) ;
V_29 -> V_43 = F_17 (unsigned int, fmt->format.height,
LUT_MIN_SIZE, LUT_MAX_SIZE) ;
V_29 -> V_48 = V_49 ;
V_29 -> V_50 = V_51 ;
V_45 -> V_29 = * V_29 ;
V_29 = F_15 ( & V_2 -> V_4 , V_21 , V_47 ,
V_45 -> V_46 ) ;
* V_29 = V_45 -> V_29 ;
return 0 ;
}
struct V_1 * F_18 ( struct V_52 * V_5 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 ;
int V_53 ;
V_2 = F_19 ( V_5 -> V_54 , sizeof( * V_2 ) , V_55 ) ;
if ( V_2 == NULL )
return F_20 ( - V_56 ) ;
V_2 -> V_4 . type = V_57 ;
V_53 = F_21 ( V_5 , & V_2 -> V_4 , 2 ) ;
if ( V_53 < 0 )
return F_20 ( V_53 ) ;
V_12 = & V_2 -> V_4 . V_12 ;
F_22 ( V_12 , & V_58 ) ;
V_12 -> V_4 . V_59 = & V_60 ;
V_12 -> V_61 = & V_62 ;
snprintf ( V_12 -> V_63 , sizeof( V_12 -> V_63 ) , L_1 ,
F_23 ( V_5 -> V_54 ) ) ;
F_24 ( V_12 , V_2 ) ;
V_12 -> V_64 |= V_65 ;
F_25 ( V_12 , NULL ) ;
return V_2 ;
}
