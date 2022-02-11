static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 -> V_6 )
F_3 ( V_4 -> V_5 -> V_6 , V_2 -> V_7 ,
false ) ;
V_4 -> V_8 = false ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 -> V_6 )
F_3 ( V_4 -> V_5 -> V_6 , V_2 -> V_7 ,
true ) ;
V_4 -> V_8 = true ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_13 * V_14 = & V_10 -> V_14 ;
if ( V_4 -> V_5 -> V_6 )
F_6 ( V_4 -> V_5 -> V_6 ,
V_14 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_13 * V_15 ,
struct V_13 * V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_8 ( V_2 -> V_7 , V_4 -> V_5 -> V_16 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_8 )
F_1 ( V_2 ) ;
F_10 ( V_2 ) ;
}
int F_11 ( struct V_17 * V_18 ,
struct V_19 * V_5 , struct V_20 * V_21 )
{
struct V_1 * V_2 = F_12 ( V_5 ) ;
struct V_22 * V_23 ;
struct V_3 * V_4 ;
int V_24 ;
V_4 = F_13 ( V_18 -> V_25 , sizeof( * V_4 ) , V_26 ) ;
if ( V_4 == NULL )
return - V_27 ;
V_23 = F_14 ( V_21 ) ;
if ( ! V_23 )
return - V_28 ;
V_24 = F_15 ( V_18 -> V_29 , V_2 , & V_30 ,
V_31 , NULL ) ;
if ( V_24 < 0 )
return V_24 ;
F_16 ( V_2 , & V_32 ) ;
V_5 -> V_33 = V_4 ;
V_4 -> V_5 = V_5 ;
V_23 -> V_2 = V_2 ;
V_2 -> V_23 = V_23 ;
V_24 = F_17 ( V_18 -> V_29 , V_23 ) ;
if ( V_24 ) {
F_10 ( V_2 ) ;
return V_24 ;
}
return 0 ;
}
