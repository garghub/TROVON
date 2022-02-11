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
F_12 ( & V_5 -> V_3 -> V_15 , L_6 ) ;
return V_16 ;
}
static int F_13 ( struct V_4 * V_5 )
{
struct V_14 * V_15 ;
struct V_32 * V_33 = V_5 -> V_34 -> V_33 ;
V_15 = F_14 ( V_33 ) ;
F_12 ( V_15 , L_7 ) ;
return 0 ;
}
static int F_15 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = V_36 -> V_38 ;
V_38 -> V_39 . V_40 = 2 ;
F_16 ( V_38 , 0 , V_41 ,
& V_42 ) ;
V_38 -> V_39 . V_43 = V_44 ;
F_17 ( V_38 , 0 , 16 , 16 ) ;
F_16 ( V_38 , 0 ,
V_45 , & V_46 ) ;
return 0 ;
}
static int F_18 ( struct V_4 * V_5 ,
struct V_47 * V_48 )
{
struct V_49 * V_50 = F_19 ( V_48 ,
V_45 ) ;
struct V_49 * V_51 = F_19 ( V_48 ,
V_41 ) ;
struct V_52 * V_53 = F_20 ( V_48 , V_54 ) ;
V_50 -> V_55 = V_50 -> V_56 = 48000 ;
V_51 -> V_55 = V_51 -> V_56 = 2 ;
F_21 ( V_53 ) ;
F_22 ( V_53 , V_57 ) ;
return 0 ;
}
static int F_23 ( struct V_4 * V_5 ,
struct V_47 * V_48 )
{
struct V_49 * V_51 = F_19 ( V_48 ,
V_41 ) ;
if ( F_24 ( V_48 ) == 2 )
V_51 -> V_55 = V_51 -> V_56 = 2 ;
else
V_51 -> V_55 = V_51 -> V_56 = 4 ;
return 0 ;
}
static int F_25 ( struct V_35 * V_36 ,
struct V_47 * V_48 )
{
struct V_4 * V_5 = V_36 -> V_58 ;
struct V_1 * V_6 = V_5 -> V_6 ;
int V_16 ;
V_16 = F_6 ( V_6 ,
V_19 , 24000000 , V_20 ) ;
if ( V_16 < 0 )
F_4 ( V_5 -> V_17 , L_8 , V_16 ) ;
return V_16 ;
}
static int F_26 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = V_36 -> V_38 ;
V_38 -> V_39 . V_40 = 4 ;
F_16 ( V_38 , 0 , V_41 ,
& V_59 ) ;
return F_16 ( V_36 -> V_38 , 0 ,
V_45 , & V_46 ) ;
}
static int F_27 ( struct V_35 * V_36 )
{
return F_16 ( V_36 -> V_38 , 0 ,
V_45 ,
& V_60 ) ;
}
static int F_28 ( struct V_61 * V_62 )
{
V_25 . V_17 = & V_62 -> V_17 ;
return F_29 ( & V_62 -> V_17 , & V_25 ) ;
}
