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
struct V_33 * V_8 = & V_1 -> V_11 . V_11 ;
F_21 ( V_31 , V_8 -> V_34 ) ;
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
struct V_35 * V_36 = & V_1 -> V_6 -> V_37 ;
struct V_2 * V_3 ;
T_1 V_38 = 0 ;
static const enum V_39 V_40 [] = {
V_41 , V_42 , V_43 , V_44 , V_45 ,
} ;
F_28 (crtc, &config->crtc_list, head) {
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_13 * V_14 ;
F_9 (plane, crtc) {
enum V_16 V_17 = F_10 ( V_14 ) ;
int V_46 = V_47 [ V_17 ] ;
V_38 = F_29 ( V_38 , V_10 -> V_48 ,
V_17 , V_40 [ V_46 ] ) ;
}
}
F_14 ( V_1 , V_49 , V_38 ) ;
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_13 * V_14 ;
int V_50 , V_18 = V_10 -> V_18 ;
bool V_51 [ 4 ] = { false , false , false , false } ;
F_14 ( V_1 , F_31 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_32 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_33 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_34 ( V_18 ) , 0 ) ;
F_9 (plane, crtc) {
enum V_16 V_17 = F_10 ( V_14 ) ;
int V_46 = V_47 [ V_17 ] ;
if ( V_46 > 0 ) {
const struct V_52 * V_53 =
F_35 ( F_36 ( V_14 -> V_54 ) ) ;
V_51 [ V_46 - 1 ] = V_53 -> V_55 ;
}
}
for ( V_50 = 0 ; V_50 < 4 ; V_50 ++ ) {
T_1 V_56 ;
if ( V_51 [ V_50 ] ) {
V_56 = F_37 ( V_57 ) |
F_38 ( V_57 ) |
V_58 ;
} else {
V_56 = F_37 ( V_59 ) |
F_38 ( V_60 ) ;
}
F_14 ( V_1 , F_39 ( V_18 , V_50 ) , 0xff ) ;
F_14 ( V_1 , F_40 ( V_18 , V_50 ) , 0x00 ) ;
F_14 ( V_1 , F_41 ( V_18 , V_50 ) , V_56 ) ;
F_14 ( V_1 , F_42 ( V_18 , V_50 ) , 1 ) ;
F_14 ( V_1 , F_43 ( V_18 , V_50 ) , 0 ) ;
F_14 ( V_1 , F_44 ( V_18 , V_50 ) , 0 ) ;
F_14 ( V_1 , F_45 ( V_18 , V_50 ) , 0 ) ;
F_14 ( V_1 , F_46 ( V_18 , V_50 ) , 0 ) ;
}
F_27 ( V_1 ) ;
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_61 V_62 = V_10 -> V_62 ;
int V_18 = V_10 -> V_18 ;
struct V_63 * V_64 ;
if ( F_48 ( ! V_3 -> V_65 ) )
return;
V_64 = & V_3 -> V_65 -> V_66 ;
F_13 ( L_3 ,
V_10 -> V_19 , V_64 -> V_11 . V_67 , V_64 -> V_19 ,
V_64 -> V_68 , V_64 -> clock ,
V_64 -> V_69 , V_64 -> V_70 ,
V_64 -> V_71 , V_64 -> V_72 ,
V_64 -> V_73 , V_64 -> V_74 ,
V_64 -> V_75 , V_64 -> V_76 ,
V_64 -> type , V_64 -> V_27 ) ;
F_14 ( V_1 , F_49 ( V_62 ) ,
F_50 ( V_64 -> V_69 ) |
F_51 ( V_64 -> V_73 ) ) ;
F_14 ( V_1 , F_52 ( V_62 ) , 0 ) ;
F_14 ( V_1 , F_53 ( V_62 ) , 0 ) ;
F_14 ( V_1 , F_54 ( V_62 ) ,
F_55 ( 0 ) |
F_56 ( 0 ) ) ;
F_14 ( V_1 , F_57 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_58 ( V_18 ) ,
F_59 ( V_64 -> V_69 ) |
F_60 ( V_64 -> V_73 ) ) ;
F_14 ( V_1 , F_61 ( V_18 ) , 0 ) ;
F_14 ( V_1 , F_62 ( V_18 ) , 1 ) ;
if ( V_62 == V_77 ) {
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
if ( F_48 ( ! V_10 -> V_78 ) )
return;
F_65 ( & V_1 -> V_11 , & V_10 -> V_79 ) ;
F_66 ( V_1 ) ;
V_10 -> V_78 = false ;
}
static void F_67 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_13 ( L_4 , V_10 -> V_19 ) ;
if ( F_48 ( V_10 -> V_78 ) )
return;
F_68 ( V_1 ) ;
F_7 ( & V_1 -> V_11 , & V_10 -> V_79 ) ;
F_8 ( V_3 ) ;
V_10 -> V_78 = true ;
}
static int F_69 ( struct V_2 * V_3 ,
struct V_80 * V_65 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_13 ( L_5 , V_10 -> V_19 ) ;
return 0 ;
}
static void F_70 ( struct V_2 * V_3 ,
struct V_80 * V_81 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_13 ( L_6 , V_10 -> V_19 ) ;
}
static void F_71 ( struct V_2 * V_3 ,
struct V_80 * V_81 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_24 * V_6 = V_3 -> V_6 ;
unsigned long V_27 ;
F_13 ( L_7 , V_10 -> V_19 , V_3 -> V_65 -> V_26 ) ;
F_48 ( V_10 -> V_26 ) ;
F_16 ( & V_6 -> V_28 , V_27 ) ;
V_10 -> V_26 = V_3 -> V_65 -> V_26 ;
F_18 ( & V_6 -> V_28 , V_27 ) ;
F_30 ( V_3 ) ;
F_8 ( V_3 ) ;
F_4 ( V_3 , V_82 ) ;
}
static void F_72 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_33 * V_8 = & V_1 -> V_11 . V_11 ;
enum V_61 V_62 = V_10 -> V_62 ;
unsigned long V_27 ;
F_16 ( & V_10 -> V_83 . V_84 , V_27 ) ;
if ( V_10 -> V_83 . V_85 ) {
struct V_86 * V_87 = V_10 -> V_83 . V_87 ;
struct V_86 * V_88 = V_10 -> V_83 . V_89 ;
T_2 V_90 = V_10 -> V_83 . V_91 ;
if ( V_87 ) {
F_73 ( V_87 ) ;
F_74 ( V_87 , V_8 -> V_34 , & V_90 ) ;
F_14 ( V_1 , F_75 ( V_62 ) ,
F_76 ( V_10 -> V_83 . V_92 ) |
F_77 ( V_10 -> V_83 . V_93 ) ) ;
F_14 ( V_1 , F_78 ( V_62 ) , V_90 ) ;
F_14 ( V_1 , F_79 ( V_62 ) ,
F_80 ( V_94 ) |
V_95 ) ;
} else {
F_14 ( V_1 , F_78 ( V_62 ) ,
V_1 -> V_96 ) ;
}
if ( V_88 )
F_81 ( & V_10 -> V_32 , V_88 ) ;
V_10 -> V_83 . V_89 = V_87 ;
V_10 -> V_83 . V_85 = false ;
}
F_14 ( V_1 , F_82 ( V_62 ) ,
F_83 ( V_10 -> V_83 . V_97 ) |
F_84 ( V_10 -> V_83 . V_98 ) ) ;
F_18 ( & V_10 -> V_83 . V_84 , V_27 ) ;
}
static int F_85 ( struct V_2 * V_3 ,
struct V_22 * V_99 , T_1 V_100 ,
T_1 V_92 , T_1 V_93 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_33 * V_8 = & V_1 -> V_11 . V_11 ;
struct V_24 * V_6 = V_3 -> V_6 ;
struct V_86 * V_101 , * V_102 ;
unsigned long V_27 ;
T_2 V_90 ;
int V_103 ;
if ( ( V_92 > V_104 ) || ( V_93 > V_105 ) ) {
F_86 ( V_6 -> V_6 , L_8 , V_92 , V_93 ) ;
return - V_106 ;
}
if ( V_100 ) {
V_101 = F_87 ( V_99 , V_100 ) ;
if ( ! V_101 )
return - V_107 ;
} else {
V_101 = NULL ;
}
if ( V_101 ) {
V_103 = F_74 ( V_101 , V_8 -> V_34 , & V_90 ) ;
if ( V_103 )
goto V_108;
} else {
V_90 = 0 ;
}
F_16 ( & V_10 -> V_83 . V_84 , V_27 ) ;
V_102 = V_10 -> V_83 . V_87 ;
V_10 -> V_83 . V_87 = V_101 ;
V_10 -> V_83 . V_91 = V_90 ;
V_10 -> V_83 . V_92 = V_92 ;
V_10 -> V_83 . V_93 = V_93 ;
V_10 -> V_83 . V_85 = true ;
F_18 ( & V_10 -> V_83 . V_84 , V_27 ) ;
if ( V_102 ) {
F_81 ( & V_10 -> V_32 , V_102 ) ;
}
F_4 ( V_3 , V_109 ) ;
return 0 ;
V_108:
F_22 ( V_101 ) ;
return V_103 ;
}
static int F_88 ( struct V_2 * V_3 , int V_97 , int V_98 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
unsigned long V_27 ;
F_16 ( & V_10 -> V_83 . V_84 , V_27 ) ;
V_10 -> V_83 . V_97 = V_97 ;
V_10 -> V_83 . V_98 = V_98 ;
F_18 ( & V_10 -> V_83 . V_84 , V_27 ) ;
F_8 ( V_3 ) ;
F_4 ( V_3 , V_109 ) ;
return 0 ;
}
static void F_89 ( struct V_110 * V_111 , T_1 V_112 )
{
struct V_10 * V_10 = F_20 ( V_111 , struct V_10 , V_12 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
unsigned V_9 ;
F_65 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
V_9 = F_90 ( & V_10 -> V_9 , 0 ) ;
if ( V_9 & V_82 ) {
F_15 ( V_3 , NULL ) ;
}
if ( V_9 & V_109 ) {
F_72 ( V_3 ) ;
F_91 ( & V_10 -> V_32 , V_5 -> V_113 ) ;
}
}
static void F_92 ( struct V_110 * V_111 , T_1 V_112 )
{
struct V_10 * V_10 = F_20 ( V_111 , struct V_10 , V_79 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
F_13 ( L_9 , V_10 -> V_19 , V_112 ) ;
F_8 ( V_3 ) ;
}
static void F_93 ( struct V_2 * V_3 )
{
struct V_24 * V_6 = V_3 -> V_6 ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_103 ;
V_103 = F_94 ( V_3 ) ;
if ( V_103 )
return;
V_103 = F_95 ( V_6 -> V_12 [ F_96 ( V_3 ) ] . V_114 ,
! ( F_97 ( V_1 , V_21 ) &
V_10 -> V_20 ) ,
F_98 ( 50 ) ) ;
if ( V_103 <= 0 )
F_99 ( V_6 -> V_6 , L_10 , V_10 -> V_67 ) ;
V_10 -> V_20 = 0 ;
F_100 ( V_3 ) ;
}
T_1 F_101 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return V_10 -> V_12 . V_115 ;
}
void F_102 ( struct V_2 * V_3 , T_1 V_36 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_14 ( V_1 , F_103 ( V_10 -> V_62 ) , V_36 ) ;
}
void F_104 ( struct V_2 * V_3 , enum V_116 V_117 , int V_48 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_118 ;
V_118 = F_97 ( V_1 , V_119 ) ;
switch ( V_10 -> V_62 ) {
case V_120 :
V_118 &= ~ V_121 ;
V_118 |= F_105 ( V_117 ) ;
break;
case V_122 :
V_118 &= ~ V_123 ;
V_118 |= F_106 ( V_117 ) ;
break;
case V_77 :
V_118 &= ~ V_124 ;
V_118 |= F_107 ( V_117 ) ;
break;
}
if ( V_117 == V_125 ) {
V_118 &= ~ V_126 ;
V_118 |= V_127 ;
} else if ( V_117 == V_128 ) {
V_118 &= ~ V_127 ;
V_118 |= V_126 ;
}
V_10 -> V_48 = V_48 ;
F_30 ( V_3 ) ;
F_13 ( L_11 , V_10 -> V_19 , V_118 ) ;
F_14 ( V_1 , V_119 , V_118 ) ;
}
void F_108 ( struct V_2 * V_3 )
{
F_93 ( V_3 ) ;
}
struct V_2 * F_109 ( struct V_24 * V_6 ,
struct V_13 * V_14 , int V_67 , int V_129 ,
enum V_61 V_130 )
{
struct V_2 * V_3 = NULL ;
struct V_10 * V_10 ;
V_10 = F_110 ( sizeof( * V_10 ) , V_131 ) ;
if ( ! V_10 )
return F_111 ( - V_132 ) ;
V_3 = & V_10 -> V_11 ;
V_10 -> V_67 = V_67 ;
V_10 -> V_18 = V_129 ;
V_10 -> V_62 = V_130 ;
V_10 -> V_12 . V_115 = F_112 ( V_10 -> V_62 ) ;
V_10 -> V_12 . V_111 = F_89 ;
V_10 -> V_79 . V_115 = F_113 ( V_10 -> V_62 ) ;
V_10 -> V_79 . V_111 = F_92 ;
snprintf ( V_10 -> V_19 , sizeof( V_10 -> V_19 ) , L_12 ,
V_133 [ V_130 ] , V_129 ) ;
F_114 ( & V_10 -> V_83 . V_84 ) ;
F_115 ( & V_10 -> V_32 ,
L_13 , F_19 ) ;
F_116 ( V_6 , V_3 , V_14 , NULL , & V_134 ,
NULL ) ;
F_117 ( V_3 , & V_135 ) ;
V_14 -> V_3 = V_3 ;
return V_3 ;
}
