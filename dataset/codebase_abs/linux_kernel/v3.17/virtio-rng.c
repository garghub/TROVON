static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
if ( ! F_2 ( V_4 -> V_2 , & V_4 -> V_7 ) )
return;
F_3 ( & V_4 -> V_8 ) ;
}
static void F_4 ( struct V_3 * V_4 , T_1 * V_9 , T_2 V_10 )
{
struct V_11 V_12 ;
F_5 ( & V_12 , V_9 , V_10 ) ;
F_6 ( V_4 -> V_2 , & V_12 , 1 , V_9 , V_13 ) ;
F_7 ( V_4 -> V_2 ) ;
}
static int F_8 ( struct V_14 * V_15 , void * V_9 , T_2 V_10 , bool V_16 )
{
int V_17 ;
struct V_3 * V_4 = (struct V_3 * ) V_15 -> V_6 ;
if ( V_4 -> V_18 )
return - V_19 ;
if ( ! V_4 -> V_20 ) {
V_4 -> V_20 = true ;
F_9 ( & V_4 -> V_8 ) ;
F_4 ( V_4 , V_9 , V_10 ) ;
}
if ( ! V_16 )
return 0 ;
V_17 = F_10 ( & V_4 -> V_8 ) ;
if ( V_17 < 0 )
return V_17 ;
V_4 -> V_20 = false ;
return V_4 -> V_7 ;
}
static void F_11 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = (struct V_3 * ) V_15 -> V_6 ;
if ( V_4 -> V_20 )
F_12 ( & V_4 -> V_8 ) ;
}
static int F_13 ( struct V_21 * V_5 )
{
int V_22 , V_23 ;
struct V_3 * V_4 = NULL ;
V_4 = F_14 ( sizeof( struct V_3 ) , V_13 ) ;
if ( ! V_4 )
return - V_24 ;
V_4 -> V_23 = V_23 = F_15 ( & V_25 , 0 , 0 , V_13 ) ;
if ( V_23 < 0 ) {
F_16 ( V_4 ) ;
return V_23 ;
}
sprintf ( V_4 -> V_26 , L_1 , V_23 ) ;
F_9 ( & V_4 -> V_8 ) ;
V_4 -> V_14 = (struct V_14 ) {
. V_27 = F_8 ,
. V_28 = F_11 ,
. V_6 = ( unsigned long ) V_4 ,
. V_26 = V_4 -> V_26 ,
. V_29 = 1000 ,
} ;
V_5 -> V_6 = V_4 ;
V_4 -> V_2 = F_17 ( V_5 , F_1 , L_2 ) ;
if ( F_18 ( V_4 -> V_2 ) ) {
V_22 = F_19 ( V_4 -> V_2 ) ;
V_4 -> V_2 = NULL ;
F_16 ( V_4 ) ;
F_20 ( & V_25 , V_23 ) ;
return V_22 ;
}
return 0 ;
}
static void F_21 ( struct V_21 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_6 ;
V_4 -> V_18 = true ;
V_4 -> V_7 = 0 ;
F_3 ( & V_4 -> V_8 ) ;
V_5 -> V_30 -> V_31 ( V_5 ) ;
V_4 -> V_20 = false ;
if ( V_4 -> V_32 )
F_22 ( & V_4 -> V_14 ) ;
V_5 -> V_30 -> V_33 ( V_5 ) ;
F_20 ( & V_25 , V_4 -> V_23 ) ;
F_16 ( V_4 ) ;
}
static int F_23 ( struct V_21 * V_5 )
{
return F_13 ( V_5 ) ;
}
static void F_24 ( struct V_21 * V_5 )
{
F_21 ( V_5 ) ;
}
static void F_25 ( struct V_21 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_6 ;
int V_22 ;
V_22 = F_26 ( & V_4 -> V_14 ) ;
if ( ! V_22 )
V_4 -> V_32 = true ;
}
static int F_27 ( struct V_21 * V_5 )
{
F_21 ( V_5 ) ;
return 0 ;
}
static int F_28 ( struct V_21 * V_5 )
{
return F_13 ( V_5 ) ;
}
