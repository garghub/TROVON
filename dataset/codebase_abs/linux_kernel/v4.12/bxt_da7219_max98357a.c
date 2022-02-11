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
int V_14 = 0 ;
struct V_15 * V_16 = V_10 -> V_16 ;
struct V_2 * V_3 = V_16 -> V_3 ;
struct V_1 * V_6 ;
V_6 = F_1 ( V_3 ) ;
if ( ! V_6 ) {
F_4 ( V_3 -> V_17 , L_1 ) ;
return - V_18 ;
}
if ( F_5 ( V_13 ) ) {
V_14 = F_6 ( V_6 , 0 ,
V_19 , 0 , 0 ) ;
if ( V_14 )
F_4 ( V_3 -> V_17 , L_2 , V_14 ) ;
} else if( F_7 ( V_13 ) ) {
V_14 = F_8 ( V_6 ,
V_20 , 19200000 , V_21 ) ;
if ( V_14 )
F_4 ( V_3 -> V_17 , L_3 ) ;
V_14 = F_6 ( V_6 , 0 ,
V_22 , 0 , V_23 ) ;
if ( V_14 )
F_4 ( V_3 -> V_17 , L_4 , V_14 ) ;
}
return V_14 ;
}
static int F_9 ( struct V_4 * V_5 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = F_10 ( V_25 ,
V_28 ) ;
struct V_26 * V_29 = F_10 ( V_25 ,
V_30 ) ;
struct V_31 * V_32 = F_11 ( V_25 , V_33 ) ;
V_27 -> V_34 = V_27 -> V_35 = 48000 ;
V_29 -> V_34 = V_29 -> V_35 = V_36 ;
F_12 ( V_32 ) ;
F_13 ( V_32 , V_37 ) ;
return 0 ;
}
static int F_14 ( struct V_4 * V_5 )
{
int V_14 ;
struct V_38 * V_39 = V_5 -> V_39 ;
V_14 = F_15 ( V_5 -> V_3 , L_5 ,
V_40 | V_41 | V_42 |
V_43 | V_44 | V_45 ,
& V_46 , NULL , 0 ) ;
if ( V_14 ) {
F_4 ( V_5 -> V_17 , L_6 , V_14 ) ;
return V_14 ;
}
F_16 ( V_39 , & V_46 ) ;
F_17 ( & V_5 -> V_3 -> V_16 , L_7 ) ;
return V_14 ;
}
static int F_18 ( struct V_4 * V_5 )
{
struct V_47 * V_48 = F_19 ( V_5 -> V_3 ) ;
struct V_1 * V_49 = V_5 -> V_6 ;
struct V_50 * V_51 ;
V_51 = F_20 ( V_5 -> V_3 -> V_17 , sizeof( * V_51 ) , V_52 ) ;
if ( ! V_51 )
return - V_53 ;
V_51 -> V_54 = V_55 + V_49 -> V_56 ;
V_51 -> V_6 = V_49 ;
F_21 ( & V_51 -> V_57 , & V_48 -> V_58 ) ;
return 0 ;
}
static int F_22 ( struct V_4 * V_5 )
{
struct V_15 * V_16 ;
struct V_59 * V_60 = V_5 -> V_61 -> V_60 ;
V_16 = F_23 ( V_60 ) ;
F_17 ( V_16 , L_8 ) ;
return 0 ;
}
static int F_24 ( struct V_62 * V_63 )
{
struct V_64 * V_65 = V_63 -> V_65 ;
V_65 -> V_66 . V_67 = V_36 ;
F_25 ( V_65 , 0 , V_30 ,
& V_68 ) ;
V_65 -> V_66 . V_69 = V_70 ;
F_26 ( V_65 , 0 , 16 , 16 ) ;
F_25 ( V_65 , 0 ,
V_28 , & V_71 ) ;
return 0 ;
}
static int F_27 ( struct V_4 * V_5 ,
struct V_24 * V_25 )
{
struct V_26 * V_29 = F_10 ( V_25 ,
V_30 ) ;
if ( F_28 ( V_25 ) == 2 )
V_29 -> V_34 = V_29 -> V_35 = 2 ;
else
V_29 -> V_34 = V_29 -> V_35 = 4 ;
return 0 ;
}
static int F_29 ( struct V_62 * V_63 )
{
struct V_64 * V_65 = V_63 -> V_65 ;
V_65 -> V_66 . V_72 = V_65 -> V_66 . V_67 = V_73 ;
F_25 ( V_65 , 0 , V_30 ,
& V_74 ) ;
return F_25 ( V_63 -> V_65 , 0 ,
V_28 , & V_71 ) ;
}
static int F_30 ( struct V_62 * V_63 )
{
return F_25 ( V_63 -> V_65 , 0 ,
V_28 ,
& V_75 ) ;
}
static int F_31 ( struct V_2 * V_3 )
{
struct V_47 * V_48 = F_19 ( V_3 ) ;
struct V_50 * V_51 ;
struct V_38 * V_39 = NULL ;
int V_76 , V_77 = 0 ;
char V_78 [ V_79 ] ;
F_2 (pcm, &ctx->hdmi_pcm_list, head) {
V_39 = V_51 -> V_6 -> V_39 ;
snprintf ( V_78 , sizeof( V_78 ) ,
L_9 , V_51 -> V_54 ) ;
V_76 = F_15 ( V_3 , V_78 ,
V_80 , & V_81 [ V_77 ] ,
NULL , 0 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_32 ( V_51 -> V_6 , V_51 -> V_54 ,
& V_81 [ V_77 ] ) ;
if ( V_76 < 0 )
return V_76 ;
V_77 ++ ;
}
if ( ! V_39 )
return - V_82 ;
return F_33 ( V_39 , & V_3 -> V_16 ) ;
}
static int F_34 ( struct V_83 * V_84 )
{
struct V_47 * V_48 ;
V_48 = F_20 ( & V_84 -> V_17 , sizeof( * V_48 ) , V_85 ) ;
if ( ! V_48 )
return - V_53 ;
F_35 ( & V_48 -> V_58 ) ;
V_86 . V_17 = & V_84 -> V_17 ;
F_36 ( & V_86 , V_48 ) ;
return F_37 ( & V_84 -> V_17 , & V_86 ) ;
}
