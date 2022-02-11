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
V_27 = F_8 ( & V_2 -> V_30 , V_10 , V_26 -> V_31 ) ;
if ( ! V_27 )
return - V_14 ;
V_29 = F_9 ( & V_2 -> V_30 , V_27 , V_26 -> V_15 ) ;
if ( V_26 -> V_15 == V_18 ) {
V_26 -> V_29 = * V_29 ;
return 0 ;
}
V_29 -> V_12 = V_2 -> V_17 ? V_20
: V_19 ;
V_29 -> V_32 = F_10 (unsigned int, fmt->format.width,
HSIT_MIN_SIZE, HSIT_MAX_SIZE) ;
V_29 -> V_33 = F_10 (unsigned int, fmt->format.height,
HSIT_MIN_SIZE, HSIT_MAX_SIZE) ;
V_29 -> V_34 = V_35 ;
V_29 -> V_36 = V_37 ;
V_26 -> V_29 = * V_29 ;
V_29 = F_9 ( & V_2 -> V_30 , V_27 ,
V_18 ) ;
* V_29 = V_26 -> V_29 ;
V_29 -> V_12 = V_2 -> V_17 ? V_19
: V_20 ;
return 0 ;
}
static void F_11 ( struct V_38 * V_30 ,
struct V_39 * V_40 ,
struct V_3 * V_4 , bool V_41 )
{
struct V_1 * V_2 = F_4 ( & V_30 -> V_8 ) ;
if ( ! V_41 )
return;
if ( V_2 -> V_17 )
F_1 ( V_2 , V_4 , V_42 , V_43 ) ;
else
F_1 ( V_2 , V_4 , V_44 , V_45 ) ;
}
struct V_1 * F_12 ( struct V_46 * V_47 , bool V_17 )
{
struct V_1 * V_2 ;
int V_48 ;
V_2 = F_13 ( V_47 -> V_49 , sizeof( * V_2 ) , V_50 ) ;
if ( V_2 == NULL )
return F_14 ( - V_51 ) ;
V_2 -> V_17 = V_17 ;
V_2 -> V_30 . V_52 = & V_53 ;
if ( V_17 )
V_2 -> V_30 . type = V_54 ;
else
V_2 -> V_30 . type = V_55 ;
V_48 = F_15 ( V_47 , & V_2 -> V_30 , V_17 ? L_1 : L_2 ,
2 , & V_56 ,
V_57 ) ;
if ( V_48 < 0 )
return F_14 ( V_48 ) ;
return V_2 ;
}
