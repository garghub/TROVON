static void F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 ;
V_8 ;
V_7 = F_2 ( V_4 ) ;
F_3 ( V_7 , V_9 ) ;
EXIT ;
}
static void F_4 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_10 * V_11 ,
struct V_12 * V_13 , T_1 V_14 )
{
struct V_15 * V_16 ;
V_8 ;
V_16 = F_5 ( V_11 ) ;
V_13 -> V_17 -> V_18 = V_16 -> V_19 ;
EXIT ;
}
static int F_6 ( const struct V_1 * V_2 , struct V_20 * V_21 ,
const char * V_22 , struct V_20 * V_23 )
{
struct V_24 * V_25 = F_7 ( V_21 ) ;
struct V_26 * V_27 ;
int V_28 ;
V_8 ;
V_23 -> V_29 = V_21 -> V_29 ;
V_27 = V_23 -> V_30 ;
F_8 ( V_27 != NULL ) ;
V_28 = V_27 -> V_31 -> V_32 ( V_2 , V_23 , V_27 -> V_33 , NULL ) ;
if ( V_28 ) {
V_23 -> V_29 = NULL ;
RETURN ( V_28 ) ;
}
F_9 ( V_23 ) ;
F_10 ( & V_23 -> V_34 , L_1 , & V_35 ) ;
V_25 -> V_36 = F_11 ( V_23 ) ;
RETURN ( V_28 ) ;
}
static struct V_20 * F_12 ( const struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_20 * V_23 ;
struct V_24 * V_25 ;
V_8 ;
V_25 = F_7 ( V_21 ) ;
V_23 = F_13 ( V_25 -> V_36 ) ;
V_25 -> V_37 = NULL ;
V_25 -> V_36 = NULL ;
RETURN ( V_23 ) ;
}
static struct V_20 * F_14 ( const struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_24 * V_25 = F_7 ( V_21 ) ;
struct V_20 * V_23 = F_13 ( V_25 -> V_36 ) ;
F_15 ( F_11 ( V_21 ) ) ;
F_16 ( V_25 ) ;
return V_23 ;
}
static int F_17 ( const struct V_1 * V_2 , struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_6 * V_7 ;
int V_42 ;
F_18 ( V_7 , V_9 , V_43 ) ;
if ( V_7 != NULL ) {
F_19 ( V_41 , & V_7 -> V_44 , V_39 , & V_45 ) ;
V_42 = 0 ;
} else
V_42 = - V_46 ;
return V_42 ;
}
static struct V_20 * F_20 ( const struct V_1 * V_2 ,
struct V_26 * V_47 ,
struct V_48 * V_49 )
{
struct V_20 * V_21 ;
struct V_24 * V_25 ;
F_21 ( V_25 ) ;
if ( V_25 != NULL ) {
int V_42 ;
V_42 = F_22 ( & V_25 -> V_50 , V_47 ) ;
if ( V_42 == 0 ) {
V_21 = F_23 ( V_25 ) ;
V_21 -> V_51 = & V_52 ;
V_25 -> V_50 . V_53 = & V_54 ;
} else
V_21 = F_24 ( V_42 ) ;
} else
V_21 = F_24 ( - V_46 ) ;
return V_21 ;
}
