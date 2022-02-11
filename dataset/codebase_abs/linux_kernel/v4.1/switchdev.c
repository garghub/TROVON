int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_2 -> V_5 ;
if ( ! V_6 || ! V_6 -> V_7 )
return - V_8 ;
return V_6 -> V_7 ( V_2 , V_4 ) ;
}
int F_2 ( struct V_1 * V_2 , T_1 V_9 )
{
const struct V_5 * V_6 = V_2 -> V_5 ;
struct V_1 * V_10 ;
struct V_11 * V_12 ;
int V_13 = - V_8 ;
if ( V_6 && V_6 -> V_14 )
return V_6 -> V_14 ( V_2 , V_9 ) ;
F_3 (dev, lower_dev, iter) {
V_13 = F_2 ( V_10 , V_9 ) ;
if ( V_13 && V_13 != - V_8 )
return V_13 ;
}
return V_13 ;
}
int F_4 ( struct V_15 * V_16 )
{
int V_13 ;
F_5 ( & V_17 ) ;
V_13 = F_6 ( & V_18 , V_16 ) ;
F_7 ( & V_17 ) ;
return V_13 ;
}
int F_8 ( struct V_15 * V_16 )
{
int V_13 ;
F_5 ( & V_17 ) ;
V_13 = F_9 ( & V_18 , V_16 ) ;
F_7 ( & V_17 ) ;
return V_13 ;
}
int F_10 ( unsigned long V_19 , struct V_1 * V_2 ,
struct V_20 * V_21 )
{
int V_13 ;
V_21 -> V_2 = V_2 ;
F_5 ( & V_17 ) ;
V_13 = F_11 ( & V_18 , V_19 , V_21 ) ;
F_7 ( & V_17 ) ;
return V_13 ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_22 * V_23 , T_2 V_24 )
{
const struct V_25 * V_6 = V_2 -> V_26 ;
if ( ! ( V_2 -> V_27 & V_28 ) )
return 0 ;
if ( ! V_6 -> V_29 )
return - V_8 ;
return V_6 -> V_29 ( V_2 , V_23 , V_24 ) ;
}
int F_13 ( struct V_1 * V_2 ,
struct V_22 * V_23 , T_2 V_24 )
{
const struct V_25 * V_6 = V_2 -> V_26 ;
if ( ! ( V_2 -> V_27 & V_28 ) )
return 0 ;
if ( ! V_6 -> V_30 )
return - V_8 ;
return V_6 -> V_30 ( V_2 , V_23 , V_24 ) ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_22 * V_23 , T_2 V_24 )
{
struct V_1 * V_10 ;
struct V_11 * V_12 ;
int V_31 = 0 , V_13 = 0 ;
if ( ! ( V_2 -> V_27 & V_28 ) )
return V_31 ;
F_3 (dev, lower_dev, iter) {
V_13 = F_12 ( V_10 , V_23 , V_24 ) ;
if ( V_13 && V_13 != - V_8 )
V_31 = V_13 ;
}
return V_31 ;
}
int F_15 ( struct V_1 * V_2 ,
struct V_22 * V_23 , T_2 V_24 )
{
struct V_1 * V_10 ;
struct V_11 * V_12 ;
int V_31 = 0 , V_13 = 0 ;
if ( ! ( V_2 -> V_27 & V_28 ) )
return V_31 ;
F_3 (dev, lower_dev, iter) {
V_13 = F_13 ( V_10 , V_23 , V_24 ) ;
if ( V_13 && V_13 != - V_8 )
V_31 = V_13 ;
}
return V_31 ;
}
static struct V_1 * F_16 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = V_2 -> V_5 ;
struct V_1 * V_10 ;
struct V_1 * V_32 ;
struct V_11 * V_12 ;
if ( V_2 -> V_27 & V_28 &&
V_6 && V_6 -> V_7 )
return V_2 ;
F_3 (dev, lower_dev, iter) {
V_32 = F_16 ( V_10 ) ;
if ( V_32 )
return V_32 ;
}
return NULL ;
}
static struct V_1 * F_17 ( struct V_33 * V_34 )
{
struct V_3 V_4 ;
struct V_3 V_35 ;
struct V_1 * V_2 = NULL ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_34 -> V_37 ; V_36 ++ ) {
const struct V_38 * V_39 = & V_34 -> V_38 [ V_36 ] ;
if ( ! V_39 -> V_40 )
return NULL ;
V_2 = F_16 ( V_39 -> V_40 ) ;
if ( ! V_2 )
return NULL ;
if ( F_1 ( V_2 , & V_4 ) )
return NULL ;
if ( V_36 > 0 ) {
if ( V_35 . V_41 != V_4 . V_41 )
return NULL ;
if ( memcmp ( V_35 . V_42 , V_4 . V_42 , V_4 . V_41 ) )
return NULL ;
}
V_35 = V_4 ;
}
return V_2 ;
}
int F_18 ( T_3 V_43 , int V_44 , struct V_33 * V_34 ,
T_1 V_45 , T_1 type , T_3 V_46 , T_3 V_47 )
{
struct V_1 * V_2 ;
const struct V_5 * V_6 ;
int V_13 = 0 ;
#ifdef F_19
if ( V_34 -> V_48 -> V_49 . V_50 )
return 0 ;
#endif
if ( V_34 -> V_48 -> V_49 . V_51 )
return 0 ;
V_2 = F_17 ( V_34 ) ;
if ( ! V_2 )
return 0 ;
V_6 = V_2 -> V_5 ;
if ( V_6 -> V_52 ) {
V_13 = V_6 -> V_52 ( V_2 , F_20 ( V_43 ) , V_44 ,
V_34 , V_45 , type , V_46 ,
V_47 ) ;
if ( ! V_13 )
V_34 -> V_53 |= V_54 ;
}
return V_13 ;
}
int F_21 ( T_3 V_43 , int V_44 , struct V_33 * V_34 ,
T_1 V_45 , T_1 type , T_3 V_47 )
{
struct V_1 * V_2 ;
const struct V_5 * V_6 ;
int V_13 = 0 ;
if ( ! ( V_34 -> V_53 & V_54 ) )
return 0 ;
V_2 = F_17 ( V_34 ) ;
if ( ! V_2 )
return 0 ;
V_6 = V_2 -> V_5 ;
if ( V_6 -> V_55 ) {
V_13 = V_6 -> V_55 ( V_2 , F_20 ( V_43 ) , V_44 ,
V_34 , V_45 , type , V_47 ) ;
if ( ! V_13 )
V_34 -> V_53 &= ~ V_54 ;
}
return V_13 ;
}
void F_22 ( struct V_33 * V_34 )
{
F_23 ( V_34 -> V_48 ) ;
V_34 -> V_48 -> V_49 . V_51 = true ;
}
