static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 , T_1 V_7 , T_2 V_8 )
{
struct {
struct V_9 V_10 ;
struct V_11 V_12 ;
} V_13 ;
struct V_11 * V_12 = & V_13 . V_12 ;
struct V_9 * V_10 = & V_13 . V_10 ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_10 -> V_14 = 0 ;
V_10 -> V_15 = V_16 ;
V_10 -> V_17 = 0 ;
V_10 -> V_18 = sizeof( * V_12 ) ;
V_12 -> V_8 = V_8 ;
V_12 -> V_19 = V_20 ;
V_12 -> V_7 = V_7 ;
return F_4 ( V_6 , V_10 ) ;
}
static int F_5 ( struct V_5 * V_6 , T_1 V_7 ,
T_3 * V_21 )
{
struct {
struct V_9 V_10 ;
union {
struct V_22 V_12 ;
struct V_23 V_24 ;
};
} V_13 ;
struct V_22 * V_12 = & V_13 . V_12 ;
struct V_23 * V_24 = & V_13 . V_24 ;
struct V_9 * V_10 = & V_13 . V_10 ;
int V_25 ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_10 -> V_14 = 0 ;
V_10 -> V_15 = V_26 ;
V_10 -> V_17 = sizeof( * V_12 ) ;
V_10 -> V_18 = sizeof( * V_24 ) ;
V_12 -> V_19 = V_20 ;
V_12 -> V_7 = V_7 ;
V_25 = F_4 ( V_6 , V_10 ) ;
if ( V_21 )
* V_21 = V_10 -> V_21 ;
if ( V_25 < 0 )
return V_25 ;
return V_24 -> V_8 ;
}
static int F_6 ( struct V_5 * V_6 , T_1 V_7 )
{
return F_5 ( V_6 , V_7 , NULL ) ;
}
static int F_7 ( struct V_2 * V_4 , struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_31 = F_1 ( V_4 ) ;
int V_32 ;
if ( V_30 -> V_33 != V_34 )
return - V_35 ;
V_32 = V_30 -> V_36 ? V_30 -> V_32 : 0 ;
return F_3 ( V_31 -> V_6 , V_28 -> V_37 , V_32 ) ;
}
static void F_8 ( struct V_2 * V_4 , struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_1 * V_31 = F_1 ( V_4 ) ;
int V_25 ;
V_25 = F_6 ( V_31 -> V_6 , V_28 -> V_37 ) ;
if ( V_25 < 0 ) {
F_9 ( V_4 -> V_38 , L_1 , V_25 ) ;
return;
}
V_30 -> V_36 = ( V_25 > 0 ) ;
V_30 -> V_33 = V_34 ;
V_30 -> V_32 = V_25 ;
}
static struct V_27 *
F_10 ( struct V_2 * V_39 , const struct V_40 * args )
{
struct V_27 * V_28 ;
if ( args -> args [ 0 ] >= V_39 -> V_41 )
return F_11 ( - V_35 ) ;
V_28 = F_12 ( V_39 , args -> args [ 0 ] , NULL ) ;
if ( F_13 ( V_28 ) )
return V_28 ;
V_28 -> args . V_33 = V_34 ;
return V_28 ;
}
static int F_14 ( struct V_5 * V_6 )
{
int V_42 , V_25 ;
for ( V_42 = 0 ; V_42 <= V_43 ; V_42 ++ ) {
T_3 V_21 = 0 ;
V_25 = F_5 ( V_6 , V_42 , & V_21 ) ;
if ( V_25 < 0 && ! ( V_25 == - V_44 && V_21 ) )
return V_25 ;
if ( V_21 == V_45 )
return - V_46 ;
else if ( V_21 == V_47 )
return V_42 ;
else if ( V_21 )
return - V_44 ;
}
return V_43 ;
}
static int F_15 ( struct V_48 * V_49 )
{
struct V_5 * V_6 = F_16 ( V_49 -> V_38 . V_50 ) ;
struct V_51 * V_38 = & V_49 -> V_38 ;
struct V_1 * V_31 ;
struct V_2 * V_4 ;
int V_25 ;
if ( ! V_6 ) {
F_9 ( V_38 , L_2 ) ;
return - V_35 ;
}
V_31 = F_17 ( V_38 , sizeof( * V_31 ) , V_52 ) ;
if ( ! V_31 )
return - V_53 ;
V_4 = & V_31 -> V_4 ;
V_31 -> V_6 = V_6 ;
V_4 -> V_38 = V_38 ;
V_4 -> V_54 = & V_55 ;
V_4 -> V_56 = F_10 ;
V_4 -> V_57 = 1 ;
V_4 -> V_58 = - 1 ;
V_25 = F_14 ( V_6 ) ;
if ( V_25 < 0 ) {
F_9 ( V_38 , L_3 , V_25 ) ;
return V_25 ;
}
V_4 -> V_41 = V_25 ;
F_18 ( V_38 , L_4 , V_4 -> V_41 ) ;
V_25 = F_19 ( V_4 ) ;
if ( V_25 < 0 ) {
F_9 ( V_38 , L_5 , V_25 ) ;
return V_25 ;
}
F_20 ( V_49 , V_31 ) ;
return V_25 ;
}
static int F_21 ( struct V_48 * V_38 )
{
struct V_1 * V_31 = F_22 ( V_38 ) ;
struct V_2 * V_4 = & V_31 -> V_4 ;
return F_23 ( V_4 ) ;
}
