static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 -> V_6 )
V_4 -> V_5 -> V_6 ( V_4 ) ;
F_3 ( V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( V_2 ) ;
if ( V_4 -> V_5 -> V_7 )
V_4 -> V_5 -> V_7 ( V_4 ) ;
if ( V_2 -> V_8 -> V_9 && ! V_2 -> V_8 -> V_10 ) {
F_6 ( & V_2 -> V_11 -> V_12 ) ;
F_7 ( V_2 , V_2 -> V_8 -> V_9 ) ;
F_8 ( & V_2 -> V_11 -> V_12 ) ;
V_2 -> V_8 -> V_9 = NULL ;
}
}
static void
F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 -> V_13 )
V_4 -> V_5 -> V_13 ( V_4 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_14 * V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_8 -> V_6 )
return 0 ;
if ( V_4 -> V_5 -> V_15 )
return V_4 -> V_5 -> V_15 ( V_4 , V_8 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_14 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 -> V_17 )
V_4 -> V_5 -> V_17 ( V_4 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_14 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 -> V_18 )
V_4 -> V_5 -> V_18 ( V_4 ) ;
}
void F_13 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_19 ;
struct V_20 * V_9 = V_2 -> V_8 -> V_9 ;
unsigned long V_21 ;
if ( V_9 ) {
V_2 -> V_8 -> V_9 = NULL ;
F_14 ( & V_2 -> V_11 -> V_12 , V_21 ) ;
if ( F_15 ( V_2 ) == 0 )
F_16 ( V_2 , V_9 ) ;
else
F_7 ( V_2 , V_9 ) ;
F_17 ( & V_2 -> V_11 -> V_12 , V_21 ) ;
}
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_19 ( V_2 ) ;
F_20 ( V_4 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 -> V_22 )
return V_4 -> V_5 -> V_22 ( V_4 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 -> V_23 )
V_4 -> V_5 -> V_23 ( V_4 ) ;
}
struct V_3 * F_23 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
int V_28 ,
enum V_29 type ,
const struct V_30 * V_5 ,
void * V_31 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_32 ;
V_4 = F_24 ( sizeof( * V_4 ) , V_33 ) ;
if ( ! V_4 )
return F_25 ( - V_34 ) ;
V_4 -> V_28 = V_28 ;
V_4 -> type = type ;
V_4 -> V_5 = V_5 ;
V_4 -> V_31 = V_31 ;
V_2 = & V_4 -> V_19 ;
V_32 = F_26 ( V_25 , V_2 , V_27 , NULL ,
& V_35 , NULL ) ;
if ( V_32 < 0 )
goto V_36;
F_27 ( V_2 , & V_37 ) ;
return V_4 ;
V_36:
V_27 -> V_38 -> V_39 ( V_27 ) ;
F_20 ( V_4 ) ;
return F_25 ( V_32 ) ;
}
int F_28 ( struct V_24 * V_25 ,
enum V_29 V_40 )
{
struct V_1 * V_2 ;
F_29 (crtc, &drm_dev->mode_config.crtc_list, head) {
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
if ( V_4 -> type == V_40 )
return V_4 -> V_28 ;
}
return - V_41 ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 -> V_42 )
V_4 -> V_5 -> V_42 ( V_4 ) ;
}
