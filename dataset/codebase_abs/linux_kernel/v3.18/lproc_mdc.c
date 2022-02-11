static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = & V_5 -> V_9 . V_8 ;
int V_10 ;
F_2 ( & V_8 -> V_11 ) ;
V_10 = F_3 ( V_2 , L_1 , V_8 -> V_12 ) ;
F_4 ( & V_8 -> V_11 ) ;
return V_10 ;
}
static T_1 F_5 ( struct V_13 * V_13 ,
const char * V_14 ,
T_2 V_15 ,
T_3 * V_16 )
{
struct V_4 * V_5 =
( (struct V_1 * ) V_13 -> V_17 ) -> V_6 ;
struct V_7 * V_8 = & V_5 -> V_9 . V_8 ;
int V_18 , V_10 ;
V_10 = F_6 ( V_14 , V_15 , & V_18 ) ;
if ( V_10 )
return V_10 ;
if ( V_18 < 1 || V_18 > V_19 )
return - V_20 ;
F_2 ( & V_8 -> V_11 ) ;
V_8 -> V_12 = V_18 ;
F_4 ( & V_8 -> V_11 ) ;
return V_15 ;
}
static int F_7 ( struct V_21 * V_21 , struct V_13 * V_13 )
{
return F_8 ( V_13 , NULL , F_9 ( V_21 ) ) ;
}
static T_1 F_10 ( struct V_13 * V_13 , const char * V_14 ,
T_2 V_15 , T_3 * V_16 )
{
struct V_4 * V_22 =
( (struct V_1 * ) V_13 -> V_17 ) -> V_6 ;
struct V_23 * V_24 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
int V_29 ;
int V_30 , V_10 ;
V_10 = F_6 ( V_14 , V_15 , & V_30 ) ;
if ( V_10 )
return V_10 ;
if ( V_30 < 0 )
return - V_20 ;
F_11 ( L_2 , V_30 ) ;
V_29 = sizeof( * V_24 ) + sizeof( * V_26 ) + V_31 +
2 * F_12 ( sizeof( * V_28 ) ) ;
F_13 ( V_24 , V_29 ) ;
V_24 -> V_32 = V_33 ;
V_24 -> V_34 = V_35 ;
V_24 -> V_36 = V_37 ;
V_24 -> V_38 = V_29 ;
V_26 = (struct V_25 * ) ( V_24 + 1 ) ;
V_26 -> V_39 = V_40 ;
V_26 -> V_41 = 1 ;
V_26 -> V_42 = 0 ;
F_14 ( V_26 -> V_43 , V_22 -> V_44 , V_31 ) ;
V_26 -> V_45 = 2 ;
V_28 = F_15 ( V_26 ) ;
V_28 -> V_46 = V_47 ;
V_28 -> V_48 . V_49 = 5 ;
V_28 -> V_50 = sizeof( * V_28 ) ;
V_28 = F_16 ( V_28 ) ;
V_28 -> V_46 = V_51 ;
V_28 -> V_48 . V_49 = 10 ;
V_28 -> V_50 = sizeof( * V_28 ) ;
if ( V_30 == 0 ) {
V_10 = F_17 ( V_52 , V_24 ) ;
} else {
struct V_13 * V_53 = F_18 ( V_30 ) ;
V_10 = F_19 ( V_53 , V_24 ) ;
F_20 ( V_53 ) ;
}
F_21 ( V_24 , V_29 ) ;
if ( V_10 < 0 )
return V_10 ;
return V_15 ;
}
static int F_22 ( struct V_1 * V_2 , void * V_3 )
{
return F_23 ( V_2 , V_2 -> V_6 ) ;
}
void F_24 ( struct V_54 * V_55 )
{
V_55 -> V_56 = V_57 ;
V_55 -> V_58 = V_59 ;
}
