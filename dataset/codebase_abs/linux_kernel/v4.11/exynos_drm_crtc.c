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
struct V_3 * F_21 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
int V_26 ,
enum V_27 type ,
const struct V_28 * V_5 ,
void * V_29 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_30 ;
V_4 = F_22 ( sizeof( * V_4 ) , V_31 ) ;
if ( ! V_4 )
return F_23 ( - V_32 ) ;
V_4 -> V_26 = V_26 ;
V_4 -> type = type ;
V_4 -> V_5 = V_5 ;
V_4 -> V_29 = V_29 ;
V_2 = & V_4 -> V_19 ;
V_30 = F_24 ( V_23 , V_2 , V_25 , NULL ,
& V_33 , NULL ) ;
if ( V_30 < 0 )
goto V_34;
F_25 ( V_2 , & V_35 ) ;
return V_4 ;
V_34:
V_25 -> V_36 -> V_37 ( V_25 ) ;
F_20 ( V_4 ) ;
return F_23 ( V_30 ) ;
}
int F_26 ( struct V_22 * V_11 , unsigned int V_26 )
{
struct V_3 * V_4 = F_27 ( V_11 ,
V_26 ) ;
if ( V_4 -> V_5 -> V_38 )
return V_4 -> V_5 -> V_38 ( V_4 ) ;
return 0 ;
}
void F_28 ( struct V_22 * V_11 , unsigned int V_26 )
{
struct V_3 * V_4 = F_27 ( V_11 ,
V_26 ) ;
if ( V_4 -> V_5 -> V_39 )
V_4 -> V_5 -> V_39 ( V_4 ) ;
}
int F_29 ( struct V_22 * V_23 ,
enum V_27 V_40 )
{
struct V_1 * V_2 ;
F_30 (crtc, &drm_dev->mode_config.crtc_list, head) {
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
if ( V_4 -> type == V_40 )
return V_4 -> V_26 ;
}
return - V_41 ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 -> V_42 )
V_4 -> V_5 -> V_42 ( V_4 ) ;
}
