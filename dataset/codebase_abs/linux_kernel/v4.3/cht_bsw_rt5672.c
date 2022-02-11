static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 -> V_5 ; V_4 ++ ) {
struct V_6 * V_7 ;
V_7 = V_3 -> V_7 + V_4 ;
if ( ! strncmp ( V_7 -> V_8 -> V_9 , V_10 ,
strlen ( V_10 ) ) )
return V_7 -> V_8 ;
}
return NULL ;
}
static int F_2 ( struct V_11 * V_12 ,
struct V_13 * V_14 , int V_15 )
{
struct V_16 * V_17 = V_12 -> V_17 ;
struct V_2 * V_3 = V_17 -> V_3 ;
struct V_1 * V_8 ;
int V_18 ;
V_8 = F_1 ( V_3 ) ;
if ( ! V_8 ) {
F_3 ( V_3 -> V_19 , L_1 ) ;
return - V_20 ;
}
if ( F_4 ( V_15 ) ) {
V_18 = F_5 ( V_8 , 0 , V_21 ,
V_22 , 48000 * 512 ) ;
if ( V_18 < 0 ) {
F_3 ( V_3 -> V_19 , L_2 , V_18 ) ;
return V_18 ;
}
V_18 = F_6 ( V_8 , V_23 ,
48000 * 512 , V_24 ) ;
if ( V_18 < 0 ) {
F_3 ( V_3 -> V_19 , L_3 , V_18 ) ;
return V_18 ;
}
} else {
F_6 ( V_8 , V_25 ,
48000 * 512 , V_24 ) ;
}
return 0 ;
}
static int F_7 ( struct V_26 * V_27 ,
struct V_28 * V_29 )
{
struct V_6 * V_7 = V_27 -> V_30 ;
struct V_1 * V_8 = V_7 -> V_8 ;
int V_18 ;
V_18 = F_5 ( V_8 , 0 , V_21 ,
V_22 , F_8 ( V_29 ) * 512 ) ;
if ( V_18 < 0 ) {
F_3 ( V_7 -> V_19 , L_2 , V_18 ) ;
return V_18 ;
}
V_18 = F_6 ( V_8 , V_23 ,
F_8 ( V_29 ) * 512 ,
V_24 ) ;
if ( V_18 < 0 ) {
F_3 ( V_7 -> V_19 , L_3 , V_18 ) ;
return V_18 ;
}
return 0 ;
}
static int F_9 ( struct V_6 * V_31 )
{
int V_18 ;
struct V_1 * V_8 = V_31 -> V_8 ;
struct V_32 * V_33 = V_8 -> V_33 ;
V_18 = F_10 ( V_8 , 0xF , 0xF , 4 , 24 ) ;
if ( V_18 < 0 ) {
F_3 ( V_31 -> V_19 , L_4 , V_18 ) ;
return V_18 ;
}
F_11 ( V_33 ,
V_34
| V_35
| V_36
| V_37
| V_38
| V_39 ,
V_40 ) ;
V_18 = F_12 ( V_31 -> V_3 , L_5 ,
V_41 | V_42 |
V_43 | V_44 , & V_45 ,
V_46 , F_13 ( V_46 ) ) ;
if ( V_18 )
return V_18 ;
F_14 ( V_33 , & V_45 ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 ,
struct V_28 * V_29 )
{
struct V_47 * V_48 = F_16 ( V_29 ,
V_49 ) ;
struct V_47 * V_50 = F_16 ( V_29 ,
V_51 ) ;
V_48 -> V_52 = V_48 -> V_53 = 48000 ;
V_50 -> V_52 = V_50 -> V_53 = 2 ;
F_17 ( V_29 , V_54 ) ;
return 0 ;
}
static int F_18 ( struct V_26 * V_27 )
{
return F_19 ( V_27 -> V_31 , 0 ,
V_49 ,
& V_55 ) ;
}
static int F_20 ( struct V_2 * V_3 )
{
struct V_32 * V_33 ;
F_21 (codec, &card->codec_dev_list, card_list) {
if ( ! strcmp ( V_33 -> V_56 . V_9 , L_6 ) ) {
F_22 ( V_33 -> V_19 , L_7 ) ;
F_23 ( V_33 ) ;
break;
}
}
return 0 ;
}
static int F_24 ( struct V_2 * V_3 )
{
struct V_32 * V_33 ;
F_21 (codec, &card->codec_dev_list, card_list) {
if ( ! strcmp ( V_33 -> V_56 . V_9 , L_6 ) ) {
F_22 ( V_33 -> V_19 , L_8 ) ;
F_25 ( V_33 ) ;
break;
}
}
return 0 ;
}
static int F_26 ( struct V_57 * V_58 )
{
int V_59 = 0 ;
V_60 . V_19 = & V_58 -> V_19 ;
V_59 = F_27 ( & V_58 -> V_19 , & V_60 ) ;
if ( V_59 ) {
F_3 ( & V_58 -> V_19 ,
L_9 , V_59 ) ;
return V_59 ;
}
F_28 ( V_58 , & V_60 ) ;
return V_59 ;
}
