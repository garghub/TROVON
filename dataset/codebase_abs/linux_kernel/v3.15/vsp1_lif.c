static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 . V_5 , V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
F_4 ( V_2 -> V_4 . V_5 , V_3 , V_6 ) ;
}
static int F_5 ( struct V_7 * V_8 , int V_9 )
{
const struct V_10 * V_11 ;
struct V_1 * V_2 = F_6 ( V_8 ) ;
unsigned int V_12 = 1300 ;
unsigned int V_13 = 400 ;
unsigned int V_14 = 200 ;
if ( ! V_9 ) {
F_3 ( V_2 , V_15 , 0 ) ;
return 0 ;
}
V_11 = & V_2 -> V_4 . V_16 [ V_17 ] ;
V_13 = F_7 ( V_13 , ( V_11 -> V_18 + 1 ) / 2 * V_11 -> V_19 - 4 ) ;
F_3 ( V_2 , V_20 ,
( V_12 << V_21 ) |
( V_14 << V_22 ) ) ;
F_3 ( V_2 , V_15 ,
( V_13 << V_23 ) |
( V_11 -> V_24 == 0 ? V_25 : 0 ) |
V_26 | V_27 ) ;
return 0 ;
}
static int F_8 ( struct V_7 * V_8 ,
struct V_28 * V_29 ,
struct V_30 * V_24 )
{
static const unsigned int V_31 [] = {
V_32 ,
V_33 ,
} ;
if ( V_24 -> V_34 == V_35 ) {
if ( V_24 -> V_36 >= F_9 ( V_31 ) )
return - V_37 ;
V_24 -> V_24 = V_31 [ V_24 -> V_36 ] ;
} else {
struct V_10 * V_11 ;
if ( V_24 -> V_36 )
return - V_37 ;
V_11 = F_10 ( V_29 , V_35 ) ;
V_24 -> V_24 = V_11 -> V_24 ;
}
return 0 ;
}
static int F_11 ( struct V_7 * V_8 ,
struct V_28 * V_29 ,
struct V_38 * V_39 )
{
struct V_10 * V_11 ;
V_11 = F_10 ( V_29 , V_35 ) ;
if ( V_39 -> V_36 || V_39 -> V_24 != V_11 -> V_24 )
return - V_37 ;
if ( V_39 -> V_34 == V_35 ) {
V_39 -> V_40 = V_41 ;
V_39 -> V_42 = V_43 ;
V_39 -> V_44 = V_41 ;
V_39 -> V_45 = V_43 ;
} else {
V_39 -> V_40 = V_11 -> V_18 ;
V_39 -> V_42 = V_11 -> V_18 ;
V_39 -> V_44 = V_11 -> V_19 ;
V_39 -> V_45 = V_11 -> V_19 ;
}
return 0 ;
}
static int F_12 ( struct V_7 * V_8 , struct V_28 * V_29 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
V_47 -> V_11 = * F_13 ( & V_2 -> V_4 , V_29 , V_47 -> V_34 ,
V_47 -> V_48 ) ;
return 0 ;
}
static int F_14 ( struct V_7 * V_8 , struct V_28 * V_29 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
struct V_10 * V_11 ;
if ( V_47 -> V_11 . V_24 != V_32 &&
V_47 -> V_11 . V_24 != V_33 )
V_47 -> V_11 . V_24 = V_33 ;
V_11 = F_13 ( & V_2 -> V_4 , V_29 , V_47 -> V_34 ,
V_47 -> V_48 ) ;
if ( V_47 -> V_34 == V_17 ) {
V_47 -> V_11 = * V_11 ;
return 0 ;
}
V_11 -> V_24 = V_47 -> V_11 . V_24 ;
V_11 -> V_18 = F_15 (unsigned int, fmt->format.width,
LIF_MIN_SIZE, LIF_MAX_SIZE) ;
V_11 -> V_19 = F_15 (unsigned int, fmt->format.height,
LIF_MIN_SIZE, LIF_MAX_SIZE) ;
V_11 -> V_49 = V_50 ;
V_11 -> V_51 = V_52 ;
V_47 -> V_11 = * V_11 ;
V_11 = F_13 ( & V_2 -> V_4 , V_29 , V_17 ,
V_47 -> V_48 ) ;
* V_11 = V_47 -> V_11 ;
return 0 ;
}
struct V_1 * F_16 ( struct V_53 * V_5 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
int V_54 ;
V_2 = F_17 ( V_5 -> V_55 , sizeof( * V_2 ) , V_56 ) ;
if ( V_2 == NULL )
return F_18 ( - V_57 ) ;
V_2 -> V_4 . type = V_58 ;
V_2 -> V_4 . V_59 = V_60 ;
V_54 = F_19 ( V_5 , & V_2 -> V_4 , 2 ) ;
if ( V_54 < 0 )
return F_18 ( V_54 ) ;
V_8 = & V_2 -> V_4 . V_8 ;
F_20 ( V_8 , & V_61 ) ;
V_8 -> V_4 . V_62 = & V_63 ;
V_8 -> V_64 = & V_65 ;
snprintf ( V_8 -> V_66 , sizeof( V_8 -> V_66 ) , L_1 ,
F_21 ( V_5 -> V_55 ) ) ;
F_22 ( V_8 , V_2 ) ;
V_8 -> V_67 |= V_68 ;
F_23 ( V_8 , NULL ) ;
return V_2 ;
}
