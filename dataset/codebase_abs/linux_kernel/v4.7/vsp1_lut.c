static inline void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , T_1 V_6 )
{
F_2 ( V_4 , V_5 , V_6 ) ;
}
static int F_3 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_9 * V_10 ;
unsigned int V_11 ;
V_10 = F_4 ( V_2 -> V_12 . V_13 , F_5 ( V_8 -> V_2 ) ) ;
if ( ! V_10 )
return - V_14 ;
for ( V_11 = 0 ; V_11 < F_5 ( V_8 -> V_2 ) ; ++ V_11 )
F_6 ( V_10 , V_15 + 4 * V_11 ,
V_8 -> V_2 [ V_11 ] ) ;
F_7 ( & V_2 -> V_16 ) ;
F_8 ( V_2 -> V_2 , V_10 ) ;
F_9 ( & V_2 -> V_16 ) ;
F_10 ( V_10 ) ;
return 0 ;
}
static long F_11 ( struct V_17 * V_18 , unsigned int V_19 , void * V_20 )
{
struct V_1 * V_2 = F_12 ( V_18 ) ;
switch ( V_19 ) {
case V_21 :
return F_3 ( V_2 , V_20 ) ;
default:
return - V_22 ;
}
}
static int F_13 ( struct V_17 * V_18 ,
struct V_23 * V_24 ,
struct V_25 * V_26 )
{
static const unsigned int V_27 [] = {
V_28 ,
V_29 ,
V_30 ,
} ;
return F_14 ( V_18 , V_24 , V_26 , V_27 ,
F_5 ( V_27 ) ) ;
}
static int F_15 ( struct V_17 * V_18 ,
struct V_23 * V_24 ,
struct V_31 * V_32 )
{
return F_16 ( V_18 , V_24 , V_32 , V_33 ,
V_33 , V_34 ,
V_34 ) ;
}
static int F_17 ( struct V_17 * V_18 ,
struct V_23 * V_24 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 = F_12 ( V_18 ) ;
struct V_23 * V_8 ;
struct V_37 * V_38 ;
V_8 = F_18 ( & V_2 -> V_12 , V_24 , V_36 -> V_39 ) ;
if ( ! V_8 )
return - V_40 ;
if ( V_36 -> V_38 . V_26 != V_28 &&
V_36 -> V_38 . V_26 != V_29 &&
V_36 -> V_38 . V_26 != V_30 )
V_36 -> V_38 . V_26 = V_30 ;
V_38 = F_19 ( & V_2 -> V_12 , V_8 , V_36 -> V_41 ) ;
if ( V_36 -> V_41 == V_42 ) {
V_36 -> V_38 = * V_38 ;
return 0 ;
}
V_38 -> V_26 = V_36 -> V_38 . V_26 ;
V_38 -> V_43 = F_20 (unsigned int, fmt->format.width,
LUT_MIN_SIZE, LUT_MAX_SIZE) ;
V_38 -> V_44 = F_20 (unsigned int, fmt->format.height,
LUT_MIN_SIZE, LUT_MAX_SIZE) ;
V_38 -> V_45 = V_46 ;
V_38 -> V_47 = V_48 ;
V_36 -> V_38 = * V_38 ;
V_38 = F_19 ( & V_2 -> V_12 , V_8 ,
V_42 ) ;
* V_38 = V_36 -> V_38 ;
return 0 ;
}
static void F_21 ( struct V_49 * V_12 ,
struct V_50 * V_51 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = F_12 ( & V_12 -> V_18 ) ;
F_1 ( V_2 , V_4 , V_52 , V_53 ) ;
F_7 ( & V_2 -> V_16 ) ;
if ( V_2 -> V_2 ) {
F_22 ( V_4 , V_2 -> V_2 ) ;
V_2 -> V_2 = NULL ;
}
F_9 ( & V_2 -> V_16 ) ;
}
struct V_1 * F_23 ( struct V_54 * V_13 )
{
struct V_1 * V_2 ;
int V_55 ;
V_2 = F_24 ( V_13 -> V_56 , sizeof( * V_2 ) , V_57 ) ;
if ( V_2 == NULL )
return F_25 ( - V_14 ) ;
V_2 -> V_12 . V_58 = & V_59 ;
V_2 -> V_12 . type = V_60 ;
V_55 = F_26 ( V_13 , & V_2 -> V_12 , L_1 , 2 , & V_61 ) ;
if ( V_55 < 0 )
return F_25 ( V_55 ) ;
return V_2 ;
}
