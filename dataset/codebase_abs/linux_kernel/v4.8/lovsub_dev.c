static void F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_4 ) ;
F_3 ( V_8 , V_7 ) ;
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
V_27 = V_26 -> V_30 -> V_31 ( V_2 , V_22 , V_26 -> V_32 , NULL ) ;
if ( V_27 ) {
V_22 -> V_28 = NULL ;
return V_27 ;
}
F_8 ( V_22 ) ;
F_9 ( & V_22 -> V_33 , L_1 , & V_34 ) ;
V_24 -> V_35 = F_10 ( V_22 ) ;
return V_27 ;
}
static struct V_19 * F_11 ( const struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_19 * V_22 ;
struct V_23 * V_24 ;
V_24 = F_7 ( V_20 ) ;
V_22 = F_12 ( V_24 -> V_35 ) ;
V_24 -> V_36 = NULL ;
V_24 -> V_35 = NULL ;
return V_22 ;
}
static struct V_19 * F_13 ( const struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_23 * V_24 = F_7 ( V_20 ) ;
struct V_19 * V_22 = F_12 ( V_24 -> V_35 ) ;
if ( F_14 ( & V_20 -> V_37 ) && V_20 -> V_28 ) {
F_15 ( V_38 , V_39 , NULL ) ;
F_16 ( V_2 , V_20 -> V_28 , & V_38 , V_40 ) ;
}
F_17 ( F_10 ( V_20 ) ) ;
F_18 ( V_24 ) ;
return V_22 ;
}
static int F_19 ( const struct V_1 * V_2 , struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_6 * V_7 ;
int V_45 ;
V_7 = F_20 ( V_8 , V_46 ) ;
if ( V_7 ) {
F_21 ( V_44 , & V_7 -> V_47 , V_42 , & V_48 ) ;
V_45 = 0 ;
} else {
V_45 = - V_49 ;
}
return V_45 ;
}
static struct V_19 * F_22 ( const struct V_1 * V_2 ,
struct V_25 * V_50 ,
struct V_51 * V_52 )
{
struct V_19 * V_20 ;
struct V_23 * V_24 ;
V_24 = F_23 ( sizeof( * V_24 ) , V_46 ) ;
if ( V_24 ) {
int V_45 ;
V_45 = F_24 ( & V_24 -> V_53 , V_50 ) ;
if ( V_45 == 0 ) {
V_20 = F_25 ( V_24 ) ;
V_20 -> V_54 = & V_55 ;
V_24 -> V_53 . V_56 = & V_57 ;
} else {
V_20 = F_26 ( V_45 ) ;
}
} else {
V_20 = F_26 ( - V_49 ) ;
}
return V_20 ;
}
