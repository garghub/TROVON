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
int V_10 = 0 ;
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
static int F_12 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_33 * V_34 = F_13 ( V_32 ,
V_35 ) ;
struct V_33 * V_36 = F_13 ( V_32 ,
V_37 ) ;
struct V_38 * V_39 = F_14 ( V_32 , V_40 ) ;
V_34 -> V_41 = V_34 -> V_42 = 48000 ;
V_36 -> V_41 = V_36 -> V_42 = 2 ;
F_15 ( V_39 ) ;
F_16 ( V_39 , V_43 ) ;
return 0 ;
}
static int F_17 ( struct V_44 * V_45 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 = V_45 -> V_46 ;
struct V_18 * V_20 = V_2 -> V_20 ;
int V_10 ;
V_10 = F_18 ( V_20 , V_47 ,
19200000 , V_48 ) ;
if ( V_10 < 0 ) {
F_19 ( V_2 -> V_23 , L_4 ) ;
return V_10 ;
}
return V_10 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_33 * V_36 = F_13 ( V_32 ,
V_37 ) ;
if ( F_21 ( V_32 ) == 2 )
V_36 -> V_41 = V_36 -> V_42 = 2 ;
else
V_36 -> V_41 = V_36 -> V_42 = 4 ;
return 0 ;
}
static int F_22 ( struct V_44 * V_45 )
{
struct V_49 * V_50 = V_45 -> V_50 ;
V_50 -> V_51 . V_52 = 4 ;
F_23 ( V_50 , 0 , V_37 ,
& V_53 ) ;
return F_23 ( V_45 -> V_50 , 0 ,
V_35 , & V_54 ) ;
}
static int F_24 ( struct V_44 * V_45 )
{
struct V_49 * V_50 = V_45 -> V_50 ;
V_50 -> V_51 . V_52 = 2 ;
F_23 ( V_50 , 0 , V_37 ,
& V_55 ) ;
V_50 -> V_51 . V_56 = V_57 ;
F_25 ( V_50 , 0 , 16 , 16 ) ;
F_23 ( V_50 , 0 ,
V_35 , & V_54 ) ;
return 0 ;
}
static int F_26 ( struct V_58 * V_11 )
{
struct V_16 * V_17 = F_9 ( V_11 ) ;
struct V_21 * V_22 ;
struct V_8 * V_9 = NULL ;
int V_59 , V_60 = 0 ;
char V_61 [ V_62 ] ;
F_27 (pcm, &ctx->hdmi_pcm_list, head) {
V_9 = V_22 -> V_20 -> V_9 ;
snprintf ( V_61 , sizeof( V_61 ) ,
L_5 , V_22 -> V_26 ) ;
V_59 = F_5 ( V_11 , V_61 ,
V_63 , & V_64 [ V_60 ] ,
NULL , 0 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_28 ( V_22 -> V_20 , V_22 -> V_26 ,
& V_64 [ V_60 ] ) ;
if ( V_59 < 0 )
return V_59 ;
V_60 ++ ;
}
if ( ! V_9 )
return - V_65 ;
return F_29 ( V_9 , & V_11 -> V_4 ) ;
}
static int F_30 ( struct V_66 * V_67 )
{
struct V_16 * V_17 ;
V_17 = F_10 ( & V_67 -> V_23 , sizeof( * V_17 ) , V_68 ) ;
if ( ! V_17 )
return - V_25 ;
F_31 ( & V_17 -> V_30 ) ;
V_69 . V_23 = & V_67 -> V_23 ;
F_32 ( & V_69 , V_17 ) ;
return F_33 ( & V_67 -> V_23 , & V_69 ) ;
}
