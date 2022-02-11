static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
if ( V_9 ) {
F_2 ( V_4 , L_1 , V_9 -> V_10 ) ;
V_9 -> V_11 -> V_12 ( V_9 , V_4 ) ;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
if ( V_9 ) {
F_2 ( V_4 , L_2 , V_9 -> V_10 ) ;
F_4 ( & V_9 -> V_13 , V_4 ) ;
}
F_2 ( V_4 , L_3 ) ;
F_4 ( & V_6 -> V_14 , V_4 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_6 ( V_4 , & V_2 -> V_15 -> V_16 ) ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_17 * V_18 , * V_19 = NULL ;
if ( V_6 -> V_20 ) {
F_2 ( V_4 , L_4 ) ;
V_19 = V_6 -> V_20 -> V_18 ;
F_8 ( V_19 , V_4 ) ;
}
F_9 ( & V_2 -> V_21 . V_22 ) ;
F_10 (fb, &dev->mode_config.fb_list, head) {
if ( V_18 == V_19 )
continue;
F_2 ( V_4 , L_5 ) ;
F_8 ( V_18 , V_4 ) ;
}
F_11 ( & V_2 -> V_21 . V_22 ) ;
return 0 ;
}
static int F_12 ( struct V_3 * V_4 , void * V_23 )
{
struct V_24 * V_25 = (struct V_24 * ) V_4 -> V_26 ;
struct V_1 * V_2 = V_25 -> V_27 -> V_2 ;
int (* V_12)( struct V_1 * V_2 , struct V_3 * V_4 ) =
V_25 -> V_28 -> V_29 ;
int V_30 ;
V_30 = F_13 ( & V_2 -> V_31 ) ;
if ( V_30 )
return V_30 ;
V_30 = V_12 ( V_2 , V_4 ) ;
F_11 ( & V_2 -> V_31 ) ;
return V_30 ;
}
static int F_14 ( struct V_32 * V_27 )
{
int V_30 ;
if ( ! V_27 )
return 0 ;
V_30 = F_15 ( V_27 ) ;
if ( V_30 ) {
F_16 ( V_27 -> V_2 -> V_2 , L_6 ) ;
return V_30 ;
}
V_30 = F_17 ( V_27 ) ;
if ( V_30 ) {
F_16 ( V_27 -> V_2 -> V_2 , L_7 ) ;
return V_30 ;
}
return 0 ;
}
int F_18 ( struct V_1 * V_2 )
{
int V_30 ;
V_30 = F_14 ( V_2 -> V_33 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_14 ( V_2 -> V_34 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_14 ( V_2 -> V_35 ) ;
return V_30 ;
}
int F_19 ( struct V_32 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_30 ;
V_30 = F_20 ( V_36 ,
F_21 ( V_36 ) ,
V_27 -> V_37 , V_27 ) ;
if ( V_30 ) {
F_16 ( V_2 -> V_2 , L_8 ) ;
return V_30 ;
}
if ( V_6 -> V_38 -> V_11 -> V_39 )
V_30 = V_6 -> V_38 -> V_11 -> V_39 ( V_6 -> V_38 , V_27 ) ;
return V_30 ;
}
void F_22 ( struct V_32 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_23 ( V_36 ,
F_21 ( V_36 ) , V_27 ) ;
if ( ! V_6 )
return;
if ( V_6 -> V_38 -> V_11 -> V_40 )
V_6 -> V_38 -> V_11 -> V_40 ( V_6 -> V_38 , V_27 ) ;
F_24 ( V_27 ) ;
F_25 ( V_27 ) ;
}
