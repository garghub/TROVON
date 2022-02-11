static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return 32768 ;
}
static int F_2 ( struct V_1 * V_2 , bool V_4 )
{
struct V_5 * V_5 = F_3 ( V_2 ,
struct V_5 ,
V_6 ) ;
struct V_7 * V_7 = V_5 -> V_7 ;
return F_4 ( V_7 -> V_8 , V_9 ,
V_10 , V_4 ? V_10 : 0 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , true ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_2 ( V_2 , false ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_3 ( V_2 ,
struct V_5 ,
V_6 ) ;
struct V_7 * V_7 = V_5 -> V_7 ;
T_1 V_11 ;
int V_12 = F_8 ( V_7 -> V_8 , V_9 , & V_11 ) ;
if ( V_12 < 0 )
return V_12 ;
return ( V_11 & V_10 ) ? 1 : 0 ;
}
static struct V_1 *
F_9 ( struct V_13 * V_14 , void * V_15 )
{
struct V_5 * V_5 = V_15 ;
unsigned int V_16 = V_14 -> args [ 0 ] ;
if ( V_16 >= 2 ) {
F_10 ( L_1 , V_17 , V_16 ) ;
return F_11 ( - V_18 ) ;
}
return V_16 ? & V_5 -> V_6 : & V_5 -> V_19 ;
}
static int F_12 ( struct V_20 * V_21 )
{
struct V_7 * V_7 = F_13 ( V_21 -> V_22 . V_23 ) ;
struct V_24 * V_25 = V_7 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_22 . V_29 ;
struct V_30 V_31 = {} ;
struct V_5 * V_5 ;
int V_12 ;
V_5 = F_14 ( & V_25 -> V_22 ,
sizeof( * V_5 ) , V_32 ) ;
if ( ! V_5 )
return - V_33 ;
V_5 -> V_7 = V_7 ;
V_31 . V_34 = NULL ;
V_31 . V_35 = 0 ;
V_31 . V_36 = L_2 ;
V_31 . V_37 = & V_38 ;
V_5 -> V_19 . V_31 = & V_31 ;
F_15 ( V_28 , L_3 ,
0 , & V_31 . V_36 ) ;
V_12 = F_16 ( & V_25 -> V_22 , & V_5 -> V_19 ) ;
if ( V_12 )
return V_12 ;
V_31 . V_36 = L_4 ;
V_31 . V_37 = & V_39 ;
V_5 -> V_6 . V_31 = & V_31 ;
F_15 ( V_28 , L_3 ,
1 , & V_31 . V_36 ) ;
V_12 = F_16 ( & V_25 -> V_22 , & V_5 -> V_6 ) ;
if ( V_12 )
return V_12 ;
return F_17 ( V_28 , F_9 , V_5 ) ;
}
static int F_18 ( struct V_20 * V_21 )
{
struct V_7 * V_7 = F_13 ( V_21 -> V_22 . V_23 ) ;
struct V_24 * V_25 = V_7 -> V_26 ;
struct V_27 * V_28 = V_25 -> V_22 . V_29 ;
F_19 ( V_28 ) ;
return 0 ;
}
