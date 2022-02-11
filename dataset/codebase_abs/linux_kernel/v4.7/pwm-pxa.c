static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , struct V_4 * V_5 ,
int V_6 , int V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
unsigned long long V_9 ;
unsigned long V_10 , V_11 , V_12 , V_13 ;
unsigned long V_14 ;
int V_15 ;
V_14 = V_5 -> V_16 ? 0x10 : 0 ;
V_9 = F_4 ( V_8 -> V_17 ) ;
V_9 = V_9 * V_7 ;
F_5 ( V_9 , 1000000000 ) ;
V_10 = V_9 ;
if ( V_10 < 1 )
V_10 = 1 ;
V_11 = ( V_10 - 1 ) / 1024 ;
V_12 = V_10 / ( V_11 + 1 ) - 1 ;
if ( V_11 > 63 )
return - V_18 ;
if ( V_6 == V_7 )
V_13 = V_19 ;
else
V_13 = ( V_12 + 1 ) * V_6 / V_7 ;
V_15 = F_6 ( V_8 -> V_17 ) ;
if ( V_15 < 0 )
return V_15 ;
F_7 ( V_11 , V_8 -> V_20 + V_14 + V_21 ) ;
F_7 ( V_13 , V_8 -> V_20 + V_14 + V_22 ) ;
F_7 ( V_12 , V_8 -> V_20 + V_14 + V_23 ) ;
F_8 ( V_8 -> V_17 ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
return F_6 ( V_8 -> V_17 ) ;
}
static void F_10 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_8 ( V_8 -> V_17 ) ;
}
static const struct V_24 * F_11 ( struct V_25 * V_26 )
{
const struct V_27 * V_28 = F_12 ( V_29 , V_26 ) ;
return V_28 ? V_28 -> V_30 : NULL ;
}
static struct V_4 *
F_13 ( struct V_2 * V_8 , const struct V_31 * args )
{
struct V_4 * V_5 ;
V_5 = F_14 ( V_8 , 0 , NULL ) ;
if ( F_15 ( V_5 ) )
return V_5 ;
V_5 -> args . V_32 = args -> args [ 0 ] ;
return V_5 ;
}
static int F_16 ( struct V_33 * V_34 )
{
const struct V_24 * V_28 = F_17 ( V_34 ) ;
struct V_1 * V_5 ;
struct V_35 * V_36 ;
int V_37 = 0 ;
if ( F_18 ( V_38 ) && V_28 == NULL )
V_28 = F_11 ( & V_34 -> V_26 ) ;
if ( V_28 == NULL )
return - V_18 ;
V_5 = F_19 ( & V_34 -> V_26 , sizeof( * V_5 ) , V_39 ) ;
if ( V_5 == NULL )
return - V_40 ;
V_5 -> V_17 = F_20 ( & V_34 -> V_26 , NULL ) ;
if ( F_15 ( V_5 -> V_17 ) )
return F_21 ( V_5 -> V_17 ) ;
V_5 -> V_3 . V_26 = & V_34 -> V_26 ;
V_5 -> V_3 . V_41 = & V_42 ;
V_5 -> V_3 . V_43 = - 1 ;
V_5 -> V_3 . V_44 = ( V_28 -> V_45 & V_46 ) ? 2 : 1 ;
if ( F_18 ( V_38 ) ) {
V_5 -> V_3 . V_47 = F_13 ;
V_5 -> V_3 . V_48 = 1 ;
}
V_36 = F_22 ( V_34 , V_49 , 0 ) ;
V_5 -> V_20 = F_23 ( & V_34 -> V_26 , V_36 ) ;
if ( F_15 ( V_5 -> V_20 ) )
return F_21 ( V_5 -> V_20 ) ;
V_37 = F_24 ( & V_5 -> V_3 ) ;
if ( V_37 < 0 ) {
F_25 ( & V_34 -> V_26 , L_1 , V_37 ) ;
return V_37 ;
}
F_26 ( V_34 , V_5 ) ;
return 0 ;
}
static int F_27 ( struct V_33 * V_34 )
{
struct V_1 * V_3 ;
V_3 = F_28 ( V_34 ) ;
if ( V_3 == NULL )
return - V_50 ;
return F_29 ( & V_3 -> V_3 ) ;
}
