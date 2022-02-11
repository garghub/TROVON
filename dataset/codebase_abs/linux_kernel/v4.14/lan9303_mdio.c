static void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
V_2 -> V_5 -> V_6 ( V_2 -> V_5 , F_2 ( V_3 ) , F_3 ( V_3 ) , V_4 ) ;
}
static int F_4 ( void * V_7 , T_2 V_3 , T_2 V_4 )
{
struct V_8 * V_9 = (struct V_8 * ) V_7 ;
V_3 <<= 2 ;
F_5 ( & V_9 -> V_10 -> V_5 -> V_11 ) ;
F_1 ( V_9 -> V_10 , V_3 , V_4 & 0xffff ) ;
F_1 ( V_9 -> V_10 , V_3 + 2 , ( V_4 >> 16 ) & 0xffff ) ;
F_6 ( & V_9 -> V_10 -> V_5 -> V_11 ) ;
return 0 ;
}
static T_1 F_7 ( struct V_1 * V_2 , int V_3 )
{
return V_2 -> V_5 -> V_12 ( V_2 -> V_5 , F_2 ( V_3 ) , F_3 ( V_3 ) ) ;
}
static int F_8 ( void * V_7 , T_2 V_3 , T_2 * V_4 )
{
struct V_8 * V_9 = (struct V_8 * ) V_7 ;
V_3 <<= 2 ;
F_5 ( & V_9 -> V_10 -> V_5 -> V_11 ) ;
* V_4 = F_7 ( V_9 -> V_10 , V_3 ) ;
* V_4 |= ( F_7 ( V_9 -> V_10 , V_3 + 2 ) << 16 ) ;
F_6 ( & V_9 -> V_10 -> V_5 -> V_11 ) ;
return 0 ;
}
int F_9 ( struct V_13 * V_14 , int V_15 , int V_3 , T_1 V_4 )
{
struct V_8 * V_9 = F_10 ( V_14 -> V_16 ) ;
return F_11 ( V_9 -> V_10 -> V_5 , V_15 , V_3 , V_4 ) ;
}
int F_12 ( struct V_13 * V_14 , int V_15 , int V_3 )
{
struct V_8 * V_9 = F_10 ( V_14 -> V_16 ) ;
return F_13 ( V_9 -> V_10 -> V_5 , V_15 , V_3 ) ;
}
static int F_14 ( struct V_1 * V_17 )
{
struct V_8 * V_9 ;
int V_18 ;
V_9 = F_15 ( & V_17 -> V_16 , sizeof( struct V_8 ) ,
V_19 ) ;
if ( ! V_9 )
return - V_20 ;
V_9 -> V_14 . V_21 = F_16 ( & V_17 -> V_16 , NULL , V_9 ,
& V_22 ) ;
if ( F_17 ( V_9 -> V_14 . V_21 ) ) {
V_18 = F_18 ( V_9 -> V_14 . V_21 ) ;
F_19 ( & V_17 -> V_16 , L_1 , V_18 ) ;
return V_18 ;
}
V_9 -> V_10 = V_17 ;
F_20 ( & V_17 -> V_16 , V_9 ) ;
V_9 -> V_14 . V_16 = & V_17 -> V_16 ;
V_9 -> V_14 . V_23 = & V_24 ;
V_18 = F_21 ( & V_9 -> V_14 , V_17 -> V_16 . V_25 ) ;
if ( V_18 != 0 )
return V_18 ;
F_22 ( & V_17 -> V_16 , L_2 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_17 )
{
struct V_8 * V_9 = F_10 ( & V_17 -> V_16 ) ;
if ( ! V_9 )
return;
F_24 ( & V_9 -> V_14 ) ;
}
