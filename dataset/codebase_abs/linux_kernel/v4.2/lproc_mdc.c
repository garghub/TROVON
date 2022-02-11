static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
int V_6 ;
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 ,
V_9 ) ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
F_3 ( & V_11 -> V_13 ) ;
V_6 = sprintf ( V_5 , L_1 , V_11 -> V_14 ) ;
F_4 ( & V_11 -> V_13 ) ;
return V_6 ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_15 ,
T_2 V_16 )
{
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 ,
V_9 ) ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
int V_17 ;
unsigned long V_18 ;
V_17 = F_6 ( V_15 , 10 , & V_18 ) ;
if ( V_17 )
return V_17 ;
if ( V_18 < 1 || V_18 > V_19 )
return - V_20 ;
F_3 ( & V_11 -> V_13 ) ;
V_11 -> V_14 = V_18 ;
F_4 ( & V_11 -> V_13 ) ;
return V_16 ;
}
static int F_7 ( struct V_21 * V_21 , struct V_22 * V_22 )
{
return F_8 ( V_22 , NULL , V_21 -> V_23 ) ;
}
static T_1 F_9 ( struct V_22 * V_22 ,
const char T_3 * V_15 ,
T_2 V_16 , T_4 * V_24 )
{
struct V_7 * V_25 =
( (struct V_26 * ) V_22 -> V_27 ) -> V_28 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
int V_6 ;
int V_35 , V_17 ;
V_17 = F_10 ( V_15 , V_16 , & V_35 ) ;
if ( V_17 )
return V_17 ;
if ( V_35 < 0 )
return - V_20 ;
F_11 ( L_2 , V_35 ) ;
V_6 = sizeof( * V_30 ) + sizeof( * V_32 ) + V_36 +
2 * F_12 ( sizeof( * V_34 ) ) ;
V_30 = F_13 ( V_6 , V_37 ) ;
if ( ! V_30 )
return - V_38 ;
V_30 -> V_39 = V_40 ;
V_30 -> V_41 = V_42 ;
V_30 -> V_43 = V_44 ;
V_30 -> V_45 = V_6 ;
V_32 = (struct V_31 * ) ( V_30 + 1 ) ;
V_32 -> V_46 = V_47 ;
V_32 -> V_48 = 1 ;
V_32 -> V_49 = 0 ;
F_14 ( V_32 -> V_50 , V_25 -> V_51 , V_36 ) ;
V_32 -> V_52 = 2 ;
V_34 = F_15 ( V_32 ) ;
V_34 -> V_53 = V_54 ;
V_34 -> V_55 . V_56 = 5 ;
V_34 -> V_57 = sizeof( * V_34 ) ;
V_34 = F_16 ( V_34 ) ;
V_34 -> V_53 = V_58 ;
V_34 -> V_55 . V_56 = 10 ;
V_34 -> V_57 = sizeof( * V_34 ) ;
if ( V_35 == 0 ) {
V_17 = F_17 ( V_59 , V_30 ) ;
} else {
struct V_22 * V_60 = F_18 ( V_35 ) ;
V_17 = F_19 ( V_60 , V_30 ) ;
F_20 ( V_60 ) ;
}
F_21 ( V_30 ) ;
if ( V_17 < 0 )
return V_17 ;
return V_16 ;
}
static T_1 F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 , struct V_7 ,
V_9 ) ;
struct V_10 * V_11 = & V_8 -> V_12 . V_11 ;
return sprintf ( V_5 , L_3 , V_11 -> V_61 ) ;
}
void F_23 ( struct V_62 * V_63 )
{
V_63 -> V_64 = & V_65 ;
V_63 -> V_66 = V_67 ;
}
