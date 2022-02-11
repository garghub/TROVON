static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ,
V_7 ) ;
struct V_5 * V_8 = F_2 ( V_4 ,
V_9 ) ;
struct V_10 * V_11 = F_3 ( V_4 , V_12 ) ;
V_6 -> V_13 = V_6 -> V_14 = 48000 ;
V_8 -> V_13 = V_8 -> V_14 = V_15 ;
F_4 ( V_11 ) ;
F_5 ( V_11 , V_16 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_17 ;
struct V_18 * V_19 = V_2 -> V_19 ;
V_17 = F_7 ( V_2 -> V_20 , L_1 ,
V_21 | V_22 | V_23 |
V_24 | V_25 | V_26 ,
& V_27 , NULL , 0 ) ;
if ( V_17 ) {
F_8 ( V_2 -> V_28 , L_2 , V_17 ) ;
return V_17 ;
}
F_9 ( V_19 , & V_27 ) ;
F_10 ( & V_2 -> V_20 -> V_29 , L_3 ) ;
return V_17 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = F_12 ( V_2 -> V_20 ) ;
struct V_32 * V_33 = V_2 -> V_34 ;
struct V_35 * V_36 ;
V_36 = F_13 ( V_2 -> V_20 -> V_28 , sizeof( * V_36 ) , V_37 ) ;
if ( ! V_36 )
return - V_38 ;
V_36 -> V_39 = V_40 + V_33 -> V_41 ;
V_36 -> V_34 = V_33 ;
F_14 ( & V_36 -> V_42 , & V_31 -> V_43 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_44 * V_29 ;
struct V_45 * V_46 = V_2 -> V_47 -> V_46 ;
V_29 = F_16 ( V_46 ) ;
F_10 ( V_29 , L_4 ) ;
return 0 ;
}
static int F_17 ( struct V_48 * V_49 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
V_51 -> V_52 . V_53 = V_15 ;
F_18 ( V_51 , 0 , V_9 ,
& V_54 ) ;
V_51 -> V_52 . V_55 = V_56 ;
F_19 ( V_51 , 0 , 16 , 16 ) ;
F_18 ( V_51 , 0 ,
V_7 , & V_57 ) ;
return 0 ;
}
static int F_20 ( struct V_48 * V_49 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_49 -> V_58 ;
struct V_32 * V_34 = V_2 -> V_34 ;
int V_17 ;
V_17 = F_21 ( V_34 ,
V_59 , 19200000 , V_60 ) ;
if ( V_17 < 0 )
F_8 ( V_34 -> V_28 , L_5 ) ;
V_17 = F_22 ( V_34 , 0 ,
V_61 , 0 , V_62 ) ;
if ( V_17 < 0 ) {
F_8 ( V_34 -> V_28 , L_6 , V_17 ) ;
return - V_63 ;
}
return V_17 ;
}
static int F_23 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_58 ;
struct V_32 * V_34 = V_2 -> V_34 ;
int V_17 ;
V_17 = F_22 ( V_34 , 0 ,
V_64 , 0 , 0 ) ;
if ( V_17 < 0 ) {
F_8 ( V_34 -> V_28 , L_7 , V_17 ) ;
return - V_63 ;
}
return V_17 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_8 = F_2 ( V_4 ,
V_9 ) ;
if ( F_25 ( V_4 ) == 2 )
V_8 -> V_13 = V_8 -> V_14 = 2 ;
else
V_8 -> V_13 = V_8 -> V_14 = 4 ;
return 0 ;
}
static int F_26 ( struct V_48 * V_49 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
V_51 -> V_52 . V_65 = V_51 -> V_52 . V_53 = V_66 ;
F_18 ( V_51 , 0 , V_9 ,
& V_67 ) ;
return F_18 ( V_49 -> V_51 , 0 ,
V_7 , & V_57 ) ;
}
static int F_27 ( struct V_48 * V_49 )
{
return F_18 ( V_49 -> V_51 , 0 ,
V_7 ,
& V_68 ) ;
}
static int F_28 ( struct V_69 * V_20 )
{
struct V_30 * V_31 = F_12 ( V_20 ) ;
struct V_35 * V_36 ;
struct V_18 * V_19 = NULL ;
int V_70 , V_71 = 0 ;
char V_72 [ V_73 ] ;
F_29 (pcm, &ctx->hdmi_pcm_list, head) {
V_19 = V_36 -> V_34 -> V_19 ;
snprintf ( V_72 , sizeof( V_72 ) ,
L_8 , V_36 -> V_39 ) ;
V_70 = F_7 ( V_20 , V_72 ,
V_74 , & V_75 [ V_71 ] ,
NULL , 0 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_30 ( V_36 -> V_34 , V_36 -> V_39 ,
& V_75 [ V_71 ] ) ;
if ( V_70 < 0 )
return V_70 ;
V_71 ++ ;
}
if ( ! V_19 )
return - V_76 ;
return F_31 ( V_19 , & V_20 -> V_29 ) ;
}
static int F_32 ( struct V_77 * V_78 )
{
struct V_30 * V_31 ;
V_31 = F_13 ( & V_78 -> V_28 , sizeof( * V_31 ) , V_79 ) ;
if ( ! V_31 )
return - V_38 ;
F_33 ( & V_31 -> V_43 ) ;
V_80 . V_28 = & V_78 -> V_28 ;
F_34 ( & V_80 , V_31 ) ;
return F_35 ( & V_78 -> V_28 , & V_80 ) ;
}
