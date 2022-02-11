static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
F_2 (rtd, &card->rtd_list, list) {
if ( ! strncmp ( V_5 -> V_6 -> V_7 , V_8 ,
strlen ( V_8 ) ) )
return V_5 -> V_6 ;
}
return NULL ;
}
static int F_3 ( struct V_9 * V_10 ,
struct V_11 * V_12 , int V_13 )
{
struct V_14 * V_15 = V_10 -> V_15 ;
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_1 * V_6 ;
int V_16 ;
V_6 = F_1 ( V_3 ) ;
if ( ! V_6 ) {
F_4 ( V_3 -> V_17 , L_1 ) ;
return - V_18 ;
}
if ( F_5 ( V_13 ) ) {
V_16 = F_6 ( V_6 ,
V_19 , 24000000 , V_20 ) ;
if ( V_16 < 0 ) {
F_4 ( V_3 -> V_17 , L_2 , V_16 ) ;
return - V_18 ;
}
} else {
V_16 = F_6 ( V_6 ,
V_21 , 0 , V_20 ) ;
if ( V_16 < 0 ) {
F_4 ( V_3 -> V_17 , L_2 , V_16 ) ;
return - V_18 ;
}
}
return V_16 ;
}
static int F_7 ( struct V_4 * V_5 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 = F_8 ( V_23 ,
V_26 ) ;
struct V_24 * V_27 = F_8 ( V_23 ,
V_28 ) ;
struct V_29 * V_30 = F_9 ( V_23 , V_31 ) ;
V_25 -> V_32 = V_25 -> V_33 = 48000 ;
V_27 -> V_32 = V_27 -> V_33 = 2 ;
F_10 ( V_30 ) ;
F_11 ( V_30 , V_34 ) ;
return 0 ;
}
static int F_12 ( struct V_4 * V_5 )
{
int V_16 ;
struct V_35 * V_36 = V_5 -> V_36 ;
V_16 = F_13 ( & V_37 , L_3 ,
V_38 | V_39 | V_40 |
V_41 | V_42 , & V_43 ,
NULL , 0 ) ;
if ( V_16 ) {
F_4 ( V_5 -> V_17 , L_4 , V_16 ) ;
return V_16 ;
}
F_14 ( V_36 , & V_43 ) ;
F_15 ( & V_5 -> V_3 -> V_15 , L_5 ) ;
return V_16 ;
}
static int F_16 ( struct V_4 * V_5 )
{
struct V_44 * V_45 = F_17 ( V_5 -> V_3 ) ;
struct V_1 * V_46 = V_5 -> V_6 ;
struct V_47 * V_48 ;
V_48 = F_18 ( V_5 -> V_3 -> V_17 , sizeof( * V_48 ) , V_49 ) ;
if ( ! V_48 )
return - V_50 ;
V_48 -> V_51 = V_52 ;
V_48 -> V_6 = V_46 ;
F_19 ( & V_48 -> V_53 , & V_45 -> V_54 ) ;
return 0 ;
}
static int F_20 ( struct V_4 * V_5 )
{
struct V_44 * V_45 = F_17 ( V_5 -> V_3 ) ;
struct V_1 * V_46 = V_5 -> V_6 ;
struct V_47 * V_48 ;
V_48 = F_18 ( V_5 -> V_3 -> V_17 , sizeof( * V_48 ) , V_49 ) ;
if ( ! V_48 )
return - V_50 ;
V_48 -> V_51 = V_55 ;
V_48 -> V_6 = V_46 ;
F_19 ( & V_48 -> V_53 , & V_45 -> V_54 ) ;
return 0 ;
}
static int F_21 ( struct V_4 * V_5 )
{
struct V_44 * V_45 = F_17 ( V_5 -> V_3 ) ;
struct V_1 * V_46 = V_5 -> V_6 ;
struct V_47 * V_48 ;
V_48 = F_18 ( V_5 -> V_3 -> V_17 , sizeof( * V_48 ) , V_49 ) ;
if ( ! V_48 )
return - V_50 ;
V_48 -> V_51 = V_56 ;
V_48 -> V_6 = V_46 ;
F_19 ( & V_48 -> V_53 , & V_45 -> V_54 ) ;
return 0 ;
}
static int F_22 ( struct V_4 * V_5 )
{
struct V_14 * V_15 ;
struct V_57 * V_58 = V_5 -> V_59 -> V_58 ;
V_15 = F_23 ( V_58 ) ;
F_15 ( V_15 , L_6 ) ;
return 0 ;
}
static int F_24 ( struct V_60 * V_61 )
{
struct V_62 * V_63 = V_61 -> V_63 ;
V_63 -> V_64 . V_65 = 2 ;
F_25 ( V_63 , 0 , V_28 ,
& V_66 ) ;
V_63 -> V_64 . V_67 = V_68 ;
F_26 ( V_63 , 0 , 16 , 16 ) ;
F_25 ( V_63 , 0 ,
V_26 , & V_69 ) ;
return 0 ;
}
static int F_27 ( struct V_60 * V_61 ,
struct V_22 * V_23 )
{
struct V_4 * V_5 = V_61 -> V_70 ;
struct V_1 * V_6 = V_5 -> V_6 ;
int V_16 ;
V_16 = F_6 ( V_6 ,
V_19 , 24000000 , V_20 ) ;
if ( V_16 < 0 )
F_4 ( V_5 -> V_17 , L_7 , V_16 ) ;
return V_16 ;
}
static int F_28 ( struct V_4 * V_5 ,
struct V_22 * V_23 )
{
struct V_24 * V_27 = F_8 ( V_23 ,
V_28 ) ;
if ( F_29 ( V_23 ) == 2 || F_30 ( V_71 ) == 2 )
V_27 -> V_32 = V_27 -> V_33 = 2 ;
else
V_27 -> V_32 = V_27 -> V_33 = 4 ;
return 0 ;
}
static int F_31 ( struct V_60 * V_61 )
{
struct V_62 * V_63 = V_61 -> V_63 ;
V_63 -> V_64 . V_65 = F_30 ( V_71 ) ;
F_25 ( V_63 , 0 , V_28 ,
V_71 ) ;
return F_25 ( V_61 -> V_63 , 0 ,
V_26 , & V_69 ) ;
}
static int F_32 ( struct V_60 * V_61 )
{
V_61 -> V_63 -> V_64 . V_65 = 1 ;
F_25 ( V_61 -> V_63 , 0 ,
V_28 ,
& V_72 ) ;
return F_25 ( V_61 -> V_63 , 0 ,
V_26 ,
& V_73 ) ;
}
static int F_33 ( struct V_2 * V_3 )
{
struct V_44 * V_45 = F_17 ( V_3 ) ;
struct V_47 * V_48 ;
int V_74 ;
F_2 (pcm, &ctx->hdmi_pcm_list, head) {
V_74 = F_34 ( V_48 -> V_6 , V_48 -> V_51 ) ;
if ( V_74 < 0 )
return V_74 ;
}
return 0 ;
}
static int F_35 ( struct V_75 * V_76 )
{
struct V_44 * V_45 ;
struct V_77 * V_78 ;
V_45 = F_18 ( & V_76 -> V_17 , sizeof( * V_45 ) , V_79 ) ;
if ( ! V_45 )
return - V_50 ;
F_36 ( & V_45 -> V_54 ) ;
V_37 . V_17 = & V_76 -> V_17 ;
F_37 ( & V_37 , V_45 ) ;
V_78 = F_38 ( & V_76 -> V_17 ) ;
if ( V_78 )
V_71 = V_78 -> V_80 == 2 ?
& V_81 : & V_82 ;
return F_39 ( & V_76 -> V_17 , & V_37 ) ;
}
