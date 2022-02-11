static inline void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , T_1 V_6 )
{
F_2 ( V_4 , V_5 , V_6 ) ;
}
static int F_3 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
struct V_11 * V_12 )
{
static const unsigned int V_13 [] = {
V_14 ,
V_15 ,
} ;
return F_4 ( V_8 , V_10 , V_12 , V_13 ,
F_5 ( V_13 ) ) ;
}
static int F_6 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
struct V_16 * V_17 )
{
return F_7 ( V_8 , V_10 , V_17 , V_18 ,
V_18 , V_19 ,
V_19 ) ;
}
static int F_8 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
struct V_20 * V_21 )
{
struct V_1 * V_2 = F_9 ( V_8 ) ;
struct V_9 * V_22 ;
struct V_23 * V_24 ;
V_22 = F_10 ( & V_2 -> V_25 , V_10 , V_21 -> V_26 ) ;
if ( ! V_22 )
return - V_27 ;
if ( V_21 -> V_24 . V_12 != V_14 &&
V_21 -> V_24 . V_12 != V_15 )
V_21 -> V_24 . V_12 = V_15 ;
V_24 = F_11 ( & V_2 -> V_25 , V_22 , V_21 -> V_28 ) ;
if ( V_21 -> V_28 == V_29 ) {
V_21 -> V_24 = * V_24 ;
return 0 ;
}
V_24 -> V_12 = V_21 -> V_24 . V_12 ;
V_24 -> V_30 = F_12 (unsigned int, fmt->format.width,
LIF_MIN_SIZE, LIF_MAX_SIZE) ;
V_24 -> V_31 = F_12 (unsigned int, fmt->format.height,
LIF_MIN_SIZE, LIF_MAX_SIZE) ;
V_24 -> V_32 = V_33 ;
V_24 -> V_34 = V_35 ;
V_21 -> V_24 = * V_24 ;
V_24 = F_11 ( & V_2 -> V_25 , V_22 ,
V_29 ) ;
* V_24 = V_21 -> V_24 ;
return 0 ;
}
static void F_13 ( struct V_36 * V_25 ,
struct V_37 * V_38 ,
struct V_3 * V_4 , bool V_39 )
{
const struct V_23 * V_24 ;
struct V_1 * V_2 = F_9 ( & V_25 -> V_8 ) ;
unsigned int V_40 = 1300 ;
unsigned int V_41 = 400 ;
unsigned int V_42 = 200 ;
if ( ! V_39 )
return;
V_24 = F_11 ( & V_2 -> V_25 , V_2 -> V_25 . V_22 ,
V_29 ) ;
V_41 = F_14 ( V_41 , ( V_24 -> V_30 + 1 ) / 2 * V_24 -> V_31 - 4 ) ;
F_1 ( V_2 , V_4 , V_43 ,
( V_40 << V_44 ) |
( V_42 << V_45 ) ) ;
F_1 ( V_2 , V_4 , V_46 ,
( V_41 << V_47 ) |
( V_24 -> V_12 == 0 ? V_48 : 0 ) |
V_49 | V_50 ) ;
}
struct V_1 * F_15 ( struct V_51 * V_52 )
{
struct V_1 * V_2 ;
int V_53 ;
V_2 = F_16 ( V_52 -> V_54 , sizeof( * V_2 ) , V_55 ) ;
if ( V_2 == NULL )
return F_17 ( - V_56 ) ;
V_2 -> V_25 . V_57 = & V_58 ;
V_2 -> V_25 . type = V_59 ;
V_53 = F_18 ( V_52 , & V_2 -> V_25 , L_1 , 2 , & V_60 ,
V_61 ) ;
if ( V_53 < 0 )
return F_17 ( V_53 ) ;
return V_2 ;
}
