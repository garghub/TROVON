static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 ,
V_2 -> V_4 + V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_2 ( V_3 ,
V_2 -> V_4 + V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_2 ( V_7 | V_8 ,
V_2 -> V_4 + V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( V_7 | V_8 ,
V_2 -> V_4 + V_6 ) ;
}
static T_1 F_6 ( struct V_9 * V_10 )
{
return V_11 | ( V_12 & ~ V_13 ) |
V_14 | V_15 ;
}
static void F_7 ( struct V_16 * V_17 , struct V_1 * V_2 )
{
int V_18 ;
V_2 -> V_19 = F_8 ( V_17 , NULL ) ;
if ( F_9 ( V_2 -> V_19 ) ) {
V_2 -> V_19 = NULL ;
goto V_20;
}
V_18 = F_10 ( V_2 -> V_19 ) ;
if ( V_18 )
goto V_20;
V_2 -> V_21 = F_11 ( V_2 -> V_19 ) ;
V_20:
if ( ! V_2 -> V_21 )
V_2 -> V_21 = V_22 ;
}
static void F_12 ( struct V_16 * V_17 , struct V_19 * V_19 )
{
if ( ! V_19 )
return;
F_13 ( V_19 ) ;
F_14 ( V_19 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
T_1 type ;
if ( ! V_24 )
return - V_25 ;
V_2 -> V_26 . V_27 = F_16 ( V_24 , 0 ) ;
if ( ! V_2 -> V_26 . V_27 )
return - V_25 ;
type = F_17 ( F_18 ( V_2 -> V_26 . V_27 ) ) ;
V_2 -> V_26 . V_28 =
( type & V_29 ) ? 1 : 0 ;
V_2 -> V_30 = F_19 ( & V_2 -> V_10 , & V_2 -> V_26 ) ;
if ( ! V_2 -> V_30 )
return - V_31 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
if ( ! V_32 )
return - V_33 ;
return F_15 ( V_2 , V_24 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
if ( V_2 -> V_30 )
F_22 ( V_2 -> V_30 ) ;
}
static int F_23 ( struct V_34 * V_35 ,
const struct V_36 * V_37 )
{
struct V_16 * V_17 = & V_35 -> V_17 ;
struct V_1 * V_2 ;
int V_18 ;
V_2 = F_24 ( V_17 , sizeof( * V_2 ) , V_38 ) ;
if ( ! V_2 )
return - V_39 ;
V_2 -> V_40 . V_41 = 0x1000 ;
V_2 -> V_40 . V_42 = 0x1010 ;
V_2 -> V_40 . V_43 = 0x1018 ;
V_2 -> V_17 = V_17 ;
F_25 ( V_35 , V_2 ) ;
V_18 = F_26 ( V_35 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_27 ( V_35 , V_44 ) ;
if ( V_18 )
return V_18 ;
V_2 -> V_4 = F_28 ( V_35 , 0 , F_29 ( V_35 , 0 ) ) ;
if ( ! V_2 -> V_4 )
return - V_25 ;
F_7 ( V_17 , V_2 ) ;
V_18 = F_30 ( V_17 , L_1 , & V_2 -> V_45 ) ;
if ( V_18 )
V_2 -> V_45 = 100000 ;
F_31 ( & V_2 -> V_46 ) ;
V_2 -> V_47 = F_1 ;
V_2 -> V_48 = F_3 ;
V_2 -> V_49 = F_4 ;
V_2 -> V_50 = F_5 ;
V_18 = F_32 ( V_35 , & V_2 -> V_51 , 1 ) ;
if ( V_18 )
goto error;
V_18 = F_33 ( V_17 , V_2 -> V_51 . V_52 , V_53 , 0 ,
V_44 , V_2 ) ;
if ( V_18 )
goto error;
V_18 = F_34 ( V_2 ) ;
if ( V_18 )
goto error;
F_35 ( V_2 ) ;
V_2 -> V_10 = V_54 ;
V_2 -> V_10 . V_55 = 5 ;
V_2 -> V_10 . V_56 = & V_57 ;
V_2 -> V_10 . V_17 . V_58 = V_17 ;
V_2 -> V_10 . V_17 . V_59 = V_35 -> V_17 . V_59 ;
snprintf ( V_2 -> V_10 . V_60 , sizeof( V_2 -> V_10 . V_60 ) ,
L_2 , F_36 ( V_17 ) ) ;
F_37 ( & V_2 -> V_10 , V_2 ) ;
V_18 = F_38 ( & V_2 -> V_10 ) ;
if ( V_18 )
goto error;
F_39 ( V_2 -> V_17 , L_3 , V_2 -> V_21 ) ;
V_18 = F_20 ( V_2 , V_35 -> V_17 . V_59 ) ;
if ( V_18 )
F_39 ( V_17 , L_4 ) ;
return 0 ;
error:
F_12 ( V_17 , V_2 -> V_19 ) ;
return V_18 ;
}
static void F_40 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_41 ( V_35 ) ;
F_21 ( V_2 ) ;
F_12 ( & V_35 -> V_17 , V_2 -> V_19 ) ;
F_42 ( & V_2 -> V_10 ) ;
}
