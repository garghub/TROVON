static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = & V_5 -> V_9 . V_8 ;
F_2 ( & V_8 -> V_10 ) ;
F_3 ( V_2 , L_1 , V_8 -> V_11 ) ;
F_4 ( & V_8 -> V_10 ) ;
return 0 ;
}
static T_1 F_5 ( struct V_12 * V_12 ,
const char T_2 * V_13 ,
T_3 V_14 ,
T_4 * V_15 )
{
struct V_4 * V_5 =
( (struct V_1 * ) V_12 -> V_16 ) -> V_6 ;
struct V_7 * V_8 = & V_5 -> V_9 . V_8 ;
int V_17 , V_18 ;
V_18 = F_6 ( V_13 , V_14 , & V_17 ) ;
if ( V_18 )
return V_18 ;
if ( V_17 < 1 || V_17 > V_19 )
return - V_20 ;
F_2 ( & V_8 -> V_10 ) ;
V_8 -> V_11 = V_17 ;
F_4 ( & V_8 -> V_10 ) ;
return V_14 ;
}
static int F_7 ( struct V_21 * V_21 , struct V_12 * V_12 )
{
return F_8 ( V_12 , NULL , F_9 ( V_21 ) ) ;
}
static T_1 F_10 ( struct V_12 * V_12 ,
const char T_2 * V_13 ,
T_3 V_14 , T_4 * V_15 )
{
struct V_4 * V_22 =
( (struct V_1 * ) V_12 -> V_16 ) -> V_6 ;
struct V_23 * V_24 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
int V_29 ;
int V_30 , V_18 ;
V_18 = F_6 ( V_13 , V_14 , & V_30 ) ;
if ( V_18 )
return V_18 ;
if ( V_30 < 0 )
return - V_20 ;
F_11 ( L_2 , V_30 ) ;
V_29 = sizeof( * V_24 ) + sizeof( * V_26 ) + V_31 +
2 * F_12 ( sizeof( * V_28 ) ) ;
F_13 ( V_24 , V_29 ) ;
if ( ! V_24 )
return - V_32 ;
V_24 -> V_33 = V_34 ;
V_24 -> V_35 = V_36 ;
V_24 -> V_37 = V_38 ;
V_24 -> V_39 = V_29 ;
V_26 = (struct V_25 * ) ( V_24 + 1 ) ;
V_26 -> V_40 = V_41 ;
V_26 -> V_42 = 1 ;
V_26 -> V_43 = 0 ;
F_14 ( V_26 -> V_44 , V_22 -> V_45 , V_31 ) ;
V_26 -> V_46 = 2 ;
V_28 = F_15 ( V_26 ) ;
V_28 -> V_47 = V_48 ;
V_28 -> V_49 . V_50 = 5 ;
V_28 -> V_51 = sizeof( * V_28 ) ;
V_28 = F_16 ( V_28 ) ;
V_28 -> V_47 = V_52 ;
V_28 -> V_49 . V_50 = 10 ;
V_28 -> V_51 = sizeof( * V_28 ) ;
if ( V_30 == 0 ) {
V_18 = F_17 ( V_53 , V_24 ) ;
} else {
struct V_12 * V_54 = F_18 ( V_30 ) ;
V_18 = F_19 ( V_54 , V_24 ) ;
F_20 ( V_54 ) ;
}
F_21 ( V_24 , V_29 ) ;
if ( V_18 < 0 )
return V_18 ;
return V_14 ;
}
static int F_22 ( struct V_1 * V_2 , void * V_3 )
{
return F_23 ( V_2 , V_2 -> V_6 ) ;
}
void F_24 ( struct V_55 * V_56 )
{
V_56 -> V_57 = V_58 ;
V_56 -> V_59 = V_60 ;
}
