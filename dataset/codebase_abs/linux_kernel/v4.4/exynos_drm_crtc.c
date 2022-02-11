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
}
static void
F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 -> V_8 )
V_4 -> V_5 -> V_8 ( V_4 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_10 -> V_6 )
return 0 ;
if ( V_4 -> V_5 -> V_11 )
return V_4 -> V_5 -> V_11 ( V_4 , V_10 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_9 * V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_13 * V_14 ;
V_4 -> V_15 = V_2 -> V_10 -> V_15 ;
F_9 (plane, crtc) {
struct V_16 * V_17 = F_10 ( V_14 ) ;
if ( V_4 -> V_5 -> V_18 )
V_4 -> V_5 -> V_18 ( V_4 ,
V_17 ) ;
}
}
static void F_11 ( struct V_1 * V_2 ,
struct V_9 * V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_13 * V_14 ;
F_9 (plane, crtc) {
struct V_16 * V_17 = F_10 ( V_14 ) ;
if ( V_4 -> V_5 -> V_19 )
V_4 -> V_5 -> V_19 ( V_4 ,
V_17 ) ;
}
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_20 * V_21 = V_2 -> V_22 -> V_23 ;
V_21 -> V_2 [ V_4 -> V_24 ] = NULL ;
F_13 ( V_2 ) ;
F_14 ( V_4 ) ;
}
struct V_3 * F_15 ( struct V_25 * V_26 ,
struct V_13 * V_14 ,
int V_24 ,
enum V_27 type ,
const struct V_28 * V_5 ,
void * V_29 )
{
struct V_3 * V_4 ;
struct V_20 * V_21 = V_26 -> V_23 ;
struct V_1 * V_2 ;
int V_30 ;
V_4 = F_16 ( sizeof( * V_4 ) , V_31 ) ;
if ( ! V_4 )
return F_17 ( - V_32 ) ;
V_4 -> V_24 = V_24 ;
V_4 -> type = type ;
V_4 -> V_5 = V_5 ;
V_4 -> V_29 = V_29 ;
F_18 ( & V_4 -> V_33 ) ;
V_2 = & V_4 -> V_34 ;
V_21 -> V_2 [ V_24 ] = V_2 ;
V_30 = F_19 ( V_26 , V_2 , V_14 , NULL ,
& V_35 ) ;
if ( V_30 < 0 )
goto V_36;
F_20 ( V_2 , & V_37 ) ;
return V_4 ;
V_36:
V_14 -> V_38 -> V_39 ( V_14 ) ;
F_14 ( V_4 ) ;
return F_17 ( V_30 ) ;
}
int F_21 ( struct V_25 * V_22 , unsigned int V_24 )
{
struct V_20 * V_21 = V_22 -> V_23 ;
struct V_3 * V_4 =
F_2 ( V_21 -> V_2 [ V_24 ] ) ;
if ( V_4 -> V_5 -> V_40 )
return V_4 -> V_5 -> V_40 ( V_4 ) ;
return 0 ;
}
void F_22 ( struct V_25 * V_22 , unsigned int V_24 )
{
struct V_20 * V_21 = V_22 -> V_23 ;
struct V_3 * V_4 =
F_2 ( V_21 -> V_2 [ V_24 ] ) ;
if ( V_4 -> V_5 -> V_41 )
V_4 -> V_5 -> V_41 ( V_4 ) ;
}
void F_23 ( struct V_3 * V_4 )
{
F_24 ( V_4 -> V_33 ,
( F_25 ( & V_4 -> V_42 ) == 0 ) ,
F_26 ( 50 ) ) ;
}
void F_27 ( struct V_3 * V_4 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = & V_4 -> V_34 ;
unsigned long V_43 ;
V_17 -> V_44 = NULL ;
if ( F_28 ( & V_4 -> V_42 ) )
F_29 ( & V_4 -> V_33 ) ;
F_30 ( & V_2 -> V_22 -> V_45 , V_43 ) ;
if ( V_4 -> V_15 )
F_31 ( V_2 , V_4 -> V_15 ) ;
V_4 -> V_15 = NULL ;
F_32 ( & V_2 -> V_22 -> V_45 , V_43 ) ;
}
void F_33 ( struct V_46 * V_47 )
{
struct V_3 * V_4 ;
struct V_25 * V_22 = V_47 -> V_22 ;
struct V_1 * V_2 ;
F_34 (crtc, &dev->mode_config.crtc_list, head) {
V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 -> V_48 )
V_4 -> V_5 -> V_48 ( V_4 ) ;
}
}
int F_35 ( struct V_25 * V_26 ,
enum V_27 V_49 )
{
struct V_1 * V_2 ;
F_34 (crtc, &drm_dev->mode_config.crtc_list, head) {
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
if ( V_4 -> type == V_49 )
return V_4 -> V_24 ;
}
return - V_50 ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 -> V_51 )
V_4 -> V_5 -> V_51 ( V_4 ) ;
}
