static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_7 -> V_6 ;
V_4 = F_2 ( V_6 ) ;
F_3 ( V_4 , L_1 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
int V_10 ;
V_10 = F_5 ( V_2 -> V_11 , L_2 ,
V_12 | V_13 ,
& V_14 ,
V_15 , F_6 ( V_15 ) ) ;
if ( V_10 )
return V_10 ;
F_7 ( V_9 , & V_14 ) ;
F_3 ( & V_2 -> V_11 -> V_4 , L_3 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_9 ( V_2 -> V_11 ) ;
struct V_18 * V_19 = V_2 -> V_20 ;
struct V_21 * V_22 ;
V_22 = F_10 ( V_2 -> V_11 -> V_23 , sizeof( * V_22 ) , V_24 ) ;
if ( ! V_22 )
return - V_25 ;
V_22 -> V_26 = V_27 + V_19 -> V_28 ;
V_22 -> V_20 = V_19 ;
F_11 ( & V_22 -> V_29 , & V_17 -> V_30 ) ;
return 0 ;
}
static int F_12 ( struct V_31 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_34 ;
V_34 -> V_35 . V_36 = 2 ;
F_13 ( V_34 , 0 , V_37 ,
& V_38 ) ;
V_34 -> V_35 . V_39 = V_40 ;
F_14 ( V_34 , 0 , 16 , 16 ) ;
F_13 ( V_34 , 0 ,
V_41 , & V_42 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
struct V_45 * V_46 = F_16 ( V_44 ,
V_41 ) ;
struct V_45 * V_47 = F_16 ( V_44 ,
V_37 ) ;
struct V_48 * V_49 = F_17 ( V_44 , V_50 ) ;
V_46 -> V_51 = V_46 -> V_52 = 48000 ;
V_47 -> V_51 = V_47 -> V_52 = 2 ;
F_18 ( V_49 ) ;
F_19 ( V_49 , V_53 ) ;
return 0 ;
}
static int F_20 ( struct V_31 * V_32 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = V_32 -> V_54 ;
struct V_18 * V_20 = V_2 -> V_20 ;
int V_10 ;
V_10 = F_21 ( V_20 , V_55 , 24000000 ,
V_56 ) ;
if ( V_10 < 0 )
F_22 ( V_2 -> V_23 , L_4 , V_10 ) ;
return V_10 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
struct V_45 * V_47 = F_16 ( V_44 ,
V_37 ) ;
if ( F_24 ( V_44 ) == 2 )
V_47 -> V_51 = V_47 -> V_52 = 2 ;
else
V_47 -> V_51 = V_47 -> V_52 = 4 ;
return 0 ;
}
static int F_25 ( struct V_31 * V_32 )
{
struct V_33 * V_34 = V_32 -> V_34 ;
V_34 -> V_35 . V_36 = 4 ;
F_13 ( V_34 , 0 , V_37 ,
& V_57 ) ;
return F_13 ( V_32 -> V_34 , 0 ,
V_41 , & V_42 ) ;
}
static int F_26 ( struct V_58 * V_11 )
{
struct V_16 * V_17 = F_9 ( V_11 ) ;
struct V_21 * V_22 ;
int V_59 ;
F_27 (pcm, &ctx->hdmi_pcm_list, head) {
V_59 = F_28 ( V_22 -> V_20 , V_22 -> V_26 ) ;
if ( V_59 < 0 )
return V_59 ;
}
return 0 ;
}
static int F_29 ( struct V_60 * V_61 )
{
struct V_16 * V_17 ;
V_17 = F_10 ( & V_61 -> V_23 , sizeof( * V_17 ) , V_62 ) ;
if ( ! V_17 )
return - V_25 ;
F_30 ( & V_17 -> V_30 ) ;
V_63 . V_23 = & V_61 -> V_23 ;
F_31 ( & V_63 , V_17 ) ;
return F_32 ( & V_61 -> V_23 , & V_63 ) ;
}
