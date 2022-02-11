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
int V_25 = 0 ;
F_10 ( & V_2 -> V_26 . V_27 ) ;
V_22 = F_11 ( & V_2 -> V_26 , V_10 , V_21 -> V_28 ) ;
if ( ! V_22 ) {
V_25 = - V_29 ;
goto V_30;
}
if ( V_21 -> V_24 . V_12 != V_14 &&
V_21 -> V_24 . V_12 != V_15 )
V_21 -> V_24 . V_12 = V_15 ;
V_24 = F_12 ( & V_2 -> V_26 , V_22 , V_21 -> V_31 ) ;
if ( V_21 -> V_31 == V_32 ) {
V_21 -> V_24 = * V_24 ;
goto V_30;
}
V_24 -> V_12 = V_21 -> V_24 . V_12 ;
V_24 -> V_33 = F_13 (unsigned int, fmt->format.width,
LIF_MIN_SIZE, LIF_MAX_SIZE) ;
V_24 -> V_34 = F_13 (unsigned int, fmt->format.height,
LIF_MIN_SIZE, LIF_MAX_SIZE) ;
V_24 -> V_35 = V_36 ;
V_24 -> V_37 = V_38 ;
V_21 -> V_24 = * V_24 ;
V_24 = F_12 ( & V_2 -> V_26 , V_22 ,
V_32 ) ;
* V_24 = V_21 -> V_24 ;
V_30:
F_14 ( & V_2 -> V_26 . V_27 ) ;
return V_25 ;
}
static void F_15 ( struct V_39 * V_26 ,
struct V_40 * V_41 ,
struct V_3 * V_4 ,
enum V_42 V_43 )
{
const struct V_23 * V_24 ;
struct V_1 * V_2 = F_9 ( & V_26 -> V_8 ) ;
unsigned int V_44 = 1300 ;
unsigned int V_45 = 400 ;
unsigned int V_46 = 200 ;
if ( V_43 != V_47 )
return;
V_24 = F_12 ( & V_2 -> V_26 , V_2 -> V_26 . V_22 ,
V_32 ) ;
V_45 = F_16 ( V_45 , ( V_24 -> V_33 + 1 ) / 2 * V_24 -> V_34 - 4 ) ;
F_1 ( V_2 , V_4 , V_48 ,
( V_44 << V_49 ) |
( V_46 << V_50 ) ) ;
F_1 ( V_2 , V_4 , V_51 ,
( V_45 << V_52 ) |
( V_24 -> V_12 == 0 ? V_53 : 0 ) |
V_54 | V_55 ) ;
}
struct V_1 * F_17 ( struct V_56 * V_57 )
{
struct V_1 * V_2 ;
int V_25 ;
V_2 = F_18 ( V_57 -> V_58 , sizeof( * V_2 ) , V_59 ) ;
if ( V_2 == NULL )
return F_19 ( - V_60 ) ;
V_2 -> V_26 . V_61 = & V_62 ;
V_2 -> V_26 . type = V_63 ;
V_25 = F_20 ( V_57 , & V_2 -> V_26 , L_1 , 2 , & V_64 ,
V_65 ) ;
if ( V_25 < 0 )
return F_19 ( V_25 ) ;
return V_2 ;
}
