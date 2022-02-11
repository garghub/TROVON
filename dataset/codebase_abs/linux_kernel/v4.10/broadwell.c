static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 = 0 ;
V_5 = F_2 ( V_2 -> V_6 , L_1 ,
V_7 | V_8 , & V_9 ,
V_10 , F_3 ( V_10 ) ) ;
if ( V_5 )
return V_5 ;
F_4 ( V_4 , & V_9 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = F_6 ( V_12 ,
V_15 ) ;
struct V_13 * V_16 = F_6 ( V_12 ,
V_17 ) ;
V_14 -> V_18 = V_14 -> V_19 = 48000 ;
V_16 -> V_18 = V_16 -> V_19 = 2 ;
F_7 ( V_12 , V_20 ) ;
return 0 ;
}
static int F_8 ( struct V_21 * V_22 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = V_22 -> V_23 ;
struct V_24 * V_25 = V_2 -> V_25 ;
int V_5 ;
V_5 = F_9 ( V_25 , V_26 , 24000000 ,
V_27 ) ;
if ( V_5 < 0 ) {
F_10 ( V_2 -> V_28 , L_2 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_12 ( V_2 -> V_31 -> V_28 ) ;
struct V_32 * V_33 = V_30 -> V_34 ;
int V_5 ;
V_5 = F_13 ( V_33 , V_35 ,
V_36 ,
V_37 , 9 ) ;
if ( V_5 < 0 ) {
F_10 ( V_2 -> V_28 , L_3 ) ;
return V_5 ;
}
return 0 ;
}
static int F_14 ( struct V_38 * V_6 ) {
struct V_39 * V_40 ;
F_15 (component, &card->component_dev_list, card_list) {
if ( ! strcmp ( V_40 -> V_41 , L_4 ) ) {
struct V_3 * V_4 = F_16 ( V_40 ) ;
F_17 ( V_4 -> V_28 , L_5 ) ;
F_4 ( V_4 , NULL ) ;
break;
}
}
return 0 ;
}
static int F_18 ( struct V_38 * V_6 ) {
struct V_39 * V_40 ;
F_15 (component, &card->component_dev_list, card_list) {
if ( ! strcmp ( V_40 -> V_41 , L_4 ) ) {
struct V_3 * V_4 = F_16 ( V_40 ) ;
F_17 ( V_4 -> V_28 , L_6 ) ;
F_4 ( V_4 , & V_9 ) ;
break;
}
}
return 0 ;
}
static int F_19 ( struct V_42 * V_43 )
{
V_44 . V_28 = & V_43 -> V_28 ;
return F_20 ( & V_43 -> V_28 , & V_44 ) ;
}
