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
void F_3 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_15 * V_16 ;
F_4 ( V_13 -> V_17 . V_18 / V_19 ,
( V_13 -> V_17 . V_20 - V_13 -> V_17 . V_18 ) / V_19 ) ;
F_5 (obj, &dev_priv->mm.gtt_list, gtt_list) {
F_6 ( V_16 ) ;
F_7 ( V_16 , V_16 -> V_4 ) ;
}
F_8 () ;
}
int F_9 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_21 . V_2 ;
struct V_12 * V_13 = V_2 -> V_14 ;
unsigned int V_22 = F_1 ( V_2 , V_16 -> V_4 ) ;
int V_23 ;
if ( V_13 -> V_17 . V_24 -> V_25 ) {
V_23 = F_10 ( V_16 -> V_26 ,
V_16 -> V_21 . V_27 >> V_28 ,
& V_16 -> V_29 ,
& V_16 -> V_30 ) ;
if ( V_23 != 0 )
return V_23 ;
F_11 ( V_16 -> V_29 ,
V_16 -> V_30 ,
V_16 -> V_31 -> V_32 >> V_28 ,
V_22 ) ;
} else
F_12 ( V_16 -> V_31 -> V_32 >> V_28 ,
V_16 -> V_21 . V_27 >> V_28 ,
V_16 -> V_26 ,
V_22 ) ;
return 0 ;
}
void F_7 ( struct V_15 * V_16 ,
enum V_3 V_4 )
{
struct V_1 * V_2 = V_16 -> V_21 . V_2 ;
struct V_12 * V_13 = V_2 -> V_14 ;
unsigned int V_22 = F_1 ( V_2 , V_4 ) ;
if ( V_13 -> V_17 . V_24 -> V_25 ) {
F_13 ( ! V_16 -> V_29 ) ;
F_11 ( V_16 -> V_29 ,
V_16 -> V_30 ,
V_16 -> V_31 -> V_32 >> V_28 ,
V_22 ) ;
} else
F_12 ( V_16 -> V_31 -> V_32 >> V_28 ,
V_16 -> V_21 . V_27 >> V_28 ,
V_16 -> V_26 ,
V_22 ) ;
}
void F_14 ( struct V_15 * V_16 )
{
F_4 ( V_16 -> V_31 -> V_32 >> V_28 ,
V_16 -> V_21 . V_27 >> V_28 ) ;
if ( V_16 -> V_29 ) {
F_15 ( V_16 -> V_29 , V_16 -> V_30 ) ;
V_16 -> V_29 = NULL ;
}
}
