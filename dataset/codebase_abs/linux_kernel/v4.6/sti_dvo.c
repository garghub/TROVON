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
struct V_48 * V_49 = V_45 -> V_50 -> V_49 ;
int V_51 ;
V_51 = F_11 ( & V_49 -> V_52 ) ;
if ( V_51 )
return V_51 ;
F_8 ( V_41 , L_7 , V_2 -> V_35 ) ;
F_12 ( V_39 ) ;
F_12 ( V_53 ) ;
F_12 ( V_54 ) ;
F_12 ( V_55 ) ;
F_12 ( V_56 ) ;
F_6 ( V_41 , V_2 -> V_35 + V_36 ) ;
F_7 ( V_41 , L_2 ) ;
F_13 ( & V_49 -> V_52 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 , struct V_57 * V_50 )
{
F_15 ( V_58 ,
F_16 ( V_58 ) ,
V_50 ) ;
}
static int F_17 ( struct V_1 * V_2 , struct V_57 * V_50 )
{
unsigned int V_34 ;
for ( V_34 = 0 ; V_34 < F_16 ( V_58 ) ; V_34 ++ )
V_58 [ V_34 ] . V_43 = V_2 ;
return F_18 ( V_58 ,
F_16 ( V_58 ) ,
V_50 -> V_59 , V_50 ) ;
}
static void F_19 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = V_61 -> V_62 ;
if ( ! V_2 -> V_63 )
return;
F_4 ( L_2 ) ;
if ( V_2 -> V_8 -> V_30 )
F_5 ( 0x00000000 , V_2 -> V_35 + V_39 ) ;
F_5 ( 0x00000000 , V_2 -> V_35 + V_53 ) ;
if ( V_2 -> V_64 )
V_2 -> V_64 -> V_65 -> V_66 ( V_2 -> V_64 ) ;
F_20 ( V_2 -> V_67 ) ;
F_20 ( V_2 -> V_68 ) ;
V_2 -> V_63 = false ;
}
static void F_21 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = V_61 -> V_62 ;
struct V_7 * V_8 = V_2 -> V_8 ;
T_2 V_69 ;
F_4 ( L_2 ) ;
if ( V_2 -> V_63 )
return;
F_5 ( 0x00000000 , V_2 -> V_35 + V_53 ) ;
F_5 ( 0x00000000 , V_2 -> V_35 + V_39 ) ;
if ( V_8 -> V_30 ) {
T_1 V_70 ;
T_2 V_32 [ V_37 ] ;
if ( ! F_1 ( V_2 , & V_70 , V_32 ) )
F_3 ( V_2 , V_32 , V_70 ) ;
else
return;
}
if ( F_22 ( V_2 -> V_67 ) )
F_2 ( L_8 ) ;
if ( F_22 ( V_2 -> V_68 ) )
F_2 ( L_9 ) ;
if ( V_2 -> V_64 )
V_2 -> V_64 -> V_65 -> V_71 ( V_2 -> V_64 ) ;
F_5 ( V_8 -> V_72 , V_2 -> V_35 + V_54 ) ;
F_5 ( V_8 -> V_73 , V_2 -> V_35 + V_55 ) ;
F_5 ( V_8 -> V_74 , V_2 -> V_35 + V_56 ) ;
V_69 = ( V_8 -> V_75 | V_76 ) ;
F_5 ( V_69 , V_2 -> V_35 + V_53 ) ;
V_2 -> V_63 = true ;
}
static void F_23 ( struct V_60 * V_61 ,
struct V_5 * V_6 ,
struct V_5 * V_77 )
{
struct V_1 * V_2 = V_61 -> V_62 ;
struct V_78 * V_79 = F_24 ( V_2 -> V_80 -> V_81 ) ;
int V_82 = V_6 -> clock * 1000 ;
struct V_68 * V_83 ;
int V_51 ;
F_4 ( L_2 ) ;
memcpy ( & V_2 -> V_6 , V_6 , sizeof( struct V_5 ) ) ;
if ( V_79 -> V_84 == V_85 )
V_83 = V_2 -> V_86 ;
else
V_83 = V_2 -> V_87 ;
if ( V_83 ) {
F_25 ( V_2 -> V_67 , V_83 ) ;
F_25 ( V_2 -> V_68 , V_83 ) ;
}
V_51 = F_26 ( V_2 -> V_67 , V_82 ) ;
if ( V_51 < 0 ) {
F_2 ( L_10 , V_82 ) ;
return;
}
V_51 = F_26 ( V_2 -> V_68 , V_82 ) ;
if ( V_51 < 0 ) {
F_2 ( L_11 , V_82 ) ;
return;
}
V_2 -> V_8 = & V_88 ;
}
static void F_27 ( struct V_60 * V_61 )
{
}
static int F_28 ( struct V_89 * V_90 )
{
struct V_91 * V_92
= F_29 ( V_90 ) ;
struct V_1 * V_2 = V_92 -> V_2 ;
if ( V_2 -> V_64 )
return V_2 -> V_64 -> V_65 -> V_93 ( V_2 -> V_64 ) ;
return 0 ;
}
static int F_30 ( struct V_89 * V_90 ,
struct V_5 * V_6 )
{
int V_94 = V_6 -> clock * 1000 ;
int V_95 = V_94 - V_96 ;
int V_97 = V_94 + V_96 ;
int V_98 ;
struct V_91 * V_92
= F_29 ( V_90 ) ;
struct V_1 * V_2 = V_92 -> V_2 ;
V_98 = F_31 ( V_2 -> V_67 , V_94 ) ;
F_4 ( L_12 ,
V_94 , V_98 ) ;
if ( ( V_98 < V_95 ) || ( V_98 > V_97 ) ) {
F_4 ( L_13 , V_94 ) ;
return V_99 ;
}
return V_100 ;
}
struct V_101 * F_32 ( struct V_89 * V_90 )
{
struct V_91 * V_92
= F_29 ( V_90 ) ;
return V_92 -> V_80 ;
}
static enum V_102
F_33 ( struct V_89 * V_90 , bool V_103 )
{
struct V_91 * V_92
= F_29 ( V_90 ) ;
struct V_1 * V_2 = V_92 -> V_2 ;
F_4 ( L_2 ) ;
if ( ! V_2 -> V_64 ) {
V_2 -> V_64 = F_34 ( V_2 -> V_104 ) ;
if ( V_2 -> V_64 )
F_35 ( V_2 -> V_64 , V_90 ) ;
}
if ( V_2 -> V_64 )
return V_105 ;
return V_106 ;
}
static void F_36 ( struct V_89 * V_90 )
{
struct V_91 * V_92
= F_29 ( V_90 ) ;
F_37 ( V_90 ) ;
F_38 ( V_90 ) ;
F_39 ( V_92 ) ;
}
static struct V_101 * F_40 ( struct V_48 * V_49 )
{
struct V_101 * V_80 ;
F_41 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_80 -> V_107 == V_108 )
return V_80 ;
}
return NULL ;
}
static int F_42 ( struct V_109 * V_49 , struct V_109 * V_110 , void * V_43 )
{
struct V_1 * V_2 = F_43 ( V_49 ) ;
struct V_48 * V_111 = V_43 ;
struct V_101 * V_80 ;
struct V_91 * V_90 ;
struct V_89 * V_89 ;
struct V_60 * V_61 ;
int V_112 ;
V_2 -> V_111 = V_111 ;
V_80 = F_40 ( V_111 ) ;
if ( ! V_80 )
return - V_113 ;
V_90 = F_44 ( V_49 , sizeof( * V_90 ) , V_114 ) ;
if ( ! V_90 )
return - V_113 ;
V_90 -> V_2 = V_2 ;
V_61 = F_44 ( V_49 , sizeof( * V_61 ) , V_114 ) ;
if ( ! V_61 )
return - V_113 ;
V_61 -> V_62 = V_2 ;
V_61 -> V_65 = & V_115 ;
V_61 -> V_116 = V_2 -> V_49 . V_116 ;
V_112 = F_45 ( V_61 ) ;
if ( V_112 ) {
F_2 ( L_14 ) ;
return V_112 ;
}
V_112 = F_46 ( V_111 , V_61 ) ;
if ( V_112 ) {
F_2 ( L_15 ) ;
return V_112 ;
}
V_2 -> V_61 = V_61 ;
V_80 -> V_61 = V_61 ;
V_90 -> V_80 = V_80 ;
V_2 -> V_80 = V_80 ;
V_89 = (struct V_89 * ) V_90 ;
V_89 -> V_117 = V_118 ;
F_47 ( V_111 , V_89 ,
& V_119 , V_120 ) ;
F_48 ( V_89 ,
& V_121 ) ;
V_112 = F_49 ( V_89 ) ;
if ( V_112 )
goto V_122;
V_112 = F_50 ( V_89 , V_80 ) ;
if ( V_112 ) {
F_2 ( L_16 ) ;
goto V_123;
}
if ( F_17 ( V_2 , V_111 -> V_124 ) )
F_2 ( L_17 ) ;
return 0 ;
V_123:
F_37 ( V_89 ) ;
V_122:
F_51 ( V_61 ) ;
F_38 ( V_89 ) ;
return - V_31 ;
}
static void F_52 ( struct V_109 * V_49 ,
struct V_109 * V_110 , void * V_43 )
{
struct V_1 * V_2 = F_43 ( V_49 ) ;
struct V_48 * V_111 = V_43 ;
F_14 ( V_2 , V_111 -> V_124 ) ;
F_51 ( V_2 -> V_61 ) ;
}
static int F_53 ( struct V_125 * V_126 )
{
struct V_109 * V_49 = & V_126 -> V_49 ;
struct V_1 * V_2 ;
struct V_127 * V_128 ;
struct V_129 * V_130 = V_49 -> V_116 ;
F_54 ( L_18 , V_131 ) ;
V_2 = F_44 ( V_49 , sizeof( * V_2 ) , V_114 ) ;
if ( ! V_2 ) {
F_2 ( L_19 ) ;
return - V_113 ;
}
V_2 -> V_49 = V_126 -> V_49 ;
V_128 = F_55 ( V_126 , V_132 , L_20 ) ;
if ( ! V_128 ) {
F_2 ( L_21 ) ;
return - V_113 ;
}
V_2 -> V_35 = F_56 ( V_49 , V_128 -> V_133 ,
F_57 ( V_128 ) ) ;
if ( ! V_2 -> V_35 )
return - V_113 ;
V_2 -> V_67 = F_58 ( V_49 , L_22 ) ;
if ( F_59 ( V_2 -> V_67 ) ) {
F_2 ( L_23 ) ;
return F_60 ( V_2 -> V_67 ) ;
}
V_2 -> V_68 = F_58 ( V_49 , L_24 ) ;
if ( F_59 ( V_2 -> V_68 ) ) {
F_2 ( L_25 ) ;
return F_60 ( V_2 -> V_68 ) ;
}
V_2 -> V_86 = F_58 ( V_49 , L_26 ) ;
if ( F_59 ( V_2 -> V_86 ) ) {
F_4 ( L_27 ) ;
V_2 -> V_86 = NULL ;
}
V_2 -> V_87 = F_58 ( V_49 , L_28 ) ;
if ( F_59 ( V_2 -> V_87 ) ) {
F_4 ( L_29 ) ;
V_2 -> V_87 = NULL ;
}
V_2 -> V_104 = F_61 ( V_130 , L_30 , 0 ) ;
if ( ! V_2 -> V_104 )
F_2 ( L_31 ) ;
F_62 ( V_126 , V_2 ) ;
return F_63 ( & V_126 -> V_49 , & V_134 ) ;
}
static int F_64 ( struct V_125 * V_126 )
{
F_65 ( & V_126 -> V_49 , & V_134 ) ;
return 0 ;
}
