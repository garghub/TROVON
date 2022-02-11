static struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 ;
F_2 (gov, &cpuidle_governors, governor_list)
if ( ! F_3 ( V_2 , V_3 -> V_4 , V_5 ) )
return V_3 ;
return NULL ;
}
int F_4 ( struct V_1 * V_3 )
{
struct V_6 * V_7 ;
if ( V_3 == V_8 )
return 0 ;
F_5 () ;
if ( V_8 ) {
F_2 (dev, &cpuidle_detected_devices, device_list)
F_6 ( V_7 ) ;
F_7 ( V_8 -> V_9 ) ;
}
V_8 = V_3 ;
if ( V_3 ) {
if ( ! F_8 ( V_8 -> V_9 ) )
return - V_10 ;
F_2 (dev, &cpuidle_detected_devices, device_list)
F_9 ( V_7 ) ;
F_10 () ;
F_11 ( V_11 L_1 , V_3 -> V_4 ) ;
}
return 0 ;
}
int F_12 ( struct V_1 * V_3 )
{
int V_12 = - V_13 ;
if ( ! V_3 || ! V_3 -> V_14 )
return - V_10 ;
if ( F_13 () )
return - V_15 ;
F_14 ( & V_16 ) ;
if ( F_1 ( V_3 -> V_4 ) == NULL ) {
V_12 = 0 ;
F_15 ( & V_3 -> V_17 , & V_18 ) ;
if ( ! V_8 ||
V_8 -> V_19 < V_3 -> V_19 )
F_4 ( V_3 ) ;
}
F_16 ( & V_16 ) ;
return V_12 ;
}
static struct V_1 * F_17 ( int V_20 )
{
struct V_1 * V_3 ;
struct V_1 * V_21 = NULL ;
unsigned int V_22 = 0 ;
F_2 (gov, &cpuidle_governors, governor_list) {
if ( V_3 -> V_19 == V_20 )
continue;
if ( V_3 -> V_19 > V_22 ) {
V_22 = V_3 -> V_19 ;
V_21 = V_3 ;
}
}
return V_21 ;
}
void F_18 ( struct V_1 * V_3 )
{
if ( ! V_3 )
return;
F_14 ( & V_16 ) ;
if ( V_3 == V_8 ) {
struct V_1 * V_23 ;
V_23 = F_17 ( V_3 -> V_19 ) ;
F_4 ( V_23 ) ;
}
F_19 ( & V_3 -> V_17 ) ;
F_16 ( & V_16 ) ;
}
