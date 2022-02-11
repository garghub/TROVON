static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 = 0 ;
if ( F_2 ( V_2 ) -> V_5 & V_6 )
goto V_7;
if ( ! ( F_3 ( V_2 ) -> V_8 & F_4 ( V_9 ) ) || V_2 -> V_10 )
goto V_7;
V_3 = F_5 ( F_6 ( V_2 ) ) ;
if ( V_2 -> V_11 > V_3 ) {
if ( V_2 -> V_12 )
F_7 ( V_2 , V_3 ) ;
else
F_8 ( V_2 , V_13 ,
V_14 , F_9 ( V_3 ) ) ;
V_4 = - V_15 ;
}
V_7:
return V_4 ;
}
int F_10 ( struct V_16 * V_17 , struct V_1 * V_2 )
{
int V_18 ;
V_18 = F_1 ( V_2 ) ;
if ( V_18 )
return V_18 ;
F_11 ( V_2 ) -> V_19 = F_3 ( V_2 ) -> V_19 ;
return F_12 ( V_2 ) ;
}
int F_13 ( struct V_16 * V_17 , struct V_1 * V_2 )
{
int V_18 ;
V_18 = F_14 ( V_17 , V_2 ) ;
if ( V_18 )
return V_18 ;
F_2 ( V_2 ) -> V_5 |= V_6 ;
return V_17 -> V_20 -> V_21 ( V_17 , V_2 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
memset ( F_2 ( V_2 ) , 0 , sizeof( * F_2 ( V_2 ) ) ) ;
V_2 -> V_19 = F_4 ( V_22 ) ;
#ifdef F_16
F_2 ( V_2 ) -> V_5 |= V_23 ;
#endif
return F_17 ( V_2 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_6 ( V_2 ) -> V_24 ;
#ifdef F_16
if ( ! V_17 ) {
F_2 ( V_2 ) -> V_5 |= V_25 ;
return F_19 ( V_2 ) ;
}
#endif
return V_17 -> V_20 -> V_26 -> V_27 ( V_2 ) ;
}
int F_20 ( struct V_28 * V_12 , struct V_1 * V_2 )
{
return F_21 ( V_29 , V_30 , V_2 ,
NULL , F_6 ( V_2 ) -> V_31 , F_18 ,
! ( F_2 ( V_2 ) -> V_5 & V_25 ) ) ;
}
void F_22 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_32 * V_33 ;
V_33 = V_2 -> V_34 ? F_23 ( V_2 ) : F_3 ( V_2 ) ;
F_24 ( V_2 -> V_12 , V_15 , V_33 -> V_35 ,
F_25 ( V_2 -> V_12 ) -> V_36 , V_3 ) ;
}
