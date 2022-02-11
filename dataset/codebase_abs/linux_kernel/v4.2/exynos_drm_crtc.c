static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 )
return;
if ( V_4 -> V_6 -> V_7 )
V_4 -> V_6 -> V_7 ( V_4 ) ;
V_4 -> V_5 = true ;
F_3 ( V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_5 )
return;
if ( ! F_5 ( V_4 -> V_8 ,
( V_4 -> V_9 == NULL ) , V_10 / 20 ) )
V_4 -> V_9 = NULL ;
F_6 ( V_2 ) ;
if ( V_4 -> V_6 -> V_11 )
V_4 -> V_6 -> V_11 ( V_4 ) ;
V_4 -> V_5 = false ;
}
static bool
F_7 ( struct V_1 * V_2 ,
const struct V_12 * V_13 ,
struct V_12 * V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_6 -> V_15 )
return V_4 -> V_6 -> V_15 ( V_4 , V_13 ,
V_14 ) ;
return true ;
}
static void
F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_6 -> V_16 )
V_4 -> V_6 -> V_16 ( V_4 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_2 -> V_17 -> V_9 ) {
F_10 ( F_11 ( V_2 ) != 0 ) ;
V_4 -> V_9 = V_2 -> V_17 -> V_9 ;
}
}
static void F_12 ( struct V_1 * V_2 )
{
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_18 * V_19 = V_2 -> V_20 -> V_21 ;
V_19 -> V_2 [ V_4 -> V_22 ] = NULL ;
F_14 ( V_2 ) ;
F_15 ( V_4 ) ;
}
struct V_3 * F_16 ( struct V_23 * V_24 ,
struct V_25 * V_26 ,
int V_22 ,
enum V_27 type ,
const struct V_28 * V_6 ,
void * V_29 )
{
struct V_3 * V_4 ;
struct V_18 * V_19 = V_24 -> V_21 ;
struct V_1 * V_2 ;
int V_30 ;
V_4 = F_17 ( sizeof( * V_4 ) , V_31 ) ;
if ( ! V_4 )
return F_18 ( - V_32 ) ;
F_19 ( & V_4 -> V_8 ) ;
V_4 -> V_22 = V_22 ;
V_4 -> type = type ;
V_4 -> V_6 = V_6 ;
V_4 -> V_29 = V_29 ;
V_2 = & V_4 -> V_33 ;
V_19 -> V_2 [ V_22 ] = V_2 ;
V_30 = F_20 ( V_24 , V_2 , V_26 , NULL ,
& V_34 ) ;
if ( V_30 < 0 )
goto V_35;
F_21 ( V_2 , & V_36 ) ;
return V_4 ;
V_35:
V_26 -> V_37 -> V_38 ( V_26 ) ;
F_15 ( V_4 ) ;
return F_18 ( V_30 ) ;
}
int F_22 ( struct V_23 * V_20 , int V_22 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
struct V_3 * V_4 =
F_2 ( V_19 -> V_2 [ V_22 ] ) ;
if ( ! V_4 -> V_5 )
return - V_39 ;
if ( V_4 -> V_6 -> V_40 )
V_4 -> V_6 -> V_40 ( V_4 ) ;
return 0 ;
}
void F_23 ( struct V_23 * V_20 , int V_22 )
{
struct V_18 * V_19 = V_20 -> V_21 ;
struct V_3 * V_4 =
F_2 ( V_19 -> V_2 [ V_22 ] ) ;
if ( ! V_4 -> V_5 )
return;
if ( V_4 -> V_6 -> V_41 )
V_4 -> V_6 -> V_41 ( V_4 ) ;
}
void F_24 ( struct V_23 * V_20 , int V_22 )
{
struct V_18 * V_42 = V_20 -> V_21 ;
struct V_1 * V_1 = V_42 -> V_2 [ V_22 ] ;
struct V_3 * V_4 = F_2 ( V_1 ) ;
unsigned long V_43 ;
F_25 ( & V_20 -> V_44 , V_43 ) ;
if ( V_4 -> V_9 ) {
F_26 ( V_20 , - 1 , V_4 -> V_9 ) ;
F_27 ( V_20 , V_22 ) ;
F_28 ( & V_4 -> V_8 ) ;
}
V_4 -> V_9 = NULL ;
F_29 ( & V_20 -> V_44 , V_43 ) ;
}
void F_30 ( struct V_45 * V_46 )
{
struct V_3 * V_4 ;
struct V_23 * V_20 = V_46 -> V_20 ;
struct V_1 * V_2 ;
F_31 (crtc, &dev->mode_config.crtc_list, head) {
V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_6 -> V_47 )
V_4 -> V_6 -> V_47 ( V_4 ) ;
}
}
int F_32 ( struct V_23 * V_24 ,
unsigned int V_48 )
{
struct V_1 * V_2 ;
F_31 (crtc, &drm_dev->mode_config.crtc_list, head) {
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
if ( V_4 -> type == V_48 )
return V_4 -> V_22 ;
}
return - V_39 ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_6 -> V_49 )
V_4 -> V_6 -> V_49 ( V_4 ) ;
}
