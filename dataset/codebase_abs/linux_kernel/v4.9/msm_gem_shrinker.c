static bool F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
if ( ! F_2 ( V_1 ) )
return false ;
#if F_3 ( V_4 ) || F_3 ( V_5 )
return V_1 -> V_6 == V_3 ;
#else
return false ;
#endif
}
static bool F_4 ( struct V_7 * V_8 , bool * V_9 )
{
if ( ! F_5 ( & V_8 -> V_10 ) ) {
if ( ! F_1 ( & V_8 -> V_10 , V_11 ) )
return false ;
* V_9 = false ;
} else {
* V_9 = true ;
}
return true ;
}
static unsigned long
F_6 ( struct V_12 * V_12 , struct V_13 * V_14 )
{
struct V_15 * V_16 =
F_7 ( V_12 , struct V_15 , V_12 ) ;
struct V_7 * V_8 = V_16 -> V_8 ;
struct V_17 * V_18 ;
unsigned long V_19 = 0 ;
bool V_9 ;
if ( ! F_4 ( V_8 , & V_9 ) )
return 0 ;
F_8 (msm_obj, &priv->inactive_list, mm_list) {
if ( F_9 ( V_18 ) )
V_19 += V_18 -> V_20 . V_21 >> V_22 ;
}
if ( V_9 )
F_10 ( & V_8 -> V_10 ) ;
return V_19 ;
}
static unsigned long
F_11 ( struct V_12 * V_12 , struct V_13 * V_14 )
{
struct V_15 * V_16 =
F_7 ( V_12 , struct V_15 , V_12 ) ;
struct V_7 * V_8 = V_16 -> V_8 ;
struct V_17 * V_18 ;
unsigned long V_23 = 0 ;
bool V_9 ;
if ( ! F_4 ( V_8 , & V_9 ) )
return V_24 ;
F_8 (msm_obj, &priv->inactive_list, mm_list) {
if ( V_23 >= V_14 -> V_25 )
break;
if ( F_9 ( V_18 ) ) {
F_12 ( & V_18 -> V_20 ) ;
V_23 += V_18 -> V_20 . V_21 >> V_22 ;
}
}
if ( V_9 )
F_10 ( & V_8 -> V_10 ) ;
if ( V_23 > 0 )
F_13 ( L_1 , V_23 << V_22 ) ;
return V_23 ;
}
static int
F_14 ( struct V_26 * V_27 , unsigned long V_28 , void * V_29 )
{
struct V_15 * V_16 =
F_7 ( V_27 , struct V_15 , V_30 ) ;
struct V_7 * V_8 = V_16 -> V_8 ;
struct V_17 * V_18 ;
unsigned V_31 = 0 ;
bool V_9 ;
if ( ! F_4 ( V_8 , & V_9 ) )
return V_32 ;
F_8 (msm_obj, &priv->inactive_list, mm_list) {
if ( F_15 ( V_18 ) ) {
F_16 ( & V_18 -> V_20 ) ;
if ( ++ V_31 >= 15 )
break;
}
}
if ( V_9 )
F_10 ( & V_8 -> V_10 ) ;
* ( unsigned long * ) V_29 += V_31 ;
if ( V_31 > 0 )
F_13 ( L_2 , V_31 ) ;
return V_32 ;
}
void F_17 ( struct V_7 * V_8 )
{
struct V_15 * V_16 = V_8 -> V_33 ;
V_16 -> V_12 . V_34 = F_6 ;
V_16 -> V_12 . V_35 = F_11 ;
V_16 -> V_12 . V_36 = V_37 ;
F_18 ( F_19 ( & V_16 -> V_12 ) ) ;
V_16 -> V_30 . V_38 = F_14 ;
F_18 ( F_20 ( & V_16 -> V_30 ) ) ;
}
void F_21 ( struct V_7 * V_8 )
{
struct V_15 * V_16 = V_8 -> V_33 ;
if ( V_16 -> V_12 . V_39 ) {
F_18 ( F_22 ( & V_16 -> V_30 ) ) ;
F_23 ( & V_16 -> V_12 ) ;
}
}
