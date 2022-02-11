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
static int F_3 ( struct V_4 * V_9 )
{
struct V_2 * V_3 = V_9 -> V_3 ;
struct V_10 * V_11 = F_4 ( V_3 ) ;
int V_12 ;
V_3 -> V_13 . V_14 = true ;
V_12 = F_5 ( V_11 -> V_15 ) ;
if ( ! V_12 )
F_6 ( V_11 -> V_15 ) ;
V_12 = F_7 ( V_11 -> V_15 , 19200000 ) ;
if ( V_12 )
F_8 ( V_3 -> V_16 , L_1 ) ;
V_12 = F_5 ( V_11 -> V_15 ) ;
if ( V_12 )
F_8 ( V_3 -> V_16 , L_2 ) ;
V_12 = F_9 ( V_9 -> V_6 , 0 , 19200000 ,
V_17 ) ;
if ( V_12 < 0 ) {
F_8 ( V_3 -> V_16 , L_3 , V_12 ) ;
return V_12 ;
}
return 0 ;
}
static int F_10 ( struct V_4 * V_5 ,
struct V_18 * V_19 )
{
struct V_20 * V_21 = F_11 ( V_19 ,
V_22 ) ;
struct V_20 * V_23 = F_11 ( V_19 ,
V_24 ) ;
int V_12 ;
V_21 -> V_25 = V_21 -> V_26 = 48000 ;
V_23 -> V_25 = V_23 -> V_26 = 2 ;
F_12 ( V_19 , V_27 ) ;
V_12 = F_13 ( V_5 -> V_28 ,
V_29 |
V_30 |
V_31
) ;
if ( V_12 < 0 ) {
F_8 ( V_5 -> V_16 , L_4 , V_12 ) ;
return V_12 ;
}
V_12 = F_14 ( V_5 -> V_28 , 0x3 , 0x3 , 2 , 24 ) ;
if ( V_12 < 0 ) {
F_8 ( V_5 -> V_16 , L_5 , V_12 ) ;
return V_12 ;
}
return 0 ;
}
static int F_15 ( struct V_32 * V_33 )
{
return F_16 ( V_33 -> V_9 ,
V_22 , 48000 ) ;
}
static int F_17 ( struct V_34 * V_35 )
{
int V_12 = 0 ;
struct V_10 * V_11 ;
V_11 = F_18 ( & V_35 -> V_16 , sizeof( * V_11 ) , V_36 ) ;
if ( ! V_11 )
return - V_37 ;
V_38 . V_16 = & V_35 -> V_16 ;
F_19 ( & V_38 , V_11 ) ;
V_11 -> V_15 = F_20 ( & V_35 -> V_16 , L_6 ) ;
if ( F_21 ( V_11 -> V_15 ) ) {
V_12 = F_22 ( V_11 -> V_15 ) ;
F_8 ( & V_35 -> V_16 ,
L_7 ,
V_12 ) ;
return V_12 ;
}
V_12 = F_23 ( & V_35 -> V_16 , & V_38 ) ;
if ( V_12 ) {
F_8 ( & V_35 -> V_16 , L_8 , V_12 ) ;
return V_12 ;
}
F_24 ( V_35 , & V_38 ) ;
return V_12 ;
}
