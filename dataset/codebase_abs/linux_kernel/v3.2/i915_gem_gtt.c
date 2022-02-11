static unsigned int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
switch ( V_4 ) {
case V_5 :
if ( F_2 ( V_2 ) -> V_6 >= 6 )
return V_7 ;
case V_8 :
return V_9 ;
default:
case V_10 :
return V_11 ;
}
}
static bool F_3 ( struct V_12 * V_13 )
{
bool V_14 = V_13 -> V_15 . V_16 ;
if ( F_4 ( V_13 -> V_15 . V_17 -> V_18 ) ) {
V_13 -> V_15 . V_16 = false ;
if ( F_5 ( V_13 -> V_2 ) ) {
F_6 ( L_1 ) ;
F_7 ( 10 ) ;
}
}
return V_14 ;
}
static void F_8 ( struct V_12 * V_13 , bool V_16 )
{
if ( F_4 ( V_13 -> V_15 . V_17 -> V_18 ) )
V_13 -> V_15 . V_16 = V_16 ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_19 ;
struct V_20 * V_21 ;
F_10 ( V_13 -> V_15 . V_22 / V_23 ,
( V_13 -> V_15 . V_24 - V_13 -> V_15 . V_22 ) / V_23 ) ;
F_11 (obj, &dev_priv->mm.gtt_list, gtt_list) {
F_12 ( V_21 ) ;
F_13 ( V_21 , V_21 -> V_4 ) ;
}
F_14 () ;
}
int F_15 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_25 . V_2 ;
struct V_12 * V_13 = V_2 -> V_19 ;
unsigned int V_26 = F_1 ( V_2 , V_21 -> V_4 ) ;
int V_14 ;
if ( V_13 -> V_15 . V_17 -> V_27 ) {
V_14 = F_16 ( V_21 -> V_28 ,
V_21 -> V_25 . V_29 >> V_30 ,
& V_21 -> V_31 ,
& V_21 -> V_32 ) ;
if ( V_14 != 0 )
return V_14 ;
F_17 ( V_21 -> V_31 ,
V_21 -> V_32 ,
V_21 -> V_33 -> V_34 >> V_30 ,
V_26 ) ;
} else
F_18 ( V_21 -> V_33 -> V_34 >> V_30 ,
V_21 -> V_25 . V_29 >> V_30 ,
V_21 -> V_28 ,
V_26 ) ;
return 0 ;
}
void F_13 ( struct V_20 * V_21 ,
enum V_3 V_4 )
{
struct V_1 * V_2 = V_21 -> V_25 . V_2 ;
struct V_12 * V_13 = V_2 -> V_19 ;
unsigned int V_26 = F_1 ( V_2 , V_4 ) ;
if ( V_13 -> V_15 . V_17 -> V_27 ) {
F_19 ( ! V_21 -> V_31 ) ;
F_17 ( V_21 -> V_31 ,
V_21 -> V_32 ,
V_21 -> V_33 -> V_34 >> V_30 ,
V_26 ) ;
} else
F_18 ( V_21 -> V_33 -> V_34 >> V_30 ,
V_21 -> V_25 . V_29 >> V_30 ,
V_21 -> V_28 ,
V_26 ) ;
}
void F_20 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_25 . V_2 ;
struct V_12 * V_13 = V_2 -> V_19 ;
bool V_16 ;
V_16 = F_3 ( V_13 ) ;
F_10 ( V_21 -> V_33 -> V_34 >> V_30 ,
V_21 -> V_25 . V_29 >> V_30 ) ;
if ( V_21 -> V_31 ) {
F_21 ( V_21 -> V_31 , V_21 -> V_32 ) ;
V_21 -> V_31 = NULL ;
}
F_8 ( V_13 , V_16 ) ;
}
