void F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
T_1 V_5 )
{
V_2 -> V_6 = 0 ;
V_2 -> V_7 = V_5 ;
V_2 -> V_8 = * V_4 ;
F_2 ( sizeof( * V_2 ) ==
( F_3 ( struct V_1 , V_8 ) +
sizeof( V_2 -> V_8 ) ) ) ;
}
void F_4 ( struct V_1 * V_2 )
{
if ( V_9 != F_5 ( V_9 ) ) {
F_6 ( & V_2 -> V_6 ) ;
F_6 ( & V_2 -> V_7 ) ;
F_7 ( & V_2 -> V_8 ) ;
}
}
void F_8 ( struct V_10 * V_11 )
{
if ( V_9 != F_5 ( V_9 ) ) {
F_6 ( & V_11 -> V_12 ) ;
F_6 ( & V_11 -> V_13 ) ;
F_9 ( & V_11 -> V_14 ) ;
F_9 ( & V_11 -> V_15 ) ;
F_9 ( & V_11 -> V_16 ) ;
F_9 ( & V_11 -> V_17 ) ;
}
}
int F_10 ( void * V_18 , int V_19 , struct V_20 * V_21 )
{
struct V_10 * V_11 = (struct V_10 * ) V_18 ;
if ( V_19 == 0 || V_19 == - V_22 )
return - V_22 ;
if ( V_19 < 0 )
return V_19 ;
if ( V_11 -> V_13 & ~ F_5 ( V_23 ) )
return - V_22 ;
F_8 ( V_11 ) ;
V_21 -> V_24 = V_11 -> V_12 ;
V_21 -> V_25 = V_11 -> V_13 ;
V_21 -> V_26 = V_11 -> V_14 ;
V_21 -> V_27 = V_11 -> V_15 ;
V_21 -> V_28 = V_11 -> V_16 ;
V_21 -> V_29 = V_11 -> V_17 ;
return 0 ;
}
void F_11 ( struct V_30 * V_11 )
{
if ( V_9 != F_5 ( V_9 ) ) {
F_6 ( & V_11 -> V_31 ) ;
F_6 ( & V_11 -> V_32 ) ;
F_9 ( & V_11 -> V_33 ) ;
F_9 ( & V_11 -> V_34 ) ;
}
}
int F_12 ( void * V_18 , int V_19 , struct V_35 * V_36 )
{
struct V_30 * V_11 = (struct V_30 * ) V_18 ;
if ( V_19 == 0 || V_19 == - V_22 )
return - V_22 ;
if ( V_19 < 0 )
return V_19 ;
F_11 ( V_11 ) ;
V_36 -> V_37 = V_11 -> V_31 ;
V_36 -> V_38 = V_11 -> V_32 ;
V_36 -> V_39 = V_11 -> V_33 ;
V_36 -> V_40 = V_11 -> V_34 ;
return 0 ;
}
void F_13 ( void * V_18 , struct V_35 * V_36 )
{
struct V_30 * V_11 = (struct V_30 * ) V_18 ;
V_11 -> V_31 = V_36 -> V_37 ;
V_11 -> V_32 = V_36 -> V_38 ;
V_11 -> V_33 = V_36 -> V_39 ;
V_11 -> V_34 = V_36 -> V_40 ;
F_11 ( V_11 ) ;
}
