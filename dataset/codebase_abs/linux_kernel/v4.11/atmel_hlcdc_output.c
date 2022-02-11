static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 ,
V_3 ) ;
}
static inline struct V_1 *
F_3 ( struct V_4 * V_5 )
{
return F_2 ( V_5 , struct V_1 , V_5 ) ;
}
static void F_4 ( struct V_4 * V_5 )
{
struct V_1 * V_6 =
F_3 ( V_5 ) ;
if ( V_6 -> V_7 ) {
F_5 ( V_6 -> V_7 ) ;
F_6 ( V_6 -> V_7 ) ;
}
}
static void F_7 ( struct V_4 * V_5 )
{
struct V_1 * V_6 =
F_3 ( V_5 ) ;
if ( V_6 -> V_7 ) {
F_8 ( V_6 -> V_7 ) ;
F_9 ( V_6 -> V_7 ) ;
}
}
static void F_10 ( struct V_4 * V_5 )
{
F_11 ( V_5 ) ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_6 =
F_1 ( V_3 ) ;
if ( V_6 -> V_7 )
return V_6 -> V_7 -> V_8 -> V_9 ( V_6 -> V_7 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 ,
struct V_10 * V_11 )
{
struct V_1 * V_6 =
F_1 ( V_3 ) ;
return F_14 ( V_6 -> V_12 , V_11 ) ;
}
static enum V_13
F_15 ( struct V_2 * V_3 , bool V_14 )
{
struct V_1 * V_6 =
F_1 ( V_3 ) ;
if ( V_6 -> V_7 )
return V_15 ;
return V_16 ;
}
static void
F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_6 =
F_1 ( V_3 ) ;
if ( V_6 -> V_7 )
F_17 ( V_6 -> V_7 ) ;
F_18 ( V_3 ) ;
}
static int F_19 ( struct V_17 * V_18 ,
const struct V_19 * V_20 )
{
struct V_21 * V_22 ;
void * V_23 ;
V_22 = F_20 ( V_20 -> V_24 ) ;
V_23 = F_21 ( V_22 ) ;
if ( ! V_23 )
V_23 = F_22 ( V_22 ) ;
F_23 ( V_22 ) ;
return V_23 ? 0 : - V_25 ;
}
static int F_24 ( struct V_17 * V_18 ,
const struct V_19 * V_20 )
{
struct V_26 * V_12 = V_18 -> V_27 ;
struct V_1 * V_28 ;
struct V_21 * V_22 ;
struct V_29 * V_7 ;
struct V_30 * V_31 ;
int V_32 ;
V_28 = F_25 ( V_18 -> V_18 , sizeof( * V_28 ) , V_33 ) ;
if ( ! V_28 )
return - V_34 ;
V_28 -> V_12 = V_12 ;
F_26 ( & V_28 -> V_5 ,
& V_35 ) ;
V_32 = F_27 ( V_18 , & V_28 -> V_5 ,
& V_36 ,
V_37 , NULL ) ;
if ( V_32 )
return V_32 ;
V_28 -> V_5 . V_38 = 0x1 ;
V_22 = F_20 ( V_20 -> V_24 ) ;
V_32 = - V_25 ;
V_7 = F_21 ( V_22 ) ;
if ( V_7 ) {
F_23 ( V_22 ) ;
V_28 -> V_3 . V_39 = V_40 ;
V_28 -> V_3 . V_41 = V_42 ;
F_28 ( & V_28 -> V_3 ,
& V_43 ) ;
V_32 = F_29 ( V_18 , & V_28 -> V_3 ,
& V_44 ,
V_45 ) ;
if ( V_32 )
goto V_46;
F_30 ( & V_28 -> V_3 ,
& V_28 -> V_5 ) ;
V_32 = F_31 ( V_7 , & V_28 -> V_3 ) ;
if ( V_32 ) {
F_18 ( & V_28 -> V_3 ) ;
goto V_46;
}
V_28 -> V_7 = V_7 ;
return 0 ;
}
V_31 = F_22 ( V_22 ) ;
F_23 ( V_22 ) ;
if ( V_31 ) {
V_32 = F_32 ( & V_28 -> V_5 , V_31 , NULL ) ;
if ( ! V_32 )
return 0 ;
}
V_46:
F_11 ( & V_28 -> V_5 ) ;
return V_32 ;
}
int F_33 ( struct V_17 * V_18 )
{
struct V_21 * V_47 = NULL ;
struct V_19 V_20 ;
int V_32 ;
F_34 (dev->dev->of_node, ep_np) {
V_32 = F_35 ( V_47 , & V_20 ) ;
if ( ! V_32 )
V_32 = F_19 ( V_18 , & V_20 ) ;
if ( V_32 ) {
F_23 ( V_47 ) ;
return V_32 ;
}
}
F_34 (dev->dev->of_node, ep_np) {
V_32 = F_35 ( V_47 , & V_20 ) ;
if ( ! V_32 )
V_32 = F_24 ( V_18 , & V_20 ) ;
if ( V_32 ) {
F_23 ( V_47 ) ;
return V_32 ;
}
}
return 0 ;
}
