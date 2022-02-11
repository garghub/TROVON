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
NULL , 0 ) ;
if ( V_16 ) {
F_4 ( V_29 -> V_17 , L_6 , V_16 ) ;
return V_16 ;
}
F_15 ( V_32 , & V_34 -> V_49 , & V_34 -> V_49 , & V_34 -> V_49 ) ;
return V_16 ;
}
static int F_16 ( struct V_4 * V_5 ,
struct V_23 * V_24 )
{
struct V_50 * V_51 = F_17 ( V_24 ,
V_52 ) ;
struct V_50 * V_53 = F_17 ( V_24 ,
V_54 ) ;
V_51 -> V_55 = V_51 -> V_56 = 48000 ;
V_53 -> V_55 = V_53 -> V_56 = 2 ;
F_18 ( V_24 , V_57 ) ;
return 0 ;
}
static int F_19 ( struct V_21 * V_22 )
{
return F_20 ( V_22 -> V_29 ,
V_52 , 48000 ) ;
}
static T_1 F_21 ( T_2 V_58 , T_3 V_59 ,
void * V_60 , void * * V_16 )
{
* ( bool * ) V_60 = true ;
return V_61 ;
}
static int F_22 ( struct V_62 * V_63 )
{
int V_64 = 0 ;
int V_65 ;
struct V_33 * V_66 ;
struct V_2 * V_3 = V_67 [ 0 ] . V_68 ;
bool V_69 = false ;
char V_70 [ 16 ] ;
V_66 = F_23 ( & V_63 -> V_17 , sizeof( * V_66 ) , V_71 ) ;
if ( ! V_66 )
return - V_72 ;
for ( V_65 = 0 ; V_65 < F_24 ( V_67 ) ; V_65 ++ ) {
if ( F_25 ( F_26 (
V_67 [ V_65 ] . V_73 ,
F_21 ,
& V_69 , NULL ) ) && V_69 ) {
F_27 ( & V_63 -> V_17 ,
L_7 , V_67 [ V_65 ] . V_73 ) ;
V_3 = V_67 [ V_65 ] . V_68 ;
V_66 -> V_40 = & V_67 [ V_65 ] ;
break;
}
}
V_3 -> V_17 = & V_63 -> V_17 ;
sprintf ( V_70 , L_8 , V_66 -> V_40 -> V_73 ) ;
for ( V_65 = 0 ; V_65 < F_24 ( V_74 ) ; V_65 ++ )
if ( ! strcmp ( V_3 -> V_75 [ V_65 ] . V_70 , L_9 ) )
V_3 -> V_75 [ V_65 ] . V_70 = F_28 ( V_70 , V_76 ) ;
F_29 ( V_3 , V_66 ) ;
V_64 = F_30 ( & V_63 -> V_17 , V_3 ) ;
if ( V_64 ) {
F_4 ( & V_63 -> V_17 ,
L_10 , V_64 ) ;
return V_64 ;
}
F_31 ( V_63 , V_3 ) ;
return V_64 ;
}
