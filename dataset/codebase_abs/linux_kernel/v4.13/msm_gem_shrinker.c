static bool F_1 ( struct V_1 * V_2 , bool * V_3 )
{
switch ( F_2 ( & V_2 -> V_4 ) ) {
case V_5 :
return false ;
case V_6 :
* V_3 = true ;
return true ;
case V_7 :
* V_3 = false ;
return true ;
}
F_3 () ;
}
static unsigned long
F_4 ( struct V_8 * V_8 , struct V_9 * V_10 )
{
struct V_11 * V_12 =
F_5 ( V_8 , struct V_11 , V_8 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_13 * V_14 ;
unsigned long V_15 = 0 ;
bool V_3 ;
if ( ! F_1 ( V_2 , & V_3 ) )
return 0 ;
F_6 (msm_obj, &priv->inactive_list, mm_list) {
if ( F_7 ( V_14 ) )
V_15 += V_14 -> V_16 . V_17 >> V_18 ;
}
if ( V_3 )
F_8 ( & V_2 -> V_4 ) ;
return V_15 ;
}
static unsigned long
F_9 ( struct V_8 * V_8 , struct V_9 * V_10 )
{
struct V_11 * V_12 =
F_5 ( V_8 , struct V_11 , V_8 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_13 * V_14 ;
unsigned long V_19 = 0 ;
bool V_3 ;
if ( ! F_1 ( V_2 , & V_3 ) )
return V_20 ;
F_6 (msm_obj, &priv->inactive_list, mm_list) {
if ( V_19 >= V_10 -> V_21 )
break;
if ( F_7 ( V_14 ) ) {
F_10 ( & V_14 -> V_16 , V_22 ) ;
V_19 += V_14 -> V_16 . V_17 >> V_18 ;
}
}
if ( V_3 )
F_8 ( & V_2 -> V_4 ) ;
if ( V_19 > 0 )
F_11 ( L_1 , V_19 << V_18 ) ;
return V_19 ;
}
static int
F_12 ( struct V_23 * V_24 , unsigned long V_25 , void * V_26 )
{
struct V_11 * V_12 =
F_5 ( V_24 , struct V_11 , V_27 ) ;
struct V_1 * V_2 = V_12 -> V_2 ;
struct V_13 * V_14 ;
unsigned V_28 = 0 ;
bool V_3 ;
if ( ! F_1 ( V_2 , & V_3 ) )
return V_29 ;
F_6 (msm_obj, &priv->inactive_list, mm_list) {
if ( F_13 ( V_14 ) ) {
F_14 ( & V_14 -> V_16 , V_22 ) ;
if ( ++ V_28 >= 15 )
break;
}
}
if ( V_3 )
F_8 ( & V_2 -> V_4 ) ;
* ( unsigned long * ) V_26 += V_28 ;
if ( V_28 > 0 )
F_11 ( L_2 , V_28 ) ;
return V_29 ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_30 ;
V_12 -> V_8 . V_31 = F_4 ;
V_12 -> V_8 . V_32 = F_9 ;
V_12 -> V_8 . V_33 = V_34 ;
F_16 ( F_17 ( & V_12 -> V_8 ) ) ;
V_12 -> V_27 . V_35 = F_12 ;
F_16 ( F_18 ( & V_12 -> V_27 ) ) ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_30 ;
if ( V_12 -> V_8 . V_36 ) {
F_16 ( F_20 ( & V_12 -> V_27 ) ) ;
F_21 ( & V_12 -> V_8 ) ;
}
}
