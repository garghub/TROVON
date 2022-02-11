int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
unsigned long V_8 = 0 ;
V_7 = F_2 ( V_2 , V_4 -> type ) ;
if ( V_7 < 0 )
return V_7 ;
V_8 |= 1 << V_7 ;
V_6 = F_3 ( V_2 , V_4 , V_8 ) ;
if ( ! V_6 ) {
F_4 ( L_1 ) ;
return - V_9 ;
}
V_4 -> V_6 = V_6 ;
V_7 = V_4 -> V_10 -> V_11 ( V_4 , V_6 ) ;
if ( V_7 ) {
F_4 ( L_2 , V_7 ) ;
goto V_12;
}
return 0 ;
V_12:
V_6 -> V_13 -> V_14 ( V_6 ) ;
return V_7 ;
}
int F_5 ( struct V_15 * V_16 )
{
if ( ! V_16 )
return - V_17 ;
F_6 ( & V_16 -> V_18 , & V_19 ) ;
return 0 ;
}
int F_7 ( struct V_15 * V_16 )
{
if ( ! V_16 )
return - V_17 ;
F_8 ( & V_16 -> V_18 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_15 * V_16 , * V_20 ;
int V_21 ;
if ( ! V_2 )
return - V_17 ;
F_10 (subdrv, n, &exynos_drm_subdrv_list, list) {
if ( V_16 -> V_22 ) {
V_16 -> V_23 = V_2 ;
V_21 = V_16 -> V_22 ( V_2 , V_16 -> V_2 ) ;
if ( V_21 ) {
F_11 ( L_3 ) ;
F_8 ( & V_16 -> V_18 ) ;
continue;
}
}
}
return 0 ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
if ( ! V_2 ) {
F_13 ( 1 , L_4 ) ;
return - V_17 ;
}
F_14 (subdrv, &exynos_drm_subdrv_list, list) {
if ( V_16 -> remove )
V_16 -> remove ( V_2 , V_16 -> V_2 ) ;
}
return 0 ;
}
int F_15 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_15 * V_16 ;
int V_7 ;
F_14 (subdrv, &exynos_drm_subdrv_list, list) {
if ( V_16 -> V_26 ) {
V_7 = V_16 -> V_26 ( V_2 , V_16 -> V_2 , V_25 ) ;
if ( V_7 )
goto V_21;
}
}
return 0 ;
V_21:
F_16 (subdrv, &subdrv->list, list) {
if ( V_16 -> V_27 )
V_16 -> V_27 ( V_2 , V_16 -> V_2 , V_25 ) ;
}
return V_7 ;
}
void F_17 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_15 * V_16 ;
F_14 (subdrv, &exynos_drm_subdrv_list, list) {
if ( V_16 -> V_27 )
V_16 -> V_27 ( V_2 , V_16 -> V_2 , V_25 ) ;
}
}
