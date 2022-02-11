static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
F_2 ( L_1 , __FILE__ ) ;
V_4 -> V_10 -> V_2 = V_4 -> V_2 ;
V_6 = F_3 ( V_2 , V_4 -> V_10 ,
( 1 << V_11 ) - 1 ) ;
if ( ! V_6 ) {
F_4 ( L_2 ) ;
return - V_12 ;
}
V_8 = F_5 ( V_2 , V_6 ) ;
if ( ! V_8 ) {
F_4 ( L_3 ) ;
V_9 = - V_12 ;
goto V_13;
}
V_4 -> V_6 = V_6 ;
V_4 -> V_8 = V_8 ;
return 0 ;
V_13:
V_6 -> V_14 -> V_15 ( V_6 ) ;
return V_9 ;
}
static void F_6 ( struct V_3 * V_4 )
{
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
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_16 ) {
int V_9 ;
V_4 -> V_17 = V_2 ;
V_9 = V_4 -> V_16 ( V_2 , V_4 -> V_2 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( L_1 , __FILE__ ) ;
if ( V_4 -> remove )
V_4 -> remove ( V_2 , V_4 -> V_2 ) ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_18 ;
unsigned int V_19 = 0 ;
int V_20 ;
F_2 ( L_1 , __FILE__ ) ;
if ( ! V_2 )
return - V_21 ;
F_10 (subdrv, n, &exynos_drm_subdrv_list, list) {
V_20 = F_7 ( V_2 , V_4 ) ;
if ( V_20 ) {
F_11 ( L_4 ) ;
F_12 ( & V_4 -> V_22 ) ;
continue;
}
if ( ! V_4 -> V_10 ) {
V_19 ++ ;
continue;
}
V_20 = F_1 ( V_2 , V_4 ) ;
if ( V_20 ) {
F_11 ( L_5 ) ;
F_8 ( V_2 , V_4 ) ;
F_12 ( & V_4 -> V_22 ) ;
continue;
}
V_19 ++ ;
}
if ( ! V_19 )
return - V_21 ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( L_1 , __FILE__ ) ;
if ( ! V_2 ) {
F_14 ( 1 , L_6 ) ;
return - V_21 ;
}
F_15 (subdrv, &exynos_drm_subdrv_list, list) {
F_8 ( V_2 , V_4 ) ;
F_6 ( V_4 ) ;
}
return 0 ;
}
int F_16 ( struct V_3 * V_4 )
{
F_2 ( L_1 , __FILE__ ) ;
if ( ! V_4 )
return - V_21 ;
F_17 ( & V_4 -> V_22 , & V_23 ) ;
return 0 ;
}
int F_18 ( struct V_3 * V_4 )
{
F_2 ( L_1 , __FILE__ ) ;
if ( ! V_4 )
return - V_21 ;
F_12 ( & V_4 -> V_22 ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_3 * V_4 ;
int V_9 ;
F_15 (subdrv, &exynos_drm_subdrv_list, list) {
if ( V_4 -> V_26 ) {
V_9 = V_4 -> V_26 ( V_2 , V_4 -> V_2 , V_25 ) ;
if ( V_9 )
goto V_20;
}
}
return 0 ;
V_20:
F_20 (subdrv, &subdrv->list, list) {
if ( V_4 -> V_27 )
V_4 -> V_27 ( V_2 , V_4 -> V_2 , V_25 ) ;
}
return V_9 ;
}
void F_21 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_3 * V_4 ;
F_15 (subdrv, &exynos_drm_subdrv_list, list) {
if ( V_4 -> V_27 )
V_4 -> V_27 ( V_2 , V_4 -> V_2 , V_25 ) ;
}
}
