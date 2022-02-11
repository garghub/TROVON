static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 , struct V_1 , V_5 ) ;
}
static T_1 F_3 ( int V_6 , void * V_7 )
{
struct V_1 * V_4 = V_7 ;
struct V_8 * V_9 = V_4 -> V_5 . V_9 ;
struct V_2 * V_3 = & V_4 -> V_5 . V_10 [ 0 ] ;
while ( ! ( F_4 ( V_4 -> V_11 + V_12 ) & V_13 ) ) {
T_2 V_14 = F_4 ( V_4 -> V_11 + V_15 ) ;
F_5 ( V_9 , L_1 , V_14 ) ;
F_6 ( V_3 , & V_14 ) ;
}
return V_16 ;
}
static int F_7 ( struct V_2 * V_3 , void * V_17 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_2 V_14 = * ( T_2 * ) V_17 ;
F_8 ( & V_4 -> V_18 ) ;
F_9 ( V_14 , V_4 -> V_11 + V_19 ) ;
F_5 ( V_4 -> V_5 . V_9 , L_2 , V_14 ) ;
F_10 ( & V_4 -> V_18 ) ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_9 ( V_20 , V_4 -> V_11 + V_21 ) ;
return 0 ;
}
static void F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_9 ( 0 , V_4 -> V_11 + V_21 ) ;
}
static bool F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
bool V_22 ;
F_8 ( & V_4 -> V_18 ) ;
V_22 = ! ( F_4 ( V_4 -> V_11 + V_23 ) & V_24 ) ;
F_10 ( & V_4 -> V_18 ) ;
return V_22 ;
}
static struct V_2 * F_14 ( struct V_25 * V_4 ,
const struct V_26 * V_27 )
{
if ( V_27 -> V_28 != 0 )
return NULL ;
return & V_4 -> V_10 [ 0 ] ;
}
static int F_15 ( struct V_29 * V_30 )
{
struct V_8 * V_9 = & V_30 -> V_9 ;
int V_22 = 0 ;
struct V_31 * V_32 ;
struct V_1 * V_4 ;
V_4 = F_16 ( V_9 , sizeof( * V_4 ) , V_33 ) ;
if ( V_4 == NULL )
return - V_34 ;
F_17 ( & V_4 -> V_18 ) ;
V_22 = F_18 ( V_9 , F_19 ( V_9 -> V_35 , 0 ) ,
F_3 , 0 , F_20 ( V_9 ) , V_4 ) ;
if ( V_22 ) {
F_21 ( V_9 , L_3 ,
V_22 ) ;
return - V_36 ;
}
V_32 = F_22 ( V_30 , V_37 , 0 ) ;
V_4 -> V_11 = F_23 ( & V_30 -> V_9 , V_32 ) ;
if ( F_24 ( V_4 -> V_11 ) ) {
V_22 = F_25 ( V_4 -> V_11 ) ;
F_21 ( & V_30 -> V_9 , L_4 , V_22 ) ;
return V_22 ;
}
V_4 -> V_5 . V_38 = true ;
V_4 -> V_5 . V_39 = 5 ;
V_4 -> V_5 . V_40 = & V_41 ;
V_4 -> V_5 . V_42 = & F_14 ;
V_4 -> V_5 . V_9 = V_9 ;
V_4 -> V_5 . V_43 = 1 ;
V_4 -> V_5 . V_10 = F_16 ( V_9 ,
sizeof( * V_4 -> V_5 . V_10 ) , V_33 ) ;
if ( ! V_4 -> V_5 . V_10 )
return - V_34 ;
V_22 = F_26 ( & V_4 -> V_5 ) ;
if ( V_22 )
return V_22 ;
F_27 ( V_30 , V_4 ) ;
F_28 ( V_9 , L_5 ) ;
return V_22 ;
}
static int F_29 ( struct V_29 * V_30 )
{
struct V_1 * V_4 = F_30 ( V_30 ) ;
F_31 ( & V_4 -> V_5 ) ;
return 0 ;
}
