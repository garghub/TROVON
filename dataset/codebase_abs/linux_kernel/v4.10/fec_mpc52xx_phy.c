static int F_1 ( struct V_1 * V_2 , int V_3 ,
int V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 T_2 * V_9 = V_7 -> V_10 ;
int V_11 = 3 ;
V_5 |= ( V_3 << V_12 ) & V_13 ;
V_5 |= ( V_4 << V_14 ) & V_15 ;
F_2 ( & V_9 -> V_16 , V_17 ) ;
F_2 ( & V_9 -> V_18 , V_5 ) ;
while ( ! ( F_3 ( & V_9 -> V_16 ) & V_17 ) && -- V_11 )
F_4 ( 1 ) ;
if ( ! V_11 )
return - V_19 ;
return V_5 & V_20 ?
F_3 ( & V_9 -> V_18 ) & V_21 : 0 ;
}
static int F_5 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , V_22 ) ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 , int V_4 ,
T_3 V_23 )
{
return F_1 ( V_2 , V_3 , V_4 ,
V_23 | V_24 ) ;
}
static int F_7 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = & V_26 -> V_28 ;
struct V_29 * V_30 = V_26 -> V_28 . V_31 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_32 V_33 ;
int V_34 ;
V_2 = F_8 () ;
if ( V_2 == NULL )
return - V_35 ;
V_7 = F_9 ( sizeof( * V_7 ) , V_36 ) ;
if ( V_7 == NULL ) {
V_34 = - V_35 ;
goto V_37;
}
V_2 -> V_38 = L_1 ;
V_2 -> V_39 = F_5 ;
V_2 -> V_40 = F_6 ;
V_34 = F_10 ( V_30 , 0 , & V_33 ) ;
if ( V_34 )
goto V_37;
V_7 -> V_10 = F_11 ( V_33 . V_41 , F_12 ( & V_33 ) ) ;
if ( V_7 -> V_10 == NULL ) {
V_34 = - V_35 ;
goto V_37;
}
snprintf ( V_2 -> V_42 , V_43 , L_2 , V_33 . V_41 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_44 = V_28 ;
F_13 ( V_28 , V_2 ) ;
F_2 ( & V_7 -> V_10 -> V_45 ,
( ( F_14 ( V_26 -> V_28 . V_31 ) >> 20 ) / 5 ) << 1 ) ;
V_34 = F_15 ( V_2 , V_30 ) ;
if ( V_34 )
goto V_46;
return 0 ;
V_46:
F_16 ( V_7 -> V_10 ) ;
V_37:
F_17 ( V_7 ) ;
F_18 ( V_2 ) ;
return V_34 ;
}
static int F_19 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_20 ( V_26 ) ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_21 ( V_2 ) ;
F_16 ( V_7 -> V_10 ) ;
F_17 ( V_7 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
