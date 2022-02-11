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
V_4 -> V_13 = V_2 -> V_10 -> V_13 ;
if ( V_4 -> V_5 -> V_14 )
V_4 -> V_5 -> V_14 ( V_4 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_9 * V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 -> V_15 )
V_4 -> V_5 -> V_15 ( V_4 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_2 -> V_18 -> V_19 ;
V_17 -> V_2 [ V_4 -> V_20 ] = NULL ;
F_11 ( V_2 ) ;
F_12 ( V_4 ) ;
}
struct V_3 * F_13 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
int V_20 ,
enum V_25 type ,
const struct V_26 * V_5 ,
void * V_27 )
{
struct V_3 * V_4 ;
struct V_16 * V_17 = V_22 -> V_19 ;
struct V_1 * V_2 ;
int V_28 ;
V_4 = F_14 ( sizeof( * V_4 ) , V_29 ) ;
if ( ! V_4 )
return F_15 ( - V_30 ) ;
V_4 -> V_20 = V_20 ;
V_4 -> type = type ;
V_4 -> V_5 = V_5 ;
V_4 -> V_27 = V_27 ;
F_16 ( & V_4 -> V_31 ) ;
V_2 = & V_4 -> V_32 ;
V_17 -> V_2 [ V_20 ] = V_2 ;
V_28 = F_17 ( V_22 , V_2 , V_24 , NULL ,
& V_33 , NULL ) ;
if ( V_28 < 0 )
goto V_34;
F_18 ( V_2 , & V_35 ) ;
return V_4 ;
V_34:
V_24 -> V_36 -> V_37 ( V_24 ) ;
F_12 ( V_4 ) ;
return F_15 ( V_28 ) ;
}
int F_19 ( struct V_21 * V_18 , unsigned int V_20 )
{
struct V_16 * V_17 = V_18 -> V_19 ;
struct V_3 * V_4 =
F_2 ( V_17 -> V_2 [ V_20 ] ) ;
if ( V_4 -> V_5 -> V_38 )
return V_4 -> V_5 -> V_38 ( V_4 ) ;
return 0 ;
}
void F_20 ( struct V_21 * V_18 , unsigned int V_20 )
{
struct V_16 * V_17 = V_18 -> V_19 ;
struct V_3 * V_4 =
F_2 ( V_17 -> V_2 [ V_20 ] ) ;
if ( V_4 -> V_5 -> V_39 )
V_4 -> V_5 -> V_39 ( V_4 ) ;
}
void F_21 ( struct V_3 * V_4 )
{
F_22 ( V_4 -> V_31 ,
( F_23 ( & V_4 -> V_40 ) == 0 ) ,
F_24 ( 50 ) ) ;
}
void F_25 ( struct V_3 * V_4 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = & V_4 -> V_32 ;
unsigned long V_43 ;
V_42 -> V_44 = NULL ;
if ( F_26 ( & V_4 -> V_40 ) )
F_27 ( & V_4 -> V_31 ) ;
F_28 ( & V_2 -> V_18 -> V_45 , V_43 ) ;
if ( V_4 -> V_13 )
F_29 ( V_2 , V_4 -> V_13 ) ;
V_4 -> V_13 = NULL ;
F_30 ( & V_2 -> V_18 -> V_45 , V_43 ) ;
}
int F_31 ( struct V_21 * V_22 ,
enum V_25 V_46 )
{
struct V_1 * V_2 ;
F_32 (crtc, &drm_dev->mode_config.crtc_list, head) {
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
if ( V_4 -> type == V_46 )
return V_4 -> V_20 ;
}
return - V_47 ;
}
void F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 -> V_48 )
V_4 -> V_5 -> V_48 ( V_4 ) ;
}
void F_34 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_51 * V_52 ;
unsigned long V_43 ;
F_28 ( & V_2 -> V_18 -> V_45 , V_43 ) ;
V_52 = V_4 -> V_13 ;
if ( V_52 && V_52 -> V_32 . V_53 == V_50 ) {
V_4 -> V_13 = NULL ;
V_52 -> V_32 . V_37 ( & V_52 -> V_32 ) ;
V_50 -> V_54 += sizeof( V_52 -> V_13 ) ;
F_35 ( & V_4 -> V_40 ) ;
}
F_30 ( & V_2 -> V_18 -> V_45 , V_43 ) ;
}
