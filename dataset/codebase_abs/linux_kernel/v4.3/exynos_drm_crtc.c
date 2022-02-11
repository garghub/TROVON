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
static void F_7 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
V_4 -> V_13 = V_2 -> V_14 -> V_13 ;
F_8 (plane, crtc) {
struct V_15 * V_16 = F_9 ( V_12 ) ;
if ( V_4 -> V_5 -> V_17 )
V_4 -> V_5 -> V_17 ( V_4 ,
V_16 ) ;
}
}
static void F_10 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
F_8 (plane, crtc) {
struct V_15 * V_16 = F_9 ( V_12 ) ;
if ( V_4 -> V_5 -> V_18 )
V_4 -> V_5 -> V_18 ( V_4 ,
V_16 ) ;
}
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_19 * V_20 = V_2 -> V_21 -> V_22 ;
V_20 -> V_2 [ V_4 -> V_23 ] = NULL ;
F_12 ( V_2 ) ;
F_13 ( V_4 ) ;
}
struct V_3 * F_14 ( struct V_24 * V_25 ,
struct V_11 * V_12 ,
int V_23 ,
enum V_26 type ,
const struct V_27 * V_5 ,
void * V_28 )
{
struct V_3 * V_4 ;
struct V_19 * V_20 = V_25 -> V_22 ;
struct V_1 * V_2 ;
int V_29 ;
V_4 = F_15 ( sizeof( * V_4 ) , V_30 ) ;
if ( ! V_4 )
return F_16 ( - V_31 ) ;
V_4 -> V_23 = V_23 ;
V_4 -> type = type ;
V_4 -> V_5 = V_5 ;
V_4 -> V_28 = V_28 ;
F_17 ( & V_4 -> V_32 ) ;
V_2 = & V_4 -> V_33 ;
V_20 -> V_2 [ V_23 ] = V_2 ;
V_29 = F_18 ( V_25 , V_2 , V_12 , NULL ,
& V_34 ) ;
if ( V_29 < 0 )
goto V_35;
F_19 ( V_2 , & V_36 ) ;
return V_4 ;
V_35:
V_12 -> V_37 -> V_38 ( V_12 ) ;
F_13 ( V_4 ) ;
return F_16 ( V_29 ) ;
}
int F_20 ( struct V_24 * V_21 , int V_23 )
{
struct V_19 * V_20 = V_21 -> V_22 ;
struct V_3 * V_4 =
F_2 ( V_20 -> V_2 [ V_23 ] ) ;
if ( V_4 -> V_5 -> V_39 )
return V_4 -> V_5 -> V_39 ( V_4 ) ;
return 0 ;
}
void F_21 ( struct V_24 * V_21 , int V_23 )
{
struct V_19 * V_20 = V_21 -> V_22 ;
struct V_3 * V_4 =
F_2 ( V_20 -> V_2 [ V_23 ] ) ;
if ( V_4 -> V_5 -> V_40 )
V_4 -> V_5 -> V_40 ( V_4 ) ;
}
void F_22 ( struct V_3 * V_4 )
{
F_23 ( V_4 -> V_32 ,
( F_24 ( & V_4 -> V_41 ) == 0 ) ,
F_25 ( 50 ) ) ;
}
void F_26 ( struct V_3 * V_4 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = & V_4 -> V_33 ;
unsigned long V_42 ;
V_16 -> V_43 = NULL ;
if ( F_27 ( & V_4 -> V_41 ) )
F_28 ( & V_4 -> V_32 ) ;
F_29 ( & V_2 -> V_21 -> V_44 , V_42 ) ;
if ( V_4 -> V_13 )
F_30 ( V_2 , V_4 -> V_13 ) ;
V_4 -> V_13 = NULL ;
F_31 ( & V_2 -> V_21 -> V_44 , V_42 ) ;
}
void F_32 ( struct V_45 * V_46 )
{
struct V_3 * V_4 ;
struct V_24 * V_21 = V_46 -> V_21 ;
struct V_1 * V_2 ;
F_33 (crtc, &dev->mode_config.crtc_list, head) {
V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 -> V_47 )
V_4 -> V_5 -> V_47 ( V_4 ) ;
}
}
int F_34 ( struct V_24 * V_25 ,
enum V_26 V_48 )
{
struct V_1 * V_2 ;
F_33 (crtc, &drm_dev->mode_config.crtc_list, head) {
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
if ( V_4 -> type == V_48 )
return V_4 -> V_23 ;
}
return - V_49 ;
}
void F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 -> V_50 )
V_4 -> V_5 -> V_50 ( V_4 ) ;
}
