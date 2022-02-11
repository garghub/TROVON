T_1 F_1 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
struct V_7 * V_8 = V_6 -> V_9 . V_8 ;
struct V_10 V_11 ;
unsigned V_12 ;
int V_13 ;
if ( V_6 -> V_14 )
return - V_15 ;
if ( V_3 < sizeof( * V_8 ) )
return - V_15 ;
V_3 = sizeof( * V_8 ) * ( V_3 / sizeof( * V_8 ) ) ;
if ( F_3 ( & V_6 -> V_16 ) )
return - V_17 ;
if ( V_6 -> V_18 &&
V_1 -> V_19 != V_6 -> V_18 ) {
F_4 ( & V_6 -> V_16 ) ;
return - V_20 ;
}
V_6 -> V_18 = V_1 -> V_19 ;
V_21:
F_5 ( & V_11 ) ;
V_11 = F_6 ( V_11 , V_6 -> V_22 ) ;
V_12 = V_11 . V_23 * 100 + V_11 . V_24 / 10000000 ;
V_12 = ( V_12 * V_25 ) / 500 ;
if ( V_12 - V_25 >= V_6 -> V_26 )
V_6 -> V_26 = V_12 - V_25 + 1 ;
if ( V_12 == V_6 -> V_26 ||
! ( V_6 -> V_27 & V_28 ) ) {
F_4 ( & V_6 -> V_16 ) ;
if ( V_1 -> V_29 & V_30 )
return - V_31 ;
if ( F_7 ( 20 ) && F_8 ( V_32 ) )
return - V_33 ;
if ( F_3 ( & V_6 -> V_16 ) )
return - V_17 ;
goto V_21;
}
for ( V_13 = 0 ; V_13 < V_3 && V_12 > V_6 -> V_26 ;
V_6 -> V_26 ++ ) {
unsigned V_34 = V_6 -> V_26 % V_25 ;
struct V_7 V_35 ;
if ( F_9 ( & V_35 , V_2 + V_13 , sizeof( V_35 ) ) ) {
V_13 = - V_36 ;
break;
}
V_13 += sizeof( V_35 ) ;
if ( ! V_6 -> V_37 )
continue;
if ( ( V_35 . V_38 & V_39 ) == V_40 ||
( V_35 . V_38 & V_41 ) )
continue;
V_35 . V_38 &= V_39 ;
V_8 [ V_34 ] = V_35 ;
}
F_4 ( & V_6 -> V_16 ) ;
return V_13 ;
}
unsigned int F_10 ( struct V_1 * V_1 , struct V_42 * V_43 )
{
return V_44 | V_45 | F_11 ( V_1 , V_43 ) ;
}
int F_12 ( struct V_1 * V_1 , void * V_46 , struct V_47 * V_48 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
if ( V_48 -> V_49 > 0 )
return - V_15 ;
F_13 ( V_48 -> V_50 , L_1 , sizeof( V_48 -> V_50 ) ) ;
V_48 -> V_51 = V_52 | V_53 |
V_54 | V_55 |
( V_6 -> V_14 ?
V_56 :
V_57 ) ;
V_48 -> V_58 = V_59 ;
V_48 -> V_60 = V_61 ;
V_48 -> V_62 = V_6 -> V_27 ;
return 0 ;
}
int F_14 ( struct V_1 * V_1 , void * V_46 , const struct V_47 * V_48 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
if ( V_48 -> V_49 )
return - V_15 ;
if ( V_48 -> V_62 & ~ 0x13 )
return - V_15 ;
V_6 -> V_27 = V_48 -> V_62 ;
return 0 ;
}
