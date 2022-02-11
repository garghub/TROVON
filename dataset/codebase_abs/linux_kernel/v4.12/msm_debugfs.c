static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
if ( V_9 ) {
F_2 ( V_4 , L_1 , V_9 -> V_10 ) ;
F_3 ( & V_9 -> V_11 -> V_2 ) ;
V_9 -> V_12 -> V_13 ( V_9 , V_4 ) ;
F_4 ( & V_9 -> V_11 -> V_2 ) ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
if ( V_9 ) {
F_2 ( V_4 , L_2 , V_9 -> V_10 ) ;
F_6 ( & V_9 -> V_14 , V_4 ) ;
}
F_2 ( V_4 , L_3 ) ;
F_6 ( & V_6 -> V_15 , V_4 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_16 V_17 = F_8 ( V_4 ) ;
F_9 ( & V_2 -> V_18 -> V_19 , & V_17 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_20 * V_21 , * V_22 = NULL ;
if ( V_6 -> V_23 ) {
F_2 ( V_4 , L_4 ) ;
V_22 = V_6 -> V_23 -> V_21 ;
F_11 ( V_22 , V_4 ) ;
}
F_12 ( & V_2 -> V_24 . V_25 ) ;
F_13 (fb, &dev->mode_config.fb_list, head) {
if ( V_21 == V_22 )
continue;
F_2 ( V_4 , L_5 ) ;
F_11 ( V_21 , V_4 ) ;
}
F_14 ( & V_2 -> V_24 . V_25 ) ;
return 0 ;
}
static int F_15 ( struct V_3 * V_4 , void * V_26 )
{
struct V_27 * V_28 = (struct V_27 * ) V_4 -> V_29 ;
struct V_1 * V_2 = V_28 -> V_30 -> V_2 ;
int (* V_13)( struct V_1 * V_2 , struct V_3 * V_4 ) =
V_28 -> V_31 -> V_32 ;
int V_33 ;
V_33 = F_16 ( & V_2 -> V_34 ) ;
if ( V_33 )
return V_33 ;
V_33 = V_13 ( V_2 , V_4 ) ;
F_14 ( & V_2 -> V_34 ) ;
return V_33 ;
}
static int F_17 ( struct V_35 * V_30 )
{
int V_33 ;
if ( ! V_30 )
return 0 ;
V_33 = F_18 ( V_30 ) ;
if ( V_33 ) {
F_19 ( V_30 -> V_2 -> V_2 , L_6 ) ;
return V_33 ;
}
V_33 = F_20 ( V_30 ) ;
if ( V_33 ) {
F_19 ( V_30 -> V_2 -> V_2 , L_7 ) ;
return V_33 ;
}
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
int V_33 ;
V_33 = F_17 ( V_2 -> V_36 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_17 ( V_2 -> V_37 ) ;
if ( V_33 )
return V_33 ;
V_33 = F_17 ( V_2 -> V_38 ) ;
return V_33 ;
}
int F_22 ( struct V_35 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_33 ;
V_33 = F_23 ( V_39 ,
F_24 ( V_39 ) ,
V_30 -> V_40 , V_30 ) ;
if ( V_33 ) {
F_19 ( V_2 -> V_2 , L_8 ) ;
return V_33 ;
}
if ( V_6 -> V_41 -> V_12 -> V_42 )
V_33 = V_6 -> V_41 -> V_12 -> V_42 ( V_6 -> V_41 , V_30 ) ;
return V_33 ;
}
