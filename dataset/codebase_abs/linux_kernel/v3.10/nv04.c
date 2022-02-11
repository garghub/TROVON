static int
F_1 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_4 , T_1 V_5 )
{
struct V_1 * V_6 = ( void * ) F_2 ( V_2 -> V_7 ) ;
struct V_8 * V_9 = ( void * ) V_6 -> V_7 ;
F_3 ( & V_9 -> V_10 , * ( T_1 * ) V_4 ) ;
return 0 ;
}
static int
F_4 ( struct V_1 * V_2 , T_1 V_3 ,
void * args , T_1 V_5 )
{
struct V_11 * V_12 = ( void * ) F_2 ( V_2 -> V_7 ) ;
if ( V_12 -> V_13 . V_14 )
return V_12 -> V_13 . V_14 ( V_12 -> V_13 . V_15 ) ;
return - V_16 ;
}
static int
F_5 ( struct V_1 * V_7 ,
struct V_1 * V_17 ,
struct V_18 * V_19 , void * V_4 , T_1 V_5 ,
struct V_1 * * V_20 )
{
struct V_11 * V_12 ;
int V_21 ;
V_21 = F_6 ( V_7 , V_17 , V_19 , & V_12 ) ;
* V_20 = F_7 ( V_12 ) ;
if ( V_21 )
return V_21 ;
return 0 ;
}
void
F_8 ( struct V_22 * V_23 )
{
F_9 ( V_23 , 0x000100 , 0x80000000 , 0x00000000 ) ;
}
static int
F_10 ( struct V_1 * V_7 , struct V_1 * V_17 ,
struct V_18 * V_19 , void * V_4 , T_1 V_5 ,
struct V_1 * * V_20 )
{
struct V_24 * V_25 ;
int V_21 ;
V_21 = F_11 ( V_7 , V_17 , V_19 , & V_25 ) ;
* V_20 = F_7 ( V_25 ) ;
if ( V_21 )
return V_21 ;
F_12 ( V_25 ) -> V_26 = & V_27 ;
F_12 ( V_25 ) -> V_28 = V_29 ;
F_13 ( V_25 ) -> V_30 = F_8 ;
return 0 ;
}
