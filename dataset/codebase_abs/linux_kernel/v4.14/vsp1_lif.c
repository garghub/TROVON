static inline void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , T_1 V_6 )
{
F_2 ( V_4 , V_5 + V_2 -> V_7 . V_8 * V_9 , V_6 ) ;
}
static int F_3 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_14 * V_15 )
{
static const unsigned int V_16 [] = {
V_17 ,
V_18 ,
} ;
return F_4 ( V_11 , V_13 , V_15 , V_16 ,
F_5 ( V_16 ) ) ;
}
static int F_6 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_19 * V_20 )
{
return F_7 ( V_11 , V_13 , V_20 , V_21 ,
V_21 , V_22 ,
V_22 ) ;
}
static int F_8 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
struct V_12 * V_25 ;
struct V_26 * V_27 ;
int V_28 = 0 ;
F_10 ( & V_2 -> V_7 . V_29 ) ;
V_25 = F_11 ( & V_2 -> V_7 , V_13 , V_24 -> V_30 ) ;
if ( ! V_25 ) {
V_28 = - V_31 ;
goto V_32;
}
if ( V_24 -> V_27 . V_15 != V_17 &&
V_24 -> V_27 . V_15 != V_18 )
V_24 -> V_27 . V_15 = V_18 ;
V_27 = F_12 ( & V_2 -> V_7 , V_25 , V_24 -> V_33 ) ;
if ( V_24 -> V_33 == V_34 ) {
V_24 -> V_27 = * V_27 ;
goto V_32;
}
V_27 -> V_15 = V_24 -> V_27 . V_15 ;
V_27 -> V_35 = F_13 (unsigned int, fmt->format.width,
LIF_MIN_SIZE, LIF_MAX_SIZE) ;
V_27 -> V_36 = F_13 (unsigned int, fmt->format.height,
LIF_MIN_SIZE, LIF_MAX_SIZE) ;
V_27 -> V_37 = V_38 ;
V_27 -> V_39 = V_40 ;
V_24 -> V_27 = * V_27 ;
V_27 = F_12 ( & V_2 -> V_7 , V_25 ,
V_34 ) ;
* V_27 = V_24 -> V_27 ;
V_32:
F_14 ( & V_2 -> V_7 . V_29 ) ;
return V_28 ;
}
static void F_15 ( struct V_41 * V_7 ,
struct V_42 * V_43 ,
struct V_3 * V_4 ,
enum V_44 V_45 )
{
const struct V_26 * V_27 ;
struct V_1 * V_2 = F_9 ( & V_7 -> V_11 ) ;
unsigned int V_46 = 1300 ;
unsigned int V_47 = 400 ;
unsigned int V_48 = 200 ;
if ( V_45 != V_49 )
return;
V_27 = F_12 ( & V_2 -> V_7 , V_2 -> V_7 . V_25 ,
V_34 ) ;
V_47 = F_16 ( V_47 , ( V_27 -> V_35 + 1 ) / 2 * V_27 -> V_36 - 4 ) ;
F_1 ( V_2 , V_4 , V_50 ,
( V_46 << V_51 ) |
( V_48 << V_52 ) ) ;
F_1 ( V_2 , V_4 , V_53 ,
( V_47 << V_54 ) |
( V_27 -> V_15 == 0 ? V_55 : 0 ) |
V_56 | V_57 ) ;
}
struct V_1 * F_17 ( struct V_58 * V_59 , unsigned int V_8 )
{
struct V_1 * V_2 ;
int V_28 ;
V_2 = F_18 ( V_59 -> V_60 , sizeof( * V_2 ) , V_61 ) ;
if ( V_2 == NULL )
return F_19 ( - V_62 ) ;
V_2 -> V_7 . V_63 = & V_64 ;
V_2 -> V_7 . type = V_65 ;
V_2 -> V_7 . V_8 = V_8 ;
V_28 = F_20 ( V_59 , & V_2 -> V_7 , L_1 , 2 , & V_66 ,
V_67 ) ;
if ( V_28 < 0 )
return F_19 ( V_28 ) ;
return V_2 ;
}
