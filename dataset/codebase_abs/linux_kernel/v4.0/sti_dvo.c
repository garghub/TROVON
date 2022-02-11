int F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_2 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_9 V_10 ;
struct V_11 V_12 ;
V_10 . V_4 = V_4 ;
V_10 . V_13 = 0 ;
V_12 . V_14 = V_6 -> V_15 ;
V_12 . V_16 = V_6 -> V_17 ;
V_12 . V_18 = V_6 -> V_19 - V_6 -> V_17 ;
V_12 . V_20 = V_6 -> V_15 - V_6 -> V_19 ;
V_12 . V_21 = V_6 -> V_22 ;
V_12 . V_23 = V_6 -> V_24 ;
V_12 . V_25 = V_6 -> V_26 - V_6 -> V_24 ;
V_12 . V_27 = V_6 -> V_22 - V_6 -> V_26 ;
V_12 . V_28 = V_29 ;
if ( V_8 -> V_30 ( & V_10 , & V_12 ) ) {
F_2 ( L_1 ) ;
return - V_31 ;
}
* V_3 = V_10 . V_13 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 , T_2 * V_32 , int V_33 )
{
int V_34 ;
F_4 ( L_2 ) ;
for ( V_34 = 0 ; V_34 < V_33 ; V_34 ++ )
F_5 ( V_32 [ V_34 ] ,
V_2 -> V_35 + V_36 + V_34 * 4 ) ;
for ( V_34 = V_33 ; V_34 < V_37 ; V_34 ++ )
F_5 ( 0 , V_2 -> V_35 + V_36 + V_34 * 4 ) ;
F_5 ( V_38 , V_2 -> V_35 + V_39 ) ;
}
static void F_6 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
if ( ! V_2 -> V_43 )
return;
F_4 ( L_2 ) ;
if ( V_2 -> V_8 -> V_30 )
F_5 ( 0x00000000 , V_2 -> V_35 + V_39 ) ;
F_5 ( 0x00000000 , V_2 -> V_35 + V_44 ) ;
if ( V_2 -> V_45 )
V_2 -> V_45 -> V_46 -> V_47 ( V_2 -> V_45 ) ;
F_7 ( V_2 -> V_48 ) ;
F_7 ( V_2 -> V_49 ) ;
V_2 -> V_43 = false ;
}
static void F_8 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
struct V_7 * V_8 = V_2 -> V_8 ;
T_2 V_50 ;
F_4 ( L_2 ) ;
if ( V_2 -> V_43 )
return;
F_5 ( 0x00000000 , V_2 -> V_35 + V_44 ) ;
F_5 ( 0x00000000 , V_2 -> V_35 + V_39 ) ;
if ( V_8 -> V_30 ) {
T_1 V_51 ;
T_2 V_32 [ V_37 ] ;
if ( ! F_1 ( V_2 , & V_51 , V_32 ) )
F_3 ( V_2 , V_32 , V_51 ) ;
else
return;
}
if ( F_9 ( V_2 -> V_48 ) )
F_2 ( L_3 ) ;
if ( F_9 ( V_2 -> V_49 ) )
F_2 ( L_4 ) ;
if ( V_2 -> V_45 )
V_2 -> V_45 -> V_46 -> V_52 ( V_2 -> V_45 ) ;
F_5 ( V_8 -> V_53 , V_2 -> V_35 + V_54 ) ;
F_5 ( V_8 -> V_55 , V_2 -> V_35 + V_56 ) ;
F_5 ( V_8 -> V_57 , V_2 -> V_35 + V_58 ) ;
V_50 = ( V_8 -> V_59 | V_60 ) ;
F_5 ( V_50 , V_2 -> V_35 + V_44 ) ;
V_2 -> V_43 = true ;
}
static void F_10 ( struct V_40 * V_41 ,
struct V_5 * V_6 ,
struct V_5 * V_61 )
{
struct V_1 * V_2 = V_41 -> V_42 ;
struct V_62 * V_63 = F_11 ( V_2 -> V_64 -> V_65 ) ;
int V_66 = V_6 -> clock * 1000 ;
struct V_49 * V_67 ;
int V_68 ;
F_4 ( L_2 ) ;
memcpy ( & V_2 -> V_6 , V_6 , sizeof( struct V_5 ) ) ;
if ( V_63 -> V_69 == V_70 )
V_67 = V_2 -> V_71 ;
else
V_67 = V_2 -> V_72 ;
if ( V_67 ) {
F_12 ( V_2 -> V_48 , V_67 ) ;
F_12 ( V_2 -> V_49 , V_67 ) ;
}
V_68 = F_13 ( V_2 -> V_48 , V_66 ) ;
if ( V_68 < 0 ) {
F_2 ( L_5 , V_66 ) ;
return;
}
V_68 = F_13 ( V_2 -> V_49 , V_66 ) ;
if ( V_68 < 0 ) {
F_2 ( L_6 , V_66 ) ;
return;
}
V_2 -> V_8 = & V_73 ;
}
static void F_14 ( struct V_40 * V_41 )
{
}
static int F_15 ( struct V_74 * V_75 )
{
struct V_76 * V_77
= F_16 ( V_75 ) ;
struct V_1 * V_2 = V_77 -> V_2 ;
if ( V_2 -> V_45 )
return V_2 -> V_45 -> V_46 -> V_78 ( V_2 -> V_45 ) ;
return 0 ;
}
static int F_17 ( struct V_74 * V_75 ,
struct V_5 * V_6 )
{
int V_79 = V_6 -> clock * 1000 ;
int V_80 = V_79 - V_81 ;
int V_82 = V_79 + V_81 ;
int V_83 ;
struct V_76 * V_77
= F_16 ( V_75 ) ;
struct V_1 * V_2 = V_77 -> V_2 ;
V_83 = F_18 ( V_2 -> V_48 , V_79 ) ;
F_4 ( L_7 ,
V_79 , V_83 ) ;
if ( ( V_83 < V_80 ) || ( V_83 > V_82 ) ) {
F_4 ( L_8 , V_79 ) ;
return V_84 ;
}
return V_85 ;
}
struct V_86 * F_19 ( struct V_74 * V_75 )
{
struct V_76 * V_77
= F_16 ( V_75 ) ;
return V_77 -> V_64 ;
}
static enum V_87
F_20 ( struct V_74 * V_75 , bool V_88 )
{
struct V_76 * V_77
= F_16 ( V_75 ) ;
struct V_1 * V_2 = V_77 -> V_2 ;
F_4 ( L_2 ) ;
if ( ! V_2 -> V_45 )
V_2 -> V_45 = F_21 ( V_2 -> V_89 ) ;
if ( V_2 -> V_45 )
if ( ! F_22 ( V_2 -> V_45 , V_75 ) )
return V_90 ;
return V_91 ;
}
static void F_23 ( struct V_74 * V_75 )
{
struct V_76 * V_77
= F_16 ( V_75 ) ;
F_24 ( V_75 ) ;
F_25 ( V_75 ) ;
F_26 ( V_77 ) ;
}
static struct V_86 * F_27 ( struct V_92 * V_93 )
{
struct V_86 * V_64 ;
F_28 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_64 -> V_94 == V_95 )
return V_64 ;
}
return NULL ;
}
static int F_29 ( struct V_96 * V_93 , struct V_96 * V_97 , void * V_98 )
{
struct V_1 * V_2 = F_30 ( V_93 ) ;
struct V_92 * V_99 = V_98 ;
struct V_86 * V_64 ;
struct V_76 * V_75 ;
struct V_74 * V_74 ;
struct V_40 * V_41 ;
int V_100 ;
V_2 -> V_99 = V_99 ;
V_64 = F_27 ( V_99 ) ;
if ( ! V_64 )
return - V_101 ;
V_75 = F_31 ( V_93 , sizeof( * V_75 ) , V_102 ) ;
if ( ! V_75 )
return - V_101 ;
V_75 -> V_2 = V_2 ;
V_41 = F_31 ( V_93 , sizeof( * V_41 ) , V_102 ) ;
if ( ! V_41 )
return - V_101 ;
V_41 -> V_42 = V_2 ;
V_41 -> V_46 = & V_103 ;
V_41 -> V_104 = V_2 -> V_93 . V_104 ;
V_100 = F_32 ( V_41 ) ;
if ( V_100 ) {
F_2 ( L_9 ) ;
return V_100 ;
}
V_100 = F_33 ( V_99 , V_41 ) ;
if ( V_100 ) {
F_2 ( L_10 ) ;
return V_100 ;
}
V_2 -> V_41 = V_41 ;
V_64 -> V_41 = V_41 ;
V_75 -> V_64 = V_64 ;
V_2 -> V_64 = V_64 ;
V_74 = (struct V_74 * ) V_75 ;
V_74 -> V_105 = V_106 ;
F_34 ( V_99 , V_74 ,
& V_107 , V_108 ) ;
F_35 ( V_74 ,
& V_109 ) ;
V_100 = F_36 ( V_74 ) ;
if ( V_100 )
goto V_110;
V_100 = F_37 ( V_74 , V_64 ) ;
if ( V_100 ) {
F_2 ( L_11 ) ;
goto V_111;
}
return 0 ;
V_111:
F_24 ( V_74 ) ;
V_110:
F_38 ( V_41 ) ;
F_25 ( V_74 ) ;
return - V_31 ;
}
static void F_39 ( struct V_96 * V_93 ,
struct V_96 * V_97 , void * V_98 )
{
struct V_1 * V_2 = F_30 ( V_93 ) ;
F_38 ( V_2 -> V_41 ) ;
}
static int F_40 ( struct V_112 * V_113 )
{
struct V_96 * V_93 = & V_113 -> V_93 ;
struct V_1 * V_2 ;
struct V_114 * V_115 ;
struct V_116 * V_117 = V_93 -> V_104 ;
F_41 ( L_12 , V_118 ) ;
V_2 = F_31 ( V_93 , sizeof( * V_2 ) , V_102 ) ;
if ( ! V_2 ) {
F_2 ( L_13 ) ;
return - V_101 ;
}
V_2 -> V_93 = V_113 -> V_93 ;
V_115 = F_42 ( V_113 , V_119 , L_14 ) ;
if ( ! V_115 ) {
F_2 ( L_15 ) ;
return - V_101 ;
}
V_2 -> V_35 = F_43 ( V_93 , V_115 -> V_120 ,
F_44 ( V_115 ) ) ;
if ( F_45 ( V_2 -> V_35 ) )
return F_46 ( V_2 -> V_35 ) ;
V_2 -> V_48 = F_47 ( V_93 , L_16 ) ;
if ( F_45 ( V_2 -> V_48 ) ) {
F_2 ( L_17 ) ;
return F_46 ( V_2 -> V_48 ) ;
}
V_2 -> V_49 = F_47 ( V_93 , L_18 ) ;
if ( F_45 ( V_2 -> V_49 ) ) {
F_2 ( L_19 ) ;
return F_46 ( V_2 -> V_49 ) ;
}
V_2 -> V_71 = F_47 ( V_93 , L_20 ) ;
if ( F_45 ( V_2 -> V_71 ) ) {
F_4 ( L_21 ) ;
V_2 -> V_71 = NULL ;
}
V_2 -> V_72 = F_47 ( V_93 , L_22 ) ;
if ( F_45 ( V_2 -> V_72 ) ) {
F_4 ( L_23 ) ;
V_2 -> V_72 = NULL ;
}
V_2 -> V_89 = F_48 ( V_117 , L_24 , 0 ) ;
if ( ! V_2 -> V_89 )
F_2 ( L_25 ) ;
F_49 ( V_113 , V_2 ) ;
return F_50 ( & V_113 -> V_93 , & V_121 ) ;
}
static int F_51 ( struct V_112 * V_113 )
{
F_52 ( & V_113 -> V_93 , & V_121 ) ;
return 0 ;
}
