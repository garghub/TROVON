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
V_16 = F_6 ( V_6 , 0 , V_19 ,
V_20 , 48000 * 512 ) ;
if ( V_16 < 0 ) {
F_4 ( V_3 -> V_17 , L_2 , V_16 ) ;
return V_16 ;
}
V_16 = F_7 ( V_6 , V_21 ,
48000 * 512 , V_22 ) ;
if ( V_16 < 0 ) {
F_4 ( V_3 -> V_17 , L_3 , V_16 ) ;
return V_16 ;
}
} else {
F_7 ( V_6 , V_23 ,
48000 * 512 , V_22 ) ;
}
return 0 ;
}
static int F_8 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_4 * V_5 = V_25 -> V_28 ;
struct V_1 * V_6 = V_5 -> V_6 ;
int V_16 ;
V_16 = F_6 ( V_6 , 0 , V_19 ,
V_20 , F_9 ( V_27 ) * 512 ) ;
if ( V_16 < 0 ) {
F_4 ( V_5 -> V_17 , L_2 , V_16 ) ;
return V_16 ;
}
V_16 = F_7 ( V_6 , V_21 ,
F_9 ( V_27 ) * 512 ,
V_22 ) ;
if ( V_16 < 0 ) {
F_4 ( V_5 -> V_17 , L_3 , V_16 ) ;
return V_16 ;
}
return 0 ;
}
static int F_10 ( struct V_4 * V_29 )
{
int V_16 ;
struct V_1 * V_6 = V_29 -> V_6 ;
struct V_30 * V_31 = V_6 -> V_31 ;
V_16 = F_11 ( V_6 , 0xF , 0xF , 4 , 24 ) ;
if ( V_16 < 0 ) {
F_4 ( V_29 -> V_17 , L_4 , V_16 ) ;
return V_16 ;
}
F_12 ( V_31 ,
V_32
| V_33
| V_34
| V_35
| V_36
| V_37 ,
V_38 ) ;
V_16 = F_13 ( V_29 -> V_3 , L_5 ,
V_39 | V_40 |
V_41 | V_42 , & V_43 ,
V_44 , F_14 ( V_44 ) ) ;
if ( V_16 )
return V_16 ;
F_15 ( V_31 , & V_43 ) ;
return 0 ;
}
static int F_16 ( struct V_4 * V_5 ,
struct V_26 * V_27 )
{
struct V_45 * V_46 = F_17 ( V_27 ,
V_47 ) ;
struct V_45 * V_48 = F_17 ( V_27 ,
V_49 ) ;
V_46 -> V_50 = V_46 -> V_51 = 48000 ;
V_48 -> V_50 = V_48 -> V_51 = 2 ;
F_18 ( V_27 , V_52 ) ;
return 0 ;
}
static int F_19 ( struct V_24 * V_25 )
{
return F_20 ( V_25 -> V_29 ,
V_47 , 48000 ) ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_53 * V_54 ;
F_2 (component, &card->component_dev_list, card_list) {
if ( ! strcmp ( V_54 -> V_7 , L_6 ) ) {
struct V_30 * V_31 = F_22 ( V_54 ) ;
F_23 ( V_31 -> V_17 , L_7 ) ;
F_24 ( V_31 ) ;
break;
}
}
return 0 ;
}
static int F_25 ( struct V_2 * V_3 )
{
struct V_53 * V_54 ;
F_2 (component, &card->component_dev_list, card_list) {
if ( ! strcmp ( V_54 -> V_7 , L_6 ) ) {
struct V_30 * V_31 = F_22 ( V_54 ) ;
F_23 ( V_31 -> V_17 , L_8 ) ;
F_26 ( V_31 ) ;
break;
}
}
return 0 ;
}
static int F_27 ( struct V_55 * V_56 )
{
int V_57 = 0 ;
struct V_58 * V_59 = V_56 -> V_17 . V_60 ;
const char * V_61 ;
int V_62 ;
strcpy ( V_63 , V_64 ) ;
if ( V_59 ) {
V_61 = F_28 ( V_59 -> V_65 ) ;
if ( V_61 ) {
snprintf ( V_63 , sizeof( V_63 ) ,
L_9 , V_61 ) ;
for ( V_62 = 0 ; V_62 < F_14 ( V_66 ) ; V_62 ++ ) {
if ( ! strcmp ( V_66 [ V_62 ] . V_67 ,
V_64 ) ) {
V_66 [ V_62 ] . V_67 =
V_63 ;
break;
}
}
}
}
V_68 . V_17 = & V_56 -> V_17 ;
V_57 = F_29 ( & V_56 -> V_17 , & V_68 ) ;
if ( V_57 ) {
F_4 ( & V_56 -> V_17 ,
L_10 , V_57 ) ;
return V_57 ;
}
F_30 ( V_56 , & V_68 ) ;
return V_57 ;
}
