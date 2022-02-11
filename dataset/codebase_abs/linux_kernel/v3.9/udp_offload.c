static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
struct V_5 * V_6 ;
if ( ! F_2 ( V_2 , sizeof( * V_6 ) ) )
return - V_7 ;
V_4 = F_3 ( V_2 ) ;
V_6 = F_4 ( V_2 ) ;
V_6 -> V_8 = ~ F_5 ( & V_4 -> V_9 , & V_4 -> V_10 , V_2 -> V_11 ,
V_12 , 0 ) ;
V_2 -> V_13 = F_6 ( V_2 ) - V_2 -> V_14 ;
V_2 -> V_15 = F_7 ( struct V_5 , V_8 ) ;
V_2 -> V_16 = V_17 ;
return 0 ;
}
static struct V_1 * F_8 ( struct V_1 * V_2 ,
T_1 V_18 )
{
struct V_1 * V_19 = F_9 ( - V_7 ) ;
unsigned int V_20 ;
unsigned int V_21 , V_22 ;
struct V_23 * V_24 ;
T_2 * V_25 , * V_26 ;
T_2 V_27 ;
T_2 V_28 = sizeof( struct V_23 ) ;
int V_29 ;
T_3 V_30 ;
V_20 = F_10 ( V_2 ) -> V_31 ;
if ( F_11 ( V_2 -> V_11 <= V_20 ) )
goto V_32;
if ( F_12 ( V_2 , V_18 | V_33 ) ) {
int type = F_10 ( V_2 ) -> V_34 ;
if ( F_11 ( type & ~ ( V_35 | V_36 |
V_37 ) ||
! ( type & ( V_35 ) ) ) )
goto V_32;
F_10 ( V_2 ) -> V_38 = F_13 ( V_2 -> V_11 , V_20 ) ;
V_19 = NULL ;
goto V_32;
}
V_29 = F_14 ( V_2 ) ;
V_30 = F_15 ( V_2 , V_29 , V_2 -> V_11 - V_29 , 0 ) ;
V_29 += V_2 -> V_15 ;
* ( V_39 * ) ( V_2 -> V_40 + V_29 ) = F_16 ( V_30 ) ;
V_2 -> V_16 = V_41 ;
if ( ( F_17 ( V_2 ) < V_2 -> V_14 + V_28 ) &&
F_18 ( V_2 , V_28 , 0 , V_42 ) )
goto V_32;
V_21 = F_19 ( V_2 , & V_26 ) ;
V_27 = * V_26 ;
* V_26 = V_43 ;
V_22 = F_20 ( V_2 ) - F_17 ( V_2 ) +
V_21 ;
V_25 = F_17 ( V_2 ) ;
memmove ( V_25 - V_28 , V_25 , V_22 ) ;
V_2 -> V_44 -= V_28 ;
V_2 -> V_45 -= V_28 ;
V_24 = (struct V_23 * ) ( F_20 ( V_2 ) + V_21 ) ;
V_24 -> V_27 = V_27 ;
V_24 -> V_46 = 0 ;
F_21 ( V_24 , (struct V_47 * ) F_22 ( V_2 ) ) ;
V_19 = F_23 ( V_2 , V_18 ) ;
V_32:
return V_19 ;
}
int T_4 F_24 ( void )
{
return F_25 ( & V_48 , V_12 ) ;
}
