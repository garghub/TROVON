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
V_3 = F_7 ( & V_15 , L_3 ,
V_16 | V_17 | V_18 |
V_19 | V_20 , & V_11 -> V_21 ,
NULL , 0 ) ;
if ( V_3 ) {
F_4 ( V_2 -> V_9 , L_4 , V_3 ) ;
return V_3 ;
}
F_8 ( V_14 , & V_11 -> V_21 ) ;
V_3 = F_3 ( & V_2 -> V_12 -> V_5 , L_5 ) ;
if ( V_3 ) {
F_4 ( V_2 -> V_9 , L_6 , V_3 ) ;
return V_3 ;
}
return V_3 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_6 ( V_2 -> V_12 ) ;
struct V_22 * V_23 = V_2 -> V_24 ;
struct V_25 * V_26 ;
V_26 = F_10 ( V_2 -> V_12 -> V_9 , sizeof( * V_26 ) , V_27 ) ;
if ( ! V_26 )
return - V_28 ;
V_26 -> V_29 = V_30 ;
V_26 -> V_24 = V_23 ;
F_11 ( & V_26 -> V_31 , & V_11 -> V_32 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_6 ( V_2 -> V_12 ) ;
struct V_22 * V_23 = V_2 -> V_24 ;
struct V_25 * V_26 ;
V_26 = F_10 ( V_2 -> V_12 -> V_9 , sizeof( * V_26 ) , V_27 ) ;
if ( ! V_26 )
return - V_28 ;
V_26 -> V_29 = V_33 ;
V_26 -> V_24 = V_23 ;
F_11 ( & V_26 -> V_31 , & V_11 -> V_32 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_6 ( V_2 -> V_12 ) ;
struct V_22 * V_23 = V_2 -> V_24 ;
struct V_25 * V_26 ;
V_26 = F_10 ( V_2 -> V_12 -> V_9 , sizeof( * V_26 ) , V_27 ) ;
if ( ! V_26 )
return - V_28 ;
V_26 -> V_29 = V_34 ;
V_26 -> V_24 = V_23 ;
F_11 ( & V_26 -> V_31 , & V_11 -> V_32 ) ;
return 0 ;
}
static int F_14 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = V_36 -> V_38 ;
V_38 -> V_39 . V_40 = 2 ;
F_15 ( V_38 , 0 , V_41 ,
& V_42 ) ;
V_38 -> V_39 . V_43 = V_44 ;
F_16 ( V_38 , 0 , 16 , 16 ) ;
F_15 ( V_38 , 0 ,
V_45 , & V_46 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_49 * V_50 = F_18 ( V_48 ,
V_45 ) ;
struct V_49 * V_51 = F_18 ( V_48 ,
V_41 ) ;
struct V_52 * V_53 = F_19 ( V_48 , V_54 ) ;
V_50 -> V_55 = V_50 -> V_56 = 48000 ;
V_51 -> V_55 = V_51 -> V_56 = 2 ;
F_20 ( V_53 ) ;
F_21 ( V_53 , V_57 ) ;
return 0 ;
}
static int F_22 ( struct V_35 * V_36 ,
struct V_47 * V_48 )
{
struct V_1 * V_2 = V_36 -> V_58 ;
struct V_22 * V_24 = V_2 -> V_24 ;
int V_3 ;
V_3 = F_23 ( V_24 ,
V_59 , 24576000 , V_60 ) ;
F_24 ( V_24 -> V_14 , V_61 , 1 ) ;
if ( V_3 < 0 )
F_4 ( V_2 -> V_9 , L_7 , V_3 ) ;
return V_3 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_49 * V_51 = F_18 ( V_48 ,
V_41 ) ;
if ( F_26 ( V_48 ) == 2 || F_27 ( V_62 ) == 2 )
V_51 -> V_55 = V_51 -> V_56 = 2 ;
else
V_51 -> V_55 = V_51 -> V_56 = 4 ;
return 0 ;
}
static int F_28 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = V_36 -> V_38 ;
V_38 -> V_39 . V_40 = F_27 ( V_62 ) ;
F_15 ( V_38 , 0 , V_41 ,
V_62 ) ;
return F_15 ( V_36 -> V_38 , 0 ,
V_45 , & V_46 ) ;
}
static int F_29 ( struct V_35 * V_36 )
{
V_36 -> V_38 -> V_39 . V_40 = 1 ;
F_15 ( V_36 -> V_38 , 0 ,
V_41 ,
& V_63 ) ;
return F_15 ( V_36 -> V_38 , 0 ,
V_45 ,
& V_64 ) ;
}
static int F_30 ( struct V_65 * V_12 )
{
struct V_10 * V_11 = F_6 ( V_12 ) ;
struct V_25 * V_26 ;
int V_66 , V_67 = 0 ;
char V_68 [ V_69 ] ;
F_31 (pcm, &ctx->hdmi_pcm_list, head) {
snprintf ( V_68 , sizeof( V_68 ) ,
L_8 , V_26 -> V_29 ) ;
V_66 = F_7 ( V_12 , V_68 ,
V_70 , & V_71 [ V_67 ] ,
NULL , 0 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_32 ( V_26 -> V_24 , V_26 -> V_29 ,
& V_71 [ V_67 ] ) ;
if ( V_66 < 0 )
return V_66 ;
V_67 ++ ;
}
return 0 ;
}
static int F_33 ( struct V_72 * V_73 )
{
struct V_10 * V_11 ;
struct V_74 * V_75 ;
V_11 = F_10 ( & V_73 -> V_9 , sizeof( * V_11 ) , V_76 ) ;
if ( ! V_11 )
return - V_28 ;
F_34 ( & V_11 -> V_32 ) ;
V_15 . V_9 = & V_73 -> V_9 ;
F_35 ( & V_15 , V_11 ) ;
V_75 = F_36 ( & V_73 -> V_9 ) ;
if ( V_75 )
V_62 = V_75 -> V_77 == 2 ?
& V_78 : & V_79 ;
return F_37 ( & V_73 -> V_9 , & V_15 ) ;
}
