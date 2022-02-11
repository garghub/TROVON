static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
F_2 ( L_1 , __FILE__ ) ;
if ( V_4 -> V_9 ) {
int V_10 ;
V_10 = V_4 -> V_9 ( V_2 , V_4 -> V_2 ) ;
if ( V_10 )
return V_10 ;
}
if ( ! V_4 -> V_11 )
return 0 ;
V_4 -> V_11 -> V_2 = V_4 -> V_2 ;
V_6 = F_3 ( V_2 , V_4 -> V_11 ,
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
F_8 (subdrv, n, &exynos_drm_subdrv_list, list) {
V_4 -> V_19 = V_2 ;
V_17 = F_1 ( V_2 , V_4 ) ;
if ( V_17 ) {
F_9 ( L_4 ) ;
F_10 ( & V_4 -> V_20 ) ;
}
}
return 0 ;
}
int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( L_1 , __FILE__ ) ;
if ( ! V_2 ) {
F_12 ( 1 , L_5 ) ;
return - V_18 ;
}
F_13 (subdrv, &exynos_drm_subdrv_list, list)
F_6 ( V_2 , V_4 ) ;
return 0 ;
}
int F_14 ( struct V_3 * V_4 )
{
F_2 ( L_1 , __FILE__ ) ;
if ( ! V_4 )
return - V_18 ;
F_15 ( & V_4 -> V_20 , & V_21 ) ;
return 0 ;
}
int F_16 ( struct V_3 * V_4 )
{
F_2 ( L_1 , __FILE__ ) ;
if ( ! V_4 )
return - V_18 ;
F_10 ( & V_4 -> V_20 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_3 * V_4 ;
int V_10 ;
F_13 (subdrv, &exynos_drm_subdrv_list, list) {
if ( V_4 -> V_24 ) {
V_10 = V_4 -> V_24 ( V_2 , V_4 -> V_2 , V_23 ) ;
if ( V_10 )
goto V_17;
}
}
return 0 ;
V_17:
F_18 (subdrv, &subdrv->list, list) {
if ( V_4 -> V_25 )
V_4 -> V_25 ( V_2 , V_4 -> V_2 , V_23 ) ;
}
return V_10 ;
}
void F_19 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_3 * V_4 ;
F_13 (subdrv, &exynos_drm_subdrv_list, list) {
if ( V_4 -> V_25 )
V_4 -> V_25 ( V_2 , V_4 -> V_2 , V_23 ) ;
}
}
