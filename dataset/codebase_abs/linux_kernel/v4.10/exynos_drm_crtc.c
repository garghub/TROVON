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
if ( V_4 -> V_5 -> V_13 )
V_4 -> V_5 -> V_13 ( V_4 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_9 * V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_14 * V_15 ;
unsigned long V_16 ;
if ( V_4 -> V_5 -> V_17 )
V_4 -> V_5 -> V_17 ( V_4 ) ;
V_15 = V_2 -> V_10 -> V_15 ;
if ( V_15 ) {
V_2 -> V_10 -> V_15 = NULL ;
F_10 ( & V_2 -> V_18 -> V_19 , V_16 ) ;
if ( F_11 ( V_2 ) == 0 )
F_12 ( V_2 , V_15 ) ;
else
F_13 ( V_2 , V_15 ) ;
F_14 ( & V_2 -> V_18 -> V_19 , V_16 ) ;
}
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_20 * V_21 = V_2 -> V_18 -> V_22 ;
V_21 -> V_2 [ V_4 -> V_23 ] = NULL ;
F_16 ( V_2 ) ;
F_17 ( V_4 ) ;
}
struct V_3 * F_18 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
int V_23 ,
enum V_28 type ,
const struct V_29 * V_5 ,
void * V_30 )
{
struct V_3 * V_4 ;
struct V_20 * V_21 = V_25 -> V_22 ;
struct V_1 * V_2 ;
int V_31 ;
V_4 = F_19 ( sizeof( * V_4 ) , V_32 ) ;
if ( ! V_4 )
return F_20 ( - V_33 ) ;
V_4 -> V_23 = V_23 ;
V_4 -> type = type ;
V_4 -> V_5 = V_5 ;
V_4 -> V_30 = V_30 ;
V_2 = & V_4 -> V_34 ;
V_21 -> V_2 [ V_23 ] = V_2 ;
V_31 = F_21 ( V_25 , V_2 , V_27 , NULL ,
& V_35 , NULL ) ;
if ( V_31 < 0 )
goto V_36;
F_22 ( V_2 , & V_37 ) ;
return V_4 ;
V_36:
V_27 -> V_38 -> V_39 ( V_27 ) ;
F_17 ( V_4 ) ;
return F_20 ( V_31 ) ;
}
int F_23 ( struct V_24 * V_18 , unsigned int V_23 )
{
struct V_3 * V_4 = F_24 ( V_18 ,
V_23 ) ;
if ( V_4 -> V_5 -> V_40 )
return V_4 -> V_5 -> V_40 ( V_4 ) ;
return 0 ;
}
void F_25 ( struct V_24 * V_18 , unsigned int V_23 )
{
struct V_3 * V_4 = F_24 ( V_18 ,
V_23 ) ;
if ( V_4 -> V_5 -> V_41 )
V_4 -> V_5 -> V_41 ( V_4 ) ;
}
int F_26 ( struct V_24 * V_25 ,
enum V_28 V_42 )
{
struct V_1 * V_2 ;
F_27 (crtc, &drm_dev->mode_config.crtc_list, head) {
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
if ( V_4 -> type == V_42 )
return V_4 -> V_23 ;
}
return - V_43 ;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 -> V_44 )
V_4 -> V_5 -> V_44 ( V_4 ) ;
}
void F_29 ( struct V_1 * V_2 ,
struct V_45 * V_46 )
{
struct V_14 * V_47 ;
unsigned long V_16 ;
F_10 ( & V_2 -> V_18 -> V_19 , V_16 ) ;
V_47 = V_2 -> V_10 -> V_15 ;
if ( V_47 && V_47 -> V_34 . V_48 == V_46 )
V_2 -> V_10 -> V_15 = NULL ;
else
V_47 = NULL ;
F_14 ( & V_2 -> V_18 -> V_19 , V_16 ) ;
if ( V_47 )
F_30 ( V_2 -> V_18 , & V_47 -> V_34 ) ;
}
