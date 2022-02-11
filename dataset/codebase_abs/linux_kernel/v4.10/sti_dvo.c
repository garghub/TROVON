static int F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_2 * V_4 )
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
static void F_6 ( struct V_40 * V_41 , void T_3 * V_42 )
{
unsigned int V_34 ;
F_7 ( V_41 , L_3 ) ;
F_7 ( V_41 , L_4 ) ;
for ( V_34 = 0 ; V_34 < V_37 ; V_34 ++ ) {
if ( V_34 % 8 == 0 )
F_8 ( V_41 , L_5 , V_34 ) ;
F_8 ( V_41 , L_6 , F_9 ( V_42 + V_34 * 4 ) ) ;
}
}
static int F_10 ( struct V_40 * V_41 , void * V_43 )
{
struct V_44 * V_45 = V_41 -> V_46 ;
struct V_1 * V_2 = (struct V_1 * ) V_45 -> V_47 -> V_43 ;
F_8 ( V_41 , L_7 , V_2 -> V_35 ) ;
F_11 ( V_39 ) ;
F_11 ( V_48 ) ;
F_11 ( V_49 ) ;
F_11 ( V_50 ) ;
F_11 ( V_51 ) ;
F_6 ( V_41 , V_2 -> V_35 + V_36 ) ;
F_7 ( V_41 , L_2 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 , struct V_52 * V_53 )
{
F_13 ( V_54 ,
F_14 ( V_54 ) ,
V_53 ) ;
}
static int F_15 ( struct V_1 * V_2 , struct V_52 * V_53 )
{
unsigned int V_34 ;
for ( V_34 = 0 ; V_34 < F_14 ( V_54 ) ; V_34 ++ )
V_54 [ V_34 ] . V_43 = V_2 ;
return F_16 ( V_54 ,
F_14 ( V_54 ) ,
V_53 -> V_55 , V_53 ) ;
}
static void F_17 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = V_57 -> V_58 ;
if ( ! V_2 -> V_59 )
return;
F_4 ( L_2 ) ;
if ( V_2 -> V_8 -> V_30 )
F_5 ( 0x00000000 , V_2 -> V_35 + V_39 ) ;
F_5 ( 0x00000000 , V_2 -> V_35 + V_48 ) ;
if ( V_2 -> V_60 )
V_2 -> V_60 -> V_61 -> V_62 ( V_2 -> V_60 ) ;
F_18 ( V_2 -> V_63 ) ;
F_18 ( V_2 -> V_64 ) ;
V_2 -> V_59 = false ;
}
static void F_19 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = V_57 -> V_58 ;
struct V_7 * V_8 = V_2 -> V_8 ;
T_2 V_65 ;
F_4 ( L_2 ) ;
if ( V_2 -> V_59 )
return;
F_5 ( 0x00000000 , V_2 -> V_35 + V_48 ) ;
F_5 ( 0x00000000 , V_2 -> V_35 + V_39 ) ;
if ( V_8 -> V_30 ) {
T_1 V_66 ;
T_2 V_32 [ V_37 ] ;
if ( ! F_1 ( V_2 , & V_66 , V_32 ) )
F_3 ( V_2 , V_32 , V_66 ) ;
else
return;
}
if ( F_20 ( V_2 -> V_63 ) )
F_2 ( L_8 ) ;
if ( F_20 ( V_2 -> V_64 ) )
F_2 ( L_9 ) ;
if ( V_2 -> V_60 )
V_2 -> V_60 -> V_61 -> V_67 ( V_2 -> V_60 ) ;
F_5 ( V_8 -> V_68 , V_2 -> V_35 + V_49 ) ;
F_5 ( V_8 -> V_69 , V_2 -> V_35 + V_50 ) ;
F_5 ( V_8 -> V_70 , V_2 -> V_35 + V_51 ) ;
V_65 = ( V_8 -> V_71 | V_72 ) ;
F_5 ( V_65 , V_2 -> V_35 + V_48 ) ;
V_2 -> V_59 = true ;
}
static void F_21 ( struct V_56 * V_57 ,
struct V_5 * V_6 ,
struct V_5 * V_73 )
{
struct V_1 * V_2 = V_57 -> V_58 ;
struct V_74 * V_75 = F_22 ( V_2 -> V_76 -> V_77 ) ;
int V_78 = V_6 -> clock * 1000 ;
struct V_64 * V_79 ;
int V_80 ;
F_4 ( L_2 ) ;
memcpy ( & V_2 -> V_6 , V_6 , sizeof( struct V_5 ) ) ;
if ( V_75 -> V_81 == V_82 )
V_79 = V_2 -> V_83 ;
else
V_79 = V_2 -> V_84 ;
if ( V_79 ) {
F_23 ( V_2 -> V_63 , V_79 ) ;
F_23 ( V_2 -> V_64 , V_79 ) ;
}
V_80 = F_24 ( V_2 -> V_63 , V_78 ) ;
if ( V_80 < 0 ) {
F_2 ( L_10 , V_78 ) ;
return;
}
V_80 = F_24 ( V_2 -> V_64 , V_78 ) ;
if ( V_80 < 0 ) {
F_2 ( L_11 , V_78 ) ;
return;
}
V_2 -> V_8 = & V_85 ;
}
static void F_25 ( struct V_56 * V_57 )
{
}
static int F_26 ( struct V_86 * V_87 )
{
struct V_88 * V_89
= F_27 ( V_87 ) ;
struct V_1 * V_2 = V_89 -> V_2 ;
if ( V_2 -> V_60 )
return V_2 -> V_60 -> V_61 -> V_90 ( V_2 -> V_60 ) ;
return 0 ;
}
static int F_28 ( struct V_86 * V_87 ,
struct V_5 * V_6 )
{
int V_91 = V_6 -> clock * 1000 ;
int V_92 = V_91 - V_93 ;
int V_94 = V_91 + V_93 ;
int V_95 ;
struct V_88 * V_89
= F_27 ( V_87 ) ;
struct V_1 * V_2 = V_89 -> V_2 ;
V_95 = F_29 ( V_2 -> V_63 , V_91 ) ;
F_4 ( L_12 ,
V_91 , V_95 ) ;
if ( ( V_95 < V_92 ) || ( V_95 > V_94 ) ) {
F_4 ( L_13 , V_91 ) ;
return V_96 ;
}
return V_97 ;
}
static enum V_98
F_30 ( struct V_86 * V_87 , bool V_99 )
{
struct V_88 * V_89
= F_27 ( V_87 ) ;
struct V_1 * V_2 = V_89 -> V_2 ;
F_4 ( L_2 ) ;
if ( ! V_2 -> V_60 ) {
V_2 -> V_60 = F_31 ( V_2 -> V_100 ) ;
if ( V_2 -> V_60 )
F_32 ( V_2 -> V_60 , V_87 ) ;
}
if ( V_2 -> V_60 )
return V_101 ;
return V_102 ;
}
static int F_33 ( struct V_86 * V_87 )
{
struct V_88 * V_89
= F_27 ( V_87 ) ;
struct V_1 * V_2 = V_89 -> V_2 ;
if ( F_15 ( V_2 , V_2 -> V_103 -> V_104 ) ) {
F_2 ( L_14 ) ;
return - V_31 ;
}
return 0 ;
}
static struct V_105 * F_34 ( struct V_106 * V_107 )
{
struct V_105 * V_76 ;
F_35 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_76 -> V_108 == V_109 )
return V_76 ;
}
return NULL ;
}
static int F_36 ( struct V_110 * V_107 , struct V_110 * V_111 , void * V_43 )
{
struct V_1 * V_2 = F_37 ( V_107 ) ;
struct V_106 * V_103 = V_43 ;
struct V_105 * V_76 ;
struct V_88 * V_87 ;
struct V_86 * V_86 ;
struct V_56 * V_57 ;
int V_112 ;
V_2 -> V_103 = V_103 ;
V_76 = F_34 ( V_103 ) ;
if ( ! V_76 )
return - V_113 ;
V_87 = F_38 ( V_107 , sizeof( * V_87 ) , V_114 ) ;
if ( ! V_87 )
return - V_113 ;
V_87 -> V_2 = V_2 ;
V_57 = F_38 ( V_107 , sizeof( * V_57 ) , V_114 ) ;
if ( ! V_57 )
return - V_113 ;
V_57 -> V_58 = V_2 ;
V_57 -> V_61 = & V_115 ;
V_57 -> V_116 = V_2 -> V_107 . V_116 ;
V_112 = F_39 ( V_57 ) ;
if ( V_112 ) {
F_2 ( L_15 ) ;
return V_112 ;
}
V_112 = F_40 ( V_103 , V_57 ) ;
if ( V_112 ) {
F_2 ( L_16 ) ;
return V_112 ;
}
V_2 -> V_57 = V_57 ;
V_76 -> V_57 = V_57 ;
V_87 -> V_76 = V_76 ;
V_2 -> V_76 = V_76 ;
V_86 = (struct V_86 * ) V_87 ;
V_86 -> V_117 = V_118 ;
F_41 ( V_103 , V_86 ,
& V_119 , V_120 ) ;
F_42 ( V_86 ,
& V_121 ) ;
V_112 = F_43 ( V_86 , V_76 ) ;
if ( V_112 ) {
F_2 ( L_17 ) ;
goto V_122;
}
return 0 ;
V_122:
F_44 ( V_57 ) ;
return - V_31 ;
}
static void F_45 ( struct V_110 * V_107 ,
struct V_110 * V_111 , void * V_43 )
{
struct V_1 * V_2 = F_37 ( V_107 ) ;
struct V_106 * V_103 = V_43 ;
F_12 ( V_2 , V_103 -> V_104 ) ;
F_44 ( V_2 -> V_57 ) ;
}
static int F_46 ( struct V_123 * V_124 )
{
struct V_110 * V_107 = & V_124 -> V_107 ;
struct V_1 * V_2 ;
struct V_125 * V_126 ;
struct V_127 * V_128 = V_107 -> V_116 ;
F_47 ( L_18 , V_129 ) ;
V_2 = F_38 ( V_107 , sizeof( * V_2 ) , V_114 ) ;
if ( ! V_2 ) {
F_2 ( L_19 ) ;
return - V_113 ;
}
V_2 -> V_107 = V_124 -> V_107 ;
V_126 = F_48 ( V_124 , V_130 , L_20 ) ;
if ( ! V_126 ) {
F_2 ( L_21 ) ;
return - V_113 ;
}
V_2 -> V_35 = F_49 ( V_107 , V_126 -> V_131 ,
F_50 ( V_126 ) ) ;
if ( ! V_2 -> V_35 )
return - V_113 ;
V_2 -> V_63 = F_51 ( V_107 , L_22 ) ;
if ( F_52 ( V_2 -> V_63 ) ) {
F_2 ( L_23 ) ;
return F_53 ( V_2 -> V_63 ) ;
}
V_2 -> V_64 = F_51 ( V_107 , L_24 ) ;
if ( F_52 ( V_2 -> V_64 ) ) {
F_2 ( L_25 ) ;
return F_53 ( V_2 -> V_64 ) ;
}
V_2 -> V_83 = F_51 ( V_107 , L_26 ) ;
if ( F_52 ( V_2 -> V_83 ) ) {
F_4 ( L_27 ) ;
V_2 -> V_83 = NULL ;
}
V_2 -> V_84 = F_51 ( V_107 , L_28 ) ;
if ( F_52 ( V_2 -> V_84 ) ) {
F_4 ( L_29 ) ;
V_2 -> V_84 = NULL ;
}
V_2 -> V_100 = F_54 ( V_128 , L_30 , 0 ) ;
if ( ! V_2 -> V_100 )
F_2 ( L_31 ) ;
F_55 ( V_2 -> V_100 ) ;
F_56 ( V_124 , V_2 ) ;
return F_57 ( & V_124 -> V_107 , & V_132 ) ;
}
static int F_58 ( struct V_123 * V_124 )
{
F_59 ( & V_124 -> V_107 , & V_132 ) ;
return 0 ;
}
