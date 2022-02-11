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
struct V_16 * V_17 = F_4 ( V_3 ) ;
int V_18 ;
V_6 = F_1 ( V_3 ) ;
if ( ! V_6 ) {
F_5 ( V_3 -> V_19 , L_1 ) ;
return - V_20 ;
}
if ( F_6 ( V_13 ) ) {
if ( V_17 -> V_21 ) {
V_18 = F_7 ( V_17 -> V_21 ) ;
if ( V_18 < 0 ) {
F_5 ( V_3 -> V_19 ,
L_2 ) ;
return V_18 ;
}
}
V_18 = F_8 ( V_6 , 0 , V_22 ,
V_23 , 48000 * 512 ) ;
if ( V_18 < 0 ) {
F_5 ( V_3 -> V_19 , L_3 , V_18 ) ;
return V_18 ;
}
V_18 = F_9 ( V_6 , V_24 ,
48000 * 512 , V_25 ) ;
if ( V_18 < 0 ) {
F_5 ( V_3 -> V_19 , L_4 , V_18 ) ;
return V_18 ;
}
} else {
F_9 ( V_6 , V_26 ,
48000 * 512 , V_25 ) ;
if ( V_17 -> V_21 )
F_10 ( V_17 -> V_21 ) ;
}
return 0 ;
}
static int F_11 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_4 * V_5 = V_28 -> V_31 ;
struct V_1 * V_6 = V_5 -> V_6 ;
int V_18 ;
V_18 = F_8 ( V_6 , 0 , V_22 ,
V_23 , F_12 ( V_30 ) * 512 ) ;
if ( V_18 < 0 ) {
F_5 ( V_5 -> V_19 , L_3 , V_18 ) ;
return V_18 ;
}
V_18 = F_9 ( V_6 , V_24 ,
F_12 ( V_30 ) * 512 ,
V_25 ) ;
if ( V_18 < 0 ) {
F_5 ( V_5 -> V_19 , L_4 , V_18 ) ;
return V_18 ;
}
return 0 ;
}
static int F_13 ( struct V_4 * V_32 )
{
int V_18 ;
struct V_1 * V_6 = V_32 -> V_6 ;
struct V_33 * V_34 = V_6 -> V_34 ;
struct V_16 * V_17 = F_4 ( V_32 -> V_3 ) ;
if ( F_14 ( V_34 -> V_19 , V_35 ) )
F_15 ( V_32 -> V_19 , L_5 ) ;
V_18 = F_16 ( V_6 , 0xF , 0xF , 4 , 24 ) ;
if ( V_18 < 0 ) {
F_5 ( V_32 -> V_19 , L_6 , V_18 ) ;
return V_18 ;
}
F_17 ( V_34 ,
V_36
| V_37
| V_38
| V_39
| V_40
| V_41 ,
V_42 ) ;
V_18 = F_18 ( V_32 -> V_3 , L_7 ,
V_43 | V_44 |
V_45 | V_46 ,
& V_17 -> V_47 ,
V_48 ,
F_19 ( V_48 ) ) ;
if ( V_18 )
return V_18 ;
F_20 ( V_34 , & V_17 -> V_47 ) ;
if ( V_17 -> V_21 ) {
V_18 = F_7 ( V_17 -> V_21 ) ;
if ( ! V_18 )
F_10 ( V_17 -> V_21 ) ;
V_18 = F_21 ( V_17 -> V_21 , V_23 ) ;
if ( V_18 ) {
F_5 ( V_32 -> V_19 , L_8 ) ;
return V_18 ;
}
}
return 0 ;
}
static int F_22 ( struct V_4 * V_5 ,
struct V_29 * V_30 )
{
struct V_49 * V_50 = F_23 ( V_30 ,
V_51 ) ;
struct V_49 * V_52 = F_23 ( V_30 ,
V_53 ) ;
V_50 -> V_54 = V_50 -> V_55 = 48000 ;
V_52 -> V_54 = V_52 -> V_55 = 2 ;
F_24 ( V_30 , V_56 ) ;
return 0 ;
}
static int F_25 ( struct V_27 * V_28 )
{
return F_26 ( V_28 -> V_32 ,
V_51 , 48000 ) ;
}
static int F_27 ( struct V_2 * V_3 )
{
struct V_57 * V_58 ;
F_2 (component, &card->component_dev_list, card_list) {
if ( ! strcmp ( V_58 -> V_7 , L_9 ) ) {
struct V_33 * V_34 = F_28 ( V_58 ) ;
F_29 ( V_34 -> V_19 , L_10 ) ;
F_30 ( V_34 ) ;
break;
}
}
return 0 ;
}
static int F_31 ( struct V_2 * V_3 )
{
struct V_57 * V_58 ;
F_2 (component, &card->component_dev_list, card_list) {
if ( ! strcmp ( V_58 -> V_7 , L_9 ) ) {
struct V_33 * V_34 = F_28 ( V_58 ) ;
F_29 ( V_34 -> V_19 , L_11 ) ;
F_32 ( V_34 ) ;
break;
}
}
return 0 ;
}
static bool F_33 ( void )
{
static const struct V_59 V_60 [] = {
{ V_61 , 6 , 55 } ,
{}
} ;
if ( ! F_34 ( V_60 ) )
return false ;
return true ;
}
static int F_35 ( struct V_62 * V_63 )
{
int V_64 = 0 ;
struct V_16 * V_65 ;
struct V_66 * V_67 = V_63 -> V_19 . V_68 ;
const char * V_69 ;
int V_70 ;
V_65 = F_36 ( & V_63 -> V_19 , sizeof( * V_65 ) , V_71 ) ;
if ( ! V_65 )
return - V_72 ;
strcpy ( V_65 -> V_73 , V_74 ) ;
if ( V_67 ) {
V_69 = F_37 ( V_67 -> V_75 ) ;
if ( V_69 ) {
snprintf ( V_65 -> V_73 , sizeof( V_65 -> V_73 ) ,
L_12 , V_69 ) ;
for ( V_70 = 0 ; V_70 < F_19 ( V_76 ) ; V_70 ++ ) {
if ( ! strcmp ( V_76 [ V_70 ] . V_73 ,
V_74 ) ) {
V_76 [ V_70 ] . V_73 =
V_65 -> V_73 ;
break;
}
}
}
}
if ( F_33 () ) {
V_65 -> V_21 = F_38 ( & V_63 -> V_19 , L_13 ) ;
if ( F_39 ( V_65 -> V_21 ) ) {
F_5 ( & V_63 -> V_19 ,
L_14 ,
F_40 ( V_65 -> V_21 ) ) ;
return F_40 ( V_65 -> V_21 ) ;
}
}
F_41 ( & V_77 , V_65 ) ;
V_77 . V_19 = & V_63 -> V_19 ;
V_64 = F_42 ( & V_63 -> V_19 , & V_77 ) ;
if ( V_64 ) {
F_5 ( & V_63 -> V_19 ,
L_15 , V_64 ) ;
return V_64 ;
}
F_43 ( V_63 , & V_77 ) ;
return V_64 ;
}
