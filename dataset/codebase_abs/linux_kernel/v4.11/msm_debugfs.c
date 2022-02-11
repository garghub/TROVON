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
struct V_15 V_16 = F_6 ( V_4 ) ;
F_7 ( & V_2 -> V_17 -> V_18 , & V_16 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_19 * V_20 , * V_21 = NULL ;
if ( V_6 -> V_22 ) {
F_2 ( V_4 , L_4 ) ;
V_21 = V_6 -> V_22 -> V_20 ;
F_9 ( V_21 , V_4 ) ;
}
F_10 ( & V_2 -> V_23 . V_24 ) ;
F_11 (fb, &dev->mode_config.fb_list, head) {
if ( V_20 == V_21 )
continue;
F_2 ( V_4 , L_5 ) ;
F_9 ( V_20 , V_4 ) ;
}
F_12 ( & V_2 -> V_23 . V_24 ) ;
return 0 ;
}
static int F_13 ( struct V_3 * V_4 , void * V_25 )
{
struct V_26 * V_27 = (struct V_26 * ) V_4 -> V_28 ;
struct V_1 * V_2 = V_27 -> V_29 -> V_2 ;
int (* V_12)( struct V_1 * V_2 , struct V_3 * V_4 ) =
V_27 -> V_30 -> V_31 ;
int V_32 ;
V_32 = F_14 ( & V_2 -> V_33 ) ;
if ( V_32 )
return V_32 ;
V_32 = V_12 ( V_2 , V_4 ) ;
F_12 ( & V_2 -> V_33 ) ;
return V_32 ;
}
static int F_15 ( struct V_34 * V_29 )
{
int V_32 ;
if ( ! V_29 )
return 0 ;
V_32 = F_16 ( V_29 ) ;
if ( V_32 ) {
F_17 ( V_29 -> V_2 -> V_2 , L_6 ) ;
return V_32 ;
}
V_32 = F_18 ( V_29 ) ;
if ( V_32 ) {
F_17 ( V_29 -> V_2 -> V_2 , L_7 ) ;
return V_32 ;
}
return 0 ;
}
int F_19 ( struct V_1 * V_2 )
{
int V_32 ;
V_32 = F_15 ( V_2 -> V_35 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_15 ( V_2 -> V_36 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_15 ( V_2 -> V_37 ) ;
return V_32 ;
}
int F_20 ( struct V_34 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_32 ;
V_32 = F_21 ( V_38 ,
F_22 ( V_38 ) ,
V_29 -> V_39 , V_29 ) ;
if ( V_32 ) {
F_17 ( V_2 -> V_2 , L_8 ) ;
return V_32 ;
}
if ( V_6 -> V_40 -> V_11 -> V_41 )
V_32 = V_6 -> V_40 -> V_11 -> V_41 ( V_6 -> V_40 , V_29 ) ;
return V_32 ;
}
void F_23 ( struct V_34 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_24 ( V_38 ,
F_22 ( V_38 ) , V_29 ) ;
if ( ! V_6 )
return;
if ( V_6 -> V_40 -> V_11 -> V_42 )
V_6 -> V_40 -> V_11 -> V_42 ( V_6 -> V_40 , V_29 ) ;
F_25 ( V_29 ) ;
F_26 ( V_29 ) ;
}
