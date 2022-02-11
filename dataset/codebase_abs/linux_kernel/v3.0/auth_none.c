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
struct V_12 * * V_13 ,
void * * V_9 , T_1 * V_14 ,
void * * V_15 , T_1 * V_16 )
{
struct V_3 * V_17 = V_2 -> V_5 ;
struct V_18 * V_19 = & V_17 -> V_19 ;
void * V_20 , * V_10 ;
int V_21 ;
if ( ! V_17 -> V_7 ) {
V_20 = V_19 -> V_9 ;
V_10 = V_20 + sizeof( V_19 -> V_9 ) ;
F_8 ( & V_20 , 1 ) ;
V_21 = F_9 ( V_2 -> V_22 , & V_20 , V_10 - 8 ) ;
if ( V_21 < 0 )
goto V_23;
F_10 ( & V_20 , V_10 , sizeof( V_24 ) , V_25 ) ;
F_11 ( & V_20 , V_2 -> V_26 ) ;
V_19 -> V_27 = V_20 - ( void * ) V_19 -> V_9 ;
V_17 -> V_7 = true ;
F_12 ( L_1 , V_19 -> V_27 ) ;
}
* V_13 = (struct V_12 * ) V_19 ;
* V_9 = V_19 -> V_9 ;
* V_14 = V_19 -> V_27 ;
* V_15 = V_19 -> V_15 ;
* V_16 = sizeof( V_19 -> V_15 ) ;
return 0 ;
V_25:
V_21 = - V_28 ;
V_23:
return V_21 ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
}
int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_12 ( L_2 , V_2 ) ;
V_4 = F_15 ( sizeof( * V_4 ) , V_29 ) ;
if ( ! V_4 )
return - V_30 ;
V_4 -> V_6 = true ;
V_4 -> V_7 = false ;
V_2 -> V_31 = V_32 ;
V_2 -> V_5 = V_4 ;
V_2 -> V_33 = & V_34 ;
return 0 ;
}
