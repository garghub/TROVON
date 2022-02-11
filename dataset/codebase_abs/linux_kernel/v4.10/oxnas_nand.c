static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
return F_4 ( V_6 -> V_7 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_2 * V_8 , int V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_6 ( V_6 -> V_7 , V_8 , V_9 ) ;
}
static void F_7 ( struct V_1 * V_2 , const T_2 * V_8 , int V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_8 ( V_6 -> V_7 , V_8 , V_9 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_10 ,
unsigned int V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
if ( V_11 & V_12 )
F_10 ( V_10 , V_6 -> V_7 + V_13 ) ;
else if ( V_11 & V_14 )
F_10 ( V_10 , V_6 -> V_7 + V_15 ) ;
}
static int F_11 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = V_17 -> V_20 . V_21 ;
struct V_18 * V_22 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_23 * V_24 ;
int V_25 = 0 ;
int V_26 = 0 ;
int V_27 = 0 ;
V_6 = F_12 ( & V_17 -> V_20 , sizeof( struct V_3 ) ,
V_28 ) ;
if ( ! V_6 )
return - V_29 ;
F_13 ( & V_6 -> V_30 ) ;
V_24 = F_14 ( V_17 , V_31 , 0 ) ;
V_6 -> V_7 = F_15 ( & V_17 -> V_20 , V_24 ) ;
if ( F_16 ( V_6 -> V_7 ) )
return F_17 ( V_6 -> V_7 ) ;
V_6 -> V_32 = F_18 ( & V_17 -> V_20 , NULL ) ;
if ( F_16 ( V_6 -> V_32 ) )
V_6 -> V_32 = NULL ;
V_26 = F_19 ( V_19 ) ;
if ( V_26 > 1 )
return - V_33 ;
F_20 ( V_6 -> V_32 ) ;
F_21 ( & V_17 -> V_20 ) ;
F_22 (np, nand_np) {
V_4 = F_12 ( & V_17 -> V_20 , sizeof( struct V_3 ) ,
V_28 ) ;
if ( ! V_4 )
return - V_29 ;
V_4 -> V_34 = & V_6 -> V_30 ;
F_23 ( V_4 , V_22 ) ;
F_24 ( V_4 , V_6 ) ;
V_2 = F_25 ( V_4 ) ;
V_2 -> V_20 . V_35 = & V_17 -> V_20 ;
V_2 -> V_36 = V_4 ;
V_4 -> V_37 = F_9 ;
V_4 -> V_38 = F_5 ;
V_4 -> V_39 = F_1 ;
V_4 -> V_40 = F_7 ;
V_4 -> V_41 = 30 ;
V_27 = F_26 ( V_2 , 1 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_27 ( V_2 , NULL , 0 ) ;
if ( V_27 ) {
F_28 ( V_2 ) ;
return V_27 ;
}
V_6 -> V_42 [ V_25 ] = V_4 ;
++ V_25 ;
}
if ( ! V_25 )
return - V_43 ;
F_29 ( V_17 , V_6 ) ;
return 0 ;
}
static int F_30 ( struct V_16 * V_17 )
{
struct V_5 * V_6 = F_31 ( V_17 ) ;
if ( V_6 -> V_42 [ 0 ] )
F_28 ( F_25 ( V_6 -> V_42 [ 0 ] ) ) ;
F_32 ( V_6 -> V_32 ) ;
return 0 ;
}
