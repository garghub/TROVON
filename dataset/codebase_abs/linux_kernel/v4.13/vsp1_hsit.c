static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 , T_1 V_6 )
{
F_2 ( V_4 , V_5 , V_6 ) ;
}
static int F_3 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
if ( V_12 -> V_13 > 0 )
return - V_14 ;
if ( ( V_12 -> V_15 == V_16 && ! V_2 -> V_17 ) |
( V_12 -> V_15 == V_18 && V_2 -> V_17 ) )
V_12 -> V_12 = V_19 ;
else
V_12 -> V_12 = V_20 ;
return 0 ;
}
static int F_5 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
struct V_21 * V_22 )
{
return F_6 ( V_8 , V_10 , V_22 , V_23 ,
V_23 , V_24 ,
V_24 ) ;
}
static int F_7 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
struct V_25 * V_26 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_9 * V_27 ;
struct V_28 * V_29 ;
int V_30 = 0 ;
F_8 ( & V_2 -> V_31 . V_32 ) ;
V_27 = F_9 ( & V_2 -> V_31 , V_10 , V_26 -> V_33 ) ;
if ( ! V_27 ) {
V_30 = - V_14 ;
goto V_34;
}
V_29 = F_10 ( & V_2 -> V_31 , V_27 , V_26 -> V_15 ) ;
if ( V_26 -> V_15 == V_18 ) {
V_26 -> V_29 = * V_29 ;
goto V_34;
}
V_29 -> V_12 = V_2 -> V_17 ? V_20
: V_19 ;
V_29 -> V_35 = F_11 (unsigned int, fmt->format.width,
HSIT_MIN_SIZE, HSIT_MAX_SIZE) ;
V_29 -> V_36 = F_11 (unsigned int, fmt->format.height,
HSIT_MIN_SIZE, HSIT_MAX_SIZE) ;
V_29 -> V_37 = V_38 ;
V_29 -> V_39 = V_40 ;
V_26 -> V_29 = * V_29 ;
V_29 = F_10 ( & V_2 -> V_31 , V_27 ,
V_18 ) ;
* V_29 = V_26 -> V_29 ;
V_29 -> V_12 = V_2 -> V_17 ? V_19
: V_20 ;
V_34:
F_12 ( & V_2 -> V_31 . V_32 ) ;
return V_30 ;
}
static void F_13 ( struct V_41 * V_31 ,
struct V_42 * V_43 ,
struct V_3 * V_4 ,
enum V_44 V_45 )
{
struct V_1 * V_2 = F_4 ( & V_31 -> V_8 ) ;
if ( V_45 != V_46 )
return;
if ( V_2 -> V_17 )
F_1 ( V_2 , V_4 , V_47 , V_48 ) ;
else
F_1 ( V_2 , V_4 , V_49 , V_50 ) ;
}
struct V_1 * F_14 ( struct V_51 * V_52 , bool V_17 )
{
struct V_1 * V_2 ;
int V_30 ;
V_2 = F_15 ( V_52 -> V_53 , sizeof( * V_2 ) , V_54 ) ;
if ( V_2 == NULL )
return F_16 ( - V_55 ) ;
V_2 -> V_17 = V_17 ;
V_2 -> V_31 . V_56 = & V_57 ;
if ( V_17 )
V_2 -> V_31 . type = V_58 ;
else
V_2 -> V_31 . type = V_59 ;
V_30 = F_17 ( V_52 , & V_2 -> V_31 , V_17 ? L_1 : L_2 ,
2 , & V_60 ,
V_61 ) ;
if ( V_30 < 0 )
return F_16 ( V_30 ) ;
return V_2 ;
}
