static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_7 -> V_8 )
V_6 -> V_7 -> V_8 ( V_6 ) ;
F_3 ( V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_5 ( V_2 ) ;
if ( V_6 -> V_7 -> V_9 )
V_6 -> V_7 -> V_9 ( V_6 ) ;
if ( V_2 -> V_10 -> V_11 && ! V_2 -> V_10 -> V_12 ) {
F_6 ( & V_2 -> V_13 -> V_14 ) ;
F_7 ( V_2 , V_2 -> V_10 -> V_11 ) ;
F_8 ( & V_2 -> V_13 -> V_14 ) ;
V_2 -> V_10 -> V_11 = NULL ;
}
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_10 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_10 -> V_8 )
return 0 ;
if ( V_6 -> V_7 -> V_15 )
return V_6 -> V_7 -> V_15 ( V_6 , V_10 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_16 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_7 -> V_17 )
V_6 -> V_7 -> V_17 ( V_6 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_16 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_7 -> V_18 )
V_6 -> V_7 -> V_18 ( V_6 ) ;
}
static enum V_19 F_12 ( struct V_1 * V_2 ,
const struct V_20 * V_21 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_7 -> V_22 )
return V_6 -> V_7 -> V_22 ( V_6 , V_21 ) ;
return V_23 ;
}
void F_13 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_24 ;
struct V_25 * V_11 = V_2 -> V_10 -> V_11 ;
unsigned long V_26 ;
if ( ! V_11 )
return;
V_2 -> V_10 -> V_11 = NULL ;
F_14 ( F_15 ( V_2 ) != 0 ) ;
F_16 ( & V_2 -> V_13 -> V_14 , V_26 ) ;
F_17 ( V_2 , V_11 ) ;
F_18 ( & V_2 -> V_13 -> V_14 , V_26 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_20 ( V_2 ) ;
F_21 ( V_6 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_7 -> V_27 )
return V_6 -> V_7 -> V_27 ( V_6 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_7 -> V_28 )
V_6 -> V_7 -> V_28 ( V_6 ) ;
}
static T_1 F_24 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_7 -> V_29 )
return V_6 -> V_7 -> V_29 ( V_6 ) ;
return 0 ;
}
struct V_5 * F_25 ( struct V_30 * V_31 ,
struct V_32 * V_33 ,
enum V_34 type ,
const struct V_35 * V_7 ,
void * V_36 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 ;
int V_37 ;
V_6 = F_26 ( sizeof( * V_6 ) , V_38 ) ;
if ( ! V_6 )
return F_27 ( - V_39 ) ;
V_6 -> type = type ;
V_6 -> V_7 = V_7 ;
V_6 -> V_36 = V_36 ;
V_2 = & V_6 -> V_24 ;
V_37 = F_28 ( V_31 , V_2 , V_33 , NULL ,
& V_40 , NULL ) ;
if ( V_37 < 0 )
goto V_41;
F_29 ( V_2 , & V_42 ) ;
return V_6 ;
V_41:
V_33 -> V_43 -> V_44 ( V_33 ) ;
F_21 ( V_6 ) ;
return F_27 ( V_37 ) ;
}
struct V_5 * F_30 ( struct V_30 * V_31 ,
enum V_34 V_45 )
{
struct V_1 * V_2 ;
F_31 (crtc, drm_dev)
if ( F_2 ( V_2 ) -> type == V_45 )
return F_2 ( V_2 ) ;
return F_27 ( - V_46 ) ;
}
int F_32 ( struct V_47 * V_48 ,
enum V_34 V_45 )
{
struct V_5 * V_2 = F_30 ( V_48 -> V_13 ,
V_45 ) ;
if ( F_33 ( V_2 ) )
return F_34 ( V_2 ) ;
V_48 -> V_49 = F_35 ( & V_2 -> V_24 ) ;
return 0 ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_7 -> V_50 )
V_6 -> V_7 -> V_50 ( V_6 ) ;
}
