static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline int F_3 ( struct V_4 * V_5 )
{
return V_5 - V_5 -> V_3 -> V_6 ;
}
static void F_4 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_5 ( V_8 ) ;
F_6 ( V_8 ) ;
F_7 ( & V_10 -> V_11 , true ) ;
F_8 ( V_8 ) ;
}
static struct V_12 * F_9 ( struct V_4 * V_5 )
{
T_1 V_13 = F_3 ( V_5 ) ;
if ( V_13 == 0 )
return V_5 -> V_3 -> V_14 . V_15 [ V_13 ] ;
return V_5 -> V_3 -> V_16 . V_15 [ V_13 - 1 ] ;
}
static void F_10 ( struct V_17 * V_8 )
{
struct V_4 * V_5 =
F_2 ( V_8 -> V_18 , struct V_4 , V_19 ) ;
struct V_20 * V_21 = V_8 -> V_22 ;
if ( F_11 ( F_3 ( V_5 ) == 0 &&
V_21 -> V_23 >= V_24 ) ) {
F_12 ( & V_5 -> V_3 -> V_3 , V_21 -> V_25 ,
& V_21 -> V_26 ) ;
} else {
struct V_7 * V_27 ;
V_27 = F_13 ( F_9 ( V_5 ) , V_21 -> V_23 ) ;
if ( ! V_27 ) {
F_14 ( V_5 -> V_3 -> V_3 . V_28 ,
L_1 ,
V_21 -> V_23 , F_3 ( V_5 ) ) ;
return;
}
F_15 ( V_27 , V_21 -> V_25 , V_21 -> V_26 ) ;
}
}
static void F_16 ( struct V_29 * V_30 )
{
struct V_9 * V_10 =
F_2 ( V_30 , struct V_9 , V_30 ) ;
V_10 -> V_8 . V_31 ( & V_10 -> V_8 ) ;
}
static enum V_32
F_17 ( struct V_7 * V_27 , bool V_33 )
{
struct V_9 * V_10 = F_5 ( V_27 ) ;
F_18 ( & V_10 -> V_5 -> V_3 -> V_3 ) ;
F_19 ( V_27 ) -> V_25 = V_34 | V_35 ;
return V_36 ;
}
static T_2 F_20 ( struct V_37 * V_38 ,
const struct V_39 * V_40 )
{
struct V_41 * V_42 = V_38 -> V_5 -> V_43 ;
struct V_4 * V_5 = V_38 -> V_44 ;
struct V_7 * V_8 = V_40 -> V_27 ;
struct V_9 * V_10 = F_5 ( V_8 ) ;
T_2 V_45 ;
V_45 = F_21 ( V_42 , V_8 , & V_10 -> V_46 ) ;
if ( V_45 )
return V_45 ;
V_10 -> V_46 . V_47 . V_48 |= V_49 ;
V_10 -> V_8 . V_50 = V_51 ;
if ( ! F_22 ( & V_10 -> V_8 , & V_5 -> V_52 ,
& V_5 -> V_19 , & V_53 ) ) {
F_6 ( V_8 ) ;
F_23 ( V_8 ) ;
F_10 ( & V_10 -> V_8 ) ;
return V_54 ;
}
if ( F_24 ( V_8 ) ) {
V_10 -> V_11 . V_55 = V_10 -> V_56 ;
if ( F_25 ( & V_10 -> V_11 ,
F_26 ( V_8 ) ,
V_10 -> V_11 . V_55 ) )
return V_57 ;
V_10 -> V_8 . V_58 = V_10 -> V_11 . V_55 ;
V_10 -> V_8 . V_59 = F_27 ( V_8 -> V_60 , V_8 , V_10 -> V_11 . V_55 ) ;
}
F_23 ( V_8 ) ;
F_28 ( & V_10 -> V_30 ) ;
return V_54 ;
}
static void F_29 ( struct V_2 * V_61 , int V_62 )
{
struct V_1 * V_3 = F_1 ( V_61 ) ;
struct V_4 * V_5 = & V_3 -> V_6 [ 0 ] ;
struct V_9 * V_10 = & V_3 -> V_63 ;
memset ( & V_10 -> V_46 , 0 , sizeof( V_10 -> V_46 ) ) ;
V_10 -> V_46 . V_47 . V_64 = V_65 ;
V_10 -> V_46 . V_47 . V_23 = V_24 ;
V_10 -> V_46 . V_47 . V_48 |= V_49 ;
if ( ! F_22 ( & V_10 -> V_8 , & V_5 -> V_52 , & V_5 -> V_19 ,
& V_53 ) ) {
F_14 ( V_3 -> V_3 . V_28 , L_2 ) ;
return;
}
F_28 ( & V_10 -> V_30 ) ;
}
static int F_30 ( struct V_1 * V_3 ,
struct V_9 * V_10 , unsigned int V_13 )
{
V_10 -> V_8 . V_46 = & V_10 -> V_46 ;
V_10 -> V_8 . V_22 = & V_10 -> V_22 ;
V_10 -> V_5 = & V_3 -> V_6 [ V_13 ] ;
F_31 ( & V_10 -> V_30 , F_16 ) ;
return 0 ;
}
static int F_32 ( struct V_66 * V_67 ,
struct V_7 * V_8 , unsigned int V_68 ,
unsigned int V_69 )
{
struct V_1 * V_3 = V_67 -> V_44 ;
return F_30 ( V_3 , F_5 ( V_8 ) ,
( V_67 == & V_3 -> V_16 ) ? V_68 + 1 : 0 ) ;
}
static int F_33 ( struct V_37 * V_38 , void * V_70 ,
unsigned int V_68 )
{
struct V_1 * V_3 = V_70 ;
struct V_4 * V_5 = & V_3 -> V_6 [ V_68 + 1 ] ;
F_34 ( V_68 >= V_3 -> V_3 . V_71 ) ;
V_38 -> V_44 = V_5 ;
return 0 ;
}
static int F_35 ( struct V_37 * V_38 , void * V_70 ,
unsigned int V_68 )
{
struct V_1 * V_3 = V_70 ;
struct V_4 * V_5 = & V_3 -> V_6 [ 0 ] ;
F_34 ( V_68 != 0 ) ;
V_38 -> V_44 = V_5 ;
return 0 ;
}
static void F_36 ( struct V_1 * V_3 )
{
F_37 ( & V_3 -> V_6 [ 0 ] . V_19 ) ;
F_38 ( V_3 -> V_3 . V_72 ) ;
F_39 ( & V_3 -> V_14 ) ;
}
static void F_40 ( struct V_2 * V_73 )
{
struct V_1 * V_3 = F_1 ( V_73 ) ;
if ( F_41 ( & V_3 -> V_74 ) )
goto V_75;
F_42 ( & V_76 ) ;
F_43 ( & V_3 -> V_74 ) ;
F_44 ( & V_76 ) ;
if ( V_73 -> V_77 ) {
F_38 ( V_3 -> V_3 . V_78 ) ;
F_39 ( & V_3 -> V_16 ) ;
}
F_45 ( V_3 -> V_6 ) ;
F_46 ( V_73 -> V_79 ) ;
V_75:
F_45 ( V_3 ) ;
}
static void F_47 ( struct V_1 * V_3 )
{
int V_80 ;
for ( V_80 = 1 ; V_80 < V_3 -> V_3 . V_71 ; V_80 ++ )
F_37 ( & V_3 -> V_6 [ V_80 ] . V_19 ) ;
}
static int F_48 ( struct V_1 * V_3 )
{
struct V_81 * V_79 = V_3 -> V_3 . V_79 ;
unsigned int V_82 ;
int V_45 , V_80 ;
V_82 = F_49 ( V_79 -> V_82 , F_50 () ) ;
V_45 = F_51 ( & V_3 -> V_3 , & V_82 ) ;
if ( V_45 || ! V_82 )
return V_45 ;
F_52 ( V_3 -> V_3 . V_28 , L_3 , V_82 ) ;
for ( V_80 = 1 ; V_80 <= V_82 ; V_80 ++ ) {
V_3 -> V_6 [ V_80 ] . V_3 = V_3 ;
V_45 = F_53 ( & V_3 -> V_6 [ V_80 ] . V_19 ) ;
if ( V_45 )
goto V_83;
V_3 -> V_3 . V_71 ++ ;
}
return 0 ;
V_83:
F_47 ( V_3 ) ;
return V_45 ;
}
static int F_54 ( struct V_1 * V_3 )
{
int V_80 , V_45 ;
for ( V_80 = 1 ; V_80 < V_3 -> V_3 . V_71 ; V_80 ++ ) {
V_45 = F_55 ( & V_3 -> V_3 , V_80 ) ;
if ( V_45 )
return V_45 ;
}
return 0 ;
}
static int F_56 ( struct V_1 * V_3 )
{
int error ;
memset ( & V_3 -> V_14 , 0 , sizeof( V_3 -> V_14 ) ) ;
V_3 -> V_14 . V_84 = & V_85 ;
V_3 -> V_14 . V_86 = V_24 ;
V_3 -> V_14 . V_87 = 2 ;
V_3 -> V_14 . V_69 = V_88 ;
V_3 -> V_14 . V_89 = sizeof( struct V_9 ) +
V_90 * sizeof( struct V_91 ) ;
V_3 -> V_14 . V_44 = V_3 ;
V_3 -> V_14 . V_92 = 1 ;
V_3 -> V_14 . V_93 = V_94 ;
V_3 -> V_6 [ 0 ] . V_3 = V_3 ;
error = F_53 ( & V_3 -> V_6 [ 0 ] . V_19 ) ;
if ( error )
return error ;
V_3 -> V_3 . V_71 = 1 ;
error = F_57 ( & V_3 -> V_14 ) ;
if ( error )
goto V_95;
V_3 -> V_3 . V_72 = F_58 ( & V_3 -> V_14 ) ;
if ( F_59 ( V_3 -> V_3 . V_72 ) ) {
error = F_60 ( V_3 -> V_3 . V_72 ) ;
goto V_96;
}
error = F_61 ( & V_3 -> V_3 ) ;
if ( error )
goto V_97;
error = F_62 ( & V_3 -> V_3 , V_98 , & V_3 -> V_3 . V_99 ) ;
if ( error ) {
F_14 ( V_3 -> V_3 . V_28 ,
L_4 ) ;
goto V_97;
}
V_3 -> V_3 . V_100 =
F_63 ( int , F_64 ( V_3 -> V_3 . V_99 ) , V_3 -> V_3 . V_100 ) ;
error = F_65 ( & V_3 -> V_3 , V_3 -> V_3 . V_99 ) ;
if ( error )
goto V_97;
V_3 -> V_3 . V_101 =
( V_102 - 1 ) << ( V_103 - 9 ) ;
error = F_66 ( & V_3 -> V_3 ) ;
if ( error )
goto V_97;
return 0 ;
V_97:
F_38 ( V_3 -> V_3 . V_72 ) ;
V_96:
F_39 ( & V_3 -> V_14 ) ;
V_95:
F_37 ( & V_3 -> V_6 [ 0 ] . V_19 ) ;
return error ;
}
static void F_67 ( struct V_1 * V_3 )
{
if ( V_3 -> V_3 . V_71 > 1 ) {
F_68 ( & V_3 -> V_3 ) ;
F_69 ( & V_3 -> V_16 ,
V_104 , & V_3 -> V_3 ) ;
F_47 ( V_3 ) ;
}
if ( V_3 -> V_3 . V_105 == V_106 )
F_70 ( & V_3 -> V_3 ) ;
F_71 ( V_3 -> V_3 . V_72 ) ;
F_69 ( & V_3 -> V_14 ,
V_104 , & V_3 -> V_3 ) ;
F_72 ( V_3 -> V_3 . V_72 ) ;
F_36 ( V_3 ) ;
}
static void F_73 ( struct V_29 * V_30 )
{
struct V_1 * V_3 = F_2 ( V_30 ,
struct V_1 , V_107 ) ;
F_74 ( & V_3 -> V_3 ) ;
F_75 ( & V_3 -> V_3 ) ;
F_67 ( V_3 ) ;
F_76 ( & V_3 -> V_3 ) ;
F_77 ( & V_3 -> V_3 ) ;
}
static int F_78 ( struct V_1 * V_3 )
{
if ( ! F_79 ( & V_3 -> V_3 , V_108 ) )
return - V_109 ;
if ( ! F_80 ( V_110 , & V_3 -> V_107 ) )
return - V_109 ;
return 0 ;
}
static int F_81 ( struct V_2 * V_73 )
{
struct V_1 * V_3 = F_1 ( V_73 ) ;
int V_45 ;
V_45 = F_78 ( V_3 ) ;
if ( V_45 )
return V_45 ;
F_82 ( & V_3 -> V_107 ) ;
return 0 ;
}
static void F_83 ( struct V_111 * V_73 )
{
struct V_1 * V_3 ;
F_42 ( & V_76 ) ;
F_84 (ctrl, &nvme_loop_ctrl_list, list) {
if ( V_3 -> V_3 . V_112 == V_73 -> V_112 )
F_78 ( V_3 ) ;
}
F_44 ( & V_76 ) ;
}
static void F_85 ( struct V_29 * V_30 )
{
struct V_1 * V_3 =
F_2 ( V_30 , struct V_1 , V_3 . V_113 ) ;
bool V_114 ;
int V_45 ;
F_74 ( & V_3 -> V_3 ) ;
F_67 ( V_3 ) ;
V_45 = F_56 ( V_3 ) ;
if ( V_45 )
goto V_115;
V_45 = F_48 ( V_3 ) ;
if ( V_45 )
goto V_116;
V_45 = F_54 ( V_3 ) ;
if ( V_45 )
goto V_117;
F_86 ( & V_3 -> V_16 ,
V_3 -> V_3 . V_71 - 1 ) ;
V_114 = F_79 ( & V_3 -> V_3 , V_106 ) ;
F_87 ( ! V_114 ) ;
F_88 ( & V_3 -> V_3 ) ;
return;
V_117:
F_47 ( V_3 ) ;
V_116:
F_36 ( V_3 ) ;
V_115:
F_89 ( V_3 -> V_3 . V_28 , L_5 ) ;
F_76 ( & V_3 -> V_3 ) ;
F_77 ( & V_3 -> V_3 ) ;
}
static int F_90 ( struct V_1 * V_3 )
{
int V_45 ;
V_45 = F_48 ( V_3 ) ;
if ( V_45 )
return V_45 ;
memset ( & V_3 -> V_16 , 0 , sizeof( V_3 -> V_16 ) ) ;
V_3 -> V_16 . V_84 = & V_118 ;
V_3 -> V_16 . V_86 = V_3 -> V_3 . V_79 -> V_119 ;
V_3 -> V_16 . V_87 = 1 ;
V_3 -> V_16 . V_69 = V_88 ;
V_3 -> V_16 . V_48 = V_120 ;
V_3 -> V_16 . V_89 = sizeof( struct V_9 ) +
V_90 * sizeof( struct V_91 ) ;
V_3 -> V_16 . V_44 = V_3 ;
V_3 -> V_16 . V_92 = V_3 -> V_3 . V_71 - 1 ;
V_3 -> V_16 . V_93 = V_121 ;
V_3 -> V_3 . V_77 = & V_3 -> V_16 ;
V_45 = F_57 ( & V_3 -> V_16 ) ;
if ( V_45 )
goto V_83;
V_3 -> V_3 . V_78 = F_58 ( & V_3 -> V_16 ) ;
if ( F_59 ( V_3 -> V_3 . V_78 ) ) {
V_45 = F_60 ( V_3 -> V_3 . V_78 ) ;
goto V_96;
}
V_45 = F_54 ( V_3 ) ;
if ( V_45 )
goto V_122;
return 0 ;
V_122:
F_38 ( V_3 -> V_3 . V_78 ) ;
V_96:
F_39 ( & V_3 -> V_16 ) ;
V_83:
F_47 ( V_3 ) ;
return V_45 ;
}
static struct V_2 * F_91 ( struct V_28 * V_123 ,
struct V_81 * V_79 )
{
struct V_1 * V_3 ;
bool V_114 ;
int V_45 ;
V_3 = F_92 ( sizeof( * V_3 ) , V_124 ) ;
if ( ! V_3 )
return F_93 ( - V_125 ) ;
V_3 -> V_3 . V_79 = V_79 ;
F_94 ( & V_3 -> V_74 ) ;
F_31 ( & V_3 -> V_107 , F_73 ) ;
F_31 ( & V_3 -> V_3 . V_113 , F_85 ) ;
V_45 = F_95 ( & V_3 -> V_3 , V_123 , & V_126 ,
0 ) ;
if ( V_45 )
goto V_127;
V_45 = - V_125 ;
V_3 -> V_3 . V_100 = V_79 -> V_119 - 1 ;
V_3 -> V_3 . V_128 = V_79 -> V_128 ;
V_3 -> V_6 = F_96 ( V_79 -> V_82 + 1 , sizeof( * V_3 -> V_6 ) ,
V_124 ) ;
if ( ! V_3 -> V_6 )
goto V_129;
V_45 = F_56 ( V_3 ) ;
if ( V_45 )
goto V_130;
if ( V_79 -> V_119 > V_3 -> V_3 . V_131 ) {
F_89 ( V_3 -> V_3 . V_28 ,
L_6 ,
V_79 -> V_119 , V_3 -> V_3 . V_131 ) ;
V_79 -> V_119 = V_3 -> V_3 . V_131 ;
}
if ( V_79 -> V_82 ) {
V_45 = F_90 ( V_3 ) ;
if ( V_45 )
goto V_132;
}
F_30 ( V_3 , & V_3 -> V_63 , 0 ) ;
F_52 ( V_3 -> V_3 . V_28 ,
L_7 , V_3 -> V_3 . V_79 -> V_133 ) ;
F_97 ( & V_3 -> V_3 . V_134 ) ;
V_114 = F_79 ( & V_3 -> V_3 , V_106 ) ;
F_87 ( ! V_114 ) ;
F_42 ( & V_76 ) ;
F_98 ( & V_3 -> V_74 , & V_135 ) ;
F_44 ( & V_76 ) ;
F_88 ( & V_3 -> V_3 ) ;
return & V_3 -> V_3 ;
V_132:
F_36 ( V_3 ) ;
V_130:
F_45 ( V_3 -> V_6 ) ;
V_129:
F_76 ( & V_3 -> V_3 ) ;
V_127:
F_77 ( & V_3 -> V_3 ) ;
if ( V_45 > 0 )
V_45 = - V_136 ;
return F_93 ( V_45 ) ;
}
static int F_99 ( struct V_137 * V_50 )
{
if ( V_51 )
return - V_138 ;
V_51 = V_50 ;
return 0 ;
}
static void F_100 ( struct V_137 * V_50 )
{
if ( V_50 == V_51 )
V_51 = NULL ;
}
static int T_3 F_101 ( void )
{
int V_45 ;
V_45 = F_102 ( & V_53 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_103 ( & V_139 ) ;
if ( V_45 )
F_104 ( & V_53 ) ;
return V_45 ;
}
static void T_4 F_105 ( void )
{
struct V_1 * V_3 , * V_140 ;
F_106 ( & V_139 ) ;
F_104 ( & V_53 ) ;
F_42 ( & V_76 ) ;
F_107 (ctrl, next, &nvme_loop_ctrl_list, list)
F_78 ( V_3 ) ;
F_44 ( & V_76 ) ;
F_108 ( V_110 ) ;
}
