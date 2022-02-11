static int F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 , sizeof( struct V_3 ) ) )
return - V_4 ;
if ( F_3 ( ! V_2 -> V_5 ) ) {
const struct V_6 * V_7 ;
struct V_3 * V_8 ;
V_7 = F_4 ( V_2 ) ;
V_8 = F_5 ( V_2 ) ;
V_8 -> V_9 = ~ F_6 ( V_7 -> V_10 , V_7 -> V_11 , V_2 -> V_12 ,
V_13 , 0 ) ;
V_2 -> V_14 = F_7 ( V_2 ) - V_2 -> V_15 ;
V_2 -> V_16 = F_8 ( struct V_3 , V_9 ) ;
V_2 -> V_17 = V_18 ;
}
return 0 ;
}
static struct V_1 * F_9 ( struct V_1 * V_2 ,
T_1 V_19 )
{
struct V_1 * V_20 = F_10 ( - V_4 ) ;
unsigned int V_21 ;
V_21 = F_11 ( V_2 ) -> V_22 ;
if ( F_12 ( V_2 -> V_12 <= V_21 ) )
goto V_23;
if ( F_13 ( V_2 , V_19 | V_24 ) ) {
int type = F_11 ( V_2 ) -> V_25 ;
if ( F_12 ( type & ~ ( V_26 | V_27 |
V_28 |
V_29 | V_30 ) ||
! ( type & ( V_26 ) ) ) )
goto V_23;
F_11 ( V_2 ) -> V_31 = F_14 ( V_2 -> V_12 , V_21 ) ;
V_20 = NULL ;
goto V_23;
}
if ( V_2 -> V_5 && F_11 ( V_2 ) -> V_25 & V_28 )
V_20 = F_15 ( V_2 , V_19 ) ;
else {
int V_32 ;
T_2 V_33 ;
V_32 = F_16 ( V_2 ) ;
V_33 = F_17 ( V_2 , V_32 , V_2 -> V_12 - V_32 , 0 ) ;
V_32 += V_2 -> V_16 ;
* ( V_34 * ) ( V_2 -> V_35 + V_32 ) = F_18 ( V_33 ) ;
V_2 -> V_17 = V_36 ;
V_20 = F_19 ( V_2 , V_19 ) ;
}
V_23:
return V_20 ;
}
int T_3 F_20 ( void )
{
return F_21 ( & V_37 , V_13 ) ;
}
