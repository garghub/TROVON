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
static int F_9 ( struct V_1 * V_2 ,
struct V_13 * V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_8 -> V_6 )
return 0 ;
if ( V_4 -> V_5 -> V_14 )
return V_4 -> V_5 -> V_14 ( V_4 , V_8 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_13 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 -> V_16 )
V_4 -> V_5 -> V_16 ( V_4 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_13 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 -> V_17 )
V_4 -> V_5 -> V_17 ( V_4 ) ;
}
void F_12 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_18 ;
struct V_19 * V_9 = V_2 -> V_8 -> V_9 ;
unsigned long V_20 ;
if ( ! V_9 )
return;
V_2 -> V_8 -> V_9 = NULL ;
F_13 ( F_14 ( V_2 ) != 0 ) ;
F_15 ( & V_2 -> V_11 -> V_12 , V_20 ) ;
F_16 ( V_2 , V_9 ) ;
F_17 ( & V_2 -> V_11 -> V_12 , V_20 ) ;
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
if ( V_4 -> V_5 -> V_21 )
return V_4 -> V_5 -> V_21 ( V_4 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 -> V_22 )
V_4 -> V_5 -> V_22 ( V_4 ) ;
}
static T_1 F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 -> V_23 )
return V_4 -> V_5 -> V_23 ( V_4 ) ;
return 0 ;
}
struct V_3 * F_24 ( struct V_24 * V_25 ,
struct V_26 * V_27 ,
enum V_28 type ,
const struct V_29 * V_5 ,
void * V_30 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_31 ;
V_4 = F_25 ( sizeof( * V_4 ) , V_32 ) ;
if ( ! V_4 )
return F_26 ( - V_33 ) ;
V_4 -> type = type ;
V_4 -> V_5 = V_5 ;
V_4 -> V_30 = V_30 ;
V_2 = & V_4 -> V_18 ;
V_31 = F_27 ( V_25 , V_2 , V_27 , NULL ,
& V_34 , NULL ) ;
if ( V_31 < 0 )
goto V_35;
F_28 ( V_2 , & V_36 ) ;
return V_4 ;
V_35:
V_27 -> V_37 -> V_38 ( V_27 ) ;
F_20 ( V_4 ) ;
return F_26 ( V_31 ) ;
}
int F_29 ( struct V_24 * V_25 ,
enum V_28 V_39 )
{
struct V_1 * V_2 ;
F_30 (crtc, drm_dev)
if ( F_2 ( V_2 ) -> type == V_39 )
return F_31 ( V_2 ) ;
return - V_40 ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 -> V_41 )
V_4 -> V_5 -> V_41 ( V_4 ) ;
}
