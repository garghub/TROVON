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
static int F_7 ( struct V_4 * V_5 )
{
int V_16 ;
V_16 = F_8 ( V_5 -> V_22 [ 0 ] , 0x01 , 0x01 , 2 , 48 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_8 ( V_5 -> V_22 [ 1 ] , 0x02 , 0x02 , 2 , 48 ) ;
if ( V_16 < 0 )
return V_16 ;
return V_16 ;
}
static int F_9 ( struct V_4 * V_5 )
{
int V_16 ;
struct V_23 * V_24 = V_5 -> V_24 ;
V_16 = F_10 ( & V_25 , L_3 ,
V_26 | V_27 | V_28 |
V_29 | V_30 , & V_31 ,
NULL , 0 ) ;
if ( V_16 ) {
F_4 ( V_5 -> V_17 , L_4 , V_16 ) ;
return V_16 ;
}
F_11 ( V_24 , & V_31 ) ;
F_12 ( & V_5 -> V_3 -> V_15 , L_5 ) ;
return V_16 ;
}
static int F_13 ( struct V_4 * V_5 )
{
struct V_32 * V_33 = F_14 ( V_5 -> V_3 ) ;
struct V_1 * V_34 = V_5 -> V_6 ;
struct V_35 * V_36 ;
V_36 = F_15 ( V_5 -> V_3 -> V_17 , sizeof( * V_36 ) , V_37 ) ;
if ( ! V_36 )
return - V_38 ;
V_36 -> V_39 = V_40 ;
V_36 -> V_6 = V_34 ;
F_16 ( & V_36 -> V_41 , & V_33 -> V_42 ) ;
return 0 ;
}
static int F_17 ( struct V_4 * V_5 )
{
struct V_32 * V_33 = F_14 ( V_5 -> V_3 ) ;
struct V_1 * V_34 = V_5 -> V_6 ;
struct V_35 * V_36 ;
V_36 = F_15 ( V_5 -> V_3 -> V_17 , sizeof( * V_36 ) , V_37 ) ;
if ( ! V_36 )
return - V_38 ;
V_36 -> V_39 = V_43 ;
V_36 -> V_6 = V_34 ;
F_16 ( & V_36 -> V_41 , & V_33 -> V_42 ) ;
return 0 ;
}
static int F_18 ( struct V_4 * V_5 )
{
struct V_32 * V_33 = F_14 ( V_5 -> V_3 ) ;
struct V_1 * V_34 = V_5 -> V_6 ;
struct V_35 * V_36 ;
V_36 = F_15 ( V_5 -> V_3 -> V_17 , sizeof( * V_36 ) , V_37 ) ;
if ( ! V_36 )
return - V_38 ;
V_36 -> V_39 = V_44 ;
V_36 -> V_6 = V_34 ;
F_16 ( & V_36 -> V_41 , & V_33 -> V_42 ) ;
return 0 ;
}
static int F_19 ( struct V_4 * V_5 )
{
struct V_14 * V_15 ;
struct V_45 * V_46 = V_5 -> V_47 -> V_46 ;
V_15 = F_20 ( V_46 ) ;
F_12 ( V_15 , L_6 ) ;
return 0 ;
}
static int F_21 ( struct V_48 * V_49 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
V_51 -> V_52 . V_53 = 2 ;
F_22 ( V_51 , 0 , V_54 ,
& V_55 ) ;
V_51 -> V_52 . V_56 = V_57 ;
F_23 ( V_51 , 0 , 16 , 16 ) ;
F_22 ( V_51 , 0 ,
V_58 , & V_59 ) ;
return 0 ;
}
static int F_24 ( struct V_4 * V_5 ,
struct V_60 * V_61 )
{
struct V_62 * V_63 = F_25 ( V_61 ,
V_58 ) ;
struct V_62 * V_64 = F_25 ( V_61 ,
V_54 ) ;
struct V_65 * V_66 = F_26 ( V_61 , V_67 ) ;
V_63 -> V_68 = V_63 -> V_69 = 48000 ;
V_64 -> V_68 = V_64 -> V_69 = 2 ;
F_27 ( V_66 ) ;
F_28 ( V_66 , V_70 ) ;
return 0 ;
}
static int F_29 ( struct V_4 * V_5 ,
struct V_60 * V_61 )
{
struct V_62 * V_64 = F_25 ( V_61 ,
V_54 ) ;
if ( F_30 ( V_61 ) == 2 || F_31 ( V_71 ) == 2 )
V_64 -> V_68 = V_64 -> V_69 = 2 ;
else
V_64 -> V_68 = V_64 -> V_69 = 4 ;
return 0 ;
}
static int F_32 ( struct V_48 * V_49 ,
struct V_60 * V_61 )
{
struct V_4 * V_5 = V_49 -> V_72 ;
struct V_1 * V_6 = V_5 -> V_6 ;
int V_16 ;
V_16 = F_6 ( V_6 ,
V_19 , 24000000 , V_20 ) ;
if ( V_16 < 0 )
F_4 ( V_5 -> V_17 , L_7 , V_16 ) ;
return V_16 ;
}
static int F_33 ( struct V_48 * V_49 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
V_51 -> V_52 . V_53 = F_31 ( V_71 ) ;
F_22 ( V_51 , 0 , V_54 ,
V_71 ) ;
return F_22 ( V_49 -> V_51 , 0 ,
V_58 , & V_59 ) ;
}
static int F_34 ( struct V_48 * V_49 )
{
V_49 -> V_51 -> V_52 . V_53 = 1 ;
F_22 ( V_49 -> V_51 , 0 ,
V_54 ,
& V_73 ) ;
return F_22 ( V_49 -> V_51 , 0 ,
V_58 ,
& V_74 ) ;
}
static int F_35 ( struct V_2 * V_3 )
{
struct V_32 * V_33 = F_14 ( V_3 ) ;
struct V_35 * V_36 ;
struct V_23 * V_24 = NULL ;
int V_75 , V_76 = 0 ;
char V_77 [ V_78 ] ;
F_2 (pcm, &ctx->hdmi_pcm_list, head) {
V_24 = V_36 -> V_6 -> V_24 ;
snprintf ( V_77 , sizeof( V_77 ) ,
L_8 , V_36 -> V_39 ) ;
V_75 = F_10 ( V_3 , V_77 ,
V_79 ,
& V_80 [ V_76 ] ,
NULL , 0 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_36 ( V_36 -> V_6 , V_36 -> V_39 ,
& V_80 [ V_76 ] ) ;
if ( V_75 < 0 )
return V_75 ;
V_76 ++ ;
}
if ( ! V_24 )
return - V_81 ;
return F_37 ( V_24 , & V_3 -> V_15 ) ;
}
static int F_38 ( struct V_82 * V_83 )
{
struct V_32 * V_33 ;
struct V_84 * V_85 ;
V_33 = F_15 ( & V_83 -> V_17 , sizeof( * V_33 ) , V_86 ) ;
if ( ! V_33 )
return - V_38 ;
F_39 ( & V_33 -> V_42 ) ;
V_25 . V_17 = & V_83 -> V_17 ;
F_40 ( & V_25 , V_33 ) ;
V_85 = F_41 ( & V_83 -> V_17 ) ;
if ( V_85 )
V_71 = V_85 -> V_87 == 2 ?
& V_88 : & V_89 ;
return F_42 ( & V_83 -> V_17 , & V_25 ) ;
}
