static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( & V_2 -> V_5 , V_3 , V_4 ) ;
}
static int F_3 ( struct V_6 * V_7 , int V_8 )
{
const struct V_9 * V_10 ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
unsigned int V_11 = 1300 ;
unsigned int V_12 = 400 ;
unsigned int V_13 = 200 ;
if ( ! V_8 ) {
F_5 ( V_2 -> V_5 . V_14 , V_15 , 0 ) ;
return 0 ;
}
V_10 = & V_2 -> V_5 . V_16 [ V_17 ] ;
V_12 = F_6 ( V_12 , ( V_10 -> V_18 + 1 ) / 2 * V_10 -> V_19 - 4 ) ;
F_1 ( V_2 , V_20 ,
( V_11 << V_21 ) |
( V_13 << V_22 ) ) ;
F_1 ( V_2 , V_15 ,
( V_12 << V_23 ) |
( V_10 -> V_24 == 0 ? V_25 : 0 ) |
V_26 | V_27 ) ;
return 0 ;
}
static int F_7 ( struct V_6 * V_7 ,
struct V_28 * V_29 ,
struct V_30 * V_24 )
{
static const unsigned int V_31 [] = {
V_32 ,
V_33 ,
} ;
struct V_1 * V_2 = F_4 ( V_7 ) ;
if ( V_24 -> V_34 == V_35 ) {
if ( V_24 -> V_36 >= F_8 ( V_31 ) )
return - V_37 ;
V_24 -> V_24 = V_31 [ V_24 -> V_36 ] ;
} else {
struct V_9 * V_10 ;
if ( V_24 -> V_36 )
return - V_37 ;
V_10 = F_9 ( & V_2 -> V_5 , V_29 ,
V_35 , V_24 -> V_38 ) ;
V_24 -> V_24 = V_10 -> V_24 ;
}
return 0 ;
}
static int F_10 ( struct V_6 * V_7 ,
struct V_28 * V_29 ,
struct V_39 * V_40 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_9 * V_10 ;
V_10 = F_9 ( & V_2 -> V_5 , V_29 , V_35 ,
V_40 -> V_38 ) ;
if ( V_40 -> V_36 || V_40 -> V_24 != V_10 -> V_24 )
return - V_37 ;
if ( V_40 -> V_34 == V_35 ) {
V_40 -> V_41 = V_42 ;
V_40 -> V_43 = V_44 ;
V_40 -> V_45 = V_42 ;
V_40 -> V_46 = V_44 ;
} else {
V_40 -> V_41 = V_10 -> V_18 ;
V_40 -> V_43 = V_10 -> V_18 ;
V_40 -> V_45 = V_10 -> V_19 ;
V_40 -> V_46 = V_10 -> V_19 ;
}
return 0 ;
}
static int F_11 ( struct V_6 * V_7 , struct V_28 * V_29 ,
struct V_47 * V_48 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
V_48 -> V_10 = * F_9 ( & V_2 -> V_5 , V_29 , V_48 -> V_34 ,
V_48 -> V_38 ) ;
return 0 ;
}
static int F_12 ( struct V_6 * V_7 , struct V_28 * V_29 ,
struct V_47 * V_48 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
struct V_9 * V_10 ;
if ( V_48 -> V_10 . V_24 != V_32 &&
V_48 -> V_10 . V_24 != V_33 )
V_48 -> V_10 . V_24 = V_33 ;
V_10 = F_9 ( & V_2 -> V_5 , V_29 , V_48 -> V_34 ,
V_48 -> V_38 ) ;
if ( V_48 -> V_34 == V_17 ) {
V_48 -> V_10 = * V_10 ;
return 0 ;
}
V_10 -> V_24 = V_48 -> V_10 . V_24 ;
V_10 -> V_18 = F_13 (unsigned int, fmt->format.width,
LIF_MIN_SIZE, LIF_MAX_SIZE) ;
V_10 -> V_19 = F_13 (unsigned int, fmt->format.height,
LIF_MIN_SIZE, LIF_MAX_SIZE) ;
V_10 -> V_49 = V_50 ;
V_10 -> V_51 = V_52 ;
V_48 -> V_10 = * V_10 ;
V_10 = F_9 ( & V_2 -> V_5 , V_29 , V_17 ,
V_48 -> V_38 ) ;
* V_10 = V_48 -> V_10 ;
return 0 ;
}
struct V_1 * F_14 ( struct V_53 * V_14 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
int V_54 ;
V_2 = F_15 ( V_14 -> V_55 , sizeof( * V_2 ) , V_56 ) ;
if ( V_2 == NULL )
return F_16 ( - V_57 ) ;
V_2 -> V_5 . type = V_58 ;
V_54 = F_17 ( V_14 , & V_2 -> V_5 , 2 ) ;
if ( V_54 < 0 )
return F_16 ( V_54 ) ;
V_7 = & V_2 -> V_5 . V_7 ;
F_18 ( V_7 , & V_59 ) ;
V_7 -> V_5 . V_60 = & V_14 -> V_61 ;
V_7 -> V_62 = & V_63 ;
snprintf ( V_7 -> V_64 , sizeof( V_7 -> V_64 ) , L_1 ,
F_19 ( V_14 -> V_55 ) ) ;
F_20 ( V_7 , V_2 ) ;
V_7 -> V_65 |= V_66 ;
F_21 ( V_7 , NULL ) ;
return V_2 ;
}
