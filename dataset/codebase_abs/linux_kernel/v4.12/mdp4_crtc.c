static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static void F_4 ( struct V_2 * V_3 , T_1 V_9 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_6 ( V_9 , & V_10 -> V_9 ) ;
F_7 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
}
static void F_8 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_13 * V_14 ;
T_1 V_15 = 0 ;
F_9 (plane, crtc) {
enum V_16 V_17 = F_10 ( V_14 ) ;
V_15 |= F_11 ( V_17 ) ;
}
V_15 |= F_12 ( V_10 -> V_18 ) ;
F_13 ( L_1 , V_10 -> V_19 , V_15 ) ;
V_10 -> V_20 = V_15 ;
F_14 ( V_1 , V_21 , V_15 ) ;
}
static void F_15 ( struct V_2 * V_3 , struct V_22 * V_23 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_24 * V_6 = V_3 -> V_6 ;
struct V_25 * V_26 ;
unsigned long V_27 ;
F_16 ( & V_6 -> V_28 , V_27 ) ;
V_26 = V_10 -> V_26 ;
if ( V_26 ) {
V_10 -> V_26 = NULL ;
F_13 ( L_2 , V_10 -> V_19 , V_26 ) ;
F_17 ( V_3 , V_26 ) ;
}
F_18 ( & V_6 -> V_28 , V_27 ) ;
}
static void F_19 ( struct V_29 * V_30 , void * V_31 )
{
struct V_10 * V_10 =
F_20 ( V_30 , struct V_10 , V_32 ) ;
struct V_1 * V_1 = F_1 ( & V_10 -> V_11 ) ;
F_21 ( V_31 , V_1 -> V_33 ) ;
F_22 ( V_31 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_24 ( V_3 ) ;
F_25 ( & V_10 -> V_32 ) ;
F_26 ( V_10 ) ;
}
static void F_27 ( struct V_1 * V_1 )
{
struct V_34 * V_35 = & V_1 -> V_6 -> V_36 ;
struct V_2 * V_3 ;
T_1 V_37 = 0 ;
static const enum V_38 V_39 [] = {
V_40 , V_41 , V_42 , V_43 , V_44 ,
} ;
F_28 (crtc, &config->crtc_list, head) {
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_13 * V_14 ;
F_9 (plane, crtc) {
enum V_16 V_17 = F_10 ( V_14 ) ;
int V_45 = V_46 [ V_17 ] ;
V_37 = F_29 ( V_37 , V_10 -> V_47 ,
V_17 , V_39 [ V_45 ] ) ;
}
}
F_14 ( V_1 , V_48 , V_37 ) ;
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_13 * V_14 ;
int V_49 , V_18 = V_10 -> V_18 ;
bool V_50 [ 4 ] = { false , false , false , false } ;
F_14 ( V_1 , F_31 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_32 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_33 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_34 ( V_18 ) , 0 ) ;
F_9 (plane, crtc) {
enum V_16 V_17 = F_10 ( V_14 ) ;
int V_45 = V_46 [ V_17 ] ;
if ( V_45 > 0 ) {
const struct V_51 * V_52 =
F_35 ( F_36 ( V_14 -> V_53 ) ) ;
V_50 [ V_45 - 1 ] = V_52 -> V_54 ;
}
}
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
T_1 V_55 ;
if ( V_50 [ V_49 ] ) {
V_55 = F_37 ( V_56 ) |
F_38 ( V_56 ) |
V_57 ;
} else {
V_55 = F_37 ( V_58 ) |
F_38 ( V_59 ) ;
}
F_14 ( V_1 , F_39 ( V_18 , V_49 ) , 0xff ) ;
F_14 ( V_1 , F_40 ( V_18 , V_49 ) , 0x00 ) ;
F_14 ( V_1 , F_41 ( V_18 , V_49 ) , V_55 ) ;
F_14 ( V_1 , F_42 ( V_18 , V_49 ) , 1 ) ;
F_14 ( V_1 , F_43 ( V_18 , V_49 ) , 0 ) ;
F_14 ( V_1 , F_44 ( V_18 , V_49 ) , 0 ) ;
F_14 ( V_1 , F_45 ( V_18 , V_49 ) , 0 ) ;
F_14 ( V_1 , F_46 ( V_18 , V_49 ) , 0 ) ;
}
F_27 ( V_1 ) ;
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_60 V_61 = V_10 -> V_61 ;
int V_18 = V_10 -> V_18 ;
struct V_62 * V_63 ;
if ( F_48 ( ! V_3 -> V_64 ) )
return;
V_63 = & V_3 -> V_64 -> V_65 ;
F_13 ( L_3 ,
V_10 -> V_19 , V_63 -> V_11 . V_33 , V_63 -> V_19 ,
V_63 -> V_66 , V_63 -> clock ,
V_63 -> V_67 , V_63 -> V_68 ,
V_63 -> V_69 , V_63 -> V_70 ,
V_63 -> V_71 , V_63 -> V_72 ,
V_63 -> V_73 , V_63 -> V_74 ,
V_63 -> type , V_63 -> V_27 ) ;
F_14 ( V_1 , F_49 ( V_61 ) ,
F_50 ( V_63 -> V_67 ) |
F_51 ( V_63 -> V_71 ) ) ;
F_14 ( V_1 , F_52 ( V_61 ) , 0 ) ;
F_14 ( V_1 , F_53 ( V_61 ) , 0 ) ;
F_14 ( V_1 , F_54 ( V_61 ) ,
F_55 ( 0 ) |
F_56 ( 0 ) ) ;
F_14 ( V_1 , F_57 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_58 ( V_18 ) ,
F_59 ( V_63 -> V_67 ) |
F_60 ( V_63 -> V_71 ) ) ;
F_14 ( V_1 , F_61 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_62 ( V_18 ) , 1 ) ;
if ( V_61 == V_75 ) {
F_14 ( V_1 , F_63 ( 0 ) , 0x00ff0000 ) ;
F_14 ( V_1 , F_63 ( 1 ) , 0x00ff0000 ) ;
F_14 ( V_1 , F_63 ( 2 ) , 0x00ff0000 ) ;
}
}
static void F_64 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_13 ( L_4 , V_10 -> V_19 ) ;
if ( F_48 ( ! V_10 -> V_76 ) )
return;
F_65 ( & V_1 -> V_11 , & V_10 -> V_77 ) ;
F_66 ( V_1 ) ;
V_10 -> V_76 = false ;
}
static void F_67 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_13 ( L_4 , V_10 -> V_19 ) ;
if ( F_48 ( V_10 -> V_76 ) )
return;
F_68 ( V_1 ) ;
F_7 ( & V_1 -> V_11 , & V_10 -> V_77 ) ;
F_8 ( V_3 ) ;
V_10 -> V_76 = true ;
}
static int F_69 ( struct V_2 * V_3 ,
struct V_78 * V_64 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_13 ( L_5 , V_10 -> V_19 ) ;
return 0 ;
}
static void F_70 ( struct V_2 * V_3 ,
struct V_78 * V_79 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_13 ( L_6 , V_10 -> V_19 ) ;
}
static void F_71 ( struct V_2 * V_3 ,
struct V_78 * V_79 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_24 * V_6 = V_3 -> V_6 ;
unsigned long V_27 ;
F_13 ( L_7 , V_10 -> V_19 , V_3 -> V_64 -> V_26 ) ;
F_48 ( V_10 -> V_26 ) ;
F_16 ( & V_6 -> V_28 , V_27 ) ;
V_10 -> V_26 = V_3 -> V_64 -> V_26 ;
F_18 ( & V_6 -> V_28 , V_27 ) ;
F_30 ( V_3 ) ;
F_8 ( V_3 ) ;
F_4 ( V_3 , V_80 ) ;
}
static void F_72 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_60 V_61 = V_10 -> V_61 ;
unsigned long V_27 ;
F_16 ( & V_10 -> V_81 . V_82 , V_27 ) ;
if ( V_10 -> V_81 . V_83 ) {
struct V_84 * V_85 = V_10 -> V_81 . V_85 ;
struct V_84 * V_86 = V_10 -> V_81 . V_87 ;
T_2 V_88 = V_10 -> V_81 . V_89 ;
if ( V_85 ) {
F_73 ( V_85 ) ;
F_74 ( V_85 , V_1 -> V_33 , & V_88 ) ;
F_14 ( V_1 , F_75 ( V_61 ) ,
F_76 ( V_10 -> V_81 . V_90 ) |
F_77 ( V_10 -> V_81 . V_91 ) ) ;
F_14 ( V_1 , F_78 ( V_61 ) , V_88 ) ;
F_14 ( V_1 , F_79 ( V_61 ) ,
F_80 ( V_92 ) |
V_93 ) ;
} else {
F_14 ( V_1 , F_78 ( V_61 ) ,
V_1 -> V_94 ) ;
}
if ( V_86 )
F_81 ( & V_10 -> V_32 , V_86 ) ;
V_10 -> V_81 . V_87 = V_85 ;
V_10 -> V_81 . V_83 = false ;
}
F_14 ( V_1 , F_82 ( V_61 ) ,
F_83 ( V_10 -> V_81 . V_95 ) |
F_84 ( V_10 -> V_81 . V_96 ) ) ;
F_18 ( & V_10 -> V_81 . V_82 , V_27 ) ;
}
static int F_85 ( struct V_2 * V_3 ,
struct V_22 * V_97 , T_1 V_98 ,
T_1 V_90 , T_1 V_91 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_24 * V_6 = V_3 -> V_6 ;
struct V_84 * V_99 , * V_100 ;
unsigned long V_27 ;
T_2 V_88 ;
int V_101 ;
if ( ( V_90 > V_102 ) || ( V_91 > V_103 ) ) {
F_86 ( V_6 -> V_6 , L_8 , V_90 , V_91 ) ;
return - V_104 ;
}
if ( V_98 ) {
V_99 = F_87 ( V_97 , V_98 ) ;
if ( ! V_99 )
return - V_105 ;
} else {
V_99 = NULL ;
}
if ( V_99 ) {
V_101 = F_88 ( V_99 , V_1 -> V_33 , & V_88 ) ;
if ( V_101 )
goto V_106;
} else {
V_88 = 0 ;
}
F_16 ( & V_10 -> V_81 . V_82 , V_27 ) ;
V_100 = V_10 -> V_81 . V_85 ;
V_10 -> V_81 . V_85 = V_99 ;
V_10 -> V_81 . V_89 = V_88 ;
V_10 -> V_81 . V_90 = V_90 ;
V_10 -> V_81 . V_91 = V_91 ;
V_10 -> V_81 . V_83 = true ;
F_18 ( & V_10 -> V_81 . V_82 , V_27 ) ;
if ( V_100 ) {
F_81 ( & V_10 -> V_32 , V_100 ) ;
}
F_4 ( V_3 , V_107 ) ;
return 0 ;
V_106:
F_22 ( V_99 ) ;
return V_101 ;
}
static int F_89 ( struct V_2 * V_3 , int V_95 , int V_96 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
unsigned long V_27 ;
F_16 ( & V_10 -> V_81 . V_82 , V_27 ) ;
V_10 -> V_81 . V_95 = V_95 ;
V_10 -> V_81 . V_96 = V_96 ;
F_18 ( & V_10 -> V_81 . V_82 , V_27 ) ;
F_8 ( V_3 ) ;
F_4 ( V_3 , V_107 ) ;
return 0 ;
}
static void F_90 ( struct V_108 * V_109 , T_1 V_110 )
{
struct V_10 * V_10 = F_20 ( V_109 , struct V_10 , V_12 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
unsigned V_9 ;
F_65 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
V_9 = F_91 ( & V_10 -> V_9 , 0 ) ;
if ( V_9 & V_80 ) {
F_15 ( V_3 , NULL ) ;
}
if ( V_9 & V_107 ) {
F_72 ( V_3 ) ;
F_92 ( & V_10 -> V_32 , V_5 -> V_111 ) ;
}
}
static void F_93 ( struct V_108 * V_109 , T_1 V_110 )
{
struct V_10 * V_10 = F_20 ( V_109 , struct V_10 , V_77 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
F_13 ( L_9 , V_10 -> V_19 , V_110 ) ;
F_8 ( V_3 ) ;
}
static void F_94 ( struct V_2 * V_3 )
{
struct V_24 * V_6 = V_3 -> V_6 ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_101 ;
V_101 = F_95 ( V_3 ) ;
if ( V_101 )
return;
V_101 = F_96 ( V_6 -> V_12 [ F_97 ( V_3 ) ] . V_112 ,
! ( F_98 ( V_1 , V_21 ) &
V_10 -> V_20 ) ,
F_99 ( 50 ) ) ;
if ( V_101 <= 0 )
F_100 ( V_6 -> V_6 , L_10 , V_10 -> V_33 ) ;
V_10 -> V_20 = 0 ;
F_101 ( V_3 ) ;
}
T_1 F_102 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return V_10 -> V_12 . V_113 ;
}
void F_103 ( struct V_2 * V_3 , T_1 V_35 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_14 ( V_1 , F_104 ( V_10 -> V_61 ) , V_35 ) ;
}
void F_105 ( struct V_2 * V_3 , enum V_114 V_115 , int V_47 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_116 ;
V_116 = F_98 ( V_1 , V_117 ) ;
switch ( V_10 -> V_61 ) {
case V_118 :
V_116 &= ~ V_119 ;
V_116 |= F_106 ( V_115 ) ;
break;
case V_120 :
V_116 &= ~ V_121 ;
V_116 |= F_107 ( V_115 ) ;
break;
case V_75 :
V_116 &= ~ V_122 ;
V_116 |= F_108 ( V_115 ) ;
break;
}
if ( V_115 == V_123 ) {
V_116 &= ~ V_124 ;
V_116 |= V_125 ;
} else if ( V_115 == V_126 ) {
V_116 &= ~ V_125 ;
V_116 |= V_124 ;
}
V_10 -> V_47 = V_47 ;
F_30 ( V_3 ) ;
F_13 ( L_11 , V_10 -> V_19 , V_116 ) ;
F_14 ( V_1 , V_117 , V_116 ) ;
}
void F_109 ( struct V_2 * V_3 )
{
F_94 ( V_3 ) ;
}
struct V_2 * F_110 ( struct V_24 * V_6 ,
struct V_13 * V_14 , int V_33 , int V_127 ,
enum V_60 V_128 )
{
struct V_2 * V_3 = NULL ;
struct V_10 * V_10 ;
V_10 = F_111 ( sizeof( * V_10 ) , V_129 ) ;
if ( ! V_10 )
return F_112 ( - V_130 ) ;
V_3 = & V_10 -> V_11 ;
V_10 -> V_33 = V_33 ;
V_10 -> V_18 = V_127 ;
V_10 -> V_61 = V_128 ;
V_10 -> V_12 . V_113 = F_113 ( V_10 -> V_61 ) ;
V_10 -> V_12 . V_109 = F_90 ;
V_10 -> V_77 . V_113 = F_114 ( V_10 -> V_61 ) ;
V_10 -> V_77 . V_109 = F_93 ;
snprintf ( V_10 -> V_19 , sizeof( V_10 -> V_19 ) , L_12 ,
V_131 [ V_128 ] , V_127 ) ;
F_115 ( & V_10 -> V_81 . V_82 ) ;
F_116 ( & V_10 -> V_32 ,
L_13 , F_19 ) ;
F_117 ( V_6 , V_3 , V_14 , NULL , & V_132 ,
NULL ) ;
F_118 ( V_3 , & V_133 ) ;
V_14 -> V_3 = V_3 ;
return V_3 ;
}
