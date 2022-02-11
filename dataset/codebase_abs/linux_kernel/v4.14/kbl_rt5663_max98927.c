static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 = V_2 -> V_8 -> V_7 ;
V_5 = F_2 ( V_7 ) ;
V_3 = F_3 ( V_5 , L_1 ) ;
if ( V_3 ) {
F_4 ( V_2 -> V_9 , L_2 , V_3 ) ;
return V_3 ;
}
return V_3 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_10 * V_11 = F_6 ( V_2 -> V_12 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
V_3 = F_7 ( V_15 , L_3 ,
V_16 | V_17 | V_18 |
V_19 | V_20 , & V_11 -> V_21 ,
NULL , 0 ) ;
if ( V_3 ) {
F_4 ( V_2 -> V_9 , L_4 , V_3 ) ;
return V_3 ;
}
F_8 ( V_14 , & V_11 -> V_21 ) ;
return V_3 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_5 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_3 ( & V_2 -> V_12 -> V_5 , L_5 ) ;
if ( V_3 ) {
F_4 ( V_2 -> V_9 , L_6 , V_3 ) ;
return V_3 ;
}
return V_3 ;
}
static int F_10 ( struct V_1 * V_2 , int V_22 )
{
struct V_10 * V_11 = F_6 ( V_2 -> V_12 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
struct V_26 * V_27 ;
V_27 = F_11 ( V_2 -> V_12 -> V_9 , sizeof( * V_27 ) , V_28 ) ;
if ( ! V_27 )
return - V_29 ;
V_27 -> V_22 = V_22 ;
V_27 -> V_25 = V_24 ;
F_12 ( & V_27 -> V_30 , & V_11 -> V_31 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return F_10 ( V_2 , V_32 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
return F_10 ( V_2 , V_33 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
return F_10 ( V_2 , V_34 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
return F_10 ( V_2 , V_35 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
return F_10 ( V_2 , V_36 ) ;
}
static int F_18 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = V_38 -> V_40 ;
V_40 -> V_41 . V_42 = 2 ;
F_19 ( V_40 , 0 , V_43 ,
& V_44 ) ;
V_40 -> V_41 . V_45 = V_46 ;
F_20 ( V_40 , 0 , 16 , 16 ) ;
F_19 ( V_40 , 0 ,
V_47 , & V_48 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_51 * V_52 = F_22 ( V_50 ,
V_47 ) ;
struct V_51 * V_53 = F_22 ( V_50 ,
V_43 ) ;
struct V_54 * V_55 = F_23 ( V_50 , V_56 ) ;
V_52 -> V_57 = V_52 -> V_58 = 48000 ;
V_53 -> V_57 = V_53 -> V_58 = 2 ;
F_24 ( V_55 ) ;
F_25 ( V_55 , V_59 ) ;
return 0 ;
}
static int F_26 ( struct V_37 * V_38 ,
struct V_49 * V_50 )
{
struct V_1 * V_2 = V_38 -> V_60 ;
struct V_23 * V_25 = V_2 -> V_25 ;
int V_3 ;
F_27 ( V_25 -> V_14 ,
V_61 | V_62 ,
V_63 ) ;
V_3 = F_28 ( V_25 ,
V_64 , 24576000 , V_65 ) ;
if ( V_3 < 0 )
F_4 ( V_2 -> V_9 , L_7 , V_3 ) ;
return V_3 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_51 * V_53 = F_22 ( V_50 ,
V_43 ) ;
if ( F_30 ( V_50 ) == 2 || F_31 ( V_66 ) == 2 )
V_53 -> V_57 = V_53 -> V_58 = 2 ;
else
V_53 -> V_57 = V_53 -> V_58 = 4 ;
return 0 ;
}
static int F_32 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = V_38 -> V_40 ;
V_40 -> V_41 . V_42 = F_31 ( V_66 ) ;
F_19 ( V_40 , 0 , V_43 ,
V_66 ) ;
return F_19 ( V_38 -> V_40 , 0 ,
V_47 , & V_48 ) ;
}
static int F_33 ( struct V_37 * V_38 )
{
V_38 -> V_40 -> V_41 . V_42 = 1 ;
F_19 ( V_38 -> V_40 , 0 ,
V_43 ,
& V_67 ) ;
return F_19 ( V_38 -> V_40 , 0 ,
V_47 ,
& V_68 ) ;
}
static int F_34 ( struct V_69 * V_12 )
{
struct V_10 * V_11 = F_6 ( V_12 ) ;
struct V_26 * V_27 ;
struct V_13 * V_14 = NULL ;
int V_70 , V_71 = 0 ;
char V_72 [ V_73 ] ;
F_35 (pcm, &ctx->hdmi_pcm_list, head) {
V_14 = V_27 -> V_25 -> V_14 ;
snprintf ( V_72 , sizeof( V_72 ) ,
L_8 , V_27 -> V_22 ) ;
V_70 = F_7 ( V_12 , V_72 ,
V_74 , & V_75 [ V_71 ] ,
NULL , 0 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_36 ( V_27 -> V_25 , V_27 -> V_22 ,
& V_75 [ V_71 ] ) ;
if ( V_70 < 0 )
return V_70 ;
V_71 ++ ;
}
if ( ! V_14 )
return - V_76 ;
return F_37 ( V_14 , & V_12 -> V_5 ) ;
}
static int F_38 ( struct V_77 * V_78 )
{
struct V_10 * V_11 ;
struct V_79 * V_80 ;
V_11 = F_11 ( & V_78 -> V_9 , sizeof( * V_11 ) , V_81 ) ;
if ( ! V_11 )
return - V_29 ;
F_39 ( & V_11 -> V_31 ) ;
V_15 =
(struct V_69 * ) V_78 -> V_82 -> V_83 ;
V_15 -> V_9 = & V_78 -> V_9 ;
F_40 ( V_15 , V_11 ) ;
V_80 = F_41 ( & V_78 -> V_9 ) ;
if ( V_80 )
V_66 = V_80 -> V_84 == 2 ?
& V_85 : & V_86 ;
return F_42 ( & V_78 -> V_9 , V_15 ) ;
}
