static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_2 -> V_5 . V_6 , V_3 , V_4 ) ;
}
static int F_3 ( struct V_7 * V_8 , int V_9 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
if ( ! V_9 )
return 0 ;
if ( V_2 -> V_10 )
F_1 ( V_2 , V_11 , V_12 ) ;
else
F_1 ( V_2 , V_13 , V_14 ) ;
return 0 ;
}
static int F_5 ( struct V_7 * V_8 ,
struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
if ( V_18 -> V_19 > 0 )
return - V_20 ;
if ( ( V_18 -> V_21 == V_22 && ! V_2 -> V_10 ) |
( V_18 -> V_21 == V_23 && V_2 -> V_10 ) )
V_18 -> V_18 = V_24 ;
else
V_18 -> V_18 = V_25 ;
return 0 ;
}
static int F_6 ( struct V_7 * V_8 ,
struct V_15 * V_16 ,
struct V_26 * V_27 )
{
struct V_28 * V_29 ;
V_29 = F_7 ( V_16 , V_27 -> V_21 ) ;
if ( V_27 -> V_19 || V_27 -> V_18 != V_29 -> V_18 )
return - V_20 ;
if ( V_27 -> V_21 == V_22 ) {
V_27 -> V_30 = V_31 ;
V_27 -> V_32 = V_33 ;
V_27 -> V_34 = V_31 ;
V_27 -> V_35 = V_33 ;
} else {
V_27 -> V_30 = V_29 -> V_36 ;
V_27 -> V_32 = V_29 -> V_36 ;
V_27 -> V_34 = V_29 -> V_37 ;
V_27 -> V_35 = V_29 -> V_37 ;
}
return 0 ;
}
static int F_8 ( struct V_7 * V_8 ,
struct V_15 * V_16 ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
V_39 -> V_29 = * F_9 ( & V_2 -> V_5 , V_16 , V_39 -> V_21 ,
V_39 -> V_40 ) ;
return 0 ;
}
static int F_10 ( struct V_7 * V_8 ,
struct V_15 * V_16 ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_28 * V_29 ;
V_29 = F_9 ( & V_2 -> V_5 , V_16 , V_39 -> V_21 ,
V_39 -> V_40 ) ;
if ( V_39 -> V_21 == V_23 ) {
V_39 -> V_29 = * V_29 ;
return 0 ;
}
V_29 -> V_18 = V_2 -> V_10 ? V_25
: V_24 ;
V_29 -> V_36 = F_11 (unsigned int, fmt->format.width,
HSIT_MIN_SIZE, HSIT_MAX_SIZE) ;
V_29 -> V_37 = F_11 (unsigned int, fmt->format.height,
HSIT_MIN_SIZE, HSIT_MAX_SIZE) ;
V_29 -> V_41 = V_42 ;
V_29 -> V_43 = V_44 ;
V_39 -> V_29 = * V_29 ;
V_29 = F_9 ( & V_2 -> V_5 , V_16 , V_23 ,
V_39 -> V_40 ) ;
* V_29 = V_39 -> V_29 ;
V_29 -> V_18 = V_2 -> V_10 ? V_24
: V_25 ;
return 0 ;
}
struct V_1 * F_12 ( struct V_45 * V_6 , bool V_10 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
int V_46 ;
V_2 = F_13 ( V_6 -> V_47 , sizeof( * V_2 ) , V_48 ) ;
if ( V_2 == NULL )
return F_14 ( - V_49 ) ;
V_2 -> V_10 = V_10 ;
if ( V_10 )
V_2 -> V_5 . type = V_50 ;
else
V_2 -> V_5 . type = V_51 ;
V_46 = F_15 ( V_6 , & V_2 -> V_5 , 2 ) ;
if ( V_46 < 0 )
return F_14 ( V_46 ) ;
V_8 = & V_2 -> V_5 . V_8 ;
F_16 ( V_8 , & V_52 ) ;
V_8 -> V_5 . V_53 = & V_54 ;
V_8 -> V_55 = & V_56 ;
snprintf ( V_8 -> V_57 , sizeof( V_8 -> V_57 ) , L_1 ,
F_17 ( V_6 -> V_47 ) , V_10 ? L_2 : L_3 ) ;
F_18 ( V_8 , V_2 ) ;
V_8 -> V_58 |= V_59 ;
F_19 ( V_8 , NULL ) ;
return V_2 ;
}
