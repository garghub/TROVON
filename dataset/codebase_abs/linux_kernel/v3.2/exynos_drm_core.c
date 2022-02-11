static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_4 -> V_9 ) {
int V_10 ;
V_10 = V_4 -> V_9 ( V_2 , V_4 -> V_11 . V_2 ) ;
if ( V_10 )
return V_10 ;
}
V_6 = F_3 ( V_2 , & V_4 -> V_11 ,
( 1 << V_12 ) - 1 ) ;
if ( ! V_6 ) {
F_4 ( L_2 ) ;
return - V_13 ;
}
V_8 = F_5 ( V_2 , V_6 ) ;
if ( ! V_8 ) {
F_4 ( L_3 ) ;
V_6 -> V_14 -> V_15 ( V_6 ) ;
return - V_13 ;
}
V_4 -> V_6 = V_6 ;
V_4 -> V_8 = V_8 ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( L_1 , __FILE__ ) ;
if ( V_4 -> remove )
V_4 -> remove ( V_2 ) ;
if ( V_4 -> V_6 ) {
struct V_5 * V_6 = V_4 -> V_6 ;
V_6 -> V_14 -> V_15 ( V_6 ) ;
V_4 -> V_6 = NULL ;
}
if ( V_4 -> V_8 ) {
struct V_7 * V_8 = V_4 -> V_8 ;
V_8 -> V_14 -> V_15 ( V_8 ) ;
V_4 -> V_8 = NULL ;
}
}
int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_16 ;
int V_17 ;
F_2 ( L_1 , __FILE__ ) ;
if ( ! V_2 )
return - V_18 ;
if ( V_19 ) {
F_4 ( L_4 ) ;
return - V_20 ;
}
F_8 ( & V_21 ) ;
F_9 (subdrv, n, &exynos_drm_subdrv_list, list) {
V_17 = F_1 ( V_2 , V_4 ) ;
if ( V_17 ) {
F_10 ( L_5 ) ;
F_11 ( & V_4 -> V_22 ) ;
}
}
V_19 = V_2 ;
F_12 ( & V_21 ) ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( L_1 , __FILE__ ) ;
if ( ! V_2 || V_2 != V_19 ) {
F_14 ( 1 , L_6 ) ;
return - V_18 ;
}
F_8 ( & V_21 ) ;
F_15 (subdrv, &exynos_drm_subdrv_list, list)
F_6 ( V_2 , V_4 ) ;
V_19 = NULL ;
F_12 ( & V_21 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = & V_2 -> V_25 -> V_26 ;
T_1 * V_27 = V_24 -> V_27 ;
int V_10 ;
F_2 ( L_1 , __FILE__ ) ;
V_10 = F_17 ( V_2 , V_24 ) ;
if ( V_10 < 0 )
return V_10 ;
F_18 ( V_27 ) ;
return 0 ;
}
int F_19 ( struct V_3 * V_4 )
{
int V_17 ;
F_2 ( L_1 , __FILE__ ) ;
if ( ! V_4 )
return - V_18 ;
F_8 ( & V_21 ) ;
if ( V_19 ) {
V_17 = F_1 ( V_19 , V_4 ) ;
if ( V_17 ) {
F_4 ( L_7 ) ;
F_12 ( & V_21 ) ;
return V_17 ;
}
V_17 = F_20 ( V_19 ) ;
if ( V_17 ) {
F_4 ( L_8 ) ;
F_6 ( V_19 , V_4 ) ;
F_12 ( & V_21 ) ;
return V_17 ;
}
V_17 = F_16 ( V_19 ) ;
if ( V_17 ) {
F_4 ( L_9 ) ;
F_21 ( V_19 ) ;
F_6 ( V_19 , V_4 ) ;
F_12 ( & V_21 ) ;
return V_17 ;
}
}
V_4 -> V_19 = V_19 ;
F_22 ( & V_4 -> V_22 , & V_28 ) ;
F_12 ( & V_21 ) ;
return 0 ;
}
int F_23 ( struct V_3 * V_4 )
{
int V_10 = - V_13 ;
F_2 ( L_1 , __FILE__ ) ;
if ( ! V_4 ) {
F_10 ( L_10 ) ;
return V_10 ;
}
F_8 ( & V_21 ) ;
if ( V_19 ) {
F_6 ( V_19 , V_4 ) ;
F_11 ( & V_4 -> V_22 ) ;
V_10 = F_20 ( V_19 ) ;
if ( V_10 < 0 ) {
F_4 ( L_11 ) ;
goto V_29;
}
V_10 = F_16 ( V_19 ) ;
if ( V_10 < 0 ) {
F_4 ( L_12 ) ;
goto V_29;
}
}
V_29:
F_12 ( & V_21 ) ;
return V_10 ;
}
