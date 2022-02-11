static struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 ;
F_2 (gov, &cpuidle_governors, governor_list)
if ( ! strncasecmp ( V_2 , V_3 -> V_4 , V_5 ) )
return V_3 ;
return NULL ;
}
int F_3 ( struct V_1 * V_3 )
{
struct V_6 * V_7 ;
if ( V_3 == V_8 )
return 0 ;
F_4 () ;
if ( V_8 ) {
F_2 (dev, &cpuidle_detected_devices, device_list)
F_5 ( V_7 ) ;
}
V_8 = V_3 ;
if ( V_3 ) {
F_2 (dev, &cpuidle_detected_devices, device_list)
F_6 ( V_7 ) ;
F_7 () ;
F_8 ( V_9 L_1 , V_3 -> V_4 ) ;
}
return 0 ;
}
int F_9 ( struct V_1 * V_3 )
{
int V_10 = - V_11 ;
if ( ! V_3 || ! V_3 -> V_12 )
return - V_13 ;
if ( F_10 () )
return - V_14 ;
F_11 ( & V_15 ) ;
if ( F_1 ( V_3 -> V_4 ) == NULL ) {
V_10 = 0 ;
F_12 ( & V_3 -> V_16 , & V_17 ) ;
if ( ! V_8 ||
V_8 -> V_18 < V_3 -> V_18 )
F_3 ( V_3 ) ;
}
F_13 ( & V_15 ) ;
return V_10 ;
}
