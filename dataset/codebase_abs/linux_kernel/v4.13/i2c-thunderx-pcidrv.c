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
if ( V_19 ) {
V_2 -> V_20 = F_8 ( V_17 , NULL ) ;
if ( F_9 ( V_2 -> V_20 ) ) {
V_2 -> V_20 = NULL ;
goto V_21;
}
V_18 = F_10 ( V_2 -> V_20 ) ;
if ( V_18 )
goto V_21;
V_2 -> V_22 = F_11 ( V_2 -> V_20 ) ;
} else {
F_12 ( V_17 , L_1 , & V_2 -> V_22 ) ;
}
V_21:
if ( ! V_2 -> V_22 )
V_2 -> V_22 = V_23 ;
}
static void F_13 ( struct V_16 * V_17 , struct V_20 * V_20 )
{
if ( ! V_20 )
return;
F_14 ( V_20 ) ;
F_15 ( V_20 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
T_1 type ;
if ( ! V_25 )
return - V_26 ;
V_2 -> V_27 . V_28 = F_17 ( V_25 , 0 ) ;
if ( ! V_2 -> V_27 . V_28 )
return - V_26 ;
type = F_18 ( F_19 ( V_2 -> V_27 . V_28 ) ) ;
V_2 -> V_27 . V_29 =
( type & V_30 ) ? 1 : 0 ;
V_2 -> V_31 = F_20 ( & V_2 -> V_10 , & V_2 -> V_27 ) ;
if ( ! V_2 -> V_31 )
return - V_32 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
if ( ! V_19 )
return - V_33 ;
return F_16 ( V_2 , V_25 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
if ( V_2 -> V_31 )
F_23 ( V_2 -> V_31 ) ;
}
static int F_24 ( struct V_34 * V_35 ,
const struct V_36 * V_37 )
{
struct V_16 * V_17 = & V_35 -> V_17 ;
struct V_1 * V_2 ;
int V_18 ;
V_2 = F_25 ( V_17 , sizeof( * V_2 ) , V_38 ) ;
if ( ! V_2 )
return - V_39 ;
V_2 -> V_40 . V_41 = 0x1000 ;
V_2 -> V_40 . V_42 = 0x1010 ;
V_2 -> V_40 . V_43 = 0x1018 ;
V_2 -> V_17 = V_17 ;
F_26 ( V_35 , V_2 ) ;
V_18 = F_27 ( V_35 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_28 ( V_35 , V_44 ) ;
if ( V_18 )
return V_18 ;
V_2 -> V_4 = F_29 ( V_35 , 0 , F_30 ( V_35 , 0 ) ) ;
if ( ! V_2 -> V_4 )
return - V_26 ;
F_7 ( V_17 , V_2 ) ;
V_18 = F_12 ( V_17 , L_2 , & V_2 -> V_45 ) ;
if ( V_18 )
V_2 -> V_45 = 100000 ;
F_31 ( & V_2 -> V_46 ) ;
V_2 -> V_47 = F_1 ;
V_2 -> V_48 = F_3 ;
V_2 -> V_49 = F_4 ;
V_2 -> V_50 = F_5 ;
V_18 = F_32 ( V_35 , 1 , 1 , V_51 ) ;
if ( V_18 < 0 )
goto error;
V_18 = F_33 ( V_17 , F_34 ( V_35 , 0 ) , V_52 , 0 ,
V_44 , V_2 ) ;
if ( V_18 )
goto error;
V_18 = F_35 ( V_2 ) ;
if ( V_18 )
goto error;
F_36 ( V_2 ) ;
V_2 -> V_10 = V_53 ;
V_2 -> V_10 . V_54 = 5 ;
V_2 -> V_10 . V_55 = V_56 ;
V_2 -> V_10 . V_57 = & V_58 ;
V_2 -> V_10 . V_17 . V_59 = V_17 ;
V_2 -> V_10 . V_17 . V_60 = V_35 -> V_17 . V_60 ;
snprintf ( V_2 -> V_10 . V_61 , sizeof( V_2 -> V_10 . V_61 ) ,
L_3 , F_37 ( V_17 ) ) ;
F_38 ( & V_2 -> V_10 , V_2 ) ;
V_18 = F_39 ( & V_2 -> V_10 ) ;
if ( V_18 )
goto error;
F_40 ( V_2 -> V_17 , L_4 , V_2 -> V_22 ) ;
V_18 = F_21 ( V_2 , V_35 -> V_17 . V_60 ) ;
if ( V_18 )
F_40 ( V_17 , L_5 ) ;
return 0 ;
error:
F_13 ( V_17 , V_2 -> V_20 ) ;
return V_18 ;
}
static void F_41 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = F_42 ( V_35 ) ;
F_22 ( V_2 ) ;
F_13 ( & V_35 -> V_17 , V_2 -> V_20 ) ;
F_43 ( & V_2 -> V_10 ) ;
}
