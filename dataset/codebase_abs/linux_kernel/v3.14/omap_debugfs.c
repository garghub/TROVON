static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 -> V_8 ;
struct V_10 * V_11 = V_8 -> V_12 ;
int V_13 ;
V_13 = F_2 ( & V_8 -> V_14 ) ;
if ( V_13 )
return V_13 ;
F_3 ( V_2 , L_1 ) ;
F_4 ( & V_11 -> V_15 , V_2 ) ;
F_5 ( & V_8 -> V_14 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 -> V_8 ;
return F_7 ( V_2 , & V_8 -> V_16 -> V_17 ) ;
}
static int F_8 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_7 * V_8 = V_5 -> V_9 -> V_8 ;
struct V_10 * V_11 = V_8 -> V_12 ;
struct V_18 * V_19 ;
F_3 ( V_2 , L_2 ) ;
F_9 ( V_11 -> V_20 -> V_19 , V_2 ) ;
F_10 ( & V_8 -> V_21 . V_22 ) ;
F_11 (fb, &dev->mode_config.fb_list, head) {
if ( V_19 == V_11 -> V_20 -> V_19 )
continue;
F_3 ( V_2 , L_3 ) ;
F_9 ( V_19 , V_2 ) ;
}
F_5 ( & V_8 -> V_21 . V_22 ) ;
return 0 ;
}
int F_12 ( struct V_23 * V_9 )
{
struct V_7 * V_8 = V_9 -> V_8 ;
int V_13 ;
V_13 = F_13 ( V_24 ,
F_14 ( V_24 ) ,
V_9 -> V_25 , V_9 ) ;
if ( V_13 ) {
F_15 ( V_8 -> V_8 , L_4 ) ;
return V_13 ;
}
if ( F_16 () )
V_13 = F_13 ( V_26 ,
F_14 ( V_26 ) ,
V_9 -> V_25 , V_9 ) ;
if ( V_13 ) {
F_15 ( V_8 -> V_8 , L_5 ) ;
return V_13 ;
}
return V_13 ;
}
void F_17 ( struct V_23 * V_9 )
{
F_18 ( V_24 ,
F_14 ( V_24 ) , V_9 ) ;
if ( F_16 () )
F_18 ( V_26 ,
F_14 ( V_26 ) , V_9 ) ;
}
