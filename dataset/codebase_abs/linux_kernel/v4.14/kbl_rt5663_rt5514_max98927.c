static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_7 -> V_6 ;
int V_8 ;
V_4 = F_2 ( V_6 ) ;
V_8 = F_3 ( V_4 , L_1 ) ;
if ( V_8 )
F_4 ( V_2 -> V_9 , L_2 , V_8 ) ;
return V_8 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_8 ;
struct V_10 * V_11 = F_6 ( V_2 -> V_12 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_15 * V_16 ;
V_8 = F_7 ( & V_17 , L_3 ,
V_18 | V_19 | V_20 |
V_21 | V_22 , & V_11 -> V_23 ,
NULL , 0 ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_9 , L_4 , V_8 ) ;
return V_8 ;
}
V_16 = & V_11 -> V_23 ;
F_8 ( V_16 -> V_16 , V_19 , V_24 ) ;
F_8 ( V_16 -> V_16 , V_20 , V_25 ) ;
F_8 ( V_16 -> V_16 , V_21 , V_26 ) ;
F_8 ( V_16 -> V_16 , V_22 , V_27 ) ;
F_9 ( V_14 , & V_11 -> V_23 ) ;
V_8 = F_3 ( & V_2 -> V_12 -> V_4 , L_5 ) ;
if ( V_8 )
F_4 ( V_2 -> V_9 , L_6 , V_8 ) ;
return V_8 ;
}
static int F_10 ( struct V_1 * V_2 , int V_28 )
{
struct V_10 * V_11 = F_6 ( V_2 -> V_12 ) ;
struct V_29 * V_30 = V_2 -> V_31 ;
struct V_32 * V_33 ;
V_33 = F_11 ( V_2 -> V_12 -> V_9 , sizeof( * V_33 ) , V_34 ) ;
if ( ! V_33 )
return - V_35 ;
V_33 -> V_28 = V_28 ;
V_33 -> V_31 = V_30 ;
F_12 ( & V_33 -> V_36 , & V_11 -> V_37 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return F_10 ( V_2 , V_38 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
return F_10 ( V_2 , V_39 ) ;
}
static int F_15 ( struct V_40 * V_41 )
{
struct V_42 * V_43 = V_41 -> V_43 ;
V_43 -> V_44 . V_45 = 2 ;
F_16 ( V_43 , 0 , V_46 ,
& V_47 ) ;
V_43 -> V_44 . V_48 = V_49 ;
F_17 ( V_43 , 0 , 16 , 16 ) ;
F_16 ( V_43 , 0 ,
V_50 , & V_51 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_54 * V_55 = F_19 ( V_53 ,
V_50 ) ;
struct V_54 * V_56 = F_19 ( V_53 ,
V_46 ) ;
struct V_57 * V_58 = F_20 ( V_53 , V_59 ) ;
struct V_60 * V_61 = F_21 (
V_53 , struct V_60 , V_62 ) ;
struct V_63 * V_64 = V_61 -> V_65 -> V_66 ;
struct V_63 * V_67 = V_61 -> V_68 -> V_66 ;
if ( ! strcmp ( V_64 -> V_69 , L_7 ) ||
! strcmp ( V_64 -> V_69 , L_8 ) ) {
V_55 -> V_70 = V_55 -> V_71 = 48000 ;
V_56 -> V_70 = V_56 -> V_71 = 2 ;
F_22 ( V_58 ) ;
F_23 ( V_58 , V_72 ) ;
} else if ( ! strcmp ( V_64 -> V_69 , L_9 ) ) {
if ( F_24 ( V_53 ) == 2 ||
F_25 ( V_73 ) == 2 )
V_56 -> V_70 = V_56 -> V_71 = 2 ;
else
V_56 -> V_70 = V_56 -> V_71 = 4 ;
}
if ( ! strcmp ( V_67 -> V_69 , L_10 ) )
F_23 ( V_58 , V_74 ) ;
return 0 ;
}
static int F_26 ( struct V_40 * V_41 ,
struct V_52 * V_53 )
{
struct V_1 * V_2 = V_41 -> V_75 ;
struct V_29 * V_31 = V_2 -> V_31 ;
int V_8 ;
F_27 ( V_31 -> V_14 ,
V_76 | V_77 ,
V_78 ) ;
V_8 = F_28 ( V_31 ,
V_79 , 24576000 , V_80 ) ;
if ( V_8 < 0 )
F_4 ( V_2 -> V_9 , L_11 , V_8 ) ;
return V_8 ;
}
static int F_29 ( struct V_40 * V_41 ,
struct V_52 * V_53 )
{
struct V_1 * V_2 = V_41 -> V_75 ;
int V_8 = 0 , V_81 ;
for ( V_81 = 0 ; V_81 < V_2 -> V_82 ; V_81 ++ ) {
struct V_29 * V_31 = V_2 -> V_83 [ V_81 ] ;
if ( ! strcmp ( V_31 -> V_6 -> V_69 , V_84 ) ) {
V_8 = F_30 ( V_31 , 0xF , 0 , 8 , 16 ) ;
if ( V_8 < 0 ) {
F_4 ( V_2 -> V_9 , L_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_28 ( V_31 ,
V_85 , 24576000 , V_80 ) ;
if ( V_8 < 0 ) {
F_4 ( V_2 -> V_9 , L_13 , V_8 ) ;
return V_8 ;
}
}
if ( ! strcmp ( V_31 -> V_6 -> V_69 , V_86 ) ) {
V_8 = F_30 ( V_31 , 0x30 , 3 , 8 , 16 ) ;
if ( V_8 < 0 ) {
F_4 ( V_2 -> V_9 , L_14 , V_8 ) ;
return V_8 ;
}
}
if ( ! strcmp ( V_31 -> V_6 -> V_69 , V_87 ) ) {
V_8 = F_30 ( V_31 , 0xC0 , 3 , 8 , 16 ) ;
if ( V_8 < 0 ) {
F_4 ( V_2 -> V_9 , L_15 , V_8 ) ;
return V_8 ;
}
}
}
return V_8 ;
}
static int F_31 ( struct V_40 * V_41 )
{
struct V_42 * V_43 = V_41 -> V_43 ;
V_43 -> V_44 . V_45 = F_25 ( V_73 ) ;
F_16 ( V_43 , 0 , V_46 ,
V_73 ) ;
return F_16 ( V_41 -> V_43 , 0 ,
V_50 , & V_51 ) ;
}
static int F_32 ( struct V_88 * V_12 )
{
struct V_10 * V_11 = F_6 ( V_12 ) ;
struct V_32 * V_33 ;
struct V_13 * V_14 = NULL ;
int V_89 , V_90 = 0 ;
char V_91 [ V_92 ] ;
F_33 (pcm, &ctx->hdmi_pcm_list, head) {
V_14 = V_33 -> V_31 -> V_14 ;
V_89 = F_7 ( V_12 , V_91 ,
V_93 , & V_11 -> V_94 [ V_90 ] ,
NULL , 0 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_34 ( V_33 -> V_31 , V_33 -> V_28 ,
& V_11 -> V_94 [ V_90 ] ) ;
if ( V_89 < 0 )
return V_89 ;
V_90 ++ ;
}
if ( ! V_14 )
return - V_95 ;
return F_35 ( V_14 , & V_12 -> V_4 ) ;
}
static int F_36 ( struct V_96 * V_97 )
{
struct V_10 * V_11 ;
struct V_98 * V_99 ;
V_11 = F_11 ( & V_97 -> V_9 , sizeof( * V_11 ) , V_100 ) ;
if ( ! V_11 )
return - V_35 ;
F_37 ( & V_11 -> V_37 ) ;
V_17 . V_9 = & V_97 -> V_9 ;
F_38 ( & V_17 , V_11 ) ;
V_99 = F_39 ( & V_97 -> V_9 ) ;
if ( V_99 )
V_73 = V_99 -> V_101 == 2 ?
& V_102 : & V_103 ;
return F_40 ( & V_97 -> V_9 , & V_17 ) ;
}
