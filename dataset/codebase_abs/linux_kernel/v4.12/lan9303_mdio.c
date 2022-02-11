static void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
V_2 -> V_5 -> V_6 ( V_2 -> V_5 , F_2 ( V_3 ) , F_3 ( V_3 ) , V_4 ) ;
}
static int F_4 ( void * V_7 , T_2 V_3 , T_2 V_4 )
{
struct V_8 * V_9 = (struct V_8 * ) V_7 ;
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
F_5 ( & V_9 -> V_10 -> V_5 -> V_11 ) ;
* V_4 = F_7 ( V_9 -> V_10 , V_3 ) ;
* V_4 |= ( F_7 ( V_9 -> V_10 , V_3 + 2 ) << 16 ) ;
F_6 ( & V_9 -> V_10 -> V_5 -> V_11 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_13 )
{
struct V_8 * V_9 ;
int V_14 ;
V_9 = F_10 ( & V_13 -> V_15 , sizeof( struct V_8 ) ,
V_16 ) ;
if ( ! V_9 )
return - V_17 ;
V_9 -> V_18 . V_19 = F_11 ( & V_13 -> V_15 , NULL , V_9 ,
& V_20 ) ;
if ( F_12 ( V_9 -> V_18 . V_19 ) ) {
V_14 = F_13 ( V_9 -> V_18 . V_19 ) ;
F_14 ( & V_13 -> V_15 , L_1 , V_14 ) ;
return V_14 ;
}
V_9 -> V_10 = V_13 ;
F_15 ( & V_13 -> V_15 , V_9 ) ;
V_9 -> V_18 . V_15 = & V_13 -> V_15 ;
V_14 = F_16 ( & V_9 -> V_18 , V_13 -> V_15 . V_21 ) ;
if ( V_14 != 0 )
return V_14 ;
F_17 ( & V_13 -> V_15 , L_2 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_13 )
{
struct V_8 * V_9 = F_19 ( & V_13 -> V_15 ) ;
if ( ! V_9 )
return;
F_20 ( & V_9 -> V_18 ) ;
}
