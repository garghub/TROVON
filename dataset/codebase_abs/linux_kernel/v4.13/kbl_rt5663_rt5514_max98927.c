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
V_8 = F_7 ( & V_15 , L_3 ,
V_16 | V_17 | V_18 |
V_19 | V_20 , & V_11 -> V_21 ,
NULL , 0 ) ;
if ( V_8 ) {
F_4 ( V_2 -> V_9 , L_4 , V_8 ) ;
return V_8 ;
}
F_8 ( V_14 , & V_11 -> V_21 ) ;
V_8 = F_3 ( & V_2 -> V_12 -> V_4 , L_5 ) ;
if ( V_8 )
F_4 ( V_2 -> V_9 , L_6 , V_8 ) ;
return V_8 ;
}
static int F_9 ( struct V_1 * V_2 , int V_22 )
{
struct V_10 * V_11 = F_6 ( V_2 -> V_12 ) ;
struct V_23 * V_24 = V_2 -> V_25 ;
struct V_26 * V_27 ;
V_27 = F_10 ( V_2 -> V_12 -> V_9 , sizeof( * V_27 ) , V_28 ) ;
if ( ! V_27 )
return - V_29 ;
V_27 -> V_22 = V_22 ;
V_27 -> V_25 = V_24 ;
F_11 ( & V_27 -> V_30 , & V_11 -> V_31 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
return F_9 ( V_2 , V_32 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
return F_9 ( V_2 , V_33 ) ;
}
static int F_14 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = V_35 -> V_37 ;
V_37 -> V_38 . V_39 = 2 ;
F_15 ( V_37 , 0 , V_40 ,
& V_41 ) ;
V_37 -> V_38 . V_42 = V_43 ;
F_16 ( V_37 , 0 , 16 , 16 ) ;
F_15 ( V_37 , 0 ,
V_44 , & V_45 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_46 * V_47 )
{
struct V_48 * V_49 = F_18 ( V_47 ,
V_44 ) ;
struct V_48 * V_50 = F_18 ( V_47 ,
V_40 ) ;
struct V_51 * V_52 = F_19 ( V_47 , V_53 ) ;
struct V_54 * V_55 = F_20 (
V_47 , struct V_54 , V_56 ) ;
struct V_57 * V_58 = V_55 -> V_59 -> V_60 ;
struct V_57 * V_61 = V_55 -> V_62 -> V_60 ;
if ( ! strcmp ( V_58 -> V_63 , L_7 ) ||
! strcmp ( V_58 -> V_63 , L_8 ) ) {
V_49 -> V_64 = V_49 -> V_65 = 48000 ;
V_50 -> V_64 = V_50 -> V_65 = 2 ;
F_21 ( V_52 ) ;
F_22 ( V_52 , V_66 ) ;
} else if ( ! strcmp ( V_58 -> V_63 , L_9 ) ) {
if ( F_23 ( V_47 ) == 2 ||
F_24 ( V_67 ) == 2 )
V_50 -> V_64 = V_50 -> V_65 = 2 ;
else
V_50 -> V_64 = V_50 -> V_65 = 4 ;
}
if ( ! strcmp ( V_61 -> V_63 , L_10 ) )
F_22 ( V_52 , V_68 ) ;
return 0 ;
}
static int F_25 ( struct V_34 * V_35 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = V_35 -> V_69 ;
struct V_23 * V_25 = V_2 -> V_25 ;
int V_8 ;
F_26 ( V_25 -> V_14 ,
V_70 | V_71 ,
V_72 ) ;
V_8 = F_27 ( V_25 ,
V_73 , 24576000 , V_74 ) ;
if ( V_8 < 0 )
F_4 ( V_2 -> V_9 , L_11 , V_8 ) ;
return V_8 ;
}
static int F_28 ( struct V_34 * V_35 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = V_35 -> V_69 ;
int V_8 = 0 , V_75 ;
for ( V_75 = 0 ; V_75 < V_2 -> V_76 ; V_75 ++ ) {
struct V_23 * V_25 = V_2 -> V_77 [ V_75 ] ;
if ( ! strcmp ( V_25 -> V_6 -> V_63 , V_78 ) ) {
V_8 = F_29 ( V_25 , 0xF , 0 , 8 , 16 ) ;
if ( V_8 < 0 ) {
F_4 ( V_2 -> V_9 , L_12 , V_8 ) ;
return V_8 ;
}
V_8 = F_27 ( V_25 ,
V_79 , 24576000 , V_74 ) ;
if ( V_8 < 0 ) {
F_4 ( V_2 -> V_9 , L_13 , V_8 ) ;
return V_8 ;
}
}
if ( ! strcmp ( V_25 -> V_6 -> V_63 , V_80 ) ||
! strcmp ( V_25 -> V_6 -> V_63 , V_81 ) ) {
V_8 = F_29 ( V_25 , 0xF0 , 3 , 8 , 16 ) ;
if ( V_8 < 0 ) {
F_4 ( V_2 -> V_9 , L_12 , V_8 ) ;
return V_8 ;
}
}
}
return V_8 ;
}
static int F_30 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = V_35 -> V_37 ;
V_37 -> V_38 . V_39 = F_24 ( V_67 ) ;
F_15 ( V_37 , 0 , V_40 ,
V_67 ) ;
return F_15 ( V_35 -> V_37 , 0 ,
V_44 , & V_45 ) ;
}
static int F_31 ( struct V_82 * V_12 )
{
struct V_10 * V_11 = F_6 ( V_12 ) ;
struct V_26 * V_27 ;
int V_83 , V_84 = 0 ;
char V_85 [ V_86 ] ;
F_32 (pcm, &ctx->hdmi_pcm_list, head) {
V_83 = F_7 ( V_12 , V_85 ,
V_87 , & V_11 -> V_88 [ V_84 ] ,
NULL , 0 ) ;
if ( V_83 )
return V_83 ;
V_83 = F_33 ( V_27 -> V_25 , V_27 -> V_22 ,
& V_11 -> V_88 [ V_84 ] ) ;
if ( V_83 < 0 )
return V_83 ;
V_84 ++ ;
}
return 0 ;
}
static int F_34 ( struct V_89 * V_90 )
{
struct V_10 * V_11 ;
struct V_91 * V_92 ;
V_11 = F_10 ( & V_90 -> V_9 , sizeof( * V_11 ) , V_93 ) ;
if ( ! V_11 )
return - V_29 ;
F_35 ( & V_11 -> V_31 ) ;
V_15 . V_9 = & V_90 -> V_9 ;
F_36 ( & V_15 , V_11 ) ;
V_92 = F_37 ( & V_90 -> V_9 ) ;
if ( V_92 )
V_67 = V_92 -> V_94 == 2 ?
& V_95 : & V_96 ;
return F_38 ( & V_90 -> V_9 , & V_15 ) ;
}
