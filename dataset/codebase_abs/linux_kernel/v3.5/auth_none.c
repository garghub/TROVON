static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_6 = true ;
V_4 -> V_7 = false ;
}
static void F_2 ( struct V_1 * V_2 )
{
F_3 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return ! V_4 -> V_6 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return V_4 -> V_6 ;
}
static int F_6 ( struct V_1 * V_2 , int V_8 ,
void * V_9 , void * V_10 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_6 = false ;
return V_8 ;
}
static int F_7 (
struct V_1 * V_2 , int V_11 ,
struct V_12 * V_13 )
{
struct V_3 * V_14 = V_2 -> V_5 ;
struct V_15 * V_16 = & V_14 -> V_16 ;
void * V_17 , * V_10 ;
int V_18 ;
if ( ! V_14 -> V_7 ) {
V_17 = V_16 -> V_9 ;
V_10 = V_17 + sizeof( V_16 -> V_9 ) ;
F_8 ( & V_17 , 1 ) ;
V_18 = F_9 ( V_2 -> V_19 , & V_17 , V_10 - 8 ) ;
if ( V_18 < 0 )
goto V_20;
F_10 ( & V_17 , V_10 , sizeof( V_21 ) , V_22 ) ;
F_11 ( & V_17 , V_2 -> V_23 ) ;
V_16 -> V_24 = V_17 - ( void * ) V_16 -> V_9 ;
V_14 -> V_7 = true ;
F_12 ( L_1 , V_16 -> V_24 ) ;
}
V_13 -> V_25 = (struct V_26 * ) V_16 ;
V_13 -> V_27 = V_16 -> V_9 ;
V_13 -> V_28 = V_16 -> V_24 ;
V_13 -> V_29 = V_16 -> V_30 ;
V_13 -> V_31 = sizeof ( V_16 -> V_30 ) ;
return 0 ;
V_22:
V_18 = - V_32 ;
V_20:
return V_18 ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_26 * V_33 )
{
}
int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_12 ( L_2 , V_2 ) ;
V_4 = F_15 ( sizeof( * V_4 ) , V_34 ) ;
if ( ! V_4 )
return - V_35 ;
V_4 -> V_6 = true ;
V_4 -> V_7 = false ;
V_2 -> V_36 = V_37 ;
V_2 -> V_5 = V_4 ;
V_2 -> V_38 = & V_39 ;
return 0 ;
}
