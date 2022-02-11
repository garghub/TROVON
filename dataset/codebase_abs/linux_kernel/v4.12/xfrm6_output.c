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
if ( V_8 -> V_9 != V_10 )
return 0 ;
V_6 = V_8 -> V_11 ;
if ( V_6 == V_12 || V_6 == V_13 )
return F_4 ( V_8 ) -> V_14 ;
}
return 0 ;
}
static void F_5 ( struct V_3 * V_4 , T_2 V_15 )
{
struct V_16 V_17 ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_17 . V_18 = V_8 -> V_19 ;
V_17 . V_20 = F_6 ( V_4 ) -> V_20 ;
F_7 ( V_8 , & V_17 , V_15 ) ;
}
void F_8 ( struct V_3 * V_4 , T_2 V_15 )
{
struct V_16 V_17 ;
const struct V_21 * V_22 ;
struct V_7 * V_8 = V_4 -> V_8 ;
V_22 = V_4 -> V_23 ? F_9 ( V_4 ) : F_6 ( V_4 ) ;
V_17 . V_24 = F_10 ( V_8 ) -> V_25 ;
V_17 . V_20 = V_22 -> V_20 ;
F_11 ( V_8 , V_26 , & V_17 , V_15 ) ;
}
static int F_12 ( struct V_3 * V_4 )
{
int V_15 , V_27 = 0 ;
struct V_28 * V_29 = F_13 ( V_4 ) ;
if ( V_4 -> V_30 )
goto V_31;
V_15 = F_14 ( V_29 ) ;
if ( V_15 < V_32 )
V_15 = V_32 ;
if ( ( ! F_15 ( V_4 ) && V_4 -> V_33 > V_15 ) ||
( F_15 ( V_4 ) &&
F_16 ( V_4 ) > F_17 ( V_4 ) ) ) {
V_4 -> V_34 = V_29 -> V_34 ;
V_4 -> V_35 = F_18 ( V_36 ) ;
if ( F_3 ( V_4 ) )
F_5 ( V_4 , V_15 ) ;
else if ( V_4 -> V_8 )
F_19 ( V_4 , V_15 ) ;
else
F_20 ( V_4 , V_37 , 0 , V_15 ) ;
V_27 = - V_26 ;
}
V_31:
return V_27 ;
}
int F_21 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_38 ;
V_38 = F_12 ( V_4 ) ;
if ( V_38 )
return V_38 ;
F_22 ( V_4 ) -> V_35 = F_6 ( V_4 ) -> V_39 ;
return F_23 ( V_4 ) ;
}
int F_24 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_38 ;
V_38 = F_25 ( V_2 , V_4 ) ;
if ( V_38 )
return V_38 ;
V_4 -> V_30 = 1 ;
V_4 -> V_35 = F_18 ( V_36 ) ;
return V_2 -> V_40 -> V_41 ( V_2 , V_4 ) ;
}
int F_26 ( struct V_7 * V_8 , struct V_3 * V_4 )
{
memset ( F_27 ( V_4 ) , 0 , sizeof( * F_27 ( V_4 ) ) ) ;
#ifdef F_28
F_27 ( V_4 ) -> V_42 |= V_43 ;
#endif
return F_29 ( V_8 , V_4 ) ;
}
static int F_30 ( struct V_44 * V_44 , struct V_7 * V_8 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_13 ( V_4 ) -> V_45 ;
return V_2 -> V_40 -> V_46 -> V_47 ( V_8 , V_4 ) ;
}
static int F_31 ( struct V_44 * V_44 , struct V_7 * V_8 , struct V_3 * V_4 )
{
struct V_28 * V_29 = F_13 ( V_4 ) ;
struct V_1 * V_2 = V_29 -> V_45 ;
int V_15 ;
bool V_48 ;
#ifdef F_28
if ( ! V_2 ) {
F_27 ( V_4 ) -> V_42 |= V_49 ;
return F_32 ( V_44 , V_8 , V_4 ) ;
}
#endif
if ( V_2 -> V_50 . V_51 != V_52 )
goto V_53;
if ( V_4 -> V_35 == F_18 ( V_36 ) )
V_15 = F_17 ( V_4 ) ;
else
V_15 = F_14 ( F_13 ( V_4 ) ) ;
V_48 = V_4 -> V_33 > V_15 && ! F_15 ( V_4 ) ;
if ( V_48 && F_3 ( V_4 ) ) {
F_5 ( V_4 , V_15 ) ;
return - V_26 ;
} else if ( ! V_4 -> V_30 && V_48 && V_4 -> V_8 ) {
F_19 ( V_4 , V_15 ) ;
return - V_26 ;
}
if ( V_48 || F_33 ( F_13 ( V_4 ) ) )
return F_34 ( V_44 , V_8 , V_4 ,
F_30 ) ;
V_53:
return V_2 -> V_40 -> V_46 -> V_47 ( V_8 , V_4 ) ;
}
int F_35 ( struct V_44 * V_44 , struct V_7 * V_8 , struct V_3 * V_4 )
{
return F_36 ( V_54 , V_55 ,
V_44 , V_8 , V_4 , NULL , F_13 ( V_4 ) -> V_34 ,
F_31 ,
! ( F_27 ( V_4 ) -> V_42 & V_49 ) ) ;
}
