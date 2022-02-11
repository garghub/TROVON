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
struct V_1 * V_32 = V_5 -> V_6 ;
return F_14 ( V_32 , V_33 ) ;
}
static int F_15 ( struct V_4 * V_5 )
{
struct V_1 * V_32 = V_5 -> V_6 ;
return F_14 ( V_32 , V_34 ) ;
}
static int F_16 ( struct V_4 * V_5 )
{
struct V_1 * V_32 = V_5 -> V_6 ;
return F_14 ( V_32 , V_35 ) ;
}
static int F_17 ( struct V_4 * V_5 )
{
struct V_14 * V_15 ;
struct V_36 * V_37 = V_5 -> V_38 -> V_37 ;
V_15 = F_18 ( V_37 ) ;
F_12 ( V_15 , L_6 ) ;
return 0 ;
}
static int F_19 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_42 ;
V_42 -> V_43 . V_44 = 2 ;
F_20 ( V_42 , 0 , V_45 ,
& V_46 ) ;
V_42 -> V_43 . V_47 = V_48 ;
F_21 ( V_42 , 0 , 16 , 16 ) ;
F_20 ( V_42 , 0 ,
V_49 , & V_50 ) ;
return 0 ;
}
static int F_22 ( struct V_4 * V_5 ,
struct V_51 * V_52 )
{
struct V_53 * V_54 = F_23 ( V_52 ,
V_49 ) ;
struct V_53 * V_55 = F_23 ( V_52 ,
V_45 ) ;
struct V_56 * V_57 = F_24 ( V_52 , V_58 ) ;
V_54 -> V_59 = V_54 -> V_60 = 48000 ;
V_55 -> V_59 = V_55 -> V_60 = 2 ;
F_25 ( V_57 ) ;
F_26 ( V_57 , V_61 ) ;
return 0 ;
}
static int F_27 ( struct V_4 * V_5 ,
struct V_51 * V_52 )
{
struct V_53 * V_55 = F_23 ( V_52 ,
V_45 ) ;
if ( F_28 ( V_52 ) == 2 )
V_55 -> V_59 = V_55 -> V_60 = 2 ;
else
V_55 -> V_59 = V_55 -> V_60 = 4 ;
return 0 ;
}
static int F_29 ( struct V_39 * V_40 ,
struct V_51 * V_52 )
{
struct V_4 * V_5 = V_40 -> V_62 ;
struct V_1 * V_6 = V_5 -> V_6 ;
int V_16 ;
V_16 = F_6 ( V_6 ,
V_19 , 24000000 , V_20 ) ;
if ( V_16 < 0 )
F_4 ( V_5 -> V_17 , L_7 , V_16 ) ;
return V_16 ;
}
static int F_30 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_42 ;
V_42 -> V_43 . V_44 = 4 ;
F_20 ( V_42 , 0 , V_45 ,
& V_63 ) ;
return F_20 ( V_40 -> V_42 , 0 ,
V_49 , & V_50 ) ;
}
static int F_31 ( struct V_39 * V_40 )
{
return F_20 ( V_40 -> V_42 , 0 ,
V_49 ,
& V_64 ) ;
}
static int F_32 ( struct V_65 * V_66 )
{
V_25 . V_17 = & V_66 -> V_17 ;
return F_33 ( & V_66 -> V_17 , & V_25 ) ;
}
