int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 * * V_5 )
{
return F_2 ( V_4 , V_5 ) ;
}
static int F_3 ( struct V_3 * V_4 )
{
int V_6 ;
struct V_7 * V_8 = V_4 -> V_8 ;
if ( V_8 ) {
V_6 = V_8 -> V_9 ;
if ( V_6 == V_10 || V_6 == V_11 )
return F_4 ( V_8 ) -> V_12 ;
}
return 0 ;
}
static void F_5 ( struct V_3 * V_4 , T_2 V_13 )
{
struct V_14 V_15 ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_15 . V_16 = V_8 -> V_17 ;
V_15 . V_18 = F_6 ( V_4 ) -> V_18 ;
F_7 ( V_8 , & V_15 , V_13 ) ;
}
static void F_8 ( struct V_3 * V_4 , T_2 V_13 )
{
struct V_14 V_15 ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_15 . V_19 = F_9 ( V_8 ) -> V_20 ;
V_15 . V_18 = F_6 ( V_4 ) -> V_18 ;
F_10 ( V_8 , V_21 , & V_15 , V_13 ) ;
}
static int F_11 ( struct V_3 * V_4 )
{
int V_13 , V_22 = 0 ;
struct V_23 * V_24 = F_12 ( V_4 ) ;
V_13 = F_13 ( V_24 ) ;
if ( V_13 < V_25 )
V_13 = V_25 ;
if ( ! V_4 -> V_26 && V_4 -> V_27 > V_13 ) {
V_4 -> V_28 = V_24 -> V_28 ;
if ( F_3 ( V_4 ) )
F_5 ( V_4 , V_13 ) ;
else if ( V_4 -> V_8 )
F_8 ( V_4 , V_13 ) ;
else
F_14 ( V_4 , V_29 , 0 , V_13 ) ;
V_22 = - V_21 ;
}
return V_22 ;
}
int F_15 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_30 ;
V_30 = F_11 ( V_4 ) ;
if ( V_30 )
return V_30 ;
F_16 ( V_4 ) -> V_31 = F_6 ( V_4 ) -> V_32 ;
return F_17 ( V_4 ) ;
}
int F_18 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_30 ;
V_30 = F_19 ( V_2 , V_4 ) ;
if ( V_30 )
return V_30 ;
memset ( F_20 ( V_4 ) , 0 , sizeof( * F_20 ( V_4 ) ) ) ;
#ifdef F_21
F_20 ( V_4 ) -> V_33 |= V_34 ;
#endif
V_4 -> V_31 = F_22 ( V_35 ) ;
V_4 -> V_26 = 1 ;
return V_2 -> V_36 -> V_37 ( V_2 , V_4 ) ;
}
int F_23 ( struct V_3 * V_4 )
{
#ifdef F_21
F_20 ( V_4 ) -> V_33 |= V_34 ;
#endif
V_4 -> V_31 = F_22 ( V_35 ) ;
return F_24 ( V_4 ) ;
}
static int F_25 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = F_12 ( V_4 ) ;
struct V_1 * V_2 = V_24 -> V_38 ;
int V_13 = F_26 ( V_4 ) ;
if ( V_4 -> V_27 > V_13 && F_3 ( V_4 ) ) {
F_5 ( V_4 , V_13 ) ;
return - V_21 ;
} else if ( ! V_4 -> V_26 && V_4 -> V_27 > V_13 && V_4 -> V_8 ) {
F_8 ( V_4 , V_13 ) ;
return - V_21 ;
}
if ( ( V_2 && V_2 -> V_39 . V_40 == V_41 ) &&
( ( V_4 -> V_27 > V_13 && ! F_27 ( V_4 ) ) ||
F_28 ( F_12 ( V_4 ) ) ) ) {
return F_29 ( V_4 , V_2 -> V_36 -> V_42 -> V_43 ) ;
}
return V_2 -> V_36 -> V_42 -> V_43 ( V_4 ) ;
}
int F_30 ( struct V_3 * V_4 )
{
return F_31 ( V_44 , V_45 , V_4 , NULL ,
F_12 ( V_4 ) -> V_28 , F_25 ) ;
}
