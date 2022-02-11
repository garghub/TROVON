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
if ( ! F_5 ( V_13 ) )
return 0 ;
V_16 = F_6 ( V_6 , V_19 ,
0 , V_20 ) ;
if ( V_16 < 0 ) {
F_4 ( V_3 -> V_17 , L_2 , V_16 ) ;
return V_16 ;
}
return 0 ;
}
static int F_7 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_4 * V_5 = V_22 -> V_25 ;
struct V_1 * V_6 = V_5 -> V_6 ;
int V_16 ;
V_16 = F_8 ( V_6 , 0 , V_26 ,
V_27 , F_9 ( V_24 ) * 512 ) ;
if ( V_16 < 0 ) {
F_4 ( V_5 -> V_17 , L_3 , V_16 ) ;
return V_16 ;
}
V_16 = F_6 ( V_6 , V_28 ,
F_9 ( V_24 ) * 512 , V_20 ) ;
if ( V_16 < 0 ) {
F_4 ( V_5 -> V_17 , L_2 , V_16 ) ;
return V_16 ;
}
return 0 ;
}
static int F_10 ( struct V_4 * V_29 )
{
int V_16 ;
int V_30 ;
struct V_31 * V_32 = V_29 -> V_32 ;
struct V_1 * V_6 = V_29 -> V_6 ;
struct V_33 * V_34 = F_11 ( V_29 -> V_3 ) ;
F_12 ( V_32 ,
V_35 |
V_36 |
V_37 |
V_38 ,
V_39 ) ;
V_16 = F_13 ( V_6 , 0xF , 0xF , 4 , 24 ) ;
if ( V_16 < 0 ) {
F_4 ( V_29 -> V_17 , L_4 , V_16 ) ;
return V_16 ;
}
if ( V_34 -> V_40 -> V_41 == V_42 )
V_30 = V_43 | V_44 |
V_45 | V_46 |
V_47 | V_48 ;
else
V_30 = V_43 | V_44 ;
V_16 = F_14 ( V_29 -> V_3 , L_5 ,
V_30 , & V_34 -> V_49 ,
V_50 , F_15 ( V_50 ) ) ;
if ( V_16 ) {
F_4 ( V_29 -> V_17 , L_6 , V_16 ) ;
return V_16 ;
}
F_16 ( V_32 , & V_34 -> V_49 , & V_34 -> V_49 , & V_34 -> V_49 ) ;
return V_16 ;
}
static int F_17 ( struct V_4 * V_5 ,
struct V_23 * V_24 )
{
struct V_51 * V_52 = F_18 ( V_24 ,
V_53 ) ;
struct V_51 * V_54 = F_18 ( V_24 ,
V_55 ) ;
V_52 -> V_56 = V_52 -> V_57 = 48000 ;
V_54 -> V_56 = V_54 -> V_57 = 2 ;
F_19 ( V_24 , V_58 ) ;
return 0 ;
}
static int F_20 ( struct V_21 * V_22 )
{
return F_21 ( V_22 -> V_29 ,
V_53 , 48000 ) ;
}
static int F_22 ( struct V_59 * V_60 )
{
int V_61 = 0 ;
int V_62 ;
struct V_33 * V_63 ;
struct V_2 * V_3 = V_64 [ 0 ] . V_65 ;
char V_66 [ 16 ] ;
struct V_67 * V_68 ;
const char * V_69 = NULL ;
int V_70 = 0 ;
V_63 = F_23 ( & V_60 -> V_17 , sizeof( * V_63 ) , V_71 ) ;
if ( ! V_63 )
return - V_72 ;
for ( V_62 = 0 ; V_62 < F_15 ( V_64 ) ; V_62 ++ ) {
if ( F_24 ( V_64 [ V_62 ] . V_73 ) ) {
F_25 ( & V_60 -> V_17 ,
L_7 , V_64 [ V_62 ] . V_73 ) ;
V_3 = V_64 [ V_62 ] . V_65 ;
V_63 -> V_40 = & V_64 [ V_62 ] ;
break;
}
}
V_3 -> V_17 = & V_60 -> V_17 ;
V_68 = V_3 -> V_17 -> V_74 ;
sprintf ( V_66 , L_8 , V_63 -> V_40 -> V_73 ) ;
for ( V_62 = 0 ; V_62 < F_15 ( V_75 ) ; V_62 ++ )
if ( ! strcmp ( V_3 -> V_76 [ V_62 ] . V_66 , L_9 ) ) {
V_3 -> V_76 [ V_62 ] . V_66 = F_26 ( V_66 , V_77 ) ;
V_70 = V_62 ;
}
V_69 = F_27 ( V_68 -> V_78 ) ;
if ( V_69 != NULL ) {
snprintf ( V_79 , sizeof( V_79 ) ,
L_10 , L_11 , V_69 ) ;
V_75 [ V_70 ] . V_66 = V_79 ;
}
F_28 ( V_3 , V_63 ) ;
V_61 = F_29 ( & V_60 -> V_17 , V_3 ) ;
if ( V_61 ) {
F_4 ( & V_60 -> V_17 ,
L_12 , V_61 ) ;
return V_61 ;
}
F_30 ( V_60 , V_3 ) ;
return V_61 ;
}
