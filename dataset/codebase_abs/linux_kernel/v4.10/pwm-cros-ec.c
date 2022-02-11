static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 , T_1 V_7 , T_2 V_8 )
{
struct {
struct V_9 V_10 ;
struct V_11 V_12 ;
} V_13 V_14 ;
struct V_11 * V_12 = & V_14 . V_12 ;
struct V_9 * V_10 = & V_14 . V_10 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_10 -> V_15 = 0 ;
V_10 -> V_16 = V_17 ;
V_10 -> V_18 = 0 ;
V_10 -> V_19 = sizeof( * V_12 ) ;
V_12 -> V_8 = V_8 ;
V_12 -> V_20 = V_21 ;
V_12 -> V_7 = V_7 ;
return F_4 ( V_6 , V_10 ) ;
}
static int F_5 ( struct V_5 * V_6 , T_1 V_7 ,
T_3 * V_22 )
{
struct {
struct V_9 V_10 ;
union {
struct V_23 V_12 ;
struct V_24 V_25 ;
};
} V_13 V_14 ;
struct V_23 * V_12 = & V_14 . V_12 ;
struct V_24 * V_25 = & V_14 . V_25 ;
struct V_9 * V_10 = & V_14 . V_10 ;
int V_26 ;
memset ( & V_14 , 0 , sizeof( V_14 ) ) ;
V_10 -> V_15 = 0 ;
V_10 -> V_16 = V_27 ;
V_10 -> V_18 = sizeof( * V_12 ) ;
V_10 -> V_19 = sizeof( * V_25 ) ;
V_12 -> V_20 = V_21 ;
V_12 -> V_7 = V_7 ;
V_26 = F_4 ( V_6 , V_10 ) ;
if ( V_22 )
* V_22 = V_10 -> V_22 ;
if ( V_26 < 0 )
return V_26 ;
return V_25 -> V_8 ;
}
static int F_6 ( struct V_5 * V_6 , T_1 V_7 )
{
return F_5 ( V_6 , V_7 , NULL ) ;
}
static int F_7 ( struct V_2 * V_4 , struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_1 * V_32 = F_1 ( V_4 ) ;
int V_33 ;
if ( V_31 -> V_34 != V_35 )
return - V_36 ;
V_33 = V_31 -> V_37 ? V_31 -> V_33 : 0 ;
return F_3 ( V_32 -> V_6 , V_29 -> V_38 , V_33 ) ;
}
static void F_8 ( struct V_2 * V_4 , struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_1 * V_32 = F_1 ( V_4 ) ;
int V_26 ;
V_26 = F_6 ( V_32 -> V_6 , V_29 -> V_38 ) ;
if ( V_26 < 0 ) {
F_9 ( V_4 -> V_39 , L_1 , V_26 ) ;
return;
}
V_31 -> V_37 = ( V_26 > 0 ) ;
V_31 -> V_34 = V_35 ;
V_31 -> V_33 = V_26 ;
}
static struct V_28 *
F_10 ( struct V_2 * V_40 , const struct V_41 * args )
{
struct V_28 * V_29 ;
if ( args -> args [ 0 ] >= V_40 -> V_42 )
return F_11 ( - V_36 ) ;
V_29 = F_12 ( V_40 , args -> args [ 0 ] , NULL ) ;
if ( F_13 ( V_29 ) )
return V_29 ;
V_29 -> args . V_34 = V_35 ;
return V_29 ;
}
static int F_14 ( struct V_5 * V_6 )
{
int V_43 , V_26 ;
for ( V_43 = 0 ; V_43 <= V_44 ; V_43 ++ ) {
T_3 V_22 = 0 ;
V_26 = F_5 ( V_6 , V_43 , & V_22 ) ;
if ( V_26 < 0 && ! ( V_26 == - V_45 && V_22 ) )
return V_26 ;
if ( V_22 == V_46 )
return - V_47 ;
else if ( V_22 == V_48 )
return V_43 ;
else if ( V_22 )
return - V_45 ;
}
return V_44 ;
}
static int F_15 ( struct V_49 * V_50 )
{
struct V_5 * V_6 = F_16 ( V_50 -> V_39 . V_51 ) ;
struct V_52 * V_39 = & V_50 -> V_39 ;
struct V_1 * V_32 ;
struct V_2 * V_4 ;
int V_26 ;
if ( ! V_6 ) {
F_9 ( V_39 , L_2 ) ;
return - V_36 ;
}
V_32 = F_17 ( V_39 , sizeof( * V_32 ) , V_53 ) ;
if ( ! V_32 )
return - V_54 ;
V_4 = & V_32 -> V_4 ;
V_32 -> V_6 = V_6 ;
V_4 -> V_39 = V_39 ;
V_4 -> V_55 = & V_56 ;
V_4 -> V_57 = F_10 ;
V_4 -> V_58 = 1 ;
V_4 -> V_59 = - 1 ;
V_26 = F_14 ( V_6 ) ;
if ( V_26 < 0 ) {
F_9 ( V_39 , L_3 , V_26 ) ;
return V_26 ;
}
V_4 -> V_42 = V_26 ;
F_18 ( V_39 , L_4 , V_4 -> V_42 ) ;
V_26 = F_19 ( V_4 ) ;
if ( V_26 < 0 ) {
F_9 ( V_39 , L_5 , V_26 ) ;
return V_26 ;
}
F_20 ( V_50 , V_32 ) ;
return V_26 ;
}
static int F_21 ( struct V_49 * V_39 )
{
struct V_1 * V_32 = F_22 ( V_39 ) ;
struct V_2 * V_4 = & V_32 -> V_4 ;
return F_23 ( V_4 ) ;
}
