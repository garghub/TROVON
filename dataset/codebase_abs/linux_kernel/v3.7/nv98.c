static int
F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
struct V_9 * V_10 ;
int V_11 ;
V_11 = F_2 ( V_2 , V_3 , V_5 , NULL ,
0 , 0 , 0 , & V_10 ) ;
* V_8 = F_3 ( V_10 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static void
F_4 ( struct V_1 * V_12 )
{
struct V_9 * V_10 = ( void * ) V_12 ;
F_5 ( & V_10 -> V_13 ) ;
}
static int
F_6 ( struct V_1 * V_12 )
{
struct V_9 * V_10 = ( void * ) V_12 ;
int V_11 ;
V_11 = F_7 ( & V_10 -> V_13 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static int
F_8 ( struct V_1 * V_12 , bool V_14 )
{
struct V_9 * V_10 = ( void * ) V_12 ;
return F_9 ( & V_10 -> V_13 , V_14 ) ;
}
static void
F_10 ( struct V_15 * V_16 )
{
}
static int
F_11 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
struct V_17 * V_10 ;
int V_11 ;
V_11 = F_12 ( V_2 , V_3 , V_5 , & V_10 ) ;
* V_8 = F_3 ( V_10 ) ;
if ( V_11 )
return V_11 ;
F_13 ( V_10 ) -> V_18 = 0x00400002 ;
F_13 ( V_10 ) -> V_19 = F_10 ;
F_14 ( V_10 ) -> V_20 = & V_21 ;
F_14 ( V_10 ) -> V_22 = V_23 ;
return 0 ;
}
static void
F_15 ( struct V_1 * V_12 )
{
struct V_17 * V_10 = ( void * ) V_12 ;
F_16 ( & V_10 -> V_13 ) ;
}
static int
F_17 ( struct V_1 * V_12 )
{
struct V_17 * V_10 = ( void * ) V_12 ;
int V_11 ;
V_11 = F_18 ( & V_10 -> V_13 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static int
F_19 ( struct V_1 * V_12 , bool V_14 )
{
struct V_17 * V_10 = ( void * ) V_12 ;
return F_20 ( & V_10 -> V_13 , V_14 ) ;
}
