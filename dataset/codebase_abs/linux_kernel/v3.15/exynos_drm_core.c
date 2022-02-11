static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
unsigned long V_10 = 0 ;
F_2 (manager, &exynos_drm_manager_list, list)
if ( V_8 -> type == V_4 -> type )
V_10 |= 1 << V_8 -> V_11 ;
V_6 = F_3 ( V_2 , V_4 , V_10 ) ;
if ( ! V_6 ) {
F_4 ( L_1 ) ;
return - V_12 ;
}
V_4 -> V_6 = V_6 ;
V_9 = V_4 -> V_13 -> V_14 ( V_4 , V_6 ) ;
if ( V_9 ) {
F_4 ( L_2 , V_9 ) ;
goto V_15;
}
return 0 ;
V_15:
V_6 -> V_16 -> V_17 ( V_6 ) ;
return V_9 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
if ( V_19 -> V_20 ) {
int V_9 ;
V_19 -> V_21 = V_2 ;
V_9 = V_19 -> V_20 ( V_2 , V_19 -> V_2 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
if ( V_19 -> remove )
V_19 -> remove ( V_2 , V_19 -> V_2 ) ;
}
int F_7 ( struct V_1 * V_2 )
{
struct V_7 * V_8 , * V_22 ;
int V_9 , V_11 = 0 ;
F_2 (manager, &exynos_drm_manager_list, list) {
if ( V_8 -> V_13 -> V_23 ) {
V_9 = V_8 -> V_13 -> V_23 ( V_8 , V_2 , V_11 ) ;
if ( V_9 ) {
F_4 ( L_3 ,
V_8 -> type , V_9 ) ;
goto V_24;
}
}
V_8 -> V_21 = V_2 ;
V_8 -> V_11 = V_11 ++ ;
V_9 = F_8 ( V_8 ) ;
if ( V_9 ) {
F_4 ( L_4 ,
V_8 -> type , V_9 ) ;
goto V_24;
}
}
return 0 ;
V_24:
F_9 (manager, n, &exynos_drm_manager_list, list) {
if ( V_11 -- > 0 )
F_10 ( V_8 ) ;
else
F_11 ( & V_8 -> V_25 ) ;
}
return V_9 ;
}
void F_12 ( struct V_1 * V_2 )
{
struct V_7 * V_8 , * V_22 ;
F_9 (manager, n, &exynos_drm_manager_list, list)
F_10 ( V_8 ) ;
}
int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_22 ;
int V_9 , V_26 = 0 ;
F_2 (display, &exynos_drm_display_list, list) {
if ( V_4 -> V_13 -> V_23 ) {
V_9 = V_4 -> V_13 -> V_23 ( V_4 , V_2 ) ;
if ( V_9 ) {
F_4 ( L_5 ,
V_4 -> type , V_9 ) ;
goto V_24;
}
}
V_26 ++ ;
V_9 = F_1 ( V_2 , V_4 ) ;
if ( V_9 ) {
F_4 ( L_6 ,
V_4 -> type , V_9 ) ;
goto V_24;
}
}
return 0 ;
V_24:
F_9 (display, n, &exynos_drm_display_list, list) {
if ( V_26 -- > 0 )
F_14 ( V_4 ) ;
else
F_11 ( & V_4 -> V_25 ) ;
}
return V_9 ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_22 ;
F_9 (display, n, &exynos_drm_display_list, list)
F_14 ( V_4 ) ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_18 * V_19 , * V_22 ;
int V_24 ;
if ( ! V_2 )
return - V_27 ;
F_9 (subdrv, n, &exynos_drm_subdrv_list, list) {
V_24 = F_5 ( V_2 , V_19 ) ;
if ( V_24 ) {
F_17 ( L_7 ) ;
F_11 ( & V_19 -> V_25 ) ;
continue;
}
}
return 0 ;
}
int F_18 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
if ( ! V_2 ) {
F_19 ( 1 , L_8 ) ;
return - V_27 ;
}
F_2 (subdrv, &exynos_drm_subdrv_list, list) {
F_6 ( V_2 , V_19 ) ;
}
return 0 ;
}
int F_20 ( struct V_7 * V_8 )
{
F_21 ( ! V_8 -> V_13 ) ;
F_22 ( & V_8 -> V_25 , & V_28 ) ;
return 0 ;
}
int F_10 ( struct V_7 * V_8 )
{
if ( V_8 -> V_13 -> remove )
V_8 -> V_13 -> remove ( V_8 ) ;
F_11 ( & V_8 -> V_25 ) ;
return 0 ;
}
int F_23 ( struct V_3 * V_4 )
{
F_21 ( ! V_4 -> V_13 ) ;
F_22 ( & V_4 -> V_25 , & V_29 ) ;
return 0 ;
}
int F_14 ( struct V_3 * V_4 )
{
if ( V_4 -> V_13 -> remove )
V_4 -> V_13 -> remove ( V_4 ) ;
F_11 ( & V_4 -> V_25 ) ;
return 0 ;
}
int F_24 ( struct V_18 * V_19 )
{
if ( ! V_19 )
return - V_27 ;
F_22 ( & V_19 -> V_25 , & V_30 ) ;
return 0 ;
}
int F_25 ( struct V_18 * V_19 )
{
if ( ! V_19 )
return - V_27 ;
F_11 ( & V_19 -> V_25 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_18 * V_19 ;
int V_9 ;
F_2 (subdrv, &exynos_drm_subdrv_list, list) {
if ( V_19 -> V_33 ) {
V_9 = V_19 -> V_33 ( V_2 , V_19 -> V_2 , V_32 ) ;
if ( V_9 )
goto V_24;
}
}
return 0 ;
V_24:
F_27 (subdrv, &subdrv->list, list) {
if ( V_19 -> V_34 )
V_19 -> V_34 ( V_2 , V_19 -> V_2 , V_32 ) ;
}
return V_9 ;
}
void F_28 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_18 * V_19 ;
F_2 (subdrv, &exynos_drm_subdrv_list, list) {
if ( V_19 -> V_34 )
V_19 -> V_34 ( V_2 , V_19 -> V_2 , V_32 ) ;
}
}
