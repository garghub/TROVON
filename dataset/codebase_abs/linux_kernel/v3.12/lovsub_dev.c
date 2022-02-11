static void F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_4 ) ;
F_3 ( V_7 , V_8 ) ;
}
static void F_4 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_9 * V_10 ,
struct V_11 * V_12 , T_1 V_13 )
{
struct V_14 * V_15 ;
V_15 = F_5 ( V_10 ) ;
V_12 -> V_16 -> V_17 = V_15 -> V_18 ;
}
static int F_6 ( const struct V_1 * V_2 , struct V_19 * V_20 ,
const char * V_21 , struct V_19 * V_22 )
{
struct V_23 * V_24 = F_7 ( V_20 ) ;
struct V_25 * V_26 ;
int V_27 ;
V_22 -> V_28 = V_20 -> V_28 ;
V_26 = V_22 -> V_29 ;
F_8 ( V_26 != NULL ) ;
V_27 = V_26 -> V_30 -> V_31 ( V_2 , V_22 , V_26 -> V_32 , NULL ) ;
if ( V_27 ) {
V_22 -> V_28 = NULL ;
return V_27 ;
}
F_9 ( V_22 ) ;
F_10 ( & V_22 -> V_33 , L_1 , & V_34 ) ;
V_24 -> V_35 = F_11 ( V_22 ) ;
return V_27 ;
}
static struct V_19 * F_12 ( const struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_19 * V_22 ;
struct V_23 * V_24 ;
V_24 = F_7 ( V_20 ) ;
V_22 = F_13 ( V_24 -> V_35 ) ;
V_24 -> V_36 = NULL ;
V_24 -> V_35 = NULL ;
return V_22 ;
}
static struct V_19 * F_14 ( const struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_23 * V_24 = F_7 ( V_20 ) ;
struct V_19 * V_22 = F_13 ( V_24 -> V_35 ) ;
F_15 ( F_11 ( V_20 ) ) ;
F_16 ( V_24 ) ;
return V_22 ;
}
static int F_17 ( const struct V_1 * V_2 , struct V_37 * V_38 ,
struct V_39 * V_40 )
{
struct V_6 * V_7 ;
int V_41 ;
F_18 ( V_7 , V_8 , V_42 ) ;
if ( V_7 != NULL ) {
F_19 ( V_40 , & V_7 -> V_43 , V_38 , & V_44 ) ;
V_41 = 0 ;
} else
V_41 = - V_45 ;
return V_41 ;
}
static struct V_19 * F_20 ( const struct V_1 * V_2 ,
struct V_25 * V_46 ,
struct V_47 * V_48 )
{
struct V_19 * V_20 ;
struct V_23 * V_24 ;
F_21 ( V_24 ) ;
if ( V_24 != NULL ) {
int V_41 ;
V_41 = F_22 ( & V_24 -> V_49 , V_46 ) ;
if ( V_41 == 0 ) {
V_20 = F_23 ( V_24 ) ;
V_20 -> V_50 = & V_51 ;
V_24 -> V_49 . V_52 = & V_53 ;
} else
V_20 = F_24 ( V_41 ) ;
} else
V_20 = F_24 ( - V_45 ) ;
return V_20 ;
}
