static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 = 0 ;
if ( F_2 ( V_2 ) -> V_5 & V_6 )
goto V_7;
if ( ! ( F_3 ( V_2 ) -> V_8 & F_4 ( V_9 ) ) || V_2 -> V_10 )
goto V_7;
V_3 = F_5 ( F_6 ( V_2 ) ) ;
if ( ( ! F_7 ( V_2 ) && V_2 -> V_11 > V_3 ) ||
( F_7 ( V_2 ) && F_8 ( V_2 ) > F_9 ( V_2 -> V_12 , V_2 ) ) ) {
V_2 -> V_13 = F_4 ( V_14 ) ;
if ( V_2 -> V_12 )
F_10 ( V_2 , V_3 ) ;
else
F_11 ( V_2 , V_15 ,
V_16 , F_12 ( V_3 ) ) ;
V_4 = - V_17 ;
}
V_7:
return V_4 ;
}
int F_13 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
int V_20 ;
V_20 = F_1 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_14 ( V_2 ) -> V_13 = F_3 ( V_2 ) -> V_13 ;
return F_15 ( V_2 ) ;
}
int F_16 ( struct V_18 * V_19 , struct V_1 * V_2 )
{
int V_20 ;
V_20 = F_17 ( V_19 , V_2 ) ;
if ( V_20 )
return V_20 ;
F_2 ( V_2 ) -> V_5 |= V_6 ;
V_2 -> V_13 = F_4 ( V_14 ) ;
return V_19 -> V_21 -> V_22 ( V_19 , V_2 ) ;
}
int F_18 ( struct V_23 * V_12 , struct V_1 * V_2 )
{
memset ( F_2 ( V_2 ) , 0 , sizeof( * F_2 ( V_2 ) ) ) ;
#ifdef F_19
F_2 ( V_2 ) -> V_5 |= V_24 ;
#endif
return F_20 ( V_12 , V_2 ) ;
}
static int F_21 ( struct V_25 * V_25 , struct V_23 * V_12 , struct V_1 * V_2 )
{
struct V_18 * V_19 = F_6 ( V_2 ) -> V_26 ;
#ifdef F_19
if ( ! V_19 ) {
F_2 ( V_2 ) -> V_5 |= V_27 ;
return F_22 ( V_25 , V_12 , V_2 ) ;
}
#endif
return V_19 -> V_21 -> V_28 -> V_29 ( V_12 , V_2 ) ;
}
int F_23 ( struct V_25 * V_25 , struct V_23 * V_12 , struct V_1 * V_2 )
{
return F_24 ( V_30 , V_31 ,
V_25 , V_12 , V_2 , NULL , F_6 ( V_2 ) -> V_32 ,
F_21 ,
! ( F_2 ( V_2 ) -> V_5 & V_27 ) ) ;
}
void F_25 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_33 * V_34 ;
V_34 = V_2 -> V_35 ? F_26 ( V_2 ) : F_3 ( V_2 ) ;
F_27 ( V_2 -> V_12 , V_17 , V_34 -> V_36 ,
F_28 ( V_2 -> V_12 ) -> V_37 , V_3 ) ;
}
