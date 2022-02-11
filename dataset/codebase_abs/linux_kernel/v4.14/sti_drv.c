static int F_1 ( void * V_1 , T_1 * V_2 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 ;
unsigned int V_7 = 0 ;
* V_2 = 0 ;
F_2 (p, &drm_dev->mode_config.plane_list, head) {
struct V_8 * V_9 = F_3 ( V_6 ) ;
* V_2 |= V_9 -> V_10 . V_11 << V_7 ;
V_7 ++ ;
}
return 0 ;
}
static int F_4 ( void * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 ;
unsigned int V_7 = 0 ;
F_2 (p, &drm_dev->mode_config.plane_list, head) {
struct V_8 * V_9 = F_3 ( V_6 ) ;
memset ( & V_9 -> V_10 , 0 , sizeof( V_9 -> V_10 ) ) ;
V_9 -> V_10 . V_11 = ( V_2 >> V_7 ) & 1 ;
V_7 ++ ;
}
return 0 ;
}
static int F_5 ( struct V_12 * V_13 , void * V_1 )
{
struct V_14 * V_15 = V_13 -> V_16 ;
struct V_3 * V_17 = V_15 -> V_18 -> V_17 ;
struct V_5 * V_6 ;
F_2 (p, &dev->mode_config.plane_list, head) {
struct V_8 * V_9 = F_3 ( V_6 ) ;
F_6 ( V_13 , L_1 ,
V_9 -> V_10 . V_19 ,
V_9 -> V_10 . V_20 ) ;
}
return 0 ;
}
static int F_7 ( struct V_21 * V_18 )
{
struct V_22 * V_22 ;
int V_23 ;
V_23 = F_8 ( V_24 ,
F_9 ( V_24 ) ,
V_18 -> V_25 , V_18 ) ;
if ( V_23 )
goto V_26;
V_22 = F_10 ( L_2 , V_27 | V_28 ,
V_18 -> V_25 , V_18 -> V_17 ,
& V_29 ) ;
if ( ! V_22 ) {
V_23 = - V_30 ;
goto V_26;
}
F_11 ( L_3 , V_31 ) ;
return 0 ;
V_26:
F_12 ( L_4 , V_31 ) ;
return V_23 ;
}
static int F_13 ( struct V_3 * V_17 ,
struct V_32 * V_33 )
{
int V_23 ;
V_23 = F_14 ( V_17 , V_33 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_15 ( V_17 , V_33 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_16 ( V_17 , V_33 ) ;
if ( V_23 )
return V_23 ;
return V_23 ;
}
static void F_17 ( struct V_3 * V_34 )
{
struct V_35 * V_16 = V_34 -> V_36 ;
F_18 ( V_16 -> V_37 ) ;
}
static void F_19 ( struct V_3 * V_17 )
{
V_17 -> V_38 . V_39 = 0 ;
V_17 -> V_38 . V_40 = 0 ;
V_17 -> V_38 . V_41 = V_42 ;
V_17 -> V_38 . V_43 = V_44 ;
V_17 -> V_38 . V_45 = & V_46 ;
}
static int F_20 ( struct V_47 * V_17 , void * V_1 )
{
return V_17 -> V_48 == V_1 ;
}
static int F_21 ( struct V_3 * V_34 )
{
struct V_35 * V_16 ;
V_16 = F_22 ( sizeof( * V_16 ) , V_49 ) ;
if ( ! V_16 )
return - V_30 ;
V_34 -> V_36 = ( void * ) V_16 ;
F_23 ( V_34 -> V_17 , V_34 ) ;
V_16 -> V_4 = V_34 ;
F_24 ( V_34 ) ;
F_19 ( V_34 ) ;
F_25 ( V_34 ) ;
return 0 ;
}
static void F_26 ( struct V_3 * V_34 )
{
struct V_35 * V_16 = V_34 -> V_36 ;
if ( V_16 -> V_37 ) {
F_27 ( V_16 -> V_37 ) ;
V_16 -> V_37 = NULL ;
}
F_28 ( V_34 ) ;
F_29 ( V_34 -> V_17 , V_34 ) ;
F_30 ( V_16 ) ;
V_34 -> V_36 = NULL ;
}
static int F_31 ( struct V_47 * V_17 )
{
struct V_3 * V_34 ;
struct V_35 * V_16 ;
struct V_50 * V_37 ;
int V_23 ;
V_34 = F_32 ( & V_51 , V_17 ) ;
if ( F_33 ( V_34 ) )
return F_34 ( V_34 ) ;
V_23 = F_21 ( V_34 ) ;
if ( V_23 )
goto V_52;
V_23 = F_35 ( V_34 -> V_17 , V_34 ) ;
if ( V_23 )
goto V_53;
V_23 = F_36 ( V_34 , 0 ) ;
if ( V_23 )
goto V_54;
F_37 ( V_34 ) ;
V_16 = V_34 -> V_36 ;
if ( V_34 -> V_38 . V_55 ) {
V_37 = F_38 ( V_34 , 32 ,
V_34 -> V_38 . V_55 ) ;
if ( F_33 ( V_37 ) ) {
F_39 ( L_5 ) ;
V_37 = NULL ;
}
V_16 -> V_37 = V_37 ;
}
return 0 ;
V_54:
F_40 ( V_34 ) ;
V_53:
F_26 ( V_34 ) ;
V_52:
F_41 ( V_34 ) ;
return V_23 ;
}
static void F_42 ( struct V_47 * V_17 )
{
struct V_3 * V_34 = F_43 ( V_17 ) ;
F_44 ( V_34 ) ;
F_26 ( V_34 ) ;
F_41 ( V_34 ) ;
}
static int F_45 ( struct V_56 * V_57 )
{
struct V_47 * V_17 = & V_57 -> V_17 ;
struct V_58 * V_15 = V_17 -> V_48 ;
struct V_58 * V_59 ;
struct V_60 * V_61 = NULL ;
F_46 ( V_17 , F_47 ( 32 ) ) ;
F_48 ( V_17 ) ;
V_59 = F_49 ( V_15 , NULL ) ;
while ( V_59 ) {
F_50 ( V_17 , & V_61 , F_20 ,
V_59 ) ;
V_59 = F_49 ( V_15 , V_59 ) ;
}
return F_51 ( V_17 , & V_62 , V_61 ) ;
}
static int F_52 ( struct V_56 * V_57 )
{
F_53 ( & V_57 -> V_17 , & V_62 ) ;
return 0 ;
}
static int F_54 ( void )
{
return F_55 ( V_63 , F_9 ( V_63 ) ) ;
}
static void F_56 ( void )
{
F_57 ( V_63 , F_9 ( V_63 ) ) ;
}
