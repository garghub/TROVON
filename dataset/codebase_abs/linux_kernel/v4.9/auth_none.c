static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_6 = true ;
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
static int F_6 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
void * V_9 = V_8 -> V_10 ;
void * const V_11 = V_9 + sizeof( V_8 -> V_10 ) ;
int V_12 ;
F_7 ( & V_9 , V_11 , 1 , V_13 ) ;
V_12 = F_8 ( V_2 -> V_14 , & V_9 , V_11 ) ;
if ( V_12 < 0 )
return V_12 ;
F_9 ( & V_9 , V_11 , V_2 -> V_15 , V_13 ) ;
V_8 -> V_16 = V_9 - ( void * ) V_8 -> V_10 ;
F_10 ( L_1 , V_17 , V_8 -> V_16 ) ;
return 0 ;
V_13:
return - V_18 ;
}
static int F_11 ( struct V_1 * V_2 , void * V_10 , void * V_11 )
{
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , int V_19 ,
void * V_10 , void * V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_6 = false ;
return V_19 ;
}
static void F_13 ( struct V_20 * V_21 )
{
F_3 ( V_21 ) ;
}
static int F_14 (
struct V_1 * V_2 , int V_22 ,
struct V_23 * V_24 )
{
struct V_7 * V_8 ;
int V_12 ;
V_8 = F_15 ( sizeof( * V_8 ) , V_25 ) ;
if ( ! V_8 )
return - V_26 ;
V_8 -> V_27 . F_2 = F_13 ;
V_12 = F_6 ( V_2 , V_8 ) ;
if ( V_12 ) {
F_3 ( V_8 ) ;
return V_12 ;
}
V_24 -> V_28 = (struct V_20 * ) V_8 ;
V_24 -> V_29 = V_8 -> V_10 ;
V_24 -> V_30 = V_8 -> V_16 ;
V_24 -> V_31 = V_8 -> V_32 ;
V_24 -> V_33 = sizeof ( V_8 -> V_32 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_10 ( L_2 , V_2 ) ;
V_4 = F_17 ( sizeof( * V_4 ) , V_25 ) ;
if ( ! V_4 )
return - V_26 ;
V_4 -> V_6 = true ;
V_2 -> V_34 = V_35 ;
V_2 -> V_5 = V_4 ;
V_2 -> V_36 = & V_37 ;
return 0 ;
}
