static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
struct V_5 * V_6 ;
if ( V_2 -> V_7 )
return - V_8 ;
if ( ! F_2 ( V_2 , sizeof( * V_6 ) ) )
return - V_8 ;
V_4 = F_3 ( V_2 ) ;
V_6 = F_4 ( V_2 ) ;
V_6 -> V_9 = ~ F_5 ( & V_4 -> V_10 , & V_4 -> V_11 , V_2 -> V_12 ,
V_13 , 0 ) ;
V_2 -> V_14 = F_6 ( V_2 ) - V_2 -> V_15 ;
V_2 -> V_16 = F_7 ( struct V_5 , V_9 ) ;
V_2 -> V_17 = V_18 ;
return 0 ;
}
static struct V_1 * F_8 ( struct V_1 * V_2 ,
T_1 V_19 )
{
struct V_1 * V_20 = F_9 ( - V_8 ) ;
unsigned int V_21 ;
unsigned int V_22 , V_23 ;
struct V_24 * V_25 ;
T_2 * V_26 , * V_27 ;
T_2 V_28 ;
T_2 V_29 = sizeof( struct V_24 ) ;
int V_30 ;
T_3 V_31 ;
int V_32 ;
V_21 = F_10 ( V_2 ) -> V_33 ;
if ( F_11 ( V_2 -> V_12 <= V_21 ) )
goto V_34;
if ( F_12 ( V_2 , V_19 | V_35 ) ) {
int type = F_10 ( V_2 ) -> V_36 ;
if ( F_11 ( type & ~ ( V_37 |
V_38 |
V_39 |
V_40 ) ||
! ( type & ( V_37 ) ) ) )
goto V_34;
F_10 ( V_2 ) -> V_41 = F_13 ( V_2 -> V_12 , V_21 ) ;
V_20 = NULL ;
goto V_34;
}
V_30 = F_14 ( V_2 ) ;
V_31 = F_15 ( V_2 , V_30 , V_2 -> V_12 - V_30 , 0 ) ;
V_30 += V_2 -> V_16 ;
* ( V_42 * ) ( V_2 -> V_43 + V_30 ) = F_16 ( V_31 ) ;
V_2 -> V_17 = V_44 ;
V_32 = F_17 ( V_2 ) ;
if ( F_18 ( V_2 ) < ( V_32 + V_29 ) ) {
if ( F_19 ( V_2 , V_32 + V_29 ) )
goto V_34;
}
V_22 = F_20 ( V_2 , & V_27 ) ;
V_28 = * V_27 ;
* V_27 = V_45 ;
V_23 = ( F_21 ( V_2 ) - F_22 ( V_2 ) ) +
V_22 + V_32 ;
V_26 = ( T_2 * ) V_2 -> V_15 + F_23 ( V_2 ) -> V_46 ;
memmove ( V_26 - V_29 , V_26 , V_23 ) ;
F_23 ( V_2 ) -> V_46 -= V_29 ;
V_2 -> V_47 -= V_29 ;
V_2 -> V_48 -= V_29 ;
V_25 = (struct V_24 * ) ( F_21 ( V_2 ) + V_22 ) ;
V_25 -> V_28 = V_28 ;
V_25 -> V_49 = 0 ;
F_24 ( V_25 , (struct V_50 * ) F_25 ( V_2 ) ) ;
V_20 = F_26 ( V_2 , V_19 ) ;
V_34:
return V_20 ;
}
int T_4 F_27 ( void )
{
return F_28 ( & V_51 , V_13 ) ;
}
