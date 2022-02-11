static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 = 0 ;
struct V_5 * V_6 ;
if ( F_2 ( V_2 ) -> V_7 & V_8 )
goto V_9;
if ( ! ( F_3 ( V_2 ) -> V_10 & F_4 ( V_11 ) ) || V_2 -> V_12 )
goto V_9;
V_6 = F_5 ( V_2 ) ;
V_3 = F_6 ( V_6 ) ;
if ( V_2 -> V_13 > V_3 ) {
if ( V_2 -> V_14 )
F_7 ( V_2 -> V_14 , V_15 , F_3 ( V_2 ) -> V_16 ,
F_8 ( V_2 -> V_14 ) -> V_17 , V_3 ) ;
else
F_9 ( V_2 , V_18 ,
V_19 , F_10 ( V_3 ) ) ;
V_4 = - V_15 ;
}
V_9:
return V_4 ;
}
int F_11 ( struct V_20 * V_21 , struct V_1 * V_2 )
{
int V_22 ;
V_22 = F_1 ( V_2 ) ;
if ( V_22 )
return V_22 ;
F_12 ( V_2 ) -> V_23 = F_3 ( V_2 ) -> V_23 ;
return F_13 ( V_2 ) ;
}
int F_14 ( struct V_20 * V_21 , struct V_1 * V_2 )
{
int V_22 ;
V_22 = F_15 ( V_21 , V_2 ) ;
if ( V_22 )
return V_22 ;
memset ( F_2 ( V_2 ) , 0 , sizeof( * F_2 ( V_2 ) ) ) ;
F_2 ( V_2 ) -> V_7 |= V_8 | V_24 ;
V_2 -> V_23 = F_4 ( V_25 ) ;
return V_21 -> V_26 -> V_27 ( V_21 , V_2 ) ;
}
int F_16 ( struct V_1 * V_2 )
{
#ifdef F_17
if ( ! F_5 ( V_2 ) -> V_28 ) {
F_2 ( V_2 ) -> V_7 |= V_29 ;
return F_18 ( V_2 ) ;
}
F_2 ( V_2 ) -> V_7 |= V_24 ;
#endif
V_2 -> V_23 = F_4 ( V_25 ) ;
return F_19 ( V_2 ) ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
struct V_20 * V_21 = V_6 -> V_28 ;
return F_21 ( V_30 , V_31 , V_2 ,
NULL , V_6 -> V_32 ,
V_21 -> V_26 -> V_33 -> V_34 ,
! ( F_2 ( V_2 ) -> V_7 & V_29 ) ) ;
}
