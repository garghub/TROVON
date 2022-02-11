int F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return - V_3 ;
F_2 ( & V_2 -> V_4 , & V_5 ) ;
return 0 ;
}
int F_3 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return - V_3 ;
F_4 ( & V_2 -> V_4 ) ;
return 0 ;
}
int F_5 ( struct V_6 * V_7 )
{
struct V_1 * V_2 , * V_8 ;
int V_9 ;
if ( ! V_7 )
return - V_3 ;
F_6 (subdrv, n, &exynos_drm_subdrv_list, list) {
if ( V_2 -> V_10 ) {
V_2 -> V_11 = V_7 ;
V_9 = V_2 -> V_10 ( V_7 , V_2 -> V_7 ) ;
if ( V_9 ) {
F_7 ( L_1 ) ;
F_4 ( & V_2 -> V_4 ) ;
continue;
}
}
}
return 0 ;
}
int F_8 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
if ( ! V_7 ) {
F_9 ( 1 , L_2 ) ;
return - V_3 ;
}
F_10 (subdrv, &exynos_drm_subdrv_list, list) {
if ( V_2 -> remove )
V_2 -> remove ( V_7 , V_2 -> V_7 ) ;
}
return 0 ;
}
int F_11 ( struct V_6 * V_7 , struct V_12 * V_13 )
{
struct V_1 * V_2 ;
int V_14 ;
F_10 (subdrv, &exynos_drm_subdrv_list, list) {
if ( V_2 -> V_15 ) {
V_14 = V_2 -> V_15 ( V_7 , V_2 -> V_7 , V_13 ) ;
if ( V_14 )
goto V_9;
}
}
return 0 ;
V_9:
F_12 (subdrv, &subdrv->list, list) {
if ( V_2 -> V_16 )
V_2 -> V_16 ( V_7 , V_2 -> V_7 , V_13 ) ;
}
return V_14 ;
}
void F_13 ( struct V_6 * V_7 , struct V_12 * V_13 )
{
struct V_1 * V_2 ;
F_10 (subdrv, &exynos_drm_subdrv_list, list) {
if ( V_2 -> V_16 )
V_2 -> V_16 ( V_7 , V_2 -> V_7 , V_13 ) ;
}
}
