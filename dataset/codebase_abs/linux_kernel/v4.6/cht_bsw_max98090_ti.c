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
struct V_11 * V_12 )
{
struct V_4 * V_5 = V_10 -> V_13 ;
struct V_1 * V_6 = V_5 -> V_6 ;
int V_14 ;
V_14 = F_4 ( V_6 , V_15 ,
V_16 , V_17 ) ;
if ( V_14 < 0 ) {
F_5 ( V_5 -> V_18 , L_1 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
static int F_6 ( struct V_19 * V_20 ,
unsigned long V_21 , void * V_22 )
{
struct V_23 * V_24 = (struct V_23 * ) V_22 ;
struct V_25 * V_26 = & V_24 -> V_3 -> V_26 ;
if ( V_21 & V_27 ) {
F_7 ( V_26 , L_2 ) ;
F_7 ( V_26 , L_3 ) ;
F_8 ( V_26 ) ;
} else {
F_9 ( V_26 , L_3 ) ;
F_9 ( V_26 , L_2 ) ;
F_8 ( V_26 ) ;
}
return 0 ;
}
static int F_10 ( struct V_4 * V_28 )
{
int V_14 ;
int V_29 ;
struct V_30 * V_31 = F_11 ( V_28 -> V_3 ) ;
struct V_23 * V_24 = & V_31 -> V_24 ;
if ( V_31 -> V_32 )
V_29 = V_33 | V_27 |
V_34 | V_35 |
V_36 | V_37 ;
else
V_29 = V_33 | V_27 ;
V_14 = F_12 ( V_28 -> V_3 , L_4 ,
V_29 , V_24 , NULL , 0 ) ;
if ( V_14 ) {
F_5 ( V_28 -> V_18 , L_5 , V_14 ) ;
return V_14 ;
}
if ( V_31 -> V_32 )
F_13 ( V_24 , & V_38 ) ;
return V_14 ;
}
static int F_14 ( struct V_4 * V_5 ,
struct V_11 * V_12 )
{
struct V_39 * V_40 = F_15 ( V_12 ,
V_41 ) ;
struct V_39 * V_42 = F_15 ( V_12 ,
V_43 ) ;
int V_14 = 0 ;
unsigned int V_44 = 0 ;
V_14 = F_16 ( V_5 -> V_45 , 0x3 , 0x3 , 2 , 16 ) ;
if ( V_14 < 0 ) {
F_5 ( V_5 -> V_18 , L_6 , V_14 ) ;
return V_14 ;
}
V_44 = V_46 | V_47
| V_48 ;
V_14 = F_17 ( V_5 -> V_45 , V_44 ) ;
if ( V_14 < 0 ) {
F_5 ( V_5 -> V_18 , L_7 , V_14 ) ;
return V_14 ;
}
V_40 -> V_49 = V_40 -> V_50 = 48000 ;
V_42 -> V_49 = V_42 -> V_50 = 2 ;
F_18 ( V_12 , V_51 ) ;
return 0 ;
}
static int F_19 ( struct V_9 * V_10 )
{
return F_20 ( V_10 -> V_28 ,
V_41 , 48000 ) ;
}
static int F_21 ( struct V_52 * V_53 )
{
struct V_2 * V_3 = V_53 -> V_3 ;
struct V_30 * V_31 = F_11 ( V_3 ) ;
return F_22 ( V_53 , & V_31 -> V_24 ) ;
}
static int F_23 ( struct V_54 * V_55 )
{
int V_56 = 0 ;
struct V_30 * V_57 ;
V_57 = F_24 ( & V_55 -> V_18 , sizeof( * V_57 ) , V_58 ) ;
if ( ! V_57 )
return - V_59 ;
V_57 -> V_32 = F_25 ( L_8 ) ;
if ( ! V_57 -> V_32 ) {
V_60 . V_61 = NULL ;
V_60 . V_62 = 0 ;
}
V_60 . V_18 = & V_55 -> V_18 ;
F_26 ( & V_60 , V_57 ) ;
V_56 = F_27 ( & V_55 -> V_18 , & V_60 ) ;
if ( V_56 ) {
F_5 ( & V_55 -> V_18 ,
L_9 , V_56 ) ;
return V_56 ;
}
F_28 ( V_55 , & V_60 ) ;
return V_56 ;
}
